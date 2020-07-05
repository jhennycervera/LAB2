/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncAux.h
 * Author: Jhenny Cervera Vargas(20182841)
 *
 * Created on 30 de junio de 2020, 8:12
 */

#ifndef FUNCAUX_H
#define FUNCAUX_H
#include "EstructCurs.h"

 void guardarArchCursos(struct Curso *, int *);
 void guardarArchCursos(struct Curso *, int *);
 FILE* abrirArch(const char* , const char* );
 void sacaPalabras(char* ,char** ,int*,char );
 char* leerCadExact(FILE*);
void leerCad(char* , int , FILE*);
void LeerCurso(FILE* ,struct Curso *);
 void ordenarCursos(struct Curso * ,int );
 void cambiar(struct Curso *,int , int );
 void imprimirRep(int ,struct Curso * ,int );
void imprimeLinea(FILE*,int ,char ,int );
 

#endif /* FUNCAUX_H */

