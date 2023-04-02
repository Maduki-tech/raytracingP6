#include "rgb.h"
#include "Vec3.h"


void rgb::clamp(V3 &c) {
    if (c.x_ > 1.0f) {
        c.x_ = 1.0f;
    }
    if (c.y_ > 1.0f) {
        c.y_ = 1.0f;
    }
    if (c.z_ > 1.0f) {
        c.z_ = 1.0f;
    }
}
