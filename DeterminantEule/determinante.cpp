#include <stdio.h>
#include <stdlib.h>

struct noh{
	int aresta;
	int grau;
};

int main(){


	/*--- Variaveis ---*/
	int i,j,limit,cursor,countPar,countImpar;
	
	/*--- Iniciando matriz ---*/
	printf("Informe quantos nohs deseja: ");
	scanf ("%d", &limit);
	system("cls");	
	struct noh grafo[limit][limit];

	/*--- Definindo valores da matriz ---*/
	for(i=0;i<limit;i++)
		for(j=0;j<limit;j++){
			grafo[i][j].aresta = -1;  
			grafo[i][j].grau   =  0;	
		}
	
	/*--- Populando matriz---*/
	for(i=0;i<limit;i++)
		for(j=0;j<limit;j++)
		{
	    	//Tratamento dos nós com ligação própria
	   	  	if(j == i){
	   	  		grafo[ i ][ j ].aresta=0;
			}
				
			else{
				//Tratamento para não háver arestas duplicados
				if(grafo[j][i].aresta != -1){
					grafo[ i ][ j ].aresta= grafo[j][i].aresta;
					if(grafo[ i ][ j ].aresta > 0){

					}
					
				}
				//Inserindo o valor das arestas
				else{
					printf ("[%d] [%d] = ", i, j);
					scanf ("%d", &grafo[ i ][ j ].aresta);
					if(grafo[ i ][ j ].aresta > 0){
						grafo[i][i].grau += 1;
						grafo[j][j].grau += 1;
					}
				}
			}   	    
		}
		
	system("cls"); 		

	/*--- Visualizar ---*/
	for(i=0;i<limit;i++)
		for(j=0;j<limit;j++){
			if(i==j){
				printf("O noh [%d] tem grau: %d\n", i, grafo[i][j].grau);
			}
	}
	
	for(i=0;i<limit;i++)
		for(j=0;j<limit;j++){
			if (grafo[i][j].aresta == grafo[j][i].aresta && i < j){
				printf ("[%d]-[%d] = %d\n", i, j,grafo[ i ][ j ].aresta);
			}
			else{
						
			}
							
				
		}
	countPar =0;
	countImpar = 0;
	for(i=0;i<limit;i++){
		if(grafo[i][i].grau%2 == 0 ){
		  	countPar++;
		}
		else if(grafo[i][i].grau%2 != 0) {
			countImpar ++;
		}
	}
	
	
	/*--- Respostas sobre tipo de grafo ---*/
	if(countPar == limit){
		printf("\nGrafo Euleriano Completo");	
	}
	else{
		if(countImpar <= 2){
			printf("\nGrafo Semi Euleriano");
		}
		else{
			if(countImpar >= 3){
				printf("\nGrafo não Euleriano");
			}
		}
	}
		

}
