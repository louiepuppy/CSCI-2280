#ifndef PATIENTTYPE_H
#define PATIENTTYPE_H

#include <iostream>
#include "dateType.h"
#include "doctorType.h"
#include "billType.h"
using namespace std;

class patientType : public personType
{
    friend ostream& operator<<(ostream&, patientType&);
    friend istream& operator>>(istream&, patientType&);

    private:
        int patientID;
        int patientAge;
        dateType patientDOB;
        doctorType attendingPhysician;
        dateType admittanceDate;
        dateType dischargeDate;
        billType bill;

    public:
        void setPatientID(int);
        int getPatientID();
        void setPatientAge(int);
        int getPatientAge();
        void setPatientDOB();
        string getPatientDOB();
        void setAttendingPhysician();
        void getAttendingPhysician();
        void setAdmittanceDate();
        string getAdmittanceDate();
        void setDischargeDate();
        string getDischargeDate();
        void showBill();
        void updateBill();
        patientType();
};

void patientType::setPatientID(int pID)
{
    patientID = pID;
    return;
}

int patientType::getPatientID()
{
    return patientID;
}

void patientType::setPatientAge(int pAge)
{
    patientAge = pAge;
    return;
}

int patientType::getPatientAge()
{
    return patientAge;
}

void patientType::setPatientDOB()
{
    int in;
    cout << "Enter month: ";
    cin >> in;
    patientDOB.setMonth(in);
    cout << "Enter day: ";
    cin >> in;
    patientDOB.setDay(in);
    cout << "Enter year: ";
    cin >> in;
    patientDOB.setYear(in);
    return;
}

string patientType::getPatientDOB()
{
    return patientDOB.getDate();
}

void patientType::setAttendingPhysician()
{
    string in;

    cout << "Enter first name of attending physician: ";
    cin.ignore();
    getline(cin, in);
    attendingPhysician.setFirstName(in);
    cout << "Enter last name of attending physician: ";
    getline(cin, in);
    attendingPhysician.setLastName(in);

    return;
}

void patientType::getAttendingPhysician()
{
    attendingPhysician.displayDoctorInfo();
}

void patientType::setAdmittanceDate()
{
    int in;
    cout << "Enter month: ";
    cin >> in;
    admittanceDate.setMonth(in);
    cout << "Enter day: ";
    cin >> in;
    admittanceDate.setDay(in);
    cout << "Enter year: ";
    cin >> in;
    admittanceDate.setYear(in);
    return;
}

string patientType::getAdmittanceDate()
{
    return admittanceDate.getDate();
}

void patientType::setDischargeDate()
{
    int in;
    cout << "Enter month: ";
    cin >> in;
    dischargeDate.setMonth(in);
    cout << "Enter day: ";
    cin >> in;
    dischargeDate.setDay(in);
    cout << "Enter year: ";
    cin >> in;
    dischargeDate.setYear(in);
    return;
}

string patientType::getDischargeDate()
{
    return dischargeDate.getDate();
}

void patientType::showBill()
{
    bill.displayBillInfo();
    return;
}

void patientType::updateBill()
{
    int in;

    cout << "Enter Doctor's fee: ";
    cin >> in;
    bill.setDoctorFee(in);
    cout << "Enter Room cost: ";
    cin >> in;
    bill.setRoomCost(in);
    cout << "Enter Medication costs: ";
    cin >> in;
    bill.setMedicationCosts(in);
    bill.calculateTotalBill();
    return;
}

patientType::patientType()
{
    patientID = 0;
    patientAge = 0;
    attendingPhysician.setFirstName("");
    attendingPhysician.setLastName("");
    admittanceDate.setMonth(0);
    admittanceDate.setDay(0);
    admittanceDate.setYear(0);
    dischargeDate.setMonth(0);
    dischargeDate.setDay(0);
    dischargeDate.setYear(0);
    bill.setDoctorFee(0);
    bill.setRoomCost(0);
    bill.setMedicationCosts(0);
    return;
}

ostream& operator<<(ostream& output, patientType& obj)
{
    output << "Patient: " << obj.getFirstName() << " " << obj.getLastName() << endl;
    output << "ID: " << obj.patientID << endl;
    output << "Age: " << obj.patientAge << endl;
    output << "Date of Birth: " << obj.getPatientDOB() << endl;
    output << "Attending Physician: ";
    obj.getAttendingPhysician();
    output << endl;
    output << "Admittance Date: " << obj.getAdmittanceDate() << endl;
    output << "Discharge Date: " << obj.getDischargeDate() << endl;
    output << "Bill Information:" << endl;
    obj.showBill();
    return output;
}

istream& operator>>(istream& input, patientType& obj)
{
    int in;
    string inString;
    
    cout << "Enter Patient's ID: ";
    cin >> in;
    obj.setPatientID(in);

    cin.ignore();

    cout << "Enter Patient's first name: ";
    getline(cin, inString);
    obj.setFirstName(inString);

    cout << "Enter Patient's last name: ";
    getline(cin, inString);
    obj.setLastName(inString);

    cout << "Enter patient's age: ";
    cin >> in;
    obj.setPatientAge(in);

    cout << "Enter Patient's DOB.";
    obj.setPatientDOB();

    obj.setAttendingPhysician();

    cout << "Enter Admittance Date.";
    obj.setAdmittanceDate();

    cout << "Enter Discharge Date.";
    obj.setDischargeDate();

    obj.updateBill();

    return input;
}



#endif