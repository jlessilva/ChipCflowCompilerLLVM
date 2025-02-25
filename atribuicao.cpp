#include "atribuicao.h"
#include "funcopera.h"
#include "geraopvar.h"
#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void atribuicao(int indopera,int indexvarx,int indexsimb, char buffersimbol[], defvarx *varx, operacao *opvar)
{
   if (buffersimbol[indexsimb] != '=' && buffersimbol[indexsimb] != '0')
                                     {  indexsimb--;
                                        indexsimb--;
                                        indexvarx--;
                                        opvar[indopera].x1=buffersimbol[indexsimb];cout << opvar[indopera].x1 << endl;
                                        varx[indexvarx].varxy=buffersimbol[indexsimb];cout << varx[indexvarx].varxy;  cout << indexvarx << endl;
                                        varx[indexvarx].staxy=1;
                                        indexvarx++;
                                        indexsimb++;
                                        indexsimb++;
                                        opvar[indopera].x2=buffersimbol[indexsimb];cout << opvar[indopera].x2 << endl;
                                        varx[indexvarx].varxy=buffersimbol[indexsimb];cout << varx[indexvarx].varxy;  cout << indexvarx << endl;
                                        indexvarx++;
                                        indexsimb++;
                                        if (buffersimbol[indexsimb] == '+')
                                            {
                                                opvar[indopera].opera="add";
                                                //indopera++;
                                            } else if (buffersimbol[indexsimb] == '-')
                                                        {
                                                            opvar[indopera].opera="sub";
                                                            //indopera++;
                                                        } else if (buffersimbol[indexsimb] == '*')
                                                                {
                                                                    opvar[indopera].opera="mul";
                                                                    //indopera++;
                                                                } else if (buffersimbol[indexsimb] == '/')
                                                                        {
                                                                            opvar[indopera].opera="div";
                                                                            //indopera++;
                                                                        }
                                        indexsimb++;
                                        opvar[indopera].x3=buffersimbol[indexsimb];cout << opvar[indopera].x3 << endl;
                                        varx[indexvarx].varxy=buffersimbol[indexsimb];cout << varx[indexvarx].varxy;  cout << indexvarx << endl;
                                        indexvarx++;
                                        indopera++;
 /*                                    } else if (buffersimbol[indexsimb]=='0')
                                                {
                                                    indexsimb--;
                                                } else {    indexsimb--; varx[indexvarx].varxy=buffersimbol[indexsimb];cout << varx[indexvarx].varxy;  cout << indexvarx << endl;
                                                            indexvarx++;
                                                        }*/


                                    } else if (buffersimbol[indexsimb] == '0')
                                            {   indexsimb--;
                                                if (buffersimbol[indexsimb] == '=')
                                                   {    indexsimb--;
                                                        opvar[indopera].x1=buffersimbol[indexsimb];
                                                        varx[indexvarx].varxy=buffersimbol[indexsimb];cout << varx[indexvarx].varxy;  cout << indexvarx << endl;
                                                        indexvarx++;
                                                        opvar[indopera].x2='\0';
                                                        opvar[indopera].x3='\0';
                                                        opvar[indopera].opera="iniczero";
                                                        indopera++;
                                                        indexsimb++;
                                                        indexsimb++;
                                                    }
                                                else {   indexsimb--; varx[indexvarx].varxy=buffersimbol[indexsimb];cout << varx[indexvarx].varxy;  cout << indexvarx << endl;
                                                            indexvarx++;
                                                     }
                                            }
}
