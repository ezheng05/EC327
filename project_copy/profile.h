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

sf::RectangleShape createProgBar(float x, float y, float width, float height, sf::Color color);

int profile();

#endif // PROFILE_H
