#include "InputManager.h"
#include <imgui.h>
void InputManager::BeginFrame()
{
}

void InputManager::ProcessEvent(const SDL_Event &e)
{
	ImGuiIO& io = ImGui::GetIO();
	if (e.type == SDL_EVENT_MOUSE_REMOVED)
	if (!io.WantCaptureMouse) {
		// safe for canvas to handle this input
		if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN){
			MouseDown(e.button.button);
		}

		if (e.type == SDL_EVENT_MOUSE_BUTTON_UP){
			MouseReleased(e.button.button);
		}
	}
	if (!io.WantCaptureKeyboard) {
		// safe for canvas/app shortcuts to handle this input
	}
}

bool InputManager::MouseDown(int button) const
{
	return false;
}

bool InputManager::MousePressed(int button) const
{
	return false;
}

bool InputManager::MouseReleased(int button) const
{
	return false;
}

SDL_Point InputManager::MousePos() const
{
	return SDL_Point();
}

SDL_Point InputManager::MouseDelta() const
{
	return SDL_Point();
}

bool InputManager::KeyPressed(SDL_Scancode key) const
{
	return false;
}
