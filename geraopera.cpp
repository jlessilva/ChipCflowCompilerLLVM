#include "geraopera.h"
//#include "genalloperator.h"
#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

// GERA TODOS OS OPERADORES E SEUS VÉRTICES GENERICOS S1,S2, ETC A PARTIR DA CHAMADA DA FUNCAO ESPECIFICANDO
// QUAL OPERADOR DEVE SER MONTADO. TUDO RETORNA NA ESTRUTURA OPERADOR


string indice(int k, char(&inds)[100]) {
    _itoa_s(k, inds, 10);
    //    _itoa(g, indr, 10);   // itoa() is a function of stdlib.h file that convert integer
        // int to array itoa( integer, targated array, base u want to
        //convert like decimal have 10
    return inds;
};


void geraop( int j, int i, int dorc, int *inteiro, char op[], asseline *operador){
    char ind[100]="";
    int v;
    cout << "valor de op[j] na entrada"; cout << op[i] << endl;
    switch (op[i])
    {

    case '\0':
        operador[j].funcao="\n";
        operador[j].s1="\n";
        operador[j].s2="\n";
        operador[j].s3="\n";
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes=0;

             cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ","; cout << operador[j].s4 + ","; cout << operador[j].s5 + ","; cout << operador[j].s6 + ";" << endl;
    //    j++;
        break;

    case 'i':
        operador[j].funcao="decider";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes=0;

//    //v=(*j);
    cout << "Valor de J na entrada ="; cout << j  << endl;

              cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ";"<< endl;
//        j++;
        break;

    case 'm':
        operador[j].funcao="accm";//------------------------------------------------------------26/4
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

//    //v=(*j);
    cout << "Valor de J na entrada ="; cout << j  << endl;

              cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ";"<< endl;
//        j++;
        break;


    case '0':
        operador[j].funcao="acc";//------------------------------------------------------------26/4
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="\n";
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

//    //v=(*j);
    cout << "Valor de J na entrada ="; cout << j  << endl;

              cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ";"<< endl;
//        j++;
        break;

    case 'b':
        operador[j].funcao="dmerged";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s4="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

              cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + "," ;cout << operador[j].s4 + ";"<< endl;
   //     j++;
        break;

    case 'f':
        operador[j].funcao="foricexx";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s4="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s5="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s6="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s7="\n";
//        *inteiro=*inteiro+1;
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

             cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ","; cout << operador[j].s4 + ","; cout << operador[j].s5 + ","; cout << operador[j].s6 + ";" << endl;
  //      j++;

        j++;
        operador[j].funcao="copyc";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ";" << endl;
        //j++;

        j++;//---------------------------------------------------------------------------------7/7
        operador[j].funcao="copyc";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ";" << endl;
        //j++;//-------------------------------------------------------------------------------7/7


        j++;
        operador[j].funcao="copyc";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ";" << endl;
        //j++;
        break;

    case 'l':
        operador[j].funcao="dualload";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s4="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s5="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s6="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s7="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

             cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ","; cout << operador[j].s4 + ","; cout << operador[j].s5 + ","; cout << operador[j].s6 + ","; cout << operador[j].s7 + ";" << endl;
  //      j++;

        j++;
        operador[j].funcao="dualsram";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s4="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s5="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s6="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + "," ; cout << operador[j].s4 + "," ; cout << operador[j].s5 + "," ; cout << operador[j].s6 + ";"<< endl;
        //j++;


        break;

        case 's':
        operador[j].funcao="dualstore";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s4="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s5="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s6="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s7="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s8="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
//        *inteiro=*inteiro+1;
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

             cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ","; cout << operador[j].s4 + ","; cout << operador[j].s5 + ","; cout << operador[j].s6 + ","; cout << operador[j].s7 + ","; cout << operador[j].s8 + ";" << endl;
  //      j++;

        j++;
        operador[j].funcao="dualsram";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s4="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s5="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s6="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + "," ; cout << operador[j].s4 + "," ; cout << operador[j].s5 + "," ; cout << operador[j].s6 + ";"<< endl;
        //j++;


        break;

        case 'p':
        operador[j].funcao="dmerged";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s4="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ","; cout << operador[j].s4 + ";" << endl;
  //      j++;
        break;

    case '+':
        operador[j].funcao="add";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ";" << endl;
  //      j++;
        break;


    case '-':
        operador[j].funcao="sub";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ";" << endl;
  //      j++;
        break;
    case '*':
        operador[j].funcao="mul";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ";" << endl;
 //       j++;
        break;

    case '/':
        operador[j].funcao="div";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ";" << endl;
 //       j++;
        break;

        case 'B':
        operador[j].funcao="constc";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="\n";
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ";" << endl;
        j++;
        operador[j].funcao="copyc";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ";" << endl;
 //       j++;
        break;

    case 'E':
        operador[j].funcao="constd";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="\n";
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ";" << endl;
//        j++;
        break;

    case 'G':
        operador[j].funcao="constd";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="\n";
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ";" << endl;
//        j++;
        break;

    case '1':
        if(dorc==1)operador[j].funcao="constd";else operador[j].funcao="constc";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="\n";
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ";" << endl;
//        j++;
        break;

    case '2':
        if(dorc==1)operador[j].funcao="constd";else operador[j].funcao="constc";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="\n";
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ";" << endl;
        j++;
        if(dorc==1)operador[j].funcao="copyd";else operador[j].funcao="copyc";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ";" << endl;
 //       j++;
        break;

    case '3':
        if(dorc==1)operador[j].funcao="constd";else operador[j].funcao="constc";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="\n";
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ";" << endl;
        j++;
        v = op[i] - '0';
        while(v>1)
            {
                if(dorc==1)operador[j].funcao="copyd";else operador[j].funcao="copyc";
                operador[j].s1="s"+ indice(*inteiro, ind);
                *inteiro=*inteiro+1;
                operador[j].s2="s"+ indice(*inteiro, ind);
                *inteiro=*inteiro+1;
                operador[j].s3="s"+ indice(*inteiro, ind);
                *inteiro=*inteiro+1;
                operador[j].s4="\n";
                operador[j].s5="\n";
                operador[j].s6="\n";
                operador[j].s7="\n";
                operador[j].staop=0;
                operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ";" << endl;
        j++;v--;}
       break;

    case '4':
        if(dorc==1)operador[j].funcao="constd";else operador[j].funcao="constc";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="\n";
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

       //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;
         cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ";" << endl;
        j++;

        v = op[i] - '0';
        while(v>1)
            {
                if(dorc==1)operador[j].funcao="copyd";else operador[j].funcao="copyc";
                operador[j].s1="s"+ indice(*inteiro, ind);
                *inteiro=*inteiro+1;
                operador[j].s2="s"+ indice(*inteiro, ind);
                *inteiro=*inteiro+1;
                operador[j].s3="s"+ indice(*inteiro, ind);
                *inteiro=*inteiro+1;
                operador[j].s4="\n";
                operador[j].s5="\n";
                operador[j].s6="\n";
                operador[j].s7="\n";
                operador[j].staop=0;
                operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ";" << endl;
        j++;v--;}
      break;

    case '5':
        if(dorc==1)operador[j].funcao="constd";else operador[j].funcao="constc";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="\n";
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ";" << endl;
        j++;

        v = op[i] - '0';
        while(v>1)
            {
                if(dorc==1)operador[j].funcao="copyd";else operador[j].funcao="copyc";
                operador[j].s1="s"+ indice(*inteiro, ind);
                *inteiro=*inteiro+1;
                operador[j].s2="s"+ indice(*inteiro, ind);
                *inteiro=*inteiro+1;
                operador[j].s3="s"+ indice(*inteiro, ind);
                *inteiro=*inteiro+1;
                operador[j].s4="\n";
                operador[j].s5="\n";
                operador[j].s6="\n";
                operador[j].s7="\n";
                operador[j].staop=0;
                operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ";" << endl;
        j++;v--;}
      break;

    case '6':
        if(dorc==1)operador[j].funcao="constd";else operador[j].funcao="constc";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="\n";
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;
            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ";" << endl;
        j++;

        v = op[i] - '0';
        while(v>1)
            {
                if(dorc==1)operador[j].funcao="copyd";else operador[j].funcao="copyc";
                operador[j].s1="s"+ indice(*inteiro, ind);
                *inteiro=*inteiro+1;
                operador[j].s2="s"+ indice(*inteiro, ind);
                *inteiro=*inteiro+1;
                operador[j].s3="s"+ indice(*inteiro, ind);
                *inteiro=*inteiro+1;
                operador[j].s4="\n";
                operador[j].s5="\n";
                operador[j].s6="\n";
                operador[j].s7="\n";
                operador[j].staop=0;
                operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ";" << endl;
        j++;v--;}
       break;

     case '7':
        if(dorc==1)operador[j].funcao="constd";else operador[j].funcao="constc";
        operador[j].s1="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s2="s"+ indice(*inteiro, ind);
        *inteiro=*inteiro+1;
        operador[j].s3="\n";
        operador[j].s4="\n";
        operador[j].s5="\n";
        operador[j].s6="\n";
        operador[j].s7="\n";
        operador[j].staop=0;
        operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;
            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ";" << endl;
        j++;

        v = op[i] - '0';
        while(v>1)
            {
                if(dorc==1)operador[j].funcao="copyd";else operador[j].funcao="copyc";
                operador[j].s1="s"+ indice(*inteiro, ind);
                *inteiro=*inteiro+1;
                operador[j].s2="s"+ indice(*inteiro, ind);
                *inteiro=*inteiro+1;
                operador[j].s3="s"+ indice(*inteiro, ind);
                *inteiro=*inteiro+1;
                operador[j].s4="\n";
                operador[j].s5="\n";
                operador[j].s6="\n";
                operador[j].s7="\n";
                operador[j].staop=0;
                operador[j].stanes = 0;

    //v=(*j);
    cout << "Valor de J na entrada"; cout << j  << endl;

            cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ";" << endl;
        j++;v--;}

        break;

    default:
        cout << "Nenhuma instrucao" << endl;

//        return operador[j].funcao;

    }}
