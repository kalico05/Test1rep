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
            cout<<"f) Agregar Bonos/Deducciones"<<endl;
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
                    cout<<"Indice de la cuenta: "<<contador<<endl;
                    contador++;
                    break;
                }

                case 'b':{
                    system ("cls");
                    cout<<"__MODIFICAR EMPLEADOS__"<<endl;
                    int indcuentamod=0;
                    char optionb;

                    cout<<"Ingrese el indice de cuenta";
                    cin>>indcuentamod;

                        do{
                            cout<<"Nombre: "<<empleados[indcuentamod].getNombre()<<endl;
                            cout<<"Matricula: "<<empleados[indcuentamod].getMatricula()<<endl;
                            cout<<"Salario: "<<empleados[indcuentamod].getSalario()<<endl;
                            cout<<"Ingrese el dato a modificar"<<endl;
                            cout<<"a) Nombre"<<endl;
                            cout<<"b) Matricula"<<endl;
                            cout<<"c) Salario"<<endl;
                            cout<<"d) Salir al menu"<<endl;
                            cin>>optionb;

                            switch (optionb){
                                case 'a':{
                                    system("cls");
                                    string newName;
                                    cout<<"Imgresa el nuevo nombre;"<<endl;
                                    cin>> newName;
                                    empleados[indcuentamod].setNombre(newName);
                                    break;
                                }

                                case 'b':{
                                    system("cls");
                                    string newMat;
                                    cout<<"Imgresa la nueva matricula;"<<endl;
                                    cin>> newMat;
                                    empleados[indcuentamod].setMatricula(newMat);
                                    break;
                                }

                                 case 'c':{
                                    system("cls");
                                    double newSal;
                                    cout<<"Imgresa la nueva matricula;"<<endl;
                                    cin>> newSal;
                                    empleados[indcuentamod].setSalario(newSal);
                                    break;
                                }

                                default:
                                break;
                                
                            }
                        
                        }while(optionb !='d');
                        break;
                }
                
                case 'c':{
                    system("cls");
                    int indcuentadel=0;
                    cout<<"__ELIMINAR EMPLEADOs__"<<endl;
                    cin >> indcuentadel;
                    if (indcuentadel>= 0 && indcuentadel < contador) {
                        for (int i = indcuentadel; i < contador - 1; ++i) {
                            empleados[i] = empleados[i + 1];
                        }
                        --contador;
                    }else{ cout<<"No es posible eliminar esa posicion"<<endl;}

                    cout<<"Se ha eliminado el empleado"<<endl;
                    system("PAUSE()");
                    break;
                }

                case 'd':{
                    system("cls");
                    cout<<"__PLANTILLA DE EMPLEADOS__"<<endl;  

                    for (int i=0; i<contador;i++){
                
                        cout<<"Nombre: "<<empleados[i].getNombre() <<endl;
                        cout<<"Matricula: "<<empleados[i].getMatricula() <<endl;
                        cout<<"Salario base: "<<empleados[i].getSalario() <<endl;
                        cout << "Bonos:" << empleados[i].getBonos() <<endl;
                        cout<<"Deducciones"<<empleados[i].getDeducciones()<<endl;
                        cout << empleados[i].CalcularSalarioTotal() <<endl;                        
                                                   
                    }
                    system("PAUSE()");
                    break;
                }
                   
            }
            
        }while (option!='g');
        
    }else{
        cout<<"Contraseña incorrecta, intente de nuevo"<<endl;
    }

    }while(acceso!=true);

    return 0;
}