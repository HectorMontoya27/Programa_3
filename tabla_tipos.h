#ifndef TABLA_TIPOS_H
#define TABLA_TIPOS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"

/* -------------------------Declaracion de Funciones -------------------------- */
/* Creacion */
Pila_T_Tipos* PTT_nueva();                                      //Lista
T_Tipos* TT_nueva(char nombre[]);                               //Lista
Tipo* T_nuevo(char nombre[], int tam, int tipoBase);            //Lista
void PTT_push(Pila_T_Tipos *pila, T_Tipos *tabla);              //Lista
void TT_nuevoRegistro(T_Tipos *tabla, Tipo *t);                 //Lista
/* Eliminacion */
void PTT_eliminar();                                            //Pendiente
T_Tipos TT_pop();                                               //Pendiente
void T_eliminar();                                              //Pendiente
/* Impresion */
void PTT_imprimir();                                            //Pendiente
void TT_imprimir();                                             //Pendiente
void T_imprimir();                                              //Pendiente
/* Busqueda */
int TT_getTam(int tipo);                                        //Pendiente

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
--Nombre Funcion: PTT_nueva()
--Descripcion: Creacion de una nueva pila para tablas de tipos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 27 Mayo 2020
*/
Pila_T_Tipos* PTT_nueva(){
    Pila_T_Tipos *pila;
    pila = (Pila_T_Tipos *)malloc(sizeof(Pila_T_Tipos));
    pila->num = 0;
    return pila;
}

/*
--Nombre Funcion: TT_nueva()
--Descripcion: Creacion de una nueva tabla de tipos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 27 Mayo 2020
*/
T_Tipos* TT_nueva(char nombre[]){
    T_Tipos *tabla;
    tabla = (T_Tipos *)malloc(sizeof(T_Tipos));
    tabla->num = 0;
    strcpy(tabla->nombre,nombre);
    return tabla;
}

/*
--Nombre Funcion: T_nuevo()
--Descripcion: Creacion de un nuevo registro de Tipo
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 27 Mayo 2020
*/
Tipo* T_nuevo(char nombre[], int tam, int tipoBase){
    Tipo *t;
    t = malloc(sizeof(Tipo));
    t->id = -1;
    strcpy(t->nombre,nombre);
    t->tam = tam;
    t->tipoBase = tipoBase;
    t->siguente = NULL;
    t->anterior = NULL;
    return t;
}

/*
--Nombre Funcion: PTT_push()
--Descripcion: Se hace un push a la pila de Tablas de tipos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 27 Mayo 2020
*/
void PTT_push(Pila_T_Tipos *pila, T_Tipos *tabla){
    if (pila == NULL) { printf("ERROR: No existe pila\n"); }
    if (tabla == NULL) { printf("ERROR: No existe tabla\n"); }
    if (pila->num == 0 || pila->inicio == NULL){
        pila->inicio = tabla;
        pila->cabeza = tabla;
        pila->num = 1;
    } else {
        pila->cabeza->siguente = tabla;
        tabla->anterior = pila->cabeza;
        pila->cabeza = tabla;
        pila->num = pila->num + 1;
    }

}

/*
--Nombre Funcion: TT_nuevoRegistro()
--Descripcion: Se agrega una registro de tipo a una tabla de tipos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 27 Mayo 2020
*/
void TT_nuevoRegistro(T_Tipos *tabla, Tipo *t){
    if (tabla == NULL) { printf("ERROR: No existe tabla\n"); }
    if (t == NULL) { printf("ERROR: No existe el tipo\n"); }
    if (tabla->inicio == NULL || tabla->num == 0) {
        tabla->inicio = t;
        tabla->cabeza = t;
        tabla->num = 1;
        t->id = 0;
    } else {
        tabla->cabeza->siguente = t;
        t->anterior = tabla->cabeza;
        tabla->cabeza = t;
        t->id = tabla->num;
        tabla->num = tabla->num + 1;
    }
}

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
void PTT_eliminar(){}

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
T_Tipos TT_pop(){}

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
void T_eliminar(){}

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
void PTT_imprimir(){}

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
void TT_imprimir(){}

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
void T_imprimir(){}

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
int TT_getTam(int tipo){}

#endif
