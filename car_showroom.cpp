#include <iostream>
#include <cstring>

using namespace std;

// ANSI escape codes for text color
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

class Car
{
public:
    string make;
    string model;
    int year;
    double price;

    Car(string ma, string mo, int y, double p) : make(ma), model(mo), year(y), price(p) {}

    Car() : make(""), model(""), year(0), price(0.0) {}
};

class Showroom
{
public:
    Car *CarsForSale;
    int numCarsForSale;

    Showroom() : CarsForSale(0), numCarsForSale(0)
    {
        cout << YELLOW;
        addCarForSale(Car("Toyota", "Camry", 2022, 25000.0));
        addCarForSale(Car("Honda", "Accord", 2022, 27000.0));
        cout << RESET;
    }

    void addCarForSale(const Car &car)
    {
        Car *newCars = new Car[numCarsForSale + 1];
        for (int i = 0; i < numCarsForSale; ++i)
        {
            newCars[i] = CarsForSale[i];
        }
        newCars[numCarsForSale++] = car;

        CarsForSale = newCars;
    }

    void displayCarsForSale()
    {
        cout << "Cars for Sale:\n";
        for (int i = 0; i < numCarsForSale; ++i)
        {
            cout << BLUE << "Make: " << CarsForSale[i].make << "\n Model: " << CarsForSale[i].model << "\n Year: "
                 << CarsForSale[i].year << "\n Price: " << CarsForSale[i].price << "\n"
                 << endl;
        }
    }
};

class Revenue
{
private:
    double totalRevenue;

public:
    Revenue() : totalRevenue(0.0) {}

    void updateRevenue(double amount)
    {
        totalRevenue += amount;
    }

    void displayRevenue()
    {
        cout << "Total Revenue: " << totalRevenue << endl;
    }
};

class RepairShop
{
public:
    Car *carsForRepair;
    int numCarsForRepair;
    Revenue revenue;

    RepairShop() : carsForRepair(0), numCarsForRepair(0) {}

    void addCarForRepair(const Car &car)
    {
        Car *newCars = new Car[numCarsForRepair + 1];
        for (int i = 0; i < numCarsForRepair; ++i)
        {
            newCars[i] = carsForRepair[i];
        }
        newCars[numCarsForRepair++] = car;

        carsForRepair = newCars;

        // Update revenue based on the car's price divided by 30000
        double amount = car.price / 3000.0;
        revenue.updateRevenue(amount);
    }

    void displayCarsForRepair()
    {
        cout << "Cars for Repair:\n";
        for (int i = 0; i < numCarsForRepair; ++i)
        {
            cout << GREEN << "Make: "
                 << carsForRepair[i].make << "\nModel: " << carsForRepair[i].model << "\nYear: "
                 << carsForRepair[i].year << "\nPrice: " << carsForRepair[i].price << "\nWorker: Worker" << i + 1 << endl;
        }
    }

    void displayRevenue()
    {
        revenue.displayRevenue();
    }
};

int main()
{
    Showroom showroom;
    RepairShop repairShop;

    int choice;
    do
    {
        cout << RED << "\nMenu:\n";
        cout << "1. Display Cars for Sale\n";
        cout << "2. Submit Car for Repair\n";
        cout << "3. Display Cars for Repair\n";
        cout << "4. Display Revenue\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: " << RESET;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            showroom.displayCarsForSale();
            break;
        }
        case 2:
        {
            string make, model;
            int year;
            int price;

            cout << RED << "Enter car details for repair:\n"
                 << RESET;
            cout << RED << "Make: " << RESET;
            cin >> make;
            cout << RED << "Model: " << RESET;
            cin >> model;
            cout << RED << "Year: " << RESET;
            cin >> year;
            cout << RED << "Price: " << RESET;
            cin >> price;

            Car carForRepair(make, model, year, price);
            repairShop.addCarForRepair(carForRepair);

            cout << RED << "Car submitted for repair.\n"
                 << RESET;
            break;
        }
        case 3:
        {
            repairShop.displayCarsForRepair();
            break;
        }
        case 4:
        {
            repairShop.displayRevenue();
            break;
        }
        case 5:
        {
            cout << GREEN << "Exiting program.\n"
                 << RESET;
            break;
        }
        default:
        {
            cout << BLUE << "Invalid choice. Please try again.\n"
                 << RESET;
            break;
        }
        }

    } while (choice != 5);

    return 0;
}
