#include <iostream>
#include <ctime>
#include <cstdlib>
#include <lab2header.h>
#include <iostream>

using namespace std;

int main()
{
    char cadena[100];
    cout << "Introduce la cadena: ";
    cin >> cadena;
    int numero = convertirCadenaAEntero(cadena);
    numero += 1;
    cout << numero << endl;
    //problema_14();
    //int n;
    //cout << "Ingrese el tamanio de la cuadricula (n): ";
    //cin >> n;
    //long long caminos = factorial(2 * n) / (factorial(n) * factorial(n));

    //cout << "Para una malla de " << n << "x" << n << " puntos hay " << caminos << " caminos." << endl;

    return 0;
}
