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
		static qreal CalculateEV(const std::pair<Entities::Card, Entities::Card> &hand, 
		                          const std::vector<Entities::Card> &board , qreal bankWithRaise, qreal nessesaryCall);
		static qreal CalculateProbabilityForBestUpdate( const std::pair<Entities::Card, Entities::Card> &hand, 
		                                                const std::vector<Entities::Card> &board );
		static qreal CalculateProbabilityForLoss( qreal probabilityForBestUpdate );
		static qreal CoinForMinusProbability(const std::vector<Entities::Card> &board , qreal bank);
		
	private:
		static qint8 CalculateCountCardsForStreatInDeck( const std::vector<Entities::Card> &boardWithHand );
		static qint8 CalculateCountCardsForFlash( const std::vector<Entities::Card> &boardWithHand );
		static qint8 CalculateCountCardsForFlashInDeck( const std::vector<Entities::Card> &boardWithHand );
		static qint8 CalculateMaxCardsCountOneSuit( const std::vector<Entities::Card> &boardWithHand );
		static bool IsStreatDraw( const std::vector<Entities::Card> & );
		static bool IsFlashDraw( const std::vector<Entities::Card> & );
		
	private:
		ProbabilityMath() = delete;
	};
	
} // namespace Tools
