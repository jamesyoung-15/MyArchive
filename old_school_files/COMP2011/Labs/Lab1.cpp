#include <iostream>
using namespace std;
  
int main()
{
    /*
        There are 4 errors in total. Can you catch them all? :)
  
        See the expected output section on the lab page to see what is expected from the corrected program.
    */

    string number1;

    cout << "Welcome to the exciting, fun, and awesome programming world! " << endl;
    cout << "Enter an odd number, and I can tell something about you! " << endl;
    cin >> number1;
    
    int number = stoi(number1);
    if (number % 2 == 0){ 
        cout << "Hmm... this is not an odd number..." << endl;
    }
    else
    {
        if (number < 0){
            cout << "You seem to be a bit negative... :( Cheer up! " << endl;
        }
        else{
            cout << "You must be very excited! Me too! :)" << endl;
        }
    }
  
    return 0;
}