#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

/**
* \brief this function is used to create a button using SFML text object
* @param button: this SFML text object is used to represent the button
* @param Font: this SFML test object is used to represent the font of the button's text   
* @param buttonName: the string to be displayed within the button
* @param xPosition : determine the respective x coordinate of the button
* @param yPosition : determine the respective x coordinate of the button 
 */


void createbutton(sf::Text &button, sf::Font &font, const string &button_name, float xposition, float yposition){
    button.setFont(font);
    button.setString(button_name);
    button.setCharacterSize(24);
    button.setFillColor(sf::Color::Magenta);
    button.setPosition(xposition, yposition);
}

/**
* \brief this function is meant to handle events and check if the mouse clicks on any button
* @param window:this SFML window object is the main window of the program
* @param event:this SFML event object is used to define a system event and its parameters 
* @param buttons: this vector of SFML text objects represents the buttons
*/

int handle_events(sf::RenderWindow &window, sf::Event &event, vector<sf::Text> &buttons){
    while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed) window.close();           
            if (event.type == sf::Event::Resized){
                sf::FloatRect VisibleArea(0,0,event.size.width, event.size.height);
                window.setView(sf::View(VisibleArea));

            }
            if(event.mouseButton.button==sf::Mouse::Left && event.type==sf::Event::MouseButtonPressed ){
                    sf::Vector2i mouseposition=sf::Mouse::getPosition(window);
                    for(int i=0;i<buttons.size();++i){
                        if(buttons[i].getGlobalBounds().contains(mouseposition.x, mouseposition.y)){
                            return i;

                 }
             }
        }
    }
return -1;
}

string suggestions(string &selected_feeling,string &selected_energy){
    if(selected_feeling=="Happy"&& selected_energy=="High Energy"){
        return "That's amazing! Reward yourself!";
    }
    else if(selected_feeling=="Happy"&& selected_energy=="Moderate Energy"){
        return "It's amazing that you're happy!\nTry to do something to give yourself an energy boost!\nChat with a friend, make a refreshing beverage,\nstretch, reconnect with nature!";
    }
    else if(selected_feeling=="Happy"&& selected_energy=="Low Energy"){
        return "It's amazing that you're happy!\nTry to do something to give yourself an energy boost! \nchat with a friend, make a refreshing beverage,\nstretch, reconnect with nature!";
    }
    else if(selected_feeling=="Sad"&& selected_energy=="High Energy"){
        return "Let's focus on bringing your mood up.\nThink about what you love to do that's\nguaranteed to increase your morale.\nPerhaps go for a walk, journal,\nor simply vent to someone you trust ";
    }
     else if(selected_feeling=="Sad"&& selected_energy=="Moderate Energy"){
        return "Let's focus on bringing your mood up.\nThink about what you love to do that's\nguaranteed to increase your morale.\nPerhaps go for a walk, journal,\nor simply vent to someone you trust ";
    }
     else if(selected_feeling=="Sad"&& selected_energy=="Low Energy"){
        return "Let's focus on bringing both your mood and energy up.\nPerhaps focusing on lifting your energy will reflect on\nyour mood Think about the optimal activity that will\nlift your energy up Maybe you could go on a small\nwalk and grab yourself a treat, maybe excercise\nfor a bit to increase the production of endorphins\nfor a mood and energy lift at the same time! ";
    }
    else if(selected_feeling=="Anxious"&& selected_energy=="High Energy"){
        return "Let's focus on easing your anxiety, \nperform breathing excercises to decrease\nstress hormones and re-center your mind.\nFirst, exhale through your mouth, then close your mouth\nand inhale through your nose Hold your breath for a while\nand repeat the steps";
    }
     else if(selected_feeling=="Anxious"&& selected_energy=="Moderate Energy"){
        return "Let's focus on easing your anxiety, \nperform breathing excercises to decrease\nstress hormones and re-center your mind.\nFirst, exhale through your mouth, then close your mouth\nand inhale through your nose Hold your breath for a while\nand repeat the steps";
    }
     else if(selected_feeling=="Anxious"&& selected_energy=="Low Energy"){
        return "Let's focus on easing your anxiety as well as\nlifting your energy, First perform breathing\nexcercises to decrease stress hormones and re-center\nyour mind. First, exhale through your mouth,\nthen close your mouth and inhale through your nose\nHold your breath for a while and repeat the steps\nOnce you feel that your anxiety has calmed\nif you're still up for it, try to lift your energy up by\ndoing something that won't overstimulate you\nAvoid intense excercise and instead try\ngoing for a walk for increased endorphin\nproduction while simultaneously\nregulating your nervous system ";
    }
     else if(selected_feeling=="Apathetic"&& selected_energy=="High Energy"){
        return "Let's try to lift up your mood.\nThink about activities that you'd enjoy\nthat will lift your morale\nSince your energy level is\nhigh. Try excercising to increase endorphin production\nto lift up your mood!";
    }
    else if(selected_feeling=="Apathetic"&& selected_energy=="Moderate Energy"){
        return "Let's try to lift up your mood.\nThink about activities that you'd enjoy\nthat will lift your morale.\nTry excercising to increase endorphin production to lift\nup your mood!";
    }
     else if(selected_feeling=="Apathetic"&& selected_energy=="Low Energy"){
        return "Let's try to lift up your mood and energy.\nFirst, think about activities that you'd enjoy\nthat will lift your morale\nSince your energy level is\nlow. Try going for a walk to increase endorphin production\nto lift up your mood and energy while\nsimultaneously not over-exerting yourself";
     }
    else if(selected_feeling=="Angry"&& selected_energy=="High Energy"){
        return "Breathe and think about the following.\nIs the thing that's making you feel\nangry going to matter in 72 hours?\nIf not, try to avoid making impulsive decisions by\ndistracting yourself from the situation.\nGoing for a walk and fresh air may be\nthe best solution to distract yourself\nand reflect on how to best handle the situation";
     }
     else if(selected_feeling=="Angry"&& selected_energy=="Moderate Energy"){
        return "Breathe and think about the following.\nIs the thing that's making you feel\nangry going to matter in 72 hours?\nIf not, try to avoid making impulsive decisions by\ndistracting yourself from the situation.\nGoing for a walk and fresh air may be\nthe best solution to distract yourself\nand reflect on how to best handle the situation";
     }
     else if(selected_feeling=="Angry"&& selected_energy=="Low Energy"){
        return "Breathe and think about the following.\nIs the thing that's making you feel\nangry going to matter in 72 hours?\nIf not, try to avoid making impulsive decisions by\ndistracting yourself from the situation.\nGoing for a walk and fresh air may be\nthe best solution to distract yourself\nand reflect on how to best handle the situation";
     }
    
    return "you have selected " + selected_feeling + " & " + selected_energy;
}

int feelings(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Feelings");
    sf::Texture image;
     if(!image.loadFromFile("pic_teddy.jpeg")){
        cerr<<"error loading image"<<endl;
        return -1;
    }
    sf::Sprite sprite(image);
    sprite.setPosition(500,250);
    sprite.scale(0.5,0.5);
    vector<string> feeling={"Happy", "Sad", "Anxious", "Apathetic", "Angry"};
    vector<string> energy={"High Energy", "Moderate Energy", "Low Energy"};
    vector<sf::Text> feeling_buttons(feeling.size());
    vector<sf::Text> energy_buttons(energy.size());
    sf::Text reset_button;
    sf::Font font;
    if(!font.loadFromFile("/Library/Fonts/Arial Unicode.ttf")){
        cerr<<"error loading font"<<endl;
        return -1;
    }

    sf::RectangleShape message_box(sf::Vector2f(500,100));
    message_box.setFillColor(sf::Color(0,0,0,150));
    message_box.setPosition(200,250);
    sf::Text message_text;
    message_text.setFont(font);
    message_text.setCharacterSize(24);
    message_text.setFillColor(sf::Color::Magenta);
    message_text.setPosition(50,100);

    for(int i=0;i<feeling.size();++i){
        createbutton(feeling_buttons[i],font,feeling[i],100,50+i*50);
    }

    for(int i=0;i<energy.size();++i){
        createbutton(energy_buttons[i],font,energy[i],100,50+i*50);
    }
    createbutton(reset_button,font,"Go back to main page",500,550);
    
    bool show_feelings=true;
    bool show_message=false;
    while(window.isOpen()){
        sf::Event event;
        int selected_feeling, selected_energy;
        if(show_feelings){
            selected_feeling=handle_events(window,event,feeling_buttons);
            if(selected_feeling != -1){
                cout<<feeling[selected_feeling]<<"\n";
                show_feelings=false;
                window.clear(sf::Color::White);
                window.draw(sprite);
                for(auto &button:energy_buttons){
                    window.draw(button);
            }
            window.display();
            }
        }
        else if(!show_message){
            selected_energy=handle_events(window,event,energy_buttons);
            if(selected_energy!= -1){
                cout<<energy[selected_energy]<<"\n";
                string message=suggestions(feeling[selected_feeling],energy[selected_energy]);
                message_text.setString(message);
                show_message=true;
                window.clear(sf::Color::White);
                window.draw(sprite);
                window.draw(message_text);
                window.draw(reset_button);
                window.display();
            }
        }
        else{
            vector<sf::Text> reset_buttons={reset_button};
           int clicked_reset=handle_events(window,event,reset_buttons);
            if(clicked_reset!=-1){
                show_feelings=true;
                show_message=false;
                window.clear(sf::Color::White);
                for(auto &button:feeling_buttons){
                    window.draw(button);
                  }
                  window.draw(sprite);
                  window.display();
            }
        }
        if(!show_message){
            window.clear(sf::Color::White);
            window.draw(sprite);
            if(show_feelings){
                for(auto &button:feeling_buttons){
                    window.draw(button);
                  }
            }

            else{
                for(auto &button:energy_buttons){
                window.draw(button);
            }

            }
            window.display();
            }

    
    }
return 0;
}    

