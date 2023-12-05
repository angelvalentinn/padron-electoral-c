#ifndef CIUDADANOS_H_INCLUDED
#define CIUDADANOS_H_INCLUDED

#include "localidad.h"

typedef struct Ciudadano Ciudadano;
typedef Ciudadano * CiudadanoPtr;

CiudadanoPtr crearCiudadanoNulo();

void crearCiudadanosNulos(CiudadanoPtr ciudadanos[], int t);

void crearCiudadanoPorParametro(CiudadanoPtr ciudadanos[], int t ,char n[30], char a[30], char ln[30], int cp);

void mostrarCiudadano(CiudadanoPtr ciudadano);

void mostrarCiudadanos(CiudadanoPtr ciudadanos[], int t);

void ordenarlosPorCP(CiudadanoPtr ciudadanos[], int t);

void eliminarCiudadanosBanfield(CiudadanoPtr ciudadanos[], int t);

void guardarCiudadanosEnTxt(CiudadanoPtr ciudadanos[], int t);

void liberarCiudadanos(CiudadanoPtr ciudadanos[], int t);


char* getNombreCiudadano(CiudadanoPtr ciudadano);
char* getApellido(CiudadanoPtr ciudadano);
int getDni(CiudadanoPtr ciudadano);
LocalidadPtr getLocalidad(CiudadanoPtr ciudadano);

void setNombreCiudadano(CiudadanoPtr ciudadano, char* n);
void setApellido(CiudadanoPtr ciudadano, char* a);
void setDni(CiudadanoPtr ciudadano, int d);

#endif // CIUDADANOS_H_INCLUDED
