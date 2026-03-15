## Nombre del archivo: python_no_opt.py
# Versión: 1.2.0
# Autor: [Juan González David]
# Fecha: 14/03/2026
# Descripción: Optimización profesional usando la librería collections y generadores.
# Entrada: Lista de números.
# Salida: Frecuencias, modo y suma de dígitos.

from collections import Counter

numeros = [3, -1, 0, 5, -7, 0, 2, 3, 3, -1, 5, 5, 5]

# MOD: v1.2.0 — Uso de Counter para conteo de alta velocidad (implementado en C)
frecuencias_obj = Counter(numeros)

# Convertir a lista de tuplas para cumplir con el formato original del repositorio
frecuencias = list(frecuencias_obj.items())

# Bloque: Obtención de la moda de forma directa
# common[0] devuelve (valor, cuenta)
modo, max_cuenta = frecuencias_obj.most_common(1)[0]

# Bloque: Suma de dígitos usando comprensión de listas y generadores
# MOD: v1.2.0 — Evita el bucle while manual convirtiendo a string y sumando dígitos
suma_digitos = sum(int(digito) for digito in str(abs(modo)))

# Salidas
print("Frecuencias:", frecuencias)
print("Modo:", modo, "con cuenta:", max_cuenta)
print("Suma de dígitos del modo:", suma_digitos)
