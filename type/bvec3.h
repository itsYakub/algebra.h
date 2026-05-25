#if !defined (_type_vec3_h_)
# define _type_vec3_h_ 1
#
# include <stdbool.h>

typedef union u_vec3 vec3;

union u_vec3 {
    struct {
        bool x;
        bool y;
        bool z;
    };

    struct {
        bool r;
        bool g;
        bool b;
    };
};

#endif /* _type_vec3_h_ */
