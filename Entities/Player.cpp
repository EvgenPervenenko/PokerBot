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

void Player::AddAction( Actions action)
{
	_actions.push_back( action );
}

void Player::AddCard(const Card &card)
{
	if( _hand.first.GetRank() == Rank::Undefind )
		_hand.first = card;
	else
		_hand.second = card;
}

const std::pair<Card, Card> &Player::GetHand() const
{
    return _hand;
}

void Player::SetHand(const std::pair<Card, Card> &hand)
{
    _hand = hand;
}

unsigned Player::GetId() const
{
    return _id;
}

void Player::SetId(const unsigned &id)
{
    _id = id;
}

const std::shared_ptr<PlayerMath::ICore> &Player::GetProcessor() const
{
    return _processor;
}

void Player::SetProcessor(const std::shared_ptr<PlayerMath::ICore> &processor)
{
    _processor = processor;
}

unsigned long long Player::GetCountPlayedRounds() const
{
    return _countPlayedRounds;
}

unsigned long long Player::GetCountRoundsInGame() const
{
    return _countRoundsInGame;
}

double Player::GetBank() const
{
    return _bank;
}

void Player::SetBank(double bank)
{
    _bank = bank;
}
