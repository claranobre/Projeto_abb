#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <iostream> 

#define TAM 10

using namespace std;

//typedef struct  node *ArvoreBinariaBusca;

struct node {
	char valores[TAM];
	struct node *direita;
	struct node *esquerda;
};

	struct node *raiz; //Ponteiro da raiz
	struct node *alocar; //Ponteiro para fazer operação de alocação

/*
* Buscar
*/
struct node *buscar(char *valores){
	struct node *ponteiro;
	ponteiro = raiz;

	while(ponteiro){
		if(strcmp(valores, ponteiro->valores) == 0){ //Comparação
			return ponteiro;
		}
		if(strcmp(valores, ponteiro->valores) > 0){
			ponteiro = ponteiro -> direita;
		}else{
			ponteiro = ponteiro -> esquerda;
		}
		return NULL;
	}
}

/*
* Inserção
*/
void inserir(char *valores){
	alocar = (struct node *) malloc(sizeof(struct node)); //Alocação de memória

	if(!alocar){
		cout<<"Erro. Falta memória.";
	}
	strcpy(alocar->valores,valores);

	if(!raiz){ //Se não existir elementos na árvore inserir valor na raiz
		raiz = alocar;
	}else{
		//buscar
		struct node *ponteiro;
		struct node *ponteiroAnterior;

		ponteiro = raiz;
		ponteiroAnterior = NULL;

		while(ponteiro){ //Busca para verificar onde será inserido o nó
			ponteiroAnterior = ponteiro;

			if(strcmp(valores, ponteiro->valores) == 0){
				cout<<"Valor já existe.\n";
				return;
			}
			if(strcmp(valores, ponteiro->valores) > 0){
				ponteiro = ponteiro -> direita;
			}else{
				ponteiro = ponteiro -> esquerda;
			}
		}
	if(strcmp(valores, ponteiroAnterior->valores) > 0){
		ponteiroAnterior->direita = alocar;   //Atribui o endereço de alocação ao ponteiro da direita do nó anterior
	}else{
		ponteiroAnterior -> esquerda = alocar; //Atribui o endereço de alocação ao ponteiro da esquerda do nó anterior
	}	
	}
}

/*
* Em Ordem
*/
void emOrdem(struct node *ponteiro) {
    if (ponteiro) {
    	emOrdem(ponteiro->esquerda);
        cout<< ponteiro->valores << "\n";
        emOrdem(ponteiro->direita);
    }
}

/*
* Main()
*/
int main(){
	char valores[TAM];

	cout << "Insira valores: \n";
	for(int i = 0; i < TAM; i++){
	cin >> valores;
	inserir(valores);
	}
	emOrdem(raiz);
	cout <<"Buscar valor: \n";
	cin >> valores;
	cout << buscar(valores);
	//cout<<"Imprimir Árvore Binária de Busca: \n");

	return 0;
}