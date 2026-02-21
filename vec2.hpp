#if !defined (_vec2_hpp_)
# define _vec2_hpp_ 1

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

    vec2(void);

    vec2(const float);

    vec2(const float, const float);

    vec2(const vec2 &);

    vec2 &operator = (const vec2 &);

    vec2 operator + (const vec2 &) const;

    vec2 operator - (const vec2 &) const;

    vec2 operator * (const vec2 &) const;

    vec2 operator / (const vec2 &) const;
};

# if defined (ALGEBRA_IMPLEMENTATION)

vec2::vec2(void) : x(0.0), y(0.0) { }

vec2::vec2(const float v) : x(v), y(v) { }

vec2::vec2(const float x, const float y) : x(x), y(y) { }

vec2::vec2(const vec2 &other) : x(other.x), y(other.y) { }

vec2 &vec2::operator = (const vec2 &other) {
    this->x = other.x;
    this->y = other.y;
    return (*this);
}

vec2 vec2::operator + (const vec2 &other) const {
    return (vec2(this->x + other.x,
                 this->y + other.y));
}

vec2 vec2::operator - (const vec2 &other) const {
    return (vec2(this->x - other.x,
                 this->y - other.y));
}

vec2 vec2::operator * (const vec2 &other) const {
    return (vec2(this->x * other.x,
                 this->y * other.y));
}

vec2 vec2::operator / (const vec2 &other) const {
    return (vec2(other.x > 0.0 ? this->x / other.x : 0.0,
                 other.y > 0.0 ? this->y / other.y : 0.0));
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec2_hpp_ */
