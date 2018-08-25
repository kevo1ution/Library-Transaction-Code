/* 
 * File:   libitem.h
 * Author: kevin
 *
 * Created on April 10, 2017, 2:35 PM
 */

#ifndef LIBITEM_H
#define LIBITEM_H

#include "main.h"

class libitem {
public:
    libitem();
    libitem(const libitem& orig);
    //virtual ~libitem();
    virtual void print();
    virtual void printall(ofstream &save) = 0;
    void settitle(int line); //1- book, 2-CD, 3- DVD, 4-Reference
    void setid(int temp);
    void setcpy();
    void setcost();
    void setstatus(int newstatus);
    string gettitle();
    int getid();
    int getcpy();
    double getcost();
    int getstatus();
    
protected:
    string title;
    int id, cpy, status;
    double cost;
};

#endif /* LIBITEM_H */

