#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
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

void intercambiarTarjeta(Persona* p1, Persona* p2) {     
    int* temp = p1->tarjeta; 
    int* temp_2 = p2->tarjeta;
    //cout<<"P2 "<<p2->tamanio_tarjeta<<" P1 "<<p1->tamanio_tarjeta<<endl;
    int temp_tam = p1->tamanio_tarjeta; 
    p1->tamanio_tarjeta = p2->tamanio_tarjeta; 
    p2->tamanio_tarjeta = temp_tam;
    //cout<<"P2 "<<p2->tamanio_tarjeta<<" P1 "<<p1->tamanio_tarjeta<<endl;
    p1->tarjeta = temp_2;
    p2->tarjeta = temp;
}
//NO PUEDO HACER ESTA FUNCION CULIA POR EL PICO ME RINDO
// PUTOS NIGGERS
// ODIO ISRAEL

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
    Persona* personas_intercambio = new Persona[p];
    Persona* personas_no_intercambio = new Persona[p];
    int c =0;
    int no_cambio = 0;
    for (int i= 0; i<p; i++){
        if (personas[i].quiere_intercambiar == 1){
            personas_intercambio[c].tarjeta = personas[i].tarjeta;
            personas_intercambio[c].quiere_intercambiar = personas[i].quiere_intercambiar;
            personas_intercambio[c].tamanio_tarjeta = personas[i].tamanio_tarjeta;
            personas_intercambio[c].nombre = personas[i].nombre;
            for (int j=0;j<11;j++){
            personas_intercambio[c].fecha[j] = *personas[j].fecha;
            }
            c++;
        } else{
            personas_no_intercambio[no_cambio].tarjeta = personas[i].tarjeta;
            personas_no_intercambio[no_cambio].quiere_intercambiar = personas[i].quiere_intercambiar;
            personas_no_intercambio[no_cambio].tamanio_tarjeta = personas[i].tamanio_tarjeta;
             personas_no_intercambio[no_cambio].nombre = personas[i].nombre;
             //personas_no_intercambio[no_cambio].fecha = personas[i].fecha;
            no_cambio++;
        }
    }
    //intercambiar tarjetas

    for (int i=1;i<=c;i++){
 
        int min = (personas_intercambio[i-1].tamanio_tarjeta <personas_intercambio[i].tamanio_tarjeta) ? personas_intercambio[i-1].tamanio_tarjeta : personas_intercambio[i].tamanio_tarjeta;
        for (int j=0;j<min;j++){
            if (personas_intercambio[i-1].tarjeta[j]==personas_intercambio[i].tarjeta[j]){
                intercambiarTarjeta(&personas_intercambio[i-1] , &personas_intercambio[i] );
                personas_intercambio[i-1].quiere_intercambiar = false;
            }
        }
    }
    int neicho =0;
    int miguel = 0;
    Persona* personas_total = new Persona[p];
    for (int i =0;i<p;i++){
        if (i<c){    
            personas_total[i] = personas_intercambio[neicho];
            neicho ++;
        }
        else{
            personas_total[i] = personas_no_intercambio[miguel];
            miguel++;   
        }
    }

    //delete[] personas_intercambio;
    //delete[] personas_no_intercambio;
    //calculo ganador
    Persona* ganador;
    int puntos_max =0;
    for (int i=0;i<p;i++){
        int a = puntaje(&personas_total[i]);
        if(a>puntos_max){
            puntos_max = a;
            ganador = &personas_total[i];
        }

    } 
    //delete[] personas_total;
    return ganador;
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
    Persona* personas = arregloPersonas(p);
    for (int i = 0; i<p; i++){
        cout << personas[i].nombre << " " << personas[i].fecha << " " << personas[i].tamanio_tarjeta << " ";
        for ( int j=0; j < personas[i].tamanio_tarjeta; j++){
            if(j==0){
                cout << "[";
            }
            cout << personas[i].tarjeta[j] << ",";
            if(j==(personas[i].tamanio_tarjeta)-1){
                cout << "]";
            }
        }
        cout << " " << personas[i].quiere_intercambiar << endl;
       
    }
    cout<<"\n";
    variosDias(personas,2);

    delete[] personas;
    for (int i=0;i <p;i++){
        delete personas[i].tarjeta;
    }
    return 0;
}
