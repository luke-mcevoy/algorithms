#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> toposort(vector<int> graph[], const size_t size) {
    int *indegree = new int[size];
    fill(indegree + 1, indegree + size, 0);

    for (size_t row = 1; row < size; row++) {
        for (size_t col = 0; col < graph[row].size(); col++) {
            indegree[graph[row][col]]++;
        }
    }

    // Min priority queue
    priority_queue<int, vector<int>, greater<int>> q;
    for (size_t i = 1; i < size; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int vertex = q.top()
        q.pop();
        order.push_back(vertex);
        for (int adjacent : graph[vertex]) {
            indegree[adjacent]--;
            if (indegree[adjacent] == 0) {
                q.push(adjacent);
            }
        }
    }

    for (size_t i = 1; i < size; i++) {
        if (indegree[i] > 0) {
            order.clear();
            break;
        }
    }

    delete [] indegree;
    return order;
}

int main() {
    size_t n, m;
    cin >> n >> m;
    vector<int> *graph = new vector<int>[n + 1];
    while (m--) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    vector<int> order = toposort(graph, n+1);
    if (order.size() > 0) {
        for (int vertex : order) {
            cout << vertex << " "; 
        }
    } else {
        cout << "Sandro fails";
    }
    return 0;
}