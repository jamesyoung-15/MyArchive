#include "lab7.h"
using namespace std;

/* External variable declarations */
// TODO 2
extern int board_size;
extern int total_step;

/* Initialize the state of a player.
   1. Read an English letter as the symbol of the player;
   2. If idx == 0 (the first player), place it at the bottom-left corner of the chessboard,
      if idx == 1 (the second player), place it at the top-right corner of the chessboard;
   3. Initialize its weight to 0.
 */
void initialize_player(Player ps[], int idx){
    Player& p = ps[idx];
    while(1){
        cout << "Please input the denoting letter of Player " << idx << " (must be one English letter in [a-zA-Z])"<< endl;
        cin >> p.letter;
        if (! (p.letter>='a' && p.letter <= 'z' || p.letter>='A' && p.letter<='Z' ) || \
            ps[idx].letter == ps[1-idx].letter)
            cout << "Please input a unique English letter" << endl;
        else
            break;
    }
    if (idx == 0){
        p.loc[0] = board_size-1;
        p.loc[1] = 0;
    } else{
        p.loc[0] = 0;
        p.loc[1] = board_size-1;
    }
    p.weight = 0;
}

/* Check whether the player is inside the board 
   Note that the size of board is stored in external vairable board_size
*/
bool check_inside(const Player& p){
    if(p.loc[0] >= 0 && p.loc[0] < board_size && p.loc[1] >= 0 && p.loc[1] < board_size)
        return true;
    //cout << p.letter << " is outside the board" << endl;
    return false;
}

void show_player(const Player& p){
    if(check_inside(p))
        printf("Player %c at (%d, %d) with weight %d.\n", p.letter, p.loc[0], p.loc[1], p.weight);
    else
        printf("Player %c is outside the board, please guide it back.\n", p.letter);
}

void initialize_board(char board[][MAX_BOARD_SIZE], const Player ps[]){
    string seq_10 = "1101211001212121001122002221112000201111000221222021122022110020221012000020220210022002210020111002";
    int c = 0;
    cout << endl;
    for (int i=0; i<board_size; i++){
        for (int j=0; j<board_size; j++){
            board[i][j] = seq_10[c++];
        }
    }
    board[ps[0].loc[0]][ps[0].loc[1]] = ps[0].letter;
    board[ps[1].loc[0]][ps[1].loc[1]] = ps[1].letter;
    return;
}

void show_board(const char board[][MAX_BOARD_SIZE]){
    for (int i=0; i<board_size+2; i++){
        for (int j=0; j<board_size+2; j++){
            if(i<2 && j<2){
                cout << ' ';
            } else if(i==0){
                cout << j-2;
            } else if (i==1)
            {
                cout << '-';
            } else if (j==0)
            {
                cout << i-2;
            } else if (j==1){
                cout << '|';
            } else{
                cout << board[i-2][j-2];
            }
        }
        cout << endl;
    }
}

bool check_number(char c){
    int sft = c - '0';
    return sft > 0 && sft < 10;
}

bool check_wasd(char c){
    switch (c)
    {
    case 'w':
    case 'W':
    case 'a':
    case 'A':
    case 's':
    case 'S':
    case 'd':
    case 'D':
        return true;
    
    default:
        return false;
    }
}

/* Given a moving direction, update the Player and the board states.
   Remember to check whether the player is inside the board.
*/
void update(char board[][MAX_BOARD_SIZE], Player& p, char direction){
    // TODO 3

    //up
    if(direction == 'w' || direction == 'W')
    {
        total_step+=1;
        if(check_inside(p))
        {
            board[p.loc[0]][p.loc[1]] = '0';
        }
        p.loc[0]-=1;
        if(check_inside(p))
        {
            if(check_number(board[p.loc[0]][p.loc[1]]))
            {
                p.weight += board[p.loc[0]][p.loc[1]] - '0';        
            }
            board[p.loc[0]][p.loc[1]] = p.letter;
        }
    }

    //down
    if(direction == 's' || direction == 'S')
    {
        total_step+=1;
        if(check_inside(p))
            board[p.loc[0]][p.loc[1]] = '0';
        p.loc[0]+=1;
        if(check_inside(p))
        {
            if(check_number(board[p.loc[0]][p.loc[1]]))
            {
                p.weight += board[p.loc[0]][p.loc[1]] - '0';        
            }
            board[p.loc[0]][p.loc[1]] = p.letter;
        }
    }

    //left
    if(direction == 'a' || direction == 'A')
    {
        total_step+=1;
        if(check_inside(p))
            board[p.loc[0]][p.loc[1]] = '0';
        p.loc[1]-=1;
        if(check_inside(p))
        {
            if(check_number(board[p.loc[0]][p.loc[1]]))
            {
                p.weight += board[p.loc[0]][p.loc[1]] - '0';        
            }
            board[p.loc[0]][p.loc[1]] = p.letter;
        }
    }

    //right
    if(direction == 'd' || direction == 'D')
    {
        total_step+=1;
        if(check_inside(p))
            board[p.loc[0]][p.loc[1]] = '0';
        p.loc[1]+=1;
        if(check_inside(p))
        {
            if(check_number(board[p.loc[0]][p.loc[1]]))
            {
                p.weight += board[p.loc[0]][p.loc[1]] - '0';        
            }
            board[p.loc[0]][p.loc[1]] = p.letter;
        }
    }
}

/* Check whether the game is over. 
   return 0 if unfinished; 1 if p1 wins; 2 if p2 wins; -1 if tie.
*/
int check_win(char board[][MAX_BOARD_SIZE], const Player ps[]){
    // TODO 4

    //if two players moves to same location
    if(ps[0].loc[0]==ps[1].loc[0] && ps[0].loc[1] == ps[1].loc[1])
    {
        if(ps[0].weight>ps[1].weight)
            return 1;
        if(ps[0].weight<ps[1].weight)
            return 2;
        if(ps[0].weight==ps[1].weight)
            return -1;
    }
    //check number of bonus left
    int numOfBonus =0;
    for (int i=0; i<board_size; i++){
        for (int j=0; j<board_size; j++)
        {
            if(check_number(board[i][j]))
            {
                numOfBonus +=1;
            }
        }
    }

    //if all bonus is cleared
    if(numOfBonus==0)
    {
        if(ps[0].weight>ps[1].weight)
            return 1;
        if(ps[0].weight<ps[1].weight)
            return 2;
        if(ps[0].weight==ps[1].weight)
            return -1;
    }
    return 0;
}

/* Check the winning flag. */
bool check_flag(int win_flag, const Player ps[]){
    if(win_flag == 1){
        cout << "Player " << ps[0].letter << " wins the game!" << endl;
        return true;
    } else if (win_flag == 2){
        cout << "Player " << ps[1].letter << " wins the game!" << endl;
        return true;
    } else if (win_flag == -1)
    {
        cout << "The game ties!" << endl;
        return true;
    }
    return false;
}

/* Play game function */
void play_game(Player ps[], char board[][MAX_BOARD_SIZE]){
    Player &p1 = ps[0], &p2 = ps[1];
    int idx;
    char direction;
    int win_flag = 0;
    while(true){
        win_flag = check_win(board, ps);

        show_board(board);
        show_player(p1);
        show_player(p2);

        if (check_flag(win_flag, ps))
            break;
        
        idx = total_step % 2 == 0 ? 0 : 1;
        do{
            cout << "Player " << ps[idx].letter << "\'s moving direction (WASD) is: ";
            cin >> direction;
        } while(!check_wasd(direction));
        
        update(board, ps[idx], direction);
    }
    cout << "Total steps: " << total_step << endl;
}
