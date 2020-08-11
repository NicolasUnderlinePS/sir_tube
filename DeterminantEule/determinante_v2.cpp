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
		printf("Op��o: ");
		scanf ("%d", &cursor);
		system("cls");
		if(cursor == 1){
			
			int countPar=0;
			int countImpar=0;
			
			printf("\nExecutando\n");
			printf("Escolha a quantidade de n�s\nOp��o:");
			scanf ("%d", &limit);
	
			struct noh grafo[limit][limit];
		
			//Igualar todos a -1//
			for ( i=0; i<limit; i++ )
			    for ( j=0; j<limit; j++ )
			    {
					 grafo[ i ][ j ].aresta= -1;
					 grafo[ i ][ j ].grau  = 0;
			      
			    }
			    
		//Inser��o das arestas//
		printf ("\n---Informe o valor das arestas---\n");
		for ( i=0; i<limit; i++ )
		    for ( j=-0; j<limit; j++ )
		    {
		    	//Tratamento dos n�s com liga��o pr�pria
		   	  	if(j == i){
		   	  		grafo[ i ][ j ].aresta=0;
				}
				
				else{
					//Tratamento para n�o h�ver arestas duplicados
					if(grafo[j][i].aresta != -1 ){
						grafo[ i ][ j ].aresta= grafo[j][i].aresta;
	
						
					}
					//Inserindo o valor das arestas
					else{
						printf ("\nN� |%d| tem liga��o com o n� |%d| ? = ", i, j);
						scanf ("%d", &grafo[ i ][ j ].aresta);
						if(grafo[ i ][ j ].aresta > 0){
							grafo[i][i].grau += 1;
							grafo[j][j].grau += 1;
						}
					}
				}   	    
		    }
		    
		system("cls");
		printf("\n---Gr�u dos n�s---\n");
		//Exibi��o de gra� dos n�s
		for ( i=0; i<limit; i++ )
		    for ( j=0; j<limit; j++ )
		    {
		   		if(i == j ){
		   			printf ("\nO N� [%d] tem Gra�:%d \n",i, grafo[i][j].grau);	
				}
	
		    }
		    
		printf("\n---Liga��o entre os n�s---\n");
		//Exibi��o das arestas
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
			printf("\nO Grafo � Euleriano perfeito\n\n");
		}
		else{
			//Tratamento para um grafo-euleriano imperfeito
			if(countImpar <= 2){
				printf("\nO Grafo � Euleriano imperfeito\n\n");
			}else{
				//Tratamento para um grafo n�o euleriano
				if(countImpar >= 3){
					printf("\nO Grafo n�o � euleriano\n\n");	
				}
			}

		
		
	}


		}
		else{
			if(cursor == 2){
				printf("Obrigado pela prefer�ncia\n");
				printf("Ao selecionar a op��o de Execu��o, voc� precisara informar o n�mero total de n�s que seu grafo possui.\n");
				printf("Logo ap�s isso, ser� solicitado que informe o valor das arestas entre cada n�.\n");
				printf("N�o se preocupe em indicar os n�s, o sistema apresenta eles por conta pr�pria.\n");
				printf("Caso o n� apresentado n�o possua uma aresta com outro n�, informe o valor 0 (zero) \n");
				printf("Ao final da inser��o o programa ira exibir o grau de cada n�, as liga��es\n");
				printf("e qual o tipo de grafo:\n");
				printf("Euleriano perfeito\n");
				printf("Euleriano imperfeito\n");
				printf("Grafo n�o euleriano \n\n");
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

