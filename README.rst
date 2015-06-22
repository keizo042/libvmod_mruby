============
vmod_mruby
============

----------------------
Varnish Mruby Module
----------------------

:Date: 2015-06-17
:Version: 1.0
:Manual section: 3

SYNOPSIS
========

import mruby;

DESCRIPTION
===========

mruby DSL  for VCL

FUNCTIONS
=========


Prototype
        ::

                conf_path(STRING PATH)
Return value
	INT
Description
        ::

                exec(STRING CODE)
Return value
	STRING
Description
execute ruby script in CODE. and retun result by string.
        ::

                exec_integer(STRING CODE)
Return value
	INT
Description
exec, return integer.
        ::

                exec_void(STRING CODE)
Return value
	VOID
Description
    exec ,return void 
Example
        ::

                set resp.http.hello = mruby.exec("'Hello World'");

INSTALLATION
============

The source tree is based on autotools to configure the building, and
does also have the necessary bits in place to do functional unit tests
using the ``varnishtest`` tool.

Building requires the Varnish header files and uses pkg-config to find
the necessary paths.

Usage::

 ./autogen.sh
 ./configure

If you have installed Varnish to a non-standard directory, call
``autogen.sh`` and ``configure`` with ``PKG_CONFIG_PATH`` pointing to
the appropriate path. For mruby, when varnishd configure was called
with ``--prefix=$PREFIX``, use

 PKG_CONFIG_PATH=${PREFIX}/lib/pkgconfig
 export PKG_CONFIG_PATH

Make targets:

* make - builds the vmod.
* make install - installs your vmod.
* make check - runs the unit tests in ``src/tests/*.vtc``
* make distcheck - run check and prepare a tarball of the vmod.

In your VCL you could then use this vmod along the following lines::

        import mruby;

        sub vcl_deliver {
                # This sets resp.http.hello to "Hello, World"
                set resp.http.hello = mruby.exec("'Hello World'");
        }

COMMON PROBLEMS
===============

* configure: error: Need varnish.m4 -- see README.rst

  Check if ``PKG_CONFIG_PATH`` has been set correctly before calling
  ``autogen.sh`` and ``configure``

CONTACT ME
==============

| mail: keizo.bookman@gmail.com 
| twitter @keizo_bookman 
