#include <iostream>
#include "LibroEmpleadosFinal.h"
using namespace std;

int main() {
    bool acceso = false;

    do {
        string contrasenia = "";
        cout << "Ingrese contrasena: ";
        cin >> contrasenia;

        if (contrasenia == "123" || contrasenia == "holamundo" || contrasenia == "contrasena") {
            acceso = true;
            system("cls");
            int contador = 0;
            int MAX_EMPLEADOS = 0;
            cout << "Ingrese la cantidad de empleados a registrar: " << endl;
            cin >> MAX_EMPLEADOS;
            Empleado empleados[MAX_EMPLEADOS];
            char option;

            do {
                system("cls");
                cout << "__MENU__" << endl;
                cout << "a) Agregar empleado" << endl;
                cout << "b) Modificar empleado" << endl;
                cout << "c) Eliminar empleado" << endl;
                cout << "d) Plantilla de empleados" << endl;
                cout << "e) Consultar empleado" << endl;
                cout << "f) Agregar Bonos/Deducciones" << endl;
                cout << "g) Salir" << endl;
                cin >> option;

                switch (option) {
                    case 'a': {
                        if (contador < MAX_EMPLEADOS) {
                            system("cls");

                            string n, m;
                            double s;

                            cout << "Nombre del empleado: ";
                            cin >> n;
                            cout << "Matricula del empleado: ";
                            cin >> m;
                            cout << "Salario del empleado: ";
                            cin >> s;

                            Empleado empleado(n, m, s);
                            empleados[contador] = empleado;
                            cout << "Indice de la cuenta: " << contador << endl;
                            contador++;
                        } else {
                            cout << "Se ha alcanzado el limite de empleados." << endl;
                        }
                        break;
                    }

                    case 'b': {
                        system("cls");
                        cout << "__MODIFICAR EMPLEADOS__" << endl;
                        int indcuentamod = 0;
                        char optionb;

                        cout << "Ingrese el indice de cuenta: ";
                        cin >> indcuentamod;

                        if (indcuentamod >= 0 && indcuentamod < contador) {
                            do {
                                cout << "\nNombre: " << empleados[indcuentamod].getNombre() << endl;
                                cout << "Matricula: " << empleados[indcuentamod].getMatricula() << endl;
                                cout << "Salario: " << empleados[indcuentamod].getSalario() << endl;
                                cout << "Ingrese el dato a modificar" << endl;
                                cout << "a) Nombre" << endl;
                                cout << "b) Matricula" << endl;
                                cout << "c) Salario" << endl;
                                cout << "d) Salir al menu" << endl;
                                cin >> optionb;

                                switch (optionb) {
                                    case 'a': {
                                        system("cls");
                                        string newName;
                                        cout << "Ingresa el nuevo nombre;" << endl;
                                        cin >> newName;
                                        empleados[indcuentamod].setNombre(newName);
                                        break;
                                    }

                                    case 'b': {
                                        system("cls");
                                        string newMat;
                                        cout << "Ingresa la nueva matricula;" << endl;
                                        cin >> newMat;
                                        empleados[indcuentamod].setMatricula(newMat);
                                        break;
                                    }

                                    case 'c': {
                                        system("cls");
                                        double newSal;
                                        cout << "Ingresa el nuevo salario;" << endl;
                                        cin >> newSal;
                                        empleados[indcuentamod].setSalario(newSal);
                                        break;
                                    }

                                    default:
                                        break;
                                }

                            } while (optionb != 'd');
                        } else {
                            cout << "Índice de empleado no válido." << endl;
                        }
                        break;
                    }

                    case 'c': {
                        system("cls");
                        int indcuentadel = 0;
                        cout << "__ELIMINAR EMPLEADO__" << endl;
                        cout << "Ingrese el indice de cuenta a eliminar: ";
                        cin >> indcuentadel;

                        if (indcuentadel >= 0 && indcuentadel < contador) {
                            for (int i = indcuentadel; i < contador - 1; ++i) {
                                empleados[i] = empleados[i + 1];
                            }
                            --contador;
                            cout << "Se ha eliminado el empleado" << endl;
                        } else {
                            cout << "No es posible eliminar esa posicion" << endl;
                        }
                        system("PAUSE()");
                        break;
                    }

                    case 'd': {
                        system("cls");
                        cout << "__PLANTILLA DE EMPLEADOS__" << endl;

                        for (int i = 0; i < contador; i++) {
                            cout << "\nNombre: " << empleados[i].getNombre() << endl;
                            cout << "Matricula: " << empleados[i].getMatricula() << endl;
                            cout << "Salario base: " << empleados[i].getSalario() << endl;
                            cout << "Bonos: " << empleados[i].getBonos() << endl;
                            cout << "Deducciones: " << empleados[i].getDeducciones() << endl;
                            cout << "Salario Total: " << empleados[i].CalcularSalarioTotal() << endl;
                        }
                        system("PAUSE()");
                        break;
                    }

                    case 'e': {
                        system("cls");
                        cout << "__CONSULTAR EMPLEADO__" << endl;
                        int indice = 0;
                        cout << "Introduce el indice del empleado a consultar: " << endl;
                        cin >> indice;

                        if (indice >= 0 && indice < contador) {
                            cout << "Nombre: " << empleados[indice].getNombre() << endl;
                            cout << "Matricula: " << empleados[indice].getMatricula() << endl;
                            cout << "Salario base: " << empleados[indice].getSalario() << endl;
                            cout << "Bonos: " << empleados[indice].getBonos() << endl;
                            cout << "Deducciones: " << empleados[indice].getDeducciones() << endl;
                            cout << "Salario Total: " << empleados[indice].CalcularSalarioTotal() << endl;
                        } else {
                            cout << "Indice de empleado no valido." << endl;
                        }
                        system("PAUSE()");
                        break;
                    }

                    case 'f': {
                        system("cls");
                        cout << "__AGREGAR BONOS/DEDUCCIONES__" << endl;
                        int ind = 0;
                        cout << "Ingresa el indice del empleado:" << endl;
                        cin >> ind;

                        // Verificar si el índice es válido
                        if (ind >= 0 && ind < contador) {
                            char optionf;

                            do {
                                cout << "a) Agregar Bono" << endl;
                                cout << "b) Agregar Deduccion" << endl;
                                cout << "c) Salir al menu" << endl;
                                cin >> optionf;

                                switch (optionf) {
                                    case 'a': {
                                        system("cls");
                                        string c;
                                        double b = 0.0;
                                        cout << "Concepto del bono:";
                                        cin >> c;
                                        cout << "Cantidad del bono:";
                                        cin >> b;
                                        empleados[ind].AgregarBonos(b, c);
                                        break;
                                    }

                                    case 'b': {
                                        system("cls");
                                        string c;
                                        double d = 0.0;
                                        cout << "Concepto de la deduccion:";
                                        cin >> c;
                                        cout << "Cantidad de la deduccion:";
                                        cin >> d;
                                        empleados[ind].AgregarDeducciones(d, c);
                                        break;
                                    }

                                    default:
                                        break;
                                }
                            } while (optionf != 'c');
                        } else {
                            cout << "Índice de empleado no válido." << endl;
                        }
                        break;
                    }

                }

            } while (option != 'g');

        } else {
            cout << "Contrasena incorrecta, intente de nuevo" << endl;
        }

    } while (acceso != true);

    return 0;
}
