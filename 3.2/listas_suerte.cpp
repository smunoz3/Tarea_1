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

//Hacer un array de structs de las personas

Persona* arregloPersonas(int& tamaño_array){
    int m;
    cin >> tamaño_array;
    Persona* personas = new Persona[tamaño_array];
    for (int i=0; i<tamaño_array; i++){
        cin >> personas[i].nombre;
        cin >> personas[i].fecha;
        personas[i].tamanio_tarjeta = personas[i].nombre.length();
        personas[i].tarjeta = comprarTarjeta(personas[i].nombre,2,m);
        cin >> personas[i].quiere_intercambiar;
    }
    return personas; 
}

int main(){
    //PARA PROBAR LA FUNCION comprarTarjeta y visualizar lo que contiene cada array de enteros
    //*****************
    /*
    int m;
    int* tarjeta = comprarTarjeta("Maria",2,m);
    for ( int i=0 ; i < m ; i++){
        cout << tarjeta[i] << endl;
    }
    delete tarjeta;
    */
    //**********************
    
   //PARA PROBAR LA FUNCION arregloPersonas y visualizar lo que contiene cada struct

   //***********************
    int tamaño_array;
    Persona* personas = arregloPersonas(tamaño_array);
    for (int i = 0; i<tamaño_array; i++){
        cout << personas[i].nombre << " " << personas[i].fecha << " " << personas[i].tamanio_tarjeta << " ";
        for ( int j=0; j < (int)personas[i].nombre.length(); j++){
            if(j==0){
                cout << "[";
            }
            cout << personas[i].tarjeta[j] << ",";
            if(j==((int)personas[i].nombre.length())-1){
                cout << "]";
            }
        }
        cout << " " << personas[i].quiere_intercambiar << endl;
        delete personas[i].tarjeta;
    }
    //delete personas; //ACA ME TIRA EL ERROR Violación de segmento (`core' generado)
    //No tengo idea porque tira error cuando esta, pero sirve cuando no esta
    //********************************
    
    return 0;
}
//NECESITO HACER LOS DELETE DE COMPRARTARJETA
//EJECUTAR EL PROGRAMA CON ./output2 < input.txt