#include "main.hpp"

int main(int argc, char *argv[]) {

    // check arguments | проверяем аргументы

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number>" << std::endl;
        return 1;
    }

    //argv[1] = side | сторона

    int side;

    try {
        side = std::stoi(argv[1]);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: invalid argument(s)" << std::endl;
        return 1;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: out of range" << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown error" << std::endl;
        return 1;
    }

    if (side == 0) {
        std::cerr << "Error: side cannot be 0 or less" << std::endl;
        return 1;
    }


    QR qr_code(side, "qr-code.jpg");

    for (char x = 0; x < QR_MODULES; x += 2){
        for (char y = 0; y < QR_MODULES; y += 2){
            qr_code.draw_module(x, y);
        }
    }

    if (qr_code.save_image())
        std::cout << "File saved!" << std::endl;

    return 0;
}
