#include <iostream>
#include "Header.h"
#include <exception>
using namespace std;

int main()
{
    IConta *C = new Conta("Jo�o", 100, 2, 250);
    IConta *D = new ContaEspecial("Joaquina", 100, 3, 304);

    C->sacar(22);
    C->depositar(20);
    D->sacar(30);
    D->depositar(20);

    Conta C1("Joao2", 100, 2, 250);
    ContaEspecial C2("Joaquina2", 100, 3, 304);
    C1.Definirlimite();
    C2.Definirlimite();

    try{
        C->sacar(400);
    }catch(SaldoNaoExisteException e)
    {
        cerr << e.what() << endl;
    }


    return 0;
}
