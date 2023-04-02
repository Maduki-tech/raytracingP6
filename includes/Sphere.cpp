#include "Ray.h"
#include "Sphere.h"
#include "Vec3.h"
#include <iostream>
#include <math.h>

inline double dot(const V3 &a, const V3 &b) {
    return (a.x_ * b.x_ + a.y_ * b.y_ + a.z_ * b.z_);
}

bool Sphere::intersects(const Ray &ray, double &t) const {
    const V3 o = ray.origin_;
    const V3 d = ray.direction_;
    const V3 oc = o - center_;
    std::cout << "oc: " << oc.x_ << " " << oc.y_ << " " << oc.z_ << std::endl;
    const double b = 2 * dot(oc, d);
    const double c = dot(oc, oc) - radius_ * radius_;
    double disc = b * b - 4 * c;
    if (disc < 1e-4)
        return false;
    disc = sqrt(disc);
    const double t0 = -b - disc;
    const double t1 = -b + disc;
    t = (t0 < t1) ? t0 : t1;
    return true;
}
