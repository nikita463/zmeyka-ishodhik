#pragma once
#include <Windows.h>
#include "main.h"
#include "skStr.h"
#include "ShellAPI.h"

using namespace KeyAuth;

bool SetPlayerPos(float posx, float posy, float appx, float appy);
float round_to_10(int x);
const char* strToChar(std::string str);
bool isApp(float px, float py, float ax, float ay);

bool gameMenu = true;
bool game = false;

float posx = 0;
float posy = 0;

int apps = 0;

float appx = round_to_10(52);
float appy = round_to_10(75);

bool left = 0;
bool right = 0;
bool down = 0;
bool up = 0;

bool isGameUnlocked = 0;
bool logMenu = 1;
bool login = 0;
bool reg = 0;
static char* logname = 0;
static char* password = 0;
static char* key = 0;
bool isLogined = 0;

//std::string name = "ImGui Zmeyka";
//std::string ownerid = "opFIUcJVxC";
//std::string secret = "ef9456eed098c8bf7ae6c6fc6dc752ef8f06a2a6b7f6af278b5ca0daea5f1554";
//std::string version = "1.0";
//std::string url = "https://keyauth.win/api/1.2/";
//
//api KeyAuthApp(name, ownerid, secret, version, url);

//void GameKeyAuth()
//{
//    if (logMenu)
//    {
//        ImGui::SetNextWindowSize(ImVec2(198, 160));
//        ImGui::Begin("Activation", &logMenu, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);
//        {
//            if (ImGui::Button(u8"Вход", ImVec2(184, 20)))
//            {
//                login = 1;
//                logMenu = 0;
//
//            }
//            if (ImGui::Button(u8"Регистрация", ImVec2(184, 20)))
//            {
//                reg = 1;
//                logMenu = 0;
//            }
//
//            ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize(u8"\nЗапросить ключ можно\nв нашем дискорд канале").x) / 2);
//            ImGui::Text(u8"\nЗапросить ключ можно\nв нашем дискорд канале");
//            if (ImGui::Button("Discord", ImVec2(184, 30)))
//            {
//                ShellExecuteA(NULL, "open", "https://discord.gg/USQ6UPh8", NULL, NULL, SW_SHOW);
//            }
//        }
//        ImGui::End();
//    }
//
//    if (login)
//    {
//        ImGui::SetNextWindowSize(ImVec2(198, 105));
//        ImGui::Begin(u8"Вход", &login, ImGuiWindowFlags_NoResize);
//        {
//            if (logname == 0) {
//                logname = new char[100];
//                logname[0] = 0;
//            }
//            ImGui::InputText(u8"Логин", logname, 50);
//
//            if (password == 0) {
//                password = new char[100];
//                password[0] = 0;
//            }
//            ImGui::InputText(u8"Пароль", password, 50, ImGuiInputTextFlags_Password);
//
//            if (ImGui::Button(u8"Войти", ImVec2(185, 20)))
//            {
//                KeyAuthApp.login(logname, password);
//                isLogined = 1;
//            }
//
//            if (!KeyAuthApp.data.success)
//            {
//                std::string msg = KeyAuthApp.data.message;
//                const char* cmsg = msg.c_str();
//
//                if (!KeyAuthApp.data.success)
//                {
//                    ImGui::Text(cmsg);
//                }
//            }
//            else if (isLogined && KeyAuthApp.data.success) {
//                isGameUnlocked = 1;
//            }
//        }
//        ImGui::End();
//    }
//
//    if (reg)
//    {
//        ImGui::SetNextWindowSize(ImVec2(198, 128));
//        ImGui::Begin(u8"Регистрация", &reg, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
//        {
//            if (logname == 0) {
//                logname = new char[100];
//                logname[0] = 0;
//            }
//            ImGui::InputText(u8"Логин", logname, 50);
//
//            if (password == 0) {
//                password = new char[100];
//                password[0] = 0;
//            }
//            ImGui::InputText(u8"Пароль", password, 50, ImGuiInputTextFlags_Password);
//
//            if (key == 0) {
//                key = new char[100];
//                key[0] = 0;
//            }
//            ImGui::InputText(u8"Ключ", key, 50);
//
//
//            if (ImGui::Button(u8"Зарегестрироваться", ImVec2(185, 20)))
//            {
//                KeyAuthApp.regstr(logname, password, key);
//                isLogined = 1;
//            }
//
//            if (!KeyAuthApp.data.success)
//            {
//                std::string msg = KeyAuthApp.data.message;
//                const char* cmsg = msg.c_str();
//
//                if (!KeyAuthApp.data.success)
//                {
//                    ImGui::Text(cmsg);
//                }
//            }
//            else if (isLogined && KeyAuthApp.data.success) {
//                isGameUnlocked = 1;
//            }
//        }
//        ImGui::End();
//    }
//}

void ZmeykaMenu()
{
    ImGui::SetNextWindowSize(ImVec2(120, 133));
    if (gameMenu) {
        ImGui::Begin(u8"Меню игры", &gameMenu, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);
        {
            if (!game) {
                if (ImGui::Button(u8"Включить игру", ImVec2(105, 25))) {
                    int randx = rand() % 450, randy = rand() % 450;
                    posx = randx;
                    posy = randy;
                    game = 1;
                    up = 0;
                    down = 0;
                    left = 0;
                    right = 0;
                }
                ImGui::Text("NUMPAD8 to up");
                ImGui::Text("NUMPAD2 to down");
                ImGui::Text("NUMPAD4 to left");
                ImGui::Text("NUMPAD6 to right");
            }
            else {
                if (ImGui::Button(u8"Выключить игру", ImVec2(105, 25))) {
                    game = 0;
                }
                ImGui::BeginChild("stats", ImVec2(105, 70), 1);
                {
                    std::string stat = u8"Собранные\nяблоки: " + std::to_string(apps);
                    const char* stats = strToChar(stat);

                    ImGui::Text(stats);
                }
                ImGui::EndChild();
            }
        }
        ImGui::End();
    }
}

void ZmeykaGame()
{
    ImGui::SetNextWindowSize(ImVec2(490, 490));
    if (game) {
        ImGui::Begin("game", &game, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);
        {
            if (SetPlayerPos(round_to_10(posx), round_to_10(posy), appx, appy))
            {
                if (left) {
                    posx -= 0.5;
                }
                if (right) {
                    posx += 0.5;
                }
                if (up) {
                    posy -= 0.5;
                }
                if (down) {
                    posy += 0.5;
                }
            }
            else {
                game = 0;
            }

            if (isApp(posx, posy, appx, appy))
            {
                apps++;
            }
        }
        ImGui::End();
    }
}
