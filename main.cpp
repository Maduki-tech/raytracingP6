#include "./includes/Image.h"


int main() {
    Image image(500,500);
    /* image.readPPM("./out.ppm"); */
    image.writePPM();
    return 0;
}
