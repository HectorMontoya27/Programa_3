#ifndef DATOS_H
#define DATOS_H

/* Argumento */
typedef struct ARG arg;
struct ARG{
    int tipo;
    arg *siguente;
};

/* Lista de argumentos */
typedef struct LIST_ARG list_arg;
struct LIST_ARG{
    arg *inicio;
    arg *final;
    int tam;
};

/* Registro de simbolos */
typedef struct SIMBOLO Simbolo;
struct SIMBOLO{
    int pos;
    char id[32];
    int dir;
    int tipo;
    char var[32];
    list_arg *lista;
    int numArgs;
    Simbolo *siguente;
    Simbolo *anterior;
};

/* Registro de tipo */
typedef struct TIPO Tipo;
struct TIPO{
    int id;
    char nombre[10];
    int tam;
    int tipoBase;
    Tipo *siguente;
    Tipo *anterior;
};

/* Tabla de simbolos */
typedef struct T_SIMBOLOS T_Simbolos;
struct T_SIMBOLOS{
    char nombre[32];
    Simbolo *inicio;
    Simbolo *cabeza;
    int num;
    T_Simbolos *siguente;
    T_Simbolos *anterior;
};

/* Tabla de tipos */
typedef struct T_TIPOS T_Tipos;
struct T_TIPOS{
    char nombre[32];
    Tipo *inicio;
    Tipo *cabeza;
    int num;
    T_Tipos *siguente;
    T_Tipos *anterior;
};

/* Pila de tablas de simbolos */
typedef struct PILA_T_SIMBOLOS Pila_T_Simbolos;
struct PILA_T_SIMBOLOS{
    T_Simbolos *inicio;
    T_Simbolos *cabeza;
    int num;
};

/* Pila de tablas de tipos */
typedef struct PILA_T_TIPOS Pila_T_Tipos;
struct PILA_T_TIPOS{
    T_Tipos *inicio;
    T_Tipos *cabeza;
    int num;
};

#endif
