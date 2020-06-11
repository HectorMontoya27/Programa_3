#ifndef DATOS_H
#define DATOS_H

typedef struct REGISTRO registroChar;
typedef struct LISTA listaChar;
typedef struct ARG arg;
typedef struct LIST_ARG listaArg;
typedef struct SIMBOLO Simbolo;
typedef struct TIPO Tipo;
typedef struct T_SIMBOLOS T_Simbolos;
typedef struct T_TIPOS T_Tipos;
typedef struct PILA_T_SIMBOLOS Pila_T_Simbolos;
typedef struct PILA_T_TIPOS Pila_T_Tipos;

/* Registro */
struct REGISTRO{
    char resgisttro[16];
    registroChar *siguente;
    registroChar *anterior;
};

/* Lista de registros */
struct LISTA{
    registroChar *inicio;
    int tam;
};

/* Argumento */
struct ARG{
    int tipo;
    arg *siguente;
};

/* Lista de argumentos */
struct LIST_ARG{
    arg *inicio;
    int tam;
};

/* Registro de simbolos */
struct SIMBOLO{
    int pos;
    char id[32];
    int dir;
    int tipo;
    char var[32];
    listaArg *lista;
    int numArgs;
    Simbolo *siguente;
    Simbolo *anterior;
};

/* Registro de tipo */
struct TIPO{
    int id;
    char nombre[20];
    int tam;
    int tipoBase;
    T_Simbolos *estructura;
    Tipo *siguente;
    Tipo *anterior;
};

/* Tabla de simbolos */
struct T_SIMBOLOS{
    char nombre[32];
    int dirMax;
    Simbolo *inicio;
    Simbolo *cabeza;
    int num;
    T_Tipos *tt;
    T_Simbolos *siguente;
    T_Simbolos *anterior;
};

/* Tabla de tipos */
struct T_TIPOS{
    char nombre[32];
    Tipo *inicio;
    Tipo *cabeza;
    int num;
    T_Tipos *siguente;
    T_Tipos *anterior;
};

/* Pila de tablas de simbolos */
struct PILA_T_SIMBOLOS{
    T_Simbolos *inicio;
    T_Simbolos *cabeza;
    int num;
};

/* Pila de tablas de tipos */
struct PILA_T_TIPOS{
    T_Tipos *inicio;
    T_Tipos *cabeza;
    int num;
};

#endif
