/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "functions.h"

void admin(transactions *t, libitems *l) {
    //1. Set up important variables
    int input = -1;
    double fine;

    //2. loop
    while (input != 0) {
        cout << "\nTHIS IS THE ADMIN MENU:\n";

        cout << " 0. return to regular menu\n"
                " 1. Change due date of a checked out item\n"
                " 2. Change the fine amount for books which is currently: $" << 
                fixed << setprecision(2) << t->getbookfine() << " per day overdue\n"
                " 3. Change the fine amount for AV items (CD/DVD) which is currently: $" << 
                t->getavfine() << " per day overdue\n"
                " 4. Print out all Books\n"
                " 5. Print out all CDs\n"
                " 6. Print out all DVDs\n"
                " 7. Print out all References\n\n"
                "input: ";
        cin >> input;
        while (cin.fail() || input < 0 || input > 7) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Your response was invalid. Please enter an integer from 0-5: \n";
            cin >> input;
        }
        switch (input) {
            case 0:
                return;
                break;
            case 1:
                t->mansetdue(l);
                break;
            case 2:
                cout << "Enter new fine amount for Books: ";
                cin >> fine;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Your response was invalid. Please enter fine amount greater than 0: \n";
                    cin >> fine;
                }
                t->setbookfine(fine);
                break;
            case 3:
                cout << "Enter new fine amount for AV items: ";
                cin >> fine;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Your response was invalid. Please enter fine amount greater than 0: \n";
                    cin >> fine;
                }
                t->setavfine(fine);
                break;
            case 4:
                l->printall(1);
                break;
            case 5:
                l->printall(2);
                break;
            case 6:
                l->printall(3);
                break;
            case 7:
                l->printall(4);
                break;
        }

    }

}

bool load(patrons *p, transactions *t, libitems *l) {
    //1. define file user wants to load
    string name;

    cout << "Enter the file name you would like to load: ";
    cin >> name;

    //2. open file
    ifstream load;
    load.open(name.c_str());

    if (load.fail()) {
        return true;
    }
    bool temp = p->load(load);
    //load patrons, books, and transactions
    if (temp) {
        cout << temp << endl;
        load.close();
        return true;
    }
    temp = l->load(load);
    if (temp) {
        load.close();
        return true;
    }
    temp = t->load(load);
    if (temp) {
        load.close();
        return true;
    }

    //load books

    load.close();
    return false;

}

bool save(patrons *p, transactions *t, libitems *l) { //1. define file user wants to load
    string name;

    cout << "Enter the file name you would like to save: ";
    cin >> name;

    //2. open file
    ofstream save;
    save.open(name.c_str());

    //save patrons, books, and transactions
    p->save(save);
    l->save(save);
    t->save(save);

    save.close();
    return false;

}