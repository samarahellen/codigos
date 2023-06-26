/***********************************************************************************
 *                              TRABALHO PRÁTICO FINAL * ALUNOS: CHRYSTIAN
 *HENRIQUE FONSECA DE SOUZA; SAMARA HELLEN FERREIRA CHAVES    * TURMA: 5156100 *
 ***********************************************************************************/
#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define Max 100
// maximo de departamentos
using namespace std;


/***********************************************************************
                              CONFIGURAÇÕES DE FALA
************************************************************************/

/***********************************************************************
                              DEFININDO AS CLASSES
************************************************************************/

// Classe de Tipo de equipamento
class Tipo_Equipamento {
  // Definindo os atributos
private:
  int CodTE;
  char DescricaoTE[Max];

public:
  void setCodTE(int *IdTE);
  void setDescricaoTE(char DescTE[Max]);
  int getCodTE();
  char *getDescricaoTE();

  // Inicializando os valores da CRUD, utilizando método construtor padrão
  Tipo_Equipamento() {
    CodTE = 0;
    strcpy(DescricaoTE, "Novo Tipo");
  };

  // Procedimento para mostrar tipos de equipamento cadastrados
  void mostra_tipdeeq() {
    if (CodTE > -1) {
      cout << "\t" << CodTE << "\t" << DescricaoTE << endl;
    }
  }
};

// Procedimento Setter de código do tipo de equipamento
void Tipo_Equipamento::setCodTE(int *IdTE) {
  if (*IdTE >= 1)
    CodTE = *IdTE;
}
// Função Getter do código do tipo de equipamento
int Tipo_Equipamento::getCodTE() { return CodTE; }

// Procedimento Setter de descrição do tipo de equipamento
void Tipo_Equipamento::setDescricaoTE(char DescTE[Max]) {
  strcpy(DescricaoTE, DescTE);
}
// Função Getter de descrição do tipo de equipamento
char *Tipo_Equipamento::getDescricaoTE() { return DescricaoTE; }

//___________________________________________________________________________

// Fazendo o CRUD de departamento
class Departamento {
private:
  int CodDep;
  char NomeDep[100];
  char DescricaoDep[100];
  int LocalizacaoDep;

public:
  void setCodDep(int *IdDep);
  void setNomeDep(char NDep[Max]);
  void setDescricaoDep(char DescDep[Max]);
  void setLocalDep(int *LocDep);
  int getCodDep();
  char *getNomeDep();
  char *getDescricaoDep();
  int getLocalDep();

  // Inicializando os valores da CRUD, utilizando método construtor padrão
  Departamento() {
    CodDep = 0;
    strcpy(NomeDep, "Novo Departamento");
    strcpy(DescricaoDep, "Nova Descricao");
    LocalizacaoDep = 0;
  };

  // Procedimento para mostrar tipos de equipamento cadastrados
  void mostra_departamento() {
    if (CodDep > -1) {
      cout << CodDep << "\t\t" << NomeDep << "\t\t " << DescricaoDep << "\t\t\t" << LocalizacaoDep << endl;
    }
  }
};

// Procedimento Setter de código do departamento
void Departamento::setCodDep(int *IdDep) {
  if (*IdDep >= -1)
    CodDep = *IdDep;
}
// Função Getter do código do departamento
int Departamento::getCodDep() { return CodDep; }

// Procedimento Setter de nome do departamento
void Departamento::setNomeDep(char NDep[Max]) { strcpy(NomeDep, NDep); }
// Função Getter de nome do departamento
char *Departamento::getNomeDep() { return NomeDep; }

// Procedimento Setter de descrição do departamento
void Departamento::setDescricaoDep(char DescDep[Max]) {
  strcpy(DescricaoDep, DescDep);
}
// Função Getter de descrição do departamento
char *Departamento::getDescricaoDep() { return DescricaoDep; }

// Procedimento Setter de localização do departamento
void Departamento::setLocalDep(int *LocDep) {
  if (*LocDep >= 1)
    LocalizacaoDep = *LocDep;
}
// Função Getter de localização do departamento
int Departamento::getLocalDep() { return LocalizacaoDep; }

//_____________________________________________________________________________

// Fazendo a classe de Equipamentos
class Equipamento {
private:
  int CodEquip;
  char NomeEquip[100];
  float PrecoEquip;
  Departamento *dpto = new Departamento;
  Tipo_Equipamento *tipo = new Tipo_Equipamento;

public:
  void setCodEQ(int *IdEQ);
  int getCodEQ();
  void setNomeEQ(char NomeEQ[Max]);
  char *getNomeEQ();
  void setPrecoEQ(float PrecoEQ);
  float getPrecoEQ();
  Tipo_Equipamento getTE ();
  Departamento getDP ();
  // Inicializando os valores da CRUD, utilizando método construtor padrão
  Equipamento() {
    CodEquip = 0;
    strcpy(NomeEquip, "Novo Equipamento");
    PrecoEquip = 0.0;
    dpto = NULL;
    tipo = NULL;
  };
  Equipamento (int CodEquip, char NomeEquip[Max], float PrecoEquip, Departamento dpto, Tipo_Equipamento tipo){
    this->CodEquip = CodEquip;
    strcpy(this->NomeEquip, NomeEquip);
    this->PrecoEquip = PrecoEquip;
    this->dpto = &dpto;
    this->tipo = &tipo;
  }
// procedimento para associar o tipo de equipamento com o equipamento
  void setTipo(Tipo_Equipamento *TipoE) {
    tipo = TipoE;
  }

  // procedimento para associar o departamento com o equipamento
  void setDpto(Departamento *Dep) {
    // Atribuicao do nome
    dpto = Dep;
  }
  // Procedimento para mostrar os equipamentos
  void mostra_EQ() {
    if (CodEquip > -1) {
      cout << CodEquip << "\t\t" << NomeEquip << "\t\t " << PrecoEquip << "\t\t" 
      << tipo->getDescricaoTE() << "\t\t" << dpto->getNomeDep() << "\n";
    }
  }
};

// Fazendo o setter do código de equipamento
void Equipamento::setCodEQ(int *IdEQ) {
  if (*IdEQ >= -1)
    CodEquip = *IdEQ;
}
// Fazendo o getter do código de equipamento
int Equipamento::getCodEQ() { return CodEquip; }

// Fazendo o setter do nome do equipamento
void Equipamento::setNomeEQ(char NomeEQ[Max]) { strcpy(NomeEquip, NomeEQ); }

// Fazendo o getter do nome do equipamento
char *Equipamento::getNomeEQ() { return NomeEquip; }

// Fazendo o setter do preço do equipamento
void Equipamento::setPrecoEQ(float PrecoEQ) {
  if (PrecoEQ >= 1.0)
    PrecoEquip = PrecoEQ;
}
// Fazendo o getter do preço do equipamento
float Equipamento::getPrecoEQ() { return PrecoEquip; }

//Fazendo o getter do Tipo de Equipamento
Tipo_Equipamento Equipamento::getTE() { return *tipo; }

//Fazendo o getter do Departamento
Departamento Equipamento::getDP() { return *dpto; }

/************************************************************************************
                        VARIÁVEIS, PROCEDIMENTOS E FUNÇÕES GLOBAIS
************************************************************************************/
Tipo_Equipamento TE[Max];
int conTE = 0;
Departamento DP[Max];
int conDep = 0;
Equipamento EQ[Max];
int contEQ = 0;

// Função de tipo inteiro que compara duas strings e retorna 0 se elas forem
// iguais ou 1 se elas forem diferentes
int Verifica_Strings(char *StrA, char *StrB) {
  int Result;
  Result = strcmp(StrA, StrB);
  return Result;
}

/*************************************************************************************
                                  PROCEDIMENTOS E FUNÇÕES
*************************************************************************************/
// Procedimento que altera o valor de uma string
void alterar_string(char nome1[], char nome2[]) {
  // Verifica se o tamanho das strings sao iguais
  if (strlen(nome1) == strlen(nome2)) {
    strcpy(nome1, nome2);

    // Verifica se a primeira string eh maior que a segunda
  } else if (strlen(nome1) > strlen(nome2)) {
    strcpy(nome1, nome2);
    nome1[strlen(nome2)] = '\0';

    // Caso a segunda string ser maior que a primeira
  } else {
    strncpy(nome1, nome2, strlen(nome2));
  }
}
// Função do tipo Bool que ve se possui Equipamento ou nao
bool tem_cadastro_EQ(int contEQ) {
  if (contEQ > 0)
    return true;
  else
    return false;
}
// Funcao do tipo bool que verifica se existe cadastro de tipo de equipamento
bool tem_cadastro_TE(int conTE) {
  if (conTE > 0)
    return true;
  else
    return false;
}
// Função do tipo bool para verificar se existe cadastro de departamento ou não
bool tem_cadastro_DEP(int conDep) {
  if (conDep > 0)
    return true;
  else
    return false;
}
//Função para buscar o código de um tipo de equipamento previamente cadastrado. Função recebe o vetor de Tipo de equipamento cadastrados e o numero referente ao codigo que será pesquisado e retorna o endereço do tipo de equipamento desejado
Tipo_Equipamento *Busca_TE (Tipo_Equipamento TE[Max], int num){
  for (int i = 0; i < conTE; i++) {
    if (num == TE[i].getCodTE()) { //Código encontrado
    // Agregamento das classes
      return &TE[i];
    }
  }
  return NULL;
}
//Função para buscar a descrição de um tipo de equipamento previamente cadastrado. Função recebe o vetor de Tipo de equipamento cadastrados e a string referente à descrição que será pesquisada e retorna um valor booleano true se a string for igual a alguma descricao de tipo de equipamento ou false se não for
bool Busca_Desc_TE (Tipo_Equipamento TE[Max], char desc[Max]){
  for (int i = 0; i < conTE && *TE[i].getDescricaoTE() != '\0'; i++) {
    if (strcmp(desc, TE[i].getDescricaoTE()) == 0) { //Descricao encontrada
      return true;
    }
    else
      return false;
  }
  return false;
}
bool Busca_Nome_Dep (Departamento DP[Max], char NDEP[Max]){
  for (int i = 0; i < conDep && *DP[i].getNomeDep() != '\0'; i++) {
    if (strcmp(NDEP, DP[i].getNomeDep())) { //Nome encontrado
      return true;
    }
    else
      return false;
  }
  return false;
}
//Função para buscar o código de um departamento previamente cadastrado. Função recebe o vetor de departamentos cadastrados e o numero referente ao codigo que será pesquisado e retorna o endereço do departamento desejado
Departamento *Busca_Dep (Departamento DP[Max], int num2){
  for (int i = 0; i < conDep; i++) {
    if (num2 == DP[i].getCodDep()) { //Código encontrado
    // Agregamento das classes
      return &DP[i];
    }
  }
  return NULL;
}
//_______________________________________________________________________________
// Menu do CRUD de Equipamento
void menuEQ() {
  int op, N, i, Id_EQ, Id_TE, x, num, j, E = -1, num2, LimArq = 0, y;
  char Nome_EQ[100], N_Dep[100], N_TE[100], N_Arq[100], DescTE[Max], NDepartamento[100];
  float preco_EQ;
  bool r, DTE[conTE], NDP[conDep];
  Departamento *Dep;
  Tipo_Equipamento *TipoE;
  do {
    cout << "\nEQUIPAMENTOS\n";
    cout << "[0] - Voltar ao Menu Anterior\n";
    cout << "[1] - Cadastrar Equipamentos\n";
    cout << "[2] - Mostrar Equipamentos\n";
    cout << "[3] - Alterar Cadastro\n";
    cout << "[4] - Excluir Cadastro\n";
    cout << "[5] - Lista dos Equipamentos\n";
    cout << "[6] - Salvar Dados em Arquivo\n";
    cout << "[7] - Lista Arquivos\n";
    cout << "Opcao: ";
    cin >> op;
    switch (op) {
    case 0: // Volta ao menu anterior
      cout << "\nVoltando ao menu anterior\n\n...\n\n";
      break;
    case 1: // Cadastro de equipamento
      cout << "\nQuantos equipamentos deseja cadastrar? ";
      cin >> N;
      for (i = 0; i < N && i < Max; i++) {
        cout << "\nEquipamento" << i + 1;
        Id_EQ = i + 1;
        cout << "\nCodigo de identificacao " << Id_EQ << endl;
        cout << "Nome: ";
        cin >> Nome_EQ;
        fflush(stdin);
        cout << "Preco: ";
        cin >> preco_EQ;
        EQ[i].setCodEQ(&Id_EQ);
        EQ[i].setNomeEQ(Nome_EQ);
        EQ[i].setPrecoEQ(preco_EQ);
        //Relação de classes
        //Escolha do Tipo de Equipamento
        cout << "\nDigite o codigo do tipo de equipamento escolhido: ";
        cin >> num;
        TipoE = Busca_TE(TE, num);
        if (TipoE != NULL)
          EQ[i].setTipo(TipoE);
        //Escolha do Departamento
        cout << "\nDigite o codigo do departamento escolhido: ";
        cin >> num2;
        Dep = Busca_Dep(DP, num2);
        if (Dep != NULL)
          EQ[i].setDpto(Dep);
        contEQ++;
      }
      cout << "\nEquipamento(s) cadastrado(s) com sucesso\n";
      break;
    case 2:                        // Mostrando os Equipamentos
      r = tem_cadastro_EQ(contEQ); // Verifica se possui cadastro de equipamento
      if (r == 0)
        cout << "\nNao existe cadastro de equipamento\n" << endl;
      else {
        cout << "\nCodigo"
             << "\t"
             << "Nome"
             << "\t"
             << "Preco"
             << "\t"
             << "Tipo"
             << "\t"
             << "Departamento"
             << "\n"
             << endl;
        for (i = 0; i < contEQ; i++) {
          EQ[i].mostra_EQ();
        }
      }
      break;
    case 3:                        // Altera cadastro Equipamentos
      r = tem_cadastro_EQ(contEQ); // Verifica se possui cadastro de equipamento
      if (r == 0)
        cout << "\nNao existe cadastro de equipamento\n" << endl;
      else {
        cout << "\nDigite o codigo do equipamento que deseja alterar: ";
        cin >> x;
        // Verificação se há algum cadastro com o codigo desejado
        for (int i = 0; i < contEQ; i++) {
          if (EQ[i].getCodEQ() == x) { // Se houver, realiza a mudança
            cout << "Digite o novo nome: ";
            cin >> Nome_EQ;
            fflush(stdin);
            cout << "Digite o novo preco: ";
            cin >> preco_EQ;
            // Passando o novo nome para a variável global
            EQ[x - 1].setNomeEQ(Nome_EQ);
            EQ[x - 1].setPrecoEQ(preco_EQ);
            cout << "\nDigite o novo codigo do tipo de equipamento: ";
            cin >> num;
            TipoE = Busca_TE(TE, num);
            if (TipoE != NULL)
            EQ[i].setTipo(TipoE);
            //Escolha do Departamento
            cout << "\nDigite o codigo do novo departamento: ";
            cin >> num2;
            Dep = Busca_Dep(DP, num2);
            if (Dep != NULL)
            EQ[i].setDpto(Dep);
            cout << "\nAlteracao realizada com sucesso!\n";
          }
        }
      }
      break;
    case 4:                        // Exclui Equipamento
      r = tem_cadastro_EQ(contEQ); // Verifica se possui cadastro de equipamento
      if (r == 0)
        cout << "\nNao existe cadastro de equipamento\n" << endl;
      else {
        // Exibe os tipos de equipamentos disponiveis para que algum possa
        // ser excluido
        cout << "\nEquipamentos Disponíveis para Exclusão:\n" << endl;
        for (i = 0; i < contEQ; i++) {
          EQ[i].mostra_EQ();
        }
        cout << "\nDigite o codigo do equipamento que deseja excluir: " << endl;
        cin >> num;
        // Acha o equipamento e o exclui
        for (i = 0; i <= contEQ; i++) {
          if (num == EQ[i].getCodEQ()) { // verifica se o id digitado é igual o id do equipamento
            EQ[i].setCodEQ(&E); // substitui o codigo atual do equipamento por -1
          }
        }
        cout << "\nExclusao Realizada com Sucesso!\n";
      }
      break;
    case 5: // Lista os Equipamentos
      cout << "\nDigite a descricao do tipo do equipamento que deseja listar: ";
      cin >> DescTE;
      cout << "\nAgora digite o nome do departamento: ";
      cin >> NDepartamento;
      fflush(stdin);
      cout << "\nListagem:\n" << endl;
      cout << "\nCodigo"
           << "\t"
           << "Nome"
           << "\t"
           << "Preco"
           << "\t"
           << "Tipo"
           << "\t"
           << "Departamento"
           << "\n"
           << endl;
      // Verifica quais equipamentos atendem às especificações
      for (i = 0; i < conTE && i < contEQ && i < conDep; i++) {
        DTE[i] = Busca_Desc_TE(TE, DescTE);
        NDP[i] = Busca_Nome_Dep(DP, NDepartamento);
        if (DTE[i] == true){ //Se o resultado da busca pelo Tipo de equipamento for verdadeiro
          if (NDP[i] == true){ //Se o resultado da busca pelo departamento for verdadeiro
            EQ[i].mostra_EQ();
          }
        }
      }
      break;
    case 6: // Salva dados em Arquivo
      // Abrindo o arquivo
      FILE *ArqEQ;
      ArqEQ = fopen("Equipamento.txt", "w");
      // Verificando se o arquivo existe
      if (ArqEQ == NULL) {
        printf("\nArquivo inexistente\n");
      }
      // Preenchendo o arquivo
      fwrite(&contEQ, sizeof(int), 1, ArqEQ);
      // Gravar informacoes
      fwrite(EQ, sizeof(Equipamento), contEQ + 1, ArqEQ);
      printf("\nArquivo preenchido com sucesso!\n");
      // Fechando o arquivo
      fclose(ArqEQ);
      break;
    case 7: //Lista arquivos
      FILE *Arquivo;
      //Entrada do nome do arquivo
      cout << "\nInsira o nome do arquivo: ";
      cin >> N_Arq;
      fflush (stdin);
      //Abre o arquivo
      Arquivo = fopen (N_Arq, "rb");
      // Verificando se o arquivo existe
      if (Arquivo == NULL) {
        printf("\nArquivo inexistente\n");
      }
      else {
        //Determina o tamanho do arquivo
        fread (&LimArq, sizeof(int), 1, Arquivo);
            LimArq++;
        //Le o arquivo de equipamento
        fread (EQ, sizeof(Equipamento), LimArq, Arquivo);
        //Exibe o conteudo lido dentro do arquivo
        for (int i = 0; i < LimArq; i++){
          EQ[i].mostra_EQ();
        }
      //Fecha o arquivo
      fclose (Arquivo);
      }
      break;
    default:
      cout << "\nDigite uma opcao valida!\n";
      break;
    }
  } while (op != 0);
}

// ________________________________________________________________________________
// Menu de Departamento
void menuDep() {
  int op, N, i, IDep, NPredio, x, num, j, R, E = -1, LimArq = 0;
  char NDep[100], DescDep[100], y[100], N_Arq[100];
  bool r;
  do {
    cout << "\nDEPARTAMENTO\n";
    cout << "[0] - Voltar ao Menu Anterior\n";
    cout << "[1] - Cadastrar Departamento\n";
    cout << "[2] - Mostrar Departamentos\n";
    cout << "[3] - Alterar Cadastro\n";
    cout << "[4] - Excluir Cadastro\n";
    cout << "[5] - Listar Departamentos\n";
    cout << "[6] - Salvar em Arquivo\n";
    cout << "[7] - Menu Equipamentos\n";
    cout << "[8] - Lista Arquivo\n";
    cout << "Opcao: ";
    cin >> op;
    switch (op) {
    case 0: // Volta ao menu anterior
      cout << "\nVoltando ao menu anterior\n\n...\n\n";
      break;
    case 1: // Cadastro de departamento
      cout << "\nQuantos departamentos deseja cadastrar? ";
      cin >> N;
      for (i = 0; i < Max && i < N; i++) {
        cout << "\nDepartamento " << i + 1;
        IDep = i + 1;
        cout << "\nCodigo de Identificacao: " << IDep << endl;
        cout << "Nome: ";
        cin >> NDep;
        fflush(stdin);
        cout << "Descricao: ";
        cin >> DescDep;
        fflush(stdin);
        cout << "Numero do Predio Onde o Departamento Fica Alocado: ";
        cin >> NPredio;
        // Passando os valores para o CRUD
        DP[i].setCodDep(&IDep);
        DP[i].setNomeDep(NDep);
        DP[i].setDescricaoDep(DescDep);
        DP[i].setLocalDep(&NPredio);
        conDep++; // Contador de cadastros
      }
      cout << "\n Cadastro Realizado com Sucesso\n";
      break;
      r = tem_cadastro_DEP(
          conDep); // Verifica se possui cadastro de departamento
      if (r == 0)
        cout << "\nNao existe cadastro de departamento\n" << endl;
      else {
      case 2: // Mostrar Departamentos
        cout << "\nDepartamentos:\n" << endl;
        cout << "Codigo"
             << "\t"
             << "Nome"
             << "\t\t"
             << "Descricao"
             << "\t\t"
             << "Predio"
             << "\n";
        for (i = 0; i < conDep; i++) {
          DP[i].mostra_departamento(); // chamando o procedimento
        }
      }
      break;
    case 3: // Alterar Cadastro de Departamento
      r = tem_cadastro_DEP(conDep); // Verifica se possui cadastro de departamento
      if (r == 0)
        cout << "\nNao existe cadastro de departamento\n" << endl;
      else {
        cout << "\nDigite o codigo do departamento que deseja alterar: ";
        cin >> x;
        // Verificação se há algum cadastro com o codigo desejado
        for (int i = 0; i < Max; i++) {
          if (DP[i].getCodDep() == x) { // Se houver, realiza a mudança
            cout << "Novo Nome: ";
            cin >> NDep;
            fflush(stdin);
            cout << "Nova Descricao: ";
            cin >> DescDep;
            fflush(stdin);
            cout << "Novo Numero do Predio de Alocacao do Departamento: ";
            cin >> NPredio;
            cout << "\nAlteracao Realizada com Sucesso!\n";
            // Passando os novos dados para a variável global
            DP[x - 1].setNomeDep(NDep);
            DP[x - 1].setDescricaoDep(DescDep);
            DP[x - 1].setLocalDep(&NPredio);
          }
        }
      }
      break;
    case 4: // Excluir Cadastro de Departamento
      r = tem_cadastro_DEP(
          conDep); // Verifica se possui cadastro de departamento
      if (r == 0)
        cout << "\nNao existe cadastro de departamento\n" << endl;
      else {
        // Exibe os departamentos disponiveis para que algum possa ser
        // excluido
        cout << "\nDepartamentos disponiveis\n";
        for (i = 0; i <= conDep; i++) {
          DP[i].mostra_departamento();
        }
        cout << "\nDigite o codigo do departamento que deseja excluir"
             << "\nOpcao: " << endl;
        cin >> num;
        // Acha o departamento
        for (i = 0; i < conDep; i++) {
          if (num == DP[i].getCodDep()) { // verifica se o id digitado é igual o
                                          // id do departamento
            DP[i].setCodDep(
                &E); // substitui o codigo atual do departamento por -1
          }
        }
        cout << "\nExclusao Realizada com Sucesso!\n";
      }
      break;
    case 5: // Listagem de Departamentos, com filtro por nome do departamento
      cout << "\nDigite o nome do departamento que deseja listar: ";
      cin >> y;
      fflush(stdin);
      cout << "\nListagem:\n" << endl;
      cout << "Codigo"
           << "\t"
           << "Nome"
           << "\t\t"
           << "Descricao"
           << "\t\t"
           << "Predio"
           << "\n";
      // Verifica quais departamentos atendem às especificações
      for (i = 0; i < conDep; i++) {
        // Função para comparar a descrição digitada com os cadastros realizados
        R = Verifica_Strings(y, DP[i].getNomeDep());
        if (R == 0) {
          DP[i].mostra_departamento(); // chamando o procedimento para mostrar na tela
        }
      }
      break;
    case 6: // Salva dados em Arquivo
      // Abrindo o arquivo
      FILE *ArqDEP;
      ArqDEP = fopen("Departamento.txt", "w");
      // Verificando se o arquivo existe
      if (ArqDEP == NULL) {
        printf("\nArquivo inexistente\n");
      }
      // Preenchendo o arquivo
      for (int i = 0; i < Max && i < conDep; i++) {
        fprintf(ArqDEP, "%d", DP[i].getCodDep());
        fprintf(ArqDEP, "%s", DP[i].getNomeDep());
        fprintf(ArqDEP, "%s", DP[i].getDescricaoDep());
        fprintf(ArqDEP, "%d", DP[i].getLocalDep());
      }
      printf("\nArquivo preenchido com sucesso!\n");
      // Fechando o arquivo
      fclose(ArqDEP);
      break;
    case 7: //Cadastra Equipamentos
      menuEQ();
      break;
    case 8: //Lista arquivo
      FILE *Arquivo;
      //Entrada do nome do arquivo
      cout << "\nInsira o nome do arquivo: ";
      cin >> N_Arq;
      fflush (stdin);
      //Abre o arquivo
      Arquivo = fopen (N_Arq, "rb");
      // Verificando se o arquivo existe
      if (Arquivo == NULL) {
        printf("\nArquivo inexistente\n");
      }
      else {
        //Determina o tamanho do arquivo
        fread (&LimArq, sizeof(int), 1, Arquivo);
            LimArq++;
        //Le o arquivo de equipamento
        fread (DP, sizeof(Departamento), LimArq, Arquivo);
        //Exibe o conteudo lido dentro do arquivo
        for (int i = 0; i < LimArq; i++){
          DP[i].mostra_departamento();
        }
      //Fecha o arquivo
      fclose (Arquivo);
      }
      break;
    default: // Valor inválido
      cout << "\nOPCAO INVALIDA\n";
      break;
    }
  } while (op != 0);
}

//_________________________________________________________________________________
// Menu do CRUD de Tipos de Equipamento
void menuTE() {
  int op, N, i, Id, x, num, j, R, E = -1, LimArq = 0;
  bool r;
  char Desc[100], y[100], N_Arq[100];
  do {
    cout << "\nTIPOS DE EQUIPAMENTO\n";
    cout << "[0] - Voltar ao Menu Anterior\n";
    cout << "[1] - Cadastrar Tipo de Equipamento\n";
    cout << "[2] - Mostrar Tipos de Equipamento\n";
    cout << "[3] - Alterar Cadastro\n";
    cout << "[4] - Excluir Cadastro\n";
    cout << "[5] - Lista Tipos de Equipamento\n";
    cout << "[6] - Salva dados em Arquivo\n";
    cout << "[7] - Menu Departamentos\n";
    cout << "[8] - Lista Arquivo\n";
    cout << "Opcao: ";
    cin >> op;
    switch (op) {
    case 0: // Volta ao menu anterior
      cout << "\nVoltando ao menu anterior\n\n...\n\n";
      break;
    case 1: // Cadastro de tipo de equipamento
      cout << "\nQuantos tipos de equipamento deseja cadastrar? ";
      cin >> N;
      for (i = 0; i < Max && i < N; i++) {
        cout << "\nTipo de Equipamento " << i + 1;
        Id = i + 1;
        cout << "\nCodigo de Identificacao: " << Id << endl;
        cout << "Descricao: ";
        cin >> Desc;
        fflush(stdin);
        // Passando os valores para o CRUD
        TE[i].setCodTE(&Id);
        TE[i].setDescricaoTE(Desc);
        conTE++; // Contador de cadastros
      }
      cout << "\nTipos de Equipamento cadastrados com sucesso!\n";
      break;
    case 2: // Mostra os Tipos de Equipamento
      r = tem_cadastro_TE(
          conTE); // Verifica se possui cadastro de tipo de equipamento
      if (r == 0)
        cout << "\nNao existe cadastro do tipo de equipamento\n" << endl;
      else {
        cout << "\nTipos de Equipamento Disponiveis:" << endl;
        cout << "Codigo"
             << "\t"
             << "Descricao"
             << "\n"
             << endl;
        for (i = 0; i < conTE; i++) {
          TE[i].mostra_tipdeeq(); // chamando o procedimento
        }
      }
      break;
    case 3: // Altera cadastro de Tipos de Equipamento
      r = tem_cadastro_TE(
          conTE); // Verifica se possui cadastro de tipo de equipamento
      if (r == 0)
        cout << "\nNao existe cadastro do tipo de equipamento\n" << endl;
      else {
        cout << "\nDigite o codigo do tipo de equipamento que deseja "
                "alterar: ";
        cin >> x;
        // Verificação se há algum cadastro com o codigo desejado
        for (int i = 0; i < Max; i++) {
          if (TE[i].getCodTE() == x) { // Se houver, realiza a mudança
            cout << "\nDigite a Nova Descricao: ";
            cin >> Desc;
            fflush(stdin);
            cout << "\nAlteracao Realizada com Sucesso!\n";
            // Passando o novo valor para a variável global
            TE[x - 1].setDescricaoTE(Desc);
          }
        }
      }
      break;
    case 4: // Exclui cadastro de Tipos de Equipamento
      r = tem_cadastro_TE(
          conTE); // Verifica se possui cadastro de tipo de equipamento
      if (r == 0)
        cout << "\nNao existe cadastro do tipo de equipamento\n" << endl;
      else {
        // Exibe os tipos de equipamentos disponiveis para que algum possa
        // ser excluido
        cout << "\nTipos de Equipamento Disponíveis para Exclusão:\n" << endl;
        for (i = 0; i < conTE; i++) {
          TE[i].mostra_tipdeeq();
        }
        cout << "\nDigite o codigo do tipo de equipamento que deseja excluir: "
             << endl;
        cin >> num;
        // Acha o Tipo de equipamento e o exclui
        for (i = 0; i <= conTE; i++) {
          if (num == TE[i].getCodTE()) { // verifica se o id digitado é igual o
                                         // id do tipo de equipamento
            TE[i].setCodTE(
                &E); // substitui o codigo atual do tipo de equipamento por -1
          }
        }
        cout << "\nExclusao Realizada com Sucesso!\n";
      }
      break;
    case 5: // Listagem de Tipos de Equipamento
      cout << "\nDigite o Tipo de Equipamento que deseja listar: ";
      cin >> y;
      fflush(stdin);
      cout << "\nListagem:\n" << endl;
      cout << "Codigo"
           << "\t"
           << "Descricao"
           << "\n"
           << endl;
      // Verifica quais tipos de equipamento atendem às especificações
      for (i = 0; i < conTE; i++) {
        // Função para comparar a descrição digitada com os cadastros realizados
        R = Verifica_Strings(y, TE[i].getDescricaoTE());
        if (R == 0) {
          TE[i]
              .mostra_tipdeeq(); // chamando o procedimento para mostrar na tela
        }
      }
      break;
    case 6: // Salva dados em Arquivo
      // Abrindo o arquivo
      FILE *ArqTE;
      ArqTE = fopen("Tipo_de_Equipamento.txt", "w");
      // Verificando se o arquivo existe
      if (ArqTE == NULL) {
        printf("\nArquivo inexistente\n");
      }
      // Preenchendo o arquivo
      for (int i = 0; i < Max && i < conTE; i++) {
        fprintf(ArqTE, "%d", TE[i].getCodTE());
        fprintf(ArqTE, "%s", TE[i].getDescricaoTE());
      }
      printf("\nArquivo preenchido com sucesso!\n");
      // Fechando o arquivo
      fclose(ArqTE);
      break;
    case 7: //Menu de cadastros de Departamentos
      menuDep();
      break;
    case 8: //Lista arquivo
      FILE *Arquivo;
      //Entrada do nome do arquivo
      cout << "\nInsira o nome do arquivo: ";
      cin >> N_Arq;
      fflush (stdin);
      //Abre o arquivo
      Arquivo = fopen (N_Arq, "rb");
      // Verificando se o arquivo existe
      if (Arquivo == NULL) {
        printf("\nArquivo inexistente\n");
      }
      else {
        //Determina o tamanho do arquivo
        fread (&LimArq, sizeof(int), 1, Arquivo);
            LimArq++;
        //Le o arquivo de equipamento
        fread (DP, sizeof(Tipo_Equipamento), LimArq, Arquivo);
        //Exibe o conteudo lido dentro do arquivo
        for (int i = 0; i < LimArq; i++){
          TE[i].mostra_tipdeeq();
        }
      //Fecha o arquivo
      fclose (Arquivo);
      }
      break;
    default: // Valor inválido
      cout << "\nOPCAO INVALIDA\n";
      break;
    }
  } while (op != 0);
}

/*************************************************************************************
                                       DEFININDO O MAIN
*************************************************************************************/
int main() {
  // Declaração e atribuição de valor às variáveis
  int op, op2, op3, N, I, i, conTE = 0;
  char C[100];

  // Criação do Menu de inicialização do programa
  cout << "\nOla! Seja bem-vindo!\n";
  do {
    cout << "\nComo deseja utilizar o programa?\n";
    cout << "[0] - Encerrar\n";
    cout << "[1] - Sem Comandos de Voz\n";
    cout << "[2] - Com Comandos de Voz\n";
    cout << "Opcao: ";
    cin >> op;
    switch (op) {
    case 0: // Encerra o programa
      cout << "\nPrograma Encerrado\nVolte Logo!";
      break;
    case 1: // Programa sem comandos de voz
      cout << "\nPrograma nao utilizara comandos de voz!\n";
      // Chamando o menu de opções
      menuTE();
      break;
    case 2: // Programa com comandos de voz
      cout << "\nPrograma utilizara comandos de voz!\n";
      break;
    default: // Opção inválida
      cout << "\nOpcao Invalida!\n";
      break;
    }
  } while (op != 0);
  return 0;
}