#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include "HashMap/HashMap.h"
#include "Datos/ClaseDATO.h"
//Esta funcion sirve para contar la cantidad de lineas(datos) del archivo
int contarLineas(const std::string& Archivo) {
    std::string linea;
    std::ifstream archivo(Archivo);
    int i = 0;
    while (std::getline(archivo, linea))
        i++;
    archivo.close();
    return i;
}
int main() {
    clock_t begin;
    std::cout << "Comenzando a medir Tiempo\n" << std::endl;
    begin = clock();
    //Variables
    std::string linea;
    char l = ',';
    int i = 0;
    std::string NombreArchivo = "Inventariado Fisico .csv";
    int Lineas = contarLineas(NombreArchivo);
    // Llenado de la Tabla
    ifstream archivo(NombreArchivo);
    HashMap<int, Datos> Hash(Lineas); 
    while (getline(archivo, linea)) {
        std::stringstream stream(linea);
        std::string Grupo, CodigoBarras, Articulo, d1, d2, d3, d4, d5;
        int D1=0, D2=0, D3=0, D4=0, D5=0;
        std::getline(stream, Grupo, l);
        std::getline(stream, CodigoBarras, l);
        std::getline(stream, Articulo, l);
        std::getline(stream, d1, l);
        std::getline(stream, d2, l);
        std::getline(stream, d3, l);
        std::getline(stream, d4, l);
        std::getline(stream, d5, l);
        if (!d1="") {
            D1 = std::stoi(d1);
        }
        if (!d2="") {
            D2 = std::stoi(d2);
        }
        if (!d3="") {
            D3 = std::stoi(d3);
        }
        if (!d4="") {
            D4 = std::stoi(d4);
        }
        if (!d5="") {
            D5 = std::stoi(d5);
        }          
        Datos aux(Grupo, CodigoBarras, Articulo, D1, D2, D3, D4, D5);
        Hash.put(i, aux);
        i++;
    }
    Datos xd=Hash.get(32);
    xd.ver();
    clock_t end = clock();
    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Tardó " << elapsed_secs << " segundos." << std::endl;
    return 0;
}
