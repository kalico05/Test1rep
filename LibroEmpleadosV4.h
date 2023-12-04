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
void AgregarBonos(double bons, string concepto);
double getBonos();
void AgregarDeducciones(double deds, string concepto);
double getDeducciones(); 
int CalcularSalarioTotal();

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

void Empleado::setNombre(string n){
    nombre=n;
}

void Empleado::setMatricula(string m){
    matricula=m;
}

void Empleado::setSalario(double s){
    salario=s;
}

void Empleado:: AgregarBonos(double bons, string concepto){
    bonos+=bons;
}

void Empleado::AgregarDeducciones(double deds, string concepto){
    deducciones+=deds;
}

double Empleado::getBonos(){
    return bonos;
}

double Empleado::getDeducciones(){
    return deducciones;
}

int Empleado::CalcularSalarioTotal(){
  return salario + bonos + deducciones;
}