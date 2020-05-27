#ifndef DATOS_H
#define DATOS_H

typedef struct {
    int pos;
    char id[32];
    int dir;
    int tipo;
    char var[32];
    Simbolo *siguente;
    Simbolo *anterior;
} Simbolo;

typedef struct {
    int id;
    char nombre[10];
    int tam;
    int tipoBase;
    Tipo *siguente;
    Tipo *anterior;
} Tipo;

typedef struct {
    simbolo *inicio;
    simbolo *cabeza;
    int num;
    T_Simbolos *siguente;
    T_Simbolos *anterior;
} T_Simbolos;

typedef struct {
    tipo *inicio;
    tipo *cabeza;
    int num;
    T_Tipos *siguente;
    T_Tipos *anterior;
} T_Tipos;

typedef struct {
    T_Simbolos *inicio;
    T_Simbolos *cabeza;
    int num;
} Pila_T_Simbolos;

typedef struct {
    T_Tipos *inicio;
    T_Tipos *cabeza;
    int num;
} Pila_T_Tipos;

#endif
