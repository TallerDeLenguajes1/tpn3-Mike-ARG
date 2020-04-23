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
producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
};

typedef struct Cliente cliente;

//void ingresarClientes(cliente X, int N);

#define MAX 100

float calcularPrecio(producto prod);
void costoTotal (cliente client);

int main() {

    srand(time(0));

    int cantClientes;

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantClientes);
    fflush(stdin);

    cliente *p;
    p = (cliente *) malloc(sizeof(cliente) * cantClientes);

    for (int i = 0; i < cantClientes; i++) {
        p[i].ClienteID = i + 1;

        p[i].NombreCliente = (char *) malloc(sizeof(char) * MAX);
        
        printf("Ingrese el nombre del cliente %d: ", i + 1);
        scanf("%s", p[i].NombreCliente);
        fflush(stdin);

        p[i].CantidadProductosAPedir = rand() % 5 + 1;
        p[i].Productos = (producto *) malloc(sizeof(producto) * p[i].CantidadProductosAPedir);

    }
    


    for (int i = 0; i < cantClientes; i++) {
        for (int j = 0; j < p[i].CantidadProductosAPedir; j++) {
            p[i].Productos[j].ProductoID = j + 1;
            p[i].Productos[j].Cantidad = rand() % 10 + 1;
            p[i].Productos[j].PrecioUnitario = rand() % 91 + 10;
            p[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];

        }
    }

    for (int i = 0; i < cantClientes; i++) {
        printf("\n\n------------------------------------------------\n\n");
        printf("Nombre del cliente: %s\n", p[i].NombreCliente);
        printf("ID del cliente: %d\n", p[i].ClienteID);
        printf("Cantidad de productos a pedir: %d\n\n", p[i].CantidadProductosAPedir);

        costoTotal(p[i]);
        

    }




    getchar();
    free(p);
    return 0;
}


float calcularPrecio(producto prod) {
    return prod.Cantidad * prod.PrecioUnitario;
}

void costoTotal (cliente client) {
    float total = 0;

    for (int z = 0; z < client.CantidadProductosAPedir; z++) {
        printf("Producto: %s\n", client.Productos[z].TipoProducto);
        printf("ID de producto: %d\n", client.Productos[z].ProductoID);
        printf("Precio unitario: %.2f\n", client.Productos[z].PrecioUnitario);
        printf("Cantidad: %d\n", client.Productos[z].Cantidad);
        printf("Total por producto: %.2f\n\n", calcularPrecio(client.Productos[z]));

        total = total + calcularPrecio(client.Productos[z]);

    }
    printf("\n\nTOTAL A PAGAR: %.2f\n\n", total);

}
