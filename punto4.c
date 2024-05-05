#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct{
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct{
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
}Cliente;

void generarProductos(Producto *Productos, int Cantidad);

void generarCliente(Cliente *cliente, int i);

void mostrarClientes(int cantClientes, Cliente **Clientes);

float totalProducto(float pun, int cantidad );
float totalPorCliente(Producto *prod, int cantProd);

int main()
{

    int cantClientes;

    printf("-Ingrese la cantidad de clientes-\n");
    scanf("%d", &cantClientes);

    Cliente **clientes = (Cliente**) malloc(sizeof(Cliente) * cantClientes);
    //Cargar el clientes
    for (int i = 0; i < cantClientes; i++)
    {
        clientes[i] = (Cliente*) malloc(sizeof(Cliente));
        generarCliente(clientes[i], i);
    }
    

    mostrarClientes(cantClientes, clientes);
    //Libero la memoria
    for (int i = 0; i < cantClientes; i++)
    {
        free(clientes[i]);
    }
    free(clientes);
    return 0;
}

void generarCliente(Cliente *cliente, int i)
{
    cliente->ClienteID = i;
    char buff[50];
    printf("Ingrese el nombre del cliente:\n");
    if (i == 0)
    {
        getchar(); // No se porque pero me lee solo 1 caracter en la primera iteracion y saltea el fgets. Si no uso el if me come 1 caracter a partir de la segunda iteracion.
    }
    fgets(buff, 49, stdin);
    cliente->NombreCliente = malloc(sizeof(char) * (strlen(buff) + 1) );
    strcpy(cliente->NombreCliente, buff);
    cliente->CantidadProductosAPedir = 1 + rand() % 5;
    cliente->Productos = (Producto *)malloc(sizeof(Producto) * cliente->CantidadProductosAPedir);
    for (int j = 0; j < cliente->CantidadProductosAPedir; j++)
    {
        generarProductos(&cliente->Productos[j], j);
    }
}

void generarProductos(Producto *Productos, int j)
{
    
        Productos->ProductoID = j; // genero id
        // Genero el tipo de producto
        int randomTipoProducto = rand() % 5;// Genero un numero aleatorio del 1 al 5 para que el elemento que reservo el espacio y luego copio sea el mismo.
        Productos->TipoProducto = (char *) malloc(sizeof(char) * strlen(TiposProductos[randomTipoProducto])); // Reservo el espacio para 1 elemento
        strcpy(Productos->TipoProducto, TiposProductos[randomTipoProducto]);
        // Genero PU y cantidad del pedido.
        Productos->PrecioUnitario = 10 + rand() % 91;
        Productos->Cantidad = 1 + rand() % 10;
}

float totalProducto(float pun, int cantidad)
{
    return pun * cantidad;
}

float totalPorCliente(Producto *prod, int cantProd)
{
    float total = 0;
    for (int i = 0; i < cantProd; i++)
    {
        total = totalProducto(prod[i].PrecioUnitario, prod[i].Cantidad) + total;
    }
    
    return total;
}

void mostrarClientes(int cantClientes, Cliente **Clientes)
{
    for (int i = 0; i < cantClientes; i++)
    {
        printf("\n-----------------------------------------------------------------------------\n");
        printf("CLiente:");
        puts(Clientes[i]->NombreCliente);
        printf("ID del cliente: %d\n", Clientes[i]->ClienteID);
        printf("Cantidad de productos: %d\n", Clientes[i]->CantidadProductosAPedir);
        for (int j = 0; j < Clientes[i]->CantidadProductosAPedir; j++)
        {
            printf("    ---------   \n");
            printf("    Producto:");
            puts(Clientes[i]->Productos[j].TipoProducto);
            printf("    Id del Producto: %d\n", Clientes[i]->Productos[j].ProductoID);
            printf("    Precio unitario: %.2f\n", Clientes[i]->Productos[j].PrecioUnitario);
            printf("    Cantidad: %d\n", Clientes[i]->Productos[j].Cantidad);
            printf("    Precio Total: %.2f\n", totalProducto(Clientes[i]->Productos[j].PrecioUnitario,Clientes[i]->Productos[j].Cantidad));
            printf("    ---------   \n");
        }
        printf("TOTAL A PAGAR CLIENTE %s: %.2f\n", Clientes[i]->NombreCliente, totalPorCliente(Clientes[i]->Productos, Clientes[i]->CantidadProductosAPedir));
        printf("\n-----------------------------------------------------------------------------\n");
    }
}