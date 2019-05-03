// https://www.urionlinejudge.com.br/judge/pt/problems/view/1288

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
int t[100][100], a, b;

int mochila(int w[], int v[], int n, int W) {
  for (int y = 0; y <= W; y++) {
    t[0][y] = 0;
    for (int i = 1; i <= n; i++) {
      a = t[i - 1][y];
      if (w[i] > y) {
        b = 0;
      } else {
        b = t[i - 1][y - w[i]] + v[i];
      }
      if (a > b)
        t[i][y] = a;
      else
        t[i][y] = b;
    }
  }
  return (t[n][W]);
}

int main() {
  int w[60], v[60], n;
  int objetos, carga, total, resistencia;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &objetos);
    for (int i = 1; i <= objetos; i++) {
      scanf("%d", &v[i]);
      scanf("%d", &w[i]);
    }
    scanf("%d", &carga);
    scanf("%d", &resistencia);
    total = mochila(w, v, objetos, carga);
    (total >= resistencia) ? printf("Missao completada com sucesso\n")
                           : printf("Falha na missao\n");
  }
  return (0);
}