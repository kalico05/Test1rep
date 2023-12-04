#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class SistemaSeguridad {
private:
    std::unordered_map<std::string, std::string> usuarios; // Nombre de usuario -> Contraseña
    bool autenticado;
    std::string usuarioAutenticado;

public:
    SistemaSeguridad() : autenticado(false) {}

    void autenticar(const std::string& usuario, const std::string& contrasena) {
        auto it = usuarios.find(usuario);
        if (it != usuarios.end() && it->second == contrasena) {
            autenticado = true;
            usuarioAutenticado = usuario;
            std::cout << "¡Autenticación exitosa!" << std::endl;
        } else {
            std::cout << "Error de autenticación. Usuario o contraseña incorrectos." << std::endl;
        }
    }

    bool estaAutenticado() const {
        return autenticado;
    }

    const std::string& obtenerUsuarioAutenticado() const {
        return usuarioAutenticado;
    }

    void agregarUsuario(const std::string& usuario, const std::string& contrasena) {
        usuarios[usuario] = contrasena;
        std::cout << "Usuario agregado exitosamente." << std::endl;
    }
};

class Empleado {
private:
    std::string nombre;
    double salarioBase;
    double bono;
    double deducciones;

public:
    Empleado(const std::string& nombre, double salarioBase, double bono, double deducciones)
        : nombre(nombre), salarioBase(salarioBase), bono(bono), deducciones(deducciones) {}

    double calcularSalarioTotal() const {
        return salarioBase + bono - deducciones;
    }

    const std::string& obtenerNombre() const {
        return nombre;
    }

    void modificarSalarioBase(double nuevoSalarioBase) {
        salarioBase = nuevoSalarioBase;
    }
};

class ModuloEmpleados {
private:
    std::vector<Empleado> empleados;

public:
    void agregarEmpleado(const std::string& nombre, double salarioBase, double bono, double deducciones) {
        empleados.emplace_back(nombre, salarioBase, bono, deducciones);
        std::cout << "Empleado agregado exitosamente." << std::endl;
    }

    void consultarSalario(const std::string& nombre, const SistemaSeguridad& sistema) const {
        // Verificar autenticación antes de mostrar el salario
        if (sistema.estaAutenticado()) {
            for (const auto& empleado : empleados) {
                if (empleado.obtenerNombre() == nombre) {
                    std::cout << "El salario total de " << nombre << " es: " << empleado.calcularSalarioTotal() << std::endl;
                    return;
                }
            }
            std::cout << "Empleado no encontrado." << std::endl;
        } else {
            std::cout << "Debe estar autenticado para consultar salarios." << std::endl;
        }
    }

    void mostrarTodos() const {
        for (const auto& empleado : empleados) {
            std::cout << "Nombre: " << empleado.obtenerNombre() << "\tSalario Total: " << empleado.calcularSalarioTotal() << std::endl;
        }
    }
};

int main() {
    SistemaSeguridad sistema;

    ModuloEmpleados moduloEmpleados;

    int opcion;
    do {
        std::cout << "\n--- Menú ---\n";
        std::cout << "1. Agregar Empleado\n";
        std::cout << "2. Consultar Salario\n";
        std::cout << "3. Mostrar Todos los Empleados\n";
        std::cout << "0. Salir\n";
        std::cout << "Ingrese su opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string nombre, contrasena;
                double salarioBase, bono, deducciones;

                std::cout << "Ingrese el nombre del empleado: ";
                std::cin >> nombre;
                std::cout << "Ingrese la contraseña del empleado: ";
                std::cin >> contrasena;

                sistema.agregarUsuario(nombre, contrasena);

                std::cout << "Ingrese el salario base: ";
                std::cin >> salarioBase;
                std::cout << "Ingrese el bono: ";
                std::cin >> bono;
                std::cout << "Ingrese las deducciones: ";
                std::cin >> deducciones;

                moduloEmpleados.agregarEmpleado(nombre, salarioBase, bono, deducciones);
                break;
            }
            case 2: {
                if (!sistema.estaAutenticado()) {
                    std::string usuario, contrasena;
                    std::cout << "Ingrese su nombre de usuario: ";
                    std::cin >> usuario;
                    std::cout << "Ingrese su contraseña: ";
                    std::cin >> contrasena;

                    sistema.autenticar(usuario, contrasena);
                }

                if (sistema.estaAutenticado()) {
                    std::string nombreConsulta;
                    std::cout << "Ingrese el nombre del empleado para consultar salario: ";
                    std::cin >> nombreConsulta;
                    moduloEmpleados.consultarSalario(nombreConsulta, sistema);
                }
                break;
            }
            case 3:
                moduloEmpleados.mostrarTodos();
                break;
            case 0:
                std::cout << "Saliendo del sistema. ¡Hasta luego!" << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
        }

    } while (opcion != 0);

    return 0;
}