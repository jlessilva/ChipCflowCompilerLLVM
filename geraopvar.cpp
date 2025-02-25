#include "geraopvar.h"
#include "geraopera.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


string newindice(int k, char(&inds)[100]) {
    _itoa_s(k, inds, 10);
    //    _itoa(g, indr, 10);   // itoa() is a function of stdlib.h file that convert integer
        // int to array itoa( integer, targated array, base u want to
        //convert like decimal have 10
    return inds;
};


// GERA A PARTIR DO BUFFER DE SIMBOLOS TODAS AS FUNCOES DO PROGRAMA C EM OPVAR, VARIAVEIS VARX E SUAS REPETICOES,
// E ASSOCIA AS FUNCOES E SUAS VARIAVIES VINCULADA EX: IF(X<Y) -> IFXY
// EM VARX ESTAO TODAS AS VARIVAIES E EM OPERA TODAS AS FUNCOES E AS VARIAVEIS VINCULADAS

void gopvar(char buffersimbol[], string charsimb[], defvarx *varx, operacao *opvar)
{

    typedef struct
    {
        string simb;
        int sta;
    } charspecial;

    int *inteironew;
    int um=1;
    inteironew = &um;
    int *inteironewf;
    int umf=1;
    inteironewf = &umf;
    char ind[100]="";
    charspecial charsp[40];
    int opdifere=0;
    int indexsimb=0;
    char privar='\0';
    char secvar='\0';
    char nextc='\0';
    int indexsiaux=0;
    int countchave=0;
    int indexvarx=0;
    int indexsp=0;
    int auxindice=0;
    int expressaonum=1;
    int auxindopera=0;
    int refindsp=0;
    int refindpa=0;
    int charsi=0;
    int found=0;
    int tmul=1;
    int nosimb=1;
    int countsimb=0;
    int refsimb=0;//-----------------------28/4
    string varifor[50];//--------------15/4
    int ii=0;//-------------------------15/4
    int usei=0; //----------------------15/4
    string varaux1="";
    string varaux2="";
    string refopera="";
    string repn="";
    string refmat="";
    int qtdmat=0;
    int refopemat=0;
    int i;
    int ki=0; // QTD DE IF
    int kf=0; // QTD DE FOR
    int ke=0; // QTD DE ELSE
    int kr=0; // DIFERENÇA ENTRE IF E ELSE
//int indexvarx=0;
//operacao opvar[100];
    int indevari=0;
    int indopera=0;
    int indsimb=0;
    int basicop=0;
    int opmat=0;
    charsimb[indsimb]="\n";
    string varequa="";
    string varequax="";//-------------------------------------------------------------26/4
    int p=0;

    for (p = 0; p < 100; p++) {// alterado em 18/06/24
        opvar[p].xx = 0;
        opvar[p].yy = 0;
        opvar[p].matrix = 0;
        opvar[p].staat = 0;
        opvar[p].staop = 0;
        opvar[p].stx2 = 0;
        opvar[p].stx3 = 0;
        opvar[p].vetor = 0;
    };
    p = 0;

    for (p = 0; p < 100; p++) {// alterado em 18/06/24
        varx[p].ctrl = 0;
        varx[p].setxy = 0;
        varx[p].staxy = 0;
    };
    p = 0;


    while(buffersimbol[indexsimb] != '\0')//-------------------------------------------30/4
    {
        while(buffersimbol[indexsimb]!='[' && buffersimbol[indexsimb]!='\0')indexsimb++;
        if(buffersimbol[indexsimb]=='[' && buffersimbol[indexsimb+7]=='0')
        {
            refsimb=indexsimb-2;
            indexsimb=indexsimb+9;
            while(buffersimbol[refsimb]!='\0')
            {
                if(buffersimbol[indexsimb]=='}')indexsimb++;
                buffersimbol[refsimb]=buffersimbol[indexsimb];
                refsimb++;indexsimb++;
            }
        }
        indexsimb=0;
        while(buffersimbol[indexsimb]!='\0')
            {
                cout << indexsimb; cout << buffersimbol[indexsimb] << endl;
                indexsimb++;
            }



        indexsimb=0;
        found=1;
        while(found)
        {
            if(buffersimbol[indexsimb]==']' && buffersimbol[indexsimb+1]=='+' && buffersimbol[indexsimb+2]=='=' && buffersimbol[indexsimb]!='\0')found=0;
            else    {
                    if(buffersimbol[indexsimb]=='\0')found=0;
                    else
                    {   cout << buffersimbol[indexsimb]; cout << buffersimbol[indexsimb+1] << endl;
                        indexsimb++;
                    }
                    }
        }
        if(buffersimbol[indexsimb]==']' && buffersimbol[indexsimb+1]=='+')
        {
            refsimb=indexsimb+1;
            cout << refsimb << endl;
            indexsimb=indexsimb+2;
            while(buffersimbol[refsimb]!='\0')
            {
                buffersimbol[refsimb]=buffersimbol[indexsimb];
                refsimb++;indexsimb++;
            }
            opvar[indopera].opera="accm"; //---------------------------------------------------7/7
            opvar[indopera].x1="m";  // indica que o operador acc é para matrizes
            indopera++;
        }
        indexsimb=0;
        while(buffersimbol[indexsimb]!='\0')
            {
                cout << indexsimb; cout << buffersimbol[indexsimb] << endl;
                indexsimb++;
            }


    } //----------------------------------------------------------------------------------30/4


//        indexsimb=0;//----------------------------------------------------------------------------6/5
//        found=1;
//        while(found)
//        {
//            if(buffersimbol[indexsimb]=='0' && buffersimbol[indexsimb-1]=='=' && buffersimbol[indexsimb]!='\0')found=0;
//            else    {
//                    if(buffersimbol[indexsimb]=='\0')found=0;
//                    else
//                    {   cout << buffersimbol[indexsimb]; cout << buffersimbol[indexsimb+1] << endl;
//                        indexsimb++;
//                    }
//                    }
//        }
//        if(buffersimbol[indexsimb]!='\0')
//        {
//            refsimb=indexsimb-2;
//            cout << refsimb << endl;
//            indexsimb=indexsimb+2;
//            while(buffersimbol[refsimb]!='\0')
//            {
//                buffersimbol[refsimb]=buffersimbol[indexsimb];
//                refsimb++;indexsimb++;
//            }
//        }
//
//        indexsimb=0;
//        while(buffersimbol[indexsimb]!='\0')
//            {
//                cout << indexsimb; cout << buffersimbol[indexsimb] << endl;
//                indexsimb++;
//            }


        //------------------------------------------------------------------------------------------------6/5


    indexsimb=0;


    while (buffersimbol[indexsimb] != '\0')
    {
        if ((buffersimbol[indexsimb] != '<') &&
                (buffersimbol[indexsimb] != '(') &&
                (buffersimbol[indexsimb] != ')') &&
                (buffersimbol[indexsimb] != '[') &&
                (buffersimbol[indexsimb] != ']') &&
                (buffersimbol[indexsimb] != ' ') &&
                (buffersimbol[indexsimb] != '<') &&
                //(buffersimbol[indexsimb] != '+') &&//------------------------------------------------19/5
                (buffersimbol[indexsimb] != ';') &&
                (buffersimbol[indexsimb] != '*') &&
                (buffersimbol[indexsimb] != '-') &&
                (buffersimbol[indexsimb] != '/') &&
                (buffersimbol[indexsimb] != '!') &&
                (buffersimbol[indexsimb] != '\n'))
        {
            if (buffersimbol[indexsimb] == 'i')
            {
                indexsimb++;
                if (buffersimbol[indexsimb] == 'f')
                {
                    indexsimb++;
                    indexsimb++;
                    opvar[indopera].x1=buffersimbol[indexsimb];
                    cout << opvar[indopera].x1 << endl;
                    varx[indexvarx].varxy=buffersimbol[indexsimb];
                    cout << varx[indexvarx].varxy;
                    cout << indexvarx << endl;
                    indexvarx++;
                    indexsimb++;
                    indexsimb++;
                    opvar[indopera].x2=buffersimbol[indexsimb];
                    cout << opvar[indopera].x2<< endl;
                    varx[indexvarx].varxy=buffersimbol[indexsimb];
                    cout << varx[indexvarx].varxy;
                    cout <<  indexvarx << endl;
                    indexvarx++;
                    opvar[indopera].x3='\0';
                    opvar[indopera].opera="if";
                    ki++;
                    indexsiaux=indexsimb+2;
                    if(buffersimbol[indexsimb]==' ')
                        while(buffersimbol[indexsimb]== ' ')indexsimb++;
                    countchave=0;
                    if(buffersimbol[indexsiaux]=='{')
                    {
                        while(buffersimbol[indexsiaux]!='}')
                        {
                            indexsiaux++;
                            while(buffersimbol[indexsiaux]!=';')
                            {
                                if(buffersimbol[indexsiaux]=='{')
                                    while(buffersimbol[indexsiaux]!='}') indexsiaux++;
                                indexsiaux++;
                            }
                            countchave++;
                            indexsiaux++;
                        }
                    }
                    if(countchave!=0)
                    {
                        if(countchave>1)opvar[indopera].xx=countchave;
                        else opvar[indopera].xx=0;
                    }
                    else opvar[indopera].xx=0;
                    cout << opvar[indopera].xx << endl;
                    if(nextc=='i')opvar[indopera-1].xx=countchave;
                    auxindopera=indopera;
                    indopera++;
                    indexsimb++;
                    indexsimb++;
                    privar=buffersimbol[indexsimb];
                    indexsimb--;
                    if(buffersimbol[indexsimb+1]=='f' && buffersimbol[indexsimb+2]=='o' && buffersimbol[indexsimb+3=='r'])nextc='f';
                }
                else
                {
                    indexsimb--;
                    varx[indexvarx].varxy=buffersimbol[indexsimb];
                    cout << varx[indexvarx].varxy;
                    cout << indexvarx << endl;
                    indexvarx++;
                }
            }
            else if (buffersimbol[indexsimb] == 'f')
            {
                indexsimb++;
                if (buffersimbol[indexsimb] == 'o')
                {
                    indexsimb++;
                    indexsimb++;
                    indexsimb++;
                    //opvar[indopera].xx=buffersimbol[indexsimb];cout << opvar[indopera].xx << endl;
                    privar=buffersimbol[indexsimb]; //PARA GUARDAR O I INICIAL
                    cout << privar << endl;
                    opvar[indopera].x1=buffersimbol[indexsimb]+newindice(*inteironewf, ind);
                    cout << opvar[indopera].x1 << endl;
                    varx[indexvarx].varxy=buffersimbol[indexsimb]+newindice(*inteironewf, ind);
                    cout << varx[indexvarx].varxy;
                    cout << indexvarx << endl;
                    indexvarx++;
                    indexsimb++;
                    indexsimb++;
//                            opvar[indopera].x2=buffersimbol[indexsimb];cout << opvar[indopera].x2 << endl;
//                            varx[indexvarx].varxy=buffersimbol[indexsimb];cout << varx[indexvarx].varxy;  cout << indexvarx << endl;
//                            indexvarx++;
                    indexsimb++;
                    indexsimb++;
                    indexsimb++;
                    indexsimb++;
                    opvar[indopera].x2=buffersimbol[indexsimb]+newindice(*inteironewf, ind);
                    cout << opvar[indopera].x2 << endl;
                    varx[indexvarx].varxy=buffersimbol[indexsimb]+newindice(*inteironewf, ind);
                    cout << varx[indexvarx].varxy;
                    cout << indexvarx << endl;
                    repn=varx[indexvarx].varxy;
                    indexvarx++;
                    indexsimb++;
                    indexsimb++;
                    indexsimb++;
                    indexsimb++;
                    indexsimb++;
                    opvar[indopera].x3=privar;
                    indexvarx++;
                    varx[indexvarx].varxy=privar;
                    cout << varx[indexvarx].varxy;
                    cout << indexvarx << endl;
                    varifor[ii]=privar;  //---------------15/4
                    cout << varifor[ii] << endl;
                    ii++;
                    varifor[ii]="\n"; //------------------15/4
//                            varx[indexvarx].varxy=buffersimbol[indexsimb];cout << varx[indexvarx].varxy;  cout << indexvarx << endl;
//                            indexvarx++;
//                            opvar[indopera].x3='i';
//                            varx[indexvarx].varxy='i';cout << varx[indexvarx].varxy;  cout << indexvarx << endl;
                    opvar[indopera].opera="for";
                    kf++;
                    indexsiaux=indexsimb+1;
                    if(buffersimbol[indexsimb]==' ')
                        while(buffersimbol[indexsimb]== ' ')indexsimb++;
                    countchave=0;
                    if(buffersimbol[indexsiaux]!='{') opvar[indopera].xx=0;
                    else
                    {
                        if(buffersimbol[indexsiaux]=='{')
                        {
                            while(buffersimbol[indexsiaux]!='}')
                            {
                                indexsiaux++;
                                while(buffersimbol[indexsiaux]!=';')
                                {
                                    if(buffersimbol[indexsiaux]=='{')
                                        while(buffersimbol[indexsiaux]!='}') indexsiaux++;
                                    indexsiaux++;
                                }
                                countchave++;
                                indexsiaux++;
                                if(buffersimbol[indexsiaux-2]=='}')indexsiaux=indexsiaux-2;
                            }
                        }
                    }
                    if(countchave!=0)
                    {
                        if(countchave>1)opvar[indopera].xx=countchave;
                        else opvar[indopera].xx=0;
                    }
                    else opvar[indopera].xx=0;
                    cout << opvar[indopera].xx << endl;
                    if(nextc=='f')opvar[indopera-1].xx=countchave;
                    auxindopera=indopera;
                    indopera++;
                    indexsimb++;
                    indexsimb++;
                    if(buffersimbol[indexsimb]!='o' && buffersimbol[indexsimb]!='f')
                    {
                        privar=buffersimbol[indexsimb];
                        indexsimb--;
                    }
                    else
                    {
                        indexsimb--;
                        indexsimb--;
                    }
                    if(buffersimbol[indexsimb+1]=='i' && buffersimbol[indexsimb+2]=='f')nextc='i';
                    cout << "countchave" ;
                    cout << opvar[indopera].xx << endl;
                    cout << "privar" ;
                    cout << privar << endl;
                }
                else
                {
                    indexsimb--;
                    varx[indexvarx].varxy=buffersimbol[indexsimb];
                    cout << varx[indexvarx].varxy;
                    cout << indexvarx << endl;
                    indexvarx++;
                }
            }
            else if (buffersimbol[indexsimb] == '=')
            {
                indexsimb++;
                if (buffersimbol[indexsimb] != '=' && buffersimbol[indexsimb] != '0')
                {
                    indexsp=0;
                    indexsimb--;
                    indexsimb--;
                    cout << buffersimbol[indexsimb] << endl;
                    if(buffersimbol[indexsimb-2]=='[' && buffersimbol[indexsimb]==']' && buffersimbol[indexsimb-5]=='[' && buffersimbol[indexsimb-3]==']' )
                    {
                        indexsimb=indexsimb-6;
                        indexvarx=indexvarx-2;
                        varx[indexvarx].varxy=buffersimbol[indexsimb];
                        cout << varx[indexvarx].varxy;
                        cout << indexvarx << endl;
                        refmat=varx[indexvarx].varxy;
                        indexsimb=indexsimb+2;
                        indexvarx++;
                        varx[indexvarx].varxy=buffersimbol[indexsimb];
                        cout << varx[indexvarx].varxy;
                        opvar[indopera].x2=varx[indexvarx].varxy;//-------------------3/5
                        opvar[indopera].stx2=0;//-------------------------------------3/5
                        cout << indexvarx << endl;
                        indexsimb=indexsimb+3;
                        indexvarx++;
                        varx[indexvarx].varxy=buffersimbol[indexsimb];
                        cout << varx[indexvarx].varxy;
                        opvar[indopera].x3=varx[indexvarx].varxy;//--------------------3/5
                        opvar[indopera].stx3=0;//-------------------------------------3/5
                        cout << indexvarx << endl;
                        indexsimb++;
                        opvar[indopera].opera="dualstore";
                        opvar[indopera].x1=refmat;
                        cout << opvar[indopera].opera;
                        cout << opvar[indopera].x1 << endl;
                        indopera++;
                        opmat=1;

                        opvar[indopera].opera="dualsram";
                        indopera++;
                        if(opvar[indopera-3].opera=="for" || opvar[indopera-3].opera=="if")opvar[indopera-3].matrix=1;
                        else indexvarx--;
                        varequa=buffersimbol[indexsimb];
                        cout << varequa << endl;
//                                          opvar[indopera].x1=buffersimbol[indexsimb];cout << opvar[indopera].x1 << endl;
//                                          varx[indexvarx].varxy=buffersimbol[indexsimb];cout << varx[indexvarx].varxy;  cout << indexvarx << endl;
//                                          varx[indexvarx].staxy=1;
//                                          indexvarx++;
                        indexsimb++;
                        indexsimb++;
                        indexvarx++;
                        cout << buffersimbol[indexsimb] << endl;
                        if(buffersimbol[indexsimb+1]=='[' && buffersimbol[indexsimb+3]==']')
                        {
                            while(buffersimbol[indexsimb]!= '\0')
                            {
                                if(buffersimbol[indexsimb+1]=='[' && buffersimbol[indexsimb+3]==']')
                                {
                                    varx[indexvarx].varxy=buffersimbol[indexsimb];
                                    cout << varx[indexvarx].varxy;
                                    cout << indexvarx << endl;
                                    refmat=varx[indexvarx].varxy;
                                    indexsimb=indexsimb+2;
                                    indexvarx++;
                                    varx[indexvarx].varxy=buffersimbol[indexsimb];
                                    cout << varx[indexvarx].varxy;
                                    opvar[indopera].x2=varx[indexvarx].varxy;//-------------------3/5
                                    opvar[indopera].stx2=0;//-------------------------------------3/5
                                    cout << indexvarx << endl;
                                    indexsimb=indexsimb+3;
                                    indexvarx++;
                                    varx[indexvarx].varxy=buffersimbol[indexsimb];
                                    cout << varx[indexvarx].varxy;
                                    opvar[indopera].x3=varx[indexvarx].varxy;//-------------------3/5
                                    opvar[indopera].stx3=0;//-------------------------------------3/5
                                    cout << indexvarx << endl;
                                    indexsimb++;
                                    indexvarx++;
                                    opvar[indopera].opera="dualload";
                                    opvar[indopera].x1=refmat;
                                    cout << opvar[indopera].opera;
                                    cout << opvar[indopera].x1 << endl;
                                    indopera++;

                                    opvar[indopera].opera="dualsram";
                                    indopera++;
                                    //if(opvar[indopera-3].opera=="for" || opvar[indopera-3].opera=="if")opvar[indopera-3].matrix=1;

                                    indexsimb++;
                                    if(buffersimbol[indexsimb]==';')indexvarx--;

                                    refsimb=0;
                                    while(buffersimbol[refsimb]|='\0')
                                    {
                                        cout << refsimb; cout <<  buffersimbol[refsimb] << endl;
                                        refsimb++;
                                    }


                                    if(qtdmat!=0) opvar[refopemat].x2=refmat;
                                    cout << opvar[refopemat].x2 << endl;
                                    cout << buffersimbol[indexsimb] << endl;
                                    cout << indexsimb << endl;

                                    if (buffersimbol[indexsimb] == '+')
                                    {
                                        opvar[indopera].opera="add";
                                        opvar[indopera].matrix=1;
                                        refopemat=indopera;
                                        opvar[indopera].x1=refmat;
                                        cout << opvar[indopera].x1 << endl;
                                        indopera++;
                                    }
                                    else if (buffersimbol[indexsimb] == '-')
                                    {
                                        opvar[indopera].opera="sub";
                                        opvar[indopera].matrix=1;
                                        refopemat=indopera;
                                        opvar[indopera].x1=refmat;
                                        cout << opvar[indopera].x1 << endl;
                                        indopera++;
                                    }
                                    else if (buffersimbol[indexsimb] == '*')
                                    {
                                        opvar[indopera].opera="mul";
                                        opvar[indopera].matrix=1;
                                        refopemat=indopera;
                                        opvar[indopera].x1=refmat;
                                        cout << opvar[indopera].x1 << endl;
                                        indopera++;
                                    }
                                    else if (buffersimbol[indexsimb] == '/')
                                    {
                                        opvar[indopera].opera="div";
                                        opvar[indopera].matrix=1;
                                        refopemat=indopera;
                                        opvar[indopera].x1=refmat;
                                        cout << opvar[indopera].x1 << endl;
                                        indopera++;
                                    }

                                    qtdmat++;
                                    indexsimb++;

                                    //if (buffersimbol[indexsimb] == '+' ||buffersimbol[indexsimb] == '-' ||buffersimbol[indexsimb] == '*'||buffersimbol[indexsimb] == '/')
                                    //{
                                    //   basicop=1; indexsimb++;
                                    //   //indopera++;
                                    //}
                                }
                                else indexsimb++;
                            }
                        }
                    }
                    else
                    {
                        if(buffersimbol[indexsimb-2]=='[' && buffersimbol[indexsimb]==']')
                        {
                            indexsimb=indexsimb-3;
                            indexvarx=indexvarx-2;
                            varx[indexvarx].varxy=buffersimbol[indexsimb];
                            cout << varx[indexvarx].varxy;
                            cout << indexvarx << endl;
                            refmat=varx[indexvarx].varxy;
                            indexsimb=indexsimb+2;
                            indexvarx++;
                            varx[indexvarx].varxy=buffersimbol[indexsimb];
                            cout << varx[indexvarx].varxy;
                            cout << indexvarx << endl;
                            opvar[indopera].x2=varx[indexvarx].varxy;//-------------------3/5
                            opvar[indopera].stx2=0;//-------------------------------------3/5
                            indexsimb++;

                            opvar[indopera].opera="dualstore";
                            opvar[indopera].x1=refmat;
                            cout << opvar[indopera].opera;
                            cout << opvar[indopera].x1 << endl;
                            indopera++;
                            opmat=1;

                            opvar[indopera].opera="dualsram";
                            indopera++;
                            if(opvar[indopera-3].opera=="for" || opvar[indopera-3].opera=="if")opvar[indopera-3].vetor=1;
                        }
                        else
                            {   indexvarx--; //-----------------------------------------------------------27/4
                                if(buffersimbol[indexsimb]=='+')
                                    {   refsimb=indexsimb;
                                        opvar[indopera].opera="acc";
                                        opvar[indopera].x1=buffersimbol[indexsimb-1];//-----------------28/4
                                        secvar=buffersimbol[indexsimb-1];
                                        indopera++;
                                        indexsiaux=indexsimb;
                                        privar=buffersimbol[indexsimb];
                                        cout << privar << endl;
                                        buffersimbol[indexsimb]=buffersimbol[indexsimb+1];
                                        indexsimb++;
                                        if(buffersimbol[indexsimb+2]!=';' && buffersimbol[indexsimb+2]!='[')
                                        {   buffersimbol[indexsimb]='{';
                                            while(buffersimbol[indexsimb]!=';')indexsimb++;
                                            buffersimbol[indexsimb]='}'; indexsimb++;
                                            buffersimbol[indexsimb]='+';indexsimb++;
                                            buffersimbol[indexsimb]=secvar;indexsimb++;
                                            buffersimbol[indexsimb]=';';
                                        } else {
                                                indexsimb--;
                                                while(buffersimbol[indexsimb]!=';')
                                                {
                                                    buffersimbol[indexsimb]=buffersimbol[indexsimb+1];
                                                    cout << buffersimbol[indexsimb] << endl;
                                                    indexsimb++;
                                                }
                                                indexsimb--;
                                                buffersimbol[indexsimb]=privar;
                                                indexsimb++;
                                                buffersimbol[indexsimb]=secvar;
                                                indexsimb++;
                                                buffersimbol[indexsimb]=';';
                                                }
                                        indexsimb++;
                                        buffersimbol[indexsimb]='\0';
                                        //indexsiaux=indexsimb;
                                        //while(buffersimbol[indexsimb]!=';')indexsimb++;
                                        //indexsimb++;
                                        //indexsimb++;buffersimbol[indexsimb]='\0';indexsimb--;
                                        //buffersimbol[indexsimb]=';';
                                        //cout << buffersimbol[indexsimb] << endl;
                                        //indexsimb--;
                                        //buffersimbol[indexsimb]=secvar;
                                        //cout << buffersimbol[indexsimb] << endl;
                                        //indexsimb--;
                                        //buffersimbol[indexsimb]=privar;indexsimb--;
                                        //while(indexsiaux!=indexsimb)
                                        //    {
                                        //        cout << buffersimbol[indexsimb] << endl;
                                        //        buffersimbol[indexsimb-1]=buffersimbol[indexsimb];
                                        //        cout << buffersimbol[indexsimb] << endl;
                                        //        indexsimb--;
                                        //    }
                                        //buffersimbol[indexsiaux]=secvar;

                                        indexsiaux=0;
                                        while(buffersimbol[indexsiaux]!='\0')
                                        { cout << indexsiaux;
                                          cout << buffersimbol[indexsiaux] << endl;
                                          indexsiaux++;
                                        }


                                        //indexsimb; //-----------------------------------------------28/4
                                        //indexsimb--;//------------------------------------------------27/4
                                        indexsimb=refsimb-1;//------------------------------------------28/4

                                    }
                            }
                        varequa=buffersimbol[indexsimb];
                        cout << buffersimbol[indexsimb] << endl;
                        //if(varequax==varequa){opvar[indopera].opera="acc";opvar[indopera].x1=varequa;indopera++;}//-----26/4--27/4
                        if(varequa!="]") varx[indexvarx].varxy=varequa;//-----------------------------------------------8/4
                        //if(varequa==varequax)indexvarx--; //-----------------------------------------------------------26/4---27/4
                        cout << varequa << endl;
                        cout <<varx[indexvarx].varxy << endl;

//                                              opvar[indopera].x1=buffersimbol[indexsimb];cout << opvar[indopera].x1 << endl;
//                                              varx[indexvarx].varxy=buffersimbol[indexsimb];cout << varx[indexvarx].varxy;  cout << indexvarx << endl;
//                                              varx[indexvarx].staxy=1;
//                                              indexvarx++;
                        indexsimb++;
                        indexsimb++;
                        indexvarx++;
                        cout << buffersimbol[indexsimb] << endl;
                        if(buffersimbol[indexsimb+1]=='[' && buffersimbol[indexsimb+3]==']')
                        {
                            while(buffersimbol[indexsimb]!= '\0')
                            {
                                if(buffersimbol[indexsimb+1]=='[' && buffersimbol[indexsimb+3]==']')
                                {
                                    varx[indexvarx].varxy=buffersimbol[indexsimb];
                                    cout << varx[indexvarx].varxy;
                                    cout << indexvarx << endl;
                                    refmat=varx[indexvarx].varxy;
                                    indexsimb=indexsimb+2;
                                    indexvarx++;
                                    varx[indexvarx].varxy=buffersimbol[indexsimb];
                                    cout << varx[indexvarx].varxy;
                                    cout << indexvarx << endl;
                                    opvar[indopera].x2=varx[indexvarx].varxy;//-------------------3/5
                                    opvar[indopera].stx2=0;//-------------------------------------3/5
                                    indexsimb++;
                                    indexvarx++;
                                    opvar[indopera].opera="dualload";
                                    opvar[indopera].x1=refmat;
                                    cout << opvar[indopera].opera;
                                    cout << opvar[indopera].x1 << endl;
                                    indopera++;
                                    opmat=1;


                                    opvar[indopera].opera="dualsram";
                                    indopera++;
                                    if(opvar[indopera-3].opera=="for" || opvar[indopera-3].opera=="if")opvar[indopera-3].vetor=1;
                                    if(opvar[indopera-4].opera=="for" || opvar[indopera-4].opera=="if")opvar[indopera-4].vetor=1;//--------------------------19/5

                                    indexsimb++;
                                    if(buffersimbol[indexsimb]==';')indexvarx--;

                                    if(qtdmat!=0) opvar[refopemat].x2=refmat;
                                    cout << opvar[refopemat].x2 << endl;

                                    if (buffersimbol[indexsimb] == '+')
                                    {
                                        opvar[indopera].opera="add";
                                        opvar[indopera].vetor=1;
                                        refopemat=indopera;
                                        opvar[indopera].x1=refmat;
                                        cout << opvar[indopera].x1 << endl;
                                        indopera++;
                                    }
                                    else if (buffersimbol[indexsimb] == '-')
                                    {
                                        opvar[indopera].opera="sub";
                                        opvar[indopera].vetor=1;
                                        refopemat=indopera;
                                        opvar[indopera].x1=refmat;
                                        cout << opvar[indopera].x1 << endl;
                                        indopera++;
                                    }
                                    else if (buffersimbol[indexsimb] == '*')
                                    {
                                        opvar[indopera].opera="mul";
                                        opvar[indopera].vetor=1;
                                        refopemat=indopera;
                                        opvar[indopera].x1=refmat;
                                        cout << opvar[indopera].x1 << endl;
                                        indopera++;
                                    }
                                    else if (buffersimbol[indexsimb] == '/')
                                    {
                                        opvar[indopera].opera="div";
                                        opvar[indopera].vetor=1;
                                        refopemat=indopera;
                                        opvar[indopera].x1=refmat;
                                        cout << opvar[indopera].x1 << endl;
                                        indopera++;
                                    }

                                    qtdmat++;
                                    indexsimb++;

                                    //if (buffersimbol[indexsimb] == '+' ||buffersimbol[indexsimb] == '-' ||buffersimbol[indexsimb] == '*'||buffersimbol[indexsimb] == '/')
                                    //{
                                    //   basicop=1; indexsimb++;
                                    //   //indopera++;
                                    //}
                                }
                                else indexsimb++;
                            }
                        }
                    }
                    if(opmat==0)
                    {
                        auxindice=indexsimb;
                        expressaonum=1;
                        while(expressaonum)
                        {
                            //while(buffersimbol[indexsimb]!= ';')  // GERANDO CHARSP TODOS STATUS 0 EXCETO * E / QUE E 1
                            indexsp=0;
                            int refisimb=indexsimb;  //-----------------------------------------------15/4
                            ii=0;
                            while(buffersimbol[indexsimb]!= ';')
                            {
                                cout << indexsimb; cout << buffersimbol[indexsimb] << endl;
                                charsp[indexsp].simb=buffersimbol[indexsimb];
                                if (charsp[indexsp].simb=="*" || charsp[indexsp].simb=="/")
                                    charsp[indexsp].sta=2;
                                else  if (charsp[indexsp].simb=="+" || charsp[indexsp].simb=="-") charsp[indexsp].sta=1;
                                else if (charsp[indexsp].simb=="(" || charsp[indexsp].simb=="[" || charsp[indexsp].simb=="{")
                                {
                                    refindpa++;
                                    charsp[indexsp].sta=0;
                                }
                                else charsp[indexsp].sta=0;
                                cout << charsp[indexsp].simb;
                                cout << charsp[indexsp].sta << endl;
                                cout << varifor[ii] << endl;
                                //while(varifor[ii]!=buffersimbol[refisimb] && buffersimbol[refisimb]!="\n")refisimb++;//------15/4
                                //while(varifor[ii]!=charsp[indexsp].simb && varifor[ii]!="\n")ii++;//------15/4
                                //if (buffersimbol[refisimb]!="\n"){usei=1;ii=0;}   //---------------------------------------15/4
                                indexsp++;
                                indexsimb++;
                            }
                            charsp[indexsp].simb="\n";
                            indexsimb=auxindice;
                            indexsp=1;
                            int comutaux=0;
                            int comuta=2;
                            int pontref=0;
                            int indexop=0;
                            int indexelem=0;
                            int r=0;
                            while(expressaonum)  // COMPRESSAO DOS OPERADORES PRIORITARIOS INCLUINDO PX INDICE
                            {
                                while (charsp[indexsp].simb!="\n")
                                {
                                    r=0;
                                    nosimb=1;
                                    countsimb=0;
                                    while(charsp[r].simb!="\n")
                                    {if(charsp[r].simb=="{" || charsp[r].simb=="[" || charsp[r].simb=="(" || charsp[r].simb=="}" && charsp[r].simb=="]" && charsp[r].simb==")")
                                        countsimb++;
                                        r++;
                                    }
                                    if (countsimb!=0)nosimb=1;else nosimb=0;

                                    //indexsp=pontref;
                                    indexop=0;
                                    indexelem=0;
                                    while(charsp[indexelem].simb!="\n")
                                    {
                                        if(charsp[indexelem].sta==1 || charsp[indexelem].sta==2)indexop++;
                                        indexelem++;
                                    }
                                    while (charsp[indexsp].sta!=comuta && charsp[indexsp].simb!="\n")
                                    {
                                        indexsp++;
                                    }
                                    indexelem=0;
                                    pontref=indexsp;
                                    if (charsp[indexsp].simb!="\n")
                                    {
                                        r=0;
                                        while(charsp[r].simb!="\n") {cout << r; cout << charsp[r].simb << endl;r++;}

                                        if(indexsp==3 && nosimb==0 && comuta!=2)indexsp=0; else indexsp--;
                                        cout <<charsp[indexsp].simb << endl;
                                        if(charsp[indexsp].simb!="{" && charsp[indexsp].simb!="[" && charsp[indexsp].simb!="(" && charsp[indexsp].simb!="}" && charsp[indexsp].simb!="]" && charsp[indexsp].simb!=")")
                                        {
                                            varaux1=charsp[indexsp].simb;
                                            indexsp++;
                                            refopera=charsp[indexsp].simb;
                                            indexsp++;
                                            if(charsp[indexsp].simb!="{" && charsp[indexsp].simb!="[" && charsp[indexsp].simb!="(" && charsp[indexsp].simb!="}" && charsp[indexsp].simb!="]" && charsp[indexsp].simb!=")")
                                            {
                                                varaux2=charsp[indexsp].simb;
                                                indexsp--;
                                                indexsp--;
                                                refindsp=indexsp; // para alinhar o resto da expressao
                                                indexsp++;
                                                while (charsp[indexsp].simb!="\n")
                                                {
                                                    cout << charsp[indexsp].simb << endl;
                                                    charsp[indexsp].simb=charsp[indexsp+2].simb;
                                                    cout << charsp[indexsp].simb << endl;
                                                    charsp[indexsp].sta=charsp[indexsp+2].sta;
                                                    indexsp++;
                                                }
                                                charsp[refindsp].simb="p"+newindice(*inteironew, ind);
                                                charsp[refindsp].sta=0;
                                                *inteironew=*inteironew+1;
                                                charsimb[indsimb]=charsp[refindsp].simb;
                                                indsimb++;
                                                charsimb[indexsimb]="\n";
//                                                                      opvar[indopera].x1=charsp[refindsp].simb;cout << opvar[indopera].x1 << endl;
//                                                                      varx[indexvarx].varxy=charsp[refindsp].simb;cout << varx[indexvarx].varxy;  cout << indexvarx << endl;
//                                                                      varx[indexvarx].staxy=1;
//                                                                      indexvarx++;
                                                if (refindpa!=0)
                                                    if(charsp[refindsp-1].simb=="(" && charsp[refindsp+1].simb==")")
                                                    {
                                                        refindpa--;
                                                        indexsp=refindsp-1;
                                                        while (charsp[indexsp].simb!="\n")
                                                        {
                                                            cout << charsp[indexsp].simb << endl;
                                                            charsp[indexsp].simb=charsp[indexsp+1].simb;
                                                            cout << charsp[indexsp].simb << endl;
                                                            charsp[indexsp].sta=charsp[indexsp+1].sta;
                                                            indexsp++;
                                                        }
                                                        //refindpa=refindsp;
                                                        indexsp=refindsp;
                                                        //refindpa;
                                                        while (charsp[indexsp].simb!="\n")
                                                        {
                                                            cout << charsp[indexsp].simb << endl;
                                                            charsp[indexsp].simb=charsp[indexsp+1].simb;
                                                            cout << charsp[indexsp].simb << endl;
                                                            charsp[indexsp].sta=charsp[indexsp+1].sta;
                                                            indexsp++;
                                                        }
                                                        indexsp=refindsp;
                                                        refindsp--;

                                                    }
                                                    else if(charsp[refindsp-1].simb=="[" && charsp[refindsp+1].simb=="]")
                                                    {
                                                        refindpa--;
                                                        indexsp=refindsp-1;
                                                        while (charsp[indexsp].simb!="\n")
                                                        {
                                                            cout << charsp[indexsp].simb << endl;
                                                            charsp[indexsp].simb=charsp[indexsp+1].simb;
                                                            cout << charsp[indexsp].simb << endl;
                                                            charsp[indexsp].sta=charsp[indexsp+1].sta;
                                                            indexsp++;
                                                        }
                                                        indexsp=refindsp;
                                                        while (charsp[indexsp].simb!="\n")
                                                        {
                                                            cout << charsp[indexsp].simb << endl;
                                                            charsp[indexsp].simb=charsp[indexsp+1].simb;
                                                            cout << charsp[indexsp].simb << endl;
                                                            charsp[indexsp].sta=charsp[indexsp+1].sta;
                                                            indexsp++;
                                                        }
                                                        indexsp=refindsp;
                                                        refindsp--;

                                                    }
                                                    else if(charsp[refindsp-1].simb=="{" && charsp[refindsp+1].simb=="}")
                                                    {
                                                        refindpa--;
                                                        indexsp=refindsp-1;
                                                        while (charsp[indexsp].simb!="\n")
                                                        {
                                                            cout << charsp[indexsp].simb << endl;
                                                            charsp[indexsp].simb=charsp[indexsp+1].simb;
                                                            cout << charsp[indexsp].simb << endl;
                                                            charsp[indexsp].sta=charsp[indexsp+1].sta;
                                                            indexsp++;
                                                        }
                                                        indexsp=refindsp;
                                                        while (charsp[indexsp].simb!="\n")
                                                        {
                                                            cout << charsp[indexsp].simb << endl;
                                                            charsp[indexsp].simb=charsp[indexsp+1].simb;
                                                            cout << charsp[indexsp].simb << endl;
                                                            charsp[indexsp].sta=charsp[indexsp+1].sta;
                                                            indexsp++;
                                                        }
                                                        indexsp=refindsp;
                                                        refindsp--;

                                                    }
                                                opvar[indopera].x1=varaux1;
                                                cout << opvar[indopera].x1 << endl;
                                                varx[indexvarx].varxy=varaux1;
                                                cout << varx[indexvarx].varxy;
                                                cout << indexvarx << endl;
                                                cout << charsp[indexsp].simb << endl;
                                                indexvarx++;
                                                opvar[indopera].x2=varaux2;
                                                cout << opvar[indopera].x2 << endl;
                                                varx[indexvarx].varxy=varaux2;
                                                cout << varx[indexvarx].varxy;
                                                cout << indexvarx << endl;
                                                indexvarx++;
                                                cout << refopera << endl;
                                                if (refopera == "+")
                                                {
                                                    opvar[indopera].opera="add";
                                                    //indopera++;
                                                }
                                                else if (refopera == "-")
                                                {
                                                    opvar[indopera].opera="sub";
                                                    //indopera++;
                                                }
                                                else if (refopera == "*")
                                                {
                                                    opvar[indopera].opera="mul";
                                                    //indopera++;
                                                }
                                                else if (refopera == "/")
                                                {
                                                    opvar[indopera].opera="div";
                                                    //indopera++;
                                                }

                                                if(indexop==1) //------------------------------------------------------------
                                                {
                                                    if(opmat==0 && usei==1)
                                                    {   opvar[indopera].x3=varequa;//-------------------8/4---12/4--13/4
                                                        cout << opvar[indopera].x3 << endl;
                                                        varx[indexvarx].varxy=varequa;        //M9 só funciona assim
                                                        cout << varx[indexvarx].varxy;
                                                        cout << indexvarx << endl; //-----------------8/4--12/4--13/4
                                                    }
                                                    while(buffersimbol[indexsimb]!=';')indexsimb++;
                                                }
                                                else
                                                {
                                                    opvar[indopera].x3=charsp[refindsp].simb;
                                                    cout << opvar[indopera].x3 << endl;
                                                    varx[indexvarx].varxy=charsp[refindsp].simb;
                                                    cout << varx[indexvarx].varxy;
                                                    cout << indexvarx << endl;
                                                }


                                                opvar[indopera].staop=0;
                                                cout << opvar[indopera].opera;
                                                cout << opvar[indopera].x1;
                                                cout << opvar[indopera].x2;
                                                cout << opvar[indopera].x3 << endl;



                                                indexvarx++;
                                                indopera++;
                                                indexsp=pontref;
                                                int indexspaux=0;
                                                if(indexop==1)expressaonum=0;
                                                while (charsp[indexspaux].simb!="\n")
                                                {
                                                    cout << charsp[indexspaux].simb << endl;
                                                    indexspaux++;
                                                }
                                            }
                                            else
                                            {
                                                indexsp++;
                                                indexsp++;
                                            }
                                        }
                                        else
                                        {
                                            if(nosimb)
                                            {
                                                indexsp=1;
                                                comutaux=1-comutaux;
                                                comuta=2-comutaux;
                                            }
                                            else {indexsp++;
                                            indexsp++;}
                                        }
                                    }
                                }

                                comutaux=1-comutaux;
                                comuta=2-comutaux;
                                indexsp=1;
                                cout << "comuta" ;
                                cout << comuta << endl;
                            }
                        }
                    }

                    indexvarx++;
                    //varx[indexvarx].varxy="\n";
                    //indexvarx++;
                } if(buffersimbol[indexsimb]=='0'){varequax=buffersimbol[indexsimb-2];indexsimb++; cout << varequax << endl;}

            }
            else if (buffersimbol[indexsimb] == '0')
            {
                indexsimb--;
                if (buffersimbol[indexsimb] == '=')
                {
                    indexsimb--;
                    opvar[indopera].x1=buffersimbol[indexsimb];
                    varx[indexvarx].varxy=buffersimbol[indexsimb];
                    cout << varx[indexvarx].varxy;
                    cout << indexvarx << endl;
                    indexvarx++;
                    opvar[indopera].x2='\0';
                    opvar[indopera].x3='\0';
                    opvar[indopera].opera="iniczero";
                    indopera++;
                    indexsimb++;
                    indexsimb++;
                }
                else
                {
                    indexsimb--;
                    varx[indexvarx].varxy=buffersimbol[indexsimb];
                    cout << varx[indexvarx].varxy;
                    cout << indexvarx << endl;
                    indexvarx++;
                }
            }
            else if (buffersimbol[indexsimb] == 'e')
            {
                indexsimb++;
                if (buffersimbol[indexsimb] != 'l')
                {
                    indexsimb--;
                    varx[indexvarx].varxy=buffersimbol[indexsimb];
                    cout << varx[indexvarx].varxy;
                    cout << indexvarx << endl;
                    indexvarx++;
                }
                else
                {
                    indexsimb++;
                    indexsimb++;
                    indexsimb++;
                    ke++;
                    if(buffersimbol[indexsimb]==' ')
                        while(buffersimbol[indexsimb]== ' ')indexsimb++;
                    secvar=buffersimbol[indexsimb];
                    if(secvar!=privar)
                    {
                        opdifere=1;
                        opvar[auxindopera].yy=1;
                        countchave++;
                    }
                }

            }
            else
                if(buffersimbol[indexsimb]=='+')//---------------------------------------------19/5
                {
                    refsimb=indexsimb;
                    opvar[indopera].opera="acc";
                    opvar[indopera].x1=buffersimbol[indexsimb-1];//-----------------28/4
                    secvar=buffersimbol[indexsimb-1];
                    indopera++;
                    indexsiaux=indexsimb;
                    privar=buffersimbol[indexsimb];
                    cout << privar << endl;
                    buffersimbol[indexsimb]=buffersimbol[indexsimb+1];
                    indexsimb++;
                    if(buffersimbol[indexsimb+2]!=';' && buffersimbol[indexsimb+2]!='[')
                    {
                        buffersimbol[indexsimb]='{';
                        while(buffersimbol[indexsimb]!=';')indexsimb++;
                        buffersimbol[indexsimb]='}';
                        indexsimb++;
                        buffersimbol[indexsimb]='+';
                        indexsimb++;
                        buffersimbol[indexsimb]=secvar;
                        indexsimb++;
                        buffersimbol[indexsimb]=';';
                    }
                    else
                    {
                        indexsimb--;
                        while(buffersimbol[indexsimb]!=';')
                        {
                            buffersimbol[indexsimb]=buffersimbol[indexsimb+1];
                            cout << buffersimbol[indexsimb] << endl;
                            indexsimb++;
                        }
                        indexsimb--;
                        cout << buffersimbol[indexsimb-1] << endl;
                        if(buffersimbol[indexsimb-1]!=']')//--------------------------------------19/5
                        {   buffersimbol[indexsimb]=privar;
                            indexsimb++;
                            buffersimbol[indexsimb]=secvar;
                            indexsimb++;
                            buffersimbol[indexsimb]=';';
                        } else opvar[indopera-1].vetor=1; //--------------------------------------------------------------------------19/5
                    }
                    indexsimb++;
                    buffersimbol[indexsimb]='\0';
                    //indexsiaux=indexsimb;
                    //while(buffersimbol[indexsimb]!=';')indexsimb++;
                    //indexsimb++;
                    //indexsimb++;buffersimbol[indexsimb]='\0';indexsimb--;
                    //buffersimbol[indexsimb]=';';
                    //cout << buffersimbol[indexsimb] << endl;
                    //indexsimb--;
                    //buffersimbol[indexsimb]=secvar;
                    //cout << buffersimbol[indexsimb] << endl;
                    //indexsimb--;
                    //buffersimbol[indexsimb]=privar;indexsimb--;
                    //while(indexsiaux!=indexsimb)
                    //    {
                    //        cout << buffersimbol[indexsimb] << endl;
                    //        buffersimbol[indexsimb-1]=buffersimbol[indexsimb];
                    //        cout << buffersimbol[indexsimb] << endl;
                    //        indexsimb--;
                    //    }
                    //buffersimbol[indexsiaux]=secvar;

                    indexsiaux=0;
                    while(buffersimbol[indexsiaux]!='\0')
                    {
                        cout << indexsiaux;
                        cout << buffersimbol[indexsiaux] << endl;
                        indexsiaux++;
                    }


                    //indexsimb; //-----------------------------------------------28/4
                    //indexsimb--;//------------------------------------------------27/4
                    indexsimb=refsimb-1;//------------------------------------------28/4

                }//----------------------------------------------------------------------------19/5


               else{
                if ((buffersimbol[indexsimb] != '<') &&//------------------------------------------11/5
                (buffersimbol[indexsimb] != '(') &&
                (buffersimbol[indexsimb] != ')') &&
                (buffersimbol[indexsimb] != '[') &&
                (buffersimbol[indexsimb] != ']') &&
                (buffersimbol[indexsimb] != ' ') &&
                (buffersimbol[indexsimb] != '{') &&
                (buffersimbol[indexsimb] != '}') &&
                (buffersimbol[indexsimb] != '<') &&
                //(buffersimbol[indexsimb] != '+') &&//---------------------------------------------------19/5
                (buffersimbol[indexsimb] != ';') &&
                (buffersimbol[indexsimb] != '*') &&
                (buffersimbol[indexsimb] != '-') &&
                (buffersimbol[indexsimb] != '/') &&
                (buffersimbol[indexsimb] != '!') &&
                (buffersimbol[indexsimb] != '\n'))
                {
                    varx[indexvarx].varxy=buffersimbol[indexsimb];
                    cout << varx[indexvarx].varxy;
                    cout << indexvarx << endl;
                    indexvarx++;
                }//-----------------------------------------------------------------------------11/5

            }
        };
        indexsimb++;
        cout << buffersimbol[indexsimb] << endl;
        cout << privar << endl;
        cout << secvar << endl;
    };

    int krx=0;
    kr=ki-ke;
    if(opdifere==1)
    {
        krx=2;
        countchave++;
    }
    kr=ki-ke+krx;
    int countaux=0;
    while(kr!=0)
    {
        if(countchave!=0)
            while(countaux<countchave)
            {
                opvar[indopera].opera="zeroif";
                opvar[indopera].x1='E';  // & VARIAVEL GERAR CONSTD DO IF
                varx[indexvarx].varxy='E';
                indexvarx++;
                indopera++;
                countaux++;
            }
        else
        {
            opvar[indopera].opera="zeroif";
            opvar[indopera].x1='E';  // & VARIAVEL GERAR CONSTD DO IF
            varx[indexvarx].varxy='E';
            indexvarx++;
            indopera++;
            countaux++;
        }
        kr--;
    }


    int kp=0;
    kp=kf;
    countaux=0;
    while(kp!=0)
    {
        if(countchave!=0)
            while(countaux<countchave)
            {
                opvar[indopera].opera="zerofor";
                opvar[indopera].x1='G'; // @ VARIAVEL GERAR CONSTC DO FOR
                varx[indexvarx].varxy='G';
                indexvarx++;
                indopera++;
                countaux++;
            }
        else
        {
            opvar[indopera].opera="zerofor";
            opvar[indopera].x1='G'; // @ VARIAVEL GERAR CONSTC DO FOR
            varx[indexvarx].varxy='G';
            opvar[indopera].yy=1;
            indexvarx++;
            indopera++;
            countaux++;
        }
        kp--;
    }

    if(kf!=0)
    {
        if(kf!=1)kp=2; else kp=1; //---------------------------------------------------------------14/6
        countaux=0;
        while(kp>=0)
        {
            opvar[indopera].opera="ctrlfor";
            opvar[indopera].x1='B'; // @ VARIAVEL GERAR CONSTC DO FOR
            varx[indexvarx].varxy='B';
            varx[indexvarx].ctrl=1;
            indexvarx++;
            indopera++;
            countaux++;
            kp--;
        }
    }

    int countope=0;
    /*kf=0;
    if(opdifere==1)countope=1;
        {
        while(opvar[kf].opera!="if")kf++;
        while(countope!=0)
         {
            opvar[indopera].opera="copyif";
            opvar[indopera].x1='#'; cout << opvar[indopera].x1 << endl;
            varx[indexvarx].varxy='#';
            varx[indexvarx].ctrl=1;
            indexvarx++;
            indopera++;
            countope--;
        }
        }
    */



            kr=ki;
    kp=0;
    while(kr>=1)
    {
        while(opvar[kp].opera!="if")kp++;
        if(opvar[kp].xx!=0)countope=opvar[kp].xx;
        if(opvar[kp].yy!=0)countope=countope+opvar[kp].yy+1;
//    if(kf!=1 && opvar[kp].xx==0 && opvar[kp].yy==0)countope=1;
        while(countope!=0)
        {
            opvar[indopera].opera="copyif";
            opvar[indopera].x1='#';
            cout << opvar[indopera].x1 << endl;
            varx[indexvarx].varxy='#';
            varx[indexvarx].ctrl=1;
            indexvarx++;
            indopera++;
            countope--;
        }
        kp++;
        kr--;
    }

    kr=kf;
    kp=0;
    //while(opvar[kp].opera!="for")kp++; ------// em -----19/4
//if(opvar[kp+1].matrix==1)countope=2;
    kp=0;
    while(kr>=1)
    {
        while(opvar[kp].opera!="for")kp++;
        if(opvar[kp].xx!=0)countope=opvar[kp].xx;
        if(opvar[kp].yy!=0)countope=countope+opvar[kp].yy+1;
        cout << opvar[kp].matrix << endl;
        //if(opvar[kp].matrix==1)countope=2;//---------------------------30/4-------//em--3/5(RESOLVER QDO 2 MATRIZES)
//    if(kf!=1){countope=kf;if(opvar[kp].xx!=0)countope++;} else if(opvar[kp].xx!=0) countope=countope+2; //=countope+opvar[kp].yy+1;
//    if(kf!=1 && opvar[kp].xx==0 && opvar[kp].yy==0)countope=1;
        while(countope>0)
        {
            opvar[indopera].opera="copyfor";
            opvar[indopera].x1='%';
            cout << opvar[indopera].x1 << endl;
            varx[indexvarx].varxy='%';
            varx[indexvarx].ctrl=1;
            indexvarx++;
            indopera++;
            countope--;
        }
        kp++;
        kr--;
    }







    int kpi=0;
    int kpj=0;
    int kpijn=0;
    indexsimb=0;
    while(buffersimbol[indexsimb]!='\0')
    {
        if(buffersimbol[indexsimb]=='[' && buffersimbol[indexsimb+2]==']')kpi++;
        if(buffersimbol[indexsimb]=='[' && buffersimbol[indexsimb+5]==']')kpj++;
        indexsimb++;
    }
    if(kpj==0)
    {
        countope=kpi;
        while(countope>0)
        {
            opvar[indopera].opera="zeroloadi";
            opvar[indopera].x1='Z';
            cout << opvar[indopera].x1 << endl;
            varx[indexvarx].varxy='Z';
            varx[indexvarx].ctrl=0;
            indexvarx++;
            indopera++;
            opvar[indopera].opera="zeroloadi";
            opvar[indopera].x1='Z';
            cout << opvar[indopera].x1 << endl;
            varx[indexvarx].varxy='Z';
            varx[indexvarx].ctrl=0;
            indexvarx++;
            indopera++;
            countope--;
        }
    }
    else
    {
        countope=kpj;
        while(countope>0)
        {
            opvar[indopera].opera="zeroloadj";
            opvar[indopera].x1='Z';
            cout << opvar[indopera].x1 << endl;
            varx[indexvarx].varxy='Z';
            varx[indexvarx].ctrl=0;
            indexvarx++;
            indopera++;
            countope--;
        }
    }

    int indevx=0;
    if(kpi>4)kpi--;
    if(kpj!=0)kpijn=kpi-2;
    else kpijn=kpi;
    cout << repn << endl;
    while(kpijn>0)
    {
        varx[indexvarx].varxy=repn;
        indexvarx++;
        kpijn--;
    }


    varx[indexvarx].varxy="\n";
    opvar[indopera].opera="\n";



    i=0;
    cout << "iniciando VARX" << endl;
    while(varx[i].varxy!="\n") {cout << varx[i].varxy << endl; i++;}


    i=0;
    while (opvar[i].opera !="\n")
    {
        cout << opvar[i].opera;
        cout << opvar[i].x1;
        cout << opvar[i].x2;
        cout << opvar[i].x3;
        cout << opvar[i].xx << endl;
        i++;
    }
    cout << privar; cout << secvar << endl;
    if(privar!=secvar && secvar!='\0' && privar!='+' )opvar[auxindopera].yy=1;//--------28/4
    else opvar[auxindopera].yy=0;
    cout << opvar[auxindopera].yy << endl;
    cout << opvar[auxindopera].xx << endl;
}
