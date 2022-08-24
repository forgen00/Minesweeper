#include <iostream>

#include "headers/graphics.h"

IMAGE* img[12];
int number = 0;

void read_images();
void free_images();

void read_images() {
    for (int i = 0; i <= 12; ++i) {
        std::string fileName = "img/" + std::to_string(i) + ".bmp";
        img[i - 1] = loadBMP(fileName.c_str());
    }
}

void free_images() {
    for (int i = 0; i < 6; ++i) {
        freeimage(img[i]);
    }
}

int main() {
    initwindow(800, 600, "Minesweeper", 0, 0); // ����� 2-�������
    // ������ �������� 0, ������� �������� 1
    int t = 0; // ����� ����� (�����)
    while (1)
    {
        setbkcolor(BLACK); // ���� ����
        clearviewport(); // �������� ������� �������� ������ ����
        ++t;
        // ��������� �����������
        



       
        delay(30); // �������� �� 1/30 �������
        if (kbhit()) break; // ���� ������ ������� - ��������� ������
    }
    closegraph();
}