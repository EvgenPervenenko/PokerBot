#include "ProbabilityMath.h"
#include <QtMath>
#include <QDebug>

using namespace Tools;


qreal ProbabilityMath::CalculateEV(const std::pair<Entities::Card, Entities::Card> &hand, 
                                   const std::vector<Entities::Card> &board, 
                                   qreal bankWithRaise, 
                                   qreal nessesaryCall)
{
	auto probabilityForBestHand = CalculateProbabilityForBestUpdate( hand, board );
	auto probabilityForLoss = CalculateProbabilityForLoss( probabilityForBestHand );
	
	const auto countCardOnFlop( 3 );
	
	if( board.size() == countCardOnFlop )
	{
		auto tempBoard = board;
		tempBoard.push_back( Entities::Card( Entities::Rank::Undefind, Entities::Suit::Undefind ) );
		
		auto probabilityForBestHandOnRiver = CalculateProbabilityForBestUpdate( hand, board );
		auto probabilityForLossOnRiver = CalculateProbabilityForLoss( probabilityForBestHand );
		
		auto resulWinProbability = probabilityForBestHand * probabilityForLossOnRiver 
		        + probabilityForBestHandOnRiver * probabilityForLoss 
		        + probabilityForBestHand * probabilityForBestHandOnRiver;
		
		probabilityForBestHand = resulWinProbability;
		probabilityForLoss = CalculateProbabilityForLoss( probabilityForBestHand );
	}
	
	qDebug() << "probabilityForBestHand = " << probabilityForBestHand;
	qDebug() << "probabilityForLoss = " << probabilityForLoss;
	
	return ( ( probabilityForBestHand * bankWithRaise ) - ( probabilityForLoss * nessesaryCall ) );
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
		probability = (qreal)CalculateCountCardsForStreatInDeck( temp ) / countCardsInDeck;
	else if( IsFlashDraw( temp ) )
		probability = (qreal)CalculateCountCardsForFlashInDeck( temp ) / countCardsInDeck;
	
	return probability;
}

qreal ProbabilityMath::CalculateProbabilityForLoss(qreal probabilityForBestUpdate)
{
	return 1 - probabilityForBestUpdate;
}

qint8 ProbabilityMath::CalculateCountCardsForFlash(const std::vector<Entities::Card> &boardWithHand)
{
	qint8 countCardsInFlashCombination( 5 );
	
	auto countCards = CalculateMaxCardsCountOneSuit( boardWithHand );
	
	return countCardsInFlashCombination - countCards;
}

qint8 ProbabilityMath::CalculateCountCardsForFlashInDeck(const std::vector<Entities::Card> &boardWithHand)
{
	quint8 countOneSuitCardsInDeck( 13 );
	
	auto countCards = CalculateMaxCardsCountOneSuit( boardWithHand );
	
	return countOneSuitCardsInDeck - countCards;
}

qint8 ProbabilityMath::CalculateMaxCardsCountOneSuit(const std::vector<Entities::Card> &boardWithHand)
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
	
	return qMax( qMax( countHearts, countDimonds ), 
	             qMax( countClumbs, countSpades ) );
}

qint8 ProbabilityMath::CalculateCountCardsForStreatInDeck(const std::vector<Entities::Card> &boardWithHand)
{
	if( boardWithHand.size() < 3 )
		return 0;
	
	auto temp = boardWithHand;
	
	std::sort( temp.begin(), temp.end(), 
	           []( const Entities::Card &c1, const Entities::Card &c2 )
	{
		return static_cast<unsigned short>( c1.GetRank() ) < static_cast<unsigned short>( c2.GetRank() );
	}
	);
	
	bool isHoleStreatDraw( false );
	auto countCards( 0 );
	
	for( size_t i = 0; i < temp.size(); ++i )
	{
		auto countCardsInDeq( 1 );
		auto currentCard = temp.at( i );
		bool isFirstHole( false );
		
		for( size_t j = i + 1; j < temp.size(); ++j )
		{
			auto nextCard = temp.at( j );
			
			auto dif = static_cast<quint8>( nextCard.GetRank() ) - static_cast<quint8>( currentCard.GetRank() );
			if( dif == 1 )
			{
				currentCard = nextCard;
				++countCardsInDeq;
			}
			else if( isFirstHole == true )
				break;
			else if( dif == 2 )
			{
				isFirstHole = true;
			}
			else
				break;
		}
		
		if( countCardsInDeq > 3 )
		{
			isHoleStreatDraw = isFirstHole;
			countCards = countCardsInDeq;
			break;
		}
	}
	
	if( isHoleStreatDraw )
		return 4;
	else if( countCards == 4 )
		return 8;
	else
		return 0;
}

bool ProbabilityMath::IsStreatDraw(const std::vector<Entities::Card> &cards)
{
	auto countCardsForStreat = CalculateCountCardsForStreatInDeck( cards );
	
	return countCardsForStreat;
}

bool ProbabilityMath::IsFlashDraw(const std::vector<Entities::Card> &cards)
{
	auto countCardsForFlash = CalculateCountCardsForFlashInDeck( cards );
	
	return countCardsForFlash == 9;
}
