#include "vmod_mruby.h"

#include "pthread.h"

static void make_key();

typedef struct mrb_vmod_ctx_t {
    mrb_state *mrb;
}mrb_vmod_ctx_t;

static mrb_vmod_ctx_t* mrb_vmod_ctx_new()
{
    mrb_vmod_ctx_t *ctx = malloc( sizeof(mrb_vmod_ctx_t) );
    ctx->mrb = mrb_open();
    return ctx;
}

static void mrb_vmod_ctx_close(void *p)
{
    mrb_vmod_ctx_t *ctx = (mrb_vmod_ctx_t*)p;
    mrb_close(ctx->mrb);
    free(ctx);
}



typedef void (*thread_desruct_t)(void*);

static pthread_once_t th_once = PTHREAD_ONCE_INIT;

static pthread_key_t th_key ;


mrb_vmod_ctx_t *get_vmod_ctx()
{
    mrb_vmod_ctx_t *ctx =(mrb_vmod_ctx_t*)pthread_getspecific(th_key);
    if(!ctx)
    {
        mrb_vmod_ctx_t *ctx = mrb_vmod_ctx_new();
        pthread_setspecific(th_key, (void*)ctx);
    }
    return ctx;
}

int
init_function(struct vmod_priv *priv, const struct VCL_conf *conf)
{

    pthread_once(&th_once, make_key);

	return (0);
}

static void make_key()
{
    pthread_key_create(&th_key, (thread_desruct_t)mrb_vmod_ctx_close);
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


VCL_INT vmod_init(VRT_CTX, struct vmod_priv *priv, VCL_STRING path)
{
    CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
    mrb_vmod_ctx_t *mrb = mrb_vmod_ctx_new();
    if(priv->priv)
    {
        mrb_vmod_ctx_close((mrb_vmod_ctx_t*)priv->priv);
        return -1;
    }
    priv->priv = (void*)mrb;

    return 0;
}

VCL_INT vmod_done(VRT_CTX, struct vmod_priv *priv)
{
    if(priv->priv)
    {
        mrb_vmod_ctx_close(priv->priv);
    }
    return 0;
}
