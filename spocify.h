#ifndef Spocify_H
#define Spocify_H
#include "string.h"

#define SUCESSO 0
#define PLAYLIST_VAZIA 1
#define SEM_ESPACO 2
#define MUSICA_INEXISTENTE 3
#define PLAYLIST 4
#define MUSICA_ENCONTRADA 5

typedef struct { 
	int cod;
	char musica[50];
	char autor[50];	
} dado;

typedef struct nodo Nodo; 

struct nodo {    
    dado info;
    Nodo *prox;
    Nodo *ant;
};

typedef struct {
    Nodo *inicio;
    Nodo *fim;
    int n;
} playlist;

/*void criarPlaylist (playlist *pl);
int incluiInicio (playlist *pl, dado d);
void exibePlaylist(playlist pl);
void qntMusicas (playlist pl);
int situPlaylist (playlist *pl);
int incluiFim (playlist *pl, dado d);
int excluiInicio (playlist *pl, dado *d);
int excluiFim (playlist *pl, dado *d);
int consultaPlaylist (playlist *pl, char ref);
int consultaPlaylist1 (playlist *pl, char ref);
int incluiDepois (playlist *pl, dado d, char ref[50]);*/
#endif
