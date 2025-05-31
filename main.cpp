#include <iostream>

#include <boost/program_options.hpp>

#include "application.h"

int main(int argc, char* argv[]) {

    boost::program_options::options_description desc("Game options");

    desc.add_options()
            ("help,h", "Вывести справку")
            ("input,i", boost::program_options::value<std::string>(), "Входной файл")
            ("output,o", boost::program_options::value<std::string>(), "Выходной файл")
            ("verbosity,v", boost::program_options::value<int>()->default_value(1), "Уровень подробности, от 0 до 2");

    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
    boost::program_options::notify(vm);

    // Обработка параметров
    if (vm.count("help")) {
        std::cout << "input wh and w" << std::endl;
        return 0;
    }

    Application game;
    return game.run();
}
