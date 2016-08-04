#include "vmod_mruby.h"
#include "vmod_class.h"

mrb_value mrb_vcl_http_host(mrb_state *mrb, mrb_value self)
{
    return self;
}

mrb_value mrb_vcl_http_cookie(mrb_state *mrb, mrb_value self)
{
    return self;
}

mrb_value mrb_vcl_http_cache_control(mrb_state *mrb, mrb_value self)
{
    return self;
}

mrb_value mrb_vcl_http_pragma(mrb_state *mrb, mrb_value self)
{
    return self;
}

mrb_value mrb_vcl_http_user_agent(mrb_state *mrb, mrb_value self)
{
    return self;
}

mrb_value mrb_vcl_http_gethdr(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    char *args = NULL;
    struct gethdr_s hdr = {.where = HDR_RESP, .what = args };
    mrb_get_args(mrb, "v", args);
    if( VRT_GetHdr(ctx, &hdr )!= 0)
    {
        return mrb_true_value();
    }
        return mrb_false_value();
}

mrb_value mrb_vcl_http_sethdr(mrb_state *mrb, mrb_value self)
{
    return self;
}
void mrb_define_vcl_http_class(mrb_state *mrb)
{
    struct RClass  *http, *varnish;
    varnish = mrb_define_class(mrb, "HTTP", mrb->object_class);
    http = mrb_define_class_under(mrb, varnish, "HTTP", mrb->object_class);

    mrb_define_method(mrb, http, "host",            mrb_vcl_http_host,          MRB_ARGS_NONE());
    mrb_define_method(mrb, http, "cookie",          mrb_vcl_http_cookie,        MRB_ARGS_NONE());
    mrb_define_method(mrb, http, "cache_control",   mrb_vcl_http_cache_control, MRB_ARGS_NONE());
    mrb_define_method(mrb, http, "pragma",          mrb_vcl_http_pragma,        MRB_ARGS_NONE());
    mrb_define_method(mrb, http, "user_agent",      mrb_vcl_http_user_agent,    MRB_ARGS_NONE());
}