#include "Game.h"
#include "Entities/DillerFactory.h"
#include "Entities/IDiller.h"
#include "PlayerMath/CoreFactory.h"
#include "PlayerMath/ICore.h"

Game::Game()
{
	
}

void Game::StartRound()
{
	std::shared_ptr<Entities::Round> round( new Entities::Round );
	auto lastRound = _rounds.back();
	auto gameInfo = lastRound->GetGameInfo();
	round->SetGameInfo( gameInfo );
}
