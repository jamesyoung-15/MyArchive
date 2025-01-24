#include <iostream>
#include<cmath>

using namespace std;

int BasicSim(float beta, int inf, int duration)
{
// TODO 2: Implement the basic simulator.

    int new_infected = round(inf + (beta * inf));
    //cout << new_infected;
    if(duration > 1)
    {
        return BasicSim(beta,new_infected,duration-1);
    }
    else
    {
        return new_infected;
    }
    //return 0; //temporary for code to compile, you need to modify it 
// End of TODO 2.
   
}

// TODO 3: Modify two parameters in the formal parameter list. Note that you need to use "pass by reference".
void CompSim(float beta, int &inf, int &susc, int population, int duration)
// End of TODO 3.

{
    // TODO 4.
    for (;duration>0; --duration)
    {
        susc = population - inf;
        int new_inf = round((inf * beta * susc)/population);
        inf = new_inf + inf;

        // cout << susc << endl;
        // cout << new_inf << endl;
        // cout << inf << endl;
    }
      
    // End of TODO 4.
}

void SimRange(int population, int duration)
{
    float beta_base;
    cout << "Input base beta:";
    cin >> beta_base;

    float beta_interval;
    cout << "Input interval of beta:";
    cin >> beta_interval;


    int num_steps_of_beta;
    cout << "Input steps of beta:";
    cin >> num_steps_of_beta;

    int inf_base;
    cout << "Input base of infected people:";
    cin >> inf_base;

    int inf_interval;
    cout << "Input interval of infected people:";
    cin >> inf_interval;

    int num_steps_of_interval;
    cout << "Input steps of infected people:";
    cin >> num_steps_of_interval;


    // Print Title  
    cout << "Population:" << population << " Duration:" << duration << endl;
    cout << "=================================================================================" << endl;
    cout << "| Beta\t| Initial infected\t| Final infected\t| Final susceptible\t|" << endl; 
    cout << "=================================================================================" << endl;

    // TODO 5: Use nested loops to output the final number of infected people and parameters 
    //         for different combinations of beta and inf using the compartmental simulator.

    int interval_steps = num_steps_of_interval;
    int original_inf = inf_base;
    int new_inf, new_susc;

    while(num_steps_of_beta>0)
    {
        num_steps_of_interval = interval_steps;
        inf_base = original_inf;
        while(num_steps_of_interval>0)
        {
            new_inf = inf_base;
            CompSim(beta_base, new_inf, new_susc, population, duration);
            new_susc = population - new_inf;
            cout << "| " << beta_base << "\t| "<< inf_base << "\t\t\t| " << new_inf <<"\t\t\t| " << new_susc << "\t\t\t|" <<endl ;

            inf_base += inf_interval;
            num_steps_of_interval -=1;
        }
        beta_base += beta_interval;
        num_steps_of_beta --;
    }
    // End of TODO 5.
}
int main()
{
    int mode;
    float beta;
    int inf; 
    int duration;
    int population;
    int susc;

    cout << "Mode 1: Basic simulator " << endl;
    cout << "Mode 2: Compartmental simulator" << endl;
    cout << "Mode 3: SimRange for compartmental simulator" << endl;

    cout << "Enter mode: "; 
    cin >> mode;
    if (mode == 1){
        cout << "-------------------Basic simulator-------------------"  << endl;
        cout << "Input beta:";
        cin >> beta;
        cout << "Input number of infected persons:" ;
        cin >> inf;
        cout << "Input duration (days):" ;
        cin >> duration;
        // TODO 1: Get the infected number of people after the duration days.
        // End of TODO 1.
        cout << "The number of infected persons after " << duration << " day(s) is " << BasicSim(beta,inf,duration) << endl; 
    }
    else if (mode == 2){
        cout << "-------------------Compartmental simulator-------------------" <<endl;
        cout << "Total population:" ;
        cin >> population;
        cout << "Input duration (days):" ;
        cin >> duration;
        cout << "Input beta:";
        cin >> beta;
        cout << "Input number of infected persons:" ;
        cin >> inf;
        susc = population - inf;
        CompSim(beta, inf, susc, population, duration); 
        cout << "The number of infected persons after " << duration << " days is " << inf << endl; 
    }
    else if (mode == 3){
        cout << "Total population:" ;
        cin >> population;
        cout << "Duration:" ;
        cin >> duration;
        SimRange(population, duration);
    }
    else{
        cout << "Wrong input, please input 1 or 2!";
    }
}
