#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "../Lista/Lista.h"
#include "../Datos/ClaseDATO.h"
#include <string>
using namespace std;
/*
Notas
Esta clase utiliza la clase lista que ya estaba previamente hecha y utiliza la clase Datos que esta en otro archivo
Aqui se incluiran las funciones y metodos
*/ 

class ListaDatos {
private:
    Lista<Datos> lista;
public:
    ListaDatos(const std::string& NombreArchivo) {
        setlocale(LC_ALL, "spanish");
        std::string linea, aux;
        char l = ',';
        ifstream archivo(NombreArchivo);
        
        if (!archivo.is_open()) {
            cerr << "Error: Could not open file " << NombreArchivo << endl;
            return;
        }
        
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
            lista.insertarUltimo(aux);
        }
        cout<<"Se termino la creacion\n";
    }
    //Metodos que se pidieron
        Lista<std::string>min_stock(int n)
    {
        Lista<std::string>resultado;
        int i,tpa;
        for(i=0;i<lista.getTamanio();i++)
        {
            Datos aux=lista.getDato(i);
            tpa=aux.getD1()+aux.getD2()+aux.getD3()+aux.getD4()+aux.getD5();
            if(tpa<=n)
            {
                resultado.insertarUltimo(aux.getArticulo());
            }
        }
        cout<<"Fin min_stock\n";
        return resultado;
    }
    Lista<std::string>min_stock(int n,int Deposito)
    {
        Lista<std::string> resultado;
        int i,tpa;
        for(i=0;i<lista.getTamanio();i++)
        {
            Datos aux=lista.getDato(i);
            switch (Deposito)
                    {
                        case 1:
                            tpa=aux.getD1();
                            break;
                        case 2:
                            tpa=aux.getD2();
                            break;
                        case 3:
                            tpa=aux.getD3();
                            break;
                        case 4:
                            tpa=aux.getD4();
                            break;
                        case 5:
                            tpa=aux.getD5();
                            break;
                    }
            if(tpa<=n)
            {
                resultado.insertarUltimo(aux.getArticulo());
            }
        }
        cout<<"Fin min_stock\n";
        return resultado;
    }


    Lista<std::string>max_stock(int n)
    {
        Lista<std::string>resultado;
        int i,tpa;
        for(i=0;i<lista.getTamanio();i++)
        {
            Datos aux=lista.getDato(i);
            tpa=aux.getD1()+aux.getD2()+aux.getD3()+aux.getD4()+aux.getD5();
            if(tpa>=n)
            {
                resultado.insertarUltimo(aux.getArticulo());
            }
        }
        return resultado;
    }
    int stock(std::string articulo)
    {
        int i;
        int st=-1;
        for(i=1;i<lista.getTamanio();i++)
        {
            Datos aux=lista.getDato(i);
            std::string str=aux.getArticulo();
            if(articulo==str)
            {
                cout<<"Encontrado\n";
                st=aux.getD1()+aux.getD2()+aux.getD3()+aux.getD4()+aux.getD5();
                cout<<st<<" existencias de "<<str<<"\n";
                break;
            }     
        }
        return st;
    }
    int stock(std::string articulo,int Deposito)
    {
        int i;
        int st=-1;
        if(Deposito>0&&Deposito<=5)
        {
            for(i=1;i<lista.getTamanio();i++)
            {
                Datos aux=lista.getDato(i);
                std::string str=aux.getArticulo();
                if(articulo==str)
                {
                    cout<<"Encontrado\n";
                    switch (Deposito)
                    {
                        case 1:
                            st=aux.getD1();
                            break;
                        case 2:
                            st=aux.getD2();
                            break;
                        case 3:
                            st=aux.getD3();
                            break;
                        case 4:
                            st=aux.getD4();
                            break;
                        case 5:
                            st=aux.getD5();
                            break;
                    }
                    cout<<st<<" existencias de "<<str<<"\n";
                    break;
                }     
            }
        }
        return st;
    }

    };

#endif
