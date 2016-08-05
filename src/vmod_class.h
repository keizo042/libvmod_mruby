#ifndef VMOD_MRUBY_CLASS_H
#define VMOD_MRUBY_CLASS_H
#include "mruby.h"
#include "vrt_obj.h"
#include "vsa.h"
#include <pthread.h>

#define TMP_VRT_CTX  const struct vrt_ctx *ctx = (struct vrt_ctx*)mrb->ud;

void mrb_define_vcl_class(mrb_state *mrb);

typedef struct mrb_vcl_internal_state{
    unsigned state;
}mrb_vcl_internal_state;

inline struct RClass* mrb_define_class_under_varnish(mrb_state *mrb, char *name)
{
    struct RClass *varnish, *child;
    varnish = mrb_class_get(mrb, "Varnish"); 
    child =  mrb_define_class_under(mrb, varnish, name, mrb->object_class);
    MRB_SET_INSTANCE_TT(child, MRB_TT_DATA);
    return child;
}

#endif
