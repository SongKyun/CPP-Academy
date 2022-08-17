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
#include <d3d11.h>  // DirectX11 ���
#include <d3dcompiler.h> // ���̴� �����Ϸ� ��� ����
#include <comdef.h>


//lib ��ŷ.
//#pragma comment(lib, "d3d11.lib")
//#pragma comment(lib, "d3dcompiler.lib")

#include <Core/Core.h>

//namespace STL
//{
//    /*__declspec(dllimport)*/ ENGINE_API void Show(const wchar_t* message);
//
//}

//����.
// ��������
 // Register the window class.
//std::wstring className = TEXT("Sample Window Class");
//std::wstring title = TEXT("STL Render Engine");
//HINSTANCE hInstance = nullptr;
//int width = 1600;
//int height = 900;
//HWND hwnd = nullptr;

//DX ����
//DX ��ġ.
ID3D11Device * device = nullptr;
ID3D11DeviceContext* context = nullptr;
IDXGISwapChain* swapChain = nullptr;
ID3D11RenderTargetView* renderTargetView = nullptr;
ID3D11InputLayout* inputlayout = nullptr;

//���� ���� ���� ����
unsigned int vertexByteWidth = 0u;
unsigned int vertexCount = 0u;
ID3D11Buffer* vertexBuffer = nullptr;
ID3D11VertexShader* VertexShader = nullptr;
ID3D11PixelShader* pixelShader = nullptr;

// DX ��ġ �ʱ�ȭ
void InitializeDevice(const STL::Window& window);

//��� �ʱ�ȭ
void InitializeScene();

void Draw();

//���� �޽��� ������ �Լ�.
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

//    // Show �Լ� �׽�Ʈ
//    STL::Show(TEXT("�׽�Ʈ"));
//
//    // Register the window class.
//    ::hInstance = hInstance; // ���� ���������� ���� :: 
//
//    WNDCLASS wc = { }; // ����ü
//    //memset(&wc, 0, sizeof(wc));
//
//    // Invoke. 
//    wc.lpfnWndProc = WindowProc; // �ݹ�(Callback) �����찡 �츮 �Լ��� ȣ�����ְ� �ִ�. / ����(Delegate)
//    wc.hInstance = hInstance;
//    wc.lpszClassName = className.c_str();
//
//    //â Ŭ���� �̸� ���.
//    RegisterClass(&wc);
//
//    // Create the window.
//    
//    //â ũ�� ���� 2���� ��� 
//    //RECT�� ���簢�� ����ü, (left, top, right, bottom).
//    RECT rect = { 0, 0, static_cast<long>(width), static_cast<long>(height) }; // int�� long���� �� ��ȯ
//    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
//
//    //������ ���簢�� ũ��� â ����/���� ũ�� ���ϱ�
//    int windowWidth = rect.right - rect.left;
//    int windowHeight = rect.bottom - rect.top;
//
//    //ȭ�� �߽ɿ��� â�� �׸��� ���� ������ǥ ���ϱ�
//    // GetSystemMetrics(SM_CXSCREEN) -> ����� ���� ũ�� ���ϴ� �Լ�
//    // GetSystemMetrics(SM_CYSCREEN) - > ����� ���� ũ�� ���ϴ� �Լ�
//    int xPosition = (GetSystemMetrics(SM_CXSCREEN) - windowWidth) / 2;
//    int yPosition = (GetSystemMetrics(SM_CYSCREEN) - windowHeight) / 2;
//
//    hwnd = CreateWindowEx( //���� ����Ǵ� �ڵ� ��
//        0,                              // Optional window styles.
//        className.c_str(),                     // Window class
//       title.c_str(),    // Window text ������ â �ؽ�Ʈ ��
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
//        return 0; // ���α׷� ����
//    }
//
//    ShowWindow(hwnd, SW_SHOW); // ������ â �����ֶ�� ��
//    UpdateWindow(hwnd); // â�� ����� �������ֶ��
    // -- â ���� ---- //

    // â Ŭ����
    using STL::Window;

    //â ��ü ����
    Window* window = new Window(
        hInstance,
        1600, 900,
        L"STL Render Engine",
        WindowProc
    );

    //â ������ ��� �� ����
    window->Intialize();
     
    //DX �ʱ�ȭ
    InitializeDevice(*window);

    //��� �ʱ�ȭ
    InitializeScene();

    // Run the message loop.

    MSG msg = { }; // �޽��� ����ü �ʱ�ȭ

    //WM_QUIT �޽����� �ƴϸ� ��� ���� ����
    while (msg.message != WM_QUIT) // �� �޽��� , peek �޽��� 2������ �ִ�.
    {
        //�����찡 �޽��� �����ϸ� ����.
        // if(GetMessage(&msg, NULL, 0, 0) > 0) - �޽��� ó���� ������
        if (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE))
        {
            //������(OS)�� ������ �޽��� �ؼ� �� ����(WindowProc �Լ� ȣ��).
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

    //â ��� ����.
    //UnregisterClass(className.c_str(), hInstance);

    delete window;

    return 0;
}

void InitializeDevice(const STL::Window& window)
{
    //��ġ ������ �� ������ �ɼ� ��.
    unsigned int createFlag = 0;

#if _DEBUG
    // Debug ����� ���,
    // ��ġ ���� �������� ������ �߻����� �� ����� ������ �� ���� �����ش޶�� �ɼ� �߰�.
    createFlag = D3D11_CREATE_DEVICE_DEBUG;
#endif

    //DX11 ���� ����.
    //���� ������ �տ� ������ ���� �õ��غ���, �������� ������ ���� �������� �Ѿ.
    D3D_FEATURE_LEVEL levels[] =
    {
        D3D_FEATURE_LEVEL_11_1, // �ٷ� ����
        D3D_FEATURE_LEVEL_11_0,
    };

    //����ü�� ������ ���� ����ü ����
    DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
    swapChainDesc.BufferCount = 1; // ����� ���� ����
    swapChainDesc.BufferDesc.Width = window.Width(); // ������(�̹���) ���� ũ��
    swapChainDesc.BufferDesc.Height = window.Height(); // ������(�̹���) ���� ũ��
    swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // �̹��� ä�κ� ����.
    swapChainDesc.Windowed = true; // â(window) ��� ���� ����
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // ������(�̹���)�� �뵵 (������)
    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD; // Front<->Back ���� ������ �� ȿ�� ������ ����
    swapChainDesc.SampleDesc.Count = 1; // ��Ƽ ���ø� ���� ���� ���� -> ����
    swapChainDesc.SampleDesc.Quality = 0; // ��Ƽ ���ø� ǰ�� ���� -> �⺻ ��( Count -1 )
    swapChainDesc.OutputWindow = window.Handle(); // DX�� �׸� â �ڵ�.

    D3D_FEATURE_LEVEL finalFeature;

    //��ġ �ʱ�ȭ
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

    //���� ���� Ȯ��
    S_OK;
    E_FAIL;
    if (FAILED(result))
    {
        MessageBox(nullptr, L"Failed to create device.", L"Error", MB_OK);
        exit(-1);
    }

    //����(�׸���, Draw) Ÿ�� (�����) -> �츮�� �̹����� �׸� ����(�޸�).
    ID3D11Texture2D* backbuffer = nullptr;
    // �׷���ī�尡 ������ �ִ� ����� ������ �����´�.
    result = swapChain->GetBuffer(0 , __uuidof(ID3D11Texture2D) , reinterpret_cast<void**>(&backbuffer));
    // swapChain �� ������� ���
    //���� Ȯ��
    if (FAILED(result))
    {
        MessageBox(nullptr, L"Failed to create device.", L"Error", MB_OK);
        exit(-1);
    }

    //���� Ÿ�� ��(RenderTaghetView) ����.
    renderTargetView = nullptr;
    result = device->CreateRenderTargetView(
        backbuffer,
        nullptr,
        &renderTargetView
    );

    //���� Ȯ��
    if (FAILED(result))
    {
        MessageBox(nullptr, L"Failed to create device.", L"Error", MB_OK);
        exit(-1);
    }

    //����� ����.
    //COM
    backbuffer->Release();

    //���� Ÿ�� �� ����.
    context->OMSetRenderTargets(1, &renderTargetView, nullptr);

    //ȭ��(VIewport) ����.
    D3D11_VIEWPORT viewport = {};
    viewport.TopLeftX = 0.0f;
    viewport.TopLeftY = 0.0f;
    viewport.Width = static_cast<float>(window.Width());
    viewport.Height = static_cast<float>(window.Height());
    viewport.MinDepth = 0.0f;
    viewport.MaxDepth = 1.0f;

    //����Ʈ ����
    context->RSSetViewports(1, &viewport);
}

void InitializeScene()
{
    // 1. ����(Vertex) ������ ���� �Լ� �ȿ��� ����ü�� ����
    struct Vertex
    {
        float x;
        float y;
        float z;
    };

    //�� ������
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

    //���� ���۸� �����ϴ� ����ü
    D3D11_BUFFER_DESC vertextBufferDesc = {};
    vertextBufferDesc.ByteWidth = sizeof(Vertex) * _countof(vertices); // sizeof 12����Ʈ
    vertextBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    //���� �迭(������)�� ���� ����ü
    D3D11_SUBRESOURCE_DATA vertexData = {};
    vertexData.pSysMem = vertices;

    //���� ����
    //ID3D11Buffer* vertexBuffer = nullptr;

    auto result = device->CreateBuffer(
        &vertextBufferDesc,
        &vertexData,
        &vertexBuffer
    );
    
    //���� Ȯ��
    if (FAILED(result))
    {
        MessageBox(nullptr, GetErrorMessage(result).c_str(), L"Error", MB_OK);
        exit(-1);
    }
    
    //���̴�(Shader-�׷��� ī�忡�� ����ϴ� ���α׷�) ���� (���� ���̴� / �ȼ� ���̴�).
    //���� ���̴� ����
    // 1. ������
    // 2. �����ϵ� ���� ���� �ε�
    // 3. ���̴� ����
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
    
    //���� Ȯ��
    if (FAILED(result))
    {
        MessageBox(nullptr, GetErrorMessage(result).c_str(), L"Error", MB_OK);
        exit(-1);
    }

    // ���� ���̴� ����
  //ID3D11VertexShader* VertexShader = nullptr;
    result = device->CreateVertexShader(
        vertexShaderBuffer->GetBufferPointer(),
        vertexShaderBuffer->GetBufferSize(),
        nullptr,
        &VertexShader

    );

    // �ȼ� ���̴�
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

    //���� Ȯ��
    if (FAILED(result))
    {
        MessageBox(nullptr, GetErrorMessage(result).c_str(), L"Error", MB_OK);
        exit(-1);
    }

    // �ȼ� ���̴� ����
    //ID3D11VertexShader* VertexShader = nullptr;
    result = device->CreatePixelShader(
        pixelShaderBuffer->GetBufferPointer(),
        pixelShaderBuffer->GetBufferSize(),
        nullptr,
        &pixelShader

    );

    //�Է� ���̾ƿ� ���� (�Է�=����, ������ �����).
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
    //��� �����.
    float color[] = { 0.2f, 0.4f, 0.6f, 1.0f };
    context->ClearRenderTargetView(renderTargetView, color);
    
    //�׸���
    //������/���̴� ����
    //���� �������.

    //���� �����ؼ� ���� ���� �� �����̵Ǵ� ����� ������.
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    
    static unsigned int stride = vertexByteWidth;
    static unsigned int offset = 0u;

    //���� ���� ����
    context->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
    context->IASetInputLayout(inputlayout);

    //���̴� ����
    context->VSSetShader(VertexShader, nullptr, 0);
    context->PSSetShader(pixelShader, nullptr, 0);

    //��ο� ��.
    context->Draw(vertexCount, 0);

    swapChain->Present(1u, 0u);

    // BeginRender  -> ��� �����
    // Render       -> ��� �׸���
    // EndRender    -> ����ü�� ��ȯ
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0; // â�� ������ �ߴܽ�Ű��

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // All painting occurs here, between BeginPaint and EndPaint.

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }

    return 0; // break ��ſ� �Լ� �����

    case WM_KEYDOWN:
        {
            //ESC Ű�� ������
            if (wParam == VK_ESCAPE)
            {
                //�޽��� ���� ����
                //��/�ƴϿ� ��ư�� �����ϴ� �޽��� ���ڸ� ����, �� �� �����ϸ� â ����
                if (MessageBox(nullptr, TEXT("Quit"), TEXT("Quit Engine"), MB_YESNO) == IDYES)
                {
                    //â �ڵ� ���� -> â ����
                    DestroyWindow(hwnd);
                }
            }
        }
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam); // ������ �⺻ ���ν���
}