#include <iostream>

#include "application.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int GRID_SIZE = 10;
const int CELL_SIZE = WINDOW_WIDTH / GRID_SIZE;

//-----------------------------------------------------------------------------
Application::Application()
    : m_isRunning{true}
{
    unsigned int init_flags{
        SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER
    };
    if (SDL_Init(init_flags) != 0) {
        m_isRunning = false;
        std::cerr << "Ошибка инициализации SDL: " << SDL_GetError() << std::endl;
    } else {
        init();
    }
}

//-----------------------------------------------------------------------------
Application::~Application()
{
    SDL_Quit();
}

//-----------------------------------------------------------------------------
void Application::init()
{
    try {
        m_window = std::make_unique<GameWindow>("Conways game");
        m_renderer = std::make_unique<GameRender>(*m_window);
    }  catch (std::runtime_error) {
        m_isRunning = false;
    }

}

//-----------------------------------------------------------------------------
int Application::run()
{
    if (m_isRunning == false) {
      return 1;
    }



    while (m_isRunning) {
        SDL_Event event;
        SDL_WaitEvent(&event);

        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            m_isRunning = false;
        }

        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE) {
            m_isRunning = false;
        }

        // Очистка экрана
        SDL_SetRenderDrawColor(m_renderer->getRender(), 255, 255, 255, 255); // Белый цвет
        SDL_RenderClear(m_renderer->getRender());

        // Отрисовка сетки
        SDL_SetRenderDrawColor(m_renderer->getRender(), 0, 0, 0, 255); // Черный цвет

        // Вертикальные линии
        for (int i = 0; i <= GRID_SIZE; ++i) {
            SDL_RenderDrawLine(m_renderer->getRender(), i * CELL_SIZE, 0, i * CELL_SIZE, WINDOW_HEIGHT);
        }

        // Горизонтальные линии
        for (int i = 0; i <= GRID_SIZE; ++i) {
            SDL_RenderDrawLine(m_renderer->getRender(), 0, i * CELL_SIZE, WINDOW_WIDTH, i * CELL_SIZE);
        }

        // Отображение рендерера
        SDL_RenderPresent(m_renderer->getRender());
    }


    return 0;
}

//-----------------------------------------------------------------------------
void Application::stop()
{
    m_isRunning = false;
}
