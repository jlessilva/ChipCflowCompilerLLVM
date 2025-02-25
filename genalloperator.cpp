#include "genalloperator.h"
#include "geraopvar.h"
#include "geraopera.h"
#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

// GERA TODOS OS OPERADORES JA COM OS RESPECTIVOS CONSTD E COPYS A PARTIR DA REPETICAO DAS VARIAVEIS
// E DA FUNCAO ENCONTRADA NO PROGRAMA C

void genallop( operacao *opvar, maxvar *defr, asseline *operadores)
    {
     cout << "cheguei sim" << endl;

    int i=0;
    int *v;
    int zero=0;
    int dorc=0;
    char op='\0';
//    int *r;
    int j=0;
    int *inteiroi;
    int k=0;
    int refj=0;
//    r=&zero;
    char ope[100];
    int um=1;
    int notend=1;
    inteiroi = &um;
    while (defr[i].varxk!="\n")
    {   cout << defr[i].varxk; cout << defr[i].setxmax; cout << defr[i].ctrl << endl;
        if (defr[i].setxmax==1 && defr[i].ctrl!=1) {ope[i]='1';refj=1;dorc=1;}
        else if (defr[i].setxmax==2 && defr[i].ctrl!=1) {ope[i]='2';refj=2;dorc=1;}
        else if (defr[i].setxmax==3 && defr[i].ctrl!=1) {ope[i]='3';refj=3;dorc=1;}
        else if (defr[i].setxmax==4 && defr[i].ctrl!=1) {ope[i]='4';refj=4;dorc=1;}
        else if (defr[i].setxmax==5 && defr[i].ctrl!=1) {ope[i]='5';refj=5;dorc=1;}
        else if (defr[i].setxmax==6 && defr[i].ctrl!=1) {ope[i]='6';refj=6;dorc=1;}
        else if (defr[i].setxmax==7 && defr[i].ctrl!=1) {ope[i]='7';refj=7;dorc=1;}
        else if (defr[i].setxmax==1 && defr[i].ctrl!=0) {ope[i]='1';refj=1;dorc=0;}
        else if (defr[i].setxmax==2 && defr[i].ctrl!=0) {ope[i]='2';refj=2;dorc=0;}
        else if (defr[i].setxmax==3 && defr[i].ctrl!=0) {ope[i]='3';refj=3;dorc=0;}
        else if (defr[i].setxmax==4 && defr[i].ctrl!=0) {ope[i]='4';refj=4;dorc=0;}
        else if (defr[i].setxmax==5 && defr[i].ctrl!=0) {ope[i]='5';refj=5;dorc=0;}
        else if (defr[i].setxmax==6 && defr[i].ctrl!=0) {ope[i]='6';refj=6;dorc=0;}
        else if (defr[i].setxmax==7 && defr[i].ctrl!=0) {ope[i]='7';refj=7;dorc=0;}

        cout << "valor de op[i] = "; cout << ope[i] << endl;

        geraop(j,i,dorc,inteiroi,ope,operadores);
        j=j+refj;
        cout << "valor de op[i] = "; cout << ope[i] << endl;
        cout << "valor de J na saida da funçao = "; cout << j << endl;
//        cout << "valor de r = "; cout << r << endl;
//        cout << "valor de inteiroi = "; cout << inteiroi << endl;

      //  cout << operadores[r].funcao + " "; cout << operadores[r].s1 + ","; cout << operadores[r].s2 + ","; cout << operadores[r].s3 + ","; cout << operadores[r].s4 + ","; cout << operadores[r].s5 + ","; cout << operadores[r].s6 + ";" << endl;
        cout << defr[i].varxk; cout << defr[i].setxmax<< endl;
        i++;
        cout << defr[i].varxk << endl;
//        r++;

 };
    int indexvarx=0;
    int indopera=0;
   // cout << opera[indopera] << endl;
    while (opvar[indopera].opera!="\n")
    {//   cout << opera[indopera] << endl;
        if (opvar[indopera].opera=="if")
        {   ope[i]='i';refj=1;
            geraop(j,i,dorc,inteiroi,ope,operadores);

            j=j+refj;
                    cout << "valor de J na saída da funçao = "; cout << j << endl;

 //       cout << operadores[i].funcao + " "; cout << operadores[i].s1 + ","; cout << operadores[i].s2 + ","; cout << operadores[i].s3 + ","; cout << operadores[i].s4 + ","; cout << operadores[i].s5 + ","; cout << operadores[i].s6 + ";" << endl;
            i++;
            ope[i]='b';
            geraop(j,i,dorc,inteiroi,ope,operadores);

            j=j+refj;
        cout << "valor de J na saída da funçao = "; cout << j << endl;
        int contachave=opvar[indopera].xx;

 //       cout << operadores[i].funcao + " "; cout << operadores[i].s1 + ","; cout << operadores[i].s2 + ","; cout << operadores[i].s3 + ","; cout << operadores[i].s4 + ","; cout << operadores[i].s5 + ","; cout << operadores[i].s6 + ";" << endl;
            if(contachave!=0)
            {while(contachave>1)
            {
//                i++;
//                ope[i]='o';
//                geraop(j,i,dorc,inteiroi,ope,operadores);
//
//                j=j+refj;
//                cout << "valor de J na saída da funçao = "; cout << j << endl;

                i++;
                ope[i]='p';
                geraop(j,i,dorc,inteiroi,ope,operadores);

                j=j+refj;
                cout << "valor de J na saída da funçao = "; cout << j << endl;
                contachave--;
            }
            i++;
            }

            contachave=opvar[indopera].yy;

 //       cout << operadores[i].funcao + " "; cout << operadores[i].s1 + ","; cout << operadores[i].s2 + ","; cout << operadores[i].s3 + ","; cout << operadores[i].s4 + ","; cout << operadores[i].s5 + ","; cout << operadores[i].s6 + ";" << endl;

            if(contachave==1)
            {
//                i++;
//                ope[i]='o';
//                geraop(j,i,dorc,inteiroi,ope,operadores);
//
//                j=j+refj;
//                cout << "valor de J na saída da funçao = "; cout << j << endl;

                ope[i]='p';
                geraop(j,i,dorc,inteiroi,ope,operadores);

                j=j+refj;
                cout << "valor de J na saída da funçao = "; cout << j << endl;
                contachave--;
            }
            i++;
        } else if (opvar[indopera].opera=="add")
                {   ope[i]='+';
                    geraop(j,i,dorc,inteiroi,ope,operadores);

                    j=j+refj;
                    cout << "valor de J na saída da funçao = "; cout << j << endl;

 //       cout << operadores[i].funcao + " "; cout << operadores[i].s1 + ","; cout << operadores[i].s2 + ","; cout << operadores[i].s3 + ","; cout << operadores[i].s4 + ","; cout << operadores[i].s5 + ","; cout << operadores[i].s6 + ";" << endl;
                    i++;
                } else if (opvar[indopera].opera=="mul")
                        {   ope[i]='*';
                            geraop(j,i,dorc,inteiroi,ope,operadores);

                            j=j+refj;
                            cout << "valor de J na saída da funçao = "; cout << j << endl;

 //       cout << operadores[i].funcao + " "; cout << operadores[i].s1 + ","; cout << operadores[i].s2 + ","; cout << operadores[i].s3 + ","; cout << operadores[i].s4 + ","; cout << operadores[i].s5 + ","; cout << operadores[i].s6 + ";" << endl;
                            i++;
                        } else if (opvar[indopera].opera=="sub")
                                {   ope[i]='-';
                                    geraop(j,i,dorc,inteiroi,ope,operadores);

                                    j=j+refj;
                                    cout << "valor de J na saída da funçao = "; cout << j << endl;

 //       cout << operadores[i].funcao + " "; cout << operadores[i].s1 + ","; cout << operadores[i].s2 + ","; cout << operadores[i].s3 + ","; cout << operadores[i].s4 + ","; cout << operadores[i].s5 + ","; cout << operadores[i].s6 + ";" << endl;
                                    i++;
                                } else if (opvar[indopera].opera=="div")
                                        {   ope[i]='/';
                                            geraop(j,i,dorc,inteiroi,ope,operadores);

                                            j=j+refj;
                                            cout << "valor de J na saída da funçao = "; cout << j << endl;

 //       cout << operadores[i].funcao + " "; cout << operadores[i].s1 + ","; cout << operadores[i].s2 + ","; cout << operadores[i].s3 + ","; cout << operadores[i].s4 + ","; cout << operadores[i].s5 + ","; cout << operadores[i].s6 + ";" << endl;
                                            i++;
                                        } else if (opvar[indopera].opera=="acc")//------------------------------------------26/4
                                                {   ope[i]='0';
                                                    geraop(j,i,dorc,inteiroi,ope,operadores);

                                                    j=j+refj;
                                                    cout << "valor de J na saída da funçao = "; cout << j << endl;

 //       cout << operadores[i].funcao + " "; cout << operadores[i].s1 + ","; cout << operadores[i].s2 + ","; cout << operadores[i].s3 + ","; cout << operadores[i].s4 + ","; cout << operadores[i].s5 + ","; cout << operadores[i].s6 + ";" << endl;
                                                    i++;
                                                } else if (opvar[indopera].opera=="accm")//------------------------------------------26/4
                                                    {   ope[i]='m';
                                                        geraop(j,i,dorc,inteiroi,ope,operadores);

                                                        j=j+refj;
                                                        cout << "valor de J na saída da funçao = "; cout << j << endl;

 //       cout << operadores[i].funcao + " "; cout << operadores[i].s1 + ","; cout << operadores[i].s2 + ","; cout << operadores[i].s3 + ","; cout << operadores[i].s4 + ","; cout << operadores[i].s5 + ","; cout << operadores[i].s6 + ";" << endl;
                                                        i++;
                                                    } else if (opvar[indopera].opera=="for")
                                                        {   ope[i]='f';refj=1;
                                                            geraop(j,i,dorc,inteiroi,ope,operadores);
                                                            j=j+refj+3;
                                                            cout << "valor de J na saída da funçao = "; cout << j << endl;

                                                    //       cout << operadores[i].funcao + " "; cout << operadores[i].s1 + ","; cout << operadores[i].s2 + ","; cout << operadores[i].s3 + ","; cout << operadores[i].s4 + ","; cout << operadores[i].s5 + ","; cout << operadores[i].s6 + ";" << endl;
                                                            i++;
                                                            ope[i]='b';
                                                            geraop(j,i,dorc,inteiroi,ope,operadores);

                                                         //   else if (opvar[indopera].opera=="zeroif")
                                                           //     {   ope[i]='&';
                                                             //       geraop(j,i,dorc,inteiroi,ope,operadores);
                                                            j=j+refj;
                                                            cout << "valor de J na saída da funçao = "; cout << j << endl;
                                                            int contachave=opvar[indopera].xx;

                                            //       cout << operadores[i].funcao + " "; cout << operadores[i].s1 + ","; cout << operadores[i].s2 + ","; cout << operadores[i].s3 + ","; cout << operadores[i].s4 + ","; cout << operadores[i].s5 + ","; cout << operadores[i].s6 + ";" << endl;
                                                        if(contachave!=0)
                                                        {while(contachave>1)
                                                        {
                                                            //i++;
															//                ope[i]='o';
                                                            //                geraop(j,i,dorc,inteiroi,ope,operadores);
                                                            //
                                                            //                j=j+refj;
                                                            //                cout << "valor de J na saída da funçao = "; cout << j << endl;

                                                            i++;
                                                            ope[i]='p';
                                                            geraop(j,i,dorc,inteiroi,ope,operadores);




                                                            j=j+refj;
                                                            cout << "valor de J na saída da funçao = "; cout << j << endl;
                                                            contachave--;
                                                        }
                                                        i++;
                                                        }

                                                        contachave=opvar[indopera].yy;

                                                        //       cout << operadores[i].funcao + " "; cout << operadores[i].s1 + ","; cout << operadores[i].s2 + ","; cout << operadores[i].s3 + ","; cout << operadores[i].s4 + ","; cout << operadores[i].s5 + ","; cout << operadores[i].s6 + ";" << endl;



                                                        if(contachave==1)
                                                        {
                                                        //                i++;
                                                        //                ope[i]='o';
                                                        //                geraop(j,i,dorc,inteiroi,ope,operadores);
                                                        //
                                                        //                j=j+refj;
                                                        //                cout << "valor de J na saída da funçao = "; cout << j << endl;

                                                            ope[i]='p';
                                                            geraop(j,i,dorc,inteiroi,ope,operadores);

                                                            j=j+refj;
                                                            cout << "valor de J na saída da funçao = "; cout << j << endl;
                                                            contachave--;
														}
                                                            i++;
                                                        } else if (opvar[indopera].opera=="dualload")
                                                                  {   ope[i]='l';
                                                                        geraop(j,i,dorc,inteiroi,ope,operadores);

                                                                        j=j+refj+1;
                                                                        cout << "valor de J na saída da funçao = "; cout << j << endl;

 //       cout << operadores[i].funcao + " "; cout << operadores[i].s1 + ","; cout << operadores[i].s2 + ","; cout << operadores[i].s3 + ","; cout << operadores[i].s4 + ","; cout << operadores[i].s5 + ","; cout << operadores[i].s6 + ";" << endl;
                                                                        i++;
                                                                    } else if (opvar[indopera].opera=="dualstore")
                                                                            {   ope[i]='s';
                                                                                geraop(j,i,dorc,inteiroi,ope,operadores);

                                                                                j=j+refj+1;
                                                                                cout << "valor de J na saída da funçao = "; cout << j << endl;

 //       cout << operadores[i].funcao + " "; cout << operadores[i].s1 + ","; cout << operadores[i].s2 + ","; cout << operadores[i].s3 + ","; cout << operadores[i].s4 + ","; cout << operadores[i].s5 + ","; cout << operadores[i].s6 + ";" << endl;
                                                                                i++;
                                                                            }

         cout << opvar[indopera].opera << endl;
         indopera++;
    };
    cout << "chegamos no fim" << endl;
  //  cout << "valor de  i = " ; cout << i << endl;
    ope[i]='\0';
    geraop(j,i,dorc,inteiroi,ope,operadores); // GERANDO CARACTER NULO NO ULTIMO REGISTRO DE OPERADORES

    cout << "cheguei ate aqui"  << endl;

    j=0;
    while (operadores[j].funcao!="\n")
    {
       cout << operadores[j].funcao + " "; cout << operadores[j].s1 + ","; cout << operadores[j].s2 + ","; cout << operadores[j].s3 + ","; cout << operadores[j].s4 + ","; cout << operadores[j].s5 + ","; cout << operadores[j].s6 + ","; cout << operadores[j].s7 + ";" << endl;
    j++;
   }
    }
