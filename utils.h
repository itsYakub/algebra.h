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

/* NOTE:
 *  Static-inlining those functions because the cost of binary-size is cheaper then cost of context switch.
 *  Like, cmon, these functions could be macro - functions as well...
 * */

static inline float deg2rad(float);

static inline float rad2deg(float);


static inline float deg2rad(float f) { return (f * (PI / 180.0)); }

static inline float rad2deg(float f) { return (f * (180.0 / PI)); }

#endif /* _utils_h_ */
