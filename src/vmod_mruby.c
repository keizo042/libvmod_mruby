#include <stdio.h>
#include <stdlib.h>

#include "vrt.h"
#include "cache/cache.h"

#include "vcc_if.h"


#include "mruby.h"
#include "mruby/object.h"
#include "mruby/class.h"
#include "mruby/compile.h"
#include "mruby/numeric.h"
#include "mruby/data.h"
#include "mruby/error.h"
#include "mruby/value.h"
#include "mruby/string.h"

void  mrb_vmod_class_define(mrb_state* mrb);

static  void mrb_vmod_close(void*p)
{
    mrb_close((mrb_state*)p);
}

int
init_function(struct vmod_priv *priv, const struct VCL_conf *conf)
{
    mrb_state *mrb = mrb_open();
    if(!mrb)
    {
        return -1;
    }

    priv->priv = (void*)mrb;
    priv->free = (vmod_priv_free_f*)mrb_vmod_close;
    mrb_vmod_class_define(mrb);
	return (0);
}

VCL_INT vmod_conf_path(struct vrt_ctx *ctx, struct vmod_priv *priv, VCL_STRING path)
{
    mrb_state *mrb= (mrb_state*)priv->priv;
    FILE *fp;
    mrb_value v;

    fp = fopen(path,"r");
    if(fp == NULL)
    {
        return -1;
    }
    v = mrb_load_file(mrb,fp);
    return 0;
}

static mrb_value  mrb_code_exec(mrb_state *mrb, struct vmod_priv *priv, const char *code)
{
    mrb_value ret;
    mrb =mrb_open();
    if(!mrb)
    {
        return mrb_nil_value();
    }
    ret =mrb_load_string(mrb,code);
    mrb_close(mrb);

    return ret;

}

VCL_STRING vmod_exec(const struct vrt_ctx *ctx, struct vmod_priv *priv, VCL_STRING code)
{
    mrb_state *mrb = (mrb_state*)priv->priv;
    mrb_value v = mrb_code_exec(mrb,code);
    if(!mrb_string_p(v))
    {
        return "";
    }

    return mrb_cptr(v);
}
VCL_INT vmod_exec_ret_int(const struct vrt_ctx *ctx, struct vmod_priv *priv, VCL_STRING code)
{
    mrb_state *mrb = (mrb_state*)priv->priv;
    mrb_value v = mrb_code_exec(mrb,code);
    if(!mrb_fixnum_p(v))
    {
        return 0;
    }
    return mrb_fixnum(v);
}
VCL_VOID vmod_exec_void(const struct vrt_ctx *ctx, struct vmod_priv *priv, VCL_STRING code)
{
    mrb_state *mrb = (mrb_state*)priv->priv;
     mrb_code_exec(mrb, code);
    return ;

}
