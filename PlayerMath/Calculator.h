#pragma once

#include "ICore.h"

namespace PlayerMath
{
	class Calculator : public ICore
	{
	public:
		Calculator();
		virtual ~Calculator();
		
		virtual bool Init( const Input & ) override;
		virtual void Start() override;
		virtual void Stop() override;
	};
	
} // namespace PlayerMath
