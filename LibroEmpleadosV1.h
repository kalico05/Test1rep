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

public:

Empleado(string n="", string m="", double s=0.0);

//Métodos

string getNombre();
string getMatricula();
double getSalario();

void setNombre(string n);
void setMatricula(string m);
void setSalario(double s);

//Acciones
void AgregarBonos(double bons);
void AgregarDeducciones(double deds);
void getBonos();
void getDeducciones();
void CalcularSalario();
};

//Constructor
Empleado::Empleado(string n, string m, double s): nombre(n), matricula (m), salario(s){}

string Empleado::getNombre(){
    return nombre;
}

string Empleado::getMatricula(){
    return matricula;
}

double Empleado::getSalario(){
    return salario;
}

double Empleado bonos;
double deducciones;
void Empleado::setNombre(string n){
    nombre=n;
}

void Empleado::setMatricula(string m){
    matricula=m;
}

void Empleado::setSalario(double s){
    salario=s;
}

void Empleado:: AgregarBonos(double bons){
    salario+=bons;
}

void Empleado::AgregarDeducciones(double deds){
    salario+=deds;
}

void Empleado::getBonos(){
    return bonos;
}
