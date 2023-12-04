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
void setBonos(double b);
void setDeducciones(double d);

//Acciones
void AgregarBonos(double bons, string concepto);
double getBonos();
void AgregarDeducciones(double deds, string concepto);
double getDeducciones(); 
double CalcularSalarioTotal();

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

void Empleado::setBonos(double b){
    bonos=b;
}
 
void Empleado::setDeducciones(double d){
    deducciones=d;
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

double Empleado::CalcularSalarioTotal(){
    double BonosT=0;
    double DeduccionesT=0;
    
    BonosT+=bonos;
    DeduccionesT+=deducciones;

    return salario + BonosT + DeduccionesT;
}
