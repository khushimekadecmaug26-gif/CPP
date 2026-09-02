#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "Usage: ./sensor_monitor <warn_threshold> <critical_threshold> <num_readings>" << endl;
        cout << "Error: Missing arguments." << endl;
        return 1;
    }

    double warn_threshold = stod(argv[1]);
    double critical_threshold = stod(argv[2]);
    int num_readings = stoi(argv[3]);

    if (warn_threshold >= critical_threshold) {
        cout << "Error: Warning threshold must be less than critical threshold." << endl;
        return 1;
    }
    if (num_readings < 1 || num_readings > 500) {
        cout << "Error: Number of readings must be between 1 and 500." << endl;
        return 1;
    }

    cout << "Config : Warn=" << warn_threshold 
         << "°C Critical=" << critical_threshold 
         << "°C Readings=" << num_readings << endl;

    int normal = 0, warning = 0, critical = 0, shutdown = 0;

    cout << "Enter " << num_readings << " temperature readings:" << endl;
    for (int i = 0; i < num_readings; i++) {
        double temp;
        cin >> temp; // Take temperature directly from input

        if (temp < warn_threshold) {
            normal++;
        } else if (temp < critical_threshold) {
            warning++;
        } else if (temp < 60) {
            critical++;
        } else {
            shutdown++;
        }
    }

    cout << "Results: Normal:" << normal 
         << " Warning:" << warning 
         << " Critical:" << critical 
         << " Shutdown:" << shutdown << endl;

    return 0;
}

