# Projeto Árvore Binária de Busca(ABB)
Autor(a): Ana Clara [GitHub](github.com/claranobre)

**Uma árvore binária de busca é uma árvore binária que armazena itens (chave-info.) nos seus nós, de modo que, para nós ´´´u´´´, ´´´v´´´, e ´´´w´´´ tais que ´´´u´´´ está na sub-árvore esquerda de ´´´v´´´ e ´´´w´´´ está na sub-árvore direita de ´´´v´´´, tem-se:

´´´python
chave(u) ≤ chave(v) ≤ chave(w)
´´´
# Análise Assintótica
* Busca
A complexidade da busca depende da altura da árvore, portanto o ideal é uma árvore com a menor altura possível.
Melhor caso: é dado quando a chave é encontrada na raíz ´´´(O log n)´´´.
Pior caso: chave encontrada ou não encontrada no maior caminho entre a raíz e uma folha ´´´(O(n))´´´.

* Inserção
A complexidade é dominada pela complexidade da busca.
Melhor caso: ´´´O(log n)´´´
Pior caso: ´´´O(n)´´´
* Remoção
A complexidade é dominada pela complexidade da busca.

# Executando o projeto
* É necessário possuir o compilador GCC instalado na máquina:
- No Windows seguir os passos do link abaixo
´´´python
https://goo.gl/Dkzr9v
´´´ 
- No Linux (Debian)
´´´python
apt-get install gcc
´´´

Após a instalação abrir o diretório do projeto e no Terminal Linux:

´´´python 
gcc ArvoreBinariaBusca.cpp -o ArvoreBinariaBusca
´´´