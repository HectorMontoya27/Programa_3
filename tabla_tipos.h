#ifndef TABLA_TIPOS_H
#define TABLA_TIPOS_H
#include <stdio.h>

/* Creacion */
Pila_T_Tipos* PTT_nueva();                             //Lista
T_Tipos* TT_nueva();                                   //Lista
Tipo* T_nuevo();    //Lista
void PTT_push(Pila_T_Tipos *pila, T_Simbolos *tabla);  //Lista
void TT_nuevoRegistro(T_Tipos* tabla);                 //Lista
/* Eliminacion */
void PTT_eliminar();                                      //Pendiente
T_Simbolos TT_pop();                                      //Pendiente
void T_eliminar();                                        //Pendiente
/* Impresion */
void PTT_imprimir();                                      //Pendiente
void TT_imprimir();                                       //Pendiente
void T_imprimir();                                        //Pendiente
/* Busqueda */
void TT_getTam(int tipo);

#endid
