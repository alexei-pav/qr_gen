#include "main.hpp"

int main() {
    // create an image | создаём изображение
    sf::Image image;
    image.create(WIDTH, HEIGHT, sf::Color::White);

    // fill the image with a gradient | заполняем изображение градиентом
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            // сalculate grayscale color | вычисляем цвет оттенка серого
            sf::Uint8 color = static_cast<sf::Uint8>(x + y);
            image.setPixel(x, y, sf::Color(color, color, color));
        }
    }

    // save the image to a file | сохраняем изображение в файл
    if (!image.saveToFile("output.png")) {
        std::cerr << "Failed to save image." << std::endl;
        return 1;
    }

    std::cout << "Image created successfully." << std::endl;
    return 0;
}

