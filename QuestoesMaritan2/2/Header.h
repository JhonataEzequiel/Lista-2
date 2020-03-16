#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <exception>
using namespace std;

class SaldoNaoExisteException : public exception
{
    public:
    virtual const char* what()
    {
        return "Saldo Nao Disponivel\n";
    }
};

class IConta
{
public:
   virtual void sacar(double valor) = 0;
   virtual void depositar(double valor) = 0;
};
class Conta : public IConta
{
protected:
    string nomeDoCliente;
    int numeroconta;
    double limite;
    double saldo;
    double salariomensal;
public:
    void sacar(double valor)
    {
        if(saldo >= valor){
            saldo = saldo - valor;
        }else
        {
            throw SaldoNaoExisteException();
        }
        
    }
    void depositar (double valor)
    {
        saldo = saldo + valor;
    }
    string getNome()
    {
        return nomeDoCliente;
    }
    double getSalariomensal()
    {
        return salariomensal;
    }
    int getnumero()
    {
        return numeroconta;
    }
    double getSaldo()
    {
        return saldo;
    }
    double getLimite()
    {
        return limite;
    }
    void setNome(string nome)
    {
        nomeDoCliente = nome;
    }
    void setSalariomensal(double salario)
    {
        salariomensal = salario;
    }
    void setnumero(int n)
    {
        numeroconta = n;
    }
    void setSaldo(double saldo)
    {
        this -> saldo = saldo;
    }
    Conta(string nome, double salario, int n, double saldo)
    {
        nomeDoCliente = nome;
        salariomensal = salario;
        numeroconta = n;
        this -> saldo = saldo;
    }
    void Definirlimite()
    {
        limite = salariomensal*2;
    }
};
class ContaEspecial : public Conta
{
public:
    void sacar(double valor)
    {
        if(saldo >= valor){
            saldo = saldo - valor;
        }else
        {
            throw SaldoNaoExisteException();
        }
    }
    void depositar (double valor)
    {
        saldo = saldo + valor;
    }
    void Definirlimite()
    {
        limite = salariomensal*3;
    }
    ContaEspecial(string nome, double salario, int n, double saldo);
};

ContaEspecial::ContaEspecial(string nome, double salario, int n, double saldo) : Conta(nome, salario, n, saldo){}


#endif // HEADER_H
