#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <vector>

using namespace std;

// Граф в виде словаря
map<string, vector<string>> graph = {
	{"A", {"S"}},
	{"B", {"C", "D", "S"}},
	{"C", {"B", "J"}},
	{"D", {"B", "G", "S"}},
	{"E", {"G", "S"}},
	{"F", {"G", "H"}},
	{"G", {"D", "E", "F", "H", "J"}},
	{"H", {"F", "G", "I"}},
	{"I", {"H", "J"}},
	{"J", {"C", "G", "I"}},
	{"S", {"A", "B", "D", "E"}}
};

// Функция для поиска кратчайшего пути в ширину
vector<string> bfs(string start, string end) {
	// Очередь для вершин, которые нужно обойти
	queue<string> q;
	// Словарь для хранения расстояния до каждой вершины
	map<string, int> dist;
	// Словарь для хранения предшественника для каждой вершины
	map<string, string> prev;
	// Очередь для вершин, которые нужно обойти
	q.push(start);
	// Расстояние до стартовой вершины равно 0
	dist[start] = 0;
	// Предшественник стартовой вершины - это сама стартовая вершина
	prev[start] = "";

	while (!q.empty()) {
		// Выбираем вершину из очереди
		string curr = q.front();
		q.pop();

		// Если мы достигли конечной вершины, то можно строить путь
		if (curr == end) {
			vector<string> path;
			string temp = end;
			while (temp != "") {
				path.push_back(temp);
				temp = prev[temp];
			}
			reverse(path.begin(), path.end());
			return path;
		}

		// Обходим все смежные вершины
		for (string neighbor : graph[curr]) {
			// Если мы не visited соседа, то обновляем расстояние и предшественника
			if (dist.find(neighbor) == dist.end() || dist[neighbor] > dist[curr] + 1) {
				dist[neighbor] = dist[curr] + 1;
				prev[neighbor] = curr;
				q.push(neighbor);
			}
		}
	}

	// Если мы не достигли конечной вершины, то путь не существует
	return {};
}

int main() {
	setlocale(LC_ALL, "Russian");
	string start = "S";
	string end = "I";
	vector<string> path = bfs(start, end);

	if (!path.empty()) {
		cout << "Кратчайший путь от " << start << " до " << end << ": ";
		for (string vertex : path) {
			cout << vertex << " ";
		}
		cout << endl;
	}
	else {
		cout << "Путь не существует" << endl;
	}

	return 0;
}