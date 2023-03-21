//Andrew Card

#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <iostream>

using namespace std;

int main(){

    //Set Pixel on screen
    HDC hdc = GetDC(NULL);
    SetPixel(hdc, 100, 100, RGB(255, 0, 0));

    return 0;
}