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

    vec3(float);

    vec3(float, float, float);

    vec3(const vec3 &);
   
    /* operator overloading... */

    vec3 &operator = (const vec3 &);

    vec3 operator + (vec3) const;
    
    vec3 operator - (vec3) const;
    
    vec3 operator * (vec3) const;
    
    vec3 operator / (vec3) const;
    
    vec3 operator + (float) const;
    
    vec3 operator - (float) const;
    
    vec3 operator * (float) const;
    
    vec3 operator / (float) const;
    
    vec3 &operator += (vec3);

    vec3 &operator -= (vec3);

    vec3 &operator *= (vec3);

    vec3 &operator /= (vec3);
    
    vec3 &operator += (float);

    vec3 &operator -= (float);

    vec3 &operator *= (float);

    vec3 &operator /= (float);
   
    /* static methods... */
    
    static float dot(vec3, vec3);
    
    static float length(vec3);

    static vec3 cross(vec3, vec3);
    
    static vec3 normalize(vec3);
};

# if defined (ALGEBRA_IMPLEMENTATION)

vec3::vec3(void) : x(0.0), y(0.0), z(0.0) { }

vec3::vec3(float v) : x(v), y(v), z(v) { }

vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) { }

vec3::vec3(const vec3 &other) : x(other.x), y(other.y), z(other.z) { }

vec3 &vec3::operator = (const vec3 &other) {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    return (*this);
}

vec3 vec3::operator + (vec3 other) const {
    return (vec3(this->x + other.x,
                 this->y + other.y,
                 this->z + other.z));
}

vec3 vec3::operator - (vec3 other) const {
    return (vec3(this->x - other.x,
                 this->y - other.y,
                 this->z - other.z));
}

vec3 vec3::operator * (vec3 other) const {
    return (vec3(this->x * other.x,
                 this->y * other.y,
                 this->z * other.z));
}

vec3 vec3::operator / (vec3 other) const {
    return (vec3(other.x > 0.0 ? this->x / other.x : 0.0,
                 other.y > 0.0 ? this->y / other.y : 0.0,
                 other.z > 0.0 ? this->z / other.z : 0.0));
}

vec3 vec3::operator + (float f) const {
    return (vec3(this->x + f,
                 this->y + f,
                 this->z + f));
}

vec3 vec3::operator - (float f) const {
    return (vec3(this->x - f,
                 this->y - f,
                 this->z - f));
}

vec3 vec3::operator * (float f) const {
    return (vec3(this->x * f,
                 this->y * f,
                 this->z * f));
}

vec3 vec3::operator / (float f) const {
    return (vec3(f > 0.0 ? this->x / f : 0.0,
                 f > 0.0 ? this->y / f : 0.0,
                 f > 0.0 ? this->z / f : 0.0));
}

vec3 &vec3::operator += (vec3 other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    return (*this);
}

vec3 &vec3::operator -= (vec3 other) {
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    return (*this);
}

vec3 &vec3::operator *= (vec3 other) {
    this->x *= other.x;
    this->y *= other.y;
    this->z *= other.z;
    return (*this);
}

vec3 &vec3::operator /= (vec3 other) {
    this->x = other.x > 0.0 ? this->x / other.x : 0.0;
    this->y = other.y > 0.0 ? this->y / other.y : 0.0;
    this->z = other.z > 0.0 ? this->z / other.z : 0.0;
    return (*this);
}

vec3 &vec3::operator += (float f) {
    this->x += f;
    this->y += f;
    this->z += f;
    return (*this);
}

vec3 &vec3::operator -= (float f) {
    this->x -= f;
    this->y -= f;
    this->z -= f;
    return (*this);
}

vec3 &vec3::operator *= (float f) {
    this->x *= f;
    this->y *= f;
    this->z *= f;
    return (*this);
}

vec3 &vec3::operator /= (float f) {
    this->x = f != 0.0 ? this->x / f : 0.0;
    this->y = f != 0.0 ? this->y / f : 0.0;
    this->z = f != 0.0 ? this->z / f : 0.0;
    return (*this);
}

float vec3::dot(vec3 a, vec3 b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float vec3::length(vec3 a) {
    return (sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2)));
}

vec3 vec3::cross(vec3 a, vec3 b) {
    vec3 vec;

    vec.x = a.y * b.z - a.z * b.y;
    vec.y = a.z * b.x - a.x * b.z;
    vec.z = a.x * b.y - a.y * b.x;
    return (vec);
}

vec3 vec3::normalize(vec3 a) {
    float len = vec3::length(a);

    vec3 vec = a;
    if (len != 0.0) {
        vec *= 1.0 / len;
    }
    return (vec);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec3_hpp_ */
