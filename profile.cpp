#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include  <winodwmaxfeelings.cpp>


int main(){

	sf::RenderWindow window(sf::VideoMode(800,600), "My Profile");

	sf::Font font;

	sf::Texture texture = loadImageFromUrl ("https://images.app.goo.gl/cqZoWjtomP2e5eRc6");
	if (texture.getSize().x==0){
		std::cer<<"could not load image from URL";
		return -1;
	}


	sf::Text nameText;
	nameText.setFont(font);
	nameText.setCharacterSize(24);
	nameText.FillColor(sf::Color::White);
	nameText.setPosition(50,10);
	string userName;

	//display the input field 

	bool isEnteringName = true;
	while (isEnteringName && window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == Event::TextEnterned){
				if (event.text.unicode<128){
				if(event.text.unicode == '\b'&& !userName.empty()){
					userName += static_cast<char>(event.text.unicode);
				}

				nameText.setString("Name:"+userName);

			}
				}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return){
				is isEnteringName = false;
			}
		}

		window.clear(sf::Color::Black);
		window.draw(nameText);
		window.display();
	}

	//progress bar 
	st::RectangleShape progressBar(sf::Vector2f(300,30));
	progressBar.setPosition(400,400);


	std::string slected Emotion = "Happy";
	float progress = 0.5f;
	progressBar.setSize(sf::Vector2f(300*progress,30));
	progressBar.setFillColor(sf::Color::Green);


	std::string slected Emotion = "Sad";
	float progress = 0.1f;
	progressBar.setSize(sf::Vector2f(50*progress,5));
	progressBar.setFillColor(sf::Color::Red);

	std::string slected Emotion = "Anxies";
	float prograss = 0.3f;
	progressBar.setSize(sf::Vector2f(100*progress, 10));
	progressBar.setFillColor(sf::Color::Orange);

	while(window.isOpen()){
		sf::Event event;

		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sprite);
		window.draw(text);
		window.draw(progressBar);
		window.display();
	}
	return 0;
}






