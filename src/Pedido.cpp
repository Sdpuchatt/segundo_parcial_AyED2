#include "Pedido.h"
#include <numeric>
#include <iostream>
#include <ctime>
using namespace std;

// Constructor (CORRECCIÓN: Orden según la declaración en Pedido.h)
Pedido::Pedido(int nro, const Proveedor* prov, const Empleado* emp)
    : nroPedido(nro), fecha(__DATE__), proveedor(prov), empleadoSolicitante(emp) {}

void Pedido::agregarDetalle(const Articulo* art, int cantidad) {
    detalles.emplace_back(art, cantidad);
}

double Pedido::calcularTotal() const {
    return accumulate(detalles.begin(), detalles.end(), 0.0, 
        [](double total, const DetallePedido& detalle) {
            return total + detalle.calcularSubtotal();
        });
}

void Pedido::mostrarDetalles() const {
    cout << "\n=== PEDIDO N° " << nroPedido << " (" << fecha << ") ===" << endl;
    cout << "  Proveedor: " << proveedor->getRazonSocial() << endl;
    cout << "  Solicitante: " << empleadoSolicitante->getNombreCompleto() << endl;
    cout << "  Articulos solicitados:" << endl;
    for (const auto& detalle : detalles) {
        detalle.mostrarDetalle();
    }
    cout << "  TOTAL DEL PEDIDO: $" << calcularTotal() << endl;
}