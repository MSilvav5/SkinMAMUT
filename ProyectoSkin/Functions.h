#pragma once
#include "Includes.h"
#include <iostream>
#include <random>
#include <vector>

using namespace std;

/* Memory Functions */
DWORD getModuleBaseAddress(DWORD pid, const char* name)
{
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
    MODULEENTRY32 mEntry;
    mEntry.dwSize = sizeof(MODULEENTRY32);
    do
    {
        if (!strcmp(mEntry.szModule, name))
        {
            CloseHandle(snapshot);
            return (DWORD)mEntry.modBaseAddr;
        }
    } while (Module32Next(snapshot, &mEntry));
}

template <typename T>
T readMem(DWORD address)
{
    T buffer;
    ReadProcessMemory(pHandle, (LPVOID)address, &buffer, sizeof(buffer), 0);
    return buffer;
}

template <typename T>
void writeMem(DWORD address, T value)
{
    WriteProcessMemory(pHandle, (LPVOID)address, &value, sizeof(value), 0);
}

UINT GetModelIndex(const char* modelName)
{
    int ClientState = readMem<UINT>(engineBase + dwClientState);
    int m_pModelPrecacheTable = readMem<UINT>(ClientState + 0x52A4);
    int nsd = readMem<UINT>(m_pModelPrecacheTable + 0x40);
    int m_pItems = readMem<UINT>(nsd + 0xC);
    int xxxxx = m_pItems + 0xC;

    for (UINT i = 0; i < 1024; i++)
    {
        int nsdi_i = readMem<UINT>(xxxxx + (i * 0x34));
        char str[128] = { 0 };
        if (ReadProcessMemory(pHandle, (LPCVOID)nsdi_i, str, sizeof(str), NULL))
        {
            if (_stricmp(str, modelName) == 0)
            {
                return i;
            }
        }
    }
    return 0;
}

UINT GetModelIndexByID(const short knifeID)
{
    UINT modelIndex = 0;
    switch (knifeID)
    {
    case WEAPON_KNIFE:
        modelIndex = GetModelIndex("models/weapons/v_knife_default_ct.mdl");
        break;
    case WEAPON_KNIFE_T:
        modelIndex = GetModelIndex("models/weapons/v_knife_default_t.mdl");
        break;
    case WEAPON_KNIFE_BAYONET:
        modelIndex = GetModelIndex("models/weapons/v_knife_bayonet.mdl");
        break;
    case WEAPON_KNIFE_BUTTERFLY:
        modelIndex = GetModelIndex("models/weapons/v_knife_butterfly.mdl");
        break;
    case WEAPON_KNIFE_CANIS:
        modelIndex = GetModelIndex("models/weapons/v_knife_canis.mdl");
        break;
    case WEAPON_KNIFE_CORD:
        modelIndex = GetModelIndex("models/weapons/v_knife_cord.mdl");
        break;
    case WEAPON_KNIFE_CSS:
        modelIndex = GetModelIndex("models/weapons/v_knife_css.mdl");
        break;
    case WEAPON_KNIFE_FALCHION:
        modelIndex = GetModelIndex("models/weapons/v_knife_falchion_advanced.mdl");
        break;
    case WEAPON_KNIFE_FLIP:
        modelIndex = GetModelIndex("models/weapons/v_knife_flip.mdl");
        break;
    case WEAPON_KNIFE_GUT:
        modelIndex = GetModelIndex("models/weapons/v_knife_gut.mdl");
        break;
    case WEAPON_KNIFE_GYPSY_JACKKNIFE:
        modelIndex = GetModelIndex("models/weapons/v_knife_gypsy_jackknife.mdl");
        break;
    case WEAPON_KNIFE_KARAMBIT:
        modelIndex = GetModelIndex("models/weapons/v_knife_karam.mdl");
        break;
    case WEAPON_KNIFE_M9_BAYONET:
        modelIndex = GetModelIndex("models/weapons/v_knife_m9_bay.mdl");
        break;
    case WEAPON_KNIFE_OUTDOOR:
        modelIndex = GetModelIndex("models/weapons/v_knife_outdoor.mdl");
        break;
    case WEAPON_KNIFE_PUSH:
        modelIndex = GetModelIndex("models/weapons/v_knife_push.mdl");
        break;
    case WEAPON_KNIFE_SKELETON:
        modelIndex = GetModelIndex("models/weapons/v_knife_skeleton.mdl");
        break;
    case WEAPON_KNIFE_STILETTO:
        modelIndex = GetModelIndex("models/weapons/v_knife_stiletto.mdl");
        break;
    case WEAPON_KNIFE_SURVIVAL_BOWIE:
        modelIndex = GetModelIndex("models/weapons/v_knife_survival_bowie.mdl");
        break;
    case WEAPON_KNIFE_TACTICAL:
        modelIndex = GetModelIndex("models/weapons/v_knife_tactical.mdl");
        break;
    case WEAPON_KNIFE_URSUS:
        modelIndex = GetModelIndex("models/weapons/v_knife_ursus.mdl");
        break;
    case WEAPON_KNIFE_WIDOWMAKER:
        modelIndex = GetModelIndex("models/weapons/v_knife_widowmaker.mdl");
        break;
    default:
        break;
    }
    return modelIndex;
}

int Menu()
{
    //aqui irá el menu
    int choice;

    while (true) {
        system("cls"); // borra la pantalla de la consola
        cout << "           MENU PRINCIPAL" << endl;
        cout << "1. CAMBIAR SKIN DE ARMA" << endl;
        cout << "2. CAMBIAR SKIN DE CHUCHILLO" << endl;
        cout << "3. SALIR / CONFIRMAR CAMBIOS" << endl;
        cout << "\nIngrese su eleccion: ";
        cin >> choice;

        switch (choice) {
        case 1:
            while (true) {
                system("cls"); // borra la pantalla de la consola
                cout << "           MENU DE ARMAS" << endl;
                cout << "1. PISTOLAS" << endl;
                cout << "2. ESCOPETAS" << endl;
                cout << "3. RIFLES" << endl;
                cout << "4. Regresar" << endl;
                cout << "\nIngrese su eleccion: ";
                cin >> choice;
                switch (choice) {
                case 1:
                    // codigo para la subopcion 1
                    while (true) {
                        system("cls"); // borra la pantalla de la consola
                        cout << "           MENU DE PISTOLAS" << endl;
                        cout << "1. GLOCK" << endl;
                        cout << "2. USP" << endl;
                        cout << "3. DEAGLE" << endl;
                        cout << "4. REGRESAR" << endl;
                        cout << "\nIngrese su eleccion: ";
                        cin >> choice;
                        switch (choice) {
                        case 1:
                            // codigo para la subsubmenu 1
                            cout << "INGRESA EL ID DE SKIN || RECOMENDACIONES: 988,957,420,963 " << endl;
                            cin >> GLOCK_SKIN;
                            break;
                        case 2:
                            // codigo para la subsubmenu 2
                            cout << "ID DE LA SKIN ||  RECOMENDACIONES: 504,653,1142,1040,705" << endl;
                            cin >> USP_SKIN;
                            break;
                        case 3:
                            // codigo para la subsubmenu 3
                            cout << "ID DE LA SKIN ||  RECOMENDACIONES: 764,470,962,757,711,527" << endl;
                            cin >> DEAGLE_SKIN;
                            break;
                        default:
                            cout << "Opcion invalida. Intentelo de nuevo." << endl;
                            break;
                        }
                        if (choice == 4) {
                            break;
                        }
                        break;
                    }
                    break;
                case 2:
                    // codigo para la subopcion 2
                    while (true) {
                        system("cls"); // borra la pantalla de la consola
                        cout << "MENU DE SUBOPCIONES 1" << endl;
                        cout << "1. Subsubmenu 1" << endl;
                        cout << "2. Subsubmenu 2" << endl;
                        cout << "3. Regresar" << endl;
                        cout << "\nIngrese su eleccion: ";
                        cin >> choice;
                        switch (choice) {
                        case 1:
                            // codigo para la subsubmenu 1
                            cout << "Ha elegido la subsubmenu 1" << endl;
                            break;
                        case 2:
                            // codigo para la subsubmenu 2
                            cout << "Ha elegido la subsubmenu 2" << endl;
                            break;
                        case 3:
                            // salir del bucle while interno y volver al submenu
                            cout << "Volviendo al submenu." << endl;
                            break;
                        default:
                            cout << "Opcion invalida. Intentelo de nuevo." << endl;
                            break;
                        }
                        if (choice == 3) {
                            break;
                        }
                    }
                    break;
                case 3:
                    while (true) {
                        system("cls"); // borra la pantalla de la consola
                        cout << "           MENU DE PISTOLAS" << endl;
                        cout << "1. AK47" << endl;
                        cout << "2. M4A4" << endl;
                        cout << "3. M4A4-SILENCIADA" << endl;
                        cout << "4. AWP" << endl;
                        cout << "5. REGRESAR" << endl;
                        cout << "\nIngrese su eleccion: ";
                        cin >> choice;
                        switch (choice) {
                        case 1:
                            // codigo para la subsubmenu 1
                            cout << "INGRESA EL ID DE SKIN || RECOMENDACIONES: 675,959,707,801,724,1141,600,490" << endl;
                            cin >> AK47_SKIN;
                            break;
                        case 2:
                            // codigo para la subsubmenu 2
                            cout << "ID DE LA SKIN ||  RECOMENDACIONES: 309,695,844,1228,588,255,1041" << endl;
                            cin >> M4A4_SKIN;
                            break;
                        case 3:
                            // codigo para la subsubmenu 3
                            cout << "ID DE LA SKIN ||  RECOMENDACIONES: 946,1073,714,984,430,644,548" << endl;
                            cin >> M4A4S_SKIN;
                            break;
                        case 4:
                            // codigo para la subsubmenu 4
                            cout << "ID DE LA SKIN ||  RECOMENDACIONES: 756,344,1222,819,803,446,662" << endl;
                            cin >> AWP_SKIN;
                            break;
                        default:
                            cout << "Opcion invalida. Intentelo de nuevo." << endl;
                            break;
                        }
                        if (choice == 5) {
                            break;
                        }
                        break;
                    }
                    break;
                case 4:
                    // salir del bucle while interno y volver al menu principal
                    cout << "Volviendo al menu principal." << endl;
                    break;
                default:
                    cout << "Opcion invalida. Intentelo de nuevo." << endl;
                    break;
                }
                if (choice == 4) {
                    break;
                }
                break;
            }
            break;
        case 2:
            while (true) {
                system("cls"); // borra la pantalla de la consola
                cout << "SUBMENU 2" << endl;
                cout << "1. Subopcion 1" << endl;
                cout << "2. Subopcion 2" << endl;
                cout << "3. Regresar" << endl;
                cout << "\nIngrese su eleccion: ";
                cin >> choice;
                switch (choice) {
                case 1:
                    // codigo para la subopcion 1
                    cout << "Ha elegido la subopcion 1" << endl;
                    break;
                case 2:
                    // codigo para la subopcion 2
                    cout << "Ha elegido la subopcion 2" << endl;
                    break;
                case 3:
                    // salir del bucle while interno y volver al menu principal
                    cout << "Volviendo al menu principal." << endl;
                    break;
                default:
                    cout << "Opcion invalida. Intentelo de nuevo." << endl;
                    break;
                }
                if (choice == 3) {
                    break;
                }
            }
            break;
        case 3:
            // salir del programa
            cout << "Saliendo del programa." << endl;
            return 0;
        default:
            cout << "Opcion invalida. Intentelo de nuevo." << endl;
            break;
        }
    }
    return 0;
}

void ForceUpdate()
{
    DWORD _dwClientState = readMem<DWORD>(engineBase + dwClientState);
    writeMem<int>(_dwClientState + 0x174, -1);
    cout << "SE FORZO EL CLIENTE" << endl;
}

void ListaSKIN()
{
    //RIFLE
    if (GetAsyncKeyState(VK_F6) & 1)
    {
        RIFLE_POS = RIFLE_POS + 1;
        EXIT_MENU = true;
        if (RIFLE_POS == RIFLE_ID.size()) {
            RIFLE_POS = 0;
        }
        cout << RIFLE_POS << "\n" << RIFLE_ID.size() << endl;
    }
    //PISTOLA
    if (GetAsyncKeyState(VK_F7) & 1)
    {
        PISTOL_POS = PISTOL_POS + 1;
        EXIT_MENU = true;
        if (PISTOL_POS == PISTOL_ID.size()) {
            PISTOL_POS = 0;
        }
        cout << PISTOL_POS << "\n" << PISTOL_ID.size() << endl;
    }
}



void skinChanger()
{
    
    while (true)
    {
        EXIT_MENU = false;
        if (GetAsyncKeyState(VK_F1) & 1)
        {
            Menu();
            EXIT_MENU = true;
        }
        
        auto EnginePointer = readMem<DWORD>(engineBase + dwClientState);
        auto GameState = readMem<int>(EnginePointer + 0x108);
        DWORD localPlayer = readMem<DWORD>(clientBase + dwLocalPlayer);

        if (GameState == clientState.ingame)
        {
            /* Skin Changer */
            for (int i = 0; i < 8; i++)
            {
                DWORD weaponEntity = readMem<DWORD>(localPlayer + m_hMyWeapons + i * 0x4) & 0xfff;
                weaponEntity = readMem<DWORD>(clientBase + dwEntityList + (weaponEntity - 1) * 0x10);
                int accountID = readMem<int>(weaponEntity + m_OriginalOwnerXuidLow);
                if (weaponEntity == 0) { continue; }

                short weaponID = readMem<int>(weaponEntity + m_iItemDefinitionIndex);
                DWORD Paintkit = 0;
                DWORD Seed = 0;
                DWORD Statrak = 0;
                DWORD Quality = 0;
                float Wear = 0;
                char CustomName[20] = "";

                if (weaponID == 0) { continue; } //Weapons
                 else if (weaponID == WEAPON_GLOCK)
                {
                    PISTOL_ID = GLOCK_LISTA;
                    ListaSKIN();
                    Paintkit = GLOCK_LISTA[PISTOL_POS];
                    Seed = 420;
                    Statrak = 69;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID == WEAPON_USP_SILENCER)
                {
                    PISTOL_ID = USP_LISTA;
                    ListaSKIN();
                    Paintkit = USP_LISTA[PISTOL_POS];
                    Seed = 420;
                    Statrak = 69;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID == WEAPON_DEAGLE)
                {
                    PISTOL_ID = DEAGLE_LISTA;
                    ListaSKIN();
                    Paintkit = DEAGLE_LISTA[PISTOL_POS];
                    Seed = 420;
                    Statrak = 69;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID == WEAPON_AK47)
                {
                    RIFLE_ID = AK47_LISTA;
                    ListaSKIN();
                    Paintkit = AK47_LISTA[RIFLE_POS];
                    Seed = 420;
                    Statrak = 69;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID == WEAPON_AWP)
                {
                    RIFLE_ID = AWP_LISTA;
                    ListaSKIN();
                    Paintkit = AWP_LISTA[RIFLE_POS];
                    Seed = 420;
                    Statrak = 0;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID == WEAPON_M4A1)
                {
                    RIFLE_ID = M4A4_LISTA;
                    ListaSKIN();
                    Paintkit = M4A4_LISTA[RIFLE_POS];
                    Seed = 420;
                    Statrak = 69;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID == WEAPON_M4A1_SILENCER)
                {
                    RIFLE_ID = M4A4S_LISTA;
                    ListaSKIN();
                    Paintkit = M4A4S_LISTA[RIFLE_POS];
                    Seed = 420;
                    Statrak = 0;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID == WEAPON_MAC10)
                {
                    Paintkit = 898;
                    Seed = 420;
                    Statrak = 69;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID == WEAPON_MP9)
                {
                    Paintkit = 1134;
                    Seed = 420;
                    Statrak = 69;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID == WEAPON_SSG08)
                {
                    Paintkit = 624;
                    Seed = 420;
                    Statrak = 69;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID == WEAPON_AUG)
                {
                    Paintkit = 455;
                    Seed = 420;
                    Statrak = 69;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID == WEAPON_P90)
                {
                    Paintkit = 359;
                    Seed = 420;
                    Statrak = 69;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID == WEAPON_MAG7)
                {
                    Paintkit = 948;
                    Seed = 420;
                    Statrak = 69;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID == WEAPON_SAWEDOFF)
                {
                    Paintkit = 953;
                    Seed = 420;
                    Statrak = 69;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID == WEAPON_NOVA)
                {
                    Paintkit = 537;
                    Seed = 420;
                    Statrak = 69;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID == WEAPON_GALILAR)
                {
                    Paintkit = 379;
                    Seed = 420;
                    Statrak = 69;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID == WEAPON_SG556)
                {
                    Paintkit = 897;
                    Seed = 420;
                    Statrak = 69;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID == WEAPON_DUALB)
                {
                    Paintkit = 1126;
                    Seed = 420;
                    Statrak = 0;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID == WEAPON_P250)
                {
                    Paintkit = 678;
                    Seed = 420;
                    Statrak = 0;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");
                }
                else if (weaponID != WEAPON_KNIFE && weaponID != WEAPON_KNIFE_T && weaponID != WEAPON_KNIFE_KARAMBIT) { continue; }
                else
                {
                    Paintkit = 413;//413
                    Seed = 305;
                    Statrak = 0;
                    Quality = 3;
                    Wear = 0.0063f;
                    strcpy_s(CustomName, "");

                    //seccion para cambiar de modelos de cuchillo
                    writeMem<short>(weaponEntity + m_iItemDefinitionIndex, WEAPON_KNIFE_KARAMBIT); //Knife Name
                    writeMem<int>(weaponEntity + m_nModelIndex, knifeIndex);
                }
                if (readMem<int>(weaponEntity + m_iItemIDHigh) != -1)
                {
                    writeMem<int>(weaponEntity + m_iItemIDHigh, -1);
                }
                writeMem<int>(weaponEntity + m_iAccountID, accountID);
                writeMem<DWORD>(weaponEntity + m_nFallbackPaintKit, Paintkit);
                writeMem<int>(weaponEntity + m_nFallbackSeed, Seed);
                writeMem<float>(weaponEntity + m_flFallbackWear, Wear);
                if (Statrak == 0) {
                    continue;
                }
                else {
                    writeMem<int>(weaponEntity + m_nFallbackStatTrak, Statrak);
                }
                writeMem<int>(weaponEntity + m_iEntityQuality, Quality);

                if (CustomName != "")
                {
                    WriteProcessMemory(pHandle, (LPVOID)(weaponEntity + m_szCustomName), CustomName, sizeof(char[20]), NULL);
                }
            }

            /* Knife Changer */
            /* Getting knife model index in other gamestate. */
            if (isGetted == false)
            {
                knifeIndex = GetModelIndexByID(WEAPON_KNIFE_KARAMBIT); //Knife Model
                isGetted = true;
            }

            UINT iCurWeaponAdress = readMem<UINT>(localPlayer + m_hActiveWeapon) & 0xFFF;
            UINT m_iBase = readMem<UINT>(clientBase + dwEntityList + (iCurWeaponAdress - 1) * 0x10);
            short curwpnID = readMem<short>(m_iBase + m_iItemDefinitionIndex);

            if (curwpnID == WEAPON_KNIFE || curwpnID == WEAPON_KNIFE_T || curwpnID == WEAPON_KNIFE_KARAMBIT)
            {
                DWORD knifeViewModel = readMem<DWORD>(localPlayer + m_hViewModel) & 0xfff;
                knifeViewModel = readMem<DWORD>(clientBase + dwEntityList + (knifeViewModel - 1) * 0x10);

                if (knifeViewModel == 0) { continue; }

                writeMem<DWORD>(knifeViewModel + m_nModelIndex, knifeIndex);
            }

            if (GetAsyncKeyState(VK_F2) & 1)
            {
                ForceUpdate();
            }

            if (EXIT_MENU)
            {
                ForceUpdate();
                EXIT_MENU = false;
            }

        }
        else
        {
            isGetted = !isGetted;
            break;
        }
    }
    std::cout << "SE ROMPIO EL WHILE" << std::endl;
}

void otherThreads()
{
    while (true)
    {
        /* Press HOME Key to Calling update Engine function */
        if (GetAsyncKeyState(VK_F2) & 1)
        {
            ForceUpdate();
            break;
        }
    }
}
