#ifndef FEELINGS_H
#define FEELINGS_H

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

extern vector<pair<string, string>> feeling_entries; // declare as extern

void createbutton(sf::Text &button, sf::Font &font, const string &button_name, float xposition, float yposition);

int handle_events(sf::RenderWindow &window, sf::Event &event, vector<sf::Text> &buttons);

string suggestions(string &selected_feeling, string &selected_energy);

void addFeel(string &feeling, string &energy);

vector<pair<string, string>> getLastFeel();

int feelings();

#endif 
