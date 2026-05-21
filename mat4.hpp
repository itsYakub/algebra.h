#if !defined (_mat4_hpp_)
# define _mat4_hpp_ 1
#
# if !defined ALGAPI
#  define ALGAPI extern inline
# endif /* ALGAPI */
#
# include "./type/vec4.hpp"
# include "./type/mat4.hpp"

inline mat4 operator + (mat4, mat4);

inline mat4 operator - (mat4, mat4);

inline mat4 operator * (mat4, mat4);

inline mat4 operator * (mat4, float);

inline vec4 operator * (mat4, vec4);

inline bool operator == (mat4, mat4);

inline bool operator != (mat4, mat4);

inline mat4 &operator += (mat4 &, mat4);

inline mat4 &operator -= (mat4 &, mat4);

inline mat4 &operator *= (mat4 &, mat4);

# if defined (ALGEBRA_IMPLEMENTATION)

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _mat4_hpp_ */
