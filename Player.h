#include "SDLGameObject.h"
#include <string>

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams *pPrams);

	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	void handleInput();
};
