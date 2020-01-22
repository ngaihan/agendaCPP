#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

#include "entry.h"

class linkedList{
private:
    entry *head;
public:
    linkedList();
    
    entry *getHead();
    void setHead(entry *nhead);
    
    bool addEntry(entry *newEntry);
    
    /*Prints list in the format
    mm/dd    TITLE*/
    void printList();
    
    //Searches the list using the title and returns pointer
    entry *search(string target);
    
    //Deletes the target from the list
    bool deleteEntry(string target);
    
    void generateList(string fileName);
    
    ~linkedList();
    
    void destroyList();
    
    void destroyRecursive(entry *node);
    
    string convertMonth(int date);
};

#endif	/* LINKEDLIST_H */

