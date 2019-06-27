#include <iostream>
#include <stack>

using namespace std;

stack<int>* book;
bool* visited;
int wcount = 0;

void union_search(int a)
{
	if (visited[a - 1] == true)
		return;
	else
	{
		visited[a - 1] = true;
		wcount++;
	}
	while (!book[a - 1].empty())
	{
		int number = book[a - 1].top();
		book[a - 1].pop();
		union_search(number);
	}
}
int main()
{
	int N;
	int C;
	cin >> N >> C;
	visited = new bool[N]; // 값 1은 인덱스 0에
	book = new stack<int>[N];

	int j = 0;
	for (; j < N;)
	{
		visited[j] = false;
		j++;
	}

	int i = 0;
	for (; i < C;)
	{
		int first;
		int second;
		cin >> first;
		cin >> second;
		book[first - 1].push(second);
		book[second - 1].push(first);
		i++;
	}

	union_search(1);
	cout << wcount - 1<< endl;
	system("pause");
}