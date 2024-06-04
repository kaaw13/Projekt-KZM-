#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

int main()
{
   
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ruszajace sie kolo");

    
    sf::CircleShape circle(30);
    circle.setFillColor(sf::Color::Blue);

   
    float posX = static_cast<float>(std::rand() % (window.getSize().x - 2 * static_cast<int>(circle.getRadius())) + circle.getRadius());
    float posY = static_cast<float>(std::rand() % (window.getSize().y - 2 * static_cast<int>(circle.getRadius())) + circle.getRadius());
    circle.setPosition(posX, posY);

   
    float speedX = static_cast<float>(std::rand() % 50 - 10); 
    float speedY = static_cast<float>(std::rand() % 50 - 10);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        posX += speedX * 0.01f; 
        posY += speedY * 0.01f;

       
        if (posX + circle.getRadius()+2 >= window.getSize().x || posX  <= 0)
            speedX = -speedX; 
        if (posY + circle.getRadius()+2 >= window.getSize().y || posY  <= 0)
            speedY = -speedY; 

       
        circle.setPosition(posX, posY);

        
        window.clear();

       
        window.draw(circle);

        window.display();
    }

    return 0;
}
