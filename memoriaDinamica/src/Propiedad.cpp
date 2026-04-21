#include "Propiedad.h"

Propiedad::Propiedad()
    : id{}, piso{}, area{}, hayParqueadero{}, cuartoUtil{}{}
Propiedad::Propiedad(int id, int piso, double area, bool hayParqueadero, CuartoUtil *cuartoUtil)
    : id{id}, piso{piso}, area{area},
        hayParqueadero{hayParqueadero}, cuartoUtil{cuartoUtil}{}
Propiedad::~Propiedad(){
    delete cuartoUtil;
    cuartoUtil = nullptr;
}

void Propiedad::mostrarDatos(){
    std::cout << "  -ID: " << id << ", ";
    std::cout << "Piso: " << piso << ", ";
    std::cout << "Area: " << area << '\n';
    std::cout << "  -Tiene parqueadero: " << (hayParqueadero ? "Si\n" : "No\n");
    if (cuartoUtil != nullptr){
        std::cout << "Detalles del cuarto util:\n";
        cuartoUtil->mostrarDatos();
    }
    else{std::cout << "No tiene cuarto util\n";}
}

double Propiedad::calcularRecargo(double cobroAscensor, double costoBase, double recargo, double areaRecargo){
    double total;

    if(area > areaRecargo){
        total = (cobroAscensor * piso) + ((costoBase * recargo) + costoBase);
    }
    else{
        total = (cobroAscensor * piso) + costoBase;
    }
    if (cuartoUtil && !cuartoUtil->getEstado()){total -= (total * 0.01);}

    return total;
}

int Propiedad::getId() const{return id;}
void Propiedad::setId(int nId){id = nId;}

int Propiedad::getPiso() const{return piso;}
void Propiedad::setPiso(int nPiso){piso = nPiso;}

double Propiedad::getArea() const{return area;}
void Propiedad::setarea(double narea){area = narea;}

bool Propiedad::getHayParqueadero() const{return hayParqueadero;}
void Propiedad::setHayParqueadero(bool nHayParqueadero){hayParqueadero = nHayParqueadero;}

CuartoUtil *Propiedad::getCuartoUtil() const{return cuartoUtil;}
void Propiedad::setCuartoUtil(CuartoUtil *nCuartoUtil){cuartoUtil = nCuartoUtil;}
