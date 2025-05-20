# SFML SpaceInvaders

Learning C++ with SFML and a SpaceInvaders clone.

## Requirements

* CMake
* vcpkg

## Dependencies

* SFML
* Box2D
* Dear ImGui

## C++ Learning

* Use smart pointers (std::unique_ptr, std::shared_ptr) instead of raw pointers to prevent memory leaks
* Leverage RAII (Resource Acquisition Is Initialization) for resource management
* Use auto for type inference when appropriate
* Prefer references to pointers when you don't need ownership transfer
* Try being const-correct

## Design Patterns

* Data-Oriented Design: when necessary, use Structure of Array instead of Array of Structure (OOP)
* Finite State Machine: For managing game states (loading, playing, paused)
* Use a CommandRegistry for storing commands and executing commands

## To Do

### Gameplay

- [ ] Controlling the player spaceship with the keyboard (AWSD, Space)
  - [ ] Ensure control is smooth and responsive
  - [ ] Use spring movement with slight rotation for appeal
- [ ] Firing bullets, add them to the bullet collection, create a BulletSystem
  - [ ] Bullet movement, destruction when out of screen
  - [ ] Bullet collision with enemies
  - [ ] Bullet collision with player spaceship
  - [ ] Player lives and health, game over
- [ ] Spawn enemies, enemy movements, enemy system (EnemyMovement)
  - [ ] The enemies should move horizontally, they should not go out of the screen
  - [ ] Enemies should shoot bullets randomly
  - [ ] If the enemies reach the bottom of the screen, game over-
  - [ ] Different enemy types with varying behaviors and health points
- [ ] Add a score system
- [ ] Add a high score system, save to disk
- [ ] Replace enemies and player with sprites
- [ ] Power-ups (shields, weapon upgrades, extra lives)
  - [ ] Increase spread of main weapon
  - [ ] Rockets, with recharge time
  - [ ] Shields
  - [ ] Extra lives, extra health
- [ ] Settings screen, save settings on disk
  - [ ] Music and SFX volumes
  - [ ] Game difficulty settings
  - [ ] Screen resolution and window management
  - [ ] Configurable controls
  - [ ] Colorblind options
- [ ] Level progression system (increasing difficulty, new enemy patterns)
  - [ ] Level is cleared one the enemies are dead 
  - [ ] Initialize enemy position, health, behavior, shooting patterns, at each level (Waves)
  - [ ] EnemyFormation management (rows, V-shape, random spawn, etc.)
  - [ ] Difficulty progression (speed, health, fire rate, etc.)
  - [ ] Boss battles at the end of levels/stages
- [ ] Controlling the player spaceship with the gamepad
- [ ] Controlling the player spaceship with the mouse
- [ ] PauseScreen when pressing ESC in the GameScreen
- [ ] GameOverScreen when the game is lost

### Technical

- [ ] Frame rate management and performance optimization
- [ ] Memory profiling and optimization
- [ ] Game state serialization (save/load game)
- [ ] Collision optimization (spatial partitioning, grid or quadtree, if needed)

### Polish

- [ ] Loading screen with a progress indicator
- [ ] Tutorial or help screen
- [ ] Credits screen
- [ ] Juices and other visual effects (explosions, power-ups, etc.)
  - [ ] Particle system for explosions and bullets fire & smoke
  - [ ] Visual feedback for hits/damage
  - [ ] Screen shake and other juicy effects
- [ ] Localization support for multiple languages

### Testing & Deployment

- [ ] Unit tests for core game systems
- [ ] Automated build process using Github Actions
- [ ] Version tracking, and release process
- [ ] Installer creation, distribution
- [ ] Update mechanism

### UI

- [ ] Sound and effects
- [ ] Text rendering and layout system
- [ ] Button animation and Sound

### Engine

- [x] Set up a basic DoD architecture
- [x] ScreenManager for screen transition
  - [ ] LoadingScreen while loading assets
  - [ ] Overlay, transition animation
- [ ] Component communication system (events/messaging)
- [ ] CommandRegistry for storing commands
- [ ] CommandBuffer for buffering commands
- [ ] InputSystem & InputBuffer, input -> command system
- [ ] Integrate Dear ImGUI for debugging, console, and other debugging actions
- [ ] Create a manifest system for loading resources (ResourceLoader)
  - [ ] Create factories for initializing resources by type
- [ ] Audio and Music managers
- [ ] Engine reusability across games
- [ ] Basic analytics for understanding player behavior
- [ ] Crash reporting mechanism
