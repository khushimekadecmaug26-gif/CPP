#include <iostream>
using namespace std;

bool parsePacket(const int* rawData, int size, int** outMin, int** outMax)
{
    if (size <= 0)
        return false;

    int min = 0;
    int max = 0;

    for (int i = 1; i < size; i++)
    {
        if (rawData[i] < rawData[min])
            min = i;

        if (rawData[i] > rawData[max])
            max = i;
    }

    *outMin = (int*)&rawData[min];
    *outMax = (int*)&rawData[max];

    return true;
}

int main()
{
    int packet[] = {45, 12, 67, 8, 55, 31};

    int* minPtr = nullptr;
    int* maxPtr = nullptr;

    if (parsePacket(packet, 6, &minPtr, &maxPtr))
    {
        cout << "Calibration Min : " << *minPtr << endl;
        cout << "Calibration Max : " << *maxPtr << endl;
    }

    return 0;
}