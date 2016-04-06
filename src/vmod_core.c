#include "vmod_mruby.h"
#include "vmod_core.h"

#include "vmod_backend.h"
#include "vmod_actions.h"
#include "vmod_param.h"


mrb_value mrb_vmod_vcl_VRT_ban_string(mrb_state *mrb, mrb_value self) 
{
    char *str;
    mrb_get_args(mrb, "v",&str); 
    VRT_ban_string((struct vrt_ctx*)mrb->ud, str);
    return mrb_nil_value();
}

mrb_value mrb_vmod_vcl_VRT_purge(mrb_state *mrb, mrb_value self)
{
    mrb_float ttl, grace, keep;
    mrb_get_args(mrb,"", &ttl, &grace, &keep);
    VRT_purge((struct vrt_ctx*)mrb->ud, (double)ttl, (double)grace, (double)keep);

    return mrb_nil_value();
}

mrb_value mrb_vmod_vcl_VRT_count(mrb_state *mrb, mrb_value self)
{
    mrb_int i;
    mrb_get_args(mrb, "i", &i);
    VRT_count((struct vrt_ctx*)mrb->ud, i);
    return mrb_nil_value();
}

mrb_value mrb_vmod_vcl_VRT_synth(mrb_state *mrb, mrb_value self)
{
    mrb_int i;
    char *str;
    mrb_get_args(mrb, "iv", &i, &str);
    VRT_synth((struct vrt_ctx*)mrb->ud, i, str);
    return mrb_nil_value();
}

mrb_value mrb_vmod_vcl_VRT_selecthttp(mrb_state *mrb, mrb_value self)
{
    mrb_value v;
    mrb_get_args(mrb,"o",v);

    switch() {
    }
    return mrb_nil_value();
}

void mrb_vmod_define_core(mrb_state *mrb) 
{
    struct RClass *vcl, *action;

    mrb_define_class(mrb, vcl, "VCL", mrb->object_class);
    MRB_SET_INSTANCE_TT(mrb, MRB_TT_DATA);


}
