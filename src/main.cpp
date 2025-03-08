#include <SFML/Graphics.hpp>
#include "core/include/configuration.hpp"
#include "game/include/game.hpp"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode(configuration::windowSize), "SFML Project");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

	const Game game(window);
    game.run();

    return 0;
}
