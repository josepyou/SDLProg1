#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <SDL2/SDL.h>
#include <string>
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams *pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
};

#endif