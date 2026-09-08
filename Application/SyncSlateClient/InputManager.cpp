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
            int b = e.button.button - 1;
			if (b >= 0 && b < 3)
            {
                mouseDown[b] = true;
                mousePressedThisFrame[b] = true;
            }
		}

		if (e.type == SDL_EVENT_MOUSE_BUTTON_UP){
            int b = e.button.button - 1;
            if (b >= 0 && b < 3)
            {
                mouseDown[b] = false;
                mouseReleasedThisFrame[b] = true;
            }		
		}
	}
	if (!io.WantCaptureKeyboard) {
		// safe for canvas/app shortcuts to handle this input
	}
}

bool InputManager::MouseDown(int button) const
{
	return mouseDown[button];
}

bool InputManager::MousePressed(int button) const
{
	return mousePressedThisFrame[button];
}

bool InputManager::MouseReleased(int button) const
{
	return mouseReleasedThisFrame[button];
}

SDL_Point InputManager::MousePos() const
{
	return mousePos;
}

SDL_Point InputManager::MouseDelta() const
{
	return SDL_Point(mousePos.x - lastMousePos.x,
		 mousePos.y - lastMousePos.y);
}

bool InputManager::KeyPressed(SDL_Scancode key) const
{
	return false;
}
