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
#  define deg2rad(f) ((f) * ((PI) / 180.0))
# endif /* deg2rad */
#
# if !defined (rad2deg)
#  define rad2deg(f) ((f) * (180.0 / (PI)))
# endif /* rad2deg */
#
# if !defined (min)
#  define min(a, b) ((a) < (b) ? (a) : (b))
# endif /* min */
#
# if !defined (max)
#  define max(a, b) ((a) > (b) ? (a) : (b))
# endif /* max */
#
# if !defined (clamp)
#  define clamp(f, a, b) (min(max((f), (a)), (b)))
# endif /* clamp */
#
# if !defined (clamp01)
#  define clamp01(f) (clamp((f), 0.0, 1.0))
# endif /* clamp01 */
#
# if !defined (lerp)
#  define lerp(a, b, t) (((b) - (a)) * (t) + (a))
# endif /* lerp */
#
# if !defined (lerp01)
#  define lerp01(a, b, t) (lerp(a, b, clamp01(t)))
# endif /* lerp01 */
#
#endif /* _utils_h_ */
