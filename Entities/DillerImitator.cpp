#include "DillerImitator.h"
#include <algorithm>

using namespace Entities;

DillerImitator::DillerImitator() : 
    IDiller()
{
	
}

DillerImitator::~DillerImitator()
{
	
}

Card DillerImitator::GetCard()
{
	auto index = std::rand() % ( _deck.size() + 1 );
	auto card = _deck.at( index );
	_deck.erase(_deck.begin() + index);
	
	return card;
}
