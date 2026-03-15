#Alan Sanchez Hernandez 
numeros = [3, -1, 0, 5, -7, 0, 2, 3, 3, -1, 5, 5, 5]

frecuencias_dict = {}

for val in numeros:
    if val in frecuencias_dict:
        frecuencias_dict[val] += 1
    else:
        frecuencias_dict[val] = 1

frecuencias = list(frecuencias_dict.items())

modo = None
max_cuenta = -1

for v, c in frecuencias_dict.items():
    if c > max_cuenta:
        max_cuenta = c
        modo = v

x = abs(modo)
suma_digitos = 0

while x > 0:
    suma_digitos += (x % 10)
    x //= 10

print("Frecuencias:", frecuencias)
print("Modo:", modo, "con cuenta:", max_cuenta)
print("Suma de dígitos del modo:", suma_digitos)
