#include <iostream>
#include <string>
using namespace std;

class Empleado{
private://Atributos

string nombre;
string matricula;
double salario;
double bonos;
double deducciones;

public://Métodos

Empleado(string n="", string m="", double salario=0.0);

};