#pragma once


#ifdef PS_PLATFORM_WINDOWS 

extern PigSkin::Application* PigSkin::CreateApplication();

int main(int argc, char** argv)
{
	printf("PigSkin Engine! \n");
	auto app = PigSkin::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif // PS_PLATFORM_WINDOWS 
