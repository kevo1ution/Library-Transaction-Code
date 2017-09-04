/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   patrons.h
 * Author: kevin
 *
 * Created on March 20, 2017, 12:07 AM
 */

#ifndef PATRONS_H
#define PATRONS_H
#include "main.h"
#include "patron.h"
class patrons {
public:
    void addpatron();
    void removepatron();
    void editpatron();
    void printall();
    void listmail();
    void listpatronfine();
    int findpatron(int tempid);
    void payfine();
    void addfine(int elem, double fine);
    patron getpat(int elem);
    void changestatus(int elem, int newstatus, int newbrwd);
    int getpcnt();
    int getid();
    bool load(ifstream &load);
    bool save(ofstream &save);
    patrons();
    patrons(vector<patron> temp, int tempcnt, int tempid);
private:
    vector<patron> pat;
    int id;
    int pcnt;

};

#endif /* PATRONS_H */

