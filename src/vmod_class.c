#include "vmod_class.h"

/*
 *
 *  initalize functions
 *
 */

static mrb_value mrb_vmod_init(mrb_state *mrb, mrb_value self)
{

    return self;
}

static mrb_value mrb_vmod_probe_init(mrb_state *mrb, mrb_value self)
{

    return self;
}

/*
 *
 * Class and Module define.
 *
 */

void mrb_vmod_probe_define(mrb_state *mrb)
{
    struct RClass *varnish, *probe;
    varnish= mrb_class_get(mrb,"Varnish");
    probe        = mrb_define_class(mrb, "Probe",     varnish);

    mrb_define_method(mrb, probe,    "initialize", mrb_vmod_probe_init,   MRB_ARGS_NONE() );
}


void mrb_vmod_class_define(mrb_state *mrb)
{
    struct RClass *varnish;

    varnish = mrb_define_class(mrb, "Varnish", mrb->object_class);
    MRB_SET_INSTANCE_TT(varnish, MRB_TT_DATA);

    mrb_define_method(mrb, varnish, "initialize", mrb_vmod_init,            MRB_ARGS_NONE() );
    mrb_define_method(mrb, varnish, "return", NULL,            MRB_ARGS_NONE() );

    mrb_vmod_action_define(mrb);
    mrb_vmod_fetch_define(mrb);
    mrb_vmod_recv_define(mrb);
    mrb_vmod_deliver_define(mrb);
    mrb_vmod_backend_define(mrb);
    mrb_vmod_conf_define(mrb); // from vmod_conf.c
    mrb_vmod_varnish_define(mrb);

}
