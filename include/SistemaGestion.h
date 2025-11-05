#pragma once
#include "Articulo.h"
#include "Proveedor.h"
#include "Empleado.h"
#include "Pedido.h"
#include <vector>
#include <string>
using namespace std;

class SistemaGestion {
private:
    vector<Articulo> articulos;
    vector<Proveedor> proveedores;
    vector<Empleado> empleados;
    vector<Pedido> pedidos;
    int contadorPedidos = 1;

public:
    void cargarArticulo(const string& cod, const string& nom, double precio);
    void cargarProveedor(const string& c, const string& rs, const string& cont);
    void cargarEmpleado(const string& leg, const string& nom, const string& ape);

    const Articulo* buscarArticulo(const string& nombreArticulo) const;
    const Proveedor* buscarProveedor(const string& razonSocial) const;
    const Empleado* buscarEmpleado(const string& legajo) const;
    
    Pedido& crearNuevoPedido(const Proveedor* prov, const Empleado* emp);
    void mostrarPedidosAProveedores() const; 
};