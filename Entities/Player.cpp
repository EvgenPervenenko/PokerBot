#include "Player.h"

using namespace Entities;

unsigned Entities::Player::_idCounter = 0;

Player::Player() : 
    _id( ++_idCounter ), 
    _countPlayedRounds( 0 ), 
    _countRoundsInGame( 0 ), 
    _bank( 0. )
{
}

Actions Player::GetProbabilityAction(Actions)
{
	return Actions::Fold;
}

void Player::Reset()
{
	_actions.clear();
	_hand = std::make_pair( Card(), Card() );
}
