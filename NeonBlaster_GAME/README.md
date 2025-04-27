# Neon Blaster

**Neon Blaster** is a simple 2D game written in C using the SDL2 library. The game involves controlling a spaceship, shooting enemies, and avoiding them, earning points for each enemy destroyed.

## How to Play

1. **Controls**:
   - **WASD** – move the spaceship (up, down, left, right)
   - **Arrow keys** – aim and shoot in the corresponding direction (up, down, left, right)
   
2. The goal of the game is to survive as long as possible while shooting down enemies and avoiding collisions with them. Each time you destroy an enemy, your score increases.

## Features

- **Player Movement**: Use WASD to move the spaceship around the screen.
- **Shooting**: Shoot bullets in one of the four cardinal directions using the arrow keys.
- **Enemies**: Enemies appear from random edges of the screen and move towards the player.
- **Collisions**: If an enemy collides with the player, the game ends.
- **Score**: Earn points by shooting enemies.

## How to Compile and Run

#### Windows (using MinGW)
1. Install MinGW to get the GCC compiler:
   - Download and install proper architecture [MinGW-w64](https://mingw-w64.org/doku.php/download/mingw-builds).
2. Download the SDL2 development libraries for MinGW from the [official SDL2 website](https://www.libsdl.org/download-2.0.php).


3. **RUN**: 
   After compilation, you can run the game with:
   NeonBlaster.exe
   or use the NeonBlaster_GAME\build\NeonBlaster.exe file.


## Future Plans
-*Texture Enhancements*: Replace basic shapes with more detailed textures and sprites to improve the visual experience.

-*Power-ups*: Introduce various power-ups such as rapid fire, shields, or score multipliers to add more depth to the gameplay.

-*Multiple Levels*: Implement several levels with increasing difficulty, including different enemy types and environmental hazards.

-*Enemy Variety*: Add new types of enemies with unique movement patterns, behaviors, and attack strategies.

-*Sound Effects & Music*: Integrate sound effects for shooting, collisions, and background music to enhance the overall experience.

-*Improved UI*: Upgrade the user interface with a better scoreboard, menus, and in-game HUD.

-*Multiplayer Mode*: Add local multiplayer support for two players to play cooperatively or against each other.

-*Leaderboards*: Introduce an online leaderboard system to track high scores globally.

-*Improved Physics*: Fine-tune the movement mechanics and collision detection for a smoother experience.
