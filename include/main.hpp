#ifndef MAIN_HPP
#define MAIN_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <iostream>
#include <string>

// set image size | устанавливаем размер изображения
const int WIDTH   = 1000;
const int HEIGHT  = 1000;

void draw_module(int module_size, int start_x, int start_y, sf::Image* image);

#endif
