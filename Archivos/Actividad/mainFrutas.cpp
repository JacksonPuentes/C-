#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void OrdenarFrutas(string NOMBREARCHIVO){

    const string NOMBREESCRITURA="frutas ordenadas.txt";

    string orden={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string arrayName[100];
    string arrayCantidad[100];
    int identify[100];

    string name, cantidad, letra;
    int contador=0;

    ifstream archivo(NOMBREARCHIVO);
    ofstream ordenado(NOMBREESCRITURA);

    while(getline(archivo,name,';')){
        getline(archivo,cantidad,'\n');

        arrayName[contador]=name;
        arrayCantidad[contador]=cantidad;

        for (int i = 0; i < 26; i++)
        {
            letra=name[0];
            if (string(letra)==(string(orden[i])))//por que orden esta como char si esta declarado como string? y sin embargo no puedo castear
            {
                identify[contador]=i;
            }
            
        }

    }

    archivo.close();

    cout << identify;

    //hacer ordenamiento burbuja con numeros
    //escribir en archivo
    
    ordenado.close();

}

void buscarPorNombre(string NOMBREARCHIVO){

    string fruta, name, cantidad;
    int contador=0;

    ifstream archivo(NOMBREARCHIVO);

    cout << "\nIngrese el nombre de la fruta a buscar: ";
    cin >> fruta ;

    while(getline(archivo,name,';')){
        getline(archivo,cantidad,'\n');
        if (name==fruta)
        {
            cout << name + " " + cantidad<<endl;
            contador++;
        }
        
    }

    if (contador==0)
    {
        cout << "\nFruta no en stock\n"<< endl;
    }
    

    archivo.close();


}

void mostrarStock(string NOMBREARCHIVO){

    int contador=0;

    ifstream archivo(NOMBREARCHIVO);

    string name;
    string cantidad;

    while (getline(archivo, name, ';')){
        getline(archivo,cantidad,'\n');

        if (contador!=0)
        {
            cout << name + " " + cantidad<<endl;
        }

        contador++;
    }
    
    archivo.close();

}

void iniciarMenu(){

    const string NOMBREARCHIVO = "frutas.txt";

    int opcion;

    cout << "..::Bienvenido a este programa para frutas::.." << endl ;
    cout << "\n Seleccione una opcion:" << endl ;
    cout << "1)Saber la cantidad de frutas en stock, nombre - cantidad" << endl ;
    cout << "2)Buscar una fruta por nombre" << endl ;
    cout << "3)Ordenar alfabeticamente las frutas" << endl ;
    

    do
    {
        cout << "\n Escriba su opcion: " << endl ;

        cin >> opcion;

        if (opcion<=0 || opcion>=4)
        {
            cout<<"\n Opcion incorrecta: " << endl ;
        }
        

    } while (opcion<=0 || opcion>=4);
    
    if (opcion==1)
    {
        mostrarStock(NOMBREARCHIVO);
    }
    else if (opcion==2)
    {
        buscarPorNombre(NOMBREARCHIVO);
    }
    else if (opcion==3)
    {
            OrdenarFrutas(NOMBREARCHIVO);
    }
    

}

int main(){

    iniciarMenu();
    return 0;

}