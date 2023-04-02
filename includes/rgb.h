#ifndef RGB_H
#define RGB_H
#include "Vec3.h"
/**
 * @class rgb
 * @brief A class to store the RGB values of a pixel
 *
 */
class rgb {
  private:
    /**
     * @brief All pixel values are stored as floats
     */
    float r, g, b;

  public:
    /**
     * @brief Get the Red object
     *
     * This set the values of every pixel to 0 -> Black
     */
    rgb() { r = g = b = 0.0f; }
    /**
     * @brief Construct a new RGB object
     *
     * @param red Red Pixel Value
     * @param green Green Pixel Value
     * @param blue Blue Pixel Value
     */
    rgb(float red, float green, float blue) : r(red), g(green), b(blue){};
    /**
     * @brief Clamp the values of the pixel to 0-1
     */
    static void clamp(V3 &c);
    float getR() { return r; }
    float getG() { return g; }
    float getB() { return b; }
    ~rgb(){};
};

#endif // RGB_H
