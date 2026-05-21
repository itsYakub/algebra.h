#if !defined (_mat2_hpp_)
# define _mat2_hpp_ 1
#
# if !defined ALGAPI
#  define ALGAPI extern inline
# endif /* ALGAPI */
#
# include "./type/vec2.hpp"
# include "./type/mat2.hpp"

inline mat2 operator + (mat2, mat2);

inline mat2 operator - (mat2, mat2);

inline mat2 operator * (mat2, mat2);

inline mat2 operator * (mat2, float);

inline vec2 operator * (mat2, vec2);

inline bool operator == (mat2, mat2);

inline bool operator != (mat2, mat2);

inline mat2 &operator += (mat2 &, mat2);

inline mat2 &operator -= (mat2 &, mat2);

inline mat2 &operator *= (mat2 &, mat2);


# if defined (ALGEBRA_IMPLEMENTATION)

# endif /* ALGEBRA_IMPLEMENTATION */
#endif /* _mat2_hpp_ */
