#include <stdio.h>

// Tasas de cambio (pueden cambiarse según el valor actual)
#define GTQ_TO_USD 0.13
#define GTQ_TO_EUR 0.12
#define USD_TO_GTQ 7.80
#define USD_TO_EUR 0.92
#define EUR_TO_GTQ 8.50
#define EUR_TO_USD 1.09

// Función para convertir moneda
double convertir(double cantidad, char origen, char destino) {
    if (origen == destino) {
        return cantidad; // Si es la misma moneda, no se convierte
    }

    if (origen == 'Q' && destino == 'U') return cantidad * GTQ_TO_USD;
    if (origen == 'Q' && destino == 'E') return cantidad * GTQ_TO_EUR;
    if (origen == 'U' && destino == 'Q') return cantidad * USD_TO_GTQ;
    if (origen == 'U' && destino == 'E') return cantidad * USD_TO_EUR;
    if (origen == 'E' && destino == 'Q') return cantidad * EUR_TO_GTQ;
    if (origen == 'E' && destino == 'U') return cantidad * EUR_TO_USD;

    return -1; // Caso inválido
}

int main() {
    double cantidad, resultado;
    char origen, destino;

    printf("Conversor de moneda (Q = Quetzal, U = Dólar, E = Euro)\n");
    printf("Ingrese la cantidad a convertir: ");
    scanf("%lf", &cantidad);
    
    printf("Ingrese la moneda de origen (Q/U/E): ");
    scanf(" %c", &origen);
    
    printf("Ingrese la moneda de destino (Q/U/E): ");
    scanf(" %c", &destino);

    resultado = convertir(cantidad, origen, destino);
    
    if (resultado != -1) {
        printf("Resultado: %.2f %c\n", resultado, destino);
    } else {
        printf("Error: Moneda no válida\n");
    }

    return 0;
}
