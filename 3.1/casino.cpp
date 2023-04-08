#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

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
    bool retorno;
    retorno = false;
    string rut_string = rut;

    fstream file_binario;        //abrir archivo binario
    file_binario.open("saldos.bin",ios::binary| ios::in);
    if (!file_binario.is_open()){
        cout<<"Error \n";exit(1);
        }
    ofstream file;          //abrir archivo txt
    file.open(consumos_dia+".txt",ios::app);
    if (!file.is_open()){
        cout<<"Error \n";exit(1);
        }

    string comidas_array [4];
    comidas_array[0]="DESAYUNO";comidas_array[1]="ALMUERZO";comidas_array[2]="ONCE";comidas_array[3]="CENA";
    
    int saldo_size;
    file_binario.read((char*)&saldo_size,sizeof(int));

    SaldoColaborado saldo_lectura [saldo_size];
    for (int i=0;i<saldo_size;i++){
        file_binario.read((char*)&saldo_lectura[i],sizeof(SaldoColaborado));
        if (strcmp(rut , saldo_lectura[i].rut)== 0){
            if (servicio == SERV_DESAYUNO ){
                if (saldo_lectura[i].saldo_desayuno>0){
                    retorno = true;
                    file <<rut << " " + comidas_array[servicio] + "\n";
                }
                else{
                    cout<<"no desayuno"<<endl;
                }
            }
            else if (servicio == SERV_ALMUERZO ){
                if (saldo_lectura[i].saldo_almuerzo>0){
                    retorno = true;
                    file <<rut << " " + comidas_array[servicio] + "\n";
                }
                else{
                    cout<<"no almuerzo"<<endl;
                }
            }
            else if (servicio == SERV_ONCE ){
                if (saldo_lectura[i].saldo_once>0){
                    retorno = true;
                    file <<rut << " " + comidas_array[servicio] + "\n";
                }
                else{
                    cout<<"no once"<<endl;
                }
            }
            else if (servicio == SERV_CENA ){
                if (saldo_lectura[i].saldo_cena>0){
                    retorno = true;
                    file <<rut << " " + comidas_array[servicio] + "\n";
                }
                else{
                    cout<<"no cena"<<endl;
                }
            }
            
        }
        else{
            cout<<"no rut"<<endl;
        }

    }
    cout<<retorno<<endl;
    file.close();
    file_binario.close();
    return retorno;
};

int main(){
        bool test = puedeConsumir("11111111-1",0,"Consumos");
        bool test2 = puedeConsumir("11111111-1",2,"Consumos");
        bool test3= puedeConsumir("11111111-1",7,"Consumos");
        bool test4 = puedeConsumir("22222222-2",2,"Consumos");
    return 0;
}
