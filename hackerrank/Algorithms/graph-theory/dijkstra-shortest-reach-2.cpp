// https://www.hackerrank.com/challenges/dijkstrashortreach/problem

#include <bits/stdc++.h>

using namespace std;

#define INF numeric_limits<int>::max()

vector<int> dijkstra(vector<vector<int>> &graph, int start) {
  vector<int> dist(graph.size(), INF);
  vector<bool> visted(graph.size(), false);

  dist[start] = 0;

  for (int i = 1; i <= graph.size(); ++i) {
    int u = 0, smallDist = INF;
    for (int j = 1; j < graph.size(); ++j) {
      if (!visted[j] && dist[j] < smallDist) {
        u = j;
        smallDist = dist[j];
      }
    }
  
    visted[u] = true;

    for (int v = 1; v < graph.size(); ++v) {
      if (graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
        dist[v] = dist[u] + graph[u][v];
      }
    }
  }

  return dist;
}

int main() {
  int N, T, M, u, v, w, start;
  cin >> T;
  while (T--) {
    cin >> N >> M;
    vector<vector<int>> graph;
    graph.resize(N + 1, vector<int>(N + 1, INF));

    for (int i = 0; i < M; ++i) {
      cin >> u >> v >> w;
      int minimum = min(graph[u][v], w);
      graph[u][v] = graph[v][u] = minimum;
    }
    cin >> start;

    vector<int> dist = dijkstra(graph, start);

    bool space = false;
    for (int i = 1; i <= N; ++i) {
      if (i != start) {
        if (space)
          cout << " ";
        else
          space = true;
        cout << (dist[i] == INF ? -1 : dist[i]);
      }
    }
    cout << endl;
  }
}