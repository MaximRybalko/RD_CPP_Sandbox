#pragma once

#include <iostream>
#include <vector>

// Player structure
struct Player {
    std::string Name;
    int Health;
    int Damage;

    Player(const std::string& Name, int Health, int Damage);
};

// Functions
void AddPlayer(std::vector<Player>& Clan, const std::string& Name, int Health, int Damage, int ClanNumber);
void AddPlayerToBattle();
void RemovePlayerFromBattle(bool isBattleActive);
void RemovePlayer(int ClanNumber, const std::string& Name);
void StartBattle();
void CreateMenu();
void BattleRound(Player& Player1, Player& Player2, int Round);
void ProcessPlayerDeath(Player& DeadPlayer, int ClanNumber);

// Global variables
extern int TotalPlayers;
extern std::vector<Player> Clan1;
extern std::vector<Player> Clan2;