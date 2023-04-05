#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int const SERV_DESAYUNO = 0;
int const SERV_ALMUERZO = 1;
int const SERV_ONCE = 2;
int const SERV_CENA = 3;

struct SaldoColaborado{  // estructura binario
    char rut [11];
    int saldo_desayuno;
    int saldo_almuerzo;
    int saldo_once;
    int saldo_cena; 
};

bool puedeConsumir(char* rut, int servicio, string consumos_dia){
    bool n;
    n = true;
    string servicio_salida ="h";
    ofstream file;
    file.open(consumos_dia+".txt",ios::app);
    if (!file.is_open()){
        cout<<"Error \n";exit(1);
        }
    if (SERV_DESAYUNO  ==  servicio){
        servicio_salida = "DESAYUNO";
    }
    else if   (SERV_ALMUERZO  ==  servicio){
        servicio_salida = "ALMUERZO";
    }
    else if  (SERV_ONCE  ==  servicio){
        servicio_salida = "ONCE";
    }
    else if (SERV_CENA  ==  servicio){
        servicio_salida = "CENA";
    }
    else {
        servicio_salida = "Error PAPU :V\n";
    }
    file<<rut<<" "<<servicio_salida <<"\n";


    file.close();



    return n;
};

/*
fstream fp;
fp.open("saldos.bin",ios::binary|ios:out);
fp.write("21270184-K", 1, 1 ,0, 0);
*/

int main(){
        bool test = puedeConsumir("21270184-K",0,"Consumos");
        bool test2 = puedeConsumir("21298184-1",2,"Consumos");
        bool test3= puedeConsumir("21298184-1",7,"Consumos");
        cout<<test<<test2<<test3<<endl;
    return 0;
}
