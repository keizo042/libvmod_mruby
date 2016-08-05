
mrb_value mrb_vcl_varnish_server_hostname(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_str_new_cstr(mrb, VRT_r_server_hostname(ctx));
}

mrb_value mrb_vcl_varnish_server_identity(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    return mrb_str_new_cstr(mrb, VRT_r_server_identity(ctx));
}

mrb_value mrb_vcl_varnish_server_ip(mrb_state *mrb, mrb_value self)
{
    TMP_VRT_CTX;
    VCL_IP ip = VRT_r_server_ip(ctx);
    return mrb_str_new_cstr(mrb, VRT_IP_string(ctx,ip));
}

void mrb_define_vcl_server_class(mrb_state *mrb)
{
    struct RClass *server;
    server = mrb_define_class_under_varnish(mrb, "Server");
    mrb_define_method(mrb, server, "hostname", mrb_vcl_varnish_server_hostname, MRB_ARGS_NONE());
    mrb_define_method(mrb, server, "identity", mrb_vcl_varnish_server_identity, MRB_ARGS_NONE());
    mrb_define_method(mrb, server, "ip", mrb_vcl_varnish_server_ip, MRB_ARGS_NONE());

}
