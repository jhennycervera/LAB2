/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Jhenny Cervera Vargas(20182841)
 *
 * Created on 30 de junio de 2020, 8:05
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncAux.h"
#include "EstructCurs.h"
#include "EstructRequisit.h"
/*
 * 
 */
int main(int argc, char** argv) {

    struct Curso cursos[100];
    int numCurs,numReqI;
    
    guardarArchCursos(cursos,&numCurs);
    ordenarCursos(cursos,numCurs);
    //leer datos 
    printf("Ingresar el numero de requisitos:");
    scanf("%d", &numReqI);
    imprimirRep(numReqI,cursos,numCurs);
    
    return (EXIT_SUCCESS);
}

