/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   libitems.cpp
 * Author: kevin
 * 
 * Created on April 17, 2017, 9:49 AM
 */

#include "libitems.h"

libitems::libitems() {
    cnt = 0;
    id = 0;
}

libitems::libitems(const libitems& orig) {
    cnt = orig.cnt;
    id = orig.id;
    items = orig.items;
    types = orig.types;
}

libitems::~libitems() {
    items.clear();
    types.clear();
}

int libitems::getcnt() {
    return cnt;
}

int libitems::getid() {
    return id;
}

int libitems::gettype(int index) {
    return types[index];
}

int libitems::getstatus(int elem) {
    return items[elem]->getstatus();
}

int libitems::getrechecks(int elem) {
    return static_cast<book *> (items[elem])->getrechecks();
}

void libitems::additem() {
    //1. increase count of items and id number
    cnt++;
    id++;

    //2. find out the type of item the user is adding
    int input;
    cout << "\nWhat type of library item would you like to add?\n"
            " 1. Book\n"
            " 2. CD\n"
            " 3. DVD\n"
            " 4. Reference\n\n"
            " Your input: ";
    cin >> input;
    switch (input) {
        case 1:
            items.push_back(new book);
            items[cnt - 1]->setid(id);
            items[cnt - 1]->setcpy();
            items[cnt - 1]->setcost();
            items[cnt - 1]->settitle(1);
            static_cast<book *> (items[cnt - 1])->setpublisher(0);

            types.push_back(input);
            cout << "\n\nbook was successfully created!\n"
                    "The New Auto Generated ID: " << id << endl << endl;
            break;
        case 2:
            items.push_back(new cd);
            items[cnt - 1]->setid(id);
            items[cnt - 1]->setcpy();
            items[cnt - 1]->setcost();
            static_cast<cd *> (items[cnt - 1])->setdur();
            items[cnt - 1]->settitle(1);
            static_cast<cd *> (items[cnt - 1])->setart(0);
            static_cast<cd *> (items[cnt - 1])->setlabel(0);

            types.push_back(input);
            cout << "\n\nCD was successfully created!\n"
                    "The New Auto Generated ID: " << id << endl << endl;

            break;
        case 3:
            items.push_back(new dvd);
            items[cnt - 1]->setid(id);
            items[cnt - 1]->setcpy();
            items[cnt - 1]->setcost();
            static_cast<dvd *> (items[cnt - 1])->setdur();
            items[cnt - 1]->settitle(1);
            static_cast<dvd *> (items[cnt - 1])->setdir(0);
            static_cast<dvd *> (items[cnt - 1])->setstdio(0);

            types.push_back(input);
            cout << "\n\nDVD was successfully created!\n"
                    "The New Auto Generated ID: " << id << endl << endl;

            break;
        case 4:
            items.push_back(new reference);
            items[cnt - 1]->setid(id);
            items[cnt - 1]->setcpy();
            items[cnt - 1]->setcost();
            items[cnt - 1]->settitle(1);
            static_cast<reference *> (items[cnt - 1])->setpub(0);
            static_cast<reference *> (items[cnt - 1])->setauth(0);

            types.push_back(input);
            cout << "\n\nbook was successfully created!\n"
                    "The New Auto Generated ID: " << id << endl << endl;

            break;
        default:
            cout << "Your input was invalid. Please try again.\n";
            cnt--;
            id--;
            return;
            break;



    }
}

void libitems::removeitem() {
    //1. get the id of item the user wants to remove
    int index, tempid;

    //2. ask user for id and find index
    cout << " Enter Item Id for removal: ";
    cin >> tempid;
    if (cin.fail() || finditem(tempid) == -1) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (finditem(tempid) == -1) {
            cout << "The ID you entered does not correlate with any "
                    "Item in the system:\n";
        }
        cout << "Response was invalid. Please try again\n";
        return;
    }
    //3. get the index and check if item is checked out
    index = finditem(tempid);
    if (items[index]->getstatus() != 0) {
        cout << "Error: you cannot delete this item, it is checked out!\n";
        return;
    }

    //4. lower item count
    cnt--;

    //5. erase the correct item
    types.erase(types.begin() + index);
    items.erase(items.begin() + index);

    cout << "\nItem was successfully deleted!\n\n";

}

void libitems::edititem() {

    //1. set up necessary variables 
    int index;
    int tempid;
    int input = -1;
    int line = 1;
    int type;

    //2. get user input for the id of the item
    cout << " Enter the id of the item you would like to edit: ";
    cin >> tempid;
    if (cin.fail() || finditem(tempid) == -1) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (finditem(tempid) == -1) {
            cout << "The Item ID you entered does not correlate with any "
                    "Item in the system:\n";
        }
        cout << "Response was invalid. Please enter a valid id(integer)\n";
        return;
    }
    //3. get index and figure out what type the item is
    index = finditem(tempid);
    type = types[index];

    while (input != 0) {
        cout << "What would like to edit?\n"
                " 0. Done editing!\n"
                " 1. title\n"
                " 2. copy number\n"
                " 3. cost\n";
        switch (type) {
            case 1:
                cout << " 4. publisher\n";
                break;
            case 2:
                cout << " 4. duration\n"
                        " 5. label\n"
                        " 6. artist\n";
                break;
            case 3:
                cout << " 4. duration\n"
                        " 5. studio\n"
                        " 6. director\n";
                break;
            case 4:
                cout << " 4. author\n"
                        " 5. publisher\n";
                break;
        }
        cin >> input;
        while (cin.fail() || input < 0 || input > 6) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Your response was invalid. Please enter a valid integer(0-4): ";
            cin >> input;
        }

        switch (input) {
            case 1:
                items[index]->settitle(line);
                break;
            case 2:
                items[index]->setcpy();
                break;
            case 3:
                items[index]->setcost();
                break;
        }
        switch (type) {
            case 1:
                switch (input) {
                    case 4:
                        static_cast<book*> (items[index])->setpublisher(line);
                        break;
                }

                break;
            case 2:
                switch (input) {
                    case 4:
                        static_cast<cd*> (items[index])->setdur();
                        break;
                    case 5:
                        static_cast<cd*> (items[index])->setlabel(line);
                        break;
                    case 6:
                        static_cast<cd*> (items[index])->setart(line);
                        break;
                }

                break;
            case 3:
                switch (input) {
                    case 4:
                        static_cast<dvd*> (items[index])->setdur();
                        break;
                    case 5:
                        static_cast<dvd*> (items[index])->setstdio(line);
                        break;
                    case 6:
                        static_cast<dvd*> (items[index])->setdir(line);
                        break;
                }

                break;
            case 4:
                switch (input) {
                    case 4:
                        static_cast<reference*> (items[index])->setauth(line);
                        break;
                    case 5:
                        static_cast<reference*> (items[index])->setpub(line);
                        break;
                }
                break;
        }

    }
}

int libitems::finditem(int tempid) {
    //1. search through vector for index number
    for (int x = 0; x < cnt; x++) {
        if (items[x]->getid() == tempid) {
            return x;
        }
    }
    return -1; //error
}

void libitems::changestatus(int elem, int newstatus, int newrechecks) {
    items[elem]->setstatus(newstatus);
    static_cast<book*> (items[elem])->setrechecks(newrechecks);
}

void libitems::changestatus(int elem, int newstatus) {
    items[elem]->setstatus(newstatus);
}

void libitems::printitem(int elem) {
    items[elem]->print();
}

void libitems::printall(int type) {
    switch (type) {
        case 1: // book
            cout << "Books:\n"
                    "----------------------------------------------------------\n"
                    "ID | Cpy | Cost | Title                   | Publisher\n"
                    "----------------------------------------------------------\n";
            for (int x = 0; x < cnt; x++) {
                if (types[x] == type) {
                    cout << setw(3) << left << items[x]->getid() << "| "
                            << setw(4) << items[x]->getcpy() << "| "
                            << setw(5) << items[x]->getcost() << "| "
                            << setw(24) << items[x]->gettitle() << "| "
                            << static_cast<book*> (items[x])->getpublisher() << endl;
                }
            }
            break;
        case 2: // CD
            cout << "CDs:\n"
                    "------------------------------------------------------------------------------\n"
                    "ID | Cpy | Duration (sec) | Cost | Artist        | Label      | Title\n"
                    "------------------------------------------------------------------------------\n";
            for (int x = 0; x < cnt; x++) {
                if (types[x] == type) {
                    cout << setw(3) << left << items[x]->getid() << "| "
                            << setw(4) << items[x]->getcpy() << "| "
                            << setw(15) << static_cast<cd *> (items[x])->getdur() << "| "
                            << setw(5) << items[x]->getcost() << "| "
                            << setw(14) << static_cast<cd *> (items[x])->getart() << "| "
                            << setw(11) << static_cast<cd *> (items[x])->getlabel() << "| "
                            << items[x]->gettitle() << endl;
                }
            }
            break;
        case 3: // DVD
            cout << "DVDs:\n"
                    "-----------------------------------------------------------------------------\n"
                    "ID | Cpy | Duration (sec) | Cost | Director        | Studio      | Title\n"
                    "-----------------------------------------------------------------------------\n";
            for (int x = 0; x < cnt; x++) {
                if (types[x] == type) {
                    cout << setw(3) << left << items[x]->getid() << "| "
                            << setw(4) << items[x]->getcpy() << "| "
                            << setw(15) << static_cast<dvd *> (items[x])->getdur() << "| "
                            << setw(5) << items[x]->getcost() << "| "
                            << setw(16) << static_cast<dvd *> (items[x])->getdir() << "| "
                            << setw(12) << static_cast<dvd *> (items[x])->getstdio() << "| "
                            << items[x]->gettitle() << endl;
                }
            }
            break;
        case 4: // Reference
            cout << "References:\n"
                    "-------------------------------------------------------------------\n"
                    "ID | Cpy | Cost | Author        | Title             | Publisher\n"
                    "-------------------------------------------------------------------\n";
            for (int x = 0; x < cnt; x++) {
                if (types[x] == type) {
                    cout << setw(3) << left << items[x]->getid() << "| "
                            << setw(4) << items[x]->getcpy() << "| "
                            << setw(5) << items[x]->getcost() << "| "
                            << setw(14) << static_cast<reference *> (items[x])->getauth() << "| "
                            << setw(18) << items[x]->gettitle() << "| "
                            << static_cast<reference*> (items[x])->getpub() << endl;
                }
            }
            break;

    }

}

bool libitems::load(ifstream &load) {
    //1. start loading information
    char temp;
    int type;
    load >> temp;
    if (temp == 'l') {
        load >> cnt >> id;
    } else {
        return true;
    }

    //2. set up temporary objects
    book *b = new book;
    cd *c = new cd;
    dvd *d = new dvd;
    reference *r = new reference;

    //3. clear out system
    types.clear();
    items.clear();
    for (int x = 0; x < cnt; x++) {
        load >> type;
        types.push_back(type);
        switch (type) {
            case 1: // book
                load >> *b;
                items.push_back(b);
                b = new book;
                break;
            case 2: // CD
                load >> *c;
                items.push_back(c);
                c = new cd;
                break;
            case 3: // DVD
                load >> *d;
                items.push_back(d);
                d = new dvd;
                break;
            case 4: // Reference
                load >> *r;
                items.push_back(r);
                r = new reference;
                break;
        }
    }

    return false;
}

bool libitems::save(ofstream &save) {
    //1. print out header of libitems
    save << "l " << cnt << " " << id << endl;

    //2. print out all item info
    for (int x = 0; x < cnt; x++) {
        save << types[x] << " ";
        items[x]->printall(save);
    }
    return false;

}