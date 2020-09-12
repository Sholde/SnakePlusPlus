#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;

int main(int argc, char* argv[]) {
  cout << "Version " << "." << endl;

  sf::Window screen(sf::VideoMode(800, 600), "myproject");
  bool running = true;
  while (running) {
    screen.display();
  }
}