#include <stdio.h>
#include "funciones.h"
//Definición
#define IVA 0.15
#define INTERES 5.0 

int main() {
    //Productos Vectores
    struct Producto productos[6] = {
        {"Laptop", 1000, 2500},
        {"Telefono inteligente", 800, 200},
        {"Tableta", 500, 300},
        {"Camara digital", 600, 150},
        {"Auriculares inalambricos", 200, 50},
        {"Smartwatch", 300, 100}
    };

    int cantidad[6] = {0}; // Inicializar el arreglo de cantidades
    float precioProducto[6] = {0}; // Inicializar el arreglo de precios
    int numProductos = 0; // Contador de productos seleccionados

    // Mostrar el menú
    printf("\nMenu de Productos Exportados de Tecnologia:\n");
    printf("%-2s %-30s %-10s %-10s\n", "No", "Producto", "Precio", "Peso");
    for (int i = 0; i < 6; i++) {
        printf("%-2d %-30s $%.2f      %.2f g\n", i + 1, productos[i].nombre, productos[i].precio, productos[i].peso);
    }

    while (1) {
        // Leer la opción del usuario
        printf("Seleccione el producto que desea comprar (1-6), o 0 para terminar: ");
        int indiceProducto;
        scanf("%d", &indiceProducto);

        // Si el usuario ingresa 0, salir del bucle
        if (indiceProducto == 0) {
            break;
        }
        // Validar la opción ingresada
        if (indiceProducto < 1 || indiceProducto > 6) {
            printf("Opción inválida. Por favor, seleccione una opción válida.\n");
            continue;
        }
        // Obtener el índice del producto seleccionado
        indiceProducto--;
        // Leer la cantidad de productos por unidad
        printf("Ingrese la cantidad de productos que desea comprar: ");
        int cantidadProducto;
        scanf("%d", &cantidadProducto);
        // Validar cantidad positiva
        if (cantidadProducto <= 0) {
            printf("Cantidad invalida. Por favor, ingrese una cantidad positiva.\n");
            continue;
        }

        // Actualizar la cantidad del producto seleccionado
        cantidad[indiceProducto] += cantidadProducto;
        // Actualizar el precio del producto seleccionado
        precioProducto[indiceProducto] = productos[indiceProducto].precio;
        // Incrementar el contador de productos solo si es la primera vez que se selecciona
        if (cantidad[indiceProducto] == cantidadProducto) {
            numProductos++;
        }
    }

    // Calcular el subtotal de los productos seleccionados
    float subtotal = 0;
    for (int i = 0; i < 6; i++) {
        if (cantidad[i] > 0) {
            subtotal += precioProducto[i] * cantidad[i];
        }
    }

    // Calcula el interés del subtotal
    float interes = subtotal * (INTERES / 100);
    // Calcula el IVA del subtotal
    float iva = subtotal * IVA;
    // Calcula el costo de envío
    float costoEnvio = 0;
    for (int i = 0; i < 6; i++) {
        if (cantidad[i] > 0) {
            costoEnvio += calcularCostoEnvio(productos[i].peso, cantidad[i]);
        }
    }
    // Calcular el total
    float total = subtotal + interes + iva + costoEnvio;
    // Imprimir la factura
    imprimirFactura(productos, precioProducto, interes, iva, costoEnvio, total, cantidad, numProductos);

    printf("Gracias por su compra.\n");

    return 0;
}
