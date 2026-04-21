#ifndef PROPIEDAD_H
#define PROPIEDAD_H

#include <iostream>
#include "CuartoUtil.h"

class Propiedad{
private:
    int id;
    int piso;
    double area;
    bool hayParqueadero;
    CuartoUtil *cuartoUtil;

public:
    Propiedad();
    Propiedad(int id, int piso, double area, bool hayParqueadero, CuartoUtil *cuartoUtil);
    ~Propiedad();

    double calcularRecargo(double cobroAscensor, double costoBase, double recargo, double areaRecargo);

    void mostrarDatos();

    int getId() const;
    void setId(int nId);
    int getPiso() const;
    void setPiso(int nPiso);
    double getArea() const;
    void setarea(double narea);
    bool getHayParqueadero() const;
    void setHayParqueadero(bool nHayParqueadero);

    CuartoUtil *getCuartoUtil() const;
    void setCuartoUtil(CuartoUtil *nCuartoUtil);
};

#endif
