#include "Image.h"
#include <fstream>
#include <iostream>

Image::Image() {}

void Image::writePPM(int x, int y) {
    std::ofstream file("test.ppm", std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file out.ppm" << std::endl;
        exit(1);
    }
    file << "P6" << std::endl;
    file << x << " " << y << std::endl;
    file << "255" << std::endl;
    std::cout << dimX;
    for (int width = 0; width < dimX; width++) {
        for (int height = 0; height < dimY; height++) {
            file << raster[width][height].getR() << " "
                 << raster[width][height].getG() << " "
                 << raster[width][height].getB() << " ";
        }
    }
    file.close();
}

void Image::readPPM(const char *filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << filename << std::endl;
        exit(1);
    }
    std::string magic;
    file >> magic;
    if (magic != "P6") {
        std::cout << "Error: File is not a PPM file" << std::endl;
        exit(1);
    }
    int width, height, maxValue;
    file >> width >> height >> maxValue;
    std::cout << "WidthxHeight: " << width << "x" << height << std::endl;

    // set Values for dimX and dimY and create a raster
    dimX = width;
    dimY = height;
    // TODO: Loop is wrong Values does look not right
    raster = new rgb *[dimX];
    for (int width = 0; width < dimX; width++) {
        raster[width] = new rgb[dimY];
        for (int height = 0; height < dimY; height++) {
            file.read((char *)&raster[width][height], 3);
            std::cout << raster[width][height].getR() / 255.f << " "
                      << raster[width][height].getG() / 255.f << " "
                      << raster[width][height].getB() / 255.f << " ";
        }
    }

    file.close();
}

Image::~Image() {}
