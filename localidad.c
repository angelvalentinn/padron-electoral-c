#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "localidad.h"

struct Localidad {

    char nombre[30];
    int codigoPostal;

};

LocalidadPtr crearLocalidadNula() {

    LocalidadPtr localidad = (LocalidadPtr) malloc( sizeof(Localidad) );

    if( localidad == NULL ) {

        printf("\n\nError al solicitar memoria\n");
        exit(1);

    }

    return localidad;

};

char* getNombreLocalidad(LocalidadPtr localidad) {
    return localidad->nombre;
};

int getCodigoPostal(LocalidadPtr localidad) {
    return localidad->codigoPostal;
};

void setNombreLocalidad(LocalidadPtr localidad, char n[30]) {
    strcpy(localidad->nombre, n);
};

void setCodigoPostal(LocalidadPtr localidad, int cp) {
    localidad->codigoPostal = cp;
};






