#ifndef ENTITIES_DILLER_H
#define ENTITIES_DILLER_H

#include "Card.h"

namespace Entities {
	
	class IDiller
	{
	public:
		virtual Card GetCard() = 0;
		
		virtual ~IDiller()
		{}
		
	protected:
		IDiller()
		{}
	};
	
} // namespace Entities

#endif // ENTITIES_DILLER_H
