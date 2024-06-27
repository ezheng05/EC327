#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "diceroll.h"
#include "beeGame.h"
#include "feelings.h"
#include "bubblePopper.h"
#include "profile.h"

using std::cout;

int main() {
    bool scale = true;

    sf::RenderWindow window(sf::VideoMode(800, 570), "Home Page");

    // load background bee image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background.jpeg")) {
        cout << "Error loading image\n";
        return -1;
    }

    // load font
    sf::Font font;
    if (!font.loadFromFile("arial/ARIAL.TTF")) {
        cout << "Error loading font\n";
        return -1;
    }

    // load and play music
    sf::Music music;
    if (!music.openFromFile("rain.ogg")) {
        cout << "Error playing sound\n";
        return -1;
    }
    music.setLoop(true);
    music.play();

    // create and position background image sprite
    sf::Sprite background(backgroundTexture);
    sf::FloatRect spriteBounds = background.getGlobalBounds();
    background.setOrigin(spriteBounds.left + spriteBounds.width / 2, spriteBounds.top + spriteBounds.height / 2.0f);
    background.setPosition(400, 300); // center of window
    bool move_right = true;

    // user instructions
    sf::Text instructions;
    instructions.setFont(font);
    instructions.setString("Note: new windows may appear behind this home page.");
    instructions.setCharacterSize(18);
    instructions.setFillColor(sf::Color::Red);
    sf::FloatRect instructBounds = instructions.getLocalBounds();
    instructions.setOrigin(instructBounds.left + instructBounds.width / 2, instructBounds.top + instructBounds.height / 2);
    instructions.setPosition(400, 50);

    // feelings button #1
    sf::RectangleShape feelings_button(sf::Vector2f(200, 100));
    sf::FloatRect feelingsBounds = feelings_button.getLocalBounds();
    feelings_button.setOrigin(feelingsBounds.left + feelingsBounds.width / 2, feelingsBounds.top + feelingsBounds.height / 2);
    feelings_button.setFillColor(sf::Color::Magenta);
    feelings_button.setPosition(150, 150);
    // feelings text
    sf::Text feelings_text;
    feelings_text.setFont(font);
    feelings_text.setString("Feelings survey");
    feelings_text.setCharacterSize(16);
    feelings_text.setFillColor(sf::Color::White);
    sf::FloatRect feeltextBounds = feelings_text.getLocalBounds();
    feelings_text.setOrigin(feeltextBounds.left + feeltextBounds.width / 2, feeltextBounds.top + feeltextBounds.height / 2);
    feelings_text.setPosition(150, 150);

    // games button #2
    // game 1
    sf::RectangleShape games_button1(sf::Vector2f(100, 100));
    sf::FloatRect gamesBounds1 = games_button1.getLocalBounds();
    games_button1.setOrigin(gamesBounds1.left + gamesBounds1.width / 2, gamesBounds1.top + gamesBounds1.height / 2);
    games_button1.setFillColor(sf::Color(70, 200, 50));
    games_button1.setPosition(100, 450);
    // game 2
    sf::RectangleShape games_button2(sf::Vector2f(100, 100));
    sf::FloatRect gamesBounds2 = games_button2.getLocalBounds();
    games_button2.setOrigin(gamesBounds2.left + gamesBounds2.width / 2, gamesBounds2.top + gamesBounds2.height / 2);
    games_button2.setFillColor(sf::Color::Blue);
    games_button2.setPosition(200, 450);
    // games text
    sf::Text games_text;
    games_text.setFont(font);
    games_text.setString("Play de-stress games:");
    games_text.setCharacterSize(17);
    games_text.setFillColor(sf::Color::Black);
    sf::FloatRect gamestextBounds = games_text.getLocalBounds();
    games_text.setOrigin(gamestextBounds.left + gamestextBounds.width / 2, gamestextBounds.top + gamestextBounds.height / 2);
    games_text.setPosition(150, 385);
    // game 1 text
    sf::Text games_text1;
    games_text1.setFont(font);
    games_text1.setString("Bee Game");
    games_text1.setCharacterSize(16);
    games_text1.setFillColor(sf::Color::White);
    sf::FloatRect gamestextBounds1 = games_text1.getLocalBounds();
    games_text1.setOrigin(gamestextBounds1.left + gamestextBounds1.width / 2, gamestextBounds1.top + gamestextBounds1.height / 2);
    games_text1.setPosition(100, 450);
    // game 2 text
    sf::Text games_text2;
    games_text2.setFont(font);
    games_text2.setString("Bubble\nPopper");
    games_text2.setCharacterSize(16);
    games_text2.setFillColor(sf::Color::White);
    sf::FloatRect gamestextBounds2 = games_text2.getLocalBounds();
    games_text2.setOrigin(gamestextBounds2.left + gamestextBounds2.width / 2, gamestextBounds2.top + gamestextBounds2.height / 2);
    games_text2.setPosition(200, 450);

    // dice button #3
    sf::RectangleShape dice_button(sf::Vector2f(200, 100));
    sf::FloatRect diceBounds = dice_button.getLocalBounds();
    dice_button.setOrigin(diceBounds.left + diceBounds.width / 2, diceBounds.top + diceBounds.height / 2);
    dice_button.setFillColor(sf::Color(250, 100, 100));
    dice_button.setPosition(650, 150);
    // dice text
    sf::Text dice_text;
    dice_text.setFont(font);
    dice_text.setString("Surprise me!");
    dice_text.setCharacterSize(16);
    dice_text.setFillColor(sf::Color::White);
    sf::FloatRect dicetextBounds = dice_text.getLocalBounds();
    dice_text.setOrigin(dicetextBounds.left + dicetextBounds.width / 2, dicetextBounds.top + dicetextBounds.height / 2);
    dice_text.setPosition(650, 150);

    // profile/personal button #4
    sf::RectangleShape profile_button(sf::Vector2f(200, 100));
    sf::FloatRect profileBounds = profile_button.getLocalBounds();
    profile_button.setOrigin(profileBounds.left + profileBounds.width / 2, profileBounds.top + profileBounds.height / 2);
    profile_button.setFillColor(sf::Color(150, 50, 250));
    profile_button.setPosition(650, 450);
    // profile text
    sf::Text profile_text;
    profile_text.setFont(font);
    profile_text.setString("My profile");
    profile_text.setCharacterSize(16);
    profile_text.setFillColor(sf::Color::White);
    sf::FloatRect proftextBounds = profile_text.getLocalBounds();
    profile_text.setOrigin(proftextBounds.left + proftextBounds.width / 2, proftextBounds.top + proftextBounds.height / 2);
    profile_text.setPosition(650, 450);

    window.setFramerateLimit(20);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window); // get mouse pos relative to window
            sf::Vector2f translated_pos = window.mapPixelToCoords(mouse_pos);

            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (feelings_button.getGlobalBounds().contains(translated_pos)) {
                    cout << "Feelings survey open\n";
                    feelings();
                } else if (games_button1.getGlobalBounds().contains(translated_pos)) {
                    cout << "Bee game open\n";
                    beeGame();
                } else if (games_button2.getGlobalBounds().contains(translated_pos)) {
                    cout << "Bubble popper game open\n";
                    bubblePopper();
                } else if (dice_button.getGlobalBounds().contains(translated_pos)) {
                    cout << "Dice roll open\n";
                    diceroll();
                } else if (profile_button.getGlobalBounds().contains(translated_pos)) {
                    cout << "Profile open\n";
                    profile();
                }
            }
        }

        // move bee back and forth
        sf::Vector2f pos = background.getPosition();
        if (move_right) {
            background.move(3, 0);
            if (pos.x >= 450)
                move_right = false;
        } else {
            background.move(-3, 0);
            if (pos.x <= 350)
                move_right = true;
        }

        // animate text
        sf::Vector2f size = instructions.getScale();
        if (scale) {
            instructions.setScale(size.x + 0.005, size.y + 0.005);
            if (size.x >= 1.05)
                scale = false;
        } else {
            instructions.setScale(size.x - 0.005, size.y - 0.005);
            if (size.x <= 0.95)
                scale = true;
        }

        window.clear(sf::Color::White);
        window.draw(background);
        window.draw(instructions);
        window.draw(feelings_button);
        window.draw(feelings_text);
        window.draw(games_button1);
        window.draw(games_button2);
        window.draw(games_text);
        window.draw(games_text1);
        window.draw(games_text2);
        window.draw(dice_button);
        window.draw(dice_text);
        window.draw(profile_button);
        window.draw(profile_text);
        window.display();
    }
    return 0;
}
