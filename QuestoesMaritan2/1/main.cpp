#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    IConta *C = new Conta("João", 100, 2, 250);
    IConta *D = new ContaEspecial("Joaquina", 100, 3, 304);

    C->sacar(22);
    C->depositar(20);
    D->sacar(30);
    D->depositar(20);

    Conta C1("João2", 100, 2, 250);
    ContaEspecial C2("Joaquina2", 100, 3, 304);
    C1.Definirlimite();
    C2.Definirlimite();


    return 0;
}
