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
# if !defined (deg2rad)

static inline float __algebra_deg2rad(float f) {
    return (f * PI / 180.0);
}

#  define deg2rad __algebra_deg2rad
# endif /* deg2rad */
#
# if !defined (rad2deg)

static inline float __algebra_rad2deg(float f) {
    return (f * 180.0 / PI);
}

#  define rad2deg __algebra_rad2deg
# endif /* rad2deg */
#
# if !defined (min)

static inline float __algebra_min(float a, float b) {
    return (a < b ? a : b);
}

#  define min __algebra_min
# endif /* min */
#
# if !defined (max)

static inline float __algebra_max(float a, float b) {
    return (a > b ? a : b);
}

#  define max __algebra_max
# endif /* max */
#
# if !defined (clamp)

static inline float __algebra_clamp(float f, float a, float b) {
    return (min(max(f, a), b));
}

#  define clamp __algebra_clamp
# endif /* clamp */
#
# if !defined (clamp01)
#  define clamp01(f) (clamp((f), 0.0, 1.0))
# endif /* clamp01 */
#
# if !defined (lerp)

static inline float __algebra_lerp(float a, float b, float t) {
    return (b - a * t + a);
}

#  define lerp __algebra_lerp
# endif /* lerp */
#
# if !defined (lerp01)
#  define lerp01(a, b, t) (lerp((a), (b), clamp01((t))))
# endif /* lerp01 */
#
# if !defined (saturate)

static inline float __algebra_saturate(float a) { 
    return (max(0.0, min(1.0, a)));
}

#  define saturate __algebra_saturate
# endif /* saturate */
#
# if !defined (step)

static inline float __algebra_step(float a, float x) {
    return (x > a ? 1.0 : 0.0);
}

#  define step __algebra_step
# endif /* step */
#
# if !defined (smoothstep)

static inline float __algebra_smoothstep(float e0, float e1, float x) {
    float t = saturate((x - e0) / (e1 - e0));

    return (t * t * (3.0 - (2.0 * t)));
}

#  define smoothstep __algebra_smoothstep
# endif /* smoothstep */
#
#endif /* _utils_h_ */
