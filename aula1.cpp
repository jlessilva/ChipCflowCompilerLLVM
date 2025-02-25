#include <iostream>

using namespace std;

int man() {

    int x = 55;
    char tam[50];
    itoa(x,tam,10);
    printf("%s",tam);
    return 0;
}
