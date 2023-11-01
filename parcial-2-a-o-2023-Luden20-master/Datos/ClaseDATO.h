#ifndef ClaseDATO
#define ClaseDATO
#include <string>
using namespace std;
/*
Clase Dato
Sirve para guardar la informacion de cada linea
Cada instancia de la clase contiene en string la informacion de grupo, codigo de varras y articulo
mientras se gurdan en ints la cantidad de stock en cada deposito
*/
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
    int total;

public:
    // Constructor sin argumentos
    Datos() {
        Grupo = "";
        CodigoBarras = "";
        Articulo = "NULL";
        D1 = 0;
        D2 = 0;
        D3 = 0;
        D4 = 0;
        D5 = 0;
        total=0;
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
        this->total=D1+D2+D3+D4+D5;
    }
    //No hay get  en c++, asi que me las arregle haciendo esto
    int getD1(){return D1;}
    int getD2(){return D2;}
    int getD3(){return D3;}
    int getD4(){return D4;}
    int getD5(){return D5;}
    int getTotal(){int i=D1+D2+D3+D4+D5;return i ;}
    int getD(int deposito)
    {
        int total;
        switch (deposito)
                    {
                        case 1:
                            total=D1;
                            break;
                        case 2:
                            total=D2;
                            break;
                        case 3:
                            total=D3;
                            break;
                        case 4:
                            total=D4;
                            break;
                        case 5:
                            total=D5;
                            break;
                    }
        return total;
    }
    std::string getGrupo(){return Grupo;}
    std::string getCodigoBarras(){return CodigoBarras;}
    std::string getArticulo(){return Articulo;}
    bool Vacio()
    {
        bool r=false;
        if(Articulo=="NULL")
        {
            r=true;
        }
        return r;
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
};

#endif
