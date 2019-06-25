#include <iostream>
#include <stack>
#include <vector>
using namespace std;
 
public class Computer
{
	int mData;
    bool isVisited = false;

	Computer()
	{
	}
	
	Computer(int data)
		:mData(data)
	{
	}
}

void dfs(Computer* computer)
{
	if ((computer->isVisited == false) && (computer->mData == 1))
		stack.push(computer);

	visited.push(computer);
	computer->isVisited = true;
	stack.pop();
	for (std::vector<::Computer*>::iterator iter = (computer->pointer).begin();
		iter != (computer->pointer).end(); iter++)
	{
		if ((*iter)->isVisited == false)
		{
			stack.push(*iter);
		}
	}

	if (stack.empty())
		return;
	else
	{
		dfs(stack.top());
	}
}

int main()
{

	std::stack<Computer*> visited;
	std::stack<Computer*> stack;
	int num_of_nodes;
	int num_of_pairs;
	cin >> num_of_nodes;
	cin >> num_of_pairs;
	vector<Computer*> computers;

	for (int i = 1; i <= num_of_nodes; i++)
	{
		computers.push_back(new Computer(i));
	}

	for (int i = 0; i < num_of_pairs; i++)
	{
		int first;
		int second;
		cin >> first;
		cin >> second;
		computers.at(first - 1)->pointer.push_back(computers.at(second-1));
		computers.at(second - 1)->pointer.push_back(computers.at(first - 1));
	}

	int first_index = 0;
	for (vector<Computer*>::iterator it = computers.begin(); it != computers.end(); it++)
	{
		if ((*it)->mData == 1)
		{
			break;
		}
		else
			first_index++;
	}

	DFS* dfs_unit = new DFS();
	dfs_unit->dfs(computers.at(first_index));
	
	//cout << dfs_unit->visited.size() << endl; // visited 벡터의 사이즈.

	//dfs_unit->visited.pop();

	int visited_count = 0;
	cout << endl;
	while (!((dfs_unit->visited).empty()))
	{
		//cout << "방문 노드 : " << dfs_unit->visited.top()->mData << endl;
		dfs_unit->visited.pop();
		visited_count++;
	}
	
	cout << visited_count << endl;
	system("pause");
}