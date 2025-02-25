#ifndef AVIAO_H_INCLUDED
#define AVIAO_H_INCLUDED

using namespace std;

class Aviao{

public:
    int velMax;
    int tipo;
    Aviao(int tp);
//    int getVelMax();
private:
    int vel;
    string nome;
    bool ligado;

};

//int Aviao::getVelMax(){
//    return velMax;
//}

Aviao::Aviao(int tp){//~Jato, 2~Monomotor, 3~Planador

     tipo=tp;
    if (tipo==1){
        nome="Carro";
        velMax=200;
    }
    else if(tipo==2){
       nome="Aviao";
      velMax=800;
    }else if (tipo==3){
       nome="Navio";
      velMax=120;
    }


//void Aviao::imprimir(){
//    cout << endl;
//    cout<< "Tipo..............:" << tipo << endl;
//    cout<< "Velocidade Máxima.:" << velMax << endl;
//    cout<< "Velocidade Atual..:" << vel << endl;

//}


#endif // AVIAO_H_INCLUDED
