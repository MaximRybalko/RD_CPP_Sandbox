#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Структура для гравця
struct Player {
    std::string name;
    int health;
    int damage;

    Player(const std::string& n, int h, int d) : name(n), health(h), damage(d) {}
};

// Додавання гравця до клану
void add_player(std::vector<Player>& clan, const std::string& name, int health, int damage) {
    clan.emplace_back(name, health, damage);
}

// Видалення гравця з клану
void remove_player(std::vector<Player>& clan, const std::string& name) {
    clan.erase(std::remove_if(clan.begin(), clan.end(),
        [&](const Player& player) { return player.name == name; }), clan.end());
}

// Підрахунок загальної кількості здоров'я в клані
int total_health(const std::vector<Player>& clan) {
    int total = 0;
    for (const Player& player : clan) {
        total += player.health;
    }
    return total;
}

// Підрахунок загальної кількості урону в клані
int total_damage(const std::vector<Player>& clan) {
    int total = 0;
    for (const Player& player : clan) {
        total += player.damage;
    }
    return total;
}

// Функція для симуляції бою
void start_battle(std::vector<Player>& clan0, std::vector<Player>& clan1) {
    int health0 = total_health(clan0);
    int health1 = total_health(clan1);
    int damage0 = total_damage(clan0);
    int damage1 = total_damage(clan1);

    std::cout << "Clan 0: Health = " << health0 << ", Damage = " << damage0 << "\n";
    std::cout << "Clan 1: Health = " << health1 << ", Damage = " << damage1 << "\n";

    // Перевірка результату бою
    if (damage0 >= health1 && damage1 >= health0) {
        std::cout << "Both clans died! It's a draw.\n";
    }
    else if (damage0 >= health1) {
        std::cout << "Clan 0 wins!\n";
    }
    else if (damage1 >= health0) {
        std::cout << "Clan 1 wins!\n";
    }
    else {
        std::cout << "Both clans survived! No winner.\n";
    }

    // Завершення програми після бою
    std::exit(0);
}

// Обробка команд
void process_commands() {
    std::vector<Player> clan0;
    std::vector<Player> clan1;

    while (true) {
        int command;
        std::cin >> command;

        if (command == 0) {
            // Додати гравця
            std::string name;
            int clan_id, health, damage;
            std::cin >> name >> clan_id >> health >> damage;

            if (clan_id == 0) {
                add_player(clan0, name, health, damage);
            }
            else if (clan_id == 1) {
                add_player(clan1, name, health, damage);
            }
        }
        else if (command == 1) {
            // Вилучити гравця
            std::string name;
            int clan_id;
            std::cin >> name >> clan_id;

            if (clan_id == 0) {
                remove_player(clan0, name);
            }
            else if (clan_id == 1) {
                remove_player(clan1, name);
            }
        }
        else if (command == 2) {
            // Провести бій
            start_battle(clan0, clan1);
        }
    }
}

int main() {
    process_commands();
    return 0;
}
