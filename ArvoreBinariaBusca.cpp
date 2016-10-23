clas ArvoreBinariaBusca{

	/*
	* Método construtor da classe
	*/
	ArvoreBinariaBusca();

	/*
	* Método destrutor da classe
	*/
	~ArvoreBinariaBusca();

	//Função de inserção de um elemento
	void Insert(int x);
	//Função de remoção de um elemento
	void Delete(int x);
	//Função de busca de um elemento
	void Search(int x);

	//Árvore binária criada e iniciada como vazia
	ArvoreBinariaBusca::ArvoreBinariaBusca(){
		root = NULL;
	}

	//Árvore binária é destruída liberando espaço ocupado pelos seus elementos
	ArvoreBinariaBusca::~ArvoreBinariaBusca(){
		Clear();
	}

	//Função retorna 'true' se a árvore binária estiver vazia e 'false' caso contrário
	bool ArvoreBinariaBusca::Empty(){
		return(bool == NULL);
	}

	//Função retorna 'true' se a árvore binária estiver cheia e 'false' caso contrário
	bool ArvoreBinariaBusca::Full(){
		return false;
	}
}