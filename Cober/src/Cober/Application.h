#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Cober {

	class CB_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in a client
	Application* CreateApplication();
}

