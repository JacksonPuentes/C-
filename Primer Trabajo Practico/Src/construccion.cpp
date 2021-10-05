#include<iostream>
#include<string.h>
#include<fstream>
#include "construccion.h"

using namespace std;


void crearArrayDinamico(string* &puntero,int size){

    puntero=new string [size];  
}

int validarInt(int menor,int mayor){
    
    int opcion;
    mayor=mayor+1;

    cout << "Escriba la opcion deseada: ";
    cin >> opcion;

    bool validador = (menor<opcion && opcion<mayor);

    while (!validador)
    {
        cout<<"Elija una opcion correcta: ";
        cin >> opcion;
        validador = (menor<opcion && opcion<mayor);
    }

    cout<<endl;

    return opcion;    
}

int materialesDisponibles(string* &materiales,int tamanoVecMateriales, string palabra){

    int contador=-2,bandera=1;
    string material;


    while (bandera!=0 && contador<tamanoVecMateriales-2)
    {
        contador=contador+2;

        material=materiales[contador];
        
        if (material==palabra)
            bandera=0;        
    }

    if (bandera==0){
        int cantidad = atoi(materiales[contador+1].c_str());

        return cantidad;   
    }

    return -1;
}

int posicionEnVector(string* &edificios,int opcion){

    int  posicion;

    if (opcion!=0)
    {
        posicion=opcion*6;
    }
    else if (opcion==0)
    {
        posicion=0;
    }

    return posicion;
}

int mostrarEdificios(string* &edificios,int tamanoVecEdificios){

    int contador=1;
    const int OPCIONVALIDAMAYOR=(tamanoVecEdificios/6);
    const int OPCIONVALIDAMENOR=0;
    
    for (int i = 0; i < tamanoVecEdificios; i++)
    {
        if (i%6==0)
        {
            cout<< contador;
            cout<< ". " + edificios[i]<<endl;
            contador++;
        } 
    }

    int opcion = validarInt(OPCIONVALIDAMENOR,OPCIONVALIDAMAYOR);

    return opcion;
}

void pasajeInformacionAHeap(string Auxiliar[],int tamano,string* &puntero,int size){


   for (int i = 0; i < size; i++)
    {
        puntero[i]=Auxiliar[i];
    }

}

void leerArchivoEdificios(string* &edificios,int* &size1){

    const string NOMBRE_ARCHIVO_EDIFICIOS = "edificios.txt";

    string edificiosAuxiliar[100];
    string material, cantidad;
    int contador=0;

    ifstream documentoEdificios(NOMBRE_ARCHIVO_EDIFICIOS,std::ios::in);

    while (getline(documentoEdificios,material,' '))
    {
        edificiosAuxiliar[contador]=material;
        contador++;

        for (int i = 0; i < 5; i++)
        {
            if (i!=4){
                getline(documentoEdificios,cantidad,' ');
            }
            else{
                getline(documentoEdificios,cantidad,'\n');
            }
            
            edificiosAuxiliar[contador]=cantidad;
            contador++;
        }

    }
    
    documentoEdificios.close();

    *size1=contador;

    crearArrayDinamico(edificios,*size1);

    pasajeInformacionAHeap(edificiosAuxiliar,100,edificios,*size1);

}

void leerArchivoMateriales(string* &materiales,int* &size){

    const string NOMBRE_ARCHIVO_MATERIALES = "materiales.txt";

    string materialesAuxiliar[20];
    string material, cantidad;
    int contador=0;

    ifstream lectura(NOMBRE_ARCHIVO_MATERIALES,std::ios::in);

    while (getline(lectura,material,' '))
    {
        getline(lectura,cantidad,'\n');
        
        materialesAuxiliar[contador]=material;
        materialesAuxiliar[contador+1]=cantidad;

        contador=contador+2;

    }
     lectura.close();

    *size=contador;
    contador=0;

    crearArrayDinamico(materiales,*size);

    pasajeInformacionAHeap(materialesAuxiliar,20,materiales,*size);

}

void lecturaArchivos(string* &materiales,int* size, string* &edificios,int* size1){
    
    leerArchivoMateriales(materiales,size);
    

    leerArchivoEdificios(edificios,size1);
    
}

int mostrarMenu(){


    const int OPCIONVALIDAMENOR=0;
    const int OPCIONVALIDAMAYOR=6;

    cout<<"\n..::BIENVENIDO::."<<endl;

    cout<<"1. Listar materiales de construcción.  "<<endl;
    cout<< "2. Construir edificio por nombre. "<<endl;
    cout<< "3. Listar los edificios construidos. "<<endl;
    cout<< "4. Listar todos los edificios. "<<endl;
    cout<< "5. Demoler un edificio por nombre.  "<<endl;
    cout<< "6. Guardar y salir.  "<<endl;

    int opcion = validarInt(OPCIONVALIDAMENOR,OPCIONVALIDAMAYOR);

    return opcion;

}

void listarMateriales(string materiales[],int tamanoVecMateriales){

    for (int i = 0; i < (tamanoVecMateriales-1); i+=2)
    {

        cout<<"Material: " + materiales[i] + " || Cantidad: " + materiales[i+1]<<endl;
    }
}

void restarMaterialDisponible(string* &materiales,int tamanoVecMateriales, string palabra,int cantidad){

    int contador=-2,bandera=1;
    string material;


    while (bandera!=0 && contador<tamanoVecMateriales-2)
    {
        contador=contador+2;

        material=materiales[contador];
        
        if (material==palabra)
            bandera=0;        
    }

    int materialesActuales=atoi(materiales[contador+1].c_str());

    materiales[contador+1]=to_string(materialesActuales-cantidad);

}

void construirEdificio(string* &edificios,int tamanoVecEdificios,string* &materiales,int tamanoVecMateriales){

    int opcion = mostrarEdificios(edificios,tamanoVecEdificios);
    int posicionVec = posicionEnVector(edificios,opcion-1);
    string edificioConstruir=edificios[posicionVec];
    int piedraNecesaria=atoi(edificios[posicionVec+1].c_str());
    int maderaNecesaria=atoi(edificios[posicionVec+2].c_str());
    int metalNecesario= atoi(edificios[posicionVec+3].c_str());
    int cantidadConstruidos=atoi(edificios[posicionVec+4].c_str());
    int maximaCantidadPermitidos=atoi(edificios[posicionVec+5].c_str());

    int piedraDisponible=materialesDisponibles(materiales,tamanoVecMateriales, "piedra");
    int maderaDisponible=materialesDisponibles(materiales,tamanoVecMateriales, "madera");
    int metalDisponible=materialesDisponibles(materiales,tamanoVecMateriales, "metal");

    cout<<"\n..:::ZONA DE CONSTRUCCION::..\n"<<endl;

    bool bandera1=(cantidadConstruidos<maximaCantidadPermitidos);
    bool bandera2=(piedraDisponible>=piedraNecesaria);
    bool bandera3=(maderaDisponible>=maderaNecesaria);
    bool bandera4=(metalDisponible>=metalNecesario);

    if (bandera1 && bandera2 && bandera3 && bandera4)
    {
        edificios[posicionVec+4]=to_string(cantidadConstruidos+1);

        restarMaterialDisponible(materiales,tamanoVecMateriales, "piedra",piedraNecesaria);
        restarMaterialDisponible(materiales,tamanoVecMateriales, "madera",maderaNecesaria);
        restarMaterialDisponible(materiales,tamanoVecMateriales, "metal",metalNecesario);

        cout << "\n..::CONSTRUCCION APROBADA::.." << endl;
        cout << "..::CONSTRUCCION FINALIZADA::..\n" << endl;
        cout << "..::" + edificioConstruir + "::..";
        cout << " || Cantidad: " + edificios[posicionVec+4] << endl;
    }
    else if (!bandera1){
        cout << "\n..::MAXIMOS PERMITIDOS CONSTRUIDOS::..\n" << endl;
    }
    else if (!bandera2 || !bandera3 || !bandera4){
        cout << "\n..::MATERIALES INSUFICIENTES::..\n" << endl;
    } 
}

void sumarMaterialDisponible(string* &materiales,int tamanoVecMateriales, string palabra,int cantidad){

    int contador=-2,bandera=1;
    string material;


    while (bandera!=0 && contador<tamanoVecMateriales-2)
    {
        contador=contador+2;

        material=materiales[contador];
        
        if (material==palabra)
            bandera=0;        
    }

    int materialesActuales=atoi(materiales[contador+1].c_str());

    materiales[contador+1]=to_string(materialesActuales+cantidad);

}

void DemolerEdificio(string* &edificios,int tamanoVecEdificios,string* &materiales,int tamanoVecMateriales){

    int opcion = mostrarEdificios(edificios,tamanoVecEdificios);
    int posicionVec = posicionEnVector(edificios,opcion-1);
    string edificioConstruir=edificios[posicionVec];
    int piedraNecesaria=atoi(edificios[posicionVec+1].c_str());
    int maderaNecesaria=atoi(edificios[posicionVec+2].c_str());
    int metalNecesario= atoi(edificios[posicionVec+3].c_str());
    int cantidadConstruidos=atoi(edificios[posicionVec+4].c_str());
    int maximaCantidadPermitidos=atoi(edificios[posicionVec+5].c_str());

    cout<<"\n..:::ZONA DE DEMOLICION::..\n"<<endl;

    if (cantidadConstruidos>0)
    {
        
        edificios[posicionVec+4]=to_string(cantidadConstruidos-1);
        int sumarPiedra=piedraNecesaria/2;
        int sumarMadera=maderaNecesaria/2;
        int sumarMetal=metalNecesario/2;

        sumarMaterialDisponible(materiales,tamanoVecMateriales, "piedra",sumarPiedra);
        sumarMaterialDisponible(materiales,tamanoVecMateriales, "madera",sumarMadera);
        sumarMaterialDisponible(materiales,tamanoVecMateriales, "metal",sumarMetal);

        cout << "\n..::DEMOLICION REALIZADA::.." << endl;

    }
    else if (cantidadConstruidos==0)
    {
        cout<<"\n..:::NO TIENES EDIFICIOS PARA DESTRUIR::..\n"<< endl;
    }    

}


void listarEdificios(string* &edificios,int tamanoVecEdificios){

    for (int i = 0; i < (tamanoVecEdificios-1); i+=6)
    {
        cout<<"Edificio: " + edificios[i] + " || Cantidad construido: " + edificios[i+4]<<endl;
    }
}

void listarDatosParaEdificios(string* &edificios,int tamanoVecEdificios){

    cout<< "..::EDIFICIOS INFORMES::.." <<endl;

    for (int i = 0; i < tamanoVecEdificios; i+=6)
    {
        cout<< "\n..::" + edificios[i] + "::.." <<endl;
        cout<< "->Piedra necesaria:" + edificios[i+1] + "::.." <<endl;
        cout<< "->Madera necesaria:" + edificios[i+2] + "::.." <<endl;
        cout<< "->Metal necesario:" + edificios[i+3] + "::.." <<endl;
        cout<< "*Cantidad construida:" + edificios[i+4] + "::.." <<endl;
        cout<< "*Cantidad maxima para construir:" + edificios[i+5] + "::.." <<endl;
    }

}

void escribirArchivoEdificio(string* &edificios,int tamanoVecEdificios){

    const string NOMBRE_ARCHIVO_EDIFICIOS = "edificios.txt";

    ofstream archivo_escritura(NOMBRE_ARCHIVO_EDIFICIOS,std::ios::out);

    for (int i = 0; i < tamanoVecEdificios; i+=6)
    {
        archivo_escritura<<edificios[i] + " " + edificios[i+1] + " " + edificios[i+2] + " "+edificios[i+3] + " "+edificios[i+4] + " "+edificios[i+5]<<endl;
    }   

    archivo_escritura.close();

}

void escribirArchivoMateriales(string* &materiales,int tamanoVecMateriales){

    const string NOMBRE_ARCHIVO_MATERIALES = "materiales.txt";

    ofstream archivo_escritura2(NOMBRE_ARCHIVO_MATERIALES,std::ios::out);

    for (int i = 0; i < tamanoVecMateriales; i+=2)
    {
        archivo_escritura2<<materiales[i] + " " + materiales[i+1] <<endl;
    }   

    archivo_escritura2.close();
}

void borrarMemoriaDinamica(string* &puntero){

    delete []puntero; 
}



