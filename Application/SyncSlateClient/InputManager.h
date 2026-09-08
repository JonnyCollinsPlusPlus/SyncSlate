#pragma once
#include <SDL3/SDL.h>
class InputManager{
private:
    bool mouseDown[3]{}, mousePressedThisFrame[3]{}, mouseReleasedThisFrame[3]{};
    SDL_Point mousePos{}, lastMousePos{};
    // keyboard state similarly
protected:
public:
    void BeginFrame(); // reset "just pressed/released" flags
    void ProcessEvent(const SDL_Event& e);

    bool MouseDown(int button) const;
    bool MousePressed(int button) const;
    bool MouseReleased(int button) const;
    SDL_Point MousePos() const;
    SDL_Point MouseDelta() const;
    bool KeyPressed(SDL_Scancode key) const;

};