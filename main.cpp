#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void create_file(string name);
void write_file(string name, string info);
string read_file(string name);

int main()
{
    write_file("prueba.txt", "Hola mundo!");
    cout << "Hello World!" << endl;
    return 0;
}

void create_file(string name)
{
    fstream file;
    file.open(name, ios::out);
    file.close();
}
void write_file(string name, string info)
{
    fstream file;
    file.open(name, ios::out);
    file << info;
    file.close();
}
string read_file(string name)
{
    fstream file;
    unsigned long long tam;
    file.open(name, ios::in | ios::ate);
    if (file.is_open()){
        tam = file.tellg();
        file.seekg(0);
        for (unsigned long long i = 0; i < tam; i++){
            //data.push_back(file.get());
        }
    }
    file.close();
}


