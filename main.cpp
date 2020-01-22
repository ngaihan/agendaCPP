#include "entry.h"
#include "linkedList.h"
#include "functions.h"
#include "entry.cpp"
#include "linkedList.cpp"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    
    linkedList *list = new linkedList;
    list->generateList("save.txt");
    
    cout << endl << '\t' << "Task List" << endl << "__________________" << endl;
    list->printList();
    cout << endl;

    printActions();
    cout << endl << ">> ";
    
    string input;
    char command;
    
    getline(cin, input);
    command = toupper(input[0]);
    
    while (command != 'Q'){
        
        if (command == 'I'){
            
            string title;
            int month, day;
            
            cout << "Enter title: ";
            getline(cin, title);
            
            cout << "Enter date (month day): ";
            cin >> month >> day;
            cin.ignore(100, '\n');
            
            //Check date entered
            if (month > 12 || day > 31){
                cout << "Date entered is invalid" << endl;
            }
            
            else{
                entry *newEntry = new entry(title, month, day);
                bool success;
                
                success = list->addEntry(newEntry);
                
                if (success){
                    cout << "Entry successfully added" << endl;
                }
                else{
                    cout << "ERROR: Entry already exists in the list" << endl;
                }                
            }
        }
        
        else if (command == 'P'){
            cout << endl << '\t' << "Task List" << endl << "__________________" << endl;
            list->printList();
        }
        
        else if (command == 'F'){
            
            string target;
            entry *targetEntry;
            
            cout << "Enter title of task to finish: ";
            getline(cin, target);
            
            targetEntry = list->search(target);
            
            //Check for success
            if (targetEntry == NULL){
                cout << "ERROR: \'" << target << "\' does not exist" << endl;
            }
            else{
                targetEntry->setFinished(true);
                cout << '\'' << target << "\' has been finished, good job :)" << endl;
            }            
        }
        
        else if (command == 'D'){
            
            string target;
            bool success;
            
            cout << "Enter title of task to be deleted: ";
            getline(cin, target);
            
            success = list->deleteEntry(target);
            
            if (success){
                cout << '\'' << target << "\' was deleted successfully" << endl;
            }
            else{
                cout << "ERROR: \'" << target << "\' does not exist" << endl;
            }            
        }
        
        else{
            cout << endl << "Invalid command" << endl << endl;
            printActions();
        }
        
        cout << endl << ">> ";

        getline(cin, input);
        command = toupper(input[0]);
    }
    
    //Save list and quit
    ofstream saveData("save.txt");
    entry *current;
    current = list->getHead();
    
    while (current != NULL){
        if (!current->getFinished()){
            saveData << current->getMonth() << ' ' << current->getDay() << current->getTitle() << endl;       
        }
        
        current = current->getNext();
    }
    
    saveData.close();
    
    return 0;
}
