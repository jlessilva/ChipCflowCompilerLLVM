#ifndef __IMPLFUNCS_H_
#define __IMPLFUNCS_H_
#include "varevertices.h"
#include <string>

using namespace std;


    typedef struct {
        char var1;
        char var2;
        string varz; //
        string tifs[10]; // vertice de referencia true DMERGE
        string fifs[10]; // vertice de referencia false DMERGE
        string ztifs[10]; // variavel z como referencia de saida true
        string zfifs[10]; // variavel z como referencia de saida false
        string ifctrl[10];
        int indxif;
        int indope;
        int indvar;
        int staif;
        int aninha;
        int ultimo;
        int matrix;
        int vetor;
   } refif;

       typedef struct {
        char var2;
        char var1;
        char var3;
        string outz; // VARIÁVEL Z,R,Q,...
        string cxfor; //CONTROLE DO FOR $
        string cxxfor; //CONTROLE DO FOR $
        string cxacc; //CONTROLE DO FOR $
        string tfs[10]; // vertice de referencia true DMERGE Z
        string ffs[10]; // vertice de referencia false DMERGE @
        string forctrl[10]; // VERTICE DE REFERENCIA #
        string ztfs[10]; // VARIÁVEIS DE SAÍDA DOS DEMERGES (Z,R,Q....)
        string ctrlf; // VERTICE DE REFERENCIA DO SINAL DE CONTROLE
        int indope;
        int indvar;
        int indxfor;
        int aninha;
        int ultimo;
        int stafor;
        int matrix;
        int vetor;
        int atriacc;//-----------------------------------------------------------------------26/4
   } reffor;

          typedef struct {
//        char var1;
//        char var2;
//        string varz;
//        string tfors;
//        string ffors;
//        string zfors;
        int idxelse;
   } refelse;

     typedef struct {
    string ope;
    string vref[10];
    string varz[10];
    int kx;
  } seqope;

      typedef struct {
     string refi;
     string refj;
     int stai;
     int staj;
     } defrefij;


   void iffunc( int ki, int kf, int ks, int ka, int ioif, refif *ifx, reffor *forx, seqope *sop, int indexsimb, char buffersimbol[], varepsta* varep, operacao *opvar, vertices *vert, asseline *operadores,defrefij *refiload, defrefij *refistore);

   void forfunc( int ki, int kf, int ks, int ka, int ioif, refif *ifx, reffor *forx, seqope *sop, int indexsimb, char buffersimbol[], varepsta* varep, operacao *opvar, vertices *vert, asseline *operadores,defrefij *refiload, defrefij *refistore);

    void geraopatrif( int ki, int ks, int torf, int ko, refif *ifx, seqope *sop, int indexsimb, char buffersimbol[], vertices *vert, operacao *opvar, asseline *operadores);

    void geraopatrifor( int ki, int ks, int torf, int ko, reffor *forx, seqope *sop, int indexsimb, char buffersimbol[], vertices *vert, operacao *opvar, asseline *operadores);

    void atrifuncif( int ki, int ks, int ko, refif *ifx,  seqope *sop, int indexsimb, char buffersimb[], vertices *vert, asseline *operadores);

    void pairopera(int ki, int kf, int ks, refif *ifx, reffor *forx, seqope *sop, string funcao,operacao *opvar, varepsta *varep, vertices *vert, asseline *operador, defrefij *refiload, defrefij *refistore);

    void atrifunc( int ki, int ks, int ka, refif *ifx,  seqope *sop, int indexsimb, char buffersimbol[],vertices *vert, operacao *opvar, asseline *operadores);

    void geraopatri(int ki, int ks, int torf, int ka, refif *ifx,  seqope *sop, int indexsimb, char buffersimbol[], vertices *vert, operacao *opvar, asseline *operadores);


#endif // IMPLFUNCS_H_INCLUDED
