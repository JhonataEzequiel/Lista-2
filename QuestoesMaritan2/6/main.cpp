#include <vector>
#include <iostream>
#include <string>
#include "cabeçalho.h"
using namespace std;

int main()
{
    Pedido pedido00 = Pedido();
    Pedido pedido01 = Pedido();

    cout << "Adicionando o pedido 00:" << endl;

    pedido00.numero = 10;
    pedido00.descricao = "vinho pisoteado por escravos chineses";
    pedido00.preco = 5000;
    pedido00.quantidade = 33;

    cout << "Adicionando o pedido 01:" << endl;

    pedido01.numero = 11;
    pedido01.descricao = "vinho pisoteado por escravos patagoesneses";
    pedido01.preco = 10;
    pedido01.quantidade = 50;

    MesaDoRestaurante mesa00;
    MesaDoRestaurante mesa01;

    mesa00.adicionaAoPedido(pedido00);
    mesa01.adicionaAoPedido(pedido01);

    RestauranteCaseiro restaurante;

    restaurante.setMesas(mesa00);
    restaurante.setMesas(mesa01);

    cout << "total do restaurante:" << restaurante.calculaTotalRestaurante() << endl;

    restaurante.mesas[0].zeraPedidos();
    restaurante.mesas[1].zeraPedidos();

    cout << "total do restaurante zerado:" << restaurante.calculaTotalRestaurante() << endl;

    return 0;
}
