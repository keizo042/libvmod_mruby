#include "vmod_mruby.h"
#include "vrt_obj.h"

#include <pthread.h>

#define TMP_VRT_CTX  const struct vrt_ctx *ctx = (struct vrt_ctx*)mrb->ud;

static inline struct RClass* mrb_define_class_under_varnish(mrb_state *mrb, char *name)
{
    struct RClass *varnish, *child;
    varnish = mrb_class_get(mrb, "Varnish"); 
    child =  mrb_define_class_under(mrb, varnish, name, mrb->object_class);
    MRB_SET_INSTANCE_TT(child, MRB_TT_DATA);
    return child;
}



static mrb_value mrb_vcl_var(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vcl_beresp_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vcl_beresp_backend_ip(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vcl_beresp_backend_name(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;

    return mrb_str_new_cstr(mrb, VRT_r_beresp_name(ctx));
}

static mrb_value mrb_vcl_beresp_backend_port(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_fixnum_value( VRT_r_beresp_ip(ctx));
}

static mrb_value mrb_vcl_beresp_do_esi(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_fixnum_value( VRT_r_beresp_do_esi(ctx));
}

static mrb_value mrb_vcl_beresp_do_gunzip(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_fixnum_value( VRT_r_bresp_do_gunzip(ctx));
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

static mrb_value mrb_vcl_beresp_response(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_str_new_cstr(mrb, VRT_r_beresp_response(ctx));
}

static mrb_value mrb_vcl_beresp_status(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_fixnum_value( VRT_r_beresp_status(ctx));
}

static mrb_value mrb_vcl_beresp_storage(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_str_new_cstr(mrb, VRT_r_beresp_storage(ctx));
}

static mrb_value mrb_vcl_beresp_ttl(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_fixnum_value(mrb, VRT_r_bresp_ttl(ctx));
}

void mrb_define_vcl_beresp_class(mrb_state *mrb)
{
    struct RClass *beresp;
    beresp = mrb_define_class_under_varnish(mrb, "Beresp");

    mrb_define_method(mrb, beresp, "initialize", mrb_vcl_beresp_init,   MRB_ARGS_NONE());
    return ;
}


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
    return mrb_fixnum_value(val);
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

static mrb_value mrb_vcl_bereq_http_get(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return self;
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
    // maybe, http_get is hard to impl.
    // mrb_define_method(mrb, bereq, "http_get",               mrb_vcl_bereq_http_get,                 MRB_ARGS_NONE());

    return ;

}

static mrb_value  mrb_vcl_resp_proto(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_str_new_cstr(mrb, VRT_r_resp_proto(ctx));
}

static mrb_value mrb_vcl_resp_response(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_str_new_cstr(mrb, VRT_r_resp_response(ctx));
}

static mrb_value mrb_vcl_resp_status(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_float( VRT_r_resp_status(ctx) );
}

void mrb_define_vcl_resp_class(mrb_state *mrb)
{
    struct RClass *resp;
    resp = mrb_define_class_under_varnish(mrb, "Resp");
    return ;
}

static mrb_vcl_req_backend_healthy(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_float( VRT_r_req_backend_healthy(ctx));
}

static mrb_value mrb_vcl_req_backend_name(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_str_new_cstr(mrb, VRT_backend_name(ctx, VRT_r_req_backend(ctx)));
}

static mrb_value mrb_vcl_req_can_gzip(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_float( VRT_r_req_can_gzip(ctx));
}

static mrb_value mrb_vcl_req_esi(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_float( VRT_r_req_esi(ctx));
}

static mrb_value mrb_vcl_req_esi_level(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_float( VRT_r_req_esi_level(ctx));
}

static mrb_value mrb_vcl_req_grace(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_fixnum_value(mrb, VRT_r_req_grace(ctx));
}

static mrb_value mrb_vcl_req_hash_always_miss(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_float( VRT_r_req_hash_alwas_miss(ctx));
}

static mrb_value mrb_vcl_req_hash_ignore_busy(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_float( VRT_r_req_hash_ignoer_busy(ctx));
}

static mrb_value mrb_vcl_req_keep(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_fixnum_value(mrb, VRT_r_req_keep(ctx));
}

static mrb_value mrb_vcl_req_proto(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_str_new_cstr(mrb, VRT_r_req_proto(ctx));
}

static mrb_value mrb_vcl_req_request(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_str_new_cstr(mrb, VRT_r_req_request(ctx));
}

void mrb_define_vcl_req_class(mrb_state *mrb)
{
    struct RClass *req;
    req = mrb_define_class_under_varnish(mrb, "Req");
    return ;
}

void mrb_define_vcl_server_class(mrb_state *mrb)
{
    struct RClass *server;
    server = mrb_define_class_under_varnish(mrb, "Server");
}

static mrb_value mrb_vcl_client_identity(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vcl_client_ip(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vcl_client_port(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vcl_obj_grace(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vcl_obj_hits(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vcl_obj_keep(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vcl_obj_lastuse(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vcl_obj_proto(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vcl_obj_response(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vcl_obj_ttl(mrb_state *mrb, mrb_value self)
{
    return self;
}

void mrb_define_vcl_client_class(mrb_state *mrb)
{
    struct RClass *client;
    client = mrb_define_class_under_varnish(mrb, "Client");
    return ;
}

void mrb_define_vcl_obj_class(mrb_state *mrb)
{
    struct RClass *obj;
    obj = mrb_define_class_under_varnish(mrb, "Obj");
}

void mrb_define_vcl_class(mrb_state *mrb)
{
    struct RClass *varnish = mrb_define_class(mrb, "Varnish", mrb->object_class);
    MRB_SET_INSTANCE_TT(mrb, MRB_TT_DATA);


    mrb_define_class_method(mrb, varnish, "var", mrb_vcl_var,    MRB_ARGS_REQ(1));

    mrb_define_vcl_beresp_class(mrb);
    mrb_define_vcl_bereq_class(mrb);
    mrb_define_vcl_resp_class(mrb);
    mrb_define_vcl_req_class(mrb);
    mrb_define_vcl_server_class(mrb);
    mrb_define_vcl_client_class(mrb);
    mrb_define_vcl_obj_class(mrb);

}



