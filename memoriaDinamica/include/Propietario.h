#ifndef PROPIETARIO_H
#define PROPIETARIO_H

#include <iostream>
#include "Propiedad.h"

class Propietario{
private:
    int id;
    std::string nombre;
    Propiedad* propiedad;

public:
    Propietario();

    const std::string& getNombre() const;
    Propiedad* getPropiedad() const;
    int getId() const;

    void setNombre(const std::string& nNombre);
    void setPropiedad(Propiedad* nPropiedad);
    void setId(int nId);

    void mostrarDatos();
};

#endif
