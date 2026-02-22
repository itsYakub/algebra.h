#if !defined (_vec3_hpp_)
# define _vec3_hpp_ 1
#
# include <cmath>

struct vec3 {
    union {
        struct {
            float x;
            float y;
            float z;
        };

        struct {
            float r;
            float g;
            float b;
        };

        float ptr[3];
    };
   
    /* constructors... */

    vec3(void);

    vec3(const float);

    vec3(const float, const float, const float);

    vec3(const vec3 &);
   
    /* operator overloading... */

    vec3 &operator = (const vec3 &);

    vec3 operator + (const vec3 &) const;
    
    vec3 operator += (const vec3 &) const;

    vec3 operator - (const vec3 &) const;
    
    vec3 operator -= (const vec3 &) const;

    vec3 operator * (const vec3 &) const;
    
    vec3 operator *= (const vec3 &) const;

    vec3 operator / (const vec3 &) const;
    
    vec3 operator /= (const vec3 &) const;
   
    /* public methods... */

    float length(void);

    vec3 &cross(const vec3 &);

    vec3 &normalize(void);
};

# if defined (ALGEBRA_IMPLEMENTATION)

vec3::vec3(void) : x(0.0), y(0.0), z(0.0) { }

vec3::vec3(const float v) : x(v), y(v), z(v) { }

vec3::vec3(const float x, const float y, const float z) : x(x), y(y), z(z) { }

vec3::vec3(const vec3 &other) : x(other.x), y(other.y), z(other.z) { }

vec3 &vec3::operator = (const vec3 &other) {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    return (*this);
}

vec3 vec3::operator + (const vec3 &other) const {
    return (vec3(this->x + other.x,
                 this->y + other.y,
                 this->z + other.z));
}

vec3 vec3::operator += (const vec3 &other) const {
    return (*this + other);
}

vec3 vec3::operator - (const vec3 &other) const {
    return (vec3(this->x - other.x,
                 this->y - other.y,
                 this->z - other.z));
}

vec3 vec3::operator -= (const vec3 &other) const {
    return (*this - other);
}

vec3 vec3::operator * (const vec3 &other) const {
    return (vec3(this->x * other.x,
                 this->y * other.y,
                 this->z * other.z));
}

vec3 vec3::operator *= (const vec3 &other) const {
    return (*this * other);
}

vec3 vec3::operator / (const vec3 &other) const {
    return (vec3(other.x > 0.0 ? this->x / other.x : 0.0,
                 other.y > 0.0 ? this->y / other.y : 0.0,
                 other.z > 0.0 ? this->z / other.z : 0.0));
}

vec3 vec3::operator /= (const vec3 &other) const {
    return (*this / other);
}

float vec3::length(void) {
    return (sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2)));
}

vec3 &vec3::cross(const vec3 &other) {
    vec3 vec;

    vec.x = this->y * other.z - this->z * other.y;
    vec.y = this->x * other.z - this->z * other.x;
    vec.z = this->x * other.y - this->x * other.y;
    *this = vec;
    return (*this);
}

vec3 &vec3::normalize(void) {
    *this = vec3();
    float len  = this->length();
    if (len > 0.0) {
        *this *= 1.0 / len;
    }
    return (*this);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec3_hpp_ */
