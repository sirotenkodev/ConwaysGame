#include <chrono>
#include <iostream>
#include <thread>

#include "application.h"

//-----------------------------------------------------------------------------
Application::Application(int wH, int wW, int gS)
    : m_isRunning{true}
    , m_onPause{true}
{
    unsigned int init_flags{
        SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER
    };
    if (SDL_Init(init_flags) != 0) {
        m_isRunning = false;
        std::cerr << "Ошибка инициализации SDL: " << SDL_GetError() << std::endl;
    } else {
        init(wH, wW, gS);
    }
}

//-----------------------------------------------------------------------------
Application::~Application()
{
    SDL_Quit();
}

//-----------------------------------------------------------------------------
void Application::init(int wH, int wW, int gS)
{
    try {
        m_window = std::make_unique<GameWindow>("Conways game", wH, wW);
        m_grid = std::make_unique<Grid>(wH, wW, gS, *m_window);
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
    using namespace std::chrono_literals;


    while (m_isRunning) {

        Uint32 start, elapsed, estimated = 1000 / 50;
        SDL_Event event;
        start = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                m_isRunning = false;
                return 0;
            }

            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                m_grid->setCellOnGrid(mouseX, mouseY);
                break;
            }

            if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_SPACE) {
                togglePause();
                break;
            }
        }
        if (!m_onPause) {
            m_grid->updateGeneration();
            m_grid->updateGrid();
        }
        m_grid->drawGrid();

        elapsed = SDL_GetTicks() - start;
        if(elapsed < estimated) {
            SDL_Delay(estimated - elapsed);
        }
    }


    return 0;
}

//-----------------------------------------------------------------------------
void Application::stop()
{
    m_isRunning = false;
}

//-----------------------------------------------------------------------------
void Application::togglePause()
{
    m_onPause = !m_onPause;
}
