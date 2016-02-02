#include <Application.h>

int main()
{
	Application* theApp = new Application();
	if (theApp->Initialise())
	{
		//gameloop
		while (theApp->Update())
		{
			theApp->Draw();
		}
		theApp->Shutdown();
	}

	//--------------------------
	delete theApp;
	return 0;
}