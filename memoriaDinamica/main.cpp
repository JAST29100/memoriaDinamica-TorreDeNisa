#include <iostream>
#include <limits>
#include "Administracion.h"

void limpiarPantalla(){
    std::cout << "\033[H\033[2J\033[3J";
}

void mostrarMenuPropietarios(Administracion &adminMenuProp){
    int opcPropietarios{};

    std::cout << "\nMenu de propietarios ... \n";
    std::cout << "1. Mostrar propietarios \n";
    std::cout << "2. Propietarios con parqueadero \n";
    std::cout << "3. Propietarios sin cuarto util\n";
    std::cout << "4. Propietarios con cuarto util sin terminar \n";
    std::cout << "5. Propietarios con cuarto util terminado \n";
    std::cout << "6. Agregar propietario\n";
    std::cout << "7. Mostrar un propietario dado su Id\n";
    std::cout << "-1. Volver\n";
    std::cout << "\nIngrese una opcion: ";
    std::cin >> opcPropietarios;

    bool isCuartoTerminado{};
    int idPropietario{};

    limpiarPantalla();
    switch(opcPropietarios){
    case 1:
        adminMenuProp.imprimirPropietarios();
        break;
    case 2:
        adminMenuProp.imprimirPropietariosConParqueadero();
        break;
    case 3:
        adminMenuProp.imprimirPropietariosSinCuarto();
        break;
    case 4:
        isCuartoTerminado = false;
        adminMenuProp.imprimirPropietariosCuartoUtil(isCuartoTerminado);
        break;
    case 5:
        isCuartoTerminado = true;
        adminMenuProp.imprimirPropietariosCuartoUtil(isCuartoTerminado);
        break;
    case 6:
        adminMenuProp.agregarPropietario();
        break;
    case 7:
        std::cout << "Ingrese el ID del propetario: ";
        std::cin >> idPropietario;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ingrese un ID valido\n";
            mostrarMenuPropietarios(adminMenuProp);
            break;
        }
        adminMenuProp.imprimirUnPropietario(idPropietario);
        break;
    case -1:
        break;
    default:
        std::cout << "Ingrese una opcion valida\n";
        mostrarMenuPropietarios(adminMenuProp);
        break;
    }
}

void mostrarMenuAdministracion(Administracion& administracionMenuAdmin){
    int opc{};
    std::cout << "\nMenu de administracion ... \n";
    std::cout << "1. Recaudar administracion \n";
    std::cout << "2. Generar reporte general\n";
    std::cout << "3. Asociar propietario-propiedad \n";
    std::cout << "4. Agregar propiedad \n";
    std::cout << "5. Propietario con mayor costo de administracion\n";
    std::cout << "6. Propietario con menor area de propiedad\n";
    std::cout << "7. Propietario con menor piso de propiedad\n";
    std::cout << "8. Propietario con mayor piso de propiedad\n";
    std::cout << "-1. Volver\n";
    std::cout << "\nIngrese una opcion: ";
    std::cin >> opc;

    limpiarPantalla();
    switch (opc){
    case 1:
        administracionMenuAdmin.recaudarAdministracion();
        break;
    case 2:
        administracionMenuAdmin.generarReportePropiedades();
        break;
    case 3:
        administracionMenuAdmin.relacionarPropietarioPropiedad();
        break;
    case 4:
        administracionMenuAdmin.agregarPropiedad();
        break;
    case 5:
        administracionMenuAdmin.reporteMayorAdministracion();
        break;
    case 6:
        administracionMenuAdmin.reporteMenorArea();
        break;
    case 7:
        administracionMenuAdmin.reporteMenorPiso();
        break;
    case 8:
        administracionMenuAdmin.reporteMayorPiso();
        break;
    case -1:
        break;
    default:
        std::cout << "Ingrese una opcion valida\n";
        mostrarMenuAdministracion(administracionMenuAdmin);
        break;
    }
}

void menu(Administracion& administracionMenu){
    int opc{};
    while(opc != -1){
        std::cout << "\n****Bienvenidos****\n";
        std::cout << "1. Mostrar menu Propietarios \n";
        std::cout << "2. Mostrar menu Administracion \n";
        std::cout << "-1. Salir \n";
        std::cout << "\nIngrese una opcion: ";

        std::cin >> opc;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        limpiarPantalla();
        switch(opc){
        case 1:
            mostrarMenuPropietarios(administracionMenu);
            break;
        case 2:
            mostrarMenuAdministracion(administracionMenu);
            break;
        case -1:
            break;
        default:
            std::cout << "Ingrese una opcion valida\n";
            break;
        }
    }
}

int main(){
    Administracion administracion; // Instanciado con el stack
    menu(administracion);
    return 0;
}
