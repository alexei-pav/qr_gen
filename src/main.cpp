#include "main.hpp"
#include <SFML/Graphics/Image.hpp>
#include <cmath>
#include <iostream>

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

    // create an image | создаём изображение
    sf::Image image;
    image.create(side, side, sf::Color::White);

    int module_size = static_cast<int>(side / 21);

    draw_module(module_size, 0, 0, &image);
    draw_module(module_size, 2, 2, &image);

    // save the image to a file | сохраняем изображение в файл
    if (!image.saveToFile("output.png")) {
        std::cerr << "Failed to save image." << std::endl;
        return 1;
    }

    std::cout << "Image created successfully." << std::endl;
    return 0;
}

void draw_module(int module_size, int start_x, int start_y, sf::Image* image)
{
    if (image == nullptr){
        std::cerr << "nullptr at: " << "\n  file: " <<__FILE__
            << "\n  line: " << __LINE__ << std::endl;
        return;
    } else {
        start_x *= module_size;
        start_y *= module_size;
        for (int x = 0; x < module_size; x++){
            for (int y = 0; y < module_size; y++){
                image->setPixel(start_x + x, start_y + y, sf::Color(0, 0, 0));
            }
        }
    }
}

