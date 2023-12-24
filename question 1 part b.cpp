#include <iostream>
#include<string>
using namespace std;
class ElectronicDevice //abstract base class
{
public:
    virtual void turn_On()  = 0;   // Pure virtual function
    virtual void turn_Off()  = 0;  // Pure virtual function
};
//first derived class from base class in public mode
class Television : public ElectronicDevice
 {
public:
    void turn_On()  //override
    {
       cout << "Television is turned on." << endl;
    }

    void turn_Off()
     {
       cout  << "Television is turned off." << endl;
    }
};
//second class derived from base class in public mode
class Laptop : public ElectronicDevice
 {
public:
    void turn_On()
    {
        cout << "Laptop is starting up." << endl;
    }

    void turn_Off()
     {
        cout << "Laptop is shutting down." << endl;
    }
};
int main()
{
    Television tv;
    Laptop laptop;
    ElectronicDevice* device1 = &tv;
    ElectronicDevice* device2 = &laptop;
    cout << "#####FOR TV #####" << endl;
    device1->turn_On();
    device1->turn_Off();
    cout << "##### FOR LAPTOP #####" << endl;
    device2->turn_On();
    device2->turn_Off();
    return 0;
}
