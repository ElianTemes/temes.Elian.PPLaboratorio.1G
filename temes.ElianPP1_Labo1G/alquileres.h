#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include "juego.h"
#include "categoria.h"
#include "cliente.h"
#include "funciones.h"
#include "localidad.h"

#define TAM 5
#define TAMN 51
#define TEL 21
#define TRUE 1
#define FALSE 0

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int codigoAlq;
    int codigoJuego;
    int codigoCliente;
    int isEmpty;
    eFecha fecha;
}eAlquileres;

int initAlquileres(eAlquileres alquiler[], int tam);
int indexLibreAlquiler(eAlquileres alquiler[], int tam);
int chequeoArray(eAlquileres alquileres[], int tamAlq, eJuego juegos[], int tamJuego, eCliente clientes[], int tamClientes, eFecha fechas[], int tamFechas);
int altaAlquiler(eAlquileres alquileres[], int tamAlquiler, int* codigoAlq, eJuego juegos[], int tamJuego, eCliente clientes[], int tamClientes, eFecha fechas[], int tamFechas, eLocalidad loc[], int tamLoc);
int mostrarAlquileres(eAlquileres alquileres[], int tamAlquiler, eCliente cliente[], int tamClientes, eJuego juego[], int tamJuego ,eCategoria cat[], int tamCat, eLocalidad loc[], int tamLoc);
int bajaCliente(eCliente cliente[], int tamCli, eAlquileres alquiler[], int tamAlq);
int mostrarAlqCliente(eAlquileres alquileres[], int tamAlquiler, eCliente cliente[], int tamClientes, eJuego juego[], int tamJuego ,eCategoria cat[], int tamCat, eLocalidad loc[], int tamLoc);
int mostrarImporteCliente(eAlquileres alquileres[], int tamAlquiler, eCliente cliente[], int tamClientes, eJuego juego[], int tamJuego);

#endif // ALQUILERES_H_INCLUDED


