#include <iostream>
#include <cstdlib>
#include "agent.h"
using namespace std;


State* observe(const char map[10][10], const int map_size, const int goal_loc[2], int agent_loc[2])
{
	State* curr_state = new State;

	// TODO
	curr_state->curr_loc[0] = agent_loc[0]; curr_state->curr_loc[1] = agent_loc[1];
	curr_state->goal_loc[0] = goal_loc[0]; curr_state->goal_loc[1] = goal_loc[1];
	curr_state->map_size = map_size; 

	for (int dx = -SENSOR_RANGE; dx < SENSOR_RANGE + 1; ++dx)
	{
		for (int dy = -SENSOR_RANGE; dy < SENSOR_RANGE + 1; ++dy)
		{
			if (abs(dx) + abs(dy) <= 2 && 
				(agent_loc[0] - dx >= 0 && agent_loc[0] + dx <= map_size - 1) && 
				(agent_loc[1] - dy >= 0 && agent_loc[1] + dy <= map_size - 1)) 
			{
				int detect_loc_x = agent_loc[0] - dx;
				int detect_loc_y = agent_loc[1] - dy;
				if (map[detect_loc_x][detect_loc_y] == 'x')
				{
					curr_state->obstacle[0] = detect_loc_x; curr_state->obstacle[1] = detect_loc_y;
					return curr_state;
				}
			}
		}
	}
	curr_state->obstacle[0] = -1; curr_state->obstacle[1] = -1;

	delete[] agent_loc;
	// TODO ends

	return curr_state;
}


Action* think(const State* curr_state)
{
	int	min_dist_to_goal = 999;
	Action* best_action = new Action;

	Action actions[4] = {N, S, E, W};
	for (int i = 0; i < 4; ++i)
	{
		int next_x, next_y;

		switch (actions[i])
		{
			case N:
				next_x = curr_state->curr_loc[0] - 1;
				next_y = curr_state->curr_loc[1];
				break;
			case S:
				next_x = curr_state->curr_loc[0] + 1;
				next_y = curr_state->curr_loc[1];
				break;
			case E:
				next_x = curr_state->curr_loc[0];
				next_y = curr_state->curr_loc[1] + 1;
				break;
			case W:
				next_x = curr_state->curr_loc[0];
				next_y = curr_state->curr_loc[1] - 1;
				break;
		}

		// TODO
		if (next_x == curr_state->obstacle[0] && next_y == curr_state->obstacle[1])
		{
			continue;
		}
		else if (next_x < 0 || next_x > curr_state->map_size - 1 || next_y < 0 || next_y > curr_state->map_size - 1)
		{
			continue;
		}
		else
		{
			int dist_to_goal = abs(curr_state->goal_loc[0] - next_x) + abs(curr_state->goal_loc[1] - next_y);
			if (dist_to_goal <= min_dist_to_goal)
			{
				min_dist_to_goal = dist_to_goal;
				*best_action = actions[i];
			}
		}
		// TODO ends
	}
	return best_action;
}


int* act(State* curr_state, Action* action)
{
	// TODO
	int* next_loc = new int[2];
	// TODO ends

	int next_x, next_y;
	switch (*action)
	{
		case N:
			next_x = curr_state->curr_loc[0] - 1;
			next_y = curr_state->curr_loc[1];
			break;
		case S:
			next_x = curr_state->curr_loc[0] + 1;
			next_y = curr_state->curr_loc[1];
			break;
		case E:
			next_x = curr_state->curr_loc[0];
			next_y = curr_state->curr_loc[1] + 1;
			break;
		case W:
			next_x = curr_state->curr_loc[0];
			next_y = curr_state->curr_loc[1] - 1;
			break;
	}

	// TODO
	next_loc[0] = next_x; next_loc[1] = next_y;

	delete action;
	delete curr_state;

	return next_loc;
	// TODO ends
}


bool reach_goal(const int curr_loc[2], const int goal_loc[2])
{
	if (curr_loc[0] == goal_loc[0] && curr_loc[1] == goal_loc[1])
	{
		return true;
	}
	return false;
}
