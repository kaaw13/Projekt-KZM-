#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>





	//Window
	sf::Window window(sf::VideoMode(640, 480), "Moja pierwsza gra", sf::Style::Titlebar | sf::Style::Close);
	sf::Event event;
	class Gra {
	private:
		sf::Window window;
		sf::Event event;

	public:
		Gra() : window(sf::VideoMode(640, 480), "Moja pierwsza gra", sf::Style::Titlebar | sf::Style::Close) {}

		void run() {
			//Game loop
			while (window.isOpen()) {
				//Event polling
				while (window.pollEvent(event)) {
					switch (event.type) {
					case sf::Event::Closed:
						window.close();
						break;
					case sf::Event::KeyPressed:
						if (event.key.code == sf::Keyboard::Escape) {
							window.close();
						}
						break;
					}
				}
				//Update

				//Render
				 //czyszczenie okna
				window.display(); //wyświetlanie
			}
		}
	};

	
	int main() {
		Gra gra;
		gra.run();
		return 0;
	}
