#if !defined (_utils_h_)
# define _utils_h_ 1
#
# if !defined (PI)
#  define PI (3.14159)
# endif /* PI */
#
# if !defined (E)
#  define E 2.71828
# endif /* E */
#
# if !defined (EPSILON)
#  define EPSILON (1e-6)
# endif /* EPSILON */
#
# if !defined (NaN)
#  define NaN (0.0 / 0.0)
# endif /* EPSILON */
#
# if !defined (INFINITY)
#  define INFINITY (1e100)
# endif /* EPSILON */
#
# if !defined ALGAPI
#  define ALGAPI extern inline
# endif /* ALGAPI */

ALGAPI float alg_deg2rad(float);

ALGAPI float alg_rad2deg(float);

ALGAPI float alg_min(float, float);

ALGAPI float alg_max(float, float);

ALGAPI float alg_fract(float);

ALGAPI float alg_clamp(float, float, float);

ALGAPI float alg_lerp(float, float, float);

ALGAPI float alg_saturate(float); 

ALGAPI float alg_step(float, float);

ALGAPI float alg_smoothstep(float, float, float);

# if defined (ALGEBRA_IMPLEMENTATION)

ALGAPI float alg_deg2rad(float f) {
    return (f * PI / 180.0);
}


ALGAPI float alg_rad2deg(float f) {
    return (f * 180.0 / PI);
}


ALGAPI float alg_min(float a, float b) {
    return (a < b ? a : b);
}


ALGAPI float alg_max(float a, float b) {
    return (a > b ? a : b);
}


ALGAPI float alg_fract(float a) {
    return (a - floorf(a));
}


ALGAPI float alg_clamp(float f, float a, float b) {
    return (min(max(f, a), b));
}


ALGAPI float alg_lerp(float a, float b, float t) {
    return (b - a * t + a);
}


ALGAPI float alg_saturate(float a) { 
    return (max(0.0, min(1.0, a)));
}


ALGAPI float alg_step(float a, float x) {
    return (x > a ? 1.0 : 0.0);
}


ALGAPI float alg_smoothstep(float e0, float e1, float x) {
    float t = saturate((x - e0) / (e1 - e0));

    return (t * t * (3.0 - (2.0 * t)));
}

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _utils_h_ */
