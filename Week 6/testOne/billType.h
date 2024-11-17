#ifndef BILLTYPE_H
#define BILLTYPE_H

#include <iostream>
#include <iomanip>
using namespace std;

class billType
{
    private:
        int patientID;
        double medicationCosts;
        double doctorFee;
        double roomCost;
    
    public:
        void setPatientID(int);
        int getPatientID() const;
        void setMedicationCosts(double);
        double getMedicationCosts() const;
        void setDoctorFee(double);
        double getDoctorFee() const;
        void setRoomCost(double);
        double getRoomCost() const;
        double calculateTotalBill() const;
        billType(int pID, double mCosts, double dFee, double rCost);
        billType();
        void displayBillInfo() const;
};

void billType::setPatientID(int pID)
{
    patientID = pID;
    return;
}

int billType::getPatientID() const
{
    return patientID;
}

void billType::setMedicationCosts(double mCosts)
{
    medicationCosts = mCosts;
    return;
}

double billType::getMedicationCosts() const
{
    return medicationCosts;
}

void billType::setDoctorFee(double dFee)
{
    doctorFee = dFee;
    return;
}

double billType::getDoctorFee() const
{
    return doctorFee;
}

void billType::setRoomCost(double rCost)
{
    roomCost = rCost;
    return;
}

double billType::getRoomCost() const
{
    return roomCost;
}

double billType::calculateTotalBill() const
{
    return medicationCosts + doctorFee + roomCost;
}

billType::billType(int pID, double mCosts, double dFee, double rCost)
{
    patientID = pID;
    medicationCosts = mCosts;
    doctorFee = dFee;
    roomCost = rCost;
    return;
}

billType::billType()
{
    patientID = 0;
    medicationCosts = 0.0;
    doctorFee = 0.0;
    roomCost = 0.0;
    return;
}

void billType::displayBillInfo() const
{
    cout << fixed << setprecision(2);
    cout << "Patient ID: " << patientID << endl;
    cout << "Medication Costs: $" << medicationCosts << endl;
    cout << "Doctor Fee: $" << doctorFee << endl;
    cout << "Room Cost: $" << roomCost << endl;
    cout << "----------------------------------------" << endl;
    cout << "Total Bill: $" << calculateTotalBill() << endl;
    return;
}

#endif