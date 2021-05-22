#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "categoria.h"
#include "funciones.h"


#define TAM 5
#define TAMN 51
#define TEL 21
#define TRUE 1
#define FALSE 0

int idH[TAM] = {10, 11, 12, 13, 14};
char descripcionCH[TAM][TAMN] = {"estrategia", "mental", "cartas", "precision", "mesa"};

/** \brief hardcodea la estructura categoria
 * \param eCategoria cat
 * \return 0 si no hubo error, -1 si lo hubo
 */
int hardcodearCat(eCategoria cat[]){
    int posicion;
    if(cat != NULL){
        for(posicion = 0; posicion < TAM; posicion++){
            cat[posicion].idCat = idH[posicion];
            strcpy(cat[posicion].descripcion, descripcionCH[posicion]);
        }
        return 0;
    }
    return -1;
}

void mostrarCat(eCategoria cat[]){
     printf("/////ID CATEGORIA     \t     DESCRIPCION/////");
    for(int posicion = 0; posicion < TAM; posicion ++){
        printf("%d      \t      %s", cat[posicion].idCat, cat[posicion].descripcion);
    }

}
