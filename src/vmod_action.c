
static mrb_value mrb_vmod_action_init(mrb_state *mrb, mrb_value self)
{
    return self;
}


static mrb_value mrb_vmod_pass_init(mrb_state *mrb, mrb_value self)
{
    return self;
}
static mrb_value mrb_vmod_miss_init(mrb_state *mrb, mrb_value self)
{
    return self;
}



static mrb_value mrb_vmod_pipe_init(mrb_state *mrb, mrb_value self)
{
    return self;
}

static mrb_value mrb_vmod_lookup_init(mrb_state *mrb, mrb_value self)
{
    return self;
}
void mrb_vmod_action_define(mrb_state *mrb)
{
    struct RClass *varnish, *action, *pass, *lookup, *pipe, *miss;
    varnish     =   mrb_class_get(mrb,"Varnish");

    action      =   mrb_define_class(mrb, "Action",   varnish);

    pass        =   mrb_define_class(mrb, "Pass",      action);
    lookup      =   mrb_define_class(mrb, "Lookup", action);
    pipe        =   mrb_define_class(mrb, "Pipe", action);
    miss        =   mrb_define_class(mrb, "Miss",      action);

    mrb_define_method(mrb, action,  "initialize", mrb_vmod_action_init,     MRB_ARGS_NONE() );
    mrb_define_method(mrb, pipe,    "initialize", mrb_vmod_pipe_init,   MRB_ARGS_NONE() );
    mrb_define_method(mrb, lookup,  "initalize", mrb_vmod_lookup_init,  MRB_ARGS_NONE() );
    mrb_define_method(mrb, pass,     "initialize", mrb_vmod_pass_init,    MRB_ARGS_NONE() );
    mrb_define_method(mrb, miss,     "initialize", mrb_vmod_miss_init,    MRB_ARGS_NONE() );
}
