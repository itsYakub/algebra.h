#if !defined (_vec4_hpp_)
# define _vec4_hpp_ 1
#
# if !defined ALGAPI
#  define ALGAPI extern inline
# endif /* ALGAPI */
#
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

    /* ... */

};

# if defined (ALGEBRA_IMPLEMENTATION)

namespace alg {

    /* ... */

};

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec4_hpp_ */
