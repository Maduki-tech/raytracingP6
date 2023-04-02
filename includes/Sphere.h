#ifndef SPHERE_H
#define SPHERE_H
#include "Ray.h"
#include "Vec3.h"
class Sphere {
  public:
    V3 center_;
    double radius_;
    Sphere();
    Sphere(const V3& c,double radius): center_(c), radius_(radius) {}
    V3 getNormal(const V3 &point) const {return (point - center_) / radius_;}
    bool intersects(const Ray &ray, double &t) const;

  private:
};

#endif // !#ifndef SPHERE_H
