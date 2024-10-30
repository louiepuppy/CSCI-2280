#ifndef STATEPAIR
#define STATEPAIR
using namespace std;

template<typename T1, typename T2>
class StatePair {

// TODO: Define constructors
private:
    T1 userKey;
    T2 userValue;

public:
    StatePair()
    {
    }
    StatePair(T1 userKey, T2 userValue)
   {
        this->userKey = userKey;
        this->userValue = userValue;
   }
   
// TODO: Define mutators, and accessors for StatePair
    void SetKey(T1 key)
    {
        userKey = key;
    }
    T1 GetKey()
    {
        return userKey;
    }
    void SetValue(T2 value)
    {
        userValue = value;
    }
    T2 GetValue()
    {
        return userValue;
    }
	
// TODO: Define PrintInfo() method
    void PrintInfo()
    {
        cout << userKey << ": " << userValue << endl;
    }
};



#endif