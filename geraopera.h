#ifndef __GERAOPERA_H_
#define __GERAOPERA_H_
#include <string>
//#include "genalloperator.h"

using namespace std;

//std::string indice(int k, char inds[100]="");

   typedef struct {
      string funcao;
      string s1;
      string s2;
      string s3;
      string s4;
      string s5;
      string s6;
      string s7;
      string s8;
      int staop;
      int stanes;
    } asseline;

void geraop( int j, int i, int dorc, int *inteiro, char op[], asseline *operador);

#endif // GERAOPERA_H_INCLUDED
