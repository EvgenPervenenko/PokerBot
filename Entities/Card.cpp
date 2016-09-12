#include "Card.h"

using namespace Entities;

Card::Card() : 
    _rank( Rank::Undefind ), 
    _suit( Suit::Undefind )
{
	
}

Card::Card(Rank rank, Suit suit) :
    _rank( rank ), 
    _suit( suit )
{
	
}

Card::~Card()
{
	
}

Rank Card::GetRank() const
{
	return _rank;
}

void Card::SetRank(Rank rank)
{
	_rank = rank;
}

Suit Card::GetSuit() const
{
	return _suit;
}

void Card::SetSuit(Suit suit)
{
	_suit = suit;
}
