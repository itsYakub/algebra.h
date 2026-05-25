#if !defined (_type_dmat3_h_)
# define _type_dmat3_h_ 1

typedef union u_dmat3 dmat3;

union u_dmat3 {
    struct {
        double m00, m01, m02,
               m10, m11, m12,
               m20, m21, m22;
    };
};

#endif /* _type_dmat3_h_ */
