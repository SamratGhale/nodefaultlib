/*
  This is a minimal code and setup demonstrating the use of nodefaultlib
 */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

static int running;

LRESULT CALLBACK window_callback(HWND window, UINT message, WPARAM wParam, LPARAM lParam){
  LRESULT result = 0;

  switch(message){
  case WM_PAINT:
    PAINTSTRUCT paint;
    HDC hdc = BeginPaint(window, &paint);
    EndPaint(window, &paint);
    break;

  case WM_QUIT:
  case WM_DESTROY:{
    running = 0;
  }break;
      
  default:
    result = DefWindowProc(window, message, wParam, lParam);
    break;
  }
  return result;
}

void WinMainCRTStartup(){

  WNDCLASS win_class     = {0};
  win_class.style         = CS_HREDRAW | CS_VREDRAW;
  win_class.lpfnWndProc   = window_callback;

  win_class.hInstance     = GetModuleHandle(NULL); 
  win_class.lpszClassName =  "Opengl Practice";

  RegisterClass(&win_class);

  HWND window = CreateWindowEx(0, win_class.lpszClassName, "Playing Around", WS_OVERLAPPED | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1744, 1119, 0, 0, win_class.hInstance, 0);

  running = 1;

  while(running){

    MSG msg;
    while (PeekMessage(&msg, window, 0, 0, PM_REMOVE)) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }

    DwmFlush();
  }
}
