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
		
		void TakePlace( unsigned short placeNumber, const std::shared_ptr<Player> & );
		
	private:
		std::map<unsigned short, std::shared_ptr<Player> > _places;
		std::vector<double> _bankChanging;
		
	};
	
} // namespace Entities

#endif // ENTITIES_TABLE_H
