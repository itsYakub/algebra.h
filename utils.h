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

extern inline float deg2rad(float);

extern inline float rad2deg(float);

extern inline float min(float, float);

extern inline float max(float, float);

extern inline float clamp(float, float, float);

extern inline float clamp01(float);

extern inline float lerp(float, float, float);

# if defined (ALGEBRA_IMPLEMENTATION)

extern inline float deg2rad(float f) { return (f * (PI / 180.0)); }

extern inline float rad2deg(float f) { return (f * (180.0 / PI)); }

extern inline float min(float a, float b) { return (a < b ? a : b); }

extern inline float max(float a, float b) { return (a > b ? a : b); }

extern inline float clamp(float f, float a, float b) { return (min(max(f, a), b)); }

extern inline float clamp01(float f) { return (min(max(f, 0), 1)); }

extern inline float lerp(float a, float b, float t) { return ((b - a) * t + a); }

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _utils_h_ */
