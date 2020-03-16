#ifndef CABECALHO_H
#define CABECALHO_H
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Pedido{
public:
    int numero;
    string descricao;
    int quantidade;
    double preco;
    Pedido();
};
class MesaDoRestaurante
{
public:
    vector <Pedido> pedidos;
    void adicionaAoPedido(Pedido pedido);
    void zeraPedidos();
    double calculaTotal();
};
class RestauranteCaseiro
{
public:
    vector <MesaDoRestaurante> mesas;
    void adicionaAoPedido(Pedido pedido);
    double calculaTotalRestaurante();
    void setMesas(MesaDoRestaurante mesa);
};
Pedido::Pedido()
{
    numero = 0;
    descricao = "\0";
    quantidade = 0;
    preco = 0;
}
void MesaDoRestaurante::adicionaAoPedido(Pedido pedido)
{
    pedidos.push_back(pedido);
}
void MesaDoRestaurante::zeraPedidos()
{
    for(unsigned int i = 0; i < pedidos.size(); i++)
        pedidos[i].quantidade = 0;
}
double MesaDoRestaurante::calculaTotal()
{
    double preco = 0;

    for(unsigned int i = 0; i < pedidos.size() && pedidos[i].quantidade != 0; i++)
        preco += pedidos[i].preco;

    return preco;
}
void RestauranteCaseiro::setMesas(MesaDoRestaurante mesa)
{
    mesas.push_back(mesa);
}
void RestauranteCaseiro::adicionaAoPedido(Pedido pedido)
{
    for(unsigned int i = 0; i < mesas.size(); i++)
        mesas[i].adicionaAoPedido(pedido);

}
double RestauranteCaseiro::calculaTotalRestaurante()
{
    double precoTotal = 0;
    for(unsigned int i = 0; i<mesas.size() && (mesas[i].pedidos[i].quantidade != 0); i++)
        precoTotal += mesas[i].calculaTotal();

    return precoTotal;
}
#endif // CABEçALHO_H
