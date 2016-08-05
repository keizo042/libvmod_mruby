#include "vmod_mruby.h"
#include "vmod_class.h"
#include "vmod_mruby_client.h"

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

void mrb_define_vcl_client_class(mrb_state *mrb)
{
    struct RClass *client;
    client = mrb_define_class_under_varnish(mrb, "Client");

    mrb_define_method(mrb, client, "identity", mrb_vcl_client_identity, MRB_ARGS_NONE());
    mrb_define_method(mrb, client, "ip", mrb_vcl_client_ip, MRB_ARGS_NONE());
    mrb_define_method(mrb, client, "port", mrb_vcl_client_port, MRB_ARGS_NONE());
    return ;
}
