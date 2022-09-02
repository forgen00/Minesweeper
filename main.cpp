#include <iostream>

#include "functions.h"
#include "headers/graphics.h"

IMAGE* img[12];
const int WIDTH = 400, HEIGHT = 400;

int main() {
    srand(time(0));
    initwindow(WIDTH, HEIGHT, "Minesweeper", 0, 0, true);
    read_images(img);

    int w = 32;
    int gridLogic[12][12];
    int gridView[12][12];
    int t = 0;

    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            gridView[i][j] = 10;
            if (rand() % 5 == 0) {
                gridLogic[i][j] = 9;
            }
            else {
                gridLogic[i][j] = 0;
            }
        }
    }

    std::pair<int, int> delta[8] = { {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0} };
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            int n = 0;
            for (int d = 0; d < 8; ++d) {
                int dx = i + delta[d].first;
                int dy = j + delta[d].second;
                if (gridLogic[dx][dy] == 9) {
                    ++n;
                }
            }
            if (gridLogic[i][j] != 9) {
                gridLogic[i][j] = n;
            }
        }
    }
    
    while (1) {
        setbkcolor(BLACK);
        clearviewport();
        ++t;

        int x = mousex() / w;
        int y = mousey() / w;

        if (mousebuttons() == 1) {
            gridView[x][y] = gridLogic[x][y];
        }
        else if (mousebuttons() == 2) {
            gridView[x][y] = 11;
        }

        for (int i = 1; i <= 10; ++i) {
            for (int j = 1; j <= 10; ++j) {
                if (gridView[x][y] == 9) {
                    gridView[i][j] = gridLogic[i][j];
                }
                putimage(i * w, j * w, img[gridView[i][j]], COPY_PUT);
            }
        }

        swapbuffers();
        delay(30);
        if (kbhit()) break;
    }
    free_images(img);
    closegraph();
    return 0;
}