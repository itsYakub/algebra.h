#if defined (__cplusplus)
# pragma once
#endif /* __cplusplus */
#
#if !defined (_algebra_h_)
# define _algebra_h_ 1
#
# /* fall-back to C++ */
# if defined (__cplusplus)
#  include "algebra.hpp"
# else
#  include "vec2.h"
#  include "vec3.h"
#  include "vec4.h"
#  include "mat2.h"
#  include "mat3.h"
#  include "mat4.h"
#  include "utils.h"
# endif /* __cplusplus */
#endif /* _algebra_h_ */
