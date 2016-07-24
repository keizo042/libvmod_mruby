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



static mrb_value mrb_vcl_beresp_http_get(mrb_state *mrb, mrb_value self)
{
    return self;
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

static mrb_value mrb_vcl_bresp_method(mrb_state *mrb, mrb_value self)
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

static mrb_value mrb_vcl_beresp_xid(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    const char *xid = VRT_r_bereq_xid(ctx);
    return mrb_str_new_cstr(mrb, xid);

}

void mrb_define_vcl_bereq_class(mrb_state *mrb)
{
    struct RClass *bereq;
    bereq = mrb_define_class_under_varnish(mrb, "Bereq");
    return ;
}


void mrb_define_vcl_resp_class(mrb_state *mrb)
{
    struct RClass *resp;
    resp = mrb_define_class_under_varnish(mrb, "Resp");
    return ;
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

void mrb_define_vcl_client_class(mrb_state *mrb)
{
    struct RClass *client;
    client = mrb_define_class_under_varnish(mrb, "Client");
    return ;
}

void mrb_vcl_class_define(mrb_state *mrb)
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

}



