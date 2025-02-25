#include "varevertices.h"
#include "genalloperator.h"
#include "funcopera.h"
#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

void defmax(defvarx *varx, string charsimb[], maxvar *defr)
{
   int j;
   int k=0;
   int i=0;
   int ret=0;
   int setflag[100]={0};
   int indsimb=0;
   int simbp=0;
   for (i = 0; i < 100; i++) {
       defr[i].ctrl = 0;
       defr[i].setxmax = 0;
   };
   i = 0;
   while (varx[i].varxy != "\n")
    {   defr[k].varxk=varx[i].varxy; cout << varx[i].varxy; cout << varx[i].ctrl;
        if (varx[i].ctrl==1) defr[k].ctrl=1; else defr[k].ctrl=0;
        j=0; cout << defr[k].ctrl << endl;
        if (setflag[i] ==0)
        { //cout << "entrou" << endl;
            indsimb=0;
            simbp=0;
            while(charsimb[indsimb]!="\n")
            {if(varx[i].varxy==charsimb[indsimb]) simbp=1; indsimb++;}
            if(simbp==1)
            {
                while (varx[j].varxy !="\n")
                    {   cout << varx[j].varxy << endl;
                        if(defr[k].varxk==varx[j].varxy) {defr[k].setxmax=1; setflag[j]=1;}
                        cout << defr[k].varxk ; cout << defr[k].setxmax << endl;
                        j++;
                    }

                //defr[k].setxmax=0; setflag[j]=1;
            }
            else {
                    while (varx[j].varxy !="\n")
                    {   cout << varx[j].varxy << endl;
                        if(defr[k].varxk==varx[j].varxy) {defr[k].setxmax=varx[j].setxy; setflag[j]=1;}
                        cout << defr[k].varxk ; cout << defr[k].setxmax << endl;
                        j++;
                    }
                }
            k++;
        } //cout << i << endl;
     i++;
    }; defr[k].varxk="\n";

    i=0;
while (defr[i].varxk !="\n"){
    cout << defr[i].varxk ; cout << defr[i].ctrl; cout << defr[i].setxmax << endl;
    i++;
}

}


void statusvert(asseline *operadores, vertices *vert)
{

   int k=0;
   int i=0;
   int j=0;
        cout << "VERT" << endl;
    while (operadores[i].funcao !="\n")
    {  //j=0; //cout << operadores[i].funcao << endl;
        if (operadores[i].s1 != "\n")
        {
            vert[j].verts=operadores[i].s1; cout << j; cout << "="; cout << vert[j].verts ;cout << " ref ";
            vert[j].variref="0";cout << vert[j].variref;
            vert[j].stav=0;cout << vert[j].stav << endl;
            j++;
        };
        if (operadores[i].s2 != "\n")
        {
            vert[j].verts=operadores[i].s2;cout << j; cout << "="; cout << vert[j].verts ;cout << " ref ";
            vert[j].variref="0";cout << vert[j].variref;
            vert[j].stav=0;cout << vert[j].stav << endl;
            j++;
        } ;
        if (operadores[i].s3 !=  "\n")
        {
            vert[j].verts=operadores[i].s3;cout << j; cout << "="; cout << vert[j].verts ;cout << " ref ";
            vert[j].variref="0"; cout << vert[j].variref ;
            vert[j].stav=0;cout << vert[j].stav << endl;
            j++;
        } ;
        if (operadores[i].s4 !=  "\n")
        {
            vert[j].verts=operadores[i].s4;cout << j; cout << "="; cout << vert[j].verts ;cout << " ref ";
            vert[j].variref="0";cout << vert[j].variref ;
            vert[j].stav=0;cout << vert[j].stav << endl;
            j++;
        };
        if (operadores[i].s5 !=  "\n")
        {
            vert[j].verts=operadores[i].s5;cout << j; cout << "="; cout << vert[j].verts ;cout << " ref ";
            vert[j].variref="0";cout << vert[j].variref ;
            vert[j].stav=0;cout << vert[j].stav << endl;
            j++;
        } ;
        if (operadores[i].s6 !=  "\n")
        {
           vert[j].verts=operadores[i].s6;cout << j; cout << "="; cout << vert[j].verts ;cout << " ref ";
           vert[j].variref="0";cout << vert[j].variref ;
           vert[j].stav=0;cout << vert[j].stav << endl;
           j++;
        };
        i++;
    };
    vert[j].verts="\n";

    cout <<"acabei vert" << endl;

   i=0;
   while (vert[i].verts !="\n")
   {
       cout << vert[i].verts; cout << vert[i].variref ; cout << vert[i].stav << endl;
       i++;
   }
}

void statusrep(asseline *operadores,maxvar *defr,vertices *vert)
{
   int i=0;
   int k=0;
   int cta, t, ct;
   t=0;


   while (operadores[i].funcao !="\n" && defr[t].varxk !="\n")
   {
        cta=defr[t].setxmax;
         cout << operadores[i].funcao << endl;
        if (cta==1)
        {
            operadores[i].s1=defr[t].varxk;  cout << operadores[i].s1 << endl;
            vert[k].variref=defr[t].varxk;
            vert[k].stav=1;
                   cout << k; cout << "="; cout << vert[k].verts; cout << " ref "; cout << vert[k].variref ; cout << vert[k].stav << endl;

            k++;
            vert[k].variref=vert[k].verts;
            vert[k].stav=0;
                   cout << k; cout << "="; cout << vert[k].verts; cout << " ref "; cout << vert[k].variref ; cout << vert[k].stav << endl;
            k++;

        }else { operadores[i].s1=defr[t].varxk;   cout << operadores[i].s1 << endl;
                vert[k].variref=defr[t].varxk;
                vert[k].stav=1;
                   cout << k; cout << "="; cout << vert[k].verts; cout << " ref "; cout << vert[k].variref ; cout << vert[k].stav << endl;

                k++;
                vert[k].variref=operadores[i].s2;  cout << operadores[i].s2 << endl;
                if (vert[k].variref=="E")vert[k].stav=0;else vert[k].stav=1;
                  cout << k; cout << "="; cout << vert[k].verts; cout << " ref "; cout << vert[k].variref ; cout << vert[k].stav << endl;

                i++;
                k++;
                operadores[i].s1=operadores[i-1].s2;  cout << operadores[i].s1 << endl;
                vert[k].variref=operadores[i-1].s2;
                if (vert[k].variref=="E")vert[k].stav=0;else vert[k].stav=1;
                  cout << k; cout << "="; cout << vert[k].verts; cout << " ref "; cout << vert[k].variref ; cout << vert[k].stav << endl;

                k++;
                vert[k].variref=operadores[i].s2;
                if (vert[k].variref=="E")vert[k].stav=0;else vert[k].stav=1;
                  cout << k; cout << "="; cout << vert[k].verts; cout << " ref "; cout << vert[k].variref ; cout << vert[k].stav << endl;

                k++;
                vert[k].variref=operadores[i].s3;  cout << operadores[i].s3 << endl;
                vert[k].stav=0;
                  cout << k; cout << "="; cout << vert[k].verts; cout << " ref "; cout << vert[k].variref ; cout << vert[k].stav << endl;

                for (ct=2;ct<cta;ct++)
                {   k++;i++;
                    operadores[i].s1=operadores[i-1].s2;   cout << operadores[i].s1 << endl;
                    vert[k].variref=operadores[i-1].s2;
                    if (vert[k].variref=="E")vert[k].stav=0;else vert[k].stav=1;
                  cout << k; cout << "="; cout << vert[k].verts; cout << " ref "; cout << vert[k].variref ; cout << vert[k].stav << endl;

                    k++;
                    vert[k].variref=operadores[i].s2;   cout << operadores[i].s2 << endl;
                    if (vert[k].variref=="E")vert[k].stav=0;else vert[k].stav=1;
                  cout << k; cout << "="; cout << vert[k].verts; cout << " ref "; cout << vert[k].variref ; cout << vert[k].stav << endl;

                    k++;
                    vert[k].variref=operadores[i].s3;   cout << operadores[i].s3 << endl;
                    vert[k].stav=0;
                }   vert[k-1].stav=0;
                    k++;
              }
        i++;
        t++;

   }


   int j=0;
    while (operadores[j].funcao!="\n")
    {
       cout << operadores[j].funcao + " "; cout << operadores[j].s1 + ","; cout << operadores[j].s2 + ","; cout << operadores[j].s3 + ","; cout << operadores[j].s4 + ","; cout << operadores[j].s5 + ","; cout << operadores[j].s6 + ";" << endl;
    j++;
   }


       i=0;
   while (vert[i].verts !="\n")
   {
       cout << i; cout << "="; cout << vert[i].verts; cout << " ref "; cout << vert[i].variref ; cout << vert[i].stav << endl;
       i++;
   }
}



void gervarep(maxvar *defr, varepsta *varep)
{
     int k=0;
     int i=0;
   int j=0;
//   um=3;
//   int inteirop = 3;
   while ( defr[k].varxk !="\n")
    {   if(defr[k].setxmax!=0)
        {   for (j=0;j<defr[k].setxmax;j++)
            {
                varep[i].varrx=defr[k].varxk;
                varep[i].vrefv="";
                varep[i].varsta=0; cout << i; cout << " = ";  cout << varep[i].varrx; cout << varep[i].varsta << endl;
  //            inteirop=inteirop+2;
                i++;
            }
        }else { varep[i].varrx=defr[k].varxk;
                varep[i].vrefv="";
                varep[i].varsta=0; cout << i; cout << " = ";  cout << varep[i].varrx; cout << varep[i].varsta << endl;
                i++;
              }
        ; //inteirop=3;
        k++;
    };
    varep[i].varrx="\n";


   i=0;
   while (varep[i].varrx !="\n")
   {
        cout << i; cout << "="; cout << varep[i].varrx; cout << varep[i].vrefv; cout << varep[i].varsta << endl;
        i++;
   }

}
