/* Nombre del archivo: codigo_optimizado.c
   Versión: 1.2.1
   Autor: Luis Adrian Hernandez Castro
   Fecha: 14/03/2026
   Descripción: Optimización mediante Criba de Eratóstenes (O(N log log N)).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int N = 1000000; // Un millón para medir tiempo real
    int count_primos = 0;
    long long suma_primos = 0;
    int primos_pares = 0;
    int primos_impares = 0;
    int p, i, j; // Variables declaradas fuera para evitar errores

    // Iniciar medición de tiempo
    clock_t inicio = clock();

    // Uso de memoria dinámica
    char *es_compuesto = (char *)calloc(N + 1, sizeof(char));

    // Algoritmo de Criba de Eratóstenes
    for (p = 2; p * p <= N; p++) {
        if (es_compuesto[p] == 0) {
            for (i = p * p; i <= N; i += p)
                es_compuesto[i] = 1;
        }
    }

    // Conteo y clasificación
    for (j = 2; j <= N; j++) {
        if (es_compuesto[j] == 0) {
            count_primos++;
            suma_primos += j;
            if (j % 2 == 0) primos_pares++;
            else primos_impares++;
        }
    }

    // Finalizar medición
    clock_t fin = clock();
    double tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Primos encontrados: %d\n", count_primos);
    printf("Suma de primos: %lld\n", suma_primos);
    printf("Tiempo de ejecucion: %f segundos\n", tiempo_total);

    // Liberar memoria
    free(es_compuesto);
    
    // Pausa para ver el resultado
    system("pause");
    return 0;
}
