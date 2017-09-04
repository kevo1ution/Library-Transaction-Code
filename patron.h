/* 
 * File:   patron.h
 * Author: kevin tang
 * Description: patron class header, defines prototypes for functions
 * Created on March 20, 2017, 12:07 AM
 */

#ifndef PATRON_H
#define PATRON_H
#include "main.h"
class patron {
public:
    void setphone();
    void setpstatus(int newstatus, int newbrwd);
    void setfirst();
    void setlast();
    void setaddress();
    void setemail();
    void setpid(int temp);
    int getpid();
    long long int getphone();
    double getpfine();
    int getpbrwd();
    int getpstatus();
    string getfirst();
    string getlast();
    string getaddress();
    string getemail();
    void add_fine(double cost);
    void add_book_cost();
    void pay_fine(double paying);
    patron();
    void set(double tfine, long long int tphone, int tpbrwd,
            int tstatus, int tpid, string tfirst, string tlast, string taddress, string temail);
private:

    double pfine;
    long long int phone;
    int pbrwd, pstatus, pid; //for status, 1- goodstanding, 2- blocked
    string first, last, address, email;
};

#endif /* PATRON_H */

