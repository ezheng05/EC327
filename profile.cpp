#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include <vector>
#include  <winodwmaxfeelings.cpp>

//uploading the image from the url

sf::Texture loadImageFromUrl (const std::string& url, const std::string& path){
	sf::Texture texture;
	sf::Http http(url);
	sf::Http::Request request(path);
	sf::Http::Response response = http.sendRequest(request);

	if(response.getSatus()== sf::Http::Response::Ok){
//error handeling in case the image does not load in the game 
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

//reding the music from the url 
void loadResourcs(sf::Music& music, sf::Font& font){

	if (!music.openFromFile("https://youtu.be/J3lfFxqa24Q?si=vkjZmT5BSYUYZ-4")){
		std::cerr<<"could not load music\n";
		exit(-1);
	}

	music .setLoop(true);

	if (!font.openFromFile("https://youtu.be/J3lfFxqa24Q?si=vkjZmT5BSYUYZ-4")){
		std::cerr<<"Could not load front\n";
		exit(-1);


	}
}
//user input
string getUserName();
int getUserFeeling();

//making the bar and size 
void setupProgressBar(sf::RectangleShape& progressBar , int feeling){
	if (feeling == 0 ){
		progressBar.setSize(sf::Vector2f(200,30));
		progressBar.setFillColor(sf::Color::Green);
	}

	else if(feeling == 1){
		progressBar.setSize(sf::Vector2f(150,30));
		progressBar.setFillColor(sf::Color::Red);
	}
}


int main(){

	sf::RenderWindow window(sf::VideoMode(800,600), "My Profile");

	sf::Music music;
	sf::Font font;

	loadResourcs(music, font);
	music.play();

	sf::Texture texture = loadImageFromUrl ("https://images.app.goo.gl/cqZoWjtomP2e5eRc6");
	if (texture.getSize().x==0){
		std::cer<<"could not load image from URL";
		return -1;
	}

	sf::Sprite sprite(texture);

	std::string name = getUserName();
	int feeling = getUserFeeling();
//display the name on top of the page

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






