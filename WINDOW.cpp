#include "WINDOW.h"
#define LOWORD
///////////////////////
std::string TextDATAString;
//////////////////////////
char textSaved[20];

LPSTR TextData;
HWND hWndEditA;

//////////////////////////
///IMAGES PREFAPS///

///=======================/////
LRESULT CALLBACK WindowProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam){
 switch(uMsg){
case WM_CREATE:
    break;
case WM_CLOSE:
        DestroyWindow(hWnd);
    break;
case WM_DESTROY:
        PostQuitMessage(0);
    break;
case WM_COMMAND:{
    if(LOWORD(wParam) ==1){
        int gwstat=0;
        gwstat= GetWindowText(hWndEditA,&textSaved[0],20);
        TextData = textSaved;
        SaveDataBase(textSaved);
    }
}
    return 0;
    }
    return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

WINDOW::WINDOW(): m_hinstance(GetModuleHandle(nullptr)){
////////////////////////////////////////////
    const char* CLASS_NAME = "Ventanita";
///=====Window PRELOAD======///
    WNDCLASS wndclass = {};
    wndclass.lpszClassName = CLASS_NAME;
    wndclass.hInstance = m_hinstance;
    wndclass.hIcon = LoadIcon(NULL,IDI_WINLOGO);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpfnWndProc = WindowProc;
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW);

    RegisterClass(&wndclass);
    DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;
//WIDTH AND HEIGHT OF THE Window//
    int width = 150;
    int height = 150;
///==Window MEASUREMENTS===========////
    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
///====================================///
    AdjustWindowRect(&rect, style, false);
///Window PROPERTIES
    m_hWnd = CreateWindowEx(0,CLASS_NAME,"Save Text Files",style,rect.left,rect.top,
                            rect.right - rect.left,rect.bottom - rect.top,
                            NULL,NULL,m_hinstance,NULL);
    ShowWindow(m_hWnd,SW_SHOW);
///CREATE ITEMS WindowS
HWND hWndGIFAI = CreateWindow(
        ("Static"),
        ("Save Idea"),
        WS_CHILD | WS_VISIBLE | SS_LEFT,
        45,
        1,
        150,
        20,
        m_hWnd,
        NULL,
        NULL,
        NULL);
hWndEditA = CreateWindow(
        ("Edit"),
        (""),
        WS_VISIBLE| WS_CHILD | WS_BORDER,
        5,
        20,
        140,
        100,
        m_hWnd,
        0,
        m_hinstance,
        0);
HWND hWndButton = CreateWindow(
        ("Button"),
        ("Save"),
        WS_VISIBLE| WS_CHILD | WS_BORDER,
        50,
        125,
        50,
        20,
        m_hWnd,
        (HMENU) 1,
        NULL,
        NULL);

}

////DestroyWindow//////
WINDOW::~WINDOW(){
////////////////////////////////////////////
  const char* CLASS_NAME = "Ventanita";
  UnregisterClass(CLASS_NAME, m_hinstance);
////////////////////////////////////////////
}
///////////////
bool WINDOW::ProcessMessages(){
    MSG msg ={};
//////////////////////////////////////////////////
   while(PeekMessage(&msg,nullptr,0u,0u,PM_REMOVE)){
        if(msg.message == WM_QUIT){
            return false;
        }
///////////////////////////////
TranslateMessage(&msg);
DispatchMessage(&msg);
///////////////////////////
    }
    return true;
}
