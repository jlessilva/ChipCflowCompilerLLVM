#include "pairall.h"
#include "implfuncs.h"
#include "varevertices.h"
#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
#include<stdlib.h>



void pairall( int ki, int kf, int ks, string charsimb[], refif *ifx, reffor *forx, seqope *sop, refelse *elsex, char buffersimbol[], varepsta *varep, operacao *opvar, vertices *vert, asseline *operadores, defrefij *refiload, defrefij *refistore)
{
  cout << "Entrando no PAIRALL" << endl;
    int ke=0;
    int ka=0;
    int t=0;
    int auxindex=0;
    int indexsimb=0;
    int st=0;
    int ioif=0;
    int torf=0;
    int iofor=0;
    int indopex=0;
    int atribacc=0;
    int r=0;
    int kfx=0;
    char var1if, var2if;
    ki=0;
    kf=0;
    int kq=0;
    int found=0;

    for (t = 0; t < 100; t++) {
        ifx[t].aninha = 0;
        ifx[t].indope = 0;
        ifx[t].indvar = 0;
        ifx[t].indxif = 0;
        ifx[t].matrix = 0;
        ifx[t].staif = 0;
        ifx[t].ultimo = 0;
        ifx[t].vetor = 0;
    };
    t = 0;
    for (t = 0; t < 100; t++) {
        forx[t].aninha = 0;
        forx[t].atriacc = 0;
        forx[t].indope = 0;
        forx[t].indvar = 0;
        forx[t].indxfor = 0;
        forx[t].matrix = 0;
        forx[t].stafor = 0;
        forx[t].ultimo = 0;
        forx[t].vetor = 0;
    };




    while(opvar[kq].opera!="\n")
    {
        if(opvar[kq].opera=="accm" && opvar[kq].x1=="m")atribacc=1;
        kq++;
    }
    kq=0;
    while(opvar[kq].opera!="\n")
    {
        opvar[kq].staat=0;
        kq++;
    }
    while (buffersimbol[indexsimb] != '\0')
    {
        cout << buffersimbol[indexsimb] << endl;
        switch (st)
        {
        case 0:
        {
            if (buffersimbol[indexsimb] == 'i')
            {
                indexsimb++;
                if (buffersimbol[indexsimb] == 'f')
                {
                    ki=0;
                    indexsimb++;
                    indexsimb++;
                    ifx[ki].var1=buffersimbol[indexsimb];
                    indexsimb++;
                    indexsimb++;
                    ifx[ki].var2=buffersimbol[indexsimb];
                    indexsimb++;
                    indexsimb++;
                    kq=0;
                    found=0;
                    while(opvar[kq].opera!="\n" && found==0)
                    {
                        if(opvar[kq].opera=="if" && opvar[kq].staat==0)
                        {
                            ifx[ki].indope=opvar[kq].xx;
                            opvar[kq].staat=1;
                            found=1;
                        }
                        kq++;
                    }
                    //ifx[ki].indope=opvar[ki].xx;
                    cout << ifx[ki].indope << endl;
                    ifx[ki].indvar=opvar[ki].yy;
                    cout << ifx[ki].indvar << endl;
                    ifx[ki].vetor=opvar[ki].vetor;
                    ifx[ki].staif=0;
                    sop[ks].ope="if";
                    sop[ks].kx=ki;
                    ks++;
                    st=1;
                }
                else        //cout << buffersimbol[indexsimb] << endl;
                {
                    st=16; // ------------------------------------------------------------26/4
                }
            }
            else st = 16;//--------------------------------------------------------------26/4
        };
        break;

        case 1:
        {
            if (buffersimbol[indexsimb] == 'i')
            {
                cout << buffersimbol[indexsimb] << endl;
                indexsimb++;
                if (buffersimbol[indexsimb] == 'f')
                {
                    ki++;  // NEST DO IF
                    indexsimb++;
                    auxindex=indexsimb;
                    indexsimb++;
                    ifx[ki].var1=buffersimbol[indexsimb];
                    indexsimb++;
                    indexsimb++;
                    ifx[ki].var2=buffersimbol[indexsimb];
                    kq=0;
                    found=0;
                    while(opvar[kq].opera!="\n" && found==0)
                    {
                        if(opvar[kq].opera=="if" && opvar[kq].staat==0)
                        {
                            ifx[ki].indope=opvar[kq].xx;
                            opvar[kq].staat=1;
                            found=1;
                        }
                        kq++;
                    }
                    //ifx[ki].indope=opvar[ki].xx;
                    cout << ifx[ki].indope << endl;
                    ifx[ki].indvar=opvar[ki].yy;
                    cout << ifx[ki].indvar << endl;
                    ifx[ki].vetor=opvar[ki].vetor;
                    ifx[ki].staif=0;
                    indexsimb++;
                    indexsimb++;
                    sop[ks].ope="if";
                    sop[ks].kx=ki;
                    ks++;
                    st = 1;
                }
                else
                {
                    st = 2;
                    ifx[ki].ultimo=1;
                }
            }
            else
            {
                st = 2;
                ifx[ki].ultimo=1;
            }
        };
        break;

        case 2:
        {
            if (buffersimbol[indexsimb] == 'f')
            {
                cout << buffersimbol[indexsimb] << endl;
                indexsimb++;
                if (buffersimbol[indexsimb] == 'o')
                {
                    cout << buffersimbol[indexsimb] << endl;
                    indexsimb++;
                    if (buffersimbol[indexsimb] == 'r')
                    {
                        kf=0;
                        forx[kf].aninha=0;
                        indexsimb++;
                        indexsimb++;
                        forx[kf].var1=buffersimbol[indexsimb];
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        forx[kf].var2=buffersimbol[indexsimb];
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        kq=0;
                        found=0;
                        while(opvar[kq].opera!="\n" && found==0)
                        {
                            if(opvar[kq].opera=="for" && opvar[kq].staat==0)
                            {
                                forx[kf].indope=opvar[kq].xx;
                                opvar[kq].staat=1;
                                found=1;
                            }
                            kq++;
                        }
                        //forx[kf].indope=opvar[kf].xx;
                        cout << forx[kf].indope << endl;
                        forx[kf].indvar=opvar[kq-1].yy;
                        cout << ifx[ki].indvar << endl;
                        forx[kf].vetor=opvar[kq-1].vetor;
                        forx[kf].matrix=opvar[kq-1].matrix;
                        sop[ks].ope="for";
                        sop[ks].kx=kf;
                        if(ks!=0)if(sop[ks-1].ope=="if" && forx[kf].indope!=0)ifx[ki].indope=forx[kf].indope;
                        ks++;
                        st = 9 ;
                    }
                    else st = 3;
                }
                else st = 3;
            }
            else st = 3;
        }
        break;

        case 3:
        {
            while(buffersimbol[indexsimb]!= ';') indexsimb++;
            cout << " CHEGUEI NA ATRIBUICAO"  << endl;
            auxindex=indexsimb; // MANTEM O ULTIMO INDEX DE SIMBOLO ATÉ AQUI.
            geraopatrif(ki, ks, 0, ka, ifx, sop, indexsimb, buffersimbol, vert, opvar, operadores);
            cout << ifx[ki].tifs[t] << endl;
            cout << ifx[ki].ztifs[t] << endl;
            indexsimb=auxindex;
            indexsimb++;
            cout << buffersimbol[indexsimb] << endl;
            if (buffersimbol[indexsimb]=='\n' || buffersimbol[indexsimb]=='\0') indexsimb--;
            st=4;
        };
        break;

        case 4:
        {
            if (buffersimbol[indexsimb]=='e')
            {
                cout << buffersimbol[indexsimb] << endl;
                indexsimb++;
                if (buffersimbol[indexsimb]=='l')
                {
                    cout << buffersimbol[indexsimb] << endl;
                    indexsimb++;
                    if (buffersimbol[indexsimb]=='s')
                    {
                        cout << buffersimbol[indexsimb] << endl;
                        indexsimb++;
                        if (buffersimbol[indexsimb]=='e')
                        {
                            cout << buffersimbol[indexsimb] << endl;
                            indexsimb++;
                            st=6;
                            ifx[ki].staif=1;
                        }
                        else
                        {
                            indexsimb++;
                            st=5;
                            cout << buffersimbol[indexsimb] << endl;
                        }
                    }
                    else
                    {
                        indexsimb++;
                        st=5;
                        cout << buffersimbol[indexsimb] << endl;
                    }
                }
                else
                {
                    indexsimb++;
                    st=5;
                    cout << buffersimbol[indexsimb] << endl;
                }
            }
            else st=5;
        }
        break;

        case 5:
        {
            int kix=ki;
            indexsimb=auxindex;
            while (kix>=0)
            {
                while (buffersimbol[indexsimb]!='(' || buffersimbol[indexsimb-2]!='i')
                {
                    cout << buffersimbol[indexsimb] << endl;
                    cout << buffersimbol[indexsimb-2] << endl;
                    indexsimb--;
                }// DECIDER E dmerge
                if(ifx[ki].indvar==1)ka=1;
                int h=0;
                while(vert[h].verts!="\n")
                {
                    cout << h;
                    cout << "=";
                    cout << vert[h].verts;
                    cout << " ref ";
                    cout << vert[h].variref ;
                    cout << vert[h].stav << endl;
                    h++;
                }

                cout << ifx[kix].staif << endl;
                iffunc( kix, kf, ks, ka, ifx[kix].staif, ifx, forx,  sop,  indexsimb, buffersimbol,  varep, opvar, vert, operadores, refiload, refistore);
                indexsimb=auxindex;
                indexsimb++;
                indopex=ifx[ki].indope-1;
                while(indopex>0)
                {
                    {
                        while(buffersimbol[indexsimb]!=';')indexsimb++;
                        indexsimb++;
                    }
                    if(indopex==1)indexsimb++;
                    indopex--;
                }
                kix--;
                if(kfx>=0)indexsimb--;
            }
            //cout << sop[ks-2].ope << endl;
            if(ks!=0 && ks !=1)
            {
                if(ks>=2 && sop[ks-2].ope=="for") st=14;
                else
                {
                    st = 0;
                    while(buffersimbol[indexsimb]!='\0')indexsimb++;
                }
            }
            else
            {
                st = 0;
                while(buffersimbol[indexsimb]!='\0')indexsimb++;
            }
        }
        break;

        case 6:
        {
            if (buffersimbol[indexsimb] == 'i')
            {
                cout << buffersimbol[indexsimb] << endl;
                indexsimb++;
                if (buffersimbol[indexsimb] == 'f')
                {
                    cout << buffersimbol[indexsimb] << endl;
                    indexsimb++;
                    st = 1 ;
                }
                else st = 7;
            }
            else st = 7;
        }
        break;
        //forfunc[buffersimbol[indexsimb]
        case 7:
        {
            if (buffersimbol[indexsimb] == 'f')
            {
                cout << buffersimbol[indexsimb] << endl;
                indexsimb++;
                if (buffersimbol[indexsimb] == 'o')
                {
                    cout << buffersimbol[indexsimb] << endl;
                    indexsimb++;
                    if (buffersimbol[indexsimb] == 'r')
                    {
                        st = 9 ;
                    }
                    else st = 8;
                }
                else st = 8;
            }
            else st = 8;
        }
        break;                                   //forfunc[buffersimbol[indexsimb]



        case 8:
        {
            while(buffersimbol[indexsimb]!= ';') indexsimb++;
            cout << " CHEGUEI NA ATRIBUICAO"  << endl;
            auxindex=indexsimb; // MANTEM O ULTIMO INDEX DE SIMBOLO ATÉ AQUI.
            if(ifx[ki].indvar==1)
            {
                torf=0;
                ka=1;
            }
            else
            {
                torf=1;
                ka=0;
            }
            geraopatrif(ki, ks, torf, ka, ifx,  sop, indexsimb, buffersimbol, vert, opvar, operadores);
            cout << ifx[ki].tifs[t] << endl;
            cout << ifx[ki].fifs[t] << endl;
            cout << ifx[ki].tifs[t+1] << endl;
            cout << ifx[ki].fifs[t+1] << endl;
            cout << ifx[ki].zfifs[t+1] << endl;
            cout << ifx[ki].ztifs[t+1] << endl;
            indexsimb=auxindex;
            indexsimb++;
            cout << buffersimbol[indexsimb] << endl;
            if (buffersimbol[indexsimb]=='\n' || buffersimbol[indexsimb]=='\0') indexsimb--;
            st=12;
        };
        break;

        case 12:
        {
            if (buffersimbol[indexsimb]=='e')
            {
                cout << buffersimbol[indexsimb] << endl;
                indexsimb++;
                if (buffersimbol[indexsimb]=='l')
                {
                    cout << buffersimbol[indexsimb] << endl;
                    indexsimb++;
                    if (buffersimbol[indexsimb]=='s')
                    {
                        cout << buffersimbol[indexsimb] << endl;
                        indexsimb++;
                        if (buffersimbol[indexsimb]=='e')
                        {
                            cout << buffersimbol[indexsimb] << endl;
                            indexsimb++;
                            st=13;
                            ke++;
                            ifx[ki-ke].staif=1;
                        }
                        else
                        {
                            indexsimb++;
                            st=5;
                            cout << buffersimbol[indexsimb] << endl;
                        }
                    }
                    else
                    {
                        indexsimb++;
                        st=5;
                        cout << buffersimbol[indexsimb] << endl;
                    }
                }
                else
                {
                    indexsimb++;
                    st=5;
                    cout << buffersimbol[indexsimb] << endl;
                }
            }
            else st=5;
        }
        break;

        case 13:
        {
            while(buffersimbol[indexsimb]!= ';') indexsimb++;
            auxindex=indexsimb; // MANTEM O ULTIMO INDEX DE SIMBOLO ATÉ AQUI.
            ki--;
            if(ifx[ki].indope!=0)ka++;   //------------------------------------------------------------------------------
            geraopatrif(ki, ks, 1, ka, ifx,  sop, indexsimb, buffersimbol, vert, opvar, operadores);
            cout << ifx[ki].fifs[t+1] << endl;
            ki++;
            int kix=ki;
            indexsimb=auxindex;
            cout << buffersimbol[indexsimb] << endl;
            while (kix>=0)
            {
                while (buffersimbol[indexsimb]!='(' || buffersimbol[indexsimb-2]!='i')
                {
                    cout << buffersimbol[indexsimb] << endl;
                    cout << buffersimbol[indexsimb-2] << endl;
                    indexsimb--;
                }// DECIDER E dmerge
                cout << ifx[kix].staif << endl;
                iffunc( kix,  ks, kf, ka, ifx[kix].staif, ifx, forx, sop, indexsimb, buffersimbol,  varep, opvar, vert, operadores,refiload, refistore);
                indexsimb--;
                kix--;
            }
            indexsimb=auxindex;
            indexsimb++;
            st=0;
        };
        break;

        /*             case 13: { while(buffersimbol[indexsimb]!= ';') indexsimb++;
                                cout << " CHEGUEI NA ATRIBUICAO"  << endl;
                                auxindex=indexsimb; // MANTEM O ULTIMO INDEX DE SIMBOLO ATÉ AQUI.
                                ki--;
                                geraopatrif(ki, 0, ka, ifx, indexsimb, buffersimbol, vert, opvar, operadores);
                                cout << ifx[ki].tifs[t] << endl;
                                indexsimb=auxindex;indexsimb++;cout << buffersimbol[indexsimb] << endl;
                                if (buffersimbol[indexsimb]=='\n' || buffersimbol[indexsimb]=='\0') indexsimb--;
                                st=14;
                                ki++;
                            }; break;

                     case 14: {   int kix=ki;
                                indexsimb=auxindex;
                                while (kix>=0)
                                {
                                while (buffersimbol[indexsimb]!='(' || buffersimbol[indexsimb-2]!='i')
                                { cout << buffersimbol[indexsimb] << endl;
                                  cout << buffersimbol[indexsimb-2] << endl;
                                 indexsimb--;
                                }// DECIDER E dmerge
                                iffunc( kix, kf, ka, ifx[kix].staif, ifx, forx,  indexsimb, buffersimbol,  varep, opvar, vert, operadores);
                                indexsimb--;
                                kix--;
                                }
                                indexsimb=auxindex;indexsimb++;
                                st = 0;
                            } break;
        */

        case 9:
        {
            if (buffersimbol[indexsimb] == 'f')
            {
                cout << buffersimbol[indexsimb] << endl;
                indexsimb++;
                if (buffersimbol[indexsimb] == 'o')
                {
                    cout << buffersimbol[indexsimb] << endl;
                    indexsimb++;
                    if (buffersimbol[indexsimb] == 'r')
                    {
                        iofor++;
                        kf++;
                        forx[kf-1].aninha=1;
                        forx[kf].aninha=1;
                        indexsimb++;
                        indexsimb++;
                        forx[kf].var1=buffersimbol[indexsimb];
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        forx[kf].var2=buffersimbol[indexsimb];
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;


                        kq=0;
                        found=0;
                        int vetores=0;
                        while(opvar[kq].opera!="\n" && found==0)
                        {
                            if(opvar[kq].vetor==1)
                            {
                                vetores=1;
                                found=1;
                            }
                            kq++;
                        }
                        kq=0;
                        found=0;
                        while(opvar[kq].opera!="\n" && found==0)
                        {
                            if(opvar[kq].opera=="for" && opvar[kq].staat==0)
                            {
                                forx[kf].indope=opvar[kq].xx;
                                opvar[kq].staat=1;
                                found=1;
                            }
                            kq++;
                        }
                        //forx[kf].indope=opvar[kf].xx;
                        cout << ifx[ki].indope << endl;
                        forx[kf].indvar=opvar[kq-1].yy;
                        cout << ifx[ki].indvar << endl;
                        forx[kf].vetor=opvar[kq-1].vetor;
                        if(kf==0 && vetores==1) forx[kf].matrix=1; else forx[kf].matrix=opvar[kq-1].matrix;//--------------5/5
                        sop[ks].ope="for";
                        sop[ks].kx=ki;
                        ks++;
                        if(atribacc==1)forx[kf].atriacc=1;//------------------------------------------26/4
                        st=9;
                    }
                    else
                    {
                        st = 10;
                        forx[kf].ultimo=1;
                    }
                }
                else
                {
                    st = 10;
                    forx[kf].ultimo=1;
                }
            }
            else
            {
                st = 10;
                forx[kf].ultimo=1;
            }
        }
        break;

        case 10:
        {
            if (buffersimbol[indexsimb] == 'i')
            {
                cout << buffersimbol[indexsimb] << endl;
                indexsimb++;
                if (buffersimbol[indexsimb] == 'f')
                {
                    cout << buffersimbol[indexsimb] << endl;
                    indexsimb++;
                    kq=0;
                    found=0;
                    while(opvar[kq].opera!="\n" && found==0)
                    {
                        if(opvar[kq].opera=="if" && opvar[kq].staat==0)
                        {
                            ifx[ki].indope=opvar[kq].xx;
                            opvar[kq].staat=1;
                            found=1;
                        }
                        kq++;
                    }
                    //ifx[ki].indope=opvar[ki].xx;
                    cout << ifx[ki].indope << endl;
                    ifx[ki].indvar=opvar[ki].yy;
                    cout << ifx[ki].indvar << endl;
                    sop[ks].ope="if";
                    sop[ks].kx=ki;
                    if(ks!=0)if(sop[ks-1].ope=="for" && ifx[ki].indope!=0)forx[kf].indope=ifx[ki].indope;
                    ks++;
                    st = 1 ;
                }
                else st = 11;
            }
            else st = 11;
        }
        break;


        case 11:
        {
            while(buffersimbol[indexsimb]!= ';') indexsimb++;
            auxindex=indexsimb; // MANTEM O ULTIMO INDEX DE SIMBOLO ATÉ AQUI.
            geraopatrifor(kf, ks, 1, ka, forx, sop, indexsimb, buffersimbol, vert, opvar, operadores);
            indexsimb=auxindex;
            cout << buffersimbol[indexsimb] << endl;
            if (buffersimbol[indexsimb]=='\n' || buffersimbol[indexsimb]=='\0') indexsimb--;
            st=14;
        }
        break;

        case 14:
        {
            kfx=kf;
            indexsimb=auxindex;
            while(kfx>=0)
            {
                while (buffersimbol[indexsimb]!='(' || buffersimbol[indexsimb-3]!='f')
                {
                    cout << buffersimbol[indexsimb] << endl;
                    cout << buffersimbol[indexsimb-2] << endl;
                    indexsimb--;
                }
                // DECIDER E dmerge
                forfunc( ki, kfx, ks, ka, 0, ifx, forx, sop, indexsimb, buffersimbol,  varep, opvar, vert, operadores, refiload, refistore);
                //indexsimb=auxindex;indexsimb++;
                indopex=forx[kf].indope-1;
                while(indopex>0)
                {
                    {
                        while(buffersimbol[indexsimb]!=';')indexsimb++;
                        indexsimb++;
                    }
                    if(indopex==1)indexsimb++;
                    indopex--;
                }
                kfx--;
                if(kfx>=0)indexsimb--;
            }
            //cout << sop[ks-2].ope << endl;
            if(ks>=2 && sop[ks-2].ope=="if") st=5;
            else
            {
                st = 0;
                while(buffersimbol[indexsimb]!='\0')indexsimb++;
            }
        }
        break;


        case 16://-------------------------------------------------------------------------------26/4
        {
            if (buffersimbol[indexsimb] == 'f')
            {
                cout << buffersimbol[indexsimb] << endl;
                indexsimb++;
                if (buffersimbol[indexsimb] == 'o')
                {
                    cout << buffersimbol[indexsimb] << endl;
                    indexsimb++;
                    if (buffersimbol[indexsimb] == 'r')
                    {
                        kf=0;
                        forx[kf].aninha=0;
                        indexsimb++;
                        indexsimb++;
                        forx[kf].var1=buffersimbol[indexsimb];
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        forx[kf].var2=buffersimbol[indexsimb];
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;
                        indexsimb++;


                        kq=0;
                        found=0;
                        int matriz=0;
                        while(opvar[kq].opera!="\n" && found==0)
                        {
                            if(opvar[kq].matrix==1)
                            {
                                matriz=1; found=0;
                            }
                            kq++;
                        }

                        kq=0;
                        found=0;
                        while(opvar[kq].opera!="\n" && found==0)
                        {
                            if(opvar[kq].opera=="for" && opvar[kq].staat==0)
                            {
                                forx[kf].indope=opvar[kq].xx;
                                opvar[kq].staat=1;
                                found=1;
                            }
                            kq++;
                        }


                        //forx[kf].indope=opvar[kf].xx;
                        cout << forx[kf].indope << endl;
                        forx[kf].indvar=opvar[kq-1].yy;
                        cout << ifx[ki].indvar << endl;
                        cout << opvar[kq].matrix << endl;
                        forx[kf].vetor=opvar[kq-1].vetor;
                        if(kf==0 && matriz==1) forx[kf].matrix=1; else forx[kf].matrix=opvar[kq-1].matrix;//----------------------5/5
                        cout << forx[kf].matrix << endl;
                        sop[ks].ope="for";
                        sop[ks].kx=kf;
                        if(ks!=0)if(sop[ks-1].ope=="if" && forx[kf].indope!=0)ifx[ki].indope=forx[kf].indope;
                        ks++;
                        if(atribacc==1)forx[kf].atriacc=1;//-----------------------------------------26/4
                        st = 9 ;
                    }
                    else st = 17;//----------------------------------------------------------------------26/4
                }
                else st = 17;//----------------------------------------------------------------------26/4
            }
            else st = 17;//----------------------------------------------------------------------26/4
        }
        break;

        case 15: //----------------------------------------------------------------------26/4
        {
            while(buffersimbol[indexsimb]!= ';') indexsimb++;
            atribacc=1; indexsimb++; //-------------------------------------------------------------------26/4
            //auxindex=indexsimb; // MANTEM O ULTIMO INDEX DE SIMBOLO ATÉ AQUI.
            //geraopatrifor(kf, ks, 1, ka, forx, sop, indexsimb, buffersimbol, vert, opvar, operadores);
            //indexsimb=auxindex;
            //cout << buffersimbol[indexsimb] << endl;//--------------------------------------26/4
            if (buffersimbol[indexsimb]=='\n' || buffersimbol[indexsimb]=='\0') indexsimb--;
            st=0;
        }
        break; //----------------------------------------------------------------------26/4


        case 17:
        {
           if(buffersimbol[indexsimb+1]=='=' && buffersimbol[indexsimb+2]!='0')
            {
                string variz;
                int finish=1;
                r=0;
                atrifunc( ki, ks, ka, ifx,  sop, indexsimb, buffersimbol, vert, opvar, operadores);
                variz=operadores[0].s1; cout << variz << endl;
                cout << operadores[0].funcao << endl;
                cout << operadores[0].s1;
                cout << operadores[0].s2;
                cout << operadores[0].s3 << endl;
                operadores[0].funcao="branco";
                while(operadores[r].funcao!="\n")
                {
                cout << r;
                cout << operadores[r].funcao;
                cout << operadores[r].s1;
                cout << operadores[r].s2;
                cout << operadores[r].s3 << endl;
                r++;
                }
                if(r<=5)r--;else {r--;r--;}
                operadores[r].s3=variz;
                cout << r;
                cout << operadores[r].funcao;
                cout << operadores[r].s1;
                cout << operadores[r].s2;
                cout << operadores[r].s3 << endl;
                r=0;
                while(finish)
                {   while(operadores[r].funcao!="copyd" && operadores[r].funcao!="\n")
                    {
                        cout << r;
                        cout << operadores[r].funcao;
                        cout << operadores[r].s1;
                        cout << operadores[r].s2;
                        cout << operadores[r].s3 << endl;
                        r++;
                    }
                    if(operadores[r].funcao=="copyd")
                    {
                        operadores[r].funcao="branco";
                        operadores[r-1].funcao="branco";
                        r++;
                    } else if(operadores[r].funcao!="\n")r++;else finish=0;
                        cout << r;
                        cout << operadores[r].funcao;
                        cout << operadores[r].s1;
                        cout << operadores[r].s2;
                        cout << operadores[r].s3 << endl;
                }


                while(buffersimbol[indexsimb]!=';')indexsimb++;indexsimb++;

            } else st=15;

        }
        break;

        };
    };


    int j=0;
    int k=0;
    while (operadores[j].funcao!="\n")
    {
        if(operadores[j].funcao=="constd")
        {
            int kix=ki;
            while(kix>=0)
            {
                if(ifx[ki].indope!=0)t=ifx[ki].indope-1;
                else t=0;
                while(t>=0)
                {
                    cout << ifx[ki].ztifs[t];
                    cout << ifx[ki].zfifs[t] << endl;
                    if(operadores[j].s1==ifx[ki].ztifs[t] || operadores[j].s1==ifx[ki].zfifs[t] )operadores[j].funcao="branco";
                    t--;
                }
                kix--;
            }
        }
        cout << operadores[j].funcao + " ";
        cout << operadores[j].s1 + ",";
        cout << operadores[j].s2 + ",";
        cout << operadores[j].s3 + ",";
        cout << operadores[j].s4 + ",";
        cout << operadores[j].s5 + ",";
        cout << operadores[j].s6 + ";" << endl;
        j++;
    }

    j=0;
    k=0;
    while (operadores[j].funcao!="\n")
    {
        if(operadores[j].funcao=="constd")
        {
            while(opvar[k].opera!="dualload" && opvar[k].opera!="\n")k++;
            if(opvar[k].opera=="\n")k=0;
            else
            {
                cout << operadores[j].s1;
                cout << opvar[k].x1 << endl;
                if(operadores[j].s1==opvar[k].x1)
                {
                    operadores[j].funcao="branco";
                    k++;
                }
            }
        }
        cout << operadores[j].funcao + " ";
        cout << operadores[j].s1 + ",";
        cout << operadores[j].s2 + ",";
        cout << operadores[j].s3 + ",";
        cout << operadores[j].s4 + ",";
        cout << operadores[j].s5 + ",";
        cout << operadores[j].s6 + ";" << endl;
        j++;
    }


    j=0;
    k=0;
    while (operadores[j].funcao!="\n")
    {
        if(operadores[j].funcao=="constd")
        {
            while(opvar[k].opera!="dualstore" && opvar[k].opera!="\n")k++;
            if(opvar[k].opera=="\n")k=0;
            else
            {
                cout << operadores[j].s1;
                cout << opvar[k].x1 << endl;
                if(operadores[j].s1==opvar[k].x1)
                {
                    operadores[j].funcao="branco";
                    k++;
                }
            }
        }
        cout << operadores[j].funcao + " ";
        cout << operadores[j].s1 + ",";
        cout << operadores[j].s2 + ",";
        cout << operadores[j].s3 + ",";
        cout << operadores[j].s4 + ",";
        cout << operadores[j].s5 + ",";
        cout << operadores[j].s6 + ";" << endl;
        j++;
    }





    j=0;
    while (operadores[j].funcao!="\n")
    {
        if(operadores[j].funcao=="constc")
        {
            int kix=kf;
            while(kix>=0)
            {
                if(forx[kf].indope!=0)t=forx[kf].indope-1;
                else t=0;
                while(t>=0)
                {
                    cout << forx[kf].ztfs[t];
                    if(operadores[j].s1==forx[kf].ztfs[t])operadores[j].funcao="branco";
                    t--;
                }
                kix--;
            }
        }
        cout << operadores[j].funcao + " ";
        cout << operadores[j].s1 + ",";
        cout << operadores[j].s2 + ",";
        cout << operadores[j].s3 + ",";
        cout << operadores[j].s4 + ",";
        cout << operadores[j].s5 + ",";
        cout << operadores[j].s6 + ";" << endl;
        j++;
    }

    j=0;
    while (operadores[j].funcao!="\n")
    {
        if(operadores[j].funcao=="constd")
        {
            int kix=kf;
            while(kix>=0)
            {
                if(forx[kf].indope!=0)t=forx[kf].indope-1;
                else t=0;
                while(t>=0)
                {
                    cout << forx[kf].ztfs[t] << endl;
                    cout << operadores[j].s1 << endl;
                    if(operadores[j].s1==forx[kf].ztfs[t])
                    {
                        operadores[j].funcao="branco"; //--------------{--------------------------------15/4
                        cout << operadores[j].funcao << endl;//----------------------------------------15/4
                        //j++;//----------------------------------------------------------------------------------------10/5
                        while(operadores[j+1].funcao=="copyd") {operadores[j+1].funcao="branco"; j++;}//---tudo------15/4---10/5
                        cout << operadores[j+1].funcao << endl;//--------------------------------tudo-----15/4
                    } //------------------------------------------------}------------------------------15/4
                    t--;
                }
                kix--;
            }
        }
        cout << operadores[j].funcao + " ";
        cout << operadores[j].s1 + ",";
        cout << operadores[j].s2 + ",";
        cout << operadores[j].s3 + ",";
        cout << operadores[j].s4 + ",";
        cout << operadores[j].s5 + ",";
        cout << operadores[j].s6 + ";" << endl;
        j++;
    }


    j=0;
    while (operadores[j].funcao!="\n")
    {
        if(operadores[j].funcao=="constd")
        {
            if(operadores[j].s1=="{" || operadores[j].s1=="}")operadores[j].funcao="branco";
        }
        cout << operadores[j].funcao + " ";
        cout << operadores[j].s1 + ",";
        cout << operadores[j].s2 + ",";
        cout << operadores[j].s3 + ",";
        cout << operadores[j].s4 + ",";
        cout << operadores[j].s5 + ",";
        cout << operadores[j].s6 + ";" << endl;
        j++;
    }

    j=0;
    while (operadores[j].funcao!="\n")
    {
        if(operadores[j].funcao=="constc")
        {
            if(operadores[j].s1=="#")operadores[j].funcao="branco";
        }
        cout << operadores[j].funcao + " ";
        cout << operadores[j].s1 + ",";
        cout << operadores[j].s2 + ",";
        cout << operadores[j].s3 + ",";
        cout << operadores[j].s4 + ",";
        cout << operadores[j].s5 + ",";
        cout << operadores[j].s6 + ";" << endl;
        j++;
    }

    j=0;
    while (operadores[j].funcao!="\n")
    {
        if(operadores[j].funcao=="constc")
        {
            if(operadores[j].s1=="%")operadores[j].funcao="branco";
        }
        cout << operadores[j].funcao + " ";
        cout << operadores[j].s1 + ",";
        cout << operadores[j].s2 + ",";
        cout << operadores[j].s3 + ",";
        cout << operadores[j].s4 + ",";
        cout << operadores[j].s5 + ",";
        cout << operadores[j].s6 + ";" << endl;
        j++;
    }

    j=0;
    while (operadores[j].funcao!="\n")
    {
        if(operadores[j].funcao=="branco")
        {
            k=j+1;
            while(operadores[k].funcao=="copyd")
            {
                operadores[k].funcao="branco";
                k++;
            }
            j=k;
        }
        cout << operadores[j].funcao + " ";
        cout << operadores[j].s1 + ",";
        cout << operadores[j].s2 + ",";
        cout << operadores[j].s3 + ",";
        cout << operadores[j].s4 + ",";
        cout << operadores[j].s5 + ",";
        cout << operadores[j].s6 + ";" << endl;
        j++;
    }


        j=0;
    while (operadores[j].funcao!="\n")
    {
        if(operadores[j].funcao=="foricexx")
        {
            if(operadores[j+1].funcao=="copyc" && operadores[j+1].staop==0)
            {
                operadores[j+1].funcao="branco";
            }
            j++;
            if(operadores[j+1].funcao=="copyc" && operadores[j+1].staop==0)
            {
                operadores[j+1].funcao="branco";
            }
            j++;
            if(operadores[j+1].funcao=="copyc" && operadores[j+1].staop==0)
            {
                operadores[j+1].funcao="branco";
            }
            j++;
        }
        cout << operadores[j].funcao + " ";
        cout << operadores[j].s1 + ",";
        cout << operadores[j].s2 + ",";
        cout << operadores[j].s3 + ",";
        cout << operadores[j].s4 + ",";
        cout << operadores[j].s5 + ",";
        cout << operadores[j].s6 + ";" << endl;
        j++;
    }










    j=0;
    while (operadores[j].funcao!="\n")
    {
        if(operadores[j].funcao=="constd")
        {
            int ks=0;
            while(charsimb[ks]!="\n")
            {
                if(operadores[j].s1==charsimb[ks])operadores[j].funcao="branco";
                ks++;
            }
        }
        cout << operadores[j].funcao + " ";
        cout << operadores[j].s1 + ",";
        cout << operadores[j].s2 + ",";
        cout << operadores[j].s3 + ",";
        cout << operadores[j].s4 + ",";
        cout << operadores[j].s5 + ",";
        cout << operadores[j].s6 + ";" << endl;
        j++;
    }
    kfx=kf;
    while(kfx>=0)
    {

        j=0;
        string foraux="";
        foraux=forx[kfx].var1;
        cout << foraux << endl;
        while (operadores[j].funcao!="\n")
        {
            if(operadores[j].funcao=="constd")
            {
                if(operadores[j].s1==foraux)operadores[j].funcao="branco";
            }
       cout << operadores[j].funcao + " "; cout << operadores[j].s1 + ","; cout << operadores[j].s2 + ","; cout << operadores[j].s3 + ","; cout << operadores[j].s4 + ","; cout << operadores[j].s5 + ","; cout << operadores[j].s6 + ";" << endl;
            j++;
        }
        kfx--;
    }



    //j=2;------------------------------------------------------------------5/5 (RESOLVER ESSA CONDIÇÃO)
    //if(operadores[j].funcao=="copyd")operadores[j].funcao="branco";//----------------------28/4-----5/5



    j=0;
    while (operadores[j].funcao!="\n")
    {
        cout << operadores[j].staop;
        cout << operadores[j].funcao + " ";
        cout << operadores[j].s1 + ",";
        cout << operadores[j].s2 + ",";
        cout << operadores[j].s3 + ",";
        cout << operadores[j].s4 + ",";
        cout << operadores[j].s5 + ",";
        cout << operadores[j].s6 + ";" << endl;
        j++;
    }


}
