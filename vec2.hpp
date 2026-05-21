#if !defined (_vec2_hpp_)
# define _vec2_hpp_ 1
#
# if !defined ALGAPI
#  define ALGAPI extern inline
# endif /* ALGAPI */
#
# include "./type/vec2.hpp"
# include "./type/mat2.hpp"

/* Operator - overloading */

inline vec2 operator + (vec2, vec2);

inline vec2 operator - (vec2, vec2);

inline vec2 operator * (vec2, vec2);

inline vec2 operator / (vec2, vec2);

inline vec2 operator % (vec2, vec2);

inline vec2 operator + (vec2, float);

inline vec2 operator - (vec2, float);

inline vec2 operator * (vec2, float);

inline vec2 operator / (vec2, float);

inline vec2 operator % (vec2, float);

inline vec2 operator * (vec2, mat2);

inline bool operator == (vec2, vec2);

inline bool operator != (vec2, vec2);

inline bool operator > (vec2, vec2);

inline bool operator >= (vec2, vec2);

inline bool operator < (vec2, vec2);

inline bool operator <= (vec2, vec2);

inline vec2 &operator += (vec2 &, vec2);

inline vec2 &operator -= (vec2 &, vec2);

inline vec2 &operator *= (vec2 &, vec2);

inline vec2 &operator /= (vec2 &, vec2);

inline vec2 &operator %= (vec2 &, vec2);

inline vec2 &operator += (vec2 &, float);

inline vec2 &operator -= (vec2 &, float);

inline vec2 &operator *= (vec2 &, float);

inline vec2 &operator /= (vec2 &, float);

inline vec2 &operator %= (vec2 &, float);

# if defined (ALGEBRA_IMPLEMENTATION)

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec2_hpp_ */
