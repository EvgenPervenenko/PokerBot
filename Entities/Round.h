#ifndef ENTITIES_ROUND_H
#define ENTITIES_ROUND_H

#include "Table.h"
#include <memory>
#include "IDiller.h"

namespace Entities {
	
	enum class Stage : unsigned short
	{
		Start = 0, 
		Distribution, 
		Flop, 
		River, 
		Turn
	};
	
	class Round
	{
	public:
		Round();
		
		void Start();
		
		const std::shared_ptr<Table> &GetGameInfo() const;
		const std::shared_ptr<IDiller> &GetDiller() const;
		
		void SetGameInfo(const std::shared_ptr<Table> &gameInfo);
		void SetDiller(const std::shared_ptr<IDiller> &diller);
		
	private:
		void DistributeCards();
		void Flop();
		void River();
		void Turn();
		
	private:
		std::shared_ptr<Table> _gameInfo;
		std::shared_ptr<IDiller> _diller;
		Stage _currentStage;
	};
	
} // namespace Entities

#endif // ENTITIES_ROUND_H
