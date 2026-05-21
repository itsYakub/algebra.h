#if !defined (_type_mat3_hpp_)
# define _type_mat3_hpp_ 1

using mat3 = union u_mat3;

union u_mat3 {
    struct {
        float m00, m01, m02,
              m10, m11, m12,
              m20, m21, m22;
    };
};

#endif /* _type_mat3_hpp_ */
