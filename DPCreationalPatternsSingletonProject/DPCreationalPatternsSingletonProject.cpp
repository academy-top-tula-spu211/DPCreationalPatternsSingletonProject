// DPCreationalPatternsSingletonProject.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>

#include "Singleton.h"

void ComputerLaunch(std::string name)
{
    Computer* computer = new Computer();
    computer->Launch(name);
    std::cout << computer->OS()->Name() << "\n";
}

int main()
{
    /*Computer* computer1 = new Computer();
    computer1->Launch("Linux");

    std::cout << computer1->OS()->Name() << "\n";

    Computer* computer2 = new Computer();
    computer2->Launch("Windows");
    std::cout << computer2->OS()->Name() << "\n";

    Computer* computer3 = new Computer();
    computer3->Launch("MacOs");
    std::cout << computer3->OS()->Name() << "\n";*/

    std::thread th1(ComputerLaunch, "Linux");
    std::thread th2(ComputerLaunch, "Windows");

    th2.join();
    th1.join();
}
