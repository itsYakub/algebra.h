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

# if defined (ALGEBRA_IMPLEMENTATION)

extern inline float deg2rad(float f) { return (f * (PI / 180.0)); }

extern inline float rad2deg(float f) { return (f * (180.0 / PI)); }

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _utils_h_ */
