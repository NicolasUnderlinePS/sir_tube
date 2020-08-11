#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Nicolas Pereira Silva 830463
struct noh{
	int aresta;
	int grau;
};


int main(){
	setlocale(LC_ALL, "Portuguese");
	int i, j;
	int limit;
	int cursor =1;
	int countPar=0;
	int countImpar=0;
	
	//menu	
	while(cursor != 0){
		printf("_________________  \n");	
		printf("|Menu principal  | \n");
		printf("|1 - Executar    | \n");
		printf("|2 - Ajuda       | \n");
		printf("|0 - Sair        | \n");
		printf("|________________|   \n");		
		printf("Opção: ");
		scanf ("%d", &cursor);
		system("cls");
		if(cursor == 1){
			
			int countPar=0;
			int countImpar=0;
			
			printf("\nExecutando\n");
			printf("Escolha a quantidade de nós\nOpção:");
			scanf ("%d", &limit);
	
			struct noh grafo[limit][limit];
		
			//Igualar todos a -1//
			for ( i=0; i<limit; i++ )
			    for ( j=0; j<limit; j++ )
			    {
					 grafo[ i ][ j ].aresta= -1;
					 grafo[ i ][ j ].grau  = 0;
			      
			    }
			    
		//Inserção das arestas//
		printf ("\n---Informe o valor das arestas---\n");
		for ( i=0; i<limit; i++ )
		    for ( j=-0; j<limit; j++ )
		    {
		    	//Tratamento dos nós com ligação própria
		   	  	if(j == i){
		   	  		grafo[ i ][ j ].aresta=0;
				}
				
				else{
					//Tratamento para não háver arestas duplicados
					if(grafo[j][i].aresta != -1 ){
						grafo[ i ][ j ].aresta= grafo[j][i].aresta;
	
						
					}
					//Inserindo o valor das arestas
					else{
						printf ("\nNó |%d| tem ligação com o nó |%d| ? = ", i, j);
						scanf ("%d", &grafo[ i ][ j ].aresta);
						if(grafo[ i ][ j ].aresta > 0){
							grafo[i][i].grau += 1;
							grafo[j][j].grau += 1;
						}
					}
				}   	    
		    }
		    
		system("cls");
		printf("\n---Gráu dos nós---\n");
		//Exibição de graú dos nós
		for ( i=0; i<limit; i++ )
		    for ( j=0; j<limit; j++ )
		    {
		   		if(i == j ){
		   			printf ("\nO Nó [%d] tem Graú:%d \n",i, grafo[i][j].grau);	
				}
	
		    }
		    
		printf("\n---Ligação entre os nós---\n");
		//Exibição das arestas
		for ( i=0; i<limit; i++ )
		    for ( j=0; j<limit; j++ )
		    {				
				printf ("\n[%d]-[%d] = %d\n", i, j,grafo[ i ][ j ].aresta);
		    }
		    
		for (i=0; i<limit; i++){
			if(grafo[i][i].grau%2 == 0 ){
		      	countPar++;
			}else if(grafo[i][i].grau%2 != 0) {
			  	countImpar++;
			}
		}
	
		//Respostas
		
		//Tratamento para um grafo-euleriano
		if(countPar == limit){
			printf("\nO Grafo é Euleriano perfeito\n\n");
		}
		else{
			//Tratamento para um grafo-euleriano imperfeito
			if(countImpar <= 2){
				printf("\nO Grafo é Euleriano imperfeito\n\n");
			}else{
				//Tratamento para um grafo não euleriano
				if(countImpar >= 3){
					printf("\nO Grafo não é euleriano\n\n");	
				}
			}

		
		
	}


		}
		else{
			if(cursor == 2){
				printf("Obrigado pela preferência\n");
				printf("Ao selecionar a opção de Execução, você precisara informar o número total de nós que seu grafo possui.\n");
				printf("Logo após isso, será solicitado que informe o valor das arestas entre cada nó.\n");
				printf("Não se preocupe em indicar os nós, o sistema apresenta eles por conta própria.\n");
				printf("Caso o nó apresentado não possua uma aresta com outro nó, informe o valor 0 (zero) \n");
				printf("Ao final da inserção o programa ira exibir o grau de cada nó, as ligações\n");
				printf("e qual o tipo de grafo:\n");
				printf("Euleriano perfeito\n");
				printf("Euleriano imperfeito\n");
				printf("Grafo não euleriano \n\n");
				printf("Tenha um bom uso!\n\n");
			}
			else{
				if(cursor == 0){
					printf("\Saindo\n");
				}
			}
		}
		system("pause");
		system("cls");
	}	




	


	

}

