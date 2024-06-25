// g++ --std=c++17 bubblePopper.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include -o app -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cstdlib> // For std::rand() and std::srand()
#include <ctime>   // For std::time()
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>

using sf::Mouse;

int bubblePopper() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Bubble Popper");

    sf::Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile("bubblePopper/background.jpg")){
        return -1;
    }
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("bubblePopper/bubblepop.mp3"))
        return -1;  

    sf::Sound sound;
    sound.setBuffer(buffer);

    sf::Sprite background(backgroundTexture);
    sf::Vector2 windowSize = window.getSize();
    sf::Vector2 textureSize = backgroundTexture.getSize();
        background.setScale(
        (float)(windowSize.x) / textureSize.x, 
        (float)(windowSize.y) / textureSize.y
    );
    sf::Texture bubbleTexture;
    if(!bubbleTexture.loadFromFile("bubblePopper/bubble1.png")){
        return -1;
    }
    bubbleTexture.setSmooth(true);
    sf::Sprite bubble(bubbleTexture);
    bubble.setScale(0.05f, 0.05f);

    std::srand(std::time(NULL));

    float x = (float)(std::rand() % (windowSize.x - (int)(bubble.getGlobalBounds().width)));
    float y = (float)(std::rand() % (windowSize.y - (int)(bubble.getGlobalBounds().height)));
    bubble.setPosition(x, y);
    

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
            window.clear();
        auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
        auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
        if(bubble.getGlobalBounds().contains(translated_pos)){ // Rectangle-contains-point check
            // Mouse is inside the sprite.
                float x = (float)(std::rand() % (windowSize.x - (int)(bubble.getGlobalBounds().width)));
                float y = (float)(std::rand() % (windowSize.y - (int)(bubble.getGlobalBounds().height)));
                    sound.play();
                bubble.setPosition(x, y);
            }
        // Draw the background
    window.draw(background);
    window.draw(bubble);
    window.display();

    }        

    return 0;
}
