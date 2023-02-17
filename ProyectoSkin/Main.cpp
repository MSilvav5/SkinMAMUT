#include "Includes.h"
#include "Functions.h"

using namespace std;

void createAscii()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

    std::cout << "\n" << std::endl;
    std::cout << "    888    888        d8888  .d8888b.  888    d8P 888     888     d8888 8888888b.  8888888 888     888 888b     d888" << std::endl;
    std::cout << "    888    888       d88888 d88P  Y88b 888   d8P  888     888    d88888 888   Y88b   888   888     888 8888b   d8888" << std::endl;
    std::cout << "    888    888      d88P888 888    888 888  d8P   888     888   d88P888 888    888   888   888     888 88888b.d88888" << std::endl;
    std::cout << "    8888888888     d88P 888 888        888d88K    Y88b   d88P  d88P 888 888   d88P   888   888     888 888Y88888P888" << std::endl;
    std::cout << "    888    888    d88P  888 888        8888888b    Y88b d88P  d88P  888 8888888P     888   888     888 888 Y888P 888" << std::endl;
    std::cout << "    888    888   d88P   888 888    888 888  Y88b    Y88o88P  d88P   888 888 T88b     888   888     888 888  Y8P  888" << std::endl;
    std::cout << "    888    888  d8888888888 Y88b  d88P 888   Y88b    Y888P  d8888888888 888  T88b    888   Y88b..d88P  888       888" << std::endl;
    std::cout << "    888    888 d88P     888   Y8888P   888    Y88b    Y8P  d88P     888 888   T88b 8888888   Y88888P   888       888\n\n\n" << std::endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

    std::cout << "       @@@@@@   @@@  @@@  @@@  @@@  @@@      @@@@@@@  @@@  @@@   @@@@@@   @@@  @@@   @@@@@@@@  @@@@@@@@  @@@@@@@   " << std::endl;
    std::cout << "      @@@@@@@   @@@  @@@  @@@  @@@@ @@@     @@@@@@@@  @@@  @@@  @@@@@@@@  @@@@ @@@  @@@@@@@@@  @@@@@@@@  @@@@@@@@  " << std::endl;
    std::cout << "      !@@       @@!  !@@  @@!  @@!@!@@@     !@@       @@!  @@@  @@!  @@@  @@!@!@@@  !@@        @@!       @@!  @@@  " << std::endl;
    std::cout << "      !@!       !@!  @!!  !@!  !@!!@!@!     !@!       !@!  @!@  !@!  @!@  !@!!@!@!  !@!        !@!       !@!  @!@  " << std::endl;
    std::cout << "      !!@@!!    @!@@!@!   !!@  @!@ !!@!     !@!       @!@!@!@!  @!@!@!@!  @!@ !!@!  !@! @!@!@  @!!!:!    @!@!!@!   " << std::endl;
    std::cout << "       !!@!!!   !!@!!!    !!!  !@!  !!!     !!!       !!!@!!!!  !!!@!!!!  !@!  !!!  !!! !!@!!  !!!!!:    !!@!@!    " << std::endl;
    std::cout << "           !:!  !!: :!!   !!:  !!:  !!!     :!!       !!:  !!!  !!:  !!!  !!:  !!!  :!!   !!:  !!:       !!: :!!   " << std::endl;
    std::cout << "          !:!   :!:  !:!  :!:  :!:  !:!     :!:       :!:  !:!  :!:  !:!  :!:  !:!  :!:   !::  :!:       :!:  !:!  " << std::endl;
    std::cout << "      :::: ::   ::   :::  :::  :::  :::      ::: :::  ::   :::  ::   :::  :::  :::  :::::::::  ::::::::  :::  :::  " << std::endl;
    std::cout << "      :: : :    ::   :::  :::  :::  :::       :: :::  ::   :::  ::   :::  :::  :::   :::::::   ::::::::  :::  :::  " << std::endl;
    std::cout << "\n\n" << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    std::cout << "                                                                                       version 2.5 sin contrasena" << std::endl;
    
}

void consoleMsg(string msg)
{
    system("CLS");
    createAscii();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
    cout << msg;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

int main()
{
    bool correctpass = false;
    std::string input;
    std::string password = "mamut";
    /*
       If you open csgo with Sandboxie use "[#] Counter-Strike: Global Offensive [#]" , If you open csgo with MIGI use "CS:GO MIGI".
       In shortly if you open csgo in third party software get CSGO's window name and change 'windowName' Variable..    The cheat will not be injected if you change it to the wrong window name.
    */
    const char windowName[] = "Counter-Strike: Global Offensive - Direct3D 9";
    HWND hwnd = FindWindowA(NULL, windowName);
    DWORD processID;
    GetWindowThreadProcessId(hwnd, &processID);
    pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
    
    //CONTRASEÑA
    std::cout << "                                 CUAL ES MEJOR CLUB DE DISCORD?" << std::endl;
    //do {
    //    std::getline(std::cin, input);
    //} while (input != password);

    //Get Csgo Window
    consoleMsg("Waiting for CS:GO to open...");
    while (true)
    {
        if (hwnd != 0)
        {
            Sleep(500);
            break;
        }
        else
        {
            hwnd = FindWindowA(NULL, windowName);
        }
    }

    //Get Client Base
    consoleMsg("Getting client.dll module adress..");
    do {
        if (clientBase == 0)
        {
            GetWindowThreadProcessId(hwnd, &processID);
        }
        clientBase = getModuleBaseAddress(processID, "client.dll");
        Sleep(500);
    } while (!clientBase);

    //Get Engine Base
    consoleMsg("Getting engine.dll module adress..");
    do {
        if (engineBase == 0)
        {
            GetWindowThreadProcessId(hwnd, &processID);
        }
        engineBase = getModuleBaseAddress(processID, "engine.dll");
        Sleep(500);
    } while (!engineBase);

    if (hwnd && processID)
    {
        consoleMsg("MAMUTskin Listo... Presiona F2 cuando comienze la ronda.");
    }

    auto EnginePointer = readMem<DWORD>(engineBase + dwClientState);
    auto GameState = readMem<int>(EnginePointer + 0x108);
    DWORD localPlayer = readMem<DWORD>(clientBase + dwLocalPlayer);

    otherThreads();
    skinChanger();
}