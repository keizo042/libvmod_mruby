#include "vmod_mruby.h"
#include "vmod_class.h"
#include "vmod_mruby_req.h"
static mrb_value mrb_vcl_req_can_gzip(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    VCL_BOOL v = VRT_r_req_can_gzip(ctx);
    if(0 == v)
    {
    return mrb_true_value();
    }else
    {
        return mrb_false_value();
    }
}

static mrb_value mrb_vcl_req_esi(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_float_value(mrb, VRT_r_req_esi(ctx));
}

static mrb_value mrb_vcl_req_esi_level(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_float_value(mrb, VRT_r_req_esi_level(ctx));
}


static mrb_value mrb_vcl_req_hash_always_miss(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    VCL_BOOL v = VRT_r_req_hash_always_miss(ctx);
    if(0 == v)
    {
        return mrb_true_value();
    }else
    {
        return mrb_false_value();
    }
}

static mrb_value mrb_vcl_req_hash_ignore_busy(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    VCL_BOOL v = VRT_r_req_hash_ignore_busy(ctx);
    if(0 == v)
    {
        return mrb_true_value();
    }else
    {
        return mrb_false_value();
    }
}


static mrb_value mrb_vcl_req_proto(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_str_new_cstr(mrb, VRT_r_req_proto(ctx));
}

static mrb_value mrb_vcl_req_restarts(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_fixnum_value( VRT_r_req_restarts(ctx));
}

static mrb_value mrb_vcl_req_url(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_str_new_cstr(mrb, VRT_r_req_url(ctx));
}

#if 0
static mrb_value mrb_vcl_req_url(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_str_new_cstr(mrb, VRT_r_req_top_url(ctx));
}
#endif

void mrb_define_vcl_req_class(mrb_state *mrb)
{
    struct RClass *req;
    req = mrb_define_class_under_varnish(mrb, "Req");

    mrb_define_method(mrb, req, "can_gzip", mrb_vcl_req_can_gzip, MRB_ARGS_NONE());
    mrb_define_method(mrb, req, "esi", mrb_vcl_req_esi, MRB_ARGS_NONE());
    mrb_define_method(mrb, req, "esi_level", mrb_vcl_req_esi_level, MRB_ARGS_NONE());
    mrb_define_method(mrb, req, "hash_always_miss", mrb_vcl_req_hash_always_miss, MRB_ARGS_NONE());
    mrb_define_method(mrb, req, "hash_ignore_busy", mrb_vcl_req_hash_ignore_busy, MRB_ARGS_NONE());
    mrb_define_method(mrb, req, "proto", mrb_vcl_req_proto, MRB_ARGS_NONE());
    mrb_define_method(mrb, req, "restarts", mrb_vcl_req_restarts, MRB_ARGS_NONE());
    mrb_define_method(mrb, req, "url", mrb_vcl_req_url, MRB_ARGS_NONE());
#if 0
    mrb_define_method(mrb, req, "top_url", mrb_vcl_req_top_url, MRB_ARGS_NONE());
#endif
    return ;
}
