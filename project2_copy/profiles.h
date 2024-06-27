#ifndef PROFILE_H
#define PROFILE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <map>
#include "feelings.h"

using std::vector;
using std::map;
using std::string;
using std::pair;

// create progress bar
sf::RectangleShape createProgBar(float x, float y, float width, float height, sf::Color color) {
    sf::RectangleShape progressBar(sf::Vector2f(width, height));
    progressBar.setFillColor(color);
    progressBar.setPosition(x, y);
    return progressBar;
}

int profile() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Profile");

    // get last 7 feelings
    vector<pair<string,string>> last_feelings = getLastFeel();

    // progress bar colors for each feeling
    map<string, sf::Color> feeling_colors = {
        {"Happy", sf::Color::Yellow},
        {"Sad", sf::Color::Blue},
        {"Anxious", sf::Color(250, 150, 100)},
        {"Apathetic", sf::Color::Green},
        {"Angry", sf::Color::Red}
    };

    // create progress bars
    vector<sf::RectangleShape> progressBars;
    float x = 50.0;
    float y = 50.0;
    float width = 100.0;
    float height = 30.0;
    float spacing = 10.0;

    for (auto& feeling : last_feelings) {
        if (feeling_colors.find(feeling.first) != feeling_colors.end()) {
            sf::RectangleShape progressBar = createProgBar(x, y, width, height, feeling_colors[feeling.first]);
            progressBars.push_back(progressBar);
            y += height + spacing;
        } else {
            std::cerr << "Unknown feeling: " << feeling.first << "\n";
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        for (const auto& progressBar : progressBars) {
            window.draw(progressBar);
        }

        window.display();
    }

    return 0;
}

#endif
