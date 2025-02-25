#ifndef __GERAOPVAR_H_
#define __GERAOPVAR_H_
#include <string>
#include "funcopera.h"
#include "geraopera.h"

using namespace std;

   typedef struct {
      string opera;
      string x1;
      string x2;
      int stx2;
      string x3;
      int stx3;
      int xx;
      int yy;
      int staop;
      int staat;
      int matrix;
      int vetor;
   } operacao;


void gopvar(char buffersimbol[], string charsimb[], defvarx *varx, operacao *opvar);


#endif // GERAOPVAR_H_INCLUDED
