#include "Imports.h"
#include "MetodosGenerales.h"


int main() {

    //PRUEBA 1
    vector<string> vecArchivo = Leer("rectangulos.in");
    vector<rectangulo> vecRectangulos;
    int numRectangulos,filas,columnas;
    ProcessDatosGenerales(vecArchivo,numRectangulos,filas,columnas);

    int** matriz = CrearMatrizRectangulos(filas,columnas);
    ProcessRectangulos(vecArchivo,vecRectangulos);

    vector<rectangulo> vectorValidado= Validar(vecRectangulos);
    Imprimir("rectangulos.out",vectorValidado);
    DestruirMatrizRectangulos(matriz,filas);



/*
    //PRUEBA 2
    vector<string> vecArchivo = Leer("rectangulos2Prueba.in");
    vector<rectangulo> vecRectangulos;
    int numRectangulos,filas,columnas;
    ProcessDatosGenerales(vecArchivo,numRectangulos,filas,columnas);

    int** matriz = CrearMatrizRectangulos(filas,columnas);
    ProcessRectangulos(vecArchivo,vecRectangulos);

    vector<rectangulo> vectorValidado= Validar(vecRectangulos);
    Imprimir("rectangulos2Prueba.out",vectorValidado);
    DestruirMatrizRectangulos(matriz,filas);
*/

    return 0;
}