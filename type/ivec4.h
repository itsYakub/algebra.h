#if !defined (_type_vec4_h_)
# define _type_vec4_h_ 1

typedef union u_vec4 vec4;

union u_vec4 {
    struct {
        int x;
        int y;
        int z;
        int w;
    };

    struct {
        int r;
        int g;
        int b;
        int a;
    };
};

#endif /* _type_vec4_h_ */
