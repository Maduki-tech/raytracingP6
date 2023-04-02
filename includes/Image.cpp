#include "Image.h"
#include "Sphere.h"
#include "Vec3.h"
#include "rgb.h"
#include <fstream>
#include <iostream>

Image::Image() {}

inline double Image::dot(const V3 &a, const V3 &b) {
    return (a.x_ * b.x_ + a.y_ * b.y_ + a.z_ * b.z_);
}

void Image::writePPM() {
    std::ofstream outImage;
    outImage.open("outImage.ppm", std::ios::binary);

    const V3 white(1.0f, 1.0f, 1.0f);
    const V3 black(0.0f, 0.0f, 0.0f);
    const V3 red(1.0f, 0.0f, 0.0f);

    const Sphere sphere(V3(dimX * 0.5, dimY * 0.5, 50), 50.5f);
    const Sphere light(V3(0, 0, 50), 50.5f);

    if (outImage.fail()) {
        std::cout << "Unable to create image.ppm" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Image header - Need this to start the image propertiesj
    outImage << "P6"
             << std::endl; // Declare that you want to use ASCII colour values

    outImage << dimX << " " << dimY << std::endl; // Declare w & h
    outImage << 255 << std::endl;                 // Declare max colour ID
    double t;
    V3 pixelColor(red);
    std::cout << pixelColor.x_ << std::endl;
    std::cout << pixelColor.y_ << std::endl;
    std::cout << pixelColor.y_ << std::endl;
    for (int y = 0; y < dimX; ++y) {
        for (int x = 0; x < dimY; ++x) {
            pixelColor = white;

            const Ray ray(V3(x, y, 0), V3(0, 0, 1));
            if (sphere.intersects(ray, t)) {
                const V3 pi = ray.origin_ + ray.direction_ * t;
                const V3 L = light.center_ - pi;
                const V3 N = sphere.getNormal(pi);
                const double dt = dot(L.normalize(), N.normalize());

                pixelColor = (red + white * dt) * 0.5;
                rgb::clamp(pixelColor);
                std::cout << pixelColor.x_ << std::endl;
                std::cout << pixelColor.y_ << std::endl;
                std::cout << pixelColor.z_ << std::endl;
            }
            outImage << (int)pixelColor.x_ << ' ' << (int)pixelColor.y_ << ' '
                     << (int)pixelColor.z_ << '\n';
        }
    }

    outImage.close();
    std::cout << "Image has been generated. \n";
}

void Image::readPPM(const char *filename) {
    std::string header;
    std::ifstream image;
    unsigned int width, height;

    image.open(filename, std::ios::binary);
    rgb colors;

    if (!image) {
        std::cerr << "file could not be open" << std::endl;
        exit(EXIT_FAILURE);
    }

    // read the header
    image >> header >> width >> height;

    // check the header
    // PPM "header" is valid
    if (header.compare("P6") != 0) {
        std::cout << "Invalid image format (must be 'P6')";
        exit(EXIT_FAILURE);
    }

    std::cout << width << ";" << height << std::endl;

    std::ofstream readImage;
    readImage.open("readImage.ppm", std::ios::binary);

    if (readImage.fail()) {
        std::cout << "Unable to create image.ppm" << std::endl;
        exit(EXIT_FAILURE);
        ;
    }

    // Image header - Need this to start the image properties
    readImage << "P6"
              << std::endl; // Declare that you want to use ASCII colour values
    readImage << width << " " << height << std::endl; // Declare w & h
    readImage << 255 << std::endl;                    // Declare max colour ID

    for (int i = 0; i < width * height; i++) { // iterate over all pixels
        unsigned char r_, g_, b_;
        image >> r_;
        image >> g_;
        image >> b_;

        readImage.put(r_);
        readImage.put(g_);
        readImage.put(b_);
    }
    image.close();
    readImage.close();

    std::cout << "Image has been read. \n";
}

Image::~Image() {}
