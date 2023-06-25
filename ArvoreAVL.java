package TP_2_Semestre;

/***********************************************************************************
 * TRABALHO PRATICO FINAL * ALUNOS: CHRYSTIAN
 * HENRIQUE FONSECA DE SOUZA; SAMARA HELLEN FERREIRA CHAVES * TURMA: 3110101 *
 ***********************************************************************************/

/*Como eh calculado o fator de balanceamento?
altura sub arvore a direita - altura sub arvore a esquerda
*******************************************************************
Fator do no = 2
Se o fator do filho a direita for 1 ou 0: rotacao simples a esquerda
Se o fator do filho a direita for -1: rotacao dupla direita esquerda
********************************************************************
Fator do no=-2
Se o fator do filho a direita for -1 ou 0: rotacao simples a direita
Se o fator do filho a direita for 1: rotacao dupla esquerda direita*/

public class ArvoreAVL {
	//Declaracao de variavel raiz
	No Raiz;

	//Metodo construtor vazio
	public ArvoreAVL() {
		Raiz = null;
	}
	
	// Metodos de Rotacao da Arvore AVL:
	
	// Metodo para obter a altura de um "no"
	int altura(No n) {
		if (n == null) {
			return -1;
		}
		return n.altura;
	}
	//Rotacao simples para a esquerda
    No RotSimpEsq(No a) {
        No b = a.dir;
        a.dir = b.esq;
        b.esq = a;
        a.altura = Math.max(altura(a.esq), altura(a.dir)) + 1;
        b.altura = Math.max(altura(b.dir), a.altura) + 1;
        return b;
    }
    //Rotacao simples para a direita
    No RotSimpDir(No a) {
        No b = a.esq;
        a.esq = b.dir;
        b.dir = a;
        a.altura = Math.max(altura(a.esq), altura(a.dir)) + 1;
        b.altura = Math.max(altura(b.esq), a.altura) + 1;
        return b;
    }
    //Rotacao dupla esquerda-direita
    No RotDupEsqDir(No a) {
        a.esq = RotSimpEsq(a.esq);
        return RotSimpDir(a);
    }
    //Rotacao dupla direta-esquerda
    No RotDupDirEsq(No a) {
        a.dir = RotSimpDir(a.dir);
        return RotSimpEsq(a);
    }
		
	//Metodo Inserir, com balanceamento por rotacao
	void Inserir (Palavra x)throws Exception{
		Raiz = Inserir(x, Raiz);
	}
	No Inserir(Palavra x, No i) throws Exception {
        if (i == null) {//Se o no for nulo, ira criar um novo i com a palavra x
            i = new No(x);
        } 
        //Se nao for nulo, ira entrar na condicao seguinte:
        else if (x.getPalavra().compareTo(i.p.getPalavra()) < 0) {//Se x for menor de forma lexicografica a palavra no no atual
            i.esq = Inserir(x, i.esq);//ira inserir na sub arvore a esquerda e verifica o balanceamento
            if (altura(i.esq) - altura(i.dir) == 2) {//Caso esteja desbalanceado ira calcular o fator de balanceamento
                if (x.getPalavra().compareTo(i.esq.p.getPalavra()) < 0) {
                    i = RotSimpDir(i);//realiza uma rotacao simples a direita
                } 
                else {
                    i = RotDupEsqDir(i);//Realiza uma rotacao dupla esquerda direita
                }
            }
        } 
        else if (x.getPalavra().compareTo(i.p.getPalavra()) > 0) {//Se x for maior de forma lexicografica a palavra no no atual
            i.dir = Inserir(x, i.dir);//ira inserir na sub arvore a direita
            if (altura(i.dir) - altura(i.esq) == 2) {//Caso esteja desbalanceado ira calcular o fator de balanceamento
                if (x.getPalavra().compareTo(i.dir.p.getPalavra()) > 0) {
                    i = RotSimpEsq(i);//realiza uma rotacao simples a esquerda
                } 
                else {
                    i = RotDupDirEsq(i);//realiza uma rotacao dupla direita esquerda
                }
            }
        } 
        else { // Caso a palavra ja esteja na arvore, incrementa o contador
        	if(Verificar(x.getPalavra()) == true)
           i.p.contador++;
        }
        //Atualizando a altura do no
        i.altura = Math.max(altura(i.esq), altura(i.dir)) + 1;
        return i;
    }
	
	// Metodo para verificar se uma palavra ja esta inserida na arvore AVL
	boolean Verificar(String palavra) {
	    return Verificar(palavra, Raiz);
	}
	boolean Verificar(String palavra, No i) {
	    if (i == null) {
	        return false;
	    }
	    int comparacao = palavra.compareTo(i.p.getPalavra());
	    /*
	     * Interpretacao da comparacao: 
	    Se comparacao for igual a 0, significa que as duas palavras sao iguais;
	    Se comparacao for menor que 0, significa que a palavra atual (palavra) eh lexicograficamente anterior Ã  palavra do "no" (i.p.getPalavra;
	    Se comparacao for maior que 0, significa que a palavra atual (palavra) eh lexicograficamente posterior Ã  palavra do "no" (i.p.getPalavra
	    */
	    
	    //Implementacao das acoes de acordo com o resultado da comparacao
	    if (comparacao == 0) {
	    // A palavra foi encontrada na sub-arvore analisada
	        return true;
	    } 
	    else if (comparacao < 0) {
	        // Verificar se a palavra estah na sub-arvore da esquerda
	        return Verificar(palavra, i.esq);
	    } 
	    else {
	        // Verifica de a palavra estah na sub-arvore da direita
	        return Verificar(palavra, i.dir);
	    }
	}
	
	//Metodo Caminhar Central
	void Caminhar_Central(No i) {
		if (i != null) {
			Caminhar_Central(i.esq);
			System.out.println(i.p + ": " + i.p.contador + " " );
			Caminhar_Central(i.dir);
		}
	}
	
	//Metodo Remover, com balanceamento por rotacao
	void Remover (Palavra x) throws Exception{
		Raiz = Remover(x, Raiz);
	}
	No Remover(Palavra x, No i) throws Exception {
        if (i == null) {//Se a arvore estiver vazia, ira dar erro
            throw new Exception("ERRO!");
        } 
        //Caso nao seja vazio, ira comparar 
        else if (x.getPalavra().compareTo(i.p.getPalavra()) < 0) {//Se x for menor de forma lexicografica a palavra no no atual
            i.esq = Remover(x, i.esq);//Remove o no na sub arvore a esquerda
            if (altura(i.dir) - altura(i.esq) == 2) {//Caso esteja desbalanceado ira calcular o fator de balanceamento
                if (altura(i.dir.esq) > altura(i.dir.dir)) {
                    i = RotDupDirEsq(i);//Realiza uma rotacao dupla direita esquerda
                } 
                else {
                    i = RotSimpEsq(i);//Realiza uma rotacao simples pra esquerda
                }
            }
        } 
        else if (x.getPalavra().compareTo(i.p.getPalavra()) > 0) {//Se x for maior de forma lexicografica a palavra no no atual
            i.dir = Remover(x, i.dir);//Remove o no na sub arvore a direita
            if (altura(i.esq) - altura(i.dir) == 2) {//Caso esteja desbalanceado ira calcular o fator de balanceamento
                if (altura(i.esq.dir) > altura(i.esq.esq)) {
                    i = RotDupEsqDir(i);//Realiza uma rotacao dupla esquerda direita
                } 
                else {
                    i = RotSimpDir(i);//Realiza uma rotacao simples a direita
                }
            }
        } 
        //Se o no x for encontrado
        else if (i.dir == null) {
            i = i.esq;//Ira remover o no atual se ele nao tiver filhos a direita
        } 
        else if (i.esq == null) {
            i = i.dir;//Ira remover o no atual se ele nao tiver filhos a esquerda
        } 
        else {
        	//Substitui a palavra no no atual pela maior palavra da sub arvore a esquerda
            i.esq = MaiorEsq(i, i.esq);
            if (altura(i.dir) - altura(i.esq) == 2) {
                if (altura(i.dir.esq) > altura(i.dir.dir)) {
                    i = RotDupDirEsq(i);//Realiza uma rotacao dupla direita esquerda
                } 
                else {
                    i = RotSimpEsq(i);//Realiza uma rotacao simples a esquerda
                }
            }
        }
        //Atualiza a altura do no
        if (i != null) {
            i.altura = Math.max(altura(i.esq), altura(i.dir)) + 1;
        }
        return i;
	}
	No MaiorEsq(No i, No j) {
		//Caso nao haja mais filhos na direita
		if (j.dir == null) { 
			i.p = j.p; j = j.esq;
		} 
		//Caso haja mais filhos na direita, verifica novamente qual eh o maior
		else { 
			j.dir = MaiorEsq(i, j.dir);
		} 
		return j;
	}
	
	void AddLista(ListaDupla lista) {
	    AddLista(Raiz, lista);
	}
	void AddLista(No no, ListaDupla lista) {
	    if (no != null) {
	        AddLista(no.dir, lista); // Percorre o nó da direita primeiro

	        // Encontra a posição correta para inserir a palavra na lista ordenada
	        No atualOrdenado = lista.primeiro;
	        while (atualOrdenado != null && atualOrdenado.p.contador >= no.p.contador) {
	            atualOrdenado = atualOrdenado.dir;
	        }

	        // Insere a palavra na posição correta da lista ordenada
	        if (atualOrdenado == null) {
	            lista.inserirFim(no.p); // Insere no fim se a lista estiver vazia ou se o contador for menor que todos os elementos
	        } else {
	            lista.inserirAntes(atualOrdenado, no.p); // Insere antes do nó encontrado
	        }
	        AddLista(no.esq, lista); // Percorre o nó da esquerda em seguida
	    }
	}

	

	
	//Metodo Imprimir
	void Imprimir () {
		System.out.println("Arvore AVL: ");
		System.out.println(""); //Espaco
		Caminhar_Central(Raiz);
		System.out.println(""); //Espaco
		System.out.println(""); //Espaco
	}
}
