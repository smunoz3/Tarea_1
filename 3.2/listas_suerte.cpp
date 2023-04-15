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

int p;

int* comprarTarjeta (string nombre, int dia, int& m){

    int* tarjeta= new int[m];

    for (int i=0; i<m; i++){
        tarjeta[i]= nombre[i]%dia;
    }
    return tarjeta;

}

//Hacer un array de structs de las personas

//ESTA FUNCION LA VAN A CREAR LOS AYUDANTES
Persona* arregloPersonas(int& p){
    int m;
    p;
    Persona* personas = new Persona[p];
    for (int i=0; i<p; i++){
        cin >> personas[i].nombre;
        cin >> personas[i].fecha;
        personas[i].tamanio_tarjeta = personas[i].nombre.length();
        //personas[i].tarjeta = comprarTarjeta(personas[i].nombre,2,m); //ACA SE PUEDE CAMBIAR EL DIA IMPORTANTE
        cin >> personas[i].quiere_intercambiar;
    }
    return personas; 
}


void intercambiarTarjeta(Persona* p1, Persona* p2){
    //Tengo un problema el cual hace que el arreglo de enteros "tarjeta", sea el largo del nombre de la persona,
    //Pero esta se mantiene al intercambiar tarjetas, entonces si tienen diferentes tamaños
    //Una queda mas larga y otra mas corta
    int tamanio_temp = p1->tamanio_tarjeta;
    int* temp = new int[tamanio_temp];  //Cree un arreglo temporal
    for (int i=0; i<tamanio_temp; i++){
        temp[i] = p1->tarjeta[i];  //Aca se pasa el arreglo de p1 al temporal
    }
    delete [] p1->tarjeta;
    p1->tarjeta = new int[p2->tamanio_tarjeta];  //Se guarda el arreglo de p2 en p1
    for (int i=0; i<p2->tamanio_tarjeta; i++){
        temp[i] = p2->tarjeta[i];  //Aca se pasa el arreglo de p2 a p1
    }
    delete [] p2->tarjeta;
    p2->tarjeta = new int[tamanio_temp];  //Se guarda el arreglo de p2 en p1
    for (int i=0; i<tamanio_temp; i++){
        p2->tarjeta[i] = temp[i];  //Aca se pasa el arreglo de p2 a p1
    }
    delete [] temp;
    for ( int i=0; i < p1->tamanio_tarjeta && i < p2->tamanio_tarjeta; i++){
        int valor_temp = p1->tarjeta[i];
        p1->tarjeta[i] = p2->tarjeta[i];
        p2->tarjeta[i] = valor_temp;
    }
} //NO PUEDO HACER ESTA FUNCION CULIA POR EL PICO ME RINDO

int puntaje(Persona* p1){
    int puntaje;
    puntaje = 0;
    for (int i=0; i<p1->tamanio_tarjeta; i++){
        puntaje += (p1->tarjeta[i])*(p1->fecha[i%10]);
    }
    return puntaje;
}
//NO ME SIRVE ESTA WEA ME QUIERO MATAR

Persona* unDia(Persona* personas, int dia){
    int n_intercambios = 0;
    for(int i=0; i<p; i++){
        int largo_nombre;
        largo_nombre = personas[i].nombre.length();
        personas[i].tarjeta = comprarTarjeta(personas[i].nombre, dia, largo_nombre); //Aca se le da una tarjeta a cada persona
        if (personas[i].quiere_intercambiar==1){
            n_intercambios++;
        }
    }//HASTA ACA FUNCIONA
    int contador=0;
    Persona* personaintercambio = new Persona [contador];
    for (int i=0; i<p; i++){
        if (personas[i].quiere_intercambiar==1){
            personaintercambio[contador]=personas[i];//Arreglo de personas que quieren intercambiar
            contador++;
        }
    }
    
    for(int i=1; i<=n_intercambios; i+=2){
        int largo_tarjeta_menor = (personaintercambio[i-1].tamanio_tarjeta<=personaintercambio[i].tamanio_tarjeta) ? personaintercambio[i-1].tamanio_tarjeta : personaintercambio[i].tamanio_tarjeta;
        for(int j=0; j<largo_tarjeta_menor; j++){
            if (personaintercambio[i-1].tarjeta[j] == personaintercambio[i].tarjeta[j]){
                Persona* p1 = &personaintercambio[i-1];
                Persona* p2 = &personaintercambio[i];
                intercambiarTarjeta(p1,p2);// ACA SE CAMBIAN LAS TARJETAS EN EL NUEVO ARREGLO, REVISAR SI CAMBIA AL STRUCT ORIGINAL
                break;
            }
        }
    }
    delete [] personaintercambio;
    
}

void variosDias (Persona* personas, int cant_dias){ //TOO EZ
    Persona* ganador;
    for (int i=1; i<=cant_dias; i++){
        ganador = unDia(personas,i);
        cout << ganador->nombre << " " << ganador->fecha << " " << puntaje(ganador) << endl;
    }
    
}
//PICO
int main(){
    cin >> p;
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
    int p;
    Persona* personas = arregloPersonas(p);
    for (int i = 0; i<p; i++){
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
   /*
   int p;
    Persona* personas = arregloPersonas(p);
    for (int i = 0; i<p; i++){
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
    for (int i = 0; i<p; i++){
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
    //*************************


    //PARA PROBAR LA FUNCION puntaje
    //***************************
    /*
    int p;
    Persona* personas = arregloPersonas(p); //Crear los structs
    for (int i = 0; i<p; i++){
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

    Persona* p1;
    p1 = &personas[1];
    int puntos;
    puntos = puntaje(p1);
    cout << "\n" << puntos;
    for (int i=0; i<p; i++){
        delete personas[i].tarjeta;
    }
    */
   //******************************************


   //PARA PROBAR LA FUNCION unDia
   int p;
    Persona* personas = arregloPersonas(p); //Crear los structs
    for (int i = 0; i<p; i++){
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

    unDia(personas,2);

    for (int i = 0; i<p; i++){
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
    for (int i=0; i<p; i++){
        delete personas[i].tarjeta;
    }
    return 0;
}
//QUE NO SE TE OLVIDE HACER LOS DELETE EN MAIN
//EJECUTAR EL PROGRAMA CON ./output2 < input.txt
//ELIMINAR LAS ENIE