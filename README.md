# Actividad 2
Este proyecto implementa dos algoritmos para calcular el cambio mínimo utilizando un conjunto dado de denominaciones de monedas:

- Programación Dinámica: Emplea una técnica de memoización para encontrar la solución óptima, considerando todas las posibles combinaciones de monedas.
- Algoritmo Ávaro: Utiliza un enfoque greedy para seleccionar en cada paso la moneda de mayor valor posible que sea menor o igual al cambio restante.

# Autores:
1. Dael Chávez Ferreyra - A01771963
2. Andrea Bahena Valdés - A01369019

# Fecha de Última Modificación
17-AGO-2024

## Estructura del Código:
dinamico(int cambio, vector<int> vec): Implementa el algoritmo de programación dinámica.
Complejidad: O(n^2)
Funcionamiento: Utiliza una matriz de memoización para almacenar los resultados de subproblemas y construir la solución óptima de forma bottom-up.
avaro(int cambio, vector<int> vec): Implementa el algoritmo ávido.
Complejidad: O(n)
Funcionamiento: Selecciona en cada paso la moneda de mayor valor posible que sea menor o igual al cambio restante.
## Compilación y Ejecución:
### Requisitos:
Un compilador de C++ (por ejemplo, g++)

El programa solicitará:

El número de denominaciones de monedas.
Las denominaciones de monedas.
El valor a pagar y el monto recibido.
Ejemplo de Entrada:
3
10 5 1
15 20
Ejemplo de Salida:
Solución usando programación dinámica: 
1 monedas de 10
0 monedas de 5
0 monedas de 1

Solución algoritmo ávaro: 
1 monedas de 10
1 monedas de 5
0 monedas de 1
