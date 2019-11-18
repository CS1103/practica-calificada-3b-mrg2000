//
// Created by Maor Roizman Gheiler on 17/11/19.
//

#include "Imports.h"
#include "rectangulo.h"
#include "MetodosGenerales.h"


vector<string> Leer(string nombreArchivo){

    vector<string> vec;
    ifstream archivo;
    archivo.open(nombreArchivo,ios::in);
    if(archivo.is_open()){
        string fila, str;
        while(getline(archivo,fila)){
            stringstream ss(fila);
            getline(ss,str);
            vec.push_back(str);
        }
    }else{
            cout << "ERROR";
        }
    archivo.close();

    return vec;

}

void Imprimir(string nombreArchivo,vector<rectangulo> vecRectangulos){
    ofstream archivo;
    char accion;
    archivo.open(nombreArchivo);
    for(auto it:vecRectangulos){
        accion = toupper(it.tipoAccion);
        archivo << accion << " ";
        archivo << it.posx << " ";
        archivo << it.posy << " ";
        archivo << it.numFilas << " ";
        archivo << it.numColumnas << " ";
        archivo << endl;
    }
    archivo.close();
}



void ProcessDatosGenerales(vector<string> vecArchivo, int& numRectangulos, int& numFilas, int& numColumnas){
    string linea;
    for(auto it = vecArchivo.begin();it  != vecArchivo.end();++it){
        if(it == vecArchivo.begin()){
            for(int i = 0; i < 3; i++){
                linea = "";
                auto it2 = find(it->begin(), it->end(),' ');
                auto it3 = it->begin();
                if(i == 0) {
                    cambiar(linea,it3,it2);
                    numRectangulos= stoi(linea);
                    it->erase(0,3);
                }
                if(i == 1){
                    cambiar(linea,it3,it2);
                    numFilas = stoi(linea);
                    it->erase(0,3);
                }
                if(i == 2){
                    cambiar(linea,it3,it2);
                    numColumnas = stoi(linea);
                }
            }
        }
    }
}




void ProcessRectangulos(vector<string> vecArchivo, vector<rectangulo>& vecRectangulos){
    char _tipoAccion;
    int rr,c,x,y;
    string _filas, _columnas, _posx, _posy;
    rectangulo rec;
    for(auto it = vecArchivo.begin(); it != vecArchivo.end();it++){
        if(it != vecArchivo.begin()){
            _tipoAccion = '\0';
            _filas = "";
            _columnas = "";
            _posx = "";
            _posy = "";
            auto it1 = it->begin();
            auto it2 = find(it->begin(), it->end(),' '); it2++;
            auto it3 = find(it2, it->end(),' '); it3++;
            auto it4 = find(it3, it->end(),' '); it4++;
            auto it5 = find(it4, it->end(), ' '); it5++;
            while(it1 != it2){
                _tipoAccion += *it1;
                it1++;
            }
            cambiar(_posx,it2,it3);
            x = stoi(_posx);
            cambiar(_posy,it3,it4);
            y = stoi(_posy);
            cambiar(_filas,it4,it5);
            rr = stoi(_filas);
            cambiar(_columnas,it5,it->end());
            c = stoi(_columnas);
            rec.tipoAccion = _tipoAccion;
            rec.numFilas = rr;
            rec.numColumnas = c;
            rec.posx = x;
            rec.posy = y;
            vecRectangulos.push_back(rec);
        }
    }
}


int** CrearMatrizRectangulos(int filas,int columnas){
    int** matriz = new int*[filas];
    for(int i = 0; i < filas; i++)
        matriz[i] = new int[columnas];
    return matriz;
}


void DestruirMatrizRectangulos(int**& matriz,int filas){
    for(int i = 0; i < filas; i++)
        delete[] matriz[i];
    delete[] matriz;
}


vector<rectangulo> Validar(vector<rectangulo>& vecRectangulos){
    vector<rectangulo> vec;
    auto it = vecRectangulos.begin();
    vec.push_back(*it);
    it++;
    bool varBool;
    for(;it != vecRectangulos.end();it++){
        for(auto it2 : vec){
            varBool = false;
            if((it->posx == it2.posx && it->posy == it2.posy) && (it->numFilas > it2.numFilas || it->numColumnas > it2.numColumnas)){
                varBool = true;
                break;
            }
        }
        if(!varBool){
            vec.push_back(*it);
        }
    }
    sort(vec.begin(),vec.end(),Verificar);
    return vec;

}

bool Verificar(const rectangulo& z, const rectangulo& w){
    return z.posx < w.posx;
}
