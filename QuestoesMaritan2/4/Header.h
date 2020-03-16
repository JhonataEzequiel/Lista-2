#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <exception>
using namespace std;

class ExcecaoCustomizada: public exception
{
    const char* msg;
    public:
    ExcecaoCustomizada(const char* msg)
    {
        this -> msg = msg;
    }
    virtual const char* what()
    {
        return msg;
    }
};

class TestaValidaNumero
{
    public:
    void valida(int num)
    {
        if(num <- 0)
        {
            throw ExcecaoCustomizada("Numero menor ou igual a zero\n");
        }
        if(num > 100 && num < 1000)
        {
            throw ExcecaoCustomizada("Numero entre 100 e 1000\n");
        }else if(num >= 1000)
        {
            throw ExcecaoCustomizada("Numero maior ou igual a 1000\n");
        }else
        {
            throw ExcecaoCustomizada("Numero entre 100 e 0\n");
        }
        
    }
};

#endif 