#include <iostream>
#include<string>
using namespace std;
class ElectronicDevice 
{
public:
    virtual void turn_On()  = 0;   
    virtual void turn_Off()  = 0;  
};

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
