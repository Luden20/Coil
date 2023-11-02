#ifndef DATOCLAVE_H
#define DATOCLAVE_H
#include <vector>
#include "../Lista/Lista.h"
#include "../Datos/ClaseDATO.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <functional>
#include <vector>
class DatoClave{
    private:
        Datos dato;
        int clave;
    public:
        DatoClave(int clave)
        {
            this->clave=clave;
        }
        DatoClave(int clave,Datos dato)
        {
            this->clave=clave;
            this->dato=dato;
        }
        DatoClave()
        {
            this->clave=-1;
        }
        int getClave()
        {
            return clave;
        }
};
#endif
