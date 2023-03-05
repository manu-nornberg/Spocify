#include <stdio.h>
#include <stdlib.h>
#include "spocify.h"
#include <string.h>

int main () {
	
	playlist pl;
	int cod, op, x;
	char musica[50], autor[50], r[50];
	dado d;
	
	criarPlaylist(&pl);
	
	do {
		printf ("0. Fim\n");
		printf ("1. Inclui no inicio\n");
		printf ("2. Exibe playlist\n");
		printf ("3. Quantidade de musicas\n");
		printf ("4. Situacao da playlist\n");
		printf ("5. Inclui no fim\n");
		printf ("6. Exclui no inicio\n");
		printf ("7. Exclui no fim\n");
		printf ("8. Consulta por artista\n");
		printf ("9. Consulta por musica\n");
		printf ("10. Inclui depois\n");
		printf ("11.Exclui musica\n");
		printf("Operacao: ");    
      	scanf("%d", &op);
      	scanf("%c");
      	printf ("--------------------\n");
      	
      		switch (op){
      			case 1: 
						printf ("Digite o nome da musica:\n ");
      					fgets(d.musica, 50, stdin);
					    for(x=0;x<50;x++){ 
					        if(d.musica[x]==32){  //ASCII do enter
					            d.musica[x]=10;  // ASCII do espaço
					        break;
							}
					    }
      					printf ("Digite o nome do autor:\n ");
      					fgets(d.autor,50,stdin);
					    for(x=0;x<50;x++){
					        if(d.autor[x]==32){
					            d.autor[x]=10;
					        break;
							}
					    }
	      					if (incluiInicio(&pl, d)==SUCESSO){
	      						printf ("Sucesso!\n");
							}else if (incluiInicio(&pl, d) == MUSICA_ENCONTRADA){
								printf ("Musica ja adicionada \n");
							}else 
								printf ("Erro! Falta espaco na playlist\n\n");				
						printf ("--------------------\n");	
	      				break; 
	      				
	      		case 2: 
						exibePlaylist(pl);
						printf ("\n--------------------\n");
						break;
						
				case 3: 
						qntMusicas(pl);
						printf ("--------------------\n");
						break;
						
				case 4: 
						if (situPlaylist(&pl)==SEM_ESPACO){
							printf ("Playlist cheia!\n");
						}else if (situPlaylist(&pl)==PLAYLIST_VAZIA){
							printf ("Playlist vazia!\n");
						}else 
							qntMusicas(pl);		
						printf ("--------------------\n");
						break;
						
				case 5: 
						printf ("Digite o nome da musica:\n ");
      					fgets(d.musica,50,stdin);
					    for(x=0;x<50;x++){
					        if(d.musica[x]==32){
					            d.musica[x]=10;
					        break;
							}
					    }
      					printf ("Digite o nome do autor:\n ");
      					fgets(d.autor,50,stdin);
					    for(x=0;x<50;x++){
					        if(d.autor[x]==32){
					            d.autor[x]=10;
					        break;
							}
					    }
	      					if (incluiFim(&pl, d)==SUCESSO){
	      						printf ("Sucesso!\n");
							}else if (incluiFim(&pl, d) == MUSICA_ENCONTRADA){
								printf ("Musica ja adicionada \n");
							}else 
								printf ("Erro! Falta espaco na playlist\n\n");		
						printf ("--------------------\n");	
	      				break;				
						
				case 6: 
						if (excluiInicio(&pl, &d)==PLAYLIST_VAZIA){
							printf ("Playlist vazia, nao e possivel excluir!\n");
						}else 
							printf ("Sucesso! Musica excluida:\n %c %s - %c %s \n", 16, d.autor, 14, d.musica);			
						printf ("--------------------\n");	
	      				break;		
	      				
	      		case 7: 
						if (excluiFim(&pl, &d)==PLAYLIST_VAZIA){
							printf ("Playlist vazia, nao e possivel excluir!\n");
						}else 
							printf ("Sucesso! Musica excluida:\n %c %s - %c %s \n", 16, d.autor, 14, d.musica);	
						printf ("--------------------\n");	
	      				break;
						  
				case 8: 
						printf ("Digite o nome do artista no qual deseja procurar: ");
						fgets (r, 50 , stdin);
					    for(x=0; x<50; x++){
					        if(r[x] == 32){
					            r[x] = 10;
					        break;
							}
					    }
      					if (consultaPlaylist(&pl, r)==MUSICA_INEXISTENTE){
							printf("Artista inexistente!\n");						  
						}else 
						  	printf("SUCESSO!\n");	
						printf ("--------------------\n");	
	      				break;
						  
				case 9: 
						printf ("Digite o nome da musica na qual deseja procurar: ");
      					fgets (r, 50 , stdin);
					    for(x=0; x<50; x++){
					        if(r[x] == 32){
					            r[x] = 10;
					        break;
							}
					    }
      					if (consultaPlaylist1(&pl, r)==MUSICA_INEXISTENTE){
							printf("Musica inexistente!\n");						  
						}else 
						  	printf("SUCESSO!\n");	
						printf ("--------------------\n");	
	      				break;
						  
				case 10: 
						printf ("Digite o nome da musica:\n ");
      					fgets(d.musica,50,stdin);
					    for(x=0;x<50;x++){
					        if(d.musica[x]==32){
					            d.musica[x]=10;
					        break;
							}
					    }
      					printf ("Digite o nome do autor:\n ");
      					fgets(d.autor,50,stdin);
					    for(x=0;x<50;x++){
					        if(d.autor[x]==32){
					            d.autor[x]=10;
					        break;
							}
					    }
						printf ("Digite o nome da musica de referencia: ");
      					fgets (r, 50 , stdin);
					    for(x=0; x<50; x++){
					        if(r[x] == 32){
					            r[x] = 10;
					        break;
							}
					    }    
						if (incluiDepois(&pl, d) == SUCESSO){
	      						printf ("Sucesso!\n");
						}else if (incluiDepois(&pl, d) == MUSICA_ENCONTRADA){
								printf ("Musica ja adicionada \n");
						}else if (incluiDepois(&pl, d) == SEM_ESPACO){
								printf ("Erro! Falta espaco na playlist\n");
						}else { 
							printf("Musica inexistente!\n");
						}
						printf ("--------------------\n");	
	      				break;
						  
				case 11:
						printf ("Digite a musica que deseja excluir: ");
      					fgets (r, 50 , stdin);
					    for(x=0; x<50; x++){
					        if(r[x] == 32){
					            r[x] = 10;
					        break;
							}
					    }
						if (excluiNodo(&pl, r, &d)==SUCESSO){
							printf ("Sucesso! Musica excluida:\n %c %s - %c %s \n", 16, d.autor, 14, d.musica);
						}else if (excluiNodo(&pl, r, &d)==PLAYLIST_VAZIA){
							printf ("Playlist vazia!\n");
						}else 
							printf("Musica inexistente!\n");	
						printf ("--------------------\n");	
	      				break;		  	
						  	  		  		  		
}
}while(op!=0);
}
