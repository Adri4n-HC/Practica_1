/* Archivo: c_no_opt.c
   Versión: 1.1.0
   Autor: [Maroto May Alejandro]
   Fecha: 13-03-2026
   Descripción: Cálculo optimizado de números primos hasta N, sumatoria y clasificación.
   Entrada: Entero N (límite).
   Salida: Conteo total, suma acumulada, cantidad de primos pares e impares.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Necesario para sqrt()

int main() {
    int N = 1000; 
    int count_primos = 0;
    long long suma_primos = 0;
    int primos_pares = 0;
    int primos_impares = 0;

    // Itera desde 2 hasta N para evaluar candidatos a primos
    for (int m = 2; m <= N; m++) {
        int es_primo = 1; 

        /* MOD: v1.1.0 — Optimización de búsqueda de divisores hasta raíz cuadrada y uso de break */
        // Si el número es par y mayor a 2, no es primo (ahorra iteraciones)
        if (m > 2 && m % 2 == 0) {
            es_primo = 0;
        } else {
            // Solo probamos divisores hasta la raíz cuadrada de m
            int limite = (int)sqrt(m);
            for (int d = 3; d <= limite; d += 2) {
                if (m % d == 0) {
                    es_primo = 0;
                    break; // MOD: v1.1.0 — Salida temprana al hallar un divisor
                }
            }
        }

        // Si es_primo sigue siendo 1, actualizamos estadísticas
        if (es_primo) {
            count_primos++;           // Incrementa contador total
            suma_primos += m;        // Acumula el valor del primo
            
            // Clasificación par/impar
            if (m % 2 == 0) {
                primos_pares++;      // Únicamente para el número 2
            } else {
                primos_impares++;    // Para el resto de los primos
            }
        }
    }

    printf("Primos encontrados: %d\n", count_primos);
    printf("Suma de primos: %lld\n", suma_primos);
    printf("Primos pares: %d\n", primos_pares);
    printf("Primos impares: %d\n", primos_impares);

    return 0;
}
