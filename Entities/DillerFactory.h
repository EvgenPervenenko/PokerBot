#ifndef ENTITIES_DILLERFACTORY_H
#define ENTITIES_DILLERFACTORY_H

#include "IDiller.h"
#include <memory>

namespace Entities {
	
	class DillerFactory
	{
	public:
		static std::shared_ptr<IDiller> CreateDiller();
		
	private:
		DillerFactory() = delete;
	};
	
} // namespace Entities

#endif // ENTITIES_DILLERFACTORY_H
