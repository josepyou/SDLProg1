#include <SDL2/SDL.h>
#include <vector>
#include "Vector2D.h"


enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if(s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}

		return s_pInstance;
	}

	void update();
	void clean();

	void initializeJoysticks();
	bool joysticksInitialized() { return m_bJoysticksInitialized; }

	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);

	bool getButtonState(int joy, int buttonNumber)
	{
		return m_buttonStates[joy][buttonNumber];
	}
	bool getMouseButtonState(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}

private:
	InputHandler() 
	{
		for(int i = 0; i < 3; i++)
		{
			m_mouseButtonStates.push_back(false);
		}
	}
	~InputHandler() {}
	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialized;
	std::vector<std::pair<Vector2D*, Vector2D*> > m_joystickValues;
	std::vector<std::vector<bool> > m_buttonStates;
	std::vector<bool> m_mouseButtonStates;

	const int m_joystickDeadZone = 10000;

	static InputHandler* s_pInstance;
};

typedef InputHandler TheInputHandler;

