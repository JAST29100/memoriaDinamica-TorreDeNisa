#ifndef CUARTOUTIL_H
#define CUARTOUTIL_H

#include <string>

class CuartoUtil{
private:
    int id;
    int piso;
    bool estado;

public:
    CuartoUtil();
    CuartoUtil(int nId, int nPiso, bool nEstado);

    void mostrarDatos();

    int getId() const;
    void setId(int nId);

    int getPiso() const;
    void setPiso(int nPiso);

    bool getEstado() const;
    void setEstado(bool nEstado);
};

#endif
