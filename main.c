#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ciudadanos.h"
#include "localidad.h"

//Crear un programa que permita administrar al padron electoral.
//Crear un array de como max 10 ciudadanos. De los ciudadanos
//nos interesa saber su nombre, apellido, dni(aleaotorio 10000 y 100000))
//El ciudadano tiene  localidad, la localidad tiene nombre y codigo postal

//Crear 5 personas y agregarlas al array y mostrar los ciudadanos cargados (constructor por parametros)

//Nicolas Perez, de Lanus, 1824
//Jorge Golfieri, de Banfield, 1825
//Alejandra Vranic, de Lanus, 1824
//Leandro Rios, de Lomas, 1832
//Roberto García, de Banfield, 1825

//Ordenarlas por CP, y mostrar a los ciudadanos cargados ordenados.
//Eliminar a los ciudadanos de Banfield
//Guardar el array en uno o varios txt con algun formato facil de recuperacion

int main()
{
    srand(time(NULL));

    int t = 10; //Tamaño ciudadanos

    CiudadanoPtr ciudadanos[t];

    crearCiudadanosNulos(ciudadanos, t);

    crearCiudadanoPorParametro(ciudadanos, t ,"Nicolas", "Perez", "Lanus", 1824);
    crearCiudadanoPorParametro(ciudadanos, t ,"Jorge", "Golfieri", "Banfield", 1825);
    crearCiudadanoPorParametro(ciudadanos, t ,"Alejandra", "Vranic", "Lanus", 1824);
    crearCiudadanoPorParametro(ciudadanos, t ,"Leandro", "Rios", "Lomas", 1832);
    crearCiudadanoPorParametro(ciudadanos, t ,"Roberto", "Garcia", "Banfield", 1825);

    ordenarlosPorCP(ciudadanos, t);

    mostrarCiudadanos(ciudadanos, t);

    eliminarCiudadanosBanfield(ciudadanos, t);

    guardarCiudadanosEnTxt(ciudadanos, t);

    liberarCiudadanos(ciudadanos, t);


    return 0;
}










