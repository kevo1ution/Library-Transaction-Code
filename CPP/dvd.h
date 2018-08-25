/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dvd.h
 * Author: kevin
 *
 * Created on April 14, 2017, 3:28 PM
 */

#ifndef DVD_H
#define DVD_Hvoid set(int tid, int tcpy, int tstatus, long long int tduration, double tcost, string tdir, string tstudio, string ttitle);
#include "libitem.h"

class dvd : public libitem {
public:
    dvd();
    dvd(const dvd& orig);
    //virtual ~dvd();
    void print();
    void printall(ofstream &save);
    void operator=(const dvd& orig);
    void setdur();
    void setstdio(int line);
    void setdir(int line);
    void set(int tid, int tcpy, int tstatus, long long int tduration,
            double tcost, string tdir, string tstudio, string ttitle);
    long long int getdur();
    int gettype();
    string getstdio();
    string getdir();

    friend ostream &operator<<(ostream &output, const dvd &d) {
        output << d.id << " "
                << d.cpy << " "
                << d.status << " "
                << d.dur << " "
                << d.cost << " "
                << d.dir << endl
                << d.stdio << endl
                << d.title << endl;
        return output;
    }

    friend istream &operator>>(istream &input, dvd &d) {
        input >> d.id >> d.cpy >> d.status >> d.dur >> d.cost;
        input.ignore(1);
        getline(input, d.dir);
        getline(input, d.stdio);
        getline(input, d.title);

        return input;
    }
private:
    long long int dur;
    string stdio;
    string dir;
};

#endif /* DVD_H */

