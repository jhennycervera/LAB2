/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//Author: Jhenny Cervera Vargas(20182841)     

#include <stdio.h>
#include <stdlib.h>
#include "FuncAux.h"
#include <string.h>
#define MAX_LIN 170
#define MAX_CAR 60;

 void guardarArchCursos(struct Curso *cursos, int *numCurs){
     FILE*archCur;
    archCur=abrirArch("Cursos.csv", "r"); 
    (*numCurs)=0;
    struct Curso cur;
    while(1){
        LeerCurso(archCur,&cur);
        if(feof(archCur)) break;
        cursos[(*numCurs)]=cur;
/*
        printf("%s %-10s %10.2lf",cursos[(*numCurs)].cod, cursos[(*numCurs)].nombre, cursos[(*numCurs)].cred );
        for(int i=0; i<cursos[(*numCurs)].numCursReq; i++) printf("%10s %10d", cursos[(*numCurs)].cursosReq[i].cod, cursos[(*numCurs)].cursosReq[i].nivel);
        printf("\n");
*/
        (*numCurs)++;
    }
    
    fclose(archCur);
 }

FILE* abrirArch(const char* nombreArch, const char* modo){
    FILE* arch;
    arch=fopen(nombreArch,modo);
    if(arch==NULL){
        printf("ERROR: No se puede abrir el archivo %s\n",nombreArch );
        exit(1);
    }
    return arch;
}

void LeerCurso(FILE* archCur,struct Curso *cur){
    
    char* pal[103], *linea;
    int numPal, j;
    linea=leerCadExact(archCur);
    if(linea==NULL) return;
    sacaPalabras(linea,pal,&numPal, ',');
    cur->cod=pal[0];
    cur->nombre=pal[1];
    cur->cred= atof(pal[numPal-1]);
    
    cur->numCursReq=(numPal-3)/2;
    //guardando los cursos requisitos
    j=2;
    for(int i=0; i<(cur->numCursReq) ; i++){
        cur->cursosReq[i].cod= pal[j];
        cur->cursosReq[i].nivel= atoi(pal[j+1]);
        j+=2;
    }
    
    free(pal[numPal-1]);
}

char* leerCadExact(FILE*arch){
    int len;
    char *pt, buff[500];
    leerCad(buff,500,arch);
    if(feof(arch)) return NULL;
    
    len=strlen(buff);
    pt=(char*)malloc(sizeof(char)*(len+1));
    strcpy(pt,buff);
    return pt;
}

void leerCad(char* cad, int tope, FILE*arch){
    int nCar;
    fgets(cad, tope, arch);
    nCar=strlen(cad);
    if(cad[nCar-1]=='\n') cad[nCar-1]=0;
}



void sacaPalabras(char* text,char** palabra,int*numPal,char carSep){
    
    int i=0,j;
    char* pt, buff[100];
    (*numPal)=0;
    while(1){
        while(text[i]==carSep) i++;
        if(text[i]==0) break;
        j=0;
        while(text[i]!=carSep && text[i]!=0){
            buff[j]=text[i];
            j++;
            i++;
        }
        buff[j]=0;
        pt=(char*)malloc(sizeof(char)*(j+1));
        strcpy(pt,buff);
        palabra[*numPal]=pt;
        (*numPal)++;
    }
}


void ordenarCursos(struct Curso * cursos,int numCurs){
    
    for(int i=0; i<numCurs-1; i++){
        for(int j=i+1; j<numCurs;j++){
            if(cursos[i].numCursReq< cursos[j].numCursReq || (cursos[i].numCursReq==cursos[j].numCursReq
                            && strcmp(cursos[i].cod,cursos[j].cod)<0)){ //ambos casos ordenados de mayor a menor
                cambiar(cursos,i, j);
            }
        }
    }
}


void cambiar(struct Curso *cursos,int i, int j){
    struct Curso aux;
    aux=cursos[i];
    cursos[i]=cursos[j];
    cursos[j]=aux;
}

void imprimirRep(int numReqI,struct Curso * cursos,int numCurs){
    
    FILE*archRep;
    archRep=abrirArch("CursosSolicitados.txt", "w");
    double promNiv,sumNiv=0 ;
    int cantCur=0, numBlanc, lon;
    //imprimir cabecera
    fprintf(archRep, "Numero de requisitos ingresado: %d\n",numReqI);
    imprimeLinea(archRep,MAX_LIN,'=', 1);
    fprintf(archRep, "%s %7s %58s %35s %35s\n", "CODIGO", "CURSO", "Creditos", "Requisitos(Codigo/Nivel)", "PromNiv");
    imprimeLinea(archRep,MAX_LIN,'=', 1);
    //imprimiendo cursos
    for(int i=0; i<numCurs; i++){
        if(cursos[i].numCursReq==numReqI){
            
            fprintf(archRep, "%s %-52s",cursos[i].cod, cursos[i].nombre);
/*
            lon=strlen(cursos[i].nombre);
            numBlanc= MAX_CAR - (lon+7);
            imprimeLinea(archRep,numBlanc,' ',0);
*/
            fprintf( archRep, "%20.2lf",cursos[i].cred);
            sumNiv=0;
            for(int j=0; j< cursos[i].numCursReq ; j++){
                fprintf(archRep, "%10s/%d",cursos[i].cursosReq[j].cod, cursos[i].cursosReq[j].nivel);
                //acumulando suma de niveles
                sumNiv+=cursos[i].cursosReq[j].nivel;
            }
            promNiv=sumNiv/(double)cursos[i].numCursReq;
            fprintf(archRep, "%25.2lf\n",promNiv);
            cantCur++;
        }
    }
    
    imprimeLinea(archRep,MAX_LIN,'=', 1);
    fprintf(archRep, "Total de Cursos: %d\n",cantCur);
    
    fclose(archRep);
 }

void imprimeLinea(FILE*archRep,int numBlanc,char c,int op){
    for(int i=0; i<numBlanc; i++){
        fputc(c, archRep);
    }
    if(op) fputc('\n',archRep);
}
