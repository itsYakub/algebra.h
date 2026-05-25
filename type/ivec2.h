#if !defined (_type_ivec2_h_)
# define _type_ivec2_h_ 1

typedef union u_ivec2 ivec2;

union u_ivec2 {
    struct {
        int x;
        int y;
    };

    struct {
        int w;
        int h;
    };
};

#endif /* _type_ivec2_h_ */
