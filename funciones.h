
struct Producto {
    char nombre[50];
    float precio;
    float peso;
};

float calcularCostoEnvio(float peso, int cantidad);
void imprimirFactura(struct Producto producto[], float precioProducto[], float interes, float iva, float costoEnvio, float total, int cantidad[], int numProductos);
