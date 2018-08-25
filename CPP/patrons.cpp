/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   patrons.cpp
 * Author: kevin
 * 
 * Created on March 20, 2017, 12:07 AM
 */

#include <valarray>

#include "patrons.h"

void patrons::addpatron() {
    //1. increase counter of patrons and allocate memory to table
    pcnt++;
    id++;

    //2. create a temp patron and add it to the vector
    patron temp;
    temp.setpid(id);
    temp.setfirst();
    temp.setlast();
    temp.setphone();
    temp.setaddress();
    temp.setemail();

    //3. push back vector to hold one more patron
    pat.push_back(temp);
    
    //4. out print that the patron was created
    cout << "\n\nPatron was successfully created!\nPatron's New Auto Generated ID: "
            << id << endl << endl;
}

void patrons::removepatron() {
    //1. index variable is the patron wanting to be deleted, and update everything
    int index, tempid;

    //2. ask user for patron id and find index
    cout << " Enter patron's Id for removal: ";
    cin >> tempid;
    if (cin.fail() || findpatron(tempid) == -1) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (findpatron(tempid) == -1) {
            cout << "The patron ID you entered does not correlate with any "
                    "patron in the system:\n";
        }
        cout << "Response was invalid. Please try again and enter a valid integer id.\n";
        return;
    }
    index = findpatron(tempid);
    if (pat[index].getpstatus() == 2 || pat[index].getpbrwd() > 0){
        cout << "The Patron you entered has over due fines or has checked out some books.\n"
                "You can't delete Patron with overdue fines or checked out books.\n";
        return;
    }
    
    
    
    //3.lower the patron count
    pcnt--;

    //4. delete the element in the vector
    pat.erase(pat.begin() + index);
    
    //6. print patron was successfully deleted
    cout << "\nPatron was successfully deleted!\n\n";
}

void patrons::editpatron() {

    //1. get input for patron id
    int index;
    int tempid;
    int input = -1;

    cout << " Enter id of Patron you would like to edit: ";
    cin >> tempid;
    while (cin.fail() || findpatron(tempid) == -1) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (findpatron(tempid) == -1) {
            cout << "The patron ID you entered does not correlate with any "
                    "patron in the system:\n";
        }
        cout << "Response was invalid. Please try again with a valid integer ID\n";
        return;
    }


    //2. output options for user to edit patron info
    index = findpatron(tempid);

    while (input != 0) {
        cout << "What would like to edit for this patron?\n"
                " 0. Done editing!\n"
                " 1. First name\n"
                " 2. Last name\n"
                " 3. phone number\n"
                " 4. Address\n"
                " 5. Email\n";
        cin >> input;
        while (cin.fail() || input < 0 || input > 5) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Your response was invalid. Please enter a valid integer(0-5): ";
            cin >> input;
        }

        switch (input) {
            case 1:
                pat[index].setfirst();
                break;
            case 2:
                pat[index].setlast();
                break;
            case 3:
                pat[index].setphone();
                break;
            case 4:
                pat[index].setaddress();
                break;
            case 5:
                pat[index].setemail();
                break;
        }

    }

}

void patrons::printall(){

    //1. print out all people

    cout << "ID | First Name | Last Name | address                | email             | Balance | Phone number | # of items checked out\n"
            "--------------------------------------------------------------------------------------------------------------------------\n";

    for (int x = 0; x < pcnt; x++) {
        cout << setw(3) << left << pat[x].getpid() << "| "
                << setw(11) << pat[x].getfirst() << "| "
                << setw(10) << pat[x].getlast() << "| "
                << setw(23) << pat[x].getaddress() << "| "
                << setw(18) << pat[x].getemail() << "| $"
                << setw(7) << fixed << setprecision(2) << pat[x].getpfine() << "| "
                << setw(13) << pat[x].getphone() << "| " << pat[x].getpbrwd() << endl;
            
        }

    cout << endl;    
    
}

void patrons::listmail() {

    //1. print out all people

    cout << "ID | Mailing Label\n"
            "------------------------------------------\n";

    for (int x = 0; x < pcnt; x++) {
        cout << setw(3) << left << pat[x].getpid() << "| "
                << pat[x].getfirst() << " "
                << pat[x].getlast() << endl
                << setw(3) << " " << "| " 
                << pat[x].getaddress() << endl
                << setw(3) << " " << "|" << endl;
    }

    cout << endl;
}

void patrons::listpatronfine() {

    //1. out print table
    cout << "ID | Balance | First Name | Last Name | phone    | address \n"
            "-----------------------------------------------------------\n";

    //2. search through patrons with fines
    int temp = 0;
    double mult = 0;
    for (int x = 0; x < pcnt; x++) {
        mult = pat[x].getpfine() * 100;
        temp = mult;
        if (temp > 0) {
            cout << setw(4) << left << pat[x].getpid()
                    << setw(10) << pat[x].getpfine()
                    << setw(13) << pat[x].getfirst()
                    << setw(12) << pat[x].getlast()
                    << setw(11) << pat[x].getphone()
                    << pat[x].getaddress() << endl;
        }
    }
}

int patrons::findpatron(int tempid) {
    //1. set up variable index to return
    for (int x = 0; x < pcnt; x++) {
        if (pat[x].getpid() == tempid) {
            return x;
        }
    }
    return -1; //error
}

void patrons::payfine() {
    //1. set up temporary variables to find patron and locate fine balance
    int tempid, index;
    double paying;

    //2. prompt for both id and how much the person is paying
    cout << " Enter the Patron's ID: ";
    cin >> tempid;
    while (cin.fail() || findpatron(tempid) == -1) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (findpatron(tempid) == -1) {
            cout << "Patron does not exist.\n";
        }
        cout << "Your response was invalid. Please enter a valid Id next time!n";
        return;
    }


    //3. find the patron's info based on id and record how payment
    index = findpatron(tempid);
    cout << "Patron's fines total: $" << fixed << setprecision(2) << pat[index].getpfine() << endl
            << " Enter amount being payed: ";
    cin >> paying;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Your response was invalid. Please enter a valid payment amount:\n";
        cin >> paying;
    }



    //4. detract from balance
    pat[index].pay_fine(paying);
    cout << "Patron's new fine total: $" << pat[index].getpfine() << endl;

}

void patrons::addfine(int elem, double fine){
    
    pat[elem].add_fine(fine);
    
}

patron patrons::getpat(int elem){
    return pat[elem];
}

void patrons::changestatus(int elem, int newstatus, int newbrwd){
    pat[elem].setpstatus(newstatus, newbrwd);
}

int patrons::getpcnt() {
    return pcnt;
}

int patrons::getid() {
    return id;
}

bool patrons::load(ifstream &load) {

    //1. start loading information
    char temp;
    double pfine;
    long long int phone;
    int pbrwd, pstatus, pid;
    string first, last, address, email;
    load.get(temp);
    if (temp == 'p') {
        load >> pcnt >> id;
    } else {
        return true;
    }
    
    //2. set up temporary patron and clear pat array
    pat.clear();
    patron temppatron;

    for (int x = 0; x < pcnt; x++) {
        load >> pfine >> phone >> pbrwd >> pstatus >> pid >> first >> last;
        load.ignore(1);
        getline(load, address);
        getline(load, email);
        temppatron.set(pfine, phone, pbrwd, pstatus, pid, first, last, address, email);
        pat.push_back(temppatron);
    }

    return false;
}

bool patrons::save(ofstream &save) {
    //1. print out header of patrons
    save << "p " << pcnt << " " << id << endl;

    //2. print out all patron info
    for (int x = 0; x < pcnt; x++) {
        save << pat[x].getpfine() << " "
                << pat[x].getphone() << " "
                << pat[x].getpbrwd() << " "
                << pat[x].getpstatus() << " "
                << pat[x].getpid() << " "
                << pat[x].getfirst() << " "
                << pat[x].getlast() << " "
                << pat[x].getaddress() << endl
                << pat[x].getemail() << endl;
    }
    return false;
}

patrons::patrons() {
    pcnt = 0;
    id = 0;

}

patrons::patrons(vector<patron> temp, int tempcnt, int tempid) {
    //1. copy important variables to temp
    pcnt = tempcnt;
    id = tempid;
    pat = temp;
}