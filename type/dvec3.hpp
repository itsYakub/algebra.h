#if !defined (_type_vec3_hpp_)
# define _type_vec3_hpp_ 1

using vec3 = union u_vec3;

union u_vec3 {
    struct {
        double x;
        double y;
        double z;
    };

    struct {
        double r;
        double g;
        double b;
    };
};

#endif /* _type_vec3_hpp_ */
