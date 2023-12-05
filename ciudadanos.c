#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "ciudadanos.h"
#include "localidad.h"

struct Ciudadano {

    char nombre[30];
    char apellido[30];
    int dni;
    LocalidadPtr localidad;

};

CiudadanoPtr crearCiudadanoNulo() {

    CiudadanoPtr ciudadano = (CiudadanoPtr) malloc( sizeof(Ciudadano) );

    ciudadano->localidad = crearLocalidadNula();

    setDni(ciudadano, -1);

    if( ciudadano == NULL ) {

        printf("\n\nError al solicitar memoria\n");
        exit(1);

    }

    return ciudadano;

};

void crearCiudadanosNulos(CiudadanoPtr ciudadanos[], int t) {


    for(int i=0; i<t; i++) {
        ciudadanos[i] = crearCiudadanoNulo();
    }



};

void crearCiudadanoPorParametro(CiudadanoPtr ciudadanos[], int t ,char n[30], char a[30], char ln[30], int cp) {

    int r = 10000 + rand() % (100000 - 10000 + 1);

    for(int i=0; i<t; i++) {

        if( ciudadanos[i]->dni == -1 ) {

            setNombreCiudadano(ciudadanos[i], n);
            setApellido(ciudadanos[i], a);
            setDni(ciudadanos[i], r);
            setNombreLocalidad( getLocalidad(ciudadanos[i]), ln);
            setCodigoPostal( getLocalidad(ciudadanos[i]), cp);

            return;

        }

    }

    printf("\n\nNo hay lugar para cargar ciudadano!!\n\n");

};

void mostrarCiudadano(CiudadanoPtr ciudadano) {

    if( ciudadano->dni != -1 ) {
        printf("Nombre y Apellido: %s %s\nDni: %d\nLocalidad: %s\nCodigo Postal: %d\n\n", getNombreCiudadano(ciudadano),
        getApellido(ciudadano), getDni(ciudadano) , getNombreLocalidad(ciudadano->localidad), getCodigoPostal(ciudadano->localidad));
    }

};

void mostrarCiudadanos(CiudadanoPtr ciudadanos[], int t) {

    printf("\n\n");
    for(int i=0; i<t; i++) {

        mostrarCiudadano(ciudadanos[i]);

    }

};

void ordenarlosPorCP(CiudadanoPtr ciudadanos[], int t) {

    CiudadanoPtr aux;

    for(int i=0; i<t-1; i++) {

        for(int j=i+1; j<t; j++) {

            if(  getCodigoPostal( getLocalidad(ciudadanos[i]) ) > getCodigoPostal( getLocalidad(ciudadanos[j]) ) ) {

                aux = ciudadanos[i];
                ciudadanos[i] = ciudadanos[j];
                ciudadanos[j] = aux;

            }

        }

    }


};

void eliminarCiudadanosBanfield(CiudadanoPtr ciudadanos[], int t) {

    for(int i=0; i<t; i++) {

        if( strcmp( getNombreLocalidad( getLocalidad(ciudadanos[i]) ), "Banfield") == 0 ) {
            ciudadanos[i] = crearCiudadanoNulo();
        }

    }

};

void guardarCiudadanosEnTxt(CiudadanoPtr ciudadanos[], int t) {

    FILE * archivo = fopen("ciudadanos.txt","w");

    if(archivo == NULL) {
        printf("\n\nError al escribir archivo\n");
        exit(1);
    }

    for(int i=0; i<t; i++) {

        if( getDni(ciudadanos[i]) != -1 ) {

        fprintf(archivo,"%s,%s,%d,%s,%d\n",getNombreCiudadano(ciudadanos[i]), getApellido(ciudadanos[i]), getDni(ciudadanos[i]),
                                           getNombreLocalidad(ciudadanos[i]->localidad),
                                           getCodigoPostal(ciudadanos[i]->localidad));

        }

    }

    fclose(archivo);

};

void liberarCiudadanos(CiudadanoPtr ciudadanos[], int t) {

    for(int i=0; i<t; i++) {

        free(getLocalidad(ciudadanos[i])); //Libero primero localidad
        free(ciudadanos[i]); //Despues el ciudadano

    }

};

char* getNombreCiudadano(CiudadanoPtr ciudadano) {
    return ciudadano->nombre;
};

char* getApellido(CiudadanoPtr ciudadano) {
    return ciudadano->apellido;
};

int getDni(CiudadanoPtr ciudadano) {
    return ciudadano->dni;
};

LocalidadPtr getLocalidad(CiudadanoPtr ciudadano) {
    return ciudadano->localidad;
};

void setNombreCiudadano(CiudadanoPtr ciudadano, char* n) {
    strcpy(ciudadano->nombre, n);
};

void setApellido(CiudadanoPtr ciudadano, char* a) {
    strcpy(ciudadano->apellido, a);
};

void setDni(CiudadanoPtr ciudadano, int d) {
    ciudadano->dni = d;
};





