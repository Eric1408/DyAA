import matplotlib.pyplot as plt

# Leer datos desde un archivo
with open('resultados.txt', 'r') as file:
    lines = file.readlines()

# Procesar los datos
dimensiones = []
tiempo_por_filas = []
tiempo_por_columnas = []

for line in lines:
    data = line.split()
    dimensiones.append(int(data[0]))
    tiempo_por_filas.append(float(data[1]))
    tiempo_por_columnas.append(float(data[2]))

# Crear la gráfica
plt.figure(figsize=(10, 6))
plt.scatter(dimensiones, tiempo_por_filas, color='blue', label='Multiplicación por filas', marker='o')
plt.scatter(dimensiones, tiempo_por_columnas, color='red', label='Multiplicación por columnas', marker='o')

# Añadir etiquetas y título
plt.xlabel('Dimension')
plt.ylabel('Tiempo de ejecución en segundos')
plt.title('Tiempo de ejecución de multiplicación de matrices por filas y columnas')
plt.legend()

# Mostrar la gráfica
plt.savefig('grafica.png')

