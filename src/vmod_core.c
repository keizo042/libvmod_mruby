#include "vmod_mruby.h"
#include "vmod_core.h"

#include "vmod_backend.h"
#include "vmod_actions.h"
#include "vmod_param.h"


void mrb_vmod_define_core(mrb_state *mrb) 
{
    struct RClass *vcl, *action;

    mrb_define_class(mrb, vcl, "VCL", mrb->object_class);
    MRB_SET_INSTANCE_TT(mrb, MRB_TT_DATA);


}
