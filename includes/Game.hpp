#ifndef game_hpp
#define game_hpp

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Display.hpp"
#include "Player.hpp"
#include "Apple.hpp"

#define RESTART_KEY R
#define QUIT_KEY A

#define TOP_KEY Z
#define BOTTOM_KEY S
#define LEFT_KEY Q
#define RIGHT_KEY D

class Game {
  private:
    sf::RenderWindow window;
    Display display;
    Player player;
    Apple apple;

    void displayGame();

  public:
    Game();
    ~Game();

    void key_controller();
    void start();
    void end();
};

#endif // !game_hpp