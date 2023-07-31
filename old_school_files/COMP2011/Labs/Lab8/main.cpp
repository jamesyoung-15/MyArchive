#include <iostream>
#include "agent.h"
#include "maps.h"
#include <string.h>
using namespace std;

void map_init(char map[10][10], int* map_size, const int i)
{
	switch (i)
	{
		case 0:
			*map_size = 3;
			for (int i = 0; i < *map_size; ++i)
			{
				memcpy(map[i], map0[i], sizeof(map0[i]));
			}
			break;
		case 1:
			*map_size = 5;
			for (int i = 0; i < *map_size; ++i)
			{
				memcpy(map[i], map1[i], sizeof(map1[i]));
			}
			break;
		case 2:
			*map_size = 8;
			for (int i = 0; i < *map_size; ++i)
			{
				memcpy(map[i], map2[i], sizeof(map2[i]));
			}
			break;
		case 3:
			*map_size = 10;
			for (int i = 0; i < *map_size; ++i)
			{
				memcpy(map[i], map3[i], sizeof(map3[i]));
			}
			break;
	}
}

void goal_init(char map[10][10], const int map_size, int goal_loc[2])
{
	while (true)
	{
		int x,y;
		cin >> x >> y;
		if (map[x][y] == 'x')
		{
			cout << "Already occupied by an obstackle, please choose another one:" << endl;
			continue;
		}
		else if ((x < 0 || x >= map_size) || (y < 0 || y >= map_size))
		{
			cout << "Please pick a goal location inside the map:" << endl;
			continue;
		}
		map[x][y] = 'g';
		goal_loc[0] = x; goal_loc[1] = y;
		break;
	}
}

void print_map(const char map[10][10], const int map_size, const int curr_loc[2], const int mode)
{
	switch (mode)
	{
		case 0: // print empty map 
			for (int i = 0; i < map_size; ++i)
			{
				for (int j = 0; j < map_size; ++j)
				{
					cout << map[i][j] << ' ';
				}
				cout << endl;
			}
			cout << endl;
			break;
		case 1: // print intermediat steps
			for (int i = 0; i < map_size; ++i)
			{
				for (int j = 0; j < map_size; ++j)
				{
					if (i == curr_loc[0] && j == curr_loc[1])
					{
						cout << 'O' << ' ';
					}
					else
					{
						cout << map[i][j] << ' ';
					}
				}
				cout << endl;
			}
			cout << endl;
			break;
		case 2: // print goal state
			for (int i = 0; i < map_size; ++i)
			{
				for (int j = 0; j < map_size; ++j)
				{
					if (i == curr_loc[0] && j == curr_loc[1])
					{
						cout << 'G' << ' ';
					}
					else
					{
						cout << map[i][j] << ' ';
					}
				}
				cout << endl;
			}
			cout << endl;
			cout << "Reach the goal!" << endl;
			break;
	}
}

int main()
{
	const int MAX_ITER = 20;

	// Map initialization
	char map[10][10];

	int map_size;

	cout << "Please specify which map you want to use: 0~3:" << endl;
	int i;
	cin >> i;
	map_init(map, &map_size, i);

	cout << "Please specify the goal location (except [0, 0]):" << endl;
	int goal_loc[2];
	goal_init(map, map_size, goal_loc);

	cout << "The map looks like this:" << endl;
	print_map(map, map_size, NULL, 0);

	// Game starts
	cout << "Start path finding..." << endl;
	int* curr_loc = new int[2];
	curr_loc[0] = 0; curr_loc[1] = 0;

	int step = 0;
	while(!reach_goal(curr_loc, goal_loc)){
		cout << "Step: " << step << endl;
		print_map(map, map_size, curr_loc, 1);

		State* curr_state = observe(map, map_size, goal_loc, curr_loc);
		Action* action = think(curr_state);
		int* next_loc = act(curr_state, action);

		curr_loc = next_loc;

		step += 1;

		if (step > MAX_ITER)
		{
			cout << "Fail to reach the goal :-(" << endl;
			cout << "However, please think that is this goal really unreachable, or is your algorithm to blame?" << endl;
			
			// TODO
			delete[] curr_loc;
			return -1;
			// TODO ends
		}
	}

	cout << "Step: " << step << endl;
	print_map(map, map_size, curr_loc, 2);

	// TODO
	delete[] curr_loc;
	// TODO ends

	return 0;
}