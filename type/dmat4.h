#if !defined (_type_dmat4_h_)
# define _type_dmat4_h_ 1

typedef union u_dmat4 dmat4;

union u_dmat4 {
    struct {
        double m00, m01, m02, m03,
               m10, m11, m12, m13,
               m20, m21, m22, m23,
               m30, m31, m32, m33;
    };
};

#endif /* _type_dmat4_h_ */
