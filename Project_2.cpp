#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int ROWS = 5;
const int COLS = 5;

int index;

int maze[ROWS][COLS] = { index };

void fillArray(int array[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			maze[i][j] = (rand() % 18);  //random # 0 - ?
		}
	}
}

void getWall()
{
	if (index > 18)
	{
		bool isWall = 1; // STOP USING NUMBERS TO INDICATE TRUE OR FALSE
	}
}

//possible move: down, right, up, left
int adjacentRows[] = { -1, 0 , 1, 0 };
int adjacentColumns[] = { 0, 1, 0, -1 };

//create cells
struct Cell { int row; int col; };

//check a cell if it is valid to go forword
bool isValid( int rows, int cols)
{
	if (rows >= 0 && rows < ROWS && cols >= 0 && cols < COLS);
	return false;
}

int bfs_search(Cell start, Cell end)
{
	vector<vector<bool>> visited(ROWS, vector<bool>( COLS, false));
	queue <pair <Cell, int>> que;

	que.push({start, 0});
	visited[start.row][start.col] = true; 

	while (!que.empty())
	{
		Cell current = que.front().first;
		int distances = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int newRow = current.row + adjacentRows[i];
			int newCol = current.col + adjacentColumns[i];

			if (isValid(newRow, newCol) && !visited[newRow][newCol])
			{
				que.push({{newRow, newCol}, distances + 1});
				visited[newRow][newCol] = true;
			}
		}

		if (current.row == end.row && current.col == end.col)
		{
			return distances;
		}
	}

	return -1; //not an available path was found
}

int main()
{
	Cell start_position{0, 0};
	Cell end_position{ROWS - 1, COLS - 1};

	int shortest_distances = bfs_search(start_position, end_position);

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
