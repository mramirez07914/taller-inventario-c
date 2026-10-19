
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 50

// FUNCION PARA INGRESAR PRODUCTOS
int ingresarProductos(char nombres[][MAX_NOMBRE], float precios[])
{
    int cantidad;
    int i;
    int valido;
    int caracter;

    do
    {
        printf("Ingrese la cantidad de productos (1-10): ");
        valido = scanf("%d", &cantidad);

        if (valido != 1)
        {
            while ((caracter = getchar()) != '\n' && caracter != EOF)
            {
            }

            printf("Error: ingrese un numero entero.\n");
            cantidad = 0;
        }
        else if (cantidad < 1 || cantidad > 10)
        {
            printf("Error: la cantidad debe estar entre 1 y 10.\n");
        }

    } while (cantidad < 1 || cantidad > 10);

    for (i = 0; i < cantidad; i++)
    {
        printf("\n--- PRODUCTO %d ---\n", i + 1);

        printf("Ingrese el nombre: ");
        scanf(" %49[^\n]", nombres[i]);

        do
        {
            printf("Ingrese el precio: ");
            valido = scanf("%f", &precios[i]);

            if (valido != 1)
            {
                while ((caracter = getchar()) != '\n' && caracter != EOF)
                {
                }

                printf("Error: ingrese un precio numerico.\n");
                precios[i] = -1;
            }
            else if (precios[i] < 0)
            {
                printf("Error: el precio no puede ser negativo.\n");
            }

        } while (precios[i] < 0);
    }

    return cantidad;
}

// FUNCION PARA CALCULAR EL TOTAL
float calcularTotal(float precios[], int cantidad)
{
    float total = 0;
    int i;

    for (i = 0; i < cantidad; i++)
    {
        total = total + precios[i];
    }

    return total;
}

// FUNCION PARA CALCULAR EL PROMEDIO
float calcularPromedio(float precios[], int cantidad)
{
    float total;

    total = calcularTotal(precios, cantidad);

    return total / cantidad;
}

// FUNCION PARA ENCONTRAR EL PRODUCTO MAS CARO
void productoMasCaro(char nombres[][MAX_NOMBRE],
                     float precios[], int cantidad)
{
    int i;
    int posicion = 0;

    for (i = 1; i < cantidad; i++)
    {
        if (precios[i] > precios[posicion])
        {
            posicion = i;
        }
    }

    printf("\nProducto mas caro: %s\n", nombres[posicion]);
    printf("Precio: $%.2f\n", precios[posicion]);
}

// FUNCION PARA ENCONTRAR EL PRODUCTO MAS BARATO
void productoMasBarato(char nombres[][MAX_NOMBRE],
                       float precios[], int cantidad)
{
    int i;
    int posicion = 0;

    for (i = 1; i < cantidad; i++)
    {
        if (precios[i] < precios[posicion])
        {
            posicion = i;
        }
    }

    printf("\nProducto mas barato: %s\n", nombres[posicion]);
    printf("Precio: $%.2f\n", precios[posicion]);
}

// FUNCION PARA BUSCAR UN PRODUCTO
void buscarProducto(char nombres[][MAX_NOMBRE],
                    float precios[], int cantidad)
{
    char buscado[MAX_NOMBRE];
    int i;
    int encontrado = 0;

    printf("\nIngrese el nombre del producto a buscar: ");
    scanf(" %49[^\n]", buscado);

    for (i = 0; i < cantidad; i++)
    {
        if (strcmp(nombres[i], buscado) == 0)
        {
            printf("Producto encontrado: %s\n", nombres[i]);
            printf("Precio: $%.2f\n", precios[i]);
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0)
    {
        printf("El producto no se encuentra en el inventario.\n");
    }
}

// PROGRAMA PRINCIPAL
int main()
{
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    int cantidad;

    printf("=================================\n");
    printf("    SISTEMA DE INVENTARIO\n");
    printf("=================================\n");

    cantidad = ingresarProductos(nombres, precios);

    printf("\n=== LISTA DE PRODUCTOS ===\n");

    for (int i = 0; i < cantidad; i++)
    {
        printf("%d. %s - $%.2f\n",
               i + 1, nombres[i], precios[i]);
    }

    printf("\n=== RESULTADOS DEL INVENTARIO ===\n");

    printf("Precio total: $%.2f\n",
           calcularTotal(precios, cantidad));

    printf("Precio promedio: $%.2f\n",
           calcularPromedio(precios, cantidad));

    productoMasCaro(nombres, precios, cantidad);

    productoMasBarato(nombres, precios, cantidad);

    printf("\n=== BUSQUEDA DE PRODUCTOS ===\n");

    buscarProducto(nombres, precios, cantidad);

    printf("\n=== FIN DEL PROGRAMA ===\n");

    return 0;
}