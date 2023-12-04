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
        int contador=0;
        int MAX_EMPLEADOS=0;
        cout<<"Ingrese la cantidad de empleados a registrar: "<<endl;
        cin>>MAX_EMPLEADOS;
        Empleado empleados[MAX_EMPLEADOS];
        char option;

        do{
            system("cls");
            cout<<"__MENU__"<<endl;
            cout<<"a) Agregar empleado"<<endl;
            cout<<"b) Modificar empleado"<<endl;
            cout<<"c) Eliminar empleado"<<endl;
            cout<<"d) Plantilla de empleados"<<endl;
            cout<<"e) Consultar empleado"<<endl;
            cout<<"e) Agregar Bonos/Deducciones"<<endl;
            cout<<"g) Salir"<<endl;
            cin>>option;
            
            switch(option){

                case 'a':{
                    system("cls");

                    string n, m;
                    double s;

                    cout << "Nombre del empleado: ";
                    cin >> n;
                    cout << "Matrícula del empleado: ";
                    cin >> m;
                    cout << "Salario del empleado: ";
                    cin >> s;

                    Empleado empleado(n, m, s);
                    empleados[contador]= empleado;
                    contador++;
                    break;
                }

                case 'b':{
                    system ("cls");
                    cout<<"";
                }

            }
            
        }while (option!='g');
        
    }else{
        cout<<"Contraseña incorrecta, intente de nuevo"<<endl;
    }

    }while(acceso!=true);

    return 0;
}