#include "BattleArena.h"

int main()
{
    //Some Players added into Clans
    Clan1.emplace_back("Arthur", 100, 20);
    Clan1.emplace_back("Tiberius", 120, 15);

    Clan2.emplace_back("Crassus", 110, 18);
    Clan2.emplace_back("Fabius", 105, 22);

    TotalPlayers = Clan1.size() + Clan2.size();

    std::cout << "\x1B[93mWelcome to the Battle Arena!\033[0m" << std::endl;

    CreateMenu();

    return 0;
}