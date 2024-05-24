#include <iostream>
#include <vector>
#include <queue>
#include <limits>

/*Дан ориентированный взвешенный граф. Найдите кратчайшее расстояние от одной
заданной вершины до другой.

Входные данные
В первой строке содержатся три числа: N, S и F (1≤ N≤ 100, 1≤ S, F≤ N), где 
N – количество вершин графа, S – начальная вершина, а F – конечная. В следующих 
N строках вводится по N чисел, не превосходящих 100, – матрица смежности графа,
где -1 означает отсутствие ребра между вершинами, а любое неотрицательное число 
– присутствие ребра данного веса. На главной диагонали матрицы записаны нули.

Выходные данные
Требуется вывести искомое расстояние или -1, если пути между указанными вершинами не существует.*/

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(const vector<vector<int>>& graph, int start, int finish) {
	int n = graph.size();
	vector<int> dist(n, INF);
	vector<bool> visited(n, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if (visited[u]) continue;
		visited[u] = true; //маркируем текущую вершину u как посещенную

		for (int v = 0; v < n; v++) {
			if (graph[u][v] != -1 && !visited[v]) {
				int alt = dist[u] + graph[u][v];
				if (alt < dist[v]) {
					dist[v] = alt;
					pq.push({ alt, v });
				}
			}
		}
		/*обновляем кратчайшие расстояния до соседних вершин, и добавляем 
		их в приоритетную очередь*/
	}

	return dist;
}

int main() {
	int n, s, f;
	cin >> n >> s >> f;
	s--; f--; //тк индексы

	vector<vector<int>> graph(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	vector<int> dist = dijkstra(graph, s, f);

	if (dist[f] == INF) {
		cout << -1 << endl;
	}
	else {
		cout << dist[f] << endl;
	}

	return 0;
}