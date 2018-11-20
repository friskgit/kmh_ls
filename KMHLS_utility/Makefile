# Makefile for faust code compilation.
# 
# This file assumes that your faust code exists in
# a subdirectory at the same hieararchy as this named
# 'src'. It may contain one or several .dsp files.
# These files should be specified below in the variable
# 'input'.
#
# The clean directory looks like this:
#
# ./Makefile
# ./src
#
# and the build process addes the 'bin' and 'doc' directories.
#
# The targets, apart from 'all' are:
#
# * jack
# * app
# * runapp (will run the application)
# * max
# * sc (supercollider)
# * pd
# * mdoc
# * html
# * wasm
# * oct
# * octview (will run octave with the current file)
# * svg 
# * clean_all (will clean all required dirs)
# * clean (will only clean the bin directory)
#
# 30 Juni 2018	Henrik Frisk	mail@henrikfrisk.com

## Specify the sources to build here
srcdir	:= src
src	:= $(wildcard $(addsuffix /*.dsp, $(srcdir)))
webdir	:= webaudio
websrc	:= $(webdir)/$(notdir $(src:.dsp=.html))

## Output directories, dipsosable
bindir	:= bin
docdir	:= doc
cppdir 	:= cpp
scdir	:= $(bindir)/sc
maxdir	:= $(bindir)/max
vstdir	:= $(bindir)/vst
pddir	:= $(bindir)/pd
wasmdir := $(bindir)/wasm

## Targets
jack	:= $(addprefix $(bindir)/, $(notdir $(basename $(src))))
app	:= $(addprefix $(bindir)/, $(notdir $(src:.dsp=.app)))
vst	:= $(addprefix $(vstdir)/, $(notdir $(src:.dsp=.vst)))
mxo	:= $(addprefix $(maxdir)/, $(notdir $(src:.dsp=~.mxo)))
sc	:= $(addprefix $(scdir)/, $(notdir $(src:.dsp=.sc)))
scx	:= $(addprefix $(scdir)/, $(notdir $(src:.dsp=.scx)))
superscx:= $(addprefix $(scdir)/, $(notdir $(src:.dsp=_supernova.scx)))
ambix	:= $(addprefix $(ambixdir)/, $(notdir $(src:.dsp=.config)))
pd	:= $(addprefix $(pddir)/, $(notdir $(src:.dsp=~.pd_darwin)))
html	:= $(addprefix $(docdir)/, $(notdir $(src:.dsp=.html)))
wasm	:= $(addprefix $(wasmdir)/, $(notdir $(src:.dsp=.wasm)))
oct	:= $(addprefix $(bindir)/, $(notdir $(src:.dsp=.m)))
svg	:= $(addprefix $(docdir)/, $(notdir $(src:.dsp=-svg)))
mdoc	:= $(addprefix $(docdir)/, $(notdir $(src:.dsp=-mdoc)))
prgrms	:= $(jack) $(app) $(html) $(mxo) $(sc)

pdinstdir	:= ~/Documents/Pd/externals/ADT
vstinstdir	:= ~/Library/Audio/Plug-Ins/VST/ADT

POLY		:= -nvoices 8
HTTPD		:= -httpd
OSC		:= -osc
MIDI		:= -midi

# Any of the above
FLAGS		:= $(OSC)
FX		:= -effect
NO_PATCH	:= -nppatch

# Any of the above except OSC and HTTPD
PANDOC		:= pandoc
MAX_FLAGS	:= $(POLY)
FAUST2SVG	:= faust2svg #faust2firefox
FAUST2VST	:= faust2vst
FAUST2PD	:= faust2puredata
FAUST2CAQT	:= faust2caqt
FAUST2JACK	:= faust2jack
FAUST2MAX	:= faust2max6
FAUST2SC	:= faust2supercollider -sn -ks -noprefix
FAUST2OCT 	:= $(HOME)/bin/f2o
FAUST2OCTV 	:= faust2octave
FAUST2MDOC	:= f2mdoc

SC_INSTALL	:= ~/Library/Application\ Support/SuperCollider/Extensions
VST_INSTALL	:= $(vstinstdir)
MAX_INSTALL	:= ~/Documents/Max\ 7/Packages
PD_INSTALL	:= $(pdinstdir)
AMBIX_INSTALL	:= $(ambixinstdir)
MAX_HELP	:= help
MAX_EXTERNALS	:= externals
MAX_JSUI	:= jsui
MAX_MISC	:= misc
MAX_README	:= readme.md
MAX_PACKAGE_DIRS:= $(MAX_EXTERNALS) $(MAX_JSUI) $(MAX_MISC)

REQUIRED_DIRS	= $(bindir) $(docdir) $(cppdir) $(scdir) $(maxdir) $(vstdir) $(pddir) $(wasmdir)
MKDIR	       	:= $(shell for d in $(REQUIRED_DIRS); \
			do				\
			[[ -d $$d ]] || mkdir -p $$d; 	\
			done)

.DEFAULT_GOAL	:= all

all : $(app) $(jack) $(vst) $(html) $(mxo) $(sc) $(svg) $(pd)

doc : $(html)

jack : $(jack)

app : $(app)

max : $(mxo)

sc : $(sc)

oct : $(oct)

octview : $(src)
	$(FAUST2OCTV) $<

svg : $(svg)
#	inkview $(svg)

pd : $(pd)

vst : $(vst)

mdoc : $(mdoc)

wasm : $(wasm)

test :
	@echo $(websrc)

$(vstdir)/%.vst : $(srcdir)/%.dsp
	$(FAUST2VST) $(FLAGS) $<
	if [ -d "$@" ]; then rm -rf $@; fi
	@mv $(srcdir)/$(notdir $@) $(dir $@)

$(bindir)/%.app : $(srcdir)/%.dsp
	@echo compiling $<
	$(FAUST2CAQT) $(FLAGS) $<
	@mv $(srcdir)/$(notdir $@) $@

#### Jack
$(bindir)/% : $(srcdir)/%.dsp
	$(FAUST2JACK) $(FLAGS) $<
	@mv $(srcdir)/$(notdir $@) $@

$(maxdir)/%~.mxo : $(srcdir)/%.dsp
	echo $<
	$(FAUST2MAX) $<
	@mv $(srcdir)/$(notdir $@) $@
	@mv $(notdir $(<:.dsp=.maxpat)) $(maxdir)
	@mv ui.js $(maxdir)

$(pddir)/%~.pd_darwin : $(srcdir)/%.dsp
	$(FAUST2PD) $<
	@mv $(srcdir)/$(notdir $@) $@

$(docdir)/%.html : $(docdir)/%.md
	$(PANDOC) $< -f markdown -t html -o $@

$(docdir)/%.md : src/%.dsp
	faust2md $< > $@

$(docdir)/%-mdoc : $(srcdir)/%.dsp
	$(FAUST2MDOC) $<
	@cp -r $(<:.dsp=-mdoc) $@
	@rm -rf $(<:.dsp=-mdoc)

$(bindir)/%.m : $(srcdir)/%.dsp
	$(FAUST2OCT) $<
	@mv $(<:.dsp=.m) $@

$(docdir)/%-svg : $(srcdir)/%.dsp
	$(FAUST2SVG) $<
	@cp -r $(<:.dsp=-svg) $@
	@rm -rf $(<:.dsp=-svg)

$(scdir)/%.sc : $(srcdir)/%.dsp
	export SUPERCOLLIDER_HEADERS=~/bin/supercollider/include/; \
	$(FAUST2SC) $<
	@mv $(basename $<).sc $@
	@mv $(basename $<).scx $(scdir)
	@mv $(basename $<)_supernova.scx $(scdir)
	@mv $(basename $<).cpp $(cppdir)

$(wasmdir)/%.wasm : $(srcdir)/%.dsp 
	$(FAUST2WASM) $<
	@mv $(notdir $(basename $<).wasm) $(wasmdir)
	@mv $(notdir $(basename $<).js) $(wasmdir)
	@mv main.json $(wasmdir)
	@cp $(websrc) $(wasmdir)

setup :
	@echo ----------------------------
	@echo Creating default directories
	@echo Done

.PHONY: install

.PHONY : maxinstall maxdirs tester maxbin maxjsui maxreadme maxhelp

maxinstall : max maxbin maxjsui maxreadme maxhelp
	@echo "Max package installed in $(MAX_INSTALL)"
	@echo ""

maxreadme : doc
	@echo "Installing max/msp doc files in $(MAX_INSTALL)"
	@echo ""
	$(eval maxdoc=$(wildcard $(docdir)/*.md))
	$(foreach var, $(maxdoc), $(shell cp $(var) $(MAX_INSTALL)/$(notdir $(var:.md=))/$(notdir $(var))))

maxhelp : maxhelpdir
	@echo "Installing max/msp help files in $(MAX_INSTALL)/help"
	@echo ""
	$(eval maxpat=$(wildcard $(maxdir)/*.maxpat)) \
	$(foreach var, $(maxpat), $(shell cp $(var) $(MAX_INSTALL)/$(notdir $(var:.maxpat=))/$(MAX_HELP)/$(notdir $(var:.maxpat=~.maxhelp))))

maxhelpdir :
	$(eval maxpat=$(wildcard $(maxdir)/*.maxpat)) \
	$(foreach var, $(mxo), $(shell mkdir -p $(MAX_INSTALL)/$(notdir $(var:~.mxo=))/$(MAX_HELP)))

maxjsui : maxbin
	@echo "Installing max/msp javascript ui files in $(MAX_INSTALL)/jsui"
	@echo ""
	$(foreach var, $(mxo), $(shell mkdir -p $(MAX_INSTALL)/$(notdir $(var:~.mxo=))/$(MAX_JSUI)))
	$(foreach var, $(mxo), $(shell cp $(maxdir)/ui.js $(MAX_INSTALL)/$(notdir $(var:~.mxo=))/$(MAX_JSUI)))

maxbin : maxbindir
	@echo "Installing max/msp binaries in $(MAX_INSTALL)/externals"
	@echo ""
	$(foreach var, $(mxo), $(shell cp -r $(var) $(MAX_INSTALL)/$(notdir $(var:~.mxo=))/$(MAX_EXTERNALS)))

maxbindir :
	$(foreach var, $(mxo), $(shell mkdir -p $(MAX_INSTALL)/$(notdir $(var:~.mxo=))/$(MAX_EXTERNALS)))

maxdirs : # maxinstall
	 $(foreach var, $(mxo), $(if [[ ! -d $(MAX_INSTALL)/$(notdir $(var:~.mxo=))/$(mvar)]], $(foreach mvar, $(MAX_PACKAGE_DIRS), @mkdir $(MAX_INSTALL)/$(notdir $(var:~.mxo=))/$(mvar)), "Directory exists"));

scinstall : ##$(SC) $(SCX) $(SSCX)
	@echo "Installing SuperCollider extensions  in $(SC_INSTALL)"
	@echo "$(sc)"
	$(foreach var, $(sc), $(shell cp $(var) $(SC_INSTALL)))
	$(foreach var, $(scx), $(shell cp $(var) $(SC_INSTALL)))
	$(foreach var, $(superscx), $(shell cp $(var) $(SC_INSTALL)))

pdinstall : $(pd)
	@echo "Installing PureData extension in $(PD_INSTALL)"
	@echo ""
	$(foreach var, $(pd), $(shell install $(var) $(PD_INSTALL)))

## The install target did not work as expected, hence this solution for  the VSTs.
vstinstall : $(vst)
	@echo ""
	@echo "Installing VST plug-ins in $(VST_INSTALL)"
	@echo ""
	$(foreach var, $(vst), $(shell cp -R $(var) $(VST_INSTALL)))

clean_all :
	@rm  -rf $(REQUIRED_DIRS)

clean :
	@rm -rf $(bindir)/*

binclean :
	@rm -rf $(bindir)/*

.PHONY: all test clean doc runapp viewsvg oct octview sc max binclean mdoc setup wasm
.SUFFIXES: .app .dsp .html .md
