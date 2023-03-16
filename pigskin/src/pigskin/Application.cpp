#include "Application.h"

#include "pigskin/Events/ApplicationEvent.h"
#include "pigskin/Log.h"

namespace PigSkin {
	Application::Application()
	{

	}
	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			PS_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			PS_TRACE(e.ToString());
		}
		while (true);
	}

}