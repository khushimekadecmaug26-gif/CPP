#include <iostream>
using namespace std;


int range(int temp)
{
    if(temp < 0)
    {
        return -1;
    }
    else if(temp >= 0 && temp <=29)
    {
        return 0;
    }
    if(temp >= 30 && temp <=44)
    {
        return 1;
    }
    if(temp >= 45 && temp <=59)
    {
        return 2;
    }
    if(temp >= 60)
    {
        return 3;
    }
}
 

    int statusLabel(int temp)
    {
        switch(temp)
        {
            case -1:
            cout << "Status        :  SENSOR_ERROR" << endl;
            cout << "Action        :  Sensor fault — check wiring" << endl;
            break;
            case 0:
            cout << "Status        :  NORMAL" << endl;
            cout << "Action        :  No action required" << endl;
            break;
            case 1:
            cout << "Status        :  WARNING" << endl;
            cout << "Action        :  Alert sent to supervisor" << endl;
            break;
            case 2:
            cout << "Status        :  CRITICAL" << endl;
            cout << "Action        :  Cooling system triggered" << endl;
            break;
            case 3:
            cout << "Status        :  SHUTDOWN" << endl;
            cout << "Action        :  Emergency shutdown initiated" << endl;
            break;
            
        }
  }
int main()
{
    double reading;
    cout << "Enter The Sensor Reading : ";
    cin >> reading;  //47.3

    double Fahrenheit = (reading * 9 / 5) + 32;      //(47.3 * 9/5) + 32 = 117.14
    cout << "Tempertature  : " << reading << " / " << Fahrenheit << endl;

    int temp = range(reading);  
    statusLabel(temp);

    (reading > 25)? cout << "Reading       :  Above Average" : cout << "Reading       :  Below Average" << endl;

}