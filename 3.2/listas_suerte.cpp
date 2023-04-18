#include <iostream>
#include <string>

using namespace std;

int p;

struct Persona {
    string nombre;
    char fecha[11];
    int tamanio_tarjeta;
    int* tarjeta;
    bool quiere_intercambiar;
};

/*****
* int* comprar Tarjeta
******
* La función comprarTarjeta genera una tarjeta de la suerte en la cual influye el nombre y el dia.
******
* Input:
*   string nombre: nombre es un string el cual contiene el nombre de la persona que quiere comprar la tarjeta de la suerte.
*   int dia: dia es un entero el cual contiene el dia en el que se compra la tarjeta de la suerte. 
*   int& m: m es una referencia a un entero, es el tamaño del arreglo que se va a retornar.
******
* Returns:
*   Se retorna un arreglo de enteros el cual tiene el mismo largo que el nombre ingresado, en este arreglo, en la posicion i estará el valor que corresponde a la operación nombre[i]%dia. 
*****/

int* comprarTarjeta (string nombre, int dia, int& m){
    m = nombre.length();  //probar funcion comprar y funcion putaje
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
    Persona* personas = new Persona[p];
    for (int i=0; i<p; i++){
        //m = personas[i].nombre.length(); //
        cin >> personas[i].nombre;
        cin >> personas[i].fecha;
        personas[i].tamanio_tarjeta = personas[i].nombre.length();
        personas[i].tarjeta = comprarTarjeta(personas[i].nombre,2,m); //ACA SE PUEDE CAMBIAR EL DIA IMPORTANTE
        //Descomentar para probar funcion puntaje
        cin >> personas[i].quiere_intercambiar;
    }

    return personas; 
}


/*****
* void intercambiarTarjeta
******
* La función intercambiarTarjeta
******
* Input:
*   Persona* p1: Variable p1 del tipo puntero a el struct Persona, esto me da una persona.
*   Persona* p2: Variable p2 del tipo puntero a el struct Persona, esto me da otra persona.
******
* Returns:
*   No se retorna nada ya que la función es de tipo void.
*****/

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

/*****
* int puntaje
******
* La función puntaje recibe una persona y le da el puntaje a esa persona mediante la fórmula proporcionada en la guía.
******
* Input:
*   Persona* p1: Variable p1 del tipo puntero a el struct Persona.
******
* Returns:
*   Se retorna un valor entero que representa el puntaje de la persona.
*****/

int puntaje(Persona* p1){
    int puntaje;
    puntaje = 0;
        for (int i=0; i<p1->tamanio_tarjeta; i++){
        puntaje += (p1->tarjeta[i])*(p1->fecha[i%10]);
    }
    return puntaje;
}

/*****
* Persona* unDia
******
* La función unDIa 
* Input:
*   Persona* personas: Variable personas del tipo puntero a el struct Persona, el cual tiene personas dentro.
*   int dia: El dia en el que se compra la tarjeta para cada personas.
******
* Returns:
*   Se retorna la persona que obtuvo más puntaje en las tarjetas.
*****/

Persona* unDia(Persona* personas, int dia){  //FALTA TERMINAR
    for(int i=0; i<p; i++){
        int largo_nombre;
        largo_nombre = personas[i].nombre.length();
        personas[i].tarjeta = comprarTarjeta(personas[i].nombre, dia, largo_nombre); //Aca se le da una tarjeta a cada persona
    }//HASTA ACA FUNCIONA
    
    return personas;
}

/*****
* void variosDias
******
* La función variosDias 
* Input:
*   Persona* personas: Variable personas del tipo puntero a el struct Persona, el cual tiene personas dentro.
*   int cant_dias: Variable cant_dias del tipo entero que tiene la cantidad de dias yotales a realizar.
******
* Returns:
*   No se retorna nada ya que la función es de tipo void.
*****/

void variosDias (Persona* personas, int cant_dias){ //TOO EZ
    Persona* ganador;
    for (int i=1; i<=cant_dias; i++){
        ganador = unDia(personas,i);
        cout << ganador->nombre << " " << ganador->fecha << " " << puntaje(ganador) << endl;
    } 
}
//NO ME SIRVE ESTA WEA ME QUIERO MATAR



int main(){
    cin >> p;
    //PARA PROBAR LA FUNCION comprarTarjeta y visualizar lo que contiene cada array de enteros
    //*****************
    /*
    int m;
    int* tarjeta = comprarTarjeta("Pepito",2,m);
    for ( int i=0 ; i < m ; i++){
        cout << tarjeta[i] << endl;
    }
    delete tarjeta;
    */
    //**********************
    
   //PARA PROBAR LA FUNCION arregloPersonas y visualizar lo que contiene cada struct
   //***********************
 /*
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
        delete [] personas[i].tarjeta;
    }
    delete [] personas;
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
    //************************
    
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
    cout << "\n" << puntos << endl;
    for (int i=0; i<p; i++){
        delete personas[i].tarjeta;
    }
    delete [] personas;
    
    //***************************
    
    return 0;
}
//QUE NO SE TE OLVIDE HACER LOS DELETE EN MAIN
//EJECUTAR EL PROGRAMA CON ./output2 < input.txt
//ELIMINAR LAS ENIE
// Valgrind:
// g++ -g listas_suerte.cpp -o output2 -Wall
//valgrind --leakcheck=yes ./output2 < input.txt