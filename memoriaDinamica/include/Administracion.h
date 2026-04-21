#ifndef ADMINISTRACION_H
#define ADMINISTRACION_H

#include <iostream>
#include <vector>
#include "Propietario.h"
#include "Propiedad.h"

class Administracion{
private:
    double cobroAscensor;
    double costoBase;
    double recargo;
    double areaRecargo;
    int propIds;
    int utilIds;
    std::vector<Propietario*> propietarios;
    std::vector<Propiedad*> propiedades;

    void inicializarDatos();

public:
    Administracion();
    ~Administracion();

    void imprimirPropietariosConParqueadero();
    void imprimirUnPropietario(int id);
    void imprimirPropietarios();
    void imprimirPropietariosSinCuarto();
    void imprimirPropietariosCuartoUtil(bool isTerminado);

    void recaudarAdministracion();
    void generarReportePropiedades();
    void reporteMayorAdministracion();
    void reporteMenorArea();
    void reporteMenorPiso();
    void reporteMayorPiso();

    void agregarPropiedad();
    void agregarPropietario();
    void relacionarPropietarioPropiedad();
};

#endif
