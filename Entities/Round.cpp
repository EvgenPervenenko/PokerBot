#include "Round.h"

using namespace Entities;

Round::Round() : 
    _currentStage( Stage::Start )
{
	
}

void Round::Start()
{
	unsigned short temp = static_cast<unsigned short>( _currentStage );
	++temp;
	_currentStage = static_cast<Stage>(temp);
	
	switch (_currentStage) {
	case Stage::Distribution:
		DistributeCards();
		break;
	case Stage::Flop:
		Flop();
		break;
	case Stage::River:
		River();
		break;
	case Stage::Turn:
		Turn();
		break;
	default:
		break;
	}
}

const std::shared_ptr<Table> &Round::GetGameInfo() const
{
	return _gameInfo;
}

void Round::SetGameInfo(const std::shared_ptr<Table> &gameInfo)
{
	_gameInfo = gameInfo;
}

const std::shared_ptr<IDiller> &Round::GetDiller() const
{
	return _diller;
}

void Round::SetDiller(const std::shared_ptr<IDiller> &diller)
{
	_diller = diller;
}

void Round::DistributeCards()
{
	for( auto it = _gameInfo->GetPlaces().cbegin(); it != _gameInfo->GetPlaces().cend(); ++it )
	{
		if( it->second.get() != nullptr )
		{
			auto card = _diller->GetCard();
			it->second->AddCard( card );
		}
	}
}

void Round::Flop()
{
	const unsigned short countCardOnFlop = 3;
	for( auto counter = 0; counter < countCardOnFlop; ++counter )
	{
		auto card = _diller->GetCard();
		_gameInfo->AddCardOnBoard( card );
	}
}

void Round::River()
{
	
}

void Round::Turn()
{
	
}
