#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int SIZE = 5;

enum CellType {
	START, EMPTY, WALL, END
};

void fillArray(vector<vector<CellType>>& grid, int threshold_wall)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			int randomnum = rand() % 100; //assign ramdom number 0-100. If the number is greater than 50 then it becomes a wall cell.
			if (randomnum > threshold_wall)
			{
				grid[i][j] = WALL; //set as wall
			}
			else
			{
				grid[i][j] = EMPTY; //set as empty
			}
		}
	}
}

//possible move: down, right, up, left
int adjacentRows[] = { -1, 0 , 1, 0 };
int adjacentColumns[] = { 0, 1, 0, -1 };

//check a cell if it is valid to go forword
bool isValid( int rows, int cols)
{
	return (rows >= 0 && rows < SIZE && cols >= 0 && cols < SIZE);	 
}

int bfs_search(vector<vector<CellType>>& grid, pair<int, int> START,
 pair<int, int> END, vector<vector<bool>>& visited)
{
	queue <pair <int, int>> que;
	que.push(START);
	visited[START.first][START.second] = true;
	vector<vector<int>> distance(SIZE, vector<int>(SIZE, -1));
	distance[START.first][START.second] = 0;

	while (!que.empty())
	{
		pair<int, int> current = que.front();
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int newRow = current.first + adjacentRows[i];
			int newCol = current.second + adjacentColumns[i];

			if (isValid(newRow, newCol) && !visited[newRow][newCol]
			&& grid[newRow][newCol] != WALL)
			{
				visited[newRow][newCol] = true;
				que.push({newRow, newCol});
				distance[newRow][newCol] = distance[current.first][current.second] + 1; 
			}
		}

		if (current == END)
		{
			return distance[current.first][current.second];
		}
	}

	return -1; //not an available path was found
}

int main()
{
	vector<vector<CellType>> grid(SIZE, vector<CellType>(SIZE, EMPTY));
	vector<vector<bool>> visited(SIZE, vector<bool>(SIZE, false)); 

	fillArray(grid, 90);

	pair<int, int> START = { 0, 0 };
	pair<int, int> END = { SIZE - 1, SIZE - 1 };

	int shortest_distances = bfs_search(grid, START, END, visited);

	if (shortest_distances == true)
	{
		cout << "Found the shortest route using BFS algorithm." << endl;
		cout << "Total path length: " << shortest_distances << endl;
	}
	else {
		cout << "No path was found." << endl;
	}

	return 0;
}
