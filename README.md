# BeeBetter - EC 327 Final Project

## Team Patches

### Team Members
-Ellen Zheng (ellenz@bu.edu)
-Monirah Alodah (modah@bu.edu)
-Oumelbenine Tayeb (otayeb@bu.edu)
-Prashast Pandey (prashast@bu.edu)

### Links
GitHub Repository: [BeeBetter on GitHub](https://github.com/ezheng05/EC327.git)

Video Link: https://youtu.be/2FM6CKtAQZQ 
—
## Running the program

g++ --std=c++17 main.cpp profile.cpp feelings.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include -o app -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

Make sure to include the necessary libraries and SFML components

## Application Overview

BeeBetter is a mental health tracking application designed to help users manage and improve their emotional well-being. The main features of the application include:

-Feelings Survey: Users can record their current feelings and energy levels, receiving personalized suggestions based on their inputs.

-Surprise Me: A random activity generator to provide fun and engaging activities.

-Mini Games: Two de-stress games, "Bee Game" and "Bubble Popper," designed to provide a calming and engaging experience.

-User Profile: A personalized profile page displaying usage statistics and tracking progress over time.


### Target Users

BeeBetter is aimed at people who are looking for a simple, fun, and convenient way to manage everyday stress and track their mental health.



### Home Page
The main interface with an animated background and interactive buttons leading to core functionalities: feelings survey, mini games, random activity generator, and profile page.

### Feelings Survey Tab
Allows users to select their current feelings and energy levels, storing data for analysis and providing personalized suggestions.

### Games Tab

**Bubble Pop Game:** 
- Users pop bubbles for a relaxing experience.
- Sound effects and random bubble positions enhance engagement.

**Bee Game:** 
- Users control a bee to collect sunflowers, aiming to increase their score.
- Simple controls and random sunflower positions provide a fun, casual experience.

### Dice Roll Tab
Generates random activities from a predefined list, simulating a dice roll or card shuffle, providing a quick way to choose wellness activities.

### My Profile Tab
Displays user's last seven recorded feelings and energy levels using progress bars. Helps users track their emotional progress over time.

---
