package TP_2_Semestre;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/***********************************************************************************
 * TRABALHO PRATICO FINAL * ALUNOS: CHRYSTIAN
 * HENRIQUE FONSECA DE SOUZA; SAMARA HELLEN FERREIRA CHAVES * TURMA: 3110101 *
 ***********************************************************************************/

public class ClassePrincipal {
    public static void main(String[] args) throws Exception {
        // Fazendo com que o programa abra e leia um arquivo txt

        // Declaracao de variaveis
        ArvoreAVL A1 = new ArvoreAVL();
        String CaminhoArquivo = "D:\\LabAEDII\\src\\TP_2_Semestre\\ArquivoTP";
        BufferedReader Leitor = null;
        
      //Bloco usado para definir um conjunto de instrucoes onde podem ocorrer excecoes, combinado com metodos "catch" e "finally", para tratar as exececoes encontradas
        try { 
            // Leitura do arquivo
            Leitor = new BufferedReader(new FileReader(CaminhoArquivo));
            String linha;
            while ((linha = Leitor.readLine()) != null) { // Condicao para que o programa leia todo o arquivo txt
                linha = linha.replaceAll("[^a-zA-Z0-9]", ""); // Despreza os sinais de pontuacao e espacos
                linha = linha.toLowerCase(); // Converte as letras maiusculas em minusculas
                Palavra P = new Palavra(linha);
                A1.Inserir(P); // Insere as palavras na arvore
            }
            A1.Imprimir(); // Mostra a arvore
            
            // Insere todas as palavras da arvore na lista dupla, na ordem das que mais aparecem para as que menos aparecem
            // Criando uma lista dupla vazia
            ListaDupla lista = new ListaDupla();

            // Adiciona as palavras da arvore na lista dupla
            A1.AddLista(lista);

            // Mostra a lista dupla
            lista.mostrarLista();
            
            
            
            
        } catch (FileNotFoundException e) { // Tratamento para a excecao caso o arquivo nao seja encontrado no sistema
            e.printStackTrace(); // Metodo usado para depurar e rastrear o fluxo de execucao do programa quando uma excecao eh lancada
        } catch (IOException e) { // Tratamento para a exececao caso haja algum erro durante a leitura ou gravacao de dados de entrada ou saida
            e.printStackTrace();
            
        //Fechando o Arquivo    
        } finally { // Bloco que sera executado independe de ser encontrada alguma excecao
            if (Leitor != null) {
                try {
                    Leitor.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
