#define PRESETDIR "/var/tmp/"
/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit, Henrik Frisk"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMHLS_FullSetup_3h3p_full_2"
version: "1.2"
Code generated with Faust 2.18.3 (https://faust.grame.fr)
Compilation options: -lang cpp -scal -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

/************************************************************************
 IMPORTANT NOTE : this file contains two clearly delimited sections :
 the ARCHITECTURE section (in two parts) and the USER section. Each section
 is governed by its own copyright and license. Please check individually
 each section for license and copyright information.
 *************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2019 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 
 ************************************************************************
 ************************************************************************/

#include <libgen.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <list>

/************************** BEGIN proxy-dsp.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __proxy_dsp__
#define __proxy_dsp__

#include <vector>
#include <map>

/************************** BEGIN dsp.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp__
#define __dsp__

#include <string>
#include <vector>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;
struct Meta;

/**
 * DSP memory manager.
 */

struct dsp_memory_manager {
    
    virtual ~dsp_memory_manager() {}
    
    virtual void* allocate(size_t size) = 0;
    virtual void destroy(void* ptr) = 0;
    
};

/**
* Signal processor definition.
*/

class dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the ui_interface parameter with instance specific calls
         * to 'addBtton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Returns the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /**
         * Global init, calls the following methods:
         * - static class 'classInit': static tables initialization
         * - 'instanceInit': constants and instance state initialization
         *
         * @param sample_rate - the sampling rate in Hertz
         */
        virtual void init(int sample_rate) = 0;

        /**
         * Init instance state
         *
         * @param sample_rate - the sampling rate in Hertz
         */
        virtual void instanceInit(int sample_rate) = 0;

        /**
         * Init instance constant state
         *
         * @param sample_rate - the sampling rate in Hertz
         */
        virtual void instanceConstants(int sample_rate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (delay lines...) */
        virtual void instanceClear() = 0;
 
        /**
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value) metadata.
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with successive in/out audio buffers.
         *
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation: alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (either float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (either float, double or quad)
         *
         */
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int sample_rate) { fDSP->init(sample_rate); }
        virtual void instanceInit(int sample_rate) { fDSP->instanceInit(sample_rate); }
        virtual void instanceConstants(int sample_rate) { fDSP->instanceConstants(sample_rate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { fDSP->metadata(m); }
        // Beware: subclasses usually have to overload the two 'compute' methods
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
    
};

/**
 * DSP factory class.
 */

class dsp_factory {
    
    protected:
    
        // So that to force sub-classes to use deleteDSPFactory(dsp_factory* factory);
        virtual ~dsp_factory() {}
    
    public:
    
        virtual std::string getName() = 0;
        virtual std::string getSHAKey() = 0;
        virtual std::string getDSPCode() = 0;
        virtual std::string getCompileOptions() = 0;
        virtual std::vector<std::string> getLibraryList() = 0;
        virtual std::vector<std::string> getIncludePathnames() = 0;
    
        virtual dsp* createDSPInstance() = 0;
    
        virtual void setMemoryManager(dsp_memory_manager* manager) = 0;
        virtual dsp_memory_manager* getMemoryManager() = 0;
    
};

/**
 * On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
 * flags to avoid costly denormals.
 */

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif
/**************************  END  dsp.h **************************/
/************************** BEGIN JSONUIDecoder.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __JSONUIDecoder__
#define __JSONUIDecoder__

#include <vector>
#include <map>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <functional>

/************************** BEGIN CGlue.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef CGLUE_H
#define CGLUE_H

/************************** BEGIN UI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __UI_H__
#define __UI_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust DSP User Interface
 * User Interface as expected by the buildUserInterface() method of a DSP.
 * This abstract class contains only the method that the Faust compiler can
 * generate to describe a DSP user interface.
 ******************************************************************************/

struct Soundfile;

template <typename REAL>
class UIReal
{
    
    public:
        
        UIReal() {}
        virtual ~UIReal() {}
        
        // -- widget's layouts
        
        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;
        
        // -- active widgets
        
        virtual void addButton(const char* label, REAL* zone) = 0;
        virtual void addCheckButton(const char* label, REAL* zone) = 0;
        virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
        virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
        virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
        
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) = 0;
        virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max) = 0;
        
        // -- soundfiles
        
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;
        
        // -- metadata declarations
        
        virtual void declare(REAL* zone, const char* key, const char* val) {}
};

class UI : public UIReal<FAUSTFLOAT>
{

    public:

        UI() {}
        virtual ~UI() {}
};

#endif
/**************************  END  UI.h **************************/
/************************** BEGIN CInterface.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef CINTERFACE_H
#define CINTERFACE_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
    
struct Soundfile;

/*******************************************************************************
 * UI and Meta classes for C or LLVM generated code.
 ******************************************************************************/

// -- widget's layouts

typedef void (* openTabBoxFun) (void* ui_interface, const char* label);
typedef void (* openHorizontalBoxFun) (void* ui_interface, const char* label);
typedef void (* openVerticalBoxFun) (void* ui_interface, const char* label);
typedef void (*closeBoxFun) (void* ui_interface);

// -- active widgets

typedef void (* addButtonFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone);
typedef void (* addCheckButtonFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone);
typedef void (* addVerticalSliderFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step);
typedef void (* addHorizontalSliderFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step);
typedef void (* addNumEntryFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step);

// -- passive widgets

typedef void (* addHorizontalBargraphFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max);
typedef void (* addVerticalBargraphFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max);

// -- soundfiles
    
typedef void (* addSoundfileFun) (void* ui_interface, const char* label, const char* url, struct Soundfile** sf_zone);

typedef void (* declareFun) (void* ui_interface, FAUSTFLOAT* zone, const char* key, const char* value);

typedef struct {

    void* uiInterface;

    openTabBoxFun openTabBox;
    openHorizontalBoxFun openHorizontalBox;
    openVerticalBoxFun openVerticalBox;
    closeBoxFun closeBox;
    addButtonFun addButton;
    addCheckButtonFun addCheckButton;
    addVerticalSliderFun addVerticalSlider;
    addHorizontalSliderFun addHorizontalSlider;
    addNumEntryFun addNumEntry;
    addHorizontalBargraphFun addHorizontalBargraph;
    addVerticalBargraphFun addVerticalBargraph;
    addSoundfileFun addSoundfile;
    declareFun declare;

} UIGlue;

typedef void (* metaDeclareFun) (void* ui_interface, const char* key, const char* value);

typedef struct {

    void* metaInterface;
    
    metaDeclareFun declare;

} MetaGlue;

/***************************************
 *  Interface for the DSP object
 ***************************************/

typedef char dsp_imp;
    
typedef dsp_imp* (* newDspFun) ();
typedef void (* deleteDspFun) (dsp_imp* dsp);
typedef void (* allocateDspFun) (dsp_imp* dsp);
typedef void (* destroyDspFun) (dsp_imp* dsp);
typedef int (* getNumInputsFun) (dsp_imp* dsp);
typedef int (* getNumOutputsFun) (dsp_imp* dsp);
typedef void (* buildUserInterfaceFun) (dsp_imp* dsp, UIGlue* ui);
typedef void (* initFun) (dsp_imp* dsp, int sample_rate);
typedef void (* clearFun) (dsp_imp* dsp);
typedef int (* getSampleRateFun) (dsp_imp* dsp);
typedef void (* computeFun) (dsp_imp* dsp, int len, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs);
typedef void (* metadataFun) (MetaGlue* meta);
typedef void (* classInitFun) (int sample_rate);
typedef const char* (* getJSONFun) ();
    
/***************************************
 * DSP memory manager functions
 ***************************************/

typedef void* (* allocateFun) (void* manager_interface, size_t size);
typedef void (* destroyFun) (void* manager_interface, void* ptr);

typedef struct {
    
    void* managerInterface;
    
    allocateFun allocate;
    destroyFun destroy;
    
} ManagerGlue;

#ifdef __cplusplus
}
#endif

#endif
/**************************  END  CInterface.h **************************/
/************************** BEGIN meta.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __meta__
#define __meta__

struct Meta
{
    virtual ~Meta() {};
    virtual void declare(const char* key, const char* value) = 0;
    
};

#endif
/**************************  END  meta.h **************************/

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * UI glue code
 ******************************************************************************/
 
class UIFloat
{

    public:

        UIFloat() {}

        virtual ~UIFloat() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, float* zone) = 0;
        virtual void addCheckButton(const char* label, float* zone) = 0;
        virtual void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
        virtual void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
        virtual void addNumEntry(const char* label, float* zone, float init, float min, float max, float step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, float* zone, float min, float max) = 0;
        virtual void addVerticalBargraph(const char* label, float* zone, float min, float max) = 0;
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;

        // -- metadata declarations

        virtual void declare(float* zone, const char* key, const char* val) {}
};

static void openTabBoxGlueFloat(void* cpp_interface, const char* label)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->openTabBox(label);
}

static void openHorizontalBoxGlueFloat(void* cpp_interface, const char* label)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->openHorizontalBox(label);
}

static void openVerticalBoxGlueFloat(void* cpp_interface, const char* label)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->openVerticalBox(label);
}

static void closeBoxGlueFloat(void* cpp_interface)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->closeBox();
}

static void addButtonGlueFloat(void* cpp_interface, const char* label, float* zone)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addButton(label, zone);
}

static void addCheckButtonGlueFloat(void* cpp_interface, const char* label, float* zone)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addCheckButton(label, zone);
}

static void addVerticalSliderGlueFloat(void* cpp_interface, const char* label, float* zone, float init, float min, float max, float step)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addVerticalSlider(label, zone, init, min, max, step);
}

static void addHorizontalSliderGlueFloat(void* cpp_interface, const char* label, float* zone, float init, float min, float max, float step)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addHorizontalSlider(label, zone, init, min, max, step);
}

static void addNumEntryGlueFloat(void* cpp_interface, const char* label, float* zone, float init, float min, float max, float step)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addNumEntry(label, zone, init, min, max, step);
}

static void addHorizontalBargraphGlueFloat(void* cpp_interface, const char* label, float* zone, float min, float max)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addHorizontalBargraph(label, zone, min, max);
}

static void addVerticalBargraphGlueFloat(void* cpp_interface, const char* label, float* zone, float min, float max)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addVerticalBargraph(label, zone, min, max);
}
    
static void addSoundfileGlueFloat(void* cpp_interface, const char* label, const char* url, Soundfile** sf_zone)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addSoundfile(label, url, sf_zone);
}

static void declareGlueFloat(void* cpp_interface, float* zone, const char* key, const char* value)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->declare(zone, key, value);
}

class UIDouble
{

    public:

        UIDouble() {}

        virtual ~UIDouble() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, double* zone) = 0;
        virtual void addCheckButton(const char* label, double* zone) = 0;
        virtual void addVerticalSlider(const char* label, double* zone, double init, double min, double max, double step) = 0;
        virtual void addHorizontalSlider(const char* label, double* zone, double init, double min, double max, double step) = 0;
        virtual void addNumEntry(const char* label, double* zone, double init, double min, double max, double step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, double* zone, double min, double max) = 0;
        virtual void addVerticalBargraph(const char* label, double* zone, double min, double max) = 0;
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;

        // -- metadata declarations

        virtual void declare(double* zone, const char* key, const char* val) {}
};

static void openTabBoxGlueDouble(void* cpp_interface, const char* label)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->openTabBox(label);
}

static void openHorizontalBoxGlueDouble(void* cpp_interface, const char* label)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->openHorizontalBox(label);
}

static void openVerticalBoxGlueDouble(void* cpp_interface, const char* label)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->openVerticalBox(label);
}

static void closeBoxGlueDouble(void* cpp_interface)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->closeBox();
}

static void addButtonGlueDouble(void* cpp_interface, const char* label, double* zone)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addButton(label, zone);
}

static void addCheckButtonGlueDouble(void* cpp_interface, const char* label, double* zone)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addCheckButton(label, zone);
}

static void addVerticalSliderGlueDouble(void* cpp_interface, const char* label, double* zone, double init, double min, double max, double step)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addVerticalSlider(label, zone, init, min, max, step);
}

static void addHorizontalSliderGlueDouble(void* cpp_interface, const char* label, double* zone, double init, double min, double max, double step)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addHorizontalSlider(label, zone, init, min, max, step);
}

static void addNumEntryGlueDouble(void* cpp_interface, const char* label, double* zone, double init, double min, double max, double step)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addNumEntry(label, zone, init, min, max, step);
}

static void addHorizontalBargraphGlueDouble(void* cpp_interface, const char* label, double* zone, double min, double max)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addHorizontalBargraph(label, zone, min, max);
}

static void addVerticalBargraphGlueDouble(void* cpp_interface, const char* label, double* zone, double min, double max)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addVerticalBargraph(label, zone, min, max);
}
    
static void addSoundfileGlueDouble(void* cpp_interface, const char* label, const char* url, Soundfile** sf_zone)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addSoundfile(label, url, sf_zone);
}

static void declareGlueDouble(void* cpp_interface, double* zone, const char* key, const char* value)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->declare(zone, key, value);
}

static void buildUIGlue(UIGlue* glue, UI* ui_interface, bool is_double)
{
    glue->uiInterface = ui_interface;
    
    if (is_double) {
        glue->openTabBox = reinterpret_cast<openTabBoxFun>(openTabBoxGlueDouble);
        glue->openHorizontalBox = reinterpret_cast<openHorizontalBoxFun>(openHorizontalBoxGlueDouble);
        glue->openVerticalBox = reinterpret_cast<openVerticalBoxFun>(openVerticalBoxGlueDouble);
        glue->closeBox = reinterpret_cast<closeBoxFun>(closeBoxGlueDouble);
        glue->addButton = reinterpret_cast<addButtonFun>(addButtonGlueDouble);
        glue->addCheckButton = reinterpret_cast<addCheckButtonFun>(addCheckButtonGlueDouble);
        glue->addVerticalSlider = reinterpret_cast<addVerticalSliderFun>(addVerticalSliderGlueDouble);
        glue->addHorizontalSlider = reinterpret_cast<addHorizontalSliderFun>(addHorizontalSliderGlueDouble);
        glue->addNumEntry = reinterpret_cast<addNumEntryFun>(addNumEntryGlueDouble);
        glue->addHorizontalBargraph = reinterpret_cast<addHorizontalBargraphFun>(addHorizontalBargraphGlueDouble);
        glue->addVerticalBargraph = reinterpret_cast<addVerticalBargraphFun>(addVerticalBargraphGlueDouble);
        glue->addSoundfile = reinterpret_cast<addSoundfileFun>(addSoundfileGlueDouble);
        glue->declare = reinterpret_cast<declareFun>(declareGlueDouble);
    } else {
        glue->openTabBox = reinterpret_cast<openTabBoxFun>(openTabBoxGlueFloat);
        glue->openHorizontalBox = reinterpret_cast<openHorizontalBoxFun>(openHorizontalBoxGlueFloat);
        glue->openVerticalBox = reinterpret_cast<openVerticalBoxFun>(openVerticalBoxGlueFloat);
        glue->closeBox = reinterpret_cast<closeBoxFun>(closeBoxGlueFloat);
        glue->addButton = reinterpret_cast<addButtonFun>(addButtonGlueFloat);
        glue->addCheckButton = reinterpret_cast<addCheckButtonFun>(addCheckButtonGlueFloat);
        glue->addVerticalSlider = reinterpret_cast<addVerticalSliderFun>(addVerticalSliderGlueFloat);
        glue->addHorizontalSlider = reinterpret_cast<addHorizontalSliderFun>(addHorizontalSliderGlueFloat);
        glue->addNumEntry = reinterpret_cast<addNumEntryFun>(addNumEntryGlueFloat);
        glue->addHorizontalBargraph = reinterpret_cast<addHorizontalBargraphFun>(addHorizontalBargraphGlueFloat);
        glue->addVerticalBargraph = reinterpret_cast<addVerticalBargraphFun>(addVerticalBargraphGlueFloat);
        glue->addSoundfile = reinterpret_cast<addSoundfileFun>(addSoundfileGlueFloat);
        glue->declare = reinterpret_cast<declareFun>(declareGlueFloat);
    }
}
    
class UITemplate
{
    
    private:
        
        void* fCPPInterface;
        
    public:
        
        UITemplate(void* cpp_interface):fCPPInterface(cpp_interface)
        {}
        
        virtual ~UITemplate() {}
        
        // -- widget's layouts
        
        virtual void openTabBox(const char* label)
        {
            openTabBoxGlueFloat(fCPPInterface, label);
        }
        virtual void openHorizontalBox(const char* label)
        {
            openHorizontalBoxGlueFloat(fCPPInterface, label);
        }
        virtual void openVerticalBox(const char* label)
        {
            openVerticalBoxGlueFloat(fCPPInterface, label);
        }
        virtual void closeBox()
        {
            closeBoxGlueFloat(fCPPInterface);
        }
        
        // float version
        
        // -- active widgets
        
        virtual void addButton(const char* label, float* zone)
        {
            addButtonGlueFloat(fCPPInterface, label, zone);
        }
        virtual void addCheckButton(const char* label, float* zone)
        {
            addCheckButtonGlueFloat(fCPPInterface, label, zone);
        }
        
        virtual void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step)
        {
            addVerticalSliderGlueFloat(fCPPInterface, label, zone, init, min, max, step);
        }
        
        virtual void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step)
        {
            addHorizontalSliderGlueFloat(fCPPInterface, label, zone, init, min, max, step);
        }
        
        virtual void addNumEntry(const char* label, float* zone, float init, float min, float max, float step)
        {
            addNumEntryGlueFloat(fCPPInterface, label, zone, init, min, max, step);
        }
        
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, float* zone, float min, float max)
        {
            addHorizontalBargraphGlueFloat(fCPPInterface, label, zone, min, max);
        }
        
        virtual void addVerticalBargraph(const char* label, float* zone, float min, float max)
        {
            addVerticalBargraphGlueFloat(fCPPInterface, label, zone, min, max);
        }
    
        // -- metadata declarations
        
        virtual void declare(float* zone, const char* key, const char* val)
        {
            declareGlueFloat(fCPPInterface, zone, key, val);
        }
        
        // double version
        
        virtual void addButton(const char* label, double* zone)
        {
            addButtonGlueDouble(fCPPInterface, label, zone);
        }
        virtual void addCheckButton(const char* label, double* zone)
        {
            addCheckButtonGlueDouble(fCPPInterface, label, zone);
        }
        
        virtual void addVerticalSlider(const char* label, double* zone, double init, double min, double max, double step)
        {
            addVerticalSliderGlueDouble(fCPPInterface, label, zone, init, min, max, step);
        }
        
        virtual void addHorizontalSlider(const char* label, double* zone, double init, double min, double max, double step)
        {
            addHorizontalSliderGlueDouble(fCPPInterface, label, zone, init, min, max, step);
        }
        
        virtual void addNumEntry(const char* label, double* zone, double init, double min, double max, double step)
        {
            addNumEntryGlueDouble(fCPPInterface, label, zone, init, min, max, step);
        }
    
        // -- soundfiles
        
        virtual void addSoundfile(const char* label, const char* url, Soundfile** sf_zone)
        {
            addSoundfileGlueFloat(fCPPInterface, label, url, sf_zone);
        }
    
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, double* zone, double min, double max)
        {
            addHorizontalBargraphGlueDouble(fCPPInterface, label, zone, min, max);
        }
        
        virtual void addVerticalBargraph(const char* label, double* zone, double min, double max)
        {
            addVerticalBargraphGlueDouble(fCPPInterface, label, zone, min, max);
        }
    
        // -- metadata declarations
        
        virtual void declare(double* zone, const char* key, const char* val)
        {
            declareGlueDouble(fCPPInterface, zone, key, val);
        }

};

/*******************************************************************************
 * Meta glue code
 ******************************************************************************/

static void declareMetaGlue(void* cpp_interface, const char* key, const char* value)
{
    Meta* meta_interface = static_cast<Meta*>(cpp_interface);
    meta_interface->declare(key, value);
}

static void buildMetaGlue(MetaGlue* glue, Meta* meta)
{
    glue->metaInterface = meta;
    glue->declare = declareMetaGlue;
}
    
/*******************************************************************************
 * Memory manager glue code
 ******************************************************************************/

static void* allocateManagerGlue(void* cpp_interface, size_t size)
{
    dsp_memory_manager* manager_interface = static_cast<dsp_memory_manager*>(cpp_interface);
    return manager_interface->allocate(size);
}
    
static void destroyManagerGlue(void* cpp_interface, void* ptr)
{
    dsp_memory_manager* manager_interface = static_cast<dsp_memory_manager*>(cpp_interface);
    manager_interface->destroy(ptr);
}

static void buildManagerGlue(ManagerGlue* glue, dsp_memory_manager* manager)
{
    glue->managerInterface = manager;
    glue->allocate = allocateManagerGlue;
    glue->destroy = destroyManagerGlue;
}

#ifdef __cplusplus
}
#endif

#endif
/**************************  END  CGlue.h **************************/
/************************** BEGIN SimpleParser.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef SIMPLEPARSER_H
#define SIMPLEPARSER_H

// ---------------------------------------------------------------------
//                          Simple Parser
// A parser returns true if it was able to parse what it is
// supposed to parse and advance the pointer. Otherwise it returns false
// and the pointer is not advanced so that another parser can be tried.
// ---------------------------------------------------------------------

#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <ctype.h>

#ifndef _WIN32
# pragma GCC diagnostic ignored "-Wunused-function"
#endif

struct itemInfo {
    std::string type;
    std::string label;
    std::string url;
    std::string address;
    int index;
    double init;
    double min;
    double max;
    double step;
    std::vector<std::pair<std::string, std::string> > meta;
    
    itemInfo():index(0), init(0.), min(0.), max(0.), step(0.)
    {}
};

// ---------------------------------------------------------------------
//                          Elementary parsers
// ---------------------------------------------------------------------

// Report a parsing error
static bool parseError(const char*& p, const char* errmsg)
{
    std::cerr << "Parse error : " << errmsg << " here : " << p << std::endl;
    return true;
}

/**
 * @brief skipBlank : advance pointer p to the first non blank character
 * @param p the string to parse, then the remaining string
 */
static void skipBlank(const char*& p)
{
    while (isspace(*p)) { p++; }
}

// Parse character x, but don't report error if fails
static bool tryChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseChar : parse a specific character x
 * @param p the string to parse, then the remaining string
 * @param x the character to recognize
 * @return true if x was found at the begin of p
 */
static bool parseChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseWord : parse a specific string w
 * @param p the string to parse, then the remaining string
 * @param w the string to recognize
 * @return true if string w was found at the begin of p
 */
static bool parseWord(const char*& p, const char* w)
{
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail
    while ((*w == *p) && (*w)) {++w; ++p;}
    if (*w) {
        p = saved;
        return false;
    } else {
        return true;
    }
}

/**
 * @brief parseDouble : parse number [s]dddd[.dddd] and store the result in x
 * @param p the string to parse, then the remaining string
 * @param x the float number found if any
 * @return true if a float number was found at the begin of p
 */
static bool parseDouble(const char*& p, double& x)
{
    double sign = +1.0;    // sign of the number
    double ipart = 0;      // integral part of the number
    double dpart = 0;      // decimal part of the number before division
    double dcoef = 1.0;    // division factor for the decimal part
    
    bool valid = false;    // true if the number contains at least one digit
    skipBlank(p);
    const char* saved = p; // to restore position if we fail
    
    if (parseChar(p, '+')) {
        sign = 1.0;
    } else if (parseChar(p, '-')) {
        sign = -1.0;
    }
    while (isdigit(*p)) {
        valid = true;
        ipart = ipart*10 + (*p - '0');
        p++;
    }
    if (parseChar(p, '.')) {
        while (isdigit(*p)) {
            valid = true;
            dpart = dpart*10 + (*p - '0');
            dcoef *= 10.0;
            p++;
        }
    }
    if (valid)  {
        x = sign*(ipart + dpart/dcoef);
    } else {
        p = saved;
    }
 
    return valid;
}

/**
 * @brief parseString, parse an arbitrary quoted string q...q and store the result in s
 * @param p the string to parse, then the remaining string
 * @param quote the character used to quote the string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseString(const char*& p, char quote, std::string& s)
{
    std::string str;
    skipBlank(p);
    
    const char* saved = p;  // to restore position if we fail
    if (*p++ == quote) {
        while ((*p != 0) && (*p != quote)) {
            str += *p++;
        }
        if (*p++ == quote) {
            s = str;
            return true;
        }
    }
    p = saved;
    return false;
}

/**
 * @brief parseSQString, parse a single quoted string '...' and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseSQString(const char*& p, std::string& s)
{
    return parseString(p, '\'', s);
}

/**
 * @brief parseDQString, parse a double quoted string "..." and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseDQString(const char*& p, std::string& s)
{
    return parseString(p, '"', s);
}

// ---------------------------------------------------------------------
//
//                          IMPLEMENTATION
// 
// ---------------------------------------------------------------------

/**
 * @brief parseMenuItem, parse a menu item ...'low':440.0...
 * @param p the string to parse, then the remaining string
 * @param name the name found
 * @param value the value found
 * @return true if a nemu item was found
 */
static bool parseMenuItem(const char*& p, std::string& name, double& value)
{
    const char* saved = p;  // to restore position if we fail
    if (parseSQString(p, name) && parseChar(p, ':') && parseDouble(p, value)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

static bool parseMenuItem2(const char*& p, std::string& name)
{
    const char* saved = p;  // to restore position if we fail
    
    // single quoted
    if (parseSQString(p, name)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

/**
 * @brief parseMenuList, parse a menu list {'low' : 440.0; 'mid' : 880.0; 'hi' : 1760.0}...
 * @param p the string to parse, then the remaining string
 * @param names the vector of names found
 * @param values the vector of values found
 * @return true if a menu list was found
 */
static bool parseMenuList(const char*& p, std::vector<std::string>& names, std::vector<double>& values)
{
    std::vector<std::string> tmpnames;
    std::vector<double> tmpvalues;
    const char* saved = p; // to restore position if we fail

    if (parseChar(p, '{')) {
        do {
            std::string n;
            double v;
            if (parseMenuItem(p, n, v)) {
                tmpnames.push_back(n);
                tmpvalues.push_back(v);
            } else {
                p = saved;
                return false;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            values = tmpvalues;
            return true;
        }
    }
    p = saved;
    return false;
}

static bool parseMenuList2(const char*& p, std::vector<std::string>& names, bool debug)
{
    std::vector<std::string> tmpnames;
    const char* saved = p;  // to restore position if we fail
    
    if (parseChar(p, '{')) {
        do {
            std::string n;
            if (parseMenuItem2(p, n)) {
                tmpnames.push_back(n);
            } else {
                goto error;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            return true;
        }
    }
    
error:
    if (debug) { std::cerr << "parseMenuList2 : (" << saved << ") is not a valid list !\n"; }
    p = saved;
    return false;
}

/// ---------------------------------------------------------------------
// Parse list of strings
/// ---------------------------------------------------------------------
static bool parseList(const char*& p, std::vector<std::string>& items)
{
    const char* saved = p;  // to restore position if we fail
    if (parseChar(p, '[')) {
        do {
            std::string item;
            if (!parseDQString(p, item)) {
                p = saved;
                return false;
            }
            items.push_back(item);
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        p = saved;
        return false;
    }
}

static bool parseMetaData(const char*& p, std::map<std::string, std::string>& metadatas)
{
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas[metaKey] = metaValue;
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        return false;
    }
}

static bool parseItemMetaData(const char*& p, std::vector<std::pair<std::string, std::string> >& metadatas)
{
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas.push_back(std::make_pair(metaKey, metaValue));
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse metadatas of the interface:
// "name" : "...", "inputs" : "...", "outputs" : "...", ...
// and store the result as key/value
/// ---------------------------------------------------------------------
static bool parseGlobalMetaData(const char*& p, std::string& key, std::string& value, double& dbl, std::map<std::string, std::string>& metadatas, std::vector<std::string>& items)
{
    if (parseDQString(p, key)) {
        if (key == "meta") {
            return parseMetaData(p, metadatas);
        } else {
            return parseChar(p, ':') && (parseDQString(p, value) || parseList(p, items) || parseDouble(p, dbl));
        }
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse gui:
// "type" : "...", "label" : "...", "address" : "...", ...
// and store the result in uiItems Vector
/// ---------------------------------------------------------------------
static bool parseUI(const char*& p, std::vector<itemInfo>& uiItems, int& numItems)
{
    if (parseChar(p, '{')) {
   
        std::string label;
        std::string value;
        double dbl = 0;
        
        do {
            if (parseDQString(p, label)) {
                if (label == "type") {
                    if (uiItems.size() != 0) {
                        numItems++;
                    }
                    if (parseChar(p, ':') && parseDQString(p, value)) {   
                        itemInfo item;
                        item.type = value;
                        uiItems.push_back(item);
                    }
                }
                
                else if (label == "label") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].label = value;
                    }
                }
                
                else if (label == "url") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].url = value;
                    }
                }
                
                else if (label == "address") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].address = value;
                    }
                }
                
                else if (label == "index") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].index = dbl;
                    }
                }
                
                else if (label == "meta") {
                    if (!parseItemMetaData(p, uiItems[numItems].meta)) {
                        return false;
                    }
                }
                
                else if (label == "init") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].init = dbl;
                    }
                }
                
                else if (label == "min") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].min = dbl;
                    }
                }
                
                else if (label == "max") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].max = dbl;
                    }
                }
                
                else if (label == "step"){
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].step = dbl;
                    }
                }
                
                else if (label == "items") {
                    if (parseChar(p, ':') && parseChar(p, '[')) {
                        do { 
                            if (!parseUI(p, uiItems, numItems)) {
                                return false;
                            }
                        } while (tryChar(p, ','));
                        if (parseChar(p, ']')) {
                            itemInfo item;
                            item.type = "close";
                            uiItems.push_back(item);
                            numItems++;
                        }
                    }
                }
            } else {
                return false;
            }
            
        } while (tryChar(p, ','));
        
        return parseChar(p, '}');
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse full JSON record describing a JSON/Faust interface :
// {"metadatas": "...", "ui": [{ "type": "...", "label": "...", "items": [...], "address": "...","init": "...", "min": "...", "max": "...","step": "..."}]}
//
// and store the result in map Metadatas and vector containing the items of the interface. Returns true if parsing was successfull.
/// ---------------------------------------------------------------------
static bool parseJson(const char*& p,
                      std::map<std::string, std::pair<std::string, double> >& metaDatas0,
                      std::map<std::string, std::string>& metaDatas1,
                      std::map<std::string, std::vector<std::string> >& metaDatas2,
                      std::vector<itemInfo>& uiItems)
{
    parseChar(p, '{');
    
    do {
        std::string key;
        std::string value;
        double dbl = 0;
        std::vector<std::string> items;
        if (parseGlobalMetaData(p, key, value, dbl, metaDatas1, items)) {
            if (key != "meta") {
                // keep "name", "inputs", "outputs" key/value pairs
                if (items.size() > 0) {
                    metaDatas2[key] = items;
                    items.clear();
                } else if (value != "") {
                    metaDatas0[key].first = value;
                } else {
                    metaDatas0[key].second = dbl;
                }
            }
        } else if (key == "ui") {
            int numItems = 0;
            parseChar(p, '[') && parseUI(p, uiItems, numItems);
        }
    } while (tryChar(p, ','));
    
    return parseChar(p, '}');
}

#endif // SIMPLEPARSER_H
/**************************  END  SimpleParser.h **************************/

#ifdef _WIN32
#include <windows.h>
#define snprintf _snprintf
#endif

//-------------------------------------------------------------------
//  Decode a dsp JSON description and implement 'buildUserInterface'
//-------------------------------------------------------------------

#define REAL_UI(ui_interface)  reinterpret_cast<UIReal<REAL>*>(ui_interface)
#define REAL_ADR(offset)       reinterpret_cast<REAL*>(&memory_block[offset])
#define SOUNDFILE_ADR(offset)  reinterpret_cast<Soundfile**>(&memory_block[offset])

typedef std::function<void(double)> ReflectFunction;
typedef std::function<double()> ModifyFunction;

struct ExtZoneParam {

    virtual void reflectZone() = 0;
    virtual void modifyZone() = 0;
    
    virtual void setReflectZoneFun(ReflectFunction reflect) = 0;
    virtual void setModifyZoneFun(ModifyFunction modify) = 0;
    
};

template <typename REAL>
struct JSONUIDecoderAux {
    
    struct ZoneParam : public ExtZoneParam {
        
        REAL fZone;
        int fIndex;
        ReflectFunction fReflect;
        ModifyFunction fModify;
        
    #if defined(TARGET_OS_IPHONE) || defined(WIN32)
        ZoneParam(int index, ReflectFunction reflect = nullptr, ModifyFunction modify = nullptr)
        :fIndex(index), fReflect(reflect), fModify(modify)
        {}
        void reflectZone() { if (fReflect) fReflect(fZone); }
        void modifyZone() { if (fModify) fZone = fModify(); }
    #else
        ZoneParam(int index, ReflectFunction reflect = [](REAL value) {}, ModifyFunction modify = []() { return REAL(-1); })
        :fIndex(index), fReflect(reflect), fModify(modify)
        {}
        void reflectZone() { fReflect(fZone); }
        void modifyZone() { fZone = fModify(); }
    #endif
        
        void setReflectZoneFun(ReflectFunction reflect) { fReflect = reflect; }
        void setModifyZoneFun(ModifyFunction modify) { fModify = modify; }
        
    };

    typedef std::vector<ExtZoneParam*> controlMap;
  
    std::string fName;
    std::string fFileName;
    std::string fJSON;
    std::string fVersion;
    std::string fCompileOptions;
    
    std::map<std::string, std::string> fMetadata;
    std::vector<itemInfo> fUiItems;
    
    std::vector<std::string> fLibraryList;
    std::vector<std::string> fIncludePathnames;
    
    Soundfile** fSoundfiles;
    
    int fNumInputs, fNumOutputs, fSRIndex;
    int fSoundfileItems;
    int fDSPSize;
    
    controlMap fPathInputTable;     // [path, ZoneParam]
    controlMap fPathOutputTable;    // [path, ZoneParam]

    bool isInput(const std::string& type)
    {
        return (type == "vslider" || type == "hslider" || type == "nentry" || type == "button" || type == "checkbox");
    }
    bool isOutput(const std::string& type) { return (type == "hbargraph" || type == "vbargraph"); }
    bool isSoundfile(const std::string& type) { return (type == "soundfile"); }
    
    std::string getString(std::map<std::string, std::pair<std::string, double> >& map, const std::string& key)
    {
        return (map.find(key) != map.end()) ? map[key].first : "";
    }
    
    int getInt(std::map<std::string, std::pair<std::string, double> >& map, const std::string& key)
    {
        return (map.find(key) != map.end()) ? int(map[key].second) : -1;
    }
    
    void setReflectZoneFun(int index, ReflectFunction fun)
    {
        fPathInputTable[index]->setReflectZoneFun(fun);
    }
    
    void setModifyZoneFun(int index, ModifyFunction fun)
    {
        fPathOutputTable[index]->setModifyZoneFun(fun);
    }

    JSONUIDecoderAux(const std::string& json)
    {
        fJSON = json;
        const char* p = fJSON.c_str();
        std::map<std::string, std::pair<std::string, double> > meta_data1;
        std::map<std::string, std::vector<std::string> > meta_data2;
        parseJson(p, meta_data1, fMetadata, meta_data2, fUiItems);
        
        // meta_data1 contains <name : val>, <inputs : val>, <ouputs : val> pairs etc...
        fName = getString(meta_data1, "name");
        fFileName = getString(meta_data1, "filename");
        fVersion = getString(meta_data1, "version");
        fCompileOptions = getString(meta_data1, "compile_options");
        
        if (meta_data2.find("library_list") != meta_data2.end()) {
            fLibraryList = meta_data2["library_list"];
        }
        if (meta_data2.find("include_pathnames") != meta_data2.end()) {
            fIncludePathnames = meta_data2["include_pathnames"];
        }
        
        fDSPSize = getInt(meta_data1, "size");
        fNumInputs = getInt(meta_data1, "inputs");
        fNumOutputs = getInt(meta_data1, "outputs");
        fSRIndex = getInt(meta_data1, "sr_index");
       
        fSoundfileItems = 0;
        for (auto& it : fUiItems) {
            std::string type = it.type;
            if (isSoundfile(type)) {
                fSoundfileItems++;
            }
        }
        
        fSoundfiles = new Soundfile*[fSoundfileItems];
        
        // Prepare the fPathTable and init zone
        for (auto& it : fUiItems) {
            std::string type = it.type;
            // Meta data declaration for input items
            if (isInput(type)) {
                ZoneParam* param = new ZoneParam(it.index);
                fPathInputTable.push_back(param);
                param->fZone = it.init;
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                ZoneParam* param = new ZoneParam(it.index);
                fPathOutputTable.push_back(param);
                param->fZone = REAL(0);
            }
        }
    }
    
    virtual ~JSONUIDecoderAux()
    {
        delete [] fSoundfiles;
    }
    
    void metadata(Meta* m)
    {
        for (auto& it : fMetadata) {
            m->declare(it.first.c_str(), it.second.c_str());
        }
    }
    
    void metadata(MetaGlue* m)
    {
        for (auto& it : fMetadata) {
            m->declare(m->metaInterface, it.first.c_str(), it.second.c_str());
        }
    }
    
    void resetUserInterface()
    {
        int item = 0;
        for (auto& it : fUiItems) {
            if (isInput(it.type)) {
                static_cast<ZoneParam*>(fPathInputTable[item++])->fZone = it.init;
            }
        }
    }
    
    void resetUserInterface(char* memory_block, Soundfile* defaultsound = nullptr)
    {
        for (auto& it : fUiItems) {
            int offset = it.index;
            if (isInput(it.type)) {
                *REAL_ADR(offset) = it.init;
            } else if (isSoundfile(it.type)) {
                if (*SOUNDFILE_ADR(offset) == nullptr) {
                    *SOUNDFILE_ADR(offset) = defaultsound;
                }
            }
        }
    }
    
    int getSampleRate(char* memory_block)
    {
        return *reinterpret_cast<int*>(&memory_block[fSRIndex]);
    }
   
    void buildUserInterface(UI* ui_interface)
    {
        // MANDATORY: to be sure floats or double are correctly parsed
        char* tmp_local = setlocale(LC_ALL, nullptr);
        setlocale(LC_ALL, "C");
        
        int countIn = 0;
        int countOut = 0;
        int countSound = 0;
        
        for (auto& it : fUiItems) {
            
            std::string type = it.type;
            REAL init = it.init;
            REAL min = it.min;
            REAL max = it.max;
            REAL step = it.step;
            
            // Meta data declaration for input items
            if (isInput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(&static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(&static_cast<ZoneParam*>(fPathOutputTable[countOut])->fZone, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(0, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                REAL_UI(ui_interface)->openHorizontalBox(it.label.c_str());
            } else if (type == "vgroup") { 
                REAL_UI(ui_interface)->openVerticalBox(it.label.c_str());
            } else if (type == "tgroup") {
                REAL_UI(ui_interface)->openTabBox(it.label.c_str());
            } else if (type == "vslider") {
                REAL_UI(ui_interface)->addVerticalSlider(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, init, min, max, step);
            } else if (type == "hslider") {
                REAL_UI(ui_interface)->addHorizontalSlider(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, init, min, max, step);
            } else if (type == "checkbox") {
                REAL_UI(ui_interface)->addCheckButton(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone);
            } else if (type == "soundfile") {
                REAL_UI(ui_interface)->addSoundfile(it.label.c_str(), it.url.c_str(), &fSoundfiles[countSound]);
            } else if (type == "hbargraph") {
                REAL_UI(ui_interface)->addHorizontalBargraph(it.label.c_str(), &static_cast<ZoneParam*>(fPathOutputTable[countOut])->fZone, min, max);
            } else if (type == "vbargraph") {
                REAL_UI(ui_interface)->addVerticalBargraph(it.label.c_str(), &static_cast<ZoneParam*>(fPathOutputTable[countOut])->fZone, min, max);
            } else if (type == "nentry") {
                REAL_UI(ui_interface)->addNumEntry(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, init, min, max, step);
            } else if (type == "button") {
                REAL_UI(ui_interface)->addButton(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone);
            } else if (type == "close") {
                REAL_UI(ui_interface)->closeBox();
            }
            
            if (isInput(type)) {
                countIn++;
            } else if (isOutput(type)) {
                countOut++;
            } else if (isSoundfile(type)) {
                countSound++;
            }
        }
        
        setlocale(LC_ALL, tmp_local);
    }
    
    void buildUserInterface(UI* ui_interface, char* memory_block)
    {
        // MANDATORY: to be sure floats or double are correctly parsed
        char* tmp_local = setlocale(LC_ALL, nullptr);
        setlocale(LC_ALL, "C");
        
        for (auto& it : fUiItems) {
            
            std::string type = it.type;
            int offset = it.index;
            REAL init = it.init;
            REAL min = it.min;
            REAL max = it.max;
            REAL step = it.step;
            
            // Meta data declaration for input items
            if (isInput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(REAL_ADR(offset), it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(REAL_ADR(offset), it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(0, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                REAL_UI(ui_interface)->openHorizontalBox(it.label.c_str());
            } else if (type == "vgroup") {
                REAL_UI(ui_interface)->openVerticalBox(it.label.c_str());
            } else if (type == "tgroup") {
                REAL_UI(ui_interface)->openTabBox(it.label.c_str());
            } else if (type == "vslider") {
                REAL_UI(ui_interface)->addVerticalSlider(it.label.c_str(), REAL_ADR(offset), init, min, max, step);
            } else if (type == "hslider") {
                REAL_UI(ui_interface)->addHorizontalSlider(it.label.c_str(), REAL_ADR(offset), init, min, max, step);
            } else if (type == "checkbox") {
                REAL_UI(ui_interface)->addCheckButton(it.label.c_str(), REAL_ADR(offset));
            } else if (type == "soundfile") {
                REAL_UI(ui_interface)->addSoundfile(it.label.c_str(), it.url.c_str(), SOUNDFILE_ADR(offset));
            } else if (type == "hbargraph") {
                REAL_UI(ui_interface)->addHorizontalBargraph(it.label.c_str(), REAL_ADR(offset), min, max);
            } else if (type == "vbargraph") {
                REAL_UI(ui_interface)->addVerticalBargraph(it.label.c_str(), REAL_ADR(offset), min, max);
            } else if (type == "nentry") {
                REAL_UI(ui_interface)->addNumEntry(it.label.c_str(), REAL_ADR(offset), init, min, max, step);
            } else if (type == "button") {
                REAL_UI(ui_interface)->addButton(it.label.c_str(), REAL_ADR(offset));
            } else if (type == "close") {
                REAL_UI(ui_interface)->closeBox();
            }
        }
        
        setlocale(LC_ALL, tmp_local);
    }
    
    void buildUserInterface(UIGlue* ui_interface, char* memory_block)
    {
        // TODO
    }
    
    bool hasCompileOption(const std::string& option)
    {
        std::istringstream iss(fCompileOptions);
        std::string token;
        while (std::getline(iss, token, ' ')) {
            if (token == option) return true;
        }
        return false;
    }
    
};

// Templated decoder

struct JSONUITemplatedDecoder
{

    virtual ~JSONUITemplatedDecoder()
    {}
    
    virtual void metadata(Meta* m) = 0;
    virtual void metadata(MetaGlue* glue) = 0;
    virtual int getDSPSize() = 0;
    virtual std::string getName() = 0;
    virtual std::string getLibVersion() = 0;
    virtual std::string getCompileOptions() = 0;
    virtual std::vector<std::string> getLibraryList() = 0;
    virtual std::vector<std::string> getIncludePathnames() = 0;
    virtual int getNumInputs() = 0;
    virtual int getNumOutputs() = 0;
    virtual int getSampleRate(char* memory_block) = 0;
    virtual void setReflectZoneFun(int index, ReflectFunction fun) = 0;
    virtual void setModifyZoneFun(int index, ModifyFunction fun) = 0;
    virtual std::vector<ExtZoneParam*>& getInputControls() = 0;
    virtual std::vector<ExtZoneParam*>& getOutputControls() = 0;
    virtual void resetUserInterface(char* memory_block, Soundfile* defaultsound = nullptr) = 0;
    virtual void buildUserInterface(UI* ui_interface) = 0;
    virtual void buildUserInterface(UI* ui_interface, char* memory_block) = 0;
    virtual void buildUserInterface(UIGlue* ui_interface, char* memory_block) = 0;
    virtual bool hasCompileOption(const std::string& option) = 0;
};

struct JSONUIFloatDecoder : public JSONUIDecoderAux<float>, public JSONUITemplatedDecoder
{
    JSONUIFloatDecoder(const std::string& json):JSONUIDecoderAux<float>(json)
    {}
    
    void metadata(Meta* m) { JSONUIDecoderAux<float>::metadata(m); }
    void metadata(MetaGlue* glue) { JSONUIDecoderAux<float>::metadata(glue); }
    int getDSPSize() { return fDSPSize; }
    std::string getName() { return fName; }
    std::string getLibVersion() { return fVersion; }
    std::string getCompileOptions() { return fCompileOptions; }
    std::vector<std::string> getLibraryList() { return fLibraryList; }
    std::vector<std::string> getIncludePathnames() { return fIncludePathnames; }
    int getNumInputs() { return fNumInputs; }
    int getNumOutputs() { return fNumOutputs; }
    int getSampleRate(char* memory_block)  { return JSONUIDecoderAux<float>::getSampleRate(memory_block); }
    void setReflectZoneFun(int index, ReflectFunction fun)
    {
        JSONUIDecoderAux<float>::setReflectZoneFun(index, fun);
    }
    void setModifyZoneFun(int index, ModifyFunction fun)
    {
        JSONUIDecoderAux<float>::setModifyZoneFun(index, fun);
    }
    std::vector<ExtZoneParam*>& getInputControls()
    {
        return fPathInputTable;
    }
    std::vector<ExtZoneParam*>& getOutputControls()
    {
        return fPathOutputTable;
    }
    void resetUserInterface(char* memory_block, Soundfile* defaultsound = nullptr)
    {
        JSONUIDecoderAux<float>::resetUserInterface(memory_block, defaultsound);
    }
    void buildUserInterface(UI* ui_interface)
    {
        JSONUIDecoderAux<float>::buildUserInterface(ui_interface);
    }
    void buildUserInterface(UI* ui_interface, char* memory_block)
    {
        JSONUIDecoderAux<float>::buildUserInterface(ui_interface, memory_block);
    }
    void buildUserInterface(UIGlue* ui_interface, char* memory_block)
    {
        JSONUIDecoderAux<float>::buildUserInterface(ui_interface, memory_block);
    }
    bool hasCompileOption(const std::string& option) { return JSONUIDecoderAux<float>::hasCompileOption(option); }
};

struct JSONUIDoubleDecoder : public JSONUIDecoderAux<double>, public JSONUITemplatedDecoder
{
    JSONUIDoubleDecoder(const std::string& json):JSONUIDecoderAux<double>(json)
    {}
    
    void metadata(Meta* m) { JSONUIDecoderAux<double>::metadata(m); }
    void metadata(MetaGlue* glue) { JSONUIDecoderAux<double>::metadata(glue); }
    int getDSPSize() { return fDSPSize; }
    std::string getName() { return fName; }
    std::string getLibVersion() { return fVersion; }
    std::string getCompileOptions() { return fCompileOptions; }
    std::vector<std::string> getLibraryList() { return fLibraryList; }
    std::vector<std::string> getIncludePathnames() { return fIncludePathnames; }
    int getNumInputs() { return fNumInputs; }
    int getNumOutputs() { return fNumOutputs; }
    int getSampleRate(char* memory_block) { return JSONUIDecoderAux<double>::getSampleRate(memory_block); }
    void setReflectZoneFun(int index, ReflectFunction fun)
    {
        JSONUIDecoderAux<double>::setReflectZoneFun(index, fun);
    }
    void setModifyZoneFun(int index, ModifyFunction fun)
    {
        JSONUIDecoderAux<double>::setModifyZoneFun(index, fun);
    }
    std::vector<ExtZoneParam*>& getInputControls()
    {
        return fPathInputTable;
    }
    std::vector<ExtZoneParam*>& getOutputControls()
    {
        return fPathOutputTable;
    }
    void resetUserInterface(char* memory_block, Soundfile* defaultsound = nullptr)
    {
        JSONUIDecoderAux<double>::resetUserInterface(memory_block, defaultsound);
    }
    void buildUserInterface(UI* ui_interface)
    {
        JSONUIDecoderAux<double>::buildUserInterface(ui_interface);
    }
    void buildUserInterface(UI* ui_interface, char* memory_block)
    {
        JSONUIDecoderAux<double>::buildUserInterface(ui_interface, memory_block);
    }
    void buildUserInterface(UIGlue* ui_interface, char* memory_block)
    {
        JSONUIDecoderAux<double>::buildUserInterface(ui_interface, memory_block);
    }
    bool hasCompileOption(const std::string& option) { return JSONUIDecoderAux<double>::hasCompileOption(option); }
};

// FAUSTFLOAT decoder

struct JSONUIDecoder : public JSONUIDecoderAux<FAUSTFLOAT>
{
    JSONUIDecoder(const std::string& json):JSONUIDecoderAux<FAUSTFLOAT>(json)
    {}
};

static JSONUITemplatedDecoder* createJSONUIDecoder(const std::string& json)
{
    JSONUIDecoder decoder(json);
    if (decoder.hasCompileOption("-double")) {
        return new JSONUIDoubleDecoder(json);
    } else {
        return new JSONUIFloatDecoder(json);
    }
}

#endif
/**************************  END  JSONUIDecoder.h **************************/
/************************** BEGIN JSONUI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef FAUST_JSONUI_H
#define FAUST_JSONUI_H

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

/************************** BEGIN PathBuilder.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_PATHBUILDER_H
#define FAUST_PATHBUILDER_H

#include <vector>
#include <string>
#include <algorithm>

/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class PathBuilder
{

    protected:
    
        std::vector<std::string> fControlsLevel;
       
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            std::replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
        void pushLabel(const std::string& label) { fControlsLevel.push_back(label); }
        void popLabel() { fControlsLevel.pop_back(); }
    
};

#endif  // FAUST_PATHBUILDER_H
/**************************  END  PathBuilder.h **************************/

/*******************************************************************************
 * JSONUI : Faust User Interface
 * This class produce a complete JSON decription of the DSP instance.
 ******************************************************************************/

template <typename REAL>
class JSONUIAux : public PathBuilder, public Meta, public UIReal<REAL>
{

    protected:
    
        std::stringstream fUI;
        std::stringstream fMeta;
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        std::string fVersion;           // Compiler version
        std::string fCompileOptions;    // Compilation options
        std::vector<std::string> fLibraryList;
        std::vector<std::string> fIncludePathnames;
        std::string fName;
        std::string fFileName;
        std::string fExpandedCode;
        std::string fSHAKey;
        int fDSPSize;                   // In bytes
        std::map<std::string, int> fPathTable;
        bool fExtended;
    
        char fCloseUIPar;
        char fCloseMetaPar;
        int fTab;
    
        int fInputs, fOutputs, fSRIndex;
         
        void tab(int n, std::ostream& fout)
        {
            fout << '\n';
            while (n-- > 0) {
                fout << '\t';
            }
        }
    
        std::string flatten(const std::string& src)
        {
            std::string dst;
            for (size_t i = 0; i < src.size(); i++) {
                switch (src[i]) {
                    case '\n':
                    case '\t':
                        break;
                    default:
                        dst += src[i];
                        break;
                }
            }
            return dst;
        }
    
        void addMeta(int tab_val, bool quote = true)
        {
            if (fMetaAux.size() > 0) {
                tab(tab_val, fUI); fUI << "\"meta\": [";
                std::string sep = "";
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    fUI << sep;
                    tab(tab_val + 1, fUI); fUI << "{ \"" << fMetaAux[i].first << "\": \"" << fMetaAux[i].second << "\" }";
                    sep = ",";
                }
                tab(tab_val, fUI); fUI << ((quote) ? "],": "]");
                fMetaAux.clear();
            }
        }
    
        int getAddressIndex(const std::string& path)
        {
            return (fPathTable.find(path) != fPathTable.end()) ? fPathTable[path] : -1;
        }
      
     public:
     
        JSONUIAux(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  int sr_index,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& compile_options,
                  const std::vector<std::string>& library_list,
                  const std::vector<std::string>& include_pathnames,
                  int size,
                  const std::map<std::string, int>& path_table)
        {
            init(name, filename, inputs, outputs, sr_index, sha_key, dsp_code, version, compile_options, library_list, include_pathnames, size, path_table);
        }

        JSONUIAux(const std::string& name, const std::string& filename, int inputs, int outputs)
        {
            init(name, filename, inputs, outputs, -1, "", "", "", "", std::vector<std::string>(), std::vector<std::string>(), -1, std::map<std::string, int>());
        }

        JSONUIAux(int inputs, int outputs)
        {
            init("", "", inputs, outputs, -1, "", "","", "", std::vector<std::string>(), std::vector<std::string>(), -1, std::map<std::string, int>());
        }
        
        JSONUIAux()
        {
            init("", "", -1, -1, -1, "", "", "", "", std::vector<std::string>(), std::vector<std::string>(), -1, std::map<std::string, int>());
        }
 
        virtual ~JSONUIAux() {}
        
        void setInputs(int inputs) { fInputs = inputs; }
        void setOutputs(int outputs) { fOutputs = outputs; }
    
        void setSRIndex(int sr_index) { fSRIndex = sr_index; }
    
        // Init may be called multiple times so fMeta and fUI are reinitialized
        void init(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  int sr_index,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& compile_options,
                  const std::vector<std::string>& library_list,
                  const std::vector<std::string>& include_pathnames,
                  int size,
                  const std::map<std::string, int>& path_table,
                  bool extended = false)
        {
            fTab = 1;
            fExtended = extended;
            if (fExtended) {
                fUI << std::setprecision(std::numeric_limits<REAL>::max_digits10);
                fMeta << std::setprecision(std::numeric_limits<REAL>::max_digits10);
            }
            
            // Start Meta generation
            fMeta.str("");
            tab(fTab, fMeta); fMeta << "\"meta\": [";
            fCloseMetaPar = ' ';
            
            // Start UI generation
            fUI.str("");
            tab(fTab, fUI); fUI << "\"ui\": [";
            fCloseUIPar = ' ';
            fTab += 1;
            
            fName = name;
            fFileName = filename;
            fInputs = inputs;
            fOutputs = outputs;
            fSRIndex = sr_index;
            fExpandedCode = dsp_code;
            fSHAKey = sha_key;
            fDSPSize = size;
            fPathTable = path_table;
            fVersion = version;
            fCompileOptions = compile_options;
            fLibraryList = library_list;
            fIncludePathnames = include_pathnames;
        }
   
        // -- widget's layouts
    
        virtual void openGenericGroup(const char* label, const char* name)
        {
            pushLabel(label);
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            addMeta(fTab);
            tab(fTab, fUI); fUI << "\"items\": [";
            fCloseUIPar = ' ';
            fTab += 1;
        }

        virtual void openTabBox(const char* label)
        {
            openGenericGroup(label, "tgroup");
        }
    
        virtual void openHorizontalBox(const char* label)
        {
            openGenericGroup(label, "hgroup");
        }
    
        virtual void openVerticalBox(const char* label)
        {
            openGenericGroup(label, "vgroup");
        }
    
        virtual void closeBox()
        {
            popLabel();
            fTab -= 1;
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        // -- active widgets
  
        virtual void addGenericButton(const char* label, const char* name)
        {
            std::string path = buildPath(label);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"address\": \"" << path << "\",";
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path) << ((fMetaAux.size() > 0) ? "," : "");
            } else {
                tab(fTab, fUI); fUI << "\"address\": \"" << path << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            }
            addMeta(fTab, false);
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "button");
        }
    
        virtual void addCheckButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "checkbox");
        }

        virtual void addGenericEntry(const char* label, const char* name, REAL init, REAL min, REAL max, REAL step)
        {
            std::string path = buildPath(label);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            tab(fTab, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path) << ",";
            }
            addMeta(fTab);
            tab(fTab, fUI); fUI << "\"init\": " << init << ",";
            tab(fTab, fUI); fUI << "\"min\": " << min << ",";
            tab(fTab, fUI); fUI << "\"max\": " << max << ",";
            tab(fTab, fUI); fUI << "\"step\": " << step;
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "vslider", init, min, max, step);
        }
    
        virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "hslider", init, min, max, step);
        }
    
        virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "nentry", init, min, max, step);
        }

        // -- passive widgets
    
        virtual void addGenericBargraph(const char* label, const char* name, REAL min, REAL max) 
        {
            std::string path = buildPath(label);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            tab(fTab, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path) << ",";
            }
            addMeta(fTab);
            tab(fTab, fUI); fUI << "\"min\": " << min << ",";
            tab(fTab, fUI); fUI << "\"max\": " << max;
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) 
        {
            addGenericBargraph(label, "hbargraph", min, max);
        }
    
        virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max)
        {
            addGenericBargraph(label, "vbargraph", min, max);
        }
    
        virtual void addSoundfile(const char* label, const char* url, Soundfile** zone)
        {
            std::string path = buildPath(label);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << "soundfile" << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab, fUI); fUI << "\"url\": \"" << url << "\"" << ",";
            tab(fTab, fUI); fUI << "\"address\": \"" << path << "\"" << ((fPathTable.size() > 0) ? "," : "");
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path);
            }
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        // -- metadata declarations

        virtual void declare(REAL* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
    
        // Meta interface
        virtual void declare(const char* key, const char* value)
        {
            fMeta << fCloseMetaPar;
            // fName found in metadata
            if ((strcmp(key, "name") == 0) && (fName == "")) fName = value;
            // fFileName found in metadata
            if ((strcmp(key, "filename") == 0) && (fFileName == "")) fFileName = value;
            tab(fTab, fMeta); fMeta << "{ " << "\"" << key << "\"" << ": " << "\"" << value << "\" }";
            fCloseMetaPar = ',';
        }
    
        std::string JSON(bool flat = false)
        {
            fTab = 0;
            std::stringstream JSON;
            if (fExtended) {
                JSON << std::setprecision(std::numeric_limits<REAL>::max_digits10);
            }
            JSON << "{";
            fTab += 1;
            tab(fTab, JSON); JSON << "\"name\": \"" << fName << "\",";
            tab(fTab, JSON); JSON << "\"filename\": \"" << fFileName << "\",";
            if (fVersion != "") { tab(fTab, JSON); JSON << "\"version\": \"" << fVersion << "\","; }
            if (fCompileOptions != "") { tab(fTab, JSON); JSON << "\"compile_options\": \"" <<  fCompileOptions << "\","; }
            if (fLibraryList.size() > 0) {
                tab(fTab, JSON);
                JSON << "\"library_list\": [";
                for (size_t i = 0; i < fLibraryList.size(); i++) {
                    JSON << "\"" << fLibraryList[i] << "\"";
                    if (i < (fLibraryList.size() - 1)) JSON << ",";
                }
                JSON << "],";
            }
            if (fIncludePathnames.size() > 0) {
                tab(fTab, JSON);
                JSON << "\"include_pathnames\": [";
                for (size_t i = 0; i < fIncludePathnames.size(); i++) {
                    JSON << "\"" << fIncludePathnames[i] << "\"";
                    if (i < (fIncludePathnames.size() - 1)) JSON << ",";
                }
                JSON << "],";
            }
            if (fDSPSize != -1) { tab(fTab, JSON); JSON << "\"size\": " << fDSPSize << ","; }
            if (fSHAKey != "") { tab(fTab, JSON); JSON << "\"sha_key\": \"" << fSHAKey << "\","; }
            if (fExpandedCode != "") { tab(fTab, JSON); JSON << "\"code\": \"" << fExpandedCode << "\","; }
            tab(fTab, JSON); JSON << "\"inputs\": " << fInputs << ",";
            tab(fTab, JSON); JSON << "\"outputs\": " << fOutputs << ",";
            if (fSRIndex != -1) { tab(fTab, JSON); JSON << "\"sr_index\": " << fSRIndex << ","; }
            tab(fTab, fMeta); fMeta << "],";
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            if (fCloseMetaPar == ',') { // If "declare" has been called, fCloseMetaPar state is now ','
                JSON << fMeta.str() << fUI.str();
            } else {
                JSON << fUI.str();
            }
            tab(fTab, JSON); JSON << "}";
            return (flat) ? flatten(JSON.str()) : JSON.str();
        }
    
};

// Externally available class using FAUSTFLOAT

class JSONUI : public JSONUIAux<FAUSTFLOAT>, public UI
{
    public :
    
        JSONUI(const std::string& name,
               const std::string& filename,
               int inputs,
               int outputs,
               int sr_index,
               const std::string& sha_key,
               const std::string& dsp_code,
               const std::string& version,
               const std::string& compile_options,
               const std::vector<std::string>& library_list,
               const std::vector<std::string>& include_pathnames,
               int size,
               const std::map<std::string, int>& path_table):
        JSONUIAux<FAUSTFLOAT>(name, filename,
                              inputs, outputs,
                              sr_index,
                              sha_key, dsp_code,
                              version, compile_options,
                              library_list, include_pathnames,
                              size, path_table)
        {}
        
        JSONUI(const std::string& name, const std::string& filename, int inputs, int outputs):
        JSONUIAux<FAUSTFLOAT>(name, filename, inputs, outputs)
        {}
        
        JSONUI(int inputs, int outputs):JSONUIAux<FAUSTFLOAT>(inputs, outputs)
        {}
        
        JSONUI():JSONUIAux<FAUSTFLOAT>()
        {}
    
        virtual void openTabBox(const char* label)
        {
            JSONUIAux<FAUSTFLOAT>::openTabBox(label);
        }
        virtual void openHorizontalBox(const char* label)
        {
            JSONUIAux<FAUSTFLOAT>::openHorizontalBox(label);
        }
        virtual void openVerticalBox(const char* label)
        {
            JSONUIAux<FAUSTFLOAT>::openVerticalBox(label);
        }
        virtual void closeBox()
        {
            JSONUIAux<FAUSTFLOAT>::closeBox();
        }
        
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            JSONUIAux<FAUSTFLOAT>::addButton(label, zone);
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            JSONUIAux<FAUSTFLOAT>::addCheckButton(label, zone);
        }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            JSONUIAux<FAUSTFLOAT>::addVerticalSlider(label, zone, init, min, max, step);
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            JSONUIAux<FAUSTFLOAT>::addHorizontalSlider(label, zone, init, min, max, step);
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            JSONUIAux<FAUSTFLOAT>::addNumEntry(label, zone, init, min, max, step);
        }
        
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            JSONUIAux<FAUSTFLOAT>::addHorizontalBargraph(label, zone, min, max);
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            JSONUIAux<FAUSTFLOAT>::addVerticalBargraph(label, zone, min, max);
        }
        
        // -- soundfiles
        
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone)
        {
            JSONUIAux<FAUSTFLOAT>::addSoundfile(label, filename, sf_zone);
        }
        
        // -- metadata declarations
        
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            JSONUIAux<FAUSTFLOAT>::declare(zone, key, val);
        }
    
        virtual void declare(const char* key, const char* val)
        {
            JSONUIAux<FAUSTFLOAT>::declare(key, val);
        }
    
        virtual ~JSONUI() {}
    
};

#endif // FAUST_JSONUI_H
/**************************  END  JSONUI.h **************************/

//----------------------------------------------------------------
//  Proxy dsp definition created from the DSP JSON description
//  This class allows a 'proxy' dsp to control a real dsp 
//  possibly running somewhere else.
//----------------------------------------------------------------

class proxy_dsp : public dsp {

    private:
    
        JSONUIDecoder* fDecoder;
        int fSampleRate;
        
    public:
    
        proxy_dsp():fDecoder(nullptr), fSampleRate(-1)
        {}
    
        proxy_dsp(const std::string& json)
        {
            init(json);
        }
    
        void init(const std::string& json)
        {
            fDecoder = new JSONUIDecoder(json);
            fSampleRate = -1;
        }
          
        proxy_dsp(dsp* dsp)
        {
            JSONUI builder(dsp->getNumInputs(), dsp->getNumOutputs());
            dsp->metadata(&builder);
            dsp->buildUserInterface(&builder);
            fSampleRate = dsp->getSampleRate();
            fDecoder = new JSONUIDecoder(builder.JSON());
        }
      
        virtual ~proxy_dsp()
        {
            delete fDecoder;
        }
       
        virtual int getNumInputs() { return fDecoder->fNumInputs; }
        virtual int getNumOutputs() { return fDecoder->fNumOutputs; }
        
        virtual void buildUserInterface(UI* ui) { fDecoder->buildUserInterface(ui); }
        
        // To possibly implement in a concrete proxy dsp 
        virtual void init(int sample_rate)
        {
            instanceInit(sample_rate);
        }
        virtual void instanceInit(int sample_rate)
        {
            instanceConstants(sample_rate);
            instanceResetUserInterface();
            instanceClear();
        }
        virtual void instanceConstants(int sample_rate) { fSampleRate = sample_rate; }
        virtual void instanceResetUserInterface() { fDecoder->resetUserInterface(); }
        virtual void instanceClear() {}
    
        virtual int getSampleRate() { return fSampleRate; }
    
        virtual proxy_dsp* clone() { return new proxy_dsp(fDecoder->fJSON); }
        virtual void metadata(Meta* m) { fDecoder->metadata(m); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {}
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {} 
        
};

#endif
/**************************  END  proxy-dsp.h **************************/
/************************** BEGIN timed-dsp.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __timed_dsp__
#define __timed_dsp__

#include <set>
#include <float.h>
#include <assert.h>

/************************** BEGIN GUI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __GUI_H__
#define __GUI_H__

#include <list>
#include <map>
#include <vector>
#include <iostream>

#ifdef _WIN32
# pragma warning (disable: 4100)
#else
# pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

/************************** BEGIN ring-buffer.h **************************/
/*
  Copyright (C) 2000 Paul Davis
  Copyright (C) 2003 Rohan Drape
  Copyright (C) 2016 GRAME (renaming for internal use)

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

  ISO/POSIX C version of Paul Davis's lock free ringbuffer C++ code.
  This is safe for the case of one read thread and one write thread.
*/

#ifndef __ring_buffer__
#define __ring_buffer__

#include <stdlib.h>
#include <string.h>

#ifdef WIN32
# pragma warning (disable: 4334)
#else
# pragma GCC diagnostic ignored "-Wunused-function"
#endif

typedef struct {
    char *buf;
    size_t len;
}
ringbuffer_data_t;

typedef struct {
    char *buf;
    volatile size_t write_ptr;
    volatile size_t read_ptr;
    size_t	size;
    size_t	size_mask;
    int	mlocked;
}
ringbuffer_t;

static ringbuffer_t *ringbuffer_create(size_t sz);
static void ringbuffer_free(ringbuffer_t *rb);
static void ringbuffer_get_read_vector(const ringbuffer_t *rb,
                                         ringbuffer_data_t *vec);
static void ringbuffer_get_write_vector(const ringbuffer_t *rb,
                                          ringbuffer_data_t *vec);
static size_t ringbuffer_read(ringbuffer_t *rb, char *dest, size_t cnt);
static size_t ringbuffer_peek(ringbuffer_t *rb, char *dest, size_t cnt);
static void ringbuffer_read_advance(ringbuffer_t *rb, size_t cnt);
static size_t ringbuffer_read_space(const ringbuffer_t *rb);
static int ringbuffer_mlock(ringbuffer_t *rb);
static void ringbuffer_reset(ringbuffer_t *rb);
static void ringbuffer_reset_size (ringbuffer_t * rb, size_t sz);
static size_t ringbuffer_write(ringbuffer_t *rb, const char *src,
                                 size_t cnt);
static void ringbuffer_write_advance(ringbuffer_t *rb, size_t cnt);
static size_t ringbuffer_write_space(const ringbuffer_t *rb);

/* Create a new ringbuffer to hold at least `sz' bytes of data. The
   actual buffer size is rounded up to the next power of two. */

static ringbuffer_t *
ringbuffer_create (size_t sz)
{
	size_t power_of_two;
	ringbuffer_t *rb;

	if ((rb = (ringbuffer_t *) malloc (sizeof (ringbuffer_t))) == NULL) {
		return NULL;
	}

	for (power_of_two = 1u; 1u << power_of_two < sz; power_of_two++);

	rb->size = 1u << power_of_two;
	rb->size_mask = rb->size;
	rb->size_mask -= 1;
	rb->write_ptr = 0;
	rb->read_ptr = 0;
	if ((rb->buf = (char *) malloc (rb->size)) == NULL) {
		free (rb);
		return NULL;
	}
	rb->mlocked = 0;

	return rb;
}

/* Free all data associated with the ringbuffer `rb'. */

static void
ringbuffer_free (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (rb->mlocked) {
		munlock (rb->buf, rb->size);
	}
#endif /* USE_MLOCK */
	free (rb->buf);
	free (rb);
}

/* Lock the data block of `rb' using the system call 'mlock'.  */

static int
ringbuffer_mlock (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (mlock (rb->buf, rb->size)) {
		return -1;
	}
#endif /* USE_MLOCK */
	rb->mlocked = 1;
	return 0;
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

static void
ringbuffer_reset (ringbuffer_t * rb)
{
	rb->read_ptr = 0;
	rb->write_ptr = 0;
    memset(rb->buf, 0, rb->size);
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

static void
ringbuffer_reset_size (ringbuffer_t * rb, size_t sz)
{
    rb->size = sz;
    rb->size_mask = rb->size;
    rb->size_mask -= 1;
    rb->read_ptr = 0;
    rb->write_ptr = 0;
}

/* Return the number of bytes available for reading. This is the
   number of bytes in front of the read pointer and behind the write
   pointer.  */

static size_t
ringbuffer_read_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return w - r;
	} else {
		return (w - r + rb->size) & rb->size_mask;
	}
}

/* Return the number of bytes available for writing. This is the
   number of bytes in front of the write pointer and behind the read
   pointer.  */

static size_t
ringbuffer_write_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		return (r - w) - 1;
	} else {
		return rb->size - 1;
	}
}

/* The copying data reader. Copy at most `cnt' bytes from `rb' to
   `dest'.  Returns the actual number of bytes copied. */

static size_t
ringbuffer_read (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[rb->read_ptr]), n1);
	rb->read_ptr = (rb->read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[rb->read_ptr]), n2);
		rb->read_ptr = (rb->read_ptr + n2) & rb->size_mask;
	}

	return to_read;
}

/* The copying data reader w/o read pointer advance. Copy at most
   `cnt' bytes from `rb' to `dest'.  Returns the actual number of bytes
   copied. */

static size_t
ringbuffer_peek (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;
	size_t tmp_read_ptr;

	tmp_read_ptr = rb->read_ptr;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = tmp_read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - tmp_read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[tmp_read_ptr]), n1);
	tmp_read_ptr = (tmp_read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[tmp_read_ptr]), n2);
	}

	return to_read;
}

/* The copying data writer. Copy at most `cnt' bytes to `rb' from
   `src'.  Returns the actual number of bytes copied. */

static size_t
ringbuffer_write (ringbuffer_t * rb, const char *src, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_write;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_write_space (rb)) == 0) {
		return 0;
	}

	to_write = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->write_ptr + to_write;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->write_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_write;
		n2 = 0;
	}

	memcpy (&(rb->buf[rb->write_ptr]), src, n1);
	rb->write_ptr = (rb->write_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (&(rb->buf[rb->write_ptr]), src + n1, n2);
		rb->write_ptr = (rb->write_ptr + n2) & rb->size_mask;
	}

	return to_write;
}

/* Advance the read pointer `cnt' places. */

static void
ringbuffer_read_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->read_ptr + cnt) & rb->size_mask;
	rb->read_ptr = tmp;
}

/* Advance the write pointer `cnt' places. */

static void
ringbuffer_write_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->write_ptr + cnt) & rb->size_mask;
	rb->write_ptr = tmp;
}

/* The non-copying data reader. `vec' is an array of two places. Set
   the values at `vec' to hold the current readable data at `rb'. If
   the readable data is in one segment the second segment has zero
   length. */

static void
ringbuffer_get_read_vector (const ringbuffer_t * rb,
				 ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = w - r;
	} else {
		free_cnt = (w - r + rb->size) & rb->size_mask;
	}

	cnt2 = r + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = rb->size - r;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;

	} else {

		/* Single part vector: just the rest of the buffer */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

/* The non-copying data writer. `vec' is an array of two places. Set
   the values at `vec' to hold the current writeable data at `rb'. If
   the writeable data is in one segment the second segment has zero
   length. */

static void
ringbuffer_get_write_vector (const ringbuffer_t * rb,
				  ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		free_cnt = (r - w) - 1;
	} else {
		free_cnt = rb->size - 1;
	}

	cnt2 = w + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[w]);
		vec[0].len = rb->size - w;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;
	} else {
		vec[0].buf = &(rb->buf[w]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

#endif // __ring_buffer__
/**************************  END  ring-buffer.h **************************/

/*******************************************************************************
 * GUI : Abstract Graphic User Interface
 * Provides additional mechanisms to synchronize widgets and zones. Widgets
 * should both reflect the value of a zone and allow to change this value.
 ******************************************************************************/

class uiItem;
class GUI;
struct clist;

typedef void (*uiCallback)(FAUSTFLOAT val, void* data);

struct uiItemBase
{
    
    uiItemBase(GUI* ui, FAUSTFLOAT* zone) {}
    
    virtual ~uiItemBase()
    {}
    
    virtual void modifyZone(FAUSTFLOAT v) = 0;
    virtual void modifyZone(double date, FAUSTFLOAT v) {}
    virtual double cache() = 0;
    virtual void reflectZone() = 0;
};


static void deleteClist(clist* cl);

struct clist : public std::list<uiItemBase*>
{
    
    virtual ~clist()
    {
        deleteClist(this);
    }
        
};

static void createUiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data);

typedef std::map<FAUSTFLOAT*, clist*> zmap;

typedef std::map<FAUSTFLOAT*, ringbuffer_t*> ztimedmap;

class GUI : public UI
{
		
    private:
     
        static std::list<GUI*> fGuiList;
        zmap fZoneMap;
        bool fStopped;
        
     public:
            
        GUI():fStopped(false)
        {	
            fGuiList.push_back(this);
        }
        
        virtual ~GUI() 
        {   
            // delete all items
            zmap::iterator it;
            for (it = fZoneMap.begin(); it != fZoneMap.end(); it++) {
                delete (*it).second;
            }
            // suppress 'this' in static fGuiList
            fGuiList.remove(this);
        }

        // -- registerZone(z,c) : zone management
        
        void registerZone(FAUSTFLOAT* z, uiItemBase* c)
        {
            if (fZoneMap.find(z) == fZoneMap.end()) fZoneMap[z] = new clist();
            fZoneMap[z]->push_back(c);
        }
 
        void updateAllZones()
        {
            for (zmap::iterator m = fZoneMap.begin(); m != fZoneMap.end(); m++) {
                FAUSTFLOAT* z = m->first;
                clist* l = m->second;
                if (z) {
                    FAUSTFLOAT v = *z;
                    for (clist::iterator c = l->begin(); c != l->end(); c++) {
                        if ((*c)->cache() != v) (*c)->reflectZone();
                    }
                }
            }
        }
        
        void updateZone(FAUSTFLOAT* z)
        {
            FAUSTFLOAT v = *z;
            clist* l = fZoneMap[z];
            for (clist::iterator c = l->begin(); c != l->end(); c++) {
                if ((*c)->cache() != v) (*c)->reflectZone();
            }
        }
    
        static void updateAllGuis()
        {
            std::list<GUI*>::iterator g;
            for (g = fGuiList.begin(); g != fGuiList.end(); g++) {
                (*g)->updateAllZones();
            }
        }
    
        void addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data)
        {
            createUiCallbackItem(this, zone, foo, data);
        }

        virtual void show() {};	
        virtual bool run() { return false; };

        static void runAllGuis() {
            std::list<GUI*>::iterator g;
            for (g = fGuiList.begin(); g != fGuiList.end(); g++) {
                (*g)->run();
            }
        }
    
        virtual void stop() { fStopped = true; }
        bool stopped() { return fStopped; }
    
        // -- widget's layouts
        
        virtual void openTabBox(const char* label) {};
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
    
        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
    
        // Static global for timed zones, shared between all UI that will set timed values
        static ztimedmap gTimedZoneMap;

};

/**
 * User Interface Item: abstract definition
 */

template <typename REAL>
class uiTypedItem : public uiItemBase
{
    protected:
        
        GUI* fGUI;
        REAL* fZone;
        REAL fCache;
        
        uiTypedItem(GUI* ui, REAL* zone):uiItemBase(ui, static_cast<FAUSTFLOAT*>(zone)),
        fGUI(ui), fZone(zone), fCache(REAL(-123456.654321))
        {
            ui->registerZone(zone, this);
        }
        
    public:
        
        virtual ~uiTypedItem()
        {}
    
        void modifyZone(REAL v)
        {
            fCache = v;
            if (*fZone != v) {
                *fZone = v;
                fGUI->updateZone(fZone);
            }
        }
    
        double cache() { return fCache; }
    
};

class uiItem : public uiTypedItem<FAUSTFLOAT> {
    
    protected:
    
        uiItem(GUI* ui, FAUSTFLOAT* zone):uiTypedItem<FAUSTFLOAT>(ui, zone)
        {}

    public:

        virtual ~uiItem() 
        {}

		void modifyZone(FAUSTFLOAT v)
		{
			fCache = v;
			if (*fZone != v) {
				*fZone = v;
				fGUI->updateZone(fZone);
			}
		}

};

/**
 * User Interface item owned (and so deleted) by external code
 */

class uiOwnedItem : public uiItem {
    
    protected:
    
        uiOwnedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
    
     public:
    
        virtual ~uiOwnedItem()
        {}
    
        virtual void reflectZone() {}
};

/**
 * Callback Item
 */

class uiCallbackItem : public uiItem {
    
    protected:
    
        uiCallback fCallback;
        void* fData;
    
    public:
    
        uiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data)
        : uiItem(ui, zone), fCallback(foo), fData(data) {}
        
        virtual void reflectZone() 
        {		
            FAUSTFLOAT v = *fZone;
            fCache = v; 
            fCallback(v, fData);	
        }
};

/**
 *  For timestamped control
 */

struct DatedControl {
    
    double fDate;
    FAUSTFLOAT fValue;
    
    DatedControl(double d = 0., FAUSTFLOAT v = FAUSTFLOAT(0)):fDate(d), fValue(v) {}
    
};

/**
 * Base class for timed items
 */

class uiTimedItem : public uiItem
{
    
    protected:
        
        bool fDelete;
        
    public:
    
        using uiItem::modifyZone;
        
        uiTimedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {
            if (GUI::gTimedZoneMap.find(fZone) == GUI::gTimedZoneMap.end()) {
                GUI::gTimedZoneMap[fZone] = ringbuffer_create(8192);
                fDelete = true;
            } else {
                fDelete = false;
            }
        }
        
        virtual ~uiTimedItem()
        {
            ztimedmap::iterator it;
            if (fDelete && ((it = GUI::gTimedZoneMap.find(fZone)) != GUI::gTimedZoneMap.end())) {
                ringbuffer_free((*it).second);
                GUI::gTimedZoneMap.erase(it);
            }
        }
        
        virtual void modifyZone(double date, FAUSTFLOAT v)
        {
            size_t res;
            DatedControl dated_val(date, v);
            if ((res = ringbuffer_write(GUI::gTimedZoneMap[fZone], (const char*)&dated_val, sizeof(DatedControl))) != sizeof(DatedControl)) {
                std::cerr << "ringbuffer_write error DatedControl" << std::endl;
            }
        }
    
};

/**
 * Allows to group a set of zones
 */

class uiGroupItem : public uiItem
{
    protected:
    
        std::vector<FAUSTFLOAT*> fZoneMap;

    public:
    
        uiGroupItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
        virtual ~uiGroupItem() 
        {}
        
        virtual void reflectZone() 
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            
            // Update all zones of the same group
            std::vector<FAUSTFLOAT*>::iterator it;
            for (it = fZoneMap.begin(); it != fZoneMap.end(); it++) {
                (*(*it)) = v;
            }
        }
        
        void addZone(FAUSTFLOAT* zone) { fZoneMap.push_back(zone); }

};

// Can not be defined as method in the classes

static void createUiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data)
{
    new uiCallbackItem(ui, zone, foo, data);
}

static void deleteClist(clist* cl)
{
    std::list<uiItemBase*>::iterator it;
    for (it = cl->begin(); it != cl->end(); it++) {
        uiOwnedItem* owned = dynamic_cast<uiOwnedItem*>(*it);
        // owned items are deleted by external code
        if (!owned) {
            delete (*it);
        }
    }
}

#endif
/**************************  END  GUI.h **************************/
/************************** BEGIN DecoratorUI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef Decorator_UI_H
#define Decorator_UI_H


//----------------------------------------------------------------
//  Generic UI empty implementation
//----------------------------------------------------------------

class GenericUI : public UI
{
    
    public:
        
        GenericUI() {}
        virtual ~GenericUI() {}
        
        // -- widget's layouts
        virtual void openTabBox(const char* label) {}
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* soundpath, Soundfile** sf_zone) {}
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) {}
    
};

//----------------------------------------------------------------
//  Generic UI decorator
//----------------------------------------------------------------

class DecoratorUI : public UI
{
    
    protected:
        
        UI* fUI;
        
    public:
        
        DecoratorUI(UI* ui = 0):fUI(ui) {}
        virtual ~DecoratorUI() { delete fUI; }
        
        // -- widget's layouts
        virtual void openTabBox(const char* label)          { fUI->openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fUI->openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fUI->openVerticalBox(label); }
        virtual void closeBox()                             { fUI->closeBox(); }
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)         { fUI->addButton(label, zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)    { fUI->addCheckButton(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addVerticalSlider(label, zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addHorizontalSlider(label, zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addNumEntry(label, zone, init, min, max, step); }
        
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addHorizontalBargraph(label, zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addVerticalBargraph(label, zone, min, max); }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) { fUI->addSoundfile(label, filename, sf_zone); }
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }
    
};

#endif
/**************************  END  DecoratorUI.h **************************/

namespace {
    
#if __APPLE__
#if TARGET_OS_IPHONE
    //inline double GetCurrentTimeInUsec() { return double(CAHostTimeBase::GetCurrentTimeInNanos()) / 1000.; }
    // TODO
    inline double GetCurrentTimeInUsec() { return 0.0; }
#else
    #include <CoreAudio/HostTime.h>
    inline double GetCurrentTimeInUsec() { return double(AudioConvertHostTimeToNanos(AudioGetCurrentHostTime())) / 1000.; }
#endif
#endif

#if __linux__
#include <sys/time.h>
inline double GetCurrentTimeInUsec() 
{
    struct timeval tv;
    (void)gettimeofday(&tv, (struct timezone *)NULL);
    return double((tv.tv_sec * 1000000) + tv.tv_usec);
}
#endif

#if _WIN32
#include <windows.h>
inline double GetCurrentTimeInUsec(void)
{
    LARGE_INTEGER time;
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&time);
    return double(time.QuadPart) / double(frequency.QuadPart) * 1000000.0;
}
#endif
    
}

/**
 * ZoneUI : this class collect zones in a set.
 */

struct ZoneUI : public GenericUI
{
    
    std::set<FAUSTFLOAT*> fZoneSet;
    
    ZoneUI():GenericUI() {}
    virtual ~ZoneUI() {}
    
    void insertZone(FAUSTFLOAT* zone) 
    { 
        if (GUI::gTimedZoneMap.find(zone) != GUI::gTimedZoneMap.end()) {
            fZoneSet.insert(zone);
        } 
    }
    
    // -- active widgets
    void addButton(const char* label, FAUSTFLOAT* zone)
    {
        insertZone(zone);
    }
    void addCheckButton(const char* label, FAUSTFLOAT* zone)
    {
        insertZone(zone);
    }
    void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
    {
        insertZone(zone);
    }
    void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
    {
        insertZone(zone);
    }
    void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
    {
        insertZone(zone);
    }
    
    // -- passive widgets
    void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
    {
        insertZone(zone);
    }
    void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
    {
        insertZone(zone);
    }
  
};

/**
 * Timed signal processor that allows to handle the decorated DSP by 'slices'
 * that is, calling the 'compute' method several times and changing control
 * parameters between slices.
 */

class timed_dsp : public decorator_dsp {

    protected:
        
        double fDateUsec;       // Compute call date in usec
        double fOffsetUsec;     // Compute call offset in usec
        bool fFirstCallback;
        ZoneUI fZoneUI;
    
        FAUSTFLOAT** fInputsSlice;
        FAUSTFLOAT** fOutputsSlice;
    
        void computeSlice(int offset, int slice, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) 
        {
            if (slice > 0) {
                for (int chan = 0; chan < fDSP->getNumInputs(); chan++) {
                    fInputsSlice[chan] = &(inputs[chan][offset]);
                }
                for (int chan = 0; chan < fDSP->getNumOutputs(); chan++) {
                    fOutputsSlice[chan] = &(outputs[chan][offset]);
                }
                fDSP->compute(slice, fInputsSlice, fOutputsSlice);
            } 
        }
        
        double convertUsecToSample(double usec)
        {
            return std::max<double>(0., (double(getSampleRate()) * (usec - fDateUsec)) / 1000000.);
        }
        
        ztimedmap::iterator getNextControl(DatedControl& res)
        {
            DatedControl date1(DBL_MAX, 0);
            ztimedmap::iterator it1, it2 = GUI::gTimedZoneMap.end();
            std::set<FAUSTFLOAT*>::iterator it3;
              
            // Find date of next audio slice to compute
            for (it3 = fZoneUI.fZoneSet.begin(); it3 != fZoneUI.fZoneSet.end(); it3++) {
                // If value list is not empty, get the date and keep the minimal one
                it1 = GUI::gTimedZoneMap.find(*it3);
                if (it1 != GUI::gTimedZoneMap.end()) { // Check if zone still in global GUI::gTimedZoneMap (since MidiUI may have been desallocated)
                    DatedControl date2;
                    if (ringbuffer_peek((*it1).second, (char*)&date2, sizeof(DatedControl)) == sizeof(DatedControl) 
                        && date2.fDate < date1.fDate) {
                        it2 = it1;
                        date1 = date2;
                    }
                }
            }
            
            res = date1;
            return it2;
        }
        
        virtual void computeAux(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs, bool convert_ts)
        {
            int slice, offset = 0;
            ztimedmap::iterator it;
            DatedControl next_control;
             
            // Do audio computation "slice" by "slice"
            while ((it = getNextControl(next_control)) != GUI::gTimedZoneMap.end()) {
                
                // If needed, convert next_control in samples from begining of the buffer, possible moving to 0 (if negative)
                if (convert_ts) {
                    next_control.fDate = convertUsecToSample(next_control.fDate);
                }
                     
                // Compute audio slice
                slice = int(next_control.fDate) - offset;
                computeSlice(offset, slice, inputs, outputs);
                offset += slice;
               
                // Update control
                ringbuffer_t* control_values = (*it).second;
                *((*it).first) = next_control.fValue;
                
                // Move ringbuffer pointer
                ringbuffer_read_advance(control_values, sizeof(DatedControl));
            } 
            
            // Compute last audio slice
            slice = count - offset;
            computeSlice(offset, slice, inputs, outputs);
        }

    public:

        timed_dsp(dsp* dsp):decorator_dsp(dsp), fDateUsec(0), fOffsetUsec(0), fFirstCallback(true)
        {
            fInputsSlice = new FAUSTFLOAT*[dsp->getNumInputs()];
            fOutputsSlice = new FAUSTFLOAT*[dsp->getNumOutputs()];
        }
        virtual ~timed_dsp() 
        {
            delete [] fInputsSlice;
            delete [] fOutputsSlice;
        }
        
        virtual void init(int sample_rate)
        {
            fDSP->init(sample_rate);
        }
        
        virtual void buildUserInterface(UI* ui_interface)   
        { 
            fDSP->buildUserInterface(ui_interface); 
            // Only keep zones that are in GUI::gTimedZoneMap
            fDSP->buildUserInterface(&fZoneUI);
        }
    
        virtual timed_dsp* clone()
        {
            return new timed_dsp(fDSP->clone());
        }
    
        // Default method take a timestamp at 'compute' call time
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            compute(::GetCurrentTimeInUsec(), count, inputs, outputs);
        }    
        
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            if (date_usec == -1) {
                // Timestamp is expressed in frames
                computeAux(count, inputs, outputs, false);
            } else {
                // Save the timestamp offset in the first callback
                if (fFirstCallback) {
                    fFirstCallback = false;
                    double current_date_usec = ::GetCurrentTimeInUsec();
                    fDateUsec = current_date_usec;
                    fOffsetUsec = current_date_usec - date_usec;
                }
                
                // RtMidi mode: timestamp must be converted in frames
                computeAux(count, inputs, outputs, true);
                
                // Keep call date 
                fDateUsec = date_usec + fOffsetUsec;
            }
        }
        
};

#endif
/**************************  END  timed-dsp.h **************************/
/************************** BEGIN dsp-adapter.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp_adapter__
#define __dsp_adapter__

#include <string.h>
#include <iostream>


// Adapts a DSP for a different number of inputs/outputs

class dsp_adapter : public decorator_dsp {
    
    private:
        
        FAUSTFLOAT** fAdaptedInputs;
        FAUSTFLOAT** fAdaptedOutputs;
        int fHardwareInputs;
        int fHardwareOutputs;
        
        void adaptBuffers(FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            for (int i = 0; i < fHardwareInputs; i++) {
                fAdaptedInputs[i] = inputs[i];
            }
            for (int i = 0; i < fHardwareOutputs; i++) {
                fAdaptedOutputs[i] = outputs[i];
            }
        }
        
    public:
        
        dsp_adapter(dsp* dsp, int hardware_inputs, int hardware_outputs, int buffer_size):decorator_dsp(dsp)
        {
            fHardwareInputs = hardware_inputs;
            fHardwareOutputs = hardware_outputs;
             
            fAdaptedInputs = new FAUSTFLOAT*[dsp->getNumInputs()];
            for (int i = 0; i < dsp->getNumInputs() - fHardwareInputs; i++) {
                fAdaptedInputs[i + fHardwareInputs] = new FAUSTFLOAT[buffer_size];
                memset(fAdaptedInputs[i + fHardwareInputs], 0, sizeof(FAUSTFLOAT) * buffer_size);
            }
            
            fAdaptedOutputs = new FAUSTFLOAT*[dsp->getNumOutputs()];
            for (int i = 0; i < dsp->getNumOutputs() - fHardwareOutputs; i++) {
                fAdaptedOutputs[i + fHardwareOutputs] = new FAUSTFLOAT[buffer_size];
                memset(fAdaptedOutputs[i + fHardwareOutputs], 0, sizeof(FAUSTFLOAT) * buffer_size);
            }
        }
        
        virtual ~dsp_adapter()
        {
            for (int i = 0; i < fDSP->getNumInputs() - fHardwareInputs; i++) {
                delete [] fAdaptedInputs[i + fHardwareInputs];
            }
            delete [] fAdaptedInputs;
            
            for (int i = 0; i < fDSP->getNumOutputs() - fHardwareOutputs; i++) {
                delete [] fAdaptedOutputs[i + fHardwareOutputs];
            }
            delete [] fAdaptedOutputs;
        }
    
        virtual int getNumInputs() { return fHardwareInputs; }
        virtual int getNumOutputs() { return fHardwareOutputs; }
    
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            adaptBuffers(inputs, outputs);
            fDSP->compute(date_usec, count, fAdaptedInputs, fAdaptedOutputs);
        }
        
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            adaptBuffers(inputs, outputs);
            fDSP->compute(count, fAdaptedInputs, fAdaptedOutputs);
        }
};

// Adapts a DSP for a different sample size

template <typename TYPE_INT, typename TYPE_EXT>
class dsp_sample_adapter : public decorator_dsp {
    
    protected:
    
        TYPE_INT** fAdaptedInputs;
        TYPE_INT** fAdaptedOutputs;
    
        void adaptInputBuffers(int count, FAUSTFLOAT** inputs)
        {
            for (int chan = 0; chan < fDSP->getNumInputs(); chan++) {
                for (int frame = 0; frame < count; frame++) {
                    fAdaptedInputs[chan][frame] = TYPE_INT(reinterpret_cast<TYPE_EXT**>(inputs)[chan][frame]);
                }
            }
        }
    
        void adaptOutputsBuffers(int count, FAUSTFLOAT** outputs)
        {
            for (int chan = 0; chan < fDSP->getNumOutputs(); chan++) {
                for (int frame = 0; frame < count; frame++) {
                    reinterpret_cast<TYPE_EXT**>(outputs)[chan][frame] = TYPE_EXT(fAdaptedOutputs[chan][frame]);
                }
            }
        }
    
    public:
    
        dsp_sample_adapter(dsp* dsp):decorator_dsp(dsp)
        {
            fAdaptedInputs = new TYPE_INT*[dsp->getNumInputs()];
            for (int i = 0; i < dsp->getNumInputs(); i++) {
                fAdaptedInputs[i] = new TYPE_INT[4096];
            }
            
            fAdaptedOutputs = new TYPE_INT*[dsp->getNumOutputs()];
            for (int i = 0; i < dsp->getNumOutputs(); i++) {
                fAdaptedOutputs[i] = new TYPE_INT[4096];
            }
        }
    
        virtual ~dsp_sample_adapter()
        {
            for (int i = 0; i < fDSP->getNumInputs(); i++) {
                delete [] fAdaptedInputs[i];
            }
            delete [] fAdaptedInputs;
            
            for (int i = 0; i < fDSP->getNumOutputs(); i++) {
                delete [] fAdaptedOutputs[i];
            }
            delete [] fAdaptedOutputs;
        }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            adaptInputBuffers(count, inputs);
            // DSP base class uses FAUSTFLOAT** type, so reinterpret_cast has to be used even if the real DSP uses TYPE_INT
            fDSP->compute(count, reinterpret_cast<FAUSTFLOAT**>(fAdaptedInputs), reinterpret_cast<FAUSTFLOAT**>(fAdaptedOutputs));
            adaptOutputsBuffers(count, outputs);
        }
    
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            adaptInputBuffers(count, inputs);
            // DSP base class uses FAUSTFLOAT** type, so reinterpret_cast has to be used even if the real DSP uses TYPE_INT
            fDSP->compute(date_usec, count, reinterpret_cast<FAUSTFLOAT**>(fAdaptedInputs), reinterpret_cast<FAUSTFLOAT**>(fAdaptedOutputs));
            adaptOutputsBuffers(count, outputs);
       }
};

#endif
/**************************  END  dsp-adapter.h **************************/
/************************** BEGIN FUI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_FUI_H
#define FAUST_FUI_H

#include <string>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <iostream>
#include <fstream>


/*******************************************************************************
 * FUI : used to save and recall the state of the user interface
 * This class provides essentially two new methods saveState() and recallState()
 * used to save on file and recall from file the state of the user interface.
 * The file is human readable and editable
 ******************************************************************************/

class FUI : public UI, public PathBuilder
{

    protected:

        std::map<std::string, FAUSTFLOAT*> fName2Zone;
        std::vector<FAUSTFLOAT*> fButtons;

        // add an element by relating its full name and memory zone
        virtual void addElement(const char* label, FAUSTFLOAT* zone, bool button = false)
        {
            std::string path = buildPath(label);
            fName2Zone[path] = zone;
            if (button) {
                fButtons.push_back(zone);
            }
        }

    
    public:

        FUI() {}
        virtual ~FUI() {}

        // -- Save and recall methods

        // save the zones values and full names
        virtual void saveState(const char* filename)
        {
            std::ofstream file(filename);
            std::map<std::string, FAUSTFLOAT*>::iterator it;
            
            if (file.is_open()) {
                for (it = fName2Zone.begin(); it != fName2Zone.end(); ++it) {
                    file << *(*it).second << ' ' << (*it).first << std::endl;
                }

                file << std::endl;
                file.close();
            } else {
                 std::cerr << "Error opening " << filename << " file\n";
            }
        }

        // recall the zones values and full names
        virtual void recallState(const char* filename)
        {
            std::ifstream file(filename);
            FAUSTFLOAT value;
            std::string path1, path2;
            while (file.good()) {
                file >> value >> path1;
                path2 = "/" + path1;
                if (fName2Zone.count(path1) > 0) {          // Old path system
                    *(fName2Zone[path1]) = value;
                } else if (fName2Zone.count(path2) > 0) {   // New path system with the starting '/'
                    *(fName2Zone[path2]) = value;
                } else if (path1.size() > 0) {
                    std::cerr << "recallState : parameter not found : " << path1 << " with value : " << value << std::endl;
                }
            }
            file.close();
        }

        void setButtons(bool state)
        {
            for (size_t i = 0; i < fButtons.size(); i++) {
                *fButtons[i] = state;
            }
        }

        // -- widget's layouts (just keep track of group labels)

        virtual void openTabBox(const char* label) { pushLabel(label); }
        virtual void openHorizontalBox(const char* label) { pushLabel(label);; }
        virtual void openVerticalBox(const char* label) { pushLabel(label); }
        virtual void closeBox() { popLabel(); };

        // -- active widgets (just add an element)

        virtual void addButton(const char* label, FAUSTFLOAT* zone) { addElement(label, zone, true); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) { addElement(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT)
                                                                    { addElement(label, zone); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT)
                                                                    { addElement(label, zone); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT)
                                                                    { addElement(label, zone); }

        // -- passive widgets (are ignored)

        virtual void addHorizontalBargraph(const char*, FAUSTFLOAT*, FAUSTFLOAT, FAUSTFLOAT) {};
        virtual void addVerticalBargraph(const char*, FAUSTFLOAT*, FAUSTFLOAT, FAUSTFLOAT) {};
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}

        // -- metadata are not used

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}

};

#endif

/**************************  END  FUI.h **************************/
/************************** BEGIN PresetUI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __PresetUI_H__
#define __PresetUI_H__

#include <string>
#include <iostream>
#include <sstream>


class PresetUI;

struct LoaderUI : public GUI
{
    PresetUI* fPresetUI;
    
    LoaderUI(PresetUI* presetui);
        
};

class PresetUI : public DecoratorUI
{
    friend LoaderUI;
		
    private:
    
        int fGroupCount;
        FAUSTFLOAT fPreset;
        FAUSTFLOAT fLoad;
        FAUSTFLOAT fSave;
        FAUSTFLOAT fReset;
        FUI fFileUI;
        LoaderUI fLoaderUI;
        std::string fRootFolder;
    
        static void load(FAUSTFLOAT val, void* arg)
        {
            if (val == FAUSTFLOAT(1)) {
                static_cast<PresetUI*>(arg)->loadState();
            }
        }
    
        static void save(FAUSTFLOAT val, void* arg)
        {
            if (val == FAUSTFLOAT(1)) {
                static_cast<PresetUI*>(arg)->saveState();
            }
        }
    
        static void reset(FAUSTFLOAT val, void* arg)
        {
            if (val == FAUSTFLOAT(1)) {
                static_cast<PresetUI*>(arg)->loadDefault();
            }
        }
    
        void checkOpenFirstBox(const char* label)
        {
            if (fGroupCount++ == 0) {
                // Start of top-level group
                fUI->openHorizontalBox("Preset manager");
                fUI->addButton("Save", &fSave);
                fUI->addNumEntry("Preset", &fPreset, FAUSTFLOAT(0),FAUSTFLOAT(0), FAUSTFLOAT(100), FAUSTFLOAT(1));
                fUI->addButton("Load", &fLoad);
                fUI->addButton("Reset", &fReset);
                fUI->closeBox();
            }
        }
    
    public:
    
        PresetUI(UI* ui, const std::string& root_folfer):
            DecoratorUI(ui),
            fGroupCount(0),
            fPreset(FAUSTFLOAT(0)),
            fSave(FAUSTFLOAT(0)),
            fLoad(FAUSTFLOAT(0)),
            fReset(FAUSTFLOAT(0)),
            fLoaderUI(this),
            fRootFolder(root_folfer)
        {}
    
        virtual ~PresetUI()
        {}
    
        void saveDefault()
        {
            std::stringstream str;
            str << fRootFolder << "_default";
            fFileUI.saveState(str.str().c_str());
        }
        
        void loadDefault()
        {
            std::stringstream str;
            str << fRootFolder << "_default";
            fFileUI.recallState(str.str().c_str());
        }
    
        void saveState()
        {
            std::stringstream str;
            str << fRootFolder << "_preset" << int(fPreset);
            fFileUI.saveState(str.str().c_str());
        }
    
        void loadState()
        {
            std::stringstream str;
            str << fRootFolder << "_preset" << int(fPreset);
            fFileUI.recallState(str.str().c_str());
        }
    
        // -- widget's layouts
        virtual void openTabBox(const char* label)
        {
            checkOpenFirstBox(label);
            fUI->openTabBox(label);
            fFileUI.openTabBox(label);
        }
        virtual void openHorizontalBox(const char* label)
        {
            checkOpenFirstBox(label);
            fUI->openHorizontalBox(label);
            fFileUI.openHorizontalBox(label);
        }
        virtual void openVerticalBox(const char* label)
        {
            checkOpenFirstBox(label);
            fUI->openVerticalBox(label);
            fFileUI.openVerticalBox(label);
        }
        virtual void closeBox()
        {
            fUI->closeBox();
            if (--fGroupCount == 0) {
                // End of top-level group
                saveDefault();
            }
        }
    
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            fUI->addButton(label, zone);
            fFileUI.addButton(label, zone);
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            fUI->addCheckButton(label, zone);
            fFileUI.addCheckButton(label, zone);
        }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            fUI->addVerticalSlider(label, zone, init, min, max, step);
            fFileUI.addVerticalSlider(label, zone, init, min, max, step);
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            fUI->addHorizontalSlider(label, zone, init, min, max, step);
            fFileUI.addHorizontalSlider(label, zone, init, min, max, step);
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            fUI->addNumEntry(label, zone, init, min, max, step);
            fFileUI.addNumEntry(label, zone, init, min, max, step);
        }
        
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            fUI->addHorizontalBargraph(label, zone, min, max);
            fFileUI.addHorizontalBargraph(label, zone, min, max);
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            fUI->addVerticalBargraph(label, zone, min, max);
            fFileUI.addVerticalBargraph(label, zone, min, max);
        }
        
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone)
        {
            fUI->addSoundfile(label, filename, sf_zone);
            fFileUI.addSoundfile(label, filename, sf_zone);
        }
        
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            fUI->declare(zone, key, val);
            fFileUI.declare(zone, key, val);
        }

};

LoaderUI::LoaderUI(PresetUI* presetui)
{
    new uiCallbackItem(this, &presetui->fLoad, PresetUI::load, presetui);
    new uiCallbackItem(this, &presetui->fSave, PresetUI::save, presetui);
    new uiCallbackItem(this, &presetui->fReset, PresetUI::reset, presetui);
}

#endif
/**************************  END  PresetUI.h **************************/
/************************** BEGIN QTUI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __QTUI__
#define __QTUI__

#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <stack>

#if defined(HTTPCTRL) && defined(QRCODECTRL)

#ifdef _WIN32
# include <winsock2.h>
# undef min
# undef max
# pragma warning (disable: 4100)
#else
# include <netdb.h>
# include <arpa/inet.h>
# include <unistd.h>
#endif

#include <QtNetwork>

#endif

#include <QtGlobal>
#include <QtGui>
#if QT_VERSION >= 0x050000
#include <QtWidgets>
#endif
#include <QApplication>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <sstream>

/************************** BEGIN ValueConverter.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __ValueConverter__
#define __ValueConverter__

/***************************************************************************************
								ValueConverter.h
							    (GRAME, © 2015)

Set of conversion objects used to map user interface values (for example a gui slider
delivering values between 0 and 1) to faust values (for example a vslider between
20 and 20000) using a log scale.

-- Utilities

Range(lo,hi) : clip a value x between lo and hi
Interpolator(lo,hi,v1,v2) : Maps a value x between lo and hi to a value y between v1 and v2
Interpolator3pt(lo,mi,hi,v1,vm,v2) : Map values between lo mid hi to values between v1 vm v2

-- Value Converters

ValueConverter::ui2faust(x)
ValueConverter::faust2ui(x)

-- ValueConverters used for sliders depending of the scale

LinearValueConverter(umin, umax, fmin, fmax)
LogValueConverter(umin, umax, fmin, fmax)
ExpValueConverter(umin, umax, fmin, fmax)

-- ValueConverters used for accelerometers based on 3 points

AccUpConverter(amin, amid, amax, fmin, fmid, fmax)		-- curve 0
AccDownConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 1
AccUpDownConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 2
AccDownUpConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 3

-- lists of ZoneControl are used to implement accelerometers metadata for each axes

ZoneControl(zone, valueConverter) : a zone with an accelerometer data converter

-- ZoneReader are used to implement screencolor metadata

ZoneReader(zone, valueConverter) : a zone with a data converter

****************************************************************************************/

#include <float.h>
#include <algorithm>    // std::max
#include <cmath>
#include <vector>
#include <assert.h>

//--------------------------------------------------------------------------------------
// Interpolator(lo,hi,v1,v2)
// Maps a value x between lo and hi to a value y between v1 and v2
// y = v1 + (x-lo)/(hi-lo)*(v2-v1)
// y = v1 + (x-lo) * coef   		with coef = (v2-v1)/(hi-lo)
// y = v1 + x*coef - lo*coef
// y = v1 - lo*coef + x*coef
// y = offset + x*coef				with offset = v1 - lo*coef
//--------------------------------------------------------------------------------------
class Interpolator
{
    private:

        //--------------------------------------------------------------------------------------
        // Range(lo,hi) clip a value between lo and hi
        //--------------------------------------------------------------------------------------
        struct Range
        {
            double fLo;
            double fHi;

            Range(double x, double y) : fLo(std::min<double>(x,y)), fHi(std::max<double>(x,y)) {}
            double operator()(double x) { return (x<fLo) ? fLo : (x>fHi) ? fHi : x; }
        };


        Range fRange;
        double fCoef;
        double fOffset;

    public:

        Interpolator(double lo, double hi, double v1, double v2) : fRange(lo,hi)
        {
            if (hi != lo) {
                // regular case
                fCoef = (v2-v1)/(hi-lo);
                fOffset = v1 - lo*fCoef;
            } else {
                // degenerate case, avoids division by zero
                fCoef = 0;
                fOffset = (v1+v2)/2;
            }
        }
        double operator()(double v)
        {
            double x = fRange(v);
            return  fOffset + x*fCoef;
        }

        void getLowHigh(double& amin, double& amax)
        {
            amin = fRange.fLo;
            amax = fRange.fHi;
        }
};

//--------------------------------------------------------------------------------------
// Interpolator3pt(lo,mi,hi,v1,vm,v2)
// Map values between lo mid hi to values between v1 vm v2
//--------------------------------------------------------------------------------------
class Interpolator3pt
{

    private:

        Interpolator fSegment1;
        Interpolator fSegment2;
        double fMid;

    public:

        Interpolator3pt(double lo, double mi, double hi, double v1, double vm, double v2) :
            fSegment1(lo, mi, v1, vm),
            fSegment2(mi, hi, vm, v2),
            fMid(mi) {}
        double operator()(double x) { return  (x < fMid) ? fSegment1(x) : fSegment2(x); }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fSegment1.getLowHigh(amin, amid);
            fSegment2.getLowHigh(amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Abstract ValueConverter class. Converts values between UI and Faust representations
//--------------------------------------------------------------------------------------
class ValueConverter
{

    public:

        virtual ~ValueConverter() {}
        virtual double ui2faust(double x) = 0;
        virtual double faust2ui(double x) = 0;
};

//--------------------------------------------------------------------------------------
// Linear conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class LinearValueConverter : public ValueConverter
{

    private:

        Interpolator fUI2F;
        Interpolator fF2UI;

    public:

        LinearValueConverter(double umin, double umax, double fmin, double fmax) :
            fUI2F(umin,umax,fmin,fmax), fF2UI(fmin,fmax,umin,umax)
        {}

        LinearValueConverter() :
            fUI2F(0.,0.,0.,0.), fF2UI(0.,0.,0.,0.)
        {}
        virtual double ui2faust(double x) {	return fUI2F(x); }
        virtual double faust2ui(double x) {	return fF2UI(x); }

};

//--------------------------------------------------------------------------------------
// Logarithmic conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class LogValueConverter : public LinearValueConverter
{

    public:

        LogValueConverter(double umin, double umax, double fmin, double fmax) :
        LinearValueConverter(umin, umax, log(std::max<double>(DBL_MIN, fmin)), std::log(std::max<double>(DBL_MIN, fmax)))
        {}

        virtual double ui2faust(double x) 	{ return std::exp(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x)	{ return LinearValueConverter::faust2ui(std::log(std::max<double>(x, DBL_MIN))); }

};

//--------------------------------------------------------------------------------------
// Exponential conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class ExpValueConverter : public LinearValueConverter
{

    public:

        ExpValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, exp(fmin), exp(fmax))
        {}

        virtual double ui2faust(double x) { return std::log(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x) { return LinearValueConverter::faust2ui(std::exp(x)); }

};

//--------------------------------------------------------------------------------------
// A converter than can be updated
//--------------------------------------------------------------------------------------

class UpdatableValueConverter : public ValueConverter {

    protected:

        bool fActive;

    public:

        UpdatableValueConverter():fActive(true)
        {}
        virtual ~UpdatableValueConverter()
        {}

        virtual void setMappingValues(double amin, double amid, double amax, double min, double init, double max) = 0;
        virtual void getMappingValues(double& amin, double& amid, double& amax) = 0;

        void setActive(bool on_off) { fActive = on_off; }
        bool getActive() { return fActive; }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up curve (curve 0)
//--------------------------------------------------------------------------------------
class AccUpConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt fA2F;
        Interpolator3pt fF2A;

    public:

        AccUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmid,fmax),
            fF2A(fmin,fmid,fmax,amin,amid,amax)
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmin,fmid,fmax);
            fF2A = Interpolator3pt(fmin,fmid,fmax,amin,amid,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down curve (curve 1)
//--------------------------------------------------------------------------------------
class AccDownConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator3pt	fF2A;

    public:

        AccDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmid,fmin),
            fF2A(fmin,fmid,fmax,amax,amid,amin)
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmax,fmid,fmin);
            fF2A = Interpolator3pt(fmin,fmid,fmax,amax,amid,amin);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up-Down curve (curve 2)
//--------------------------------------------------------------------------------------
class AccUpDownConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccUpDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmax,fmin),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotone function
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmin,fmax,fmin);
            fF2A = Interpolator(fmin,fmax,amin,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down-Up curve (curve 3)
//--------------------------------------------------------------------------------------
class AccDownUpConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccDownUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmin,fmax),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotone function
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmax,fmin,fmax);
            fF2A = Interpolator(fmin,fmax,amin,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Base class for ZoneControl
//--------------------------------------------------------------------------------------
class ZoneControl
{

    protected:

        FAUSTFLOAT*	fZone;

    public:

        ZoneControl(FAUSTFLOAT* zone) : fZone(zone) {}
        virtual ~ZoneControl() {}

        virtual void update(double v) {}

        virtual void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max) {}
        virtual void getMappingValues(double& amin, double& amid, double& amax) {}

        FAUSTFLOAT* getZone() { return fZone; }

        virtual void setActive(bool on_off) {}
        virtual bool getActive() { return false; }

        virtual int getCurve() { return -1; }

};

//--------------------------------------------------------------------------------------
//  Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class ConverterZoneControl : public ZoneControl
{

    private:

        ValueConverter* fValueConverter;

    public:

        ConverterZoneControl(FAUSTFLOAT* zone, ValueConverter* valueConverter) : ZoneControl(zone), fValueConverter(valueConverter) {}
        virtual ~ConverterZoneControl() { delete fValueConverter; } // Assuming fValueConverter is not kept elsewhere...

        void update(double v) { *fZone = fValueConverter->ui2faust(v); }

        ValueConverter* getConverter() { return fValueConverter; }

};

//--------------------------------------------------------------------------------------
// Association of a zone and a four value converter, each one for each possible curve.
// Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class CurveZoneControl : public ZoneControl
{

    private:

        std::vector<UpdatableValueConverter*> fValueConverters;
        int fCurve;

    public:

        CurveZoneControl(FAUSTFLOAT* zone, int curve, double amin, double amid, double amax, double min, double init, double max) : ZoneControl(zone), fCurve(0)
        {
            assert(curve >= 0 && curve <= 3);
            fValueConverters.push_back(new AccUpConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccUpDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownUpConverter(amin, amid, amax, min, init, max));
            fCurve = curve;
        }
        virtual ~CurveZoneControl()
        {
            std::vector<UpdatableValueConverter*>::iterator it;
            for (it = fValueConverters.begin(); it != fValueConverters.end(); it++) {
                delete(*it);
            }
        }
        void update(double v) { if (fValueConverters[fCurve]->getActive()) *fZone = fValueConverters[fCurve]->ui2faust(v); }

        void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max)
        {
            fValueConverters[curve]->setMappingValues(amin, amid, amax, min, init, max);
            fCurve = curve;
        }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fValueConverters[fCurve]->getMappingValues(amin, amid, amax);
        }

        void setActive(bool on_off)
        {
            std::vector<UpdatableValueConverter*>::iterator it;
            for (it = fValueConverters.begin(); it != fValueConverters.end(); it++) {
                (*it)->setActive(on_off);
            }
        }

        int getCurve() { return fCurve; }
};

class ZoneReader
{

    private:

        FAUSTFLOAT* fZone;
        Interpolator fInterpolator;

    public:

        ZoneReader(FAUSTFLOAT* zone, double lo, double hi) : fZone(zone), fInterpolator(lo, hi, 0, 255) {}

        virtual ~ZoneReader() {}

        int getValue()
        {
            if (fZone != 0) {
                return (int)fInterpolator(*fZone);
            } else {
                return 127;
            }
        }

};

#endif
/**************************  END  ValueConverter.h **************************/
/************************** BEGIN MetaDataUI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef MetaData_UI_H
#define MetaData_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <map>
#include <set>
#include <string>
#include <assert.h>


static bool startWith(const std::string& str, const std::string& prefix)
{
    return (str.substr(0, prefix.size()) == prefix);
}

/**
 * Convert a dB value into a scale between 0 and 1 (following IEC standard ?)
 */
static FAUSTFLOAT dB2Scale(FAUSTFLOAT dB)
{
    FAUSTFLOAT scale = FAUSTFLOAT(1.0);
    
    /*if (dB < -70.0f)
     scale = 0.0f;
     else*/
    if (dB < FAUSTFLOAT(-60.0))
        scale = (dB + FAUSTFLOAT(70.0)) * FAUSTFLOAT(0.0025);
    else if (dB < FAUSTFLOAT(-50.0))
        scale = (dB + FAUSTFLOAT(60.0)) * FAUSTFLOAT(0.005) + FAUSTFLOAT(0.025);
    else if (dB < FAUSTFLOAT(-40.0))
        scale = (dB + FAUSTFLOAT(50.0)) * FAUSTFLOAT(0.0075) + FAUSTFLOAT(0.075);
    else if (dB < FAUSTFLOAT(-30.0))
        scale = (dB + FAUSTFLOAT(40.0)) * FAUSTFLOAT(0.015) + FAUSTFLOAT(0.15);
    else if (dB < FAUSTFLOAT(-20.0))
        scale = (dB + FAUSTFLOAT(30.0)) * FAUSTFLOAT(0.02) + FAUSTFLOAT(0.3);
    else if (dB < FAUSTFLOAT(-0.001) || dB > FAUSTFLOAT(0.001))  /* if (dB < 0.0) */
        scale = (dB + FAUSTFLOAT(20.0)) * FAUSTFLOAT(0.025) + FAUSTFLOAT(0.5);
    
    return scale;
}

/*******************************************************************************
 * MetaDataUI : Common class for MetaData handling
 ******************************************************************************/

//============================= BEGIN GROUP LABEL METADATA===========================
// Unlike widget's label, metadata inside group's label are not extracted directly by
// the Faust compiler. Therefore they must be extracted within the architecture file
//-----------------------------------------------------------------------------------

class MetaDataUI {
    
    protected:
        
        std::string                         fGroupTooltip;
        std::map<FAUSTFLOAT*, FAUSTFLOAT>   fGuiSize;            // map widget zone with widget size coef
        std::map<FAUSTFLOAT*, std::string>  fTooltip;            // map widget zone with tooltip strings
        std::map<FAUSTFLOAT*, std::string>  fUnit;               // map widget zone to unit string (i.e. "dB")
        std::map<FAUSTFLOAT*, std::string>  fRadioDescription;   // map zone to {'low':440; ...; 'hi':1000.0}
        std::map<FAUSTFLOAT*, std::string>  fMenuDescription;    // map zone to {'low':440; ...; 'hi':1000.0}
        std::set<FAUSTFLOAT*>               fKnobSet;            // set of widget zone to be knobs
        std::set<FAUSTFLOAT*>               fLedSet;             // set of widget zone to be LEDs
        std::set<FAUSTFLOAT*>               fNumSet;             // set of widget zone to be numerical bargraphs
        std::set<FAUSTFLOAT*>               fLogSet;             // set of widget zone having a log UI scale
        std::set<FAUSTFLOAT*>               fExpSet;             // set of widget zone having an exp UI scale
        std::set<FAUSTFLOAT*>               fHiddenSet;          // set of hidden widget zone
        
        void clearMetadata()
        {
            fGuiSize.clear();
            fTooltip.clear();
            fUnit.clear();
            fRadioDescription.clear();
            fMenuDescription.clear();
            fKnobSet.clear();
            fLedSet.clear();
            fNumSet.clear();
            fLogSet.clear();
            fExpSet.clear();
            fHiddenSet.clear();
        }
        
        /**
         * rmWhiteSpaces(): Remove the leading and trailing white spaces of a string
         * (but not those in the middle of the string)
         */
        static std::string rmWhiteSpaces(const std::string& s)
        {
            size_t i = s.find_first_not_of(" \t");
            size_t j = s.find_last_not_of(" \t");
            if ((i != std::string::npos) && (j != std::string::npos)) {
                return s.substr(i, 1+j-i);
            } else {
                return "";
            }
        }
        
        /**
         * Format tooltip string by replacing some white spaces by
         * return characters so that line width doesn't exceed n.
         * Limitation : long words exceeding n are not cut
         */
        std::string formatTooltip(int n, const std::string& tt)
        {
            std::string ss = tt;  // ss string we are going to format
            int lws = 0;          // last white space encountered
            int lri = 0;          // last return inserted
            for (int i = 0; i < (int)tt.size(); i++) {
                if (tt[i] == ' ') lws = i;
                if (((i-lri) >= n) && (lws > lri)) {
                    // insert return here
                    ss[lws] = '\n';
                    lri = lws;
                }
            }
            return ss;
        }
        
    public:
        
        virtual ~MetaDataUI()
        {}
        
        enum Scale {
            kLin,
            kLog,
            kExp
        };
        
        Scale getScale(FAUSTFLOAT* zone)
        {
            if (fLogSet.count(zone) > 0) return kLog;
            if (fExpSet.count(zone) > 0) return kExp;
            return kLin;
        }
        
        bool isKnob(FAUSTFLOAT* zone)
        {
            return fKnobSet.count(zone) > 0;
        }
        
        bool isRadio(FAUSTFLOAT* zone)
        {
            return fRadioDescription.count(zone) > 0;
        }
        
        bool isMenu(FAUSTFLOAT* zone)
        {
            return fMenuDescription.count(zone) > 0;
        }
        
        bool isLed(FAUSTFLOAT* zone)
        {
            return fLedSet.count(zone) > 0;
        }
        
        bool isNumerical(FAUSTFLOAT* zone)
        {
            return fNumSet.count(zone) > 0;
        }
        
        bool isHidden(FAUSTFLOAT* zone)
        {
            return fHiddenSet.count(zone) > 0;
        }
        
        /**
         * Extracts metadata from a label : 'vol [unit: dB]' -> 'vol' + metadata(unit=dB)
         */
        static void extractMetadata(const std::string& fulllabel, std::string& label, std::map<std::string, std::string>& metadata)
        {
            enum {kLabel, kEscape1, kEscape2, kEscape3, kKey, kValue};
            int state = kLabel; int deep = 0;
            std::string key, value;
            
            for (unsigned int i = 0; i < fulllabel.size(); i++) {
                char c = fulllabel[i];
                switch (state) {
                    case kLabel :
                        assert(deep == 0);
                        switch (c) {
                            case '\\' : state = kEscape1; break;
                            case '[' : state = kKey; deep++; break;
                            default : label += c;
                        }
                        break;
                        
                    case kEscape1:
                        label += c;
                        state = kLabel;
                        break;
                        
                    case kEscape2:
                        key += c;
                        state = kKey;
                        break;
                        
                    case kEscape3:
                        value += c;
                        state = kValue;
                        break;
                        
                    case kKey:
                        assert(deep > 0);
                        switch (c) {
                            case '\\':
                                state = kEscape2;
                                break;
                                
                            case '[':
                                deep++;
                                key += c;
                                break;
                                
                            case ':':
                                if (deep == 1) {
                                    state = kValue;
                                } else {
                                    key += c;
                                }
                                break;
                            case ']':
                                deep--;
                                if (deep < 1) {
                                    metadata[rmWhiteSpaces(key)] = "";
                                    state = kLabel;
                                    key="";
                                    value="";
                                } else {
                                    key += c;
                                }
                                break;
                            default : key += c;
                        }
                        break;
                        
                    case kValue:
                        assert(deep > 0);
                        switch (c) {
                            case '\\':
                                state = kEscape3;
                                break;
                                
                            case '[':
                                deep++;
                                value += c;
                                break;
                                
                            case ']':
                                deep--;
                                if (deep < 1) {
                                    metadata[rmWhiteSpaces(key)] = rmWhiteSpaces(value);
                                    state = kLabel;
                                    key = "";
                                    value = "";
                                } else {
                                    value += c;
                                }
                                break;
                            default : value += c;
                        }
                        break;
                        
                    default:
                        std::cerr << "ERROR unrecognized state " << state << std::endl;
                }
            }
            label = rmWhiteSpaces(label);
        }
        
        /**
         * Analyses the widget zone metadata declarations and takes appropriate actions
         */
        void declare(FAUSTFLOAT* zone, const char* key, const char* value)
        {
            if (zone == 0) {
                // special zone 0 means group metadata
                if (strcmp(key, "tooltip") == 0) {
                    // only group tooltip are currently implemented
                    fGroupTooltip = formatTooltip(30, value);
                } else if (strcmp(key, "hidden") == 0) {
                    fHiddenSet.insert(zone);
                }
            } else {
                if (strcmp(key, "size") == 0) {
                    fGuiSize[zone] = atof(value);
                }
                else if (strcmp(key, "tooltip") == 0) {
                    fTooltip[zone] = formatTooltip(30, value);
                }
                else if (strcmp(key, "unit") == 0) {
                    fUnit[zone] = value;
                }
                else if (strcmp(key, "hidden") == 0) {
                    fHiddenSet.insert(zone);
                }
                else if (strcmp(key, "scale") == 0) {
                    if (strcmp(value, "log") == 0) {
                        fLogSet.insert(zone);
                    } else if (strcmp(value, "exp") == 0) {
                        fExpSet.insert(zone);
                    }
                }
                else if (strcmp(key, "style") == 0) {
                    if (strcmp(value, "knob") == 0) {
                        fKnobSet.insert(zone);
                    } else if (strcmp(value, "led") == 0) {
                        fLedSet.insert(zone);
                    } else if (strcmp(value, "numerical") == 0) {
                        fNumSet.insert(zone);
                    } else {
                        const char* p = value;
                        if (parseWord(p, "radio")) {
                            fRadioDescription[zone] = std::string(p);
                        } else if (parseWord(p, "menu")) {
                            fMenuDescription[zone] = std::string(p);
                        }
                    }
                }
            }
        }
    
};

#endif
/**************************  END  MetaDataUI.h **************************/

#if defined(HTTPCTRL) && defined(QRCODECTRL)
/************************** BEGIN qrcodegen.h **************************/
/* 
 * QR Code generator library (C)
 * 
 * Copyright (c) Project Nayuki. (MIT License)
 * https://www.nayuki.io/page/qr-code-generator-library
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * - The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 * - The Software is provided "as is", without warranty of any kind, express or
 *   implied, including but not limited to the warranties of merchantability,
 *   fitness for a particular purpose and noninfringement. In no event shall the
 *   authors or copyright holders be liable for any claim, damages or other
 *   liability, whether in an action of contract, tort or otherwise, arising from,
 *   out of or in connection with the Software or the use or other dealings in the
 *   Software.
 */

#ifndef qrcodegen_h
#define qrcodegen_h

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef WIN32
# pragma warning (disable: 4100)
#else
# pragma GCC diagnostic ignored "-Wunused-function"
#endif

/*---- Enum and struct types----*/

/* 
 * The error correction level used in a QR Code symbol.
 */
enum qrcodegen_Ecc {
	qrcodegen_Ecc_LOW = 0,
	qrcodegen_Ecc_MEDIUM,
	qrcodegen_Ecc_QUARTILE,
	qrcodegen_Ecc_HIGH,
};


/* 
 * The mask pattern used in a QR Code symbol.
 */
enum qrcodegen_Mask {
	// A special value to tell the QR Code encoder to
	// automatically select an appropriate mask pattern
	qrcodegen_Mask_AUTO = -1,
	// The eight actual mask patterns
	qrcodegen_Mask_0 = 0,
	qrcodegen_Mask_1,
	qrcodegen_Mask_2,
	qrcodegen_Mask_3,
	qrcodegen_Mask_4,
	qrcodegen_Mask_5,
	qrcodegen_Mask_6,
	qrcodegen_Mask_7,
};


/* 
 * The mode field of a segment.
 */
enum qrcodegen_Mode {
	qrcodegen_Mode_NUMERIC,
	qrcodegen_Mode_ALPHANUMERIC,
	qrcodegen_Mode_BYTE,
	qrcodegen_Mode_KANJI,
	qrcodegen_Mode_ECI,
};


/* 
 * A segment of user/application data that a QR Code symbol can convey.
 * Each segment has a mode, a character count, and character/general data that is
 * already encoded as a sequence of bits. The maximum allowed bit length is 32767,
 * because even the largest QR Code (version 40) has only 31329 modules.
 */
struct qrcodegen_Segment {
	// The mode indicator for this segment.
	enum qrcodegen_Mode mode;
	
	// The length of this segment's unencoded data. Always in the range [0, 32767].
	// For numeric, alphanumeric, and kanji modes, this measures in Unicode code points.
	// For byte mode, this measures in bytes (raw binary data, text in UTF-8, or other encodings).
	// For ECI mode, this is always zero.
	int numChars;
	
	// The data bits of this segment, packed in bitwise big endian.
	// Can be null if the bit length is zero.
	uint8_t *data;
	
	// The number of valid data bits used in the buffer. Requires
	// 0 <= bitLength <= 32767, and bitLength <= (capacity of data array) * 8.
	int bitLength;
};



/*---- Macro constants and functions ----*/

// The minimum and maximum defined QR Code version numbers for Model 2.
#define qrcodegen_VERSION_MIN  1
#define qrcodegen_VERSION_MAX  40

// Calculates the number of bytes needed to store any QR Code up to and including the given version number,
// as a compile-time constant. For example, 'uint8_t buffer[qrcodegen_BUFFER_LEN_FOR_VERSION(25)];'
// can store any single QR Code from version 1 to 25, inclusive.
// Requires qrcodegen_VERSION_MIN <= n <= qrcodegen_VERSION_MAX.
#define qrcodegen_BUFFER_LEN_FOR_VERSION(n)  ((((n) * 4 + 17) * ((n) * 4 + 17) + 7) / 8 + 1)

// The worst-case number of bytes needed to store one QR Code, up to and including
// version 40. This value equals 3918, which is just under 4 kilobytes.
// Use this more convenient value to avoid calculating tighter memory bounds for buffers.
#define qrcodegen_BUFFER_LEN_MAX  qrcodegen_BUFFER_LEN_FOR_VERSION(qrcodegen_VERSION_MAX)

#ifdef __cplusplus
extern "C" {
#endif

/*---- Functions to generate QR Codes ----*/

/* 
 * Encodes the given text string to a QR Code symbol, returning true if encoding succeeded.
 * If the data is too long to fit in any version in the given range
 * at the given ECC level, then false is returned.
 * - The input text must be encoded in UTF-8 and contain no NULs.
 * - The variables ecl and mask must correspond to enum constant values.
 * - Requires 1 <= minVersion <= maxVersion <= 40.
 * - The arrays tempBuffer and qrcode must each have a length
 *   of at least qrcodegen_BUFFER_LEN_FOR_VERSION(maxVersion).
 * - After the function returns, tempBuffer contains no useful data.
 * - If successful, the resulting QR Code may use numeric,
 *   alphanumeric, or byte mode to encode the text.
 * - In the most optimistic case, a QR Code at version 40 with low ECC
 *   can hold any UTF-8 string up to 2953 bytes, or any alphanumeric string
 *   up to 4296 characters, or any digit string up to 7089 characters.
 *   These numbers represent the hard upper limit of the QR Code standard.
 * - Please consult the QR Code specification for information on
 *   data capacities per version, ECC level, and text encoding mode.
 */
static bool qrcodegen_encodeText(const char *text, uint8_t tempBuffer[], uint8_t qrcode[],
	enum qrcodegen_Ecc ecl, int minVersion, int maxVersion, enum qrcodegen_Mask mask, bool boostEcl);


/* 
 * Encodes the given binary data to a QR Code symbol, returning true if encoding succeeded.
 * If the data is too long to fit in any version in the given range
 * at the given ECC level, then false is returned.
 * - The input array range dataAndTemp[0 : dataLen] should normally be
 *   valid UTF-8 text, but is not required by the QR Code standard.
 * - The variables ecl and mask must correspond to enum constant values.
 * - Requires 1 <= minVersion <= maxVersion <= 40.
 * - The arrays dataAndTemp and qrcode must each have a length
 *   of at least qrcodegen_BUFFER_LEN_FOR_VERSION(maxVersion).
 * - After the function returns, the contents of dataAndTemp may have changed,
 *   and does not represent useful data anymore.
 * - If successful, the resulting QR Code will use byte mode to encode the data.
 * - In the most optimistic case, a QR Code at version 40 with low ECC can hold any byte
 *   sequence up to length 2953. This is the hard upper limit of the QR Code standard.
 * - Please consult the QR Code specification for information on
 *   data capacities per version, ECC level, and text encoding mode.
 */
static bool qrcodegen_encodeBinary(uint8_t dataAndTemp[], size_t dataLen, uint8_t qrcode[],
	enum qrcodegen_Ecc ecl, int minVersion, int maxVersion, enum qrcodegen_Mask mask, bool boostEcl);


/* 
 * Tests whether the given string can be encoded as a segment in alphanumeric mode.
 */
static bool qrcodegen_isAlphanumeric(const char *text);


/* 
 * Tests whether the given string can be encoded as a segment in numeric mode.
 */
static bool qrcodegen_isNumeric(const char *text);


/* 
 * Returns the number of bytes (uint8_t) needed for the data buffer of a segment
 * containing the given number of characters using the given mode. Notes:
 * - Returns SIZE_MAX on failure, i.e. numChars > INT16_MAX or
 *   the number of needed bits exceeds INT16_MAX (i.e. 32767).
 * - Otherwise, all valid results are in the range [0, ceil(INT16_MAX / 8)], i.e. at most 4096.
 * - It is okay for the user to allocate more bytes for the buffer than needed.
 * - For byte mode, numChars measures the number of bytes, not Unicode code points.
 * - For ECI mode, numChars must be 0, and the worst-case number of bytes is returned.
 *   An actual ECI segment can have shorter data. For non-ECI modes, the result is exact.
 */
static size_t qrcodegen_calcSegmentBufferSize(enum qrcodegen_Mode mode, size_t numChars);


/* 
 * Returns a segment representing the given binary data encoded in byte mode.
 */
static struct qrcodegen_Segment qrcodegen_makeBytes(const uint8_t data[], size_t len, uint8_t buf[]);


/* 
 * Returns a segment representing the given string of decimal digits encoded in numeric mode.
 */
static struct qrcodegen_Segment qrcodegen_makeNumeric(const char *digits, uint8_t buf[]);


/* 
 * Returns a segment representing the given text string encoded in alphanumeric mode.
 * The characters allowed are: 0 to 9, A to Z (uppercase only), space,
 * dollar, percent, asterisk, plus, hyphen, period, slash, colon.
 */
static struct qrcodegen_Segment qrcodegen_makeAlphanumeric(const char *text, uint8_t buf[]);


/* 
 * Returns a segment representing an Extended Channel Interpretation
 * (ECI) designator with the given assignment value.
 */
static struct qrcodegen_Segment qrcodegen_makeEci(long assignVal, uint8_t buf[]);


/* 
 * Renders a QR Code symbol representing the given data segments at the given error correction
 * level or higher. The smallest possible QR Code version is automatically chosen for the output.
 * Returns true if QR Code creation succeeded, or false if the data is too long to fit in any version.
 * This function allows the user to create a custom sequence of segments that switches
 * between modes (such as alphanumeric and binary) to encode text more efficiently.
 * This function is considered to be lower level than simply encoding text or binary data.
 * To save memory, the segments' data buffers can alias/overlap tempBuffer, and will
 * result in them being clobbered, but the QR Code output will still be correct.
 * But the qrcode array must not overlap tempBuffer or any segment's data buffer.
 */
static bool qrcodegen_encodeSegments(const struct qrcodegen_Segment segs[], size_t len,
	enum qrcodegen_Ecc ecl, uint8_t tempBuffer[], uint8_t qrcode[]);


/* 
 * Renders a QR Code symbol representing the given data segments with the given encoding parameters.
 * Returns true if QR Code creation succeeded, or false if the data is too long to fit in the range of versions.
 * The smallest possible QR Code version within the given range is automatically chosen for the output.
 * This function allows the user to create a custom sequence of segments that switches
 * between modes (such as alphanumeric and binary) to encode text more efficiently.
 * This function is considered to be lower level than simply encoding text or binary data.
 * To save memory, the segments' data buffers can alias/overlap tempBuffer, and will
 * result in them being clobbered, but the QR Code output will still be correct.
 * But the qrcode array must not overlap tempBuffer or any segment's data buffer.
 */
static bool qrcodegen_encodeSegmentsAdvanced(const struct qrcodegen_Segment segs[], size_t len, enum qrcodegen_Ecc ecl,
	int minVersion, int maxVersion, int mask, bool boostEcl, uint8_t tempBuffer[], uint8_t qrcode[]);


/*---- Functions to extract raw data from QR Codes ----*/

/* 
 * Returns the side length of the given QR Code, assuming that encoding succeeded.
 * The result is in the range [21, 177]. Note that the length of the array buffer
 * is related to the side length - every 'uint8_t qrcode[]' must have length at least
 * qrcodegen_BUFFER_LEN_FOR_VERSION(version), which equals ceil(size^2 / 8 + 1).
 */
static int qrcodegen_getSize(const uint8_t qrcode[]);


/* 
 * Returns the color of the module (pixel) at the given coordinates, which is either
 * false for white or true for black. The top left corner has the coordinates (x=0, y=0).
 * If the given coordinates are out of bounds, then false (white) is returned.
 */
static bool qrcodegen_getModule(const uint8_t qrcode[], int x, int y);

#ifdef __cplusplus
}
#endif

// includes the implementation
/************************** BEGIN qrcodegen.impl.h **************************/
/* 
 * QR Code generator library (C)
 * 
 * Copyright (c) Project Nayuki. (MIT License)
 * https://www.nayuki.io/page/qr-code-generator-library
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * - The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 * - The Software is provided "as is", without warranty of any kind, express or
 *   implied, including but not limited to the warranties of merchantability,
 *   fitness for a particular purpose and noninfringement. In no event shall the
 *   authors or copyright holders be liable for any claim, damages or other
 *   liability, whether in an action of contract, tort or otherwise, arising from,
 *   out of or in connection with the Software or the use or other dealings in the
 *   Software.
 */

#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#ifndef QRCODEGEN_TEST
	#define testable static  // Keep functions private
#else
	// Expose private functions
	#ifndef __cplusplus
		#define testable
	#else
		// Needed for const variables because they are treated as implicitly 'static' in C++
		#define testable extern
	#endif
#endif


/*---- Forward declarations for private functions ----*/

// Regarding all public and private functions defined in this source file:
// - They require all pointer/array arguments to be not null.
// - They only read input scalar/array arguments, write to output pointer/array
//   arguments, and return scalar values; they are "pure" functions.
// - They don't read mutable global variables or write to any global variables.
// - They don't perform I/O, read the clock, print to console, etc.
// - They allocate a small and constant amount of stack memory.
// - They don't allocate or free any memory on the heap.
// - They don't recurse or mutually recurse. All the code
//   could be inlined into the top-level public functions.
// - They run in at most quadratic time with respect to input arguments.
//   Most functions run in linear time, and some in constant time.
//   There are no unbounded loops or non-obvious termination conditions.
// - They are completely thread-safe if the caller does not give the
//   same writable buffer to concurrent calls to these functions.

testable void appendBitsToBuffer(unsigned int val, int numBits, uint8_t buffer[], int *bitLen);

testable void appendErrorCorrection(uint8_t data[], int version, enum qrcodegen_Ecc ecl, uint8_t result[]);
testable int getNumDataCodewords(int version, enum qrcodegen_Ecc ecl);
testable int getNumRawDataModules(int version);

testable void calcReedSolomonGenerator(int degree, uint8_t result[]);
testable void calcReedSolomonRemainder(const uint8_t data[], int dataLen,
	const uint8_t generator[], int degree, uint8_t result[]);
testable uint8_t finiteFieldMultiply(uint8_t x, uint8_t y);

testable void initializeFunctionModules(int version, uint8_t qrcode[]);
static void drawWhiteFunctionModules(uint8_t qrcode[], int version);
static void drawFormatBits(enum qrcodegen_Ecc ecl, enum qrcodegen_Mask mask, uint8_t qrcode[]);
testable int getAlignmentPatternPositions(int version, uint8_t result[7]);
static void fillRectangle(int left, int top, int width, int height, uint8_t qrcode[]);

static void drawCodewords(const uint8_t data[], int dataLen, uint8_t qrcode[]);
static void applyMask(const uint8_t functionModules[], uint8_t qrcode[], enum qrcodegen_Mask mask);
static long getPenaltyScore(const uint8_t qrcode[]);

testable bool getModule(const uint8_t qrcode[], int x, int y);
testable void setModule(uint8_t qrcode[], int x, int y, bool isBlack);
testable void setModuleBounded(uint8_t qrcode[], int x, int y, bool isBlack);

testable int calcSegmentBitLength(enum qrcodegen_Mode mode, size_t numChars);
testable int getTotalBits(const struct qrcodegen_Segment segs[], size_t len, int version);
static int numCharCountBits(enum qrcodegen_Mode mode, int version);



/*---- Private tables of constants ----*/

// For checking text and encoding segments.
static const char *ALPHANUMERIC_CHARSET = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";

// For generating error correction codes.
testable const int8_t ECC_CODEWORDS_PER_BLOCK[4][41] = {
	// Version: (note that index 0 is for padding, and is set to an illegal value)
	//0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40    Error correction level
	{-1,  7, 10, 15, 20, 26, 18, 20, 24, 30, 18, 20, 24, 26, 30, 22, 24, 28, 30, 28, 28, 28, 28, 30, 30, 26, 28, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30},  // Low
	{-1, 10, 16, 26, 18, 24, 16, 18, 22, 22, 26, 30, 22, 22, 24, 24, 28, 28, 26, 26, 26, 26, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28},  // Medium
	{-1, 13, 22, 18, 26, 18, 24, 18, 22, 20, 24, 28, 26, 24, 20, 30, 24, 28, 28, 26, 30, 28, 30, 30, 30, 30, 28, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30},  // Quartile
	{-1, 17, 28, 22, 16, 22, 28, 26, 26, 24, 28, 24, 28, 22, 24, 24, 30, 28, 28, 26, 28, 30, 24, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30},  // High
};

// For generating error correction codes.
testable const int8_t NUM_ERROR_CORRECTION_BLOCKS[4][41] = {
	// Version: (note that index 0 is for padding, and is set to an illegal value)
	//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40    Error correction level
	{-1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 4,  4,  4,  4,  4,  6,  6,  6,  6,  7,  8,  8,  9,  9, 10, 12, 12, 12, 13, 14, 15, 16, 17, 18, 19, 19, 20, 21, 22, 24, 25},  // Low
	{-1, 1, 1, 1, 2, 2, 4, 4, 4, 5, 5,  5,  8,  9,  9, 10, 10, 11, 13, 14, 16, 17, 17, 18, 20, 21, 23, 25, 26, 28, 29, 31, 33, 35, 37, 38, 40, 43, 45, 47, 49},  // Medium
	{-1, 1, 1, 2, 2, 4, 4, 6, 6, 8, 8,  8, 10, 12, 16, 12, 17, 16, 18, 21, 20, 23, 23, 25, 27, 29, 34, 34, 35, 38, 40, 43, 45, 48, 51, 53, 56, 59, 62, 65, 68},  // Quartile
	{-1, 1, 1, 2, 4, 4, 4, 5, 6, 8, 8, 11, 11, 16, 16, 18, 16, 19, 21, 25, 25, 25, 34, 30, 32, 35, 37, 40, 42, 45, 48, 51, 54, 57, 60, 63, 66, 70, 74, 77, 81},  // High
};

// For automatic mask pattern selection.
static const int PENALTY_N1 = 3;
static const int PENALTY_N2 = 3;
static const int PENALTY_N3 = 40;
static const int PENALTY_N4 = 10;



/*---- High-level QR Code encoding functions ----*/

// Public function - see documentation comment in header file.
static bool qrcodegen_encodeText(const char *text, uint8_t tempBuffer[], uint8_t qrcode[],
		enum qrcodegen_Ecc ecl, int minVersion, int maxVersion, enum qrcodegen_Mask mask, bool boostEcl) {
	
	size_t textLen = strlen(text);
	if (textLen == 0)
		return qrcodegen_encodeSegmentsAdvanced(NULL, 0, ecl, minVersion, maxVersion, mask, boostEcl, tempBuffer, qrcode);
	size_t bufLen = qrcodegen_BUFFER_LEN_FOR_VERSION(maxVersion);
	
	struct qrcodegen_Segment seg;
	if (qrcodegen_isNumeric(text)) {
		if (qrcodegen_calcSegmentBufferSize(qrcodegen_Mode_NUMERIC, textLen) > bufLen)
			goto fail;
		seg = qrcodegen_makeNumeric(text, tempBuffer);
	} else if (qrcodegen_isAlphanumeric(text)) {
		if (qrcodegen_calcSegmentBufferSize(qrcodegen_Mode_ALPHANUMERIC, textLen) > bufLen)
			goto fail;
		seg = qrcodegen_makeAlphanumeric(text, tempBuffer);
	} else {
		if (textLen > bufLen)
			goto fail;
		for (size_t i = 0; i < textLen; i++)
			tempBuffer[i] = (uint8_t)text[i];
		seg.mode = qrcodegen_Mode_BYTE;
		seg.bitLength = calcSegmentBitLength(seg.mode, textLen);
		if (seg.bitLength == -1)
			goto fail;
		seg.numChars = (int)textLen;
		seg.data = tempBuffer;
	}
	return qrcodegen_encodeSegmentsAdvanced(&seg, 1, ecl, minVersion, maxVersion, mask, boostEcl, tempBuffer, qrcode);
	
fail:
	qrcode[0] = 0;  // Set size to invalid value for safety
	return false;
}


// Public function - see documentation comment in header file.
static bool qrcodegen_encodeBinary(uint8_t dataAndTemp[], size_t dataLen, uint8_t qrcode[],
		enum qrcodegen_Ecc ecl, int minVersion, int maxVersion, enum qrcodegen_Mask mask, bool boostEcl) {
	
	struct qrcodegen_Segment seg;
	seg.mode = qrcodegen_Mode_BYTE;
	seg.bitLength = calcSegmentBitLength(seg.mode, dataLen);
	if (seg.bitLength == -1) {
		qrcode[0] = 0;  // Set size to invalid value for safety
		return false;
	}
	seg.numChars = (int)dataLen;
	seg.data = dataAndTemp;
	return qrcodegen_encodeSegmentsAdvanced(&seg, 1, ecl, minVersion, maxVersion, mask, boostEcl, dataAndTemp, qrcode);
}


// Appends the given sequence of bits to the given byte-based bit buffer, increasing the bit length.
testable void appendBitsToBuffer(unsigned int val, int numBits, uint8_t buffer[], int *bitLen) {
	assert(0 <= numBits && numBits <= 16 && (unsigned long)val >> numBits == 0);
	for (int i = numBits - 1; i >= 0; i--, (*bitLen)++)
		buffer[*bitLen >> 3] |= ((val >> i) & 1) << (7 - (*bitLen & 7));
}



/*---- Error correction code generation functions ----*/

// Appends error correction bytes to each block of the given data array, then interleaves bytes
// from the blocks and stores them in the result array. data[0 : rawCodewords - totalEcc] contains
// the input data. data[rawCodewords - totalEcc : rawCodewords] is used as a temporary work area
// and will be clobbered by this function. The final answer is stored in result[0 : rawCodewords].
testable void appendErrorCorrection(uint8_t data[], int version, enum qrcodegen_Ecc ecl, uint8_t result[]) {
	// Calculate parameter numbers
	assert(0 <= (int)ecl && (int)ecl < 4 && qrcodegen_VERSION_MIN <= version && version <= qrcodegen_VERSION_MAX);
	int numBlocks = NUM_ERROR_CORRECTION_BLOCKS[(int)ecl][version];
	int blockEccLen = ECC_CODEWORDS_PER_BLOCK[(int)ecl][version];
	int rawCodewords = getNumRawDataModules(version) / 8;
	int dataLen = rawCodewords - blockEccLen * numBlocks;
	int numShortBlocks = numBlocks - rawCodewords % numBlocks;
	int shortBlockDataLen = rawCodewords / numBlocks - blockEccLen;
	
	// Split data into blocks and append ECC after all data
	uint8_t generator[30];
	calcReedSolomonGenerator(blockEccLen, generator);
	for (int i = 0, j = dataLen, k = 0; i < numBlocks; i++) {
		int blockLen = shortBlockDataLen;
		if (i >= numShortBlocks)
			blockLen++;
		calcReedSolomonRemainder(&data[k], blockLen, generator, blockEccLen, &data[j]);
		j += blockEccLen;
		k += blockLen;
	}
	
	// Interleave (not concatenate) the bytes from every block into a single sequence
	for (int i = 0, k = 0; i < numBlocks; i++) {
		for (int j = 0, l = i; j < shortBlockDataLen; j++, k++, l += numBlocks)
			result[l] = data[k];
		if (i >= numShortBlocks)
			k++;
	}
	for (int i = numShortBlocks, k = (numShortBlocks + 1) * shortBlockDataLen, l = numBlocks * shortBlockDataLen;
			i < numBlocks; i++, k += shortBlockDataLen + 1, l++)
		result[l] = data[k];
	for (int i = 0, k = dataLen; i < numBlocks; i++) {
		for (int j = 0, l = dataLen + i; j < blockEccLen; j++, k++, l += numBlocks)
			result[l] = data[k];
	}
}


// Returns the number of 8-bit codewords that can be used for storing data (not ECC),
// for the given version number and error correction level. The result is in the range [9, 2956].
testable int getNumDataCodewords(int version, enum qrcodegen_Ecc ecl) {
	int v = version, e = (int)ecl;
	assert(0 <= e && e < 4 && qrcodegen_VERSION_MIN <= v && v <= qrcodegen_VERSION_MAX);
	return getNumRawDataModules(v) / 8 - ECC_CODEWORDS_PER_BLOCK[e][v] * NUM_ERROR_CORRECTION_BLOCKS[e][v];
}


// Returns the number of data bits that can be stored in a QR Code of the given version number, after
// all function modules are excluded. This includes remainder bits, so it might not be a multiple of 8.
// The result is in the range [208, 29648]. This could be implemented as a 40-entry lookup table.
testable int getNumRawDataModules(int version) {
	assert(qrcodegen_VERSION_MIN <= version && version <= qrcodegen_VERSION_MAX);
	int result = (16 * version + 128) * version + 64;
	if (version >= 2) {
		int numAlign = version / 7 + 2;
		result -= (25 * numAlign - 10) * numAlign - 55;
		if (version >= 7)
			result -= 18 * 2;  // Subtract version information
	}
	return result;
}



/*---- Reed-Solomon ECC generator functions ----*/

// Calculates the Reed-Solomon generator polynomial of the given degree, storing in result[0 : degree].
testable void calcReedSolomonGenerator(int degree, uint8_t result[]) {
	// Start with the monomial x^0
	assert(1 <= degree && degree <= 30);
	memset(result, 0, degree * sizeof(result[0]));
	result[degree - 1] = 1;
	
	// Compute the product polynomial (x - r^0) * (x - r^1) * (x - r^2) * ... * (x - r^{degree-1}),
	// drop the highest term, and store the rest of the coefficients in order of descending powers.
	// Note that r = 0x02, which is a generator element of this field GF(2^8/0x11D).
	uint8_t root = 1;
	for (int i = 0; i < degree; i++) {
		// Multiply the current product by (x - r^i)
		for (int j = 0; j < degree; j++) {
			result[j] = finiteFieldMultiply(result[j], root);
			if (j + 1 < degree)
				result[j] ^= result[j + 1];
		}
		root = finiteFieldMultiply(root, 0x02);
	}
}


// Calculates the remainder of the polynomial data[0 : dataLen] when divided by the generator[0 : degree], where all
// polynomials are in big endian and the generator has an implicit leading 1 term, storing the result in result[0 : degree].
testable void calcReedSolomonRemainder(const uint8_t data[], int dataLen,
		const uint8_t generator[], int degree, uint8_t result[]) {
	
	// Perform polynomial division
	assert(1 <= degree && degree <= 30);
	memset(result, 0, degree * sizeof(result[0]));
	for (int i = 0; i < dataLen; i++) {
		uint8_t factor = data[i] ^ result[0];
		memmove(&result[0], &result[1], (degree - 1) * sizeof(result[0]));
		result[degree - 1] = 0;
		for (int j = 0; j < degree; j++)
			result[j] ^= finiteFieldMultiply(generator[j], factor);
	}
}


// Returns the product of the two given field elements modulo GF(2^8/0x11D).
// All inputs are valid. This could be implemented as a 256*256 lookup table.
testable uint8_t finiteFieldMultiply(uint8_t x, uint8_t y) {
	// Russian peasant multiplication
	uint8_t z = 0;
	for (int i = 7; i >= 0; i--) {
		z = (z << 1) ^ ((z >> 7) * 0x11D);
		z ^= ((y >> i) & 1) * x;
	}
	return z;
}



/*---- Drawing function modules ----*/

// Clears the given QR Code grid with white modules for the given
// version's size, then marks every function module as black.
testable void initializeFunctionModules(int version, uint8_t qrcode[]) {
	// Initialize QR Code
	int qrsize = version * 4 + 17;
	memset(qrcode, 0, ((qrsize * qrsize + 7) / 8 + 1) * sizeof(qrcode[0]));
	qrcode[0] = (uint8_t)qrsize;
	
	// Fill horizontal and vertical timing patterns
	fillRectangle(6, 0, 1, qrsize, qrcode);
	fillRectangle(0, 6, qrsize, 1, qrcode);
	
	// Fill 3 finder patterns (all corners except bottom right) and format bits
	fillRectangle(0, 0, 9, 9, qrcode);
	fillRectangle(qrsize - 8, 0, 8, 9, qrcode);
	fillRectangle(0, qrsize - 8, 9, 8, qrcode);
	
	// Fill numerous alignment patterns
	uint8_t alignPatPos[7] = {0};
	int numAlign = getAlignmentPatternPositions(version, alignPatPos);
	for (int i = 0; i < numAlign; i++) {
		for (int j = 0; j < numAlign; j++) {
			if ((i == 0 && j == 0) || (i == 0 && j == numAlign - 1) || (i == numAlign - 1 && j == 0))
				continue;  // Skip the three finder corners
			else
				fillRectangle(alignPatPos[i] - 2, alignPatPos[j] - 2, 5, 5, qrcode);
		}
	}
	
	// Fill version blocks
	if (version >= 7) {
		fillRectangle(qrsize - 11, 0, 3, 6, qrcode);
		fillRectangle(0, qrsize - 11, 6, 3, qrcode);
	}
}


// Draws white function modules and possibly some black modules onto the given QR Code, without changing
// non-function modules. This does not draw the format bits. This requires all function modules to be previously
// marked black (namely by initializeFunctionModules()), because this may skip redrawing black function modules.
static void drawWhiteFunctionModules(uint8_t qrcode[], int version) {
	// Draw horizontal and vertical timing patterns
	int qrsize = qrcodegen_getSize(qrcode);
	for (int i = 7; i < qrsize - 7; i += 2) {
		setModule(qrcode, 6, i, false);
		setModule(qrcode, i, 6, false);
	}
	
	// Draw 3 finder patterns (all corners except bottom right; overwrites some timing modules)
	for (int i = -4; i <= 4; i++) {
		for (int j = -4; j <= 4; j++) {
			int dist = abs(i);
			if (abs(j) > dist)
				dist = abs(j);
			if (dist == 2 || dist == 4) {
				setModuleBounded(qrcode, 3 + j, 3 + i, false);
				setModuleBounded(qrcode, qrsize - 4 + j, 3 + i, false);
				setModuleBounded(qrcode, 3 + j, qrsize - 4 + i, false);
			}
		}
	}
	
	// Draw numerous alignment patterns
	uint8_t alignPatPos[7] = {0};
	int numAlign = getAlignmentPatternPositions(version, alignPatPos);
	for (int i = 0; i < numAlign; i++) {
		for (int j = 0; j < numAlign; j++) {
			if ((i == 0 && j == 0) || (i == 0 && j == numAlign - 1) || (i == numAlign - 1 && j == 0))
				continue;  // Skip the three finder corners
			else {
				for (int k = -1; k <= 1; k++) {
					for (int l = -1; l <= 1; l++)
						setModule(qrcode, alignPatPos[i] + l, alignPatPos[j] + k, k == 0 && l == 0);
				}
			}
		}
	}
	
	// Draw version blocks
	if (version >= 7) {
		// Calculate error correction code and pack bits
		int rem = version;  // version is uint6, in the range [7, 40]
		for (int i = 0; i < 12; i++)
			rem = (rem << 1) ^ ((rem >> 11) * 0x1F25);
		long data = (long)version << 12 | rem;  // uint18
		assert(data >> 18 == 0);
		
		// Draw two copies
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				int k = qrsize - 11 + j;
				setModule(qrcode, k, i, (data & 1) != 0);
				setModule(qrcode, i, k, (data & 1) != 0);
				data >>= 1;
			}
		}
	}
}


// Draws two copies of the format bits (with its own error correction code) based
// on the given mask and error correction level. This always draws all modules of
// the format bits, unlike drawWhiteFunctionModules() which might skip black modules.
static void drawFormatBits(enum qrcodegen_Ecc ecl, enum qrcodegen_Mask mask, uint8_t qrcode[]) {
	// Calculate error correction code and pack bits
	assert(0 <= (int)mask && (int)mask <= 7);
	int data = -1;  // Dummy value
	switch (ecl) {
		case qrcodegen_Ecc_LOW     :  data = 1;  break;
		case qrcodegen_Ecc_MEDIUM  :  data = 0;  break;
		case qrcodegen_Ecc_QUARTILE:  data = 3;  break;
		case qrcodegen_Ecc_HIGH    :  data = 2;  break;
		default:  assert(false);
	}
	data = data << 3 | (int)mask;  // ecl-derived value is uint2, mask is uint3
	int rem = data;
	for (int i = 0; i < 10; i++)
		rem = (rem << 1) ^ ((rem >> 9) * 0x537);
	data = data << 10 | rem;
	data ^= 0x5412;  // uint15
	assert(data >> 15 == 0);
	
	// Draw first copy
	for (int i = 0; i <= 5; i++)
		setModule(qrcode, 8, i, ((data >> i) & 1) != 0);
	setModule(qrcode, 8, 7, ((data >> 6) & 1) != 0);
	setModule(qrcode, 8, 8, ((data >> 7) & 1) != 0);
	setModule(qrcode, 7, 8, ((data >> 8) & 1) != 0);
	for (int i = 9; i < 15; i++)
		setModule(qrcode, 14 - i, 8, ((data >> i) & 1) != 0);
	
	// Draw second copy
	int qrsize = qrcodegen_getSize(qrcode);
	for (int i = 0; i <= 7; i++)
		setModule(qrcode, qrsize - 1 - i, 8, ((data >> i) & 1) != 0);
	for (int i = 8; i < 15; i++)
		setModule(qrcode, 8, qrsize - 15 + i, ((data >> i) & 1) != 0);
	setModule(qrcode, 8, qrsize - 8, true);
}


// Calculates the positions of alignment patterns in ascending order for the given version number,
// storing them to the given array and returning an array length in the range [0, 7].
testable int getAlignmentPatternPositions(int version, uint8_t result[7]) {
	if (version == 1)
		return 0;
	int numAlign = version / 7 + 2;
	int step;
	if (version != 32) {
		// ceil((size - 13) / (2*numAlign - 2)) * 2
		step = (version * 4 + numAlign * 2 + 1) / (2 * numAlign - 2) * 2;
	} else  // C-C-C-Combo breaker!
		step = 26;
	for (int i = numAlign - 1, pos = version * 4 + 10; i >= 1; i--, pos -= step)
		result[i] = pos;
	result[0] = 6;
	return numAlign;
}


// Sets every pixel in the range [left : left + width] * [top : top + height] to black.
static void fillRectangle(int left, int top, int width, int height, uint8_t qrcode[]) {
	for (int dy = 0; dy < height; dy++) {
		for (int dx = 0; dx < width; dx++)
			setModule(qrcode, left + dx, top + dy, true);
	}
}



/*---- Drawing data modules and masking ----*/

// Draws the raw codewords (including data and ECC) onto the given QR Code. This requires the initial state of
// the QR Code to be black at function modules and white at codeword modules (including unused remainder bits).
static void drawCodewords(const uint8_t data[], int dataLen, uint8_t qrcode[]) {
	int qrsize = qrcodegen_getSize(qrcode);
	int i = 0;  // Bit index into the data
	// Do the funny zigzag scan
	for (int right = qrsize - 1; right >= 1; right -= 2) {  // Index of right column in each column pair
		if (right == 6)
			right = 5;
		for (int vert = 0; vert < qrsize; vert++) {  // Vertical counter
			for (int j = 0; j < 2; j++) {
				int x = right - j;  // Actual x coordinate
				bool upward = ((right + 1) & 2) == 0;
				int y = upward ? qrsize - 1 - vert : vert;  // Actual y coordinate
				if (!getModule(qrcode, x, y) && i < dataLen * 8) {
					bool black = ((data[i >> 3] >> (7 - (i & 7))) & 1) != 0;
					setModule(qrcode, x, y, black);
					i++;
				}
				// If there are any remainder bits (0 to 7), they are already
				// set to 0/false/white when the grid of modules was initialized
			}
		}
	}
	assert(i == dataLen * 8);
}


// XORs the data modules in this QR Code with the given mask pattern. Due to XOR's mathematical
// properties, calling applyMask(..., m) twice with the same value is equivalent to no change at all.
// This means it is possible to apply a mask, undo it, and try another mask. Note that a final
// well-formed QR Code symbol needs exactly one mask applied (not zero, not two, etc.).
static void applyMask(const uint8_t functionModules[], uint8_t qrcode[], enum qrcodegen_Mask mask) {
	assert(0 <= (int)mask && (int)mask <= 7);  // Disallows qrcodegen_Mask_AUTO
	int qrsize = qrcodegen_getSize(qrcode);
	for (int y = 0; y < qrsize; y++) {
		for (int x = 0; x < qrsize; x++) {
			if (getModule(functionModules, x, y))
				continue;
			bool invert = false;  // Dummy value
			switch ((int)mask) {
				case 0:  invert = (x + y) % 2 == 0;                    break;
				case 1:  invert = y % 2 == 0;                          break;
				case 2:  invert = x % 3 == 0;                          break;
				case 3:  invert = (x + y) % 3 == 0;                    break;
				case 4:  invert = (x / 3 + y / 2) % 2 == 0;            break;
				case 5:  invert = x * y % 2 + x * y % 3 == 0;          break;
				case 6:  invert = (x * y % 2 + x * y % 3) % 2 == 0;    break;
				case 7:  invert = ((x + y) % 2 + x * y % 3) % 2 == 0;  break;
				default:  assert(false);
			}
			bool val = getModule(qrcode, x, y);
			setModule(qrcode, x, y, val ^ invert);
		}
	}
}


// Calculates and returns the penalty score based on state of the given QR Code's current modules.
// This is used by the automatic mask choice algorithm to find the mask pattern that yields the lowest score.
static long getPenaltyScore(const uint8_t qrcode[]) {
	int qrsize = qrcodegen_getSize(qrcode);
	long result = 0;
	
	// Adjacent modules in row having same color
	for (int y = 0; y < qrsize; y++) {
		bool colorX = false;
		for (int x = 0, runX = -1; x < qrsize; x++) {
			if (x == 0 || getModule(qrcode, x, y) != colorX) {
				colorX = getModule(qrcode, x, y);
				runX = 1;
			} else {
				runX++;
				if (runX == 5)
					result += PENALTY_N1;
				else if (runX > 5)
					result++;
			}
		}
	}
	// Adjacent modules in column having same color
	for (int x = 0; x < qrsize; x++) {
		bool colorY = false;
		for (int y = 0, runY = -1; y < qrsize; y++) {
			if (y == 0 || getModule(qrcode, x, y) != colorY) {
				colorY = getModule(qrcode, x, y);
				runY = 1;
			} else {
				runY++;
				if (runY == 5)
					result += PENALTY_N1;
				else if (runY > 5)
					result++;
			}
		}
	}
	
	// 2*2 blocks of modules having same color
	for (int y = 0; y < qrsize - 1; y++) {
		for (int x = 0; x < qrsize - 1; x++) {
			bool  color = getModule(qrcode, x, y);
			if (  color == getModule(qrcode, x + 1, y) &&
			      color == getModule(qrcode, x, y + 1) &&
			      color == getModule(qrcode, x + 1, y + 1))
				result += PENALTY_N2;
		}
	}
	
	// Finder-like pattern in rows
	for (int y = 0; y < qrsize; y++) {
		for (int x = 0, bits = 0; x < qrsize; x++) {
			bits = ((bits << 1) & 0x7FF) | (getModule(qrcode, x, y) ? 1 : 0);
			if (x >= 10 && (bits == 0x05D || bits == 0x5D0))  // Needs 11 bits accumulated
				result += PENALTY_N3;
		}
	}
	// Finder-like pattern in columns
	for (int x = 0; x < qrsize; x++) {
		for (int y = 0, bits = 0; y < qrsize; y++) {
			bits = ((bits << 1) & 0x7FF) | (getModule(qrcode, x, y) ? 1 : 0);
			if (y >= 10 && (bits == 0x05D || bits == 0x5D0))  // Needs 11 bits accumulated
				result += PENALTY_N3;
		}
	}
	
	// Balance of black and white modules
	int black = 0;
	for (int y = 0; y < qrsize; y++) {
		for (int x = 0; x < qrsize; x++) {
			if (getModule(qrcode, x, y))
				black++;
		}
	}
	int total = qrsize * qrsize;
	// Find smallest k such that (45-5k)% <= dark/total <= (55+5k)%
	for (int k = 0; black*20L < (9L-k)*total || black*20L > (11L+k)*total; k++)
		result += PENALTY_N4;
	return result;
}



/*---- Basic QR Code information ----*/

// Public function - see documentation comment in header file.
int qrcodegen_getSize(const uint8_t qrcode[]) {
	assert(qrcode != NULL);
	int result = qrcode[0];
	assert((qrcodegen_VERSION_MIN * 4 + 17) <= result
		&& result <= (qrcodegen_VERSION_MAX * 4 + 17));
	return result;
}


// Public function - see documentation comment in header file.
bool qrcodegen_getModule(const uint8_t qrcode[], int x, int y) {
	assert(qrcode != NULL);
	int qrsize = qrcode[0];
	return (0 <= x && x < qrsize && 0 <= y && y < qrsize) && getModule(qrcode, x, y);
}


// Gets the module at the given coordinates, which must be in bounds.
testable bool getModule(const uint8_t qrcode[], int x, int y) {
	int qrsize = qrcode[0];
	assert(21 <= qrsize && qrsize <= 177 && 0 <= x && x < qrsize && 0 <= y && y < qrsize);
	int index = y * qrsize + x;
	int bitIndex = index & 7;
	int byteIndex = (index >> 3) + 1;
	return ((qrcode[byteIndex] >> bitIndex) & 1) != 0;
}


// Sets the module at the given coordinates, which must be in bounds.
testable void setModule(uint8_t qrcode[], int x, int y, bool isBlack) {
	int qrsize = qrcode[0];
	assert(21 <= qrsize && qrsize <= 177 && 0 <= x && x < qrsize && 0 <= y && y < qrsize);
	int index = y * qrsize + x;
	int bitIndex = index & 7;
	int byteIndex = (index >> 3) + 1;
	if (isBlack)
		qrcode[byteIndex] |= 1 << bitIndex;
	else
		qrcode[byteIndex] &= (1 << bitIndex) ^ 0xFF;
}


// Sets the module at the given coordinates, doing nothing if out of bounds.
testable void setModuleBounded(uint8_t qrcode[], int x, int y, bool isBlack) {
	int qrsize = qrcode[0];
	if (0 <= x && x < qrsize && 0 <= y && y < qrsize)
		setModule(qrcode, x, y, isBlack);
}



/*---- Segment handling ----*/

// Public function - see documentation comment in header file.
bool qrcodegen_isAlphanumeric(const char *text) {
	assert(text != NULL);
	for (; *text != '\0'; text++) {
		if (strchr(ALPHANUMERIC_CHARSET, *text) == NULL)
			return false;
	}
	return true;
}


// Public function - see documentation comment in header file.
bool qrcodegen_isNumeric(const char *text) {
	assert(text != NULL);
	for (; *text != '\0'; text++) {
		if (*text < '0' || *text > '9')
			return false;
	}
	return true;
}


// Public function - see documentation comment in header file.
size_t qrcodegen_calcSegmentBufferSize(enum qrcodegen_Mode mode, size_t numChars) {
	int temp = calcSegmentBitLength(mode, numChars);
	if (temp == -1)
		return SIZE_MAX;
	assert(0 <= temp && temp <= INT16_MAX);
	return ((size_t)temp + 7) / 8;
}


// Returns the number of data bits needed to represent a segment
// containing the given number of characters using the given mode. Notes:
// - Returns -1 on failure, i.e. numChars > INT16_MAX or
//   the number of needed bits exceeds INT16_MAX (i.e. 32767).
// - Otherwise, all valid results are in the range [0, INT16_MAX].
// - For byte mode, numChars measures the number of bytes, not Unicode code points.
// - For ECI mode, numChars must be 0, and the worst-case number of bits is returned.
//   An actual ECI segment can have shorter data. For non-ECI modes, the result is exact.
testable int calcSegmentBitLength(enum qrcodegen_Mode mode, size_t numChars) {
	const int LIMIT = INT16_MAX;  // Can be configured as high as INT_MAX
	if (numChars > (unsigned int)LIMIT)
		return -1;
	int n = (int)numChars;
	
	int result = -2;
	if (mode == qrcodegen_Mode_NUMERIC) {
		// n * 3 + ceil(n / 3)
		if (n > LIMIT / 3)
			goto overflow;
		result = n * 3;
		int temp = n / 3 + (n % 3 == 0 ? 0 : 1);
		if (temp > LIMIT - result)
			goto overflow;
		result += temp;
	} else if (mode == qrcodegen_Mode_ALPHANUMERIC) {
		// n * 5 + ceil(n / 2)
		if (n > LIMIT / 5)
			goto overflow;
		result = n * 5;
		int temp = n / 2 + n % 2;
		if (temp > LIMIT - result)
			goto overflow;
		result += temp;
	} else if (mode == qrcodegen_Mode_BYTE) {
		if (n > LIMIT / 8)
			goto overflow;
		result = n * 8;
	} else if (mode == qrcodegen_Mode_KANJI) {
		if (n > LIMIT / 13)
			goto overflow;
		result = n * 13;
	} else if (mode == qrcodegen_Mode_ECI && numChars == 0)
		result = 3 * 8;
	assert(0 <= result && result <= LIMIT);
	return result;
overflow:
	return -1;
}


// Public function - see documentation comment in header file.
static struct qrcodegen_Segment qrcodegen_makeBytes(const uint8_t data[], size_t len, uint8_t buf[]) {
	assert(data != NULL || len == 0);
	struct qrcodegen_Segment result;
	result.mode = qrcodegen_Mode_BYTE;
	result.bitLength = calcSegmentBitLength(result.mode, len);
	assert(result.bitLength != -1);
	result.numChars = (int)len;
	if (len > 0)
		memcpy(buf, data, len * sizeof(buf[0]));
	result.data = buf;
	return result;
}


// Public function - see documentation comment in header file.
static struct qrcodegen_Segment qrcodegen_makeNumeric(const char *digits, uint8_t buf[]) {
	assert(digits != NULL);
	struct qrcodegen_Segment result;
	size_t len = strlen(digits);
	result.mode = qrcodegen_Mode_NUMERIC;
	int bitLen = calcSegmentBitLength(result.mode, len);
	assert(bitLen != -1);
	result.numChars = (int)len;
	if (bitLen > 0)
		memset(buf, 0, ((size_t)bitLen + 7) / 8 * sizeof(buf[0]));
	result.bitLength = 0;
	
	unsigned int accumData = 0;
	int accumCount = 0;
	for (; *digits != '\0'; digits++) {
		char c = *digits;
		assert('0' <= c && c <= '9');
		accumData = accumData * 10 + (c - '0');
		accumCount++;
		if (accumCount == 3) {
			appendBitsToBuffer(accumData, 10, buf, &result.bitLength);
			accumData = 0;
			accumCount = 0;
		}
	}
	if (accumCount > 0)  // 1 or 2 digits remaining
		appendBitsToBuffer(accumData, accumCount * 3 + 1, buf, &result.bitLength);
	assert(result.bitLength == bitLen);
	result.data = buf;
	return result;
}


// Public function - see documentation comment in header file.
static struct qrcodegen_Segment qrcodegen_makeAlphanumeric(const char *text, uint8_t buf[]) {
	assert(text != NULL);
	struct qrcodegen_Segment result;
	size_t len = strlen(text);
	result.mode = qrcodegen_Mode_ALPHANUMERIC;
	int bitLen = calcSegmentBitLength(result.mode, len);
	assert(bitLen != -1);
	result.numChars = (int)len;
	if (bitLen > 0)
		memset(buf, 0, ((size_t)bitLen + 7) / 8 * sizeof(buf[0]));
	result.bitLength = 0;
	
	unsigned int accumData = 0;
	int accumCount = 0;
	for (; *text != '\0'; text++) {
		const char *temp = strchr(ALPHANUMERIC_CHARSET, *text);
		assert(temp != NULL);
		accumData = accumData * 45 + (temp - ALPHANUMERIC_CHARSET);
		accumCount++;
		if (accumCount == 2) {
			appendBitsToBuffer(accumData, 11, buf, &result.bitLength);
			accumData = 0;
			accumCount = 0;
		}
	}
	if (accumCount > 0)  // 1 character remaining
		appendBitsToBuffer(accumData, 6, buf, &result.bitLength);
	assert(result.bitLength == bitLen);
	result.data = buf;
	return result;
}


// Public function - see documentation comment in header file.
static struct qrcodegen_Segment qrcodegen_makeEci(long assignVal, uint8_t buf[]) {
	struct qrcodegen_Segment result;
	result.mode = qrcodegen_Mode_ECI;
	result.numChars = 0;
	result.bitLength = 0;
	if (0 <= assignVal && assignVal < (1 << 7)) {
		memset(buf, 0, 1 * sizeof(buf[0]));
		appendBitsToBuffer(assignVal, 8, buf, &result.bitLength);
	} else if ((1 << 7) <= assignVal && assignVal < (1 << 14)) {
		memset(buf, 0, 2 * sizeof(buf[0]));
		appendBitsToBuffer(2, 2, buf, &result.bitLength);
		appendBitsToBuffer(assignVal, 14, buf, &result.bitLength);
	} else if ((1 << 14) <= assignVal && assignVal < 1000000L) {
		memset(buf, 0, 3 * sizeof(buf[0]));
		appendBitsToBuffer(6, 3, buf, &result.bitLength);
		appendBitsToBuffer(assignVal >> 10, 11, buf, &result.bitLength);
		appendBitsToBuffer(assignVal & 0x3FF, 10, buf, &result.bitLength);
	} else
		assert(false);
	result.data = buf;
	return result;
}


// Public function - see documentation comment in header file.
static bool qrcodegen_encodeSegments(const struct qrcodegen_Segment segs[], size_t len,
		enum qrcodegen_Ecc ecl, uint8_t tempBuffer[], uint8_t qrcode[]) {
	return qrcodegen_encodeSegmentsAdvanced(segs, len, ecl,
		qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX, -1, true, tempBuffer, qrcode);
}


// Public function - see documentation comment in header file.
static bool qrcodegen_encodeSegmentsAdvanced(const struct qrcodegen_Segment segs[], size_t len, enum qrcodegen_Ecc ecl,
		int minVersion, int maxVersion, int mask, bool boostEcl, uint8_t tempBuffer[], uint8_t qrcode[]) {
	assert(segs != NULL || len == 0);
	assert(qrcodegen_VERSION_MIN <= minVersion && minVersion <= maxVersion && maxVersion <= qrcodegen_VERSION_MAX);
	assert(0 <= (int)ecl && (int)ecl <= 3 && -1 <= (int)mask && (int)mask <= 7);
	
	// Find the minimal version number to use
	int version, dataUsedBits;
	for (version = minVersion; ; version++) {
		int dataCapacityBits = getNumDataCodewords(version, ecl) * 8;  // Number of data bits available
		dataUsedBits = getTotalBits(segs, len, version);
		if (dataUsedBits != -1 && dataUsedBits <= dataCapacityBits)
			break;  // This version number is found to be suitable
		if (version >= maxVersion) {  // All versions in the range could not fit the given data
			qrcode[0] = 0;  // Set size to invalid value for safety
			return false;
		}
	}
	assert(dataUsedBits != -1);
	
	// Increase the error correction level while the data still fits in the current version number
	for (int i = (int)qrcodegen_Ecc_MEDIUM; i <= (int)qrcodegen_Ecc_HIGH; i++) {
		if (boostEcl && dataUsedBits <= getNumDataCodewords(version, (enum qrcodegen_Ecc)i) * 8)
			ecl = (enum qrcodegen_Ecc)i;
	}
	
	// Create the data bit string by concatenating all segments
	int dataCapacityBits = getNumDataCodewords(version, ecl) * 8;
	memset(qrcode, 0, qrcodegen_BUFFER_LEN_FOR_VERSION(version) * sizeof(qrcode[0]));
	int bitLen = 0;
	for (size_t i = 0; i < len; i++) {
		const struct qrcodegen_Segment *seg = &segs[i];
		unsigned int modeBits = 0;  // Dummy value
		switch (seg->mode) {
			case qrcodegen_Mode_NUMERIC     :  modeBits = 0x1;  break;
			case qrcodegen_Mode_ALPHANUMERIC:  modeBits = 0x2;  break;
			case qrcodegen_Mode_BYTE        :  modeBits = 0x4;  break;
			case qrcodegen_Mode_KANJI       :  modeBits = 0x8;  break;
			case qrcodegen_Mode_ECI         :  modeBits = 0x7;  break;
			default:  assert(false);
		}
		appendBitsToBuffer(modeBits, 4, qrcode, &bitLen);
		appendBitsToBuffer(seg->numChars, numCharCountBits(seg->mode, version), qrcode, &bitLen);
		for (int j = 0; j < seg->bitLength; j++)
			appendBitsToBuffer((seg->data[j >> 3] >> (7 - (j & 7))) & 1, 1, qrcode, &bitLen);
	}
	
	// Add terminator and pad up to a byte if applicable
	int terminatorBits = dataCapacityBits - bitLen;
	if (terminatorBits > 4)
		terminatorBits = 4;
	appendBitsToBuffer(0, terminatorBits, qrcode, &bitLen);
	appendBitsToBuffer(0, (8 - bitLen % 8) % 8, qrcode, &bitLen);
	
	// Pad with alternate bytes until data capacity is reached
	for (uint8_t padByte = 0xEC; bitLen < dataCapacityBits; padByte ^= 0xEC ^ 0x11)
		appendBitsToBuffer(padByte, 8, qrcode, &bitLen);
	assert(bitLen % 8 == 0);
	
	// Draw function and data codeword modules
	appendErrorCorrection(qrcode, version, ecl, tempBuffer);
	initializeFunctionModules(version, qrcode);
	drawCodewords(tempBuffer, getNumRawDataModules(version) / 8, qrcode);
	drawWhiteFunctionModules(qrcode, version);
	initializeFunctionModules(version, tempBuffer);
	
	// Handle masking
	if (mask == qrcodegen_Mask_AUTO) {  // Automatically choose best mask
		long minPenalty = LONG_MAX;
		for (int i = 0; i < 8; i++) {
			drawFormatBits(ecl, (enum qrcodegen_Mask)i, qrcode);
			applyMask(tempBuffer, qrcode, (enum qrcodegen_Mask)i);
			long penalty = getPenaltyScore(qrcode);
			if (penalty < minPenalty) {
				mask = (enum qrcodegen_Mask)i;
				minPenalty = penalty;
			}
			applyMask(tempBuffer, qrcode, (enum qrcodegen_Mask)i);  // Undoes the mask due to XOR
		}
	}
	assert(0 <= (int)mask && (int)mask <= 7);
	drawFormatBits(ecl, (enum qrcodegen_Mask)mask, qrcode);
	applyMask(tempBuffer, qrcode, (enum qrcodegen_Mask)mask);
	return true;
}


// Returns the number of bits needed to encode the given list of segments at the given version.
// The result is in the range [0, 32767] if successful. Otherwise, -1 is returned if any segment
// has more characters than allowed by that segment's mode's character count field at the version,
// or if the actual answer exceeds INT16_MAX.
testable int getTotalBits(const struct qrcodegen_Segment segs[], size_t len, int version) {
	assert(segs != NULL || len == 0);
	assert(qrcodegen_VERSION_MIN <= version && version <= qrcodegen_VERSION_MAX);
	int result = 0;
	for (size_t i = 0; i < len; i++) {
		int numChars = segs[i].numChars;
		int bitLength = segs[i].bitLength;
		assert(0 <= numChars && numChars <= INT16_MAX);
		assert(0 <= bitLength && bitLength <= INT16_MAX);
		int ccbits = numCharCountBits(segs[i].mode, version);
		assert(0 <= ccbits && ccbits <= 16);
		// Fail if segment length value doesn't fit in the length field's bit-width
		if (numChars >= (1L << ccbits))
			return -1;
		long temp = 4L + ccbits + bitLength;
		if (temp > INT16_MAX - result)
			return -1;
		result += temp;
	}
	assert(0 <= result && result <= INT16_MAX);
	return result;
}


// Returns the bit width of the segment character count field for the
// given mode at the given version number. The result is in the range [0, 16].
static int numCharCountBits(enum qrcodegen_Mode mode, int version) {
	assert(qrcodegen_VERSION_MIN <= version && version <= qrcodegen_VERSION_MAX);
	int i = -1;  // Dummy value
	if      ( 1 <= version && version <=  9)  i = 0;
	else if (10 <= version && version <= 26)  i = 1;
	else if (27 <= version && version <= 40)  i = 2;
	else  assert(false);
	
	switch (mode) {
		case qrcodegen_Mode_NUMERIC     : { static const int temp[] = {10, 12, 14}; return temp[i]; }
		case qrcodegen_Mode_ALPHANUMERIC: { static const int temp[] = { 9, 11, 13}; return temp[i]; }
		case qrcodegen_Mode_BYTE        : { static const int temp[] = { 8, 16, 16}; return temp[i]; }
		case qrcodegen_Mode_KANJI       : { static const int temp[] = { 8, 10, 12}; return temp[i]; }
		case qrcodegen_Mode_ECI         : return 0;
		default:  assert(false);
	}
	return -1;  // Dummy value
}
/**************************  END  qrcodegen.impl.h **************************/

#endif
/**************************  END  qrcodegen.h **************************/
#endif

// for compatibility
#define minValue minimum
#define maxValue maximum

//==============================BEGIN QSYNTHKNOB=====================================
//
//   qsynthknob and qsynthDialVokiStyle borrowed from qsynth-0.3.3 by Rui Nuno Capela
//   This widget is based on a design by Thorsten Wilms,
//   implemented by Chris Cannam in Rosegarden,
//   adapted for QSynth by Pedro Lopez-Cabanillas,
//   improved for Qt4 by David Garcia Garzon.
//

#define DIAL_MIN       (0.25 * M_PI)
#define DIAL_MAX       (1.75 * M_PI)
#define DIAL_RANGE     (DIAL_MAX - DIAL_MIN)
#define DIAL_WRAPPING  false

class qsynthDialVokiStyle : public QCommonStyle
{
    
public:
    qsynthDialVokiStyle() {};
    virtual ~qsynthDialVokiStyle() {};
    
    virtual void drawComplexControl(ComplexControl cc, const QStyleOptionComplex* opt, QPainter* p, const QWidget* widget = NULL) const
    {
        if (cc != QStyle::CC_Dial)
        {
            QCommonStyle::drawComplexControl(cc, opt, p, widget);
            return;
        }
        
        const QStyleOptionSlider* dial = qstyleoption_cast<const QStyleOptionSlider *>(opt);
        if (dial == NULL) return;
        
        double angle = DIAL_MIN // offset
        + (DIAL_RANGE *
           (double(dial->sliderValue - dial->minimum) /
            (double(dial->maximum - dial->minimum))));
        int degrees = int(angle * 180.0 / M_PI);
        int side = dial->rect.width() < dial->rect.height() ? dial->rect.width() : dial->rect.height();
        int xcenter = dial->rect.width() / 2;
        int ycenter = dial->rect.height() / 2;
        int notchWidth   = 1 + side / 400;
        int pointerWidth = 2 + side / 30;
        int scaleShadowWidth = 1 + side / 100;
        int knobBorderWidth = 0;
        int ns = dial->tickInterval;
        int numTicks = 1 + (dial->maximum + ns - dial->minimum) / ns;
        int indent = int(0.15 * side) + 2;
        int knobWidth = side - 2 * indent;
        int shineFocus = knobWidth / 4;
        int shineCenter = knobWidth / 5;
        int shineExtension = shineCenter * 4;
        int shadowShift = shineCenter * 2;
        int meterWidth = side - 2 * scaleShadowWidth;
        
        QPalette pal = opt->palette;
        QColor knobColor = pal.mid().color();
        QColor borderColor = knobColor.light();
        QColor meterColor = (dial->state & State_Enabled) ?
        QColor("orange") : pal.mid().color();
        // pal.highlight().color() : pal.mid().color();
        QColor background = pal.window().color();
        
        p->save();
        p->setRenderHint(QPainter::Antialiasing, true);
        
        // The bright metering bit...
        QConicalGradient meterShadow(xcenter, ycenter, -90);
        meterShadow.setColorAt(0, meterColor.dark());
        meterShadow.setColorAt(0.5, meterColor);
        meterShadow.setColorAt(1.0, meterColor.light().light());
        p->setBrush(meterShadow);
        p->setPen(Qt::transparent);
        p->drawPie(xcenter - meterWidth / 2, ycenter - meterWidth / 2,
                   meterWidth, meterWidth, (180 + 45) * 16, -(degrees - 45) * 16);
        
        // Knob projected shadow
        QRadialGradient projectionGradient(xcenter + shineCenter, ycenter + shineCenter,
                                           shineExtension,	xcenter + shadowShift, ycenter + shadowShift);
        projectionGradient.setColorAt(0, QColor(  0, 0, 0, 100));
        projectionGradient.setColorAt(1, QColor(200, 0, 0,  10));
        QBrush shadowBrush(projectionGradient);
        p->setBrush(shadowBrush);
        p->drawEllipse(xcenter - shadowShift, ycenter - shadowShift,
                       knobWidth, knobWidth);
        
        // Knob body and face...
        QPen pen;
        pen.setColor(knobColor);
        pen.setWidth(knobBorderWidth);
        p->setPen(pen);
        
        QRadialGradient gradient(xcenter - shineCenter, ycenter - shineCenter,
                                 shineExtension,	xcenter - shineFocus, ycenter - shineFocus);
        gradient.setColorAt(0.2, knobColor.light().light());
        gradient.setColorAt(0.5, knobColor);
        gradient.setColorAt(1.0, knobColor.dark(150));
        QBrush knobBrush(gradient);
        p->setBrush(knobBrush);
        p->drawEllipse(xcenter - knobWidth / 2, ycenter - knobWidth / 2,
                       knobWidth, knobWidth);
        
        // Tick notches...
        p->setBrush(Qt::NoBrush);
        
        if (dial->subControls & QStyle::SC_DialTickmarks) {
            pen.setColor(pal.dark().color());
            pen.setWidth(notchWidth);
            p->setPen(pen);
            double hyp = double(side - scaleShadowWidth) / 2.0;
            double len = hyp / 4;
            for (int i = 0; i < numTicks; ++i) {
                int div = numTicks;
                if (div > 1) --div;
                bool internal = (i != 0 && i != numTicks - 1);
                double angle = DIAL_MIN
                + (DIAL_MAX - DIAL_MIN) * i / div;
                double dir = (internal ? -1 : len);
                double sinAngle = sin(angle);
                double cosAngle = cos(angle);
                double x0 = xcenter - (hyp - len) * sinAngle;
                double y0 = ycenter + (hyp - len) * cosAngle;
                double x1 = xcenter - (hyp + dir) * sinAngle;
                double y1 = ycenter + (hyp + dir) * cosAngle;
                p->drawLine(QLineF(x0, y0, x1, y1));
            }
        }
        
        // Shadowing...
        
        // Knob shadow...
        if (knobBorderWidth > 0) {
            QLinearGradient inShadow(xcenter - side / 4, ycenter - side / 4,
                                     xcenter + side / 4, ycenter + side / 4);
            inShadow.setColorAt(0.0, borderColor.light());
            inShadow.setColorAt(1.0, borderColor.dark());
            p->setPen(QPen(QBrush(inShadow), knobBorderWidth * 7 / 8));
            p->drawEllipse(xcenter - side / 2 + indent,
                           ycenter - side / 2 + indent,
                           side - 2 * indent, side - 2 * indent);
        }
        
        // Scale shadow...
        QLinearGradient outShadow(xcenter - side / 3, ycenter - side / 3,
                                  xcenter + side / 3, ycenter + side / 3);
        outShadow.setColorAt(0.0, background.dark().dark());
        outShadow.setColorAt(1.0, background.light().light());
        p->setPen(QPen(QBrush(outShadow), scaleShadowWidth));
        p->drawArc(xcenter - side / 2 + scaleShadowWidth / 2,
                   ycenter - side / 2 + scaleShadowWidth / 2,
                   side - scaleShadowWidth, side - scaleShadowWidth, -45 * 16, 270 * 16);
        
        // Pointer notch...
        double hyp = double(side) / 2.0;
        double len = hyp - indent - 1;
        
        double x = xcenter - len * sin(angle);
        double y = ycenter + len * cos(angle);
        
        QColor pointerColor = pal.dark().color();
        pen.setColor((dial->state & State_Enabled) ? pointerColor.dark(140) : pointerColor);
        pen.setWidth(pointerWidth + 2);
        p->setPen(pen);
        p->drawLine(QLineF(xcenter, ycenter, x, y));
        pen.setColor((dial->state & State_Enabled) ? pointerColor.light() : pointerColor.light(140));
        pen.setWidth(pointerWidth);
        p->setPen(pen);
        p->drawLine(QLineF(xcenter - 1, ycenter - 1, x - 1, y - 1));
        
        // done
        p->restore();
    }
    
};

//
//===============================END QSYNTHKNOB======================================


//==============================BEGIN DISPLAYS===================================
//
// This section constains displays, passive QT widgets that displays values in
// different ways, in particular bargraphs
//

/**
 * An abstract widget that display a value in a range
 */
class AbstractDisplay : public QWidget
{
    
protected:
    
    FAUSTFLOAT fMin;
    FAUSTFLOAT fMax;
    FAUSTFLOAT fValue;
    
public:
    
    AbstractDisplay(FAUSTFLOAT lo, FAUSTFLOAT hi) : fMin(lo), fMax(hi), fValue(lo)
    {}
    
    /**
     * set the range of displayed values
     */
    virtual void setRange(FAUSTFLOAT lo, FAUSTFLOAT hi)
    {
        fMin = lo;
        fMax = hi;
    }
    
    /**
     * set the value to be displayed
     */
    virtual void setValue(FAUSTFLOAT v)
    {
        if (v < fMin)       v = fMin;
        else if (v > fMax)  v = fMax;
        
        if (v != fValue) {
            fValue = v;
            update();
        }
    }
};

/**
 * Displays dB values using a scale of colors
 */
class dbAbstractDisplay : public AbstractDisplay
{
    
protected:
    
    FAUSTFLOAT      fScaleMin;
    FAUSTFLOAT      fScaleMax;
    std::vector<int>     fLevel;
    std::vector<QBrush>  fBrush;
    
    /**
     * Create the scale of colors used to paint the bargraph in relation to the levels
     * The parameter x indicates the direction of the gradient. x=1 means an horizontal
     * gradient typically used by a vertical bargraph, and x=0 a vertical gradient.
     */
    void initLevelsColors(int x)
    {
        int alpha = 200;
        { // level until -10 dB
            QColor c(40, 160, 40, alpha);
            QLinearGradient g(0,0,x,1-x);
            g.setCoordinateMode(QGradient::ObjectBoundingMode);
            g.setColorAt(0.0, c.lighter());
            g.setColorAt(0.2, c);
            g.setColorAt(0.8, c);
            g.setColorAt(0.9, c.darker(120));
            
            fLevel.push_back(-10);
            fBrush.push_back(QBrush(g));
        }
        
        { // level until -6 dB
            QColor c(160, 220, 20, alpha);
            QLinearGradient g(0,0,x,1-x);
            g.setCoordinateMode(QGradient::ObjectBoundingMode);
            g.setColorAt(0.0, c.lighter());
            g.setColorAt(0.2, c);
            g.setColorAt(0.8, c);
            g.setColorAt(0.9, c.darker(120));
            
            fLevel.push_back(-6);
            fBrush.push_back(QBrush(g));
        }
        
        { // level until -3 dB
            QColor c(220, 220, 20, alpha);
            QLinearGradient g(0,0,x,1-x);
            g.setCoordinateMode(QGradient::ObjectBoundingMode);
            g.setColorAt(0.0, c.lighter());
            g.setColorAt(0.2, c);
            g.setColorAt(0.8, c);
            g.setColorAt(0.9, c.darker(120));
            
            fLevel.push_back(-3);
            fBrush.push_back(QBrush(g));
        }
        
        { // level until -0 dB
            QColor c(240, 160, 20, alpha);
            QLinearGradient g(0,0,x,1-x);
            g.setCoordinateMode(QGradient::ObjectBoundingMode);
            g.setColorAt(0.0, c.lighter());
            g.setColorAt(0.2, c);
            g.setColorAt(0.8, c);
            g.setColorAt(0.9, c.darker(120));
            
            fLevel.push_back(0);
            fBrush.push_back(QBrush(g));
        }
        
        { // until 10 dB (and over because last one)
            QColor c(240,  0, 20, alpha);   // ColorOver
            QLinearGradient g(0,0,x,1-x);
            g.setCoordinateMode(QGradient::ObjectBoundingMode);
            g.setColorAt(0.0, c.lighter());
            g.setColorAt(0.2, c);
            g.setColorAt(0.8, c);
            g.setColorAt(0.9, c.darker(120));
            
            fLevel.push_back(+10);
            fBrush.push_back(QBrush(g));
        }
    }
    
public:
    
    dbAbstractDisplay(FAUSTFLOAT lo, FAUSTFLOAT hi) : AbstractDisplay(lo, hi)
    {}
    
    /**
     * set the range of displayed values
     */
    virtual void setRange(FAUSTFLOAT lo, FAUSTFLOAT hi)
    {
        AbstractDisplay::setRange(lo, hi);
        fScaleMin = dB2Scale(fMin);
        fScaleMax = dB2Scale(fMax);
    }
};

/**
 * Small rectangular LED display which color changes with the level in dB
 */
class dbLED : public dbAbstractDisplay
{
    
protected:
    
    /**
     * Draw the LED using a color depending of its value in dB
     */
    virtual void paintEvent(QPaintEvent*)
    {
        QPainter painter(this);
        painter.drawRect(rect());
        
        if (fValue <= fLevel[0]) {
            
            // interpolate the first color on the alpha channel
            QColor c(40, 160, 40) ;
            FAUSTFLOAT a = (fValue-fMin)/(fLevel[0]-fMin);
            c.setAlphaF(a);
            painter.fillRect(rect(), c);
            
        } else {
            
            // find the minimal level > value
            size_t l = fLevel.size()-1; while (fValue < fLevel[l] && l > 0) l--;
            painter.fillRect(rect(), fBrush[l]);
        }
    }
    
public:
    
    dbLED(FAUSTFLOAT lo, FAUSTFLOAT hi) : dbAbstractDisplay(lo,hi)
    {
        setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        initLevelsColors(1);
    }
    
    virtual QSize sizeHint() const
    {
        return QSize(16, 8);
    }
};

/**
 * Small rectangular LED display which intensity (alpha channel) changes according to the value
 */
class LED : public AbstractDisplay
{
    
protected:
    
    QColor fColor;
    
    /**
     * Draw the LED using a transparency depending of its value
     */
    virtual void paintEvent(QPaintEvent *)
    {
        QPainter painter(this);
        painter.drawRect(rect());
        // interpolate the first color on the alpha channel
        QColor c = fColor ;
        FAUSTFLOAT a = (fValue-fMin)/(fMax-fMin);
        c.setAlphaF(a);
        painter.fillRect(rect(), c);
    }
    
public:
    
    LED(FAUSTFLOAT lo, FAUSTFLOAT hi) : AbstractDisplay(lo,hi), fColor("yellow")
    {
        setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    }
    
    virtual QSize sizeHint() const
    {
        return QSize(16, 8);
    }
};

/**
 * A simple bargraph that detect automatically its direction
 */
class linBargraph : public AbstractDisplay
{
    
protected:
    
    QBrush fBrush;
    
    /**
     * No scale implemented yet
     */
    void paintScale(QPainter* painter) const
    {
        painter->drawRect(0,0,width(),height());
    }
    
    /**
     * The length of the rectangle is proportional to the value
     */
    void paintContent(QPainter* painter) const
    {
        int     w = width();
        int     h = height();
        FAUSTFLOAT   v = (fValue-fMin)/(fMax-fMin);
        
        if (h > w) {
            // draw vertical rectangle
            painter->fillRect(0,(1-v)*h,w, v*h, fBrush);
        } else {
            // draw horizontal rectangle
            painter->fillRect(0, 0, v*w, h, fBrush);
        }
    }
    
    virtual void paintEvent(QPaintEvent *)
    {
        QPainter painter(this);
        paintContent(&painter);
        paintScale(&painter);
    }
    
public:
    
    linBargraph(FAUSTFLOAT lo, FAUSTFLOAT hi) : AbstractDisplay(lo,hi)
    {
        // compute the brush that will be used to
        // paint the value
        QColor c(0xffa500);                 // orange
        int x = int(height() < width());    // gradient direction
        QLinearGradient g(0,0,x,1-x);
        g.setCoordinateMode(QGradient::ObjectBoundingMode);
        g.setColorAt(0.0, c.lighter());
        g.setColorAt(0.2, c);
        g.setColorAt(0.8, c);
        g.setColorAt(0.9, c.darker(120));
        fBrush = QBrush(g);
    }
};

/**
 * A simple vertical bargraph
 */
class linVerticalBargraph : public linBargraph
{
    
public:
    
    linVerticalBargraph(FAUSTFLOAT lo, FAUSTFLOAT hi) : linBargraph(lo,hi)
    {
        setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    }
    
    virtual QSize sizeHint() const
    {
        return QSize(16, 128);
    }
};

/**
 * A simple horizontal bargraph
 */
class linHorizontalBargraph : public linBargraph
{
    
public:
    
    linHorizontalBargraph(FAUSTFLOAT lo, FAUSTFLOAT hi) : linBargraph(lo,hi)
    {
        setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    }
    
    virtual QSize sizeHint() const
    {
        return QSize(128, 16);
    }
};

/**
 * A dB Bargraph with a scale of colors
 */
class dbBargraph : public dbAbstractDisplay
{
    
protected:
    
    QBrush  fBackColor;
    
    // These two abstract methods are implemented
    // according to the vertical or horizontal direction
    // in dbVerticalBargraph and dbHorizontalBargraph
    virtual void paintMark(QPainter* painter, FAUSTFLOAT v) const = 0;
    virtual int paintSegment(QPainter* painter, int pos, FAUSTFLOAT v, const QBrush& b) const = 0;
    
    /**
     * Draw the logarithmic scale
     */
    void paintScale(QPainter* painter) const
    {
        painter->fillRect(0,0,width(),height(), fBackColor);
        painter->save();
        painter->setPen(QColor(0x6699aa)); //0xffa500));
        for (FAUSTFLOAT v = -10; v > fMin; v -= 10) paintMark(painter, v);
        for (FAUSTFLOAT v = -6; v < fMax; v += 3) paintMark(painter, v);
        painter->restore();
    }
    
    /**
     * Draw the content using colored segments
     */
    void paintContent(QPainter* painter) const
    {
        size_t l = fLevel.size();
        
        FAUSTFLOAT p = -1;   // fake value indicates to start from border
        size_t n = 0;
        // paint all the full segments < fValue
        for (n = 0; (n < l) && (fValue > fLevel[n]); n++) {
            p = paintSegment(painter, p, fLevel[n], fBrush[n]);
        }
        // paint the last segment
        if (n == l) n = n-1;
        p=paintSegment(painter, p, fValue, fBrush[n]);
        
        painter->drawRect(0,0,width(),height());
    }
    
    virtual void paintEvent(QPaintEvent *)
    {
        QPainter painter(this);
        paintScale(&painter);
        paintContent(&painter);
    }
    
public:
    
    dbBargraph(FAUSTFLOAT lo, FAUSTFLOAT hi) : dbAbstractDisplay(lo,hi)
    {
        QFont f = this->font();
        f.setPointSize(6);
        this->setFont(f);
        fBackColor = QBrush(QColor(20,20,20));
    }
};

/**
 * Vertical dB Bargraph
 */
class dbVerticalBargraph : public dbBargraph
{
    
protected:
    /**
     * Convert a dB value into a vertical position
     */
    FAUSTFLOAT dB2y(FAUSTFLOAT dB) const
    {
        FAUSTFLOAT s0 = fScaleMin;
        FAUSTFLOAT s1 = fScaleMax;
        FAUSTFLOAT sx = dB2Scale(dB);
        int h = height();
        return h - h*(s0-sx)/(s0-s1);
    }
    
    /**
     * Paint a vertical graduation mark
     */
    virtual void paintMark(QPainter* painter, FAUSTFLOAT v) const
    {
        int n = 10;
        int y = dB2y(v);
        QRect r(0,y-n,width()-1,2*n);
        if (v > 0.0) {
            painter->drawText(r, Qt::AlignRight|Qt::AlignVCenter, QString::number(v).prepend('+'));
        } else {
            painter->drawText(r, Qt::AlignRight|Qt::AlignVCenter, QString::number(v));
        }
    }
    
    /**
     * Paint a color segment
     */
    virtual int paintSegment(QPainter* painter, int pos, FAUSTFLOAT v, const QBrush& b) const
    {
        if (pos == -1) pos = height();
        FAUSTFLOAT y = dB2y(v);
        painter->fillRect(0, y, width(), pos-y+1, b);
        return y;
    }
    
public:
    
    dbVerticalBargraph(FAUSTFLOAT lo, FAUSTFLOAT hi) : dbBargraph(lo,hi)
    {
        setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        initLevelsColors(1);
    }
    
    virtual QSize sizeHint() const
    {
        return QSize(18, 256);
    }
};

/**
 * Horizontal dB Bargraph
 */
class dbHorizontalBargraph : public dbBargraph
{
    
protected:
    
    /**
     * Convert a dB value into an horizontal position
     */
    FAUSTFLOAT dB2x(FAUSTFLOAT dB) const
    {
        FAUSTFLOAT s0 = fScaleMin;
        FAUSTFLOAT s1 = fScaleMax;
        FAUSTFLOAT sx = dB2Scale(dB);
        int    w = width();
        return w - w*(s1-sx)/(s1-s0);
    }
    
    /**
     * Paint an horizontal graduation mark
     */
    void paintMark(QPainter* painter, FAUSTFLOAT v) const
    {
        int n = 10;
        int x = dB2x(v);
        QRect r(x-n,0,2*n, height());
        painter->drawText(r, Qt::AlignHCenter|Qt::AlignVCenter, QString::number(v));
    }
    
    /**
     * Paint a horizontal color segment
     */
    int paintSegment(QPainter* painter, int pos, FAUSTFLOAT v, const QBrush& b) const
    {
        if (pos == -1) pos = 0;
        FAUSTFLOAT x = dB2x(v);
        painter->fillRect(pos, 0, x-pos, height(), b);
        return x;
    }
    
public:
    
    dbHorizontalBargraph(FAUSTFLOAT lo, FAUSTFLOAT hi) : dbBargraph(lo,hi)
    {
        setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        initLevelsColors(0);
    }
    
    virtual QSize sizeHint() const
    {
        return QSize(256, 18);
    }
    
};

//
//===============================END DISPLAYS====================================

/******************************************************************************
 *******************************************************************************
 
 IMPLEMENTATION OF GUI ITEMS
 (QT 4.3 for FAUST)
 
 *******************************************************************************
 *******************************************************************************/


/**
 * A push button that controls/reflects the value (O/1)
 * of a zone.
 */
class uiButton : public QObject, public uiItem
{
    Q_OBJECT
    
public:
    
    QAbstractButton* 	fButton;
    
    uiButton(GUI* ui, FAUSTFLOAT* zone, QAbstractButton* b) : uiItem(ui, zone), fButton(b) {}
    
    virtual void reflectZone()
    {
        FAUSTFLOAT v = *fZone;
        fCache = v;
        fButton->setDown( v > 0.0 );
    }
    
    public slots :
    void pressed()		{ modifyZone(1.0); }
    void released()		{ modifyZone(0.0); }
};


/**
 * A checkbox that controls/reflects the value (O/1)
 * of a zone.
 */
class uiCheckButton : public QObject, public uiItem
{
    Q_OBJECT
    
public:
    
    QCheckBox* 	fCheckBox;
    
    uiCheckButton(GUI* ui, FAUSTFLOAT* zone, QCheckBox* b) : uiItem(ui, zone), fCheckBox(b) {}
    
    virtual void reflectZone()
    {
        FAUSTFLOAT v = *fZone;
        fCache = v;
        fCheckBox->setCheckState((v < 0.5) ? Qt::Unchecked : Qt::Checked);
    }
    
    public slots :
    void setState(int v)		{ modifyZone(FAUSTFLOAT(v>0)); }
};

/**
 * A slider that controls/reflects the value (min..max)
 * of a zone.
 */
class uiSlider : public QObject, public uiItem
{
    Q_OBJECT
    
protected:
    
    QAbstractSlider* 	fSlider;
    FAUSTFLOAT			fCur;
    FAUSTFLOAT			fMin;
    FAUSTFLOAT			fMax;
    FAUSTFLOAT			fStep;
    ValueConverter*		fConverter;
    
public:
    
    uiSlider(GUI* ui, FAUSTFLOAT* zone, QAbstractSlider* slider, FAUSTFLOAT cur, FAUSTFLOAT lo, FAUSTFLOAT hi, FAUSTFLOAT step, MetaDataUI::Scale scale)
    : uiItem(ui, zone), fSlider(slider), fCur(cur), fMin(lo), fMax(hi), fStep(step)
    {
        // select appropriate converter according to scale mode
        if (scale == MetaDataUI::kLog) 			{ fConverter = new LogValueConverter(0, 10000, fMin, fMax); }
        else if (scale == MetaDataUI::kExp) 	{ fConverter = new ExpValueConverter(0, 10000, fMin, fMax); }
        else                                    { fConverter = new LinearValueConverter(0, 10000, fMin, fMax); }
        
        fSlider->setMinimum(0);
        fSlider->setMaximum(10000);
        fSlider->setValue(int(0.5+fConverter->faust2ui(fCur)));
        *fZone = fCur;
    }
    
    virtual ~uiSlider()
    {
        delete fConverter;
    }
    
    virtual void reflectZone()
    {
        FAUSTFLOAT v = *fZone;
        fCache = v;
        fSlider->setValue(int(0.5+fConverter->faust2ui(v)));
    }
    
    public slots :
    void setValue(int v)
    {
        modifyZone(fConverter->ui2faust(v));
    }
};


/**
 * A zone setter, an object that sets a zone with a predefined value
 * every time the set(bool) method is called. The boolean parameter
 * is here for compatibility with some signals and is ignored.
 */
class ZoneSetter : public QObject
{
    Q_OBJECT
    
protected:
    
    FAUSTFLOAT  fValue;
    FAUSTFLOAT* fZone;
    
public:
    explicit ZoneSetter(FAUSTFLOAT v, FAUSTFLOAT* z, QObject* parent = NULL):
    QObject(parent), fValue(v), fZone(z)
    {}
    
    public slots:
    void set(bool)
    {
        *fZone = fValue;
        // qDebug() << "setting " << fValue << " --> " << fZone;
    }
};


/**
 * A set of mutually exclusive radio buttons vertically
 * layed out. The names and values used for the radio buttons
 * are described in the string mdescr with the following syntax
 * "{'foo':3.14; 'faa':-0.34; ... 'fii':10.5}"
 */
class uiRadioButtons : public QGroupBox, public uiItem
{
    Q_OBJECT
    
protected:
    
    std::vector<double>          fValues;
    std::vector<QRadioButton*>   fButtons;
    
public:
    
    uiRadioButtons(GUI* ui, FAUSTFLOAT* z, const char* label,
                   FAUSTFLOAT cur, FAUSTFLOAT lo, FAUSTFLOAT hi, FAUSTFLOAT /*step*/,
                   bool vertical, const char* mdescr, QWidget* parent)
    : QGroupBox(label, parent),  uiItem(ui, z)
    {
        std::vector<std::string>  names;
        std::vector<double>  values;
        
        if (parseMenuList(mdescr, names, values)) {
            
            QBoxLayout* l;
            if (vertical) {
                l = new QVBoxLayout(this);
            } else {
                l = new QHBoxLayout(this);
            }
            l->setSpacing(5);
            
            QRadioButton*   defaultbutton = NULL;
            double          mindelta = FLT_MAX;
            
            for (unsigned int i = 0; i < names.size(); i++) {
                double v = values[i];
                if ((v >= lo) && (v <= hi)) {
                    
                    // It is a valid value included in slider's range
                    QRadioButton*   b = new QRadioButton(QString(names[i].c_str()), this);
                    ZoneSetter*     s = new ZoneSetter(v,z,b);
                    fValues.push_back(v);
                    fButtons.push_back(b);
                    connect(b,SIGNAL(clicked(bool)), s, SLOT(set(bool)));
                    l->addWidget(b);
                    
                    // Check if this item is a good candidate to represent the current value
                    double delta = fabs(cur-v);
                    if (delta < mindelta) {
                        mindelta = delta;
                        defaultbutton = b;
                    }
                }
            }
            // check the best candidate to represent the current value
            if (defaultbutton) { defaultbutton->setChecked(true); }
            setLayout(l);
        } else {
            std::cerr << "parseMenuList : (" << mdescr << ") is not a menu !\n";
        }
        *fZone = cur;
    }
    
    virtual void reflectZone()
    {
        FAUSTFLOAT v = *fZone;
        fCache = v;
        
        // select closest value
        int             defaultitem = -1;
        double          mindelta = FLT_MAX;
        
        for (unsigned int i=0; i<fValues.size(); i++) {
            double delta = fabs(fValues[i]-v);
            if (delta < mindelta) {
                mindelta = delta;
                defaultitem = i;
            }
        }
        if (defaultitem > -1) { fButtons[defaultitem]->setChecked(true); }
    }
};

/**
 * A popup menu. The names and values used for the menu items
 * are described in the string mdescr with the following syntax
 * "{'foo':3.14; 'faa':-0.34; ... 'fii':10.5}"
 */
class uiMenu : public QComboBox, public uiItem
{
    Q_OBJECT
    
protected:
    
    std::vector<double>  fValues;
    
public:
    
    uiMenu(GUI* ui, FAUSTFLOAT* z, const char* /*label*/,
           FAUSTFLOAT cur, FAUSTFLOAT lo, FAUSTFLOAT hi, FAUSTFLOAT /*step*/,
           const char* mdescr, QWidget* parent)
    : QComboBox(parent),  uiItem(ui, z)
    {
        std::vector<std::string>  names;
        std::vector<double>  values;
        
        if (parseMenuList(mdescr, names, values)) {
            
            int     defaultitem = -1;
            double  mindelta = FLT_MAX;
            
            for (unsigned int i = 0; i < names.size(); i++) {
                double v = values[i];
                if ((v >= lo) && (v <= hi)) {
                    
                    // It is a valid value : add corresponding menu item
                    addItem(QString(names[i].c_str()), v);
                    fValues.push_back(v);
                    
                    // Check if this item is a good candidate to represent the current value
                    double delta = fabs(cur-v);
                    if (delta < mindelta) {
                        mindelta = delta;
                        defaultitem = count()-1;
                    }
                }
            }
            // check the best candidate to represent the current value
            if (defaultitem > -1) { setCurrentIndex(defaultitem); }
        } else {
            std::cerr << "parseMenuList : (" << mdescr << ") is not a menu !\n";
        }
        connect(this,SIGNAL(activated(int)), this, SLOT(updateZone(int)));
        *fZone = cur;
    }
    
    virtual void reflectZone()
    {
        FAUSTFLOAT v = *fZone;
        fCache = v;
        
        // search closest value
        int defaultitem = -1;
        double mindelta = FLT_MAX;
        
        for (unsigned int i=0; i<fValues.size(); i++) {
            double delta = fabs(fValues[i]-v);
            if (delta < mindelta) {
                mindelta = delta;
                defaultitem = i;
            }
        }
        if (defaultitem > -1) { setCurrentIndex(defaultitem); }
    }
    
    public slots :
    
    void updateZone(int)
    {
        double x = itemData(currentIndex()).toDouble();
        *fZone = x;
    }
};

/**
 * A bargraph representing the value of a zone
 */
class uiBargraph : public QObject, public uiItem
{
    Q_OBJECT
    
protected:
    
    AbstractDisplay* fBar;
    
public:
    
    uiBargraph(GUI* ui, FAUSTFLOAT* zone, AbstractDisplay* bar, FAUSTFLOAT lo, FAUSTFLOAT hi)
    : uiItem(ui, zone), fBar(bar)
    {
        fBar->setRange(lo, hi);
        fBar->setValue(lo);
        *fZone = lo;
    }
    
    virtual void reflectZone()
    {
        FAUSTFLOAT v = *fZone;
        fCache = v;
        fBar->setValue(v);
    }
};

/**
 * A numerical entry that controls/reflects the value (min..max)
 * of a zone.
 */
class uiNumEntry : public QObject, public uiItem
{
    Q_OBJECT
    
protected:
    
    QDoubleSpinBox* 	fNumEntry;
    FAUSTFLOAT			fCur;
    FAUSTFLOAT			fMin;
    FAUSTFLOAT			fMax;
    FAUSTFLOAT			fStep;
    
public:
    
    uiNumEntry(GUI* ui, FAUSTFLOAT* zone, QDoubleSpinBox* numEntry, FAUSTFLOAT cur, FAUSTFLOAT lo, FAUSTFLOAT hi, FAUSTFLOAT step)
    : uiItem(ui, zone), fNumEntry(numEntry), fCur(cur), fMin(lo), fMax(hi), fStep(step)
    {
        int decimals = (fStep >= 1.0) ? 0 : int(0.5+log10(1.0/fStep));
        fNumEntry->setMinimum(fMin);
        fNumEntry->setMaximum(fMax);
        fNumEntry->setSingleStep(fStep);
        fNumEntry->setDecimals(decimals);
        fNumEntry->setValue(fCur);
        *fZone = fCur;
    }
    
    virtual void reflectZone()
    {
        FAUSTFLOAT v = *fZone;
        fCache = v;
        fNumEntry->setValue(v);
    }
    
    public slots :
    void setValue(double v)
    {
        modifyZone(FAUSTFLOAT(v));
    }
};

/******************************************************************************
 *******************************************************************************
 
 IMPLEMENTATION OF THE USER INTERFACE
 (QT 4.3 for FAUST)
 
 *******************************************************************************
 *******************************************************************************/
#if defined(HTTPCTRL) && defined(QRCODECTRL)
// a simple utility to retrieve an abstract qr code
// introduced to remove the dependency to qrencode
static QImage getQRCode(const QString& url, int padding)
{
    qrcodegen_Ecc errCorLvl = qrcodegen_Ecc_HIGH; //qrcodegen_Ecc_MEDIUM qrcodegen_Ecc_LOW Error correction level
    uint8_t qrcode[qrcodegen_BUFFER_LEN_MAX];
    uint8_t tempBuffer[qrcodegen_BUFFER_LEN_MAX];
    if (!qrcodegen_encodeText(url.toStdString().c_str(), tempBuffer, qrcode, errCorLvl, qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX, qrcodegen_Mask_AUTO, true))
        return QImage(1, 1, QImage::Format_RGB32);
    
    int size = qrcodegen_getSize(qrcode);
    QRgb colors[2];
    colors[0] = qRgb(255, 255, 255); 	// 0 is white
    colors[1] = qRgb(0, 0, 0); 			// 1 is black
    // build the QRCode image
    QImage image(size+2*padding, size+2*padding, QImage::Format_RGB32);
    // clear the image
    for (int y=0; y<size + 2*padding; y++) {
        for (int x=0; x<size + 2*padding; x++) {
            image.setPixel(x, y, colors[0]);
        }
    }
    // copy the qrcode inside
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            image.setPixel(x+padding, y+padding, colors[qrcodegen_getModule(qrcode, x, y) & 1]);
        }
    }
    return image;
}
#endif

class QTGUI : public QWidget, public GUI, public MetaDataUI
{
    Q_OBJECT
    
protected:
    
    QTimer*                 fTimer;
    std::stack<QWidget* > 	fGroupStack;
    
    QMainWindow*            fMainWindow;
    QVBoxLayout*            fGeneralLayout;
    
    QPixmap                 fQrCode;
    
    bool isTabContext()
    {
        //return fGroupStack.empty() || ((!fGroupStack.empty()) && (dynamic_cast<QTabWidget*>(fGroupStack.top()) != 0));
        return ((!fGroupStack.empty()) && (dynamic_cast<QTabWidget*>(fGroupStack.top()) != NULL));
    }
    
    /**
     * Insert a widget into the parent widget (the top of
     * the stack group). The label is used if this group is
     * a tab.
     */
    
    void insert(const char* label, QWidget* widget)
    {
        if (!fGroupStack.empty()) {
            QWidget* mother = fGroupStack.top();
            QTabWidget*	tab = dynamic_cast<QTabWidget*>(mother);
            if (tab) {
                tab->addTab(widget,label);
            } else {
                widget->setParent(mother);
                mother->layout()->addWidget(widget);
            }
        }
    }
    
    /**
     * Analyses a full label and activates the relevant options. Returns a simplified
     * label (without options) and an amount of stack adjustement (in case additional
     * containers were pushed on the stack).
     */
    
    int checkLabelOptions(QWidget* widget, const std::string& fullLabel, std::string& simplifiedLabel)
    {
        std::map<std::string, std::string> metadata;
        extractMetadata(fullLabel, simplifiedLabel, metadata);
        
        if (metadata.count("tooltip")) {
            widget->setToolTip(metadata["tooltip"].c_str());
        }
        if (metadata["option"] == "detachable") {
            //openHandleBox(simplifiedLabel.c_str());
            return 1;
        }
        
        // no adjustement of the stack needed
        return 0;
    }
    
    /**
     * Check if a tooltip is associated to a zone and add it to the corresponding widget
     */
    void checkForTooltip(FAUSTFLOAT* zone, QWidget* widget)
    {
        if (fTooltip.count(zone)) {
            widget->setToolTip(fTooltip[zone].c_str());
        }
    }
    
    void openBox(const char* fulllabel, QLayout* layout)
    {
        std::map<std::string, std::string> metadata;
        std::string label;
        extractMetadata(fulllabel, label, metadata);
        layout->setMargin(5);
        QWidget* box;
        
        label = startWith(label, "0x") ? "" : label;
        
        if (fGroupStack.empty()) {
            if (isTabContext()) {
                box = new QWidget(this);
                // set background color
                QPalette pal = box->palette();
                pal.setColor(box->backgroundRole(), QColor::fromRgb(150, 150, 150));
                box->setPalette(pal);
                
            } else if (label.size() > 0) {
                QGroupBox* group = new QGroupBox(this);
                group->setTitle(label.c_str());
                box = group;
                
            } else {
                // no label here we use simple widget
                layout->setMargin(0);
                box = new QWidget(this);
            }
            
            box->setLayout(layout);
            fGeneralLayout->addWidget(box);
            if (fGroupTooltip != "") {
                box->setToolTip(fGroupTooltip.c_str());
                fGroupTooltip = "";
            }
        } else {
            if (isTabContext()) {
                box = new QWidget();
                // set background color
                QPalette pal = box->palette();
                pal.setColor(box->backgroundRole(), QColor::fromRgb(150, 150, 150));
                box->setPalette(pal);
                
            } else if (label.size()>0) {
                QGroupBox* group = new QGroupBox();
                group->setTitle(label.c_str());
                box = group;
                
            } else {
                // no label here we use simple widget
                layout->setMargin(0);
                box = new QWidget;
            }
            
            box->setLayout(layout);
            if (fGroupTooltip != "") {
                box->setToolTip(fGroupTooltip.c_str());
                fGroupTooltip = "";
            }
        }
        insert(label.c_str(), box);
        fGroupStack.push(box);
    }
    
    void openTab(const char* label)
    {
        QTabWidget* group;
        
        if (fGroupStack.empty()) {
            group = new QTabWidget(this);
            fGeneralLayout->addWidget(group);
        } else {
            group = new QTabWidget();
        }
        
        insert(label, group);
        fGroupStack.push(group);
    }
    
    public slots:
    
    void update()
    {
        //std::cout << '.' << std::endl;
        //		updateAllZones();
        updateAllGuis();
    }
    
public:
    
    QTGUI(QWidget* parent) : QWidget(parent)
    {
        fGeneralLayout = new QVBoxLayout;
        setLayout(fGeneralLayout);
        QWidget::show();
        
        fMainWindow = NULL;
        fTimer = NULL;
    }
    
    QTGUI():QWidget()
    {
        fGeneralLayout = new QVBoxLayout;
        setLayout(fGeneralLayout);
        QWidget::show();
        
        fTimer = NULL;
        
        fMainWindow = new QMainWindow;
        QScrollArea *sa = new QScrollArea(fMainWindow);
        
        sa->setWidgetResizable(true);
        sa->setWidget(this);
        
        fMainWindow->setCentralWidget(sa);
    }
    
    virtual ~QTGUI()
    {
        delete fGeneralLayout;
    }
    
    QString styleSheet()
    {
        QString styleSheet("");
        QFile file(":/Grey.qss");
        
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            styleSheet = QLatin1String(file.readAll());
            file.close();
        }
        
        return styleSheet;
    }
    
    /**
     * Analyses the widget zone metadata declarations and takes
     * appropriate actions
     */
    virtual void declare(FAUSTFLOAT* zone, const char* key, const char* value)
    {
        MetaDataUI::declare(zone, key, value);
    }
    
#if defined(HTTPCTRL) && defined(QRCODECTRL)
    
    //
    // Returns the IP address of the machine (to be qrcoded)
    //
    QString extractIPnum()
    {
        QList<QHostAddress> ipAdresses = QNetworkInterface::allAddresses();
        QList<QHostAddress>::iterator it;
        QString localhost("localhost");
        
        for (it = ipAdresses.begin(); it != ipAdresses.end(); it++) {
            if ((*it).protocol() == QAbstractSocket::IPv4Protocol && (*it) != QHostAddress::LocalHost) {
                return it->toString();
            } else if((*it).protocol() == QAbstractSocket::IPv4Protocol && (*it) == QHostAddress::LocalHost) {
                localhost = it->toString();
            }
        }
        
        return localhost;
    }
    
    //
    // Used in HTTPD mode, display the QRCode of the URL of the application
    //
    void displayQRCode(int portnum)
    {
        QString url("http://");
        url += extractIPnum();
        url += ":";
        url += QString::number(portnum);
        displayQRCode(url, NULL);
    }
    
    void displayQRCode(const QString& url, QMainWindow* parent = NULL)
    {
        if (parent == NULL) {
            parent = new QMainWindow;
        }
        
        QWidget* centralWidget = new QWidget;
        parent->setCentralWidget(centralWidget);
        //    QTextEdit* httpdText = new QTextEdit(centralWidget);
        QTextBrowser* myBro = new QTextBrowser(centralWidget);
        
        //        //Construction of the flashcode
        //        const int padding = 5;
        //        QRcode* qrc = QRcode_encodeString(url.toLatin1().data(), 0, QR_ECLEVEL_H, QR_MODE_8, 1);
        //
        //        //   qDebug() << "QRcode width = " << qrc->width;
        //
        //        QRgb colors[2];
        //        colors[0] = qRgb(255, 255, 255); 	// 0 is white
        //        colors[1] = qRgb(0, 0, 0); 			// 1 is black
        //
        //        // build the QRCode image
        //        QImage image(qrc->width+2*padding, qrc->width+2*padding, QImage::Format_RGB32);
        //        // clear the image
        //        for (int y = 0; y < qrc->width+2*padding; y++) {
        //            for (int x = 0; x < qrc->width+2*padding; x++) {
        //                image.setPixel(x, y, colors[0]);
        //            }
        //        }
        //        // copy the qrcode inside
        //        for (int y = 0; y < qrc->width; y++) {
        //            for (int x = 0; x < qrc->width; x++) {
        //                image.setPixel(x+padding, y+padding, colors[qrc->data[y*qrc->width+x]&1]);
        //            }
        //        }
        
        const int padding = 5;
        QImage image = getQRCode (url, padding);
        //        QImage big = image.scaledToWidth(qrc->width*8);
        QImage big = image.scaledToWidth(image.width() * 8);
        QLabel* myLabel = new QLabel(centralWidget);
        
        fQrCode = QPixmap::fromImage(big);
        myLabel->setPixmap(fQrCode);
        
        //----Written Address
        
        QString sheet = QString::fromLatin1("a{ text-decoration: underline; color: white; font: Menlo; font-size: 14px }");
        //    myBro->document()->setDefaultStyleSheet(sheet);
        //    myBro->setStyleSheet("*{color: white; font: Menlo; font-size: 14px }");
        
        QString text("<br>Please connect to ");
        text += "<br><a href = " + url + ">"+ url+ "</a>";
        text += "<br>Or scan the QR code below";
        
        myBro->setOpenExternalLinks(true);
        myBro->setHtml(text);
        myBro->setAlignment(Qt::AlignCenter);
        myBro->setFixedWidth(big.width());
        //    myBro->setFixedHeight(myBro->minimumHeight());
        
        QGridLayout *mainLayout = new QGridLayout;
        mainLayout->addWidget(myBro, 0, 1);
        mainLayout->addWidget(myLabel, 1, 1);
        centralWidget->setLayout(mainLayout);
        centralWidget->show();
        centralWidget->adjustSize();
        parent->show();
    }
    
    bool toPNG(const QString& filename, QString& error)
    {
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly)) {
            fQrCode.save(&file, "PNG");
            return true;
        } else {
            error = "Impossible to write file.";
            return false;
        }
    }
#endif
    
    virtual bool run()
    {
        if (!fTimer) {
            fTimer = new QTimer(this);
            QObject::connect(fTimer, SIGNAL(timeout()), this, SLOT(update()));
            fTimer->start(100);
        }
        
        if (fMainWindow) {
            fMainWindow->show();
        }
        return true;
    }
    
    virtual void stop()
    {
        if (fTimer) {
            fTimer->stop();
            delete fTimer;
            fTimer = NULL;
        }
        
        GUI::stop();
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    // OPEN AND CLOSE GROUPS
    //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    virtual void openHorizontalBox(const char* label)
    {
        openBox(label, new QHBoxLayout());
    }
    
    virtual void openVerticalBox(const char* label)
    {
        openBox(label, new QVBoxLayout());
    }
    
    virtual void openFrameBox(const char* )
    {}
    
    virtual void openTabBox(const char* label)
    {
        openTab(label);
    }
    
    virtual void closeBox()
    {
        QWidget* group = fGroupStack.top();
        fGroupStack.pop();
        if (fGroupStack.empty()) {
            group->show();
            group->adjustSize();
        }
    }
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    // ADD BUTTONS AND CHECKBOX
    //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    virtual void addButton(const char* label, FAUSTFLOAT* zone)
    {
        QAbstractButton* 	w = new QPushButton(label);
        w->setAttribute(Qt::WA_MacNoClickThrough);
        uiButton* 			c = new uiButton(this, zone, w);
        
        insert(label, w);
        QObject::connect(w, SIGNAL(pressed()), c, SLOT(pressed()));
        QObject::connect(w, SIGNAL(released()), c, SLOT(released()));
        checkForTooltip(zone, w);
        clearMetadata();
    }
    
    virtual void addToggleButton(const char*, FAUSTFLOAT*)
    {}
    
    virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
    {
        QCheckBox* w = new QCheckBox(label);
        uiCheckButton* c = new uiCheckButton(this, zone, w);
        
        insert(label, w);
        QObject::connect(w, SIGNAL(stateChanged(int)), c, SLOT(setState(int)));
        checkForTooltip(zone, w);
        clearMetadata();
    }
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    // ADD NUMERICAL ENTRY
    //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        if (isKnob(zone)) {
            addVerticalKnob(label, zone, init, min, max, step);
            return;
        } else if (isRadio(zone)) {
            addVerticalRadioButtons(label, zone, init, min, max, step, fRadioDescription[zone].c_str());
            return;
        } else if (isMenu(zone)) {
            addMenu(label, zone, init, min, max, step, fMenuDescription[zone].c_str());
            return;
        }
        //insert(label, new QDoubleSpinBox());
        if (label && label[0]) openVerticalBox(label);
        QDoubleSpinBox*     w = new QDoubleSpinBox();
        uiNumEntry*         c = new uiNumEntry(this, zone, w, init, min, max, step);
        insert(label, w);
        std::string suffix = " " + fUnit[zone];
        w->setSuffix(suffix.c_str());
        QObject::connect(w, SIGNAL(valueChanged(double)), c, SLOT(setValue(double)));
        if (label && label[0]) closeBox();
        checkForTooltip(zone, w);
        clearMetadata();
    }
    
    // special num entry without buttons
    virtual void addNumDisplay(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        //insert(label, new QDoubleSpinBox());
        if (label && label[0]) openVerticalBox(label);
        QDoubleSpinBox*     w = new QDoubleSpinBox();
        w->setAlignment(Qt::AlignHCenter);
#if 1
        w->setStyleSheet(
                         "QDoubleSpinBox {"
                         "border: 2px solid orange;"
                         "border-radius: 5px;"
                         "font-size: 8pt;"
                         "}"
                         );
#endif
        uiNumEntry* c = new uiNumEntry(this, zone, w, init, min, max, step);
        insert(label, w);
        w->setButtonSymbols(QAbstractSpinBox::NoButtons);
        std::string suffix = " " + fUnit[zone];
        w->setSuffix(suffix.c_str());
        QObject::connect(w, SIGNAL(valueChanged(double)), c, SLOT(setValue(double)));
        if (label && label[0]) closeBox();
        checkForTooltip(zone, w);
        // Metadata is not cleared here, since it will be by the enclosing element calling addNumDisplay
    }
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    // ADD KNOBS
    //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    virtual void addVerticalKnob(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        openVerticalBox(label);
        QDial* w = new QDial(); //qsynthKnob();
        uiSlider* c = new uiSlider(this, zone, w, init, min, max, step, getScale(zone));
        insert(label, w);
        w->setStyle(new qsynthDialVokiStyle());
        w->setFocusPolicy(Qt::StrongFocus);
        w->setWrapping(DIAL_WRAPPING);
        QObject::connect(w, SIGNAL(valueChanged(int)), c, SLOT(setValue(int)));
        addNumDisplay(0, zone, init, min, max, step);
        
        // compute the size of the knob+display
        int width = int(64*pow(2,fGuiSize[zone]));
        int height = int(100*pow(2,fGuiSize[zone]));
        fGroupStack.top()->setMinimumSize(width,height);
        fGroupStack.top()->setMaximumSize(width,height);
        
        closeBox();
        checkForTooltip(zone, w);
        clearMetadata();
    }
    
    virtual void addHorizontalKnob(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        openHorizontalBox(label);
        QDial* w = new QDial(); //new qsynthKnob();
        uiSlider* c = new uiSlider(this, zone, w, init, min, max, step, getScale(zone));
        insert(label, w);
        w->setStyle(new qsynthDialVokiStyle());
        w->setFocusPolicy(Qt::StrongFocus);
        w->setWrapping(DIAL_WRAPPING);
        QObject::connect(w, SIGNAL(valueChanged(int)), c, SLOT(setValue(int)));
        addNumDisplay(0, zone, init, min, max, step);
        closeBox();
        checkForTooltip(zone, w);
        clearMetadata();
    }
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    // ADD SLIDERS
    //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        if (isKnob(zone)) {
            addVerticalKnob(label, zone, init, min, max, step);
            return;
        } else if (isRadio(zone)) {
            addVerticalRadioButtons(label, zone, init, min, max, step, fRadioDescription[zone].c_str());
            return;
        } else if (isMenu(zone)) {
            addMenu(label, zone, init, min, max, step, fMenuDescription[zone].c_str());
            return;
        }
        openVerticalBox(label);
        QSlider* w = new QSlider(Qt::Vertical);
        w->setMinimumHeight(160);
        w->setMinimumWidth(34);
        //w->setTickPosition(QSlider::TicksBothSides);
        uiSlider* c = new uiSlider(this, zone, w, init, min, max, step, getScale(zone));
        insert(label, w);
        QObject::connect(w, SIGNAL(valueChanged(int)), c, SLOT(setValue(int)));
        addNumDisplay(0, zone, init, min, max, step);
        closeBox();
        checkForTooltip(zone, w);
        clearMetadata();
    }
    
    virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        if (isKnob(zone)) {
            addHorizontalKnob(label, zone, init, min, max, step);
            return;
        } else if (isRadio(zone)) {
            addHorizontalRadioButtons(label, zone, init, min, max, step, fRadioDescription[zone].c_str());
            return;
        } else if (isMenu(zone)) {
            addMenu(label, zone, init, min, max, step, fMenuDescription[zone].c_str());
            return;
        }
        openHorizontalBox(label);
        QSlider* w = new QSlider(Qt::Horizontal);
        w->setMinimumHeight(34);
        w->setMinimumWidth(160);
        //w->setTickPosition(QSlider::TicksBothSides);
        uiSlider* c = new uiSlider(this, zone, w, init, min, max, step, getScale(zone));
        insert(label, w);
        QObject::connect(w, SIGNAL(valueChanged(int)), c, SLOT(setValue(int)));
        addNumDisplay(0, zone, init, min, max, step);
        closeBox();
        checkForTooltip(zone, w);
        clearMetadata();
    }
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    // ADD RADIO-BUTTONS AND MENUS
    //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    virtual void addVerticalRadioButtons(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min,
                                         FAUSTFLOAT max, FAUSTFLOAT step, const char* mdescr)
    {
        uiRadioButtons* w = new uiRadioButtons(this, zone, label, init, min, max, step, true, mdescr, 0);
        insert(label, w);
        checkForTooltip(zone, w);
        clearMetadata();
    }
    
    virtual void addHorizontalRadioButtons(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min,
                                           FAUSTFLOAT max, FAUSTFLOAT step, const char* mdescr)
    {
        uiRadioButtons* w = new uiRadioButtons(this, zone, label, init, min, max, step, false, mdescr, 0);
        insert(label, w);
        checkForTooltip(zone, w);
        clearMetadata();
    }
    
    virtual void addMenu(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min,
                         FAUSTFLOAT max, FAUSTFLOAT step, const char* mdescr)
    {
        if (label && label[0]) openVerticalBox(label);
        uiMenu* w = new uiMenu(this, zone, label, init, min, max, step, mdescr, 0);
        insert(label, w);
        checkForTooltip(zone, w);
        if (label && label[0]) closeBox();
        clearMetadata();
    }
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    // ADD BARGRAPHS
    //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
    {
        openVerticalBox(label);
        if (isNumerical(zone)) {
            addNumDisplay(0, zone, min, min, max, (max-min)/pow(10, FLT_DIG));
        } else {
            AbstractDisplay* bargraph;
            bool db = (fUnit[zone] == "dB");
            if (isLed(zone)) {
                if (db) {
                    bargraph = new dbLED(min, max);
                } else {
                    bargraph = new LED(min, max);
                }
            } else {
                if (db) {
                    bargraph = new dbHorizontalBargraph(min, max);
                } else {
                    bargraph = new linHorizontalBargraph(min, max);
                }
            }
            
            new uiBargraph(this, zone, bargraph, min, max);
            insert(label, bargraph);
            checkForTooltip(zone, bargraph);
        }
        closeBox();
        clearMetadata();
    }
    
    virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
    {
        openVerticalBox(label);
        if (isNumerical(zone)) {
            addNumDisplay(0, zone, min, min, max, (max-min)/pow(10, FLT_DIG));
        } else {
            AbstractDisplay* bargraph;
            bool db = (fUnit[zone] == "dB");
            if (isLed(zone)) {
                if (db) {
                    bargraph = new dbLED(min, max);
                } else {
                    bargraph = new LED(min, max);
                }
            } else {
                if (db) {
                    bargraph = new dbVerticalBargraph(min, max);
                } else {
                    bargraph = new linVerticalBargraph(min, max);
                }
            }
            new uiBargraph(this, zone, bargraph, min, max);
            insert(label, bargraph);
            addNumDisplay(0, zone, min, min, max, (max-min)/1000.0);
            checkForTooltip(zone, bargraph);
        }
        closeBox();
        clearMetadata();
    }
};

#ifdef _WIN32
# pragma warning (default: 4100)
#endif

#endif
/**************************  END  QTUI.h **************************/
/************************** BEGIN audio.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __audio__
#define __audio__

#include <set>
#include <utility>

class dsp;

typedef void (* shutdown_callback)(const char* message, void* arg);

typedef void (* compute_callback)(void* arg);

class audio {
    
    protected:
    
        shutdown_callback fShutdown;    // Shutdown callback
        void* fShutdownArg;             // Shutdown callback data
    
        std::set<std::pair<compute_callback, void*> > fComputeCallbackList;
    
    public:
    
        audio():fShutdown(nullptr), fShutdownArg(nullptr) {}
        virtual ~audio() {}

        virtual bool init(const char* name, dsp* dsp) = 0;
    
        virtual bool start() = 0;
        virtual void stop() = 0;
    
        void setShutdownCallback(shutdown_callback cb, void* arg)
        {
            fShutdown = cb;
            fShutdownArg = arg;
        }
    
        void addControlCallback(compute_callback cb, void* arg)
        {
            fComputeCallbackList.insert(std::make_pair(cb, arg));
        }
        bool removeControlCallback(compute_callback cb, void* arg)
        {
            return (fComputeCallbackList.erase(std::make_pair(cb, arg)) == 1);
        }
        void runControlCallbacks()
        {
            for (auto& it : fComputeCallbackList) {
                it.first(it.second);
            }
        }
    
        virtual int getBufferSize() = 0;
        virtual int getSampleRate() = 0;

        virtual int getNumInputs() = 0;
        virtual int getNumOutputs() = 0;

        virtual float getCPULoad() { return 0.f; }
};
					
#endif
/**************************  END  audio.h **************************/
/************************** BEGIN misc.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <string>


using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key] = value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key] = value; }
};

static int lsr(int x, int n) { return int(((unsigned int)x) >> n); }

static int int2pow2(int x) { int r = 0; while ((1<<r) < x) r++; return r; }

static long lopt(char* argv[], const char* name, long def)
{
	int	i;
    for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return std::atoi(argv[i+1]);
	return def;
}

static bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

static const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

static std::string pathToContent(const std::string& path)
{
    std::ifstream file(path.c_str(), std::ifstream::binary);
    
    file.seekg(0, file.end);
    int size = int(file.tellg());
    file.seekg(0, file.beg);
    
    // And allocate buffer to that a single line can be read...
    char* buffer = new char[size + 1];
    file.read(buffer, size);
    
    // Terminate the string
    buffer[size] = 0;
    std::string result = buffer;
    file.close();
    delete [] buffer;
    return result;
}

#endif

/**************************  END  misc.h **************************/

#ifdef IOS
/************************** BEGIN APIUI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef API_UI_H
#define API_UI_H

#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <map>


class APIUI : public PathBuilder, public Meta, public UI
{
    public:
    
        enum ItemType { kButton = 0, kCheckButton, kVSlider, kHSlider, kNumEntry, kHBargraph, kVBargraph };
  
    protected:
    
        enum { kLin = 0, kLog = 1, kExp = 2 };
    
        int fNumParameters;
        std::vector<std::string> fPaths;
        std::vector<std::string> fLabels;
        std::map<std::string, int> fPathMap;
        std::map<std::string, int> fLabelMap;
        std::vector<ValueConverter*> fConversion;
        std::vector<FAUSTFLOAT*> fZone;
        std::vector<FAUSTFLOAT> fInit;
        std::vector<FAUSTFLOAT> fMin;
        std::vector<FAUSTFLOAT> fMax;
        std::vector<FAUSTFLOAT> fStep;
        std::vector<ItemType> fItemType;
        std::vector<std::map<std::string, std::string> > fMetaData;
        std::vector<ZoneControl*> fAcc[3];
        std::vector<ZoneControl*> fGyr[3];

        // Screen color control
        // "...[screencolor:red]..." etc.
        bool fHasScreenControl;      // true if control screen color metadata
        ZoneReader* fRedReader;
        ZoneReader* fGreenReader;
        ZoneReader* fBlueReader;

        // Current values controlled by metadata
        std::string fCurrentUnit;
        int fCurrentScale;
        std::string fCurrentAcc;
        std::string fCurrentGyr;
        std::string fCurrentColor;
        std::string fCurrentTooltip;
        std::map<std::string, std::string> fCurrentMetadata;
    
        // Add a generic parameter
        virtual void addParameter(const char* label,
                                FAUSTFLOAT* zone,
                                FAUSTFLOAT init,
                                FAUSTFLOAT min,
                                FAUSTFLOAT max,
                                FAUSTFLOAT step,
                                ItemType type)
        {
            std::string path = buildPath(label);
            fPathMap[path] = fLabelMap[label] = fNumParameters++;
            fPaths.push_back(path);
            fLabels.push_back(label);
            fZone.push_back(zone);
            fInit.push_back(init);
            fMin.push_back(min);
            fMax.push_back(max);
            fStep.push_back(step);
            fItemType.push_back(type);
            
            // handle scale metadata
            switch (fCurrentScale) {
                case kLin:
                    fConversion.push_back(new LinearValueConverter(0, 1, min, max));
                    break;
                case kLog:
                    fConversion.push_back(new LogValueConverter(0, 1, min, max));
                    break;
                case kExp: fConversion.push_back(new ExpValueConverter(0, 1, min, max));
                    break;
            }
            fCurrentScale = kLin;
            
            if (fCurrentAcc.size() > 0 && fCurrentGyr.size() > 0) {
                std::cerr << "warning : 'acc' and 'gyr' metadata used for the same " << label << " parameter !!\n";
            }

            // handle acc metadata "...[acc : <axe> <curve> <amin> <amid> <amax>]..."
            if (fCurrentAcc.size() > 0) {
                std::istringstream iss(fCurrentAcc);
                int axe, curve;
                double amin, amid, amax;
                iss >> axe >> curve >> amin >> amid >> amax;

                if ((0 <= axe) && (axe < 3) &&
                    (0 <= curve) && (curve < 4) &&
                    (amin < amax) && (amin <= amid) && (amid <= amax))
                {
                    fAcc[axe].push_back(new CurveZoneControl(zone, curve, amin, amid, amax, min, init, max));
                } else {
                    std::cerr << "incorrect acc metadata : " << fCurrentAcc << std::endl;
                }
                fCurrentAcc = "";
            }
       
            // handle gyr metadata "...[gyr : <axe> <curve> <amin> <amid> <amax>]..."
            if (fCurrentGyr.size() > 0) {
                std::istringstream iss(fCurrentGyr);
                int axe, curve;
                double amin, amid, amax;
                iss >> axe >> curve >> amin >> amid >> amax;

                if ((0 <= axe) && (axe < 3) &&
                    (0 <= curve) && (curve < 4) &&
                    (amin < amax) && (amin <= amid) && (amid <= amax))
                {
                    fGyr[axe].push_back(new CurveZoneControl(zone, curve, amin, amid, amax, min, init, max));
                } else {
                    std::cerr << "incorrect gyr metadata : " << fCurrentGyr << std::endl;
                }
                fCurrentGyr = "";
            }
        
            // handle screencolor metadata "...[screencolor:red|green|blue|white]..."
            if (fCurrentColor.size() > 0) {
                if ((fCurrentColor == "red") && (fRedReader == 0)) {
                    fRedReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else if ((fCurrentColor == "green") && (fGreenReader == 0)) {
                    fGreenReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else if ((fCurrentColor == "blue") && (fBlueReader == 0)) {
                    fBlueReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else if ((fCurrentColor == "white") && (fRedReader == 0) && (fGreenReader == 0) && (fBlueReader == 0)) {
                    fRedReader = new ZoneReader(zone, min, max);
                    fGreenReader = new ZoneReader(zone, min, max);
                    fBlueReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else {
                    std::cerr << "incorrect screencolor metadata : " << fCurrentColor << std::endl;
                }
            }
            fCurrentColor = "";
            
            fMetaData.push_back(fCurrentMetadata);
            fCurrentMetadata.clear();
        }

        int getZoneIndex(std::vector<ZoneControl*>* table, int p, int val)
        {
            FAUSTFLOAT* zone = fZone[p];
            for (size_t i = 0; i < table[val].size(); i++) {
                if (zone == table[val][i]->getZone()) return int(i);
            }
            return -1;
        }
    
        void setConverter(std::vector<ZoneControl*>* table, int p, int val, int curve, double amin, double amid, double amax)
        {
            int id1 = getZoneIndex(table, p, 0);
            int id2 = getZoneIndex(table, p, 1);
            int id3 = getZoneIndex(table, p, 2);
            
            // Deactivates everywhere..
            if (id1 != -1) table[0][id1]->setActive(false);
            if (id2 != -1) table[1][id2]->setActive(false);
            if (id3 != -1) table[2][id3]->setActive(false);
            
            if (val == -1) { // Means: no more mapping...
                // So stay all deactivated...
            } else {
                int id4 = getZoneIndex(table, p, val);
                if (id4 != -1) {
                    // Reactivate the one we edit...
                    table[val][id4]->setMappingValues(curve, amin, amid, amax, fMin[p], fInit[p], fMax[p]);
                    table[val][id4]->setActive(true);
                } else {
                    // Allocate a new CurveZoneControl which is 'active' by default
                    FAUSTFLOAT* zone = fZone[p];
                    table[val].push_back(new CurveZoneControl(zone, curve, amin, amid, amax, fMin[p], fInit[p], fMax[p]));
                }
            }
        }
    
        void getConverter(std::vector<ZoneControl*>* table, int p, int& val, int& curve, double& amin, double& amid, double& amax)
        {
            int id1 = getZoneIndex(table, p, 0);
            int id2 = getZoneIndex(table, p, 1);
            int id3 = getZoneIndex(table, p, 2);
            
            if (id1 != -1) {
                val = 0;
                curve = table[val][id1]->getCurve();
                table[val][id1]->getMappingValues(amin, amid, amax);
            } else if (id2 != -1) {
                val = 1;
                curve = table[val][id2]->getCurve();
                table[val][id2]->getMappingValues(amin, amid, amax);
            } else if (id3 != -1) {
                val = 2;
                curve = table[val][id3]->getCurve();
                table[val][id3]->getMappingValues(amin, amid, amax);
            } else {
                val = -1; // No mapping
                curve = 0;
                amin = -100.;
                amid = 0.;
                amax = 100.;
            }
        }

     public:
    
        enum Type { kAcc = 0, kGyr = 1, kNoType };
   
        APIUI() : fNumParameters(0), fHasScreenControl(false), fRedReader(0), fGreenReader(0), fBlueReader(0), fCurrentScale(kLin)
        {}

        virtual ~APIUI()
        {
            std::vector<ValueConverter*>::iterator it1;
            for (it1 = fConversion.begin(); it1 != fConversion.end(); it1++) {
                delete(*it1);
            }

            std::vector<ZoneControl*>::iterator it2;
            for (int i = 0; i < 3; i++) {
                for (it2 = fAcc[i].begin(); it2 != fAcc[i].end(); it2++) {
                    delete(*it2);
                }
                for (it2 = fGyr[i].begin(); it2 != fGyr[i].end(); it2++) {
                    delete(*it2);
                }
            }
            
            delete fRedReader;
            delete fGreenReader;
            delete fBlueReader;
        }
    
        // -- widget's layouts

        virtual void openTabBox(const char* label)          { pushLabel(label); }
        virtual void openHorizontalBox(const char* label)   { pushLabel(label); }
        virtual void openVerticalBox(const char* label)     { pushLabel(label); }
        virtual void closeBox()                             { popLabel(); }

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addParameter(label, zone, 0, 0, 1, 1, kButton);
        }

        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addParameter(label, zone, 0, 0, 1, 1, kCheckButton);
        }

        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addParameter(label, zone, init, min, max, step, kVSlider);
        }

        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addParameter(label, zone, init, min, max, step, kHSlider);
        }

        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addParameter(label, zone, init, min, max, step, kNumEntry);
        }

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addParameter(label, zone, min, min, max, (max-min)/1000.0, kHBargraph);
        }

        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addParameter(label, zone, min, min, max, (max-min)/1000.0, kVBargraph);
        }
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            // Keep matadata
            fCurrentMetadata[key] = val;
            
            if (strcmp(key, "scale") == 0) {
                if (strcmp(val, "log") == 0) {
                    fCurrentScale = kLog;
                } else if (strcmp(val, "exp") == 0) {
                    fCurrentScale = kExp;
                } else {
                    fCurrentScale = kLin;
                }
            } else if (strcmp(key, "unit") == 0) {
                fCurrentUnit = val;
            } else if (strcmp(key, "acc") == 0) {
                fCurrentAcc = val;
            } else if (strcmp(key, "gyr") == 0) {
                fCurrentGyr = val;
            } else if (strcmp(key, "screencolor") == 0) {
                fCurrentColor = val; // val = "red", "green", "blue" or "white"
            } else if (strcmp(key, "tooltip") == 0) {
                fCurrentTooltip = val;
            }
        }

        virtual void declare(const char* key, const char* val)
        {}

		//-------------------------------------------------------------------------------
		// Simple API part
		//-------------------------------------------------------------------------------
		int getParamsCount() { return fNumParameters; }
        int getParamIndex(const char* path)
        {
            if (fPathMap.find(path) != fPathMap.end()) {
                return fPathMap[path];
            } else if (fLabelMap.find(path) != fLabelMap.end()) {
                return fLabelMap[path];
            } else {
                return -1;
            }
        }
        const char* getParamAddress(int p) { return fPaths[p].c_str(); }
        const char* getParamLabel(int p) { return fLabels[p].c_str(); }
        std::map<const char*, const char*> getMetadata(int p)
        {
            std::map<const char*, const char*> res;
            std::map<std::string, std::string> metadata = fMetaData[p];
            std::map<std::string, std::string>::iterator it;
            for (it = metadata.begin(); it != metadata.end(); ++it) {
                res[(*it).first.c_str()] = (*it).second.c_str();
            }
            return res;
        }

        const char* getMetadata(int p, const char* key)
        {
            return (fMetaData[p].find(key) != fMetaData[p].end()) ? fMetaData[p][key].c_str() : "";
        }
        FAUSTFLOAT getParamMin(int p) { return fMin[p]; }
        FAUSTFLOAT getParamMax(int p) { return fMax[p]; }
        FAUSTFLOAT getParamStep(int p) { return fStep[p]; }
        FAUSTFLOAT getParamInit(int p) { return fInit[p]; }

        FAUSTFLOAT* getParamZone(int p) { return fZone[p]; }
        FAUSTFLOAT getParamValue(int p) { return *fZone[p]; }
        void setParamValue(int p, FAUSTFLOAT v) { *fZone[p] = v; }

        double getParamRatio(int p) { return fConversion[p]->faust2ui(*fZone[p]); }
        void setParamRatio(int p, double r) { *fZone[p] = fConversion[p]->ui2faust(r); }

        double value2ratio(int p, double r)	{ return fConversion[p]->faust2ui(r); }
        double ratio2value(int p, double r)	{ return fConversion[p]->ui2faust(r); }
    
        /**
         * Return the control type (kAcc, kGyr, or -1) for a given parameter
         *
         * @param p - the UI parameter index
         *
         * @return the type
         */
        Type getParamType(int p)
        {
            if (p >= 0) {
                if (getZoneIndex(fAcc, p, 0) != -1
                    || getZoneIndex(fAcc, p, 1) != -1
                    || getZoneIndex(fAcc, p, 2) != -1) {
                    return kAcc;
                } else if (getZoneIndex(fGyr, p, 0) != -1
                           || getZoneIndex(fGyr, p, 1) != -1
                           || getZoneIndex(fGyr, p, 2) != -1) {
                    return kGyr;
                }
            }
            return kNoType;
        }
    
        /**
         * Return the Item type (kButton = 0, kCheckButton, kVSlider, kHSlider, kNumEntry, kHBargraph, kVBargraph) for a given parameter
         *
         * @param p - the UI parameter index
         *
         * @return the Item type
         */
        ItemType getParamItemType(int p)
        {
            return fItemType[p];
        }
   
        /**
         * Set a new value coming from an accelerometer, propagate it to all relevant float* zones.
         *
         * @param acc - 0 for X accelerometer, 1 for Y accelerometer, 2 for Z accelerometer
         * @param value - the new value
         *
         */
        void propagateAcc(int acc, double value)
        {
            for (size_t i = 0; i < fAcc[acc].size(); i++) {
                fAcc[acc][i]->update(value);
            }
        }
    
        /**
         * Used to edit accelerometer curves and mapping. Set curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param acc - 0 for X accelerometer, 1 for Y accelerometer, 2 for Z accelerometer (-1 means "no mapping")
         * @param curve - between 0 and 3
         * @param amin - mapping 'min' point
         * @param amid - mapping 'middle' point
         * @param amax - mapping 'max' point
         *
         */
        void setAccConverter(int p, int acc, int curve, double amin, double amid, double amax)
        {
            setConverter(fAcc, p, acc, curve, amin, amid, amax);
        }
    
        /**
         * Used to edit gyroscope curves and mapping. Set curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param acc - 0 for X gyroscope, 1 for Y gyroscope, 2 for Z gyroscope (-1 means "no mapping")
         * @param curve - between 0 and 3
         * @param amin - mapping 'min' point
         * @param amid - mapping 'middle' point
         * @param amax - mapping 'max' point
         *
         */
        void setGyrConverter(int p, int gyr, int curve, double amin, double amid, double amax)
        {
             setConverter(fGyr, p, gyr, curve, amin, amid, amax);
        }
    
        /**
         * Used to edit accelerometer curves and mapping. Get curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param acc - the acc value to be retrieved (-1 means "no mapping")
         * @param curve - the curve value to be retrieved
         * @param amin - the amin value to be retrieved
         * @param amid - the amid value to be retrieved
         * @param amax - the amax value to be retrieved
         *
         */
        void getAccConverter(int p, int& acc, int& curve, double& amin, double& amid, double& amax)
        {
            getConverter(fAcc, p, acc, curve, amin, amid, amax);
        }

        /**
         * Used to edit gyroscope curves and mapping. Get curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param gyr - the gyr value to be retrieved (-1 means "no mapping")
         * @param curve - the curve value to be retrieved
         * @param amin - the amin value to be retrieved
         * @param amid - the amid value to be retrieved
         * @param amax - the amax value to be retrieved
         *
         */
        void getGyrConverter(int p, int& gyr, int& curve, double& amin, double& amid, double& amax)
        {
            getConverter(fGyr, p, gyr, curve, amin, amid, amax);
        }
    
        /**
         * Set a new value coming from an gyroscope, propagate it to all relevant float* zones.
         *
         * @param gyr - 0 for X gyroscope, 1 for Y gyroscope, 2 for Z gyroscope
         * @param value - the new value
         *
         */
        void propagateGyr(int gyr, double value)
        {
            for (size_t i = 0; i < fGyr[gyr].size(); i++) {
                fGyr[gyr][i]->update(value);
            }
        }
   
        // getScreenColor() : -1 means no screen color control (no screencolor metadata found)
        // otherwise return 0x00RRGGBB a ready to use color
        int getScreenColor()
        {
            if (fHasScreenControl) {
                int r = (fRedReader) ? fRedReader->getValue() : 0;
                int g = (fGreenReader) ? fGreenReader->getValue() : 0;
                int b = (fBlueReader) ? fBlueReader->getValue() : 0;
                return (r<<16) | (g<<8) | b;
            } else {
                return -1;
            }
        }

};

#endif
/**************************  END  APIUI.h **************************/
/************************** BEGIN coreaudio-ios-dsp.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.

 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __coreaudio_ios_dsp__
#define __coreaudio_ios_dsp__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <errno.h>
#include <time.h>


#include <AudioToolbox/AudioConverter.h>
#include <AudioToolbox/AudioServices.h>
#include <AudioUnit/AudioUnit.h>

using namespace std;

/******************************************************************************
*******************************************************************************

							COREAUDIO INTERFACE

*******************************************************************************
*******************************************************************************/

#define OPEN_ERR -1
#define NO_ERR 0

class TiPhoneCoreAudioRenderer
{

    protected:

        AudioUnit fAUHAL;

        int	fDevNumInChans;
        int	fDevNumOutChans;

        int fHWNumInChans;
        int fHWNumOutChans;

        dsp* fDSP;
    
        audio* fAudio;

        AudioBufferList* fCAInputData;

        static void PrintStreamDesc(AudioStreamBasicDescription *inDesc)
        {
            printf("- - - - - - - - - - - - - - - - - - - -\n");
            printf("  Sample Rate:%f\n", inDesc->mSampleRate);
            printf("  Format ID:%.*s\n", (int) sizeof(inDesc->mFormatID), (char*)&inDesc->mFormatID);
            printf("  Format Flags:%lX\n", inDesc->mFormatFlags);
            printf("  Bytes per Packet:%ld\n", inDesc->mBytesPerPacket);
            printf("  Frames per Packet:%ld\n", inDesc->mFramesPerPacket);
            printf("  Bytes per Frame:%ld\n", inDesc->mBytesPerFrame);
            printf("  Channels per Frame:%ld\n", inDesc->mChannelsPerFrame);
            printf("  Bits per Channel:%ld\n", inDesc->mBitsPerChannel);
            printf("- - - - - - - - - - - - - - - - - - - -\n");
        }

        static void printError(OSStatus err)
        {
            switch (err) {
                case kAudioConverterErr_FormatNotSupported:
                    printf("error code : kAudioConverterErr_FormatNotSupported\n");
                    break;
                case kAudioConverterErr_OperationNotSupported:
                    printf("error code : kAudioConverterErr_OperationNotSupported\n");
                    break;
                case kAudioConverterErr_PropertyNotSupported:
                    printf("error code : kAudioConverterErr_PropertyNotSupported\n");
                    break;
                case kAudioConverterErr_InvalidInputSize:
                    printf("error code : kAudioConverterErr_InvalidInputSize\n");
                    break;
                case kAudioConverterErr_InvalidOutputSize:
                    printf("error code : kAudioConverterErr_InvalidOutputSize\n");
                    break;
                case kAudioConverterErr_UnspecifiedError:
                    printf("error code : kAudioConverterErr_UnspecifiedError\n");
                    break;
                case kAudioConverterErr_BadPropertySizeError:
                    printf("error code : kAudioConverterErr_BadPropertySizeError\n");
                    break;
                case kAudioConverterErr_RequiresPacketDescriptionsError:
                    printf("error code : kAudioConverterErr_RequiresPacketDescriptionsError\n");
                    break;
                case kAudioConverterErr_InputSampleRateOutOfRange:
                    printf("error code : kAudioConverterErr_InputSampleRateOutOfRange\n");
                    break;
                case kAudioConverterErr_OutputSampleRateOutOfRange:
                    printf("error code : kAudioConverterErr_OutputSampleRateOutOfRange\n");
                    break;
                default:
                    printf("error code : unknown\n");
                    break;
            }
        }

        static OSStatus Render(void *inRefCon,AudioUnitRenderActionFlags *ioActionFlags,
                               const AudioTimeStamp *inTimeStamp,
                               UInt32,
                               UInt32 inNumberFrames,
                               AudioBufferList *ioData)
        {
            return static_cast<TiPhoneCoreAudioRenderer*>(inRefCon)->Render(ioActionFlags, inTimeStamp, inNumberFrames, ioData);
        }

        OSStatus Render(AudioUnitRenderActionFlags *ioActionFlags,
                        const AudioTimeStamp *inTimeStamp,
                        UInt32 inNumberFrames,
                        AudioBufferList *ioData)
        {
            OSStatus err = noErr;

            if (fDevNumInChans > 0) {
                err = AudioUnitRender(fAUHAL, ioActionFlags, inTimeStamp, 1, inNumberFrames, fCAInputData);
            }

            if (err == noErr) {
                float* fInChannel[fDevNumInChans];
                float* fOutChannel[fDevNumOutChans];

                for (int chan = 0; chan < fDevNumInChans; chan++) {
                    fInChannel[chan] = (float*)fCAInputData->mBuffers[chan].mData;
                }

                for (int chan = 0; chan < fDevNumOutChans; chan++) {
                    fOutChannel[chan] = (float*)ioData->mBuffers[chan].mData;
                }

                fDSP->compute((int)inNumberFrames, fInChannel, fOutChannel);
                
                fAudio->runControlCallbacks();
            }
            return err;
        }

        static void InterruptionListener(void *inClientData, UInt32 inInterruption)
        {
            TiPhoneCoreAudioRenderer *obj = (TiPhoneCoreAudioRenderer*)inClientData;
            printf("Session interrupted! --- %s ---", (inInterruption == kAudioSessionBeginInterruption) ? "Begin Interruption" : "End Interruption");

            if (inInterruption == kAudioSessionEndInterruption) {
                // Make sure we are again the active session
                AudioSessionSetActive(true);
                obj->SetupMixing();
                AudioOutputUnitStart(obj->fAUHAL);
            }

            if (inInterruption == kAudioSessionBeginInterruption) {
                AudioOutputUnitStop(obj->fAUHAL);
            }
        }
    
        int SetupMixing()
        {
            OSStatus err;

            /*
            01/07/2014 : cause iRig to fail, so deactivated for now...
            CFStringRef route;
            UInt32 routesize = sizeof(route);
            OSStatus err  = AudioSessionGetProperty(kAudioSessionProperty_AudioRoute, &routesize, &route);
            if (err == noErr) {
                if (CFStringCompare(route, CFSTR("ReceiverAndMicrophone"), 0) == kCFCompareEqualTo || CFStringCompare(route,CFSTR("Receiver"), 0) == kCFCompareEqualTo) {
                    // Re-route audio to the speaker (not the receiver, which no music app will ever want)
                    printf("Rerouting audio to speaker\n");
                    UInt32 newRoute = kAudioSessionOverrideAudioRoute_Speaker;
                    AudioSessionSetProperty(kAudioSessionProperty_OverrideAudioRoute, sizeof(newRoute), &newRoute);
                }
             }
            */

            UInt32 allowMixing = true;
            err = AudioSessionSetProperty(kAudioSessionProperty_OverrideCategoryMixWithOthers, sizeof(allowMixing), &allowMixing);
            if (err != noErr) {
                printf("Could not set audio session mixing\n");
                printError(err);
                return -1;
            } else {
                return 0;
            }
        }

        static void AudioSessionPropertyListener(void* inClientData, AudioSessionPropertyID inID, UInt32 inDataSize, const void* inData)
        {
            TiPhoneCoreAudioRenderer *obj = (TiPhoneCoreAudioRenderer*)inData;
            switch (inID) {
                case kAudioSessionProperty_ServerDied: {
                    printf("kAudioSessionProperty_ServerDied\n");
                    break;
                }
                case kAudioSessionProperty_AudioRouteChange: {
                    printf("kAudioSessionProperty_AudioRouteChange\n");
                    obj->SetupMixing();
                    break;
                }
                case kAudioSessionProperty_AudioInputAvailable: {
                    printf("kAudioSessionProperty_AudioInputAvailable\n");
                    obj->SetupMixing();
                    break;
                }
            }
        }

        static int SetAudioCategory(int input, int output)
        {
            // Set the audioCategory the way Faust DSP wants
            UInt32 audioCategory;
            if ((input > 0) && (output > 0)) {
                audioCategory = kAudioSessionCategory_PlayAndRecord;
                printf("AudioCategory kAudioSessionCategory_PlayAndRecord\n");
            } else if (input > 0) {
                audioCategory = kAudioSessionCategory_RecordAudio;
                printf("AudioCategory kAudioSessionCategory_RecordAudio\n");
            } else  if (output > 0) {
                audioCategory = kAudioSessionCategory_MediaPlayback;
                printf("AudioCategory kAudioSessionCategory_MediaPlayback\n");
            }

            OSStatus err = AudioSessionSetProperty(kAudioSessionProperty_AudioCategory, sizeof(audioCategory), &audioCategory);
            if (err != noErr) {
                printf("Couldn't set audio category\n");
                printError(err);
                return OPEN_ERR;
            }

            // 09/07/2015 : https://developer.apple.com/library/ios/qa/qa1754/_index.html
            if (audioCategory == kAudioSessionCategory_PlayAndRecord) {
                
                // 21/09/2017 Compatible with bluetooth devices. Deactivate bluetooth micro which run at 16khz, use internal micro instead.
                /*
                UInt32 overrideAudioRoute = 1;
                err = AudioSessionSetProperty(kAudioSessionProperty_OverrideCategoryDefaultToSpeaker, sizeof(UInt32), &overrideAudioRoute);
                if (err != noErr) {
                    printf("Error setting kAudioSessionProperty_OverrideCategoryDefaultToSpeaker\n");
                    printError(err);
                }

                UInt32 allowBluetoothInput = 1;
                err = AudioSessionSetProperty(kAudioSessionProperty_OverrideCategoryEnableBluetoothInput, sizeof(UInt32), &allowBluetoothInput);
                if (err != noErr) {
                    printf("Error setting kAudioSessionProperty_OverrideCategoryEnableBluetoothInput\n");
                    printError(err);
                }
                */
                
                // On devices with more than one built-in microphone, the microphone closest to the video camera is used.
                UInt32 allowInternalInput = kAudioSessionMode_VideoRecording;
                err = AudioSessionSetProperty(kAudioSessionProperty_Mode, sizeof(UInt32), &allowInternalInput);
                if (err != noErr) {
                    printf("Error setting kAudioSessionMode_VideoRecording\n");
                    printError(err);
                }

            }

        #if NOAGC
            // If input is used, disable AGC
            if (audioCategory == kAudioSessionCategory_RecordAudio || audioCategory == kAudioSessionCategory_PlayAndRecord) {

                UInt32 sessionMode = kAudioSessionMode_Measurement;
                err = AudioSessionSetProperty(kAudioSessionProperty_Mode, sizeof(sessionMode), &sessionMode);
                if (err != noErr) {
                    printf("Error setting kAudioSessionMode_Measurement\n");
                    printError(err);
                }

                UInt32 availableGain;
                UInt32 outSize = sizeof(availableGain);
                err = AudioSessionGetProperty(kAudioSessionProperty_InputGainAvailable, &outSize, &availableGain);
                if (err != noErr) {
                    printf("Error getting kAudioSessionProperty_InputGainAvailable\n");
                    printError(err);
                } else {
                    Float32 gain;
                    printf("Getting kAudioSessionProperty_InputGainAvailable OK\n");
                    outSize = sizeof(Float32);
                    AudioSessionGetProperty(kAudioSessionProperty_InputGainScalar, &outSize, &gain);
                    printf("Getting kAudioSessionProperty_InputGainScalar :  %f\n", gain);
                    gain = 1.0f;
                    err = AudioSessionSetProperty(kAudioSessionProperty_InputGainScalar, sizeof(Float32), &gain);
                    if (err != noErr) {
                        printf("Error setting kAudioSessionProperty_InputGainScalar\n");
                        printError(err);
                    } else {
                        printf("Setting kAudioSessionProperty_InputGainAvailable to 1.0 OK\n");
                    }
                }
            }
        #endif

            return NO_ERR;
        }

        int SetParameters(int bufferSize, int samplerate)
        {
            OSStatus err;
            UInt32 outSize;
            UInt32 enableIO;
            AudioStreamBasicDescription srcFormat, dstFormat;

            printf("SetParameters fDevNumInChans = %d fDevNumOutChans = %d bufferSize = %d samplerate = %d\n", fDevNumInChans, fDevNumOutChans, bufferSize, samplerate);

            err = AudioSessionSetActive(true);
            if (err != noErr) {
                printf("Couldn't set audio session active\n");
                printError(err);
                return OPEN_ERR;
            }

            AudioSessionAddPropertyListener(kAudioSessionProperty_AudioRouteChange, AudioSessionPropertyListener, this);
            AudioSessionAddPropertyListener(kAudioSessionProperty_AudioInputAvailable, AudioSessionPropertyListener, this);
            AudioSessionAddPropertyListener(kAudioSessionProperty_ServerDied, AudioSessionPropertyListener, this);

            if (SetAudioCategory(fDevNumInChans, fDevNumOutChans) != NO_ERR) {
                return OPEN_ERR;
            }

            // Scan Hardware
            outSize = sizeof(fHWNumInChans);
            err = AudioSessionGetProperty(kAudioSessionProperty_CurrentHardwareInputNumberChannels, &outSize, &fHWNumInChans);
            if (err != noErr) {
                fHWNumInChans = 0;
                printf("Couldn't get hw input channels\n");
                printError(err);
            } else {
                printf("Get hw input channels %d\n", fHWNumInChans);
            }

            outSize = sizeof(fHWNumOutChans);
            err = AudioSessionGetProperty(kAudioSessionProperty_CurrentHardwareOutputNumberChannels, &outSize, &fHWNumOutChans);
            if (err != noErr) {
                fHWNumOutChans = 0;
                printf("Couldn't get hw output channels\n");
                printError(err);
            } else {
                printf("Get hw output channels %d\n", fHWNumOutChans);
            }
            /*
            // Possibly reset the audioCategory the way hardware allows
            // 21/09/2017 cause problem when use bluetooth, deactive for now
            if (SetAudioCategory(fHWNumInChans, fHWNumOutChans) != NO_ERR) {
                return OPEN_ERR;
            }
            */
            if (SetupMixing() < 0) {
                return OPEN_ERR;
            }

            Float64 hwSampleRate;
            outSize = sizeof(hwSampleRate);
            err = AudioSessionGetProperty(kAudioSessionProperty_CurrentHardwareSampleRate, &outSize, &hwSampleRate);
            if (err != noErr) {
                printf("Couldn't get hw sample rate\n");
                printError(err);
                return OPEN_ERR;
            } else {
                printf("Get hw sample rate %f\n", hwSampleRate);
            }

            Float32 hwBufferSize;
            outSize = sizeof(hwBufferSize);
            err = AudioSessionGetProperty(kAudioSessionProperty_CurrentHardwareIOBufferDuration, &outSize, &hwBufferSize);
            if (err != noErr) {
                printf("Couldn't get hw buffer duration\n");
                printError(err);
                return OPEN_ERR;
            } else {
                printf("Get hw buffer duration %f\n", hwBufferSize);
            }

            Float32 preferredPeriodDuration = float(bufferSize) / float(samplerate);
            printf("preferredPeriodDuration %f \n", preferredPeriodDuration);

            err = AudioSessionSetProperty(kAudioSessionProperty_PreferredHardwareIOBufferDuration, sizeof(preferredPeriodDuration), &preferredPeriodDuration);
            if (err != noErr) {
                printf("Couldn't set i/o buffer duration\n");
                printError(err);
                return OPEN_ERR;
            }

            Float32 actualPeriodDuration;
            outSize = sizeof(actualPeriodDuration);
            err = AudioSessionGetProperty(kAudioSessionProperty_PreferredHardwareIOBufferDuration, &outSize, &actualPeriodDuration);
            if (err != noErr) {
                printf("Couldn't get hw buffer duration\n");
                printError(err);
                return OPEN_ERR;
            }

            printf("preferredPeriodDuration %f actualPeriodDuration %f\n", preferredPeriodDuration, actualPeriodDuration);
            if (preferredPeriodDuration != actualPeriodDuration) {
                printf("Couldn't set hw buffer duration\n");
                return OPEN_ERR;
            }

            Float64 preferredSamplerate = float(samplerate);
            err = AudioSessionSetProperty(kAudioSessionProperty_PreferredHardwareSampleRate, sizeof(preferredSamplerate), &preferredSamplerate);
            if (err != noErr) {
                printf("Couldn't set i/o sample rate\n");
                printError(err);
                return OPEN_ERR;
            }

            Float32 inputLatency;
            outSize = sizeof(inputLatency);
            err = AudioSessionGetProperty(kAudioSessionProperty_CurrentHardwareInputLatency, &outSize, &inputLatency);
            if (err != noErr) {
                printf("Couldn't get inputLatency\n");
                printError(err);
            } else {
                printf("inputLatency in sec : %f\n", inputLatency);
            }

            Float32 outputLatency;
            outSize = sizeof(outputLatency);
            err = AudioSessionGetProperty(kAudioSessionProperty_CurrentHardwareOutputLatency, &outSize, &outputLatency);
            if (err != noErr) {
                printf("Couldn't get outputLatency\n");
                printError(err);
            } else {
                printf("outputLatency in sec : %f\n", outputLatency);
            }

            // AUHAL
            AudioComponentDescription cd = {kAudioUnitType_Output, kAudioUnitSubType_RemoteIO, kAudioUnitManufacturer_Apple, 0, 0};
            AudioComponent HALOutput = AudioComponentFindNext(NULL, &cd);

            err = AudioComponentInstanceNew(HALOutput, &fAUHAL);
            if (err != noErr) {
                printf("Error calling OpenAComponent\n");
                printError(err);
                goto error;
            }

            enableIO = 1;
            err = AudioUnitSetProperty(fAUHAL, kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Output, 0, &enableIO, sizeof(enableIO));
            if (err != noErr) {
                printf("Error calling AudioUnitSetProperty - kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Output\n");
                printError(err);
                goto error;
            }

            enableIO = 1;
            err = AudioUnitSetProperty(fAUHAL, kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Input, 1, &enableIO, sizeof(enableIO));
            if (err != noErr) {
                printf("Error calling AudioUnitSetProperty - kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Input\n");
                printError(err);
                goto error;
            }

            UInt32 maxFPS;
            outSize = sizeof(maxFPS);
            err = AudioUnitGetProperty(fAUHAL, kAudioUnitProperty_MaximumFramesPerSlice, kAudioUnitScope_Global, 0, &maxFPS, &outSize);
            if (err != noErr) {
                printf("Couldn't get kAudioUnitProperty_MaximumFramesPerSlice\n");
                printError(err);
                goto error;
            } else {
                printf("Get kAudioUnitProperty_MaximumFramesPerSlice %d\n", (unsigned int)maxFPS);
            }

            err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_MaximumFramesPerSlice, kAudioUnitScope_Global, 1, (UInt32*)&bufferSize, sizeof(UInt32));
            if (err != noErr) {
                printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_MaximumFramesPerSlice\n");
                printError(err);
                goto error;
            }

            err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_MaximumFramesPerSlice, kAudioUnitScope_Global, 0, (UInt32*)&bufferSize, sizeof(UInt32));
            if (err != noErr) {
                printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_MaximumFramesPerSlice\n");
                printError(err);
                goto error;
            }

            err = AudioUnitInitialize(fAUHAL);
            if (err != noErr) {
                printf("Cannot initialize AUHAL unit\n");
                printError(err);
                goto error;
            }

            // Setting format
            if (fDevNumInChans > 0) {
                outSize = sizeof(AudioStreamBasicDescription);
                err = AudioUnitGetProperty(fAUHAL, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Output, 1, &srcFormat, &outSize);
                if (err != noErr) {
                    printf("Error calling AudioUnitGetProperty - kAudioUnitProperty_StreamFormat kAudioUnitScope_Output\n");
                    printError(err);
                }
                PrintStreamDesc(&srcFormat);

                srcFormat.mFormatID = kAudioFormatLinearPCM;
                srcFormat.mFormatFlags = kAudioFormatFlagsNativeFloatPacked | kLinearPCMFormatFlagIsNonInterleaved;
                srcFormat.mBytesPerPacket = sizeof(AudioUnitSampleType);
                srcFormat.mFramesPerPacket = 1;
                srcFormat.mBytesPerFrame = sizeof(AudioUnitSampleType);
                srcFormat.mChannelsPerFrame = fDevNumInChans;
                srcFormat.mBitsPerChannel = 32;

                PrintStreamDesc(&srcFormat);

                err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Output, 1, &srcFormat, sizeof(AudioStreamBasicDescription));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_StreamFormat kAudioUnitScope_Output\n");
                    printError(err);
                }
            }

            if (fDevNumOutChans > 0) {
                outSize = sizeof(AudioStreamBasicDescription);
                err = AudioUnitGetProperty(fAUHAL, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Input, 0, &dstFormat, &outSize);
                if (err != noErr) {
                    printf("Error calling AudioUnitGetProperty - kAudioUnitProperty_StreamFormat kAudioUnitScope_Input\n");
                    printError(err);
                }
                PrintStreamDesc(&dstFormat);

                dstFormat.mFormatID = kAudioFormatLinearPCM;
                dstFormat.mFormatFlags = kAudioFormatFlagsNativeFloatPacked | kLinearPCMFormatFlagIsNonInterleaved;
                dstFormat.mBytesPerPacket = sizeof(AudioUnitSampleType);
                dstFormat.mFramesPerPacket = 1;
                dstFormat.mBytesPerFrame = sizeof(AudioUnitSampleType);
                dstFormat.mChannelsPerFrame = fDevNumOutChans;
                dstFormat.mBitsPerChannel = 32;

                PrintStreamDesc(&dstFormat);

                err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Input, 0, &dstFormat, sizeof(AudioStreamBasicDescription));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_StreamFormat kAudioUnitScope_Input\n");
                    printError(err);
                }
            }

            if (fDevNumInChans > 0 && fDevNumOutChans == 0) {
                AURenderCallbackStruct output;
                output.inputProc = Render;
                output.inputProcRefCon = this;
                err = AudioUnitSetProperty(fAUHAL, kAudioOutputUnitProperty_SetInputCallback, kAudioUnitScope_Global, 0, &output, sizeof(output));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_SetRenderCallback 1\n");
                    printError(err);
                    goto error;
                }
            } else {
                AURenderCallbackStruct output;
                output.inputProc = Render;
                output.inputProcRefCon = this;
                err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_SetRenderCallback, kAudioUnitScope_Input, 0, &output, sizeof(output));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_SetRenderCallback 0\n");
                    printError(err);
                    goto error;
                }
            }

            // Possibly prepare input buffers
            if (fDevNumInChans > 0) {
                fCAInputData = (AudioBufferList*)malloc(sizeof(float) + fDevNumInChans * sizeof(AudioBuffer));
                fCAInputData->mNumberBuffers = fDevNumInChans;
                for (int i = 0; i < fDevNumInChans; i++) {
                    fCAInputData->mBuffers[i].mNumberChannels = 1;
                    fCAInputData->mBuffers[i].mDataByteSize = bufferSize * sizeof(float);
                    fCAInputData->mBuffers[i].mData = malloc(bufferSize * sizeof(float));
                }
            }

            return NO_ERR;

        error:
            AudioUnitUninitialize(fAUHAL);
            AudioComponentInstanceDispose(fAUHAL);
            return OPEN_ERR;
        }

    public:

        TiPhoneCoreAudioRenderer(audio* audio)
            :fAUHAL(0), fDevNumInChans(0), fDevNumOutChans(0),
            fHWNumInChans(0), fHWNumOutChans(0),
            fDSP(0), fAudio(audio), fCAInputData(NULL)
        {}

        virtual ~TiPhoneCoreAudioRenderer()
        {
            if (fCAInputData) {
                for (int i = 0; i < fDevNumInChans; i++) {
                    free(fCAInputData->mBuffers[i].mData);
                }
                free(fCAInputData);
            }
        }
    
        int Open(dsp* dsp, int inChan, int outChan, int buffersize, int samplerate)
        {
            fDSP = dsp;
            fDevNumInChans = inChan;
            fDevNumOutChans = outChan;
      
            // Initialize and configure the audio session
            OSStatus err = AudioSessionInitialize(NULL, NULL, InterruptionListener, this);
            if (err != noErr && err != kAudioSessionAlreadyInitialized) {
                printf("Couldn't initialize audio session\n");
                printError(err);
                return OPEN_ERR;
            }

            if (SetParameters(buffersize, samplerate) < 0) {
                printf("Cannot set parameters to CoreAudio device\n");
                return OPEN_ERR;
            }

            return NO_ERR;
        }

        int Close()
        {
            AudioUnitUninitialize(fAUHAL);
            AudioComponentInstanceDispose(fAUHAL);
            return NO_ERR;
        }

        int Start()
        {
            AudioSessionSetActive(true);

            if (AudioOutputUnitStart(fAUHAL) != noErr) {
                printf("Error while opening device : device open error\n");
                return OPEN_ERR;
            } else {
                return NO_ERR;
            }
        }

        int Stop()
        {
            AudioSessionSetActive(false);

            if (AudioOutputUnitStop(fAUHAL) != noErr) {
                printf("Error while closing device : device close error\n");
                return OPEN_ERR;
            } else {
                return NO_ERR;
            }
        }

        int GetNumInputs() { return fHWNumInChans; }
        int GetNumOutputs() { return fHWNumOutChans; }

};

/******************************************************************************
 *******************************************************************************

                                CORE AUDIO INTERFACE

 *******************************************************************************
 *******************************************************************************/

class iosaudio : public audio {
    
    protected:

        TiPhoneCoreAudioRenderer fAudioDevice;
        int fSampleRate, fBufferSize;
  
    public:

        iosaudio(int srate, int bsize)
        :fAudioDevice(this), fSampleRate(srate), fBufferSize(bsize)
        {}

        virtual ~iosaudio() { fAudioDevice.Close(); }
   
        virtual bool init(const char* /*name*/, dsp* DSP)
        {
            DSP->init(fSampleRate);
            if (fAudioDevice.Open(DSP, DSP->getNumInputs(), DSP->getNumOutputs(), fBufferSize, fSampleRate) < 0) {
                printf("Cannot open iOS audio device\n");
                return false;
            }
            return true;
        }

        virtual bool start()
        {
            if (fAudioDevice.Start() < 0) {
                printf("Cannot start iOS audio device\n");
                return false;
            }
            return true;
        }

        virtual void stop()
        {
            fAudioDevice.Stop();
        }

        virtual int getBufferSize() { return fBufferSize; }
        virtual int getSampleRate() { return fSampleRate; }

        virtual int getNumInputs() { return fAudioDevice.GetNumInputs(); }
        virtual int getNumOutputs() { return fAudioDevice.GetNumOutputs(); }

};

#endif

/********************END ARCHITECTURE SECTION (part 2/2)****************/
/**************************  END  coreaudio-ios-dsp.h **************************/
#else
/************************** BEGIN coreaudio-dsp.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __coreaudio_dsp__
#define __coreaudio_dsp__

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <sys/time.h>

#include <AudioToolbox/AudioConverter.h>
#include <CoreAudio/CoreAudio.h>
#include <AudioUnit/AudioUnit.h>
#include <CoreServices/CoreServices.h>


/******************************************************************************
*******************************************************************************

							COREAUDIO INTERNAL INTERFACE

*******************************************************************************
*******************************************************************************/

#define OPEN_ERR -1
#define CLOSE_ERR -1
#define NO_ERR 0

#define WAIT_NOTIFICATION_COUNTER 60

typedef	UInt8	CAAudioHardwareDeviceSectionID;
#define	kAudioDeviceSectionInput	((CAAudioHardwareDeviceSectionID)0x01)
#define	kAudioDeviceSectionOutput	((CAAudioHardwareDeviceSectionID)0x00)
#define	kAudioDeviceSectionGlobal	((CAAudioHardwareDeviceSectionID)0x00)
#define	kAudioDeviceSectionWildcard	((CAAudioHardwareDeviceSectionID)0xFF)

class TCoreAudioRenderer;
typedef TCoreAudioRenderer* TCoreAudioRendererPtr;

static void PrintStreamDesc(AudioStreamBasicDescription *inDesc)
{
    printf("- - - - - - - - - - - - - - - - - - - -\n");
    printf("  Sample Rate:%f\n", inDesc->mSampleRate);
    printf("  Format ID:%.*s\n", (int)sizeof(inDesc->mFormatID), (char*)&inDesc->mFormatID);
    printf("  Format Flags:%lX\n", (unsigned long)inDesc->mFormatFlags);
    printf("  Bytes per Packet:%ld\n", (long)inDesc->mBytesPerPacket);
    printf("  Frames per Packet:%ld\n", (long)inDesc->mFramesPerPacket);
    printf("  Bytes per Frame:%ld\n", (long)inDesc->mBytesPerFrame);
    printf("  Channels per Frame:%ld\n", (long)inDesc->mChannelsPerFrame);
    printf("  Bits per Channel:%ld\n", (long)inDesc->mBitsPerChannel);
    printf("- - - - - - - - - - - - - - - - - - - -\n");
}

static void printError(OSStatus err)
{
    switch (err) {
        case kAudioHardwareNoError:
            printf("error code : kAudioHardwareNoError\n");
            break;
		case kAudioConverterErr_FormatNotSupported:
            printf("error code : kAudioConverterErr_FormatNotSupported\n");
            break;
        case kAudioConverterErr_OperationNotSupported:
            printf("error code : kAudioConverterErr_OperationNotSupported\n");
            break;
        case kAudioConverterErr_PropertyNotSupported:
            printf("error code : kAudioConverterErr_PropertyNotSupported\n");
            break;
        case kAudioConverterErr_InvalidInputSize:
            printf("error code : kAudioConverterErr_InvalidInputSize\n");
            break;
        case kAudioConverterErr_InvalidOutputSize:
            printf("error code : kAudioConverterErr_InvalidOutputSize\n");
            break;
        case kAudioConverterErr_UnspecifiedError:
            printf("error code : kAudioConverterErr_UnspecifiedError\n");
            break;
        case kAudioConverterErr_BadPropertySizeError:
            printf("error code : kAudioConverterErr_BadPropertySizeError\n");
            break;
        case kAudioConverterErr_RequiresPacketDescriptionsError:
            printf("error code : kAudioConverterErr_RequiresPacketDescriptionsError\n");
            break;
        case kAudioConverterErr_InputSampleRateOutOfRange:
            printf("error code : kAudioConverterErr_InputSampleRateOutOfRange\n");
            break;
        case kAudioConverterErr_OutputSampleRateOutOfRange:
            printf("error code : kAudioConverterErr_OutputSampleRateOutOfRange\n");
            break;
		case kAudioHardwareNotRunningError:
            printf("error code : kAudioHardwareNotRunningError\n");
            break;
        case kAudioHardwareUnknownPropertyError:
            printf("error code : kAudioHardwareUnknownPropertyError\n");
            break;
        case kAudioHardwareIllegalOperationError:
            printf("error code : kAudioHardwareIllegalOperationError\n");
            break;
        case kAudioHardwareBadDeviceError:
            printf("error code : kAudioHardwareBadDeviceError\n");
            break;
        case kAudioHardwareBadStreamError:
            printf("error code : kAudioHardwareBadStreamError\n");
            break;
        case kAudioDeviceUnsupportedFormatError:
            printf("error code : kAudioDeviceUnsupportedFormatError\n");
            break;
        case kAudioDevicePermissionsError:
            printf("error code : kAudioDevicePermissionsError\n");
            break;
        default:
            printf("error code : err = %d\n", err);
            break;
    }
}

static Float64 GetNominalSampleRate(AudioDeviceID inDevice) 
{
    Float64 sampleRate = 0;
    UInt32 outSize =  sizeof(Float64);
    OSStatus err = AudioDeviceGetProperty(inDevice, 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyNominalSampleRate, &outSize, &sampleRate);
    if (err != noErr) {
        printf("Cannot get current sample rate\n");
        printError(err);
        return -1;
    } else {
        return sampleRate;
    }
}

static CFStringRef GetDeviceName(AudioDeviceID id)
{
    UInt32 size = sizeof(CFStringRef);
    CFStringRef UIname;
    OSStatus err = AudioDeviceGetProperty(id, 0, false, kAudioDevicePropertyDeviceUID, &size, &UIname);
    return (err == noErr) ? UIname : NULL;
}

static bool CheckAvailableDeviceName(const char* device_name, AudioDeviceID* device_id, int len = -1)
{
    UInt32 size;
    Boolean isWritable;
    int i, deviceNum;
    OSStatus err;

    err = AudioHardwareGetPropertyInfo(kAudioHardwarePropertyDevices, &size, &isWritable);
    if (err != noErr) {
        return false;
    }

    deviceNum = size / sizeof(AudioDeviceID);
    AudioDeviceID devices[deviceNum];
 
    err = AudioHardwareGetProperty(kAudioHardwarePropertyDevices, &size, devices);
    if (err != noErr) {
        return false;
    }

    for (i = 0; i < deviceNum; i++) {
        char device_name_aux[256];
    
        size = 256;
        err = AudioDeviceGetProperty(devices[i], 0, false, kAudioDevicePropertyDeviceName, &size, device_name_aux);
        if (err != noErr) {
            return false;
        }
 
        if (strncmp(device_name_aux, device_name, (len == -1) ? strlen(device_name) : len) == 0) {
            *device_id = devices[i];
            return true;
        }
    }

    return false;
}

class TCoreAudioRenderer
{
    
    protected:
    
        AudioDeviceID fAggregateDeviceID;
        AudioObjectID fAggregatePluginID;    // Used for aggregate device
     
        int fDevNumInChans;
        int fDevNumOutChans;
        
        int fPhysicalInputs;
        int fPhysicalOutputs;
        
        float** fInChannel;
        float** fOutChannel;

        int fBufferSize;
        int fSampleRate;
    
        bool fIsInJackDevice;
        bool fIsOutJackDevice;
        
        dsp* fDSP;
    
        audio* fAudio;

        AudioBufferList* fInputData;
        AudioDeviceID fDeviceID;
        AudioUnit fAUHAL;
        bool fState;

        OSStatus GetDefaultDeviceAndSampleRate(int inChan, int outChan, int& sample_rate, AudioDeviceID* device)
        {
            
            UInt32 theSize = sizeof(UInt32);
            AudioDeviceID inDefault;
            AudioDeviceID outDefault;
            OSStatus res;
            
            if ((res = AudioHardwareGetProperty(kAudioHardwarePropertyDefaultInputDevice,
                                                &theSize, &inDefault)) != noErr) {
                return res;
            }
            
            if ((res = AudioHardwareGetProperty(kAudioHardwarePropertyDefaultOutputDevice,
                                                &theSize, &outDefault)) != noErr) {
                return res;
            }
            
            /*
            // TODO
            if (inDefault == 0) {
                printf("Error default input device is 0, will take 'Built-in'...\n");
                if (CheckAvailableDeviceName("Built-in Microphone", &inDefault) 
                    || CheckAvailableDeviceName("Built-in Line", &inDefault)) {
                    printf("GetDefaultInputDevice : output = %ld\n", inDefault);
                } else {
                    printf("Cannot find any input device to use...");
                    return -1;
                }
            }
            
            if (outDefault == 0) {
                printf("Error default ouput device is 0, will take 'Built-in'...\n");
                if (CheckAvailableDeviceName("Built-in Output", &outDefault)) {
                    printf("GetDefaultOutputDevice : output = %ld\n", outDefault);
                } else {
                    printf("Cannot find any output device to use...\n");
                    return -1;
                }
            }  
            */          
            
            //printf("GetDefaultDevice : input = %d output = %d\n", inDefault, outDefault);
            
            // Duplex mode
            if (inChan > 0 && outChan > 0) {
                // Get the device only if default input and output are the same
                if (inDefault == outDefault) {
                    *device = inDefault;
                    goto end;
                } else {
                    if (CreateAggregateDevice(inDefault, outDefault, sample_rate) != noErr) {
                        return kAudioHardwareBadDeviceError;
                    }
                    //printf("fAggregateDeviceID %d\n", fAggregateDeviceID);
                    *device = fAggregateDeviceID;
                    goto end;
                }
            } else if (inChan > 0) {
                *device = inDefault;
                goto end;
            } else if (outChan > 0) {
                *device = outDefault;
                goto end;
            } else {
                return kAudioHardwareBadDeviceError;
            }
            
        end:   
            
            if (sample_rate == -1) {
                // Possible take the current sample rate
                sample_rate = int(GetNominalSampleRate(*device));
            } else {
                // Otherwise force the one we want...
                SetupSampleRateAux(*device, sample_rate);
            }
            //printf("samplerate %d\n", sample_rate);
            fSampleRate = sample_rate;
            return noErr;
        }

        OSStatus CreateAggregateDevice(AudioDeviceID captureDeviceID, AudioDeviceID playbackDeviceID, int& sample_rate)
        {
            OSStatus err = noErr;
            AudioObjectID sub_device[32];
            UInt32 outSize = sizeof(sub_device);
            
            //printf("CreateAggregateDevice : input device %d\n", captureDeviceID);
            
            err = AudioDeviceGetProperty(captureDeviceID, 0, kAudioDeviceSectionGlobal, kAudioAggregateDevicePropertyActiveSubDeviceList, &outSize, sub_device);
            std::vector<AudioDeviceID> captureDeviceIDArray;
            
            if (err != noErr) {
                //printf("Input device does not have subdevices\n");
                captureDeviceIDArray.push_back(captureDeviceID);
            } else {
                int num_devices = outSize / sizeof(AudioObjectID);
                //printf("Input device has %d subdevices\n", num_devices);
                for (int i = 0; i < num_devices; i++) {
                    //printf("Input sub_device %d\n", sub_device[i]);
                    captureDeviceIDArray.push_back(sub_device[i]);
                }
            }
            
            outSize = sizeof(sub_device);
            err = AudioDeviceGetProperty(playbackDeviceID, 0, kAudioDeviceSectionGlobal, kAudioAggregateDevicePropertyActiveSubDeviceList, &outSize, sub_device);
            std::vector<AudioDeviceID> playbackDeviceIDArray;
            
            if (err != noErr) {
                //printf("Output device does not have subdevices\n");
                playbackDeviceIDArray.push_back(playbackDeviceID);
            } else {
                int num_devices = outSize / sizeof(AudioObjectID);
                //printf("Output device has %d subdevices\n", num_devices);
                for (int i = 0; i < num_devices; i++) {
                    //printf("Output sub_device %d\n", sub_device[i]);
                    playbackDeviceIDArray.push_back(sub_device[i]);
                }
            }
            
            return CreateAggregateDeviceAux(captureDeviceIDArray, playbackDeviceIDArray, sample_rate);
        }
        
        OSStatus CreateAggregateDeviceAux(std::vector<AudioDeviceID> captureDeviceID, std::vector<AudioDeviceID> playbackDeviceID, int& sample_rate)
        {
            OSStatus osErr = noErr;
            UInt32 outSize;
            Boolean outWritable;
            bool fClockDriftCompensate = true;
            
            // Prepare sub-devices for clock drift compensation
            // Workaround for bug in the HAL : until 10.6.2
            AudioObjectPropertyAddress theAddressOwned = { kAudioObjectPropertyOwnedObjects, kAudioObjectPropertyScopeGlobal, kAudioObjectPropertyElementMaster };
            AudioObjectPropertyAddress theAddressDrift = { kAudioSubDevicePropertyDriftCompensation, kAudioObjectPropertyScopeGlobal, kAudioObjectPropertyElementMaster };
            UInt32 theQualifierDataSize = sizeof(AudioObjectID);
            AudioClassID inClass = kAudioSubDeviceClassID;
            void* theQualifierData = &inClass;
            UInt32 subDevicesNum = 0;
            
            //---------------------------------------------------------------------------
            // Setup SR of both devices otherwise creating AD may fail...
            //---------------------------------------------------------------------------
            UInt32 keptclockdomain = 0;
            UInt32 clockdomain = 0;
            outSize = sizeof(UInt32);
            bool need_clock_drift_compensation = false;
            
            for (UInt32 i = 0; i < captureDeviceID.size(); i++) {
                if (SetupSampleRateAux(captureDeviceID[i], sample_rate) < 0) {
                    printf("TCoreAudioRenderer::CreateAggregateDeviceAux : cannot set SR of input device\n");
                } else  {
                    // Check clock domain
                    osErr = AudioDeviceGetProperty(captureDeviceID[i], 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyClockDomain, &outSize, &clockdomain);
                    if (osErr != 0) {
                        printf("TCoreAudioRenderer::CreateAggregateDeviceAux : kAudioDevicePropertyClockDomain error\n");
                        printError(osErr);
                    } else {
                        keptclockdomain = (keptclockdomain == 0) ? clockdomain : keptclockdomain;
                        //printf("TCoreAudioRenderer::CreateAggregateDevice : input clockdomain = %d\n", clockdomain);
                        if (clockdomain != 0 && clockdomain != keptclockdomain) {
                            //printf("TCoreAudioRenderer::CreateAggregateDevice : devices do not share the same clock!! clock drift compensation would be needed...\n");
                            need_clock_drift_compensation = true;
                        }
                    }
                }
            }
            
            for (UInt32 i = 0; i < playbackDeviceID.size(); i++) {
                if (SetupSampleRateAux(playbackDeviceID[i], sample_rate) < 0) {
                    printf("TCoreAudioRenderer::CreateAggregateDeviceAux : cannot set SR of output device\n");
                } else {
                    // Check clock domain
                    osErr = AudioDeviceGetProperty(playbackDeviceID[i], 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyClockDomain, &outSize, &clockdomain);
                    if (osErr != 0) {
                        printf("TCoreAudioRenderer::CreateAggregateDeviceAux : kAudioDevicePropertyClockDomain error\n");
                        printError(osErr);
                    } else {
                        keptclockdomain = (keptclockdomain == 0) ? clockdomain : keptclockdomain;
                        //printf("TCoreAudioRenderer::CreateAggregateDevice : output clockdomain = %d", clockdomain);
                        if (clockdomain != 0 && clockdomain != keptclockdomain) {
                            //printf("TCoreAudioRenderer::CreateAggregateDevice : devices do not share the same clock!! clock drift compensation would be needed...\n");
                            need_clock_drift_compensation = true;
                        }
                    }
                }
            }
            
            // If no valid clock domain was found, then assume we have to compensate...
            if (keptclockdomain == 0) {
                need_clock_drift_compensation = true;
            }
            
            //---------------------------------------------------------------------------
            // Start to create a new aggregate by getting the base audio hardware plugin
            //---------------------------------------------------------------------------
            
            char device_name[256];
            for (UInt32 i = 0; i < captureDeviceID.size(); i++) {
                GetDeviceNameFromID(captureDeviceID[i], device_name);
                //printf("Separated input = '%s' \n", device_name);
            }
            
            for (UInt32 i = 0; i < playbackDeviceID.size(); i++) {
                GetDeviceNameFromID(playbackDeviceID[i], device_name);
                //printf("Separated output = '%s' \n", device_name);
            }
            
            osErr = AudioHardwareGetPropertyInfo(kAudioHardwarePropertyPlugInForBundleID, &outSize, &outWritable);
            if (osErr != noErr) {
                printf("TCoreAudioRenderer::CreateAggregateDeviceAux : AudioHardwareGetPropertyInfo kAudioHardwarePropertyPlugInForBundleID error\n");
                printError(osErr);
                return osErr;
            }
            
            AudioValueTranslation pluginAVT;
            CFStringRef inBundleRef = CFSTR("com.apple.audio.CoreAudio");
            
            pluginAVT.mInputData = &inBundleRef;
            pluginAVT.mInputDataSize = sizeof(inBundleRef);
            pluginAVT.mOutputData = &fAggregatePluginID;
            pluginAVT.mOutputDataSize = sizeof(fAggregatePluginID);
            
            osErr = AudioHardwareGetProperty(kAudioHardwarePropertyPlugInForBundleID, &outSize, &pluginAVT);
            if (osErr != noErr) {
                printf("TCoreAudioRenderer::CreateAggregateDeviceAux : AudioHardwareGetProperty kAudioHardwarePropertyPlugInForBundleID error\n");
                printError(osErr);
                return osErr;
            }
            
            //-------------------------------------------------
            // Create a CFDictionary for our aggregate device
            //-------------------------------------------------
            
            CFMutableDictionaryRef aggDeviceDict = CFDictionaryCreateMutable(NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
            
            char buffer1[64];
            char buffer2[64];
            
            // generate "random" name
            struct timeval fTv1;
            struct timezone tz;
            gettimeofday(&fTv1, &tz);
            
            sprintf(buffer1, "com.grame.%d", fTv1.tv_sec + fTv1.tv_usec);
            sprintf(buffer2, "%d", fTv1.tv_sec + fTv1.tv_usec);
            
            CFStringRef AggregateDeviceNameRef = CFStringCreateWithCString(kCFAllocatorDefault, buffer1, CFStringGetSystemEncoding());
            CFStringRef AggregateDeviceUIDRef = CFStringCreateWithCString(kCFAllocatorDefault, buffer2, CFStringGetSystemEncoding());
            
            // add the name of the device to the dictionary
            CFDictionaryAddValue(aggDeviceDict, CFSTR(kAudioAggregateDeviceNameKey), AggregateDeviceNameRef);
            
            // add our choice of UID for the aggregate device to the dictionary
            CFDictionaryAddValue(aggDeviceDict, CFSTR(kAudioAggregateDeviceUIDKey), AggregateDeviceUIDRef);
            
            // add a "private aggregate key" to the dictionary
            int value = 1;
            CFNumberRef AggregateDeviceNumberRef = CFNumberCreate(NULL, kCFNumberIntType, &value);
            
            SInt32 system;
            Gestalt(gestaltSystemVersion, &system);
            
            //printf("TCoreAudioRenderer::CreateAggregateDevice : system version = %x limit = %x\n", system, 0x00001054);
            
            // Starting with 10.5.4 systems, the AD can be internal... (better)
            if (system < 0x00001054) {
                //printf("TCoreAudioRenderer::CreateAggregateDevice : public aggregate device....\n");
            } else {
                //printf("TCoreAudioRenderer::CreateAggregateDevice : private aggregate device....\n");
                CFDictionaryAddValue(aggDeviceDict, CFSTR(kAudioAggregateDeviceIsPrivateKey), AggregateDeviceNumberRef);
            }
            
            // Prepare sub-devices for clock drift compensation
            CFMutableArrayRef subDevicesArrayClock = NULL;
            
            /*
             if (fClockDriftCompensate) {
                 if (need_clock_drift_compensation) {
                     jack_info("Clock drift compensation activated...");
                     subDevicesArrayClock = CFArrayCreateMutable(NULL, 0, &kCFTypeArrayCallBacks);
                     
                     for (UInt32 i = 0; i < captureDeviceID.size(); i++) {
                         CFStringRef UID = GetDeviceName(captureDeviceID[i]);
                         if (UID) {
                         CFMutableDictionaryRef subdeviceAggDeviceDict = CFDictionaryCreateMutable(NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
                         CFDictionaryAddValue(subdeviceAggDeviceDict, CFSTR(kAudioSubDeviceUIDKey), UID);
                         CFDictionaryAddValue(subdeviceAggDeviceDict, CFSTR(kAudioSubDeviceDriftCompensationKey), AggregateDeviceNumberRef);
                         //CFRelease(UID);
                         CFArrayAppendValue(subDevicesArrayClock, subdeviceAggDeviceDict);
                     }
                 }
                 
                 for (UInt32 i = 0; i < playbackDeviceID.size(); i++) {
                     CFStringRef UID = GetDeviceName(playbackDeviceID[i]);
                     if (UID) {
                         CFMutableDictionaryRef subdeviceAggDeviceDict = CFDictionaryCreateMutable(NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
                         CFDictionaryAddValue(subdeviceAggDeviceDict, CFSTR(kAudioSubDeviceUIDKey), UID);
                         CFDictionaryAddValue(subdeviceAggDeviceDict, CFSTR(kAudioSubDeviceDriftCompensationKey), AggregateDeviceNumberRef);
                         //CFRelease(UID);
                         CFArrayAppendValue(subDevicesArrayClock, subdeviceAggDeviceDict);
                     }
                 }
                     
                     // add sub-device clock array for the aggregate device to the dictionary
                     CFDictionaryAddValue(aggDeviceDict, CFSTR(kAudioAggregateDeviceSubDeviceListKey), subDevicesArrayClock);
                     } else {
                     jack_info("Clock drift compensation was asked but is not needed (devices use the same clock domain)");
                 }
            }
            */
            
            //-------------------------------------------------
            // Create a CFMutableArray for our sub-device list
            //-------------------------------------------------
            
            // we need to append the UID for each device to a CFMutableArray, so create one here
            CFMutableArrayRef subDevicesArray = CFArrayCreateMutable(NULL, 0, &kCFTypeArrayCallBacks);
            
            std::vector<CFStringRef> captureDeviceUID;
            for (UInt32 i = 0; i < captureDeviceID.size(); i++) {
                CFStringRef ref = GetDeviceName(captureDeviceID[i]);
                if (ref == NULL) {
                    return -1;
                }
                captureDeviceUID.push_back(ref);
                // input sub-devices in this example, so append the sub-device's UID to the CFArray
                CFArrayAppendValue(subDevicesArray, ref);
            }
            
            std::vector<CFStringRef> playbackDeviceUID;
            for (UInt32 i = 0; i < playbackDeviceID.size(); i++) {
                CFStringRef ref = GetDeviceName(playbackDeviceID[i]);
                if (ref == NULL) {
                    return -1;
                }
                playbackDeviceUID.push_back(ref);
                // output sub-devices in this example, so append the sub-device's UID to the CFArray
                CFArrayAppendValue(subDevicesArray, ref);
            }
            
            //-----------------------------------------------------------------------
            // Feed the dictionary to the plugin, to create a blank aggregate device
            //-----------------------------------------------------------------------
            
            AudioObjectPropertyAddress pluginAOPA;
            pluginAOPA.mSelector = kAudioPlugInCreateAggregateDevice;
            pluginAOPA.mScope = kAudioObjectPropertyScopeGlobal;
            pluginAOPA.mElement = kAudioObjectPropertyElementMaster;
            UInt32 outDataSize;
            
            osErr = AudioObjectGetPropertyDataSize(fAggregatePluginID, &pluginAOPA, 0, NULL, &outDataSize);
            if (osErr != noErr) {
                printf("TCoreAudioRenderer::CreateAggregateDeviceAux : AudioObjectGetPropertyDataSize error\n");
                printError(osErr);
                goto error;
            }
            
            osErr = AudioObjectGetPropertyData(fAggregatePluginID, &pluginAOPA, sizeof(aggDeviceDict), &aggDeviceDict, &outDataSize, &fAggregateDeviceID);
            if (osErr != noErr) {
                printf("TCoreAudioRenderer::CreateAggregateDeviceAux : AudioObjectGetPropertyData error\n");
                printError(osErr);
                goto error;
            }
            
            // pause for a bit to make sure that everything completed correctly
            // this is to work around a bug in the HAL where a new aggregate device seems to disappear briefly after it is created
            CFRunLoopRunInMode(kCFRunLoopDefaultMode, 0.1, false);
            
            //-------------------------
            // Set the sub-device list
            //-------------------------
            
            pluginAOPA.mSelector = kAudioAggregateDevicePropertyFullSubDeviceList;
            pluginAOPA.mScope = kAudioObjectPropertyScopeGlobal;
            pluginAOPA.mElement = kAudioObjectPropertyElementMaster;
            outDataSize = sizeof(CFMutableArrayRef);
            osErr = AudioObjectSetPropertyData(fAggregateDeviceID, &pluginAOPA, 0, NULL, outDataSize, &subDevicesArray);
            if (osErr != noErr) {
                printf("TCoreAudioRenderer::CreateAggregateDeviceAux : AudioObjectSetPropertyData for sub-device list error\n");
                printError(osErr);
                goto error;
            }
            
            // pause again to give the changes time to take effect
            CFRunLoopRunInMode(kCFRunLoopDefaultMode, 0.1, false);
            
            //-----------------------
            // Set the master device
            //-----------------------
            
            // set the master device manually (this is the device which will act as the master clock for the aggregate device)
            // pass in the UID of the device you want to use
            pluginAOPA.mSelector = kAudioAggregateDevicePropertyMasterSubDevice;
            pluginAOPA.mScope = kAudioObjectPropertyScopeGlobal;
            pluginAOPA.mElement = kAudioObjectPropertyElementMaster;
            outDataSize = sizeof(CFStringRef);
            osErr = AudioObjectSetPropertyData(fAggregateDeviceID, &pluginAOPA, 0, NULL, outDataSize, &playbackDeviceUID[0]);  // First playback is master...
            if (osErr != noErr) {
                printf("TCoreAudioRenderer::CreateAggregateDeviceAux : AudioObjectSetPropertyData for master device error\n");
                printError(osErr);
                goto error;
            }
            
            // pause again to give the changes time to take effect
            CFRunLoopRunInMode(kCFRunLoopDefaultMode, 0.1, false);
            
            // Prepare sub-devices for clock drift compensation
            // Workaround for bug in the HAL : until 10.6.2
            
            if (fClockDriftCompensate) {
                if (need_clock_drift_compensation) {
                    //printf("Clock drift compensation activated...\n");
                    
                    // Get the property data size
                    osErr = AudioObjectGetPropertyDataSize(fAggregateDeviceID, &theAddressOwned, theQualifierDataSize, theQualifierData, &outSize);
                    if (osErr != noErr) {
                        printf("TCoreAudioRenderer::CreateAggregateDeviceAux kAudioObjectPropertyOwnedObjects error\n");
                        printError(osErr);
                    }
                    
                    //	Calculate the number of object IDs
                    subDevicesNum = outSize / sizeof(AudioObjectID);
                    //printf("TCoreAudioRenderer::CreateAggregateDevice clock drift compensation, number of sub-devices = %d\n", subDevicesNum);
                    AudioObjectID subDevices[subDevicesNum];
                    outSize = sizeof(subDevices);
                    
                    osErr = AudioObjectGetPropertyData(fAggregateDeviceID, &theAddressOwned, theQualifierDataSize, theQualifierData, &outSize, subDevices);
                    if (osErr != noErr) {
                        printf("TCoreAudioRenderer::CreateAggregateDeviceAux kAudioObjectPropertyOwnedObjects error\n");
                        printError(osErr);
                    }
                    
                    // Set kAudioSubDevicePropertyDriftCompensation property...
                    for (UInt32 index = 0; index < subDevicesNum; ++index) {
                        UInt32 theDriftCompensationValue = 1;
                        osErr = AudioObjectSetPropertyData(subDevices[index], &theAddressDrift, 0, NULL, sizeof(UInt32), &theDriftCompensationValue);
                        if (osErr != noErr) {
                            printf("TCoreAudioRenderer::CreateAggregateDeviceAux kAudioSubDevicePropertyDriftCompensation error\n");
                            printError(osErr);
                        }
                    }
                } else {
                    //printf("Clock drift compensation was asked but is not needed (devices use the same clock domain)\n");
                }
            }
            
            // pause again to give the changes time to take effect
            CFRunLoopRunInMode(kCFRunLoopDefaultMode, 0.1, false);
            
            //----------
            // Clean up
            //----------
            
            // release the private AD key
            CFRelease(AggregateDeviceNumberRef);
            
            // release the CF objects we have created - we don't need them any more
            CFRelease(aggDeviceDict);
            CFRelease(subDevicesArray);
            
            if (subDevicesArrayClock)
                CFRelease(subDevicesArrayClock);
            
            // release the device UID
            for (UInt32 i = 0; i < captureDeviceUID.size(); i++) {
                CFRelease(captureDeviceUID[i]);
            }
            
            for (UInt32 i = 0; i < playbackDeviceUID.size(); i++) {
                CFRelease(playbackDeviceUID[i]);
            }
            
            //printf("New aggregate device %d\n", fAggregateDeviceID);
            return noErr;
            
        error:
            DestroyAggregateDevice();
            return -1;
        }

        void DestroyAggregateDevice()
        {   
            if (fAggregateDeviceID > 0) {
                OSStatus osErr = noErr;
                AudioObjectPropertyAddress pluginAOPA;
                pluginAOPA.mSelector = kAudioPlugInDestroyAggregateDevice;
                pluginAOPA.mScope = kAudioObjectPropertyScopeGlobal;
                pluginAOPA.mElement = kAudioObjectPropertyElementMaster;
                UInt32 outDataSize;
                if (fAggregatePluginID > 0)   {
                    osErr = AudioObjectGetPropertyDataSize(fAggregatePluginID, &pluginAOPA, 0, NULL, &outDataSize);
                    if (osErr != noErr) {
                        //printf("TCoreAudioRenderer::DestroyAggregateDevice : AudioObjectGetPropertyDataSize error\n");
                        //printError(osErr);
                    }
                    osErr = AudioObjectGetPropertyData(fAggregatePluginID, &pluginAOPA, 0, NULL, &outDataSize, &fAggregateDeviceID);
                    if (osErr != noErr) {
                        //printf("TCoreAudioRenderer::DestroyAggregateDevice : AudioObjectGetPropertyData error\n");
                        //printError(osErr);
                    }
                }
            }
        }

        OSStatus GetDeviceNameFromID(AudioDeviceID id, char* name)
        {
            UInt32 size = 256;
            return AudioDeviceGetProperty(id, 0, false, kAudioDevicePropertyDeviceName, &size, name);
        }
        
        int SetupBufferSize(int buffer_size)
        {
            // Setting buffer size
            OSStatus err = noErr;
            UInt32 current_buffer_size = buffer_size;
            UInt32 outSize; 
            AudioValueRange buffer_size_range;
            
            outSize = sizeof(AudioValueRange);
            err = AudioDeviceGetProperty(fDeviceID, 0, true, kAudioDevicePropertyBufferFrameSizeRange, &outSize, &buffer_size_range);
            if (err != noErr) {
                printf("Cannot get buffer size range\n");
                printError(err);
                return -1;
            } else {
                //printf("SetupBufferSize : buffer size range min = %ld max = %ld\n", (int)buffer_size_range.mMinimum, (int)buffer_size_range.mMaximum);
            }
            
            outSize = sizeof(UInt32);
            err = AudioDeviceGetProperty(fDeviceID, 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyBufferFrameSize, &outSize, &current_buffer_size);
            if (err != noErr) {
                printf("Cannot get buffer size\n");
                printError(err);
                return -1;
            } else {
                //printf("SetupBufferSize : current buffer size %ld\n", current_buffer_size);
            }

            // If needed, set new buffer size
            if (buffer_size != current_buffer_size && buffer_size >= (int)buffer_size_range.mMinimum && buffer_size <= (int)buffer_size_range.mMaximum) {
                current_buffer_size = buffer_size;

                // To get BS change notification
                err = AudioDeviceAddPropertyListener(fDeviceID, 0, true, kAudioDevicePropertyBufferFrameSize, BSNotificationCallback, this);
                if (err != noErr) {
                    printf("Error calling AudioDeviceAddPropertyListener with kAudioDevicePropertyBufferFrameSize\n");
                    printError(err);
                    return -1;
                }

                // Waiting for BS change notification
                int count = 0;
                fState = false;

                err = AudioDeviceSetProperty(fDeviceID, NULL, 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyBufferFrameSize, outSize, &current_buffer_size);
                if (err != noErr) {
                    printf("SetupBufferSize : cannot set buffer size = %ld\n", current_buffer_size);
                    printError(err);
                    goto error;
                }

                while (!fState && count++ < WAIT_NOTIFICATION_COUNTER) {
                    usleep(100000);
                    //printf("SetupBufferSize : wait count = %d\n", count);
                }

                if (count >= WAIT_NOTIFICATION_COUNTER) {
                    printf("Did not get buffer size notification...\n");
                    goto error;
                }

                // Check new buffer size
                outSize = sizeof(UInt32);
                err = AudioDeviceGetProperty(fDeviceID, 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyBufferFrameSize, &outSize, &current_buffer_size);
                if (err != noErr) {
                    printf("Cannot get current buffer size\n");
                    printError(err);
                } else {
                    //printf("SetupBufferSize : checked buffer size = %ld\n", current_buffer_size);
                }

                // Remove BS change notification
                AudioDeviceRemovePropertyListener(fDeviceID, 0, true, kAudioDevicePropertyBufferFrameSize, BSNotificationCallback);
            } else {
                //printf("Keep current buffer size = %ld\n", current_buffer_size);
            }
            
            fBufferSize = current_buffer_size;
            return 0;

        error:

            // Remove BS change notification
            AudioDeviceRemovePropertyListener(fDeviceID, 0, true, kAudioDevicePropertyBufferFrameSize, BSNotificationCallback);
            return -1;
        }
        
        static OSStatus BSNotificationCallback(AudioDeviceID inDevice,
                                                         UInt32 inChannel,
                                                         Boolean isInput,
                                                         AudioDevicePropertyID inPropertyID,
                                                         void* inClientData)
        {
            TCoreAudioRenderer* driver = (TCoreAudioRenderer*)inClientData;
        
            switch (inPropertyID) {

                case kAudioDevicePropertyBufferFrameSize: {
                    //printf("BSNotificationCallback kAudioDevicePropertyBufferFrameSize\n");
                    // Check new buffer size
                    UInt32 current_buffer_size;
                    UInt32 outSize = sizeof(UInt32);
                    OSStatus err = AudioDeviceGetProperty(inDevice, 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyBufferFrameSize, &outSize, &current_buffer_size);
                    if (err != noErr) {
                        printf("Cannot get current buffer size\n");
                        printError(err);
                    } else {
                        //printf("BSNotificationCallback : checked current buffer size = %d\n", current_buffer_size);
                    }
                    driver->fState = true;
                    break;
                }
            }

            return noErr;
        }

        int SetupSampleRateAux(AudioDeviceID inDevice, int& sample_rate)
        {
            OSStatus err = noErr;
            UInt32 outSize = sizeof(Float64);
            Float64 sampleRate = GetNominalSampleRate(inDevice);
            
            if (sample_rate != -1 && sample_rate != (int)sampleRate) {
                sampleRate = (Float64)sample_rate;
                
                // To get SR change notification
                err = AudioDeviceAddPropertyListener(inDevice, 0, true, kAudioDevicePropertyNominalSampleRate, SRNotificationCallback, this);
                if (err != noErr) {
                    printf("Error calling AudioDeviceAddPropertyListener with kAudioDevicePropertyNominalSampleRate\n");
                    printError(err);
                    return -1;
                }
                err = AudioDeviceSetProperty(inDevice, NULL, 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyNominalSampleRate, outSize, &sampleRate);
                if (err != noErr) {
                    printf("Cannot set sample rate = %d\n", sample_rate);
                    printError(err);
                    return -1;
                }
                
                // Waiting for SR change notification
                int count = 0;
                while (!fState && count++ < WAIT_NOTIFICATION_COUNTER) {
                    usleep(100000);
                    //printf("Wait count = %d\n", count);
                }
                
                // Check new sample rate
                outSize = sizeof(Float64);
                err = AudioDeviceGetProperty(inDevice, 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyNominalSampleRate, &outSize, &sampleRate);
                if (err != noErr) {
                    printf("Cannot get current sample rate\n");
                    printError(err);
                } else {
                    //printf("Checked sample rate = %f\n", sampleRate);
                }
                
                // Remove SR change notification
                AudioDeviceRemovePropertyListener(inDevice, 0, true, kAudioDevicePropertyNominalSampleRate, SRNotificationCallback);
            }
            
            sample_rate = int(sampleRate);
            return 0;
        }   

        static OSStatus Render(void *inRefCon,
                           AudioUnitRenderActionFlags *ioActionFlags,
                           const AudioTimeStamp *inTimeStamp,
                           UInt32 inBusNumber,
                           UInt32 inNumberFrames,
                           AudioBufferList *ioData)
        {
            return static_cast<TCoreAudioRendererPtr>(inRefCon)->Render(ioActionFlags, inTimeStamp, inNumberFrames, ioData);
        }

        static OSStatus SRNotificationCallback(AudioDeviceID inDevice,
                                            UInt32 inChannel,
                                            Boolean	isInput,
                                            AudioDevicePropertyID inPropertyID,
                                               void* inClientData)
        {
            TCoreAudioRenderer* driver = (TCoreAudioRenderer*)inClientData;
            
            switch (inPropertyID) {
                    
                case kAudioDevicePropertyNominalSampleRate: {
                    //printf("SRNotificationCallback kAudioDevicePropertyNominalSampleRate\n");
                    driver->fState = true;
                    // Check new sample rate
                    Float64 sampleRate;
                    UInt32 outSize = sizeof(Float64);
                    OSStatus err = AudioDeviceGetProperty(inDevice, 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyNominalSampleRate, &outSize, &sampleRate);
                    if (err != noErr) {
                        printf("Cannot get current sample rate\n");
                        printError(err);
                    } else {
                        //printf("SRNotificationCallback : checked sample rate = %f\n", sampleRate);
                    }
                    break;
                }
            }
            
            return noErr;
        }

        virtual OSStatus Render(AudioUnitRenderActionFlags *ioActionFlags,
                            const AudioTimeStamp *inTimeStamp,
                            UInt32 inNumberFrames,
                            AudioBufferList *ioData)
        {
            OSStatus err = noErr;
            if (fDevNumInChans > 0) {
                err = AudioUnitRender(fAUHAL, ioActionFlags, inTimeStamp, 1, inNumberFrames, fInputData);
            }
            if (err == noErr) {
                for (int i = 0; i < fDevNumInChans; i++) {
                    fInChannel[i] = (float*)fInputData->mBuffers[i].mData;
                }
                for (int i = 0; i < fDevNumOutChans; i++) {
                    fOutChannel[i] = (float*)ioData->mBuffers[i].mData;
                }
                fDSP->compute(double(AudioConvertHostTimeToNanos(inTimeStamp->mHostTime))/1000., inNumberFrames, fInChannel, fOutChannel);
                fAudio->runControlCallbacks();
            } else {
                printf("AudioUnitRender error... %x\n", fInputData);
                printError(err);
            }
            return err;
        }
        
    public:
    
        TCoreAudioRenderer(audio* audio)
            :fAggregateDeviceID(-1),fAggregatePluginID(-1),
            fDevNumInChans(0),fDevNumOutChans(0),
            fPhysicalInputs(0), fPhysicalOutputs(0),
            fInChannel(0),fOutChannel(0),
            fBufferSize(0),fSampleRate(0),
            fIsInJackDevice(false),
            fIsOutJackDevice(false),
            fDSP(0),
            fAudio(audio),
            fInputData(0),
            fDeviceID(0),fAUHAL(0),
            fState(false)
        {}

        virtual ~TCoreAudioRenderer()
        {}
        
        int GetBufferSize() {return fBufferSize;}
        int GetSampleRate() {return fSampleRate;}
        
        static OSStatus RestartProc(AudioObjectID objectID, UInt32 numberAddresses,
                                   const AudioObjectPropertyAddress inAddresses[],
                                   void *clientData) 
        {
            /*
            TCoreAudioRenderer* renderer = (TCoreAudioRenderer*)clientData;
            AudioDeviceID defaultDevice;
            UInt32 theSize = sizeof(UInt32);
            OSStatus res;
            char device_name[256];
            
            // Test if new device is "JackRouter"
            if (inAddresses[0].mSelector == kAudioHardwarePropertyDefaultInputDevice) {
                
                if ((res = AudioHardwareGetProperty(kAudioHardwarePropertyDefaultInputDevice,
                                                    &theSize, &defaultDevice)) == noErr) {
                    renderer->GetDeviceNameFromID(defaultDevice, device_name);
                    renderer->fIsInJackDevice = strcmp(device_name, "JackRouter") == 0;
                }
                
            } else  if (inAddresses[0].mSelector == kAudioHardwarePropertyDefaultOutputDevice) {
                
                if ((res = AudioHardwareGetProperty(kAudioHardwarePropertyDefaultOutputDevice,
                                                    &theSize, &defaultDevice)) == noErr) {
                    renderer->GetDeviceNameFromID(defaultDevice, device_name);
                    renderer->fIsOutJackDevice = strcmp(device_name, "JackRouter") == 0;
                }
                
            }
            
            // Switch only of input and output are "JackRouter"
            if (renderer->fIsInJackDevice && renderer->fIsOutJackDevice || !renderer->fIsInJackDevice && !renderer->fIsOutJackDevice) {
                renderer->Stop();
                renderer->Close();
                int sampleRate = -1; // Use the current sample rate
                int bufferSize = (renderer->fBufferSize > 0) ? renderer->fBufferSize : 512; // Use default if needed
                renderer->OpenDefault(renderer->fDSP, renderer->fDevNumInChans, renderer->fDevNumOutChans, bufferSize, sampleRate);
                renderer->Start();
            }
            */
            return 0;
        }
    
        int OpenDefault(dsp* DSP, int inChan, int outChan, int bufferSize, int& sampleRate)
        {
            fDevNumInChans = 0;
            fDevNumOutChans = 0;
            fInChannel = 0;
            fOutChannel = 0;
            fBufferSize = 0;
            fSampleRate = 0;
            fDSP = 0;
            fInputData = 0;
            fDeviceID = 0; 
            fAUHAL = 0;
            fState = false;
            return OpenDefault(inChan, outChan, bufferSize, sampleRate);
        }
    
        int OpenDefault(int inChan, int outChan, int buffer_size, int& sample_rate)
        {
            OSStatus err;
            UInt32 outSize;
            UInt32 enableIO;
            Boolean isWritable;
            AudioStreamBasicDescription srcFormat, dstFormat, sampleRate;
            
            fDevNumInChans = inChan;
            fDevNumOutChans = outChan;
            
            fInChannel = new float*[fDevNumInChans];
            fOutChannel = new float*[fDevNumOutChans];
            
            //printf("OpenDefault inChan = %ld outChan = %ld bufferSize = %ld sample_rate = %ld\n", inChan, outChan, bufferSize, sample_rate);
            
            SInt32 major;
            SInt32 minor;
            Gestalt(gestaltSystemVersionMajor, &major);
            Gestalt(gestaltSystemVersionMinor, &minor);
            
            // Starting with 10.6 systems, the HAL notification thread is created internally
            if (major == 10 && minor >= 6) {
                CFRunLoopRef theRunLoop = NULL;
                AudioObjectPropertyAddress theAddress = { kAudioHardwarePropertyRunLoop, kAudioObjectPropertyScopeGlobal, kAudioObjectPropertyElementMaster };
                OSStatus osErr = AudioObjectSetPropertyData (kAudioObjectSystemObject, &theAddress, 0, NULL, sizeof(CFRunLoopRef), &theRunLoop);
                if (osErr != noErr) {
                    printf("TCoreAudioRenderer::Open kAudioHardwarePropertyRunLoop error\n");
                    printError(osErr);
                }
            }
             
            if (GetDefaultDeviceAndSampleRate(inChan, outChan, sample_rate, &fDeviceID) != noErr) {
                printf("Cannot open default device\n");
                return OPEN_ERR;
            }
             
            // Setting buffer size
            if (SetupBufferSize(buffer_size) < 0) {
                return OPEN_ERR;
            }
            
            // fBufferSize now has the real value, either 'bufferSize' (if could be changed) or driver current one
            
            // AUHAL
        
        #ifdef MAC_OS_X_VERSION_10_5
            ComponentDescription cd = {kAudioUnitType_Output, kAudioUnitSubType_HALOutput, kAudioUnitManufacturer_Apple, 0, 0};
            Component HALOutput = FindNextComponent(NULL, &cd);
            err = OpenAComponent(HALOutput, &fAUHAL);
            if (err != noErr) {
                printf("Error calling OpenAComponent\n");
                printError(err);
                goto error;
            }
        #else 
            AudioComponentDescription cd = {kAudioUnitType_Output, kAudioUnitSubType_HALOutput, kAudioUnitManufacturer_Apple, 0, 0};
            AudioComponent HALOutput = AudioComponentFindNext(NULL, &cd);
            err = AudioComponentInstanceNew(HALOutput, &fAUHAL);
            if (err != noErr) {
                printf("Error calling AudioComponentInstanceNew\n");
                printError(err);
                goto error;
            }
        #endif
            
            err = AudioUnitInitialize(fAUHAL);
            if (err != noErr) {
                printf("Cannot initialize AUHAL unit\n");
                printError(err);
                goto error;
            }
            
            if (inChan > 0) {
                enableIO = 1;
                //printf("OpenAUHAL : setup AUHAL input on\n");
            } else {
                enableIO = 0;
                //printf("OpenAUHAL : setup AUHAL input off\n");
            }
            
            err = AudioUnitSetProperty(fAUHAL, kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Input, 1, &enableIO, sizeof(enableIO));
            if (err != noErr) {
                printf("Error calling AudioUnitSetProperty - kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Input\n");
                printError(err);
                goto error;
            }
                
            if (outChan > 0) {
                enableIO = 1;
                //printf("OpenAUHAL : setup AUHAL output on\n");
            } else {
                enableIO = 0;
                //printf("OpenAUHAL : setup AUHAL output off\n");
            }
            
            err = AudioUnitSetProperty(fAUHAL, kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Output, 0, &enableIO, sizeof(enableIO));
            if (err != noErr) {
                printf("Error calling AudioUnitSetProperty - kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Output\n");
                printError(err);
                goto error;
            }
            
            AudioDeviceID currAudioDeviceID;
            outSize = sizeof(AudioDeviceID);
            err = AudioUnitGetProperty(fAUHAL, kAudioOutputUnitProperty_CurrentDevice, kAudioUnitScope_Global, 0, &currAudioDeviceID, &outSize);
            if (err != noErr) {
                printf("Error calling AudioUnitGetProperty - kAudioOutputUnitProperty_CurrentDevice\n");
                printError(err);
                goto error;
            } else {
                //printf("AudioUnitGetPropertyCurrentDevice = %d\n", currAudioDeviceID);
            }
        
            // Setup up choosen device, in both input and output cases
            err = AudioUnitSetProperty(fAUHAL, kAudioOutputUnitProperty_CurrentDevice, kAudioUnitScope_Global, 0, &fDeviceID, sizeof(AudioDeviceID));
            if (err != noErr) {
                printf("Error calling AudioUnitSetProperty - kAudioOutputUnitProperty_CurrentDevice\n");
                printError(err);
                goto error;
            }
            
            if (inChan > 0) {
                err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_MaximumFramesPerSlice, kAudioUnitScope_Global, 1, (UInt32*)&fBufferSize, sizeof(UInt32));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_MaximumFramesPerSlice\n");
                    printError(err);
                    goto error;
                }
            }
            
            if (outChan > 0) {
                err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_MaximumFramesPerSlice, kAudioUnitScope_Global, 0, (UInt32*)&fBufferSize, sizeof(UInt32));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_MaximumFramesPerSlice\n");
                    printError(err);
                    goto error;
                }
            }
            
            err = AudioUnitGetPropertyInfo(fAUHAL, kAudioOutputUnitProperty_ChannelMap, kAudioUnitScope_Input, 1, &outSize, &isWritable);
            if (err != noErr) {
                //printf("Error calling AudioUnitGetPropertyInfo - kAudioOutputUnitProperty_ChannelMap 1\n");
                //printError(err);
            } else {
                fPhysicalInputs = outSize / sizeof(SInt32);
                //printf("fPhysicalInputs = %ld\n", fPhysicalInputs);
            }
                    
            err = AudioUnitGetPropertyInfo(fAUHAL, kAudioOutputUnitProperty_ChannelMap, kAudioUnitScope_Output, 0, &outSize, &isWritable);
            if (err != noErr) {
                //printf("Error calling AudioUnitGetPropertyInfo - kAudioOutputUnitProperty_ChannelMap 0\n");
                //printError(err);
            } else {
                fPhysicalOutputs = outSize / sizeof(SInt32);
                //printf("fPhysicalOutputs = %ld\n", fPhysicalOutputs);
            }
            
            /*
             Just ignore this case : seems to work without any further change...
             
             if (outChan > fPhysicalOutputs) {
                printf("This device hasn't required output channels\n");
                goto error;
             }
             if (inChan > fPhysicalInputs) {
                printf("This device hasn't required input channels\n");
                goto error;
             }
             */
            
            if (inChan < fPhysicalInputs) {
                SInt32 chanArr[fPhysicalInputs];
                for (int i = 0; i < fPhysicalInputs; i++) {
                    chanArr[i] = -1;
                }
                for (int i = 0; i < inChan; i++) {
                    chanArr[i] = i;
                }
                AudioUnitSetProperty(fAUHAL, kAudioOutputUnitProperty_ChannelMap , kAudioUnitScope_Input, 1, chanArr, sizeof(SInt32) * fPhysicalInputs);
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioOutputUnitProperty_ChannelMap 1\n");
                    printError(err);
                }
            }
            
            if (outChan < fPhysicalOutputs) {
                SInt32 chanArr[fPhysicalOutputs];
                for (int i = 0;	i < fPhysicalOutputs; i++) {
                    chanArr[i] = -1;
                }
                for (int i = 0; i < outChan; i++) {
                    chanArr[i] = i;
                }
                err = AudioUnitSetProperty(fAUHAL, kAudioOutputUnitProperty_ChannelMap, kAudioUnitScope_Output, 0, chanArr, sizeof(SInt32) * fPhysicalOutputs);
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioOutputUnitProperty_ChannelMap 0\n");
                    printError(err);
                }
            }
            
            if (inChan > 0) {
                outSize = sizeof(AudioStreamBasicDescription);
                err = AudioUnitGetProperty(fAUHAL, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Output, 1, &srcFormat, &outSize);
                if (err != noErr) {
                    printf("Error calling AudioUnitGetProperty - kAudioUnitProperty_StreamFormat kAudioUnitScope_Output\n");
                    printError(err);
                }
                //PrintStreamDesc(&srcFormat);
                
                srcFormat.mSampleRate = sample_rate;
                srcFormat.mFormatID = kAudioFormatLinearPCM;
                srcFormat.mFormatFlags = kAudioFormatFlagsNativeFloatPacked | kLinearPCMFormatFlagIsNonInterleaved;
                srcFormat.mBytesPerPacket = sizeof(float);
                srcFormat.mFramesPerPacket = 1;
                srcFormat.mBytesPerFrame = sizeof(float);
                srcFormat.mChannelsPerFrame = inChan;
                srcFormat.mBitsPerChannel = 32;
                
                //PrintStreamDesc(&srcFormat);
                
                err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Output, 1, &srcFormat, sizeof(AudioStreamBasicDescription));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_StreamFormat kAudioUnitScope_Output\n");
                    printError(err);
                }
            }
            
            if (outChan > 0) {
                outSize = sizeof(AudioStreamBasicDescription);
                err = AudioUnitGetProperty(fAUHAL, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Input, 0, &dstFormat, &outSize);
                if (err != noErr) {
                    printf("Error calling AudioUnitGetProperty - kAudioUnitProperty_StreamFormat kAudioUnitScope_Output\n");
                    printError(err);
                }
                //PrintStreamDesc(&dstFormat);
                
                dstFormat.mSampleRate = sample_rate;
                dstFormat.mFormatID = kAudioFormatLinearPCM;
                dstFormat.mFormatFlags = kAudioFormatFlagsNativeFloatPacked | kLinearPCMFormatFlagIsNonInterleaved;
                dstFormat.mBytesPerPacket = sizeof(float);
                dstFormat.mFramesPerPacket = 1;
                dstFormat.mBytesPerFrame = sizeof(float);
                dstFormat.mChannelsPerFrame = outChan;
                dstFormat.mBitsPerChannel = 32;
                
                //PrintStreamDesc(&dstFormat);
                
                err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Input, 0, &dstFormat, sizeof(AudioStreamBasicDescription));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_StreamFormat kAudioUnitScope_Output\n");
                    printError(err);
                }
            }
            
            if (inChan > 0 && outChan == 0) {
                AURenderCallbackStruct output;
                output.inputProc = Render;
                output.inputProcRefCon = this;
                err = AudioUnitSetProperty(fAUHAL, kAudioOutputUnitProperty_SetInputCallback, kAudioUnitScope_Global, 0, &output, sizeof(output));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_SetRenderCallback 1\n");
                    printError(err);
                    goto error;
                }
            } else {
                AURenderCallbackStruct output;
                output.inputProc = Render;
                output.inputProcRefCon = this;
                err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_SetRenderCallback, kAudioUnitScope_Input, 0, &output, sizeof(output));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_SetRenderCallback 0\n");
                    printError(err);
                    goto error;
                }
            }
            
            if (inChan > 0) {
                fInputData = (AudioBufferList*)malloc(sizeof(UInt32) + inChan * sizeof(AudioBuffer));
                assert(fInputData);
                fInputData->mNumberBuffers = inChan;
                
                // Prepare buffers
                for (int i = 0; i < inChan; i++) {
                    fInputData->mBuffers[i].mNumberChannels = 1;
                    fInputData->mBuffers[i].mData = malloc(fBufferSize * sizeof(float));
                    assert(fInputData->mBuffers[i].mData),
                    fInputData->mBuffers[i].mDataByteSize = fBufferSize * sizeof(float);
                }
            }
            
            AudioObjectPropertyAddress property_address;
            property_address.mScope = kAudioObjectPropertyScopeGlobal;
            property_address.mElement = kAudioObjectPropertyElementMaster;
            
            property_address.mSelector = kAudioHardwarePropertyDefaultInputDevice;
            if (AudioObjectAddPropertyListener(kAudioObjectSystemObject, &property_address, RestartProc, this)) {
                printf("AudioObjectAddPropertyListener() failed\n");
                return OPEN_ERR;
            } else {
                //printf("AudioObjectAddPropertyListener() OK\n");
            }
            
            property_address.mSelector = kAudioHardwarePropertyDefaultOutputDevice;
            if (AudioObjectAddPropertyListener(kAudioObjectSystemObject, &property_address, RestartProc, this)) {
                printf("AudioObjectAddPropertyListener() failed\n");
                return OPEN_ERR;
            } else {
                //printf("AudioObjectAddPropertyListener() OK\n");
            }
             
            return NO_ERR;
            
        error:
            AudioUnitUninitialize(fAUHAL);
            CloseComponent(fAUHAL);
            fAUHAL = 0;
            return OPEN_ERR;
        }
        
        int Close()
        {
            if (!fAUHAL) {
                return CLOSE_ERR;
            }
            
            for (int i = 0; i < fDevNumInChans; i++) {
                free(fInputData->mBuffers[i].mData);
            }
            if (fInputData) {
                free(fInputData);
            }
            AudioUnitUninitialize(fAUHAL);
            CloseComponent(fAUHAL);
            fAUHAL = NULL;
            
            DestroyAggregateDevice();
            
            delete[] fInChannel;
            delete[] fOutChannel;
            
            AudioObjectPropertyAddress property_address;
            property_address.mScope = kAudioObjectPropertyScopeGlobal;
            property_address.mElement = kAudioObjectPropertyElementMaster;
            
            property_address.mSelector = kAudioHardwarePropertyDefaultInputDevice;
            AudioObjectRemovePropertyListener(kAudioObjectSystemObject, &property_address, RestartProc, this);
            
            property_address.mSelector = kAudioHardwarePropertyDefaultOutputDevice;
            AudioObjectRemovePropertyListener(kAudioObjectSystemObject, &property_address, RestartProc, this);
            
            return NO_ERR;
        }

        int Start()
        {
            if (!fAUHAL) {
                return OPEN_ERR;
            }
            
            OSStatus err = AudioOutputUnitStart(fAUHAL);
            
            if (err != noErr) {
                printf("Error while opening device : device open error \n");
                return OPEN_ERR;
            } else {
                return NO_ERR;
            }
        }
        
        int Stop()
        {
            if (!fAUHAL) {
                return OPEN_ERR;
            }
            
            OSStatus err = AudioOutputUnitStop(fAUHAL);
            
            if (err != noErr) {
                printf("Error while closing device : device close error \n");
                return OPEN_ERR;
            } else {
                return NO_ERR;
            }
        }
    
        void setDsp(dsp* DSP)
        {
            fDSP = DSP;
        }
        
        int GetNumInputs() { return fPhysicalInputs; }
        int GetNumOutputs() { return fPhysicalOutputs; }

};

/******************************************************************************
*******************************************************************************

							CORE AUDIO INTERFACE

*******************************************************************************
*******************************************************************************/
class coreaudio : public audio {

    protected:
        
        TCoreAudioRenderer fAudioDevice;
        int fSampleRate, fBufferSize;

    public:
      
        coreaudio(int srate, int bsize) : fAudioDevice(this), fSampleRate(srate), fBufferSize(bsize) {}
        coreaudio(int bsize) : fAudioDevice(this), fSampleRate(-1), fBufferSize(bsize) {}
        virtual ~coreaudio() { fAudioDevice.Close(); }

        virtual bool init(const char* /*name*/, dsp* DSP) 
        {
            if (fAudioDevice.OpenDefault(DSP, DSP->getNumInputs(), DSP->getNumOutputs(), fBufferSize, fSampleRate) < 0) {
                printf("Cannot open CoreAudio device\n");
                return false;
            }
            fAudioDevice.setDsp(DSP);
            // If -1 was given, fSampleRate will be changed by OpenDefault
            DSP->init(fSampleRate);
            return true;
        }

        virtual bool start() 
        {
            if (fAudioDevice.Start() < 0) {
                printf("Cannot start CoreAudio device\n");
                return false;
            }
            return true;
        }

        virtual void stop() 
        {
            fAudioDevice.Stop();
        }
        
        virtual int getBufferSize() { return fAudioDevice.GetBufferSize(); }
        virtual int getSampleRate() { return fAudioDevice.GetSampleRate(); }
        
        virtual int getNumInputs() { return fAudioDevice.GetNumInputs(); }
        virtual int getNumOutputs() { return fAudioDevice.GetNumOutputs(); }

};

#endif

/********************END ARCHITECTURE SECTION (part 2/2)****************/


/**************************  END  coreaudio-dsp.h **************************/
#endif

#ifdef OSCCTRL
/************************** BEGIN OSCUI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __OSCUI__
#define __OSCUI__

#include <vector>
#include <string>

/*

  Faust Project

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __OSCControler__
#define __OSCControler__

#include <string>
/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __FaustFactory__
#define __FaustFactory__

#include <stack>
#include <string>
#include <sstream>

/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __FaustNode__
#define __FaustNode__

#include <string>
#include <vector>

/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __MessageDriven__
#define __MessageDriven__

#include <string>
#include <vector>

/*

  Copyright (C) 2010  Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __MessageProcessor__
#define __MessageProcessor__

namespace oscfaust
{

class Message;
//--------------------------------------------------------------------------
/*!
	\brief an abstract class for objects able to process OSC messages	
*/
class MessageProcessor
{
	public:
		virtual		~MessageProcessor() {}
		virtual void processMessage( const Message* msg ) = 0;
};

} // end namespoace

#endif
/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __smartpointer__
#define __smartpointer__

#include <cassert>

namespace oscfaust
{

/*!
\brief the base class for smart pointers implementation

	Any object that want to support smart pointers should
	inherit from the smartable class which provides reference counting
	and automatic delete when the reference count drops to zero.
*/
class smartable {
	private:
		unsigned 	refCount;		
	public:
		//! gives the reference count of the object
		unsigned refs() const         { return refCount; }
		//! addReference increments the ref count and checks for refCount overflow
		void addReference()           { refCount++; assert(refCount != 0); }
		//! removeReference delete the object when refCount is zero		
		void removeReference()		  { if (--refCount == 0) delete this; }
		
	protected:
		smartable() : refCount(0) {}
		smartable(const smartable&): refCount(0) {}
		//! destructor checks for non-zero refCount
		virtual ~smartable()    
        { 
            /* 
                See "Static SFaustNode create (const char* name, C* zone, C init, C min, C max, const char* prefix, GUI* ui)" comment.
                assert (refCount == 0); 
            */
        }
		smartable& operator=(const smartable&) { return *this; }
};

/*!
\brief the smart pointer implementation

	A smart pointer is in charge of maintaining the objects reference count 
	by the way of pointers operators overloading. It supports class 
	inheritance and conversion whenever possible.
\n	Instances of the SMARTP class are supposed to use \e smartable types (or at least
	objects that implements the \e addReference and \e removeReference
	methods in a consistent way).
*/
template<class T> class SMARTP {
	private:
		//! the actual pointer to the class
		T* fSmartPtr;

	public:
		//! an empty constructor - points to null
		SMARTP()	: fSmartPtr(0) {}
		//! build a smart pointer from a class pointer
		SMARTP(T* rawptr) : fSmartPtr(rawptr)              { if (fSmartPtr) fSmartPtr->addReference(); }
		//! build a smart pointer from an convertible class reference
		template<class T2> 
		SMARTP(const SMARTP<T2>& ptr) : fSmartPtr((T*)ptr) { if (fSmartPtr) fSmartPtr->addReference(); }
		//! build a smart pointer from another smart pointer reference
		SMARTP(const SMARTP& ptr) : fSmartPtr((T*)ptr)     { if (fSmartPtr) fSmartPtr->addReference(); }

		//! the smart pointer destructor: simply removes one reference count
		~SMARTP()  { if (fSmartPtr) fSmartPtr->removeReference(); }
		
		//! cast operator to retrieve the actual class pointer
		operator T*() const  { return fSmartPtr;	}

		//! '*' operator to access the actual class pointer
		T& operator*() const {
			// checks for null dereference
			assert (fSmartPtr != 0);
			return *fSmartPtr;
		}

		//! operator -> overloading to access the actual class pointer
		T* operator->() const	{ 
			// checks for null dereference
			assert (fSmartPtr != 0);
			return fSmartPtr;
		}

		//! operator = that moves the actual class pointer
		template <class T2>
		SMARTP& operator=(T2 p1_)	{ *this=(T*)p1_; return *this; }

		//! operator = that moves the actual class pointer
		SMARTP& operator=(T* p_)	{
			// check first that pointers differ
			if (fSmartPtr != p_) {
				// increments the ref count of the new pointer if not null
				if (p_ != 0) p_->addReference();
				// decrements the ref count of the old pointer if not null
				if (fSmartPtr != 0) fSmartPtr->removeReference();
				// and finally stores the new actual pointer
				fSmartPtr = p_;
			}
			return *this;
		}
		//! operator < to support SMARTP map with Visual C++
		bool operator<(const SMARTP<T>& p_)	const			  { return fSmartPtr < ((T *) p_); }
		//! operator = to support inherited class reference
		SMARTP& operator=(const SMARTP<T>& p_)                { return operator=((T *) p_); }
		//! dynamic cast support
		template<class T2> SMARTP& cast(T2* p_)               { return operator=(dynamic_cast<T*>(p_)); }
		//! dynamic cast support
		template<class T2> SMARTP& cast(const SMARTP<T2>& p_) { return operator=(dynamic_cast<T*>(p_)); }
};

}

#endif

namespace oscfaust
{

class Message;
class OSCRegexp;
class MessageDriven;
typedef class SMARTP<MessageDriven>	SMessageDriven;

//--------------------------------------------------------------------------
/*!
	\brief a base class for objects accepting OSC messages
	
	Message driven objects are hierarchically organized in a tree.
	They provides the necessary to dispatch an OSC message to its destination
	node, according to the message OSC address. 
	
	The principle of the dispatch is the following:
	- first the processMessage() method should be called on the top level node
	- next processMessage call propose 
*/
class MessageDriven : public MessageProcessor, public smartable
{
	std::string						fName;			///< the node name
	std::string						fOSCPrefix;		///< the node OSC address prefix (OSCAddress = fOSCPrefix + '/' + fName)
	std::vector<SMessageDriven>		fSubNodes;		///< the subnodes of the current node

	protected:
				 MessageDriven(const char *name, const char *oscprefix) : fName (name), fOSCPrefix(oscprefix) {}
		virtual ~MessageDriven() {}

	public:
		static SMessageDriven create(const char* name, const char *oscprefix)	{ return new MessageDriven(name, oscprefix); }

		/*!
			\brief OSC message processing method.
			\param msg the osc message to be processed
			The method should be called on the top level node.
		*/
		virtual void	processMessage(const Message* msg);

		/*!
			\brief propose an OSc message at a given hierarchy level.
			\param msg the osc message currently processed
			\param regexp a regular expression based on the osc address head
			\param addrTail the osc address tail
			
			The method first tries to match the regular expression with the object name. 
			When it matches:
			- it calls \c accept when \c addrTail is empty 
			- or it \c propose the message to its subnodes when \c addrTail is not empty. 
			  In this case a new \c regexp is computed with the head of \c addrTail and a new \c addrTail as well.
		*/
		virtual void	propose(const Message* msg, const OSCRegexp* regexp, const std::string addrTail);

		/*!
			\brief accept an OSC message. 
			\param msg the osc message currently processed
			\return true when the message is processed by the node
			
			The method is called only for the destination nodes. The real message acceptance is the node 
			responsability and may depend on the message content.
		*/
		virtual bool	accept(const Message* msg);

		/*!
			\brief handler for the \c 'get' message
			\param ipdest the output message destination IP
			
			The \c 'get' message is supported by every node:
			- it is propagated to the subnodes until it reaches terminal nodes
			- a terminal node send its state on \c 'get' request to the IP address given as parameter.
			The \c get method is basically called by the accept method.
		*/
		virtual void	get(unsigned long ipdest) const;

		/*!
			\brief handler for the \c 'get' 'attribute' message
			\param ipdest the output message destination IP
			\param what the requested attribute
			
			The \c 'get' message is supported by every node:
			- it is propagated to the subnodes until it reaches terminal nodes
			- a terminal node send its state on \c 'get' request to the IP address given as parameter.
			The \c get method is basically called by the accept method.
		*/
		virtual void	get (unsigned long ipdest, const std::string & what) const {}

		void			add(SMessageDriven node)	{ fSubNodes.push_back (node); }
		const char*		getName() const				{ return fName.c_str(); }
		std::string		getOSCAddress() const;
		int				size() const				{ return (int)fSubNodes.size (); }
		
		const std::string&	name() const			{ return fName; }
		SMessageDriven	subnode(int i)              { return fSubNodes[i]; }
};

} // end namespoace

#endif
/*

  Copyright (C) 2011  Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/


#ifndef __Message__
#define __Message__

#include <string>
#include <vector>

namespace oscfaust
{

class OSCStream;
template <typename T> class MsgParam;
class baseparam;
typedef SMARTP<baseparam>	Sbaseparam;

//--------------------------------------------------------------------------
/*!
	\brief base class of a message parameters
*/
class baseparam : public smartable
{
	public:
		virtual ~baseparam() {}

		/*!
		 \brief utility for parameter type checking
		*/
		template<typename X> bool isType() const { return dynamic_cast<const MsgParam<X>*> (this) != 0; }
		/*!
		 \brief utility for parameter convertion
		 \param errvalue the returned value when no conversion applies
		 \return the parameter value when the type matches
		*/
		template<typename X> X	value(X errvalue) const 
			{ const MsgParam<X>* o = dynamic_cast<const MsgParam<X>*> (this); return o ? o->getValue() : errvalue; }
		/*!
		 \brief utility for parameter comparison
		*/
		template<typename X> bool	equal(const baseparam& p) const 
			{ 
				const MsgParam<X>* a = dynamic_cast<const MsgParam<X>*> (this); 
				const MsgParam<X>* b = dynamic_cast<const MsgParam<X>*> (&p);
				return a && b && (a->getValue() == b->getValue());
			}
		/*!
		 \brief utility for parameter comparison
		*/
		bool operator==(const baseparam& p) const 
			{ 
				return equal<float>(p) || equal<int>(p) || equal<std::string>(p);
			}
		bool operator!=(const baseparam& p) const
			{ 
				return !equal<float>(p) && !equal<int>(p) && !equal<std::string>(p);
			}
			
		virtual SMARTP<baseparam> copy() const = 0;
};

//--------------------------------------------------------------------------
/*!
	\brief template for a message parameter
*/
template <typename T> class MsgParam : public baseparam
{
	T fParam;
	public:
				 MsgParam(T val) : fParam(val)	{}
		virtual ~MsgParam() {}
		
		T getValue() const { return fParam; }
		
		virtual Sbaseparam copy() const { return new MsgParam<T>(fParam); }
};

//--------------------------------------------------------------------------
/*!
	\brief a message description
	
	A message is composed of an address (actually an OSC address),
	a message string that may be viewed as a method name
	and a list of message parameters.
*/
class Message
{
    public:
        typedef SMARTP<baseparam>		argPtr;		///< a message argument ptr type
        typedef std::vector<argPtr>		argslist;	///< args list type

    private:
        unsigned long	fSrcIP;			///< the message source IP number
        std::string	fAddress;			///< the message osc destination address
        std::string	fAlias;             ///< the message alias osc destination address
        argslist	fArguments;			///< the message arguments

    public:
            /*!
                \brief an empty message constructor
            */
             Message() {}
            /*!
                \brief a message constructor
                \param address the message destination address
            */
            Message(const std::string& address) : fAddress(address), fAlias("") {}
             
            Message(const std::string& address, const std::string& alias) : fAddress(address), fAlias(alias) {}
            /*!
                \brief a message constructor
                \param address the message destination address
                \param args the message parameters
            */
            Message(const std::string& address, const argslist& args) 
                : fAddress(address), fArguments(args) {}
            /*!
                \brief a message constructor
                \param msg a message
            */
             Message(const Message& msg);
    virtual ~Message() {} //{ freed++; std::cout << "running messages: " << (allocated - freed) << std::endl; }

    /*!
        \brief adds a parameter to the message
        \param val the parameter
    */
    template <typename T> void add(T val)	{ fArguments.push_back(new MsgParam<T>(val)); }
    /*!
        \brief adds a float parameter to the message
        \param val the parameter value
    */
    void	add(float val)					{ add<float>(val); }
    /*!
        \brief adds an int parameter to the message
        \param val the parameter value
    */
    void	add(int val)					{ add<int>(val); }
    /*!
        \brief adds a string parameter to the message
        \param val the parameter value
    */
    void	add(const std::string& val)		{ add<std::string>(val); }

    /*!
        \brief adds a parameter to the message
        \param val the parameter
    */
    void	add(argPtr val)                 { fArguments.push_back( val ); }

    /*!
        \brief sets the message address
        \param addr the address
    */
    void				setSrcIP(unsigned long addr)		{ fSrcIP = addr; }

    /*!
        \brief sets the message address
        \param addr the address
    */
    void				setAddress(const std::string& addr)		{ fAddress = addr; }
    /*!
        \brief print the message
        \param out the output stream
    */
    void				print(std::ostream& out) const;
    /*!
        \brief send the message to OSC
        \param out the OSC output stream
    */
    void				print(OSCStream& out) const;
    /*!
        \brief print message arguments
        \param out the OSC output stream
    */
    void				printArgs(OSCStream& out) const;

    /// \brief gives the message address
    const std::string&	address() const		{ return fAddress; }
    /// \brief gives the message alias
    const std::string&	alias() const		{ return fAlias; }
    /// \brief gives the message parameters list
    const argslist&		params() const		{ return fArguments; }
    /// \brief gives the message parameters list
    argslist&			params()			{ return fArguments; }
    /// \brief gives the message source IP 
    unsigned long		src() const			{ return fSrcIP; }
    /// \brief gives the message parameters count
    int					size() const		{ return (int)fArguments.size(); }

    bool operator == (const Message& other) const;	

    /*!
        \brief gives a message float parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, float& val) const		{ val = params()[i]->value<float>(val); return params()[i]->isType<float>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, int& val) const		{ val = params()[i]->value<int>(val); return params()[i]->isType<int>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, unsigned int& val) const		{ val = params()[i]->value<int>(val); return params()[i]->isType<int>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
        \note a boolean value is handled as integer
    */
    bool	param(int i, bool& val) const		{ int ival = 0; ival = params()[i]->value<int>(ival); val = ival!=0; return params()[i]->isType<int>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, long int& val) const	{ val = long(params()[i]->value<int>(val)); return params()[i]->isType<int>(); }
    /*!
        \brief gives a message string parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, std::string& val) const { val = params()[i]->value<std::string>(val); return params()[i]->isType<std::string>(); }
};


} // end namespoace

#endif
/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __RootNode__
#define __RootNode__

#include <map>
#include <string>
#include <vector>


namespace oscfaust
{

class OSCIO;
class RootNode;
typedef class SMARTP<RootNode> SRootNode;

/**
 * an alias target includes a map to rescale input values to output values
 * and a target osc address. The input values can be given in reversed order
 * to reverse the control
 */
struct aliastarget
{
	float       fMinIn;
	float       fMaxIn;
	float       fMinOut;
	float       fMaxOut;
	std::string fTarget;	// the real osc address

	aliastarget(const char* address, float imin, float imax, float omin, float omax)
		: fMinIn(imin), fMaxIn(imax), fMinOut(omin), fMaxOut(omax), fTarget(address) {}

	aliastarget(const aliastarget& t)
		: fMinIn(t.fMinIn), fMaxIn(t.fMaxIn), fMinOut(t.fMinOut), fMaxOut(t.fMaxOut), fTarget(t.fTarget) {}

	float scale(float x) const 
    {
        if (fMinIn < fMaxIn) {
            // increasing control
            float z = (x < fMinIn) ? fMinIn : (x > fMaxIn) ? fMaxIn : x;
            return fMinOut + (z-fMinIn)*(fMaxOut-fMinOut)/(fMaxIn-fMinIn);
            
        } else if (fMinIn > fMaxIn) {
            // reversed control
            float z = (x < fMaxIn) ? fMaxIn : (x > fMinIn) ? fMinIn : x;
            return fMinOut + (fMinIn-z)*(fMaxOut-fMinOut)/(fMinIn-fMaxIn);
            
        } else {
            // no control !
            return (fMinOut+fMaxOut)/2.0f;
        }
    }
    
    float invscale(float x) const
    {
        if (fMinOut < fMaxOut) {
            // increasing control
            float z = (x < fMinOut) ? fMinOut : (x > fMaxOut) ? fMaxOut : x;
            return fMinIn + (z-fMinOut)*(fMaxIn-fMinIn)/(fMaxOut-fMinOut);
            
        } else if (fMinOut > fMaxOut) {
            // reversed control
            float z = (x < fMaxOut) ? fMaxOut : (x > fMinOut) ? fMinOut : x;
            return fMinIn + (fMinOut-z)*(fMaxIn-fMinIn)/(fMinOut-fMaxOut);
            
        } else {
            // no control !
            return (fMinIn+fMaxIn)/2.0f;
        }
    }
};

//--------------------------------------------------------------------------
/*!
	\brief a faust root node

	A Faust root node handles the \c 'hello' message and provides support
	for incoming osc signal data. 
*/
class RootNode : public MessageDriven
{

    private:
        int *fUPDIn, *fUDPOut, *fUDPErr;    // the osc port numbers (required by the hello method)
        OSCIO* fIO;                         // an OSC IO controler
        JSONUI* fJSON;

        typedef std::map<std::string, std::vector<aliastarget> > TAliasMap;
        TAliasMap fAliases;

        void processAlias(const std::string& address, float val);
        void eraseAliases(const std::string& target);
        void eraseAlias(const std::string& target, const std::string& alias);
        bool aliasError(const Message* msg);

    protected:
        RootNode(const char *name, JSONUI* json, OSCIO* io = NULL) : MessageDriven(name, ""), fUPDIn(0), fUDPOut(0), fUDPErr(0), fIO(io), fJSON(json) {}
        virtual ~RootNode() {}

    public:
        static SRootNode create(const char* name, JSONUI* json, OSCIO* io = NULL) { return new RootNode(name, json, io); }

        virtual void processMessage(const Message* msg);
        virtual bool accept(const Message* msg);
        virtual void get(unsigned long ipdest) const;
        virtual void get(unsigned long ipdest, const std::string& what) const;

        bool aliasMsg(const Message* msg, float omin, float omax);
        void addAlias(const char* alias, const char* address, float imin, float imax, float omin, float omax);
        bool acceptSignal(const Message* msg);      ///< handler for signal data
        void hello(unsigned long ipdest) const;     ///< handler for the 'hello' message
        void setPorts(int* in, int* out, int* err);

        std::vector<std::pair<std::string, double> > getAliases(const std::string& address, double value);
};

} // end namespoace

#endif

namespace oscfaust
{

/**
 * map (rescale) input values to output values
 */
template <typename C> struct mapping
{
	const C fMinOut;
	const C fMaxOut;
	mapping(C omin, C omax) : fMinOut(omin), fMaxOut(omax) {}
	C clip (C x) { return (x < fMinOut) ? fMinOut : (x > fMaxOut) ? fMaxOut : x; }
};

//--------------------------------------------------------------------------
/*!
	\brief a faust node is a terminal node and represents a faust parameter controler
*/
template <typename C> class FaustNode : public MessageDriven, public uiTypedItem<C>
{
	mapping<C>	fMapping;
    RootNode* fRoot;
    bool fInput;  // true for input nodes (slider, button...)
	
	//---------------------------------------------------------------------
	// Warning !!!
	// The cast (C *)fZone is necessary because the real size allocated is
	// only known at execution time. When the library is compiled, fZone is
	// uniquely defined by FAUSTFLOAT.
	//---------------------------------------------------------------------
	bool	store(C val) { *(C *)this->fZone = fMapping.clip(val); return true; }
	void	sendOSC() const;

	protected:
		FaustNode(RootNode* root, const char *name, C* zone, C init, C min, C max, const char* prefix, GUI* ui, bool initZone, bool input) 
			: MessageDriven(name, prefix), uiTypedItem<C>(ui, zone), fMapping(min, max), fRoot(root), fInput(input)
			{
                if (initZone) {
                    *zone = init; 
                }
            }
			
		virtual ~FaustNode() {}

	public:
		typedef SMARTP<FaustNode<C> > SFaustNode;
		static SFaustNode create(RootNode* root, const char* name, C* zone, C init, C min, C max, const char* prefix, GUI* ui, bool initZone, bool input)	
        { 
            SFaustNode node = new FaustNode(root, name, zone, init, min, max, prefix, ui, initZone, input); 
            /*
                Since FaustNode is a subclass of uiItem, the pointer will also be kept in the GUI class, and it's desallocation will be done there.
                So we don't want to have smartpointer logic desallocate it and we increment the refcount.
            */
            node->addReference();
            return node; 
        }
    
		bool accept(const Message* msg);
		void get(unsigned long ipdest) const;		///< handler for the 'get' message
		virtual void reflectZone() { sendOSC(); this->fCache = *this->fZone; }
};

} // end namespace

#endif

class GUI;
namespace oscfaust
{

class OSCIO;
class RootNode;
typedef class SMARTP<RootNode> SRootNode;
class MessageDriven;
typedef class SMARTP<MessageDriven>	SMessageDriven;

//--------------------------------------------------------------------------
/*!
	\brief a factory to build a OSC UI hierarchy
	
	Actually, makes use of a stack to build the UI hierarchy.
	It includes a pointer to a OSCIO controler, but just to give it to the root node.
*/
class FaustFactory
{
	std::stack<SMessageDriven>	fNodes;		///< maintains the current hierarchy level
	SRootNode					fRoot;		///< keep track of the root node
	OSCIO*                      fIO;		///< hack to support audio IO via OSC, actually the field is given to the root node
	GUI*						fGUI;		///< a GUI pointer to support updateAllGuis(), required for bi-directionnal OSC
    JSONUI*                     fJSON;
    
	private:
		std::string addressFirst(const std::string& address) const;
		std::string addressTail(const std::string& address) const;

	public:
				 FaustFactory(GUI* ui, JSONUI* json, OSCIO * io = NULL);
		virtual ~FaustFactory(); 

		template <typename C> void addnode(const char* label, C* zone, C init, C min, C max, bool initZone, bool input);
		template <typename C> void addAlias(const std::string& fullpath, C* zone, C imin, C imax, C init, C min, C max, const char* label);
        
		void addAlias(const char* alias, const char* address, float imin, float imax, float omin, float omax);
		void opengroup(const char* label);
		void closegroup();

		SRootNode root() const; 
};

/**
 * Add a node to the OSC UI tree in the current group at the top of the stack 
 */
template <typename C> void FaustFactory::addnode(const char* label, C* zone, C init, C min, C max, bool initZone, bool input) 
{
	SMessageDriven top;
	if (fNodes.size()) top = fNodes.top();
	if (top) {
		std::string prefix = top->getOSCAddress();
		top->add(FaustNode<C>::create(root(), label, zone, init, min, max, prefix.c_str(), fGUI, initZone, input));
	}
}

/**
 * Add an alias (actually stored and handled at root node level
 */
template <typename C> void FaustFactory::addAlias(const std::string& fullpath, C* zone, C imin, C imax, C init, C min, C max, const char* label)
{
	std::istringstream 	ss(fullpath);
	std::string 		realpath; 
 
	ss >> realpath >> imin >> imax;
	SMessageDriven top = fNodes.top();
	if (top) {
		std::string target = top->getOSCAddress() + "/" + label;
		addAlias(realpath.c_str(), target.c_str(), float(imin), float(imax), float(min), float(max));
	}
}

} // end namespoace

#endif

class GUI;

typedef void (*ErrorCallback)(void*);  

namespace oscfaust
{

class OSCIO;
class OSCSetup;
class OSCRegexp;
    
//--------------------------------------------------------------------------
/*!
	\brief the main Faust OSC Lib API
	
	The OSCControler is essentially a glue between the memory representation (in charge of the FaustFactory),
	and the network services (in charge of OSCSetup).
*/
class OSCControler
{
	int fUDPPort,   fUDPOut, fUPDErr;	// the udp ports numbers
	std::string     fDestAddress;		// the osc messages destination address, used at initialization only
										// to collect the address from the command line
	std::string     fBindAddress;		// when non empty, the address used to bind the socket for listening
	OSCSetup*		fOsc;				// the network manager (handles the udp sockets)
	OSCIO*			fIO;				// hack for OSC IO support (actually only relayed to the factory)
	FaustFactory*	fFactory;			// a factory to build the memory representation

    bool            fInit;
    
	public:
		/*
			base udp port is chosen in an unassigned range from IANA PORT NUMBERS (last updated 2011-01-24)
			see at http://www.iana.org/assignments/port-numbers
			5507-5552  Unassigned
		*/
		enum { kUDPBasePort = 5510 };
            
        OSCControler(int argc, char* argv[], GUI* ui, JSONUI* json, OSCIO* io = NULL, ErrorCallback errCallback = NULL, void* arg = NULL, bool init = true);

        virtual ~OSCControler();
	
		//--------------------------------------------------------------------------
		// addnode, opengroup and closegroup are simply relayed to the factory
		//--------------------------------------------------------------------------
		// Add a node in the current group (top of the group stack)
		template <typename T> void addnode(const char* label, T* zone, T init, T min, T max, bool input = true)
							{ fFactory->addnode(label, zone, init, min, max, fInit, input); }
		
		//--------------------------------------------------------------------------
		// This method is used for alias messages. The arguments imin and imax allow
		// to map incomming values from the alias input range to the actual range 
		template <typename T> void addAlias(const std::string& fullpath, T* zone, T imin, T imax, T init, T min, T max, const char* label)
							{ fFactory->addAlias(fullpath, zone, imin, imax, init, min, max, label); }

		void opengroup(const char* label)		{ fFactory->opengroup(label); }
		void closegroup()						{ fFactory->closegroup(); }
	   
		//--------------------------------------------------------------------------
		void run();				// starts the network services
		void endBundle();		// when bundle mode is on, close and send the current bundle (if any)
		void stop();			// stop the network services
		std::string getInfos() const; // gives information about the current environment (version, port numbers,...)

		int	getUDPPort() const			{ return fUDPPort; }
		int	getUDPOut()	const			{ return fUDPOut; }
		int	getUDPErr()	const			{ return fUPDErr; }
		const char*	getDestAddress() const { return fDestAddress.c_str(); }
		const char*	getRootName() const;	// probably useless, introduced for UI extension experiments
    
        void setUDPPort(int port) { fUDPPort = port; }
        void setUDPOut(int port) { fUDPOut = port; }
        void setUDPErr(int port) { fUPDErr = port; }
        void setDestAddress(const char* address) { fDestAddress = address; }

        // By default, an osc interface emits all parameters. You can filter specific params dynamically.
        static std::vector<OSCRegexp*>     fFilteredPaths; // filtered paths will not be emitted
        static void addFilteredPath(std::string path);
        static bool isPathFiltered(std::string path);
        static void resetFilteredPaths();
    
		static float version();				// the Faust OSC library version number
		static const char* versionstr();	// the Faust OSC library version number as a string
		static int gXmit;                   // a static variable to control the transmission of values
                                            // i.e. the use of the interface as a controler
		static int gBundle;                 // a static variable to control the osc bundle mode
};

#define kNoXmit     0
#define kAll        1
#define kAlias      2

}

#endif

#ifdef _WIN32
#define strcasecmp _stricmp
#endif

/******************************************************************************
 *******************************************************************************
 
 OSC (Open Sound Control) USER INTERFACE
 
 *******************************************************************************
 *******************************************************************************/
/*
 
 Note about the OSC addresses and the Faust UI names:
 ----------------------------------------------------
 There are potential conflicts between the Faust UI objects naming scheme and
 the OSC address space. An OSC symbolic names is an ASCII string consisting of
 printable characters other than the following:
	space
 #	number sign
 *	asterisk
 ,	comma
 /	forward
 ?	question mark
 [	open bracket
 ]	close bracket
 {	open curly brace
 }	close curly brace
 
 a simple solution to address the problem consists in replacing
 space or tabulation with '_' (underscore)
 all the other osc excluded characters with '-' (hyphen)
 
 This solution is implemented in the proposed OSC UI;
 */

class OSCUI : public GUI
{
    
    private:
        
        oscfaust::OSCControler*	fCtrl;
        std::vector<const char*> fAlias;
        JSONUI fJSON;
        
        const char* tr(const char* label) const
        {
            static char buffer[1024];
            char * ptr = buffer; int n=1;
            while (*label && (n++ < 1024)) {
                switch (*label) {
                    case ' ': case '	':
                        *ptr++ = '_';
                        break;
                    case '#': case '*': case ',': case '/': case '?':
                    case '[': case ']': case '{': case '}': case '(': case ')':
                        *ptr++ = '_';
                        break;
                    default:
                        *ptr++ = *label;
                }
                label++;
            }
            *ptr = 0;
            return buffer;
        }
        
        // add all accumulated alias
        void addalias(FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, const char* label)
        {
            for (unsigned int i = 0; i < fAlias.size(); i++) {
                fCtrl->addAlias(fAlias[i], zone, FAUSTFLOAT(0), FAUSTFLOAT(1), init, min, max, label);
            }
            fAlias.clear();
        }
        
    public:
        
        OSCUI(const char* /*applicationname*/, int argc, char* argv[], oscfaust::OSCIO* io = NULL, ErrorCallback errCallback = NULL, void* arg = NULL, bool init = true) : GUI()
        {
            fCtrl = new oscfaust::OSCControler(argc, argv, this, &fJSON, io, errCallback, arg, init);
            //		fCtrl->opengroup(applicationname);
        }
        
        virtual ~OSCUI() { delete fCtrl; }
        
        // -- widget's layouts
        
        virtual void openTabBox(const char* label)          { fCtrl->opengroup(tr(label)); fJSON.openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fCtrl->opengroup(tr(label)); fJSON.openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fCtrl->opengroup(tr(label)); fJSON.openVerticalBox(label); }
        virtual void closeBox()                             { fCtrl->closegroup(); fJSON.closeBox(); }
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            const char* l = tr(label);
            addalias(zone, 0, 0, 1, l);
            fCtrl->addnode(l, zone, FAUSTFLOAT(0), FAUSTFLOAT(0), FAUSTFLOAT(1));
            fJSON.addButton(label, zone);
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            const char* l = tr(label);
            addalias(zone, 0, 0, 1, l);
            fCtrl->addnode(l, zone, FAUSTFLOAT(0), FAUSTFLOAT(0), FAUSTFLOAT(1));
            fJSON.addCheckButton(label, zone);
        }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            const char* l = tr(label);
            addalias(zone, init, min, max, l);
            fCtrl->addnode(l, zone, init, min, max);
            fJSON.addVerticalSlider(label, zone, init, min, max, step);
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            const char* l = tr(label);
            addalias(zone, init, min, max, l);
            fCtrl->addnode(l, zone, init, min, max);
            fJSON.addHorizontalSlider(label, zone, init, min, max, step);
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            const char* l = tr(label);
            addalias(zone, init, min, max, l);
            fCtrl->addnode(l, zone, init, min, max);
            fJSON.addNumEntry(label, zone, init, min, max, step);
        }
        
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            const char* l = tr(label);
            addalias(zone, 0, min, max, l);
            fCtrl->addnode(l, zone, FAUSTFLOAT(0), min, max, false);
            fJSON.addHorizontalBargraph(label, zone, min, max);
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            const char* l = tr(label);
            addalias(zone, 0, min, max, l);
            fCtrl->addnode(l, zone, FAUSTFLOAT(0), min, max, false);
            fJSON.addVerticalBargraph(label, zone, min, max);
        }
            
        // -- metadata declarations
        
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* alias)
        {
            if (strcasecmp(key, "OSC") == 0) fAlias.push_back(alias);
            fJSON.declare(zone, key, alias);
        }
        
        virtual void show() {}
        
        bool run()
        {
            fCtrl->run();
            return true;
        }
        
        void stop()			{ fCtrl->stop(); }
        void endBundle() 	{ fCtrl->endBundle(); }
        
        std::string getInfos()          { return fCtrl->getInfos(); }
        
        const char* getRootName()		{ return fCtrl->getRootName(); }
        int getUDPPort()                { return fCtrl->getUDPPort(); }
        int getUDPOut()                 { return fCtrl->getUDPOut(); }
        int getUDPErr()                 { return fCtrl->getUDPErr(); }
        const char* getDestAddress()    { return fCtrl->getDestAddress(); }
        
        void setUDPPort(int port)       { fCtrl->setUDPPort(port); }
        void setUDPOut(int port)        { fCtrl->setUDPOut(port); }
        void setUDPErr(int port)        { fCtrl->setUDPErr(port); }
        void setDestAddress(const char* address)    { return fCtrl->setDestAddress(address); }
    
};

#endif // __OSCUI__
/**************************  END  OSCUI.h **************************/
static void osc_compute_callback(void* arg)
{
    static_cast<OSCUI*>(arg)->endBundle();
}
#endif

#ifdef HTTPCTRL
/************************** BEGIN httpdUI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __httpdUI__
#define __httpdUI__

#include <iostream>
#include <sstream>
#include <cstdlib>

/*

  Faust Project

  Copyright (C) 2012 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __HTTPDControler__
#define __HTTPDControler__

#include <string>
#include <map>

namespace httpdfaust
{

class HTTPDSetup;
class JSONDesc;
class FaustFactory;
class jsonfactory;
class htmlfactory;

//--------------------------------------------------------------------------
/*!
	\brief the main Faust HTTPD Lib API
	
	The HTTPDControler is essentially a glue between the memory representation (in charge of the FaustFactory), 
	and the network services (in charge of HTTPDSetup).
*/
class HTTPDControler
{
	int fTCPPort;				// the tcp port number
	FaustFactory*	fFactory;	// a factory to build the memory representation
	jsonfactory*	fJson;
	htmlfactory*	fHtml;
	HTTPDSetup*		fHttpd;		// the network manager
	std::string		fHTML;		// the corresponding HTML page
	std::map<std::string, std::string>	fCurrentMeta;	// the current meta declarations 

    bool            fInit;
    
	public:
		/*
			base udp port is chosen in an unassigned range from IANA PORT NUMBERS (last updated 2011-01-24)
			see at http://www.iana.org/assignments/port-numbers
			5507-5552  Unassigned
		*/
		enum { kTCPBasePort = 5510};

				 HTTPDControler(int argc, char *argv[], const char* applicationname, bool init = true);
		virtual ~HTTPDControler();
	
		//--------------------------------------------------------------------------
		// addnode, opengroup and closegroup are simply relayed to the factory
		//--------------------------------------------------------------------------
		template <typename C> void addnode(const char* type, const char* label, C* zone);
		template <typename C> void addnode(const char* type, const char* label, C* zone, C min, C max);
		template <typename C> void addnode(const char* type, const char* label, C* zone, C init, C min, C max, C step);
							  void declare(const char* key, const char* val ) { fCurrentMeta[key] = val; }

		void opengroup(const char* type, const char* label);
		void closegroup();

		//--------------------------------------------------------------------------
		void run();				// start the httpd server
		void stop();			// stop the httpd server
		
		int	getTCPPort()			{ return fTCPPort; }
        std::string getJSON();
        void        setInputs(int numInputs);
        void        setOutputs(int numOutputs);

		static float version();				// the Faust httpd library version number
		static const char* versionstr();	// the Faust httpd library version number as a string
};

}

#endif

#ifndef _WIN32
#include <unistd.h>
#include <pthread.h>
#endif

/******************************************************************************
*******************************************************************************

					HTTPD USER INTERFACE

*******************************************************************************
*******************************************************************************/

class httpdUIAux
{
    public:
    
        virtual ~httpdUIAux() {}

        virtual bool run()              = 0;
        virtual void stop()             = 0;
        virtual int getTCPPort()        = 0;
        virtual std::string getJSON()   = 0;
};

/*

Note about URLs and the Faust UI names:
----------------------------------------------------
Characters in a url could be:
1. Reserved: ; / ? : @ & = + $ ,
   These characters delimit URL parts.
2. Unreserved: alphanum - _ . ! ~ * ' ( )
   These characters have no special meaning and can be used as is.
3. Excluded: control characters, space, < > # % ", { } | \ ^ [ ] `

To solve potential conflicts between the Faust UI objects naming scheme and
the URL allowed characters, the reserved and excluded characters are replaced
with '-' (hyphen).
Space or tabulation are replaced with '_' (underscore)
*/

class httpdServerUI : public UI, public httpdUIAux
{
    private:

        httpdfaust::HTTPDControler*	fCtrl;

        const char* tr(const char* label) const
        {
            static char buffer[1024];
            char * ptr = buffer; int n = 1;
            while (*label && (n++ < 1024)) {
                switch (*label) {
                    case ' ': case '	':
                        *ptr++ = '_';
                        break;
                    case ';': case '/': case '?': case ':': case '@':
                    case '&': case '=': case '+': case '$': case ',':
                    case '<': case '>': case '#': case '%': case '"':
                    case '{': case '}': case '|': case '\\': case '^':
                    case '[': case ']': case '`':
                        *ptr++ = '_';
                        break;
                    default:
                        *ptr++ = *label;
                }
                label++;
            }
            *ptr = 0;
            return buffer;
        }

    public:

        httpdServerUI(const char* applicationname, int inputs, int outputs, int argc, char* argv[], bool init = true)
        {
            fCtrl = new httpdfaust::HTTPDControler(argc, argv, applicationname, init);
            fCtrl->setInputs(inputs);
            fCtrl->setOutputs(outputs);
        }

        virtual ~httpdServerUI() { delete fCtrl; }

        // -- widget's layouts
        virtual void openTabBox(const char* label) 			{ fCtrl->opengroup("tgroup", tr(label)); }
        virtual void openHorizontalBox(const char* label) 	{ fCtrl->opengroup("hgroup", tr(label)); }
        virtual void openVerticalBox(const char* label) 	{ fCtrl->opengroup("vgroup", tr(label)); }
        virtual void closeBox() 							{ fCtrl->closegroup(); }

        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)			{ fCtrl->addnode("button", tr(label), zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)	{ fCtrl->addnode("checkbox", tr(label), zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
                                        { fCtrl->addnode("vslider", tr(label), zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
                                        { fCtrl->addnode("hslider", tr(label), zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
                                        { fCtrl->addnode("nentry", tr(label), zone, init, min, max, step); }

        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
                                        { fCtrl->addnode("hbargraph", tr(label), zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
                                        { fCtrl->addnode("vbargraph", tr(label), zone, min, max); }
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}

        virtual void declare(FAUSTFLOAT*, const char* key, const char* val) { fCtrl->declare(key, val); }

        bool run()						{ fCtrl->run(); return true; }
        void stop()						{ fCtrl->stop(); }
        int getTCPPort()                { return fCtrl->getTCPPort(); }

        std::string getJSON() { return fCtrl->getJSON(); }

};

// API from sourcefetcher.hh and compiled in libHTTPDFaust library.
int http_fetch(const char *url, char **fileBuf);

/*
Use to control a running Faust DSP wrapped with "httpdServerUI".
*/

#ifndef _WIN32
class httpdClientUI : public GUI, public PathBuilder, public httpdUIAux
{

    private:

        class uiUrlValue : public uiItem
        {

            private:

                std::string fPathURL;

            public:

                uiUrlValue(const std::string& path_url, GUI* ui, FAUSTFLOAT* zone)
                    :uiItem(ui, zone),fPathURL(path_url)
                {}
                virtual ~uiUrlValue()
                {}

                virtual void reflectZone()
                {
                    FAUSTFLOAT v = *fZone;
                    fCache = v;
                    std::stringstream str;
                    str << fPathURL << "?value=" << v;
                    std::string path = str.str();
                    http_fetch(path.c_str(), NULL);
                }

        };

        std::string fServerURL;
        std::string fJSON;
        std::map<std::string, FAUSTFLOAT*> fZoneMap;
        pthread_t fThread;
        int fTCPPort;
        bool fRunning;

        void insertMap(std::string label, FAUSTFLOAT* zone)
        {
            fZoneMap[label] = zone;
        }

        static void* UpdateUI(void* arg)
        {
            httpdClientUI* ui = static_cast<httpdClientUI*>(arg);
            std::map<std::string, FAUSTFLOAT*>::iterator it;
            while (ui->fRunning) {
                for (it = ui->fZoneMap.begin(); it != ui->fZoneMap.end(); it++) {
                    char* answer;
                    std::string path = (*it).first;
                    http_fetch(path.c_str(), &answer);
                    std::string answer_str = answer;
                    (*(*it).second) = (FAUSTFLOAT)std::strtod(answer_str.substr(answer_str.find(' ')).c_str(), NULL);
                    // 'http_fetch' result must be deallocated
                    free(answer);
                }
                usleep(100000);
            }
			return 0;
        }

        virtual void addGeneric(const char* label, FAUSTFLOAT* zone)
        {
            std::string url = fServerURL + buildPath(label);
            insertMap(url, zone);
            new uiUrlValue(url, this, zone);
        }

    public:

        httpdClientUI(const std::string& server_url):fServerURL(server_url), fRunning(false)
        {
            char* json_buffer = 0;
            std::string json_url = std::string(server_url) + "/JSON";
            http_fetch(json_url.c_str(), &json_buffer);
            if (json_buffer) {
                fJSON = json_buffer;
                fTCPPort = std::atoi(server_url.substr(server_url.find_last_of(':') + 1).c_str());
                // 'http_fetch' result must be deallocated
                free(json_buffer);
                std::cout << "Faust httpd client controling server '" << server_url << "'" << std::endl;
            } else {
                fJSON = "";
                fTCPPort = -1;
            }
        }

        virtual ~httpdClientUI()
        {
            stop();
        }

        // -- widget's layouts
        void openTabBox(const char* label)
        {
            pushLabel(label);
        }
        void openHorizontalBox(const char* label)
        {
            pushLabel(label);
        }
        void openVerticalBox(const char* label)
        {
            pushLabel(label);
        }
        void closeBox()
        {
            popLabel();
        }

        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            // addGeneric(label, zone);
            // Do not update button state with received messages (otherwise on/off messages may be lost...)
            std::string url = fServerURL + buildPath(label);
            new uiUrlValue(url, this, zone);
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addGeneric(label, zone);
        }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGeneric(label, zone);
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGeneric(label, zone);
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGeneric(label, zone);
        }

        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addGeneric(label, zone);
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addGeneric(label, zone);
        }

        virtual void declare(FAUSTFLOAT*, const char* key, const char* val) {}

        bool run()
        {
            if (fTCPPort > 0) {
                fRunning = true;
                return (pthread_create(&fThread, NULL, UpdateUI, this) == 0);
            } else {
                return false;
            }
        }

        void stop()
        {
            if (fRunning) {
                fRunning = false;
                pthread_join(fThread, NULL);
            }
        }

        int getTCPPort()
        {
            return fTCPPort;
        }

        std::string getJSON() { return fJSON; }

};
#endif

/*
Creates a httpdServerUI or httpdClientUI depending of the presence of '-server URL' parameter.
*/

class httpdUI : public DecoratorUI
{

    public:

        httpdUI(const char* applicationname, int inputs, int outputs, int argc, char* argv[], bool init = true)
        {
            if (argv && isopt(argv, "-server")) {
            #ifndef _WIN32
                fUI = new httpdClientUI(lopts(argv, "-server", "http://localhost:5510"));
            #endif
            } else {
                fUI = new httpdServerUI(applicationname, inputs, outputs, argc, argv, init);
            }
        }

        bool run() { return dynamic_cast<httpdUIAux*>(fUI)->run(); }
        void stop() { dynamic_cast<httpdUIAux*>(fUI)->stop(); }
        int getTCPPort() { return dynamic_cast<httpdUIAux*>(fUI)->getTCPPort(); }

        std::string getJSON() { return dynamic_cast<httpdUIAux*>(fUI)->getJSON(); }

};

#endif
/**************************  END  httpdUI.h **************************/
#endif

#ifdef SOUNDFILE
/************************** BEGIN SoundUI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __SoundUI_H__
#define __SoundUI_H__

#include <map>
#include <vector>
#include <string>


#ifdef __APPLE__
#include <CoreFoundation/CFBundle.h>
#endif

// Always included otherwise -i mode later on will not always include it (with the conditional includes)
/************************** BEGIN Soundfile.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.

 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __Soundfile__
#define __Soundfile__

#include <iostream>
#include <string.h>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#define BUFFER_SIZE 16384
#define SAMPLE_RATE 44100
#define MAX_CHAN 64
#define MAX_SOUNDFILE_PARTS 256

#ifdef _MSC_VER
#define PRE_PACKED_STRUCTURE __pragma(pack(push, 1))
#define POST_PACKED_STRUCTURE \
    ;                         \
    __pragma(pack(pop))
#else
#define PRE_PACKED_STRUCTURE
#define POST_PACKED_STRUCTURE __attribute__((__packed__))
#endif

/*
 The soundfile structure to be used by the DSP code. Soundfile has a MAX_SOUNDFILE_PARTS parts 
 (even a single soundfile or an empty soundfile). 
 fLength, fOffset and fSR fields are filled accordingly by repeating
 the actual parts if needed.
 
 It has to be 'packed' to that the LLVM backend can correctly access it.

 Index computation:
    - p is the current part number [0..MAX_SOUNDFILE_PARTS-1] (must be proved by the type system)
    - i is the current position in the part. It will be constrained between [0..length]
    - idx(p,i) = fOffset[p] + max(0, min(i, fLength[p]));
*/

PRE_PACKED_STRUCTURE
struct Soundfile {
    FAUSTFLOAT** fBuffers;
    int* fLength;   // length of each part
    int* fSR;       // sample rate of each part
    int* fOffset;   // offset of each part in the global buffer
    int fChannels;  // max number of channels of all concatenated files

    Soundfile()
    {
        fBuffers  = NULL;
        fChannels = -1;
        fLength   = new int[MAX_SOUNDFILE_PARTS];
        fSR       = new int[MAX_SOUNDFILE_PARTS];
        fOffset   = new int[MAX_SOUNDFILE_PARTS];
    }

    ~Soundfile()
    {
        // Free the real channels only
        for (int chan = 0; chan < fChannels; chan++) {
            delete fBuffers[chan];
        }
        delete[] fBuffers;
        delete[] fLength;
        delete[] fSR;
        delete[] fOffset;
    }

} POST_PACKED_STRUCTURE;

/*
 The generic soundfile reader.
 */

class SoundfileReader {
    
   protected:
    
    int fDriverSR;
    
    void emptyFile(Soundfile* soundfile, int part, int& offset)
    {
        soundfile->fLength[part] = BUFFER_SIZE;
        soundfile->fSR[part] = SAMPLE_RATE;
        soundfile->fOffset[part] = offset;
        // Update offset
        offset += soundfile->fLength[part];
    }

    Soundfile* createSoundfile(int cur_chan, int length, int max_chan)
    {
        Soundfile* soundfile = new Soundfile();
        if (!soundfile) {
            throw std::bad_alloc();
        }
        
        soundfile->fBuffers = new FAUSTFLOAT*[max_chan];
        if (!soundfile->fBuffers) {
            throw std::bad_alloc();
        }
        
        for (int chan = 0; chan < cur_chan; chan++) {
            soundfile->fBuffers[chan] = new FAUSTFLOAT[length];
            if (!soundfile->fBuffers[chan]) {
                throw std::bad_alloc();
            }
            memset(soundfile->fBuffers[chan], 0, sizeof(FAUSTFLOAT) * length);
        }
        
        soundfile->fChannels = cur_chan;
        return soundfile;
    }

    void getBuffersOffset(Soundfile* soundfile, FAUSTFLOAT** buffers, int offset)
    {
        for (int chan = 0; chan < soundfile->fChannels; chan++) {
            buffers[chan] = &soundfile->fBuffers[chan][offset];
        }
    }
    
    // Check if a soundfile exists and return its real path_name
    std::string checkFile(const std::vector<std::string>& sound_directories, const std::string& file_name)
    {
        if (checkFile(file_name)) {
            return file_name;
        } else {
            for (size_t i = 0; i < sound_directories.size(); i++) {
                std::string path_name = sound_directories[i] + "/" + file_name;
                if (checkFile(path_name)) { return path_name; }
            }
            return "";
        }
    }
    
    bool isResampling(int sample_rate) { return (fDriverSR > 0 && fDriverSR != sample_rate); }
 
    // To be implemented by subclasses

    /**
     * Check the availability of a sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     *
     * @return true if the sound resource is available, false otherwise.
     */
    virtual bool checkFile(const std::string& path_name) = 0;
    
    /**
     * Check the availability of a sound resource.
     *
     * @param buffer - the sound buffer
     * @param buffer - the sound buffer length
     *
     * @return true if the sound resource is available, false otherwise.
     */

    virtual bool checkFile(unsigned char* buffer, size_t length) { return true; }

    /**
     * Get the channels and length values of the given sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param channels - the channels value to be filled with the sound resource number of channels
     * @param length - the length value to be filled with the sound resource length in frames
     *
     */
    virtual void getParamsFile(const std::string& path_name, int& channels, int& length) = 0;
    
    /**
     * Get the channels and length values of the given sound resource.
     *
     * @param buffer - the sound buffer
     * @param buffer - the sound buffer length
     * @param channels - the channels value to be filled with the sound resource number of channels
     * @param length - the length value to be filled with the sound resource length in frames
     *
     */
    virtual void getParamsFile(unsigned char* buffer, size_t size, int& channels, int& length) {}

    /**
     * Read one sound resource and fill the 'soundfile' structure accordingly
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param part - the part number to be filled in the soundfile
     * @param offset - the offset value to be incremented with the actual sound resource length in frames
     * @param max_chan - the maximum number of mono channels to fill
     *
     */
    virtual void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan) = 0;
    
    /**
     * Read one sound resource and fill the 'soundfile' structure accordingly
     *
     * @param buffer - the sound buffer
     * @param buffer - the sound buffer length
     * @param part - the part number to be filled in the soundfile
     * @param offset - the offset value to be incremented with the actual sound resource length in frames
     * @param max_chan - the maximum number of mono channels to fill
     *
     */
    virtual void readFile(Soundfile* soundfile, unsigned char* buffer, size_t length, int part, int& offset, int max_chan) {}

  public:
    
    virtual ~SoundfileReader() {}
    
    void setSampleRate(int sample_rate) { fDriverSR = sample_rate; }
   
    Soundfile* createSoundfile(const std::vector<std::string>& path_name_list, int max_chan)
    {
        try {
            int cur_chan = 1; // At least one buffer
            int total_length = 0;
            
            // Compute total length and channels max of all files
            for (int i = 0; i < int(path_name_list.size()); i++) {
                int chan, length;
                if (path_name_list[i] == "__empty_sound__") {
                    length = BUFFER_SIZE;
                    chan = 1;
                } else {
                    getParamsFile(path_name_list[i], chan, length);
                }
                cur_chan = std::max<int>(cur_chan, chan);
                total_length += length;
            }
           
            // Complete with empty parts
            total_length += (MAX_SOUNDFILE_PARTS - path_name_list.size()) * BUFFER_SIZE;
            
            // Create the soundfile
            Soundfile* soundfile = createSoundfile(cur_chan, total_length, max_chan);
            
            // Init offset
            int offset = 0;
            
            // Read all files
            for (int i = 0; i < int(path_name_list.size()); i++) {
                if (path_name_list[i] == "__empty_sound__") {
                    emptyFile(soundfile, i, offset);
                } else {
                    readFile(soundfile, path_name_list[i], i, offset, max_chan);
                }
            }
            
            // Complete with empty parts
            for (int i = int(path_name_list.size()); i < MAX_SOUNDFILE_PARTS; i++) {
                emptyFile(soundfile, i, offset);
            }
            
            // Share the same buffers for all other channels so that we have max_chan channels available
            for (int chan = cur_chan; chan < max_chan; chan++) {
                soundfile->fBuffers[chan] = soundfile->fBuffers[chan % cur_chan];
            }
            
            return soundfile;
            
        } catch (...) {
            return NULL;
        }
    }

    // Check if all soundfiles exist and return their real path_name
    std::vector<std::string> checkFiles(const std::vector<std::string>& sound_directories,
                                        const std::vector<std::string>& file_name_list)
    {
        std::vector<std::string> path_name_list;
        for (size_t i = 0; i < file_name_list.size(); i++) {
            std::string path_name = checkFile(sound_directories, file_name_list[i]);
            // If 'path_name' is not found, it is replaced by an empty sound (= silence)
            path_name_list.push_back((path_name == "") ? "__empty_sound__" : path_name);
        }
        return path_name_list;
    }

};

#endif
/**************************  END  Soundfile.h **************************/

#if defined(JUCE_32BIT) || defined(JUCE_64BIT)
/************************** BEGIN JuceReader.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __JuceReader__
#define __JuceReader__

#include <assert.h>


struct JuceReader : public SoundfileReader {
    
    AudioFormatManager fFormatManager;
    
    JuceReader() { fFormatManager.registerBasicFormats(); }
    
    bool checkFile(const std::string& path_name)
    {
        File file(path_name);
        if (file.existsAsFile()) {
            return true;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name << "'" << std::endl;
            return false;
        }
    }
    
    void getParamsFile(const std::string& path_name, int& channels, int& length)
    {
        ScopedPointer<AudioFormatReader> formatReader = fFormatManager.createReaderFor(File(path_name));
        assert(formatReader);
        channels = int(formatReader->numChannels);
        length = int(formatReader->lengthInSamples);
    }
    
    void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan)
    {
        ScopedPointer<AudioFormatReader> formatReader = fFormatManager.createReaderFor(File(path_name));
        
        int channels = std::min<int>(max_chan, int(formatReader->numChannels));
        
        soundfile->fLength[part] = int(formatReader->lengthInSamples);
        soundfile->fSR[part] = int(formatReader->sampleRate);
        soundfile->fOffset[part] = offset;
        
        FAUSTFLOAT* buffers[soundfile->fChannels];
        getBuffersOffset(soundfile, buffers, offset);
        
        if (formatReader->read(reinterpret_cast<int *const *>(buffers), int(formatReader->numChannels), 0, int(formatReader->lengthInSamples), false)) {
            
            // Possibly concert samples
            if (!formatReader->usesFloatingPointData) {
                for (int chan = 0; chan < int(formatReader->numChannels); ++chan) {
                    FAUSTFLOAT* buffer = &soundfile->fBuffers[chan][soundfile->fOffset[part]];
                    FloatVectorOperations::convertFixedToFloat(buffer, reinterpret_cast<const int*>(buffer), 1.0f/0x7fffffff, int(formatReader->lengthInSamples));
                }
            }
            
        } else {
            std::cerr << "Error reading the file : " << path_name << std::endl;
        }
            
        // Update offset
        offset += soundfile->fLength[part];
    }
    
};

#endif
/**************************  END  JuceReader.h **************************/
JuceReader gReader;
#elif defined(MEMORY_READER)
/************************** BEGIN MemoryReader.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __MemoryReader__
#define __MemoryReader__


/*
 A 'MemoryReader' object can be used to prepare a set of sound resources in memory, to be used by SoundUI::addSoundfile.
 
 A Soundfile* object will have to be filled with a list of sound resources: the fLength, fOffset, fSampleRate and fBuffers fields 
 have to be completed with the appropriate values, and will be accessed in the DSP object while running.
 *
 */

// To adapt for a real case use

#define SOUND_CHAN      2
#define SOUND_LENGTH    4096
#define SOUND_SR        40100

struct MemoryReader : public SoundfileReader {
    
    MemoryReader()
    {}
    
    /**
     * Check the availability of a sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     *
     * @return true if the sound resource is available, false otherwise.
     */
    virtual bool checkFile(const std::string& path_name) { return true; }
    
    /**
     * Get the channels and length values of the given sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param channels - the channels value to be filled with the sound resource number of channels
     * @param length - the length value to be filled with the sound resource length in frames
     *
     */
    virtual void getParamsFile(const std::string& path_name, int& channels, int& length)
    {
        channels = SOUND_CHAN;
        length = SOUND_LENGTH;
    }
    
    /**
     * Read one sound resource and fill the 'soundfile' structure accordingly
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param part - the part number to be filled in the soundfile
     * @param offset - the offset value to be incremented with the actual sound resource length in frames
     * @param max_chan - the maximum number of mono channels to fill
     *
     */
    virtual void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan)
    {
        soundfile->fLength[part] = SOUND_LENGTH;
        soundfile->fSR[part] = SOUND_SR;
        soundfile->fOffset[part] = offset;
        
        // Audio frames have to be written for each chan
        for (int sample = 0; sample < SOUND_LENGTH; sample++) {
            for (int chan = 0; chan < SOUND_CHAN; chan++) {
                soundfile->fBuffers[chan][offset + sample] = 0.f;
            }
        }
        
        // Update offset
        offset += SOUND_LENGTH;
    }
    
};

#endif
/**************************  END  MemoryReader.h **************************/
MemoryReader gReader;
#else
/************************** BEGIN LibsndfileReader.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __LibsndfileReader__
#define __LibsndfileReader__

#ifdef SAMPLERATE
#include <samplerate.h>
#endif
#include <sndfile.h>
#include <string.h>
#include <assert.h>
#include <iostream>


struct VFLibsndfile {
    
    #define SIGNED_SIZEOF(x) ((int)sizeof(x))
    
    unsigned char* fBuffer;
    size_t fLength;
    size_t fOffset;
    SF_VIRTUAL_IO fVIO;
    
    VFLibsndfile(unsigned char* buffer, size_t length):fBuffer(buffer), fLength(length), fOffset(0)
    {
        fVIO.get_filelen = vfget_filelen;
        fVIO.seek = vfseek;
        fVIO.read = vfread;
        fVIO.write = vfwrite;
        fVIO.tell = vftell;
    }
    
    static sf_count_t vfget_filelen(void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        return vf->fLength;
    }
  
    static sf_count_t vfseek(sf_count_t offset, int whence, void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        switch (whence) {
            case SEEK_SET:
                vf->fOffset = offset;
                break;
                
            case SEEK_CUR:
                vf->fOffset = vf->fOffset + offset;
                break;
                
            case SEEK_END:
                vf->fOffset = vf->fLength + offset;
                break;
                
            default:
                break;
        };
        
        return vf->fOffset;
    }
    
    static sf_count_t vfread(void* ptr, sf_count_t count, void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        
        /*
         **	This will break badly for files over 2Gig in length, but
         **	is sufficient for testing.
         */
        if (vf->fOffset + count > vf->fLength) {
            count = vf->fLength - vf->fOffset;
        }
        
        memcpy(ptr, vf->fBuffer + vf->fOffset, count);
        vf->fOffset += count;
        
        return count;
    }
    
    static sf_count_t vfwrite(const void* ptr, sf_count_t count, void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        
        /*
         **	This will break badly for files over 2Gig in length, but
         **	is sufficient for testing.
         */
        if (vf->fOffset >= SIGNED_SIZEOF(vf->fBuffer)) {
            return 0;
        }
        
        if (vf->fOffset + count > SIGNED_SIZEOF(vf->fBuffer)) {
            count = sizeof (vf->fBuffer) - vf->fOffset;
        }
        
        memcpy(vf->fBuffer + vf->fOffset, ptr, (size_t)count);
        vf->fOffset += count;
        
        if (vf->fOffset > vf->fLength) {
            vf->fLength = vf->fOffset;
        }
        
        return count;
    }
    
    static sf_count_t vftell(void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        return vf->fOffset;
    }
 
};

struct LibsndfileReader : public SoundfileReader {
	
    LibsndfileReader() {}
	
    typedef sf_count_t (* sample_read)(SNDFILE* sndfile, FAUSTFLOAT* ptr, sf_count_t frames);
	
    // Check file
    bool checkFile(const std::string& path_name)
    {
        SF_INFO snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        return checkFileAux(snd_file, path_name);
    }
    
    bool checkFile(unsigned char* buffer, size_t length)
    {
        SF_INFO snd_info;
        snd_info.format = 0;
        VFLibsndfile vio(buffer, length);
        SNDFILE* snd_file = sf_open_virtual(&vio.fVIO, SFM_READ, &snd_info, &vio);
        return checkFileAux(snd_file, "virtual file");
    }
    
    bool checkFileAux(SNDFILE* snd_file, const std::string& path_name)
    {
        if (snd_file) {
            sf_close(snd_file);
            return true;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name << "' (" << sf_strerror(NULL) << ")" << std::endl;
            return false;
        }
    }

    // Open the file and returns its length and channels
    void getParamsFile(const std::string& path_name, int& channels, int& length)
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        getParamsFileAux(snd_file, snd_info, channels, length);
    }
    
    void getParamsFile(unsigned char* buffer, size_t size, int& channels, int& length)
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        VFLibsndfile vio(buffer, size);
        SNDFILE* snd_file = sf_open_virtual(&vio.fVIO, SFM_READ, &snd_info, &vio);
        getParamsFileAux(snd_file, snd_info, channels, length);
    }
    
    void getParamsFileAux(SNDFILE* snd_file, const SF_INFO& snd_info, int& channels, int& length)
    {
        assert(snd_file);
        channels = int(snd_info.channels);
    #ifdef SAMPLERATE
        length = (isResampling(snd_info.samplerate)) ? ((double(snd_info.frames) * double(fDriverSR) / double(snd_info.samplerate)) + BUFFER_SIZE) : int(snd_info.frames);
    #else
        length = int(snd_info.frames);
    #endif
        sf_close(snd_file);
    }
    
    // Read the file
    void copyToOut(Soundfile* soundfile, int size, int channels, int max_channels, int offset, FAUSTFLOAT* buffer)
    {
        for (int sample = 0; sample < size; sample++) {
            for (int chan = 0; chan < channels; chan++) {
                soundfile->fBuffers[chan][offset + sample] = buffer[sample * max_channels + chan];
            }
        }
    }
    
    void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan)
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        readFileAux(soundfile, snd_file, snd_info, part, offset, max_chan);
    }
    
    void readFile(Soundfile* soundfile, unsigned char* buffer, size_t length, int part, int& offset, int max_chan)
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        VFLibsndfile vio(buffer, length);
        SNDFILE* snd_file = sf_open_virtual(&vio.fVIO, SFM_READ, &snd_info, &vio);
        readFileAux(soundfile, snd_file, snd_info, part, offset, max_chan);
    }
	
    // Will be called to fill all parts from 0 to MAX_SOUNDFILE_PARTS-1
    void readFileAux(Soundfile* soundfile, SNDFILE* snd_file, const SF_INFO& snd_info, int part, int& offset, int max_chan)
    {
        assert(snd_file);
        int channels = std::min<int>(max_chan, snd_info.channels);
    #ifdef SAMPLERATE
        if (isResampling(snd_info.samplerate)) {
            soundfile->fLength[part] = int(double(snd_info.frames) * double(fDriverSR) / double(snd_info.samplerate));
            soundfile->fSR[part] = fDriverSR;
        } else {
            soundfile->fLength[part] = int(snd_info.frames);
            soundfile->fSR[part] = snd_info.samplerate;
        }
    #else
        soundfile->fLength[part] = int(snd_info.frames);
        soundfile->fSR[part] = snd_info.samplerate;
    #endif
        soundfile->fOffset[part] = offset;
		
        // Read and fill snd_info.channels number of channels
        sf_count_t nbf;
        FAUSTFLOAT* buffer_in = (FAUSTFLOAT*)alloca(BUFFER_SIZE * sizeof(FAUSTFLOAT) * snd_info.channels);
        sample_read reader;
        
        if (sizeof(FAUSTFLOAT) == 4) {
            reader = reinterpret_cast<sample_read>(sf_readf_float);
        } else {
            reader = reinterpret_cast<sample_read>(sf_readf_double);
        }
        
    #ifdef SAMPLERATE
        // Resampling
        SRC_STATE* resampler = nullptr;
        FAUSTFLOAT* buffer_out = nullptr;
        if  (isResampling(snd_info.samplerate)) {
            int error;
            resampler = src_new(SRC_SINC_FASTEST, channels, &error);
            if (error != 0) {
                std::cerr << "ERROR : src_new " << src_strerror(error) << std::endl;
                throw -1;
            }
            buffer_out = (FAUSTFLOAT*)alloca(BUFFER_SIZE * sizeof(FAUSTFLOAT) * snd_info.channels);
        }
    #endif
        
        do {
            nbf = reader(snd_file, buffer_in, BUFFER_SIZE);
        #ifdef SAMPLERATE
            // Resampling
            if  (isResampling(snd_info.samplerate)) {
                int in_offset = 0;
                SRC_DATA src_data;
                src_data.src_ratio = double(fDriverSR)/double(snd_info.samplerate);
                do {
                    src_data.data_in = &buffer_in[in_offset * snd_info.channels];
                    src_data.data_out = buffer_out;
                    src_data.input_frames = nbf - in_offset;
                    src_data.output_frames = BUFFER_SIZE;
                    src_data.end_of_input = (nbf < BUFFER_SIZE);
                    int res = src_process(resampler, &src_data);
                    if (res != 0) {
                        std::cerr << "ERROR : src_process " << src_strerror(res) << std::endl;
                        throw -1;
                    }
                    copyToOut(soundfile, src_data.output_frames_gen, channels, snd_info.channels, offset, buffer_out);
                    in_offset += src_data.input_frames_used;
                    // Update offset
                    offset += src_data.output_frames_gen;
                } while (in_offset < nbf);
            } else {
                copyToOut(soundfile, nbf, channels, snd_info.channels, offset, buffer_in);
                // Update offset
                offset += nbf;
            }
        #else
            copyToOut(soundfile, nbf, channels, snd_info.channels, offset, buffer_in);
            // Update offset
            offset += nbf;
        #endif
        } while (nbf == BUFFER_SIZE);
		
        sf_close(snd_file);
    #ifdef SAMPLERATE
        if (resampler) src_delete(resampler);
    #endif
    }

};

#endif
/**************************  END  LibsndfileReader.h **************************/
LibsndfileReader gReader;
#endif

// To be used by DSP code if no SoundUI is used
std::vector<std::string> path_name_list;
Soundfile* defaultsound = gReader.createSoundfile(path_name_list, MAX_CHAN);

class SoundUI : public GenericUI
{
		
    private:
    
        std::vector<std::string> fSoundfileDir;             // The soundfile directories
        std::map<std::string, Soundfile*> fSoundfileMap;    // Map to share loaded soundfiles
        SoundfileReader* fSoundReader;

     public:
    
        SoundUI(const std::string& sound_directory = "", int sample_rate = -1, SoundfileReader* reader = nullptr)
        {
            fSoundfileDir.push_back(sound_directory);
            fSoundReader = (reader) ? reader : &gReader;
            fSoundReader->setSampleRate(sample_rate);
        }
    
        SoundUI(const std::vector<std::string>& sound_directories, int sample_rate = -1, SoundfileReader* reader = nullptr)
        :fSoundfileDir(sound_directories)
        {
            fSoundReader = (reader) ? reader : &gReader;
            fSoundReader->setSampleRate(sample_rate);
        }
    
        virtual ~SoundUI()
        {   
            // Delete all soundfiles
            std::map<std::string, Soundfile*>::iterator it;
            for (it = fSoundfileMap.begin(); it != fSoundfileMap.end(); it++) {
                delete (*it).second;
            }
        }

        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* url, Soundfile** sf_zone)
        {
            const char* saved_url = url; // 'url' is consumed by parseMenuList2
            std::vector<std::string> file_name_list;
            
            bool menu = parseMenuList2(url, file_name_list, true);
            // If not a list, we have as single file
            if (!menu) { file_name_list.push_back(saved_url); }
            
            // Parse the possible list
            if (fSoundfileMap.find(saved_url) == fSoundfileMap.end()) {
                // Check all files and get their complete path
                std::vector<std::string> path_name_list = fSoundReader->checkFiles(fSoundfileDir, file_name_list);
                // Read them and create the Soundfile
                Soundfile* sound_file = fSoundReader->createSoundfile(path_name_list, MAX_CHAN);
                if (sound_file) {
                    fSoundfileMap[saved_url] = sound_file;
                } else {
                    // If failure, use 'defaultsound'
                    std::cerr << "addSoundfile : soundfile for " << saved_url << " cannot be created !" << std::endl;
                    *sf_zone = defaultsound;
                    return;
                }
            }
            
            // Get the soundfile
            *sf_zone = fSoundfileMap[saved_url];
        }
    
        static std::string getBinaryPath(std::string folder = "")
        {
            std::string bundle_path_str;
        #ifdef __APPLE__
            CFURLRef bundle_ref = CFBundleCopyBundleURL(CFBundleGetMainBundle());
            if (bundle_ref) {
                UInt8 bundle_path[512];
                if (CFURLGetFileSystemRepresentation(bundle_ref, true, bundle_path, 512)) {
                    bundle_path_str = std::string((char*)bundle_path) + folder;
                }
            }
        #endif
        #ifdef ANDROID_DRIVER
            bundle_path_str = "/data/data/__CURRENT_ANDROID_PACKAGE__/files";
        #endif
            return bundle_path_str;
        }
        
        static std::string getBinaryPathFrom(const std::string& path)
        {
            std::string bundle_path_str;
        #ifdef __APPLE__
            CFBundleRef bundle = CFBundleGetBundleWithIdentifier(CFStringCreateWithCString(kCFAllocatorDefault, path.c_str(), CFStringGetSystemEncoding()));
            CFURLRef bundle_ref = CFBundleCopyBundleURL(bundle);
            if (bundle_ref) {
                UInt8 bundle_path[512];
                if (CFURLGetFileSystemRepresentation(bundle_ref, true, bundle_path, 512)) {
                    bundle_path_str = std::string((char*)bundle_path);
                }
            }
        #endif
        #ifdef ANDROID_DRIVER
            bundle_path_str = "/data/data/__CURRENT_ANDROID_PACKAGE__/files";
        #endif
            return bundle_path_str;
        }
};

#endif
/**************************  END  SoundUI.h **************************/
#endif

// Always include this file, otherwise -nvoices only mode does not compile....
/************************** BEGIN MidiUI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_MIDIUI_H
#define FAUST_MIDIUI_H

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <cstdlib>
#include <cmath>

/************************** BEGIN MapUI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#include <vector>
#include <map>
#include <string>


/*******************************************************************************
 * MapUI : Faust User Interface
 * This class creates a map of complete hierarchical path and zones for each UI items.
 ******************************************************************************/

class MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Complete path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
    public:
        
        MapUI() {};
        virtual ~MapUI() {};
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            pushLabel(label);
        }
        void openHorizontalBox(const char* label)
        {
            pushLabel(label);
        }
        void openVerticalBox(const char* label)
        {
            pushLabel(label);
        }
        void closeBox()
        {
            popLabel();
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
        
        // -- metadata declarations
        void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
        
        // set/get
        void setParamValue(const std::string& path, FAUSTFLOAT value)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                *fPathZoneMap[path] = value;
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                *fLabelZoneMap[path] = value;
            }
        }
        
        FAUSTFLOAT getParamValue(const std::string& path)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                return *fPathZoneMap[path];
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[path];
            } else {
                return FAUSTFLOAT(0);
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getMap() { return fPathZoneMap; }
        
        int getParamsCount() { return int(fPathZoneMap.size()); }
        
        std::string getParamAddress(int index)
        { 
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            while (index-- > 0 && it++ != fPathZoneMap.end()) {}
            return (*it).first;
        }
    
        std::string getParamAddress(FAUSTFLOAT* zone)
        {
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            do {
                if ((*it).second == zone) return (*it).first;
            }
            while (it++ != fPathZoneMap.end());
            return "";
        }
    
        static bool endsWith(std::string const& str, std::string const& end)
        {
            size_t l1 = str.length();
            size_t l2 = end.length();
            return (l1 >= l2) && (0 == str.compare(l1 - l2, l2, end));
        }
};


#endif // FAUST_MAPUI_H
/**************************  END  MapUI.h **************************/
/************************** BEGIN midi.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __midi__
#define __midi__

#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>

class MapUI;

/*************************************
 A time-stamped short MIDI message
**************************************/

#pragma pack (push, 1)
struct MIDIMessage
{
    uint32_t frameIndex;
    uint8_t byte0, byte1, byte2;
};
#pragma pack (pop)

/*******************************************************************************
 * MIDI processor definition.
 *
 * MIDI input or output handling classes will implement this interface,
 * so the same method names (keyOn, ctrlChange...) will be used either
 * when decoding MIDI input or encoding MIDI output events.
 *******************************************************************************/

class midi {

    public:

        midi() {}
        virtual ~midi() {}

        // Additional time-stamped API for MIDI input
        virtual MapUI* keyOn(double, int channel, int pitch, int velocity)
        {
            return keyOn(channel, pitch, velocity);
        }
        
        virtual void keyOff(double, int channel, int pitch, int velocity = 127)
        {
            keyOff(channel, pitch, velocity);
        }
    
        virtual void keyPress(double, int channel, int pitch, int press)
        {
            keyPress(channel, pitch, press);
        }
        
        virtual void chanPress(double date, int channel, int press)
        {
            chanPress(channel, press);
        }
    
        virtual void pitchWheel(double, int channel, int wheel)
        {
            pitchWheel(channel, wheel);
        }
           
        virtual void ctrlChange(double, int channel, int ctrl, int value)
        {
            ctrlChange(channel, ctrl, value);
        }
    
        virtual void ctrlChange14bits(double, int channel, int ctrl, int value)
        {
            ctrlChange14bits(channel, ctrl, value);
        }

        virtual void progChange(double, int channel, int pgm)
        {
            progChange(channel, pgm);
        }
    
        virtual void sysEx(double, std::vector<unsigned char>& message)
        {
            sysEx(message);
        }

        // MIDI sync
        virtual void startSync(double date)  {}
        virtual void stopSync(double date)   {}
        virtual void clock(double date)  {}

        // Standard MIDI API
        virtual MapUI* keyOn(int channel, int pitch, int velocity)      { return 0; }
        virtual void keyOff(int channel, int pitch, int velocity)       {}
        virtual void keyPress(int channel, int pitch, int press)        {}
        virtual void chanPress(int channel, int press)                  {}
        virtual void ctrlChange(int channel, int ctrl, int value)       {}
        virtual void ctrlChange14bits(int channel, int ctrl, int value) {}
        virtual void pitchWheel(int channel, int wheel)                 {}
        virtual void progChange(int channel, int pgm)                   {}
        virtual void sysEx(std::vector<unsigned char>& message)         {}

        enum MidiStatus {

            // channel voice messages
            MIDI_NOTE_OFF = 0x80,
            MIDI_NOTE_ON = 0x90,
            MIDI_CONTROL_CHANGE = 0xB0,
            MIDI_PROGRAM_CHANGE = 0xC0,
            MIDI_PITCH_BEND = 0xE0,
            MIDI_AFTERTOUCH = 0xD0,         // aka channel pressure
            MIDI_POLY_AFTERTOUCH = 0xA0,    // aka key pressure
            MIDI_CLOCK = 0xF8,
            MIDI_START = 0xFA,
            MIDI_CONT = 0xFB,
            MIDI_STOP = 0xFC,
            MIDI_SYSEX_START = 0xF0,
            MIDI_SYSEX_STOP = 0xF7

        };

        enum MidiCtrl {

            ALL_NOTES_OFF = 123,
            ALL_SOUND_OFF = 120

        };
};

/****************************************************
 * Base class for MIDI input handling.
 *
 * Shared common code used for input handling:
 * - decoding Real-Time messages: handleSync
 * - decoding one data byte messages: handleData1
 * - decoding two data byte messages: handleData2
 * - getting ready messages in polling mode
 ****************************************************/

class midi_handler : public midi {

    protected:

        std::vector<midi*> fMidiInputs;
        std::string fName;
    
        int range(int min, int max, int val) { return (val < min) ? min : ((val >= max) ? max : val); }
  
    public:

        midi_handler(const std::string& name = "MIDIHandler"):fName(name) {}
        virtual ~midi_handler() {}

        void addMidiIn(midi* midi_dsp) { if (midi_dsp) fMidiInputs.push_back(midi_dsp); }
        void removeMidiIn(midi* midi_dsp)
        {
            std::vector<midi*>::iterator it = std::find(fMidiInputs.begin(), fMidiInputs.end(), midi_dsp);
            if (it != fMidiInputs.end()) {
                fMidiInputs.erase(it);
            }
        }

        virtual bool startMidi() { return true; }
        virtual void stopMidi() {}
    
        void setName(const std::string& name) { fName = name; }
        std::string getName() { return fName; }
    
        // To be used in polling mode
        virtual int getMessages(std::vector<MIDIMessage>* message) { return 0; }
    
        void handleSync(double time, int type)
        {
            if (type == MIDI_CLOCK) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->clock(time);
                }
            } else if (type == MIDI_START) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->startSync(time);
                }
            } else if (type == MIDI_STOP) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->stopSync(time);
                }
            }
        }

        void handleData1(double time, int type, int channel, int data1)
        {
            if (type == MIDI_PROGRAM_CHANGE) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->progChange(time, channel, data1);
                }
            } else if (type == MIDI_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->chanPress(time, channel, data1);
                }
            }
        }

        void handleData2(double time, int type, int channel, int data1, int data2)
        {
            if (type == MIDI_NOTE_OFF || ((type == MIDI_NOTE_ON) && (data2 == 0))) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOff(time, channel, data1, data2);
                }
            } else if (type == MIDI_NOTE_ON) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOn(time, channel, data1, data2);
                }
            } else if (type == MIDI_CONTROL_CHANGE) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->ctrlChange(time, channel, data1, data2);
                }
            } else if (type == MIDI_PITCH_BEND) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->pitchWheel(time, channel, (data2 << 7) + data1);
                }
            } else if (type == MIDI_POLY_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyPress(time, channel, data1, data2);
                }
            }
        }
    
        void handleMessage(double time, int type, std::vector<unsigned char>& message)
        {
            if (type == MIDI_SYSEX_START) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->sysEx(time, message);
                }
            }
        }

};

//-------------------------------
// For timestamped MIDI messages
//-------------------------------

struct DatedMessage {
    
    double fDate;
    unsigned char fBuffer[3];
    size_t fSize;
    
    DatedMessage(double date, unsigned char* buffer, size_t size)
    :fDate(date), fSize(size)
    {
        assert(size <= 3);
        memcpy(fBuffer, buffer, size);
    }
    
    DatedMessage():fDate(0.0), fSize(0)
    {}
    
};

#endif // __midi__
/**************************  END  midi.h **************************/

#ifdef _MSC_VER
#define gsscanf sscanf_s
#else
#define gsscanf sscanf
#endif

/*****************************************************************************
* Helper code for MIDI meta and polyphonic 'nvoices' parsing
******************************************************************************/

struct MidiMeta : public Meta, public std::map<std::string, std::string>
{
    void declare(const char* key, const char* value)
    {
        (*this)[key] = value;
    }
    
    const std::string get(const char* key, const char* def)
    {
        if (this->find(key) != this->end()) {
            return (*this)[key];
        } else {
            return def;
        }
    }
    
    static void analyse(dsp* mono_dsp, bool& midi_sync, int& nvoices)
    {
        JSONUI jsonui;
        mono_dsp->buildUserInterface(&jsonui);
        std::string json = jsonui.JSON();
        midi_sync = ((json.find("midi") != std::string::npos) &&
                     ((json.find("start") != std::string::npos) ||
                      (json.find("stop") != std::string::npos) ||
                      (json.find("clock") != std::string::npos) ||
                      (json.find("timestamp") != std::string::npos)));
    
    #if defined(NVOICES) && NVOICES!=NUM_VOICES
        nvoices = NVOICES;
    #else
        MidiMeta meta;
        mono_dsp->metadata(&meta);
        bool found_voices = false;
        // If "options" metadata is used
        std::string options = meta.get("options", "");
        if (options != "") {
            std::map<std::string, std::string> metadata;
            std::string res;
            MetaDataUI::extractMetadata(options, res, metadata);
            if (metadata.find("nvoices") != metadata.end()) {
                nvoices = std::atoi(metadata["nvoices"].c_str());
                found_voices = true;
            }
        }
        // Otherwise test for "nvoices" metadata
        if (!found_voices) {
            std::string numVoices = meta.get("nvoices", "0");
            nvoices = std::atoi(numVoices.c_str());
        }
        nvoices = std::max<int>(0, nvoices);
    #endif
    }
    
    static bool checkPolyphony(dsp* mono_dsp)
    {
        MapUI map_ui;
        mono_dsp->buildUserInterface(&map_ui);
        bool has_freq = false;
        bool has_gate = false;
        bool has_gain = false;
        for (int i = 0; i < map_ui.getParamsCount(); i++) {
            std::string path = map_ui.getParamAddress(i);
            has_freq |= MapUI::endsWith(path, "/freq");
            has_gate |= MapUI::endsWith(path, "/gate");
            has_gain |= MapUI::endsWith(path, "/gain");
        }
        return (has_freq && has_gate && has_gain);
    }
    
};

/*******************************************************************************
 * MidiUI : Faust User Interface
 * This class decodes MIDI meta data and maps incoming MIDI messages to them.
 * Currently ctrl, keyon/keyoff, keypress, pgm, chanpress, pitchwheel/pitchbend
 * start/stop/clock meta data is handled.
 ******************************************************************************/

class uiMidi {
    
    protected:
        
        midi* fMidiOut;
        bool fInputCtrl;
        
    public:
        
        uiMidi(midi* midi_out, bool input):fMidiOut(midi_out), fInputCtrl(input)
        {}
        virtual ~uiMidi()
        {}
    
};

/*****************************************************************************
 * Base class for MIDI aware UI items
 ******************************************************************************/

class uiMidiItem : public uiMidi, public uiItem {
    
    public:
        
        uiMidiItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidi(midi_out, input), uiItem(ui, zone)
        {}
        virtual ~uiMidiItem()
        {}
    
        virtual void reflectZone() {}
    
};

/*****************************************************************************
 * Base class for MIDI aware UI items with timestamp support
 ******************************************************************************/

class uiMidiTimedItem : public uiMidi, public uiTimedItem {
    
    public:
        
        uiMidiTimedItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidi(midi_out, input), uiTimedItem(ui, zone)
        {}
        virtual ~uiMidiTimedItem()
        {}
    
        virtual void reflectZone() {}
    
};

//-------------
// MIDI sync
//-------------

class uiMidiStart : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStart(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStart()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->startSync(0);
            }
        }
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(v));
            }
        }
        
};

class uiMidiStop : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStop(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStop()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(1)) {
                fMidiOut->stopSync(0);
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(v));
            }
        }
};

class uiMidiClock : public uiMidiTimedItem
{

    private:
        
        bool fState;
  
    public:
    
        uiMidiClock(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fState(false)
        {}
        virtual ~uiMidiClock()
        {}
    
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->clock(0);
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                fState = !fState;
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fState));
            }
        }

};

//----------------------
// Standard MIDI events
//----------------------

class uiMidiProgChange : public uiMidiTimedItem
{
    
    private:
        
        int fPgm;
  
    public:
    
        uiMidiProgChange(midi* midi_out, int pgm, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fPgm(pgm)
        {}
        virtual ~uiMidiProgChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->progChange(0, fPgm);
            }
        }
        
};

class uiMidiChanPress : public uiMidiTimedItem
{
    private:
        
        int fPress;
  
    public:
    
        uiMidiChanPress(midi* midi_out, int press, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fPress(press)
        {}
        virtual ~uiMidiChanPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->chanPress(0, fPress);
            }
        }
        
};

class uiMidiCtrlChange : public uiMidiTimedItem
{
    private:
    
        int fCtrl;
        LinearValueConverter fConverter;
 
    public:
    
        uiMidiCtrlChange(midi* midi_out, int ctrl, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fCtrl(ctrl), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiCtrlChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->ctrlChange(0, fCtrl, fConverter.faust2ui(v));
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
 
};

class uiMidiPitchWheel : public uiMidiTimedItem
{

    private:
    	
		// currently, the range is of pitchwheel if fixed (-2/2 semitones)
        FAUSTFLOAT wheel2bend(float v)
        {
            return std::pow(2.0,(v/16383.0*4-2)/12);
        }

        int bend2wheel(float v)
        {
            return (int)((12*std::log(v)/std::log(2.0)+2)/4*16383);
        }
 
    public:
    
        uiMidiPitchWheel(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiPitchWheel()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->pitchWheel(0, bend2wheel(v));
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(wheel2bend(v));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, wheel2bend(v));
            }
        }
 
};

class uiMidiKeyOn : public uiMidiTimedItem
{

    private:
        
        int fKeyOn;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOn(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fKeyOn(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOn()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOn(0, fKeyOn, fConverter.faust2ui(v));
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
};

class uiMidiKeyOff : public uiMidiTimedItem
{

    private:
        
        int fKeyOff;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOff(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fKeyOff(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOff()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOff(0, fKeyOff, fConverter.faust2ui(v));
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
};

class uiMidiKeyPress : public uiMidiTimedItem
{

    private:
    
        int fKey;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyPress(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fKey(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyPress(0, fKey, fConverter.faust2ui(v));
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
};

class MapUI;

/******************************************************************************************
 * MidiUI : Faust User Interface
 * This class decodes MIDI metadata and maps incoming MIDI messages to them.
 * Currently ctrl, keyon/keyoff, keypress, pgm, chanpress, pitchwheel/pitchbend
 * start/stop/clock meta data are handled.
 *
 * Maps associating MIDI event ID (like each ctrl number) with all MIDI aware UI items
 * are defined and progressively filled when decoding MIDI related metadata.
 * MIDI aware UI items are used in both directions:
 *  - modifying their internal state when receving MIDI input events
 *  - sending their internal state as MIDI output events
 *******************************************************************************************/

class MidiUI : public GUI, public midi
{

    protected:
    
        std::map <int, std::vector<uiMidiCtrlChange*> > fCtrlChangeTable;
        std::map <int, std::vector<uiMidiProgChange*> > fProgChangeTable;
        std::map <int, std::vector<uiMidiChanPress*> >  fChanPressTable;
        std::map <int, std::vector<uiMidiKeyOn*> >      fKeyOnTable;
        std::map <int, std::vector<uiMidiKeyOff*> >     fKeyOffTable;
        std::map <int, std::vector<uiMidiKeyOn*> >      fKeyTable;
        std::map <int, std::vector<uiMidiKeyPress*> >   fKeyPressTable;
        std::vector<uiMidiPitchWheel*>                  fPitchWheelTable;
        
        std::vector<uiMidiStart*>   fStartTable;
        std::vector<uiMidiStop*>    fStopTable;
        std::vector<uiMidiClock*>   fClockTable;
        
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        
        midi_handler* fMidiHandler;
        bool fDelete;
        bool fTimeStamp;
    
        void addGenericZone(FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
        {
            if (fMetaAux.size() > 0) {
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    unsigned num;
                    if (fMetaAux[i].first == "midi") {
                        if (gsscanf(fMetaAux[i].second.c_str(), "ctrl %u", &num) == 1) {
                            fCtrlChangeTable[num].push_back(new uiMidiCtrlChange(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyon %u", &num) == 1) {
                            fKeyOnTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyoff %u", &num) == 1) {
                            fKeyOffTable[num].push_back(new uiMidiKeyOff(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "key %u", &num) == 1) {
                            fKeyTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keypress %u", &num) == 1) {
                            fKeyPressTable[num].push_back(new uiMidiKeyPress(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "pgm %u", &num) == 1) {
                            fProgChangeTable[num].push_back(new uiMidiProgChange(fMidiHandler, num, this, zone, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "chanpress %u", &num) == 1) {
                            fChanPressTable[num].push_back(new uiMidiChanPress(fMidiHandler, num, this, zone, input));
                        } else if (fMetaAux[i].second == "pitchwheel" || fMetaAux[i].second == "pitchbend") {
                            fPitchWheelTable.push_back(new uiMidiPitchWheel(fMidiHandler, this, zone, input));
                        // MIDI sync
                        } else if (fMetaAux[i].second == "start") {
                            fStartTable.push_back(new uiMidiStart(fMidiHandler, this, zone, input));
                        } else if (fMetaAux[i].second == "stop") {
                            fStopTable.push_back(new uiMidiStop(fMidiHandler, this, zone, input));
                        } else if (fMetaAux[i].second == "clock") {
                            fClockTable.push_back(new uiMidiClock(fMidiHandler, this, zone, input));
                        // Explicit metadata to activate 'timestamp' mode
                        } else if (fMetaAux[i].second == "timestamp") {
                            fTimeStamp = true;
                        }
                    }
                }
            }
            fMetaAux.clear();
        }

    public:
    
        MidiUI():fMidiHandler(NULL), fDelete(false), fTimeStamp(false)
        {}

        MidiUI(midi_handler* midi_handler, bool delete_handler = false)
        {
            fMidiHandler = midi_handler;
            fMidiHandler->addMidiIn(this);
            fDelete = delete_handler;
            fTimeStamp = false;
        }
 
        virtual ~MidiUI() 
        { 
            fMidiHandler->removeMidiIn(this);
            if (fDelete) delete fMidiHandler;
        }
        
        bool run() { return fMidiHandler->startMidi(); }
        void stop() { fMidiHandler->stopMidi(); }
        
        void addMidiIn(midi* midi_dsp) { fMidiHandler->addMidiIn(midi_dsp); }
        void removeMidiIn(midi* midi_dsp) { fMidiHandler->removeMidiIn(midi_dsp); }
      
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            addGenericZone(zone, min, max, false);
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addGenericZone(zone, min, max, false);
        }

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
        
        // -- MIDI API 
        
        MapUI* keyOn(double date, int channel, int note, int velocity)
        {
            if (fKeyOnTable.find(note) != fKeyOnTable.end()) {
                if (fTimeStamp) {
                    for (unsigned int i = 0; i < fKeyOnTable[note].size(); i++) {
                        fKeyOnTable[note][i]->modifyZone(date, FAUSTFLOAT(velocity));
                    }
                } else {
                    for (unsigned int i = 0; i < fKeyOnTable[note].size(); i++) {
                        fKeyOnTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                    }
                }
            }
            // If note is in fKeyTable, handle it as a keyOn
            if (fKeyTable.find(note) != fKeyTable.end()) {
                if (fTimeStamp) {
                    for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                        fKeyTable[note][i]->modifyZone(date, FAUSTFLOAT(velocity));
                    }
                } else {
                    for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                        fKeyTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                    }
                }
            }
            return 0;
        }
        
        void keyOff(double date, int channel, int note, int velocity)
        {
            if (fKeyOffTable.find(note) != fKeyOffTable.end()) {
                if (fTimeStamp) {
                    for (unsigned int i = 0; i < fKeyOffTable[note].size(); i++) {
                        fKeyOffTable[note][i]->modifyZone(date, FAUSTFLOAT(velocity));
                    }
                } else {
                    for (unsigned int i = 0; i < fKeyOffTable[note].size(); i++) {
                        fKeyOffTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                    }
                }
            }
            // If note is in fKeyTable, handle it as a keyOff with a 0 velocity
            if (fKeyTable.find(note) != fKeyTable.end()) {
                if (fTimeStamp) {
                    for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                        fKeyTable[note][i]->modifyZone(date, 0);
                    }
                } else {
                    for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                        fKeyTable[note][i]->modifyZone(0);
                    }
                }
            }
        }
           
        void ctrlChange(double date, int channel, int ctrl, int value)
        {
            if (fCtrlChangeTable.find(ctrl) != fCtrlChangeTable.end()) {
                if (fTimeStamp) {
                    for (unsigned int i = 0; i < fCtrlChangeTable[ctrl].size(); i++) {
                        fCtrlChangeTable[ctrl][i]->modifyZone(date, FAUSTFLOAT(value));
                    }
                } else {
                    for (unsigned int i = 0; i < fCtrlChangeTable[ctrl].size(); i++) {
                        fCtrlChangeTable[ctrl][i]->modifyZone(FAUSTFLOAT(value));
                    }
                }
            }
        }
        
        void progChange(double date, int channel, int pgm)
        {
            if (fProgChangeTable.find(pgm) != fProgChangeTable.end()) {
                if (fTimeStamp) {
                    for (unsigned int i = 0; i < fProgChangeTable[pgm].size(); i++) {
                        fProgChangeTable[pgm][i]->modifyZone(date, FAUSTFLOAT(1));
                    }
                } else {
                    for (unsigned int i = 0; i < fProgChangeTable[pgm].size(); i++) {
                        fProgChangeTable[pgm][i]->modifyZone(FAUSTFLOAT(1));
                    }
                }
            }
        }
        
        void pitchWheel(double date, int channel, int wheel) 
        {
            if (fTimeStamp) {
                for (unsigned int i = 0; i < fPitchWheelTable.size(); i++) {
                    fPitchWheelTable[i]->modifyZone(date, FAUSTFLOAT(wheel));
                }
            } else {
                for (unsigned int i = 0; i < fPitchWheelTable.size(); i++) {
                    fPitchWheelTable[i]->modifyZone(FAUSTFLOAT(wheel));
                }
            }
        }
        
        void keyPress(double date, int channel, int pitch, int press) 
        {
            if (fKeyPressTable.find(pitch) != fKeyPressTable.end()) {
                if (fTimeStamp) {
                    for (unsigned int i = 0; i < fKeyPressTable[pitch].size(); i++) {
                        fKeyPressTable[pitch][i]->modifyZone(date, FAUSTFLOAT(press));
                    }
                } else {
                    for (unsigned int i = 0; i < fKeyPressTable[pitch].size(); i++) {
                        fKeyPressTable[pitch][i]->modifyZone(FAUSTFLOAT(press));
                    }
                }
            }
        }
        
        void chanPress(double date, int channel, int press)
        {
            if (fChanPressTable.find(press) != fChanPressTable.end()) {
                if (fTimeStamp) {
                    for (unsigned int i = 0; i < fChanPressTable[press].size(); i++) {
                        fChanPressTable[press][i]->modifyZone(date, FAUSTFLOAT(1));
                    }
                } else {
                    for (unsigned int i = 0; i < fChanPressTable[press].size(); i++) {
                        fChanPressTable[press][i]->modifyZone(FAUSTFLOAT(1));
                    }
                }
            } 
        }
        
        void ctrlChange14bits(double date, int channel, int ctrl, int value) {}
        
        // MIDI sync
        
        void startSync(double date)
        {
            for (unsigned int i = 0; i < fStartTable.size(); i++) {
                fStartTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
        
        void stopSync(double date)
        {
            for (unsigned int i = 0; i < fStopTable.size(); i++) {
                fStopTable[i]->modifyZone(date, FAUSTFLOAT(0));
            }
        }
        
        void clock(double date)
        {
            for (unsigned int i = 0; i < fClockTable.size(); i++) {
                fClockTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
};

#endif // FAUST_MIDIUI_H
/**************************  END  MidiUI.h **************************/

#ifdef MIDICTRL
/************************** BEGIN rt-midi.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __rt_midi__
#define __rt_midi__ 
 
#include <iostream>
#include <cstdlib>
/************************** BEGIN RtMidi.h **************************/
/*
 File: CAHostTimeBase.h
 Abstract: Part of CoreAudio Utility Classes
 Version: 1.0.3
 
 Disclaimer: IMPORTANT:  This Apple software is supplied to you by Apple
 Inc. ("Apple") in consideration of your agreement to the following
 terms, and your use, installation, modification or redistribution of
 this Apple software constitutes acceptance of these terms.  If you do
 not agree with these terms, please do not use, install, modify or
 redistribute this Apple software.
 
 In consideration of your agreement to abide by the following terms, and
 subject to these terms, Apple grants you a personal, non-exclusive
 license, under Apple's copyrights in this original Apple software (the
 "Apple Software"), to use, reproduce, modify and redistribute the Apple
 Software, with or without modifications, in source and/or binary forms;
 provided that if you redistribute the Apple Software in its entirety and
 without modifications, you must retain this notice and the following
 text and disclaimers in all such redistributions of the Apple Software.
 Neither the name, trademarks, service marks or logos of Apple Inc. may
 be used to endorse or promote products derived from the Apple Software
 without specific prior written permission from Apple.  Except as
 expressly stated in this notice, no other rights or licenses, express or
 implied, are granted by Apple herein, including but not limited to any
 patent rights that may be infringed by your derivative works or by other
 works in which the Apple Software may be incorporated.
 
 The Apple Software is provided by Apple on an "AS IS" basis.  APPLE
 MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION
 THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS
 FOR A PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND
 OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS.
 
 IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL
 OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION) ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION,
 MODIFICATION AND/OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED
 AND WHETHER UNDER THEORY OF CONTRACT, TORT (INCLUDING NEGLIGENCE),
 STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
 
 Copyright (C) 2013 Apple Inc. All Rights Reserved.
 */

#if !defined(__CAHostTimeBase_h__)
#define __CAHostTimeBase_h__

#ifdef __APPLE__

//=============================================================================
//	Includes
//=============================================================================

#if !defined(__COREAUDIO_USE_FLAT_INCLUDES__)
#include <CoreAudio/CoreAudioTypes.h>
#else
#include <CoreAudioTypes.h>
#endif

#if TARGET_OS_MAC
#include <mach/mach_time.h>
#elif TARGET_OS_WIN32
#include <windows.h>
#else
#error	Unsupported operating system
#endif

//=============================================================================
//	CAHostTimeBase
//
//	This class provides platform independent access to the host's time base.
//=============================================================================

class CAHostTimeBase
{
    
public:
    static UInt64	ConvertToNanos(UInt64 inHostTime);
    static UInt64	ConvertFromNanos(UInt64 inNanos);
    
    static UInt64	GetTheCurrentTime();
#if TARGET_OS_MAC
    static UInt64	GetCurrentTime() { return GetTheCurrentTime(); }
#endif
    static UInt64	GetCurrentTimeInNanos();
    
    static Float64	GetFrequency() { if(!sIsInited) { Initialize(); } return sFrequency; }
    static Float64	GetInverseFrequency() { if(!sIsInited) { Initialize(); } return sInverseFrequency; }
    static UInt32	GetMinimumDelta() { if(!sIsInited) { Initialize(); } return sMinDelta; }
    
    static UInt64	AbsoluteHostDeltaToNanos(UInt64 inStartTime, UInt64 inEndTime);
    static SInt64	HostDeltaToNanos(UInt64 inStartTime, UInt64 inEndTime);
    
    static void     Initialize();
    
private:
    
    static bool sIsInited;
    
    static Float64 sFrequency;
    static Float64 sInverseFrequency;
    static UInt32 sMinDelta;
    static UInt32 sToNanosNumerator;
    static UInt32 sToNanosDenominator;
    static UInt32 sFromNanosNumerator;
    static UInt32 sFromNanosDenominator;
    static bool sUseMicroseconds;
#if Track_Host_TimeBase
    static UInt64	sLastTime;
#endif
};

inline UInt64 CAHostTimeBase::GetTheCurrentTime()
{
    UInt64 theTime = 0;
    
#if TARGET_OS_MAC
    theTime = mach_absolute_time();
    
#elif TARGET_OS_WIN32
    LARGE_INTEGER theValue;
    QueryPerformanceCounter(&theValue);
    theTime = *((UInt64*)&theValue);
#endif
    
#if	Track_Host_TimeBase
    if(sLastTime != 0)
    {
        if(theTime <= sLastTime)
        {
            DebugMessageN2("CAHostTimeBase::GetTheCurrentTime: the current time is earlier than the last time, now: %qd, then: %qd", theTime, sLastTime);
        }
        sLastTime = theTime;
    }
    else
    {
        sLastTime = theTime;
    }
#endif
    
    return theTime;
}

inline UInt64 CAHostTimeBase::ConvertToNanos(UInt64 inHostTime)
{
    if(!sIsInited)
    {
        Initialize();
    }
    
    Float64 theNumerator = static_cast<Float64>(sToNanosNumerator);
    Float64 theDenominator = static_cast<Float64>(sToNanosDenominator);
    Float64 theHostTime = static_cast<Float64>(inHostTime);
    
    Float64 thePartialAnswer = theHostTime / theDenominator;
    Float64 theFloatAnswer = thePartialAnswer * theNumerator;
    UInt64 theAnswer = static_cast<UInt64>(theFloatAnswer);
    
    return theAnswer;
}

inline UInt64 CAHostTimeBase::ConvertFromNanos(UInt64 inNanos)
{
    if(!sIsInited)
    {
        Initialize();
    }
    
    Float64 theNumerator = static_cast<Float64>(sToNanosNumerator);
    Float64 theDenominator = static_cast<Float64>(sToNanosDenominator);
    Float64 theNanos = static_cast<Float64>(inNanos);
    
    Float64 thePartialAnswer = theNanos / theNumerator;
    Float64 theFloatAnswer = thePartialAnswer * theDenominator;
    UInt64 theAnswer = static_cast<UInt64>(theFloatAnswer);
    
    return theAnswer;
}

inline UInt64 CAHostTimeBase::GetCurrentTimeInNanos()
{
    return ConvertToNanos(GetTheCurrentTime());
}

inline UInt64 CAHostTimeBase::AbsoluteHostDeltaToNanos(UInt64 inStartTime, UInt64 inEndTime)
{
    UInt64 theAnswer;
    
    if(inStartTime <= inEndTime)
    {
        theAnswer = inEndTime - inStartTime;
    }
    else
    {
        theAnswer = inStartTime - inEndTime;
    }
    
    return ConvertToNanos(theAnswer);
}

inline SInt64 CAHostTimeBase::HostDeltaToNanos(UInt64 inStartTime, UInt64 inEndTime)
{
    SInt64 theAnswer;
    SInt64 theSign = 1;
    
    if(inStartTime <= inEndTime)
    {
        theAnswer = inEndTime - inStartTime;
    }
    else
    {
        theAnswer = inStartTime - inEndTime;
        theSign = -1;
    }
    
    return theSign * ConvertToNanos(theAnswer);
}

#endif // __APPLE__

#endif

/**********************************************************************/
/*! \class RtMidi
    \brief An abstract base class for realtime MIDI input/output.

    This class implements some common functionality for the realtime
    MIDI input/output subclasses RtMidiIn and RtMidiOut.

    RtMidi WWW site: http://music.mcgill.ca/~gary/rtmidi/

    RtMidi: realtime MIDI i/o C++ classes
    Copyright (c) 2003-2017 Gary P. Scavone

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation files
    (the "Software"), to deal in the Software without restriction,
    including without limitation the rights to use, copy, modify, merge,
    publish, distribute, sublicense, and/or sell copies of the Software,
    and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    Any person wishing to distribute modifications to the Software is
    asked to send the modifications to the original developer so that
    they can be incorporated into the canonical version.  This is,
    however, not a binding provision of this license.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
    ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
    CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
/**********************************************************************/

/*!
  \file RtMidi.h
 */

#ifndef RTMIDI_H
#define RTMIDI_H

#define RTMIDI_VERSION "3.0.0"

#include <exception>
#include <iostream>
#include <string>
#include <vector>

#if __APPLE__
#define __MACOSX_CORE__ 1
//#define __UNIX_JACK__ 1
#endif

#if __linux__
#define __LINUX_ALSA__ 1
#endif

#if _WIN32
#define __WINDOWS_MM__ 1
#endif


/************************************************************************/
/*! \class RtMidiError
    \brief Exception handling class for RtMidi.

    The RtMidiError class is quite simple but it does allow errors to be
    "caught" by RtMidiError::Type. See the RtMidi documentation to know
    which methods can throw an RtMidiError.
*/
/************************************************************************/

class RtMidiError : public std::exception
{
 public:
  //! Defined RtMidiError types.
  enum Type {
    WARNING,           /*!< A non-critical error. */
    DEBUG_WARNING,     /*!< A non-critical error which might be useful for debugging. */
    UNSPECIFIED,       /*!< The default, unspecified error type. */
    NO_DEVICES_FOUND,  /*!< No devices found on system. */
    INVALID_DEVICE,    /*!< An invalid device ID was specified. */
    MEMORY_ERROR,      /*!< An error occured during memory allocation. */
    INVALID_PARAMETER, /*!< An invalid parameter was specified to a function. */
    INVALID_USE,       /*!< The function was called incorrectly. */
    DRIVER_ERROR,      /*!< A system driver error occured. */
    SYSTEM_ERROR,      /*!< A system error occured. */
    THREAD_ERROR       /*!< A thread error occured. */
  };

  //! The constructor.
  RtMidiError( const std::string& message, Type type = RtMidiError::UNSPECIFIED ) throw() : message_(message), type_(type) {}
 
  //! The destructor.
  virtual ~RtMidiError( void ) throw() {}

  //! Prints thrown error message to stderr.
  virtual void printMessage( void ) const throw() { std::cerr << '\n' << message_ << "\n\n"; }

  //! Returns the thrown error message type.
  virtual const Type& getType(void) const throw() { return type_; }

  //! Returns the thrown error message string.
  virtual const std::string& getMessage(void) const throw() { return message_; }

  //! Returns the thrown error message as a c-style string.
  virtual const char* what( void ) const throw() { return message_.c_str(); }

 protected:
  std::string message_;
  Type type_;
};

//! RtMidi error callback function prototype.
/*!
    \param type Type of error.
    \param errorText Error description.

    Note that class behaviour is undefined after a critical error (not
    a warning) is reported.
 */
typedef void (*RtMidiErrorCallback)( RtMidiError::Type type, const std::string &errorText, void *userData );

class MidiApi;

class RtMidi
{
 public:

  //! MIDI API specifier arguments.
  enum Api {
    UNSPECIFIED,    /*!< Search for a working compiled API. */
    MACOSX_CORE,    /*!< Macintosh OS-X Core Midi API. */
    LINUX_ALSA,     /*!< The Advanced Linux Sound Architecture API. */
    UNIX_JACK,      /*!< The JACK Low-Latency MIDI Server API. */
    WINDOWS_MM,     /*!< The Microsoft Multimedia MIDI API. */
    RTMIDI_DUMMY    /*!< A compilable but non-functional API. */
  };

  //! A static function to determine the current RtMidi version.
  static std::string getVersion( void ) throw();

  //! A static function to determine the available compiled MIDI APIs.
  /*!
    The values returned in the std::vector can be compared against
    the enumerated list values.  Note that there can be more than one
    API compiled for certain operating systems.
  */
  static void getCompiledApi( std::vector<RtMidi::Api> &apis ) throw();

  //! Pure virtual openPort() function.
  virtual void openPort( unsigned int portNumber = 0, const std::string &portName = std::string( "RtMidi" ) ) = 0;

  //! Pure virtual openVirtualPort() function.
  virtual void openVirtualPort( const std::string &portName = std::string( "RtMidi" ) ) = 0;

  //! Pure virtual getPortCount() function.
  virtual unsigned int getPortCount() = 0;

  //! Pure virtual getPortName() function.
  virtual std::string getPortName( unsigned int portNumber = 0 ) = 0;

  //! Pure virtual closePort() function.
  virtual void closePort( void ) = 0;

  //! Returns true if a port is open and false if not.
  /*!
      Note that this only applies to connections made with the openPort()
      function, not to virtual ports.
  */
  virtual bool isPortOpen( void ) const = 0;

  //! Set an error callback function to be invoked when an error has occured.
  /*!
    The callback function will be called whenever an error has occured. It is best
    to set the error callback function before opening a port.
  */
  virtual void setErrorCallback( RtMidiErrorCallback errorCallback = NULL, void *userData = 0 ) = 0;

 protected:

  RtMidi();
  virtual ~RtMidi();

  MidiApi *rtapi_;
};

/**********************************************************************/
/*! \class RtMidiIn
    \brief A realtime MIDI input class.

    This class provides a common, platform-independent API for
    realtime MIDI input.  It allows access to a single MIDI input
    port.  Incoming MIDI messages are either saved to a queue for
    retrieval using the getMessage() function or immediately passed to
    a user-specified callback function.  Create multiple instances of
    this class to connect to more than one MIDI device at the same
    time.  With the OS-X, Linux ALSA, and JACK MIDI APIs, it is also
    possible to open a virtual input port to which other MIDI software
    clients can connect.

    by Gary P. Scavone, 2003-2017.
*/
/**********************************************************************/

// **************************************************************** //
//
// RtMidiIn and RtMidiOut class declarations.
//
// RtMidiIn / RtMidiOut are "controllers" used to select an available
// MIDI input or output interface.  They present common APIs for the
// user to call but all functionality is implemented by the classes
// MidiInApi, MidiOutApi and their subclasses.  RtMidiIn and RtMidiOut
// each create an instance of a MidiInApi or MidiOutApi subclass based
// on the user's API choice.  If no choice is made, they attempt to
// make a "logical" API selection.
//
// **************************************************************** //

class RtMidiIn : public RtMidi
{
 public:

  //! User callback function type definition.
  typedef void (*RtMidiCallback)( double timeStamp, std::vector<unsigned char> *message, void *userData);

  //! Default constructor that allows an optional api, client name and queue size.
  /*!
    An exception will be thrown if a MIDI system initialization
    error occurs.  The queue size defines the maximum number of
    messages that can be held in the MIDI queue (when not using a
    callback function).  If the queue size limit is reached,
    incoming messages will be ignored.

    If no API argument is specified and multiple API support has been
    compiled, the default order of use is ALSA, JACK (Linux) and CORE,
    JACK (OS-X).

    \param api        An optional API id can be specified.
    \param clientName An optional client name can be specified. This
                      will be used to group the ports that are created
                      by the application.
    \param queueSizeLimit An optional size of the MIDI input queue can be specified.
  */
  RtMidiIn( RtMidi::Api api=UNSPECIFIED,
            const std::string& clientName = "RtMidi Input Client",
            unsigned int queueSizeLimit = 100 );

  //! If a MIDI connection is still open, it will be closed by the destructor.
  ~RtMidiIn ( void ) throw();

  //! Returns the MIDI API specifier for the current instance of RtMidiIn.
  RtMidi::Api getCurrentApi( void ) throw();

  //! Open a MIDI input connection given by enumeration number.
  /*!
    \param portNumber An optional port number greater than 0 can be specified.
                      Otherwise, the default or first port found is opened.
    \param portName An optional name for the application port that is used to connect to portId can be specified.
  */
  void openPort( unsigned int portNumber = 0, const std::string &portName = std::string( "RtMidi Input" ) );

  //! Create a virtual input port, with optional name, to allow software connections (OS X, JACK and ALSA only).
  /*!
    This function creates a virtual MIDI input port to which other
    software applications can connect.  This type of functionality
    is currently only supported by the Macintosh OS-X, any JACK,
    and Linux ALSA APIs (the function returns an error for the other APIs).

    \param portName An optional name for the application port that is
                    used to connect to portId can be specified.
  */
  void openVirtualPort( const std::string &portName = std::string( "RtMidi Input" ) );

  //! Set a callback function to be invoked for incoming MIDI messages.
  /*!
    The callback function will be called whenever an incoming MIDI
    message is received.  While not absolutely necessary, it is best
    to set the callback function before opening a MIDI port to avoid
    leaving some messages in the queue.

    \param callback A callback function must be given.
    \param userData Optionally, a pointer to additional data can be
                    passed to the callback function whenever it is called.
  */
  void setCallback( RtMidiCallback callback, void *userData = 0 );

  //! Cancel use of the current callback function (if one exists).
  /*!
    Subsequent incoming MIDI messages will be written to the queue
    and can be retrieved with the \e getMessage function.
  */
  void cancelCallback();

  //! Close an open MIDI connection (if one exists).
  void closePort( void );

  //! Returns true if a port is open and false if not.
  /*!
      Note that this only applies to connections made with the openPort()
      function, not to virtual ports.
  */
  virtual bool isPortOpen() const;

  //! Return the number of available MIDI input ports.
  /*!
    \return This function returns the number of MIDI ports of the selected API.
  */
  unsigned int getPortCount();

  //! Return a string identifier for the specified MIDI input port number.
  /*!
    \return The name of the port with the given Id is returned.
    \retval An empty string is returned if an invalid port specifier
            is provided. User code should assume a UTF-8 encoding.
  */
  std::string getPortName( unsigned int portNumber = 0 );

  //! Specify whether certain MIDI message types should be queued or ignored during input.
  /*!
    By default, MIDI timing and active sensing messages are ignored
    during message input because of their relative high data rates.
    MIDI sysex messages are ignored by default as well.  Variable
    values of "true" imply that the respective message type will be
    ignored.
  */
  void ignoreTypes( bool midiSysex = true, bool midiTime = true, bool midiSense = true );

  //! Fill the user-provided vector with the data bytes for the next available MIDI message in the input queue and return the event delta-time in seconds.
  /*!
    This function returns immediately whether a new message is
    available or not.  A valid message is indicated by a non-zero
    vector size.  An exception is thrown if an error occurs during
    message retrieval or an input connection was not previously
    established.
  */
  double getMessage( std::vector<unsigned char> *message );

  //! Set an error callback function to be invoked when an error has occured.
  /*!
    The callback function will be called whenever an error has occured. It is best
    to set the error callback function before opening a port.
  */
  virtual void setErrorCallback( RtMidiErrorCallback errorCallback = NULL, void *userData = 0 );

 protected:
  void openMidiApi( RtMidi::Api api, const std::string &clientName, unsigned int queueSizeLimit );

};

/**********************************************************************/
/*! \class RtMidiOut
    \brief A realtime MIDI output class.

    This class provides a common, platform-independent API for MIDI
    output.  It allows one to probe available MIDI output ports, to
    connect to one such port, and to send MIDI bytes immediately over
    the connection.  Create multiple instances of this class to
    connect to more than one MIDI device at the same time.  With the
    OS-X, Linux ALSA and JACK MIDI APIs, it is also possible to open a
    virtual port to which other MIDI software clients can connect.

    by Gary P. Scavone, 2003-2017.
*/
/**********************************************************************/

class RtMidiOut : public RtMidi
{
 public:

  //! Default constructor that allows an optional client name.
  /*!
    An exception will be thrown if a MIDI system initialization error occurs.

    If no API argument is specified and multiple API support has been
    compiled, the default order of use is ALSA, JACK (Linux) and CORE,
    JACK (OS-X).
  */
  RtMidiOut( RtMidi::Api api=UNSPECIFIED,
             const std::string& clientName = "RtMidi Output Client" );

  //! The destructor closes any open MIDI connections.
  ~RtMidiOut( void ) throw();

  //! Returns the MIDI API specifier for the current instance of RtMidiOut.
  RtMidi::Api getCurrentApi( void ) throw();

  //! Open a MIDI output connection.
  /*!
      An optional port number greater than 0 can be specified.
      Otherwise, the default or first port found is opened.  An
      exception is thrown if an error occurs while attempting to make
      the port connection.
  */
  void openPort( unsigned int portNumber = 0, const std::string &portName = std::string( "RtMidi Output" ) );

  //! Close an open MIDI connection (if one exists).
  void closePort( void );

  //! Returns true if a port is open and false if not.
  /*!
      Note that this only applies to connections made with the openPort()
      function, not to virtual ports.
  */
  virtual bool isPortOpen() const;

  //! Create a virtual output port, with optional name, to allow software connections (OS X, JACK and ALSA only).
  /*!
      This function creates a virtual MIDI output port to which other
      software applications can connect.  This type of functionality
      is currently only supported by the Macintosh OS-X, Linux ALSA
      and JACK APIs (the function does nothing with the other APIs).
      An exception is thrown if an error occurs while attempting to
      create the virtual port.
  */
  void openVirtualPort( const std::string &portName = std::string( "RtMidi Output" ) );

  //! Return the number of available MIDI output ports.
  unsigned int getPortCount( void );

  //! Return a string identifier for the specified MIDI port type and number.
  /*!
    \return The name of the port with the given Id is returned.
    \retval An empty string is returned if an invalid port specifier
            is provided. User code should assume a UTF-8 encoding.
  */
  std::string getPortName( unsigned int portNumber = 0 );

  //! Immediately send a single message out an open MIDI output port.
  /*!
      An exception is thrown if an error occurs during output or an
      output connection was not previously established.
  */
  void sendMessage( const std::vector<unsigned char> *message );

  //! Immediately send a single message out an open MIDI output port.
  /*!
      An exception is thrown if an error occurs during output or an
      output connection was not previously established.

      \param message A pointer to the MIDI message as raw bytes
      \param size    Length of the MIDI message in bytes
  */
  void sendMessage( const unsigned char *message, size_t size );

  //! Set an error callback function to be invoked when an error has occured.
  /*!
    The callback function will be called whenever an error has occured. It is best
    to set the error callback function before opening a port.
  */
  virtual void setErrorCallback( RtMidiErrorCallback errorCallback = NULL, void *userData = 0 );

 protected:
  void openMidiApi( RtMidi::Api api, const std::string &clientName );
};


// **************************************************************** //
//
// MidiInApi / MidiOutApi class declarations.
//
// Subclasses of MidiInApi and MidiOutApi contain all API- and
// OS-specific code necessary to fully implement the RtMidi API.
//
// Note that MidiInApi and MidiOutApi are abstract base classes and
// cannot be explicitly instantiated.  RtMidiIn and RtMidiOut will
// create instances of a MidiInApi or MidiOutApi subclass.
//
// **************************************************************** //

class MidiApi
{
 public:

  MidiApi();
  virtual ~MidiApi();
  virtual RtMidi::Api getCurrentApi( void ) = 0;
  virtual void openPort( unsigned int portNumber, const std::string &portName ) = 0;
  virtual void openVirtualPort( const std::string &portName ) = 0;
  virtual void closePort( void ) = 0;

  virtual unsigned int getPortCount( void ) = 0;
  virtual std::string getPortName( unsigned int portNumber ) = 0;

  inline bool isPortOpen() const { return connected_; }
  void setErrorCallback( RtMidiErrorCallback errorCallback, void *userData );

  //! A basic error reporting function for RtMidi classes.
  void error( RtMidiError::Type type, std::string errorString );

protected:
  virtual void initialize( const std::string& clientName ) = 0;

  void *apiData_;
  bool connected_;
  std::string errorString_;
  RtMidiErrorCallback errorCallback_;
  bool firstErrorOccurred_;
  void *errorCallbackUserData_;
};

class MidiInApi : public MidiApi
{
 public:

  MidiInApi( unsigned int queueSizeLimit );
  virtual ~MidiInApi( void );
  void setCallback( RtMidiIn::RtMidiCallback callback, void *userData );
  void cancelCallback( void );
  virtual void ignoreTypes( bool midiSysex, bool midiTime, bool midiSense );
  double getMessage( std::vector<unsigned char> *message );

  // A MIDI structure used internally by the class to store incoming
  // messages.  Each message represents one and only one MIDI message.
  struct MidiMessage { 
    std::vector<unsigned char> bytes; 

    //! Time in seconds elapsed since the previous message
    double timeStamp;

    // Default constructor.
  MidiMessage()
  :bytes(0), timeStamp(0.0) {}
  };

  struct MidiQueue {
    unsigned int front;
    unsigned int back;
    unsigned int ringSize;
    MidiMessage *ring;

    // Default constructor.
  MidiQueue()
  :front(0), back(0), ringSize(0), ring(0) {}
    bool push(const MidiMessage&);
    bool pop(std::vector<unsigned char>*, double*);
    unsigned int size(unsigned int *back=0,
		      unsigned int *front=0);
  };

  // The RtMidiInData structure is used to pass private class data to
  // the MIDI input handling function or thread.
  struct RtMidiInData {
    MidiQueue queue;
    MidiMessage message;
    unsigned char ignoreFlags;
    bool doInput;
    bool firstMessage;
    void *apiData;
    bool usingCallback;
    RtMidiIn::RtMidiCallback userCallback;
    void *userData;
    bool continueSysex;

    // Default constructor.
  RtMidiInData()
  : ignoreFlags(7), doInput(false), firstMessage(true),
      apiData(0), usingCallback(false), userCallback(0), userData(0),
      continueSysex(false) {}
  };

 protected:
  RtMidiInData inputData_;
};

class MidiOutApi : public MidiApi
{
 public:

  MidiOutApi( void );
  virtual ~MidiOutApi( void );
  virtual void sendMessage( const unsigned char *message, size_t size ) = 0;
};

// **************************************************************** //
//
// Inline RtMidiIn and RtMidiOut definitions.
//
// **************************************************************** //

inline RtMidi::Api RtMidiIn :: getCurrentApi( void ) throw() { return rtapi_->getCurrentApi(); }
inline void RtMidiIn :: openPort( unsigned int portNumber, const std::string &portName ) { rtapi_->openPort( portNumber, portName ); }
inline void RtMidiIn :: openVirtualPort( const std::string &portName ) { rtapi_->openVirtualPort( portName ); }
inline void RtMidiIn :: closePort( void ) { rtapi_->closePort(); }
inline bool RtMidiIn :: isPortOpen() const { return rtapi_->isPortOpen(); }
inline void RtMidiIn :: setCallback( RtMidiCallback callback, void *userData ) { ((MidiInApi *)rtapi_)->setCallback( callback, userData ); }
inline void RtMidiIn :: cancelCallback( void ) { ((MidiInApi *)rtapi_)->cancelCallback(); }
inline unsigned int RtMidiIn :: getPortCount( void ) { return rtapi_->getPortCount(); }
inline std::string RtMidiIn :: getPortName( unsigned int portNumber ) { return rtapi_->getPortName( portNumber ); }
inline void RtMidiIn :: ignoreTypes( bool midiSysex, bool midiTime, bool midiSense ) { ((MidiInApi *)rtapi_)->ignoreTypes( midiSysex, midiTime, midiSense ); }
inline double RtMidiIn :: getMessage( std::vector<unsigned char> *message ) { return ((MidiInApi *)rtapi_)->getMessage( message ); }
inline void RtMidiIn :: setErrorCallback( RtMidiErrorCallback errorCallback, void *userData ) { rtapi_->setErrorCallback(errorCallback, userData); }

inline RtMidi::Api RtMidiOut :: getCurrentApi( void ) throw() { return rtapi_->getCurrentApi(); }
inline void RtMidiOut :: openPort( unsigned int portNumber, const std::string &portName ) { rtapi_->openPort( portNumber, portName ); }
inline void RtMidiOut :: openVirtualPort( const std::string &portName ) { rtapi_->openVirtualPort( portName ); }
inline void RtMidiOut :: closePort( void ) { rtapi_->closePort(); }
inline bool RtMidiOut :: isPortOpen() const { return rtapi_->isPortOpen(); }
inline unsigned int RtMidiOut :: getPortCount( void ) { return rtapi_->getPortCount(); }
inline std::string RtMidiOut :: getPortName( unsigned int portNumber ) { return rtapi_->getPortName( portNumber ); }
inline void RtMidiOut :: sendMessage( const std::vector<unsigned char> *message ) { ((MidiOutApi *)rtapi_)->sendMessage( &message->at(0), message->size() ); }
inline void RtMidiOut :: sendMessage( const unsigned char *message, size_t size ) { ((MidiOutApi *)rtapi_)->sendMessage( message, size ); }
inline void RtMidiOut :: setErrorCallback( RtMidiErrorCallback errorCallback, void *userData ) { rtapi_->setErrorCallback(errorCallback, userData); }

// **************************************************************** //
//
// MidiInApi and MidiOutApi subclass prototypes.
//
// **************************************************************** //

#if !defined(__LINUX_ALSA__) && !defined(__UNIX_JACK__) && !defined(__MACOSX_CORE__) && !defined(__WINDOWS_MM__)
  #define __RTMIDI_DUMMY__
#endif

#if defined(__MACOSX_CORE__)

class MidiInCore: public MidiInApi
{
 public:
  MidiInCore( const std::string &clientName, unsigned int queueSizeLimit );
  ~MidiInCore( void );
  RtMidi::Api getCurrentApi( void ) { return RtMidi::MACOSX_CORE; };
  void openPort( unsigned int portNumber, const std::string &portName );
  void openVirtualPort( const std::string &portName );
  void closePort( void );
  unsigned int getPortCount( void );
  std::string getPortName( unsigned int portNumber );

 protected:
  void initialize( const std::string& clientName );
};

class MidiOutCore: public MidiOutApi
{
 public:
  MidiOutCore( const std::string &clientName );
  ~MidiOutCore( void );
  RtMidi::Api getCurrentApi( void ) { return RtMidi::MACOSX_CORE; };
  void openPort( unsigned int portNumber, const std::string &portName );
  void openVirtualPort( const std::string &portName );
  void closePort( void );
  unsigned int getPortCount( void );
  std::string getPortName( unsigned int portNumber );
  void sendMessage( const unsigned char *message, size_t size );

 protected:
  void initialize( const std::string& clientName );
};

#endif

#if defined(__UNIX_JACK__)

class MidiInJack: public MidiInApi
{
 public:
  MidiInJack( const std::string &clientName, unsigned int queueSizeLimit );
  ~MidiInJack( void );
  RtMidi::Api getCurrentApi( void ) { return RtMidi::UNIX_JACK; };
  void openPort( unsigned int portNumber, const std::string &portName );
  void openVirtualPort( const std::string &portName );
  void closePort( void );
  unsigned int getPortCount( void );
  std::string getPortName( unsigned int portNumber );

 protected:
  std::string clientName;

  void connect( void );
  void initialize( const std::string& clientName );
};

class MidiOutJack: public MidiOutApi
{
 public:
  MidiOutJack( const std::string &clientName );
  ~MidiOutJack( void );
  RtMidi::Api getCurrentApi( void ) { return RtMidi::UNIX_JACK; };
  void openPort( unsigned int portNumber, const std::string &portName );
  void openVirtualPort( const std::string &portName );
  void closePort( void );
  unsigned int getPortCount( void );
  std::string getPortName( unsigned int portNumber );
  void sendMessage( const unsigned char *message, size_t size );

 protected:
  std::string clientName;

  void connect( void );
  void initialize( const std::string& clientName );
};

#endif

#if defined(__LINUX_ALSA__)

class MidiInAlsa: public MidiInApi
{
 public:
  MidiInAlsa( const std::string &clientName, unsigned int queueSizeLimit );
  ~MidiInAlsa( void );
  RtMidi::Api getCurrentApi( void ) { return RtMidi::LINUX_ALSA; };
  void openPort( unsigned int portNumber, const std::string &portName );
  void openVirtualPort( const std::string &portName );
  void closePort( void );
  unsigned int getPortCount( void );
  std::string getPortName( unsigned int portNumber );

 protected:
  void initialize( const std::string& clientName );
};

class MidiOutAlsa: public MidiOutApi
{
 public:
  MidiOutAlsa( const std::string &clientName );
  ~MidiOutAlsa( void );
  RtMidi::Api getCurrentApi( void ) { return RtMidi::LINUX_ALSA; };
  void openPort( unsigned int portNumber, const std::string &portName );
  void openVirtualPort( const std::string &portName );
  void closePort( void );
  unsigned int getPortCount( void );
  std::string getPortName( unsigned int portNumber );
  void sendMessage( const unsigned char *message, size_t size );

 protected:
  void initialize( const std::string& clientName );
};

#endif

#if defined(__WINDOWS_MM__)

class MidiInWinMM: public MidiInApi
{
 public:
  MidiInWinMM( const std::string &clientName, unsigned int queueSizeLimit );
  ~MidiInWinMM( void );
  RtMidi::Api getCurrentApi( void ) { return RtMidi::WINDOWS_MM; };
  void openPort( unsigned int portNumber, const std::string &portName );
  void openVirtualPort( const std::string &portName );
  void closePort( void );
  unsigned int getPortCount( void );
  std::string getPortName( unsigned int portNumber );

 protected:
  void initialize( const std::string& clientName );
};

class MidiOutWinMM: public MidiOutApi
{
 public:
  MidiOutWinMM( const std::string &clientName );
  ~MidiOutWinMM( void );
  RtMidi::Api getCurrentApi( void ) { return RtMidi::WINDOWS_MM; };
  void openPort( unsigned int portNumber, const std::string &portName );
  void openVirtualPort( const std::string &portName );
  void closePort( void );
  unsigned int getPortCount( void );
  std::string getPortName( unsigned int portNumber );
  void sendMessage( const unsigned char *message, size_t size );

 protected:
  void initialize( const std::string& clientName );
};

#endif

#if defined(__RTMIDI_DUMMY__)

class MidiInDummy: public MidiInApi
{
 public:
 MidiInDummy( const std::string &/*clientName*/, unsigned int queueSizeLimit ) : MidiInApi( queueSizeLimit ) { errorString_ = "MidiInDummy: This class provides no functionality."; error( RtMidiError::WARNING, errorString_ ); }
  RtMidi::Api getCurrentApi( void ) { return RtMidi::RTMIDI_DUMMY; }
  void openPort( unsigned int /*portNumber*/, const std::string &/*portName*/ ) {}
  void openVirtualPort( const std::string &/*portName*/ ) {}
  void closePort( void ) {}
  unsigned int getPortCount( void ) { return 0; }
  std::string getPortName( unsigned int /*portNumber*/ ) { return ""; }

 protected:
  void initialize( const std::string& /*clientName*/ ) {}
};

class MidiOutDummy: public MidiOutApi
{
 public:
  MidiOutDummy( const std::string &/*clientName*/ ) { errorString_ = "MidiOutDummy: This class provides no functionality."; error( RtMidiError::WARNING, errorString_ ); }
  RtMidi::Api getCurrentApi( void ) { return RtMidi::RTMIDI_DUMMY; }
  void openPort( unsigned int /*portNumber*/, const std::string &/*portName*/ ) {}
  void openVirtualPort( const std::string &/*portName*/ ) {}
  void closePort( void ) {}
  unsigned int getPortCount( void ) { return 0; }
  std::string getPortName( unsigned int /*portNumber*/ ) { return ""; }
  void sendMessage( const unsigned char * /*message*/, size_t /*size*/ ) {}

 protected:
  void initialize( const std::string& /*clientName*/ ) {}
};

#endif

#endif
/**************************  END  RtMidi.h **************************/

class MapUI;

//-------------------------------------------------
// MIDI input/output handling using RtMidi library
//-------------------------------------------------

class rt_midi : public midi_handler {

    private:
    
        std::vector<RtMidiIn*> fInput;
        std::vector<RtMidiOut*> fOutput;
        bool fIsVirtual;
        bool fPolling;
    
        static void midiCallback(double time, std::vector<unsigned char>* message, void* arg)
        {
            rt_midi* midi = static_cast<rt_midi*>(arg);
            size_t nBytes = message->size();
            int type = (int)message->at(0) & 0xf0;
            int channel = (int)message->at(0) & 0x0f;
            
            // MIDI sync
            if (nBytes == 1) {
                midi->handleSync(time, (int)message->at(0));
            // One data byte messages
            } else if (nBytes == 2) {
                midi->handleData1(time, type, channel, (int)message->at(1));
            // Two data bytes messages
            } else if (nBytes == 3) {
                midi->handleData2(time, type, channel, (int)message->at(1), (int)message->at(2));
            } else {
                midi->handleMessage(time, (int)message->at(0), *message);
            }
        }
        
        bool openMidiInputPorts()
        {
            // Get number of input ports
            RtMidiIn midi_in;
            unsigned nInPorts = midi_in.getPortCount();
            if (nInPorts == 0) {
                std::cout << "No input ports available!" << std::endl;
                return false;
            }
    
            // Then open all of them
            for (unsigned int i = 0; i < nInPorts; i++) {
                RtMidiIn* midi_in = new RtMidiIn();
                midi_in->ignoreTypes(true, false, true);
                fInput.push_back(midi_in);
                midi_in->openPort(i);
                if (!fPolling) {
                    midi_in->setCallback(&midiCallback, this);
                }
                //std::cout << "Input port #" << i << ": " << midi_in->getPortName(i) << '\n';
            }
            return true;
        }
        
        bool openMidiOutputPorts()
        {
            // Get number of output ports
            RtMidiOut midi_out;
            unsigned nOutPorts = midi_out.getPortCount();
            if (nOutPorts == 0) {
                std::cout << "No output ports available!" << std::endl;
                return false;
            }
    
            // Then open all of them
            for (unsigned int i = 0; i < nOutPorts; i++) {
                RtMidiOut* midi_out = new RtMidiOut();
                fOutput.push_back(midi_out);
                midi_out->openPort(i);
                //std::cout << "Output port #" << i << ": " << midi_out->getPortName(i) << '\n';
            }
            return true;
        }
        
        void chooseMidiInputPort(const std::string& name)
        {
            RtMidiIn* midi_in = new RtMidiIn();
            midi_in->ignoreTypes(true, false, true);
            fInput.push_back(midi_in);
            if (!fPolling) {
                midi_in->setCallback(&midiCallback, this);
            }
            midi_in->openVirtualPort(name);
        }
        
        void chooseMidiOutPort(const std::string& name)
        {
            RtMidiOut* midi_out = new RtMidiOut();
            fOutput.push_back(midi_out);
            midi_out->openVirtualPort(name);
        }
        
        void sendMessage(std::vector<unsigned char>& message)
        {
            for (auto& it : fOutput) {
                it->sendMessage(&message);
            }
        }
    
    public:
    
        rt_midi(const std::string& name = "RtMidi",
                bool is_virtual = false,
                bool is_polling = false)
        :midi_handler(name), fIsVirtual(is_virtual), fPolling(is_polling)
        {}
        
        virtual ~rt_midi()
        {
            stopMidi();
        }
        
        bool startMidi()
        {
            try {
            
            #if TARGET_OS_IPHONE
                if (!openMidiInputPorts())  { stopMidi(); return false; }
                if (!openMidiOutputPorts()) { stopMidi(); return false; }
            #else
                if (fIsVirtual) {
                    chooseMidiInputPort(fName);
                    chooseMidiOutPort(fName);
                } else {
                    if (!openMidiInputPorts())  { stopMidi(); return false; }
                    //std::cout << "Warning : MIDI outputs are not started in this mode !\n";
                }
            #endif
                return true;
                
            } catch (RtMidiError &error) {
                error.printMessage();
                stopMidi();
                return false;
            }
        }
        
        void stopMidi()
        {
            for (auto& it1 : fInput) {
                delete it1;
            }
            fInput.clear();
            for (auto& it2 : fOutput) {
                delete it2;
            }
            fOutput.clear();
        }
    
        // To be used in polling mode
        int getMessages(std::vector<MIDIMessage>* messages)
        {
            int count = 0;
            double first_time_stamp = 0.;
            for (auto& it : fInput) {
                std::vector<unsigned char> message;
                double time_stamp = (uint32_t)it->getMessage(&message);
                if (message.size() > 0) {
                    if (count == 0) first_time_stamp = time_stamp;
                    MIDIMessage& mes = messages->at(count++);
                    mes.frameIndex = (uint32_t)(time_stamp - first_time_stamp);
                    mes.byte0 = message[0];
                    mes.byte1 = message[1];
                    mes.byte2 = message[2];
                }
            }
            return count;
        }
    
        // MIDI output API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_NOTE_ON + channel);
            message.push_back(pitch);
            message.push_back(velocity);
            sendMessage(message);
            return 0;
        }
        
        void keyOff(int channel, int pitch, int velocity) 
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_NOTE_OFF + channel);
            message.push_back(pitch);
            message.push_back(velocity);
            sendMessage(message);
        }
        
        void ctrlChange(int channel, int ctrl, int val) 
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_CONTROL_CHANGE + channel);
            message.push_back(ctrl);
            message.push_back(val);
            sendMessage(message);
        }
        
        void chanPress(int channel, int press) 
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_AFTERTOUCH + channel);
            message.push_back(press);
            sendMessage(message);
        }
        
        void progChange(int channel, int pgm) 
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_PROGRAM_CHANGE + channel);
            message.push_back(pgm);
            sendMessage(message);
        }
          
        void keyPress(int channel, int pitch, int press) 
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_POLY_AFTERTOUCH + channel);
            message.push_back(pitch);
            message.push_back(press);
            sendMessage(message);
        }
   
        void pitchWheel(int channel, int wheel) 
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_PITCH_BEND + channel);
            message.push_back(wheel & 0x7F);		// lsb 7bit
            message.push_back((wheel >> 7) & 0x7F);	// msb 7bit
            sendMessage(message);
        }
        
        void ctrlChange14bits(int channel, int ctrl, int value) {}
         
        void startSync(double date)
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_START);
            sendMessage(message);
        }
       
        void stopSync(double date)
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_STOP);
            sendMessage(message);
        }
        
        void clock(double date) 
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_CLOCK);
            sendMessage(message);
        }
    
        void sysEx(double, std::vector<unsigned char>& message)
        {
            sendMessage(message);
        }
    
};


#endif // __rt_midi__
/**************************  END  rt-midi.h **************************/
/**********************************************************************/
/*! \class RtMidi
    \brief An abstract base class for realtime MIDI input/output.

    This class implements some common functionality for the realtime
    MIDI input/output subclasses RtMidiIn and RtMidiOut.

    RtMidi WWW site: http://music.mcgill.ca/~gary/rtmidi/

    RtMidi: realtime MIDI i/o C++ classes
    Copyright (c) 2003-2017 Gary P. Scavone

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation files
    (the "Software"), to deal in the Software without restriction,
    including without limitation the rights to use, copy, modify, merge,
    publish, distribute, sublicense, and/or sell copies of the Software,
    and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    Any person wishing to distribute modifications to the Software is
    asked to send the modifications to the original developer so that
    they can be incorporated into the canonical version.  This is,
    however, not a binding provision of this license.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
    ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
    CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
/**********************************************************************/

#include <sstream>

#ifdef __APPLE__

Float64 CAHostTimeBase::sFrequency = 0;
Float64 CAHostTimeBase::sInverseFrequency = 0;
UInt32 CAHostTimeBase::sMinDelta = 0;
UInt32 CAHostTimeBase::sToNanosNumerator = 0;
UInt32 CAHostTimeBase::sToNanosDenominator = 0;
UInt32 CAHostTimeBase::sFromNanosNumerator = 0;
UInt32 CAHostTimeBase::sFromNanosDenominator = 0;
bool CAHostTimeBase::sUseMicroseconds = false;
bool CAHostTimeBase::sIsInited = false;
#if Track_Host_TimeBase
UInt64 CAHostTimeBase::sLastTime = 0;
#endif

//=============================================================================
//	CAHostTimeBase
//
//	This class provides platform independent access to the host's time base.
//=============================================================================

void CAHostTimeBase::Initialize()
{
    if (!sIsInited) {
        
        //	get the info about Absolute time
#if TARGET_OS_MAC
        struct mach_timebase_info	theTimeBaseInfo;
        mach_timebase_info(&theTimeBaseInfo);
        sMinDelta = 1;
        sToNanosNumerator = theTimeBaseInfo.numer;
        sToNanosDenominator = theTimeBaseInfo.denom;
        sFromNanosNumerator = sToNanosDenominator;
        sFromNanosDenominator = sToNanosNumerator;
        
        //	the frequency of that clock is: (sToNanosDenominator / sToNanosNumerator) * 10^9
        sFrequency = static_cast<Float64>(sToNanosDenominator) / static_cast<Float64>(sToNanosNumerator);
        sFrequency *= 1000000000.0;
#elif TARGET_OS_WIN32
        LARGE_INTEGER theFrequency;
        QueryPerformanceFrequency(&theFrequency);
        sMinDelta = 1;
        sToNanosNumerator = 1000000000ULL;
        sToNanosDenominator = *((UInt64*)&theFrequency);
        sFromNanosNumerator = sToNanosDenominator;
        sFromNanosDenominator = sToNanosNumerator;
        sFrequency = static_cast<Float64>(*((UInt64*)&theFrequency));
#endif
        sInverseFrequency = 1.0 / sFrequency;
        
#if	Log_Host_Time_Base_Parameters
        DebugMessage(  "Host Time Base Parameters");
        DebugMessageN1(" Minimum Delta:          %lu", sMinDelta);
        DebugMessageN1(" Frequency:              %f", sFrequency);
        DebugMessageN1(" To Nanos Numerator:     %lu", sToNanosNumerator);
        DebugMessageN1(" To Nanos Denominator:   %lu", sToNanosDenominator);
        DebugMessageN1(" From Nanos Numerator:   %lu", sFromNanosNumerator);
        DebugMessageN1(" From Nanos Denominator: %lu", sFromNanosDenominator);
#endif
        
        sIsInited = true;
    }
}

#endif

#if defined(__MACOSX_CORE__)
  #if TARGET_OS_IPHONE
    #define AudioGetCurrentHostTime CAHostTimeBase::GetCurrentTime
    #define AudioConvertHostTimeToNanos CAHostTimeBase::ConvertToNanos
  #endif
#endif

// Default for Windows is to add an identifier to the port names; this
// flag can be undefined to disable this behaviour.
#define RTMIDI_ENSURE_UNIQUE_PORTNAMES

//*********************************************************************//
//  RtMidi Definitions
//*********************************************************************//

RtMidi :: RtMidi()
  : rtapi_(0)
{
#if defined(__MACOSX_CORE__)
    #if TARGET_OS_IPHONE
        CAHostTimeBase::Initialize();
    #endif
#endif
}

RtMidi :: ~RtMidi()
{
  delete rtapi_;
  rtapi_ = 0;
}

std::string RtMidi :: getVersion( void ) throw()
{
  return std::string( RTMIDI_VERSION );
}

void RtMidi :: getCompiledApi( std::vector<RtMidi::Api> &apis ) throw()
{
  apis.clear();

  // The order here will control the order of RtMidi's API search in
  // the constructor.
#if defined(__MACOSX_CORE__)
  apis.push_back( MACOSX_CORE );
#endif
#if defined(__LINUX_ALSA__)
  apis.push_back( LINUX_ALSA );
#endif
#if defined(__UNIX_JACK__)
  apis.push_back( UNIX_JACK );
#endif
#if defined(__WINDOWS_MM__)
  apis.push_back( WINDOWS_MM );
#endif
#if defined(__RTMIDI_DUMMY__)
  apis.push_back( RTMIDI_DUMMY );
#endif
}

//*********************************************************************//
//  RtMidiIn Definitions
//*********************************************************************//

void RtMidiIn :: openMidiApi( RtMidi::Api api, const std::string &clientName, unsigned int queueSizeLimit )
{
  delete rtapi_;
  rtapi_ = 0;

#if defined(__UNIX_JACK__)
  if ( api == UNIX_JACK )
    rtapi_ = new MidiInJack( clientName, queueSizeLimit );
#endif
#if defined(__LINUX_ALSA__)
  if ( api == LINUX_ALSA )
    rtapi_ = new MidiInAlsa( clientName, queueSizeLimit );
#endif
#if defined(__WINDOWS_MM__)
  if ( api == WINDOWS_MM )
    rtapi_ = new MidiInWinMM( clientName, queueSizeLimit );
#endif
#if defined(__MACOSX_CORE__)
  if ( api == MACOSX_CORE )
    rtapi_ = new MidiInCore( clientName, queueSizeLimit );
#endif
#if defined(__RTMIDI_DUMMY__)
  if ( api == RTMIDI_DUMMY )
    rtapi_ = new MidiInDummy( clientName, queueSizeLimit );
#endif
}

RtMidiIn :: RtMidiIn( RtMidi::Api api, const std::string &clientName, unsigned int queueSizeLimit )
  : RtMidi()
{
  if ( api != UNSPECIFIED ) {
    // Attempt to open the specified API.
    openMidiApi( api, clientName, queueSizeLimit );
    if ( rtapi_ ) return;

    // No compiled support for specified API value.  Issue a warning
    // and continue as if no API was specified.
    std::cerr << "\nRtMidiIn: no compiled support for specified API argument!\n\n" << std::endl;
  }

  // Iterate through the compiled APIs and return as soon as we find
  // one with at least one port or we reach the end of the list.
  std::vector< RtMidi::Api > apis;
  getCompiledApi( apis );
  for ( unsigned int i=0; i<apis.size(); i++ ) {
    openMidiApi( apis[i], clientName, queueSizeLimit );
    if ( rtapi_ && rtapi_->getPortCount() ) break;
  }

  if ( rtapi_ ) return;

  // It should not be possible to get here because the preprocessor
  // definition __RTMIDI_DUMMY__ is automatically defined if no
  // API-specific definitions are passed to the compiler. But just in
  // case something weird happens, we'll throw an error.
  std::string errorText = "RtMidiIn: no compiled API support found ... critical error!!";
  throw( RtMidiError( errorText, RtMidiError::UNSPECIFIED ) );
}

RtMidiIn :: ~RtMidiIn() throw()
{
}


//*********************************************************************//
//  RtMidiOut Definitions
//*********************************************************************//

void RtMidiOut :: openMidiApi( RtMidi::Api api, const std::string &clientName )
{
  delete rtapi_;
  rtapi_ = 0;

#if defined(__UNIX_JACK__)
  if ( api == UNIX_JACK )
    rtapi_ = new MidiOutJack( clientName );
#endif
#if defined(__LINUX_ALSA__)
  if ( api == LINUX_ALSA )
    rtapi_ = new MidiOutAlsa( clientName );
#endif
#if defined(__WINDOWS_MM__)
  if ( api == WINDOWS_MM )
    rtapi_ = new MidiOutWinMM( clientName );
#endif
#if defined(__MACOSX_CORE__)
  if ( api == MACOSX_CORE )
    rtapi_ = new MidiOutCore( clientName );
#endif
#if defined(__RTMIDI_DUMMY__)
  if ( api == RTMIDI_DUMMY )
    rtapi_ = new MidiOutDummy( clientName );
#endif
}

RtMidiOut :: RtMidiOut( RtMidi::Api api, const std::string &clientName)
{
  if ( api != UNSPECIFIED ) {
    // Attempt to open the specified API.
    openMidiApi( api, clientName );
    if ( rtapi_ ) return;

    // No compiled support for specified API value.  Issue a warning
    // and continue as if no API was specified.
    std::cerr << "\nRtMidiOut: no compiled support for specified API argument!\n\n" << std::endl;
  }

  // Iterate through the compiled APIs and return as soon as we find
  // one with at least one port or we reach the end of the list.
  std::vector< RtMidi::Api > apis;
  getCompiledApi( apis );
  for ( unsigned int i=0; i<apis.size(); i++ ) {
    openMidiApi( apis[i], clientName );
    if ( rtapi_ && rtapi_->getPortCount() ) break;
  }

  if ( rtapi_ ) return;

  // It should not be possible to get here because the preprocessor
  // definition __RTMIDI_DUMMY__ is automatically defined if no
  // API-specific definitions are passed to the compiler. But just in
  // case something weird happens, we'll thrown an error.
  std::string errorText = "RtMidiOut: no compiled API support found ... critical error!!";
  throw( RtMidiError( errorText, RtMidiError::UNSPECIFIED ) );
}

RtMidiOut :: ~RtMidiOut() throw()
{
}

//*********************************************************************//
//  Common MidiApi Definitions
//*********************************************************************//

MidiApi :: MidiApi( void )
  : apiData_( 0 ), connected_( false ), errorCallback_(0), firstErrorOccurred_(false), errorCallbackUserData_(0)
{
}

MidiApi :: ~MidiApi( void )
{
}

void MidiApi :: setErrorCallback( RtMidiErrorCallback errorCallback, void *userData = 0 )
{
    errorCallback_ = errorCallback;
    errorCallbackUserData_ = userData;
}

void MidiApi :: error( RtMidiError::Type type, std::string errorString )
{
  if ( errorCallback_ ) {

    if ( firstErrorOccurred_ )
      return;

    firstErrorOccurred_ = true;
    const std::string errorMessage = errorString;

    errorCallback_( type, errorMessage, errorCallbackUserData_);
    firstErrorOccurred_ = false;
    return;
  }

  if ( type == RtMidiError::WARNING ) {
    std::cerr << '\n' << errorString << "\n\n";
  }
  else if ( type == RtMidiError::DEBUG_WARNING ) {
#if defined(__RTMIDI_DEBUG__)
    std::cerr << '\n' << errorString << "\n\n";
#endif
  }
  else {
    std::cerr << '\n' << errorString << "\n\n";
    throw RtMidiError( errorString, type );
  }
}

//*********************************************************************//
//  Common MidiInApi Definitions
//*********************************************************************//

MidiInApi :: MidiInApi( unsigned int queueSizeLimit )
  : MidiApi()
{
  // Allocate the MIDI queue.
  inputData_.queue.ringSize = queueSizeLimit;
  if ( inputData_.queue.ringSize > 0 )
    inputData_.queue.ring = new MidiMessage[ inputData_.queue.ringSize ];
}

MidiInApi :: ~MidiInApi( void )
{
  // Delete the MIDI queue.
  if ( inputData_.queue.ringSize > 0 ) delete [] inputData_.queue.ring;
}

void MidiInApi :: setCallback( RtMidiIn::RtMidiCallback callback, void *userData )
{
  if ( inputData_.usingCallback ) {
    errorString_ = "MidiInApi::setCallback: a callback function is already set!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  if ( !callback ) {
    errorString_ = "RtMidiIn::setCallback: callback function value is invalid!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  inputData_.userCallback = callback;
  inputData_.userData = userData;
  inputData_.usingCallback = true;
}

void MidiInApi :: cancelCallback()
{
  if ( !inputData_.usingCallback ) {
    errorString_ = "RtMidiIn::cancelCallback: no callback function was set!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  inputData_.userCallback = 0;
  inputData_.userData = 0;
  inputData_.usingCallback = false;
}

void MidiInApi :: ignoreTypes( bool midiSysex, bool midiTime, bool midiSense )
{
  inputData_.ignoreFlags = 0;
  if ( midiSysex ) inputData_.ignoreFlags = 0x01;
  if ( midiTime ) inputData_.ignoreFlags |= 0x02;
  if ( midiSense ) inputData_.ignoreFlags |= 0x04;
}

double MidiInApi :: getMessage( std::vector<unsigned char> *message )
{
  message->clear();

  if ( inputData_.usingCallback ) {
    errorString_ = "RtMidiIn::getNextMessage: a user callback is currently set for this port.";
    error( RtMidiError::WARNING, errorString_ );
    return 0.0;
  }

  double timeStamp;
  if (!inputData_.queue.pop(message, &timeStamp))
    return 0.0;

  return timeStamp;
}

unsigned int MidiInApi::MidiQueue::size(unsigned int *__back,
					unsigned int *__front)
{
  // Access back/front members exactly once and make stack copies for
  // size calculation
  unsigned int _back = back, _front = front, _size;
  if (_back >= _front)
    _size = _back - _front;
  else
    _size = ringSize - _front + _back;

  // Return copies of back/front so no new and unsynchronized accesses
  // to member variables are needed.
  if (__back) *__back = _back;
  if (__front) *__front = _front;
  return _size;
}

// As long as we haven't reached our queue size limit, push the message.
bool MidiInApi::MidiQueue::push(const MidiInApi::MidiMessage& msg)
{
  // Local stack copies of front/back
  unsigned int _back, _front, _size;

  // Get back/front indexes exactly once and calculate current size
  _size = size(&_back, &_front);

  if ( _size < ringSize-1 )
  {
    ring[_back] = msg;
    back = (back+1)%ringSize;
    return true;
  }

  return false;
}

bool MidiInApi::MidiQueue::pop(std::vector<unsigned char> *msg, double* timeStamp)
{
  // Local stack copies of front/back
  unsigned int _back, _front, _size;

  // Get back/front indexes exactly once and calculate current size
  _size = size(&_back, &_front);

  if (_size == 0)
    return false;

  // Copy queued message to the vector pointer argument and then "pop" it.
  msg->assign( ring[_front].bytes.begin(), ring[_front].bytes.end() );
  *timeStamp = ring[_front].timeStamp;

  // Update front
  front = (front+1)%ringSize;
  return true;
}

//*********************************************************************//
//  Common MidiOutApi Definitions
//*********************************************************************//

MidiOutApi :: MidiOutApi( void )
  : MidiApi()
{
}

MidiOutApi :: ~MidiOutApi( void )
{
}

// *************************************************** //
//
// OS/API-specific methods.
//
// *************************************************** //

#if defined(__MACOSX_CORE__)

// The CoreMIDI API is based on the use of a callback function for
// MIDI input.  We convert the system specific time stamps to delta
// time values.

// The CoreMIDI API is based on the use of a callback function for
// MIDI input.  We convert the system specific time stamps to delta
// time values.

// OS-X CoreMIDI header files.
#include <CoreMIDI/CoreMIDI.h>

#if defined(__MACOSX_CORE__)
    #if TARGET_OS_IPHONE
    static inline UInt32 EndianS32_BtoN(UInt32 x)
        {
            return ((x << 24) & 0xFF000000) | ((x << 8) & 0x00FF0000)
            | ((x >> 8) & 0x0000FF00) | ((x >> 24) & 0x000000FF);
        }
    #else
        #include <CoreAudio/HostTime.h>
        #include <CoreServices/CoreServices.h>
    #endif
#endif

// A structure to hold variables related to the CoreMIDI API
// implementation.
struct CoreMidiData {
  MIDIClientRef client;
  MIDIPortRef port;
  MIDIEndpointRef endpoint;
  MIDIEndpointRef destinationId;
  unsigned long long lastTime;
  MIDISysexSendRequest sysexreq;
};

//*********************************************************************//
//  API: OS-X
//  Class Definitions: MidiInCore
//*********************************************************************//

static void midiInputCallback( const MIDIPacketList *list, void *procRef, void */*srcRef*/ )
{
  MidiInApi::RtMidiInData *data = static_cast<MidiInApi::RtMidiInData *> (procRef);
  CoreMidiData *apiData = static_cast<CoreMidiData *> (data->apiData);

  unsigned char status;
  unsigned short nBytes, iByte, size;
  unsigned long long time;

  bool& continueSysex = data->continueSysex;
  MidiInApi::MidiMessage& message = data->message;

  const MIDIPacket *packet = &list->packet[0];
  for ( unsigned int i=0; i<list->numPackets; ++i ) {

    // My interpretation of the CoreMIDI documentation: all message
    // types, except sysex, are complete within a packet and there may
    // be several of them in a single packet.  Sysex messages can be
    // broken across multiple packets and PacketLists but are bundled
    // alone within each packet (these packets do not contain other
    // message types).  If sysex messages are split across multiple
    // MIDIPacketLists, they must be handled by multiple calls to this
    // function.

    nBytes = packet->length;
    if ( nBytes == 0 ) continue;

    // Calculate time stamp.

    /*
    if ( data->firstMessage ) {
      message.timeStamp = 0.0;
      data->firstMessage = false;
    }
    else {
      time = packet->timeStamp;
      if ( time == 0 ) { // this happens when receiving asynchronous sysex messages
        time = AudioGetCurrentHostTime();
      }
      time -= apiData->lastTime;
      time = AudioConvertHostTimeToNanos( time );
      if ( !continueSysex )
        message.timeStamp = time * 0.000000001;
    }
    apiData->lastTime = packet->timeStamp;
    if ( apiData->lastTime == 0 ) { // this happens when receiving asynchronous sysex messages
      apiData->lastTime = AudioGetCurrentHostTime();
    }
    //std::cout << "TimeStamp = " << packet->timeStamp << std::endl;
    */
      
    // 10/02/19: absolute usec based time stamp, possibly using current time if packet timestamp seems wrong...
    double packet_usec = AudioConvertHostTimeToNanos(packet->timeStamp) / 1000;
    double cur_date_usec = double(AudioConvertHostTimeToNanos(AudioGetCurrentHostTime())) / 1000.;
    double delta_usec = cur_date_usec - packet_usec;
    message.timeStamp = (delta_usec > 1000) ? cur_date_usec : packet_usec;
  
    iByte = 0;
    if ( continueSysex ) {
      // We have a continuing, segmented sysex message.
      if ( !( data->ignoreFlags & 0x01 ) ) {
        // If we're not ignoring sysex messages, copy the entire packet.
        for ( unsigned int j=0; j<nBytes; ++j )
          message.bytes.push_back( packet->data[j] );
      }
      continueSysex = packet->data[nBytes-1] != 0xF7;

      if ( !( data->ignoreFlags & 0x01 ) && !continueSysex ) {
        // If not a continuing sysex message, invoke the user callback function or queue the message.
        if ( data->usingCallback ) {
          RtMidiIn::RtMidiCallback callback = (RtMidiIn::RtMidiCallback) data->userCallback;
          callback( message.timeStamp, &message.bytes, data->userData );
        }
        else {
          // As long as we haven't reached our queue size limit, push the message.
          if (!data->queue.push(message))
            std::cerr << "\nMidiInCore: message queue limit reached!!\n\n";
        }
        message.bytes.clear();
      }
    }
    else {
      while ( iByte < nBytes ) {
        size = 0;
        // We are expecting that the next byte in the packet is a status byte.
        status = packet->data[iByte];
        if ( !(status & 0x80) ) break;
        // Determine the number of bytes in the MIDI message.
        if ( status < 0xC0 ) size = 3;
        else if ( status < 0xE0 ) size = 2;
        else if ( status < 0xF0 ) size = 3;
        else if ( status == 0xF0 ) {
          // A MIDI sysex
          if ( data->ignoreFlags & 0x01 ) {
            size = 0;
            iByte = nBytes;
          }
          else size = nBytes - iByte;
          continueSysex = packet->data[nBytes-1] != 0xF7;
        }
        else if ( status == 0xF1 ) {
            // A MIDI time code message
           if ( data->ignoreFlags & 0x02 ) {
            size = 0;
            iByte += 2;
           }
           else size = 2;
        }
        else if ( status == 0xF2 ) size = 3;
        else if ( status == 0xF3 ) size = 2;
        else if ( status == 0xF8 && ( data->ignoreFlags & 0x02 ) ) {
          // A MIDI timing tick message and we're ignoring it.
          size = 0;
          iByte += 1;
        }
        else if ( status == 0xFE && ( data->ignoreFlags & 0x04 ) ) {
          // A MIDI active sensing message and we're ignoring it.
          size = 0;
          iByte += 1;
        }
        else size = 1;

        // Copy the MIDI data to our vector.
        if ( size ) {
          message.bytes.assign( &packet->data[iByte], &packet->data[iByte+size] );
          if ( !continueSysex ) {
            // If not a continuing sysex message, invoke the user callback function or queue the message.
            if ( data->usingCallback ) {
              RtMidiIn::RtMidiCallback callback = (RtMidiIn::RtMidiCallback) data->userCallback;
              callback( message.timeStamp, &message.bytes, data->userData );
            }
            else {
              // As long as we haven't reached our queue size limit, push the message.
              if (!data->queue.push(message))
                std::cerr << "\nMidiInCore: message queue limit reached!!\n\n";
            }
            message.bytes.clear();
          }
          iByte += size;
        }
      }
    }
    packet = MIDIPacketNext(packet);
  }
}

MidiInCore :: MidiInCore( const std::string &clientName, unsigned int queueSizeLimit ) : MidiInApi( queueSizeLimit )
{
  initialize( clientName );
}

MidiInCore :: ~MidiInCore( void )
{
  // Close a connection if it exists.
  closePort();

  // Cleanup.
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);
  MIDIClientDispose( data->client );
  if ( data->endpoint ) MIDIEndpointDispose( data->endpoint );
  delete data;
}

void MidiInCore :: initialize( const std::string& clientName )
{
  // Set up our client.
  MIDIClientRef client;
  CFStringRef name = CFStringCreateWithCString( NULL, clientName.c_str(), kCFStringEncodingASCII );
  OSStatus result = MIDIClientCreate(name, NULL, NULL, &client );
  if ( result != noErr ) {
    std::ostringstream ost;
    ost << "MidiInCore::initialize: error creating OS-X MIDI client object (" << result << ").";
    errorString_ = ost.str();
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Save our api-specific connection information.
  CoreMidiData *data = (CoreMidiData *) new CoreMidiData;
  data->client = client;
  data->endpoint = 0;
  apiData_ = (void *) data;
  inputData_.apiData = (void *) data;
  CFRelease(name);
}

void MidiInCore :: openPort( unsigned int portNumber, const std::string &portName )
{
  if ( connected_ ) {
    errorString_ = "MidiInCore::openPort: a valid connection already exists!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  CFRunLoopRunInMode( kCFRunLoopDefaultMode, 0, false );
  unsigned int nSrc = MIDIGetNumberOfSources();
  if (nSrc < 1) {
    errorString_ = "MidiInCore::openPort: no MIDI input sources found!";
    error( RtMidiError::NO_DEVICES_FOUND, errorString_ );
    return;
  }

  if ( portNumber >= nSrc ) {
    std::ostringstream ost;
    ost << "MidiInCore::openPort: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::INVALID_PARAMETER, errorString_ );
    return;
  }

  MIDIPortRef port;
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);
  OSStatus result = MIDIInputPortCreate( data->client, 
                                         CFStringCreateWithCString( NULL, portName.c_str(), kCFStringEncodingASCII ),
                                         midiInputCallback, (void *)&inputData_, &port );
  if ( result != noErr ) {
    MIDIClientDispose( data->client );
    errorString_ = "MidiInCore::openPort: error creating OS-X MIDI input port.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Get the desired input source identifier.
  MIDIEndpointRef endpoint = MIDIGetSource( portNumber );
  if ( endpoint == 0 ) {
    MIDIPortDispose( port );
    MIDIClientDispose( data->client );
    errorString_ = "MidiInCore::openPort: error getting MIDI input source reference.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Make the connection.
  result = MIDIPortConnectSource( port, endpoint, NULL );
  if ( result != noErr ) {
    MIDIPortDispose( port );
    MIDIClientDispose( data->client );
    errorString_ = "MidiInCore::openPort: error connecting OS-X MIDI input port.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Save our api-specific port information.
  data->port = port;

  connected_ = true;
}

void MidiInCore :: openVirtualPort( const std::string &portName )
{
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);

  // Create a virtual MIDI input destination.
  MIDIEndpointRef endpoint;
  OSStatus result = MIDIDestinationCreate( data->client,
                                           CFStringCreateWithCString( NULL, portName.c_str(), kCFStringEncodingASCII ),
                                           midiInputCallback, (void *)&inputData_, &endpoint );
  if ( result != noErr ) {
    errorString_ = "MidiInCore::openVirtualPort: error creating virtual OS-X MIDI destination.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Save our api-specific connection information.
  data->endpoint = endpoint;
}

void MidiInCore :: closePort( void )
{
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);

  if ( data->endpoint ) {
    MIDIEndpointDispose( data->endpoint );
    data->endpoint = 0;
  }

  if ( data->port ) {
    MIDIPortDispose( data->port );
    data->port = 0;
  }

  connected_ = false;
}

unsigned int MidiInCore :: getPortCount()
{
  CFRunLoopRunInMode( kCFRunLoopDefaultMode, 0, false );
  return MIDIGetNumberOfSources();
}

// This function was submitted by Douglas Casey Tucker and apparently
// derived largely from PortMidi.
CFStringRef EndpointName( MIDIEndpointRef endpoint, bool isExternal )
{
  CFMutableStringRef result = CFStringCreateMutable( NULL, 0 );
  CFStringRef str;

  // Begin with the endpoint's name.
  str = NULL;
  MIDIObjectGetStringProperty( endpoint, kMIDIPropertyName, &str );
  if ( str != NULL ) {
    CFStringAppend( result, str );
    CFRelease( str );
  }

  MIDIEntityRef entity = 0;
  MIDIEndpointGetEntity( endpoint, &entity );
  if ( entity == 0 )
    // probably virtual
    return result;

  if ( CFStringGetLength( result ) == 0 ) {
    // endpoint name has zero length -- try the entity
    str = NULL;
    MIDIObjectGetStringProperty( entity, kMIDIPropertyName, &str );
    if ( str != NULL ) {
      CFStringAppend( result, str );
      CFRelease( str );
    }
  }
  // now consider the device's name
  MIDIDeviceRef device = 0;
  MIDIEntityGetDevice( entity, &device );
  if ( device == 0 )
    return result;

  str = NULL;
  MIDIObjectGetStringProperty( device, kMIDIPropertyName, &str );
  if ( CFStringGetLength( result ) == 0 ) {
      CFRelease( result );
      return str;
  }
  if ( str != NULL ) {
    // if an external device has only one entity, throw away
    // the endpoint name and just use the device name
    if ( isExternal && MIDIDeviceGetNumberOfEntities( device ) < 2 ) {
      CFRelease( result );
      return str;
    } else {
      if ( CFStringGetLength( str ) == 0 ) {
        CFRelease( str );
        return result;
      }
      // does the entity name already start with the device name?
      // (some drivers do this though they shouldn't)
      // if so, do not prepend
        if ( CFStringCompareWithOptions( result, /* endpoint name */
             str /* device name */,
             CFRangeMake(0, CFStringGetLength( str ) ), 0 ) != kCFCompareEqualTo ) {
        // prepend the device name to the entity name
        if ( CFStringGetLength( result ) > 0 )
          CFStringInsert( result, 0, CFSTR(" ") );
        CFStringInsert( result, 0, str );
      }
      CFRelease( str );
    }
  }
  return result;
}

// This function was submitted by Douglas Casey Tucker and apparently
// derived largely from PortMidi.
static CFStringRef ConnectedEndpointName( MIDIEndpointRef endpoint )
{
  CFMutableStringRef result = CFStringCreateMutable( NULL, 0 );
  CFStringRef str;
  OSStatus err;
  int i;

  // Does the endpoint have connections?
  CFDataRef connections = NULL;
  int nConnected = 0;
  bool anyStrings = false;
  err = MIDIObjectGetDataProperty( endpoint, kMIDIPropertyConnectionUniqueID, &connections );
  if ( connections != NULL ) {
    // It has connections, follow them
    // Concatenate the names of all connected devices
    nConnected = CFDataGetLength( connections ) / sizeof(MIDIUniqueID);
    if ( nConnected ) {
      const SInt32 *pid = (const SInt32 *)(CFDataGetBytePtr(connections));
      for ( i=0; i<nConnected; ++i, ++pid ) {
        MIDIUniqueID id = EndianS32_BtoN( *pid );
        MIDIObjectRef connObject;
        MIDIObjectType connObjectType;
        err = MIDIObjectFindByUniqueID( id, &connObject, &connObjectType );
        if ( err == noErr ) {
          if ( connObjectType == kMIDIObjectType_ExternalSource  ||
              connObjectType == kMIDIObjectType_ExternalDestination ) {
            // Connected to an external device's endpoint (10.3 and later).
            str = EndpointName( (MIDIEndpointRef)(connObject), true );
          } else {
            // Connected to an external device (10.2) (or something else, catch-
            str = NULL;
            MIDIObjectGetStringProperty( connObject, kMIDIPropertyName, &str );
          }
          if ( str != NULL ) {
            if ( anyStrings )
              CFStringAppend( result, CFSTR(", ") );
            else anyStrings = true;
            CFStringAppend( result, str );
            CFRelease( str );
          }
        }
      }
    }
    CFRelease( connections );
  }
  if ( anyStrings )
    return result;

  CFRelease( result );

  // Here, either the endpoint had no connections, or we failed to obtain names 
  return EndpointName( endpoint, false );
}

std::string MidiInCore :: getPortName( unsigned int portNumber )
{
  CFStringRef nameRef;
  MIDIEndpointRef portRef;
  char name[128];

  std::string stringName;
  CFRunLoopRunInMode( kCFRunLoopDefaultMode, 0, false );
  if ( portNumber >= MIDIGetNumberOfSources() ) {
    std::ostringstream ost;
    ost << "MidiInCore::getPortName: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::WARNING, errorString_ );
    return stringName;
  }

  portRef = MIDIGetSource( portNumber );
  nameRef = ConnectedEndpointName(portRef);
  CFStringGetCString( nameRef, name, sizeof(name), kCFStringEncodingUTF8);
  CFRelease( nameRef );

  return stringName = name;
}

//*********************************************************************//
//  API: OS-X
//  Class Definitions: MidiOutCore
//*********************************************************************//

MidiOutCore :: MidiOutCore( const std::string &clientName ) : MidiOutApi()
{
  initialize( clientName );
}

MidiOutCore :: ~MidiOutCore( void )
{
  // Close a connection if it exists.
  closePort();

  // Cleanup.
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);
  MIDIClientDispose( data->client );
  if ( data->endpoint ) MIDIEndpointDispose( data->endpoint );
  delete data;
}

void MidiOutCore :: initialize( const std::string& clientName )
{
  // Set up our client.
  MIDIClientRef client;
  CFStringRef name = CFStringCreateWithCString( NULL, clientName.c_str(), kCFStringEncodingASCII );
  OSStatus result = MIDIClientCreate(name, NULL, NULL, &client );
  if ( result != noErr ) {
    std::ostringstream ost;
    ost << "MidiInCore::initialize: error creating OS-X MIDI client object (" << result << ").";
    errorString_ = ost.str();
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Save our api-specific connection information.
  CoreMidiData *data = (CoreMidiData *) new CoreMidiData;
  data->client = client;
  data->endpoint = 0;
  apiData_ = (void *) data;
  CFRelease( name );
}

unsigned int MidiOutCore :: getPortCount()
{
  CFRunLoopRunInMode( kCFRunLoopDefaultMode, 0, false );
  return MIDIGetNumberOfDestinations();
}

std::string MidiOutCore :: getPortName( unsigned int portNumber )
{
  CFStringRef nameRef;
  MIDIEndpointRef portRef;
  char name[128];

  std::string stringName;
  CFRunLoopRunInMode( kCFRunLoopDefaultMode, 0, false );
  if ( portNumber >= MIDIGetNumberOfDestinations() ) {
    std::ostringstream ost;
    ost << "MidiOutCore::getPortName: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::WARNING, errorString_ );
    return stringName;
  }

  portRef = MIDIGetDestination( portNumber );
  nameRef = ConnectedEndpointName(portRef);
  CFStringGetCString( nameRef, name, sizeof(name), kCFStringEncodingUTF8 );
  CFRelease( nameRef );
  
  return stringName = name;
}

void MidiOutCore :: openPort( unsigned int portNumber, const std::string &portName )
{
  if ( connected_ ) {
    errorString_ = "MidiOutCore::openPort: a valid connection already exists!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  CFRunLoopRunInMode( kCFRunLoopDefaultMode, 0, false );
  unsigned int nDest = MIDIGetNumberOfDestinations();
  if (nDest < 1) {
    errorString_ = "MidiOutCore::openPort: no MIDI output destinations found!";
    error( RtMidiError::NO_DEVICES_FOUND, errorString_ );
    return;
  }

  if ( portNumber >= nDest ) {
    std::ostringstream ost;
    ost << "MidiOutCore::openPort: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::INVALID_PARAMETER, errorString_ );
    return;
  }

  MIDIPortRef port;
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);
  CFStringRef portNameRef = CFStringCreateWithCString( NULL, portName.c_str(), kCFStringEncodingASCII );
  OSStatus result = MIDIOutputPortCreate( data->client, 
                                          portNameRef,
                                          &port );
  CFRelease( portNameRef );
  if ( result != noErr ) {
    MIDIClientDispose( data->client );
    errorString_ = "MidiOutCore::openPort: error creating OS-X MIDI output port.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Get the desired output port identifier.
  MIDIEndpointRef destination = MIDIGetDestination( portNumber );
  if ( destination == 0 ) {
    MIDIPortDispose( port );
    MIDIClientDispose( data->client );
    errorString_ = "MidiOutCore::openPort: error getting MIDI output destination reference.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Save our api-specific connection information.
  data->port = port;
  data->destinationId = destination;
  connected_ = true;
}

void MidiOutCore :: closePort( void )
{
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);

  if ( data->endpoint ) {
    MIDIEndpointDispose( data->endpoint );
    data->endpoint = 0;
  }

  if ( data->port ) {
    MIDIPortDispose( data->port );
    data->port = 0;
  }

  connected_ = false;
}

void MidiOutCore :: openVirtualPort( const std::string &portName )
{
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);

  if ( data->endpoint ) {
    errorString_ = "MidiOutCore::openVirtualPort: a virtual output port already exists!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  // Create a virtual MIDI output source.
  MIDIEndpointRef endpoint;
  OSStatus result = MIDISourceCreate( data->client,
                                      CFStringCreateWithCString( NULL, portName.c_str(), kCFStringEncodingASCII ),
                                      &endpoint );
  if ( result != noErr ) {
    errorString_ = "MidiOutCore::initialize: error creating OS-X virtual MIDI source.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Save our api-specific connection information.
  data->endpoint = endpoint;
}

void MidiOutCore :: sendMessage( const unsigned char *message, size_t size )
{
  // We use the MIDISendSysex() function to asynchronously send sysex
  // messages.  Otherwise, we use a single CoreMidi MIDIPacket.
  unsigned int nBytes = static_cast<unsigned int> (size);
  if ( nBytes == 0 ) {
    errorString_ = "MidiOutCore::sendMessage: no data in message argument!";      
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  MIDITimeStamp timeStamp = AudioGetCurrentHostTime();
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);
  OSStatus result;

  if ( message[0] != 0xF0 && nBytes > 3 ) {
    errorString_ = "MidiOutCore::sendMessage: message format problem ... not sysex but > 3 bytes?";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  Byte buffer[nBytes+(sizeof(MIDIPacketList))];
  ByteCount listSize = sizeof(buffer);
  MIDIPacketList *packetList = (MIDIPacketList*)buffer;
  MIDIPacket *packet = MIDIPacketListInit( packetList );

  ByteCount remainingBytes = nBytes;
  while (remainingBytes && packet) {
    ByteCount bytesForPacket = remainingBytes > 65535 ? 65535 : remainingBytes; // 65535 = maximum size of a MIDIPacket
    const Byte* dataStartPtr = (const Byte *) &message[nBytes - remainingBytes];
    packet = MIDIPacketListAdd( packetList, listSize, packet, timeStamp, bytesForPacket, dataStartPtr);
    remainingBytes -= bytesForPacket; 
  }

  if ( !packet ) {
    errorString_ = "MidiOutCore::sendMessage: could not allocate packet list";      
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Send to any destinations that may have connected to us.
  if ( data->endpoint ) {
    result = MIDIReceived( data->endpoint, packetList );
    if ( result != noErr ) {
      errorString_ = "MidiOutCore::sendMessage: error sending MIDI to virtual destinations.";
      error( RtMidiError::WARNING, errorString_ );
    }
  }

  // And send to an explicit destination port if we're connected.
  if ( connected_ ) {
    result = MIDISend( data->port, data->destinationId, packetList );
    if ( result != noErr ) {
      errorString_ = "MidiOutCore::sendMessage: error sending MIDI message to port.";
      error( RtMidiError::WARNING, errorString_ );
    }
  }
}

#endif  // __MACOSX_CORE__


//*********************************************************************//
//  API: LINUX ALSA SEQUENCER
//*********************************************************************//

// API information found at:
//   - http://www.alsa-project.org/documentation.php#Library

#if defined(__LINUX_ALSA__)

// The ALSA Sequencer API is based on the use of a callback function for
// MIDI input.
//
// Thanks to Pedro Lopez-Cabanillas for help with the ALSA sequencer
// time stamps and other assorted fixes!!!

// If you don't need timestamping for incoming MIDI events, define the
// preprocessor definition AVOID_TIMESTAMPING to save resources
// associated with the ALSA sequencer queues.

#include <pthread.h>
#include <sys/time.h>

// ALSA header file.
#include <alsa/asoundlib.h>

// A structure to hold variables related to the ALSA API
// implementation.
struct AlsaMidiData {
  snd_seq_t *seq;
  unsigned int portNum;
  int vport;
  snd_seq_port_subscribe_t *subscription;
  snd_midi_event_t *coder;
  unsigned int bufferSize;
  unsigned char *buffer;
  pthread_t thread;
  pthread_t dummy_thread_id;
  snd_seq_real_time_t lastTime;
  int queue_id; // an input queue is needed to get timestamped events
  int trigger_fds[2];
};

#define PORT_TYPE( pinfo, bits ) ((snd_seq_port_info_get_capability(pinfo) & (bits)) == (bits))

//*********************************************************************//
//  API: LINUX ALSA
//  Class Definitions: MidiInAlsa
//*********************************************************************//

static void *alsaMidiHandler( void *ptr )
{
  MidiInApi::RtMidiInData *data = static_cast<MidiInApi::RtMidiInData *> (ptr);
  AlsaMidiData *apiData = static_cast<AlsaMidiData *> (data->apiData);

  long nBytes;
  double time;
  bool continueSysex = false;
  bool doDecode = false;
  MidiInApi::MidiMessage message;
  int poll_fd_count;
  struct pollfd *poll_fds;

  snd_seq_event_t *ev;
  int result;
  apiData->bufferSize = 32;
  result = snd_midi_event_new( 0, &apiData->coder );
  if ( result < 0 ) {
    data->doInput = false;
    std::cerr << "\nMidiInAlsa::alsaMidiHandler: error initializing MIDI event parser!\n\n";
    return 0;
  }
  unsigned char *buffer = (unsigned char *) malloc( apiData->bufferSize );
  if ( buffer == NULL ) {
    data->doInput = false;
    snd_midi_event_free( apiData->coder );
    apiData->coder = 0;
    std::cerr << "\nMidiInAlsa::alsaMidiHandler: error initializing buffer memory!\n\n";
    return 0;
  }
  snd_midi_event_init( apiData->coder );
  snd_midi_event_no_status( apiData->coder, 1 ); // suppress running status messages

  poll_fd_count = snd_seq_poll_descriptors_count( apiData->seq, POLLIN ) + 1;
  poll_fds = (struct pollfd*)alloca( poll_fd_count * sizeof( struct pollfd ));
  snd_seq_poll_descriptors( apiData->seq, poll_fds + 1, poll_fd_count - 1, POLLIN );
  poll_fds[0].fd = apiData->trigger_fds[0];
  poll_fds[0].events = POLLIN;

  while ( data->doInput ) {

    if ( snd_seq_event_input_pending( apiData->seq, 1 ) == 0 ) {
      // No data pending
      if ( poll( poll_fds, poll_fd_count, -1) >= 0 ) {
        if ( poll_fds[0].revents & POLLIN ) {
          bool dummy;
          int res = read( poll_fds[0].fd, &dummy, sizeof(dummy) );
          (void) res;
        }
      }
      continue;
    }

    // If here, there should be data.
    result = snd_seq_event_input( apiData->seq, &ev );
    if ( result == -ENOSPC ) {
      std::cerr << "\nMidiInAlsa::alsaMidiHandler: MIDI input buffer overrun!\n\n";
      continue;
    }
    else if ( result <= 0 ) {
      std::cerr << "\nMidiInAlsa::alsaMidiHandler: unknown MIDI input error!\n";
      perror("System reports");
      continue;
    }

    // This is a bit weird, but we now have to decode an ALSA MIDI
    // event (back) into MIDI bytes.  We'll ignore non-MIDI types.
    if ( !continueSysex ) message.bytes.clear();

    doDecode = false;
    switch ( ev->type ) {

    case SND_SEQ_EVENT_PORT_SUBSCRIBED:
#if defined(__RTMIDI_DEBUG__)
      std::cout << "MidiInAlsa::alsaMidiHandler: port connection made!\n";
#endif
      break;

    case SND_SEQ_EVENT_PORT_UNSUBSCRIBED:
#if defined(__RTMIDI_DEBUG__)
      std::cerr << "MidiInAlsa::alsaMidiHandler: port connection has closed!\n";
      std::cout << "sender = " << (int) ev->data.connect.sender.client << ":"
                << (int) ev->data.connect.sender.port
                << ", dest = " << (int) ev->data.connect.dest.client << ":"
                << (int) ev->data.connect.dest.port
                << std::endl;
#endif
      break;

    case SND_SEQ_EVENT_QFRAME: // MIDI time code
      if ( !( data->ignoreFlags & 0x02 ) ) doDecode = true;
      break;

    case SND_SEQ_EVENT_TICK: // 0xF9 ... MIDI timing tick
      if ( !( data->ignoreFlags & 0x02 ) ) doDecode = true;
      break;

    case SND_SEQ_EVENT_CLOCK: // 0xF8 ... MIDI timing (clock) tick
      if ( !( data->ignoreFlags & 0x02 ) ) doDecode = true;
      break;

    case SND_SEQ_EVENT_SENSING: // Active sensing
      if ( !( data->ignoreFlags & 0x04 ) ) doDecode = true;
      break;

		case SND_SEQ_EVENT_SYSEX:
      if ( (data->ignoreFlags & 0x01) ) break;
      if ( ev->data.ext.len > apiData->bufferSize ) {
        apiData->bufferSize = ev->data.ext.len;
        free( buffer );
        buffer = (unsigned char *) malloc( apiData->bufferSize );
        if ( buffer == NULL ) {
          data->doInput = false;
          std::cerr << "\nMidiInAlsa::alsaMidiHandler: error resizing buffer memory!\n\n";
          break;
        }
      }

    default:
      doDecode = true;
    }

    if ( doDecode ) {

      nBytes = snd_midi_event_decode( apiData->coder, buffer, apiData->bufferSize, ev );
      if ( nBytes > 0 ) {
        // The ALSA sequencer has a maximum buffer size for MIDI sysex
        // events of 256 bytes.  If a device sends sysex messages larger
        // than this, they are segmented into 256 byte chunks.  So,
        // we'll watch for this and concatenate sysex chunks into a
        // single sysex message if necessary.
        if ( !continueSysex )
          message.bytes.assign( buffer, &buffer[nBytes] );
        else
          message.bytes.insert( message.bytes.end(), buffer, &buffer[nBytes] );

        continueSysex = ( ( ev->type == SND_SEQ_EVENT_SYSEX ) && ( message.bytes.back() != 0xF7 ) );
        if ( !continueSysex ) {

          // Calculate the time stamp:
          message.timeStamp = 0.0;

          // Method 1: Use the system time.
          //(void)gettimeofday(&tv, (struct timezone *)NULL);
          //time = (tv.tv_sec * 1000000) + tv.tv_usec;

          // Method 2: Use the ALSA sequencer event time data.
          // (thanks to Pedro Lopez-Cabanillas!).

          // Using method from:
          // https://www.gnu.org/software/libc/manual/html_node/Elapsed-Time.html

          // Perform the carry for the later subtraction by updating y.
          snd_seq_real_time_t &x(ev->time.time);
          snd_seq_real_time_t &y(apiData->lastTime);
          if (x.tv_nsec < y.tv_nsec) {
              int nsec = (y.tv_nsec - x.tv_nsec) / 1000000000 + 1;
              y.tv_nsec -= 1000000000 * nsec;
              y.tv_sec += nsec;
          }
          if (x.tv_nsec - y.tv_nsec > 1000000000) {
              int nsec = (x.tv_nsec - y.tv_nsec) / 1000000000;
              y.tv_nsec += 1000000000 * nsec;
              y.tv_sec -= nsec;
          }

          // Compute the time difference.
          time = x.tv_sec - y.tv_sec + (x.tv_nsec - y.tv_nsec)*1e-9;

          apiData->lastTime = ev->time.time;

          if ( data->firstMessage == true )
            data->firstMessage = false;
          else
            message.timeStamp = time;
            
          // 10/02/19: absolute usec based time stamp
          message.timeStamp *= 1000000;
        }
        else {
#if defined(__RTMIDI_DEBUG__)
          std::cerr << "\nMidiInAlsa::alsaMidiHandler: event parsing error or not a MIDI event!\n\n";
#endif
        }
      }
    }

    snd_seq_free_event( ev );
    if ( message.bytes.size() == 0 || continueSysex ) continue;

    if ( data->usingCallback ) {
      RtMidiIn::RtMidiCallback callback = (RtMidiIn::RtMidiCallback) data->userCallback;
      callback( message.timeStamp, &message.bytes, data->userData );
    }
    else {
      // As long as we haven't reached our queue size limit, push the message.
      if (!data->queue.push(message))
        std::cerr << "\nMidiInAlsa: message queue limit reached!!\n\n";
    }
  }

  if ( buffer ) free( buffer );
  snd_midi_event_free( apiData->coder );
  apiData->coder = 0;
  apiData->thread = apiData->dummy_thread_id;
  return 0;
}

MidiInAlsa :: MidiInAlsa( const std::string &clientName, unsigned int queueSizeLimit ) : MidiInApi( queueSizeLimit )
{
  initialize( clientName );
}

MidiInAlsa :: ~MidiInAlsa()
{
  // Close a connection if it exists.
  closePort();

  // Shutdown the input thread.
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( inputData_.doInput ) {
    inputData_.doInput = false;
    int res = write( data->trigger_fds[1], &inputData_.doInput, sizeof(inputData_.doInput) );
    (void) res;
    if ( !pthread_equal(data->thread, data->dummy_thread_id) )
      pthread_join( data->thread, NULL );
  }

  // Cleanup.
  close ( data->trigger_fds[0] );
  close ( data->trigger_fds[1] );
  if ( data->vport >= 0 ) snd_seq_delete_port( data->seq, data->vport );
#ifndef AVOID_TIMESTAMPING
  snd_seq_free_queue( data->seq, data->queue_id );
#endif
  snd_seq_close( data->seq );
  delete data;
}

void MidiInAlsa :: initialize( const std::string& clientName )
{
  // Set up the ALSA sequencer client.
  snd_seq_t *seq;
  int result = snd_seq_open(&seq, "default", SND_SEQ_OPEN_DUPLEX, SND_SEQ_NONBLOCK);
  if ( result < 0 ) {
    errorString_ = "MidiInAlsa::initialize: error creating ALSA sequencer client object.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Set client name.
  snd_seq_set_client_name( seq, clientName.c_str() );

  // Save our api-specific connection information.
  AlsaMidiData *data = (AlsaMidiData *) new AlsaMidiData;
  data->seq = seq;
  data->portNum = -1;
  data->vport = -1;
  data->subscription = 0;
  data->dummy_thread_id = pthread_self();
  data->thread = data->dummy_thread_id;
  data->trigger_fds[0] = -1;
  data->trigger_fds[1] = -1;
  apiData_ = (void *) data;
  inputData_.apiData = (void *) data;

   if ( pipe(data->trigger_fds) == -1 ) {
    errorString_ = "MidiInAlsa::initialize: error creating pipe objects.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Create the input queue
#ifndef AVOID_TIMESTAMPING
  data->queue_id = snd_seq_alloc_named_queue(seq, "RtMidi Queue");
  // Set arbitrary tempo (mm=100) and resolution (240)
  snd_seq_queue_tempo_t *qtempo;
  snd_seq_queue_tempo_alloca(&qtempo);
  snd_seq_queue_tempo_set_tempo(qtempo, 600000);
  snd_seq_queue_tempo_set_ppq(qtempo, 240);
  snd_seq_set_queue_tempo(data->seq, data->queue_id, qtempo);
  snd_seq_drain_output(data->seq);
#endif
}

// This function is used to count or get the pinfo structure for a given port number.
unsigned int portInfo( snd_seq_t *seq, snd_seq_port_info_t *pinfo, unsigned int type, int portNumber )
{
  snd_seq_client_info_t *cinfo;
  int client;
  int count = 0;
  snd_seq_client_info_alloca( &cinfo );

  snd_seq_client_info_set_client( cinfo, -1 );
  while ( snd_seq_query_next_client( seq, cinfo ) >= 0 ) {
    client = snd_seq_client_info_get_client( cinfo );
    if ( client == 0 ) continue;
    // Reset query info
    snd_seq_port_info_set_client( pinfo, client );
    snd_seq_port_info_set_port( pinfo, -1 );
    while ( snd_seq_query_next_port( seq, pinfo ) >= 0 ) {
      unsigned int atyp = snd_seq_port_info_get_type( pinfo );
      if ( ( ( atyp & SND_SEQ_PORT_TYPE_MIDI_GENERIC ) == 0 ) &&
           ( ( atyp & SND_SEQ_PORT_TYPE_SYNTH ) == 0 ) &&
           ( ( atyp & SND_SEQ_PORT_TYPE_APPLICATION ) == 0 ) ) continue;
	    
      unsigned int caps = snd_seq_port_info_get_capability( pinfo );
      if ( ( caps & type ) != type ) continue;
      if ( count == portNumber ) return 1;
      ++count;
    }
  }

  // If a negative portNumber was used, return the port count.
  if ( portNumber < 0 ) return count;
  return 0;
}

unsigned int MidiInAlsa :: getPortCount()
{
  snd_seq_port_info_t *pinfo;
  snd_seq_port_info_alloca( &pinfo );

  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  return portInfo( data->seq, pinfo, SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ, -1 );
}

std::string MidiInAlsa :: getPortName( unsigned int portNumber )
{
  snd_seq_client_info_t *cinfo;
  snd_seq_port_info_t *pinfo;
  snd_seq_client_info_alloca( &cinfo );
  snd_seq_port_info_alloca( &pinfo );

  std::string stringName;
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( portInfo( data->seq, pinfo, SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ, (int) portNumber ) ) {
    int cnum = snd_seq_port_info_get_client( pinfo );
    snd_seq_get_any_client_info( data->seq, cnum, cinfo );
    std::ostringstream os;
    os << snd_seq_client_info_get_name( cinfo );
    os << ":";
    os << snd_seq_port_info_get_name( pinfo );
    os << " ";                                    // These lines added to make sure devices are listed
    os << snd_seq_port_info_get_client( pinfo );  // with full portnames added to ensure individual device names
    os << ":";
    os << snd_seq_port_info_get_port( pinfo );
    stringName = os.str();
    return stringName;
  }

  // If we get here, we didn't find a match.
  errorString_ = "MidiInAlsa::getPortName: error looking for port name!";
  error( RtMidiError::WARNING, errorString_ );
  return stringName;
}

void MidiInAlsa :: openPort( unsigned int portNumber, const std::string &portName )
{
  if ( connected_ ) {
    errorString_ = "MidiInAlsa::openPort: a valid connection already exists!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  unsigned int nSrc = this->getPortCount();
  if ( nSrc < 1 ) {
    errorString_ = "MidiInAlsa::openPort: no MIDI input sources found!";
    error( RtMidiError::NO_DEVICES_FOUND, errorString_ );
    return;
  }

  snd_seq_port_info_t *src_pinfo;
  snd_seq_port_info_alloca( &src_pinfo );
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( portInfo( data->seq, src_pinfo, SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ, (int) portNumber ) == 0 ) {
    std::ostringstream ost;
    ost << "MidiInAlsa::openPort: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::INVALID_PARAMETER, errorString_ );
    return;
  }

  snd_seq_addr_t sender, receiver;
  sender.client = snd_seq_port_info_get_client( src_pinfo );
  sender.port = snd_seq_port_info_get_port( src_pinfo );
  receiver.client = snd_seq_client_id( data->seq );

  snd_seq_port_info_t *pinfo;
  snd_seq_port_info_alloca( &pinfo );
  if ( data->vport < 0 ) {
    snd_seq_port_info_set_client( pinfo, 0 );
    snd_seq_port_info_set_port( pinfo, 0 );
    snd_seq_port_info_set_capability( pinfo,
                                      SND_SEQ_PORT_CAP_WRITE |
                                      SND_SEQ_PORT_CAP_SUBS_WRITE );
    snd_seq_port_info_set_type( pinfo,
                                SND_SEQ_PORT_TYPE_MIDI_GENERIC |
                                SND_SEQ_PORT_TYPE_APPLICATION );
    snd_seq_port_info_set_midi_channels(pinfo, 16);
#ifndef AVOID_TIMESTAMPING
    snd_seq_port_info_set_timestamping(pinfo, 1);
    snd_seq_port_info_set_timestamp_real(pinfo, 1);    
    snd_seq_port_info_set_timestamp_queue(pinfo, data->queue_id);
#endif
    snd_seq_port_info_set_name(pinfo,  portName.c_str() );
    data->vport = snd_seq_create_port(data->seq, pinfo);
  
    if ( data->vport < 0 ) {
      errorString_ = "MidiInAlsa::openPort: ALSA error creating input port.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }
    data->vport = snd_seq_port_info_get_port(pinfo);
  }

  receiver.port = data->vport;

  if ( !data->subscription ) {
    // Make subscription
    if (snd_seq_port_subscribe_malloc( &data->subscription ) < 0) {
      errorString_ = "MidiInAlsa::openPort: ALSA error allocation port subscription.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }
    snd_seq_port_subscribe_set_sender(data->subscription, &sender);
    snd_seq_port_subscribe_set_dest(data->subscription, &receiver);
    if ( snd_seq_subscribe_port(data->seq, data->subscription) ) {
      snd_seq_port_subscribe_free( data->subscription );
      data->subscription = 0;
      errorString_ = "MidiInAlsa::openPort: ALSA error making port connection.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }
  }

  if ( inputData_.doInput == false ) {
    // Start the input queue
#ifndef AVOID_TIMESTAMPING
    snd_seq_start_queue( data->seq, data->queue_id, NULL );
    snd_seq_drain_output( data->seq );
#endif
    // Start our MIDI input thread.
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_attr_setschedpolicy(&attr, SCHED_OTHER);

    inputData_.doInput = true;
    int err = pthread_create(&data->thread, &attr, alsaMidiHandler, &inputData_);
    pthread_attr_destroy(&attr);
    if ( err ) {
      snd_seq_unsubscribe_port( data->seq, data->subscription );
      snd_seq_port_subscribe_free( data->subscription );
      data->subscription = 0;
      inputData_.doInput = false;
      errorString_ = "MidiInAlsa::openPort: error starting MIDI input thread!";
      error( RtMidiError::THREAD_ERROR, errorString_ );
      return;
    }
  }

  connected_ = true;
}

void MidiInAlsa :: openVirtualPort( const std::string &portName )
{
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( data->vport < 0 ) {
    snd_seq_port_info_t *pinfo;
    snd_seq_port_info_alloca( &pinfo );
    snd_seq_port_info_set_capability( pinfo,
				      SND_SEQ_PORT_CAP_WRITE |
				      SND_SEQ_PORT_CAP_SUBS_WRITE );
    snd_seq_port_info_set_type( pinfo,
				SND_SEQ_PORT_TYPE_MIDI_GENERIC |
				SND_SEQ_PORT_TYPE_APPLICATION );
    snd_seq_port_info_set_midi_channels(pinfo, 16);
#ifndef AVOID_TIMESTAMPING
    snd_seq_port_info_set_timestamping(pinfo, 1);
    snd_seq_port_info_set_timestamp_real(pinfo, 1);    
    snd_seq_port_info_set_timestamp_queue(pinfo, data->queue_id);
#endif
    snd_seq_port_info_set_name(pinfo, portName.c_str());
    data->vport = snd_seq_create_port(data->seq, pinfo);

    if ( data->vport < 0 ) {
      errorString_ = "MidiInAlsa::openVirtualPort: ALSA error creating virtual port.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }
    data->vport = snd_seq_port_info_get_port(pinfo);
  }

  if ( inputData_.doInput == false ) {
    // Wait for old thread to stop, if still running
    if ( !pthread_equal(data->thread, data->dummy_thread_id) )
      pthread_join( data->thread, NULL );

    // Start the input queue
#ifndef AVOID_TIMESTAMPING
    snd_seq_start_queue( data->seq, data->queue_id, NULL );
    snd_seq_drain_output( data->seq );
#endif
    // Start our MIDI input thread.
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_attr_setschedpolicy(&attr, SCHED_OTHER);

    inputData_.doInput = true;
    int err = pthread_create(&data->thread, &attr, alsaMidiHandler, &inputData_);
    pthread_attr_destroy(&attr);
    if ( err ) {
      if ( data->subscription ) {
        snd_seq_unsubscribe_port( data->seq, data->subscription );
        snd_seq_port_subscribe_free( data->subscription );
        data->subscription = 0;
      }
      inputData_.doInput = false;
      errorString_ = "MidiInAlsa::openPort: error starting MIDI input thread!";
      error( RtMidiError::THREAD_ERROR, errorString_ );
      return;
    }
  }
}

void MidiInAlsa :: closePort( void )
{
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);

  if ( connected_ ) {
    if ( data->subscription ) {
      snd_seq_unsubscribe_port( data->seq, data->subscription );
      snd_seq_port_subscribe_free( data->subscription );
      data->subscription = 0;
    }
    // Stop the input queue
#ifndef AVOID_TIMESTAMPING
    snd_seq_stop_queue( data->seq, data->queue_id, NULL );
    snd_seq_drain_output( data->seq );
#endif
    connected_ = false;
  }

  // Stop thread to avoid triggering the callback, while the port is intended to be closed
  if ( inputData_.doInput ) {
    inputData_.doInput = false;
    int res = write( data->trigger_fds[1], &inputData_.doInput, sizeof(inputData_.doInput) );
    (void) res;
    if ( !pthread_equal(data->thread, data->dummy_thread_id) )
      pthread_join( data->thread, NULL );
  }
}

//*********************************************************************//
//  API: LINUX ALSA
//  Class Definitions: MidiOutAlsa
//*********************************************************************//

MidiOutAlsa :: MidiOutAlsa( const std::string &clientName ) : MidiOutApi()
{
  initialize( clientName );
}

MidiOutAlsa :: ~MidiOutAlsa()
{
  // Close a connection if it exists.
  closePort();

  // Cleanup.
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( data->vport >= 0 ) snd_seq_delete_port( data->seq, data->vport );
  if ( data->coder ) snd_midi_event_free( data->coder );
  if ( data->buffer ) free( data->buffer );
  snd_seq_close( data->seq );
  delete data;
}

void MidiOutAlsa :: initialize( const std::string& clientName )
{
  // Set up the ALSA sequencer client.
  snd_seq_t *seq;
  int result1 = snd_seq_open( &seq, "default", SND_SEQ_OPEN_OUTPUT, SND_SEQ_NONBLOCK );
  if ( result1 < 0 ) {
    errorString_ = "MidiOutAlsa::initialize: error creating ALSA sequencer client object.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
	}

  // Set client name.
  snd_seq_set_client_name( seq, clientName.c_str() );

  // Save our api-specific connection information.
  AlsaMidiData *data = (AlsaMidiData *) new AlsaMidiData;
  data->seq = seq;
  data->portNum = -1;
  data->vport = -1;
  data->bufferSize = 32;
  data->coder = 0;
  data->buffer = 0;
  int result = snd_midi_event_new( data->bufferSize, &data->coder );
  if ( result < 0 ) {
    delete data;
    errorString_ = "MidiOutAlsa::initialize: error initializing MIDI event parser!\n\n";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }
  data->buffer = (unsigned char *) malloc( data->bufferSize );
  if ( data->buffer == NULL ) {
    delete data;
    errorString_ = "MidiOutAlsa::initialize: error allocating buffer memory!\n\n";
    error( RtMidiError::MEMORY_ERROR, errorString_ );
    return;
  }
  snd_midi_event_init( data->coder );
  apiData_ = (void *) data;
}

unsigned int MidiOutAlsa :: getPortCount()
{
	snd_seq_port_info_t *pinfo;
	snd_seq_port_info_alloca( &pinfo );

  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  return portInfo( data->seq, pinfo, SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE, -1 );
}

std::string MidiOutAlsa :: getPortName( unsigned int portNumber )
{
  snd_seq_client_info_t *cinfo;
  snd_seq_port_info_t *pinfo;
  snd_seq_client_info_alloca( &cinfo );
  snd_seq_port_info_alloca( &pinfo );

  std::string stringName;
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( portInfo( data->seq, pinfo, SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE, (int) portNumber ) ) {
    int cnum = snd_seq_port_info_get_client(pinfo);
    snd_seq_get_any_client_info( data->seq, cnum, cinfo );
    std::ostringstream os;
    os << snd_seq_client_info_get_name(cinfo);
    os << ":";
    os << snd_seq_port_info_get_name( pinfo );
    os << " ";                                    // These lines added to make sure devices are listed
    os << snd_seq_port_info_get_client( pinfo );  // with full portnames added to ensure individual device names
    os << ":";
    os << snd_seq_port_info_get_port(pinfo);
    stringName = os.str();
    return stringName;
  }

  // If we get here, we didn't find a match.
  errorString_ = "MidiOutAlsa::getPortName: error looking for port name!";
  error( RtMidiError::WARNING, errorString_ );
  return stringName;
}

void MidiOutAlsa :: openPort( unsigned int portNumber, const std::string &portName )
{
  if ( connected_ ) {
    errorString_ = "MidiOutAlsa::openPort: a valid connection already exists!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  unsigned int nSrc = this->getPortCount();
  if (nSrc < 1) {
    errorString_ = "MidiOutAlsa::openPort: no MIDI output sources found!";
    error( RtMidiError::NO_DEVICES_FOUND, errorString_ );
    return;
  }

	snd_seq_port_info_t *pinfo;
	snd_seq_port_info_alloca( &pinfo );
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( portInfo( data->seq, pinfo, SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE, (int) portNumber ) == 0 ) {
    std::ostringstream ost;
    ost << "MidiOutAlsa::openPort: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::INVALID_PARAMETER, errorString_ );
    return;
  }

  snd_seq_addr_t sender, receiver;
  receiver.client = snd_seq_port_info_get_client( pinfo );
  receiver.port = snd_seq_port_info_get_port( pinfo );
  sender.client = snd_seq_client_id( data->seq );

  if ( data->vport < 0 ) {
    data->vport = snd_seq_create_simple_port( data->seq, portName.c_str(),
                                              SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ,
                                              SND_SEQ_PORT_TYPE_MIDI_GENERIC|SND_SEQ_PORT_TYPE_APPLICATION );
    if ( data->vport < 0 ) {
      errorString_ = "MidiOutAlsa::openPort: ALSA error creating output port.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }
  }

  sender.port = data->vport;

  // Make subscription
  if (snd_seq_port_subscribe_malloc( &data->subscription ) < 0) {
    snd_seq_port_subscribe_free( data->subscription );
    errorString_ = "MidiOutAlsa::openPort: error allocating port subscription.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }
  snd_seq_port_subscribe_set_sender(data->subscription, &sender);
  snd_seq_port_subscribe_set_dest(data->subscription, &receiver);
  snd_seq_port_subscribe_set_time_update(data->subscription, 1);
  snd_seq_port_subscribe_set_time_real(data->subscription, 1);
  if ( snd_seq_subscribe_port(data->seq, data->subscription) ) {
    snd_seq_port_subscribe_free( data->subscription );
    errorString_ = "MidiOutAlsa::openPort: ALSA error making port connection.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  connected_ = true;
}

void MidiOutAlsa :: closePort( void )
{
  if ( connected_ ) {
    AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
    snd_seq_unsubscribe_port( data->seq, data->subscription );
    snd_seq_port_subscribe_free( data->subscription );
    data->subscription = 0;
    connected_ = false;
  }
}

void MidiOutAlsa :: openVirtualPort( const std::string &portName )
{
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( data->vport < 0 ) {
    data->vport = snd_seq_create_simple_port( data->seq, portName.c_str(),
                                              SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ,
                                              SND_SEQ_PORT_TYPE_MIDI_GENERIC|SND_SEQ_PORT_TYPE_APPLICATION );

    if ( data->vport < 0 ) {
      errorString_ = "MidiOutAlsa::openVirtualPort: ALSA error creating virtual port.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
    }
  }
}

void MidiOutAlsa :: sendMessage( const unsigned char *message, size_t size )
{
  int result;
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  unsigned int nBytes = static_cast<unsigned int> (size);
  if ( nBytes > data->bufferSize ) {
    data->bufferSize = nBytes;
    result = snd_midi_event_resize_buffer ( data->coder, nBytes);
    if ( result != 0 ) {
      errorString_ = "MidiOutAlsa::sendMessage: ALSA error resizing MIDI event buffer.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }
    free (data->buffer);
    data->buffer = (unsigned char *) malloc( data->bufferSize );
    if ( data->buffer == NULL ) {
    errorString_ = "MidiOutAlsa::initialize: error allocating buffer memory!\n\n";
    error( RtMidiError::MEMORY_ERROR, errorString_ );
    return;
    }
  }

  snd_seq_event_t ev;
  snd_seq_ev_clear(&ev);
  snd_seq_ev_set_source(&ev, data->vport);
  snd_seq_ev_set_subs(&ev);
  snd_seq_ev_set_direct(&ev);
  for ( unsigned int i=0; i<nBytes; ++i ) data->buffer[i] = message[i];
  result = snd_midi_event_encode( data->coder, data->buffer, (long)nBytes, &ev );
  if ( result < (int)nBytes ) {
    errorString_ = "MidiOutAlsa::sendMessage: event parsing error!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  // Send the event.
  result = snd_seq_event_output(data->seq, &ev);
  if ( result < 0 ) {
    errorString_ = "MidiOutAlsa::sendMessage: error sending MIDI message to port.";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }
  snd_seq_drain_output(data->seq);
}

#endif // __LINUX_ALSA__


//*********************************************************************//
//  API: Windows Multimedia Library (MM)
//*********************************************************************//

// API information deciphered from:
//  - http://msdn.microsoft.com/library/default.asp?url=/library/en-us/multimed/htm/_win32_midi_reference.asp

// Thanks to Jean-Baptiste Berruchon for the sysex code.

#if defined(__WINDOWS_MM__)

// The Windows MM API is based on the use of a callback function for
// MIDI input.  We convert the system specific time stamps to delta
// time values.

// Windows MM MIDI header files.
#include <windows.h>
#include <mmsystem.h>

// Convert a null-terminated wide string or ANSI-encoded string to UTF-8.
static std::string ConvertToUTF8(const TCHAR *str)
{
  std::string u8str;
  const WCHAR *wstr = L"";
#if defined( UNICODE ) || defined( _UNICODE )
  wstr = str;
#else
  // Convert from ANSI encoding to wide string
  int wlength = MultiByteToWideChar( CP_ACP, 0, str, -1, NULL, 0 );
  std::wstring wstrtemp;
  if ( wlength )
  {
    wstrtemp.assign( wlength - 1, 0 );
    MultiByteToWideChar( CP_ACP, 0, str, -1, &wstrtemp[0], wlength );
    wstr = &wstrtemp[0];
  }
#endif
  // Convert from wide string to UTF-8
  int length = WideCharToMultiByte( CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL );
  if ( length )
  {
    u8str.assign( length - 1, 0 );
    length = WideCharToMultiByte( CP_UTF8, 0, wstr, -1, &u8str[0], length, NULL, NULL );
  }
  return u8str;
}

#define  RT_SYSEX_BUFFER_SIZE 1024
#define  RT_SYSEX_BUFFER_COUNT 4

// A structure to hold variables related to the CoreMIDI API
// implementation.
struct WinMidiData {
  HMIDIIN inHandle;    // Handle to Midi Input Device
  HMIDIOUT outHandle;  // Handle to Midi Output Device
  DWORD lastTime;
  MidiInApi::MidiMessage message;
  LPMIDIHDR sysexBuffer[RT_SYSEX_BUFFER_COUNT];
  CRITICAL_SECTION _mutex; // [Patrice] see https://groups.google.com/forum/#!topic/mididev/6OUjHutMpEo
};

//*********************************************************************//
//  API: Windows MM
//  Class Definitions: MidiInWinMM
//*********************************************************************//

static void CALLBACK midiInputCallback( HMIDIIN /*hmin*/,
                                        UINT inputStatus, 
                                        DWORD_PTR instancePtr,
                                        DWORD_PTR midiMessage,
                                        DWORD timestamp )
{
  if ( inputStatus != MIM_DATA && inputStatus != MIM_LONGDATA && inputStatus != MIM_LONGERROR ) return;

  //MidiInApi::RtMidiInData *data = static_cast<MidiInApi::RtMidiInData *> (instancePtr);
  MidiInApi::RtMidiInData *data = (MidiInApi::RtMidiInData *)instancePtr;
  WinMidiData *apiData = static_cast<WinMidiData *> (data->apiData);

  /*
  // Calculate time stamp.
  if ( data->firstMessage == true ) {
    apiData->message.timeStamp = 0.0;
    data->firstMessage = false;
  }
  else apiData->message.timeStamp = (double) ( timestamp - apiData->lastTime ) * 0.001;
  apiData->lastTime = timestamp;
  */
    
  // 10/02/19: absolute usec based time stamp
  apiData->message.timeStamp = double(timestamp) * 1000;

  if ( inputStatus == MIM_DATA ) { // Channel or system message

    // Make sure the first byte is a status byte.
    unsigned char status = (unsigned char) (midiMessage & 0x000000FF);
    if ( !(status & 0x80) ) return;

    // Determine the number of bytes in the MIDI message.
    unsigned short nBytes = 1;
    if ( status < 0xC0 ) nBytes = 3;
    else if ( status < 0xE0 ) nBytes = 2;
    else if ( status < 0xF0 ) nBytes = 3;
    else if ( status == 0xF1 ) {
      if ( data->ignoreFlags & 0x02 ) return;
      else nBytes = 2;
    }
    else if ( status == 0xF2 ) nBytes = 3;
    else if ( status == 0xF3 ) nBytes = 2;
    else if ( status == 0xF8 && (data->ignoreFlags & 0x02) ) {
      // A MIDI timing tick message and we're ignoring it.
      return;
    }
    else if ( status == 0xFE && (data->ignoreFlags & 0x04) ) {
      // A MIDI active sensing message and we're ignoring it.
      return;
    }

    // Copy bytes to our MIDI message.
    unsigned char *ptr = (unsigned char *) &midiMessage;
    for ( int i=0; i<nBytes; ++i ) apiData->message.bytes.push_back( *ptr++ );
  }
  else { // Sysex message ( MIM_LONGDATA or MIM_LONGERROR )
    MIDIHDR *sysex = ( MIDIHDR *) midiMessage; 
    if ( !( data->ignoreFlags & 0x01 ) && inputStatus != MIM_LONGERROR ) {  
      // Sysex message and we're not ignoring it
      for ( int i=0; i<(int)sysex->dwBytesRecorded; ++i )
        apiData->message.bytes.push_back( sysex->lpData[i] );
    }

    // The WinMM API requires that the sysex buffer be requeued after
    // input of each sysex message.  Even if we are ignoring sysex
    // messages, we still need to requeue the buffer in case the user
    // decides to not ignore sysex messages in the future.  However,
    // it seems that WinMM calls this function with an empty sysex
    // buffer when an application closes and in this case, we should
    // avoid requeueing it, else the computer suddenly reboots after
    // one or two minutes.
    if ( apiData->sysexBuffer[sysex->dwUser]->dwBytesRecorded > 0 ) {
      //if ( sysex->dwBytesRecorded > 0 ) {
      EnterCriticalSection( &(apiData->_mutex) );
      MMRESULT result = midiInAddBuffer( apiData->inHandle, apiData->sysexBuffer[sysex->dwUser], sizeof(MIDIHDR) );
      LeaveCriticalSection( &(apiData->_mutex) );
      if ( result != MMSYSERR_NOERROR )
        std::cerr << "\nRtMidiIn::midiInputCallback: error sending sysex to Midi device!!\n\n";

      if ( data->ignoreFlags & 0x01 ) return;
    }
    else return;
  }

  if ( data->usingCallback ) {
    RtMidiIn::RtMidiCallback callback = (RtMidiIn::RtMidiCallback) data->userCallback;
    callback( apiData->message.timeStamp, &apiData->message.bytes, data->userData );
  }
  else {
    // As long as we haven't reached our queue size limit, push the message.
    if (!data->queue.push(apiData->message))
      std::cerr << "\nMidiInWinMM: message queue limit reached!!\n\n";
  }

  // Clear the vector for the next input message.
  apiData->message.bytes.clear();
}

MidiInWinMM :: MidiInWinMM( const std::string &clientName, unsigned int queueSizeLimit ) : MidiInApi( queueSizeLimit )
{
  initialize( clientName );
}

MidiInWinMM :: ~MidiInWinMM()
{
  // Close a connection if it exists.
  closePort();

  WinMidiData *data = static_cast<WinMidiData *> (apiData_);
  DeleteCriticalSection( &(data->_mutex) );

  // Cleanup.
  delete data;
}

void MidiInWinMM :: initialize( const std::string& /*clientName*/ )
{
  // We'll issue a warning here if no devices are available but not
  // throw an error since the user can plugin something later.
  unsigned int nDevices = midiInGetNumDevs();
  if ( nDevices == 0 ) {
    errorString_ = "MidiInWinMM::initialize: no MIDI input devices currently available.";
    error( RtMidiError::WARNING, errorString_ );
  }

  // Save our api-specific connection information.
  WinMidiData *data = (WinMidiData *) new WinMidiData;
  apiData_ = (void *) data;
  inputData_.apiData = (void *) data;
  data->message.bytes.clear();  // needs to be empty for first input message

  if ( !InitializeCriticalSectionAndSpinCount(&(data->_mutex), 0x00000400) ) {
    errorString_ = "MidiInWinMM::initialize: InitializeCriticalSectionAndSpinCount failed.";
    error( RtMidiError::WARNING, errorString_ );
  }
}

void MidiInWinMM :: openPort( unsigned int portNumber, const std::string &/*portName*/ )
{
  if ( connected_ ) {
    errorString_ = "MidiInWinMM::openPort: a valid connection already exists!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  unsigned int nDevices = midiInGetNumDevs();
  if (nDevices == 0) {
    errorString_ = "MidiInWinMM::openPort: no MIDI input sources found!";
    error( RtMidiError::NO_DEVICES_FOUND, errorString_ );
    return;
  }

  if ( portNumber >= nDevices ) {
    std::ostringstream ost;
    ost << "MidiInWinMM::openPort: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::INVALID_PARAMETER, errorString_ );
    return;
  }

  WinMidiData *data = static_cast<WinMidiData *> (apiData_);
  MMRESULT result = midiInOpen( &data->inHandle,
                                portNumber,
                                (DWORD_PTR)&midiInputCallback,
                                (DWORD_PTR)&inputData_,
                                CALLBACK_FUNCTION );
  if ( result != MMSYSERR_NOERROR ) {
    errorString_ = "MidiInWinMM::openPort: error creating Windows MM MIDI input port.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Allocate and init the sysex buffers.
  for ( int i=0; i<RT_SYSEX_BUFFER_COUNT; ++i ) {
    data->sysexBuffer[i] = (MIDIHDR*) new char[ sizeof(MIDIHDR) ];
    data->sysexBuffer[i]->lpData = new char[ RT_SYSEX_BUFFER_SIZE ];
    data->sysexBuffer[i]->dwBufferLength = RT_SYSEX_BUFFER_SIZE;
    data->sysexBuffer[i]->dwUser = i; // We use the dwUser parameter as buffer indicator
    data->sysexBuffer[i]->dwFlags = 0;

    result = midiInPrepareHeader( data->inHandle, data->sysexBuffer[i], sizeof(MIDIHDR) );
    if ( result != MMSYSERR_NOERROR ) {
      midiInClose( data->inHandle );
      data->inHandle = 0;
      errorString_ = "MidiInWinMM::openPort: error starting Windows MM MIDI input port (PrepareHeader).";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }

    // Register the buffer.
    result = midiInAddBuffer( data->inHandle, data->sysexBuffer[i], sizeof(MIDIHDR) );
    if ( result != MMSYSERR_NOERROR ) {
      midiInClose( data->inHandle );
      data->inHandle = 0;
      errorString_ = "MidiInWinMM::openPort: error starting Windows MM MIDI input port (AddBuffer).";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }
  }

  result = midiInStart( data->inHandle );
  if ( result != MMSYSERR_NOERROR ) {
    midiInClose( data->inHandle );
    data->inHandle = 0;
    errorString_ = "MidiInWinMM::openPort: error starting Windows MM MIDI input port.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  connected_ = true;
}

void MidiInWinMM :: openVirtualPort( const std::string &/*portName*/ )
{
  // This function cannot be implemented for the Windows MM MIDI API.
  errorString_ = "MidiInWinMM::openVirtualPort: cannot be implemented in Windows MM MIDI API!";
  error( RtMidiError::WARNING, errorString_ );
}

void MidiInWinMM :: closePort( void )
{
  if ( connected_ ) {
    WinMidiData *data = static_cast<WinMidiData *> (apiData_);
    EnterCriticalSection( &(data->_mutex) );
    midiInReset( data->inHandle );
    midiInStop( data->inHandle );

    for ( int i=0; i<RT_SYSEX_BUFFER_COUNT; ++i ) {
      int result = midiInUnprepareHeader(data->inHandle, data->sysexBuffer[i], sizeof(MIDIHDR));
      delete [] data->sysexBuffer[i]->lpData;
      delete [] data->sysexBuffer[i];
      if ( result != MMSYSERR_NOERROR ) {
        midiInClose( data->inHandle );
        data->inHandle = 0;
        errorString_ = "MidiInWinMM::openPort: error closing Windows MM MIDI input port (midiInUnprepareHeader).";
        error( RtMidiError::DRIVER_ERROR, errorString_ );
        return;
      }
    }

    midiInClose( data->inHandle );
    data->inHandle = 0;
    connected_ = false;
    LeaveCriticalSection( &(data->_mutex) );
  }
}

unsigned int MidiInWinMM :: getPortCount()
{
  return midiInGetNumDevs();
}

std::string MidiInWinMM :: getPortName( unsigned int portNumber )
{
  std::string stringName;
  unsigned int nDevices = midiInGetNumDevs();
  if ( portNumber >= nDevices ) {
    std::ostringstream ost;
    ost << "MidiInWinMM::getPortName: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::WARNING, errorString_ );
    return stringName;
  }

  MIDIINCAPS deviceCaps;
  midiInGetDevCaps( portNumber, &deviceCaps, sizeof(MIDIINCAPS));
  stringName = ConvertToUTF8( deviceCaps.szPname );

  // Next lines added to add the portNumber to the name so that 
  // the device's names are sure to be listed with individual names
  // even when they have the same brand name
#ifdef RTMIDI_ENSURE_UNIQUE_PORTNAMES
  std::ostringstream os;
  os << " ";
  os << portNumber;
  stringName += os.str();
#endif

  return stringName;
}

//*********************************************************************//
//  API: Windows MM
//  Class Definitions: MidiOutWinMM
//*********************************************************************//

MidiOutWinMM :: MidiOutWinMM( const std::string &clientName ) : MidiOutApi()
{
  initialize( clientName );
}

MidiOutWinMM :: ~MidiOutWinMM()
{
  // Close a connection if it exists.
  closePort();

  // Cleanup.
  WinMidiData *data = static_cast<WinMidiData *> (apiData_);
  delete data;
}

void MidiOutWinMM :: initialize( const std::string& /*clientName*/ )
{
  // We'll issue a warning here if no devices are available but not
  // throw an error since the user can plug something in later.
  unsigned int nDevices = midiOutGetNumDevs();
  if ( nDevices == 0 ) {
    errorString_ = "MidiOutWinMM::initialize: no MIDI output devices currently available.";
    error( RtMidiError::WARNING, errorString_ );
  }

  // Save our api-specific connection information.
  WinMidiData *data = (WinMidiData *) new WinMidiData;
  apiData_ = (void *) data;
}

unsigned int MidiOutWinMM :: getPortCount()
{
  return midiOutGetNumDevs();
}

std::string MidiOutWinMM :: getPortName( unsigned int portNumber )
{
  std::string stringName;
  unsigned int nDevices = midiOutGetNumDevs();
  if ( portNumber >= nDevices ) {
    std::ostringstream ost;
    ost << "MidiOutWinMM::getPortName: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::WARNING, errorString_ );
    return stringName;
  }

  MIDIOUTCAPS deviceCaps;
  midiOutGetDevCaps( portNumber, &deviceCaps, sizeof(MIDIOUTCAPS));
  stringName = ConvertToUTF8( deviceCaps.szPname );

  // Next lines added to add the portNumber to the name so that 
  // the device's names are sure to be listed with individual names
  // even when they have the same brand name
  std::ostringstream os;
#ifdef RTMIDI_ENSURE_UNIQUE_PORTNAMES
  os << " ";
  os << portNumber;
  stringName += os.str();
#endif

  return stringName;
}

void MidiOutWinMM :: openPort( unsigned int portNumber, const std::string &/*portName*/ )
{
  if ( connected_ ) {
    errorString_ = "MidiOutWinMM::openPort: a valid connection already exists!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  unsigned int nDevices = midiOutGetNumDevs();
  if (nDevices < 1) {
    errorString_ = "MidiOutWinMM::openPort: no MIDI output destinations found!";
    error( RtMidiError::NO_DEVICES_FOUND, errorString_ );
    return;
  }

  if ( portNumber >= nDevices ) {
    std::ostringstream ost;
    ost << "MidiOutWinMM::openPort: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::INVALID_PARAMETER, errorString_ );
    return;
  }

  WinMidiData *data = static_cast<WinMidiData *> (apiData_);
  MMRESULT result = midiOutOpen( &data->outHandle,
                                 portNumber,
                                 (DWORD)NULL,
                                 (DWORD)NULL,
                                 CALLBACK_NULL );
  if ( result != MMSYSERR_NOERROR ) {
    errorString_ = "MidiOutWinMM::openPort: error creating Windows MM MIDI output port.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  connected_ = true;
}

void MidiOutWinMM :: closePort( void )
{
  if ( connected_ ) {
    WinMidiData *data = static_cast<WinMidiData *> (apiData_);
    midiOutReset( data->outHandle );
    midiOutClose( data->outHandle );
    data->outHandle = 0;
    connected_ = false;
  }
}

void MidiOutWinMM :: openVirtualPort( const std::string &/*portName*/ )
{
  // This function cannot be implemented for the Windows MM MIDI API.
  errorString_ = "MidiOutWinMM::openVirtualPort: cannot be implemented in Windows MM MIDI API!";
  error( RtMidiError::WARNING, errorString_ );
}

void MidiOutWinMM :: sendMessage( const unsigned char *message, size_t size )
{
  if ( !connected_ ) return;

  unsigned int nBytes = static_cast<unsigned int>(size);
  if ( nBytes == 0 ) {
    errorString_ = "MidiOutWinMM::sendMessage: message argument is empty!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  MMRESULT result;
  WinMidiData *data = static_cast<WinMidiData *> (apiData_);
  if ( message[0] == 0xF0 ) { // Sysex message

    // Allocate buffer for sysex data.
    char *buffer = (char *) malloc( nBytes );
    if ( buffer == NULL ) {
      errorString_ = "MidiOutWinMM::sendMessage: error allocating sysex message memory!";
      error( RtMidiError::MEMORY_ERROR, errorString_ );
      return;
    }

    // Copy data to buffer.
    for ( unsigned int i=0; i<nBytes; ++i ) buffer[i] = message[i];

    // Create and prepare MIDIHDR structure.
    MIDIHDR sysex;
    sysex.lpData = (LPSTR) buffer;
    sysex.dwBufferLength = nBytes;
    sysex.dwFlags = 0;
    result = midiOutPrepareHeader( data->outHandle,  &sysex, sizeof(MIDIHDR) ); 
    if ( result != MMSYSERR_NOERROR ) {
      free( buffer );
      errorString_ = "MidiOutWinMM::sendMessage: error preparing sysex header.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }

    // Send the message.
    result = midiOutLongMsg( data->outHandle, &sysex, sizeof(MIDIHDR) );
    if ( result != MMSYSERR_NOERROR ) {
      free( buffer );
      errorString_ = "MidiOutWinMM::sendMessage: error sending sysex message.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }

    // Unprepare the buffer and MIDIHDR.
    while ( MIDIERR_STILLPLAYING == midiOutUnprepareHeader( data->outHandle, &sysex, sizeof (MIDIHDR) ) ) Sleep( 1 );
    free( buffer );
  }
  else { // Channel or system message.

    // Make sure the message size isn't too big.
    if ( nBytes > 3 ) {
      errorString_ = "MidiOutWinMM::sendMessage: message size is greater than 3 bytes (and not sysex)!";
      error( RtMidiError::WARNING, errorString_ );
      return;
    }

    // Pack MIDI bytes into double word.
    DWORD packet;
    unsigned char *ptr = (unsigned char *) &packet;
    for ( unsigned int i=0; i<nBytes; ++i ) {
      *ptr = message[i];
      ++ptr;
    }

    // Send the message immediately.
    result = midiOutShortMsg( data->outHandle, packet );
    if ( result != MMSYSERR_NOERROR ) {
      errorString_ = "MidiOutWinMM::sendMessage: error sending MIDI message.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
    }
  }
}

#endif  // __WINDOWS_MM__


//*********************************************************************//
//  API: UNIX JACK
//
//  Written primarily by Alexander Svetalkin, with updates for delta
//  time by Gary Scavone, April 2011.
//
//  *********************************************************************//

#if defined(__UNIX_JACK__)

// JACK header files
#include <jack/jack.h>
#include <jack/midiport.h>
#include <jack/ringbuffer.h>
#ifdef HAVE_SEMAPHORE
  #include <semaphore.h>
#endif

#define JACK_RINGBUFFER_SIZE 16384 // Default size for ringbuffer

struct JackMidiData {
  jack_client_t *client;
  jack_port_t *port;
  jack_ringbuffer_t *buffSize;
  jack_ringbuffer_t *buffMessage;
  jack_time_t lastTime;
#ifdef HAVE_SEMAPHORE
  sem_t sem_cleanup;
  sem_t sem_needpost;
#endif
  MidiInApi :: RtMidiInData *rtMidiIn;
  };

//*********************************************************************//
//  API: JACK
//  Class Definitions: MidiInJack
//*********************************************************************//

static int jackProcessIn( jack_nframes_t nframes, void *arg )
{
  JackMidiData *jData = (JackMidiData *) arg;
  MidiInApi :: RtMidiInData *rtData = jData->rtMidiIn;
  jack_midi_event_t event;
  jack_time_t time;

  // Is port created?
  if ( jData->port == NULL ) return 0;
  void *buff = jack_port_get_buffer( jData->port, nframes );

  // We have midi events in buffer
  int evCount = jack_midi_get_event_count( buff );
  for (int j = 0; j < evCount; j++) {
    MidiInApi::MidiMessage message;
    message.bytes.clear();

    jack_midi_event_get( &event, buff, j );

    for ( unsigned int i = 0; i < event.size; i++ )
      message.bytes.push_back( event.buffer[i] );

    // Compute the delta time.
    time = jack_get_time();
    if ( rtData->firstMessage == true )
      rtData->firstMessage = false;
    else
      message.timeStamp = ( time - jData->lastTime ) * 0.000001;

    jData->lastTime = time;

    if ( !rtData->continueSysex ) {
      if ( rtData->usingCallback ) {
        RtMidiIn::RtMidiCallback callback = (RtMidiIn::RtMidiCallback) rtData->userCallback;
        callback( message.timeStamp, &message.bytes, rtData->userData );
      }
      else {
        // As long as we haven't reached our queue size limit, push the message.
        if (!rtData->queue.push(message))
          std::cerr << "\nMidiInJack: message queue limit reached!!\n\n";
      }
    }
  }

  return 0;
}

MidiInJack :: MidiInJack( const std::string &clientName, unsigned int queueSizeLimit ) : MidiInApi( queueSizeLimit )
{
  initialize( clientName );
}

void MidiInJack :: initialize( const std::string& clientName )
{
  JackMidiData *data = new JackMidiData;
  apiData_ = (void *) data;

  data->rtMidiIn = &inputData_;
  data->port = NULL;
  data->client = NULL;
  this->clientName = clientName;

  connect();
}

void MidiInJack :: connect()
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);
  if ( data->client )
    return;

  // Initialize JACK client
  if (( data->client = jack_client_open( clientName.c_str(), JackNoStartServer, NULL )) == 0) {
    errorString_ = "MidiInJack::initialize: JACK server not running?";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  jack_set_process_callback( data->client, jackProcessIn, data );
  jack_activate( data->client );
}

MidiInJack :: ~MidiInJack()
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);
  closePort();

  if ( data->client )
    jack_client_close( data->client );
  delete data;
}

void MidiInJack :: openPort( unsigned int portNumber, const std::string &portName )
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);

  connect();

  // Creating new port
  if ( data->port == NULL)
    data->port = jack_port_register( data->client, portName.c_str(),
                                     JACK_DEFAULT_MIDI_TYPE, JackPortIsInput, 0 );

  if ( data->port == NULL) {
    errorString_ = "MidiInJack::openPort: JACK error creating port";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Connecting to the output
  std::string name = getPortName( portNumber );
  jack_connect( data->client, name.c_str(), jack_port_name( data->port ) );
}

void MidiInJack :: openVirtualPort( const std::string &portName )
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);

  connect();
  if ( data->port == NULL )
    data->port = jack_port_register( data->client, portName.c_str(),
                                     JACK_DEFAULT_MIDI_TYPE, JackPortIsInput, 0 );

  if ( data->port == NULL ) {
    errorString_ = "MidiInJack::openVirtualPort: JACK error creating virtual port";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
  }
}

unsigned int MidiInJack :: getPortCount()
{
  int count = 0;
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);
  connect();
  if ( !data->client )
    return 0;

  // List of available ports
  const char **ports = jack_get_ports( data->client, NULL, JACK_DEFAULT_MIDI_TYPE, JackPortIsOutput );

  if ( ports == NULL ) return 0;
  while ( ports[count] != NULL )
    count++;

  free( ports );

  return count;
}

std::string MidiInJack :: getPortName( unsigned int portNumber )
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);
  std::string retStr("");

  connect();

  // List of available ports
  const char **ports = jack_get_ports( data->client, NULL,
                                       JACK_DEFAULT_MIDI_TYPE, JackPortIsOutput );

  // Check port validity
  if ( ports == NULL ) {
    errorString_ = "MidiInJack::getPortName: no ports available!";
    error( RtMidiError::WARNING, errorString_ );
    return retStr;
  }

  if ( ports[portNumber] == NULL ) {
    std::ostringstream ost;
    ost << "MidiInJack::getPortName: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::WARNING, errorString_ );
  }
  else retStr.assign( ports[portNumber] );

  free( ports );
  return retStr;
}

void MidiInJack :: closePort()
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);

  if ( data->port == NULL ) return;
  jack_port_unregister( data->client, data->port );
  data->port = NULL;
}

//*********************************************************************//
//  API: JACK
//  Class Definitions: MidiOutJack
//*********************************************************************//

// Jack process callback
static int jackProcessOut( jack_nframes_t nframes, void *arg )
{
  JackMidiData *data = (JackMidiData *) arg;
  jack_midi_data_t *midiData;
  int space;

  // Is port created?
  if ( data->port == NULL ) return 0;

  void *buff = jack_port_get_buffer( data->port, nframes );
  jack_midi_clear_buffer( buff );

  while ( jack_ringbuffer_read_space( data->buffSize ) > 0 ) {
    jack_ringbuffer_read( data->buffSize, (char *) &space, (size_t) sizeof(space) );
    midiData = jack_midi_event_reserve( buff, 0, space );

    jack_ringbuffer_read( data->buffMessage, (char *) midiData, (size_t) space );
  }

#ifdef HAVE_SEMAPHORE
  if (!sem_trywait(&data->sem_needpost))
    sem_post(&data->sem_cleanup);
#endif

  return 0;
}

MidiOutJack :: MidiOutJack( const std::string &clientName ) : MidiOutApi()
{
  initialize( clientName );
}

void MidiOutJack :: initialize( const std::string& clientName )
{
  JackMidiData *data = new JackMidiData;
  apiData_ = (void *) data;

  data->port = NULL;
  data->client = NULL;
#ifdef HAVE_SEMAPHORE
  sem_init(&data->sem_cleanup, 0, 0);
  sem_init(&data->sem_needpost, 0, 0);
#endif
  this->clientName = clientName;

  connect();
}

void MidiOutJack :: connect()
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);
  if ( data->client )
    return;
  
  // Initialize output ringbuffers  
  data->buffSize = jack_ringbuffer_create( JACK_RINGBUFFER_SIZE );
  data->buffMessage = jack_ringbuffer_create( JACK_RINGBUFFER_SIZE );

  // Initialize JACK client
  if (( data->client = jack_client_open( clientName.c_str(), JackNoStartServer, NULL )) == 0) {
    errorString_ = "MidiOutJack::initialize: JACK server not running?";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  jack_set_process_callback( data->client, jackProcessOut, data );
  jack_activate( data->client );
}

MidiOutJack :: ~MidiOutJack()
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);
  closePort();
  
  // Cleanup
  jack_ringbuffer_free( data->buffSize );
  jack_ringbuffer_free( data->buffMessage );
  if ( data->client ) {
    jack_client_close( data->client );
  }

#ifdef HAVE_SEMAPHORE
  sem_destroy(&data->sem_cleanup);
  sem_destroy(&data->sem_needpost);
#endif

  delete data;
}

void MidiOutJack :: openPort( unsigned int portNumber, const std::string &portName )
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);

  connect();

  // Creating new port
  if ( data->port == NULL )
    data->port = jack_port_register( data->client, portName.c_str(),
      JACK_DEFAULT_MIDI_TYPE, JackPortIsOutput, 0 );

  if ( data->port == NULL ) {
    errorString_ = "MidiOutJack::openPort: JACK error creating port";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Connecting to the output
  std::string name = getPortName( portNumber );
  jack_connect( data->client, jack_port_name( data->port ), name.c_str() );
}

void MidiOutJack :: openVirtualPort( const std::string &portName )
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);

  connect();
  if ( data->port == NULL )
    data->port = jack_port_register( data->client, portName.c_str(),
      JACK_DEFAULT_MIDI_TYPE, JackPortIsOutput, 0 );

  if ( data->port == NULL ) {
    errorString_ = "MidiOutJack::openVirtualPort: JACK error creating virtual port";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
  }
}

unsigned int MidiOutJack :: getPortCount()
{
  int count = 0;
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);
  connect();
  if ( !data->client )
    return 0;

  // List of available ports
  const char **ports = jack_get_ports( data->client, NULL,
    JACK_DEFAULT_MIDI_TYPE, JackPortIsInput );

  if ( ports == NULL ) return 0;
  while ( ports[count] != NULL )
    count++;

  free( ports );

  return count;
}

std::string MidiOutJack :: getPortName( unsigned int portNumber )
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);
  std::string retStr("");

  connect();

  // List of available ports
  const char **ports = jack_get_ports( data->client, NULL,
    JACK_DEFAULT_MIDI_TYPE, JackPortIsInput );

  // Check port validity
  if ( ports == NULL) {
    errorString_ = "MidiOutJack::getPortName: no ports available!";
    error( RtMidiError::WARNING, errorString_ );
    return retStr;
  }

  if ( ports[portNumber] == NULL) {
    std::ostringstream ost;
    ost << "MidiOutJack::getPortName: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::WARNING, errorString_ );
  }
  else retStr.assign( ports[portNumber] );

  free( ports );
  return retStr;
}

void MidiOutJack :: closePort()
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);

  if ( data->port == NULL ) return;

#ifdef HAVE_SEMAPHORE
  struct timespec ts;
  if (clock_gettime(CLOCK_REALTIME, &ts) != -1)
  {
    ts.tv_sec += 1; // wait max one second
    sem_post(&data->sem_needpost);
    sem_timedwait(&data->sem_cleanup, &ts);
  }
#endif

  jack_port_unregister( data->client, data->port );
  data->port = NULL;
}

void MidiOutJack :: sendMessage( const unsigned char *message, size_t size )
{
  int nBytes = static_cast<int>(size);
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);

  // Write full message to buffer
  jack_ringbuffer_write( data->buffMessage, ( const char * ) message,
                         nBytes );
  jack_ringbuffer_write( data->buffSize, ( char * ) &nBytes, sizeof( nBytes ) );
}

#endif  // __UNIX_JACK__
#endif

#define stringify_literal(x) #x
#define stringify_expanded(x) stringify_literal(x)

/******************************************************************************
 *******************************************************************************
 
 VECTOR INTRINSICS
 
 *******************************************************************************
 *******************************************************************************/


/********************END ARCHITECTURE SECTION (part 1/2)****************/

/**************************BEGIN USER SECTION **************************/

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <math.h>

static float mydsp_faustpower2_f(float value) {
	return (value * value);
	
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 private:
	
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fRec1[2];
	float fRec2[3];
	FAUSTFLOAT fHslider2;
	float fRec3[2];
	float fConst2;
	float fConst3;
	float fConst4;
	float fConst5;
	float fConst6;
	float fConst7;
	float fRec13[3];
	float fRec14[3];
	float fRec15[3];
	float fRec16[3];
	float fRec17[3];
	float fRec18[3];
	float fRec19[3];
	float fRec12[2];
	float fRec10[2];
	float fRec9[2];
	float fRec7[2];
	float fConst8;
	float fRec6[2];
	float fRec4[2];
	float fConst9;
	float fRec23[3];
	float fRec24[3];
	float fRec25[3];
	float fConst10;
	float fRec22[2];
	float fRec20[2];
	float fConst11;
	float fRec32[3];
	float fRec33[3];
	float fRec34[3];
	float fRec35[3];
	float fRec36[3];
	float fConst12;
	float fConst13;
	float fRec31[2];
	float fRec29[2];
	float fRec28[2];
	float fRec26[2];
	int IOTA;
	float fVec0[1024];
	int iConst14;
	float fRec45[2];
	float fRec43[2];
	float fRec42[2];
	float fRec40[2];
	float fRec39[2];
	float fRec37[2];
	float fRec48[2];
	float fRec46[2];
	float fRec54[2];
	float fRec52[2];
	float fRec51[2];
	float fRec49[2];
	float fVec1[1024];
	float fRec63[2];
	float fRec61[2];
	float fRec60[2];
	float fRec58[2];
	float fRec57[2];
	float fRec55[2];
	float fRec66[2];
	float fRec64[2];
	float fRec72[2];
	float fRec70[2];
	float fRec69[2];
	float fRec67[2];
	float fVec2[1024];
	float fRec81[2];
	float fRec79[2];
	float fRec78[2];
	float fRec76[2];
	float fRec75[2];
	float fRec73[2];
	float fRec84[2];
	float fRec82[2];
	float fRec90[2];
	float fRec88[2];
	float fRec87[2];
	float fRec85[2];
	float fVec3[1024];
	float fRec99[2];
	float fRec97[2];
	float fRec96[2];
	float fRec94[2];
	float fRec93[2];
	float fRec91[2];
	float fRec102[2];
	float fRec100[2];
	float fRec108[2];
	float fRec106[2];
	float fRec105[2];
	float fRec103[2];
	float fVec4[1024];
	float fRec117[2];
	float fRec115[2];
	float fRec114[2];
	float fRec112[2];
	float fRec111[2];
	float fRec109[2];
	float fRec120[2];
	float fRec118[2];
	float fRec126[2];
	float fRec124[2];
	float fRec123[2];
	float fRec121[2];
	float fVec5[1024];
	float fRec135[2];
	float fRec133[2];
	float fRec132[2];
	float fRec130[2];
	float fRec129[2];
	float fRec127[2];
	float fRec138[2];
	float fRec136[2];
	float fRec144[2];
	float fRec142[2];
	float fRec141[2];
	float fRec139[2];
	float fVec6[1024];
	float fRec153[2];
	float fRec151[2];
	float fRec150[2];
	float fRec148[2];
	float fRec147[2];
	float fRec145[2];
	float fRec156[2];
	float fRec154[2];
	float fRec162[2];
	float fRec160[2];
	float fRec159[2];
	float fRec157[2];
	float fVec7[1024];
	float fRec171[2];
	float fRec169[2];
	float fRec168[2];
	float fRec166[2];
	float fRec165[2];
	float fRec163[2];
	float fRec174[2];
	float fRec172[2];
	float fRec180[2];
	float fRec178[2];
	float fRec177[2];
	float fRec175[2];
	float fVec8[1024];
	float fRec189[2];
	float fRec187[2];
	float fRec186[2];
	float fRec184[2];
	float fRec183[2];
	float fRec181[2];
	float fRec192[2];
	float fRec190[2];
	float fRec198[2];
	float fRec196[2];
	float fRec195[2];
	float fRec193[2];
	float fVec9[1024];
	float fRec207[2];
	float fRec205[2];
	float fRec204[2];
	float fRec202[2];
	float fRec201[2];
	float fRec199[2];
	float fRec210[2];
	float fRec208[2];
	float fRec216[2];
	float fRec214[2];
	float fRec213[2];
	float fRec211[2];
	float fVec10[1024];
	float fRec225[2];
	float fRec223[2];
	float fRec222[2];
	float fRec220[2];
	float fRec219[2];
	float fRec217[2];
	float fRec228[2];
	float fRec226[2];
	float fRec234[2];
	float fRec232[2];
	float fRec231[2];
	float fRec229[2];
	float fVec11[1024];
	float fRec243[2];
	float fRec241[2];
	float fRec240[2];
	float fRec238[2];
	float fRec237[2];
	float fRec235[2];
	float fRec246[2];
	float fRec244[2];
	float fRec252[2];
	float fRec250[2];
	float fRec249[2];
	float fRec247[2];
	float fVec12[1024];
	float fRec261[2];
	float fRec259[2];
	float fRec258[2];
	float fRec256[2];
	float fRec255[2];
	float fRec253[2];
	float fRec264[2];
	float fRec262[2];
	float fRec270[2];
	float fRec268[2];
	float fRec267[2];
	float fRec265[2];
	float fVec13[1024];
	float fRec279[2];
	float fRec277[2];
	float fRec276[2];
	float fRec274[2];
	float fRec273[2];
	float fRec271[2];
	float fRec282[2];
	float fRec280[2];
	float fRec288[2];
	float fRec286[2];
	float fRec285[2];
	float fRec283[2];
	float fVec14[1024];
	float fRec297[2];
	float fRec295[2];
	float fRec294[2];
	float fRec292[2];
	float fRec291[2];
	float fRec289[2];
	float fRec300[2];
	float fRec298[2];
	float fRec306[2];
	float fRec304[2];
	float fRec303[2];
	float fRec301[2];
	float fVec15[1024];
	float fConst15;
	float fConst16;
	float fConst17;
	float fConst18;
	float fConst19;
	float fRec315[2];
	float fRec313[2];
	float fRec312[2];
	float fRec310[2];
	float fConst20;
	float fRec309[2];
	float fRec307[2];
	float fConst21;
	float fConst22;
	float fRec318[2];
	float fRec316[2];
	float fConst23;
	float fConst24;
	float fConst25;
	float fRec324[2];
	float fRec322[2];
	float fRec321[2];
	float fRec319[2];
	float fVec16[512];
	int iConst26;
	float fRec333[2];
	float fRec331[2];
	float fRec330[2];
	float fRec328[2];
	float fRec327[2];
	float fRec325[2];
	float fRec336[2];
	float fRec334[2];
	float fRec342[2];
	float fRec340[2];
	float fRec339[2];
	float fRec337[2];
	float fVec17[512];
	float fRec351[2];
	float fRec349[2];
	float fRec348[2];
	float fRec346[2];
	float fRec345[2];
	float fRec343[2];
	float fRec354[2];
	float fRec352[2];
	float fRec360[2];
	float fRec358[2];
	float fRec357[2];
	float fRec355[2];
	float fVec18[512];
	float fRec369[2];
	float fRec367[2];
	float fRec366[2];
	float fRec364[2];
	float fRec363[2];
	float fRec361[2];
	float fRec372[2];
	float fRec370[2];
	float fRec378[2];
	float fRec376[2];
	float fRec375[2];
	float fRec373[2];
	float fVec19[512];
	float fRec387[2];
	float fRec385[2];
	float fRec384[2];
	float fRec382[2];
	float fRec381[2];
	float fRec379[2];
	float fRec390[2];
	float fRec388[2];
	float fRec396[2];
	float fRec394[2];
	float fRec393[2];
	float fRec391[2];
	float fVec20[512];
	float fRec402[2];
	float fRec400[2];
	float fRec399[2];
	float fRec397[2];
	float fRec405[2];
	float fRec403[2];
	float fRec414[2];
	float fRec412[2];
	float fRec411[2];
	float fRec409[2];
	float fRec408[2];
	float fRec406[2];
	float fVec21[512];
	float fRec423[2];
	float fRec421[2];
	float fRec420[2];
	float fRec418[2];
	float fRec417[2];
	float fRec415[2];
	float fRec426[2];
	float fRec424[2];
	float fRec432[2];
	float fRec430[2];
	float fRec429[2];
	float fRec427[2];
	float fVec22[512];
	float fRec435[2];
	float fRec433[2];
	float fRec441[2];
	float fRec439[2];
	float fRec438[2];
	float fRec436[2];
	float fRec450[2];
	float fRec448[2];
	float fRec447[2];
	float fRec445[2];
	float fRec444[2];
	float fRec442[2];
	float fVec23[512];
	float fConst27;
	float fConst28;
	float fConst29;
	float fConst30;
	float fConst31;
	float fRec459[2];
	float fRec457[2];
	float fRec456[2];
	float fRec454[2];
	float fConst32;
	float fRec453[2];
	float fRec451[2];
	float fConst33;
	float fConst34;
	float fRec462[2];
	float fRec460[2];
	float fConst35;
	float fConst36;
	float fConst37;
	float fRec468[2];
	float fRec466[2];
	float fRec465[2];
	float fRec463[2];
	float fVec24[256];
	int iConst38;
	float fRec477[2];
	float fRec475[2];
	float fRec474[2];
	float fRec472[2];
	float fRec471[2];
	float fRec469[2];
	float fRec480[2];
	float fRec478[2];
	float fRec486[2];
	float fRec484[2];
	float fRec483[2];
	float fRec481[2];
	float fVec25[256];
	float fRec495[2];
	float fRec493[2];
	float fRec492[2];
	float fRec490[2];
	float fRec489[2];
	float fRec487[2];
	float fRec498[2];
	float fRec496[2];
	float fRec504[2];
	float fRec502[2];
	float fRec501[2];
	float fRec499[2];
	float fVec26[256];
	float fRec513[2];
	float fRec511[2];
	float fRec510[2];
	float fRec508[2];
	float fRec507[2];
	float fRec505[2];
	float fRec516[2];
	float fRec514[2];
	float fRec522[2];
	float fRec520[2];
	float fRec519[2];
	float fRec517[2];
	float fVec27[256];
	float fConst39;
	float fConst40;
	float fConst41;
	float fConst42;
	float fConst43;
	float fRec531[2];
	float fRec529[2];
	float fRec528[2];
	float fRec526[2];
	float fConst44;
	float fRec525[2];
	float fRec523[2];
	float fConst45;
	float fConst46;
	float fRec534[2];
	float fRec532[2];
	float fConst47;
	float fConst48;
	float fConst49;
	float fRec540[2];
	float fRec538[2];
	float fRec537[2];
	float fRec535[2];
	float fRec549[2];
	float fRec547[2];
	float fRec546[2];
	float fRec544[2];
	float fRec543[2];
	float fRec541[2];
	float fRec552[2];
	float fRec550[2];
	float fRec558[2];
	float fRec556[2];
	float fRec555[2];
	float fRec553[2];
	float fVec28[1024];
	float fRec567[2];
	float fRec565[2];
	float fRec564[2];
	float fRec562[2];
	float fRec561[2];
	float fRec559[2];
	float fRec570[2];
	float fRec568[2];
	float fRec576[2];
	float fRec574[2];
	float fRec573[2];
	float fRec571[2];
	float fVec29[1024];
	float fRec585[2];
	float fRec583[2];
	float fRec582[2];
	float fRec580[2];
	float fRec579[2];
	float fRec577[2];
	float fRec588[2];
	float fRec586[2];
	float fRec594[2];
	float fRec592[2];
	float fRec591[2];
	float fRec589[2];
	float fVec30[1024];
	float fRec603[2];
	float fRec601[2];
	float fRec600[2];
	float fRec598[2];
	float fRec597[2];
	float fRec595[2];
	float fRec606[2];
	float fRec604[2];
	float fRec612[2];
	float fRec610[2];
	float fRec609[2];
	float fRec607[2];
	float fVec31[1024];
	float fRec621[2];
	float fRec619[2];
	float fRec618[2];
	float fRec616[2];
	float fRec615[2];
	float fRec613[2];
	float fRec624[2];
	float fRec622[2];
	float fRec630[2];
	float fRec628[2];
	float fRec627[2];
	float fRec625[2];
	float fVec32[1024];
	float fRec639[2];
	float fRec637[2];
	float fRec636[2];
	float fRec634[2];
	float fRec633[2];
	float fRec631[2];
	float fRec642[2];
	float fRec640[2];
	float fRec648[2];
	float fRec646[2];
	float fRec645[2];
	float fRec643[2];
	float fVec33[1024];
	float fRec657[2];
	float fRec655[2];
	float fRec654[2];
	float fRec652[2];
	float fRec651[2];
	float fRec649[2];
	float fRec660[2];
	float fRec658[2];
	float fRec666[2];
	float fRec664[2];
	float fRec663[2];
	float fRec661[2];
	float fVec34[1024];
	float fRec675[2];
	float fRec673[2];
	float fRec672[2];
	float fRec670[2];
	float fRec669[2];
	float fRec667[2];
	float fRec678[2];
	float fRec676[2];
	float fRec684[2];
	float fRec682[2];
	float fRec681[2];
	float fRec679[2];
	float fVec35[1024];
	float fRec693[2];
	float fRec691[2];
	float fRec690[2];
	float fRec688[2];
	float fRec687[2];
	float fRec685[2];
	float fRec696[2];
	float fRec694[2];
	float fRec702[2];
	float fRec700[2];
	float fRec699[2];
	float fRec697[2];
	float fVec36[1024];
	float fRec711[2];
	float fRec709[2];
	float fRec708[2];
	float fRec706[2];
	float fRec705[2];
	float fRec703[2];
	float fRec714[2];
	float fRec712[2];
	float fRec720[2];
	float fRec718[2];
	float fRec717[2];
	float fRec715[2];
	float fVec37[1024];
	float fRec729[2];
	float fRec727[2];
	float fRec726[2];
	float fRec724[2];
	float fRec723[2];
	float fRec721[2];
	float fRec732[2];
	float fRec730[2];
	float fRec738[2];
	float fRec736[2];
	float fRec735[2];
	float fRec733[2];
	float fVec38[1024];
	float fRec747[2];
	float fRec745[2];
	float fRec744[2];
	float fRec742[2];
	float fRec741[2];
	float fRec739[2];
	float fRec750[2];
	float fRec748[2];
	float fRec756[2];
	float fRec754[2];
	float fRec753[2];
	float fRec751[2];
	float fVec39[1024];
	float fRec765[2];
	float fRec763[2];
	float fRec762[2];
	float fRec760[2];
	float fRec759[2];
	float fRec757[2];
	float fRec768[2];
	float fRec766[2];
	float fRec774[2];
	float fRec772[2];
	float fRec771[2];
	float fRec769[2];
	float fVec40[1024];
	float fRec783[2];
	float fRec781[2];
	float fRec780[2];
	float fRec778[2];
	float fRec777[2];
	float fRec775[2];
	float fRec786[2];
	float fRec784[2];
	float fRec792[2];
	float fRec790[2];
	float fRec789[2];
	float fRec787[2];
	float fVec41[1024];
	float fRec801[2];
	float fRec799[2];
	float fRec798[2];
	float fRec796[2];
	float fRec795[2];
	float fRec793[2];
	float fRec804[2];
	float fRec802[2];
	float fRec810[2];
	float fRec808[2];
	float fRec807[2];
	float fRec805[2];
	float fVec42[1024];
	float fRec819[2];
	float fRec817[2];
	float fRec816[2];
	float fRec814[2];
	float fRec813[2];
	float fRec811[2];
	float fRec822[2];
	float fRec820[2];
	float fRec828[2];
	float fRec826[2];
	float fRec825[2];
	float fRec823[2];
	float fVec43[1024];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit, Henrik Frisk");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMHLS_FullSetup_3h3p_full_2.dsp");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMHLS_FullSetup_3h3p_full_2");
		m->declare("version", "1.2");
	}

	virtual int getNumInputs() {
		return 16;
		
	}
	virtual int getNumOutputs() {
		return 45;
		
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			case 2: {
				rate = 1;
				break;
			}
			case 3: {
				rate = 1;
				break;
			}
			case 4: {
				rate = 1;
				break;
			}
			case 5: {
				rate = 1;
				break;
			}
			case 6: {
				rate = 1;
				break;
			}
			case 7: {
				rate = 1;
				break;
			}
			case 8: {
				rate = 1;
				break;
			}
			case 9: {
				rate = 1;
				break;
			}
			case 10: {
				rate = 1;
				break;
			}
			case 11: {
				rate = 1;
				break;
			}
			case 12: {
				rate = 1;
				break;
			}
			case 13: {
				rate = 1;
				break;
			}
			case 14: {
				rate = 1;
				break;
			}
			case 15: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			case 2: {
				rate = 1;
				break;
			}
			case 3: {
				rate = 1;
				break;
			}
			case 4: {
				rate = 1;
				break;
			}
			case 5: {
				rate = 1;
				break;
			}
			case 6: {
				rate = 1;
				break;
			}
			case 7: {
				rate = 1;
				break;
			}
			case 8: {
				rate = 1;
				break;
			}
			case 9: {
				rate = 1;
				break;
			}
			case 10: {
				rate = 1;
				break;
			}
			case 11: {
				rate = 1;
				break;
			}
			case 12: {
				rate = 1;
				break;
			}
			case 13: {
				rate = 1;
				break;
			}
			case 14: {
				rate = 1;
				break;
			}
			case 15: {
				rate = 1;
				break;
			}
			case 16: {
				rate = 1;
				break;
			}
			case 17: {
				rate = 1;
				break;
			}
			case 18: {
				rate = 1;
				break;
			}
			case 19: {
				rate = 1;
				break;
			}
			case 20: {
				rate = 1;
				break;
			}
			case 21: {
				rate = 1;
				break;
			}
			case 22: {
				rate = 1;
				break;
			}
			case 23: {
				rate = 1;
				break;
			}
			case 24: {
				rate = 1;
				break;
			}
			case 25: {
				rate = 1;
				break;
			}
			case 26: {
				rate = 1;
				break;
			}
			case 27: {
				rate = 1;
				break;
			}
			case 28: {
				rate = 1;
				break;
			}
			case 29: {
				rate = 1;
				break;
			}
			case 30: {
				rate = 1;
				break;
			}
			case 31: {
				rate = 1;
				break;
			}
			case 32: {
				rate = 1;
				break;
			}
			case 33: {
				rate = 1;
				break;
			}
			case 34: {
				rate = 1;
				break;
			}
			case 35: {
				rate = 1;
				break;
			}
			case 36: {
				rate = 1;
				break;
			}
			case 37: {
				rate = 1;
				break;
			}
			case 38: {
				rate = 1;
				break;
			}
			case 39: {
				rate = 1;
				break;
			}
			case 40: {
				rate = 1;
				break;
			}
			case 41: {
				rate = 1;
				break;
			}
			case 42: {
				rate = 1;
				break;
			}
			case 43: {
				rate = 1;
				break;
			}
			case 44: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int sample_rate) {
		
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = float(std::min<int>(192000, std::max<int>(1, fSampleRate)));
		fConst1 = (3.14159274f / fConst0);
		fConst2 = (1.0f / ((((8950.84668f / fConst0) + 136.906693f) / fConst0) + 1.0f));
		fConst3 = (1.0f / fConst0);
		fConst4 = (35803.3867f / fConst0);
		fConst5 = (fConst4 + 273.813385f);
		fConst6 = ((86.4433823f / fConst0) + 1.0f);
		fConst7 = (1.0f / fConst6);
		fConst8 = (172.886765f / (fConst0 * fConst6));
		fConst9 = (1.0f / ((37.2250137f / fConst0) + 1.0f));
		fConst10 = (74.4500275f / fConst0);
		fConst11 = (1.0f / ((((4157.10498f / fConst0) + 111.675041f) / fConst0) + 1.0f));
		fConst12 = (16628.4199f / fConst0);
		fConst13 = (fConst12 + 223.350082f);
		iConst14 = int(((0.00281456532f * fConst0) + 0.5f));
		fConst15 = (1.0f / ((((7981.24072f / fConst0) + 129.278961f) / fConst0) + 1.0f));
		fConst16 = (31924.9629f / fConst0);
		fConst17 = (fConst16 + 258.557922f);
		fConst18 = ((81.6271973f / fConst0) + 1.0f);
		fConst19 = (1.0f / fConst18);
		fConst20 = (163.254395f / (fConst0 * fConst18));
		fConst21 = (1.0f / ((35.1510277f / fConst0) + 1.0f));
		fConst22 = (70.3020554f / fConst0);
		fConst23 = (1.0f / ((((3706.78394f / fConst0) + 105.453079f) / fConst0) + 1.0f));
		fConst24 = (14827.1357f / fConst0);
		fConst25 = (fConst24 + 210.906158f);
		iConst26 = int(((0.00202205847f * fConst0) + 0.5f));
		fConst27 = (1.0f / ((((6728.72266f / fConst0) + 118.702255f) / fConst0) + 1.0f));
		fConst28 = (26914.8906f / fConst0);
		fConst29 = (fConst28 + 237.40451f);
		fConst30 = ((74.949028f / fConst0) + 1.0f);
		fConst31 = (1.0f / fConst30);
		fConst32 = (149.898056f / (fConst0 * fConst30));
		fConst33 = (1.0f / ((32.2752151f / fConst0) + 1.0f));
		fConst34 = (64.5504303f / fConst0);
		fConst35 = (1.0f / ((((3125.06836f / fConst0) + 96.8256378f) / fConst0) + 1.0f));
		fConst36 = (12500.2734f / fConst0);
		fConst37 = (fConst36 + 193.651276f);
		iConst38 = int(((0.000754629844f * fConst0) + 0.5f));
		fConst39 = (1.0f / ((((6118.1543f / fConst0) + 113.188644f) / fConst0) + 1.0f));
		fConst40 = (24472.6172f / fConst0);
		fConst41 = (fConst40 + 226.377289f);
		fConst42 = ((71.4677124f / fConst0) + 1.0f);
		fConst43 = (1.0f / fConst42);
		fConst44 = (142.935425f / (fConst0 * fConst42));
		fConst45 = (1.0f / ((30.7760601f / fConst0) + 1.0f));
		fConst46 = (61.5521202f / fConst0);
		fConst47 = (1.0f / ((((2841.49756f / fConst0) + 92.3281784f) / fConst0) + 1.0f));
		fConst48 = (11365.9902f / fConst0);
		fConst49 = (fConst48 + 184.656357f);
		
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(-10.0f);
		fHslider1 = FAUSTFLOAT(400.0f);
		fHslider2 = FAUSTFLOAT(0.0f);
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
			
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0f;
			
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0f;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
			
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec13[l4] = 0.0f;
			
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec14[l5] = 0.0f;
			
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec15[l6] = 0.0f;
			
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec16[l7] = 0.0f;
			
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec17[l8] = 0.0f;
			
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec18[l9] = 0.0f;
			
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec19[l10] = 0.0f;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec12[l11] = 0.0f;
			
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec10[l12] = 0.0f;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec9[l13] = 0.0f;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec7[l14] = 0.0f;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec6[l15] = 0.0f;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec4[l16] = 0.0f;
			
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec23[l17] = 0.0f;
			
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec24[l18] = 0.0f;
			
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec25[l19] = 0.0f;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec22[l20] = 0.0f;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec20[l21] = 0.0f;
			
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec32[l22] = 0.0f;
			
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec33[l23] = 0.0f;
			
		}
		for (int l24 = 0; (l24 < 3); l24 = (l24 + 1)) {
			fRec34[l24] = 0.0f;
			
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec35[l25] = 0.0f;
			
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec36[l26] = 0.0f;
			
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec31[l27] = 0.0f;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec29[l28] = 0.0f;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec28[l29] = 0.0f;
			
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec26[l30] = 0.0f;
			
		}
		IOTA = 0;
		for (int l31 = 0; (l31 < 1024); l31 = (l31 + 1)) {
			fVec0[l31] = 0.0f;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec45[l32] = 0.0f;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec43[l33] = 0.0f;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec42[l34] = 0.0f;
			
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec40[l35] = 0.0f;
			
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec39[l36] = 0.0f;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec37[l37] = 0.0f;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec48[l38] = 0.0f;
			
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec46[l39] = 0.0f;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec54[l40] = 0.0f;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec52[l41] = 0.0f;
			
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec51[l42] = 0.0f;
			
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec49[l43] = 0.0f;
			
		}
		for (int l44 = 0; (l44 < 1024); l44 = (l44 + 1)) {
			fVec1[l44] = 0.0f;
			
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec63[l45] = 0.0f;
			
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec61[l46] = 0.0f;
			
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec60[l47] = 0.0f;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec58[l48] = 0.0f;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec57[l49] = 0.0f;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec55[l50] = 0.0f;
			
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec66[l51] = 0.0f;
			
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec64[l52] = 0.0f;
			
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fRec72[l53] = 0.0f;
			
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec70[l54] = 0.0f;
			
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec69[l55] = 0.0f;
			
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fRec67[l56] = 0.0f;
			
		}
		for (int l57 = 0; (l57 < 1024); l57 = (l57 + 1)) {
			fVec2[l57] = 0.0f;
			
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec81[l58] = 0.0f;
			
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec79[l59] = 0.0f;
			
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			fRec78[l60] = 0.0f;
			
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec76[l61] = 0.0f;
			
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec75[l62] = 0.0f;
			
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec73[l63] = 0.0f;
			
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec84[l64] = 0.0f;
			
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec82[l65] = 0.0f;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec90[l66] = 0.0f;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec88[l67] = 0.0f;
			
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec87[l68] = 0.0f;
			
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec85[l69] = 0.0f;
			
		}
		for (int l70 = 0; (l70 < 1024); l70 = (l70 + 1)) {
			fVec3[l70] = 0.0f;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec99[l71] = 0.0f;
			
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec97[l72] = 0.0f;
			
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec96[l73] = 0.0f;
			
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec94[l74] = 0.0f;
			
		}
		for (int l75 = 0; (l75 < 2); l75 = (l75 + 1)) {
			fRec93[l75] = 0.0f;
			
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec91[l76] = 0.0f;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec102[l77] = 0.0f;
			
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec100[l78] = 0.0f;
			
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fRec108[l79] = 0.0f;
			
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec106[l80] = 0.0f;
			
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec105[l81] = 0.0f;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec103[l82] = 0.0f;
			
		}
		for (int l83 = 0; (l83 < 1024); l83 = (l83 + 1)) {
			fVec4[l83] = 0.0f;
			
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec117[l84] = 0.0f;
			
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec115[l85] = 0.0f;
			
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec114[l86] = 0.0f;
			
		}
		for (int l87 = 0; (l87 < 2); l87 = (l87 + 1)) {
			fRec112[l87] = 0.0f;
			
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			fRec111[l88] = 0.0f;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec109[l89] = 0.0f;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec120[l90] = 0.0f;
			
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec118[l91] = 0.0f;
			
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec126[l92] = 0.0f;
			
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec124[l93] = 0.0f;
			
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec123[l94] = 0.0f;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec121[l95] = 0.0f;
			
		}
		for (int l96 = 0; (l96 < 1024); l96 = (l96 + 1)) {
			fVec5[l96] = 0.0f;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec135[l97] = 0.0f;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec133[l98] = 0.0f;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec132[l99] = 0.0f;
			
		}
		for (int l100 = 0; (l100 < 2); l100 = (l100 + 1)) {
			fRec130[l100] = 0.0f;
			
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fRec129[l101] = 0.0f;
			
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec127[l102] = 0.0f;
			
		}
		for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) {
			fRec138[l103] = 0.0f;
			
		}
		for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) {
			fRec136[l104] = 0.0f;
			
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fRec144[l105] = 0.0f;
			
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec142[l106] = 0.0f;
			
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fRec141[l107] = 0.0f;
			
		}
		for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) {
			fRec139[l108] = 0.0f;
			
		}
		for (int l109 = 0; (l109 < 1024); l109 = (l109 + 1)) {
			fVec6[l109] = 0.0f;
			
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec153[l110] = 0.0f;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec151[l111] = 0.0f;
			
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec150[l112] = 0.0f;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec148[l113] = 0.0f;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec147[l114] = 0.0f;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec145[l115] = 0.0f;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec156[l116] = 0.0f;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec154[l117] = 0.0f;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec162[l118] = 0.0f;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec160[l119] = 0.0f;
			
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec159[l120] = 0.0f;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec157[l121] = 0.0f;
			
		}
		for (int l122 = 0; (l122 < 1024); l122 = (l122 + 1)) {
			fVec7[l122] = 0.0f;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec171[l123] = 0.0f;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec169[l124] = 0.0f;
			
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fRec168[l125] = 0.0f;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec166[l126] = 0.0f;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec165[l127] = 0.0f;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec163[l128] = 0.0f;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec174[l129] = 0.0f;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec172[l130] = 0.0f;
			
		}
		for (int l131 = 0; (l131 < 2); l131 = (l131 + 1)) {
			fRec180[l131] = 0.0f;
			
		}
		for (int l132 = 0; (l132 < 2); l132 = (l132 + 1)) {
			fRec178[l132] = 0.0f;
			
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec177[l133] = 0.0f;
			
		}
		for (int l134 = 0; (l134 < 2); l134 = (l134 + 1)) {
			fRec175[l134] = 0.0f;
			
		}
		for (int l135 = 0; (l135 < 1024); l135 = (l135 + 1)) {
			fVec8[l135] = 0.0f;
			
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec189[l136] = 0.0f;
			
		}
		for (int l137 = 0; (l137 < 2); l137 = (l137 + 1)) {
			fRec187[l137] = 0.0f;
			
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec186[l138] = 0.0f;
			
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fRec184[l139] = 0.0f;
			
		}
		for (int l140 = 0; (l140 < 2); l140 = (l140 + 1)) {
			fRec183[l140] = 0.0f;
			
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fRec181[l141] = 0.0f;
			
		}
		for (int l142 = 0; (l142 < 2); l142 = (l142 + 1)) {
			fRec192[l142] = 0.0f;
			
		}
		for (int l143 = 0; (l143 < 2); l143 = (l143 + 1)) {
			fRec190[l143] = 0.0f;
			
		}
		for (int l144 = 0; (l144 < 2); l144 = (l144 + 1)) {
			fRec198[l144] = 0.0f;
			
		}
		for (int l145 = 0; (l145 < 2); l145 = (l145 + 1)) {
			fRec196[l145] = 0.0f;
			
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fRec195[l146] = 0.0f;
			
		}
		for (int l147 = 0; (l147 < 2); l147 = (l147 + 1)) {
			fRec193[l147] = 0.0f;
			
		}
		for (int l148 = 0; (l148 < 1024); l148 = (l148 + 1)) {
			fVec9[l148] = 0.0f;
			
		}
		for (int l149 = 0; (l149 < 2); l149 = (l149 + 1)) {
			fRec207[l149] = 0.0f;
			
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec205[l150] = 0.0f;
			
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec204[l151] = 0.0f;
			
		}
		for (int l152 = 0; (l152 < 2); l152 = (l152 + 1)) {
			fRec202[l152] = 0.0f;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec201[l153] = 0.0f;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec199[l154] = 0.0f;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec210[l155] = 0.0f;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec208[l156] = 0.0f;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec216[l157] = 0.0f;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec214[l158] = 0.0f;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec213[l159] = 0.0f;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec211[l160] = 0.0f;
			
		}
		for (int l161 = 0; (l161 < 1024); l161 = (l161 + 1)) {
			fVec10[l161] = 0.0f;
			
		}
		for (int l162 = 0; (l162 < 2); l162 = (l162 + 1)) {
			fRec225[l162] = 0.0f;
			
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			fRec223[l163] = 0.0f;
			
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			fRec222[l164] = 0.0f;
			
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec220[l165] = 0.0f;
			
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec219[l166] = 0.0f;
			
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fRec217[l167] = 0.0f;
			
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec228[l168] = 0.0f;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec226[l169] = 0.0f;
			
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec234[l170] = 0.0f;
			
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fRec232[l171] = 0.0f;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec231[l172] = 0.0f;
			
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fRec229[l173] = 0.0f;
			
		}
		for (int l174 = 0; (l174 < 1024); l174 = (l174 + 1)) {
			fVec11[l174] = 0.0f;
			
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec243[l175] = 0.0f;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec241[l176] = 0.0f;
			
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec240[l177] = 0.0f;
			
		}
		for (int l178 = 0; (l178 < 2); l178 = (l178 + 1)) {
			fRec238[l178] = 0.0f;
			
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec237[l179] = 0.0f;
			
		}
		for (int l180 = 0; (l180 < 2); l180 = (l180 + 1)) {
			fRec235[l180] = 0.0f;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec246[l181] = 0.0f;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec244[l182] = 0.0f;
			
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fRec252[l183] = 0.0f;
			
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec250[l184] = 0.0f;
			
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec249[l185] = 0.0f;
			
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fRec247[l186] = 0.0f;
			
		}
		for (int l187 = 0; (l187 < 1024); l187 = (l187 + 1)) {
			fVec12[l187] = 0.0f;
			
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec261[l188] = 0.0f;
			
		}
		for (int l189 = 0; (l189 < 2); l189 = (l189 + 1)) {
			fRec259[l189] = 0.0f;
			
		}
		for (int l190 = 0; (l190 < 2); l190 = (l190 + 1)) {
			fRec258[l190] = 0.0f;
			
		}
		for (int l191 = 0; (l191 < 2); l191 = (l191 + 1)) {
			fRec256[l191] = 0.0f;
			
		}
		for (int l192 = 0; (l192 < 2); l192 = (l192 + 1)) {
			fRec255[l192] = 0.0f;
			
		}
		for (int l193 = 0; (l193 < 2); l193 = (l193 + 1)) {
			fRec253[l193] = 0.0f;
			
		}
		for (int l194 = 0; (l194 < 2); l194 = (l194 + 1)) {
			fRec264[l194] = 0.0f;
			
		}
		for (int l195 = 0; (l195 < 2); l195 = (l195 + 1)) {
			fRec262[l195] = 0.0f;
			
		}
		for (int l196 = 0; (l196 < 2); l196 = (l196 + 1)) {
			fRec270[l196] = 0.0f;
			
		}
		for (int l197 = 0; (l197 < 2); l197 = (l197 + 1)) {
			fRec268[l197] = 0.0f;
			
		}
		for (int l198 = 0; (l198 < 2); l198 = (l198 + 1)) {
			fRec267[l198] = 0.0f;
			
		}
		for (int l199 = 0; (l199 < 2); l199 = (l199 + 1)) {
			fRec265[l199] = 0.0f;
			
		}
		for (int l200 = 0; (l200 < 1024); l200 = (l200 + 1)) {
			fVec13[l200] = 0.0f;
			
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fRec279[l201] = 0.0f;
			
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec277[l202] = 0.0f;
			
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fRec276[l203] = 0.0f;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec274[l204] = 0.0f;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec273[l205] = 0.0f;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec271[l206] = 0.0f;
			
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec282[l207] = 0.0f;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec280[l208] = 0.0f;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec288[l209] = 0.0f;
			
		}
		for (int l210 = 0; (l210 < 2); l210 = (l210 + 1)) {
			fRec286[l210] = 0.0f;
			
		}
		for (int l211 = 0; (l211 < 2); l211 = (l211 + 1)) {
			fRec285[l211] = 0.0f;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec283[l212] = 0.0f;
			
		}
		for (int l213 = 0; (l213 < 1024); l213 = (l213 + 1)) {
			fVec14[l213] = 0.0f;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fRec297[l214] = 0.0f;
			
		}
		for (int l215 = 0; (l215 < 2); l215 = (l215 + 1)) {
			fRec295[l215] = 0.0f;
			
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fRec294[l216] = 0.0f;
			
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec292[l217] = 0.0f;
			
		}
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fRec291[l218] = 0.0f;
			
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec289[l219] = 0.0f;
			
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fRec300[l220] = 0.0f;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec298[l221] = 0.0f;
			
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec306[l222] = 0.0f;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec304[l223] = 0.0f;
			
		}
		for (int l224 = 0; (l224 < 2); l224 = (l224 + 1)) {
			fRec303[l224] = 0.0f;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec301[l225] = 0.0f;
			
		}
		for (int l226 = 0; (l226 < 1024); l226 = (l226 + 1)) {
			fVec15[l226] = 0.0f;
			
		}
		for (int l227 = 0; (l227 < 2); l227 = (l227 + 1)) {
			fRec315[l227] = 0.0f;
			
		}
		for (int l228 = 0; (l228 < 2); l228 = (l228 + 1)) {
			fRec313[l228] = 0.0f;
			
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fRec312[l229] = 0.0f;
			
		}
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec310[l230] = 0.0f;
			
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fRec309[l231] = 0.0f;
			
		}
		for (int l232 = 0; (l232 < 2); l232 = (l232 + 1)) {
			fRec307[l232] = 0.0f;
			
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fRec318[l233] = 0.0f;
			
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec316[l234] = 0.0f;
			
		}
		for (int l235 = 0; (l235 < 2); l235 = (l235 + 1)) {
			fRec324[l235] = 0.0f;
			
		}
		for (int l236 = 0; (l236 < 2); l236 = (l236 + 1)) {
			fRec322[l236] = 0.0f;
			
		}
		for (int l237 = 0; (l237 < 2); l237 = (l237 + 1)) {
			fRec321[l237] = 0.0f;
			
		}
		for (int l238 = 0; (l238 < 2); l238 = (l238 + 1)) {
			fRec319[l238] = 0.0f;
			
		}
		for (int l239 = 0; (l239 < 512); l239 = (l239 + 1)) {
			fVec16[l239] = 0.0f;
			
		}
		for (int l240 = 0; (l240 < 2); l240 = (l240 + 1)) {
			fRec333[l240] = 0.0f;
			
		}
		for (int l241 = 0; (l241 < 2); l241 = (l241 + 1)) {
			fRec331[l241] = 0.0f;
			
		}
		for (int l242 = 0; (l242 < 2); l242 = (l242 + 1)) {
			fRec330[l242] = 0.0f;
			
		}
		for (int l243 = 0; (l243 < 2); l243 = (l243 + 1)) {
			fRec328[l243] = 0.0f;
			
		}
		for (int l244 = 0; (l244 < 2); l244 = (l244 + 1)) {
			fRec327[l244] = 0.0f;
			
		}
		for (int l245 = 0; (l245 < 2); l245 = (l245 + 1)) {
			fRec325[l245] = 0.0f;
			
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fRec336[l246] = 0.0f;
			
		}
		for (int l247 = 0; (l247 < 2); l247 = (l247 + 1)) {
			fRec334[l247] = 0.0f;
			
		}
		for (int l248 = 0; (l248 < 2); l248 = (l248 + 1)) {
			fRec342[l248] = 0.0f;
			
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fRec340[l249] = 0.0f;
			
		}
		for (int l250 = 0; (l250 < 2); l250 = (l250 + 1)) {
			fRec339[l250] = 0.0f;
			
		}
		for (int l251 = 0; (l251 < 2); l251 = (l251 + 1)) {
			fRec337[l251] = 0.0f;
			
		}
		for (int l252 = 0; (l252 < 512); l252 = (l252 + 1)) {
			fVec17[l252] = 0.0f;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec351[l253] = 0.0f;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec349[l254] = 0.0f;
			
		}
		for (int l255 = 0; (l255 < 2); l255 = (l255 + 1)) {
			fRec348[l255] = 0.0f;
			
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec346[l256] = 0.0f;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fRec345[l257] = 0.0f;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec343[l258] = 0.0f;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec354[l259] = 0.0f;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec352[l260] = 0.0f;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec360[l261] = 0.0f;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec358[l262] = 0.0f;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec357[l263] = 0.0f;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec355[l264] = 0.0f;
			
		}
		for (int l265 = 0; (l265 < 512); l265 = (l265 + 1)) {
			fVec18[l265] = 0.0f;
			
		}
		for (int l266 = 0; (l266 < 2); l266 = (l266 + 1)) {
			fRec369[l266] = 0.0f;
			
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec367[l267] = 0.0f;
			
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec366[l268] = 0.0f;
			
		}
		for (int l269 = 0; (l269 < 2); l269 = (l269 + 1)) {
			fRec364[l269] = 0.0f;
			
		}
		for (int l270 = 0; (l270 < 2); l270 = (l270 + 1)) {
			fRec363[l270] = 0.0f;
			
		}
		for (int l271 = 0; (l271 < 2); l271 = (l271 + 1)) {
			fRec361[l271] = 0.0f;
			
		}
		for (int l272 = 0; (l272 < 2); l272 = (l272 + 1)) {
			fRec372[l272] = 0.0f;
			
		}
		for (int l273 = 0; (l273 < 2); l273 = (l273 + 1)) {
			fRec370[l273] = 0.0f;
			
		}
		for (int l274 = 0; (l274 < 2); l274 = (l274 + 1)) {
			fRec378[l274] = 0.0f;
			
		}
		for (int l275 = 0; (l275 < 2); l275 = (l275 + 1)) {
			fRec376[l275] = 0.0f;
			
		}
		for (int l276 = 0; (l276 < 2); l276 = (l276 + 1)) {
			fRec375[l276] = 0.0f;
			
		}
		for (int l277 = 0; (l277 < 2); l277 = (l277 + 1)) {
			fRec373[l277] = 0.0f;
			
		}
		for (int l278 = 0; (l278 < 512); l278 = (l278 + 1)) {
			fVec19[l278] = 0.0f;
			
		}
		for (int l279 = 0; (l279 < 2); l279 = (l279 + 1)) {
			fRec387[l279] = 0.0f;
			
		}
		for (int l280 = 0; (l280 < 2); l280 = (l280 + 1)) {
			fRec385[l280] = 0.0f;
			
		}
		for (int l281 = 0; (l281 < 2); l281 = (l281 + 1)) {
			fRec384[l281] = 0.0f;
			
		}
		for (int l282 = 0; (l282 < 2); l282 = (l282 + 1)) {
			fRec382[l282] = 0.0f;
			
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec381[l283] = 0.0f;
			
		}
		for (int l284 = 0; (l284 < 2); l284 = (l284 + 1)) {
			fRec379[l284] = 0.0f;
			
		}
		for (int l285 = 0; (l285 < 2); l285 = (l285 + 1)) {
			fRec390[l285] = 0.0f;
			
		}
		for (int l286 = 0; (l286 < 2); l286 = (l286 + 1)) {
			fRec388[l286] = 0.0f;
			
		}
		for (int l287 = 0; (l287 < 2); l287 = (l287 + 1)) {
			fRec396[l287] = 0.0f;
			
		}
		for (int l288 = 0; (l288 < 2); l288 = (l288 + 1)) {
			fRec394[l288] = 0.0f;
			
		}
		for (int l289 = 0; (l289 < 2); l289 = (l289 + 1)) {
			fRec393[l289] = 0.0f;
			
		}
		for (int l290 = 0; (l290 < 2); l290 = (l290 + 1)) {
			fRec391[l290] = 0.0f;
			
		}
		for (int l291 = 0; (l291 < 512); l291 = (l291 + 1)) {
			fVec20[l291] = 0.0f;
			
		}
		for (int l292 = 0; (l292 < 2); l292 = (l292 + 1)) {
			fRec402[l292] = 0.0f;
			
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec400[l293] = 0.0f;
			
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec399[l294] = 0.0f;
			
		}
		for (int l295 = 0; (l295 < 2); l295 = (l295 + 1)) {
			fRec397[l295] = 0.0f;
			
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec405[l296] = 0.0f;
			
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec403[l297] = 0.0f;
			
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec414[l298] = 0.0f;
			
		}
		for (int l299 = 0; (l299 < 2); l299 = (l299 + 1)) {
			fRec412[l299] = 0.0f;
			
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec411[l300] = 0.0f;
			
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec409[l301] = 0.0f;
			
		}
		for (int l302 = 0; (l302 < 2); l302 = (l302 + 1)) {
			fRec408[l302] = 0.0f;
			
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec406[l303] = 0.0f;
			
		}
		for (int l304 = 0; (l304 < 512); l304 = (l304 + 1)) {
			fVec21[l304] = 0.0f;
			
		}
		for (int l305 = 0; (l305 < 2); l305 = (l305 + 1)) {
			fRec423[l305] = 0.0f;
			
		}
		for (int l306 = 0; (l306 < 2); l306 = (l306 + 1)) {
			fRec421[l306] = 0.0f;
			
		}
		for (int l307 = 0; (l307 < 2); l307 = (l307 + 1)) {
			fRec420[l307] = 0.0f;
			
		}
		for (int l308 = 0; (l308 < 2); l308 = (l308 + 1)) {
			fRec418[l308] = 0.0f;
			
		}
		for (int l309 = 0; (l309 < 2); l309 = (l309 + 1)) {
			fRec417[l309] = 0.0f;
			
		}
		for (int l310 = 0; (l310 < 2); l310 = (l310 + 1)) {
			fRec415[l310] = 0.0f;
			
		}
		for (int l311 = 0; (l311 < 2); l311 = (l311 + 1)) {
			fRec426[l311] = 0.0f;
			
		}
		for (int l312 = 0; (l312 < 2); l312 = (l312 + 1)) {
			fRec424[l312] = 0.0f;
			
		}
		for (int l313 = 0; (l313 < 2); l313 = (l313 + 1)) {
			fRec432[l313] = 0.0f;
			
		}
		for (int l314 = 0; (l314 < 2); l314 = (l314 + 1)) {
			fRec430[l314] = 0.0f;
			
		}
		for (int l315 = 0; (l315 < 2); l315 = (l315 + 1)) {
			fRec429[l315] = 0.0f;
			
		}
		for (int l316 = 0; (l316 < 2); l316 = (l316 + 1)) {
			fRec427[l316] = 0.0f;
			
		}
		for (int l317 = 0; (l317 < 512); l317 = (l317 + 1)) {
			fVec22[l317] = 0.0f;
			
		}
		for (int l318 = 0; (l318 < 2); l318 = (l318 + 1)) {
			fRec435[l318] = 0.0f;
			
		}
		for (int l319 = 0; (l319 < 2); l319 = (l319 + 1)) {
			fRec433[l319] = 0.0f;
			
		}
		for (int l320 = 0; (l320 < 2); l320 = (l320 + 1)) {
			fRec441[l320] = 0.0f;
			
		}
		for (int l321 = 0; (l321 < 2); l321 = (l321 + 1)) {
			fRec439[l321] = 0.0f;
			
		}
		for (int l322 = 0; (l322 < 2); l322 = (l322 + 1)) {
			fRec438[l322] = 0.0f;
			
		}
		for (int l323 = 0; (l323 < 2); l323 = (l323 + 1)) {
			fRec436[l323] = 0.0f;
			
		}
		for (int l324 = 0; (l324 < 2); l324 = (l324 + 1)) {
			fRec450[l324] = 0.0f;
			
		}
		for (int l325 = 0; (l325 < 2); l325 = (l325 + 1)) {
			fRec448[l325] = 0.0f;
			
		}
		for (int l326 = 0; (l326 < 2); l326 = (l326 + 1)) {
			fRec447[l326] = 0.0f;
			
		}
		for (int l327 = 0; (l327 < 2); l327 = (l327 + 1)) {
			fRec445[l327] = 0.0f;
			
		}
		for (int l328 = 0; (l328 < 2); l328 = (l328 + 1)) {
			fRec444[l328] = 0.0f;
			
		}
		for (int l329 = 0; (l329 < 2); l329 = (l329 + 1)) {
			fRec442[l329] = 0.0f;
			
		}
		for (int l330 = 0; (l330 < 512); l330 = (l330 + 1)) {
			fVec23[l330] = 0.0f;
			
		}
		for (int l331 = 0; (l331 < 2); l331 = (l331 + 1)) {
			fRec459[l331] = 0.0f;
			
		}
		for (int l332 = 0; (l332 < 2); l332 = (l332 + 1)) {
			fRec457[l332] = 0.0f;
			
		}
		for (int l333 = 0; (l333 < 2); l333 = (l333 + 1)) {
			fRec456[l333] = 0.0f;
			
		}
		for (int l334 = 0; (l334 < 2); l334 = (l334 + 1)) {
			fRec454[l334] = 0.0f;
			
		}
		for (int l335 = 0; (l335 < 2); l335 = (l335 + 1)) {
			fRec453[l335] = 0.0f;
			
		}
		for (int l336 = 0; (l336 < 2); l336 = (l336 + 1)) {
			fRec451[l336] = 0.0f;
			
		}
		for (int l337 = 0; (l337 < 2); l337 = (l337 + 1)) {
			fRec462[l337] = 0.0f;
			
		}
		for (int l338 = 0; (l338 < 2); l338 = (l338 + 1)) {
			fRec460[l338] = 0.0f;
			
		}
		for (int l339 = 0; (l339 < 2); l339 = (l339 + 1)) {
			fRec468[l339] = 0.0f;
			
		}
		for (int l340 = 0; (l340 < 2); l340 = (l340 + 1)) {
			fRec466[l340] = 0.0f;
			
		}
		for (int l341 = 0; (l341 < 2); l341 = (l341 + 1)) {
			fRec465[l341] = 0.0f;
			
		}
		for (int l342 = 0; (l342 < 2); l342 = (l342 + 1)) {
			fRec463[l342] = 0.0f;
			
		}
		for (int l343 = 0; (l343 < 256); l343 = (l343 + 1)) {
			fVec24[l343] = 0.0f;
			
		}
		for (int l344 = 0; (l344 < 2); l344 = (l344 + 1)) {
			fRec477[l344] = 0.0f;
			
		}
		for (int l345 = 0; (l345 < 2); l345 = (l345 + 1)) {
			fRec475[l345] = 0.0f;
			
		}
		for (int l346 = 0; (l346 < 2); l346 = (l346 + 1)) {
			fRec474[l346] = 0.0f;
			
		}
		for (int l347 = 0; (l347 < 2); l347 = (l347 + 1)) {
			fRec472[l347] = 0.0f;
			
		}
		for (int l348 = 0; (l348 < 2); l348 = (l348 + 1)) {
			fRec471[l348] = 0.0f;
			
		}
		for (int l349 = 0; (l349 < 2); l349 = (l349 + 1)) {
			fRec469[l349] = 0.0f;
			
		}
		for (int l350 = 0; (l350 < 2); l350 = (l350 + 1)) {
			fRec480[l350] = 0.0f;
			
		}
		for (int l351 = 0; (l351 < 2); l351 = (l351 + 1)) {
			fRec478[l351] = 0.0f;
			
		}
		for (int l352 = 0; (l352 < 2); l352 = (l352 + 1)) {
			fRec486[l352] = 0.0f;
			
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec484[l353] = 0.0f;
			
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec483[l354] = 0.0f;
			
		}
		for (int l355 = 0; (l355 < 2); l355 = (l355 + 1)) {
			fRec481[l355] = 0.0f;
			
		}
		for (int l356 = 0; (l356 < 256); l356 = (l356 + 1)) {
			fVec25[l356] = 0.0f;
			
		}
		for (int l357 = 0; (l357 < 2); l357 = (l357 + 1)) {
			fRec495[l357] = 0.0f;
			
		}
		for (int l358 = 0; (l358 < 2); l358 = (l358 + 1)) {
			fRec493[l358] = 0.0f;
			
		}
		for (int l359 = 0; (l359 < 2); l359 = (l359 + 1)) {
			fRec492[l359] = 0.0f;
			
		}
		for (int l360 = 0; (l360 < 2); l360 = (l360 + 1)) {
			fRec490[l360] = 0.0f;
			
		}
		for (int l361 = 0; (l361 < 2); l361 = (l361 + 1)) {
			fRec489[l361] = 0.0f;
			
		}
		for (int l362 = 0; (l362 < 2); l362 = (l362 + 1)) {
			fRec487[l362] = 0.0f;
			
		}
		for (int l363 = 0; (l363 < 2); l363 = (l363 + 1)) {
			fRec498[l363] = 0.0f;
			
		}
		for (int l364 = 0; (l364 < 2); l364 = (l364 + 1)) {
			fRec496[l364] = 0.0f;
			
		}
		for (int l365 = 0; (l365 < 2); l365 = (l365 + 1)) {
			fRec504[l365] = 0.0f;
			
		}
		for (int l366 = 0; (l366 < 2); l366 = (l366 + 1)) {
			fRec502[l366] = 0.0f;
			
		}
		for (int l367 = 0; (l367 < 2); l367 = (l367 + 1)) {
			fRec501[l367] = 0.0f;
			
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec499[l368] = 0.0f;
			
		}
		for (int l369 = 0; (l369 < 256); l369 = (l369 + 1)) {
			fVec26[l369] = 0.0f;
			
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec513[l370] = 0.0f;
			
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			fRec511[l371] = 0.0f;
			
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			fRec510[l372] = 0.0f;
			
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fRec508[l373] = 0.0f;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec507[l374] = 0.0f;
			
		}
		for (int l375 = 0; (l375 < 2); l375 = (l375 + 1)) {
			fRec505[l375] = 0.0f;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec516[l376] = 0.0f;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec514[l377] = 0.0f;
			
		}
		for (int l378 = 0; (l378 < 2); l378 = (l378 + 1)) {
			fRec522[l378] = 0.0f;
			
		}
		for (int l379 = 0; (l379 < 2); l379 = (l379 + 1)) {
			fRec520[l379] = 0.0f;
			
		}
		for (int l380 = 0; (l380 < 2); l380 = (l380 + 1)) {
			fRec519[l380] = 0.0f;
			
		}
		for (int l381 = 0; (l381 < 2); l381 = (l381 + 1)) {
			fRec517[l381] = 0.0f;
			
		}
		for (int l382 = 0; (l382 < 256); l382 = (l382 + 1)) {
			fVec27[l382] = 0.0f;
			
		}
		for (int l383 = 0; (l383 < 2); l383 = (l383 + 1)) {
			fRec531[l383] = 0.0f;
			
		}
		for (int l384 = 0; (l384 < 2); l384 = (l384 + 1)) {
			fRec529[l384] = 0.0f;
			
		}
		for (int l385 = 0; (l385 < 2); l385 = (l385 + 1)) {
			fRec528[l385] = 0.0f;
			
		}
		for (int l386 = 0; (l386 < 2); l386 = (l386 + 1)) {
			fRec526[l386] = 0.0f;
			
		}
		for (int l387 = 0; (l387 < 2); l387 = (l387 + 1)) {
			fRec525[l387] = 0.0f;
			
		}
		for (int l388 = 0; (l388 < 2); l388 = (l388 + 1)) {
			fRec523[l388] = 0.0f;
			
		}
		for (int l389 = 0; (l389 < 2); l389 = (l389 + 1)) {
			fRec534[l389] = 0.0f;
			
		}
		for (int l390 = 0; (l390 < 2); l390 = (l390 + 1)) {
			fRec532[l390] = 0.0f;
			
		}
		for (int l391 = 0; (l391 < 2); l391 = (l391 + 1)) {
			fRec540[l391] = 0.0f;
			
		}
		for (int l392 = 0; (l392 < 2); l392 = (l392 + 1)) {
			fRec538[l392] = 0.0f;
			
		}
		for (int l393 = 0; (l393 < 2); l393 = (l393 + 1)) {
			fRec537[l393] = 0.0f;
			
		}
		for (int l394 = 0; (l394 < 2); l394 = (l394 + 1)) {
			fRec535[l394] = 0.0f;
			
		}
		for (int l395 = 0; (l395 < 2); l395 = (l395 + 1)) {
			fRec549[l395] = 0.0f;
			
		}
		for (int l396 = 0; (l396 < 2); l396 = (l396 + 1)) {
			fRec547[l396] = 0.0f;
			
		}
		for (int l397 = 0; (l397 < 2); l397 = (l397 + 1)) {
			fRec546[l397] = 0.0f;
			
		}
		for (int l398 = 0; (l398 < 2); l398 = (l398 + 1)) {
			fRec544[l398] = 0.0f;
			
		}
		for (int l399 = 0; (l399 < 2); l399 = (l399 + 1)) {
			fRec543[l399] = 0.0f;
			
		}
		for (int l400 = 0; (l400 < 2); l400 = (l400 + 1)) {
			fRec541[l400] = 0.0f;
			
		}
		for (int l401 = 0; (l401 < 2); l401 = (l401 + 1)) {
			fRec552[l401] = 0.0f;
			
		}
		for (int l402 = 0; (l402 < 2); l402 = (l402 + 1)) {
			fRec550[l402] = 0.0f;
			
		}
		for (int l403 = 0; (l403 < 2); l403 = (l403 + 1)) {
			fRec558[l403] = 0.0f;
			
		}
		for (int l404 = 0; (l404 < 2); l404 = (l404 + 1)) {
			fRec556[l404] = 0.0f;
			
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec555[l405] = 0.0f;
			
		}
		for (int l406 = 0; (l406 < 2); l406 = (l406 + 1)) {
			fRec553[l406] = 0.0f;
			
		}
		for (int l407 = 0; (l407 < 1024); l407 = (l407 + 1)) {
			fVec28[l407] = 0.0f;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec567[l408] = 0.0f;
			
		}
		for (int l409 = 0; (l409 < 2); l409 = (l409 + 1)) {
			fRec565[l409] = 0.0f;
			
		}
		for (int l410 = 0; (l410 < 2); l410 = (l410 + 1)) {
			fRec564[l410] = 0.0f;
			
		}
		for (int l411 = 0; (l411 < 2); l411 = (l411 + 1)) {
			fRec562[l411] = 0.0f;
			
		}
		for (int l412 = 0; (l412 < 2); l412 = (l412 + 1)) {
			fRec561[l412] = 0.0f;
			
		}
		for (int l413 = 0; (l413 < 2); l413 = (l413 + 1)) {
			fRec559[l413] = 0.0f;
			
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec570[l414] = 0.0f;
			
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec568[l415] = 0.0f;
			
		}
		for (int l416 = 0; (l416 < 2); l416 = (l416 + 1)) {
			fRec576[l416] = 0.0f;
			
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec574[l417] = 0.0f;
			
		}
		for (int l418 = 0; (l418 < 2); l418 = (l418 + 1)) {
			fRec573[l418] = 0.0f;
			
		}
		for (int l419 = 0; (l419 < 2); l419 = (l419 + 1)) {
			fRec571[l419] = 0.0f;
			
		}
		for (int l420 = 0; (l420 < 1024); l420 = (l420 + 1)) {
			fVec29[l420] = 0.0f;
			
		}
		for (int l421 = 0; (l421 < 2); l421 = (l421 + 1)) {
			fRec585[l421] = 0.0f;
			
		}
		for (int l422 = 0; (l422 < 2); l422 = (l422 + 1)) {
			fRec583[l422] = 0.0f;
			
		}
		for (int l423 = 0; (l423 < 2); l423 = (l423 + 1)) {
			fRec582[l423] = 0.0f;
			
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec580[l424] = 0.0f;
			
		}
		for (int l425 = 0; (l425 < 2); l425 = (l425 + 1)) {
			fRec579[l425] = 0.0f;
			
		}
		for (int l426 = 0; (l426 < 2); l426 = (l426 + 1)) {
			fRec577[l426] = 0.0f;
			
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec588[l427] = 0.0f;
			
		}
		for (int l428 = 0; (l428 < 2); l428 = (l428 + 1)) {
			fRec586[l428] = 0.0f;
			
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec594[l429] = 0.0f;
			
		}
		for (int l430 = 0; (l430 < 2); l430 = (l430 + 1)) {
			fRec592[l430] = 0.0f;
			
		}
		for (int l431 = 0; (l431 < 2); l431 = (l431 + 1)) {
			fRec591[l431] = 0.0f;
			
		}
		for (int l432 = 0; (l432 < 2); l432 = (l432 + 1)) {
			fRec589[l432] = 0.0f;
			
		}
		for (int l433 = 0; (l433 < 1024); l433 = (l433 + 1)) {
			fVec30[l433] = 0.0f;
			
		}
		for (int l434 = 0; (l434 < 2); l434 = (l434 + 1)) {
			fRec603[l434] = 0.0f;
			
		}
		for (int l435 = 0; (l435 < 2); l435 = (l435 + 1)) {
			fRec601[l435] = 0.0f;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec600[l436] = 0.0f;
			
		}
		for (int l437 = 0; (l437 < 2); l437 = (l437 + 1)) {
			fRec598[l437] = 0.0f;
			
		}
		for (int l438 = 0; (l438 < 2); l438 = (l438 + 1)) {
			fRec597[l438] = 0.0f;
			
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec595[l439] = 0.0f;
			
		}
		for (int l440 = 0; (l440 < 2); l440 = (l440 + 1)) {
			fRec606[l440] = 0.0f;
			
		}
		for (int l441 = 0; (l441 < 2); l441 = (l441 + 1)) {
			fRec604[l441] = 0.0f;
			
		}
		for (int l442 = 0; (l442 < 2); l442 = (l442 + 1)) {
			fRec612[l442] = 0.0f;
			
		}
		for (int l443 = 0; (l443 < 2); l443 = (l443 + 1)) {
			fRec610[l443] = 0.0f;
			
		}
		for (int l444 = 0; (l444 < 2); l444 = (l444 + 1)) {
			fRec609[l444] = 0.0f;
			
		}
		for (int l445 = 0; (l445 < 2); l445 = (l445 + 1)) {
			fRec607[l445] = 0.0f;
			
		}
		for (int l446 = 0; (l446 < 1024); l446 = (l446 + 1)) {
			fVec31[l446] = 0.0f;
			
		}
		for (int l447 = 0; (l447 < 2); l447 = (l447 + 1)) {
			fRec621[l447] = 0.0f;
			
		}
		for (int l448 = 0; (l448 < 2); l448 = (l448 + 1)) {
			fRec619[l448] = 0.0f;
			
		}
		for (int l449 = 0; (l449 < 2); l449 = (l449 + 1)) {
			fRec618[l449] = 0.0f;
			
		}
		for (int l450 = 0; (l450 < 2); l450 = (l450 + 1)) {
			fRec616[l450] = 0.0f;
			
		}
		for (int l451 = 0; (l451 < 2); l451 = (l451 + 1)) {
			fRec615[l451] = 0.0f;
			
		}
		for (int l452 = 0; (l452 < 2); l452 = (l452 + 1)) {
			fRec613[l452] = 0.0f;
			
		}
		for (int l453 = 0; (l453 < 2); l453 = (l453 + 1)) {
			fRec624[l453] = 0.0f;
			
		}
		for (int l454 = 0; (l454 < 2); l454 = (l454 + 1)) {
			fRec622[l454] = 0.0f;
			
		}
		for (int l455 = 0; (l455 < 2); l455 = (l455 + 1)) {
			fRec630[l455] = 0.0f;
			
		}
		for (int l456 = 0; (l456 < 2); l456 = (l456 + 1)) {
			fRec628[l456] = 0.0f;
			
		}
		for (int l457 = 0; (l457 < 2); l457 = (l457 + 1)) {
			fRec627[l457] = 0.0f;
			
		}
		for (int l458 = 0; (l458 < 2); l458 = (l458 + 1)) {
			fRec625[l458] = 0.0f;
			
		}
		for (int l459 = 0; (l459 < 1024); l459 = (l459 + 1)) {
			fVec32[l459] = 0.0f;
			
		}
		for (int l460 = 0; (l460 < 2); l460 = (l460 + 1)) {
			fRec639[l460] = 0.0f;
			
		}
		for (int l461 = 0; (l461 < 2); l461 = (l461 + 1)) {
			fRec637[l461] = 0.0f;
			
		}
		for (int l462 = 0; (l462 < 2); l462 = (l462 + 1)) {
			fRec636[l462] = 0.0f;
			
		}
		for (int l463 = 0; (l463 < 2); l463 = (l463 + 1)) {
			fRec634[l463] = 0.0f;
			
		}
		for (int l464 = 0; (l464 < 2); l464 = (l464 + 1)) {
			fRec633[l464] = 0.0f;
			
		}
		for (int l465 = 0; (l465 < 2); l465 = (l465 + 1)) {
			fRec631[l465] = 0.0f;
			
		}
		for (int l466 = 0; (l466 < 2); l466 = (l466 + 1)) {
			fRec642[l466] = 0.0f;
			
		}
		for (int l467 = 0; (l467 < 2); l467 = (l467 + 1)) {
			fRec640[l467] = 0.0f;
			
		}
		for (int l468 = 0; (l468 < 2); l468 = (l468 + 1)) {
			fRec648[l468] = 0.0f;
			
		}
		for (int l469 = 0; (l469 < 2); l469 = (l469 + 1)) {
			fRec646[l469] = 0.0f;
			
		}
		for (int l470 = 0; (l470 < 2); l470 = (l470 + 1)) {
			fRec645[l470] = 0.0f;
			
		}
		for (int l471 = 0; (l471 < 2); l471 = (l471 + 1)) {
			fRec643[l471] = 0.0f;
			
		}
		for (int l472 = 0; (l472 < 1024); l472 = (l472 + 1)) {
			fVec33[l472] = 0.0f;
			
		}
		for (int l473 = 0; (l473 < 2); l473 = (l473 + 1)) {
			fRec657[l473] = 0.0f;
			
		}
		for (int l474 = 0; (l474 < 2); l474 = (l474 + 1)) {
			fRec655[l474] = 0.0f;
			
		}
		for (int l475 = 0; (l475 < 2); l475 = (l475 + 1)) {
			fRec654[l475] = 0.0f;
			
		}
		for (int l476 = 0; (l476 < 2); l476 = (l476 + 1)) {
			fRec652[l476] = 0.0f;
			
		}
		for (int l477 = 0; (l477 < 2); l477 = (l477 + 1)) {
			fRec651[l477] = 0.0f;
			
		}
		for (int l478 = 0; (l478 < 2); l478 = (l478 + 1)) {
			fRec649[l478] = 0.0f;
			
		}
		for (int l479 = 0; (l479 < 2); l479 = (l479 + 1)) {
			fRec660[l479] = 0.0f;
			
		}
		for (int l480 = 0; (l480 < 2); l480 = (l480 + 1)) {
			fRec658[l480] = 0.0f;
			
		}
		for (int l481 = 0; (l481 < 2); l481 = (l481 + 1)) {
			fRec666[l481] = 0.0f;
			
		}
		for (int l482 = 0; (l482 < 2); l482 = (l482 + 1)) {
			fRec664[l482] = 0.0f;
			
		}
		for (int l483 = 0; (l483 < 2); l483 = (l483 + 1)) {
			fRec663[l483] = 0.0f;
			
		}
		for (int l484 = 0; (l484 < 2); l484 = (l484 + 1)) {
			fRec661[l484] = 0.0f;
			
		}
		for (int l485 = 0; (l485 < 1024); l485 = (l485 + 1)) {
			fVec34[l485] = 0.0f;
			
		}
		for (int l486 = 0; (l486 < 2); l486 = (l486 + 1)) {
			fRec675[l486] = 0.0f;
			
		}
		for (int l487 = 0; (l487 < 2); l487 = (l487 + 1)) {
			fRec673[l487] = 0.0f;
			
		}
		for (int l488 = 0; (l488 < 2); l488 = (l488 + 1)) {
			fRec672[l488] = 0.0f;
			
		}
		for (int l489 = 0; (l489 < 2); l489 = (l489 + 1)) {
			fRec670[l489] = 0.0f;
			
		}
		for (int l490 = 0; (l490 < 2); l490 = (l490 + 1)) {
			fRec669[l490] = 0.0f;
			
		}
		for (int l491 = 0; (l491 < 2); l491 = (l491 + 1)) {
			fRec667[l491] = 0.0f;
			
		}
		for (int l492 = 0; (l492 < 2); l492 = (l492 + 1)) {
			fRec678[l492] = 0.0f;
			
		}
		for (int l493 = 0; (l493 < 2); l493 = (l493 + 1)) {
			fRec676[l493] = 0.0f;
			
		}
		for (int l494 = 0; (l494 < 2); l494 = (l494 + 1)) {
			fRec684[l494] = 0.0f;
			
		}
		for (int l495 = 0; (l495 < 2); l495 = (l495 + 1)) {
			fRec682[l495] = 0.0f;
			
		}
		for (int l496 = 0; (l496 < 2); l496 = (l496 + 1)) {
			fRec681[l496] = 0.0f;
			
		}
		for (int l497 = 0; (l497 < 2); l497 = (l497 + 1)) {
			fRec679[l497] = 0.0f;
			
		}
		for (int l498 = 0; (l498 < 1024); l498 = (l498 + 1)) {
			fVec35[l498] = 0.0f;
			
		}
		for (int l499 = 0; (l499 < 2); l499 = (l499 + 1)) {
			fRec693[l499] = 0.0f;
			
		}
		for (int l500 = 0; (l500 < 2); l500 = (l500 + 1)) {
			fRec691[l500] = 0.0f;
			
		}
		for (int l501 = 0; (l501 < 2); l501 = (l501 + 1)) {
			fRec690[l501] = 0.0f;
			
		}
		for (int l502 = 0; (l502 < 2); l502 = (l502 + 1)) {
			fRec688[l502] = 0.0f;
			
		}
		for (int l503 = 0; (l503 < 2); l503 = (l503 + 1)) {
			fRec687[l503] = 0.0f;
			
		}
		for (int l504 = 0; (l504 < 2); l504 = (l504 + 1)) {
			fRec685[l504] = 0.0f;
			
		}
		for (int l505 = 0; (l505 < 2); l505 = (l505 + 1)) {
			fRec696[l505] = 0.0f;
			
		}
		for (int l506 = 0; (l506 < 2); l506 = (l506 + 1)) {
			fRec694[l506] = 0.0f;
			
		}
		for (int l507 = 0; (l507 < 2); l507 = (l507 + 1)) {
			fRec702[l507] = 0.0f;
			
		}
		for (int l508 = 0; (l508 < 2); l508 = (l508 + 1)) {
			fRec700[l508] = 0.0f;
			
		}
		for (int l509 = 0; (l509 < 2); l509 = (l509 + 1)) {
			fRec699[l509] = 0.0f;
			
		}
		for (int l510 = 0; (l510 < 2); l510 = (l510 + 1)) {
			fRec697[l510] = 0.0f;
			
		}
		for (int l511 = 0; (l511 < 1024); l511 = (l511 + 1)) {
			fVec36[l511] = 0.0f;
			
		}
		for (int l512 = 0; (l512 < 2); l512 = (l512 + 1)) {
			fRec711[l512] = 0.0f;
			
		}
		for (int l513 = 0; (l513 < 2); l513 = (l513 + 1)) {
			fRec709[l513] = 0.0f;
			
		}
		for (int l514 = 0; (l514 < 2); l514 = (l514 + 1)) {
			fRec708[l514] = 0.0f;
			
		}
		for (int l515 = 0; (l515 < 2); l515 = (l515 + 1)) {
			fRec706[l515] = 0.0f;
			
		}
		for (int l516 = 0; (l516 < 2); l516 = (l516 + 1)) {
			fRec705[l516] = 0.0f;
			
		}
		for (int l517 = 0; (l517 < 2); l517 = (l517 + 1)) {
			fRec703[l517] = 0.0f;
			
		}
		for (int l518 = 0; (l518 < 2); l518 = (l518 + 1)) {
			fRec714[l518] = 0.0f;
			
		}
		for (int l519 = 0; (l519 < 2); l519 = (l519 + 1)) {
			fRec712[l519] = 0.0f;
			
		}
		for (int l520 = 0; (l520 < 2); l520 = (l520 + 1)) {
			fRec720[l520] = 0.0f;
			
		}
		for (int l521 = 0; (l521 < 2); l521 = (l521 + 1)) {
			fRec718[l521] = 0.0f;
			
		}
		for (int l522 = 0; (l522 < 2); l522 = (l522 + 1)) {
			fRec717[l522] = 0.0f;
			
		}
		for (int l523 = 0; (l523 < 2); l523 = (l523 + 1)) {
			fRec715[l523] = 0.0f;
			
		}
		for (int l524 = 0; (l524 < 1024); l524 = (l524 + 1)) {
			fVec37[l524] = 0.0f;
			
		}
		for (int l525 = 0; (l525 < 2); l525 = (l525 + 1)) {
			fRec729[l525] = 0.0f;
			
		}
		for (int l526 = 0; (l526 < 2); l526 = (l526 + 1)) {
			fRec727[l526] = 0.0f;
			
		}
		for (int l527 = 0; (l527 < 2); l527 = (l527 + 1)) {
			fRec726[l527] = 0.0f;
			
		}
		for (int l528 = 0; (l528 < 2); l528 = (l528 + 1)) {
			fRec724[l528] = 0.0f;
			
		}
		for (int l529 = 0; (l529 < 2); l529 = (l529 + 1)) {
			fRec723[l529] = 0.0f;
			
		}
		for (int l530 = 0; (l530 < 2); l530 = (l530 + 1)) {
			fRec721[l530] = 0.0f;
			
		}
		for (int l531 = 0; (l531 < 2); l531 = (l531 + 1)) {
			fRec732[l531] = 0.0f;
			
		}
		for (int l532 = 0; (l532 < 2); l532 = (l532 + 1)) {
			fRec730[l532] = 0.0f;
			
		}
		for (int l533 = 0; (l533 < 2); l533 = (l533 + 1)) {
			fRec738[l533] = 0.0f;
			
		}
		for (int l534 = 0; (l534 < 2); l534 = (l534 + 1)) {
			fRec736[l534] = 0.0f;
			
		}
		for (int l535 = 0; (l535 < 2); l535 = (l535 + 1)) {
			fRec735[l535] = 0.0f;
			
		}
		for (int l536 = 0; (l536 < 2); l536 = (l536 + 1)) {
			fRec733[l536] = 0.0f;
			
		}
		for (int l537 = 0; (l537 < 1024); l537 = (l537 + 1)) {
			fVec38[l537] = 0.0f;
			
		}
		for (int l538 = 0; (l538 < 2); l538 = (l538 + 1)) {
			fRec747[l538] = 0.0f;
			
		}
		for (int l539 = 0; (l539 < 2); l539 = (l539 + 1)) {
			fRec745[l539] = 0.0f;
			
		}
		for (int l540 = 0; (l540 < 2); l540 = (l540 + 1)) {
			fRec744[l540] = 0.0f;
			
		}
		for (int l541 = 0; (l541 < 2); l541 = (l541 + 1)) {
			fRec742[l541] = 0.0f;
			
		}
		for (int l542 = 0; (l542 < 2); l542 = (l542 + 1)) {
			fRec741[l542] = 0.0f;
			
		}
		for (int l543 = 0; (l543 < 2); l543 = (l543 + 1)) {
			fRec739[l543] = 0.0f;
			
		}
		for (int l544 = 0; (l544 < 2); l544 = (l544 + 1)) {
			fRec750[l544] = 0.0f;
			
		}
		for (int l545 = 0; (l545 < 2); l545 = (l545 + 1)) {
			fRec748[l545] = 0.0f;
			
		}
		for (int l546 = 0; (l546 < 2); l546 = (l546 + 1)) {
			fRec756[l546] = 0.0f;
			
		}
		for (int l547 = 0; (l547 < 2); l547 = (l547 + 1)) {
			fRec754[l547] = 0.0f;
			
		}
		for (int l548 = 0; (l548 < 2); l548 = (l548 + 1)) {
			fRec753[l548] = 0.0f;
			
		}
		for (int l549 = 0; (l549 < 2); l549 = (l549 + 1)) {
			fRec751[l549] = 0.0f;
			
		}
		for (int l550 = 0; (l550 < 1024); l550 = (l550 + 1)) {
			fVec39[l550] = 0.0f;
			
		}
		for (int l551 = 0; (l551 < 2); l551 = (l551 + 1)) {
			fRec765[l551] = 0.0f;
			
		}
		for (int l552 = 0; (l552 < 2); l552 = (l552 + 1)) {
			fRec763[l552] = 0.0f;
			
		}
		for (int l553 = 0; (l553 < 2); l553 = (l553 + 1)) {
			fRec762[l553] = 0.0f;
			
		}
		for (int l554 = 0; (l554 < 2); l554 = (l554 + 1)) {
			fRec760[l554] = 0.0f;
			
		}
		for (int l555 = 0; (l555 < 2); l555 = (l555 + 1)) {
			fRec759[l555] = 0.0f;
			
		}
		for (int l556 = 0; (l556 < 2); l556 = (l556 + 1)) {
			fRec757[l556] = 0.0f;
			
		}
		for (int l557 = 0; (l557 < 2); l557 = (l557 + 1)) {
			fRec768[l557] = 0.0f;
			
		}
		for (int l558 = 0; (l558 < 2); l558 = (l558 + 1)) {
			fRec766[l558] = 0.0f;
			
		}
		for (int l559 = 0; (l559 < 2); l559 = (l559 + 1)) {
			fRec774[l559] = 0.0f;
			
		}
		for (int l560 = 0; (l560 < 2); l560 = (l560 + 1)) {
			fRec772[l560] = 0.0f;
			
		}
		for (int l561 = 0; (l561 < 2); l561 = (l561 + 1)) {
			fRec771[l561] = 0.0f;
			
		}
		for (int l562 = 0; (l562 < 2); l562 = (l562 + 1)) {
			fRec769[l562] = 0.0f;
			
		}
		for (int l563 = 0; (l563 < 1024); l563 = (l563 + 1)) {
			fVec40[l563] = 0.0f;
			
		}
		for (int l564 = 0; (l564 < 2); l564 = (l564 + 1)) {
			fRec783[l564] = 0.0f;
			
		}
		for (int l565 = 0; (l565 < 2); l565 = (l565 + 1)) {
			fRec781[l565] = 0.0f;
			
		}
		for (int l566 = 0; (l566 < 2); l566 = (l566 + 1)) {
			fRec780[l566] = 0.0f;
			
		}
		for (int l567 = 0; (l567 < 2); l567 = (l567 + 1)) {
			fRec778[l567] = 0.0f;
			
		}
		for (int l568 = 0; (l568 < 2); l568 = (l568 + 1)) {
			fRec777[l568] = 0.0f;
			
		}
		for (int l569 = 0; (l569 < 2); l569 = (l569 + 1)) {
			fRec775[l569] = 0.0f;
			
		}
		for (int l570 = 0; (l570 < 2); l570 = (l570 + 1)) {
			fRec786[l570] = 0.0f;
			
		}
		for (int l571 = 0; (l571 < 2); l571 = (l571 + 1)) {
			fRec784[l571] = 0.0f;
			
		}
		for (int l572 = 0; (l572 < 2); l572 = (l572 + 1)) {
			fRec792[l572] = 0.0f;
			
		}
		for (int l573 = 0; (l573 < 2); l573 = (l573 + 1)) {
			fRec790[l573] = 0.0f;
			
		}
		for (int l574 = 0; (l574 < 2); l574 = (l574 + 1)) {
			fRec789[l574] = 0.0f;
			
		}
		for (int l575 = 0; (l575 < 2); l575 = (l575 + 1)) {
			fRec787[l575] = 0.0f;
			
		}
		for (int l576 = 0; (l576 < 1024); l576 = (l576 + 1)) {
			fVec41[l576] = 0.0f;
			
		}
		for (int l577 = 0; (l577 < 2); l577 = (l577 + 1)) {
			fRec801[l577] = 0.0f;
			
		}
		for (int l578 = 0; (l578 < 2); l578 = (l578 + 1)) {
			fRec799[l578] = 0.0f;
			
		}
		for (int l579 = 0; (l579 < 2); l579 = (l579 + 1)) {
			fRec798[l579] = 0.0f;
			
		}
		for (int l580 = 0; (l580 < 2); l580 = (l580 + 1)) {
			fRec796[l580] = 0.0f;
			
		}
		for (int l581 = 0; (l581 < 2); l581 = (l581 + 1)) {
			fRec795[l581] = 0.0f;
			
		}
		for (int l582 = 0; (l582 < 2); l582 = (l582 + 1)) {
			fRec793[l582] = 0.0f;
			
		}
		for (int l583 = 0; (l583 < 2); l583 = (l583 + 1)) {
			fRec804[l583] = 0.0f;
			
		}
		for (int l584 = 0; (l584 < 2); l584 = (l584 + 1)) {
			fRec802[l584] = 0.0f;
			
		}
		for (int l585 = 0; (l585 < 2); l585 = (l585 + 1)) {
			fRec810[l585] = 0.0f;
			
		}
		for (int l586 = 0; (l586 < 2); l586 = (l586 + 1)) {
			fRec808[l586] = 0.0f;
			
		}
		for (int l587 = 0; (l587 < 2); l587 = (l587 + 1)) {
			fRec807[l587] = 0.0f;
			
		}
		for (int l588 = 0; (l588 < 2); l588 = (l588 + 1)) {
			fRec805[l588] = 0.0f;
			
		}
		for (int l589 = 0; (l589 < 1024); l589 = (l589 + 1)) {
			fVec42[l589] = 0.0f;
			
		}
		for (int l590 = 0; (l590 < 2); l590 = (l590 + 1)) {
			fRec819[l590] = 0.0f;
			
		}
		for (int l591 = 0; (l591 < 2); l591 = (l591 + 1)) {
			fRec817[l591] = 0.0f;
			
		}
		for (int l592 = 0; (l592 < 2); l592 = (l592 + 1)) {
			fRec816[l592] = 0.0f;
			
		}
		for (int l593 = 0; (l593 < 2); l593 = (l593 + 1)) {
			fRec814[l593] = 0.0f;
			
		}
		for (int l594 = 0; (l594 < 2); l594 = (l594 + 1)) {
			fRec813[l594] = 0.0f;
			
		}
		for (int l595 = 0; (l595 < 2); l595 = (l595 + 1)) {
			fRec811[l595] = 0.0f;
			
		}
		for (int l596 = 0; (l596 < 2); l596 = (l596 + 1)) {
			fRec822[l596] = 0.0f;
			
		}
		for (int l597 = 0; (l597 < 2); l597 = (l597 + 1)) {
			fRec820[l597] = 0.0f;
			
		}
		for (int l598 = 0; (l598 < 2); l598 = (l598 + 1)) {
			fRec828[l598] = 0.0f;
			
		}
		for (int l599 = 0; (l599 < 2); l599 = (l599 + 1)) {
			fRec826[l599] = 0.0f;
			
		}
		for (int l600 = 0; (l600 < 2); l600 = (l600 + 1)) {
			fRec825[l600] = 0.0f;
			
		}
		for (int l601 = 0; (l601 < 2); l601 = (l601 + 1)) {
			fRec823[l601] = 0.0f;
			
		}
		for (int l602 = 0; (l602 < 1024); l602 = (l602 + 1)) {
			fVec43[l602] = 0.0f;
			
		}
		
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
		
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("KMHLS_FullSetup_3h3p_full_2");
		ui_interface->declare(&fHslider0, "unit", "dB");
		ui_interface->addHorizontalSlider("gain", &fHslider0, -10.0f, -30.0f, 10.0f, 1.0f);
		ui_interface->declare(&fHslider2, "unit", "dB");
		ui_interface->addHorizontalSlider("lf/hf", &fHslider2, 0.0f, -3.0f, 3.0f, 0.100000001f);
		ui_interface->addCheckButton("mute", &fCheckbox0);
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("xover", &fHslider1, 400.0f, 200.0f, 800.0f, 20.0f);
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* input2 = inputs[2];
		FAUSTFLOAT* input3 = inputs[3];
		FAUSTFLOAT* input4 = inputs[4];
		FAUSTFLOAT* input5 = inputs[5];
		FAUSTFLOAT* input6 = inputs[6];
		FAUSTFLOAT* input7 = inputs[7];
		FAUSTFLOAT* input8 = inputs[8];
		FAUSTFLOAT* input9 = inputs[9];
		FAUSTFLOAT* input10 = inputs[10];
		FAUSTFLOAT* input11 = inputs[11];
		FAUSTFLOAT* input12 = inputs[12];
		FAUSTFLOAT* input13 = inputs[13];
		FAUSTFLOAT* input14 = inputs[14];
		FAUSTFLOAT* input15 = inputs[15];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		FAUSTFLOAT* output2 = outputs[2];
		FAUSTFLOAT* output3 = outputs[3];
		FAUSTFLOAT* output4 = outputs[4];
		FAUSTFLOAT* output5 = outputs[5];
		FAUSTFLOAT* output6 = outputs[6];
		FAUSTFLOAT* output7 = outputs[7];
		FAUSTFLOAT* output8 = outputs[8];
		FAUSTFLOAT* output9 = outputs[9];
		FAUSTFLOAT* output10 = outputs[10];
		FAUSTFLOAT* output11 = outputs[11];
		FAUSTFLOAT* output12 = outputs[12];
		FAUSTFLOAT* output13 = outputs[13];
		FAUSTFLOAT* output14 = outputs[14];
		FAUSTFLOAT* output15 = outputs[15];
		FAUSTFLOAT* output16 = outputs[16];
		FAUSTFLOAT* output17 = outputs[17];
		FAUSTFLOAT* output18 = outputs[18];
		FAUSTFLOAT* output19 = outputs[19];
		FAUSTFLOAT* output20 = outputs[20];
		FAUSTFLOAT* output21 = outputs[21];
		FAUSTFLOAT* output22 = outputs[22];
		FAUSTFLOAT* output23 = outputs[23];
		FAUSTFLOAT* output24 = outputs[24];
		FAUSTFLOAT* output25 = outputs[25];
		FAUSTFLOAT* output26 = outputs[26];
		FAUSTFLOAT* output27 = outputs[27];
		FAUSTFLOAT* output28 = outputs[28];
		FAUSTFLOAT* output29 = outputs[29];
		FAUSTFLOAT* output30 = outputs[30];
		FAUSTFLOAT* output31 = outputs[31];
		FAUSTFLOAT* output32 = outputs[32];
		FAUSTFLOAT* output33 = outputs[33];
		FAUSTFLOAT* output34 = outputs[34];
		FAUSTFLOAT* output35 = outputs[35];
		FAUSTFLOAT* output36 = outputs[36];
		FAUSTFLOAT* output37 = outputs[37];
		FAUSTFLOAT* output38 = outputs[38];
		FAUSTFLOAT* output39 = outputs[39];
		FAUSTFLOAT* output40 = outputs[40];
		FAUSTFLOAT* output41 = outputs[41];
		FAUSTFLOAT* output42 = outputs[42];
		FAUSTFLOAT* output43 = outputs[43];
		FAUSTFLOAT* output44 = outputs[44];
		float fSlow0 = (0.00100000005f * (float((float(fCheckbox0) < 0.5f)) * std::pow(10.0f, (0.0500000007f * float(fHslider0)))));
		float fSlow1 = (0.00100000005f * float(fHslider1));
		float fSlow2 = (0.00100000005f * std::pow(10.0f, (0.0500000007f * float(fHslider2))));
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec0[0] = (fSlow0 + (0.999000013f * fRec0[1]));
			fRec1[0] = (fSlow1 + (0.999000013f * fRec1[1]));
			float fTemp0 = std::tan((fConst1 * fRec1[0]));
			float fTemp1 = mydsp_faustpower2_f(fTemp0);
			float fTemp2 = ((fTemp0 * (fTemp0 + -2.0f)) + 1.0f);
			float fTemp3 = (fTemp1 + -1.0f);
			float fTemp4 = ((fTemp0 * (fTemp0 + 2.0f)) + 1.0f);
			fRec2[0] = (float(input0[i]) - (((fRec2[2] * fTemp2) + (2.0f * (fRec2[1] * fTemp3))) / fTemp4));
			fRec3[0] = (fSlow2 + (0.999000013f * fRec3[1]));
			float fTemp5 = (fRec3[0] * fTemp4);
			float fTemp6 = (0.0f - (2.0f / fTemp4));
			float fTemp7 = (((fTemp1 * (fRec2[2] + (fRec2[0] + (2.0f * fRec2[1])))) / fTemp5) + (2.79763007f * (fRec3[0] * (0.0f - ((fRec2[1] * fTemp6) + ((fRec2[0] + fRec2[2]) / fTemp4))))));
			fRec13[0] = (float(input9[i]) - (((fTemp2 * fRec13[2]) + (2.0f * (fTemp3 * fRec13[1]))) / fTemp4));
			float fTemp8 = (((fTemp1 * (fRec13[2] + (fRec13[0] + (2.0f * fRec13[1])))) / fTemp5) + (0.852569342f * (fRec3[0] * (0.0f - ((fTemp6 * fRec13[1]) + ((fRec13[0] + fRec13[2]) / fTemp4))))));
			fRec14[0] = (float(input10[i]) - (((fTemp2 * fRec14[2]) + (2.0f * (fTemp3 * fRec14[1]))) / fTemp4));
			float fTemp9 = (((fTemp1 * (fRec14[2] + (fRec14[0] + (2.0f * fRec14[1])))) / fTemp5) + (0.852569342f * (fRec3[0] * (0.0f - ((fTemp6 * fRec14[1]) + ((fRec14[0] + fRec14[2]) / fTemp4))))));
			fRec15[0] = (float(input14[i]) - (((fTemp2 * fRec15[2]) + (2.0f * (fTemp3 * fRec15[1]))) / fTemp4));
			float fTemp10 = (((fTemp1 * (fRec15[2] + (fRec15[0] + (2.0f * fRec15[1])))) / fTemp5) + (0.852569342f * (fRec3[0] * (0.0f - ((fTemp6 * fRec15[1]) + ((fRec15[0] + fRec15[2]) / fTemp4))))));
			fRec16[0] = (float(input11[i]) - (((fTemp2 * fRec16[2]) + (2.0f * (fTemp3 * fRec16[1]))) / fTemp4));
			float fTemp11 = (((fTemp1 * (fRec16[2] + (fRec16[0] + (2.0f * fRec16[1])))) / fTemp5) + (0.852569342f * (fRec3[0] * (0.0f - ((fTemp6 * fRec16[1]) + ((fRec16[0] + fRec16[2]) / fTemp4))))));
			fRec17[0] = (float(input12[i]) - (((fTemp2 * fRec17[2]) + (2.0f * (fTemp3 * fRec17[1]))) / fTemp4));
			float fTemp12 = (((fTemp1 * (fRec17[2] + (fRec17[0] + (2.0f * fRec17[1])))) / fTemp5) + (0.852569342f * (fRec3[0] * (0.0f - ((fTemp6 * fRec17[1]) + ((fRec17[0] + fRec17[2]) / fTemp4))))));
			fRec18[0] = (float(input13[i]) - (((fTemp2 * fRec18[2]) + (2.0f * (fTemp3 * fRec18[1]))) / fTemp4));
			float fTemp13 = (((fTemp1 * (fRec18[2] + (fRec18[0] + (2.0f * fRec18[1])))) / fTemp5) + (0.852569342f * (fRec3[0] * (0.0f - ((fTemp6 * fRec18[1]) + ((fRec18[0] + fRec18[2]) / fTemp4))))));
			fRec19[0] = (float(input15[i]) - (((fTemp2 * fRec19[2]) + (2.0f * (fTemp3 * fRec19[1]))) / fTemp4));
			float fTemp14 = (((fTemp1 * (fRec19[2] + (fRec19[0] + (2.0f * fRec19[1])))) / fTemp5) + (0.852569342f * (fRec3[0] * (0.0f - ((fTemp6 * fRec19[1]) + ((fRec19[0] + fRec19[2]) / fTemp4))))));
			float fTemp15 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec10[1]) + (fConst4 * fRec7[1])))) + (fConst7 * ((((0.229184031f * fTemp8) + (0.138398468f * fTemp9)) + (0.0530737042f * fTemp10)) - ((((0.120342016f * fTemp11) + (0.0544278622f * fTemp12)) + (0.17165485f * fTemp13)) + (0.0563216209f * fTemp14))))));
			fRec12[0] = (fRec12[1] + fTemp15);
			fRec10[0] = fRec12[0];
			float fRec11 = fTemp15;
			fRec9[0] = (fRec10[0] + fRec9[1]);
			fRec7[0] = fRec9[0];
			float fRec8 = fRec11;
			float fTemp16 = (fConst8 * fRec4[1]);
			fRec6[0] = ((fRec8 + fRec6[1]) - fTemp16);
			fRec4[0] = fRec6[0];
			float fRec5 = (fRec8 - fTemp16);
			fRec23[0] = (float(input1[i]) - (((fTemp2 * fRec23[2]) + (2.0f * (fTemp3 * fRec23[1]))) / fTemp4));
			float fTemp17 = (((fTemp1 * (fRec23[2] + (fRec23[0] + (2.0f * fRec23[1])))) / fTemp5) + (2.40914083f * (fRec3[0] * (0.0f - ((fTemp6 * fRec23[1]) + ((fRec23[0] + fRec23[2]) / fTemp4))))));
			fRec24[0] = (float(input2[i]) - (((fTemp2 * fRec24[2]) + (2.0f * (fTemp3 * fRec24[1]))) / fTemp4));
			float fTemp18 = (((fTemp1 * (fRec24[2] + (fRec24[0] + (2.0f * fRec24[1])))) / fTemp5) + (2.40914083f * (fRec3[0] * (0.0f - ((fTemp6 * fRec24[1]) + ((fRec24[0] + fRec24[2]) / fTemp4))))));
			fRec25[0] = (float(input3[i]) - (((fTemp2 * fRec25[2]) + (2.0f * (fTemp3 * fRec25[1]))) / fTemp4));
			float fTemp19 = (((fTemp1 * (fRec25[2] + (fRec25[0] + (2.0f * fRec25[1])))) / fTemp5) + (2.40914083f * (fRec3[0] * (0.0f - ((fTemp6 * fRec25[1]) + ((fRec25[0] + fRec25[2]) / fTemp4))))));
			float fTemp20 = (fConst9 * (((0.0729958713f * fTemp17) + ((0.151668563f * fTemp18) + (0.105826542f * fTemp19))) - (fConst10 * fRec20[1])));
			fRec22[0] = (fRec22[1] + fTemp20);
			fRec20[0] = fRec22[0];
			float fRec21 = fTemp20;
			fRec32[0] = (float(input4[i]) - (((fTemp2 * fRec32[2]) + (2.0f * (fTemp3 * fRec32[1]))) / fTemp4));
			float fTemp21 = (((fTemp1 * (fRec32[2] + (fRec32[0] + (2.0f * fRec32[1])))) / fTemp5) + (1.71308291f * (fRec3[0] * (0.0f - ((fTemp6 * fRec32[1]) + ((fRec32[0] + fRec32[2]) / fTemp4))))));
			fRec33[0] = (float(input5[i]) - (((fTemp2 * fRec33[2]) + (2.0f * (fTemp3 * fRec33[1]))) / fTemp4));
			float fTemp22 = (((fTemp1 * (fRec33[2] + (fRec33[0] + (2.0f * fRec33[1])))) / fTemp5) + (1.71308291f * (fRec3[0] * (0.0f - ((fTemp6 * fRec33[1]) + ((fRec33[0] + fRec33[2]) / fTemp4))))));
			fRec34[0] = (float(input7[i]) - (((fTemp2 * fRec34[2]) + (2.0f * (fTemp3 * fRec34[1]))) / fTemp4));
			float fTemp23 = (((fTemp1 * (fRec34[2] + (fRec34[0] + (2.0f * fRec34[1])))) / fTemp5) + (1.71308291f * (fRec3[0] * (0.0f - ((fTemp6 * fRec34[1]) + ((fRec34[0] + fRec34[2]) / fTemp4))))));
			fRec35[0] = (float(input8[i]) - (((fTemp2 * fRec35[2]) + (2.0f * (fTemp3 * fRec35[1]))) / fTemp4));
			float fTemp24 = (((fTemp1 * (fRec35[2] + (fRec35[0] + (2.0f * fRec35[1])))) / fTemp5) + (1.71308291f * (fRec3[0] * (0.0f - ((fTemp6 * fRec35[1]) + ((fRec35[0] + fRec35[2]) / fTemp4))))));
			fRec36[0] = (float(input6[i]) - (((fTemp2 * fRec36[2]) + (2.0f * (fTemp3 * fRec36[1]))) / fTemp4));
			float fTemp25 = (((fTemp1 * (fRec36[2] + (fRec36[0] + (2.0f * fRec36[1])))) / fTemp5) + (1.71308291f * (fRec3[0] * (0.0f - ((fTemp6 * fRec36[1]) + ((fRec36[0] + fRec36[2]) / fTemp4))))));
			float fTemp26 = (fConst11 * ((((((0.195528686f * fTemp21) + (0.122138552f * fTemp22)) + (0.176479369f * fTemp23)) + (0.0736751854f * fTemp24)) - (0.178841889f * fTemp25)) + (fConst3 * (0.0f - ((fConst13 * fRec29[1]) + (fConst12 * fRec26[1]))))));
			fRec31[0] = (fRec31[1] + fTemp26);
			fRec29[0] = fRec31[0];
			float fRec30 = fTemp26;
			fRec28[0] = (fRec29[0] + fRec28[1]);
			fRec26[0] = fRec28[0];
			float fRec27 = fRec30;
			fVec0[(IOTA & 1023)] = ((0.0811889991f * fTemp7) + (fRec5 + (fRec21 + fRec27)));
			output0[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec0[((IOTA - iConst14) & 1023)])));
			float fTemp27 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec43[1]) + (fConst4 * fRec40[1])))) + (fConst7 * (((((0.152017519f * fTemp8) + (0.0657557696f * fTemp9)) + (0.13623789f * fTemp10)) + (0.181312099f * fTemp14)) - (((0.0490719602f * fTemp11) + (0.0538455397f * fTemp12)) + (0.201620907f * fTemp13))))));
			fRec45[0] = (fRec45[1] + fTemp27);
			fRec43[0] = fRec45[0];
			float fRec44 = fTemp27;
			fRec42[0] = (fRec43[0] + fRec42[1]);
			fRec40[0] = fRec42[0];
			float fRec41 = fRec44;
			float fTemp28 = (fConst8 * fRec37[1]);
			fRec39[0] = ((fRec41 + fRec39[1]) - fTemp28);
			fRec37[0] = fRec39[0];
			float fRec38 = (fRec41 - fTemp28);
			float fTemp29 = (fConst9 * (((0.0288413614f * fTemp17) + ((0.152452603f * fTemp18) + (0.126892507f * fTemp19))) - (fConst10 * fRec46[1])));
			fRec48[0] = (fRec48[1] + fTemp29);
			fRec46[0] = fRec48[0];
			float fRec47 = fTemp29;
			float fTemp30 = (fConst11 * ((((((0.0952446163f * fTemp21) + (0.049898468f * fTemp22)) + (0.2081687f * fTemp23)) + (0.187439948f * fTemp24)) - (0.179717749f * fTemp25)) + (fConst3 * (0.0f - ((fConst13 * fRec52[1]) + (fConst12 * fRec49[1]))))));
			fRec54[0] = (fRec54[1] + fTemp30);
			fRec52[0] = fRec54[0];
			float fRec53 = fTemp30;
			fRec51[0] = (fRec52[0] + fRec51[1]);
			fRec49[0] = fRec51[0];
			float fRec50 = fRec53;
			fVec1[(IOTA & 1023)] = ((0.0805836096f * fTemp7) + (fRec38 + (fRec47 + fRec50)));
			output1[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec1[((IOTA - iConst14) & 1023)])));
			float fTemp31 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec61[1]) + (fConst4 * fRec58[1])))) + (fConst7 * ((((0.0393178128f * fTemp11) + (0.142928421f * fTemp10)) + (0.201456249f * fTemp14)) - ((((0.123450674f * fTemp8) + (0.0538078472f * fTemp9)) + (0.0540995821f * fTemp12)) + (0.204378888f * fTemp13))))));
			fRec63[0] = (fRec63[1] + fTemp31);
			fRec61[0] = fRec63[0];
			float fRec62 = fTemp31;
			fRec60[0] = (fRec61[0] + fRec60[1]);
			fRec58[0] = fRec60[0];
			float fRec59 = fRec62;
			float fTemp32 = (fConst8 * fRec55[1]);
			fRec57[0] = ((fRec59 + fRec57[1]) - fTemp32);
			fRec55[0] = fRec57[0];
			float fRec56 = (fRec59 - fTemp32);
			float fTemp33 = (fConst9 * ((((0.15327397f * fTemp18) + (0.129370868f * fTemp19)) - (0.0236173179f * fTemp17)) - (fConst10 * fRec64[1])));
			fRec66[0] = (fRec66[1] + fTemp33);
			fRec64[0] = fRec66[0];
			float fRec65 = fTemp33;
			float fTemp34 = (fConst11 * ((((0.210336268f * fTemp23) + (0.196204066f * fTemp24)) - (((0.0743314996f * fTemp21) + (0.0390272252f * fTemp22)) + (0.17992574f * fTemp25))) + (fConst3 * (0.0f - ((fConst13 * fRec70[1]) + (fConst12 * fRec67[1]))))));
			fRec72[0] = (fRec72[1] + fTemp34);
			fRec70[0] = fRec72[0];
			float fRec71 = fTemp34;
			fRec69[0] = (fRec70[0] + fRec69[1]);
			fRec67[0] = fRec69[0];
			float fRec68 = fRec71;
			fVec2[(IOTA & 1023)] = ((0.0801607594f * fTemp7) + (fRec56 + (fRec65 + fRec68)));
			output2[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec2[((IOTA - iConst14) & 1023)])));
			float fTemp35 = (fConst2 * ((fConst7 * (((0.113283768f * fTemp11) + (0.0662244409f * fTemp10)) - (((((0.235402659f * fTemp8) + (0.133389935f * fTemp9)) + (0.05481584f * fTemp12)) + (0.17793116f * fTemp13)) + (0.0272637568f * fTemp14)))) + (fConst3 * (0.0f - ((fConst5 * fRec79[1]) + (fConst4 * fRec76[1]))))));
			fRec81[0] = (fRec81[1] + fTemp35);
			fRec79[0] = fRec81[0];
			float fRec80 = fTemp35;
			fRec78[0] = (fRec79[0] + fRec78[1]);
			fRec76[0] = fRec78[0];
			float fRec77 = fRec80;
			float fTemp36 = (fConst8 * fRec73[1]);
			fRec75[0] = ((fRec77 + fRec75[1]) - fTemp36);
			fRec73[0] = fRec75[0];
			float fRec74 = (fRec77 - fTemp36);
			float fTemp37 = (fConst9 * ((((0.153502658f * fTemp18) + (0.110956453f * fTemp19)) - (0.0682918876f * fTemp17)) - (fConst10 * fRec82[1])));
			fRec84[0] = (fRec84[1] + fTemp37);
			fRec82[0] = fRec84[0];
			float fRec83 = fTemp37;
			float fTemp38 = (fConst11 * ((((0.181724727f * fTemp23) + (0.0908379108f * fTemp24)) - (((0.190416351f * fTemp21) + (0.115014873f * fTemp22)) + (0.179846764f * fTemp25))) + (fConst3 * (0.0f - ((fConst13 * fRec88[1]) + (fConst12 * fRec85[1]))))));
			fRec90[0] = (fRec90[1] + fTemp38);
			fRec88[0] = fRec90[0];
			float fRec89 = fTemp38;
			fRec87[0] = (fRec88[0] + fRec87[1]);
			fRec85[0] = fRec87[0];
			float fRec86 = fRec89;
			fVec3[(IOTA & 1023)] = ((0.0806309059f * fTemp7) + (fRec74 + (fRec83 + fRec86)));
			output3[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec3[((IOTA - iConst14) & 1023)])));
			float fTemp39 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec97[1]) + (fConst4 * fRec94[1])))) + (fConst7 * ((0.1737964f * fTemp11) - ((((((0.0522835478f * fTemp8) + (0.136743218f * fTemp9)) + (0.0555725209f * fTemp12)) + (0.119879469f * fTemp13)) + (0.0571330711f * fTemp10)) + (0.231479719f * fTemp14))))));
			fRec99[0] = (fRec99[1] + fTemp39);
			fRec97[0] = fRec99[0];
			float fRec98 = fTemp39;
			fRec96[0] = (fRec97[0] + fRec96[1]);
			fRec94[0] = fRec96[0];
			float fRec95 = fRec98;
			float fTemp40 = (fConst8 * fRec91[1]);
			fRec93[0] = ((fRec95 + fRec93[1]) - fTemp40);
			fRec91[0] = fRec93[0];
			float fRec92 = (fRec95 - fTemp40);
			float fTemp41 = (fConst9 * ((((0.153228924f * fTemp18) + (0.0724589676f * fTemp19)) - (0.107601047f * fTemp17)) - (fConst10 * fRec100[1])));
			fRec102[0] = (fRec102[1] + fTemp41);
			fRec100[0] = fRec102[0];
			float fRec101 = fTemp41;
			float fTemp42 = (fConst11 * (((0.121473879f * fTemp23) - ((((0.197569624f * fTemp21) + (0.178934962f * fTemp22)) + (0.179841653f * fTemp25)) + (0.077969797f * fTemp24))) + (fConst3 * (0.0f - ((fConst13 * fRec106[1]) + (fConst12 * fRec103[1]))))));
			fRec108[0] = (fRec108[1] + fTemp42);
			fRec106[0] = fRec108[0];
			float fRec107 = fTemp42;
			fRec105[0] = (fRec106[0] + fRec105[1]);
			fRec103[0] = fRec105[0];
			float fRec104 = fRec107;
			fVec4[(IOTA & 1023)] = ((0.0817889199f * fTemp7) + (fRec92 + (fRec101 + fRec104)));
			output4[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec4[((IOTA - iConst14) & 1023)])));
			float fTemp43 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec115[1]) + (fConst4 * fRec112[1])))) + (fConst7 * (((0.193576619f * fTemp8) + (0.204754308f * fTemp11)) - (((((0.0586837791f * fTemp9) + (0.0558398515f * fTemp12)) + (0.0436627902f * fTemp13)) + (0.142036334f * fTemp10)) + (0.136924297f * fTemp14))))));
			fRec117[0] = (fRec117[1] + fTemp43);
			fRec115[0] = fRec117[0];
			float fRec116 = fTemp43;
			fRec114[0] = (fRec115[0] + fRec114[1]);
			fRec112[0] = fRec114[0];
			float fRec113 = fRec116;
			float fTemp44 = (fConst8 * fRec109[1]);
			fRec111[0] = ((fRec113 + fRec111[1]) - fTemp44);
			fRec109[0] = fRec111[0];
			float fRec110 = (fRec113 - fTemp44);
			float fTemp45 = (fConst9 * ((((0.153029606f * fTemp18) + (0.0254880935f * fTemp19)) - (0.129422933f * fTemp17)) - (fConst10 * fRec118[1])));
			fRec120[0] = (fRec120[1] + fTemp45);
			fRec118[0] = fRec120[0];
			float fRec119 = fTemp45;
			float fTemp46 = (fConst11 * (((0.0443824418f * fTemp23) - ((((0.0844233334f * fTemp21) + (0.21142292f * fTemp22)) + (0.179997727f * fTemp25)) + (0.193864897f * fTemp24))) + (fConst3 * (0.0f - ((fConst13 * fRec124[1]) + (fConst12 * fRec121[1]))))));
			fRec126[0] = (fRec126[1] + fTemp46);
			fRec124[0] = fRec126[0];
			float fRec125 = fTemp46;
			fRec123[0] = (fRec124[0] + fRec123[1]);
			fRec121[0] = fRec123[0];
			float fRec122 = fRec125;
			fVec5[(IOTA & 1023)] = ((0.0824428275f * fTemp7) + (fRec110 + (fRec119 + fRec122)));
			output5[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec5[((IOTA - iConst14) & 1023)])));
			float fTemp47 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec133[1]) + (fConst4 * fRec130[1])))) + (fConst7 * ((((((0.196849659f * fTemp8) + (0.0563823506f * fTemp9)) + (0.205974281f * fTemp11)) + (0.043272499f * fTemp13)) + (0.135105297f * fTemp14)) - ((0.0553543866f * fTemp12) + (0.142877445f * fTemp10))))));
			fRec135[0] = (fRec135[1] + fTemp47);
			fRec133[0] = fRec135[0];
			float fRec134 = fTemp47;
			fRec132[0] = (fRec133[0] + fRec132[1]);
			fRec130[0] = fRec132[0];
			float fRec131 = fRec134;
			float fTemp48 = (fConst8 * fRec127[1]);
			fRec129[0] = ((fRec131 + fRec129[1]) - fTemp48);
			fRec127[0] = fRec129[0];
			float fRec128 = (fRec131 - fTemp48);
			float fTemp49 = (fConst9 * (((0.153297737f * fTemp18) - ((0.130128831f * fTemp17) + (0.0255391095f * fTemp19))) - (fConst10 * fRec136[1])));
			fRec138[0] = (fRec138[1] + fTemp49);
			fRec136[0] = fRec138[0];
			float fRec137 = fTemp49;
			float fTemp50 = (fConst11 * (((0.0840053782f * fTemp21) - ((((0.210673526f * fTemp22) + (0.18032226f * fTemp25)) + (0.042723421f * fTemp23)) + (0.195018664f * fTemp24))) + (fConst3 * (0.0f - ((fConst13 * fRec142[1]) + (fConst12 * fRec139[1]))))));
			fRec144[0] = (fRec144[1] + fTemp50);
			fRec142[0] = fRec144[0];
			float fRec143 = fTemp50;
			fRec141[0] = (fRec142[0] + fRec141[1]);
			fRec139[0] = fRec141[0];
			float fRec140 = fRec143;
			fVec6[(IOTA & 1023)] = ((0.0818421617f * fTemp7) + (fRec128 + (fRec137 + fRec140)));
			output6[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec6[((IOTA - iConst14) & 1023)])));
			float fTemp51 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec151[1]) + (fConst4 * fRec148[1])))) + (fConst7 * (((((0.135847777f * fTemp9) + (0.174516216f * fTemp11)) + (0.122085541f * fTemp13)) + (0.231336504f * fTemp14)) - (((0.0564924888f * fTemp8) + (0.0540709719f * fTemp12)) + (0.0549573824f * fTemp10))))));
			fRec153[0] = (fRec153[1] + fTemp51);
			fRec151[0] = fRec153[0];
			float fRec152 = fTemp51;
			fRec150[0] = (fRec151[0] + fRec150[1]);
			fRec148[0] = fRec150[0];
			float fRec149 = fRec152;
			float fTemp52 = (fConst8 * fRec145[1]);
			fRec147[0] = ((fRec149 + fRec147[1]) - fTemp52);
			fRec145[0] = fRec147[0];
			float fRec146 = (fRec149 - fTemp52);
			float fTemp53 = (fConst9 * (((0.153698936f * fTemp18) - ((0.107328966f * fTemp17) + (0.0721342638f * fTemp19))) - (fConst10 * fRec154[1])));
			fRec156[0] = (fRec156[1] + fTemp53);
			fRec154[0] = fRec156[0];
			float fRec155 = fTemp53;
			float fTemp54 = (fConst11 * (((0.198701769f * fTemp21) - ((((0.175604299f * fTemp22) + (0.180786967f * fTemp25)) + (0.122042432f * fTemp23)) + (0.0751220062f * fTemp24))) + (fConst3 * (0.0f - ((fConst13 * fRec160[1]) + (fConst12 * fRec157[1]))))));
			fRec162[0] = (fRec162[1] + fTemp54);
			fRec160[0] = fRec162[0];
			float fRec161 = fTemp54;
			fRec159[0] = (fRec160[0] + fRec159[1]);
			fRec157[0] = fRec159[0];
			float fRec158 = fRec161;
			fVec7[(IOTA & 1023)] = ((0.0803265944f * fTemp7) + (fRec146 + (fRec155 + fRec158)));
			output7[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec7[((IOTA - iConst14) & 1023)])));
			float fTemp55 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec169[1]) + (fConst4 * fRec166[1])))) + (fConst7 * ((((((0.130875006f * fTemp9) + (0.114081241f * fTemp11)) + (0.178320244f * fTemp13)) + (0.0647244975f * fTemp10)) + (0.0287231598f * fTemp14)) - ((0.232020587f * fTemp8) + (0.052510608f * fTemp12))))));
			fRec171[0] = (fRec171[1] + fTemp55);
			fRec169[0] = fRec171[0];
			float fRec170 = fTemp55;
			fRec168[0] = (fRec169[0] + fRec168[1]);
			fRec166[0] = fRec168[0];
			float fRec167 = fRec170;
			float fTemp56 = (fConst8 * fRec163[1]);
			fRec165[0] = ((fRec167 + fRec165[1]) - fTemp56);
			fRec163[0] = fRec165[0];
			float fRec164 = (fRec167 - fTemp56);
			float fTemp57 = (fConst9 * (((0.153477266f * fTemp18) - ((0.0671517551f * fTemp17) + (0.107598834f * fTemp19))) - (fConst10 * fRec172[1])));
			fRec174[0] = (fRec174[1] + fTemp57);
			fRec172[0] = fRec174[0];
			float fRec173 = fTemp57;
			float fTemp58 = (fConst11 * ((((0.188003421f * fTemp21) + (0.088648811f * fTemp24)) - (((0.113497578f * fTemp22) + (0.181114316f * fTemp25)) + (0.179241568f * fTemp23))) + (fConst3 * (0.0f - ((fConst13 * fRec178[1]) + (fConst12 * fRec175[1]))))));
			fRec180[0] = (fRec180[1] + fTemp58);
			fRec178[0] = fRec180[0];
			float fRec179 = fTemp58;
			fRec177[0] = (fRec178[0] + fRec177[1]);
			fRec175[0] = fRec177[0];
			float fRec176 = fRec179;
			fVec8[(IOTA & 1023)] = ((0.0791144371f * fTemp7) + (fRec164 + (fRec173 + fRec176)));
			output8[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec8[((IOTA - iConst14) & 1023)])));
			float fTemp59 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec187[1]) + (fConst4 * fRec184[1])))) + (fConst7 * (((((0.054349903f * fTemp9) + (0.0403231829f * fTemp11)) + (0.20473969f * fTemp13)) + (0.139943734f * fTemp10)) - (((0.124790564f * fTemp8) + (0.0516160093f * fTemp12)) + (0.19749473f * fTemp14))))));
			fRec189[0] = (fRec189[1] + fTemp59);
			fRec187[0] = fRec189[0];
			float fRec188 = fTemp59;
			fRec186[0] = (fRec187[0] + fRec186[1]);
			fRec184[0] = fRec186[0];
			float fRec185 = fRec188;
			float fTemp60 = (fConst8 * fRec181[1]);
			fRec183[0] = ((fRec185 + fRec183[1]) - fTemp60);
			fRec181[0] = fRec183[0];
			float fRec182 = (fRec185 - fTemp60);
			float fTemp61 = (fConst9 * (((0.152507901f * fTemp18) - ((0.0223175641f * fTemp17) + (0.125908941f * fTemp19))) - (fConst10 * fRec190[1])));
			fRec192[0] = (fRec192[1] + fTemp61);
			fRec190[0] = fRec192[0];
			float fRec191 = fTemp61;
			float fTemp62 = (fConst11 * ((((0.0747592598f * fTemp21) + (0.192663416f * fTemp24)) - (((0.0405323766f * fTemp22) + (0.180806756f * fTemp25)) + (0.206273779f * fTemp23))) + (fConst3 * (0.0f - ((fConst13 * fRec196[1]) + (fConst12 * fRec193[1]))))));
			fRec198[0] = (fRec198[1] + fTemp62);
			fRec196[0] = fRec198[0];
			float fRec197 = fTemp62;
			fRec195[0] = (fRec196[0] + fRec195[1]);
			fRec193[0] = fRec195[0];
			float fRec194 = fRec197;
			fVec9[(IOTA & 1023)] = ((0.0789035037f * fTemp7) + (fRec182 + (fRec191 + fRec194)));
			output9[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec9[((IOTA - iConst14) & 1023)])));
			float fTemp63 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec205[1]) + (fConst4 * fRec202[1])))) + (fConst7 * ((((0.141466811f * fTemp8) + (0.203323364f * fTemp13)) + (0.136777163f * fTemp10)) - ((((0.0592958517f * fTemp9) + (0.0450252965f * fTemp11)) + (0.0519870371f * fTemp12)) + (0.19039017f * fTemp14))))));
			fRec207[0] = (fRec207[1] + fTemp63);
			fRec205[0] = fRec207[0];
			float fRec206 = fTemp63;
			fRec204[0] = (fRec205[0] + fRec204[1]);
			fRec202[0] = fRec204[0];
			float fRec203 = fRec206;
			float fTemp64 = (fConst8 * fRec199[1]);
			fRec201[0] = ((fRec203 + fRec201[1]) - fTemp64);
			fRec199[0] = fRec201[0];
			float fRec200 = (fRec203 - fTemp64);
			float fTemp65 = (fConst9 * ((((0.0269974656f * fTemp17) + (0.151179001f * fTemp18)) - (0.125871882f * fTemp19)) - (fConst10 * fRec208[1])));
			fRec210[0] = (fRec210[1] + fTemp65);
			fRec208[0] = fRec210[0];
			float fRec209 = fTemp65;
			float fTemp66 = (fConst11 * ((((0.04409853f * fTemp22) + (0.190414622f * fTemp24)) - (((0.087534219f * fTemp21) + (0.179401666f * fTemp25)) + (0.204770505f * fTemp23))) + (fConst3 * (0.0f - ((fConst13 * fRec214[1]) + (fConst12 * fRec211[1]))))));
			fRec216[0] = (fRec216[1] + fTemp66);
			fRec214[0] = fRec216[0];
			float fRec215 = fTemp66;
			fRec213[0] = (fRec214[0] + fRec213[1]);
			fRec211[0] = fRec213[0];
			float fRec212 = fRec215;
			fVec10[(IOTA & 1023)] = ((0.0794107467f * fTemp7) + (fRec200 + (fRec209 + fRec212)));
			output10[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec10[((IOTA - iConst14) & 1023)])));
			float fTemp67 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec223[1]) + (fConst4 * fRec220[1])))) + (fConst7 * (((((0.229956612f * fTemp8) + (0.172543004f * fTemp13)) + (0.0530477092f * fTemp10)) + (0.0505424999f * fTemp14)) - (((0.135934904f * fTemp9) + (0.118328698f * fTemp11)) + (0.0536476597f * fTemp12))))));
			fRec225[0] = (fRec225[1] + fTemp67);
			fRec223[0] = fRec225[0];
			float fRec224 = fTemp67;
			fRec222[0] = (fRec223[0] + fRec222[1]);
			fRec220[0] = fRec222[0];
			float fRec221 = fRec224;
			float fTemp68 = (fConst8 * fRec217[1]);
			fRec219[0] = ((fRec221 + fRec219[1]) - fTemp68);
			fRec217[0] = fRec219[0];
			float fRec218 = (fRec221 - fTemp68);
			float fTemp69 = (fConst9 * ((((0.0702822506f * fTemp17) + (0.150386631f * fTemp18)) - (0.105620071f * fTemp19)) - (fConst10 * fRec226[1])));
			fRec228[0] = (fRec228[1] + fTemp69);
			fRec226[0] = fRec228[0];
			float fRec227 = fTemp69;
			float fTemp70 = (fConst11 * ((((0.119506948f * fTemp22) + (0.0774740726f * fTemp24)) - (((0.192688748f * fTemp21) + (0.177247822f * fTemp25)) + (0.173627004f * fTemp23))) + (fConst3 * (0.0f - ((fConst13 * fRec232[1]) + (fConst12 * fRec229[1]))))));
			fRec234[0] = (fRec234[1] + fTemp70);
			fRec232[0] = fRec234[0];
			float fRec233 = fTemp70;
			fRec231[0] = (fRec232[0] + fRec231[1]);
			fRec229[0] = fRec231[0];
			float fRec230 = fRec233;
			fVec11[(IOTA & 1023)] = ((0.0799569711f * fTemp7) + (fRec218 + (fRec227 + fRec230)));
			output11[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec11[((IOTA - iConst14) & 1023)])));
			float fTemp71 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec241[1]) + (fConst4 * fRec238[1])))) + (fConst7 * ((((0.0459832661f * fTemp8) + (0.11683061f * fTemp13)) + (0.2274459f * fTemp14)) - ((((0.135821447f * fTemp9) + (0.171425074f * fTemp11)) + (0.0556686781f * fTemp12)) + (0.0602593198f * fTemp10))))));
			fRec243[0] = (fRec243[1] + fTemp71);
			fRec241[0] = fRec243[0];
			float fRec242 = fTemp71;
			fRec240[0] = (fRec241[0] + fRec240[1]);
			fRec238[0] = fRec240[0];
			float fRec239 = fRec242;
			float fTemp72 = (fConst8 * fRec235[1]);
			fRec237[0] = ((fRec239 + fRec237[1]) - fTemp72);
			fRec235[0] = fRec237[0];
			float fRec236 = (fRec239 - fTemp72);
			float fTemp73 = (fConst9 * ((((0.104553297f * fTemp17) + (0.150337458f * fTemp18)) - (0.0699313059f * fTemp19)) - (fConst10 * fRec244[1])));
			fRec246[0] = (fRec246[1] + fTemp73);
			fRec244[0] = fRec246[0];
			float fRec245 = fTemp73;
			float fTemp74 = (fConst11 * (((0.176804766f * fTemp22) - ((((0.188898057f * fTemp21) + (0.175306946f * fTemp25)) + (0.117919371f * fTemp23)) + (0.0774369314f * fTemp24))) + (fConst3 * (0.0f - ((fConst13 * fRec250[1]) + (fConst12 * fRec247[1]))))));
			fRec252[0] = (fRec252[1] + fTemp74);
			fRec250[0] = fRec252[0];
			float fRec251 = fTemp74;
			fRec249[0] = (fRec250[0] + fRec249[1]);
			fRec247[0] = fRec249[0];
			float fRec248 = fRec251;
			fVec12[(IOTA & 1023)] = ((0.080257006f * fTemp7) + (fRec236 + (fRec245 + fRec248)));
			output12[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec12[((IOTA - iConst14) & 1023)])));
			float fTemp75 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec259[1]) + (fConst4 * fRec256[1])))) + (fConst7 * (((0.0455419645f * fTemp13) + (0.141557083f * fTemp14)) - (((((0.186730742f * fTemp8) + (0.0630886182f * fTemp9)) + (0.199714676f * fTemp11)) + (0.0569221564f * fTemp12)) + (0.13965784f * fTemp10))))));
			fRec261[0] = (fRec261[1] + fTemp75);
			fRec259[0] = fRec261[0];
			float fRec260 = fTemp75;
			fRec258[0] = (fRec259[0] + fRec258[1]);
			fRec256[0] = fRec258[0];
			float fRec257 = fRec260;
			float fTemp76 = (fConst8 * fRec253[1]);
			fRec255[0] = ((fRec257 + fRec255[1]) - fTemp76);
			fRec253[0] = fRec255[0];
			float fRec254 = (fRec257 - fTemp76);
			float fTemp77 = (fConst9 * ((((0.125054896f * fTemp17) + (0.150657937f * fTemp18)) - (0.0265217982f * fTemp19)) - (fConst10 * fRec262[1])));
			fRec264[0] = (fRec264[1] + fTemp77);
			fRec262[0] = fRec264[0];
			float fRec263 = fTemp77;
			float fTemp78 = (fConst11 * (((0.20813778f * fTemp22) - ((((0.0859115496f * fTemp21) + (0.174560443f * fTemp25)) + (0.04678303f * fTemp23)) + (0.187298864f * fTemp24))) + (fConst3 * (0.0f - ((fConst13 * fRec268[1]) + (fConst12 * fRec265[1]))))));
			fRec270[0] = (fRec270[1] + fTemp78);
			fRec268[0] = fRec270[0];
			float fRec269 = fTemp78;
			fRec267[0] = (fRec268[0] + fRec267[1]);
			fRec265[0] = fRec267[0];
			float fRec266 = fRec269;
			fVec13[(IOTA & 1023)] = ((0.0805214942f * fTemp7) + (fRec254 + (fRec263 + fRec266)));
			output13[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec13[((IOTA - iConst14) & 1023)])));
			float fTemp79 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec277[1]) + (fConst4 * fRec274[1])))) + (fConst7 * ((0.051229056f * fTemp9) - ((((((0.203914493f * fTemp8) + (0.202355266f * fTemp11)) + (0.0568680055f * fTemp12)) + (0.0382907055f * fTemp13)) + (0.144620731f * fTemp10)) + (0.121061198f * fTemp14))))));
			fRec279[0] = (fRec279[1] + fTemp79);
			fRec277[0] = fRec279[0];
			float fRec278 = fTemp79;
			fRec276[0] = (fRec277[0] + fRec276[1]);
			fRec274[0] = fRec276[0];
			float fRec275 = fRec278;
			float fTemp80 = (fConst8 * fRec271[1]);
			fRec273[0] = ((fRec275 + fRec273[1]) - fTemp80);
			fRec271[0] = fRec273[0];
			float fRec272 = (fRec275 - fTemp80);
			float fTemp81 = (fConst9 * (((0.128043652f * fTemp17) + ((0.150956526f * fTemp18) + (0.0230083186f * fTemp19))) - (fConst10 * fRec280[1])));
			fRec282[0] = (fRec282[1] + fTemp81);
			fRec280[0] = fRec282[0];
			float fRec281 = fTemp81;
			float fTemp82 = (fConst11 * (((((0.0727000833f * fTemp21) + (0.210371837f * fTemp22)) + (0.0377832651f * fTemp23)) - ((0.175354689f * fTemp25) + (0.195759654f * fTemp24))) + (fConst3 * (0.0f - ((fConst13 * fRec286[1]) + (fConst12 * fRec283[1]))))));
			fRec288[0] = (fRec288[1] + fTemp82);
			fRec286[0] = fRec288[0];
			float fRec287 = fTemp82;
			fRec285[0] = (fRec286[0] + fRec285[1]);
			fRec283[0] = fRec285[0];
			float fRec284 = fRec287;
			fVec14[(IOTA & 1023)] = ((0.0809824541f * fTemp7) + (fRec272 + (fRec281 + fRec284)));
			output14[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec14[((IOTA - iConst14) & 1023)])));
			float fTemp83 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec295[1]) + (fConst4 * fRec292[1])))) + (fConst7 * (((0.0257722028f * fTemp8) + (0.133474961f * fTemp9)) - (((((0.17651616f * fTemp11) + (0.0557496548f * fTemp12)) + (0.112579919f * fTemp13)) + (0.0677374676f * fTemp10)) + (0.234672233f * fTemp14))))));
			fRec297[0] = (fRec297[1] + fTemp83);
			fRec295[0] = fRec297[0];
			float fRec296 = fTemp83;
			fRec294[0] = (fRec295[0] + fRec294[1]);
			fRec292[0] = fRec294[0];
			float fRec293 = fRec296;
			float fTemp84 = (fConst8 * fRec289[1]);
			fRec291[0] = ((fRec293 + fRec291[1]) - fTemp84);
			fRec289[0] = fRec291[0];
			float fRec290 = (fRec293 - fTemp84);
			float fTemp85 = (fConst9 * (((0.110282697f * fTemp17) + ((0.151175082f * fTemp18) + (0.0677397847f * fTemp19))) - (fConst10 * fRec298[1])));
			fRec300[0] = (fRec300[1] + fTemp85);
			fRec298[0] = fRec300[0];
			float fRec299 = fTemp85;
			float fTemp86 = (fConst11 * (((((0.187024504f * fTemp21) + (0.181362808f * fTemp22)) + (0.114309736f * fTemp23)) - ((0.177093536f * fTemp25) + (0.0914811864f * fTemp24))) + (fConst3 * (0.0f - ((fConst13 * fRec304[1]) + (fConst12 * fRec301[1]))))));
			fRec306[0] = (fRec306[1] + fTemp86);
			fRec304[0] = fRec306[0];
			float fRec305 = fTemp86;
			fRec303[0] = (fRec304[0] + fRec303[1]);
			fRec301[0] = fRec303[0];
			float fRec302 = fRec305;
			fVec15[(IOTA & 1023)] = ((0.0813522041f * fTemp7) + (fRec290 + (fRec299 + fRec302)));
			output15[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec15[((IOTA - iConst14) & 1023)])));
			float fTemp87 = (fConst15 * ((fConst3 * (0.0f - ((fConst17 * fRec313[1]) + (fConst16 * fRec310[1])))) + (fConst19 * (((((((0.129928842f * fTemp8) + (0.266343892f * fTemp9)) + (0.0691473112f * fTemp11)) + (0.171123326f * fTemp13)) + (0.277946115f * fTemp10)) + (0.0569466241f * fTemp14)) - (0.246465489f * fTemp12)))));
			fRec315[0] = (fRec315[1] + fTemp87);
			fRec313[0] = fRec315[0];
			float fRec314 = fTemp87;
			fRec312[0] = (fRec313[0] + fRec312[1]);
			fRec310[0] = fRec312[0];
			float fRec311 = fRec314;
			float fTemp88 = (fConst20 * fRec307[1]);
			fRec309[0] = ((fRec311 + fRec309[1]) - fTemp88);
			fRec307[0] = fRec309[0];
			float fRec308 = (fRec311 - fTemp88);
			float fTemp89 = (fConst21 * (((0.0708236843f * fTemp17) + ((0.0301519744f * fTemp18) + (0.17470777f * fTemp19))) - (fConst22 * fRec316[1])));
			fRec318[0] = (fRec318[1] + fTemp89);
			fRec316[0] = fRec318[0];
			float fRec317 = fTemp89;
			float fTemp90 = (fConst23 * ((((((0.0658472553f * fTemp21) + (0.115861163f * fTemp22)) + (0.174544141f * fTemp25)) + (0.277383447f * fTemp23)) + (0.0652571693f * fTemp24)) + (fConst3 * (0.0f - ((fConst25 * fRec322[1]) + (fConst24 * fRec319[1]))))));
			fRec324[0] = (fRec324[1] + fTemp90);
			fRec322[0] = fRec324[0];
			float fRec323 = fTemp90;
			fRec321[0] = (fRec322[0] + fRec321[1]);
			fRec319[0] = fRec321[0];
			float fRec320 = fRec323;
			fVec16[(IOTA & 511)] = ((0.183395863f * fTemp7) + (fRec308 + (fRec317 + fRec320)));
			output16[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec16[((IOTA - iConst26) & 511)])));
			float fTemp91 = (fConst15 * ((fConst3 * (0.0f - ((fConst17 * fRec331[1]) + (fConst16 * fRec328[1])))) + (fConst19 * ((((0.16925998f * fTemp13) + (0.27389431f * fTemp10)) + (0.0524643734f * fTemp14)) - ((((0.132005215f * fTemp8) + (0.273072243f * fTemp9)) + (0.0709334761f * fTemp11)) + (0.247545272f * fTemp12))))));
			fRec333[0] = (fRec333[1] + fTemp91);
			fRec331[0] = fRec333[0];
			float fRec332 = fTemp91;
			fRec330[0] = (fRec331[0] + fRec330[1]);
			fRec328[0] = fRec330[0];
			float fRec329 = fRec332;
			float fTemp92 = (fConst20 * fRec325[1]);
			fRec327[0] = ((fRec329 + fRec327[1]) - fTemp92);
			fRec325[0] = fRec327[0];
			float fRec326 = (fRec329 - fTemp92);
			float fTemp93 = (fConst21 * ((((0.0304611083f * fTemp18) + (0.174798712f * fTemp19)) - (0.0735848099f * fTemp17)) - (fConst22 * fRec334[1])));
			fRec336[0] = (fRec336[1] + fTemp93);
			fRec334[0] = fRec336[0];
			float fRec335 = fTemp93;
			float fTemp94 = (fConst23 * (((((0.175342366f * fTemp25) + (0.277159363f * fTemp23)) + (0.0641784668f * fTemp24)) - ((0.0666037053f * fTemp21) + (0.117828205f * fTemp22))) + (fConst3 * (0.0f - ((fConst25 * fRec340[1]) + (fConst24 * fRec337[1]))))));
			fRec342[0] = (fRec342[1] + fTemp94);
			fRec340[0] = fRec342[0];
			float fRec341 = fTemp94;
			fRec339[0] = (fRec340[0] + fRec339[1]);
			fRec337[0] = fRec339[0];
			float fRec338 = fRec341;
			fVec17[(IOTA & 511)] = ((0.18333903f * fTemp7) + (fRec326 + (fRec335 + fRec338)));
			output17[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec17[((IOTA - iConst26) & 511)])));
			float fTemp95 = (fConst15 * ((fConst3 * (0.0f - ((fConst17 * fRec349[1]) + (fConst16 * fRec346[1])))) + (fConst19 * (((0.0664764941f * fTemp8) + (0.0646144152f * fTemp13)) - (((((0.254508585f * fTemp9) + (0.171438307f * fTemp11)) + (0.250091642f * fTemp12)) + (0.293999612f * fTemp10)) + (0.126623839f * fTemp14))))));
			fRec351[0] = (fRec351[1] + fTemp95);
			fRec349[0] = fRec351[0];
			float fRec350 = fTemp95;
			fRec348[0] = (fRec349[0] + fRec348[1]);
			fRec346[0] = fRec348[0];
			float fRec347 = fRec350;
			float fTemp96 = (fConst20 * fRec343[1]);
			fRec345[0] = ((fRec347 + fRec345[1]) - fTemp96);
			fRec343[0] = fRec345[0];
			float fRec344 = (fRec347 - fTemp96);
			float fTemp97 = (fConst21 * ((((0.0296976492f * fTemp18) + (0.0668916181f * fTemp19)) - (0.176876515f * fTemp17)) - (fConst22 * fRec352[1])));
			fRec354[0] = (fRec354[1] + fTemp97);
			fRec352[0] = fRec354[0];
			float fRec353 = fTemp97;
			float fTemp98 = (fConst23 * ((((0.176835299f * fTemp25) + (0.108309373f * fTemp23)) - (((0.0631847456f * fTemp21) + (0.284614265f * fTemp22)) + (0.0689972118f * fTemp24))) + (fConst3 * (0.0f - ((fConst25 * fRec358[1]) + (fConst24 * fRec355[1]))))));
			fRec360[0] = (fRec360[1] + fTemp98);
			fRec358[0] = fRec360[0];
			float fRec359 = fTemp98;
			fRec357[0] = (fRec358[0] + fRec357[1]);
			fRec355[0] = fRec357[0];
			float fRec356 = fRec359;
			fVec18[(IOTA & 511)] = ((0.185234532f * fTemp7) + (fRec344 + (fRec353 + fRec356)));
			output18[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec18[((IOTA - iConst26) & 511)])));
			float fTemp99 = (fConst15 * ((fConst3 * (0.0f - ((fConst17 * fRec367[1]) + (fConst16 * fRec364[1])))) + (fConst19 * ((((0.0364651643f * fTemp8) + (0.291914433f * fTemp9)) + (0.13821952f * fTemp14)) - ((((0.164095461f * fTemp11) + (0.24629055f * fTemp12)) + (0.0763883665f * fTemp13)) + (0.251508743f * fTemp10))))));
			fRec369[0] = (fRec369[1] + fTemp99);
			fRec367[0] = fRec369[0];
			float fRec368 = fTemp99;
			fRec366[0] = (fRec367[0] + fRec366[1]);
			fRec364[0] = fRec366[0];
			float fRec365 = fRec368;
			float fTemp100 = (fConst20 * fRec361[1]);
			fRec363[0] = ((fRec365 + fRec363[1]) - fTemp100);
			fRec361[0] = fRec363[0];
			float fRec362 = (fRec365 - fTemp100);
			float fTemp101 = (fConst21 * (((0.0315316021f * fTemp18) - ((0.171046257f * fTemp17) + (0.0796997398f * fTemp19))) - (fConst22 * fRec370[1])));
			fRec372[0] = (fRec372[1] + fTemp101);
			fRec370[0] = fRec372[0];
			float fRec371 = fTemp101;
			float fTemp102 = (fConst23 * ((((0.0738038197f * fTemp21) + (0.173070818f * fTemp25)) - (((0.27148807f * fTemp22) + (0.127863377f * fTemp23)) + (0.0584145449f * fTemp24))) + (fConst3 * (0.0f - ((fConst25 * fRec376[1]) + (fConst24 * fRec373[1]))))));
			fRec378[0] = (fRec378[1] + fTemp102);
			fRec376[0] = fRec378[0];
			float fRec377 = fTemp102;
			fRec375[0] = (fRec376[0] + fRec375[1]);
			fRec373[0] = fRec375[0];
			float fRec374 = fRec377;
			fVec19[(IOTA & 511)] = ((0.182793453f * fTemp7) + (fRec362 + (fRec371 + fRec374)));
			output19[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec19[((IOTA - iConst26) & 511)])));
			float fTemp103 = (fConst15 * ((fConst3 * (0.0f - ((fConst17 * fRec385[1]) + (fConst16 * fRec382[1])))) + (fConst19 * (((0.252162874f * fTemp9) + (0.284346104f * fTemp10)) - (((((0.124466375f * fTemp8) + (0.0651137158f * fTemp11)) + (0.239980549f * fTemp12)) + (0.168873221f * fTemp13)) + (0.0631815046f * fTemp14))))));
			fRec387[0] = (fRec387[1] + fTemp103);
			fRec385[0] = fRec387[0];
			float fRec386 = fTemp103;
			fRec384[0] = (fRec385[0] + fRec384[1]);
			fRec382[0] = fRec384[0];
			float fRec383 = fRec386;
			float fTemp104 = (fConst20 * fRec379[1]);
			fRec381[0] = ((fRec383 + fRec381[1]) - fTemp104);
			fRec379[0] = fRec381[0];
			float fRec380 = (fRec383 - fTemp104);
			float fTemp105 = (fConst21 * (((0.0323959552f * fTemp18) - ((0.0668478683f * fTemp17) + (0.173329547f * fTemp19))) - (fConst22 * fRec388[1])));
			fRec390[0] = (fRec390[1] + fTemp105);
			fRec388[0] = fRec390[0];
			float fRec389 = fTemp105;
			float fTemp106 = (fConst23 * (((((0.0613467991f * fTemp21) + (0.168646619f * fTemp25)) + (0.0667670146f * fTemp24)) - ((0.106367759f * fTemp22) + (0.273657769f * fTemp23))) + (fConst3 * (0.0f - ((fConst25 * fRec394[1]) + (fConst24 * fRec391[1]))))));
			fRec396[0] = (fRec396[1] + fTemp106);
			fRec394[0] = fRec396[0];
			float fRec395 = fTemp106;
			fRec393[0] = (fRec394[0] + fRec393[1]);
			fRec391[0] = fRec393[0];
			float fRec392 = fRec395;
			fVec20[(IOTA & 511)] = ((0.179619446f * fTemp7) + (fRec380 + (fRec389 + fRec392)));
			output20[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec20[((IOTA - iConst26) & 511)])));
			float fTemp107 = (fConst23 * (((((0.107048161f * fTemp22) + (0.171027735f * fTemp25)) + (0.0676470548f * fTemp24)) - ((0.0623452887f * fTemp21) + (0.272611588f * fTemp23))) + (fConst3 * (0.0f - ((fConst25 * fRec400[1]) + (fConst24 * fRec397[1]))))));
			fRec402[0] = (fRec402[1] + fTemp107);
			fRec400[0] = fRec402[0];
			float fRec401 = fTemp107;
			fRec399[0] = (fRec400[0] + fRec399[1]);
			fRec397[0] = fRec399[0];
			float fRec398 = fRec401;
			float fTemp108 = (fConst21 * ((((0.0671670809f * fTemp17) + (0.0298743527f * fTemp18)) - (0.17436336f * fTemp19)) - (fConst22 * fRec403[1])));
			fRec405[0] = (fRec405[1] + fTemp108);
			fRec403[0] = fRec405[0];
			float fRec404 = fTemp108;
			float fTemp109 = (fConst15 * ((fConst3 * (0.0f - ((fConst17 * fRec412[1]) + (fConst16 * fRec409[1])))) + (fConst19 * ((((0.125441328f * fTemp8) + (0.065604791f * fTemp11)) + (0.285587251f * fTemp10)) - ((((0.253556848f * fTemp9) + (0.24061507f * fTemp12)) + (0.170164675f * fTemp13)) + (0.064895153f * fTemp14))))));
			fRec414[0] = (fRec414[1] + fTemp109);
			fRec412[0] = fRec414[0];
			float fRec413 = fTemp109;
			fRec411[0] = (fRec412[0] + fRec411[1]);
			fRec409[0] = fRec411[0];
			float fRec410 = fRec413;
			float fTemp110 = (fConst20 * fRec406[1]);
			fRec408[0] = ((fRec410 + fRec408[1]) - fTemp110);
			fRec406[0] = fRec408[0];
			float fRec407 = (fRec410 - fTemp110);
			fVec21[(IOTA & 511)] = ((0.180832431f * fTemp7) + (fRec398 + (fRec404 + fRec407)));
			output21[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec21[((IOTA - iConst26) & 511)])));
			float fTemp111 = (fConst15 * ((fConst3 * (0.0f - ((fConst17 * fRec421[1]) + (fConst16 * fRec418[1])))) + (fConst19 * (((0.170521393f * fTemp11) + (0.134050816f * fTemp14)) - (((((0.0417343229f * fTemp8) + (0.285005987f * fTemp9)) + (0.247401625f * fTemp12)) + (0.0760966167f * fTemp13)) + (0.258281201f * fTemp10))))));
			fRec423[0] = (fRec423[1] + fTemp111);
			fRec421[0] = fRec423[0];
			float fRec422 = fTemp111;
			fRec420[0] = (fRec421[0] + fRec420[1]);
			fRec418[0] = fRec420[0];
			float fRec419 = fRec422;
			float fTemp112 = (fConst20 * fRec415[1]);
			fRec417[0] = ((fRec419 + fRec417[1]) - fTemp112);
			fRec415[0] = fRec417[0];
			float fRec416 = (fRec419 - fTemp112);
			float fTemp113 = (fConst21 * ((((0.171344355f * fTemp17) + (0.0278569851f * fTemp18)) - (0.0772481412f * fTemp19)) - (fConst22 * fRec424[1])));
			fRec426[0] = (fRec426[1] + fTemp113);
			fRec424[0] = fRec426[0];
			float fRec425 = fTemp113;
			float fTemp114 = (fConst23 * ((((0.269503593f * fTemp22) + (0.177593544f * fTemp25)) - (((0.0681558102f * fTemp21) + (0.122882687f * fTemp23)) + (0.0592721775f * fTemp24))) + (fConst3 * (0.0f - ((fConst25 * fRec430[1]) + (fConst24 * fRec427[1]))))));
			fRec432[0] = (fRec432[1] + fTemp114);
			fRec430[0] = fRec432[0];
			float fRec431 = fTemp114;
			fRec429[0] = (fRec430[0] + fRec429[1]);
			fRec427[0] = fRec429[0];
			float fRec428 = fRec431;
			fVec22[(IOTA & 511)] = ((0.183686823f * fTemp7) + (fRec416 + (fRec425 + fRec428)));
			output22[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec22[((IOTA - iConst26) & 511)])));
			float fTemp115 = (fConst21 * (((0.176851153f * fTemp17) + ((0.0284732208f * fTemp18) + (0.0697356835f * fTemp19))) - (fConst22 * fRec433[1])));
			fRec435[0] = (fRec435[1] + fTemp115);
			fRec433[0] = fRec435[0];
			float fRec434 = fTemp115;
			float fTemp116 = (fConst23 * ((((((0.0631834567f * fTemp21) + (0.277794689f * fTemp22)) + (0.177968666f * fTemp25)) + (0.111204818f * fTemp23)) - (0.0667784438f * fTemp24)) + (fConst3 * (0.0f - ((fConst25 * fRec439[1]) + (fConst24 * fRec436[1]))))));
			fRec441[0] = (fRec441[1] + fTemp116);
			fRec439[0] = fRec441[0];
			float fRec440 = fTemp116;
			fRec438[0] = (fRec439[0] + fRec438[1]);
			fRec436[0] = fRec438[0];
			float fRec437 = fRec440;
			float fTemp117 = (fConst15 * ((fConst3 * (0.0f - ((fConst17 * fRec448[1]) + (fConst16 * fRec445[1])))) + (fConst19 * ((((0.264052242f * fTemp9) + (0.173452884f * fTemp11)) + (0.067378588f * fTemp13)) - ((((0.0601888299f * fTemp8) + (0.24932538f * fTemp12)) + (0.285375029f * fTemp10)) + (0.128828615f * fTemp14))))));
			fRec450[0] = (fRec450[1] + fTemp117);
			fRec448[0] = fRec450[0];
			float fRec449 = fTemp117;
			fRec447[0] = (fRec448[0] + fRec447[1]);
			fRec445[0] = fRec447[0];
			float fRec446 = fRec449;
			float fTemp118 = (fConst20 * fRec442[1]);
			fRec444[0] = ((fRec446 + fRec444[1]) - fTemp118);
			fRec442[0] = fRec444[0];
			float fRec443 = (fRec446 - fTemp118);
			fVec23[(IOTA & 511)] = ((0.184734806f * fTemp7) + (fRec434 + (fRec437 + fRec443)));
			output23[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec23[((IOTA - iConst26) & 511)])));
			float fTemp119 = (fConst27 * ((fConst3 * (0.0f - ((fConst29 * fRec457[1]) + (fConst28 * fRec454[1])))) + (fConst31 * (((((((0.00662300922f * fTemp8) + (0.126196831f * fTemp9)) + (0.35925442f * fTemp11)) + (0.227164567f * fTemp12)) + (0.358558953f * fTemp13)) + (0.000372940412f * fTemp10)) - (0.00665140012f * fTemp14)))));
			fRec459[0] = (fRec459[1] + fTemp119);
			fRec457[0] = fRec459[0];
			float fRec458 = fTemp119;
			fRec456[0] = (fRec457[0] + fRec456[1]);
			fRec454[0] = fRec456[0];
			float fRec455 = fRec458;
			float fTemp120 = (fConst32 * fRec451[1]);
			fRec453[0] = ((fRec455 + fRec453[1]) - fTemp120);
			fRec451[0] = fRec453[0];
			float fRec452 = (fRec455 - fTemp120);
			float fTemp121 = (fConst33 * (((0.170545951f * fTemp17) + ((0.224340498f * fTemp18) + (0.170221686f * fTemp19))) - (fConst34 * fRec460[1])));
			fRec462[0] = (fRec462[1] + fTemp121);
			fRec460[0] = fRec462[0];
			float fRec461 = fTemp121;
			float fTemp122 = (fConst35 * ((((((0.00623398134f * fTemp21) + (0.0164986048f * fTemp22)) + (0.229997918f * fTemp25)) + (0.0140721733f * fTemp23)) - (0.000417499396f * fTemp24)) + (fConst3 * (0.0f - ((fConst37 * fRec466[1]) + (fConst36 * fRec463[1]))))));
			fRec468[0] = (fRec468[1] + fTemp122);
			fRec466[0] = fRec468[0];
			float fRec467 = fTemp122;
			fRec465[0] = (fRec466[0] + fRec465[1]);
			fRec463[0] = fRec465[0];
			float fRec464 = fRec467;
			fVec24[(IOTA & 255)] = ((0.161377579f * fTemp7) + (fRec452 + (fRec461 + fRec464)));
			output24[i] = FAUSTFLOAT((0.953550935f * (fRec0[0] * fVec24[((IOTA - iConst38) & 255)])));
			float fTemp123 = (fConst27 * ((fConst3 * (0.0f - ((fConst29 * fRec475[1]) + (fConst28 * fRec472[1])))) + (fConst31 * ((((0.226113051f * fTemp12) + (0.358148545f * fTemp13)) + (0.00054387952f * fTemp10)) - ((((0.00632870523f * fTemp8) + (0.126230061f * fTemp9)) + (0.359592617f * fTemp11)) + (0.00749808224f * fTemp14))))));
			fRec477[0] = (fRec477[1] + fTemp123);
			fRec475[0] = fRec477[0];
			float fRec476 = fTemp123;
			fRec474[0] = (fRec475[0] + fRec474[1]);
			fRec472[0] = fRec474[0];
			float fRec473 = fRec476;
			float fTemp124 = (fConst32 * fRec469[1]);
			fRec471[0] = ((fRec473 + fRec471[1]) - fTemp124);
			fRec469[0] = fRec471[0];
			float fRec470 = (fRec473 - fTemp124);
			float fTemp125 = (fConst33 * ((((0.222355738f * fTemp18) + (0.170260623f * fTemp19)) - (0.171076179f * fTemp17)) - (fConst34 * fRec478[1])));
			fRec480[0] = (fRec480[1] + fTemp125);
			fRec478[0] = fRec480[0];
			float fRec479 = fTemp125;
			float fTemp126 = (fConst35 * (((((0.232364699f * fTemp25) + (0.0150450831f * fTemp23)) + (0.000143985293f * fTemp24)) - ((0.00616362924f * fTemp21) + (0.0164758377f * fTemp22))) + (fConst3 * (0.0f - ((fConst37 * fRec484[1]) + (fConst36 * fRec481[1]))))));
			fRec486[0] = (fRec486[1] + fTemp126);
			fRec484[0] = fRec486[0];
			float fRec485 = fTemp126;
			fRec483[0] = (fRec484[0] + fRec483[1]);
			fRec481[0] = fRec483[0];
			float fRec482 = fRec485;
			fVec25[(IOTA & 255)] = ((0.162064657f * fTemp7) + (fRec470 + (fRec479 + fRec482)));
			output25[i] = FAUSTFLOAT((0.953550935f * (fRec0[0] * fVec25[((IOTA - iConst38) & 255)])));
			float fTemp127 = (fConst27 * ((fConst3 * (0.0f - ((fConst29 * fRec493[1]) + (fConst28 * fRec490[1])))) + (fConst31 * ((((0.122740388f * fTemp9) + (0.231224477f * fTemp12)) + (0.00681099761f * fTemp14)) - ((((0.00587446848f * fTemp8) + (0.359305203f * fTemp11)) + (0.3568919f * fTemp13)) + (0.00328544341f * fTemp10))))));
			fRec495[0] = (fRec495[1] + fTemp127);
			fRec493[0] = fRec495[0];
			float fRec494 = fTemp127;
			fRec492[0] = (fRec493[0] + fRec492[1]);
			fRec490[0] = fRec492[0];
			float fRec491 = fRec494;
			float fTemp128 = (fConst32 * fRec487[1]);
			fRec489[0] = ((fRec491 + fRec489[1]) - fTemp128);
			fRec487[0] = fRec489[0];
			float fRec488 = (fRec491 - fTemp128);
			float fTemp129 = (fConst33 * (((0.225024834f * fTemp18) - ((0.170818225f * fTemp17) + (0.168984294f * fTemp19))) - (fConst34 * fRec496[1])));
			fRec498[0] = (fRec498[1] + fTemp129);
			fRec496[0] = fRec498[0];
			float fRec497 = fTemp129;
			float fTemp130 = (fConst35 * (((((0.00622403855f * fTemp21) + (0.226742908f * fTemp25)) + (9.66254011e-05f * fTemp24)) - ((0.0145585248f * fTemp22) + (0.0131325293f * fTemp23))) + (fConst3 * (0.0f - ((fConst37 * fRec502[1]) + (fConst36 * fRec499[1]))))));
			fRec504[0] = (fRec504[1] + fTemp130);
			fRec502[0] = fRec504[0];
			float fRec503 = fTemp130;
			fRec501[0] = (fRec502[0] + fRec501[1]);
			fRec499[0] = fRec501[0];
			float fRec500 = fRec503;
			fVec26[(IOTA & 255)] = ((0.159303993f * fTemp7) + (fRec488 + (fRec497 + fRec500)));
			output26[i] = FAUSTFLOAT((0.953550935f * (fRec0[0] * fVec26[((IOTA - iConst38) & 255)])));
			float fTemp131 = (fConst27 * ((fConst31 * (((((0.00595481694f * fTemp8) + (0.359264106f * fTemp11)) + (0.231563836f * fTemp12)) + (0.00732591283f * fTemp14)) - (((0.123768471f * fTemp9) + (0.357470602f * fTemp13)) + (0.00230165967f * fTemp10)))) + (fConst3 * (0.0f - ((fConst29 * fRec511[1]) + (fConst28 * fRec508[1]))))));
			fRec513[0] = (fRec513[1] + fTemp131);
			fRec511[0] = fRec513[0];
			float fRec512 = fTemp131;
			fRec510[0] = (fRec511[0] + fRec510[1]);
			fRec508[0] = fRec510[0];
			float fRec509 = fRec512;
			float fTemp132 = (fConst32 * fRec505[1]);
			fRec507[0] = ((fRec509 + fRec507[1]) - fTemp132);
			fRec505[0] = fRec507[0];
			float fRec506 = (fRec509 - fTemp132);
			float fTemp133 = (fConst33 * ((((0.170531079f * fTemp17) + (0.225941733f * fTemp18)) - (0.169340909f * fTemp19)) - (fConst34 * fRec514[1])));
			fRec516[0] = (fRec516[1] + fTemp133);
			fRec514[0] = fRec516[0];
			float fRec515 = fTemp133;
			float fTemp134 = (fConst35 * ((((0.0157277714f * fTemp22) + (0.22573249f * fTemp25)) - (((0.00634190487f * fTemp21) + (0.0132789239f * fTemp23)) + (0.000511749298f * fTemp24))) + (fConst3 * (0.0f - ((fConst37 * fRec520[1]) + (fConst36 * fRec517[1]))))));
			fRec522[0] = (fRec522[1] + fTemp134);
			fRec520[0] = fRec522[0];
			float fRec521 = fTemp134;
			fRec519[0] = (fRec520[0] + fRec519[1]);
			fRec517[0] = fRec519[0];
			float fRec518 = fRec521;
			fVec27[(IOTA & 255)] = ((0.159218952f * fTemp7) + (fRec506 + (fRec515 + fRec518)));
			output27[i] = FAUSTFLOAT((0.953550935f * (fRec0[0] * fVec27[((IOTA - iConst38) & 255)])));
			float fTemp135 = (fConst39 * ((fConst3 * (0.0f - ((fConst41 * fRec529[1]) + (fConst40 * fRec526[1])))) + (fConst43 * ((((9.22014005e-05f * fTemp8) + (0.447217971f * fTemp12)) + (0.000335796707f * fTemp13)) - ((((0.000180994597f * fTemp9) + (0.000348522299f * fTemp11)) + (0.000233055805f * fTemp10)) + (2.13890999e-05f * fTemp14))))));
			fRec531[0] = (fRec531[1] + fTemp135);
			fRec529[0] = fRec531[0];
			float fRec530 = fTemp135;
			fRec528[0] = (fRec529[0] + fRec528[1]);
			fRec526[0] = fRec528[0];
			float fRec527 = fRec530;
			float fTemp136 = (fConst44 * fRec523[1]);
			fRec525[0] = ((fRec527 + fRec525[1]) - fTemp136);
			fRec523[0] = fRec525[0];
			float fRec524 = (fRec527 - fTemp136);
			float fTemp137 = (fConst45 * ((((0.371741682f * fTemp18) + (0.000357547309f * fTemp19)) - (0.000292339886f * fTemp17)) - (fConst46 * fRec532[1])));
			fRec534[0] = (fRec534[1] + fTemp137);
			fRec532[0] = fRec534[0];
			float fRec533 = fTemp137;
			float fTemp138 = (fConst47 * ((((0.000706973078f * fTemp22) + (0.125658303f * fTemp25)) - (((2.94628007e-05f * fTemp21) + (1.98041998e-05f * fTemp23)) + (0.000124590297f * fTemp24))) + (fConst3 * (0.0f - ((fConst49 * fRec538[1]) + (fConst48 * fRec535[1]))))));
			fRec540[0] = (fRec540[1] + fTemp138);
			fRec538[0] = fRec540[0];
			float fRec539 = fTemp138;
			fRec537[0] = (fRec538[0] + fRec537[1]);
			fRec535[0] = fRec537[0];
			float fRec536 = fRec539;
			output28[i] = FAUSTFLOAT((fRec0[0] * ((0.107219175f * fTemp7) + (fRec524 + (fRec533 + fRec536)))));
			float fTemp139 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec547[1]) + (fConst4 * fRec544[1])))) + (fConst7 * ((((0.241654605f * fTemp8) + (0.0790398046f * fTemp12)) + (0.0794952512f * fTemp14)) - ((((0.125738993f * fTemp9) + (0.0314656533f * fTemp11)) + (0.0658324808f * fTemp13)) + (0.116670616f * fTemp10))))));
			fRec549[0] = (fRec549[1] + fTemp139);
			fRec547[0] = fRec549[0];
			float fRec548 = fTemp139;
			fRec546[0] = (fRec547[0] + fRec546[1]);
			fRec544[0] = fRec546[0];
			float fRec545 = fRec548;
			float fTemp140 = (fConst8 * fRec541[1]);
			fRec543[0] = ((fRec545 + fRec543[1]) - fTemp140);
			fRec541[0] = fRec543[0];
			float fRec542 = (fRec545 - fTemp140);
			float fTemp141 = (fConst9 * ((((0.114983477f * fTemp17) + (0.260578573f * fTemp19)) - (0.143181607f * fTemp18)) - (fConst10 * fRec550[1])));
			fRec552[0] = (fRec552[1] + fTemp141);
			fRec550[0] = fRec552[0];
			float fRec551 = fTemp141;
			float fTemp142 = (fConst11 * ((((0.213112175f * fTemp21) + (0.192354947f * fTemp24)) - (((0.0821826085f * fTemp22) + (0.061959032f * fTemp25)) + (0.183261499f * fTemp23))) + (fConst3 * (0.0f - ((fConst13 * fRec556[1]) + (fConst12 * fRec553[1]))))));
			fRec558[0] = (fRec558[1] + fTemp142);
			fRec556[0] = fRec558[0];
			float fRec557 = fTemp142;
			fRec555[0] = (fRec556[0] + fRec555[1]);
			fRec553[0] = fRec555[0];
			float fRec554 = fRec557;
			fVec28[(IOTA & 1023)] = ((0.187069282f * fTemp7) + (fRec542 + (fRec551 + fRec554)));
			output29[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec28[((IOTA - iConst14) & 1023)])));
			float fTemp143 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec565[1]) + (fConst4 * fRec562[1])))) + (fConst7 * ((((0.0193030704f * fTemp8) + (0.078759186f * fTemp12)) + (0.253488362f * fTemp14)) - ((((0.00865725987f * fTemp9) + (0.0012651626f * fTemp11)) + (0.071384877f * fTemp13)) + (0.173975185f * fTemp10))))));
			fRec567[0] = (fRec567[1] + fTemp143);
			fRec565[0] = fRec567[0];
			float fRec566 = fTemp143;
			fRec564[0] = (fRec565[0] + fRec564[1]);
			fRec562[0] = fRec564[0];
			float fRec563 = fRec566;
			float fTemp144 = (fConst8 * fRec559[1]);
			fRec561[0] = ((fRec563 + fRec561[1]) - fTemp144);
			fRec559[0] = fRec561[0];
			float fRec560 = (fRec563 - fTemp144);
			float fTemp145 = (fConst9 * ((((0.00682277465f * fTemp17) + (0.286985546f * fTemp19)) - (0.143427595f * fTemp18)) - (fConst10 * fRec568[1])));
			fRec570[0] = (fRec570[1] + fTemp145);
			fRec568[0] = fRec570[0];
			float fRec569 = fTemp145;
			float fTemp146 = (fConst11 * ((((0.0153381806f * fTemp21) + (0.287879199f * fTemp24)) - (((0.00549846236f * fTemp22) + (0.0614362881f * fTemp25)) + (0.201519281f * fTemp23))) + (fConst3 * (0.0f - ((fConst13 * fRec574[1]) + (fConst12 * fRec571[1]))))));
			fRec576[0] = (fRec576[1] + fTemp146);
			fRec574[0] = fRec576[0];
			float fRec575 = fTemp146;
			fRec573[0] = (fRec574[0] + fRec573[1]);
			fRec571[0] = fRec573[0];
			float fRec572 = fRec575;
			fVec29[(IOTA & 1023)] = ((0.187045008f * fTemp7) + (fRec560 + (fRec569 + fRec572)));
			output30[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec29[((IOTA - iConst14) & 1023)])));
			float fTemp147 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec583[1]) + (fConst4 * fRec580[1])))) + (fConst7 * (((((0.114927664f * fTemp9) + (0.0288584065f * fTemp11)) + (0.0789415091f * fTemp12)) + (0.110815495f * fTemp14)) - (((0.228298798f * fTemp8) + (0.0678292289f * fTemp13)) + (0.128168374f * fTemp10))))));
			fRec585[0] = (fRec585[1] + fTemp147);
			fRec583[0] = fRec585[0];
			float fRec584 = fTemp147;
			fRec582[0] = (fRec583[0] + fRec582[1]);
			fRec580[0] = fRec582[0];
			float fRec581 = fRec584;
			float fTemp148 = (fConst8 * fRec577[1]);
			fRec579[0] = ((fRec581 + fRec579[1]) - fTemp148);
			fRec577[0] = fRec579[0];
			float fRec578 = (fRec581 - fTemp148);
			float fTemp149 = (fConst9 * (((0.268010855f * fTemp19) - ((0.103115477f * fTemp17) + (0.143303543f * fTemp18))) - (fConst10 * fRec586[1])));
			fRec588[0] = (fRec588[1] + fTemp149);
			fRec586[0] = fRec588[0];
			float fRec587 = fTemp149;
			float fTemp150 = (fConst11 * ((((0.0731661841f * fTemp22) + (0.212204933f * fTemp24)) - (((0.194686264f * fTemp21) + (0.0616754815f * fTemp25)) + (0.187654689f * fTemp23))) + (fConst3 * (0.0f - ((fConst13 * fRec592[1]) + (fConst12 * fRec589[1]))))));
			fRec594[0] = (fRec594[1] + fTemp150);
			fRec592[0] = fRec594[0];
			float fRec593 = fTemp150;
			fRec591[0] = (fRec592[0] + fRec591[1]);
			fRec589[0] = fRec591[0];
			float fRec590 = fRec593;
			fVec30[(IOTA & 1023)] = ((0.186989933f * fTemp7) + (fRec578 + (fRec587 + fRec590)));
			output31[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec30[((IOTA - iConst14) & 1023)])));
			float fTemp151 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec601[1]) + (fConst4 * fRec598[1])))) + (fConst7 * ((((0.170547858f * fTemp9) + (0.0521675125f * fTemp11)) + (0.0795823932f * fTemp12)) - ((((0.189554781f * fTemp8) + (0.0542694069f * fTemp13)) + (0.00633903639f * fTemp10)) + (0.170954853f * fTemp14))))));
			fRec603[0] = (fRec603[1] + fTemp151);
			fRec601[0] = fRec603[0];
			float fRec602 = fTemp151;
			fRec600[0] = (fRec601[0] + fRec600[1]);
			fRec598[0] = fRec600[0];
			float fRec599 = fRec602;
			float fTemp152 = (fConst8 * fRec595[1]);
			fRec597[0] = ((fRec599 + fRec597[1]) - fTemp152);
			fRec595[0] = fRec597[0];
			float fRec596 = (fRec599 - fTemp152);
			float fTemp153 = (fConst9 * (((0.206261799f * fTemp19) - ((0.198346913f * fTemp17) + (0.143366992f * fTemp18))) - (fConst10 * fRec604[1])));
			fRec606[0] = (fRec606[1] + fTemp153);
			fRec604[0] = fRec606[0];
			float fRec605 = fTemp153;
			float fTemp154 = (fConst11 * ((((0.14029181f * fTemp22) + (0.0100446092f * fTemp24)) - (((0.288921297f * fTemp21) + (0.0626269504f * fTemp25)) + (0.144105166f * fTemp23))) + (fConst3 * (0.0f - ((fConst13 * fRec610[1]) + (fConst12 * fRec607[1]))))));
			fRec612[0] = (fRec612[1] + fTemp154);
			fRec610[0] = fRec612[0];
			float fRec611 = fTemp154;
			fRec609[0] = (fRec610[0] + fRec609[1]);
			fRec607[0] = fRec609[0];
			float fRec608 = fRec611;
			fVec31[(IOTA & 1023)] = ((0.187469795f * fTemp7) + (fRec596 + (fRec605 + fRec608)));
			output32[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec31[((IOTA - iConst14) & 1023)])));
			float fTemp155 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec619[1]) + (fConst4 * fRec616[1])))) + (fConst7 * ((((((0.0910240114f * fTemp8) + (0.123514086f * fTemp9)) + (0.0665320456f * fTemp11)) + (0.0801662356f * fTemp12)) + (0.121339157f * fTemp10)) - ((0.0302412808f * fTemp13) + (0.238146901f * fTemp14))))));
			fRec621[0] = (fRec621[1] + fTemp155);
			fRec619[0] = fRec621[0];
			float fRec620 = fTemp155;
			fRec618[0] = (fRec619[0] + fRec618[1]);
			fRec616[0] = fRec618[0];
			float fRec617 = fRec620;
			float fTemp156 = (fConst8 * fRec613[1]);
			fRec615[0] = ((fRec617 + fRec615[1]) - fTemp156);
			fRec613[0] = fRec615[0];
			float fRec614 = (fRec617 - fTemp156);
			float fTemp157 = (fConst9 * (((0.11093121f * fTemp19) - ((0.265786201f * fTemp17) + (0.143630743f * fTemp18))) - (fConst10 * fRec622[1])));
			fRec624[0] = (fRec624[1] + fTemp157);
			fRec622[0] = fRec624[0];
			float fRec623 = fTemp157;
			float fTemp158 = (fConst11 * (((0.18625547f * fTemp22) - ((((0.20798251f * fTemp21) + (0.0635434687f * fTemp25)) + (0.0775863305f * fTemp23)) + (0.201459736f * fTemp24))) + (fConst3 * (0.0f - ((fConst13 * fRec628[1]) + (fConst12 * fRec625[1]))))));
			fRec630[0] = (fRec630[1] + fTemp158);
			fRec628[0] = fRec630[0];
			float fRec629 = fTemp158;
			fRec627[0] = (fRec628[0] + fRec627[1]);
			fRec625[0] = fRec627[0];
			float fRec626 = fRec629;
			fVec32[(IOTA & 1023)] = ((0.188191861f * fTemp7) + (fRec614 + (fRec623 + fRec626)));
			output33[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec32[((IOTA - iConst14) & 1023)])));
			float fTemp159 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec637[1]) + (fConst4 * fRec634[1])))) + (fConst7 * (((((((0.255113989f * fTemp8) + (0.00128528243f * fTemp9)) + (0.0717878044f * fTemp11)) + (0.0801370963f * fTemp12)) + (0.0001397343f * fTemp13)) + (0.175451964f * fTemp10)) - (0.00112352741f * fTemp14)))));
			fRec639[0] = (fRec639[1] + fTemp159);
			fRec637[0] = fRec639[0];
			float fRec638 = fTemp159;
			fRec636[0] = (fRec637[0] + fRec636[1]);
			fRec634[0] = fRec636[0];
			float fRec635 = fRec638;
			float fTemp160 = (fConst8 * fRec631[1]);
			fRec633[0] = ((fRec635 + fRec633[1]) - fTemp160);
			fRec631[0] = fRec633[0];
			float fRec632 = (fRec635 - fTemp160);
			float fTemp161 = (fConst9 * (((0.000228432298f * fTemp19) - ((0.290622473f * fTemp17) + (0.143689498f * fTemp18))) - (fConst10 * fRec640[1])));
			fRec642[0] = (fRec642[1] + fTemp161);
			fRec640[0] = fRec642[0];
			float fRec641 = fTemp161;
			float fTemp162 = (fConst11 * (((0.202322111f * fTemp22) - ((((0.0001860661f * fTemp21) + (0.063623406f * fTemp25)) + (0.000484482996f * fTemp23)) + (0.290245444f * fTemp24))) + (fConst3 * (0.0f - ((fConst13 * fRec646[1]) + (fConst12 * fRec643[1]))))));
			fRec648[0] = (fRec648[1] + fTemp162);
			fRec646[0] = fRec648[0];
			float fRec647 = fTemp162;
			fRec645[0] = (fRec646[0] + fRec645[1]);
			fRec643[0] = fRec645[0];
			float fRec644 = fRec647;
			fVec33[(IOTA & 1023)] = ((0.188362479f * fTemp7) + (fRec632 + (fRec641 + fRec644)));
			output34[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec33[((IOTA - iConst14) & 1023)])));
			float fTemp163 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec655[1]) + (fConst4 * fRec652[1])))) + (fConst7 * (((((((0.0909219459f * fTemp8) + (0.067693986f * fTemp11)) + (0.0794848874f * fTemp12)) + (0.0306297708f * fTemp13)) + (0.122514047f * fTemp10)) + (0.240691751f * fTemp14)) - (0.123783216f * fTemp9)))));
			fRec657[0] = (fRec657[1] + fTemp163);
			fRec655[0] = fRec657[0];
			float fRec656 = fTemp163;
			fRec654[0] = (fRec655[0] + fRec654[1]);
			fRec652[0] = fRec654[0];
			float fRec653 = fRec656;
			float fTemp164 = (fConst8 * fRec649[1]);
			fRec651[0] = ((fRec653 + fRec651[1]) - fTemp164);
			fRec649[0] = fRec651[0];
			float fRec650 = (fRec653 - fTemp164);
			float fTemp165 = (fConst9 * ((0.0f - ((0.266413778f * fTemp17) + ((0.143378869f * fTemp18) + (0.11142993f * fTemp19)))) - (fConst10 * fRec658[1])));
			fRec660[0] = (fRec660[1] + fTemp165);
			fRec658[0] = fRec660[0];
			float fRec659 = fTemp165;
			float fTemp166 = (fConst11 * (((((0.210151643f * fTemp21) + (0.185609668f * fTemp22)) + (0.0776571333f * fTemp23)) - ((0.0628017709f * fTemp25) + (0.201723233f * fTemp24))) + (fConst3 * (0.0f - ((fConst13 * fRec664[1]) + (fConst12 * fRec661[1]))))));
			fRec666[0] = (fRec666[1] + fTemp166);
			fRec664[0] = fRec666[0];
			float fRec665 = fTemp166;
			fRec663[0] = (fRec664[0] + fRec663[1]);
			fRec661[0] = fRec663[0];
			float fRec662 = fRec665;
			fVec34[(IOTA & 1023)] = ((0.1877148f * fTemp7) + (fRec650 + (fRec659 + fRec662)));
			output35[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec34[((IOTA - iConst14) & 1023)])));
			float fTemp167 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec673[1]) + (fConst4 * fRec670[1])))) + (fConst7 * (((((0.0526175201f * fTemp11) + (0.0787265077f * fTemp12)) + (0.0538136587f * fTemp13)) + (0.169774562f * fTemp14)) - (((0.189450547f * fTemp8) + (0.170634866f * fTemp9)) + (0.00585230859f * fTemp10))))));
			fRec675[0] = (fRec675[1] + fTemp167);
			fRec673[0] = fRec675[0];
			float fRec674 = fTemp167;
			fRec672[0] = (fRec673[0] + fRec672[1]);
			fRec670[0] = fRec672[0];
			float fRec671 = fRec674;
			float fTemp168 = (fConst8 * fRec667[1]);
			fRec669[0] = ((fRec671 + fRec669[1]) - fTemp168);
			fRec667[0] = fRec669[0];
			float fRec668 = (fRec671 - fTemp168);
			float fTemp169 = (fConst9 * ((0.0f - ((0.19724302f * fTemp17) + ((0.143014684f * fTemp18) + (0.204982489f * fTemp19)))) - (fConst10 * fRec676[1])));
			fRec678[0] = (fRec678[1] + fTemp169);
			fRec676[0] = fRec678[0];
			float fRec677 = fTemp169;
			float fTemp170 = (fConst11 * ((((((0.286907822f * fTemp21) + (0.138538003f * fTemp22)) + (0.143573239f * fTemp23)) + (0.0103783496f * fTemp24)) - (0.0617375672f * fTemp25)) + (fConst3 * (0.0f - ((fConst13 * fRec682[1]) + (fConst12 * fRec679[1]))))));
			fRec684[0] = (fRec684[1] + fTemp170);
			fRec682[0] = fRec684[0];
			float fRec683 = fTemp170;
			fRec681[0] = (fRec682[0] + fRec681[1]);
			fRec679[0] = fRec681[0];
			float fRec680 = fRec683;
			fVec35[(IOTA & 1023)] = ((0.186820269f * fTemp7) + (fRec668 + (fRec677 + fRec680)));
			output36[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec35[((IOTA - iConst14) & 1023)])));
			float fTemp171 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec691[1]) + (fConst4 * fRec688[1])))) + (fConst7 * ((((0.0282102562f * fTemp11) + (0.0783253983f * fTemp12)) + (0.0666486025f * fTemp13)) - ((((0.226201519f * fTemp8) + (0.115223274f * fTemp9)) + (0.126017109f * fTemp10)) + (0.107387535f * fTemp14))))));
			fRec693[0] = (fRec693[1] + fTemp171);
			fRec691[0] = fRec693[0];
			float fRec692 = fTemp171;
			fRec690[0] = (fRec691[0] + fRec690[1]);
			fRec688[0] = fRec690[0];
			float fRec689 = fRec692;
			float fTemp172 = (fConst8 * fRec685[1]);
			fRec687[0] = ((fRec689 + fRec687[1]) - fTemp172);
			fRec685[0] = fRec687[0];
			float fRec686 = (fRec689 - fTemp172);
			float fTemp173 = (fConst9 * ((0.0f - ((0.102293178f * fTemp17) + ((0.142862439f * fTemp18) + (0.264594197f * fTemp19)))) - (fConst10 * fRec694[1])));
			fRec696[0] = (fRec696[1] + fTemp173);
			fRec694[0] = fRec696[0];
			float fRec695 = fTemp173;
			float fTemp174 = (fConst11 * ((((((0.192499489f * fTemp21) + (0.0726164952f * fTemp22)) + (0.185703352f * fTemp23)) + (0.207765564f * fTemp24)) - (0.061097838f * fTemp25)) + (fConst3 * (0.0f - ((fConst13 * fRec700[1]) + (fConst12 * fRec697[1]))))));
			fRec702[0] = (fRec702[1] + fTemp174);
			fRec700[0] = fRec702[0];
			float fRec701 = fTemp174;
			fRec699[0] = (fRec700[0] + fRec699[1]);
			fRec697[0] = fRec699[0];
			float fRec698 = fRec701;
			fVec36[(IOTA & 1023)] = ((0.186301932f * fTemp7) + (fRec686 + (fRec695 + fRec698)));
			output37[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec36[((IOTA - iConst14) & 1023)])));
			float fTemp175 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec709[1]) + (fConst4 * fRec706[1])))) + (fConst7 * ((((0.000399995188f * fTemp9) + (0.0782553926f * fTemp12)) + (0.0706105754f * fTemp13)) - ((((0.000335831108f * fTemp8) + (0.000390380388f * fTemp11)) + (0.174084261f * fTemp10)) + (0.253661513f * fTemp14))))));
			fRec711[0] = (fRec711[1] + fTemp175);
			fRec709[0] = fRec711[0];
			float fRec710 = fTemp175;
			fRec708[0] = (fRec709[0] + fRec708[1]);
			fRec706[0] = fRec708[0];
			float fRec707 = fRec710;
			float fTemp176 = (fConst8 * fRec703[1]);
			fRec705[0] = ((fRec707 + fRec705[1]) - fTemp176);
			fRec703[0] = fRec705[0];
			float fRec704 = (fRec707 - fTemp176);
			float fTemp177 = (fConst9 * (((6.07567999e-05f * fTemp17) - ((0.1426723f * fTemp18) + (0.285045564f * fTemp19))) - (fConst10 * fRec712[1])));
			fRec714[0] = (fRec714[1] + fTemp177);
			fRec712[0] = fRec714[0];
			float fRec713 = fTemp177;
			float fTemp178 = (fConst11 * (((((5.61720008e-05f * fTemp22) + (0.200068608f * fTemp23)) + (0.286202282f * fTemp24)) - ((0.000921689323f * fTemp21) + (0.0609477647f * fTemp25))) + (fConst3 * (0.0f - ((fConst13 * fRec718[1]) + (fConst12 * fRec715[1]))))));
			fRec720[0] = (fRec720[1] + fTemp178);
			fRec718[0] = fRec720[0];
			float fRec719 = fTemp178;
			fRec717[0] = (fRec718[0] + fRec717[1]);
			fRec715[0] = fRec717[0];
			float fRec716 = fRec719;
			fVec37[(IOTA & 1023)] = ((0.186023787f * fTemp7) + (fRec704 + (fRec713 + fRec716)));
			output38[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec37[((IOTA - iConst14) & 1023)])));
			float fTemp179 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec727[1]) + (fConst4 * fRec724[1])))) + (fConst7 * (((((0.241573662f * fTemp8) + (0.125984311f * fTemp9)) + (0.0782987699f * fTemp12)) + (0.065694347f * fTemp13)) - (((0.0310833603f * fTemp11) + (0.11934302f * fTemp10)) + (0.0855972245f * fTemp14))))));
			fRec729[0] = (fRec729[1] + fTemp179);
			fRec727[0] = fRec729[0];
			float fRec728 = fTemp179;
			fRec726[0] = (fRec727[0] + fRec726[1]);
			fRec724[0] = fRec726[0];
			float fRec725 = fRec728;
			float fTemp180 = (fConst8 * fRec721[1]);
			fRec723[0] = ((fRec725 + fRec723[1]) - fTemp180);
			fRec721[0] = fRec723[0];
			float fRec722 = (fRec725 - fTemp180);
			float fTemp181 = (fConst9 * (((0.111959741f * fTemp17) - ((0.141891271f * fTemp18) + (0.260526091f * fTemp19))) - (fConst10 * fRec730[1])));
			fRec732[0] = (fRec732[1] + fTemp181);
			fRec730[0] = fRec732[0];
			float fRec731 = fTemp181;
			float fTemp182 = (fConst11 * ((((0.182688653f * fTemp23) + (0.196180597f * fTemp24)) - (((0.209836736f * fTemp21) + (0.0797216669f * fTemp22)) + (0.0610940568f * fTemp25))) + (fConst3 * (0.0f - ((fConst13 * fRec736[1]) + (fConst12 * fRec733[1]))))));
			fRec738[0] = (fRec738[1] + fTemp182);
			fRec736[0] = fRec738[0];
			float fRec737 = fTemp182;
			fRec735[0] = (fRec736[0] + fRec735[1]);
			fRec733[0] = fRec735[0];
			float fRec734 = fRec737;
			fVec38[(IOTA & 1023)] = ((0.185388774f * fTemp7) + (fRec722 + (fRec731 + fRec734)));
			output39[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec38[((IOTA - iConst14) & 1023)])));
			float fTemp183 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec745[1]) + (fConst4 * fRec742[1])))) + (fConst7 * (((((((0.1759689f * fTemp8) + (0.168888181f * fTemp9)) + (0.0783503428f * fTemp12)) + (0.0518754721f * fTemp13)) + (0.00104552985f * fTemp10)) + (0.178658351f * fTemp14)) - (0.0522370078f * fTemp11)))));
			fRec747[0] = (fRec747[1] + fTemp183);
			fRec745[0] = fRec747[0];
			float fRec746 = fTemp183;
			fRec744[0] = (fRec745[0] + fRec744[1]);
			fRec742[0] = fRec744[0];
			float fRec743 = fRec746;
			float fTemp184 = (fConst8 * fRec739[1]);
			fRec741[0] = ((fRec743 + fRec741[1]) - fTemp184);
			fRec739[0] = fRec741[0];
			float fRec740 = (fRec743 - fTemp184);
			float fTemp185 = (fConst9 * (((0.19837223f * fTemp17) - ((0.140644163f * fTemp18) + (0.197949842f * fTemp19))) - (fConst10 * fRec748[1])));
			fRec750[0] = (fRec750[1] + fTemp185);
			fRec748[0] = fRec750[0];
			float fRec749 = fTemp185;
			float fTemp186 = (fConst11 * (((0.138802856f * fTemp23) - ((((0.281514794f * fTemp21) + (0.140253827f * fTemp22)) + (0.0613777339f * fTemp25)) + (0.00121014565f * fTemp24))) + (fConst3 * (0.0f - ((fConst13 * fRec754[1]) + (fConst12 * fRec751[1]))))));
			fRec756[0] = (fRec756[1] + fTemp186);
			fRec754[0] = fRec756[0];
			float fRec755 = fTemp186;
			fRec753[0] = (fRec754[0] + fRec753[1]);
			fRec751[0] = fRec753[0];
			float fRec752 = fRec755;
			fVec39[(IOTA & 1023)] = ((0.184384644f * fTemp7) + (fRec740 + (fRec749 + fRec752)));
			output40[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec39[((IOTA - iConst14) & 1023)])));
			float fTemp187 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec763[1]) + (fConst4 * fRec760[1])))) + (fConst7 * ((((((0.118978679f * fTemp9) + (0.0785232112f * fTemp12)) + (0.0293763466f * fTemp13)) + (0.120251097f * fTemp10)) + (0.231209546f * fTemp14)) - ((0.0923781693f * fTemp8) + (0.0651272461f * fTemp11))))));
			fRec765[0] = (fRec765[1] + fTemp187);
			fRec763[0] = fRec765[0];
			float fRec764 = fTemp187;
			fRec762[0] = (fRec763[0] + fRec762[1]);
			fRec760[0] = fRec762[0];
			float fRec761 = fRec764;
			float fTemp188 = (fConst8 * fRec757[1]);
			fRec759[0] = ((fRec761 + fRec759[1]) - fTemp188);
			fRec757[0] = fRec759[0];
			float fRec758 = (fRec761 - fTemp188);
			float fTemp189 = (fConst9 * (((0.258361578f * fTemp17) - ((0.139575496f * fTemp18) + (0.107951567f * fTemp19))) - (fConst10 * fRec766[1])));
			fRec768[0] = (fRec768[1] + fTemp189);
			fRec766[0] = fRec768[0];
			float fRec767 = fTemp189;
			float fTemp190 = (fConst11 * (((0.075938262f * fTemp23) - ((((0.199384257f * fTemp21) + (0.180946231f * fTemp22)) + (0.0618313141f * fTemp25)) + (0.197065711f * fTemp24))) + (fConst3 * (0.0f - ((fConst13 * fRec772[1]) + (fConst12 * fRec769[1]))))));
			fRec774[0] = (fRec774[1] + fTemp190);
			fRec772[0] = fRec774[0];
			float fRec773 = fTemp190;
			fRec771[0] = (fRec772[0] + fRec771[1]);
			fRec769[0] = fRec771[0];
			float fRec770 = fRec773;
			fVec40[(IOTA & 1023)] = ((0.183589727f * fTemp7) + (fRec758 + (fRec767 + fRec770)));
			output41[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec40[((IOTA - iConst14) & 1023)])));
			float fTemp191 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec781[1]) + (fConst4 * fRec778[1])))) + (fConst7 * ((((((0.00966438372f * fTemp9) + (0.0788678303f * fTemp12)) + (0.00237652217f * fTemp13)) + (0.172884077f * fTemp10)) + (0.024082588f * fTemp14)) - ((0.252206326f * fTemp8) + (0.0703033954f * fTemp11))))));
			fRec783[0] = (fRec783[1] + fTemp191);
			fRec781[0] = fRec783[0];
			float fRec782 = fTemp191;
			fRec780[0] = (fRec781[0] + fRec780[1]);
			fRec778[0] = fRec780[0];
			float fRec779 = fRec782;
			float fTemp192 = (fConst8 * fRec775[1]);
			fRec777[0] = ((fRec779 + fRec777[1]) - fTemp192);
			fRec775[0] = fRec777[0];
			float fRec776 = (fRec779 - fTemp192);
			float fTemp193 = (fConst9 * (((0.282610863f * fTemp17) - ((0.139458641f * fTemp18) + (0.00839023944f * fTemp19))) - (fConst10 * fRec784[1])));
			fRec786[0] = (fRec786[1] + fTemp193);
			fRec784[0] = fRec786[0];
			float fRec785 = fTemp193;
			float fTemp194 = (fConst11 * (((0.00631497847f * fTemp23) - ((((0.0176514443f * fTemp21) + (0.196794584f * fTemp22)) + (0.0623787157f * fTemp25)) + (0.284319341f * fTemp24))) + (fConst3 * (0.0f - ((fConst13 * fRec790[1]) + (fConst12 * fRec787[1]))))));
			fRec792[0] = (fRec792[1] + fTemp194);
			fRec790[0] = fRec792[0];
			float fRec791 = fTemp194;
			fRec789[0] = (fRec790[0] + fRec789[1]);
			fRec787[0] = fRec789[0];
			float fRec788 = fRec791;
			fVec41[(IOTA & 1023)] = ((0.183708191f * fTemp7) + (fRec776 + (fRec785 + fRec788)));
			output42[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec41[((IOTA - iConst14) & 1023)])));
			float fTemp195 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec799[1]) + (fConst4 * fRec796[1])))) + (fConst7 * (((0.0792677253f * fTemp12) + (0.126897782f * fTemp10)) - (((((0.109227903f * fTemp8) + (0.116749443f * fTemp9)) + (0.0674500614f * fTemp11)) + (0.0283376053f * fTemp13)) + (0.229696959f * fTemp14))))));
			fRec801[0] = (fRec801[1] + fTemp195);
			fRec799[0] = fRec801[0];
			float fRec800 = fTemp195;
			fRec798[0] = (fRec799[0] + fRec798[1]);
			fRec796[0] = fRec798[0];
			float fRec797 = fRec800;
			float fTemp196 = (fConst8 * fRec793[1]);
			fRec795[0] = ((fRec797 + fRec795[1]) - fTemp196);
			fRec793[0] = fRec795[0];
			float fRec794 = (fRec797 - fTemp196);
			float fTemp197 = (fConst9 * ((((0.26458773f * fTemp17) + (0.104334638f * fTemp19)) - (0.140584067f * fTemp18)) - (fConst10 * fRec802[1])));
			fRec804[0] = (fRec804[1] + fTemp197);
			fRec802[0] = fRec804[0];
			float fRec803 = fTemp197;
			float fTemp198 = (fConst11 * (((0.194695532f * fTemp21) - ((((0.184562027f * fTemp22) + (0.06278947f * fTemp25)) + (0.0729265064f * fTemp23)) + (0.209713399f * fTemp24))) + (fConst3 * (0.0f - ((fConst13 * fRec808[1]) + (fConst12 * fRec805[1]))))));
			fRec810[0] = (fRec810[1] + fTemp198);
			fRec808[0] = fRec810[0];
			float fRec809 = fTemp198;
			fRec807[0] = (fRec808[0] + fRec807[1]);
			fRec805[0] = fRec807[0];
			float fRec806 = fRec809;
			fVec42[(IOTA & 1023)] = ((0.1849484f * fTemp7) + (fRec794 + (fRec803 + fRec806)));
			output43[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec42[((IOTA - iConst14) & 1023)])));
			float fTemp199 = (fConst2 * ((fConst3 * (0.0f - ((fConst5 * fRec817[1]) + (fConst4 * fRec814[1])))) + (fConst7 * ((((0.160544321f * fTemp8) + (0.0793352053f * fTemp12)) + (0.0113679375f * fTemp10)) - ((((0.169016361f * fTemp9) + (0.0551356338f * fTemp11)) + (0.0508549139f * fTemp13)) + (0.19562234f * fTemp14))))));
			fRec819[0] = (fRec819[1] + fTemp199);
			fRec817[0] = fRec819[0];
			float fRec818 = fTemp199;
			fRec816[0] = (fRec817[0] + fRec816[1]);
			fRec814[0] = fRec816[0];
			float fRec815 = fRec818;
			float fTemp200 = (fConst8 * fRec811[1]);
			fRec813[0] = ((fRec815 + fRec813[1]) - fTemp200);
			fRec811[0] = fRec813[0];
			float fRec812 = (fRec815 - fTemp200);
			float fTemp201 = (fConst9 * ((((0.207553372f * fTemp17) + (0.193706363f * fTemp19)) - (0.142086446f * fTemp18)) - (fConst10 * fRec820[1])));
			fRec822[0] = (fRec822[1] + fTemp201);
			fRec820[0] = fRec822[0];
			float fRec821 = fTemp201;
			float fTemp202 = (fConst11 * (((0.284390092f * fTemp21) - ((((0.14612706f * fTemp22) + (0.0626240596f * fTemp25)) + (0.136070594f * fTemp23)) + (0.0196162909f * fTemp24))) + (fConst3 * (0.0f - ((fConst13 * fRec826[1]) + (fConst12 * fRec823[1]))))));
			fRec828[0] = (fRec828[1] + fTemp202);
			fRec826[0] = fRec828[0];
			float fRec827 = fTemp202;
			fRec825[0] = (fRec826[0] + fRec825[1]);
			fRec823[0] = fRec825[0];
			float fRec824 = fRec827;
			fVec43[(IOTA & 1023)] = ((0.186314508f * fTemp7) + (fRec812 + (fRec821 + fRec824)));
			output44[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec43[((IOTA - iConst14) & 1023)])));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec12[1] = fRec12[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec23[2] = fRec23[1];
			fRec23[1] = fRec23[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec22[1] = fRec22[0];
			fRec20[1] = fRec20[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec31[1] = fRec31[0];
			fRec29[1] = fRec29[0];
			fRec28[1] = fRec28[0];
			fRec26[1] = fRec26[0];
			IOTA = (IOTA + 1);
			fRec45[1] = fRec45[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec37[1] = fRec37[0];
			fRec48[1] = fRec48[0];
			fRec46[1] = fRec46[0];
			fRec54[1] = fRec54[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec49[1] = fRec49[0];
			fRec63[1] = fRec63[0];
			fRec61[1] = fRec61[0];
			fRec60[1] = fRec60[0];
			fRec58[1] = fRec58[0];
			fRec57[1] = fRec57[0];
			fRec55[1] = fRec55[0];
			fRec66[1] = fRec66[0];
			fRec64[1] = fRec64[0];
			fRec72[1] = fRec72[0];
			fRec70[1] = fRec70[0];
			fRec69[1] = fRec69[0];
			fRec67[1] = fRec67[0];
			fRec81[1] = fRec81[0];
			fRec79[1] = fRec79[0];
			fRec78[1] = fRec78[0];
			fRec76[1] = fRec76[0];
			fRec75[1] = fRec75[0];
			fRec73[1] = fRec73[0];
			fRec84[1] = fRec84[0];
			fRec82[1] = fRec82[0];
			fRec90[1] = fRec90[0];
			fRec88[1] = fRec88[0];
			fRec87[1] = fRec87[0];
			fRec85[1] = fRec85[0];
			fRec99[1] = fRec99[0];
			fRec97[1] = fRec97[0];
			fRec96[1] = fRec96[0];
			fRec94[1] = fRec94[0];
			fRec93[1] = fRec93[0];
			fRec91[1] = fRec91[0];
			fRec102[1] = fRec102[0];
			fRec100[1] = fRec100[0];
			fRec108[1] = fRec108[0];
			fRec106[1] = fRec106[0];
			fRec105[1] = fRec105[0];
			fRec103[1] = fRec103[0];
			fRec117[1] = fRec117[0];
			fRec115[1] = fRec115[0];
			fRec114[1] = fRec114[0];
			fRec112[1] = fRec112[0];
			fRec111[1] = fRec111[0];
			fRec109[1] = fRec109[0];
			fRec120[1] = fRec120[0];
			fRec118[1] = fRec118[0];
			fRec126[1] = fRec126[0];
			fRec124[1] = fRec124[0];
			fRec123[1] = fRec123[0];
			fRec121[1] = fRec121[0];
			fRec135[1] = fRec135[0];
			fRec133[1] = fRec133[0];
			fRec132[1] = fRec132[0];
			fRec130[1] = fRec130[0];
			fRec129[1] = fRec129[0];
			fRec127[1] = fRec127[0];
			fRec138[1] = fRec138[0];
			fRec136[1] = fRec136[0];
			fRec144[1] = fRec144[0];
			fRec142[1] = fRec142[0];
			fRec141[1] = fRec141[0];
			fRec139[1] = fRec139[0];
			fRec153[1] = fRec153[0];
			fRec151[1] = fRec151[0];
			fRec150[1] = fRec150[0];
			fRec148[1] = fRec148[0];
			fRec147[1] = fRec147[0];
			fRec145[1] = fRec145[0];
			fRec156[1] = fRec156[0];
			fRec154[1] = fRec154[0];
			fRec162[1] = fRec162[0];
			fRec160[1] = fRec160[0];
			fRec159[1] = fRec159[0];
			fRec157[1] = fRec157[0];
			fRec171[1] = fRec171[0];
			fRec169[1] = fRec169[0];
			fRec168[1] = fRec168[0];
			fRec166[1] = fRec166[0];
			fRec165[1] = fRec165[0];
			fRec163[1] = fRec163[0];
			fRec174[1] = fRec174[0];
			fRec172[1] = fRec172[0];
			fRec180[1] = fRec180[0];
			fRec178[1] = fRec178[0];
			fRec177[1] = fRec177[0];
			fRec175[1] = fRec175[0];
			fRec189[1] = fRec189[0];
			fRec187[1] = fRec187[0];
			fRec186[1] = fRec186[0];
			fRec184[1] = fRec184[0];
			fRec183[1] = fRec183[0];
			fRec181[1] = fRec181[0];
			fRec192[1] = fRec192[0];
			fRec190[1] = fRec190[0];
			fRec198[1] = fRec198[0];
			fRec196[1] = fRec196[0];
			fRec195[1] = fRec195[0];
			fRec193[1] = fRec193[0];
			fRec207[1] = fRec207[0];
			fRec205[1] = fRec205[0];
			fRec204[1] = fRec204[0];
			fRec202[1] = fRec202[0];
			fRec201[1] = fRec201[0];
			fRec199[1] = fRec199[0];
			fRec210[1] = fRec210[0];
			fRec208[1] = fRec208[0];
			fRec216[1] = fRec216[0];
			fRec214[1] = fRec214[0];
			fRec213[1] = fRec213[0];
			fRec211[1] = fRec211[0];
			fRec225[1] = fRec225[0];
			fRec223[1] = fRec223[0];
			fRec222[1] = fRec222[0];
			fRec220[1] = fRec220[0];
			fRec219[1] = fRec219[0];
			fRec217[1] = fRec217[0];
			fRec228[1] = fRec228[0];
			fRec226[1] = fRec226[0];
			fRec234[1] = fRec234[0];
			fRec232[1] = fRec232[0];
			fRec231[1] = fRec231[0];
			fRec229[1] = fRec229[0];
			fRec243[1] = fRec243[0];
			fRec241[1] = fRec241[0];
			fRec240[1] = fRec240[0];
			fRec238[1] = fRec238[0];
			fRec237[1] = fRec237[0];
			fRec235[1] = fRec235[0];
			fRec246[1] = fRec246[0];
			fRec244[1] = fRec244[0];
			fRec252[1] = fRec252[0];
			fRec250[1] = fRec250[0];
			fRec249[1] = fRec249[0];
			fRec247[1] = fRec247[0];
			fRec261[1] = fRec261[0];
			fRec259[1] = fRec259[0];
			fRec258[1] = fRec258[0];
			fRec256[1] = fRec256[0];
			fRec255[1] = fRec255[0];
			fRec253[1] = fRec253[0];
			fRec264[1] = fRec264[0];
			fRec262[1] = fRec262[0];
			fRec270[1] = fRec270[0];
			fRec268[1] = fRec268[0];
			fRec267[1] = fRec267[0];
			fRec265[1] = fRec265[0];
			fRec279[1] = fRec279[0];
			fRec277[1] = fRec277[0];
			fRec276[1] = fRec276[0];
			fRec274[1] = fRec274[0];
			fRec273[1] = fRec273[0];
			fRec271[1] = fRec271[0];
			fRec282[1] = fRec282[0];
			fRec280[1] = fRec280[0];
			fRec288[1] = fRec288[0];
			fRec286[1] = fRec286[0];
			fRec285[1] = fRec285[0];
			fRec283[1] = fRec283[0];
			fRec297[1] = fRec297[0];
			fRec295[1] = fRec295[0];
			fRec294[1] = fRec294[0];
			fRec292[1] = fRec292[0];
			fRec291[1] = fRec291[0];
			fRec289[1] = fRec289[0];
			fRec300[1] = fRec300[0];
			fRec298[1] = fRec298[0];
			fRec306[1] = fRec306[0];
			fRec304[1] = fRec304[0];
			fRec303[1] = fRec303[0];
			fRec301[1] = fRec301[0];
			fRec315[1] = fRec315[0];
			fRec313[1] = fRec313[0];
			fRec312[1] = fRec312[0];
			fRec310[1] = fRec310[0];
			fRec309[1] = fRec309[0];
			fRec307[1] = fRec307[0];
			fRec318[1] = fRec318[0];
			fRec316[1] = fRec316[0];
			fRec324[1] = fRec324[0];
			fRec322[1] = fRec322[0];
			fRec321[1] = fRec321[0];
			fRec319[1] = fRec319[0];
			fRec333[1] = fRec333[0];
			fRec331[1] = fRec331[0];
			fRec330[1] = fRec330[0];
			fRec328[1] = fRec328[0];
			fRec327[1] = fRec327[0];
			fRec325[1] = fRec325[0];
			fRec336[1] = fRec336[0];
			fRec334[1] = fRec334[0];
			fRec342[1] = fRec342[0];
			fRec340[1] = fRec340[0];
			fRec339[1] = fRec339[0];
			fRec337[1] = fRec337[0];
			fRec351[1] = fRec351[0];
			fRec349[1] = fRec349[0];
			fRec348[1] = fRec348[0];
			fRec346[1] = fRec346[0];
			fRec345[1] = fRec345[0];
			fRec343[1] = fRec343[0];
			fRec354[1] = fRec354[0];
			fRec352[1] = fRec352[0];
			fRec360[1] = fRec360[0];
			fRec358[1] = fRec358[0];
			fRec357[1] = fRec357[0];
			fRec355[1] = fRec355[0];
			fRec369[1] = fRec369[0];
			fRec367[1] = fRec367[0];
			fRec366[1] = fRec366[0];
			fRec364[1] = fRec364[0];
			fRec363[1] = fRec363[0];
			fRec361[1] = fRec361[0];
			fRec372[1] = fRec372[0];
			fRec370[1] = fRec370[0];
			fRec378[1] = fRec378[0];
			fRec376[1] = fRec376[0];
			fRec375[1] = fRec375[0];
			fRec373[1] = fRec373[0];
			fRec387[1] = fRec387[0];
			fRec385[1] = fRec385[0];
			fRec384[1] = fRec384[0];
			fRec382[1] = fRec382[0];
			fRec381[1] = fRec381[0];
			fRec379[1] = fRec379[0];
			fRec390[1] = fRec390[0];
			fRec388[1] = fRec388[0];
			fRec396[1] = fRec396[0];
			fRec394[1] = fRec394[0];
			fRec393[1] = fRec393[0];
			fRec391[1] = fRec391[0];
			fRec402[1] = fRec402[0];
			fRec400[1] = fRec400[0];
			fRec399[1] = fRec399[0];
			fRec397[1] = fRec397[0];
			fRec405[1] = fRec405[0];
			fRec403[1] = fRec403[0];
			fRec414[1] = fRec414[0];
			fRec412[1] = fRec412[0];
			fRec411[1] = fRec411[0];
			fRec409[1] = fRec409[0];
			fRec408[1] = fRec408[0];
			fRec406[1] = fRec406[0];
			fRec423[1] = fRec423[0];
			fRec421[1] = fRec421[0];
			fRec420[1] = fRec420[0];
			fRec418[1] = fRec418[0];
			fRec417[1] = fRec417[0];
			fRec415[1] = fRec415[0];
			fRec426[1] = fRec426[0];
			fRec424[1] = fRec424[0];
			fRec432[1] = fRec432[0];
			fRec430[1] = fRec430[0];
			fRec429[1] = fRec429[0];
			fRec427[1] = fRec427[0];
			fRec435[1] = fRec435[0];
			fRec433[1] = fRec433[0];
			fRec441[1] = fRec441[0];
			fRec439[1] = fRec439[0];
			fRec438[1] = fRec438[0];
			fRec436[1] = fRec436[0];
			fRec450[1] = fRec450[0];
			fRec448[1] = fRec448[0];
			fRec447[1] = fRec447[0];
			fRec445[1] = fRec445[0];
			fRec444[1] = fRec444[0];
			fRec442[1] = fRec442[0];
			fRec459[1] = fRec459[0];
			fRec457[1] = fRec457[0];
			fRec456[1] = fRec456[0];
			fRec454[1] = fRec454[0];
			fRec453[1] = fRec453[0];
			fRec451[1] = fRec451[0];
			fRec462[1] = fRec462[0];
			fRec460[1] = fRec460[0];
			fRec468[1] = fRec468[0];
			fRec466[1] = fRec466[0];
			fRec465[1] = fRec465[0];
			fRec463[1] = fRec463[0];
			fRec477[1] = fRec477[0];
			fRec475[1] = fRec475[0];
			fRec474[1] = fRec474[0];
			fRec472[1] = fRec472[0];
			fRec471[1] = fRec471[0];
			fRec469[1] = fRec469[0];
			fRec480[1] = fRec480[0];
			fRec478[1] = fRec478[0];
			fRec486[1] = fRec486[0];
			fRec484[1] = fRec484[0];
			fRec483[1] = fRec483[0];
			fRec481[1] = fRec481[0];
			fRec495[1] = fRec495[0];
			fRec493[1] = fRec493[0];
			fRec492[1] = fRec492[0];
			fRec490[1] = fRec490[0];
			fRec489[1] = fRec489[0];
			fRec487[1] = fRec487[0];
			fRec498[1] = fRec498[0];
			fRec496[1] = fRec496[0];
			fRec504[1] = fRec504[0];
			fRec502[1] = fRec502[0];
			fRec501[1] = fRec501[0];
			fRec499[1] = fRec499[0];
			fRec513[1] = fRec513[0];
			fRec511[1] = fRec511[0];
			fRec510[1] = fRec510[0];
			fRec508[1] = fRec508[0];
			fRec507[1] = fRec507[0];
			fRec505[1] = fRec505[0];
			fRec516[1] = fRec516[0];
			fRec514[1] = fRec514[0];
			fRec522[1] = fRec522[0];
			fRec520[1] = fRec520[0];
			fRec519[1] = fRec519[0];
			fRec517[1] = fRec517[0];
			fRec531[1] = fRec531[0];
			fRec529[1] = fRec529[0];
			fRec528[1] = fRec528[0];
			fRec526[1] = fRec526[0];
			fRec525[1] = fRec525[0];
			fRec523[1] = fRec523[0];
			fRec534[1] = fRec534[0];
			fRec532[1] = fRec532[0];
			fRec540[1] = fRec540[0];
			fRec538[1] = fRec538[0];
			fRec537[1] = fRec537[0];
			fRec535[1] = fRec535[0];
			fRec549[1] = fRec549[0];
			fRec547[1] = fRec547[0];
			fRec546[1] = fRec546[0];
			fRec544[1] = fRec544[0];
			fRec543[1] = fRec543[0];
			fRec541[1] = fRec541[0];
			fRec552[1] = fRec552[0];
			fRec550[1] = fRec550[0];
			fRec558[1] = fRec558[0];
			fRec556[1] = fRec556[0];
			fRec555[1] = fRec555[0];
			fRec553[1] = fRec553[0];
			fRec567[1] = fRec567[0];
			fRec565[1] = fRec565[0];
			fRec564[1] = fRec564[0];
			fRec562[1] = fRec562[0];
			fRec561[1] = fRec561[0];
			fRec559[1] = fRec559[0];
			fRec570[1] = fRec570[0];
			fRec568[1] = fRec568[0];
			fRec576[1] = fRec576[0];
			fRec574[1] = fRec574[0];
			fRec573[1] = fRec573[0];
			fRec571[1] = fRec571[0];
			fRec585[1] = fRec585[0];
			fRec583[1] = fRec583[0];
			fRec582[1] = fRec582[0];
			fRec580[1] = fRec580[0];
			fRec579[1] = fRec579[0];
			fRec577[1] = fRec577[0];
			fRec588[1] = fRec588[0];
			fRec586[1] = fRec586[0];
			fRec594[1] = fRec594[0];
			fRec592[1] = fRec592[0];
			fRec591[1] = fRec591[0];
			fRec589[1] = fRec589[0];
			fRec603[1] = fRec603[0];
			fRec601[1] = fRec601[0];
			fRec600[1] = fRec600[0];
			fRec598[1] = fRec598[0];
			fRec597[1] = fRec597[0];
			fRec595[1] = fRec595[0];
			fRec606[1] = fRec606[0];
			fRec604[1] = fRec604[0];
			fRec612[1] = fRec612[0];
			fRec610[1] = fRec610[0];
			fRec609[1] = fRec609[0];
			fRec607[1] = fRec607[0];
			fRec621[1] = fRec621[0];
			fRec619[1] = fRec619[0];
			fRec618[1] = fRec618[0];
			fRec616[1] = fRec616[0];
			fRec615[1] = fRec615[0];
			fRec613[1] = fRec613[0];
			fRec624[1] = fRec624[0];
			fRec622[1] = fRec622[0];
			fRec630[1] = fRec630[0];
			fRec628[1] = fRec628[0];
			fRec627[1] = fRec627[0];
			fRec625[1] = fRec625[0];
			fRec639[1] = fRec639[0];
			fRec637[1] = fRec637[0];
			fRec636[1] = fRec636[0];
			fRec634[1] = fRec634[0];
			fRec633[1] = fRec633[0];
			fRec631[1] = fRec631[0];
			fRec642[1] = fRec642[0];
			fRec640[1] = fRec640[0];
			fRec648[1] = fRec648[0];
			fRec646[1] = fRec646[0];
			fRec645[1] = fRec645[0];
			fRec643[1] = fRec643[0];
			fRec657[1] = fRec657[0];
			fRec655[1] = fRec655[0];
			fRec654[1] = fRec654[0];
			fRec652[1] = fRec652[0];
			fRec651[1] = fRec651[0];
			fRec649[1] = fRec649[0];
			fRec660[1] = fRec660[0];
			fRec658[1] = fRec658[0];
			fRec666[1] = fRec666[0];
			fRec664[1] = fRec664[0];
			fRec663[1] = fRec663[0];
			fRec661[1] = fRec661[0];
			fRec675[1] = fRec675[0];
			fRec673[1] = fRec673[0];
			fRec672[1] = fRec672[0];
			fRec670[1] = fRec670[0];
			fRec669[1] = fRec669[0];
			fRec667[1] = fRec667[0];
			fRec678[1] = fRec678[0];
			fRec676[1] = fRec676[0];
			fRec684[1] = fRec684[0];
			fRec682[1] = fRec682[0];
			fRec681[1] = fRec681[0];
			fRec679[1] = fRec679[0];
			fRec693[1] = fRec693[0];
			fRec691[1] = fRec691[0];
			fRec690[1] = fRec690[0];
			fRec688[1] = fRec688[0];
			fRec687[1] = fRec687[0];
			fRec685[1] = fRec685[0];
			fRec696[1] = fRec696[0];
			fRec694[1] = fRec694[0];
			fRec702[1] = fRec702[0];
			fRec700[1] = fRec700[0];
			fRec699[1] = fRec699[0];
			fRec697[1] = fRec697[0];
			fRec711[1] = fRec711[0];
			fRec709[1] = fRec709[0];
			fRec708[1] = fRec708[0];
			fRec706[1] = fRec706[0];
			fRec705[1] = fRec705[0];
			fRec703[1] = fRec703[0];
			fRec714[1] = fRec714[0];
			fRec712[1] = fRec712[0];
			fRec720[1] = fRec720[0];
			fRec718[1] = fRec718[0];
			fRec717[1] = fRec717[0];
			fRec715[1] = fRec715[0];
			fRec729[1] = fRec729[0];
			fRec727[1] = fRec727[0];
			fRec726[1] = fRec726[0];
			fRec724[1] = fRec724[0];
			fRec723[1] = fRec723[0];
			fRec721[1] = fRec721[0];
			fRec732[1] = fRec732[0];
			fRec730[1] = fRec730[0];
			fRec738[1] = fRec738[0];
			fRec736[1] = fRec736[0];
			fRec735[1] = fRec735[0];
			fRec733[1] = fRec733[0];
			fRec747[1] = fRec747[0];
			fRec745[1] = fRec745[0];
			fRec744[1] = fRec744[0];
			fRec742[1] = fRec742[0];
			fRec741[1] = fRec741[0];
			fRec739[1] = fRec739[0];
			fRec750[1] = fRec750[0];
			fRec748[1] = fRec748[0];
			fRec756[1] = fRec756[0];
			fRec754[1] = fRec754[0];
			fRec753[1] = fRec753[0];
			fRec751[1] = fRec751[0];
			fRec765[1] = fRec765[0];
			fRec763[1] = fRec763[0];
			fRec762[1] = fRec762[0];
			fRec760[1] = fRec760[0];
			fRec759[1] = fRec759[0];
			fRec757[1] = fRec757[0];
			fRec768[1] = fRec768[0];
			fRec766[1] = fRec766[0];
			fRec774[1] = fRec774[0];
			fRec772[1] = fRec772[0];
			fRec771[1] = fRec771[0];
			fRec769[1] = fRec769[0];
			fRec783[1] = fRec783[0];
			fRec781[1] = fRec781[0];
			fRec780[1] = fRec780[0];
			fRec778[1] = fRec778[0];
			fRec777[1] = fRec777[0];
			fRec775[1] = fRec775[0];
			fRec786[1] = fRec786[0];
			fRec784[1] = fRec784[0];
			fRec792[1] = fRec792[0];
			fRec790[1] = fRec790[0];
			fRec789[1] = fRec789[0];
			fRec787[1] = fRec787[0];
			fRec801[1] = fRec801[0];
			fRec799[1] = fRec799[0];
			fRec798[1] = fRec798[0];
			fRec796[1] = fRec796[0];
			fRec795[1] = fRec795[0];
			fRec793[1] = fRec793[0];
			fRec804[1] = fRec804[0];
			fRec802[1] = fRec802[0];
			fRec810[1] = fRec810[0];
			fRec808[1] = fRec808[0];
			fRec807[1] = fRec807[0];
			fRec805[1] = fRec805[0];
			fRec819[1] = fRec819[0];
			fRec817[1] = fRec817[0];
			fRec816[1] = fRec816[0];
			fRec814[1] = fRec814[0];
			fRec813[1] = fRec813[0];
			fRec811[1] = fRec811[0];
			fRec822[1] = fRec822[0];
			fRec820[1] = fRec820[0];
			fRec828[1] = fRec828[0];
			fRec826[1] = fRec826[0];
			fRec825[1] = fRec825[0];
			fRec823[1] = fRec823[0];
			
		}
		
	}

};

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

/************************** BEGIN poly-dsp.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __poly_dsp__
#define __poly_dsp__

#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <ostream>
#include <sstream>
#include <vector>
#include <limits.h>
#include <float.h>
#include <assert.h>

/************************** BEGIN dsp-combiner.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2019 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.

 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp_combiner__
#define __dsp_combiner__

#include <string.h>
#include <string>
#include <assert.h>
#include <sstream>


// Base class and common code for binary combiners

class dsp_binary_combiner : public dsp {

    protected:

        dsp* fDSP1;
        dsp* fDSP2;

        void buildUserInterfaceAux(UI* ui_interface, const char* name)
        {
            ui_interface->openTabBox(name);
            ui_interface->openVerticalBox("DSP1");
            fDSP1->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->openVerticalBox("DSP2");
            fDSP2->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->closeBox();
        }

        FAUSTFLOAT** allocateChannels(int num, int buffer_size)
        {
            FAUSTFLOAT** channels = new FAUSTFLOAT*[num];
            for (int chan = 0; chan < num; chan++) {
                channels[chan] = new FAUSTFLOAT[buffer_size];
                memset(channels[chan], 0, sizeof(FAUSTFLOAT) * buffer_size);
            }
            return channels;
        }

        void deleteChannels(FAUSTFLOAT** channels, int num)
        {
            for (int chan = 0; chan < num; chan++) {
                delete [] channels[chan];
            }
            delete [] channels;
        }

     public:

        dsp_binary_combiner(dsp* dsp1, dsp* dsp2):fDSP1(dsp1), fDSP2(dsp2)
        {}

        virtual ~dsp_binary_combiner()
        {
            delete fDSP1;
            delete fDSP2;
        }

        virtual int getSampleRate()
        {
            return fDSP1->getSampleRate();
        }
        virtual void init(int sample_rate)
        {
            fDSP1->init(sample_rate);
            fDSP2->init(sample_rate);
        }
        virtual void instanceInit(int sample_rate)
        {
            fDSP1->instanceInit(sample_rate);
            fDSP2->instanceInit(sample_rate);
        }
        virtual void instanceConstants(int sample_rate)
        {
            fDSP1->instanceConstants(sample_rate);
            fDSP2->instanceConstants(sample_rate);
        }

        virtual void instanceResetUserInterface()
        {
            fDSP1->instanceResetUserInterface();
            fDSP2->instanceResetUserInterface();
        }

        virtual void instanceClear()
        {
            fDSP1->instanceClear();
            fDSP2->instanceClear();
        }

        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }

};

// Combine two 'compatible' DSP in sequence

class dsp_sequencer : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Outputs;

    public:

        dsp_sequencer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096):dsp_binary_combiner(dsp1, dsp2)
        {
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs(), buffer_size);
        }

        virtual ~dsp_sequencer()
        {
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface, "Sequencer");
        }

        virtual dsp* clone()
        {
            return new dsp_sequencer(fDSP1->clone(), fDSP2->clone());
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, fDSP1Outputs);
            fDSP2->compute(count, fDSP1Outputs, outputs);
        }

        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }

};

// Combine two DSP in parallel

class dsp_parallelizer : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP2Inputs;
        FAUSTFLOAT** fDSP2Outputs;

    public:

        dsp_parallelizer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096):dsp_binary_combiner(dsp1, dsp2)
        {
            fDSP2Inputs = new FAUSTFLOAT*[fDSP2->getNumInputs()];
            fDSP2Outputs = new FAUSTFLOAT*[fDSP2->getNumOutputs()];
        }

        virtual ~dsp_parallelizer()
        {
            delete [] fDSP2Inputs;
            delete [] fDSP2Outputs;
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs() + fDSP2->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs() + fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface, "Parallelizer");
        }

        virtual dsp* clone()
        {
            return new dsp_parallelizer(fDSP1->clone(), fDSP2->clone());
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, outputs);

            // Shift inputs/outputs channels for fDSP2
            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                fDSP2Inputs[chan] = inputs[fDSP1->getNumInputs() + chan];
            }
            for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                fDSP2Outputs[chan] = outputs[fDSP1->getNumOutputs() + chan];
            }

            fDSP2->compute(count, fDSP2Inputs, fDSP2Outputs);
        }

        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }

};

// Combine two 'compatible' DSP in splitter

class dsp_splitter : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Outputs;
        FAUSTFLOAT** fDSP2Inputs;

    public:

        dsp_splitter(dsp* dsp1, dsp* dsp2, int buffer_size = 4096):dsp_binary_combiner(dsp1, dsp2)
        {
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs(), buffer_size);
            fDSP2Inputs = new FAUSTFLOAT*[fDSP2->getNumInputs()];
        }

        virtual ~dsp_splitter()
        {
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
            delete [] fDSP2Inputs;
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface, "Splitter");
        }

        virtual dsp* clone()
        {
            return new dsp_splitter(fDSP1->clone(), fDSP2->clone());
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, fDSP1Outputs);

            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                 fDSP2Inputs[chan] = fDSP1Outputs[chan % fDSP1->getNumOutputs()];
            }

            fDSP2->compute(count, fDSP2Inputs, outputs);
        }
};

// Combine two 'compatible' DSP in merger

class dsp_merger : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Inputs;
        FAUSTFLOAT** fDSP1Outputs;
        FAUSTFLOAT** fDSP2Inputs;

        void mix(int count, FAUSTFLOAT* dst, FAUSTFLOAT* src)
        {
            for (int frame = 0; frame < count; frame++) {
                dst[frame] += src[frame];
            }
        }

    public:

        dsp_merger(dsp* dsp1, dsp* dsp2, int buffer_size = 4096):dsp_binary_combiner(dsp1, dsp2)
        {
            fDSP1Inputs = allocateChannels(fDSP1->getNumInputs(), buffer_size);
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs(), buffer_size);
            fDSP2Inputs = new FAUSTFLOAT*[fDSP2->getNumInputs()];
        }

        virtual ~dsp_merger()
        {
            deleteChannels(fDSP1Inputs, fDSP1->getNumInputs());
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
            delete [] fDSP2Inputs;
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface, "Merge");
        }

        virtual dsp* clone()
        {
            return new dsp_merger(fDSP1->clone(), fDSP2->clone());
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, fDSP1Inputs, fDSP1Outputs);

            memset(fDSP2Inputs, 0, sizeof(FAUSTFLOAT*) * fDSP2->getNumInputs());

            for (int chan = 0; chan < fDSP1->getNumOutputs(); chan++) {
                int mchan = chan % fDSP2->getNumInputs();
                if (fDSP2Inputs[mchan]) {
                    mix(count, fDSP2Inputs[mchan], fDSP1Outputs[chan]);
                } else {
                    fDSP2Inputs[mchan] = fDSP1Outputs[chan];
                }
            }

            fDSP2->compute(count, fDSP2Inputs, outputs);
        }
};

// Combine two 'compatible' DSP in a recursive way

class dsp_recursiver : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Inputs;
        FAUSTFLOAT** fDSP1Outputs;

        FAUSTFLOAT** fDSP2Inputs;
        FAUSTFLOAT** fDSP2Outputs;

    public:

        dsp_recursiver(dsp* dsp1, dsp* dsp2):dsp_binary_combiner(dsp1, dsp2)
        {
            fDSP1Inputs = allocateChannels(fDSP1->getNumInputs(), 1);
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs(), 1);
            fDSP2Inputs = allocateChannels(fDSP2->getNumInputs(), 1);
            fDSP2Outputs = allocateChannels(fDSP2->getNumOutputs(), 1);
        }

        virtual ~dsp_recursiver()
        {
            deleteChannels(fDSP1Inputs, fDSP1->getNumInputs());
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
            deleteChannels(fDSP2Inputs, fDSP2->getNumInputs());
            deleteChannels(fDSP2Outputs, fDSP2->getNumOutputs());
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs() - fDSP2->getNumOutputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface, "Recursiver");
        }

        virtual dsp* clone()
        {
            return new dsp_recursiver(fDSP1->clone(), fDSP2->clone());
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            for (int frame = 0; (frame < count); frame++) {

                for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                    fDSP1Inputs[chan][0] = fDSP2Outputs[chan][0];
                }

                for (int chan = 0; chan < fDSP1->getNumInputs() - fDSP2->getNumOutputs(); chan++) {
                    fDSP1Inputs[chan + fDSP2->getNumOutputs()][0] = inputs[chan][frame];
                }

                fDSP1->compute(1, fDSP1Inputs, fDSP1Outputs);

                for (int chan = 0; chan < fDSP1->getNumOutputs(); chan++) {
                    outputs[chan][frame] = fDSP1Outputs[chan][0];
                }

                for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                    fDSP2Inputs[chan][0] = fDSP1Outputs[chan][0];
                }

                fDSP2->compute(1, fDSP2Inputs, fDSP2Outputs);
            }
        }

        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }

};

#ifndef __dsp_algebra_api__
#define __dsp_algebra_api__
// DSP algebra API
/*
 Each operation takes two DSP as parameters, returns the combined DSPs, or null if failure with an error message.
 */

static dsp* createDSPSequencer(dsp* dsp1, dsp* dsp2, std::string& error)
{
    if (dsp1->getNumOutputs() != dsp2->getNumInputs()) {
        std::stringstream error_aux;
        error_aux << "Connection error int dsp_sequencer : the number of outputs ("
                  << dsp1->getNumOutputs() << ") of A "
                  << "must be equal to the number of inputs (" << dsp2->getNumInputs() << ") of B" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else {
        return new dsp_sequencer(dsp1, dsp2);
    }
}

static dsp* createDSPParallelize(dsp* dsp1, dsp* dsp2, std::string& error)
{
    return new dsp_parallelizer(dsp1, dsp2);
}

static dsp* createDSPSplitter(dsp* dsp1, dsp* dsp2, std::string& error)
{
    if (dsp1->getNumOutputs() == 0) {
        error = "Connection error in dsp_splitter : the first expression has no outputs\n";
        return nullptr;
    } else if (dsp2->getNumInputs() == 0) {
        error = "Connection error in dsp_splitter : the second expression has no inputs\n";
        return nullptr;
    } else if (dsp2->getNumInputs() % dsp1->getNumOutputs() != 0) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_splitter : the number of outputs (" << dsp1->getNumOutputs()
                  << ") of the first expression should be a divisor of the number of inputs ("
                  << dsp2->getNumInputs()
                  << ") of the second expression" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else if (dsp2->getNumInputs() == dsp1->getNumOutputs()) {
        return new dsp_sequencer(dsp1, dsp2);
    } else {
        return new dsp_splitter(dsp1, dsp2);
    }
}

static dsp* createDSPMerger(dsp* dsp1, dsp* dsp2, std::string& error)
{
    if (dsp1->getNumOutputs() == 0) {
        error = "Connection error in dsp_merger : the first expression has no outputs\n";
        return nullptr;
    } else if (dsp2->getNumInputs() == 0) {
        error = "Connection error in dsp_merger : the second expression has no inputs\n";
        return nullptr;
    } else if (dsp1->getNumOutputs() % dsp2->getNumInputs() != 0) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_merger : the number of outputs (" << dsp1->getNumOutputs()
                  << ") of the first expression should be a multiple of the number of inputs ("
                  << dsp2->getNumInputs()
                  << ") of the second expression" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else if (dsp2->getNumInputs() == dsp1->getNumOutputs()) {
        return new dsp_sequencer(dsp1, dsp2);
    } else {
        return new dsp_merger(dsp1, dsp2);
    }
}

static dsp* createDSPRecursiver(dsp* dsp1, dsp* dsp2, std::string& error)
{
    if ((dsp2->getNumInputs() > dsp1->getNumOutputs()) || (dsp2->getNumOutputs() > dsp1->getNumInputs())) {
        std::stringstream error_aux;
        error_aux << "Connection error in : dsp_recursiver" << std::endl;
        if (dsp2->getNumInputs() > dsp1->getNumOutputs()) {
            error_aux << "The number of outputs " << dsp1->getNumOutputs()
                      << " of the first expression should be greater or equal to the number of inputs ("
                      << dsp2->getNumInputs()
                      << ") of the second expression" << std::endl;
        }
        if (dsp2->getNumOutputs() > dsp1->getNumInputs()) {
            error_aux << "The number of inputs " << dsp1->getNumInputs()
                      << " of the first expression should be greater or equal to the number of outputs ("
                      << dsp2->getNumOutputs()
                      << ") of the second expression" << std::endl;
        }
        error = error_aux.str();
        return nullptr;
    } else {
        return new dsp_recursiver(dsp1, dsp2);
    }
}
#endif

#endif
/**************************  END  dsp-combiner.h **************************/
/************************** BEGIN JSONControl.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2019 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __JSON_CONTROL__
#define __JSON_CONTROL__

#include <string>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

struct JSONControl {
    
    virtual std::string getJSON() { return ""; }

    virtual void setParamValue(const std::string& path, FAUSTFLOAT value) {}

    virtual FAUSTFLOAT getParamValue(const std::string& path) { return 0; }
    
};

#endif
/**************************  END  JSONControl.h **************************/

#define kActiveVoice      0
#define kFreeVoice        -1
#define kReleaseVoice     -2
#define kNoVoice          -3

#define VOICE_STOP_LEVEL  0.0005    // -70 db
#define MIX_BUFFER_SIZE   4096

// endsWith(<str>,<end>) : returns true if <str> ends with <end>

static double midiToFreq(double note)
{
    return 440.0 * std::pow(2.0, (note-69.0)/12.0);
}

/**
 * Allows to control zones in a grouped manner.
 */

class GroupUI : public GUI, public PathBuilder
{

    private:

        std::map<std::string, uiGroupItem*> fLabelZoneMap;

        void insertMap(std::string label, FAUSTFLOAT* zone)
        {
            if (!MapUI::endsWith(label, "/gate")
                && !MapUI::endsWith(label, "/freq")
                && !MapUI::endsWith(label, "/gain")) {

                // Groups all controller except 'freq', 'gate', and 'gain'
                if (fLabelZoneMap.find(label) != fLabelZoneMap.end()) {
                    fLabelZoneMap[label]->addZone(zone);
                } else {
                    fLabelZoneMap[label] = new uiGroupItem(this, zone);
                }
            }
        }

        uiCallbackItem* fPanic;

    public:

        GroupUI(FAUSTFLOAT* zone, uiCallback cb, void* arg)
        {
            fPanic = new uiCallbackItem(this, zone, cb, arg);
        }
    
        virtual ~GroupUI()
        {
            // 'fPanic' is kept and deleted in GUI, so do not delete here
        }

        // -- widget's layouts
        void openTabBox(const char* label)
        {
            pushLabel(label);
        }
        void openHorizontalBox(const char* label)
        {
            pushLabel(label);
        }
        void openVerticalBox(const char* label)
        {
            pushLabel(label);
        }
        void closeBox()
        {
            popLabel();
        }

        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }

        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }

};

/**
 * One voice of polyphony.
 */

struct dsp_voice : public MapUI, public decorator_dsp {

    int fNote;                          // Playing note actual pitch
    int fDate;                          // KeyOn date
    int fRelease;                       // Current number of samples used in release mode to detect end of note
    int fMinRelease;                    // Max of samples used in release mode to detect end of note
    FAUSTFLOAT fLevel;                  // Last audio block level
    std::vector<std::string> fGatePath; // Paths of 'gate' control
    std::vector<std::string> fGainPath; // Paths of 'gain' control
    std::vector<std::string> fFreqPath; // Paths of 'freq' control
 
    dsp_voice(dsp* dsp):decorator_dsp(dsp)
    {
        dsp->buildUserInterface(this);
        fNote = kFreeVoice;
        fLevel = FAUSTFLOAT(0);
        fDate = 0;
        fMinRelease = dsp->getSampleRate()/2; // One 1/2 sec used in release mode to detect end of note
        extractPaths(fGatePath, fFreqPath, fGainPath);
    }
    virtual ~dsp_voice()
    {}

    void extractPaths(std::vector<std::string>& gate, std::vector<std::string>& freq, std::vector<std::string>& gain)
    {
        // Keep gain, freq and gate labels
        std::map<std::string, FAUSTFLOAT*>::iterator it;
        for (it = getMap().begin(); it != getMap().end(); it++) {
            std::string path = (*it).first;
            if (endsWith(path, "/gate")) {
                gate.push_back(path);
            } else if (endsWith(path, "/freq")) {
                freq.push_back(path);
            } else if (endsWith(path, "/gain")) {
                gain.push_back(path);
            }
        }
    }

    // MIDI velocity [0..127]
    void keyOn(int pitch, int velocity, bool trigger)
    {
        keyOn(pitch, float(velocity)/127.f, trigger);
    }

    // Normalized MIDI velocity [0..1]
    void keyOn(int pitch, float velocity, bool trigger)
    {
        for (size_t i = 0; i < fFreqPath.size(); i++) {
            setParamValue(fFreqPath[i], midiToFreq(pitch));
        }
        for (size_t i = 0; i < fGatePath.size(); i++) {
            setParamValue(fGatePath[i], FAUSTFLOAT(1));
        }
        for (size_t i = 0; i < fGainPath.size(); i++) {
            setParamValue(fGainPath[i], velocity);
        }
        
        fNote = pitch;
    }

    void keyOff(bool hard = false)
    {
        // No use of velocity for now...
        for (size_t i = 0; i < fGatePath.size(); i++) {
            setParamValue(fGatePath[i], FAUSTFLOAT(0));
        }
        
        if (hard) {
            // Immediately stop voice
            fNote = kFreeVoice;
        } else {
            // Release voice
            fRelease = fMinRelease;
            fNote = kReleaseVoice;
        }
    }

};

/**
 * A group of voices.
 */

struct dsp_voice_group {

    GroupUI fGroups;

    std::vector<dsp_voice*> fVoiceTable; // Individual voices
    dsp* fVoiceGroup;                    // Voices group to be used for GUI grouped control

    FAUSTFLOAT fPanic;

    bool fVoiceControl;
    bool fGroupControl;

    dsp_voice_group(uiCallback cb, void* arg, bool control, bool group)
        :fGroups(&fPanic, cb, arg),
        fVoiceGroup(0), fPanic(FAUSTFLOAT(0)),
        fVoiceControl(control), fGroupControl(group)
    {}

    virtual ~dsp_voice_group()
    {
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            delete fVoiceTable[i];
        }
        delete fVoiceGroup;
    }

    void addVoice(dsp_voice* voice)
    {
        fVoiceTable.push_back(voice);
    }

    void clearVoices()
    {
        fVoiceTable.clear();
    }

    void init()
    {
        // Groups all uiItem for a given path
        fVoiceGroup = new proxy_dsp(fVoiceTable[0]);
        fVoiceGroup->buildUserInterface(&fGroups);
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            fVoiceTable[i]->buildUserInterface(&fGroups);
        }
    }

    void buildUserInterface(UI* ui_interface)
    {
        if (fVoiceTable.size() > 1) {
            ui_interface->openTabBox("Polyphonic");

            // Grouped voices UI
            ui_interface->openVerticalBox("Voices");
            ui_interface->addButton("Panic", &fPanic);
            fVoiceGroup->buildUserInterface(ui_interface);
            ui_interface->closeBox();

            // If not grouped, also add individual voices UI
            if (!fGroupControl) {
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    char buffer[32];
                    snprintf(buffer, 32, ((fVoiceTable.size() < 8) ? "Voice%ld" : "V%ld"), long(i+1));
                    ui_interface->openHorizontalBox(buffer);
                    fVoiceTable[i]->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                }
            }

            ui_interface->closeBox();
        } else {
            fVoiceTable[0]->buildUserInterface(ui_interface);
        }
    }

};

/**
 * Base class for MIDI controllable DSP.
 */

#ifdef EMCC
#endif

class dsp_poly : public decorator_dsp, public midi, public JSONControl {

    protected:
    
    #ifdef EMCC
        MapUI fMapUI;
        std::string fJSON;
    #endif
    
    public:
    
        dsp_poly()
        {}
        dsp_poly(dsp* dsp):decorator_dsp(dsp)
        {
        #ifdef EMCC
            JSONUI jsonui(getNumInputs(), getNumOutputs());
            buildUserInterface(&jsonui);
            fJSON = jsonui.JSON(true);
            buildUserInterface(&fMapUI);
        #endif
        }
    
        virtual ~dsp_poly() {}
    
        // Reimplemented for EMCC
    #ifdef EMCC
        virtual int getNumInputs() { return decorator_dsp::getNumInputs(); }
        virtual int getNumOutputs() { return decorator_dsp::getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { decorator_dsp::buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return decorator_dsp::getSampleRate(); }
        virtual void init(int sample_rate) { decorator_dsp::init(sample_rate); }
        virtual void instanceInit(int sample_rate) { decorator_dsp::instanceInit(sample_rate); }
        virtual void instanceConstants(int sample_rate) { decorator_dsp::instanceConstants(sample_rate); }
        virtual void instanceResetUserInterface() { decorator_dsp::instanceResetUserInterface(); }
        virtual void instanceClear() { decorator_dsp::instanceClear(); }
        virtual dsp_poly* clone() { return new dsp_poly(fDSP->clone()); }
        virtual void metadata(Meta* m) { decorator_dsp::metadata(m); }
    
        // Additional API
        std::string getJSON()
        {
            return fJSON;
        }
    
        virtual void setParamValue(const std::string& path, FAUSTFLOAT value)
        {
            fMapUI.setParamValue(path, value);
            GUI::updateAllGuis();
        }
        
        virtual FAUSTFLOAT getParamValue(const std::string& path) { return fMapUI.getParamValue(path); }

        virtual void computeJS(int count, uintptr_t inputs, uintptr_t outputs)
        {
            decorator_dsp::compute(count, reinterpret_cast<FAUSTFLOAT**>(inputs),reinterpret_cast<FAUSTFLOAT**>(outputs));
        }
    #endif
    
        virtual  MapUI* keyOn(int channel, int pitch, int velocity)
        {
            return midi::keyOn(channel, pitch, velocity);
        }
        virtual  void keyOff(int channel, int pitch, int velocity)
        {
            midi::keyOff(channel, pitch, velocity);
        }
        virtual  void keyPress(int channel, int pitch, int press)
        {
            midi::keyPress(channel, pitch, press);
        }
        virtual void chanPress(int channel, int press)
        {
            midi::chanPress(channel, press);
        }
        virtual void ctrlChange(int channel, int ctrl, int value)
        {
            midi::ctrlChange(channel, ctrl, value);
        }
        virtual void ctrlChange14bits(int channel, int ctrl, int value)
        {
            midi::ctrlChange14bits(channel, ctrl, value);
        }
        virtual void pitchWheel(int channel, int wheel)
        {
            midi::pitchWheel(channel, wheel);
        }
        virtual void progChange(int channel, int pgm)
        {
            midi::progChange(channel, pgm);
        }
    
        // Group API
        virtual void setGroup(bool group) {}
        virtual bool getGroup() { return false; }

};

/**
 * Polyphonic DSP: groups a set of DSP to be played together or triggered by MIDI.
 *
 * All voices are preallocated by cloning the single DSP voice given at creation time.
 * Dynamic voice allocation is done in 'getFreeVoice'
 */

class mydsp_poly : public dsp_voice_group, public dsp_poly {

    private:

        FAUSTFLOAT** fMixBuffer;
        int fDate;

        FAUSTFLOAT mixCheckVoice(int count, FAUSTFLOAT** outputBuffer, FAUSTFLOAT** mixBuffer)
        {
            FAUSTFLOAT level = 0;
            for (int i = 0; i < getNumOutputs(); i++) {
                FAUSTFLOAT* mixChannel = mixBuffer[i];
                FAUSTFLOAT* outChannel = outputBuffer[i];
                for (int j = 0; j < count; j++) {
                    level = std::max<FAUSTFLOAT>(level, (FAUSTFLOAT)fabs(outChannel[j]));
                    mixChannel[j] += outChannel[j];
                }
            }
            return level;
        }
    
        void mixVoice(int count, FAUSTFLOAT** outputBuffer, FAUSTFLOAT** mixBuffer)
        {
            FAUSTFLOAT level = 0;
            for (int i = 0; i < getNumOutputs(); i++) {
                FAUSTFLOAT* mixChannel = mixBuffer[i];
                FAUSTFLOAT* outChannel = outputBuffer[i];
                for (int j = 0; j < count; j++) {
                    mixChannel[j] += outChannel[j];
                }
            }
        }

        void clearOutput(int count, FAUSTFLOAT** mixBuffer)
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                memset(mixBuffer[i], 0, count * sizeof(FAUSTFLOAT));
            }
        }
    
        int getPlayingVoice(int pitch)
        {
            int voice_playing = kNoVoice;
            int oldest_date_playing = INT_MAX;
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == pitch) {
                    // Keeps oldest playing voice
                    if (fVoiceTable[i]->fDate < oldest_date_playing) {
                        oldest_date_playing = fVoiceTable[i]->fDate;
                        voice_playing = int(i);
                    }
                }
            }
            
            return voice_playing;
        }
    
        // Always returns a voice
        int getFreeVoice()
        {
            int voice = kNoVoice;
            
            // Looks for the first available voice
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == kFreeVoice) {
                    voice = int(i);
                    goto result;
                }
            }

            {
                // Otherwise steal one
                int voice_release = kNoVoice;
                int voice_playing = kNoVoice;
                
                int oldest_date_release = INT_MAX;
                int oldest_date_playing = INT_MAX;

                // Scan all voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    if (fVoiceTable[i]->fNote == kReleaseVoice) {
                        // Keeps oldest release voice
                        if (fVoiceTable[i]->fDate < oldest_date_release) {
                            oldest_date_release = fVoiceTable[i]->fDate;
                            voice_release = int(i);
                        }
                    } else {
                        // Otherwise keeps oldest playing voice
                        if (fVoiceTable[i]->fDate < oldest_date_playing) {
                            oldest_date_playing = fVoiceTable[i]->fDate;
                            voice_playing = int(i);
                        }
                    }
                }
            
                // Then decide which one to steal
                if (oldest_date_release != INT_MAX) {
                    std::cout << "Steal release voice : voice_date " << fVoiceTable[voice_release]->fDate << " cur_date = " << fDate << " voice = " << voice_release << std::endl;
                    voice = voice_release;
                    goto result;
                } else if (oldest_date_playing != INT_MAX) {
                    std::cout << "Steal playing voice : voice_date " << fVoiceTable[voice_playing]->fDate << " cur_date = " << fDate << " voice = " << voice_playing << std::endl;
                    voice = voice_playing;
                    goto result;
                } else {
                    assert(false);
                    return kNoVoice;
                }
            }
            
        result:
            // So that envelop is always re-initialized
            fVoiceTable[voice]->instanceClear();
            fVoiceTable[voice]->fDate = fDate++;
            fVoiceTable[voice]->fNote = kActiveVoice;
            return voice;
        }

        static void panic(FAUSTFLOAT val, void* arg)
        {
            if (val == FAUSTFLOAT(1)) {
                static_cast<mydsp_poly*>(arg)->allNotesOff(true);
            }
        }

        bool checkPolyphony()
        {
            if (fVoiceTable.size() > 0) {
                return true;
            } else {
                std::cout << "DSP is not polyphonic...\n";
                return false;
            }
        }

    public:
    
        /**
         * Constructor.
         *
         * @param dsp - the dsp to be used for one voice. Beware: mydsp_poly will use and finally delete the pointer.
         * @param nvoices - number of polyphony voices, should be at least 1
         * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
         *                If false all voices are always running.
         * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
         *                a given control on all voices, assuming GUI::updateAllGuis() is called.
         *                If false, all voices can be individually controlled.
         *                setGroup/getGroup methods can be used to set/get the group state.
         *
         */
        mydsp_poly(dsp* dsp,
                   int nvoices,
                   bool control = false,
                   bool group = true)
        : dsp_voice_group(panic, this, control, group), dsp_poly(dsp) // dsp parameter is deallocated by ~dsp_poly
        {
            fDate = 0;

            // Create voices
            assert(nvoices > 0);
            for (int i = 0; i < nvoices; i++) {
                addVoice(new dsp_voice(dsp->clone()));
            }

            // Init audio output buffers
            fMixBuffer = new FAUSTFLOAT*[getNumOutputs()];
            for (int i = 0; i < getNumOutputs(); i++) {
                fMixBuffer[i] = new FAUSTFLOAT[MIX_BUFFER_SIZE];
            }

            dsp_voice_group::init();
        }

        virtual ~mydsp_poly()
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                delete[] fMixBuffer[i];
            }
            delete[] fMixBuffer;
        }

        // DSP API
    
        void buildUserInterface(UI* ui_interface)
        {
            dsp_voice_group::buildUserInterface(ui_interface);
        }

        void init(int sample_rate)
        {
            decorator_dsp::init(sample_rate);
            fVoiceGroup->init(sample_rate);
            fPanic = FAUSTFLOAT(0);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->init(sample_rate);
            }
        }
    
        void instanceInit(int samplingFreq)
        {
            instanceConstants(samplingFreq);
            instanceResetUserInterface();
            instanceClear();
        }

        void instanceConstants(int sample_rate)
        {
            decorator_dsp::instanceConstants(sample_rate);
            fVoiceGroup->instanceConstants(sample_rate);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceConstants(sample_rate);
            }
        }

        void instanceResetUserInterface()
        {
            decorator_dsp::instanceResetUserInterface();
            fVoiceGroup->instanceResetUserInterface();
            fPanic = FAUSTFLOAT(0);
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceResetUserInterface();
            }
        }

        void instanceClear()
        {
            decorator_dsp::instanceClear();
            fVoiceGroup->instanceClear();
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceClear();
            }
        }

        virtual mydsp_poly* clone()
        {
            return new mydsp_poly(fDSP->clone(), int(fVoiceTable.size()), fVoiceControl, fGroupControl);
        }

        void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count <= MIX_BUFFER_SIZE);

            // First clear the outputs
            clearOutput(count, outputs);

            if (fVoiceControl) {
                // Mix all playing voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    dsp_voice* voice = fVoiceTable[i];
                    if (voice->fNote != kFreeVoice) {
                        voice->compute(count, inputs, fMixBuffer);
                        // Mix it in result
                        voice->fLevel = mixCheckVoice(count, fMixBuffer, outputs);
                        // Check the level to possibly set the voice in kFreeVoice again
                        voice->fRelease -= count;
                        if ((voice->fNote == kReleaseVoice)
                            && (voice->fRelease < 0)
                            && (voice->fLevel < VOICE_STOP_LEVEL)) {
                            voice->fNote = kFreeVoice;
                        }
                    }
                }
            } else {
                // Mix all voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    fVoiceTable[i]->compute(count, inputs, fMixBuffer);
                    mixVoice(count, fMixBuffer, outputs);
                }
            }
        }

        void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            compute(count, inputs, outputs);
        }
    
        // Terminate all active voices, gently or immediately (depending of 'hard' value)
        void allNotesOff(bool hard = false)
        {
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->keyOff(hard);
            }
        }

        // Additional polyphonic API
        MapUI* newVoice()
        {
            return fVoiceTable[getFreeVoice()];
        }

        void deleteVoice(MapUI* voice)
        {
            std::vector<dsp_voice*>::iterator it = find(fVoiceTable.begin(), fVoiceTable.end(), reinterpret_cast<dsp_voice*>(voice));
            if (it != fVoiceTable.end()) {
                (*it)->keyOff();
            } else {
                std::cout << "Voice not found\n";
            }
        }
    
        void setGroup(bool group) { fGroupControl = group; }
        bool getGroup() { return fGroupControl; }

        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            if (checkPolyphony()) {
                int voice = getFreeVoice();
                fVoiceTable[voice]->keyOn(pitch, velocity, true);
                return fVoiceTable[voice];
            } else {
                return 0;
            }
        }

        void keyOff(int channel, int pitch, int velocity = 127)
        {
            if (checkPolyphony()) {
                int voice = getPlayingVoice(pitch);
                if (voice != kNoVoice) {
                    fVoiceTable[voice]->keyOff();
                } else {
                    std::cout << "Playing pitch = " << pitch << " not found\n";
                }
            }
        }

        void pitchWheel(int channel, int wheel)
        {}

        void ctrlChange(int channel, int ctrl, int value)
        {
            if (ctrl == ALL_NOTES_OFF || ctrl == ALL_SOUND_OFF) {
                allNotesOff();
            }
        }

        void progChange(int channel, int pgm)
        {}

        void keyPress(int channel, int pitch, int press)
        {}

        void chanPress(int channel, int press)
        {}

        void ctrlChange14bits(int channel, int ctrl, int value)
        {}

};

/**
 * Polyphonic DSP with an integrated effect. fPolyDSP will respond to MIDI messages.
 */
class dsp_poly_effect : public dsp_poly {
    
    private:
        
        dsp_poly* fPolyDSP;
        
    public:
        
        dsp_poly_effect(dsp_poly* dsp1, dsp* dsp2)
        :dsp_poly(dsp2), fPolyDSP(dsp1)
        {}
        
        virtual ~dsp_poly_effect()
        {
            // dsp_poly_effect is also a decorator_dsp, which will free fPolyDSP
        }
        
        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            return fPolyDSP->keyOn(channel, pitch, velocity);
        }
        void keyOff(int channel, int pitch, int velocity)
        {
            fPolyDSP->keyOff(channel, pitch, velocity);
        }
        void keyPress(int channel, int pitch, int press)
        {
            fPolyDSP->keyPress(channel, pitch, press);
        }
        void chanPress(int channel, int press)
        {
            fPolyDSP->chanPress(channel, press);
        }
        void ctrlChange(int channel, int ctrl, int value)
        {
            fPolyDSP->ctrlChange(channel, ctrl, value);
        }
        void ctrlChange14bits(int channel, int ctrl, int value)
        {
            fPolyDSP->ctrlChange14bits(channel, ctrl, value);
        }
        void pitchWheel(int channel, int wheel)
        {
            fPolyDSP->pitchWheel(channel, wheel);
        }
        void progChange(int channel, int pgm)
        {
            fPolyDSP->progChange(channel, pgm);
        }
        
        // Group API
        void setGroup(bool group)
        {
            fPolyDSP->setGroup(group);
        }
        bool getGroup()
        {
            return fPolyDSP->getGroup();
        }
};

/**
 * Polyphonic DSP factory class. Helper code to support polyphonic DSP source with an integrated effect.
 */

struct dsp_poly_factory : public dsp_factory {
    
    dsp_factory* fProcessFactory;
    dsp_factory* fEffectFactory;
    
    std::string getEffectCode(const std::string& dsp_content)
    {
        std::stringstream effect_code;
        effect_code << "adapt(1,1) = _; adapt(2,2) = _,_; adapt(1,2) = _ <: _,_; adapt(2,1) = _,_ :> _;";
        effect_code << "adaptor(F,G) = adapt(outputs(F),inputs(G)); dsp_code = environment{ " << dsp_content << " };";
        effect_code << "process = adaptor(dsp_code.process, dsp_code.effect) : dsp_code.effect;";
        return effect_code.str();
    }

    dsp_poly_factory(dsp_factory* process_factory = NULL,
                     dsp_factory* effect_factory = NULL):
    fProcessFactory(process_factory)
    ,fEffectFactory(effect_factory)
    {}
    
    virtual ~dsp_poly_factory()
    {}
    
    virtual std::string getName() { return fProcessFactory->getName(); }
    virtual std::string getSHAKey() { return fProcessFactory->getSHAKey(); }
    virtual std::string getDSPCode() { return fProcessFactory->getDSPCode(); }
    virtual std::string getCompileOptions() { return fProcessFactory->getCompileOptions(); }
    virtual std::vector<std::string> getLibraryList() { return fProcessFactory->getLibraryList(); }
    virtual std::vector<std::string> getIncludePathnames() { return fProcessFactory->getIncludePathnames(); }
    
    virtual void setMemoryManager(dsp_memory_manager* manager)
    {
        fProcessFactory->setMemoryManager(manager);
        if (fEffectFactory) {
            fEffectFactory->setMemoryManager(manager);
        }
    }
    virtual dsp_memory_manager* getMemoryManager() { return fProcessFactory->getMemoryManager(); }
    
    /* Create a new polyphonic DSP instance with global effect, to be deleted with C++ 'delete'
     *
     * @param nvoices - number of polyphony voices, should be at least 1
     * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
     *                If false all voices are always running.
     * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
     *                a given control on all voices, assuming GUI::updateAllGuis() is called.
     *                If false, all voices can be individually controlled.
     */
    dsp_poly* createPolyDSPInstance(int nvoices, bool control, bool group)
    {
        dsp_poly* dsp_poly = new mydsp_poly(fProcessFactory->createDSPInstance(), nvoices, control, group);
        if (fEffectFactory) {
            // the 'dsp_poly' object has to be controlled with MIDI, so kept separated from new dsp_sequencer(...) object
            return new dsp_poly_effect(dsp_poly, new dsp_sequencer(dsp_poly, fEffectFactory->createDSPInstance()));
        } else {
            return new dsp_poly_effect(dsp_poly, dsp_poly);
        }
    }
    
    /* Create a new DSP instance, to be deleted with C++ 'delete' */
    dsp* createDSPInstance()
    {
        return fProcessFactory->createDSPInstance();
    }
    
};

#endif // __poly_dsp__
/**************************  END  poly-dsp.h **************************/

#ifdef POLY2
#include "effect.h"
#endif

dsp* DSP;

std::list<GUI*> GUI::fGuiList;
ztimedmap GUI::gTimedZoneMap;

/******************************************************************************
 *******************************************************************************
 
 Sensors section
 
 *******************************************************************************
 *******************************************************************************/

#ifdef IOS
#include <QAccelerometer>
#include <QGyroscope>
#include <QAccelerometerReading>
#include <QGyroscopeReading>
#include <QTimer>

//------------------------------------------------------------------------
class Sensor
{
    private:
        
        QSensor* fSensor;
        int fType;
        QSensorReading* fReader;
        QSensor* create(int type) const;
        
    public:
        enum { kSensorStart = 1, kAccelerometer = 1, kGyroscope, kSensorMax };
        
        Sensor(int type) : fSensor(0), fType(type), fReader(0)
        { fSensor = create (type); fSensor->connectToBackend(); }
        virtual ~Sensor() { if (available()) activate (false); delete fSensor; }
        
        int isAccel() const { return fType == kAccelerometer; }
        int isGyro () const { return fType == kGyroscope; }
        bool available() const { return fSensor->isConnectedToBackend(); }
        bool active() const { return fSensor->isActive(); }
        void activate(bool state){ fSensor->setActive(state); fReader = fSensor->reading(); }
        int count() { return fReader ? fReader->valueCount() : 0; }
        float value(int i) const { return fReader->value(i).value<float>(); }
};

//------------------------------------------------------------------------
QSensor* Sensor::create(int type) const
{
    switch (type) {
        case kAccelerometer: return new QAccelerometer();
        case kGyroscope: return new QGyroscope();
        default: cerr << "unknown sensor type " << type << endl;
    }
    return 0;
}

//------------------------------------------------------------------------
class Sensors : public QObject
{
    private:
        
        APIUI* fUI;
        Sensor fAccel, fGyro;
        int fTimerID;
        
    public:
        
        typedef std::map<int, Sensor*> TSensors;
        Sensors(APIUI* ui)
        : fUI(ui), fAccel(Sensor::kAccelerometer), fGyro(Sensor::kGyroscope), fTimerID(0) {}
        virtual ~Sensors() { killTimer(fTimerID); }
        void start();
        
    protected:
        
        void timerEvent(QTimerEvent*);
};

//------------------------------------------------------------------------
void Sensors::timerEvent(QTimerEvent*)
{
    if (fAccel.active()) {
        int count = fAccel.count();
        for (int i = 0; (i< count) && (i < 3); i++) {
            fUI->propagateAcc(i, fAccel.value(i));
        }
    }
    if (fGyro.active()) {
        int count = fGyro.count();
        for (int i = 0; (i< count) && (i < 3); i++) {
            fUI->propagateGyr(i, fGyro.value(i));
        }
    }
}

//------------------------------------------------------------------------
void Sensors::start()
{
    bool activate = false;
    if (fAccel.available()) { fAccel.activate(true); activate = true; }
    if (fGyro.available()) { fGyro.activate(true); activate = true; }
    if (activate) fTimerID = startTimer(10);
}
#endif

/******************************************************************************
 *******************************************************************************
 
 MAIN PLAY THREAD
 
 *******************************************************************************
 *******************************************************************************/

#ifdef IOS
#define lopt(a,b,val)	val
#define coreaudio		iosaudio
#endif

int main(int argc, char *argv[])
{
    char name[256];
    char rcfilename[256];
    char* home = getenv("HOME");
    bool midi_sync = false;
    int nvoices = 0;
    bool control = true;
    mydsp_poly* dsp_poly = NULL;
    
    mydsp* tmp_dsp = new mydsp();
    MidiMeta::analyse(tmp_dsp, midi_sync, nvoices);
    delete tmp_dsp;
    
#ifdef IOS
    APIUI apiui;
    Sensors sensors(&apiui);
#endif
    
    snprintf(name, 256, "%s", basename(argv[0]));
    snprintf(rcfilename, 256, "%s/.%src", home, name);
    
    if (isopt(argv, "-h")) {
        std::cout << "prog [--frequency <val>] [--buffer <val>] [--nvoices <val>] [--control <0/1>] [--group <0/1>] [--virtual-midi <0/1>]\n";
        exit(1);
    }
    
    long srate = (long)lopt(argv, "--frequency", -1);
    int fpb = lopt(argv, "--buffer", 512);
    bool is_virtual = lopt(argv, "--virtual-midi", false);
    
#ifdef POLY2
    nvoices = lopt(argv, "--nvoices", nvoices);
    control = lopt(argv, "--control", control);
    int group = lopt(argv, "--group", 1);
    
    std::cout << "Started with " << nvoices << " voices\n";
    dsp_poly = new mydsp_poly(new mydsp(), nvoices, control, group);
    
#if MIDICTRL
    if (midi_sync) {
        DSP = new timed_dsp(new dsp_sequencer(dsp_poly, new effect()));
    } else {
        DSP = new dsp_sequencer(dsp_poly, new effect());
    }
#else
    DSP = new dsp_sequencer(dsp_poly, new effect());
#endif
    
#else
    nvoices = lopt(argv, "--nvoices", nvoices);
    control = lopt(argv, "--control", control);
    int group = lopt(argv, "--group", 1);
    
    if (nvoices > 0) {
        std::cout << "Started with " << nvoices << " voices\n";
        dsp_poly = new mydsp_poly(new mydsp(), nvoices, control, group);
        
#if MIDICTRL
        if (midi_sync) {
            DSP = new timed_dsp(dsp_poly);
        } else {
            DSP = dsp_poly;
        }
#else
        DSP = dsp_poly;
#endif
        
    } else {
#if MIDICTRL
        if (midi_sync) {
            DSP = new timed_dsp(new mydsp());
        } else {
            DSP = new mydsp();
        }
#else
        // We possibly have a file...
        /*
         try {
            DSP = new dsp_sequencer(new sound_player(stringify_expanded(SOUND_FILE)), new mydsp());
         } catch (...) {
            DSP = new mydsp();
         }
         */
        DSP = new mydsp();
#endif
    }
    
#endif
    
    if (DSP == 0) {
        std::cerr << "Unable to allocate Faust DSP object" << std::endl;
        exit(1);
    }
    
    QApplication myApp(argc, argv);
    
    FUI finterface;
    QTGUI* interface = new QTGUI();
    
#ifdef PRESETUI
    PresetUI* pinterface = new PresetUI(interface, std::string(PRESETDIR) + std::string(name) + ((nvoices > 0) ? "_poly" : ""));
    DSP->buildUserInterface(pinterface);
#else
    DSP->buildUserInterface(interface);
    DSP->buildUserInterface(&finterface);
#endif
    
#ifdef IOS
    DSP->buildUserInterface(&apiui);
#endif
    
#ifdef MIDICTRL
    rt_midi midi_handler(name, is_virtual);
    midi_handler.addMidiIn(dsp_poly);
    MidiUI midiinterface(&midi_handler);
    DSP->buildUserInterface(&midiinterface);
    std::cout << "MIDI is on" << std::endl;
#endif
    
#ifdef HTTPCTRL
    httpdUI httpdinterface(name, DSP->getNumInputs(), DSP->getNumOutputs(), argc, argv);
    DSP->buildUserInterface(&httpdinterface);
    std::cout << "HTTPD is on" << std::endl;
#endif
    
    coreaudio audio(srate, fpb);
    audio.init(name, DSP);
    audio.start();
   
// After audio init to get SR
#ifdef SOUNDFILE
    // Use bundle path
    SoundUI soundinterface(SoundUI::getBinaryPath("/Contents/Resources/"), audio.getSampleRate());
    // SoundUI has to be dispatched on all internal voices
    if (dsp_poly) dsp_poly->setGroup(false);
    DSP->buildUserInterface(&soundinterface);
    if (dsp_poly) dsp_poly->setGroup(group);
#endif
    
#ifdef IOS
    sensors.start();
#endif
    
#ifdef OSCCTRL
    OSCUI oscinterface(name, argc, argv);
    DSP->buildUserInterface(&oscinterface);
    std::cout << "OSC is on" << std::endl;
    audio.addControlCallback(osc_compute_callback, &oscinterface);
#endif
    
    std::cout << "ins " << audio.getNumInputs() << std::endl;
    std::cout << "outs " << audio.getNumOutputs() << std::endl;
    
#ifdef HTTPCTRL
    httpdinterface.run();
#ifdef QRCODECTRL
    interface->displayQRCode(httpdinterface.getTCPPort());
#endif
#endif
    
#ifdef OSCCTRL
    oscinterface.run();
#endif
#ifdef MIDICTRL
    if (!midiinterface.run()) {
        std::cerr << "MidiUI run error\n";
    }
#endif
    
    // After the allocation of controllers
    finterface.recallState(rcfilename);
    interface->run();
    
    myApp.setStyleSheet(interface->styleSheet());
    myApp.exec();
    
#ifdef MIDICTRL
    midiinterface.stop();
#endif
    interface->stop();
    
    audio.stop();
    finterface.saveState(rcfilename);
    
    return 0;
}

/********************END ARCHITECTURE SECTION (part 2/2)****************/


#endif
