#ifndef DRAW_CODE_HPP
#define DRAW_CODE_HPP

#define QR_MODULES 21

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>

#include <string>
#include <iostream>

class QR {
    public:
        // class' constructors | конструкторы класса
        QR(unsigned int side);
        QR(unsigned int side, std::string filename);

        // class' destructor | деструктор класса
        ~QR();

        // draw a module (QR) | рисует модуль (QR)
        void draw_module(unsigned int x, unsigned int y);

        // save an image | сохраняет изображение
        bool save_image();
        bool save_image(std::string filename);

    private:
        unsigned int module_size;
        unsigned int qr_side;
        std::string qr_filename;
        sf::Image image;
        const unsigned char qr_modules = QR_MODULES;
};

#endif
