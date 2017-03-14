#include <SDL2/SDL.h>
#include <vector>

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

private:
	InputHandler() {}
	~InputHandler() {}
	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialized;

	static InputHandler* s_pInstance;
};

typedef InputHandler TheInputHandler;

