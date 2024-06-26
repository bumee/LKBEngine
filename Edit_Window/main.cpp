// Edit_Window.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Edit_Window.h"
#include "..\\LKBEngine_SOURCE\LKBApplication.h"
//#pragma comment (lib, "..\\Debug\\LKBEngine_Window.lib") //pragme 코드로 연결

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, //프로그램의 인스턴스 핸들을 의미한다.
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    //깃허브 테스트

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EDITWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EDITWINDOW));

    MSG msg;

    // GetMessage(&msg, nullptr, 0, 0)
    // 프로세스에서 발생한 메세지를 메세지 큐에서 가져오는 함수
    // 메세지큐에 아무것도 없다면? 아무 메세지도 가져오지 않게 된다.
    // PeekMessage : 메세지 큐에 메세지 유무에 상관없이 함수가 리턴된다.
    // 리턴 값이 true인 경우 메세지가 있고, false인 경우는 메세지가 없다라고 가르쳐준다.

    while (true) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT)
                break;
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else {
            // 메세지가 없을 경우 여기서 처리한다.
            // 게임 로직이 들어가면 된다.
        }
    }

    // 기본 메시지 루프입니다:
    //while (GetMessage(&msg, nullptr, 0, 0))
    //{
    //    if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
    //    {
    //        // 메세지가 들어오는 경우 윈도우 로직을 여기서 실행한다.
    //        TranslateMessage(&msg);
    //        DispatchMessage(&msg);
    //    }
    //    else {
    //        // 메세지가 없을 경우 여기서 처리한다.
    //        // 게임 로직이 들어가면 된다.
    //    }
    //}

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EDITWINDOW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EDITWINDOW);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
            HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush); //새로운 핑크색 선택

            Rectangle(hdc, 100, 100, 200, 200); //핑크색 사각형 그리고

            SelectObject(hdc, oldBrush); //다시 원래 색인 하얀색을 선택

            HPEN pinkpen = CreatePen(PS_SOLID, 2, RGB(255, 0, 255));

            HPEN oldPen = (HPEN)SelectObject(hdc, pinkpen); //기존의 검은 펜 반환

            Ellipse(hdc, 300, 300, 400, 400); //다시 하얀색 원 그리고

            SelectObject(hdc, oldPen); //기존 검은펜 다시 잡아주고
            DeleteObject(pinkpen); //새로 만든 핑크펜은 메모리에서 지워주기

            DeleteObject(brush); //다 사용한 파란색 브러쉬는 메모리에서 지워주자 !

            //DC란 화면에 출력에 필요한 모든 정보를 가지는 데이터 구조체이며
            // GDI모듈에 의해 관리된다.
            // 어떤 폰트를 사용할건가? 어떤 선의 굵기를 정해줄건가? 어떤 색상으로 그려줄 것인가?
            // 화면 출력에 필요한 모든 경우는 WINAPI에선 DC를 통해서 작업을 진행할 수 있다.
            // 
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
