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


#include "mruby.h"


void vmod_conf_define(struct mrb_state *mrb)
{
    struct RClass *varnish, *conf;

    varnish = mrb_class_get(mrb, "Varnish");
    conf = mrb_define_class(mrb,  "Varnish", varnish);

    mrb_define_const(mrb, conf, "TEST", mrb_nil_value());
}
/*
 * It is  options when varnishd start
acceptor_sleep_decay       
acceptor_sleep_incr       
acceptor_sleep_max       
auto_restart            
ban_dups               
ban_lurker_age        
ban_lurker_batch     
ban_lurker_sleep    
between_bytes_timeout
busyobj_worker_cache
cc_command         
cli_buffer        
cli_limit        
cli_timeout     
clock_skew     
connect_timeout
critbit_cooloff         
debug                  
default_grace         
default_keep         
default_ttl         
feature            
fetch_chunksize   
fetch_maxchunksize        
first_byte_timeout       
group                   
group_cc               
gzip_buffer           
gzip_level           
gzip_memlevel       
http_gzip_support  
http_max_hdr      
http_range_support  
http_req_hdr_len   
http_req_size     
http_resp_hdr_len
http_resp_size  
idle_send_timeout
listen_address  
listen_depth   
lru_interval  
max_esi_depth
max_restarts  
max_retries  
nuke_limit  
pcre_match_limit           
pcre_match_limit_recursion
ping_interval            
pipe_timeout            
pool_req               
pool_sess             
pool_vbc             
pool_vbo            
prefer_ipv6        
rush_exponent     
send_timeout     
session_max     
shm_reclen     
shortlived    
sigsegv_handler            
syslog_cli_traffic        
tcp_keepalive_intvl      
tcp_keepalive_probes    
tcp_keepalive_time     
thread_pool_add_delay 
thread_pool_destroy_delay  
thread_pool_fail_delay    
thread_pool_max          
thread_pool_min         
thread_pool_stack      
thread_pool_timeout   
thread_pools         
thread_queue_limit  
thread_stats_rate  
timeout_idle      
timeout_linger          
timeout_req            
user                  
vcc_allow_inline_c   
vcc_err_unref       
vcc_unsafe_path    
vcl_dir           
vmod_dir         
vsl_buffer      
vsl_mask       
vsl_reclen    
vsl_space    
vsm_space   
waiter     
workspace_backend          
workspace_client          
workspace_session        
workspace_thread   
*/
