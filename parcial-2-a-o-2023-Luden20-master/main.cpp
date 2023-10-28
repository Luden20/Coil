#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include "ListaDatos/ListaDatos.h"
#include "ListaDatos/TablaHashDatos.h"
int main() {
    clock_t begin;
    std::cout << "Comenzando a medir Tiempo\n" << std::endl;
    begin = clock();
    std::string NombreArchivo = "Inventariado Fisico.csv";
    //std::string NombreBusquedaStock = "ANGULOS FIXSYSTEM";
    ListaDatos DatosGuardados(NombreArchivo);
    HashMapDatos HashDatos(NombreArchivo);
    //Lista<std::string> Nombres=DatosGuardados.min_stock(90);
    //Nombres.print();    
    clock_t end = clock();
    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Tardó " << elapsed_secs << " segundos." << std::endl;
    return 0;
}
