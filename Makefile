GameMain: main.o Game.o GameObject.o SDLGameObject.o Player.o Enemy.o TextureManager.o InputHandler.o
	g++ -o GameMain main.o Game.o GameObject.o SDLGameObject.o Player.o Enemy.o TextureManager.o InputHandler.o -lSDL2 -lSDL2_image
main.o: main.cpp
	g++ -c main.cpp
InputHandler.o: InputHandler.cpp
	g++ -c InputHandler.cpp
Game.o: Game.cpp
	g++ -c Game.cpp
GameObject.o:
	g++ -c GameObject.cpp
SDLGameObject.o: SDLGameObject.cpp
	g++ -c SDLGameObject.cpp
Player.o: Player.cpp
	g++ -c Player.cpp
Enemy.o: Enemy.cpp
	g++ -c Enemy.cpp
TextureManager.o: TextureManager.cpp
	g++ -c TextureManager.cpp
