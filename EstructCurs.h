/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EstructCurs.h
 * Author: Jhenny Cervera Vargas(20182841)
 *
 * Created on 30 de junio de 2020, 8:13
 */

#ifndef ESTRUCTCURS_H
#define ESTRUCTCURS_H
#include "EstructRequisit.h"

struct Curso{
    char*cod;
    char* nombre;
    double cred;
    struct Requisito cursosReq[10];
    int numCursReq;
};

#endif /* ESTRUCTCURS_H */

