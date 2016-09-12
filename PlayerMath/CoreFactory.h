#ifndef PLAYERMATH_COREFACTORY_H
#define PLAYERMATH_COREFACTORY_H

#include "ICore.h"
#include <memory>

namespace PlayerMath {
	
	class CoreFactory
	{
	public:
		static std::shared_ptr<ICore> CreateCore();
		
	private:
		CoreFactory() = delete;
	};
	
} // namespace PlayerMath

#endif // PLAYERMATH_COREFACTORY_H
