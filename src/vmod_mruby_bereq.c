#include "vmod_mruby.h"
#include "vmod_class.h"

static mrb_value mrb_vcl_bereq_between_bytes_timeout(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    double timeout = VRT_r_bereq_between_bytes_timeout(ctx);
    return mrb_float_value(mrb, timeout);
}

static mrb_value mrb_vcl_bereq_connect_timeout(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    double timeout = VRT_r_bereq_connect_timeout(ctx);
    return mrb_float_value(mrb, timeout);
}

static mrb_value mrb_vcl_bereq_first_byte_timeout(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    double timeout = VRT_r_bereq_first_byte_timeout(ctx);
    return mrb_float_value(mrb, timeout);
}

static mrb_value mrb_vcl_bereq_method(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    const char *name = VRT_r_bereq_method(ctx);
    return mrb_str_new_cstr(mrb,name);
}

static mrb_value mrb_vcl_bereq_proto(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    const char *name = VRT_r_bereq_proto(ctx);
    return mrb_str_new_cstr(mrb, name);
}

static mrb_value mrb_vcl_bereq_retries(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    const int count = VRT_r_bereq_retries(ctx);
    return mrb_fixnum_value(count);
}

static mrb_value mrb_vcl_bereq_uncacheable(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    int val;
    val = VRT_r_bereq_uncacheable(ctx);
    if(0 == val)
    {
        return mrb_true_value();
    }else{
        return mrb_false_value();

    }
}

static mrb_value mrb_vcl_bereq_url(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    const char *url = VRT_r_bereq_url(ctx);
    return mrb_str_new_cstr(mrb, url);
}

static mrb_value mrb_vcl_bereq_xid(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    const char *xid = VRT_r_bereq_xid(ctx);
    return mrb_str_new_cstr(mrb, xid);

}


void mrb_define_vcl_bereq_class(mrb_state *mrb)
{
    struct RClass *bereq;
    bereq = mrb_define_class_under_varnish(mrb, "Bereq");

    mrb_define_method(mrb, bereq, "between_bytes_timeout",  mrb_vcl_bereq_between_bytes_timeout,    MRB_ARGS_NONE());
    mrb_define_method(mrb, bereq, "connect_timeout",        mrb_vcl_bereq_connect_timeout,          MRB_ARGS_NONE());
    mrb_define_method(mrb, bereq, "first_byte_timeout",     mrb_vcl_bereq_first_byte_timeout,       MRB_ARGS_NONE());
    mrb_define_method(mrb, bereq, "proto",                  mrb_vcl_bereq_proto,                    MRB_ARGS_NONE());
    mrb_define_method(mrb, bereq, "retries",                mrb_vcl_bereq_retries,                  MRB_ARGS_NONE());
    mrb_define_method(mrb, bereq, "uncacheable",            mrb_vcl_bereq_uncacheable,              MRB_ARGS_NONE());
    mrb_define_method(mrb, bereq, "url",                    mrb_vcl_bereq_url,                      MRB_ARGS_NONE());
    mrb_define_method(mrb, bereq, "xid",                    mrb_vcl_bereq_xid,                      MRB_ARGS_NONE());
    mrb_define_method(mrb, bereq, "method",                 mrb_vcl_bereq_method,                   MRB_ARGS_NONE());
    // maybe, http_get is hard to impl.
    // mrb_define_method(mrb, bereq, "http_get",               mrb_vcl_bereq_http_get,                 MRB_ARGS_NONE());


    return ;

}
