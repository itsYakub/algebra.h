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

static inline float deg2rad(float f) { return (f * (PI / 180.0)); }

static inline float rad2deg(float f) { return (f * (180.0 / PI)); }

static inline float min(float a, float b) { return (a < b ? a : b); }

static inline float max(float a, float b) { return (a > b ? a : b); }

static inline float clamp(float f, float a, float b) { return (min(max(f, a), b)); }

static inline float clamp01(float f) { return (min(max(f, 0), 1)); }

static inline float lerp(float a, float b, float t) { return ((b - a) * t + a); }

#endif /* _utils_h_ */
