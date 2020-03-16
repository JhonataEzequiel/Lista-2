#include "Header.h"
#include <iostream>
#include <exception>

using namespace std;

int main()
{
    int numero;
    cin >> numero;
    TestaValidaNumero t;
    try{
        t.valida(numero);
    }catch(ExcecaoCustomizada e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}