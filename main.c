#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"
#include "lista_arg.h"
#include "tabla_simbolos.h"
#include "tabla_tipos.h"

int main(int argc, char const *argv[]) {
    // Declaraciones
    Pila_T_Tipos *nuevaPilaT;
    Pila_T_Simbolos *nuevaPilaS;
    listaArg *nuevaLista;
    int valor;
    //Creacion de lista de argumentos
    nuevaLista = crearListaArg();
    // Creacion de pilas
    nuevaPilaT = PTT_nueva();
    nuevaPilaS = PTS_nueva();
    // Insertar valores a la lista de argumentos
    agregarArg(nuevaLista,0);
    agregarArg(nuevaLista,0);
    agregarArg(nuevaLista,1);
    // Nueva tabla de tipos global y se inicializa
    PTT_push(nuevaPilaT,TT_nueva("Global"));
    valor = TT_nuevoRegistro(nuevaPilaT->inicio,T_nuevo("ent",4,-2,NULL));
    printf("Se agrego un registro en la tabla de tipos en la posicion: %d\n", valor);
    valor = TT_nuevoRegistro(nuevaPilaT->inicio,T_nuevo("real",4,-2,NULL));
    printf("Se agrego un registro en la tabla de tipos en la posicion: %d\n", valor);
    valor = TT_nuevoRegistro(nuevaPilaT->inicio,T_nuevo("dreal",8,-2,NULL));
    printf("Se agrego un registro en la tabla de tipos en la posicion: %d\n", valor);
    valor = TT_nuevoRegistro(nuevaPilaT->inicio,T_nuevo("array",12,0,NULL));
    printf("Se agrego un registro en la tabla de tipos en la posicion: %d\n", valor);
    // Nueva tabla de tipos llamada suma y se inicializa
    PTT_push(nuevaPilaT,TT_nueva("Suma"));
    valor = TT_nuevoRegistro(nuevaPilaT->cabeza,T_nuevo("ent",4,-2,NULL));
    printf("Se agrego un registro en la tabla de tipos en la posicion: %d\n", valor);
    valor = TT_nuevoRegistro(nuevaPilaT->cabeza,T_nuevo("real",4,-2,NULL));
    printf("Se agrego un registro en la tabla de tipos en la posicion: %d\n", valor);
    valor = TT_nuevoRegistro(nuevaPilaT->cabeza,T_nuevo("dreal",8,-2,NULL));
    printf("Se agrego un registro en la tabla de tipos en la posicion: %d\n", valor);
    valor = TT_nuevoRegistro(nuevaPilaT->cabeza,T_nuevo("array",12,0,NULL));
    printf("Se agrego un registro en la tabla de tipos en la posicion: %d\n", valor);
    valor = TT_nuevoRegistro(nuevaPilaT->cabeza,T_nuevo("estructura",8,-1,TS_nueva("estructura")));
    printf("Se agrego un registro en la tabla de tipos en la posicion: %d\n", valor);
    getTS(nuevaPilaT->cabeza,4)->tt = TT_nueva("estructura");
    TT_nuevoRegistro(getTT(getTS(nuevaPilaT->cabeza,4)),T_nuevo("ent",4,-2,NULL));
    TT_nuevoRegistro(getTT(getTS(nuevaPilaT->cabeza,4)),T_nuevo("real",4,-2,NULL));
    TS_nuevoRegistro(getTT(getTS(nuevaPilaT->cabeza,4)),getTS(nuevaPilaT->cabeza,4),S_nuevo("x",0,"var",NULL));
    TS_nuevoRegistro(getTT(getTS(nuevaPilaT->cabeza,4)),getTS(nuevaPilaT->cabeza,4),S_nuevo("y",1,"var",NULL));
    // Nueva tabla de simbolos global y se inicializa
    PTS_push(nuevaPilaS,TS_nueva("Global"));
    TS_nuevoRegistro(nuevaPilaT->inicio,nuevaPilaS->inicio,S_nuevo("x",0,"var",NULL));
    TS_nuevoRegistro(nuevaPilaT->inicio,nuevaPilaS->inicio,S_nuevo("y",1,"var",NULL));
    TS_nuevoRegistro(nuevaPilaT->inicio,nuevaPilaS->inicio,S_nuevo("variab",3,"var",NULL));
    TS_nuevoRegistro(nuevaPilaT->inicio,nuevaPilaS->inicio,S_nuevo("gh",2,"var",NULL));
    TS_nuevoRegistro(nuevaPilaT->inicio,nuevaPilaS->inicio,S_nuevo("gh",-1,"fun",nuevaLista));
    PTS_push(nuevaPilaS,TS_nueva("Suma"));
    TS_nuevoRegistro(nuevaPilaT->cabeza,nuevaPilaS->cabeza,S_nuevo("tipo",0,"var",NULL));
    TS_nuevoRegistro(nuevaPilaT->cabeza,nuevaPilaS->cabeza,S_nuevo("sd",0,"var",NULL));
    TS_nuevoRegistro(nuevaPilaT->cabeza,nuevaPilaS->cabeza,S_nuevo("cd",1,"var",NULL));
    TS_nuevoRegistro(nuevaPilaT->cabeza,nuevaPilaS->cabeza,S_nuevo("ty",0,"fun",nuevaLista));
    TS_nuevoRegistro(nuevaPilaT->cabeza,nuevaPilaS->cabeza,S_nuevo("es",4,"estru",NULL));
    // Más pruebas de funciones
    printf("El tamaño del tipo 0 de la tabla en la cima de la pila de tipos es: %d\n", TT_getTam(getTablaGlobal(nuevaPilaT),0));
    printf("El nombre del tipo 0 de la tabla en la cima de la pila de tipos es: %s\n", getNombre_TT(getTablaGlobal(nuevaPilaT),0));
    printf("Lo que nos regresa la funcion existeID() de una tabla de simbolos es: %d\n", existeID(nuevaPilaS->cabeza,"ty"));
    printf("El tipo que nos regresa la funcion getTipo() de una tabla de simbolos es: %d\n", getTipo(nuevaPilaS->cabeza,"ty"));
    printf("La direccion que regresa la funcion getDir() de una tabla de simbolos es: %d\n", getDir(nuevaPilaS->cabeza,"ty"));
    printf("El tipo de variable que regresa la funcion getVar_TS() de una tabla de simbolos es: %s\n", getVar_TS(nuevaPilaS->cabeza,"ty"));
    printf("Impresion de un simbolo regresado por getSimbolo()\t");
    S_imprimir(getSimbolo(nuevaPilaS->cabeza,2));
    // Impresion de las pilas
    PTT_imprimir(nuevaPilaT);
    TT_imprimir(getTT(getTS(nuevaPilaT->cabeza,4)));
    PTS_imprimir(nuevaPilaS);
    TS_imprimir(getTS(nuevaPilaT->cabeza,4));
    TT_eliminar(getTT(getTS(nuevaPilaT->cabeza,4)));
    TS_eliminar(getTS(nuevaPilaT->cabeza,4));
    // Se elimina una tabla
    TS_eliminar(PTS_pop(nuevaPilaS));
    // Mostramos la pila
    PTS_imprimir(nuevaPilaS);
    // Eliminamos las pilas
    PTT_eliminar(nuevaPilaT);
    PTS_eliminar(nuevaPilaS);

    return 0;
}
