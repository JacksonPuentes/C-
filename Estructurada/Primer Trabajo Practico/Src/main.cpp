#include<iostream>
#include<string.h>
#include "construccion.h"

using namespace std;

int main()
{
    int tamanoVecMateriales;
    int tamanoVecEdificios;
    int opcion=0;
    string* materiales, *edificios;
    bool bandera;


    lecturaArchivos(materiales,&tamanoVecMateriales,edificios,&tamanoVecEdificios);

    while(opcion!=6){
        opcion = mostrarMenu();

        if (opcion==1)
        {
            listarMateriales(materiales,tamanoVecMateriales);
        }
        else if (opcion==2)
        {
            construirEdificio(edificios,tamanoVecEdificios,materiales,tamanoVecMateriales);
            bandera=1;
        }
        else if (opcion==3)
        {
            listarEdificios(edificios,tamanoVecEdificios);
        }
        else if (opcion==4)
        {
            listarDatosParaEdificios(edificios,tamanoVecEdificios);
        }
        else if (opcion==5)
        {
            DemolerEdificio(edificios,tamanoVecEdificios,materiales,tamanoVecMateriales);
            bandera=1;
        }
        
    }
    
    if (bandera)
    {
        escribirArchivoEdificio(edificios,tamanoVecEdificios);
        escribirArchivoMateriales(materiales,tamanoVecMateriales);
    }
    
    
    cout<<"\n....::::HASTA PRONTO::::....\n"<<endl;

    borrarMemoriaDinamica(materiales);
    borrarMemoriaDinamica(edificios);

    return 0;
}


