package TP_2_Semestre;

/***********************************************************************************
 * TRABALHO PRÃTICO FINAL * ALUNOS: CHRYSTIAN
 * HENRIQUE FONSECA DE SOUZA; SAMARA HELLEN FERREIRA CHAVES * TURMA: 3110101 *
 ***********************************************************************************/

public class No {
    // Declarando as variaveis
    Palavra p;
    No esq;
    No dir;
    int altura;

    // Metodo construtor padrao
    public No(Palavra p) {
        this.p = p;
        this.esq = null;
        this.dir = null;
        this.altura = 1;
    }
}

