#include "vmod_mruby.h"

#include "pthread.h"


typedef struct mrb_vmod_ctx_t {
    mrb_state *mrb;
}mrb_vmod_ctx_t;

static  void mrb_vmod_close(void *p)
{
    mrb_close((mrb_state*)p);
}

int
init_function(struct vmod_priv *priv, const struct VCL_conf *conf)
{
    mrb_state *mrb = NULL;
    if(priv->priv == NULL)
    {
        mrb = mrb_open();
        if(!mrb)
        {
            return -1;
        }
    }

    priv->free = (vmod_priv_free_f*)mrb_vmod_close;

	return (0);
}


VCL_INT vmod_init(VRT_CTX, struct vmod_priv *priv, VCL_STRING path)
{
    CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);

    return 0;
}


VCL_STRING vmod_exec_str(VRT_CTX, struct vmod_priv *priv, VCL_STRING code)
{
    CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);

    mrb_state *mrb = mrb_open();
    mrb_value v = mrb_load_string(mrb,code); 
    if(!mrb_string_p(v))
    {
        v = mrb_obj_as_string(mrb,v);
    }

    mrb_close(mrb);
    return RSTRING_PTR(v);
}

VCL_INT vmod_exec_int(VRT_CTX, struct vmod_priv *priv, VCL_STRING code)
{
    CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);

    mrb_state *mrb = mrb_open();
    mrb_value v = mrb_load_string(mrb, code);
    if(!mrb_fixnum_p(v))
    {
        return 0;
    }
    mrb_close(mrb);
    return mrb_fixnum(v);
}

VCL_VOID vmod_exec(VRT_CTX, struct vmod_priv *priv, VCL_STRING code)
{
    CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);

    mrb_state *mrb = mrb_open();
    mrb_load_string(mrb,code);
    mrb_close(mrb);
    return ;

}
