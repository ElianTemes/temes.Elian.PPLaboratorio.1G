#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "localidad.h"

#define TAM 5
#define TAMN 51
#define TEL 21
#define TRUE 1
#define FALSE 0

typedef struct{
    int codigo;
    char nombre[TAMN];
    char apellido[TAMN];
    char sexo;
    char telefono[TEL];
    int idLocalidad;
    int isEmpty;
}eCliente;

int initCliente(eCliente cliente[], int tam);
int indexLibreCliente(eCliente cliente[], int tam);
int clientePorCodigo(eCliente cliente[], int tam);
int altaCliente(eCliente cliente[], int tam, int* codigoCli);
int modCliente(eCliente cliente[], int tam);
int ordenarClientes(eCliente cliente[], int tam);
int mostrarClientes(eCliente cliente[], int tam, eLocalidad loc[], int tamLoc);
int clienteLocalidad(eCliente cliente[], int tamCliente);
int ordenarClientesLoc(eCliente cliente[], int tamCli, eLocalidad loc[], int tamLoc );

#endif // CLIENTE_H_INCLUDED


