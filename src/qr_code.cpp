#include "qr_code.hpp"

QR::QR(unsigned int side) : qr_side(side), qr_filename("output.jpg") {
    module_size = static_cast<int>(side / qr_modules);
    image.create(qr_side, qr_side, sf::Color::White);
}

QR::QR(unsigned int side, std::string name) : qr_side(side), qr_filename(name) {
    module_size = static_cast<int>(side / qr_modules);
    image.create(qr_side, qr_side, sf::Color::White);
}

QR::~QR(){
    // nothing yet | пока ничего
}

bool QR::save_image() {
    if (!image.saveToFile(qr_filename)) {
        return 0;
    }
    return 1;
}

bool QR::save_image(std::string filename) {
    if (!image.saveToFile(filename)) {
        return 0;
    }
    return 1;
}


void QR::draw_module(unsigned int start_x, unsigned int start_y) {

    if (start_x > qr_modules || start_y > qr_modules){
        std::cerr << "Error: out of the image, set to zero" << std::endl;
        start_x = start_y = 0;
    }

    start_x *= module_size;
    start_y *= module_size;

    start_x += (qr_side % qr_modules) / 2;
    start_y += (qr_side % qr_modules) / 2;

    std::cout << "start_x: " << start_x << " y: " << start_y << std::endl;

    for (int x = 0; x < module_size; x++){
        for (int y = 0; y < module_size; y++){
            image.setPixel(start_x + x, start_y + y, sf::Color(0, 0, 0));
        }
    }
}
