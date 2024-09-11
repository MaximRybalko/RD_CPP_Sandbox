#pragma once
#include <iostream>

class Building {

private:	
	int BuildingID, MaxAge, InitialCost, CurrentAge;

	void Destroy();

public:
	Building(int BuildingID, int MaxAge, int InitialCost);

	int GetCost();
	void ToAge(int Years);
    
    int GetCurrentAge() const;
    int GetMaxAge() const;
    int GetId() const;

};