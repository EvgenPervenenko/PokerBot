#pragma once

#include "Input.h"
#include "Output.h"

namespace PlayerMath
{
	class ICore
	{
	public:
		virtual bool Init( const Input & ) = 0;
		virtual void Start() = 0;
		virtual void Stop() = 0;
		
		virtual const Output &GetResult() const
		{
			return _outputData;
		}
		
		virtual ~ICore()
		{}
		
	protected:
		ICore()
		{}
		
	protected:
		Input _inputData;
		Output _outputData;
		
	};
	
} // namespace PlayerMath
