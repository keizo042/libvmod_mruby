#ifndef VMOD_MRUBY_CLASS_H
#define VMOD_MRUBY_CLASS_H
#include "mruby.h"

#define TMP_VRT_CTX  const struct vrt_ctx *ctx = (struct vrt_ctx*)mrb->ud;

void mrb_define_vcl_class(mrb_state *mrb);
#endif
