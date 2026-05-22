#if !defined (_vec3_hpp_)
# define _vec3_hpp_ 1
#
# if !defined ALGAPI
#  define ALGAPI extern inline
# endif /* ALGAPI */
#
# include "./type/vec3.hpp"
# include "./type/mat3.hpp"

inline vec3 operator + (vec3, vec3);

inline vec3 operator - (vec3, vec3);

inline vec3 operator * (vec3, vec3);

inline vec3 operator / (vec3, vec3);

inline vec3 operator + (vec3, float);

inline vec3 operator - (vec3, float);

inline vec3 operator * (vec3, float);

inline vec3 operator / (vec3, float);

inline vec3 operator * (vec3, mat3);

inline bool operator == (vec3, vec3);

inline bool operator != (vec3, vec3);

inline bool operator > (vec3, vec3);

inline bool operator >= (vec3, vec3);

inline bool operator < (vec3, vec3);

inline bool operator <= (vec3, vec3);

inline vec3 &operator += (vec3 &, vec3);

inline vec3 &operator -= (vec3 &, vec3);

inline vec3 &operator *= (vec3 &, vec3);

inline vec3 &operator /= (vec3 &, vec3);

inline vec3 &operator += (vec3 &, float);

inline vec3 &operator -= (vec3 &, float);

inline vec3 &operator *= (vec3 &, float);

inline vec3 &operator /= (vec3 &, float);

namespace alg {

    /* ... */

};

# if defined (ALGEBRA_IMPLEMENTATION)

namespace alg {

    /* ... */

};

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _vec3_hpp_ */
