#pragma once
#include "imgui.h"
#include "imgui_impl_dx12.h"
#include "imgui_impl_win32.h"
#include "auth.hpp"
#include "skStr.h"
#include <d3d9.h>
#include <string>
#include <Windows.h>
#include <tchar.h>
#include "imguiWindow.h"



void SwitchThemeRED() {
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Arial.ttf", 14, NULL, io.Fonts->GetGlyphRangesCyrillic());

    ImGuiStyle& style = ImGui::GetStyle();

    style.WindowRounding = 5.0;
    style.WindowTitleAlign = ImVec2(0.5f, 0.84f);
    style.ChildRounding = 2.0;
    style.FrameRounding = 2.0;
    style.ItemSpacing = ImVec2(5.0f, 4.0f);
    style.ScrollbarSize = 13.0;
    style.ScrollbarRounding = 0;
    style.GrabMinSize = 8.0;
    style.GrabRounding = 1.0;

    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.48f, 0.16f, 0.16f, 0.54f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.98f, 0.26f, 0.26f, 0.40f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.98f, 0.26f, 0.26f, 0.67f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.48f, 0.16f, 0.16f, 1.00f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.98f, 0.26f, 0.26f, 1.00f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.88f, 0.26f, 0.24f, 1.00f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.98f, 0.26f, 0.26f, 1.00f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.98f, 0.26f, 0.26f, 0.40f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.98f, 0.26f, 0.26f, 1.00f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.98f, 0.06f, 0.06f, 1.00f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.98f, 0.26f, 0.26f, 0.31f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.98f, 0.26f, 0.26f, 0.80f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.98f, 0.26f, 0.26f, 1.00f);
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.75f, 0.10f, 0.10f, 0.78f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.75f, 0.10f, 0.10f, 1.00f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.98f, 0.26f, 0.26f, 0.25f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.98f, 0.26f, 0.26f, 0.67f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.98f, 0.26f, 0.26f, 0.95f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.98f, 0.26f, 0.26f, 0.35f);
    style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
}

bool SetPlayerPos(float posx, float posy, float appx, float appy) {

    if (posy < 0) {
        return 0;
    }
    if (posy > 485) {
        return 0;
    }
    if (posx < 0) {
        return 0;
    }
    if (posx > 485) {
        return 0;
    }

    ImGui::SetCursorPos(ImVec2(appx, appy));
    ImGui::Button(" ", ImVec2(10, 10));

    ImGui::SetCursorPos(ImVec2(posx, posy));
    ImGui::Button(" ", ImVec2(10, 10));

    return 1;
}

bool isApp(float px, float py, float ax, float ay)
{
    return px == ax && py == ay;
}

const char* strToChar(std::string str) {
    const char* cstr = str.c_str();
    return cstr;
}

float round_to_10(int x) {
    if (x % 10 >= 5)
    {
        x += 10 - x % 10;
    }
    else
    {
        x -= x % 10;
    }
    return (float)x;
}