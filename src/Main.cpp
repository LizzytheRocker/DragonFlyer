#include "Platform/Platform.hpp"
#include "GameEngine.hpp"

int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	GameEngine game;

	while (game.running())
	{
		game.render();
	}

	return 0;
}
