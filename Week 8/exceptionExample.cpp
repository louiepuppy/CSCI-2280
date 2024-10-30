#include <iostream>
#include <stdexcept>
#include <iomanip>
using namespace std;

int getWeight()
{
    int weight;

    cout << "Enter your weight (in pounds): ";
    cin >> weight;

    if (weight <= 0)
    {
        throw runtime_error("Invalid weight.");
    }

    return weight;
}

int getHeight()
{
    double height;

    cout << "Enter your height (in inches): ";
    cin >> height;

    if (height <= 0)
    {
        throw runtime_error("Invalid height.");
    }

    return height;
}

double calculateBMI(int weight, int height)
{
    double bmi = static_cast<double>(weight) * 703 / (height * height);
    return bmi;
}

int main()
{
    int weightVal, heightVal;
    float bmiCalc;
    char quitCMD;

    quitCMD = 'a';

    while (quitCMD != 'q')
    {
        try
        {
            weightVal = getWeight();
            heightVal = getHeight();
            bmiCalc = calculateBMI(weightVal, heightVal);

            cout << setprecision(2) << fixed << endl
                 << endl;
            cout << "Your BMI is: " << bmiCalc << endl;
            if (bmiCalc > 25)
            {
                cout << "You are overweight." << endl;
            }
            else if (bmiCalc < 18.5)
            {
                cout << "You are underweight." << endl;
            }
            else
            {
                cout << "You are at a healthy weight." << endl;
            }

            cout << endl
                 << "Enter 'q' to quit, or any other key to continue: ";
            cin >> quitCMD;
            cout << endl;
        }
        catch (const runtime_error &e)
        {
            cout << "Error: " << e.what() << endl;
            continue;
        }
    }

    return 0;
}