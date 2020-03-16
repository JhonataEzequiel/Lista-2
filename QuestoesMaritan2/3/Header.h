#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <vector>
#include <string>
#include <exception>
using namespace std;

class Funcionario
{
protected:
    double salario;
    string nome;
    int matricula;
public:
    Funcionario(){};
    Funcionario(double s, string n, int m){salario = s; nome = n; matricula = m;}
    string getNome(){return nome;}
    void setNome(string n){nome = n;}
    int getMatricula(){return matricula;}
    void setMatricula(int m){matricula = m;}
    void setSalario(double s){salario = s;}
    double getSalario(){return salario;}

    virtual double calculaSalario(){};
};

class Assalariado : public Funcionario
{
public:
    Assalariado(double s, string n, int m) : Funcionario(s, n, m){};
    double calculaSalario()
    {
        return salario;
    }
};

class Horista : public Funcionario
{
    double salarioPorHora;
    double horasTrabalhadas;
public:
    Horista(double s, string n, int m, double salaph, double ht) : Funcionario(s, n, m){salarioPorHora = salaph; horasTrabalhadas = ht;};
    double getSalarioPorHora(){return salarioPorHora;}
    void setSalarioPorHora(double salariop){salarioPorHora = salariop;}
    double gethorasTrabalhadas(){return horasTrabalhadas;}
    void sethorasTrabalhadas(double h){horasTrabalhadas = h;}

    double calculaSalario()
    {
        double horasextras = 0;
        salario = 0;
        if(horasTrabalhadas>=40)
        {
            horasextras = horasTrabalhadas - 40;
            horasTrabalhadas = horasTrabalhadas - horasextras;
            salario = (horasTrabalhadas * salarioPorHora) + (salarioPorHora * horasextras * 1.5);
        }else{
            salario = horasTrabalhadas * salarioPorHora;
        }
        return salario;
    }
};

class Comissionado : public Funcionario
{
    double vendasSemanais;
    double percentualComissao;
public:
    Comissionado(double s, string n, int m, double vendas1, double perc) : Funcionario(s, n, m){vendasSemanais = vendas1; percentualComissao = perc;};
    double getVendas(){return vendasSemanais;}
    void setVendas(double v){vendasSemanais = v;}
    double getPercentual(){return percentualComissao;}
    void setPercentual(double p){percentualComissao = p;}

    double calculaSalario()
    {
        salario += vendasSemanais*(percentualComissao/100);
        return salario;
    }
};

class FuncionarioNaoExisteException : public exception
{
public:
    virtual const char* what()
    {
        return "Funcionario nao existe!\n";
    }
};

class OrcamentoEstouradoException : public exception
{
public:
    virtual const char* what()
    {
        return "Orcamento Estourado";
    }
};

class SistemaGerenciaFolha
{
    vector<Funcionario> f;
    double orcamento;
public:
    void setFuncionario(Funcionario f1)
    {
        f.push_back(f1);
    }

    double consultaSalarioFuncionario(string n)
    {
        unsigned int aux = f.size()+1;
        for(unsigned int i=0; i < f.size(); i++)
        {
            if((f[i].getNome()).compare(n) == 0)
            {
                aux = i;
            }
        }
        if(aux <= f.size())
        {
            return f[aux].getSalario();
        }else{
            throw FuncionarioNaoExisteException();
        }

    }
    double calculaValorTotalFolha()
    {
        double total = 0;
        for(unsigned int i = 0; i < f.size(); i++)
        {
            total += f[i].getSalario();
        }
        if(orcamento >= total)
        {
            return total;
        }else{
            throw OrcamentoEstouradoException();
        }

    }
    SistemaGerenciaFolha(double orc){orcamento = orc;}
};



#endif // HEADER_H
