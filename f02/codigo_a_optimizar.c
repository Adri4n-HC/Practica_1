/*Versión: 1.2.2
   Autor: Luis Daniel Zavala Cervantes
   Fecha: 14/03/2026
   Descripción breve: Implementación de la Criba de Eratóstenes para eliminar divisiones.
   Entrada esperada: Entero N (ej. 1000).
   Salida esperada: Estadísticas de primos con complejidad (N log N).
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N = 1000; // Límite de búsqueda
    int count_primos = 0;
    long long suma_primos = 0;
    int primos_pares = 0;
    int primos_impares = 0;

    /* MOD: v1.2.0 — Asignación de memoria dinámica para el mapa de la criba */
    // Usamos calloc para inicializar todo el array en 0 (asumimos todos primos inicialmente)
    char *es_compuesto = (char *)calloc(N + 1, sizeof(char));

    /* Bloque: Algoritmo de Criba de Eratóstenes */
    // Eliminamos el 0 y 1 manualmente
    if (N >= 0) es_compuesto[0] = 1;
    if (N >= 1) es_compuesto[1] = 1;

    // Marcamos los múltiplos de cada número p empezando desde su cuadrado
    for (int p = 2; p * p <= N; p++) {
        if (es_compuesto[p] == 0) {
            // MOD: v1.2.0 — Marcado masivo de múltiplos: i += p evita divisiones y módulos
            for (int i = p * p; i <= N; i += p) {
                es_compuesto[i] = 1;
            }
        }
    }

    /* Bloque: Recolección de resultados en una sola pasada lineal O(N) */
    for (int i = 2; i <= N; i++) {
        if (es_compuesto[i] == 0) {
            count_primos++;
            suma_primos += i;
            // Clasificación par/impar
            if (i % 2 == 0) primos_pares++;
            else primos_impares++;
        }
    }

    /* Impresión de resultados */
    printf("Primos encontrados: %d\n", count_primos);
    printf("Suma de primos: %lld\n", suma_primos);
    printf("Primos pares: %d\n", primos_pares);
    printf("Primos impares: %d\n", primos_impares);

    /* MOD: v1.2.0 — Liberación de memoria para evitar fugas (memory leaks) */
    free(es_compuesto);

    return 0;
}
