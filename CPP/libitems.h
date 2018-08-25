/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   libitems.h
 * Author: kevin
 *
 * Created on April 17, 2017, 9:49 AM
 */

#ifndef LIBITEMS_H
#define LIBITEMS_H
#include "book.h"
#include "cd.h"
#include "dvd.h"
#include "reference.h"
#include "libitem.h"

class libitems {
public:
    libitems();
    libitems(const libitems& orig);
    virtual ~libitems();
    int getcnt();
    int getid();
    int gettype(int index);
    int getstatus(int elem);
    int getrechecks(int elem);
    void additem();
    void removeitem();
    void edititem();
    int finditem(int tempid);
    void changestatus(int elem, int newstatus, int newrechecks);
    void changestatus(int elem, int newstatus);
    void printitem(int elem);
    void printall(int type);
    bool load(ifstream &load);
    bool save(ofstream &save);
private:
    vector <int> types; //1-book, 2-CD, 3-DVD, 4-Reference
    vector <libitem *> items;
    int id;
    int cnt;
};

#endif /* LIBITEMS_H */

