#pragma once
#include <string>
#include <iostream>
using namespace std;

class Empleado {
private:
    string legajo;
    string nombre;
    string apellido;

public:
    Empleado(const string& leg, const string& nom, const string& ape)
        : legajo(leg), nombre(nom), apellido(ape) {}

    string getLegajo() const { return legajo; }
    string getNombre() const { return nombre; }
    string getApellido() const { return apellido; }
    string getNombreCompleto() const { return nombre + " " + apellido; }
};