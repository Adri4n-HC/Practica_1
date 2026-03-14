# python_no_opt.py
# Versión: 1.1.0
# Autor: [Maroto May Alejandro]
# Fecha: 13-03-2026
# Descripción: Determina la frecuencia de números, identifica la moda y suma los dígitos de esta.
# Entrada: Lista de enteros (numeros).
# Salida: Diccionario de frecuencias, valor modal y suma de sus dígitos.

numeros = [3, -1, 0, 5, -7, 0, 2, 3, 3, -1, 5, 5, 5]

# MOD: v1.1.0 — Sustitución de listas por diccionario para reducir complejidad de O(n^2) a O(n)
frecuencias_dict = {}

# Construir mapa de frecuencias en un solo recorrido
for val in numeros:
    # Si el valor ya existe, incrementa; si no, inicializa en 1
    if val in frecuencias_dict:
        frecuencias_dict[val] += 1
    else:
        frecuencias_dict[val] = 1

# MOD: v1.1.0 — Conversión a formato de lista de tuplas para mantener compatibilidad con salida original
frecuencias = list(frecuencias_dict.items())

# Encontrar el valor modal de forma eficiente
modo = None
max_cuenta = -1

for v, c in frecuencias:
    # Actualiza el modo si encuentra una frecuencia mayor
    if c > max_cuenta:
        max_cuenta = c
        modo = v

# Sumar dígitos del valor modal
# MOD: v1.1.0 — Simplificación usando conversión a string y valor absoluto
abs_modo = abs(modo)
suma_digitos = sum(int(digito) for digito in str(abs_modo))

# Salidas de resultados
print("Frecuencias:", frecuencias)
print(f"Modo: {modo} con cuenta: {max_cuenta}")
print(f"Suma de dígitos del modo: {suma_digitos}")
