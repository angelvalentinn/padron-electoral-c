#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

typedef struct Localidad Localidad;
typedef Localidad * LocalidadPtr;

LocalidadPtr crearLocalidadNula();

char* getNombreLocalidad(LocalidadPtr localidad);

int getCodigoPostal(LocalidadPtr localidad);

void setNombreLocalidad(LocalidadPtr localidad, char n[30]);

void setCodigoPostal(LocalidadPtr localidad, int cp);

#endif // LOCALIDAD_H_INCLUDED
