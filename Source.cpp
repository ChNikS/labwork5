#include<conio.h>
#include <iostream>
using namespace std;
int V;///global variable for setting size
/// function of Deijkstra algoritm
void Dijkstra(int **mas, int st)
{
	int *distance, count, index, i, u, m = st + 1;
	distance = new int[V];
	bool *visited;
	visited = new bool[V];
	for (i = 0; i<V; i++)
	{
		distance[i] = INT_MAX; visited[i] = false;
	}
	distance[st] = 0;
	for (count = 0; count<V - 1; count++)
	{
		int min = INT_MAX;
		for (i = 0; i<V; i++)
			if (!visited[i] && distance[i] <= min)
			{
				min = distance[i]; index = i;
			}
		u = index;
		visited[u] = true;
		for (i = 0; i<V; i++)
			if (!visited[i] && mas[u][i] && distance[u] != INT_MAX &&
				distance[u] + mas[u][i]<distance[i])
				distance[i] = distance[u] + mas[u][i];
	}
	cout << "distance form 1\n";
	for (i = 0; i<V; i++) if (distance[i] != INT_MAX)
		cout << m << " > " << i + 1 << " = " << distance[i] << endl;
	else cout << m << " > " << i + 1 << " = " << "unavailable" << endl;
}
///main function
void main()
{
	std::cin >> V;
	int **mas=new int*[V];
	for (int i = 0; i < V; i++){
		mas[i] = new int[V];
	
	}
	for (int i = 0; i < V; i++){
		for (int j = 0; j < V; j++){
			std::cin >> mas[i][j];
		}
	}

	Dijkstra(mas, 0);///function dijkstra call
	_getch();
}