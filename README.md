# SFML SpaceInvaders

Learning C++, Game Developer and Game Engine Development, with SFML and a SpaceInvaders clone.

## Requirements

This project was compiled on Jetbrains CLion. It uses:

* MingGW
* CMake Build Generator
* Ninja Build Tool
* g++ compiler

## Dependencies

The external dependencies are installed in the `Vendor/` directory.

* SFML
* nlohmann::json
* Box2D (not implemented yet)
* Dear ImGui (not implemented yet)

## Installation

```shell
git clone git@github.com:ericjeker/sfml-space-invaders.git
```

If you have already cloned the repository, you can update the submodules with:

```shell
git submodule update --init --recursive
```

## Reasonable Defaults

* Data-oriented design by default (under refactoring)
* Separation of data and processing (under refactoring)
* Processors and Systems can be static
* Use Structures of Array instead of Array of Structure
* Avoid complex inheritance, polymorphism, etc.

### Architecture

* Screens are the game Worlds (I could rename them properly)
* Screen transition is manager by a ScreenManager
* A ResourceManager is a centralized place to load resources
* Use a CommandRegistry for storing and executing commands
* Finite State Machine: For managing game states (loading, playing, paused)

### Gameplay

* State/Data live separately from the processing so they can be optimized and serialized easily
* Systems process data (Render, Update)

### C++

* Use smart pointers instead of raw pointers to prevent memory leaks
* Member classes are pointers (under refactoring)
* Prefer references to pointers when you don't need ownership transfer
* Leverage RAII (Resource Acquisition Is Initialization) for resource management
* Use auto for type inference when appropriate
* Try being const-correct as much as possible

### Coding Conventions

* Clean, modular folder structure
* Use CMake for generating build files
* Use Clang-Format and Clang-Tidy

## To Do

### Gameplay

- [ ] Controlling the player spaceship
  - [x] Keyboard support with WASD, and Space
  - [ ] Ensure control is smooth and responsive
  - [ ] Use spring movement with slight rotation for appeal
  - [ ] Gamepad support
- [ ] Firing bullets, add them to the bullet collection, create a BulletSystem
  - [ ] Bullet movement, destruction when out of screen
  - [ ] Bullet collision with enemies
  - [ ] Bullet collision with player spaceship
  - [ ] Player lives and health, game over
- [ ] Spawn enemies, enemy movements, enemy system (EnemyMovement)
  - [ ] The enemies should move horizontally, they should not go out of the screen
  - [ ] Enemies should shoot bullets randomly
  - [ ] If the enemies reach the bottom of the screen, the game is over
  - [ ] Different enemy types with varying behaviors and health points
- [ ] Add a score system
- [ ] Add a high-score system, save to disk
- [ ] Replace enemies and the player with sprites
- [ ] Power-ups (shields, weapon upgrades, extra lives)
  - [ ] Increase spread of the main weapon
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
- [ ] GameOverScreen when the game is lost
- [x] ~~PauseScreen when pressing ESC in the GameScreen~~

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
  - [ ] Particle system for explosions and bullets fire and smoke
  - [ ] Visual feedback for hits/damage
  - [ ] Screen shake and other juicy effects
- [ ] Localization support for multiple languages

### Testing & Deployment

- [ ] Unit tests for core game systems
- [ ] Automated build process using GitHub Actions
- [ ] Version tracking, and release process
- [ ] Installer creation, distribution
- [ ] Update mechanism

### UI

- [ ] Sound when click
- [ ] Text alignment, center point
- [ ] Layout system with auto-align
- [x] ~~Button animation~~
- [ ] VFX, animated background

### Engine

- [x] ~~Set up a basic DoD architecture~~
- [x] ~~ScreenManager for screen transition~~
  - [ ] LoadingScreen while loading assets
  - [ ] Overlay, transition animation
- [ ] Component communication system (events/messaging)
- [x] ~~CommandBuffer for buffering commands~~
- [ ] Integrate Dear ImGUI for debugging, console, and other debugging actions
- [x] ~~Create a manifest system for loading resources (ResourceLoader)~~
  - [ ] Create factories for initializing resources by type
- [ ] Audio and Music managers
- [x] ~~Engine reusability across games~~
- [ ] Basic analytics for understanding player behavior
- [ ] Crash reporting mechanism
