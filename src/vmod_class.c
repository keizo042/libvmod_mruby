#include "vmod_mruby.h"

#include <pthread.h>

#define DEFINE_CLASS_UNDER_VARNISH(mrb, class_name, class_var, parent_var, AGRS)  \
    while(0){   \
        (parent_var) = mrb_class_get(mrb, "Varnish"); \
        (class_var) = mrb_define_class_under(mrb, (parent), (class_name), (ARGS))  \
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
    struct RClass *beresp, *varnish;

    mrb_define_method(mrb, beresp, mrb_vcl_beresp_init,  "initialize", MRB_AGS_NONE());
    return ;
}

void mrb_define_vcl_bereq_class(mrb_state *mrb)
{
    struct RClass *bereq, *varnish;
    return ;
}

void mrb_define_vcl_resp_class(mrb_state *mrb)
{
    struct RClass *resp, *varnish;
    return ;
}

void mrb_vcl_req_class_define(mrb_state *mrb)
{
    struct RClass *req, *varnish;
    return ;
}

void mrb_vcl_server_class_define(mrb_state *mrb)
{
    struct RClass *server, *varnish;
}

void mrb_vcl_client_class_define(mrb_state *mrb)
{
    struct RClass *client, *varnish;
    return ;
}

void mrb_vcl_class_define(mrb_state *mrb)
{
    struct RClass *varnish = mrb_class_define(mrb, "Varnish", mrb->obj_class);
    MRB_SET_INSTANCE_TT(mrb, MRB_TT_DATA);


    mrb_define_class_method(mrb, varnish, mrb_vcl_var,  "var",  MRB_AGS_REQ(1));

}



