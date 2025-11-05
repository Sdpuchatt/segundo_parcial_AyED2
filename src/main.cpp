#include "SistemaGestion.h"
#include <iostream>
using namespace std;

void ejecutarDemo(SistemaGestion& sistema) {
    // 1. Cargar Entidades (Artículos, Proveedores, Empleados)
    cout << "--- 1. CARGANDO DATOS INICIALES ---" << endl;
    sistema.cargarArticulo("A001", "Tornillo M6", 0.15);
    sistema.cargarArticulo("A002", "Placa PCB Arduino", 3.50);
    sistema.cargarArticulo("A003", "Resistencia 10kOhm", 0.05);

    sistema.cargarProveedor("30-123456-1", "ProMetal S.A.", "contacto@prometal.com");
    sistema.cargarProveedor("20-987654-2", "Electronica Rapida", "ventas@elecrapida.net");

    sistema.cargarEmpleado("EMP001", "Maria", "Gomez");
    sistema.cargarEmpleado("EMP002", "Carlos", "Ruiz");

    // Búsqueda de referencias para el pedido (simula la interacción del usuario)
    const Articulo* art1 = sistema.buscarArticulo("Tornillo M6");
    const Articulo* art2 = sistema.buscarArticulo("Placa PCB Arduino");
    const Proveedor* prov1 = sistema.buscarProveedor("ProMetal S.A.");
    const Proveedor* prov2 = sistema.buscarProveedor("Electronica Rapida"); // Nota: Corregí el acento para que coincida con la carga
    const Empleado* emp1 = sistema.buscarEmpleado("EMP001");
    
    // 4. Cargar Pedidos Asignados a Proveedores
    cout << "\n--- 2. GENERANDO PEDIDOS ---" << endl;
    
    if (art1 && prov1 && emp1) {
        // Pedido 1: A ProMetal por Tornillos
        Pedido& p1 = sistema.crearNuevoPedido(prov1, emp1);
        p1.agregarDetalle(art1, 5000); 
    }

    if (art2 && prov2 && emp1) {
        // Pedido 2: A Electronica Rapida por Placas y Resistencias
        Pedido& p2 = sistema.crearNuevoPedido(prov2, emp1);
        p2.agregarDetalle(art2, 100); 
        const Articulo* art3 = sistema.buscarArticulo("Resistencia 10kOhm");
        if (art3) {
            p2.agregarDetalle(art3, 2000); 
        }
    }

    // 5. Mostrar los pedidos a los Proveedores (y por consola)
    sistema.mostrarPedidosAProveedores();
}

int main() {
    SistemaGestion sistema;
    ejecutarDemo(sistema);
    
    return 0;
}