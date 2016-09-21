#include "ProbabilityMath.h"
#include <QtMath>

using namespace Tools;


qreal ProbabilityMath::CalculateEV(qreal result1, qreal result2)
{
	return result1 + result2;
}

qreal ProbabilityMath::CalculateProbabilityForBestUpdate(const std::pair<Entities::Card, Entities::Card> &hand, 
                                                         const std::vector<Entities::Card> &board)
{
	std::vector<Entities::Card> temp = board;
	temp.push_back( hand.first );
	temp.push_back( hand.second );
	
	const quint8 countCardsInDeckInStart( 52 );
	quint8 countCardsInDeck = countCardsInDeckInStart - (quint8)temp.size();
	
	qreal probability( 0 );
	
	if( IsStreatDraw( temp ) )
		probability = CalculateCountCardsForStreat( temp ) / countCardsInDeck;
	else if( IsFlashDraw( temp ) )
		probability = CalculateCountCardsForFlash( temp ) / countCardsInDeck;
	
	return probability;
}

qint8 ProbabilityMath::CalculateCountCardsForFlash(const std::vector<Entities::Card> &boardWithHand)
{
	auto temp = boardWithHand;
	
	auto countHearts = (quint8)std::count_if( temp.begin(), temp.end(), 
	                                  [=](const Entities::Card &card)
	{return card.GetSuit() == Entities::Suit::Heart; } );
	
	auto countDimonds = (quint8)std::count_if( temp.begin(), temp.end(), 
	                                   [=](const Entities::Card &card)
	{return card.GetSuit() == Entities::Suit::Dimond; } );
	
	auto countClumbs = (quint8)std::count_if( temp.begin(), temp.end(), 
	                                  [=](const Entities::Card &card)
	{return card.GetSuit() == Entities::Suit::Clubs; } );
	
	auto countSpades = (quint8)(temp.size() - ( countHearts + countDimonds + countClumbs ));
	
	qint8 countCardsInFlashCombination( 5 );
	
	return countCardsInFlashCombination - qMax( qMax( countHearts, countDimonds ), 
	                                            qMax( countClumbs, countSpades ) );
}

qint8 ProbabilityMath::CalculateCountCardsForStreat(const std::vector<Entities::Card> &boardWithHand)
{
	auto temp = boardWithHand;
	
	std::sort( temp.begin(), temp.end(), 
	           []( const Entities::Card &c1, const Entities::Card &c2 )
	{
		return static_cast<unsigned short>( c1.GetRank() ) < static_cast<unsigned short>( c2.GetRank() );
	}
	);
	
	const quint8 countCardsInStreatCombination( 5 );
	qint8 countCardsForStreat( countCardsInStreatCombination );
	qint8 minCardsForStreat( countCardsInStreatCombination );
	
	for( size_t i = 1; i < temp.size(); ++i )
	{
		auto currentCardRank = static_cast<unsigned short>( temp.at( i - 1 ).GetRank() );
		auto nextCardRank = static_cast<unsigned short>( temp.at( i ).GetRank() );
		
		auto dif = nextCardRank - currentCardRank;
		
		if( dif != 0 )
			continue;
		else if( dif == 1 )
			--countCardsForStreat;
		else
		{
			countCardsForStreat = countCardsInStreatCombination;
			minCardsForStreat = qMin( countCardsForStreat, minCardsForStreat );
		}
	}
	
	return minCardsForStreat;
}

bool ProbabilityMath::IsStreatDraw(const std::vector<Entities::Card> &cards)
{
	auto countCardsForStreat = CalculateCountCardsForStreat( cards );
	
	return countCardsForStreat < 1;
}

bool ProbabilityMath::IsFlashDraw(const std::vector<Entities::Card> &cards)
{
	auto countCardsForFlash = CalculateCountCardsForFlash( cards );
	
	return countCardsForFlash < 2;
}
