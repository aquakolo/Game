#include <SFML/Graphics.hpp>
#include "Events.cpp"

using namespace sf;
using namespace std;

const int szerokosc=1000,wysokosc=700,METR=50;
double FPS;

RenderWindow window(VideoMode(szerokosc, wysokosc), "Gra");
// OnStart,OnClose,OnKey,OnFps
int main(){
	
	Time time;
	Clock clock;
	Event event;
	Mouse mouse;
	OnStart();
	
	while (window.isOpen())
	{
		window.clear();
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) OnClose(), window.close();
			if (event.type == Event::Event::KeyPressed) OnKey(&event);
			if (event.type == Event::Event::MouseButtonPressed)
			{
				Vector2i a=mouse.getPosition(window);
				OnClick(a.x, a.y, mouse.isButtonPressed(Mouse::Left), mouse.isButtonPressed(Mouse::Right));
			}
		}
		OnFps(FPS);
		//***Dodatkowe funkcje wykonywane co klatkę***
		{
			
			
		}
		//	
		window.display();
		time=clock.getElapsedTime();
   		FPS=time.asSeconds();
		clock.restart(); 
	}
}
