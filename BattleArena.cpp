#include "BattleArena.h"
#include <cstdlib>
#include <chrono>
#include <thread>

int TotalPlayers = 0;
std::vector<Player> Clan1;
std::vector<Player> Clan2;

Player::Player(const std::string& Name, int Health, int Damage) : Name(Name), Health(Health), Damage(Damage) {}

void CreateMenu()
{
    //Main menu
    std::cout << "[0]: Add warrior to the battle" << std::endl;
    std::cout << "[1]: Remove warrior from the battle" << std::endl;
    std::cout << "[2]: Let the Battle Begin!" << std::endl;

    int MenuSelect;
    while (!(std::cin >> MenuSelect) || MenuSelect < 0 || MenuSelect > 2) {
        std::cout << "Invalid selection. Please enter a valid option (0, 1, or 2): ";
    }

    switch (MenuSelect)
    {
    case 0:
        AddPlayerToBattle();
        break;
    case 1:
        RemovePlayerFromBattle(false);
        break;
    case 2:
        StartBattle();
        break;
    default:
        break;
    }
}

void AddPlayerToBattle()
{
    std::string Name;
    int ClanNumber, Health, Damage;

    std::cout << "Please enter Player's info.\nName: ";
    std::cin >> Name;

    std::cout << "Clan ID: ";
    std::cin >> ClanNumber;

    std::cout << "Health: ";
    std::cin >> Health;

    std::cout << "Damage: ";
    std::cin >> Damage;

    if (ClanNumber == 1) {
        AddPlayer(Clan1, Name, Health, Damage, ClanNumber);
        TotalPlayers++;
        CreateMenu();
    }
    else if (ClanNumber == 2) {
        AddPlayer(Clan2, Name, Health, Damage, ClanNumber);
        TotalPlayers++;
        CreateMenu();
    }
    else {
        std::cout << "There is no Clan like this!\n";
        CreateMenu();
    }
}

void RemovePlayerFromBattle(bool isBattleActive) {
    std::string Name;
    int ClanNumber;
    std::cout << "Enter Player's Name: ";
    std::cin >> Name;

    std::cout << "Enter Player's Clan: ";
    std::cin >> ClanNumber;

    RemovePlayer(ClanNumber, Name);

    if (!isBattleActive) {
        CreateMenu();
    }
}

void RemovePlayer(int ClanNumber, const std::string& Name)
{
    std::vector<Player>* Clan;

    if (ClanNumber == 1) {
        Clan = &Clan1;
    }
    else if (ClanNumber == 2) {
        Clan = &Clan2;
    }
    else {
        std::cout << "Invalid Clan Number!" << std::endl;
        return;
    }

    auto it = std::find_if(Clan->begin(), Clan->end(), [&](const Player& p) {
        return p.Name == Name;
        });

    if (it != Clan->end()) {
        Clan->erase(it);
        TotalPlayers--;
        std::cout << "Player " << Name << " has been removed from Clan " << ClanNumber << std::endl;
    }
    else {
        std::cout << "Player " << Name << " not found in Clan " << ClanNumber << std::endl;
    }
}

void AddPlayer(std::vector<Player>& Clan, const std::string& Name, int Health, int Damage, int ClanNumber)
{
    Clan.emplace_back(Name, Health, Damage);

    std::cout << "Added Player: " << Name << " to the Clan: " << ClanNumber
        << " with Health: " << Health << " and Damage: " << Damage << std::endl;
}

void StartBattle() {
    if (Clan1.empty() || Clan2.empty()) {
        std::cout << "Both clans must have players to start the battle!\n";
        CreateMenu();
        return;
    }

    int Round = 1;
    while (!Clan1.empty() && !Clan2.empty()) {
        int Player1ID = rand() % Clan1.size();
        int Player2ID = rand() % Clan2.size();
        Player& Player1 = Clan1.at(Player1ID);
        Player& Player2 = Clan2.at(Player2ID);

        BattleRound(Player1, Player2, Round);
        Round++;

        if (Clan1.empty() || Clan2.empty()) {
            break;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Press Enter to continue to the next round...";
        std::cin.get();
        std::cin.get(); //without this second round autostarts. Maybe there is another problem with while cycle...
    }

    if (Clan1.empty()) {
        std::cout << "\x1B[93m\n\nClan 2 has won the battle!\n\n\033[0m";
    }
    else if (Clan2.empty()) {
        std::cout << "\x1B[93m\n\nClan 1 has won the battle!\n\n\033[0m";
    }

    CreateMenu();
}

void BattleRound(Player& Player1, Player& Player2, int Round) {
    std::cout << "\x1B[93m\nRound " << Round << "!\n";
    std::cout << Player1.Name << " (H: " << Player1.Health << " D: " << Player1.Damage << ") vs "
        << Player2.Name << " (H: " << Player2.Health << " D: " << Player2.Damage << ")\033[0m" << std::endl;

    Player2.Health -= Player1.Damage;

    if (Player2.Health > 0) {
        std::cout << Player2.Name << " was attacked by " << Player1.Name << " and got "
            << Player1.Damage << " damage. Now " << Player2.Name << " has "
            << Player2.Health << " Health." << std::endl;

        Player1.Health -= Player2.Damage;

        if (Player1.Health > 0) {
            std::cout << Player1.Name << " was attacked by " << Player2.Name << " and got "
                << Player2.Damage << " damage. Now " << Player1.Name << " has "
                << Player1.Health << " Health." << std::endl;
        }
        else {
            ProcessPlayerDeath(Player1, 1);
        }
    }
    else {
        ProcessPlayerDeath(Player2, 2);
    }
}

void ProcessPlayerDeath(Player& DeadPlayer, int ClanNumber) {
    std::cout << "Player " << DeadPlayer.Name << " has died.\n";
    RemovePlayer(ClanNumber, DeadPlayer.Name);
}