/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reference.h
 * Author: kevin
 *
 * Created on April 14, 2017, 3:28 PM
 */

#ifndef REFERENCE_H
#define REFERENCE_H

#include "libitem.h"

class reference : public libitem {
public:
    reference();
    reference(const reference& orig);
    //virtual ~reference();
    void print();
    void printall(ofstream &save);
    void operator=(const reference& orig);
    void setauth(int line);
    void setpub(int line);
    void set(int tid, int tcpy, int tstatus, double tcost,
            string tauth, string tpub, string ttitle);
    string getauth();
    string getpub();

    friend ostream &operator<<(ostream &output, const reference &r) {
        output << r.id << " "
                << r.cpy << " "
                << r.status << " "
                << r.cost << " "
                << r.auth << endl
                << r.title << endl
                << r.publisher << endl;
        return output;

    }

    friend istream &operator>>(istream &input, reference &r) {
        input >> r.id >> r.cpy >> r.status >> r.cost;
        input.ignore(1);
        getline(input, r.auth);
        getline(input, r.publisher);
        getline(input, r.title);
        return input;
    }
private:
    string auth;
    string publisher;
};

#endif /* REFERENCE_H */

