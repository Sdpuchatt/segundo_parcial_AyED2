#include "SistemaGestion.h"
#include <iostream>
#include <algorithm>
using namespace std;

void SistemaGestion::cargarArticulo(const string& cod, const string& nom, double precio) {
    articulos.emplace_back(cod, nom, precio);
}

void SistemaGestion::cargarProveedor(const string& c, const string& rs, const string& cont) {
    proveedores.emplace_back(c, rs, cont);
}

void SistemaGestion::cargarEmpleado(const string& leg, const string& nom, const string& ape) {
    empleados.emplace_back(leg, nom, ape);
}

const Articulo* SistemaGestion::buscarArticulo(const string& nombreArticulo) const {
    for (const auto& art : articulos) {
        if (art.getNombre() == nombreArticulo) {
            return &art;
        }
    }
    return nullptr;
}

const Proveedor* SistemaGestion::buscarProveedor(const string& razonSocial) const {
    for (const auto& prov : proveedores) {
        if (prov.getRazonSocial() == razonSocial) {
            return &prov;
        }
    }
    return nullptr;
}

const Empleado* SistemaGestion::buscarEmpleado(const string& legajo) const {
    for (const auto& emp : empleados) {
        if (emp.getLegajo() == legajo) {
            return &emp;
        }
    }
    return nullptr;
}

Pedido& SistemaGestion::crearNuevoPedido(const Proveedor* prov, const Empleado* emp) {
    pedidos.emplace_back(contadorPedidos++, prov, emp);
    return pedidos.back(); 
}

void SistemaGestion::mostrarPedidosAProveedores() const {
    if (pedidos.empty()) {
        cout << "\n--- No hay pedidos registrados ---" << endl;
        return;
    }
    cout << "\n*** REPORTE DE TODOS LOS PEDIDOS A PROVEEDORES ***" << endl;
    for (const auto& pedido : pedidos) {
        pedido.mostrarDetalles();
    }
    cout << "\n***************************************************" << endl;
}