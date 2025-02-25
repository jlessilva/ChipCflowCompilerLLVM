#ifndef CLASSEDOIS_H_INCLUDED
#define CLASSEDOIS_H_INCLUDED

using namespace std;

class Truck{

public:

    int modelo;
    Truck (int tp);
    bool getLigado();
    void setLigado(int l);
    int getAutomatico();
    int getPesoMax();
    int getVelMax();
    int getNome();
    void setPassageiro(int p);
    bool getPassageiro();

private:
    int automatico;
    void setAutomatico(int a);
    int velMax;
    void setVelMax(int vm);
    int pesoMax;
    void setPesoMax(int a);
    bool ligado;
    bool passageiro;
    void setNome(int tx);
    int nome;


};



void Truck::setNome(int tx){
        nome=1;
};

int Truck::getNome(){
      return nome;
}

void Truck::setAutomatico(int a){   // definindo fun��o de autom�tico ou n�o que s� vai informar, pela variavel automatico, que � privada � uma coisa ou outra
        automatico=a;
}

int Truck::getAutomatico(){      // essa fun�ao na verdade � quem retorna para o progama main qual a situa��o do automatico que vai ser definido privado dentro
      return automatico;         // da categoria de Truck, ou seja, ela vincula a variavel automatico que � priavada
}

void Truck::setPesoMax(int k){      //definindo fun��o de peso pesomaxio; que vai retornar um valor conforme modelo de peso;
        pesoMax=k;
}

int Truck::getPesoMax(){      // essa fun�ao na verdade � quem retorna para o progama main qual a situa��o do automatico que vai ser definido privado dentro
      return pesoMax;         // da categoria de Truck, ou seja, ela vincula a variavel automatico que � priavada
};

void Truck::setLigado(int l){     //essa fun�ao faz acesso a variavel ligado que � privada e s� pode ser acessado via funcao a ser utilizada no main.
    if(l==1){
        ligado=true;
    }else if(l==0){
        ligado=false;
        }
};


bool Truck::getLigado(){      // essa fun�ao na verdade � quem retorna para o progama main qual a situa��o do ligado, ou seja, ela vincula a variavel ligado
    return ligado;             // a partir da definicao da funcao que defini o que sera a variavel ligado, tudo
}


void Truck::setPassageiro(int p){     //essa fun�ao faz acesso a variavel ligado que � privada e s� pode ser acessado via funcao a ser utilizada no main.
    if(p==1){
        passageiro=true;
    }else if(p==0){
        passageiro=false;
        }
};


bool Truck::getPassageiro(){      // essa fun�ao na verdade � quem retorna para o progama main qual a situa��o do ligado, ou seja, ela vincula a variavel ligado
    return passageiro;             // a partir da definicao da funcao que defini o que sera a variavel ligado, tudo
}

int Truck::getVelMax(){  //get sempre � a variavel de retorno dentro do main para os valores setado no privado dentro da class.
    return velMax;
}

void Truck::setVelMax(int vm){
    velMax=vm;
};


Truck::Truck(int tp){//~Jato, 2~Monomotor, 3~Planador
     modelo=tp;
    if (modelo==1){
        setVelMax(90);
        setPesoMax(30000);
        setAutomatico(1);
        setNome(1);
    }else if(modelo==2){
        setVelMax(90);
        setPesoMax(20000);
        setAutomatico(0);
        setNome(1);
    }else if (modelo==3){
        setVelMax(80);
        setPesoMax(10000);
        setAutomatico(1);
        setNome(1);

    }
    setLigado(0);

}



#endif // CLASSEDOIS_H_INCLUDED
