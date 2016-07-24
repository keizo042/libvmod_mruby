#include "vmod_mruby.h"

#include <pthread.h>

inline struct RClass* mrb_define_class_under_varnish(mrb_state *mrb, char *name)
{
    struct RClass *varnish, *child;
    varnish = mrb_class_get(mrb, "Varnish"); 
    child =  mrb_define_class_under(mrb, varnish, name, mrb->object_class);
    MRB_SET_INSTANCE_TT(child, MRB_TT_DATA);
    return child;
}



mrb_value mrb_vcl_var(mrb_state *mrb, mrb_value self)
{
    return self;
}

mrb_value mrb_vcl_beresp_init(mrb_state *mrb, mrb_value self)
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

void mrb_vcl_req_class_define(mrb_state *mrb)
{
    struct RClass *req;
    req = mrb_define_class_under_varnish(mrb, "Req");
    return ;
}

void mrb_vcl_server_class_define(mrb_state *mrb)
{
    struct RClass *server;
    server = mrb_define_class_under_varnish(mrb, "Server");
}

void mrb_vcl_client_class_define(mrb_state *mrb)
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

}



