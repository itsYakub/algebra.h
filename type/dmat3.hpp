#if !defined (_type_dmat3_hpp_)
# define _type_dmat3_hpp_ 1

using dmat3 = union u_dmat3;

union u_dmat3 {
    struct {
        double m00, m01, m02,
               m10, m11, m12,
               m20, m21, m22;
    };
};

#endif /* _type_dmat3_hpp_ */
