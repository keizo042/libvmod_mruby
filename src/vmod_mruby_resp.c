#include "vmod_mruby.h"
#include "vmod_class.h"
#include "vmod_mruby_resp.h"
static mrb_value mrb_vcl_resp_is_streaming(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    VCL_BOOL v = VRT_r_resp_is_streaming(ctx);
    if(0 == v)
    {
        return mrb_false_value();
    }else{
        return mrb_true_value();
    }



}

static mrb_value  mrb_vcl_resp_proto(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_str_new_cstr(mrb, VRT_r_resp_proto(ctx));
}

static mrb_value mrb_vcl_resp_reason(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_str_new_cstr(mrb, VRT_r_resp_reason(ctx));
}

static mrb_value mrb_vcl_resp_status(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_float_value(mrb, VRT_r_resp_status(ctx) );
}

void mrb_define_vcl_resp_class(mrb_state *mrb)
{
    struct RClass *resp;
    resp = mrb_define_class_under_varnish(mrb, "Resp");

    mrb_define_method(mrb, resp, "is_streaming", mrb_vcl_resp_is_streaming, MRB_ARGS_NONE());
    mrb_define_method(mrb, resp, "reason", mrb_vcl_resp_reason, MRB_ARGS_NONE());
    mrb_define_method(mrb, resp, "proto", mrb_vcl_resp_proto, MRB_ARGS_NONE());
    mrb_define_method(mrb, resp, "status", mrb_vcl_resp_status, MRB_ARGS_NONE());
    return ;
}
