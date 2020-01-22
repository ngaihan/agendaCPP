#ifndef ENTRY_H
#define	ENTRY_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class entry{
private:
    string title;
    int day;
    int month;
    bool finished;
    entry *next;
public:
    //Basic constructors, accessors, and mutators
    entry();
    entry(string title, int month, int day);
    
    string getTitle();
    void setTitle(string ntitle);
    
    int getDay();
    void setDay(int nday);
    
    int getMonth();
    void setMonth(int nmonth);
    
    bool getFinished();
    void setFinished(bool nfinished);
    
    entry* getNext();
    void setNext(entry *nnext);
    
    //Returns 0 if same, 1 if lhs is after, 2 if left before
    int dateCompare(entry *rhs);
    
    ~entry();
    
};



#endif	/* ENTRY_H */

