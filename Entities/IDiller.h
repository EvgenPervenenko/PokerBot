#ifndef ENTITIES_DILLER_H
#define ENTITIES_DILLER_H

#include "Card.h"
#include <map>
#include <vector>

namespace Entities {
	
	class IDiller
	{
	public:
		virtual Card GetCard() = 0;
		virtual std::map<unsigned int, std::pair<Card, Card> > GetDistribution() = 0;
		virtual std::vector<Card> GetFlop() = 0;
		virtual Card GetRiver() = 0;
		virtual Card GetTurn() = 0;
		
		virtual ~IDiller()
		{}
		
	protected:
		IDiller()
		{}
	};
	
} // namespace Entities

#endif // ENTITIES_DILLER_H
