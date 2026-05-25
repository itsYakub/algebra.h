#if !defined (_type_vec4_hpp_)
# define _type_vec4_hpp_ 1

using vec4 = union u_vec4;

union u_vec4 {
    struct {
        double x;
        double y;
        double z;
        double w;
    };

    struct {
        double r;
        double g;
        double b;
        double a;
    };
};

#endif /* _type_vec4_hpp_ */
