#include "DillerFactory.h"
#include "DillerImitator.h"

namespace Entities {
	
	std::shared_ptr<IDiller> DillerFactory::CreateDiller()
	{
		return std::shared_ptr<IDiller>(new DillerImitator);
	}
	
	
} // namespace Entities
