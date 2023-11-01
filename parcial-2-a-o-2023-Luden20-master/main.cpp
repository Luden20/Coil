#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include "ListaDatos/ListaDatos.h"
#include "ListaDatos/TablaHashDatos.h"
//#include "HashMap/HashEntry.h"
#include "HashMap/HashMap.h"
#include "Lista/Lista.h"
#include "Datos/ClaseDATO.h"
#include <string>
#include <functional>
#include <vector>

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
            clave = clave % 232;
            cout<<clave<<"\n";
            return clave;
        }
int main() {
    std::string NombreArchivo = "Inventariado Fisico.csv";
    int l=ContarLineas(NombreArchivo);
    TablaHashDatos thd(l);
    thd.LlenadoDatos(NombreArchivo);
    //ListaDatos ListaD(NombreArchivo);
    clock_t begin;
    std::cout << "Comenzando a medir Tiempo\n" << std::endl;
    begin = clock();
    //Lista <std::string> xd=ListaD.max_stock(10);//0.001
    //Lista <std::string>xadl=ListaD.min_stock(90);//0.001
   // Lista <std::string>xad=ListaD.min_stock(2,1);//0.001
    //xd.print();
    //int L=ListaD.total_art();
    //int xdasda=ListaD.total_art_dif();
   // xd.print();
   /*
    HashMap<int, Datos>tahs=ConstruirTabla(NombreArchivo);
    Datos aux=tahs.get(91);
    aux.ver();
    cout<<"Ver";
    */
    //Datos prueba=thd.Busqueda("PILETA DE VIDRIO CUADRADA NARANJA");
    //int posi=HashP("PILETA C. CERART MICHEL  BCA EMBUTIR");
    Datos prueba=thd.Busqueda("PILETA FERRUM ARIANNA BLANCA");
    //ESCURREPLATOS ALACENA 860
    //thd.Ver();
    clock_t end = clock();
    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Tardó " << elapsed_secs << " segundos." << std::endl;
    return 0;
}