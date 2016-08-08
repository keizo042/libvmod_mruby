#include "vmod_mruby.h"
#include "vmod_class.h"
#include "vmod_mruby_acl.h"

mrb_value mrb_vcl_acl_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

mrb_value mrb_vcl_acl_log(mrb_state *mrb, mrb_value self)
{
    return self;
}

mrb_value mrb_vcl_acl_match(mrb_state *mrb, mrb_value self)
{
    return self;
}

void mrb_define_varnish_acl_class(mrb_state *mrb)
{
    struct RClass *acl = mrb_define_class_under_varnish(mrb, "ACL");
    mrb_define_method(mrb, acl, "initialize",  mrb_vcl_acl_init, MRB_ARGS_NONE());
}
