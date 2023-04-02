#ifndef RAY_H
#define RAY_H

#include "Vec3.h"

class Ray {
  public:
    V3 origin_, direction_;
    Ray();
    Ray(const V3& origin, const V3& direction): origin_(origin), direction_(direction) {}
  private:
};

#endif // !#ifndef RAY_H
