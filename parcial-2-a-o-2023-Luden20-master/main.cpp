#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include "ListaDatos/ListaDatos.h"
#include "ListaDatos/TablaHashDatos.h"
#include "HashMap/HashEntry.h"
#include "HashMap/HashMap.h"
#include "Lista/Lista.h"
#include "Datos/ClaseDATO.h"
#include <string>
int ContarLineas(const std::string &nombrearchivo) {
        std::string linea;
        int i = 0;
        std::ifstream archivo(nombrearchivo);
        while (std::getline(archivo, linea)) {
            i++;
        }
        archivo.close();
        return i;
}
HashMap<std::string,Datos> CrearTabla(std::string NombreArchivo)
{
std::string linea, aux;
        char l = ',';
        int i=0;
        ifstream archivo(NombreArchivo);
        int dim = ContarLineas(NombreArchivo);
        HashMap<string, Datos>tablaHash(dim);
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
            tablaHash.put(Articulo, aux);
            i++;
        }
         cout << "Se termino la creacion\n";
         return tablaHash;
    }
    int stock(std::string nombre_articulo,HashMap<std::string,Datos>hash)
    {
        Datos aux=hash.get(nombre_articulo);
        int stock = aux.getTotal();
        cout<<"El total de "<<aux.getArticulo()<<" es "<<stock<<"\n";
        return stock;
    }

int main() {
    clock_t begin;
    std::cout << "Comenzando a medir Tiempo\n" << std::endl;
    begin = clock();
    std::string NombreArchivo = "Inventariado Fisico.csv";

/*
    // Crear una instancia de HashMap con claves de tipo int
    HashMap<int,std::string> myHashMap(100);

    // Agregar pares clave-valor a la tabla hash
    myHashMap.put(42, "Valor1");
    myHashMap.put(10, "Valor2");
    myHashMap.put(5, "Valor3");

    // Obtener valores a partir de las claves
    std::cout << "Valor asociado a la clave 42: " << myHashMap.get(42) << std::endl;
    std::cout << "Valor asociado a la clave 10: " << myHashMap.get(10) << std::endl;
    std::cout << "Valor asociado a la clave 5: " << myHashMap.get(5) << std::endl;

    //cout<<valor<<"\n";
    //HashMap <std::string , Datos > hashTabla = CrearTabla(NombreArchivo);
    //int st=stock("SOPAPA CESTILLO CUADRADA",hashTabla);
    */
    clock_t end = clock();
    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Tardó " << elapsed_secs << " segundos." << std::endl;
    return 0;
}