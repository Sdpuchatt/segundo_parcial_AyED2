#pragma once
#include <string>
#include <iostream>
using namespace std; // Usando namespace std

class Articulo {
private:
    string codigo;
    string nombre;
    double precioUnitario;

public:
    Articulo(const string& cod, const string& nom, double precio)
        : codigo(cod), nombre(nom), precioUnitario(precio) {}

    string getCodigo() const { return codigo; }
    string getNombre() const { return nombre; }
    double getPrecioUnitario() const { return precioUnitario; }

    void mostrarInfo() const {
        cout << "  [Articulo] Cod: " << codigo << ", Nombre: " << nombre 
                  << ", Precio: $" << precioUnitario << endl;
    }
};