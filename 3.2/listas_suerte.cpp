#include <iostream>
#include <string>

using namespace std;

struct Persona {
    string nombre;
    char fecha[11];
    int tamanio_tarjeta;
    int* tarjeta;
    bool quiere_intercambiar;
};

int* comprarTarjeta (string nombre, int dia, int& m){
    m = nombre.length();

    int* tarjeta= new int[m];

    for (int i=0; i<m; i++){
        tarjeta[i]= nombre[i]%dia;
    }
    return tarjeta;

}

int main(){
    //PARA PROBAR LA FUNCION comprarTarjeta y visualizar lo que contiene cada string de enteros
    //*****************
    int m;
    int* tarjeta = comprarTarjeta("Maria",2,m);
    for ( int i=0 ; i < m ; i++){
        cout << tarjeta[i] << endl;
    }
    delete tarjeta;
    //**********************
    return 0;
}