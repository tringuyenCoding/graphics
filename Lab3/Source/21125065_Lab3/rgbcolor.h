#pragma once
class RGBColor {
public:
    unsigned char r;
    unsigned char g;
    unsigned char b;

    RGBColor();
    RGBColor(unsigned char r, unsigned char g, unsigned char b);
    void SetColor(unsigned char r, unsigned char g, unsigned char b);
    void GetColor(unsigned char& r, unsigned char& g, unsigned char& b) const;
    void Display() const;
    void MixColor(const RGBColor& color1, const RGBColor& color2);

};

