/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dvd.cpp
 * Author: kevin
 * 
 * Created on April 14, 2017, 3:28 PM
 */

#include "dvd.h"

dvd::dvd() {
    id = 0;
    cpy = 1;
    status = 0;
    dur = 0;
    cost = 0;
    dir = "";
    stdio = "";
    title = "";    
}

dvd::dvd(const dvd& orig) {
    id = orig.id;
    cpy = orig.cpy;
    status = orig.status;
    dur = orig.dur;
    cost = orig.cost;
    dir = orig.dir;
    stdio = orig.stdio;
    title = orig.title;
}

/*dvd::~dvd() {
    
}*/

void dvd::print(){
        cout << "DVD    " << setw(5) << left << id
            << setw(32) << left << title;
    
}

void dvd::printall(ofstream& save){
    save << *this;
}

void dvd::operator = (const dvd& orig){
    id = orig.id;
    cpy = orig.cpy;
    status = orig.status;
    dur = orig.dur;
    cost = orig.cost;
    dir = orig.dir;
    stdio = orig.stdio;
    title = orig.title;    
}

void dvd::setdur() {
    //1. set up variables
    int hours, minutes, seconds;

    //2. get user input
    cout << "\n You are now entering the duration of the DVD in hours, minutes, and seconds.\n";
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

void dvd::setstdio(int line) {
    if (line == 1) { //1 means that it is called by editing function
        cin.ignore();
    }
    cout << " Enter the studio that made this DVD: ";
    getline(cin, stdio);
}

void dvd::setdir(int line) {
    if (line == 1) { //1 means that it is called by editing function
        cin.ignore();
    }
    cout << " Enter the director of this DVD: ";
    getline(cin, dir);
}

void dvd::set(int tid, int tcpy, int tstatus, long long int tduration, double tcost, string tdir, string tstudio, string ttitle) {
    id = tid;
    cpy = tcpy;
    status = tstatus;
    dur = tduration;
    cost = tcost;
    dir = tdir;
    stdio = tstudio;
    title = ttitle;
}

long long int dvd::getdur() {
    return dur;
}

string dvd::getstdio() {
    return stdio;
}

string dvd::getdir() {
    return dir;
}
