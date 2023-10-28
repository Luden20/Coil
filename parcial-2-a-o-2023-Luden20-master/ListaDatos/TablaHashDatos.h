#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "../HashMap/HashEntry.h"
#include "../HashMap/HashMap.h"
#include "../Lista/Lista.h"
#include "../Datos/ClaseDATO.h"
#include <string>
using namespace std;

class HashMapDatos {
private:
    HashMap<std::string, Datos> TablaHash;
public:
    HashMapDatos(const std::string NombreArchivo) {
        setlocale(LC_ALL, "spanish");
        std::string linea, aux;
        char l = ',';
        ifstream archivo(NombreArchivo);
        int dim = ContarLineas(NombreArchivo);
        TablaHash=HashMap<std::string, Datos>(dim);
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
            TablaHash.put("clave", aux);
        }
        cout << "Se termino la creacion\n";
    }

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
};

#endif
