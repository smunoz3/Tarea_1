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

void intercambiarTarjeta(Persona* p1, Persona* p2){
    //Tengo un problema el cual hace que el arreglo de enteros "tarjeta", sea el largo del nombre de la persona,
    //Pero esta se mantiene al intercambiar tarjetas, entonces si tienen diferentes tamaños
    //Una queda mas larga y otra mas corta
    int* holder;
    holder = p1->tarjeta;
    p1->tarjeta = p2->tarjeta;
    p2->tarjeta = holder;
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
   /*
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
    */
    //delete personas; //ACA ME TIRA EL ERROR Violación de segmento (`core' generado)
    //No tengo idea porque tira error cuando esta, pero sirve cuando no esta
    //********************************
    

   //PARA PROBAR LA FUNCION intercambiarTarjeta
   //********************
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
    }
    cout << "\n";
    Persona* p1;
    Persona* p2;
    p1 = &personas[0];
    p2 = &personas[2];
    intercambiarTarjeta(p1,p2);
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
    //*************************
    return 0;
}
//QUE NO SE TE OLVIDE HACER LOS DELETE EN MAIN
//EJECUTAR EL PROGRAMA CON ./output2 < input.txt