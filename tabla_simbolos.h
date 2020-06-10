#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H
#include "datos.h"
#include "tabla_tipos.h"
#include "lista_arg.h"

/* -------------------------Declaracion de Funciones -------------------------- */
/* Creacion */
Pila_T_Simbolos* PTS_nueva();                                                   //Lista
T_Simbolos* TS_nueva(char nombre[]);                                            //Lista
Simbolo* S_nuevo(char id[], int tipo,char var[], listaArg* lista);              //Lista
void PTS_push(Pila_T_Simbolos *pila, T_Simbolos *tabla);                        //Lista
void TS_nuevoRegistro(T_Tipos *tablaT, T_Simbolos* tabla, Simbolo* sim);        //Lista
/* Eliminacion */
void PTS_eliminar(Pila_T_Simbolos *pila);                                       //Lista
T_Simbolos* PTS_pop(Pila_T_Simbolos *pila);                                     //Lista
void TS_eliminar(T_Simbolos *tabla);                                            //Lista
void S_eliminar(Simbolo *sim);                                                  //Lista
/* Impresion */
void PTS_imprimir(Pila_T_Simbolos *pila);                                       //Lista
void TS_imprimir(T_Simbolos *tabla);                                            //Lista
void S_imprimir(Simbolo *sim);                                                  //Lista
/* Busqueda */
int existeID(T_Simbolos *sim, char id[]);                                       //Lista
Simbolo* getSimbolo(T_Simbolos *tabla, int posicion);                           //Lista
int getTipo(T_Simbolos *st, char id[]);                                         //Lista
listaArg* getArgs(T_Simbolos *ts, char id[]);                                   //Lista
T_Tipos* getTT(T_Simbolos *tabla);                                              //Lista
int getDir(T_Simbolos *st,char id[]);                                           //Pendiente
char* getVar_TS(T_Simbolos *st, char id[]);                                     //Pendiente


#endif
