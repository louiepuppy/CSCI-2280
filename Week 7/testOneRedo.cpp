#include <iostream>
#include "patientType.h"
#include "billType.h"

using namespace std;

int main()
{
    patientType p1, p2;
    billType b1, b2;

    cin >> p1;

    cout << p1;

    b1.setPatientID(p1.getPatientID());
    b1.setDoctorFee(100);
    b1.setRoomCost(200);
    b1.setMedicationCost(50);
    b1.calculateTotalCost();
    b1.displayBill();

    cin >> p2;

    b2.setPatientID(p2.getPatientID());
    b2.setDoctorFee(150);
    b2.setRoomCost(250);
    b2.setMedicationCost(75);
    b2.calculateTotalCost();
    b2.displayBill();

    "Comparing bills: ";
    if (b1 > b2)
    {
        cout << "Patient 1's bill costs more." << endl;
    }
    else if (b1 < b2)
    {
        cout << "Patient 2's bill costs more." << endl;
    }
    else if (b1 == b2)
    {
        cout << "Both bills cost the same." << endl;
    }

    return 0;
}