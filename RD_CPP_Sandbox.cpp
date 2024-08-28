//Robot_Dreams C++ Sandbox

#include <iostream>
#include <array>
#include <thread>
#include <chrono> 
#include <sstream>  

std::string to_string(int value) {
    std::ostringstream os;
    os << value;
    return os.str();
}

void TypeText(const std::string& text, int delay_ms = 50) {
    for (char c : text) {
        std::cout << c;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }
}

int main()
{
    std::string Name;
    float Health;

    std::string Prefix = "\x1B[93m"; // Color for dialogue
    std::string Postfix = "\033[0m";
    std::string Message;

    Message = "[Midnight.\nAfter 10 hours of riding you've finally reached the destination. You see an old man holding a candle lamp and looking at you.]\n" + Prefix + "******: Welcome to the Mistvale Woods, traveler!\n******: The forest awaits your courage and curiosity!\n\nPlease, tell me your name: " + Postfix;
    TypeText(Message, 50);

    std::cin >> Name;

    Message = Prefix + "******: Nice to meet you, " + Name + ". I am Eldric.\nEldric: Have you eaten today? You are looking tired. What is your current Health?: " + Postfix;
    TypeText(Message, 40);

    std::cin >> Health;

    if (Health <= 0)
    {
        Message = "Here is the end of your journey. RIP, " + Name + ".";
        TypeText(Message, 120);
        return 0;
    }

    Health = (Health > 100) ? 100 : Health;

    if (Health < 70)
    {
        std::string Choice;

        Message = Prefix + "Eldric: Oh, you need to heal yourself. Here, take a snack. " + Postfix + "\n\n[An old man offers you an apple]\nTake apple? (Y/N): ";
        TypeText(Message, 50);

        std::cin >> Choice;
        if (Choice == "Y" || Choice == "y")
        {
            Health += 30;

            Message = "[You've taken a juicy apple. It tastes very good. You are feeling better]\n";
            TypeText(Message, 60);
        }
        else
        {
            Message = Prefix + "Hmm, up to you, " + Name + ".\n";
            TypeText(Message, 120);

            Message = "But take a rest as soon as possible today!\n" + Postfix;
            TypeText(Message, 70);
        }
    }
    else
    {
        Message = Prefix + "Good, but take a rest after your trip soon\n" + Postfix;
        TypeText(Message, 50);
    }

    Message = "\nYour Name is: " + Name + "\nYour Health is: " + std::to_string(Health) + "\n";
    TypeText(Message, 30);

    Message = Prefix + "\n\nEldric: Look out, " + Name + "!!!\n" + Postfix;
    TypeText(Message, 30);

    Message = "\n[You've turned around and noticed something in the forest. It looks like a shining sphere. It changes its glowing color from red to blue and back.]\n";
    TypeText(Message, 35);

    float ItemDistance;
    float ItemImpact;

    while (Health > 0)
    {
        Message = "What is the distance to the sphere?: ";
        TypeText(Message, 35);
        std::cin >> ItemDistance;

        Message = "What is the impact of the sphere?: ";
        TypeText(Message, 35);
        std::cin >> ItemImpact;

        if (ItemDistance <= 100 && ItemDistance >= 0)
        {
            float ResultImpact = ItemImpact * (1 - ItemDistance / 100);

            Health += ResultImpact;

            if (Health > 0 && Health < 1)
            {
                Health = 1;
            }
            else if (Health > 100)
            {
                Health = 100;
            }
            else if (Health <= 0)
            {
                Message = "\n\nHere is the end of your journey. RIP, " + Name + ".";
                TypeText(Message, 120);
                return 0;
            }

            Message = "\nYour Health is: " + std::to_string(Health) + "\nAnd the shining sphere is still there. It's moving!!!\n\n";
            TypeText(Message, 30);
        }
        else
        {
            Message = "\nThe shining sphere is far from you but it is still there. And it's moving!!!\n\n";
            TypeText(Message, 30);
        }
    }
}
