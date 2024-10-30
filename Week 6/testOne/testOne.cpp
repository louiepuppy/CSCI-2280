#include <iostream>
#include "patientType.h"

using namespace std;


int main()
{
    patientType p1, p2;

    cout << "Enter patient 1's data:" << endl;
    cin >> p1;
    cout << "Patient 1 data:" << endl;
    cout << p1;
    cout << endl;

    // p2.setAdmittanceDate();
    // p2.setAttendingPhysician();
    // p2.setDischargeDate();
    // p2.setPatientAge(48);
    // p2.setPatientDOB();
    // p2.setPatientID(209);
    // p2.updateBill();

    return 0;
}