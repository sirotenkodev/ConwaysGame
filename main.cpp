#include <iostream>

#include <cxxopts.hpp>

#include "application.h"

//-----------------------------------------------------------------------------
int main(int argc, char* argv[]) {

    cxxopts::Options options(argv[0], "Conways game");
    options.add_options()
            ("w,width", "Window width", cxxopts::value<int>()->default_value("800"))
            ("h,height", "Window height", cxxopts::value<int>()->default_value("800"))
            ("g,grid", "Grid size", cxxopts::value<int>()->default_value("40"));

    const auto result = options.parse(argc, argv);
    Application game(result["height"].as<int>(), result["width"].as<int>(), result["grid"].as<int>());
    return game.run();
}
