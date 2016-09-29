#include "Game.h"
#include "Entities/DillerFactory.h"
#include "Entities/IDiller.h"
#include "Tools/ProbabilityMath.h"
#include "Entities/Player.h"

#include <QDebug>

Game::Game()
{
	///NOTE: for test(remove if release)
	std::shared_ptr<Entities::Round> round( new Entities::Round );
	std::shared_ptr<Entities::Table> gameInfo( new Entities::Table );
	
	gameInfo->TakePlace( 1, std::shared_ptr<Entities::Player>( new Entities::Player ) );
	gameInfo->TakePlace( 2, std::shared_ptr<Entities::Player>( new Entities::Player ) );
	gameInfo->TakePlace( 3, std::shared_ptr<Entities::Player>( new Entities::Player ) );
	gameInfo->TakePlace( 4, std::shared_ptr<Entities::Player>( new Entities::Player ) );
	
	round->SetGameInfo( gameInfo );
	
}

void Game::StartRound()
{
	std::shared_ptr<Entities::Round> round( new Entities::Round );
	
	auto gameInfo = ( _rounds.size() != 0 ) 
	        ? _rounds.back()->GetGameInfo() 
	        : std::shared_ptr<Entities::Table>( new Entities::Table );
	
	round->SetGameInfo( gameInfo );
	
	auto diller = Entities::DillerFactory::CreateDiller();
	round->SetDiller( diller );
	
	round->Start();
	
	///NOTE: for test(remove if release)
	round->Start();
	
	auto hand = std::make_pair( Entities::Card( Entities::Rank::King, Entities::Suit::Clubs ), 
	                                            Entities::Card( Entities::Rank::Ten, Entities::Suit::Clubs ) );
	
	auto board = round->GetGameInfo()->GetBoard();
//	board.push_back( Entities::Card( Entities::Rank::Two, Entities::Suit::Clubs ) );
	auto coin = Tools::ProbabilityMath::CoinForMinusProbability( board, 150 );
	auto ev = Tools::ProbabilityMath::CalculateEV( hand, board, 150 + 174 , 174 );
	
	qDebug() << ev << "::" << "coin = " << coin;
}
