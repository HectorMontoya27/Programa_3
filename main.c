#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"
#include "lista_arg.h"
#include "tabla_simbolos.h"
#include "tabla_tipos.h"

int main(int argc, char const *argv[]) {
    Pila_T_Tipos *nuevaPilaT;
    Pila_T_Simbolos *nuevaPilaS;
    listaArg *nuevaLista;
    nuevaLista = crearListaArg();
    nuevaPilaT = PTT_nueva();
    nuevaPilaS = PTS_nueva();
    agregarArg(nuevaLista,0);
    agregarArg(nuevaLista,0);
    agregarArg(nuevaLista,1);
    PTT_push(nuevaPilaT,TT_nueva("Global"));
    TT_nuevoRegistro(nuevaPilaT->inicio,T_nuevo("ent",4,-1));
    TT_nuevoRegistro(nuevaPilaT->inicio,T_nuevo("real",4,-1));
    TT_nuevoRegistro(nuevaPilaT->inicio,T_nuevo("dreal",8,-1));
    TT_nuevoRegistro(nuevaPilaT->inicio,T_nuevo("array",12,0));
    PTT_push(nuevaPilaT,TT_nueva("Suma"));
    TT_nuevoRegistro(nuevaPilaT->cabeza,T_nuevo("ent",4,-1));
    TT_nuevoRegistro(nuevaPilaT->cabeza,T_nuevo("real",4,-1));
    TT_nuevoRegistro(nuevaPilaT->cabeza,T_nuevo("dreal",8,-1));
    TT_nuevoRegistro(nuevaPilaT->cabeza,T_nuevo("array",12,0));
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
    PTT_imprimir(nuevaPilaT);
    PTS_imprimir(nuevaPilaS);
    TS_eliminar(PTS_pop(nuevaPilaS));
    PTS_imprimir(nuevaPilaS);
    PTT_eliminar(nuevaPilaT);
    PTS_eliminar(nuevaPilaS);

    return 0;
}
