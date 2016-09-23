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
	
	std::vector<std::vector<Entities::Card> > groupsConsecutiveCards;
	
	for( size_t i = 1; i < temp.size(); ++i )
	{
		auto currentCard = temp.at( i - 1 );
		auto nextCard = temp.at( i );
		
		auto dif = static_cast<quint8>( nextCard.GetRank() ) 
		        - static_cast<quint8>( currentCard.GetRank() );
		std::vector<Entities::Card> consecutiveCards;
		
		if( dif == 1 )
		{
			consecutiveCards.push_back( currentCard );
			consecutiveCards.push_back( nextCard );
			++i;
		}
		
		while( dif < 2 && i < temp.size() )
		{
			
			currentCard = temp.at( i - 1 );
			nextCard = temp.at( i );
			
			dif = static_cast<quint8>( nextCard.GetRank() ) 
			        - static_cast<quint8>( currentCard.GetRank() );
			
			if( dif == 1 )
			{
				consecutiveCards.push_back( nextCard );
				++i;
			}
			else
				break;
		}
		
		if( consecutiveCards.size() > 1 )
			groupsConsecutiveCards.push_back( consecutiveCards );
	}
	
	bool isHoleyDraw( false );
	bool isDoubleSideDraw( false );
	
	if( groupsConsecutiveCards.size() == 1 )
	{
		auto consecutiveCards = groupsConsecutiveCards.at( 0 );
		
		if( consecutiveCards.size() == 4 )
		{
			isDoubleSideDraw = true;
		}
		else if( consecutiveCards.size() == 3 )
		{
			for( size_t i = 0; i < temp.size(); ++i )
			{
				auto currentCard = temp.at( i );
				
				auto iter = std::find_if( consecutiveCards.begin(), consecutiveCards.end(), 
				              [&]( const Entities::Card &c ) 
				{ return ( c.GetRank() == currentCard.GetRank() 
					       && c.GetSuit() == currentCard.GetSuit() ); });
				
				
				if( iter == consecutiveCards.end() )
				{
					auto dif1 = std::abs(static_cast<short>( consecutiveCards.at(0).GetRank() ) 
					                     - static_cast<short>( currentCard.GetRank() ) );
					
					auto dif2 = std::abs(static_cast<short>( consecutiveCards.at(2).GetRank() ) 
					                     - static_cast<short>( currentCard.GetRank() ) );
					
					if( dif1 == 2 || dif2 == 2 )
					{
						isHoleyDraw = true;
						break;
					}
				}
			}
			
			if( consecutiveCards.at( 0 ).GetRank() == Entities::Rank::Two )
			{
				auto iter = std::find_if( consecutiveCards.begin(), consecutiveCards.end(), 
				              [&]( const Entities::Card &c ) 
				{ return ( c.GetRank() == Entities::Rank::Ace ); });
				
				if( iter != consecutiveCards.end() )
					isHoleyDraw = true;
			}
		}
	}
	else if( groupsConsecutiveCards.size() == 2 )
	{
		auto consecutiveCards1 = groupsConsecutiveCards.at( 0 );
		auto consecutiveCards2 = groupsConsecutiveCards.at( 1 );
		
		auto dif1 = std::abs(static_cast<short>( consecutiveCards1.at(0).GetRank() ) 
		        - static_cast<short>( consecutiveCards2.at(1).GetRank() ) );
		
		auto dif2 = std::abs(static_cast<short>( consecutiveCards1.at(1).GetRank() ) 
		        - static_cast<short>( consecutiveCards2.at(0).GetRank() ) );
		
		if( dif1 == 2 || dif2 == 2 )
			isHoleyDraw = true;
	}
	
	if( isHoleyDraw )
		return 4;
	else if( isDoubleSideDraw )
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
