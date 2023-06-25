package TP_2_Semestre;

/***********************************************************************************
 * TRABALHO PRATICO FINAL * ALUNOS: CHRYSTIAN
 * HENRIQUE FONSECA DE SOUZA; SAMARA HELLEN FERREIRA CHAVES * TURMA: 3110101 *
 ***********************************************************************************/

public class ListaDupla {
    // Declarando as variaveis
    No primeiro;
    No ultimo;

    // Metodo construtor vazio
    public ListaDupla() {
        this.primeiro = null;
        this.ultimo = null;
    }

    // Metodos de insercao e remocao na lista
    // inserir no inicio da lista
    public void inserirInicio(Palavra palavra) {
        // Criacao de um novo "no" para insercao da palavra no inicio da lista
        No tmp = new No(palavra);
        // Condicao caso a lista esteja vazia
        if (primeiro == null) {
        	primeiro = tmp;
        	ultimo = tmp;
        } else { // Caso esteja preenchida, faz o devido encadeamento para o tmp virar o primeiro termo
            tmp.dir = primeiro;
            primeiro.esq = tmp;
            primeiro = tmp;
        }
    }
    
    void inserirAntes(No noExistente, Palavra palavra) {
    	//Criando um novo no que contem a palavra
        No novoNo = new No(palavra);

        if (noExistente == null) {
            // Caso o no existente seja nulo(a lista esta vazia), o novo no sera inserido como o primeiro elemento da lista
            novoNo.dir = primeiro;//Ira colocar o novo no como primeiro da lista
            if (primeiro != null) {//Se o primeiro for diferente de null
                primeiro.esq = novoNo;//Ira colocar o no anterior do primeiro da lista como novo no 
            }
            primeiro = novoNo;//Atualiza o primeiro da lista como novo no
            if (ultimo == null) {//se o ultimo for nulo(a lista esta vazia)
                ultimo = novoNo;//o ultimo sera o novo no
            }
        } else {
            // Caso contrario, insere o novo no antes do no existente
            novoNo.dir = noExistente;//colocando o apontador a direita para o no ja existente
            novoNo.esq = noExistente.esq;//atribui o anterior do no existente ao anterior do novo no
            if (noExistente.esq != null) {//se o anterior do no existente for diferente de nulo
                noExistente.esq.dir = novoNo;//atualiza o proximo do no anterior para o novo no
            } else {
                primeiro = novoNo;//se o no anterior do no existente for nulo, o novo no sera o primeiro da lista
            }
            noExistente.esq = novoNo;//Atualiza o no anterior do no existente para o novo no
        }
    }


    // Inserir no fim da lista
    public void inserirFim(Palavra palavra) {
        // Criacao de um novo "no" para insercao da palavra no fim da lista
        No tmp = new No(palavra);
        // Condicao caso a lista esteja vazia
        if (ultimo == null) {
        	primeiro = tmp;
        	ultimo = tmp;
        } else { // Caso esteja preenchida, faz o devido encadeamento para o tmp virar o ultimo termo
            tmp.esq = ultimo;
            ultimo.dir = tmp;
            ultimo = tmp;
        }
    }

    // Remover no inicio da lista
    public void removerInicio() {
        // Condicao caso a lista esteja vazia
        if (primeiro == null) {
            System.out.println("A lista esta vazia. Nao e possivel remover.");
        } else if (primeiro == ultimo) { // Condicao caso haja apenas um "no" na lista
        	primeiro = null;
        	ultimo = null;
        } else { // Remove o "no" no inicio e atualiza as referencias
        	primeiro = primeiro.dir;
        	primeiro.esq = null;
        }
    }

    // Remover no fim da lista
    public void removerFim() {
        // Condicao caso a lista esteja vazia
        if (ultimo == null) {
            System.out.println("A lista esta vazia. Nao e possivel remover.");
        } else if (primeiro == ultimo) { // Condicao caso haja apenas um "no" na lista
        	primeiro = null;
        	ultimo = null;
        } else { // Remove o "no" no fim e atualiza as referencias
        	ultimo = ultimo.esq;
        	ultimo.dir = null;
        }
    }
    
    //Metodo para mostrar a lista
    public void mostrarLista() {
    	System.out.println("Lista Dupla: ");
    	System.out.println("");//Espaco
        No atual = primeiro;//Iniciando do primeiro
        while (atual != null) {//Enquanto o atual nao for nulo
            System.out.println(atual.p + ": " + atual.p.contador + " Vezes");//Ira mostrar a lista
            atual = atual.dir;//E atualizar a posicao para mostrar o proximo
        }
        System.out.println(""); //Espaco
    }
}
