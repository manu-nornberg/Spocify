#include <stdio.h>
#include <stdlib.h>
#include "spocify.h"
#include <string.h>

void criarPlaylist (playlist *pl){
	pl->inicio = NULL;
	pl->fim = NULL;
	pl->n = 0;
}

int incluiInicio (playlist *pl, dado d){
	Nodo *pNodo;
	Nodo *pAux;
	pAux = pl->inicio;
	pNodo = (Nodo *) malloc (sizeof (Nodo));
	if (pNodo == NULL){
		return SEM_ESPACO;
	}else{
		while (pAux != NULL){
	    if (strcmp (pAux->info.musica, d.musica) == 0){
	    	return MUSICA_ENCONTRADA;
	    }
	    pAux = pAux->prox;
    }
		pNodo->info = d;
		pNodo->ant = NULL;
		pNodo->prox = pl->inicio;
		if (pl->n == 0){
			pl->fim = pNodo;
		}else{
			pl->inicio->ant = pNodo;
		}
	pl->inicio = pNodo;
	pl->n++;
	d.cod++;	
	return SUCESSO;
	}
}


void exibePlaylist(playlist pl){
     Nodo *pAux;
     pAux = pl.inicio;
     printf("Exibindo a Playlist\n");
     while (pAux != NULL) {
           printf("%c %s - %c %s \n", 16, pAux->info.autor, 14, pAux->info.musica);
           pAux = pAux->prox;
     }
}

void qntMusicas (playlist pl){
	printf ("Quantidade de musicas: %d\n", pl.n);
}

int situPlaylist (playlist *pl){
	Nodo *pNodo;
	if (pNodo==NULL){
		return SEM_ESPACO;
	}else if (pl->n==0){
		return PLAYLIST_VAZIA;
	}else 
		return PLAYLIST;
}

int incluiFim (playlist *pl, dado d){
	Nodo *pNodo;
	Nodo *pAux;
	pAux = pl->inicio;
	pNodo = (Nodo *) malloc (sizeof (Nodo));
		if (pNodo == NULL){
			return SEM_ESPACO;
		}else{
			while (pAux != NULL){
	    		if (strcmp (pAux->info.musica, d.musica) == 0){
	    		return MUSICA_ENCONTRADA;
	    		}
		    pAux = pAux->prox;
	    	}
			pNodo->info = d;
			pNodo->prox = NULL;
			}if (pl->inicio==0){
				pNodo->ant = NULL;
				pl->inicio = pNodo; 			
			}else{
				pNodo->ant = pl->fim;
				pl->fim->prox = pNodo;
				}
		pl->fim = pNodo;
		pl->n++;
		d.cod++;		
		return SUCESSO;
}

int excluiInicio (playlist *pl, dado *d){
	Nodo *pTemp;
	if (pl->inicio == NULL && pl->fim == NULL && pl->n == 0){
		return PLAYLIST_VAZIA;
	}else if(pl->n == 1){
		*d = pl->inicio->info;
		pTemp = pl->inicio;
		free(pTemp);
		pl->inicio = NULL;
		pl->fim = NULL;
		pl->n = 0;
		}else{
		*d = pl->inicio->info;
		pTemp = pl->inicio;
		pl->inicio = pl->inicio->prox;
		pl->inicio->ant = NULL;
		free (pTemp);
		pl->n--;
		d->cod--;
	}
	return SUCESSO;
}

int excluiFim (playlist *pl, dado *d){
	Nodo *pTemp;
	if (pl->inicio == NULL && pl->fim == NULL && pl->n == 0){
		return PLAYLIST_VAZIA;
	}else if(pl->n == 1){
		*d = pl->fim->info;
		pTemp = pl->fim;
		free(pTemp);
		pl->inicio = NULL;
		pl->fim = NULL;
		pl->n = 0;
		}else{
		*d = pl->inicio->info;
		pTemp = pl->fim;
		pl->fim = pl->fim->ant;
		pl->fim->prox = NULL;
		free (pTemp);
		pl->n--;
		d->cod--;	
	}
	return SUCESSO;
}

int consultaPlaylist (playlist *pl, char ref[50]){
    Nodo *pAux;
    int achou = 0;
    pAux = pl->inicio;
    while (pAux != NULL){
        if (strcmp (pAux->info.autor, ref) == 0){
            printf("%c %s - %c %s \n", 16, pAux->info.autor, 14, pAux->info.musica);
              achou++;
        }

        pAux = pAux->prox;
        }
        if(achou >0)
            return SUCESSO;
        else
            return MUSICA_INEXISTENTE;
}

int consultaPlaylist1 (playlist *pl, char ref[50]){
    Nodo *pAux;
    int achou = 0;
    pAux = pl->inicio;
    while (pAux != NULL){
        if (strcmp (pAux->info.musica, ref) == 0){
            printf("%c %s - %c %s \n", 16, pAux->info.autor, 14, pAux->info.musica);
              achou++;
        }

        pAux = pAux->prox;
        }
        if(achou >0)
            return SUCESSO;
        else
            return MUSICA_INEXISTENTE;
}

int incluiDepois (playlist *pl, dado d, char ref[50]){
	Nodo *pAux;
	Nodo *pNodo;
	Nodo *pAux2;
	
	pAux = pl->inicio;
	
	while (pAux != NULL){
		if(strcmp (pAux->info.musica, d.musica) == 0)
			return MUSICA_ENCONTRADA;
		pAux = pAux->prox;
		}
				
	pAux = pl->inicio;
	
	
	while (pAux != NULL){
		if (strcmp (pAux->info.musica, ref) == 0){
			pNodo = (Nodo *) malloc (sizeof (Nodo));
			if (pNodo == NULL)
				return SEM_ESPACO;		 
			if (pl->n==1){
				pNodo->info = d;
				pNodo->prox = NULL;
				pNodo->ant = pAux;
				pl->fim->prox = pNodo;
				pl->fim = pNodo;
				pl->n++;
				return SUCESSO;
			}
			if (pAux->prox == NULL){
				pNodo->info = d;
				pNodo->prox = NULL;
				pNodo->ant = pAux;
				pl->fim = pNodo;
				pl->n++;
				return SUCESSO;
			}
			pNodo->info = d;
			pAux2 = pAux->prox;
			pNodo->ant = pAux;
			pNodo->prox = pAux->prox;
			pAux->prox = pNodo;
			pAux2->ant = pNodo;
			return SUCESSO;			
	}
	pAux = pAux->prox;	
}
	return MUSICA_INEXISTENTE;
}



int excluiNodo (playlist *pl, char ref[50], dado *d){
	Nodo *pAux;
	Nodo *pTemp;
	Nodo *pProx;
	Nodo *pAntes;
	pAux = pl->inicio;
	if (pl->inicio == NULL){
		return PLAYLIST_VAZIA;
	}while (pAux != NULL){
		if (strcmp (pAux->info.musica, ref) == 0){
			*d = pAux->info;
				if (pl->n==1){
					pTemp = pl->fim;
					free(pTemp);
					pl->inicio = NULL;
					pl->fim = NULL;
					pl->n = 0;
				}else if (pAux->ant==NULL){
					*d = pl->inicio->info;
					pTemp = pl->inicio;
					pl->inicio = pl->inicio->prox;
					pl->inicio->ant = NULL;
					free (pTemp);
					pl->n--;
				}else if (pAux->prox == NULL){
					*d = pl->inicio->info;
					pTemp = pl->fim;
					pl->fim = pl->fim->ant;
					pl->fim->prox = NULL;
					free (pTemp);
					pl->n--;	
				}else{
					*d = pl->inicio->info;
					pProx = pAux->prox;
					pAntes = pAux->ant;
					pAntes->prox = pProx;
					pProx->ant = pAntes;
					free(pAux);
					pl->n--; 
				}
		return SUCESSO;
		}
		pAux = pAux->prox;		
		}
	return MUSICA_INEXISTENTE;
}

