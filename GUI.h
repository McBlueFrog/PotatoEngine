#pragma once
#include "Defines.h"


float window_color[] = { 0.1f, 0.1f, 0.1f, 0.80f };
float border_color[] = { 0.1f, 0.1f, 0.1f, 0.90f };
float frame_color[] = { 0.1f, 0.1f, 0.1f, 0.90f };
float active_frame_color[] = { 0.2f, 0.2f, 0.2f, 0.90f };
float active_border_color[] = { 0.3f, 0.3f, 0.3f, 0.90f };
bool object_editor = false;
bool scene = false;
bool engine_settings = false;
bool content_browser = false;
float my_color[] = { 0.0f, 0.0f, 0.0f, 1.0f };
float near_plane = 1.0f, far_plane = 5.5f;

glm::vec3 lightPos(-2.0f, 18.0f, -1.0f);



// positions of the point lights
glm::vec3 pointLightPositions[] = {
    glm::vec3(0.7f,  0.2f,  2.0f),
};


void gui()
{

    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();



    ImVec4* colors = ImGui::GetStyle().Colors;
    colors[ImGuiCol_TitleBg] = { border_color[0],border_color[1],border_color[2],border_color[3] };
    colors[ImGuiCol_TitleBgActive] = { active_border_color[0],active_border_color[1],active_border_color[2],active_border_color[3] };
    colors[ImGuiCol_WindowBg] = { window_color[0],window_color[1],window_color[2],window_color[3] };
    colors[ImGuiCol_FrameBg] = { frame_color[0],frame_color[1],frame_color[2],frame_color[3] };
    colors[ImGuiCol_FrameBgActive] = { active_frame_color[0],active_frame_color[1],active_frame_color[2],active_frame_color[3] };

    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Project"))
        {
            if (ImGui::MenuItem("Open"))
            {
                //Do something
            }
            if (ImGui::MenuItem("New"))
            {
                //Do something
            }
            if (ImGui::MenuItem("Save"))
            {
                //Do something
            }
            if (ImGui::MenuItem("Save As"))
            {
                //Do something
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Settings"))
        {
            if (ImGui::MenuItem("Project Settings"))
            {
                //Do something
            }
            if (ImGui::MenuItem("Engine Settings"))
            {
                engine_settings = !engine_settings;
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Window"))
        {
            if (ImGui::MenuItem("Object Editor"))
            {
                object_editor = !object_editor;
            }
            if (ImGui::MenuItem("Scene"))
            {
                scene = !scene;
            }
            if (ImGui::MenuItem("Content Browser"))
            {
                content_browser = !content_browser;
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Help"))
        {
            if (ImGui::MenuItem("Manual"))
            {
                //Do something
            }
            ImGui::EndMenu();
        }

        ImGui::SameLine(ImGui::GetWindowWidth() - 200);
        ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::EndMainMenuBar();
    }

    // ENGINE SETTINGS
    if (engine_settings)
    {
        ImGui::Begin("Engine Settings", &engine_settings);


        ImGui::Text("Color: ");

        // Edit a color (stored as ~4 floats)
        ImGui::ColorEdit4("Background Color", window_color);

        ImGui::ColorEdit4("Border Color", border_color);

        ImGui::ColorEdit4("Active Border Color", active_border_color);

        ImGui::ColorEdit4("Frame Color", frame_color);

        ImGui::ColorEdit4("Actvie Frame Color", active_frame_color);

        ImGui::EndChild();
        ImGui::End();
    }
    // ENGINE SETTINGS

    // OBJECT EDITOR
    if (object_editor)
    {
        ImGui::Begin("Object Editor", &object_editor);


        ImGui::Text("Selected Object: ");

        // Edit a color (stored as ~4 floats)
        ImGui::ColorEdit4("Color", my_color);

        ImGui::SliderFloat("far plane", &far_plane, 0.0f, 10.0f);
        ImGui::SliderFloat("near plane", &near_plane, 0.0f, 10.0f);


        ImGui::SliderFloat("light x", &lightPos.x , -100.0f, 100.0f);
        ImGui::SliderFloat("light y", &lightPos.y, -100.0f, 100.0f);
        ImGui::SliderFloat("light z", &lightPos.z, -100.0f, 100.0f);

        

        ImGui::EndChild();
        ImGui::End();
    }
    // OBJECT EDITOR

    //SCENE
    if (scene)
    {
        ImGui::Begin("Scene", &scene);
        ImGui::Text("Some Object");
        ImGui::End();
    }
    //SCENE

    //CONTENT BROWSER
    if (content_browser)
    {
        ImGui::Begin("Content Browser", &content_browser, ImGuiWindowFlags_MenuBar);
        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("Import", "Ctrl+I")) { /* Do stuff */ }
                if (ImGui::MenuItem("Export", "Ctrl+E")) { /* Do stuff */ }
                if (ImGui::MenuItem("Delete", "Del")) {}
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }
        ImGui::End();
    }
    //CONTENT BROWSER
}