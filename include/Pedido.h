#pragma once
#include "Proveedor.h"
#include "Empleado.h"
#include "DetallePedido.h"
#include <vector>
#include <string>
using namespace std;

class Pedido {
private:
    int nroPedido;
    string fecha; // Simplificado como string
    const Proveedor* proveedor;
    const Empleado* empleadoSolicitante;
    vector<DetallePedido> detalles; 

public:
    Pedido(int nro, const Proveedor* prov, const Empleado* emp);

    void agregarDetalle(const Articulo* art, int cantidad);
    double calcularTotal() const;
    void mostrarDetalles() const;
};