#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class LoaderParams;


class GameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

protected:

	GameObject(const LoaderParams *pPrams) {}
	virtual ~GameObject() {}

	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;

	int m_x;
	int m_y;

	int m_width;
	int m_height;
};

#endif