#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include "ListaDatos/ListaDatos.h"
//Esta funcion sirve para contar la cantidad de lineas(datos) del archivo
/*
Lista<Datos>CreacionLista(const std::string& NombreArchivo)
{
    setlocale(LC_ALL, "spanish");
    std::string linea,aux;
    char l = ',';
    ifstream archivo(NombreArchivo);
    Lista<Datos> Lista; 
    std::getline(archivo,linea);
    while (getline(archivo, linea)) {
        std::stringstream stream(linea);
        std::string Grupo, CodigoBarras, Articulo, d1, d2, d3, d4, d5;
        int D1=0, D2=0, D3=0, D4=0, D5=0;   
            std::getline(stream, Grupo, l);
            if(Grupo!="")
                aux=Grupo;
            Grupo=aux;
            std::getline(stream, CodigoBarras, l);
            std::getline(stream, Articulo, l);
            std::getline(stream, d1, l);
            std::getline(stream, d2, l);
            std::getline(stream, d3, l);
            std::getline(stream, d4, l);
            std::getline(stream, d5, l);
            if (d1!="") {
                D1 = std::stoi(d1);
            }
            if (d2!="") {
                D2 = std::stoi(d2);
            }
            if (d3!="") {
                D3 = std::stoi(d3);
            }
            if (d4!="") {
                D4 = std::stoi(d4);
            }
            if (d5!="") {
                D5 = std::stoi(d5);
            }          
            Datos aux(Grupo, CodigoBarras, Articulo, D1, D2, D3, D4, D5);
            Lista.insertarUltimo(aux);
    }
    return Lista;
}
Lista<std::string>min_stock(int n,Lista<Datos>lista)
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

Lista<std::string>max_stock(int n,Lista<Datos>lista)
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
int stock(std::string articulo,Lista<Datos>lista)
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
            break;
        }     
    }
    return st;
}
*/


int main() {
    clock_t begin;
    std::cout << "Comenzando a medir Tiempo\n" << std::endl;
    begin = clock();
    int i;
    std::string NombreArchivo = "Inventariado Fisico.csv";
    std::string NombreBusquedaStock = "ANGULOS FIXSYSTEM";
    //Lista<Datos>DatosGuardados=CreacionLista(NombreArchivo);
    //Datos p=DatosGuardados.getDato(21);
    //p.ver();
    //i=stock(NombreBusquedaStock,DatosGuardados);
    ListaDatos DatosGuardados(NombreArchivo);
    DatosGuardados.stock(NombreBusquedaStock);
    clock_t end = clock();
    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Tardó " << elapsed_secs << " segundos." << std::endl;
    return 0;
}
