#pragma once 

#include "Interface.hpp"

namespace My
{
	Interface IRuntimeModule
	{
	public:
		// 虚析构
		virtual ~IRuntimeModule(){};

		// 初始化
		virtual int Initialize() = 0;
		// 清理
		virtual void Finalize() = 0;

		// tick
		virtual  void Tick() = 0;
	};
}