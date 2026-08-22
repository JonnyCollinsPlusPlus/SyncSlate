#include "SyncSlateServer.h"
#include <imgui.h>
#include <SDL3/SDL.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_sdlrenderer3.h>
#include <cmath>

bool SyncSlateServer::Init(){
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
    debug = true;
    networkManager = std::make_unique<ServerNetworkManager>();
    networkManager->Init();
    return true;
}
void SyncSlateServer::Update(float deltaTime){
	networkManager->Update(deltaTime);
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL3_ProcessEvent(&event);
        if (event.type == SDL_EVENT_QUIT) {
            //TODO Exit the program
            int a;
        }
    }
    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();
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
    ImGui::Render();
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
    SDL_RenderPresent(renderer);
}
void SyncSlateServer::Shutdown(){
}
int main(int argc, char* argv[]) {
	SyncSlateServer* server = new SyncSlateServer();
	server->Init();
	while(true){
		server->Update(1);
	}
	server->Shutdown();
	delete server;
	server = nullptr;
	return 0;
}