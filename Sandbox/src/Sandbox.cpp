#include "PigSkin.h"

class Sandbox : public PigSkin::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};


PigSkin::Application* PigSkin::CreateApplication() 
{
	return new Sandbox();
}

