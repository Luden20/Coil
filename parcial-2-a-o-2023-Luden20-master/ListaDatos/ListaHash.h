#ifndef HASH_H
#define HASH_H
#include <vector>
#include "../Lista/Lista.h"
#include "../Datos/ClaseDATO.h"
#include "DatoClave.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <functional>
#include <cmath> 
//#include <vector>
class ListaHash{
    private:
        Lista <DatoClave> ListaH;
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
        void Insertar(Datos dato) {
            int clave=HashP(dato.getArticulo());
            DatoClave aux(clave,dato);
            int pos=PosInsercion(clave);
            ListaH.insertar(pos,aux);
        }
        int PosInsercion(int clave)
        {
            int pos=0,i,claveActual=0;
            DatoClave aux;
            if(ListaH.getTamanio()>0)
            {
                for(i=0;i<ListaH.getTamanio();i++)
                {
                    aux=ListaH.getDato(i);
                    claveActual=aux.getClave();
                    if(claveActual>=clave)
                    {
                        pos=i;
                        break;
                    }
                }
                    if (claveActual < clave) {
                        pos = ListaH.getTamanio();
                    }
            }
            return pos;
        }
        DatoClave Busquedabinaria(std::string ArticuloBuscado) {
            int claveBuscada=HashP(ArticuloBuscado);
            int limiteInferrior = 0;
            int limiteSuperior = ListaH.getTamanio() ; 
            int pasos = 0;
            int claveActual;
            int PosMitad;
            std::string ArticuloActual;
            DatoClave aux,r;

            while (limiteInferrior <= limiteSuperior) {
                pasos++;
                PosMitad = (limiteInferrior + limiteSuperior) / 2;
                if(limiteSuperior-limiteInferrior==1)
                {
                    break;
                }
                aux = ListaH.getDato(PosMitad);
                claveActual = aux.getClave();
                if (claveActual == claveBuscada) {
                    break;
                } 
                else if (claveActual < claveBuscada) {
                    limiteInferrior = PosMitad ;
                } 
                else {
                    limiteSuperior = PosMitad;
                }
            }
            while(true)
            {
                pasos++;
                aux=ListaH.getDato(PosMitad);
                claveActual=aux.getClave();
                if(claveActual!=claveBuscada)
                {
                    break;
                }
                PosMitad--;
            }
            PosMitad++;
            aux=ListaH.getDato(PosMitad);
            while (true)
            {
                aux=ListaH.getDato(PosMitad);
                claveActual=aux.getClave();
                if(claveActual!=claveBuscada)
                {
                    break;
                }
                ArticuloActual=ListaH.getDato(PosMitad).getDato().getArticulo();
                if(ArticuloActual==ArticuloBuscado)
                {
                    r=aux;
                    break;
                }
                PosMitad++;
            }
            cout << "Pasos " << pasos << "\n";
            return r;
        }
        int stock(std::string nombre_articulo)
        {
            DatoClave aux=Busquedabinaria(nombre_articulo);
            int st=aux.getDato().getTotal();
            if(aux.getClave()!=-1)
            {
                cout<<"El articulo "<<aux.getDato().getArticulo()<<" tiene "<<st<<" de stock\n";
            }
            else
            {
                cout<<"El articulo "<<nombre_articulo<< "no existe\n";
            }      
            return st;
        }
        int stock(std::string nombre_articulo,int Deposito)
        {
            DatoClave aux=Busquedabinaria(nombre_articulo);
            int st=aux.getDato().getD(Deposito);
            if(aux.getClave()!=-1)
            {
                cout<<"El articulo "<<aux.getDato().getArticulo()<<" tiene "<<st<<" de stock\n";
            }
            else
            {
                cout<<"El articulo "<<nombre_articulo<< "no existe\n";
            }      
            return st;
        }
        void Ver()
        {
            int clave;
            Datos aux;
            DatoClave aux2;
            for(int i=0;i<ListaH.getTamanio();i++)
            {
                aux2=ListaH.getDato(i);
                aux=aux2.getDato();
                clave=aux2.getClave();
                cout<<"Clave:"<<clave<<"Articulo"<<aux.getArticulo()<<"\n";
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
