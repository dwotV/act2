#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

vector<int> vec;

vector<int> dinamico(int cambio, vector<int> vec) {
    int n = vec.size();
    vector<int> memoria(cambio + 1, INT_MAX);
    vector<int> numMonedas(cambio + 1, 0);
    vector<int> monedasUsadas(cambio + 1, -1);
    
    memoria[0] = 0;
    
    for (int i = 1; i <= cambio; i++) {
        for (int j = 0; j < n; j++) {
            if (vec[j] <= i && memoria[i - vec[j]] != INT_MAX) {
                if (memoria[i] > memoria[i - vec[j]] + 1) {
                    memoria[i] = memoria[i - vec[j]] + 1;
                    monedasUsadas[i] = j;
                }
            }
        }
    }
    
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

vector<int> avaro(int cambio, vector<int> vec) {
 int n  = vec.size();
  vector<int> res(n, 0);

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
  printf("\nSolución algoritmo avaro: \n");
  for (int i = 0; i < N; i++) {
    cout << resAvaro[i] << " monedas de " << vec[i] << endl;
  }

  return 0;
}
