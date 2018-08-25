/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   transaction.cpp
 * Author: kevin
 * 
 * Created on March 20, 2017, 12:07 AM
 */

#include <valarray>
#include "transaction.h"

void transaction::settid(int temp) {
    tid = temp;
}

bool transaction::setlid(libitems *l) {
    int tempid, index, status, type;
    cout << "Enter the ID of the item the patron is borrowing: ";
    cin >> tempid;

    if (l->finditem(tempid) == -1) {
        return true;
    }
    index = l->finditem(tempid);
    status = l->getstatus(index);
    type = l->gettype(index);
    if (status != 0) {

        return true;
    }
    if (type == 4){
        cout << "Error: You cannot check out a Reference!\n";
        return true;
    }
    //change item status to checked out

    //check type of item, if it is a book then check rechecks
    if(type == 1){
        status = l->getrechecks(index);
        if(status != 0){
            return true;
        }
    }
    
    l->changestatus(index, 1);
    lid = tempid;
    return false;


}

bool transaction::setpid(patrons *p) {
    int tempid, index, status;
    patron temppatron;
    cout << "Enter the Patron ID that wants to check out a item: ";
    cin >> tempid;
    if (p->findpatron(tempid) == -1) {
        return true;
    }

    index = p->findpatron(tempid);
    temppatron = p->getpat(index);

    status = temppatron.getpstatus();
    if (status != 1 || p->findpatron(tempid) == -1) {
        return true;
    }
    p->changestatus(index, 1, temppatron.getpbrwd() + 1);
    if (temppatron.getpbrwd() + 1 > 4) {
        cout << "*Warning*: After you enter the item ID, the patron will have checked out 5 items.\n"
                "After a patron checks out 5 items, no more items can be checked out or rechecked out.\n\n";
        p->changestatus(index, 2, temppatron.getpbrwd() + 1);
    }

    pid = tempid;
    return false;

}

void transaction::setdue(libitems *l) {
    //1. get current time
    time_t current;
    time(&current);

    int type, index;
    index = l->finditem(lid);
    type = l->gettype(index);
    
    //2. check if book or CD/DVD
    if(type == 1){
        due = current + 14 * 24 * 60 * 60; //add 2 weeks to the time

        cout << "Your book is due: " << ctime(&due) << endl;
    }else if(type == 2 || type == 3){
        due = current + 7 * 24 *60 * 60; //add 1 week to time
        
        cout << "Your CD/DVD is due: " << ctime(&due) << endl;
    }
}

void transaction::setdue(time_t test){
    due = test;    
}

void transaction::setrelid(int tempid) {
    lid = tempid;
}

void transaction::setrepid(int tempid) {
    pid = tempid;
}

int transaction::gettid() {
    return tid;
}

int transaction::getlid() {
    return lid;
}

int transaction::getpid() {
    return pid;
}

time_t transaction::getdue() {
    return due;
}

transaction::transaction() {
    tid = 0;
    lid = 0;
    pid = 0;
    due = 0;
}

void transaction::set(int temptid, int templid, int temppid, time_t tempdue) {
    tid = temptid;
    lid = templid;
    pid = temppid;
    due = tempdue;
}

