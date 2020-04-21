#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
};


typedef struct Producto producto;

struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
};

typedef struct Cliente cliente;

//void ingresarClientes(cliente X, int N);

#define MAX 100

int main() {

    srand(time(0));

    int cantClientes;

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantClientes);
    fflush(stdin);

    cliente *p;
    p = (cliente *) malloc(sizeof(cliente) * cantClientes);

    (*p).NombreCliente = (char *) malloc(sizeof(char) * MAX);

    for (int i = 0; i < cantClientes; i++) {
        (*p).ClienteID = i;
        
        printf("Ingrese el nombre del cliente: ");
        scanf("%s", (*p).NombreCliente);
        fflush(stdin);

        (*p).CantidadProductosAPedir = rand() % 5 + 1;
        (*p).Productos = (producto *) malloc(sizeof(producto) * (*p).CantidadProductosAPedir);

    }





    free(p);
    getchar();
    return 0;
}

/*void ingresarClientes(cliente *X, int N) {
    cliente aux = *X;

    for (int i = 0; i < N; i++) {
        (*(X + i)).ClienteID = 0;

        printf("Ingrese el nombre del cliente: ");
        scanf("%s", (*(X + i)).NombreCliente);
        fflush(stdin);

        (*(X + i)).CantidadProductosAPedir = rand() % 5 + 1;

        (*(X + i)).Productos = (producto *) malloc(sizeof(producto) * (*(X + i)).CantidadProductosAPedir);

        for (int j = 0; j < (*(X + i)).CantidadProductosAPedir; j++) {
            (*(X + i)).Productos
        }


    }
}
*/