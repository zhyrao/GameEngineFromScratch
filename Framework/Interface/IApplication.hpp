#pragma once 

#include "Interface.hpp"
#include "IRuntimeModule.hpp"

namespace My
{
	Interface IApplication : implements IRuntimeModule
	{
	public:
		virtual int Initialize() = 0;
		virtual void Finalize() = 0;

		// once cycle of the main loop
		virtual void Tick() = 0;

		// check if need quit
		virtual bool IsQuit() = 0;
	};
}