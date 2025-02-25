#ifndef __GENALLOPERATOR_H_
#define __GENALLOPERATOR_H_
#include "geraopvar.h"
#include "geraopera.h"
#include <string>

using namespace std;

   typedef struct {
      string varxk;
      int ctrl;
      int setxmax;
   } maxvar;

void genallop( operacao *opvar, maxvar *defr, asseline *operadores);


#endif // GENALLOPERATOR_H_INCLUDED
