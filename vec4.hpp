#if !defined (_vec4_hpp_)
# define _vec4_hpp_ 1
#
# include "./algebra-fwd.hpp"
# include "./type/vec4.hpp"
# include "./type/mat4.hpp"

inline vec4 operator + (vec4, vec4);

inline vec4 operator - (vec4, vec4);

inline vec4 operator * (vec4, vec4);

inline vec4 operator / (vec4, vec4);

inline vec4 operator + (vec4, float);

inline vec4 operator - (vec4, float);

inline vec4 operator * (vec4, float);

inline vec4 operator / (vec4, float);

inline vec4 operator * (vec4, mat4);

inline bool operator == (vec4, vec4);

inline bool operator != (vec4, vec4);

inline bool operator > (vec4, vec4);

inline bool operator >= (vec4, vec4);

inline bool operator < (vec4, vec4);

inline bool operator <= (vec4, vec4);

inline vec4 &operator += (vec4 &, vec4);

inline vec4 &operator -= (vec4 &, vec4);

inline vec4 &operator *= (vec4 &, vec4);

inline vec4 &operator /= (vec4 &, vec4);

inline vec4 &operator += (vec4 &, float);

inline vec4 &operator -= (vec4 &, float);

inline vec4 &operator *= (vec4 &, float);

inline vec4 &operator /= (vec4 &, float);

namespace alg {

    template <>
	vec4 init<vec4>(float);

    template <>
	vec4 init<vec4>(float, float);

    template <>
	vec4 init<vec4>(float, float, float);

    template <>
	vec4 init<vec4>(float, float, float, float);

    template <>
	vec4 rotate<vec4>(vec4, float);

    template <>
	float len<vec4>(vec4);

    template <>
	float lensq<vec4>(vec4);

    template <>
	float dist<vec4>(vec4, vec4);

    template <>
	float distsq<vec4>(vec4, vec4);

    template <>
	float dot<vec4>(vec4, vec4);

    template <>
	vec4 norm<vec4>(vec4);

    template <>
	vec4 neg<vec4>(vec4);

    template <>
	vec4 abs<vec4>(vec4);

    template <>
	vec4 sign<vec4>(vec4);

    template <>
	vec4 sqrt<vec4>(vec4);

    template <>
	vec4 pow<vec4>(vec4, float);

    template <>
	vec4 fract<vec4>(vec4);

    template <>
	vec4 floor<vec4>(vec4);

    template <>
	vec4 ceil<vec4>(vec4);

    template <>
	vec4 round<vec4>(vec4);

    template <>
	vec4 min<vec4>(vec4, vec4);

    template <>
	vec4 minf<vec4>(vec4, float);

    template <>
	vec4 max<vec4>(vec4, vec4);

    template <>
	vec4 maxf<vec4>(vec4, float);

    template <>
	vec4 clamp<vec4>(vec4, vec4, vec4);

    template <>
	vec4 clampf<vec4>(vec4, float, float);

    template <>
	vec4 lerp<vec4>(vec4, vec4, float);

    template <>
	vec4 step<vec4>(vec4, vec4);

    template <>
	vec4 smoothstep<vec4>(vec4, vec4, vec4);

    template <>
	vec4 reflect<vec4>(vec4, vec4);

    template <>
	vec4 refract<vec4>(vec4, vec4, float);

};

# if defined (ALGEBRA_IMPLEMENTATION)
#
#  include "./utils.hpp"
#
#  include <cmath>

inline vec4 operator + (vec4 a, vec4 b) {
    vec4 v;

    v.x = a.x + b.x;
    v.y = a.y + b.y;
    v.z = a.z + b.z;
    v.w = a.w + b.w;
    return (v);
}


inline vec4 operator - (vec4 a, vec4 b) {
    vec4 v;

    v.x = a.x - b.x;
    v.y = a.y - b.y;
    v.z = a.z - b.z;
    v.w = a.w - b.w;
    return (v);
}


inline vec4 operator * (vec4 a, vec4 b) {
    vec4 v;

    v.x = a.x * b.x;
    v.y = a.y * b.y;
    v.z = a.z * b.z;
    v.w = a.w * b.w;
    return (v);
}


inline vec4 operator / (vec4 a, vec4 b) {
    vec4 v;

    v.x = b.x != 0.0f ? a.x / b.x : 0.0f;
    v.y = b.y != 0.0f ? a.y / b.y : 0.0f;
    v.z = b.z != 0.0f ? a.z / b.z : 0.0f;
    v.w = b.w != 0.0f ? a.w / b.w : 0.0f;
    return (v);
}


inline vec4 operator % (vec4 a, vec4 b) {
    vec4 v;

    v.x = a.x - b.x * floorf(a.x / b.x);
    v.y = a.y - b.y * floorf(a.y / b.y);
    v.z = a.z - b.z * floorf(a.z / b.z);
    v.w = a.w - b.w * floorf(a.w / b.w);
    return (v);
}


inline vec4 operator + (vec4 a, float f) {
    vec4 v;

    v.x = a.x + f;
    v.y = a.y + f;
    v.z = a.z + f;
    v.w = a.w + f;
    return (v);
}


inline vec4 operator - (vec4 a, float f) {
    vec4 v;

    v.x = a.x - f;
    v.y = a.y - f;
    v.z = a.z - f;
    v.w = a.w - f;
    return (v);
}


inline vec4 operator * (vec4 a, float f) {
    vec4 v;

    v.x = a.x * f;
    v.y = a.y * f;
    v.z = a.z * f;
    v.w = a.w * f;
    return (v);
}


inline vec4 operator / (vec4 a, float f) {
    vec4 v;

    v.x = f != 0.0f ? a.x / f : 0.0f;
    v.y = f != 0.0f ? a.y / f : 0.0f;
    v.z = f != 0.0f ? a.z / f : 0.0f;
    v.w = f != 0.0f ? a.w / f : 0.0f;
    return (v);
}


inline vec4 operator % (vec4 a, float f) {
    vec4 v;

    v.x = a.x - f * floorf(a.x / f);
    v.y = a.y - f * floorf(a.y / f);
    v.z = a.z - f * floorf(a.z / f);
    v.w = a.w - f * floorf(a.w / f);
    return (v);
}


inline vec4 operator * (vec4 a, mat4 m) {
    vec4 v;

    v.x = m.m00 * a.x + m.m10 * a.y + m.m20 * a.z;
    v.y = m.m01 * a.x + m.m11 * a.y + m.m21 * a.z;
    v.z = m.m02 * a.x + m.m12 * a.y + m.m22 * a.z;
    v.w = m.m02 * a.x + m.m12 * a.y + m.m22 * a.w;
    return (v);
}


inline bool operator == (vec4 a, vec4 b) {
    return (fabsf(a.x - b.x) < 1e-6f &&
            fabsf(a.y - b.y) < 1e-6f &&
            fabsf(a.z - b.z) < 1e-6f &&
            fabsf(a.w - b.w) < 1e-6f);
}


inline bool operator != (vec4 a, vec4 b) {
    return (!(a == b));
}


inline bool operator > (vec4 a, vec4 b) {
    return (a.x > b.x ||
            a.y > b.y ||
            a.z > b.z ||
            a.w > b.w);
}


inline bool operator >= (vec4 a, vec4 b) {
    return (a.x >= b.x ||
            a.y >= b.y ||
            a.z >= b.z ||
            a.w >= b.w);
}


inline bool operator < (vec4 a, vec4 b) {
    return (a.x < b.x ||
            a.y < b.y ||
            a.z < b.z ||
            a.w < b.w);
}


inline bool operator <= (vec4 a, vec4 b) {
    return (a.x <= b.x ||
            a.y <= b.y ||
            a.z <= b.z ||
            a.w <= b.w);
}


inline vec4 &operator += (vec4 &a, vec4 b) {
    a = a + b;
    return (a);
}


inline vec4 &operator -= (vec4 &a, vec4 b) {
    a = a - b;
    return (a);
}


inline vec4 &operator *= (vec4 &a, vec4 b) {
    a = a * b;
    return (a);
}


inline vec4 &operator /= (vec4 &a, vec4 b) {
    a = a / b;
    return (a);
}


inline vec4 &operator %= (vec4 &a, vec4 b) {
    a = a % b;
    return (a);
}


inline vec4 &operator += (vec4 &a, float f) {
    a = a + f;
    return (a);
}


inline vec4 &operator -= (vec4 &a, float f) {
    a = a - f;
    return (a);
}


inline vec4 &operator *= (vec4 &a, float f) {
    a = a * f;
    return (a);
}


inline vec4 &operator /= (vec4 &a, float f) {
    a = a / f;
    return (a);
}


inline vec4 &operator %= (vec4 &a, float f) {
    a = a % f;
    return (a);
}

namespace alg {

    template <>
	vec4 init<vec4>(float x) {
        vec4 v;

        v.x = x;
        v.y = 0.0f;
        v.z = 0.0f;
        v.w = 0.0f;
        return (v);
	}


    template <>
	vec4 init<vec4>(float x, float y) {
        vec4 v;

        v.x = x;
        v.y = y;
        v.z = 0.0f;
        v.w = 0.0f;
        return (v);
	}


    template <>
	vec4 init<vec4>(float x, float y, float z) {
        vec4 v;

        v.x = x;
        v.y = y;
        v.z = z;
        v.w = 0.0f;
        return (v);
	}


    template <>
	vec4 init<vec4>(float x, float y, float z, float w) {
        vec4 v;

        v.x = x;
        v.y = y;
        v.z = z;
        v.z = w;
        return (v);
	}


    template <>
	vec4 rotate<vec4>(vec4 x, vec4 axis, float angle) {
        float a = cosf(angle / 2.0);

        vec4  n = alg::norm<vec4>(axis);
        float s = sinf(angle / 2.0);
        float b = n.x * s;
        float c = n.y * s;
        float d = n.z * s;

        vec4 w;
        w.x = b, w.y = c, w.z = d;
        
        vec4 v;
        v.x = x.x + 2.0 * a * (w.x * x.x) + 2.0 * (w.x * (w.x * x.x));
        v.y = x.y + 2.0 * a * (w.y * x.y) + 2.0 * (w.y * (w.y * x.y));
        v.z = x.z + 2.0 * a * (w.z * x.z) + 2.0 * (w.z * (w.z * x.z));
        return (v);
	}


    template <>
	float len<vec4>(vec4 a) {
        return (sqrtf(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w));
	}


    template <>
	float lensq<vec4>(vec4 a) {
        return (a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
	}


    template <>
	float dist<vec4>(vec4 a, vec4 b) {
        return (sqrtf((a.x - b.x) * (a.x - b.x) +
                      (a.y - b.y) * (a.y - b.y) +
                      (a.z - b.z) * (a.z - b.z) +
                      (a.w - b.w) * (a.w - b.w)));
	}


    template <>
	float distsq<vec4>(vec4 a, vec4 b) {
        return ((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y) +
                (a.z - b.z) * (a.z - b.z) +
                (a.w - b.w) * (a.w - b.w));
	}


    template <>
	float dot<vec4>(vec4 a, vec4 b) {
        return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
	}


    template <>
	vec4 norm<vec4>(vec4 a) {
        float len = alg::len<vec4>(a);

        if (len != 0.0f) {
            a.x *= 1.0f / len;
            a.y *= 1.0f / len;
            a.z *= 1.0f / len;
            a.w *= 1.0f / len;
        }
        return (a);
	}


    template <>
	vec4 neg<vec4>(vec4 a) {
        a.x = -a.x;
        a.y = -a.y;
        a.z = -a.z;
        a.w = -a.w;
        return (a);
	}


    template <>
	vec4 abs<vec4>(vec4 a) {
        a.x = fabsf(a.x);
        a.y = fabsf(a.y);
        a.z = fabsf(a.z);
        a.w = fabsf(a.w);
        return (a);
	}


    template <>
	vec4 sign<vec4>(vec4 a) {
        a.x = a.x > 0.0f ? 1.0f : (a.x < 0.0f ? -1.0f : 0.0f);
        a.y = a.y > 0.0f ? 1.0f : (a.y < 0.0f ? -1.0f : 0.0f);
        a.z = a.z > 0.0f ? 1.0f : (a.z < 0.0f ? -1.0f : 0.0f);
        a.w = a.w > 0.0f ? 1.0f : (a.w < 0.0f ? -1.0f : 0.0f);
        return (a);
	}


    template <>
	vec4 sqrt<vec4>(vec4 a) {
        a.x = sqrtf(a.x);
        a.y = sqrtf(a.y);
        a.z = sqrtf(a.z);
        a.w = sqrtf(a.w);
        return (a);
	}


    template <>
	vec4 pow<vec4>(vec4 a, float f) {
        a.x = powf(a.x, f);
        a.y = powf(a.y, f);
        a.z = powf(a.z, f);
        a.w = powf(a.w, f);
        return (a);
	}


    template <>
	vec4 fract<vec4>(vec4 a) {
        a.x = alg_fract(a.x);
        a.y = alg_fract(a.y);
        a.z = alg_fract(a.z);
        a.w = alg_fract(a.w);
        return (a);
	}


    template <>
	vec4 floor<vec4>(vec4 a) {
        a.x = floorf(a.x);
        a.y = floorf(a.y);
        a.z = floorf(a.z);
        a.w = floorf(a.w);
        return (a);
	}


    template <>
	vec4 ceil<vec4>(vec4 a) {
        a.x = ceilf(a.x);
        a.y = ceilf(a.y);
        a.z = ceilf(a.z);
        a.w = ceilf(a.w);
        return (a);
	}


    template <>
	vec4 round<vec4>(vec4 a) {
        a.x = roundf(a.x);
        a.y = roundf(a.y);
        a.z = roundf(a.z);
        a.w = roundf(a.w);
        return (a);
	}


    template <>
	vec4 min<vec4>(vec4 a, vec4 b) {
        vec4 v;

        v.x = alg_min(a.x, b.x);
        v.y = alg_min(a.y, b.y);
        v.z = alg_min(a.z, b.z);
        v.w = alg_min(a.w, b.w);
        return (v);
	}


    template <>
	vec4 minf<vec4>(vec4 a, float f) {
        vec4 v;

        v.x = alg_min(a.x, f);
        v.y = alg_min(a.y, f);
        v.z = alg_min(a.z, f);
        v.w = alg_min(a.w, f);
        return (v);
	}


    template <>
	vec4 max<vec4>(vec4 a, vec4 b) {
        vec4 v;

        v.x = alg_max(a.x, b.x);
        v.y = alg_max(a.y, b.y);
        v.z = alg_max(a.z, b.z);
        v.w = alg_max(a.w, b.w);
        return (v);
	}


    template <>
	vec4 maxf<vec4>(vec4 a, float f) {
        vec4 v;

        v.x = alg_max(a.x, f);
        v.y = alg_max(a.y, f);
        v.z = alg_max(a.z, f);
        v.w = alg_max(a.w, f);
        return (v);
	}


    template <>
	vec4 clamp<vec4>(vec4 a, vec4 lo, vec4 hi) {
        vec4 v;

        v.x = alg_clamp(a.x, lo.x, hi.x);
        v.y = alg_clamp(a.y, lo.y, hi.y);
        v.z = alg_clamp(a.z, lo.z, hi.z);
        v.w = alg_clamp(a.w, lo.w, hi.w);
        return (v);
	}


    template <>
	vec4 clampf<vec4>(vec4 a, float lo, float hi) {
        vec4 v;

        v.x = alg_clamp(a.x, lo, hi);
        v.y = alg_clamp(a.y, lo, hi);
        v.z = alg_clamp(a.z, lo, hi);
        v.w = alg_clamp(a.w, lo, hi);
        return (v);
	}


    template <>
	vec4 lerp<vec4>(vec4 a, vec4 b, float t) {
        vec4 v;

        v.x = alg_lerp(a.x, b.x, t);
        v.y = alg_lerp(a.y, b.y, t);
        v.z = alg_lerp(a.z, b.z, t);
        v.w = alg_lerp(a.w, b.w, t);
        return (v);
	}


    template <>
	vec4 step<vec4>(vec4 a, vec4 x) {
        vec4 v;

        v.x = alg_step(a.x, x.x);
        v.y = alg_step(a.y, x.y);
        v.z = alg_step(a.z, x.z);
        v.w = alg_step(a.w, x.w);
        return (v);
	}


    template <>
	vec4 smoothstep<vec4>(vec4 e0, vec4 e1, vec4 x) {
        vec4 v;

        v.x = alg_smoothstep(e0.x, e1.x, x.x);
        v.y = alg_smoothstep(e0.y, e1.y, x.y);
        v.z = alg_smoothstep(e0.z, e1.z, x.z);
        v.w = alg_smoothstep(e0.w, e1.w, x.w);
        return (v);
	}


    template <>
	vec4 reflect<vec4>(vec4 a, vec4 n) {
        float dot = alg::dot<vec4>(a, n);
        vec4  v;

        v.x = a.x - 2.0f * dot * n.x;
        v.y = a.y - 2.0f * dot * n.y;
        v.z = a.z - 2.0f * dot * n.z;
        v.w = a.w - 2.0f * dot * n.w;
        return (v);
	}


    template <>
	vec4 refract<vec4>(vec4 a, vec4 n, float eta) {
        float dot = alg::dot<vec4>(a, n);
        float d   = 1.0f - eta * eta * (1.0 - dot * dot);

        vec4 v = alg::init<vec4>(0.0);
        if (d >= 0) {
            d = sqrtf(d);
            v.x = eta * a.x - (eta * dot + d) * n.x;
            v.y = eta * a.y - (eta * dot + d) * n.y;
            v.z = eta * a.z - (eta * dot + d) * n.z;
            v.w = eta * a.w - (eta * dot + d) * n.w;
        }

        return (v);
	}

};

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec4_hpp_ */
