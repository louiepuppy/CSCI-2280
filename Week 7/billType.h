#ifndef BILLTYPE_H
#define BILLTYPE_H

#include <iostream>
using namespace std;

class billType
{
private:
    int patientID;
    double medicationCost;
    double doctorFee;
    double roomCost;
    double totalCost;

friend bool operator<(billType, billType);
friend bool operator>(billType, billType);
friend bool operator==(billType, billType);

public:
    void setPatientID(int patientID);
    int getPatientID();
    void setMedicationCost(double medicationCost);
    double getMedicationCost();
    void setDoctorFee(double doctorFee);
    double getDoctorFee();
    void setRoomCost(double roomCost);
    double getRoomCost();
    void calculateTotalCost();
    double getTotalCost();
    void displayBill();
    billType(int patientID = 0, double medicationCost = 0.0, double doctorFee = 0.0, double roomCost = 0.0);
};

void billType::setPatientID(int patientID)
{
    this->patientID = patientID;
}

int billType::getPatientID()
{
    return patientID;
}

void billType::setMedicationCost(double medicationCost)
{
    this->medicationCost = medicationCost;
}

double billType::getMedicationCost()
{
    return medicationCost;
}

void billType::setDoctorFee(double doctorFee)
{
    this->doctorFee = doctorFee;
}

double billType::getDoctorFee()
{
    return doctorFee;
}

void billType::setRoomCost(double roomCost)
{
    this->roomCost = roomCost;
}

double billType::getRoomCost()
{
    return roomCost;
}

void billType::calculateTotalCost()
{
    totalCost = medicationCost + doctorFee + roomCost;
}

double billType::getTotalCost()
{
    return totalCost;
}

void billType::displayBill()
{
    cout << "Patient ID: " << patientID << endl;
    cout << "Medication Cost: $" << medicationCost << endl;
    cout << "Doctor Fee: $" << doctorFee << endl;
    cout << "Room Cost: $" << roomCost << endl;
    cout << "--------------------------------" << endl;
    cout << "Total Cost: $" << totalCost << endl << endl << endl;
}

billType::billType(int patientID, double medicationCost, double doctorFee, double roomCost)
{
    this->patientID = patientID;
    this->medicationCost = medicationCost;
    this->doctorFee = doctorFee;
    this->roomCost = roomCost;
    calculateTotalCost();
}

bool operator<(billType b1, billType b2)
{
    return b1.totalCost < b2.totalCost;
}

bool operator>(billType b1, billType b2)
{
    return b1.totalCost > b2.totalCost;
}

bool operator==(billType b1, billType b2)
{
    return b1.totalCost == b2.totalCost;
}

#endif // BILLTYPE_H