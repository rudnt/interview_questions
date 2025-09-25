#include <iostream>
#include <exception>

import App;

int main() {
    try {
        interviews::App app;
        app.run();
        return 0;
    } catch (std::exception& exc) {
        std::cerr << exc.what() << std::endl;
        return 1;
    }
}
