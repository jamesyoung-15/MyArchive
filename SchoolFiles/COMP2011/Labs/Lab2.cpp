#include <iostream>

using namespace std;

int main(){

    // Initializing variables to store the positions of all pieces.
    unsigned int A_x = 0, A_y = 0;
    unsigned int B_x = 1, B_y = 0;
    unsigned int C_x = 2, C_y = 0;

    unsigned int D_x = 0, D_y = 2;
    unsigned int E_x = 1, E_y = 2;
    unsigned int F_x = 2, F_y = 2;

    // Initializing other variables
    unsigned int round = 1;  // The round number of the game.
    char piece = ' '; // Variable to store which piece the player select.
    unsigned int direction = 0; // Variable to store which direction the player select.

    cout << "Game Start!" << endl;

    // Enter a loop until one player wins.
    while(true){
        cout << "Round " << round << endl;

        // This part is for printing the board.
        for(int i=0; i<3; i++) {
            cout << endl;
            for(int j=0; j<3; j++) {
                char pos = (A_x==i && A_y==j)?'A': (B_x==i && B_y==j)?'B':
                (C_x==i && C_y==j)?'C': (D_x==i && D_y==j)?'D':
                (E_x==i && E_y==j)?'E': (F_x==i && F_y==j)?'F':'*';
                cout << pos;
                if (j<2) cout<<"   ";
            }
            cout << endl;
        }

        // Player1 starts first.
        cout << "Player 1:" << endl;

        // TODO 1: Ask the player to input the piece to select and store the input.
        cout << "Please select the piece to move (A,B or C): " <<endl;
        cin >> piece;

        /* TODO 2: Check whether the input is valid. If not, ask the player to input again.
         If the input is valid, get the coordinates of the selected piece. */
        while (piece!='A' && piece != 'B' && piece!= 'C')
        {
            cout << piece << " is not a valid input (choose A, B or C)" <<endl;
            cout << "Please select the piece to move (A,B or C): " <<endl;
            cin >> piece;
        }

        // TODO 3: Ask the player to input the direction to move and store the input.
        cout << "Please select direction to move (0-7):" << endl;
        cin >> direction;

        // TODO 4: Check whether the input is valid. If not, ask the player to input again.
        while(direction<0 || direction>7)
        {
            cout << direction << " is not a valid input (choose 0-7)" <<endl;
            cout << "Please select direction to move (0-7):" << endl;
            cin >> direction;
        }

        //TODO 5 START holy fuck this code is too long probably missed a way to shorten it too redundant
        bool canMove = false; //Boolean variable that indicates if the piece can move to the direction.
        while(!canMove){
            canMove = true;
            
            //piece A
            if(piece == 'A')
            {
                
                int checkposax = A_x;
                int checkposay = A_y;
                
                //debug 
                //cout << "\n Check start: x= " << checkposax << "  y= " << checkposay << endl;

                //check if move does not take piece out of board and if there is line between target and piece
                if (A_x ==0)
                {
                    if (direction == 0 || direction == 1 || direction == 2)
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                    else if (A_y==0)
                    {
                        if(direction ==7 ||direction ==6)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (A_y == 1)
                    {
                        if(direction == 6 || direction == 4)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if(A_y ==2)
                    {
                        if(direction == 3 || direction == 5)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                }
                else if (A_x==1)
                {
                    if (A_y==0)
                    {
                        if(direction==0 || direction ==7 ||direction ==6 ||direction ==4 || direction ==2)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (A_y==2)
                    {
                        if(direction == 2 || direction ==3 || direction ==4 || direction ==0 || direction ==6)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                }
                if (A_x == 2)
                {
                    if (direction == 6 || direction == 5 || direction == 4)
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                    else if (A_y ==0)
                    {
                        if(direction ==0 || direction == 7)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (A_y==1)
                    {
                        if(direction ==0 || direction == 2)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (A_y==2)
                    {
                        if(direction ==2 || direction==3)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                }
                
                //check if target position has another piece
                if (direction == 0)
                {
                    checkposax-=1;
                    checkposay-=1;
                    if((checkposax == B_x && checkposay == B_y) || (checkposax == C_x && checkposay == C_y) || (checkposax == D_x && checkposay == D_y) || (checkposax == E_x && checkposay == E_y) || (checkposax == F_x && checkposay == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if(direction==1)
                {
                    checkposax-=1;
                    if((checkposax == B_x && checkposay == B_y) || (checkposax == C_x && checkposay == C_y) || (checkposax == D_x && checkposay == D_y) || (checkposax == E_x && checkposay == E_y) || (checkposax == F_x && checkposay == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if(direction==2)
                {
                    checkposax-=1;
                    checkposay+=1;
                    if((checkposax == B_x && checkposay == B_y) || (checkposax == C_x && checkposay == C_y) || (checkposax == D_x && checkposay == D_y) || (checkposax == E_x && checkposay == E_y) || (checkposax == F_x && checkposay == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==3)
                {
                    checkposay+=1;
                    if((checkposax == B_x && checkposay == B_y) || (checkposax == C_x && checkposay == C_y) || (checkposax == D_x && checkposay == D_y) || (checkposax == E_x && checkposay == E_y) || (checkposax == F_x && checkposay == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==4)
                {
                    checkposax+=1;
                    checkposay+=1;
                    if((checkposax == B_x && checkposay == B_y) || (checkposax == C_x && checkposay == C_y) || (checkposax == D_x && checkposay == D_y) || (checkposax == E_x && checkposay == E_y) || (checkposax == F_x && checkposay == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==5)
                {
                    checkposax+=1;
                    if((checkposax == B_x && checkposay == B_y) || (checkposax == C_x && checkposay == C_y) || (checkposax == D_x && checkposay == D_y) || (checkposax == E_x && checkposay == E_y) || (checkposax == F_x && checkposay == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==6)
                {
                    checkposax+=1;
                    checkposay-=1;
                    if((checkposax == B_x && checkposay == B_y) || (checkposax == C_x && checkposay == C_y) || (checkposax == D_x && checkposay == D_y) || (checkposax == E_x && checkposay == E_y) || (checkposax == F_x && checkposay == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==7)
                {
                    checkposay-=1;
                    //cout << "\n Check end: x= " << checkposax << "  y= " << checkposay << endl;
                    if((checkposax == B_x && checkposay == B_y) || (checkposax == C_x && checkposay == C_y) || (checkposax == D_x && checkposay == D_y) || (checkposax == E_x && checkposay == E_y) || (checkposax == F_x && checkposay == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                //cout << "\n Check end: x= " << checkposax << "  y= " << checkposay << endl;
            }

            //piece B (copy paste piece A)
            if(piece == 'B')
            {
                
                int checkposbx = B_x;
                int checkposby = B_y;
                
                //debug 
                //cout << "\n Check start: x= " << checkposbx << "  y= " << checkposby << endl;

                //check if move does not take piece out of board and if there is line between target and piece
                if (B_x ==0)
                {
                    if (direction == 0 || direction == 1 || direction == 2)
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                    else if (B_y==0)
                    {
                        if(direction ==7 ||direction ==6)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (B_y == 1)
                    {
                        if(direction == 6 || direction == 4)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if(B_y ==2)
                    {
                        if(direction == 3 || direction == 5)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                }
                else if (B_x==1)
                {
                    if (B_y==0)
                    {
                        if(direction==0 || direction ==7 ||direction ==6 ||direction ==4 || direction ==2)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (B_y==2)
                    {
                        if(direction == 2 || direction ==3 || direction ==4 || direction ==0 || direction ==6)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                }
                if (B_x == 2)
                {
                    if (direction == 6 || direction == 5 || direction == 4)
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                    else if (B_y ==0)
                    {
                        if(direction ==0 || direction == 7)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (B_y==1)
                    {
                        if(direction ==0 || direction == 2)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (B_y==2)
                    {
                        if(direction ==2 || direction==3)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                }
                
                //check if target position has another piece
                if (direction == 0)
                {
                    checkposbx-=1;
                    checkposby-=1;
                    if((checkposbx == A_x && checkposby == A_y) || (checkposbx == C_x && checkposby == C_y) || (checkposbx == D_x && checkposby == D_y) || (checkposbx == E_x && checkposby == E_y) || (checkposbx == F_x && checkposby == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if(direction==1)
                {
                    checkposbx-=1;
                    if((checkposbx == A_x && checkposby == A_y) || (checkposbx == C_x && checkposby == C_y) || (checkposbx == D_x && checkposby == D_y) || (checkposbx == E_x && checkposby == E_y) || (checkposbx == F_x && checkposby == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if(direction==2)
                {
                    checkposbx-=1;
                    checkposby+=1;
                    if((checkposbx == A_x && checkposby == A_y) || (checkposbx == C_x && checkposby == C_y) || (checkposbx == D_x && checkposby == D_y) || (checkposbx == E_x && checkposby == E_y) || (checkposbx == F_x && checkposby == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==3)
                {
                    checkposby+=1;
                    if((checkposbx == A_x && checkposby == A_y) || (checkposbx == C_x && checkposby == C_y) || (checkposbx == D_x && checkposby == D_y) || (checkposbx == E_x && checkposby == E_y) || (checkposbx == F_x && checkposby == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==4)
                {
                    checkposbx+=1;
                    checkposby+=1;
                    if((checkposbx == A_x && checkposby == A_y) || (checkposbx == C_x && checkposby == C_y) || (checkposbx == D_x && checkposby == D_y) || (checkposbx == E_x && checkposby == E_y) || (checkposbx == F_x && checkposby == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==5)
                {
                    checkposbx+=1;
                    if((checkposbx == A_x && checkposby == A_y) || (checkposbx == C_x && checkposby == C_y) || (checkposbx == D_x && checkposby == D_y) || (checkposbx == E_x && checkposby == E_y) || (checkposbx == F_x && checkposby == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==6)
                {
                    checkposbx+=1;
                    checkposby-=1;
                    if((checkposbx == A_x && checkposby == A_y) || (checkposbx == C_x && checkposby == C_y) || (checkposbx == D_x && checkposby == D_y) || (checkposbx == E_x && checkposby == E_y) || (checkposbx == F_x && checkposby == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==7)
                {
                    checkposby-=1;
                    //cout << "\n Check end: x= " << checkposbx << "  y= " << checkposby << endl;
                    if((checkposbx == A_x && checkposby == A_y) || (checkposbx == C_x && checkposby == C_y) || (checkposbx == D_x && checkposby == D_y) || (checkposbx == E_x && checkposby == E_y) || (checkposbx == F_x && checkposby == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                //cout << "\n Check end: x= " << checkposbx << "  y= " << checkposby << endl;
            }

             //piece C (copy and paste from piece A)
            if(piece == 'C')
            {
                
                int checkposcx = C_x;
                int checkposcy = C_y;
                
                //debug 
                //cout << "\n Check start: x= " << checkposcx << "  y= " << checkposcy << endl;

                //check if move does not take piece out of board and if there is line between target and piece
                if (C_x ==0)
                {
                    if (direction == 0 || direction == 1 || direction == 2)
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                    else if (C_y==0)
                    {
                        if(direction ==7 ||direction ==6)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (C_y == 1)
                    {
                        if(direction == 6 || direction == 4)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if(C_y ==2)
                    {
                        if(direction == 3 || direction == 5)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                }
                else if (C_x==1)
                {
                    if (C_y==0)
                    {
                        if(direction==0 || direction ==7 ||direction ==6 ||direction ==4 || direction ==2)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (C_y==2)
                    {
                        if(direction == 2 || direction ==3 || direction ==4 || direction ==0 || direction ==6)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                }
                if (C_x == 2)
                {
                    if (direction == 6 || direction == 5 || direction == 4)
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                    else if (C_y ==0)
                    {
                        if(direction ==0 || direction == 7)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (C_y==1)
                    {
                        if(direction ==0 || direction == 2)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (C_y==2)
                    {
                        if(direction ==2 || direction==3)
                        {
                            canMove = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                }
                
                //check if target position has another piece
                if (direction == 0)
                {
                    checkposcx-=1;
                    checkposcy-=1;
                    if((checkposcx == B_x && checkposcy == B_y) || (checkposcx == A_x && checkposcy == A_y) || (checkposcx == D_x && checkposcy == D_y) || (checkposcx == E_x && checkposcy == E_y) || (checkposcx == F_x && checkposcy == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if(direction==1)
                {
                    checkposcx-=1;
                    if((checkposcx == B_x && checkposcy == B_y) || (checkposcx == A_x && checkposcy == A_y) || (checkposcx == D_x && checkposcy == D_y) || (checkposcx == E_x && checkposcy == E_y) || (checkposcx == F_x && checkposcy == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if(direction==2)
                {
                    checkposcx-=1;
                    checkposcy+=1;
                    if((checkposcx == B_x && checkposcy == B_y) || (checkposcx == A_x && checkposcy == A_y) || (checkposcx == D_x && checkposcy == D_y) || (checkposcx == E_x && checkposcy == E_y) || (checkposcx == F_x && checkposcy == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==3)
                {
                    checkposcy+=1;
                    if((checkposcx == B_x && checkposcy == B_y) || (checkposcx == A_x && checkposcy == A_y) || (checkposcx == D_x && checkposcy == D_y) || (checkposcx == E_x && checkposcy == E_y) || (checkposcx == F_x && checkposcy == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==4)
                {
                    checkposcx+=1;
                    checkposcy+=1;
                    if((checkposcx == B_x && checkposcy == B_y) || (checkposcx == A_x && checkposcy == A_y) || (checkposcx == D_x && checkposcy == D_y) || (checkposcx == E_x && checkposcy == E_y) || (checkposcx == F_x && checkposcy == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==5)
                {
                    checkposcx+=1;
                    if((checkposcx == B_x && checkposcy == B_y) || (checkposcx == A_x && checkposcy == A_y) || (checkposcx == D_x && checkposcy == D_y) || (checkposcx == E_x && checkposcy == E_y) || (checkposcx == F_x && checkposcy == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==6)
                {
                    checkposcx+=1;
                    checkposcy-=1;
                    if((checkposcx == B_x && checkposcy == B_y) || (checkposcx == A_x && checkposcy == A_y) || (checkposcx == D_x && checkposcy == D_y) || (checkposcx == E_x && checkposcy == E_y) || (checkposcx == F_x && checkposcy == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==7)
                {
                    checkposcy-=1;
                    //cout << "\n Check end: x= " << checkposcx << "  y= " << checkposcy << endl;
                    if((checkposcx == B_x && checkposcy == B_y) || (checkposcx == A_x && checkposcy == A_y) || (checkposcx == D_x && checkposcy == D_y) || (checkposcx == E_x && checkposcy == E_y) || (checkposcx == F_x && checkposcy == F_y))
                    {
                        canMove = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                //cout << "\n Check end: x= " << checkposcx << "  y= " << checkposcy << endl;
            }

            


            /* TODO 5: Check if the selected piece can move to the selected direction:
                1. There is no direct line between the original position and the target position of selected piece on the board.
                2. After moving, the piece is out of the board.
                3. There is another piece on the target position.
            If any of above conditions is true, set canMove to false and ask the player to input a direction again.*/
        }
        //TODO 5 END
            

        // TODO 6: Update the position of pieces after moving.

        //piece A
        if(piece=='A')
        {
            if (direction ==0)
            {
                A_x-=1;
                A_y-=1;
            }
            else if(direction == 1)
            {
                A_x-=1;
            }
            else if(direction ==2)
            {
                A_x -=1;
                A_y +=1;
            }
            else if(direction ==3)
            {
                A_y +=1;
            }
            else if(direction ==4)
            {
                A_x+=1;
                A_y+=1;
            }
            else if(direction ==5)
            {
                A_x+=1;
            }
            else if (direction==6)
            {
                A_x+=1;
                A_y-=1;
            }
            else if(direction ==7)
            {
                A_y-=1;
            }
        }

        //piece B
        else if(piece=='B')
        {
            if (direction ==0)
            {
                B_x-=1;
                B_y-=1;
            }
            else if(direction == 1)
            {
                B_x-=1;
            }
            else if(direction ==2)
            {
                B_x -=1;
                B_y +=1;
            }
            else if(direction ==3)
            {
                B_y+=1;
            }
            else if(direction ==4)
            {
                B_x+=1;
                B_y+=1;
            }
            else if(direction ==5)
            {
                B_x+=1;
            }
            else if (direction==6)
            {
                B_x+=1;
                B_y-=1;
            }
            else if(direction ==7)
            {
                B_y-=1;
            }
        }

        //piece C
        else if(piece=='C')
        {
            if (direction ==0)
            {
                C_x-=1;
                C_y-=1;
            }
            else if(direction == 1)
            {
                C_x-=1;
            }
            else if(direction ==2)
            {
                C_x -=1;
                C_y +=1;
            }
            else if(direction ==3)
            {
                C_y +=1;
            }
            else if(direction ==4)
            {
                C_x+=1;
                C_y+=1;
            }
            else if(direction ==5)
            {
                C_x+=1;
            }
            else if (direction==6)
            {
                C_x+=1;
                C_y-=1;
            }
            else if(direction ==7)
            {
                C_y-=1;
            }
        }

        // TODO 7: Check if Player1 wins. If so, exit the loop.

        //all combos when A is at top left corner
        if((A_x == 0 && A_y ==0) && (((B_x == 1 && B_y == 1) && (C_x == 2 && C_y == 2)) || ((B_x == 2 && B_y == 2) && (C_x == 1 && C_y == 1))))
        {
            cout << "Player 1 wins!" << endl;
            for(int i=0; i<3; i++) {
                cout << endl;
                for(int j=0; j<3; j++) {
                    char pos = (A_x==i && A_y==j)?'A': (B_x==i && B_y==j)?'B':
                    (C_x==i && C_y==j)?'C': (D_x==i && D_y==j)?'D':
                    (E_x==i && E_y==j)?'E': (F_x==i && F_y==j)?'F':'*';
                    cout << pos;
                    if (j<2) cout<<"   ";
                }
                cout << endl;
            }
            break;
        }

        //all combos when A is at top right corner
        if((A_x == 0 && A_y ==2) && (((B_x == 1 && B_y == 1) && (C_x == 2 && C_y == 0)) || ((B_x == 2 && B_y == 0) && (C_x == 1 && C_y == 1))))
        {
            cout << "Player 1 wins!" << endl;
            for(int i=0; i<3; i++) {
                cout << endl;
                for(int j=0; j<3; j++) {
                    char pos = (A_x==i && A_y==j)?'A': (B_x==i && B_y==j)?'B':
                    (C_x==i && C_y==j)?'C': (D_x==i && D_y==j)?'D':
                    (E_x==i && E_y==j)?'E': (F_x==i && F_y==j)?'F':'*';
                    cout << pos;
                    if (j<2) cout<<"   ";
                }
                cout << endl;
            }
            break;
        }

        //all combos when A is at middle
        if((A_x == 1 && A_y ==1) && (((B_x == 0 && B_y == 0) && (C_x == 2 && C_y == 2)) || ((B_x == 2 && B_y == 2) && (C_x == 0 && C_y == 0))))
        {
            cout << "Player 1 wins!" << endl;
            for(int i=0; i<3; i++) {
                cout << endl;
                for(int j=0; j<3; j++) {
                    char pos = (A_x==i && A_y==j)?'A': (B_x==i && B_y==j)?'B':
                    (C_x==i && C_y==j)?'C': (D_x==i && D_y==j)?'D':
                    (E_x==i && E_y==j)?'E': (F_x==i && F_y==j)?'F':'*';
                    cout << pos;
                    if (j<2) cout<<"   ";
                }
                cout << endl;
            }
            break;
        }

        //all combos when A is at bottom left corner
        if((A_x == 2 && A_y ==2) && (((B_x == 1 && B_y == 1) && (C_x == 0 && C_y == 0)) || ((B_x == 0 && B_y == 0) && (C_x == 1 && C_y == 1))))
        {
            cout << "Player 1 wins!" << endl;
            for(int i=0; i<3; i++) 
            {
                cout << endl;
            for(int i=0; i<3; i++) {
                cout << endl;
                for(int j=0; j<3; j++) {
                    char pos = (A_x==i && A_y==j)?'A': (B_x==i && B_y==j)?'B':
                    (C_x==i && C_y==j)?'C': (D_x==i && D_y==j)?'D':
                    (E_x==i && E_y==j)?'E': (F_x==i && F_y==j)?'F':'*';
                    cout << pos;
                    if (j<2) cout<<"   ";
                }
                cout << endl;
            }
            break;
            }
        }

        //all combos when A is at bottom right corner
        if((A_x == 2 && A_y ==0) && (((B_x == 1 && B_y == 1) && (C_x == 0 && C_y == 2)) || ((B_x == 0 && B_y == 2) && (C_x == 1 && C_y == 1))))
        {
            cout << "Player 1 wins!" << endl;
            // Printing the board again.
            for(int i=0; i<3; i++) {
                cout << endl;
                for(int j=0; j<3; j++) {
                    char pos = (A_x==i && A_y==j)?'A': (B_x==i && B_y==j)?'B':
                    (C_x==i && C_y==j)?'C': (D_x==i && D_y==j)?'D':
                    (E_x==i && E_y==j)?'E': (F_x==i && F_y==j)?'F':'*';
                    cout << pos;
                    if (j<2) cout<<"   ";
                }
                cout << endl;
            }
            break;
        }

        // Printing the board again.
        for(int i=0; i<3; i++) {
            cout << endl;
            for(int j=0; j<3; j++) {
                char pos = (A_x==i && A_y==j)?'A': (B_x==i && B_y==j)?'B':
                (C_x==i && C_y==j)?'C': (D_x==i && D_y==j)?'D':
                (E_x==i && E_y==j)?'E': (F_x==i && F_y==j)?'F':'*';
                cout << pos;
                if (j<2) cout<<"   ";
            }
            cout << endl;
        }

        cout << "Player 2:" << endl;
        //TODO 8: Repeat the game steps for Player2.

        //copy and paste from above, replace variables

        // TODO 1: Ask the player to input the piece to select and store the input.
        cout << "Please select the piece to move (D,E or F): " <<endl;
        cin >> piece;

        /* TODO 2: Check whether the input is valid. If not, ask the player to input again.
         If the input is valid, get the coordinates of the selected piece. */
        while (piece!='D' && piece != 'E' && piece!= 'F')
        {
            cout << piece << " is not a valid input (choose D, E or F)" <<endl;
            cout << "Please select the piece to move (D,E or F): " <<endl;
            cin >> piece;
        }

        // TODO 3: Dsk the player to input the direction to move and store the input.
        cout << "Please select direction to move (0-7):" << endl;
        cin >> direction;

        // TODO 4: Fheck whether the input is valid. If not, ask the player to input again.
        while(direction<0 || direction>7)
        {
            cout << direction << " is not a valid input (choose 0-7)" <<endl;
            cout << "Please select direction to move (0-7):" << endl;
            cin >> direction;
        }

        bool canMoveP2 = false; //Eoolean variable that indicates if the piece can move to the direction.
        while(!canMoveP2){
            canMoveP2 = true;
            
            //piece D
            if(piece == 'D')
            {
                
                int checkposdx = D_x;
                int checkposdy = D_y;
                
                //debug 
                //cout << "\n Fheck start: x= " << checkposdx << "  y= " << checkposdy << endl;

                //check if move does not take piece out of board and if there is line between target and piece
                if (D_x ==0)
                {
                    if (direction == 0 || direction == 1 || direction == 2)
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                    else if (D_y==0)
                    {
                        if(direction ==7 ||direction ==6)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (D_y == 1)
                    {
                        if(direction == 6 || direction == 4)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if(D_y ==2)
                    {
                        if(direction == 3 || direction == 5)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                }
                else if (D_x==1)
                {
                    if (D_y==0)
                    {
                        if(direction==0 || direction ==7 ||direction ==6 ||direction ==4 || direction ==2)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (D_y==2)
                    {
                        if(direction == 2 || direction ==3 || direction ==4 || direction ==0 || direction ==6)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                }
                if (D_x == 2)
                {
                    if (direction == 6 || direction == 5 || direction == 4)
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                    else if (D_y ==0)
                    {
                        if(direction ==0 || direction == 7)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (D_y==1)
                    {
                        if(direction ==0 || direction == 2)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (D_y==2)
                    {
                        if(direction ==2 || direction==3)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                }
                
                //check if target position has another piece
                if (direction == 0)
                {
                    checkposdx-=1;
                    checkposdy-=1;
                    if((checkposdx == E_x && checkposdy == E_y) || (checkposdx == F_x && checkposdy == F_y) || (checkposdx == A_x && checkposdy == A_y) || (checkposdx == B_x && checkposdy == B_y) || (checkposdx == C_x && checkposdy == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if(direction==1)
                {
                    checkposdx-=1;
                    if((checkposdx == E_x && checkposdy == E_y) || (checkposdx == F_x && checkposdy == F_y) || (checkposdx == A_x && checkposdy == A_y) || (checkposdx == B_x && checkposdy == B_y) || (checkposdx == C_x && checkposdy == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if(direction==2)
                {
                    checkposdx-=1;
                    checkposdy+=1;
                    if((checkposdx == E_x && checkposdy == E_y) || (checkposdx == F_x && checkposdy == F_y) || (checkposdx == A_x && checkposdy == A_y) || (checkposdx == B_x && checkposdy == B_y) || (checkposdx == C_x && checkposdy == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==3)
                {
                    checkposdy+=1;
                    if((checkposdx == E_x && checkposdy == E_y) || (checkposdx == F_x && checkposdy == F_y) || (checkposdx == A_x && checkposdy == A_y) || (checkposdx == B_x && checkposdy == B_y) || (checkposdx == C_x && checkposdy == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==4)
                {
                    checkposdx+=1;
                    checkposdy+=1;
                    if((checkposdx == E_x && checkposdy == E_y) || (checkposdx == F_x && checkposdy == F_y) || (checkposdx == A_x && checkposdy == A_y) || (checkposdx == B_x && checkposdy == B_y) || (checkposdx == C_x && checkposdy == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==5)
                {
                    checkposdx+=1;
                    if((checkposdx == E_x && checkposdy == E_y) || (checkposdx == F_x && checkposdy == F_y) || (checkposdx == A_x && checkposdy == A_y) || (checkposdx == B_x && checkposdy == B_y) || (checkposdx == C_x && checkposdy == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==6)
                {
                    checkposdx+=1;
                    checkposdy-=1;
                    if((checkposdx == E_x && checkposdy == E_y) || (checkposdx == F_x && checkposdy == F_y) || (checkposdx == A_x && checkposdy == A_y) || (checkposdx == B_x && checkposdy == B_y) || (checkposdx == C_x && checkposdy == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==7)
                {
                    checkposdy-=1;
                    //cout << "\n Fheck end: x= " << checkposdx << "  y= " << checkposdy << endl;
                    if((checkposdx == E_x && checkposdy == E_y) || (checkposdx == F_x && checkposdy == F_y) || (checkposdx == A_x && checkposdy == A_y) || (checkposdx == B_x && checkposdy == B_y) || (checkposdx == C_x && checkposdy == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                //cout << "\n Fheck end: x= " << checkposdx << "  y= " << checkposdy << endl;
            }

            //piece E (copy paste piece D)
            if(piece == 'E')
            {
                
                int checkposex = E_x;
                int checkposey = E_y;
                
                //debug 
                //cout << "\n Fheck start: x= " << checkposex << "  y= " << checkposey << endl;

                //check if move does not take piece out of board and if there is line between target and piece
                if (E_x ==0)
                {
                    if (direction == 0 || direction == 1 || direction == 2)
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                    else if (E_y==0)
                    {
                        if(direction ==7 ||direction ==6)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (E_y == 1)
                    {
                        if(direction == 6 || direction == 4)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if(E_y ==2)
                    {
                        if(direction == 3 || direction == 5)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                }
                else if (E_x==1)
                {
                    if (E_y==0)
                    {
                        if(direction==0 || direction ==7 ||direction ==6 ||direction ==4 || direction ==2)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (E_y==2)
                    {
                        if(direction == 2 || direction ==3 || direction ==4 || direction ==0 || direction ==6)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                }
                if (E_x == 2)
                {
                    if (direction == 6 || direction == 5 || direction == 4)
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                    else if (E_y ==0)
                    {
                        if(direction ==0 || direction == 7)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (E_y==1)
                    {
                        if(direction ==0 || direction == 2)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (E_y==2)
                    {
                        if(direction ==2 || direction==3)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                }
                
                //check if target position has another piece
                if (direction == 0)
                {
                    checkposex-=1;
                    checkposey-=1;
                    if((checkposex == D_x && checkposey == D_y) || (checkposex == F_x && checkposey == F_y) || (checkposex == A_x && checkposey == A_y) || (checkposex == B_x && checkposey == B_y) || (checkposex == C_x && checkposey == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if(direction==1)
                {
                    checkposex-=1;
                    if((checkposex == D_x && checkposey == D_y) || (checkposex == F_x && checkposey == F_y) || (checkposex == A_x && checkposey == A_y) || (checkposex == B_x && checkposey == B_y) || (checkposex == C_x && checkposey == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if(direction==2)
                {
                    checkposex-=1;
                    checkposey+=1;
                    if((checkposex == D_x && checkposey == D_y) || (checkposex == F_x && checkposey == F_y) || (checkposex == A_x && checkposey == A_y) || (checkposex == B_x && checkposey == B_y) || (checkposex == C_x && checkposey == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==3)
                {
                    checkposey+=1;
                    if((checkposex == D_x && checkposey == D_y) || (checkposex == F_x && checkposey == F_y) || (checkposex == A_x && checkposey == A_y) || (checkposex == B_x && checkposey == B_y) || (checkposex == C_x && checkposey == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==4)
                {
                    checkposex+=1;
                    checkposey+=1;
                    if((checkposex == D_x && checkposey == D_y) || (checkposex == F_x && checkposey == F_y) || (checkposex == A_x && checkposey == A_y) || (checkposex == B_x && checkposey == B_y) || (checkposex == C_x && checkposey == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==5)
                {
                    checkposex+=1;
                    if((checkposex == D_x && checkposey == D_y) || (checkposex == F_x && checkposey == F_y) || (checkposex == A_x && checkposey == A_y) || (checkposex == B_x && checkposey == B_y) || (checkposex == C_x && checkposey == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==6)
                {
                    checkposex+=1;
                    checkposey-=1;
                    if((checkposex == D_x && checkposey == D_y) || (checkposex == F_x && checkposey == F_y) || (checkposex == A_x && checkposey == A_y) || (checkposex == B_x && checkposey == B_y) || (checkposex == C_x && checkposey == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==7)
                {
                    checkposey-=1;
                    //cout << "\n Fheck end: x= " << checkposex << "  y= " << checkposey << endl;
                    if((checkposex == D_x && checkposey == D_y) || (checkposex == F_x && checkposey == F_y) || (checkposex == A_x && checkposey == A_y) || (checkposex == B_x && checkposey == B_y) || (checkposex == C_x && checkposey == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                //cout << "\n Fheck end: x= " << checkposex << "  y= " << checkposey << endl;
            }

             //piece F (copy and paste from piece D)
            if(piece == 'F')
            {
                
                int checkposfx = F_x;
                int checkposfy = F_y;
                
                //debug 
                //cout << "\n Fheck start: x= " << checkposfx << "  y= " << checkposfy << endl;

                //check if move does not take piece out of board and if there is line between target and piece
                if (F_x ==0)
                {
                    if (direction == 0 || direction == 1 || direction == 2)
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                    else if (F_y==0)
                    {
                        if(direction ==7 ||direction ==6)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (F_y == 1)
                    {
                        if(direction == 6 || direction == 4)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if(F_y ==2)
                    {
                        if(direction == 3 || direction == 5)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                }
                else if (F_x==1)
                {
                    if (F_y==0)
                    {
                        if(direction==0 || direction ==7 ||direction ==6 ||direction ==4 || direction ==2)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (F_y==2)
                    {
                        if(direction == 2 || direction ==3 || direction ==4 || direction ==0 || direction ==6)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                }
                if (F_x == 2)
                {
                    if (direction == 6 || direction == 5 || direction == 4)
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                    else if (F_y ==0)
                    {
                        if(direction ==0 || direction == 7)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (F_y==1)
                    {
                        if(direction ==0 || direction == 2)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                    else if (F_y==2)
                    {
                        if(direction ==2 || direction==3)
                        {
                            canMoveP2 = false;
                            cout <<"Can't move to direction " << direction <<endl;
                            cout << "Please select direction to move (0-7):" << endl;
                            cin >> direction;
                        }
                    }
                }
                
                //check if target position has another piece
                if (direction == 0)
                {
                    checkposfx-=1;
                    checkposfy-=1;
                    if((checkposfx == E_x && checkposfy == E_y) || (checkposfx == D_x && checkposfy == D_y) || (checkposfx == A_x && checkposfy == A_y) || (checkposfx == B_x && checkposfy == B_y) || (checkposfx == C_x && checkposfy == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if(direction==1)
                {
                    checkposfx-=1;
                    if((checkposfx == E_x && checkposfy == E_y) || (checkposfx == D_x && checkposfy == D_y) || (checkposfx == A_x && checkposfy == A_y) || (checkposfx == B_x && checkposfy == B_y) || (checkposfx == C_x && checkposfy == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if(direction==2)
                {
                    checkposfx-=1;
                    checkposfy+=1;
                    if((checkposfx == E_x && checkposfy == E_y) || (checkposfx == D_x && checkposfy == D_y) || (checkposfx == A_x && checkposfy == A_y) || (checkposfx == B_x && checkposfy == B_y) || (checkposfx == C_x && checkposfy == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==3)
                {
                    checkposfy+=1;
                    if((checkposfx == E_x && checkposfy == E_y) || (checkposfx == D_x && checkposfy == D_y) || (checkposfx == A_x && checkposfy == A_y) || (checkposfx == B_x && checkposfy == B_y) || (checkposfx == C_x && checkposfy == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==4)
                {
                    checkposfx+=1;
                    checkposfy+=1;
                    if((checkposfx == E_x && checkposfy == E_y) || (checkposfx == D_x && checkposfy == D_y) || (checkposfx == A_x && checkposfy == A_y) || (checkposfx == B_x && checkposfy == B_y) || (checkposfx == C_x && checkposfy == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==5)
                {
                    checkposfx+=1;
                    if((checkposfx == E_x && checkposfy == E_y) || (checkposfx == D_x && checkposfy == D_y) || (checkposfx == A_x && checkposfy == A_y) || (checkposfx == B_x && checkposfy == B_y) || (checkposfx == C_x && checkposfy == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==6)
                {
                    checkposfx+=1;
                    checkposfy-=1;
                    if((checkposfx == E_x && checkposfy == E_y) || (checkposfx == D_x && checkposfy == D_y) || (checkposfx == A_x && checkposfy == A_y) || (checkposfx == B_x && checkposfy == B_y) || (checkposfx == C_x && checkposfy == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                else if (direction==7)
                {
                    checkposfy-=1;
                    //cout << "\n Fheck end: x= " << checkposfx << "  y= " << checkposfy << endl;
                    if((checkposfx == E_x && checkposfy == E_y) || (checkposfx == D_x && checkposfy == D_y) || (checkposfx == A_x && checkposfy == A_y) || (checkposfx == B_x && checkposfy == B_y) || (checkposfx == C_x && checkposfy == C_y))
                    {
                        canMoveP2 = false;
                        cout <<"Can't move to direction " << direction <<endl;
                        cout << "Please select direction to move (0-7):" << endl;
                        cin >> direction;
                    }
                }
                //cout << "\n Fheck end: x= " << checkposfx << "  y= " << checkposfy << endl;
            }

            


            /* TODO 5: Fheck if the selected piece can move to the selected direction:
                1. There is no direct line between the original position and the target position of selected piece on the board.
                2. Dfter moving, the piece is out of the board.
                3. There is another piece on the target position.
            If any of above conditions is true, set canMove to false and ask the player to input a direction again.*/
        }
            

        // TODO 6: Update the position of pieces after moving.
        if(piece=='D')
        {
            if (direction ==0)
            {
                D_x-=1;
                D_y-=1;
            }
            else if(direction == 1)
            {
                D_x-=1;
            }
            else if(direction ==2)
            {
                D_x -=1;
                D_y +=1;
            }
            else if(direction ==3)
            {
                D_y +=1;
            }
            else if(direction ==4)
            {
                D_x+=1;
                D_y+=1;
            }
            else if(direction ==5)
            {
                D_x+=1;
            }
            else if (direction==6)
            {
                D_x+=1;
                D_y-=1;
            }
            else if(direction ==7)
            {
                D_y-=1;
            }
        }
        else if(piece=='E')
        {
            if (direction ==0)
            {
                E_x-=1;
                E_y-=1;
            }
            else if(direction == 1)
            {
                E_x-=1;
            }
            else if(direction ==2)
            {
                E_x -=1;
                E_y +=1;
            }
            else if(direction ==3)
            {
                E_y+=1;
            }
            else if(direction ==4)
            {
                E_x+=1;
                E_y+=1;
            }
            else if(direction ==5)
            {
                E_x+=1;
            }
            else if (direction==6)
            {
                E_x+=1;
                E_y-=1;
            }
            else if(direction ==7)
            {
                E_y-=1;
            }
        }
        else if(piece=='F')
        {
            if (direction ==0)
            {
                F_x-=1;
                F_y-=1;
            }
            else if(direction == 1)
            {
                F_x-=1;
            }
            else if(direction ==2)
            {
                F_x -=1;
                F_y +=1;
            }
            else if(direction ==3)
            {
                F_y +=1;
            }
            else if(direction ==4)
            {
                F_x+=1;
                F_y+=1;
            }
            else if(direction ==5)
            {
                F_x+=1;
            }
            else if (direction==6)
            {
                F_x+=1;
                F_y-=1;
            }
            else if(direction ==7)
            {
                F_y-=1;
            }
        }

        // TODO 7: Fheck if Player1 wins. If so, exit the loop.

        //all combos when D is at top left corner
        if((D_x == 0 && D_y ==0) && (((E_x == 1 && E_y == 1) && (F_x == 2 && F_y == 2)) || ((E_x == 2 && E_y == 2) && (F_x == 1 && F_y == 1))))
        {
            cout << "Player 2 wins!" << endl;
            for(int i=0; i<3; i++) {
                cout << endl;
                for(int j=0; j<3; j++) {
                    char pos = (A_x==i && A_y==j)?'A': (B_x==i && B_y==j)?'B':
                    (C_x==i && C_y==j)?'C': (D_x==i && D_y==j)?'D':
                    (E_x==i && E_y==j)?'E': (F_x==i && F_y==j)?'F':'*';
                    cout << pos;
                    if (j<2) cout<<"   ";
                }
                cout << endl;
            }
            break;
        }

        //all combos when D is at top right corner
        if((D_x == 0 && D_y ==2) && (((E_x == 1 && E_y == 1) && (F_x == 2 && F_y == 0)) || ((E_x == 2 && E_y == 0) && (F_x == 1 && F_y == 1))))
        {
            cout << "Player 2 wins!" << endl;
            for(int i=0; i<3; i++) {
                cout << endl;
                for(int j=0; j<3; j++) {
                    char pos = (A_x==i && A_y==j)?'A': (B_x==i && B_y==j)?'B':
                    (C_x==i && C_y==j)?'C': (D_x==i && D_y==j)?'D':
                    (E_x==i && E_y==j)?'E': (F_x==i && F_y==j)?'F':'*';
                    cout << pos;
                    if (j<2) cout<<"   ";
                }
                cout << endl;
            }
            break;
        }

        //all combos when D is at middle
        if((D_x == 1 && D_y ==1) && (((E_x == 0 && E_y == 0) && (F_x == 2 && F_y == 2)) || ((E_x == 2 && E_y == 2) && (F_x == 0 && F_y == 0))))
        {
            cout << "Player 2 wins!" << endl;
            for(int i=0; i<3; i++) {
                cout << endl;
                for(int j=0; j<3; j++) {
                    char pos = (A_x==i && A_y==j)?'A': (B_x==i && B_y==j)?'B':
                    (C_x==i && C_y==j)?'C': (D_x==i && D_y==j)?'D':
                    (E_x==i && E_y==j)?'E': (F_x==i && F_y==j)?'F':'*';
                    cout << pos;
                    if (j<2) cout<<"   ";
                }
                cout << endl;
            }
            break;
        }

        //all combos when D is at bottom left corner
        if((D_x == 2 && D_y ==2) && (((E_x == 1 && E_y == 1) && (F_x == 0 && F_y == 0)) || ((E_x == 0 && E_y == 0) && (F_x == 1 && F_y == 1))))
        {
            cout << "Player 2 wins!" << endl;
            for(int i=0; i<3; i++) {
                cout << endl;
                for(int j=0; j<3; j++) {
                    char pos = (A_x==i && A_y==j)?'A': (B_x==i && B_y==j)?'B':
                    (C_x==i && C_y==j)?'C': (D_x==i && D_y==j)?'D':
                    (E_x==i && E_y==j)?'E': (F_x==i && F_y==j)?'F':'*';
                    cout << pos;
                    if (j<2) cout<<"   ";
                }
                cout << endl;
            }
            break;
        }

        //all combos when D is at bottom right corner
        if((D_x == 2 && D_y ==0) && (((E_x == 1 && E_y == 1) && (F_x == 0 && F_y == 2)) || ((E_x == 0 && E_y == 2) && (F_x == 1 && F_y == 1))))
        {
            cout << "Player 2 wins!" << endl;
            for(int i=0; i<3; i++) {
                cout << endl;
                for(int j=0; j<3; j++) {
                    char pos = (A_x==i && A_y==j)?'A': (B_x==i && B_y==j)?'B':
                    (C_x==i && C_y==j)?'C': (D_x==i && D_y==j)?'D':
                    (E_x==i && E_y==j)?'E': (F_x==i && F_y==j)?'F':'*';
                    cout << pos;
                    if (j<2) cout<<"   ";
                }
                cout << endl;
            }
            break;
        }

        round += 1;
    }
    return 0;
}