#include <iostream>
#include <math.h>
using namespace std;

const int AP_NUM = 5;
const int MAX_K = 5;
const int MAX_GRID_PTS_PER_LINE = 8;
const int TOTAL_GRID = MAX_GRID_PTS_PER_LINE * MAX_GRID_PTS_PER_LINE; // Square grid.

// Calculate cosine similarity between signals from a SINGLE grid point (reference) and the target.
double cosine_similarity(const double ref_signal[], const double target_signal[]);

// Find top k nearest neighbors of target from all grid points (references) using cosine similarity.
void k_nearest_neighbor(int knn[], const double similarity[], int k, int current_total_grid_pts);

// Convert grid index to coordinates. A helper function that can be used in cetnroid calculation.
void convert2D(int index, int& i, int& j, int grid_pts_per_line);

// Find centroid coordinates of k nearest neighbors.
void centroid(int knn[], double& centroid_x, double& centroid_y, int k, int grid_pts_per_line);

// Find the target location with reference point signals and target signals.
void do_localization(const double ref_signals[], const double target_signals[], int k, int grid_pts_per_line);


int main()
{   
    int choice;
    int k, grid_pts_per_line;

    double ref_signals_all[AP_NUM * 64] = {-162.5,-175.504,-101.438,-42.6599,-80.398,-158.5,-152.483,-85.6827,-50.4156,-95.4192,-156.5,-131.461,-71.927,-60.1713,-112.44,-156.5,-112.44,-60.1713,-71.927,-131.461,-158.5,-95.4192,-50.4156,-85.6827,-152.483,-162.5,-80.398,-42.6599,-101.438,-175.504,-168.5,-67.3769,-36.9042,-119.194,-200.525,-176.5,-56.3558,-33.1485,-138.95,-227.546,-138.5,-165.323,-113.619,-54.8402,-70.2177,-134.5,-142.302,-97.8631,-62.5959,-85.2388,-132.5,-121.281,-84.1073,-72.3516,-102.26,-132.5,-102.26,-72.3516,-84.1073,-121.281,-134.5,-85.2388,-62.5959,-97.863,-142.302,-138.5,-70.2177,-54.8402,-113.619,-165.323,-144.5,-57.1965,-49.0845,-131.374,-190.344,-152.5,-46.1754,-45.3288,-151.13,-217.366,-116.5,-157.143,-127.799,-69.0206,-62.0373,-112.5,-134.122,-112.043,-76.7763,-77.0585,-110.5,-113.101,-98.2877,-86.532,-94.0796,-110.5,-94.0796,-86.532,-98.2877,-113.101,-112.5,-77.0585,-76.7763,-112.043,-134.122,-116.5,-62.0373,-69.0206,-127.799,-157.143,-122.5,-49.0162,-63.2649,-145.555,-182.164,-130.5,-37.9951,-59.5092,-165.311,-209.185,-96.5,-150.963,-143.979,-85.2009,-55.857,-92.5,-127.942,-128.224,-92.9566,-70.8781,-90.5,-106.92,-114.468,-102.712,-87.8993,-90.5,-87.8993,-102.712,-114.468,-106.92,-92.5,-70.8781,-92.9566,-128.224,-127.942,-96.5,-55.857,-85.2009,-143.979,-150.963,-102.5,-42.8359,-79.4452,-161.735,-175.984,-110.5,-31.8147,-75.6895,-181.491,-203.005,-78.5,-146.782,-162.16,-103.381,-51.6767,-74.5,-123.761,-146.404,-111.137,-66.6978,-72.5,-102.74,-132.648,-120.893,-83.7189,-72.5,-83.7189,-120.893,-132.648,-102.74,-74.5,-66.6978,-111.137,-146.404,-123.761,-78.5,-51.6767,-103.381,-162.16,-146.782,-84.5,-38.6555,-97.6255,-179.915,-171.803,-92.5,-27.6344,-93.8698,-199.671,-198.825,-62.5,-144.602,-182.34,-123.562,-49.4963,-58.5,-121.581,-166.584,-131.317,-64.5174,-56.5,-100.56,-152.829,-141.073,-81.5386,-56.5,-81.5386,-141.073,-152.829,-100.56,-58.5,-64.5174,-131.317,-166.584,-121.581,-62.5,-49.4963,-123.562,-182.34,-144.602,-68.5,-36.4752,-117.806,-200.096,-169.623,-76.5,-25.4541,-114.05,-219.852,-196.644,-48.5,-144.422,-204.52,-145.742,-49.316,-44.5,-121.4,-188.765,-153.498,-64.3371,-42.5,-100.379,-175.009,-163.253,-81.3582,-42.5,-81.3582,-163.253,-175.009,-100.379,-44.5,-64.3371,-153.498,-188.765,-121.4,-48.5,-49.316,-145.742,-204.52,-144.422,-54.5,-36.2948,-139.986,-222.276,-169.443,-62.5,-25.2737,-136.231,-242.032,-196.464,-36.5,-146.241,-228.701,-169.922,-51.1356,-32.5,-123.22,-212.945,-177.678,-66.1568,-30.5,-102.199,-199.189,-187.434,-83.1779,-30.5,-83.1779,-187.434,-199.189,-102.199,-32.5,-66.1568,-177.678,-212.945,-123.22,-36.5,-51.1356,-169.922,-228.701,-146.241,-42.5,-38.1145,-164.167,-246.456,-171.262,-50.5,-27.0934,-160.411,-266.212,-198.284};
    double target_signals[AP_NUM] = {-78.17,-10.3314,-144.037,-294.51,-253.802};   
    
    while (true) 
    {
        cout << "Please input the case you would like to test (0-4): " << endl;
        cin >> choice;

        // Initialization.
        switch (choice)
        {
            case 0: 
                k = 3; grid_pts_per_line = 5;                                                 
                break;
            case 1: 
                k = 4; grid_pts_per_line = 5;    
                break;           
            case 2: 
                k = 5; grid_pts_per_line = 5;                
                break;
            case 3: 
                k = 3; grid_pts_per_line = 6;                
                break;
            case 4: 
                k = 3; grid_pts_per_line = 8;              
                break;             
            default:                
                cout << "Test ended." << endl;            
                return 0;                               
        }
        
        double ref_signals[AP_NUM * TOTAL_GRID];
        for (int m=0; m<AP_NUM * TOTAL_GRID; m++)
        {                
            ref_signals[m] = ref_signals_all[m];
        }
        do_localization(ref_signals, target_signals, k, grid_pts_per_line);
        
    }
}

void do_localization(const double ref_signals[], const double target_signals[], int k, int grid_pts_per_line)
{      
    
    int current_total_grid_pts = grid_pts_per_line * grid_pts_per_line;
    double similarity[TOTAL_GRID]; // Cosine similarity between the target and each grid point (reference).    
    int knn[MAX_K]; // Indices of top k nearest neighbors of the target in terms of cosine similarity.    
    double centroid_x, centroid_y; // Predicted (x, y) coordinates of the target.    
    double current_ref_signals[AP_NUM]; // Array to store current grid point signals.

    for (int i=0; i<TOTAL_GRID; i++) similarity[i] = -1;
    // Loop to calculate cosine similarity between the target and each grid point (reference).
    for (int i=0; i<current_total_grid_pts; i++)
    {        
        for (int j=0; j<AP_NUM; j++)
        {
            current_ref_signals[j] = ref_signals[i*AP_NUM+j];
            // cout << "current ref signals : "<< current_ref_signals[j] << endl;
        }
        similarity[i] = cosine_similarity(current_ref_signals, target_signals);   
        // cout << "similarity[" << i << "]" << similarity[i] << endl;
    }
    
    // Get top k indices of grid points (references) with largest consine similarities.
    k_nearest_neighbor(knn, similarity, k, current_total_grid_pts);    

    // Find the centroid coordinates of the top k grid points (references) as the predicted target location.
    centroid(knn, centroid_x, centroid_y, k, grid_pts_per_line);    
    
    cout << "Prediction is (x: " << centroid_x << ", y: " << centroid_y << ")." << endl;
    return;
}

double cosine_similarity(const double ref_signal[], const double target_signal[])
{
    /* TODO1: 
        Calculate cosine similarity between signals from a SINGLE grid point (reference) and the target.  
        
        ref_signals[AP_NUM]: signals collected at a single grid point.
        target_signals[AP_NUM]: signals collected by the target.      

        Hint: you can use sqrt() in <math.h> (already included) to calculate the square root of a value, e.g., a = sqrt(100), then a = 10.
    */
    double dotProduct =0, bottomV=0, bottomVDot =0, cosSimilarity=0; //use equation given in lab
    //loop through the five AP signals for each reference point
    for(int i=0;i<AP_NUM; i++)
    {
        // cout << "Ref signal: " << ref_signal[i] << "  Target: " << target_signal [i] << endl;
        dotProduct += ref_signal[i] * target_signal[i];
        bottomV += pow(ref_signal[i],2.0);
        bottomVDot += pow(target_signal[i],2.0);
    }
    cosSimilarity = dotProduct/(sqrt(bottomV) * sqrt(bottomVDot));
    // cout << cosSimilarity << endl;
    return cosSimilarity;
}

void k_nearest_neighbor(int knn[], const double similarity[], int k, int current_total_grid_pts)
{
    /* TODO 2:
        Find top k nearest neighbors of the target from all grid points (references) using cosine similarity.

        knn[k]: top K indices with largest similarity.
        similarity[total_grid_pts]: cosine similarity between each grid point (reference) and the target.
    */
    int kIndices[current_total_grid_pts]; //array of the indices of all the cosine similarities which will eventually be sorted from largest to smallest
    int temp; //temporary value to use during loop

    //initialize the kIndices
    for(int i=0; i<current_total_grid_pts; i++)
    {
        kIndices[i] =i;
    }

    //compare each index to all other index greater than it (eg. compare 0th index to 1-total), assign the greatest value's index to that index
    for(int i =0; i<current_total_grid_pts-1; i++)
    {
        for(int j =i+1; j<current_total_grid_pts; j++)
        {
            // cout<< "similarity[kIndices[" << i << "]: " << similarity[kIndices[i]] << "  similarity[kIndices[" <<j <<"]: "<< similarity[kIndices[j]] << endl;
            if(similarity[kIndices[i]]<similarity[kIndices[j]])
            {
                temp = kIndices[i];
                kIndices [i] = kIndices[j];
                kIndices[j] = temp;
            }
        }
    }

    
    // for(int i =0;i<current_total_grid_pts; i++)
    // {
    //     cout<<i << " Element: "<< kIndices[i] << endl;
    // }

    //get k number of top value indices
    for(int i=0; i<k; i++)
    {
        knn[i]= kIndices[i];
    }

    return;
}

void convert2D(const int index, int& i, int& j, int grid_pts_per_line)
{
    /* TODO 3:
        Convert grid index to coordinates. A helper function that can be used in cetnroid calculation.
        It is a squared grid. X coordinate increases first until a line is filled.
    */


    for(int row =1; row<=grid_pts_per_line; row++)
    {
        //if the grid point is in that row, break otherwise it will continue looping until it reaches that row
        if(index<grid_pts_per_line*row)
        {
            i=row-1; //i is equal to the current row
            j=index - grid_pts_per_line * (row-1); //j is equal to index minus the amount of grid points per line times the current row
            break; 
        }
    }
    // if(index<grid_pts_per_line)
    // {
    //     i=0;
    //     j=index;
    // }
    // else if(index<grid_pts_per_line *2 && index>grid_pts_per_line)
    // {
    //     i=1;
    //     j=index-grid_pts_per_line;
    // }
    // else if(index<grid_pts_per_line *3 && index> grid_pts_per_line * 2)
    // {
    //     i=2;
    //     j=index-grid_pts_per_line*2;
    // }
    return;
}

void centroid(int knn[], double& centroid_x, double& centroid_y, int k, int grid_pts_per_line)
{
    int ref_i[MAX_K], ref_j[MAX_K];
    for (int m=0; m<k; m++)
    {
        int i = 0, j =0;
        convert2D(knn[m], i, j, grid_pts_per_line);
        ref_i[m] = i;
        ref_j[m] = j;
        cout << k << "th element is (" << i << ", " << j << ")"<< endl; 
    }
    
    double sum_x = 0;
    double sum_y = 0;
    for (int m=0; m<k; m++)
    {
        sum_x += ref_i[m];
        sum_y += ref_j[m];
    }
    cout << "sum_x is " << sum_x << ", sum_y is " << sum_y << endl;
    centroid_x = sum_x / k;
    centroid_y = sum_y / k;
    return;
}