#include "DillerImitator.h"
#include <algorithm>
#include "Entities/Card.h"

using namespace Entities;

DillerImitator::DillerImitator() : 
    IDiller()
{
	auto limit = static_cast<unsigned short>( Entities::Rank::Ace );
	for( auto rank = static_cast<unsigned short>(Entities::Rank::Two); rank <= limit; ++rank )
	{
		auto suitLimit = static_cast<unsigned short>( Entities::Suit::Clubs );
		
		for( auto suit = static_cast<unsigned short>( Entities::Suit::Heart ); suit <= suitLimit; ++suit )
		{
			_deck.push_back( Entities::Card( static_cast<Entities::Rank>(rank), static_cast<Entities::Suit>(suit) ) );
		}
	}
}

DillerImitator::~DillerImitator()
{
	
}

Card DillerImitator::GetCard()
{
	auto index = std::rand() % ( _deck.size() );
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
