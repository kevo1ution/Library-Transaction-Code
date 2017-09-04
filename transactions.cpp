/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   transactions.cpp
 * Author: kevin
 * 
 * Created on March 20, 2017, 12:07 AM
 */

#include "transactions.h"

void transactions::setavfine(double tempfine) {
    avfine = tempfine;
}

void transactions::setbookfine(double tempfine) {
    bookfine = tempfine;
}

double transactions::getavfine() {
    return avfine;
}

double transactions::getbookfine() {
    return bookfine;
}

void transactions::update(patrons* p) {
    //1a. search through array for due dates that are over due
    time_t now, tempdue, diff;
    time(&now);

    //1b. set up patron index
    int pindex;
    patron temppat;
    for (int x = 0; x < tcnt; x++) {
        //2a. find the difference in time between the due date and now to 
        //    check if book is overdue.
        tempdue = trans[x].getdue();
        diff = difftime(now, tempdue);
        pindex = p->findpatron(trans[x].getpid());
        temppat = p->getpat(pindex);
        int temppfine = temppat.getpfine() * 100;
        if (diff > 0 || temppfine > 0) {
            //2b. update status of patrons

            p->changestatus(pindex, 2, temppat.getpbrwd());
        }
    }
}

void transactions::checkout(patrons *p, libitems *l) {
    //1. increase counter of transactions and allocate memory to table
    update(p);
    tcnt++;
    id++;

    //2. set up new transaction object to be pushed back in vector
    transaction temptrans;
    temptrans.settid(id);

    if (temptrans.setpid(p)) {
        cout << "The Patron Id you entered is invalid or Blocked meaning the patron has overdue"
                "\nbooks or has checked out more than 5 books."
                "\n Please try again.\n";
        tcnt--;
        id--;
        return;
    }
    if (temptrans.setlid(l)) {
        cout << "The Item Id you entered is invalid or checked out. Please try again.\n";
        tcnt--;
        id--;
        return;
    }
    temptrans.setdue(l);

    //3. push back the temporary transaction object into the vector
    trans.push_back(temptrans);
    cout << "\n\nTransaction was successfully created and the item was checked out!\nThe New Auto Generated ID: "
            << id << endl << endl;

}

void transactions::checkin(patrons *p, libitems *l) {
    //1. set up index variable, and tempids
    int index, lindex, temppid, templid;

    //2. prompt user for both ID
    cout << "Enter Patron ID: ";
    cin >> temppid;
    if (cin.fail() || p->findpatron(temppid) == -1) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (p->findpatron(temppid) == -1) {
            cout << "The patron ID you entered does not correlate with any "
                    "patron in the system:\n";
        }
        cout << "Response was invalid. Please enter a valid id(integer)\n";
        return;
    }
    cout << "Enter Item ID you want to return: ";
    cin >> templid;
    if (cin.fail() || l->finditem(templid) == -1) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (l->finditem(templid) == -1) {
            cout << "The Book ID you entered does not correlate with any "
                    "Book in the system:\n";
        }
        cout << "Response was invalid. Please enter a valid id(integer)\n";
        return;
    }

    //3. error check input ID
    index = find(temppid, templid);
    if (index == -1) {
        cout << "The Patron has not checked out this item, and therefore cannot return it\n"
                "Please try again.\n";
        return;
    }

    //4. check if book was overdue and create fine accordingly
    double fine = 0.0;
    time_t now, diff;
    time(&now);

    lindex = l->finditem(templid);
    diff = difftime(now, trans[index].getdue());
    if (diff > 0) {
        long long int tempdays = diff / (24 * 60 * 60);

        if (l->gettype(lindex) == 1) {
            fine = bookfine * tempdays;
        } else if (l->gettype(lindex) == 2 || l->gettype(lindex) == 3) {
            fine = avfine * tempdays;
        }
        cout << "A fine of $" << fixed << setprecision(2) << fine << " has been added to the patron's fines for being overdue\n";
    }

    //5. change amount borrowed by patron, and change status if checked out 5 books originally
    //   or if there are fines due to the due date of book, add fines to patron and block
    int pindex, refine;
    patron temppat;
    pindex = p->findpatron(temppid);
    p->addfine(pindex, fine);
    temppat = p->getpat(pindex);

    refine = (fine + temppat.getpfine()) * 100;
    if (refine == 0) {
        p->changestatus(pindex, 1, (temppat.getpbrwd() - 1));
    } else if (refine > 0) {
        p->changestatus(pindex, 2, (temppat.getpbrwd() - 1));
    }

    //6. Now that we've configured the settings for each book, we will delete the borrowed transaction
    tcnt--;

    trans.erase(trans.begin() + index);

    //7. change item status to checked in, check if it is a item or not
    int type = l->gettype(lindex);
    if (type == 1) {
        l->changestatus(lindex, 0, 0); //checks in and set to 0
    } else {
        l->changestatus(lindex, 0);
    }
    cout << "\nThe item has been returned!\n\n";
}

void transactions::recheck(patrons *p, libitems *l) {
    update(p);
    //1. set up variables for rechecking
    int temppid, tempbid;

    //2. get patron and book id
    int pindex;
    patron temppatron;
    cout << "Enter the patron ID that is rechecking a book: ";
    cin >> temppid;

    if (p->findpatron(temppid) == -1 || cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Error: invalid patron ID.\n";
        return;
    }
    pindex = p->findpatron(temppid);
    temppatron = p->getpat(pindex);
    if (temppatron.getpstatus() == 2) {
        cout << "Error: The patron you entered is blocked, meaning the patron has a combination of the following\n"
                "1.) 5 items checked out\n"
                "2.) overdue items\n"
                "3.) outstanding fines\n";
        return;
    }
    cout << "Enter the book ID: ";
    cin >> tempbid;

    //3. check book recheck status and make sure its a book
    int bindex = l->finditem(tempbid);
    if (l->finditem(tempbid) == -1 || cin.fail() || l->getrechecks(bindex)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Error: invalid book ID.\n";
        if (l->getrechecks(bindex) == 1) {
            cout << "You cannot recheck out a book more than once\n";
        }
        return;
    }
    if (l->gettype(bindex) != 1) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Error: This is not a Book item! Please try again.\n";
        return;
    }

    //4. Check if the book is overdue
    int index = find(temppid, tempbid);
    time_t now, diff;
    time(&now);

    diff = difftime(now, trans[index].getdue());
    if (diff > 0) {
        cout << "You cannot recheck an item that is overdue!\n";
        return;
    }
    //5. set new due date
    trans[index].setdue(l);

    cout << "\n\nTransaction was successfully created and the book was rechecked out!\nThe New Auto Generated ID: "
            << id << endl << endl;

    //6. change status of book
    l->changestatus(bindex, 1, 1);
}

void transactions::listitempatron(patrons* p, libitems *l) {

    //1. set up variables
    int pindex, temppid;
    patron temppatron;

    cout << "Enter the Patron ID to see items checked out: ";
    cin >> temppid;

    if (p->findpatron(temppid) == -1) {
        cout << "Patron ID is invalid. Please try again.\n";
        return;
    }

    pindex = p->findpatron(temppid);
    temppatron = p->getpat(pindex);

    int bindex, tempbid;
    time_t tempdue;

    //2. print out information for books patron has
    cout << "Items Checked Out For Patron: " << temppatron.getfirst() << " " << temppatron.getlast() << endl;
    cout << "----------------------------------------------------\n";
    cout << "Type | ID | Title                         | due date\n";
    cout << "----------------------------------------------------\n";
    for (int x = 0; x < tcnt; x++) {
        bindex = l->finditem(trans[x].getlid());
        if (temppid == trans[x].getpid() && l->gettype(bindex) == 1) {
            tempdue = trans[x].getdue();
            l->printitem(bindex);
            cout << ctime(&tempdue) << endl;
        }
    }

    //3. print out CDs
    for (int x = 0; x < tcnt; x++) {
        bindex = l->finditem(trans[x].getlid());
        if (temppid == trans[x].getpid() && l->gettype(bindex) == 2) {
            tempdue = trans[x].getdue();
            l->printitem(bindex);
            cout << ctime(&tempdue) << endl;
        }
    }
    //4. print out DVDs
    for (int x = 0; x < tcnt; x++) {
        bindex = l->finditem(trans[x].getlid());
        if (temppid == trans[x].getpid() && l->gettype(bindex) == 3) {
            tempdue = trans[x].getdue();
            l->printitem(bindex);
            cout << ctime(&tempdue) << endl;
        }
    }
    cout << endl << endl;
}

void transactions::listoverdue(patrons* p, libitems *l) {
    //1. print out basic information
    cout << "Type | ID | Title                         | Patron ID | Patron's Name \n";
    cout << "----------------------------------------------------------------------\n";
    //2a. search through array for due dates that are over due
    time_t now, tempdue, diff;
    time(&now);
    //2b. set up book and patron to get names
    int bindex, pindex;
    patron temppatron;

    for (int x = 0; x < tcnt; x++) {
        //2c. find the difference in time between the due date and now to 
        //    check if book is overdue.
        tempdue = trans[x].getdue();
        diff = difftime(now, tempdue);

        if (diff > 0) {
            //2d. print over due books and patron who checked them out
            temppatron = p->getpat(p->findpatron(trans[x].getpid()));
            bindex = l->finditem(trans[x].getlid());
            l->printitem(bindex);
            cout << setw(12) << trans[x].getpid() << " "
                    << temppatron.getfirst() << " " << temppatron.getlast() << endl;
        }
    }
}

void transactions::listdue(libitems *l) {

    //1. error check book input
    int tempbid, bindex, bstatus, rechecks, counter = 0;
    cout << "Enter the item ID: ";
    cin >> tempbid;

    bindex = l->finditem(tempbid);
    if (bindex == -1) {
        cout << "Error: The item you entered doesn't exist. Please try again.\n";
        return;
    }

    bstatus = l->getstatus(bindex);
    if (bstatus != 1) {
        cout << "The ID you entered is invalid: Item is not checked out or doesn't exist.\n"
                "Please try again.";
        return;
    }

    //2. print due date
    for (int x = 0; x < tcnt; x++) {
        time_t temp = trans[x].getdue();
        if (tempbid == trans[x].getlid()) {
            cout << "The due date of the item is: " << ctime(&temp) << endl;
        }
    }
}

int transactions::find(int pid, int lid) {
    //1. search through dynamic array for index number
    for (int x = 0; x < tcnt; x++) {
        if (trans[x].getpid() == pid && trans[x].getlid() == lid) {
            return x;
        }
    }
    return -1; //error    
}

int transactions::find(int lid) {
    //1. search through dynamic array for index number
    for (int x = 0; x < tcnt; x++) {
        if (trans[x].getlid() == lid) {
            return x;
        }
    }
    return -1; //error

}

void transactions::mansetdue(libitems *l) {

    //1. get book id for due date changing
    int tempbid, index;
    cout << "Enter item ID for due date to change: ";
    cin >> tempbid;

    //2. check if book id is legit
    if (cin.fail() || l->finditem(tempbid) == -1) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (l->finditem(tempbid) == -1) {
            cout << "The ID you entered does not correlate with any "
                    "Item in the system:\n";
        }
        cout << "Response was invalid. Please enter a valid id(integer)\n";
        return;
    }
    index = l->finditem(tempbid);

    //3. check if book is checked out
    if (l->getstatus(index) != 1) {
        cout << "Error: The Item is not checked out!\n\n";
        return;
    }

    //4. update the due date of book
    time_t tempdue;
    cout << "Enter the new due date (the amount of seconds from 1/1/1970)\n";
    cin >> tempdue;
    index = find(tempbid);
    trans[index].setdue(tempdue);
}

bool transactions::load(ifstream &load) {
    //1. load beginning information
    char temp;
    int tid, lid, pid;
    time_t due;
    load >> temp;
    if (temp == 't') {
        load >> tcnt >> id >> avfine >> bookfine;
    } else {
        return true;
    }

    //2. use push back and a temp transaction object
    transaction temptrans;
    trans.clear();

    for (int x = 0; x < tcnt; x++) {
        load >> tid >> lid >> pid >> due;
        temptrans.set(tid, lid, pid, due);
        trans.push_back(temptrans);
    }

    return false;
}

bool transactions::save(ofstream &save) {
    //1. print out header of book
    save << "t " << tcnt << " " << id << " " << avfine << " " << bookfine << endl;

    //2. print out all book info
    for (int x = 0; x < tcnt; x++) {
        save << trans[x].gettid() << " "
                << trans[x].getlid() << " "
                << trans[x].getpid() << " "
                << trans[x].getdue() << endl;
    }
    return false;

}

transactions::transactions() {
    tcnt = 0;
    id = 0;
    avfine = 1.00;
    bookfine = 0.25;
}

transactions::transactions(vector<transaction> temp, int tempcnt, int tempid, double tempavfine, double tempbookfine) {
    //1. copy important variables to temp
    tcnt = tempcnt;
    id = tempid;
    trans = temp;
    avfine = tempavfine;
    bookfine = tempbookfine;
}