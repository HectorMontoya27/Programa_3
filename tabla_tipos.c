#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"
#include "tabla_tipos.h"

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
--Fecha de modificacion: 30 Mayo 2020
--Autor modificacion: Héctor Montoya
--Descripcion de modificacion: Se agrego la inicializacion de NULL a las variables
*/
Pila_T_Tipos* PTT_nueva(){
    Pila_T_Tipos *pila;
    pila = (Pila_T_Tipos *)malloc(sizeof(Pila_T_Tipos));
    pila->num = 0;
    pila->inicio = NULL;
    pila->cabeza = NULL;
    return pila;
}

/*
--Nombre Funcion: TT_nueva()
--Descripcion: Creacion de una nueva tabla de tipos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 27 Mayo 2020
--Fecha de modificacion: 30 Mayo 2020
--Autor modificacion: Héctor Montoya
--Descripcion de modificacion: Se agrego la inicializacion de NULL a las variables
*/
T_Tipos* TT_nueva(char nombre[]){
    T_Tipos *tabla;
    tabla = (T_Tipos *)malloc(sizeof(T_Tipos));
    tabla->num = 0;
    strcpy(tabla->nombre,nombre);
    tabla->inicio = NULL;
    tabla->cabeza = NULL;
    tabla->siguente = NULL;
    tabla->anterior = NULL;
    return tabla;
}

/*
--Nombre Funcion: T_nuevo()
--Descripcion: Creacion de un nuevo registro de Tipo
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 27 Mayo 2020
*/
Tipo* T_nuevo(char nombre[], int tam, int tipoBase, T_Simbolos *tabla){
    Tipo *t;
    t = malloc(sizeof(Tipo));
    t->id = -1;
    strcpy(t->nombre,nombre);
    t->tam = tam;
    t->siguente = NULL;
    t->anterior = NULL;
    t->tipoBase = tipoBase;
    t->estructura = NULL;
    if (tipoBase == -1) { t->estructura = tabla; }
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
int TT_nuevoRegistro(T_Tipos *tabla, Tipo *t){
    if (tabla == NULL) { printf("ERROR: No existe tabla\n"); return -1; }
    if (t == NULL) { printf("ERROR: No existe el tipo\n"); return -1; }
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
    return tabla->num;
}

/*
--Nombre Funcion: PTT_eliminar()
--Descripcion: Eliminacion de la pila y liberar cada tabla de la pila
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 28 Mayo 2020
*/
void PTT_eliminar(Pila_T_Tipos *pila){
    while (pila->num != 0) {
        TT_eliminar(PTT_pop(pila));
    }
    free(pila);
}

/*
--Nombre Funcion: PTT_pop()
--Descripcion: Se le aplica un pop a la pila de tablas de tipos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 28 Mayo 2020
*/
T_Tipos* PTT_pop(Pila_T_Tipos *pila){
    T_Tipos *tabla;
    if(pila->cabeza == NULL) { return NULL; }
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
--Nombre Funcion: TT_eliminar()
--Descripcion: Se libera la memoria de la tabla pero primero se liberan los registros
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 28 Mayo 2020
*/
void TT_eliminar(T_Tipos *tabla){
    Tipo *t, *t2;
    t = tabla->inicio;
    while (t != NULL) {
        t2 = t->siguente;
        T_eliminar(t);
        t = t2;
    }
    free(tabla);
}

/*
--Nombre Funcion: T_eliminar()
--Descripcion: Liberacion de memoria para un tipo
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 28 Mayo 2020
*/
void T_eliminar(Tipo *t){
    free(t);
}

/*
--Nombre Funcion: PTT_imprimir()
--Descripcion: Impresion de un pila de tablas de tipos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 28 Mayo 2020
*/
void PTT_imprimir(Pila_T_Tipos *pila){
    T_Tipos *tabla;
    tabla = pila->inicio;
    printf("\n\t\tTABLAS DE LA PILA\n");
    while (tabla != NULL) {
        printf("\n");
        TT_imprimir(tabla);
        tabla = tabla->siguente;
    }
}

/*
--Nombre Funcion: TT_imprimir()
--Descripcion: Impresion de la tabla de tipos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 28 Mayo 2020
*/
void TT_imprimir(T_Tipos *tabla){
    Tipo *t;
    if (tabla != NULL) {
        t = tabla->inicio;
        printf("\tTabla de Tipos \"%s\"\n", tabla->nombre);
        printf("\tID\tNombre\ttam\tTipoBase\n");
        while (t != NULL) {
            T_imprimir(t);
            t = t->siguente;
        }
    }
}

/*
--Nombre Funcion: T_imprimir()
--Descripcion: Impresion de la un tipo
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 28 Mayo 2020
*/
void T_imprimir(Tipo *t){
    printf("\t%d\t%s\t%d\t%d\n", t->id, t->nombre, t->tam, t->tipoBase);
}

/*
--Nombre Funcion: TT_getTam()
--Descripcion: Se hace una busqueda del tamaño de un tipo
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 28 Mayo 2020
*/
int TT_getTam(T_Tipos *tabla, int tipo){
    Tipo *t;
    if (tabla == NULL || tipo < 0 || tabla->inicio == NULL) { return -1; }
    t = tabla->inicio;
    while (t != NULL) {
        if (t->id == tipo) { return t->tam; }
        t = t->siguente;
    }
    return -1;
}

/*
--Nombre Funcion: getTablaGlobal()
--Descripcion: Nos regeresa la tabla global de una pila de tabla de tipos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 09 Junio 2020
*/
T_Tipos* getTablaGlobal(Pila_T_Tipos *pila){
    if (pila == NULL) { return NULL; }
    return pila->inicio;
}

/*
--Nombre Funcion: getTS()
--Descripcion: Regresa una tabla de simbolos asociada al tipo definido
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 09 Junio 2020
*/
T_Simbolos* getTS(T_Tipos *tabla, int id){
    if (tabla == NULL || id < 0) { return NULL; }
    Tipo *t;
    t = tabla->inicio;
    while (t != NULL) {
        if (t->id == id) { return t->estructura; }
        t = t->siguente;
    }
    return NULL;
}

/*
--Nombre Funcion: getNombre_TT()
--Descripcion: Regresa el nombre del tipo asociada al id
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 09 Junio 2020
*/
char* getNombre_TT(T_Tipos *tabla, int id){
    if (tabla == NULL) { return NULL; }
    Tipo *t;
    t = tabla->inicio;
    while (t != NULL) {
        if (t->id == id) { return t->nombre; }
        t = t->siguente;
    }
    return NULL;
}
