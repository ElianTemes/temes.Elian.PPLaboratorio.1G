#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquileres.h"

#define TAM 5
#define TAMN 51
#define TEL 21
#define TRUE 1
#define FALSE 0


/** \brief incializa el arrya de alquileres
 *
 * \param eAlquileres alquileres
 * \param int tam
 * \return 0 si todo ok, -1 si fallo
 *
 */
int initAlquileres(eAlquileres alquiler[], int tam){
    int posicion;
    if(alquiler != NULL && tam > 0){
        for(posicion = 0; posicion < tam; posicion++){
            alquiler[posicion].isEmpty = TRUE;
        }
        return 0;
    }
    return -1;
}

/** \brief Busca el primer indice libre del array
 *
 * \param eAlquileres alquiler
 * \param int tam
 * \return primera posicion libre o -1 si hubo un error
 *
 */
int indexLibreAlquiler(eAlquileres alquiler[], int tam){
    int posicion;
    if(alquiler != NULL && tam > 0){
        for(posicion = 0; posicion < tam; posicion++){
            if(alquiler[posicion].isEmpty == TRUE){
                return posicion;
            }
        }
    }
    return -1;
}

int chequeoArray(eAlquileres alquileres[], int tamAlq, eJuego juegos[], int tamJuego, eCliente clientes[], int tamClientes, eFecha fechas[], int tamFechas){
    if( ( alquileres != NULL && tamAlq > 0 ) && ( juegos != NULL && tamJuego > 0 ) && ( clientes != NULL && tamClientes > 0 ) && ( fechas != NULL && tamFechas > 0 ) ){
        return 1;
    }
return -1;
}

int altaAlquiler(eAlquileres alquileres[], int tamAlquiler, int* codigoAlq, eJuego juegos[], int tamJuego, eCliente clientes[], int tamClientes, eFecha fechas[], int tamFechas, eLocalidad loc[], int tamLoc){
    int index = indexLibreAlquiler(alquileres, tamAlquiler);
    int posicion;
    int flagCli = 0;
    int flagJue = 0;
    if(chequeoArray(alquileres, tamAlquiler, juegos, tamJuego, clientes, tamClientes, fechas, tamFechas) != -1){
        if(index != -1){
                alquileres[index].codigoAlq = (*codigoAlq)++;
                mostrarJuego(juegos);
                printf("\nIngrese el codigo del juego: ");
                getInt(&alquileres[index].codigoJuego);
                while(flagJue == 0){
                        for(posicion = 0; posicion < tamJuego && flagJue == 0; posicion++){
                            if(alquileres[index].codigoJuego >= 1 && alquileres[index].codigoJuego <= 5){
                                flagJue = 1;
                            }
                        }
                    if(flagJue == 0){
                        printf("\nError ingrese el codigo de juego nuevamente: ");
                        getInt(&alquileres[index].codigoJuego);
                    }
                }
                mostrarClientes(clientes, tamClientes, loc, tamLoc);
                printf("\nIngrese el codigo del cliente: ");
                getInt(&alquileres[index].codigoCliente);
                while(flagCli == 0){
                        for(posicion = 0; posicion < tamClientes && flagCli == 0; posicion++){
                            if(clientes[posicion].codigo == alquileres[index].codigoCliente){
                                flagCli = 1;
                            }
                        }
                    if(flagCli == 0){
                        printf("\nError ingrese el codigo de cliente nuevamente: ");
                        getInt(&alquileres[index].codigoCliente);
                    }
                }
                printf("\nIngrese la fecha: (DD/MM/AA) ");
                scanf("%d/%d/%d", &alquileres[index].fecha.dia, &alquileres[index].fecha.mes, &alquileres[index].fecha.anio);
                alquileres[index].isEmpty = FALSE;
                return 0;
        }
    }
return -1;
}

int mostrarAlquileres(eAlquileres alquileres[], int tamAlquiler, eCliente cliente[], int tamClientes, eJuego juego[], int tamJuego ,eCategoria cat[], int tamCat, eLocalidad loc[], int tamLoc){
    int i;
    int j;
    int indice;
    int index;
    if(alquileres != NULL && tamAlquiler > 0) {
        printf("////CODIGO ALQUILER\tJUEGO\t\tIMPORTE\t\tCATEGORIA\tFECHA\tCODIGO CLIENTE\tNOMBRE CLIENTE\tLOCALIDAD////\n");
        for(i = 0; i < tamAlquiler; i++){
            if(alquileres[i].isEmpty == FALSE){
                for(j = 0; j < tamClientes; j++){
                    if(cliente[j].isEmpty == FALSE && alquileres[i].codigoCliente == cliente[j].codigo){
                    indice = buscarJuegoId(juego, alquileres[i].codigoJuego);
                    index = indiceLoc(loc, cliente[j].idLocalidad);
                    printf(" \t %3d       \t%8s      \t%4d       %10s      %2d/%2d/%4d        %3d     %s  %s \t %s\n",
                        alquileres[i].codigoAlq, juego[indice].descripcion, juego[indice].importe, cat[indice].descripcion ,alquileres[i].fecha.dia, alquileres[i].fecha.mes, alquileres[i].fecha.anio, alquileres[i].codigoCliente,
                         cliente[j].nombre, cliente[j].apellido, loc[index].descripcion);
                    }
                }
            }
        }
        return 0;
    }
return -1;
}

int bajaCliente(eCliente cliente[], int tamCli, eAlquileres alquiler[], int tamAlq){
    int index = clientePorCodigo(cliente, tamCli);
    int posicion;
    if(cliente != NULL && tamCli > 0 && cliente[index].isEmpty == FALSE){
        cliente[index].isEmpty = TRUE;
        for(posicion = 0; posicion < tamAlq; posicion++){
            if(alquiler != NULL && tamAlq > 0 && alquiler[posicion].isEmpty == FALSE && alquiler[posicion].codigoCliente == cliente[index].codigo){
                alquiler[posicion].isEmpty = TRUE;
            }
        }
        return 0;
    }
    return -1;
}

int mostrarAlqCliente(eAlquileres alquileres[], int tamAlquiler, eCliente cliente[], int tamClientes, eJuego juego[], int tamJuego ,eCategoria cat[], int tamCat, eLocalidad loc[], int tamLoc){
    int indice;
    int index;
    int cli;
    int i;
    if(alquileres != NULL && tamAlquiler > 0){
        cli = clientePorCodigo(cliente, tamClientes);
        printf("////CODIGO ALQUILER\tJUEGO\t\tIMPORTE\t\tCATEGORIA\tFECHA\tCODIGO CLIENTE\tNOMBRE CLIENTE\tLOCALIDAD////\n");
        for(i = 0; i < tamAlquiler; i++){
            if(alquileres[i].codigoCliente == cliente[cli].codigo){
                if(cliente[cli].isEmpty == FALSE){
                    indice = buscarJuegoId(juego, alquileres[i].codigoJuego);
                    index = indiceLoc(loc, cliente[cli].idLocalidad);
                    printf(" \t %3d       \t%8s      \t%4d       %10s      %2d/%2d/%4d        %3d       %s  %s \t %s\n",
                    alquileres[i].codigoAlq, juego[indice].descripcion, juego[indice].importe, cat[indice].descripcion ,alquileres[i].fecha.dia, alquileres[i].fecha.mes, alquileres[i].fecha.anio, alquileres[i].codigoCliente,
                    cliente[cli].nombre, cliente[cli].apellido, loc[index].descripcion);
                }
            }
        }
        return 1;
    }
return -1;
}

int mostrarImporteCliente(eAlquileres alquileres[], int tamAlquiler, eCliente cliente[], int tamClientes, eJuego juego[], int tamJuego){
    int indice;
    int cli;
    int i;
    int acumImp = 0;
    if(alquileres != NULL && tamAlquiler > 0){
        cli = clientePorCodigo(cliente, tamClientes);
        for(i = 0; i < tamAlquiler; i++){
            if(alquileres[i].codigoCliente == cliente[cli].codigo){
                if(cliente[cli].isEmpty == FALSE){
                    indice = buscarJuegoId(juego, alquileres[i].codigoJuego);
                    acumImp += juego[indice].importe;
                }
            }
        }
        printf("Gasto acumulado del cliente %s: %d", cliente[cli].nombre, acumImp);
        return 1;
    }
return -1;
}
