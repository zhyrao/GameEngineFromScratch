// Include the basic windows header file
#include <windows.h>
#include <windowsx.h>
#include <tchar.h>


// the WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd,
							UINT message,
							WPARAM wParam,
							WPARAM lParam);

// the entry point for any windows program
int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPTSTR lpCmdLine,
				   int nCmdShow)
{
	// the handle for the window, filled by a function
	HWND hWnd;

	// this struct hold information for the window class
	WNDCLASSEX wc;

	// clear out the window class for use
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	// fill in the struct with the needed information
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = _T("WindowClass1");

	// register the window class
	RegisterClassEx(&wc);

	// create the window and use the result as the handle
	hWnd = CreateWindowEx(0,
						  _T("WindowClass1"),
						  _T("Hello, Engine!"),
						  WS_OVERLAPPEDWINDOW,
						  300,
						  300,
						  500,
						  400,
						  NULL,
						  NULL,
						  hInstance,
						  NULL);

	// display the window on the screen
	ShowWindow(hWnd, nCmdShow);

	// enter main loop

	// this struct holds windows events messages
	MSG msg;

	// wait for the next message in the quene, store the result in 'msg'
	while(GetMessage(&msg, NULL, 0, 0))
	{
		// translate keystroke messages into the right format
		TranslateMessage(&msg);

		// send the message to the windowproc function
		DispatchMessage(&msg);
	}

	// return this part of the WM_QUIT message to windows
	return msg.wParam;
}


// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, WPARAM lParam)
{
	// sort through and find out what code to run for the message given
	switch(message)
	{
		// paint
		case WM_PAINT:
		{
			// 
			PAINTSTRUCT ps;

			// device
			HDC hdc = BeginPaint(hWnd, &ps);
			// rect for paint
			RECT rec = {20, 20, 60, 80};

			// get brush for paint
			HBRUSH brush = (HBRUSH)GetStockObject(BLACK_BRUSH);
			// paint
			FillRect(hdc, &rec, brush);

			// end paint
			EndPaint(hWnd, &ps);
		}break;
		// this message is read when the window is close
		case WM_DESTROY:
		{
			// close the application entirely
			PostQuitMessage(0);
			return 0;
		}break;
	}

	// handle any messages the switch statement didn't
	return DefWindowProc(hWnd, message, wParam, lParam);
}