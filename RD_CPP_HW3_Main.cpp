#include "CitySim.h"

int main() {
    
    int BuildingID, MaxAge, InitialCost;

    std::cout << "Welcome to CitySim.\nPlease, enter Building's data.\nEnter Building's ID: ";
    std::cin >> BuildingID;

    std::cout << "Enter Building's maximum service life: ";
    std::cin >> MaxAge;

    std::cout << "Enter the cost of the building: ";
    std::cin >> InitialCost;


    Building Building(BuildingID, MaxAge, InitialCost);

    std::cout << "Initial cost of the building: " << Building.GetCost() << " $" << std::endl;

    while (Building.GetCurrentAge() < Building.GetMaxAge())
    {
        int AddAge;
        std::cout << "Add age to the building: ";
        std::cin >> AddAge;

        Building.ToAge(AddAge);
        std::cout << "Cost after " << Building.GetCurrentAge() << "  years: " << Building.GetCost() << " $" << std::endl;
    }

    return 0;
}
