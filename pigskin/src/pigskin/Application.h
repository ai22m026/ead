#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace PigSkin {

	class PS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined at client
	Application* CreateApplication();
}