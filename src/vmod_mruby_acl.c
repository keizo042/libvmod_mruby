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
    mrb_value v;
    mrb_get_args(mrb, "s", &v);
    VRT_acl_log(ctx,RSTRING_PTR(v));
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
    i = VRT_acl_match(ctx, acl, ip);
    return mrb_fixnum_value(i);
}
#endif

void mrb_define_varnish_acl_class(mrb_state *mrb)
{
    struct RClass *acl = mrb_define_class_under_varnish(mrb, "ACL");
    mrb_define_method(mrb, acl, "initialize",  mrb_vcl_acl_init, MRB_ARGS_NONE());
}
