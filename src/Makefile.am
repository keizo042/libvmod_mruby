AM_CPPFLAGS = @VMOD_INCLUDES@ -Wall -I$(abs_srcdir)/mruby/include -I$(asb_srcdir)/mruby -lm -lmruby

vmoddir = @VMOD_DIR@
vmod_LTLIBRARIES = libvmod_mruby.la

LIBMRUBY = $(srcdir)/mruby/build/host/lib/libmruby.a

libvmod_mruby_la_SOURCES =	\
	$(LIBMRUBY)		\
	vmod_mruby.h		\
	vmod_mruby.c		\
	vmod_class.h		\
	vmod_class.c		\
	vmod_mruby_http.c	\
	vmod_mruby_http.h	\
	vmod_mruby_client.c	\
	vmod_mruby_client.h	\
	vmod_mruby_server.c	\
	vmod_mruby_server.h	\
	vmod_mruby_req.c	\
	vmod_mruby_req.h	\
	vmod_mruby_resp.c	\
	vmod_mruby_resp.h	\
	vmod_mruby_bereq.c	\
	vmod_mruby_bereq.h	\
	vmod_mruby_beresp.c	\
	vmod_mruby_beresp.h	\
	vmod_mruby_obj.c	\
	vmod_mruby_obj.h	\
	vmod_mruby_acl.c	\
	vmod_mruby_acl.h	\
	vmod_mruby_director.c	\
	vmod_mruby_director.h	\
	vmod_mruby_prob.c	\
	vmod_mruby_prob.h	\
	debug.h			

nodist_libvmod_mruby_la_SOURCES = \
	vcc_if.c \
	vcc_if.h

vmod_mruby.lo: vcc_if.c vcc_if.h

vcc_if.c: vcc_if.h

vcc_if.h: @VMODTOOL@ $(top_srcdir)/src/vmod_mruby.vcc
	@VMODTOOL@ $(top_srcdir)/src/vmod_mruby.vcc

VMOD_TESTS = $(top_srcdir)/src/tests/*.vtc
.PHONY: $(VMOD_TESTS)

$(top_srcdir)/src/tests/*.vtc: libvmod_mruby.la
	@VARNISHTEST@ -Dvarnishd=@VARNISHD@ -Dvmod_topbuild=$(abs_top_builddir) $@

check: $(VMOD_TESTS)

$(srcdir)/vmod_mruby.c: $(srcdir)/mruby
$(srcdir)/vmod_class.c: $(srcdir)/mruby

MRUBY_CONFIG_FILE = $(abs_top_srcdir)/build_config.rb
$(LIBMRUBY): $(srcdir)/mruby $(MRUBY_CONFIG_FILE)
	MRUBY_CONFIG=$(MRUBY_CONFIG_FILE) $(abs_srcdir)/mruby/minirake -C $(abs_srcdir)/mruby all

$(srcdir)/mruby:
	@GIT@ clone --depth 1 git://github.com/mruby/mruby.git

EXTRA_DIST = \
	vmod_mruby.vcc \
	$(VMOD_TESTS)

CLEANFILES = \
	$(builddir)/vcc_if.c \
	$(builddir)/vcc_if.h \
	$(builddir)/vmod_mruby.rst \
	$(builddir)/vmod_mruby.man.rst
