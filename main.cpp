#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pessoa {
private:
  string nome;
  vector<string> listaDesenhos;
  vector<Pessoa *> listaAmigos;
  vector<string> listaExercicios;

public:
  Pessoa(string _nome) : nome(_nome) {}

  string getNome() const { return nome; }

  void adicionarDesenho(string desenho) { listaDesenhos.push_back(desenho); }

  void adicionarAmigo(Pessoa *amigo) { listaAmigos.push_back(amigo); }

  void mostrarDesenhos() const {
    cout << "Desenhos de " << nome << ":" << endl;
    for (const auto &desenho : listaDesenhos) {
      cout << "- " << desenho << endl;
    }
  }

  void mostrarAmigos() const {
    cout << "Amigos de " << nome << ":" << endl;
    for (const auto &amigo : listaAmigos) {
      cout << "- " << amigo->getNome() << endl;
    }
  }

  void adicionarExercicio(string exercicio) { listaExercicios.push_back(exercicio); }

  void mostrarExercicios() const {
    cout << "Exercícios de " << nome << ":" << endl;
    for (const auto &exercicio : listaExercicios) {
      cout << "- " << exercicio << endl;
    }
  }
};

void inserirUsuario(vector<Pessoa *> &lista) {
  string nome;
  cout << "Digite o nome da pessoa: ";
  getline(cin, nome);
  Pessoa *novaPessoa = new Pessoa(nome);
  lista.push_back(novaPessoa);
  cout << "Pessoa inserida com sucesso!" << endl << endl;
}

void exibirLista(const vector<Pessoa *> &lista) {
  cout << "Lista de pessoas:" << endl;
  for (size_t i = 0; i < lista.size(); ++i) {
    cout << i << ". " << lista[i]->getNome() << endl;
  }
  cout << endl;
}

void adicionarDesenho(vector<Pessoa *> &pessoas) {
  if (!pessoas.empty()) {
    cout << "Escolha o número da pessoa para adicionar um desenho: ";
    int indice;
    cin >> indice;
    cin.ignore();
    if (indice >= 0 && indice < pessoas.size()) {
      string desenho;
      cout << "Digite o desenho: ";
      getline(cin, desenho);
      pessoas[indice]->adicionarDesenho(desenho);
      cout << "Desenho adicionado com sucesso!" << endl;
    } else {
      cout << "Índice inválido." << endl;
    }
  } else {
    cout << "Não há pessoas cadastradas." << endl;
  }
}

void adicionarAmigo(vector<Pessoa *> &pessoas) {
  if (!pessoas.empty()) {
    cout << "Escolha o número da pessoa para adicionar um amigo: ";
    int indicePessoa;
    cin >> indicePessoa;
    cin.ignore();
    if (indicePessoa >= 0 && indicePessoa < pessoas.size()) {
      cout << "Escolha o número do amigo a ser adicionado: ";
      int indiceAmigo;
      cin >> indiceAmigo;
      cin.ignore();
      if (indiceAmigo >= 0 && indiceAmigo < pessoas.size()) {
        pessoas[indicePessoa]->adicionarAmigo(pessoas[indiceAmigo]);
        cout << "Amigo adicionado com sucesso!" << endl;
      } else {
        cout << "Índice do amigo inválido." << endl;
      }
    } else {
      cout << "Índice da pessoa inválido." << endl;
    }
  } else {
    cout << "Não há pessoas cadastradas." << endl;
  }
}

void adicionarExercicio(vector<Pessoa *> &pessoas) {
  if (!pessoas.empty()) {
    cout << "Escolha o número da pessoa para adicionar um exercício: ";
    int indice;
    cin >> indice;
    cin.ignore();
    if (indice >= 0 && indice < pessoas.size()) {
      string exercicio;
      cout << "Digite o exercício: ";
      getline(cin, exercicio);
      pessoas[indice]->adicionarExercicio(exercicio);
      cout << "Exercício adicionado com sucesso!" << endl;
    } else {
      cout << "Índice inválido." << endl;
    }
  } else {
    cout << "Não há pessoas cadastradas." << endl;
  }
}

void menu(vector<Pessoa *> &pessoas) {
  cout << "Bem-vindo ao sistema de cadastro de usuários!" << endl;
  int opcao = 0;

  while (opcao != 5) {
    cout << "Menu:" << endl;
    cout << "1. Cadastrar pessoa" << endl;
    cout << "2. Exibir lista de pessoas" << endl;
    cout << "3. Adicionar desenho a uma pessoa" << endl;
    cout << "4. Adicionar amigo a uma pessoa" << endl;
    cout << "5. Adicionar exercício a uma pessoa" << endl;
    cout << "6. Sair do sistema" << endl;
    cout << "Escolha uma opção: ";
    cin >> opcao;
    cin.ignore();

    switch (opcao) {
    case 1:
      inserirUsuario(pessoas);
      break;
    case 2:
      exibirLista(pessoas);
      break;
    case 3:
      adicionarDesenho(pessoas);
      break;
    case 4:
      adicionarAmigo(pessoas);
      break;
    case 5:
      adicionarExercicio(pessoas);
      break;
    case 6:
      cout << "Saindo do sistema. Até mais!" << endl;
      break;
    default:
      cout << "Opção inválida. Tente novamente." << endl << endl;
    }
  }
  for (auto pessoa : pessoas) {
    delete pessoa;
  }
}

int main() {
  vector<Pessoa *> pessoas;
  menu(pessoas);
  return 0;
}
