#ifndef GAME_H
#define GAME_H

#include "Entities/Round.h"
#include <vector>
#include <memory>

class Game
{
public:
	Game();
	
	void StartRound();
	
private:
	std::vector<std::shared_ptr<Entities::Round> > _rounds;
};

#endif // GAME_H
