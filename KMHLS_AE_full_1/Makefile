# Makefile for faust code compilation.
# 
# This file assumes that your faust code exists in
# a subdirectory at the same hieararchy as this named
# 'src'. It may contan one or several .dsp files.
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
# * max  (made a test with faust2msp for max 8 compatibility 30/10 2019)
# * sc (supercollider)
# * pd
# * mdoc
# * html
# * oct
# * octview (will run octave with the current file)
# * svg 
# * clean_all (will clean all required dirs)
# * clean (will only clean the bin directory)
#
# maxinstall, scinstall, vstinstall etc attempts to install in default positions, the exact
# location can be specified below under respective argument (see Install directories)
# 
# 30 Juni 2018	Henrik Frisk	mail@henrikfrisk.com

## Platform specific

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	SYSTEM =+ Linux
	SUPERNOVA_EXT = so
	SC_INSTALL := ~/.local/share/SuperCollider/Extensions/MyExtensions
endif
ifeq ($(UNAME), Darwin)
	SYSTEM =+ OSX
	SUPERNOVA_EXT = scx
	SC_INSTALL := ~/Library/Application\ Support/SuperCollider/Extensions/ADT
endif

## Specify the sources to build here
srcdir	:= src
src	:= $(wildcard $(addsuffix /*.dsp, $(srcdir)))

## Output directories, dipsosable
bindir	:= bin
docdir	:= doc
cppdir 	:= cpp
scdir	:= $(bindir)/sc
maxdir	:= $(bindir)/max
vstdir	:= $(bindir)/vst
pddir	:= $(bindir)/pd
ambixdir:= ambix

## Install directories
pdinstdir	:= ~/Documents/Pd/externals/ADT
vstinstdir	:= ~/Library/Audio/Plug-Ins/VST/ADT
ambixinstdir	:= ~/Library/ambix/binaural_presets
maxinstall	:= ~/Documents/Max\ 7/Packages
maxpackage	:= $(maxdir)

## Variables
amb108		:= kmh_108
amb114		:= kmh_114
ambls		:= kmh_ls

## Targets
jack	:= $(addprefix $(bindir)/, $(notdir $(basename $(src))))
app	:= $(addprefix $(bindir)/, $(notdir $(src:.dsp=.app)))
vst	:= $(addprefix $(vstdir)/, $(notdir $(src:.dsp=.vst)))
mxo	:= $(addprefix $(maxdir)/, $(notdir $(src:.dsp=~.mxo)))
scx	:= $(addprefix $(scdir)/, $(notdir $(src:.dsp=.$(SUPERNOVA_EXT))))
superscx:= $(addprefix $(scdir)/, $(notdir $(src:.dsp=_supernova.$(SUPERNOVA_EXT))))
sc	:= $(addprefix $(scdir)/, $(notdir $(src:.dsp=.sc)))
ambix	:= $(addprefix $(ambixdir)/, $(notdir $(src:.dsp=.config)))
pd	:= $(addprefix $(pddir)/, $(notdir $(src:.dsp=~.pd_darwin)))
html	:= $(addprefix $(docdir)/, $(notdir $(src:.dsp=.html)))
oct	:= $(addprefix $(bindir)/, $(notdir $(src:.dsp=.m)))
svg	:= $(addprefix $(docdir)/, $(notdir $(src:.dsp=-svg)))
mdoc	:= $(addprefix $(docdir)/, $(notdir $(src:.dsp=-mdoc)))
prgrms	:= $(jack) $(app) $(html) $(mxo) $(sc)

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

## Create the relevant directories for compiling and installing.
REQUIRED_DIRS	= $(bindir) $(docdir) $(cppdir) $(scdir) $(maxdir) $(vstdir) $(pddir) $(pdinstdir) $(vstinstdir) $(ambixinstdir)/$(amb108) $(ambixinstdir)/$(amb114) $(ambixinstdir)/$(ambls)
MKDIR	       	:= $(shell for d in $(REQUIRED_DIRS); \
			do				\
			[ -d $$d ] || mkdir -p $$d; 	\
			done)

LOC108		:= KMH108
LOC114		:= KMH114
LOCLS		:= KMHLS

# SC_INSTALL see above
VST_INSTALL	:= $(vstinstdir)
MAX_OBJECTS	:= $(maxpackage)
MAX_INSTALL	:= $(maxinstall)
PD_INSTALL	:= $(pdinstdir)
AMBIX_INSTALL	:= $(ambixinstdir)
MAX_HELP	:= help
MAX_EXTERNALS	:= externals
MAX_JSUI	:= jsui
MAX_MISC	:= misc
MAX_README	:= readme.md
MAX_PACKAGE_DIRS:= $(MAX_EXTERNALS) $(MAX_JSUI) $(MAX_MISC)
VST		:= $(addprefix $(VST_INSTALL)/, $(notdir $(src:.dsp=.vst)))
PD		:= $(addprefix $(PD_INSTALL)/, $(notdir $(src:.dsp=~.pd_darwin)))
SC		:= $(addprefix $(SC_INSTALL)/, $(notdir $(src:.dsp=.sc)))
SCX		:= $(addprefix $(SC_INSTALL)/, $(notdir $(src:.dsp=.scx)))
SSCX		:= $(addprefix $(SC_INSTALL)/, $(notdir $(src:.dsp=_supernova.scx)))

.DEFAULT_GOAL	:= all

.PRECIOUS : $(docdir)/%.md

all : $(app) $(jack) $(vst) $(html) $(mxo) $(sc) $(svg) $(pd)

install : scinstall maxpackage pdinstall vstinstall ambixinstall

doc : $(html)

jack : $(jack)

app : $(app)

max : $(mxo)

sc : $(sc)

oct : $(oct)

octview : $(src)
	$(FAUST2OCTV) $<

svg : $(svg)
	inkview $(svg)

pd : $(pd)

vst : $(vst)

mdoc : $(mdoc)

$(vstdir)/%.vst : $(srcdir)/%.dsp
	$(FAUST2VST) $(FLAGS) $<
	@mv $(srcdir)/$(notdir $@) $@

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
ifeq ($(SYSTEM), OSX)
	export SUPERCOLLIDER_HEADERS=~/bin/supercollider/include/;
endif
	$(FAUST2SC) $<
	@mv $(basename $<).sc $@
	@mv $(basename $<).$(SUPERNOVA_EXT) $(scdir)
	@mv $(basename $<)_supernova.$(SUPERNOVA_EXT) $(scdir)
	@mv $(basename $<).cpp $(cppdir)

.PHONY : maxpackage maxdirs tester maxbin maxjsui maxreadme maxhelp maxzip

maxzip : 
	@echo $(maxdir)
	$(eval maxobj=$(wildcard $(maxdir)/*))	
	$(foreach var, $(maxobj), @zip -r $(var).zip $(var))

maxpackage : max maxbin maxjsui maxreadme maxhelp
	rm $(maxdir)/*.maxpat && rm -rf $(maxdir)/*.mxo && rm $(maxdir)/*.js
	@echo "Max package installed in $(MAX_OBJECTS)"
	@echo ""

maxinstall : #maxpackage
	@echo "Installing Max objects in $(MAX_INSTALL)"
	@echo ""
	$(eval maxobj=$(wildcard $(maxdir)/*))	
	$(foreach var, $(maxobj), $(shell cp -R $(var) $(MAX_INSTALL)))

maxreadme : doc
	@echo "Installing max/msp doc files in $(MAX_OBJECTS)"
	@echo ""
	$(eval maxdoc=$(wildcard $(docdir)/*.md))
	$(foreach var, $(maxdoc), $(shell cp $(var) $(MAX_OBJECTS)/$(notdir $(var:.md=))/$(notdir $(var))))

maxhelp : maxhelpdir
	@echo "Installing max/msp help files in $(MAX_OBJECTS)/help"
	@echo ""
	$(eval maxpat=$(wildcard $(maxdir)/*.maxpat)) \
	$(foreach var, $(maxpat), $(shell cp $(var) $(MAX_OBJECTS)/$(notdir $(var:.maxpat=))/$(MAX_HELP)/$(notdir $(var:.maxpat=~.maxhelp))))

maxhelpdir :
	$(eval maxpat=$(wildcard $(maxdir)/*.maxpat)) \
	$(foreach var, $(mxo), $(shell mkdir -p $(MAX_OBJECTS)/$(notdir $(var:~.mxo=))/$(MAX_HELP)))

maxjsui : maxbin
	@echo "Installing max/msp javascript ui files in $(MAX_OBJECTS)/jsui"
	@echo ""
	$(foreach var, $(mxo), $(shell mkdir -p $(MAX_OBJECTS)/$(notdir $(var:~.mxo=))/$(MAX_JSUI)))
	$(foreach var, $(mxo), $(shell cp $(maxdir)/ui.js $(MAX_OBJECTS)/$(notdir $(var:~.mxo=))/$(MAX_JSUI)))

maxbin : maxbindir
	@echo "Installing max/msp binaries in $(MAX_OBJECTS)/externals"
	@echo ""
	$(foreach var, $(mxo), $(shell cp -r $(var) $(MAX_OBJECTS)/$(notdir $(var:~.mxo=))/$(MAX_EXTERNALS)))

maxbindir :
	$(foreach var, $(mxo), $(shell mkdir -p $(MAX_OBJECTS)/$(notdir $(var:~.mxo=))/$(MAX_EXTERNALS)))

maxdirs : # maxpackage
	 $(foreach var, $(mxo), $(if [[ ! -d $(MAX_OBJECTS)/$(notdir $(var:~.mxo=))/$(mvar)]], $(foreach mvar, $(MAX_PACKAGE_DIRS), @mkdir $(MAX_OBJECTS)/$(notdir $(var:~.mxo=))/$(mvar)), "Directory exists"));

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

# $(VST_INSTALL)/%.vst : $(vst)
# 	@cp -R $< $(dir $@)

ambixinstall :
	$(if $(ambix), $(if $(wildcard $(srcdir)/$(LOC108)*.dsp), install $(wildcard $(ambixdir)/*.config) $(AMBIX_INSTALL)/$(amb108))) \
	$(if $(ambix), $(if $(wildcard $(srcdir)/$(LOC114)*.dsp), install $(wildcard $(ambixdir)/*.config) $(AMBIX_INSTALL)/$(amb114))) \
	$(if $(ambix), $(if $(wildcard $(srcdir)/$(LOCLS)*.dsp), install $(wildcard $(ambixdir)/*.config) $(AMBIX_INSTALL)/$(ambls)))

update_author :
	$(foreach var, $(src), $(shell sed -i.bu 's/AmbisonicDecoderToolkit"/AmbisonicDecoderToolkit, Henrik Frisk"/' $(var)))

clean_max :
	  @rm -rf $(maxdir)/*

clean_all :
	@rm  -rf $(REQUIRED_DIRS)

clean :
	@rm -rf $(bindir)/*

.PHONY: all test clean doc runapp viewsvg oct octview sc max binclean mdoc scinstall pdinstall vstinstall install ambixinstall

.SUFFIXES: .app .dsp .html .md
