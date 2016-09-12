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
		
	private:
		std::vector<Card> _deck;
	};
	
} // namespace Entities

#endif // ENTITIES_DILLERIMITATOR_H
