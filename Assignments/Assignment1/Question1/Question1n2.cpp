#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "readings entered: ";
    cin>>N;

    double readings[100];
    for(int i = 0; i < N; i++)
    {
        cin>>readings[i];
    }
    int skip = 0;
    cout<<"\n Valid Reading";

    for(int i = 0; i < N; i++)
    {
        if(readings[i] < 0 )
        {
            skip++;
            continue;
        }
        cout<<readings[i] << endl;

    }
    cout << "skipped(error):  "<< skip;


    //step3

    for(int i = 0; i< N; i++)
    {
        if(readings[i] >= 45)
        {
            cout << "First Critical  :  Index " <<i << "->" << readings[i] << "C" << endl;
            break;
        }
    }
    return 0;
}