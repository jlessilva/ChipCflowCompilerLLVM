#include "pairopera.h"
#include "varevertices.h"
#include "implfuncs.h"
#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void pairopera(int ki, int kf, int ks, refif *ifx, reffor *forx, seqope *sop, string funcao,operacao *opvar, varepsta *varep, vertices *vert, asseline *operador, defrefij *refiload, defrefij *refistore)
{
    int j;
    int i=0;
    int r=0;
    int t=0;
    string xref;
    string xrefn;
    string sref;
    string auxdm1,auxdm2,auxbran;
    string dpra,dmin,dpo,dout,a,d,da,we,spo,addr;
    string operef[2];
    int p;
    int k;
    int refp;
    int found=0;
    int foundex=0;
    int pris=0;
    int pril=0;
    int ksx=ks-1;
    int pridmerge=0;
    cout << "VERTS" << endl;
       i=0;
   while (vert[i].verts !="\n")
   {
       cout << i; cout << "="; cout << vert[i].verts; cout << " ref "; cout << vert[i].variref ; cout << vert[i].stav << endl;
       i++;
   }
    cout << "VAREP" << endl;

      i=0;
   while (varep[i].varrx !="\n")
   {
        cout << i; cout << "="; cout << varep[i].varrx; cout << varep[i].vrefv; cout << varep[i].varsta << endl;
        i++;
   }
   i=0;


    while (opvar[i].opera !=funcao) i++;
            cout << "valor de I = "; cout << i << endl;
            cout << "proxima operacao" ; cout << opvar[i].opera << endl;
             if (opvar[i].opera=="if")
             {
                int kix=0;
                while(kix!=ki)
                    {if(opvar[i].opera=="if") i++;
                     kix++;
                     }
                if(opvar[i].staop!=1)
                {
                xref=opvar[i].x1;
                j=0;
                while (vert[j].variref != xref) j++;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                vert[j].stav=1;
       cout << xref; cout << j; cout << "="; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref ; cout << vert[j].stav << endl;

                p=0;
                while (varep[p].varrx!=xref) p++;
                while (varep[p].varsta==1) p++;
                varep[p].vrefv=vert[j].variref;
                varep[p].varsta=1;
                opvar[i].staop=1;
        cout << "varep = "; cout << p; cout << " ";cout << varep[p].varrx; cout << " ";cout << varep[p].vrefv; cout << " "; cout << varep[p].varsta << endl;

                r=0;
                kix=0;
                cout << operador[r].funcao; cout << operador[r].staop << endl;;
                while(operador[r].funcao != "decider") r++;
                while(kix!=ki){r++; while(operador[r].funcao != "decider") r++;kix++;}
                while(operador[r].staop==1) r++;
                cout << operador[r].funcao; cout << operador[r].staop << endl;;
                operador[r].s1=vert[j].variref;

                xref=opvar[i].x2;
                j=0;         // TESTANDO VERT
                while (vert[j].variref != xref) j++;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                vert[j].stav=1;
       cout << xref; cout << j; cout << "="; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref ; cout << vert[j].stav << endl;

                p=0;          // TESTANDO VAREP
                while (varep[p].varrx!=xref) p++;
                while (varep[p].varsta==1) p++;
                varep[p].vrefv=vert[j].variref;
                varep[p].varsta=1;
        cout << "varep = "; cout << p; cout << " ";cout << varep[p].varrx; cout << " ";cout << varep[p].vrefv; cout << " "; cout << varep[p].varsta << endl;

                r=0;
                kix=0;
                cout << operador[r].funcao; cout << operador[r].staop << endl;;
                while(operador[r].funcao != "decider") r++;
                while(kix!=ki){r++; while(operador[r].funcao != "decider") r++;kix++;}
                while(operador[r].staop==1) r++;
                cout << operador[r].funcao; cout << operador[r].staop << endl;;
                operador[r].s2=vert[j].variref;

                if(ifx[ki].indope==0 && ifx[ki].indvar==0)
                {
                xref=ifx[ki].ztifs[t];
                j=0;         // TESTANDO VERT
                while (vert[j].variref != xref) j++;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                //vert[j].stav=1;
       cout << xref; cout << j; cout << "="; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref ; cout << vert[j].stav << endl;

                p=0;          // TESTANDO VAREP
                while (varep[p].varrx!=xref) {cout << varep[p].varrx << endl; p++;}
                while (varep[p].varsta==1) p++;
                varep[p].vrefv=operador[r].s3; //vert[j].variref;
                ifx[ki].ifctrl[t]=varep[p].vrefv;
                cout << ifx[ki].ifctrl[t] << endl;
                varep[p].varsta=1;
        cout << "varep = "; cout << p; cout << " ";cout << varep[p].varrx; cout << " ";cout << varep[p].vrefv; cout << " "; cout << varep[p].varsta << endl;
                     // AQUI EST� O PROBLEMA NA SEGUNDA RODADA DE IFFUNC

                r=0;
                kix=0;
                while(operador[r].funcao != "decider") r++;
                while(kix!=ki){r++; while(operador[r].funcao != "decider") r++;kix++;}
                while(operador[r].staop==1) r++;
                cout << operador[r].funcao; cout << operador[r].staop << endl;
                //operador[r].s3=vert[j].variref;
                operador[r].staop=1;
                cout << ifx[ki].ztifs[t] << endl;
                cout << operador[r].s3 << endl;
                } else
                {

                r=0;
                kix=0;
                while(operador[r].funcao != "decider") r++;
                while(kix!=ki){r++; while(operador[r].funcao != "decider") r++;kix++;}
                while(operador[r].staop==1) r++;
                cout << operador[r].funcao; cout << operador[r].staop;
                operador[r].s2=vert[j].variref;
                operador[r].staop=1;
                operador[r].s3=ifx[ki].varz;
                cout << operador[r].s3 << endl;//////////////////////////////////////////

                }

                if(ki!=0)ifx[ki-1].ztifs[t]=ifx[ki].ztifs[t];
 //               cout << ifx[ki-1].ztifs[t] << endl;
                }
                       cout << sop[ks].ope << endl;
//                int contope=0;
//                while(contope<ifx[ki].indope)
//                {

                r=0;
                t=0;
                cout << " INDVAR " ;cout << ifx[ki].indvar << endl;
                cout << " INDOPE " ;cout << ifx[ki].indope << endl;      // O PROBLEMA EST� AQUI
                int demergeok;
                if (ifx[ki].indvar==0)demergeok=1;
                if (ifx[ki].indope!=0)demergeok=ifx[ki].indope;
//                if (demergeok==0) demergeok=1;
//                else if(ifx[ki].indvar!=0) demergeok=ifx[ki].indope;
//                if(ifx[ki].indope==0) demergeok=1; else demergeok=ifx[ki].indope;
                while(demergeok!=0)
                {   cout << ifx[ki].indope << endl;
                    cout << ifx[ki].staif << endl;
                    found=1;
                    while(found)
                    { while(operador[r].funcao != "dmerged") r++;
                      if(operador[r].staop==1)r++; else found=0;
                    }
                    //if(operador[r].funcao=="dmerged")
                    //if(ifx[ki].indvar!=0)t++;
                    //{

                        cout << operador[r].funcao << endl;
//                while(operador[r].staop==1) r++;
                        cout << operador[r].staop << endl;
                        if(ks>=2 && sop[ks-1].ope=="for"){operador[r].s1=sop[ks-2].vref[t]; cout << operador[r].s1 << endl;}
                        else if(ifx[ki].staif==1 && ifx[ki].indope>0)
                                if(pridmerge==0)operador[r].s1=ifx[ki].tifs[t];
                                else operador[r].s1=ifx[ki].fifs[t];
                              else operador[r].s1=ifx[ki].tifs[t];
                              cout << operador[r].s1 << endl;

                        if(ifx[ki].staif==1 && ifx[ki].indope>0)
                            if(pridmerge==0) operador[r].s2=ifx[ki].fifs[t];
                            else operador[r].s2=ifx[ki].tifs[t];
                        else operador[r].s2=ifx[ki].fifs[t];
                        cout << operador[r].s2 << endl;
                        operador[r].s3=ifx[ki].ifctrl[t];cout << operador[r].s3 << endl;
                        if(ks>=2 && sop[ks-1].ope=="for"){operador[r].s4=sop[ks-2].varz[t]; cout << operador[r].s4 << endl;}
                        else if(ki==0)
                                {if(ksx>0)//-----------era != mudei >---19/4
                                    {if(sop[ksx-1].ope=="for")
                                        { sop[ksx-1].vref[t]=operador[r].s4;
                                            sop[ksx-1].varz[t]=ifx[ki].ztifs[t];
                                            cout << sop[ksx-1].vref[t] << endl;
                                            cout << sop[ksx-1].varz[t] << endl;
                                        }else operador[r].s4=ifx[ki].ztifs[t];
                                    }else operador[r].s4=ifx[ki].ztifs[t];
                                }
                                else ifx[ki-1].tifs[t]=operador[r].s4;
                            cout << operador[r].s4 << endl;




                        if(ki!=0) ifx[ki-1].tifs[t]=operador[r].s4;
//                cout << ifx[ki-1].tifs[t] << endl;
                        operador[r].staop=1;
//                cout << varep[p].varrx; cout << varep[p].vrefv; cout << varep[p].varsta << endl;
                        if(ifx[ki].indvar!=0 || ifx[ki].indope!=0)t++;
                        if(ifx[ki].indvar!=0 || ifx[ki].indope!=0)demergeok=demergeok-1; else demergeok=0;
//                contope++;
                        if(ifx[ki].staif==1 && ifx[ki].indope>0)pridmerge++;
                        r++;
                    //}
                }

//                }
             }
            if (opvar[i].opera=="for")
             {
                int kix=0;
                while(kix!=kf)
                    {if(opvar[i].opera=="for") i++;
                     kix++;
                     }
                if(opvar[i].staop!=1)
                {
                xref=opvar[i].x1;
                j=0;
                while (vert[j].variref != xref) j++;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                vert[j].stav=1;
       cout << xref; cout << j; cout << "="; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref ; cout << vert[j].stav << endl;

                p=0;
                while (varep[p].varrx!=xref) p++;
                while (varep[p].varsta==1) p++;
                varep[p].vrefv=vert[j].variref;
                varep[p].varsta=1;
                opvar[i].staop=1;
       cout << "varep = "; cout << p; cout << " ";cout << varep[p].varrx; cout << " ";cout << varep[p].vrefv; cout << " "; cout << varep[p].varsta << endl;

                r=0;
                kix=0;
                cout << operador[r].funcao; cout << operador[r].staop << endl;
                while(operador[r].funcao != "foricexx") r++;
                while(kix!=kf){r++; while(operador[r].funcao != "foricexx") r++;kix++;}
                while(operador[r].staop==1) r++;
                cout << operador[r].funcao; cout << operador[r].staop << endl;;
                operador[r].s2=vert[j].variref;//-----------------------------------------------------31/5



                xref=opvar[i].x2;
                xrefn=opvar[i].x2;
                j=0;         // TESTANDO VERT
                while (vert[j].variref != xref) j++;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                vert[j].stav=1;
       cout << xref; cout << j; cout << "="; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref ; cout << vert[j].stav << endl;

                p=0;          // TESTANDO VAREP
                while (varep[p].varrx!=xref) p++;
                while (varep[p].varsta==1) p++;
                varep[p].vrefv=vert[j].variref;
                varep[p].varsta=1;
       cout << "varep = "; cout << p; cout << " ";cout << varep[p].varrx; cout << " ";cout << varep[p].vrefv; cout << " "; cout << varep[p].varsta << endl;

       cout << forx[kf].forctrl[0] << endl;
       cout << forx[kf].forctrl[1] << endl;

                r=0;

                kix=0;
                cout << operador[r].funcao; cout << operador[r].staop << endl;
                while(operador[r].funcao != "foricexx") r++;
                while(kix!=kf){r++; while(operador[r].funcao != "foricexx") r++;kix++;}
                while(operador[r].staop==1) r++;
                cout << operador[r].funcao; cout << operador[r].staop << endl;
                operador[r].s1=vert[j].variref;//-------------------------------------------------------------31/5

                cout << forx[kf].vetor; cout << forx[kf].matrix << endl;
                if(forx[kf].vetor==1 || forx[kf].matrix==1)
                {
                    r=0;
                    kix=0;
                    cout << operador[r].funcao; cout << operador[r].staop << endl;
                    while(operador[r].funcao != "foricexx") r++;
                    while(kix!=kf){r++; while(operador[r].funcao != "foricexx") r++;kix++;}
                    while(operador[r].staop==1) r++;
                    cout << operador[r].funcao; cout << operador[r].staop << endl;
                    operador[r].s4=vert[j].variref; cout << operador[r].s4 << endl;
                    found=1;
                    k=0;
                    t=0;
                    while (found)
                    {   while(opvar[k].opera!="dualstore" && opvar[k].opera!="\n")k++;
                        if(opvar[k].opera!="\n")
                        {   foundex=1;
                            cout << opvar[i].x3; cout << opvar[k].x1; cout << opvar[k].x2; cout << opvar[k].x3 << endl;//------3/5
                            if(opvar[i].x3==opvar[k].x2 && opvar[k].stx2==0)
                            {
                                xref=opvar[i].x3;opvar[k].stx2=1; refistore[t].stai=0;
                            }
                            else if(opvar[i].x3==opvar[k].x3 && opvar[k].stx3==0)
                                    {
                                        xref=opvar[i].x3;opvar[k].stx3=1;refistore[t].staj=0;
                                    } else {foundex=0;k++;t++;}
                                //|| opvar[i].x3==opvar[k].x3)xref=opvar[i].x3; else found=0;//---------3/5
                            //xref=opvar[i].x3;----------------------------------------------------------3/5
                            if(foundex)
                            {cout << xref << endl;
                            j=0;
                            while (vert[j].variref != xref && vert[j].verts != "\n"){cout << vert[j].variref << endl; j++;}
                            cout << vert[j].verts << endl;
                            if(vert[j].verts != "\n")
                            {   j++;j++;vert[j].stav=1;
                                if( vert[j].variref != vert[j-1].variref )j--;
                                //while (vert[j].stav==1) j++;
                                //vert[j].stav=1;
                                cout << xref; cout << j; cout << "="; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref ; cout << vert[j].stav << endl;
                                while(vert[j].stav==1)j++;
                                vert[j].stav=1;
                                if(opvar[k].stx2==1 && refistore[t].stai!=1)//---------4/5
                                    {
                                        refistore[t].refi=vert[j].variref;
                                        cout << refistore[t].refi << endl;
                                        refistore[t].stai=1;
                                    }//------------------------------------------------------------------4/5
                                if(opvar[k].stx3==1 && refistore[t].staj!=1)
                                    {
                                        refistore[t].refj=vert[j].variref;
                                        cout << refistore[t].refj << endl;
                                        refistore[t].staj=1;
                                    }//--------------------------------------------------------------------4/5
                                t++;
                                p=0;
                                while (varep[p].varrx!=xref) p++;
                                while (varep[p].varsta==1) p++;
                                varep[p].vrefv=vert[j].variref;
                                varep[p].varsta=1;
                                opvar[i].staop=1;
                                cout << "varep = "; cout << p; cout << " ";cout << varep[p].varrx; cout << " ";cout << varep[p].vrefv; cout << " "; cout << varep[p].varsta << endl;


                                k++;
                            } else {operador[r].s4=xref; k++;}
                            }
                        } else found=0;
                    }

                    found=1;
                    k=0;
                    t=0;
                    while (found)
                    {   while(opvar[k].opera!="dualload" && opvar[k].opera!="\n")k++;
                        if(opvar[k].opera!="\n")
                        {   foundex=1;
                            cout << opvar[i].x3; cout << opvar[k].x1; cout << opvar[k].x2; cout << opvar[k].x3 << endl;
                            cout << opvar[k].stx2; cout << opvar[k].stx3 << endl;
                            if(opvar[i].x3==opvar[k].x2 && opvar[k].stx2==0)
                            {
                                xref=opvar[i].x3;opvar[k].stx2=1;refiload[t].stai=0;
                            }
                            else if(opvar[i].x3==opvar[k].x3 && opvar[k].stx3==0)
                                    {
                                        xref=opvar[i].x3;opvar[k].stx3=1; refiload[t].staj=0;
                                    } else {foundex=0;k++;t++;}
                            //if(opvar[i].x3==opvar[k].x2 || opvar[i].x3==opvar[k].x3)xref=opvar[i].x3;else found=0;//---------3/5
                            //xref=opvar[i].x3;//--------------------------------------------------------------3/5
                            if(foundex)
                            {cout << xref << endl;
                            j=0;
                            while (vert[j].variref != xref && vert[j].verts != "\n"){cout << vert[j].variref << endl; j++;}
                            cout << vert[j].verts << endl;
                            if(vert[j].verts != "\n")
                            {   j++;j++;vert[j].stav=1;
                                if( vert[j].variref != vert[j-1].variref )j--;
                                //while (vert[j].stav==1) j++;
                                //vert[j].stav=1;
                                cout << xref; cout << j; cout << "="; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref ; cout << vert[j].stav << endl;
                                while(vert[j].stav==1)j++;
                                vert[j].stav=1;
                                if(opvar[k].stx2==1 && refiload[t].stai!=1)//------------------------------------4/5
                                    {
                                        refiload[t].refi=vert[j].variref;
                                        cout << refiload[t].refi << endl;
                                        refiload[t].stai=1;
                                    }//-------------------------------------------------------------------------------4/5
                                if(opvar[k].stx3==1 && refiload[t].staj!=1)
                                    {
                                        refiload[t].refj=vert[j].variref;
                                        cout << refiload[t].refj << endl;
                                        refiload[t].staj=1;
                                    }//-----------------------------------------------------------------------------4/5
                                t++;
                                p=0;
                                while (varep[p].varrx!=xref) p++;
                                while (varep[p].varsta==1) p++;
                                varep[p].vrefv=vert[j].variref;
                                varep[p].varsta=1;
                                opvar[i].staop=1;
                                cout << "varep = "; cout << p; cout << " ";cout << varep[p].varrx; cout << " ";cout << varep[p].vrefv; cout << " "; cout << varep[p].varsta << endl;


                                k++;
                            } else {operador[r].s4=xref; k++;}
                            }
                        } else found=0;
                    }

                }

                t=0;
                xref=opvar[i].x3;
                cout << xref << endl;
                j=0;
                while (vert[j].variref != xref && vert[j].verts != "\n"){cout << vert[j].variref << endl; j++;}
                cout << vert[j].verts << endl;
                if(vert[j].verts != "\n")
                {   j++;j++;vert[j].stav=1;
                    if( vert[j].variref != vert[j-1].variref )j--;
                    //while (vert[j].stav==1) j++;
                    //vert[j].stav=1;
                    cout << xref; cout << j; cout << "="; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref ; cout << vert[j].stav << endl;
                    //while(vert[j].stav==1)j++;
                    //refilost=vert[j].variref;
                    p=0;
                    while (varep[p].varrx!=xref) p++;
                    while (varep[p].varsta==1) p++;
                    varep[p].vrefv=vert[j].variref;
                    varep[p].varsta=1;
                    opvar[i].staop=1;
                    cout << "varep = "; cout << p; cout << " ";cout << varep[p].varrx; cout << " ";cout << varep[p].vrefv; cout << " "; cout << varep[p].varsta << endl;

                    r=0;
                    kix=0;
                    cout << operador[r].funcao; cout << operador[r].staop << endl;
                    while(operador[r].funcao != "foricexx") r++;
                    while(kix!=kf){r++; while(operador[r].funcao != "foricexx") r++;kix++;}
                    while(operador[r].staop==1) r++;
                    cout << operador[r].funcao; cout << operador[r].staop << endl;;
                    operador[r].s4=vert[j].variref;
                } else operador[r].s4=xref;
                cout << operador[r].s4 << endl;

                //if(forx[kf].indope==0 && forx[kf].indvar==0)
                //{

            if(forx[kf].indope==0 && forx[kf].indvar==0 && forx[kf].aninha==0)
            {
                if(opvar[i].vetor==1 || opvar[i].matrix==1)
                {
                    found=1;
                    k=0;
                    t=0;
                    while (found)
                    {
                        while(operador[k].funcao!="dualstore" && operador[k].funcao!="\n")k++;
                        if(operador[k].funcao!="\n")
                        {
                            xref='Z';
                            cout << xref << endl;
                            j=0;
                            while (vert[j].variref != xref && vert[j].verts != "\n")
                            {
                                cout << vert[j].variref << endl;
                                j++;
                            }
                            cout << vert[j].verts << endl;
                            if(vert[j].verts != "\n")
                            {
                                j++;
                                j++;
                                vert[j].stav=1;
                                if( vert[j].variref != vert[j-1].variref )j--;
                                //while (vert[j].stav==1) j++;
                                //vert[j].stav=1;
                                cout << xref;
                                cout << j;
                                cout << "=";
                                cout << vert[j].verts;
                                cout << " ref ";
                                cout << vert[j].variref ;
                                cout << vert[j].stav << endl;
                                while(vert[j].stav==1)j++;
                                vert[j].stav=1;
                                operador[k].s1=vert[j].variref;
                                cout << operador[k].s1 << endl;
                                p=0;
                                while (varep[p].varrx!=xref) p++;
                                while (varep[p].varsta==1) p++;
                                varep[p].vrefv=vert[j].variref;
                                varep[p].varsta=1;
                                opvar[i].staop=1;
                                cout << "varep = ";
                                cout << p;
                                cout << " ";
                                cout << varep[p].varrx;
                                cout << " ";
                                cout << varep[p].vrefv;
                                cout << " ";
                                cout << varep[p].varsta << endl;
                                while(vert[j].stav==1)j++;
                                vert[j].stav=1;
                                operador[k].s2=vert[j].variref;
                                cout << operador[k].s2 << endl;
                                p=0;
                                while (varep[p].varrx!=xref) p++;
                                while (varep[p].varsta==1) p++;
                                varep[p].vrefv=vert[j].variref;
                                varep[p].varsta=1;
                                opvar[i].staop=1;
                                cout << "varep = ";
                                cout << p;
                                cout << " ";
                                cout << varep[p].varrx;
                                cout << " ";
                                cout << varep[p].vrefv;
                                cout << " ";
                                cout << varep[p].varsta << endl;


                                k++;
                            }
                            else
                            {
                                operador[r].s4=xref;
                                k++;
                            }
                        }
                        else found=0;
                    }

                    found=1;
                    k=0;
                    t=0;
                    while (found)
                    {
                        while(operador[k].funcao!="dualload" && operador[k].funcao!="\n")k++;
                        if(operador[k].funcao!="\n")
                        {
                            xref='Z';
                            cout << xref << endl;
                            j=0;
                            while (vert[j].variref != xref && vert[j].verts != "\n")
                            {
                                cout << vert[j].variref << endl;
                                j++;
                            }
                            cout << vert[j].verts << endl;
                            if(vert[j].verts != "\n")
                            {
                                j++;
                                j++;
                                vert[j].stav=1;
                                if( vert[j].variref != vert[j-1].variref )j--;
                                //while (vert[j].stav==1) j++;
                                //vert[j].stav=1;
                                cout << xref;
                                cout << j;
                                cout << "=";
                                cout << vert[j].verts;
                                cout << " ref ";
                                cout << vert[j].variref ;
                                cout << vert[j].stav << endl;
                                while(vert[j].stav==1)j++;
                                vert[j].stav=1;
                                operador[k].s1=vert[j].variref;
                                cout << operador[k].s1 << endl;
                                p=0;
                                while (varep[p].varrx!=xref) p++;
                                while (varep[p].varsta==1) p++;
                                varep[p].vrefv=vert[j].variref;
                                varep[p].varsta=1;
                                opvar[i].staop=1;
                                cout << "varep = ";
                                cout << p;
                                cout << " ";
                                cout << varep[p].varrx;
                                cout << " ";
                                cout << varep[p].vrefv;
                                cout << " ";
                                cout << varep[p].varsta << endl;
                                while(vert[j].stav==1)j++;
                                vert[j].stav=1;
                                operador[k].s2=vert[j].variref;
                                cout << operador[k].s2 << endl;
                                p=0;
                                while (varep[p].varrx!=xref) p++;
                                while (varep[p].varsta==1) p++;
                                varep[p].vrefv=vert[j].variref;
                                varep[p].varsta=1;
                                opvar[i].staop=1;
                                cout << "varep = ";
                                cout << p;
                                cout << " ";
                                cout << varep[p].varrx;
                                cout << " ";
                                cout << varep[p].vrefv;
                                cout << " ";
                                cout << varep[p].varsta << endl;


                                k++;
                            }
                            else
                            {
                                operador[r].s4=xref;
                                k++;
                            }
                        }
                        else found=0;
                    }
                } else if(kf==0 && forx[kf].ultimo==1)forx[kf].ctrlf=operador[r].s3;

                /*
                forx[kf].ctrlf=operador[r].s3;
                xref=forx[kf].ctrlf;
                cout << xref << endl;
                j=0;         // TESTANDO VERT
                while (vert[j].verts != xref) j++;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                vert[j].stav=1;
                cout << xref;
                cout << j;
                cout << "=";
                cout << vert[j].verts;
                cout << " ref ";
                cout << vert[j].variref ;
                cout << vert[j].stav << endl;

                //p=0;          // TESTANDO VAREP
                //while (varep[p].vrefv!=xref) {cout << varep[p].vrefv << endl; p++;}
                //while (varep[p].varsta==1) p++;
                //varep[p].vrefv=operador[r].s3; //vert[j].variref;
                forx[kf].forctrl[t]=operador[r].s3;
                cout << forx[kf].forctrl[t] << endl;
                varep[p].varsta=1;
                cout << "varep = ";
                cout << p;
                cout << " ";
                cout << varep[p].varrx;
                cout << " ";
                cout << varep[p].vrefv;
                cout << " ";
                cout << varep[p].varsta << endl;
                */
            }
            else if(forx[kf].indope==0 && forx[kf].indvar==0 && forx[kf].aninha==1)
            {
                cout << forx[kf].aninha << endl;
                if(opvar[i].vetor==1 || opvar[i].matrix==1)
                {
                    found=1;
                    k=0;
                    t=0;
                    while (found)
                    {
                        while(operador[k].funcao!="dualstore" && operador[k].funcao!="\n")k++;
                        if(operador[k].funcao!="\n")
                        {
                            xref='Z';
                            cout << xref << endl;
                            j=0;
                            while (vert[j].variref != xref && vert[j].verts != "\n")
                            {
                                cout << vert[j].variref << endl;
                                j++;
                            }
                            cout << vert[j].verts << endl;
                            if(vert[j].verts != "\n")
                            {
                                j++;
                                j++;
                                vert[j].stav=1;
                                if( vert[j].variref != vert[j-1].variref )j--;
                                //while (vert[j].stav==1) j++;
                                //vert[j].stav=1;
                                cout << xref;
                                cout << j;
                                cout << "=";
                                cout << vert[j].verts;
                                cout << " ref ";
                                cout << vert[j].variref ;
                                cout << vert[j].stav << endl;
                                while(vert[j].stav==1)j++;
                                vert[j].stav=1;
                                operador[k].s1=vert[j].variref;
                                cout << operador[k].s1 << endl;
                                p=0;
                                while (varep[p].varrx!=xref) p++;
                                while (varep[p].varsta==1) p++;
                                varep[p].vrefv=vert[j].variref;
                                varep[p].varsta=1;
                                opvar[i].staop=1;
                                cout << "varep = ";
                                cout << p;
                                cout << " ";
                                cout << varep[p].varrx;
                                cout << " ";
                                cout << varep[p].vrefv;
                                cout << " ";
                                cout << varep[p].varsta << endl;
                                /*while(vert[j].stav==1)j++;
                                vert[j].stav=1;
                                operador[k].s2=vert[j].variref;
                                cout << operador[k].s2 << endl;
                                p=0;
                                while (varep[p].varrx!=xref) p++;
                                while (varep[p].varsta==1) p++;
                                varep[p].vrefv=vert[j].variref;
                                varep[p].varsta=1;
                                opvar[i].staop=1;
                                cout << "varep = ";
                                cout << p;
                                cout << " ";
                                cout << varep[p].varrx;
                                cout << " ";
                                cout << varep[p].vrefv;
                                cout << " ";
                                cout << varep[p].varsta << endl;
                                */


                                k++;
                            }
                            else
                            {
                                operador[r].s4=xref;
                                k++;
                            }
                        }
                        else found=0;
                    }

                    found=1;
                    k=0;
                    t=0;
                    while (found)
                    {
                        while(operador[k].funcao!="dualload" && operador[k].funcao!="\n")k++;
                        if(operador[k].funcao!="\n")
                        {
                            xref='Z';
                            cout << xref << endl;
                            j=0;
                            while (vert[j].variref != xref && vert[j].verts != "\n")
                            {
                                cout << vert[j].variref << endl;
                                j++;
                            }
                            cout << vert[j].verts << endl;
                            if(vert[j].verts != "\n")
                            {
                                j++;
                                j++;
                                vert[j].stav=1;
                                if( vert[j].variref != vert[j-1].variref )j--;
                                //while (vert[j].stav==1) j++;
                                //vert[j].stav=1;
                                cout << xref;
                                cout << j;
                                cout << "=";
                                cout << vert[j].verts;
                                cout << " ref ";
                                cout << vert[j].variref ;
                                cout << vert[j].stav << endl;
                                while(vert[j].stav==1)j++;
                                vert[j].stav=1;
                                operador[k].s1=vert[j].variref;
                                cout << operador[k].s1 << endl;
                                p=0;
                                while (varep[p].varrx!=xref) p++;
                                while (varep[p].varsta==1) p++;
                                varep[p].vrefv=vert[j].variref;
                                varep[p].varsta=1;
                                opvar[i].staop=1;
                                cout << "varep = ";
                                cout << p;
                                cout << " ";
                                cout << varep[p].varrx;
                                cout << " ";
                                cout << varep[p].vrefv;
                                cout << " ";
                                cout << varep[p].varsta << endl;
                                /*while(vert[j].stav==1)j++;
                                vert[j].stav=1;
                                operador[k].s2=vert[j].variref;
                                cout << operador[k].s2 << endl;
                                p=0;
                                while (varep[p].varrx!=xref) p++;
                                while (varep[p].varsta==1) p++;
                                varep[p].vrefv=vert[j].variref;
                                varep[p].varsta=1;
                                opvar[i].staop=1;
                                cout << "varep = ";
                                cout << p;
                                cout << " ";
                                cout << varep[p].varrx;
                                cout << " ";
                                cout << varep[p].vrefv;
                                cout << " ";
                                cout << varep[p].varsta << endl;
                                */


                                k++;
                            }
                            else
                            {
                                operador[r].s4=xref;
                                k++;
                            }
                        }
                        else found=0;
                    }
                }

                /*forx[kf].ctrlf=operador[r].s3;
                xref=forx[kf].ctrlf;
                cout << xref << endl;
                j=0;         // TESTANDO VERT
                while (vert[j].verts != xref) j++;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                vert[j].stav=1;
                cout << xref;
                cout << j;
                cout << "=";
                cout << vert[j].verts;
                cout << " ref ";
                cout << vert[j].variref ;
                cout << vert[j].stav << endl;

                //p=0;          // TESTANDO VAREP
                //while (varep[p].vrefv!=xref) {cout << varep[p].vrefv << endl; p++;}
                //while (varep[p].varsta==1) p++;
                //varep[p].vrefv=operador[r].s3; //vert[j].variref;
                forx[kf].forctrl[t]=operador[r].s3;
                cout << forx[kf].forctrl[t] << endl;
                varep[p].varsta=1;
                cout << "varep = ";
                cout << p;
                cout << " ";
                cout << varep[p].varrx;
                cout << " ";
                cout << varep[p].vrefv;
                cout << " ";
                cout << varep[p].varsta << endl;
                // AQUI EST� O PROBLEMA NA SEGUNDA RODADA DE IFFUNC
                */
            }
            else
            {
                if(forx[kf].ultimo!=0 && forx[kf].indope!=0)
                {
                    xref=forx[kf].ctrlf;
                    cout << xref << endl;
                    operador[r].s3=xref;

                }
            }

                if(forx[kf].ultimo!=0)
                {
                xref="B"; //forx[kf].ctrlf; //"$";
                cout << xref << endl;
                j=0;         // TESTANDO VERT
                while (vert[j].variref != xref) j++;
                vert[j].stav=1;
                j++;
                //if(kf==0)j++;
                //else
				//while (vert[j].stav==1) j++;
                //if(kf!=0)vert[j].stav=1;
       cout << xref; cout << j; cout << "="; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref ; cout << vert[j].stav << endl;

                p=0;          // TESTANDO VAREP  -------------------------------------------------10/6
                while (varep[p].varrx!=xref) {cout << p; cout << varep[p].varrx; cout << varep[p].varsta << endl; p++;}
                while (varep[p].varsta==1) p++;
                while (vert[j].stav==1)j++;
                cout << vert[j].verts << endl;
                vert[j].stav=1;
                varep[p].vrefv=vert[j].verts;
                forx[kf].cxfor=varep[p].vrefv;
                operador[r].s5=forx[kf].cxfor;
                cout << forx[kf].cxfor << endl;
                varep[p].varsta=1;j++;
                //vert[j].stav=1;
       cout << "varep = "; cout << p; cout << " ";cout << varep[p].varrx; cout << " ";cout << varep[p].vrefv; cout << " "; cout << varep[p].varsta << endl;
                while (vert[j].stav==1)j++;
                cout << vert[j].verts << endl;
                vert[j].stav=1;
                varep[p].vrefv=vert[j].verts;
                forx[kf].cxxfor=varep[p].vrefv;
                operador[r].s6=forx[kf].cxxfor;
                cout << forx[kf].cxxfor << endl;
                varep[p].varsta=1;j++;
                //vert[j].stav=1;
       cout << "varep = "; cout << p; cout << " ";cout << varep[p].varrx; cout << " ";cout << varep[p].vrefv; cout << " "; cout << varep[p].varsta << endl;
                if(kf!=0) forx[kf-1].ultimo=0;
                } else
                    {

                        j=0;
                        while(vert[j].verts!="\n")
                        {cout << j; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref; cout << vert[j].stav << endl;j++;}
                        if(kf!=0)
                            {   xref="B"; //forx[kf].ctrlf; //"$";---------------------------11/6
                                cout << xref << endl;
                                j=0;         // TESTANDO VERT
                                while (vert[j].variref != xref) j++;
                                while (vert[j].stav==1)j++;
                                cout << vert[j].verts << endl;
                                vert[j].stav=1;
                                varep[p].vrefv=vert[j].verts;
                                forx[kf].cxxfor=varep[p].vrefv;
                                operador[r].s6=forx[kf].cxxfor;
                                cout << forx[kf].cxxfor << endl;
                                varep[p].varsta=1;j++;
                cout << "varep = "; cout << p; cout << " ";cout << varep[p].varrx; cout << " ";cout << varep[p].vrefv; cout << " "; cout << varep[p].varsta << endl;
                            } else
                                if(ks<=2)
                                {   xref="B"; //forx[kf].ctrlf; //"$";---------------------------11/6
                                    cout << xref << endl;
                                    j=0;         // TESTANDO VERT
                                    while (vert[j].variref != xref) j++;
                                    while (vert[j].stav==1)j++;
                                    cout << vert[j].verts << endl;
                                    vert[j].stav=1;
                                    varep[p].vrefv=vert[j].verts;
                                    forx[kf].cxxfor=varep[p].vrefv;
                                    operador[r].s6=forx[kf].cxxfor;
                                    cout << forx[kf].cxxfor << endl;
                                    varep[p].varsta=1;j++;
                        cout << "varep = "; cout << p; cout << " ";cout << varep[p].varrx; cout << " ";cout << varep[p].vrefv; cout << " "; cout << varep[p].varsta << endl;
                                }
                        //operador[r].s5=forx[kf].cxfor; cout << forx[kf].cxfor << endl;-----------------10/6
                    }

                 cout << forx[kf].cxxfor << endl;
                 cout << forx[kf].cxfor << endl;

                 cout << forx[kf].forctrl[0] << endl;
                 cout << forx[kf].forctrl[1] << endl;

                r=0;
                kix=0;
                while(operador[r].funcao != "foricexx") r++;
                while(kix!=kf){r++; while(operador[r].funcao != "foricexx") r++;kix++;}
                while(operador[r].staop==1) r++;
                cout << operador[r].funcao; cout << operador[r].staop << endl;
                //operador[r].s3=vert[j].variref;
               //operador[r].staop=1;
                cout << forx[kf].ctrlf << endl;
                if(kf!=0 && forx[kf].ultimo==1 && forx[kf].atriacc==0)
                {       operador[r].s3=forx[kf].ctrlf;
                        if(kf>=2) operador[r+2].s1=operador[r+1].s2;
                        operador[r+1].staop=1;
                        if(kf>=2) operador[r+2].staop=1;
                        xref=operador[r].s3;
                        cout << xref << endl;
                        j=0;         // TESTANDO VERT
                        while (vert[j].verts != xref) j++;
                        j++;
                        xref=vert[j].verts;
                cout << xref; cout << j; cout << "="; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref ; cout << vert[j].stav << endl;
                        if(forx[kf].matrix!=1 && forx[kf].vetor!=1)
                        {
                            if(kf>=2)forx[kf-1].cxfor=operador[r+2].s2; else forx[kf-1].cxfor=operador[r+1].s2; //---12/4--13/4--
                            if(kf>=2)forx[kf-2].cxxfor=operador[r+2].s3;
                            //cout << forx[kf-1].cxfor << endl;
                            //cout << forx[kf-2].cxxfor << endl;
                        }

                        if(forx[kf].matrix==1 || forx[kf].vetor==1)//-----------------------------------------------------15/6
                            {
                                if(kf>=2)forx[kf-1].cxfor=operador[r+2].s2; else forx[kf-1].cxfor=operador[r+1].s2; //---12/4--13/4--
                                if(kf>=2)forx[kf-2].cxxfor=operador[r+2].s3;
                                                //cout << forx[kf-1].cxfor << endl;
                                                //cout << forx[kf-2].cxxfor << endl;
                            }  //            forx[kf-1].cxfor=xref ; //---------------------10/5--------------------15/6
                        //if(forx[kf].atriacc==1) forx[kf-1].cxfor=xref;//----------------------------------------------6/5---15/6
                        j++;
                        xref=vert[j].verts;
                        forx[kf].forctrl[t]=xref ;//rador[r].s3;
                        cout << forx[kf].forctrl[t] << endl;
                        varep[p].varsta=1;
                cout << "varep = "; cout << p; cout << " ";cout << varep[p].varrx; cout << " ";cout << varep[p].vrefv; cout << " "; cout << varep[p].varsta << endl;

                } else
                    if(kf!=0 && forx[kf].ultimo==1 && forx[kf].atriacc==1)
                    {       operador[r].s3=forx[kf].ctrlf;
                            if(kf>=2) operador[r+3].s1=operador[r+2].s2; operador[r+2].staop=1;
                                      operador[r+2].s1=operador[r+1].s2; operador[r+1].staop=1;
                            if(kf>=2) operador[r+3].staop=1;
                            xref=operador[r+2].s2;
                            cout << xref << endl;
                            cout << operador[r+3].s1 << endl;
                            cout << operador[r+2].s1 << endl;

                            j=0;         // TESTANDO VERT
                            while (vert[j].verts != xref) j++;
                            j++;
                            xref=vert[j].verts;
                    cout << xref; cout << j; cout << "="; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref ; cout << vert[j].stav << endl;
                            if(forx[kf].matrix!=1 && forx[kf].vetor!=1)
                            {
                                if(kf>=2)forx[kf-1].cxfor=operador[r+2].s2; else forx[kf-1].cxfor=operador[r+1].s2; //---12/4--13/4--
                                if(kf>=2)forx[kf-2].cxxfor=operador[r+2].s3;
                            //cout << forx[kf-1].cxfor << endl;
                            //cout << forx[kf-2].cxxfor << endl;
                            }

                        if(forx[kf].matrix==1 || forx[kf].vetor==1)//-----------------------------------------------------15/6
                            {
                                if(kf>=2)forx[kf].cxacc=operador[r+1].s3;
                                if(kf>=2)forx[kf-1].cxfor=operador[r+3].s2; else forx[kf-1].cxfor=operador[r+2].s2; //---12/4--13/4--
                                if(kf>=2)forx[kf-2].cxxfor=operador[r+3].s3;
                                                cout << forx[kf].cxacc << endl;
                                                cout << forx[kf-1].cxfor << endl;
                                                cout << forx[kf-2].cxxfor << endl;
                            }  //            forx[kf-1].cxfor=xref ; //---------------------10/5--------------------15/6
                        //if(forx[kf].atriacc==1) forx[kf-1].cxfor=xref;//----------------------------------------------6/5---15/6
                        //j++;
                        //xref=vert[j].verts;
                        forx[kf].forctrl[t]=xref ;//rador[r].s3;
                        cout << forx[kf].forctrl[t] << endl;
                        varep[p].varsta=1;
                cout << "varep = "; cout << p; cout << " ";cout << varep[p].varrx; cout << " ";cout << varep[p].vrefv; cout << " "; cout << varep[p].varsta << endl;

                } else
                    if(kf!=0 && forx[kf].ultimo==0)
                    {   operador[r].s3=forx[kf].ctrlf;
                        xref=forx[kf].ctrlf;
                        cout << xref << endl;
                        j=0;         // TESTANDO VERT
                        while (vert[j].verts != xref) j++;
                        j++;
                        xref=vert[j].verts;
                cout << xref; cout << j; cout << "="; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref ; cout << vert[j].stav << endl;
                        if(kf==1)forx[kf-1].cxfor=xref ;//rador[r].s3;---------------------11/6
                        cout << forx[kf-1].cxfor << endl;
                        j++; //vert[j].stav=1;--------------------------------------------11/6
                        xref=vert[j].verts;
                        forx[kf].forctrl[t]=xref ;//rador[r].s3;
                        cout << forx[kf].forctrl[t] << endl;
                        varep[p].varsta=1;
                cout << "varep = "; cout << p; cout << " ";cout << varep[p].varrx; cout << " ";cout << varep[p].vrefv; cout << " "; cout << varep[p].varsta << endl;
                        operador[r].s5=forx[kf].cxfor; cout << operador[r].s5 << endl;
                        operador[r+1].staop=1;
                        operador[r+2].staop=0;
                    } //else
                        //if(kf==0 && forx[kf].ultimo==1)
                        //{   //operador[r].s3=forx[kf].ctrlf;
                            //xref=forx[kf].ctrlf;
                            //cout << xref << endl;
                            //j=0;         // TESTANDO VERT
                            //while (vert[j].verts != xref) j++;
                            //j++;
                            //xref=vert[j].verts;
                            //cout << xref; cout << j; cout << "="; cout << vert[j].verts; cout << " ref "; cout << vert[j].variref ; cout << vert[j].stav << endl;
                            //forx[kf-1].cxfor=xref ;//rador[r].s3;
                            //j++; //vert[j].stav=1;
                            //xref=vert[j].verts;
                          //  forx[kf].forctrl[t]=operador[r].s3 ;//rador[r].s3;
                          //  cout << forx[kf].forctrl[t] << endl;
                            //varep[p].varsta=1;
                            //cout << "varep = "; cout << p; cout << " ";cout << varep[p].varrx; cout << " ";cout << varep[p].vrefv; cout << " "; cout << varep[p].varsta << endl;
                        //}


                        //forx[kf].forctrl[t]=operador[r].s3; cout << forx[kf].forctrl[t] << endl;}
                    else {
                            if(kf==0 && forx[kf].indope==0 && forx[kf].matrix!=1 && forx[kf].vetor!=1)
                            {forx[kf].forctrl[t]=forx[kf].ctrlf;operador[r].s3=forx[kf].ctrlf; operador[r].s5=forx[kf].cxfor; operador[r].s6=forx[kf].cxxfor;  cout << forx[kf].forctrl[t]; cout << forx[kf].ctrlf; cout << forx[kf].cxfor;cout << forx[kf].cxxfor << endl;}
                            if(kf==0 && (forx[kf].matrix==1 || forx[kf].vetor==1)&& ks==3)
                            {t=0;forx[kf].forctrl[t]=operador[r].s3;operador[r].s5=forx[kf].cxfor; operador[r].s6=forx[kf].cxxfor; cout << forx[kf].forctrl[t]; cout << forx[kf].ctrlf; cout << forx[kf].cxfor;cout << forx[kf].cxxfor << endl;}
                            if(kf==0 && forx[kf].indope!=0 && forx[kf].matrix!=1 && forx[kf].vetor!=1){cout << forx[kf].forctrl[t]; cout << forx[kf].ctrlf; cout << forx[kf].cxfor;}
                            else {t=0;forx[kf].forctrl[t]=operador[r].s3;operador[r].s5=forx[kf].cxfor;cout << forx[kf].forctrl[t]; cout << forx[kf].ctrlf; cout << forx[kf].cxfor;}
                         }
                cout << operador[r].s3 << endl;
                operador[r].staop=1;

                if(kf!=0)forx[kf-1].ztfs[t]=forx[kf].ztfs[t];
                cout << forx[kf-1].ztfs[t] << endl;
                }

//                int contope=0;
//                while(contope<ifx[ki].indope)
//                {

                        cout << operador[r].staop << endl;
                       // operador[r].s3=forx[kf].outz;
                r=0;
                t=0;

                cout << " INDVAR " ;cout << forx[kf].indvar << endl;
                cout << " INDOPE " ;cout << forx[kf].indope << endl;      // O PROBLEMA EST� AQUI

        if(forx[kf].vetor==1 || forx[kf].matrix==1)
        {
            int rref=0;
            int finish=1;
            found=1;
            t=0;
            k=0;
            while(operador[r].funcao !="\n" && finish)
            {
                found=1;
                while(found)
                {
                    while(operador[r].funcao != "dualload" && operador[r].funcao!="\n") r++;
                    if(operador[r].staop==1 && operador[r].funcao!="\n")r++;
                    else
                    {
                        found=0;
                        if(kf==0)operador[r].staop=1;
                    }
                }
                //if(ifx[ki].indvar!=0)t++;
                //{
                if(operador[r].funcao!="\n" && finish)
                {
                    cout << operador[r].funcao << endl;
                    dpra=operador[r].s5;
                    cout << dpra << endl;
                    dmin=operador[r].s6;
                    cout << dmin << endl;
//                      dpo=operador[r].s7;  cout << dpo << endl;
                    cout << forx[kf].tfs[t] << endl;
                    if(forx[kf].matrix==1 && kf==1 && forx[kf].atriacc!=1)forx[kf].tfs[t]=operador[r].s7;//--------6/5
                    cout << forx[kf].vetor << endl;
                    cout << forx[kf].tfs[t] << endl;
                    if(forx[kf].vetor==1 && kf==0 && forx[kf].atriacc!=1)forx[kf].tfs[t]=operador[r].s7;//--------6/5---11/5
                    cout << forx[kf].tfs[t] << endl;
                    cout << operador[r].s7 << endl;//--------------------------------------------------------------------11/5
                    if(forx[kf].vetor==1 && kf==0 && forx[kf].atriacc==1)forx[kf].tfs[t]=operador[r].s7;//--------19/5
                    cout << forx[kf].tfs[t] << endl;
                    cout << operador[r].s7 << endl;//--------------------------------------------------------------------16/5

                    if(forx[kf].vetor==1)//--------------------------------------------------------------------11/5
                        //operador[r].s3=refiload[t].refj;//------------------------------------------4/5
                        operador[r].s3=refiload[t].refi;//------------------------------------------4/5
                    //else operador[r].s3=refiload[t];//--------------------------------------------4/5-------11/5
                    cout << operador[r].s3 << endl;
                    cout << operador[r].s2 << endl;


                    if(forx[kf].vetor==1)//--------------------------------------------------------19/5
                    operef[k]=operador[r].s7;//-------------------------------------------------19/5


                    if(forx[kf].matrix==1)
                        {operador[r].s3=refiload[t].refj;//------------------------------------------4/5
                        operador[r].s2=refiload[t].refi;}//------------------------------------------4/5
                    //else operador[r].s3=refiload[t];//--------------------------------------------4/5
                    cout << operador[r].s3 << endl;
                    cout << operador[r].s2 << endl;
                    operef[k]=operador[r].s7;
                    cout << operef[k] << endl;
                    t++;
                    rref=r;
                }

                if(kf==0)
                {
                    found=1;
                    while(found)
                    {
                        while(operador[r].funcao != "dualsram" && operador[r].funcao!="\n") r++;
                        if(operador[r].staop==1 && operador[r].funcao!="\n")r++;
                        else
                        {
                            found=0;
                            if(kf==0)operador[r].staop=1;
                        }
                    }
                    if(operador[r].funcao!="\n" && finish)
                    {
                        cout << operador[r].funcao << endl;
                        operador[r].s1=dpra;
                        cout << operador[r].s1 << endl;
                        //operador[r].s2=dmin;  cout << operador[r].s2 << endl;
                        operador[rref].s6=operador[r].s5;
                        cout << operador[r].s5 << endl;
                        r++;
                        k++;
                        //t++;

                        j=0;         // TESTANDO VERT
                        while (vert[j].variref != xrefn) j++;
                        vert[j].stav=1;
                        while (vert[j].stav==1) j++;
                        vert[j].stav=1;
                        cout << xrefn;
                        cout << j;
                        cout << "=";
                        cout << vert[j].verts;
                        cout << " ref ";
                        cout << vert[j].variref ;
                        cout << vert[j].stav << endl;
                        operador[rref].s4=vert[j].variref;
                        cout << operador[rref].funcao;
                        cout << operador[rref].s4 << endl;

                        p=0;          // TESTANDO VAREP
                        while (varep[p].varrx!=xrefn) p++;
                        while (varep[p].varsta==1) p++;
                        varep[p].vrefv=vert[j].variref;
                        varep[p].varsta=1;
                        cout << "varep = ";
                        cout << p;
                        cout << " ";
                        cout << varep[p].varrx;
                        cout << " ";
                        cout << varep[p].vrefv;
                        cout << " ";
                        cout << varep[p].varsta << endl;
                    }
                    else finish=0;
                }
                else
                {
                    if(operador[r].funcao!="\n") r++;
                    else finish=0;
                }


            }
            found=1;
            while(found)
            {
                i=0;
                p=0;
                t=0;
                while(opvar[i].opera!="add" && opvar[i].opera!="\n") i++;
                if(opvar[i].opera!="\n")
                {
                    cout << opvar[i].matrix;
                    cout << opvar[i].vetor << endl;
                    if(opvar[i].vetor==1 || opvar[i].matrix==1)
                    {
                        while(operador[p].funcao != "add") p++;
                        found=0;
                        k=0;
                        cout << forx[kf].aninha << endl;
                        operador[p].s1=operef[k];
                        cout << operador[p].s1 << endl;
                        operador[p].s2=operef[k+1];
                        cout << operador[p].s2 << endl;
                        if(forx[kf].vetor==1 && kf==0) forx[kf].tfs[t] = operador[p].s3;
                        if(forx[kf].matrix==1 && kf!=0)forx[kf].tfs[t] = operador[p].s3;
                        cout << operador[p].s3 << endl;
                        cout << forx[kf].tfs[t] << endl;
                        i++;
                    }
                }
                else
                {
                    i=0;
                    p=0;
                    while(opvar[i].opera!="sub" && opvar[i].opera!="\n") i++;
                    if(opvar[i].opera!="\n")
                    {
                        cout << opvar[i].matrix;
                        cout << opvar[i].vetor << endl;
                        if(opvar[i].vetor==1 || opvar[i].matrix==1)
                        {
                            while(operador[p].funcao != "sub") p++;
                            found=0;
                            k=0;
                            operador[p].s1=operef[k];
                            cout << operador[p].s1 << endl;
                            operador[p].s2=operef[k+1];
                            cout << operador[p].s2 << endl;
                            if(forx[kf].matrix==1 && kf!=0)forx[kf].tfs[t] = operador[p].s3;
                            cout << operador[p].s3 << endl;
                            i++;
                        }
                    }
                    else
                    {
                        i=0;
                        p=0;
                        while(opvar[i].opera!="mul" && opvar[i].opera!="\n") i++;
                        if(opvar[i].opera!="\n")
                        {
                            cout << opvar[i].matrix;
                            cout << opvar[i].vetor << endl;
                            if(opvar[i].vetor==1 || opvar[i].matrix==1)
                            {
                                while(operador[p].funcao != "mul") p++;
                                found=0;
                                k=0;
                                operador[p].s1=operef[k];
                                cout << operador[p].s1 << endl;
                                operador[p].s2=operef[k+1];
                                cout << operador[p].s2 << endl;
                                cout << forx[kf].tfs[t] << endl;
                                if(forx[kf].matrix==1 && kf!=0 && operador[p].staop==0)//------------------------5/5
                                {
                                    forx[kf].tfs[t] = operador[p].s3;
                                    operador[p].staop=1;
                                    cout << operador[p].s3 << endl;
                                }//-----------------------------------------------------------------------------5/5
                                i++;
                                if(forx[kf].atriacc==1)//-------------------------------------------------30/4
                                {
                                    refp=p;
                                    p=0;
                                    while(operador[p].funcao != "accm") p++;
                                    operador[p].s1=operador[refp].s3;
                                    if(forx[kf].matrix==1 && kf!=0 && operador[p].staop==0)//----------------------5/5
                                    {
                                        forx[kf].tfs[t] = operador[p].s3;
                                        operador[p].s2 = forx[kf].cxacc;
                                        operador[p].staop=1;
                                        cout << operador[p].funcao;
                                        cout << operador[p].s1;
                                        cout << operador[p].s2;
                                        cout << operador[p].s3 << endl;
                                    }//------------------------------------------------------------------------5/5

                                }//-----------------------------------------------------------------------30/4

                            }
                        }
                        else
                        {
                            i=0;
                            p=0;
                            while(opvar[i].opera!="div" && opvar[i].opera!="\n") i++;
                            if(opvar[i].opera!="\n")
                            {
                                cout << opvar[i].matrix;
                                cout << opvar[i].vetor << endl;
                                if(opvar[i].vetor==1 || opvar[i].matrix==1)
                                {
                                    while(operador[p].funcao != "div") p++;
                                    found=0;
                                    k=0;
                                    operador[p].s1=operef[k];
                                    cout << operador[p].s1 << endl;
                                    operador[p].s2=operef[k+1];
                                    cout << operador[p].s2 << endl;
                                    if(forx[kf].matrix==1 && kf!=0)forx[kf].tfs[t] = operador[p].s3;
                                    cout << operador[p].s3 << endl;
                                    i++;
                                }
                            }
                            else
                            {
                                i=0;
                                p=0;
                                while(opvar[i].opera!="acc" && opvar[i].vetor==1 && opvar[i].opera!="\n") i++;
                                if(opvar[i].opera!="\n")
                                {
                                    cout << opvar[i].matrix;
                                    cout << opvar[i].vetor << endl;
                                    if(opvar[i].vetor==1 || opvar[i].matrix==1)
                                    {
                                        while(operador[p].funcao != "acc") p++;
                                        found=0;
                                        k=0;
                                        operador[p].s1=operef[k];
                                        cout << operador[p].s1 << endl;
                                        //operador[p].s2=operef[k+1];
                                        //cout << operador[p].s2 << endl;
                                        if(forx[kf].vetor==1)forx[kf].tfs[t] = operador[p].s2;
                                        cout << operador[p].s3 << endl;
                                        i++;
                                    }
                                }
                                else found=0;
                            }
                            found=0;
                        }
                        found=0;
                    }
                    found=0;
                }
                found=0;
            }


            r=0;
            t=0;
            found=1;
            finish=1;
            cout << refistore[t].refj << endl;
            cout << refistore[t].refi << endl;

            while(found)
            {
                while(operador[r].funcao != "dualstore" && operador[r].funcao!="\n") r++;
                if(operador[r].staop==1 && operador[r].funcao!="\n")r++;
                else
                {
                    found=0;
                    if(kf==0)operador[r].staop=1;
                }
            }
            //if(ifx[ki].indvar!=0)t++;
            //{
            if(operador[r].funcao!="\n" && finish)
            {
                cout << operador[r].funcao << endl;
                addr=operador[r].s6;
                cout << addr << endl;
                dout=operador[r].s8;
                cout << dout << endl;
                we=operador[r].s5;
                cout << we << endl;
                da=operador[r].s7;
                cout << da << endl;
                //forx[kf].tfs[t]=operador[r].s7;
                if(forx[kf].vetor==1)
                    {
                        //operador[r].s3=refistore[t].refj;//-----------------------------------4/5------11/5
                        operador[r].s3=refistore[t].refi;//------------------------------------4/5-------11/5
                    }
                if(forx[kf].matrix==1)
                    {
                        operador[r].s3=refistore[t].refj;//-----------------------------------4/5
                        operador[r].s2=refistore[t].refi;//------------------------------------4/5
                    }
                //else operador[r].s3=refistore[t];
                cout << operador[r].s3 << endl;
                cout << operador[r].s2 << endl;
                //t++;
                rref=r;
            }


            if(kf==0)
            {
                found=1;
                while(found)
                {
                    while(operador[r].funcao != "dualsram" && operador[r].funcao!="\n") r++;
                    if(operador[r].staop==1 && operador[r].funcao!="\n")r++;
                    else
                    {
                        found=0;
                        if(kf==0)operador[r].staop=1;
                    }
                }
                if(operador[r].funcao!="\n" && finish)
                {
                    cout << operador[r].funcao << endl;
                    operador[r].s1=addr;
                    cout << operador[r].s1 << endl;
                    operador[r].s2=dout;
                    cout << operador[r].s2 << endl;
                    //operador[r].s6=dpo;  cout << operador[r].s6 << endl;
                    operador[r].s4=we;
                    cout << operador[r].s4 << endl;
                    t++;





                    j=0;         // TESTANDO VERT
                    while (vert[j].variref != xrefn) j++;
                    vert[j].stav=1;
                    while (vert[j].stav==1) j++;
                    vert[j].stav=1;
                    cout << xrefn;
                    cout << j;
                    cout << "=";
                    cout << vert[j].verts;
                    cout << " ref ";
                    cout << vert[j].variref ;
                    cout << vert[j].stav << endl;
                    operador[rref].s4=vert[j].variref;
                    cout << operador[rref].funcao;
                    cout << operador[rref].s4 << endl;

                    p=0;          // TESTANDO VAREP
                    while (varep[p].varrx!=xrefn) p++;
                    while (varep[p].varsta==1) p++;
                    varep[p].vrefv=vert[j].variref;
                    varep[p].varsta=1;
                    cout << "varep = ";
                    cout << p;
                    cout << " ";
                    cout << varep[p].varrx;
                    cout << " ";
                    cout << varep[p].vrefv;
                    cout << " ";
                    cout << varep[p].varsta << endl;
                    //finish=0;

                    operador[r].staop=1;
                    r++;

                } else finish=0;
            }
            else
            {
                r++;
                finish=0;
            }
            //}
        }


                r=0;
                t=0;
                cout << " INDVAR " ;cout << forx[kf].indvar << endl;
                cout << " INDOPE " ;cout << forx[kf].indope << endl;      // O PROBLEMA EST� AQUI
                int demergeok;
                if (forx[kf].indvar==0)demergeok=1;
                if (forx[kf].indope!=0)demergeok=forx[kf].indope;
//                if (demergeok==0) demergeok=1;
//                else if(ifx[ki].indvar!=0) demergeok=ifx[ki].indope;
//                if(ifx[ki].indope==0) demergeok=1; else demergeok=ifx[ki].indope;
                while(demergeok!=0)
                {
                    found=1;
                    while(found)
                    { while(operador[r].funcao != "dmerged") r++;
                      if(operador[r].staop==1)r++; else found=0;
                    }
                    //if(ifx[ki].indvar!=0)t++;
                    //{
                        cout << operador[r].funcao << endl;
//                while(operador[r].staop==1) r++;
                        cout << operador[r].staop << endl;
                        cout << forx[kf].tfs[t] << endl;
                        if(ks>=2 && sop[ks-1].ope=="if"){operador[r].s1=sop[ks-2].vref[t]; cout << operador[r].s1 << endl;}else {operador[r].s1=forx[kf].tfs[t]; cout << operador[r].s1 << endl;}
                        operador[r].s2=forx[kf].ffs[t];cout << operador[r].s2 << endl;
                        operador[r].s3=forx[kf].forctrl[t];cout << operador[r].s3 << endl;
                        if(ks>=2 &&  sop[ks-1].ope=="if"){operador[r].s4=sop[ks-2].varz[t]; cout << operador[r].s4 << endl;}
                        else if(kf==0)
                             //{//--------------------m9/w11/w9----------------------------13/4
                                 if(ksx>0)
                                       if(sop[ksx-1].ope=="if")//----------{---14/4
                                        {   sop[ksx-1].vref[t]=operador[r].s4;
                                            sop[ksx-1].varz[t]=forx[kf].ztfs[t];
                                            cout << sop[ksx-1].vref[t] << endl;
                                            cout << sop[ksx-1].varz[t] << endl;
                                        } else operador[r].s4=forx[kf].ztfs[t];
                                     else {operador[r].s4=forx[kf].ztfs[t]; cout << operador[r].s4 << endl;}//-----}---14/4

                             //}//---------------------m9/w11/w9-----------------------------13/4
                             else if(kf>0)forx[kf-1].tfs[t]=operador[r].s4;
                                    else operador[r].s4=da;
                           // cout << forx[kf-1].tfs[t]; cout << operador[r].s4 << endl;----------------------6/5
                           cout << da << endl;
                        if((forx[kf].matrix==1 || forx[kf].vetor==1) && kf>0)forx[kf-1].tfs[t]=operador[r].s4;
                        //cout << forx[kf-1].tfs[t] << endl;
                        if(forx[kf].matrix==1  && kf==0 && forx[kf].atriacc==1)operador[r].s4=da;//--------------------22/5
                        if(forx[kf].vetor==1  && kf==0 && forx[kf].atriacc==0)operador[r].s4=da;//----------------------22/5
                        if(forx[kf].matrix==1  && kf==0 && forx[kf].atriacc==0)operador[r].s4=da;
                          //  cout << operador[r].s4 << endl;

//                        if(kf==0)operador[r].s4=forx[kf].ztfs[t];

//                        if(kf!=0)
//                cout << ifx[ki-1].tifs[t] << endl;
                        operador[r].staop=1;
//                cout << varep[p].varrx; cout << varep[p].vrefv; cout << varep[p].varsta << endl;
                        if(forx[kf].indvar!=0 || forx[kf].indope!=0)t++;
                        if(forx[kf].indvar!=0 || forx[kf].indope!=0)demergeok=demergeok-1; else demergeok=0;
//                contope++;
                        r++;
                    //}
                }

             };
            if (opvar[i].opera=="add")
            {   if(opvar[i].vetor!=1)
                { xref=opvar[i].x2;
                j=0;
                while (vert[j].variref != xref) j++;
                cout << "Achei xref " ; cout << j  << endl;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                cout << "Achei stav " ; cout << j  << endl;
                vert[j].stav=1;
                p=0;
                while (varep[p].varrx!=xref) p++;
                cout << "Achei xref " ; cout << p  << endl;
                while (varep[p].varsta==1) p++;
                cout << "Achei varsta " ; cout << p  << endl;
                varep[p].vrefv=vert[j].variref;
                varep[p].varsta=1;
                r=0;
                while(operador[r].funcao != "add" && operador[r].staop==1) r++;
                operador[r].s2=vert[j].variref;
                operador[r].staop=1;
                cout << varep[p].varrx; cout << varep[p].vrefv; cout << varep[p].varsta << endl;
                if(opvar[i].vetor==1)xref= operef[k+1];
                else xref=opvar[i].x3;
                j=0;         // TESTANDO VERT
                while (vert[j].variref != xref) j++;
                cout << "Achei xref " ; cout << j  << endl;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                cout << "Achei stav " ; cout << j  << endl;
                vert[j].stav=1;
                p=0;          // TESTANDO VAREP
                while (varep[p].varrx!=xref) p++;
                cout << "Achei xref " ; cout << p  << endl;
                while (varep[p].varsta==1) p++;
                cout << "Achei varsta " ; cout << p  << endl;
                varep[p].vrefv=vert[j].variref;
                varep[p].varsta=1;
                r=0;
                while(operador[r].funcao != "add" && operador[r].staop==1) r++;
                operador[r].s3=vert[j].variref;
                operador[r].staop=1;
                cout << varep[p].varrx; cout << varep[p].vrefv; cout << varep[p].varsta << endl;
                xref=opvar[i].x1;
                j=0;
                while (vert[j].variref != xref) j++;
                cout << "Achei xref " ; cout << j  << endl;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                cout << "Achei stav " ; cout << j  << endl;
                vert[j].stav=1;
                p=0;
                while (varep[p].varrx!=xref) p++;
                cout << "Achei xref " ; cout << p  << endl;
                while (varep[p].varsta==1) p++;
                cout << "Achei varsta " ; cout << p  << endl;
                varep[p].vrefv=vert[j].variref;
                varep[p].varsta=1;
                r=0;
                while(operador[r].funcao != "add" && operador[r].staop==1) r++;
                operador[r].s1=vert[j].variref;
                operador[r].staop=1;
                cout << varep[p].varrx; cout << varep[p].vrefv; cout << varep[p].varsta << endl;
                }
            };
            if (opvar[i].opera=="mul")
            {   if(opvar[i].vetor!=1)
                {
                xref=opvar[i].x2;
                j=0;
                while (vert[j].variref != xref) j++;
                cout << "Achei xref " ; cout << j  << endl;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                cout << "Achei stav " ; cout << j  << endl;
                vert[j].stav=1;
                p=0;
                while (varep[p].varrx!=xref) p++;
                cout << "Achei xref " ; cout << p  << endl;
                while (varep[p].varsta==1) p++;
                cout << "Achei varsta " ; cout << p  << endl;
                varep[p].vrefv=vert[j].variref;
                varep[p].varsta=1;
                 r=0;
                while(operador[r].funcao != "mul" && operador[r].staop==1) r++;
                operador[r].s2=vert[j].variref;
                operador[r].staop=1;
               cout << varep[p].varrx; cout << varep[p].vrefv; cout << varep[p].varsta << endl;
                xref=opvar[i].x3;
                j=0;         // TESTANDO VERT
                while (vert[j].variref != xref) j++;
                cout << "Achei xref " ; cout << j  << endl;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                cout << "Achei stav " ; cout << j  << endl;
                vert[j].stav=1;
                p=0;          // TESTANDO VAREP
                while (varep[p].varrx!=xref) p++;
                cout << "Achei xref " ; cout << p  << endl;
                while (varep[p].varsta==1) p++;
                cout << "Achei varsta " ; cout << p  << endl;
                varep[p].vrefv=vert[j].variref;
                varep[p].varsta=1;
                r=0;
                while(operador[r].funcao != "mul" && operador[r].staop==1) r++;
                operador[r].s3=vert[j].variref;
                operador[r].staop=1;
                cout << varep[p].varrx; cout << varep[p].vrefv; cout << varep[p].varsta << endl;
                xref=opvar[i].x1;
                j=0;
                while (vert[j].variref != xref) j++;
                cout << "Achei xref " ; cout << j  << endl;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                cout << "Achei stav " ; cout << j  << endl;
                vert[j].stav=1;
                p=0;
                while (varep[p].varrx!=xref) p++;
                cout << "Achei xref " ; cout << p  << endl;
                while (varep[p].varsta==1) p++;
                cout << "Achei varsta " ; cout << p  << endl;
                varep[p].vrefv=vert[j].variref;
                varep[p].varsta=1;
                 r=0;
                while(operador[r].funcao != "mul" && operador[r].staop==1) r++;
                operador[r].s1=vert[j].variref;
                operador[r].staop=1;
               cout << varep[p].varrx; cout << varep[p].vrefv; cout << varep[p].varsta << endl;
                }
            };
            if (opvar[i].opera=="sub")
            {   if(opvar[i].vetor!=1)
                {
                xref=opvar[i].x2;
                j=0;
                while (vert[j].variref != xref) j++;
                cout << "Achei xref " ; cout << j  << endl;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                cout << "Achei stav " ; cout << j  << endl;
                vert[j].stav=1;
                p=0;
                while (varep[p].varrx!=xref) p++;
                cout << "Achei xref " ; cout << p  << endl;
                while (varep[p].varsta==1) p++;
                cout << "Achei varsta " ; cout << p  << endl;
                varep[p].vrefv=vert[j].variref;
                varep[p].varsta=1;
                r=0;
                while(operador[r].funcao != "sub" && operador[r].staop==1) r++;
                operador[r].s2=vert[j].variref;
                operador[r].staop=1;
                cout << varep[p].varrx; cout << varep[p].vrefv; cout << varep[p].varsta << endl;
                xref=opvar[i].x3;
                j=0;         // TESTANDO VERT
                while (vert[j].variref != xref) j++;
                cout << "Achei xref " ; cout << j  << endl;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                cout << "Achei stav " ; cout << j  << endl;
                vert[j].stav=1;
                p=0;          // TESTANDO VAREP
                while (varep[p].varrx!=xref) p++;
                cout << "Achei xref " ; cout << p  << endl;
                while (varep[p].varsta==1) p++;
                cout << "Achei varsta " ; cout << p  << endl;
                varep[p].vrefv=vert[j].variref;
                varep[p].varsta=1;
                 r=0;
                while(operador[r].funcao != "sub" && operador[r].staop==1) r++;
                operador[r].s3=vert[j].variref;
                operador[r].staop=1;
               cout << varep[p].varrx; cout << varep[p].vrefv; cout << varep[p].varsta << endl;
                xref=opvar[i].x1;
                j=0;
                while (vert[j].variref != xref) j++;
                cout << "Achei xref " ; cout << j  << endl;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                cout << "Achei stav " ; cout << j  << endl;
                vert[j].stav=1;
                p=0;
                while (varep[p].varrx!=xref) p++;
                cout << "Achei xref " ; cout << p  << endl;
                while (varep[p].varsta==1) p++;
                cout << "Achei varsta " ; cout << p  << endl;
                varep[p].vrefv=vert[j].variref;
                varep[p].varsta=1;
                r=0;
                while(operador[r].funcao != "sub" && operador[r].staop==1) r++;
                operador[r].s1=vert[j].variref;
                operador[r].staop=1;
             cout << varep[p].varrx; cout << varep[p].vrefv; cout << varep[p].varsta << endl;
                }
            };
            if (opvar[i].opera=="div")
            {   if(opvar[i].vetor!=1)
                {
                xref=opvar[i].x2;
                j=0;
                while (vert[j].variref != xref) j++;
                cout << "Achei xref " ; cout << j  << endl;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                cout << "Achei stav " ; cout << j  << endl;
                vert[j].stav=1;
                p=0;
                while (varep[p].varrx!=xref) p++;
                cout << "Achei xref " ; cout << p  << endl;
                while (varep[p].varsta==1) p++;
                cout << "Achei varsta " ; cout << p  << endl;
                varep[p].vrefv=vert[j].variref;
                varep[p].varsta=1;
                r=0;
                while(operador[r].funcao != "div" && operador[r].staop==1) r++;
                operador[r].s2=vert[j].variref;
                operador[r].staop=1;
                cout << varep[p].varrx; cout << varep[p].vrefv; cout << varep[p].varsta << endl;
                xref=opvar[i].x3;
                j=0;         // TESTANDO VERT
                while (vert[j].variref != xref) j++;
                cout << "Achei xref " ; cout << j  << endl;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                cout << "Achei stav " ; cout << j  << endl;
                vert[j].stav=1;
                p=0;          // TESTANDO VAREP
                while (varep[p].varrx!=xref) p++;
                cout << "Achei xref " ; cout << p  << endl;
                while (varep[p].varsta==1) p++;
                cout << "Achei varsta " ; cout << p  << endl;
                varep[p].vrefv=vert[j].variref;
                varep[p].varsta=1;
                r=0;
                while(operador[r].funcao != "div" && operador[r].staop==1) r++;
                operador[r].s3=vert[j].variref;
                operador[r].staop=1;
                cout << varep[p].varrx; cout << varep[p].vrefv; cout << varep[p].varsta << endl;
                xref=opvar[i].x1;
                j=0;
                while (vert[j].variref != xref) j++;
                cout << "Achei xref " ; cout << j  << endl;
                vert[j].stav=1;
                while (vert[j].stav==1) j++;
                cout << "Achei stav " ; cout << j  << endl;
                vert[j].stav=1;
                p=0;
                while (varep[p].varrx!=xref) p++;
                cout << "Achei xref " ; cout << p  << endl;
                while (varep[p].varsta==1) p++;
                cout << "Achei varsta " ; cout << p  << endl;
                varep[p].vrefv=vert[j].variref;
                varep[p].varsta=1;
                 r=0;
                while(operador[r].funcao != "div" && operador[r].staop==1) r++;
                operador[r].s1=vert[j].variref;
                operador[r].staop=1;
               cout << varep[p].varrx; cout << varep[p].vrefv; cout << varep[p].varsta << endl;
                }
            };

   /*     cout << "valor de i = "; cout << i << endl;
        i=0;
        while (varep[i].varrx !="\n")
        {   varep[i].varsta=0;
            cout << varep[i].varrx; cout << varep[i].vrefv; cout << varep[i].varsta << endl;
            i++;
        }
*/

   j=0;
    while (operador[j].funcao!="\n")
    {
     cout << j;  cout << operador[j].funcao + " "; cout << operador[j].s1 + ","; cout << operador[j].s2 + ","; cout << operador[j].s3 + ","; cout << operador[j].s4 + ","; cout << operador[j].s5 + ","; cout << operador[j].s6 + ","; cout << operador[j].s7 + ","; cout << operador[j].s8 + ";" << endl;
    j++;
   }
}
