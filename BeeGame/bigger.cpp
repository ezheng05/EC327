#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include <ctime>
#include <string>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bee Game");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("./assets/background.jpg")) {
        return -1; // Error loading background image
    }
    sf::Sprite background(backgroundTexture);

    sf::Vector2 windowSize = window.getSize();
    sf::Vector2 textureSize = backgroundTexture.getSize();
    background.setScale(
        (float)(windowSize.x) / textureSize.x, 
        (float)(windowSize.y) / textureSize.y
    );

    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("./assets/player.png")) {
        return -1; 
    }
    sf::Sprite player(playerTexture);
    player.setPosition(400, 300); 

    player.setScale(50.0 / playerTexture.getSize().x, 50.0 / playerTexture.getSize().y);

    sf::Texture sunflowerTexture;
    if (!sunflowerTexture.loadFromFile("./assets/sunflower.png")) {
        return -1;
    }
    sf::Sprite sunflower(sunflowerTexture);
    sunflower.setScale(25.0 / sunflowerTexture.getSize().x, 25.0 / sunflowerTexture.getSize().y);

    std::srand(std::time(NULL));

    float playerSpeed = 200.0; 

    int score = 0;

    sf::Font font;
    if (!font.loadFromFile("./assets/ARIALBD.ttf")) {
        return -1;
    }

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);

    scoreText.setFillColor(sf::Color::White);

    scoreText.setString("Score: " + std::to_string(score));

    // Center the score text
    sf::FloatRect textRect = scoreText.getLocalBounds();
    scoreText.setOrigin(textRect.left + textRect.width / 2.0, textRect.top + textRect.height / 2.0);
    scoreText.setPosition(windowSize.x / 2.0, textRect.height / 2.0 + 10); 

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        sf::Text exitButtonText;
        exitButtonText.setFont(font);
    exitButtonText.setCharacterSize(24);
         exitButtonText.setFillColor(sf::Color::White);
        exitButtonText.setString("Press esc to Exit");
        exitButtonText.setPosition(windowSize.x/2 - 100 ,30);

        sf::Vector2 movement(0.0f, 0.0f);
        if(!(player.getGlobalBounds().width >= windowSize.x-50) && !(player.getGlobalBounds().width <= 10) ){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            movement.x -= playerSpeed * dt;
            player.setRotation(270); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            movement.x += playerSpeed * dt;
            player.setRotation(90); 
        }
        }
        if(!(player.getGlobalBounds().height >= windowSize.y-50) && !(player.getGlobalBounds().height <= 10) ){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            movement.y -= playerSpeed * dt;
            player.setRotation(0); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            movement.y += playerSpeed * dt;
            player.setRotation(180); 
        }
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }
        if (movement.x != 0 && movement.y != 0) {
            float angle = std::atan2(movement.y, movement.x) * 180 / 3.14159265;

            player.setRotation(angle + 90); 
        }

        player.move(movement);

        if (player.getGlobalBounds().intersects(sunflower.getGlobalBounds())) {
            score++;
            scoreText.setString("Score: " + std::to_string(score));

            sf::FloatRect textRect = scoreText.getLocalBounds();
            scoreText.setOrigin(textRect.left + textRect.width / 2.0, textRect.top + textRect.height / 2.0);
            scoreText.setPosition(windowSize.x / 2.0, textRect.height / 2.0 + 10); 

            float x = (float)(std::rand() % (windowSize.x - (int)(sunflower.getGlobalBounds().width)));
            float y = (float)(std::rand() % (windowSize.y - (int)(sunflower.getGlobalBounds().height)));
            sunflower.setPosition(x, y);
        }
        

        window.clear();
        window.draw(background);
        window.draw(sunflower);
        window.draw(player);
        window.draw(scoreText);
        window.draw(exitButtonText);
        window.display();
    }

    return 0;
}
