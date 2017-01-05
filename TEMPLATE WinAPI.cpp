// BEWARE proc dont finish after closing app

#include <windows.h>

LRESULT CALLBACK MainProc(HWND hwnd, UINT message, WPARAM wpar, LPARAM lpar);			// TODO while programming

//*************************************************************************************

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInctance, LPSTR lpszCmdLine, int nMode)
{
	// Basic declaration of window
	HWND hWindow;																		
	MSG Message;
	WNDCLASS MainWindow;

	// Setting basic values to WNDCLASS MainWindow;
	MainWindow.hInstance = hInstance;
	MainWindow.lpszClassName = L"Main class";
	MainWindow.lpfnWndProc = DefWindowProc;			// Here you setting your MainProc
	MainWindow.lpszMenuName = NULL;
	MainWindow.style = 0;
	MainWindow.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	MainWindow.hCursor = LoadCursor(NULL, IDC_ARROW);
	MainWindow.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	MainWindow.cbClsExtra = 0;
	MainWindow.cbWndExtra = 0;

	if (!RegisterClass(&MainWindow)) return 0;		// Checking if everything goes right

	hWindow = CreateWindow(L"Main class", L"Title", WS_OVERLAPPEDWINDOW, 500, 100, 600, 600, NULL, NULL, hInstance, NULL);	// Creating MainWindow

	ShowWindow(hWindow, SW_SHOW);	// Seeing the result

	while (GetMessage(&Message, NULL, 0, 0))	// Showing INFINITE
	{
		DispatchMessage(&Message);
	}

	return 0;
}

//*************************************************************************************

LRESULT CALLBACK MainProc(HWND hwnd, UINT message, WPARAM wpar, LPARAM lpar)	// TODO
{
	return DefWindowProc(hwnd, NULL, 0, 0);
}