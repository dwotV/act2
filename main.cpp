/*
 Actividad 1.2
 Análisis y diseño de algoritmos avanzados

 Dael Chávez Ferreyra - A01771963
 Andrea Bahena Valdés - A01369019
 Última modificación: 17-AGO-2024

 Este programa calcula el cambio con diferentes denominaciones de monedas
 implementando un algoritmo ávaro y por otro lado programación dinámica

 El propósito es calcular el cambio con la cantidad mínima de monedas

 */


#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

vector<int> vec;


/* Resolución mediante programación dinámica
   Complejidad algorítmica: O(n2)

   Función: Calculo de monedas mínimas con programación dinámica (memoización)
   Parámetro: cambio = entero que representa el cambio ($20 - $15 = $5 -> cambio)
              vec = vector de las monedas disponibles
   Retorno: resultado = vector con la optimización de las monedas para el cambio

*/
vector<int> dinamico(int cambio, vector<int> vec) {
    int n = vec.size();
    vector<int> memoria(cambio + 1, INT_MAX);
    vector<int> numMonedas(cambio + 1, 0);
    vector<int> monedasUsadas(cambio + 1, -1);
    
    memoria[0] = 0;
    
    for (int i = 1; i <= cambio; i++) {
        for (int j = 0; j < n; j++) {

 /* Etapa de memoización - programación dinámica
    Si se encuentra una mejor solución, se guarda (proceso de aprendizaje)
 */
            if (vec[j] <= i && memoria[i - vec[j]] != INT_MAX) {
                if (memoria[i] > memoria[i - vec[j]] + 1) {
                    memoria[i] = memoria[i - vec[j]] + 1;
                    monedasUsadas[i] = j;
                }
            }
        }
    }


//  Estructura de datos para almacenar las monedas de la solución

    vector<int> resultado(n, 0);
    if (memoria[cambio] != INT_MAX) {
        int monto = cambio;
        while (monto > 0) {
            int idx = monedasUsadas[monto];
            resultado[idx]++;
            monto -= vec[idx];
        }
    }
    
    return resultado;
}



/* Resolución mediante un algoritmo ávaro
   Complejidad algorítmica: O(n)

   Función: Calculo de monedas mínimas con programación dinámica (memoización)
   Parámetro: cambio = entero que representa el cambio ($20 - $15 = $5 -> cambio)
              vec = vector de las monedas disponibles
   Retorno: resultado = vector con la optimización de las monedas para el cambio


   El algoritmo ávaro, al ser un algoritmo Greedy no siempre ofrece la
   mejor solución. Algunas veces ni siquiera ofrece una solución, sino una
   aproximación cercana a la solución.

   Este algoritmo ávaro es un ávaro puro, por lo que no tiene un proceso
   de aprendizaje como sus variaciones Dijkstra o el ávaro binario
*/

vector<int> avaro(int cambio, vector<int> vec) {
 int n  = vec.size();
  vector<int> res(n, 0);

/*  Itera sobre las denominaciones para usar la moneda con valor
    igual o el más cercano al cambio tantas veces como sea posible
*/

  for (int i = 0; i < n; i++) {
    if (vec[i] <= cambio) {
      res[i] = cambio / vec[i];
      cambio %= vec[i];
    }
  }

  return res;
}

int main (int argc, char *argv[]) {
  
  int N;
  cin >> N;

  vec.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> vec[i];
  } 

  sort(vec.rbegin(), vec.rend());

  int P, Q;

  cin >> P >> Q;
  int cambio = Q - P;

  vector<int> resDinamico = dinamico(cambio, vec);
  printf("\nSolución usando programación dinámica: \n");
  for (int i = 0; i < N; i++) {
    cout << resDinamico[i] << " monedas de " << vec[i] << endl;
  }

  vector<int> resAvaro = avaro(cambio, vec);
  printf("\nSolución algoritmo ávaro: \n");
  for (int i = 0; i < N; i++) {
    cout << resAvaro[i] << " monedas de " << vec[i] << endl;
  }

  return 0;
}
