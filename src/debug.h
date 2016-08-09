#ifndef VMOD_MRUBY_DEBUG_H
#define VMOD_MRUBY_DEBUG_H

#define LOG_WARN(msg)  fprintf(stdout, "file:%s, lien:%d, %s", __FILE__, __LINE__, msg)
#define LOG_DEBUG(msg) fprintf(stderr, "file:%s, line:%d, %s", __FILE__, __LINE__, msg)

#endif
