/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMHLS_FullSetup_1H1P_full_5"
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
	float fConst2;
	FAUSTFLOAT fHslider1;
	float fRec4[2];
	float fRec5[3];
	FAUSTFLOAT fHslider2;
	float fRec6[2];
	float fRec7[3];
	float fRec8[3];
	float fConst3;
	float fRec3[2];
	float fRec1[2];
	float fRec9[3];
	int IOTA;
	float fVec0[1024];
	int iConst4;
	float fRec12[2];
	float fRec10[2];
	float fVec1[1024];
	float fRec15[2];
	float fRec13[2];
	float fVec2[1024];
	float fRec18[2];
	float fRec16[2];
	float fVec3[1024];
	float fRec21[2];
	float fRec19[2];
	float fVec4[1024];
	float fRec24[2];
	float fRec22[2];
	float fVec5[1024];
	float fRec27[2];
	float fRec25[2];
	float fVec6[1024];
	float fRec30[2];
	float fRec28[2];
	float fVec7[1024];
	float fRec33[2];
	float fRec31[2];
	float fVec8[1024];
	float fRec36[2];
	float fRec34[2];
	float fVec9[1024];
	float fRec39[2];
	float fRec37[2];
	float fVec10[1024];
	float fRec42[2];
	float fRec40[2];
	float fVec11[1024];
	float fRec45[2];
	float fRec43[2];
	float fVec12[1024];
	float fRec48[2];
	float fRec46[2];
	float fVec13[1024];
	float fRec51[2];
	float fRec49[2];
	float fVec14[1024];
	float fRec54[2];
	float fRec52[2];
	float fVec15[1024];
	float fConst5;
	float fConst6;
	float fRec57[2];
	float fRec55[2];
	float fVec16[512];
	int iConst7;
	float fRec60[2];
	float fRec58[2];
	float fVec17[512];
	float fRec63[2];
	float fRec61[2];
	float fVec18[512];
	float fRec66[2];
	float fRec64[2];
	float fVec19[512];
	float fRec69[2];
	float fRec67[2];
	float fVec20[512];
	float fRec72[2];
	float fRec70[2];
	float fVec21[512];
	float fRec75[2];
	float fRec73[2];
	float fVec22[512];
	float fRec78[2];
	float fRec76[2];
	float fVec23[512];
	float fConst8;
	float fConst9;
	float fRec81[2];
	float fRec79[2];
	float fVec24[256];
	int iConst10;
	float fRec84[2];
	float fRec82[2];
	float fVec25[256];
	float fRec87[2];
	float fRec85[2];
	float fVec26[256];
	float fRec90[2];
	float fRec88[2];
	float fVec27[256];
	float fConst11;
	float fConst12;
	float fRec93[2];
	float fRec91[2];
	float fRec96[2];
	float fRec94[2];
	float fVec28[1024];
	float fRec99[2];
	float fRec97[2];
	float fVec29[1024];
	float fRec102[2];
	float fRec100[2];
	float fVec30[1024];
	float fRec105[2];
	float fRec103[2];
	float fVec31[1024];
	float fRec108[2];
	float fRec106[2];
	float fVec32[1024];
	float fRec111[2];
	float fRec109[2];
	float fVec33[1024];
	float fRec114[2];
	float fRec112[2];
	float fVec34[1024];
	float fRec117[2];
	float fRec115[2];
	float fVec35[1024];
	float fRec120[2];
	float fRec118[2];
	float fVec36[1024];
	float fRec123[2];
	float fRec121[2];
	float fVec37[1024];
	float fRec126[2];
	float fRec124[2];
	float fVec38[1024];
	float fRec129[2];
	float fRec127[2];
	float fVec39[1024];
	float fRec132[2];
	float fRec130[2];
	float fVec40[1024];
	float fRec135[2];
	float fRec133[2];
	float fVec41[1024];
	float fRec138[2];
	float fRec136[2];
	float fVec42[1024];
	float fRec141[2];
	float fRec139[2];
	float fVec43[1024];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMHLS_FullSetup_1H1P_full_5.dsp");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMHLS_FullSetup_1H1P_full_5");
		m->declare("version", "1.2");
	}

	virtual int getNumInputs() {
		return 4;
		
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
		fConst1 = (1.0f / ((37.2250137f / fConst0) + 1.0f));
		fConst2 = (3.14159274f / fConst0);
		fConst3 = (74.4500275f / fConst0);
		iConst4 = int(((0.00281456532f * fConst0) + 0.5f));
		fConst5 = (1.0f / ((35.1510277f / fConst0) + 1.0f));
		fConst6 = (70.3020554f / fConst0);
		iConst7 = int(((0.00202205847f * fConst0) + 0.5f));
		fConst8 = (1.0f / ((32.2752151f / fConst0) + 1.0f));
		fConst9 = (64.5504303f / fConst0);
		iConst10 = int(((0.000754629844f * fConst0) + 0.5f));
		fConst11 = (1.0f / ((30.7760601f / fConst0) + 1.0f));
		fConst12 = (61.5521202f / fConst0);
		
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
			fRec4[l1] = 0.0f;
			
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec5[l2] = 0.0f;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec6[l3] = 0.0f;
			
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec7[l4] = 0.0f;
			
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec8[l5] = 0.0f;
			
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec3[l6] = 0.0f;
			
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec1[l7] = 0.0f;
			
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec9[l8] = 0.0f;
			
		}
		IOTA = 0;
		for (int l9 = 0; (l9 < 1024); l9 = (l9 + 1)) {
			fVec0[l9] = 0.0f;
			
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec12[l10] = 0.0f;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec10[l11] = 0.0f;
			
		}
		for (int l12 = 0; (l12 < 1024); l12 = (l12 + 1)) {
			fVec1[l12] = 0.0f;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec15[l13] = 0.0f;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec13[l14] = 0.0f;
			
		}
		for (int l15 = 0; (l15 < 1024); l15 = (l15 + 1)) {
			fVec2[l15] = 0.0f;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec18[l16] = 0.0f;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec16[l17] = 0.0f;
			
		}
		for (int l18 = 0; (l18 < 1024); l18 = (l18 + 1)) {
			fVec3[l18] = 0.0f;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec21[l19] = 0.0f;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec19[l20] = 0.0f;
			
		}
		for (int l21 = 0; (l21 < 1024); l21 = (l21 + 1)) {
			fVec4[l21] = 0.0f;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec24[l22] = 0.0f;
			
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec22[l23] = 0.0f;
			
		}
		for (int l24 = 0; (l24 < 1024); l24 = (l24 + 1)) {
			fVec5[l24] = 0.0f;
			
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec27[l25] = 0.0f;
			
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec25[l26] = 0.0f;
			
		}
		for (int l27 = 0; (l27 < 1024); l27 = (l27 + 1)) {
			fVec6[l27] = 0.0f;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec30[l28] = 0.0f;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec28[l29] = 0.0f;
			
		}
		for (int l30 = 0; (l30 < 1024); l30 = (l30 + 1)) {
			fVec7[l30] = 0.0f;
			
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec33[l31] = 0.0f;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec31[l32] = 0.0f;
			
		}
		for (int l33 = 0; (l33 < 1024); l33 = (l33 + 1)) {
			fVec8[l33] = 0.0f;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec36[l34] = 0.0f;
			
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec34[l35] = 0.0f;
			
		}
		for (int l36 = 0; (l36 < 1024); l36 = (l36 + 1)) {
			fVec9[l36] = 0.0f;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec39[l37] = 0.0f;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec37[l38] = 0.0f;
			
		}
		for (int l39 = 0; (l39 < 1024); l39 = (l39 + 1)) {
			fVec10[l39] = 0.0f;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec42[l40] = 0.0f;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec40[l41] = 0.0f;
			
		}
		for (int l42 = 0; (l42 < 1024); l42 = (l42 + 1)) {
			fVec11[l42] = 0.0f;
			
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec45[l43] = 0.0f;
			
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec43[l44] = 0.0f;
			
		}
		for (int l45 = 0; (l45 < 1024); l45 = (l45 + 1)) {
			fVec12[l45] = 0.0f;
			
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec48[l46] = 0.0f;
			
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec46[l47] = 0.0f;
			
		}
		for (int l48 = 0; (l48 < 1024); l48 = (l48 + 1)) {
			fVec13[l48] = 0.0f;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec51[l49] = 0.0f;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec49[l50] = 0.0f;
			
		}
		for (int l51 = 0; (l51 < 1024); l51 = (l51 + 1)) {
			fVec14[l51] = 0.0f;
			
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec54[l52] = 0.0f;
			
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fRec52[l53] = 0.0f;
			
		}
		for (int l54 = 0; (l54 < 1024); l54 = (l54 + 1)) {
			fVec15[l54] = 0.0f;
			
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec57[l55] = 0.0f;
			
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fRec55[l56] = 0.0f;
			
		}
		for (int l57 = 0; (l57 < 512); l57 = (l57 + 1)) {
			fVec16[l57] = 0.0f;
			
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec60[l58] = 0.0f;
			
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec58[l59] = 0.0f;
			
		}
		for (int l60 = 0; (l60 < 512); l60 = (l60 + 1)) {
			fVec17[l60] = 0.0f;
			
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec63[l61] = 0.0f;
			
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec61[l62] = 0.0f;
			
		}
		for (int l63 = 0; (l63 < 512); l63 = (l63 + 1)) {
			fVec18[l63] = 0.0f;
			
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec66[l64] = 0.0f;
			
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec64[l65] = 0.0f;
			
		}
		for (int l66 = 0; (l66 < 512); l66 = (l66 + 1)) {
			fVec19[l66] = 0.0f;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec69[l67] = 0.0f;
			
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec67[l68] = 0.0f;
			
		}
		for (int l69 = 0; (l69 < 512); l69 = (l69 + 1)) {
			fVec20[l69] = 0.0f;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec72[l70] = 0.0f;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec70[l71] = 0.0f;
			
		}
		for (int l72 = 0; (l72 < 512); l72 = (l72 + 1)) {
			fVec21[l72] = 0.0f;
			
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec75[l73] = 0.0f;
			
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec73[l74] = 0.0f;
			
		}
		for (int l75 = 0; (l75 < 512); l75 = (l75 + 1)) {
			fVec22[l75] = 0.0f;
			
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec78[l76] = 0.0f;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec76[l77] = 0.0f;
			
		}
		for (int l78 = 0; (l78 < 512); l78 = (l78 + 1)) {
			fVec23[l78] = 0.0f;
			
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fRec81[l79] = 0.0f;
			
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec79[l80] = 0.0f;
			
		}
		for (int l81 = 0; (l81 < 256); l81 = (l81 + 1)) {
			fVec24[l81] = 0.0f;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec84[l82] = 0.0f;
			
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fRec82[l83] = 0.0f;
			
		}
		for (int l84 = 0; (l84 < 256); l84 = (l84 + 1)) {
			fVec25[l84] = 0.0f;
			
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec87[l85] = 0.0f;
			
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec85[l86] = 0.0f;
			
		}
		for (int l87 = 0; (l87 < 256); l87 = (l87 + 1)) {
			fVec26[l87] = 0.0f;
			
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			fRec90[l88] = 0.0f;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec88[l89] = 0.0f;
			
		}
		for (int l90 = 0; (l90 < 256); l90 = (l90 + 1)) {
			fVec27[l90] = 0.0f;
			
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec93[l91] = 0.0f;
			
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec91[l92] = 0.0f;
			
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec96[l93] = 0.0f;
			
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec94[l94] = 0.0f;
			
		}
		for (int l95 = 0; (l95 < 1024); l95 = (l95 + 1)) {
			fVec28[l95] = 0.0f;
			
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fRec99[l96] = 0.0f;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec97[l97] = 0.0f;
			
		}
		for (int l98 = 0; (l98 < 1024); l98 = (l98 + 1)) {
			fVec29[l98] = 0.0f;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec102[l99] = 0.0f;
			
		}
		for (int l100 = 0; (l100 < 2); l100 = (l100 + 1)) {
			fRec100[l100] = 0.0f;
			
		}
		for (int l101 = 0; (l101 < 1024); l101 = (l101 + 1)) {
			fVec30[l101] = 0.0f;
			
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec105[l102] = 0.0f;
			
		}
		for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) {
			fRec103[l103] = 0.0f;
			
		}
		for (int l104 = 0; (l104 < 1024); l104 = (l104 + 1)) {
			fVec31[l104] = 0.0f;
			
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fRec108[l105] = 0.0f;
			
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec106[l106] = 0.0f;
			
		}
		for (int l107 = 0; (l107 < 1024); l107 = (l107 + 1)) {
			fVec32[l107] = 0.0f;
			
		}
		for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) {
			fRec111[l108] = 0.0f;
			
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec109[l109] = 0.0f;
			
		}
		for (int l110 = 0; (l110 < 1024); l110 = (l110 + 1)) {
			fVec33[l110] = 0.0f;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec114[l111] = 0.0f;
			
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec112[l112] = 0.0f;
			
		}
		for (int l113 = 0; (l113 < 1024); l113 = (l113 + 1)) {
			fVec34[l113] = 0.0f;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec117[l114] = 0.0f;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec115[l115] = 0.0f;
			
		}
		for (int l116 = 0; (l116 < 1024); l116 = (l116 + 1)) {
			fVec35[l116] = 0.0f;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec120[l117] = 0.0f;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec118[l118] = 0.0f;
			
		}
		for (int l119 = 0; (l119 < 1024); l119 = (l119 + 1)) {
			fVec36[l119] = 0.0f;
			
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec123[l120] = 0.0f;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec121[l121] = 0.0f;
			
		}
		for (int l122 = 0; (l122 < 1024); l122 = (l122 + 1)) {
			fVec37[l122] = 0.0f;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec126[l123] = 0.0f;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec124[l124] = 0.0f;
			
		}
		for (int l125 = 0; (l125 < 1024); l125 = (l125 + 1)) {
			fVec38[l125] = 0.0f;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec129[l126] = 0.0f;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec127[l127] = 0.0f;
			
		}
		for (int l128 = 0; (l128 < 1024); l128 = (l128 + 1)) {
			fVec39[l128] = 0.0f;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec132[l129] = 0.0f;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec130[l130] = 0.0f;
			
		}
		for (int l131 = 0; (l131 < 1024); l131 = (l131 + 1)) {
			fVec40[l131] = 0.0f;
			
		}
		for (int l132 = 0; (l132 < 2); l132 = (l132 + 1)) {
			fRec135[l132] = 0.0f;
			
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec133[l133] = 0.0f;
			
		}
		for (int l134 = 0; (l134 < 1024); l134 = (l134 + 1)) {
			fVec41[l134] = 0.0f;
			
		}
		for (int l135 = 0; (l135 < 2); l135 = (l135 + 1)) {
			fRec138[l135] = 0.0f;
			
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec136[l136] = 0.0f;
			
		}
		for (int l137 = 0; (l137 < 1024); l137 = (l137 + 1)) {
			fVec42[l137] = 0.0f;
			
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec141[l138] = 0.0f;
			
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fRec139[l139] = 0.0f;
			
		}
		for (int l140 = 0; (l140 < 1024); l140 = (l140 + 1)) {
			fVec43[l140] = 0.0f;
			
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
		ui_interface->openVerticalBox("KMHLS_FullSetup_1H1P_full_5");
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
			fRec4[0] = (fSlow1 + (0.999000013f * fRec4[1]));
			float fTemp0 = std::tan((fConst2 * fRec4[0]));
			float fTemp1 = mydsp_faustpower2_f(fTemp0);
			float fTemp2 = ((fTemp0 * (fTemp0 + -2.0f)) + 1.0f);
			float fTemp3 = (fTemp1 + -1.0f);
			float fTemp4 = ((fTemp0 * (fTemp0 + 2.0f)) + 1.0f);
			fRec5[0] = (float(input1[i]) - (((fTemp2 * fRec5[2]) + (2.0f * (fTemp3 * fRec5[1]))) / fTemp4));
			fRec6[0] = (fSlow2 + (0.999000013f * fRec6[1]));
			float fTemp5 = (fRec6[0] * fTemp4);
			float fTemp6 = (0.0f - (2.0f / fTemp4));
			float fTemp7 = (((fTemp1 * (fRec5[2] + (fRec5[0] + (2.0f * fRec5[1])))) / fTemp5) + (0.577350259f * (fRec6[0] * (0.0f - ((fTemp6 * fRec5[1]) + ((fRec5[0] + fRec5[2]) / fTemp4))))));
			fRec7[0] = (float(input2[i]) - (((fTemp2 * fRec7[2]) + (2.0f * (fTemp3 * fRec7[1]))) / fTemp4));
			float fTemp8 = (((fTemp1 * (fRec7[2] + (fRec7[0] + (2.0f * fRec7[1])))) / fTemp5) + (0.577350259f * (fRec6[0] * (0.0f - ((fTemp6 * fRec7[1]) + ((fRec7[0] + fRec7[2]) / fTemp4))))));
			fRec8[0] = (float(input3[i]) - (((fTemp2 * fRec8[2]) + (2.0f * (fTemp3 * fRec8[1]))) / fTemp4));
			float fTemp9 = (((fTemp1 * (fRec8[2] + (fRec8[0] + (2.0f * fRec8[1])))) / fTemp5) + (0.577350259f * (fRec6[0] * (0.0f - ((fTemp6 * fRec8[1]) + ((fRec8[0] + fRec8[2]) / fTemp4))))));
			float fTemp10 = (fConst1 * ((((0.0298504047f * fTemp7) + (0.0202646218f * fTemp8)) + (0.0434191413f * fTemp9)) - (fConst3 * fRec1[1])));
			fRec3[0] = (fRec3[1] + fTemp10);
			fRec1[0] = fRec3[0];
			float fRec2 = fTemp10;
			fRec9[0] = (float(input0[i]) - (((fRec9[2] * fTemp2) + (2.0f * (fRec9[1] * fTemp3))) / fTemp4));
			float fTemp11 = (((fTemp1 * (fRec9[2] + (fRec9[0] + (2.0f * fRec9[1])))) / fTemp5) + (fRec6[0] * (0.0f - ((fRec9[1] * fTemp6) + ((fRec9[0] + fRec9[2]) / fTemp4)))));
			fVec0[(IOTA & 1023)] = (fRec2 + (0.0136061301f * fTemp11));
			output0[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec0[((IOTA - iConst4) & 1023)])));
			float fTemp12 = (fConst1 * ((((0.0120373871f * fTemp7) + (0.0204132814f * fTemp8)) + (0.0512767471f * fTemp9)) - (fConst3 * fRec10[1])));
			fRec12[0] = (fRec12[1] + fTemp12);
			fRec10[0] = fRec12[0];
			float fRec11 = fTemp12;
			fVec1[(IOTA & 1023)] = (fRec11 + (0.0137059428f * fTemp11));
			output1[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec1[((IOTA - iConst4) & 1023)])));
			float fTemp13 = (fConst1 * ((((0.0205417182f * fTemp8) + (0.0517920777f * fTemp9)) - (0.0097507881f * fTemp7)) - (fConst3 * fRec13[1])));
			fRec15[0] = (fRec15[1] + fTemp13);
			fRec13[0] = fRec15[0];
			float fRec14 = fTemp13;
			fVec2[(IOTA & 1023)] = (fRec14 + (0.0137921786f * fTemp11));
			output2[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec2[((IOTA - iConst4) & 1023)])));
			float fTemp14 = (fConst1 * ((((0.0206061155f * fTemp8) + (0.0446067639f * fTemp9)) - (0.0282667503f * fTemp7)) - (fConst3 * fRec16[1])));
			fRec18[0] = (fRec18[1] + fTemp14);
			fRec16[0] = fRec18[0];
			float fRec17 = fTemp14;
			fVec3[(IOTA & 1023)] = (fRec17 + (0.0138354162f * fTemp11));
			output3[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec3[((IOTA - iConst4) & 1023)])));
			float fTemp15 = (fConst1 * ((((0.0206083488f * fTemp8) + (0.0296961404f * fTemp9)) - (0.0438616574f * fTemp7)) - (fConst3 * fRec19[1])));
			fRec21[0] = (fRec21[1] + fTemp15);
			fRec19[0] = fRec21[0];
			float fRec20 = fTemp15;
			fVec4[(IOTA & 1023)] = (fRec20 + (0.0138369156f * fTemp11));
			output4[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec4[((IOTA - iConst4) & 1023)])));
			float fTemp16 = (fConst1 * ((((0.0205444861f * fTemp8) + (0.0108944429f * fTemp9)) - (0.0519422367f * fTemp7)) - (fConst3 * fRec22[1])));
			fRec24[0] = (fRec24[1] + fTemp16);
			fRec22[0] = fRec24[0];
			float fRec23 = fTemp16;
			fVec5[(IOTA & 1023)] = (fRec23 + (0.0137940366f * fTemp11));
			output5[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec5[((IOTA - iConst4) & 1023)])));
			float fTemp17 = (fConst1 * (((0.0204208773f * fTemp8) - ((0.0520368926f * fTemp7) + (0.0102543849f * fTemp9))) - (fConst3 * fRec25[1])));
			fRec27[0] = (fRec27[1] + fTemp17);
			fRec25[0] = fRec27[0];
			float fRec26 = fTemp17;
			fVec6[(IOTA & 1023)] = (fRec26 + (0.0137110436f * fTemp11));
			output6[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec6[((IOTA - iConst4) & 1023)])));
			float fTemp18 = (fConst1 * (((0.0202582851f * fTemp8) - ((0.0436618477f * fTemp7) + (0.0297394637f * fTemp9))) - (fConst3 * fRec28[1])));
			fRec30[0] = (fRec30[1] + fTemp18);
			fRec28[0] = fRec30[0];
			float fRec29 = fTemp18;
			fVec7[(IOTA & 1023)] = (fRec29 + (0.0136018759f * fTemp11));
			output7[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec7[((IOTA - iConst4) & 1023)])));
			float fTemp19 = (fConst1 * (((0.0200858265f * fTemp8) - ((0.0284083094f * fTemp7) + (0.0441608392f * fTemp9))) - (fConst3 * fRec31[1])));
			fRec33[0] = (fRec33[1] + fTemp19);
			fRec31[0] = fRec33[0];
			float fRec32 = fTemp19;
			fVec8[(IOTA & 1023)] = (fRec32 + (0.0134860827f * fTemp11));
			output8[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec8[((IOTA - iConst4) & 1023)])));
			float fTemp20 = (fConst1 * (((0.0199402012f * fTemp8) - ((0.0102873575f * fTemp7) + (0.0511998832f * fTemp9))) - (fConst3 * fRec34[1])));
			fRec36[0] = (fRec36[1] + fTemp20);
			fRec34[0] = fRec36[0];
			float fRec35 = fTemp20;
			fVec9[(IOTA & 1023)] = (fRec35 + (0.0133883059f * fTemp11));
			output9[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec9[((IOTA - iConst4) & 1023)])));
			float fTemp21 = (fConst1 * ((((0.0107658459f * fTemp7) + (0.0198206995f * fTemp8)) - (0.05091355f * fTemp9)) - (fConst3 * fRec37[1])));
			fRec39[0] = (fRec39[1] + fTemp21);
			fRec37[0] = fRec39[0];
			float fRec38 = fTemp21;
			fVec10[(IOTA & 1023)] = (fRec38 + (0.0133080706f * fTemp11));
			output10[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec10[((IOTA - iConst4) & 1023)])));
			float fTemp22 = (fConst1 * ((((0.029444078f * fTemp7) + (0.0197601542f * fTemp8)) - (0.0429131873f * fTemp9)) - (fConst3 * fRec40[1])));
			fRec42[0] = (fRec42[1] + fTemp22);
			fRec40[0] = fRec42[0];
			float fRec41 = fTemp22;
			fVec11[(IOTA & 1023)] = (fRec41 + (0.0132674184f * fTemp11));
			output11[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec11[((IOTA - iConst4) & 1023)])));
			float fTemp23 = (fConst1 * ((((0.0435499176f * fTemp7) + (0.0197619721f * fTemp8)) - (0.028772451f * fTemp9)) - (fConst3 * fRec43[1])));
			fRec45[0] = (fRec45[1] + fTemp23);
			fRec43[0] = fRec45[0];
			float fRec44 = fTemp23;
			fVec12[(IOTA & 1023)] = (fRec44 + (0.0132686393f * fTemp11));
			output12[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec12[((IOTA - iConst4) & 1023)])));
			float fTemp24 = (fConst1 * ((((0.0512182191f * fTemp7) + (0.0198216364f * fTemp8)) - (0.0110902544f * fTemp9)) - (fConst3 * fRec46[1])));
			fRec48[0] = (fRec48[1] + fTemp24);
			fRec46[0] = fRec48[0];
			float fRec47 = fTemp24;
			fVec13[(IOTA & 1023)] = (fRec47 + (0.0133086992f * fTemp11));
			output13[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec13[((IOTA - iConst4) & 1023)])));
			float fTemp25 = (fConst1 * ((((0.0517163575f * fTemp7) + (0.019940095f * fTemp8)) + (0.00957704894f * fTemp9)) - (fConst3 * fRec49[1])));
			fRec51[0] = (fRec51[1] + fTemp25);
			fRec49[0] = fRec51[0];
			float fRec50 = fTemp25;
			fVec14[(IOTA & 1023)] = (fRec50 + (0.0133882351f * fTemp11));
			output14[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec14[((IOTA - iConst4) & 1023)])));
			float fTemp26 = (fConst1 * ((((0.0445122533f * fTemp7) + (0.0200908091f * fTemp8)) + (0.0281868316f * fTemp9)) - (fConst3 * fRec52[1])));
			fRec54[0] = (fRec54[1] + fTemp26);
			fRec52[0] = fRec54[0];
			float fRec53 = fTemp26;
			fVec15[(IOTA & 1023)] = (fRec53 + (0.013489428f * fTemp11));
			output15[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec15[((IOTA - iConst4) & 1023)])));
			float fTemp27 = (fConst5 * ((((0.0166244842f * fTemp7) + (0.0281272698f * fTemp8)) + (0.0412974879f * fTemp9)) - (fConst6 * fRec55[1])));
			fRec57[0] = (fRec57[1] + fTemp27);
			fRec55[0] = fRec57[0];
			float fRec56 = fTemp27;
			fVec16[(IOTA & 511)] = (fRec56 + (0.0188852903f * fTemp11));
			output16[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec16[((IOTA - iConst7) & 511)])));
			float fTemp28 = (fConst5 * ((((0.0283230357f * fTemp8) + (0.0410879143f * fTemp9)) - (0.017599998f * fTemp7)) - (fConst6 * fRec58[1])));
			fRec60[0] = (fRec60[1] + fTemp28);
			fRec58[0] = fRec60[0];
			float fRec59 = fTemp28;
			fVec17[(IOTA & 511)] = (fRec59 + (0.0190167334f * fTemp11));
			output17[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec17[((IOTA - iConst7) & 511)])));
			float fTemp29 = (fConst5 * ((((0.0283166822f * fTemp8) + (0.0161428489f * fTemp9)) - (0.041937422f * fTemp7)) - (fConst6 * fRec61[1])));
			fRec63[0] = (fRec63[1] + fTemp29);
			fRec61[0] = fRec63[0];
			float fRec62 = fTemp29;
			fVec18[(IOTA & 511)] = (fRec62 + (0.0190124679f * fTemp11));
			output18[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec18[((IOTA - iConst7) & 511)])));
			float fTemp30 = (fConst5 * (((0.0281040948f * fTemp8) - ((0.0405962057f * fTemp7) + (0.0187553708f * fTemp9))) - (fConst6 * fRec64[1])));
			fRec66[0] = (fRec66[1] + fTemp30);
			fRec64[0] = fRec66[0];
			float fRec65 = fTemp30;
			fVec19[(IOTA & 511)] = (fRec65 + (0.0188697316f * fTemp11));
			output19[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec19[((IOTA - iConst7) & 511)])));
			float fTemp31 = (fConst5 * (((0.0278355423f * fTemp8) - ((0.0164951384f * fTemp7) + (0.0408709832f * fTemp9))) - (fConst6 * fRec67[1])));
			fRec69[0] = (fRec69[1] + fTemp31);
			fRec67[0] = fRec69[0];
			float fRec68 = fTemp31;
			fVec20[(IOTA & 511)] = (fRec68 + (0.0186894182f * fTemp11));
			output20[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec20[((IOTA - iConst7) & 511)])));
			float fTemp32 = (fConst5 * ((((0.0155715561f * fTemp7) + (0.0276513174f * fTemp8)) - (0.0408112854f * fTemp9)) - (fConst6 * fRec70[1])));
			fRec72[0] = (fRec72[1] + fTemp32);
			fRec70[0] = fRec72[0];
			float fRec71 = fTemp32;
			fVec21[(IOTA & 511)] = (fRec71 + (0.0185657255f * fTemp11));
			output21[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec21[((IOTA - iConst7) & 511)])));
			float fTemp33 = (fConst5 * ((((0.0400551818f * fTemp7) + (0.0276444778f * fTemp8)) - (0.0179699026f * fTemp9)) - (fConst6 * fRec73[1])));
			fRec75[0] = (fRec75[1] + fTemp33);
			fRec73[0] = fRec75[0];
			float fRec74 = fTemp33;
			fVec22[(IOTA & 511)] = (fRec74 + (0.0185611341f * fTemp11));
			output22[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec22[((IOTA - iConst7) & 511)])));
			float fTemp34 = (fConst5 * ((((0.0409858972f * fTemp7) + (0.0278438292f * fTemp8)) + (0.0169010833f * fTemp9)) - (fConst6 * fRec76[1])));
			fRec78[0] = (fRec78[1] + fTemp34);
			fRec76[0] = fRec78[0];
			float fRec77 = fTemp34;
			fVec23[(IOTA & 511)] = (fRec77 + (0.0186949819f * fTemp11));
			output23[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec23[((IOTA - iConst7) & 511)])));
			float fTemp35 = (fConst8 * ((((0.0131354248f * fTemp7) + (0.0362305269f * fTemp8)) + (0.0140374005f * fTemp9)) - (fConst9 * fRec79[1])));
			fRec81[0] = (fRec81[1] + fTemp35);
			fRec79[0] = fRec81[0];
			float fRec80 = fTemp35;
			fVec24[(IOTA & 255)] = (fRec80 + (0.0243260041f * fTemp11));
			output24[i] = FAUSTFLOAT((0.953550935f * (fRec0[0] * fVec24[((IOTA - iConst10) & 255)])));
			float fTemp36 = (fConst8 * ((((0.0363869146f * fTemp8) + (0.0139872627f * fTemp9)) - (0.0140849631f * fTemp7)) - (fConst9 * fRec82[1])));
			fRec84[0] = (fRec84[1] + fTemp36);
			fRec82[0] = fRec84[0];
			float fRec83 = fTemp36;
			fVec25[(IOTA & 255)] = (fRec83 + (0.0244310051f * fTemp11));
			output25[i] = FAUSTFLOAT((0.953550935f * (fRec0[0] * fVec25[((IOTA - iConst10) & 255)])));
			float fTemp37 = (fConst8 * (((0.036228627f * fTemp8) - ((0.0141351009f * fTemp7) + (0.0130255641f * fTemp9))) - (fConst9 * fRec85[1])));
			fRec87[0] = (fRec87[1] + fTemp37);
			fRec85[0] = fRec87[0];
			float fRec86 = fTemp37;
			fVec26[(IOTA & 255)] = (fRec86 + (0.0243247263f * fTemp11));
			output26[i] = FAUSTFLOAT((0.953550935f * (fRec0[0] * fVec26[((IOTA - iConst10) & 255)])));
			float fTemp38 = (fConst8 * ((((0.013085288f * fTemp7) + (0.0360722393f * fTemp8)) - (0.0129754273f * fTemp9)) - (fConst9 * fRec88[1])));
			fRec90[0] = (fRec90[1] + fTemp38);
			fRec88[0] = fRec90[0];
			float fRec89 = fTemp38;
			fVec27[(IOTA & 255)] = (fRec89 + (0.0242197253f * fTemp11));
			output27[i] = FAUSTFLOAT((0.953550935f * (fRec0[0] * fVec27[((IOTA - iConst10) & 255)])));
			float fTemp39 = (fConst11 * ((((0.0377016775f * fTemp8) + (0.000526474614f * fTemp9)) - (0.000520147383f * fTemp7)) - (fConst12 * fRec91[1])));
			fRec93[0] = (fRec93[1] + fTemp39);
			fRec91[0] = fRec93[0];
			float fRec92 = fTemp39;
			output28[i] = FAUSTFLOAT((fRec0[0] * (fRec92 + (0.0253137667f * fTemp11))));
			float fTemp40 = (fConst1 * ((((0.0219302345f * fTemp7) + (0.0140899783f * fTemp8)) + (0.0492566489f * fTemp9)) - (fConst3 * fRec94[1])));
			fRec96[0] = (fRec96[1] + fTemp40);
			fRec94[0] = fRec96[0];
			float fRec95 = fTemp40;
			fVec28[(IOTA & 1023)] = (fRec95 + (0.00946033373f * fTemp11));
			output29[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec28[((IOTA - iConst4) & 1023)])));
			float fTemp41 = (fConst1 * ((((0.00129641336f * fTemp7) + (0.0142357433f * fTemp8)) + (0.0538554601f * fTemp9)) - (fConst3 * fRec97[1])));
			fRec99[0] = (fRec99[1] + fTemp41);
			fRec97[0] = fRec99[0];
			float fRec98 = fTemp41;
			fVec29[(IOTA & 1023)] = (fRec98 + (0.00955820363f * fTemp11));
			output30[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec29[((IOTA - iConst4) & 1023)])));
			float fTemp42 = (fConst1 * ((((0.0143351583f * fTemp8) + (0.0501749553f * fTemp9)) - (0.0197288189f * fTemp7)) - (fConst3 * fRec100[1])));
			fRec102[0] = (fRec102[1] + fTemp42);
			fRec100[0] = fRec102[0];
			float fRec101 = fTemp42;
			fVec30[(IOTA & 1023)] = (fRec101 + (0.00962495245f * fTemp11));
			output31[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec30[((IOTA - iConst4) & 1023)])));
			float fTemp43 = (fConst1 * ((((0.0143714091f * fTemp8) + (0.0387824439f * fTemp9)) - (0.0376457274f * fTemp7)) - (fConst3 * fRec103[1])));
			fRec105[0] = (fRec105[1] + fTemp43);
			fRec103[0] = fRec105[0];
			float fRec104 = fTemp43;
			fVec31[(IOTA & 1023)] = (fRec104 + (0.00964929257f * fTemp11));
			output32[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec31[((IOTA - iConst4) & 1023)])));
			float fTemp44 = (fConst1 * ((((0.0143383145f * fTemp8) + (0.02109758f * fTemp9)) - (0.049932614f * fTemp7)) - (fConst3 * fRec106[1])));
			fRec108[0] = (fRec108[1] + fTemp44);
			fRec106[0] = fRec108[0];
			float fRec107 = fTemp44;
			fVec32[(IOTA & 1023)] = (fRec107 + (0.00962707214f * fTemp11));
			output33[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec32[((IOTA - iConst4) & 1023)])));
			float fTemp45 = (fConst1 * ((((0.0142408637f * fTemp8) + (0.000234429303f * fTemp9)) - (0.0542802587f * fTemp7)) - (fConst3 * fRec109[1])));
			fRec111[0] = (fRec111[1] + fTemp45);
			fRec109[0] = fRec111[0];
			float fRec110 = fTemp45;
			fVec33[(IOTA & 1023)] = (fRec110 + (0.00956164114f * fTemp11));
			output34[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec33[((IOTA - iConst4) & 1023)])));
			float fTemp46 = (fConst1 * (((0.0140912067f * fTemp8) - ((0.0499560721f * fTemp7) + (0.0210191291f * fTemp9))) - (fConst3 * fRec112[1])));
			fRec114[0] = (fRec114[1] + fTemp46);
			fRec112[0] = fRec114[0];
			float fRec113 = fTemp46;
			fVec34[(IOTA & 1023)] = (fRec113 + (0.00946115796f * fTemp11));
			output35[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec34[((IOTA - iConst4) & 1023)])));
			float fTemp47 = (fConst1 * (((0.0139159653f * fTemp8) - ((0.0375772454f * fTemp7) + (0.0387331694f * fTemp9))) - (fConst3 * fRec115[1])));
			fRec117[0] = (fRec117[1] + fTemp47);
			fRec115[0] = fRec117[0];
			float fRec116 = fTemp47;
			fVec35[(IOTA & 1023)] = (fRec116 + (0.00934349652f * fTemp11));
			output36[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec35[((IOTA - iConst4) & 1023)])));
			float fTemp48 = (fConst1 * (((0.0137500884f * fTemp8) - ((0.0200514384f * fTemp7) + (0.0498053133f * fTemp9))) - (fConst3 * fRec118[1])));
			fRec120[0] = (fRec120[1] + fTemp48);
			fRec118[0] = fRec120[0];
			float fRec119 = fTemp48;
			fVec36[(IOTA & 1023)] = (fRec119 + (0.00923212338f * fTemp11));
			output37[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec36[((IOTA - iConst4) & 1023)])));
			float fTemp49 = (fConst1 * (((0.0136157991f * fTemp8) - ((0.000470341911f * fTemp7) + (0.0534816161f * fTemp9))) - (fConst3 * fRec121[1])));
			fRec123[0] = (fRec123[1] + fTemp49);
			fRec121[0] = fRec123[0];
			float fRec122 = fTemp49;
			fVec37[(IOTA & 1023)] = (fRec122 + (0.00914195832f * fTemp11));
			output38[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec37[((IOTA - iConst4) & 1023)])));
			float fTemp50 = (fConst1 * ((((0.0214408059f * fTemp7) + (0.0135164466f * fTemp8)) - (0.0489218682f * fTemp9)) - (fConst3 * fRec124[1])));
			fRec126[0] = (fRec126[1] + fTemp50);
			fRec124[0] = fRec126[0];
			float fRec125 = fTemp50;
			fVec38[(IOTA & 1023)] = (fRec125 + (0.00907525048f * fTemp11));
			output39[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec38[((IOTA - iConst4) & 1023)])));
			float fTemp51 = (fConst1 * ((((0.038288977f * fTemp7) + (0.0134871975f * fTemp8)) - (0.0373844393f * fTemp9)) - (fConst3 * fRec127[1])));
			fRec129[0] = (fRec129[1] + fTemp51);
			fRec127[0] = fRec129[0];
			float fRec128 = fTemp51;
			fVec39[(IOTA & 1023)] = (fRec128 + (0.00905561261f * fTemp11));
			output40[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec39[((IOTA - iConst4) & 1023)])));
			float fTemp52 = (fConst1 * ((((0.0496098362f * fTemp7) + (0.0135207744f * fTemp8)) - (0.0205647182f * fTemp9)) - (fConst3 * fRec130[1])));
			fRec132[0] = (fRec132[1] + fTemp52);
			fRec130[0] = fRec132[0];
			float fRec131 = fTemp52;
			fVec40[(IOTA & 1023)] = (fRec131 + (0.0090781562f * fTemp11));
			output41[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec40[((IOTA - iConst4) & 1023)])));
			float fTemp53 = (fConst1 * ((((0.0538574345f * fTemp7) + (0.0136073893f * fTemp8)) - (0.00164541602f * fTemp9)) - (fConst3 * fRec133[1])));
			fRec135[0] = (fRec135[1] + fTemp53);
			fRec133[0] = fRec135[0];
			float fRec134 = fTemp53;
			fVec41[(IOTA & 1023)] = (fRec134 + (0.00913631171f * fTemp11));
			output42[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec41[((IOTA - iConst4) & 1023)])));
			float fTemp54 = (fConst1 * ((((0.0501729362f * fTemp7) + (0.0137553727f * fTemp8)) + (0.0199502502f * fTemp9)) - (fConst3 * fRec136[1])));
			fRec138[0] = (fRec138[1] + fTemp54);
			fRec136[0] = fRec138[0];
			float fRec137 = fTemp54;
			fVec42[(IOTA & 1023)] = (fRec137 + (0.00923567172f * fTemp11));
			output43[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec42[((IOTA - iConst4) & 1023)])));
			float fTemp55 = (fConst1 * ((((0.0393984765f * fTemp7) + (0.0139169618f * fTemp8)) + (0.0369117446f * fTemp9)) - (fConst3 * fRec139[1])));
			fRec141[0] = (fRec141[1] + fTemp55);
			fRec139[0] = fRec141[0];
			float fRec140 = fTemp55;
			fVec43[(IOTA & 1023)] = (fRec140 + (0.00934416614f * fTemp11));
			output44[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec43[((IOTA - iConst4) & 1023)])));
			fRec0[1] = fRec0[0];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec3[1] = fRec3[0];
			fRec1[1] = fRec1[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			IOTA = (IOTA + 1);
			fRec12[1] = fRec12[0];
			fRec10[1] = fRec10[0];
			fRec15[1] = fRec15[0];
			fRec13[1] = fRec13[0];
			fRec18[1] = fRec18[0];
			fRec16[1] = fRec16[0];
			fRec21[1] = fRec21[0];
			fRec19[1] = fRec19[0];
			fRec24[1] = fRec24[0];
			fRec22[1] = fRec22[0];
			fRec27[1] = fRec27[0];
			fRec25[1] = fRec25[0];
			fRec30[1] = fRec30[0];
			fRec28[1] = fRec28[0];
			fRec33[1] = fRec33[0];
			fRec31[1] = fRec31[0];
			fRec36[1] = fRec36[0];
			fRec34[1] = fRec34[0];
			fRec39[1] = fRec39[0];
			fRec37[1] = fRec37[0];
			fRec42[1] = fRec42[0];
			fRec40[1] = fRec40[0];
			fRec45[1] = fRec45[0];
			fRec43[1] = fRec43[0];
			fRec48[1] = fRec48[0];
			fRec46[1] = fRec46[0];
			fRec51[1] = fRec51[0];
			fRec49[1] = fRec49[0];
			fRec54[1] = fRec54[0];
			fRec52[1] = fRec52[0];
			fRec57[1] = fRec57[0];
			fRec55[1] = fRec55[0];
			fRec60[1] = fRec60[0];
			fRec58[1] = fRec58[0];
			fRec63[1] = fRec63[0];
			fRec61[1] = fRec61[0];
			fRec66[1] = fRec66[0];
			fRec64[1] = fRec64[0];
			fRec69[1] = fRec69[0];
			fRec67[1] = fRec67[0];
			fRec72[1] = fRec72[0];
			fRec70[1] = fRec70[0];
			fRec75[1] = fRec75[0];
			fRec73[1] = fRec73[0];
			fRec78[1] = fRec78[0];
			fRec76[1] = fRec76[0];
			fRec81[1] = fRec81[0];
			fRec79[1] = fRec79[0];
			fRec84[1] = fRec84[0];
			fRec82[1] = fRec82[0];
			fRec87[1] = fRec87[0];
			fRec85[1] = fRec85[0];
			fRec90[1] = fRec90[0];
			fRec88[1] = fRec88[0];
			fRec93[1] = fRec93[0];
			fRec91[1] = fRec91[0];
			fRec96[1] = fRec96[0];
			fRec94[1] = fRec94[0];
			fRec99[1] = fRec99[0];
			fRec97[1] = fRec97[0];
			fRec102[1] = fRec102[0];
			fRec100[1] = fRec100[0];
			fRec105[1] = fRec105[0];
			fRec103[1] = fRec103[0];
			fRec108[1] = fRec108[0];
			fRec106[1] = fRec106[0];
			fRec111[1] = fRec111[0];
			fRec109[1] = fRec109[0];
			fRec114[1] = fRec114[0];
			fRec112[1] = fRec112[0];
			fRec117[1] = fRec117[0];
			fRec115[1] = fRec115[0];
			fRec120[1] = fRec120[0];
			fRec118[1] = fRec118[0];
			fRec123[1] = fRec123[0];
			fRec121[1] = fRec121[0];
			fRec126[1] = fRec126[0];
			fRec124[1] = fRec124[0];
			fRec129[1] = fRec129[0];
			fRec127[1] = fRec127[0];
			fRec132[1] = fRec132[0];
			fRec130[1] = fRec130[0];
			fRec135[1] = fRec135[0];
			fRec133[1] = fRec133[0];
			fRec138[1] = fRec138[0];
			fRec136[1] = fRec136[0];
			fRec141[1] = fRec141[0];
			fRec139[1] = fRec139[0];
			
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
