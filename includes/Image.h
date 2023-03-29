#ifndef IMAGE_H
#define IMAGE_H

class Image
{
public:
    struct Rgb
    {
        Rgb();
        Rgb(float c);
        Rgb(float _r, float _g, float _b);
        bool operator != (const Rgb& c) const;
        Rgb& operator *= (const Rgb& rgb);
        Rgb& operator += (const Rgb& rgb);
        friend float& operator += (float& f, const Rgb rgb);
        float r, g, b;
    };

    Image();
    Image(const unsigned int& _w, const unsigned int& _h, const Rgb& c = kBlack);
    const Rgb& operator [] (const unsigned int& i) const;
    Rgb& operator [] (const unsigned int& i);
    ~Image();

    unsigned int w, h;
    Rgb* pixels;

    static const Rgb kBlack, kWhite, kRed, kGreen, kBlue;
};

#endif


