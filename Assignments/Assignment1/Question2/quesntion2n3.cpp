#include <iostream>
using namespace std;

int main() {

    int statusReg = 0b10110001;
    int controlReg = 0b00000000;
    int dataReg = 0b11001010;

    
    const int* regPtr1 = &statusReg;

    cout << "Status: " << *regPtr1 << endl;

    int* const regPtr2 = &controlReg;

    *regPtr2 = 255;

    cout << "Control: " << *regPtr2 << endl;

    const int* const regPtr3 = &statusReg;

    cout << "Status: " << *regPtr3 << endl;


    return 0;
}