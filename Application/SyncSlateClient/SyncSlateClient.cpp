#include "SyncSlateClient.h"
#include <imgui.h>
#include <SDL3/SDL.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_sdlrenderer3.h>
#include <cmath>

bool SyncSlateClient::Init() {
    // --- Setup: SDL window + renderer ---
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("SyncSlate", 1280, 720, SDL_WINDOW_RESIZABLE);
    if (!window) {
        SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
        return false;
    }
    NET_Init();

    // --- Setup: ImGui context + backends ---
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui::StyleColorsDark();

    ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer3_Init(renderer);
    active = true;
    canvas = std::make_unique<Canvas>();
    networkManager = std::make_unique<ClientNetworkManager>();
    networkManager->Init();
    inputManager = std::make_unique<InputManager>();
    return true;
}
void SyncSlateClient::Run(){

        // Start the frame
        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();

        // --- UI ---
        if (active) {
            canvas->draw();
        }
        ImGui::Begin("Debug", &debug, ImGuiWindowFlags_MenuBar);

        if (ImGui::BeginMenuBar()) {
            if (ImGui::BeginMenu("File")) {
                if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
                if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */ }
                if (ImGui::MenuItem("Close", "Ctrl+W")) { debug = false; }
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }

        ImGui::Text("DEBUG MENU");
        ImGui::Text(networkManager->GetDebugInfo().c_str());

        ImGui::End();
        // --- Render ---
        ImGui::Render();
        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
        SDL_RenderClear(renderer);
        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
        SDL_RenderPresent(renderer);
}
void SyncSlateClient::Shutdown(){
    // --- Cleanup ---
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void SyncSlateClient::Update(float deltaTime){
    networkManager->Update(deltaTime);
    if (inputManager->MouseDown(0)){
        canvas->MakeTestStroke();
    }
}

int main(int argc, char* argv[]) {
    SyncSlateClient* client = new SyncSlateClient();
    client->Init();
    // --- Main loop ---
    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL3_ProcessEvent(&event);
            client->GetInputManager().ProcessEvent(event);
            if (event.type == SDL_EVENT_QUIT) running = false;
            client->Run();
            client->Update(1);
        }

    }
    client->Shutdown();

    return 0;
}