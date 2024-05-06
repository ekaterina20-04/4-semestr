#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <vector>

using namespace std;

// создаем граф в виде словаря
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

vector<string> bfs(string start, string end) {
	queue<string> q; //контейнер, который хранит элементы в порядке, в котором они были добавлены
	map<string, int> dist;
	map<string, string> prev;// Словарь предшественника
	q.push(start);
	dist[start] = 0;
	prev[start] = ""; //расстояние от нач верш до себя 0,предшествующая является пустой строкой

	while (!q.empty()) {
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
			// Если мы не видим соседа, то обновляем расстояние и предшественника
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

	if (!path.empty()) { //если контейнер не пустой
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