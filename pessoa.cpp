#include "pessoa.hpp"

using namespace std;


Pessoa::Pessoa(){
    idade=0;
    nome = "";
};

Pessoa::Pessoa(int idade, string nome) {
this->idade = idade;
nome = nome;
}

int  Pessoa::getIdade() {
    return idade;
}

void Pessoa::setIdade(int idade){
    this->idade=idade;
}

string Pessoa::getNome(){
    return nome;
}

void Pessoa::setNome(string nome){
    this->nome = nome;
}
