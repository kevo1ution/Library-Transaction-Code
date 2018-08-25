/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   functions.h
 * Author: kevin
 *
 * Created on March 29, 2017, 12:20 PM
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "main.h"
#include "patrons.h"
#include "transactions.h"
#include "libitems.h"
//function prototypes
void admin(transactions *t, libitems *l);
bool load(patrons *p, transactions *t, libitems *l);
bool save(patrons *p, transactions *t, libitems *l);

#endif /* FUNCTIONS_H */

