#ifndef UNICODE
#define UNICODE
#endif 

// #include <window.h>
#include <Device/Window.h>
#include <windows.h>
#include <tchar.h>
#include <string>
#include <time.h>
#include <cmath>


// DX Header.
#include <d3d11.h>  // DirectX11 헤더
#include <d3dcompiler.h> // 쉐이더 컴파일러 기능 제공
#include <comdef.h>


//lib 링킹.
//#pragma comment(lib, "d3d11.lib")
//#pragma comment(lib, "d3dcompiler.lib")

#include <Core/Core.h>

//namespace STL
//{
//    /*__declspec(dllimport)*/ ENGINE_API void Show(const wchar_t* message);
//
//}

//변수.
// 전역변수
 // Register the window class.
//std::wstring className = TEXT("Sample Window Class");
//std::wstring title = TEXT("STL Render Engine");
//HINSTANCE hInstance = nullptr;
//int width = 1600;
//int height = 900;
//HWND hwnd = nullptr;

//DX 변수
//DX 장치.
ID3D11Device * device = nullptr;
ID3D11DeviceContext* context = nullptr;
IDXGISwapChain* swapChain = nullptr;
ID3D11RenderTargetView* renderTargetView = nullptr;
ID3D11InputLayout* inputlayout = nullptr;

//정점 버퍼 관련 변수
unsigned int vertexByteWidth = 0u;
unsigned int vertexCount = 0u;
ID3D11Buffer* vertexBuffer = nullptr;
ID3D11VertexShader* VertexShader = nullptr;
ID3D11PixelShader* pixelShader = nullptr;

// DX 장치 초기화
void InitializeDevice(const STL::Window& window);

//장면 초기화
void InitializeScene();

void Draw();

//오류 메시지 얻어오는 함수.
std::wstring GetErrorMessage(HRESULT hr)
{
    _com_error error(hr);
    return error.ErrorMessage();
}



LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ int nShowCmd)
{

//    // Show 함수 테스트
//    STL::Show(TEXT("테스트"));
//
//    // Register the window class.
//    ::hInstance = hInstance; // 위에 전역변수와 연결 :: 
//
//    WNDCLASS wc = { }; // 구조체
//    //memset(&wc, 0, sizeof(wc));
//
//    // Invoke. 
//    wc.lpfnWndProc = WindowProc; // 콜백(Callback) 윈도우가 우리 함수를 호출해주고 있다. / 위임(Delegate)
//    wc.hInstance = hInstance;
//    wc.lpszClassName = className.c_str();
//
//    //창 클래스 이름 등록.
//    RegisterClass(&wc);
//
//    // Create the window.
//    
//    //창 크기 조정 2가지 방법 
//    //RECT는 직사각형 구조체, (left, top, right, bottom).
//    RECT rect = { 0, 0, static_cast<long>(width), static_cast<long>(height) }; // int를 long으로 형 변환
//    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
//
//    //조정된 직사각형 크기로 창 가로/세로 크기 구하기
//    int windowWidth = rect.right - rect.left;
//    int windowHeight = rect.bottom - rect.top;
//
//    //화면 중심에서 창을 그리기 위한 생성좌표 구하기
//    // GetSystemMetrics(SM_CXSCREEN) -> 모니터 가로 크기 구하는 함수
//    // GetSystemMetrics(SM_CYSCREEN) - > 모니터 세로 크기 구하는 함수
//    int xPosition = (GetSystemMetrics(SM_CXSCREEN) - windowWidth) / 2;
//    int yPosition = (GetSystemMetrics(SM_CYSCREEN) - windowHeight) / 2;
//
//    hwnd = CreateWindowEx( //힙에 저장되는 핸들 값
//        0,                              // Optional window styles.
//        className.c_str(),                     // Window class
//       title.c_str(),    // Window text 윈도우 창 텍스트 값
//        WS_OVERLAPPEDWINDOW,            // Window style
//
//        
//        // Size and position
//        xPosition, yPosition, windowWidth, windowHeight,
//
//        nullptr,       // Parent window
//        nullptr,       // Menu
//        hInstance,  // Instance handle
//        nullptr        // Additional application data
//    );
//
//    if (hwnd == nullptr)
//    {
//        return 0; // 프로그램 종료
//    }
//
//    ShowWindow(hwnd, SW_SHOW); // 윈도우 창 보여주라는 값
//    UpdateWindow(hwnd); // 창을 제대로 갱신해주라는
    // -- 창 생성 ---- //

    // 창 클래스
    using STL::Window;

    //창 객체 생성
    Window* window = new Window(
        hInstance,
        1600, 900,
        L"STL Render Engine",
        WindowProc
    );

    //창 윈도우 등록 및 생성
    window->Intialize();
     
    //DX 초기화
    InitializeDevice(*window);

    //장면 초기화
    InitializeScene();

    // Run the message loop.

    MSG msg = { }; // 메시지 구조체 초기화

    //WM_QUIT 메시지가 아니면 계속 루프 실행
    while (msg.message != WM_QUIT) // 겟 메시지 , peek 메시지 2가지가 있다.
    {
        //윈도우가 메시지 전달하면 실행.
        // if(GetMessage(&msg, NULL, 0, 0) > 0) - 메시지 처리만 가능한
        if (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE))
        {
            //윈도우(OS)가 전달한 메시지 해석 및 전달(WindowProc 함수 호출).
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            continue;
        }
        else
        {

            Draw();
            //GameLoop.
            //Rendering.

            //ProcessInput
            //Update
            //Render
            //PostRender

        }
    }

    //창 등록 해제.
    //UnregisterClass(className.c_str(), hInstance);

    delete window;

    return 0;
}

void InitializeDevice(const STL::Window& window)
{
    //장치 생성할 때 전달할 옵션 값.
    unsigned int createFlag = 0;

#if _DEBUG
    // Debug 모드인 경우,
    // 장치 생성 과정에서 오류가 발생했을 때 디버깅 정보를 더 많이 전달해달라는 옵션 추가.
    createFlag = D3D11_CREATE_DEVICE_DEBUG;
#endif

    //DX11 버전 지정.
    //상위 버전을 앞에 넣으면 먼저 시도해보고, 지원하지 않으면 다음 버전으로 넘어감.
    D3D_FEATURE_LEVEL levels[] =
    {
        D3D_FEATURE_LEVEL_11_1, // 다렉 버전
        D3D_FEATURE_LEVEL_11_0,
    };

    //스왑체인 생성을 위한 구조체 설정
    DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
    swapChainDesc.BufferCount = 1; // 백버퍼 개수 설정
    swapChainDesc.BufferDesc.Width = window.Width(); // 프레임(이미지) 가로 크기
    swapChainDesc.BufferDesc.Height = window.Height(); // 프레임(이미지) 세로 크기
    swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // 이미지 채널별 포맷.
    swapChainDesc.Windowed = true; // 창(window) 모드 여부 설정
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // 프레임(이미지)의 용도 (렌더링)
    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD; // Front<->Back 버퍼 변경할 때 효과 넣을지 설정
    swapChainDesc.SampleDesc.Count = 1; // 멀티 샘플링 할지 여부 설정 -> 안함
    swapChainDesc.SampleDesc.Quality = 0; // 멀티 샘플링 품질 설정 -> 기본 값( Count -1 )
    swapChainDesc.OutputWindow = window.Handle(); // DX가 그릴 창 핸들.

    D3D_FEATURE_LEVEL finalFeature;

    //장치 초기화
    //D3D10CreateDevice();
    auto result = D3D11CreateDeviceAndSwapChain(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        createFlag,
        levels,
        //ARRAYSIZE(levels),
        _countof(levels),
        D3D11_SDK_VERSION,
        &swapChainDesc,
        &swapChain,
        &device,
        &finalFeature,
        &context
        );

    //실패 여부 확인
    S_OK;
    E_FAIL;
    if (FAILED(result))
    {
        MessageBox(nullptr, L"Failed to create device.", L"Error", MB_OK);
        exit(-1);
    }

    //렌더(그린다, Draw) 타겟 (백버퍼) -> 우리가 이미지를 그릴 버퍼(메모리).
    ID3D11Texture2D* backbuffer = nullptr;
    // 그래픽카드가 가지고 있는 백버퍼 정보를 가져온다.
    result = swapChain->GetBuffer(0 , __uuidof(ID3D11Texture2D) , reinterpret_cast<void**>(&backbuffer));
    // swapChain 의 결과값도 출력
    //오류 확인
    if (FAILED(result))
    {
        MessageBox(nullptr, L"Failed to create device.", L"Error", MB_OK);
        exit(-1);
    }

    //렌더 타겟 뷰(RenderTaghetView) 생성.
    renderTargetView = nullptr;
    result = device->CreateRenderTargetView(
        backbuffer,
        nullptr,
        &renderTargetView
    );

    //오류 확인
    if (FAILED(result))
    {
        MessageBox(nullptr, L"Failed to create device.", L"Error", MB_OK);
        exit(-1);
    }

    //백버퍼 해제.
    //COM
    backbuffer->Release();

    //렌더 타겟 뷰 설정.
    context->OMSetRenderTargets(1, &renderTargetView, nullptr);

    //화면(VIewport) 설정.
    D3D11_VIEWPORT viewport = {};
    viewport.TopLeftX = 0.0f;
    viewport.TopLeftY = 0.0f;
    viewport.Width = static_cast<float>(window.Width());
    viewport.Height = static_cast<float>(window.Height());
    viewport.MinDepth = 0.0f;
    viewport.MaxDepth = 1.0f;

    //뷰포트 설정
    context->RSSetViewports(1, &viewport);
}

void InitializeScene()
{
    // 1. 정점(Vertex) 데이터 생성 함수 안에서 구조체를 생성
    struct Vertex
    {
        float x;
        float y;
        float z;
    };

    //점 데이터
    // NDC - (Viewport)
    Vertex vertices[] =
    {
        { 0.0f,  0.5f, 0.5f },
        { 0.5f, -0.5f, 0.5f },
        {-0.5f, -0.5f, 0.5f },
    };

    //
    vertexByteWidth = sizeof(Vertex);
    vertexCount = _countof(vertices);

    //정점 버퍼를 설명하는 구조체
    D3D11_BUFFER_DESC vertextBufferDesc = {};
    vertextBufferDesc.ByteWidth = sizeof(Vertex) * _countof(vertices); // sizeof 12바이트
    vertextBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    //정점 배열(데이터)을 담을 구조체
    D3D11_SUBRESOURCE_DATA vertexData = {};
    vertexData.pSysMem = vertices;

    //정점 버퍼
    //ID3D11Buffer* vertexBuffer = nullptr;

    auto result = device->CreateBuffer(
        &vertextBufferDesc,
        &vertexData,
        &vertexBuffer
    );
    
    //오류 확인
    if (FAILED(result))
    {
        MessageBox(nullptr, GetErrorMessage(result).c_str(), L"Error", MB_OK);
        exit(-1);
    }
    
    //셰이더(Shader-그래픽 카드에서 사용하는 프로그램) 생성 (정점 쉐이더 / 픽셀 쉐이더).
    //정점 셰이더 생성
    // 1. 컴파일
    // 2. 컴파일된 이진 파일 로드
    // 3. 셰이더 생성
    ID3DBlob* vertexShaderBuffer = nullptr;
    result = D3DCompileFromFile(
        L"VertexShader.hlsl",
        nullptr,
        nullptr,
        "main",
        "vs_5_0",
        0u,
        0u,
        &vertexShaderBuffer,
        nullptr
    );
    
    //오류 확인
    if (FAILED(result))
    {
        MessageBox(nullptr, GetErrorMessage(result).c_str(), L"Error", MB_OK);
        exit(-1);
    }

    // 정점 셰이더 생성
  //ID3D11VertexShader* VertexShader = nullptr;
    result = device->CreateVertexShader(
        vertexShaderBuffer->GetBufferPointer(),
        vertexShaderBuffer->GetBufferSize(),
        nullptr,
        &VertexShader

    );

    // 픽셀 셰이더
    ID3DBlob* pixelShaderBuffer = nullptr;
    result = D3DCompileFromFile(
        L"PixelShader.hlsl",
        nullptr,
        nullptr,
        "main",
        "ps_5_0",
        0u,
        0u,
        &pixelShaderBuffer,
        nullptr
    );

    //오류 확인
    if (FAILED(result))
    {
        MessageBox(nullptr, GetErrorMessage(result).c_str(), L"Error", MB_OK);
        exit(-1);
    }

    // 픽셀 셰이더 생성
    //ID3D11VertexShader* VertexShader = nullptr;
    result = device->CreatePixelShader(
        pixelShaderBuffer->GetBufferPointer(),
        pixelShaderBuffer->GetBufferSize(),
        nullptr,
        &pixelShader

    );

    //입력 레이아웃 생성 (입력=정점, 정점의 생김새).
    //ID3D11InputLayout* inputlayout = nullptr;
    
    /*LPCSTR SemanticName;
    UINT SemanticIndex;
    DXGI_FORMAT Format;
    UINT InputSlot;
    UINT AlignedByteOffset;
    D3D11_INPUT_CLASSIFICATION InputSlotClass;
    UINT InstanceDataStepRate;*/
    D3D11_INPUT_ELEMENT_DESC inputElementDesc[] =
    {
        {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0 , 0 , D3D11_INPUT_PER_VERTEX_DATA, 0  }
    };

    device->CreateInputLayout(inputElementDesc,
        _countof(inputElementDesc),
        vertexShaderBuffer->GetBufferPointer(),
        vertexShaderBuffer->GetBufferSize(),
        &inputlayout
    );
}   

void Draw()
{
    //배경 지우기.
    float color[] = { 0.2f, 0.4f, 0.6f, 1.0f };
    context->ClearRenderTargetView(renderTargetView, color);
    
    //그리기
    //데이터/셰이더 설정
    //순서 상관없음.

    //점을 연결해서 면을 만들 때 기준이되는 방식을 지정함.
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    
    static unsigned int stride = vertexByteWidth;
    static unsigned int offset = 0u;

    //정점 버퍼 설정
    context->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
    context->IASetInputLayout(inputlayout);

    //셰이더 설정
    context->VSSetShader(VertexShader, nullptr, 0);
    context->PSSetShader(pixelShader, nullptr, 0);

    //드로우 콜.
    context->Draw(vertexCount, 0);

    swapChain->Present(1u, 0u);

    // BeginRender  -> 배경 지우기
    // Render       -> 장면 그리기
    // EndRender    -> 스왑체인 교환
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0; // 창이 꺼지면 중단시키는

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // All painting occurs here, between BeginPaint and EndPaint.

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }

    return 0; // break 대신에 함수 종료용

    case WM_KEYDOWN:
        {
            //ESC 키가 눌리면
            if (wParam == VK_ESCAPE)
            {
                //메시지 상자 띄우기
                //예/아니요 버튼을 제공하는 메시지 상자를 띄우고, 예 를 선택하면 창 삭제
                if (MessageBox(nullptr, TEXT("Quit"), TEXT("Quit Engine"), MB_YESNO) == IDYES)
                {
                    //창 핸들 삭제 -> 창 삭제
                    DestroyWindow(hwnd);
                }
            }
        }
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam); // 윈도우 기본 프로시저
}