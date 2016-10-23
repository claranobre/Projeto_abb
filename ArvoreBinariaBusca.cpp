#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

class ArvoreBinariaBusca{

	ArvoreBinariaBusca *esquerda, *direita;
	ArvoreBinariaBusca raiz;
	int contador;
	char chave;

	/*
	* Método construtor da classe
	*/
	ArvoreBinariaBusca();

	/*
	* Método destrutor da classe
	*/
	~ArvoreBinariaBusca();

	//Função de inserção de um elemento
	void Insercao(int x);
	//Função de remoção de um elemento
	void Remocao(int x);
	//Função de busca de um elemento
	void Busca(int x);

	//Árvore binária criada e iniciada como vazia
	ArvoreBinariaBusca::ArvoreBinariaBusca(){
		raiz = NULL;
		contador = 0;
	}

	//Árvore binária é destruída liberando espaço ocupado pelos seus elementos
	ArvoreBinariaBusca::~ArvoreBinariaBusca(ArvoreBinariaBusca *&raiz){
		if(raiz != NULL){
			~ArvoreBinariaBusca(raiz->esquerda);
			~ArvoreBinariaBusca(raiz->direita);
			free(raiz);
			raiz = NULL;
		}
		//Clear();
	}

	//Função retorna 'true' se a árvore binária estiver vazia e 'false' caso contrário
	bool ArvoreBinariaBusca::Vazia(){
		return(bool == NULL);
	}

	//Função retorna 'true' se a árvore binária estiver cheia e 'false' caso contrário
	bool ArvoreBinariaBusca::Cheia(){
		return false;
	}

	//Função para verificar o tamanho da árvore de busca
	int ArvoreBinariaBusca::Tamanho(){
		return contador;
	}

	//Função de inserção de um novo nó no lugar de uma subárvore vazia
	ArvoreBinariaBusca::Insercao(char key, int x, ArvoreBinariaBusca *&raiz){
		if(raiz == NULL){
			if((raiz=(ArvoreBinariaBusca *) malloc(sizeof(ArvoreBinariaBusca))) == NULL){
				return false;
			}else{
				raiz -> x = chave;
				raiz -> esquerda = raiz -> direita = NULL;
				contador++;
				return true;
			}
		else{
			if(chave < raiz -> x){
				return ArvoreBinariaBusca::Insercao(chave,raiz->direita);
			}else{
				return false; //chave já existe na árvore
			}
		}
	}

	//Função para percorrer a árvore binária de busca em Ordem
	ArvoreBinariaBusca::PercorrerEmOrdem(ArvoreBinariaBusca *&raiz){
		if(raiz != NULL){
			ArvoreBinariaBusca::PercorrerEmOrdem(raiz -> esquerda);
			printf("%s\n", raiz->x);
			ArvoreBinariaBusca::PercorrerEmOrdem(raiz -> direita);
		}
	}
}

int main(){
	char chave, opcao;

	ArvoreBinariaBusca();

	do{
		printf("Informe a chave: \n");
		cin(chave);

		ArvoreBinariaBusca::Insercao(chave, raiz);

		cout::"Mais dados?"::endl;
		cin(opcao);
	}while(toupper(opcao) != 'N');
}