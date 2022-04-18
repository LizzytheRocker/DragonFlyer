#include "Platform/Platform.hpp"
#include "GameEngine.hpp"

int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif
	//Create game instance
	GameEngine game;
	//Run the game while the game window is open
	while (game.running())
	{
		game.update();
		game.render();
	}

	return 0;
}
