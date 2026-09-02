#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // 1. Declare the 3x3 2D array
    double grid[3][3];

    // 2. Read input into the array using nested loops
    cout << "Enter 9 temperature readings (3 per floor):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> grid[i][j];
        }
    }

    // 3. Display the formatted grid table
    cout << "\n\tRoom 1\tRoom 2\tRoom 3" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Floor " << (i + 1) << " : ";
        for (int j = 0; j < 3; j++) {
            cout << fixed << setprecision(1) << grid[i][j] << "\t";
        }
        cout << endl;
    }

    // 4. Variables to track requirements
    double maxTemp = -1e9; // or grid[0][0]
    int maxFloor = -1, maxRoom = -1;
    
    double highestAvg = -1e9;
    int highestAvgFloor = -1;
    
    int warningCount = 0;

    // 5. Single nested traversal to calculate all metrics
    for (int i = 0; i < 3; i++) {
        double floorSum = 0.0;
        
        for (int j = 0; j < 3; j++) {
            double currentVal = grid[i][j];
            floorSum += currentVal;

            // Check for hottest room
            if (currentVal > maxTemp) {
                maxTemp = currentVal;
                maxFloor = i + 1;  // +1 for 1-based indexing
                maxRoom = j + 1;
            }

            // Check warning threshold (>= 30°C)
            if (currentVal >= 30.0) {
                warningCount++;
            }
        }

        // Calculate floor average and check for highest average floor
        double currentFloorAvg = floorSum / 3.0;
        if (currentFloorAvg > highestAvg) {
            highestAvg = currentFloorAvg;
            highestAvgFloor = i + 1;
        }
    }

    // 6. Print the summary report
    cout << "\nHottest Room              : Floor " << maxFloor << ", Room " << maxRoom 
         << " -> " << fixed << setprecision(1) << maxTemp << "°C" << endl;
         
    cout << "Hottest Floor             : Floor " << highestAvgFloor 
         << " (avg " << fixed << setprecision(2) << highestAvg << "°C)" << endl;
         
    cout << "Rooms at WARNING or above : " << warningCount << endl;

    return 0;
}