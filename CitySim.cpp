#include "CitySim.h"

Building::Building(int BuildingID, int MaxAge, int InitialCost)
	: BuildingID(BuildingID), MaxAge(MaxAge), InitialCost(InitialCost), CurrentAge(0) {}

int Building::GetCost()
{
	if (CurrentAge >= MaxAge)
	{
		return 0;
	}

	return InitialCost * (MaxAge - CurrentAge) / MaxAge;
}

void Building::ToAge(int Years)
{
	CurrentAge += Years;

	if(CurrentAge >= MaxAge)
	{
		Destroy();
	}
}

int Building::GetCurrentAge() const
{
	return CurrentAge;
}

int Building::GetMaxAge() const
{
	return MaxAge;
}

int Building::GetId() const
{
	return BuildingID;
}

void Building::Destroy()
{
	std::cout << "Building with ID " << BuildingID << " has been destroyed!" << std::endl;
}
