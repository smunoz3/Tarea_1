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

//ESTA FUNCION LA VAN A CREAR LOS AYUDANTES
Persona* arregloPersonas(int& tamanio_array){
    int m;
    cin >> tamanio_array;
    Persona* personas = new Persona[tamanio_array];
    for (int i=0; i<tamanio_array; i++){
        cin >> personas[i].nombre;
        cin >> personas[i].fecha;
        personas[i].tamanio_tarjeta = personas[i].nombre.length();
        personas[i].tarjeta = comprarTarjeta(personas[i].nombre,2,m); //ACA FALTA CAMBIAR EL DIA IMPORTANTE
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
    int fecha_temp[7];
    int contador;
    contador=0;
    for (int i=0; i<8; i++){
        if ((int)p1->fecha[i]==0){
            fecha_temp[contador]=(int)p1->fecha[i];
            contador ++;
        } else if((int)p1->fecha[i]==1){
            fecha_temp[contador]=(int)p1->fecha[i];
            contador ++;
        } else if((int)p1->fecha[i]==2){
            fecha_temp[contador]=(int)p1->fecha[i];
            contador ++;
        } else if((int)p1->fecha[i]==3){
            fecha_temp[contador]=(int)p1->fecha[i];
            contador ++;
        } else if((int)p1->fecha[i]==4){
            fecha_temp[contador]=(int)p1->fecha[i];
            contador ++;
        } else if((int)p1->fecha[i]==5){
            fecha_temp[contador]=(int)p1->fecha[i];
            contador ++;
        } else if((int)p1->fecha[i]==6){
            fecha_temp[contador]=(int)p1->fecha[i];
            contador ++;
        } else if((int)p1->fecha[i]==7){
            fecha_temp[contador]=(int)p1->fecha[i];
            contador ++;
        } else if((int)p1->fecha[i]==8){
            fecha_temp[contador]=(int)p1->fecha[i];
            contador ++;
        } else if((int)p1->fecha[i]==9){
            fecha_temp[contador]=(int)p1->fecha[i];
            contador ++;
        }
    }
    for (int i=0; i<(p1->tamanio_tarjeta-1); i++){
        puntaje += (p1->tarjeta[i])*(fecha_temp[i%10]);//Hay problemas, ya que la fecha se lee como string y se calcula de acuerdo a ASCII
    }
    return puntaje;
}
//NO ME SIRVE ESTA WEA ME QUIERO MATAR

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
    int tamanio_array;
    Persona* personas = arregloPersonas(tamanio_array);
    for (int i = 0; i<tamanio_array; i++){
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
   int tamanio_array;
    Persona* personas = arregloPersonas(tamanio_array);
    for (int i = 0; i<tamanio_array; i++){
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
    for (int i = 0; i<tamanio_array; i++){
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

    int tamanio_array;
    Persona* personas = arregloPersonas(tamanio_array); //Crear los structs
    for (int i = 0; i<tamanio_array; i++){
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

    Persona* p1;
    p1 = &personas[1];
    int puntos;
    puntos = puntaje(p1);
    cout << "\n" << puntos;
    return 0;
}
//QUE NO SE TE OLVIDE HACER LOS DELETE EN MAIN
//EJECUTAR EL PROGRAMA CON ./output2 < input.txt
//ELIMINAR LAS ENIE