//
// Created by Paedda on 25.03.2018.
//

#ifndef RAYTRACER_LAMBERTIAN_H
#define RAYTRACER_LAMBERTIAN_H

#include "material.h"

vec3 random_in_unit_sphere() {
    vec3 p;
    do {
        p = 2.0 * vec3(drand48(), drand48(), drand48()) - vec3(1, 1, 1);
    } while (p.squared_length() >= 1);
    return p;
}

class lambertian : public material {
public:
    lambertian(const vec3 &a) : albedo(a) {}

    virtual bool scatter(const ray &r_in, const hit_record &rec, vec3 attenuation, ray &scattered) const {
        vec3 target = rec.p + rec.normal + random_in_unit_sphere();
        scattered = ray(rec.p, target - rec.p);
        attenuation = albedo;
        return (dot(scattered.direction(), rec.normal) > 0);
    }

    vec3 albedo;
};

#endif //RAYTRACER_LAMBERTIAN_H
