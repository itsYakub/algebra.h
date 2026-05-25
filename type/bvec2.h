#if !defined (_type_vec2_h_)
# define _type_vec2_h_ 1
#
# include <stdbool.h>

typedef union u_vec2 vec2;

union u_vec2 {
    struct {
        bool x;
        bool y;
    };

    struct {
        bool w;
        bool h;
    };
};

#endif /* _type_vec2_h_ */
