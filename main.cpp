/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kevin
 *
 * Created on March 25, 2017, 4:02 PM
 */


#include "functions.h"
using namespace std;

/*
 *
 * 
 * 
 *  
 */
int main() {
    //1. Prompt with author name, course number, program title, etc.
    cout << " _____________________________________________________\n"
            "|                                                     |\n"
            "|       Author: Kevin Tang <kevin26428@gmail.com      |\n"
            "|                 Course: CSCE 1040.001               |\n"
            "|             Homework 5: Library System              |\n"
            "|_____________________________________________________|\n"
            "\nDescription: This program uses STL transaction for a Library Book system\n"
            "This program also also uses polymorphism, operator overloading, and inheritance";

    //2. Prompt user with options and set up necessary variables
    patrons p;
    libitems l;
    transactions t;

    int response = 1;
    while (response != 0) {

        cout << "\nEnter in number (0-14) for correct option.\n"
                " 0- quit\n"
                " 1- Add a new library patron\n"
                " 2- Edit patron information\n"
                " 3- Remove a patron\n"
                " 4- Print a list of all patrons by ID number (least to greatest)\n"
                " 5- Print a list of all patrons with outstanding fines by ID Number (least to greatest)\n"
                " 6- Print a list of items a patron has\n"
                " 7- Add a item (book, reference, CD, or DVD) to the catalog\n"
                " 8- Edit a item information\n"
                " 9- Remove item from catalog\n"
                " 10- Checkout an item to patron (A book must be returned within 2 weeks or pay $" << fixed << setprecision(2) << t.getbookfine() << " per day overdue,\n"
                "     CDs and DVDs must be returned within 1 week, or a $" << t.getavfine() << " fine per day will be charged,\n"
                "     References cannot be checked out)\n"
                "     Note: A patron can only check out 5 of any combination of books, CDs, and DVDs at a time.\n"
                " 11- Recheck a book (1 recheck per book, CDs and DVDs cannot be rechecked)\n"
                " 12- Return or check in an item from patron (This automatically computes fine amount if item is overdue)\n"
                " 13- Compute the Due Date of a checked out item (2 weeks from day checked out for books, and 1 week for CDs and DVDs)\n"
                " 14- Record that a patron has paid some money toward his fines\n"
                " 15- Print all overdue items, and which patrons have them\n"
                " 16- Print address mailing labels\n"
                " 17- Load\n"
                " 18- Save\n"
                " 19- ADMIN MENU (THIS IS FOR LIBRARIAN/GRADER PURPOSES!)\n\n"
                "Your input: ";
        cin >> response;
        while (cin.fail() || response < 0 || response > 19) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Your response was invalid. Please enter an integer from 0-18: \n";
            cin >> response;
        }
        switch (response) {
            case 1:
                p.addpatron();
                break;
            case 2:
                p.editpatron();
                break;
            case 3:
                t.update(&p);
                p.removepatron();
                break;
            case 4:
                p.printall();
                break;
            case 5:
                p.listpatronfine();
                break;
            case 6:
                t.listitempatron(&p, &l);
                break;
            case 7:
                l.additem();
                break;
            case 8:
                l.edititem();
                break;
            case 9:
                l.removeitem();
                break;
            case 10:
                t.checkout(&p, &l);
                break;
            case 11:
                t.recheck(&p, &l);
                break;
            case 12:
                t.checkin(&p, &l);
                break;
            case 13:
                t.listdue(&l);
                break;
            case 14:
                p.payfine();
                break;
            case 15:
                t.listoverdue(&p, &l);
                break;
            case 16:
                p.listmail();
                break;
            case 17:
                if (load(&p, &t, &l)) {
                    cout << "\nError: Corrupt file or File does not exist please try again!\n";
                }
                break;
            case 18:
                save(&p, &t, &l);
                break;
            case 19:
                admin(&t, &l);
                break;
        }

    }

    return 0;
}

