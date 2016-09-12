#include "Round.h"

namespace Entities {
	
	Round::Round()
	{
		
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
	
} // namespace Entities
