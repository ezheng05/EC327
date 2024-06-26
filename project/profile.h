#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>

sf::Texture loadImageFromUrl(const string& url , const string& path);
void loadResources(sf::Music &music, sf::Font& font);

string getUserName();
int getUserFeeling();
void setupProgressBar(sf::RectangleShape& progressBar , int feeling);

int profile(){

	sf::RenderWindow window(sf::VideoMode(800,600), "My Profile");

	sf::Music music;
	sf::Font font;

	loadResources(music, font);
	music.play();

	sf::Texture texture;
	if (!texture.loadFromFile("profile.jpg")){
		std::cout<<"could not load image from URL";
		return -1;
	}

	sf::Sprite sprite(texture);

	std::string name = getUserName();
	int feeling = getUserFeeling();

	sf::Text text (name, font, 30);
	text.setPosition(10,10);

	sf::RectangleShape progressBar(sf::Vector2f(200,30));
	progressBar.setPosition(300,550);
	setupProgressBar(progressBar, feeling);

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

sf::Texture loadImageFromUrl (const std::string& url, const std::string& path){
	sf::Texture texture;
	sf::Http http(url);
	sf::Http::Request request(path);
	sf::Http::Response response = http.sendRequest(request);

	if(response.getStatus()== sf::Http::Response::Ok){

		const std::string& body = response.getBody();
		if(!texture.loadFromMemory(body.c_str(),body.size())){
			std::cerr <<"Could not load image from image\n";
		}

		else{
			cout<<"Faild";
		}
	}
	return texture;
}

void loadResources(sf::Music& music, sf::Font& font){

	if (!music.openFromFile("https://youtu.be/J3lfFxqa24Q?si=vkjZmT5BSYUYZ-4")){
		std::cerr<<"could not load music\n";
		exit(-1);
	}

	music.setLoop(true);

	if (!font.loadFromFile("https://youtu.be/J3lfFxqa24Q?si=vkjZmT5BSYUYZ-4")){
		std::cerr<<"Could not load font\n";
		exit(-1);
	}
}

void setupProgressBar(sf::RectangleShape& progressBar, int feeling){
	if (feeling == 0 ){
		progressBar.setSize(sf::Vector2f(50,30));
		progressBar.setFillColor(sf::Color::Red);
	}

	else if (feeling == 1){
		progressBar.setSize(sf::Vector2f(150,30));
		progressBar.setFillColor(sf::Color(150, 50, 250));
	}

	else if(feeling == 2){
		progressBar.setSize(sf::Vector2f(200,30));
		progressBar.setFillColor(sf::Color::Green);
	}
}


