#include <iostream>
#include <string>
using namespace std;

class Laptop {
private:
    string brand;
    double screenSize;
    string processor;
    int ram;
    int storage;
    double batteryLevel;
    bool isOn;

public:
    // 1. Default Constructor
    Laptop() {
        brand = "Unknown";
        screenSize = 0.0;
        processor = "Not specified";
        ram = 0;
        storage = 0;
        batteryLevel = 100.0;
        isOn = false;
        cout << "Default Constructor: Laptop created with default values.\n";
    }

    // 2. Parameterized Constructor
    Laptop(string b, double s, string p, int r, int st, double battery) {
        brand = b;
        screenSize = s;
        processor = p;
        ram = r;
        storage = st;
        batteryLevel = battery;
        isOn = false;
        cout << "Parameterized Constructor: Laptop created with custom values.\n";
    }

    // 3. Copy Constructor
    Laptop(const Laptop &other) {
        brand = other.brand;
        screenSize = other.screenSize;
        processor = other.processor;
        ram = other.ram;
        storage = other.storage;
        batteryLevel = other.batteryLevel;
        isOn = other.isOn;
        cout << "Copy Constructor: Laptop copied from another laptop.\n";
    }

    // 4. Inline Constructor (short version)
    Laptop(string b, double s) : brand(b), screenSize(s), processor("Not specified"),
                                 ram(8), storage(256), batteryLevel(100.0), isOn(false) {
        cout << "Inline Constructor: Laptop created with brand and screen size only.\n";
    }

    // Destructor
    ~Laptop() {
        cout << "Destructor: " << brand << " is shutting down and resources released.\n";
    }

    // Methods
    void powerOn() {
        if (!isOn) {
            isOn = true;
            cout << brand << " is now powered ON.\n";
        } else {
            cout << brand << " is already ON.\n";
        }
    }

    void powerOff() {
        if (isOn) {
            isOn = false;
            cout << brand << " is now powered OFF.\n";
        } else {
            cout << brand << " is already OFF.\n";
        }
    }

    void openApps(int numApps) {
        if (isOn) {
            batteryLevel -= numApps * 0.5; // reduce battery for each app
            if (batteryLevel < 0) batteryLevel = 0;
            cout << numApps << " apps opened. Battery now at " << batteryLevel << "%.\n";
        } else {
            cout << "Laptop is OFF. Cannot open apps.\n";
        }
    }

    void closeApps(int numApps) {
        if (isOn) {
            batteryLevel += numApps * 0.2; // simulate restoring battery
            if (batteryLevel > 100) batteryLevel = 100;
            cout << numApps << " apps closed. Battery now at " << batteryLevel << "%.\n";
        } else {
            cout << "Laptop is OFF. Cannot close apps.\n";
        }
    }

    void charge(double amount) {
        batteryLevel += amount;
        if (batteryLevel > 100) batteryLevel = 100;
        cout << "Laptop charged. Battery now at " << batteryLevel << "%.\n";
    }

    void printSpecs() {
        cout << "\nLaptop Specifications:\n";
        cout << "Brand: " << brand << "\n";
        cout << "Screen Size: " << screenSize << " inches\n";
        cout << "Processor: " << processor << "\n";
        cout << "RAM: " << ram << " GB\n";
        cout << "Storage: " << storage << " GB\n";
        cout << "Battery Level: " << batteryLevel << "%\n";
        cout << "Power Status: " << (isOn ? "ON" : "OFF") << "\n\n";
    }
};

// Main function to test
int main() {
    // Default constructor
    Laptop l1;
    l1.printSpecs();

    // Parameterized constructor
    Laptop l2("Dell XPS", 15.6, "Intel i7", 16, 512, 85.0);
    l2.printSpecs();

    // Copy constructor
    Laptop l3 = l2;
    l3.printSpecs();

    // Inline constructor
    Laptop l4("MacBook Pro", 16.0);
    l4.printSpecs();

    // Testing methods
    l2.powerOn();
    l2.openApps(5);
    l2.closeApps(2);
    l2.charge(10);
    l2.powerOff();

    return 0;
}
