#pragma once
#include <string>
#include <iostream>
using namespace std;

class Proveedor {
private:
    string cuit;
    string razonSocial;
    string contacto;

public:
    Proveedor(const string& c, const string& rs, const string& cont)
        : cuit(c), razonSocial(rs), contacto(cont) {}

    string getCuit() const { return cuit; }
    string getRazonSocial() const { return razonSocial; }
    string getContacto() const { return contacto; }
};