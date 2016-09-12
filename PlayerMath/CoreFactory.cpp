#include "CoreFactory.h"
#include "Calculator.h"

using namespace PlayerMath;

std::shared_ptr<ICore> CoreFactory::CreateCore()
{
	return std::shared_ptr<ICore>(new Calculator);
}

