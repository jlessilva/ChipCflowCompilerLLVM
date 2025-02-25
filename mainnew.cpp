#include <iostream>
#include <fstream>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

string indice(int k, char inds[100]=""){
itoa(k,inds,10) ;   // itoa() is a function of stdlib.h file that convert integer
                   // int to array itoa( integer, targated array, base u want to
                   //convert like decimal have 10
return inds;


}



int main()
{
char ch;
char fileName[80];
char buffer[255]; // for user input
char fileNamevhd[80];
string buffervhd[50];
string bufferindex[50];
char buffersimbol[200];

cout << "File name: ";
cin >> fileName;

cout << "File name: ";
cin >> fileNamevhd;


ifstream fin(fileName); // reopen for reading

// declaração de todas as variáveis necessárias para gerar o código assembler chipcflow

string var1;
string var2;
string var3;
string var4;
string var5;
string var6;
string var7;
char ind[100];
char varx[10];
int indexvarx=0;



// Criando a tabela de símbolos
int indexsimb=0;
while (fin.get(ch)){
buffersimbol[indexsimb]=ch;
indexsimb=indexsimb+1;
}
// Tabela de simbolos criada


// Manipulando a tabela de símbolos
// AQUI COMEÇA TODA A DECODIFICAÇÃO DO PRORGAMA ESCRITO EM C PARA SER CONVERTIDO EM ASSEMBLER DO CHIPCFLOW

// CONVERTENDO COMANDOS C EM ASSEMBLER CHIPCFLOW

int inteiro = 1;
int counter=0;
counter=0;
indexsimb=0;

while (buffersimbol[indexsimb] != '\0')
{
  if (buffersimbol[indexsimb]=='i'){    //COMANDO IF
     indexsimb=indexsimb+1;
     if (buffersimbol[indexsimb]=='f'){
        var1="x"+ indice(inteiro, ind);
        inteiro=inteiro+1;
        var2="x"+ indice(inteiro, ind);
        inteiro=inteiro+1;
        var3="x" + indice(inteiro, ind);
        inteiro=inteiro+1;
        var4="x" + indice(inteiro, ind);
        inteiro=inteiro+1;
        var5="x" + indice(inteiro, ind);
        inteiro=inteiro+1;
        var6="x" + indice(inteiro, ind);
        inteiro=inteiro+1;
        var7="x" + indice(inteiro, ind);
        inteiro=inteiro+1;
        buffervhd[counter]="decider " + var1 + "," + var2 + "," + var3 +";\n"; cout << buffervhd[counter] << endl; counter++;
        buffervhd[counter]="branchd " + var4 + "," + var5 + "," + var6 + "," + var7 + ";\n"; cout << buffervhd[counter] << endl; counter++;
     }};

  if (buffersimbol[indexsimb]=='f'){    // COMANDO FOR
     indexsimb=indexsimb+1;
     if (buffersimbol[indexsimb]=='o'){
        indexsimb=indexsimb+1;
        if (buffersimbol[indexsimb]=='r'){
            var1="x"+ indice(inteiro, ind);
            inteiro=inteiro+1;
            var2="x"+ indice(inteiro, ind);
            inteiro=inteiro+1;
            var3="x" + indice(inteiro, ind);
            inteiro=inteiro+1;
            var4="x" + indice(inteiro, ind);
            inteiro=inteiro+1;
            var5="x" + indice(inteiro, ind);
            inteiro=inteiro+1;
            var6="x" + indice(inteiro, ind);
            inteiro=inteiro+1;
            buffervhd[counter]="foricexx " + var1 + "," + var2 + "," + var3 + "," + var4 + "," + var5 + "," + var6 + ";\n"; cout << buffervhd[counter] << endl;counter++;
     }}};

  if (buffersimbol[indexsimb]=='+'){    // COMANDO FOR
            var1="x"+ indice(inteiro, ind);
            inteiro=inteiro+1;
            var2="x"+ indice(inteiro, ind);
            inteiro=inteiro+1;
            var3="x" + indice(inteiro, ind);
            inteiro=inteiro+1;
            buffervhd[counter]="add " + var1 + "," + var2 + "," + var3 + ";\n"; cout << buffervhd[counter] << endl;counter++;
     };

  if (buffersimbol[indexsimb]=='*'){    // COMANDO FOR
            var1="x"+ indice(inteiro, ind);
            inteiro=inteiro+1;
            var2="x"+ indice(inteiro, ind);
            inteiro=inteiro+1;
            var3="x" + indice(inteiro, ind);
            inteiro=inteiro+1;
            buffervhd[counter]="mul " + var1 + "," + var2 + "," + var3 + ";\n"; cout << buffervhd[counter] << endl;counter++;
     };

     // vai para o próximo caracter da tabela de símbolos
     indexsimb=indexsimb+1;

// ENCERRANDO TRATAMENTO DE COMANDOS C PARA ASSEMBLER CHIPCFLOW


/*

   if (ch=='i'){fin.get(ch);//i
     if (ch=='f'){fin.get(ch);//f
       if (ch=='('){fin.get(ch);//x
            var1="x"+ indice(inteiro, ind);
            inteiro=inteiro+1;

/*            var1=ch;  //varx
            fin.get(ch);//<
            fin.get(ch);//y
            var2=ch;//vary
            fin.get(ch);//)
            fin.get(ch);//branco
            fin.get(ch);//Z
            var3=ch;//varz;
            fin.get(ch);//=
            fin.get(ch);//x
*/


//            caractere = inteiro+'0';
//            ind=caractere;
/*            var4="s" + indice(inteiro, ind);
            inteiro=inteiro+1;
            var5="s" + indice(inteiro, ind);
            inteiro=inteiro+1;
            var6="s" + indice(inteiro, ind);
            inteiro=inteiro+1;
            var7="s" + indice(inteiro, ind);
            inteiro=inteiro+1;

//            var6="z";
            }
            buffervhd[counter]="decider " + var1 + "," + var2 + "," + var3 +";\n"; cout << buffervhd[counter] << endl; counter++;
            buffervhd[counter]="branchd " + var4 + "," + var5 + "," + var6 + "," + var7 + ";\n"; cout << buffervhd[counter] << endl; counter++;
    }};
    counter++;
   if (ch=='f'){fin.get(ch);
     if (ch=='o'){fin.get(ch);
       if (ch=='r'){
            inteiro=1;
            var1="s"+ indice(inteiro, ind);
            inteiro=inteiro+1;
            var2="s"+ indice(inteiro, ind);
            inteiro=inteiro+1;
            var3="s" + indice(inteiro, ind);
            inteiro=inteiro+1;
            var4="s" + indice(inteiro, ind);
            inteiro=inteiro+1;
            var5="s" + indice(inteiro, ind);
            inteiro=inteiro+1;
            var6="s" + indice(inteiro, ind);
            inteiro=inteiro+1;
       }
            buffervhd[counter]="foricexx " + var1 + "," + var2 + "," + var3 + "," + var4 + "," + var5 + "," + var6 + ";\n"; cout << buffervhd[counter] << endl; counter++;
    }};
    counter=counter+1;
   if (ch=='+'){fin.get(ch);
       { buffervhd[counter]="add x1,x2,x3; \n"; cout << buffervhd[counter] << endl;
    }};
    counter=counter+1;
*/
}

// INICIANDO TRATAMENTO DE VARIAVEIS EM C PARA ASSEMBLER CHIPCFLOW

indexsimb=0;
indexvarx=0;
while (buffersimbol[indexsimb] != '\0')
{
  if (buffersimbol[indexsimb]=='i'){    //COMANDO IF
     indexsimb=indexsimb+1;
     if (buffersimbol[indexsimb]=='f'){
        indexsimb=indexsimb+1;
        if (buffersimbol[indexsimb]=='('){    //COMANDO IF
            indexsimb=indexsimb+1;
            varx[indexvarx]=buffersimbol[indexsimb];
            cout << varx[indexvarx] << endl;
            indexsimb=indexsimb+1;
            if (buffersimbol[indexsimb]=='<'){    //COMANDO IF
                indexsimb=indexsimb+1;
                varx[indexvarx]=buffersimbol[indexsimb];
                cout << varx[indexvarx] << endl;
            }}}}
            indexsimb=indexsimb+1;

/*  if (buffersimbol[indexsimb]=='f'){    // COMANDO FOR
     indexsimb=indexsimb+1;
     if (buffersimbol[indexsimb]=='o'){
        indexsimb=indexsimb+1;
        if (buffersimbol[indexsimb]=='r'){
            var1="x"+ indice(inteiro, ind);
            inteiro=inteiro+1;
            var2="x"+ indice(inteiro, ind);
            inteiro=inteiro+1;
            var3="x" + indice(inteiro, ind);
            inteiro=inteiro+1;
            var4="x" + indice(inteiro, ind);
            inteiro=inteiro+1;
            var5="x" + indice(inteiro, ind);
            inteiro=inteiro+1;
            var6="x" + indice(inteiro, ind);
            inteiro=inteiro+1;
            buffervhd[counter]="foricexx " + var1 + "," + var2 + "," + var3 + "," + var4 + "," + var5 + "," + var6 + ";\n"; cout << buffervhd[counter] << endl;counter++;
     }}};

  if (buffersimbol[indexsimb]=='+'){    // COMANDO FOR
            var1="x"+ indice(inteiro, ind);
            inteiro=inteiro+1;
            var2="x"+ indice(inteiro, ind);
            inteiro=inteiro+1;
            var3="x" + indice(inteiro, ind);
            inteiro=inteiro+1;
            buffervhd[counter]="add " + var1 + "," + var2 + "," + var3 + ";\n"; cout << buffervhd[counter] << endl;counter++;
     };

  if (buffersimbol[indexsimb]=='*'){    // COMANDO FOR
            var1="x"+ indice(inteiro, ind);
            inteiro=inteiro+1;
            var2="x"+ indice(inteiro, ind);
            inteiro=inteiro+1;
            var3="x" + indice(inteiro, ind);
            inteiro=inteiro+1;
            buffervhd[counter]="mul " + var1 + "," + var2 + "," + var3 + ";\n"; cout << buffervhd[counter] << endl;counter++;
     };

     // vai para o próximo caracter da tabela de símbolos
     indexsimb=indexsimb+1;
*/
// ENCERRANDO TRATAMENTO DE COMANDOS C PARA ASSEMBLER CHIPCFLOW
}




// AQUI SE INCERRA TODA A DECODIFICAÇÃO DO PROGRAMA CONVERTIDO.

//cout << "\n***End of file contents.***\n";
fin.close(); // always pays to be tidy

counter=0;
ofstream fout(fileNamevhd); // open for writing
//fout << "This line written directly to the file...\n";
//cout << "Enter text for the file: ";
//cin.ignore(1,'\n'); // eat the newline after the file name
//cin.getline(buffer,255); // get the user’s input
int i;
for(i=0;i<20;i++)
fout << buffervhd[i]; // and write it to the file
// eat the newline after the file name

fout.close(); // close the file, ready for reopen

return 0;
 }

