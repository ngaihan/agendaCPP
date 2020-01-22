#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include "entry.h"
#include "linkedList.h"

linkedList::linkedList(){
    head = NULL;
}

entry* linkedList::getHead(){
    return head;
}

void linkedList::setHead(entry *nhead){
    head = nhead;
}

bool linkedList::addEntry(entry *newEntry){
    
    //Empty list case
    if (head == NULL){
        head = newEntry;
        return true;
    }
    
    //Add at head case
    if (head->dateCompare(newEntry) == 1 || head->dateCompare(newEntry) == 0){
        newEntry->setNext(head);
        head = newEntry;
        return true;
    }
    
    //Add in the middle of the list case
    entry *current = head;
    entry *prev = NULL;
    
    while (current != NULL){
        //Same entry title case
        if (current->getTitle() == newEntry->getTitle()){
            delete newEntry;
            return false;
        }
        
        if (current->dateCompare(newEntry) == 1 || current->dateCompare(newEntry) == 0){
            prev->setNext(newEntry);
            newEntry->setNext(current);
            return true;
        }
        
        prev = current;
        current = current->getNext();
    }
    
    //End of the list case
    prev->setNext(newEntry);
    return true;
}

void linkedList::printList(){
    entry *current = head;
    
    if (head == NULL){
        cout << "List is empty" << endl;
    }
    
    while (current != NULL){
        if (current->getFinished()){
            cout << "O " << convertMonth(current->getMonth()) << ' ' << current->getDay() << "     " << current->getTitle() << endl;
        }
        else{
            cout << "X " << convertMonth(current->getMonth()) << ' ' << current->getDay() << "     " << current->getTitle() << endl;
        }
        
        current = current->getNext();
    }
}

entry *linkedList::search(string target){
    
    entry* current = head;
    
    while (current != NULL){
        if (current->getTitle() == target){
            return current;
        }
        current = current->getNext();
    }
    
    return NULL;
}

bool linkedList::deleteEntry(string target){
    entry *temp;
    
    if (head->getTitle().compare(target) == 0){
        temp = head;
        head = head->getNext();
        temp->setNext(NULL);
        delete temp;
        return true;
    }
    
    entry *current = head;
    entry *prev = NULL;
    
    while (current != NULL){
        if (current->getTitle().compare(target) == 0){
            temp = current;
            current = current->getNext();
            temp->setNext(NULL);           
            prev->setNext(current);
            delete temp;
            return true;
        }
        
        prev = current;
        current = current->getNext();
    }
    
    return false;
}

//Reads save data and generates a list from it
void linkedList::generateList(string fileName){    
    ifstream data(fileName);
    int month, day;
    string title;
    
    if (data >> month >> day){
        getline(data, title);
        if (title[0] == ' '){
            title = title.substr(1, title.size() - 1);
        }
        
        head = new entry(title, month, day);
    }
    
    entry *current = head;
    
    while (data >> month >> day){
        getline(data, title);
        if (title[0] == ' '){
            title = title.substr(1, title.size() - 1);
        }
        
        current->setNext(new entry(title, month, day));
        current = current->getNext();
    }
}

linkedList::~linkedList(){
    entry *temp;
    
    while (head != NULL){
        temp = head;
        head = head->getNext();
        delete temp;
    }
}

void linkedList::destroyList(){
    while (head != NULL){
        entry *temp;
        temp = head;
        head = head->getNext();
        this->destroyList();
        delete temp;
    }
}

string linkedList::convertMonth(int nmonth){
    string monthList[12] = {"Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec"};
    for (int i=0; i<11; i++){
        if (i == nmonth)
            return monthList[i-1];
    }
}

#endif

