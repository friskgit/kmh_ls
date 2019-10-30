/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMHLS_FullSetup_3h3p_full_4"
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
	float fConst4;
	float fRec15[3];
	float fRec16[3];
	float fRec17[3];
	float fRec18[3];
	float fRec19[3];
	float fConst5;
	float fConst6;
	float fConst7;
	float fRec14[2];
	float fRec12[2];
	float fRec11[2];
	float fRec9[2];
	float fConst8;
	float fConst9;
	float fConst10;
	float fConst11;
	float fConst12;
	float fRec29[3];
	float fRec30[3];
	float fRec31[3];
	float fRec32[3];
	float fRec33[3];
	float fRec34[3];
	float fRec35[3];
	float fRec28[2];
	float fRec26[2];
	float fRec25[2];
	float fRec23[2];
	float fConst13;
	float fRec22[2];
	float fRec20[2];
	float fRec36[3];
	int IOTA;
	float fVec0[1024];
	int iConst14;
	float fRec42[2];
	float fRec40[2];
	float fRec39[2];
	float fRec37[2];
	float fRec45[2];
	float fRec43[2];
	float fRec54[2];
	float fRec52[2];
	float fRec51[2];
	float fRec49[2];
	float fRec48[2];
	float fRec46[2];
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
	float fRec150[2];
	float fRec148[2];
	float fRec147[2];
	float fRec145[2];
	float fRec153[2];
	float fRec151[2];
	float fRec162[2];
	float fRec160[2];
	float fRec159[2];
	float fRec157[2];
	float fRec156[2];
	float fRec154[2];
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
	float fRec201[2];
	float fRec199[2];
	float fRec207[2];
	float fRec205[2];
	float fRec204[2];
	float fRec202[2];
	float fRec216[2];
	float fRec214[2];
	float fRec213[2];
	float fRec211[2];
	float fRec210[2];
	float fRec208[2];
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
	float fRec276[2];
	float fRec274[2];
	float fRec273[2];
	float fRec271[2];
	float fRec279[2];
	float fRec277[2];
	float fRec288[2];
	float fRec286[2];
	float fRec285[2];
	float fRec283[2];
	float fRec282[2];
	float fRec280[2];
	float fVec14[1024];
	float fRec294[2];
	float fRec292[2];
	float fRec291[2];
	float fRec289[2];
	float fRec297[2];
	float fRec295[2];
	float fRec306[2];
	float fRec304[2];
	float fRec303[2];
	float fRec301[2];
	float fRec300[2];
	float fRec298[2];
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
	float fRec345[2];
	float fRec343[2];
	float fRec351[2];
	float fRec349[2];
	float fRec348[2];
	float fRec346[2];
	float fRec360[2];
	float fRec358[2];
	float fRec357[2];
	float fRec355[2];
	float fRec354[2];
	float fRec352[2];
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
	float fRec405[2];
	float fRec403[2];
	float fRec402[2];
	float fRec400[2];
	float fRec399[2];
	float fRec397[2];
	float fRec408[2];
	float fRec406[2];
	float fRec414[2];
	float fRec412[2];
	float fRec411[2];
	float fRec409[2];
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
	float fRec441[2];
	float fRec439[2];
	float fRec438[2];
	float fRec436[2];
	float fRec435[2];
	float fRec433[2];
	float fRec444[2];
	float fRec442[2];
	float fRec450[2];
	float fRec448[2];
	float fRec447[2];
	float fRec445[2];
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
	float fRec474[2];
	float fRec472[2];
	float fRec471[2];
	float fRec469[2];
	float fRec477[2];
	float fRec475[2];
	float fRec486[2];
	float fRec484[2];
	float fRec483[2];
	float fRec481[2];
	float fRec480[2];
	float fRec478[2];
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
	float fRec525[2];
	float fRec523[2];
	float fConst41;
	float fConst42;
	float fConst43;
	float fRec531[2];
	float fRec529[2];
	float fRec528[2];
	float fRec526[2];
	float fConst44;
	float fConst45;
	float fConst46;
	float fConst47;
	float fConst48;
	float fRec540[2];
	float fRec538[2];
	float fRec537[2];
	float fRec535[2];
	float fConst49;
	float fRec534[2];
	float fRec532[2];
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
	float fRec561[2];
	float fRec559[2];
	float fRec567[2];
	float fRec565[2];
	float fRec564[2];
	float fRec562[2];
	float fRec576[2];
	float fRec574[2];
	float fRec573[2];
	float fRec571[2];
	float fRec570[2];
	float fRec568[2];
	float fVec29[1024];
	float fRec582[2];
	float fRec580[2];
	float fRec579[2];
	float fRec577[2];
	float fRec585[2];
	float fRec583[2];
	float fRec594[2];
	float fRec592[2];
	float fRec591[2];
	float fRec589[2];
	float fRec588[2];
	float fRec586[2];
	float fVec30[1024];
	float fRec597[2];
	float fRec595[2];
	float fRec603[2];
	float fRec601[2];
	float fRec600[2];
	float fRec598[2];
	float fRec612[2];
	float fRec610[2];
	float fRec609[2];
	float fRec607[2];
	float fRec606[2];
	float fRec604[2];
	float fVec31[1024];
	float fRec615[2];
	float fRec613[2];
	float fRec621[2];
	float fRec619[2];
	float fRec618[2];
	float fRec616[2];
	float fRec630[2];
	float fRec628[2];
	float fRec627[2];
	float fRec625[2];
	float fRec624[2];
	float fRec622[2];
	float fVec32[1024];
	float fRec636[2];
	float fRec634[2];
	float fRec633[2];
	float fRec631[2];
	float fRec639[2];
	float fRec637[2];
	float fRec648[2];
	float fRec646[2];
	float fRec645[2];
	float fRec643[2];
	float fRec642[2];
	float fRec640[2];
	float fVec33[1024];
	float fRec651[2];
	float fRec649[2];
	float fRec657[2];
	float fRec655[2];
	float fRec654[2];
	float fRec652[2];
	float fRec666[2];
	float fRec664[2];
	float fRec663[2];
	float fRec661[2];
	float fRec660[2];
	float fRec658[2];
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
	float fRec744[2];
	float fRec742[2];
	float fRec741[2];
	float fRec739[2];
	float fRec747[2];
	float fRec745[2];
	float fRec756[2];
	float fRec754[2];
	float fRec753[2];
	float fRec751[2];
	float fRec750[2];
	float fRec748[2];
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
		m->declare("author", "AmbisonicDecoderToolkit");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMHLS_FullSetup_3h3p_full_4.dsp");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMHLS_FullSetup_3h3p_full_4");
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
		fConst1 = (1.0f / ((37.2250137f / fConst0) + 1.0f));
		fConst2 = (3.14159274f / fConst0);
		fConst3 = (74.4500275f / fConst0);
		fConst4 = (1.0f / ((((4157.10498f / fConst0) + 111.675041f) / fConst0) + 1.0f));
		fConst5 = (1.0f / fConst0);
		fConst6 = (16628.4199f / fConst0);
		fConst7 = (fConst6 + 223.350082f);
		fConst8 = (1.0f / ((((8950.84668f / fConst0) + 136.906693f) / fConst0) + 1.0f));
		fConst9 = (35803.3867f / fConst0);
		fConst10 = (fConst9 + 273.813385f);
		fConst11 = ((86.4433823f / fConst0) + 1.0f);
		fConst12 = (1.0f / fConst11);
		fConst13 = (172.886765f / (fConst0 * fConst11));
		iConst14 = int(((0.00281456532f * fConst0) + 0.5f));
		fConst15 = (1.0f / ((((7981.24072f / fConst0) + 129.278961f) / fConst0) + 1.0f));
		fConst16 = ((81.6271973f / fConst0) + 1.0f);
		fConst17 = (1.0f / fConst16);
		fConst18 = (31924.9629f / fConst0);
		fConst19 = (fConst18 + 258.557922f);
		fConst20 = (163.254395f / (fConst0 * fConst16));
		fConst21 = (1.0f / ((35.1510277f / fConst0) + 1.0f));
		fConst22 = (70.3020554f / fConst0);
		fConst23 = (1.0f / ((((3706.78394f / fConst0) + 105.453079f) / fConst0) + 1.0f));
		fConst24 = (14827.1357f / fConst0);
		fConst25 = (fConst24 + 210.906158f);
		iConst26 = int(((0.00202205847f * fConst0) + 0.5f));
		fConst27 = (1.0f / ((((6728.72266f / fConst0) + 118.702255f) / fConst0) + 1.0f));
		fConst28 = ((74.949028f / fConst0) + 1.0f);
		fConst29 = (1.0f / fConst28);
		fConst30 = (26914.8906f / fConst0);
		fConst31 = (fConst30 + 237.40451f);
		fConst32 = (149.898056f / (fConst0 * fConst28));
		fConst33 = (1.0f / ((32.2752151f / fConst0) + 1.0f));
		fConst34 = (64.5504303f / fConst0);
		fConst35 = (1.0f / ((((3125.06836f / fConst0) + 96.8256378f) / fConst0) + 1.0f));
		fConst36 = (12500.2734f / fConst0);
		fConst37 = (fConst36 + 193.651276f);
		iConst38 = int(((0.000754629844f * fConst0) + 0.5f));
		fConst39 = (1.0f / ((30.7760601f / fConst0) + 1.0f));
		fConst40 = (61.5521202f / fConst0);
		fConst41 = (1.0f / ((((2841.49756f / fConst0) + 92.3281784f) / fConst0) + 1.0f));
		fConst42 = (11365.9902f / fConst0);
		fConst43 = (fConst42 + 184.656357f);
		fConst44 = (1.0f / ((((6118.1543f / fConst0) + 113.188644f) / fConst0) + 1.0f));
		fConst45 = (24472.6172f / fConst0);
		fConst46 = (fConst45 + 226.377289f);
		fConst47 = ((71.4677124f / fConst0) + 1.0f);
		fConst48 = (1.0f / fConst47);
		fConst49 = (142.935425f / (fConst0 * fConst47));
		
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
			fRec15[l8] = 0.0f;
			
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec16[l9] = 0.0f;
			
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec17[l10] = 0.0f;
			
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec18[l11] = 0.0f;
			
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec19[l12] = 0.0f;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec14[l13] = 0.0f;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec12[l14] = 0.0f;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec11[l15] = 0.0f;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec9[l16] = 0.0f;
			
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec29[l17] = 0.0f;
			
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec30[l18] = 0.0f;
			
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec31[l19] = 0.0f;
			
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec32[l20] = 0.0f;
			
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec33[l21] = 0.0f;
			
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec34[l22] = 0.0f;
			
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec35[l23] = 0.0f;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec28[l24] = 0.0f;
			
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec26[l25] = 0.0f;
			
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec25[l26] = 0.0f;
			
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec23[l27] = 0.0f;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec22[l28] = 0.0f;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec20[l29] = 0.0f;
			
		}
		for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) {
			fRec36[l30] = 0.0f;
			
		}
		IOTA = 0;
		for (int l31 = 0; (l31 < 1024); l31 = (l31 + 1)) {
			fVec0[l31] = 0.0f;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec42[l32] = 0.0f;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec40[l33] = 0.0f;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec39[l34] = 0.0f;
			
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec37[l35] = 0.0f;
			
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec45[l36] = 0.0f;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec43[l37] = 0.0f;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec54[l38] = 0.0f;
			
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec52[l39] = 0.0f;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec51[l40] = 0.0f;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec49[l41] = 0.0f;
			
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec48[l42] = 0.0f;
			
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec46[l43] = 0.0f;
			
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
			fRec150[l110] = 0.0f;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec148[l111] = 0.0f;
			
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec147[l112] = 0.0f;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec145[l113] = 0.0f;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec153[l114] = 0.0f;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec151[l115] = 0.0f;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec162[l116] = 0.0f;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec160[l117] = 0.0f;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec159[l118] = 0.0f;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec157[l119] = 0.0f;
			
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec156[l120] = 0.0f;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec154[l121] = 0.0f;
			
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
			fRec201[l149] = 0.0f;
			
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec199[l150] = 0.0f;
			
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec207[l151] = 0.0f;
			
		}
		for (int l152 = 0; (l152 < 2); l152 = (l152 + 1)) {
			fRec205[l152] = 0.0f;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec204[l153] = 0.0f;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec202[l154] = 0.0f;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec216[l155] = 0.0f;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec214[l156] = 0.0f;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec213[l157] = 0.0f;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec211[l158] = 0.0f;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec210[l159] = 0.0f;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec208[l160] = 0.0f;
			
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
			fRec276[l201] = 0.0f;
			
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec274[l202] = 0.0f;
			
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fRec273[l203] = 0.0f;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec271[l204] = 0.0f;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec279[l205] = 0.0f;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec277[l206] = 0.0f;
			
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec288[l207] = 0.0f;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec286[l208] = 0.0f;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec285[l209] = 0.0f;
			
		}
		for (int l210 = 0; (l210 < 2); l210 = (l210 + 1)) {
			fRec283[l210] = 0.0f;
			
		}
		for (int l211 = 0; (l211 < 2); l211 = (l211 + 1)) {
			fRec282[l211] = 0.0f;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec280[l212] = 0.0f;
			
		}
		for (int l213 = 0; (l213 < 1024); l213 = (l213 + 1)) {
			fVec14[l213] = 0.0f;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fRec294[l214] = 0.0f;
			
		}
		for (int l215 = 0; (l215 < 2); l215 = (l215 + 1)) {
			fRec292[l215] = 0.0f;
			
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fRec291[l216] = 0.0f;
			
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec289[l217] = 0.0f;
			
		}
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fRec297[l218] = 0.0f;
			
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec295[l219] = 0.0f;
			
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fRec306[l220] = 0.0f;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec304[l221] = 0.0f;
			
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec303[l222] = 0.0f;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec301[l223] = 0.0f;
			
		}
		for (int l224 = 0; (l224 < 2); l224 = (l224 + 1)) {
			fRec300[l224] = 0.0f;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec298[l225] = 0.0f;
			
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
			fRec345[l253] = 0.0f;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec343[l254] = 0.0f;
			
		}
		for (int l255 = 0; (l255 < 2); l255 = (l255 + 1)) {
			fRec351[l255] = 0.0f;
			
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec349[l256] = 0.0f;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fRec348[l257] = 0.0f;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec346[l258] = 0.0f;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec360[l259] = 0.0f;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec358[l260] = 0.0f;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec357[l261] = 0.0f;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec355[l262] = 0.0f;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec354[l263] = 0.0f;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec352[l264] = 0.0f;
			
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
			fRec405[l292] = 0.0f;
			
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec403[l293] = 0.0f;
			
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec402[l294] = 0.0f;
			
		}
		for (int l295 = 0; (l295 < 2); l295 = (l295 + 1)) {
			fRec400[l295] = 0.0f;
			
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec399[l296] = 0.0f;
			
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec397[l297] = 0.0f;
			
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec408[l298] = 0.0f;
			
		}
		for (int l299 = 0; (l299 < 2); l299 = (l299 + 1)) {
			fRec406[l299] = 0.0f;
			
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec414[l300] = 0.0f;
			
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec412[l301] = 0.0f;
			
		}
		for (int l302 = 0; (l302 < 2); l302 = (l302 + 1)) {
			fRec411[l302] = 0.0f;
			
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec409[l303] = 0.0f;
			
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
			fRec441[l318] = 0.0f;
			
		}
		for (int l319 = 0; (l319 < 2); l319 = (l319 + 1)) {
			fRec439[l319] = 0.0f;
			
		}
		for (int l320 = 0; (l320 < 2); l320 = (l320 + 1)) {
			fRec438[l320] = 0.0f;
			
		}
		for (int l321 = 0; (l321 < 2); l321 = (l321 + 1)) {
			fRec436[l321] = 0.0f;
			
		}
		for (int l322 = 0; (l322 < 2); l322 = (l322 + 1)) {
			fRec435[l322] = 0.0f;
			
		}
		for (int l323 = 0; (l323 < 2); l323 = (l323 + 1)) {
			fRec433[l323] = 0.0f;
			
		}
		for (int l324 = 0; (l324 < 2); l324 = (l324 + 1)) {
			fRec444[l324] = 0.0f;
			
		}
		for (int l325 = 0; (l325 < 2); l325 = (l325 + 1)) {
			fRec442[l325] = 0.0f;
			
		}
		for (int l326 = 0; (l326 < 2); l326 = (l326 + 1)) {
			fRec450[l326] = 0.0f;
			
		}
		for (int l327 = 0; (l327 < 2); l327 = (l327 + 1)) {
			fRec448[l327] = 0.0f;
			
		}
		for (int l328 = 0; (l328 < 2); l328 = (l328 + 1)) {
			fRec447[l328] = 0.0f;
			
		}
		for (int l329 = 0; (l329 < 2); l329 = (l329 + 1)) {
			fRec445[l329] = 0.0f;
			
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
			fRec474[l344] = 0.0f;
			
		}
		for (int l345 = 0; (l345 < 2); l345 = (l345 + 1)) {
			fRec472[l345] = 0.0f;
			
		}
		for (int l346 = 0; (l346 < 2); l346 = (l346 + 1)) {
			fRec471[l346] = 0.0f;
			
		}
		for (int l347 = 0; (l347 < 2); l347 = (l347 + 1)) {
			fRec469[l347] = 0.0f;
			
		}
		for (int l348 = 0; (l348 < 2); l348 = (l348 + 1)) {
			fRec477[l348] = 0.0f;
			
		}
		for (int l349 = 0; (l349 < 2); l349 = (l349 + 1)) {
			fRec475[l349] = 0.0f;
			
		}
		for (int l350 = 0; (l350 < 2); l350 = (l350 + 1)) {
			fRec486[l350] = 0.0f;
			
		}
		for (int l351 = 0; (l351 < 2); l351 = (l351 + 1)) {
			fRec484[l351] = 0.0f;
			
		}
		for (int l352 = 0; (l352 < 2); l352 = (l352 + 1)) {
			fRec483[l352] = 0.0f;
			
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec481[l353] = 0.0f;
			
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec480[l354] = 0.0f;
			
		}
		for (int l355 = 0; (l355 < 2); l355 = (l355 + 1)) {
			fRec478[l355] = 0.0f;
			
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
			fRec525[l383] = 0.0f;
			
		}
		for (int l384 = 0; (l384 < 2); l384 = (l384 + 1)) {
			fRec523[l384] = 0.0f;
			
		}
		for (int l385 = 0; (l385 < 2); l385 = (l385 + 1)) {
			fRec531[l385] = 0.0f;
			
		}
		for (int l386 = 0; (l386 < 2); l386 = (l386 + 1)) {
			fRec529[l386] = 0.0f;
			
		}
		for (int l387 = 0; (l387 < 2); l387 = (l387 + 1)) {
			fRec528[l387] = 0.0f;
			
		}
		for (int l388 = 0; (l388 < 2); l388 = (l388 + 1)) {
			fRec526[l388] = 0.0f;
			
		}
		for (int l389 = 0; (l389 < 2); l389 = (l389 + 1)) {
			fRec540[l389] = 0.0f;
			
		}
		for (int l390 = 0; (l390 < 2); l390 = (l390 + 1)) {
			fRec538[l390] = 0.0f;
			
		}
		for (int l391 = 0; (l391 < 2); l391 = (l391 + 1)) {
			fRec537[l391] = 0.0f;
			
		}
		for (int l392 = 0; (l392 < 2); l392 = (l392 + 1)) {
			fRec535[l392] = 0.0f;
			
		}
		for (int l393 = 0; (l393 < 2); l393 = (l393 + 1)) {
			fRec534[l393] = 0.0f;
			
		}
		for (int l394 = 0; (l394 < 2); l394 = (l394 + 1)) {
			fRec532[l394] = 0.0f;
			
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
			fRec561[l408] = 0.0f;
			
		}
		for (int l409 = 0; (l409 < 2); l409 = (l409 + 1)) {
			fRec559[l409] = 0.0f;
			
		}
		for (int l410 = 0; (l410 < 2); l410 = (l410 + 1)) {
			fRec567[l410] = 0.0f;
			
		}
		for (int l411 = 0; (l411 < 2); l411 = (l411 + 1)) {
			fRec565[l411] = 0.0f;
			
		}
		for (int l412 = 0; (l412 < 2); l412 = (l412 + 1)) {
			fRec564[l412] = 0.0f;
			
		}
		for (int l413 = 0; (l413 < 2); l413 = (l413 + 1)) {
			fRec562[l413] = 0.0f;
			
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec576[l414] = 0.0f;
			
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec574[l415] = 0.0f;
			
		}
		for (int l416 = 0; (l416 < 2); l416 = (l416 + 1)) {
			fRec573[l416] = 0.0f;
			
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec571[l417] = 0.0f;
			
		}
		for (int l418 = 0; (l418 < 2); l418 = (l418 + 1)) {
			fRec570[l418] = 0.0f;
			
		}
		for (int l419 = 0; (l419 < 2); l419 = (l419 + 1)) {
			fRec568[l419] = 0.0f;
			
		}
		for (int l420 = 0; (l420 < 1024); l420 = (l420 + 1)) {
			fVec29[l420] = 0.0f;
			
		}
		for (int l421 = 0; (l421 < 2); l421 = (l421 + 1)) {
			fRec582[l421] = 0.0f;
			
		}
		for (int l422 = 0; (l422 < 2); l422 = (l422 + 1)) {
			fRec580[l422] = 0.0f;
			
		}
		for (int l423 = 0; (l423 < 2); l423 = (l423 + 1)) {
			fRec579[l423] = 0.0f;
			
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec577[l424] = 0.0f;
			
		}
		for (int l425 = 0; (l425 < 2); l425 = (l425 + 1)) {
			fRec585[l425] = 0.0f;
			
		}
		for (int l426 = 0; (l426 < 2); l426 = (l426 + 1)) {
			fRec583[l426] = 0.0f;
			
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec594[l427] = 0.0f;
			
		}
		for (int l428 = 0; (l428 < 2); l428 = (l428 + 1)) {
			fRec592[l428] = 0.0f;
			
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec591[l429] = 0.0f;
			
		}
		for (int l430 = 0; (l430 < 2); l430 = (l430 + 1)) {
			fRec589[l430] = 0.0f;
			
		}
		for (int l431 = 0; (l431 < 2); l431 = (l431 + 1)) {
			fRec588[l431] = 0.0f;
			
		}
		for (int l432 = 0; (l432 < 2); l432 = (l432 + 1)) {
			fRec586[l432] = 0.0f;
			
		}
		for (int l433 = 0; (l433 < 1024); l433 = (l433 + 1)) {
			fVec30[l433] = 0.0f;
			
		}
		for (int l434 = 0; (l434 < 2); l434 = (l434 + 1)) {
			fRec597[l434] = 0.0f;
			
		}
		for (int l435 = 0; (l435 < 2); l435 = (l435 + 1)) {
			fRec595[l435] = 0.0f;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec603[l436] = 0.0f;
			
		}
		for (int l437 = 0; (l437 < 2); l437 = (l437 + 1)) {
			fRec601[l437] = 0.0f;
			
		}
		for (int l438 = 0; (l438 < 2); l438 = (l438 + 1)) {
			fRec600[l438] = 0.0f;
			
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec598[l439] = 0.0f;
			
		}
		for (int l440 = 0; (l440 < 2); l440 = (l440 + 1)) {
			fRec612[l440] = 0.0f;
			
		}
		for (int l441 = 0; (l441 < 2); l441 = (l441 + 1)) {
			fRec610[l441] = 0.0f;
			
		}
		for (int l442 = 0; (l442 < 2); l442 = (l442 + 1)) {
			fRec609[l442] = 0.0f;
			
		}
		for (int l443 = 0; (l443 < 2); l443 = (l443 + 1)) {
			fRec607[l443] = 0.0f;
			
		}
		for (int l444 = 0; (l444 < 2); l444 = (l444 + 1)) {
			fRec606[l444] = 0.0f;
			
		}
		for (int l445 = 0; (l445 < 2); l445 = (l445 + 1)) {
			fRec604[l445] = 0.0f;
			
		}
		for (int l446 = 0; (l446 < 1024); l446 = (l446 + 1)) {
			fVec31[l446] = 0.0f;
			
		}
		for (int l447 = 0; (l447 < 2); l447 = (l447 + 1)) {
			fRec615[l447] = 0.0f;
			
		}
		for (int l448 = 0; (l448 < 2); l448 = (l448 + 1)) {
			fRec613[l448] = 0.0f;
			
		}
		for (int l449 = 0; (l449 < 2); l449 = (l449 + 1)) {
			fRec621[l449] = 0.0f;
			
		}
		for (int l450 = 0; (l450 < 2); l450 = (l450 + 1)) {
			fRec619[l450] = 0.0f;
			
		}
		for (int l451 = 0; (l451 < 2); l451 = (l451 + 1)) {
			fRec618[l451] = 0.0f;
			
		}
		for (int l452 = 0; (l452 < 2); l452 = (l452 + 1)) {
			fRec616[l452] = 0.0f;
			
		}
		for (int l453 = 0; (l453 < 2); l453 = (l453 + 1)) {
			fRec630[l453] = 0.0f;
			
		}
		for (int l454 = 0; (l454 < 2); l454 = (l454 + 1)) {
			fRec628[l454] = 0.0f;
			
		}
		for (int l455 = 0; (l455 < 2); l455 = (l455 + 1)) {
			fRec627[l455] = 0.0f;
			
		}
		for (int l456 = 0; (l456 < 2); l456 = (l456 + 1)) {
			fRec625[l456] = 0.0f;
			
		}
		for (int l457 = 0; (l457 < 2); l457 = (l457 + 1)) {
			fRec624[l457] = 0.0f;
			
		}
		for (int l458 = 0; (l458 < 2); l458 = (l458 + 1)) {
			fRec622[l458] = 0.0f;
			
		}
		for (int l459 = 0; (l459 < 1024); l459 = (l459 + 1)) {
			fVec32[l459] = 0.0f;
			
		}
		for (int l460 = 0; (l460 < 2); l460 = (l460 + 1)) {
			fRec636[l460] = 0.0f;
			
		}
		for (int l461 = 0; (l461 < 2); l461 = (l461 + 1)) {
			fRec634[l461] = 0.0f;
			
		}
		for (int l462 = 0; (l462 < 2); l462 = (l462 + 1)) {
			fRec633[l462] = 0.0f;
			
		}
		for (int l463 = 0; (l463 < 2); l463 = (l463 + 1)) {
			fRec631[l463] = 0.0f;
			
		}
		for (int l464 = 0; (l464 < 2); l464 = (l464 + 1)) {
			fRec639[l464] = 0.0f;
			
		}
		for (int l465 = 0; (l465 < 2); l465 = (l465 + 1)) {
			fRec637[l465] = 0.0f;
			
		}
		for (int l466 = 0; (l466 < 2); l466 = (l466 + 1)) {
			fRec648[l466] = 0.0f;
			
		}
		for (int l467 = 0; (l467 < 2); l467 = (l467 + 1)) {
			fRec646[l467] = 0.0f;
			
		}
		for (int l468 = 0; (l468 < 2); l468 = (l468 + 1)) {
			fRec645[l468] = 0.0f;
			
		}
		for (int l469 = 0; (l469 < 2); l469 = (l469 + 1)) {
			fRec643[l469] = 0.0f;
			
		}
		for (int l470 = 0; (l470 < 2); l470 = (l470 + 1)) {
			fRec642[l470] = 0.0f;
			
		}
		for (int l471 = 0; (l471 < 2); l471 = (l471 + 1)) {
			fRec640[l471] = 0.0f;
			
		}
		for (int l472 = 0; (l472 < 1024); l472 = (l472 + 1)) {
			fVec33[l472] = 0.0f;
			
		}
		for (int l473 = 0; (l473 < 2); l473 = (l473 + 1)) {
			fRec651[l473] = 0.0f;
			
		}
		for (int l474 = 0; (l474 < 2); l474 = (l474 + 1)) {
			fRec649[l474] = 0.0f;
			
		}
		for (int l475 = 0; (l475 < 2); l475 = (l475 + 1)) {
			fRec657[l475] = 0.0f;
			
		}
		for (int l476 = 0; (l476 < 2); l476 = (l476 + 1)) {
			fRec655[l476] = 0.0f;
			
		}
		for (int l477 = 0; (l477 < 2); l477 = (l477 + 1)) {
			fRec654[l477] = 0.0f;
			
		}
		for (int l478 = 0; (l478 < 2); l478 = (l478 + 1)) {
			fRec652[l478] = 0.0f;
			
		}
		for (int l479 = 0; (l479 < 2); l479 = (l479 + 1)) {
			fRec666[l479] = 0.0f;
			
		}
		for (int l480 = 0; (l480 < 2); l480 = (l480 + 1)) {
			fRec664[l480] = 0.0f;
			
		}
		for (int l481 = 0; (l481 < 2); l481 = (l481 + 1)) {
			fRec663[l481] = 0.0f;
			
		}
		for (int l482 = 0; (l482 < 2); l482 = (l482 + 1)) {
			fRec661[l482] = 0.0f;
			
		}
		for (int l483 = 0; (l483 < 2); l483 = (l483 + 1)) {
			fRec660[l483] = 0.0f;
			
		}
		for (int l484 = 0; (l484 < 2); l484 = (l484 + 1)) {
			fRec658[l484] = 0.0f;
			
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
			fRec744[l538] = 0.0f;
			
		}
		for (int l539 = 0; (l539 < 2); l539 = (l539 + 1)) {
			fRec742[l539] = 0.0f;
			
		}
		for (int l540 = 0; (l540 < 2); l540 = (l540 + 1)) {
			fRec741[l540] = 0.0f;
			
		}
		for (int l541 = 0; (l541 < 2); l541 = (l541 + 1)) {
			fRec739[l541] = 0.0f;
			
		}
		for (int l542 = 0; (l542 < 2); l542 = (l542 + 1)) {
			fRec747[l542] = 0.0f;
			
		}
		for (int l543 = 0; (l543 < 2); l543 = (l543 + 1)) {
			fRec745[l543] = 0.0f;
			
		}
		for (int l544 = 0; (l544 < 2); l544 = (l544 + 1)) {
			fRec756[l544] = 0.0f;
			
		}
		for (int l545 = 0; (l545 < 2); l545 = (l545 + 1)) {
			fRec754[l545] = 0.0f;
			
		}
		for (int l546 = 0; (l546 < 2); l546 = (l546 + 1)) {
			fRec753[l546] = 0.0f;
			
		}
		for (int l547 = 0; (l547 < 2); l547 = (l547 + 1)) {
			fRec751[l547] = 0.0f;
			
		}
		for (int l548 = 0; (l548 < 2); l548 = (l548 + 1)) {
			fRec750[l548] = 0.0f;
			
		}
		for (int l549 = 0; (l549 < 2); l549 = (l549 + 1)) {
			fRec748[l549] = 0.0f;
			
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
		ui_interface->openVerticalBox("KMHLS_FullSetup_3h3p_full_4");
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
			float fTemp7 = (((fTemp1 * (fRec5[2] + (fRec5[0] + (2.0f * fRec5[1])))) / fTemp5) + (2.40914083f * (fRec6[0] * (0.0f - ((fTemp6 * fRec5[1]) + ((fRec5[0] + fRec5[2]) / fTemp4))))));
			fRec7[0] = (float(input2[i]) - (((fTemp2 * fRec7[2]) + (2.0f * (fTemp3 * fRec7[1]))) / fTemp4));
			float fTemp8 = (((fTemp1 * (fRec7[2] + (fRec7[0] + (2.0f * fRec7[1])))) / fTemp5) + (2.40914083f * (fRec6[0] * (0.0f - ((fTemp6 * fRec7[1]) + ((fRec7[0] + fRec7[2]) / fTemp4))))));
			fRec8[0] = (float(input3[i]) - (((fTemp2 * fRec8[2]) + (2.0f * (fTemp3 * fRec8[1]))) / fTemp4));
			float fTemp9 = (((fTemp1 * (fRec8[2] + (fRec8[0] + (2.0f * fRec8[1])))) / fTemp5) + (2.40914083f * (fRec6[0] * (0.0f - ((fTemp6 * fRec8[1]) + ((fRec8[0] + fRec8[2]) / fTemp4))))));
			float fTemp10 = (fConst1 * ((((0.00307707628f * fTemp7) + (0.536454558f * fTemp8)) + (0.0043273624f * fTemp9)) - (fConst3 * fRec1[1])));
			fRec3[0] = (fRec3[1] + fTemp10);
			fRec1[0] = fRec3[0];
			float fRec2 = fTemp10;
			fRec15[0] = (float(input5[i]) - (((fTemp2 * fRec15[2]) + (2.0f * (fTemp3 * fRec15[1]))) / fTemp4));
			float fTemp11 = (((fTemp1 * (fRec15[2] + (fRec15[0] + (2.0f * fRec15[1])))) / fTemp5) + (1.71308291f * (fRec6[0] * (0.0f - ((fTemp6 * fRec15[1]) + ((fRec15[0] + fRec15[2]) / fTemp4))))));
			fRec16[0] = (float(input4[i]) - (((fTemp2 * fRec16[2]) + (2.0f * (fTemp3 * fRec16[1]))) / fTemp4));
			float fTemp12 = (((fTemp1 * (fRec16[2] + (fRec16[0] + (2.0f * fRec16[1])))) / fTemp5) + (1.71308291f * (fRec6[0] * (0.0f - ((fTemp6 * fRec16[1]) + ((fRec16[0] + fRec16[2]) / fTemp4))))));
			fRec17[0] = (float(input7[i]) - (((fTemp2 * fRec17[2]) + (2.0f * (fTemp3 * fRec17[1]))) / fTemp4));
			float fTemp13 = (((fTemp1 * (fRec17[2] + (fRec17[0] + (2.0f * fRec17[1])))) / fTemp5) + (1.71308291f * (fRec6[0] * (0.0f - ((fTemp6 * fRec17[1]) + ((fRec17[0] + fRec17[2]) / fTemp4))))));
			fRec18[0] = (float(input8[i]) - (((fTemp2 * fRec18[2]) + (2.0f * (fTemp3 * fRec18[1]))) / fTemp4));
			float fTemp14 = (((fTemp1 * (fRec18[2] + (fRec18[0] + (2.0f * fRec18[1])))) / fTemp5) + (1.71308291f * (fRec6[0] * (0.0f - ((fTemp6 * fRec18[1]) + ((fRec18[0] + fRec18[2]) / fTemp4))))));
			fRec19[0] = (float(input6[i]) - (((fTemp2 * fRec19[2]) + (2.0f * (fTemp3 * fRec19[1]))) / fTemp4));
			float fTemp15 = (((fTemp1 * (fRec19[2] + (fRec19[0] + (2.0f * fRec19[1])))) / fTemp5) + (1.71308291f * (fRec6[0] * (0.0f - ((fTemp6 * fRec19[1]) + ((fRec19[0] + fRec19[2]) / fTemp4))))));
			float fTemp16 = (fConst4 * ((((0.139131561f * fTemp11) + ((0.119125478f * fTemp12) + ((0.201512724f * fTemp13) + (0.044701796f * fTemp14)))) - (0.51456815f * fTemp15)) + (fConst5 * (0.0f - ((fConst7 * fRec12[1]) + (fConst6 * fRec9[1]))))));
			fRec14[0] = (fRec14[1] + fTemp16);
			fRec12[0] = fRec14[0];
			float fRec13 = fTemp16;
			fRec11[0] = (fRec12[0] + fRec11[1]);
			fRec9[0] = fRec11[0];
			float fRec10 = fRec13;
			fRec29[0] = (float(input9[i]) - (((fTemp2 * fRec29[2]) + (2.0f * (fTemp3 * fRec29[1]))) / fTemp4));
			float fTemp17 = (((fTemp1 * (fRec29[2] + (fRec29[0] + (2.0f * fRec29[1])))) / fTemp5) + (0.852569342f * (fRec6[0] * (0.0f - ((fTemp6 * fRec29[1]) + ((fRec29[0] + fRec29[2]) / fTemp4))))));
			fRec30[0] = (float(input10[i]) - (((fTemp2 * fRec30[2]) + (2.0f * (fTemp3 * fRec30[1]))) / fTemp4));
			float fTemp18 = (((fTemp1 * (fRec30[2] + (fRec30[0] + (2.0f * fRec30[1])))) / fTemp5) + (0.852569342f * (fRec6[0] * (0.0f - ((fTemp6 * fRec30[1]) + ((fRec30[0] + fRec30[2]) / fTemp4))))));
			fRec31[0] = (float(input12[i]) - (((fTemp2 * fRec31[2]) + (2.0f * (fTemp3 * fRec31[1]))) / fTemp4));
			float fTemp19 = (((fTemp1 * (fRec31[2] + (fRec31[0] + (2.0f * fRec31[1])))) / fTemp5) + (0.852569342f * (fRec6[0] * (0.0f - ((fTemp6 * fRec31[1]) + ((fRec31[0] + fRec31[2]) / fTemp4))))));
			fRec32[0] = (float(input14[i]) - (((fTemp2 * fRec32[2]) + (2.0f * (fTemp3 * fRec32[1]))) / fTemp4));
			float fTemp20 = (((fTemp1 * (fRec32[2] + (fRec32[0] + (2.0f * fRec32[1])))) / fTemp5) + (0.852569342f * (fRec6[0] * (0.0f - ((fTemp6 * fRec32[1]) + ((fRec32[0] + fRec32[2]) / fTemp4))))));
			fRec33[0] = (float(input11[i]) - (((fTemp2 * fRec33[2]) + (2.0f * (fTemp3 * fRec33[1]))) / fTemp4));
			float fTemp21 = (((fTemp1 * (fRec33[2] + (fRec33[0] + (2.0f * fRec33[1])))) / fTemp5) + (0.852569342f * (fRec6[0] * (0.0f - ((fTemp6 * fRec33[1]) + ((fRec33[0] + fRec33[2]) / fTemp4))))));
			fRec34[0] = (float(input13[i]) - (((fTemp2 * fRec34[2]) + (2.0f * (fTemp3 * fRec34[1]))) / fTemp4));
			float fTemp22 = (((fTemp1 * (fRec34[2] + (fRec34[0] + (2.0f * fRec34[1])))) / fTemp5) + (0.852569342f * (fRec6[0] * (0.0f - ((fTemp6 * fRec34[1]) + ((fRec34[0] + fRec34[2]) / fTemp4))))));
			fRec35[0] = (float(input15[i]) - (((fTemp2 * fRec35[2]) + (2.0f * (fTemp3 * fRec35[1]))) / fTemp4));
			float fTemp23 = (((fTemp1 * (fRec35[2] + (fRec35[0] + (2.0f * fRec35[1])))) / fTemp5) + (0.852569342f * (fRec6[0] * (0.0f - ((fTemp6 * fRec35[1]) + ((fRec35[0] + fRec35[2]) / fTemp4))))));
			float fTemp24 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec26[1]) + (fConst9 * fRec23[1])))) + (fConst12 * (((((0.150217935f * fTemp17) + (0.0980835855f * fTemp18)) + (0.145619825f * fTemp19)) + (0.038579572f * fTemp20)) - (((0.132051751f * fTemp21) + (0.189451635f * fTemp22)) + (0.0369312316f * fTemp23))))));
			fRec28[0] = (fRec28[1] + fTemp24);
			fRec26[0] = fRec28[0];
			float fRec27 = fTemp24;
			fRec25[0] = (fRec26[0] + fRec25[1]);
			fRec23[0] = fRec25[0];
			float fRec24 = fRec27;
			float fTemp25 = (fConst13 * fRec20[1]);
			fRec22[0] = ((fRec24 + fRec22[1]) - fTemp25);
			fRec20[0] = fRec22[0];
			float fRec21 = (fRec24 - fTemp25);
			fRec36[0] = (float(input0[i]) - (((fRec36[2] * fTemp2) + (2.0f * (fRec36[1] * fTemp3))) / fTemp4));
			float fTemp26 = (((fTemp1 * (fRec36[2] + (fRec36[0] + (2.0f * fRec36[1])))) / fTemp5) + (2.79763007f * (fRec6[0] * (0.0f - ((fRec36[1] * fTemp6) + ((fRec36[0] + fRec36[2]) / fTemp4))))));
			fVec0[(IOTA & 1023)] = ((fRec2 + (fRec10 + fRec21)) - (0.15891397f * fTemp26));
			output0[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec0[((IOTA - iConst14) & 1023)])));
			float fTemp27 = (fConst4 * ((((0.0566642135f * fTemp11) + ((0.0583554693f * fTemp12) + ((0.236861259f * fTemp13) + (0.114018746f * fTemp14)))) - (0.518889189f * fTemp15)) + (fConst5 * (0.0f - ((fConst7 * fRec40[1]) + (fConst6 * fRec37[1]))))));
			fRec42[0] = (fRec42[1] + fTemp27);
			fRec40[0] = fRec42[0];
			float fRec41 = fTemp27;
			fRec39[0] = (fRec40[0] + fRec39[1]);
			fRec37[0] = fRec39[0];
			float fRec38 = fRec41;
			float fTemp28 = (fConst1 * ((((0.000629278016f * fTemp7) + (0.54107964f * fTemp8)) + (0.00715278741f * fTemp9)) - (fConst3 * fRec43[1])));
			fRec45[0] = (fRec45[1] + fTemp28);
			fRec43[0] = fRec45[0];
			float fRec44 = fTemp28;
			float fTemp29 = (fConst8 * ((fConst12 * ((((((0.0995588377f * fTemp17) + (0.046324946f * fTemp18)) + (0.147688359f * fTemp19)) + (0.0981910527f * fTemp20)) + (0.118612163f * fTemp23)) - ((0.0537781641f * fTemp21) + (0.221880361f * fTemp22)))) + (fConst5 * (0.0f - ((fConst10 * fRec52[1]) + (fConst9 * fRec49[1]))))));
			fRec54[0] = (fRec54[1] + fTemp29);
			fRec52[0] = fRec54[0];
			float fRec53 = fTemp29;
			fRec51[0] = (fRec52[0] + fRec51[1]);
			fRec49[0] = fRec51[0];
			float fRec50 = fRec53;
			float fTemp30 = (fConst13 * fRec46[1]);
			fRec48[0] = ((fRec50 + fRec48[1]) - fTemp30);
			fRec46[0] = fRec48[0];
			float fRec47 = (fRec50 - fTemp30);
			fVec1[(IOTA & 1023)] = ((fRec38 + (fRec44 + fRec47)) - (0.161209002f * fTemp26));
			output1[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec1[((IOTA - iConst14) & 1023)])));
			float fTemp31 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec61[1]) + (fConst9 * fRec58[1])))) + (fConst12 * (((((0.0437992476f * fTemp21) + (0.148251593f * fTemp19)) + (0.10293787f * fTemp20)) + (0.131665096f * fTemp23)) - (((0.0809970573f * fTemp17) + (0.0383432955f * fTemp18)) + (0.224622041f * fTemp22))))));
			fRec63[0] = (fRec63[1] + fTemp31);
			fRec61[0] = fRec63[0];
			float fRec62 = fTemp31;
			fRec60[0] = (fRec61[0] + fRec60[1]);
			fRec58[0] = fRec60[0];
			float fRec59 = fRec62;
			float fTemp32 = (fConst13 * fRec55[1]);
			fRec57[0] = ((fRec59 + fRec57[1]) - fTemp32);
			fRec55[0] = fRec57[0];
			float fRec56 = (fRec59 - fTemp32);
			float fTemp33 = (fConst1 * ((((0.544038773f * fTemp8) + (0.00813358184f * fTemp9)) - (0.000541546673f * fTemp7)) - (fConst3 * fRec64[1])));
			fRec66[0] = (fRec66[1] + fTemp33);
			fRec64[0] = fRec66[0];
			float fRec65 = fTemp33;
			float fTemp34 = (fConst4 * ((((0.239199802f * fTemp13) + (0.119398527f * fTemp14)) - ((0.0456056334f * fTemp11) + ((0.0451357104f * fTemp12) + (0.521048427f * fTemp15)))) + (fConst5 * (0.0f - ((fConst7 * fRec70[1]) + (fConst6 * fRec67[1]))))));
			fRec72[0] = (fRec72[1] + fTemp34);
			fRec70[0] = fRec72[0];
			float fRec71 = fTemp34;
			fRec69[0] = (fRec70[0] + fRec69[1]);
			fRec67[0] = fRec69[0];
			float fRec68 = fRec71;
			fVec2[(IOTA & 1023)] = ((fRec56 + (fRec65 + fRec68)) - (0.162584737f * fTemp26));
			output2[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec2[((IOTA - iConst14) & 1023)])));
			float fTemp35 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec79[1]) + (fConst9 * fRec76[1])))) + (fConst12 * ((((0.12556766f * fTemp21) + (0.147352323f * fTemp19)) + (0.0477927998f * fTemp20)) - ((((0.15440239f * fTemp17) + (0.0943210572f * fTemp18)) + (0.195854291f * fTemp22)) + (0.0181956291f * fTemp23))))));
			fRec81[0] = (fRec81[1] + fTemp35);
			fRec79[0] = fRec81[0];
			float fRec80 = fTemp35;
			fRec78[0] = (fRec79[0] + fRec78[1]);
			fRec76[0] = fRec78[0];
			float fRec77 = fRec80;
			float fTemp36 = (fConst13 * fRec73[1]);
			fRec75[0] = ((fRec77 + fRec75[1]) - fTemp36);
			fRec73[0] = fRec75[0];
			float fRec74 = (fRec77 - fTemp36);
			float fTemp37 = (fConst1 * ((((0.543890715f * fTemp8) + (0.00603322219f * fTemp9)) - (0.00173550518f * fTemp7)) - (fConst3 * fRec82[1])));
			fRec84[0] = (fRec84[1] + fTemp37);
			fRec82[0] = fRec84[0];
			float fRec83 = fTemp37;
			float fTemp38 = (fConst4 * ((((0.207265988f * fTemp13) + (0.055247739f * fTemp14)) - ((0.132714823f * fTemp11) + ((0.116406344f * fTemp12) + (0.52055335f * fTemp15)))) + (fConst5 * (0.0f - ((fConst7 * fRec88[1]) + (fConst6 * fRec85[1]))))));
			fRec90[0] = (fRec90[1] + fTemp38);
			fRec88[0] = fRec90[0];
			float fRec89 = fTemp38;
			fRec87[0] = (fRec88[0] + fRec87[1]);
			fRec85[0] = fRec87[0];
			float fRec86 = fRec89;
			fVec3[(IOTA & 1023)] = ((fRec74 + (fRec83 + fRec86)) - (0.162095413f * fTemp26));
			output3[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec3[((IOTA - iConst14) & 1023)])));
			float fTemp39 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec97[1]) + (fConst9 * fRec94[1])))) + (fConst12 * (((0.19211939f * fTemp21) + (0.145872176f * fTemp19)) - (((((0.0344753005f * fTemp17) + (0.0963652804f * fTemp18)) + (0.132543802f * fTemp22)) + (0.04091838f * fTemp20)) + (0.151883245f * fTemp23))))));
			fRec99[0] = (fRec99[1] + fTemp39);
			fRec97[0] = fRec99[0];
			float fRec98 = fTemp39;
			fRec96[0] = (fRec97[0] + fRec96[1]);
			fRec94[0] = fRec96[0];
			float fRec95 = fRec98;
			float fTemp40 = (fConst13 * fRec91[1]);
			fRec93[0] = ((fRec95 + fRec93[1]) - fTemp40);
			fRec91[0] = fRec93[0];
			float fRec92 = (fRec95 - fTemp40);
			float fTemp41 = (fConst1 * ((((0.541885078f * fTemp8) + (0.00227685785f * fTemp9)) - (0.00462430343f * fTemp7)) - (fConst3 * fRec100[1])));
			fRec102[0] = (fRec102[1] + fTemp41);
			fRec100[0] = fRec102[0];
			float fRec101 = fTemp41;
			float fTemp42 = (fConst4 * (((0.139248446f * fTemp13) - ((0.205175236f * fTemp11) + ((0.121027559f * fTemp12) + ((0.518802524f * fTemp15) + (0.047507707f * fTemp14))))) + (fConst5 * (0.0f - ((fConst7 * fRec106[1]) + (fConst6 * fRec103[1]))))));
			fRec108[0] = (fRec108[1] + fTemp42);
			fRec106[0] = fRec108[0];
			float fRec107 = fTemp42;
			fRec105[0] = (fRec106[0] + fRec105[1]);
			fRec103[0] = fRec105[0];
			float fRec104 = fRec107;
			fVec4[(IOTA & 1023)] = ((fRec92 + (fRec101 + fRec104)) - (0.160433933f * fTemp26));
			output4[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec4[((IOTA - iConst14) & 1023)])));
			float fTemp43 = (fConst8 * ((fConst12 * ((((0.126629189f * fTemp17) + (0.225720733f * fTemp21)) + (0.145284355f * fTemp19)) - ((((0.0413142703f * fTemp18) + (0.0487814955f * fTemp22)) + (0.102014035f * fTemp20)) + (0.0897749886f * fTemp23)))) + (fConst5 * (0.0f - ((fConst10 * fRec115[1]) + (fConst9 * fRec112[1]))))));
			fRec117[0] = (fRec117[1] + fTemp43);
			fRec115[0] = fRec117[0];
			float fRec116 = fTemp43;
			fRec114[0] = (fRec115[0] + fRec114[1]);
			fRec112[0] = fRec114[0];
			float fRec113 = fRec116;
			float fTemp44 = (fConst13 * fRec109[1]);
			fRec111[0] = ((fRec113 + fRec111[1]) - fTemp44);
			fRec109[0] = fRec111[0];
			float fRec110 = (fRec113 - fTemp44);
			float fTemp45 = (fConst1 * (((0.540891886f * fTemp8) - ((0.00764536019f * fTemp7) + (0.000176201604f * fTemp9))) - (fConst3 * fRec118[1])));
			fRec120[0] = (fRec120[1] + fTemp45);
			fRec118[0] = fRec120[0];
			float fRec119 = fTemp45;
			float fTemp46 = (fConst4 * (((0.0510658771f * fTemp13) - ((0.241598397f * fTemp11) + ((0.0516100787f * fTemp12) + ((0.518126667f * fTemp15) + (0.118012689f * fTemp14))))) + (fConst5 * (0.0f - ((fConst7 * fRec124[1]) + (fConst6 * fRec121[1]))))));
			fRec126[0] = (fRec126[1] + fTemp46);
			fRec124[0] = fRec126[0];
			float fRec125 = fTemp46;
			fRec123[0] = (fRec124[0] + fRec123[1]);
			fRec121[0] = fRec123[0];
			float fRec122 = fRec125;
			fVec5[(IOTA & 1023)] = ((fRec110 + (fRec119 + fRec122)) - (0.159572184f * fTemp26));
			output5[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec5[((IOTA - iConst14) & 1023)])));
			float fTemp47 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec133[1]) + (fConst9 * fRec130[1])))) + (fConst12 * (((((((0.12890467f * fTemp17) + (0.039527487f * fTemp18)) + (0.226716429f * fTemp21)) + (0.146422267f * fTemp19)) + (0.047230348f * fTemp22)) + (0.0886498168f * fTemp23)) - (0.102676965f * fTemp20)))));
			fRec135[0] = (fRec135[1] + fTemp47);
			fRec133[0] = fRec135[0];
			float fRec134 = fTemp47;
			fRec132[0] = (fRec133[0] + fRec132[1]);
			fRec130[0] = fRec132[0];
			float fRec131 = fRec134;
			float fTemp48 = (fConst13 * fRec127[1]);
			fRec129[0] = ((fRec131 + fRec129[1]) - fTemp48);
			fRec127[0] = fRec129[0];
			float fRec128 = (fRec131 - fTemp48);
			float fTemp49 = (fConst1 * (((0.542715728f * fTemp8) - ((0.00815920997f * fTemp7) + (0.000982502243f * fTemp9))) - (fConst3 * fRec136[1])));
			fRec138[0] = (fRec138[1] + fTemp49);
			fRec136[0] = fRec138[0];
			float fRec137 = fTemp49;
			float fTemp50 = (fConst4 * (((0.0517803133f * fTemp12) - ((0.240908772f * fTemp11) + (((0.519915104f * fTemp15) + (0.0492548868f * fTemp13)) + (0.118712977f * fTemp14)))) + (fConst5 * (0.0f - ((fConst7 * fRec142[1]) + (fConst6 * fRec139[1]))))));
			fRec144[0] = (fRec144[1] + fTemp50);
			fRec142[0] = fRec144[0];
			float fRec143 = fTemp50;
			fRec141[0] = (fRec142[0] + fRec141[1]);
			fRec139[0] = fRec141[0];
			float fRec140 = fRec143;
			fVec6[(IOTA & 1023)] = ((fRec128 + (fRec137 + fRec140)) - (0.160738289f * fTemp26));
			output6[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec6[((IOTA - iConst14) & 1023)])));
			float fTemp51 = (fConst4 * (((0.121841468f * fTemp12) - ((0.201858163f * fTemp11) + (((0.523391128f * fTemp15) + (0.140298232f * fTemp13)) + (0.0458520763f * fTemp14)))) + (fConst5 * (0.0f - ((fConst7 * fRec148[1]) + (fConst6 * fRec145[1]))))));
			fRec150[0] = (fRec150[1] + fTemp51);
			fRec148[0] = fRec150[0];
			float fRec149 = fTemp51;
			fRec147[0] = (fRec148[0] + fRec147[1]);
			fRec145[0] = fRec147[0];
			float fRec146 = fRec149;
			float fTemp52 = (fConst1 * (((0.546260059f * fTemp8) - ((0.00504400767f * fTemp7) + (0.0018301364f * fTemp9))) - (fConst3 * fRec151[1])));
			fRec153[0] = (fRec153[1] + fTemp52);
			fRec151[0] = fRec153[0];
			float fRec152 = fTemp52;
			float fTemp53 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec160[1]) + (fConst9 * fRec157[1])))) + (fConst12 * ((((((0.0954369605f * fTemp18) + (0.192347899f * fTemp21)) + (0.148993686f * fTemp19)) + (0.134090915f * fTemp22)) + (0.151926577f * fTemp23)) - ((0.0369079039f * fTemp17) + (0.0395361409f * fTemp20))))));
			fRec162[0] = (fRec162[1] + fTemp53);
			fRec160[0] = fRec162[0];
			float fRec161 = fTemp53;
			fRec159[0] = (fRec160[0] + fRec159[1]);
			fRec157[0] = fRec159[0];
			float fRec158 = fRec161;
			float fTemp54 = (fConst13 * fRec154[1]);
			fRec156[0] = ((fRec158 + fRec156[1]) - fTemp54);
			fRec154[0] = fRec156[0];
			float fRec155 = (fRec158 - fTemp54);
			fVec7[(IOTA & 1023)] = ((fRec146 + (fRec152 + fRec155)) - (0.163303062f * fTemp26));
			output7[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec7[((IOTA - iConst14) & 1023)])));
			float fTemp55 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec169[1]) + (fConst9 * fRec166[1])))) + (fConst12 * (((((((0.0922770798f * fTemp18) + (0.12642622f * fTemp21)) + (0.151286989f * fTemp19)) + (0.195434213f * fTemp22)) + (0.0463965759f * fTemp20)) + (0.0193524454f * fTemp23)) - (0.151836678f * fTemp17)))));
			fRec171[0] = (fRec171[1] + fTemp55);
			fRec169[0] = fRec171[0];
			float fRec170 = fTemp55;
			fRec168[0] = (fRec169[0] + fRec168[1]);
			fRec166[0] = fRec168[0];
			float fRec167 = fRec170;
			float fTemp56 = (fConst13 * fRec163[1]);
			fRec165[0] = ((fRec167 + fRec165[1]) - fTemp56);
			fRec163[0] = fRec165[0];
			float fRec164 = (fRec167 - fTemp56);
			float fTemp57 = (fConst1 * (((0.547890782f * fTemp8) - ((0.000823044975f * fTemp7) + (0.00411263434f * fTemp9))) - (fConst3 * fRec172[1])));
			fRec174[0] = (fRec174[1] + fTemp57);
			fRec172[0] = fRec174[0];
			float fRec173 = fTemp57;
			float fTemp58 = (fConst4 * ((((0.114729911f * fTemp12) + (0.0536742099f * fTemp14)) - ((0.131591365f * fTemp11) + ((0.525515556f * fTemp15) + (0.205110282f * fTemp13)))) + (fConst5 * (0.0f - ((fConst7 * fRec178[1]) + (fConst6 * fRec175[1]))))));
			fRec180[0] = (fRec180[1] + fTemp58);
			fRec178[0] = fRec180[0];
			float fRec179 = fTemp58;
			fRec177[0] = (fRec178[0] + fRec177[1]);
			fRec175[0] = fRec177[0];
			float fRec176 = fRec179;
			fVec8[(IOTA & 1023)] = ((fRec164 + (fRec173 + fRec176)) - (0.164989024f * fTemp26));
			output8[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec8[((IOTA - iConst14) & 1023)])));
			float fTemp59 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec187[1]) + (fConst9 * fRec184[1])))) + (fConst12 * ((((((0.0387924835f * fTemp18) + (0.0455331244f * fTemp21)) + (0.15152736f * fTemp19)) + (0.22376959f * fTemp22)) + (0.100365862f * fTemp20)) - ((0.0816515461f * fTemp17) + (0.128871605f * fTemp23))))));
			fRec189[0] = (fRec189[1] + fTemp59);
			fRec187[0] = fRec189[0];
			float fRec188 = fTemp59;
			fRec186[0] = (fRec187[0] + fRec186[1]);
			fRec184[0] = fRec186[0];
			float fRec185 = fRec188;
			float fTemp60 = (fConst13 * fRec181[1]);
			fRec183[0] = ((fRec185 + fRec183[1]) - fTemp60);
			fRec181[0] = fRec183[0];
			float fRec182 = (fRec185 - fTemp60);
			float fTemp61 = (fConst1 * ((((0.00139717327f * fTemp7) + (0.545374036f * fTemp8)) - (0.00654617557f * fTemp9)) - (fConst3 * fRec190[1])));
			fRec192[0] = (fRec192[1] + fTemp61);
			fRec190[0] = fRec192[0];
			float fRec191 = fTemp61;
			float fTemp62 = (fConst4 * ((((0.0451242886f * fTemp12) + (0.116969563f * fTemp14)) - ((0.0479032844f * fTemp11) + ((0.523845017f * fTemp15) + (0.23517783f * fTemp13)))) + (fConst5 * (0.0f - ((fConst7 * fRec196[1]) + (fConst6 * fRec193[1]))))));
			fRec198[0] = (fRec198[1] + fTemp62);
			fRec196[0] = fRec198[0];
			float fRec197 = fTemp62;
			fRec195[0] = (fRec196[0] + fRec195[1]);
			fRec193[0] = fRec195[0];
			float fRec194 = fRec197;
			fVec9[(IOTA & 1023)] = ((fRec182 + (fRec191 + fRec194)) - (0.164312586f * fTemp26));
			output9[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec9[((IOTA - iConst14) & 1023)])));
			float fTemp63 = (fConst1 * ((((0.00163474865f * fTemp7) + (0.538768351f * fTemp8)) - (0.00726868212f * fTemp9)) - (fConst3 * fRec199[1])));
			fRec201[0] = (fRec201[1] + fTemp63);
			fRec199[0] = fRec201[0];
			float fRec200 = fTemp63;
			float fTemp64 = (fConst4 * ((((0.0496484861f * fTemp11) + (0.115810938f * fTemp14)) - ((0.0537721217f * fTemp12) + ((0.517728806f * fTemp15) + (0.233157828f * fTemp13)))) + (fConst5 * (0.0f - ((fConst7 * fRec205[1]) + (fConst6 * fRec202[1]))))));
			fRec207[0] = (fRec207[1] + fTemp64);
			fRec205[0] = fRec207[0];
			float fRec206 = fTemp64;
			fRec204[0] = (fRec205[0] + fRec204[1]);
			fRec202[0] = fRec204[0];
			float fRec203 = fRec206;
			float fTemp65 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec214[1]) + (fConst9 * fRec211[1])))) + (fConst12 * (((((0.092654787f * fTemp17) + (0.149029166f * fTemp19)) + (0.221937165f * fTemp22)) + (0.0980903432f * fTemp20)) - (((0.0411720648f * fTemp18) + (0.048638396f * fTemp21)) + (0.124471173f * fTemp23))))));
			fRec216[0] = (fRec216[1] + fTemp65);
			fRec214[0] = fRec216[0];
			float fRec215 = fTemp65;
			fRec213[0] = (fRec214[0] + fRec213[1]);
			fRec211[0] = fRec213[0];
			float fRec212 = fRec215;
			float fTemp66 = (fConst13 * fRec208[1]);
			fRec210[0] = ((fRec212 + fRec210[1]) - fTemp66);
			fRec208[0] = fRec210[0];
			float fRec209 = (fRec212 - fTemp66);
			fVec10[(IOTA & 1023)] = ((fRec200 + (fRec203 + fRec209)) - (0.161364496f * fTemp26));
			output10[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec10[((IOTA - iConst14) & 1023)])));
			float fTemp67 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec223[1]) + (fConst9 * fRec220[1])))) + (fConst12 * ((((((0.150575548f * fTemp17) + (0.144834518f * fTemp19)) + (0.188587695f * fTemp22)) + (0.0381134376f * fTemp20)) + (0.0330215096f * fTemp23)) - ((0.095505707f * fTemp18) + (0.129729182f * fTemp21))))));
			fRec225[0] = (fRec225[1] + fTemp67);
			fRec223[0] = fRec225[0];
			float fRec224 = fTemp67;
			fRec222[0] = (fRec223[0] + fRec222[1]);
			fRec220[0] = fRec222[0];
			float fRec221 = fRec224;
			float fTemp68 = (fConst13 * fRec217[1]);
			fRec219[0] = ((fRec221 + fRec219[1]) - fTemp68);
			fRec217[0] = fRec219[0];
			float fRec218 = (fRec221 - fTemp68);
			float fTemp69 = (fConst1 * ((((0.0018944504f * fTemp7) + (0.531518579f * fTemp8)) - (0.00529586384f * fTemp9)) - (fConst3 * fRec226[1])));
			fRec228[0] = (fRec228[1] + fTemp69);
			fRec226[0] = fRec228[0];
			float fRec227 = fTemp69;
			float fTemp70 = (fConst4 * ((((0.135999829f * fTemp11) + (0.047368031f * fTemp14)) - ((0.117280409f * fTemp12) + ((0.509904742f * fTemp15) + (0.198022977f * fTemp13)))) + (fConst5 * (0.0f - ((fConst7 * fRec232[1]) + (fConst6 * fRec229[1]))))));
			fRec234[0] = (fRec234[1] + fTemp70);
			fRec232[0] = fRec234[0];
			float fRec233 = fTemp70;
			fRec231[0] = (fRec232[0] + fRec231[1]);
			fRec229[0] = fRec231[0];
			float fRec230 = fRec233;
			fVec11[(IOTA & 1023)] = ((fRec218 + (fRec227 + fRec230)) - (0.157904744f * fTemp26));
			output11[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec11[((IOTA - iConst14) & 1023)])));
			float fTemp71 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec241[1]) + (fConst9 * fRec238[1])))) + (fConst12 * (((((0.0301209819f * fTemp17) + (0.140951097f * fTemp19)) + (0.128035471f * fTemp22)) + (0.148680195f * fTemp23)) - (((0.0957592353f * fTemp18) + (0.188256785f * fTemp21)) + (0.0429701135f * fTemp20))))));
			fRec243[0] = (fRec243[1] + fTemp71);
			fRec241[0] = fRec243[0];
			float fRec242 = fTemp71;
			fRec240[0] = (fRec241[0] + fRec240[1]);
			fRec238[0] = fRec240[0];
			float fRec239 = fRec242;
			float fTemp72 = (fConst13 * fRec235[1]);
			fRec237[0] = ((fRec239 + fRec237[1]) - fTemp72);
			fRec235[0] = fRec237[0];
			float fRec236 = (fRec239 - fTemp72);
			float fTemp73 = (fConst1 * ((((0.00391753204f * fTemp7) + (0.526567936f * fTemp8)) - (0.00229139649f * fTemp9)) - (fConst3 * fRec244[1])));
			fRec246[0] = (fRec246[1] + fTemp73);
			fRec244[0] = fRec246[0];
			float fRec245 = fTemp73;
			float fTemp74 = (fConst4 * (((0.200671598f * fTemp11) - ((0.114537328f * fTemp12) + (((0.503743231f * fTemp15) + (0.134846017f * fTemp13)) + (0.0467584655f * fTemp14)))) + (fConst5 * (0.0f - ((fConst7 * fRec250[1]) + (fConst6 * fRec247[1]))))));
			fRec252[0] = (fRec252[1] + fTemp74);
			fRec250[0] = fRec252[0];
			float fRec251 = fTemp74;
			fRec249[0] = (fRec250[0] + fRec249[1]);
			fRec247[0] = fRec249[0];
			float fRec248 = fRec251;
			fVec12[(IOTA & 1023)] = ((fRec236 + (fRec245 + fRec248)) - (0.155424982f * fTemp26));
			output12[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec12[((IOTA - iConst14) & 1023)])));
			float fTemp75 = (fConst8 * ((fConst12 * ((((0.139085248f * fTemp19) + (0.0498912893f * fTemp22)) + (0.0924032852f * fTemp23)) - ((((0.122209214f * fTemp17) + (0.0444297157f * fTemp18)) + (0.219119027f * fTemp21)) + (0.099716641f * fTemp20)))) + (fConst5 * (0.0f - ((fConst10 * fRec259[1]) + (fConst9 * fRec256[1]))))));
			fRec261[0] = (fRec261[1] + fTemp75);
			fRec259[0] = fRec261[0];
			float fRec260 = fTemp75;
			fRec258[0] = (fRec259[0] + fRec258[1]);
			fRec256[0] = fRec258[0];
			float fRec257 = fRec260;
			float fTemp76 = (fConst13 * fRec253[1]);
			fRec255[0] = ((fRec257 + fRec255[1]) - fTemp76);
			fRec253[0] = fRec255[0];
			float fRec254 = (fRec257 - fTemp76);
			float fTemp77 = (fConst1 * ((((0.00676348526f * fTemp7) + (0.525141418f * fTemp8)) - (0.000270051591f * fTemp9)) - (fConst3 * fRec262[1])));
			fRec264[0] = (fRec264[1] + fTemp77);
			fRec262[0] = fRec264[0];
			float fRec263 = fTemp77;
			float fTemp78 = (fConst4 * (((0.235527381f * fTemp11) - ((0.0519268923f * fTemp12) + (((0.501509845f * fTemp15) + (0.0534632653f * fTemp13)) + (0.113704555f * fTemp14)))) + (fConst5 * (0.0f - ((fConst7 * fRec268[1]) + (fConst6 * fRec265[1]))))));
			fRec270[0] = (fRec270[1] + fTemp78);
			fRec268[0] = fRec270[0];
			float fRec269 = fTemp78;
			fRec267[0] = (fRec268[0] + fRec267[1]);
			fRec265[0] = fRec267[0];
			float fRec266 = fRec269;
			fVec13[(IOTA & 1023)] = ((fRec254 + (fRec263 + fRec266)) - (0.154474169f * fTemp26));
			output13[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec13[((IOTA - iConst14) & 1023)])));
			float fTemp79 = (fConst4 * ((((0.237984449f * fTemp11) + ((0.0442009978f * fTemp12) + (0.0436796881f * fTemp13))) - ((0.503581941f * fTemp15) + (0.11909382f * fTemp14))) + (fConst5 * (0.0f - ((fConst7 * fRec274[1]) + (fConst6 * fRec271[1]))))));
			fRec276[0] = (fRec276[1] + fTemp79);
			fRec274[0] = fRec276[0];
			float fRec275 = fTemp79;
			fRec273[0] = (fRec274[0] + fRec273[1]);
			fRec271[0] = fRec273[0];
			float fRec272 = fRec275;
			float fTemp80 = (fConst1 * ((((0.00818715245f * fTemp7) + (0.526983678f * fTemp8)) + (0.000602109008f * fTemp9)) - (fConst3 * fRec277[1])));
			fRec279[0] = (fRec279[1] + fTemp80);
			fRec277[0] = fRec279[0];
			float fRec278 = fTemp80;
			float fTemp81 = (fConst8 * ((fConst12 * (((0.0365918167f * fTemp18) + (0.139784902f * fTemp19)) - (((((0.133381367f * fTemp17) + (0.221757427f * fTemp21)) + (0.0426270366f * fTemp22)) + (0.103153683f * fTemp20)) + (0.0794780999f * fTemp23)))) + (fConst5 * (0.0f - ((fConst10 * fRec286[1]) + (fConst9 * fRec283[1]))))));
			fRec288[0] = (fRec288[1] + fTemp81);
			fRec286[0] = fRec288[0];
			float fRec287 = fTemp81;
			fRec285[0] = (fRec286[0] + fRec285[1]);
			fRec283[0] = fRec285[0];
			float fRec284 = fRec287;
			float fTemp82 = (fConst13 * fRec280[1]);
			fRec282[0] = ((fRec284 + fRec282[1]) - fTemp82);
			fRec280[0] = fRec282[0];
			float fRec281 = (fRec284 - fTemp82);
			fVec14[(IOTA & 1023)] = ((fRec272 + (fRec278 + fRec281)) - (0.154907823f * fTemp26));
			output14[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec14[((IOTA - iConst14) & 1023)])));
			float fTemp83 = (fConst4 * ((((0.205777392f * fTemp11) + ((0.11363674f * fTemp12) + (0.131216615f * fTemp13))) - ((0.50854522f * fTemp15) + (0.0558036827f * fTemp14))) + (fConst5 * (0.0f - ((fConst7 * fRec292[1]) + (fConst6 * fRec289[1]))))));
			fRec294[0] = (fRec294[1] + fTemp83);
			fRec292[0] = fRec294[0];
			float fRec293 = fTemp83;
			fRec291[0] = (fRec292[0] + fRec291[1]);
			fRec289[0] = fRec291[0];
			float fRec290 = fRec293;
			float fTemp84 = (fConst1 * ((((0.00655668043f * fTemp7) + (0.531031311f * fTemp8)) + (0.00167262775f * fTemp9)) - (fConst3 * fRec295[1])));
			fRec297[0] = (fRec297[1] + fTemp84);
			fRec295[0] = fRec297[0];
			float fRec296 = fTemp84;
			float fTemp85 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec304[1]) + (fConst9 * fRec301[1])))) + (fConst12 * ((((0.0170657709f * fTemp17) + (0.0948601961f * fTemp18)) + (0.1423949f * fTemp19)) - ((((0.193457514f * fTemp21) + (0.124669485f * fTemp22)) + (0.0480135232f * fTemp20)) + (0.153761491f * fTemp23))))));
			fRec306[0] = (fRec306[1] + fTemp85);
			fRec304[0] = fRec306[0];
			float fRec305 = fTemp85;
			fRec303[0] = (fRec304[0] + fRec303[1]);
			fRec301[0] = fRec303[0];
			float fRec302 = fRec305;
			float fTemp86 = (fConst13 * fRec298[1]);
			fRec300[0] = ((fRec302 + fRec300[1]) - fTemp86);
			fRec298[0] = fRec300[0];
			float fRec299 = (fRec302 - fTemp86);
			fVec15[(IOTA & 1023)] = ((fRec290 + (fRec296 + fRec299)) - (0.156453952f * fTemp26));
			output15[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec15[((IOTA - iConst14) & 1023)])));
			float fTemp87 = (fConst15 * ((fConst17 * (((((((0.0849887803f * fTemp17) + (0.20637688f * fTemp18)) + (0.0474371314f * fTemp21)) + (0.123034433f * fTemp22)) + (0.21774739f * fTemp20)) + (0.0374729969f * fTemp23)) - (0.409563184f * fTemp19))) + (fConst5 * (0.0f - ((fConst19 * fRec313[1]) + (fConst18 * fRec310[1]))))));
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
			float fTemp89 = (fConst21 * ((((0.0414057933f * fTemp7) + (0.10622099f * fTemp9)) - (0.51724577f * fTemp8)) - (fConst22 * fRec316[1])));
			fRec318[0] = (fRec318[1] + fTemp89);
			fRec316[0] = fRec318[0];
			float fRec317 = fTemp89;
			float fTemp90 = (fConst23 * (((0.0834310502f * fTemp11) + ((0.0272547938f * fTemp12) + (((0.620109618f * fTemp15) + (0.193166018f * fTemp13)) + (0.0258422904f * fTemp14)))) + (fConst5 * (0.0f - ((fConst25 * fRec322[1]) + (fConst24 * fRec319[1]))))));
			fRec324[0] = (fRec324[1] + fTemp90);
			fRec322[0] = fRec324[0];
			float fRec323 = fTemp90;
			fRec321[0] = (fRec322[0] + fRec321[1]);
			fRec319[0] = fRec321[0];
			float fRec320 = fRec323;
			fVec16[(IOTA & 511)] = ((0.349964797f * fTemp26) + (fRec308 + (fRec317 + fRec320)));
			output16[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec16[((IOTA - iConst26) & 511)])));
			float fTemp91 = (fConst15 * ((fConst5 * (0.0f - ((fConst19 * fRec331[1]) + (fConst18 * fRec328[1])))) + (fConst17 * ((((0.121108972f * fTemp22) + (0.21483101f * fTemp20)) + (0.0346229002f * fTemp23)) - ((((0.0864849389f * fTemp17) + (0.212617636f * fTemp18)) + (0.0509614833f * fTemp21)) + (0.411242932f * fTemp19))))));
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
			float fTemp93 = (fConst21 * (((0.105975017f * fTemp9) - ((0.0446815975f * fTemp7) + (0.518460333f * fTemp8))) - (fConst22 * fRec334[1])));
			fRec336[0] = (fRec336[1] + fTemp93);
			fRec334[0] = fRec336[0];
			float fRec335 = fTemp93;
			float fTemp94 = (fConst23 * (((((0.622229993f * fTemp15) + (0.19364439f * fTemp13)) + (0.0252974126f * fTemp14)) - ((0.0270787384f * fTemp12) + (0.0819328129f * fTemp11))) + (fConst5 * (0.0f - ((fConst25 * fRec340[1]) + (fConst24 * fRec337[1]))))));
			fRec342[0] = (fRec342[1] + fTemp94);
			fRec340[0] = fRec342[0];
			float fRec341 = fTemp94;
			fRec339[0] = (fRec340[0] + fRec339[1]);
			fRec337[0] = fRec339[0];
			float fRec338 = fRec341;
			fVec17[(IOTA & 511)] = ((0.350594461f * fTemp26) + (fRec326 + (fRec335 + fRec338)));
			output17[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec17[((IOTA - iConst26) & 511)])));
			float fTemp95 = (fConst21 * (((0.0400109254f * fTemp9) - ((0.106243543f * fTemp7) + (0.526147187f * fTemp8))) - (fConst22 * fRec343[1])));
			fRec345[0] = (fRec345[1] + fTemp95);
			fRec343[0] = fRec345[0];
			float fRec344 = fTemp95;
			float fTemp96 = (fConst23 * ((((0.630343974f * fTemp15) + (0.076293245f * fTemp13)) - ((0.200104281f * fTemp11) + ((0.0262939148f * fTemp12) + (0.0271750968f * fTemp14)))) + (fConst5 * (0.0f - ((fConst25 * fRec349[1]) + (fConst24 * fRec346[1]))))));
			fRec351[0] = (fRec351[1] + fTemp96);
			fRec349[0] = fRec351[0];
			float fRec350 = fTemp96;
			fRec348[0] = (fRec349[0] + fRec348[1]);
			fRec346[0] = fRec348[0];
			float fRec347 = fRec350;
			float fTemp97 = (fConst15 * ((fConst17 * (((0.0438687578f * fTemp17) + (0.0456842855f * fTemp22)) - (((((0.197824776f * fTemp18) + (0.121757738f * fTemp21)) + (0.416832f * fTemp19)) + (0.232077494f * fTemp20)) + (0.0828533769f * fTemp23)))) + (fConst5 * (0.0f - ((fConst19 * fRec358[1]) + (fConst18 * fRec355[1]))))));
			fRec360[0] = (fRec360[1] + fTemp97);
			fRec358[0] = fRec360[0];
			float fRec359 = fTemp97;
			fRec357[0] = (fRec358[0] + fRec357[1]);
			fRec355[0] = fRec357[0];
			float fRec356 = fRec359;
			float fTemp98 = (fConst20 * fRec352[1]);
			fRec354[0] = ((fRec356 + fRec354[1]) - fTemp98);
			fRec352[0] = fRec354[0];
			float fRec353 = (fRec356 - fTemp98);
			fVec18[(IOTA & 511)] = ((0.355321735f * fTemp26) + (fRec344 + (fRec347 + fRec353)));
			output18[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec18[((IOTA - iConst26) & 511)])));
			float fTemp99 = (fConst15 * ((fConst5 * (0.0f - ((fConst19 * fRec367[1]) + (fConst18 * fRec364[1])))) + (fConst17 * ((((0.0244791918f * fTemp17) + (0.225795478f * fTemp18)) + (0.0903535187f * fTemp23)) - ((((0.116895519f * fTemp21) + (0.407577753f * fTemp19)) + (0.0527625345f * fTemp22)) + (0.199404612f * fTemp20))))));
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
			float fTemp101 = (fConst21 * ((0.0f - (((0.103312783f * fTemp7) + (0.510956287f * fTemp8)) + (0.047063943f * fTemp9))) - (fConst22 * fRec370[1])));
			fRec372[0] = (fRec372[1] + fTemp101);
			fRec370[0] = fRec372[0];
			float fRec371 = fTemp101;
			float fTemp102 = (fConst23 * ((((0.0308974143f * fTemp12) + (0.614435315f * fTemp15)) - ((0.189313427f * fTemp11) + ((0.0899212509f * fTemp13) + (0.0226607043f * fTemp14)))) + (fConst5 * (0.0f - ((fConst25 * fRec376[1]) + (fConst24 * fRec373[1]))))));
			fRec378[0] = (fRec378[1] + fTemp102);
			fRec376[0] = fRec378[0];
			float fRec377 = fTemp102;
			fRec375[0] = (fRec376[0] + fRec375[1]);
			fRec373[0] = fRec375[0];
			float fRec374 = fRec377;
			fVec19[(IOTA & 511)] = ((0.347188592f * fTemp26) + (fRec362 + (fRec371 + fRec374)));
			output19[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec19[((IOTA - iConst26) & 511)])));
			float fTemp103 = (fConst15 * ((fConst5 * (0.0f - ((fConst19 * fRec385[1]) + (fConst18 * fRec382[1])))) + (fConst17 * (((0.195052356f * fTemp18) + (0.221818238f * fTemp20)) - (((((0.0812706053f * fTemp17) + (0.0470186695f * fTemp21)) + (0.394993544f * fTemp19)) + (0.119730249f * fTemp22)) + (0.0414738841f * fTemp23))))));
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
			float fTemp105 = (fConst21 * ((0.0f - (((0.0407508686f * fTemp7) + (0.494837821f * fTemp8)) + (0.104406685f * fTemp9))) - (fConst22 * fRec388[1])));
			fRec390[0] = (fRec390[1] + fTemp105);
			fRec388[0] = fRec390[0];
			float fRec389 = fTemp105;
			float fTemp106 = (fConst23 * ((((0.0248900317f * fTemp12) + ((0.596006334f * fTemp15) + (0.0263619702f * fTemp14))) - ((0.0727427602f * fTemp11) + (0.189435437f * fTemp13))) + (fConst5 * (0.0f - ((fConst25 * fRec394[1]) + (fConst24 * fRec391[1]))))));
			fRec396[0] = (fRec396[1] + fTemp106);
			fRec394[0] = fRec396[0];
			float fRec395 = fTemp106;
			fRec393[0] = (fRec394[0] + fRec393[1]);
			fRec391[0] = fRec393[0];
			float fRec392 = fRec395;
			fVec20[(IOTA & 511)] = ((0.337708086f * fTemp26) + (fRec380 + (fRec389 + fRec392)));
			output20[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec20[((IOTA - iConst26) & 511)])));
			float fTemp107 = (fConst15 * ((fConst5 * (0.0f - ((fConst19 * fRec403[1]) + (fConst18 * fRec400[1])))) + (fConst17 * ((((0.0818223134f * fTemp17) + (0.0457343757f * fTemp21)) + (0.223201424f * fTemp20)) - ((((0.196909457f * fTemp18) + (0.399513394f * fTemp19)) + (0.12169227f * fTemp22)) + (0.0424832329f * fTemp23))))));
			fRec405[0] = (fRec405[1] + fTemp107);
			fRec403[0] = fRec405[0];
			float fRec404 = fTemp107;
			fRec402[0] = (fRec403[0] + fRec402[1]);
			fRec400[0] = fRec402[0];
			float fRec401 = fRec404;
			float fTemp108 = (fConst20 * fRec397[1]);
			fRec399[0] = ((fRec401 + fRec399[1]) - fTemp108);
			fRec397[0] = fRec399[0];
			float fRec398 = (fRec401 - fTemp108);
			float fTemp109 = (fConst21 * (((0.0400022864f * fTemp7) - ((0.506499469f * fTemp8) + (0.105930291f * fTemp9))) - (fConst22 * fRec406[1])));
			fRec408[0] = (fRec408[1] + fTemp109);
			fRec406[0] = fRec408[0];
			float fRec407 = fTemp109;
			float fTemp110 = (fConst23 * ((((0.0755914077f * fTemp11) + ((0.606704056f * fTemp15) + (0.0267274603f * fTemp14))) - ((0.0255542267f * fTemp12) + (0.187560409f * fTemp13))) + (fConst5 * (0.0f - ((fConst25 * fRec412[1]) + (fConst24 * fRec409[1]))))));
			fRec414[0] = (fRec414[1] + fTemp110);
			fRec412[0] = fRec414[0];
			float fRec413 = fTemp110;
			fRec411[0] = (fRec412[0] + fRec411[1]);
			fRec409[0] = fRec411[0];
			float fRec410 = fRec413;
			fVec21[(IOTA & 511)] = ((0.343118697f * fTemp26) + (fRec398 + (fRec407 + fRec410)));
			output21[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec21[((IOTA - iConst26) & 511)])));
			float fTemp111 = (fConst15 * ((fConst5 * (0.0f - ((fConst19 * fRec421[1]) + (fConst18 * fRec418[1])))) + (fConst17 * (((0.122866087f * fTemp21) + (0.0877754018f * fTemp23)) - (((((0.02781507f * fTemp17) + (0.220973104f * fTemp18)) + (0.414806515f * fTemp19)) + (0.0537453778f * fTemp22)) + (0.203984052f * fTemp20))))));
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
			float fTemp113 = (fConst21 * (((0.104782425f * fTemp7) - ((0.529045105f * fTemp8) + (0.0464244634f * fTemp9))) - (fConst22 * fRec424[1])));
			fRec426[0] = (fRec426[1] + fTemp113);
			fRec424[0] = fRec426[0];
			float fRec425 = fTemp113;
			float fTemp114 = (fConst23 * ((((0.186308503f * fTemp11) + (0.631829798f * fTemp15)) - ((0.0273393132f * fTemp12) + ((0.0853402913f * fTemp13) + (0.0230241232f * fTemp14)))) + (fConst5 * (0.0f - ((fConst25 * fRec430[1]) + (fConst24 * fRec427[1]))))));
			fRec432[0] = (fRec432[1] + fTemp114);
			fRec430[0] = fRec432[0];
			float fRec431 = fTemp114;
			fRec429[0] = (fRec430[0] + fRec429[1]);
			fRec427[0] = fRec429[0];
			float fRec428 = fRec431;
			fVec22[(IOTA & 511)] = ((0.354980856f * fTemp26) + (fRec416 + (fRec425 + fRec428)));
			output22[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec22[((IOTA - iConst26) & 511)])));
			float fTemp115 = (fConst15 * ((fConst5 * (0.0f - ((fConst19 * fRec439[1]) + (fConst18 * fRec436[1])))) + (fConst17 * ((((0.205405548f * fTemp18) + (0.124467656f * fTemp21)) + (0.0481899753f * fTemp22)) - ((((0.0396388732f * fTemp17) + (0.417271554f * fTemp19)) + (0.225248098f * fTemp20)) + (0.0843508095f * fTemp23))))));
			fRec441[0] = (fRec441[1] + fTemp115);
			fRec439[0] = fRec441[0];
			float fRec440 = fTemp115;
			fRec438[0] = (fRec439[0] + fRec438[1]);
			fRec436[0] = fRec438[0];
			float fRec437 = fRec440;
			float fTemp116 = (fConst20 * fRec433[1]);
			fRec435[0] = ((fRec437 + fRec435[1]) - fTemp116);
			fRec433[0] = fRec435[0];
			float fRec434 = (fRec437 - fTemp116);
			float fTemp117 = (fConst21 * ((((0.107887007f * fTemp7) + (0.0421818942f * fTemp9)) - (0.530113637f * fTemp8)) - (fConst22 * fRec442[1])));
			fRec444[0] = (fRec444[1] + fTemp117);
			fRec442[0] = fRec444[0];
			float fRec443 = fTemp117;
			float fTemp118 = (fConst23 * ((((0.193337142f * fTemp11) + ((0.0251681805f * fTemp12) + ((0.633770227f * fTemp15) + (0.0775489584f * fTemp13)))) - (0.0262388736f * fTemp14)) + (fConst5 * (0.0f - ((fConst25 * fRec448[1]) + (fConst24 * fRec445[1]))))));
			fRec450[0] = (fRec450[1] + fTemp118);
			fRec448[0] = fRec450[0];
			float fRec449 = fTemp118;
			fRec447[0] = (fRec448[0] + fRec447[1]);
			fRec445[0] = fRec447[0];
			float fRec446 = fRec449;
			fVec23[(IOTA & 511)] = ((0.356408775f * fTemp26) + (fRec434 + (fRec443 + fRec446)));
			output23[i] = FAUSTFLOAT((0.875537992f * (fRec0[0] * fVec23[((IOTA - iConst26) & 511)])));
			float fTemp119 = (fConst27 * ((fConst29 * (((((((0.00376295694f * fTemp17) + (0.0996614993f * fTemp18)) + (0.371659219f * fTemp21)) + (0.178527281f * fTemp19)) + (0.371169925f * fTemp22)) + (0.000124218306f * fTemp20)) - (0.00385668245f * fTemp23))) + (fConst5 * (0.0f - ((fConst31 * fRec457[1]) + (fConst30 * fRec454[1]))))));
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
			float fTemp121 = (fConst33 * ((((0.198458537f * fTemp7) + (0.196300924f * fTemp8)) + (0.198337048f * fTemp9)) - (fConst34 * fRec460[1])));
			fRec462[0] = (fRec462[1] + fTemp121);
			fRec460[0] = fRec462[0];
			float fRec461 = fTemp121;
			float fTemp122 = (fConst35 * (((0.0894538015f * fTemp15) - ((0.119087845f * fTemp11) + ((0.00338083855f * fTemp12) + ((0.121682182f * fTemp13) + (0.000178258502f * fTemp14))))) + (fConst5 * (0.0f - ((fConst37 * fRec466[1]) + (fConst36 * fRec463[1]))))));
			fRec468[0] = (fRec468[1] + fTemp122);
			fRec466[0] = fRec468[0];
			float fRec467 = fTemp122;
			fRec465[0] = (fRec466[0] + fRec465[1]);
			fRec463[0] = fRec465[0];
			float fRec464 = fRec467;
			fVec24[(IOTA & 255)] = ((0.0681516528f * fTemp26) + (fRec452 + (fRec461 + fRec464)));
			output24[i] = FAUSTFLOAT((0.953550935f * (fRec0[0] * fVec24[((IOTA - iConst38) & 255)])));
			float fTemp123 = (fConst35 * ((((0.118888423f * fTemp11) + ((0.00345011009f * fTemp12) + (0.100990638f * fTemp15))) - ((0.120080367f * fTemp13) + (6.1880899e-05f * fTemp14))) + (fConst5 * (0.0f - ((fConst37 * fRec472[1]) + (fConst36 * fRec469[1]))))));
			fRec474[0] = (fRec474[1] + fTemp123);
			fRec472[0] = fRec474[0];
			float fRec473 = fTemp123;
			fRec471[0] = (fRec472[0] + fRec471[1]);
			fRec469[0] = fRec471[0];
			float fRec470 = fRec473;
			float fTemp124 = (fConst33 * ((((0.183836982f * fTemp8) + (0.197894111f * fTemp9)) - (0.198741466f * fTemp7)) - (fConst34 * fRec475[1])));
			fRec477[0] = (fRec477[1] + fTemp124);
			fRec475[0] = fRec477[0];
			float fRec476 = fTemp124;
			float fTemp125 = (fConst27 * ((fConst5 * (0.0f - ((fConst31 * fRec484[1]) + (fConst30 * fRec481[1])))) + (fConst29 * ((((0.173804626f * fTemp19) + (0.370224208f * fTemp22)) + (0.00118083099f * fTemp20)) - ((((0.00362948119f * fTemp17) + (0.0993002877f * fTemp18)) + (0.371892184f * fTemp21)) + (0.00441059144f * fTemp23))))));
			fRec486[0] = (fRec486[1] + fTemp125);
			fRec484[0] = fRec486[0];
			float fRec485 = fTemp125;
			fRec483[0] = (fRec484[0] + fRec483[1]);
			fRec481[0] = fRec483[0];
			float fRec482 = fRec485;
			float fTemp126 = (fConst32 * fRec478[1]);
			fRec480[0] = ((fRec482 + fRec480[1]) - fTemp126);
			fRec478[0] = fRec480[0];
			float fRec479 = (fRec482 - fTemp126);
			fVec25[(IOTA & 255)] = ((0.073586829f * fTemp26) + (fRec470 + (fRec476 + fRec479)));
			output25[i] = FAUSTFLOAT((0.953550935f * (fRec0[0] * fVec25[((IOTA - iConst38) & 255)])));
			float fTemp127 = (fConst27 * ((fConst5 * (0.0f - ((fConst31 * fRec493[1]) + (fConst30 * fRec490[1])))) + (fConst29 * ((((0.0963917226f * fTemp18) + (0.186665148f * fTemp19)) + (0.00385038112f * fTemp23)) - ((((0.00318401633f * fTemp17) + (0.372215807f * fTemp21)) + (0.369523793f * fTemp22)) + (0.00253204582f * fTemp20))))));
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
			float fTemp129 = (fConst33 * (((0.206251472f * fTemp8) - ((0.199014723f * fTemp7) + (0.197232217f * fTemp9))) - (fConst34 * fRec496[1])));
			fRec498[0] = (fRec498[1] + fTemp129);
			fRec496[0] = fRec498[0];
			float fRec497 = fTemp129;
			float fTemp130 = (fConst35 * ((((0.121424466f * fTemp11) + (((0.0776813924f * fTemp15) + (0.121789776f * fTemp13)) + (0.000212477506f * fTemp14))) - (0.00333584193f * fTemp12)) + (fConst5 * (0.0f - ((fConst37 * fRec502[1]) + (fConst36 * fRec499[1]))))));
			fRec504[0] = (fRec504[1] + fTemp130);
			fRec502[0] = fRec504[0];
			float fRec503 = fTemp130;
			fRec501[0] = (fRec502[0] + fRec501[1]);
			fRec499[0] = fRec501[0];
			float fRec500 = fRec503;
			fVec26[(IOTA & 255)] = ((0.062218491f * fTemp26) + (fRec488 + (fRec497 + fRec500)));
			output26[i] = FAUSTFLOAT((0.953550935f * (fRec0[0] * fVec26[((IOTA - iConst38) & 255)])));
			float fTemp131 = (fConst27 * ((fConst5 * (0.0f - ((fConst31 * fRec511[1]) + (fConst30 * fRec508[1])))) + (fConst29 * (((((0.00325604132f * fTemp17) + (0.371654123f * fTemp21)) + (0.188635901f * fTemp19)) + (0.00443608733f * fTemp23)) - (((0.0975675508f * fTemp18) + (0.37001121f * fTemp22)) + (0.0022796425f * fTemp20))))));
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
			float fTemp133 = (fConst33 * ((((0.198538467f * fTemp7) + (0.212811694f * fTemp8)) - (0.197550148f * fTemp9)) - (fConst34 * fRec514[1])));
			fRec516[0] = (fRec516[1] + fTemp133);
			fRec514[0] = fRec516[0];
			float fRec515 = fTemp133;
			float fTemp134 = (fConst35 * ((((0.00324617582f * fTemp12) + ((0.0718967021f * fTemp15) + (0.121579647f * fTemp13))) - ((0.119860783f * fTemp11) + (0.000188571401f * fTemp14))) + (fConst5 * (0.0f - ((fConst37 * fRec520[1]) + (fConst36 * fRec517[1]))))));
			fRec522[0] = (fRec522[1] + fTemp134);
			fRec520[0] = fRec522[0];
			float fRec521 = fTemp134;
			fRec519[0] = (fRec520[0] + fRec519[1]);
			fRec517[0] = fRec519[0];
			float fRec518 = fRec521;
			fVec27[(IOTA & 255)] = ((0.0595878065f * fTemp26) + (fRec506 + (fRec515 + fRec518)));
			output27[i] = FAUSTFLOAT((0.953550935f * (fRec0[0] * fVec27[((IOTA - iConst38) & 255)])));
			float fTemp135 = (fConst39 * ((((0.000109369998f * fTemp7) + (0.901154518f * fTemp8)) - (9.11524985e-05f * fTemp9)) - (fConst40 * fRec523[1])));
			fRec525[0] = (fRec525[1] + fTemp135);
			fRec523[0] = fRec525[0];
			float fRec524 = fTemp135;
			float fTemp136 = (fConst41 * ((0.0f - ((0.000206620403f * fTemp11) + ((1.71831998e-05f * fTemp12) + (((0.550075293f * fTemp15) + (0.000195069893f * fTemp13)) + (0.000155677699f * fTemp14))))) + (fConst5 * (0.0f - ((fConst43 * fRec529[1]) + (fConst42 * fRec526[1]))))));
			fRec531[0] = (fRec531[1] + fTemp136);
			fRec529[0] = fRec531[0];
			float fRec530 = fTemp136;
			fRec528[0] = (fRec529[0] + fRec528[1]);
			fRec526[0] = fRec528[0];
			float fRec527 = fRec530;
			float fTemp137 = (fConst44 * ((fConst5 * (0.0f - ((fConst46 * fRec538[1]) + (fConst45 * fRec535[1])))) + (fConst48 * ((((((3.28503011e-05f * fTemp17) + (0.000116524898f * fTemp18)) + (0.000266813091f * fTemp21)) + (0.594347596f * fTemp19)) + (0.000737567199f * fTemp20)) - ((0.000332687807f * fTemp22) + (2.92714994e-05f * fTemp23))))));
			fRec540[0] = (fRec540[1] + fTemp137);
			fRec538[0] = fRec540[0];
			float fRec539 = fTemp137;
			fRec537[0] = (fRec538[0] + fRec537[1]);
			fRec535[0] = fRec537[0];
			float fRec536 = fRec539;
			float fTemp138 = (fConst49 * fRec532[1]);
			fRec534[0] = ((fRec536 + fRec534[1]) - fTemp138);
			fRec532[0] = fRec534[0];
			float fRec533 = (fRec536 - fTemp138);
			output28[i] = FAUSTFLOAT((fRec0[0] * ((fRec524 + (fRec527 + fRec533)) - (0.244039878f * fTemp26))));
			float fTemp139 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec547[1]) + (fConst9 * fRec544[1])))) + (fConst12 * (((((0.158195898f * fTemp17) + (0.0162898954f * fTemp21)) + (0.0428528935f * fTemp22)) + (0.0525754541f * fTemp23)) - (((0.111944444f * fTemp18) + (0.0317356735f * fTemp19)) + (0.105316281f * fTemp20))))));
			fRec549[0] = (fRec549[1] + fTemp139);
			fRec547[0] = fRec549[0];
			float fRec548 = fTemp139;
			fRec546[0] = (fRec547[0] + fRec546[1]);
			fRec544[0] = fRec546[0];
			float fRec545 = fRec548;
			float fTemp140 = (fConst13 * fRec541[1]);
			fRec543[0] = ((fRec545 + fRec543[1]) - fTemp140);
			fRec541[0] = fRec543[0];
			float fRec542 = (fRec545 - fTemp140);
			float fTemp141 = (fConst1 * ((((0.0963481069f * fTemp7) + (0.219445392f * fTemp9)) - (0.337151587f * fTemp8)) - (fConst3 * fRec550[1])));
			fRec552[0] = (fRec552[1] + fTemp141);
			fRec550[0] = fRec552[0];
			float fRec551 = fTemp141;
			float fTemp142 = (fConst4 * ((((0.14642331f * fTemp12) + ((0.177118987f * fTemp15) + (0.13265872f * fTemp14))) - ((0.0984692127f * fTemp11) + (0.221877754f * fTemp13))) + (fConst5 * (0.0f - ((fConst7 * fRec556[1]) + (fConst6 * fRec553[1]))))));
			fRec558[0] = (fRec558[1] + fTemp142);
			fRec556[0] = fRec558[0];
			float fRec557 = fTemp142;
			fRec555[0] = (fRec556[0] + fRec555[1]);
			fRec553[0] = fRec555[0];
			float fRec554 = fRec557;
			fVec28[(IOTA & 1023)] = ((0.219577104f * fTemp26) + (fRec542 + (fRec551 + fRec554)));
			output29[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec28[((IOTA - iConst14) & 1023)])));
			float fTemp143 = (fConst1 * ((((0.00590840075f * fTemp7) + (0.242113218f * fTemp9)) - (0.339145064f * fTemp8)) - (fConst3 * fRec559[1])));
			fRec561[0] = (fRec561[1] + fTemp143);
			fRec559[0] = fRec561[0];
			float fRec560 = fTemp143;
			float fTemp144 = (fConst4 * ((((0.0105640655f * fTemp12) + ((0.179195464f * fTemp15) + (0.198572695f * fTemp14))) - ((0.00651274761f * fTemp11) + (0.244516179f * fTemp13))) + (fConst5 * (0.0f - ((fConst7 * fRec565[1]) + (fConst6 * fRec562[1]))))));
			fRec567[0] = (fRec567[1] + fTemp144);
			fRec565[0] = fRec567[0];
			float fRec566 = fTemp144;
			fRec564[0] = (fRec565[0] + fRec564[1]);
			fRec562[0] = fRec564[0];
			float fRec563 = fRec566;
			float fTemp145 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec574[1]) + (fConst9 * fRec571[1])))) + (fConst12 * (((((0.0126232924f * fTemp17) + (0.00158408436f * fTemp21)) + (0.0482298769f * fTemp22)) + (0.166274622f * fTemp23)) - (((0.00758787198f * fTemp18) + (0.0326858573f * fTemp19)) + (0.156895638f * fTemp20))))));
			fRec576[0] = (fRec576[1] + fTemp145);
			fRec574[0] = fRec576[0];
			float fRec575 = fTemp145;
			fRec573[0] = (fRec574[0] + fRec573[1]);
			fRec571[0] = fRec573[0];
			float fRec572 = fRec575;
			float fTemp146 = (fConst13 * fRec568[1]);
			fRec570[0] = ((fRec572 + fRec570[1]) - fTemp146);
			fRec568[0] = fRec570[0];
			float fRec569 = (fRec572 - fTemp146);
			fVec29[(IOTA & 1023)] = ((0.220378011f * fTemp26) + (fRec560 + (fRec563 + fRec569)));
			output30[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec29[((IOTA - iConst14) & 1023)])));
			float fTemp147 = (fConst4 * ((((0.0880952552f * fTemp11) + ((0.178433552f * fTemp15) + (0.14639309f * fTemp14))) - ((0.133978873f * fTemp12) + (0.227442831f * fTemp13))) + (fConst5 * (0.0f - ((fConst7 * fRec580[1]) + (fConst6 * fRec577[1]))))));
			fRec582[0] = (fRec582[1] + fTemp147);
			fRec580[0] = fRec582[0];
			float fRec581 = fTemp147;
			fRec579[0] = (fRec580[0] + fRec579[1]);
			fRec577[0] = fRec579[0];
			float fRec578 = fRec581;
			float fTemp148 = (fConst1 * (((0.225845844f * fTemp9) - ((0.0863559321f * fTemp7) + (0.338537902f * fTemp8))) - (fConst3 * fRec583[1])));
			fRec585[0] = (fRec585[1] + fTemp148);
			fRec583[0] = fRec585[0];
			float fRec584 = fTemp148;
			float fTemp149 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec592[1]) + (fConst9 * fRec589[1])))) + (fConst12 * ((((0.102637589f * fTemp18) + (0.0436144657f * fTemp22)) + (0.0725145862f * fTemp23)) - ((((0.149486199f * fTemp17) + (0.0142718712f * fTemp21)) + (0.0321305804f * fTemp19)) + (0.115561105f * fTemp20))))));
			fRec594[0] = (fRec594[1] + fTemp149);
			fRec592[0] = fRec594[0];
			float fRec593 = fTemp149;
			fRec591[0] = (fRec592[0] + fRec591[1]);
			fRec589[0] = fRec591[0];
			float fRec590 = fRec593;
			float fTemp150 = (fConst13 * fRec586[1]);
			fRec588[0] = ((fRec590 + fRec588[1]) - fTemp150);
			fRec586[0] = fRec588[0];
			float fRec587 = (fRec590 - fTemp150);
			fVec30[(IOTA & 1023)] = ((0.220043972f * fTemp26) + (fRec578 + (fRec584 + fRec587)));
			output31[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec30[((IOTA - iConst14) & 1023)])));
			float fTemp151 = (fConst1 * (((0.173214346f * fTemp9) - ((0.166966736f * fTemp7) + (0.337275416f * fTemp8))) - (fConst3 * fRec595[1])));
			fRec597[0] = (fRec597[1] + fTemp151);
			fRec595[0] = fRec597[0];
			float fRec596 = fTemp151;
			float fTemp152 = (fConst4 * ((((0.1698872f * fTemp11) + ((0.176279113f * fTemp15) + (0.00691629108f * fTemp14))) - ((0.198969483f * fTemp12) + (0.173964709f * fTemp13))) + (fConst5 * (0.0f - ((fConst7 * fRec601[1]) + (fConst6 * fRec598[1]))))));
			fRec603[0] = (fRec603[1] + fTemp152);
			fRec601[0] = fRec603[0];
			float fRec602 = fTemp152;
			fRec600[0] = (fRec601[0] + fRec600[1]);
			fRec598[0] = fRec600[0];
			float fRec599 = fRec602;
			float fTemp153 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec610[1]) + (fConst9 * fRec607[1])))) + (fConst12 * (((0.15229477f * fTemp18) + (0.0313023627f * fTemp22)) - (((((0.12406221f * fTemp17) + (0.0308006182f * fTemp21)) + (0.0307277013f * fTemp19)) + (0.00567851681f * fTemp20)) + (0.112192243f * fTemp23))))));
			fRec612[0] = (fRec612[1] + fTemp153);
			fRec610[0] = fRec612[0];
			float fRec611 = fTemp153;
			fRec609[0] = (fRec610[0] + fRec609[1]);
			fRec607[0] = fRec609[0];
			float fRec608 = fRec611;
			float fTemp154 = (fConst13 * fRec604[1]);
			fRec606[0] = ((fRec608 + fRec606[1]) - fTemp154);
			fRec604[0] = fRec606[0];
			float fRec605 = (fRec608 - fTemp154);
			fVec31[(IOTA & 1023)] = ((0.219702542f * fTemp26) + (fRec596 + (fRec599 + fRec605)));
			output32[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec31[((IOTA - iConst14) & 1023)])));
			float fTemp155 = (fConst1 * (((0.0928307995f * fTemp9) - ((0.224538758f * fTemp7) + (0.336715013f * fTemp8))) - (fConst3 * fRec613[1])));
			fRec615[0] = (fRec615[1] + fTemp155);
			fRec613[0] = fRec615[0];
			float fRec614 = fTemp155;
			float fTemp156 = (fConst4 * ((((0.226790488f * fTemp11) + (0.174678117f * fTemp15)) - ((0.143214643f * fTemp12) + ((0.0931916907f * fTemp13) + (0.13906379f * fTemp14)))) + (fConst5 * (0.0f - ((fConst7 * fRec619[1]) + (fConst6 * fRec616[1]))))));
			fRec621[0] = (fRec621[1] + fTemp156);
			fRec619[0] = fRec621[0];
			float fRec620 = fTemp156;
			fRec618[0] = (fRec619[0] + fRec618[1]);
			fRec616[0] = fRec618[0];
			float fRec617 = fRec620;
			float fTemp157 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec628[1]) + (fConst9 * fRec625[1])))) + (fConst12 * (((((0.0597572103f * fTemp17) + (0.110298827f * fTemp18)) + (0.0158402976f * fTemp22)) + (0.109542996f * fTemp20)) - (((0.044401966f * fTemp21) + (0.0296470225f * fTemp19)) + (0.156120092f * fTemp23))))));
			fRec630[0] = (fRec630[1] + fTemp157);
			fRec628[0] = fRec630[0];
			float fRec629 = fTemp157;
			fRec627[0] = (fRec628[0] + fRec627[1]);
			fRec625[0] = fRec627[0];
			float fRec626 = fRec629;
			float fTemp158 = (fConst13 * fRec622[1]);
			fRec624[0] = ((fRec626 + fRec624[1]) - fTemp158);
			fRec622[0] = fRec624[0];
			float fRec623 = (fRec626 - fTemp158);
			fVec32[(IOTA & 1023)] = ((0.219809368f * fTemp26) + (fRec614 + (fRec617 + fRec623)));
			output33[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec32[((IOTA - iConst14) & 1023)])));
			float fTemp159 = (fConst4 * ((((0.246784776f * fTemp11) + ((3.95101997e-05f * fTemp12) + (0.17468828f * fTemp15))) - ((0.000522316084f * fTemp13) + (0.200457588f * fTemp14))) + (fConst5 * (0.0f - ((fConst7 * fRec634[1]) + (fConst6 * fRec631[1]))))));
			fRec636[0] = (fRec636[1] + fTemp159);
			fRec634[0] = fRec636[0];
			float fRec635 = fTemp159;
			fRec633[0] = (fRec634[0] + fRec633[1]);
			fRec631[0] = fRec633[0];
			float fRec632 = fRec635;
			float fTemp160 = (fConst1 * (((0.000288919196f * fTemp9) - ((0.245738387f * fTemp7) + (0.336850375f * fTemp8))) - (fConst3 * fRec637[1])));
			fRec639[0] = (fRec639[1] + fTemp160);
			fRec637[0] = fRec639[0];
			float fRec638 = fTemp160;
			float fTemp161 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec646[1]) + (fConst9 * fRec643[1])))) + (fConst12 * (((((0.167306885f * fTemp17) + (0.0011401138f * fTemp18)) + (0.000545269693f * fTemp22)) + (0.158530638f * fTemp20)) - (((0.049217876f * fTemp21) + (0.0296977907f * fTemp19)) + (0.000622167427f * fTemp23))))));
			fRec648[0] = (fRec648[1] + fTemp161);
			fRec646[0] = fRec648[0];
			float fRec647 = fTemp161;
			fRec645[0] = (fRec646[0] + fRec645[1]);
			fRec643[0] = fRec645[0];
			float fRec644 = fRec647;
			float fTemp162 = (fConst13 * fRec640[1]);
			fRec642[0] = ((fRec644 + fRec642[1]) - fTemp162);
			fRec640[0] = fRec642[0];
			float fRec641 = (fRec644 - fTemp162);
			fVec33[(IOTA & 1023)] = ((0.219978943f * fTemp26) + (fRec632 + (fRec638 + fRec641)));
			output34[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec33[((IOTA - iConst14) & 1023)])));
			float fTemp163 = (fConst1 * ((0.0f - (((0.224782825f * fTemp7) + (0.337144136f * fTemp8)) + (0.0929932743f * fTemp9))) - (fConst3 * fRec649[1])));
			fRec651[0] = (fRec651[1] + fTemp163);
			fRec649[0] = fRec651[0];
			float fRec650 = fTemp163;
			float fTemp164 = (fConst4 * ((((0.225669205f * fTemp11) + ((0.144856751f * fTemp12) + ((0.176020145f * fTemp15) + (0.0931760967f * fTemp13)))) - (0.139595851f * fTemp14)) + (fConst5 * (0.0f - ((fConst7 * fRec655[1]) + (fConst6 * fRec652[1]))))));
			fRec657[0] = (fRec657[1] + fTemp164);
			fRec655[0] = fRec657[0];
			float fRec656 = fTemp164;
			fRec654[0] = (fRec655[0] + fRec654[1]);
			fRec652[0] = fRec654[0];
			float fRec653 = fRec656;
			float fTemp165 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec664[1]) + (fConst9 * fRec661[1])))) + (fConst12 * ((((0.0598700605f * fTemp17) + (0.111054689f * fTemp20)) + (0.158033639f * fTemp23)) - ((((0.110454045f * fTemp18) + (0.0431853719f * fTemp21)) + (0.0307732113f * fTemp19)) + (0.0152263064f * fTemp22))))));
			fRec666[0] = (fRec666[1] + fTemp165);
			fRec664[0] = fRec666[0];
			float fRec665 = fTemp165;
			fRec663[0] = (fRec664[0] + fRec663[1]);
			fRec661[0] = fRec663[0];
			float fRec662 = fRec665;
			float fTemp166 = (fConst13 * fRec658[1]);
			fRec660[0] = ((fRec662 + fRec660[1]) - fTemp166);
			fRec658[0] = fRec660[0];
			float fRec659 = (fRec662 - fTemp166);
			fVec34[(IOTA & 1023)] = ((0.219839483f * fTemp26) + (fRec650 + (fRec653 + fRec659)));
			output35[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec34[((IOTA - iConst14) & 1023)])));
			float fTemp167 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec673[1]) + (fConst9 * fRec670[1])))) + (fConst12 * ((0.111678727f * fTemp23) - ((((((0.123682067f * fTemp17) + (0.152072921f * fTemp18)) + (0.0297531039f * fTemp21)) + (0.0321177319f * fTemp19)) + (0.0311478712f * fTemp22)) + (0.00451690331f * fTemp20))))));
			fRec675[0] = (fRec675[1] + fTemp167);
			fRec673[0] = fRec675[0];
			float fRec674 = fTemp167;
			fRec672[0] = (fRec673[0] + fRec672[1]);
			fRec670[0] = fRec672[0];
			float fRec671 = fRec674;
			float fTemp168 = (fConst13 * fRec667[1]);
			fRec669[0] = ((fRec671 + fRec669[1]) - fTemp168);
			fRec667[0] = fRec669[0];
			float fRec668 = (fRec671 - fTemp168);
			float fTemp169 = (fConst1 * ((0.0f - (((0.165723726f * fTemp7) + (0.337442309f * fTemp8)) + (0.171796203f * fTemp9))) - (fConst3 * fRec676[1])));
			fRec678[0] = (fRec678[1] + fTemp169);
			fRec676[0] = fRec678[0];
			float fRec677 = fTemp169;
			float fTemp170 = (fConst4 * (((0.16735591f * fTemp11) + ((0.197316974f * fTemp12) + (((0.177683473f * fTemp15) + (0.172775671f * fTemp13)) + (0.00656883838f * fTemp14)))) + (fConst5 * (0.0f - ((fConst7 * fRec682[1]) + (fConst6 * fRec679[1]))))));
			fRec684[0] = (fRec684[1] + fTemp170);
			fRec682[0] = fRec684[0];
			float fRec683 = fTemp170;
			fRec681[0] = (fRec682[0] + fRec681[1]);
			fRec679[0] = fRec681[0];
			float fRec680 = fRec683;
			fVec35[(IOTA & 1023)] = ((0.219583765f * fTemp26) + (fRec668 + (fRec677 + fRec680)));
			output36[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec35[((IOTA - iConst14) & 1023)])));
			float fTemp171 = (fConst8 * ((fConst12 * (0.0f - (((((((0.147745177f * fTemp17) + (0.102478892f * fTemp18)) + (0.0149267223f * fTemp21)) + (0.0329473428f * fTemp19)) + (0.0433936231f * fTemp22)) + (0.112928361f * fTemp20)) + (0.0700524673f * fTemp23)))) + (fConst5 * (0.0f - ((fConst10 * fRec691[1]) + (fConst9 * fRec688[1]))))));
			fRec693[0] = (fRec693[1] + fTemp171);
			fRec691[0] = fRec693[0];
			float fRec692 = fTemp171;
			fRec690[0] = (fRec691[0] + fRec690[1]);
			fRec688[0] = fRec690[0];
			float fRec689 = fRec692;
			float fTemp172 = (fConst13 * fRec685[1]);
			fRec687[0] = ((fRec689 + fRec687[1]) - fTemp172);
			fRec685[0] = fRec687[0];
			float fRec686 = (fRec689 - fTemp172);
			float fTemp173 = (fConst1 * ((0.0f - (((0.0856082365f * fTemp7) + (0.337572575f * fTemp8)) + (0.222581327f * fTemp9))) - (fConst3 * fRec694[1])));
			fRec696[0] = (fRec696[1] + fTemp173);
			fRec694[0] = fRec696[0];
			float fRec695 = fTemp173;
			float fTemp174 = (fConst4 * (((0.087312378f * fTemp11) + ((0.131919473f * fTemp12) + (((0.178648382f * fTemp15) + (0.224207968f * fTemp13)) + (0.14279148f * fTemp14)))) + (fConst5 * (0.0f - ((fConst7 * fRec700[1]) + (fConst6 * fRec697[1]))))));
			fRec702[0] = (fRec702[1] + fTemp174);
			fRec700[0] = fRec702[0];
			float fRec701 = fTemp174;
			fRec699[0] = (fRec700[0] + fRec699[1]);
			fRec697[0] = fRec699[0];
			float fRec698 = fRec701;
			fVec36[(IOTA & 1023)] = ((0.219427153f * fTemp26) + (fRec686 + (fRec695 + fRec698)));
			output37[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec36[((IOTA - iConst14) & 1023)])));
			float fTemp175 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec709[1]) + (fConst9 * fRec706[1])))) + (fConst12 * (((0.000116970201f * fTemp17) + (0.000537793327f * fTemp18)) - (((((0.000934037496f * fTemp21) + (0.0329410806f * fTemp19)) + (0.0479857251f * fTemp22)) + (0.156585127f * fTemp20)) + (0.166288882f * fTemp23))))));
			fRec711[0] = (fRec711[1] + fTemp175);
			fRec709[0] = fRec711[0];
			float fRec710 = fTemp175;
			fRec708[0] = (fRec709[0] + fRec708[1]);
			fRec706[0] = fRec708[0];
			float fRec707 = fRec710;
			float fTemp176 = (fConst13 * fRec703[1]);
			fRec705[0] = ((fRec707 + fRec705[1]) - fTemp176);
			fRec703[0] = fRec705[0];
			float fRec704 = (fRec707 - fTemp176);
			float fTemp177 = (fConst1 * ((0.0f - (((1.06075004e-05f * fTemp7) + (0.336761117f * fTemp8)) + (0.240122393f * fTemp9))) - (fConst3 * fRec712[1])));
			fRec714[0] = (fRec714[1] + fTemp177);
			fRec712[0] = fRec714[0];
			float fRec713 = fTemp177;
			float fTemp178 = (fConst4 * ((((0.000472827494f * fTemp11) + (((0.178265467f * fTemp15) + (0.24186115f * fTemp13)) + (0.197205603f * fTemp14))) - (0.00117291242f * fTemp12)) + (fConst5 * (0.0f - ((fConst7 * fRec718[1]) + (fConst6 * fRec715[1]))))));
			fRec720[0] = (fRec720[1] + fTemp178);
			fRec718[0] = fRec720[0];
			float fRec719 = fTemp178;
			fRec717[0] = (fRec718[0] + fRec717[1]);
			fRec715[0] = fRec717[0];
			float fRec716 = fRec719;
			fVec37[(IOTA & 1023)] = ((0.218969673f * fTemp26) + (fRec704 + (fRec713 + fRec716)));
			output38[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec37[((IOTA - iConst14) & 1023)])));
			float fTemp179 = (fConst8 * ((fConst12 * ((((0.158421338f * fTemp17) + (0.11203403f * fTemp18)) + (0.0151844649f * fTemp21)) - ((((0.031885501f * fTemp19) + (0.0424462967f * fTemp22)) + (0.107762434f * fTemp20)) + (0.0567626879f * fTemp23)))) + (fConst5 * (0.0f - ((fConst10 * fRec727[1]) + (fConst9 * fRec724[1]))))));
			fRec729[0] = (fRec729[1] + fTemp179);
			fRec727[0] = fRec729[0];
			float fRec728 = fTemp179;
			fRec726[0] = (fRec727[0] + fRec726[1]);
			fRec724[0] = fRec726[0];
			float fRec725 = fRec728;
			float fTemp180 = (fConst13 * fRec721[1]);
			fRec723[0] = ((fRec725 + fRec723[1]) - fTemp180);
			fRec721[0] = fRec723[0];
			float fRec722 = (fRec725 - fTemp180);
			float fTemp181 = (fConst1 * (((0.0933172777f * fTemp7) - ((0.333591551f * fTemp8) + (0.219042554f * fTemp9))) - (fConst3 * fRec730[1])));
			fRec732[0] = (fRec732[1] + fTemp181);
			fRec730[0] = fRec732[0];
			float fRec731 = fTemp181;
			float fTemp182 = (fConst4 * (((((0.175788283f * fTemp15) + (0.220413655f * fTemp13)) + (0.135617122f * fTemp14)) - ((0.144282609f * fTemp12) + (0.0947407112f * fTemp11))) + (fConst5 * (0.0f - ((fConst7 * fRec736[1]) + (fConst6 * fRec733[1]))))));
			fRec738[0] = (fRec738[1] + fTemp182);
			fRec736[0] = fRec738[0];
			float fRec737 = fTemp182;
			fRec735[0] = (fRec736[0] + fRec735[1]);
			fRec733[0] = fRec735[0];
			float fRec734 = fRec737;
			fVec38[(IOTA & 1023)] = ((0.217316672f * fTemp26) + (fRec722 + (fRec731 + fRec734)));
			output39[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec38[((IOTA - iConst14) & 1023)])));
			float fTemp183 = (fConst4 * ((((0.172026783f * fTemp15) + (0.166712046f * fTemp13)) - ((0.167754307f * fTemp11) + ((0.192905396f * fTemp12) + (0.000174449102f * fTemp14)))) + (fConst5 * (0.0f - ((fConst7 * fRec742[1]) + (fConst6 * fRec739[1]))))));
			fRec744[0] = (fRec744[1] + fTemp183);
			fRec742[0] = fRec744[0];
			float fRec743 = fTemp183;
			fRec741[0] = (fRec742[0] + fRec741[1]);
			fRec739[0] = fRec741[0];
			float fRec740 = fRec743;
			float fTemp184 = (fConst1 * (((0.165715486f * fTemp7) - ((0.328861624f * fTemp8) + (0.165696681f * fTemp9))) - (fConst3 * fRec745[1])));
			fRec747[0] = (fRec747[1] + fTemp184);
			fRec745[0] = fRec747[0];
			float fRec746 = fTemp184;
			float fTemp185 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec754[1]) + (fConst9 * fRec751[1])))) + (fConst12 * ((((((0.115325429f * fTemp17) + (0.149780884f * fTemp18)) + (0.0300947148f * fTemp21)) + (0.000346768094f * fTemp20)) + (0.116033867f * fTemp23)) - ((0.0301990304f * fTemp19) + (0.0300057624f * fTemp22))))));
			fRec756[0] = (fRec756[1] + fTemp185);
			fRec754[0] = fRec756[0];
			float fRec755 = fTemp185;
			fRec753[0] = (fRec754[0] + fRec753[1]);
			fRec751[0] = fRec753[0];
			float fRec752 = fRec755;
			float fTemp186 = (fConst13 * fRec748[1]);
			fRec750[0] = ((fRec752 + fRec750[1]) - fTemp186);
			fRec748[0] = fRec750[0];
			float fRec749 = (fRec752 - fTemp186);
			fVec39[(IOTA & 1023)] = ((0.214801863f * fTemp26) + (fRec740 + (fRec746 + fRec749)));
			output40[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec39[((IOTA - iConst14) & 1023)])));
			float fTemp187 = (fConst8 * ((fConst12 * (((((0.105098419f * fTemp18) + (0.04196335f * fTemp21)) + (0.107611738f * fTemp20)) + (0.150558278f * fTemp23)) - (((0.0605282933f * fTemp17) + (0.0284665227f * fTemp19)) + (0.0150985634f * fTemp22)))) + (fConst5 * (0.0f - ((fConst10 * fRec763[1]) + (fConst9 * fRec760[1]))))));
			fRec765[0] = (fRec765[1] + fTemp187);
			fRec763[0] = fRec765[0];
			float fRec764 = fTemp187;
			fRec762[0] = (fRec763[0] + fRec762[1]);
			fRec760[0] = fRec762[0];
			float fRec761 = fRec764;
			float fTemp188 = (fConst13 * fRec757[1]);
			fRec759[0] = ((fRec761 + fRec759[1]) - fTemp188);
			fRec757[0] = fRec759[0];
			float fRec758 = (fRec761 - fTemp188);
			float fTemp189 = (fConst1 * (((0.216371372f * fTemp7) - ((0.324566782f * fTemp8) + (0.0898311585f * fTemp9))) - (fConst3 * fRec766[1])));
			fRec768[0] = (fRec768[1] + fTemp189);
			fRec766[0] = fRec768[0];
			float fRec767 = fTemp189;
			float fTemp190 = (fConst4 * ((((0.168372646f * fTemp15) + (0.0906518251f * fTemp13)) - ((0.21768786f * fTemp11) + ((0.13620095f * fTemp12) + (0.135185421f * fTemp14)))) + (fConst5 * (0.0f - ((fConst7 * fRec772[1]) + (fConst6 * fRec769[1]))))));
			fRec774[0] = (fRec774[1] + fTemp190);
			fRec772[0] = fRec774[0];
			float fRec773 = fTemp190;
			fRec771[0] = (fRec772[0] + fRec771[1]);
			fRec769[0] = fRec771[0];
			float fRec770 = fRec773;
			fVec40[(IOTA & 1023)] = ((0.212566227f * fTemp26) + (fRec758 + (fRec767 + fRec770)));
			output41[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec40[((IOTA - iConst14) & 1023)])));
			float fTemp191 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec781[1]) + (fConst9 * fRec778[1])))) + (fConst12 * (((((0.00787438173f * fTemp18) + (0.0465675332f * fTemp21)) + (0.15510422f * fTemp20)) + (0.0153202927f * fTemp23)) - (((0.165268838f * fTemp17) + (0.0275401566f * fTemp19)) + (0.000901874213f * fTemp22))))));
			fRec783[0] = (fRec783[1] + fTemp191);
			fRec781[0] = fRec783[0];
			float fRec782 = fTemp191;
			fRec780[0] = (fRec781[0] + fRec780[1]);
			fRec778[0] = fRec780[0];
			float fRec779 = fRec782;
			float fTemp192 = (fConst13 * fRec775[1]);
			fRec777[0] = ((fRec779 + fRec777[1]) - fTemp192);
			fRec775[0] = fRec777[0];
			float fRec776 = (fRec779 - fTemp192);
			float fTemp193 = (fConst1 * (((0.237025127f * fTemp7) - ((0.323341876f * fTemp8) + (0.00663374877f * fTemp9))) - (fConst3 * fRec784[1])));
			fRec786[0] = (fRec786[1] + fTemp193);
			fRec784[0] = fRec786[0];
			float fRec785 = fTemp193;
			float fTemp194 = (fConst4 * ((((0.166792184f * fTemp15) + (0.00715193199f * fTemp13)) - ((0.237513617f * fTemp11) + ((0.0115648834f * fTemp12) + (0.195545226f * fTemp14)))) + (fConst5 * (0.0f - ((fConst7 * fRec790[1]) + (fConst6 * fRec787[1]))))));
			fRec792[0] = (fRec792[1] + fTemp194);
			fRec790[0] = fRec792[0];
			float fRec791 = fTemp194;
			fRec789[0] = (fRec790[0] + fRec789[1]);
			fRec787[0] = fRec789[0];
			float fRec788 = fRec791;
			fVec41[(IOTA & 1023)] = ((0.212086394f * fTemp26) + (fRec776 + (fRec785 + fRec788)));
			output42[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec41[((IOTA - iConst14) & 1023)])));
			float fTemp195 = (fConst8 * ((fConst5 * (0.0f - ((fConst10 * fRec799[1]) + (fConst9 * fRec796[1])))) + (fConst12 * ((((0.041841317f * fTemp21) + (0.0151107674f * fTemp22)) + (0.113869295f * fTemp20)) - ((((0.071656324f * fTemp17) + (0.104332209f * fTemp18)) + (0.028026009f * fTemp19)) + (0.15030539f * fTemp23))))));
			fRec801[0] = (fRec801[1] + fTemp195);
			fRec799[0] = fRec801[0];
			float fRec800 = fTemp195;
			fRec798[0] = (fRec799[0] + fRec798[1]);
			fRec796[0] = fRec798[0];
			float fRec797 = fRec800;
			float fTemp196 = (fConst13 * fRec793[1]);
			fRec795[0] = ((fRec797 + fRec795[1]) - fTemp196);
			fRec793[0] = fRec795[0];
			float fRec794 = (fRec797 - fTemp196);
			float fTemp197 = (fConst1 * ((((0.221904859f * fTemp7) + (0.087434873f * fTemp9)) - (0.326558858f * fTemp8)) - (fConst3 * fRec802[1])));
			fRec804[0] = (fRec804[1] + fTemp197);
			fRec802[0] = fRec804[0];
			float fRec803 = fTemp197;
			float fTemp198 = (fConst4 * ((((0.133866981f * fTemp12) + (0.168543905f * fTemp15)) - ((0.222652644f * fTemp11) + ((0.0877925232f * fTemp13) + (0.144399449f * fTemp14)))) + (fConst5 * (0.0f - ((fConst7 * fRec808[1]) + (fConst6 * fRec805[1]))))));
			fRec810[0] = (fRec810[1] + fTemp198);
			fRec808[0] = fRec810[0];
			float fRec809 = fTemp198;
			fRec807[0] = (fRec808[0] + fRec807[1]);
			fRec805[0] = fRec807[0];
			float fRec806 = fRec809;
			fVec42[(IOTA & 1023)] = ((0.214052483f * fTemp26) + (fRec794 + (fRec803 + fRec806)));
			output43[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec42[((IOTA - iConst14) & 1023)])));
			float fTemp199 = (fConst8 * ((fConst12 * (((((0.105035655f * fTemp17) + (0.0307273827f * fTemp21)) + (0.0298537407f * fTemp22)) + (0.00994398724f * fTemp20)) - (((0.150606439f * fTemp18) + (0.0297204982f * fTemp19)) + (0.127635404f * fTemp23)))) + (fConst5 * (0.0f - ((fConst10 * fRec817[1]) + (fConst9 * fRec814[1]))))));
			fRec819[0] = (fRec819[1] + fTemp199);
			fRec817[0] = fRec819[0];
			float fRec818 = fTemp199;
			fRec816[0] = (fRec817[0] + fRec816[1]);
			fRec814[0] = fRec816[0];
			float fRec815 = fRec818;
			float fTemp200 = (fConst13 * fRec811[1]);
			fRec813[0] = ((fRec815 + fRec813[1]) - fTemp200);
			fRec811[0] = fRec813[0];
			float fRec812 = (fRec815 - fTemp200);
			float fTemp201 = (fConst1 * ((((0.173912972f * fTemp7) + (0.162573189f * fTemp9)) - (0.332071424f * fTemp8)) - (fConst3 * fRec820[1])));
			fRec822[0] = (fRec822[1] + fTemp201);
			fRec820[0] = fRec822[0];
			float fRec821 = fTemp201;
			float fTemp202 = (fConst4 * ((((0.195307299f * fTemp12) + (0.172664464f * fTemp15)) - ((0.175723791f * fTemp11) + ((0.164096728f * fTemp13) + (0.0134854f * fTemp14)))) + (fConst5 * (0.0f - ((fConst7 * fRec826[1]) + (fConst6 * fRec823[1]))))));
			fRec828[0] = (fRec828[1] + fTemp202);
			fRec826[0] = fRec828[0];
			float fRec827 = fTemp202;
			fRec825[0] = (fRec826[0] + fRec825[1]);
			fRec823[0] = fRec825[0];
			float fRec824 = fRec827;
			fVec43[(IOTA & 1023)] = ((0.217061654f * fTemp26) + (fRec812 + (fRec821 + fRec824)));
			output44[i] = FAUSTFLOAT((0.82675755f * (fRec0[0] * fVec43[((IOTA - iConst14) & 1023)])));
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
			fRec14[1] = fRec14[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec9[1] = fRec9[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec28[1] = fRec28[0];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec20[1] = fRec20[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			IOTA = (IOTA + 1);
			fRec42[1] = fRec42[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec37[1] = fRec37[0];
			fRec45[1] = fRec45[0];
			fRec43[1] = fRec43[0];
			fRec54[1] = fRec54[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec46[1] = fRec46[0];
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
			fRec150[1] = fRec150[0];
			fRec148[1] = fRec148[0];
			fRec147[1] = fRec147[0];
			fRec145[1] = fRec145[0];
			fRec153[1] = fRec153[0];
			fRec151[1] = fRec151[0];
			fRec162[1] = fRec162[0];
			fRec160[1] = fRec160[0];
			fRec159[1] = fRec159[0];
			fRec157[1] = fRec157[0];
			fRec156[1] = fRec156[0];
			fRec154[1] = fRec154[0];
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
			fRec201[1] = fRec201[0];
			fRec199[1] = fRec199[0];
			fRec207[1] = fRec207[0];
			fRec205[1] = fRec205[0];
			fRec204[1] = fRec204[0];
			fRec202[1] = fRec202[0];
			fRec216[1] = fRec216[0];
			fRec214[1] = fRec214[0];
			fRec213[1] = fRec213[0];
			fRec211[1] = fRec211[0];
			fRec210[1] = fRec210[0];
			fRec208[1] = fRec208[0];
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
			fRec276[1] = fRec276[0];
			fRec274[1] = fRec274[0];
			fRec273[1] = fRec273[0];
			fRec271[1] = fRec271[0];
			fRec279[1] = fRec279[0];
			fRec277[1] = fRec277[0];
			fRec288[1] = fRec288[0];
			fRec286[1] = fRec286[0];
			fRec285[1] = fRec285[0];
			fRec283[1] = fRec283[0];
			fRec282[1] = fRec282[0];
			fRec280[1] = fRec280[0];
			fRec294[1] = fRec294[0];
			fRec292[1] = fRec292[0];
			fRec291[1] = fRec291[0];
			fRec289[1] = fRec289[0];
			fRec297[1] = fRec297[0];
			fRec295[1] = fRec295[0];
			fRec306[1] = fRec306[0];
			fRec304[1] = fRec304[0];
			fRec303[1] = fRec303[0];
			fRec301[1] = fRec301[0];
			fRec300[1] = fRec300[0];
			fRec298[1] = fRec298[0];
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
			fRec345[1] = fRec345[0];
			fRec343[1] = fRec343[0];
			fRec351[1] = fRec351[0];
			fRec349[1] = fRec349[0];
			fRec348[1] = fRec348[0];
			fRec346[1] = fRec346[0];
			fRec360[1] = fRec360[0];
			fRec358[1] = fRec358[0];
			fRec357[1] = fRec357[0];
			fRec355[1] = fRec355[0];
			fRec354[1] = fRec354[0];
			fRec352[1] = fRec352[0];
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
			fRec405[1] = fRec405[0];
			fRec403[1] = fRec403[0];
			fRec402[1] = fRec402[0];
			fRec400[1] = fRec400[0];
			fRec399[1] = fRec399[0];
			fRec397[1] = fRec397[0];
			fRec408[1] = fRec408[0];
			fRec406[1] = fRec406[0];
			fRec414[1] = fRec414[0];
			fRec412[1] = fRec412[0];
			fRec411[1] = fRec411[0];
			fRec409[1] = fRec409[0];
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
			fRec441[1] = fRec441[0];
			fRec439[1] = fRec439[0];
			fRec438[1] = fRec438[0];
			fRec436[1] = fRec436[0];
			fRec435[1] = fRec435[0];
			fRec433[1] = fRec433[0];
			fRec444[1] = fRec444[0];
			fRec442[1] = fRec442[0];
			fRec450[1] = fRec450[0];
			fRec448[1] = fRec448[0];
			fRec447[1] = fRec447[0];
			fRec445[1] = fRec445[0];
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
			fRec474[1] = fRec474[0];
			fRec472[1] = fRec472[0];
			fRec471[1] = fRec471[0];
			fRec469[1] = fRec469[0];
			fRec477[1] = fRec477[0];
			fRec475[1] = fRec475[0];
			fRec486[1] = fRec486[0];
			fRec484[1] = fRec484[0];
			fRec483[1] = fRec483[0];
			fRec481[1] = fRec481[0];
			fRec480[1] = fRec480[0];
			fRec478[1] = fRec478[0];
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
			fRec525[1] = fRec525[0];
			fRec523[1] = fRec523[0];
			fRec531[1] = fRec531[0];
			fRec529[1] = fRec529[0];
			fRec528[1] = fRec528[0];
			fRec526[1] = fRec526[0];
			fRec540[1] = fRec540[0];
			fRec538[1] = fRec538[0];
			fRec537[1] = fRec537[0];
			fRec535[1] = fRec535[0];
			fRec534[1] = fRec534[0];
			fRec532[1] = fRec532[0];
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
			fRec561[1] = fRec561[0];
			fRec559[1] = fRec559[0];
			fRec567[1] = fRec567[0];
			fRec565[1] = fRec565[0];
			fRec564[1] = fRec564[0];
			fRec562[1] = fRec562[0];
			fRec576[1] = fRec576[0];
			fRec574[1] = fRec574[0];
			fRec573[1] = fRec573[0];
			fRec571[1] = fRec571[0];
			fRec570[1] = fRec570[0];
			fRec568[1] = fRec568[0];
			fRec582[1] = fRec582[0];
			fRec580[1] = fRec580[0];
			fRec579[1] = fRec579[0];
			fRec577[1] = fRec577[0];
			fRec585[1] = fRec585[0];
			fRec583[1] = fRec583[0];
			fRec594[1] = fRec594[0];
			fRec592[1] = fRec592[0];
			fRec591[1] = fRec591[0];
			fRec589[1] = fRec589[0];
			fRec588[1] = fRec588[0];
			fRec586[1] = fRec586[0];
			fRec597[1] = fRec597[0];
			fRec595[1] = fRec595[0];
			fRec603[1] = fRec603[0];
			fRec601[1] = fRec601[0];
			fRec600[1] = fRec600[0];
			fRec598[1] = fRec598[0];
			fRec612[1] = fRec612[0];
			fRec610[1] = fRec610[0];
			fRec609[1] = fRec609[0];
			fRec607[1] = fRec607[0];
			fRec606[1] = fRec606[0];
			fRec604[1] = fRec604[0];
			fRec615[1] = fRec615[0];
			fRec613[1] = fRec613[0];
			fRec621[1] = fRec621[0];
			fRec619[1] = fRec619[0];
			fRec618[1] = fRec618[0];
			fRec616[1] = fRec616[0];
			fRec630[1] = fRec630[0];
			fRec628[1] = fRec628[0];
			fRec627[1] = fRec627[0];
			fRec625[1] = fRec625[0];
			fRec624[1] = fRec624[0];
			fRec622[1] = fRec622[0];
			fRec636[1] = fRec636[0];
			fRec634[1] = fRec634[0];
			fRec633[1] = fRec633[0];
			fRec631[1] = fRec631[0];
			fRec639[1] = fRec639[0];
			fRec637[1] = fRec637[0];
			fRec648[1] = fRec648[0];
			fRec646[1] = fRec646[0];
			fRec645[1] = fRec645[0];
			fRec643[1] = fRec643[0];
			fRec642[1] = fRec642[0];
			fRec640[1] = fRec640[0];
			fRec651[1] = fRec651[0];
			fRec649[1] = fRec649[0];
			fRec657[1] = fRec657[0];
			fRec655[1] = fRec655[0];
			fRec654[1] = fRec654[0];
			fRec652[1] = fRec652[0];
			fRec666[1] = fRec666[0];
			fRec664[1] = fRec664[0];
			fRec663[1] = fRec663[0];
			fRec661[1] = fRec661[0];
			fRec660[1] = fRec660[0];
			fRec658[1] = fRec658[0];
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
			fRec744[1] = fRec744[0];
			fRec742[1] = fRec742[0];
			fRec741[1] = fRec741[0];
			fRec739[1] = fRec739[0];
			fRec747[1] = fRec747[0];
			fRec745[1] = fRec745[0];
			fRec756[1] = fRec756[0];
			fRec754[1] = fRec754[0];
			fRec753[1] = fRec753[0];
			fRec751[1] = fRec751[0];
			fRec750[1] = fRec750[0];
			fRec748[1] = fRec748[0];
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
