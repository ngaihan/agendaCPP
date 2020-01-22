#ifndef ENTRY_CPP
#define ENTRY_CPP

#include "entry.h"

entry::entry(){
    title = "\0";
    day = 0;
    month = 0;
    finished = false;
    next = NULL;
}

entry::entry(string ntitle, int nmonth, int nday){
    title = ntitle;
    month = nmonth;
    day = nday;
    finished = false;
    next = NULL;
}

string entry::getTitle(){
    return title;
}

void entry::setTitle(string ntitle){
    title = ntitle;
}

int entry::getDay(){
    return day;
}

void entry::setDay(int nday){
    day = nday;
}

int entry::getMonth(){
    return month;
}

void entry::setMonth(int nmonth){
    month = nmonth;
}

bool entry::getFinished(){
    return finished;
}

void entry::setFinished(bool nfinished){
    finished = nfinished;
}

entry* entry::getNext(){
    return next;
}

void entry::setNext(entry *nnext){
    next = nnext;
}

int entry::dateCompare(entry *rhs){
    if (month > rhs->getMonth()){
        return 1;
    }
    else if (month < rhs->getMonth()){
        return 2;
    }
    else if (day > rhs->getDay()){
        return 1;
    }
    else if (day < rhs->getDay()){
        return 2;
    }
    return 0;
}

entry::~entry(){
    if (next != NULL){
        delete next;
    }
}

#endif
