#include "rgbcolor.h"
#include <iostream>
RGBColor::RGBColor() {
    r = 0;
    g = 0;
    b = 0;
}

RGBColor::RGBColor(unsigned char r, unsigned char g, unsigned char b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void RGBColor::SetColor(unsigned char r, unsigned char g, unsigned char b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void RGBColor::GetColor(unsigned char& r, unsigned char& g, unsigned char& b) const {
    r = this->r;
    g = this->g;
    b = this->b;
}

void RGBColor::Display() const {
    std::cout << "R: " << (int)r << " G: " << (int)g << " B: " << (int)b << std::endl;
}

void RGBColor::MixColor(const RGBColor& color1, const RGBColor& color2) {
    r = (color1.r + color2.r) / 2;
    g = (color1.g + color2.g) / 2;
    b = (color1.b + color2.b) / 2;
}