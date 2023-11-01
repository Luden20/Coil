#ifndef HASH_H
#define HASH_H
#include <vector>
#include "../Lista/Lista.h"
#include "../Datos/ClaseDATO.h"
#include "NodosLista.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <functional>
//#include <vector>
class ListaHash{
    private:
        Lista <ListaClave> ListaH;
    public:
        int HashP(std::string st)
            {
                int clave = 0;
                for (int i = 0; i < st.length(); i++)
                {
                    char c = st[i];
                    if (c != '(' && c != ')')
                    {
                        clave += static_cast<int>(c) * (i + 1); // Multiplicar por la posición
                    }
                }
                clave = clave % 232;
                return clave;
            }
        ListaClave Buscar(int clave)//Es una busqueda provisional, luego hare una mejor con interpolacion
        {
            cout<<"Se esta buscando \n";
            int claveActual;
            ListaClave aux;
            for(int i=0;i<ListaH.getTamanio();i++)
            {
                cout<<"Se esta buscando en la pos"<<i<<"\n";
                aux=ListaH.getDato(i);
                claveActual=aux.getClave();
                if(clave==claveActual)
                {
                    break;
                }
            }
            return aux;
        }
        void Insertar(Datos dato) {
            cout<<"Se intenta insertar\n";
            int clave=HashP(dato.getArticulo());
            ListaClave au(clave,dato);
            ListaClave aux=Buscar(clave);
            if(aux.getClave()==-1)
            {//No existe con esa clave asi que creo una y la inserto al final
                cout<<"Se inserto al final";
                ListaH.insertarUltimo(au);
            }
            else
            {
                cout<<"Ya existia y se le agrego mas\n";
                aux.Insertar(dato);
            }
        }
        ListaHash(std::string NombreArchivo)
        {
            cout<<"comenzando a crear..\n";
             setlocale(LC_ALL, "spanish");
            std::string linea, aux;
            char l = ',';
            ifstream archivo(NombreArchivo);
            std::getline(archivo, linea); // Read and discard the header line
            while (getline(archivo, linea)) {
                std::stringstream stream(linea);
                std::string Grupo, CodigoBarras, Articulo, d1, d2, d3, d4, d5;
                int D1 = 0, D2 = 0, D3 = 0, D4 = 0, D5 = 0;
                std::getline(stream, Grupo, l);
                if (Grupo != "") {
                    aux = Grupo;
                }
                Grupo = aux;
                std::getline(stream, CodigoBarras, l);
                std::getline(stream, Articulo, l);
                std::getline(stream, d1, l);
                std::getline(stream, d2, l);
                std::getline(stream, d3, l);
                std::getline(stream, d4, l);
                std::getline(stream, d5, l);
                if (!d1.empty()) {
                    D1 = std::stoi(d1);
                }
                if (!d2.empty()) {
                    D2 = std::stoi(d2);
                }
                if (!d3.empty()) {
                    D3 = std::stoi(d3);
                }
                if (!d4.empty()) {
                    D4 = std::stoi(d4);
                }
                if (!d5.empty()) {
                    D5 = std::stoi(d5);
                }
                Datos aux(Grupo, CodigoBarras, Articulo, D1, D2, D3, D4, D5);
                Insertar(aux);
            }
            cout<<"Se termino la creacion\n\n\n\n\n\n";
        }
};
#endif
