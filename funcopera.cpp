#include "funcopera.h"
#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void defrep(defvarx *varx){    // gera variaveis e suas repeticoes
int indevari;
int indexrep;
int indesetx;
int contigual;
string varix;
            indevari=0;
            varix=varx[indevari].varxy;
            while (varx[indevari].varxy !="\n")
            {
                indexrep=0;
                contigual=0;
                indesetx=0;
                while (varx[indexrep].varxy !="\n")
                     { cout << varx[indevari].varxy << endl;
                         if (varx[indexrep].varxy == varix )
                        if(varx[indexrep].staxy!=1)
                            {contigual++; varx[indesetx].setxy=contigual; varx[indesetx].staxy=0;}
                        else varx[indesetx].setxy=1;
                         indexrep++;
                         indesetx++;
                     };

             indevari++;
             varix=varx[indevari].varxy;
             }
};

