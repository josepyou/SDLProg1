COMPILE_CMD = g++
OPTION_FLG = -std=c++11


GameMain: main.o Game.o GameObject.o SDLGameObject.o Player.o Enemy.o TextureManager.o InputHandler.o PlayState.o MenuState.o GameStateMachine.o MenuButton.o
	$(COMPILE_CMD) $(OPTION_FLG) -o GameMain main.o Game.o GameObject.o SDLGameObject.o Player.o Enemy.o TextureManager.o InputHandler.o PlayState.o MenuState.o GameStateMachine.o MenuButton.o -lSDL2 -lSDL2_image
main.o: main.cpp
	$(COMPILE_CMD) $(OPTION_FLG) -c main.cpp
InputHandler.o: InputHandler.cpp
	$(COMPILE_CMD) $(OPTION_FLG) -c InputHandler.cpp
Game.o: Game.cpp
	$(COMPILE_CMD) $(OPTION_FLG) -c Game.cpp
GameObject.o:
	$(COMPILE_CMD) $(OPTION_FLG) -c GameObject.cpp
SDLGameObject.o: SDLGameObject.cpp
	$(COMPILE_CMD) $(OPTION_FLG) -c SDLGameObject.cpp
Player.o: Player.cpp
	$(COMPILE_CMD) $(OPTION_FLG) -c Player.cpp
Enemy.o: Enemy.cpp
	$(COMPILE_CMD) $(OPTION_FLG) -c Enemy.cpp
TextureManager.o: TextureManager.cpp
	$(COMPILE_CMD) $(OPTION_FLG) -c TextureManager.cpp
PlayState.o : PlayState.cpp
	$(COMPILE_CMD) $(OPTION_FLG) -c PlayState.cpp
MenuState.o : MenuState.cpp
	$(COMPILE_CMD) $(OPTION_FLG) -c MenuState.cpp
GameStateMachine.o : GameStateMachine.cpp
	$(COMPILE_CMD) $(OPTION_FLG) -c GameStateMachine.cpp
MenuButton.o : MenuButton.cpp
	$(COMPILE_CMD) $(OPTION_FLG) -c MenuButton.cpp
