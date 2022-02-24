#pragma once

#ifdef CB_PLATFORM_WINDOWS

extern Cober::Application* Cober::CreateApplication();

int main(int argc, char** argv) 
{
	Cober::Log::Init();
	CB_CORE_WARN("Initialized Log!");
	int a = 5;
	CB_INFO("Cool! {0}", a);

	auto app = Cober::CreateApplication();
	app->Run();
	delete app;
}

#endif