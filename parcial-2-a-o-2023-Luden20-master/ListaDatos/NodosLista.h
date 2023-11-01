#ifndef NODOLISTA_H
#define NODOLISTA_H
#include <vector>
#include "../Lista/Lista.h"
#include "../Datos/ClaseDATO.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <functional>
#include <vector>
class ListaClave{
    private:
        Lista <Datos> lista;
        int clave;
    public:
        ListaClave(int clave)
        {
            this->clave=clave;
        }
        ListaClave(int clave,Datos dato)
        {
            this->clave=clave;
            lista.insertarUltimo(dato);
        }
        ListaClave()
        {
            this->clave=-1;
        }
        void Insertar(Datos dato)
        {
            lista.insertarUltimo(dato);
        }
        int getClave()
        {
            return clave;
        }
        Datos Busqueda(std::string buscado)
        {
            Datos aux;
            for(int i=0;i<lista.getTamanio();i++)
            {
                aux=lista.getDato(i);
                if(aux.getArticulo()==buscado)
                {
                    break;
                }
            } 
            return aux;
        }
};
#endif
