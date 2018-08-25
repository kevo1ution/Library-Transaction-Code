/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   book.h
 * Author: kevin
 *
 * Created on March 20, 2017, 12:07 AM
 */

#ifndef BOOK_H
#define BOOK_H
#include "libitem.h"

class book : public libitem {
public:
    void setpublisher(int line);
    void setrechecks(int newrechecks);
    int getrechecks();
    string getpublisher();
    book();
    book(const book& orig);
    //virtual ~book();
    void print();
    void printall(ofstream &save);
    void operator=(const book& orig);
    void set(int tid, int tcpy, int tstatus, int trechecks, double tcost, string ttitle, string tpublisher);

    friend ostream &operator<<(ostream &output, const book &b) {
        output << b.id << " "
                << b.cpy << " "
                << b.status << " "
                << b.rechecks << " "
                << b.cost << " "
                << b.title << endl
                << b.publisher << endl;
        return output;
    }

    friend istream &operator>>( istream &input, book &b) {
        input >> b.id >> b.cpy >> b.status >> b.rechecks >> b.cost;
        input.ignore(1);
        getline(input, b.title);
        getline(input, b.publisher);
        return input;
    }
private:
    int rechecks;
    string publisher;
};

#endif /* BOOK_H */

