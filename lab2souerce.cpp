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
void cadenaYNumero(char cadena)
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
