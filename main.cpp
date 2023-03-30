#include "./includes/Image.h"

int main() {
    Image image;
    image.readPPM("./out.ppm");
    image.writePPM(100, 100);
    return 0;
}
