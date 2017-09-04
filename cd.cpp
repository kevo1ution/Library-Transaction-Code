/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cd.cpp
 * Author: kevin
 * 
 * Created on April 14, 2017, 3:27 PM
 */

#include "cd.h"

cd::cd() {
    id = 0;
    cpy = 1;
    status = 0;
    dur = 0;
    cost = 0;
    art = "";
    label = "";
    title = "";
}

cd::cd(const cd& orig) {
    id = orig.id;
    cpy = orig.cpy;
    status = orig.status;
    dur = orig.dur;
    cost = orig.cost;
    art = orig.art;
    label = orig.label;
    title = orig.title;
}

/*cd::~cd() {
}*/

void cd::print() {
    cout << "CD     " << setw(5) << left << id
            << setw(32) << left << title;

}

void cd::printall(ofstream& save){
    save << *this;
}

void cd::operator=(const cd& orig) {
    id = orig.id;
    cpy = orig.cpy;
    status = orig.status;
    dur = orig.dur;
    cost = orig.cost;
    art = orig.art;
    label = orig.label;
    title = orig.title;

}

void cd::setdur() {
    //1. set up variables
    int hours, minutes, seconds;
    
    //2. Notify users that they are inputing the duration
    cout << "\n You are now entering the duration of the CD in hours, minutes, and seconds.\n";
    cout << " Enter the number of hours: ";
    cin >> hours;
    while (cin.fail() || hours < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Your response was invalid. Please enter an integer greater than 0: ";
        cin >> hours;
    }
    cout << " Enter the number of minutes: ";
    cin >> minutes;
    while (cin.fail() || minutes < 0 || minutes > 59) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Your response was invalid. Please enter an integer greater than 0 and less than 60: ";
        cin >> minutes;
    }
    cout << " Enter the number of seconds: ";
    cin >> seconds;
    while (cin.fail() || seconds < 0 || seconds > 59) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Your response was invalid. Please enter an integer greater than 0 and less than 60: ";
        cin >> seconds;
    }
    dur = hours * 60 * 60 * 24 + minutes * 60 + seconds;
}

void cd::setart(int line) {
    if (line == 1) { //1 means that it is called by editing function
        cin.ignore();
    }
    cout << " Enter the artist of this CD: ";
    getline(cin, art);
}

void cd::setlabel(int line) {
    if (line == 1) { //1 means that it is called by editing function
        cin.ignore();
    }
    cout << " Enter the label of this CD: ";
    getline(cin, label);
}

void cd::set(int tid, int tcpy, int tstatus, long long int tduration,
        double tcost, string tartist, string tlabel, string ttitle) {
    id = tid;
    cpy = tcpy;
    dur = tduration;
    cost = tcost;
    art = tartist;
    label = tlabel;
    title = ttitle;
}

long long int cd::getdur() {
    return dur;
}

string cd::getart() {
    return art;
}

string cd::getlabel() {
    return label;
}
