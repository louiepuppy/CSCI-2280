#ifndef PATIENTTYPE_H
#define PATIENTTYPE_H

#include <iostream>
#include "doctorType.h"
#include "dateType.h"
using namespace std;

class patientType : public personType
{
private:
    int patientID;
    dateType DOB;
    doctorType attendingPhysician;
    dateType admitDate;
    dateType dischargeDate;

friend ostream& operator<<(ostream&, patientType&);
friend istream& operator>>(istream&, patientType&);

public:
    void setPatientID(int patientID);
    int getPatientID();
    void setDOB(int month, int day, int year);
    dateType getDOB();
    void setAttendingPhysician(doctorType attendingPhysician);
    doctorType getAttendingPhysician();
    void setAdmitDate(int month, int day, int year);
    dateType getAdmitDate();
    void setDischargeDate(int month, int day, int year);
    dateType getDischargeDate();
    void display();
    patientType();
};

void patientType::setPatientID(int patientID)
{
    this->patientID = patientID;
}

int patientType::getPatientID()
{
    return patientID;
}

void patientType::setDOB(int month, int day, int year)
{
    DOB.setMonth(month);
    DOB.setDay(day);
    DOB.setYear(year);
}

dateType patientType::getDOB()
{
    return DOB;
}

void patientType::setAttendingPhysician(doctorType attendingPhysician)
{
    this->attendingPhysician = attendingPhysician;
}

doctorType patientType::getAttendingPhysician()
{
    return attendingPhysician;
}

void patientType::setAdmitDate(int month, int day, int year)
{
    admitDate.setMonth(month);
    admitDate.setDay(day);
    admitDate.setYear(year);
}

dateType patientType::getAdmitDate()
{
    return admitDate;
}

void patientType::setDischargeDate(int month, int day, int year)
{
    dischargeDate.setMonth(month);
    dischargeDate.setDay(day);
    dischargeDate.setYear(year);
}

dateType patientType::getDischargeDate()
{
    return dischargeDate;
}

void patientType::display()
{
    cout << "Patient: ";
    personType::display();
    cout << endl;
    cout << "Patient ID: " << patientID << endl;
    cout << "Date of Birth: " << DOB.getMonth() << "/" << DOB.getDay() << "/" << DOB.getYear() << endl;
    cout << "Attending Physician: ";
    attendingPhysician.display();
    cout << endl;
    cout << "Admit Date: " << admitDate.getMonth() << "/" << admitDate.getDay() << "/" << admitDate.getYear() << endl;
    cout << "Discharge Date: " << dischargeDate.getMonth() << "/" << dischargeDate.getDay() << "/" << dischargeDate.getYear() << endl;
}

patientType::patientType() : personType()
{
    patientID = 0;
    DOB.setMonth(1);
    DOB.setDay(1);
    DOB.setYear(1969);
    attendingPhysician.setFirstName("");
    attendingPhysician.setLastName("");
    admitDate.setMonth(1);
    admitDate.setDay(1);
    admitDate.setYear(1969);
    dischargeDate.setMonth(1);
    dischargeDate.setDay(1);
    dischargeDate.setYear(1969);
}

ostream& operator<<(ostream& output, patientType& patient)
{
    cout << "Patient: " << patient.getFirstName() << " " << patient.getLastName() << endl;
    cout << "Patient ID: " << patient.getPatientID() << endl;
    cout << "Attending Physician: ";
    patient.getAttendingPhysician().getFirstName();
    cout << " ";
    patient.getAttendingPhysician().getLastName();
    cout << endl;
    cout << "Admit Date: " << patient.getAdmitDate().getMonth() << "/" << patient.getAdmitDate().getDay() << "/" << patient.getAdmitDate().getYear() << endl;
    cout << "Discharge Date: " << patient.getDischargeDate().getMonth() << "/" << patient.getDischargeDate().getDay() << "/" << patient.getDischargeDate().getYear() << endl;
    cout << endl << endl;

    return output;
}

istream& operator>>(istream& input, patientType& patient)
{
    string name;
    cout << "Enter patient information:" << endl;
    cout << "Patient ID: ";
    input >> patient.patientID;
    cout << "First Name: ";
    input >> patient.firstName;
    cout << "Last Name: ";
    input >> patient.lastName;

    cout << "Attending Physician First Name: ";
    input >> name;
    patient.attendingPhysician.setFirstName(name);
    cout << "Attending Physician Last Name: ";
    input >> name;
    patient.attendingPhysician.setLastName(name);

    cout << "Doctor's specialty: ";
    input >> name;
    patient.attendingPhysician.setSpecialty(name);
    return input;
}

#endif // PATIENTTYPE_H