#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

/*В стране N городов, некоторые из которых соединены между собой дорогами. Для того, чтобы
проехать по одной дороге, требуется один бак бензина. В каждом городе бак бензина имеет 
разную стоимость. Вам требуется добраться из первого города в N-ый, потратив как можно 
меньшее денег. Покупать бензин впрок нельзя.

Входные данные
В первой строке вводится число N (1≤N≤100), в следующей строке идет N чисел, i-ое из которых
задает стоимость бензина в i-ом городе (всё это целые числа из диапазона от 0 до 100). Затем
идет число M – количество дорог в стране, далее идет описание самих дорог. Каждая дорога 
задается двумя числами – номерами городов, которые она соединяет. Все дороги двухсторонние 
(то есть по ним можно ездить как в одну, так и в другую сторону), между двумя городами 
всегда существует не более одной дороги, не существует дорог, ведущих из города в себя.

Выходные данные
Требуется вывести одно число – суммарную стоимость маршрута или -1, если добраться невозможно.

Пример:входные данные
5
3 6 1 7 6 
8
1 2
5 4
5 1
3 4
5 2
2 4
2 3
3 1
выходные данные
3*/

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int cost;
};

vector<vector<Edge>> graph;
vector<int> prices;
vector<int> dist;

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({ 0, start });

    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();

        if (d_v != dist[v]) continue;

        for (const Edge& e : graph[v]) {
            int to = e.to;
            int cost = d_v + prices[v];
            if (dist[to] > cost) {
                dist[to] = cost;
                q.push({ dist[to], to });
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N;
    prices.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }
    cin >> M;
    graph.resize(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--; // adjust to 0-based indexing
        graph[u].push_back({ v, 1 });
        graph[v].push_back({ u, 1 });
    }

    dist.resize(N, INF);
    dijkstra(0);

    if (dist[N - 1] == INF) {
        cout << -1 << endl;
    }
    else {
        cout << dist[N - 1] << endl;
    }

    return 0;
}