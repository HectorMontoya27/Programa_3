#ifndef DATOS_H
#define DATOS_H

/* Argumento */
typedef struct {
    int tipo;
    arg *siguente;
} arg;

/* Lista de argumentos */
typedef struct {
    arg *inicio;
    arg *final;
    int tam;
} list_arg;

/* Registro de simbolos */
typedef struct {
    int pos;
    char id[32];
    int dir;
    int tipo;
    char var[32];
    list_arg *lista;
    int numArgs;
    Simbolo *siguente;
    Simbolo *anterior;
} Simbolo;

/* Registro de tipo */
typedef struct {
    int id;
    char nombre[10];
    int tam;
    int tipoBase;
    Tipo *siguente;
    Tipo *anterior;
} Tipo;

/* Tabla de simbolos */
typedef struct {
    char nombre[32];
    simbolo *inicio;
    simbolo *cabeza;
    int num;
    T_Simbolos *siguente;
    T_Simbolos *anterior;
} T_Simbolos;

/* Tabla de tipos */
typedef struct {
    char nombre[32];
    tipo *inicio;
    tipo *cabeza;
    int num;
    T_Tipos *siguente;
    T_Tipos *anterior;
} T_Tipos;

/* Pila de tablas de simbolos */
typedef struct {
    T_Simbolos *inicio;
    T_Simbolos *cabeza;
    int num;
} Pila_T_Simbolos;

/* Pila de tablas de tipos */
typedef struct {
    T_Tipos *inicio;
    T_Tipos *cabeza;
    int num;
} Pila_T_Tipos;

#endif
