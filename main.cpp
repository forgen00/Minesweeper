#include <iostream>

#include "headers/graphics.h"

IMAGE* img[12];
int number = 0;
const int WIDTH = 800, HEIGHT = 600;

void read_images();
void free_images();

void read_images() {
    for (int i = 0; i <= 12; ++i) {
        std::string fileName = "img/" + std::to_string(i) + ".bmp";
        img[i - 1] = loadBMP(fileName.c_str());
    }
}

void free_images() {
    for (int i = 0; i < 12; ++i) {
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
    int t = 0; // номер кадра (время)

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            gridView[i][j] = 10;
        }
    }

    while (1)
    {
        setbkcolor(BLACK); // цвет фона
        clearviewport(); // закраска текущей страницы цветом фона
        ++t;
        // рисование изображения
        
        for (int i = 1; i <= 10; ++i) {
            for (int j = 1; j <= 10; ++j) {
                putimage(i * w, j * w, img[number], COPY_PUT);
            }
        }



        swapbuffers();
        delay(30); // задержка на 1/30 секунды
        if (kbhit()) break; // если нажата клавиша - завершить работу
    }
    freeimage(img);
    closegraph();
    return 0;
}