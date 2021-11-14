#define AGENDA_UTILES_H
#include <string>

using namespace std;

const int OPCIONES_VALIDAS = 5;
const string PATH_CONTACTOS = "contactos.txt";
const int SALIR = 5;
const int CANTIDAD_NUMEROS_EN_TELEFONO = 11;

struct Contacto{
    string nombre;
    long numero;
};

struct Agenda{
    Contacto** contactos;
    int cantidad_de_contactos;
};

//Precondiciones: -
//Postcondiciones: Carga la agenda con los datos del archivo de contactos
void cargar_agenda(Agenda* agenda);

//Precondiciones: -
//Postcondiciones: imprime por pantalla el menu
void mostrar_menu();

//Precondiciones: -
//Postcondiciones: Le solicita al usuario que ingrese el numero de la opcion que desea seleccionar
int pedir_opcion();

//Precondiciones: recibe la opcion elegida precargada
//Postcondiciones: Verifica que la opcion sea un numero entre 0 y el valor de OPCIONES_VALIDAS y si no lo es vuelve a solicitar los datos
void validar_opcion_elegida(int &opcion_elegida);

//Precondiciones: El contacto debe estar bien cargado
//Postcondiciones: Añade el contacto a la agenda
void agregar_contacto(Agenda* agenda, Contacto* contacto);

//Precondiciones: La opcion es valida.
//Postcondiciones: Realiza la opcion indicada.
void procesar_opcion(Agenda* agenda, int opcion);

void cerrar_agenda(Agenda* agenda);

void cargar_agenda(Agenda* agenda);
