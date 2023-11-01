#ifndef HASH_H
#define HASH_H
#include <vector>
#include "../Datos/ClaseDATO.h"
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
            for (char c : st)
            {
                if (c != '(' && c != ')')
                {
                    clave += static_cast<int>(c);
                }
            }
            clave = clave % 232; 
            return clave;
        }
        void InsertarDatoPrincipal(int pos,Datos dato)
        {
            cout<<"Principal se va a poner "<<pos<<"el dato"<<dato.getArticulo()<<" donde antes estaba "<<TablaPrincipal[pos].getArticulo()<<"\n";
            TablaPrincipal.insert(TablaPrincipal.begin()+pos,dato);
            ocupadosPrincipal++;
        }
        void InsertarDatosSecundaria(int pos,Datos dato)
        {
            if(TablaSecundaria[pos].Vacio())
            {
                cout<<"Secundario se va a poner "<<pos<<"el dato"<<dato.getArticulo()<<" donde antes estaba "<<TablaSecundaria[pos].getArticulo()<<"\n";
                TablaSecundaria.insert(TablaSecundaria.begin()+pos,dato);
            }
            else
            {
                while(TablaSecundaria[pos].Vacio()!=true)
                {
                    pos++;
                    if(pos==dim)
                    {
                        pos=0;
                    }
                }
                cout<<"Secundario se va a poner "<<pos<<"el dato"<<dato.getArticulo()<<" donde antes estaba "<<TablaSecundaria[pos].getArticulo()<<"\n";
                TablaSecundaria.insert(TablaSecundaria.begin()+pos,dato);
            }
            ocupadosSecundarios++;
        }
        void IngresarDato(Datos dato)
        {
            int clave=HashP(dato.getArticulo());
            if(TablaPrincipal[clave].Vacio())//Esta vacio y puedo ingresar
            {
                InsertarDatoPrincipal(clave,dato);
            }
            else//Esta lleno y devo mandar a la secundaria
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
        void Ver()
        {
            int c=0;
            int i=0;
            for(i;i<dim;i++)
            {
                Datos v=TablaPrincipal[i];
                v.ver();
                //if(!TablaPrincipal[i].Vacio())
                //{
                  //  cout<<i<<" Principal "<<TablaPrincipal[i].getArticulo()<<"\n";
                    //c++;
                //}
            }
            i=0;
            for(i;i<dim;i++)
            {
                Datos vs=TablaPrincipal[i];
                //vs.ver();
                //if(!TablaSecundaria[i].Vacio())
                //{
                 //   cout<<i<<" Secundaria "<<TablaSecundaria[i].getArticulo()<<"\n";
                  //  c++;
                //}
            }
            cout<<c<<" datos\n";
        }
        Datos Busqueda(std::string Buscado)
        {
            int pasos=0;
            int pos=HashP(Buscado);
            int ipos=pos;
            Datos R;
            cout<<"Se busco en"<<pos<<" en la tb1 donde esta "<<TablaPrincipal[pos].getArticulo()<<"\n";
            if(TablaPrincipal[pos].getArticulo()==Buscado)
            {
                cout<<"Se encontro en la tabla 1 en "<<pos<<" \n";
                //Lo encontre a la primera
                R=TablaPrincipal[pos];
                pasos++;
            }
            else
            {
                cout<<"Se buscara en la tabla 2\n";
                if(TablaSecundaria[pos].getArticulo()==Buscado)
                {
                    cout<<"Se encontro en la tabla 2 en "<<pos<<" \n";
                    R=TablaSecundaria[pos];
                    pasos++;
                }
                else
                {
                    pasos++;
                    while(TablaSecundaria[pos].getArticulo()!=Buscado)
                    {
                        cout<<"Se busco en"<<pos<<" en la tb2\n";
                        pasos++;
                        if(TablaSecundaria[pos].getArticulo()==Buscado)
                        {
                            cout<<"Se encontro en la tabla 2 en "<<pos<<" \n";
                            R=TablaSecundaria[pos];
                        }
                        pos++;
                        if(pos==dim)
                        {
                            pos=0;
                        }
                        if(pos==ipos)
                        {
                            cout<<"No se encontro \n";
                            break;
                        }
                    }
                }
            }
            cout<<"Pasos:"<<pasos<<"\n";
            return R;
        }
};
#endif
