#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using namespace std;

class Datos {
private:
    std::string Grupo;
    std::string CodigoBarras;
    std::string Articulo;
    int D1;
    int D2;
    int D3;
    int D4;
    int D5;

public:
    // Constructor sin argumentos
    Datos() {
        Grupo = "";
        CodigoBarras = "";
        Articulo = "";
        D1 = 0;
        D2 = 0;
        D3 = 0;
        D4 = 0;
        D5 = 0;
    }

    // Constructor con argumentos
    Datos(std::string Grupo, std::string CodigoBarras, std::string Articulo, int D1, int D2, int D3, int D4, int D5) {
        this->Grupo = Grupo;
        this->CodigoBarras = CodigoBarras;
        this->Articulo = Articulo;
        this->D1 = D1;
        this->D2 = D2;
        this->D3 = D3;
        this->D4 = D4;
        this->D5 = D5;
    }
    void ver() {
        std::cout << "Grupo: " << Grupo << std::endl;
        std::cout << "Código de Barras: " << CodigoBarras << std::endl;
        std::cout << "Artículo: " << Articulo << std::endl;
        std::cout << "D1: " << D1 << std::endl;
        std::cout << "D2: " << D2 << std::endl;
        std::cout << "D3: " << D3 << std::endl;
        std::cout << "D4: " << D4 << std::endl;
        std::cout << "D5: " << D5 << std::endl;
    }
    int getD1(){return D1;}
};

#endif
