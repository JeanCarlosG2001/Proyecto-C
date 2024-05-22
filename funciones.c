#include <stdio.h>
#include "funciones.h"

float calcularCostoEnvio(float peso, int cantidad) {
    return peso * cantidad * 0.10;
}

void imprimirFactura(struct Producto producto[], float precioProducto[], float interes, float iva, float costoEnvio, float total, int cantidad[], int numProductos) {
    printf("\n\nFactura:\n");
    printf("%-30s %-10s %-10s %-10s %-10s\n", "Producto", "Precio", "Peso", "Cantidad", "Subtotal");
    for (int i = 0; i < 6; i++) {
        if (cantidad[i] > 0) {
            printf("%-30s $%.2f      %.2f g    %-10d $%.2f\n", producto[i].nombre, precioProducto[i], producto[i].peso, cantidad[i], precioProducto[i] * cantidad[i]);
        }
    }
    printf("Interes: $%.2f\n", interes);
    printf("IVA: $%.2f\n", iva);
    printf("Costo de envio: $%.2f\n", costoEnvio);
    printf("Total: $%.2f\n", total);
}
