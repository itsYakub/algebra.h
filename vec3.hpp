#if !defined (_vec3_hpp_)
# define _vec3_hpp_ 1

struct vec3 {
    union {
        struct {
            double x;
            double y;
            double z;
        };

        struct {
            double r;
            double g;
            double b;
        };

        double ptr[3];
    };

    vec3(void);

    vec3(const double);

    vec3(const double, const double, const double);

    vec3(const vec3 &);

    const vec3 &operator = (const vec3 &);

    vec3 operator + (const vec3 &);

    vec3 operator - (const vec3 &);

    vec3 operator * (const vec3 &);

    vec3 operator / (const vec3 &);
};

# if defined (ALGEBRA_IMPLEMENTATION)

vec3::vec3(void) : x(0.0), y(0.0), z(0.0) { }

vec3::vec3(const double v) : x(v), y(v), z(v) { }

vec3::vec3(const double x, const double y, const double z) : x(x), y(y), z(z) { }

vec3::vec3(const vec3 &other) : x(other.x), y(other.y), z(other.z) { }

const vec3 &vec3::operator = (const vec3 &other) {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    return (*this);
}

vec3 vec3::operator + (const vec3 &other) {
    return (vec3(this->x + other.x,
                 this->y + other.y,
                 this->z + other.z));
}

vec3 vec3::operator - (const vec3 &other) {
    return (vec3(this->x - other.x,
                 this->y - other.y,
                 this->z - other.z));
}

vec3 vec3::operator * (const vec3 &other) {
    return (vec3(this->x * other.x,
                 this->y * other.y,
                 this->z * other.z));
}

vec3 vec3::operator / (const vec3 &other) {
    return (vec3(other.x > 0.0 ? this->x / other.x : 0.0,
                 other.y > 0.0 ? this->y / other.y : 0.0,
                 other.z > 0.0 ? this->z / other.z : 0.0));
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec3_hpp_ */
