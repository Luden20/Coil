#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
//Clases guardadas en archivos aparte en la carpeta
#include "Hash/ListaHash.h"
#include"Hash/DatoClave.h"
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
    //Esto sirve para crear la alternativa 1
    int l=ContarLineas(NombreArchivo);
    TablaHashDatos thd(l);//Creo la clase
    thd.LlenadoDatos(NombreArchivo);//Lleno las dos tablas con los datos
    //Esto sirve para crear la alternativa 2
    ListaHash lh(NombreArchivo);

    clock_t begin;
    std::cout << "Comenzando a medir Tiempo\n" << std::endl;
    begin = clock();
    //Esto es para el stock con la alternativa 1
    int st=thd.stock("PILETA C. CERART ARGENTA BCA");//Uso de la funcion stock
    int sat=thd.stock("ANAFE INDUCCION SMART COOK I4",9);//Uso de la funcion stock con depositos
    //Esto es para el stock con la alternativa 2
    int xd=lh.stock("GRIFERIA VASSER ZAFIRO MONO NEGRO 12/2302NG");
    int xd2=lh.stock("GRIFERIA VASSER ZAFIRO MONO NEGRO 12/2302NG",9);
    clock_t end = clock();
    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Tardó " << elapsed_secs << " segundos." << std::endl;
    return 0;
}