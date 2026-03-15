//Alan Sanchez Hernandez
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int N = 1000; 
    int count_primos = 0; 
    long long suma_primos = 0; 
    int primos_pares = 0; 
    int primos_impares = 0;

    
    if (N >= 2) {
        count_primos++; 
        suma_primos += 2;
        primos_pares++;
    }

   
    for (int m = 3; m <= N; m += 2) {
        int es_primo = 1;

        int limite = (int)sqrt(m); 
        int d = 3; // Empezamos a probar desde el 3
        
        while (d <= limite) {
           
            if (m % d == 0) {
                es_primo = 0;
                break;
            }
            d += 2;
        }

        if (es_primo) {
            count_primos++; 
            suma_primos += m;
            primos_impares++;
        }
    }

    printf("Primos encontrados: %d\n", count_primos);
    printf("Suma de primos: %lld\n", suma_primos);
    printf("Primos pares: %d\n", primos_pares);
    printf("Primos impares: %d\n", primos_impares);

    return 0;
}
