#include <iostream>
#include <iomanip>
#include "Administracion.h"

Administracion::Administracion()
    :cobroAscensor{15'000}, costoBase{150'000}, recargo{0.05},
        areaRecargo{150}, propIds{}, utilIds{}{
    std::cout << "Entre al constructor de administracion\n";
    inicializarDatos();
    std::cout << "Terminé la inicializacion\n";
}
Administracion::~Administracion(){
    for(Propietario* p : propietarios){delete p;}
    for(Propiedad* p : propiedades){delete p;}

    std::cout << "LLame al destructor, elimine todo y termine\n";
}
void Administracion::inicializarDatos(){
    Propietario *persona1 = new Propietario();
    std::cout << "(Propietario) Se ha creado: Debora vilar\n";
    Propietario *persona2 = new Propietario();
    std::cout << "(Propietario) Se ha creado: Ignacio Rodriguez\n";
    Propietario *persona3 = new Propietario();
    std::cout << "(Propietario) Se ha creado: Erika Munoz\n";
    Propietario *persona4 = new Propietario();
    std::cout << "(Propietario) Se ha creado: Modesto Villaverde\n";
    Propiedad *prop1 = new Propiedad();
    std::cout << "(Propiedad) Se ha creado: 1\n";
    Propiedad *prop2 = new Propiedad();
    std::cout << "(Propiedad) Se ha creado: 2\n";
    Propiedad *prop3 = new Propiedad();
    std::cout << "(Propiedad) Se ha creado: 3\n";
    Propiedad *prop4 = new Propiedad();
    std::cout << "(Propiedad) Se ha creado: 4\n";
    CuartoUtil *cuarto1 = new CuartoUtil();
    std::cout << "(CuartoUtil) Se ha creado: 1\n";
    CuartoUtil *cuarto2 = new CuartoUtil();
    std::cout << "(CuartoUtil) Se ha creado: 2\n";
    CuartoUtil *cuarto3 = new CuartoUtil();
    std::cout << "(CuartoUtil) Se ha creado: 3\n";

    //Inicializar cuartos utiles
    std::vector<CuartoUtil *> cuartosUtiles;
    cuarto1->setPiso(2);
    cuarto1->setId(utilIds++);
    cuarto1->setEstado(false);

    cuarto2->setPiso(2);
    cuarto2->setId(utilIds++);
    cuarto2->setEstado(true);

    cuarto3->setPiso(2);
    cuarto3->setId(utilIds++);
    cuarto3->setEstado(true);

    cuartosUtiles.push_back(cuarto1);
    cuartosUtiles.push_back(cuarto2);
    cuartosUtiles.push_back(cuarto3);

    // Inicializar propiedades
    prop1->setId(propIds++);
    prop1->setarea(160);
    prop1->setHayParqueadero(true);
    prop1->setPiso(10);

    prop2->setId(propIds++);
    prop2->setarea(30);
    prop2->setHayParqueadero(false);
    prop2->setPiso(9);

    prop3->setId(propIds++);
    prop3->setarea(45);
    prop3->setHayParqueadero(true);
    prop3->setPiso(7);

    prop4->setId(propIds++);
    prop4->setarea(60);
    prop4->setHayParqueadero(false);
    prop4->setPiso(5);

    propiedades.push_back(prop1);
    propiedades.push_back(prop2);
    propiedades.push_back(prop3);
    propiedades.push_back(prop4);

    // Inicializar propietarios
    persona1->setNombre("Debora Vilar");
    persona1->setId(20202492);
    persona1->setPropiedad(prop1);
    persona1->getPropiedad()->setCuartoUtil(cuarto1);

    persona2->setNombre("Ignacio Rodriguez");
    persona2->setId(88888);
    persona2->setPropiedad(prop2);
    persona2->getPropiedad()->setCuartoUtil(cuarto2);

    persona3->setNombre("Erika Munoz");
    persona3->setId(1058845781);
    persona3->setPropiedad(prop3);
    persona3->getPropiedad()->setCuartoUtil(cuarto3);

    // Ojo a la persona4 no se le pone cuarto útil a propósito, entonces se debe controlar en el constructor.
    persona4->setNombre("Modesto Villaverde");
    persona4->setId(31321432);
    persona4->setPropiedad(prop4);

    propietarios.push_back(persona1);
    propietarios.push_back(persona2);
    propietarios.push_back(persona3);
    propietarios.push_back(persona4);
}

void Administracion::agregarPropiedad(){
    int piso;
    double area;
    bool parqueadero;
    bool cuarto;

    Propiedad* propTemp;

    std::cout << "Piso de la propiedad: ";
    std::cin >> piso;

    std::cout << "Area de la propiedad: ";
    std::cin >> area;

    std::cout << "[0] No tiene parqueadero\n";
    std::cout << "[1] Tiene parqueadero\n";
    std::cout << "Ingrese una opcion: ";
    std::cin >> parqueadero;

    std::cout << "[0] No tiene cuarto util\n";
    std::cout << "[1] Tiene cuarto util\n";
    std::cout << "Ingrese una opcion: ";
    std::cin >> cuarto;

    if(cuarto){
        int pisoCuarto;
        bool estadoCuarto;

        std::cout << "Piso del cuarto util: ";
        std::cin >> pisoCuarto;

        std::cout << "[0] Sin terminar\n";
        std::cout << "[1] Terminado\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> estadoCuarto;

        CuartoUtil* Cuarto = new CuartoUtil();
        Cuarto->setId(utilIds++);
        Cuarto->setPiso(pisoCuarto);
        Cuarto->setEstado(estadoCuarto);

        propTemp = new Propiedad(propIds++, piso, area, parqueadero, Cuarto);
    }

    else {
        propTemp = new Propiedad(propIds++, piso, area, parqueadero, nullptr);
    }

    propiedades.push_back(propTemp);
    std::cout << "\nPropiedad agregada\n";
}
void Administracion::agregarPropietario(){
    std::string nombre;
    int id;

    std::cout << "Ingrese el nombre: ";
    std::cin.ignore(); // Importante para quitar el salto de línea en caso de que exista
    getline(std::cin, nombre); // Sirve para leer cadenas

    std::cout << "Ingrese el id: ";
    std::cin >> id;

    Propietario *propTemp = new Propietario();
    propTemp->setNombre(nombre);
    propTemp->setId(id);
    propietarios.push_back(propTemp);
}
void Administracion::relacionarPropietarioPropiedad(){
    double id{};
    bool idFound{};
    int idPropiedad{};
    bool idPropiedadFound{};

    int idxTempPropietario{-1};
    int idxTempPropiedad{-1};


    std::cout << "Ingrese el id de la propiedad (-1 para cancelar): ";
    std::cin >> idPropiedad;

    std::cout << "Ingrese id del propietario (-1 para cancelar): ";
    std::cin >> id;

    for(size_t i{}; i < propietarios.size() && !idFound; ++i){
        if (propietarios[i]->getId() == id) {
            // Se verifica que el propietario no tenga previamente una propiedad
            if(propietarios[i]->getPropiedad() == nullptr){
                idFound = true;
                idxTempPropietario = i;
            }
            else{
                std::cout << "No es posible seleccionar el propietario con id " << id
                    << " este propietario ya tiene una propiedad asociada\n";
                break;
            }
        }
    }

    if(!idFound){std::cout << "Id de propietario no encontrado\n";}
    else{
        for(size_t i{}; i < propiedades.size() && !idPropiedadFound; ++i){
            if(propiedades[i]->getId() == idPropiedad){
                idPropiedadFound = true;
                idxTempPropiedad = i;
            }
        }
        if(!idPropiedadFound){
            std::cout << "Id de propiedad no encontrado\n";
        }
    }

    if(idFound && idPropiedadFound){
        Propiedad *propiedadTemp = propiedades[idxTempPropiedad];
        propietarios[idxTempPropietario]->setPropiedad(propiedadTemp);
        std::cout << "Propietario " << propietarios[idxTempPropietario]->getNombre() << " asociado con propiedad "
                << propiedadTemp->getId() << '\n';
    }
}

void Administracion::imprimirUnPropietario(int id){
    bool encontrado{};
    for (size_t i{}; i < propietarios.size() && !encontrado; i++){
        if(propietarios[i]->getId() == id){
            propietarios[i]->mostrarDatos();
            encontrado = true;
        }
    }

    if(!encontrado){std::cout << "ERROR: Propietario con id " << id << " no fue encontrado\n";}
}
void Administracion::imprimirPropietarios(){
    for(Propietario* p : propietarios){p->mostrarDatos();}
}
void Administracion::imprimirPropietariosConParqueadero(){
    std::cout << "Propietarios con parqueadero:\n\n";
    for (Propietario* p : propietarios){
        if(p->getPropiedad() && p->getPropiedad()->getHayParqueadero()){
                p->mostrarDatos();
        }
    }
}
void Administracion::imprimirPropietariosSinCuarto(){
    for(Propietario* p : propietarios){
        if((p->getPropiedad() && !p->getPropiedad()->getCuartoUtil()) || !p->getPropiedad())  {
            p->mostrarDatos();
        }
    }
}
void Administracion::imprimirPropietariosCuartoUtil(bool isTerminado){
    for(Propietario* p : propietarios){
        if(p->getPropiedad() && p->getPropiedad()->getCuartoUtil()
           && p->getPropiedad()->getCuartoUtil()->getEstado() == isTerminado){
                p->mostrarDatos();
        }
    }
}

void Administracion::recaudarAdministracion(){
    double valorAdministracion{};
    for(Propietario* p : propietarios){
        if(p->getPropiedad()){
            valorAdministracion += p->getPropiedad()->calcularRecargo(cobroAscensor, costoBase, recargo, areaRecargo);
            std::cout << p->getPropiedad()->calcularRecargo(cobroAscensor, costoBase, recargo, areaRecargo) << '\n';
        }
    }

    std::cout << std::fixed << std::setprecision(0) << "Total de administracion recaudada: $" << valorAdministracion << '\n';
}

void Administracion::generarReportePropiedades(){
    // Realisticamente solo es llamar imprimirPropietarios y esto deberia dividirse en responsabilidades por objetos pero bue... no mas para practicar
    for(Propietario* p : propietarios){
            std::cout << "Propietario: " << p->getNombre() << ", ID: " << p->getId() << '\n';
            if(p->getPropiedad()){
                std::cout << "  - Propiedad ID: " << p->getPropiedad()->getId() << ", Piso: " << p->getPropiedad()->getPiso()
                    << ", Area: " << p->getPropiedad()->getArea() << '\n';
                std::cout << "  - Tiene parqueadero: " << (p->getPropiedad()->getHayParqueadero() ? "Si\n" : "No\n");

                if(p->getPropiedad()->getCuartoUtil()){
                    std::cout << "  - Cuarto util: " << (p->getPropiedad()->getCuartoUtil()->getEstado() ? "Terminado\n" : "No terminado\n");
                }
                else{std::cout << "  - Cuarto Util: No tiene\n";}
            }
            else{std::cout << "  - No tiene propiedad\n";}
            std::cout << "-----------------------------------------------\n";
    }
    recaudarAdministracion();
}
void Administracion::reporteMayorAdministracion(){
    double mayorCosto{};
    Propietario* mayorPropietario{};

    for(Propietario* p : propietarios){
        if(p->getPropiedad() && (p->getPropiedad()->calcularRecargo(cobroAscensor, costoBase, recargo, areaRecargo) > mayorCosto)){
            mayorCosto = p->getPropiedad()->calcularRecargo(cobroAscensor, costoBase, recargo, areaRecargo);
            mayorPropietario = p;
        }
    }
    mayorPropietario->mostrarDatos();
}
void Administracion::reporteMenorArea(){
    double menorArea{propietarios[0]->getPropiedad()->getArea()};
    Propietario* menorPropietario{propietarios[0]};

    for(Propietario* p : propietarios){
        if(p->getPropiedad() && (p->getPropiedad()->getArea() < menorArea)){
            menorArea = p->getPropiedad()->getArea();
            menorPropietario = p;
        }
    }
    menorPropietario->mostrarDatos();
}

void Administracion::reporteMenorPiso(){
    int menorPiso{propietarios[0]->getPropiedad()->getPiso()};
    Propietario* menorPropietario{propietarios[0]};

    for(Propietario* p : propietarios){
        if(p->getPropiedad() && (p->getPropiedad()->getPiso() < menorPiso)){
            menorPiso = p->getPropiedad()->getPiso();
            menorPropietario = p;
        }
    }
    menorPropietario->mostrarDatos();
}

void Administracion::reporteMayorPiso(){
    int mayorPiso{};
    Propietario* mayorPropietario{};

    for(Propietario* p : propietarios){
        if(p->getPropiedad() && (p->getPropiedad()->getPiso() > mayorPiso)){
            mayorPiso = p->getPropiedad()->getPiso();
            mayorPropietario = p;
        }
    }
    mayorPropietario->mostrarDatos();
}
