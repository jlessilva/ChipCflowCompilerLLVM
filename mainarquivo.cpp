#include <iostream>
#include <fstream>

using namespace std;

int main()
{
char fileName[80];
char buffer[255]; // for user input
char fileNamevhd[80];

cout << "File name: ";
cin >> fileName;

cout << "File name: ";
cin >> fileNamevhd;

ofstream fout(fileNamevhd); // open for writing
//fout << "This line written directly to the file...\n";
cout << "Enter text for the file: ";
cin.ignore(1,'\n'); // eat the newline after the file name
cin.getline(buffer,255); // get the user’s input
fout << buffer << "\n"; // and write it to the file
fout.close(); // close the file, ready for reopen



ifstream fin(fileNamevhd); // reopen for reading
cout << "Here is the contents of the file:\n";
char ch;
while (fin.get(ch))
 fout.put(ch); // Grava o caracter no arquivo
cout << ch;
cout << "\n***End of file contents.***\n";
fin.close(); // always pays to be tidy


return 0;
 }

