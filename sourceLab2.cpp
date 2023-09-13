#include <lab2header.h>
#include <ctime>
#include <stdlib.h>
#include <iostream>

using namespace std;


void arregloLetras()
{
    srand(time(NULL));
    const int dimension = 200;
    char arreglo[dimension];

    for (int i = 0; i < dimension; i++){
        arreglo[i] = 'A' + rand() % 26;
    }
    for (int i = 0; i < dimension; i++){
        cout << arreglo[i];
    }
    cout << endl;
    int rep[26] = {0};
    for (int i = 0; i < dimension; i++){
        if (arreglo[i] >= 'A' && arreglo[i] <= 'z'){
            rep[arreglo[i] - 'A']++;
        }
    }
    for (char letra = 'A'; letra <= 'Z'; letra++) cout << letra << ": " << rep[letra - 'A'] << endl;


}
void convertirAMayusculas(char cadena[]) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') cadena[i] = cadena[i] - 'a' + 'A';
    }
}
void cadenaYNumero(char cadena[])
{
    char newCadena[100];
    int j;
    for (int i = 0; cadena[i] != '\0'; i++){
        if (!isdigit(cadena[i])){
            newCadena[j] = cadena[i];
            j++;
        }
    }
    cout << newCadena << endl;

}
void numeroRomano(char cadena[]){
    int numero = 0;
    int j = 1;

    for (int i = 0; cadena[j] != '\0'; i += 2)
    {
        int valor = 0;
        int valorSiguiente = 0;
        switch (cadena[i])
        {
        case 'M': valor = 1000; break;
        case 'D': valor = 500; break;
        case 'C': valor = 100; break;
        case 'L': valor = 50; break;
        case 'X': valor = 10; break;
        case 'V': valor = 5; break;
        case 'I': valor = 1; break;
        }
        switch (cadena[j])
        {
        case 'M': valorSiguiente = 1000; break;
        case 'D': valorSiguiente = 500; break;
        case 'C': valorSiguiente = 100; break;
        case 'L': valorSiguiente = 50; break;
        case 'X': valorSiguiente = 10; break;
        case 'V': valorSiguiente = 5; break;
        case 'I': valorSiguiente = 1; break;
        }

        if (valor < valorSiguiente)
        {
            valor -=  valorSiguiente;
            numero -= valor;
        }
        else
        {
            valor +=  valorSiguiente;
            numero += valor;
        }
        j += 2;
    }

    cout << "El numero ingresado fue: " << cadena << endl;
    cout << "Que corresponde a: " << numero << endl;
}
void matriz(){
    int filas, columnas;
    cout << "Ingrese el número de filas de la matriz: ";
    cin >> filas;
    cout << "Ingrese el número de columnas de la matriz: ";
    cin >> columnas;

    // Declara una matriz como un arreglo bidimensional de enteros
    int matriz[filas][columnas];

    // Solicita al usuario ingresar los elementos de la matriz
    cout << "Ingrese los elementos de la matriz:" << endl;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento en la fila " << i + 1 << " y columna " << j + 1 << ": ";
            cin >> matriz[i][j];
        }
    }

    // Muestra la matriz ingresada por el usuario
    cout << "La matriz ingresada es:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}
