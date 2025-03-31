# SFML SpaceInvaders

Learning C++ with SFML and a SpaceInvaders clone.

## Requirements

* CMake
* vcpkg

## Dependencies

* SFML
* EnTT
* Box2D
* Dear ImGui

## C++ Practices

* Use smart pointers (std::unique_ptr, std::shared_ptr) instead of raw pointers to prevent memory leaks
* Leverage RAII (Resource Acquisition Is Initialization) for resource management
* Use auto for type inference when appropriate
* Prefer references over pointers when you don't need ownership transfer

## Design Patterns

* Entity-Component-System (ECS) - EnTT implements this pattern, which separates data (components) from behavior (systems)
* Struct as Archetypes
* Finite State Machine - For managing game states (loading, playing, paused)
* Data-driven approach for loading resources using ResourceLoader and ResourceManager  

## To Do

- [ ] Set up EnTT and replace the current GameState with a registry
- [ ] Set up Dear ImGui
- [ ] Create a manifest system for loading resources
  - [ ] Create factories for initializing resources by type
- [ ] Audio and Music managers
- [ ] How to create a distribution package?
  - [ ] Include game executable
  - [ ] Include required DLLs, including dependencies
  - [ ] Include game assets
  - [ ] Include configuration files

### Screens & GUI

- [ ] PauseScreen when pressing ESC in the GameScreen
- [ ] GameOverScreen when the game is lost
- [ ] Button animation and Sound
- [ ] Integrate Dear ImGUI for debugging, console, and other debugging actions

### Entity, Components, Archetypes, Systems

- [ ] InputSystem & InputRegistryComponent
- [ ] CommandRegistryComponent for storing commands
- [ ] GameStateComponent for managing game states
- [ ] PaddleEntity and PaddleArchetype
  - [ ] TransformComponent
  - [ ] VelocityComponent
  - [ ] HealthComponent
- [ ] BulletEntity and BulletArchetype
  - [ ] TransformComponent
  - [ ] VelocityComponent
  - [ ] DamageComponent
- [ ] EnemyEntity and EnemyArchetype
  - [ ] TransformComponent
  - [ ] VelocityComponent
  - [ ] HealthComponent
  - [ ] EnemyTypeComponent & EnemyAISystem
- [ ] SpriteAnimationArchetype and AnimationSystem for animating entities
  - [ ] TransformComponent
  - [ ] SpriteAnimationComponent and SpriteAnimationSystem
  - [ ] SpriteComponent and SpriteRenderingSystem
- [ ] SoundComponent for playing sound effects
- [ ] SoundEffectComponent for playing sound effects

### Managers

- [x] ScreenManager
- [x] ResourceManager
- [ ] ResourceLoader
- [ ] InputManager
- [ ] CommandRegistry
