#ifndef ENTITIES_ROUND_H
#define ENTITIES_ROUND_H

#include "Table.h"
#include <memory>
#include "IDiller.h"

namespace Entities {
	
	class Round
	{
	public:
		Round();
		
		const std::shared_ptr<Table> &GetGameInfo() const;
		const std::shared_ptr<IDiller> &GetDiller() const;
		
		void SetGameInfo(const std::shared_ptr<Table> &gameInfo);
		void SetDiller(const std::shared_ptr<IDiller> &diller);
		
	private:
		std::shared_ptr<Table> _gameInfo;
		std::shared_ptr<IDiller> _diller;
	};
	
} // namespace Entities

#endif // ENTITIES_ROUND_H
