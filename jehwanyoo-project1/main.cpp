#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[101];
bool visited[101];
int N, M, cnt;

void dfs(int x) {
	visited[x] = true;
    cnt++;
	
	for (auto n : graph[x]) {
        if (!visited[n]) dfs(n);
    }
}

int main(void)
{
	int a, b;
    
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	dfs(1);
    
	cout << cnt - 1 << endl;
}
