#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include "ListaDatos/ListaHash.h"
#include"ListaDatos/DatoClave.h"
#include "Hash/ClaseDATO.h"
#include "Hash/TablaHashDatos.h"
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
int main() {
    std::string NombreArchivo = "Inventariado Fisico.csv";
    ListaHash lh(NombreArchivo);
    int l=ContarLineas(NombreArchivo);   //Se puedo modificar la longitud de ambas tablas
    //TablaHashDatos thd(l);//Creo la clase
    //thd.LlenadoDatos(NombreArchivo);//Lleno las dos tablas con los datos
    clock_t begin;
    std::cout << "Comenzando a medir Tiempo\n" << std::endl;
    begin = clock();

    //int st=thd.stock("PILETA C. CERART ARGENTA BCA");//Uso de la funcion stock
    //int sat=thd.stock("ANAFE INDUCCION SMART COOK I4",4);//Uso de la funcion stock con depositos
    //lh.Ver();
    //DatoClave x=lh.Busquedabinaria("VASSER CYRANO TOALLERO PERCHA 13/1829");
    //x.Ver();
    int xd=lh.stock("GRIFERIA VASSER ZAFIRO MONO NEGRO 12/2302NG");
    clock_t end = clock();
    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Tardó " << elapsed_secs << " segundos." << std::endl;
    return 0;
}