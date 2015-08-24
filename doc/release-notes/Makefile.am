## Copyright (C) 1996-2015 The Squid Software Foundation and contributors
##
## Squid software is distributed under GPLv2+ license and includes
## contributions from numerous individuals and organizations.
## Please see the COPYING and CONTRIBUTORS files for details.
##

# requires the linuxdoc tools
if ENABLE_RELEASE_DOCS

DOC= release-4

$(DOC).ps: $(DOC).sgml
	linuxdoc -B latex -o ps $(DOC)

#$(DOC).dvi: $(DOC).tex
#	latex $(DOC).tex
#	latex $(DOC).tex
#	latex $(DOC).tex
#

%.txt: %.sgml
	linuxdoc -B txt --filter $<

%.html: %.sgml
	linuxdoc -B html -T 2 --split=0 $<
	perl -i -p -e "s%$@%%" $@
	cp -p $(DOC).html $(top_builddir)/RELEASENOTES.html

%.man: %.sgml
	linuxdoc -B txt -T 2 -m $(DOC)

EXTRA_DIST= $(DOC).html $(top_builddir)/RELEASENOTES.html

CLEANFILES= \
	*.html \
	*.tex *.ps *.dvi *.aux *.log *.toc \
	*.txt *.man \
	$(top_builddir)/RELEASENOTES.html

endif