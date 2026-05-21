#if !defined (_type_vec2_h_)
# define _type_vec2_h_ 1

typedef union u_vec2 vec2;

union u_vec2 {
    struct {
        float x;
        float y;
    };

    struct {
        float w;
        float h;
    };
};

#endif /* _type_vec2_h */
