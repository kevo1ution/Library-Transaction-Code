/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   patron.cpp
 * Author: kevi
 * Created on March 20, 2017, 12:07 AM
 */

#include "patron.h"

void patron::setphone() {

    cout << "\n Enter Patron's phone number: " << flush;
    cin >> phone;
    while (cin.fail() || phone < 1000000000 || phone > 9999999999) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Your response was invalid. Please enter a valid phone number "
                "must be 10 digit integer:\n";
        cin >> phone;
    }
}

void patron::setpstatus(int newstatus, int newbrwd) {
    pstatus = newstatus;
    pbrwd = newbrwd;
}

void patron::setfirst() {

    cout << " Enter Patron's first name: " << flush;
    cin >> first;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Your response was invalid. Please enter a valid first name:\n";
        cin >> first;
    }
}

void patron::setlast() {
    cout << " Enter Patron's last name: " << flush;
    cin >> last;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Your response was invalid. Please enter a valid last name:\n";
        cin >> last;
    }

}

void patron::setaddress() {
    cin.ignore();
    cout << " Enter Patron's address: " << flush;
    getline(cin, address);

}

void patron::setemail(){
    cout << " Enter Patron's email: ";
    cin >> email;
}

void patron::setpid(int temp){
    pid = temp;
}

int patron::getpid() {
    return pid;
}

long long patron::getphone() {
    return phone;
}

double patron::getpfine() {
    return pfine;
}

int patron::getpbrwd() {
    return pbrwd;
}

int patron::getpstatus() {
    return pstatus;
}

string patron::getfirst() {
    return first;
}

string patron::getlast() {
    return last;
}

string patron::getaddress() {
    return address;
}

string patron::getemail(){
    return email;
}

void patron::add_fine(double cost) {
    pfine += cost;
}

void patron::add_book_cost() {

}

void patron::pay_fine(double paying) {

    pfine -= paying;

}

patron::patron(){
    pfine = 0;
    phone = 0;
    pbrwd = 0;
    pstatus = 1;
    first = "";
    last = "";
    address = "";
    email = "";
}

void patron::set(double tfine, long long int tphone, int tpbrwd,
        int tstatus, int tpid, string tfirst, string tlast, string taddress, string temail) {

    pfine = tfine;
    phone = tphone;
    pbrwd = tpbrwd;
    pstatus = tstatus;
    first = tfirst;
    last = tlast;
    address = taddress;
    email = temail;
    pid = tpid;

}