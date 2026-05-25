#if !defined (_type_vec2_h_)
# define _type_vec2_h_ 1

typedef union u_vec2 vec2;

union u_vec2 {
    struct {
        int x;
        int y;
    };

    struct {
        int w;
        int h;
    };
};

#endif /* _type_vec2_h_ */
