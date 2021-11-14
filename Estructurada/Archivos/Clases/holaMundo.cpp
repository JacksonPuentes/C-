#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const string NOMBREDOCUMENTO = "frutas.txt";
const string NOMBREDOCUMENTO2 = "archivo.txt";

void escribirArchivo(){
    ofstream archivo_escritura(NOMBREDOCUMENTO2);

    string campo;

    cout << "EScriba algo: ";
    cin >> campo;

    archivo_escritura<<campo<<endl;

    cout << "EScriba algo: ";
    cin >> campo;

    archivo_escritura<<campo<<endl;

    archivo_escritura.close();
}

void leerArchivo(){

    ifstream archivo_entrada(NOMBREDOCUMENTO);

    string nombre,cantidad;
    int contador=0;

    while(getline(archivo_entrada, nombre,';')){
        getline(archivo_entrada, cantidad,'\n');

        if (contador!=0)
        {
           cout<<"Hay " + cantidad + " " + nombre <<endl;
        }
        contador++;
    }

    archivo_entrada.close();
}

int main(){    

    leerArchivo();
    escribirArchivo();

    return 0;
}

