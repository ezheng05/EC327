// diceroll
// g++ --std=c++17 diceroll.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include -o app -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::srand;
using std::time;
using std::rand;

bool loadDice(vector<sf::Texture>& textures) {
    string fileNames[] = {"diceroll/takeawalk.jpeg", "diceroll/meditate.jpeg", "diceroll/read.jpeg", "diceroll/playagame.jpeg", "diceroll/listentomusic.jpeg", "diceroll/journal.jpeg"};
    for (auto file : fileNames) {
        sf::Texture texture;
        if (!texture.loadFromFile(file)) {
            cout<< "Error loading " << file << "\n";
            return false;
        }
        textures.push_back(texture);
    }
    return true;
}

int diceroll() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Dice Roll Animation");
  vector<sf::Texture> diceTextures;
  string actNames[] = {"Take a walk", "Meditate", "Read", "Play a game", "Listen to music", "Journal"};
  
  // try loadDice
  if (!loadDice(diceTextures)) {
    return -1;
  }

  // load font
  sf::Font font;
  if (!font.loadFromFile("arial/ARIAL.TTF")) {
    cout << "Error loading font\n";
    return -1;
  }

  // load sound
  sf::SoundBuffer sound;
  if (!sound.loadFromFile("diceroll/shuffle.mp3"))
    return -1;
  sf::Sound shuffle;
  shuffle.setBuffer(sound);

  // text -> directions
  sf::Text text;
  text.setFont(font);
  text.setString("Press the spacebar to generate activity.");
  text.setCharacterSize(24);
  text.setFillColor(sf::Color::Black);
  text.setPosition(10, 10);

  // sprite set up
  sf::Sprite diceSprite;

  // activity name set up
  sf::Text activity;
  activity.setFont(font);
  activity.setCharacterSize(20);
  activity.setFillColor(sf::Color::Black);

  srand(static_cast<unsigned int>(time(nullptr))); // seed

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
      shuffle.play();
      shuffle.setPlayingOffset(sf::seconds(1));
      // Simulate dice roll
      for (int i = 0; i < 10; ++i) { // roll duration
        int diceValue = rand() % 6; // rand number between 0 and 5
        diceSprite.setTexture(diceTextures[diceValue]);
        activity.setString(actNames[diceValue]);

        sf::FloatRect spriteBounds = diceSprite.getLocalBounds(); // find sprite bounds
        diceSprite.setOrigin(spriteBounds.left + spriteBounds.width/2, spriteBounds.top + spriteBounds.height/2);
        diceSprite.setPosition(400, 300); // position sprite

        sf::FloatRect spriteGBounds = diceSprite.getGlobalBounds();
        sf::FloatRect textBounds = activity.getLocalBounds(); // find text bounds
        activity.setOrigin(textBounds.left + textBounds.width/2, textBounds.top + textBounds.height / 2.0f); // set origin to center of text
        activity.setPosition(spriteGBounds.left + spriteGBounds.width/2, 415); // align text with image along x-axis

        window.clear(sf::Color::White);
        window.draw(diceSprite);
        window.draw(activity);
        window.display();

        sf::sleep(sf::milliseconds(100)); // control dice roll speed
      }
    }

    // set up
    window.clear(sf::Color::White);
    window.draw(text);
    window.draw(diceSprite);
    window.draw(activity);
    window.display();
  }

  return 0;
}