#ifndef DESAFIOS_H_INCLUDED
#define DESAFIOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DESAFIOS "desafios.dat"

typedef struct{
    int idMonstruo;
	char nombreMonstruo[30];
	int vidaBaseMonstruo;
    int ataqueBaseMonstruo;
    int puntosMonstruo;
}STmonstruo;

typedef struct{
    int idDesafio;
    char tipoDesafio;
    char descripcionDesafio[100];
    int dificultadDesafio; 	/// 1-2-3 (Facil-Medio-Dificil )
    STmonstruo monstruo;
    char preguntaProxDesafio[100];
    int desafioEliminado;
}STdesafio;

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
nodoArbolDesa* pasarDesafiosArbolToArbol(nodoArbolDesa* arbol);


#endif // DESAFIOS_H_INCLUDED
