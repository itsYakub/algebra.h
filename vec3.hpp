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
    
    vec3operator += (vec3);

    vec3operator -= (vec3);

    vec3operator *= (vec3);

    vec3operator /= (vec3);
    
    vec3 &operator += (float);

    vec3 &operator -= (float);

    vec3 &operator *= (float);

    vec3 &operator /= (float);
   
    /* public methods... */
    
    float dot(vec3);

    float length(void);

    vec3 cross(vec3);

    vec3 normalize(void);
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

vec3 vec3::operator += (vec3 other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    return (*this);
}

vec3 vec3::operator -= (vec3 other) {
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    return (*this);
}

vec3 vec3::operator *= (vec3 other) {
    this->x *= other.x;
    this->y *= other.y;
    this->z *= other.z;
    return (*this);
}

vec3 vec3::operator /= (vec3 other) {
    this->x /= other.x > 0.0 ? this->x / other.x : 0.0;
    this->y /= other.y > 0.0 ? this->y / other.y : 0.0;
    this->z /= other.z > 0.0 ? this->z / other.z : 0.0;
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
    this->x /= f > 0.0 ? this->x / f : 0.0;
    this->y /= f > 0.0 ? this->y / f : 0.0;
    this->z /= f > 0.0 ? this->z / f : 0.0;
    return (*this);
}

float vec3::dot(vec3 other) {
    return (this->x * other.x + this->y * other.y + this->z * other.z);
}

float vec3::length(void) {
    return (sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2)));
}

vec3 vec3::cross(vec3 other) {
    vec3 vec;

    vec.x = this->y * other.z - this->z * other.y;
    vec.y = this->z * other.x - this->x * other.z;
    vec.z = this->x * other.y - this->y * other.x;
    return (vec);
}

vec3 vec3::normalize(void) {
    vec3 vec = *this;
    float len = vec.length();
    if (len > 0.0) {
        vec *= 1.0 / len;
    }
    return (vec);
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec3_hpp_ */
