#ifndef MRB_VMOD_CLASS_H
#define MRB_VMOD_CLASS_H

#include "vmod_mruby.h"


void mrb_vmod_class_define(mrb_state *mrb);
void mrb_vmod_backend_define(mrb_state *mrb);
void mrb_vmod_recv_define(mrb_state *mrb);
void mrb_vmod_action_define(mrb_state *mrb);
void mrb_vmod_fetch_define(mrb_state *mrb);
void mrb_vmod_recv_define(mrb_state *mrb);
void mrb_vmod_deliver_define(mrb_state *mrb);
void mrb_vmod_backend_define(mrb_state *mrb);
void mrb_vmod_conf_define(mrb_state *mrb); 

#endif 
