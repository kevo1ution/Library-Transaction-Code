/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cd.h
 * Author: kevin
 *
 * Created on April 14, 2017, 3:27 PM
 */

#ifndef CD_H
#define CD_H
#include "libitem.h"

class cd : public libitem {
public:
    cd();
    cd(const cd& orig);
    //virtual ~cd();
    void print();
    void printall(ofstream &save);
    void operator=(const cd& orig);
    void setdur();
    void setart(int line);
    void setlabel(int line);
    void set(int tid, int tcpy, int tstatus, long long int tduration,
            double tcost, string tartist, string tlabel, string ttitle);
    long long int getdur();
    string getart();
    string getlabel();

    friend ostream &operator<<(ostream &output, const cd &c) {
        output << c.id << " "
                << c.cpy << " "
                << c.status << " "
                << c.dur << " "
                << c.cost << " "
                << c.art << endl
                << c.label << endl
                << c.title << endl;
        return output;
    }

    friend istream &operator>>(istream &input, cd &c) {
        input >> c.id >> c.cpy >> c.status >> c.dur >> c.cost;
        input.ignore(1);
        getline(input, c.art);
        getline(input, c.label);
        getline(input, c.title);
        return input;
    }
private:
    long long int dur;
    string art;
    string label;
};

#endif /* CD_H */

