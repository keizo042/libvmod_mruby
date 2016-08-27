#include "vmod_mruby.h"
#include "vmod_class.h"
#include "vmod_mruby_acl.h"

mrb_value mrb_vcl_acl_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

mrb_value mrb_vcl_acl_log(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    const char *message = NULL;
    mrb_get_args(mrb, "z", &message);
    VRT_acl_log(ctx, message);
    return mrb_nil_value();
}

#if (VRT_MAJOR_VERSION >= 4U) && (VRT_MINOR_VERSION >= 0U)
mrb_value mrb_vcl_acl_match(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    mrb_value v,w;
    VCL_IP ip = NULL;
    VCL_ACL acl = NULL;
    int i;
    mrb_get_args(mrb, "oo", &v, &w);
    ip = mrb_vcl_ip_cptr(mrb, w);
    acl = mrb_vcl_acl_cptr(mrb, w);
    i = VRT_acl_match(ctx, acl, ip);
    return mrb_fixnum_value(i);
}
#endif

void mrb_define_varnish_acl_class(mrb_state *mrb)
{
    struct RClass *acl = mrb_define_class_under_varnish(mrb, "ACL");
    mrb_define_method(mrb,  acl,    "initialize",   mrb_vcl_acl_init,   MRB_ARGS_NONE());
    mrb_define_method(mrb,  acl,    "log",          mrb_vcl_acl_log,    MRB_ARGS_REQ(1));

#if (VRT_MAJOR_VERSION >= 4U) && (VRT_MINOR_VERSION >= 0U)
    mrb_define_method(mrb,  acl,    "match",        mrb_vcl_acl_match,  MRB_ARGS_REQ(1));
#endif
}
