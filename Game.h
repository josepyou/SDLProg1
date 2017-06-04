#ifndef __GAME_H__
#define __GAME_H__

#include <SDL2/SDL.h>
#include "TextureManager.h"

#include <vector>

class GameObject;
class GameStateMachine;

class Game
{
public:
	~Game() {}

	void init();

	void render();
	void update();
	void handleEvents();
	void clean();
	void draw();
	void quit();

	bool init(const char *title, int xpos, int ypos, int width, int height, int flags);

	// a function to access the private running variable
	bool running() { return m_bRunning; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	static Game* Instance()
	{
		if(s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

private:
	Game(){}

	static Game* s_pInstance;


	SDL_Window *m_pWindow;
	SDL_Renderer *m_pRenderer;

	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;
	int m_currentFrame;
	bool m_bRunning;
	
	std::vector<GameObject*> m_gameObjects;

	GameObject *m_go;
	GameObject *m_player;
	GameObject *m_enemy;

	GameStateMachine *m_pGameStateMachine;
};

typedef Game TheGame;


#endif // GAME_H