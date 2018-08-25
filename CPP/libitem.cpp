/* 
 * File:   libitem.cpp
 * Author: kevin
 * 
 * Created on April 10, 2017, 2:35 PM
 */

#include "libitem.h"

libitem::libitem() {
    id = 0;
    cost = 0;
    status = 0;
    cpy = 1;
    title = "";
}

libitem::libitem(const libitem& orig) {
    title = orig.title;
    id = orig.id;
    cpy = orig.cpy;
    status = orig.status;
    cost = orig.cost;
}

/*libitem::~libitem() {

}
*/
void libitem::print(){
    cout << id << " " << cpy << " " << status << " " << cost;
}

void libitem::settitle(int line) {
    if (line == 1) { //1 means that it is called by editing function
        cin.ignore();
    }
    cout << " Enter the title of this item: ";
    getline(cin, title);
}

void libitem::setid(int temp) {
    id = temp;
}

void libitem::setcpy() {
    cout << " Enter the copy number for the library item(example- if you already have 2 of the \n"
            " same book and you are adding another copy, your copy number is 3 for the new book)\n"
            " Copy Number: ";
    cin >> cpy;
    while (cin.fail() || cpy < 1) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Your response was invalid. Please enter a copy number (must be integer greater than 0): ";
        cin >> cpy;
    }
}

void libitem::setstatus(int newstatus) {
    status = newstatus;
}

void libitem::setcost() {
    cout << " Enter the cost of this library item: ";
    cin >> cost;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Your response was invalid. Please enter a valid book price: ";
        cin >> cost;
    }
}

string libitem::gettitle() {
    return title;
}

int libitem::getid() {
    return id;
}

int libitem::getcpy() {
    return cpy;
}

int libitem::getstatus() {
    return status;
}

double libitem::getcost() {
    return cost;
}
