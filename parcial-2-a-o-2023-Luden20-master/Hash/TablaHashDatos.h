#ifndef TABLA_HASH_DATOS_H
#define TABLA_HASH_DATOS_H
#include <vector>
#include "ClaseDATO.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <functional>
#include <vector>
class TablaHashDatos{
    private:
        std::vector<Datos>TablaPrincipal;
        std::vector<Datos>TablaSecundaria;
        int ocupadosPrincipal=0;
        int ocupadosSecundarios=0;
        int dim;
    public:
        TablaHashDatos(int size)
        {
            this->dim = size;
            TablaPrincipal.resize(size);
            TablaSecundaria.resize(size);
        }
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
            clave = clave % dim;
            return clave;
        }
        void InsertarDatoPrincipal(int pos,Datos dato)
        {
            TablaPrincipal[pos]=dato;
            ocupadosPrincipal++;
        }
        void InsertarDatosSecundaria(int pos,Datos dato)
        {
            if(TablaSecundaria[pos].Vacio())
            {
                TablaSecundaria[pos] = dato;
            }
            else if(!TablaSecundaria[pos].Vacio())
            {
                while(TablaSecundaria[pos].Vacio()!=true)
                {
                    pos++;
                    if(pos==dim-1)
                    {
                        pos=0;
                    }
                }
                TablaSecundaria[pos] = dato;
            }
            ocupadosSecundarios++;
        }
        void IngresarDato(Datos dato)
        {
            std::string articulo=dato.getArticulo();
            int clave=HashP(articulo);
            if(TablaPrincipal[clave].Vacio())//Esta vacio y puedo ingresar
            {
                InsertarDatoPrincipal(clave,dato);
            }
            else if(!TablaPrincipal[clave].Vacio())//Esta lleno y devo mandar a la secundaria
            {         
                InsertarDatosSecundaria(clave,dato);       
            }
        }
        void VerOcupaciones()
        {
            cout<<"Principal:"<<ocupadosPrincipal<<"\n";
            cout<<"Secundario:"<<ocupadosSecundarios<<"\n";
        }
        void LlenadoDatos(std::string NombreArchivo)
        {
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
                IngresarDato(aux);
            }
            cout<<"Se termino la creacion\n\n\n\n\n\n";
            VerOcupaciones();
        }
        void BusquedaForsada1(std::string buscado)
        {
            int i=0,r=-1;
            for(i;i<dim;i++)
            {
                if(buscado==TablaPrincipal[i].getArticulo())
                {
                    r=i;
                    break;
                }
            }
            cout<<r<<" posicion\n";
        }
        void BusquedaForsada2(std::string buscado)
        {
            int i=0,r=-1;
            for(i;i<dim;i++)
            {
                if(buscado==TablaSecundaria[i].getArticulo())
                {
                    r=i;
                    break;
                }
            }
            cout<<r<<" posicion\n";
        }
        Datos Busqueda(std::string Buscado)
        {
            int pasos=0;
            int pos=HashP(Buscado);
            int ipos=pos;
            Datos R;
            if(TablaPrincipal[pos].getArticulo()==Buscado)
            {
                //Lo encontre a la primera
                R=TablaPrincipal[pos];
                pasos++;
            }
            else
            {
                if(TablaSecundaria[pos].getArticulo()==Buscado)
                {
                    R=TablaSecundaria[pos];
                    pasos++;
                }
                else
                {
                    pasos++;
                    while(TablaSecundaria[pos].getArticulo()!=Buscado)
                    {
                        if(TablaSecundaria[pos].getArticulo()=="NULL")
                        {
                            break;
                        }
                        pasos++;
                        if(TablaSecundaria[pos].getArticulo()==Buscado)
                        {
                            R=TablaSecundaria[pos];
                        }
                        pos++;
                        if(pos==dim-1)
                        {
                            pos=0;
                        }
                        if(pos==ipos)
                        {
                            break;
                        }
                    }
                }
            }
            cout<<"Pasos:"<<pasos<<"\n";
            return R;
        }
        int stock(std::string nombre_articulo)
        {
            int s=-1;
            Datos buscado=Busqueda(nombre_articulo);
            if(buscado.getArticulo()!="NULL")
            {
                s=buscado.getTotal();
            }
            if(s==-1)
            {
            cout<<"El articulo"<<nombre_articulo<<" no existe\n";
            }
            else
            {
                cout<<"El articulo "<<nombre_articulo<<" tiene "<<s<<" stock en total\n";
            }
            return s;
        }
        int stock(std::string nombre_articulo,int deposito)
        {
            int s=-1;
            Datos buscado=Busqueda(nombre_articulo);
            if(buscado.getArticulo()!="NULL")
            {
                s=buscado.getD(deposito);
            }
            if(s==-1)
            {
            cout<<"El articulo"<<nombre_articulo<<" no existe\n";
            }
            else
            {
                cout<<"El articulo "<<nombre_articulo<<" tiene "<<s<<" stock en el deposito "<<deposito<<"\n";
            }
            return s;
        }
};
#endif
