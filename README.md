# SFML SpaceInvaders

Learning C++ with SFML and a SpaceInvaders clone.

## Requirements

* CMake

## Dependencies

* SFML
* EnTT

## C++ Practices

* Use smart pointers (std::unique_ptr, std::shared_ptr) instead of raw pointers to prevent memory leaks
* Leverage RAII (Resource Acquisition Is Initialization) for resource management
* Use auto for type inference when appropriate (as you've done)
* Prefer references over pointers when you don't need ownership transfer

## Design Patterns

* Entity-Component-System (ECS) - EnTT implements this pattern, which separates data (components) from behavior (systems)
* State Pattern - For managing game states (menu, playing, paused)
* Observer Pattern - For event handling
* Factory Pattern - For creating game objects

## To Learn

- [ ] Which types of data should I use and when?

## Architecture

- TitleScreen
- GameScreen
- PauseScreen
- GameOverScreen

- InputManager
- ScreenManager (Finite State Machine)

- Store mouse position in game state (sf::Mouse::getPosition(window))
- How to share the game state with the different screens?
- Replace GameState with EnTT::registry