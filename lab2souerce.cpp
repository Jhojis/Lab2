#include <lab2header.h>
#include <ctime>
#include <stdlib.h>
#include <iostream>

using namespace std;

int convertirCadenaAEntero(char cadena[])
{
    int numero = 0;
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        int valor = cadena[i] - '0';
        numero = numero * 10 + valor;
    }
    return numero;
}
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
    cout << "Ingrese el numero de filas de la matriz: ";
    cin >> filas;
    cout << "Ingrese el numero de columnas de la matriz: ";
    cin >> columnas;

    int matriz[filas][columnas];

    cout << "Ingrese los elementos de la matriz:" << endl;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento en la fila " << i + 1 << " y columna " << j + 1 << ": ";
            cin >> matriz[i][j];
        }
    }

    cout << "La matriz ingresada es:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    //Suma de referencia
    int sumaDeReferencia = 0;
    for (int j = 0; j < columnas; j++) {
        sumaDeReferencia += matriz[0][j];
    }

    //Determinar si es magica
    // Suma de las filas...
    bool esCuadradoMagic = true;
    for (int i = 0; i < filas; i++) {
        int sumaFilas = 0;
        for (int j = 0; j < columnas; j++) {
            sumaFilas += matriz[i][j];
        }
        if (sumaDeReferencia != sumaFilas) {
            esCuadradoMagic = false;
            break;
        }
    }
    //Suma de las columnas...
    for (int j = 0; j < columnas; j++) {
        int sumaColumnas = 0;
        for (int i = 0; i < filas; i++) {
            sumaColumnas += matriz[i][j];
        }
        if (sumaDeReferencia != sumaColumnas) {
            esCuadradoMagic = false;
            break;
        }
    }
    //Suma de la diagonal principal
    int sumaDiagonalPrincipal = 0;
    for (int i = 0; i < filas; i++) sumaDiagonalPrincipal += matriz[i][i];

    if (sumaDeReferencia != sumaDiagonalPrincipal) esCuadradoMagic = false;

    //sumaDiagonalSecundaria
    int sumaDiagonalSecundaria = 0;
    for (int i = 0; i < filas; i++) sumaDiagonalSecundaria += matriz[i][filas - 1 - i];

    if (sumaDeReferencia != sumaDiagonalSecundaria) esCuadradoMagic = false;


    if (esCuadradoMagic) cout << "Magiaaa" << endl;
    else cout << "No magiaaa" << endl;

}
int **dinamic_memory(int n)
{
    int **matrix = new int *[n];
    for(int i=0; i<n; i++) matrix[i] = new int [n];

    return matrix;
}
void generate_matrix(int **matrix, int n)
{
    for(int fil = 0; fil<n;fil++){
        for(int col=0;col<n;col++) matrix[fil][col] = n*fil+(col+1);
    }
}
void print_matrix(int **matrix, int n)
{
    for(int fil = 0; fil<n;fil++){
        for(int col=0;col<n;col++) cout << matrix[fil][col]<< '\t';
        cout << endl << endl;
    }
}
void problema_14()
{
    int n, ***conj_matrix;
    cout << "ingrese un numero: ";
    cin >> n;
    conj_matrix = dinamic_memory_P3(4,n);
    generate_matrix(conj_matrix[0],n);
    cout << "Matriz rotada 0 grados " << endl << endl;
    print_matrix(conj_matrix[0],n);
    for(int i=1;i<4;i++){
        cout << "Matriz rotada "<< 90*(i) << " grados " << endl << endl;
        rotate_90(conj_matrix[i-1],conj_matrix[i],n);
        print_matrix(conj_matrix[i],n);
    }
    delete_P3(conj_matrix,n);
}
int ***dinamic_memory_P3(int n,int m)
{
    int ***conj_matrix = new int**[n];
    for(int i=0; i<n; i++) conj_matrix[i] = dinamic_memory(m);

    return conj_matrix;
}
void rotate_90(int **matrix, int**n_matrix, int n)
{
    for(int fil = 0; fil<n;fil++){
        for(int col=0;col<n;col++) n_matrix[col][n-1-fil] = matrix[fil][col];
    }
}
void delete_P2(int **matrix, int n)
{
    for(int i=0; i<n; i++) delete[] matrix[i];
    delete[] matrix;
}
void delete_P3(int ***conj_matrix, int n)
{
    for(int i=0; i<4; i++) delete_P2(conj_matrix[i],n);
    delete[] conj_matrix;
}
long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}
