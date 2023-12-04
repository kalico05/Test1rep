#include <iostream>
#include "LibroEmpleadosV3.h"
using namespace std;

int main(){
    bool acceso=false;
    do{
    string contrasenia="";
    cout<<"Ingrese contrasena: ";
    cin>>contrasenia;

    if (contrasenia=="123"||contrasenia=="holamundo"||contrasenia=="contrasena"){
        acceso=true;
        system("cls");
        
    }


    }while(acceso!=true);


    return 0;
}