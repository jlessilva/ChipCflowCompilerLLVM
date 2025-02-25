#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "geraopera.h"
#include "geraopvar.h"
#include "genalloperator.h"
#include "varevertices.h"
#include "implfuncs.h"
#include "pairopera.h"
#include "pairall.h"
#include "funcopera.h"
//#include "atribuicao.h"

// V0


string newindiceram(int g, char(&indr)[10]) {
    _itoa_s(g, indr, 10);
    //    _itoa(g, indr, 10);   // itoa() is a function of stdlib.h file that convert integer
        // int to array itoa( integer, targated array, base u want to
        //convert like decimal have 10
    return indr;
};


using namespace std;


int main()
{
char ch;
char fileName[80];
char buffer[255]=""; // for user input
char fileNamevhd[255]="";
char buffersimbol[200]="";
char ind[150]="";
//char varx[50];
int indexvarx=0;
int *inteiroi=0;
int counter=0;
int indopera=0;
int i;
asseline operadores[200];
operacao opvar[100];
defvarx varx[100];
string charsimb[100];
int setx[150]{};
string buffervhd[150];
string bufferindex[150];
maxvar defr[100];
varepsta varep[200];
vertices vert[2000];
int ki=0;
int kf=0;
int ks=0;
refif ifx[100];
reffor forx[100];
refelse elsex[100];
seqope sop[10];
defrefij refiload[3];
defrefij refistore[3];
int *inteiroram;
int umr=0;
inteiroram = &umr;
char indr[10]="";


cout << "File name: ";
cin >> fileName;

cout << "File name: ";
cin >> fileNamevhd;


ifstream fin(fileName); // reopen for reading


// GERA TABELA DE SIMBOLOS ////////////////////////////////////////////////////////////////////////

int indexsimb=0;
while (fin.get(ch)){
buffersimbol[indexsimb]=ch; cout << buffersimbol[indexsimb] << endl;
indexsimb=indexsimb+1;
}
buffersimbol[indexsimb]='\0';

// GERA A PARTIR DO BUFFER DE SIMBOLOS TODAS AS FUNCOES DO PROGRAMA C EM OPVAR, VARIAVEIS VARX E SUAS REPETICOES,
// E ASSOCIA AS FUNCOES E SUAS VARIAVIES VINCULADA EX: IF(X<Y) -> IFXY
// EM VARX ESTAO TODAS AS VARIVAIES E EM OPERA TODAS AS FUNCOES E AS VARIAVEIS VINCULADAS

indexsimb=0;
int indeaux=0;
while (buffersimbol[indexsimb]!='\0')
{
    if (buffersimbol[indexsimb]==' ' || buffersimbol[indexsimb]=='\n')
        {   indeaux=indexsimb;
            while (buffersimbol[indeaux]!='\0') {buffersimbol[indeaux]=buffersimbol[indeaux+1]; indeaux++;}
        }
    else indexsimb++;
}



    cout << "entrei na opvar" << endl;
    gopvar(buffersimbol,charsimb, varx,opvar);   //GERA OPVAR E VARX

// DEFINICAO DE UM BUFFER DE VARIAVEIS REPETIDAS PARA DEFINICAO DE QUANTOS COPYS GERAR X5,Y3. ETC


    cout << "entrei na defrep" << endl;

    defrep(varx); // FUNCAO QUE GERAR AS REPETICOES DE VARIAVEIS


// DEFINE UM REGISTRO COM O AS VARIAVEIS E SEU NUMERO DE REPETICOES DAS VARIAVEIS X3  defr[]->varxk[] e defr[].setxmax[] /////////////////////////////
// MAXVAR DEFINIDO EM GENALLOPERATOR.H


    cout << "entrei na defmax" << endl;
   defmax(varx,charsimb,defr);  // SO DEFINI PARA CADA VARIAVEL QUANTAS VEZES ELE APARECE X5, Y7, ETC

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout << "entrei na varep" << endl;

    gervarep(defr,varep);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CRIANDO OPERADORES A PARTIR DE DEFR E OPER
    // ASSELINE DEFINIDO EM GERAOPERA.H


    cout << "entrei na gera operadores" << endl;

    genallop(opvar,defr,operadores);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   // CRIANDO TABELA VERT QUE IRA CONTER OS SINAIS VERTICES GERADOS E UM CAMPO DA VARIÁVEL ATRIBUIDA A ESSE VERTICE
   // E DEFININDO STATUS DE CADA VERTICE COMO SENDO 0

     cout << "entrei na status vertices" << endl;

    statusvert(operadores,vert);



// A PARTIR DOS OPERADORES E SUAS VARIÁVEIS TODA A REPETICAO E UMA VARIAVEL É SETADA EM VERT
// PARA QUE EM UMA PROXIMA APARICAO DA MESMA REFERENCIA DE VARIAVEL SE PEGA O PROXIMO NA LISTA DE VERTICES
// FAZENDO JA UMA CORRESPONDENCIA ENTRE OS VERTICES E VARIAVEIS EX: X3,S10, X7,S44, ETC.

      cout << "entrei na alinha vertices" << endl;

      statusrep(operadores,defr,vert);


//SETAR 1 TODOS AQUELES VERTICES QUE JÁ TEM REFERENCIA DEFININDA ------------OK

/*BUSCAR EM OPERA UMA FUNÇÃO
VER A PRIMEIRA VARIAVEL ASSOCIADA
BUSCAR NA VERT A VARIAVEL ASSOCIADA ENCONTRADA
BUSCAR EM OEPRADORES O OPERADOR CORRESPONDENTE A FUNCAO
ALTERAR VERTICE DO OPERADOR PARA O ENCONTRADO DA VARIVAEL E SE OEPRADOR COMPLETO, SETAR 1 CAMPO STATUS OEPRADOR
REPETE O PROCESSO
*/

cout << "iniciando emparelhamento"  << endl;
/*i=0;
while (opvar[i].opera !="\n"){
    cout << opvar[i].opera;

    cout << opvar[i].x1;
    cout << opvar[i].x2;
    cout << opvar[i].x3 << endl;
    i++;
}*/


// EMPARELHA TODOS OS OPERAÇÕES QUE AINDA NÃO TIVERAM SEUS VERTICES EMPARELHADOS CONFORME DATAFLOW
// GERACAO FINAL ENTAO DO PROGRAMA VHDL GERADO A PARTIR DE PROGRAMA FONTE C


//   operacao*opvar;
//   vertices *vert;
//   asseline *operadores;


     pairall( ki, kf, ks, charsimb, ifx, forx, sop, elsex, buffersimbol, varep, opvar, vert, operadores, refiload, refistore);




   cout << "A C A B O U " << endl;

  int j=0;
  while (operadores[j].funcao != "\n")
    {
        if (operadores[j].funcao=="copyd")
        {
            buffervhd[j]=operadores[j].funcao + " " + operadores[j].s1 + "," + operadores[j].s2 + "," + operadores[j].s3 +";"+"\n";
        }
        if (operadores[j].funcao=="acc")
        {
            buffervhd[j]=operadores[j].funcao + " " + operadores[j].s1 + "," + operadores[j].s2 +";"+"\n";
        }
        if (operadores[j].funcao=="accm")
        {
            buffervhd[j]=operadores[j].funcao + " " + operadores[j].s1 + "," + operadores[j].s2 + "," + operadores[j].s3 +";"+"\n";
        }
        if (operadores[j].funcao=="constd")
        {
            buffervhd[j]=operadores[j].funcao + " " + operadores[j].s1 + "," + operadores[j].s2 +";"+"\n";
        }
        if (operadores[j].funcao=="constc")
        {
            buffervhd[j]=operadores[j].funcao + " " + operadores[j].s1 + "," + operadores[j].s2 +";"+"\n";
        }

        if (operadores[j].funcao=="decider")
        {
            buffervhd[j]=operadores[j].funcao + " " + operadores[j].s1 + "," + operadores[j].s2 + "," + operadores[j].s3 +";"+"\n";
        }
        if (operadores[j].funcao=="add")
        {
            buffervhd[j]=operadores[j].funcao + " " + operadores[j].s1 + "," + operadores[j].s2 + "," + operadores[j].s3 +";"+"\n";
        }
        if (operadores[j].funcao=="sub")
        {
            buffervhd[j]=operadores[j].funcao + " " + operadores[j].s1 + "," + operadores[j].s2 + "," + operadores[j].s3 +";"+"\n";
        }
        if (operadores[j].funcao=="mul")
        {
            buffervhd[j]=operadores[j].funcao + " " + operadores[j].s1 + "," + operadores[j].s2 + "," + operadores[j].s3 +";"+"\n";
        }
        if (operadores[j].funcao=="div")
        {
            buffervhd[j]=operadores[j].funcao + " " + operadores[j].s1 + "," + operadores[j].s2 + "," + operadores[j].s3 +";"+"\n";
        }
        if (operadores[j].funcao=="foricexx")
        {
            buffervhd[j]=operadores[j].funcao + " " + operadores[j].s1 + "," + operadores[j].s2 + "," + operadores[j].s3 + "," + operadores[j].s4 + "," + operadores[j].s5 + "," + operadores[j].s6 + ";"+"\n";
        }
        if (operadores[j].funcao=="dualload")
        {
            buffervhd[j]=operadores[j].funcao + " " + operadores[j].s1 + "," + operadores[j].s2 + "," + operadores[j].s3 + "," + operadores[j].s4 + "," + operadores[j].s5 + "," + operadores[j].s6 + "," + operadores[j].s7 + ";"+"\n";
        }
        if (operadores[j].funcao=="dualstore")
        {
            buffervhd[j]=operadores[j].funcao + " " + operadores[j].s1 + "," + operadores[j].s2 + "," + operadores[j].s3 + "," + operadores[j].s4 + "," + operadores[j].s5 + "," + operadores[j].s6 + "," + operadores[j].s7 + "," + operadores[j].s8 + ";"+"\n";
        }
        if (operadores[j].funcao=="dualsram")
        {
            buffervhd[j]=operadores[j].funcao+newindiceram(*inteiroram, indr) + " " + operadores[j].s1 + "," + operadores[j].s2 + "," + operadores[j].s3 + "," + operadores[j].s4 + "," + operadores[j].s5 + "," + operadores[j].s6 + ";"+"\n";*inteiroram=*inteiroram+1;
        }
        if (operadores[j].funcao=="dmerged")
        {
            buffervhd[j]=operadores[j].funcao + " " + operadores[j].s1 + "," + operadores[j].s2 + "," + operadores[j].s3 + "," + operadores[j].s4 + ";"+"\n";
        }
        if (operadores[j].funcao=="copyc")
        {
            buffervhd[j]=operadores[j].funcao + " " + operadores[j].s1 + "," + operadores[j].s2 + "," + operadores[j].s3 +";"+"\n";
        }
        cout << buffervhd[j] <<endl;
        j++;
     };












// AQUI SE INCERRA TODA A DECODIFICAÇÃO DO PROGRAMA CONVERTIDO.

//cout << "\n***End of file contents.***\n";
fin.close(); // always pays to be tidy

counter=0;
ofstream fout(fileNamevhd); // open for writing
//fout << "This line written directly to the file...\n";
//cout << "Enter text for the file: ";
//cin.ignore(1,'\n'); // eat the newline after the file name
//cin.getline(buffer,255); // get the user’s input

for(i=0;i<100;i++)
fout << buffervhd[i]; // and write it to the file
// eat the newline after the file name

fout.close(); // close the file, ready for reopen

return 0;
 }

