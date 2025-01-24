struct State
{
	int curr_loc[2];
	int goal_loc[2];
	int obstacle[2];
	int map_size;
};

enum Action {E, S, W, N};

const int SENSOR_RANGE = 2;

State* observe(const char map[10][10], const int map_size, const int goal_loc[2], int agent_loc[2]);

Action* think(const State* curr_state);

int* act(State* curr_state, Action* action);

bool reach_goal(const int curr_loc[2], const int goal_loc[2]);

	