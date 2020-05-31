#ifndef TABLA_TIPOS_H
#define TABLA_TIPOS_H
#include "datos.h"

/* -------------------------Declaracion de Funciones -------------------------- */
/* Creacion */
Pila_T_Tipos* PTT_nueva();                                      //Lista
T_Tipos* TT_nueva(char nombre[]);                               //Lista
Tipo* T_nuevo(char nombre[], int tam, int tipoBase);            //Lista
void PTT_push(Pila_T_Tipos *pila, T_Tipos *tabla);              //Lista
void TT_nuevoRegistro(T_Tipos *tabla, Tipo *t);                 //Lista
/* Eliminacion */
void PTT_eliminar(Pila_T_Tipos *pila);                          //Lista
T_Tipos* PTT_pop(Pila_T_Tipos *pila);                           //Lista
void TT_eliminar(T_Tipos *tabla);                               //Lista
void T_eliminar(Tipo *t);                                       //Lista
/* Impresion */
void PTT_imprimir(Pila_T_Tipos *pila);                          //Lista
void TT_imprimir(T_Tipos *tabla);                               //Lista
void T_imprimir(Tipo *t);                                       //Lista
/* Busqueda */
int TT_getTam(T_Tipos *tabla, int tipo);                        //Lista

#endif
