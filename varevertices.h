#ifndef __VAREVERTICES_H_
#define __VAREVERTICES_H_
#include "genalloperator.h"
#include "funcopera.h"
#include <string>

using namespace std;

void defmax(defvarx *varx, string charsimb[], maxvar *defr);

      typedef struct {
      string verts;
      string variref;
      int stav;
   } vertices;

void statusvert(asseline* operadores, vertices *vert);
void statusrep(asseline *operadores,maxvar *defr,vertices *vert);

      typedef struct {
      string varrx;
      string vrefv;
      int varsta;
   } varepsta;
void gervarep(maxvar *defr, varepsta *varep);


#endif // VAREVERTICES_H_INCLUDED
