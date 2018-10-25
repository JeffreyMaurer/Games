#include "Lepton.h"


Lepton::Lepton(float x, float y) :
pos(x, y),
vel(5,0)
{
	texture.loadFromFile("Lepton.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos);
}
void Lepton::update()
{
	pos += vel;
	sprite.move(vel);
}

sf::Texture Lepton::texture = sf::Texture();

Lepton::~Lepton()
{
}
