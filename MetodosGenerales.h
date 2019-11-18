//
// Created by Maor Roizman Gheiler on 17/11/19.
//

#ifndef PC3B_METODOSGENERALES_H
#define PC3B_METODOSGENERALES_H

#include "Imports.h"
#include "rectangulo.h"


template<typename T,typename siguiente>
void cambiar(T& valor, siguiente z, siguiente w){
    while(z != w){
        valor += *z;
        z++;
    }
}

void Imprimir(string nombreArchivo,vector<rectangulo> vecRectangulos);
vector<string> Leer(string nombreArchivo);
void ProcessDatosGenerales(vector<string> vecArchivo, int& numRectangulos, int& numFilas, int& numColumnas);
void ProcessRectangulos(vector<string> vecArchivo, vector<rectangulo>& vecRectangulos);
int** CrearMatrizRectangulos(int filas,int columnas);
void DestruirMatrizRectangulos(int**& matriz,int filas);
vector<rectangulo> Validar(vector<rectangulo>& vecRectangulos);
bool Verificar(const rectangulo& z, const rectangulo& w);



#endif //PC3B_METODOSGENERALES_H
