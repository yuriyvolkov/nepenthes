# nepenthes module Makefile
# Paul Baecher, Maximillian Dornseif, Markus Koetter
# $Id: Makefile.am 718 2006-12-28 23:29:59Z common $

AUTOMAKE_OPTIONS = foreign

AM_CPPFLAGS = -I$(top_srcdir)/nepenthes-core/include -I$(top_srcdir)/nepenthes-core/src -pipe -D _GNU_SOURCE -I/usr/include/libipq
AM_CXXFLAGS = -Wall -Werror
AM_LDFLAGS = ${LIB_PCAP} ${LIB_IPQ} 

pkglib_LTLIBRARIES = modulehoneytrap.la

modulehoneytrap_la_SOURCES = module-honeytrap.cpp module-honeytrap.hpp 
modulehoneytrap_la_SOURCES += PCAPSocket.cpp PCAPSocket.hpp
modulehoneytrap_la_SOURCES += TrapSocket.cpp TrapSocket.hpp
modulehoneytrap_la_SOURCES += module-honeytrap.conf.dist

modulehoneytrap_la_LDFLAGS = -module -no-undefined -avoid-version $(AM_LDFLAGS)
