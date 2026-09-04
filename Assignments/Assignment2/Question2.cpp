#include <iostream>
#include <string>

using namespace std;

class Patient
{
private:
    int patientId;
    string name;
    int age;
    string ward;
    const string bloodGroup;

public:

    // Constructor 1: Default Constructor
    Patient()
        : patientId(0),
          name("Unknown"),
          age(0),
          ward("General"),
          bloodGroup("O+")
    {
        cout << "[Constructor] Default patient registered." << endl;
    }


    // Constructor 2: Emergency Admission
    Patient(int id, const string& name)
        : patientId(id),
          name(name),
          age(0),
          ward("Emergency"),
          bloodGroup("O+")
    {
        cout << "[Constructor] Emergency: " << name << endl;
    }


    // Constructor 3: Full Admission
    Patient(int id,
            const string& name,
            int age,
            const string& ward,
            const string& bg)
        : patientId(id),
          name(name),
          age(age),
          ward(ward),
          bloodGroup(bg)
    {
        cout << "[Constructor] Full admission: " << name << endl;
    }


    // Destructor
    ~Patient()
    {
        cout << "[Destructor] Patient "
             << name
             << " discharged."
             << endl;
    }


    // Display patient record
    void displayRecord() const
    {
        cout << "Patient Record:" << endl;
        cout << "ID : " << patientId << endl;
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Ward : " << ward << endl;
        cout << "Blood Grp : " << bloodGroup << endl;
    }


    // Transfer patient to another ward
    void transferWard(const string& newWard)
    {
        cout << "Ward Transfer: "
             << name
             << " -> "
             << newWard
             << endl;

        ward = newWard;
    }
};


int main()
{
    cout << "===== STACK PATIENTS =====" << endl;

    // 1. Three stack objects using different constructors

    Patient p1(
        1001,
        "Meera Joshi",
        34,
        "Cardiology",
        "B+"
    );

    Patient p2(
        1002,
        "Raj Patel"
    );

    Patient p3;


    cout << "\n===== DYNAMIC PATIENT ARRAY =====" << endl;

    // 2. Dynamic array of 4 Patient objects
    Patient* patients = new Patient[4];


    // 3. Display all 4 patients
    cout << "\n===== PATIENT RECORDS =====" << endl;

    for (int i = 0; i < 4; i++)
    {
        patients[i].displayRecord();
        cout << endl;
    }


    // 4. Transfer one patient's ward
    patients[1].transferWard("ICU");


    // 5. Delete dynamic array
    cout << "\n===== DELETING DYNAMIC ARRAY =====" << endl;

    delete[] patients;


    cout << "\n===== END OF MAIN =====" << endl;

    return 0;
}