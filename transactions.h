/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   transactions.h
 * Author: kevin
 *
 * Created on March 20, 2017, 12:07 AM
 */

#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include "main.h"
#include "transaction.h"

class transactions {
public:
    void setavfine(double tempfine);
    void setbookfine(double tempfine);
    double getavfine();
    double getbookfine();
    void update(patrons *p);
    void checkout(patrons *p, libitems *l);
    void checkin(patrons *p, libitems *l);
    void recheck(patrons *p, libitems *l);
    void listitempatron(patrons *p, libitems *l);
    void listoverdue(patrons *p, libitems *l);
    void listdue(libitems *l);
    int find(int pid, int lid);
    int find(int lid);
    bool load(ifstream &load);
    bool save(ofstream &save);
    void mansetdue(libitems *l);
    transactions();
    transactions(vector<transaction> temp, int tempcnt, int tempid, double tempavfine, double tempbookfine);
private:
    int tcnt, id;
    double avfine, bookfine; //fine values for AV and Book items
    vector<transaction> trans;
};

#endif /* TRANSACTIONS_H */

