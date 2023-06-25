package TP_2_Semestre;

/***********************************************************************************
 * TRABALHO PRATICO FINAL * ALUNOS: CHRYSTIAN
 * HENRIQUE FONSECA DE SOUZA; SAMARA HELLEN FERREIRA CHAVES * TURMA: 3110101 *
 ***********************************************************************************/

public class Palavra {
    // Declarando as variaveis
    String nome;
    Integer contador;

    // Metodo construtor padrao
    public Palavra(String nome) {
        this.nome = nome;
        this.contador = 1;
    }
    //Metodo get
	public String getPalavra() {
		return nome;
	}
	//Metodo para fornecer uma representacao em string, de um objeto do tipo palavra
	@Override
	public String toString () {
		return nome;
	}
	public int compareTo(Palavra palavra) {
		// TODO Auto-generated method stub
		return 0;
	}
}

