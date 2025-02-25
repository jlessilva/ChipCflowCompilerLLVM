#ifndef CLASSEUM_H_INCLUDED
#define CLASSEUM_H_INCLUDED

class Veiculo{

public:
    int vel;
    int tipo;
    Veiculo(int tp);
    int getVelMax();
    bool getLigado();
    void setLigado(int l);
private:
    void setVelMax(int vm);
    std::string nome;
    int velMax;
    bool ligado;

};

void Veiculo::setLigado(int l){
    if(l==1){
        ligado=true;
    }else if(l==0){
        ligado=false;
        }
};


bool Veiculo::getLigado(){
    return ligado;
}

int Veiculo::getVelMax(){
    return velMax;
}

void Veiculo::setVelMax(int vm){
    velMax=vm;
};


Veiculo::Veiculo(int tp){//~Jato, 2~Monomotor, 3~Planador
     tipo=tp;
    if (tipo==1){
        nome="Carro";
        setVelMax(200);
    }else if(tipo==2){
       nome="Aviao";
      setVelMax(800);
    }else if (tipo==3){
       nome="Navio";
      setVelMax(120);
    }
    setLigado(0);
}


#endif // CLASSEUM_H_INCLUDED
