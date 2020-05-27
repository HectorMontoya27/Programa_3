#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H
#include <stdio.h>
#include "tabla_tipos.h"

/* Creacion */
Pila_T_Simbolos* PTS_nueva();                             //Lista
T_Simbolos* TS_nueva();                                   //Lista
Simbolo* S_nuevo(char[32] id, int tipo,char[32] vars);    //Lista
void PTS_push(Pila_T_Simbolos *pila, T_Simbolos *tabla);  //Lista
void TS_nuevoRegistro(T_Simbolos* tabla);                 //Lista
/* Eliminacion */
void PTS_eliminar();                                      //Pendiente
T_Simbolos TS_pop();                                      //Pendiente
void S_eliminar();                                        //Pendiente
/* Impresion */
void PTS_imprimir();                                      //Pendiente
void TS_imprimir();                                       //Pendiente
void S_imprimir();                                        //Pendiente
/* Busqueda */


/* -------------------------------- Funciones -------------------------------- */

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/

/*
--Nombre Funcion: PTS_nueva()
--Descripcion: Creacion de memoria para una nueva pila de tablas de simbolos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 26 Mayo 2020
*/
Pila_T_Simbolos* PTS_nueva(){
    Pila_T_Simbolos *pila;
    pila = (Pila_T_Simbolos *)malloc(sizeof(Pila_T_Simbolos));
    pila.num = 0;
    return pila;
}

/*
--Nombre Funcion: TS_nueva()
--Descripcion: Creacion de memoria para una tabla de simbolos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 26 Mayo 2020
*/
T_Simbolos* TS_nueva(){
    T_Simbolos *tabla;
    tabla = (T_Simbolos *)malloc(sizeof(T_Simbolos));
    tabla.num = 0;
    return tabla;
}

/*
--Nombre Funcion: S_nueva()
--Descripcion: Creacion de memoria para un nuevo registro de simbolos con parametros
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 26 Mayo 2020
*/
Simbolo* S_nuevo(char[32] id, int tipo,char[32] var){
    Simbolo *sim;
    sim = (Simbolo *)malloc(sizeof(Simbolo));
    sim.id = id;
    sim.dir = dir;
    sim.tipo = tipo;
    sim.var = var;
    return sim;
}

/*
--Nombre Funcion: PTS_push()
--Descripcion: Push a la pila de Tabla de simbolos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 26 Mayo 2020
*/
void PTS_push(Pila_T_Simbolos *pila, T_Simbolos *tabla){
    if (pila = NULL){ printf("No existe pila\n"); }
    if (pila.num = 0 || pila.inicio = NULL) {
        pila.inicio = tabla;
        pila.cabeza = tabla;
        pila.num = 1;
    } else {
        pila.cabeza.siguente = tabla;
        tabla.anterior = pila.cabeza;
        pila.cabeza = tabla;
        pila.num = pila.num + 1;
    }
}

/*
--Nombre Funcion: TS_nuevoRegistro()
--Descripcion: Nuevo registro a una tabla de simbolos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 26 Mayo 2020
*/
void TS_nuevoRegistro(T_Simbolos* tabla, Simbolo* sim){
    if (tabla = NULL){ printf("No existe tabla\n"); }
    if (tabla.num = 0 || tabla.inicio = NULL){
        tabla.inicio = sim;
        tabla.cabeza = sim;
        tabla.num = 1;
        sim.pos = 1;
        sim.dir = 0;
    } else {
        sim.dir = tabla.cabeza.dir + TT_getTam(sim.tipo);
        tabla.cabeza.siguente = sim;
        sim.anterior = tabla.cabeza;
        tabla.cabeza = sim;
        tabla.num = tabla.num + 1;
        sim.pos = tabla.num;
    }
}

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
void PTS_eliminar(){}

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
T_Simbolos TS_pop(){}

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
void S_eliminar(){}

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
void PTS_imprimir(){}

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
void TS_imprimir(){}

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
void S_imprimir(){}

#endif
