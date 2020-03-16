#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ifstream arquivo1("teste.txt", ios::in);
    vector <string> conteudo; string linhas;

    while(!arquivo1.eof())
    {
        getline(arquivo1, linhas);
        conteudo.push_back(linhas);
    }

    for(int i = 0; i < conteudo.size(); i++)
    {
        cout << conteudo[i] << endl;
    }

    arquivo1.close();

    ofstream arquivo2("teste_bkp.txt", ios::out);

    for(int i = 0; i < conteudo.size(); i++)
    {
        arquivo2 << conteudo[i] << endl;
    }

    arquivo2.close();

    return 0;
}