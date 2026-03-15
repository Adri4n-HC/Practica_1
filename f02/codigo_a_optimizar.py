# Versión: 1.2.1
# Autor: Luis Daniel Zavala Cervantes
# Fecha: 14/03/2026
# Descripción: Optimización profesional usando collections.Counter y generadores.
# Entrada: Lista de números enteros.
# Salida: Frecuencias, modo y suma de dígitos con alta eficiencia.

from collections import Counter

numeros = [3, -1, 0, 5, -7, 0, 2, 3, 3, -1, 5, 5, 5]

# MOD: v1.2.0 — Uso de Counter: clase especializada que cuenta elementos en O(n)
# Esta clase sustituye los bucles manuales de búsqueda por una implementación nativa.
frecuencias_obj = Counter(numeros)

# Convertir a lista de tuplas para mantener el formato original requerido
frecuencias = list(frecuencias_obj.items())

# Bloque: Obtención del valor modal
# MOD: v1.2.0 — most_common(1) extrae el elemento con mayor frecuencia eficientemente
modo, max_cuenta = frecuencias_obj.most_common(1)[0]

# Bloque: Suma de dígitos del modo
# MOD: v1.2.0 — Uso de generador y función sum() para evitar el bucle while manual
# 1. abs(modo) quita el signo.
# 2. str() convierte a cadena para iterar carácter por carácter.
# 3. int(d) convierte cada carácter de vuelta a número.
suma_digitos = sum(int(d) for d in str(abs(modo)))

# Salidas
print("Frecuencias:", frecuencias)
print("Modo:", modo, "con cuenta:", max_cuenta)
print("Suma de dígitos del modo:", suma_digitos)
