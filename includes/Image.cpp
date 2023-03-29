#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>

class Image {
public:
  // Rgb structure, i.e. a pixel
  struct Rgb {
    Rgb() : r(0), g(0), b(0) {}
    Rgb(float c) : r(c), g(c), b(c) {}
    Rgb(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {}
    bool operator!=(const Rgb &c) const {
      return c.r != r || c.g != g || c.b != b;
    }
    Rgb &operator*=(const Rgb &rgb) {
      r *= rgb.r, g *= rgb.g, b *= rgb.b;
      return *this;
    }
    Rgb &operator+=(const Rgb &rgb) {
      r += rgb.r, g += rgb.g, b += rgb.b;
      return *this;
    }
    friend float &operator+=(float &f, const Rgb rgb) {
      f += (rgb.r + rgb.g + rgb.b) / 3.f;
      return f;
    }
    float r, g, b;
  };

  Image() : w(0), h(0), pixels(nullptr) { /* empty image */
  }
  Image(const unsigned int &_w, const unsigned int &_h, const Rgb &c = kBlack)
      : w(_w), h(_h), pixels(NULL) {
    pixels = new Rgb[w * h];
    for (int i = 0; i < w * h; ++i)
      pixels[i] = c;
  }
  const Rgb &operator[](const unsigned int &i) const { return pixels[i]; }
  Rgb &operator[](const unsigned int &i) { return pixels[i]; }
  ~Image() {
    if (pixels != NULL)
      delete[] pixels;
  }
  unsigned int w, h;                                    // Image resolution
  Rgb *pixels;                                          // 1D array of pixels
  static const Rgb kBlack, kWhite, kRed, kGreen, kBlue; // Preset colors
};
const Image::Rgb Image::kBlack = Image::Rgb(0);
const Image::Rgb Image::kWhite = Image::Rgb(1);
const Image::Rgb Image::kRed = Image::Rgb(1, 0, 0);
const Image::Rgb Image::kGreen = Image::Rgb(0, 1, 0);
const Image::Rgb Image::kBlue = Image::Rgb(0, 0, 1);

