#if !defined (_vec2_hpp_)
# define _vec2_hpp_ 1

struct mat2;

struct vec2 {
    union {
        struct {
            float x;
            float y;
        };

        struct {
            float w;
            float h;
        };

        float ptr[2];
    };
   
    /* constructors... */

    vec2(void);

    vec2(float);

    vec2(float, float);

    vec2(const vec2 &);
    
    /* properties... */

    static const vec2 zero;

    static const vec2 one;

    static const vec2 right;

    static const vec2 left;

    static const vec2 up;

    static const vec2 down;
   
    /* operator overloading... */

    vec2 &operator = (const vec2 &);

    vec2 operator + (vec2) const;
    
    vec2 operator - (vec2) const;
    
    vec2 operator * (vec2) const;
    
    vec2 operator / (vec2) const;
    
    vec2 operator + (float) const;
    
    vec2 operator - (float) const;
    
    vec2 operator * (float) const;
    
    vec2 operator / (float) const;
    
    vec2 operator * (mat2) const;
    
    vec2 &operator += (vec2);

    vec2 &operator -= (vec2);

    vec2 &operator *= (vec2);

    vec2 &operator /= (vec2);
    
    vec2 &operator += (float);

    vec2 &operator -= (float);

    vec2 &operator *= (float);

    vec2 &operator /= (float);
    
    vec2 &operator *= (mat2);

    bool operator == (vec2) const;
    
    bool operator != (vec2) const;
    
    bool operator > (vec2) const;
    
    bool operator >= (vec2) const;
    
    bool operator < (vec2) const;
    
    bool operator <= (vec2) const;
   
    /* static methods... */
    
    static float dot(vec2, vec2);
    
    static float length(vec2);

    static float distance(vec2, vec2);

    static float cross(vec2, vec2);
    
    static vec2 normalize(vec2);
};

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include <cmath>
#
#  include "./mat2.hpp"
    
/* constructors... */

vec2::vec2(void) : x(0.0), y(0.0) { }


vec2::vec2(float v) : x(v), y(v) { }


vec2::vec2(float x, float y) : x(x), y(y) { }


vec2::vec2(const vec2 &other) : x(other.x), y(other.y) { }

/* properties... */

const vec2 vec2::zero = vec2(0.0);


const vec2 vec2::one = vec2(1.0);


const vec2 vec2::right = vec2(1.0, 0.0);


const vec2 vec2::left = vec2(-1.0, 0.0);


const vec2 vec2::up = vec2(0.0, 1.0);


const vec2 vec2::down = vec2(0.0, -1.0);

/* operator overloading... */

vec2 &vec2::operator = (const vec2 &other) {
    this->x = other.x;
    this->y = other.y;
    return (*this);
}


vec2 vec2::operator + (vec2 other) const {
    return (vec2(this->x + other.x,
                 this->y + other.y));
}


vec2 vec2::operator - (vec2 other) const {
    return (vec2(this->x - other.x,
                 this->y - other.y));
}


vec2 vec2::operator * (vec2 other) const {
    return (vec2(this->x * other.x,
                 this->y * other.y));
}


vec2 vec2::operator / (vec2 other) const {
    return (vec2(other.x != 0.0 ? this->x / other.x : 0.0,
                 other.y != 0.0 ? this->y / other.y : 0.0));
}


vec2 vec2::operator + (float f) const {
    return (vec2(this->x + f,
                 this->y + f));
}


vec2 vec2::operator - (float f) const {
    return (vec2(this->x - f,
                 this->y - f));
}


vec2 vec2::operator * (float f) const {
    return (vec2(this->x * f,
                 this->y * f));
}


vec2 vec2::operator / (float f) const {
    return (vec2(f != 0.0 ? this->x / f : 0.0,
                 f != 0.0 ? this->y / f : 0.0));
}


vec2 vec2::operator * (mat2 m) const {
    return (vec2(m.m00 * this->x + m.m01 * this->y,
                 m.m10 * this->x + m.m11 * this->y));
}


vec2 &vec2::operator += (vec2 other) {
    this->x += other.x;
    this->y += other.y;
    return (*this);
}


vec2 &vec2::operator -= (vec2 other) {
    this->x -= other.x;
    this->y -= other.y;
    return (*this);
}


vec2 &vec2::operator *= (vec2 other) {
    this->x *= other.x;
    this->y *= other.y;
    return (*this);
}


vec2 &vec2::operator /= (vec2 other) {
    this->x = other.x != 0.0 ? this->x / other.x : 0.0;
    this->y = other.y != 0.0 ? this->y / other.y : 0.0;
    return (*this);
}


vec2 &vec2::operator += (float f) {
    this->x += f;
    this->y += f;
    return (*this);
}


vec2 &vec2::operator -= (float f) {
    this->x -= f;
    this->y -= f;
    return (*this);
}


vec2 &vec2::operator *= (float f) {
    this->x *= f;
    this->y *= f;
    return (*this);
}


vec2 &vec2::operator /= (float f) {
    this->x = f != 0.0 ? this->x / f : 0.0;
    this->y = f != 0.0 ? this->y / f : 0.0;
    return (*this);
}


vec2 &vec2::operator *= (mat2 m) {
    vec2 v = vec2(m.m00 * this->x + m.m01 * this->y,
                  m.m10 * this->x + m.m11 * this->y);

    *this = v;
    return (*this);
}


bool vec2::operator == (vec2 other) const {
    return (this->x == other.x &&
            this->y == other.y);
}


bool vec2::operator != (vec2 other) const {
    return (this->x != other.x ||
            this->y != other.y);
}


bool vec2::operator > (vec2 other) const {
    return (this->x > other.x ||
            this->y > other.y);
}


bool vec2::operator >= (vec2 other) const {
    return (this->x >= other.x ||
            this->y >= other.y);
}


bool vec2::operator < (vec2 other) const {
    return (this->x < other.x ||
            this->y < other.y);
}


bool vec2::operator <= (vec2 other) const {
    return (this->x <= other.x ||
            this->y <= other.y);
}

/* static methods... */

float vec2::dot(vec2 a, vec2 b) {
    return (a.x * b.x + a.y * b.y);
}


float vec2::length(vec2 a) {
    return (sqrt(a.x * a.x + a.y * a.y));
}


float vec2::distance(vec2 a, vec2 b) {
    return (sqrt((a.x - b.x) * (a.x - b.x) +
                 (a.y - b.y) * (a.y * b.y)));
}


float vec2::cross(vec2 a, vec2 b) {
    return (a.x * b.y - a.y * b.x);
}


vec2 vec2::normalize(vec2 a) {
    float len = vec2::length(a);

    vec2 vec = a;
    if (len == 0.0) {
        len = 1.0;
    }
    
    return (vec * (1.0 / len));
}


# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec2_hpp_ */
