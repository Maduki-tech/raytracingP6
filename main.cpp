#include <algorithm>
#include <iostream>
#include <fstream>
#include <ostream>

void writePPM(){
    std::ofstream out;
    std::ifstream image;

    out.open("outImage.ppm", std::ios::binary);
    int width = 1024;
    int height = 768;
    image.open("image.ppm", std::ios::binary);
    // adding meta data to new image
    out << "P6" << std::endl;
    out << width << " " << height << std::endl;
    out << "255" << std::endl;

    // adding image data to new image
    unsigned char *data = new unsigned char[width * height * 3];
    unsigned char *data2 = new unsigned char[width * height * 3];
    for (int i = 0; i < height * 3 ; i++) {
        for (int j = 0; j < width * 3; j += 3) {
            // r
            data2[j] = 255;
            // g
            data2[j + 1] = 0;
            // b
            data2[j + 2] = 0;
        }
        std::cout << data2[i] << std::endl;
    }

    std::cout << "Reading image data" << std::endl;

    image.read((char*)data, 1024 * 768 * 3);
    std::cout << "Writing image data" << std::endl;
    out.write((char*)data2, 1024 * 768 * 3);


    // closing files
    out.close();
    image.close();

    std::cout << "Done" << std::endl;


}

void readPPM(const char *filename) {
    std::ifstream image;
    image.open(filename, std::ios::binary);
    if (!image.is_open()) {
        std::cout << "Error: Could not open file " << filename << std::endl;
        return;
    }

    // check if header is p6
    std::string header;
    image >> header;
    if (header != "P6") {
        std::cout << "Error: Invalid PPM header" << std::endl;
        return;
    }

    // read width, height and max value
    int width, height, max;
    image >> width >> height >> max;

    // read image data
    unsigned char *data = new unsigned char[width * height * 3];
    image.read((char*)data, width * height * 3);
    std::cout << "Read " << width << "x" << height << " image with " << max << " color channels" << std::endl;
    // close file
    image.close();

}


int main ()
{
    readPPM("image.ppm");
    writePPM();
    return 0;
}
