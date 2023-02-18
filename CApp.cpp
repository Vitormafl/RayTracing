#include "CApp.h"

//Construtor padrão
CApp::CApp()
{
    isRunning = true;
    pWindow = NULL;
    pRenderer = NULL;
}

//Função de inicialização do SDL

bool CApp::onInit()
{
    //Inicializa todos os componentes do SDL e testa se todos foram incializados corretamente
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }    

    //Com os componentes devidamente habilitados podemos criar a Janela
    pWindow = SDL_CreateWindow("Vitor's RayTracing Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);

    //Teste para verificar se a criação da janela ocorreu corretamente, caso seja o caso, criamos o renderer ligado a janela
    if (pWindow != NULL)
    {
        pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
    }
    else
    {
        return false;
    }

    return true;
}

int CApp::onExecute()
{
    SDL_Event event;

    if (onInit() == false)
    {
        return -1;
    }

    while (isRunning)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            onEvent(&event);
        }

        onLoop();
        onRender();
    }
}

void CApp::onEvent(SDL_Event *event)
{
    if (event->type == SDL_QUIT)
    {
        isRunning = false;
    }
}

void CApp::onLoop(){}

void CApp::onRender()
{
    //configurar a cor de fundo para branco
    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(pRenderer);

    //exibir o resultado
    SDL_RenderPresent(pRenderer);
}

void CApp::onExit()
{
    //Destroi todos os objetos criados, renderer e window 
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    pWindow = NULL;
    SDL_Quit;
}















































