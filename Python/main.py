import time
import sys
sys.set_int_max_str_digits(85000)
def fibonacci(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        a, b = 0, 1
        for _ in range(2, n + 1):
            a, b = b, a + b
        return b


n = 400000


inicio = time.perf_counter()
resultado = fibonacci(n)
fin = time.perf_counter()
tiempo_transcurrido = (fin - inicio) * 1000
print("Python: ",tiempo_transcurrido, "ms")

# Escribir el resultado en un archivo de texto
with open("resultado_python.txt", "a") as archivo:
    archivo.write(str(resultado))