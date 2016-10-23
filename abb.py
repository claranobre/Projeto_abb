# 'no' refere-se ao nó-pai, neste caso
def arvore_binaria_buscar(no, valor):
    if no is None:
        # valor não encontrado
        return None
    else:
        if valor == no.valor:
            # valor encontrado
            return no.valor
        elif valor < no.valor:
            # busca na subárvore esquerda
            return arvore_binaria_buscar(no.filho_esquerdo, valor)
        elif valor > no.valor:
            # busca na subárvore direita
            return arvore_binaria_buscar(no.filho_direito, valor)

def arvore_binaria_inserir(no, chave, valor):
    if no is None:
        return TreeNode(None, chave, valor, None)
    if chave == no.chave:
        return TreeNode(no.filho_esquerdo, chave, valor, no.filho_direito)
    if chave < no.chave:
        return TreeNode(arvore_binaria_inserir(no.filho_esquerdo, chave, valor), no.chave, no.valor, no.filho_direito)
    else:
        return TreeNode(no.filho_esquerdo, no.chave, no.valor, arvore_binaria_inserir(no.filho_direito, chave, valor))

def exclusao_em_arvore_binaria(nó_arvore, valor):
    if nó_arvore is None: return None # Valor não encontrado
    esquerda, nó_valor, direita = nó_arvore.esquerda, nó_arvore.valor, nó_arvore.direita
    if nó_valor == valor:
        if esquerda is None:
            return direita
        elif direita is None:
            return esquerda
        else:
            valor_max, novo_esquerda = busca_max(esquerda)
            return TreeNode(novo_esquerda, valor_max, direita)
    elif valor < nó_valor:
        return TreeNode(exclusao_em_arvore_binaria(esquerda, valor), nó_valor, direita)
    else:
        return TreeNode(esquerda, nó_valor, exclusao_em_arvore_binaria(direita, valor))

def busca_max(nó_arvore):
    esquerda, nó_valor, direita = nó_arvore.esquerda, nó_arvore.valor, nó_arvore.direita
    if direita is None: return (nó_valor, esquerda)
    else:
        (valor_max, novo_direita) = busca_max(direita)
        return (valor_max, (esquerda, nó_valor, novo_direita))

def criar_arvore_binaria(valor):
    arvore = None
    for v in valor:
        arvore = arvore_binaria_de_insercao(arvore, v)
    return arvore

def arvore_binaria_transversal(nó_arvore):
    if nó_arvore is None: return []
    else:
        esquerda, valor, direita = nó_arvore
        return (arvore_binaria_transversal(esquerda) + [valor] + arvore_binaria_transversal(direita))