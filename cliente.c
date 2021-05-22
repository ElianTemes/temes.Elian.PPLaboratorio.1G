#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "funciones.h"

#define TAM 5
#define TAMN 51
#define TEL 21
#define TRUE 1
#define FALSE 0

/** \brief incializa el array de clientes
 *
 * \param eCliente cliente
 * \param int tam
 * \return 0 si todo ok, -1 si fallo
 *
 */
int initCliente(eCliente cliente[], int tam){
    int posicion;
    if(cliente != NULL && tam > 0){
        for(posicion = 0; posicion < tam; posicion++){
            cliente[posicion].isEmpty = TRUE;
        }
        return 0;
    }
    return -1;
}

/** \brief Busca el primer indice libre del array
 *
 * \param eCliente cliente
 * \param int tam
 * \return primera posicion libre o -1 si hubo un error
 *
 */
int indexLibreCliente(eCliente cliente[], int tam){
    int posicion;
    if(cliente != NULL && tam > 0){
        for(posicion = 0; posicion < tam; posicion++){
            if(cliente[posicion].isEmpty == TRUE){
                return posicion;
            }
        }
    }
    return -1;
}

/** \brief busca un cliente por medio de su codigo
 *
 * \param eCliente cliente
 * \param int tam
 * \return la posicion del cliente o -1 si fallo
 *
 */
int clientePorCodigo(eCliente cliente[], int tam){
    if(cliente != NULL && tam > 0){
        int posicion;
        int validacion;
        int codigo;
        int flagCli = 0;
        printf("Ingrese el codigo del cliente: ");
        getInt(&codigo);
        while(flagCli == 0){
            for(validacion = 0; validacion < tam && flagCli == 0; validacion++){
                if(codigo >= 100 && codigo <= 104){
                    flagCli = 1;
                }
            }
            if(flagCli == 0){
                printf("\nError ingrese el codigo de cliente nuevamente: ");
                getInt(&codigo);
            }
        }
        for(posicion = 0; posicion < tam; posicion++){
            if(cliente[posicion].codigo == codigo){
                return posicion;
            }
        }
    }
    return -1;
}

/** \brief da de alta un cliente
 * \param eCliente cliente
 * \param int tam
 * \return 0 si todo ok, -1 si hubo un error
 */
int altaCliente(eCliente cliente[], int tam, int* codigoCli){
    int index = indexLibreCliente(cliente, tam);
    if(cliente != NULL && tam > 0){
        printf("\nIngrese nombre: ");
        myGets(cliente[index].nombre, TAMN);
        printf("\nIngrese apellido: ");
        myGets(cliente[index].apellido, TAMN);
        printf("\nIngrese sexo: ");
        scanf(" %c", &cliente[index].sexo);
        cliente[index].sexo = tolower(cliente[index].sexo);
        while(cliente[index].sexo != 'f' && cliente[index].sexo != 'm' && cliente[index].sexo != 'n'){
            printf("\nError ingrese un sexo correcto: ");
            scanf(" %c", &cliente[index].sexo);
            cliente[index].sexo = tolower(cliente[index].sexo);
        }
        printf("\nIngrese telefono: ");
        myGets(cliente[index].telefono, TEL);
        printf("\nIngrese la localidad del cliente: ");
        printf("\n1) Avellaneda");
        printf("\n2) Quilmes");
        printf("\n3) Lanus");
        printf("\n4) CABA");
        printf("\n5) Tigre\n");
        getInt(&cliente[index].idLocalidad);
        while(cliente[index].idLocalidad < 1 || cliente[index].idLocalidad > 5){
            printf("\nIngrese una localidad correcta! * numerica * ");
            printf("\n1) Avellaneda");
            printf("\n2) Quilmes");
            printf("\n3) Lanus");
            printf("\n4) CABA");
            printf("\n5) Tigre\n");
            getInt(&cliente[index].idLocalidad);
        }
        cliente[index].codigo = (*codigoCli)++;
        cliente[index].isEmpty = FALSE;
        return 0;
    }

return -1;
}

/** \brief modifica un cliente en base a su codigo
 * \param eCliente cliente
 * \param int tam
 * \return 0 si funciono, -1 si fallo
 */
int modCliente(eCliente cliente[], int tam){
    int index = clientePorCodigo(cliente, tam);
    if(cliente != NULL && tam > 0 && cliente[index].isEmpty == FALSE){
        int opt;
        printf("Ingrese la opcion deseada.\n 1) Nombre\n 2) Apellido\n 3) Telefono\n");
        getInt(&opt);
        switch(opt){

        case 1:
            myGets(cliente[index].nombre, TAMN);
        break;

        case 2:
            myGets(cliente[index].apellido, TAMN);
        break;

        case 3:
            myGets(cliente[index].telefono, TEL);
        break;

        return 0;
        }
    }
    return -1;
}

/** \brief da de baja al cliente en base a su codigo
 *
 * \param eCliente cliente
 * \param int tam
 * \return 0 si todo ok, -1 si fallo
 *
 */

/** \brief ordena a los clientes por nombre y apellido de mayor a menor
 * \param eCliente cliente
 * \param int tam
 * \return 0 si todo ok, -1 si fallo
 */
int ordenarClientes(eCliente cliente[], int tam ){
    if(cliente != NULL && tam > 0){
        eCliente auxCliente;
        int primero;
        int siguiente;
        int nombre;
        int apellido;
        for(primero = 0; primero < tam - 1; primero++){

            for(siguiente = primero + 1; siguiente < tam; siguiente++){
                nombre = strcmp(cliente[primero].nombre, cliente[siguiente].nombre);
                apellido = strcmp(cliente[primero].apellido, cliente[siguiente].apellido);
                if( (nombre < 0 && cliente[primero].isEmpty == FALSE && cliente[siguiente].isEmpty == FALSE) || (nombre == 0 && apellido < 0)){
                    auxCliente = cliente[siguiente];
                    cliente[siguiente] = cliente[primero];
                    cliente[primero] = auxCliente;
                }
            }
        }
        return 0;
    }
return -1;
}

/** \brief muestra a los clientes en pantalla
 * \param eCliente cliente
 * \param int tam
 * \return 0 si todo ok, -1 si fallo
 */
int mostrarClientes(eCliente cliente[], int tam, eLocalidad loc[], int tamLoc){
    int posicion;
    char nombreCompleto[101];
    int index;
    if(cliente != NULL && tam > 0) {
        printf("////CODIGO \t   NOMBRE COMPLETO \t   SEXO \t   TELEFONO \t LOCALIDAD////");
        for(posicion = 0; posicion < tam; posicion++){
            if(cliente[posicion].isEmpty == FALSE){
                nombreCompleto[0] = '\0';
                strcat(nombreCompleto, cliente[posicion].nombre);
                strcat(nombreCompleto, " " );
                strcat(nombreCompleto, cliente[posicion].apellido);
                index = indiceLoc(loc, cliente[posicion].idLocalidad);
                printf("\n  %5d   \t     %s \t     %c \t          %s \t    %s",
                cliente[posicion].codigo, nombreCompleto, cliente[posicion].sexo, cliente[posicion].telefono, loc[index].descripcion);
            }
        }
        return 0;
    }
    return -1;
}

int clienteLocalidad(eCliente cliente[], int tamCliente){
    int locIng;
    char nombreCompleto[101];
    int posicion;
    if (cliente != NULL && tamCliente > 0){
        printf("\nIngrese la localidad para ver a los clientes que viven en ellas: \n ");
        printf("\n1) Avellaneda");
        printf("\n2) Quilmes");
        printf("\n3) Lanus");
        printf("\n4) CABA");
        printf("\n5) Tigre\n");
        getInt(&locIng);
        while(locIng < 1 || locIng > 5){
            printf("\nIngrese una localidad correcta! * numerica * ");
            printf("\n1) Avellaneda");
            printf("\n2) Quilmes");
            printf("\n3) Lanus");
            printf("\n4) CABA");
            printf("\n5) Tigre\n");
            getInt(&locIng);
        }
        for(posicion = 0; posicion < tamCliente; posicion++){
            if(cliente[posicion].idLocalidad == locIng){
                nombreCompleto[0] = '\0';
                strcat(nombreCompleto, cliente[posicion].nombre);
                strcat(nombreCompleto, " " );
                strcat(nombreCompleto, cliente[posicion].apellido);
                printf("\n/////CLIENTES DE LA LOCALIDAD//////");
                printf("\n \t    %s", nombreCompleto);
            }
        }
    return 1;
    }
return 0;
}

int ordenarClientesLoc(eCliente cliente[], int tamCli, eLocalidad loc[], int tamLoc ){
    eCliente auxCli;
    if(cliente != NULL && tamCli > 0 && loc != NULL && tamLoc > 0){
        int primero;
        int siguiente;
        int localidad;
        for(primero = 0; primero < tamLoc - 1; primero++){

            for(siguiente = primero + 1; siguiente < tamLoc; siguiente++){
                localidad = strcmp(loc[primero].descripcion, loc[siguiente].descripcion);
                if(localidad < 0 && cliente[primero].isEmpty == FALSE){
                    auxCli = cliente[siguiente];
                    cliente[siguiente] = cliente[primero];
                    cliente[primero] = auxCli;
                }
            }
        }
        return 0;
    }
return -1;
}
