#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pessoa {
private:
  string nome;
  vector<string> listaDesenhos;
  vector<Pessoa *> listaAmigos;

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
  for (const auto &pessoa : lista) {
    cout << pessoa->getNome() << endl;
  }
  cout << endl;
}

void menu(vector<Pessoa *> &pessoas) {
  cout << "Bem-vindo ao sistema de cadastro de usuários!" << endl;
  int opcao = 0;

  while (opcao != 4) {
    cout << "Menu:" << endl;
    cout << "1. Cadastrar pessoa" << endl;
    cout << "2. Exibir lista de pessoas" << endl;
    cout << "3. Ver informações de uma pessoa" << endl;
    cout << "4. Sair do sistema" << endl;
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
      if (!pessoas.empty()) {
        cout << "Digite o número da pessoa que deseja ver as informações: ";
        int indice;
        cin >> indice;
        cin.ignore();
        if (indice >= 0 && indice < pessoas.size()) {
          pessoas[indice]->mostrarDesenhos();
          pessoas[indice]->mostrarAmigos();
        } else {
          cout << "Índice inválido." << endl;
        }
      } else {
        cout << "Não há pessoas cadastradas." << endl;
      }
      break;
    case 4:
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
