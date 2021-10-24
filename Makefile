# Makefile for faust code compilation of directories
# created by the ADT generation routines in kmh_decoders
# 
# This file assumes that your faust code exists in
# a subdirectory that has its own Makefile:
#
# ./KMH108_AE_1h1p_normal_6/src/faustsources.dsp
#
# It may contan one or several .dsp files.
#
# The target for the recursively called Makefiles is 'all' by
# default but the build command may change this by running:
#
# make -K target=sc all

#------------------------------------#

# This builds the 'all' target in this Makefile and
# the sc target in the sub-Makefiles.
#
# To clean out all SVG files that may take up space:
#
# make clean_svg
# 
# # 23 September 2018	Henrik Frisk	mail@henrikfrisk.com

# sed script to remove faulty lines:
# sed -i -E 's/(.+n_inputs,n_outputs,outs.+)/\/\/\1/; s/(.+par.i,n_outputs,.0,gate_bus.i,outs.+)/\/\/\1/; s/.+m.bus.n_outputs.+//'

subdirs := $(wildcard ./KMH*)
target_makefile	:=  ~/Music/faust/faust_stuff.git/Makefile.adt
target 	:= all
sources := $(wildcard */src/*.dsp)

UNAME := $(shell uname)

test: 
	@echo $(UNAME)

print_subdirs :
	@echo $(subdirs)

.PHONY : all $(subdirs) update_makefile

clean_svg :
	$(foreach var, $(subdirs), $(shell rm "$(var)"/doc/*-svg/*.svg))

all : $(subdirs)

$(subdirs) :
	@echo "Installing sc files for $@..."
	$(MAKE) -C $@ $(target)

update_makefile : $(target_makefile)
	$(foreach var, $(subdirs), $(shell cp "$<" "$(var)/Makefile"))

list_sources :
	@echo $(sources)

edit_sources :
	$(foreach var, $(sources), $(shell sed -i -E 's/(.+n_inputs,n_outputs,outs.+)/\/\/\1/; s/(.+par.i,n_outputs,.0,gate_bus.i,outs.+)/\/\/\1/; s/.+m.bus.n_outputs.+//' $(var)))
