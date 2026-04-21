#include <iostream>
#include "CuartoUtil.h"

CuartoUtil::CuartoUtil()
    : id{}, piso{}, estado{}{}
CuartoUtil::CuartoUtil(int nId, int nPiso, bool nEstado)
    : id{nId}, piso{nPiso}, estado{nEstado}{}

void CuartoUtil::mostrarDatos(){
    std::cout << "  -ID: " << id << ", ";
    std::cout << "Piso: " << piso << '\n';
    std::cout << "  -El cuarto esta: " << (getEstado() ? "Terminado\n" : "No terminado\n");
}

int CuartoUtil::getId() const{return id;}
void CuartoUtil::setId(int nId){id = nId;}

int CuartoUtil::getPiso() const{return piso;}
void CuartoUtil::setPiso(int nPiso){piso = nPiso;}

bool CuartoUtil::getEstado() const{return estado;}
void CuartoUtil::setEstado(bool nEstado){estado = nEstado;}
