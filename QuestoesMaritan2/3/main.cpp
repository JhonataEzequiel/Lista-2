#include <iostream>
#include "Header.h"
#include <vector>
#include <exception>
using namespace std;

int main()
{
    Funcionario *f1 = new Assalariado(100, "Francisco", 2019);
    cout << f1[0].calculaSalario() << endl;
    Funcionario *f2 = new Horista(200, "Jamanta", 2020, 15, 45);
    cout << f2[0].calculaSalario() << endl;
    Funcionario *f3 = new Comissionado(300, "JoaquimJoseDaSilvaJavier", 2021, 5, 15);
    cout << f3[0].calculaSalario() << endl;
    SistemaGerenciaFolha s(1000);
    s.setFuncionario(f1[0]); s.setFuncionario(f2[0]); s.setFuncionario(f3[0]);
    try{
        cout << s.calculaValorTotalFolha() << endl;
    }
    catch(OrcamentoEstouradoException e1)
    {
        cerr << "Erro: " << e1.what() << endl;
    }
    catch(...)
    {
        cerr << "Erro inesperado!\n" << endl;
    }
    try{
        cout << s.consultaSalarioFuncionario("Jamanta2") << endl;
    }
    catch(FuncionarioNaoExisteException e)
    {
        cerr << "Erro: " << e.what() << endl;
    }
    catch(...)
    {
        cerr << "Erro inesperado!\n" << endl;
    }

    return 0;
}
