#pragma once

#include <QtGlobal>
#include "../Entities/Card.h"
#include "../Entities/Table.h"
#include <memory>
#include <vector>

namespace Tools {
	class ProbabilityMath
	{
	public:
		static qreal CalculateEV( qreal result1, qreal result2 );
		static qreal CalculateProbabilityForBestUpdate( const std::pair<Entities::Card, Entities::Card> &hand, 
		                                            const std::vector<Entities::Card> &board );
		
	private:
		static qint8 CalculateCountCardsForStreat( const std::vector<Entities::Card> &boardWithHand );
		static qint8 CalculateCountCardsForFlash( const std::vector<Entities::Card> &boardWithHand );
		static bool IsStreatDraw( const std::vector<Entities::Card> & );
		static bool IsFlashDraw( const std::vector<Entities::Card> & );
		
	private:
		ProbabilityMath() = delete;
	};
	
} // namespace Tools
