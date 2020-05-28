#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"
#include "tabla_tipos.h"

/* -------------------------Declaracion de Funciones -------------------------- */
/* Creacion */
Pila_T_Simbolos* PTS_nueva();                                                         //Lista
T_Simbolos* TS_nueva(char nombre[]);                                                  //Lista
Simbolo* S_nuevo(char id[], int tipo,char var[], list_arg* lista, int numArgs);       //Lista
void PTS_push(Pila_T_Simbolos *pila, T_Simbolos *tabla);                              //Lista
void TS_nuevoRegistro(T_Simbolos* tabla, Simbolo* sim);                               //Lista
/* Eliminacion */
void PTS_eliminar(Pila_T_Simbolos *pila);                                             //Lista
T_Simbolos* PTS_pop(Pila_T_Simbolos *pila);                                           //Lista
void TS_eliminar(T_Simbolos *tabla);                                                  //Lista
void S_eliminar(Simbolo *sim);                                                        //Lista
/* Impresion */
void PTS_imprimir();                                                                  //Lista
void TS_imprimir();                                                                   //Lista
void S_imprimir();                                                                    //Lista
/* Busqueda */

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
--Nombre Funcion: PTS_nueva()
--Descripcion: Creacion de memoria para una nueva pila de tablas de simbolos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 26 Mayo 2020
*/
Pila_T_Simbolos* PTS_nueva(){
    Pila_T_Simbolos *pila;
    pila = (Pila_T_Simbolos *)malloc(sizeof(Pila_T_Simbolos));
    pila->num = 0;
    return pila;
}

/*
--Nombre Funcion: TS_nueva()
--Descripcion: Creacion de memoria para una tabla de simbolos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 26 Mayo 2020
--Fecha de modificacion: 27 Mayo 2020
--Autor modificacion: Héctor Montoya Pérez
--Descripcion de modificacion: Se agrega un argumento para el nombre de la tabla
--Fecha de modificacion: 27 Mayo 2020
--Autor modificacion: Héctor Montoya Pérez
--Descripcion de modificacion: Se agrego la inicializacion de una nueva variable dirMax
*/
T_Simbolos* TS_nueva(char nombre[]){
    T_Simbolos *tabla;
    tabla = (T_Simbolos *)malloc(sizeof(T_Simbolos));
    strcpy(tabla->nombre,nombre);
    tabla->dirMax = 0;
    tabla->num = 0;
    return tabla;
}

/*
--Nombre Funcion: S_nueva()
--Descripcion: Creacion de memoria para un nuevo registro de simbolos con parametros
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 26 Mayo 2020
--Fecha de modificacion: 27 Mayo 2020
--Autor modificacion: Héctor Montoya Pérez
--Descripcion de modificacion: Se agrego argumentos a la funcion para agregar la lista de argumentos y tamaño
--Fecha de modificacion: 27 Mayo 2020
--Autor modificacion: Héctor Montoya Pérez
--Descripcion de modificacion: Se inicializaron las variables faltantes
*/
Simbolo* S_nuevo(char id[], int tipo,char var[], list_arg* lista, int numArgs){
    Simbolo *sim;
    sim = malloc(sizeof(Simbolo));
    sim->pos = -1;
    strcpy(sim->id,id);
    sim->dir = -1;
    sim->tipo = tipo;
    strcpy(sim->var,var);
    sim->lista = lista;
    sim->numArgs = numArgs;
    sim->siguente = NULL;
    sim->anterior = NULL;
    return sim;
}

/*
--Nombre Funcion: PTS_push()
--Descripcion: Push a la pila de Tabla de simbolos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 26 Mayo 2020
--Fecha de modificacion: 27 Mayo 2020
--Autor modificacion: Se agregaron corretamente la validacion de la existencia de los argumentos
--Descripcion de modificacion:
*/
void PTS_push(Pila_T_Simbolos *pila, T_Simbolos *tabla){
    if (pila == NULL) { printf("ERROR: No existe pila\n"); }
    if (tabla == NULL) { printf("ERROR: No existe tabla\n"); }
    if (pila->num == 0 || pila->inicio == NULL) {
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
--Nombre Funcion: TS_nuevoRegistro()
--Descripcion: Nuevo registro a una tabla de simbolos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 26 Mayo 2020
--Fecha de modificacion: 27 Mayo 2020
--Autor modificacion: Héctor Montoya Pérez
--Descripcion de modificacion: Se agrego una nueva variable dirMax que contendra la direccion donde se almacena
                               el siguente simbolo y se agregaron las correctas validaciones de los argumentos
*/
void TS_nuevoRegistro(T_Simbolos* tabla, Simbolo* sim){
    if (tabla == NULL) { printf("ERROR: No existe tabla\n"); }
    if (sim == NULL) { printf("ERROR: No existe el simbolo\n"); }
    if (tabla->num == 0 || tabla->inicio == NULL){
        tabla->inicio = sim;
        tabla->cabeza = sim;
        tabla->num = 1;
        sim->pos = 0;
        sim->dir = 0;
        tabla->dirMax = tabla->dirMax + TT_getTam(sim->tipo);
    } else {
        tabla->cabeza->siguente = sim;
        sim->anterior = tabla->cabeza;
        tabla->cabeza = sim;
        sim->dir = tabla->dirMax;
        tabla->dirMax = tabla->dirMax + TT_getTam(sim->tipo);
        sim->pos = tabla->num;
        tabla->num = tabla->num + 1;
    }
}

/*
--Nombre Funcion: PTS_eliminar()
--Descripcion: Se hace la eliminacion de la pila pero primero se hace la eliminacion de la pila
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 27 Mayo 2020
*/
void PTS_eliminar(Pila_T_Simbolos *pila){
    while (pila->num != 0) {
        TS_eliminar(PTS_pop(pila));
    }
    free(pila);
}

/*
--Nombre Funcion: PTS_pop()
--Descripcion: Se hace un POP a la pila de tablas de simbolos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 27 Mayo 2020
*/
T_Simbolos* PTS_pop(Pila_T_Simbolos *pila){
    T_Simbolos *tabla;
    if (pila->cabeza == NULL) { return NULL; }
    tabla = pila->cabeza;
    pila->cabeza = tabla->anterior;
    if (pila->cabeza != NULL) {pila->cabeza->siguente = NULL;}
    else {pila->inicio = NULL;}
    pila->num = pila->num - 1;
    tabla->siguente = NULL;
    tabla->anterior = NULL;
    return tabla;
}

/*
--Nombre Funcion: TS_eliminar()
--Descripcion: Se hace la liberacion de memoria de una tabla junto con sus registros
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 27 Mayo 2020
*/
void TS_eliminar(T_Simbolos *tabla){
    Simbolo *sim, *sim2;
    sim = tabla->inicio;
    while (sim != NULL) {
        sim2 = sim->siguente;
        S_eliminar(sim);
        sim = sim2;
    }
    free(tabla);
}

/*
--Nombre Funcion: S_eliminar()
--Descripcion: Se libera la memoria de un registro para simbolo
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 27 Mayo 2020
*/
void S_eliminar(Simbolo *sim){
    free(sim);
}

/*
--Nombre Funcion: PTS_imprimir()
--Descripcion: Funcion para imprimir una pila de tabla de simbolos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 26 Mayo 2020
*/
void PTS_imprimir(Pila_T_Simbolos *pila){
    T_Simbolos *tabla;
    tabla = pila->inicio;
    printf("   TABLAS DE LA PILA\n");
    while (tabla != NULL) {
        printf("\n");
        TS_imprimir(tabla);
        tabla = tabla->siguente;
    }
}

/*
--Nombre Funcion: TS_imprimir()
--Descripcion: Funcion para imprimir una tabla de simbolos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 26 Mayo 2020
*/
void TS_imprimir(T_Simbolos *tabla){
    Simbolo *sim;
    sim = tabla->inicio;
    printf("\tPos\tID\tDir\tTipo\tVar\n");
    while (sim != NULL) {
        S_imprimir(sim);
        sim = sim->siguente;
    }
}

/*
--Nombre Funcion: S_imprimir()
--Descripcion: Funcion para imprimir un registro
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 26 Mayo 2020
*/
void S_imprimir(Simbolo *sim){
    printf("\t%d\t%s\t%d\t%d\t%s\n", sim->pos, sim->id, sim->dir, sim->tipo, sim->var);
}

#endif
