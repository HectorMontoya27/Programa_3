#ifndef LISTA_ARG_H
#define LISTA_ARG_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"

/* -------------------------Declaracion de Funciones -------------------------- */
/* Creacion */
listaArg *crearListaArg();                //Lista
arg* crearArg(int tipo);                  //Lista
void agregarArg(listaArg *la, int tipo);  //Lista
/* Eliminar */
void borrarlistaArg(listaArg *la);        //Lista
void borrarArgs(arg *a);                  //Lista
/* Impresion */
void imprimirLista(listaArg* lista);      //Pendiente
void imprimirArg(arg* arg);               //Pendiente
/* Busqueda */
int getTipo(arg* arg);                    //Pendiente
int getTamlistaArg(listaArg *la);         //Lista

/* --------------------------- Formato de Documentacion ------------------------- */

// Documentacion de Creacion - Copiar y pegar
/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
// Documentacion de Modificacion - Copiar y pegar
/*
--Fecha de modificacion:
--Autor modificacion:
--Descripcion de modificacion:
*/

/* -------------------------------- Funciones -------------------------------- */

/*
--Nombre Funcion: crearListaArg()
--Descripcion: Creacion de una nueva lista de argumentos
--Autor: Soto Vázquez Patricia
--Fecha de creacion: 31 Mayo 2020
*/
listaArg *crearListaArg(){
    listaArg *Nueva = (listaArg*)malloc(sizeof(listaArg));
    Nueva->tam = 0;
    Nueva->inicio = NULL;
    return Nueva;
}

/*
--Nombre Funcion: crearArg()
--Descripcion: Creacion de un nuevo argumento
--Autor: Soto Vázquez Patricia
--Fecha de creacion: 31 Mayo 2020
*/
arg* crearArg(int tipo){
    arg *Nuevo = (arg*)malloc(sizeof(arg));
    Nuevo->tipo = tipo;
    Nuevo->siguente = NULL;
    return Nuevo;
}

/*
--Nombre Funcion: agregarArg()
--Descripcion: Se agrega un nuevo tipo a la lista
--Autor: Soto Vázquez Patricia
--Fecha de creacion: 31 Mayo 2020
*/
void agregarArg(listaArg *la, int tipo){
    if (la->inicio == NULL){
        la->inicio = crearArg(tipo);
        la->tam ++;
    } else {
        arg *Aux = la->inicio;
        while(Aux->siguente != NULL){
            Aux = Aux->siguente;
        }
        Aux->siguente = crearArg(tipo);
        la->tam ++;
    }
}

/*
--Nombre Funcion: borrarlistaArg()
--Descripcion: Eliminacion de memoria para una lista de argumento pero primero se liberan los argumentos
--Autor: Soto Vázquez Patricia
--Fecha de creacion: 31 Mayo 2020
*/
void borrarlistaArg(listaArg *la){
    if (la->inicio != NULL){ borrarArgs(la->inicio); }
    free(la);
}

/*
--Nombre Funcion: borrarArgs()
--Descripcion: Borra la memoria  de los argumentos 1 a 1
--Autor: Soto Vázquez Patricia
--Fecha de creacion: 31 Mayo 2020
*/
void borrarArgs(arg *a){
    if(a->siguente != NULL){ borrarArgs(a->siguente); }
    free(a);
}

/*
--Nombre Funcion: imprimirLista(list_arg* lista)
--Descripcion: Impresion de una lista de argimentos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 31 Mayo 2020
*/
void imprimirLista(listaArg* lista){
    if (lista != NULL) {
        arg *arg = lista->inicio;
        while (arg != NULL) {
            imprimirArg(arg);
            arg = arg->siguente;
        }
    }
}

/*
--Nombre Funcion: imprimirArg(arg* arg)
--Descripcion: Impresion de un argumento
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 31 Mayo 2020
*/
void imprimirArg(arg *arg){
    printf(" %d", arg->tipo);
}

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
int getTipo(arg* arg){}

/*
--Nombre Funcion: getTamlistaArg()
--Descripcion: Funcion que retorna el numero de elementos que tiene la lista
--Autor: Soto Vázquez Patricia
--Fecha de creacion: 31 Mayo 2020
*/
int getTamlistaArg(listaArg *la){
    return la->tam;
}

#endif
