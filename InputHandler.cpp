#include "InputHandler.h"
#include <iostream>

#include "Game.h"

#include <iostream>

InputHandler* InputHandler::s_pInstance = 0;

void InputHandler::initializeJoysticks()
{
	if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
	{
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}

	if(SDL_NumJoysticks() > 0)
	{
		for(int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_Joystick* joy = SDL_JoystickOpen(i);
			if(joy)
			{
				m_joysticks.push_back(joy);
			}
			else
			{
				std::cout << SDL_GetError();
			}
		}
		SDL_JoystickEventState(SDL_ENABLE);
		m_bJoysticksInitialized = true;

		std::cout << "Initialized" << m_joysticks.size() << "joystick(s)";
	}
	else
	{
		std::cout << "initialize false\n";
		m_bJoysticksInitialized = false;
	}
}

void InputHandler::clean()
{
	if(m_bJoysticksInitialized)
	{
		for(unsigned int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_JoystickClose(m_joysticks[i]);
		}
	}
}

void InputHandler::update()
{
	SDL_Event event;
	while(SDL_PollEvent(&event) != 0)
	{
		if(event.type == SDL_QUIT)
		{
			TheGame::Instance()->quit();
		}
	}
}

