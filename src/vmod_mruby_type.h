#ifndef VMOD_MRUBY_TYPE_H
#define VMOD_MRUBY_TYPE_H
#include "mruby.h"
void mrb_define_vcl_type_class(mrb_state *mrb);
VCL_IP mrb_vcl_ip_cptr(mrb_state *mrb, mrb_value value);
VCL_ACL mrb_vcl_acl_cptr(mrb_state *mrb, mrb_value value);
#endif
