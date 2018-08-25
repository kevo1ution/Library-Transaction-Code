/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   transaction.h
 * Author: kevin
 *
 * Created on March 20, 2017, 12:07 AM
 */

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "main.h"
#include "patrons.h"
#include "libitems.h"

class transaction {
public:
    void settid(int temp);
    bool setlid(libitems *l);
    bool setpid(patrons *p);
    void setrelid(int tempid);
    void setrepid(int tempid);
    void setdue(libitems *l);
    void setdue(time_t test);

    int gettid();
    int getlid();
    int getpid();
    time_t getdue();


    transaction();
    void set(int temptid, int templid, int temppid, time_t tempdue);
private:
    int tid, lid, pid;
    time_t due;
};

#endif /* TRANSACTION_H */

