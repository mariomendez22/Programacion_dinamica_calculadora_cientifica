#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
#include <limits>

using namespace std;

// ------------ FUNCIONES BÁSICAS ------------

// Suma: int con parámetro por omisión
int suma(int a, int b = 0) {
    return a + b;
}

// Suma: double (sobrecarga)
double suma(double a, double b) {
    return a + b;
}

// Resta
int resta(int a, int b) {
    return a - b;
}
double resta(double a, double b) {
    return a - b;
}

// Multiplicación
int multiplicar(int a, int b) {
    return a * b;
}
double multiplicar(double a, double b) {
    return a * b;
}

// División (checar división entre cero manualmente)
double dividir(double a, double b) {
    if (b == 0.0) {
        throw runtime_error("No se puede dividir entre cero.");
    }
    return a / b;
}

// ------------ FUNCIONES AVANZADAS ------------

// Factorial recursivo
unsigned long long factorial(unsigned int n) {
    if (n == 0 || n == 1)
        return 1ULL;
    return n * factorial(n - 1);
}

// Potencia 
double potencia(double base, int exp) {
    int i;
    double resultado = 1.0;

    int e = exp;
    if (e < 0) e = -e;

    for (i = 0; i < e; i++) {
        resultado *= base;
    }

    if (exp < 0) {
        if (resultado == 0.0)
            throw runtime_error("Potencia negativa con base 0 genera division por cero.");
        return 1.0 / resultado;
    }

    return resultado;
}

// Raíz cuadrada
double raizCuadrada(double x) {
    if (x < 0.0)
        throw runtime_error("No existe raiz real para numeros negativos.");
    return sqrt(x);
}

// ------------ LECTURA SEGURA ------------

double leerDouble(const string &msg) {
    double x;
    cout << msg;
    if (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("Entrada invalida (se esperaba numero).");
    }
    return x;
}

int leerEntero(const string &msg) {
    int x;
    cout << msg;
    if (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("Entrada invalida (se esperaba entero).");
    }
    return x;
}

// ------------ MENÚ ------------

void mostrarMenu() {
    cout << "\n--- Calculadora ---\n";
    cout << "1. Suma\n";
    cout << "2. Resta\n";
    cout << "3. Multiplicacion\n";
    cout << "4. Division\n";
    cout << "5. Factorial\n";
    cout << "6. Potencia\n";
    cout << "7. Raiz Cuadrada\n";
    cout << "8. Salir\n";
    cout << "--------------------\n";
}

int main() {
    bool correr = true;
    cout << "Calculadora iniciada.\n";

    while (correr) {
        try {
            mostrarMenu();
            int opcion = leerEntero("Opcion: ");

            if (opcion == 1) {
                cout << "SUMA:\n";
                int a = leerEntero("a = ");
                int b = leerEntero("b = (0 si lo quieres por defecto) ");
                cout << "Resultado: " << suma(a, b) << "\n";
            }
            else if (opcion == 2) {
                cout << "RESTA:\n";
                double a = leerDouble("a = ");
                double b = leerDouble("b = ");
                cout << "Resultado: " << resta(a, b) << "\n";
            }
            else if (opcion == 3) {
                cout << "MULTIPLICACION:\n";
                double a = leerDouble("a = ");
                double b = leerDouble("b = ");
                cout << "Resultado: " << multiplicar(a, b) << "\n";
            }
            else if (opcion == 4) {
                cout << "DIVISION:\n";
                double a = leerDouble("a = ");
                double b = leerDouble("b = ");
                cout << "Resultado: " << dividir(a, b) << "\n";
            }
            else if (opcion == 5) {
                cout << "FACTORIAL:\n";
                int n = leerEntero("n (entero >= 0) = ");
                if (n < 0)
                    throw runtime_error("Factorial solo acepta enteros no negativos.");
                cout << "Resultado: " << factorial((unsigned int)n) << "\n";
            }
            else if (opcion == 6) {
                cout << "POTENCIA:\n";
                double base = leerDouble("Base = ");
                int exp = leerEntero("Exponente (entero) = ");
                cout << "Resultado: " << potencia(base, exp) << "\n";
            }
            else if (opcion == 7) {
                cout << "RAIZ CUADRADA:\n";
                double x = leerDouble("Numero = ");
                cout << "Resultado: " << raizCuadrada(x) << "\n";
            }
            else if (opcion == 8) {
                cout << "Saliendo...\n";
                correr = false;
            }
            else {
                cout << "Opcion no valida.\n";
            }
        }
        catch (const exception &e) {
            cout << "Error: " << e.what() << "\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}
