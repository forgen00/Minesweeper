#include <iostream>

#include "functions.h"
#include "headers/graphics.h"

void read_images(IMAGE* img[12]) {
    for (int i = 0; i < 12; ++i) {
        std::string fileName = "img/" + std::to_string(i) + ".bmp";
        img[i] = loadBMP(fileName.c_str());
    }
}

void free_images(IMAGE* img[12]) {
    for (int i = 0; i < 12; ++i) {
        freeimage(img[i]);
    }
}