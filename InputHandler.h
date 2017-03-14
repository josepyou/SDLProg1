#include <SDL2/SDL.h>
#include <vector>
#include "Vector2D.h"


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

private:
	InputHandler() {}
	~InputHandler() {}
	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialized;
	std::vector<std::pair<Vector2D*, Vector2D*> > m_joystickValues;

	const int m_joystickDeadZone = 10000;

	static InputHandler* s_pInstance;
};

typedef InputHandler TheInputHandler;

