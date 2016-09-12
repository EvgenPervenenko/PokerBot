#ifndef ENTITIES_PLAYER_H
#define ENTITIES_PLAYER_H

#include <utility>
#include <memory>
#include <map>
#include <vector>
#include "Card.h"
#include "PlayerMath/ICore.h"

namespace Entities {
	
	enum class Actions : unsigned short
	{
		Bet = 1, 
		Check, 
		Fold, 
		Raise, 
		Reraise,
		Call
	};
	
	class Player
	{
	public:
		Player();
		~Player() = default;
		
		Actions GetProbabilityAction( Actions );
		
		void Reset();
		
	private:
		unsigned _id;
		std::pair<Card, Card> _hand;
		std::shared_ptr<PlayerMath::ICore> _processor;
		unsigned long long _countPlayedRounds;
		unsigned long long _countRoundsInGame;
		double _bank;
		std::vector<Actions> _actions;
		static unsigned _idCounter;
	};
	
} // namespace Entities

#endif // ENTITIES_PLAYER_H
