#ifndef ENTITIES_DILLERIMITATOR_H
#define ENTITIES_DILLERIMITATOR_H

#include "IDiller.h"
#include <vector>

namespace Entities {
	
	class DillerImitator : public IDiller
	{
	public:
		DillerImitator();
		virtual ~DillerImitator();
		
		virtual Card GetCard() override;
		virtual std::map<unsigned int, std::pair<Card, Card> > GetDistribution() override;
		virtual std::vector<Card> GetFlop() override;
		virtual Card GetRiver() override;
		virtual Card GetTurn() override;
		
	private:
		std::vector<Card> _deck;
	};
	
} // namespace Entities

#endif // ENTITIES_DILLERIMITATOR_H
