#include "pch.h"
#include "Application.h"

#include "Cober/Events/ApplicationEvent.h"
#include "Cober/Log.h"

namespace Cober {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run() 
	{
		WindowResizeEvent e(1280, 720);
		CB_INFO(e);

		while (true);
	}
}
