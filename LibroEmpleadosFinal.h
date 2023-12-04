#include <iostream>
#include <string>
using namespace std;

class Empleado {
private:
    string nombre;
    string matricula;
    double salario;
    double bonos;
    double deducciones;

public:
    Empleado(string n = "", string m = "", double s = 0.0);

    // Métodos de acceso
    string getNombre();
    string getMatricula();
    double getSalario();
    double getBonos();
    double getDeducciones();

    // Métodos de modificación
    void setNombre(string n);
    void setMatricula(string m);
    void setSalario(double s);
    void AgregarBonos(double b, string concepto);
    void AgregarDeducciones(double d, string concepto);
    double CalcularSalarioTotal();
};

// Implementación de los métodos de la clase Empleado
Empleado::Empleado(string n, string m, double s) : nombre(n), matricula(m), salario(s), bonos(0.0), deducciones(0.0) {}

string Empleado::getNombre() {
    return nombre;
}

string Empleado::getMatricula() {
    return matricula;
}

double Empleado::getSalario() {
    return salario;
}

double Empleado::getBonos() {
    return bonos;
}

double Empleado::getDeducciones() {
    return deducciones;
}

void Empleado::setNombre(string n) {
    nombre = n;
}

void Empleado::setMatricula(string m) {
    matricula = m;
}

void Empleado::setSalario(double s) {
    salario = s;
}

void Empleado::AgregarBonos(double b, string concepto) {
    bonos += b;
    cout << "Se agregaron " << b << " de bonos por concepto: " << concepto << endl;
}

void Empleado::AgregarDeducciones(double d, string concepto) {
    deducciones += d;
    cout << "Se agregaron " << d << " de deducciones por concepto: " << concepto << endl;
}

double Empleado::CalcularSalarioTotal() {
    return salario + bonos - deducciones;
}