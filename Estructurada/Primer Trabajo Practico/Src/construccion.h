#ifndef CONSTRUCCION_H
#define CONSTRUCCION_H
#include <string>


using namespace std;

//pre:
//post:Crea en memoria dinamica un array con la informacion de los txt, y almacena en variables size y size1 el tamaño.
void lecturaArchivos(string* &materiales,int* size, string* &edificios,int* size1);

//pre:
//post:
int mostrarMenu();

//pre:Debe recibir una lista de materiales con el tamaño de la lista.
//post:Muestra por pantalla nombre y cantidad de materiales.
void listarMateriales(string materiales[],int tamanoVecMateriales);

//pre:Recibe 2 listas, una de materiales y una de edificios.
//post:Construye un edificio, de no poder constuir muestra un mensaje, agrega o quita materiales a la lista materiales.
void construirEdificio(string* &edificios,int tamanoVecEdificios, string* &materiales, int tamanoVecMateriales);

//pre:Recibe una lista con los datos de los edificos y su tamaño de datos.
//post:Muestra los edificios disponibles para construir.
void listarEdificios(string* &edificios,int tamanoVecEdificios);

//pre:Recibe una lista con los datos de los edificos y su tamaño de datos.
//post:Muestra que necesita cada edificio para constuirse la cantidad construida y la cantidad maxima permitida para construir.
void listarDatosParaEdificios(string* &edificios,int tamanoVecEdificios);

//pre:Recibe 2 listas, una de materiales y una de edificios.
//post:Destruye un edificio y suma la cantidad de material correspondiente.
void demolerEdificio(string* &edificios,int tamanoVecEdificios, string* &materiales, int tamanoVecMateriales);

//pre:Recibe una lista con los datos de los edificos, materiales y sus tamaños de datos.
//post:Si hubo cambios en los datos de algun archivo este archivo lo escribe en un txt.
void escribirArchivos(string* &edificios,int tamanoVecEdificios,string* &materiales,int tamanoVecMateriales);

//pre:Recibe un puntero a memoria dinamica.
//post:elimina la memoria dinamica solicitada.
void borrarMemoriaDinamica(string* &puntero,int tamanoVec);


//pre:Recibe la lista de materiales, el tamaño de datos y la palabra a buscar.
//post:Devuelve la cantidad del material o -1 si no la encontrò.
int materialesDisponibles(string* &materiales,int tamanoVecMateriales, string palabra);

//pre:
//post:Devuelve la posicion en el vector donde se encuentra el nombre del edificio.
int posicionEnVector(string* &edificios,int opcion);

//pre:
//post:
int mostrarEdificios(string* &edificios,int tamanoVecEdificios);


//pre:
//post:
void crearArrayDinamico(string* &materiales,int size);


//pre:Debe recibir la opcion menor y mayor que puedo elegir el usuario.
//post:Valida si la opcion que colocara el usuario se encuentra entre valores validos y devuelve un booleano.
int validarInt(int menor,int mayor);

#endif
