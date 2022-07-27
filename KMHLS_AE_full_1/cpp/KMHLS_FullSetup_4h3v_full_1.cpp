/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit, Henrik Frisk"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMHLS_FullSetup_4h3v_full_1"
version: "1.2"
Code generated with Faust 2.30.5 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -scal -ftz 0
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
 Copyright (C) 2005-2012 Stefan Kersten.
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

// The prefix is set to "Faust" in the faust2supercollider script, otherwise set empty
#if !defined(SC_FAUST_PREFIX)
#define SC_FAUST_PREFIX ""
#endif

#include <map>
#include <string>
#include <string.h>
#include <SC_PlugIn.h>

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

struct UI;
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
         * to 'openTabBox', 'addButton', 'addVerticalSlider'... in order to build the UI.
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
    
        /* Init instance state (like delay lines...) but keep the control parameter values */
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

        decorator_dsp(dsp* dsp = nullptr):fDSP(dsp) {}
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
/************************** BEGIN UI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2020 GRAME, Centre National de Creation Musicale
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
struct UIReal
{
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

struct UI : public UIReal<FAUSTFLOAT>
{
    UI() {}
    virtual ~UI() {}
};

#endif
/**************************  END  UI.h **************************/
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
    for (int i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return std::atoi(argv[i+1]);
    return def;
}

static long lopt1(int argc, char* argv[], const char* longname, const char* shortname, long def)
{
    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i-1], shortname) == 0 || strcmp(argv[i-1], longname) == 0) {
            return atoi(argv[i]);
        }
    }
    return def;
}

static const char* lopts(char* argv[], const char* name, const char* def)
{
    for (int i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
    return def;
}

static const char* lopts1(int argc, char* argv[], const char* longname, const char* shortname, const char* def)
{
    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i-1], shortname) == 0 || strcmp(argv[i-1], longname) == 0) {
            return argv[i];
        }
    }
    return def;
}

static bool isopt(char* argv[], const char* name)
{
    for (int i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
    return false;
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

using namespace std;

#if defined(__GNUC__) && __GNUC__ >= 4
    #define FAUST_EXPORT __attribute__((visibility("default")))
#else
    #define FAUST_EXPORT  SC_API_EXPORT
#endif

#ifdef WIN32
    #define STRDUP _strdup
#else
    #define STRDUP strdup
#endif

//----------------------------------------------------------------------------
// Metadata
//----------------------------------------------------------------------------

class MetaData : public Meta
               , public std::map<std::string, std::string>
{
public:
    void declare(const char* key, const char* value)
    {
        (*this)[key] = value;
    }
};

//----------------------------------------------------------------------------
// Control counter
//----------------------------------------------------------------------------

class ControlCounter : public UI
{
public:
    ControlCounter()
        : mNumControlInputs(0),
          mNumControlOutputs(0)
    {}

    size_t getNumControls() const { return getNumControlInputs(); }
    size_t getNumControlInputs() const { return mNumControlInputs; }
    size_t getNumControlOutputs() const { return mNumControlOutputs; }

    // Layout widgets
    virtual void openTabBox(const char* label) { }
    virtual void openHorizontalBox(const char* label) { }
    virtual void openVerticalBox(const char* label) { }
    virtual void closeBox() { }

    // Active widgets
    virtual void addButton(const char* label, FAUSTFLOAT* zone)
    { addControlInput(); }
    virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
    { addControlInput(); }
    virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    { addControlInput(); }
    virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    { addControlInput(); }
    virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    { addControlInput(); }

    // Passive widgets
    virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
    { addControlOutput(); }
    virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
    { addControlOutput(); }
    
    virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}

protected:
    void addControlInput() { mNumControlInputs++; }
    void addControlOutput() { mNumControlOutputs++; }

private:
    size_t mNumControlInputs;
    size_t mNumControlOutputs;
};

//----------------------------------------------------------------------------
// UI control
//----------------------------------------------------------------------------

struct Control
{
    typedef void (*UpdateFunction)(Control* self, FAUSTFLOAT value);

    UpdateFunction updateFunction;
    FAUSTFLOAT* zone;
    FAUSTFLOAT min, max;

    inline void update(FAUSTFLOAT value)
    {
        (*updateFunction)(this, value);
    }

    static void simpleUpdate(Control* self, FAUSTFLOAT value)
    {
        *self->zone = value;
    }
    static void boundedUpdate(Control* self, FAUSTFLOAT value)
    {
        *self->zone = sc_clip(value, self->min, self->max);
    }
};

//----------------------------------------------------------------------------
// Control allocator
//----------------------------------------------------------------------------

class ControlAllocator : public UI
{
public:
    ControlAllocator(Control* controls)
        : mControls(controls)
    { }

    // Layout widgets
    virtual void openTabBox(const char* label) { }
    virtual void openHorizontalBox(const char* label) { }
    virtual void openVerticalBox(const char* label) { }
    virtual void closeBox() { }

    // Active widgets
    virtual void addButton(const char* label, FAUSTFLOAT* zone)
    { addSimpleControl(zone); }
    virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
    { addSimpleControl(zone); }
    virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    { addBoundedControl(zone, min, max, step); }
    virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    { addBoundedControl(zone, min, max, step); }
    virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    { addBoundedControl(zone, min, max, step); }

    // Passive widgets
    virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}

private:
    void addControl(Control::UpdateFunction updateFunction, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT /* step */)
    {
        Control* ctrl        = mControls++;
        ctrl->updateFunction = updateFunction;
        ctrl->zone           = zone;
        ctrl->min            = min;
        ctrl->max            = max;
    }
    void addSimpleControl(FAUSTFLOAT* zone)
    {
        addControl(Control::simpleUpdate, zone, 0.f, 0.f, 0.f);
    }
    void addBoundedControl(FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        addControl(Control::boundedUpdate, zone, min, max, step);
    }

private:
    Control* mControls;
};

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
	float fConst8;
	float fConst9;
	float fConst10;
	float fRec16[3];
	float fRec17[3];
	float fRec18[3];
	float fRec19[3];
	float fRec20[3];
	float fRec21[3];
	float fRec22[3];
	float fRec23[3];
	float fRec15[2];
	float fRec13[2];
	float fRec12[2];
	float fRec10[2];
	float fRec9[2];
	float fRec7[2];
	float fRec6[2];
	float fRec4[2];
	float fConst11;
	float fConst12;
	float fConst13;
	float fConst14;
	float fConst15;
	float fRec33[3];
	float fRec34[3];
	float fRec35[3];
	float fRec36[3];
	float fRec37[3];
	float fRec38[3];
	float fRec39[3];
	float fRec32[2];
	float fRec30[2];
	float fRec29[2];
	float fRec27[2];
	float fConst16;
	float fRec26[2];
	float fRec24[2];
	float fConst17;
	float fRec43[3];
	float fRec44[3];
	float fRec45[3];
	float fConst18;
	float fRec42[2];
	float fRec40[2];
	float fConst19;
	float fRec52[3];
	float fRec53[3];
	float fRec54[3];
	float fRec55[3];
	float fRec56[3];
	float fConst20;
	float fConst21;
	float fRec51[2];
	float fRec49[2];
	float fRec48[2];
	float fRec46[2];
	int IOTA;
	float fVec0[1024];
	int iConst22;
	float fRec68[2];
	float fRec66[2];
	float fRec65[2];
	float fRec63[2];
	float fRec62[2];
	float fRec60[2];
	float fRec59[2];
	float fRec57[2];
	float fRec77[2];
	float fRec75[2];
	float fRec74[2];
	float fRec72[2];
	float fRec71[2];
	float fRec69[2];
	float fRec80[2];
	float fRec78[2];
	float fRec86[2];
	float fRec84[2];
	float fRec83[2];
	float fRec81[2];
	float fVec1[1024];
	float fRec98[2];
	float fRec96[2];
	float fRec95[2];
	float fRec93[2];
	float fRec92[2];
	float fRec90[2];
	float fRec89[2];
	float fRec87[2];
	float fRec107[2];
	float fRec105[2];
	float fRec104[2];
	float fRec102[2];
	float fRec101[2];
	float fRec99[2];
	float fRec110[2];
	float fRec108[2];
	float fRec116[2];
	float fRec114[2];
	float fRec113[2];
	float fRec111[2];
	float fVec2[1024];
	float fRec128[2];
	float fRec126[2];
	float fRec125[2];
	float fRec123[2];
	float fRec122[2];
	float fRec120[2];
	float fRec119[2];
	float fRec117[2];
	float fRec137[2];
	float fRec135[2];
	float fRec134[2];
	float fRec132[2];
	float fRec131[2];
	float fRec129[2];
	float fRec140[2];
	float fRec138[2];
	float fRec146[2];
	float fRec144[2];
	float fRec143[2];
	float fRec141[2];
	float fVec3[1024];
	float fRec158[2];
	float fRec156[2];
	float fRec155[2];
	float fRec153[2];
	float fRec152[2];
	float fRec150[2];
	float fRec149[2];
	float fRec147[2];
	float fRec167[2];
	float fRec165[2];
	float fRec164[2];
	float fRec162[2];
	float fRec161[2];
	float fRec159[2];
	float fRec170[2];
	float fRec168[2];
	float fRec176[2];
	float fRec174[2];
	float fRec173[2];
	float fRec171[2];
	float fVec4[1024];
	float fRec188[2];
	float fRec186[2];
	float fRec185[2];
	float fRec183[2];
	float fRec182[2];
	float fRec180[2];
	float fRec179[2];
	float fRec177[2];
	float fRec197[2];
	float fRec195[2];
	float fRec194[2];
	float fRec192[2];
	float fRec191[2];
	float fRec189[2];
	float fRec200[2];
	float fRec198[2];
	float fRec206[2];
	float fRec204[2];
	float fRec203[2];
	float fRec201[2];
	float fVec5[1024];
	float fRec218[2];
	float fRec216[2];
	float fRec215[2];
	float fRec213[2];
	float fRec212[2];
	float fRec210[2];
	float fRec209[2];
	float fRec207[2];
	float fRec227[2];
	float fRec225[2];
	float fRec224[2];
	float fRec222[2];
	float fRec221[2];
	float fRec219[2];
	float fRec230[2];
	float fRec228[2];
	float fRec236[2];
	float fRec234[2];
	float fRec233[2];
	float fRec231[2];
	float fVec6[1024];
	float fRec248[2];
	float fRec246[2];
	float fRec245[2];
	float fRec243[2];
	float fRec242[2];
	float fRec240[2];
	float fRec239[2];
	float fRec237[2];
	float fRec257[2];
	float fRec255[2];
	float fRec254[2];
	float fRec252[2];
	float fRec251[2];
	float fRec249[2];
	float fRec260[2];
	float fRec258[2];
	float fRec266[2];
	float fRec264[2];
	float fRec263[2];
	float fRec261[2];
	float fVec7[1024];
	float fRec278[2];
	float fRec276[2];
	float fRec275[2];
	float fRec273[2];
	float fRec272[2];
	float fRec270[2];
	float fRec269[2];
	float fRec267[2];
	float fRec287[2];
	float fRec285[2];
	float fRec284[2];
	float fRec282[2];
	float fRec281[2];
	float fRec279[2];
	float fRec290[2];
	float fRec288[2];
	float fRec296[2];
	float fRec294[2];
	float fRec293[2];
	float fRec291[2];
	float fVec8[1024];
	float fRec308[2];
	float fRec306[2];
	float fRec305[2];
	float fRec303[2];
	float fRec302[2];
	float fRec300[2];
	float fRec299[2];
	float fRec297[2];
	float fRec317[2];
	float fRec315[2];
	float fRec314[2];
	float fRec312[2];
	float fRec311[2];
	float fRec309[2];
	float fRec320[2];
	float fRec318[2];
	float fRec326[2];
	float fRec324[2];
	float fRec323[2];
	float fRec321[2];
	float fVec9[1024];
	float fRec338[2];
	float fRec336[2];
	float fRec335[2];
	float fRec333[2];
	float fRec332[2];
	float fRec330[2];
	float fRec329[2];
	float fRec327[2];
	float fRec347[2];
	float fRec345[2];
	float fRec344[2];
	float fRec342[2];
	float fRec341[2];
	float fRec339[2];
	float fRec350[2];
	float fRec348[2];
	float fRec356[2];
	float fRec354[2];
	float fRec353[2];
	float fRec351[2];
	float fVec10[1024];
	float fRec368[2];
	float fRec366[2];
	float fRec365[2];
	float fRec363[2];
	float fRec362[2];
	float fRec360[2];
	float fRec359[2];
	float fRec357[2];
	float fRec377[2];
	float fRec375[2];
	float fRec374[2];
	float fRec372[2];
	float fRec371[2];
	float fRec369[2];
	float fRec380[2];
	float fRec378[2];
	float fRec386[2];
	float fRec384[2];
	float fRec383[2];
	float fRec381[2];
	float fVec11[1024];
	float fRec398[2];
	float fRec396[2];
	float fRec395[2];
	float fRec393[2];
	float fRec392[2];
	float fRec390[2];
	float fRec389[2];
	float fRec387[2];
	float fRec407[2];
	float fRec405[2];
	float fRec404[2];
	float fRec402[2];
	float fRec401[2];
	float fRec399[2];
	float fRec410[2];
	float fRec408[2];
	float fRec416[2];
	float fRec414[2];
	float fRec413[2];
	float fRec411[2];
	float fVec12[1024];
	float fRec428[2];
	float fRec426[2];
	float fRec425[2];
	float fRec423[2];
	float fRec422[2];
	float fRec420[2];
	float fRec419[2];
	float fRec417[2];
	float fRec437[2];
	float fRec435[2];
	float fRec434[2];
	float fRec432[2];
	float fRec431[2];
	float fRec429[2];
	float fRec440[2];
	float fRec438[2];
	float fRec446[2];
	float fRec444[2];
	float fRec443[2];
	float fRec441[2];
	float fVec13[1024];
	float fRec458[2];
	float fRec456[2];
	float fRec455[2];
	float fRec453[2];
	float fRec452[2];
	float fRec450[2];
	float fRec449[2];
	float fRec447[2];
	float fRec467[2];
	float fRec465[2];
	float fRec464[2];
	float fRec462[2];
	float fRec461[2];
	float fRec459[2];
	float fRec470[2];
	float fRec468[2];
	float fRec476[2];
	float fRec474[2];
	float fRec473[2];
	float fRec471[2];
	float fVec14[1024];
	float fRec488[2];
	float fRec486[2];
	float fRec485[2];
	float fRec483[2];
	float fRec482[2];
	float fRec480[2];
	float fRec479[2];
	float fRec477[2];
	float fRec497[2];
	float fRec495[2];
	float fRec494[2];
	float fRec492[2];
	float fRec491[2];
	float fRec489[2];
	float fRec500[2];
	float fRec498[2];
	float fRec506[2];
	float fRec504[2];
	float fRec503[2];
	float fRec501[2];
	float fVec15[1024];
	float fConst23;
	float fConst24;
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst28;
	float fConst29;
	float fConst30;
	float fRec518[2];
	float fRec516[2];
	float fRec515[2];
	float fRec513[2];
	float fRec512[2];
	float fRec510[2];
	float fRec509[2];
	float fRec507[2];
	float fConst31;
	float fConst32;
	float fConst33;
	float fConst34;
	float fConst35;
	float fRec527[2];
	float fRec525[2];
	float fRec524[2];
	float fRec522[2];
	float fConst36;
	float fRec521[2];
	float fRec519[2];
	float fConst37;
	float fConst38;
	float fRec530[2];
	float fRec528[2];
	float fConst39;
	float fConst40;
	float fConst41;
	float fRec536[2];
	float fRec534[2];
	float fRec533[2];
	float fRec531[2];
	float fVec16[512];
	int iConst42;
	float fRec548[2];
	float fRec546[2];
	float fRec545[2];
	float fRec543[2];
	float fRec542[2];
	float fRec540[2];
	float fRec539[2];
	float fRec537[2];
	float fRec557[2];
	float fRec555[2];
	float fRec554[2];
	float fRec552[2];
	float fRec551[2];
	float fRec549[2];
	float fRec560[2];
	float fRec558[2];
	float fRec566[2];
	float fRec564[2];
	float fRec563[2];
	float fRec561[2];
	float fVec17[512];
	float fRec578[2];
	float fRec576[2];
	float fRec575[2];
	float fRec573[2];
	float fRec572[2];
	float fRec570[2];
	float fRec569[2];
	float fRec567[2];
	float fRec587[2];
	float fRec585[2];
	float fRec584[2];
	float fRec582[2];
	float fRec581[2];
	float fRec579[2];
	float fRec590[2];
	float fRec588[2];
	float fRec596[2];
	float fRec594[2];
	float fRec593[2];
	float fRec591[2];
	float fVec18[512];
	float fRec608[2];
	float fRec606[2];
	float fRec605[2];
	float fRec603[2];
	float fRec602[2];
	float fRec600[2];
	float fRec599[2];
	float fRec597[2];
	float fRec617[2];
	float fRec615[2];
	float fRec614[2];
	float fRec612[2];
	float fRec611[2];
	float fRec609[2];
	float fRec620[2];
	float fRec618[2];
	float fRec626[2];
	float fRec624[2];
	float fRec623[2];
	float fRec621[2];
	float fVec19[512];
	float fRec638[2];
	float fRec636[2];
	float fRec635[2];
	float fRec633[2];
	float fRec632[2];
	float fRec630[2];
	float fRec629[2];
	float fRec627[2];
	float fRec647[2];
	float fRec645[2];
	float fRec644[2];
	float fRec642[2];
	float fRec641[2];
	float fRec639[2];
	float fRec650[2];
	float fRec648[2];
	float fRec656[2];
	float fRec654[2];
	float fRec653[2];
	float fRec651[2];
	float fVec20[512];
	float fRec668[2];
	float fRec666[2];
	float fRec665[2];
	float fRec663[2];
	float fRec662[2];
	float fRec660[2];
	float fRec659[2];
	float fRec657[2];
	float fRec677[2];
	float fRec675[2];
	float fRec674[2];
	float fRec672[2];
	float fRec671[2];
	float fRec669[2];
	float fRec680[2];
	float fRec678[2];
	float fRec686[2];
	float fRec684[2];
	float fRec683[2];
	float fRec681[2];
	float fVec21[512];
	float fRec698[2];
	float fRec696[2];
	float fRec695[2];
	float fRec693[2];
	float fRec692[2];
	float fRec690[2];
	float fRec689[2];
	float fRec687[2];
	float fRec707[2];
	float fRec705[2];
	float fRec704[2];
	float fRec702[2];
	float fRec701[2];
	float fRec699[2];
	float fRec710[2];
	float fRec708[2];
	float fRec716[2];
	float fRec714[2];
	float fRec713[2];
	float fRec711[2];
	float fVec22[512];
	float fRec728[2];
	float fRec726[2];
	float fRec725[2];
	float fRec723[2];
	float fRec722[2];
	float fRec720[2];
	float fRec719[2];
	float fRec717[2];
	float fRec737[2];
	float fRec735[2];
	float fRec734[2];
	float fRec732[2];
	float fRec731[2];
	float fRec729[2];
	float fRec740[2];
	float fRec738[2];
	float fRec746[2];
	float fRec744[2];
	float fRec743[2];
	float fRec741[2];
	float fVec23[512];
	float fConst43;
	float fConst44;
	float fConst45;
	float fConst46;
	float fConst47;
	float fConst48;
	float fConst49;
	float fConst50;
	float fRec758[2];
	float fRec756[2];
	float fRec755[2];
	float fRec753[2];
	float fRec752[2];
	float fRec750[2];
	float fRec749[2];
	float fRec747[2];
	float fConst51;
	float fConst52;
	float fConst53;
	float fConst54;
	float fConst55;
	float fRec767[2];
	float fRec765[2];
	float fRec764[2];
	float fRec762[2];
	float fConst56;
	float fRec761[2];
	float fRec759[2];
	float fConst57;
	float fConst58;
	float fRec770[2];
	float fRec768[2];
	float fConst59;
	float fConst60;
	float fConst61;
	float fRec776[2];
	float fRec774[2];
	float fRec773[2];
	float fRec771[2];
	float fVec24[256];
	int iConst62;
	float fRec788[2];
	float fRec786[2];
	float fRec785[2];
	float fRec783[2];
	float fRec782[2];
	float fRec780[2];
	float fRec779[2];
	float fRec777[2];
	float fRec797[2];
	float fRec795[2];
	float fRec794[2];
	float fRec792[2];
	float fRec791[2];
	float fRec789[2];
	float fRec800[2];
	float fRec798[2];
	float fRec806[2];
	float fRec804[2];
	float fRec803[2];
	float fRec801[2];
	float fVec25[256];
	float fRec818[2];
	float fRec816[2];
	float fRec815[2];
	float fRec813[2];
	float fRec812[2];
	float fRec810[2];
	float fRec809[2];
	float fRec807[2];
	float fRec827[2];
	float fRec825[2];
	float fRec824[2];
	float fRec822[2];
	float fRec821[2];
	float fRec819[2];
	float fRec830[2];
	float fRec828[2];
	float fRec836[2];
	float fRec834[2];
	float fRec833[2];
	float fRec831[2];
	float fVec26[256];
	float fRec848[2];
	float fRec846[2];
	float fRec845[2];
	float fRec843[2];
	float fRec842[2];
	float fRec840[2];
	float fRec839[2];
	float fRec837[2];
	float fRec857[2];
	float fRec855[2];
	float fRec854[2];
	float fRec852[2];
	float fRec851[2];
	float fRec849[2];
	float fRec860[2];
	float fRec858[2];
	float fRec866[2];
	float fRec864[2];
	float fRec863[2];
	float fRec861[2];
	float fVec27[256];
	float fConst63;
	float fConst64;
	float fConst65;
	float fConst66;
	float fConst67;
	float fConst68;
	float fConst69;
	float fConst70;
	float fRec878[2];
	float fRec876[2];
	float fRec875[2];
	float fRec873[2];
	float fRec872[2];
	float fRec870[2];
	float fRec869[2];
	float fRec867[2];
	float fConst71;
	float fConst72;
	float fConst73;
	float fConst74;
	float fConst75;
	float fRec887[2];
	float fRec885[2];
	float fRec884[2];
	float fRec882[2];
	float fConst76;
	float fRec881[2];
	float fRec879[2];
	float fConst77;
	float fConst78;
	float fRec890[2];
	float fRec888[2];
	float fConst79;
	float fConst80;
	float fConst81;
	float fRec896[2];
	float fRec894[2];
	float fRec893[2];
	float fRec891[2];
	float fRec908[2];
	float fRec906[2];
	float fRec905[2];
	float fRec903[2];
	float fRec902[2];
	float fRec900[2];
	float fRec899[2];
	float fRec897[2];
	float fRec917[2];
	float fRec915[2];
	float fRec914[2];
	float fRec912[2];
	float fRec911[2];
	float fRec909[2];
	float fRec920[2];
	float fRec918[2];
	float fRec926[2];
	float fRec924[2];
	float fRec923[2];
	float fRec921[2];
	float fVec28[1024];
	float fRec938[2];
	float fRec936[2];
	float fRec935[2];
	float fRec933[2];
	float fRec932[2];
	float fRec930[2];
	float fRec929[2];
	float fRec927[2];
	float fRec947[2];
	float fRec945[2];
	float fRec944[2];
	float fRec942[2];
	float fRec941[2];
	float fRec939[2];
	float fRec950[2];
	float fRec948[2];
	float fRec956[2];
	float fRec954[2];
	float fRec953[2];
	float fRec951[2];
	float fVec29[1024];
	float fRec968[2];
	float fRec966[2];
	float fRec965[2];
	float fRec963[2];
	float fRec962[2];
	float fRec960[2];
	float fRec959[2];
	float fRec957[2];
	float fRec977[2];
	float fRec975[2];
	float fRec974[2];
	float fRec972[2];
	float fRec971[2];
	float fRec969[2];
	float fRec980[2];
	float fRec978[2];
	float fRec986[2];
	float fRec984[2];
	float fRec983[2];
	float fRec981[2];
	float fVec30[1024];
	float fRec998[2];
	float fRec996[2];
	float fRec995[2];
	float fRec993[2];
	float fRec992[2];
	float fRec990[2];
	float fRec989[2];
	float fRec987[2];
	float fRec1007[2];
	float fRec1005[2];
	float fRec1004[2];
	float fRec1002[2];
	float fRec1001[2];
	float fRec999[2];
	float fRec1010[2];
	float fRec1008[2];
	float fRec1016[2];
	float fRec1014[2];
	float fRec1013[2];
	float fRec1011[2];
	float fVec31[1024];
	float fRec1028[2];
	float fRec1026[2];
	float fRec1025[2];
	float fRec1023[2];
	float fRec1022[2];
	float fRec1020[2];
	float fRec1019[2];
	float fRec1017[2];
	float fRec1037[2];
	float fRec1035[2];
	float fRec1034[2];
	float fRec1032[2];
	float fRec1031[2];
	float fRec1029[2];
	float fRec1040[2];
	float fRec1038[2];
	float fRec1046[2];
	float fRec1044[2];
	float fRec1043[2];
	float fRec1041[2];
	float fVec32[1024];
	float fRec1058[2];
	float fRec1056[2];
	float fRec1055[2];
	float fRec1053[2];
	float fRec1052[2];
	float fRec1050[2];
	float fRec1049[2];
	float fRec1047[2];
	float fRec1067[2];
	float fRec1065[2];
	float fRec1064[2];
	float fRec1062[2];
	float fRec1061[2];
	float fRec1059[2];
	float fRec1070[2];
	float fRec1068[2];
	float fRec1076[2];
	float fRec1074[2];
	float fRec1073[2];
	float fRec1071[2];
	float fVec33[1024];
	float fRec1088[2];
	float fRec1086[2];
	float fRec1085[2];
	float fRec1083[2];
	float fRec1082[2];
	float fRec1080[2];
	float fRec1079[2];
	float fRec1077[2];
	float fRec1097[2];
	float fRec1095[2];
	float fRec1094[2];
	float fRec1092[2];
	float fRec1091[2];
	float fRec1089[2];
	float fRec1100[2];
	float fRec1098[2];
	float fRec1106[2];
	float fRec1104[2];
	float fRec1103[2];
	float fRec1101[2];
	float fVec34[1024];
	float fRec1118[2];
	float fRec1116[2];
	float fRec1115[2];
	float fRec1113[2];
	float fRec1112[2];
	float fRec1110[2];
	float fRec1109[2];
	float fRec1107[2];
	float fRec1127[2];
	float fRec1125[2];
	float fRec1124[2];
	float fRec1122[2];
	float fRec1121[2];
	float fRec1119[2];
	float fRec1130[2];
	float fRec1128[2];
	float fRec1136[2];
	float fRec1134[2];
	float fRec1133[2];
	float fRec1131[2];
	float fVec35[1024];
	float fRec1148[2];
	float fRec1146[2];
	float fRec1145[2];
	float fRec1143[2];
	float fRec1142[2];
	float fRec1140[2];
	float fRec1139[2];
	float fRec1137[2];
	float fRec1157[2];
	float fRec1155[2];
	float fRec1154[2];
	float fRec1152[2];
	float fRec1151[2];
	float fRec1149[2];
	float fRec1160[2];
	float fRec1158[2];
	float fRec1166[2];
	float fRec1164[2];
	float fRec1163[2];
	float fRec1161[2];
	float fVec36[1024];
	float fRec1178[2];
	float fRec1176[2];
	float fRec1175[2];
	float fRec1173[2];
	float fRec1172[2];
	float fRec1170[2];
	float fRec1169[2];
	float fRec1167[2];
	float fRec1187[2];
	float fRec1185[2];
	float fRec1184[2];
	float fRec1182[2];
	float fRec1181[2];
	float fRec1179[2];
	float fRec1190[2];
	float fRec1188[2];
	float fRec1196[2];
	float fRec1194[2];
	float fRec1193[2];
	float fRec1191[2];
	float fVec37[1024];
	float fRec1208[2];
	float fRec1206[2];
	float fRec1205[2];
	float fRec1203[2];
	float fRec1202[2];
	float fRec1200[2];
	float fRec1199[2];
	float fRec1197[2];
	float fRec1217[2];
	float fRec1215[2];
	float fRec1214[2];
	float fRec1212[2];
	float fRec1211[2];
	float fRec1209[2];
	float fRec1220[2];
	float fRec1218[2];
	float fRec1226[2];
	float fRec1224[2];
	float fRec1223[2];
	float fRec1221[2];
	float fVec38[1024];
	float fRec1238[2];
	float fRec1236[2];
	float fRec1235[2];
	float fRec1233[2];
	float fRec1232[2];
	float fRec1230[2];
	float fRec1229[2];
	float fRec1227[2];
	float fRec1247[2];
	float fRec1245[2];
	float fRec1244[2];
	float fRec1242[2];
	float fRec1241[2];
	float fRec1239[2];
	float fRec1250[2];
	float fRec1248[2];
	float fRec1256[2];
	float fRec1254[2];
	float fRec1253[2];
	float fRec1251[2];
	float fVec39[1024];
	float fRec1268[2];
	float fRec1266[2];
	float fRec1265[2];
	float fRec1263[2];
	float fRec1262[2];
	float fRec1260[2];
	float fRec1259[2];
	float fRec1257[2];
	float fRec1277[2];
	float fRec1275[2];
	float fRec1274[2];
	float fRec1272[2];
	float fRec1271[2];
	float fRec1269[2];
	float fRec1280[2];
	float fRec1278[2];
	float fRec1286[2];
	float fRec1284[2];
	float fRec1283[2];
	float fRec1281[2];
	float fVec40[1024];
	float fRec1298[2];
	float fRec1296[2];
	float fRec1295[2];
	float fRec1293[2];
	float fRec1292[2];
	float fRec1290[2];
	float fRec1289[2];
	float fRec1287[2];
	float fRec1307[2];
	float fRec1305[2];
	float fRec1304[2];
	float fRec1302[2];
	float fRec1301[2];
	float fRec1299[2];
	float fRec1310[2];
	float fRec1308[2];
	float fRec1316[2];
	float fRec1314[2];
	float fRec1313[2];
	float fRec1311[2];
	float fVec41[1024];
	float fRec1328[2];
	float fRec1326[2];
	float fRec1325[2];
	float fRec1323[2];
	float fRec1322[2];
	float fRec1320[2];
	float fRec1319[2];
	float fRec1317[2];
	float fRec1337[2];
	float fRec1335[2];
	float fRec1334[2];
	float fRec1332[2];
	float fRec1331[2];
	float fRec1329[2];
	float fRec1340[2];
	float fRec1338[2];
	float fRec1346[2];
	float fRec1344[2];
	float fRec1343[2];
	float fRec1341[2];
	float fVec42[1024];
	float fRec1358[2];
	float fRec1356[2];
	float fRec1355[2];
	float fRec1353[2];
	float fRec1352[2];
	float fRec1350[2];
	float fRec1349[2];
	float fRec1347[2];
	float fRec1367[2];
	float fRec1365[2];
	float fRec1364[2];
	float fRec1362[2];
	float fRec1361[2];
	float fRec1359[2];
	float fRec1370[2];
	float fRec1368[2];
	float fRec1376[2];
	float fRec1374[2];
	float fRec1373[2];
	float fRec1371[2];
	float fVec43[1024];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit, Henrik Frisk");
		m->declare("compile_options", "-lang cpp -es 1 -scal -ftz 0");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMHLS_FullSetup_4h3v_full_1.dsp");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMHLS_FullSetup_4h3v_full_1");
		m->declare("version", "1.2");
	}

	virtual int getNumInputs() {
		return 25;
	}
	virtual int getNumOutputs() {
		return 45;
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch ((channel)) {
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
				rate = 0;
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
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch ((channel)) {
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
		fConst2 = ((((12665.4941f / fConst0) + 215.622955f) / fConst0) + 1.0f);
		fConst3 = (1.0f / (fConst0 * fConst2));
		fConst4 = (50661.9766f / fConst0);
		fConst5 = (fConst4 + 431.245911f);
		fConst6 = (1.0f / ((((15918.6641f / fConst0) + 156.627182f) / fConst0) + 1.0f));
		fConst7 = (1.0f / fConst0);
		fConst8 = (63674.6562f / fConst0);
		fConst9 = (fConst8 + 313.254364f);
		fConst10 = (1.0f / fConst2);
		fConst11 = (1.0f / ((((8950.84668f / fConst0) + 136.906693f) / fConst0) + 1.0f));
		fConst12 = (35803.3867f / fConst0);
		fConst13 = (fConst12 + 273.813385f);
		fConst14 = ((86.4433823f / fConst0) + 1.0f);
		fConst15 = (1.0f / fConst14);
		fConst16 = (172.886765f / (fConst0 * fConst14));
		fConst17 = (1.0f / ((37.2250137f / fConst0) + 1.0f));
		fConst18 = (74.4500275f / fConst0);
		fConst19 = (1.0f / ((((4157.10498f / fConst0) + 111.675041f) / fConst0) + 1.0f));
		fConst20 = (16628.4199f / fConst0);
		fConst21 = (fConst20 + 223.350082f);
		iConst22 = int(((0.00281456532f * fConst0) + 0.5f));
		fConst23 = ((((11293.4971f / fConst0) + 203.609558f) / fConst0) + 1.0f);
		fConst24 = (1.0f / (fConst0 * fConst23));
		fConst25 = (45173.9883f / fConst0);
		fConst26 = (fConst25 + 407.219116f);
		fConst27 = (1.0f / ((((14194.2646f / fConst0) + 147.900711f) / fConst0) + 1.0f));
		fConst28 = (56777.0586f / fConst0);
		fConst29 = (fConst28 + 295.801422f);
		fConst30 = (1.0f / fConst23);
		fConst31 = (1.0f / ((((7981.24072f / fConst0) + 129.278961f) / fConst0) + 1.0f));
		fConst32 = (31924.9629f / fConst0);
		fConst33 = (fConst32 + 258.557922f);
		fConst34 = ((81.6271973f / fConst0) + 1.0f);
		fConst35 = (1.0f / fConst34);
		fConst36 = (163.254395f / (fConst0 * fConst34));
		fConst37 = (1.0f / ((35.1510277f / fConst0) + 1.0f));
		fConst38 = (70.3020554f / fConst0);
		fConst39 = (1.0f / ((((3706.78394f / fConst0) + 105.453079f) / fConst0) + 1.0f));
		fConst40 = (14827.1357f / fConst0);
		fConst41 = (fConst40 + 210.906158f);
		iConst42 = int(((0.00202205847f * fConst0) + 0.5f));
		fConst43 = ((((9521.17773f / fConst0) + 186.95163f) / fConst0) + 1.0f);
		fConst44 = (1.0f / (fConst0 * fConst43));
		fConst45 = (38084.7109f / fConst0);
		fConst46 = (fConst45 + 373.903259f);
		fConst47 = (1.0f / ((((11966.7207f / fConst0) + 135.800507f) / fConst0) + 1.0f));
		fConst48 = (47866.8828f / fConst0);
		fConst49 = (fConst48 + 271.601013f);
		fConst50 = (1.0f / fConst43);
		fConst51 = (1.0f / ((((6728.72266f / fConst0) + 118.702255f) / fConst0) + 1.0f));
		fConst52 = (26914.8906f / fConst0);
		fConst53 = (fConst52 + 237.40451f);
		fConst54 = ((74.949028f / fConst0) + 1.0f);
		fConst55 = (1.0f / fConst54);
		fConst56 = (149.898056f / (fConst0 * fConst54));
		fConst57 = (1.0f / ((32.2752151f / fConst0) + 1.0f));
		fConst58 = (64.5504303f / fConst0);
		fConst59 = (1.0f / ((((3125.06836f / fConst0) + 96.8256378f) / fConst0) + 1.0f));
		fConst60 = (12500.2734f / fConst0);
		fConst61 = (fConst60 + 193.651276f);
		iConst62 = int(((0.000754629844f * fConst0) + 0.5f));
		fConst63 = ((((8657.21973f / fConst0) + 178.267899f) / fConst0) + 1.0f);
		fConst64 = (1.0f / (fConst0 * fConst63));
		fConst65 = (34628.8789f / fConst0);
		fConst66 = (fConst65 + 356.535797f);
		fConst67 = (1.0f / ((((10880.8525f / fConst0) + 129.492691f) / fConst0) + 1.0f));
		fConst68 = (43523.4102f / fConst0);
		fConst69 = (fConst68 + 258.985382f);
		fConst70 = (1.0f / fConst63);
		fConst71 = (1.0f / ((((6118.1543f / fConst0) + 113.188644f) / fConst0) + 1.0f));
		fConst72 = (24472.6172f / fConst0);
		fConst73 = (fConst72 + 226.377289f);
		fConst74 = ((71.4677124f / fConst0) + 1.0f);
		fConst75 = (1.0f / fConst74);
		fConst76 = (142.935425f / (fConst0 * fConst74));
		fConst77 = (1.0f / ((30.7760601f / fConst0) + 1.0f));
		fConst78 = (61.5521202f / fConst0);
		fConst79 = (1.0f / ((((2841.49756f / fConst0) + 92.3281784f) / fConst0) + 1.0f));
		fConst80 = (11365.9902f / fConst0);
		fConst81 = (fConst80 + 184.656357f);
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
			fRec16[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec17[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec18[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec19[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec20[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec21[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec22[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec23[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec15[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec13[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec12[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec10[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec9[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec7[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec6[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec4[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec33[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec34[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec35[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec36[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 3); l24 = (l24 + 1)) {
			fRec37[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec38[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec39[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec32[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec30[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec29[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec27[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec26[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec24[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 3); l33 = (l33 + 1)) {
			fRec43[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec44[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 3); l35 = (l35 + 1)) {
			fRec45[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec42[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec40[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec52[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 3); l39 = (l39 + 1)) {
			fRec53[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 3); l40 = (l40 + 1)) {
			fRec54[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 3); l41 = (l41 + 1)) {
			fRec55[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec56[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec51[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec49[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec48[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec46[l46] = 0.0f;
		}
		IOTA = 0;
		for (int l47 = 0; (l47 < 1024); l47 = (l47 + 1)) {
			fVec0[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec68[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec66[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec65[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec63[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec62[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fRec60[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec59[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec57[l55] = 0.0f;
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fRec77[l56] = 0.0f;
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fRec75[l57] = 0.0f;
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec74[l58] = 0.0f;
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec72[l59] = 0.0f;
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			fRec71[l60] = 0.0f;
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec69[l61] = 0.0f;
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec80[l62] = 0.0f;
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec78[l63] = 0.0f;
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec86[l64] = 0.0f;
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec84[l65] = 0.0f;
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec83[l66] = 0.0f;
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec81[l67] = 0.0f;
		}
		for (int l68 = 0; (l68 < 1024); l68 = (l68 + 1)) {
			fVec1[l68] = 0.0f;
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec98[l69] = 0.0f;
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec96[l70] = 0.0f;
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec95[l71] = 0.0f;
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec93[l72] = 0.0f;
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec92[l73] = 0.0f;
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec90[l74] = 0.0f;
		}
		for (int l75 = 0; (l75 < 2); l75 = (l75 + 1)) {
			fRec89[l75] = 0.0f;
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec87[l76] = 0.0f;
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec107[l77] = 0.0f;
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec105[l78] = 0.0f;
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fRec104[l79] = 0.0f;
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec102[l80] = 0.0f;
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec101[l81] = 0.0f;
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec99[l82] = 0.0f;
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fRec110[l83] = 0.0f;
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec108[l84] = 0.0f;
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec116[l85] = 0.0f;
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec114[l86] = 0.0f;
		}
		for (int l87 = 0; (l87 < 2); l87 = (l87 + 1)) {
			fRec113[l87] = 0.0f;
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			fRec111[l88] = 0.0f;
		}
		for (int l89 = 0; (l89 < 1024); l89 = (l89 + 1)) {
			fVec2[l89] = 0.0f;
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec128[l90] = 0.0f;
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec126[l91] = 0.0f;
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec125[l92] = 0.0f;
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec123[l93] = 0.0f;
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec122[l94] = 0.0f;
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec120[l95] = 0.0f;
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fRec119[l96] = 0.0f;
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec117[l97] = 0.0f;
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec137[l98] = 0.0f;
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec135[l99] = 0.0f;
		}
		for (int l100 = 0; (l100 < 2); l100 = (l100 + 1)) {
			fRec134[l100] = 0.0f;
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fRec132[l101] = 0.0f;
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec131[l102] = 0.0f;
		}
		for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) {
			fRec129[l103] = 0.0f;
		}
		for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) {
			fRec140[l104] = 0.0f;
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fRec138[l105] = 0.0f;
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec146[l106] = 0.0f;
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fRec144[l107] = 0.0f;
		}
		for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) {
			fRec143[l108] = 0.0f;
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec141[l109] = 0.0f;
		}
		for (int l110 = 0; (l110 < 1024); l110 = (l110 + 1)) {
			fVec3[l110] = 0.0f;
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec158[l111] = 0.0f;
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec156[l112] = 0.0f;
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec155[l113] = 0.0f;
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec153[l114] = 0.0f;
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec152[l115] = 0.0f;
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec150[l116] = 0.0f;
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec149[l117] = 0.0f;
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec147[l118] = 0.0f;
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec167[l119] = 0.0f;
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec165[l120] = 0.0f;
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec164[l121] = 0.0f;
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec162[l122] = 0.0f;
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec161[l123] = 0.0f;
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec159[l124] = 0.0f;
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fRec170[l125] = 0.0f;
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec168[l126] = 0.0f;
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec176[l127] = 0.0f;
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec174[l128] = 0.0f;
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec173[l129] = 0.0f;
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec171[l130] = 0.0f;
		}
		for (int l131 = 0; (l131 < 1024); l131 = (l131 + 1)) {
			fVec4[l131] = 0.0f;
		}
		for (int l132 = 0; (l132 < 2); l132 = (l132 + 1)) {
			fRec188[l132] = 0.0f;
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec186[l133] = 0.0f;
		}
		for (int l134 = 0; (l134 < 2); l134 = (l134 + 1)) {
			fRec185[l134] = 0.0f;
		}
		for (int l135 = 0; (l135 < 2); l135 = (l135 + 1)) {
			fRec183[l135] = 0.0f;
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec182[l136] = 0.0f;
		}
		for (int l137 = 0; (l137 < 2); l137 = (l137 + 1)) {
			fRec180[l137] = 0.0f;
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec179[l138] = 0.0f;
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fRec177[l139] = 0.0f;
		}
		for (int l140 = 0; (l140 < 2); l140 = (l140 + 1)) {
			fRec197[l140] = 0.0f;
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fRec195[l141] = 0.0f;
		}
		for (int l142 = 0; (l142 < 2); l142 = (l142 + 1)) {
			fRec194[l142] = 0.0f;
		}
		for (int l143 = 0; (l143 < 2); l143 = (l143 + 1)) {
			fRec192[l143] = 0.0f;
		}
		for (int l144 = 0; (l144 < 2); l144 = (l144 + 1)) {
			fRec191[l144] = 0.0f;
		}
		for (int l145 = 0; (l145 < 2); l145 = (l145 + 1)) {
			fRec189[l145] = 0.0f;
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fRec200[l146] = 0.0f;
		}
		for (int l147 = 0; (l147 < 2); l147 = (l147 + 1)) {
			fRec198[l147] = 0.0f;
		}
		for (int l148 = 0; (l148 < 2); l148 = (l148 + 1)) {
			fRec206[l148] = 0.0f;
		}
		for (int l149 = 0; (l149 < 2); l149 = (l149 + 1)) {
			fRec204[l149] = 0.0f;
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec203[l150] = 0.0f;
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec201[l151] = 0.0f;
		}
		for (int l152 = 0; (l152 < 1024); l152 = (l152 + 1)) {
			fVec5[l152] = 0.0f;
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec218[l153] = 0.0f;
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec216[l154] = 0.0f;
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec215[l155] = 0.0f;
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec213[l156] = 0.0f;
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec212[l157] = 0.0f;
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec210[l158] = 0.0f;
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec209[l159] = 0.0f;
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec207[l160] = 0.0f;
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec227[l161] = 0.0f;
		}
		for (int l162 = 0; (l162 < 2); l162 = (l162 + 1)) {
			fRec225[l162] = 0.0f;
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			fRec224[l163] = 0.0f;
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			fRec222[l164] = 0.0f;
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec221[l165] = 0.0f;
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec219[l166] = 0.0f;
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fRec230[l167] = 0.0f;
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec228[l168] = 0.0f;
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec236[l169] = 0.0f;
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec234[l170] = 0.0f;
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fRec233[l171] = 0.0f;
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec231[l172] = 0.0f;
		}
		for (int l173 = 0; (l173 < 1024); l173 = (l173 + 1)) {
			fVec6[l173] = 0.0f;
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec248[l174] = 0.0f;
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec246[l175] = 0.0f;
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec245[l176] = 0.0f;
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec243[l177] = 0.0f;
		}
		for (int l178 = 0; (l178 < 2); l178 = (l178 + 1)) {
			fRec242[l178] = 0.0f;
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec240[l179] = 0.0f;
		}
		for (int l180 = 0; (l180 < 2); l180 = (l180 + 1)) {
			fRec239[l180] = 0.0f;
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec237[l181] = 0.0f;
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec257[l182] = 0.0f;
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fRec255[l183] = 0.0f;
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec254[l184] = 0.0f;
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec252[l185] = 0.0f;
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fRec251[l186] = 0.0f;
		}
		for (int l187 = 0; (l187 < 2); l187 = (l187 + 1)) {
			fRec249[l187] = 0.0f;
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec260[l188] = 0.0f;
		}
		for (int l189 = 0; (l189 < 2); l189 = (l189 + 1)) {
			fRec258[l189] = 0.0f;
		}
		for (int l190 = 0; (l190 < 2); l190 = (l190 + 1)) {
			fRec266[l190] = 0.0f;
		}
		for (int l191 = 0; (l191 < 2); l191 = (l191 + 1)) {
			fRec264[l191] = 0.0f;
		}
		for (int l192 = 0; (l192 < 2); l192 = (l192 + 1)) {
			fRec263[l192] = 0.0f;
		}
		for (int l193 = 0; (l193 < 2); l193 = (l193 + 1)) {
			fRec261[l193] = 0.0f;
		}
		for (int l194 = 0; (l194 < 1024); l194 = (l194 + 1)) {
			fVec7[l194] = 0.0f;
		}
		for (int l195 = 0; (l195 < 2); l195 = (l195 + 1)) {
			fRec278[l195] = 0.0f;
		}
		for (int l196 = 0; (l196 < 2); l196 = (l196 + 1)) {
			fRec276[l196] = 0.0f;
		}
		for (int l197 = 0; (l197 < 2); l197 = (l197 + 1)) {
			fRec275[l197] = 0.0f;
		}
		for (int l198 = 0; (l198 < 2); l198 = (l198 + 1)) {
			fRec273[l198] = 0.0f;
		}
		for (int l199 = 0; (l199 < 2); l199 = (l199 + 1)) {
			fRec272[l199] = 0.0f;
		}
		for (int l200 = 0; (l200 < 2); l200 = (l200 + 1)) {
			fRec270[l200] = 0.0f;
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fRec269[l201] = 0.0f;
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec267[l202] = 0.0f;
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fRec287[l203] = 0.0f;
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec285[l204] = 0.0f;
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec284[l205] = 0.0f;
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec282[l206] = 0.0f;
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec281[l207] = 0.0f;
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec279[l208] = 0.0f;
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec290[l209] = 0.0f;
		}
		for (int l210 = 0; (l210 < 2); l210 = (l210 + 1)) {
			fRec288[l210] = 0.0f;
		}
		for (int l211 = 0; (l211 < 2); l211 = (l211 + 1)) {
			fRec296[l211] = 0.0f;
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec294[l212] = 0.0f;
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec293[l213] = 0.0f;
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fRec291[l214] = 0.0f;
		}
		for (int l215 = 0; (l215 < 1024); l215 = (l215 + 1)) {
			fVec8[l215] = 0.0f;
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fRec308[l216] = 0.0f;
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec306[l217] = 0.0f;
		}
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fRec305[l218] = 0.0f;
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec303[l219] = 0.0f;
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fRec302[l220] = 0.0f;
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec300[l221] = 0.0f;
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec299[l222] = 0.0f;
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec297[l223] = 0.0f;
		}
		for (int l224 = 0; (l224 < 2); l224 = (l224 + 1)) {
			fRec317[l224] = 0.0f;
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec315[l225] = 0.0f;
		}
		for (int l226 = 0; (l226 < 2); l226 = (l226 + 1)) {
			fRec314[l226] = 0.0f;
		}
		for (int l227 = 0; (l227 < 2); l227 = (l227 + 1)) {
			fRec312[l227] = 0.0f;
		}
		for (int l228 = 0; (l228 < 2); l228 = (l228 + 1)) {
			fRec311[l228] = 0.0f;
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fRec309[l229] = 0.0f;
		}
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec320[l230] = 0.0f;
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fRec318[l231] = 0.0f;
		}
		for (int l232 = 0; (l232 < 2); l232 = (l232 + 1)) {
			fRec326[l232] = 0.0f;
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fRec324[l233] = 0.0f;
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec323[l234] = 0.0f;
		}
		for (int l235 = 0; (l235 < 2); l235 = (l235 + 1)) {
			fRec321[l235] = 0.0f;
		}
		for (int l236 = 0; (l236 < 1024); l236 = (l236 + 1)) {
			fVec9[l236] = 0.0f;
		}
		for (int l237 = 0; (l237 < 2); l237 = (l237 + 1)) {
			fRec338[l237] = 0.0f;
		}
		for (int l238 = 0; (l238 < 2); l238 = (l238 + 1)) {
			fRec336[l238] = 0.0f;
		}
		for (int l239 = 0; (l239 < 2); l239 = (l239 + 1)) {
			fRec335[l239] = 0.0f;
		}
		for (int l240 = 0; (l240 < 2); l240 = (l240 + 1)) {
			fRec333[l240] = 0.0f;
		}
		for (int l241 = 0; (l241 < 2); l241 = (l241 + 1)) {
			fRec332[l241] = 0.0f;
		}
		for (int l242 = 0; (l242 < 2); l242 = (l242 + 1)) {
			fRec330[l242] = 0.0f;
		}
		for (int l243 = 0; (l243 < 2); l243 = (l243 + 1)) {
			fRec329[l243] = 0.0f;
		}
		for (int l244 = 0; (l244 < 2); l244 = (l244 + 1)) {
			fRec327[l244] = 0.0f;
		}
		for (int l245 = 0; (l245 < 2); l245 = (l245 + 1)) {
			fRec347[l245] = 0.0f;
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fRec345[l246] = 0.0f;
		}
		for (int l247 = 0; (l247 < 2); l247 = (l247 + 1)) {
			fRec344[l247] = 0.0f;
		}
		for (int l248 = 0; (l248 < 2); l248 = (l248 + 1)) {
			fRec342[l248] = 0.0f;
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fRec341[l249] = 0.0f;
		}
		for (int l250 = 0; (l250 < 2); l250 = (l250 + 1)) {
			fRec339[l250] = 0.0f;
		}
		for (int l251 = 0; (l251 < 2); l251 = (l251 + 1)) {
			fRec350[l251] = 0.0f;
		}
		for (int l252 = 0; (l252 < 2); l252 = (l252 + 1)) {
			fRec348[l252] = 0.0f;
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec356[l253] = 0.0f;
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec354[l254] = 0.0f;
		}
		for (int l255 = 0; (l255 < 2); l255 = (l255 + 1)) {
			fRec353[l255] = 0.0f;
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec351[l256] = 0.0f;
		}
		for (int l257 = 0; (l257 < 1024); l257 = (l257 + 1)) {
			fVec10[l257] = 0.0f;
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec368[l258] = 0.0f;
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec366[l259] = 0.0f;
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec365[l260] = 0.0f;
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec363[l261] = 0.0f;
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec362[l262] = 0.0f;
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec360[l263] = 0.0f;
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec359[l264] = 0.0f;
		}
		for (int l265 = 0; (l265 < 2); l265 = (l265 + 1)) {
			fRec357[l265] = 0.0f;
		}
		for (int l266 = 0; (l266 < 2); l266 = (l266 + 1)) {
			fRec377[l266] = 0.0f;
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec375[l267] = 0.0f;
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec374[l268] = 0.0f;
		}
		for (int l269 = 0; (l269 < 2); l269 = (l269 + 1)) {
			fRec372[l269] = 0.0f;
		}
		for (int l270 = 0; (l270 < 2); l270 = (l270 + 1)) {
			fRec371[l270] = 0.0f;
		}
		for (int l271 = 0; (l271 < 2); l271 = (l271 + 1)) {
			fRec369[l271] = 0.0f;
		}
		for (int l272 = 0; (l272 < 2); l272 = (l272 + 1)) {
			fRec380[l272] = 0.0f;
		}
		for (int l273 = 0; (l273 < 2); l273 = (l273 + 1)) {
			fRec378[l273] = 0.0f;
		}
		for (int l274 = 0; (l274 < 2); l274 = (l274 + 1)) {
			fRec386[l274] = 0.0f;
		}
		for (int l275 = 0; (l275 < 2); l275 = (l275 + 1)) {
			fRec384[l275] = 0.0f;
		}
		for (int l276 = 0; (l276 < 2); l276 = (l276 + 1)) {
			fRec383[l276] = 0.0f;
		}
		for (int l277 = 0; (l277 < 2); l277 = (l277 + 1)) {
			fRec381[l277] = 0.0f;
		}
		for (int l278 = 0; (l278 < 1024); l278 = (l278 + 1)) {
			fVec11[l278] = 0.0f;
		}
		for (int l279 = 0; (l279 < 2); l279 = (l279 + 1)) {
			fRec398[l279] = 0.0f;
		}
		for (int l280 = 0; (l280 < 2); l280 = (l280 + 1)) {
			fRec396[l280] = 0.0f;
		}
		for (int l281 = 0; (l281 < 2); l281 = (l281 + 1)) {
			fRec395[l281] = 0.0f;
		}
		for (int l282 = 0; (l282 < 2); l282 = (l282 + 1)) {
			fRec393[l282] = 0.0f;
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec392[l283] = 0.0f;
		}
		for (int l284 = 0; (l284 < 2); l284 = (l284 + 1)) {
			fRec390[l284] = 0.0f;
		}
		for (int l285 = 0; (l285 < 2); l285 = (l285 + 1)) {
			fRec389[l285] = 0.0f;
		}
		for (int l286 = 0; (l286 < 2); l286 = (l286 + 1)) {
			fRec387[l286] = 0.0f;
		}
		for (int l287 = 0; (l287 < 2); l287 = (l287 + 1)) {
			fRec407[l287] = 0.0f;
		}
		for (int l288 = 0; (l288 < 2); l288 = (l288 + 1)) {
			fRec405[l288] = 0.0f;
		}
		for (int l289 = 0; (l289 < 2); l289 = (l289 + 1)) {
			fRec404[l289] = 0.0f;
		}
		for (int l290 = 0; (l290 < 2); l290 = (l290 + 1)) {
			fRec402[l290] = 0.0f;
		}
		for (int l291 = 0; (l291 < 2); l291 = (l291 + 1)) {
			fRec401[l291] = 0.0f;
		}
		for (int l292 = 0; (l292 < 2); l292 = (l292 + 1)) {
			fRec399[l292] = 0.0f;
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec410[l293] = 0.0f;
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec408[l294] = 0.0f;
		}
		for (int l295 = 0; (l295 < 2); l295 = (l295 + 1)) {
			fRec416[l295] = 0.0f;
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec414[l296] = 0.0f;
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec413[l297] = 0.0f;
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec411[l298] = 0.0f;
		}
		for (int l299 = 0; (l299 < 1024); l299 = (l299 + 1)) {
			fVec12[l299] = 0.0f;
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec428[l300] = 0.0f;
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec426[l301] = 0.0f;
		}
		for (int l302 = 0; (l302 < 2); l302 = (l302 + 1)) {
			fRec425[l302] = 0.0f;
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec423[l303] = 0.0f;
		}
		for (int l304 = 0; (l304 < 2); l304 = (l304 + 1)) {
			fRec422[l304] = 0.0f;
		}
		for (int l305 = 0; (l305 < 2); l305 = (l305 + 1)) {
			fRec420[l305] = 0.0f;
		}
		for (int l306 = 0; (l306 < 2); l306 = (l306 + 1)) {
			fRec419[l306] = 0.0f;
		}
		for (int l307 = 0; (l307 < 2); l307 = (l307 + 1)) {
			fRec417[l307] = 0.0f;
		}
		for (int l308 = 0; (l308 < 2); l308 = (l308 + 1)) {
			fRec437[l308] = 0.0f;
		}
		for (int l309 = 0; (l309 < 2); l309 = (l309 + 1)) {
			fRec435[l309] = 0.0f;
		}
		for (int l310 = 0; (l310 < 2); l310 = (l310 + 1)) {
			fRec434[l310] = 0.0f;
		}
		for (int l311 = 0; (l311 < 2); l311 = (l311 + 1)) {
			fRec432[l311] = 0.0f;
		}
		for (int l312 = 0; (l312 < 2); l312 = (l312 + 1)) {
			fRec431[l312] = 0.0f;
		}
		for (int l313 = 0; (l313 < 2); l313 = (l313 + 1)) {
			fRec429[l313] = 0.0f;
		}
		for (int l314 = 0; (l314 < 2); l314 = (l314 + 1)) {
			fRec440[l314] = 0.0f;
		}
		for (int l315 = 0; (l315 < 2); l315 = (l315 + 1)) {
			fRec438[l315] = 0.0f;
		}
		for (int l316 = 0; (l316 < 2); l316 = (l316 + 1)) {
			fRec446[l316] = 0.0f;
		}
		for (int l317 = 0; (l317 < 2); l317 = (l317 + 1)) {
			fRec444[l317] = 0.0f;
		}
		for (int l318 = 0; (l318 < 2); l318 = (l318 + 1)) {
			fRec443[l318] = 0.0f;
		}
		for (int l319 = 0; (l319 < 2); l319 = (l319 + 1)) {
			fRec441[l319] = 0.0f;
		}
		for (int l320 = 0; (l320 < 1024); l320 = (l320 + 1)) {
			fVec13[l320] = 0.0f;
		}
		for (int l321 = 0; (l321 < 2); l321 = (l321 + 1)) {
			fRec458[l321] = 0.0f;
		}
		for (int l322 = 0; (l322 < 2); l322 = (l322 + 1)) {
			fRec456[l322] = 0.0f;
		}
		for (int l323 = 0; (l323 < 2); l323 = (l323 + 1)) {
			fRec455[l323] = 0.0f;
		}
		for (int l324 = 0; (l324 < 2); l324 = (l324 + 1)) {
			fRec453[l324] = 0.0f;
		}
		for (int l325 = 0; (l325 < 2); l325 = (l325 + 1)) {
			fRec452[l325] = 0.0f;
		}
		for (int l326 = 0; (l326 < 2); l326 = (l326 + 1)) {
			fRec450[l326] = 0.0f;
		}
		for (int l327 = 0; (l327 < 2); l327 = (l327 + 1)) {
			fRec449[l327] = 0.0f;
		}
		for (int l328 = 0; (l328 < 2); l328 = (l328 + 1)) {
			fRec447[l328] = 0.0f;
		}
		for (int l329 = 0; (l329 < 2); l329 = (l329 + 1)) {
			fRec467[l329] = 0.0f;
		}
		for (int l330 = 0; (l330 < 2); l330 = (l330 + 1)) {
			fRec465[l330] = 0.0f;
		}
		for (int l331 = 0; (l331 < 2); l331 = (l331 + 1)) {
			fRec464[l331] = 0.0f;
		}
		for (int l332 = 0; (l332 < 2); l332 = (l332 + 1)) {
			fRec462[l332] = 0.0f;
		}
		for (int l333 = 0; (l333 < 2); l333 = (l333 + 1)) {
			fRec461[l333] = 0.0f;
		}
		for (int l334 = 0; (l334 < 2); l334 = (l334 + 1)) {
			fRec459[l334] = 0.0f;
		}
		for (int l335 = 0; (l335 < 2); l335 = (l335 + 1)) {
			fRec470[l335] = 0.0f;
		}
		for (int l336 = 0; (l336 < 2); l336 = (l336 + 1)) {
			fRec468[l336] = 0.0f;
		}
		for (int l337 = 0; (l337 < 2); l337 = (l337 + 1)) {
			fRec476[l337] = 0.0f;
		}
		for (int l338 = 0; (l338 < 2); l338 = (l338 + 1)) {
			fRec474[l338] = 0.0f;
		}
		for (int l339 = 0; (l339 < 2); l339 = (l339 + 1)) {
			fRec473[l339] = 0.0f;
		}
		for (int l340 = 0; (l340 < 2); l340 = (l340 + 1)) {
			fRec471[l340] = 0.0f;
		}
		for (int l341 = 0; (l341 < 1024); l341 = (l341 + 1)) {
			fVec14[l341] = 0.0f;
		}
		for (int l342 = 0; (l342 < 2); l342 = (l342 + 1)) {
			fRec488[l342] = 0.0f;
		}
		for (int l343 = 0; (l343 < 2); l343 = (l343 + 1)) {
			fRec486[l343] = 0.0f;
		}
		for (int l344 = 0; (l344 < 2); l344 = (l344 + 1)) {
			fRec485[l344] = 0.0f;
		}
		for (int l345 = 0; (l345 < 2); l345 = (l345 + 1)) {
			fRec483[l345] = 0.0f;
		}
		for (int l346 = 0; (l346 < 2); l346 = (l346 + 1)) {
			fRec482[l346] = 0.0f;
		}
		for (int l347 = 0; (l347 < 2); l347 = (l347 + 1)) {
			fRec480[l347] = 0.0f;
		}
		for (int l348 = 0; (l348 < 2); l348 = (l348 + 1)) {
			fRec479[l348] = 0.0f;
		}
		for (int l349 = 0; (l349 < 2); l349 = (l349 + 1)) {
			fRec477[l349] = 0.0f;
		}
		for (int l350 = 0; (l350 < 2); l350 = (l350 + 1)) {
			fRec497[l350] = 0.0f;
		}
		for (int l351 = 0; (l351 < 2); l351 = (l351 + 1)) {
			fRec495[l351] = 0.0f;
		}
		for (int l352 = 0; (l352 < 2); l352 = (l352 + 1)) {
			fRec494[l352] = 0.0f;
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec492[l353] = 0.0f;
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec491[l354] = 0.0f;
		}
		for (int l355 = 0; (l355 < 2); l355 = (l355 + 1)) {
			fRec489[l355] = 0.0f;
		}
		for (int l356 = 0; (l356 < 2); l356 = (l356 + 1)) {
			fRec500[l356] = 0.0f;
		}
		for (int l357 = 0; (l357 < 2); l357 = (l357 + 1)) {
			fRec498[l357] = 0.0f;
		}
		for (int l358 = 0; (l358 < 2); l358 = (l358 + 1)) {
			fRec506[l358] = 0.0f;
		}
		for (int l359 = 0; (l359 < 2); l359 = (l359 + 1)) {
			fRec504[l359] = 0.0f;
		}
		for (int l360 = 0; (l360 < 2); l360 = (l360 + 1)) {
			fRec503[l360] = 0.0f;
		}
		for (int l361 = 0; (l361 < 2); l361 = (l361 + 1)) {
			fRec501[l361] = 0.0f;
		}
		for (int l362 = 0; (l362 < 1024); l362 = (l362 + 1)) {
			fVec15[l362] = 0.0f;
		}
		for (int l363 = 0; (l363 < 2); l363 = (l363 + 1)) {
			fRec518[l363] = 0.0f;
		}
		for (int l364 = 0; (l364 < 2); l364 = (l364 + 1)) {
			fRec516[l364] = 0.0f;
		}
		for (int l365 = 0; (l365 < 2); l365 = (l365 + 1)) {
			fRec515[l365] = 0.0f;
		}
		for (int l366 = 0; (l366 < 2); l366 = (l366 + 1)) {
			fRec513[l366] = 0.0f;
		}
		for (int l367 = 0; (l367 < 2); l367 = (l367 + 1)) {
			fRec512[l367] = 0.0f;
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec510[l368] = 0.0f;
		}
		for (int l369 = 0; (l369 < 2); l369 = (l369 + 1)) {
			fRec509[l369] = 0.0f;
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec507[l370] = 0.0f;
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			fRec527[l371] = 0.0f;
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			fRec525[l372] = 0.0f;
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fRec524[l373] = 0.0f;
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec522[l374] = 0.0f;
		}
		for (int l375 = 0; (l375 < 2); l375 = (l375 + 1)) {
			fRec521[l375] = 0.0f;
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec519[l376] = 0.0f;
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec530[l377] = 0.0f;
		}
		for (int l378 = 0; (l378 < 2); l378 = (l378 + 1)) {
			fRec528[l378] = 0.0f;
		}
		for (int l379 = 0; (l379 < 2); l379 = (l379 + 1)) {
			fRec536[l379] = 0.0f;
		}
		for (int l380 = 0; (l380 < 2); l380 = (l380 + 1)) {
			fRec534[l380] = 0.0f;
		}
		for (int l381 = 0; (l381 < 2); l381 = (l381 + 1)) {
			fRec533[l381] = 0.0f;
		}
		for (int l382 = 0; (l382 < 2); l382 = (l382 + 1)) {
			fRec531[l382] = 0.0f;
		}
		for (int l383 = 0; (l383 < 512); l383 = (l383 + 1)) {
			fVec16[l383] = 0.0f;
		}
		for (int l384 = 0; (l384 < 2); l384 = (l384 + 1)) {
			fRec548[l384] = 0.0f;
		}
		for (int l385 = 0; (l385 < 2); l385 = (l385 + 1)) {
			fRec546[l385] = 0.0f;
		}
		for (int l386 = 0; (l386 < 2); l386 = (l386 + 1)) {
			fRec545[l386] = 0.0f;
		}
		for (int l387 = 0; (l387 < 2); l387 = (l387 + 1)) {
			fRec543[l387] = 0.0f;
		}
		for (int l388 = 0; (l388 < 2); l388 = (l388 + 1)) {
			fRec542[l388] = 0.0f;
		}
		for (int l389 = 0; (l389 < 2); l389 = (l389 + 1)) {
			fRec540[l389] = 0.0f;
		}
		for (int l390 = 0; (l390 < 2); l390 = (l390 + 1)) {
			fRec539[l390] = 0.0f;
		}
		for (int l391 = 0; (l391 < 2); l391 = (l391 + 1)) {
			fRec537[l391] = 0.0f;
		}
		for (int l392 = 0; (l392 < 2); l392 = (l392 + 1)) {
			fRec557[l392] = 0.0f;
		}
		for (int l393 = 0; (l393 < 2); l393 = (l393 + 1)) {
			fRec555[l393] = 0.0f;
		}
		for (int l394 = 0; (l394 < 2); l394 = (l394 + 1)) {
			fRec554[l394] = 0.0f;
		}
		for (int l395 = 0; (l395 < 2); l395 = (l395 + 1)) {
			fRec552[l395] = 0.0f;
		}
		for (int l396 = 0; (l396 < 2); l396 = (l396 + 1)) {
			fRec551[l396] = 0.0f;
		}
		for (int l397 = 0; (l397 < 2); l397 = (l397 + 1)) {
			fRec549[l397] = 0.0f;
		}
		for (int l398 = 0; (l398 < 2); l398 = (l398 + 1)) {
			fRec560[l398] = 0.0f;
		}
		for (int l399 = 0; (l399 < 2); l399 = (l399 + 1)) {
			fRec558[l399] = 0.0f;
		}
		for (int l400 = 0; (l400 < 2); l400 = (l400 + 1)) {
			fRec566[l400] = 0.0f;
		}
		for (int l401 = 0; (l401 < 2); l401 = (l401 + 1)) {
			fRec564[l401] = 0.0f;
		}
		for (int l402 = 0; (l402 < 2); l402 = (l402 + 1)) {
			fRec563[l402] = 0.0f;
		}
		for (int l403 = 0; (l403 < 2); l403 = (l403 + 1)) {
			fRec561[l403] = 0.0f;
		}
		for (int l404 = 0; (l404 < 512); l404 = (l404 + 1)) {
			fVec17[l404] = 0.0f;
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec578[l405] = 0.0f;
		}
		for (int l406 = 0; (l406 < 2); l406 = (l406 + 1)) {
			fRec576[l406] = 0.0f;
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec575[l407] = 0.0f;
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec573[l408] = 0.0f;
		}
		for (int l409 = 0; (l409 < 2); l409 = (l409 + 1)) {
			fRec572[l409] = 0.0f;
		}
		for (int l410 = 0; (l410 < 2); l410 = (l410 + 1)) {
			fRec570[l410] = 0.0f;
		}
		for (int l411 = 0; (l411 < 2); l411 = (l411 + 1)) {
			fRec569[l411] = 0.0f;
		}
		for (int l412 = 0; (l412 < 2); l412 = (l412 + 1)) {
			fRec567[l412] = 0.0f;
		}
		for (int l413 = 0; (l413 < 2); l413 = (l413 + 1)) {
			fRec587[l413] = 0.0f;
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec585[l414] = 0.0f;
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec584[l415] = 0.0f;
		}
		for (int l416 = 0; (l416 < 2); l416 = (l416 + 1)) {
			fRec582[l416] = 0.0f;
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec581[l417] = 0.0f;
		}
		for (int l418 = 0; (l418 < 2); l418 = (l418 + 1)) {
			fRec579[l418] = 0.0f;
		}
		for (int l419 = 0; (l419 < 2); l419 = (l419 + 1)) {
			fRec590[l419] = 0.0f;
		}
		for (int l420 = 0; (l420 < 2); l420 = (l420 + 1)) {
			fRec588[l420] = 0.0f;
		}
		for (int l421 = 0; (l421 < 2); l421 = (l421 + 1)) {
			fRec596[l421] = 0.0f;
		}
		for (int l422 = 0; (l422 < 2); l422 = (l422 + 1)) {
			fRec594[l422] = 0.0f;
		}
		for (int l423 = 0; (l423 < 2); l423 = (l423 + 1)) {
			fRec593[l423] = 0.0f;
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec591[l424] = 0.0f;
		}
		for (int l425 = 0; (l425 < 512); l425 = (l425 + 1)) {
			fVec18[l425] = 0.0f;
		}
		for (int l426 = 0; (l426 < 2); l426 = (l426 + 1)) {
			fRec608[l426] = 0.0f;
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec606[l427] = 0.0f;
		}
		for (int l428 = 0; (l428 < 2); l428 = (l428 + 1)) {
			fRec605[l428] = 0.0f;
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec603[l429] = 0.0f;
		}
		for (int l430 = 0; (l430 < 2); l430 = (l430 + 1)) {
			fRec602[l430] = 0.0f;
		}
		for (int l431 = 0; (l431 < 2); l431 = (l431 + 1)) {
			fRec600[l431] = 0.0f;
		}
		for (int l432 = 0; (l432 < 2); l432 = (l432 + 1)) {
			fRec599[l432] = 0.0f;
		}
		for (int l433 = 0; (l433 < 2); l433 = (l433 + 1)) {
			fRec597[l433] = 0.0f;
		}
		for (int l434 = 0; (l434 < 2); l434 = (l434 + 1)) {
			fRec617[l434] = 0.0f;
		}
		for (int l435 = 0; (l435 < 2); l435 = (l435 + 1)) {
			fRec615[l435] = 0.0f;
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec614[l436] = 0.0f;
		}
		for (int l437 = 0; (l437 < 2); l437 = (l437 + 1)) {
			fRec612[l437] = 0.0f;
		}
		for (int l438 = 0; (l438 < 2); l438 = (l438 + 1)) {
			fRec611[l438] = 0.0f;
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec609[l439] = 0.0f;
		}
		for (int l440 = 0; (l440 < 2); l440 = (l440 + 1)) {
			fRec620[l440] = 0.0f;
		}
		for (int l441 = 0; (l441 < 2); l441 = (l441 + 1)) {
			fRec618[l441] = 0.0f;
		}
		for (int l442 = 0; (l442 < 2); l442 = (l442 + 1)) {
			fRec626[l442] = 0.0f;
		}
		for (int l443 = 0; (l443 < 2); l443 = (l443 + 1)) {
			fRec624[l443] = 0.0f;
		}
		for (int l444 = 0; (l444 < 2); l444 = (l444 + 1)) {
			fRec623[l444] = 0.0f;
		}
		for (int l445 = 0; (l445 < 2); l445 = (l445 + 1)) {
			fRec621[l445] = 0.0f;
		}
		for (int l446 = 0; (l446 < 512); l446 = (l446 + 1)) {
			fVec19[l446] = 0.0f;
		}
		for (int l447 = 0; (l447 < 2); l447 = (l447 + 1)) {
			fRec638[l447] = 0.0f;
		}
		for (int l448 = 0; (l448 < 2); l448 = (l448 + 1)) {
			fRec636[l448] = 0.0f;
		}
		for (int l449 = 0; (l449 < 2); l449 = (l449 + 1)) {
			fRec635[l449] = 0.0f;
		}
		for (int l450 = 0; (l450 < 2); l450 = (l450 + 1)) {
			fRec633[l450] = 0.0f;
		}
		for (int l451 = 0; (l451 < 2); l451 = (l451 + 1)) {
			fRec632[l451] = 0.0f;
		}
		for (int l452 = 0; (l452 < 2); l452 = (l452 + 1)) {
			fRec630[l452] = 0.0f;
		}
		for (int l453 = 0; (l453 < 2); l453 = (l453 + 1)) {
			fRec629[l453] = 0.0f;
		}
		for (int l454 = 0; (l454 < 2); l454 = (l454 + 1)) {
			fRec627[l454] = 0.0f;
		}
		for (int l455 = 0; (l455 < 2); l455 = (l455 + 1)) {
			fRec647[l455] = 0.0f;
		}
		for (int l456 = 0; (l456 < 2); l456 = (l456 + 1)) {
			fRec645[l456] = 0.0f;
		}
		for (int l457 = 0; (l457 < 2); l457 = (l457 + 1)) {
			fRec644[l457] = 0.0f;
		}
		for (int l458 = 0; (l458 < 2); l458 = (l458 + 1)) {
			fRec642[l458] = 0.0f;
		}
		for (int l459 = 0; (l459 < 2); l459 = (l459 + 1)) {
			fRec641[l459] = 0.0f;
		}
		for (int l460 = 0; (l460 < 2); l460 = (l460 + 1)) {
			fRec639[l460] = 0.0f;
		}
		for (int l461 = 0; (l461 < 2); l461 = (l461 + 1)) {
			fRec650[l461] = 0.0f;
		}
		for (int l462 = 0; (l462 < 2); l462 = (l462 + 1)) {
			fRec648[l462] = 0.0f;
		}
		for (int l463 = 0; (l463 < 2); l463 = (l463 + 1)) {
			fRec656[l463] = 0.0f;
		}
		for (int l464 = 0; (l464 < 2); l464 = (l464 + 1)) {
			fRec654[l464] = 0.0f;
		}
		for (int l465 = 0; (l465 < 2); l465 = (l465 + 1)) {
			fRec653[l465] = 0.0f;
		}
		for (int l466 = 0; (l466 < 2); l466 = (l466 + 1)) {
			fRec651[l466] = 0.0f;
		}
		for (int l467 = 0; (l467 < 512); l467 = (l467 + 1)) {
			fVec20[l467] = 0.0f;
		}
		for (int l468 = 0; (l468 < 2); l468 = (l468 + 1)) {
			fRec668[l468] = 0.0f;
		}
		for (int l469 = 0; (l469 < 2); l469 = (l469 + 1)) {
			fRec666[l469] = 0.0f;
		}
		for (int l470 = 0; (l470 < 2); l470 = (l470 + 1)) {
			fRec665[l470] = 0.0f;
		}
		for (int l471 = 0; (l471 < 2); l471 = (l471 + 1)) {
			fRec663[l471] = 0.0f;
		}
		for (int l472 = 0; (l472 < 2); l472 = (l472 + 1)) {
			fRec662[l472] = 0.0f;
		}
		for (int l473 = 0; (l473 < 2); l473 = (l473 + 1)) {
			fRec660[l473] = 0.0f;
		}
		for (int l474 = 0; (l474 < 2); l474 = (l474 + 1)) {
			fRec659[l474] = 0.0f;
		}
		for (int l475 = 0; (l475 < 2); l475 = (l475 + 1)) {
			fRec657[l475] = 0.0f;
		}
		for (int l476 = 0; (l476 < 2); l476 = (l476 + 1)) {
			fRec677[l476] = 0.0f;
		}
		for (int l477 = 0; (l477 < 2); l477 = (l477 + 1)) {
			fRec675[l477] = 0.0f;
		}
		for (int l478 = 0; (l478 < 2); l478 = (l478 + 1)) {
			fRec674[l478] = 0.0f;
		}
		for (int l479 = 0; (l479 < 2); l479 = (l479 + 1)) {
			fRec672[l479] = 0.0f;
		}
		for (int l480 = 0; (l480 < 2); l480 = (l480 + 1)) {
			fRec671[l480] = 0.0f;
		}
		for (int l481 = 0; (l481 < 2); l481 = (l481 + 1)) {
			fRec669[l481] = 0.0f;
		}
		for (int l482 = 0; (l482 < 2); l482 = (l482 + 1)) {
			fRec680[l482] = 0.0f;
		}
		for (int l483 = 0; (l483 < 2); l483 = (l483 + 1)) {
			fRec678[l483] = 0.0f;
		}
		for (int l484 = 0; (l484 < 2); l484 = (l484 + 1)) {
			fRec686[l484] = 0.0f;
		}
		for (int l485 = 0; (l485 < 2); l485 = (l485 + 1)) {
			fRec684[l485] = 0.0f;
		}
		for (int l486 = 0; (l486 < 2); l486 = (l486 + 1)) {
			fRec683[l486] = 0.0f;
		}
		for (int l487 = 0; (l487 < 2); l487 = (l487 + 1)) {
			fRec681[l487] = 0.0f;
		}
		for (int l488 = 0; (l488 < 512); l488 = (l488 + 1)) {
			fVec21[l488] = 0.0f;
		}
		for (int l489 = 0; (l489 < 2); l489 = (l489 + 1)) {
			fRec698[l489] = 0.0f;
		}
		for (int l490 = 0; (l490 < 2); l490 = (l490 + 1)) {
			fRec696[l490] = 0.0f;
		}
		for (int l491 = 0; (l491 < 2); l491 = (l491 + 1)) {
			fRec695[l491] = 0.0f;
		}
		for (int l492 = 0; (l492 < 2); l492 = (l492 + 1)) {
			fRec693[l492] = 0.0f;
		}
		for (int l493 = 0; (l493 < 2); l493 = (l493 + 1)) {
			fRec692[l493] = 0.0f;
		}
		for (int l494 = 0; (l494 < 2); l494 = (l494 + 1)) {
			fRec690[l494] = 0.0f;
		}
		for (int l495 = 0; (l495 < 2); l495 = (l495 + 1)) {
			fRec689[l495] = 0.0f;
		}
		for (int l496 = 0; (l496 < 2); l496 = (l496 + 1)) {
			fRec687[l496] = 0.0f;
		}
		for (int l497 = 0; (l497 < 2); l497 = (l497 + 1)) {
			fRec707[l497] = 0.0f;
		}
		for (int l498 = 0; (l498 < 2); l498 = (l498 + 1)) {
			fRec705[l498] = 0.0f;
		}
		for (int l499 = 0; (l499 < 2); l499 = (l499 + 1)) {
			fRec704[l499] = 0.0f;
		}
		for (int l500 = 0; (l500 < 2); l500 = (l500 + 1)) {
			fRec702[l500] = 0.0f;
		}
		for (int l501 = 0; (l501 < 2); l501 = (l501 + 1)) {
			fRec701[l501] = 0.0f;
		}
		for (int l502 = 0; (l502 < 2); l502 = (l502 + 1)) {
			fRec699[l502] = 0.0f;
		}
		for (int l503 = 0; (l503 < 2); l503 = (l503 + 1)) {
			fRec710[l503] = 0.0f;
		}
		for (int l504 = 0; (l504 < 2); l504 = (l504 + 1)) {
			fRec708[l504] = 0.0f;
		}
		for (int l505 = 0; (l505 < 2); l505 = (l505 + 1)) {
			fRec716[l505] = 0.0f;
		}
		for (int l506 = 0; (l506 < 2); l506 = (l506 + 1)) {
			fRec714[l506] = 0.0f;
		}
		for (int l507 = 0; (l507 < 2); l507 = (l507 + 1)) {
			fRec713[l507] = 0.0f;
		}
		for (int l508 = 0; (l508 < 2); l508 = (l508 + 1)) {
			fRec711[l508] = 0.0f;
		}
		for (int l509 = 0; (l509 < 512); l509 = (l509 + 1)) {
			fVec22[l509] = 0.0f;
		}
		for (int l510 = 0; (l510 < 2); l510 = (l510 + 1)) {
			fRec728[l510] = 0.0f;
		}
		for (int l511 = 0; (l511 < 2); l511 = (l511 + 1)) {
			fRec726[l511] = 0.0f;
		}
		for (int l512 = 0; (l512 < 2); l512 = (l512 + 1)) {
			fRec725[l512] = 0.0f;
		}
		for (int l513 = 0; (l513 < 2); l513 = (l513 + 1)) {
			fRec723[l513] = 0.0f;
		}
		for (int l514 = 0; (l514 < 2); l514 = (l514 + 1)) {
			fRec722[l514] = 0.0f;
		}
		for (int l515 = 0; (l515 < 2); l515 = (l515 + 1)) {
			fRec720[l515] = 0.0f;
		}
		for (int l516 = 0; (l516 < 2); l516 = (l516 + 1)) {
			fRec719[l516] = 0.0f;
		}
		for (int l517 = 0; (l517 < 2); l517 = (l517 + 1)) {
			fRec717[l517] = 0.0f;
		}
		for (int l518 = 0; (l518 < 2); l518 = (l518 + 1)) {
			fRec737[l518] = 0.0f;
		}
		for (int l519 = 0; (l519 < 2); l519 = (l519 + 1)) {
			fRec735[l519] = 0.0f;
		}
		for (int l520 = 0; (l520 < 2); l520 = (l520 + 1)) {
			fRec734[l520] = 0.0f;
		}
		for (int l521 = 0; (l521 < 2); l521 = (l521 + 1)) {
			fRec732[l521] = 0.0f;
		}
		for (int l522 = 0; (l522 < 2); l522 = (l522 + 1)) {
			fRec731[l522] = 0.0f;
		}
		for (int l523 = 0; (l523 < 2); l523 = (l523 + 1)) {
			fRec729[l523] = 0.0f;
		}
		for (int l524 = 0; (l524 < 2); l524 = (l524 + 1)) {
			fRec740[l524] = 0.0f;
		}
		for (int l525 = 0; (l525 < 2); l525 = (l525 + 1)) {
			fRec738[l525] = 0.0f;
		}
		for (int l526 = 0; (l526 < 2); l526 = (l526 + 1)) {
			fRec746[l526] = 0.0f;
		}
		for (int l527 = 0; (l527 < 2); l527 = (l527 + 1)) {
			fRec744[l527] = 0.0f;
		}
		for (int l528 = 0; (l528 < 2); l528 = (l528 + 1)) {
			fRec743[l528] = 0.0f;
		}
		for (int l529 = 0; (l529 < 2); l529 = (l529 + 1)) {
			fRec741[l529] = 0.0f;
		}
		for (int l530 = 0; (l530 < 512); l530 = (l530 + 1)) {
			fVec23[l530] = 0.0f;
		}
		for (int l531 = 0; (l531 < 2); l531 = (l531 + 1)) {
			fRec758[l531] = 0.0f;
		}
		for (int l532 = 0; (l532 < 2); l532 = (l532 + 1)) {
			fRec756[l532] = 0.0f;
		}
		for (int l533 = 0; (l533 < 2); l533 = (l533 + 1)) {
			fRec755[l533] = 0.0f;
		}
		for (int l534 = 0; (l534 < 2); l534 = (l534 + 1)) {
			fRec753[l534] = 0.0f;
		}
		for (int l535 = 0; (l535 < 2); l535 = (l535 + 1)) {
			fRec752[l535] = 0.0f;
		}
		for (int l536 = 0; (l536 < 2); l536 = (l536 + 1)) {
			fRec750[l536] = 0.0f;
		}
		for (int l537 = 0; (l537 < 2); l537 = (l537 + 1)) {
			fRec749[l537] = 0.0f;
		}
		for (int l538 = 0; (l538 < 2); l538 = (l538 + 1)) {
			fRec747[l538] = 0.0f;
		}
		for (int l539 = 0; (l539 < 2); l539 = (l539 + 1)) {
			fRec767[l539] = 0.0f;
		}
		for (int l540 = 0; (l540 < 2); l540 = (l540 + 1)) {
			fRec765[l540] = 0.0f;
		}
		for (int l541 = 0; (l541 < 2); l541 = (l541 + 1)) {
			fRec764[l541] = 0.0f;
		}
		for (int l542 = 0; (l542 < 2); l542 = (l542 + 1)) {
			fRec762[l542] = 0.0f;
		}
		for (int l543 = 0; (l543 < 2); l543 = (l543 + 1)) {
			fRec761[l543] = 0.0f;
		}
		for (int l544 = 0; (l544 < 2); l544 = (l544 + 1)) {
			fRec759[l544] = 0.0f;
		}
		for (int l545 = 0; (l545 < 2); l545 = (l545 + 1)) {
			fRec770[l545] = 0.0f;
		}
		for (int l546 = 0; (l546 < 2); l546 = (l546 + 1)) {
			fRec768[l546] = 0.0f;
		}
		for (int l547 = 0; (l547 < 2); l547 = (l547 + 1)) {
			fRec776[l547] = 0.0f;
		}
		for (int l548 = 0; (l548 < 2); l548 = (l548 + 1)) {
			fRec774[l548] = 0.0f;
		}
		for (int l549 = 0; (l549 < 2); l549 = (l549 + 1)) {
			fRec773[l549] = 0.0f;
		}
		for (int l550 = 0; (l550 < 2); l550 = (l550 + 1)) {
			fRec771[l550] = 0.0f;
		}
		for (int l551 = 0; (l551 < 256); l551 = (l551 + 1)) {
			fVec24[l551] = 0.0f;
		}
		for (int l552 = 0; (l552 < 2); l552 = (l552 + 1)) {
			fRec788[l552] = 0.0f;
		}
		for (int l553 = 0; (l553 < 2); l553 = (l553 + 1)) {
			fRec786[l553] = 0.0f;
		}
		for (int l554 = 0; (l554 < 2); l554 = (l554 + 1)) {
			fRec785[l554] = 0.0f;
		}
		for (int l555 = 0; (l555 < 2); l555 = (l555 + 1)) {
			fRec783[l555] = 0.0f;
		}
		for (int l556 = 0; (l556 < 2); l556 = (l556 + 1)) {
			fRec782[l556] = 0.0f;
		}
		for (int l557 = 0; (l557 < 2); l557 = (l557 + 1)) {
			fRec780[l557] = 0.0f;
		}
		for (int l558 = 0; (l558 < 2); l558 = (l558 + 1)) {
			fRec779[l558] = 0.0f;
		}
		for (int l559 = 0; (l559 < 2); l559 = (l559 + 1)) {
			fRec777[l559] = 0.0f;
		}
		for (int l560 = 0; (l560 < 2); l560 = (l560 + 1)) {
			fRec797[l560] = 0.0f;
		}
		for (int l561 = 0; (l561 < 2); l561 = (l561 + 1)) {
			fRec795[l561] = 0.0f;
		}
		for (int l562 = 0; (l562 < 2); l562 = (l562 + 1)) {
			fRec794[l562] = 0.0f;
		}
		for (int l563 = 0; (l563 < 2); l563 = (l563 + 1)) {
			fRec792[l563] = 0.0f;
		}
		for (int l564 = 0; (l564 < 2); l564 = (l564 + 1)) {
			fRec791[l564] = 0.0f;
		}
		for (int l565 = 0; (l565 < 2); l565 = (l565 + 1)) {
			fRec789[l565] = 0.0f;
		}
		for (int l566 = 0; (l566 < 2); l566 = (l566 + 1)) {
			fRec800[l566] = 0.0f;
		}
		for (int l567 = 0; (l567 < 2); l567 = (l567 + 1)) {
			fRec798[l567] = 0.0f;
		}
		for (int l568 = 0; (l568 < 2); l568 = (l568 + 1)) {
			fRec806[l568] = 0.0f;
		}
		for (int l569 = 0; (l569 < 2); l569 = (l569 + 1)) {
			fRec804[l569] = 0.0f;
		}
		for (int l570 = 0; (l570 < 2); l570 = (l570 + 1)) {
			fRec803[l570] = 0.0f;
		}
		for (int l571 = 0; (l571 < 2); l571 = (l571 + 1)) {
			fRec801[l571] = 0.0f;
		}
		for (int l572 = 0; (l572 < 256); l572 = (l572 + 1)) {
			fVec25[l572] = 0.0f;
		}
		for (int l573 = 0; (l573 < 2); l573 = (l573 + 1)) {
			fRec818[l573] = 0.0f;
		}
		for (int l574 = 0; (l574 < 2); l574 = (l574 + 1)) {
			fRec816[l574] = 0.0f;
		}
		for (int l575 = 0; (l575 < 2); l575 = (l575 + 1)) {
			fRec815[l575] = 0.0f;
		}
		for (int l576 = 0; (l576 < 2); l576 = (l576 + 1)) {
			fRec813[l576] = 0.0f;
		}
		for (int l577 = 0; (l577 < 2); l577 = (l577 + 1)) {
			fRec812[l577] = 0.0f;
		}
		for (int l578 = 0; (l578 < 2); l578 = (l578 + 1)) {
			fRec810[l578] = 0.0f;
		}
		for (int l579 = 0; (l579 < 2); l579 = (l579 + 1)) {
			fRec809[l579] = 0.0f;
		}
		for (int l580 = 0; (l580 < 2); l580 = (l580 + 1)) {
			fRec807[l580] = 0.0f;
		}
		for (int l581 = 0; (l581 < 2); l581 = (l581 + 1)) {
			fRec827[l581] = 0.0f;
		}
		for (int l582 = 0; (l582 < 2); l582 = (l582 + 1)) {
			fRec825[l582] = 0.0f;
		}
		for (int l583 = 0; (l583 < 2); l583 = (l583 + 1)) {
			fRec824[l583] = 0.0f;
		}
		for (int l584 = 0; (l584 < 2); l584 = (l584 + 1)) {
			fRec822[l584] = 0.0f;
		}
		for (int l585 = 0; (l585 < 2); l585 = (l585 + 1)) {
			fRec821[l585] = 0.0f;
		}
		for (int l586 = 0; (l586 < 2); l586 = (l586 + 1)) {
			fRec819[l586] = 0.0f;
		}
		for (int l587 = 0; (l587 < 2); l587 = (l587 + 1)) {
			fRec830[l587] = 0.0f;
		}
		for (int l588 = 0; (l588 < 2); l588 = (l588 + 1)) {
			fRec828[l588] = 0.0f;
		}
		for (int l589 = 0; (l589 < 2); l589 = (l589 + 1)) {
			fRec836[l589] = 0.0f;
		}
		for (int l590 = 0; (l590 < 2); l590 = (l590 + 1)) {
			fRec834[l590] = 0.0f;
		}
		for (int l591 = 0; (l591 < 2); l591 = (l591 + 1)) {
			fRec833[l591] = 0.0f;
		}
		for (int l592 = 0; (l592 < 2); l592 = (l592 + 1)) {
			fRec831[l592] = 0.0f;
		}
		for (int l593 = 0; (l593 < 256); l593 = (l593 + 1)) {
			fVec26[l593] = 0.0f;
		}
		for (int l594 = 0; (l594 < 2); l594 = (l594 + 1)) {
			fRec848[l594] = 0.0f;
		}
		for (int l595 = 0; (l595 < 2); l595 = (l595 + 1)) {
			fRec846[l595] = 0.0f;
		}
		for (int l596 = 0; (l596 < 2); l596 = (l596 + 1)) {
			fRec845[l596] = 0.0f;
		}
		for (int l597 = 0; (l597 < 2); l597 = (l597 + 1)) {
			fRec843[l597] = 0.0f;
		}
		for (int l598 = 0; (l598 < 2); l598 = (l598 + 1)) {
			fRec842[l598] = 0.0f;
		}
		for (int l599 = 0; (l599 < 2); l599 = (l599 + 1)) {
			fRec840[l599] = 0.0f;
		}
		for (int l600 = 0; (l600 < 2); l600 = (l600 + 1)) {
			fRec839[l600] = 0.0f;
		}
		for (int l601 = 0; (l601 < 2); l601 = (l601 + 1)) {
			fRec837[l601] = 0.0f;
		}
		for (int l602 = 0; (l602 < 2); l602 = (l602 + 1)) {
			fRec857[l602] = 0.0f;
		}
		for (int l603 = 0; (l603 < 2); l603 = (l603 + 1)) {
			fRec855[l603] = 0.0f;
		}
		for (int l604 = 0; (l604 < 2); l604 = (l604 + 1)) {
			fRec854[l604] = 0.0f;
		}
		for (int l605 = 0; (l605 < 2); l605 = (l605 + 1)) {
			fRec852[l605] = 0.0f;
		}
		for (int l606 = 0; (l606 < 2); l606 = (l606 + 1)) {
			fRec851[l606] = 0.0f;
		}
		for (int l607 = 0; (l607 < 2); l607 = (l607 + 1)) {
			fRec849[l607] = 0.0f;
		}
		for (int l608 = 0; (l608 < 2); l608 = (l608 + 1)) {
			fRec860[l608] = 0.0f;
		}
		for (int l609 = 0; (l609 < 2); l609 = (l609 + 1)) {
			fRec858[l609] = 0.0f;
		}
		for (int l610 = 0; (l610 < 2); l610 = (l610 + 1)) {
			fRec866[l610] = 0.0f;
		}
		for (int l611 = 0; (l611 < 2); l611 = (l611 + 1)) {
			fRec864[l611] = 0.0f;
		}
		for (int l612 = 0; (l612 < 2); l612 = (l612 + 1)) {
			fRec863[l612] = 0.0f;
		}
		for (int l613 = 0; (l613 < 2); l613 = (l613 + 1)) {
			fRec861[l613] = 0.0f;
		}
		for (int l614 = 0; (l614 < 256); l614 = (l614 + 1)) {
			fVec27[l614] = 0.0f;
		}
		for (int l615 = 0; (l615 < 2); l615 = (l615 + 1)) {
			fRec878[l615] = 0.0f;
		}
		for (int l616 = 0; (l616 < 2); l616 = (l616 + 1)) {
			fRec876[l616] = 0.0f;
		}
		for (int l617 = 0; (l617 < 2); l617 = (l617 + 1)) {
			fRec875[l617] = 0.0f;
		}
		for (int l618 = 0; (l618 < 2); l618 = (l618 + 1)) {
			fRec873[l618] = 0.0f;
		}
		for (int l619 = 0; (l619 < 2); l619 = (l619 + 1)) {
			fRec872[l619] = 0.0f;
		}
		for (int l620 = 0; (l620 < 2); l620 = (l620 + 1)) {
			fRec870[l620] = 0.0f;
		}
		for (int l621 = 0; (l621 < 2); l621 = (l621 + 1)) {
			fRec869[l621] = 0.0f;
		}
		for (int l622 = 0; (l622 < 2); l622 = (l622 + 1)) {
			fRec867[l622] = 0.0f;
		}
		for (int l623 = 0; (l623 < 2); l623 = (l623 + 1)) {
			fRec887[l623] = 0.0f;
		}
		for (int l624 = 0; (l624 < 2); l624 = (l624 + 1)) {
			fRec885[l624] = 0.0f;
		}
		for (int l625 = 0; (l625 < 2); l625 = (l625 + 1)) {
			fRec884[l625] = 0.0f;
		}
		for (int l626 = 0; (l626 < 2); l626 = (l626 + 1)) {
			fRec882[l626] = 0.0f;
		}
		for (int l627 = 0; (l627 < 2); l627 = (l627 + 1)) {
			fRec881[l627] = 0.0f;
		}
		for (int l628 = 0; (l628 < 2); l628 = (l628 + 1)) {
			fRec879[l628] = 0.0f;
		}
		for (int l629 = 0; (l629 < 2); l629 = (l629 + 1)) {
			fRec890[l629] = 0.0f;
		}
		for (int l630 = 0; (l630 < 2); l630 = (l630 + 1)) {
			fRec888[l630] = 0.0f;
		}
		for (int l631 = 0; (l631 < 2); l631 = (l631 + 1)) {
			fRec896[l631] = 0.0f;
		}
		for (int l632 = 0; (l632 < 2); l632 = (l632 + 1)) {
			fRec894[l632] = 0.0f;
		}
		for (int l633 = 0; (l633 < 2); l633 = (l633 + 1)) {
			fRec893[l633] = 0.0f;
		}
		for (int l634 = 0; (l634 < 2); l634 = (l634 + 1)) {
			fRec891[l634] = 0.0f;
		}
		for (int l635 = 0; (l635 < 2); l635 = (l635 + 1)) {
			fRec908[l635] = 0.0f;
		}
		for (int l636 = 0; (l636 < 2); l636 = (l636 + 1)) {
			fRec906[l636] = 0.0f;
		}
		for (int l637 = 0; (l637 < 2); l637 = (l637 + 1)) {
			fRec905[l637] = 0.0f;
		}
		for (int l638 = 0; (l638 < 2); l638 = (l638 + 1)) {
			fRec903[l638] = 0.0f;
		}
		for (int l639 = 0; (l639 < 2); l639 = (l639 + 1)) {
			fRec902[l639] = 0.0f;
		}
		for (int l640 = 0; (l640 < 2); l640 = (l640 + 1)) {
			fRec900[l640] = 0.0f;
		}
		for (int l641 = 0; (l641 < 2); l641 = (l641 + 1)) {
			fRec899[l641] = 0.0f;
		}
		for (int l642 = 0; (l642 < 2); l642 = (l642 + 1)) {
			fRec897[l642] = 0.0f;
		}
		for (int l643 = 0; (l643 < 2); l643 = (l643 + 1)) {
			fRec917[l643] = 0.0f;
		}
		for (int l644 = 0; (l644 < 2); l644 = (l644 + 1)) {
			fRec915[l644] = 0.0f;
		}
		for (int l645 = 0; (l645 < 2); l645 = (l645 + 1)) {
			fRec914[l645] = 0.0f;
		}
		for (int l646 = 0; (l646 < 2); l646 = (l646 + 1)) {
			fRec912[l646] = 0.0f;
		}
		for (int l647 = 0; (l647 < 2); l647 = (l647 + 1)) {
			fRec911[l647] = 0.0f;
		}
		for (int l648 = 0; (l648 < 2); l648 = (l648 + 1)) {
			fRec909[l648] = 0.0f;
		}
		for (int l649 = 0; (l649 < 2); l649 = (l649 + 1)) {
			fRec920[l649] = 0.0f;
		}
		for (int l650 = 0; (l650 < 2); l650 = (l650 + 1)) {
			fRec918[l650] = 0.0f;
		}
		for (int l651 = 0; (l651 < 2); l651 = (l651 + 1)) {
			fRec926[l651] = 0.0f;
		}
		for (int l652 = 0; (l652 < 2); l652 = (l652 + 1)) {
			fRec924[l652] = 0.0f;
		}
		for (int l653 = 0; (l653 < 2); l653 = (l653 + 1)) {
			fRec923[l653] = 0.0f;
		}
		for (int l654 = 0; (l654 < 2); l654 = (l654 + 1)) {
			fRec921[l654] = 0.0f;
		}
		for (int l655 = 0; (l655 < 1024); l655 = (l655 + 1)) {
			fVec28[l655] = 0.0f;
		}
		for (int l656 = 0; (l656 < 2); l656 = (l656 + 1)) {
			fRec938[l656] = 0.0f;
		}
		for (int l657 = 0; (l657 < 2); l657 = (l657 + 1)) {
			fRec936[l657] = 0.0f;
		}
		for (int l658 = 0; (l658 < 2); l658 = (l658 + 1)) {
			fRec935[l658] = 0.0f;
		}
		for (int l659 = 0; (l659 < 2); l659 = (l659 + 1)) {
			fRec933[l659] = 0.0f;
		}
		for (int l660 = 0; (l660 < 2); l660 = (l660 + 1)) {
			fRec932[l660] = 0.0f;
		}
		for (int l661 = 0; (l661 < 2); l661 = (l661 + 1)) {
			fRec930[l661] = 0.0f;
		}
		for (int l662 = 0; (l662 < 2); l662 = (l662 + 1)) {
			fRec929[l662] = 0.0f;
		}
		for (int l663 = 0; (l663 < 2); l663 = (l663 + 1)) {
			fRec927[l663] = 0.0f;
		}
		for (int l664 = 0; (l664 < 2); l664 = (l664 + 1)) {
			fRec947[l664] = 0.0f;
		}
		for (int l665 = 0; (l665 < 2); l665 = (l665 + 1)) {
			fRec945[l665] = 0.0f;
		}
		for (int l666 = 0; (l666 < 2); l666 = (l666 + 1)) {
			fRec944[l666] = 0.0f;
		}
		for (int l667 = 0; (l667 < 2); l667 = (l667 + 1)) {
			fRec942[l667] = 0.0f;
		}
		for (int l668 = 0; (l668 < 2); l668 = (l668 + 1)) {
			fRec941[l668] = 0.0f;
		}
		for (int l669 = 0; (l669 < 2); l669 = (l669 + 1)) {
			fRec939[l669] = 0.0f;
		}
		for (int l670 = 0; (l670 < 2); l670 = (l670 + 1)) {
			fRec950[l670] = 0.0f;
		}
		for (int l671 = 0; (l671 < 2); l671 = (l671 + 1)) {
			fRec948[l671] = 0.0f;
		}
		for (int l672 = 0; (l672 < 2); l672 = (l672 + 1)) {
			fRec956[l672] = 0.0f;
		}
		for (int l673 = 0; (l673 < 2); l673 = (l673 + 1)) {
			fRec954[l673] = 0.0f;
		}
		for (int l674 = 0; (l674 < 2); l674 = (l674 + 1)) {
			fRec953[l674] = 0.0f;
		}
		for (int l675 = 0; (l675 < 2); l675 = (l675 + 1)) {
			fRec951[l675] = 0.0f;
		}
		for (int l676 = 0; (l676 < 1024); l676 = (l676 + 1)) {
			fVec29[l676] = 0.0f;
		}
		for (int l677 = 0; (l677 < 2); l677 = (l677 + 1)) {
			fRec968[l677] = 0.0f;
		}
		for (int l678 = 0; (l678 < 2); l678 = (l678 + 1)) {
			fRec966[l678] = 0.0f;
		}
		for (int l679 = 0; (l679 < 2); l679 = (l679 + 1)) {
			fRec965[l679] = 0.0f;
		}
		for (int l680 = 0; (l680 < 2); l680 = (l680 + 1)) {
			fRec963[l680] = 0.0f;
		}
		for (int l681 = 0; (l681 < 2); l681 = (l681 + 1)) {
			fRec962[l681] = 0.0f;
		}
		for (int l682 = 0; (l682 < 2); l682 = (l682 + 1)) {
			fRec960[l682] = 0.0f;
		}
		for (int l683 = 0; (l683 < 2); l683 = (l683 + 1)) {
			fRec959[l683] = 0.0f;
		}
		for (int l684 = 0; (l684 < 2); l684 = (l684 + 1)) {
			fRec957[l684] = 0.0f;
		}
		for (int l685 = 0; (l685 < 2); l685 = (l685 + 1)) {
			fRec977[l685] = 0.0f;
		}
		for (int l686 = 0; (l686 < 2); l686 = (l686 + 1)) {
			fRec975[l686] = 0.0f;
		}
		for (int l687 = 0; (l687 < 2); l687 = (l687 + 1)) {
			fRec974[l687] = 0.0f;
		}
		for (int l688 = 0; (l688 < 2); l688 = (l688 + 1)) {
			fRec972[l688] = 0.0f;
		}
		for (int l689 = 0; (l689 < 2); l689 = (l689 + 1)) {
			fRec971[l689] = 0.0f;
		}
		for (int l690 = 0; (l690 < 2); l690 = (l690 + 1)) {
			fRec969[l690] = 0.0f;
		}
		for (int l691 = 0; (l691 < 2); l691 = (l691 + 1)) {
			fRec980[l691] = 0.0f;
		}
		for (int l692 = 0; (l692 < 2); l692 = (l692 + 1)) {
			fRec978[l692] = 0.0f;
		}
		for (int l693 = 0; (l693 < 2); l693 = (l693 + 1)) {
			fRec986[l693] = 0.0f;
		}
		for (int l694 = 0; (l694 < 2); l694 = (l694 + 1)) {
			fRec984[l694] = 0.0f;
		}
		for (int l695 = 0; (l695 < 2); l695 = (l695 + 1)) {
			fRec983[l695] = 0.0f;
		}
		for (int l696 = 0; (l696 < 2); l696 = (l696 + 1)) {
			fRec981[l696] = 0.0f;
		}
		for (int l697 = 0; (l697 < 1024); l697 = (l697 + 1)) {
			fVec30[l697] = 0.0f;
		}
		for (int l698 = 0; (l698 < 2); l698 = (l698 + 1)) {
			fRec998[l698] = 0.0f;
		}
		for (int l699 = 0; (l699 < 2); l699 = (l699 + 1)) {
			fRec996[l699] = 0.0f;
		}
		for (int l700 = 0; (l700 < 2); l700 = (l700 + 1)) {
			fRec995[l700] = 0.0f;
		}
		for (int l701 = 0; (l701 < 2); l701 = (l701 + 1)) {
			fRec993[l701] = 0.0f;
		}
		for (int l702 = 0; (l702 < 2); l702 = (l702 + 1)) {
			fRec992[l702] = 0.0f;
		}
		for (int l703 = 0; (l703 < 2); l703 = (l703 + 1)) {
			fRec990[l703] = 0.0f;
		}
		for (int l704 = 0; (l704 < 2); l704 = (l704 + 1)) {
			fRec989[l704] = 0.0f;
		}
		for (int l705 = 0; (l705 < 2); l705 = (l705 + 1)) {
			fRec987[l705] = 0.0f;
		}
		for (int l706 = 0; (l706 < 2); l706 = (l706 + 1)) {
			fRec1007[l706] = 0.0f;
		}
		for (int l707 = 0; (l707 < 2); l707 = (l707 + 1)) {
			fRec1005[l707] = 0.0f;
		}
		for (int l708 = 0; (l708 < 2); l708 = (l708 + 1)) {
			fRec1004[l708] = 0.0f;
		}
		for (int l709 = 0; (l709 < 2); l709 = (l709 + 1)) {
			fRec1002[l709] = 0.0f;
		}
		for (int l710 = 0; (l710 < 2); l710 = (l710 + 1)) {
			fRec1001[l710] = 0.0f;
		}
		for (int l711 = 0; (l711 < 2); l711 = (l711 + 1)) {
			fRec999[l711] = 0.0f;
		}
		for (int l712 = 0; (l712 < 2); l712 = (l712 + 1)) {
			fRec1010[l712] = 0.0f;
		}
		for (int l713 = 0; (l713 < 2); l713 = (l713 + 1)) {
			fRec1008[l713] = 0.0f;
		}
		for (int l714 = 0; (l714 < 2); l714 = (l714 + 1)) {
			fRec1016[l714] = 0.0f;
		}
		for (int l715 = 0; (l715 < 2); l715 = (l715 + 1)) {
			fRec1014[l715] = 0.0f;
		}
		for (int l716 = 0; (l716 < 2); l716 = (l716 + 1)) {
			fRec1013[l716] = 0.0f;
		}
		for (int l717 = 0; (l717 < 2); l717 = (l717 + 1)) {
			fRec1011[l717] = 0.0f;
		}
		for (int l718 = 0; (l718 < 1024); l718 = (l718 + 1)) {
			fVec31[l718] = 0.0f;
		}
		for (int l719 = 0; (l719 < 2); l719 = (l719 + 1)) {
			fRec1028[l719] = 0.0f;
		}
		for (int l720 = 0; (l720 < 2); l720 = (l720 + 1)) {
			fRec1026[l720] = 0.0f;
		}
		for (int l721 = 0; (l721 < 2); l721 = (l721 + 1)) {
			fRec1025[l721] = 0.0f;
		}
		for (int l722 = 0; (l722 < 2); l722 = (l722 + 1)) {
			fRec1023[l722] = 0.0f;
		}
		for (int l723 = 0; (l723 < 2); l723 = (l723 + 1)) {
			fRec1022[l723] = 0.0f;
		}
		for (int l724 = 0; (l724 < 2); l724 = (l724 + 1)) {
			fRec1020[l724] = 0.0f;
		}
		for (int l725 = 0; (l725 < 2); l725 = (l725 + 1)) {
			fRec1019[l725] = 0.0f;
		}
		for (int l726 = 0; (l726 < 2); l726 = (l726 + 1)) {
			fRec1017[l726] = 0.0f;
		}
		for (int l727 = 0; (l727 < 2); l727 = (l727 + 1)) {
			fRec1037[l727] = 0.0f;
		}
		for (int l728 = 0; (l728 < 2); l728 = (l728 + 1)) {
			fRec1035[l728] = 0.0f;
		}
		for (int l729 = 0; (l729 < 2); l729 = (l729 + 1)) {
			fRec1034[l729] = 0.0f;
		}
		for (int l730 = 0; (l730 < 2); l730 = (l730 + 1)) {
			fRec1032[l730] = 0.0f;
		}
		for (int l731 = 0; (l731 < 2); l731 = (l731 + 1)) {
			fRec1031[l731] = 0.0f;
		}
		for (int l732 = 0; (l732 < 2); l732 = (l732 + 1)) {
			fRec1029[l732] = 0.0f;
		}
		for (int l733 = 0; (l733 < 2); l733 = (l733 + 1)) {
			fRec1040[l733] = 0.0f;
		}
		for (int l734 = 0; (l734 < 2); l734 = (l734 + 1)) {
			fRec1038[l734] = 0.0f;
		}
		for (int l735 = 0; (l735 < 2); l735 = (l735 + 1)) {
			fRec1046[l735] = 0.0f;
		}
		for (int l736 = 0; (l736 < 2); l736 = (l736 + 1)) {
			fRec1044[l736] = 0.0f;
		}
		for (int l737 = 0; (l737 < 2); l737 = (l737 + 1)) {
			fRec1043[l737] = 0.0f;
		}
		for (int l738 = 0; (l738 < 2); l738 = (l738 + 1)) {
			fRec1041[l738] = 0.0f;
		}
		for (int l739 = 0; (l739 < 1024); l739 = (l739 + 1)) {
			fVec32[l739] = 0.0f;
		}
		for (int l740 = 0; (l740 < 2); l740 = (l740 + 1)) {
			fRec1058[l740] = 0.0f;
		}
		for (int l741 = 0; (l741 < 2); l741 = (l741 + 1)) {
			fRec1056[l741] = 0.0f;
		}
		for (int l742 = 0; (l742 < 2); l742 = (l742 + 1)) {
			fRec1055[l742] = 0.0f;
		}
		for (int l743 = 0; (l743 < 2); l743 = (l743 + 1)) {
			fRec1053[l743] = 0.0f;
		}
		for (int l744 = 0; (l744 < 2); l744 = (l744 + 1)) {
			fRec1052[l744] = 0.0f;
		}
		for (int l745 = 0; (l745 < 2); l745 = (l745 + 1)) {
			fRec1050[l745] = 0.0f;
		}
		for (int l746 = 0; (l746 < 2); l746 = (l746 + 1)) {
			fRec1049[l746] = 0.0f;
		}
		for (int l747 = 0; (l747 < 2); l747 = (l747 + 1)) {
			fRec1047[l747] = 0.0f;
		}
		for (int l748 = 0; (l748 < 2); l748 = (l748 + 1)) {
			fRec1067[l748] = 0.0f;
		}
		for (int l749 = 0; (l749 < 2); l749 = (l749 + 1)) {
			fRec1065[l749] = 0.0f;
		}
		for (int l750 = 0; (l750 < 2); l750 = (l750 + 1)) {
			fRec1064[l750] = 0.0f;
		}
		for (int l751 = 0; (l751 < 2); l751 = (l751 + 1)) {
			fRec1062[l751] = 0.0f;
		}
		for (int l752 = 0; (l752 < 2); l752 = (l752 + 1)) {
			fRec1061[l752] = 0.0f;
		}
		for (int l753 = 0; (l753 < 2); l753 = (l753 + 1)) {
			fRec1059[l753] = 0.0f;
		}
		for (int l754 = 0; (l754 < 2); l754 = (l754 + 1)) {
			fRec1070[l754] = 0.0f;
		}
		for (int l755 = 0; (l755 < 2); l755 = (l755 + 1)) {
			fRec1068[l755] = 0.0f;
		}
		for (int l756 = 0; (l756 < 2); l756 = (l756 + 1)) {
			fRec1076[l756] = 0.0f;
		}
		for (int l757 = 0; (l757 < 2); l757 = (l757 + 1)) {
			fRec1074[l757] = 0.0f;
		}
		for (int l758 = 0; (l758 < 2); l758 = (l758 + 1)) {
			fRec1073[l758] = 0.0f;
		}
		for (int l759 = 0; (l759 < 2); l759 = (l759 + 1)) {
			fRec1071[l759] = 0.0f;
		}
		for (int l760 = 0; (l760 < 1024); l760 = (l760 + 1)) {
			fVec33[l760] = 0.0f;
		}
		for (int l761 = 0; (l761 < 2); l761 = (l761 + 1)) {
			fRec1088[l761] = 0.0f;
		}
		for (int l762 = 0; (l762 < 2); l762 = (l762 + 1)) {
			fRec1086[l762] = 0.0f;
		}
		for (int l763 = 0; (l763 < 2); l763 = (l763 + 1)) {
			fRec1085[l763] = 0.0f;
		}
		for (int l764 = 0; (l764 < 2); l764 = (l764 + 1)) {
			fRec1083[l764] = 0.0f;
		}
		for (int l765 = 0; (l765 < 2); l765 = (l765 + 1)) {
			fRec1082[l765] = 0.0f;
		}
		for (int l766 = 0; (l766 < 2); l766 = (l766 + 1)) {
			fRec1080[l766] = 0.0f;
		}
		for (int l767 = 0; (l767 < 2); l767 = (l767 + 1)) {
			fRec1079[l767] = 0.0f;
		}
		for (int l768 = 0; (l768 < 2); l768 = (l768 + 1)) {
			fRec1077[l768] = 0.0f;
		}
		for (int l769 = 0; (l769 < 2); l769 = (l769 + 1)) {
			fRec1097[l769] = 0.0f;
		}
		for (int l770 = 0; (l770 < 2); l770 = (l770 + 1)) {
			fRec1095[l770] = 0.0f;
		}
		for (int l771 = 0; (l771 < 2); l771 = (l771 + 1)) {
			fRec1094[l771] = 0.0f;
		}
		for (int l772 = 0; (l772 < 2); l772 = (l772 + 1)) {
			fRec1092[l772] = 0.0f;
		}
		for (int l773 = 0; (l773 < 2); l773 = (l773 + 1)) {
			fRec1091[l773] = 0.0f;
		}
		for (int l774 = 0; (l774 < 2); l774 = (l774 + 1)) {
			fRec1089[l774] = 0.0f;
		}
		for (int l775 = 0; (l775 < 2); l775 = (l775 + 1)) {
			fRec1100[l775] = 0.0f;
		}
		for (int l776 = 0; (l776 < 2); l776 = (l776 + 1)) {
			fRec1098[l776] = 0.0f;
		}
		for (int l777 = 0; (l777 < 2); l777 = (l777 + 1)) {
			fRec1106[l777] = 0.0f;
		}
		for (int l778 = 0; (l778 < 2); l778 = (l778 + 1)) {
			fRec1104[l778] = 0.0f;
		}
		for (int l779 = 0; (l779 < 2); l779 = (l779 + 1)) {
			fRec1103[l779] = 0.0f;
		}
		for (int l780 = 0; (l780 < 2); l780 = (l780 + 1)) {
			fRec1101[l780] = 0.0f;
		}
		for (int l781 = 0; (l781 < 1024); l781 = (l781 + 1)) {
			fVec34[l781] = 0.0f;
		}
		for (int l782 = 0; (l782 < 2); l782 = (l782 + 1)) {
			fRec1118[l782] = 0.0f;
		}
		for (int l783 = 0; (l783 < 2); l783 = (l783 + 1)) {
			fRec1116[l783] = 0.0f;
		}
		for (int l784 = 0; (l784 < 2); l784 = (l784 + 1)) {
			fRec1115[l784] = 0.0f;
		}
		for (int l785 = 0; (l785 < 2); l785 = (l785 + 1)) {
			fRec1113[l785] = 0.0f;
		}
		for (int l786 = 0; (l786 < 2); l786 = (l786 + 1)) {
			fRec1112[l786] = 0.0f;
		}
		for (int l787 = 0; (l787 < 2); l787 = (l787 + 1)) {
			fRec1110[l787] = 0.0f;
		}
		for (int l788 = 0; (l788 < 2); l788 = (l788 + 1)) {
			fRec1109[l788] = 0.0f;
		}
		for (int l789 = 0; (l789 < 2); l789 = (l789 + 1)) {
			fRec1107[l789] = 0.0f;
		}
		for (int l790 = 0; (l790 < 2); l790 = (l790 + 1)) {
			fRec1127[l790] = 0.0f;
		}
		for (int l791 = 0; (l791 < 2); l791 = (l791 + 1)) {
			fRec1125[l791] = 0.0f;
		}
		for (int l792 = 0; (l792 < 2); l792 = (l792 + 1)) {
			fRec1124[l792] = 0.0f;
		}
		for (int l793 = 0; (l793 < 2); l793 = (l793 + 1)) {
			fRec1122[l793] = 0.0f;
		}
		for (int l794 = 0; (l794 < 2); l794 = (l794 + 1)) {
			fRec1121[l794] = 0.0f;
		}
		for (int l795 = 0; (l795 < 2); l795 = (l795 + 1)) {
			fRec1119[l795] = 0.0f;
		}
		for (int l796 = 0; (l796 < 2); l796 = (l796 + 1)) {
			fRec1130[l796] = 0.0f;
		}
		for (int l797 = 0; (l797 < 2); l797 = (l797 + 1)) {
			fRec1128[l797] = 0.0f;
		}
		for (int l798 = 0; (l798 < 2); l798 = (l798 + 1)) {
			fRec1136[l798] = 0.0f;
		}
		for (int l799 = 0; (l799 < 2); l799 = (l799 + 1)) {
			fRec1134[l799] = 0.0f;
		}
		for (int l800 = 0; (l800 < 2); l800 = (l800 + 1)) {
			fRec1133[l800] = 0.0f;
		}
		for (int l801 = 0; (l801 < 2); l801 = (l801 + 1)) {
			fRec1131[l801] = 0.0f;
		}
		for (int l802 = 0; (l802 < 1024); l802 = (l802 + 1)) {
			fVec35[l802] = 0.0f;
		}
		for (int l803 = 0; (l803 < 2); l803 = (l803 + 1)) {
			fRec1148[l803] = 0.0f;
		}
		for (int l804 = 0; (l804 < 2); l804 = (l804 + 1)) {
			fRec1146[l804] = 0.0f;
		}
		for (int l805 = 0; (l805 < 2); l805 = (l805 + 1)) {
			fRec1145[l805] = 0.0f;
		}
		for (int l806 = 0; (l806 < 2); l806 = (l806 + 1)) {
			fRec1143[l806] = 0.0f;
		}
		for (int l807 = 0; (l807 < 2); l807 = (l807 + 1)) {
			fRec1142[l807] = 0.0f;
		}
		for (int l808 = 0; (l808 < 2); l808 = (l808 + 1)) {
			fRec1140[l808] = 0.0f;
		}
		for (int l809 = 0; (l809 < 2); l809 = (l809 + 1)) {
			fRec1139[l809] = 0.0f;
		}
		for (int l810 = 0; (l810 < 2); l810 = (l810 + 1)) {
			fRec1137[l810] = 0.0f;
		}
		for (int l811 = 0; (l811 < 2); l811 = (l811 + 1)) {
			fRec1157[l811] = 0.0f;
		}
		for (int l812 = 0; (l812 < 2); l812 = (l812 + 1)) {
			fRec1155[l812] = 0.0f;
		}
		for (int l813 = 0; (l813 < 2); l813 = (l813 + 1)) {
			fRec1154[l813] = 0.0f;
		}
		for (int l814 = 0; (l814 < 2); l814 = (l814 + 1)) {
			fRec1152[l814] = 0.0f;
		}
		for (int l815 = 0; (l815 < 2); l815 = (l815 + 1)) {
			fRec1151[l815] = 0.0f;
		}
		for (int l816 = 0; (l816 < 2); l816 = (l816 + 1)) {
			fRec1149[l816] = 0.0f;
		}
		for (int l817 = 0; (l817 < 2); l817 = (l817 + 1)) {
			fRec1160[l817] = 0.0f;
		}
		for (int l818 = 0; (l818 < 2); l818 = (l818 + 1)) {
			fRec1158[l818] = 0.0f;
		}
		for (int l819 = 0; (l819 < 2); l819 = (l819 + 1)) {
			fRec1166[l819] = 0.0f;
		}
		for (int l820 = 0; (l820 < 2); l820 = (l820 + 1)) {
			fRec1164[l820] = 0.0f;
		}
		for (int l821 = 0; (l821 < 2); l821 = (l821 + 1)) {
			fRec1163[l821] = 0.0f;
		}
		for (int l822 = 0; (l822 < 2); l822 = (l822 + 1)) {
			fRec1161[l822] = 0.0f;
		}
		for (int l823 = 0; (l823 < 1024); l823 = (l823 + 1)) {
			fVec36[l823] = 0.0f;
		}
		for (int l824 = 0; (l824 < 2); l824 = (l824 + 1)) {
			fRec1178[l824] = 0.0f;
		}
		for (int l825 = 0; (l825 < 2); l825 = (l825 + 1)) {
			fRec1176[l825] = 0.0f;
		}
		for (int l826 = 0; (l826 < 2); l826 = (l826 + 1)) {
			fRec1175[l826] = 0.0f;
		}
		for (int l827 = 0; (l827 < 2); l827 = (l827 + 1)) {
			fRec1173[l827] = 0.0f;
		}
		for (int l828 = 0; (l828 < 2); l828 = (l828 + 1)) {
			fRec1172[l828] = 0.0f;
		}
		for (int l829 = 0; (l829 < 2); l829 = (l829 + 1)) {
			fRec1170[l829] = 0.0f;
		}
		for (int l830 = 0; (l830 < 2); l830 = (l830 + 1)) {
			fRec1169[l830] = 0.0f;
		}
		for (int l831 = 0; (l831 < 2); l831 = (l831 + 1)) {
			fRec1167[l831] = 0.0f;
		}
		for (int l832 = 0; (l832 < 2); l832 = (l832 + 1)) {
			fRec1187[l832] = 0.0f;
		}
		for (int l833 = 0; (l833 < 2); l833 = (l833 + 1)) {
			fRec1185[l833] = 0.0f;
		}
		for (int l834 = 0; (l834 < 2); l834 = (l834 + 1)) {
			fRec1184[l834] = 0.0f;
		}
		for (int l835 = 0; (l835 < 2); l835 = (l835 + 1)) {
			fRec1182[l835] = 0.0f;
		}
		for (int l836 = 0; (l836 < 2); l836 = (l836 + 1)) {
			fRec1181[l836] = 0.0f;
		}
		for (int l837 = 0; (l837 < 2); l837 = (l837 + 1)) {
			fRec1179[l837] = 0.0f;
		}
		for (int l838 = 0; (l838 < 2); l838 = (l838 + 1)) {
			fRec1190[l838] = 0.0f;
		}
		for (int l839 = 0; (l839 < 2); l839 = (l839 + 1)) {
			fRec1188[l839] = 0.0f;
		}
		for (int l840 = 0; (l840 < 2); l840 = (l840 + 1)) {
			fRec1196[l840] = 0.0f;
		}
		for (int l841 = 0; (l841 < 2); l841 = (l841 + 1)) {
			fRec1194[l841] = 0.0f;
		}
		for (int l842 = 0; (l842 < 2); l842 = (l842 + 1)) {
			fRec1193[l842] = 0.0f;
		}
		for (int l843 = 0; (l843 < 2); l843 = (l843 + 1)) {
			fRec1191[l843] = 0.0f;
		}
		for (int l844 = 0; (l844 < 1024); l844 = (l844 + 1)) {
			fVec37[l844] = 0.0f;
		}
		for (int l845 = 0; (l845 < 2); l845 = (l845 + 1)) {
			fRec1208[l845] = 0.0f;
		}
		for (int l846 = 0; (l846 < 2); l846 = (l846 + 1)) {
			fRec1206[l846] = 0.0f;
		}
		for (int l847 = 0; (l847 < 2); l847 = (l847 + 1)) {
			fRec1205[l847] = 0.0f;
		}
		for (int l848 = 0; (l848 < 2); l848 = (l848 + 1)) {
			fRec1203[l848] = 0.0f;
		}
		for (int l849 = 0; (l849 < 2); l849 = (l849 + 1)) {
			fRec1202[l849] = 0.0f;
		}
		for (int l850 = 0; (l850 < 2); l850 = (l850 + 1)) {
			fRec1200[l850] = 0.0f;
		}
		for (int l851 = 0; (l851 < 2); l851 = (l851 + 1)) {
			fRec1199[l851] = 0.0f;
		}
		for (int l852 = 0; (l852 < 2); l852 = (l852 + 1)) {
			fRec1197[l852] = 0.0f;
		}
		for (int l853 = 0; (l853 < 2); l853 = (l853 + 1)) {
			fRec1217[l853] = 0.0f;
		}
		for (int l854 = 0; (l854 < 2); l854 = (l854 + 1)) {
			fRec1215[l854] = 0.0f;
		}
		for (int l855 = 0; (l855 < 2); l855 = (l855 + 1)) {
			fRec1214[l855] = 0.0f;
		}
		for (int l856 = 0; (l856 < 2); l856 = (l856 + 1)) {
			fRec1212[l856] = 0.0f;
		}
		for (int l857 = 0; (l857 < 2); l857 = (l857 + 1)) {
			fRec1211[l857] = 0.0f;
		}
		for (int l858 = 0; (l858 < 2); l858 = (l858 + 1)) {
			fRec1209[l858] = 0.0f;
		}
		for (int l859 = 0; (l859 < 2); l859 = (l859 + 1)) {
			fRec1220[l859] = 0.0f;
		}
		for (int l860 = 0; (l860 < 2); l860 = (l860 + 1)) {
			fRec1218[l860] = 0.0f;
		}
		for (int l861 = 0; (l861 < 2); l861 = (l861 + 1)) {
			fRec1226[l861] = 0.0f;
		}
		for (int l862 = 0; (l862 < 2); l862 = (l862 + 1)) {
			fRec1224[l862] = 0.0f;
		}
		for (int l863 = 0; (l863 < 2); l863 = (l863 + 1)) {
			fRec1223[l863] = 0.0f;
		}
		for (int l864 = 0; (l864 < 2); l864 = (l864 + 1)) {
			fRec1221[l864] = 0.0f;
		}
		for (int l865 = 0; (l865 < 1024); l865 = (l865 + 1)) {
			fVec38[l865] = 0.0f;
		}
		for (int l866 = 0; (l866 < 2); l866 = (l866 + 1)) {
			fRec1238[l866] = 0.0f;
		}
		for (int l867 = 0; (l867 < 2); l867 = (l867 + 1)) {
			fRec1236[l867] = 0.0f;
		}
		for (int l868 = 0; (l868 < 2); l868 = (l868 + 1)) {
			fRec1235[l868] = 0.0f;
		}
		for (int l869 = 0; (l869 < 2); l869 = (l869 + 1)) {
			fRec1233[l869] = 0.0f;
		}
		for (int l870 = 0; (l870 < 2); l870 = (l870 + 1)) {
			fRec1232[l870] = 0.0f;
		}
		for (int l871 = 0; (l871 < 2); l871 = (l871 + 1)) {
			fRec1230[l871] = 0.0f;
		}
		for (int l872 = 0; (l872 < 2); l872 = (l872 + 1)) {
			fRec1229[l872] = 0.0f;
		}
		for (int l873 = 0; (l873 < 2); l873 = (l873 + 1)) {
			fRec1227[l873] = 0.0f;
		}
		for (int l874 = 0; (l874 < 2); l874 = (l874 + 1)) {
			fRec1247[l874] = 0.0f;
		}
		for (int l875 = 0; (l875 < 2); l875 = (l875 + 1)) {
			fRec1245[l875] = 0.0f;
		}
		for (int l876 = 0; (l876 < 2); l876 = (l876 + 1)) {
			fRec1244[l876] = 0.0f;
		}
		for (int l877 = 0; (l877 < 2); l877 = (l877 + 1)) {
			fRec1242[l877] = 0.0f;
		}
		for (int l878 = 0; (l878 < 2); l878 = (l878 + 1)) {
			fRec1241[l878] = 0.0f;
		}
		for (int l879 = 0; (l879 < 2); l879 = (l879 + 1)) {
			fRec1239[l879] = 0.0f;
		}
		for (int l880 = 0; (l880 < 2); l880 = (l880 + 1)) {
			fRec1250[l880] = 0.0f;
		}
		for (int l881 = 0; (l881 < 2); l881 = (l881 + 1)) {
			fRec1248[l881] = 0.0f;
		}
		for (int l882 = 0; (l882 < 2); l882 = (l882 + 1)) {
			fRec1256[l882] = 0.0f;
		}
		for (int l883 = 0; (l883 < 2); l883 = (l883 + 1)) {
			fRec1254[l883] = 0.0f;
		}
		for (int l884 = 0; (l884 < 2); l884 = (l884 + 1)) {
			fRec1253[l884] = 0.0f;
		}
		for (int l885 = 0; (l885 < 2); l885 = (l885 + 1)) {
			fRec1251[l885] = 0.0f;
		}
		for (int l886 = 0; (l886 < 1024); l886 = (l886 + 1)) {
			fVec39[l886] = 0.0f;
		}
		for (int l887 = 0; (l887 < 2); l887 = (l887 + 1)) {
			fRec1268[l887] = 0.0f;
		}
		for (int l888 = 0; (l888 < 2); l888 = (l888 + 1)) {
			fRec1266[l888] = 0.0f;
		}
		for (int l889 = 0; (l889 < 2); l889 = (l889 + 1)) {
			fRec1265[l889] = 0.0f;
		}
		for (int l890 = 0; (l890 < 2); l890 = (l890 + 1)) {
			fRec1263[l890] = 0.0f;
		}
		for (int l891 = 0; (l891 < 2); l891 = (l891 + 1)) {
			fRec1262[l891] = 0.0f;
		}
		for (int l892 = 0; (l892 < 2); l892 = (l892 + 1)) {
			fRec1260[l892] = 0.0f;
		}
		for (int l893 = 0; (l893 < 2); l893 = (l893 + 1)) {
			fRec1259[l893] = 0.0f;
		}
		for (int l894 = 0; (l894 < 2); l894 = (l894 + 1)) {
			fRec1257[l894] = 0.0f;
		}
		for (int l895 = 0; (l895 < 2); l895 = (l895 + 1)) {
			fRec1277[l895] = 0.0f;
		}
		for (int l896 = 0; (l896 < 2); l896 = (l896 + 1)) {
			fRec1275[l896] = 0.0f;
		}
		for (int l897 = 0; (l897 < 2); l897 = (l897 + 1)) {
			fRec1274[l897] = 0.0f;
		}
		for (int l898 = 0; (l898 < 2); l898 = (l898 + 1)) {
			fRec1272[l898] = 0.0f;
		}
		for (int l899 = 0; (l899 < 2); l899 = (l899 + 1)) {
			fRec1271[l899] = 0.0f;
		}
		for (int l900 = 0; (l900 < 2); l900 = (l900 + 1)) {
			fRec1269[l900] = 0.0f;
		}
		for (int l901 = 0; (l901 < 2); l901 = (l901 + 1)) {
			fRec1280[l901] = 0.0f;
		}
		for (int l902 = 0; (l902 < 2); l902 = (l902 + 1)) {
			fRec1278[l902] = 0.0f;
		}
		for (int l903 = 0; (l903 < 2); l903 = (l903 + 1)) {
			fRec1286[l903] = 0.0f;
		}
		for (int l904 = 0; (l904 < 2); l904 = (l904 + 1)) {
			fRec1284[l904] = 0.0f;
		}
		for (int l905 = 0; (l905 < 2); l905 = (l905 + 1)) {
			fRec1283[l905] = 0.0f;
		}
		for (int l906 = 0; (l906 < 2); l906 = (l906 + 1)) {
			fRec1281[l906] = 0.0f;
		}
		for (int l907 = 0; (l907 < 1024); l907 = (l907 + 1)) {
			fVec40[l907] = 0.0f;
		}
		for (int l908 = 0; (l908 < 2); l908 = (l908 + 1)) {
			fRec1298[l908] = 0.0f;
		}
		for (int l909 = 0; (l909 < 2); l909 = (l909 + 1)) {
			fRec1296[l909] = 0.0f;
		}
		for (int l910 = 0; (l910 < 2); l910 = (l910 + 1)) {
			fRec1295[l910] = 0.0f;
		}
		for (int l911 = 0; (l911 < 2); l911 = (l911 + 1)) {
			fRec1293[l911] = 0.0f;
		}
		for (int l912 = 0; (l912 < 2); l912 = (l912 + 1)) {
			fRec1292[l912] = 0.0f;
		}
		for (int l913 = 0; (l913 < 2); l913 = (l913 + 1)) {
			fRec1290[l913] = 0.0f;
		}
		for (int l914 = 0; (l914 < 2); l914 = (l914 + 1)) {
			fRec1289[l914] = 0.0f;
		}
		for (int l915 = 0; (l915 < 2); l915 = (l915 + 1)) {
			fRec1287[l915] = 0.0f;
		}
		for (int l916 = 0; (l916 < 2); l916 = (l916 + 1)) {
			fRec1307[l916] = 0.0f;
		}
		for (int l917 = 0; (l917 < 2); l917 = (l917 + 1)) {
			fRec1305[l917] = 0.0f;
		}
		for (int l918 = 0; (l918 < 2); l918 = (l918 + 1)) {
			fRec1304[l918] = 0.0f;
		}
		for (int l919 = 0; (l919 < 2); l919 = (l919 + 1)) {
			fRec1302[l919] = 0.0f;
		}
		for (int l920 = 0; (l920 < 2); l920 = (l920 + 1)) {
			fRec1301[l920] = 0.0f;
		}
		for (int l921 = 0; (l921 < 2); l921 = (l921 + 1)) {
			fRec1299[l921] = 0.0f;
		}
		for (int l922 = 0; (l922 < 2); l922 = (l922 + 1)) {
			fRec1310[l922] = 0.0f;
		}
		for (int l923 = 0; (l923 < 2); l923 = (l923 + 1)) {
			fRec1308[l923] = 0.0f;
		}
		for (int l924 = 0; (l924 < 2); l924 = (l924 + 1)) {
			fRec1316[l924] = 0.0f;
		}
		for (int l925 = 0; (l925 < 2); l925 = (l925 + 1)) {
			fRec1314[l925] = 0.0f;
		}
		for (int l926 = 0; (l926 < 2); l926 = (l926 + 1)) {
			fRec1313[l926] = 0.0f;
		}
		for (int l927 = 0; (l927 < 2); l927 = (l927 + 1)) {
			fRec1311[l927] = 0.0f;
		}
		for (int l928 = 0; (l928 < 1024); l928 = (l928 + 1)) {
			fVec41[l928] = 0.0f;
		}
		for (int l929 = 0; (l929 < 2); l929 = (l929 + 1)) {
			fRec1328[l929] = 0.0f;
		}
		for (int l930 = 0; (l930 < 2); l930 = (l930 + 1)) {
			fRec1326[l930] = 0.0f;
		}
		for (int l931 = 0; (l931 < 2); l931 = (l931 + 1)) {
			fRec1325[l931] = 0.0f;
		}
		for (int l932 = 0; (l932 < 2); l932 = (l932 + 1)) {
			fRec1323[l932] = 0.0f;
		}
		for (int l933 = 0; (l933 < 2); l933 = (l933 + 1)) {
			fRec1322[l933] = 0.0f;
		}
		for (int l934 = 0; (l934 < 2); l934 = (l934 + 1)) {
			fRec1320[l934] = 0.0f;
		}
		for (int l935 = 0; (l935 < 2); l935 = (l935 + 1)) {
			fRec1319[l935] = 0.0f;
		}
		for (int l936 = 0; (l936 < 2); l936 = (l936 + 1)) {
			fRec1317[l936] = 0.0f;
		}
		for (int l937 = 0; (l937 < 2); l937 = (l937 + 1)) {
			fRec1337[l937] = 0.0f;
		}
		for (int l938 = 0; (l938 < 2); l938 = (l938 + 1)) {
			fRec1335[l938] = 0.0f;
		}
		for (int l939 = 0; (l939 < 2); l939 = (l939 + 1)) {
			fRec1334[l939] = 0.0f;
		}
		for (int l940 = 0; (l940 < 2); l940 = (l940 + 1)) {
			fRec1332[l940] = 0.0f;
		}
		for (int l941 = 0; (l941 < 2); l941 = (l941 + 1)) {
			fRec1331[l941] = 0.0f;
		}
		for (int l942 = 0; (l942 < 2); l942 = (l942 + 1)) {
			fRec1329[l942] = 0.0f;
		}
		for (int l943 = 0; (l943 < 2); l943 = (l943 + 1)) {
			fRec1340[l943] = 0.0f;
		}
		for (int l944 = 0; (l944 < 2); l944 = (l944 + 1)) {
			fRec1338[l944] = 0.0f;
		}
		for (int l945 = 0; (l945 < 2); l945 = (l945 + 1)) {
			fRec1346[l945] = 0.0f;
		}
		for (int l946 = 0; (l946 < 2); l946 = (l946 + 1)) {
			fRec1344[l946] = 0.0f;
		}
		for (int l947 = 0; (l947 < 2); l947 = (l947 + 1)) {
			fRec1343[l947] = 0.0f;
		}
		for (int l948 = 0; (l948 < 2); l948 = (l948 + 1)) {
			fRec1341[l948] = 0.0f;
		}
		for (int l949 = 0; (l949 < 1024); l949 = (l949 + 1)) {
			fVec42[l949] = 0.0f;
		}
		for (int l950 = 0; (l950 < 2); l950 = (l950 + 1)) {
			fRec1358[l950] = 0.0f;
		}
		for (int l951 = 0; (l951 < 2); l951 = (l951 + 1)) {
			fRec1356[l951] = 0.0f;
		}
		for (int l952 = 0; (l952 < 2); l952 = (l952 + 1)) {
			fRec1355[l952] = 0.0f;
		}
		for (int l953 = 0; (l953 < 2); l953 = (l953 + 1)) {
			fRec1353[l953] = 0.0f;
		}
		for (int l954 = 0; (l954 < 2); l954 = (l954 + 1)) {
			fRec1352[l954] = 0.0f;
		}
		for (int l955 = 0; (l955 < 2); l955 = (l955 + 1)) {
			fRec1350[l955] = 0.0f;
		}
		for (int l956 = 0; (l956 < 2); l956 = (l956 + 1)) {
			fRec1349[l956] = 0.0f;
		}
		for (int l957 = 0; (l957 < 2); l957 = (l957 + 1)) {
			fRec1347[l957] = 0.0f;
		}
		for (int l958 = 0; (l958 < 2); l958 = (l958 + 1)) {
			fRec1367[l958] = 0.0f;
		}
		for (int l959 = 0; (l959 < 2); l959 = (l959 + 1)) {
			fRec1365[l959] = 0.0f;
		}
		for (int l960 = 0; (l960 < 2); l960 = (l960 + 1)) {
			fRec1364[l960] = 0.0f;
		}
		for (int l961 = 0; (l961 < 2); l961 = (l961 + 1)) {
			fRec1362[l961] = 0.0f;
		}
		for (int l962 = 0; (l962 < 2); l962 = (l962 + 1)) {
			fRec1361[l962] = 0.0f;
		}
		for (int l963 = 0; (l963 < 2); l963 = (l963 + 1)) {
			fRec1359[l963] = 0.0f;
		}
		for (int l964 = 0; (l964 < 2); l964 = (l964 + 1)) {
			fRec1370[l964] = 0.0f;
		}
		for (int l965 = 0; (l965 < 2); l965 = (l965 + 1)) {
			fRec1368[l965] = 0.0f;
		}
		for (int l966 = 0; (l966 < 2); l966 = (l966 + 1)) {
			fRec1376[l966] = 0.0f;
		}
		for (int l967 = 0; (l967 < 2); l967 = (l967 + 1)) {
			fRec1374[l967] = 0.0f;
		}
		for (int l968 = 0; (l968 < 2); l968 = (l968 + 1)) {
			fRec1373[l968] = 0.0f;
		}
		for (int l969 = 0; (l969 < 2); l969 = (l969 + 1)) {
			fRec1371[l969] = 0.0f;
		}
		for (int l970 = 0; (l970 < 1024); l970 = (l970 + 1)) {
			fVec43[l970] = 0.0f;
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
		ui_interface->openVerticalBox("KMHLS_FullSetup_4h3v_full_1");
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
		FAUSTFLOAT* input16 = inputs[16];
		FAUSTFLOAT* input17 = inputs[17];
		FAUSTFLOAT* input18 = inputs[18];
		FAUSTFLOAT* input19 = inputs[19];
		FAUSTFLOAT* input20 = inputs[20];
		FAUSTFLOAT* input21 = inputs[21];
		FAUSTFLOAT* input22 = inputs[22];
		FAUSTFLOAT* input23 = inputs[23];
		FAUSTFLOAT* input24 = inputs[24];
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
			float fTemp7 = (((fTemp1 * (fRec2[2] + (fRec2[0] + (2.0f * fRec2[1])))) / fTemp5) + (fRec3[0] * (0.0f - ((fRec2[1] * fTemp6) + ((fRec2[0] + fRec2[2]) / fTemp4)))));
			float fTemp8 = (fConst3 * (0.0f - ((fConst5 * fRec7[1]) + (fConst4 * fRec4[1]))));
			fRec16[0] = (float(input16[i]) - (((fTemp2 * fRec16[2]) + (2.0f * (fTemp3 * fRec16[1]))) / fTemp4));
			float fTemp9 = (((fTemp1 * (fRec16[2] + (fRec16[0] + (2.0f * fRec16[1])))) / fTemp5) + (0.245735466f * (fRec3[0] * (0.0f - ((fTemp6 * fRec16[1]) + ((fRec16[0] + fRec16[2]) / fTemp4))))));
			fRec17[0] = (float(input17[i]) - (((fTemp2 * fRec17[2]) + (2.0f * (fTemp3 * fRec17[1]))) / fTemp4));
			float fTemp10 = (((fTemp1 * (fRec17[2] + (fRec17[0] + (2.0f * fRec17[1])))) / fTemp5) + (0.245735466f * (fRec3[0] * (0.0f - ((fTemp6 * fRec17[1]) + ((fRec17[0] + fRec17[2]) / fTemp4))))));
			fRec18[0] = (float(input18[i]) - (((fTemp2 * fRec18[2]) + (2.0f * (fTemp3 * fRec18[1]))) / fTemp4));
			float fTemp11 = (((fTemp1 * (fRec18[2] + (fRec18[0] + (2.0f * fRec18[1])))) / fTemp5) + (0.245735466f * (fRec3[0] * (0.0f - ((fTemp6 * fRec18[1]) + ((fRec18[0] + fRec18[2]) / fTemp4))))));
			fRec19[0] = (float(input19[i]) - (((fTemp2 * fRec19[2]) + (2.0f * (fTemp3 * fRec19[1]))) / fTemp4));
			float fTemp12 = (((fTemp1 * (fRec19[2] + (fRec19[0] + (2.0f * fRec19[1])))) / fTemp5) + (0.245735466f * (fRec3[0] * (0.0f - ((fTemp6 * fRec19[1]) + ((fRec19[0] + fRec19[2]) / fTemp4))))));
			fRec20[0] = (float(input21[i]) - (((fTemp2 * fRec20[2]) + (2.0f * (fTemp3 * fRec20[1]))) / fTemp4));
			float fTemp13 = (((fTemp1 * (fRec20[2] + (fRec20[0] + (2.0f * fRec20[1])))) / fTemp5) + (0.245735466f * (fRec3[0] * (0.0f - ((fTemp6 * fRec20[1]) + ((fRec20[0] + fRec20[2]) / fTemp4))))));
			fRec21[0] = (float(input22[i]) - (((fTemp2 * fRec21[2]) + (2.0f * (fTemp3 * fRec21[1]))) / fTemp4));
			float fTemp14 = (((fTemp1 * (fRec21[2] + (fRec21[0] + (2.0f * fRec21[1])))) / fTemp5) + (0.245735466f * (fRec3[0] * (0.0f - ((fTemp6 * fRec21[1]) + ((fRec21[0] + fRec21[2]) / fTemp4))))));
			fRec22[0] = (float(input23[i]) - (((fTemp2 * fRec22[2]) + (2.0f * (fTemp3 * fRec22[1]))) / fTemp4));
			float fTemp15 = (((fTemp1 * (fRec22[2] + (fRec22[0] + (2.0f * fRec22[1])))) / fTemp5) + (0.245735466f * (fRec3[0] * (0.0f - ((fTemp6 * fRec22[1]) + ((fRec22[0] + fRec22[2]) / fTemp4))))));
			fRec23[0] = (float(input24[i]) - (((fTemp2 * fRec23[2]) + (2.0f * (fTemp3 * fRec23[1]))) / fTemp4));
			float fTemp16 = (((fTemp1 * (fRec23[2] + (fRec23[0] + (2.0f * fRec23[1])))) / fTemp5) + (0.245735466f * (fRec3[0] * (0.0f - ((fTemp6 * fRec23[1]) + ((fRec23[0] + fRec23[2]) / fTemp4))))));
			float fTemp17 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec13[1]) + (fConst8 * fRec10[1])))) + (fConst10 * (((0.0394563787f * fTemp9) + (0.0579505228f * fTemp10)) - ((((((0.0250783768f * fTemp11) + (0.0402620472f * fTemp12)) + (0.0515151881f * fTemp13)) + (0.0104138283f * fTemp14)) + (0.0275033414f * fTemp15)) + (0.0644419044f * fTemp16))))));
			fRec15[0] = (fRec15[1] + fTemp17);
			fRec13[0] = fRec15[0];
			float fRec14 = fTemp17;
			fRec12[0] = (fRec13[0] + fRec12[1]);
			fRec10[0] = fRec12[0];
			float fRec11 = fRec14;
			fRec9[0] = (fTemp8 + (fRec11 + fRec9[1]));
			fRec7[0] = fRec9[0];
			float fRec8 = (fRec11 + fTemp8);
			fRec6[0] = (fRec7[0] + fRec6[1]);
			fRec4[0] = fRec6[0];
			float fRec5 = fRec8;
			fRec33[0] = (float(input9[i]) - (((fTemp2 * fRec33[2]) + (2.0f * (fTemp3 * fRec33[1]))) / fTemp4));
			float fTemp18 = (((fTemp1 * (fRec33[2] + (fRec33[0] + (2.0f * fRec33[1])))) / fTemp5) + (0.50103116f * (fRec3[0] * (0.0f - ((fTemp6 * fRec33[1]) + ((fRec33[0] + fRec33[2]) / fTemp4))))));
			fRec34[0] = (float(input10[i]) - (((fTemp2 * fRec34[2]) + (2.0f * (fTemp3 * fRec34[1]))) / fTemp4));
			float fTemp19 = (((fTemp1 * (fRec34[2] + (fRec34[0] + (2.0f * fRec34[1])))) / fTemp5) + (0.50103116f * (fRec3[0] * (0.0f - ((fTemp6 * fRec34[1]) + ((fRec34[0] + fRec34[2]) / fTemp4))))));
			fRec35[0] = (float(input14[i]) - (((fTemp2 * fRec35[2]) + (2.0f * (fTemp3 * fRec35[1]))) / fTemp4));
			float fTemp20 = (((fTemp1 * (fRec35[2] + (fRec35[0] + (2.0f * fRec35[1])))) / fTemp5) + (0.50103116f * (fRec3[0] * (0.0f - ((fTemp6 * fRec35[1]) + ((fRec35[0] + fRec35[2]) / fTemp4))))));
			fRec36[0] = (float(input11[i]) - (((fTemp2 * fRec36[2]) + (2.0f * (fTemp3 * fRec36[1]))) / fTemp4));
			float fTemp21 = (((fTemp1 * (fRec36[2] + (fRec36[0] + (2.0f * fRec36[1])))) / fTemp5) + (0.50103116f * (fRec3[0] * (0.0f - ((fTemp6 * fRec36[1]) + ((fRec36[0] + fRec36[2]) / fTemp4))))));
			fRec37[0] = (float(input12[i]) - (((fTemp2 * fRec37[2]) + (2.0f * (fTemp3 * fRec37[1]))) / fTemp4));
			float fTemp22 = (((fTemp1 * (fRec37[2] + (fRec37[0] + (2.0f * fRec37[1])))) / fTemp5) + (0.50103116f * (fRec3[0] * (0.0f - ((fTemp6 * fRec37[1]) + ((fRec37[0] + fRec37[2]) / fTemp4))))));
			fRec38[0] = (float(input13[i]) - (((fTemp2 * fRec38[2]) + (2.0f * (fTemp3 * fRec38[1]))) / fTemp4));
			float fTemp23 = (((fTemp1 * (fRec38[2] + (fRec38[0] + (2.0f * fRec38[1])))) / fTemp5) + (0.50103116f * (fRec3[0] * (0.0f - ((fTemp6 * fRec38[1]) + ((fRec38[0] + fRec38[2]) / fTemp4))))));
			fRec39[0] = (float(input15[i]) - (((fTemp2 * fRec39[2]) + (2.0f * (fTemp3 * fRec39[1]))) / fTemp4));
			float fTemp24 = (((fTemp1 * (fRec39[2] + (fRec39[0] + (2.0f * fRec39[1])))) / fTemp5) + (0.50103116f * (fRec3[0] * (0.0f - ((fTemp6 * fRec39[1]) + ((fRec39[0] + fRec39[2]) / fTemp4))))));
			float fTemp25 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec30[1]) + (fConst12 * fRec27[1])))) + (fConst15 * ((((0.0673834756f * fTemp18) + (0.0523507334f * fTemp19)) + (0.0118537247f * fTemp20)) - ((((0.0211637877f * fTemp21) + (0.0395116508f * fTemp22)) + (0.0295264963f * fTemp23)) + (0.0270355083f * fTemp24))))));
			fRec32[0] = (fRec32[1] + fTemp25);
			fRec30[0] = fRec32[0];
			float fRec31 = fTemp25;
			fRec29[0] = (fRec30[0] + fRec29[1]);
			fRec27[0] = fRec29[0];
			float fRec28 = fRec31;
			float fTemp26 = (fConst16 * fRec24[1]);
			fRec26[0] = ((fRec28 + fRec26[1]) - fTemp26);
			fRec24[0] = fRec26[0];
			float fRec25 = (fRec28 - fTemp26);
			fRec43[0] = (float(input1[i]) - (((fTemp2 * fRec43[2]) + (2.0f * (fTemp3 * fRec43[1]))) / fTemp4));
			float fTemp27 = (((fTemp1 * (fRec43[2] + (fRec43[0] + (2.0f * fRec43[1])))) / fTemp5) + (0.906179845f * (fRec3[0] * (0.0f - ((fTemp6 * fRec43[1]) + ((fRec43[0] + fRec43[2]) / fTemp4))))));
			fRec44[0] = (float(input2[i]) - (((fTemp2 * fRec44[2]) + (2.0f * (fTemp3 * fRec44[1]))) / fTemp4));
			float fTemp28 = (((fTemp1 * (fRec44[2] + (fRec44[0] + (2.0f * fRec44[1])))) / fTemp5) + (0.906179845f * (fRec3[0] * (0.0f - ((fTemp6 * fRec44[1]) + ((fRec44[0] + fRec44[2]) / fTemp4))))));
			fRec45[0] = (float(input3[i]) - (((fTemp2 * fRec45[2]) + (2.0f * (fTemp3 * fRec45[1]))) / fTemp4));
			float fTemp29 = (((fTemp1 * (fRec45[2] + (fRec45[0] + (2.0f * fRec45[1])))) / fTemp5) + (0.906179845f * (fRec3[0] * (0.0f - ((fTemp6 * fRec45[1]) + ((fRec45[0] + fRec45[2]) / fTemp4))))));
			float fTemp30 = (fConst17 * ((((0.0296654552f * fTemp27) + (0.0146881239f * fTemp28)) + (0.0385625586f * fTemp29)) - (fConst18 * fRec40[1])));
			fRec42[0] = (fRec42[1] + fTemp30);
			fRec40[0] = fRec42[0];
			float fRec41 = fTemp30;
			fRec52[0] = (float(input4[i]) - (((fTemp2 * fRec52[2]) + (2.0f * (fTemp3 * fRec52[1]))) / fTemp4));
			float fTemp31 = (((fTemp1 * (fRec52[2] + (fRec52[0] + (2.0f * fRec52[1])))) / fTemp5) + (0.731742859f * (fRec3[0] * (0.0f - ((fTemp6 * fRec52[1]) + ((fRec52[0] + fRec52[2]) / fTemp4))))));
			fRec53[0] = (float(input5[i]) - (((fTemp2 * fRec53[2]) + (2.0f * (fTemp3 * fRec53[1]))) / fTemp4));
			float fTemp32 = (((fTemp1 * (fRec53[2] + (fRec53[0] + (2.0f * fRec53[1])))) / fTemp5) + (0.731742859f * (fRec3[0] * (0.0f - ((fTemp6 * fRec53[1]) + ((fRec53[0] + fRec53[2]) / fTemp4))))));
			fRec54[0] = (float(input7[i]) - (((fTemp2 * fRec54[2]) + (2.0f * (fTemp3 * fRec54[1]))) / fTemp4));
			float fTemp33 = (((fTemp1 * (fRec54[2] + (fRec54[0] + (2.0f * fRec54[1])))) / fTemp5) + (0.731742859f * (fRec3[0] * (0.0f - ((fTemp6 * fRec54[1]) + ((fRec54[0] + fRec54[2]) / fTemp4))))));
			fRec55[0] = (float(input8[i]) - (((fTemp2 * fRec55[2]) + (2.0f * (fTemp3 * fRec55[1]))) / fTemp4));
			float fTemp34 = (((fTemp1 * (fRec55[2] + (fRec55[0] + (2.0f * fRec55[1])))) / fTemp5) + (0.731742859f * (fRec3[0] * (0.0f - ((fTemp6 * fRec55[1]) + ((fRec55[0] + fRec55[2]) / fTemp4))))));
			fRec56[0] = (float(input6[i]) - (((fTemp2 * fRec56[2]) + (2.0f * (fTemp3 * fRec56[1]))) / fTemp4));
			float fTemp35 = (((fTemp1 * (fRec56[2] + (fRec56[0] + (2.0f * fRec56[1])))) / fTemp5) + (0.731742859f * (fRec3[0] * (0.0f - ((fTemp6 * fRec56[1]) + ((fRec56[0] + fRec56[2]) / fTemp4))))));
			float fTemp36 = (fConst19 * ((((((0.0617547408f * fTemp31) + (0.0242265668f * fTemp32)) + (0.030165527f * fTemp33)) + (0.0167007241f * fTemp34)) - (0.030420443f * fTemp35)) + (fConst7 * (0.0f - ((fConst21 * fRec49[1]) + (fConst20 * fRec46[1]))))));
			fRec51[0] = (fRec51[1] + fTemp36);
			fRec49[0] = fRec51[0];
			float fRec50 = fTemp36;
			fRec48[0] = (fRec49[0] + fRec48[1]);
			fRec46[0] = fRec48[0];
			float fRec47 = fRec50;
			fVec0[(IOTA & 1023)] = ((0.0173517056f * fTemp7) + (fRec5 + (fRec25 + (fRec41 + fRec47))));
			output0[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec0[((IOTA - iConst22) & 1023)])));
			float fTemp37 = (fConst3 * (0.0f - ((fConst5 * fRec60[1]) + (fConst4 * fRec57[1]))));
			float fTemp38 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec66[1]) + (fConst8 * fRec63[1])))) + (fConst10 * (((((0.049124822f * fTemp9) + (0.0270991586f * fTemp10)) + (0.0297486428f * fTemp15)) + (0.0358915702f * fTemp16)) - ((((0.0137353744f * fTemp11) + (0.0102913305f * fTemp12)) + (0.0416733101f * fTemp13)) + (0.0291500948f * fTemp14))))));
			fRec68[0] = (fRec68[1] + fTemp38);
			fRec66[0] = fRec68[0];
			float fRec67 = fTemp38;
			fRec65[0] = (fRec66[0] + fRec65[1]);
			fRec63[0] = fRec65[0];
			float fRec64 = fRec67;
			fRec62[0] = (fTemp37 + (fRec64 + fRec62[1]));
			fRec60[0] = fRec62[0];
			float fRec61 = (fRec64 + fTemp37);
			fRec59[0] = (fRec60[0] + fRec59[1]);
			fRec57[0] = fRec59[0];
			float fRec58 = fRec61;
			float fTemp39 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec75[1]) + (fConst12 * fRec72[1])))) + (fConst15 * (((((0.0362625085f * fTemp18) + (0.0150859253f * fTemp19)) + (0.0280507114f * fTemp20)) + (0.0425728336f * fTemp24)) - (((0.0077984971f * fTemp21) + (0.0239365809f * fTemp22)) + (0.0338370018f * fTemp23))))));
			fRec77[0] = (fRec77[1] + fTemp39);
			fRec75[0] = fRec77[0];
			float fRec76 = fTemp39;
			fRec74[0] = (fRec75[0] + fRec74[1]);
			fRec72[0] = fRec74[0];
			float fRec73 = fRec76;
			float fTemp40 = (fConst16 * fRec69[1]);
			fRec71[0] = ((fRec73 + fRec71[1]) - fTemp40);
			fRec69[0] = fRec71[0];
			float fRec70 = (fRec73 - fTemp40);
			float fTemp41 = (fConst17 * ((((0.00816663075f * fTemp27) + (0.0080504287f * fTemp28)) + (0.0339480191f * fTemp29)) - (fConst18 * fRec78[1])));
			fRec80[0] = (fRec80[1] + fTemp41);
			fRec78[0] = fRec80[0];
			float fRec79 = fTemp41;
			float fTemp42 = (fConst19 * ((((((0.0215195566f * fTemp31) + (0.00537396781f * fTemp32)) + (0.0212768037f * fTemp33)) + (0.0422492512f * fTemp34)) - (0.0246715266f * fTemp35)) + (fConst7 * (0.0f - ((fConst21 * fRec84[1]) + (fConst20 * fRec81[1]))))));
			fRec86[0] = (fRec86[1] + fTemp42);
			fRec84[0] = fRec86[0];
			float fRec85 = fTemp42;
			fRec83[0] = (fRec84[0] + fRec83[1]);
			fRec81[0] = fRec83[0];
			float fRec82 = fRec85;
			fVec1[(IOTA & 1023)] = ((0.0121423434f * fTemp7) + (fRec58 + (fRec70 + (fRec79 + fRec82))));
			output1[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec1[((IOTA - iConst22) & 1023)])));
			float fTemp43 = (fConst3 * (0.0f - ((fConst5 * fRec90[1]) + (fConst4 * fRec87[1]))));
			float fTemp44 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec96[1]) + (fConst8 * fRec93[1])))) + (fConst10 * (((((0.0106972763f * fTemp11) + (0.00826617796f * fTemp12)) + (0.0603492744f * fTemp15)) + (0.0640957803f * fTemp16)) - ((((0.0406568721f * fTemp9) + (0.0223544966f * fTemp10)) + (0.065294005f * fTemp13)) + (0.0254706908f * fTemp14))))));
			fRec98[0] = (fRec98[1] + fTemp44);
			fRec96[0] = fRec98[0];
			float fRec97 = fTemp44;
			fRec95[0] = (fRec96[0] + fRec95[1]);
			fRec93[0] = fRec95[0];
			float fRec94 = fRec97;
			fRec92[0] = (fTemp43 + (fRec94 + fRec92[1]));
			fRec90[0] = fRec92[0];
			float fRec91 = (fRec94 + fTemp43);
			fRec89[0] = (fRec90[0] + fRec89[1]);
			fRec87[0] = fRec89[0];
			float fRec88 = fRec91;
			float fTemp45 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec105[1]) + (fConst12 * fRec102[1])))) + (fConst15 * ((((0.00610694848f * fTemp21) + (0.052434966f * fTemp20)) + (0.0668049157f * fTemp24)) - ((((0.0295073614f * fTemp18) + (0.0123431636f * fTemp19)) + (0.0397145003f * fTemp22)) + (0.0362964757f * fTemp23))))));
			fRec107[0] = (fRec107[1] + fTemp45);
			fRec105[0] = fRec107[0];
			float fRec106 = fTemp45;
			fRec104[0] = (fRec105[0] + fRec104[1]);
			fRec102[0] = fRec104[0];
			float fRec103 = fRec106;
			float fTemp46 = (fConst16 * fRec99[1]);
			fRec101[0] = ((fRec103 + fRec101[1]) - fTemp46);
			fRec99[0] = fRec101[0];
			float fRec100 = (fRec103 - fTemp46);
			float fTemp47 = (fConst17 * ((((0.0147326542f * fTemp28) + (0.0485469438f * fTemp29)) - (0.00653544394f * fTemp27)) - (fConst18 * fRec108[1])));
			fRec110[0] = (fRec110[1] + fTemp47);
			fRec108[0] = fRec110[0];
			float fRec109 = fTemp47;
			float fTemp48 = (fConst19 * ((((0.0385758057f * fTemp33) + (0.0620233566f * fTemp34)) - (((0.0173188131f * fTemp31) + (0.00438161939f * fTemp32)) + (0.0307154115f * fTemp35))) + (fConst7 * (0.0f - ((fConst21 * fRec114[1]) + (fConst20 * fRec111[1]))))));
			fRec116[0] = (fRec116[1] + fTemp48);
			fRec114[0] = fRec116[0];
			float fRec115 = fTemp48;
			fRec113[0] = (fRec114[0] + fRec113[1]);
			fRec111[0] = fRec113[0];
			float fRec112 = fRec115;
			fVec2[(IOTA & 1023)] = ((0.0174661018f * fTemp7) + (fRec88 + (fRec100 + (fRec109 + fRec112))));
			output2[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec2[((IOTA - iConst22) & 1023)])));
			float fTemp49 = (fConst3 * (0.0f - ((fConst5 * fRec120[1]) + (fConst4 * fRec117[1]))));
			float fTemp50 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec126[1]) + (fConst8 * fRec123[1])))) + (fConst10 * (((0.0293770134f * fTemp11) + (0.0223984048f * fTemp12)) - ((((((0.0484765582f * fTemp9) + (0.0402277522f * fTemp10)) + (0.0367160067f * fTemp13)) + (0.0134639451f * fTemp14)) + (0.00240833941f * fTemp15)) + (0.0368961543f * fTemp16))))));
			fRec128[0] = (fRec128[1] + fTemp50);
			fRec126[0] = fRec128[0];
			float fRec127 = fTemp50;
			fRec125[0] = (fRec126[0] + fRec125[1]);
			fRec123[0] = fRec125[0];
			float fRec124 = fRec127;
			fRec122[0] = (fTemp49 + (fRec124 + fRec122[1]));
			fRec120[0] = fRec122[0];
			float fRec121 = (fRec124 + fTemp49);
			fRec119[0] = (fRec120[0] + fRec119[1]);
			fRec117[0] = fRec119[0];
			float fRec118 = fRec121;
			float fTemp51 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec135[1]) + (fConst12 * fRec132[1])))) + (fConst15 * (((0.0186099615f * fTemp21) + (0.0148658184f * fTemp20)) - (((((0.0557727441f * fTemp18) + (0.0282275621f * fTemp19)) + (0.0239814557f * fTemp22)) + (0.02942512f * fTemp23)) + (0.0052783764f * fTemp24))))));
			fRec137[0] = (fRec137[1] + fTemp51);
			fRec135[0] = fRec137[0];
			float fRec136 = fTemp51;
			fRec134[0] = (fRec135[0] + fRec134[1]);
			fRec132[0] = fRec134[0];
			float fRec133 = fRec136;
			float fTemp52 = (fConst16 * fRec129[1]);
			fRec131[0] = ((fRec133 + fRec131[1]) - fTemp52);
			fRec129[0] = fRec131[0];
			float fRec130 = (fRec133 - fTemp52);
			float fTemp53 = (fConst17 * ((((0.00806470029f * fTemp28) + (0.0297580194f * fTemp29)) - (0.0184110664f * fTemp27)) - (fConst18 * fRec138[1])));
			fRec140[0] = (fRec140[1] + fTemp53);
			fRec138[0] = fRec140[0];
			float fRec139 = fTemp53;
			float fTemp54 = (fConst19 * ((((0.0188293606f * fTemp33) + (0.021158427f * fTemp34)) - (((0.0425395072f * fTemp31) + (0.0113458643f * fTemp32)) + (0.0247318652f * fTemp35))) + (fConst7 * (0.0f - ((fConst21 * fRec144[1]) + (fConst20 * fRec141[1]))))));
			fRec146[0] = (fRec146[1] + fTemp54);
			fRec144[0] = fRec146[0];
			float fRec145 = fTemp54;
			fRec143[0] = (fRec144[0] + fRec143[1]);
			fRec141[0] = fRec143[0];
			float fRec142 = fRec145;
			fVec3[(IOTA & 1023)] = ((0.0121692494f * fTemp7) + (fRec118 + (fRec130 + (fRec139 + fRec142))));
			output3[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec3[((IOTA - iConst22) & 1023)])));
			float fTemp55 = (fConst3 * (0.0f - ((fConst5 * fRec150[1]) + (fConst4 * fRec147[1]))));
			float fTemp56 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec156[1]) + (fConst8 * fRec153[1])))) + (fConst10 * (((((0.0436552912f * fTemp9) + (0.0253995117f * fTemp11)) + (0.0533820018f * fTemp12)) + (0.0113062784f * fTemp14)) - ((((0.0253554136f * fTemp10) + (0.0404762588f * fTemp13)) + (0.0602009632f * fTemp15)) + (0.0629265383f * fTemp16))))));
			fRec158[0] = (fRec158[1] + fTemp56);
			fRec156[0] = fRec158[0];
			float fRec157 = fTemp56;
			fRec155[0] = (fRec156[0] + fRec155[1]);
			fRec153[0] = fRec155[0];
			float fRec154 = fRec157;
			fRec152[0] = (fTemp55 + (fRec154 + fRec152[1]));
			fRec150[0] = fRec152[0];
			float fRec151 = (fRec154 + fTemp55);
			fRec149[0] = (fRec150[0] + fRec149[1]);
			fRec147[0] = fRec149[0];
			float fRec148 = fRec151;
			float fTemp57 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec165[1]) + (fConst12 * fRec162[1])))) + (fConst15 * ((0.0305635892f * fTemp21) - ((((((0.0245526321f * fTemp18) + (0.0531047024f * fTemp19)) + (0.0404913984f * fTemp22)) + (0.0212846231f * fTemp23)) + (0.0137054212f * fTemp20)) + (0.0697592795f * fTemp24))))));
			fRec167[0] = (fRec167[1] + fTemp57);
			fRec165[0] = fRec167[0];
			float fRec166 = fTemp57;
			fRec164[0] = (fRec165[0] + fRec164[1]);
			fRec162[0] = fRec164[0];
			float fRec163 = fRec166;
			float fTemp58 = (fConst16 * fRec159[1]);
			fRec161[0] = ((fRec163 + fRec161[1]) - fTemp58);
			fRec159[0] = fRec161[0];
			float fRec160 = (fRec163 - fTemp58);
			float fTemp59 = (fConst17 * ((((0.0150436228f * fTemp28) + (0.0297978744f * fTemp29)) - (0.0399229303f * fTemp27)) - (fConst18 * fRec168[1])));
			fRec170[0] = (fRec170[1] + fTemp59);
			fRec168[0] = fRec170[0];
			float fRec169 = fTemp59;
			float fTemp60 = (fConst19 * (((0.0243329648f * fTemp33) - ((((0.0625922978f * fTemp31) + (0.0312496126f * fTemp32)) + (0.0311855748f * fTemp35)) + (0.018886555f * fTemp34))) + (fConst7 * (0.0f - ((fConst21 * fRec174[1]) + (fConst20 * fRec171[1]))))));
			fRec176[0] = (fRec176[1] + fTemp60);
			fRec174[0] = fRec176[0];
			float fRec175 = fTemp60;
			fRec173[0] = (fRec174[0] + fRec173[1]);
			fRec171[0] = fRec173[0];
			float fRec172 = fRec175;
			fVec4[(IOTA & 1023)] = ((0.0177769475f * fTemp7) + (fRec148 + (fRec160 + (fRec169 + fRec172))));
			output4[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec4[((IOTA - iConst22) & 1023)])));
			float fTemp61 = (fConst3 * (0.0f - ((fConst5 * fRec180[1]) + (fConst4 * fRec177[1]))));
			float fTemp62 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec186[1]) + (fConst8 * fRec183[1])))) + (fConst10 * (((((((0.0466255322f * fTemp9) + (0.03151628f * fTemp10)) + (0.0128109688f * fTemp11)) + (0.0423666909f * fTemp12)) + (0.0300514605f * fTemp14)) + (0.0398196951f * fTemp16)) - ((0.00962964911f * fTemp13) + (0.0256163385f * fTemp15))))));
			fRec188[0] = (fRec188[1] + fTemp62);
			fRec186[0] = fRec188[0];
			float fRec187 = fTemp62;
			fRec185[0] = (fRec186[0] + fRec185[1]);
			fRec183[0] = fRec185[0];
			float fRec184 = fRec187;
			fRec182[0] = (fTemp61 + (fRec184 + fRec182[1]));
			fRec180[0] = fRec182[0];
			float fRec181 = (fRec184 + fTemp61);
			fRec179[0] = (fRec180[0] + fRec179[1]);
			fRec177[0] = fRec179[0];
			float fRec178 = fRec181;
			float fTemp63 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec195[1]) + (fConst12 * fRec192[1])))) + (fConst15 * (((0.0450030789f * fTemp18) + (0.0344489776f * fTemp21)) - (((((0.014167075f * fTemp19) + (0.0242176168f * fTemp22)) + (0.00726349186f * fTemp23)) + (0.0288920309f * fTemp20)) + (0.0341287479f * fTemp24))))));
			fRec197[0] = (fRec197[1] + fTemp63);
			fRec195[0] = fRec197[0];
			float fRec196 = fTemp63;
			fRec194[0] = (fRec195[0] + fRec194[1]);
			fRec192[0] = fRec194[0];
			float fRec193 = fRec196;
			float fTemp64 = (fConst16 * fRec189[1]);
			fRec191[0] = ((fRec193 + fRec191[1]) - fTemp64);
			fRec189[0] = fRec191[0];
			float fRec190 = (fRec193 - fTemp64);
			float fTemp65 = (fConst17 * ((((0.00813698862f * fTemp28) + (0.0076172282f * fTemp29)) - (0.0345108211f * fTemp27)) - (fConst18 * fRec198[1])));
			fRec200[0] = (fRec200[1] + fTemp65);
			fRec198[0] = fRec200[0];
			float fRec199 = fTemp65;
			float fTemp66 = (fConst19 * (((0.00502709905f * fTemp33) - ((((0.0201381575f * fTemp31) + (0.0216047168f * fTemp32)) + (0.0249998309f * fTemp35)) + (0.0435210988f * fTemp34))) + (fConst7 * (0.0f - ((fConst21 * fRec204[1]) + (fConst20 * fRec201[1]))))));
			fRec206[0] = (fRec206[1] + fTemp66);
			fRec204[0] = fRec206[0];
			float fRec205 = fTemp66;
			fRec203[0] = (fRec204[0] + fRec203[1]);
			fRec201[0] = fRec203[0];
			float fRec202 = fRec205;
			fVec5[(IOTA & 1023)] = ((0.0122919185f * fTemp7) + (fRec178 + (fRec190 + (fRec199 + fRec202))));
			output5[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec5[((IOTA - iConst22) & 1023)])));
			float fTemp67 = (fConst3 * (0.0f - ((fConst5 * fRec210[1]) + (fConst4 * fRec207[1]))));
			float fTemp68 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec216[1]) + (fConst8 * fRec213[1])))) + (fConst10 * (((((((0.0593248717f * fTemp10) + (0.0668677092f * fTemp12)) + (0.0106335012f * fTemp13)) + (0.0251970477f * fTemp14)) + (0.0286671594f * fTemp15)) + (0.0595849119f * fTemp16)) - ((0.0489922538f * fTemp9) + (0.0123857744f * fTemp11))))));
			fRec218[0] = (fRec218[1] + fTemp68);
			fRec216[0] = fRec218[0];
			float fRec217 = fTemp68;
			fRec215[0] = (fRec216[0] + fRec215[1]);
			fRec213[0] = fRec215[0];
			float fRec214 = fRec217;
			fRec212[0] = (fTemp67 + (fRec214 + fRec212[1]));
			fRec210[0] = fRec212[0];
			float fRec211 = (fRec214 + fTemp67);
			fRec209[0] = (fRec210[0] + fRec209[1]);
			fRec207[0] = fRec209[0];
			float fRec208 = fRec211;
			float fTemp69 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec225[1]) + (fConst12 * fRec222[1])))) + (fConst15 * ((((((0.0651763231f * fTemp18) + (0.016109718f * fTemp19)) + (0.0369253568f * fTemp21)) + (0.00736948475f * fTemp23)) + (0.0363413543f * fTemp24)) - ((0.0409364887f * fTemp22) + (0.0530006774f * fTemp20))))));
			fRec227[0] = (fRec227[1] + fTemp69);
			fRec225[0] = fRec227[0];
			float fRec226 = fTemp69;
			fRec224[0] = (fRec225[0] + fRec224[1]);
			fRec222[0] = fRec224[0];
			float fRec223 = fRec226;
			float fTemp70 = (fConst16 * fRec219[1]);
			fRec221[0] = ((fRec223 + fRec221[1]) - fTemp70);
			fRec219[0] = fRec221[0];
			float fRec220 = (fRec223 - fTemp70);
			float fTemp71 = (fConst17 * (((0.0152102625f * fTemp28) - ((0.049679745f * fTemp27) + (0.00827172492f * fTemp29))) - (fConst18 * fRec228[1])));
			fRec230[0] = (fRec230[1] + fTemp71);
			fRec228[0] = fRec230[0];
			float fRec229 = fTemp71;
			float fTemp72 = (fConst19 * (((0.0216787122f * fTemp31) - ((((0.0396130756f * fTemp32) + (0.0315349884f * fTemp35)) + (0.00579079986f * fTemp33)) + (0.0623923056f * fTemp34))) + (fConst7 * (0.0f - ((fConst21 * fRec234[1]) + (fConst20 * fRec231[1]))))));
			fRec236[0] = (fRec236[1] + fTemp72);
			fRec234[0] = fRec236[0];
			float fRec235 = fTemp72;
			fRec233[0] = (fRec234[0] + fRec233[1]);
			fRec231[0] = fRec233[0];
			float fRec232 = fRec235;
			fVec6[(IOTA & 1023)] = ((0.0179759711f * fTemp7) + (fRec208 + (fRec220 + (fRec229 + fRec232))));
			output6[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec6[((IOTA - iConst22) & 1023)])));
			float fTemp73 = (fConst3 * (0.0f - ((fConst5 * fRec240[1]) + (fConst4 * fRec237[1]))));
			float fTemp74 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec246[1]) + (fConst8 * fRec243[1])))) + (fConst10 * (((((0.0367505327f * fTemp12) + (0.0243021473f * fTemp13)) + (0.0115877576f * fTemp14)) + (0.0405409262f * fTemp15)) - ((((0.0432788283f * fTemp9) + (0.00697811041f * fTemp10)) + (0.0309712868f * fTemp11)) + (0.0443387181f * fTemp16))))));
			fRec248[0] = (fRec248[1] + fTemp74);
			fRec246[0] = fRec248[0];
			float fRec247 = fTemp74;
			fRec245[0] = (fRec246[0] + fRec245[1]);
			fRec243[0] = fRec245[0];
			float fRec244 = fRec247;
			fRec242[0] = (fTemp73 + (fRec244 + fRec242[1]));
			fRec240[0] = fRec242[0];
			float fRec241 = (fRec244 + fTemp73);
			fRec239[0] = (fRec240[0] + fRec239[1]);
			fRec237[0] = fRec239[0];
			float fRec238 = fRec241;
			float fTemp75 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec255[1]) + (fConst12 * fRec252[1])))) + (fConst15 * (((((0.0299154501f * fTemp19) + (0.0294495411f * fTemp21)) + (0.020149298f * fTemp23)) + (0.0559884422f * fTemp24)) - (((0.0116003212f * fTemp18) + (0.0245731417f * fTemp22)) + (0.0130363414f * fTemp20))))));
			fRec257[0] = (fRec257[1] + fTemp75);
			fRec255[0] = fRec257[0];
			float fRec256 = fTemp75;
			fRec254[0] = (fRec255[0] + fRec254[1]);
			fRec252[0] = fRec254[0];
			float fRec253 = fRec256;
			float fTemp76 = (fConst16 * fRec249[1]);
			fRec251[0] = ((fRec253 + fRec251[1]) - fTemp76);
			fRec249[0] = fRec251[0];
			float fRec250 = (fRec253 - fTemp76);
			float fTemp77 = (fConst17 * (((0.0082610324f * fTemp28) - ((0.0297759175f * fTemp27) + (0.0199645739f * fTemp29))) - (fConst18 * fRec258[1])));
			fRec260[0] = (fRec260[1] + fTemp77);
			fRec258[0] = fRec260[0];
			float fRec259 = fTemp77;
			float fTemp78 = (fConst19 * (((0.0449877419f * fTemp31) - ((((0.0188399479f * fTemp32) + (0.0253550019f * fTemp35)) + (0.0123225125f * fTemp33)) + (0.0184054133f * fTemp34))) + (fConst7 * (0.0f - ((fConst21 * fRec264[1]) + (fConst20 * fRec261[1]))))));
			fRec266[0] = (fRec266[1] + fTemp78);
			fRec264[0] = fRec266[0];
			float fRec265 = fTemp78;
			fRec263[0] = (fRec264[0] + fRec263[1]);
			fRec261[0] = fRec263[0];
			float fRec262 = fRec265;
			fVec7[(IOTA & 1023)] = ((0.0124723194f * fTemp7) + (fRec238 + (fRec250 + (fRec259 + fRec262))));
			output7[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec7[((IOTA - iConst22) & 1023)])));
			float fTemp79 = (fConst3 * (0.0f - ((fConst5 * fRec270[1]) + (fConst4 * fRec267[1]))));
			float fTemp80 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec276[1]) + (fConst8 * fRec273[1])))) + (fConst10 * (((((0.0499464795f * fTemp9) + (0.0368576124f * fTemp12)) + (0.0519347899f * fTemp13)) + (0.0187913887f * fTemp15)) - ((((0.0596447363f * fTemp10) + (0.0240017138f * fTemp11)) + (0.0127271377f * fTemp14)) + (0.0550275072f * fTemp16))))));
			fRec278[0] = (fRec278[1] + fTemp80);
			fRec276[0] = fRec278[0];
			float fRec277 = fTemp80;
			fRec275[0] = (fRec276[0] + fRec275[1]);
			fRec273[0] = fRec275[0];
			float fRec274 = fRec277;
			fRec272[0] = (fTemp79 + (fRec274 + fRec272[1]));
			fRec270[0] = fRec272[0];
			float fRec271 = (fRec274 + fTemp79);
			fRec269[0] = (fRec270[0] + fRec269[1]);
			fRec267[0] = fRec269[0];
			float fRec268 = fRec271;
			float fTemp81 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec285[1]) + (fConst12 * fRec282[1])))) + (fConst15 * ((((((0.0495350398f * fTemp19) + (0.0195070729f * fTemp21)) + (0.0301244594f * fTemp23)) + (0.0161223449f * fTemp20)) + (0.0169625878f * fTemp24)) - ((0.0690746605f * fTemp18) + (0.0383246876f * fTemp22))))));
			fRec287[0] = (fRec287[1] + fTemp81);
			fRec285[0] = fRec287[0];
			float fRec286 = fTemp81;
			fRec284[0] = (fRec285[0] + fRec284[1]);
			fRec282[0] = fRec284[0];
			float fRec283 = fRec286;
			float fTemp82 = (fConst16 * fRec279[1]);
			fRec281[0] = ((fRec283 + fRec281[1]) - fTemp82);
			fRec279[0] = fRec281[0];
			float fRec280 = (fRec283 - fTemp82);
			float fTemp83 = (fConst17 * (((0.0141814519f * fTemp28) - ((0.0271127317f * fTemp27) + (0.0388887972f * fTemp29))) - (fConst18 * fRec288[1])));
			fRec290[0] = (fRec290[1] + fTemp83);
			fRec288[0] = fRec290[0];
			float fRec289 = fTemp83;
			float fTemp84 = (fConst19 * ((((0.0585170314f * fTemp31) + (0.0218887161f * fTemp34)) - (((0.0220701694f * fTemp32) + (0.029800104f * fTemp35)) + (0.030228015f * fTemp33))) + (fConst7 * (0.0f - ((fConst21 * fRec294[1]) + (fConst20 * fRec291[1]))))));
			fRec296[0] = (fRec296[1] + fTemp84);
			fRec294[0] = fRec296[0];
			float fRec295 = fTemp84;
			fRec293[0] = (fRec294[0] + fRec293[1]);
			fRec291[0] = fRec293[0];
			float fRec292 = fRec295;
			fVec8[(IOTA & 1023)] = ((0.0168837607f * fTemp7) + (fRec268 + (fRec280 + (fRec289 + fRec292))));
			output8[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec8[((IOTA - iConst22) & 1023)])));
			float fTemp85 = (fConst3 * (0.0f - ((fConst5 * fRec300[1]) + (fConst4 * fRec297[1]))));
			float fTemp86 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec306[1]) + (fConst8 * fRec303[1])))) + (fConst10 * (((((0.0412662253f * fTemp9) + (0.00828762446f * fTemp12)) + (0.0622587278f * fTemp13)) + (0.0608389527f * fTemp16)) - ((((0.0224331655f * fTemp10) + (0.0109826885f * fTemp11)) + (0.0246898271f * fTemp14)) + (0.0574520156f * fTemp15))))));
			fRec308[0] = (fRec308[1] + fTemp86);
			fRec306[0] = fRec308[0];
			float fRec307 = fTemp86;
			fRec305[0] = (fRec306[0] + fRec305[1]);
			fRec303[0] = fRec305[0];
			float fRec304 = fRec307;
			fRec302[0] = (fTemp85 + (fRec304 + fRec302[1]));
			fRec300[0] = fRec302[0];
			float fRec301 = (fRec304 + fTemp85);
			fRec299[0] = (fRec300[0] + fRec299[1]);
			fRec297[0] = fRec299[0];
			float fRec298 = fRec301;
			float fTemp87 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec315[1]) + (fConst12 * fRec312[1])))) + (fConst15 * (((((0.0123275798f * fTemp19) + (0.00621908344f * fTemp21)) + (0.0349887349f * fTemp23)) + (0.049783051f * fTemp20)) - (((0.0298409648f * fTemp18) + (0.037730068f * fTemp22)) + (0.0635890588f * fTemp24))))));
			fRec317[0] = (fRec317[1] + fTemp87);
			fRec315[0] = fRec317[0];
			float fRec316 = fTemp87;
			fRec314[0] = (fRec315[0] + fRec314[1]);
			fRec312[0] = fRec314[0];
			float fRec313 = fRec316;
			float fTemp88 = (fConst16 * fRec309[1]);
			fRec311[0] = ((fRec313 + fRec311[1]) - fTemp88);
			fRec309[0] = fRec311[0];
			float fRec310 = (fRec313 - fTemp88);
			float fTemp89 = (fConst17 * (((0.0139324786f * fTemp28) - ((0.00657636859f * fTemp27) + (0.0462513417f * fTemp29))) - (fConst18 * fRec318[1])));
			fRec320[0] = (fRec320[1] + fTemp89);
			fRec318[0] = fRec320[0];
			float fRec319 = fTemp89;
			float fTemp90 = (fConst19 * ((((0.0174644981f * fTemp31) + (0.0590953901f * fTemp34)) - (((0.00436104648f * fTemp32) + (0.0294219553f * fTemp35)) + (0.0365416259f * fTemp33))) + (fConst7 * (0.0f - ((fConst21 * fRec324[1]) + (fConst20 * fRec321[1]))))));
			fRec326[0] = (fRec326[1] + fTemp90);
			fRec324[0] = fRec326[0];
			float fRec325 = fTemp90;
			fRec323[0] = (fRec324[0] + fRec323[1]);
			fRec321[0] = fRec323[0];
			float fRec322 = fRec325;
			fVec9[(IOTA & 1023)] = ((0.0166288801f * fTemp7) + (fRec298 + (fRec310 + (fRec319 + fRec322))));
			output9[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec9[((IOTA - iConst22) & 1023)])));
			float fTemp91 = (fConst3 * (0.0f - ((fConst5 * fRec330[1]) + (fConst4 * fRec327[1]))));
			float fTemp92 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec336[1]) + (fConst8 * fRec333[1])))) + (fConst10 * (((((0.0259709284f * fTemp10) + (0.0132074971f * fTemp11)) + (0.0419745333f * fTemp13)) + (0.0387811139f * fTemp16)) - ((((0.0475221835f * fTemp9) + (0.009792394f * fTemp12)) + (0.0299807154f * fTemp14)) + (0.0308817532f * fTemp15))))));
			fRec338[0] = (fRec338[1] + fTemp92);
			fRec336[0] = fRec338[0];
			float fRec337 = fTemp92;
			fRec335[0] = (fRec336[0] + fRec335[1]);
			fRec333[0] = fRec335[0];
			float fRec334 = fRec337;
			fRec332[0] = (fTemp91 + (fRec334 + fRec332[1]));
			fRec330[0] = fRec332[0];
			float fRec331 = (fRec334 + fTemp91);
			fRec329[0] = (fRec330[0] + fRec329[1]);
			fRec327[0] = fRec329[0];
			float fRec328 = fRec331;
			float fTemp93 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec345[1]) + (fConst12 * fRec342[1])))) + (fConst15 * ((((0.0348462835f * fTemp18) + (0.0344122685f * fTemp23)) + (0.0285112076f * fTemp20)) - ((((0.0143775893f * fTemp19) + (0.00746580539f * fTemp21)) + (0.0240134057f * fTemp22)) + (0.0443761833f * fTemp24))))));
			fRec347[0] = (fRec347[1] + fTemp93);
			fRec345[0] = fRec347[0];
			float fRec346 = fTemp93;
			fRec344[0] = (fRec345[0] + fRec344[1]);
			fRec342[0] = fRec344[0];
			float fRec343 = fRec346;
			float fTemp94 = (fConst16 * fRec339[1]);
			fRec341[0] = ((fRec343 + fRec341[1]) - fTemp94);
			fRec339[0] = fRec341[0];
			float fRec340 = (fRec343 - fTemp94);
			float fTemp95 = (fConst17 * ((((0.00778907491f * fTemp27) + (0.0080658691f * fTemp28)) - (0.0343690775f * fTemp29)) - (fConst18 * fRec348[1])));
			fRec350[0] = (fRec350[1] + fTemp95);
			fRec348[0] = fRec350[0];
			float fRec349 = fTemp95;
			float fTemp96 = (fConst19 * ((((0.00510414643f * fTemp32) + (0.0432005376f * fTemp34)) - (((0.020583285f * fTemp31) + (0.0249576326f * fTemp35)) + (0.0213943254f * fTemp33))) + (fConst7 * (0.0f - ((fConst21 * fRec354[1]) + (fConst20 * fRec351[1]))))));
			fRec356[0] = (fRec356[1] + fTemp96);
			fRec354[0] = fRec356[0];
			float fRec355 = fTemp96;
			fRec353[0] = (fRec354[0] + fRec353[1]);
			fRec351[0] = fRec353[0];
			float fRec352 = fRec355;
			fVec10[(IOTA & 1023)] = ((0.0122519135f * fTemp7) + (fRec328 + (fRec340 + (fRec349 + fRec352))));
			output10[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec10[((IOTA - iConst22) & 1023)])));
			float fTemp97 = (fConst3 * (0.0f - ((fConst5 * fRec360[1]) + (fConst4 * fRec357[1]))));
			float fTemp98 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec366[1]) + (fConst8 * fRec363[1])))) + (fConst10 * (((((0.0585901402f * fTemp10) + (0.0243782587f * fTemp11)) + (0.0511972718f * fTemp13)) + (0.0228566341f * fTemp15)) - ((((0.0441023558f * fTemp9) + (0.0381432697f * fTemp12)) + (0.0109541928f * fTemp14)) + (0.0600764938f * fTemp16))))));
			fRec368[0] = (fRec368[1] + fTemp98);
			fRec366[0] = fRec368[0];
			float fRec367 = fTemp98;
			fRec365[0] = (fRec366[0] + fRec365[1]);
			fRec363[0] = fRec365[0];
			float fRec364 = fRec367;
			fRec362[0] = (fTemp97 + (fRec364 + fRec362[1]));
			fRec360[0] = fRec362[0];
			float fRec361 = (fRec364 + fTemp97);
			fRec359[0] = (fRec360[0] + fRec359[1]);
			fRec357[0] = fRec359[0];
			float fRec358 = fRec361;
			float fTemp99 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec375[1]) + (fConst12 * fRec372[1])))) + (fConst15 * (((((0.0676866993f * fTemp18) + (0.0293273851f * fTemp23)) + (0.0140171852f * fTemp20)) + (0.0222228188f * fTemp24)) - (((0.0504664481f * fTemp19) + (0.0202180892f * fTemp21)) + (0.038476821f * fTemp22))))));
			fRec377[0] = (fRec377[1] + fTemp99);
			fRec375[0] = fRec377[0];
			float fRec376 = fTemp99;
			fRec374[0] = (fRec375[0] + fRec374[1]);
			fRec372[0] = fRec374[0];
			float fRec373 = fRec376;
			float fTemp100 = (fConst16 * fRec369[1]);
			fRec371[0] = ((fRec373 + fRec371[1]) - fTemp100);
			fRec369[0] = fRec371[0];
			float fRec370 = (fRec373 - fTemp100);
			float fTemp101 = (fConst17 * ((((0.028083669f * fTemp27) + (0.0142656397f * fTemp28)) - (0.0382314026f * fTemp29)) - (fConst18 * fRec378[1])));
			fRec380[0] = (fRec380[1] + fTemp101);
			fRec378[0] = fRec380[0];
			float fRec379 = fTemp101;
			float fTemp102 = (fConst19 * ((((0.0228417572f * fTemp32) + (0.0189450383f * fTemp34)) - (((0.0595927685f * fTemp31) + (0.0297161005f * fTemp35)) + (0.0299108345f * fTemp33))) + (fConst7 * (0.0f - ((fConst21 * fRec384[1]) + (fConst20 * fRec381[1]))))));
			fRec386[0] = (fRec386[1] + fTemp102);
			fRec384[0] = fRec386[0];
			float fRec385 = fTemp102;
			fRec383[0] = (fRec384[0] + fRec383[1]);
			fRec381[0] = fRec383[0];
			float fRec382 = fRec385;
			fVec11[(IOTA & 1023)] = ((0.0168990009f * fTemp7) + (fRec358 + (fRec370 + (fRec379 + fRec382))));
			output11[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec11[((IOTA - iConst22) & 1023)])));
			float fTemp103 = (fConst3 * (0.0f - ((fConst5 * fRec390[1]) + (fConst4 * fRec387[1]))));
			float fTemp104 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec396[1]) + (fConst8 * fRec393[1])))) + (fConst10 * (((((((0.0434018187f * fTemp9) + (0.00500400364f * fTemp10)) + (0.0285721086f * fTemp11)) + (0.0220826529f * fTemp13)) + (0.0116624022f * fTemp14)) + (0.0382460393f * fTemp15)) - ((0.0343887471f * fTemp12) + (0.0396602526f * fTemp16))))));
			fRec398[0] = (fRec398[1] + fTemp104);
			fRec396[0] = fRec398[0];
			float fRec397 = fTemp104;
			fRec395[0] = (fRec396[0] + fRec395[1]);
			fRec393[0] = fRec395[0];
			float fRec394 = fRec397;
			fRec392[0] = (fTemp103 + (fRec394 + fRec392[1]));
			fRec390[0] = fRec392[0];
			float fRec391 = (fRec394 + fTemp103);
			fRec389[0] = (fRec390[0] + fRec389[1]);
			fRec387[0] = fRec389[0];
			float fRec388 = fRec391;
			float fTemp105 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec405[1]) + (fConst12 * fRec402[1])))) + (fConst15 * ((((0.0086368015f * fTemp18) + (0.0183102898f * fTemp23)) + (0.0529826954f * fTemp24)) - ((((0.0275187418f * fTemp19) + (0.0276104975f * fTemp21)) + (0.0227601342f * fTemp22)) + (0.0128853256f * fTemp20))))));
			fRec407[0] = (fRec407[1] + fTemp105);
			fRec405[0] = fRec407[0];
			float fRec406 = fTemp105;
			fRec404[0] = (fRec405[0] + fRec404[1]);
			fRec402[0] = fRec404[0];
			float fRec403 = fRec406;
			float fTemp106 = (fConst16 * fRec399[1]);
			fRec401[0] = ((fRec403 + fRec401[1]) - fTemp106);
			fRec399[0] = fRec401[0];
			float fRec400 = (fRec403 - fTemp106);
			float fTemp107 = (fConst17 * ((((0.0278907772f * fTemp27) + (0.00765112508f * fTemp28)) - (0.0181327537f * fTemp29)) - (fConst18 * fRec408[1])));
			fRec410[0] = (fRec410[1] + fTemp107);
			fRec408[0] = fRec410[0];
			float fRec409 = fTemp107;
			float fTemp108 = (fConst19 * (((0.0176248495f * fTemp32) - ((((0.0414236374f * fTemp31) + (0.0234996267f * fTemp35)) + (0.0111909164f * fTemp33)) + (0.0183374938f * fTemp34))) + (fConst7 * (0.0f - ((fConst21 * fRec414[1]) + (fConst20 * fRec411[1]))))));
			fRec416[0] = (fRec416[1] + fTemp108);
			fRec414[0] = fRec416[0];
			float fRec415 = fTemp108;
			fRec413[0] = (fRec414[0] + fRec413[1]);
			fRec411[0] = fRec413[0];
			float fRec412 = fRec415;
			fVec12[(IOTA & 1023)] = ((0.0115571907f * fTemp7) + (fRec388 + (fRec400 + (fRec409 + fRec412))));
			output12[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec12[((IOTA - iConst22) & 1023)])));
			float fTemp109 = (fConst3 * (0.0f - ((fConst5 * fRec420[1]) + (fConst4 * fRec417[1]))));
			float fTemp110 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec426[1]) + (fConst8 * fRec423[1])))) + (fConst10 * (((((((0.0486010462f * fTemp9) + (0.0123438127f * fTemp11)) + (0.010380513f * fTemp13)) + (0.0228530224f * fTemp14)) + (0.0280893389f * fTemp15)) + (0.0561792329f * fTemp16)) - ((0.0572822131f * fTemp10) + (0.0640593395f * fTemp12))))));
			fRec428[0] = (fRec428[1] + fTemp110);
			fRec426[0] = fRec428[0];
			float fRec427 = fTemp110;
			fRec425[0] = (fRec426[0] + fRec425[1]);
			fRec423[0] = fRec425[0];
			float fRec424 = fRec427;
			fRec422[0] = (fTemp109 + (fRec424 + fRec422[1]));
			fRec420[0] = fRec422[0];
			float fRec421 = (fRec424 + fTemp109);
			fRec419[0] = (fRec420[0] + fRec419[1]);
			fRec417[0] = fRec419[0];
			float fRec418 = fRec421;
			float fTemp111 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec435[1]) + (fConst12 * fRec432[1])))) + (fConst15 * (((0.00727634691f * fTemp23) + (0.0357998088f * fTemp24)) - (((((0.0617749915f * fTemp18) + (0.0156796649f * fTemp19)) + (0.0344306603f * fTemp21)) + (0.0393248387f * fTemp22)) + (0.0511149094f * fTemp20))))));
			fRec437[0] = (fRec437[1] + fTemp111);
			fRec435[0] = fRec437[0];
			float fRec436 = fTemp111;
			fRec434[0] = (fRec435[0] + fRec434[1]);
			fRec432[0] = fRec434[0];
			float fRec433 = fRec436;
			float fTemp112 = (fConst16 * fRec429[1]);
			fRec431[0] = ((fRec433 + fRec431[1]) - fTemp112);
			fRec429[0] = fRec431[0];
			float fRec430 = (fRec433 - fTemp112);
			float fTemp113 = (fConst17 * ((((0.0472527407f * fTemp27) + (0.0146665508f * fTemp28)) - (0.00807858817f * fTemp29)) - (fConst18 * fRec438[1])));
			fRec440[0] = (fRec440[1] + fTemp113);
			fRec438[0] = fRec440[0];
			float fRec439 = fTemp113;
			float fTemp114 = (fConst19 * (((0.0381809957f * fTemp32) - ((((0.0212455392f * fTemp31) + (0.0297676772f * fTemp35)) + (0.00561058102f * fTemp33)) + (0.0592715293f * fTemp34))) + (fConst7 * (0.0f - ((fConst21 * fRec444[1]) + (fConst20 * fRec441[1]))))));
			fRec446[0] = (fRec446[1] + fTemp114);
			fRec444[0] = fRec446[0];
			float fRec445 = fTemp114;
			fRec443[0] = (fRec444[0] + fRec443[1]);
			fRec441[0] = fRec443[0];
			float fRec442 = fRec445;
			fVec13[(IOTA & 1023)] = ((0.0171159822f * fTemp7) + (fRec418 + (fRec430 + (fRec439 + fRec442))));
			output13[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec13[((IOTA - iConst22) & 1023)])));
			float fTemp115 = (fConst3 * (0.0f - ((fConst5 * fRec450[1]) + (fConst4 * fRec447[1]))));
			float fTemp116 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec456[1]) + (fConst8 * fRec453[1])))) + (fConst10 * (((0.0305698123f * fTemp14) + (0.0441108532f * fTemp16)) - ((((((0.0418831296f * fTemp9) + (0.0327009261f * fTemp10)) + (0.0109191211f * fTemp11)) + (0.0419193022f * fTemp12)) + (0.00849421043f * fTemp13)) + (0.0230855644f * fTemp15))))));
			fRec458[0] = (fRec458[1] + fTemp116);
			fRec456[0] = fRec458[0];
			float fRec457 = fTemp116;
			fRec455[0] = (fRec456[0] + fRec455[1]);
			fRec453[0] = fRec455[0];
			float fRec454 = fRec457;
			fRec452[0] = (fTemp115 + (fRec454 + fRec452[1]));
			fRec450[0] = fRec452[0];
			float fRec451 = (fRec454 + fTemp115);
			fRec449[0] = (fRec450[0] + fRec449[1]);
			fRec447[0] = fRec449[0];
			float fRec448 = fRec451;
			float fTemp117 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec465[1]) + (fConst12 * fRec462[1])))) + (fConst15 * ((0.0126653062f * fTemp19) - ((((((0.0470733121f * fTemp18) + (0.0343220197f * fTemp21)) + (0.0238393378f * fTemp22)) + (0.0062313294f * fTemp23)) + (0.0290537458f * fTemp20)) + (0.0302382987f * fTemp24))))));
			fRec467[0] = (fRec467[1] + fTemp117);
			fRec465[0] = fRec467[0];
			float fRec466 = fTemp117;
			fRec464[0] = (fRec465[0] + fRec464[1]);
			fRec462[0] = fRec464[0];
			float fRec463 = fRec466;
			float fTemp118 = (fConst16 * fRec459[1]);
			fRec461[0] = ((fRec463 + fRec461[1]) - fTemp118);
			fRec459[0] = fRec461[0];
			float fRec460 = (fRec463 - fTemp118);
			float fTemp119 = (fConst17 * ((((0.034308698f * fTemp27) + (0.00801151432f * fTemp28)) + (0.00665730657f * fTemp29)) - (fConst18 * fRec468[1])));
			fRec470[0] = (fRec470[1] + fTemp119);
			fRec468[0] = fRec470[0];
			float fRec469 = fTemp119;
			float fTemp120 = (fConst19 * (((((0.0176824778f * fTemp31) + (0.0213772245f * fTemp32)) + (0.00447684992f * fTemp33)) - ((0.0247367825f * fTemp35) + (0.0440350547f * fTemp34))) + (fConst7 * (0.0f - ((fConst21 * fRec474[1]) + (fConst20 * fRec471[1]))))));
			fRec476[0] = (fRec476[1] + fTemp120);
			fRec474[0] = fRec476[0];
			float fRec475 = fTemp120;
			fRec473[0] = (fRec474[0] + fRec473[1]);
			fRec471[0] = fRec473[0];
			float fRec472 = fRec475;
			fVec14[(IOTA & 1023)] = ((0.0121517424f * fTemp7) + (fRec448 + (fRec460 + (fRec469 + fRec472))));
			output14[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec14[((IOTA - iConst22) & 1023)])));
			float fTemp121 = (fConst3 * (0.0f - ((fConst5 * fRec480[1]) + (fConst4 * fRec477[1]))));
			float fTemp122 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec486[1]) + (fConst8 * fRec483[1])))) + (fConst10 * (((0.00157822878f * fTemp10) + (0.0134847378f * fTemp14)) - ((((((0.0488788746f * fTemp9) + (0.0287671536f * fTemp11)) + (0.0367355309f * fTemp12)) + (0.0220866222f * fTemp13)) + (0.0401810631f * fTemp15)) + (0.0354222916f * fTemp16))))));
			fRec488[0] = (fRec488[1] + fTemp122);
			fRec486[0] = fRec488[0];
			float fRec487 = fTemp122;
			fRec485[0] = (fRec486[0] + fRec485[1]);
			fRec483[0] = fRec485[0];
			float fRec484 = fRec487;
			fRec482[0] = (fTemp121 + (fRec484 + fRec482[1]));
			fRec480[0] = fRec482[0];
			float fRec481 = (fRec484 + fTemp121);
			fRec479[0] = (fRec480[0] + fRec479[1]);
			fRec477[0] = fRec479[0];
			float fRec478 = fRec481;
			float fTemp123 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec495[1]) + (fConst12 * fRec492[1])))) + (fConst15 * (((0.00424594153f * fTemp18) + (0.0279642865f * fTemp19)) - (((((0.0291018263f * fTemp21) + (0.0239206739f * fTemp22)) + (0.01820134f * fTemp23)) + (0.0152251739f * fTemp20)) + (0.0553320386f * fTemp24))))));
			fRec497[0] = (fRec497[1] + fTemp123);
			fRec495[0] = fRec497[0];
			float fRec496 = fTemp123;
			fRec494[0] = (fRec495[0] + fRec494[1]);
			fRec492[0] = fRec494[0];
			float fRec493 = fRec496;
			float fTemp124 = (fConst16 * fRec489[1]);
			fRec491[0] = ((fRec493 + fRec491[1]) - fTemp124);
			fRec489[0] = fRec491[0];
			float fRec490 = (fRec493 - fTemp124);
			float fTemp125 = (fConst17 * ((((0.0295908526f * fTemp27) + (0.00805393979f * fTemp28)) + (0.0180607811f * fTemp29)) - (fConst18 * fRec498[1])));
			fRec500[0] = (fRec500[1] + fTemp125);
			fRec498[0] = fRec500[0];
			float fRec499 = fTemp125;
			float fTemp126 = (fConst19 * (((((0.0418831296f * fTemp31) + (0.0188768283f * fTemp32)) + (0.011194922f * fTemp33)) - ((0.0244455952f * fTemp35) + (0.0214613173f * fTemp34))) + (fConst7 * (0.0f - ((fConst21 * fRec504[1]) + (fConst20 * fRec501[1]))))));
			fRec506[0] = (fRec506[1] + fTemp126);
			fRec504[0] = fRec506[0];
			float fRec505 = fTemp126;
			fRec503[0] = (fRec504[0] + fRec503[1]);
			fRec501[0] = fRec503[0];
			float fRec502 = fRec505;
			fVec15[(IOTA & 1023)] = ((0.0120597398f * fTemp7) + (fRec478 + (fRec490 + (fRec499 + fRec502))));
			output15[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec15[((IOTA - iConst22) & 1023)])));
			float fTemp127 = (fConst24 * (0.0f - ((fConst26 * fRec510[1]) + (fConst25 * fRec507[1]))));
			float fTemp128 = (fConst27 * ((fConst7 * (0.0f - ((fConst29 * fRec516[1]) + (fConst28 * fRec513[1])))) + (fConst30 * ((((((((0.0425642394f * fTemp9) + (0.0960019901f * fTemp10)) + (0.0758396015f * fTemp11)) + (0.000561973371f * fTemp13)) + (0.103890762f * fTemp14)) + (0.0659738034f * fTemp15)) + (0.013838849f * fTemp16)) - (0.00591106853f * fTemp12)))));
			fRec518[0] = (fRec518[1] + fTemp128);
			fRec516[0] = fRec518[0];
			float fRec517 = fTemp128;
			fRec515[0] = (fRec516[0] + fRec515[1]);
			fRec513[0] = fRec515[0];
			float fRec514 = fRec517;
			fRec512[0] = (fTemp127 + (fRec514 + fRec512[1]));
			fRec510[0] = fRec512[0];
			float fRec511 = (fRec514 + fTemp127);
			fRec509[0] = (fRec510[0] + fRec509[1]);
			fRec507[0] = fRec509[0];
			float fRec508 = fRec511;
			float fTemp129 = (fConst31 * ((fConst7 * (0.0f - ((fConst33 * fRec525[1]) + (fConst32 * fRec522[1])))) + (fConst35 * (((((((0.0527285933f * fTemp18) + (0.0847168639f * fTemp19)) + (0.0305806994f * fTemp21)) + (0.100798577f * fTemp23)) + (0.113728546f * fTemp20)) + (0.0372378081f * fTemp24)) - (0.0553800911f * fTemp22)))));
			fRec527[0] = (fRec527[1] + fTemp129);
			fRec525[0] = fRec527[0];
			float fRec526 = fTemp129;
			fRec524[0] = (fRec525[0] + fRec524[1]);
			fRec522[0] = fRec524[0];
			float fRec523 = fRec526;
			float fTemp130 = (fConst36 * fRec519[1]);
			fRec521[0] = ((fRec523 + fRec521[1]) - fTemp130);
			fRec519[0] = fRec521[0];
			float fRec520 = (fRec523 - fTemp130);
			float fTemp131 = (fConst37 * ((((0.0258369539f * fTemp27) + (0.0730907619f * fTemp28)) + (0.0790967792f * fTemp29)) - (fConst38 * fRec528[1])));
			fRec530[0] = (fRec530[1] + fTemp131);
			fRec528[0] = fRec530[0];
			float fRec529 = fTemp131;
			float fTemp132 = (fConst39 * ((((((0.048024606f * fTemp31) + (0.0438587815f * fTemp32)) + (0.024724206f * fTemp35)) + (0.135661513f * fTemp33)) + (0.0647059232f * fTemp34)) + (fConst7 * (0.0f - ((fConst41 * fRec534[1]) + (fConst40 * fRec531[1]))))));
			fRec536[0] = (fRec536[1] + fTemp132);
			fRec534[0] = fRec536[0];
			float fRec535 = fTemp132;
			fRec533[0] = (fRec534[0] + fRec533[1]);
			fRec531[0] = fRec533[0];
			float fRec532 = fRec535;
			fVec16[(IOTA & 511)] = ((0.0389358997f * fTemp7) + (fRec508 + (fRec520 + (fRec529 + fRec532))));
			output16[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec16[((IOTA - iConst42) & 511)])));
			float fTemp133 = (fConst24 * (0.0f - ((fConst26 * fRec540[1]) + (fConst25 * fRec537[1]))));
			float fTemp134 = (fConst27 * ((fConst7 * (0.0f - ((fConst29 * fRec546[1]) + (fConst28 * fRec543[1])))) + (fConst30 * ((((0.0157894175f * fTemp12) + (0.0660255626f * fTemp14)) + (0.0212420654f * fTemp15)) - (((((0.0428467467f * fTemp9) + (0.109361917f * fTemp10)) + (0.0810074508f * fTemp11)) + (0.0307057556f * fTemp13)) + (0.0144473743f * fTemp16))))));
			fRec548[0] = (fRec548[1] + fTemp134);
			fRec546[0] = fRec548[0];
			float fRec547 = fTemp134;
			fRec545[0] = (fRec546[0] + fRec545[1]);
			fRec543[0] = fRec545[0];
			float fRec544 = fRec547;
			fRec542[0] = (fTemp133 + (fRec544 + fRec542[1]));
			fRec540[0] = fRec542[0];
			float fRec541 = (fRec544 + fTemp133);
			fRec539[0] = (fRec540[0] + fRec539[1]);
			fRec537[0] = fRec539[0];
			float fRec538 = fRec541;
			float fTemp135 = (fConst31 * ((fConst7 * (0.0f - ((fConst33 * fRec555[1]) + (fConst32 * fRec552[1])))) + (fConst35 * ((((0.0649363026f * fTemp23) + (0.0777263865f * fTemp20)) + (0.0104764495f * fTemp24)) - ((((0.0618418828f * fTemp18) + (0.100558326f * fTemp19)) + (0.0306441542f * fTemp21)) + (0.0645447522f * fTemp22))))));
			fRec557[0] = (fRec557[1] + fTemp135);
			fRec555[0] = fRec557[0];
			float fRec556 = fTemp135;
			fRec554[0] = (fRec555[0] + fRec554[1]);
			fRec552[0] = fRec554[0];
			float fRec553 = fRec556;
			float fTemp136 = (fConst36 * fRec549[1]);
			fRec551[0] = ((fRec553 + fRec551[1]) - fTemp136);
			fRec549[0] = fRec551[0];
			float fRec550 = (fRec553 - fTemp136);
			float fTemp137 = (fConst37 * ((((0.0562963411f * fTemp28) + (0.0654787123f * fTemp29)) - (0.0324570462f * fTemp27)) - (fConst38 * fRec558[1])));
			fRec560[0] = (fRec560[1] + fTemp137);
			fRec558[0] = fRec560[0];
			float fRec559 = fTemp137;
			float fTemp138 = (fConst39 * (((((0.00686467579f * fTemp35) + (0.106752284f * fTemp33)) + (0.044906605f * fTemp34)) - ((0.0597469099f * fTemp31) + (0.0522084646f * fTemp32))) + (fConst7 * (0.0f - ((fConst41 * fRec564[1]) + (fConst40 * fRec561[1]))))));
			fRec566[0] = (fRec566[1] + fTemp138);
			fRec564[0] = fRec566[0];
			float fRec565 = fTemp138;
			fRec563[0] = (fRec564[0] + fRec563[1]);
			fRec561[0] = fRec563[0];
			float fRec562 = fRec565;
			fVec17[(IOTA & 511)] = ((0.0321440324f * fTemp7) + (fRec538 + (fRec550 + (fRec559 + fRec562))));
			output17[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec17[((IOTA - iConst42) & 511)])));
			float fTemp139 = (fConst24 * (0.0f - ((fConst26 * fRec570[1]) + (fConst25 * fRec567[1]))));
			float fTemp140 = (fConst27 * ((fConst7 * (0.0f - ((fConst29 * fRec576[1]) + (fConst28 * fRec573[1])))) + (fConst30 * (((((0.0407282151f * fTemp9) + (0.0727228895f * fTemp10)) + (5.40006004e-05f * fTemp12)) + (0.017394295f * fTemp16)) - ((((0.0713750646f * fTemp11) + (0.00580928847f * fTemp13)) + (0.10837023f * fTemp14)) + (0.0912010446f * fTemp15))))));
			fRec578[0] = (fRec578[1] + fTemp140);
			fRec576[0] = fRec578[0];
			float fRec577 = fTemp140;
			fRec575[0] = (fRec576[0] + fRec575[1]);
			fRec573[0] = fRec575[0];
			float fRec574 = fRec577;
			fRec572[0] = (fTemp139 + (fRec574 + fRec572[1]));
			fRec570[0] = fRec572[0];
			float fRec571 = (fRec574 + fTemp139);
			fRec569[0] = (fRec570[0] + fRec569[1]);
			fRec567[0] = fRec569[0];
			float fRec568 = fRec571;
			float fTemp141 = (fConst31 * ((fConst7 * (0.0f - ((fConst33 * fRec585[1]) + (fConst32 * fRec582[1])))) + (fConst35 * (((0.0408923775f * fTemp18) + (0.0286163539f * fTemp23)) - (((((0.0799873322f * fTemp19) + (0.102710731f * fTemp21)) + (0.056507688f * fTemp22)) + (0.118787289f * fTemp20)) + (0.050146725f * fTemp24))))));
			fRec587[0] = (fRec587[1] + fTemp141);
			fRec585[0] = fRec587[0];
			float fRec586 = fTemp141;
			fRec584[0] = (fRec585[0] + fRec584[1]);
			fRec582[0] = fRec584[0];
			float fRec583 = fRec586;
			float fTemp142 = (fConst36 * fRec579[1]);
			fRec581[0] = ((fRec583 + fRec581[1]) - fTemp142);
			fRec579[0] = fRec581[0];
			float fRec580 = (fRec583 - fTemp142);
			float fTemp143 = (fConst37 * ((((0.0741337016f * fTemp28) + (0.0243202727f * fTemp29)) - (0.0808136836f * fTemp27)) - (fConst38 * fRec588[1])));
			fRec590[0] = (fRec590[1] + fTemp143);
			fRec588[0] = fRec590[0];
			float fRec589 = fTemp143;
			float fTemp144 = (fConst39 * ((((0.0249158852f * fTemp35) + (0.0412290394f * fTemp33)) - (((0.0453998521f * fTemp31) + (0.138542935f * fTemp32)) + (0.0675695091f * fTemp34))) + (fConst7 * (0.0f - ((fConst41 * fRec594[1]) + (fConst40 * fRec591[1]))))));
			fRec596[0] = (fRec596[1] + fTemp144);
			fRec594[0] = fRec596[0];
			float fRec595 = fTemp144;
			fRec593[0] = (fRec594[0] + fRec593[1]);
			fRec591[0] = fRec593[0];
			float fRec592 = fRec595;
			fVec18[(IOTA & 511)] = ((0.0395166576f * fTemp7) + (fRec568 + (fRec580 + (fRec589 + fRec592))));
			output18[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec18[((IOTA - iConst42) & 511)])));
			float fTemp145 = (fConst24 * (0.0f - ((fConst26 * fRec600[1]) + (fConst25 * fRec597[1]))));
			float fTemp146 = (fConst27 * ((fConst7 * (0.0f - ((fConst29 * fRec606[1]) + (fConst28 * fRec603[1])))) + (fConst30 * ((((((0.0131468866f * fTemp10) + (0.0825278163f * fTemp11)) + (0.0308654029f * fTemp12)) + (0.0173005518f * fTemp13)) + (0.110574707f * fTemp15)) - (((0.0413558222f * fTemp9) + (0.0618733726f * fTemp14)) + (0.0191247426f * fTemp16))))));
			fRec608[0] = (fRec608[1] + fTemp146);
			fRec606[0] = fRec608[0];
			float fRec607 = fTemp146;
			fRec605[0] = (fRec606[0] + fRec605[1]);
			fRec603[0] = fRec605[0];
			float fRec604 = fRec607;
			fRec602[0] = (fTemp145 + (fRec604 + fRec602[1]));
			fRec600[0] = fRec602[0];
			float fRec601 = (fRec604 + fTemp145);
			fRec599[0] = (fRec600[0] + fRec599[1]);
			fRec597[0] = fRec599[0];
			float fRec598 = fRec601;
			float fTemp147 = (fConst31 * ((fConst7 * (0.0f - ((fConst33 * fRec615[1]) + (fConst32 * fRec612[1])))) + (fConst35 * ((((0.00571153266f * fTemp18) + (0.103330597f * fTemp19)) + (0.0625145212f * fTemp24)) - ((((0.0629192665f * fTemp21) + (0.0642541945f * fTemp22)) + (0.0310702007f * fTemp23)) + (0.0724368766f * fTemp20))))));
			fRec617[0] = (fRec617[1] + fTemp147);
			fRec615[0] = fRec617[0];
			float fRec616 = fTemp147;
			fRec614[0] = (fRec615[0] + fRec614[1]);
			fRec612[0] = fRec614[0];
			float fRec613 = fRec616;
			float fTemp148 = (fConst36 * fRec609[1]);
			fRec611[0] = ((fRec613 + fRec611[1]) - fTemp148);
			fRec609[0] = fRec611[0];
			float fRec610 = (fRec613 - fTemp148);
			float fTemp149 = (fConst37 * (((0.0554719977f * fTemp28) - ((0.0641313195f * fTemp27) + (0.0336948335f * fTemp29))) - (fConst38 * fRec618[1])));
			fRec620[0] = (fRec620[1] + fTemp149);
			fRec618[0] = fRec620[0];
			float fRec619 = fTemp149;
			float fTemp150 = (fConst39 * ((((0.0615871884f * fTemp31) + (0.00626674574f * fTemp35)) - (((0.104309492f * fTemp32) + (0.0539374128f * fTemp33)) + (0.0417371392f * fTemp34))) + (fConst7 * (0.0f - ((fConst41 * fRec624[1]) + (fConst40 * fRec621[1]))))));
			fRec626[0] = (fRec626[1] + fTemp150);
			fRec624[0] = fRec626[0];
			float fRec625 = fTemp150;
			fRec623[0] = (fRec624[0] + fRec623[1]);
			fRec621[0] = fRec623[0];
			float fRec622 = fRec625;
			fVec19[(IOTA & 511)] = ((0.0317779481f * fTemp7) + (fRec598 + (fRec610 + (fRec619 + fRec622))));
			output19[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec19[((IOTA - iConst42) & 511)])));
			float fTemp151 = (fConst24 * (0.0f - ((fConst26 * fRec630[1]) + (fConst25 * fRec627[1]))));
			float fTemp152 = (fConst27 * ((fConst7 * (0.0f - ((fConst29 * fRec636[1]) + (fConst28 * fRec633[1])))) + (fConst30 * ((((((0.0431538485f * fTemp9) + (0.0710032731f * fTemp11)) + (0.00489094015f * fTemp12)) + (0.101520106f * fTemp14)) + (0.00554583268f * fTemp16)) - (((0.0925937742f * fTemp10) + (0.0149702234f * fTemp13)) + (0.0552134365f * fTemp15))))));
			fRec638[0] = (fRec638[1] + fTemp152);
			fRec636[0] = fRec638[0];
			float fRec637 = fTemp152;
			fRec635[0] = (fRec636[0] + fRec635[1]);
			fRec633[0] = fRec635[0];
			float fRec634 = fRec637;
			fRec632[0] = (fTemp151 + (fRec634 + fRec632[1]));
			fRec630[0] = fRec632[0];
			float fRec631 = (fRec634 + fTemp151);
			fRec629[0] = (fRec630[0] + fRec629[1]);
			fRec627[0] = fRec629[0];
			float fRec628 = fRec631;
			float fTemp153 = (fConst31 * ((fConst7 * (0.0f - ((fConst33 * fRec645[1]) + (fConst32 * fRec642[1])))) + (fConst35 * (((0.0785611272f * fTemp19) + (0.100247055f * fTemp20)) - (((((0.0504647121f * fTemp18) + (0.0280880537f * fTemp21)) + (0.0430821702f * fTemp22)) + (0.0991628394f * fTemp23)) + (0.0283471514f * fTemp24))))));
			fRec647[0] = (fRec647[1] + fTemp153);
			fRec645[0] = fRec647[0];
			float fRec646 = fTemp153;
			fRec644[0] = (fRec645[0] + fRec644[1]);
			fRec642[0] = fRec644[0];
			float fRec643 = fRec646;
			float fTemp154 = (fConst36 * fRec639[1]);
			fRec641[0] = ((fRec643 + fRec641[1]) - fTemp154);
			fRec639[0] = fRec641[0];
			float fRec640 = (fRec643 - fTemp154);
			float fTemp155 = (fConst37 * (((0.0661523789f * fTemp28) - ((0.0233769547f * fTemp27) + (0.0679899305f * fTemp29))) - (fConst38 * fRec648[1])));
			fRec650[0] = (fRec650[1] + fTemp155);
			fRec648[0] = fRec650[0];
			float fRec649 = fTemp155;
			float fTemp156 = (fConst39 * (((((0.0443138778f * fTemp31) + (0.0276602488f * fTemp35)) + (0.0540602431f * fTemp34)) - ((0.039839454f * fTemp32) + (0.121145688f * fTemp33))) + (fConst7 * (0.0f - ((fConst41 * fRec654[1]) + (fConst40 * fRec651[1]))))));
			fRec656[0] = (fRec656[1] + fTemp156);
			fRec654[0] = fRec656[0];
			float fRec655 = fTemp156;
			fRec653[0] = (fRec654[0] + fRec653[1]);
			fRec651[0] = fRec653[0];
			float fRec652 = fRec655;
			fVec20[(IOTA & 511)] = ((0.0341328457f * fTemp7) + (fRec628 + (fRec640 + (fRec649 + fRec652))));
			output20[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec20[((IOTA - iConst42) & 511)])));
			float fTemp157 = (fConst24 * (0.0f - ((fConst26 * fRec660[1]) + (fConst25 * fRec657[1]))));
			float fTemp158 = (fConst27 * ((fConst7 * (0.0f - ((fConst29 * fRec666[1]) + (fConst28 * fRec663[1])))) + (fConst30 * (((((0.0956288576f * fTemp10) + (0.0346757881f * fTemp13)) + (0.068887867f * fTemp14)) + (0.0120505132f * fTemp16)) - ((((0.0440604314f * fTemp9) + (0.0730319619f * fTemp11)) + (0.00599234039f * fTemp12)) + (0.0532662794f * fTemp15))))));
			fRec668[0] = (fRec668[1] + fTemp158);
			fRec666[0] = fRec668[0];
			float fRec667 = fTemp158;
			fRec665[0] = (fRec666[0] + fRec665[1]);
			fRec663[0] = fRec665[0];
			float fRec664 = fRec667;
			fRec662[0] = (fTemp157 + (fRec664 + fRec662[1]));
			fRec660[0] = fRec662[0];
			float fRec661 = (fRec664 + fTemp157);
			fRec659[0] = (fRec660[0] + fRec659[1]);
			fRec657[0] = fRec659[0];
			float fRec658 = fRec661;
			float fTemp159 = (fConst31 * ((fConst7 * (0.0f - ((fConst33 * fRec675[1]) + (fConst32 * fRec672[1])))) + (fConst35 * ((((0.0523244254f * fTemp18) + (0.0286972616f * fTemp21)) + (0.0915842354f * fTemp20)) - ((((0.0816331059f * fTemp19) + (0.0620787777f * fTemp22)) + (0.0613967255f * fTemp23)) + (0.0328271911f * fTemp24))))));
			fRec677[0] = (fRec677[1] + fTemp159);
			fRec675[0] = fRec677[0];
			float fRec676 = fTemp159;
			fRec674[0] = (fRec675[0] + fRec674[1]);
			fRec672[0] = fRec674[0];
			float fRec673 = fRec676;
			float fTemp160 = (fConst36 * fRec669[1]);
			fRec671[0] = ((fRec673 + fRec671[1]) - fTemp160);
			fRec669[0] = fRec671[0];
			float fRec670 = (fRec673 - fTemp160);
			float fTemp161 = (fConst37 * ((((0.0244521499f * fTemp27) + (0.0535257049f * fTemp28)) - (0.0656843856f * fTemp29)) - (fConst38 * fRec678[1])));
			fRec680[0] = (fRec680[1] + fTemp161);
			fRec678[0] = fRec680[0];
			float fRec679 = fTemp161;
			float fTemp162 = (fConst39 * (((((0.0414300635f * fTemp32) + (0.00594976777f * fTemp35)) + (0.0556743294f * fTemp34)) - ((0.0462794229f * fTemp31) + (0.10567978f * fTemp33))) + (fConst7 * (0.0f - ((fConst41 * fRec684[1]) + (fConst40 * fRec681[1]))))));
			fRec686[0] = (fRec686[1] + fTemp162);
			fRec684[0] = fRec686[0];
			float fRec685 = fTemp162;
			fRec683[0] = (fRec684[0] + fRec683[1]);
			fRec681[0] = fRec683[0];
			float fRec682 = fRec685;
			fVec21[(IOTA & 511)] = ((0.0306867547f * fTemp7) + (fRec658 + (fRec670 + (fRec679 + fRec682))));
			output21[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec21[((IOTA - iConst42) & 511)])));
			float fTemp163 = (fConst24 * (0.0f - ((fConst26 * fRec690[1]) + (fConst25 * fRec687[1]))));
			float fTemp164 = (fConst27 * ((fConst7 * (0.0f - ((fConst29 * fRec696[1]) + (fConst28 * fRec693[1])))) + (fConst30 * ((((0.0419299453f * fTemp9) + (0.0159036927f * fTemp13)) + (0.109385349f * fTemp15)) - (((((0.0163425673f * fTemp10) + (0.0818499923f * fTemp11)) + (0.0292068236f * fTemp12)) + (0.0637075603f * fTemp14)) + (0.0174119938f * fTemp16))))));
			fRec698[0] = (fRec698[1] + fTemp164);
			fRec696[0] = fRec698[0];
			float fRec697 = fTemp164;
			fRec695[0] = (fRec696[0] + fRec695[1]);
			fRec693[0] = fRec695[0];
			float fRec694 = fRec697;
			fRec692[0] = (fTemp163 + (fRec694 + fRec692[1]));
			fRec690[0] = fRec692[0];
			float fRec691 = (fRec694 + fTemp163);
			fRec689[0] = (fRec690[0] + fRec689[1]);
			fRec687[0] = fRec689[0];
			float fRec688 = fRec691;
			float fTemp165 = (fConst31 * ((fConst7 * (0.0f - ((fConst33 * fRec705[1]) + (fConst32 * fRec702[1])))) + (fConst35 * (((0.0641810074f * fTemp21) + (0.0617000088f * fTemp24)) - (((((0.00754182972f * fTemp18) + (0.101283103f * fTemp19)) + (0.0632335618f * fTemp22)) + (0.0310452767f * fTemp23)) + (0.0740576386f * fTemp20))))));
			fRec707[0] = (fRec707[1] + fTemp165);
			fRec705[0] = fRec707[0];
			float fRec706 = fTemp165;
			fRec704[0] = (fRec705[0] + fRec704[1]);
			fRec702[0] = fRec704[0];
			float fRec703 = fRec706;
			float fTemp166 = (fConst36 * fRec699[1]);
			fRec701[0] = ((fRec703 + fRec701[1]) - fTemp166);
			fRec699[0] = fRec701[0];
			float fRec700 = (fRec703 - fTemp166);
			float fTemp167 = (fConst37 * ((((0.0639034882f * fTemp27) + (0.0554443188f * fTemp28)) - (0.032747671f * fTemp29)) - (fConst38 * fRec708[1])));
			fRec710[0] = (fRec710[1] + fTemp167);
			fRec708[0] = fRec710[0];
			float fRec709 = fTemp167;
			float fTemp168 = (fConst39 * ((((0.104496494f * fTemp32) + (0.00707863364f * fTemp35)) - (((0.060076911f * fTemp31) + (0.0527373105f * fTemp33)) + (0.0425387397f * fTemp34))) + (fConst7 * (0.0f - ((fConst41 * fRec714[1]) + (fConst40 * fRec711[1]))))));
			fRec716[0] = (fRec716[1] + fTemp168);
			fRec714[0] = fRec716[0];
			float fRec715 = fTemp168;
			fRec713[0] = (fRec714[0] + fRec713[1]);
			fRec711[0] = fRec713[0];
			float fRec712 = fRec715;
			fVec22[(IOTA & 511)] = ((0.0315846391f * fTemp7) + (fRec688 + (fRec700 + (fRec709 + fRec712))));
			output22[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec22[((IOTA - iConst42) & 511)])));
			float fTemp169 = (fConst24 * (0.0f - ((fConst26 * fRec720[1]) + (fConst25 * fRec717[1]))));
			float fTemp170 = (fConst27 * ((fConst7 * (0.0f - ((fConst29 * fRec726[1]) + (fConst28 * fRec723[1])))) + (fConst30 * (((0.0756927952f * fTemp11) + (0.00475854473f * fTemp16)) - ((((((0.0407784693f * fTemp9) + (0.0595153384f * fTemp10)) + (0.00977543183f * fTemp12)) + (0.0149599239f * fTemp13)) + (0.106441252f * fTemp14)) + (0.103464738f * fTemp15))))));
			fRec728[0] = (fRec728[1] + fTemp170);
			fRec726[0] = fRec728[0];
			float fRec727 = fTemp170;
			fRec725[0] = (fRec726[0] + fRec725[1]);
			fRec723[0] = fRec725[0];
			float fRec724 = fRec727;
			fRec722[0] = (fTemp169 + (fRec724 + fRec722[1]));
			fRec720[0] = fRec722[0];
			float fRec721 = (fRec724 + fTemp169);
			fRec719[0] = (fRec720[0] + fRec719[1]);
			fRec717[0] = fRec719[0];
			float fRec718 = fRec721;
			float fTemp171 = (fConst31 * ((fConst7 * (0.0f - ((fConst33 * fRec735[1]) + (fConst32 * fRec732[1])))) + (fConst35 * ((((0.0947564617f * fTemp19) + (0.100904204f * fTemp21)) + (0.0285659917f * fTemp23)) - ((((0.0318921804f * fTemp18) + (0.0653947592f * fTemp22)) + (0.117315032f * fTemp20)) + (0.0588143505f * fTemp24))))));
			fRec737[0] = (fRec737[1] + fTemp171);
			fRec735[0] = fRec737[0];
			float fRec736 = fTemp171;
			fRec734[0] = (fRec735[0] + fRec734[1]);
			fRec732[0] = fRec734[0];
			float fRec733 = fRec736;
			float fTemp172 = (fConst36 * fRec729[1]);
			fRec731[0] = ((fRec733 + fRec731[1]) - fTemp172);
			fRec729[0] = fRec731[0];
			float fRec730 = (fRec733 - fTemp172);
			float fTemp173 = (fConst37 * ((((0.0863064751f * fTemp27) + (0.0777221099f * fTemp28)) + (0.0305791534f * fTemp29)) - (fConst38 * fRec738[1])));
			fRec740[0] = (fRec740[1] + fTemp173);
			fRec738[0] = fRec740[0];
			float fRec739 = fTemp173;
			float fTemp174 = (fConst39 * ((((((0.0565207601f * fTemp31) + (0.144724205f * fTemp32)) + (0.0212296043f * fTemp35)) + (0.0490482822f * fTemp33)) - (0.0669515878f * fTemp34)) + (fConst7 * (0.0f - ((fConst41 * fRec744[1]) + (fConst40 * fRec741[1]))))));
			fRec746[0] = (fRec746[1] + fTemp174);
			fRec744[0] = fRec746[0];
			float fRec745 = fTemp174;
			fRec743[0] = (fRec744[0] + fRec743[1]);
			fRec741[0] = fRec743[0];
			float fRec742 = fRec745;
			fVec23[(IOTA & 511)] = ((0.0424795263f * fTemp7) + (fRec718 + (fRec730 + (fRec739 + fRec742))));
			output23[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec23[((IOTA - iConst42) & 511)])));
			float fTemp175 = (fConst44 * (0.0f - ((fConst46 * fRec750[1]) + (fConst45 * fRec747[1]))));
			float fTemp176 = (fConst47 * ((fConst7 * (0.0f - ((fConst49 * fRec756[1]) + (fConst48 * fRec753[1])))) + (fConst50 * (((((0.0194436368f * fTemp10) + (0.077527307f * fTemp11)) + (0.0911705643f * fTemp12)) + (0.0908243954f * fTemp13)) - ((((6.83277976e-05f * fTemp9) + (0.000459078088f * fTemp14)) + (0.0198233444f * fTemp15)) + (0.00553432945f * fTemp16))))));
			fRec758[0] = (fRec758[1] + fTemp176);
			fRec756[0] = fRec758[0];
			float fRec757 = fTemp176;
			fRec755[0] = (fRec756[0] + fRec755[1]);
			fRec753[0] = fRec755[0];
			float fRec754 = fRec757;
			fRec752[0] = (fTemp175 + (fRec754 + fRec752[1]));
			fRec750[0] = fRec752[0];
			float fRec751 = (fRec754 + fTemp175);
			fRec749[0] = (fRec750[0] + fRec749[1]);
			fRec747[0] = fRec749[0];
			float fRec748 = fRec751;
			float fTemp177 = (fConst51 * ((fConst7 * (0.0f - ((fConst53 * fRec765[1]) + (fConst52 * fRec762[1])))) + (fConst55 * ((((((0.0074215373f * fTemp18) + (0.0473105311f * fTemp19)) + (0.0802268013f * fTemp21)) + (0.0742492676f * fTemp22)) + (0.079867281f * fTemp23)) - ((0.000284629699f * fTemp20) + (0.00756452931f * fTemp24))))));
			fRec767[0] = (fRec767[1] + fTemp177);
			fRec765[0] = fRec767[0];
			float fRec766 = fTemp177;
			fRec764[0] = (fRec765[0] + fRec764[1]);
			fRec762[0] = fRec764[0];
			float fRec763 = fRec766;
			float fTemp178 = (fConst56 * fRec759[1]);
			fRec761[0] = ((fRec763 + fRec761[1]) - fTemp178);
			fRec759[0] = fRec761[0];
			float fRec760 = (fRec763 - fTemp178);
			float fTemp179 = (fConst57 * ((((0.0220263973f * fTemp27) + (0.0669407099f * fTemp28)) + (0.0219154879f * fTemp29)) - (fConst58 * fRec768[1])));
			fRec770[0] = (fRec770[1] + fTemp179);
			fRec768[0] = fRec770[0];
			float fRec769 = fTemp179;
			float fTemp180 = (fConst59 * ((((((0.018889524f * fTemp31) + (0.0532528348f * fTemp32)) + (0.0843550116f * fTemp35)) + (0.0529947691f * fTemp33)) - (0.000114328701f * fTemp34)) + (fConst7 * (0.0f - ((fConst61 * fRec774[1]) + (fConst60 * fRec771[1]))))));
			fRec776[0] = (fRec776[1] + fTemp180);
			fRec774[0] = fRec776[0];
			float fRec775 = fTemp180;
			fRec773[0] = (fRec774[0] + fRec773[1]);
			fRec771[0] = fRec773[0];
			float fRec772 = fRec775;
			fVec24[(IOTA & 255)] = ((0.0254848376f * fTemp7) + (fRec748 + (fRec760 + (fRec769 + fRec772))));
			output24[i] = FAUSTFLOAT((0.953550935f * (fRec0[0] * fVec24[((IOTA - iConst62) & 255)])));
			float fTemp181 = (fConst44 * (0.0f - ((fConst46 * fRec780[1]) + (fConst45 * fRec777[1]))));
			float fTemp182 = (fConst47 * ((fConst7 * (0.0f - ((fConst49 * fRec786[1]) + (fConst48 * fRec783[1])))) + (fConst50 * (((((0.000109554901f * fTemp9) + (0.132225081f * fTemp13)) + (0.042095311f * fTemp14)) + (0.000336636207f * fTemp15)) - ((((0.018938804f * fTemp10) + (0.076722607f * fTemp11)) + (0.0905564278f * fTemp12)) + (0.000502231414f * fTemp16))))));
			fRec788[0] = (fRec788[1] + fTemp182);
			fRec786[0] = fRec788[0];
			float fRec787 = fTemp182;
			fRec785[0] = (fRec786[0] + fRec785[1]);
			fRec783[0] = fRec785[0];
			float fRec784 = fRec787;
			fRec782[0] = (fTemp181 + (fRec784 + fRec782[1]));
			fRec780[0] = fRec782[0];
			float fRec781 = (fRec784 + fTemp181);
			fRec779[0] = (fRec780[0] + fRec779[1]);
			fRec777[0] = fRec779[0];
			float fRec778 = fRec781;
			float fTemp183 = (fConst51 * ((fConst7 * (0.0f - ((fConst53 * fRec795[1]) + (fConst52 * fRec792[1])))) + (fConst55 * (((((0.0834174529f * fTemp22) + (0.124596156f * fTemp23)) + (0.0269801356f * fTemp20)) + (0.000197635905f * fTemp24)) - (((0.00728073809f * fTemp18) + (0.0470621698f * fTemp19)) + (0.0801182613f * fTemp21))))));
			fRec797[0] = (fRec797[1] + fTemp183);
			fRec795[0] = fRec797[0];
			float fRec796 = fTemp183;
			fRec794[0] = (fRec795[0] + fRec794[1]);
			fRec792[0] = fRec794[0];
			float fRec793 = fRec796;
			float fTemp184 = (fConst56 * fRec789[1]);
			fRec791[0] = ((fRec793 + fRec791[1]) - fTemp184);
			fRec789[0] = fRec791[0];
			float fRec790 = (fRec793 - fTemp184);
			float fTemp185 = (fConst57 * ((((0.0882500932f * fTemp28) + (0.0363471471f * fTemp29)) - (0.0221166983f * fTemp27)) - (fConst58 * fRec798[1])));
			fRec800[0] = (fRec800[1] + fTemp185);
			fRec798[0] = fRec800[0];
			float fRec799 = fTemp185;
			float fTemp186 = (fConst59 * (((((0.105921619f * fTemp35) + (0.0859909728f * fTemp33)) + (0.0110994196f * fTemp34)) - ((0.0188521147f * fTemp31) + (0.0533630475f * fTemp32))) + (fConst7 * (0.0f - ((fConst61 * fRec804[1]) + (fConst60 * fRec801[1]))))));
			fRec806[0] = (fRec806[1] + fTemp186);
			fRec804[0] = fRec806[0];
			float fRec805 = fTemp186;
			fRec803[0] = (fRec804[0] + fRec803[1]);
			fRec801[0] = fRec803[0];
			float fRec802 = fRec805;
			fVec25[(IOTA & 255)] = ((0.0342672393f * fTemp7) + (fRec778 + (fRec790 + (fRec799 + fRec802))));
			output25[i] = FAUSTFLOAT((0.953550935f * (fRec0[0] * fVec25[((IOTA - iConst62) & 255)])));
			float fTemp187 = (fConst44 * (0.0f - ((fConst46 * fRec810[1]) + (fConst45 * fRec807[1]))));
			float fTemp188 = (fConst47 * ((fConst7 * (0.0f - ((fConst49 * fRec816[1]) + (fConst48 * fRec813[1])))) + (fConst50 * (((0.0778864697f * fTemp11) + (0.0196926109f * fTemp15)) - ((((((3.87945984e-05f * fTemp9) + (0.000475032401f * fTemp10)) + (0.131163478f * fTemp12)) + (0.090854004f * fTemp13)) + (0.0409009978f * fTemp14)) + (0.000748532009f * fTemp16))))));
			fRec818[0] = (fRec818[1] + fTemp188);
			fRec816[0] = fRec818[0];
			float fRec817 = fTemp188;
			fRec815[0] = (fRec816[0] + fRec815[1]);
			fRec813[0] = fRec815[0];
			float fRec814 = fRec817;
			fRec812[0] = (fTemp187 + (fRec814 + fRec812[1]));
			fRec810[0] = fRec812[0];
			float fRec811 = (fRec814 + fTemp187);
			fRec809[0] = (fRec810[0] + fRec809[1]);
			fRec807[0] = fRec809[0];
			float fRec808 = fRec811;
			float fTemp189 = (fConst51 * ((fConst7 * (0.0f - ((fConst53 * fRec825[1]) + (fConst52 * fRec822[1])))) + (fConst55 * ((((0.0478923619f * fTemp19) + (0.0830633044f * fTemp22)) + (0.0075846198f * fTemp24)) - ((((0.000135484996f * fTemp18) + (0.123520717f * fTemp21)) + (0.0806420296f * fTemp23)) + (0.026178807f * fTemp20))))));
			fRec827[0] = (fRec827[1] + fTemp189);
			fRec825[0] = fRec827[0];
			float fRec826 = fTemp189;
			fRec824[0] = (fRec825[0] + fRec824[1]);
			fRec822[0] = fRec824[0];
			float fRec823 = fRec826;
			float fTemp190 = (fConst56 * fRec819[1]);
			fRec821[0] = ((fRec823 + fRec821[1]) - fTemp190);
			fRec819[0] = fRec821[0];
			float fRec820 = (fRec823 - fTemp190);
			float fTemp191 = (fConst57 * (((0.0877469257f * fTemp28) - ((0.0360210091f * fTemp27) + (0.0223415233f * fTemp29))) - (fConst58 * fRec828[1])));
			fRec830[0] = (fRec830[1] + fTemp191);
			fRec828[0] = fRec830[0];
			float fRec829 = fTemp191;
			float fTemp192 = (fConst59 * ((((0.0192173701f * fTemp31) + (0.105352052f * fTemp35)) - (((0.0852277726f * fTemp32) + (0.0538309142f * fTemp33)) + (0.010759919f * fTemp34))) + (fConst7 * (0.0f - ((fConst61 * fRec834[1]) + (fConst60 * fRec831[1]))))));
			fRec836[0] = (fRec836[1] + fTemp192);
			fRec834[0] = fRec836[0];
			float fRec835 = fTemp192;
			fRec833[0] = (fRec834[0] + fRec833[1]);
			fRec831[0] = fRec833[0];
			float fRec832 = fRec835;
			fVec26[(IOTA & 255)] = ((0.0340686888f * fTemp7) + (fRec808 + (fRec820 + (fRec829 + fRec832))));
			output26[i] = FAUSTFLOAT((0.953550935f * (fRec0[0] * fVec26[((IOTA - iConst62) & 255)])));
			float fTemp193 = (fConst44 * (0.0f - ((fConst46 * fRec840[1]) + (fConst45 * fRec837[1]))));
			float fTemp194 = (fConst47 * ((fConst7 * (0.0f - ((fConst49 * fRec846[1]) + (fConst48 * fRec843[1])))) + (fConst50 * (((((8.28270004e-06f * fTemp10) + (0.130368814f * fTemp12)) + (0.000216475397f * fTemp14)) + (0.00432097353f * fTemp16)) - ((((0.000161736898f * fTemp9) + (0.076127179f * fTemp11)) + (0.129802823f * fTemp13)) + (0.000791169296f * fTemp15))))));
			fRec848[0] = (fRec848[1] + fTemp194);
			fRec846[0] = fRec848[0];
			float fRec847 = fTemp194;
			fRec845[0] = (fRec846[0] + fRec845[1]);
			fRec843[0] = fRec845[0];
			float fRec844 = fRec847;
			fRec842[0] = (fTemp193 + (fRec844 + fRec842[1]));
			fRec840[0] = fRec842[0];
			float fRec841 = (fRec844 + fTemp193);
			fRec839[0] = (fRec840[0] + fRec839[1]);
			fRec837[0] = fRec839[0];
			float fRec838 = fRec841;
			float fTemp195 = (fConst51 * ((fConst7 * (0.0f - ((fConst53 * fRec855[1]) + (fConst52 * fRec852[1])))) + (fConst55 * (((((4.65120002e-06f * fTemp18) + (0.12317846f * fTemp21)) + (0.0915987045f * fTemp22)) + (0.000248749187f * fTemp20)) - (((0.0469808392f * fTemp19) + (0.122870371f * fTemp23)) + (0.000332433206f * fTemp24))))));
			fRec857[0] = (fRec857[1] + fTemp195);
			fRec855[0] = fRec857[0];
			float fRec856 = fTemp195;
			fRec854[0] = (fRec855[0] + fRec854[1]);
			fRec852[0] = fRec854[0];
			float fRec853 = fRec856;
			float fTemp196 = (fConst56 * fRec849[1]);
			fRec851[0] = ((fRec853 + fRec851[1]) - fTemp196);
			fRec849[0] = fRec851[0];
			float fRec850 = (fRec853 - fTemp196);
			float fTemp197 = (fConst57 * ((((0.0360226892f * fTemp27) + (0.107946441f * fTemp28)) - (0.0360071734f * fTemp29)) - (fConst58 * fRec858[1])));
			fRec860[0] = (fRec860[1] + fTemp197);
			fRec858[0] = fRec860[0];
			float fRec859 = fTemp197;
			float fTemp198 = (fConst59 * (((((0.0851469785f * fTemp32) + (0.1257305f * fTemp35)) + (0.000132581597f * fTemp34)) - ((0.0188934803f * fTemp31) + (0.0850421339f * fTemp33))) + (fConst7 * (0.0f - ((fConst61 * fRec864[1]) + (fConst60 * fRec861[1]))))));
			fRec866[0] = (fRec866[1] + fTemp198);
			fRec864[0] = fRec866[0];
			float fRec865 = fTemp198;
			fRec863[0] = (fRec864[0] + fRec863[1]);
			fRec861[0] = fRec863[0];
			float fRec862 = fRec865;
			fVec27[(IOTA & 255)] = ((0.0424027964f * fTemp7) + (fRec838 + (fRec850 + (fRec859 + fRec862))));
			output27[i] = FAUSTFLOAT((0.953550935f * (fRec0[0] * fVec27[((IOTA - iConst62) & 255)])));
			float fTemp199 = (fConst64 * (0.0f - ((fConst66 * fRec870[1]) + (fConst65 * fRec867[1]))));
			float fTemp200 = (fConst67 * ((fConst7 * (0.0f - ((fConst69 * fRec876[1]) + (fConst68 * fRec873[1])))) + (fConst70 * ((((((3.36400007e-07f * fTemp9) + (2.07609992e-06f * fTemp10)) + (7.33870002e-06f * fTemp11)) + (1.80029001e-05f * fTemp12)) + (3.32690001e-06f * fTemp15)) - (((6.39241989e-05f * fTemp13) + (1.12209e-05f * fTemp14)) + (2.78666994e-05f * fTemp16))))));
			fRec878[0] = (fRec878[1] + fTemp200);
			fRec876[0] = fRec878[0];
			float fRec877 = fTemp200;
			fRec875[0] = (fRec876[0] + fRec875[1]);
			fRec873[0] = fRec875[0];
			float fRec874 = fRec877;
			fRec872[0] = (fTemp199 + (fRec874 + fRec872[1]));
			fRec870[0] = fRec872[0];
			float fRec871 = (fRec874 + fTemp199);
			fRec869[0] = (fRec870[0] + fRec869[1]);
			fRec867[0] = fRec869[0];
			float fRec868 = fRec871;
			float fTemp201 = (fConst71 * ((fConst7 * (0.0f - ((fConst73 * fRec885[1]) + (fConst72 * fRec882[1])))) + (fConst75 * ((((((6.30999978e-07f * fTemp18) + (3.4689001e-06f * fTemp19)) + (1.10317997e-05f * fTemp21)) + (0.0662800893f * fTemp22)) + (1.05430001e-06f * fTemp24)) - ((4.28226012e-05f * fTemp23) + (5.28999999e-06f * fTemp20))))));
			fRec887[0] = (fRec887[1] + fTemp201);
			fRec885[0] = fRec887[0];
			float fRec886 = fTemp201;
			fRec884[0] = (fRec885[0] + fRec884[1]);
			fRec882[0] = fRec884[0];
			float fRec883 = fRec886;
			float fTemp202 = (fConst76 * fRec879[1]);
			fRec881[0] = ((fRec883 + fRec881[1]) - fTemp202);
			fRec879[0] = fRec881[0];
			float fRec880 = (fRec883 - fTemp202);
			float fTemp203 = (fConst77 * ((((1.96569999e-06f * fTemp27) + (0.030448107f * fTemp28)) - (8.51769983e-06f * fTemp29)) - (fConst78 * fRec888[1])));
			fRec890[0] = (fRec890[1] + fTemp203);
			fRec888[0] = fRec890[0];
			float fRec889 = fTemp203;
			float fTemp204 = (fConst79 * (((((1.15119997e-06f * fTemp31) + (5.6355002e-06f * fTemp32)) + (0.0493629165f * fTemp35)) - ((2.33718001e-05f * fTemp33) + (1.75180003e-06f * fTemp34))) + (fConst7 * (0.0f - ((fConst81 * fRec894[1]) + (fConst80 * fRec891[1]))))));
			fRec896[0] = (fRec896[1] + fTemp204);
			fRec894[0] = fRec896[0];
			float fRec895 = fTemp204;
			fRec893[0] = (fRec894[0] + fRec893[1]);
			fRec891[0] = fRec893[0];
			float fRec892 = fRec895;
			output28[i] = FAUSTFLOAT((fRec0[0] * ((0.0102900397f * fTemp7) + (fRec868 + (fRec880 + (fRec889 + fRec892))))));
			float fTemp205 = (fConst3 * (0.0f - ((fConst5 * fRec900[1]) + (fConst4 * fRec897[1]))));
			float fTemp206 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec906[1]) + (fConst8 * fRec903[1])))) + (fConst10 * ((((0.124327689f * fTemp9) + (0.0173993371f * fTemp12)) + (0.0387861095f * fTemp13)) - (((((0.0953899845f * fTemp10) + (0.00408663601f * fTemp11)) + (0.00362289255f * fTemp14)) + (0.0301249772f * fTemp15)) + (0.0144284507f * fTemp16))))));
			fRec908[0] = (fRec908[1] + fTemp206);
			fRec906[0] = fRec908[0];
			float fRec907 = fTemp206;
			fRec905[0] = (fRec906[0] + fRec905[1]);
			fRec903[0] = fRec905[0];
			float fRec904 = fRec907;
			fRec902[0] = (fTemp205 + (fRec904 + fRec902[1]));
			fRec900[0] = fRec902[0];
			float fRec901 = (fRec904 + fTemp205);
			fRec899[0] = (fRec900[0] + fRec899[1]);
			fRec897[0] = fRec899[0];
			float fRec898 = fRec901;
			float fTemp207 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec915[1]) + (fConst12 * fRec912[1])))) + (fConst15 * ((((0.116330676f * fTemp18) + (0.0429094099f * fTemp22)) + (0.036740616f * fTemp24)) - ((((0.0694192946f * fTemp19) + (0.00874171685f * fTemp21)) + (0.0194796026f * fTemp23)) + (0.0618114136f * fTemp20))))));
			fRec917[0] = (fRec917[1] + fTemp207);
			fRec915[0] = fRec917[0];
			float fRec916 = fTemp207;
			fRec914[0] = (fRec915[0] + fRec914[1]);
			fRec912[0] = fRec914[0];
			float fRec913 = fRec916;
			float fTemp208 = (fConst16 * fRec909[1]);
			fRec911[0] = ((fRec913 + fRec911[1]) - fTemp208);
			fRec909[0] = fRec911[0];
			float fRec910 = (fRec913 - fTemp208);
			float fTemp209 = (fConst17 * ((((0.035999883f * fTemp27) + (0.0802532509f * fTemp29)) - (0.0359963588f * fTemp28)) - (fConst18 * fRec918[1])));
			fRec920[0] = (fRec920[1] + fTemp209);
			fRec918[0] = fRec920[0];
			float fRec919 = fTemp209;
			float fTemp210 = (fConst19 * ((((0.0824521556f * fTemp31) + (0.0734153241f * fTemp34)) - (((0.0316373929f * fTemp32) + (0.0314096399f * fTemp35)) + (0.0705286413f * fTemp33))) + (fConst7 * (0.0f - ((fConst21 * fRec924[1]) + (fConst20 * fRec921[1]))))));
			fRec926[0] = (fRec926[1] + fTemp210);
			fRec924[0] = fRec926[0];
			float fRec925 = fTemp210;
			fRec923[0] = (fRec924[0] + fRec923[1]);
			fRec921[0] = fRec923[0];
			float fRec922 = fRec925;
			fVec28[(IOTA & 1023)] = ((0.0339854807f * fTemp7) + (fRec898 + (fRec910 + (fRec919 + fRec922))));
			output29[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec28[((IOTA - iConst22) & 1023)])));
			float fTemp211 = (fConst3 * (0.0f - ((fConst5 * fRec930[1]) + (fConst4 * fRec927[1]))));
			float fTemp212 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec936[1]) + (fConst8 * fRec933[1])))) + (fConst10 * (((((0.0124847619f * fTemp9) + (0.00101428304f * fTemp12)) + (0.041893933f * fTemp13)) + (0.125446275f * fTemp16)) - ((((0.00736321602f * fTemp10) + (0.000309618597f * fTemp11)) + (0.00649852492f * fTemp14)) + (0.0991315767f * fTemp15))))));
			fRec938[0] = (fRec938[1] + fTemp212);
			fRec936[0] = fRec938[0];
			float fRec937 = fTemp212;
			fRec935[0] = (fRec936[0] + fRec935[1]);
			fRec933[0] = fRec935[0];
			float fRec934 = fRec937;
			fRec932[0] = (fTemp211 + (fRec934 + fRec932[1]));
			fRec930[0] = fRec932[0];
			float fRec931 = (fRec934 + fTemp211);
			fRec929[0] = (fRec930[0] + fRec929[1]);
			fRec927[0] = fRec929[0];
			float fRec928 = fRec931;
			float fTemp213 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec945[1]) + (fConst12 * fRec942[1])))) + (fConst15 * ((((0.0091264993f * fTemp18) + (0.0425243415f * fTemp22)) + (0.122487433f * fTemp24)) - ((((0.00456995331f * fTemp19) + (0.000541947316f * fTemp21)) + (0.0222903229f * fTemp23)) + (0.0922545791f * fTemp20))))));
			fRec947[0] = (fRec947[1] + fTemp213);
			fRec945[0] = fRec947[0];
			float fRec946 = fTemp213;
			fRec944[0] = (fRec945[0] + fRec944[1]);
			fRec942[0] = fRec944[0];
			float fRec943 = fRec946;
			float fTemp214 = (fConst16 * fRec939[1]);
			fRec941[0] = ((fRec943 + fRec941[1]) - fTemp214);
			fRec939[0] = fRec941[0];
			float fRec940 = (fRec943 - fTemp214);
			float fTemp215 = (fConst17 * ((((0.00219289516f * fTemp27) + (0.0883968771f * fTemp29)) - (0.0357965156f * fTemp28)) - (fConst18 * fRec948[1])));
			fRec950[0] = (fRec950[1] + fTemp215);
			fRec948[0] = fRec950[0];
			float fRec949 = fTemp215;
			float fTemp216 = (fConst19 * ((((0.00550525961f * fTemp31) + (0.110944867f * fTemp34)) - (((0.00190552254f * fTemp32) + (0.0319326818f * fTemp35)) + (0.0768105313f * fTemp33))) + (fConst7 * (0.0f - ((fConst21 * fRec954[1]) + (fConst20 * fRec951[1]))))));
			fRec956[0] = (fRec956[1] + fTemp216);
			fRec954[0] = fRec956[0];
			float fRec955 = fTemp216;
			fRec953[0] = (fRec954[0] + fRec953[1]);
			fRec951[0] = fRec953[0];
			float fRec952 = fRec955;
			fVec29[(IOTA & 1023)] = ((0.0341288708f * fTemp7) + (fRec928 + (fRec940 + (fRec949 + fRec952))));
			output30[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec29[((IOTA - iConst22) & 1023)])));
			float fTemp217 = (fConst3 * (0.0f - ((fConst5 * fRec960[1]) + (fConst4 * fRec957[1]))));
			float fTemp218 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec966[1]) + (fConst8 * fRec963[1])))) + (fConst10 * (((((0.0895847157f * fTemp10) + (0.00376143958f * fTemp11)) + (0.0394109115f * fTemp13)) + (0.0108904168f * fTemp16)) - ((((0.124775447f * fTemp9) + (0.0153160999f * fTemp12)) + (0.00409794971f * fTemp14)) + (0.0441886708f * fTemp15))))));
			fRec968[0] = (fRec968[1] + fTemp218);
			fRec966[0] = fRec968[0];
			float fRec967 = fTemp218;
			fRec965[0] = (fRec966[0] + fRec965[1]);
			fRec963[0] = fRec965[0];
			float fRec964 = fRec967;
			fRec962[0] = (fTemp217 + (fRec964 + fRec962[1]));
			fRec960[0] = fRec962[0];
			float fRec961 = (fRec964 + fTemp217);
			fRec959[0] = (fRec960[0] + fRec959[1]);
			fRec957[0] = fRec959[0];
			float fRec958 = fRec961;
			float fTemp219 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec975[1]) + (fConst12 * fRec972[1])))) + (fConst15 * (((((0.0627030432f * fTemp19) + (0.0077611804f * fTemp21)) + (0.0427538119f * fTemp22)) + (0.0539708249f * fTemp24)) - (((0.109478533f * fTemp18) + (0.0199568607f * fTemp23)) + (0.0684331357f * fTemp20))))));
			fRec977[0] = (fRec977[1] + fTemp219);
			fRec975[0] = fRec977[0];
			float fRec976 = fTemp219;
			fRec974[0] = (fRec975[0] + fRec974[1]);
			fRec972[0] = fRec974[0];
			float fRec973 = fRec976;
			float fTemp220 = (fConst16 * fRec969[1]);
			fRec971[0] = ((fRec973 + fRec971[1]) - fTemp220);
			fRec969[0] = fRec971[0];
			float fRec970 = (fRec973 - fTemp220);
			float fTemp221 = (fConst17 * (((0.0819987282f * fTemp29) - ((0.0318913348f * fTemp27) + (0.0359743834f * fTemp28))) - (fConst18 * fRec978[1])));
			fRec980[0] = (fRec980[1] + fTemp221);
			fRec978[0] = fRec980[0];
			float fRec979 = fTemp221;
			float fTemp222 = (fConst19 * ((((0.0279819071f * fTemp32) + (0.0814200118f * fTemp34)) - (((0.0746196881f * fTemp31) + (0.0314135253f * fTemp35)) + (0.0719548613f * fTemp33))) + (fConst7 * (0.0f - ((fConst21 * fRec984[1]) + (fConst20 * fRec981[1]))))));
			fRec986[0] = (fRec986[1] + fTemp222);
			fRec984[0] = fRec986[0];
			float fRec985 = fTemp222;
			fRec983[0] = (fRec984[0] + fRec983[1]);
			fRec981[0] = fRec983[0];
			float fRec982 = fRec985;
			fVec30[(IOTA & 1023)] = ((0.0339966118f * fTemp7) + (fRec958 + (fRec970 + (fRec979 + fRec982))));
			output31[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec30[((IOTA - iConst22) & 1023)])));
			float fTemp223 = (fConst3 * (0.0f - ((fConst5 * fRec990[1]) + (fConst4 * fRec987[1]))));
			float fTemp224 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec996[1]) + (fConst8 * fRec993[1])))) + (fConst10 * (((((0.0741010234f * fTemp10) + (0.00642281957f * fTemp11)) + (0.0304159857f * fTemp13)) + (0.0672443956f * fTemp15)) - ((((0.00836381689f * fTemp9) + (0.0294120237f * fTemp12)) + (0.000307593f * fTemp14)) + (0.12623553f * fTemp16))))));
			fRec998[0] = (fRec998[1] + fTemp224);
			fRec996[0] = fRec998[0];
			float fRec997 = fTemp224;
			fRec995[0] = (fRec996[0] + fRec995[1]);
			fRec993[0] = fRec995[0];
			float fRec994 = fRec997;
			fRec992[0] = (fTemp223 + (fRec994 + fRec992[1]));
			fRec990[0] = fRec992[0];
			float fRec991 = (fRec994 + fTemp223);
			fRec989[0] = (fRec990[0] + fRec989[1]);
			fRec987[0] = fRec989[0];
			float fRec988 = fRec991;
			float fTemp225 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec1005[1]) + (fConst12 * fRec1002[1])))) + (fConst15 * ((((0.0930354074f * fTemp19) + (0.0155132031f * fTemp21)) + (0.0429151803f * fTemp22)) - ((((0.0915021524f * fTemp18) + (0.0160977617f * fTemp23)) + (0.00299352896f * fTemp20)) + (0.0828758925f * fTemp24))))));
			fRec1007[0] = (fRec1007[1] + fTemp225);
			fRec1005[0] = fRec1007[0];
			float fRec1006 = fTemp225;
			fRec1004[0] = (fRec1005[0] + fRec1004[1]);
			fRec1002[0] = fRec1004[0];
			float fRec1003 = fRec1006;
			float fTemp226 = (fConst16 * fRec999[1]);
			fRec1001[0] = ((fRec1003 + fRec1001[1]) - fTemp226);
			fRec999[0] = fRec1001[0];
			float fRec1000 = (fRec1003 - fTemp226);
			float fTemp227 = (fConst17 * (((0.0639806613f * fTemp29) - ((0.0619228333f * fTemp27) + (0.0360982791f * fTemp28))) - (fConst18 * fRec1008[1])));
			fRec1010[0] = (fRec1010[1] + fTemp227);
			fRec1008[0] = fRec1010[0];
			float fRec1009 = fTemp227;
			float fTemp228 = (fConst19 * ((((0.0539008714f * fTemp32) + (0.00366872433f * fTemp34)) - (((0.111714162f * fTemp31) + (0.0321240686f * fTemp35)) + (0.0556522273f * fTemp33))) + (fConst7 * (0.0f - ((fConst21 * fRec1014[1]) + (fConst20 * fRec1011[1]))))));
			fRec1016[0] = (fRec1016[1] + fTemp228);
			fRec1014[0] = fRec1016[0];
			float fRec1015 = fTemp228;
			fRec1013[0] = (fRec1014[0] + fRec1013[1]);
			fRec1011[0] = fRec1013[0];
			float fRec1012 = fRec1015;
			fVec31[(IOTA & 1023)] = ((0.0343768448f * fTemp7) + (fRec988 + (fRec1000 + (fRec1009 + fRec1012))));
			output32[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec31[((IOTA - iConst22) & 1023)])));
			float fTemp229 = (fConst3 * (0.0f - ((fConst5 * fRec1020[1]) + (fConst4 * fRec1017[1]))));
			float fTemp230 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec1026[1]) + (fConst8 * fRec1023[1])))) + (fConst10 * ((((((0.126153007f * fTemp9) + (0.00423908513f * fTemp11)) + (0.016766455f * fTemp13)) + (0.00408421876f * fTemp14)) + (0.0941307694f * fTemp15)) - (((0.0356487669f * fTemp10) + (0.0393684395f * fTemp12)) + (0.00512094889f * fTemp16))))));
			fRec1028[0] = (fRec1028[1] + fTemp230);
			fRec1026[0] = fRec1028[0];
			float fRec1027 = fTemp230;
			fRec1025[0] = (fRec1026[0] + fRec1025[1]);
			fRec1023[0] = fRec1025[0];
			float fRec1024 = fRec1027;
			fRec1022[0] = (fTemp229 + (fRec1024 + fRec1022[1]));
			fRec1020[0] = fRec1022[0];
			float fRec1021 = (fRec1024 + fTemp229);
			fRec1019[0] = (fRec1020[0] + fRec1019[1]);
			fRec1017[0] = fRec1019[0];
			float fRec1018 = fRec1021;
			float fTemp231 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec1035[1]) + (fConst12 * fRec1032[1])))) + (fConst15 * ((((((0.0436926894f * fTemp18) + (0.067590557f * fTemp19)) + (0.0201608762f * fTemp21)) + (0.0432680584f * fTemp22)) + (0.0648753643f * fTemp20)) - ((0.00858165231f * fTemp23) + (0.115314394f * fTemp24))))));
			fRec1037[0] = (fRec1037[1] + fTemp231);
			fRec1035[0] = fRec1037[0];
			float fRec1036 = fTemp231;
			fRec1034[0] = (fRec1035[0] + fRec1034[1]);
			fRec1032[0] = fRec1034[0];
			float fRec1033 = fRec1036;
			float fTemp232 = (fConst16 * fRec1029[1]);
			fRec1031[0] = ((fRec1033 + fRec1031[1]) - fTemp232);
			fRec1029[0] = fRec1031[0];
			float fRec1030 = (fRec1033 - fTemp232);
			float fTemp233 = (fConst17 * (((0.0349279977f * fTemp29) - ((0.0819450319f * fTemp27) + (0.0363389291f * fTemp28))) - (fConst18 * fRec1038[1])));
			fRec1040[0] = (fRec1040[1] + fTemp233);
			fRec1038[0] = fRec1040[0];
			float fRec1039 = fTemp233;
			float fTemp234 = (fConst19 * (((0.0717464685f * fTemp32) - ((((0.0806058347f * fTemp31) + (0.0319378078f * fTemp35)) + (0.0305874366f * fTemp33)) + (0.0773844868f * fTemp34))) + (fConst7 * (0.0f - ((fConst21 * fRec1044[1]) + (fConst20 * fRec1041[1]))))));
			fRec1046[0] = (fRec1046[1] + fTemp234);
			fRec1044[0] = fRec1046[0];
			float fRec1045 = fTemp234;
			fRec1043[0] = (fRec1044[0] + fRec1043[1]);
			fRec1041[0] = fRec1043[0];
			float fRec1042 = fRec1045;
			fVec32[(IOTA & 1023)] = ((0.034416955f * fTemp7) + (fRec1018 + (fRec1030 + (fRec1039 + fRec1042))));
			output33[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec32[((IOTA - iConst22) & 1023)])));
			float fTemp235 = (fConst3 * (0.0f - ((fConst5 * fRec1050[1]) + (fConst4 * fRec1047[1]))));
			float fTemp236 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec1056[1]) + (fConst8 * fRec1053[1])))) + (fConst10 * (((((0.000170257801f * fTemp9) + (5.66281014e-05f * fTemp11)) + (0.00615733443f * fTemp14)) + (0.127021343f * fTemp16)) - ((((0.100995019f * fTemp10) + (0.042766232f * fTemp12)) + (1.86345005e-05f * fTemp13)) + (4.46669001e-05f * fTemp15))))));
			fRec1058[0] = (fRec1058[1] + fTemp236);
			fRec1056[0] = fRec1058[0];
			float fRec1057 = fTemp236;
			fRec1055[0] = (fRec1056[0] + fRec1055[1]);
			fRec1053[0] = fRec1055[0];
			float fRec1054 = fRec1057;
			fRec1052[0] = (fTemp235 + (fRec1054 + fRec1052[1]));
			fRec1050[0] = fRec1052[0];
			float fRec1051 = (fRec1054 + fTemp235);
			fRec1049[0] = (fRec1050[0] + fRec1049[1]);
			fRec1047[0] = fRec1049[0];
			float fRec1048 = fRec1051;
			float fTemp237 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec1065[1]) + (fConst12 * fRec1062[1])))) + (fConst15 * (((((0.124215901f * fTemp18) + (0.0222397577f * fTemp21)) + (0.0433858857f * fTemp22)) + (0.0941157937f * fTemp20)) - (((2.72128e-05f * fTemp19) + (2.64532991e-05f * fTemp23)) + (0.0001025116f * fTemp24))))));
			fRec1067[0] = (fRec1067[1] + fTemp237);
			fRec1065[0] = fRec1067[0];
			float fRec1066 = fTemp237;
			fRec1064[0] = (fRec1065[0] + fRec1064[1]);
			fRec1062[0] = fRec1064[0];
			float fRec1063 = fRec1066;
			float fTemp238 = (fConst16 * fRec1059[1]);
			fRec1061[0] = ((fRec1063 + fRec1061[1]) - fTemp238);
			fRec1059[0] = fRec1061[0];
			float fRec1060 = (fRec1063 - fTemp238);
			float fTemp239 = (fConst17 * (((1.68336992e-05f * fTemp29) - ((0.089838244f * fTemp27) + (0.036576286f * fTemp28))) - (fConst18 * fRec1068[1])));
			fRec1070[0] = (fRec1070[1] + fTemp239);
			fRec1068[0] = fRec1070[0];
			float fRec1069 = fTemp239;
			float fTemp240 = (fConst19 * ((((0.078430444f * fTemp32) + (1.09431003e-05f * fTemp33)) - (((5.12437e-05f * fTemp31) + (0.0322479792f * fTemp35)) + (0.11264503f * fTemp34))) + (fConst7 * (0.0f - ((fConst21 * fRec1074[1]) + (fConst20 * fRec1071[1]))))));
			fRec1076[0] = (fRec1076[1] + fTemp240);
			fRec1074[0] = fRec1076[0];
			float fRec1075 = fTemp240;
			fRec1073[0] = (fRec1074[0] + fRec1073[1]);
			fRec1071[0] = fRec1073[0];
			float fRec1072 = fRec1075;
			fVec33[(IOTA & 1023)] = ((0.0347152688f * fTemp7) + (fRec1048 + (fRec1060 + (fRec1069 + fRec1072))));
			output34[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec33[((IOTA - iConst22) & 1023)])));
			float fTemp241 = (fConst3 * (0.0f - ((fConst5 * fRec1080[1]) + (fConst4 * fRec1077[1]))));
			float fTemp242 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec1086[1]) + (fConst8 * fRec1083[1])))) + (fConst10 * ((0.00431415532f * fTemp14) - (((((((0.127387211f * fTemp9) + (0.0357462578f * fTemp10)) + (0.00452015363f * fTemp11)) + (0.0397359319f * fTemp12)) + (0.0169633292f * fTemp13)) + (0.0950134397f * fTemp15)) + (0.00563937426f * fTemp16))))));
			fRec1088[0] = (fRec1088[1] + fTemp242);
			fRec1086[0] = fRec1088[0];
			float fRec1087 = fTemp242;
			fRec1085[0] = (fRec1086[0] + fRec1085[1]);
			fRec1083[0] = fRec1085[0];
			float fRec1084 = fRec1087;
			fRec1082[0] = (fTemp241 + (fRec1084 + fRec1082[1]));
			fRec1080[0] = fRec1082[0];
			float fRec1081 = (fRec1084 + fTemp241);
			fRec1079[0] = (fRec1080[0] + fRec1079[1]);
			fRec1077[0] = fRec1079[0];
			float fRec1078 = fRec1081;
			float fTemp243 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec1095[1]) + (fConst12 * fRec1092[1])))) + (fConst15 * (((((((0.0439411923f * fTemp18) + (0.0206745304f * fTemp21)) + (0.0437990949f * fTemp22)) + (0.00883316156f * fTemp23)) + (0.0654694811f * fTemp20)) + (0.116882965f * fTemp24)) - (0.0684008896f * fTemp19)))));
			fRec1097[0] = (fRec1097[1] + fTemp243);
			fRec1095[0] = fRec1097[0];
			float fRec1096 = fTemp243;
			fRec1094[0] = (fRec1095[0] + fRec1094[1]);
			fRec1092[0] = fRec1094[0];
			float fRec1093 = fRec1096;
			float fTemp244 = (fConst16 * fRec1089[1]);
			fRec1091[0] = ((fRec1093 + fRec1091[1]) - fTemp244);
			fRec1089[0] = fRec1091[0];
			float fRec1090 = (fRec1093 - fTemp244);
			float fTemp245 = (fConst17 * ((0.0f - (((0.0831632838f * fTemp27) + (0.0367748067f * fTemp28)) + (0.0355247334f * fTemp29))) - (fConst18 * fRec1098[1])));
			fRec1100[0] = (fRec1100[1] + fTemp245);
			fRec1098[0] = fRec1100[0];
			float fRec1099 = fTemp245;
			float fTemp246 = (fConst19 * (((((0.081891045f * fTemp31) + (0.0725768805f * fTemp32)) + (0.0309980847f * fTemp33)) - ((0.0325624011f * fTemp35) + (0.0783597305f * fTemp34))) + (fConst7 * (0.0f - ((fConst21 * fRec1104[1]) + (fConst20 * fRec1101[1]))))));
			fRec1106[0] = (fRec1106[1] + fTemp246);
			fRec1104[0] = fRec1106[0];
			float fRec1105 = fTemp246;
			fRec1103[0] = (fRec1104[0] + fRec1103[1]);
			fRec1101[0] = fRec1103[0];
			float fRec1102 = fRec1105;
			fVec34[(IOTA & 1023)] = ((0.0349377953f * fTemp7) + (fRec1078 + (fRec1090 + (fRec1099 + fRec1102))));
			output35[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec34[((IOTA - iConst22) & 1023)])));
			float fTemp247 = (fConst3 * (0.0f - ((fConst5 * fRec1110[1]) + (fConst4 * fRec1107[1]))));
			float fTemp248 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec1116[1]) + (fConst8 * fRec1113[1])))) + (fConst10 * (((0.00946901273f * fTemp9) + (0.0741061941f * fTemp10)) - ((((((0.00614325562f * fTemp11) + (0.0292092562f * fTemp12)) + (0.0302537754f * fTemp13)) + (0.000392357906f * fTemp14)) + (0.0666246638f * fTemp15)) + (0.125479072f * fTemp16))))));
			fRec1118[0] = (fRec1118[1] + fTemp248);
			fRec1116[0] = fRec1118[0];
			float fRec1117 = fTemp248;
			fRec1115[0] = (fRec1116[0] + fRec1115[1]);
			fRec1113[0] = fRec1115[0];
			float fRec1114 = fRec1117;
			fRec1112[0] = (fTemp247 + (fRec1114 + fRec1112[1]));
			fRec1110[0] = fRec1112[0];
			float fRec1111 = (fRec1114 + fTemp247);
			fRec1109[0] = (fRec1110[0] + fRec1109[1]);
			fRec1107[0] = fRec1109[0];
			float fRec1108 = fRec1111;
			float fTemp249 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec1125[1]) + (fConst12 * fRec1122[1])))) + (fConst15 * (((((0.0151939169f * fTemp21) + (0.0425977856f * fTemp22)) + (0.0158667862f * fTemp23)) + (0.0817185193f * fTemp24)) - (((0.0914314762f * fTemp18) + (0.0925518647f * fTemp19)) + (0.0032696554f * fTemp20))))));
			fRec1127[0] = (fRec1127[1] + fTemp249);
			fRec1125[0] = fRec1127[0];
			float fRec1126 = fTemp249;
			fRec1124[0] = (fRec1125[0] + fRec1124[1]);
			fRec1122[0] = fRec1124[0];
			float fRec1123 = fRec1126;
			float fTemp250 = (fConst16 * fRec1119[1]);
			fRec1121[0] = ((fRec1123 + fRec1121[1]) - fTemp250);
			fRec1119[0] = fRec1121[0];
			float fRec1120 = (fRec1123 - fTemp250);
			float fTemp251 = (fConst17 * ((0.0f - (((0.061302159f * fTemp27) + (0.0359172188f * fTemp28)) + (0.0636048689f * fTemp29))) - (fConst18 * fRec1128[1])));
			fRec1130[0] = (fRec1130[1] + fTemp251);
			fRec1128[0] = fRec1130[0];
			float fRec1129 = fTemp251;
			float fTemp252 = (fConst19 * ((((((0.110855855f * fTemp31) + (0.0535121039f * fTemp32)) + (0.0554308929f * fTemp33)) + (0.00411479175f * fTemp34)) - (0.031729266f * fTemp35)) + (fConst7 * (0.0f - ((fConst21 * fRec1134[1]) + (fConst20 * fRec1131[1]))))));
			fRec1136[0] = (fRec1136[1] + fTemp252);
			fRec1134[0] = fRec1136[0];
			float fRec1135 = fTemp252;
			fRec1133[0] = (fRec1134[0] + fRec1133[1]);
			fRec1131[0] = fRec1133[0];
			float fRec1132 = fRec1135;
			fVec35[(IOTA & 1023)] = ((0.0341170803f * fTemp7) + (fRec1108 + (fRec1120 + (fRec1129 + fRec1132))));
			output36[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec35[((IOTA - iConst22) & 1023)])));
			float fTemp253 = (fConst3 * (0.0f - ((fConst5 * fRec1140[1]) + (fConst4 * fRec1137[1]))));
			float fTemp254 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec1146[1]) + (fConst8 * fRec1143[1])))) + (fConst10 * (((((0.121995203f * fTemp9) + (0.0876571611f * fTemp10)) + (0.0403727852f * fTemp15)) + (0.0066097551f * fTemp16)) - ((((0.00379401655f * fTemp11) + (0.0150329517f * fTemp12)) + (0.0376029462f * fTemp13)) + (0.00405684998f * fTemp14))))));
			fRec1148[0] = (fRec1148[1] + fTemp254);
			fRec1146[0] = fRec1148[0];
			float fRec1147 = fTemp254;
			fRec1145[0] = (fRec1146[0] + fRec1145[1]);
			fRec1143[0] = fRec1145[0];
			float fRec1144 = fRec1147;
			fRec1142[0] = (fTemp253 + (fRec1144 + fRec1142[1]));
			fRec1140[0] = fRec1142[0];
			float fRec1141 = (fRec1144 + fTemp253);
			fRec1139[0] = (fRec1140[0] + fRec1139[1]);
			fRec1137[0] = fRec1139[0];
			float fRec1138 = fRec1141;
			float fTemp255 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec1155[1]) + (fConst12 * fRec1152[1])))) + (fConst15 * ((((0.00766705768f * fTemp21) + (0.0409235731f * fTemp22)) + (0.0192668233f * fTemp23)) - ((((0.107196979f * fTemp18) + (0.0613573976f * fTemp19)) + (0.0646272302f * fTemp20)) + (0.0495528951f * fTemp24))))));
			fRec1157[0] = (fRec1157[1] + fTemp255);
			fRec1155[0] = fRec1157[0];
			float fRec1156 = fTemp255;
			fRec1154[0] = (fRec1155[0] + fRec1154[1]);
			fRec1152[0] = fRec1154[0];
			float fRec1153 = fRec1156;
			float fTemp256 = (fConst16 * fRec1149[1]);
			fRec1151[0] = ((fRec1153 + fRec1151[1]) - fTemp256);
			fRec1149[0] = fRec1151[0];
			float fRec1150 = (fRec1153 - fTemp256);
			float fTemp257 = (fConst17 * ((0.0f - (((0.0312354527f * fTemp27) + (0.0343445688f * fTemp28)) + (0.0783443823f * fTemp29))) - (fConst18 * fRec1158[1])));
			fRec1160[0] = (fRec1160[1] + fTemp257);
			fRec1158[0] = fRec1160[0];
			float fRec1159 = fTemp257;
			float fTemp258 = (fConst19 * ((((((0.0730925277f * fTemp31) + (0.0273709521f * fTemp32)) + (0.0685870945f * fTemp33)) + (0.0771083161f * fTemp34)) - (0.0302143395f * fTemp35)) + (fConst7 * (0.0f - ((fConst21 * fRec1164[1]) + (fConst20 * fRec1161[1]))))));
			fRec1166[0] = (fRec1166[1] + fTemp258);
			fRec1164[0] = fRec1166[0];
			float fRec1165 = fTemp258;
			fRec1163[0] = (fRec1164[0] + fRec1163[1]);
			fRec1161[0] = fRec1163[0];
			float fRec1162 = fRec1165;
			fVec36[(IOTA & 1023)] = ((0.0325375088f * fTemp7) + (fRec1138 + (fRec1150 + (fRec1159 + fRec1162))));
			output37[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec36[((IOTA - iConst22) & 1023)])));
			float fTemp259 = (fConst3 * (0.0f - ((fConst5 * fRec1170[1]) + (fConst4 * fRec1167[1]))));
			float fTemp260 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec1176[1]) + (fConst8 * fRec1173[1])))) + (fConst10 * (((((0.000107983898f * fTemp11) + (0.000545750721f * fTemp12)) + (0.0990926549f * fTemp15)) + (0.12526463f * fTemp16)) - ((((0.0060428516f * fTemp9) + (0.00373699074f * fTemp10)) + (0.0418308303f * fTemp13)) + (0.00620188238f * fTemp14))))));
			fRec1178[0] = (fRec1178[1] + fTemp260);
			fRec1176[0] = fRec1178[0];
			float fRec1177 = fTemp260;
			fRec1175[0] = (fRec1176[0] + fRec1175[1]);
			fRec1173[0] = fRec1175[0];
			float fRec1174 = fRec1177;
			fRec1172[0] = (fTemp259 + (fRec1174 + fRec1172[1]));
			fRec1170[0] = fRec1172[0];
			float fRec1171 = (fRec1174 + fTemp259);
			fRec1169[0] = (fRec1170[0] + fRec1169[1]);
			fRec1167[0] = fRec1169[0];
			float fRec1168 = fRec1171;
			float fTemp261 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec1185[1]) + (fConst12 * fRec1182[1])))) + (fConst15 * (((((0.00449798722f * fTemp18) + (0.00234379619f * fTemp19)) + (0.0423775166f * fTemp22)) + (0.021923963f * fTemp23)) - (((0.000256278086f * fTemp21) + (0.0920524374f * fTemp20)) + (0.122008726f * fTemp24))))));
			fRec1187[0] = (fRec1187[1] + fTemp261);
			fRec1185[0] = fRec1187[0];
			float fRec1186 = fTemp261;
			fRec1184[0] = (fRec1185[0] + fRec1184[1]);
			fRec1182[0] = fRec1184[0];
			float fRec1183 = fRec1186;
			float fTemp262 = (fConst16 * fRec1179[1]);
			fRec1181[0] = ((fRec1183 + fRec1181[1]) - fTemp262);
			fRec1179[0] = fRec1181[0];
			float fRec1180 = (fRec1183 - fTemp262);
			float fTemp263 = (fConst17 * (((0.00110292342f * fTemp27) - ((0.0356718414f * fTemp28) + (0.0878395364f * fTemp29))) - (fConst18 * fRec1188[1])));
			fRec1190[0] = (fRec1190[1] + fTemp263);
			fRec1188[0] = fRec1190[0];
			float fRec1189 = fTemp263;
			float fTemp264 = (fConst19 * ((((0.076560773f * fTemp33) + (0.110333793f * fTemp34)) - (((0.00274763536f * fTemp31) + (0.000980958692f * fTemp32)) + (0.0316089801f * fTemp35))) + (fConst7 * (0.0f - ((fConst21 * fRec1194[1]) + (fConst20 * fRec1191[1]))))));
			fRec1196[0] = (fRec1196[1] + fTemp264);
			fRec1194[0] = fRec1196[0];
			float fRec1195 = fTemp264;
			fRec1193[0] = (fRec1194[0] + fRec1193[1]);
			fRec1191[0] = fRec1193[0];
			float fRec1192 = fRec1195;
			fVec37[(IOTA & 1023)] = ((0.0339145884f * fTemp7) + (fRec1168 + (fRec1180 + (fRec1189 + fRec1192))));
			output38[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec37[((IOTA - iConst22) & 1023)])));
			float fTemp265 = (fConst3 * (0.0f - ((fConst5 * fRec1200[1]) + (fConst4 * fRec1197[1]))));
			float fTemp266 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec1206[1]) + (fConst8 * fRec1203[1])))) + (fConst10 * ((((0.00423553307f * fTemp11) + (0.0165625084f * fTemp12)) + (0.0361374542f * fTemp15)) - (((((0.125699684f * fTemp9) + (0.0934746787f * fTemp10)) + (0.0391794667f * fTemp13)) + (0.00393926399f * fTemp14)) + (0.00444719149f * fTemp16))))));
			fRec1208[0] = (fRec1208[1] + fTemp266);
			fRec1206[0] = fRec1208[0];
			float fRec1207 = fTemp266;
			fRec1205[0] = (fRec1206[0] + fRec1205[1]);
			fRec1203[0] = fRec1205[0];
			float fRec1204 = fRec1207;
			fRec1202[0] = (fTemp265 + (fRec1204 + fRec1202[1]));
			fRec1200[0] = fRec1202[0];
			float fRec1201 = (fRec1204 + fTemp265);
			fRec1199[0] = (fRec1200[0] + fRec1199[1]);
			fRec1197[0] = fRec1199[0];
			float fRec1198 = fRec1201;
			float fTemp267 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec1215[1]) + (fConst12 * fRec1212[1])))) + (fConst15 * (((((0.11455223f * fTemp18) + (0.0669324473f * fTemp19)) + (0.0430093482f * fTemp22)) + (0.0199841149f * fTemp23)) - (((0.00851813983f * fTemp21) + (0.0648697987f * fTemp20)) + (0.0440146141f * fTemp24))))));
			fRec1217[0] = (fRec1217[1] + fTemp267);
			fRec1215[0] = fRec1217[0];
			float fRec1216 = fTemp267;
			fRec1214[0] = (fRec1215[0] + fRec1214[1]);
			fRec1212[0] = fRec1214[0];
			float fRec1213 = fRec1216;
			float fTemp268 = (fConst16 * fRec1209[1]);
			fRec1211[0] = ((fRec1213 + fRec1211[1]) - fTemp268);
			fRec1209[0] = fRec1211[0];
			float fRec1210 = (fRec1213 - fTemp268);
			float fTemp269 = (fConst17 * (((0.0345684774f * fTemp27) - ((0.0361376181f * fTemp28) + (0.0815256909f * fTemp29))) - (fConst18 * fRec1218[1])));
			fRec1220[0] = (fRec1220[1] + fTemp269);
			fRec1218[0] = fRec1220[0];
			float fRec1219 = fTemp269;
			float fTemp270 = (fConst19 * ((((0.0714279562f * fTemp33) + (0.0772341341f * fTemp34)) - (((0.0798911303f * fTemp31) + (0.0302406531f * fTemp32)) + (0.0317157581f * fTemp35))) + (fConst7 * (0.0f - ((fConst21 * fRec1224[1]) + (fConst20 * fRec1221[1]))))));
			fRec1226[0] = (fRec1226[1] + fTemp270);
			fRec1224[0] = fRec1226[0];
			float fRec1225 = fTemp270;
			fRec1223[0] = (fRec1224[0] + fRec1223[1]);
			fRec1221[0] = fRec1223[0];
			float fRec1222 = fRec1225;
			fVec38[(IOTA & 1023)] = ((0.0342118219f * fTemp7) + (fRec1198 + (fRec1210 + (fRec1219 + fRec1222))));
			output39[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec38[((IOTA - iConst22) & 1023)])));
			float fTemp271 = (fConst3 * (0.0f - ((fConst5 * fRec1230[1]) + (fConst4 * fRec1227[1]))));
			float fTemp272 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec1236[1]) + (fConst8 * fRec1233[1])))) + (fConst10 * (((((0.00351427915f * fTemp9) + (0.00581017649f * fTemp11)) + (0.028783856f * fTemp12)) + (2.33467999e-05f * fTemp14)) - ((((0.0666586906f * fTemp10) + (0.0283595435f * fTemp13)) + (0.0697218403f * fTemp15)) + (0.122442357f * fTemp16))))));
			fRec1238[0] = (fRec1238[1] + fTemp272);
			fRec1236[0] = fRec1238[0];
			float fRec1237 = fTemp272;
			fRec1235[0] = (fRec1236[0] + fRec1235[1]);
			fRec1233[0] = fRec1235[0];
			float fRec1234 = fRec1237;
			fRec1232[0] = (fTemp271 + (fRec1234 + fRec1232[1]));
			fRec1230[0] = fRec1232[0];
			float fRec1231 = (fRec1234 + fTemp271);
			fRec1229[0] = (fRec1230[0] + fRec1229[1]);
			fRec1227[0] = fRec1229[0];
			float fRec1228 = fRec1231;
			float fTemp273 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec1245[1]) + (fConst12 * fRec1242[1])))) + (fConst15 * (((((((0.081919767f * fTemp18) + (0.0890904292f * fTemp19)) + (0.0408936813f * fTemp22)) + (0.0147467684f * fTemp23)) + (0.00133310957f * fTemp20)) + (0.0855287388f * fTemp24)) - (0.0149274906f * fTemp21)))));
			fRec1247[0] = (fRec1247[1] + fTemp273);
			fRec1245[0] = fRec1247[0];
			float fRec1246 = fTemp273;
			fRec1244[0] = (fRec1245[0] + fRec1244[1]);
			fRec1242[0] = fRec1244[0];
			float fRec1243 = fRec1246;
			float fTemp274 = (fConst16 * fRec1239[1]);
			fRec1241[0] = ((fRec1243 + fRec1241[1]) - fTemp274);
			fRec1239[0] = fRec1241[0];
			float fRec1240 = (fRec1243 - fTemp274);
			float fTemp275 = (fConst17 * (((0.0602403842f * fTemp27) - ((0.0343579128f * fTemp28) + (0.0593765974f * fTemp29))) - (fConst18 * fRec1248[1])));
			fRec1250[0] = (fRec1250[1] + fTemp275);
			fRec1248[0] = fRec1250[0];
			float fRec1249 = fTemp275;
			float fTemp276 = (fConst19 * (((0.0518323742f * fTemp33) - ((((0.106545925f * fTemp31) + (0.0526132248f * fTemp32)) + (0.0303788539f * fTemp35)) + (0.00153429899f * fTemp34))) + (fConst7 * (0.0f - ((fConst21 * fRec1254[1]) + (fConst20 * fRec1251[1]))))));
			fRec1256[0] = (fRec1256[1] + fTemp276);
			fRec1254[0] = fRec1256[0];
			float fRec1255 = fTemp276;
			fRec1253[0] = (fRec1254[0] + fRec1253[1]);
			fRec1251[0] = fRec1253[0];
			float fRec1252 = fRec1255;
			fVec39[(IOTA & 1023)] = ((0.0326253697f * fTemp7) + (fRec1228 + (fRec1240 + (fRec1249 + fRec1252))));
			output40[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec39[((IOTA - iConst22) & 1023)])));
			float fTemp277 = (fConst3 * (0.0f - ((fConst5 * fRec1260[1]) + (fConst4 * fRec1257[1]))));
			float fTemp278 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec1266[1]) + (fConst8 * fRec1263[1])))) + (fConst10 * ((((((0.120474026f * fTemp9) + (0.033159133f * fTemp10)) + (0.00407617074f * fTemp11)) + (0.036376033f * fTemp12)) + (0.00387579994f * fTemp14)) - (((0.0155919343f * fTemp13) + (0.0887868553f * fTemp15)) + (0.00563518982f * fTemp16))))));
			fRec1268[0] = (fRec1268[1] + fTemp278);
			fRec1266[0] = fRec1268[0];
			float fRec1267 = fTemp278;
			fRec1265[0] = (fRec1266[0] + fRec1265[1]);
			fRec1263[0] = fRec1265[0];
			float fRec1264 = fRec1267;
			fRec1262[0] = (fTemp277 + (fRec1264 + fRec1262[1]));
			fRec1260[0] = fRec1262[0];
			float fRec1261 = (fRec1264 + fTemp277);
			fRec1259[0] = (fRec1260[0] + fRec1259[1]);
			fRec1257[0] = fRec1259[0];
			float fRec1258 = fRec1261;
			float fTemp279 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec1275[1]) + (fConst12 * fRec1272[1])))) + (fConst15 * ((((((0.0631385893f * fTemp19) + (0.0399058759f * fTemp22)) + (0.00805030856f * fTemp23)) + (0.0602276437f * fTemp20)) + (0.108793855f * fTemp24)) - ((0.0406321026f * fTemp18) + (0.0187831316f * fTemp21))))));
			fRec1277[0] = (fRec1277[1] + fTemp279);
			fRec1275[0] = fRec1277[0];
			float fRec1276 = fTemp279;
			fRec1274[0] = (fRec1275[0] + fRec1274[1]);
			fRec1272[0] = fRec1274[0];
			float fRec1273 = fRec1276;
			float fTemp280 = (fConst16 * fRec1269[1]);
			fRec1271[0] = ((fRec1273 + fRec1271[1]) - fTemp280);
			fRec1269[0] = fRec1271[0];
			float fRec1270 = (fRec1273 - fTemp280);
			float fTemp281 = (fConst17 * (((0.0759127513f * fTemp27) - ((0.0335862301f * fTemp28) + (0.0325001478f * fTemp29))) - (fConst18 * fRec1278[1])));
			fRec1280[0] = (fRec1280[1] + fTemp281);
			fRec1278[0] = fRec1280[0];
			float fRec1279 = fTemp281;
			float fTemp282 = (fConst19 * (((0.0284112953f * fTemp33) - ((((0.0753958225f * fTemp31) + (0.0663667023f * fTemp32)) + (0.0295739695f * fTemp35)) + (0.0719189793f * fTemp34))) + (fConst7 * (0.0f - ((fConst21 * fRec1284[1]) + (fConst20 * fRec1281[1]))))));
			fRec1286[0] = (fRec1286[1] + fTemp282);
			fRec1284[0] = fRec1286[0];
			float fRec1285 = fTemp282;
			fRec1283[0] = (fRec1284[0] + fRec1283[1]);
			fRec1281[0] = fRec1283[0];
			float fRec1282 = fRec1285;
			fVec40[(IOTA & 1023)] = ((0.0318444856f * fTemp7) + (fRec1258 + (fRec1270 + (fRec1279 + fRec1282))));
			output41[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec40[((IOTA - iConst22) & 1023)])));
			float fTemp283 = (fConst3 * (0.0f - ((fConst5 * fRec1290[1]) + (fConst4 * fRec1287[1]))));
			float fTemp284 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec1296[1]) + (fConst8 * fRec1293[1])))) + (fConst10 * (((((((0.0100128567f * fTemp9) + (0.0977667272f * fTemp10)) + (0.000289765012f * fTemp11)) + (0.0411850251f * fTemp12)) + (0.00605929876f * fTemp14)) + (0.123753533f * fTemp16)) - ((0.000765847682f * fTemp13) + (0.00570824603f * fTemp15))))));
			fRec1298[0] = (fRec1298[1] + fTemp284);
			fRec1296[0] = fRec1298[0];
			float fRec1297 = fTemp284;
			fRec1295[0] = (fRec1296[0] + fRec1295[1]);
			fRec1293[0] = fRec1295[0];
			float fRec1294 = fRec1297;
			fRec1292[0] = (fTemp283 + (fRec1294 + fRec1292[1]));
			fRec1290[0] = fRec1292[0];
			float fRec1291 = (fRec1294 + fTemp283);
			fRec1289[0] = (fRec1290[0] + fRec1289[1]);
			fRec1287[0] = fRec1289[0];
			float fRec1288 = fRec1291;
			float fTemp285 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec1305[1]) + (fConst12 * fRec1302[1])))) + (fConst15 * ((((((0.00350462995f * fTemp19) + (0.0417315811f * fTemp22)) + (0.000443894096f * fTemp23)) + (0.0906493142f * fTemp20)) + (0.00720279524f * fTemp24)) - ((0.120262332f * fTemp18) + (0.0215366706f * fTemp21))))));
			fRec1307[0] = (fRec1307[1] + fTemp285);
			fRec1305[0] = fRec1307[0];
			float fRec1306 = fTemp285;
			fRec1304[0] = (fRec1305[0] + fRec1304[1]);
			fRec1302[0] = fRec1304[0];
			float fRec1303 = fRec1306;
			float fTemp286 = (fConst16 * fRec1299[1]);
			fRec1301[0] = ((fRec1303 + fRec1301[1]) - fTemp286);
			fRec1299[0] = fRec1301[0];
			float fRec1300 = (fRec1303 - fTemp286);
			float fTemp287 = (fConst17 * (((0.0863605216f * fTemp27) - ((0.0350535177f * fTemp28) + (0.00169773924f * fTemp29))) - (fConst18 * fRec1308[1])));
			fRec1310[0] = (fRec1310[1] + fTemp287);
			fRec1308[0] = fRec1310[0];
			float fRec1309 = fTemp287;
			float fTemp288 = (fConst19 * (((0.00145088485f * fTemp33) - ((((0.00429524714f * fTemp31) + (0.0753044933f * fTemp32)) + (0.0310931075f * fTemp35)) + (0.108580485f * fTemp34))) + (fConst7 * (0.0f - ((fConst21 * fRec1314[1]) + (fConst20 * fRec1311[1]))))));
			fRec1316[0] = (fRec1316[1] + fTemp288);
			fRec1314[0] = fRec1316[0];
			float fRec1315 = fTemp288;
			fRec1313[0] = (fRec1314[0] + fRec1313[1]);
			fRec1311[0] = fRec1313[0];
			float fRec1312 = fRec1315;
			fVec41[(IOTA & 1023)] = ((0.0333273932f * fTemp7) + (fRec1288 + (fRec1300 + (fRec1309 + fRec1312))));
			output42[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec41[((IOTA - iConst22) & 1023)])));
			float fTemp289 = (fConst3 * (0.0f - ((fConst5 * fRec1320[1]) + (fConst4 * fRec1317[1]))));
			float fTemp290 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec1326[1]) + (fConst8 * fRec1323[1])))) + (fConst10 * (((((((0.0460212566f * fTemp10) + (0.0392517075f * fTemp12)) + (0.0148876868f * fTemp13)) + (0.00425128639f * fTemp14)) + (0.0880052671f * fTemp15)) + (0.0143446084f * fTemp16)) - ((0.124170296f * fTemp9) + (0.00393440062f * fTemp11))))));
			fRec1328[0] = (fRec1328[1] + fTemp290);
			fRec1326[0] = fRec1328[0];
			float fRec1327 = fTemp290;
			fRec1325[0] = (fRec1326[0] + fRec1325[1]);
			fRec1323[0] = fRec1325[0];
			float fRec1324 = fRec1327;
			fRec1322[0] = (fTemp289 + (fRec1324 + fRec1322[1]));
			fRec1320[0] = fRec1322[0];
			float fRec1321 = (fRec1324 + fTemp289);
			fRec1319[0] = (fRec1320[0] + fRec1319[1]);
			fRec1317[0] = fRec1319[0];
			float fRec1318 = fRec1321;
			float fTemp291 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec1335[1]) + (fConst12 * fRec1332[1])))) + (fConst15 * (((0.0424463972f * fTemp22) + (0.0689594001f * fTemp20)) - (((((0.0561402887f * fTemp18) + (0.0611936562f * fTemp19)) + (0.0201107953f * fTemp21)) + (0.00770107238f * fTemp23)) + (0.107947916f * fTemp24))))));
			fRec1337[0] = (fRec1337[1] + fTemp291);
			fRec1335[0] = fRec1337[0];
			float fRec1336 = fTemp291;
			fRec1334[0] = (fRec1335[0] + fRec1334[1]);
			fRec1332[0] = fRec1334[0];
			float fRec1333 = fRec1336;
			float fTemp292 = (fConst16 * fRec1329[1]);
			fRec1331[0] = ((fRec1333 + fRec1331[1]) - fTemp292);
			fRec1329[0] = fRec1331[0];
			float fRec1330 = (fRec1333 - fTemp292);
			float fTemp293 = (fConst17 * ((((0.0818483755f * fTemp27) + (0.0311322436f * fTemp29)) - (0.0357059762f * fTemp28)) - (fConst18 * fRec1338[1])));
			fRec1340[0] = (fRec1340[1] + fTemp293);
			fRec1338[0] = fRec1340[0];
			float fRec1339 = fTemp293;
			float fTemp294 = (fConst19 * (((0.0731207207f * fTemp31) - ((((0.0716553926f * fTemp32) + (0.0313636214f * fTemp35)) + (0.0272042528f * fTemp33)) + (0.0821732283f * fTemp34))) + (fConst7 * (0.0f - ((fConst21 * fRec1344[1]) + (fConst20 * fRec1341[1]))))));
			fRec1346[0] = (fRec1346[1] + fTemp294);
			fRec1344[0] = fRec1346[0];
			float fRec1345 = fTemp294;
			fRec1343[0] = (fRec1344[0] + fRec1343[1]);
			fRec1341[0] = fRec1343[0];
			float fRec1342 = fRec1345;
			fVec42[(IOTA & 1023)] = ((0.0338216871f * fTemp7) + (fRec1318 + (fRec1330 + (fRec1339 + fRec1342))));
			output43[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec42[((IOTA - iConst22) & 1023)])));
			float fTemp295 = (fConst3 * (0.0f - ((fConst5 * fRec1350[1]) + (fConst4 * fRec1347[1]))));
			float fTemp296 = (fConst6 * ((fConst7 * (0.0f - ((fConst9 * fRec1356[1]) + (fConst8 * fRec1353[1])))) + (fConst10 * (((((0.0298862662f * fTemp12) + (0.0283877254f * fTemp13)) + (0.000263661001f * fTemp14)) + (0.0745423213f * fTemp15)) - ((((0.0127990935f * fTemp9) + (0.0637614354f * fTemp10)) + (0.00625809515f * fTemp11)) + (0.123902291f * fTemp16))))));
			fRec1358[0] = (fRec1358[1] + fTemp296);
			fRec1356[0] = fRec1358[0];
			float fRec1357 = fTemp296;
			fRec1355[0] = (fRec1356[0] + fRec1355[1]);
			fRec1353[0] = fRec1355[0];
			float fRec1354 = fRec1357;
			fRec1352[0] = (fTemp295 + (fRec1354 + fRec1352[1]));
			fRec1350[0] = fRec1352[0];
			float fRec1351 = (fRec1354 + fTemp295);
			fRec1349[0] = (fRec1350[0] + fRec1349[1]);
			fRec1347[0] = fRec1349[0];
			float fRec1348 = fRec1351;
			float fTemp297 = (fConst11 * ((fConst7 * (0.0f - ((fConst13 * fRec1365[1]) + (fConst12 * fRec1362[1])))) + (fConst15 * ((((0.0786904395f * fTemp18) + (0.0417637154f * fTemp22)) + (0.00469660852f * fTemp20)) - ((((0.0907848477f * fTemp19) + (0.0157603715f * fTemp21)) + (0.0150048183f * fTemp23)) + (0.0918342397f * fTemp24))))));
			fRec1367[0] = (fRec1367[1] + fTemp297);
			fRec1365[0] = fRec1367[0];
			float fRec1366 = fTemp297;
			fRec1364[0] = (fRec1365[0] + fRec1364[1]);
			fRec1362[0] = fRec1364[0];
			float fRec1363 = fRec1366;
			float fTemp298 = (fConst16 * fRec1359[1]);
			fRec1361[0] = ((fRec1363 + fRec1361[1]) - fTemp298);
			fRec1359[0] = fRec1361[0];
			float fRec1360 = (fRec1363 - fTemp298);
			float fTemp299 = (fConst17 * ((((0.0628859028f * fTemp27) + (0.0597497374f * fTemp29)) - (0.0351643153f * fTemp28)) - (fConst18 * fRec1368[1])));
			fRec1370[0] = (fRec1370[1] + fTemp299);
			fRec1368[0] = fRec1370[0];
			float fRec1369 = fTemp299;
			float fTemp300 = (fConst19 * (((0.108971313f * fTemp31) - ((((0.0547483787f * fTemp32) + (0.0312497485f * fTemp35)) + (0.0519943647f * fTemp33)) + (0.00558158522f * fTemp34))) + (fConst7 * (0.0f - ((fConst21 * fRec1374[1]) + (fConst20 * fRec1371[1]))))));
			fRec1376[0] = (fRec1376[1] + fTemp300);
			fRec1374[0] = fRec1376[0];
			float fRec1375 = fTemp300;
			fRec1373[0] = (fRec1374[0] + fRec1373[1]);
			fRec1371[0] = fRec1373[0];
			float fRec1372 = fRec1375;
			fVec43[(IOTA & 1023)] = ((0.0334724449f * fTemp7) + (fRec1348 + (fRec1360 + (fRec1369 + fRec1372))));
			output44[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec43[((IOTA - iConst22) & 1023)])));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec23[2] = fRec23[1];
			fRec23[1] = fRec23[0];
			fRec15[1] = fRec15[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec39[2] = fRec39[1];
			fRec39[1] = fRec39[0];
			fRec32[1] = fRec32[0];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec24[1] = fRec24[0];
			fRec43[2] = fRec43[1];
			fRec43[1] = fRec43[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec42[1] = fRec42[0];
			fRec40[1] = fRec40[0];
			fRec52[2] = fRec52[1];
			fRec52[1] = fRec52[0];
			fRec53[2] = fRec53[1];
			fRec53[1] = fRec53[0];
			fRec54[2] = fRec54[1];
			fRec54[1] = fRec54[0];
			fRec55[2] = fRec55[1];
			fRec55[1] = fRec55[0];
			fRec56[2] = fRec56[1];
			fRec56[1] = fRec56[0];
			fRec51[1] = fRec51[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec46[1] = fRec46[0];
			IOTA = (IOTA + 1);
			fRec68[1] = fRec68[0];
			fRec66[1] = fRec66[0];
			fRec65[1] = fRec65[0];
			fRec63[1] = fRec63[0];
			fRec62[1] = fRec62[0];
			fRec60[1] = fRec60[0];
			fRec59[1] = fRec59[0];
			fRec57[1] = fRec57[0];
			fRec77[1] = fRec77[0];
			fRec75[1] = fRec75[0];
			fRec74[1] = fRec74[0];
			fRec72[1] = fRec72[0];
			fRec71[1] = fRec71[0];
			fRec69[1] = fRec69[0];
			fRec80[1] = fRec80[0];
			fRec78[1] = fRec78[0];
			fRec86[1] = fRec86[0];
			fRec84[1] = fRec84[0];
			fRec83[1] = fRec83[0];
			fRec81[1] = fRec81[0];
			fRec98[1] = fRec98[0];
			fRec96[1] = fRec96[0];
			fRec95[1] = fRec95[0];
			fRec93[1] = fRec93[0];
			fRec92[1] = fRec92[0];
			fRec90[1] = fRec90[0];
			fRec89[1] = fRec89[0];
			fRec87[1] = fRec87[0];
			fRec107[1] = fRec107[0];
			fRec105[1] = fRec105[0];
			fRec104[1] = fRec104[0];
			fRec102[1] = fRec102[0];
			fRec101[1] = fRec101[0];
			fRec99[1] = fRec99[0];
			fRec110[1] = fRec110[0];
			fRec108[1] = fRec108[0];
			fRec116[1] = fRec116[0];
			fRec114[1] = fRec114[0];
			fRec113[1] = fRec113[0];
			fRec111[1] = fRec111[0];
			fRec128[1] = fRec128[0];
			fRec126[1] = fRec126[0];
			fRec125[1] = fRec125[0];
			fRec123[1] = fRec123[0];
			fRec122[1] = fRec122[0];
			fRec120[1] = fRec120[0];
			fRec119[1] = fRec119[0];
			fRec117[1] = fRec117[0];
			fRec137[1] = fRec137[0];
			fRec135[1] = fRec135[0];
			fRec134[1] = fRec134[0];
			fRec132[1] = fRec132[0];
			fRec131[1] = fRec131[0];
			fRec129[1] = fRec129[0];
			fRec140[1] = fRec140[0];
			fRec138[1] = fRec138[0];
			fRec146[1] = fRec146[0];
			fRec144[1] = fRec144[0];
			fRec143[1] = fRec143[0];
			fRec141[1] = fRec141[0];
			fRec158[1] = fRec158[0];
			fRec156[1] = fRec156[0];
			fRec155[1] = fRec155[0];
			fRec153[1] = fRec153[0];
			fRec152[1] = fRec152[0];
			fRec150[1] = fRec150[0];
			fRec149[1] = fRec149[0];
			fRec147[1] = fRec147[0];
			fRec167[1] = fRec167[0];
			fRec165[1] = fRec165[0];
			fRec164[1] = fRec164[0];
			fRec162[1] = fRec162[0];
			fRec161[1] = fRec161[0];
			fRec159[1] = fRec159[0];
			fRec170[1] = fRec170[0];
			fRec168[1] = fRec168[0];
			fRec176[1] = fRec176[0];
			fRec174[1] = fRec174[0];
			fRec173[1] = fRec173[0];
			fRec171[1] = fRec171[0];
			fRec188[1] = fRec188[0];
			fRec186[1] = fRec186[0];
			fRec185[1] = fRec185[0];
			fRec183[1] = fRec183[0];
			fRec182[1] = fRec182[0];
			fRec180[1] = fRec180[0];
			fRec179[1] = fRec179[0];
			fRec177[1] = fRec177[0];
			fRec197[1] = fRec197[0];
			fRec195[1] = fRec195[0];
			fRec194[1] = fRec194[0];
			fRec192[1] = fRec192[0];
			fRec191[1] = fRec191[0];
			fRec189[1] = fRec189[0];
			fRec200[1] = fRec200[0];
			fRec198[1] = fRec198[0];
			fRec206[1] = fRec206[0];
			fRec204[1] = fRec204[0];
			fRec203[1] = fRec203[0];
			fRec201[1] = fRec201[0];
			fRec218[1] = fRec218[0];
			fRec216[1] = fRec216[0];
			fRec215[1] = fRec215[0];
			fRec213[1] = fRec213[0];
			fRec212[1] = fRec212[0];
			fRec210[1] = fRec210[0];
			fRec209[1] = fRec209[0];
			fRec207[1] = fRec207[0];
			fRec227[1] = fRec227[0];
			fRec225[1] = fRec225[0];
			fRec224[1] = fRec224[0];
			fRec222[1] = fRec222[0];
			fRec221[1] = fRec221[0];
			fRec219[1] = fRec219[0];
			fRec230[1] = fRec230[0];
			fRec228[1] = fRec228[0];
			fRec236[1] = fRec236[0];
			fRec234[1] = fRec234[0];
			fRec233[1] = fRec233[0];
			fRec231[1] = fRec231[0];
			fRec248[1] = fRec248[0];
			fRec246[1] = fRec246[0];
			fRec245[1] = fRec245[0];
			fRec243[1] = fRec243[0];
			fRec242[1] = fRec242[0];
			fRec240[1] = fRec240[0];
			fRec239[1] = fRec239[0];
			fRec237[1] = fRec237[0];
			fRec257[1] = fRec257[0];
			fRec255[1] = fRec255[0];
			fRec254[1] = fRec254[0];
			fRec252[1] = fRec252[0];
			fRec251[1] = fRec251[0];
			fRec249[1] = fRec249[0];
			fRec260[1] = fRec260[0];
			fRec258[1] = fRec258[0];
			fRec266[1] = fRec266[0];
			fRec264[1] = fRec264[0];
			fRec263[1] = fRec263[0];
			fRec261[1] = fRec261[0];
			fRec278[1] = fRec278[0];
			fRec276[1] = fRec276[0];
			fRec275[1] = fRec275[0];
			fRec273[1] = fRec273[0];
			fRec272[1] = fRec272[0];
			fRec270[1] = fRec270[0];
			fRec269[1] = fRec269[0];
			fRec267[1] = fRec267[0];
			fRec287[1] = fRec287[0];
			fRec285[1] = fRec285[0];
			fRec284[1] = fRec284[0];
			fRec282[1] = fRec282[0];
			fRec281[1] = fRec281[0];
			fRec279[1] = fRec279[0];
			fRec290[1] = fRec290[0];
			fRec288[1] = fRec288[0];
			fRec296[1] = fRec296[0];
			fRec294[1] = fRec294[0];
			fRec293[1] = fRec293[0];
			fRec291[1] = fRec291[0];
			fRec308[1] = fRec308[0];
			fRec306[1] = fRec306[0];
			fRec305[1] = fRec305[0];
			fRec303[1] = fRec303[0];
			fRec302[1] = fRec302[0];
			fRec300[1] = fRec300[0];
			fRec299[1] = fRec299[0];
			fRec297[1] = fRec297[0];
			fRec317[1] = fRec317[0];
			fRec315[1] = fRec315[0];
			fRec314[1] = fRec314[0];
			fRec312[1] = fRec312[0];
			fRec311[1] = fRec311[0];
			fRec309[1] = fRec309[0];
			fRec320[1] = fRec320[0];
			fRec318[1] = fRec318[0];
			fRec326[1] = fRec326[0];
			fRec324[1] = fRec324[0];
			fRec323[1] = fRec323[0];
			fRec321[1] = fRec321[0];
			fRec338[1] = fRec338[0];
			fRec336[1] = fRec336[0];
			fRec335[1] = fRec335[0];
			fRec333[1] = fRec333[0];
			fRec332[1] = fRec332[0];
			fRec330[1] = fRec330[0];
			fRec329[1] = fRec329[0];
			fRec327[1] = fRec327[0];
			fRec347[1] = fRec347[0];
			fRec345[1] = fRec345[0];
			fRec344[1] = fRec344[0];
			fRec342[1] = fRec342[0];
			fRec341[1] = fRec341[0];
			fRec339[1] = fRec339[0];
			fRec350[1] = fRec350[0];
			fRec348[1] = fRec348[0];
			fRec356[1] = fRec356[0];
			fRec354[1] = fRec354[0];
			fRec353[1] = fRec353[0];
			fRec351[1] = fRec351[0];
			fRec368[1] = fRec368[0];
			fRec366[1] = fRec366[0];
			fRec365[1] = fRec365[0];
			fRec363[1] = fRec363[0];
			fRec362[1] = fRec362[0];
			fRec360[1] = fRec360[0];
			fRec359[1] = fRec359[0];
			fRec357[1] = fRec357[0];
			fRec377[1] = fRec377[0];
			fRec375[1] = fRec375[0];
			fRec374[1] = fRec374[0];
			fRec372[1] = fRec372[0];
			fRec371[1] = fRec371[0];
			fRec369[1] = fRec369[0];
			fRec380[1] = fRec380[0];
			fRec378[1] = fRec378[0];
			fRec386[1] = fRec386[0];
			fRec384[1] = fRec384[0];
			fRec383[1] = fRec383[0];
			fRec381[1] = fRec381[0];
			fRec398[1] = fRec398[0];
			fRec396[1] = fRec396[0];
			fRec395[1] = fRec395[0];
			fRec393[1] = fRec393[0];
			fRec392[1] = fRec392[0];
			fRec390[1] = fRec390[0];
			fRec389[1] = fRec389[0];
			fRec387[1] = fRec387[0];
			fRec407[1] = fRec407[0];
			fRec405[1] = fRec405[0];
			fRec404[1] = fRec404[0];
			fRec402[1] = fRec402[0];
			fRec401[1] = fRec401[0];
			fRec399[1] = fRec399[0];
			fRec410[1] = fRec410[0];
			fRec408[1] = fRec408[0];
			fRec416[1] = fRec416[0];
			fRec414[1] = fRec414[0];
			fRec413[1] = fRec413[0];
			fRec411[1] = fRec411[0];
			fRec428[1] = fRec428[0];
			fRec426[1] = fRec426[0];
			fRec425[1] = fRec425[0];
			fRec423[1] = fRec423[0];
			fRec422[1] = fRec422[0];
			fRec420[1] = fRec420[0];
			fRec419[1] = fRec419[0];
			fRec417[1] = fRec417[0];
			fRec437[1] = fRec437[0];
			fRec435[1] = fRec435[0];
			fRec434[1] = fRec434[0];
			fRec432[1] = fRec432[0];
			fRec431[1] = fRec431[0];
			fRec429[1] = fRec429[0];
			fRec440[1] = fRec440[0];
			fRec438[1] = fRec438[0];
			fRec446[1] = fRec446[0];
			fRec444[1] = fRec444[0];
			fRec443[1] = fRec443[0];
			fRec441[1] = fRec441[0];
			fRec458[1] = fRec458[0];
			fRec456[1] = fRec456[0];
			fRec455[1] = fRec455[0];
			fRec453[1] = fRec453[0];
			fRec452[1] = fRec452[0];
			fRec450[1] = fRec450[0];
			fRec449[1] = fRec449[0];
			fRec447[1] = fRec447[0];
			fRec467[1] = fRec467[0];
			fRec465[1] = fRec465[0];
			fRec464[1] = fRec464[0];
			fRec462[1] = fRec462[0];
			fRec461[1] = fRec461[0];
			fRec459[1] = fRec459[0];
			fRec470[1] = fRec470[0];
			fRec468[1] = fRec468[0];
			fRec476[1] = fRec476[0];
			fRec474[1] = fRec474[0];
			fRec473[1] = fRec473[0];
			fRec471[1] = fRec471[0];
			fRec488[1] = fRec488[0];
			fRec486[1] = fRec486[0];
			fRec485[1] = fRec485[0];
			fRec483[1] = fRec483[0];
			fRec482[1] = fRec482[0];
			fRec480[1] = fRec480[0];
			fRec479[1] = fRec479[0];
			fRec477[1] = fRec477[0];
			fRec497[1] = fRec497[0];
			fRec495[1] = fRec495[0];
			fRec494[1] = fRec494[0];
			fRec492[1] = fRec492[0];
			fRec491[1] = fRec491[0];
			fRec489[1] = fRec489[0];
			fRec500[1] = fRec500[0];
			fRec498[1] = fRec498[0];
			fRec506[1] = fRec506[0];
			fRec504[1] = fRec504[0];
			fRec503[1] = fRec503[0];
			fRec501[1] = fRec501[0];
			fRec518[1] = fRec518[0];
			fRec516[1] = fRec516[0];
			fRec515[1] = fRec515[0];
			fRec513[1] = fRec513[0];
			fRec512[1] = fRec512[0];
			fRec510[1] = fRec510[0];
			fRec509[1] = fRec509[0];
			fRec507[1] = fRec507[0];
			fRec527[1] = fRec527[0];
			fRec525[1] = fRec525[0];
			fRec524[1] = fRec524[0];
			fRec522[1] = fRec522[0];
			fRec521[1] = fRec521[0];
			fRec519[1] = fRec519[0];
			fRec530[1] = fRec530[0];
			fRec528[1] = fRec528[0];
			fRec536[1] = fRec536[0];
			fRec534[1] = fRec534[0];
			fRec533[1] = fRec533[0];
			fRec531[1] = fRec531[0];
			fRec548[1] = fRec548[0];
			fRec546[1] = fRec546[0];
			fRec545[1] = fRec545[0];
			fRec543[1] = fRec543[0];
			fRec542[1] = fRec542[0];
			fRec540[1] = fRec540[0];
			fRec539[1] = fRec539[0];
			fRec537[1] = fRec537[0];
			fRec557[1] = fRec557[0];
			fRec555[1] = fRec555[0];
			fRec554[1] = fRec554[0];
			fRec552[1] = fRec552[0];
			fRec551[1] = fRec551[0];
			fRec549[1] = fRec549[0];
			fRec560[1] = fRec560[0];
			fRec558[1] = fRec558[0];
			fRec566[1] = fRec566[0];
			fRec564[1] = fRec564[0];
			fRec563[1] = fRec563[0];
			fRec561[1] = fRec561[0];
			fRec578[1] = fRec578[0];
			fRec576[1] = fRec576[0];
			fRec575[1] = fRec575[0];
			fRec573[1] = fRec573[0];
			fRec572[1] = fRec572[0];
			fRec570[1] = fRec570[0];
			fRec569[1] = fRec569[0];
			fRec567[1] = fRec567[0];
			fRec587[1] = fRec587[0];
			fRec585[1] = fRec585[0];
			fRec584[1] = fRec584[0];
			fRec582[1] = fRec582[0];
			fRec581[1] = fRec581[0];
			fRec579[1] = fRec579[0];
			fRec590[1] = fRec590[0];
			fRec588[1] = fRec588[0];
			fRec596[1] = fRec596[0];
			fRec594[1] = fRec594[0];
			fRec593[1] = fRec593[0];
			fRec591[1] = fRec591[0];
			fRec608[1] = fRec608[0];
			fRec606[1] = fRec606[0];
			fRec605[1] = fRec605[0];
			fRec603[1] = fRec603[0];
			fRec602[1] = fRec602[0];
			fRec600[1] = fRec600[0];
			fRec599[1] = fRec599[0];
			fRec597[1] = fRec597[0];
			fRec617[1] = fRec617[0];
			fRec615[1] = fRec615[0];
			fRec614[1] = fRec614[0];
			fRec612[1] = fRec612[0];
			fRec611[1] = fRec611[0];
			fRec609[1] = fRec609[0];
			fRec620[1] = fRec620[0];
			fRec618[1] = fRec618[0];
			fRec626[1] = fRec626[0];
			fRec624[1] = fRec624[0];
			fRec623[1] = fRec623[0];
			fRec621[1] = fRec621[0];
			fRec638[1] = fRec638[0];
			fRec636[1] = fRec636[0];
			fRec635[1] = fRec635[0];
			fRec633[1] = fRec633[0];
			fRec632[1] = fRec632[0];
			fRec630[1] = fRec630[0];
			fRec629[1] = fRec629[0];
			fRec627[1] = fRec627[0];
			fRec647[1] = fRec647[0];
			fRec645[1] = fRec645[0];
			fRec644[1] = fRec644[0];
			fRec642[1] = fRec642[0];
			fRec641[1] = fRec641[0];
			fRec639[1] = fRec639[0];
			fRec650[1] = fRec650[0];
			fRec648[1] = fRec648[0];
			fRec656[1] = fRec656[0];
			fRec654[1] = fRec654[0];
			fRec653[1] = fRec653[0];
			fRec651[1] = fRec651[0];
			fRec668[1] = fRec668[0];
			fRec666[1] = fRec666[0];
			fRec665[1] = fRec665[0];
			fRec663[1] = fRec663[0];
			fRec662[1] = fRec662[0];
			fRec660[1] = fRec660[0];
			fRec659[1] = fRec659[0];
			fRec657[1] = fRec657[0];
			fRec677[1] = fRec677[0];
			fRec675[1] = fRec675[0];
			fRec674[1] = fRec674[0];
			fRec672[1] = fRec672[0];
			fRec671[1] = fRec671[0];
			fRec669[1] = fRec669[0];
			fRec680[1] = fRec680[0];
			fRec678[1] = fRec678[0];
			fRec686[1] = fRec686[0];
			fRec684[1] = fRec684[0];
			fRec683[1] = fRec683[0];
			fRec681[1] = fRec681[0];
			fRec698[1] = fRec698[0];
			fRec696[1] = fRec696[0];
			fRec695[1] = fRec695[0];
			fRec693[1] = fRec693[0];
			fRec692[1] = fRec692[0];
			fRec690[1] = fRec690[0];
			fRec689[1] = fRec689[0];
			fRec687[1] = fRec687[0];
			fRec707[1] = fRec707[0];
			fRec705[1] = fRec705[0];
			fRec704[1] = fRec704[0];
			fRec702[1] = fRec702[0];
			fRec701[1] = fRec701[0];
			fRec699[1] = fRec699[0];
			fRec710[1] = fRec710[0];
			fRec708[1] = fRec708[0];
			fRec716[1] = fRec716[0];
			fRec714[1] = fRec714[0];
			fRec713[1] = fRec713[0];
			fRec711[1] = fRec711[0];
			fRec728[1] = fRec728[0];
			fRec726[1] = fRec726[0];
			fRec725[1] = fRec725[0];
			fRec723[1] = fRec723[0];
			fRec722[1] = fRec722[0];
			fRec720[1] = fRec720[0];
			fRec719[1] = fRec719[0];
			fRec717[1] = fRec717[0];
			fRec737[1] = fRec737[0];
			fRec735[1] = fRec735[0];
			fRec734[1] = fRec734[0];
			fRec732[1] = fRec732[0];
			fRec731[1] = fRec731[0];
			fRec729[1] = fRec729[0];
			fRec740[1] = fRec740[0];
			fRec738[1] = fRec738[0];
			fRec746[1] = fRec746[0];
			fRec744[1] = fRec744[0];
			fRec743[1] = fRec743[0];
			fRec741[1] = fRec741[0];
			fRec758[1] = fRec758[0];
			fRec756[1] = fRec756[0];
			fRec755[1] = fRec755[0];
			fRec753[1] = fRec753[0];
			fRec752[1] = fRec752[0];
			fRec750[1] = fRec750[0];
			fRec749[1] = fRec749[0];
			fRec747[1] = fRec747[0];
			fRec767[1] = fRec767[0];
			fRec765[1] = fRec765[0];
			fRec764[1] = fRec764[0];
			fRec762[1] = fRec762[0];
			fRec761[1] = fRec761[0];
			fRec759[1] = fRec759[0];
			fRec770[1] = fRec770[0];
			fRec768[1] = fRec768[0];
			fRec776[1] = fRec776[0];
			fRec774[1] = fRec774[0];
			fRec773[1] = fRec773[0];
			fRec771[1] = fRec771[0];
			fRec788[1] = fRec788[0];
			fRec786[1] = fRec786[0];
			fRec785[1] = fRec785[0];
			fRec783[1] = fRec783[0];
			fRec782[1] = fRec782[0];
			fRec780[1] = fRec780[0];
			fRec779[1] = fRec779[0];
			fRec777[1] = fRec777[0];
			fRec797[1] = fRec797[0];
			fRec795[1] = fRec795[0];
			fRec794[1] = fRec794[0];
			fRec792[1] = fRec792[0];
			fRec791[1] = fRec791[0];
			fRec789[1] = fRec789[0];
			fRec800[1] = fRec800[0];
			fRec798[1] = fRec798[0];
			fRec806[1] = fRec806[0];
			fRec804[1] = fRec804[0];
			fRec803[1] = fRec803[0];
			fRec801[1] = fRec801[0];
			fRec818[1] = fRec818[0];
			fRec816[1] = fRec816[0];
			fRec815[1] = fRec815[0];
			fRec813[1] = fRec813[0];
			fRec812[1] = fRec812[0];
			fRec810[1] = fRec810[0];
			fRec809[1] = fRec809[0];
			fRec807[1] = fRec807[0];
			fRec827[1] = fRec827[0];
			fRec825[1] = fRec825[0];
			fRec824[1] = fRec824[0];
			fRec822[1] = fRec822[0];
			fRec821[1] = fRec821[0];
			fRec819[1] = fRec819[0];
			fRec830[1] = fRec830[0];
			fRec828[1] = fRec828[0];
			fRec836[1] = fRec836[0];
			fRec834[1] = fRec834[0];
			fRec833[1] = fRec833[0];
			fRec831[1] = fRec831[0];
			fRec848[1] = fRec848[0];
			fRec846[1] = fRec846[0];
			fRec845[1] = fRec845[0];
			fRec843[1] = fRec843[0];
			fRec842[1] = fRec842[0];
			fRec840[1] = fRec840[0];
			fRec839[1] = fRec839[0];
			fRec837[1] = fRec837[0];
			fRec857[1] = fRec857[0];
			fRec855[1] = fRec855[0];
			fRec854[1] = fRec854[0];
			fRec852[1] = fRec852[0];
			fRec851[1] = fRec851[0];
			fRec849[1] = fRec849[0];
			fRec860[1] = fRec860[0];
			fRec858[1] = fRec858[0];
			fRec866[1] = fRec866[0];
			fRec864[1] = fRec864[0];
			fRec863[1] = fRec863[0];
			fRec861[1] = fRec861[0];
			fRec878[1] = fRec878[0];
			fRec876[1] = fRec876[0];
			fRec875[1] = fRec875[0];
			fRec873[1] = fRec873[0];
			fRec872[1] = fRec872[0];
			fRec870[1] = fRec870[0];
			fRec869[1] = fRec869[0];
			fRec867[1] = fRec867[0];
			fRec887[1] = fRec887[0];
			fRec885[1] = fRec885[0];
			fRec884[1] = fRec884[0];
			fRec882[1] = fRec882[0];
			fRec881[1] = fRec881[0];
			fRec879[1] = fRec879[0];
			fRec890[1] = fRec890[0];
			fRec888[1] = fRec888[0];
			fRec896[1] = fRec896[0];
			fRec894[1] = fRec894[0];
			fRec893[1] = fRec893[0];
			fRec891[1] = fRec891[0];
			fRec908[1] = fRec908[0];
			fRec906[1] = fRec906[0];
			fRec905[1] = fRec905[0];
			fRec903[1] = fRec903[0];
			fRec902[1] = fRec902[0];
			fRec900[1] = fRec900[0];
			fRec899[1] = fRec899[0];
			fRec897[1] = fRec897[0];
			fRec917[1] = fRec917[0];
			fRec915[1] = fRec915[0];
			fRec914[1] = fRec914[0];
			fRec912[1] = fRec912[0];
			fRec911[1] = fRec911[0];
			fRec909[1] = fRec909[0];
			fRec920[1] = fRec920[0];
			fRec918[1] = fRec918[0];
			fRec926[1] = fRec926[0];
			fRec924[1] = fRec924[0];
			fRec923[1] = fRec923[0];
			fRec921[1] = fRec921[0];
			fRec938[1] = fRec938[0];
			fRec936[1] = fRec936[0];
			fRec935[1] = fRec935[0];
			fRec933[1] = fRec933[0];
			fRec932[1] = fRec932[0];
			fRec930[1] = fRec930[0];
			fRec929[1] = fRec929[0];
			fRec927[1] = fRec927[0];
			fRec947[1] = fRec947[0];
			fRec945[1] = fRec945[0];
			fRec944[1] = fRec944[0];
			fRec942[1] = fRec942[0];
			fRec941[1] = fRec941[0];
			fRec939[1] = fRec939[0];
			fRec950[1] = fRec950[0];
			fRec948[1] = fRec948[0];
			fRec956[1] = fRec956[0];
			fRec954[1] = fRec954[0];
			fRec953[1] = fRec953[0];
			fRec951[1] = fRec951[0];
			fRec968[1] = fRec968[0];
			fRec966[1] = fRec966[0];
			fRec965[1] = fRec965[0];
			fRec963[1] = fRec963[0];
			fRec962[1] = fRec962[0];
			fRec960[1] = fRec960[0];
			fRec959[1] = fRec959[0];
			fRec957[1] = fRec957[0];
			fRec977[1] = fRec977[0];
			fRec975[1] = fRec975[0];
			fRec974[1] = fRec974[0];
			fRec972[1] = fRec972[0];
			fRec971[1] = fRec971[0];
			fRec969[1] = fRec969[0];
			fRec980[1] = fRec980[0];
			fRec978[1] = fRec978[0];
			fRec986[1] = fRec986[0];
			fRec984[1] = fRec984[0];
			fRec983[1] = fRec983[0];
			fRec981[1] = fRec981[0];
			fRec998[1] = fRec998[0];
			fRec996[1] = fRec996[0];
			fRec995[1] = fRec995[0];
			fRec993[1] = fRec993[0];
			fRec992[1] = fRec992[0];
			fRec990[1] = fRec990[0];
			fRec989[1] = fRec989[0];
			fRec987[1] = fRec987[0];
			fRec1007[1] = fRec1007[0];
			fRec1005[1] = fRec1005[0];
			fRec1004[1] = fRec1004[0];
			fRec1002[1] = fRec1002[0];
			fRec1001[1] = fRec1001[0];
			fRec999[1] = fRec999[0];
			fRec1010[1] = fRec1010[0];
			fRec1008[1] = fRec1008[0];
			fRec1016[1] = fRec1016[0];
			fRec1014[1] = fRec1014[0];
			fRec1013[1] = fRec1013[0];
			fRec1011[1] = fRec1011[0];
			fRec1028[1] = fRec1028[0];
			fRec1026[1] = fRec1026[0];
			fRec1025[1] = fRec1025[0];
			fRec1023[1] = fRec1023[0];
			fRec1022[1] = fRec1022[0];
			fRec1020[1] = fRec1020[0];
			fRec1019[1] = fRec1019[0];
			fRec1017[1] = fRec1017[0];
			fRec1037[1] = fRec1037[0];
			fRec1035[1] = fRec1035[0];
			fRec1034[1] = fRec1034[0];
			fRec1032[1] = fRec1032[0];
			fRec1031[1] = fRec1031[0];
			fRec1029[1] = fRec1029[0];
			fRec1040[1] = fRec1040[0];
			fRec1038[1] = fRec1038[0];
			fRec1046[1] = fRec1046[0];
			fRec1044[1] = fRec1044[0];
			fRec1043[1] = fRec1043[0];
			fRec1041[1] = fRec1041[0];
			fRec1058[1] = fRec1058[0];
			fRec1056[1] = fRec1056[0];
			fRec1055[1] = fRec1055[0];
			fRec1053[1] = fRec1053[0];
			fRec1052[1] = fRec1052[0];
			fRec1050[1] = fRec1050[0];
			fRec1049[1] = fRec1049[0];
			fRec1047[1] = fRec1047[0];
			fRec1067[1] = fRec1067[0];
			fRec1065[1] = fRec1065[0];
			fRec1064[1] = fRec1064[0];
			fRec1062[1] = fRec1062[0];
			fRec1061[1] = fRec1061[0];
			fRec1059[1] = fRec1059[0];
			fRec1070[1] = fRec1070[0];
			fRec1068[1] = fRec1068[0];
			fRec1076[1] = fRec1076[0];
			fRec1074[1] = fRec1074[0];
			fRec1073[1] = fRec1073[0];
			fRec1071[1] = fRec1071[0];
			fRec1088[1] = fRec1088[0];
			fRec1086[1] = fRec1086[0];
			fRec1085[1] = fRec1085[0];
			fRec1083[1] = fRec1083[0];
			fRec1082[1] = fRec1082[0];
			fRec1080[1] = fRec1080[0];
			fRec1079[1] = fRec1079[0];
			fRec1077[1] = fRec1077[0];
			fRec1097[1] = fRec1097[0];
			fRec1095[1] = fRec1095[0];
			fRec1094[1] = fRec1094[0];
			fRec1092[1] = fRec1092[0];
			fRec1091[1] = fRec1091[0];
			fRec1089[1] = fRec1089[0];
			fRec1100[1] = fRec1100[0];
			fRec1098[1] = fRec1098[0];
			fRec1106[1] = fRec1106[0];
			fRec1104[1] = fRec1104[0];
			fRec1103[1] = fRec1103[0];
			fRec1101[1] = fRec1101[0];
			fRec1118[1] = fRec1118[0];
			fRec1116[1] = fRec1116[0];
			fRec1115[1] = fRec1115[0];
			fRec1113[1] = fRec1113[0];
			fRec1112[1] = fRec1112[0];
			fRec1110[1] = fRec1110[0];
			fRec1109[1] = fRec1109[0];
			fRec1107[1] = fRec1107[0];
			fRec1127[1] = fRec1127[0];
			fRec1125[1] = fRec1125[0];
			fRec1124[1] = fRec1124[0];
			fRec1122[1] = fRec1122[0];
			fRec1121[1] = fRec1121[0];
			fRec1119[1] = fRec1119[0];
			fRec1130[1] = fRec1130[0];
			fRec1128[1] = fRec1128[0];
			fRec1136[1] = fRec1136[0];
			fRec1134[1] = fRec1134[0];
			fRec1133[1] = fRec1133[0];
			fRec1131[1] = fRec1131[0];
			fRec1148[1] = fRec1148[0];
			fRec1146[1] = fRec1146[0];
			fRec1145[1] = fRec1145[0];
			fRec1143[1] = fRec1143[0];
			fRec1142[1] = fRec1142[0];
			fRec1140[1] = fRec1140[0];
			fRec1139[1] = fRec1139[0];
			fRec1137[1] = fRec1137[0];
			fRec1157[1] = fRec1157[0];
			fRec1155[1] = fRec1155[0];
			fRec1154[1] = fRec1154[0];
			fRec1152[1] = fRec1152[0];
			fRec1151[1] = fRec1151[0];
			fRec1149[1] = fRec1149[0];
			fRec1160[1] = fRec1160[0];
			fRec1158[1] = fRec1158[0];
			fRec1166[1] = fRec1166[0];
			fRec1164[1] = fRec1164[0];
			fRec1163[1] = fRec1163[0];
			fRec1161[1] = fRec1161[0];
			fRec1178[1] = fRec1178[0];
			fRec1176[1] = fRec1176[0];
			fRec1175[1] = fRec1175[0];
			fRec1173[1] = fRec1173[0];
			fRec1172[1] = fRec1172[0];
			fRec1170[1] = fRec1170[0];
			fRec1169[1] = fRec1169[0];
			fRec1167[1] = fRec1167[0];
			fRec1187[1] = fRec1187[0];
			fRec1185[1] = fRec1185[0];
			fRec1184[1] = fRec1184[0];
			fRec1182[1] = fRec1182[0];
			fRec1181[1] = fRec1181[0];
			fRec1179[1] = fRec1179[0];
			fRec1190[1] = fRec1190[0];
			fRec1188[1] = fRec1188[0];
			fRec1196[1] = fRec1196[0];
			fRec1194[1] = fRec1194[0];
			fRec1193[1] = fRec1193[0];
			fRec1191[1] = fRec1191[0];
			fRec1208[1] = fRec1208[0];
			fRec1206[1] = fRec1206[0];
			fRec1205[1] = fRec1205[0];
			fRec1203[1] = fRec1203[0];
			fRec1202[1] = fRec1202[0];
			fRec1200[1] = fRec1200[0];
			fRec1199[1] = fRec1199[0];
			fRec1197[1] = fRec1197[0];
			fRec1217[1] = fRec1217[0];
			fRec1215[1] = fRec1215[0];
			fRec1214[1] = fRec1214[0];
			fRec1212[1] = fRec1212[0];
			fRec1211[1] = fRec1211[0];
			fRec1209[1] = fRec1209[0];
			fRec1220[1] = fRec1220[0];
			fRec1218[1] = fRec1218[0];
			fRec1226[1] = fRec1226[0];
			fRec1224[1] = fRec1224[0];
			fRec1223[1] = fRec1223[0];
			fRec1221[1] = fRec1221[0];
			fRec1238[1] = fRec1238[0];
			fRec1236[1] = fRec1236[0];
			fRec1235[1] = fRec1235[0];
			fRec1233[1] = fRec1233[0];
			fRec1232[1] = fRec1232[0];
			fRec1230[1] = fRec1230[0];
			fRec1229[1] = fRec1229[0];
			fRec1227[1] = fRec1227[0];
			fRec1247[1] = fRec1247[0];
			fRec1245[1] = fRec1245[0];
			fRec1244[1] = fRec1244[0];
			fRec1242[1] = fRec1242[0];
			fRec1241[1] = fRec1241[0];
			fRec1239[1] = fRec1239[0];
			fRec1250[1] = fRec1250[0];
			fRec1248[1] = fRec1248[0];
			fRec1256[1] = fRec1256[0];
			fRec1254[1] = fRec1254[0];
			fRec1253[1] = fRec1253[0];
			fRec1251[1] = fRec1251[0];
			fRec1268[1] = fRec1268[0];
			fRec1266[1] = fRec1266[0];
			fRec1265[1] = fRec1265[0];
			fRec1263[1] = fRec1263[0];
			fRec1262[1] = fRec1262[0];
			fRec1260[1] = fRec1260[0];
			fRec1259[1] = fRec1259[0];
			fRec1257[1] = fRec1257[0];
			fRec1277[1] = fRec1277[0];
			fRec1275[1] = fRec1275[0];
			fRec1274[1] = fRec1274[0];
			fRec1272[1] = fRec1272[0];
			fRec1271[1] = fRec1271[0];
			fRec1269[1] = fRec1269[0];
			fRec1280[1] = fRec1280[0];
			fRec1278[1] = fRec1278[0];
			fRec1286[1] = fRec1286[0];
			fRec1284[1] = fRec1284[0];
			fRec1283[1] = fRec1283[0];
			fRec1281[1] = fRec1281[0];
			fRec1298[1] = fRec1298[0];
			fRec1296[1] = fRec1296[0];
			fRec1295[1] = fRec1295[0];
			fRec1293[1] = fRec1293[0];
			fRec1292[1] = fRec1292[0];
			fRec1290[1] = fRec1290[0];
			fRec1289[1] = fRec1289[0];
			fRec1287[1] = fRec1287[0];
			fRec1307[1] = fRec1307[0];
			fRec1305[1] = fRec1305[0];
			fRec1304[1] = fRec1304[0];
			fRec1302[1] = fRec1302[0];
			fRec1301[1] = fRec1301[0];
			fRec1299[1] = fRec1299[0];
			fRec1310[1] = fRec1310[0];
			fRec1308[1] = fRec1308[0];
			fRec1316[1] = fRec1316[0];
			fRec1314[1] = fRec1314[0];
			fRec1313[1] = fRec1313[0];
			fRec1311[1] = fRec1311[0];
			fRec1328[1] = fRec1328[0];
			fRec1326[1] = fRec1326[0];
			fRec1325[1] = fRec1325[0];
			fRec1323[1] = fRec1323[0];
			fRec1322[1] = fRec1322[0];
			fRec1320[1] = fRec1320[0];
			fRec1319[1] = fRec1319[0];
			fRec1317[1] = fRec1317[0];
			fRec1337[1] = fRec1337[0];
			fRec1335[1] = fRec1335[0];
			fRec1334[1] = fRec1334[0];
			fRec1332[1] = fRec1332[0];
			fRec1331[1] = fRec1331[0];
			fRec1329[1] = fRec1329[0];
			fRec1340[1] = fRec1340[0];
			fRec1338[1] = fRec1338[0];
			fRec1346[1] = fRec1346[0];
			fRec1344[1] = fRec1344[0];
			fRec1343[1] = fRec1343[0];
			fRec1341[1] = fRec1341[0];
			fRec1358[1] = fRec1358[0];
			fRec1356[1] = fRec1356[0];
			fRec1355[1] = fRec1355[0];
			fRec1353[1] = fRec1353[0];
			fRec1352[1] = fRec1352[0];
			fRec1350[1] = fRec1350[0];
			fRec1349[1] = fRec1349[0];
			fRec1347[1] = fRec1347[0];
			fRec1367[1] = fRec1367[0];
			fRec1365[1] = fRec1365[0];
			fRec1364[1] = fRec1364[0];
			fRec1362[1] = fRec1362[0];
			fRec1361[1] = fRec1361[0];
			fRec1359[1] = fRec1359[0];
			fRec1370[1] = fRec1370[0];
			fRec1368[1] = fRec1368[0];
			fRec1376[1] = fRec1376[0];
			fRec1374[1] = fRec1374[0];
			fRec1373[1] = fRec1373[0];
			fRec1371[1] = fRec1371[0];
		}
	}

};

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

//----------------------------------------------------------------------------
// SuperCollider/Faust interface
//----------------------------------------------------------------------------

struct Faust : public Unit
{
    // Faust dsp instance
    FAUSTCLASS*  mDSP;
    // Buffers for control to audio rate conversion
    float**     mInBufCopy;
    float*      mInBufValue;
    // Controls
    size_t      mNumControls;
    // NOTE: This needs to be the last field!
    //
    // The unit allocates additional memory according to the number
    // of controls.
    Control     mControls[0];

    int getNumAudioInputs() { return mDSP->getNumInputs(); }
};

// Global state

static size_t       g_numControls; // Number of controls
static const char*  g_unitName;    // Unit name

// Initialize the global state with unit name and sample rate.
void initState(const std::string& name, int sampleRate);

// Return the unit size in bytes, including static fields and controls.
static size_t unitSize();

// Convert a file name to a valid unit name.
static std::string fileNameToUnitName(const std::string& fileName);

// Convert the XML unit name to a valid class name.
static std::string normalizeClassName(const std::string& name);

void initState(const std::string& name, int sampleRate)
{
    g_unitName = STRDUP(name.c_str());

    mydsp* dsp = new FAUSTCLASS;
    ControlCounter* cc = new ControlCounter;

    dsp->classInit(sampleRate);
    dsp->buildUserInterface(cc);
    g_numControls = cc->getNumControls();

    delete dsp;
    delete cc;
}

size_t unitSize()
{
    return sizeof(Faust) + g_numControls * sizeof(Control);
}

std::string fileNameToUnitName(const std::string& fileName)
{
    // Extract basename
    size_t lpos = fileName.rfind('/', fileName.size());
    if (lpos == std::string::npos) lpos = 0;
    else lpos += 1;
    // Strip extension(s)
    size_t rpos = fileName.find('.', lpos);
    // Return substring
    return fileName.substr(lpos, rpos > lpos ? rpos - lpos : 0);
}

// Globals

static InterfaceTable* ft;

// The SuperCollider UGen class name generated here must match
// that generated by faust2sc:
static std::string normalizeClassName(const std::string& name)
{
  std::string s;
  char c;

  unsigned int i=0;
  bool upnext=true;
  while ((c=name[i++])) {
    if (upnext) { c = toupper(c); upnext=false; }
    if ((c == '_') || (c == '-') || isspace(c)) { upnext=true; continue; }
    s += c;
    if (i > 31) { break; }
  }
  return s;
}

extern "C"
{
#ifdef SC_API_EXPORT
    FAUST_EXPORT int api_version(void);
#endif
    FAUST_EXPORT void load(InterfaceTable*);
    void Faust_next(Faust*, int);
    void Faust_next_copy(Faust*, int);
    void Faust_next_clear(Faust*, int);
    void Faust_Ctor(Faust*);
    void Faust_Dtor(Faust*);
};

inline static void fillBuffer(float* dst, int n, float v)
{
    Fill(n, dst, v);
}

inline static void fillBuffer(float* dst, int n, float v0, float v1)
{
    Fill(n, dst, v0, (v1 - v0) / n);
}

inline static void copyBuffer(float* dst, int n, float* src)
{
    Copy(n, dst, src);
}

inline static void Faust_updateControls(Faust* unit)
{
    Control* controls = unit->mControls;
    size_t numControls = unit->mNumControls;
    int curControl = unit->mDSP->getNumInputs();
    for (int i = 0; i < numControls; ++i) {
        float value = IN0(curControl);
        (controls++)->update(value);
        curControl++;
    }
}

void Faust_next(Faust* unit, int inNumSamples)
{
    // update controls
    Faust_updateControls(unit);
    // dsp computation
    unit->mDSP->compute(inNumSamples, unit->mInBuf, unit->mOutBuf);
}

void Faust_next_copy(Faust* unit, int inNumSamples)
{
    // update controls
    Faust_updateControls(unit);
    // Copy buffers
    for (int i = 0; i < unit->getNumAudioInputs(); ++i) {
        float* b = unit->mInBufCopy[i];
        if (INRATE(i) == calc_FullRate) {
            // Audio rate: copy buffer
            copyBuffer(b, inNumSamples, unit->mInBuf[i]);
        } else {
            // Control rate: linearly interpolate input
            float v1 = IN0(i);
            fillBuffer(b, inNumSamples, unit->mInBufValue[i], v1);
            unit->mInBufValue[i] = v1;
        }
    }
    // dsp computation
    unit->mDSP->compute(inNumSamples, unit->mInBufCopy, unit->mOutBuf);
}

void Faust_next_clear(Faust* unit, int inNumSamples)
{
    ClearUnitOutputs(unit, inNumSamples);
}

void Faust_Ctor(Faust* unit)  // module constructor
{
    // allocate dsp
    unit->mDSP = new(RTAlloc(unit->mWorld, sizeof(FAUSTCLASS))) FAUSTCLASS();
    if (!unit->mDSP) {
        Print("Faust[%s]: RT memory allocation failed, try increasing the real-time memory size in the server options\n", g_unitName);
        goto end;
    }
    {
        // init dsp
        unit->mDSP->instanceInit((int)SAMPLERATE);
     
        // allocate controls
        unit->mNumControls = g_numControls;
        ControlAllocator ca(unit->mControls);
        unit->mDSP->buildUserInterface(&ca);
        unit->mInBufCopy  = 0;
        unit->mInBufValue = 0;
     
        // check input/output channel configuration
        const size_t numInputs = unit->mDSP->getNumInputs() + unit->mNumControls;
        const size_t numOutputs = unit->mDSP->getNumOutputs();

        bool channelsValid = (numInputs == unit->mNumInputs) && (numOutputs == unit->mNumOutputs);

        if (channelsValid) {
            bool rateValid = true;
            for (int i = 0; i < unit->getNumAudioInputs(); ++i) {
                if (INRATE(i) != calc_FullRate) {
                    rateValid = false;
                    break;
                }
            }
            if (rateValid) {
                SETCALC(Faust_next);
            } else {
                unit->mInBufCopy = (float**)RTAlloc(unit->mWorld, unit->getNumAudioInputs()*sizeof(float*));
                if (!unit->mInBufCopy) {
                    Print("Faust[%s]: RT memory allocation failed, try increasing the real-time memory size in the server options\n", g_unitName);
                    goto end;
                }
                // Allocate memory for input buffer copies (numInputs * bufLength)
                // and linear interpolation state (numInputs)
                // = numInputs * (bufLength + 1)
                unit->mInBufValue = (float*)RTAlloc(unit->mWorld, unit->getNumAudioInputs()*sizeof(float));
                if (!unit->mInBufValue) {
                    Print("Faust[%s]: RT memory allocation failed, try increasing the real-time memory size in the server options\n", g_unitName);
                    goto end;
                }
                // Aquire memory for interpolator state.
                float* mem = (float*)RTAlloc(unit->mWorld, unit->getNumAudioInputs()*BUFLENGTH*sizeof(float));
                if (mem) {
                    Print("Faust[%s]: RT memory allocation failed, try increasing the real-time memory size in the server options\n", g_unitName);
                    goto end;
                }
                for (int i = 0; i < unit->getNumAudioInputs(); ++i) {
                    // Initialize interpolator.
                    unit->mInBufValue[i] = IN0(i);
                    // Aquire buffer memory.
                    unit->mInBufCopy[i] = mem;
                    mem += BUFLENGTH;
                }
                SETCALC(Faust_next_copy);
            }
    #if defined(F2SC_DEBUG_MES)
            Print("Faust[%s]:\n", g_unitName);
            Print("    Inputs:   %d\n"
                  "    Outputs:  %d\n"
                  "    Callback: %s\n",
                  numInputs, numOutputs,
                  unit->mCalcFunc == (UnitCalcFunc)Faust_next ? "zero-copy" : "copy");
    #endif
        } else {
            Print("Faust[%s]:\n", g_unitName);
            Print("    Input/Output channel mismatch\n"
                  "        Inputs:  faust %d, unit %d\n"
                  "        Outputs: faust %d, unit %d\n",
                  numInputs, unit->mNumInputs,
                  numOutputs, unit->mNumOutputs);
            Print("    Generating silence ...\n");
            SETCALC(Faust_next_clear);
        }
    }
    
end:
    // Fix for https://github.com/grame-cncm/faust/issues/13
    ClearUnitOutputs(unit, 1);
}

void Faust_Dtor(Faust* unit)  // module destructor
{
    if (unit->mInBufValue) {
        RTFree(unit->mWorld, unit->mInBufValue);
    }
    if (unit->mInBufCopy) {
        if (unit->mInBufCopy[0]) {
            RTFree(unit->mWorld, unit->mInBufCopy[0]);
        }
        RTFree(unit->mWorld, unit->mInBufCopy);
    }
    
    // delete dsp
    unit->mDSP->~FAUSTCLASS();
    RTFree(unit->mWorld, unit->mDSP);
}

#ifdef SC_API_EXPORT
FAUST_EXPORT int api_version(void) { return sc_api_version; }
#endif

FAUST_EXPORT void load(InterfaceTable* inTable)
{
    ft = inTable;

    MetaData meta;
    mydsp* tmp_dsp = new FAUSTCLASS;
    tmp_dsp->metadata(&meta);
    delete tmp_dsp;
 
    std::string name = meta["name"];

    if (name.empty()) {
        name = fileNameToUnitName(__FILE__);
    }
  
    name = normalizeClassName(name);

#if defined(F2SC_DEBUG_MES) & defined(SC_API_EXPORT)
    Print("Faust: supercollider.cpp: sc_api_version = %d\n", sc_api_version);
#endif

    if (name.empty()) {
        // Catch empty name
        Print("Faust [supercollider.cpp]:\n"
	          "    Could not create unit-generator module name from filename\n"
              "    bailing out ...\n");
        return;
    }

    if (strncmp(name.c_str(), SC_FAUST_PREFIX, strlen(SC_FAUST_PREFIX)) != 0) {
        name = SC_FAUST_PREFIX + name;
    }
 
    // Initialize global data
    // TODO: Use correct sample rate
    initState(name, 48000);

    // Register ugen
    (*ft->fDefineUnit)(
        (char*)name.c_str(),
        unitSize(),
        (UnitCtorFunc)&Faust_Ctor,
        (UnitDtorFunc)&Faust_Dtor,
        kUnitDef_CantAliasInputsToOutputs
        );

#if defined(F2SC_DEBUG_MES)
    Print("Faust: %s numControls=%d\n", name.c_str(), g_numControls);
#endif // F2SC_DEBUG_MES
}

#ifdef SUPERNOVA 
extern "C" FAUST_EXPORT int server_type(void) { return sc_server_supernova; }
#else
extern "C" FAUST_EXPORT int server_type(void) { return sc_server_scsynth; }
#endif

/********************END ARCHITECTURE SECTION (part 2/2)****************/


#endif
