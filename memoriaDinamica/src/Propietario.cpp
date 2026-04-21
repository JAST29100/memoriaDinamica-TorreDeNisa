#include <iostream>
#include "Propietario.h"

Propietario::Propietario()
    : id{}, nombre{}, propiedad{}{}

void Propietario::mostrarDatos(){
    std::cout << "Detalles del propietario:\n";
    std::cout << "  -Nombre: " << nombre << ", ID: " << id << '\n';

    if (propiedad != NULL){
        std::cout << "Detalles de la propiedad:\n";
        propiedad->mostrarDatos();
    }
    else{std::cout << "No tiene propiedad\n";}
    std::cout << "===============================================\n";
}

const std::string& Propietario::getNombre() const{return nombre;}
Propiedad *Propietario::getPropiedad() const{return propiedad;}
int Propietario::getId() const{return id;}

void Propietario::setNombre(const std::string& nNombre){nombre = nNombre;}
void Propietario::setId(int nId){id = nId;}
void Propietario::setPropiedad(Propiedad* nPropiedad){propiedad = nPropiedad;}
