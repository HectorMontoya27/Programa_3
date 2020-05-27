#ifndef DATOS_H
#define DATOS_H

typedef struct {
    int pos;
    char id[32];
    int dir;
    int tipo;
    var char[32];
    Simbolo *siguente;
} Simbolo;

typedef struct {
    int id;
    char nombre[10];
    int tam;
    int tipoBase;
    Tipo *siguente;
} Tipo;

typedef struct {
    simbolo *inicio;
    simbolo *cabeza;
    int num;
    T_Simbolos *siguente;
} T_Simbolos;

typedef struct {
    tipo *inicio;
    tipo *cabeza;
    int num;
    T_Tipos *siguente;
} T_Tipos;

typedef struct {
    T_Simbolos *inicio;
    T_Simbolos *cabeza;
    int num;
} Pila_T_Timbolos;

typedef struct {
    T_Tipos *inicio;
    T_Tipos *cabeza;
    int num;
} Pila_T_Tipos;

#endif
