#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H
#include "datos.h"
#include "tabla_tipos.h"
#include "lista_arg.h"

/* -------------------------Declaracion de Funciones -------------------------- */
/* Creacion */
Pila_T_Simbolos* PTS_nueva();                                                         //Lista
T_Simbolos* TS_nueva(char nombre[]);                                                  //Lista
Simbolo* S_nuevo(char id[], int tipo,char var[], listaArg* lista);                    //Lista
void PTS_push(Pila_T_Simbolos *pila, T_Simbolos *tabla);                              //Lista
void TS_nuevoRegistro(T_Tipos *tablaT, T_Simbolos* tabla, Simbolo* sim);              //Lista
/* Eliminacion */
void PTS_eliminar(Pila_T_Simbolos *pila);                                             //Lista
T_Simbolos* PTS_pop(Pila_T_Simbolos *pila);                                           //Lista
void TS_eliminar(T_Simbolos *tabla);                                                  //Lista
void S_eliminar(Simbolo *sim);                                                        //Lista
/* Impresion */
void PTS_imprimir(Pila_T_Simbolos *pila);                                             //Lista
void TS_imprimir(T_Simbolos *tabla);                                                  //Lista
void S_imprimir(Simbolo *sim);                                                        //Lista
/* Busqueda */

#endif
