// https://www.urionlinejudge.com.br/judge/pt/problems/view/1310
#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int maxSum(int x[], int n, int cust);
int main() {
  int vetor[1050];
  int n;
  int custo, resultado;

  while (scanf("%d", &n) != EOF) {
    scanf("%d", &custo);
    for (int i = 0; i < n; i++) scanf("%d", &vetor[i]);
    resultado = maxSum(vetor, n, custo);
    (resultado <= 0) ? printf("0\n") : printf("%d\n", resultado);
  }

  return 0;
}

int maxSum(int x[], int n, int cust) {
  int max, acc;
  max = -cust;
  acc = 0;
  for (int i = 0; i < n; i++) {
    acc += x[i] - cust;
    if (acc > max) max = acc;
    if (acc < 0) acc = 0;
  }
  return max;
}