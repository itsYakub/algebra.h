#if !defined (_mat3_hpp_)
# define _mat3_hpp_ 1
#
# if !defined ALGAPI
#  define ALGAPI extern inline
# endif /* ALGAPI */
#
# include "./type/vec3.hpp"
# include "./type/mat3.hpp"

inline mat3 operator + (mat3, mat3);

inline mat3 operator - (mat3, mat3);

inline mat3 operator * (mat3, mat3);

inline mat3 operator * (mat3, float);

inline vec3 operator * (mat3, vec3);

inline bool operator == (mat3, mat3);

inline bool operator != (mat3, mat3);

inline mat3 &operator += (mat3 &, mat3);

inline mat3 &operator -= (mat3 &, mat3);

inline mat3 &operator *= (mat3 &, mat3);

# if defined (ALGEBRA_IMPLEMENTATION)

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _mat3_hpp_ */
