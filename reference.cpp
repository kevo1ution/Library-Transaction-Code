/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reference.cpp
 * Author: kevin
 * 
 * Created on April 14, 2017, 3:28 PM
 */

#include "reference.h"

reference::reference() {
    id = 0;
    cpy = 1;
    status = 0;
    cost = 0;
    auth = "";
    publisher = "";
    title = "";
}

reference::reference(const reference& orig) {

    id = orig.id;
    cpy = orig.cpy;
    status = orig.status;
    cost = orig.cost;
    auth = orig.auth;
    publisher = orig.publisher;
    title = orig.title;
}

/*reference::~reference() {
}*/

void reference::print(){
        cout << "refer  " << setw(5) << left << id
            << setw(32) << left << title;
    
}

void reference::printall(ofstream& save){
    save << *this;
}

void reference::operator=(const reference& orig) {
    id = orig.id;
    cpy = orig.cpy;
    status = orig.status;
    cost = orig.cost;
    auth = orig.auth;
    publisher = orig.publisher;
    title = orig.title;
}

void reference::setauth(int line) {
    if (line == 1) { //1 means that it is called by editing function
        cin.ignore();
    }
    cout << " Enter the author of this Reference: ";
    getline(cin, auth);
}

void reference::setpub(int line) {
    if (line == 1) { //1 means that it is called by editing function
        cin.ignore();
    }
    cout << " Enter the publisher of this reference: ";
    getline(cin, publisher);
}

void reference::set(int tid, int tcpy, int tstatus, double tcost, string tauth, string tpub, string ttitle) {
    id = tid;
    cpy = tcpy;
    status = tstatus;
    cost = tcost;
    auth = tauth;
    publisher = tpub;
    title = ttitle;
}

string reference::getauth() {
    return auth;
}

string reference::getpub() {
    return publisher;
}