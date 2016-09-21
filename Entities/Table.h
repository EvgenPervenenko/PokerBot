#ifndef ENTITIES_TABLE_H
#define ENTITIES_TABLE_H

#include <vector>
#include <map>
#include "Player.h"
#include <memory>

namespace Entities {
	
	class Table
	{
	public:
		Table();
		
		std::vector<unsigned short> GetFreePlaces();
		const std::map<unsigned short, std::shared_ptr<Player> > &GetPlaces() const;
		const std::vector<Card> &GetBoard() const;
		
		void TakePlace( unsigned short placeNumber, const std::shared_ptr<Player> & );
		
		void AddCardOnBoard( const Card & );
		
		
	private:
		std::map<unsigned short, std::shared_ptr<Player> > _places;
		std::vector<double> _bankChanging;
		std::vector<Card> _board;
	};
	
} // namespace Entities

#endif // ENTITIES_TABLE_H
