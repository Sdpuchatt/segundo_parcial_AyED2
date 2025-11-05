#pragma once
#include "Articulo.h"
#include <iostream>
using namespace std;

class DetallePedido {
private:
    int cantidad;          // <--- DECLARADO PRIMERO
    const Articulo* articulo; // <--- DECLARADO SEGUNDO

public:
    // CORRECCIÓN: Inicialización en el orden: cantidad, luego articulo
    DetallePedido(const Articulo* art, int cant) 
        : cantidad(cant), articulo(art) {} 

    double calcularSubtotal() const {
        return (articulo != nullptr) ? cantidad * articulo->getPrecioUnitario() : 0.0;
    }

    void mostrarDetalle() const {
        if (articulo != nullptr) {
            cout << "    - " << articulo->getNombre() << " x " << cantidad 
                      << " unidades. Subtotal: $" << calcularSubtotal() << endl;
        } else {
            cout << "    - Detalle con artículo no encontrado." << endl;
        }
    }
};