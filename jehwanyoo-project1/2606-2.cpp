// union-find 

#include <iostream>
#include <vector>

using namespace std;

int parent[101];
int N, M, cnt;

void make_set() {
	for (int i = 1; i <= N; i++)
		parent[i] = i;
}

int _find(int x) {
	return parent[x] == x ? x : (parent[x] = _find(parent[x]));
}

void _union(int a, int b) {
	a = _find(a);
	b = _find(b);
	
	if (a == b)
		return;
	
	if (a < b) 
		parent[b] = a;
	else 
		parent[a] = b;
}

int main(void)
{
	int a, b;
    
	cin >> N >> M;
	
	make_set();
	
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		_union(a, b);
	}
	
	for (int i = 2; i <= N; i++)
		if (_find(i) == 1)
			cnt++;

	cout << cnt << endl;
}
