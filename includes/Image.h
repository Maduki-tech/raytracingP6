#ifndef Image_H
#define Image_H
#include "rgb.h"
/**
 * @class Image
 * @brief A class to read and write PPM files
 *
 */
class Image {
  private:
    rgb **raster;
    int dimX, dimY;

  public:
    /**
     * @brief Construct a new Image object
     */
    Image();
    /**
     * @brief Construct a new Image object
     *
     * @param x width of the image
     * @param y height of the image
     */
    Image(int x, int y) {
        // set Values for dimX and dimY and create a raster
        dimX = x;
        dimY = y;
        /* raster = new rgb *[dimX]; */
        /* for (int i = 0; i < dimX; i++) { */
        /*     raster[i] = new rgb[dimY]; */
        /* } */
    };
    /**
     * @brief Construct a new Image object with background
     *
     * @param x width of the image
     * @param y height of the image
     * @param bg background color
     */
    Image(int x, int y, rgb bg);

    /**
     * @brief read a ppm file
     *
     * @param filename The name of the file to read
     */
    void readPPM(const char *filename);
    /**
     * @brief create a new image file 
     *
     * @param x width of the image
     * @param y height of the image
     */
    void writePPM(int x, int y);
    ~Image();
};
#endif // Image_H
