#include "implfuncs.h"
#include "varevertices.h"
#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
#include<stdlib.h>

using namespace std;


   void iffunc( int ki, int kf, int ks, int ka, int ioif, refif *ifx, reffor *forx,  seqope *sop, int indexsimb, char buffersimbol[], varepsta* varep, operacao *opvar, vertices *vert, asseline *operadores, defrefij *refiload, defrefij *refistore)
   {    int s=0;
        int t=0;
        int r=0;
        int found=0;
        int notfound=1;

                ifx[ki].indxif=ki;

                cout << buffersimbol[indexsimb] << endl; indexsimb++;
                ifx[ki].var1 = buffersimbol[indexsimb];
                cout << ifx[ki].var1 << endl;
                cout << buffersimbol[indexsimb] << endl; indexsimb++;
                cout << buffersimbol[indexsimb] << endl; indexsimb++;
                ifx[ki].var2 = buffersimbol[indexsimb];
                cout << ifx[ki].var2 << endl;
                cout << buffersimbol[indexsimb] << endl; indexsimb++;
                cout << buffersimbol[indexsimb] << endl;
                int j=0;
                int i=0;
                int k=0;
                int ko=0;
                cout << ifx[ki].indope << endl;
                cout << ifx[ki].indvar << endl;
                if (ifx[ki].indope==0 && ifx[ki].indvar==0)
                {if (ioif==0){   while ( vert[j].variref!="E") {cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;j++;}
                                while ( vert[j].stav==1) {cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;j++;}
                                cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                cout << j  << endl;
                                cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                vert[j].stav=1;
                                cout << ki << endl;
                                ifx[ki].fifs[t]=vert[j].verts; cout << ifx[ki].fifs[t] << endl;
                            }
                                pairopera(ki, kf, ks, ifx, forx, sop, "if", opvar, varep, vert, operadores, refiload, refistore); // gera DECIDER com x e y
                                indexsimb++;

                } else
                  if (ioif==0 || ka==1)
                    {
                                while ( vert[j].variref!="E") {cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;j++;}
                                while ( vert[j].stav==1) {cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;j++;}
                                cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                cout << j  << endl;
                                cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                vert[j].stav=1;
                                cout << ki << endl;
                                ifx[ki].fifs[t]=vert[j].verts; cout << ifx[ki].fifs[t] << endl;

                                indexsimb++;j++;
                                cout << ifx[ki].indope << endl;
                                if(ifx[ki].indvar==1)ifx[ki].indope=ifx[ki].indope+2;
                                cout << ifx[ki].indope << endl;
                                while (ifx[ki].indope>ko+1)
                                {   t++;if(ifx[ki].indope>2)j++;
                                    cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                    cout << j  << endl;
                                    cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                    vert[j].stav=1;
                                    cout << ki << endl;
                                    ifx[ki].fifs[t]=vert[j].verts; cout << ifx[ki].fifs[t] << endl;

                                    indexsimb++;
                                    ko++;
                                }

                                ko=0;
                                j=0;
                                t=0;
                                while ( vert[j].variref!="#") {cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;j++;}
                                j++;
                                cout << ifx[ki].aninha << endl;
                                if(ifx[ki].aninha!=0 || ifx[ki].indope!=0)
                                {cout << ifx[ki].ultimo << endl;
                                //if(ifx[ki].ultimo!=0)
                                r=0;
                                        found=1;
                                        while(found)
                                            {   notfound=1;
                                                while(notfound)
                                                {   while(operadores[r].funcao!="copyc" && operadores[r].s1!=vert[j].verts)
                                                    {cout << operadores[r].funcao; cout << operadores[r].s1; cout << vert[j].verts << endl;
                                                        r++;
                                                    } cout << operadores[r].funcao; cout << operadores[r].s1; cout << vert[j].verts << endl;
                                                    if (operadores[r].funcao=="copyc" && operadores[r].s1==vert[j].verts)notfound=0; else r++;
                                                }
                                                if(operadores[r].staop==1)r++;else found=0;
                                            }                                operadores[r].staop=1;
                                cout << operadores[r].funcao; cout << operadores[r].staop << endl;
                                cout << vert[j].verts; cout << operadores[r].s1 << endl;
                                while(vert[j].verts!=operadores[r].s1)j++;
                                ifx[ki].varz=operadores[r].s1; cout << ifx[ki].varz << endl;
                                cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                cout << j  << endl;
                                vert[j].stav=1;
                                cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                cout << ki << endl;
                                j++;
                                vert[j].stav=1;
//                                cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
//                                ifx[ki].ifctrl[t]=vert[j].verts; cout << ifx[ki].ifctrl[t] << endl;
                                /* else
                                   if(ki!=0)
                                   {r=0;
                                    while(operadores[r].funcao!="copyc" || operadores[r].staop==1)r++;
                                    operadores[r].staop=1;
                                    cout << operadores[r].funcao; cout << operadores[r].staop << endl;
                                    while(vert[j].verts!=operadores[r].s1)j++;
                                    ifx[ki].varz=operadores[r].s1; cout << ifx[ki].varz << endl;
                                    cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                    cout << j  << endl;

                                    vert[j].stav=1;
                                    cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                    cout << ki << endl;
                                    j++;
                                    vert[j].stav=1;
                                    cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                    ifx[ki].ifctrl[t]=vert[j].verts; cout << ifx[ki].ifctrl[t] << endl;
                                    } else
                                        {j++;
                                            ifx[ki].ifctrl[t]=ifx[ki].varz; cout << ifx[ki].varz << endl;
                                            cout << ifx[ki].varz << endl;
                                        }*/
                                } else
                                        if(ifx[ki].indope!=0)
                                        {r=0;
                                        found=1;
                                        while(found)
                                            {   notfound=1;
                                                while(notfound)
                                                {   while(operadores[r].funcao!="copyc" && operadores[r].s1!=vert[j].verts)
                                                    {cout << operadores[r].funcao; cout << operadores[r].s1; cout << vert[j].verts << endl;
                                                        r++;
                                                    }
                                                    if (operadores[r].funcao=="copyc" && operadores[r].s1==vert[j].verts)notfound=0; else r++;
                                                }
                                                if(operadores[r].staop==1)r++;else found=0;
                                            }                                        operadores[r].staop=1;
                                        cout << operadores[r].funcao; cout << operadores[r].staop << endl;
                                        cout << vert[j].verts; cout << operadores[r].s1 << endl;
                                        while(vert[j].verts!=operadores[r].s1)j++;
                                        ifx[ki].varz=operadores[r].s1; cout << ifx[ki].varz << endl;
                                        cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                        cout << j  << endl;
                                        vert[j].stav=1;
                                        cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;

                                        cout << ki << endl;
                                        }
                                         else{
                                            j++;
                                            ifx[ki].ifctrl[t]=ifx[ki].varz; cout << ifx[ki].varz << endl;
                                            cout << ifx[ki].varz<< endl;
                                            }
                                indexsimb++;j++;
                                cout << ifx[ki].indope << endl;
                                while (ifx[ki].indope>ko)
                                {   if(ifx[ki].indope>2 && ko<ifx[ki].indope-1)j++;
                                    cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                    cout << j  << endl;
                                    cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;

                                    cout << ki << endl;
                                    ifx[ki].ifctrl[t]=vert[j].verts; cout << ifx[ki].ifctrl[t] << endl;

                                    indexsimb++;
                                    ko++;t++;j++;
                                }
                                pairopera(ki, kf, ks, ifx, forx, sop, "if", opvar, varep, vert, operadores, refiload, refistore); // gera DECIDER com x e y
                                if(kf==0)
                                {r=0;found=1; cout << ifx[ki].ultimo << endl;
                                    while(found)
                                    {while((operadores[r].funcao!="copyc" || operadores[r].staop==1) && operadores[r].funcao!="\n")
                                    {cout << operadores[r].funcao; cout << operadores[r].staop; cout << operadores[r].s1; cout << vert[j-3].verts << endl;
                                     r++;
                                    }
                                    cout << operadores[r].funcao; cout << operadores[r].staop; cout << operadores[r].s1; cout << vert[j-3].verts << endl;
                                    if(operadores[r].funcao!="\n")
                                        if (ifx[ki].ultimo==1 && operadores[r].s1!=vert[j-3].verts) found=0; else operadores[r].funcao="branco";
                                    else found=0;
                                }}
                        }
   }

   void atrifuncif( int ki, int ks, int ka, refif *ifx,  seqope *sop, int indexsimb, char buffersimbol[],vertices *vert, operacao *opvar, asseline *operadores)
   {
        int auxindex=0;
        indexsimb++; //cout << "entrei no =" << endl;
        while (buffersimbol[indexsimb] != ';')
        cout << "OPERACAO 6 DENTRO DO =" << endl;//cout << buffersimbol[indexsimb] << endl;
        auxindex=indexsimb; // MANTEM O ULTIMO INDEX DE SIMBOLO ATÉ AQUI.
        geraopatrif(ki, ks, 0, ka, ifx,  sop, indexsimb, buffersimbol, vert, opvar, operadores);
        ifx[ki].varz=operadores[ka].s3;
        indexsimb=auxindex;indexsimb++;cout << buffersimbol[indexsimb] << endl;
   }




void geraopatrif(int ki, int ks, int torf, int ka, refif *ifx,  seqope *sop, int indexsimb, char buffersimbol[], vertices *vert, operacao *opvar, asseline *operadores)
{
    cout << "entrei na geraopatrif" << endl;
    string var1, var2, var3, var3x;
    string vert1,vert2,vert3;
    string operatipo;
    int t=0;

    if(ifx[ki].vetor==1 || ifx[ki].matrix==1)
    {
        cout << "matriz" << endl;

    }
    else
    {
        int ko=0;
        if(ifx[ki].indope==0)ko=-1;
        while(ifx[ki].indope>=ko+1)
        {
            while (buffersimbol[indexsimb]!= '=') indexsimb--;
            cout << buffersimbol[indexsimb] << endl;
            indexsimb--;
            var3=buffersimbol[indexsimb];
            //if(ifx[ki].indvar==1)t++;
            if(ka==1)t++;      //                                         AQUI ESTÁ UM PROBLEMA T=0 OU T=1
            if(torf==0) ifx[ki].ztifs[t]=var3;
            else ifx[ki].zfifs[t]=var3;
            cout << buffersimbol[indexsimb] << endl;
            cout << ifx[ki].zfifs[t] << endl;
            cout << ifx[ki].ztifs[t] << endl;
            int j=0;
            int simbesp=0;
            int refindexsimb=0;
            int qtdop=0;
            indexsimb++;
            indexsimb++;
            refindexsimb=indexsimb;
            while (buffersimbol[indexsimb]!= ';')
            {
                if(buffersimbol[indexsimb]== '{' || buffersimbol[indexsimb]== '['|| buffersimbol[indexsimb]== '(')simbesp=1;
                if(buffersimbol[indexsimb]=='+' || buffersimbol[indexsimb]=='-' ||buffersimbol[indexsimb]=='*' ||buffersimbol[indexsimb]=='/' )qtdop++;
                indexsimb++;
            }
            indexsimb=refindexsimb;
            if(simbesp!=1 && qtdop==1)
            {
                var1=buffersimbol[indexsimb];
                cout << buffersimbol[indexsimb] << endl;
                indexsimb++;
                if (buffersimbol[indexsimb]=='+') operatipo="add";
                else if (buffersimbol[indexsimb]=='*') operatipo="mul";
                else if (buffersimbol[indexsimb]=='-') operatipo="sub";
                else operatipo="div";
                cout << buffersimbol[indexsimb] << endl;
                indexsimb++;
                var2=buffersimbol[indexsimb];
                cout << buffersimbol[indexsimb] << endl;
                indexsimb++;

                int j=0;
                int k=0;
                int i=0;
                j=0;
                while (vert[j].variref != var1) j++;
                cout << vert[j].variref << endl;
                while (vert[j].stav !=0) j++;
                vert1=vert[j].verts;
                // ifx[ki].tifs=vert1;  // SALVA VERTICE DE REFERENCIA
                vert[j].stav=1;
                cout << j;
                cout << "=";
                cout << vert[j].verts;
                cout << " ref ";
                cout << vert[j].variref ;
                cout << vert[j].stav << endl;


                i=0;
                j=0;
                while (vert[j].variref != var2) j++;
                cout << vert[j].variref << endl;
                while (vert[j].stav !=0) j++;
                vert2=vert[j].verts;
                //  ifx[ki].fifs=vert2; // SALVA VERTICE DE REFERENCIA
                vert[j].stav=1;
                cout << j;
                cout << "=";
                cout << vert[j].verts;
                cout << " ref ";
                cout << vert[j].variref ;
                cout << vert[j].stav << endl;
                i++;


                i=0;

                j=0;
                while (vert[j].variref != var3) j++;
                cout << j;
                cout << "=";
                cout << vert[j].verts;
                cout << " ref ";
                cout << vert[j].variref ;
                cout << vert[j].stav << endl;

//        cout << vert[j].variref << endl;
//        cout << vert[j].verts << endl;
                while (vert[j].stav !=0) j++;
                vert3=vert[j].verts;
                cout << j;
                cout << "=";
                cout << vert[j].verts;
                cout << " ref ";
                cout << vert[j].variref ;
                cout << vert[j].stav << endl;
                //if(ka==1)t++;  //--------------------------------------------------------------------------------
                if(torf==0) ifx[ki].tifs[t]=vert3;
                else ifx[ki].fifs[t]=vert3; // SALVA VERTICE DE REFERENCIA
                cout << ifx[ki].tifs[t] << endl;
                cout << ifx[ki].fifs[t] << endl;
                vert[j].stav=1;
                cout << j;
                cout << "=";
                cout << vert[j].verts;
                cout << " ref ";
                cout << vert[j].variref ;
                cout << vert[j].stav << endl;
                i++;

                int kp=0;
                while (operadores[kp].funcao!=operatipo || operadores[kp].staop==1)
                {
                    cout << operatipo << endl;
                    cout << operadores[kp].funcao << endl;
                    kp++;
                }
                cout << operadores[kp].funcao << endl;

                operadores[kp].s1=vert1;
                operadores[kp].s2=vert2;
                operadores[kp].s3=vert3;
                operadores[kp].staop=1;


                cout << operadores[kp].funcao;
                cout << " ";
                cout << operadores[kp].s1;
                cout << ",";
                cout << operadores[kp].s2;
                cout << ",";
                cout << operadores[kp].s3;
                cout << ";" << endl;


            }
            else
            {

                int    i=0;
                while (opvar[i].opera !="\n")
                {
                    cout << opvar[i].opera ;
                    cout << opvar[i].x1 ;
                    cout << opvar[i].x2 ;
                    cout << opvar[i].x3 ;
                    cout << opvar[i].staop << endl;
                    i++;
                }



                i=0;
                while (opvar[i].opera !="\n" && qtdop!=0)
                {
                    if(opvar[i].staop!=1)
                        if(opvar[i].opera=="add" || opvar[i].opera=="mul" || opvar[i].opera=="sub" ||opvar[i].opera=="div")
                        {
                            var1=opvar[i].x1;
                            cout << opvar[i].x1 << endl;
                            if (opvar[i].opera=="add") operatipo="add";
                            else if (opvar[i].opera=="mul") operatipo="mul";
                            else if (opvar[i].opera=="sub") operatipo="sub";
                            else if (opvar[i].opera=="div") operatipo="div";
                            cout << opvar[i].x1 << endl;
                            var2=opvar[i].x2;
                            cout << opvar[i].x2 << endl;
                            opvar[i].staop=1;
                            qtdop--;

                            int j=0;
                            int k=0;
                            j=0;
                            while (vert[j].variref != var1) j++;
                            cout << vert[j].variref << endl;
                            while (vert[j].stav !=0) j++;
                            vert1=vert[j].verts;
                            // ifx[ki].tifs=vert1;  // SALVA VERTICE DE REFERENCIA
                            vert[j].stav=1;
                            cout << vert[j].verts;
                            cout << vert[j].variref ;
                            cout << vert[j].stav << endl;




                            j=0;
                            while (vert[j].variref != var2) j++;
                            cout << vert[j].variref << endl;
                            while (vert[j].stav !=0) j++;
                            vert2=vert[j].verts;
                            //  ifx[ki].fifs=vert2; // SALVA VERTICE DE REFERENCIA
                            vert[j].stav=1;
                            cout << vert[j].verts;
                            cout << vert[j].variref ;
                            cout << vert[j].stav << endl;

                            j=0;
                            var3x=opvar[i].x3;
                            cout << opvar[i].x3 << endl;
                            while (vert[j].variref != var3x) j++;
                            cout << vert[j].variref << endl;
                            while (vert[j].stav !=0) j++;
                            vert3=vert[j].verts;
                            //  ifx[ki].fifs=vert2; // SALVA VERTICE DE REFERENCIA
                            // vert[j].stav=1;
                            cout << vert[j].verts;
                            cout << vert[j].variref ;
                            cout << vert[j].stav << endl;
                            int ky=0;
                            while (operadores[ky].funcao!=operatipo || operadores[ky].staop==1)
                            {
                                cout << operatipo << endl;
                                cout << operadores[ky].funcao << endl;
                                ky++;
                            }
                            cout << operadores[ky].funcao << endl;

                            operadores[ky].s1=vert1;
                            operadores[ky].s2=vert2;
                            operadores[ky].s3=vert3;
                            operadores[ky].staop=1;


                            cout << operadores[ky].funcao;
                            cout << " ";
                            cout << operadores[ky].s1;
                            cout << ",";
                            cout << operadores[ky].s2;
                            cout << ",";
                            cout << operadores[ky].s3;
                            cout << ";" << endl;


                        }
                    i++;
                }

                j=0;
                while (vert[j].variref != var3x) j++;//-------x-------19/4
                cout << vert[j].variref << endl;
                cout << vert[j].verts << endl;
                while (vert[j].stav !=0) j++;
                vert3=vert[j].verts;

                if(torf==0) ifx[ki].tifs[t]=vert3;
                else ifx[ki].fifs[t]=vert3; // SALVA VERTICE DE REFERENCIA
                cout << ifx[ki].tifs[t] << endl;
                cout << ifx[ki].fifs[t] << endl;
                vert[j].stav=1;
                cout << vert[j].verts;
                cout << vert[j].variref ;
                cout << vert[j].stav << endl;




            }
            if(ifx[ki].indope!=0 || ifx[ki].indvar==1)
            {
                ko++;
                indexsimb++;
                indexsimb++;
                t++;
            }
            else ko=0;
        }
        cout << "sai do geraopatri"  << endl;


    }



}

   void forfunc(int ki, int kf, int ks, int ka, int ioif, refif *ifx, reffor *forx,  seqope *sop, int indexsimb, char buffersimbol[], varepsta* varep, operacao *opvar, vertices *vert, asseline *operadores, defrefij *refiload, defrefij *refistore)
   {    int s=0;
        int t=0;
        int r=0;
        int found=0;
        int notfound=1;
        int kfx=0;
        string xref;
                forx[kf].indxfor=kf;
                cout << buffersimbol[indexsimb] << endl; indexsimb++;
                forx[kf].var1 = buffersimbol[indexsimb];
                cout << forx[kf].var1 << endl;
                cout << buffersimbol[indexsimb] << endl; indexsimb=indexsimb+6;

                forx[kf].var2 = buffersimbol[indexsimb];
                cout << forx[kf].var2 << endl;
                cout << buffersimbol[indexsimb] << endl; indexsimb=indexsimb+5;
                cout << buffersimbol[indexsimb] << endl;
                int j=0;
                int i=0;
                int k=0;
                int ko=0;
                cout << forx[kf].indope << endl;
                cout << forx[kf].indvar << endl;
                if(forx[kf].ultimo==1)
                {
                while ( vert[j].variref!="B") {cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;j++;}
                while ( vert[j].stav==1) {cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;j++;}
                cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                cout << j  << endl;
                cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                //vert[j].stav=1;
                cout << kf << endl;
                forx[kf].cxfor=vert[j].verts; cout << forx[kf].cxfor << endl;

                }
                indexsimb++;
                cout << forx[kf].indope; cout << forx[kf].indvar; cout << forx[kf].aninha << endl;
                if (forx[kf].indope==0 && forx[kf].indvar==0 && forx[kf].aninha==0)
                {j=0; if (ioif==0){   while ( vert[j].variref!="G") {cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;j++;}
                                while ( vert[j].stav==1) {cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;j++;}
                                cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                cout << j  << endl;
                                cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                vert[j].stav=1;
                                cout << kf << endl;
                                forx[kf].ffs[t]=vert[j].verts; cout << forx[kf].ffs[t] << endl;
                            }
                                pairopera(ki, kf, ks, ifx, forx, sop, "for", opvar, varep, vert, operadores, refiload, refistore); // gera DECIDER com x e y
                                if(kf==0)
                                {r=0;found=1;
                                    while(found)
                                    {while((operadores[r].funcao!="copyc" || operadores[r].staop==1) && operadores[r].funcao!="\n")
                                    {cout << operadores[r].funcao; cout << operadores[r].staop; cout << operadores[r].s1; cout << vert[j-3].verts << endl;
                                     r++;
                                    }
                                    cout << operadores[r].funcao; cout << operadores[r].staop; cout << operadores[r].s1; cout << vert[j-3].verts << endl;
                                    if(operadores[r].funcao!="\n")
                                        if (forx[kf].ultimo==1 && operadores[r].s1!=vert[j-3].verts && forx[kf].aninha!=0) found=0; else if(operadores[r-1].s1!="B")operadores[r].funcao="branco";
                                    else found=0;

                                }}
                                indexsimb++;
                } else
                  if (ioif==0 || ka==1)
                               {j=0;   while ( vert[j].variref!="G") {cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;j++;}
                                while ( vert[j].stav==1) {cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;j++;}
                                cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                cout << j  << endl;
                                cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                vert[j].stav=1;
                                cout << kf << endl;
                                forx[kf].ffs[t]=vert[j].verts; cout << forx[kf].ffs[t] << endl;

                                indexsimb++;j++;
                                cout << forx[kf].indope << endl;
                                if(forx[kf].indvar==1)forx[kf].indope=forx[kf].indope+2;
                                cout << forx[kf].indope << endl;
                                while (forx[kf].indope>ko+1)
                                {   t++;if(forx[kf].indope>2)j++;
                                    cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                    cout << j  << endl;
                                    cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                    vert[j].stav=1;
                                    cout << kf << endl;
                                    forx[kf].ffs[t]=vert[j].verts; cout << forx[kf].ffs[t] << endl;

                                    indexsimb++;
                                    ko++;
                                }
                                ko=0;
                                j=0;
                                t=0;
                                while ( vert[j].variref!="%" && vert[j].verts!="\n"){cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;j++;}
                                if(vert[j].verts!="\n")
                                {
                                j++;
                                cout << forx[kf].aninha << endl;
                                if(forx[kf].aninha!=0)
                                {
                                if(forx[kf].ultimo!=0)
                                {r=0;
                                        found=1;
                                         while(found)
                                            {   cout << operadores[r].funcao << endl;
                                                notfound=1;
                                                while(notfound)
                                                {   while(operadores[r].funcao!="copyc" && operadores[r].s1!=vert[j].verts && operadores[r].funcao!="\n")//--------------30/4
                                                    {cout << operadores[r].funcao; cout << operadores[r].s1; cout << vert[j].verts << endl;
                                                        r++;
                                                    }
                                                    if(operadores[r].funcao!="\n") if (operadores[r].funcao=="copyc" && operadores[r].s1==vert[j].verts)notfound=0; else r++;//-----30/4
                                                }
                                                cout << operadores[r].funcao; cout << operadores[r].s1; cout << vert[j].verts << endl;
                                                cout << operadores[r].staop << endl;
                                                if(operadores[r].staop==1)r++;else found=0;
                                            }
                                operadores[r].staop=1;
                                cout << operadores[r].funcao; cout << operadores[r].staop << endl;
                                cout << vert[j].verts; cout << operadores[r].s1 << endl;
                                while(vert[j].verts!=operadores[r].s1)j++;
                                forx[kf].ctrlf=operadores[r].s1; cout << forx[kf].ctrlf << endl;

                                cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                cout << j  << endl;
                                vert[j].stav=1;
                                cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                cout << kf << endl;
                                j++;
                                vert[j].stav=1;
                                while(vert[j].stav==1)j++;
                                cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                forx[kf].forctrl[t]=vert[j].verts; cout << forx[kf].forctrl[t] << endl;
                                j++;
                                vert[j].stav=1;
                                cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                forx[kf-1].cxfor=vert[j].verts; cout << forx[kf-1].cxfor << endl;

                                } else
                                   if(kf!=0)
                                   {r=0;

                                        while(operadores[r].funcao!="\n")
                                        {
                                          cout << r; cout << operadores[r].funcao; cout << operadores[r].s1; cout << vert[j].verts << endl;
                                          r++;

                                        }

                                        r=0;


                                        found=1;
                                        while(found)
                                            {   cout << operadores[r].funcao << endl;
                                                cout << vert[j].verts << endl;
                                                notfound=1;
                                                while(notfound)
                                                {   while(operadores[r].funcao!="copyc" && operadores[r].s1!=vert[j].verts && operadores[r].funcao!="\n")//--------30/4
                                                    {cout << operadores[r].funcao; cout << operadores[r].s1; cout << vert[j].verts << endl;
                                                        r++;
                                                    }
                                                    if(operadores[r].funcao!="\n") if (operadores[r].funcao=="copyc" && operadores[r].s1==vert[j].verts)notfound=0; else r++;//------30/4
                                                }
                                                cout << operadores[r].funcao; cout << operadores[r].s1; cout << vert[j].verts << endl;
                                                cout << operadores[r].staop << endl;
                                                if(operadores[r].staop==1)r++;else found=0;
                                            }
                                    operadores[r].staop=1;
                                    cout << operadores[r].funcao; cout << operadores[r].staop << endl;
                                    while(vert[j].verts!=operadores[r].s1)j++;
                                    forx[kf].ctrlf=operadores[r].s1; cout << forx[kf].ctrlf << endl;

                                    cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                    cout << j  << endl;
                                    vert[j].stav=1;
                                    cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                    cout << kf << endl;
                                    j++;
                                    vert[j].stav=1;
                                    cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                    forx[kf].forctrl[t]=vert[j].verts; cout << forx[kf].forctrl[t] << endl;
                                    j++;
                                    vert[j].stav=1;
                                    while(vert[j].stav==1)j++;
                                    cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                    forx[kf-1].cxfor=vert[j].verts; cout << forx[kf-1].cxfor << endl;

                                    } else
                                        {j++;
                                            forx[kf].forctrl[t]=forx[kf].ctrlf; cout << forx[kf].ctrlf << endl;
                                            cout << forx[kf].cxfor << endl;
                                        }

                                } else
                                        if(forx[kf].indope!=0)
                                        {r=0;
                                        found=1;
                                        cout << vert[j].verts << endl;
                                        while(found)
                                            {   cout << operadores[r].funcao << endl;
                                                notfound=1;
                                                while(notfound)
                                                {   while(operadores[r].funcao!="copyc" && operadores[r].s1!=vert[j].verts)
                                                    {cout << operadores[r].funcao; cout << operadores[r].s1; cout << vert[j].verts << endl;
                                                        r++;
                                                    }
                                                    if (operadores[r].funcao=="copyc" && operadores[r].s1==vert[j].verts)notfound=0; else r++;
                                                }
                                                cout << operadores[r].funcao; cout << operadores[r].s1; cout << vert[j].verts << endl;
                                                cout << operadores[r].staop << endl;
                                                if(operadores[r].staop==1)r++;else found=0;
                                            }
                                        operadores[r].staop=1;
                                        cout << operadores[r].funcao; cout << operadores[r].staop << endl;
                                        cout << vert[j].verts; cout << operadores[r].s1 << endl;
                                        while(vert[j].verts!=operadores[r].s1)j++;
                                        forx[kf].ctrlf=operadores[r].s1; cout << forx[kf].ctrlf << endl;

                                        cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                        cout << j  << endl;
                                        vert[j].stav=1;
                                        cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                        cout << kf << endl;
                                        j++;j++;
                                        vert[j].stav=1;
                                        cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                        forx[kf].forctrl[t]=vert[j].verts; cout << forx[kf].forctrl[t] << endl;
                                        }
                                         else{
                                            j++;
                                            forx[kf].forctrl[t]=forx[kf].ctrlf; cout << forx[kf].ctrlf << endl;
                                            cout << forx[kf].cxfor << endl;
                                            }
                                   } else {r=0;
                                            found=1;
                                            kfx=0;
                                            while(found)
                                            {while(operadores[r].funcao!="foricexx" && operadores[r].funcao!="\n") r++;
                                            if(operadores[r].funcao!="\n")
                                            {cout << operadores[r].funcao; cout << operadores[r].stanes << endl;
                                             if(operadores[r].stanes==0)
                                                { r++;
                                                  forx[kfx].ctrlf=operadores[r].s1;
                                                  //operadores[r-1].s3=operadores[r].s1;
                                                  cout << operadores[r-1].funcao; cout <<operadores[r].s1 << endl;
                                                  operadores[r-1].stanes=1;
                                                }else r++;
                                               kfx++;
                                            } else found=0;
                                            }
											}
                                indexsimb++;j++;
                                cout << forx[kf].indope << endl;
                                while (forx[kf].indope>ko+1)
                                {   t++;if(forx[kf].indope>2)j++;
                                    cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;
                                    cout << j  << endl;
                                    cout << vert[j].verts; cout << vert[j].variref << endl; cout << vert[j].stav << endl;

                                    cout << kf << endl;
                                    forx[kf].forctrl[t]=vert[j].verts; cout << forx[kf].forctrl[t] << endl;

                                    indexsimb++;
                                    ko++;
                                }
                                r=0;
                                found=1;
                                while(found)
                                {while(operadores[r].funcao!="foricexx" && operadores[r].funcao!="\n") r++;
                                    cout << operadores[r].staop << endl;
                                    if (operadores[r].staop!=1){found=0;/*operadores[r].staop=1;*/} else r++;
                                }
                                pairopera(ki, kf, ks, ifx, forx, sop, "for", opvar, varep, vert, operadores, refiload, refistore); // gera DECIDER com x e y
                                if(kf==0 && (forx[kf].matrix==1 || forx[kf].vetor==1))//-------------------------------13/4
                                    {   r=0;
                                        found=1;
                                        while(found)
                                        {
                                            while(operadores[r].funcao!="foricexx" && operadores[r].funcao!="\n")
                                            {
                                                if(operadores[r].funcao=="\n") found=0; else r++;
                                            }
                                            if (operadores[r].funcao=="\n") found=0;
                                            r++;
                                            if(operadores[r].funcao=="copyc" && operadores[r].staop==0) operadores[r].funcao="branco";
                                            cout << operadores[r].funcao; cout << operadores[r].staop << endl;
                                            found=0;//-----------------------------------------------------------------------10/5
                                        }
                                    }else if(kf==0 && forx[kf].aninha==1 && forx[kf].matrix==0 && forx[kf].vetor==0)
                                            {
                                                r=0;
                                                found=1;
                                                while(found)
                                                {
                                                    while(operadores[r].funcao!="foricexx" && operadores[r].funcao!="\n")
                                                    {
                                                        if(operadores[r].funcao=="\n") found=0;
                                                        else r++;
                                                    }
                                                    if (operadores[r].funcao=="\n") found=0;
                                                    r++;
                                                    if(operadores[r].funcao=="copyc" && forx[0].ctrlf==operadores[r].s1) operadores[r].funcao="branco";
                                                    cout << operadores[r].funcao;
                                                    cout << operadores[r].staop << endl;
                                                }
                                            }else  //---------------------------------------------13/4----else 14/4---
                                                if(kf==0 && forx[kf].aninha==0 && forx[kf].matrix==0 && forx[kf].vetor==0)
                                                {
                                                    r=0;
                                                    found=1;
                                                    while(found)
                                                    {
                                                        while(operadores[r].funcao!="foricexx" && operadores[r].funcao!="\n")
                                                        {
                                                            if(operadores[r].funcao=="\n") found=0;
                                                            else r++;
                                                        }
                                                        if (operadores[r].funcao=="\n") found=0;
                                                        r++;
                                                        if(operadores[r].funcao=="copyc") operadores[r].funcao="branco";
                                                        cout << operadores[r].funcao;
                                                        cout << operadores[r].staop << endl;
                                                    }
                                                } //---------------------------------------------14/4




                                /*{r=0;found=1;xref=forx[kf].ctrlf; cout << xref << endl;
                                    while(found)
                                    {   while(operadores[r].funcao!="copyc")r++;
                                        if(operadores[r].s1==xref){operadores[r].funcao="branco";found=0;} else r++;
                                    }





                                    while((operadores[r].funcao!="copyc" || operadores[r].staop==1) && operadores[r].funcao!="\n")
                                    {cout << operadores[r].funcao; cout << operadores[r].staop; cout << operadores[r].s1; cout << vert[j-3].verts << endl;
                                     r++;
                                    }
                                    cout << operadores[r].funcao; cout << operadores[r].staop; cout << operadores[r].s1; cout << vert[j-3].verts << endl;
                                    if(operadores[r].funcao!="\n")
                                        //if (forx[kf].ultimo==1 && operadores[r].s1!=vert[j-3].verts) found=0; else
                                            operadores[r].funcao="branco";
                                  else found=0;


                                }*/

                        }

}

void geraopatrifor(int kf, int ks, int torf, int ka, reffor *forx,  seqope *sop, int indexsimb, char buffersimbol[], vertices *vert, operacao *opvar, asseline *operadores)
{   cout << "entrei na geraopatrifor" << endl;
    string var1, var2, var3, var3x;
    string vert1,vert2,vert3;
    string operatipo;                                      //DEFINIR ACC//----------------26/4
    int refsimb=0;
    int t=0;
    int refkp=0;//-------------------------------------------------------------28/4
    cout << forx[kf].vetor; cout << forx[kf].matrix << endl;
    if(forx[kf].vetor==0 && forx[kf].matrix==0)
    {   //refsimb=indexsimb;
        //cout << "matriz" << endl;
        //while (buffersimbol[refsimb]!= '=') refsimb--;
        //cout << buffersimbol[refsimb] << endl;
        //refsimb--;
        //var3=buffersimbol[refsimb];
        //forx[kf].ztfs[t]=var3;
        //cout << forx[kf].ztfs[t] << endl;
    //} else
    //{
        int ko=0;
        if(forx[kf].indope==0)ko=-1;
        while(forx[kf].indope>=ko+1)
        {
            while (buffersimbol[indexsimb]!= '=') indexsimb--;
            cout << buffersimbol[indexsimb] << endl;
            indexsimb--;
            var3=buffersimbol[indexsimb];
            if(ka==1)t++;
            if(torf==0) forx[kf].ztfs[t]=var3; else forx[kf].ztfs[t]=var3;
            cout << buffersimbol[indexsimb] << endl;
            cout << forx[kf].ztfs[t] << endl;
            //    cout << ifx[ki].ztifs[t] << endl;
            int j=0;
            int simbesp=0;
            int refindexsimb=0;
            int qtdop=0;
            indexsimb++;
            indexsimb++;
            refindexsimb=indexsimb;
            while (buffersimbol[indexsimb]!= ';')
            {   if(buffersimbol[indexsimb]== '{' || buffersimbol[indexsimb]== '['|| buffersimbol[indexsimb]== '(')simbesp=1;
                if(buffersimbol[indexsimb]=='+' || buffersimbol[indexsimb]=='-' ||buffersimbol[indexsimb]=='*' ||buffersimbol[indexsimb]=='/' )qtdop++;
                indexsimb++;
            }
            indexsimb=refindexsimb;
            if(simbesp!=1 && qtdop==1)
            {
                var1=buffersimbol[indexsimb];
                cout << buffersimbol[indexsimb] << endl;
                indexsimb++;
                if (buffersimbol[indexsimb]=='+') operatipo="add";
                else if (buffersimbol[indexsimb]=='*') operatipo="mul";
                     else if (buffersimbol[indexsimb]=='-') operatipo="sub";
                          else operatipo="div";
                cout << buffersimbol[indexsimb] << endl;
                indexsimb++;
                var2=buffersimbol[indexsimb];
                cout << buffersimbol[indexsimb] << endl;
                indexsimb++;

                int j=0;
                int k=0;
                int i=0;
                j=0;
                while (vert[j].variref != var1) j++;
                cout << vert[j].variref << endl;
                while (vert[j].stav !=0) j++;
                vert1=vert[j].verts;
                // ifx[ki].tifs=vert1;  // SALVA VERTICE DE REFERENCIA
                vert[j].stav=1;
                cout << j; cout << "="; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref ; cout << vert[j].stav << endl;

                i=0;
                j=0;
                while (vert[j].variref != var2) j++;
                cout << vert[j].variref << endl;
                while (vert[j].stav !=0) j++;
                vert2=vert[j].verts;
                //  ifx[ki].fifs=vert2; // SALVA VERTICE DE REFERENCIA
                vert[j].stav=1;
                cout << j; cout << "="; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref ; cout << vert[j].stav << endl;
                i++;

                i=0;
                j=0;
                while (vert[j].variref != var3) j++;
                cout << j; cout << "="; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref ; cout << vert[j].stav << endl;
                while (vert[j].stav !=0) j++;
                vert3=vert[j].verts;
                cout << j; cout << "="; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref ; cout << vert[j].stav << endl;
                //if(ka==1)t++;  //--------------------------------------------------------------------------------
                forx[kf].tfs[t]=vert3; // SALVA VERTICE DE REFERENCIA
                cout << forx[kf].tfs[t] << endl;
                vert[j].stav=1;
                cout << j; cout << "="; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref ; cout << vert[j].stav << endl;
                i++;

                int kp=0;
                while (operadores[kp].funcao!=operatipo || operadores[kp].staop==1)
                {   cout << operatipo << endl;
                    cout << operadores[kp].funcao << endl;
                    kp++;
                }
                cout << operadores[kp].funcao << endl;
                operadores[kp].s1=vert1;
                operadores[kp].s2=vert2;
                operadores[kp].s3=vert3;
                operadores[kp].staop=1;
                refkp=kp;
                cout << operadores[kp].funcao; cout << " ";cout << operadores[kp].s1; cout << ","; cout << operadores[kp].s2; cout << ","; cout << operadores[kp].s3; cout << ";" << endl;
            } else
                {
                    int i=0;
                    while (opvar[i].opera !="\n")
                    {   cout << opvar[i].opera ;
                        cout << opvar[i].x1 ;
                        cout << opvar[i].x2 ;
                        cout << opvar[i].x3 ;
                        cout << opvar[i].staop << endl;
                        i++;
                    }

                    i=0;//-----------------------------------------------------------12/4
                    while (opvar[i].opera !="\n")
                        { cout << i;
                        cout << opvar[i].opera;
                        cout << opvar[i].x1 ;
                        cout << opvar[i].x2 ;
                        cout << opvar[i].x3 ;
                        cout << opvar[i].staop << endl;
                            i++;
                        } //--------------------------------------------------------12/4



                    i=0;
                    while (opvar[i].opera !="\n" && qtdop!=0)
                    {
                        if(opvar[i].staop!=1)
                        if(opvar[i].opera=="add" || opvar[i].opera=="mul" || opvar[i].opera=="sub" ||opvar[i].opera=="div")
                        {
                            var1=opvar[i].x1;
                            cout << opvar[i].x1 << endl;
                            if (opvar[i].opera=="add") operatipo="add";
                            else if (opvar[i].opera=="mul") operatipo="mul";
                                 else if (opvar[i].opera=="sub") operatipo="sub";
                                      else if (opvar[i].opera=="div") operatipo="div";
                            cout << opvar[i].x1 << endl;
                            var2=opvar[i].x2;
                            cout << opvar[i].x2 << endl;
                            opvar[i].staop=1;
                            qtdop--;

                            int j=0;
                            int k=0;
                            j=0;
                            while (vert[j].variref != var1) j++;
                            cout << vert[j].variref << endl;
                            while (vert[j].stav !=0) j++;
                            vert1=vert[j].verts;
                            // ifx[ki].tifs=vert1;  // SALVA VERTICE DE REFERENCIA
                            vert[j].stav=1;
                            cout << vert[j].verts; cout << vert[j].variref ; cout << vert[j].stav << endl;

                            j=0;
                            while (vert[j].variref != var2) j++;
                            cout << vert[j].variref << endl;
                            while (vert[j].stav !=0) j++;
                            vert2=vert[j].verts;
                            //  ifx[ki].fifs=vert2; // SALVA VERTICE DE REFERENCIA
                            vert[j].stav=1;
                            cout << vert[j].verts; cout << vert[j].variref ; cout << vert[j].stav << endl;

                            j=0;
                            var3x=opvar[i].x3;
                            cout << opvar[i].x3 << endl;
                            while (vert[j].variref != var3x) j++;
                            cout << vert[j].variref << endl;
                            while (vert[j].stav !=0) j++;
                            vert3=vert[j].verts;
                            //  ifx[ki].fifs=vert2; // SALVA VERTICE DE REFERENCIA
                            // vert[j].stav=1;
                            cout << vert[j].verts; cout << vert[j].variref ; cout << vert[j].stav << endl;
                            int kp=0;
                            while (operadores[kp].funcao!=operatipo || operadores[kp].staop==1)
                            {   cout << operatipo << endl;
                                cout << operadores[kp].funcao << endl;
                                kp++;
                            }
                            cout << operadores[kp].funcao << endl;

                            operadores[kp].s1=vert1;
                            operadores[kp].s2=vert2;
                            operadores[kp].s3=vert3;
                            operadores[kp].staop=1;
                            refkp=kp;
                            cout << operadores[kp].funcao; cout << " ";cout << operadores[kp].s1; cout << ","; cout << operadores[kp].s2; cout << ","; cout << operadores[kp].s3; cout << ";" << endl;
                        } i++;
                    }

                    j=0;
                    while (vert[j].variref != var3x) j++;//-------------x-----19/4
                    cout << vert[j].variref << endl;
                    cout << vert[j].verts << endl;
                    while (vert[j].stav !=0) j++;
                    vert3=vert[j].verts;

                    forx[kf].tfs[t]=vert3;// SALVA VERTICE DE REFERENCIA
                    cout << forx[kf].tfs[t] << endl;

                    vert[j].stav=1;
                    cout << vert[j].verts; cout << vert[j].variref ; cout << vert[j].stav << endl;
                }
            if(forx[kf].indope!=0 || forx[kf].indvar==1){ko++;indexsimb++;indexsimb++;t++;} else ko=0;
        }
		if(forx[kf].atriacc==1)//------------------------------------------------------------------28/4
        {
            t=0;
            while(operadores[t].funcao!="acc")t++;
            operadores[t].funcao="branco";

            cout << operadores[refkp].funcao << endl;
            operadores[refkp].funcao="acc";
            operadores[refkp].s2=operadores[refkp].s3;
            operadores[refkp].s3="";
            cout << operadores[refkp].funcao; cout << " ";cout << operadores[refkp].s1; cout << ","; cout << operadores[refkp].s2; cout << ";" << endl;
        }                    //----------------------------------------------------------------------28/4
                                  		cout << "sai do geraopatri"  << endl;
    } else if(kf!=0){if(forx[kf].vetor==1)forx[kf-1].vetor=1;if(forx[kf].matrix==1)forx[kf-1].matrix=1;}
           else if(forx[kf].vetor==1 && forx[kf].atriacc==1)//--------------------------------------19/5
            {
                while (buffersimbol[indexsimb]!= '=') indexsimb--;
                cout << buffersimbol[indexsimb] << endl;
                indexsimb--;
                var3=buffersimbol[indexsimb];
                forx[kf].ztfs[t]=var3;cout << var3 << endl;
           }//----------------------------------------------------------------------------------------19/5
    }

    void atrifunc( int ki, int ks, int ka, refif *ifx,  seqope *sop, int indexsimb, char buffersimbol[],vertices *vert, operacao *opvar, asseline *operadores)
   {
        int auxindex=0;
        indexsimb=0; //cout << "entrei no =" << endl;
        //while (buffersimbol[indexsimb] != ';')indexsimb++;
        cout << "OPERACAO 6 DENTRO DO =" << endl;//cout << buffersimbol[indexsimb] << endl;
        auxindex=indexsimb; // MANTEM O ULTIMO INDEX DE SIMBOLO ATÉ AQUI.
        geraopatri(ki, ks, 0, ka, ifx,  sop, indexsimb, buffersimbol, vert, opvar, operadores);
        //ifx[ki].varz=operadores[ka].s3;
        indexsimb=auxindex;indexsimb++;cout << buffersimbol[indexsimb] << endl;
   }




void geraopatri(int ki, int ks, int torf, int ka, refif *ifx,  seqope *sop, int indexsimb, char buffersimbol[], vertices *vert, operacao *opvar, asseline *operadores)
{
    cout << "entrei na geraopatrif" << endl;
    string var1, var2, var3, var3x;
    string vert1,vert2,vert3;
    string operatipo;
    int t=0;
    int ko=0;

//            while (buffersimbol[indexsimb]!= '=') indexsimb--;
//            cout << buffersimbol[indexsimb] << endl;
//            indexsimb--;
//            var3=buffersimbol[indexsimb];
//            //if(ifx[ki].indvar==1)t++;
//            if(ka==1)t++;      //                                         AQUI ESTÁ UM PROBLEMA T=0 OU T=1
//            if(torf==0) ifx[ki].ztifs[t]=var3;
//            else ifx[ki].zfifs[t]=var3;
//            cout << buffersimbol[indexsimb] << endl;
//            cout << ifx[ki].zfifs[t] << endl;
//            cout << ifx[ki].ztifs[t] << endl;
            int j=0;
            int simbesp=0;
            int refindexsimb=0;
            int qtdop=0;
            indexsimb++;
            indexsimb++;
            refindexsimb=indexsimb;
            while (buffersimbol[indexsimb]!= ';')
            {
                if(buffersimbol[indexsimb]== '{' || buffersimbol[indexsimb]== '['|| buffersimbol[indexsimb]== '(')simbesp=1;
                if(buffersimbol[indexsimb]=='+' || buffersimbol[indexsimb]=='-' ||buffersimbol[indexsimb]=='*' ||buffersimbol[indexsimb]=='/' )qtdop++;
                indexsimb++;
            }
            indexsimb=refindexsimb;
            if(simbesp!=1 && qtdop==1)
            {
                var1=buffersimbol[indexsimb];
                cout << buffersimbol[indexsimb] << endl;
                indexsimb++;
                if (buffersimbol[indexsimb]=='+') operatipo="add";
                else if (buffersimbol[indexsimb]=='*') operatipo="mul";
                else if (buffersimbol[indexsimb]=='-') operatipo="sub";
                else operatipo="div";
                cout << buffersimbol[indexsimb] << endl;
                indexsimb++;
                var2=buffersimbol[indexsimb];
                cout << buffersimbol[indexsimb] << endl;
                indexsimb++;

                int j=0;
                int k=0;
                int i=0;
                j=0;
                while (vert[j].variref != var1) j++;
                cout << vert[j].variref << endl;
                while (vert[j].stav !=0) j++;
                vert1=vert[j].verts;
                // ifx[ki].tifs=vert1;  // SALVA VERTICE DE REFERENCIA
                vert[j].stav=1;
                cout << j;
                cout << "=";
                cout << vert[j].verts;
                cout << " ref ";
                cout << vert[j].variref ;
                cout << vert[j].stav << endl;


                i=0;
                j=0;
                while (vert[j].variref != var2) j++;
                cout << vert[j].variref << endl;
                while (vert[j].stav !=0) j++;
                vert2=vert[j].verts;
                //  ifx[ki].fifs=vert2; // SALVA VERTICE DE REFERENCIA
                vert[j].stav=1;
                cout << j;
                cout << "=";
                cout << vert[j].verts;
                cout << " ref ";
                cout << vert[j].variref ;
                cout << vert[j].stav << endl;
                i++;


                i=0;

                j=0;
                while (vert[j].variref != var3) j++;
                cout << j;
                cout << "=";
                cout << vert[j].verts;
                cout << " ref ";
                cout << vert[j].variref ;
                cout << vert[j].stav << endl;

//        cout << vert[j].variref << endl;
//        cout << vert[j].verts << endl;
                while (vert[j].stav !=0) j++;
                vert3=vert[j].verts;
                cout << j;
                cout << "=";
                cout << vert[j].verts;
                cout << " ref ";
                cout << vert[j].variref ;
                cout << vert[j].stav << endl;
                //if(ka==1)t++;  //--------------------------------------------------------------------------------
//                if(torf==0) ifx[ki].tifs[t]=vert3;
//                else ifx[ki].fifs[t]=vert3; // SALVA VERTICE DE REFERENCIA
//                cout << ifx[ki].tifs[t] << endl;
//                cout << ifx[ki].fifs[t] << endl;
                vert[j].stav=1;
                cout << j;
                cout << "=";
                cout << vert[j].verts;
                cout << " ref ";
                cout << vert[j].variref ;
                cout << vert[j].stav << endl;
                i++;

                int kp=0;
                while (operadores[kp].funcao!=operatipo || operadores[kp].staop==1)
                {
                    cout << operatipo << endl;
                    cout << operadores[kp].funcao << endl;
                    kp++;
                }
                cout << operadores[kp].funcao << endl;

                operadores[kp].s1=vert1;
                operadores[kp].s2=vert2;
                operadores[kp].s3=vert3;
                operadores[kp].staop=1;


                cout << operadores[kp].funcao;
                cout << " ";
                cout << operadores[kp].s1;
                cout << ",";
                cout << operadores[kp].s2;
                cout << ",";
                cout << operadores[kp].s3;
                cout << ";" << endl;


            }
            else
            {

                int    i=0;
                while (opvar[i].opera !="\n")
                {
                    cout << opvar[i].opera ;
                    cout << opvar[i].x1 ;
                    cout << opvar[i].x2 ;
                    cout << opvar[i].x3 ;
                    cout << opvar[i].staop << endl;
                    i++;
                }



                i=0;
                while (opvar[i].opera !="\n" && qtdop!=0)
                {
                    if(opvar[i].staop!=1)
                        if(opvar[i].opera=="add" || opvar[i].opera=="mul" || opvar[i].opera=="sub" ||opvar[i].opera=="div")
                        {
                            var1=opvar[i].x1;
                            cout << opvar[i].x1 << endl;
                            if (opvar[i].opera=="add") operatipo="add";
                            else if (opvar[i].opera=="mul") operatipo="mul";
                            else if (opvar[i].opera=="sub") operatipo="sub";
                            else if (opvar[i].opera=="div") operatipo="div";
                            cout << opvar[i].x1 << endl;
                            var2=opvar[i].x2;
                            cout << opvar[i].x2 << endl;
                            opvar[i].staop=1;
                            qtdop--;

                            int j=0;
                            int k=0;
                            j=0;
                            while (vert[j].variref != var1) j++;
                            cout << vert[j].variref << endl;
                            while (vert[j].stav !=0) j++;
                            vert1=vert[j].verts;
                            // ifx[ki].tifs=vert1;  // SALVA VERTICE DE REFERENCIA
                            vert[j].stav=1;
                            cout << vert[j].verts;
                            cout << vert[j].variref ;
                            cout << vert[j].stav << endl;




                            j=0;
                            while (vert[j].variref != var2) j++;
                            cout << vert[j].variref << endl;
                            while (vert[j].stav !=0) j++;
                            vert2=vert[j].verts;
                            //  ifx[ki].fifs=vert2; // SALVA VERTICE DE REFERENCIA
                            vert[j].stav=1;
                            cout << vert[j].verts;
                            cout << vert[j].variref ;
                            cout << vert[j].stav << endl;

                            j=0;
                            var3x=opvar[i].x3;
                            cout << opvar[i].x3 << endl;
                            while (vert[j].variref != var3x) j++;
                            cout << vert[j].variref << endl;
                            while (vert[j].stav !=0) j++;
                            vert3=vert[j].verts;
                            //  ifx[ki].fifs=vert2; // SALVA VERTICE DE REFERENCIA
                            // vert[j].stav=1;
                            cout << vert[j].verts;
                            cout << vert[j].variref ;
                            cout << vert[j].stav << endl;
                            int ky=0;
                            while (operadores[ky].funcao!=operatipo || operadores[ky].staop==1)
                            {
                                cout << operatipo << endl;
                                cout << operadores[ky].funcao << endl;
                                ky++;
                            }
                            cout << operadores[ky].funcao << endl;

                            operadores[ky].s1=vert1;
                            operadores[ky].s2=vert2;
                            operadores[ky].s3=vert3;
                            operadores[ky].staop=1;


                            cout << operadores[ky].funcao;
                            cout << " ";
                            cout << operadores[ky].s1;
                            cout << ",";
                            cout << operadores[ky].s2;
                            cout << ",";
                            cout << operadores[ky].s3;
                            cout << ";" << endl;


                        }
                    i++;
                }

                j=0;
                while (vert[j].variref != var3x) j++;//-------x-------19/4
                cout << vert[j].variref << endl;
                cout << vert[j].verts << endl;
                while (vert[j].stav !=0) j++;
                vert3=vert[j].verts;

                if(torf==0) ifx[ki].tifs[t]=vert3;
                else ifx[ki].fifs[t]=vert3; // SALVA VERTICE DE REFERENCIA
                cout << ifx[ki].tifs[t] << endl;
                cout << ifx[ki].fifs[t] << endl;
                vert[j].stav=1;
                cout << vert[j].verts;
                cout << vert[j].variref ;
                cout << vert[j].stav << endl;




            }
            if(ifx[ki].indope!=0 || ifx[ki].indvar==1)
            {
                ko++;
                indexsimb++;
                indexsimb++;
                t++;
            }
            else ko=0;
}









