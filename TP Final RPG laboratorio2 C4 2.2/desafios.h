#ifndef DESAFIOS_H_INCLUDED
#define DESAFIOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DESAFIOS "desafios.dat"
#include "mounstruo.h"

typedef struct{
    int idDesafio;
    char tipoDesafio;   /// P=Pelea , R=Recompensa
    char descripcionDesafio[100];
    int dificultadDesafio; 	/// 1-2-3 (Facil-Medio-Dificil )
    STmonstruo monstruo;
    char preguntaProxDesafio[100];
    int desafioEliminado;
}STdesafio;

typedef struct{
    int idDesafio;
    char tipoDesafio;
    char descripcionDesafio[100];
    int dificultadDesafio; 	/// 1-2-3 (Facil-Medio-Dificil )
    int idMonstruo;
    char preguntaProxDesafio[100];
    int desafioEliminado;
}REGdesafio;



typedef struct{
    STdesafio desafio;
    struct nodoArbolDesa*izquierda;
    struct nodoArbolDesa*derecha;
}nodoArbolDesa;


nodoArbolDesa*inicArbolDesafio();
nodoArbolDesa*crearNodoArbolDesafio(STdesafio desafio);
nodoArbolDesa*insertarNodoArbolDesafio(nodoArbolDesa*arbol,STdesafio desafio);
void mostrarNodoArbolDesafio(nodoArbolDesa*arbol);
void listarArbolDesafio(nodoArbolDesa*arbol);
void guardarDesafioEnArchivo (nodoArbolDesa* nuevo);
STdesafio cargarDesafio (nodoMonstruo* lista);
void buscarMonstruoPorId(int idMonstruo, STmonstruo *aux_monstruo);
nodoArbolDesa* pasarDesafiosArbolToArbol(nodoArbolDesa* arbol);
void altaREGdesafio();
void muestraArchiDesafios();


#endif // DESAFIOS_H_INCLUDED
