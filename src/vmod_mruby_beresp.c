#include "vmod_mruby.h"
#include "vmod_class.h"
#include "vmod_mruby_beresp.h"

static mrb_value mrb_vcl_beresp_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vcl_beresp_backend_ip(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_str_new_cstr(mrb, VRT_IP_string(ctx, VRT_r_beresp_backend_ip(ctx)));
}

static mrb_value mrb_vcl_beresp_backend_name(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;

    return mrb_str_new_cstr(mrb, VRT_r_beresp_backend_name(ctx));
}

static mrb_value mrb_vcl_beresp_backend_port(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_fixnum_value( VSA_Port(VRT_r_beresp_backend_ip(ctx)));
}

static mrb_value mrb_vcl_beresp_do_esi(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_fixnum_value( VRT_r_beresp_do_esi(ctx));
}

static mrb_value mrb_vcl_beresp_do_gunzip(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_fixnum_value( VRT_r_beresp_do_gunzip(ctx));
}

static mrb_value mrb_vcl_beresp_do_gzip(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_fixnum_value( VRT_r_beresp_do_gzip(ctx));
}

static mrb_value mrb_vcl_beresp_do_stream(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_fixnum_value( VRT_r_beresp_do_stream(ctx) );
}

static mrb_value mrb_vcl_beresp_grace(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_float_value(mrb, VRT_r_beresp_grace(ctx));
}

static mrb_value mrb_vcl_beresp_keep(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_float_value(mrb, VRT_r_beresp_keep(ctx));
}

static mrb_value mrb_vcl_beresp_proto(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_str_new_cstr(mrb, VRT_r_beresp_proto(ctx));
}

static mrb_value mrb_vcl_beresp_reason(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_str_new_cstr(mrb, VRT_r_beresp_reason(ctx));
}

static mrb_value mrb_vcl_beresp_status(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_fixnum_value( VRT_r_beresp_status(ctx));
}

static mrb_value mrb_vcl_beresp_storage_hint(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_str_new_cstr(mrb, VRT_r_beresp_storage_hint(ctx));
}

static mrb_value mrb_vcl_beresp_ttl(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_fixnum_value(VRT_r_beresp_ttl(ctx));
}

static mrb_value mrb_vcl_beresp_was_304(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_fixnum_value( VRT_r_beresp_was_304(ctx));

}

void mrb_define_vcl_beresp_class(mrb_state *mrb)
{
    struct RClass *beresp;
    beresp = mrb_define_class_under_varnish(mrb, "Beresp");

    mrb_define_method(mrb, beresp,  "initialize", mrb_vcl_beresp_init,   MRB_ARGS_NONE());
    mrb_define_method(mrb, beresp,  "backend_ip", mrb_vcl_beresp_backend_ip, MRB_ARGS_NONE());
    mrb_define_method(mrb, beresp,  "backend_port", mrb_vcl_beresp_backend_port, MRB_ARGS_NONE());
    mrb_define_method(mrb, beresp,  "backend_name", mrb_vcl_beresp_backend_name, MRB_ARGS_NONE());
    mrb_define_method(mrb, beresp,  "do_esi", mrb_vcl_beresp_do_esi, MRB_ARGS_NONE());
    mrb_define_method(mrb, beresp,  "do_gunzip", mrb_vcl_beresp_do_gunzip, MRB_ARGS_NONE());
    mrb_define_method(mrb, beresp,  "do_gzip", mrb_vcl_beresp_do_gzip, MRB_ARGS_NONE());
    mrb_define_method(mrb, beresp,  "do_stresam", mrb_vcl_beresp_do_stream, MRB_ARGS_NONE());
    mrb_define_method(mrb, beresp,  "grace", mrb_vcl_beresp_grace, MRB_ARGS_NONE());
    mrb_define_method(mrb, beresp,  "keep", mrb_vcl_beresp_keep, MRB_ARGS_NONE());
    mrb_define_method(mrb, beresp,  "proto", mrb_vcl_beresp_proto, MRB_ARGS_NONE());
    mrb_define_method(mrb, beresp,  "reason",mrb_vcl_beresp_reason, MRB_ARGS_NONE());
    mrb_define_method(mrb, beresp,  "status", mrb_vcl_beresp_status, MRB_ARGS_NONE());
    mrb_define_method(mrb, beresp,  "storage_hint", mrb_vcl_beresp_storage_hint, MRB_ARGS_NONE());
    mrb_define_method(mrb, beresp,  "ttl", mrb_vcl_beresp_ttl, MRB_ARGS_NONE());
    mrb_define_method(mrb, beresp,  "was_304", mrb_vcl_beresp_was_304, MRB_ARGS_NONE());

    return ;
}
