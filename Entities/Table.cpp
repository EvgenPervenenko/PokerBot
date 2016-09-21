#include "Table.h"

#include <algorithm>
#include <utility>

using namespace Entities;

Table::Table()
{
	const unsigned short firstPlace = 1;
	const unsigned short lastPlace = 9;
	
	for( auto i = firstPlace; i <= lastPlace; ++i )
		_places.insert( std::make_pair( i, std::shared_ptr<Player>(nullptr) ) );
}

std::vector<unsigned short> Table::GetFreePlaces()
{
	std::vector<unsigned short> freePlaces;
	
	for( auto i = _places.cbegin(); i != _places.cend(); ++i )
		if( i->second.get() == nullptr )
			freePlaces.push_back( i->first );
	
	return freePlaces;
}

void Table::TakePlace(unsigned short placeNumber, const std::shared_ptr<Player> &player)
{
	if( _places.find( placeNumber ) == _places.end() )
		return;
	
	_places.insert( std::make_pair( placeNumber, player ) );
}

void Table::AddCardOnBoard(const Card &card)
{
	_board.push_back( card );
}

const std::vector<Card> &Table::GetBoard() const
{
	return _board;
}

const std::map<unsigned short, std::shared_ptr<Player> > &Table::GetPlaces() const
{
	return _places;
}
