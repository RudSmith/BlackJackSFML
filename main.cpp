#include "MainMenu.h"

#ifdef _DEBUG
#pragma comment( linker, "/subsystem:console" )
int main()

#else

#include <Windows.h>

#pragma comment( linker, "/subsystem:windows" )

int  WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd
)
#endif
{
	MainMenu gamemenu;
	gamemenu.run();
}