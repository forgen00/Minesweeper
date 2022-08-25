#include <iostream>

#include "headers/graphics.h"

IMAGE* img[12];
const int WIDTH = 400, HEIGHT = 400;

void read_images();
void free_images();

void read_images() {
    for (int i = 0; i <= 12; ++i) {
        std::string fileName = "img/" + std::to_string(i) + ".bmp";
        img[i] = loadBMP(fileName.c_str());
    }
}

void free_images() {
    for (int i = 0; i <= 12; ++i) {
        freeimage(img[i]);
    }
}

int main() {
    srand(time(0));
    initwindow(WIDTH, HEIGHT, "Minesweeper", 0, 0, true);
    read_images();

    int w = 32;
    int gridLogic[12][12];
    int gridView[12][12];
    int t = 0;

    

    while (1) {
        setbkcolor(BLACK); 
        clearviewport();
        ++t;
        

        for (int i = 1; i <= 10; ++i) {
            for (int j = 1; j <= 10; ++j) {
                putimage(i * w, j * w, img[gridView[i][j]], COPY_PUT);
            }
        }

        swapbuffers();
        delay(30);
        if (kbhit()) break; 
    }
    closegraph();
    return 0;
}
