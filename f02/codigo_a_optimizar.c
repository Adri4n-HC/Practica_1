/* Nombre del archivo: c_no_opt.c
   Versión: 1.2.0
   Autor: [Juan González David]
   Fecha: 14/03/2026
   Descripción breve: Optimización extrema mediante Criba de Eratóstenes (O(N log log N)).
   Entrada esperada: Entero N.
   Salida esperada: Conteo, suma y clasificación de primos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N = 1000;
    int count_primos = 0;
    long long suma_primos = 0;
    int primos_pares = 0;
    int primos_impares = 0;

    // MOD: v1.2.0 — Uso de memoria dinámica para crear un mapa de bits/booleanos
    char *es_compuesto = (char *)calloc(N + 1, sizeof(char));

    // Bloque: Algoritmo de Criba de Eratóstenes
    for (int p = 2; p * p <= N; p++) {
        // Si p no ha sido marcado, es un primo
        if (es_compuesto[p] == 0) {
            // Marcamos todos sus múltiplos empezando desde p*p
            for (int i = p * p; i <= N; i += p)
                es_compuesto[i] = 1; // Marcado como no primo
        }
    }

    // Bloque: Conteo y clasificación final en una sola pasada lineal
    for (int i = 2; i <= N; i++) {
        if (es_compuesto[i] == 0) {
            count_primos++;
            suma_primos += i;
            if (i % 2 == 0) primos_pares++;
            else primos_impares++;
        }
    }

    printf("Primos encontrados: %d\n", count_primos);
    printf("Suma de primos: %lld\n", suma_primos);
    printf("Primos pares: %d\n", primos_pares);
    printf("Primos impares: %d\n", primos_impares);

    free(es_compuesto); // Liberar memoria
    return 0;
}
