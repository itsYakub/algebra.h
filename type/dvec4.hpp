#if !defined (_type_dvec4_hpp_)
# define _type_dvec4_hpp_ 1

using dvec4 = union u_dvec4;

union u_dvec4 {
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

#endif /* _type_dvec4_hpp_ */
