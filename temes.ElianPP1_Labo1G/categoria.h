#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

#define TAM 5
#define TAMN 51
#define TEL 21
#define TRUE 1
#define FALSE 0

typedef struct{
    int idCat;
    char descripcion[TAMN];
}eCategoria;


#endif // CATEGORIA_H_INCLUDED

int hardcodearCat(eCategoria cat[]);

