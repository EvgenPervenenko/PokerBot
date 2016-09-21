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

std::map<unsigned int, std::pair<Card, Card> > DillerImitator::GetDistribution()
{
	std::map<unsigned int, std::pair<Card, Card> > distribution;
	
	return distribution;
}

std::vector<Card> DillerImitator::GetFlop()
{
	std::vector<Card> flop;
	
	return flop;
}

Card DillerImitator::GetRiver()
{
	Card river;
	
	return river;
}

Card DillerImitator::GetTurn()
{
	Card turn;
	
	return turn;
}
