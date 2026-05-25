#if !defined (_type_vec4_h_)
# define _type_vec4_h_ 1
#
# include <stdbool.h>

typedef union u_vec4 vec4;

union u_vec4 {
    struct {
        bool x;
        bool y;
        bool z;
        bool w;
    };

    struct {
        bool r;
        bool g;
        bool b;
        bool a;
    };
};

#endif /* _type_vec4_h_ */
