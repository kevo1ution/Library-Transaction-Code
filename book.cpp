/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   book.cpp
 * Author: kevin
 * 
 * Created on March 20, 2017, 12:07 AM
 */

#include "book.h"
#include "libitem.h"

void book::setrechecks(int newrechecks) {
    rechecks = newrechecks;
}

void book::setpublisher(int line) {
    if (line == 1) { //1 means that it is called by editing function
        cin.ignore();
    }
    cout << " Enter the publisher or author of this book: ";
    getline(cin, publisher);
}

int book::getrechecks() {
    return rechecks;
}

string book::getpublisher() {
    return publisher;
}

book::book() {
    id = 0;
    cpy = 1;
    cost = 0;
    status = 0;
    title = "";
    publisher = "";
    rechecks = 0;
}

book::book(const book& orig) {
    id = orig.id;
    cpy = orig.cpy;
    cost = orig.cost;
    status = orig.status;
    title = orig.title;
    publisher = orig.publisher;
    rechecks = orig.rechecks;
}

void book::print() {
    cout << "Book   " << setw(5) << left << id
            << setw(32) << left << title;
}

void book::printall(ofstream& save){
    save << *this;
}

void book::operator=(const book& orig) {
    id = orig.id;
    cpy = orig.cpy;
    cost = orig.cost;
    status = orig.status;
    title = orig.title;
    publisher = orig.publisher;
    rechecks = orig.rechecks;
}

void book::set(int tid, int tcpy, int tstatus, int trechecks, double tcost, string ttitle, string tpublisher) {
    id = tid;
    cpy = tcpy;
    cost = tcost;
    status = tstatus;
    rechecks = trechecks;
    title = ttitle;
    publisher = tpublisher;
}
