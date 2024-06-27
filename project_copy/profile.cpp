#include "profile.h"
#include <iostream>

using std::cout;

// progress boxes
sf::RectangleShape createProgBar(float x, float y, float width, float height, sf::Color color) {
    sf::RectangleShape progressBar(sf::Vector2f(width, height));
    progressBar.setFillColor(color);
    progressBar.setPosition(x, y);
    return progressBar;
}

int profile() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Profile");

    // load font
    sf::Font font;
    if (!font.loadFromFile("arial/ARIAL.TTF")) {
        cout << "Error loading font\n";
        return -1;
    }

    // get last 7 feelings
    vector<pair<string, string>> last_feelings = getLastFeel();

    // heading
    sf::Text instructions;
    instructions.setFont(font);
    instructions.setCharacterSize(18);
    instructions.setFillColor(sf::Color::Black);

    // key/label
    sf::Text labels;
    labels.setFont(font);

    // no recorded feelings
    if (last_feelings.empty()) {
        cout << "No feelings recorded yet.\n";
        instructions.setString("No feelings recorded yet.");
        sf::FloatRect instructBounds = instructions.getLocalBounds();
        instructions.setOrigin(instructBounds.left + instructBounds.width / 2, instructBounds.top + instructBounds.height / 2);
        instructions.setPosition(400, 30);
    } else { // display labels and heading
        cout << "Feelings recorded: " << last_feelings.size() << "\n";
        instructions.setString("Your last 7 recorded feelings");
        sf::FloatRect instructBounds = instructions.getLocalBounds();
        instructions.setOrigin(instructBounds.left + instructBounds.width / 2, instructBounds.top + instructBounds.height / 2);
        instructions.setPosition(400, 30);

        labels.setString("Happy = Yellow | Sad = Blue | Anxious = Orange | Apathetic = Green | Angry = Red");
        labels.setCharacterSize(16);
        labels.setFillColor(sf::Color::Black);
        sf::FloatRect labelsBounds = labels.getLocalBounds();
        labels.setOrigin(labelsBounds.left + labelsBounds.width / 2, labelsBounds.top + labelsBounds.height / 2);
        labels.setPosition(400, 60);
    }

    // colors for each feeling
    map<string, sf::Color> feeling_colors = {
        {"Happy", sf::Color::Yellow},
        {"Sad", sf::Color::Blue},
        {"Anxious", sf::Color(250, 150, 100)},
        {"Apathetic", sf::Color::Green},
        {"Angry", sf::Color::Red}
    };

    vector<sf::RectangleShape> progressBars;
    float x = 50.0;
    float y = 90.0;
    float width = 100.0;
    float height = 30.0;
    float spacing = 10.0;

    // draw rectangle for each feeling
    for (auto& feeling : last_feelings) {
        if (feeling_colors.find(feeling.first) != feeling_colors.end()) {
            sf::RectangleShape progressBar = createProgBar(x, y, width, height, feeling_colors[feeling.first]);
            progressBars.push_back(progressBar);
            y += height + spacing;
        } else { // error catching
            cout << "Unknown feeling: " << feeling.first << "\n";
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        for (auto& progressBar : progressBars) {
            window.draw(progressBar);
        }

        window.draw(instructions);
        window.draw(labels);

        window.display();
    }

    return 0;
}
