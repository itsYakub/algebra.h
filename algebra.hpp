#if defined (__cplusplus)
# pragma once
#endif /* __cplusplus */
#
#if !defined (_algebra_hpp_)
# define _algebra_hpp_ 1
#
# /* fall-back to C */
# if !defined (__cplusplus)
#  include "algebra.h"
# else
#  include "vec2.hpp"
#  include "vec3.hpp"
#  include "vec4.hpp"
#  include "mat2.hpp"
#  include "mat3.hpp"
#  include "mat4.hpp"
#  include "utils.hpp"
# endif /* __cplusplus */
#endif /* _algebra_hpp_ */
