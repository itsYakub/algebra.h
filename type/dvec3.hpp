#if !defined (_type_dvec3_hpp_)
# define _type_dvec3_hpp_ 1

using dvec3 = union u_dvec3;

union u_dvec3 {
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

#endif /* _type_dvec3_hpp_ */
