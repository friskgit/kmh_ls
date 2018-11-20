/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMHLS_FullSetup_5h5v_full_6"
version: "1.2"
Code generated with Faust 2.6.3 (https://faust.grame.fr)
Compilation options: cpp, -double -ftz 0
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
    Copyright (C) 2004-2028 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either version 3
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

    MAX MSP SDK : in order to compile a MaxMSP external with this
    architecture file you will need the official MaxMSP SDK from
    cycling'74. Please check the corresponding license.

 ************************************************************************
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>

#ifdef __APPLE__
#include <Carbon/Carbon.h>
#include <unistd.h>
#endif

#ifdef WIN32
#ifndef NAN
    static const unsigned long __nan[2] = {0xffffffff, 0x7fffffff};
    #define NAN (*(const float *) __nan)
#endif
#endif

#define FAUSTFLOAT double

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

class UI
{

    public:

        UI() {}

        virtual ~UI() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

#endif
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
#include <sstream>
#include <assert.h>

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
    
};

#endif  // FAUST_PATHBUILDER_H
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
    virtual void declare(const char* key, const char* value) = 0;
    virtual ~Meta() {};
};

#endif

/*******************************************************************************
 * JSONUI : Faust User Interface
 * This class produce a complete JSON decription of the DSP instance.
 ******************************************************************************/

template <typename REAL>
class JSONUIAux : public PathBuilder, public Meta, public UI
{

    protected:
    
        std::stringstream fJSON;
        std::stringstream fUI;
        std::stringstream fMeta;
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        std::string fVersion;
        std::string fOptions;
        std::string fName;
        std::string fFileName;
        std::string fExpandedCode;
        std::string fSHAKey;
        std::string fDSPSize;
        std::map<std::string, int> fPathTable;
    
        char fCloseUIPar;
        char fCloseMetaPar;
        int fTab;
    
        int fInputs, fOutputs;
         
        void tab(int n, std::ostream& fout)
        {
            fout << '\n';
            while (n-- > 0) {
                fout << '\t';
            }
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
    
        // Add escape (that is  '\') for internal strings
        inline std::string flatten(const std::string& src)
        {
            bool in_string = false;
            std::stringstream dst;
            for (size_t i = 0; i < src.size(); i++) {
                switch (src[i]) {
                    case '\n':
                    case '\t':
                        break;
                    case ' ':
                        if (in_string) dst << src[i];
                        break;
                    case '"':
                        dst << "\\" << '"';
                        in_string = !in_string;
                        break;
                    case '\\':
                        dst << '\\' << '\\';
                        break;
                    default:
                        dst << src[i];
                        break;
                }
            }
            return dst.str();
        }
    
        inline std::string getAddressIndex(const std::string& path)
        {
            if (fPathTable.find(path) != fPathTable.end()) {
                std::stringstream num; num << fPathTable[path];
                return num.str();
            } else {
                return "-1";
            }
        }
      
     public:
     
        JSONUIAux(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& options,
                  const std::string& size,
                  const std::map<std::string, int>& path_table)
        {
            init(name, filename, inputs, outputs, sha_key, dsp_code,  version, options, size, path_table);
        }

        JSONUIAux(const std::string& name, const std::string& filename, int inputs, int outputs)
        {
            init(name, filename, inputs, outputs, "", "", "", "", "", std::map<std::string, int>());
        }

        JSONUIAux(int inputs, int outputs)
        {
            init("", "", inputs, outputs, "", "","", "", "", std::map<std::string, int>());
        }
        
        JSONUIAux()
        {
            init("", "", -1, -1, "", "", "", "", "", std::map<std::string, int>());
        }
 
        virtual ~JSONUIAux() {}
        
        void setInputs(int inputs) { fInputs = inputs; }
        void setOutputs(int outputs) { fOutputs = outputs; }
    
        // Init may be called multiple times so fMeta and fUI are reinitialized
        void init(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& options,
                  const std::string& size,
                  const std::map<std::string, int>& path_table)
        {
            fTab = 1;
            
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
            fExpandedCode = dsp_code;
            fSHAKey = sha_key;
            fDSPSize = size;
            fPathTable = path_table;
            fVersion = version;
            fOptions = options;
        }
   
        // -- widget's layouts
    
        virtual void openGenericGroup(const char* label, const char* name)
        {
            fControlsLevel.push_back(label);
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            addMeta(fTab + 1);
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
            fControlsLevel.pop_back();
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
            std::string index = getAddressIndex(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << index << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            } else {
                tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            }
            addMeta(fTab + 1, false);
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
            std::string index = getAddressIndex(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << index << "\",";
            }
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"init\": \"" << init << "\",";
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\",";
            tab(fTab + 1, fUI); fUI << "\"step\": \"" << step << "\"";
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
            std::string index = getAddressIndex(path);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << index << "\",";
            }
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\"";
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
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << "soundfile" << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"url\": \"" << url << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            addMeta(fTab + 1, false);
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
            fJSON << "{";
            fTab += 1;
            tab(fTab, fJSON); fJSON << "\"name\": \"" << fName << "\",";
            tab(fTab, fJSON); fJSON << "\"filename\": \"" << fFileName << "\",";
            if (fVersion != "") { tab(fTab, fJSON); fJSON << "\"version\": \"" << fVersion << "\","; }
            if (fOptions != "") { tab(fTab, fJSON); fJSON << "\"options\": \"" << fOptions << "\","; }
            if (fDSPSize != "") { tab(fTab, fJSON); fJSON << "\"size\": \"" << fDSPSize << "\","; }
            if (fSHAKey != "") { tab(fTab, fJSON); fJSON << "\"sha_key\": \"" << fSHAKey << "\","; }
            if (fExpandedCode != "") { tab(fTab, fJSON); fJSON << "\"code\": \"" << fExpandedCode << "\","; }
            tab(fTab, fJSON); fJSON << "\"inputs\": \"" << fInputs << "\","; 
            tab(fTab, fJSON); fJSON << "\"outputs\": \"" << fOutputs << "\",";
            tab(fTab, fMeta); fMeta << "],";
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            if (fCloseMetaPar == ',') { // If "declare" has been called, fCloseMetaPar state is now ','
                fJSON << fMeta.str() << fUI.str();
            } else {
                fJSON << fUI.str();
            }
            tab(fTab, fJSON); fJSON << "}";
            return (flat) ? flatten(fJSON.str()) : fJSON.str();
        }
    
};

// Externally available class using FAUSTFLOAT

class JSONUI : public JSONUIAux<FAUSTFLOAT>
{
    public :
    
        JSONUI(const std::string& name,
               const std::string& filename,
               int inputs,
               int outputs,
               const std::string& sha_key,
               const std::string& dsp_code,
               const std::string& version,
               const std::string& options,
               const std::string& size,
               const std::map<std::string, int>& path_table):
        JSONUIAux<FAUSTFLOAT>(name, filename,
                              inputs, outputs,
                              sha_key, dsp_code,
                              version, options,
                              size, path_table)
        {}
        
        JSONUI(const std::string& name, const std::string& filename, int inputs, int outputs):
        JSONUIAux<FAUSTFLOAT>(name, filename, inputs, outputs)
        {}
        
        JSONUI(int inputs, int outputs):JSONUIAux<FAUSTFLOAT>(inputs, outputs)
        {}
        
        JSONUI():JSONUIAux<FAUSTFLOAT>()
        {}
    
        virtual ~JSONUI() {}
    
};

#endif // FAUST_JSONUI_H
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
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void init(int samplingRate) = 0;

        /**
         * Init instance state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceInit(int samplingRate) = 0;

        /**
         * Init instance constant state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceConstants(int samplingRate) = 0;
    
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
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
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
        virtual void init(int samplingRate) { fDSP->init(samplingRate); }
        virtual void instanceInit(int samplingRate) { fDSP->instanceInit(samplingRate); }
        virtual void instanceConstants(int samplingRate) { fDSP->instanceConstants(samplingRate); }
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
    
        virtual std::vector<std::string> getDSPFactoryLibraryList() = 0;
        virtual std::vector<std::string> getDSPFactoryIncludePathnames() = 0;
    
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
#include <string.h>
#include <stdlib.h>
#include <cstdlib>


using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

inline int lsr(int x, int n)	{ return int(((unsigned int)x) >> n); }

inline int int2pow2(int x)		{ int r = 0; while ((1<<r) < x) r++; return r; }

inline long lopt(char* argv[], const char* name, long def)
{
	int	i;
    for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return std::atoi(argv[i+1]);
	return def;
}

inline bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

inline const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

#endif


#ifdef POLY2
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

#ifndef __dsp_combiner__
#define __dsp_combiner__

#include <string.h>
#include <assert.h>


// Combine two DSP in sequence

class dsp_sequencer : public dsp {
    
    private:
        
        dsp* fDSP1;
        dsp* fDSP2;
        FAUSTFLOAT** fSeqBuffer;
         
    public:
        
        dsp_sequencer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096)
            :fDSP1(dsp1), fDSP2(dsp2)
        {
            assert(fDSP1->getNumOutputs() == fDSP2->getNumInputs());
            fSeqBuffer = new FAUSTFLOAT*[fDSP1->getNumOutputs()];
            for (int i = 0; i < fDSP1->getNumOutputs(); i++) {
                fSeqBuffer[i] = new FAUSTFLOAT[buffer_size];
            }
        }
        
        virtual ~dsp_sequencer()
        {
            for (int i = 0; i < fDSP1->getNumOutputs(); i++) {
               delete [] fSeqBuffer[i];
            }
            
            delete [] fSeqBuffer;
            delete fDSP1;
            delete fDSP2;
        }
               
        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }
    
        virtual void buildUserInterface(UI* ui_interface)
        {
            ui_interface->openTabBox("Sequencer");
            ui_interface->openVerticalBox("DSP1");
            fDSP1->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->openVerticalBox("DSP2");
            fDSP2->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->closeBox();
        }
        
        virtual int getSampleRate()
        {
            return fDSP1->getSampleRate();
        }
    
        virtual void init(int samplingRate)
        {
            fDSP1->init(samplingRate);
            fDSP2->init(samplingRate);
        }
    
        virtual void instanceInit(int samplingRate)
        {
            fDSP1->instanceInit(samplingRate);
            fDSP2->instanceInit(samplingRate);
        }
    
        virtual void instanceConstants(int samplingRate)
        {
            fDSP1->instanceConstants(samplingRate);
            fDSP2->instanceConstants(samplingRate);
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
        
        virtual dsp* clone()
        {
            return new dsp_sequencer(fDSP1->clone(), fDSP2->clone());
        }
    
        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }
 
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, fSeqBuffer);
            fDSP2->compute(count, fSeqBuffer, outputs);
        }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

// Combine two DSP in parallel

class dsp_parallelizer : public dsp {
    
    private:
        
        dsp* fDSP1;
        dsp* fDSP2;
    
        FAUSTFLOAT** fInputsDSP2;
        FAUSTFLOAT** fOutputsDSP2;
    
    public:
        
        dsp_parallelizer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096)
            :fDSP1(dsp1), fDSP2(dsp2)
        {
            fInputsDSP2 = new FAUSTFLOAT*[fDSP2->getNumInputs()];
            fOutputsDSP2 = new FAUSTFLOAT*[fDSP2->getNumOutputs()];
        }
        
        virtual ~dsp_parallelizer()
        {
            delete fDSP1;
            delete fDSP2;
            delete [] fInputsDSP2;
            delete [] fOutputsDSP2;
        }
               
        virtual int getNumInputs() { return fDSP1->getNumInputs() + fDSP2->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs() + fDSP2->getNumOutputs(); }
    
        virtual void buildUserInterface(UI* ui_interface)
        {
            ui_interface->openTabBox("Parallelizer");
            ui_interface->openVerticalBox("DSP1");
            fDSP1->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->openVerticalBox("DSP2");
            fDSP2->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->closeBox();
        }
        
        virtual int getSampleRate()
        {
            return fDSP1->getSampleRate();
        }
    
        virtual void init(int samplingRate)
        {
            fDSP1->init(samplingRate);
            fDSP2->init(samplingRate);
        }
    
        virtual void instanceInit(int samplingRate)
        {
            fDSP1->instanceInit(samplingRate);
            fDSP2->instanceInit(samplingRate);
        }
    
        virtual void instanceConstants(int samplingRate)
        {
            fDSP1->instanceConstants(samplingRate);
            fDSP2->instanceConstants(samplingRate);
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
        
        virtual dsp* clone()
        {
            return new dsp_parallelizer(fDSP1->clone(), fDSP2->clone());
        }

        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, outputs);
            
            // Shift inputs/outputs channels for fDSP2
            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                fInputsDSP2[chan] = inputs[fDSP1->getNumInputs() + chan];
            }
            for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                fOutputsDSP2[chan] = outputs[fDSP1->getNumOutputs() + chan];
            }
            
            fDSP2->compute(count, fInputsDSP2, fOutputsDSP2);
        }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

#endif
#include "effect.cpp"
#endif

#if SOUNDFILE
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
 
#ifndef __SoundUI_H__
#define __SoundUI_H__

#include <map>
#include <vector>
#include <string>

#ifdef __APPLE__
#include <CoreFoundation/CFBundle.h>
#endif

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

#ifndef __soundfile__
#define __soundfile__

#include <sndfile.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#define BUFFER_SIZE     1024
#define SAMPLE_RATE     44100
#define MAX_CHAN        64

#define MIN_CHAN(a,b) ((a) < (b) ? (a) : (b))

#define PRE_PACKED_STRUCTURE
#define POST_PACKED_STRUCTURE __attribute__((__packed__))

PRE_PACKED_STRUCTURE
struct Soundfile {
    
    FAUSTFLOAT** fBuffers;
    int fLength;
    int fSampleRate;
    int fChannels;
    
    typedef sf_count_t (* sample_read)(SNDFILE* sndfile, FAUSTFLOAT* ptr, sf_count_t frames);
    
    static std::string CheckAux(const std::string& path_name_str, std::string& sha_key)
    {
        SF_INFO snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name_str.c_str(), SFM_READ, &snd_info);
        if (snd_file) {
            sf_close(snd_file);
            // Possibly read associated SHA_KEY file
            std::string sha_key_path_name_str = path_name_str + "_sha_key";
            std::ifstream reader(sha_key_path_name_str.c_str());
            if (reader.is_open()) {
                std::string sha_key_line;
                getline(reader, sha_key_line);
                std::stringstream line_reader(sha_key_line);
                line_reader >> sha_key;
            }
            return path_name_str;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name_str << "' (" << sf_strerror(NULL) << ")" << std::endl;
            return "";
        }
    }
    
    // Check if soundfile exists and return the real path_name
    static std::string Check(const std::vector<std::string>& sound_directories, const std::string& file_name_str, std::string& sha_key)
    {
        std::string path_name_str = CheckAux(file_name_str, sha_key);
        if (path_name_str != "") {
            return path_name_str;
        } else {
            for (int i = 0; i < sound_directories.size(); i++) {
                std::string res = CheckAux(sound_directories[i] + "/" + file_name_str, sha_key);
                if (res != "") { return res; }
            }
            return "";
        }
    }
    
    Soundfile(const std::string& path_name_str, int max_chan)
    {
        fBuffers = new FAUSTFLOAT*[max_chan];
        if (!fBuffers) {
            throw std::bad_alloc();
        }
     
        // Open sndfile
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name_str.c_str(), SFM_READ, &snd_info);
        
        if (snd_file) {
            
            fChannels = MIN_CHAN(max_chan, snd_info.channels);
            fLength = int(snd_info.frames);
            fSampleRate = snd_info.samplerate;
            
            for (int chan = 0; chan < fChannels; chan++) {
                fBuffers[chan] = new FAUSTFLOAT[snd_info.frames];
                if (!fBuffers[chan]) {
                    throw std::bad_alloc();
                }
            }
            
            // Read and fill snd_info.channels number of channels
            sf_count_t nbf, index = 0;
            FAUSTFLOAT buffer[BUFFER_SIZE * snd_info.channels];
            sample_read reader;
            if (sizeof(FAUSTFLOAT) == 4) {
                reader = reinterpret_cast<sample_read>(sf_readf_float);
            } else {
                reader = reinterpret_cast<sample_read>(sf_readf_double);
            }
            do {
                nbf = reader(snd_file, buffer, BUFFER_SIZE);
                for (int sample = 0; sample < nbf; sample++) {
                    for (int chan = 0; chan < fChannels; chan++) {
                        fBuffers[chan][index + sample] = buffer[sample * snd_info.channels + chan];
                    }
                }
                index += nbf;
            } while (nbf == BUFFER_SIZE);
            
            // Share the same buffers for all other channels so that we have max_chan channels available
            for (int chan = fChannels; chan < max_chan; chan++) {
                fBuffers[chan] = fBuffers[chan % snd_info.channels];
            }
       
            sf_close(snd_file);
            
        } else {
            
            if (path_name_str != "") {
                std::cerr << "Error opening the file : " << path_name_str << std::endl;
            }
            
            fChannels = 1;
            fLength = BUFFER_SIZE;
            fSampleRate = SAMPLE_RATE;
            
            // Allocate 1 channel
            fBuffers[0] = new FAUSTFLOAT[BUFFER_SIZE];
            if (!fBuffers[0]) {
                throw std::bad_alloc();
            }
            memset(fBuffers[0], 0, BUFFER_SIZE * sizeof(FAUSTFLOAT));
            
            // Share the same buffer for all other channels so that we have max_chan channels available
            for (int chan = fChannels; chan < max_chan; chan++) {
                fBuffers[chan] = fBuffers[0];
            }
        }
    }
    
    ~Soundfile()
    {
        // Free the real channels only
        for (int chan = 0; chan < fChannels; chan++) {
            delete fBuffers[chan];
        }
        delete [] fBuffers;
    }
    
} POST_PACKED_STRUCTURE;

#endif

// To be used by dsp code if no SoundUI is used or when soundfile is not found
extern "C" Soundfile* defaultsound = new Soundfile("", MAX_CHAN);

class SoundUI : public GenericUI
{
		
    private:
    
        std::vector<std::string> fSoundfileDir;        // The soundfile directories
        std::map<std::string, Soundfile*> fSFMap;      // Map to share loaded soundfiles
    
     public:
            
        SoundUI(const std::string& sound_directory = "")
        {
            fSoundfileDir.push_back(sound_directory);
        }
    
        SoundUI(const std::vector<std::string>& sound_directories):fSoundfileDir(sound_directories)
        {}
    
        virtual ~SoundUI()
        {   
            // delete all soundfiles
            std::map<std::string, Soundfile*>::iterator it;
            for (it = fSFMap.begin(); it != fSFMap.end(); it++) {
                delete (*it).second;
            }
        }

        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* file_name, Soundfile** sf_zone)
        {
            // If no filename was given, assume label is the filename
            std::string file_name_str;
            if (strlen(file_name) == 0) {
                file_name_str = label;
            } else {
                file_name_str = file_name;
            }
            
            std::string sha_key;
            std::string path_name_str = Soundfile::Check(fSoundfileDir, file_name_str, sha_key);
            if (path_name_str != "") {
                std::string file_key = (sha_key == "") ? path_name_str : sha_key;
                // Check if 'file_key' is already loaded
                if (fSFMap.find(file_key) == fSFMap.end()) {
                    fSFMap[file_key] = new Soundfile(path_name_str, 64);
                }
                // Get the soundfile
                *sf_zone = fSFMap[file_key];
            } else {
                // Take the defaultsound
                std::cout << "addSoundfile : defaultsound\n";
                *sf_zone = defaultsound;
            }
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
        return bundle_path_str;
    }
};

#endif
#endif

using namespace std;

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

double mydsp_faustpower2_f(double value) {
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
	double fRec0[2];
	int fSamplingFreq;
	int iConst0;
	double fConst1;
	FAUSTFLOAT fHslider1;
	double fRec1[2];
	double fRec2[3];
	FAUSTFLOAT fHslider2;
	double fRec3[2];
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	double fConst8;
	double fConst9;
	double fConst10;
	double fRec19[3];
	double fRec20[3];
	double fRec21[3];
	double fRec22[3];
	double fRec23[3];
	double fRec24[3];
	double fRec25[3];
	double fRec26[3];
	double fRec27[3];
	double fRec28[3];
	double fRec29[3];
	double fConst11;
	double fConst12;
	double fRec18[2];
	double fRec16[2];
	double fRec15[2];
	double fRec13[2];
	double fRec12[2];
	double fRec10[2];
	double fRec9[2];
	double fRec7[2];
	double fRec6[2];
	double fRec4[2];
	double fConst13;
	double fConst14;
	double fConst15;
	double fConst16;
	double fConst17;
	double fRec42[3];
	double fRec43[3];
	double fRec44[3];
	double fRec45[3];
	double fRec46[3];
	double fRec47[3];
	double fRec48[3];
	double fRec49[3];
	double fRec50[3];
	double fConst18;
	double fConst19;
	double fRec41[2];
	double fRec39[2];
	double fRec38[2];
	double fRec36[2];
	double fRec35[2];
	double fRec33[2];
	double fRec32[2];
	double fRec30[2];
	double fConst20;
	double fConst21;
	double fConst22;
	double fConst23;
	double fRec60[3];
	double fRec61[3];
	double fRec62[3];
	double fRec63[3];
	double fRec64[3];
	double fRec65[3];
	double fRec66[3];
	double fConst24;
	double fConst25;
	double fRec59[2];
	double fRec57[2];
	double fRec56[2];
	double fRec54[2];
	double fRec53[2];
	double fRec51[2];
	double fConst26;
	double fConst27;
	double fRec70[3];
	double fRec71[3];
	double fRec72[3];
	double fConst28;
	double fRec69[2];
	double fRec67[2];
	double fConst29;
	double fConst30;
	double fRec79[3];
	double fRec80[3];
	double fRec81[3];
	double fRec82[3];
	double fRec83[3];
	double fConst31;
	double fConst32;
	double fRec78[2];
	double fRec76[2];
	double fRec75[2];
	double fRec73[2];
	int IOTA;
	double fVec0[128];
	int iConst33;
	double fConst34;
	double fConst35;
	double fConst36;
	double fConst37;
	double fConst38;
	double fConst39;
	double fConst40;
	double fConst41;
	double fConst42;
	double fRec98[2];
	double fRec96[2];
	double fRec95[2];
	double fRec93[2];
	double fRec92[2];
	double fRec90[2];
	double fRec89[2];
	double fRec87[2];
	double fRec86[2];
	double fRec84[2];
	double fConst43;
	double fConst44;
	double fConst45;
	double fConst46;
	double fConst47;
	double fConst48;
	double fConst49;
	double fRec110[2];
	double fRec108[2];
	double fRec107[2];
	double fRec105[2];
	double fRec104[2];
	double fRec102[2];
	double fRec101[2];
	double fRec99[2];
	double fConst50;
	double fConst51;
	double fConst52;
	double fConst53;
	double fConst54;
	double fConst55;
	double fRec119[2];
	double fRec117[2];
	double fRec116[2];
	double fRec114[2];
	double fRec113[2];
	double fRec111[2];
	double fConst56;
	double fConst57;
	double fConst58;
	double fRec122[2];
	double fRec120[2];
	double fConst59;
	double fConst60;
	double fConst61;
	double fConst62;
	double fRec128[2];
	double fRec126[2];
	double fRec125[2];
	double fRec123[2];
	double fVec1[128];
	int iConst63;
	double fRec143[2];
	double fRec141[2];
	double fRec140[2];
	double fRec138[2];
	double fRec137[2];
	double fRec135[2];
	double fRec134[2];
	double fRec132[2];
	double fRec131[2];
	double fRec129[2];
	double fRec155[2];
	double fRec153[2];
	double fRec152[2];
	double fRec150[2];
	double fRec149[2];
	double fRec147[2];
	double fRec146[2];
	double fRec144[2];
	double fRec164[2];
	double fRec162[2];
	double fRec161[2];
	double fRec159[2];
	double fRec158[2];
	double fRec156[2];
	double fRec167[2];
	double fRec165[2];
	double fRec173[2];
	double fRec171[2];
	double fRec170[2];
	double fRec168[2];
	double fVec2[128];
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fConst68;
	double fConst69;
	double fConst70;
	double fConst71;
	double fConst72;
	double fRec188[2];
	double fRec186[2];
	double fRec185[2];
	double fRec183[2];
	double fRec182[2];
	double fRec180[2];
	double fRec179[2];
	double fRec177[2];
	double fRec176[2];
	double fRec174[2];
	double fConst73;
	double fConst74;
	double fConst75;
	double fConst76;
	double fConst77;
	double fConst78;
	double fConst79;
	double fRec200[2];
	double fRec198[2];
	double fRec197[2];
	double fRec195[2];
	double fRec194[2];
	double fRec192[2];
	double fRec191[2];
	double fRec189[2];
	double fConst80;
	double fConst81;
	double fConst82;
	double fConst83;
	double fConst84;
	double fConst85;
	double fRec209[2];
	double fRec207[2];
	double fRec206[2];
	double fRec204[2];
	double fRec203[2];
	double fRec201[2];
	double fConst86;
	double fConst87;
	double fConst88;
	double fRec212[2];
	double fRec210[2];
	double fConst89;
	double fConst90;
	double fConst91;
	double fConst92;
	double fRec218[2];
	double fRec216[2];
	double fRec215[2];
	double fRec213[2];
	double fVec3[128];
	int iConst93;
	double fRec233[2];
	double fRec231[2];
	double fRec230[2];
	double fRec228[2];
	double fRec227[2];
	double fRec225[2];
	double fRec224[2];
	double fRec222[2];
	double fRec221[2];
	double fRec219[2];
	double fRec245[2];
	double fRec243[2];
	double fRec242[2];
	double fRec240[2];
	double fRec239[2];
	double fRec237[2];
	double fRec236[2];
	double fRec234[2];
	double fRec254[2];
	double fRec252[2];
	double fRec251[2];
	double fRec249[2];
	double fRec248[2];
	double fRec246[2];
	double fRec257[2];
	double fRec255[2];
	double fRec263[2];
	double fRec261[2];
	double fRec260[2];
	double fRec258[2];
	double fVec4[128];
	double fRec269[2];
	double fRec267[2];
	double fRec266[2];
	double fRec264[2];
	double fRec272[2];
	double fRec270[2];
	double fRec287[2];
	double fRec285[2];
	double fRec284[2];
	double fRec282[2];
	double fRec281[2];
	double fRec279[2];
	double fRec278[2];
	double fRec276[2];
	double fRec275[2];
	double fRec273[2];
	double fRec296[2];
	double fRec294[2];
	double fRec293[2];
	double fRec291[2];
	double fRec290[2];
	double fRec288[2];
	double fRec308[2];
	double fRec306[2];
	double fRec305[2];
	double fRec303[2];
	double fRec302[2];
	double fRec300[2];
	double fRec299[2];
	double fRec297[2];
	double fVec5[128];
	double fRec323[2];
	double fRec321[2];
	double fRec320[2];
	double fRec318[2];
	double fRec317[2];
	double fRec315[2];
	double fRec314[2];
	double fRec312[2];
	double fRec311[2];
	double fRec309[2];
	double fRec335[2];
	double fRec333[2];
	double fRec332[2];
	double fRec330[2];
	double fRec329[2];
	double fRec327[2];
	double fRec326[2];
	double fRec324[2];
	double fRec344[2];
	double fRec342[2];
	double fRec341[2];
	double fRec339[2];
	double fRec338[2];
	double fRec336[2];
	double fRec347[2];
	double fRec345[2];
	double fRec353[2];
	double fRec351[2];
	double fRec350[2];
	double fRec348[2];
	double fVec6[128];
	double fRec368[2];
	double fRec366[2];
	double fRec365[2];
	double fRec363[2];
	double fRec362[2];
	double fRec360[2];
	double fRec359[2];
	double fRec357[2];
	double fRec356[2];
	double fRec354[2];
	double fRec380[2];
	double fRec378[2];
	double fRec377[2];
	double fRec375[2];
	double fRec374[2];
	double fRec372[2];
	double fRec371[2];
	double fRec369[2];
	double fRec389[2];
	double fRec387[2];
	double fRec386[2];
	double fRec384[2];
	double fRec383[2];
	double fRec381[2];
	double fRec392[2];
	double fRec390[2];
	double fRec398[2];
	double fRec396[2];
	double fRec395[2];
	double fRec393[2];
	double fVec7[128];
	double fRec413[2];
	double fRec411[2];
	double fRec410[2];
	double fRec408[2];
	double fRec407[2];
	double fRec405[2];
	double fRec404[2];
	double fRec402[2];
	double fRec401[2];
	double fRec399[2];
	double fRec425[2];
	double fRec423[2];
	double fRec422[2];
	double fRec420[2];
	double fRec419[2];
	double fRec417[2];
	double fRec416[2];
	double fRec414[2];
	double fRec434[2];
	double fRec432[2];
	double fRec431[2];
	double fRec429[2];
	double fRec428[2];
	double fRec426[2];
	double fRec437[2];
	double fRec435[2];
	double fRec443[2];
	double fRec441[2];
	double fRec440[2];
	double fRec438[2];
	double fVec8[128];
	double fRec458[2];
	double fRec456[2];
	double fRec455[2];
	double fRec453[2];
	double fRec452[2];
	double fRec450[2];
	double fRec449[2];
	double fRec447[2];
	double fRec446[2];
	double fRec444[2];
	double fRec470[2];
	double fRec468[2];
	double fRec467[2];
	double fRec465[2];
	double fRec464[2];
	double fRec462[2];
	double fRec461[2];
	double fRec459[2];
	double fRec479[2];
	double fRec477[2];
	double fRec476[2];
	double fRec474[2];
	double fRec473[2];
	double fRec471[2];
	double fRec482[2];
	double fRec480[2];
	double fRec488[2];
	double fRec486[2];
	double fRec485[2];
	double fRec483[2];
	double fVec9[128];
	double fRec503[2];
	double fRec501[2];
	double fRec500[2];
	double fRec498[2];
	double fRec497[2];
	double fRec495[2];
	double fRec494[2];
	double fRec492[2];
	double fRec491[2];
	double fRec489[2];
	double fRec515[2];
	double fRec513[2];
	double fRec512[2];
	double fRec510[2];
	double fRec509[2];
	double fRec507[2];
	double fRec506[2];
	double fRec504[2];
	double fRec524[2];
	double fRec522[2];
	double fRec521[2];
	double fRec519[2];
	double fRec518[2];
	double fRec516[2];
	double fRec527[2];
	double fRec525[2];
	double fRec533[2];
	double fRec531[2];
	double fRec530[2];
	double fRec528[2];
	double fVec10[128];
	double fRec548[2];
	double fRec546[2];
	double fRec545[2];
	double fRec543[2];
	double fRec542[2];
	double fRec540[2];
	double fRec539[2];
	double fRec537[2];
	double fRec536[2];
	double fRec534[2];
	double fRec560[2];
	double fRec558[2];
	double fRec557[2];
	double fRec555[2];
	double fRec554[2];
	double fRec552[2];
	double fRec551[2];
	double fRec549[2];
	double fRec569[2];
	double fRec567[2];
	double fRec566[2];
	double fRec564[2];
	double fRec563[2];
	double fRec561[2];
	double fRec572[2];
	double fRec570[2];
	double fRec578[2];
	double fRec576[2];
	double fRec575[2];
	double fRec573[2];
	double fVec11[128];
	double fRec593[2];
	double fRec591[2];
	double fRec590[2];
	double fRec588[2];
	double fRec587[2];
	double fRec585[2];
	double fRec584[2];
	double fRec582[2];
	double fRec581[2];
	double fRec579[2];
	double fRec605[2];
	double fRec603[2];
	double fRec602[2];
	double fRec600[2];
	double fRec599[2];
	double fRec597[2];
	double fRec596[2];
	double fRec594[2];
	double fRec614[2];
	double fRec612[2];
	double fRec611[2];
	double fRec609[2];
	double fRec608[2];
	double fRec606[2];
	double fRec617[2];
	double fRec615[2];
	double fRec623[2];
	double fRec621[2];
	double fRec620[2];
	double fRec618[2];
	double fVec12[128];
	double fRec638[2];
	double fRec636[2];
	double fRec635[2];
	double fRec633[2];
	double fRec632[2];
	double fRec630[2];
	double fRec629[2];
	double fRec627[2];
	double fRec626[2];
	double fRec624[2];
	double fRec650[2];
	double fRec648[2];
	double fRec647[2];
	double fRec645[2];
	double fRec644[2];
	double fRec642[2];
	double fRec641[2];
	double fRec639[2];
	double fRec659[2];
	double fRec657[2];
	double fRec656[2];
	double fRec654[2];
	double fRec653[2];
	double fRec651[2];
	double fRec662[2];
	double fRec660[2];
	double fRec668[2];
	double fRec666[2];
	double fRec665[2];
	double fRec663[2];
	double fVec13[128];
	double fRec683[2];
	double fRec681[2];
	double fRec680[2];
	double fRec678[2];
	double fRec677[2];
	double fRec675[2];
	double fRec674[2];
	double fRec672[2];
	double fRec671[2];
	double fRec669[2];
	double fRec695[2];
	double fRec693[2];
	double fRec692[2];
	double fRec690[2];
	double fRec689[2];
	double fRec687[2];
	double fRec686[2];
	double fRec684[2];
	double fRec704[2];
	double fRec702[2];
	double fRec701[2];
	double fRec699[2];
	double fRec698[2];
	double fRec696[2];
	double fRec707[2];
	double fRec705[2];
	double fRec713[2];
	double fRec711[2];
	double fRec710[2];
	double fRec708[2];
	double fVec14[128];
	double fRec728[2];
	double fRec726[2];
	double fRec725[2];
	double fRec723[2];
	double fRec722[2];
	double fRec720[2];
	double fRec719[2];
	double fRec717[2];
	double fRec716[2];
	double fRec714[2];
	double fRec740[2];
	double fRec738[2];
	double fRec737[2];
	double fRec735[2];
	double fRec734[2];
	double fRec732[2];
	double fRec731[2];
	double fRec729[2];
	double fRec749[2];
	double fRec747[2];
	double fRec746[2];
	double fRec744[2];
	double fRec743[2];
	double fRec741[2];
	double fRec752[2];
	double fRec750[2];
	double fRec758[2];
	double fRec756[2];
	double fRec755[2];
	double fRec753[2];
	double fVec15[128];
	double fConst94;
	double fConst95;
	double fConst96;
	double fConst97;
	double fConst98;
	double fConst99;
	double fConst100;
	double fConst101;
	double fConst102;
	double fRec773[2];
	double fRec771[2];
	double fRec770[2];
	double fRec768[2];
	double fRec767[2];
	double fRec765[2];
	double fRec764[2];
	double fRec762[2];
	double fRec761[2];
	double fRec759[2];
	double fConst103;
	double fConst104;
	double fConst105;
	double fConst106;
	double fConst107;
	double fConst108;
	double fConst109;
	double fRec785[2];
	double fRec783[2];
	double fRec782[2];
	double fRec780[2];
	double fRec779[2];
	double fRec777[2];
	double fRec776[2];
	double fRec774[2];
	double fConst110;
	double fConst111;
	double fConst112;
	double fConst113;
	double fConst114;
	double fConst115;
	double fRec794[2];
	double fRec792[2];
	double fRec791[2];
	double fRec789[2];
	double fRec788[2];
	double fRec786[2];
	double fConst116;
	double fConst117;
	double fConst118;
	double fRec797[2];
	double fRec795[2];
	double fConst119;
	double fConst120;
	double fConst121;
	double fConst122;
	double fRec803[2];
	double fRec801[2];
	double fRec800[2];
	double fRec798[2];
	double fVec16[128];
	int iConst123;
	double fRec818[2];
	double fRec816[2];
	double fRec815[2];
	double fRec813[2];
	double fRec812[2];
	double fRec810[2];
	double fRec809[2];
	double fRec807[2];
	double fRec806[2];
	double fRec804[2];
	double fRec830[2];
	double fRec828[2];
	double fRec827[2];
	double fRec825[2];
	double fRec824[2];
	double fRec822[2];
	double fRec821[2];
	double fRec819[2];
	double fRec839[2];
	double fRec837[2];
	double fRec836[2];
	double fRec834[2];
	double fRec833[2];
	double fRec831[2];
	double fRec842[2];
	double fRec840[2];
	double fRec848[2];
	double fRec846[2];
	double fRec845[2];
	double fRec843[2];
	double fVec17[128];
	double fRec863[2];
	double fRec861[2];
	double fRec860[2];
	double fRec858[2];
	double fRec857[2];
	double fRec855[2];
	double fRec854[2];
	double fRec852[2];
	double fRec851[2];
	double fRec849[2];
	double fRec875[2];
	double fRec873[2];
	double fRec872[2];
	double fRec870[2];
	double fRec869[2];
	double fRec867[2];
	double fRec866[2];
	double fRec864[2];
	double fRec884[2];
	double fRec882[2];
	double fRec881[2];
	double fRec879[2];
	double fRec878[2];
	double fRec876[2];
	double fRec887[2];
	double fRec885[2];
	double fRec893[2];
	double fRec891[2];
	double fRec890[2];
	double fRec888[2];
	double fVec18[128];
	double fRec908[2];
	double fRec906[2];
	double fRec905[2];
	double fRec903[2];
	double fRec902[2];
	double fRec900[2];
	double fRec899[2];
	double fRec897[2];
	double fRec896[2];
	double fRec894[2];
	double fRec920[2];
	double fRec918[2];
	double fRec917[2];
	double fRec915[2];
	double fRec914[2];
	double fRec912[2];
	double fRec911[2];
	double fRec909[2];
	double fRec929[2];
	double fRec927[2];
	double fRec926[2];
	double fRec924[2];
	double fRec923[2];
	double fRec921[2];
	double fRec932[2];
	double fRec930[2];
	double fRec938[2];
	double fRec936[2];
	double fRec935[2];
	double fRec933[2];
	double fVec19[128];
	double fRec953[2];
	double fRec951[2];
	double fRec950[2];
	double fRec948[2];
	double fRec947[2];
	double fRec945[2];
	double fRec944[2];
	double fRec942[2];
	double fRec941[2];
	double fRec939[2];
	double fRec965[2];
	double fRec963[2];
	double fRec962[2];
	double fRec960[2];
	double fRec959[2];
	double fRec957[2];
	double fRec956[2];
	double fRec954[2];
	double fRec974[2];
	double fRec972[2];
	double fRec971[2];
	double fRec969[2];
	double fRec968[2];
	double fRec966[2];
	double fRec977[2];
	double fRec975[2];
	double fRec983[2];
	double fRec981[2];
	double fRec980[2];
	double fRec978[2];
	double fVec20[128];
	double fRec998[2];
	double fRec996[2];
	double fRec995[2];
	double fRec993[2];
	double fRec992[2];
	double fRec990[2];
	double fRec989[2];
	double fRec987[2];
	double fRec986[2];
	double fRec984[2];
	double fRec1010[2];
	double fRec1008[2];
	double fRec1007[2];
	double fRec1005[2];
	double fRec1004[2];
	double fRec1002[2];
	double fRec1001[2];
	double fRec999[2];
	double fRec1019[2];
	double fRec1017[2];
	double fRec1016[2];
	double fRec1014[2];
	double fRec1013[2];
	double fRec1011[2];
	double fRec1022[2];
	double fRec1020[2];
	double fRec1028[2];
	double fRec1026[2];
	double fRec1025[2];
	double fRec1023[2];
	double fVec21[128];
	double fRec1043[2];
	double fRec1041[2];
	double fRec1040[2];
	double fRec1038[2];
	double fRec1037[2];
	double fRec1035[2];
	double fRec1034[2];
	double fRec1032[2];
	double fRec1031[2];
	double fRec1029[2];
	double fRec1055[2];
	double fRec1053[2];
	double fRec1052[2];
	double fRec1050[2];
	double fRec1049[2];
	double fRec1047[2];
	double fRec1046[2];
	double fRec1044[2];
	double fRec1064[2];
	double fRec1062[2];
	double fRec1061[2];
	double fRec1059[2];
	double fRec1058[2];
	double fRec1056[2];
	double fRec1067[2];
	double fRec1065[2];
	double fRec1073[2];
	double fRec1071[2];
	double fRec1070[2];
	double fRec1068[2];
	double fVec22[128];
	double fRec1088[2];
	double fRec1086[2];
	double fRec1085[2];
	double fRec1083[2];
	double fRec1082[2];
	double fRec1080[2];
	double fRec1079[2];
	double fRec1077[2];
	double fRec1076[2];
	double fRec1074[2];
	double fRec1100[2];
	double fRec1098[2];
	double fRec1097[2];
	double fRec1095[2];
	double fRec1094[2];
	double fRec1092[2];
	double fRec1091[2];
	double fRec1089[2];
	double fRec1109[2];
	double fRec1107[2];
	double fRec1106[2];
	double fRec1104[2];
	double fRec1103[2];
	double fRec1101[2];
	double fRec1112[2];
	double fRec1110[2];
	double fRec1118[2];
	double fRec1116[2];
	double fRec1115[2];
	double fRec1113[2];
	double fVec23[128];
	double fConst124;
	double fConst125;
	double fConst126;
	double fConst127;
	double fConst128;
	double fConst129;
	double fConst130;
	double fConst131;
	double fConst132;
	double fRec1133[2];
	double fRec1131[2];
	double fRec1130[2];
	double fRec1128[2];
	double fRec1127[2];
	double fRec1125[2];
	double fRec1124[2];
	double fRec1122[2];
	double fRec1121[2];
	double fRec1119[2];
	double fConst133;
	double fConst134;
	double fConst135;
	double fConst136;
	double fConst137;
	double fConst138;
	double fConst139;
	double fRec1145[2];
	double fRec1143[2];
	double fRec1142[2];
	double fRec1140[2];
	double fRec1139[2];
	double fRec1137[2];
	double fRec1136[2];
	double fRec1134[2];
	double fConst140;
	double fConst141;
	double fConst142;
	double fConst143;
	double fConst144;
	double fConst145;
	double fRec1154[2];
	double fRec1152[2];
	double fRec1151[2];
	double fRec1149[2];
	double fRec1148[2];
	double fRec1146[2];
	double fConst146;
	double fConst147;
	double fConst148;
	double fRec1157[2];
	double fRec1155[2];
	double fConst149;
	double fConst150;
	double fConst151;
	double fConst152;
	double fRec1163[2];
	double fRec1161[2];
	double fRec1160[2];
	double fRec1158[2];
	double fVec24[12];
	int iConst153;
	double fRec1178[2];
	double fRec1176[2];
	double fRec1175[2];
	double fRec1173[2];
	double fRec1172[2];
	double fRec1170[2];
	double fRec1169[2];
	double fRec1167[2];
	double fRec1166[2];
	double fRec1164[2];
	double fRec1190[2];
	double fRec1188[2];
	double fRec1187[2];
	double fRec1185[2];
	double fRec1184[2];
	double fRec1182[2];
	double fRec1181[2];
	double fRec1179[2];
	double fRec1199[2];
	double fRec1197[2];
	double fRec1196[2];
	double fRec1194[2];
	double fRec1193[2];
	double fRec1191[2];
	double fRec1202[2];
	double fRec1200[2];
	double fRec1208[2];
	double fRec1206[2];
	double fRec1205[2];
	double fRec1203[2];
	double fVec25[12];
	double fRec1223[2];
	double fRec1221[2];
	double fRec1220[2];
	double fRec1218[2];
	double fRec1217[2];
	double fRec1215[2];
	double fRec1214[2];
	double fRec1212[2];
	double fRec1211[2];
	double fRec1209[2];
	double fRec1235[2];
	double fRec1233[2];
	double fRec1232[2];
	double fRec1230[2];
	double fRec1229[2];
	double fRec1227[2];
	double fRec1226[2];
	double fRec1224[2];
	double fRec1244[2];
	double fRec1242[2];
	double fRec1241[2];
	double fRec1239[2];
	double fRec1238[2];
	double fRec1236[2];
	double fRec1247[2];
	double fRec1245[2];
	double fRec1253[2];
	double fRec1251[2];
	double fRec1250[2];
	double fRec1248[2];
	double fVec26[12];
	double fRec1268[2];
	double fRec1266[2];
	double fRec1265[2];
	double fRec1263[2];
	double fRec1262[2];
	double fRec1260[2];
	double fRec1259[2];
	double fRec1257[2];
	double fRec1256[2];
	double fRec1254[2];
	double fRec1280[2];
	double fRec1278[2];
	double fRec1277[2];
	double fRec1275[2];
	double fRec1274[2];
	double fRec1272[2];
	double fRec1271[2];
	double fRec1269[2];
	double fRec1289[2];
	double fRec1287[2];
	double fRec1286[2];
	double fRec1284[2];
	double fRec1283[2];
	double fRec1281[2];
	double fRec1292[2];
	double fRec1290[2];
	double fRec1298[2];
	double fRec1296[2];
	double fRec1295[2];
	double fRec1293[2];
	double fVec27[12];
	double fConst154;
	double fConst155;
	double fConst156;
	double fConst157;
	double fConst158;
	double fConst159;
	double fConst160;
	double fConst161;
	double fConst162;
	double fRec1313[2];
	double fRec1311[2];
	double fRec1310[2];
	double fRec1308[2];
	double fRec1307[2];
	double fRec1305[2];
	double fRec1304[2];
	double fRec1302[2];
	double fRec1301[2];
	double fRec1299[2];
	double fConst163;
	double fConst164;
	double fConst165;
	double fConst166;
	double fConst167;
	double fConst168;
	double fConst169;
	double fRec1325[2];
	double fRec1323[2];
	double fRec1322[2];
	double fRec1320[2];
	double fRec1319[2];
	double fRec1317[2];
	double fRec1316[2];
	double fRec1314[2];
	double fConst170;
	double fConst171;
	double fConst172;
	double fConst173;
	double fConst174;
	double fConst175;
	double fRec1334[2];
	double fRec1332[2];
	double fRec1331[2];
	double fRec1329[2];
	double fRec1328[2];
	double fRec1326[2];
	double fConst176;
	double fConst177;
	double fConst178;
	double fRec1337[2];
	double fRec1335[2];
	double fConst179;
	double fConst180;
	double fConst181;
	double fConst182;
	double fRec1343[2];
	double fRec1341[2];
	double fRec1340[2];
	double fRec1338[2];
	double fConst183;
	double fConst184;
	double fConst185;
	double fConst186;
	double fConst187;
	double fConst188;
	double fConst189;
	double fConst190;
	double fConst191;
	double fRec1358[2];
	double fRec1356[2];
	double fRec1355[2];
	double fRec1353[2];
	double fRec1352[2];
	double fRec1350[2];
	double fRec1349[2];
	double fRec1347[2];
	double fRec1346[2];
	double fRec1344[2];
	double fConst192;
	double fConst193;
	double fConst194;
	double fConst195;
	double fConst196;
	double fConst197;
	double fConst198;
	double fRec1370[2];
	double fRec1368[2];
	double fRec1367[2];
	double fRec1365[2];
	double fRec1364[2];
	double fRec1362[2];
	double fRec1361[2];
	double fRec1359[2];
	double fConst199;
	double fConst200;
	double fConst201;
	double fConst202;
	double fConst203;
	double fConst204;
	double fRec1379[2];
	double fRec1377[2];
	double fRec1376[2];
	double fRec1374[2];
	double fRec1373[2];
	double fRec1371[2];
	double fConst205;
	double fConst206;
	double fConst207;
	double fRec1382[2];
	double fRec1380[2];
	double fConst208;
	double fConst209;
	double fConst210;
	double fConst211;
	double fRec1388[2];
	double fRec1386[2];
	double fRec1385[2];
	double fRec1383[2];
	double fVec28[512];
	int iConst212;
	double fConst213;
	double fConst214;
	double fConst215;
	double fConst216;
	double fConst217;
	double fConst218;
	double fConst219;
	double fConst220;
	double fConst221;
	double fRec1403[2];
	double fRec1401[2];
	double fRec1400[2];
	double fRec1398[2];
	double fRec1397[2];
	double fRec1395[2];
	double fRec1394[2];
	double fRec1392[2];
	double fRec1391[2];
	double fRec1389[2];
	double fConst222;
	double fConst223;
	double fConst224;
	double fConst225;
	double fConst226;
	double fConst227;
	double fConst228;
	double fRec1415[2];
	double fRec1413[2];
	double fRec1412[2];
	double fRec1410[2];
	double fRec1409[2];
	double fRec1407[2];
	double fRec1406[2];
	double fRec1404[2];
	double fConst229;
	double fConst230;
	double fConst231;
	double fConst232;
	double fConst233;
	double fConst234;
	double fRec1424[2];
	double fRec1422[2];
	double fRec1421[2];
	double fRec1419[2];
	double fRec1418[2];
	double fRec1416[2];
	double fConst235;
	double fConst236;
	double fConst237;
	double fRec1427[2];
	double fRec1425[2];
	double fConst238;
	double fConst239;
	double fConst240;
	double fConst241;
	double fRec1433[2];
	double fRec1431[2];
	double fRec1430[2];
	double fRec1428[2];
	double fVec29[512];
	int iConst242;
	double fRec1448[2];
	double fRec1446[2];
	double fRec1445[2];
	double fRec1443[2];
	double fRec1442[2];
	double fRec1440[2];
	double fRec1439[2];
	double fRec1437[2];
	double fRec1436[2];
	double fRec1434[2];
	double fRec1460[2];
	double fRec1458[2];
	double fRec1457[2];
	double fRec1455[2];
	double fRec1454[2];
	double fRec1452[2];
	double fRec1451[2];
	double fRec1449[2];
	double fRec1469[2];
	double fRec1467[2];
	double fRec1466[2];
	double fRec1464[2];
	double fRec1463[2];
	double fRec1461[2];
	double fRec1472[2];
	double fRec1470[2];
	double fRec1478[2];
	double fRec1476[2];
	double fRec1475[2];
	double fRec1473[2];
	double fVec30[512];
	double fRec1493[2];
	double fRec1491[2];
	double fRec1490[2];
	double fRec1488[2];
	double fRec1487[2];
	double fRec1485[2];
	double fRec1484[2];
	double fRec1482[2];
	double fRec1481[2];
	double fRec1479[2];
	double fRec1505[2];
	double fRec1503[2];
	double fRec1502[2];
	double fRec1500[2];
	double fRec1499[2];
	double fRec1497[2];
	double fRec1496[2];
	double fRec1494[2];
	double fRec1514[2];
	double fRec1512[2];
	double fRec1511[2];
	double fRec1509[2];
	double fRec1508[2];
	double fRec1506[2];
	double fRec1517[2];
	double fRec1515[2];
	double fRec1523[2];
	double fRec1521[2];
	double fRec1520[2];
	double fRec1518[2];
	double fVec31[512];
	double fRec1538[2];
	double fRec1536[2];
	double fRec1535[2];
	double fRec1533[2];
	double fRec1532[2];
	double fRec1530[2];
	double fRec1529[2];
	double fRec1527[2];
	double fRec1526[2];
	double fRec1524[2];
	double fRec1550[2];
	double fRec1548[2];
	double fRec1547[2];
	double fRec1545[2];
	double fRec1544[2];
	double fRec1542[2];
	double fRec1541[2];
	double fRec1539[2];
	double fRec1559[2];
	double fRec1557[2];
	double fRec1556[2];
	double fRec1554[2];
	double fRec1553[2];
	double fRec1551[2];
	double fRec1562[2];
	double fRec1560[2];
	double fRec1568[2];
	double fRec1566[2];
	double fRec1565[2];
	double fRec1563[2];
	double fVec32[512];
	double fRec1583[2];
	double fRec1581[2];
	double fRec1580[2];
	double fRec1578[2];
	double fRec1577[2];
	double fRec1575[2];
	double fRec1574[2];
	double fRec1572[2];
	double fRec1571[2];
	double fRec1569[2];
	double fRec1595[2];
	double fRec1593[2];
	double fRec1592[2];
	double fRec1590[2];
	double fRec1589[2];
	double fRec1587[2];
	double fRec1586[2];
	double fRec1584[2];
	double fRec1604[2];
	double fRec1602[2];
	double fRec1601[2];
	double fRec1599[2];
	double fRec1598[2];
	double fRec1596[2];
	double fRec1607[2];
	double fRec1605[2];
	double fRec1613[2];
	double fRec1611[2];
	double fRec1610[2];
	double fRec1608[2];
	double fVec33[512];
	double fRec1628[2];
	double fRec1626[2];
	double fRec1625[2];
	double fRec1623[2];
	double fRec1622[2];
	double fRec1620[2];
	double fRec1619[2];
	double fRec1617[2];
	double fRec1616[2];
	double fRec1614[2];
	double fRec1640[2];
	double fRec1638[2];
	double fRec1637[2];
	double fRec1635[2];
	double fRec1634[2];
	double fRec1632[2];
	double fRec1631[2];
	double fRec1629[2];
	double fRec1649[2];
	double fRec1647[2];
	double fRec1646[2];
	double fRec1644[2];
	double fRec1643[2];
	double fRec1641[2];
	double fRec1652[2];
	double fRec1650[2];
	double fRec1658[2];
	double fRec1656[2];
	double fRec1655[2];
	double fRec1653[2];
	double fVec34[512];
	double fRec1673[2];
	double fRec1671[2];
	double fRec1670[2];
	double fRec1668[2];
	double fRec1667[2];
	double fRec1665[2];
	double fRec1664[2];
	double fRec1662[2];
	double fRec1661[2];
	double fRec1659[2];
	double fRec1685[2];
	double fRec1683[2];
	double fRec1682[2];
	double fRec1680[2];
	double fRec1679[2];
	double fRec1677[2];
	double fRec1676[2];
	double fRec1674[2];
	double fRec1694[2];
	double fRec1692[2];
	double fRec1691[2];
	double fRec1689[2];
	double fRec1688[2];
	double fRec1686[2];
	double fRec1697[2];
	double fRec1695[2];
	double fRec1703[2];
	double fRec1701[2];
	double fRec1700[2];
	double fRec1698[2];
	double fVec35[512];
	double fRec1718[2];
	double fRec1716[2];
	double fRec1715[2];
	double fRec1713[2];
	double fRec1712[2];
	double fRec1710[2];
	double fRec1709[2];
	double fRec1707[2];
	double fRec1706[2];
	double fRec1704[2];
	double fRec1730[2];
	double fRec1728[2];
	double fRec1727[2];
	double fRec1725[2];
	double fRec1724[2];
	double fRec1722[2];
	double fRec1721[2];
	double fRec1719[2];
	double fRec1739[2];
	double fRec1737[2];
	double fRec1736[2];
	double fRec1734[2];
	double fRec1733[2];
	double fRec1731[2];
	double fRec1742[2];
	double fRec1740[2];
	double fRec1748[2];
	double fRec1746[2];
	double fRec1745[2];
	double fRec1743[2];
	double fVec36[512];
	double fRec1763[2];
	double fRec1761[2];
	double fRec1760[2];
	double fRec1758[2];
	double fRec1757[2];
	double fRec1755[2];
	double fRec1754[2];
	double fRec1752[2];
	double fRec1751[2];
	double fRec1749[2];
	double fRec1775[2];
	double fRec1773[2];
	double fRec1772[2];
	double fRec1770[2];
	double fRec1769[2];
	double fRec1767[2];
	double fRec1766[2];
	double fRec1764[2];
	double fRec1784[2];
	double fRec1782[2];
	double fRec1781[2];
	double fRec1779[2];
	double fRec1778[2];
	double fRec1776[2];
	double fRec1787[2];
	double fRec1785[2];
	double fRec1793[2];
	double fRec1791[2];
	double fRec1790[2];
	double fRec1788[2];
	double fVec37[512];
	double fRec1808[2];
	double fRec1806[2];
	double fRec1805[2];
	double fRec1803[2];
	double fRec1802[2];
	double fRec1800[2];
	double fRec1799[2];
	double fRec1797[2];
	double fRec1796[2];
	double fRec1794[2];
	double fRec1820[2];
	double fRec1818[2];
	double fRec1817[2];
	double fRec1815[2];
	double fRec1814[2];
	double fRec1812[2];
	double fRec1811[2];
	double fRec1809[2];
	double fRec1829[2];
	double fRec1827[2];
	double fRec1826[2];
	double fRec1824[2];
	double fRec1823[2];
	double fRec1821[2];
	double fRec1832[2];
	double fRec1830[2];
	double fRec1838[2];
	double fRec1836[2];
	double fRec1835[2];
	double fRec1833[2];
	double fVec38[512];
	double fRec1853[2];
	double fRec1851[2];
	double fRec1850[2];
	double fRec1848[2];
	double fRec1847[2];
	double fRec1845[2];
	double fRec1844[2];
	double fRec1842[2];
	double fRec1841[2];
	double fRec1839[2];
	double fRec1865[2];
	double fRec1863[2];
	double fRec1862[2];
	double fRec1860[2];
	double fRec1859[2];
	double fRec1857[2];
	double fRec1856[2];
	double fRec1854[2];
	double fRec1874[2];
	double fRec1872[2];
	double fRec1871[2];
	double fRec1869[2];
	double fRec1868[2];
	double fRec1866[2];
	double fRec1877[2];
	double fRec1875[2];
	double fRec1883[2];
	double fRec1881[2];
	double fRec1880[2];
	double fRec1878[2];
	double fVec39[512];
	double fRec1898[2];
	double fRec1896[2];
	double fRec1895[2];
	double fRec1893[2];
	double fRec1892[2];
	double fRec1890[2];
	double fRec1889[2];
	double fRec1887[2];
	double fRec1886[2];
	double fRec1884[2];
	double fRec1910[2];
	double fRec1908[2];
	double fRec1907[2];
	double fRec1905[2];
	double fRec1904[2];
	double fRec1902[2];
	double fRec1901[2];
	double fRec1899[2];
	double fRec1919[2];
	double fRec1917[2];
	double fRec1916[2];
	double fRec1914[2];
	double fRec1913[2];
	double fRec1911[2];
	double fRec1922[2];
	double fRec1920[2];
	double fRec1928[2];
	double fRec1926[2];
	double fRec1925[2];
	double fRec1923[2];
	double fVec40[512];
	double fRec1943[2];
	double fRec1941[2];
	double fRec1940[2];
	double fRec1938[2];
	double fRec1937[2];
	double fRec1935[2];
	double fRec1934[2];
	double fRec1932[2];
	double fRec1931[2];
	double fRec1929[2];
	double fRec1955[2];
	double fRec1953[2];
	double fRec1952[2];
	double fRec1950[2];
	double fRec1949[2];
	double fRec1947[2];
	double fRec1946[2];
	double fRec1944[2];
	double fRec1964[2];
	double fRec1962[2];
	double fRec1961[2];
	double fRec1959[2];
	double fRec1958[2];
	double fRec1956[2];
	double fRec1967[2];
	double fRec1965[2];
	double fRec1973[2];
	double fRec1971[2];
	double fRec1970[2];
	double fRec1968[2];
	double fVec41[512];
	double fRec1988[2];
	double fRec1986[2];
	double fRec1985[2];
	double fRec1983[2];
	double fRec1982[2];
	double fRec1980[2];
	double fRec1979[2];
	double fRec1977[2];
	double fRec1976[2];
	double fRec1974[2];
	double fRec2000[2];
	double fRec1998[2];
	double fRec1997[2];
	double fRec1995[2];
	double fRec1994[2];
	double fRec1992[2];
	double fRec1991[2];
	double fRec1989[2];
	double fRec2009[2];
	double fRec2007[2];
	double fRec2006[2];
	double fRec2004[2];
	double fRec2003[2];
	double fRec2001[2];
	double fRec2012[2];
	double fRec2010[2];
	double fRec2018[2];
	double fRec2016[2];
	double fRec2015[2];
	double fRec2013[2];
	double fVec42[512];
	double fRec2033[2];
	double fRec2031[2];
	double fRec2030[2];
	double fRec2028[2];
	double fRec2027[2];
	double fRec2025[2];
	double fRec2024[2];
	double fRec2022[2];
	double fRec2021[2];
	double fRec2019[2];
	double fRec2045[2];
	double fRec2043[2];
	double fRec2042[2];
	double fRec2040[2];
	double fRec2039[2];
	double fRec2037[2];
	double fRec2036[2];
	double fRec2034[2];
	double fRec2054[2];
	double fRec2052[2];
	double fRec2051[2];
	double fRec2049[2];
	double fRec2048[2];
	double fRec2046[2];
	double fRec2057[2];
	double fRec2055[2];
	double fRec2063[2];
	double fRec2061[2];
	double fRec2060[2];
	double fRec2058[2];
	double fVec43[512];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMHLS_FullSetup_5h5v_full_6");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMHLS_FullSetup_5h5v_full_6");
		m->declare("version", "1.2");
	}

	virtual int getNumInputs() {
		return 36;
		
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
	
	static void classInit(int samplingFreq) {
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		iConst0 = std::min(192000, std::max(1, fSamplingFreq));
		fConst1 = (3.1415926535897931 / double(iConst0));
		fConst2 = double(iConst0);
		fConst3 = ((121.98966968986812 / fConst2) + 1.0);
		fConst4 = (0.0 - (243.97933937973625 / (fConst2 * fConst3)));
		fConst5 = mydsp_faustpower2_f(fConst2);
		fConst6 = ((((15971.154193732045 / fConst2) + 224.25739781362216) / fConst2) + 1.0);
		fConst7 = (0.0 - (63884.616774928181 / (fConst5 * fConst6)));
		fConst8 = (0.0 - (((63884.616774928181 / fConst2) + 448.51479562724433) / (fConst2 * fConst6)));
		fConst9 = ((((20317.232956903419 / fConst2) + 155.52869665231037) / fConst2) + 1.0);
		fConst10 = (1.0 / ((fConst3 * fConst6) * fConst9));
		fConst11 = (0.0 - (81268.931827613676 / (fConst5 * fConst9)));
		fConst12 = (0.0 - (((81268.931827613676 / fConst2) + 311.05739330462075) / (fConst2 * fConst9)));
		fConst13 = ((((10227.965605817382 / fConst2) + 193.7664384515102) / fConst2) + 1.0);
		fConst14 = (0.0 - (40911.862423269529 / (fConst5 * fConst13)));
		fConst15 = (0.0 - (((40911.862423269529 / fConst2) + 387.53287690302039) / (fConst2 * fConst13)));
		fConst16 = ((((12855.048748690073 / fConst2) + 140.75073765235712) / fConst2) + 1.0);
		fConst17 = (1.0 / (fConst13 * fConst16));
		fConst18 = (0.0 - (51420.194994760292 / (fConst5 * fConst16)));
		fConst19 = (0.0 - (((51420.194994760292 / fConst2) + 281.50147530471423) / (fConst2 * fConst16)));
		fConst20 = ((77.681088721927608 / fConst2) + 1.0);
		fConst21 = (0.0 - (155.36217744385522 / (fConst2 * fConst20)));
		fConst22 = ((((7228.2176497399441 / fConst2) + 123.02921694039281) / fConst2) + 1.0);
		fConst23 = (1.0 / (fConst20 * fConst22));
		fConst24 = (0.0 - (28912.870598959777 / (fConst5 * fConst22)));
		fConst25 = (0.0 - (((28912.870598959777 / fConst2) + 246.05843388078563) / (fConst2 * fConst22)));
		fConst26 = ((33.451717610386737 / fConst2) + 1.0);
		fConst27 = (1.0 / fConst26);
		fConst28 = (0.0 - (66.903435220773474 / (fConst2 * fConst26)));
		fConst29 = ((((3357.0522332551745 / fConst2) + 100.35515283116021) / fConst2) + 1.0);
		fConst30 = (1.0 / fConst29);
		fConst31 = (0.0 - (13428.208933020698 / (fConst5 * fConst29)));
		fConst32 = (0.0 - (((13428.208933020698 / fConst2) + 200.71030566232042) / (fConst2 * fConst29)));
		iConst33 = int(((0.00061186204235308644 * double(iConst0)) + 0.5));
		fConst34 = ((121.82343887658625 / fConst2) + 1.0);
		fConst35 = (0.0 - (243.6468777531725 / (fConst2 * fConst34)));
		fConst36 = ((((15927.657246953317 / fConst2) + 223.95181054776756) / fConst2) + 1.0);
		fConst37 = (0.0 - (63710.628987813267 / (fConst5 * fConst36)));
		fConst38 = (0.0 - (((63710.628987813267 / fConst2) + 447.90362109553513) / (fConst2 * fConst36)));
		fConst39 = ((((20261.899598406115 / fConst2) + 155.31676344682742) / fConst2) + 1.0);
		fConst40 = (1.0 / ((fConst34 * fConst36) * fConst39));
		fConst41 = (0.0 - (81047.598393624459 / (fConst5 * fConst39)));
		fConst42 = (0.0 - (((81047.598393624459 / fConst2) + 310.63352689365485) / (fConst2 * fConst39)));
		fConst43 = ((((10200.110056355246 / fConst2) + 193.50240008881593) / fConst2) + 1.0);
		fConst44 = (0.0 - (40800.440225420985 / (fConst5 * fConst43)));
		fConst45 = (0.0 - (((40800.440225420985 / fConst2) + 387.00480017763186) / (fConst2 * fConst43)));
		fConst46 = ((((12820.038419162405 / fConst2) + 140.55894182530508) / fConst2) + 1.0);
		fConst47 = (1.0 / (fConst43 * fConst46));
		fConst48 = (0.0 - (51280.153676649621 / (fConst5 * fConst46)));
		fConst49 = (0.0 - (((51280.153676649621 / fConst2) + 281.11788365061017) / (fConst2 * fConst46)));
		fConst50 = ((77.575235573970943 / fConst2) + 1.0);
		fConst51 = (0.0 - (155.15047114794189 / (fConst2 * fConst50)));
		fConst52 = ((((7208.5318214897106 / fConst2) + 122.8615695745017) / fConst2) + 1.0);
		fConst53 = (1.0 / (fConst50 * fConst52));
		fConst54 = (0.0 - (28834.127285958843 / (fConst5 * fConst52)));
		fConst55 = (0.0 - (((28834.127285958843 / fConst2) + 245.7231391490034) / (fConst2 * fConst52)));
		fConst56 = ((33.406134191412107 / fConst2) + 1.0);
		fConst57 = (1.0 / fConst56);
		fConst58 = (0.0 - (66.812268382824215 / (fConst2 * fConst56)));
		fConst59 = ((((3347.9094048438992 / fConst2) + 100.21840257423632) / fConst2) + 1.0);
		fConst60 = (1.0 / fConst59);
		fConst61 = (0.0 - (13391.637619375597 / (fConst5 * fConst59)));
		fConst62 = (0.0 - (((13391.637619375597 / fConst2) + 200.43680514847264) / (fConst2 * fConst59)));
		iConst63 = int(((0.00059146664094131783 * double(iConst0)) + 0.5));
		fConst64 = ((121.89462514784252 / fConst2) + 1.0);
		fConst65 = (0.0 - (243.78925029568504 / (fConst2 * fConst64)));
		fConst66 = ((((15946.277010289676 / fConst2) + 224.08267448069375) / fConst2) + 1.0);
		fConst67 = (0.0 - (63785.108041158703 / (fConst5 * fConst66)));
		fConst68 = (0.0 - (((63785.108041158703 / fConst2) + 448.16534896138751) / (fConst2 * fConst66)));
		fConst69 = ((((20285.586181399329 / fConst2) + 155.40752119718587) / fConst2) + 1.0);
		fConst70 = (1.0 / ((fConst64 * fConst66) * fConst69));
		fConst71 = (0.0 - (81142.344725597315 / (fConst5 * fConst69)));
		fConst72 = (0.0 - (((81142.344725597315 / fConst2) + 310.81504239437174) / (fConst2 * fConst69)));
		fConst73 = ((((10212.034197634121 / fConst2) + 193.6154712224868) / fConst2) + 1.0);
		fConst74 = (0.0 - (40848.136790536482 / (fConst5 * fConst73)));
		fConst75 = (0.0 - (((40848.136790536482 / fConst2) + 387.23094244497361) / (fConst2 * fConst73)));
		fConst76 = ((((12835.025311310244 / fConst2) + 140.64107599466149) / fConst2) + 1.0);
		fConst77 = (1.0 / (fConst73 * fConst76));
		fConst78 = (0.0 - (51340.101245240978 / (fConst5 * fConst76)));
		fConst79 = (0.0 - (((51340.101245240978 / fConst2) + 281.28215198932298) / (fConst2 * fConst76)));
		fConst80 = ((77.620565863554475 / fConst2) + 1.0);
		fConst81 = (0.0 - (155.24113172710895 / (fConst2 * fConst80)));
		fConst82 = ((((7216.9587454520797 / fConst2) + 122.93336246673454) / fConst2) + 1.0);
		fConst83 = (1.0 / (fConst80 * fConst82));
		fConst84 = (0.0 - (28867.834981808319 / (fConst5 * fConst82)));
		fConst85 = (0.0 - (((28867.834981808319 / fConst2) + 245.86672493346907) / (fConst2 * fConst82)));
		fConst86 = ((33.425654721714835 / fConst2) + 1.0);
		fConst87 = (1.0 / fConst86);
		fConst88 = (0.0 - (66.85130944342967 / (fConst2 * fConst86)));
		fConst89 = ((((3351.8231807258917 / fConst2) + 100.27696416514451) / fConst2) + 1.0);
		fConst90 = (1.0 / fConst89);
		fConst91 = (0.0 - (13407.292722903567 / (fConst5 * fConst89)));
		fConst92 = (0.0 - (((13407.292722903567 / fConst2) + 200.55392833028901) / (fConst2 * fConst89)));
		iConst93 = int(((0.00060020752726064536 * double(iConst0)) + 0.5));
		fConst94 = ((120.25499721541576 / fConst2) + 1.0);
		fConst95 = (0.0 - (240.50999443083151 / (fConst2 * fConst94)));
		fConst96 = ((((15520.169394656026 / fConst2) + 221.0684955387936) / fConst2) + 1.0);
		fConst97 = (0.0 - (62080.677578624105 / (fConst5 * fConst96)));
		fConst98 = (0.0 - (((62080.677578624105 / fConst2) + 442.1369910775872) / (fConst2 * fConst96)));
		fConst99 = ((((19743.525940384494 / fConst2) + 153.31710488592475) / fConst2) + 1.0);
		fConst100 = (1.0 / ((fConst94 * fConst96) * fConst99));
		fConst101 = (0.0 - (78974.103761537976 / (fConst5 * fConst99)));
		fConst102 = (0.0 - (((78974.103761537976 / fConst2) + 306.6342097718495) / (fConst2 * fConst99)));
		fConst103 = ((((9939.1538544721825 / fConst2) + 191.01111246276852) / fConst2) + 1.0);
		fConst104 = (0.0 - (39756.61541788873 / (fConst5 * fConst103)));
		fConst105 = (0.0 - (((39756.61541788873 / fConst2) + 382.02222492553705) / (fConst2 * fConst103)));
		fConst106 = ((((12492.054846889559 / fConst2) + 138.74928596398775) / fConst2) + 1.0);
		fConst107 = (1.0 / (fConst103 * fConst106));
		fConst108 = (0.0 - (49968.219387558238 / (fConst5 * fConst106)));
		fConst109 = (0.0 - (((49968.219387558238 / fConst2) + 277.49857192797549) / (fConst2 * fConst106)));
		fConst110 = ((76.576476776227651 / fConst2) + 1.0);
		fConst111 = (0.0 - (153.1529535524553 / (fConst2 * fConst110)));
		fConst112 = ((((7024.111155938449 / fConst2) + 121.27976227982614) / fConst2) + 1.0);
		fConst113 = (1.0 / (fConst110 * fConst112));
		fConst114 = (0.0 - (28096.444623753796 / (fConst5 * fConst112)));
		fConst115 = (0.0 - (((28096.444623753796 / fConst2) + 242.55952455965229) / (fConst2 * fConst112)));
		fConst116 = ((32.976039842675632 / fConst2) + 1.0);
		fConst117 = (1.0 / fConst116);
		fConst118 = (0.0 - (65.952079685351265 / (fConst2 * fConst116)));
		fConst119 = ((((3262.257611117192 / fConst2) + 98.928119528026897) / fConst2) + 1.0);
		fConst120 = (1.0 / fConst119);
		fConst121 = (0.0 - (13049.030444468768 / (fConst5 * fConst119)));
		fConst122 = (0.0 - (((13049.030444468768 / fConst2) + 197.85623905605379) / (fConst2 * fConst119)));
		iConst123 = int(((0.00039625351314295164 * double(iConst0)) + 0.5));
		fConst124 = ((117.61078848130494 / fConst2) + 1.0);
		fConst125 = (0.0 - (235.22157696260987 / (fConst2 * fConst124)));
		fConst126 = ((((14845.147428742359 / fConst2) + 216.20756451491863) / fConst2) + 1.0);
		fConst127 = (0.0 - (59380.589714969436 / (fConst5 * fConst126)));
		fConst128 = (0.0 - (((59380.589714969436 / fConst2) + 432.41512902983726) / (fConst2 * fConst126)));
		fConst129 = ((((18884.816646983691 / fConst2) + 149.94591502092698) / fConst2) + 1.0);
		fConst130 = (1.0 / ((fConst124 * fConst126) * fConst129));
		fConst131 = (0.0 - (75539.266587934762 / (fConst5 * fConst129)));
		fConst132 = (0.0 - (((75539.266587934762 / fConst2) + 299.89183004185395) / (fConst2 * fConst129)));
		fConst133 = ((((9506.8681619800409 / fConst2) + 186.81109363958794) / fConst2) + 1.0);
		fConst134 = (0.0 - (38027.472647920164 / (fConst5 * fConst133)));
		fConst135 = (0.0 - (((38027.472647920164 / fConst2) + 373.62218727917588) / (fConst2 * fConst133)));
		fConst136 = ((((11948.735298846983 / fConst2) + 135.69841837184595) / fConst2) + 1.0);
		fConst137 = (1.0 / (fConst133 * fConst136));
		fConst138 = (0.0 - (47794.941195387932 / (fConst5 * fConst136)));
		fConst139 = (0.0 - (((47794.941195387932 / fConst2) + 271.39683674369189) / (fConst2 * fConst136)));
		fConst140 = ((74.892686552055764 / fConst2) + 1.0);
		fConst141 = (0.0 - (149.78537310411153 / (fConst2 * fConst140)));
		fConst142 = ((((6718.6100237851942 / fConst2) + 118.6130206548046) / fConst2) + 1.0);
		fConst143 = (1.0 / (fConst140 * fConst142));
		fConst144 = (0.0 - (26874.440095140777 / (fConst5 * fConst142)));
		fConst145 = (0.0 - (((26874.440095140777 / fConst2) + 237.2260413096092) / (fConst2 * fConst142)));
		fConst146 = ((32.250951201143394 / fConst2) + 1.0);
		fConst147 = (1.0 / fConst146);
		fConst148 = (0.0 - (64.501902402286788 / (fConst2 * fConst146)));
		fConst149 = ((((3120.3715601355971 / fConst2) + 96.752853603430182) / fConst2) + 1.0);
		fConst150 = (1.0 / fConst149);
		fConst151 = (0.0 - (12481.486240542388 / (fConst5 * fConst149)));
		fConst152 = (0.0 - (((12481.486240542388 / fConst2) + 193.50570720686036) / (fConst2 * fConst149)));
		iConst153 = int(((5.5358946689089155e-05 * double(iConst0)) + 0.5));
		fConst154 = ((117.19232312903063 / fConst2) + 1.0);
		fConst155 = (0.0 - (234.38464625806125 / (fConst2 * fConst154)));
		fConst156 = ((((14739.69573850899 / fConst2) + 215.43828666364828) / fConst2) + 1.0);
		fConst157 = (0.0 - (58958.78295403596 / (fConst5 * fConst156)));
		fConst158 = (0.0 - (((58958.78295403596 / fConst2) + 430.87657332729657) / (fConst2 * fConst156)));
		fConst159 = ((((18750.669388107974 / fConst2) + 149.41239959294987) / fConst2) + 1.0);
		fConst160 = (1.0 / ((fConst154 * fConst156) * fConst159));
		fConst161 = (0.0 - (75002.677552431895 / (fConst5 * fConst159)));
		fConst162 = (0.0 - (((75002.677552431895 / fConst2) + 298.82479918589974) / (fConst2 * fConst159)));
		fConst163 = ((((9439.3366456162785 / fConst2) + 186.14640997308004) / fConst2) + 1.0);
		fConst164 = (0.0 - (37757.346582465114 / (fConst5 * fConst163)));
		fConst165 = (0.0 - (((37757.346582465114 / fConst2) + 372.29281994616008) / (fConst2 * fConst163)));
		fConst166 = ((((11863.858113257369 / fConst2) + 135.21559628400601) / fConst2) + 1.0);
		fConst167 = (1.0 / (fConst163 * fConst166));
		fConst168 = (0.0 - (47455.432453029476 / (fConst5 * fConst166)));
		fConst169 = (0.0 - (((47455.432453029476 / fConst2) + 270.43119256801202) / (fConst2 * fConst166)));
		fConst170 = ((74.626214446346196 / fConst2) + 1.0);
		fConst171 = (0.0 - (149.25242889269239 / (fConst2 * fConst170)));
		fConst172 = ((((6670.8847461193591 / fConst2) + 118.19098930790547) / fConst2) + 1.0);
		fConst173 = (1.0 / (fConst170 * fConst172));
		fConst174 = (0.0 - (26683.538984477436 / (fConst5 * fConst172)));
		fConst175 = (0.0 - (((26683.538984477436 / fConst2) + 236.38197861581094) / (fConst2 * fConst172)));
		fConst176 = ((32.136200625708611 / fConst2) + 1.0);
		fConst177 = (1.0 / fConst176);
		fConst178 = (0.0 - (64.272401251417222 / (fConst2 * fConst176)));
		fConst179 = ((((3098.2061719673839 / fConst2) + 96.408601877125832) / fConst2) + 1.0);
		fConst180 = (1.0 / fConst179);
		fConst181 = (0.0 - (12392.824687869535 / (fConst5 * fConst179)));
		fConst182 = (0.0 - (((12392.824687869535 / fConst2) + 192.81720375425166) / (fConst2 * fConst179)));
		fConst183 = ((133.71944562158623 / fConst2) + 1.0);
		fConst184 = (0.0 - (267.43889124317246 / (fConst2 * fConst183)));
		fConst185 = ((((19190.192298607777 / fConst2) + 245.82060914185513) / fConst2) + 1.0);
		fConst186 = (0.0 - (76760.769194431108 / (fConst5 * fConst185)));
		fConst187 = (0.0 - (((76760.769194431108 / fConst2) + 491.64121828371026) / (fConst2 * fConst185)));
		fConst188 = ((((24412.237380539653 / fConst2) + 170.48337902272488) / fConst2) + 1.0);
		fConst189 = (1.0 / ((fConst183 * fConst185) * fConst188));
		fConst190 = (0.0 - (97648.949522158611 / (fConst5 * fConst188)));
		fConst191 = (0.0 - (((97648.949522158611 / fConst2) + 340.96675804544975) / (fConst2 * fConst188)));
		fConst192 = ((((12289.445359948479 / fConst2) + 212.39782676415544) / fConst2) + 1.0);
		fConst193 = (0.0 - (49157.781439793915 / (fConst5 * fConst192)));
		fConst194 = (0.0 - (((49157.781439793915 / fConst2) + 424.79565352831088) / (fConst2 * fConst192)));
		fConst195 = ((((15446.025659946026 / fConst2) + 154.28446242662227) / fConst2) + 1.0);
		fConst196 = (1.0 / (fConst192 * fConst195));
		fConst197 = (0.0 - (61784.102639784105 / (fConst5 * fConst195)));
		fConst198 = (0.0 - (((61784.102639784105 / fConst2) + 308.56892485324454) / (fConst2 * fConst195)));
		fConst199 = ((85.150424175959131 / fConst2) + 1.0);
		fConst200 = (0.0 - (170.30084835191826 / (fConst199 * fConst2)));
		fConst201 = ((((8685.0884408302827 / fConst2) + 134.85894933850753) / fConst2) + 1.0);
		fConst202 = (1.0 / (fConst199 * fConst201));
		fConst203 = (0.0 - (34740.353763321131 / (fConst201 * fConst5)));
		fConst204 = (0.0 - (((34740.353763321131 / fConst2) + 269.71789867701506) / (fConst201 * fConst2)));
		fConst205 = ((36.668228919077777 / fConst2) + 1.0);
		fConst206 = (1.0 / fConst205);
		fConst207 = (0.0 - (73.336457838155553 / (fConst2 * fConst205)));
		fConst208 = ((((4033.6770361856752 / fConst2) + 110.00468675723333) / fConst2) + 1.0);
		fConst209 = (1.0 / fConst208);
		fConst210 = (0.0 - (16134.708144742701 / (fConst208 * fConst5)));
		fConst211 = (0.0 - (((16134.708144742701 / fConst2) + 220.00937351446666) / (fConst208 * fConst2)));
		iConst212 = int(((0.001922994990252558 * double(iConst0)) + 0.5));
		fConst213 = ((134.00578276424486 / fConst2) + 1.0);
		fConst214 = (0.0 - (268.01156552848971 / (fConst2 * fConst213)));
		fConst215 = ((((19272.465268813507 / fConst2) + 246.34699160254428) / fConst2) + 1.0);
		fConst216 = (0.0 - (77089.861075254026 / (fConst5 * fConst215)));
		fConst217 = (0.0 - (((77089.861075254026 / fConst2) + 492.69398320508856) / (fConst2 * fConst215)));
		fConst218 = ((((24516.898514071392 / fConst2) + 170.84843979151012) / fConst2) + 1.0);
		fConst219 = (1.0 / ((fConst213 * fConst215) * fConst218));
		fConst220 = (0.0 - (98067.594056285569 / (fConst5 * fConst218)));
		fConst221 = (0.0 - (((98067.594056285569 / fConst2) + 341.69687958302023) / (fConst2 * fConst218)));
		fConst222 = ((((12342.133168189845 / fConst2) + 212.8526400976975) / fConst2) + 1.0);
		fConst223 = (0.0 - (49368.532672759378 / (fConst5 * fConst222)));
		fConst224 = (0.0 - (((49368.532672759378 / fConst2) + 425.70528019539501) / (fConst2 * fConst222)));
		fConst225 = ((((15512.246487186505 / fConst2) + 154.61483600783558) / fConst2) + 1.0);
		fConst226 = (1.0 / (fConst222 * fConst225));
		fConst227 = (0.0 - (62048.98594874602 / (fConst5 * fConst225)));
		fConst228 = (0.0 - (((62048.98594874602 / fConst2) + 309.22967201567116) / (fConst2 * fConst225)));
		fConst229 = ((85.332759131368022 / fConst2) + 1.0);
		fConst230 = (0.0 - (170.66551826273604 / (fConst2 * fConst229)));
		fConst231 = ((((8722.3235040025465 / fConst2) + 135.14772653195186) / fConst2) + 1.0);
		fConst232 = (1.0 / (fConst229 * fConst231));
		fConst233 = (0.0 - (34889.294016010186 / (fConst5 * fConst231)));
		fConst234 = (0.0 - (((34889.294016010186 / fConst2) + 270.29545306390372) / (fConst2 * fConst231)));
		fConst235 = ((36.746747610553314 / fConst2) + 1.0);
		fConst236 = (1.0 / fConst235);
		fConst237 = (0.0 - (73.493495221106627 / (fConst2 * fConst235)));
		fConst238 = ((((4050.9703798611172 / fConst2) + 110.24024283165994) / fConst2) + 1.0);
		fConst239 = (1.0 / fConst238);
		fConst240 = (0.0 - (16203.881519444469 / (fConst5 * fConst238)));
		fConst241 = (0.0 - (((16203.881519444469 / fConst2) + 220.48048566331988) / (fConst2 * fConst238)));
		iConst242 = int(((0.0019521312779836569 * double(iConst0)) + 0.5));
		
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = FAUSTFLOAT(0.0);
		fHslider0 = FAUSTFLOAT(-10.0);
		fHslider1 = FAUSTFLOAT(400.0);
		fHslider2 = FAUSTFLOAT(0.0);
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0;
			
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0;
			
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0;
			
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec19[l4] = 0.0;
			
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec20[l5] = 0.0;
			
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec21[l6] = 0.0;
			
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec22[l7] = 0.0;
			
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec23[l8] = 0.0;
			
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec24[l9] = 0.0;
			
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec25[l10] = 0.0;
			
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec26[l11] = 0.0;
			
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec27[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec28[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec29[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec18[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec16[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec15[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec13[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec12[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec10[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec9[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec7[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec6[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec4[l24] = 0.0;
			
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec42[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec43[l26] = 0.0;
			
		}
		for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) {
			fRec44[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 3); l28 = (l28 + 1)) {
			fRec45[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 3); l29 = (l29 + 1)) {
			fRec46[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) {
			fRec47[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) {
			fRec48[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 3); l32 = (l32 + 1)) {
			fRec49[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 3); l33 = (l33 + 1)) {
			fRec50[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec41[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec39[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec38[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec36[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec35[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec33[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec32[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec30[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec60[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) {
			fRec61[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) {
			fRec62[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec63[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec64[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec65[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec66[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec59[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec57[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec56[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec54[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fRec53[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec51[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec70[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec71[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 3); l57 = (l57 + 1)) {
			fRec72[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec69[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec67[l59] = 0.0;
			
		}
		for (int l60 = 0; (l60 < 3); l60 = (l60 + 1)) {
			fRec79[l60] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 3); l61 = (l61 + 1)) {
			fRec80[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 3); l62 = (l62 + 1)) {
			fRec81[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 3); l63 = (l63 + 1)) {
			fRec82[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 3); l64 = (l64 + 1)) {
			fRec83[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec78[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec76[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec75[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec73[l68] = 0.0;
			
		}
		IOTA = 0;
		for (int l69 = 0; (l69 < 128); l69 = (l69 + 1)) {
			fVec0[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec98[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec96[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec95[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec93[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec92[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 2); l75 = (l75 + 1)) {
			fRec90[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec89[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec87[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec86[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fRec84[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec110[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec108[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec107[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fRec105[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec104[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec102[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec101[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 2); l87 = (l87 + 1)) {
			fRec99[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			fRec119[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec117[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec116[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec114[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec113[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec111[l93] = 0.0;
			
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec122[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec120[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fRec128[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec126[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec125[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec123[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 128); l100 = (l100 + 1)) {
			fVec1[l100] = 0.0;
			
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fRec143[l101] = 0.0;
			
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec141[l102] = 0.0;
			
		}
		for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) {
			fRec140[l103] = 0.0;
			
		}
		for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) {
			fRec138[l104] = 0.0;
			
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fRec137[l105] = 0.0;
			
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec135[l106] = 0.0;
			
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fRec134[l107] = 0.0;
			
		}
		for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) {
			fRec132[l108] = 0.0;
			
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec131[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec129[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec155[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec153[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec152[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec150[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec149[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec147[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec146[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec144[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec164[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec162[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec161[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec159[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec158[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec156[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fRec167[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec165[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec173[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec171[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec170[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec168[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 128); l131 = (l131 + 1)) {
			fVec2[l131] = 0.0;
			
		}
		for (int l132 = 0; (l132 < 2); l132 = (l132 + 1)) {
			fRec188[l132] = 0.0;
			
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec186[l133] = 0.0;
			
		}
		for (int l134 = 0; (l134 < 2); l134 = (l134 + 1)) {
			fRec185[l134] = 0.0;
			
		}
		for (int l135 = 0; (l135 < 2); l135 = (l135 + 1)) {
			fRec183[l135] = 0.0;
			
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec182[l136] = 0.0;
			
		}
		for (int l137 = 0; (l137 < 2); l137 = (l137 + 1)) {
			fRec180[l137] = 0.0;
			
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec179[l138] = 0.0;
			
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fRec177[l139] = 0.0;
			
		}
		for (int l140 = 0; (l140 < 2); l140 = (l140 + 1)) {
			fRec176[l140] = 0.0;
			
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fRec174[l141] = 0.0;
			
		}
		for (int l142 = 0; (l142 < 2); l142 = (l142 + 1)) {
			fRec200[l142] = 0.0;
			
		}
		for (int l143 = 0; (l143 < 2); l143 = (l143 + 1)) {
			fRec198[l143] = 0.0;
			
		}
		for (int l144 = 0; (l144 < 2); l144 = (l144 + 1)) {
			fRec197[l144] = 0.0;
			
		}
		for (int l145 = 0; (l145 < 2); l145 = (l145 + 1)) {
			fRec195[l145] = 0.0;
			
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fRec194[l146] = 0.0;
			
		}
		for (int l147 = 0; (l147 < 2); l147 = (l147 + 1)) {
			fRec192[l147] = 0.0;
			
		}
		for (int l148 = 0; (l148 < 2); l148 = (l148 + 1)) {
			fRec191[l148] = 0.0;
			
		}
		for (int l149 = 0; (l149 < 2); l149 = (l149 + 1)) {
			fRec189[l149] = 0.0;
			
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec209[l150] = 0.0;
			
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec207[l151] = 0.0;
			
		}
		for (int l152 = 0; (l152 < 2); l152 = (l152 + 1)) {
			fRec206[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec204[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec203[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec201[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec212[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec210[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec218[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec216[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec215[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec213[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 128); l162 = (l162 + 1)) {
			fVec3[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			fRec233[l163] = 0.0;
			
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			fRec231[l164] = 0.0;
			
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec230[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec228[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fRec227[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec225[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec224[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec222[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fRec221[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec219[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fRec245[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec243[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec242[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec240[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec239[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 2); l178 = (l178 + 1)) {
			fRec237[l178] = 0.0;
			
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec236[l179] = 0.0;
			
		}
		for (int l180 = 0; (l180 < 2); l180 = (l180 + 1)) {
			fRec234[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec254[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec252[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fRec251[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec249[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec248[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fRec246[l186] = 0.0;
			
		}
		for (int l187 = 0; (l187 < 2); l187 = (l187 + 1)) {
			fRec257[l187] = 0.0;
			
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec255[l188] = 0.0;
			
		}
		for (int l189 = 0; (l189 < 2); l189 = (l189 + 1)) {
			fRec263[l189] = 0.0;
			
		}
		for (int l190 = 0; (l190 < 2); l190 = (l190 + 1)) {
			fRec261[l190] = 0.0;
			
		}
		for (int l191 = 0; (l191 < 2); l191 = (l191 + 1)) {
			fRec260[l191] = 0.0;
			
		}
		for (int l192 = 0; (l192 < 2); l192 = (l192 + 1)) {
			fRec258[l192] = 0.0;
			
		}
		for (int l193 = 0; (l193 < 128); l193 = (l193 + 1)) {
			fVec4[l193] = 0.0;
			
		}
		for (int l194 = 0; (l194 < 2); l194 = (l194 + 1)) {
			fRec269[l194] = 0.0;
			
		}
		for (int l195 = 0; (l195 < 2); l195 = (l195 + 1)) {
			fRec267[l195] = 0.0;
			
		}
		for (int l196 = 0; (l196 < 2); l196 = (l196 + 1)) {
			fRec266[l196] = 0.0;
			
		}
		for (int l197 = 0; (l197 < 2); l197 = (l197 + 1)) {
			fRec264[l197] = 0.0;
			
		}
		for (int l198 = 0; (l198 < 2); l198 = (l198 + 1)) {
			fRec272[l198] = 0.0;
			
		}
		for (int l199 = 0; (l199 < 2); l199 = (l199 + 1)) {
			fRec270[l199] = 0.0;
			
		}
		for (int l200 = 0; (l200 < 2); l200 = (l200 + 1)) {
			fRec287[l200] = 0.0;
			
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fRec285[l201] = 0.0;
			
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec284[l202] = 0.0;
			
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fRec282[l203] = 0.0;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec281[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec279[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec278[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec276[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec275[l208] = 0.0;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec273[l209] = 0.0;
			
		}
		for (int l210 = 0; (l210 < 2); l210 = (l210 + 1)) {
			fRec296[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 2); l211 = (l211 + 1)) {
			fRec294[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec293[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec291[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fRec290[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 2); l215 = (l215 + 1)) {
			fRec288[l215] = 0.0;
			
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fRec308[l216] = 0.0;
			
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec306[l217] = 0.0;
			
		}
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fRec305[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec303[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fRec302[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec300[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec299[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec297[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 128); l224 = (l224 + 1)) {
			fVec5[l224] = 0.0;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec323[l225] = 0.0;
			
		}
		for (int l226 = 0; (l226 < 2); l226 = (l226 + 1)) {
			fRec321[l226] = 0.0;
			
		}
		for (int l227 = 0; (l227 < 2); l227 = (l227 + 1)) {
			fRec320[l227] = 0.0;
			
		}
		for (int l228 = 0; (l228 < 2); l228 = (l228 + 1)) {
			fRec318[l228] = 0.0;
			
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fRec317[l229] = 0.0;
			
		}
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec315[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fRec314[l231] = 0.0;
			
		}
		for (int l232 = 0; (l232 < 2); l232 = (l232 + 1)) {
			fRec312[l232] = 0.0;
			
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fRec311[l233] = 0.0;
			
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec309[l234] = 0.0;
			
		}
		for (int l235 = 0; (l235 < 2); l235 = (l235 + 1)) {
			fRec335[l235] = 0.0;
			
		}
		for (int l236 = 0; (l236 < 2); l236 = (l236 + 1)) {
			fRec333[l236] = 0.0;
			
		}
		for (int l237 = 0; (l237 < 2); l237 = (l237 + 1)) {
			fRec332[l237] = 0.0;
			
		}
		for (int l238 = 0; (l238 < 2); l238 = (l238 + 1)) {
			fRec330[l238] = 0.0;
			
		}
		for (int l239 = 0; (l239 < 2); l239 = (l239 + 1)) {
			fRec329[l239] = 0.0;
			
		}
		for (int l240 = 0; (l240 < 2); l240 = (l240 + 1)) {
			fRec327[l240] = 0.0;
			
		}
		for (int l241 = 0; (l241 < 2); l241 = (l241 + 1)) {
			fRec326[l241] = 0.0;
			
		}
		for (int l242 = 0; (l242 < 2); l242 = (l242 + 1)) {
			fRec324[l242] = 0.0;
			
		}
		for (int l243 = 0; (l243 < 2); l243 = (l243 + 1)) {
			fRec344[l243] = 0.0;
			
		}
		for (int l244 = 0; (l244 < 2); l244 = (l244 + 1)) {
			fRec342[l244] = 0.0;
			
		}
		for (int l245 = 0; (l245 < 2); l245 = (l245 + 1)) {
			fRec341[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fRec339[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 2); l247 = (l247 + 1)) {
			fRec338[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 2); l248 = (l248 + 1)) {
			fRec336[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fRec347[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 2); l250 = (l250 + 1)) {
			fRec345[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 2); l251 = (l251 + 1)) {
			fRec353[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 2); l252 = (l252 + 1)) {
			fRec351[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec350[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec348[l254] = 0.0;
			
		}
		for (int l255 = 0; (l255 < 128); l255 = (l255 + 1)) {
			fVec6[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec368[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fRec366[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec365[l258] = 0.0;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec363[l259] = 0.0;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec362[l260] = 0.0;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec360[l261] = 0.0;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec359[l262] = 0.0;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec357[l263] = 0.0;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec356[l264] = 0.0;
			
		}
		for (int l265 = 0; (l265 < 2); l265 = (l265 + 1)) {
			fRec354[l265] = 0.0;
			
		}
		for (int l266 = 0; (l266 < 2); l266 = (l266 + 1)) {
			fRec380[l266] = 0.0;
			
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec378[l267] = 0.0;
			
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec377[l268] = 0.0;
			
		}
		for (int l269 = 0; (l269 < 2); l269 = (l269 + 1)) {
			fRec375[l269] = 0.0;
			
		}
		for (int l270 = 0; (l270 < 2); l270 = (l270 + 1)) {
			fRec374[l270] = 0.0;
			
		}
		for (int l271 = 0; (l271 < 2); l271 = (l271 + 1)) {
			fRec372[l271] = 0.0;
			
		}
		for (int l272 = 0; (l272 < 2); l272 = (l272 + 1)) {
			fRec371[l272] = 0.0;
			
		}
		for (int l273 = 0; (l273 < 2); l273 = (l273 + 1)) {
			fRec369[l273] = 0.0;
			
		}
		for (int l274 = 0; (l274 < 2); l274 = (l274 + 1)) {
			fRec389[l274] = 0.0;
			
		}
		for (int l275 = 0; (l275 < 2); l275 = (l275 + 1)) {
			fRec387[l275] = 0.0;
			
		}
		for (int l276 = 0; (l276 < 2); l276 = (l276 + 1)) {
			fRec386[l276] = 0.0;
			
		}
		for (int l277 = 0; (l277 < 2); l277 = (l277 + 1)) {
			fRec384[l277] = 0.0;
			
		}
		for (int l278 = 0; (l278 < 2); l278 = (l278 + 1)) {
			fRec383[l278] = 0.0;
			
		}
		for (int l279 = 0; (l279 < 2); l279 = (l279 + 1)) {
			fRec381[l279] = 0.0;
			
		}
		for (int l280 = 0; (l280 < 2); l280 = (l280 + 1)) {
			fRec392[l280] = 0.0;
			
		}
		for (int l281 = 0; (l281 < 2); l281 = (l281 + 1)) {
			fRec390[l281] = 0.0;
			
		}
		for (int l282 = 0; (l282 < 2); l282 = (l282 + 1)) {
			fRec398[l282] = 0.0;
			
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec396[l283] = 0.0;
			
		}
		for (int l284 = 0; (l284 < 2); l284 = (l284 + 1)) {
			fRec395[l284] = 0.0;
			
		}
		for (int l285 = 0; (l285 < 2); l285 = (l285 + 1)) {
			fRec393[l285] = 0.0;
			
		}
		for (int l286 = 0; (l286 < 128); l286 = (l286 + 1)) {
			fVec7[l286] = 0.0;
			
		}
		for (int l287 = 0; (l287 < 2); l287 = (l287 + 1)) {
			fRec413[l287] = 0.0;
			
		}
		for (int l288 = 0; (l288 < 2); l288 = (l288 + 1)) {
			fRec411[l288] = 0.0;
			
		}
		for (int l289 = 0; (l289 < 2); l289 = (l289 + 1)) {
			fRec410[l289] = 0.0;
			
		}
		for (int l290 = 0; (l290 < 2); l290 = (l290 + 1)) {
			fRec408[l290] = 0.0;
			
		}
		for (int l291 = 0; (l291 < 2); l291 = (l291 + 1)) {
			fRec407[l291] = 0.0;
			
		}
		for (int l292 = 0; (l292 < 2); l292 = (l292 + 1)) {
			fRec405[l292] = 0.0;
			
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec404[l293] = 0.0;
			
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec402[l294] = 0.0;
			
		}
		for (int l295 = 0; (l295 < 2); l295 = (l295 + 1)) {
			fRec401[l295] = 0.0;
			
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec399[l296] = 0.0;
			
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec425[l297] = 0.0;
			
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec423[l298] = 0.0;
			
		}
		for (int l299 = 0; (l299 < 2); l299 = (l299 + 1)) {
			fRec422[l299] = 0.0;
			
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec420[l300] = 0.0;
			
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec419[l301] = 0.0;
			
		}
		for (int l302 = 0; (l302 < 2); l302 = (l302 + 1)) {
			fRec417[l302] = 0.0;
			
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec416[l303] = 0.0;
			
		}
		for (int l304 = 0; (l304 < 2); l304 = (l304 + 1)) {
			fRec414[l304] = 0.0;
			
		}
		for (int l305 = 0; (l305 < 2); l305 = (l305 + 1)) {
			fRec434[l305] = 0.0;
			
		}
		for (int l306 = 0; (l306 < 2); l306 = (l306 + 1)) {
			fRec432[l306] = 0.0;
			
		}
		for (int l307 = 0; (l307 < 2); l307 = (l307 + 1)) {
			fRec431[l307] = 0.0;
			
		}
		for (int l308 = 0; (l308 < 2); l308 = (l308 + 1)) {
			fRec429[l308] = 0.0;
			
		}
		for (int l309 = 0; (l309 < 2); l309 = (l309 + 1)) {
			fRec428[l309] = 0.0;
			
		}
		for (int l310 = 0; (l310 < 2); l310 = (l310 + 1)) {
			fRec426[l310] = 0.0;
			
		}
		for (int l311 = 0; (l311 < 2); l311 = (l311 + 1)) {
			fRec437[l311] = 0.0;
			
		}
		for (int l312 = 0; (l312 < 2); l312 = (l312 + 1)) {
			fRec435[l312] = 0.0;
			
		}
		for (int l313 = 0; (l313 < 2); l313 = (l313 + 1)) {
			fRec443[l313] = 0.0;
			
		}
		for (int l314 = 0; (l314 < 2); l314 = (l314 + 1)) {
			fRec441[l314] = 0.0;
			
		}
		for (int l315 = 0; (l315 < 2); l315 = (l315 + 1)) {
			fRec440[l315] = 0.0;
			
		}
		for (int l316 = 0; (l316 < 2); l316 = (l316 + 1)) {
			fRec438[l316] = 0.0;
			
		}
		for (int l317 = 0; (l317 < 128); l317 = (l317 + 1)) {
			fVec8[l317] = 0.0;
			
		}
		for (int l318 = 0; (l318 < 2); l318 = (l318 + 1)) {
			fRec458[l318] = 0.0;
			
		}
		for (int l319 = 0; (l319 < 2); l319 = (l319 + 1)) {
			fRec456[l319] = 0.0;
			
		}
		for (int l320 = 0; (l320 < 2); l320 = (l320 + 1)) {
			fRec455[l320] = 0.0;
			
		}
		for (int l321 = 0; (l321 < 2); l321 = (l321 + 1)) {
			fRec453[l321] = 0.0;
			
		}
		for (int l322 = 0; (l322 < 2); l322 = (l322 + 1)) {
			fRec452[l322] = 0.0;
			
		}
		for (int l323 = 0; (l323 < 2); l323 = (l323 + 1)) {
			fRec450[l323] = 0.0;
			
		}
		for (int l324 = 0; (l324 < 2); l324 = (l324 + 1)) {
			fRec449[l324] = 0.0;
			
		}
		for (int l325 = 0; (l325 < 2); l325 = (l325 + 1)) {
			fRec447[l325] = 0.0;
			
		}
		for (int l326 = 0; (l326 < 2); l326 = (l326 + 1)) {
			fRec446[l326] = 0.0;
			
		}
		for (int l327 = 0; (l327 < 2); l327 = (l327 + 1)) {
			fRec444[l327] = 0.0;
			
		}
		for (int l328 = 0; (l328 < 2); l328 = (l328 + 1)) {
			fRec470[l328] = 0.0;
			
		}
		for (int l329 = 0; (l329 < 2); l329 = (l329 + 1)) {
			fRec468[l329] = 0.0;
			
		}
		for (int l330 = 0; (l330 < 2); l330 = (l330 + 1)) {
			fRec467[l330] = 0.0;
			
		}
		for (int l331 = 0; (l331 < 2); l331 = (l331 + 1)) {
			fRec465[l331] = 0.0;
			
		}
		for (int l332 = 0; (l332 < 2); l332 = (l332 + 1)) {
			fRec464[l332] = 0.0;
			
		}
		for (int l333 = 0; (l333 < 2); l333 = (l333 + 1)) {
			fRec462[l333] = 0.0;
			
		}
		for (int l334 = 0; (l334 < 2); l334 = (l334 + 1)) {
			fRec461[l334] = 0.0;
			
		}
		for (int l335 = 0; (l335 < 2); l335 = (l335 + 1)) {
			fRec459[l335] = 0.0;
			
		}
		for (int l336 = 0; (l336 < 2); l336 = (l336 + 1)) {
			fRec479[l336] = 0.0;
			
		}
		for (int l337 = 0; (l337 < 2); l337 = (l337 + 1)) {
			fRec477[l337] = 0.0;
			
		}
		for (int l338 = 0; (l338 < 2); l338 = (l338 + 1)) {
			fRec476[l338] = 0.0;
			
		}
		for (int l339 = 0; (l339 < 2); l339 = (l339 + 1)) {
			fRec474[l339] = 0.0;
			
		}
		for (int l340 = 0; (l340 < 2); l340 = (l340 + 1)) {
			fRec473[l340] = 0.0;
			
		}
		for (int l341 = 0; (l341 < 2); l341 = (l341 + 1)) {
			fRec471[l341] = 0.0;
			
		}
		for (int l342 = 0; (l342 < 2); l342 = (l342 + 1)) {
			fRec482[l342] = 0.0;
			
		}
		for (int l343 = 0; (l343 < 2); l343 = (l343 + 1)) {
			fRec480[l343] = 0.0;
			
		}
		for (int l344 = 0; (l344 < 2); l344 = (l344 + 1)) {
			fRec488[l344] = 0.0;
			
		}
		for (int l345 = 0; (l345 < 2); l345 = (l345 + 1)) {
			fRec486[l345] = 0.0;
			
		}
		for (int l346 = 0; (l346 < 2); l346 = (l346 + 1)) {
			fRec485[l346] = 0.0;
			
		}
		for (int l347 = 0; (l347 < 2); l347 = (l347 + 1)) {
			fRec483[l347] = 0.0;
			
		}
		for (int l348 = 0; (l348 < 128); l348 = (l348 + 1)) {
			fVec9[l348] = 0.0;
			
		}
		for (int l349 = 0; (l349 < 2); l349 = (l349 + 1)) {
			fRec503[l349] = 0.0;
			
		}
		for (int l350 = 0; (l350 < 2); l350 = (l350 + 1)) {
			fRec501[l350] = 0.0;
			
		}
		for (int l351 = 0; (l351 < 2); l351 = (l351 + 1)) {
			fRec500[l351] = 0.0;
			
		}
		for (int l352 = 0; (l352 < 2); l352 = (l352 + 1)) {
			fRec498[l352] = 0.0;
			
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec497[l353] = 0.0;
			
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec495[l354] = 0.0;
			
		}
		for (int l355 = 0; (l355 < 2); l355 = (l355 + 1)) {
			fRec494[l355] = 0.0;
			
		}
		for (int l356 = 0; (l356 < 2); l356 = (l356 + 1)) {
			fRec492[l356] = 0.0;
			
		}
		for (int l357 = 0; (l357 < 2); l357 = (l357 + 1)) {
			fRec491[l357] = 0.0;
			
		}
		for (int l358 = 0; (l358 < 2); l358 = (l358 + 1)) {
			fRec489[l358] = 0.0;
			
		}
		for (int l359 = 0; (l359 < 2); l359 = (l359 + 1)) {
			fRec515[l359] = 0.0;
			
		}
		for (int l360 = 0; (l360 < 2); l360 = (l360 + 1)) {
			fRec513[l360] = 0.0;
			
		}
		for (int l361 = 0; (l361 < 2); l361 = (l361 + 1)) {
			fRec512[l361] = 0.0;
			
		}
		for (int l362 = 0; (l362 < 2); l362 = (l362 + 1)) {
			fRec510[l362] = 0.0;
			
		}
		for (int l363 = 0; (l363 < 2); l363 = (l363 + 1)) {
			fRec509[l363] = 0.0;
			
		}
		for (int l364 = 0; (l364 < 2); l364 = (l364 + 1)) {
			fRec507[l364] = 0.0;
			
		}
		for (int l365 = 0; (l365 < 2); l365 = (l365 + 1)) {
			fRec506[l365] = 0.0;
			
		}
		for (int l366 = 0; (l366 < 2); l366 = (l366 + 1)) {
			fRec504[l366] = 0.0;
			
		}
		for (int l367 = 0; (l367 < 2); l367 = (l367 + 1)) {
			fRec524[l367] = 0.0;
			
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec522[l368] = 0.0;
			
		}
		for (int l369 = 0; (l369 < 2); l369 = (l369 + 1)) {
			fRec521[l369] = 0.0;
			
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec519[l370] = 0.0;
			
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			fRec518[l371] = 0.0;
			
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			fRec516[l372] = 0.0;
			
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fRec527[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec525[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 2); l375 = (l375 + 1)) {
			fRec533[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec531[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec530[l377] = 0.0;
			
		}
		for (int l378 = 0; (l378 < 2); l378 = (l378 + 1)) {
			fRec528[l378] = 0.0;
			
		}
		for (int l379 = 0; (l379 < 128); l379 = (l379 + 1)) {
			fVec10[l379] = 0.0;
			
		}
		for (int l380 = 0; (l380 < 2); l380 = (l380 + 1)) {
			fRec548[l380] = 0.0;
			
		}
		for (int l381 = 0; (l381 < 2); l381 = (l381 + 1)) {
			fRec546[l381] = 0.0;
			
		}
		for (int l382 = 0; (l382 < 2); l382 = (l382 + 1)) {
			fRec545[l382] = 0.0;
			
		}
		for (int l383 = 0; (l383 < 2); l383 = (l383 + 1)) {
			fRec543[l383] = 0.0;
			
		}
		for (int l384 = 0; (l384 < 2); l384 = (l384 + 1)) {
			fRec542[l384] = 0.0;
			
		}
		for (int l385 = 0; (l385 < 2); l385 = (l385 + 1)) {
			fRec540[l385] = 0.0;
			
		}
		for (int l386 = 0; (l386 < 2); l386 = (l386 + 1)) {
			fRec539[l386] = 0.0;
			
		}
		for (int l387 = 0; (l387 < 2); l387 = (l387 + 1)) {
			fRec537[l387] = 0.0;
			
		}
		for (int l388 = 0; (l388 < 2); l388 = (l388 + 1)) {
			fRec536[l388] = 0.0;
			
		}
		for (int l389 = 0; (l389 < 2); l389 = (l389 + 1)) {
			fRec534[l389] = 0.0;
			
		}
		for (int l390 = 0; (l390 < 2); l390 = (l390 + 1)) {
			fRec560[l390] = 0.0;
			
		}
		for (int l391 = 0; (l391 < 2); l391 = (l391 + 1)) {
			fRec558[l391] = 0.0;
			
		}
		for (int l392 = 0; (l392 < 2); l392 = (l392 + 1)) {
			fRec557[l392] = 0.0;
			
		}
		for (int l393 = 0; (l393 < 2); l393 = (l393 + 1)) {
			fRec555[l393] = 0.0;
			
		}
		for (int l394 = 0; (l394 < 2); l394 = (l394 + 1)) {
			fRec554[l394] = 0.0;
			
		}
		for (int l395 = 0; (l395 < 2); l395 = (l395 + 1)) {
			fRec552[l395] = 0.0;
			
		}
		for (int l396 = 0; (l396 < 2); l396 = (l396 + 1)) {
			fRec551[l396] = 0.0;
			
		}
		for (int l397 = 0; (l397 < 2); l397 = (l397 + 1)) {
			fRec549[l397] = 0.0;
			
		}
		for (int l398 = 0; (l398 < 2); l398 = (l398 + 1)) {
			fRec569[l398] = 0.0;
			
		}
		for (int l399 = 0; (l399 < 2); l399 = (l399 + 1)) {
			fRec567[l399] = 0.0;
			
		}
		for (int l400 = 0; (l400 < 2); l400 = (l400 + 1)) {
			fRec566[l400] = 0.0;
			
		}
		for (int l401 = 0; (l401 < 2); l401 = (l401 + 1)) {
			fRec564[l401] = 0.0;
			
		}
		for (int l402 = 0; (l402 < 2); l402 = (l402 + 1)) {
			fRec563[l402] = 0.0;
			
		}
		for (int l403 = 0; (l403 < 2); l403 = (l403 + 1)) {
			fRec561[l403] = 0.0;
			
		}
		for (int l404 = 0; (l404 < 2); l404 = (l404 + 1)) {
			fRec572[l404] = 0.0;
			
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec570[l405] = 0.0;
			
		}
		for (int l406 = 0; (l406 < 2); l406 = (l406 + 1)) {
			fRec578[l406] = 0.0;
			
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec576[l407] = 0.0;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec575[l408] = 0.0;
			
		}
		for (int l409 = 0; (l409 < 2); l409 = (l409 + 1)) {
			fRec573[l409] = 0.0;
			
		}
		for (int l410 = 0; (l410 < 128); l410 = (l410 + 1)) {
			fVec11[l410] = 0.0;
			
		}
		for (int l411 = 0; (l411 < 2); l411 = (l411 + 1)) {
			fRec593[l411] = 0.0;
			
		}
		for (int l412 = 0; (l412 < 2); l412 = (l412 + 1)) {
			fRec591[l412] = 0.0;
			
		}
		for (int l413 = 0; (l413 < 2); l413 = (l413 + 1)) {
			fRec590[l413] = 0.0;
			
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec588[l414] = 0.0;
			
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec587[l415] = 0.0;
			
		}
		for (int l416 = 0; (l416 < 2); l416 = (l416 + 1)) {
			fRec585[l416] = 0.0;
			
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec584[l417] = 0.0;
			
		}
		for (int l418 = 0; (l418 < 2); l418 = (l418 + 1)) {
			fRec582[l418] = 0.0;
			
		}
		for (int l419 = 0; (l419 < 2); l419 = (l419 + 1)) {
			fRec581[l419] = 0.0;
			
		}
		for (int l420 = 0; (l420 < 2); l420 = (l420 + 1)) {
			fRec579[l420] = 0.0;
			
		}
		for (int l421 = 0; (l421 < 2); l421 = (l421 + 1)) {
			fRec605[l421] = 0.0;
			
		}
		for (int l422 = 0; (l422 < 2); l422 = (l422 + 1)) {
			fRec603[l422] = 0.0;
			
		}
		for (int l423 = 0; (l423 < 2); l423 = (l423 + 1)) {
			fRec602[l423] = 0.0;
			
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec600[l424] = 0.0;
			
		}
		for (int l425 = 0; (l425 < 2); l425 = (l425 + 1)) {
			fRec599[l425] = 0.0;
			
		}
		for (int l426 = 0; (l426 < 2); l426 = (l426 + 1)) {
			fRec597[l426] = 0.0;
			
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec596[l427] = 0.0;
			
		}
		for (int l428 = 0; (l428 < 2); l428 = (l428 + 1)) {
			fRec594[l428] = 0.0;
			
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec614[l429] = 0.0;
			
		}
		for (int l430 = 0; (l430 < 2); l430 = (l430 + 1)) {
			fRec612[l430] = 0.0;
			
		}
		for (int l431 = 0; (l431 < 2); l431 = (l431 + 1)) {
			fRec611[l431] = 0.0;
			
		}
		for (int l432 = 0; (l432 < 2); l432 = (l432 + 1)) {
			fRec609[l432] = 0.0;
			
		}
		for (int l433 = 0; (l433 < 2); l433 = (l433 + 1)) {
			fRec608[l433] = 0.0;
			
		}
		for (int l434 = 0; (l434 < 2); l434 = (l434 + 1)) {
			fRec606[l434] = 0.0;
			
		}
		for (int l435 = 0; (l435 < 2); l435 = (l435 + 1)) {
			fRec617[l435] = 0.0;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec615[l436] = 0.0;
			
		}
		for (int l437 = 0; (l437 < 2); l437 = (l437 + 1)) {
			fRec623[l437] = 0.0;
			
		}
		for (int l438 = 0; (l438 < 2); l438 = (l438 + 1)) {
			fRec621[l438] = 0.0;
			
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec620[l439] = 0.0;
			
		}
		for (int l440 = 0; (l440 < 2); l440 = (l440 + 1)) {
			fRec618[l440] = 0.0;
			
		}
		for (int l441 = 0; (l441 < 128); l441 = (l441 + 1)) {
			fVec12[l441] = 0.0;
			
		}
		for (int l442 = 0; (l442 < 2); l442 = (l442 + 1)) {
			fRec638[l442] = 0.0;
			
		}
		for (int l443 = 0; (l443 < 2); l443 = (l443 + 1)) {
			fRec636[l443] = 0.0;
			
		}
		for (int l444 = 0; (l444 < 2); l444 = (l444 + 1)) {
			fRec635[l444] = 0.0;
			
		}
		for (int l445 = 0; (l445 < 2); l445 = (l445 + 1)) {
			fRec633[l445] = 0.0;
			
		}
		for (int l446 = 0; (l446 < 2); l446 = (l446 + 1)) {
			fRec632[l446] = 0.0;
			
		}
		for (int l447 = 0; (l447 < 2); l447 = (l447 + 1)) {
			fRec630[l447] = 0.0;
			
		}
		for (int l448 = 0; (l448 < 2); l448 = (l448 + 1)) {
			fRec629[l448] = 0.0;
			
		}
		for (int l449 = 0; (l449 < 2); l449 = (l449 + 1)) {
			fRec627[l449] = 0.0;
			
		}
		for (int l450 = 0; (l450 < 2); l450 = (l450 + 1)) {
			fRec626[l450] = 0.0;
			
		}
		for (int l451 = 0; (l451 < 2); l451 = (l451 + 1)) {
			fRec624[l451] = 0.0;
			
		}
		for (int l452 = 0; (l452 < 2); l452 = (l452 + 1)) {
			fRec650[l452] = 0.0;
			
		}
		for (int l453 = 0; (l453 < 2); l453 = (l453 + 1)) {
			fRec648[l453] = 0.0;
			
		}
		for (int l454 = 0; (l454 < 2); l454 = (l454 + 1)) {
			fRec647[l454] = 0.0;
			
		}
		for (int l455 = 0; (l455 < 2); l455 = (l455 + 1)) {
			fRec645[l455] = 0.0;
			
		}
		for (int l456 = 0; (l456 < 2); l456 = (l456 + 1)) {
			fRec644[l456] = 0.0;
			
		}
		for (int l457 = 0; (l457 < 2); l457 = (l457 + 1)) {
			fRec642[l457] = 0.0;
			
		}
		for (int l458 = 0; (l458 < 2); l458 = (l458 + 1)) {
			fRec641[l458] = 0.0;
			
		}
		for (int l459 = 0; (l459 < 2); l459 = (l459 + 1)) {
			fRec639[l459] = 0.0;
			
		}
		for (int l460 = 0; (l460 < 2); l460 = (l460 + 1)) {
			fRec659[l460] = 0.0;
			
		}
		for (int l461 = 0; (l461 < 2); l461 = (l461 + 1)) {
			fRec657[l461] = 0.0;
			
		}
		for (int l462 = 0; (l462 < 2); l462 = (l462 + 1)) {
			fRec656[l462] = 0.0;
			
		}
		for (int l463 = 0; (l463 < 2); l463 = (l463 + 1)) {
			fRec654[l463] = 0.0;
			
		}
		for (int l464 = 0; (l464 < 2); l464 = (l464 + 1)) {
			fRec653[l464] = 0.0;
			
		}
		for (int l465 = 0; (l465 < 2); l465 = (l465 + 1)) {
			fRec651[l465] = 0.0;
			
		}
		for (int l466 = 0; (l466 < 2); l466 = (l466 + 1)) {
			fRec662[l466] = 0.0;
			
		}
		for (int l467 = 0; (l467 < 2); l467 = (l467 + 1)) {
			fRec660[l467] = 0.0;
			
		}
		for (int l468 = 0; (l468 < 2); l468 = (l468 + 1)) {
			fRec668[l468] = 0.0;
			
		}
		for (int l469 = 0; (l469 < 2); l469 = (l469 + 1)) {
			fRec666[l469] = 0.0;
			
		}
		for (int l470 = 0; (l470 < 2); l470 = (l470 + 1)) {
			fRec665[l470] = 0.0;
			
		}
		for (int l471 = 0; (l471 < 2); l471 = (l471 + 1)) {
			fRec663[l471] = 0.0;
			
		}
		for (int l472 = 0; (l472 < 128); l472 = (l472 + 1)) {
			fVec13[l472] = 0.0;
			
		}
		for (int l473 = 0; (l473 < 2); l473 = (l473 + 1)) {
			fRec683[l473] = 0.0;
			
		}
		for (int l474 = 0; (l474 < 2); l474 = (l474 + 1)) {
			fRec681[l474] = 0.0;
			
		}
		for (int l475 = 0; (l475 < 2); l475 = (l475 + 1)) {
			fRec680[l475] = 0.0;
			
		}
		for (int l476 = 0; (l476 < 2); l476 = (l476 + 1)) {
			fRec678[l476] = 0.0;
			
		}
		for (int l477 = 0; (l477 < 2); l477 = (l477 + 1)) {
			fRec677[l477] = 0.0;
			
		}
		for (int l478 = 0; (l478 < 2); l478 = (l478 + 1)) {
			fRec675[l478] = 0.0;
			
		}
		for (int l479 = 0; (l479 < 2); l479 = (l479 + 1)) {
			fRec674[l479] = 0.0;
			
		}
		for (int l480 = 0; (l480 < 2); l480 = (l480 + 1)) {
			fRec672[l480] = 0.0;
			
		}
		for (int l481 = 0; (l481 < 2); l481 = (l481 + 1)) {
			fRec671[l481] = 0.0;
			
		}
		for (int l482 = 0; (l482 < 2); l482 = (l482 + 1)) {
			fRec669[l482] = 0.0;
			
		}
		for (int l483 = 0; (l483 < 2); l483 = (l483 + 1)) {
			fRec695[l483] = 0.0;
			
		}
		for (int l484 = 0; (l484 < 2); l484 = (l484 + 1)) {
			fRec693[l484] = 0.0;
			
		}
		for (int l485 = 0; (l485 < 2); l485 = (l485 + 1)) {
			fRec692[l485] = 0.0;
			
		}
		for (int l486 = 0; (l486 < 2); l486 = (l486 + 1)) {
			fRec690[l486] = 0.0;
			
		}
		for (int l487 = 0; (l487 < 2); l487 = (l487 + 1)) {
			fRec689[l487] = 0.0;
			
		}
		for (int l488 = 0; (l488 < 2); l488 = (l488 + 1)) {
			fRec687[l488] = 0.0;
			
		}
		for (int l489 = 0; (l489 < 2); l489 = (l489 + 1)) {
			fRec686[l489] = 0.0;
			
		}
		for (int l490 = 0; (l490 < 2); l490 = (l490 + 1)) {
			fRec684[l490] = 0.0;
			
		}
		for (int l491 = 0; (l491 < 2); l491 = (l491 + 1)) {
			fRec704[l491] = 0.0;
			
		}
		for (int l492 = 0; (l492 < 2); l492 = (l492 + 1)) {
			fRec702[l492] = 0.0;
			
		}
		for (int l493 = 0; (l493 < 2); l493 = (l493 + 1)) {
			fRec701[l493] = 0.0;
			
		}
		for (int l494 = 0; (l494 < 2); l494 = (l494 + 1)) {
			fRec699[l494] = 0.0;
			
		}
		for (int l495 = 0; (l495 < 2); l495 = (l495 + 1)) {
			fRec698[l495] = 0.0;
			
		}
		for (int l496 = 0; (l496 < 2); l496 = (l496 + 1)) {
			fRec696[l496] = 0.0;
			
		}
		for (int l497 = 0; (l497 < 2); l497 = (l497 + 1)) {
			fRec707[l497] = 0.0;
			
		}
		for (int l498 = 0; (l498 < 2); l498 = (l498 + 1)) {
			fRec705[l498] = 0.0;
			
		}
		for (int l499 = 0; (l499 < 2); l499 = (l499 + 1)) {
			fRec713[l499] = 0.0;
			
		}
		for (int l500 = 0; (l500 < 2); l500 = (l500 + 1)) {
			fRec711[l500] = 0.0;
			
		}
		for (int l501 = 0; (l501 < 2); l501 = (l501 + 1)) {
			fRec710[l501] = 0.0;
			
		}
		for (int l502 = 0; (l502 < 2); l502 = (l502 + 1)) {
			fRec708[l502] = 0.0;
			
		}
		for (int l503 = 0; (l503 < 128); l503 = (l503 + 1)) {
			fVec14[l503] = 0.0;
			
		}
		for (int l504 = 0; (l504 < 2); l504 = (l504 + 1)) {
			fRec728[l504] = 0.0;
			
		}
		for (int l505 = 0; (l505 < 2); l505 = (l505 + 1)) {
			fRec726[l505] = 0.0;
			
		}
		for (int l506 = 0; (l506 < 2); l506 = (l506 + 1)) {
			fRec725[l506] = 0.0;
			
		}
		for (int l507 = 0; (l507 < 2); l507 = (l507 + 1)) {
			fRec723[l507] = 0.0;
			
		}
		for (int l508 = 0; (l508 < 2); l508 = (l508 + 1)) {
			fRec722[l508] = 0.0;
			
		}
		for (int l509 = 0; (l509 < 2); l509 = (l509 + 1)) {
			fRec720[l509] = 0.0;
			
		}
		for (int l510 = 0; (l510 < 2); l510 = (l510 + 1)) {
			fRec719[l510] = 0.0;
			
		}
		for (int l511 = 0; (l511 < 2); l511 = (l511 + 1)) {
			fRec717[l511] = 0.0;
			
		}
		for (int l512 = 0; (l512 < 2); l512 = (l512 + 1)) {
			fRec716[l512] = 0.0;
			
		}
		for (int l513 = 0; (l513 < 2); l513 = (l513 + 1)) {
			fRec714[l513] = 0.0;
			
		}
		for (int l514 = 0; (l514 < 2); l514 = (l514 + 1)) {
			fRec740[l514] = 0.0;
			
		}
		for (int l515 = 0; (l515 < 2); l515 = (l515 + 1)) {
			fRec738[l515] = 0.0;
			
		}
		for (int l516 = 0; (l516 < 2); l516 = (l516 + 1)) {
			fRec737[l516] = 0.0;
			
		}
		for (int l517 = 0; (l517 < 2); l517 = (l517 + 1)) {
			fRec735[l517] = 0.0;
			
		}
		for (int l518 = 0; (l518 < 2); l518 = (l518 + 1)) {
			fRec734[l518] = 0.0;
			
		}
		for (int l519 = 0; (l519 < 2); l519 = (l519 + 1)) {
			fRec732[l519] = 0.0;
			
		}
		for (int l520 = 0; (l520 < 2); l520 = (l520 + 1)) {
			fRec731[l520] = 0.0;
			
		}
		for (int l521 = 0; (l521 < 2); l521 = (l521 + 1)) {
			fRec729[l521] = 0.0;
			
		}
		for (int l522 = 0; (l522 < 2); l522 = (l522 + 1)) {
			fRec749[l522] = 0.0;
			
		}
		for (int l523 = 0; (l523 < 2); l523 = (l523 + 1)) {
			fRec747[l523] = 0.0;
			
		}
		for (int l524 = 0; (l524 < 2); l524 = (l524 + 1)) {
			fRec746[l524] = 0.0;
			
		}
		for (int l525 = 0; (l525 < 2); l525 = (l525 + 1)) {
			fRec744[l525] = 0.0;
			
		}
		for (int l526 = 0; (l526 < 2); l526 = (l526 + 1)) {
			fRec743[l526] = 0.0;
			
		}
		for (int l527 = 0; (l527 < 2); l527 = (l527 + 1)) {
			fRec741[l527] = 0.0;
			
		}
		for (int l528 = 0; (l528 < 2); l528 = (l528 + 1)) {
			fRec752[l528] = 0.0;
			
		}
		for (int l529 = 0; (l529 < 2); l529 = (l529 + 1)) {
			fRec750[l529] = 0.0;
			
		}
		for (int l530 = 0; (l530 < 2); l530 = (l530 + 1)) {
			fRec758[l530] = 0.0;
			
		}
		for (int l531 = 0; (l531 < 2); l531 = (l531 + 1)) {
			fRec756[l531] = 0.0;
			
		}
		for (int l532 = 0; (l532 < 2); l532 = (l532 + 1)) {
			fRec755[l532] = 0.0;
			
		}
		for (int l533 = 0; (l533 < 2); l533 = (l533 + 1)) {
			fRec753[l533] = 0.0;
			
		}
		for (int l534 = 0; (l534 < 128); l534 = (l534 + 1)) {
			fVec15[l534] = 0.0;
			
		}
		for (int l535 = 0; (l535 < 2); l535 = (l535 + 1)) {
			fRec773[l535] = 0.0;
			
		}
		for (int l536 = 0; (l536 < 2); l536 = (l536 + 1)) {
			fRec771[l536] = 0.0;
			
		}
		for (int l537 = 0; (l537 < 2); l537 = (l537 + 1)) {
			fRec770[l537] = 0.0;
			
		}
		for (int l538 = 0; (l538 < 2); l538 = (l538 + 1)) {
			fRec768[l538] = 0.0;
			
		}
		for (int l539 = 0; (l539 < 2); l539 = (l539 + 1)) {
			fRec767[l539] = 0.0;
			
		}
		for (int l540 = 0; (l540 < 2); l540 = (l540 + 1)) {
			fRec765[l540] = 0.0;
			
		}
		for (int l541 = 0; (l541 < 2); l541 = (l541 + 1)) {
			fRec764[l541] = 0.0;
			
		}
		for (int l542 = 0; (l542 < 2); l542 = (l542 + 1)) {
			fRec762[l542] = 0.0;
			
		}
		for (int l543 = 0; (l543 < 2); l543 = (l543 + 1)) {
			fRec761[l543] = 0.0;
			
		}
		for (int l544 = 0; (l544 < 2); l544 = (l544 + 1)) {
			fRec759[l544] = 0.0;
			
		}
		for (int l545 = 0; (l545 < 2); l545 = (l545 + 1)) {
			fRec785[l545] = 0.0;
			
		}
		for (int l546 = 0; (l546 < 2); l546 = (l546 + 1)) {
			fRec783[l546] = 0.0;
			
		}
		for (int l547 = 0; (l547 < 2); l547 = (l547 + 1)) {
			fRec782[l547] = 0.0;
			
		}
		for (int l548 = 0; (l548 < 2); l548 = (l548 + 1)) {
			fRec780[l548] = 0.0;
			
		}
		for (int l549 = 0; (l549 < 2); l549 = (l549 + 1)) {
			fRec779[l549] = 0.0;
			
		}
		for (int l550 = 0; (l550 < 2); l550 = (l550 + 1)) {
			fRec777[l550] = 0.0;
			
		}
		for (int l551 = 0; (l551 < 2); l551 = (l551 + 1)) {
			fRec776[l551] = 0.0;
			
		}
		for (int l552 = 0; (l552 < 2); l552 = (l552 + 1)) {
			fRec774[l552] = 0.0;
			
		}
		for (int l553 = 0; (l553 < 2); l553 = (l553 + 1)) {
			fRec794[l553] = 0.0;
			
		}
		for (int l554 = 0; (l554 < 2); l554 = (l554 + 1)) {
			fRec792[l554] = 0.0;
			
		}
		for (int l555 = 0; (l555 < 2); l555 = (l555 + 1)) {
			fRec791[l555] = 0.0;
			
		}
		for (int l556 = 0; (l556 < 2); l556 = (l556 + 1)) {
			fRec789[l556] = 0.0;
			
		}
		for (int l557 = 0; (l557 < 2); l557 = (l557 + 1)) {
			fRec788[l557] = 0.0;
			
		}
		for (int l558 = 0; (l558 < 2); l558 = (l558 + 1)) {
			fRec786[l558] = 0.0;
			
		}
		for (int l559 = 0; (l559 < 2); l559 = (l559 + 1)) {
			fRec797[l559] = 0.0;
			
		}
		for (int l560 = 0; (l560 < 2); l560 = (l560 + 1)) {
			fRec795[l560] = 0.0;
			
		}
		for (int l561 = 0; (l561 < 2); l561 = (l561 + 1)) {
			fRec803[l561] = 0.0;
			
		}
		for (int l562 = 0; (l562 < 2); l562 = (l562 + 1)) {
			fRec801[l562] = 0.0;
			
		}
		for (int l563 = 0; (l563 < 2); l563 = (l563 + 1)) {
			fRec800[l563] = 0.0;
			
		}
		for (int l564 = 0; (l564 < 2); l564 = (l564 + 1)) {
			fRec798[l564] = 0.0;
			
		}
		for (int l565 = 0; (l565 < 128); l565 = (l565 + 1)) {
			fVec16[l565] = 0.0;
			
		}
		for (int l566 = 0; (l566 < 2); l566 = (l566 + 1)) {
			fRec818[l566] = 0.0;
			
		}
		for (int l567 = 0; (l567 < 2); l567 = (l567 + 1)) {
			fRec816[l567] = 0.0;
			
		}
		for (int l568 = 0; (l568 < 2); l568 = (l568 + 1)) {
			fRec815[l568] = 0.0;
			
		}
		for (int l569 = 0; (l569 < 2); l569 = (l569 + 1)) {
			fRec813[l569] = 0.0;
			
		}
		for (int l570 = 0; (l570 < 2); l570 = (l570 + 1)) {
			fRec812[l570] = 0.0;
			
		}
		for (int l571 = 0; (l571 < 2); l571 = (l571 + 1)) {
			fRec810[l571] = 0.0;
			
		}
		for (int l572 = 0; (l572 < 2); l572 = (l572 + 1)) {
			fRec809[l572] = 0.0;
			
		}
		for (int l573 = 0; (l573 < 2); l573 = (l573 + 1)) {
			fRec807[l573] = 0.0;
			
		}
		for (int l574 = 0; (l574 < 2); l574 = (l574 + 1)) {
			fRec806[l574] = 0.0;
			
		}
		for (int l575 = 0; (l575 < 2); l575 = (l575 + 1)) {
			fRec804[l575] = 0.0;
			
		}
		for (int l576 = 0; (l576 < 2); l576 = (l576 + 1)) {
			fRec830[l576] = 0.0;
			
		}
		for (int l577 = 0; (l577 < 2); l577 = (l577 + 1)) {
			fRec828[l577] = 0.0;
			
		}
		for (int l578 = 0; (l578 < 2); l578 = (l578 + 1)) {
			fRec827[l578] = 0.0;
			
		}
		for (int l579 = 0; (l579 < 2); l579 = (l579 + 1)) {
			fRec825[l579] = 0.0;
			
		}
		for (int l580 = 0; (l580 < 2); l580 = (l580 + 1)) {
			fRec824[l580] = 0.0;
			
		}
		for (int l581 = 0; (l581 < 2); l581 = (l581 + 1)) {
			fRec822[l581] = 0.0;
			
		}
		for (int l582 = 0; (l582 < 2); l582 = (l582 + 1)) {
			fRec821[l582] = 0.0;
			
		}
		for (int l583 = 0; (l583 < 2); l583 = (l583 + 1)) {
			fRec819[l583] = 0.0;
			
		}
		for (int l584 = 0; (l584 < 2); l584 = (l584 + 1)) {
			fRec839[l584] = 0.0;
			
		}
		for (int l585 = 0; (l585 < 2); l585 = (l585 + 1)) {
			fRec837[l585] = 0.0;
			
		}
		for (int l586 = 0; (l586 < 2); l586 = (l586 + 1)) {
			fRec836[l586] = 0.0;
			
		}
		for (int l587 = 0; (l587 < 2); l587 = (l587 + 1)) {
			fRec834[l587] = 0.0;
			
		}
		for (int l588 = 0; (l588 < 2); l588 = (l588 + 1)) {
			fRec833[l588] = 0.0;
			
		}
		for (int l589 = 0; (l589 < 2); l589 = (l589 + 1)) {
			fRec831[l589] = 0.0;
			
		}
		for (int l590 = 0; (l590 < 2); l590 = (l590 + 1)) {
			fRec842[l590] = 0.0;
			
		}
		for (int l591 = 0; (l591 < 2); l591 = (l591 + 1)) {
			fRec840[l591] = 0.0;
			
		}
		for (int l592 = 0; (l592 < 2); l592 = (l592 + 1)) {
			fRec848[l592] = 0.0;
			
		}
		for (int l593 = 0; (l593 < 2); l593 = (l593 + 1)) {
			fRec846[l593] = 0.0;
			
		}
		for (int l594 = 0; (l594 < 2); l594 = (l594 + 1)) {
			fRec845[l594] = 0.0;
			
		}
		for (int l595 = 0; (l595 < 2); l595 = (l595 + 1)) {
			fRec843[l595] = 0.0;
			
		}
		for (int l596 = 0; (l596 < 128); l596 = (l596 + 1)) {
			fVec17[l596] = 0.0;
			
		}
		for (int l597 = 0; (l597 < 2); l597 = (l597 + 1)) {
			fRec863[l597] = 0.0;
			
		}
		for (int l598 = 0; (l598 < 2); l598 = (l598 + 1)) {
			fRec861[l598] = 0.0;
			
		}
		for (int l599 = 0; (l599 < 2); l599 = (l599 + 1)) {
			fRec860[l599] = 0.0;
			
		}
		for (int l600 = 0; (l600 < 2); l600 = (l600 + 1)) {
			fRec858[l600] = 0.0;
			
		}
		for (int l601 = 0; (l601 < 2); l601 = (l601 + 1)) {
			fRec857[l601] = 0.0;
			
		}
		for (int l602 = 0; (l602 < 2); l602 = (l602 + 1)) {
			fRec855[l602] = 0.0;
			
		}
		for (int l603 = 0; (l603 < 2); l603 = (l603 + 1)) {
			fRec854[l603] = 0.0;
			
		}
		for (int l604 = 0; (l604 < 2); l604 = (l604 + 1)) {
			fRec852[l604] = 0.0;
			
		}
		for (int l605 = 0; (l605 < 2); l605 = (l605 + 1)) {
			fRec851[l605] = 0.0;
			
		}
		for (int l606 = 0; (l606 < 2); l606 = (l606 + 1)) {
			fRec849[l606] = 0.0;
			
		}
		for (int l607 = 0; (l607 < 2); l607 = (l607 + 1)) {
			fRec875[l607] = 0.0;
			
		}
		for (int l608 = 0; (l608 < 2); l608 = (l608 + 1)) {
			fRec873[l608] = 0.0;
			
		}
		for (int l609 = 0; (l609 < 2); l609 = (l609 + 1)) {
			fRec872[l609] = 0.0;
			
		}
		for (int l610 = 0; (l610 < 2); l610 = (l610 + 1)) {
			fRec870[l610] = 0.0;
			
		}
		for (int l611 = 0; (l611 < 2); l611 = (l611 + 1)) {
			fRec869[l611] = 0.0;
			
		}
		for (int l612 = 0; (l612 < 2); l612 = (l612 + 1)) {
			fRec867[l612] = 0.0;
			
		}
		for (int l613 = 0; (l613 < 2); l613 = (l613 + 1)) {
			fRec866[l613] = 0.0;
			
		}
		for (int l614 = 0; (l614 < 2); l614 = (l614 + 1)) {
			fRec864[l614] = 0.0;
			
		}
		for (int l615 = 0; (l615 < 2); l615 = (l615 + 1)) {
			fRec884[l615] = 0.0;
			
		}
		for (int l616 = 0; (l616 < 2); l616 = (l616 + 1)) {
			fRec882[l616] = 0.0;
			
		}
		for (int l617 = 0; (l617 < 2); l617 = (l617 + 1)) {
			fRec881[l617] = 0.0;
			
		}
		for (int l618 = 0; (l618 < 2); l618 = (l618 + 1)) {
			fRec879[l618] = 0.0;
			
		}
		for (int l619 = 0; (l619 < 2); l619 = (l619 + 1)) {
			fRec878[l619] = 0.0;
			
		}
		for (int l620 = 0; (l620 < 2); l620 = (l620 + 1)) {
			fRec876[l620] = 0.0;
			
		}
		for (int l621 = 0; (l621 < 2); l621 = (l621 + 1)) {
			fRec887[l621] = 0.0;
			
		}
		for (int l622 = 0; (l622 < 2); l622 = (l622 + 1)) {
			fRec885[l622] = 0.0;
			
		}
		for (int l623 = 0; (l623 < 2); l623 = (l623 + 1)) {
			fRec893[l623] = 0.0;
			
		}
		for (int l624 = 0; (l624 < 2); l624 = (l624 + 1)) {
			fRec891[l624] = 0.0;
			
		}
		for (int l625 = 0; (l625 < 2); l625 = (l625 + 1)) {
			fRec890[l625] = 0.0;
			
		}
		for (int l626 = 0; (l626 < 2); l626 = (l626 + 1)) {
			fRec888[l626] = 0.0;
			
		}
		for (int l627 = 0; (l627 < 128); l627 = (l627 + 1)) {
			fVec18[l627] = 0.0;
			
		}
		for (int l628 = 0; (l628 < 2); l628 = (l628 + 1)) {
			fRec908[l628] = 0.0;
			
		}
		for (int l629 = 0; (l629 < 2); l629 = (l629 + 1)) {
			fRec906[l629] = 0.0;
			
		}
		for (int l630 = 0; (l630 < 2); l630 = (l630 + 1)) {
			fRec905[l630] = 0.0;
			
		}
		for (int l631 = 0; (l631 < 2); l631 = (l631 + 1)) {
			fRec903[l631] = 0.0;
			
		}
		for (int l632 = 0; (l632 < 2); l632 = (l632 + 1)) {
			fRec902[l632] = 0.0;
			
		}
		for (int l633 = 0; (l633 < 2); l633 = (l633 + 1)) {
			fRec900[l633] = 0.0;
			
		}
		for (int l634 = 0; (l634 < 2); l634 = (l634 + 1)) {
			fRec899[l634] = 0.0;
			
		}
		for (int l635 = 0; (l635 < 2); l635 = (l635 + 1)) {
			fRec897[l635] = 0.0;
			
		}
		for (int l636 = 0; (l636 < 2); l636 = (l636 + 1)) {
			fRec896[l636] = 0.0;
			
		}
		for (int l637 = 0; (l637 < 2); l637 = (l637 + 1)) {
			fRec894[l637] = 0.0;
			
		}
		for (int l638 = 0; (l638 < 2); l638 = (l638 + 1)) {
			fRec920[l638] = 0.0;
			
		}
		for (int l639 = 0; (l639 < 2); l639 = (l639 + 1)) {
			fRec918[l639] = 0.0;
			
		}
		for (int l640 = 0; (l640 < 2); l640 = (l640 + 1)) {
			fRec917[l640] = 0.0;
			
		}
		for (int l641 = 0; (l641 < 2); l641 = (l641 + 1)) {
			fRec915[l641] = 0.0;
			
		}
		for (int l642 = 0; (l642 < 2); l642 = (l642 + 1)) {
			fRec914[l642] = 0.0;
			
		}
		for (int l643 = 0; (l643 < 2); l643 = (l643 + 1)) {
			fRec912[l643] = 0.0;
			
		}
		for (int l644 = 0; (l644 < 2); l644 = (l644 + 1)) {
			fRec911[l644] = 0.0;
			
		}
		for (int l645 = 0; (l645 < 2); l645 = (l645 + 1)) {
			fRec909[l645] = 0.0;
			
		}
		for (int l646 = 0; (l646 < 2); l646 = (l646 + 1)) {
			fRec929[l646] = 0.0;
			
		}
		for (int l647 = 0; (l647 < 2); l647 = (l647 + 1)) {
			fRec927[l647] = 0.0;
			
		}
		for (int l648 = 0; (l648 < 2); l648 = (l648 + 1)) {
			fRec926[l648] = 0.0;
			
		}
		for (int l649 = 0; (l649 < 2); l649 = (l649 + 1)) {
			fRec924[l649] = 0.0;
			
		}
		for (int l650 = 0; (l650 < 2); l650 = (l650 + 1)) {
			fRec923[l650] = 0.0;
			
		}
		for (int l651 = 0; (l651 < 2); l651 = (l651 + 1)) {
			fRec921[l651] = 0.0;
			
		}
		for (int l652 = 0; (l652 < 2); l652 = (l652 + 1)) {
			fRec932[l652] = 0.0;
			
		}
		for (int l653 = 0; (l653 < 2); l653 = (l653 + 1)) {
			fRec930[l653] = 0.0;
			
		}
		for (int l654 = 0; (l654 < 2); l654 = (l654 + 1)) {
			fRec938[l654] = 0.0;
			
		}
		for (int l655 = 0; (l655 < 2); l655 = (l655 + 1)) {
			fRec936[l655] = 0.0;
			
		}
		for (int l656 = 0; (l656 < 2); l656 = (l656 + 1)) {
			fRec935[l656] = 0.0;
			
		}
		for (int l657 = 0; (l657 < 2); l657 = (l657 + 1)) {
			fRec933[l657] = 0.0;
			
		}
		for (int l658 = 0; (l658 < 128); l658 = (l658 + 1)) {
			fVec19[l658] = 0.0;
			
		}
		for (int l659 = 0; (l659 < 2); l659 = (l659 + 1)) {
			fRec953[l659] = 0.0;
			
		}
		for (int l660 = 0; (l660 < 2); l660 = (l660 + 1)) {
			fRec951[l660] = 0.0;
			
		}
		for (int l661 = 0; (l661 < 2); l661 = (l661 + 1)) {
			fRec950[l661] = 0.0;
			
		}
		for (int l662 = 0; (l662 < 2); l662 = (l662 + 1)) {
			fRec948[l662] = 0.0;
			
		}
		for (int l663 = 0; (l663 < 2); l663 = (l663 + 1)) {
			fRec947[l663] = 0.0;
			
		}
		for (int l664 = 0; (l664 < 2); l664 = (l664 + 1)) {
			fRec945[l664] = 0.0;
			
		}
		for (int l665 = 0; (l665 < 2); l665 = (l665 + 1)) {
			fRec944[l665] = 0.0;
			
		}
		for (int l666 = 0; (l666 < 2); l666 = (l666 + 1)) {
			fRec942[l666] = 0.0;
			
		}
		for (int l667 = 0; (l667 < 2); l667 = (l667 + 1)) {
			fRec941[l667] = 0.0;
			
		}
		for (int l668 = 0; (l668 < 2); l668 = (l668 + 1)) {
			fRec939[l668] = 0.0;
			
		}
		for (int l669 = 0; (l669 < 2); l669 = (l669 + 1)) {
			fRec965[l669] = 0.0;
			
		}
		for (int l670 = 0; (l670 < 2); l670 = (l670 + 1)) {
			fRec963[l670] = 0.0;
			
		}
		for (int l671 = 0; (l671 < 2); l671 = (l671 + 1)) {
			fRec962[l671] = 0.0;
			
		}
		for (int l672 = 0; (l672 < 2); l672 = (l672 + 1)) {
			fRec960[l672] = 0.0;
			
		}
		for (int l673 = 0; (l673 < 2); l673 = (l673 + 1)) {
			fRec959[l673] = 0.0;
			
		}
		for (int l674 = 0; (l674 < 2); l674 = (l674 + 1)) {
			fRec957[l674] = 0.0;
			
		}
		for (int l675 = 0; (l675 < 2); l675 = (l675 + 1)) {
			fRec956[l675] = 0.0;
			
		}
		for (int l676 = 0; (l676 < 2); l676 = (l676 + 1)) {
			fRec954[l676] = 0.0;
			
		}
		for (int l677 = 0; (l677 < 2); l677 = (l677 + 1)) {
			fRec974[l677] = 0.0;
			
		}
		for (int l678 = 0; (l678 < 2); l678 = (l678 + 1)) {
			fRec972[l678] = 0.0;
			
		}
		for (int l679 = 0; (l679 < 2); l679 = (l679 + 1)) {
			fRec971[l679] = 0.0;
			
		}
		for (int l680 = 0; (l680 < 2); l680 = (l680 + 1)) {
			fRec969[l680] = 0.0;
			
		}
		for (int l681 = 0; (l681 < 2); l681 = (l681 + 1)) {
			fRec968[l681] = 0.0;
			
		}
		for (int l682 = 0; (l682 < 2); l682 = (l682 + 1)) {
			fRec966[l682] = 0.0;
			
		}
		for (int l683 = 0; (l683 < 2); l683 = (l683 + 1)) {
			fRec977[l683] = 0.0;
			
		}
		for (int l684 = 0; (l684 < 2); l684 = (l684 + 1)) {
			fRec975[l684] = 0.0;
			
		}
		for (int l685 = 0; (l685 < 2); l685 = (l685 + 1)) {
			fRec983[l685] = 0.0;
			
		}
		for (int l686 = 0; (l686 < 2); l686 = (l686 + 1)) {
			fRec981[l686] = 0.0;
			
		}
		for (int l687 = 0; (l687 < 2); l687 = (l687 + 1)) {
			fRec980[l687] = 0.0;
			
		}
		for (int l688 = 0; (l688 < 2); l688 = (l688 + 1)) {
			fRec978[l688] = 0.0;
			
		}
		for (int l689 = 0; (l689 < 128); l689 = (l689 + 1)) {
			fVec20[l689] = 0.0;
			
		}
		for (int l690 = 0; (l690 < 2); l690 = (l690 + 1)) {
			fRec998[l690] = 0.0;
			
		}
		for (int l691 = 0; (l691 < 2); l691 = (l691 + 1)) {
			fRec996[l691] = 0.0;
			
		}
		for (int l692 = 0; (l692 < 2); l692 = (l692 + 1)) {
			fRec995[l692] = 0.0;
			
		}
		for (int l693 = 0; (l693 < 2); l693 = (l693 + 1)) {
			fRec993[l693] = 0.0;
			
		}
		for (int l694 = 0; (l694 < 2); l694 = (l694 + 1)) {
			fRec992[l694] = 0.0;
			
		}
		for (int l695 = 0; (l695 < 2); l695 = (l695 + 1)) {
			fRec990[l695] = 0.0;
			
		}
		for (int l696 = 0; (l696 < 2); l696 = (l696 + 1)) {
			fRec989[l696] = 0.0;
			
		}
		for (int l697 = 0; (l697 < 2); l697 = (l697 + 1)) {
			fRec987[l697] = 0.0;
			
		}
		for (int l698 = 0; (l698 < 2); l698 = (l698 + 1)) {
			fRec986[l698] = 0.0;
			
		}
		for (int l699 = 0; (l699 < 2); l699 = (l699 + 1)) {
			fRec984[l699] = 0.0;
			
		}
		for (int l700 = 0; (l700 < 2); l700 = (l700 + 1)) {
			fRec1010[l700] = 0.0;
			
		}
		for (int l701 = 0; (l701 < 2); l701 = (l701 + 1)) {
			fRec1008[l701] = 0.0;
			
		}
		for (int l702 = 0; (l702 < 2); l702 = (l702 + 1)) {
			fRec1007[l702] = 0.0;
			
		}
		for (int l703 = 0; (l703 < 2); l703 = (l703 + 1)) {
			fRec1005[l703] = 0.0;
			
		}
		for (int l704 = 0; (l704 < 2); l704 = (l704 + 1)) {
			fRec1004[l704] = 0.0;
			
		}
		for (int l705 = 0; (l705 < 2); l705 = (l705 + 1)) {
			fRec1002[l705] = 0.0;
			
		}
		for (int l706 = 0; (l706 < 2); l706 = (l706 + 1)) {
			fRec1001[l706] = 0.0;
			
		}
		for (int l707 = 0; (l707 < 2); l707 = (l707 + 1)) {
			fRec999[l707] = 0.0;
			
		}
		for (int l708 = 0; (l708 < 2); l708 = (l708 + 1)) {
			fRec1019[l708] = 0.0;
			
		}
		for (int l709 = 0; (l709 < 2); l709 = (l709 + 1)) {
			fRec1017[l709] = 0.0;
			
		}
		for (int l710 = 0; (l710 < 2); l710 = (l710 + 1)) {
			fRec1016[l710] = 0.0;
			
		}
		for (int l711 = 0; (l711 < 2); l711 = (l711 + 1)) {
			fRec1014[l711] = 0.0;
			
		}
		for (int l712 = 0; (l712 < 2); l712 = (l712 + 1)) {
			fRec1013[l712] = 0.0;
			
		}
		for (int l713 = 0; (l713 < 2); l713 = (l713 + 1)) {
			fRec1011[l713] = 0.0;
			
		}
		for (int l714 = 0; (l714 < 2); l714 = (l714 + 1)) {
			fRec1022[l714] = 0.0;
			
		}
		for (int l715 = 0; (l715 < 2); l715 = (l715 + 1)) {
			fRec1020[l715] = 0.0;
			
		}
		for (int l716 = 0; (l716 < 2); l716 = (l716 + 1)) {
			fRec1028[l716] = 0.0;
			
		}
		for (int l717 = 0; (l717 < 2); l717 = (l717 + 1)) {
			fRec1026[l717] = 0.0;
			
		}
		for (int l718 = 0; (l718 < 2); l718 = (l718 + 1)) {
			fRec1025[l718] = 0.0;
			
		}
		for (int l719 = 0; (l719 < 2); l719 = (l719 + 1)) {
			fRec1023[l719] = 0.0;
			
		}
		for (int l720 = 0; (l720 < 128); l720 = (l720 + 1)) {
			fVec21[l720] = 0.0;
			
		}
		for (int l721 = 0; (l721 < 2); l721 = (l721 + 1)) {
			fRec1043[l721] = 0.0;
			
		}
		for (int l722 = 0; (l722 < 2); l722 = (l722 + 1)) {
			fRec1041[l722] = 0.0;
			
		}
		for (int l723 = 0; (l723 < 2); l723 = (l723 + 1)) {
			fRec1040[l723] = 0.0;
			
		}
		for (int l724 = 0; (l724 < 2); l724 = (l724 + 1)) {
			fRec1038[l724] = 0.0;
			
		}
		for (int l725 = 0; (l725 < 2); l725 = (l725 + 1)) {
			fRec1037[l725] = 0.0;
			
		}
		for (int l726 = 0; (l726 < 2); l726 = (l726 + 1)) {
			fRec1035[l726] = 0.0;
			
		}
		for (int l727 = 0; (l727 < 2); l727 = (l727 + 1)) {
			fRec1034[l727] = 0.0;
			
		}
		for (int l728 = 0; (l728 < 2); l728 = (l728 + 1)) {
			fRec1032[l728] = 0.0;
			
		}
		for (int l729 = 0; (l729 < 2); l729 = (l729 + 1)) {
			fRec1031[l729] = 0.0;
			
		}
		for (int l730 = 0; (l730 < 2); l730 = (l730 + 1)) {
			fRec1029[l730] = 0.0;
			
		}
		for (int l731 = 0; (l731 < 2); l731 = (l731 + 1)) {
			fRec1055[l731] = 0.0;
			
		}
		for (int l732 = 0; (l732 < 2); l732 = (l732 + 1)) {
			fRec1053[l732] = 0.0;
			
		}
		for (int l733 = 0; (l733 < 2); l733 = (l733 + 1)) {
			fRec1052[l733] = 0.0;
			
		}
		for (int l734 = 0; (l734 < 2); l734 = (l734 + 1)) {
			fRec1050[l734] = 0.0;
			
		}
		for (int l735 = 0; (l735 < 2); l735 = (l735 + 1)) {
			fRec1049[l735] = 0.0;
			
		}
		for (int l736 = 0; (l736 < 2); l736 = (l736 + 1)) {
			fRec1047[l736] = 0.0;
			
		}
		for (int l737 = 0; (l737 < 2); l737 = (l737 + 1)) {
			fRec1046[l737] = 0.0;
			
		}
		for (int l738 = 0; (l738 < 2); l738 = (l738 + 1)) {
			fRec1044[l738] = 0.0;
			
		}
		for (int l739 = 0; (l739 < 2); l739 = (l739 + 1)) {
			fRec1064[l739] = 0.0;
			
		}
		for (int l740 = 0; (l740 < 2); l740 = (l740 + 1)) {
			fRec1062[l740] = 0.0;
			
		}
		for (int l741 = 0; (l741 < 2); l741 = (l741 + 1)) {
			fRec1061[l741] = 0.0;
			
		}
		for (int l742 = 0; (l742 < 2); l742 = (l742 + 1)) {
			fRec1059[l742] = 0.0;
			
		}
		for (int l743 = 0; (l743 < 2); l743 = (l743 + 1)) {
			fRec1058[l743] = 0.0;
			
		}
		for (int l744 = 0; (l744 < 2); l744 = (l744 + 1)) {
			fRec1056[l744] = 0.0;
			
		}
		for (int l745 = 0; (l745 < 2); l745 = (l745 + 1)) {
			fRec1067[l745] = 0.0;
			
		}
		for (int l746 = 0; (l746 < 2); l746 = (l746 + 1)) {
			fRec1065[l746] = 0.0;
			
		}
		for (int l747 = 0; (l747 < 2); l747 = (l747 + 1)) {
			fRec1073[l747] = 0.0;
			
		}
		for (int l748 = 0; (l748 < 2); l748 = (l748 + 1)) {
			fRec1071[l748] = 0.0;
			
		}
		for (int l749 = 0; (l749 < 2); l749 = (l749 + 1)) {
			fRec1070[l749] = 0.0;
			
		}
		for (int l750 = 0; (l750 < 2); l750 = (l750 + 1)) {
			fRec1068[l750] = 0.0;
			
		}
		for (int l751 = 0; (l751 < 128); l751 = (l751 + 1)) {
			fVec22[l751] = 0.0;
			
		}
		for (int l752 = 0; (l752 < 2); l752 = (l752 + 1)) {
			fRec1088[l752] = 0.0;
			
		}
		for (int l753 = 0; (l753 < 2); l753 = (l753 + 1)) {
			fRec1086[l753] = 0.0;
			
		}
		for (int l754 = 0; (l754 < 2); l754 = (l754 + 1)) {
			fRec1085[l754] = 0.0;
			
		}
		for (int l755 = 0; (l755 < 2); l755 = (l755 + 1)) {
			fRec1083[l755] = 0.0;
			
		}
		for (int l756 = 0; (l756 < 2); l756 = (l756 + 1)) {
			fRec1082[l756] = 0.0;
			
		}
		for (int l757 = 0; (l757 < 2); l757 = (l757 + 1)) {
			fRec1080[l757] = 0.0;
			
		}
		for (int l758 = 0; (l758 < 2); l758 = (l758 + 1)) {
			fRec1079[l758] = 0.0;
			
		}
		for (int l759 = 0; (l759 < 2); l759 = (l759 + 1)) {
			fRec1077[l759] = 0.0;
			
		}
		for (int l760 = 0; (l760 < 2); l760 = (l760 + 1)) {
			fRec1076[l760] = 0.0;
			
		}
		for (int l761 = 0; (l761 < 2); l761 = (l761 + 1)) {
			fRec1074[l761] = 0.0;
			
		}
		for (int l762 = 0; (l762 < 2); l762 = (l762 + 1)) {
			fRec1100[l762] = 0.0;
			
		}
		for (int l763 = 0; (l763 < 2); l763 = (l763 + 1)) {
			fRec1098[l763] = 0.0;
			
		}
		for (int l764 = 0; (l764 < 2); l764 = (l764 + 1)) {
			fRec1097[l764] = 0.0;
			
		}
		for (int l765 = 0; (l765 < 2); l765 = (l765 + 1)) {
			fRec1095[l765] = 0.0;
			
		}
		for (int l766 = 0; (l766 < 2); l766 = (l766 + 1)) {
			fRec1094[l766] = 0.0;
			
		}
		for (int l767 = 0; (l767 < 2); l767 = (l767 + 1)) {
			fRec1092[l767] = 0.0;
			
		}
		for (int l768 = 0; (l768 < 2); l768 = (l768 + 1)) {
			fRec1091[l768] = 0.0;
			
		}
		for (int l769 = 0; (l769 < 2); l769 = (l769 + 1)) {
			fRec1089[l769] = 0.0;
			
		}
		for (int l770 = 0; (l770 < 2); l770 = (l770 + 1)) {
			fRec1109[l770] = 0.0;
			
		}
		for (int l771 = 0; (l771 < 2); l771 = (l771 + 1)) {
			fRec1107[l771] = 0.0;
			
		}
		for (int l772 = 0; (l772 < 2); l772 = (l772 + 1)) {
			fRec1106[l772] = 0.0;
			
		}
		for (int l773 = 0; (l773 < 2); l773 = (l773 + 1)) {
			fRec1104[l773] = 0.0;
			
		}
		for (int l774 = 0; (l774 < 2); l774 = (l774 + 1)) {
			fRec1103[l774] = 0.0;
			
		}
		for (int l775 = 0; (l775 < 2); l775 = (l775 + 1)) {
			fRec1101[l775] = 0.0;
			
		}
		for (int l776 = 0; (l776 < 2); l776 = (l776 + 1)) {
			fRec1112[l776] = 0.0;
			
		}
		for (int l777 = 0; (l777 < 2); l777 = (l777 + 1)) {
			fRec1110[l777] = 0.0;
			
		}
		for (int l778 = 0; (l778 < 2); l778 = (l778 + 1)) {
			fRec1118[l778] = 0.0;
			
		}
		for (int l779 = 0; (l779 < 2); l779 = (l779 + 1)) {
			fRec1116[l779] = 0.0;
			
		}
		for (int l780 = 0; (l780 < 2); l780 = (l780 + 1)) {
			fRec1115[l780] = 0.0;
			
		}
		for (int l781 = 0; (l781 < 2); l781 = (l781 + 1)) {
			fRec1113[l781] = 0.0;
			
		}
		for (int l782 = 0; (l782 < 128); l782 = (l782 + 1)) {
			fVec23[l782] = 0.0;
			
		}
		for (int l783 = 0; (l783 < 2); l783 = (l783 + 1)) {
			fRec1133[l783] = 0.0;
			
		}
		for (int l784 = 0; (l784 < 2); l784 = (l784 + 1)) {
			fRec1131[l784] = 0.0;
			
		}
		for (int l785 = 0; (l785 < 2); l785 = (l785 + 1)) {
			fRec1130[l785] = 0.0;
			
		}
		for (int l786 = 0; (l786 < 2); l786 = (l786 + 1)) {
			fRec1128[l786] = 0.0;
			
		}
		for (int l787 = 0; (l787 < 2); l787 = (l787 + 1)) {
			fRec1127[l787] = 0.0;
			
		}
		for (int l788 = 0; (l788 < 2); l788 = (l788 + 1)) {
			fRec1125[l788] = 0.0;
			
		}
		for (int l789 = 0; (l789 < 2); l789 = (l789 + 1)) {
			fRec1124[l789] = 0.0;
			
		}
		for (int l790 = 0; (l790 < 2); l790 = (l790 + 1)) {
			fRec1122[l790] = 0.0;
			
		}
		for (int l791 = 0; (l791 < 2); l791 = (l791 + 1)) {
			fRec1121[l791] = 0.0;
			
		}
		for (int l792 = 0; (l792 < 2); l792 = (l792 + 1)) {
			fRec1119[l792] = 0.0;
			
		}
		for (int l793 = 0; (l793 < 2); l793 = (l793 + 1)) {
			fRec1145[l793] = 0.0;
			
		}
		for (int l794 = 0; (l794 < 2); l794 = (l794 + 1)) {
			fRec1143[l794] = 0.0;
			
		}
		for (int l795 = 0; (l795 < 2); l795 = (l795 + 1)) {
			fRec1142[l795] = 0.0;
			
		}
		for (int l796 = 0; (l796 < 2); l796 = (l796 + 1)) {
			fRec1140[l796] = 0.0;
			
		}
		for (int l797 = 0; (l797 < 2); l797 = (l797 + 1)) {
			fRec1139[l797] = 0.0;
			
		}
		for (int l798 = 0; (l798 < 2); l798 = (l798 + 1)) {
			fRec1137[l798] = 0.0;
			
		}
		for (int l799 = 0; (l799 < 2); l799 = (l799 + 1)) {
			fRec1136[l799] = 0.0;
			
		}
		for (int l800 = 0; (l800 < 2); l800 = (l800 + 1)) {
			fRec1134[l800] = 0.0;
			
		}
		for (int l801 = 0; (l801 < 2); l801 = (l801 + 1)) {
			fRec1154[l801] = 0.0;
			
		}
		for (int l802 = 0; (l802 < 2); l802 = (l802 + 1)) {
			fRec1152[l802] = 0.0;
			
		}
		for (int l803 = 0; (l803 < 2); l803 = (l803 + 1)) {
			fRec1151[l803] = 0.0;
			
		}
		for (int l804 = 0; (l804 < 2); l804 = (l804 + 1)) {
			fRec1149[l804] = 0.0;
			
		}
		for (int l805 = 0; (l805 < 2); l805 = (l805 + 1)) {
			fRec1148[l805] = 0.0;
			
		}
		for (int l806 = 0; (l806 < 2); l806 = (l806 + 1)) {
			fRec1146[l806] = 0.0;
			
		}
		for (int l807 = 0; (l807 < 2); l807 = (l807 + 1)) {
			fRec1157[l807] = 0.0;
			
		}
		for (int l808 = 0; (l808 < 2); l808 = (l808 + 1)) {
			fRec1155[l808] = 0.0;
			
		}
		for (int l809 = 0; (l809 < 2); l809 = (l809 + 1)) {
			fRec1163[l809] = 0.0;
			
		}
		for (int l810 = 0; (l810 < 2); l810 = (l810 + 1)) {
			fRec1161[l810] = 0.0;
			
		}
		for (int l811 = 0; (l811 < 2); l811 = (l811 + 1)) {
			fRec1160[l811] = 0.0;
			
		}
		for (int l812 = 0; (l812 < 2); l812 = (l812 + 1)) {
			fRec1158[l812] = 0.0;
			
		}
		for (int l813 = 0; (l813 < 12); l813 = (l813 + 1)) {
			fVec24[l813] = 0.0;
			
		}
		for (int l814 = 0; (l814 < 2); l814 = (l814 + 1)) {
			fRec1178[l814] = 0.0;
			
		}
		for (int l815 = 0; (l815 < 2); l815 = (l815 + 1)) {
			fRec1176[l815] = 0.0;
			
		}
		for (int l816 = 0; (l816 < 2); l816 = (l816 + 1)) {
			fRec1175[l816] = 0.0;
			
		}
		for (int l817 = 0; (l817 < 2); l817 = (l817 + 1)) {
			fRec1173[l817] = 0.0;
			
		}
		for (int l818 = 0; (l818 < 2); l818 = (l818 + 1)) {
			fRec1172[l818] = 0.0;
			
		}
		for (int l819 = 0; (l819 < 2); l819 = (l819 + 1)) {
			fRec1170[l819] = 0.0;
			
		}
		for (int l820 = 0; (l820 < 2); l820 = (l820 + 1)) {
			fRec1169[l820] = 0.0;
			
		}
		for (int l821 = 0; (l821 < 2); l821 = (l821 + 1)) {
			fRec1167[l821] = 0.0;
			
		}
		for (int l822 = 0; (l822 < 2); l822 = (l822 + 1)) {
			fRec1166[l822] = 0.0;
			
		}
		for (int l823 = 0; (l823 < 2); l823 = (l823 + 1)) {
			fRec1164[l823] = 0.0;
			
		}
		for (int l824 = 0; (l824 < 2); l824 = (l824 + 1)) {
			fRec1190[l824] = 0.0;
			
		}
		for (int l825 = 0; (l825 < 2); l825 = (l825 + 1)) {
			fRec1188[l825] = 0.0;
			
		}
		for (int l826 = 0; (l826 < 2); l826 = (l826 + 1)) {
			fRec1187[l826] = 0.0;
			
		}
		for (int l827 = 0; (l827 < 2); l827 = (l827 + 1)) {
			fRec1185[l827] = 0.0;
			
		}
		for (int l828 = 0; (l828 < 2); l828 = (l828 + 1)) {
			fRec1184[l828] = 0.0;
			
		}
		for (int l829 = 0; (l829 < 2); l829 = (l829 + 1)) {
			fRec1182[l829] = 0.0;
			
		}
		for (int l830 = 0; (l830 < 2); l830 = (l830 + 1)) {
			fRec1181[l830] = 0.0;
			
		}
		for (int l831 = 0; (l831 < 2); l831 = (l831 + 1)) {
			fRec1179[l831] = 0.0;
			
		}
		for (int l832 = 0; (l832 < 2); l832 = (l832 + 1)) {
			fRec1199[l832] = 0.0;
			
		}
		for (int l833 = 0; (l833 < 2); l833 = (l833 + 1)) {
			fRec1197[l833] = 0.0;
			
		}
		for (int l834 = 0; (l834 < 2); l834 = (l834 + 1)) {
			fRec1196[l834] = 0.0;
			
		}
		for (int l835 = 0; (l835 < 2); l835 = (l835 + 1)) {
			fRec1194[l835] = 0.0;
			
		}
		for (int l836 = 0; (l836 < 2); l836 = (l836 + 1)) {
			fRec1193[l836] = 0.0;
			
		}
		for (int l837 = 0; (l837 < 2); l837 = (l837 + 1)) {
			fRec1191[l837] = 0.0;
			
		}
		for (int l838 = 0; (l838 < 2); l838 = (l838 + 1)) {
			fRec1202[l838] = 0.0;
			
		}
		for (int l839 = 0; (l839 < 2); l839 = (l839 + 1)) {
			fRec1200[l839] = 0.0;
			
		}
		for (int l840 = 0; (l840 < 2); l840 = (l840 + 1)) {
			fRec1208[l840] = 0.0;
			
		}
		for (int l841 = 0; (l841 < 2); l841 = (l841 + 1)) {
			fRec1206[l841] = 0.0;
			
		}
		for (int l842 = 0; (l842 < 2); l842 = (l842 + 1)) {
			fRec1205[l842] = 0.0;
			
		}
		for (int l843 = 0; (l843 < 2); l843 = (l843 + 1)) {
			fRec1203[l843] = 0.0;
			
		}
		for (int l844 = 0; (l844 < 12); l844 = (l844 + 1)) {
			fVec25[l844] = 0.0;
			
		}
		for (int l845 = 0; (l845 < 2); l845 = (l845 + 1)) {
			fRec1223[l845] = 0.0;
			
		}
		for (int l846 = 0; (l846 < 2); l846 = (l846 + 1)) {
			fRec1221[l846] = 0.0;
			
		}
		for (int l847 = 0; (l847 < 2); l847 = (l847 + 1)) {
			fRec1220[l847] = 0.0;
			
		}
		for (int l848 = 0; (l848 < 2); l848 = (l848 + 1)) {
			fRec1218[l848] = 0.0;
			
		}
		for (int l849 = 0; (l849 < 2); l849 = (l849 + 1)) {
			fRec1217[l849] = 0.0;
			
		}
		for (int l850 = 0; (l850 < 2); l850 = (l850 + 1)) {
			fRec1215[l850] = 0.0;
			
		}
		for (int l851 = 0; (l851 < 2); l851 = (l851 + 1)) {
			fRec1214[l851] = 0.0;
			
		}
		for (int l852 = 0; (l852 < 2); l852 = (l852 + 1)) {
			fRec1212[l852] = 0.0;
			
		}
		for (int l853 = 0; (l853 < 2); l853 = (l853 + 1)) {
			fRec1211[l853] = 0.0;
			
		}
		for (int l854 = 0; (l854 < 2); l854 = (l854 + 1)) {
			fRec1209[l854] = 0.0;
			
		}
		for (int l855 = 0; (l855 < 2); l855 = (l855 + 1)) {
			fRec1235[l855] = 0.0;
			
		}
		for (int l856 = 0; (l856 < 2); l856 = (l856 + 1)) {
			fRec1233[l856] = 0.0;
			
		}
		for (int l857 = 0; (l857 < 2); l857 = (l857 + 1)) {
			fRec1232[l857] = 0.0;
			
		}
		for (int l858 = 0; (l858 < 2); l858 = (l858 + 1)) {
			fRec1230[l858] = 0.0;
			
		}
		for (int l859 = 0; (l859 < 2); l859 = (l859 + 1)) {
			fRec1229[l859] = 0.0;
			
		}
		for (int l860 = 0; (l860 < 2); l860 = (l860 + 1)) {
			fRec1227[l860] = 0.0;
			
		}
		for (int l861 = 0; (l861 < 2); l861 = (l861 + 1)) {
			fRec1226[l861] = 0.0;
			
		}
		for (int l862 = 0; (l862 < 2); l862 = (l862 + 1)) {
			fRec1224[l862] = 0.0;
			
		}
		for (int l863 = 0; (l863 < 2); l863 = (l863 + 1)) {
			fRec1244[l863] = 0.0;
			
		}
		for (int l864 = 0; (l864 < 2); l864 = (l864 + 1)) {
			fRec1242[l864] = 0.0;
			
		}
		for (int l865 = 0; (l865 < 2); l865 = (l865 + 1)) {
			fRec1241[l865] = 0.0;
			
		}
		for (int l866 = 0; (l866 < 2); l866 = (l866 + 1)) {
			fRec1239[l866] = 0.0;
			
		}
		for (int l867 = 0; (l867 < 2); l867 = (l867 + 1)) {
			fRec1238[l867] = 0.0;
			
		}
		for (int l868 = 0; (l868 < 2); l868 = (l868 + 1)) {
			fRec1236[l868] = 0.0;
			
		}
		for (int l869 = 0; (l869 < 2); l869 = (l869 + 1)) {
			fRec1247[l869] = 0.0;
			
		}
		for (int l870 = 0; (l870 < 2); l870 = (l870 + 1)) {
			fRec1245[l870] = 0.0;
			
		}
		for (int l871 = 0; (l871 < 2); l871 = (l871 + 1)) {
			fRec1253[l871] = 0.0;
			
		}
		for (int l872 = 0; (l872 < 2); l872 = (l872 + 1)) {
			fRec1251[l872] = 0.0;
			
		}
		for (int l873 = 0; (l873 < 2); l873 = (l873 + 1)) {
			fRec1250[l873] = 0.0;
			
		}
		for (int l874 = 0; (l874 < 2); l874 = (l874 + 1)) {
			fRec1248[l874] = 0.0;
			
		}
		for (int l875 = 0; (l875 < 12); l875 = (l875 + 1)) {
			fVec26[l875] = 0.0;
			
		}
		for (int l876 = 0; (l876 < 2); l876 = (l876 + 1)) {
			fRec1268[l876] = 0.0;
			
		}
		for (int l877 = 0; (l877 < 2); l877 = (l877 + 1)) {
			fRec1266[l877] = 0.0;
			
		}
		for (int l878 = 0; (l878 < 2); l878 = (l878 + 1)) {
			fRec1265[l878] = 0.0;
			
		}
		for (int l879 = 0; (l879 < 2); l879 = (l879 + 1)) {
			fRec1263[l879] = 0.0;
			
		}
		for (int l880 = 0; (l880 < 2); l880 = (l880 + 1)) {
			fRec1262[l880] = 0.0;
			
		}
		for (int l881 = 0; (l881 < 2); l881 = (l881 + 1)) {
			fRec1260[l881] = 0.0;
			
		}
		for (int l882 = 0; (l882 < 2); l882 = (l882 + 1)) {
			fRec1259[l882] = 0.0;
			
		}
		for (int l883 = 0; (l883 < 2); l883 = (l883 + 1)) {
			fRec1257[l883] = 0.0;
			
		}
		for (int l884 = 0; (l884 < 2); l884 = (l884 + 1)) {
			fRec1256[l884] = 0.0;
			
		}
		for (int l885 = 0; (l885 < 2); l885 = (l885 + 1)) {
			fRec1254[l885] = 0.0;
			
		}
		for (int l886 = 0; (l886 < 2); l886 = (l886 + 1)) {
			fRec1280[l886] = 0.0;
			
		}
		for (int l887 = 0; (l887 < 2); l887 = (l887 + 1)) {
			fRec1278[l887] = 0.0;
			
		}
		for (int l888 = 0; (l888 < 2); l888 = (l888 + 1)) {
			fRec1277[l888] = 0.0;
			
		}
		for (int l889 = 0; (l889 < 2); l889 = (l889 + 1)) {
			fRec1275[l889] = 0.0;
			
		}
		for (int l890 = 0; (l890 < 2); l890 = (l890 + 1)) {
			fRec1274[l890] = 0.0;
			
		}
		for (int l891 = 0; (l891 < 2); l891 = (l891 + 1)) {
			fRec1272[l891] = 0.0;
			
		}
		for (int l892 = 0; (l892 < 2); l892 = (l892 + 1)) {
			fRec1271[l892] = 0.0;
			
		}
		for (int l893 = 0; (l893 < 2); l893 = (l893 + 1)) {
			fRec1269[l893] = 0.0;
			
		}
		for (int l894 = 0; (l894 < 2); l894 = (l894 + 1)) {
			fRec1289[l894] = 0.0;
			
		}
		for (int l895 = 0; (l895 < 2); l895 = (l895 + 1)) {
			fRec1287[l895] = 0.0;
			
		}
		for (int l896 = 0; (l896 < 2); l896 = (l896 + 1)) {
			fRec1286[l896] = 0.0;
			
		}
		for (int l897 = 0; (l897 < 2); l897 = (l897 + 1)) {
			fRec1284[l897] = 0.0;
			
		}
		for (int l898 = 0; (l898 < 2); l898 = (l898 + 1)) {
			fRec1283[l898] = 0.0;
			
		}
		for (int l899 = 0; (l899 < 2); l899 = (l899 + 1)) {
			fRec1281[l899] = 0.0;
			
		}
		for (int l900 = 0; (l900 < 2); l900 = (l900 + 1)) {
			fRec1292[l900] = 0.0;
			
		}
		for (int l901 = 0; (l901 < 2); l901 = (l901 + 1)) {
			fRec1290[l901] = 0.0;
			
		}
		for (int l902 = 0; (l902 < 2); l902 = (l902 + 1)) {
			fRec1298[l902] = 0.0;
			
		}
		for (int l903 = 0; (l903 < 2); l903 = (l903 + 1)) {
			fRec1296[l903] = 0.0;
			
		}
		for (int l904 = 0; (l904 < 2); l904 = (l904 + 1)) {
			fRec1295[l904] = 0.0;
			
		}
		for (int l905 = 0; (l905 < 2); l905 = (l905 + 1)) {
			fRec1293[l905] = 0.0;
			
		}
		for (int l906 = 0; (l906 < 12); l906 = (l906 + 1)) {
			fVec27[l906] = 0.0;
			
		}
		for (int l907 = 0; (l907 < 2); l907 = (l907 + 1)) {
			fRec1313[l907] = 0.0;
			
		}
		for (int l908 = 0; (l908 < 2); l908 = (l908 + 1)) {
			fRec1311[l908] = 0.0;
			
		}
		for (int l909 = 0; (l909 < 2); l909 = (l909 + 1)) {
			fRec1310[l909] = 0.0;
			
		}
		for (int l910 = 0; (l910 < 2); l910 = (l910 + 1)) {
			fRec1308[l910] = 0.0;
			
		}
		for (int l911 = 0; (l911 < 2); l911 = (l911 + 1)) {
			fRec1307[l911] = 0.0;
			
		}
		for (int l912 = 0; (l912 < 2); l912 = (l912 + 1)) {
			fRec1305[l912] = 0.0;
			
		}
		for (int l913 = 0; (l913 < 2); l913 = (l913 + 1)) {
			fRec1304[l913] = 0.0;
			
		}
		for (int l914 = 0; (l914 < 2); l914 = (l914 + 1)) {
			fRec1302[l914] = 0.0;
			
		}
		for (int l915 = 0; (l915 < 2); l915 = (l915 + 1)) {
			fRec1301[l915] = 0.0;
			
		}
		for (int l916 = 0; (l916 < 2); l916 = (l916 + 1)) {
			fRec1299[l916] = 0.0;
			
		}
		for (int l917 = 0; (l917 < 2); l917 = (l917 + 1)) {
			fRec1325[l917] = 0.0;
			
		}
		for (int l918 = 0; (l918 < 2); l918 = (l918 + 1)) {
			fRec1323[l918] = 0.0;
			
		}
		for (int l919 = 0; (l919 < 2); l919 = (l919 + 1)) {
			fRec1322[l919] = 0.0;
			
		}
		for (int l920 = 0; (l920 < 2); l920 = (l920 + 1)) {
			fRec1320[l920] = 0.0;
			
		}
		for (int l921 = 0; (l921 < 2); l921 = (l921 + 1)) {
			fRec1319[l921] = 0.0;
			
		}
		for (int l922 = 0; (l922 < 2); l922 = (l922 + 1)) {
			fRec1317[l922] = 0.0;
			
		}
		for (int l923 = 0; (l923 < 2); l923 = (l923 + 1)) {
			fRec1316[l923] = 0.0;
			
		}
		for (int l924 = 0; (l924 < 2); l924 = (l924 + 1)) {
			fRec1314[l924] = 0.0;
			
		}
		for (int l925 = 0; (l925 < 2); l925 = (l925 + 1)) {
			fRec1334[l925] = 0.0;
			
		}
		for (int l926 = 0; (l926 < 2); l926 = (l926 + 1)) {
			fRec1332[l926] = 0.0;
			
		}
		for (int l927 = 0; (l927 < 2); l927 = (l927 + 1)) {
			fRec1331[l927] = 0.0;
			
		}
		for (int l928 = 0; (l928 < 2); l928 = (l928 + 1)) {
			fRec1329[l928] = 0.0;
			
		}
		for (int l929 = 0; (l929 < 2); l929 = (l929 + 1)) {
			fRec1328[l929] = 0.0;
			
		}
		for (int l930 = 0; (l930 < 2); l930 = (l930 + 1)) {
			fRec1326[l930] = 0.0;
			
		}
		for (int l931 = 0; (l931 < 2); l931 = (l931 + 1)) {
			fRec1337[l931] = 0.0;
			
		}
		for (int l932 = 0; (l932 < 2); l932 = (l932 + 1)) {
			fRec1335[l932] = 0.0;
			
		}
		for (int l933 = 0; (l933 < 2); l933 = (l933 + 1)) {
			fRec1343[l933] = 0.0;
			
		}
		for (int l934 = 0; (l934 < 2); l934 = (l934 + 1)) {
			fRec1341[l934] = 0.0;
			
		}
		for (int l935 = 0; (l935 < 2); l935 = (l935 + 1)) {
			fRec1340[l935] = 0.0;
			
		}
		for (int l936 = 0; (l936 < 2); l936 = (l936 + 1)) {
			fRec1338[l936] = 0.0;
			
		}
		for (int l937 = 0; (l937 < 2); l937 = (l937 + 1)) {
			fRec1358[l937] = 0.0;
			
		}
		for (int l938 = 0; (l938 < 2); l938 = (l938 + 1)) {
			fRec1356[l938] = 0.0;
			
		}
		for (int l939 = 0; (l939 < 2); l939 = (l939 + 1)) {
			fRec1355[l939] = 0.0;
			
		}
		for (int l940 = 0; (l940 < 2); l940 = (l940 + 1)) {
			fRec1353[l940] = 0.0;
			
		}
		for (int l941 = 0; (l941 < 2); l941 = (l941 + 1)) {
			fRec1352[l941] = 0.0;
			
		}
		for (int l942 = 0; (l942 < 2); l942 = (l942 + 1)) {
			fRec1350[l942] = 0.0;
			
		}
		for (int l943 = 0; (l943 < 2); l943 = (l943 + 1)) {
			fRec1349[l943] = 0.0;
			
		}
		for (int l944 = 0; (l944 < 2); l944 = (l944 + 1)) {
			fRec1347[l944] = 0.0;
			
		}
		for (int l945 = 0; (l945 < 2); l945 = (l945 + 1)) {
			fRec1346[l945] = 0.0;
			
		}
		for (int l946 = 0; (l946 < 2); l946 = (l946 + 1)) {
			fRec1344[l946] = 0.0;
			
		}
		for (int l947 = 0; (l947 < 2); l947 = (l947 + 1)) {
			fRec1370[l947] = 0.0;
			
		}
		for (int l948 = 0; (l948 < 2); l948 = (l948 + 1)) {
			fRec1368[l948] = 0.0;
			
		}
		for (int l949 = 0; (l949 < 2); l949 = (l949 + 1)) {
			fRec1367[l949] = 0.0;
			
		}
		for (int l950 = 0; (l950 < 2); l950 = (l950 + 1)) {
			fRec1365[l950] = 0.0;
			
		}
		for (int l951 = 0; (l951 < 2); l951 = (l951 + 1)) {
			fRec1364[l951] = 0.0;
			
		}
		for (int l952 = 0; (l952 < 2); l952 = (l952 + 1)) {
			fRec1362[l952] = 0.0;
			
		}
		for (int l953 = 0; (l953 < 2); l953 = (l953 + 1)) {
			fRec1361[l953] = 0.0;
			
		}
		for (int l954 = 0; (l954 < 2); l954 = (l954 + 1)) {
			fRec1359[l954] = 0.0;
			
		}
		for (int l955 = 0; (l955 < 2); l955 = (l955 + 1)) {
			fRec1379[l955] = 0.0;
			
		}
		for (int l956 = 0; (l956 < 2); l956 = (l956 + 1)) {
			fRec1377[l956] = 0.0;
			
		}
		for (int l957 = 0; (l957 < 2); l957 = (l957 + 1)) {
			fRec1376[l957] = 0.0;
			
		}
		for (int l958 = 0; (l958 < 2); l958 = (l958 + 1)) {
			fRec1374[l958] = 0.0;
			
		}
		for (int l959 = 0; (l959 < 2); l959 = (l959 + 1)) {
			fRec1373[l959] = 0.0;
			
		}
		for (int l960 = 0; (l960 < 2); l960 = (l960 + 1)) {
			fRec1371[l960] = 0.0;
			
		}
		for (int l961 = 0; (l961 < 2); l961 = (l961 + 1)) {
			fRec1382[l961] = 0.0;
			
		}
		for (int l962 = 0; (l962 < 2); l962 = (l962 + 1)) {
			fRec1380[l962] = 0.0;
			
		}
		for (int l963 = 0; (l963 < 2); l963 = (l963 + 1)) {
			fRec1388[l963] = 0.0;
			
		}
		for (int l964 = 0; (l964 < 2); l964 = (l964 + 1)) {
			fRec1386[l964] = 0.0;
			
		}
		for (int l965 = 0; (l965 < 2); l965 = (l965 + 1)) {
			fRec1385[l965] = 0.0;
			
		}
		for (int l966 = 0; (l966 < 2); l966 = (l966 + 1)) {
			fRec1383[l966] = 0.0;
			
		}
		for (int l967 = 0; (l967 < 512); l967 = (l967 + 1)) {
			fVec28[l967] = 0.0;
			
		}
		for (int l968 = 0; (l968 < 2); l968 = (l968 + 1)) {
			fRec1403[l968] = 0.0;
			
		}
		for (int l969 = 0; (l969 < 2); l969 = (l969 + 1)) {
			fRec1401[l969] = 0.0;
			
		}
		for (int l970 = 0; (l970 < 2); l970 = (l970 + 1)) {
			fRec1400[l970] = 0.0;
			
		}
		for (int l971 = 0; (l971 < 2); l971 = (l971 + 1)) {
			fRec1398[l971] = 0.0;
			
		}
		for (int l972 = 0; (l972 < 2); l972 = (l972 + 1)) {
			fRec1397[l972] = 0.0;
			
		}
		for (int l973 = 0; (l973 < 2); l973 = (l973 + 1)) {
			fRec1395[l973] = 0.0;
			
		}
		for (int l974 = 0; (l974 < 2); l974 = (l974 + 1)) {
			fRec1394[l974] = 0.0;
			
		}
		for (int l975 = 0; (l975 < 2); l975 = (l975 + 1)) {
			fRec1392[l975] = 0.0;
			
		}
		for (int l976 = 0; (l976 < 2); l976 = (l976 + 1)) {
			fRec1391[l976] = 0.0;
			
		}
		for (int l977 = 0; (l977 < 2); l977 = (l977 + 1)) {
			fRec1389[l977] = 0.0;
			
		}
		for (int l978 = 0; (l978 < 2); l978 = (l978 + 1)) {
			fRec1415[l978] = 0.0;
			
		}
		for (int l979 = 0; (l979 < 2); l979 = (l979 + 1)) {
			fRec1413[l979] = 0.0;
			
		}
		for (int l980 = 0; (l980 < 2); l980 = (l980 + 1)) {
			fRec1412[l980] = 0.0;
			
		}
		for (int l981 = 0; (l981 < 2); l981 = (l981 + 1)) {
			fRec1410[l981] = 0.0;
			
		}
		for (int l982 = 0; (l982 < 2); l982 = (l982 + 1)) {
			fRec1409[l982] = 0.0;
			
		}
		for (int l983 = 0; (l983 < 2); l983 = (l983 + 1)) {
			fRec1407[l983] = 0.0;
			
		}
		for (int l984 = 0; (l984 < 2); l984 = (l984 + 1)) {
			fRec1406[l984] = 0.0;
			
		}
		for (int l985 = 0; (l985 < 2); l985 = (l985 + 1)) {
			fRec1404[l985] = 0.0;
			
		}
		for (int l986 = 0; (l986 < 2); l986 = (l986 + 1)) {
			fRec1424[l986] = 0.0;
			
		}
		for (int l987 = 0; (l987 < 2); l987 = (l987 + 1)) {
			fRec1422[l987] = 0.0;
			
		}
		for (int l988 = 0; (l988 < 2); l988 = (l988 + 1)) {
			fRec1421[l988] = 0.0;
			
		}
		for (int l989 = 0; (l989 < 2); l989 = (l989 + 1)) {
			fRec1419[l989] = 0.0;
			
		}
		for (int l990 = 0; (l990 < 2); l990 = (l990 + 1)) {
			fRec1418[l990] = 0.0;
			
		}
		for (int l991 = 0; (l991 < 2); l991 = (l991 + 1)) {
			fRec1416[l991] = 0.0;
			
		}
		for (int l992 = 0; (l992 < 2); l992 = (l992 + 1)) {
			fRec1427[l992] = 0.0;
			
		}
		for (int l993 = 0; (l993 < 2); l993 = (l993 + 1)) {
			fRec1425[l993] = 0.0;
			
		}
		for (int l994 = 0; (l994 < 2); l994 = (l994 + 1)) {
			fRec1433[l994] = 0.0;
			
		}
		for (int l995 = 0; (l995 < 2); l995 = (l995 + 1)) {
			fRec1431[l995] = 0.0;
			
		}
		for (int l996 = 0; (l996 < 2); l996 = (l996 + 1)) {
			fRec1430[l996] = 0.0;
			
		}
		for (int l997 = 0; (l997 < 2); l997 = (l997 + 1)) {
			fRec1428[l997] = 0.0;
			
		}
		for (int l998 = 0; (l998 < 512); l998 = (l998 + 1)) {
			fVec29[l998] = 0.0;
			
		}
		for (int l999 = 0; (l999 < 2); l999 = (l999 + 1)) {
			fRec1448[l999] = 0.0;
			
		}
		for (int l1000 = 0; (l1000 < 2); l1000 = (l1000 + 1)) {
			fRec1446[l1000] = 0.0;
			
		}
		for (int l1001 = 0; (l1001 < 2); l1001 = (l1001 + 1)) {
			fRec1445[l1001] = 0.0;
			
		}
		for (int l1002 = 0; (l1002 < 2); l1002 = (l1002 + 1)) {
			fRec1443[l1002] = 0.0;
			
		}
		for (int l1003 = 0; (l1003 < 2); l1003 = (l1003 + 1)) {
			fRec1442[l1003] = 0.0;
			
		}
		for (int l1004 = 0; (l1004 < 2); l1004 = (l1004 + 1)) {
			fRec1440[l1004] = 0.0;
			
		}
		for (int l1005 = 0; (l1005 < 2); l1005 = (l1005 + 1)) {
			fRec1439[l1005] = 0.0;
			
		}
		for (int l1006 = 0; (l1006 < 2); l1006 = (l1006 + 1)) {
			fRec1437[l1006] = 0.0;
			
		}
		for (int l1007 = 0; (l1007 < 2); l1007 = (l1007 + 1)) {
			fRec1436[l1007] = 0.0;
			
		}
		for (int l1008 = 0; (l1008 < 2); l1008 = (l1008 + 1)) {
			fRec1434[l1008] = 0.0;
			
		}
		for (int l1009 = 0; (l1009 < 2); l1009 = (l1009 + 1)) {
			fRec1460[l1009] = 0.0;
			
		}
		for (int l1010 = 0; (l1010 < 2); l1010 = (l1010 + 1)) {
			fRec1458[l1010] = 0.0;
			
		}
		for (int l1011 = 0; (l1011 < 2); l1011 = (l1011 + 1)) {
			fRec1457[l1011] = 0.0;
			
		}
		for (int l1012 = 0; (l1012 < 2); l1012 = (l1012 + 1)) {
			fRec1455[l1012] = 0.0;
			
		}
		for (int l1013 = 0; (l1013 < 2); l1013 = (l1013 + 1)) {
			fRec1454[l1013] = 0.0;
			
		}
		for (int l1014 = 0; (l1014 < 2); l1014 = (l1014 + 1)) {
			fRec1452[l1014] = 0.0;
			
		}
		for (int l1015 = 0; (l1015 < 2); l1015 = (l1015 + 1)) {
			fRec1451[l1015] = 0.0;
			
		}
		for (int l1016 = 0; (l1016 < 2); l1016 = (l1016 + 1)) {
			fRec1449[l1016] = 0.0;
			
		}
		for (int l1017 = 0; (l1017 < 2); l1017 = (l1017 + 1)) {
			fRec1469[l1017] = 0.0;
			
		}
		for (int l1018 = 0; (l1018 < 2); l1018 = (l1018 + 1)) {
			fRec1467[l1018] = 0.0;
			
		}
		for (int l1019 = 0; (l1019 < 2); l1019 = (l1019 + 1)) {
			fRec1466[l1019] = 0.0;
			
		}
		for (int l1020 = 0; (l1020 < 2); l1020 = (l1020 + 1)) {
			fRec1464[l1020] = 0.0;
			
		}
		for (int l1021 = 0; (l1021 < 2); l1021 = (l1021 + 1)) {
			fRec1463[l1021] = 0.0;
			
		}
		for (int l1022 = 0; (l1022 < 2); l1022 = (l1022 + 1)) {
			fRec1461[l1022] = 0.0;
			
		}
		for (int l1023 = 0; (l1023 < 2); l1023 = (l1023 + 1)) {
			fRec1472[l1023] = 0.0;
			
		}
		for (int l1024 = 0; (l1024 < 2); l1024 = (l1024 + 1)) {
			fRec1470[l1024] = 0.0;
			
		}
		for (int l1025 = 0; (l1025 < 2); l1025 = (l1025 + 1)) {
			fRec1478[l1025] = 0.0;
			
		}
		for (int l1026 = 0; (l1026 < 2); l1026 = (l1026 + 1)) {
			fRec1476[l1026] = 0.0;
			
		}
		for (int l1027 = 0; (l1027 < 2); l1027 = (l1027 + 1)) {
			fRec1475[l1027] = 0.0;
			
		}
		for (int l1028 = 0; (l1028 < 2); l1028 = (l1028 + 1)) {
			fRec1473[l1028] = 0.0;
			
		}
		for (int l1029 = 0; (l1029 < 512); l1029 = (l1029 + 1)) {
			fVec30[l1029] = 0.0;
			
		}
		for (int l1030 = 0; (l1030 < 2); l1030 = (l1030 + 1)) {
			fRec1493[l1030] = 0.0;
			
		}
		for (int l1031 = 0; (l1031 < 2); l1031 = (l1031 + 1)) {
			fRec1491[l1031] = 0.0;
			
		}
		for (int l1032 = 0; (l1032 < 2); l1032 = (l1032 + 1)) {
			fRec1490[l1032] = 0.0;
			
		}
		for (int l1033 = 0; (l1033 < 2); l1033 = (l1033 + 1)) {
			fRec1488[l1033] = 0.0;
			
		}
		for (int l1034 = 0; (l1034 < 2); l1034 = (l1034 + 1)) {
			fRec1487[l1034] = 0.0;
			
		}
		for (int l1035 = 0; (l1035 < 2); l1035 = (l1035 + 1)) {
			fRec1485[l1035] = 0.0;
			
		}
		for (int l1036 = 0; (l1036 < 2); l1036 = (l1036 + 1)) {
			fRec1484[l1036] = 0.0;
			
		}
		for (int l1037 = 0; (l1037 < 2); l1037 = (l1037 + 1)) {
			fRec1482[l1037] = 0.0;
			
		}
		for (int l1038 = 0; (l1038 < 2); l1038 = (l1038 + 1)) {
			fRec1481[l1038] = 0.0;
			
		}
		for (int l1039 = 0; (l1039 < 2); l1039 = (l1039 + 1)) {
			fRec1479[l1039] = 0.0;
			
		}
		for (int l1040 = 0; (l1040 < 2); l1040 = (l1040 + 1)) {
			fRec1505[l1040] = 0.0;
			
		}
		for (int l1041 = 0; (l1041 < 2); l1041 = (l1041 + 1)) {
			fRec1503[l1041] = 0.0;
			
		}
		for (int l1042 = 0; (l1042 < 2); l1042 = (l1042 + 1)) {
			fRec1502[l1042] = 0.0;
			
		}
		for (int l1043 = 0; (l1043 < 2); l1043 = (l1043 + 1)) {
			fRec1500[l1043] = 0.0;
			
		}
		for (int l1044 = 0; (l1044 < 2); l1044 = (l1044 + 1)) {
			fRec1499[l1044] = 0.0;
			
		}
		for (int l1045 = 0; (l1045 < 2); l1045 = (l1045 + 1)) {
			fRec1497[l1045] = 0.0;
			
		}
		for (int l1046 = 0; (l1046 < 2); l1046 = (l1046 + 1)) {
			fRec1496[l1046] = 0.0;
			
		}
		for (int l1047 = 0; (l1047 < 2); l1047 = (l1047 + 1)) {
			fRec1494[l1047] = 0.0;
			
		}
		for (int l1048 = 0; (l1048 < 2); l1048 = (l1048 + 1)) {
			fRec1514[l1048] = 0.0;
			
		}
		for (int l1049 = 0; (l1049 < 2); l1049 = (l1049 + 1)) {
			fRec1512[l1049] = 0.0;
			
		}
		for (int l1050 = 0; (l1050 < 2); l1050 = (l1050 + 1)) {
			fRec1511[l1050] = 0.0;
			
		}
		for (int l1051 = 0; (l1051 < 2); l1051 = (l1051 + 1)) {
			fRec1509[l1051] = 0.0;
			
		}
		for (int l1052 = 0; (l1052 < 2); l1052 = (l1052 + 1)) {
			fRec1508[l1052] = 0.0;
			
		}
		for (int l1053 = 0; (l1053 < 2); l1053 = (l1053 + 1)) {
			fRec1506[l1053] = 0.0;
			
		}
		for (int l1054 = 0; (l1054 < 2); l1054 = (l1054 + 1)) {
			fRec1517[l1054] = 0.0;
			
		}
		for (int l1055 = 0; (l1055 < 2); l1055 = (l1055 + 1)) {
			fRec1515[l1055] = 0.0;
			
		}
		for (int l1056 = 0; (l1056 < 2); l1056 = (l1056 + 1)) {
			fRec1523[l1056] = 0.0;
			
		}
		for (int l1057 = 0; (l1057 < 2); l1057 = (l1057 + 1)) {
			fRec1521[l1057] = 0.0;
			
		}
		for (int l1058 = 0; (l1058 < 2); l1058 = (l1058 + 1)) {
			fRec1520[l1058] = 0.0;
			
		}
		for (int l1059 = 0; (l1059 < 2); l1059 = (l1059 + 1)) {
			fRec1518[l1059] = 0.0;
			
		}
		for (int l1060 = 0; (l1060 < 512); l1060 = (l1060 + 1)) {
			fVec31[l1060] = 0.0;
			
		}
		for (int l1061 = 0; (l1061 < 2); l1061 = (l1061 + 1)) {
			fRec1538[l1061] = 0.0;
			
		}
		for (int l1062 = 0; (l1062 < 2); l1062 = (l1062 + 1)) {
			fRec1536[l1062] = 0.0;
			
		}
		for (int l1063 = 0; (l1063 < 2); l1063 = (l1063 + 1)) {
			fRec1535[l1063] = 0.0;
			
		}
		for (int l1064 = 0; (l1064 < 2); l1064 = (l1064 + 1)) {
			fRec1533[l1064] = 0.0;
			
		}
		for (int l1065 = 0; (l1065 < 2); l1065 = (l1065 + 1)) {
			fRec1532[l1065] = 0.0;
			
		}
		for (int l1066 = 0; (l1066 < 2); l1066 = (l1066 + 1)) {
			fRec1530[l1066] = 0.0;
			
		}
		for (int l1067 = 0; (l1067 < 2); l1067 = (l1067 + 1)) {
			fRec1529[l1067] = 0.0;
			
		}
		for (int l1068 = 0; (l1068 < 2); l1068 = (l1068 + 1)) {
			fRec1527[l1068] = 0.0;
			
		}
		for (int l1069 = 0; (l1069 < 2); l1069 = (l1069 + 1)) {
			fRec1526[l1069] = 0.0;
			
		}
		for (int l1070 = 0; (l1070 < 2); l1070 = (l1070 + 1)) {
			fRec1524[l1070] = 0.0;
			
		}
		for (int l1071 = 0; (l1071 < 2); l1071 = (l1071 + 1)) {
			fRec1550[l1071] = 0.0;
			
		}
		for (int l1072 = 0; (l1072 < 2); l1072 = (l1072 + 1)) {
			fRec1548[l1072] = 0.0;
			
		}
		for (int l1073 = 0; (l1073 < 2); l1073 = (l1073 + 1)) {
			fRec1547[l1073] = 0.0;
			
		}
		for (int l1074 = 0; (l1074 < 2); l1074 = (l1074 + 1)) {
			fRec1545[l1074] = 0.0;
			
		}
		for (int l1075 = 0; (l1075 < 2); l1075 = (l1075 + 1)) {
			fRec1544[l1075] = 0.0;
			
		}
		for (int l1076 = 0; (l1076 < 2); l1076 = (l1076 + 1)) {
			fRec1542[l1076] = 0.0;
			
		}
		for (int l1077 = 0; (l1077 < 2); l1077 = (l1077 + 1)) {
			fRec1541[l1077] = 0.0;
			
		}
		for (int l1078 = 0; (l1078 < 2); l1078 = (l1078 + 1)) {
			fRec1539[l1078] = 0.0;
			
		}
		for (int l1079 = 0; (l1079 < 2); l1079 = (l1079 + 1)) {
			fRec1559[l1079] = 0.0;
			
		}
		for (int l1080 = 0; (l1080 < 2); l1080 = (l1080 + 1)) {
			fRec1557[l1080] = 0.0;
			
		}
		for (int l1081 = 0; (l1081 < 2); l1081 = (l1081 + 1)) {
			fRec1556[l1081] = 0.0;
			
		}
		for (int l1082 = 0; (l1082 < 2); l1082 = (l1082 + 1)) {
			fRec1554[l1082] = 0.0;
			
		}
		for (int l1083 = 0; (l1083 < 2); l1083 = (l1083 + 1)) {
			fRec1553[l1083] = 0.0;
			
		}
		for (int l1084 = 0; (l1084 < 2); l1084 = (l1084 + 1)) {
			fRec1551[l1084] = 0.0;
			
		}
		for (int l1085 = 0; (l1085 < 2); l1085 = (l1085 + 1)) {
			fRec1562[l1085] = 0.0;
			
		}
		for (int l1086 = 0; (l1086 < 2); l1086 = (l1086 + 1)) {
			fRec1560[l1086] = 0.0;
			
		}
		for (int l1087 = 0; (l1087 < 2); l1087 = (l1087 + 1)) {
			fRec1568[l1087] = 0.0;
			
		}
		for (int l1088 = 0; (l1088 < 2); l1088 = (l1088 + 1)) {
			fRec1566[l1088] = 0.0;
			
		}
		for (int l1089 = 0; (l1089 < 2); l1089 = (l1089 + 1)) {
			fRec1565[l1089] = 0.0;
			
		}
		for (int l1090 = 0; (l1090 < 2); l1090 = (l1090 + 1)) {
			fRec1563[l1090] = 0.0;
			
		}
		for (int l1091 = 0; (l1091 < 512); l1091 = (l1091 + 1)) {
			fVec32[l1091] = 0.0;
			
		}
		for (int l1092 = 0; (l1092 < 2); l1092 = (l1092 + 1)) {
			fRec1583[l1092] = 0.0;
			
		}
		for (int l1093 = 0; (l1093 < 2); l1093 = (l1093 + 1)) {
			fRec1581[l1093] = 0.0;
			
		}
		for (int l1094 = 0; (l1094 < 2); l1094 = (l1094 + 1)) {
			fRec1580[l1094] = 0.0;
			
		}
		for (int l1095 = 0; (l1095 < 2); l1095 = (l1095 + 1)) {
			fRec1578[l1095] = 0.0;
			
		}
		for (int l1096 = 0; (l1096 < 2); l1096 = (l1096 + 1)) {
			fRec1577[l1096] = 0.0;
			
		}
		for (int l1097 = 0; (l1097 < 2); l1097 = (l1097 + 1)) {
			fRec1575[l1097] = 0.0;
			
		}
		for (int l1098 = 0; (l1098 < 2); l1098 = (l1098 + 1)) {
			fRec1574[l1098] = 0.0;
			
		}
		for (int l1099 = 0; (l1099 < 2); l1099 = (l1099 + 1)) {
			fRec1572[l1099] = 0.0;
			
		}
		for (int l1100 = 0; (l1100 < 2); l1100 = (l1100 + 1)) {
			fRec1571[l1100] = 0.0;
			
		}
		for (int l1101 = 0; (l1101 < 2); l1101 = (l1101 + 1)) {
			fRec1569[l1101] = 0.0;
			
		}
		for (int l1102 = 0; (l1102 < 2); l1102 = (l1102 + 1)) {
			fRec1595[l1102] = 0.0;
			
		}
		for (int l1103 = 0; (l1103 < 2); l1103 = (l1103 + 1)) {
			fRec1593[l1103] = 0.0;
			
		}
		for (int l1104 = 0; (l1104 < 2); l1104 = (l1104 + 1)) {
			fRec1592[l1104] = 0.0;
			
		}
		for (int l1105 = 0; (l1105 < 2); l1105 = (l1105 + 1)) {
			fRec1590[l1105] = 0.0;
			
		}
		for (int l1106 = 0; (l1106 < 2); l1106 = (l1106 + 1)) {
			fRec1589[l1106] = 0.0;
			
		}
		for (int l1107 = 0; (l1107 < 2); l1107 = (l1107 + 1)) {
			fRec1587[l1107] = 0.0;
			
		}
		for (int l1108 = 0; (l1108 < 2); l1108 = (l1108 + 1)) {
			fRec1586[l1108] = 0.0;
			
		}
		for (int l1109 = 0; (l1109 < 2); l1109 = (l1109 + 1)) {
			fRec1584[l1109] = 0.0;
			
		}
		for (int l1110 = 0; (l1110 < 2); l1110 = (l1110 + 1)) {
			fRec1604[l1110] = 0.0;
			
		}
		for (int l1111 = 0; (l1111 < 2); l1111 = (l1111 + 1)) {
			fRec1602[l1111] = 0.0;
			
		}
		for (int l1112 = 0; (l1112 < 2); l1112 = (l1112 + 1)) {
			fRec1601[l1112] = 0.0;
			
		}
		for (int l1113 = 0; (l1113 < 2); l1113 = (l1113 + 1)) {
			fRec1599[l1113] = 0.0;
			
		}
		for (int l1114 = 0; (l1114 < 2); l1114 = (l1114 + 1)) {
			fRec1598[l1114] = 0.0;
			
		}
		for (int l1115 = 0; (l1115 < 2); l1115 = (l1115 + 1)) {
			fRec1596[l1115] = 0.0;
			
		}
		for (int l1116 = 0; (l1116 < 2); l1116 = (l1116 + 1)) {
			fRec1607[l1116] = 0.0;
			
		}
		for (int l1117 = 0; (l1117 < 2); l1117 = (l1117 + 1)) {
			fRec1605[l1117] = 0.0;
			
		}
		for (int l1118 = 0; (l1118 < 2); l1118 = (l1118 + 1)) {
			fRec1613[l1118] = 0.0;
			
		}
		for (int l1119 = 0; (l1119 < 2); l1119 = (l1119 + 1)) {
			fRec1611[l1119] = 0.0;
			
		}
		for (int l1120 = 0; (l1120 < 2); l1120 = (l1120 + 1)) {
			fRec1610[l1120] = 0.0;
			
		}
		for (int l1121 = 0; (l1121 < 2); l1121 = (l1121 + 1)) {
			fRec1608[l1121] = 0.0;
			
		}
		for (int l1122 = 0; (l1122 < 512); l1122 = (l1122 + 1)) {
			fVec33[l1122] = 0.0;
			
		}
		for (int l1123 = 0; (l1123 < 2); l1123 = (l1123 + 1)) {
			fRec1628[l1123] = 0.0;
			
		}
		for (int l1124 = 0; (l1124 < 2); l1124 = (l1124 + 1)) {
			fRec1626[l1124] = 0.0;
			
		}
		for (int l1125 = 0; (l1125 < 2); l1125 = (l1125 + 1)) {
			fRec1625[l1125] = 0.0;
			
		}
		for (int l1126 = 0; (l1126 < 2); l1126 = (l1126 + 1)) {
			fRec1623[l1126] = 0.0;
			
		}
		for (int l1127 = 0; (l1127 < 2); l1127 = (l1127 + 1)) {
			fRec1622[l1127] = 0.0;
			
		}
		for (int l1128 = 0; (l1128 < 2); l1128 = (l1128 + 1)) {
			fRec1620[l1128] = 0.0;
			
		}
		for (int l1129 = 0; (l1129 < 2); l1129 = (l1129 + 1)) {
			fRec1619[l1129] = 0.0;
			
		}
		for (int l1130 = 0; (l1130 < 2); l1130 = (l1130 + 1)) {
			fRec1617[l1130] = 0.0;
			
		}
		for (int l1131 = 0; (l1131 < 2); l1131 = (l1131 + 1)) {
			fRec1616[l1131] = 0.0;
			
		}
		for (int l1132 = 0; (l1132 < 2); l1132 = (l1132 + 1)) {
			fRec1614[l1132] = 0.0;
			
		}
		for (int l1133 = 0; (l1133 < 2); l1133 = (l1133 + 1)) {
			fRec1640[l1133] = 0.0;
			
		}
		for (int l1134 = 0; (l1134 < 2); l1134 = (l1134 + 1)) {
			fRec1638[l1134] = 0.0;
			
		}
		for (int l1135 = 0; (l1135 < 2); l1135 = (l1135 + 1)) {
			fRec1637[l1135] = 0.0;
			
		}
		for (int l1136 = 0; (l1136 < 2); l1136 = (l1136 + 1)) {
			fRec1635[l1136] = 0.0;
			
		}
		for (int l1137 = 0; (l1137 < 2); l1137 = (l1137 + 1)) {
			fRec1634[l1137] = 0.0;
			
		}
		for (int l1138 = 0; (l1138 < 2); l1138 = (l1138 + 1)) {
			fRec1632[l1138] = 0.0;
			
		}
		for (int l1139 = 0; (l1139 < 2); l1139 = (l1139 + 1)) {
			fRec1631[l1139] = 0.0;
			
		}
		for (int l1140 = 0; (l1140 < 2); l1140 = (l1140 + 1)) {
			fRec1629[l1140] = 0.0;
			
		}
		for (int l1141 = 0; (l1141 < 2); l1141 = (l1141 + 1)) {
			fRec1649[l1141] = 0.0;
			
		}
		for (int l1142 = 0; (l1142 < 2); l1142 = (l1142 + 1)) {
			fRec1647[l1142] = 0.0;
			
		}
		for (int l1143 = 0; (l1143 < 2); l1143 = (l1143 + 1)) {
			fRec1646[l1143] = 0.0;
			
		}
		for (int l1144 = 0; (l1144 < 2); l1144 = (l1144 + 1)) {
			fRec1644[l1144] = 0.0;
			
		}
		for (int l1145 = 0; (l1145 < 2); l1145 = (l1145 + 1)) {
			fRec1643[l1145] = 0.0;
			
		}
		for (int l1146 = 0; (l1146 < 2); l1146 = (l1146 + 1)) {
			fRec1641[l1146] = 0.0;
			
		}
		for (int l1147 = 0; (l1147 < 2); l1147 = (l1147 + 1)) {
			fRec1652[l1147] = 0.0;
			
		}
		for (int l1148 = 0; (l1148 < 2); l1148 = (l1148 + 1)) {
			fRec1650[l1148] = 0.0;
			
		}
		for (int l1149 = 0; (l1149 < 2); l1149 = (l1149 + 1)) {
			fRec1658[l1149] = 0.0;
			
		}
		for (int l1150 = 0; (l1150 < 2); l1150 = (l1150 + 1)) {
			fRec1656[l1150] = 0.0;
			
		}
		for (int l1151 = 0; (l1151 < 2); l1151 = (l1151 + 1)) {
			fRec1655[l1151] = 0.0;
			
		}
		for (int l1152 = 0; (l1152 < 2); l1152 = (l1152 + 1)) {
			fRec1653[l1152] = 0.0;
			
		}
		for (int l1153 = 0; (l1153 < 512); l1153 = (l1153 + 1)) {
			fVec34[l1153] = 0.0;
			
		}
		for (int l1154 = 0; (l1154 < 2); l1154 = (l1154 + 1)) {
			fRec1673[l1154] = 0.0;
			
		}
		for (int l1155 = 0; (l1155 < 2); l1155 = (l1155 + 1)) {
			fRec1671[l1155] = 0.0;
			
		}
		for (int l1156 = 0; (l1156 < 2); l1156 = (l1156 + 1)) {
			fRec1670[l1156] = 0.0;
			
		}
		for (int l1157 = 0; (l1157 < 2); l1157 = (l1157 + 1)) {
			fRec1668[l1157] = 0.0;
			
		}
		for (int l1158 = 0; (l1158 < 2); l1158 = (l1158 + 1)) {
			fRec1667[l1158] = 0.0;
			
		}
		for (int l1159 = 0; (l1159 < 2); l1159 = (l1159 + 1)) {
			fRec1665[l1159] = 0.0;
			
		}
		for (int l1160 = 0; (l1160 < 2); l1160 = (l1160 + 1)) {
			fRec1664[l1160] = 0.0;
			
		}
		for (int l1161 = 0; (l1161 < 2); l1161 = (l1161 + 1)) {
			fRec1662[l1161] = 0.0;
			
		}
		for (int l1162 = 0; (l1162 < 2); l1162 = (l1162 + 1)) {
			fRec1661[l1162] = 0.0;
			
		}
		for (int l1163 = 0; (l1163 < 2); l1163 = (l1163 + 1)) {
			fRec1659[l1163] = 0.0;
			
		}
		for (int l1164 = 0; (l1164 < 2); l1164 = (l1164 + 1)) {
			fRec1685[l1164] = 0.0;
			
		}
		for (int l1165 = 0; (l1165 < 2); l1165 = (l1165 + 1)) {
			fRec1683[l1165] = 0.0;
			
		}
		for (int l1166 = 0; (l1166 < 2); l1166 = (l1166 + 1)) {
			fRec1682[l1166] = 0.0;
			
		}
		for (int l1167 = 0; (l1167 < 2); l1167 = (l1167 + 1)) {
			fRec1680[l1167] = 0.0;
			
		}
		for (int l1168 = 0; (l1168 < 2); l1168 = (l1168 + 1)) {
			fRec1679[l1168] = 0.0;
			
		}
		for (int l1169 = 0; (l1169 < 2); l1169 = (l1169 + 1)) {
			fRec1677[l1169] = 0.0;
			
		}
		for (int l1170 = 0; (l1170 < 2); l1170 = (l1170 + 1)) {
			fRec1676[l1170] = 0.0;
			
		}
		for (int l1171 = 0; (l1171 < 2); l1171 = (l1171 + 1)) {
			fRec1674[l1171] = 0.0;
			
		}
		for (int l1172 = 0; (l1172 < 2); l1172 = (l1172 + 1)) {
			fRec1694[l1172] = 0.0;
			
		}
		for (int l1173 = 0; (l1173 < 2); l1173 = (l1173 + 1)) {
			fRec1692[l1173] = 0.0;
			
		}
		for (int l1174 = 0; (l1174 < 2); l1174 = (l1174 + 1)) {
			fRec1691[l1174] = 0.0;
			
		}
		for (int l1175 = 0; (l1175 < 2); l1175 = (l1175 + 1)) {
			fRec1689[l1175] = 0.0;
			
		}
		for (int l1176 = 0; (l1176 < 2); l1176 = (l1176 + 1)) {
			fRec1688[l1176] = 0.0;
			
		}
		for (int l1177 = 0; (l1177 < 2); l1177 = (l1177 + 1)) {
			fRec1686[l1177] = 0.0;
			
		}
		for (int l1178 = 0; (l1178 < 2); l1178 = (l1178 + 1)) {
			fRec1697[l1178] = 0.0;
			
		}
		for (int l1179 = 0; (l1179 < 2); l1179 = (l1179 + 1)) {
			fRec1695[l1179] = 0.0;
			
		}
		for (int l1180 = 0; (l1180 < 2); l1180 = (l1180 + 1)) {
			fRec1703[l1180] = 0.0;
			
		}
		for (int l1181 = 0; (l1181 < 2); l1181 = (l1181 + 1)) {
			fRec1701[l1181] = 0.0;
			
		}
		for (int l1182 = 0; (l1182 < 2); l1182 = (l1182 + 1)) {
			fRec1700[l1182] = 0.0;
			
		}
		for (int l1183 = 0; (l1183 < 2); l1183 = (l1183 + 1)) {
			fRec1698[l1183] = 0.0;
			
		}
		for (int l1184 = 0; (l1184 < 512); l1184 = (l1184 + 1)) {
			fVec35[l1184] = 0.0;
			
		}
		for (int l1185 = 0; (l1185 < 2); l1185 = (l1185 + 1)) {
			fRec1718[l1185] = 0.0;
			
		}
		for (int l1186 = 0; (l1186 < 2); l1186 = (l1186 + 1)) {
			fRec1716[l1186] = 0.0;
			
		}
		for (int l1187 = 0; (l1187 < 2); l1187 = (l1187 + 1)) {
			fRec1715[l1187] = 0.0;
			
		}
		for (int l1188 = 0; (l1188 < 2); l1188 = (l1188 + 1)) {
			fRec1713[l1188] = 0.0;
			
		}
		for (int l1189 = 0; (l1189 < 2); l1189 = (l1189 + 1)) {
			fRec1712[l1189] = 0.0;
			
		}
		for (int l1190 = 0; (l1190 < 2); l1190 = (l1190 + 1)) {
			fRec1710[l1190] = 0.0;
			
		}
		for (int l1191 = 0; (l1191 < 2); l1191 = (l1191 + 1)) {
			fRec1709[l1191] = 0.0;
			
		}
		for (int l1192 = 0; (l1192 < 2); l1192 = (l1192 + 1)) {
			fRec1707[l1192] = 0.0;
			
		}
		for (int l1193 = 0; (l1193 < 2); l1193 = (l1193 + 1)) {
			fRec1706[l1193] = 0.0;
			
		}
		for (int l1194 = 0; (l1194 < 2); l1194 = (l1194 + 1)) {
			fRec1704[l1194] = 0.0;
			
		}
		for (int l1195 = 0; (l1195 < 2); l1195 = (l1195 + 1)) {
			fRec1730[l1195] = 0.0;
			
		}
		for (int l1196 = 0; (l1196 < 2); l1196 = (l1196 + 1)) {
			fRec1728[l1196] = 0.0;
			
		}
		for (int l1197 = 0; (l1197 < 2); l1197 = (l1197 + 1)) {
			fRec1727[l1197] = 0.0;
			
		}
		for (int l1198 = 0; (l1198 < 2); l1198 = (l1198 + 1)) {
			fRec1725[l1198] = 0.0;
			
		}
		for (int l1199 = 0; (l1199 < 2); l1199 = (l1199 + 1)) {
			fRec1724[l1199] = 0.0;
			
		}
		for (int l1200 = 0; (l1200 < 2); l1200 = (l1200 + 1)) {
			fRec1722[l1200] = 0.0;
			
		}
		for (int l1201 = 0; (l1201 < 2); l1201 = (l1201 + 1)) {
			fRec1721[l1201] = 0.0;
			
		}
		for (int l1202 = 0; (l1202 < 2); l1202 = (l1202 + 1)) {
			fRec1719[l1202] = 0.0;
			
		}
		for (int l1203 = 0; (l1203 < 2); l1203 = (l1203 + 1)) {
			fRec1739[l1203] = 0.0;
			
		}
		for (int l1204 = 0; (l1204 < 2); l1204 = (l1204 + 1)) {
			fRec1737[l1204] = 0.0;
			
		}
		for (int l1205 = 0; (l1205 < 2); l1205 = (l1205 + 1)) {
			fRec1736[l1205] = 0.0;
			
		}
		for (int l1206 = 0; (l1206 < 2); l1206 = (l1206 + 1)) {
			fRec1734[l1206] = 0.0;
			
		}
		for (int l1207 = 0; (l1207 < 2); l1207 = (l1207 + 1)) {
			fRec1733[l1207] = 0.0;
			
		}
		for (int l1208 = 0; (l1208 < 2); l1208 = (l1208 + 1)) {
			fRec1731[l1208] = 0.0;
			
		}
		for (int l1209 = 0; (l1209 < 2); l1209 = (l1209 + 1)) {
			fRec1742[l1209] = 0.0;
			
		}
		for (int l1210 = 0; (l1210 < 2); l1210 = (l1210 + 1)) {
			fRec1740[l1210] = 0.0;
			
		}
		for (int l1211 = 0; (l1211 < 2); l1211 = (l1211 + 1)) {
			fRec1748[l1211] = 0.0;
			
		}
		for (int l1212 = 0; (l1212 < 2); l1212 = (l1212 + 1)) {
			fRec1746[l1212] = 0.0;
			
		}
		for (int l1213 = 0; (l1213 < 2); l1213 = (l1213 + 1)) {
			fRec1745[l1213] = 0.0;
			
		}
		for (int l1214 = 0; (l1214 < 2); l1214 = (l1214 + 1)) {
			fRec1743[l1214] = 0.0;
			
		}
		for (int l1215 = 0; (l1215 < 512); l1215 = (l1215 + 1)) {
			fVec36[l1215] = 0.0;
			
		}
		for (int l1216 = 0; (l1216 < 2); l1216 = (l1216 + 1)) {
			fRec1763[l1216] = 0.0;
			
		}
		for (int l1217 = 0; (l1217 < 2); l1217 = (l1217 + 1)) {
			fRec1761[l1217] = 0.0;
			
		}
		for (int l1218 = 0; (l1218 < 2); l1218 = (l1218 + 1)) {
			fRec1760[l1218] = 0.0;
			
		}
		for (int l1219 = 0; (l1219 < 2); l1219 = (l1219 + 1)) {
			fRec1758[l1219] = 0.0;
			
		}
		for (int l1220 = 0; (l1220 < 2); l1220 = (l1220 + 1)) {
			fRec1757[l1220] = 0.0;
			
		}
		for (int l1221 = 0; (l1221 < 2); l1221 = (l1221 + 1)) {
			fRec1755[l1221] = 0.0;
			
		}
		for (int l1222 = 0; (l1222 < 2); l1222 = (l1222 + 1)) {
			fRec1754[l1222] = 0.0;
			
		}
		for (int l1223 = 0; (l1223 < 2); l1223 = (l1223 + 1)) {
			fRec1752[l1223] = 0.0;
			
		}
		for (int l1224 = 0; (l1224 < 2); l1224 = (l1224 + 1)) {
			fRec1751[l1224] = 0.0;
			
		}
		for (int l1225 = 0; (l1225 < 2); l1225 = (l1225 + 1)) {
			fRec1749[l1225] = 0.0;
			
		}
		for (int l1226 = 0; (l1226 < 2); l1226 = (l1226 + 1)) {
			fRec1775[l1226] = 0.0;
			
		}
		for (int l1227 = 0; (l1227 < 2); l1227 = (l1227 + 1)) {
			fRec1773[l1227] = 0.0;
			
		}
		for (int l1228 = 0; (l1228 < 2); l1228 = (l1228 + 1)) {
			fRec1772[l1228] = 0.0;
			
		}
		for (int l1229 = 0; (l1229 < 2); l1229 = (l1229 + 1)) {
			fRec1770[l1229] = 0.0;
			
		}
		for (int l1230 = 0; (l1230 < 2); l1230 = (l1230 + 1)) {
			fRec1769[l1230] = 0.0;
			
		}
		for (int l1231 = 0; (l1231 < 2); l1231 = (l1231 + 1)) {
			fRec1767[l1231] = 0.0;
			
		}
		for (int l1232 = 0; (l1232 < 2); l1232 = (l1232 + 1)) {
			fRec1766[l1232] = 0.0;
			
		}
		for (int l1233 = 0; (l1233 < 2); l1233 = (l1233 + 1)) {
			fRec1764[l1233] = 0.0;
			
		}
		for (int l1234 = 0; (l1234 < 2); l1234 = (l1234 + 1)) {
			fRec1784[l1234] = 0.0;
			
		}
		for (int l1235 = 0; (l1235 < 2); l1235 = (l1235 + 1)) {
			fRec1782[l1235] = 0.0;
			
		}
		for (int l1236 = 0; (l1236 < 2); l1236 = (l1236 + 1)) {
			fRec1781[l1236] = 0.0;
			
		}
		for (int l1237 = 0; (l1237 < 2); l1237 = (l1237 + 1)) {
			fRec1779[l1237] = 0.0;
			
		}
		for (int l1238 = 0; (l1238 < 2); l1238 = (l1238 + 1)) {
			fRec1778[l1238] = 0.0;
			
		}
		for (int l1239 = 0; (l1239 < 2); l1239 = (l1239 + 1)) {
			fRec1776[l1239] = 0.0;
			
		}
		for (int l1240 = 0; (l1240 < 2); l1240 = (l1240 + 1)) {
			fRec1787[l1240] = 0.0;
			
		}
		for (int l1241 = 0; (l1241 < 2); l1241 = (l1241 + 1)) {
			fRec1785[l1241] = 0.0;
			
		}
		for (int l1242 = 0; (l1242 < 2); l1242 = (l1242 + 1)) {
			fRec1793[l1242] = 0.0;
			
		}
		for (int l1243 = 0; (l1243 < 2); l1243 = (l1243 + 1)) {
			fRec1791[l1243] = 0.0;
			
		}
		for (int l1244 = 0; (l1244 < 2); l1244 = (l1244 + 1)) {
			fRec1790[l1244] = 0.0;
			
		}
		for (int l1245 = 0; (l1245 < 2); l1245 = (l1245 + 1)) {
			fRec1788[l1245] = 0.0;
			
		}
		for (int l1246 = 0; (l1246 < 512); l1246 = (l1246 + 1)) {
			fVec37[l1246] = 0.0;
			
		}
		for (int l1247 = 0; (l1247 < 2); l1247 = (l1247 + 1)) {
			fRec1808[l1247] = 0.0;
			
		}
		for (int l1248 = 0; (l1248 < 2); l1248 = (l1248 + 1)) {
			fRec1806[l1248] = 0.0;
			
		}
		for (int l1249 = 0; (l1249 < 2); l1249 = (l1249 + 1)) {
			fRec1805[l1249] = 0.0;
			
		}
		for (int l1250 = 0; (l1250 < 2); l1250 = (l1250 + 1)) {
			fRec1803[l1250] = 0.0;
			
		}
		for (int l1251 = 0; (l1251 < 2); l1251 = (l1251 + 1)) {
			fRec1802[l1251] = 0.0;
			
		}
		for (int l1252 = 0; (l1252 < 2); l1252 = (l1252 + 1)) {
			fRec1800[l1252] = 0.0;
			
		}
		for (int l1253 = 0; (l1253 < 2); l1253 = (l1253 + 1)) {
			fRec1799[l1253] = 0.0;
			
		}
		for (int l1254 = 0; (l1254 < 2); l1254 = (l1254 + 1)) {
			fRec1797[l1254] = 0.0;
			
		}
		for (int l1255 = 0; (l1255 < 2); l1255 = (l1255 + 1)) {
			fRec1796[l1255] = 0.0;
			
		}
		for (int l1256 = 0; (l1256 < 2); l1256 = (l1256 + 1)) {
			fRec1794[l1256] = 0.0;
			
		}
		for (int l1257 = 0; (l1257 < 2); l1257 = (l1257 + 1)) {
			fRec1820[l1257] = 0.0;
			
		}
		for (int l1258 = 0; (l1258 < 2); l1258 = (l1258 + 1)) {
			fRec1818[l1258] = 0.0;
			
		}
		for (int l1259 = 0; (l1259 < 2); l1259 = (l1259 + 1)) {
			fRec1817[l1259] = 0.0;
			
		}
		for (int l1260 = 0; (l1260 < 2); l1260 = (l1260 + 1)) {
			fRec1815[l1260] = 0.0;
			
		}
		for (int l1261 = 0; (l1261 < 2); l1261 = (l1261 + 1)) {
			fRec1814[l1261] = 0.0;
			
		}
		for (int l1262 = 0; (l1262 < 2); l1262 = (l1262 + 1)) {
			fRec1812[l1262] = 0.0;
			
		}
		for (int l1263 = 0; (l1263 < 2); l1263 = (l1263 + 1)) {
			fRec1811[l1263] = 0.0;
			
		}
		for (int l1264 = 0; (l1264 < 2); l1264 = (l1264 + 1)) {
			fRec1809[l1264] = 0.0;
			
		}
		for (int l1265 = 0; (l1265 < 2); l1265 = (l1265 + 1)) {
			fRec1829[l1265] = 0.0;
			
		}
		for (int l1266 = 0; (l1266 < 2); l1266 = (l1266 + 1)) {
			fRec1827[l1266] = 0.0;
			
		}
		for (int l1267 = 0; (l1267 < 2); l1267 = (l1267 + 1)) {
			fRec1826[l1267] = 0.0;
			
		}
		for (int l1268 = 0; (l1268 < 2); l1268 = (l1268 + 1)) {
			fRec1824[l1268] = 0.0;
			
		}
		for (int l1269 = 0; (l1269 < 2); l1269 = (l1269 + 1)) {
			fRec1823[l1269] = 0.0;
			
		}
		for (int l1270 = 0; (l1270 < 2); l1270 = (l1270 + 1)) {
			fRec1821[l1270] = 0.0;
			
		}
		for (int l1271 = 0; (l1271 < 2); l1271 = (l1271 + 1)) {
			fRec1832[l1271] = 0.0;
			
		}
		for (int l1272 = 0; (l1272 < 2); l1272 = (l1272 + 1)) {
			fRec1830[l1272] = 0.0;
			
		}
		for (int l1273 = 0; (l1273 < 2); l1273 = (l1273 + 1)) {
			fRec1838[l1273] = 0.0;
			
		}
		for (int l1274 = 0; (l1274 < 2); l1274 = (l1274 + 1)) {
			fRec1836[l1274] = 0.0;
			
		}
		for (int l1275 = 0; (l1275 < 2); l1275 = (l1275 + 1)) {
			fRec1835[l1275] = 0.0;
			
		}
		for (int l1276 = 0; (l1276 < 2); l1276 = (l1276 + 1)) {
			fRec1833[l1276] = 0.0;
			
		}
		for (int l1277 = 0; (l1277 < 512); l1277 = (l1277 + 1)) {
			fVec38[l1277] = 0.0;
			
		}
		for (int l1278 = 0; (l1278 < 2); l1278 = (l1278 + 1)) {
			fRec1853[l1278] = 0.0;
			
		}
		for (int l1279 = 0; (l1279 < 2); l1279 = (l1279 + 1)) {
			fRec1851[l1279] = 0.0;
			
		}
		for (int l1280 = 0; (l1280 < 2); l1280 = (l1280 + 1)) {
			fRec1850[l1280] = 0.0;
			
		}
		for (int l1281 = 0; (l1281 < 2); l1281 = (l1281 + 1)) {
			fRec1848[l1281] = 0.0;
			
		}
		for (int l1282 = 0; (l1282 < 2); l1282 = (l1282 + 1)) {
			fRec1847[l1282] = 0.0;
			
		}
		for (int l1283 = 0; (l1283 < 2); l1283 = (l1283 + 1)) {
			fRec1845[l1283] = 0.0;
			
		}
		for (int l1284 = 0; (l1284 < 2); l1284 = (l1284 + 1)) {
			fRec1844[l1284] = 0.0;
			
		}
		for (int l1285 = 0; (l1285 < 2); l1285 = (l1285 + 1)) {
			fRec1842[l1285] = 0.0;
			
		}
		for (int l1286 = 0; (l1286 < 2); l1286 = (l1286 + 1)) {
			fRec1841[l1286] = 0.0;
			
		}
		for (int l1287 = 0; (l1287 < 2); l1287 = (l1287 + 1)) {
			fRec1839[l1287] = 0.0;
			
		}
		for (int l1288 = 0; (l1288 < 2); l1288 = (l1288 + 1)) {
			fRec1865[l1288] = 0.0;
			
		}
		for (int l1289 = 0; (l1289 < 2); l1289 = (l1289 + 1)) {
			fRec1863[l1289] = 0.0;
			
		}
		for (int l1290 = 0; (l1290 < 2); l1290 = (l1290 + 1)) {
			fRec1862[l1290] = 0.0;
			
		}
		for (int l1291 = 0; (l1291 < 2); l1291 = (l1291 + 1)) {
			fRec1860[l1291] = 0.0;
			
		}
		for (int l1292 = 0; (l1292 < 2); l1292 = (l1292 + 1)) {
			fRec1859[l1292] = 0.0;
			
		}
		for (int l1293 = 0; (l1293 < 2); l1293 = (l1293 + 1)) {
			fRec1857[l1293] = 0.0;
			
		}
		for (int l1294 = 0; (l1294 < 2); l1294 = (l1294 + 1)) {
			fRec1856[l1294] = 0.0;
			
		}
		for (int l1295 = 0; (l1295 < 2); l1295 = (l1295 + 1)) {
			fRec1854[l1295] = 0.0;
			
		}
		for (int l1296 = 0; (l1296 < 2); l1296 = (l1296 + 1)) {
			fRec1874[l1296] = 0.0;
			
		}
		for (int l1297 = 0; (l1297 < 2); l1297 = (l1297 + 1)) {
			fRec1872[l1297] = 0.0;
			
		}
		for (int l1298 = 0; (l1298 < 2); l1298 = (l1298 + 1)) {
			fRec1871[l1298] = 0.0;
			
		}
		for (int l1299 = 0; (l1299 < 2); l1299 = (l1299 + 1)) {
			fRec1869[l1299] = 0.0;
			
		}
		for (int l1300 = 0; (l1300 < 2); l1300 = (l1300 + 1)) {
			fRec1868[l1300] = 0.0;
			
		}
		for (int l1301 = 0; (l1301 < 2); l1301 = (l1301 + 1)) {
			fRec1866[l1301] = 0.0;
			
		}
		for (int l1302 = 0; (l1302 < 2); l1302 = (l1302 + 1)) {
			fRec1877[l1302] = 0.0;
			
		}
		for (int l1303 = 0; (l1303 < 2); l1303 = (l1303 + 1)) {
			fRec1875[l1303] = 0.0;
			
		}
		for (int l1304 = 0; (l1304 < 2); l1304 = (l1304 + 1)) {
			fRec1883[l1304] = 0.0;
			
		}
		for (int l1305 = 0; (l1305 < 2); l1305 = (l1305 + 1)) {
			fRec1881[l1305] = 0.0;
			
		}
		for (int l1306 = 0; (l1306 < 2); l1306 = (l1306 + 1)) {
			fRec1880[l1306] = 0.0;
			
		}
		for (int l1307 = 0; (l1307 < 2); l1307 = (l1307 + 1)) {
			fRec1878[l1307] = 0.0;
			
		}
		for (int l1308 = 0; (l1308 < 512); l1308 = (l1308 + 1)) {
			fVec39[l1308] = 0.0;
			
		}
		for (int l1309 = 0; (l1309 < 2); l1309 = (l1309 + 1)) {
			fRec1898[l1309] = 0.0;
			
		}
		for (int l1310 = 0; (l1310 < 2); l1310 = (l1310 + 1)) {
			fRec1896[l1310] = 0.0;
			
		}
		for (int l1311 = 0; (l1311 < 2); l1311 = (l1311 + 1)) {
			fRec1895[l1311] = 0.0;
			
		}
		for (int l1312 = 0; (l1312 < 2); l1312 = (l1312 + 1)) {
			fRec1893[l1312] = 0.0;
			
		}
		for (int l1313 = 0; (l1313 < 2); l1313 = (l1313 + 1)) {
			fRec1892[l1313] = 0.0;
			
		}
		for (int l1314 = 0; (l1314 < 2); l1314 = (l1314 + 1)) {
			fRec1890[l1314] = 0.0;
			
		}
		for (int l1315 = 0; (l1315 < 2); l1315 = (l1315 + 1)) {
			fRec1889[l1315] = 0.0;
			
		}
		for (int l1316 = 0; (l1316 < 2); l1316 = (l1316 + 1)) {
			fRec1887[l1316] = 0.0;
			
		}
		for (int l1317 = 0; (l1317 < 2); l1317 = (l1317 + 1)) {
			fRec1886[l1317] = 0.0;
			
		}
		for (int l1318 = 0; (l1318 < 2); l1318 = (l1318 + 1)) {
			fRec1884[l1318] = 0.0;
			
		}
		for (int l1319 = 0; (l1319 < 2); l1319 = (l1319 + 1)) {
			fRec1910[l1319] = 0.0;
			
		}
		for (int l1320 = 0; (l1320 < 2); l1320 = (l1320 + 1)) {
			fRec1908[l1320] = 0.0;
			
		}
		for (int l1321 = 0; (l1321 < 2); l1321 = (l1321 + 1)) {
			fRec1907[l1321] = 0.0;
			
		}
		for (int l1322 = 0; (l1322 < 2); l1322 = (l1322 + 1)) {
			fRec1905[l1322] = 0.0;
			
		}
		for (int l1323 = 0; (l1323 < 2); l1323 = (l1323 + 1)) {
			fRec1904[l1323] = 0.0;
			
		}
		for (int l1324 = 0; (l1324 < 2); l1324 = (l1324 + 1)) {
			fRec1902[l1324] = 0.0;
			
		}
		for (int l1325 = 0; (l1325 < 2); l1325 = (l1325 + 1)) {
			fRec1901[l1325] = 0.0;
			
		}
		for (int l1326 = 0; (l1326 < 2); l1326 = (l1326 + 1)) {
			fRec1899[l1326] = 0.0;
			
		}
		for (int l1327 = 0; (l1327 < 2); l1327 = (l1327 + 1)) {
			fRec1919[l1327] = 0.0;
			
		}
		for (int l1328 = 0; (l1328 < 2); l1328 = (l1328 + 1)) {
			fRec1917[l1328] = 0.0;
			
		}
		for (int l1329 = 0; (l1329 < 2); l1329 = (l1329 + 1)) {
			fRec1916[l1329] = 0.0;
			
		}
		for (int l1330 = 0; (l1330 < 2); l1330 = (l1330 + 1)) {
			fRec1914[l1330] = 0.0;
			
		}
		for (int l1331 = 0; (l1331 < 2); l1331 = (l1331 + 1)) {
			fRec1913[l1331] = 0.0;
			
		}
		for (int l1332 = 0; (l1332 < 2); l1332 = (l1332 + 1)) {
			fRec1911[l1332] = 0.0;
			
		}
		for (int l1333 = 0; (l1333 < 2); l1333 = (l1333 + 1)) {
			fRec1922[l1333] = 0.0;
			
		}
		for (int l1334 = 0; (l1334 < 2); l1334 = (l1334 + 1)) {
			fRec1920[l1334] = 0.0;
			
		}
		for (int l1335 = 0; (l1335 < 2); l1335 = (l1335 + 1)) {
			fRec1928[l1335] = 0.0;
			
		}
		for (int l1336 = 0; (l1336 < 2); l1336 = (l1336 + 1)) {
			fRec1926[l1336] = 0.0;
			
		}
		for (int l1337 = 0; (l1337 < 2); l1337 = (l1337 + 1)) {
			fRec1925[l1337] = 0.0;
			
		}
		for (int l1338 = 0; (l1338 < 2); l1338 = (l1338 + 1)) {
			fRec1923[l1338] = 0.0;
			
		}
		for (int l1339 = 0; (l1339 < 512); l1339 = (l1339 + 1)) {
			fVec40[l1339] = 0.0;
			
		}
		for (int l1340 = 0; (l1340 < 2); l1340 = (l1340 + 1)) {
			fRec1943[l1340] = 0.0;
			
		}
		for (int l1341 = 0; (l1341 < 2); l1341 = (l1341 + 1)) {
			fRec1941[l1341] = 0.0;
			
		}
		for (int l1342 = 0; (l1342 < 2); l1342 = (l1342 + 1)) {
			fRec1940[l1342] = 0.0;
			
		}
		for (int l1343 = 0; (l1343 < 2); l1343 = (l1343 + 1)) {
			fRec1938[l1343] = 0.0;
			
		}
		for (int l1344 = 0; (l1344 < 2); l1344 = (l1344 + 1)) {
			fRec1937[l1344] = 0.0;
			
		}
		for (int l1345 = 0; (l1345 < 2); l1345 = (l1345 + 1)) {
			fRec1935[l1345] = 0.0;
			
		}
		for (int l1346 = 0; (l1346 < 2); l1346 = (l1346 + 1)) {
			fRec1934[l1346] = 0.0;
			
		}
		for (int l1347 = 0; (l1347 < 2); l1347 = (l1347 + 1)) {
			fRec1932[l1347] = 0.0;
			
		}
		for (int l1348 = 0; (l1348 < 2); l1348 = (l1348 + 1)) {
			fRec1931[l1348] = 0.0;
			
		}
		for (int l1349 = 0; (l1349 < 2); l1349 = (l1349 + 1)) {
			fRec1929[l1349] = 0.0;
			
		}
		for (int l1350 = 0; (l1350 < 2); l1350 = (l1350 + 1)) {
			fRec1955[l1350] = 0.0;
			
		}
		for (int l1351 = 0; (l1351 < 2); l1351 = (l1351 + 1)) {
			fRec1953[l1351] = 0.0;
			
		}
		for (int l1352 = 0; (l1352 < 2); l1352 = (l1352 + 1)) {
			fRec1952[l1352] = 0.0;
			
		}
		for (int l1353 = 0; (l1353 < 2); l1353 = (l1353 + 1)) {
			fRec1950[l1353] = 0.0;
			
		}
		for (int l1354 = 0; (l1354 < 2); l1354 = (l1354 + 1)) {
			fRec1949[l1354] = 0.0;
			
		}
		for (int l1355 = 0; (l1355 < 2); l1355 = (l1355 + 1)) {
			fRec1947[l1355] = 0.0;
			
		}
		for (int l1356 = 0; (l1356 < 2); l1356 = (l1356 + 1)) {
			fRec1946[l1356] = 0.0;
			
		}
		for (int l1357 = 0; (l1357 < 2); l1357 = (l1357 + 1)) {
			fRec1944[l1357] = 0.0;
			
		}
		for (int l1358 = 0; (l1358 < 2); l1358 = (l1358 + 1)) {
			fRec1964[l1358] = 0.0;
			
		}
		for (int l1359 = 0; (l1359 < 2); l1359 = (l1359 + 1)) {
			fRec1962[l1359] = 0.0;
			
		}
		for (int l1360 = 0; (l1360 < 2); l1360 = (l1360 + 1)) {
			fRec1961[l1360] = 0.0;
			
		}
		for (int l1361 = 0; (l1361 < 2); l1361 = (l1361 + 1)) {
			fRec1959[l1361] = 0.0;
			
		}
		for (int l1362 = 0; (l1362 < 2); l1362 = (l1362 + 1)) {
			fRec1958[l1362] = 0.0;
			
		}
		for (int l1363 = 0; (l1363 < 2); l1363 = (l1363 + 1)) {
			fRec1956[l1363] = 0.0;
			
		}
		for (int l1364 = 0; (l1364 < 2); l1364 = (l1364 + 1)) {
			fRec1967[l1364] = 0.0;
			
		}
		for (int l1365 = 0; (l1365 < 2); l1365 = (l1365 + 1)) {
			fRec1965[l1365] = 0.0;
			
		}
		for (int l1366 = 0; (l1366 < 2); l1366 = (l1366 + 1)) {
			fRec1973[l1366] = 0.0;
			
		}
		for (int l1367 = 0; (l1367 < 2); l1367 = (l1367 + 1)) {
			fRec1971[l1367] = 0.0;
			
		}
		for (int l1368 = 0; (l1368 < 2); l1368 = (l1368 + 1)) {
			fRec1970[l1368] = 0.0;
			
		}
		for (int l1369 = 0; (l1369 < 2); l1369 = (l1369 + 1)) {
			fRec1968[l1369] = 0.0;
			
		}
		for (int l1370 = 0; (l1370 < 512); l1370 = (l1370 + 1)) {
			fVec41[l1370] = 0.0;
			
		}
		for (int l1371 = 0; (l1371 < 2); l1371 = (l1371 + 1)) {
			fRec1988[l1371] = 0.0;
			
		}
		for (int l1372 = 0; (l1372 < 2); l1372 = (l1372 + 1)) {
			fRec1986[l1372] = 0.0;
			
		}
		for (int l1373 = 0; (l1373 < 2); l1373 = (l1373 + 1)) {
			fRec1985[l1373] = 0.0;
			
		}
		for (int l1374 = 0; (l1374 < 2); l1374 = (l1374 + 1)) {
			fRec1983[l1374] = 0.0;
			
		}
		for (int l1375 = 0; (l1375 < 2); l1375 = (l1375 + 1)) {
			fRec1982[l1375] = 0.0;
			
		}
		for (int l1376 = 0; (l1376 < 2); l1376 = (l1376 + 1)) {
			fRec1980[l1376] = 0.0;
			
		}
		for (int l1377 = 0; (l1377 < 2); l1377 = (l1377 + 1)) {
			fRec1979[l1377] = 0.0;
			
		}
		for (int l1378 = 0; (l1378 < 2); l1378 = (l1378 + 1)) {
			fRec1977[l1378] = 0.0;
			
		}
		for (int l1379 = 0; (l1379 < 2); l1379 = (l1379 + 1)) {
			fRec1976[l1379] = 0.0;
			
		}
		for (int l1380 = 0; (l1380 < 2); l1380 = (l1380 + 1)) {
			fRec1974[l1380] = 0.0;
			
		}
		for (int l1381 = 0; (l1381 < 2); l1381 = (l1381 + 1)) {
			fRec2000[l1381] = 0.0;
			
		}
		for (int l1382 = 0; (l1382 < 2); l1382 = (l1382 + 1)) {
			fRec1998[l1382] = 0.0;
			
		}
		for (int l1383 = 0; (l1383 < 2); l1383 = (l1383 + 1)) {
			fRec1997[l1383] = 0.0;
			
		}
		for (int l1384 = 0; (l1384 < 2); l1384 = (l1384 + 1)) {
			fRec1995[l1384] = 0.0;
			
		}
		for (int l1385 = 0; (l1385 < 2); l1385 = (l1385 + 1)) {
			fRec1994[l1385] = 0.0;
			
		}
		for (int l1386 = 0; (l1386 < 2); l1386 = (l1386 + 1)) {
			fRec1992[l1386] = 0.0;
			
		}
		for (int l1387 = 0; (l1387 < 2); l1387 = (l1387 + 1)) {
			fRec1991[l1387] = 0.0;
			
		}
		for (int l1388 = 0; (l1388 < 2); l1388 = (l1388 + 1)) {
			fRec1989[l1388] = 0.0;
			
		}
		for (int l1389 = 0; (l1389 < 2); l1389 = (l1389 + 1)) {
			fRec2009[l1389] = 0.0;
			
		}
		for (int l1390 = 0; (l1390 < 2); l1390 = (l1390 + 1)) {
			fRec2007[l1390] = 0.0;
			
		}
		for (int l1391 = 0; (l1391 < 2); l1391 = (l1391 + 1)) {
			fRec2006[l1391] = 0.0;
			
		}
		for (int l1392 = 0; (l1392 < 2); l1392 = (l1392 + 1)) {
			fRec2004[l1392] = 0.0;
			
		}
		for (int l1393 = 0; (l1393 < 2); l1393 = (l1393 + 1)) {
			fRec2003[l1393] = 0.0;
			
		}
		for (int l1394 = 0; (l1394 < 2); l1394 = (l1394 + 1)) {
			fRec2001[l1394] = 0.0;
			
		}
		for (int l1395 = 0; (l1395 < 2); l1395 = (l1395 + 1)) {
			fRec2012[l1395] = 0.0;
			
		}
		for (int l1396 = 0; (l1396 < 2); l1396 = (l1396 + 1)) {
			fRec2010[l1396] = 0.0;
			
		}
		for (int l1397 = 0; (l1397 < 2); l1397 = (l1397 + 1)) {
			fRec2018[l1397] = 0.0;
			
		}
		for (int l1398 = 0; (l1398 < 2); l1398 = (l1398 + 1)) {
			fRec2016[l1398] = 0.0;
			
		}
		for (int l1399 = 0; (l1399 < 2); l1399 = (l1399 + 1)) {
			fRec2015[l1399] = 0.0;
			
		}
		for (int l1400 = 0; (l1400 < 2); l1400 = (l1400 + 1)) {
			fRec2013[l1400] = 0.0;
			
		}
		for (int l1401 = 0; (l1401 < 512); l1401 = (l1401 + 1)) {
			fVec42[l1401] = 0.0;
			
		}
		for (int l1402 = 0; (l1402 < 2); l1402 = (l1402 + 1)) {
			fRec2033[l1402] = 0.0;
			
		}
		for (int l1403 = 0; (l1403 < 2); l1403 = (l1403 + 1)) {
			fRec2031[l1403] = 0.0;
			
		}
		for (int l1404 = 0; (l1404 < 2); l1404 = (l1404 + 1)) {
			fRec2030[l1404] = 0.0;
			
		}
		for (int l1405 = 0; (l1405 < 2); l1405 = (l1405 + 1)) {
			fRec2028[l1405] = 0.0;
			
		}
		for (int l1406 = 0; (l1406 < 2); l1406 = (l1406 + 1)) {
			fRec2027[l1406] = 0.0;
			
		}
		for (int l1407 = 0; (l1407 < 2); l1407 = (l1407 + 1)) {
			fRec2025[l1407] = 0.0;
			
		}
		for (int l1408 = 0; (l1408 < 2); l1408 = (l1408 + 1)) {
			fRec2024[l1408] = 0.0;
			
		}
		for (int l1409 = 0; (l1409 < 2); l1409 = (l1409 + 1)) {
			fRec2022[l1409] = 0.0;
			
		}
		for (int l1410 = 0; (l1410 < 2); l1410 = (l1410 + 1)) {
			fRec2021[l1410] = 0.0;
			
		}
		for (int l1411 = 0; (l1411 < 2); l1411 = (l1411 + 1)) {
			fRec2019[l1411] = 0.0;
			
		}
		for (int l1412 = 0; (l1412 < 2); l1412 = (l1412 + 1)) {
			fRec2045[l1412] = 0.0;
			
		}
		for (int l1413 = 0; (l1413 < 2); l1413 = (l1413 + 1)) {
			fRec2043[l1413] = 0.0;
			
		}
		for (int l1414 = 0; (l1414 < 2); l1414 = (l1414 + 1)) {
			fRec2042[l1414] = 0.0;
			
		}
		for (int l1415 = 0; (l1415 < 2); l1415 = (l1415 + 1)) {
			fRec2040[l1415] = 0.0;
			
		}
		for (int l1416 = 0; (l1416 < 2); l1416 = (l1416 + 1)) {
			fRec2039[l1416] = 0.0;
			
		}
		for (int l1417 = 0; (l1417 < 2); l1417 = (l1417 + 1)) {
			fRec2037[l1417] = 0.0;
			
		}
		for (int l1418 = 0; (l1418 < 2); l1418 = (l1418 + 1)) {
			fRec2036[l1418] = 0.0;
			
		}
		for (int l1419 = 0; (l1419 < 2); l1419 = (l1419 + 1)) {
			fRec2034[l1419] = 0.0;
			
		}
		for (int l1420 = 0; (l1420 < 2); l1420 = (l1420 + 1)) {
			fRec2054[l1420] = 0.0;
			
		}
		for (int l1421 = 0; (l1421 < 2); l1421 = (l1421 + 1)) {
			fRec2052[l1421] = 0.0;
			
		}
		for (int l1422 = 0; (l1422 < 2); l1422 = (l1422 + 1)) {
			fRec2051[l1422] = 0.0;
			
		}
		for (int l1423 = 0; (l1423 < 2); l1423 = (l1423 + 1)) {
			fRec2049[l1423] = 0.0;
			
		}
		for (int l1424 = 0; (l1424 < 2); l1424 = (l1424 + 1)) {
			fRec2048[l1424] = 0.0;
			
		}
		for (int l1425 = 0; (l1425 < 2); l1425 = (l1425 + 1)) {
			fRec2046[l1425] = 0.0;
			
		}
		for (int l1426 = 0; (l1426 < 2); l1426 = (l1426 + 1)) {
			fRec2057[l1426] = 0.0;
			
		}
		for (int l1427 = 0; (l1427 < 2); l1427 = (l1427 + 1)) {
			fRec2055[l1427] = 0.0;
			
		}
		for (int l1428 = 0; (l1428 < 2); l1428 = (l1428 + 1)) {
			fRec2063[l1428] = 0.0;
			
		}
		for (int l1429 = 0; (l1429 < 2); l1429 = (l1429 + 1)) {
			fRec2061[l1429] = 0.0;
			
		}
		for (int l1430 = 0; (l1430 < 2); l1430 = (l1430 + 1)) {
			fRec2060[l1430] = 0.0;
			
		}
		for (int l1431 = 0; (l1431 < 2); l1431 = (l1431 + 1)) {
			fRec2058[l1431] = 0.0;
			
		}
		for (int l1432 = 0; (l1432 < 512); l1432 = (l1432 + 1)) {
			fVec43[l1432] = 0.0;
			
		}
		
	}
	
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("KMHLS_FullSetup_5h5v_full_6");
		ui_interface->declare(&fHslider0, "unit", "dB");
		ui_interface->addHorizontalSlider("gain", &fHslider0, -10.0, -30.0, 10.0, 1.0);
		ui_interface->declare(&fHslider2, "unit", "dB");
		ui_interface->addHorizontalSlider("lf/hf", &fHslider2, 0.0, -3.0, 3.0, 0.10000000000000001);
		ui_interface->addCheckButton("mute", &fCheckbox0);
		ui_interface->declare(&fHslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("xover", &fHslider1, 400.0, 200.0, 800.0, 20.0);
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
		FAUSTFLOAT* input25 = inputs[25];
		FAUSTFLOAT* input26 = inputs[26];
		FAUSTFLOAT* input27 = inputs[27];
		FAUSTFLOAT* input28 = inputs[28];
		FAUSTFLOAT* input29 = inputs[29];
		FAUSTFLOAT* input30 = inputs[30];
		FAUSTFLOAT* input31 = inputs[31];
		FAUSTFLOAT* input32 = inputs[32];
		FAUSTFLOAT* input33 = inputs[33];
		FAUSTFLOAT* input34 = inputs[34];
		FAUSTFLOAT* input35 = inputs[35];
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
		double fSlow0 = (0.0010000000000000009 * (double((double(fCheckbox0) < 0.5)) * std::pow(10.0, (0.050000000000000003 * double(fHslider0)))));
		double fSlow1 = (0.0010000000000000009 * double(fHslider1));
		double fSlow2 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fHslider2))));
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec0[0] = (fSlow0 + (0.999 * fRec0[1]));
			fRec1[0] = (fSlow1 + (0.999 * fRec1[1]));
			double fTemp0 = std::tan((fConst1 * fRec1[0]));
			double fTemp1 = mydsp_faustpower2_f(fTemp0);
			double fTemp2 = ((fTemp0 * (fTemp0 + -2.0)) + 1.0);
			double fTemp3 = (fTemp1 + -1.0);
			double fTemp4 = ((fTemp0 * (fTemp0 + 2.0)) + 1.0);
			fRec2[0] = (double(input0[i]) - (((fRec2[2] * fTemp2) + (2.0 * (fRec2[1] * fTemp3))) / fTemp4));
			fRec3[0] = (fSlow2 + (0.999 * fRec3[1]));
			double fTemp5 = (fRec3[0] * fTemp4);
			double fTemp6 = (0.0 - (2.0 / fTemp4));
			double fTemp7 = (((fTemp1 * (fRec2[2] + (fRec2[0] + (2.0 * fRec2[1])))) / fTemp5) + (fRec3[0] * (0.0 - ((fRec2[1] * fTemp6) + ((fRec2[0] + fRec2[2]) / fTemp4)))));
			double fTemp8 = (fConst4 * fRec4[1]);
			double fTemp9 = (fConst7 * fRec7[1]);
			double fTemp10 = (fConst8 * fRec10[1]);
			fRec19[0] = (double(input25[i]) - (((fTemp2 * fRec19[2]) + (2.0 * (fTemp3 * fRec19[1]))) / fTemp4));
			double fTemp11 = (((fTemp1 * (fRec19[2] + (fRec19[0] + (2.0 * fRec19[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec19[1]) + ((fRec19[0] + fRec19[2]) / fTemp4))))));
			fRec20[0] = (double(input26[i]) - (((fTemp2 * fRec20[2]) + (2.0 * (fTemp3 * fRec20[1]))) / fTemp4));
			double fTemp12 = (((fTemp1 * (fRec20[2] + (fRec20[0] + (2.0 * fRec20[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec20[1]) + ((fRec20[0] + fRec20[2]) / fTemp4))))));
			fRec21[0] = (double(input29[i]) - (((fTemp2 * fRec21[2]) + (2.0 * (fTemp3 * fRec21[1]))) / fTemp4));
			double fTemp13 = (((fTemp1 * (fRec21[2] + (fRec21[0] + (2.0 * fRec21[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec21[1]) + ((fRec21[0] + fRec21[2]) / fTemp4))))));
			fRec22[0] = (double(input30[i]) - (((fTemp2 * fRec22[2]) + (2.0 * (fTemp3 * fRec22[1]))) / fTemp4));
			double fTemp14 = (((fTemp1 * (fRec22[2] + (fRec22[0] + (2.0 * fRec22[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec22[1]) + ((fRec22[0] + fRec22[2]) / fTemp4))))));
			fRec23[0] = (double(input31[i]) - (((fTemp2 * fRec23[2]) + (2.0 * (fTemp3 * fRec23[1]))) / fTemp4));
			double fTemp15 = (((fTemp1 * (fRec23[2] + (fRec23[0] + (2.0 * fRec23[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec23[1]) + ((fRec23[0] + fRec23[2]) / fTemp4))))));
			fRec24[0] = (double(input27[i]) - (((fTemp2 * fRec24[2]) + (2.0 * (fTemp3 * fRec24[1]))) / fTemp4));
			double fTemp16 = (((fTemp1 * (fRec24[2] + (fRec24[0] + (2.0 * fRec24[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec24[1]) + ((fRec24[0] + fRec24[2]) / fTemp4))))));
			fRec25[0] = (double(input28[i]) - (((fTemp2 * fRec25[2]) + (2.0 * (fTemp3 * fRec25[1]))) / fTemp4));
			double fTemp17 = (((fTemp1 * (fRec25[2] + (fRec25[0] + (2.0 * fRec25[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec25[1]) + ((fRec25[0] + fRec25[2]) / fTemp4))))));
			fRec26[0] = (double(input32[i]) - (((fTemp2 * fRec26[2]) + (2.0 * (fTemp3 * fRec26[1]))) / fTemp4));
			double fTemp18 = (((fTemp1 * (fRec26[2] + (fRec26[0] + (2.0 * fRec26[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec26[1]) + ((fRec26[0] + fRec26[2]) / fTemp4))))));
			fRec27[0] = (double(input33[i]) - (((fTemp2 * fRec27[2]) + (2.0 * (fTemp3 * fRec27[1]))) / fTemp4));
			double fTemp19 = (((fTemp1 * (fRec27[2] + (fRec27[0] + (2.0 * fRec27[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec27[1]) + ((fRec27[0] + fRec27[2]) / fTemp4))))));
			fRec28[0] = (double(input34[i]) - (((fTemp2 * fRec28[2]) + (2.0 * (fTemp3 * fRec28[1]))) / fTemp4));
			double fTemp20 = (((fTemp1 * (fRec28[2] + (fRec28[0] + (2.0 * fRec28[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec28[1]) + ((fRec28[0] + fRec28[2]) / fTemp4))))));
			fRec29[0] = (double(input35[i]) - (((fTemp2 * fRec29[2]) + (2.0 * (fTemp3 * fRec29[1]))) / fTemp4));
			double fTemp21 = (((fTemp1 * (fRec29[2] + (fRec29[0] + (2.0 * fRec29[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec29[1]) + ((fRec29[0] + fRec29[2]) / fTemp4))))));
			double fTemp22 = (fConst10 * ((((((0.0396892732 * fTemp11) + (0.054817154200000003 * fTemp12)) + (0.0037084573000000002 * fTemp13)) + (0.046224300400000001 * fTemp14)) + (0.0108019012 * fTemp15)) - ((((((0.0298172794 * fTemp16) + (0.060413297800000001 * fTemp17)) + (0.030717128999999999 * fTemp18)) + (0.0043576392 * fTemp19)) + (0.043713218900000003 * fTemp20)) + (0.081740197299999998 * fTemp21))));
			double fTemp23 = (fConst11 * fRec13[1]);
			double fTemp24 = (fConst12 * fRec16[1]);
			fRec18[0] = (fTemp22 + (fTemp23 + (fRec18[1] + fTemp24)));
			fRec16[0] = fRec18[0];
			double fRec17 = ((fTemp24 + fTemp23) + fTemp22);
			fRec15[0] = (fRec16[0] + fRec15[1]);
			fRec13[0] = fRec15[0];
			double fRec14 = fRec17;
			fRec12[0] = (fTemp9 + (fTemp10 + (fRec14 + fRec12[1])));
			fRec10[0] = fRec12[0];
			double fRec11 = (fTemp9 + (fRec14 + fTemp10));
			fRec9[0] = (fRec10[0] + fRec9[1]);
			fRec7[0] = fRec9[0];
			double fRec8 = fRec11;
			fRec6[0] = (fTemp8 + (fRec8 + fRec6[1]));
			fRec4[0] = fRec6[0];
			double fRec5 = (fRec8 + fTemp8);
			double fTemp25 = (fConst14 * fRec30[1]);
			double fTemp26 = (fConst15 * fRec33[1]);
			fRec42[0] = (double(input16[i]) - (((fTemp2 * fRec42[2]) + (2.0 * (fTemp3 * fRec42[1]))) / fTemp4));
			double fTemp27 = (((fTemp1 * (fRec42[2] + (fRec42[0] + (2.0 * fRec42[1])))) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec42[1]) + ((fRec42[0] + fRec42[2]) / fTemp4))))));
			fRec43[0] = (double(input17[i]) - (((fTemp2 * fRec43[2]) + (2.0 * (fTemp3 * fRec43[1]))) / fTemp4));
			double fTemp28 = (((fTemp1 * (fRec43[2] + (fRec43[0] + (2.0 * fRec43[1])))) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec43[1]) + ((fRec43[0] + fRec43[2]) / fTemp4))))));
			fRec44[0] = (double(input20[i]) - (((fTemp2 * fRec44[2]) + (2.0 * (fTemp3 * fRec44[1]))) / fTemp4));
			double fTemp29 = (((fTemp1 * (fRec44[2] + (fRec44[0] + (2.0 * fRec44[1])))) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec44[1]) + ((fRec44[0] + fRec44[2]) / fTemp4))))));
			fRec45[0] = (double(input18[i]) - (((fTemp2 * fRec45[2]) + (2.0 * (fTemp3 * fRec45[1]))) / fTemp4));
			double fTemp30 = (((fTemp1 * (fRec45[2] + (fRec45[0] + (2.0 * fRec45[1])))) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec45[1]) + ((fRec45[0] + fRec45[2]) / fTemp4))))));
			fRec46[0] = (double(input19[i]) - (((fTemp2 * fRec46[2]) + (2.0 * (fTemp3 * fRec46[1]))) / fTemp4));
			double fTemp31 = (((fTemp1 * (fRec46[2] + (fRec46[0] + (2.0 * fRec46[1])))) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec46[1]) + ((fRec46[0] + fRec46[2]) / fTemp4))))));
			fRec47[0] = (double(input21[i]) - (((fTemp2 * fRec47[2]) + (2.0 * (fTemp3 * fRec47[1]))) / fTemp4));
			double fTemp32 = (((fTemp1 * (fRec47[2] + (fRec47[0] + (2.0 * fRec47[1])))) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec47[1]) + ((fRec47[0] + fRec47[2]) / fTemp4))))));
			fRec48[0] = (double(input22[i]) - (((fTemp2 * fRec48[2]) + (2.0 * (fTemp3 * fRec48[1]))) / fTemp4));
			double fTemp33 = (((fTemp1 * (fRec48[2] + (fRec48[0] + (2.0 * fRec48[1])))) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec48[1]) + ((fRec48[0] + fRec48[2]) / fTemp4))))));
			fRec49[0] = (double(input23[i]) - (((fTemp2 * fRec49[2]) + (2.0 * (fTemp3 * fRec49[1]))) / fTemp4));
			double fTemp34 = (((fTemp1 * (fRec49[2] + (fRec49[0] + (2.0 * fRec49[1])))) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec49[1]) + ((fRec49[0] + fRec49[2]) / fTemp4))))));
			fRec50[0] = (double(input24[i]) - (((fTemp2 * fRec50[2]) + (2.0 * (fTemp3 * fRec50[1]))) / fTemp4));
			double fTemp35 = (((fTemp1 * (fRec50[2] + (fRec50[0] + (2.0 * fRec50[1])))) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec50[1]) + ((fRec50[0] + fRec50[2]) / fTemp4))))));
			double fTemp36 = (fConst17 * ((((0.076301153100000005 * fTemp27) + (0.064431403900000003 * fTemp28)) + (0.019758352 * fTemp29)) - ((((((0.033049796200000002 * fTemp30) + (0.034642695199999997 * fTemp31)) + (0.055682894599999998 * fTemp32)) + (0.020987958099999999 * fTemp33)) + (0.0076640474000000004 * fTemp34)) + (0.050985000599999997 * fTemp35))));
			double fTemp37 = (fConst18 * fRec36[1]);
			double fTemp38 = (fConst19 * fRec39[1]);
			fRec41[0] = (fTemp36 + (fTemp37 + (fRec41[1] + fTemp38)));
			fRec39[0] = fRec41[0];
			double fRec40 = ((fTemp38 + fTemp37) + fTemp36);
			fRec38[0] = (fRec39[0] + fRec38[1]);
			fRec36[0] = fRec38[0];
			double fRec37 = fRec40;
			fRec35[0] = (fTemp25 + (fTemp26 + (fRec37 + fRec35[1])));
			fRec33[0] = fRec35[0];
			double fRec34 = (fTemp25 + (fRec37 + fTemp26));
			fRec32[0] = (fRec33[0] + fRec32[1]);
			fRec30[0] = fRec32[0];
			double fRec31 = fRec34;
			double fTemp39 = (fConst21 * fRec51[1]);
			fRec60[0] = (double(input9[i]) - (((fTemp2 * fRec60[2]) + (2.0 * (fTemp3 * fRec60[1]))) / fTemp4));
			double fTemp40 = (((fTemp1 * (fRec60[2] + (fRec60[0] + (2.0 * fRec60[1])))) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec60[1]) + ((fRec60[0] + fRec60[2]) / fTemp4))))));
			fRec61[0] = (double(input10[i]) - (((fTemp2 * fRec61[2]) + (2.0 * (fTemp3 * fRec61[1]))) / fTemp4));
			double fTemp41 = (((fTemp1 * (fRec61[2] + (fRec61[0] + (2.0 * fRec61[1])))) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec61[1]) + ((fRec61[0] + fRec61[2]) / fTemp4))))));
			fRec62[0] = (double(input14[i]) - (((fTemp2 * fRec62[2]) + (2.0 * (fTemp3 * fRec62[1]))) / fTemp4));
			double fTemp42 = (((fTemp1 * (fRec62[2] + (fRec62[0] + (2.0 * fRec62[1])))) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec62[1]) + ((fRec62[0] + fRec62[2]) / fTemp4))))));
			fRec63[0] = (double(input11[i]) - (((fTemp2 * fRec63[2]) + (2.0 * (fTemp3 * fRec63[1]))) / fTemp4));
			double fTemp43 = (((fTemp1 * (fRec63[2] + (fRec63[0] + (2.0 * fRec63[1])))) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec63[1]) + ((fRec63[0] + fRec63[2]) / fTemp4))))));
			fRec64[0] = (double(input12[i]) - (((fTemp2 * fRec64[2]) + (2.0 * (fTemp3 * fRec64[1]))) / fTemp4));
			double fTemp44 = (((fTemp1 * (fRec64[2] + (fRec64[0] + (2.0 * fRec64[1])))) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec64[1]) + ((fRec64[0] + fRec64[2]) / fTemp4))))));
			fRec65[0] = (double(input13[i]) - (((fTemp2 * fRec65[2]) + (2.0 * (fTemp3 * fRec65[1]))) / fTemp4));
			double fTemp45 = (((fTemp1 * (fRec65[2] + (fRec65[0] + (2.0 * fRec65[1])))) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec65[1]) + ((fRec65[0] + fRec65[2]) / fTemp4))))));
			fRec66[0] = (double(input15[i]) - (((fTemp2 * fRec66[2]) + (2.0 * (fTemp3 * fRec66[1]))) / fTemp4));
			double fTemp46 = (((fTemp1 * (fRec66[2] + (fRec66[0] + (2.0 * fRec66[1])))) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec66[1]) + ((fRec66[0] + fRec66[2]) / fTemp4))))));
			double fTemp47 = (fConst23 * ((((0.086992999000000001 * fTemp40) + (0.049152279799999997 * fTemp41)) + (0.023180860599999999 * fTemp42)) - ((((0.023616205899999999 * fTemp43) + (0.039840277200000003 * fTemp44)) + (0.041084534700000001 * fTemp45)) + (0.0047892942000000004 * fTemp46))));
			double fTemp48 = (fConst24 * fRec54[1]);
			double fTemp49 = (fConst25 * fRec57[1]);
			fRec59[0] = (fTemp47 + (fTemp48 + (fRec59[1] + fTemp49)));
			fRec57[0] = fRec59[0];
			double fRec58 = ((fTemp49 + fTemp48) + fTemp47);
			fRec56[0] = (fRec57[0] + fRec56[1]);
			fRec54[0] = fRec56[0];
			double fRec55 = fRec58;
			fRec53[0] = (fTemp39 + (fRec55 + fRec53[1]));
			fRec51[0] = fRec53[0];
			double fRec52 = (fRec55 + fTemp39);
			fRec70[0] = (double(input1[i]) - (((fTemp2 * fRec70[2]) + (2.0 * (fTemp3 * fRec70[1]))) / fTemp4));
			double fTemp50 = (((fTemp1 * (fRec70[2] + (fRec70[0] + (2.0 * fRec70[1])))) / fTemp5) + (0.93246951420000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec70[1]) + ((fRec70[0] + fRec70[2]) / fTemp4))))));
			fRec71[0] = (double(input2[i]) - (((fTemp2 * fRec71[2]) + (2.0 * (fTemp3 * fRec71[1]))) / fTemp4));
			double fTemp51 = (((fTemp1 * (fRec71[2] + (fRec71[0] + (2.0 * fRec71[1])))) / fTemp5) + (0.93246951420000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec71[1]) + ((fRec71[0] + fRec71[2]) / fTemp4))))));
			fRec72[0] = (double(input3[i]) - (((fTemp2 * fRec72[2]) + (2.0 * (fTemp3 * fRec72[1]))) / fTemp4));
			double fTemp52 = (((fTemp1 * (fRec72[2] + (fRec72[0] + (2.0 * fRec72[1])))) / fTemp5) + (0.93246951420000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec72[1]) + ((fRec72[0] + fRec72[2]) / fTemp4))))));
			double fTemp53 = (fConst27 * (((0.029726642500000001 * fTemp50) + (0.014911744100000001 * fTemp51)) + (0.048964367199999997 * fTemp52)));
			double fTemp54 = (fConst28 * fRec67[1]);
			fRec69[0] = (fTemp53 + (fRec69[1] + fTemp54));
			fRec67[0] = fRec69[0];
			double fRec68 = (fTemp54 + fTemp53);
			fRec79[0] = (double(input4[i]) - (((fTemp2 * fRec79[2]) + (2.0 * (fTemp3 * fRec79[1]))) / fTemp4));
			double fTemp55 = (((fTemp1 * (fRec79[2] + (fRec79[0] + (2.0 * fRec79[1])))) / fTemp5) + (0.80424909239999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec79[1]) + ((fRec79[0] + fRec79[2]) / fTemp4))))));
			fRec80[0] = (double(input5[i]) - (((fTemp2 * fRec80[2]) + (2.0 * (fTemp3 * fRec80[1]))) / fTemp4));
			double fTemp56 = (((fTemp1 * (fRec80[2] + (fRec80[0] + (2.0 * fRec80[1])))) / fTemp5) + (0.80424909239999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec80[1]) + ((fRec80[0] + fRec80[2]) / fTemp4))))));
			fRec81[0] = (double(input7[i]) - (((fTemp2 * fRec81[2]) + (2.0 * (fTemp3 * fRec81[1]))) / fTemp4));
			double fTemp57 = (((fTemp1 * (fRec81[2] + (fRec81[0] + (2.0 * fRec81[1])))) / fTemp5) + (0.80424909239999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec81[1]) + ((fRec81[0] + fRec81[2]) / fTemp4))))));
			fRec82[0] = (double(input8[i]) - (((fTemp2 * fRec82[2]) + (2.0 * (fTemp3 * fRec82[1]))) / fTemp4));
			double fTemp58 = (((fTemp1 * (fRec82[2] + (fRec82[0] + (2.0 * fRec82[1])))) / fTemp5) + (0.80424909239999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec82[1]) + ((fRec82[0] + fRec82[2]) / fTemp4))))));
			fRec83[0] = (double(input6[i]) - (((fTemp2 * fRec83[2]) + (2.0 * (fTemp3 * fRec83[1]))) / fTemp4));
			double fTemp59 = (((fTemp1 * (fRec83[2] + (fRec83[0] + (2.0 * fRec83[1])))) / fTemp5) + (0.80424909239999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec83[1]) + ((fRec83[0] + fRec83[2]) / fTemp4))))));
			double fTemp60 = (fConst30 * (((((0.067278733399999999 * fTemp55) + (0.0210625147 * fTemp56)) + (0.033079176799999999 * fTemp57)) + (0.035296655400000002 * fTemp58)) - (0.037263030000000003 * fTemp59)));
			double fTemp61 = (fConst31 * fRec73[1]);
			double fTemp62 = (fConst32 * fRec76[1]);
			fRec78[0] = (fTemp60 + (fTemp61 + (fRec78[1] + fTemp62)));
			fRec76[0] = fRec78[0];
			double fRec77 = ((fTemp62 + fTemp61) + fTemp60);
			fRec75[0] = (fRec76[0] + fRec75[1]);
			fRec73[0] = fRec75[0];
			double fRec74 = fRec77;
			fVec0[(IOTA & 127)] = ((0.020287651300000001 * fTemp7) + (fRec5 + (fRec31 + (fRec52 + (fRec68 + fRec74)))));
			output0[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec0[((IOTA - iConst33) & 127)])));
			double fTemp63 = (fConst35 * fRec84[1]);
			double fTemp64 = (fConst37 * fRec87[1]);
			double fTemp65 = (fConst38 * fRec90[1]);
			double fTemp66 = (fConst40 * (((0.0610103715 * fTemp21) + (((0.029800903600000001 * fTemp15) + ((0.034537388099999997 * fTemp14) + (((0.0498576274 * fTemp11) + (0.026404712600000001 * fTemp12)) + (0.0033494699999999998 * fTemp13)))) + (0.038495813300000001 * fTemp20))) - ((0.037791204799999999 * fTemp19) + (((0.0144749578 * fTemp16) + (0.013960914899999999 * fTemp17)) + (0.046713316599999999 * fTemp18)))));
			double fTemp67 = (fConst41 * fRec93[1]);
			double fTemp68 = (fConst42 * fRec96[1]);
			fRec98[0] = (fTemp66 + (fTemp67 + (fRec98[1] + fTemp68)));
			fRec96[0] = fRec98[0];
			double fRec97 = ((fTemp68 + fTemp67) + fTemp66);
			fRec95[0] = (fRec96[0] + fRec95[1]);
			fRec93[0] = fRec95[0];
			double fRec94 = fRec97;
			fRec92[0] = (fTemp64 + (fTemp65 + (fRec94 + fRec92[1])));
			fRec90[0] = fRec92[0];
			double fRec91 = (fTemp64 + (fRec94 + fTemp65));
			fRec89[0] = (fRec90[0] + fRec89[1]);
			fRec87[0] = fRec89[0];
			double fRec88 = fRec91;
			fRec86[0] = (fTemp63 + (fRec88 + fRec86[1]));
			fRec84[0] = fRec86[0];
			double fRec85 = (fRec88 + fTemp63);
			double fTemp69 = (fConst44 * fRec99[1]);
			double fTemp70 = (fConst45 * fRec102[1]);
			double fTemp71 = (fConst47 * (((0.065033544400000004 * fTemp35) + ((((0.039804079899999997 * fTemp27) + (0.017662780699999998 * fTemp28)) + (0.026841980200000001 * fTemp29)) + (0.036427192300000001 * fTemp34))) - ((0.042734200999999999 * fTemp33) + (((0.0111106212 * fTemp30) + (0.0063062444999999996 * fTemp31)) + (0.042520284899999997 * fTemp32)))));
			double fTemp72 = (fConst48 * fRec105[1]);
			double fTemp73 = (fConst49 * fRec108[1]);
			fRec110[0] = (fTemp71 + (fTemp72 + (fRec110[1] + fTemp73)));
			fRec108[0] = fRec110[0];
			double fRec109 = ((fTemp73 + fTemp72) + fTemp71);
			fRec107[0] = (fRec108[0] + fRec107[1]);
			fRec105[0] = fRec107[0];
			double fRec106 = fRec109;
			fRec104[0] = (fTemp69 + (fTemp70 + (fRec106 + fRec104[1])));
			fRec102[0] = fRec104[0];
			double fRec103 = (fTemp69 + (fRec106 + fTemp70));
			fRec101[0] = (fRec102[0] + fRec101[1]);
			fRec99[0] = fRec101[0];
			double fRec100 = fRec103;
			double fTemp74 = (fConst51 * fRec111[1]);
			double fTemp75 = (fConst53 * (((0.063815383899999994 * fTemp46) + (((0.0279606001 * fTemp40) + (0.0095417018999999995 * fTemp41)) + (0.030657757000000001 * fTemp42))) - (((0.0059679968999999996 * fTemp43) + (0.024076274200000001 * fTemp44)) + (0.045125815 * fTemp45))));
			double fTemp76 = (fConst54 * fRec114[1]);
			double fTemp77 = (fConst55 * fRec117[1]);
			fRec119[0] = (fTemp75 + (fTemp76 + (fRec119[1] + fTemp77)));
			fRec117[0] = fRec119[0];
			double fRec118 = ((fTemp77 + fTemp76) + fTemp75);
			fRec116[0] = (fRec117[0] + fRec116[1]);
			fRec114[0] = fRec116[0];
			double fRec115 = fRec118;
			fRec113[0] = (fTemp74 + (fRec115 + fRec113[1]));
			fRec111[0] = fRec113[0];
			double fRec112 = (fRec115 + fTemp74);
			double fTemp78 = (fConst57 * (((0.0059429141000000001 * fTemp50) + (0.0081434539 * fTemp51)) + (0.042622415099999998 * fTemp52)));
			double fTemp79 = (fConst58 * fRec120[1]);
			fRec122[0] = (fTemp78 + (fRec122[1] + fTemp79));
			fRec120[0] = fRec122[0];
			double fRec121 = (fTemp79 + fTemp78);
			double fTemp80 = (fConst60 * (((((0.016014700199999999 * fTemp55) + (0.0033428676 * fTemp56)) + (0.021908569900000001 * fTemp57)) + (0.0565179216 * fTemp58)) - (0.031246433099999998 * fTemp59)));
			double fTemp81 = (fConst61 * fRec123[1]);
			double fTemp82 = (fConst62 * fRec126[1]);
			fRec128[0] = (fTemp80 + (fTemp81 + (fRec128[1] + fTemp82)));
			fRec126[0] = fRec128[0];
			double fRec127 = ((fTemp82 + fTemp81) + fTemp80);
			fRec125[0] = (fRec126[0] + fRec125[1]);
			fRec123[0] = fRec125[0];
			double fRec124 = fRec127;
			fVec1[(IOTA & 127)] = ((0.0148930529 * fTemp7) + (fRec85 + (fRec100 + (fRec112 + (fRec121 + fRec124)))));
			output1[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec1[((IOTA - iConst63) & 127)])));
			double fTemp83 = (fConst35 * fRec129[1]);
			double fTemp84 = (fConst37 * fRec132[1]);
			double fTemp85 = (fConst38 * fRec135[1]);
			double fTemp86 = (fConst40 * (((0.029884990399999999 * fTemp21) + (((0.0103474541 * fTemp15) + (((0.024205872699999999 * fTemp16) + (0.030722377799999999 * fTemp17)) + (0.046285968800000001 * fTemp14))) + (0.043768999500000003 * fTemp20))) - ((0.018109806199999998 * fTemp19) + ((((0.085898492199999996 * fTemp11) + (0.0547875372 * fTemp12)) + (0.0050272477999999997 * fTemp13)) + (0.060489767399999998 * fTemp18)))));
			double fTemp87 = (fConst41 * fRec138[1]);
			double fTemp88 = (fConst42 * fRec141[1]);
			fRec143[0] = (fTemp86 + (fTemp87 + (fRec143[1] + fTemp88)));
			fRec141[0] = fRec143[0];
			double fRec142 = ((fTemp88 + fTemp87) + fTemp86);
			fRec140[0] = (fRec141[0] + fRec140[1]);
			fRec138[0] = fRec140[0];
			double fRec139 = fRec142;
			fRec137[0] = (fTemp84 + (fTemp85 + (fRec139 + fRec137[1])));
			fRec135[0] = fRec137[0];
			double fRec136 = (fTemp84 + (fRec139 + fTemp85));
			fRec134[0] = (fRec135[0] + fRec134[1]);
			fRec132[0] = fRec134[0];
			double fRec133 = fRec136;
			fRec131[0] = (fTemp83 + (fRec133 + fRec131[1]));
			fRec129[0] = fRec131[0];
			double fRec130 = (fRec133 + fTemp83);
			double fTemp89 = (fConst44 * fRec144[1]);
			double fTemp90 = (fConst45 * fRec147[1]);
			double fTemp91 = (fConst47 * (((0.0511303491 * fTemp35) + ((((0.021007529899999999 * fTemp30) + (0.014877479399999999 * fTemp31)) + (0.019820992499999999 * fTemp29)) + (0.051029004900000001 * fTemp34))) - ((0.033150009199999997 * fTemp33) + (((0.076321344499999999 * fTemp27) + (0.040122302200000001 * fTemp28)) + (0.063934425599999997 * fTemp32)))));
			double fTemp92 = (fConst48 * fRec150[1]);
			double fTemp93 = (fConst49 * fRec153[1]);
			fRec155[0] = (fTemp91 + (fTemp92 + (fRec155[1] + fTemp93)));
			fRec153[0] = fRec155[0];
			double fRec154 = ((fTemp93 + fTemp92) + fTemp91);
			fRec152[0] = (fRec153[0] + fRec152[1]);
			fRec150[0] = fRec152[0];
			double fRec151 = fRec154;
			fRec149[0] = (fTemp89 + (fTemp90 + (fRec151 + fRec149[1])));
			fRec147[0] = fRec149[0];
			double fRec148 = (fTemp89 + (fRec151 + fTemp90));
			fRec146[0] = (fRec147[0] + fRec146[1]);
			fRec144[0] = fRec146[0];
			double fRec145 = fRec148;
			double fTemp94 = (fConst51 * fRec156[1]);
			double fTemp95 = (fConst53 * (((0.065029318399999994 * fTemp46) + ((0.0123580171 * fTemp43) + (0.049193511199999998 * fTemp42))) - ((((0.058135137599999998 * fTemp40) + (0.023170943100000001 * fTemp41)) + (0.039874397800000003 * fTemp44)) + (0.045841434700000003 * fTemp45))));
			double fTemp96 = (fConst54 * fRec159[1]);
			double fTemp97 = (fConst55 * fRec162[1]);
			fRec164[0] = (fTemp95 + (fTemp96 + (fRec164[1] + fTemp97)));
			fRec162[0] = fRec164[0];
			double fRec163 = ((fTemp97 + fTemp96) + fTemp95);
			fRec161[0] = (fRec162[0] + fRec161[1]);
			fRec159[0] = fRec161[0];
			double fRec160 = fRec163;
			fRec158[0] = (fTemp94 + (fRec160 + fRec158[1]));
			fRec156[0] = fRec158[0];
			double fRec157 = (fRec160 + fTemp94);
			double fTemp98 = (fConst57 * (((0.0149225192 * fTemp51) + (0.055717587200000002 * fTemp52)) - (0.0136027847 * fTemp50)));
			double fTemp99 = (fConst58 * fRec165[1]);
			fRec167[0] = (fTemp98 + (fRec167[1] + fTemp99));
			fRec165[0] = fRec167[0];
			double fRec166 = (fTemp99 + fTemp98);
			double fTemp100 = (fConst60 * (((0.038313226700000001 * fTemp57) + (0.067383992200000006 * fTemp58)) - (((0.0352983147 * fTemp55) + (0.0084932597000000002 * fTemp56)) + (0.037320288799999997 * fTemp59))));
			double fTemp101 = (fConst61 * fRec168[1]);
			double fTemp102 = (fConst62 * fRec171[1]);
			fRec173[0] = (fTemp100 + (fTemp101 + (fRec173[1] + fTemp102)));
			fRec171[0] = fRec173[0];
			double fRec172 = ((fTemp102 + fTemp101) + fTemp100);
			fRec170[0] = (fRec171[0] + fRec170[1]);
			fRec168[0] = fRec170[0];
			double fRec169 = fRec172;
			fVec2[(IOTA & 127)] = ((0.020312997499999999 * fTemp7) + (fRec130 + (fRec145 + (fRec157 + (fRec166 + fRec169)))));
			output2[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec2[((IOTA - iConst63) & 127)])));
			double fTemp103 = (fConst65 * fRec174[1]);
			double fTemp104 = (fConst67 * fRec177[1]);
			double fTemp105 = (fConst68 * fRec180[1]);
			double fTemp106 = (fConst70 * ((((0.023458194299999999 * fTemp15) + ((((0.0080179275000000008 * fTemp11) + (0.036957929100000002 * fTemp16)) + (0.046776700300000001 * fTemp17)) + (0.034595999299999999 * fTemp14))) + (0.016546496599999998 * fTemp19)) - ((0.078341055000000007 * fTemp21) + ((((0.026347488299999999 * fTemp12) + (0.018734932400000001 * fTemp13)) + (0.013936473 * fTemp18)) + (0.038515220599999997 * fTemp20)))));
			double fTemp107 = (fConst71 * fRec183[1]);
			double fTemp108 = (fConst72 * fRec186[1]);
			fRec188[0] = (fTemp106 + (fTemp107 + (fRec188[1] + fTemp108)));
			fRec186[0] = fRec188[0];
			double fRec187 = ((fTemp108 + fTemp107) + fTemp106);
			fRec185[0] = (fRec186[0] + fRec185[1]);
			fRec183[0] = fRec185[0];
			double fRec184 = fRec187;
			fRec182[0] = (fTemp104 + (fTemp105 + (fRec184 + fRec182[1])));
			fRec180[0] = fRec182[0];
			double fRec181 = (fTemp104 + (fRec184 + fTemp105));
			fRec179[0] = (fRec180[0] + fRec179[1]);
			fRec177[0] = fRec179[0];
			double fRec178 = fRec181;
			fRec176[0] = (fTemp103 + (fRec178 + fRec176[1]));
			fRec174[0] = fRec176[0];
			double fRec175 = (fRec178 + fTemp103);
			double fTemp109 = (fConst74 * fRec189[1]);
			double fTemp110 = (fConst75 * fRec192[1]);
			double fTemp111 = (fConst77 * ((((0.0427717523 * fTemp30) + (0.025651679300000001 * fTemp31)) + (0.026866896800000001 * fTemp29)) - ((0.065078857599999998 * fTemp35) + ((0.0133093237 * fTemp34) + ((0.011081738799999999 * fTemp33) + (((0.039704409000000003 * fTemp27) + (0.0382424835 * fTemp28)) + (0.0345562674 * fTemp32)))))));
			double fTemp112 = (fConst78 * fRec195[1]);
			double fTemp113 = (fConst79 * fRec198[1]);
			fRec200[0] = (fTemp111 + (fTemp112 + (fRec200[1] + fTemp113)));
			fRec198[0] = fRec200[0];
			double fRec199 = ((fTemp113 + fTemp112) + fTemp111);
			fRec197[0] = (fRec198[0] + fRec197[1]);
			fRec195[0] = fRec197[0];
			double fRec196 = fRec199;
			fRec194[0] = (fTemp109 + (fTemp110 + (fRec196 + fRec194[1])));
			fRec192[0] = fRec194[0];
			double fRec193 = (fTemp109 + (fRec196 + fTemp110));
			fRec191[0] = (fRec192[0] + fRec191[1]);
			fRec189[0] = fRec191[0];
			double fRec190 = fRec193;
			double fTemp114 = (fConst81 * fRec201[1]);
			double fTemp115 = (fConst83 * (((0.027722318400000001 * fTemp43) + (0.0095264601000000001 * fTemp42)) - (((((0.064875679500000005 * fTemp40) + (0.030682623900000001 * fTemp41)) + (0.024102140099999999 * fTemp44)) + (0.036142177400000003 * fTemp45)) + (0.0254269453 * fTemp46))));
			double fTemp116 = (fConst84 * fRec204[1]);
			double fTemp117 = (fConst85 * fRec207[1]);
			fRec209[0] = (fTemp115 + (fTemp116 + (fRec209[1] + fTemp117)));
			fRec207[0] = fRec209[0];
			double fRec208 = ((fTemp117 + fTemp116) + fTemp115);
			fRec206[0] = (fRec207[0] + fRec206[1]);
			fRec204[0] = fRec206[0];
			double fRec205 = fRec208;
			fRec203[0] = (fTemp114 + (fRec205 + fRec203[1]));
			fRec201[0] = fRec203[0];
			double fRec202 = (fRec205 + fTemp114);
			double fTemp118 = (fConst87 * (((0.0081500327000000004 * fTemp51) + (0.034347769799999997 * fTemp52)) - (0.025961405699999999 * fTemp50)));
			double fTemp119 = (fConst88 * fRec210[1]);
			fRec212[0] = (fTemp118 + (fRec212[1] + fTemp119));
			fRec210[0] = fRec212[0];
			double fRec211 = (fTemp119 + fTemp118);
			double fTemp120 = (fConst90 * (((0.017865129099999998 * fTemp57) + (0.0159787136 * fTemp58)) - (((0.0565492067 * fTemp55) + (0.013144476 * fTemp56)) + (0.031266058399999998 * fTemp59))));
			double fTemp121 = (fConst91 * fRec213[1]);
			double fTemp122 = (fConst92 * fRec216[1]);
			fRec218[0] = (fTemp120 + (fTemp121 + (fRec218[1] + fTemp122)));
			fRec216[0] = fRec218[0];
			double fRec217 = ((fTemp122 + fTemp121) + fTemp120);
			fRec215[0] = (fRec216[0] + fRec215[1]);
			fRec213[0] = fRec215[0];
			double fRec214 = fRec217;
			fVec3[(IOTA & 127)] = ((0.0149006869 * fTemp7) + (fRec175 + (fRec190 + (fRec202 + (fRec211 + fRec214)))));
			output3[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec3[((IOTA - iConst93) & 127)])));
			double fTemp123 = (fConst4 * fRec219[1]);
			double fTemp124 = (fConst7 * fRec222[1]);
			double fTemp125 = (fConst8 * fRec225[1]);
			double fTemp126 = (fConst10 * ((((0.0297898495 * fTemp19) + ((0.0307044517 * fTemp18) + ((0.0036895679999999998 * fTemp15) + ((((0.081833013499999996 * fTemp11) + (0.054834235699999997 * fTemp12)) + (0.060459402099999997 * fTemp17)) + (0.046242541800000002 * fTemp14))))) + (0.039613907699999999 * fTemp21)) - (((0.0043437364999999997 * fTemp16) + (0.0107702131 * fTemp13)) + (0.0438127642 * fTemp20))));
			double fTemp127 = (fConst11 * fRec228[1]);
			double fTemp128 = (fConst12 * fRec231[1]);
			fRec233[0] = (fTemp126 + (fTemp127 + (fRec233[1] + fTemp128)));
			fRec231[0] = fRec233[0];
			double fRec232 = ((fTemp128 + fTemp127) + fTemp126);
			fRec230[0] = (fRec231[0] + fRec230[1]);
			fRec228[0] = fRec230[0];
			double fRec229 = fRec232;
			fRec227[0] = (fTemp124 + (fTemp125 + (fRec229 + fRec227[1])));
			fRec225[0] = fRec227[0];
			double fRec226 = (fTemp124 + (fRec229 + fTemp125));
			fRec224[0] = (fRec225[0] + fRec224[1]);
			fRec222[0] = fRec224[0];
			double fRec223 = fRec226;
			fRec221[0] = (fTemp123 + (fRec223 + fRec221[1]));
			fRec219[0] = fRec221[0];
			double fRec220 = (fRec223 + fTemp123);
			double fTemp129 = (fConst14 * fRec234[1]);
			double fTemp130 = (fConst15 * fRec237[1]);
			double fTemp131 = (fConst17 * ((((((0.076292876199999998 * fTemp27) + (0.033044275999999997 * fTemp30)) + (0.055717674699999997 * fTemp31)) + (0.0197401109 * fTemp29)) + (0.020965751000000001 * fTemp33)) - ((0.051095692800000002 * fTemp35) + (((0.0077241684000000001 * fTemp28) + (0.034685050799999999 * fTemp32)) + (0.064498979999999997 * fTemp34)))));
			double fTemp132 = (fConst18 * fRec240[1]);
			double fTemp133 = (fConst19 * fRec243[1]);
			fRec245[0] = (fTemp131 + (fTemp132 + (fRec245[1] + fTemp133)));
			fRec243[0] = fRec245[0];
			double fRec244 = ((fTemp133 + fTemp132) + fTemp131);
			fRec242[0] = (fRec243[0] + fRec242[1]);
			fRec240[0] = fRec242[0];
			double fRec241 = fRec244;
			fRec239[0] = (fTemp129 + (fTemp130 + (fRec241 + fRec239[1])));
			fRec237[0] = fRec239[0];
			double fRec238 = (fTemp129 + (fRec241 + fTemp130));
			fRec236[0] = (fRec237[0] + fRec236[1]);
			fRec234[0] = fRec236[0];
			double fRec235 = fRec238;
			double fTemp134 = (fConst21 * fRec246[1]);
			double fTemp135 = (fConst23 * ((0.041079877600000002 * fTemp43) - ((0.087044369400000002 * fTemp46) + (((((0.0048662371000000003 * fTemp40) + (0.049225619300000002 * fTemp41)) + (0.039881970900000001 * fTemp44)) + (0.0236276347 * fTemp45)) + (0.023181087900000001 * fTemp42)))));
			double fTemp136 = (fConst24 * fRec249[1]);
			double fTemp137 = (fConst25 * fRec252[1]);
			fRec254[0] = (fTemp135 + (fTemp136 + (fRec254[1] + fTemp137)));
			fRec252[0] = fRec254[0];
			double fRec253 = ((fTemp137 + fTemp136) + fTemp135);
			fRec251[0] = (fRec252[0] + fRec251[1]);
			fRec249[0] = fRec251[0];
			double fRec250 = fRec253;
			fRec248[0] = (fTemp134 + (fRec250 + fRec248[1]));
			fRec246[0] = fRec248[0];
			double fRec247 = (fRec250 + fTemp134);
			double fTemp138 = (fConst27 * (((0.014932782 * fTemp51) + (0.029763579500000002 * fTemp52)) - (0.0489911445 * fTemp50)));
			double fTemp139 = (fConst28 * fRec255[1]);
			fRec257[0] = (fTemp138 + (fRec257[1] + fTemp139));
			fRec255[0] = fRec257[0];
			double fRec256 = (fTemp139 + fTemp138);
			double fTemp140 = (fConst30 * ((0.0211000418 * fTemp57) - ((((0.067345779199999997 * fTemp55) + (0.033116199399999997 * fTemp56)) + (0.037278278400000003 * fTemp59)) + (0.035280652199999998 * fTemp58))));
			double fTemp141 = (fConst31 * fRec258[1]);
			double fTemp142 = (fConst32 * fRec261[1]);
			fRec263[0] = (fTemp140 + (fTemp141 + (fRec263[1] + fTemp142)));
			fRec261[0] = fRec263[0];
			double fRec262 = ((fTemp142 + fTemp141) + fTemp140);
			fRec260[0] = (fRec261[0] + fRec260[1]);
			fRec258[0] = fRec260[0];
			double fRec259 = fRec262;
			fVec4[(IOTA & 127)] = ((0.020303679599999999 * fTemp7) + (fRec220 + (fRec235 + (fRec247 + (fRec256 + fRec259)))));
			output4[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec4[((IOTA - iConst33) & 127)])));
			double fTemp143 = (fConst60 * ((0.0033472354000000002 * fTemp57) - ((((0.015994445400000001 * fTemp55) + (0.021911849000000001 * fTemp56)) + (0.031196030900000001 * fTemp59)) + (0.0564357786 * fTemp58))));
			double fTemp144 = (fConst61 * fRec264[1]);
			double fTemp145 = (fConst62 * fRec267[1]);
			fRec269[0] = (fTemp143 + (fTemp144 + (fRec269[1] + fTemp145)));
			fRec267[0] = fRec269[0];
			double fRec268 = ((fTemp145 + fTemp144) + fTemp143);
			fRec266[0] = (fRec267[0] + fRec266[1]);
			fRec264[0] = fRec266[0];
			double fRec265 = fRec268;
			double fTemp146 = (fConst57 * (((0.0081455725999999996 * fTemp51) + (0.0059358450000000004 * fTemp52)) - (0.042561055899999999 * fTemp50)));
			double fTemp147 = (fConst58 * fRec270[1]);
			fRec272[0] = (fTemp146 + (fRec272[1] + fTemp147));
			fRec270[0] = fRec272[0];
			double fRec271 = (fTemp147 + fTemp146);
			double fTemp148 = (fConst35 * fRec273[1]);
			double fTemp149 = (fConst37 * fRec276[1]);
			double fTemp150 = (fConst38 * fRec279[1]);
			double fTemp151 = (fConst40 * (((0.049801534699999997 * fTemp21) + ((0.038476119000000003 * fTemp20) + ((0.014415492699999999 * fTemp19) + ((0.046709437600000001 * fTemp18) + ((0.00333103 * fTemp15) + (((0.026420590300000001 * fTemp12) + (0.013953110899999999 * fTemp17)) + (0.034537437800000001 * fTemp14))))))) - (((0.060931701800000002 * fTemp11) + (0.037739563400000002 * fTemp16)) + (0.0297501869 * fTemp13))));
			double fTemp152 = (fConst41 * fRec282[1]);
			double fTemp153 = (fConst42 * fRec285[1]);
			fRec287[0] = (fTemp151 + (fTemp152 + (fRec287[1] + fTemp153)));
			fRec285[0] = fRec287[0];
			double fRec286 = ((fTemp153 + fTemp152) + fTemp151);
			fRec284[0] = (fRec285[0] + fRec284[1]);
			fRec282[0] = fRec284[0];
			double fRec283 = fRec286;
			fRec281[0] = (fTemp149 + (fTemp150 + (fRec283 + fRec281[1])));
			fRec279[0] = fRec281[0];
			double fRec280 = (fTemp149 + (fRec283 + fTemp150));
			fRec278[0] = (fRec279[0] + fRec278[1]);
			fRec276[0] = fRec278[0];
			double fRec277 = fRec280;
			fRec275[0] = (fTemp148 + (fRec277 + fRec275[1]));
			fRec273[0] = fRec275[0];
			double fRec274 = (fRec277 + fTemp148);
			double fTemp154 = (fConst51 * fRec288[1]);
			double fTemp155 = (fConst53 * (((0.063723541300000006 * fTemp40) + (0.045048390200000003 * fTemp43)) - ((0.027924622400000002 * fTemp46) + ((((0.0095516922999999993 * fTemp41) + (0.024077398900000001 * fTemp44)) + (0.0059519671999999999 * fTemp45)) + (0.030657397100000001 * fTemp42)))));
			double fTemp156 = (fConst54 * fRec291[1]);
			double fTemp157 = (fConst55 * fRec294[1]);
			fRec296[0] = (fTemp155 + (fTemp156 + (fRec296[1] + fTemp157)));
			fRec294[0] = fRec296[0];
			double fRec295 = ((fTemp157 + fTemp156) + fTemp155);
			fRec293[0] = (fRec294[0] + fRec293[1]);
			fRec291[0] = fRec293[0];
			double fRec292 = fRec295;
			fRec290[0] = (fTemp154 + (fRec292 + fRec290[1]));
			fRec288[0] = fRec290[0];
			double fRec289 = (fRec292 + fTemp154);
			double fTemp158 = (fConst44 * fRec297[1]);
			double fTemp159 = (fConst45 * fRec300[1]);
			double fTemp160 = (fConst47 * ((((((((0.039754495799999998 * fTemp27) + (0.0364189397 * fTemp28)) + (0.011072909000000001 * fTemp30)) + (0.042518380500000001 * fTemp31)) + (0.026792149099999999 * fTemp29)) + (0.042662779200000001 * fTemp33)) + (0.064943307899999997 * fTemp35)) - ((0.0063062281999999997 * fTemp32) + (0.017677154800000001 * fTemp34))));
			double fTemp161 = (fConst48 * fRec303[1]);
			double fTemp162 = (fConst49 * fRec306[1]);
			fRec308[0] = (fTemp160 + (fTemp161 + (fRec308[1] + fTemp162)));
			fRec306[0] = fRec308[0];
			double fRec307 = ((fTemp162 + fTemp161) + fTemp160);
			fRec305[0] = (fRec306[0] + fRec305[1]);
			fRec303[0] = fRec305[0];
			double fRec304 = fRec307;
			fRec302[0] = (fTemp158 + (fTemp159 + (fRec304 + fRec302[1])));
			fRec300[0] = fRec302[0];
			double fRec301 = (fTemp158 + (fRec304 + fTemp159));
			fRec299[0] = (fRec300[0] + fRec299[1]);
			fRec297[0] = fRec299[0];
			double fRec298 = fRec301;
			fVec5[(IOTA & 127)] = ((0.0148720972 * fTemp7) + (fRec265 + (fRec271 + (fRec274 + (fRec289 + fRec298)))));
			output5[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec5[((IOTA - iConst63) & 127)])));
			double fTemp163 = (fConst35 * fRec309[1]);
			double fTemp164 = (fConst37 * fRec312[1]);
			double fTemp165 = (fConst38 * fRec315[1]);
			double fTemp166 = (fConst40 * ((((0.046266294999999999 * fTemp14) + (0.060477216299999997 * fTemp18)) + (0.043826655700000001 * fTemp20)) - ((((((((0.0299252224 * fTemp11) + (0.0547572105 * fTemp12)) + (0.018137263099999999 * fTemp16)) + (0.030689946499999999 * fTemp17)) + (0.0104456286 * fTemp13)) + (0.0050640388999999997 * fTemp15)) + (0.024272888699999998 * fTemp19)) + (0.085945946800000006 * fTemp21))));
			double fTemp167 = (fConst41 * fRec318[1]);
			double fTemp168 = (fConst42 * fRec321[1]);
			fRec323[0] = (fTemp166 + (fTemp167 + (fRec323[1] + fTemp168)));
			fRec321[0] = fRec323[0];
			double fRec322 = ((fTemp168 + fTemp167) + fTemp166);
			fRec320[0] = (fRec321[0] + fRec320[1]);
			fRec318[0] = fRec320[0];
			double fRec319 = fRec322;
			fRec317[0] = (fTemp164 + (fTemp165 + (fRec319 + fRec317[1])));
			fRec315[0] = fRec317[0];
			double fRec316 = (fTemp164 + (fRec319 + fTemp165));
			fRec314[0] = (fRec315[0] + fRec314[1]);
			fRec312[0] = fRec314[0];
			double fRec313 = fRec316;
			fRec311[0] = (fTemp163 + (fRec313 + fRec311[1]));
			fRec309[0] = fRec311[0];
			double fRec310 = (fRec313 + fTemp163);
			double fTemp169 = (fConst44 * fRec324[1]);
			double fTemp170 = (fConst45 * fRec327[1]);
			double fTemp171 = (fConst47 * (((0.051192006700000001 * fTemp35) + ((0.040089391299999999 * fTemp34) + ((0.0332188452 * fTemp33) + ((0.014860421 * fTemp32) + (((0.051056363799999997 * fTemp28) + (0.063915328499999993 * fTemp31)) + (0.0198919441 * fTemp29)))))) - ((0.076380795400000007 * fTemp27) + (0.021058597599999999 * fTemp30))));
			double fTemp172 = (fConst48 * fRec330[1]);
			double fTemp173 = (fConst49 * fRec333[1]);
			fRec335[0] = (fTemp171 + (fTemp172 + (fRec335[1] + fTemp173)));
			fRec333[0] = fRec335[0];
			double fRec334 = ((fTemp173 + fTemp172) + fTemp171);
			fRec332[0] = (fRec333[0] + fRec332[1]);
			fRec330[0] = fRec332[0];
			double fRec331 = fRec334;
			fRec329[0] = (fTemp169 + (fTemp170 + (fRec331 + fRec329[1])));
			fRec327[0] = fRec329[0];
			double fRec328 = (fTemp169 + (fRec331 + fTemp170));
			fRec326[0] = (fRec327[0] + fRec326[1]);
			fRec324[0] = fRec326[0];
			double fRec325 = fRec328;
			double fTemp174 = (fConst51 * fRec336[1]);
			double fTemp175 = (fConst53 * ((((((0.065106436899999995 * fTemp40) + (0.023147146699999999 * fTemp41)) + (0.045924851199999998 * fTemp43)) + (0.0123815399 * fTemp45)) + (0.058187098499999999 * fTemp46)) - ((0.039861520099999999 * fTemp44) + (0.049196949800000001 * fTemp42))));
			double fTemp176 = (fConst54 * fRec339[1]);
			double fTemp177 = (fConst55 * fRec342[1]);
			fRec344[0] = (fTemp175 + (fTemp176 + (fRec344[1] + fTemp177)));
			fRec342[0] = fRec344[0];
			double fRec343 = ((fTemp177 + fTemp176) + fTemp175);
			fRec341[0] = (fRec342[0] + fRec341[1]);
			fRec339[0] = fRec341[0];
			double fRec340 = fRec343;
			fRec338[0] = (fTemp174 + (fRec340 + fRec338[1]));
			fRec336[0] = fRec338[0];
			double fRec337 = (fRec340 + fTemp174);
			double fTemp178 = (fConst57 * ((0.014918545300000001 * fTemp51) - ((0.055779355500000002 * fTemp50) + (0.0136150345 * fTemp52))));
			double fTemp179 = (fConst58 * fRec345[1]);
			fRec347[0] = (fTemp178 + (fRec347[1] + fTemp179));
			fRec345[0] = fRec347[0];
			double fRec346 = (fTemp179 + fTemp178);
			double fTemp180 = (fConst60 * ((0.035331008300000001 * fTemp55) - ((((0.038305967500000003 * fTemp56) + (0.037373407400000003 * fTemp59)) + (0.0084833896000000002 * fTemp57)) + (0.0674619682 * fTemp58))));
			double fTemp181 = (fConst61 * fRec348[1]);
			double fTemp182 = (fConst62 * fRec351[1]);
			fRec353[0] = (fTemp180 + (fTemp181 + (fRec353[1] + fTemp182)));
			fRec351[0] = fRec353[0];
			double fRec352 = ((fTemp182 + fTemp181) + fTemp180);
			fRec350[0] = (fRec351[0] + fRec350[1]);
			fRec348[0] = fRec350[0];
			double fRec349 = fRec352;
			fVec6[(IOTA & 127)] = ((0.020334412400000001 * fTemp7) + (fRec310 + (fRec325 + (fRec337 + (fRec346 + fRec349)))));
			output6[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec6[((IOTA - iConst63) & 127)])));
			double fTemp183 = (fConst65 * fRec354[1]);
			double fTemp184 = (fConst67 * fRec357[1]);
			double fTemp185 = (fConst68 * fRec360[1]);
			double fTemp186 = (fConst70 * ((((((0.078365057599999996 * fTemp11) + (0.016469102999999999 * fTemp16)) + (0.034664118399999999 * fTemp14)) + (0.014030683800000001 * fTemp18)) + (0.0079017691000000008 * fTemp21)) - ((0.038600158199999998 * fTemp20) + (((((0.026523832600000002 * fTemp12) + (0.046873431 * fTemp17)) + (0.023311165299999999 * fTemp13)) + (0.018617883299999999 * fTemp15)) + (0.036838917999999998 * fTemp19)))));
			double fTemp187 = (fConst71 * fRec363[1]);
			double fTemp188 = (fConst72 * fRec366[1]);
			fRec368[0] = (fTemp186 + (fTemp187 + (fRec368[1] + fTemp188)));
			fRec366[0] = fRec368[0];
			double fRec367 = ((fTemp188 + fTemp187) + fTemp186);
			fRec365[0] = (fRec366[0] + fRec365[1]);
			fRec363[0] = fRec365[0];
			double fRec364 = fRec367;
			fRec362[0] = (fTemp184 + (fTemp185 + (fRec364 + fRec362[1])));
			fRec360[0] = fRec362[0];
			double fRec361 = (fTemp184 + (fRec364 + fTemp185));
			fRec359[0] = (fRec360[0] + fRec359[1]);
			fRec357[0] = fRec359[0];
			double fRec358 = fRec361;
			fRec356[0] = (fTemp183 + (fRec358 + fRec356[1]));
			fRec354[0] = fRec356[0];
			double fRec355 = (fRec358 + fTemp183);
			double fTemp189 = (fConst74 * fRec369[1]);
			double fTemp190 = (fConst75 * fRec372[1]);
			double fTemp191 = (fConst77 * (((0.038409235399999998 * fTemp34) + ((0.011077795 * fTemp33) + ((0.0257042837 * fTemp32) + ((0.034674740900000001 * fTemp31) + (0.026766206800000001 * fTemp29))))) - ((((0.039800237299999999 * fTemp27) + (0.013292439499999999 * fTemp28)) + (0.042654017900000001 * fTemp30)) + (0.065025436399999997 * fTemp35))));
			double fTemp192 = (fConst78 * fRec375[1]);
			double fTemp193 = (fConst79 * fRec378[1]);
			fRec380[0] = (fTemp191 + (fTemp192 + (fRec380[1] + fTemp193)));
			fRec378[0] = fRec380[0];
			double fRec379 = ((fTemp193 + fTemp192) + fTemp191);
			fRec377[0] = (fRec378[0] + fRec377[1]);
			fRec375[0] = fRec377[0];
			double fRec376 = fRec379;
			fRec374[0] = (fTemp189 + (fTemp190 + (fRec376 + fRec374[1])));
			fRec372[0] = fRec374[0];
			double fRec373 = (fTemp189 + (fRec376 + fTemp190));
			fRec371[0] = (fRec372[0] + fRec371[1]);
			fRec369[0] = fRec371[0];
			double fRec370 = fRec373;
			double fTemp194 = (fConst81 * fRec381[1]);
			double fTemp195 = (fConst83 * (((((0.030790350300000002 * fTemp41) + (0.0360911441 * fTemp43)) + (0.0276617423 * fTemp45)) + (0.064907633800000003 * fTemp46)) - (((0.025348098499999999 * fTemp40) + (0.024186315999999999 * fTemp44)) + (0.0096018156000000007 * fTemp42))));
			double fTemp196 = (fConst84 * fRec384[1]);
			double fTemp197 = (fConst85 * fRec387[1]);
			fRec389[0] = (fTemp195 + (fTemp196 + (fRec389[1] + fTemp197)));
			fRec387[0] = fRec389[0];
			double fRec388 = ((fTemp197 + fTemp196) + fTemp195);
			fRec386[0] = (fRec387[0] + fRec386[1]);
			fRec384[0] = fRec386[0];
			double fRec385 = fRec388;
			fRec383[0] = (fTemp194 + (fRec385 + fRec383[1]));
			fRec381[0] = fRec383[0];
			double fRec382 = (fRec385 + fTemp194);
			double fTemp198 = (fConst87 * ((0.0081851201999999998 * fTemp51) - ((0.034363525800000003 * fTemp50) + (0.025948127299999998 * fTemp52))));
			double fTemp199 = (fConst88 * fRec390[1]);
			fRec392[0] = (fTemp198 + (fRec392[1] + fTemp199));
			fRec390[0] = fRec392[0];
			double fRec391 = (fTemp199 + fTemp198);
			double fTemp200 = (fConst90 * ((0.056536760899999997 * fTemp55) - ((((0.017946540300000001 * fTemp56) + (0.031241391699999999 * fTemp59)) + (0.013186598500000001 * fTemp57)) + (0.016029248199999999 * fTemp58))));
			double fTemp201 = (fConst91 * fRec393[1]);
			double fTemp202 = (fConst92 * fRec396[1]);
			fRec398[0] = (fTemp200 + (fTemp201 + (fRec398[1] + fTemp202)));
			fRec396[0] = fRec398[0];
			double fRec397 = ((fTemp202 + fTemp201) + fTemp200);
			fRec395[0] = (fRec396[0] + fRec395[1]);
			fRec393[0] = fRec395[0];
			double fRec394 = fRec397;
			fVec7[(IOTA & 127)] = ((0.0149042737 * fTemp7) + (fRec355 + (fRec370 + (fRec382 + (fRec391 + fRec394)))));
			output7[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec7[((IOTA - iConst93) & 127)])));
			double fTemp203 = (fConst4 * fRec399[1]);
			double fTemp204 = (fConst7 * fRec402[1]);
			double fTemp205 = (fConst8 * fRec405[1]);
			double fTemp206 = (fConst10 * ((((((0.054824273200000002 * fTemp12) + (0.029798077999999999 * fTemp16)) + (0.046192445800000002 * fTemp14)) + (0.0043782910999999999 * fTemp19)) + (0.081796242800000002 * fTemp21)) - (((0.030694920800000001 * fTemp18) + ((((0.0397107695 * fTemp11) + (0.060395179200000003 * fTemp17)) + (0.003692084 * fTemp13)) + (0.0107898712 * fTemp15))) + (0.043762866499999997 * fTemp20))));
			double fTemp207 = (fConst11 * fRec408[1]);
			double fTemp208 = (fConst12 * fRec411[1]);
			fRec413[0] = (fTemp206 + (fTemp207 + (fRec413[1] + fTemp208)));
			fRec411[0] = fRec413[0];
			double fRec412 = ((fTemp208 + fTemp207) + fTemp206);
			fRec410[0] = (fRec411[0] + fRec410[1]);
			fRec408[0] = fRec410[0];
			double fRec409 = fRec412;
			fRec407[0] = (fTemp204 + (fTemp205 + (fRec409 + fRec407[1])));
			fRec405[0] = fRec407[0];
			double fRec406 = (fTemp204 + (fRec409 + fTemp205));
			fRec404[0] = (fRec405[0] + fRec404[1]);
			fRec402[0] = fRec404[0];
			double fRec403 = fRec406;
			fRec401[0] = (fTemp203 + (fRec403 + fRec401[1]));
			fRec399[0] = fRec401[0];
			double fRec400 = (fRec403 + fTemp203);
			double fTemp209 = (fConst14 * fRec414[1]);
			double fTemp210 = (fConst15 * fRec417[1]);
			double fTemp211 = (fConst17 * ((((0.055673970599999997 * fTemp32) + (((0.076344546200000002 * fTemp27) + (0.034645651999999999 * fTemp31)) + (0.019746962999999999 * fTemp29))) + (0.0076935431999999998 * fTemp34)) - ((((0.064461201600000004 * fTemp28) + (0.033036260300000002 * fTemp30)) + (0.020991414600000001 * fTemp33)) + (0.051025525299999999 * fTemp35))));
			double fTemp212 = (fConst18 * fRec420[1]);
			double fTemp213 = (fConst19 * fRec423[1]);
			fRec425[0] = (fTemp211 + (fTemp212 + (fRec425[1] + fTemp213)));
			fRec423[0] = fRec425[0];
			double fRec424 = ((fTemp213 + fTemp212) + fTemp211);
			fRec422[0] = (fRec423[0] + fRec422[1]);
			fRec420[0] = fRec422[0];
			double fRec421 = fRec424;
			fRec419[0] = (fTemp209 + (fTemp210 + (fRec421 + fRec419[1])));
			fRec417[0] = fRec419[0];
			double fRec418 = (fTemp209 + (fRec421 + fTemp210));
			fRec416[0] = (fRec417[0] + fRec416[1]);
			fRec414[0] = fRec416[0];
			double fRec415 = fRec418;
			double fTemp214 = (fConst21 * fRec426[1]);
			double fTemp215 = (fConst23 * (((0.0048022951000000003 * fTemp46) + ((0.023179443500000001 * fTemp42) + (((0.049185379100000003 * fTemp41) + (0.0236157169 * fTemp43)) + (0.0410878561 * fTemp45)))) - ((0.087046728399999995 * fTemp40) + (0.039849832500000001 * fTemp44))));
			double fTemp216 = (fConst24 * fRec429[1]);
			double fTemp217 = (fConst25 * fRec432[1]);
			fRec434[0] = (fTemp215 + (fTemp216 + (fRec434[1] + fTemp217)));
			fRec432[0] = fRec434[0];
			double fRec433 = ((fTemp217 + fTemp216) + fTemp215);
			fRec431[0] = (fRec432[0] + fRec431[1]);
			fRec429[0] = fRec431[0];
			double fRec430 = fRec433;
			fRec428[0] = (fTemp214 + (fRec430 + fRec428[1]));
			fRec426[0] = fRec428[0];
			double fRec427 = (fRec430 + fTemp214);
			double fTemp218 = (fConst27 * ((0.0149227358 * fTemp51) - ((0.029748477400000001 * fTemp50) + (0.048993963699999997 * fTemp52))));
			double fTemp219 = (fConst28 * fRec435[1]);
			fRec437[0] = (fTemp218 + (fRec437[1] + fTemp219));
			fRec435[0] = fRec437[0];
			double fRec436 = (fTemp219 + fTemp218);
			double fTemp220 = (fConst30 * (((0.067324036099999998 * fTemp55) + (0.035312055600000003 * fTemp58)) - (((0.0210804279 * fTemp56) + (0.0372758714 * fTemp59)) + (0.033096336300000001 * fTemp57))));
			double fTemp221 = (fConst31 * fRec438[1]);
			double fTemp222 = (fConst32 * fRec441[1]);
			fRec443[0] = (fTemp220 + (fTemp221 + (fRec443[1] + fTemp222)));
			fRec441[0] = fRec443[0];
			double fRec442 = ((fTemp222 + fTemp221) + fTemp220);
			fRec440[0] = (fRec441[0] + fRec440[1]);
			fRec438[0] = fRec440[0];
			double fRec439 = fRec442;
			fVec8[(IOTA & 127)] = ((0.0203014626 * fTemp7) + (fRec400 + (fRec415 + (fRec427 + (fRec436 + fRec439)))));
			output8[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec8[((IOTA - iConst33) & 127)])));
			double fTemp223 = (fConst35 * fRec444[1]);
			double fTemp224 = (fConst37 * fRec447[1]);
			double fTemp225 = (fConst38 * fRec450[1]);
			double fTemp226 = (fConst40 * (((0.0385799639 * fTemp20) + ((((0.026439957300000001 * fTemp12) + (0.014376998699999999 * fTemp16)) + (0.034563989599999997 * fTemp14)) + (0.0376880531 * fTemp19))) - (((0.046764931199999998 * fTemp18) + ((((0.049802605100000001 * fTemp11) + (0.013955334600000001 * fTemp17)) + (0.0033124104000000001 * fTemp13)) + (0.029655717500000001 * fTemp15))) + (0.061018189399999999 * fTemp21))));
			double fTemp227 = (fConst41 * fRec453[1]);
			double fTemp228 = (fConst42 * fRec456[1]);
			fRec458[0] = (fTemp226 + (fTemp227 + (fRec458[1] + fTemp228)));
			fRec456[0] = fRec458[0];
			double fRec457 = ((fTemp228 + fTemp227) + fTemp226);
			fRec455[0] = (fRec456[0] + fRec455[1]);
			fRec453[0] = fRec455[0];
			double fRec454 = fRec457;
			fRec452[0] = (fTemp224 + (fTemp225 + (fRec454 + fRec452[1])));
			fRec450[0] = fRec452[0];
			double fRec451 = (fTemp224 + (fRec454 + fTemp225));
			fRec449[0] = (fRec450[0] + fRec449[1]);
			fRec447[0] = fRec449[0];
			double fRec448 = fRec451;
			fRec446[0] = (fTemp223 + (fRec448 + fRec446[1]));
			fRec444[0] = fRec446[0];
			double fRec445 = (fRec448 + fTemp223);
			double fTemp229 = (fConst44 * fRec459[1]);
			double fTemp230 = (fConst45 * fRec462[1]);
			double fTemp231 = (fConst47 * ((((0.042588462399999999 * fTemp32) + (((0.039751654499999997 * fTemp27) + (0.0063091683000000001 * fTemp31)) + (0.026752755400000001 * fTemp29))) + (0.065025200699999994 * fTemp35)) - ((0.0365129098 * fTemp34) + (((0.0176913956 * fTemp28) + (0.0110519412 * fTemp30)) + (0.0426323537 * fTemp33)))));
			double fTemp232 = (fConst48 * fRec465[1]);
			double fTemp233 = (fConst49 * fRec468[1]);
			fRec470[0] = (fTemp231 + (fTemp232 + (fRec470[1] + fTemp233)));
			fRec468[0] = fRec470[0];
			double fRec469 = ((fTemp233 + fTemp232) + fTemp231);
			fRec467[0] = (fRec468[0] + fRec467[1]);
			fRec465[0] = fRec467[0];
			double fRec466 = fRec469;
			fRec464[0] = (fTemp229 + (fTemp230 + (fRec466 + fRec464[1])));
			fRec462[0] = fRec464[0];
			double fRec463 = (fTemp229 + (fRec466 + fTemp230));
			fRec461[0] = (fRec462[0] + fRec461[1]);
			fRec459[0] = fRec461[0];
			double fRec460 = fRec463;
			double fTemp234 = (fConst51 * fRec471[1]);
			double fTemp235 = (fConst53 * (((0.0307363241 * fTemp42) + (((0.0095601817999999995 * fTemp41) + (0.0059447804000000003 * fTemp43)) + (0.0450445976 * fTemp45))) - (((0.027921281199999998 * fTemp40) + (0.0241286036 * fTemp44)) + (0.063797515599999993 * fTemp46))));
			double fTemp236 = (fConst54 * fRec474[1]);
			double fTemp237 = (fConst55 * fRec477[1]);
			fRec479[0] = (fTemp235 + (fTemp236 + (fRec479[1] + fTemp237)));
			fRec477[0] = fRec479[0];
			double fRec478 = ((fTemp237 + fTemp236) + fTemp235);
			fRec476[0] = (fRec477[0] + fRec476[1]);
			fRec474[0] = fRec476[0];
			double fRec475 = fRec478;
			fRec473[0] = (fTemp234 + (fRec475 + fRec473[1]));
			fRec471[0] = fRec473[0];
			double fRec472 = (fRec475 + fTemp234);
			double fTemp238 = (fConst57 * ((0.0081684841999999994 * fTemp51) - ((0.0059353063999999997 * fTemp50) + (0.042609599499999998 * fTemp52))));
			double fTemp239 = (fConst58 * fRec480[1]);
			fRec482[0] = (fTemp238 + (fRec482[1] + fTemp239));
			fRec480[0] = fRec482[0];
			double fRec481 = (fTemp239 + fTemp238);
			double fTemp240 = (fConst60 * (((0.015992447399999998 * fTemp55) + (0.056499036900000001 * fTemp58)) - (((0.0033505019 * fTemp56) + (0.031212528199999999 * fTemp59)) + (0.021970014199999999 * fTemp57))));
			double fTemp241 = (fConst61 * fRec483[1]);
			double fTemp242 = (fConst62 * fRec486[1]);
			fRec488[0] = (fTemp240 + (fTemp241 + (fRec488[1] + fTemp242)));
			fRec486[0] = fRec488[0];
			double fRec487 = ((fTemp242 + fTemp241) + fTemp240);
			fRec485[0] = (fRec486[0] + fRec485[1]);
			fRec483[0] = fRec485[0];
			double fRec484 = fRec487;
			fVec9[(IOTA & 127)] = ((0.014890234299999999 * fTemp7) + (fRec445 + (fRec460 + (fRec472 + (fRec481 + fRec484)))));
			output9[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec9[((IOTA - iConst63) & 127)])));
			double fTemp243 = (fConst35 * fRec489[1]);
			double fTemp244 = (fConst37 * fRec492[1]);
			double fTemp245 = (fConst38 * fRec495[1]);
			double fTemp246 = (fConst40 * (((0.043693265199999998 * fTemp20) + (((0.046285479599999999 * fTemp14) + (((0.085947763799999993 * fTemp11) + (0.0307415446 * fTemp17)) + (0.0050440883999999997 * fTemp13))) + (0.018162974500000002 * fTemp19))) - (((0.060457105599999998 * fTemp18) + (((0.054861647399999998 * fTemp12) + (0.0242158328 * fTemp16)) + (0.0104845211 * fTemp15))) + (0.0298178217 * fTemp21))));
			double fTemp247 = (fConst41 * fRec498[1]);
			double fTemp248 = (fConst42 * fRec501[1]);
			fRec503[0] = (fTemp246 + (fTemp247 + (fRec503[1] + fTemp248)));
			fRec501[0] = fRec503[0];
			double fRec502 = ((fTemp248 + fTemp247) + fTemp246);
			fRec500[0] = (fRec501[0] + fRec500[1]);
			fRec498[0] = fRec500[0];
			double fRec499 = fRec502;
			fRec497[0] = (fTemp244 + (fTemp245 + (fRec499 + fRec497[1])));
			fRec495[0] = fRec497[0];
			double fRec496 = (fTemp244 + (fRec499 + fTemp245));
			fRec494[0] = (fRec495[0] + fRec494[1]);
			fRec492[0] = fRec494[0];
			double fRec493 = fRec496;
			fRec491[0] = (fTemp243 + (fRec493 + fRec491[1]));
			fRec489[0] = fRec491[0];
			double fRec490 = (fRec493 + fTemp243);
			double fTemp249 = (fConst44 * fRec504[1]);
			double fTemp250 = (fConst45 * fRec507[1]);
			double fTemp251 = (fConst47 * ((((0.063884093200000006 * fTemp32) + (((0.040177372000000003 * fTemp28) + (0.021033395100000001 * fTemp30)) + (0.019905962900000001 * fTemp29))) + (0.0510720759 * fTemp35)) - ((0.050950990000000002 * fTemp34) + (((0.076397032700000006 * fTemp27) + (0.0148908033 * fTemp31)) + (0.033221765299999997 * fTemp33)))));
			double fTemp252 = (fConst48 * fRec510[1]);
			double fTemp253 = (fConst49 * fRec513[1]);
			fRec515[0] = (fTemp251 + (fTemp252 + (fRec515[1] + fTemp253)));
			fRec513[0] = fRec515[0];
			double fRec514 = ((fTemp253 + fTemp252) + fTemp251);
			fRec512[0] = (fRec513[0] + fRec512[1]);
			fRec510[0] = fRec512[0];
			double fRec511 = fRec514;
			fRec509[0] = (fTemp249 + (fTemp250 + (fRec511 + fRec509[1])));
			fRec507[0] = fRec509[0];
			double fRec508 = (fTemp249 + (fRec511 + fTemp250));
			fRec506[0] = (fRec507[0] + fRec506[1]);
			fRec504[0] = fRec506[0];
			double fRec505 = fRec508;
			double fTemp254 = (fConst51 * fRec516[1]);
			double fTemp255 = (fConst53 * (((0.049120922300000001 * fTemp42) + ((0.058211639599999997 * fTemp40) + (0.045905278600000002 * fTemp45))) - ((((0.023203534599999999 * fTemp41) + (0.012376945699999999 * fTemp43)) + (0.0398291375 * fTemp44)) + (0.064992922999999994 * fTemp46))));
			double fTemp256 = (fConst54 * fRec519[1]);
			double fTemp257 = (fConst55 * fRec522[1]);
			fRec524[0] = (fTemp255 + (fTemp256 + (fRec524[1] + fTemp257)));
			fRec522[0] = fRec524[0];
			double fRec523 = ((fTemp257 + fTemp256) + fTemp255);
			fRec521[0] = (fRec522[0] + fRec521[1]);
			fRec519[0] = fRec521[0];
			double fRec520 = fRec523;
			fRec518[0] = (fTemp254 + (fRec520 + fRec518[1]));
			fRec516[0] = fRec518[0];
			double fRec517 = (fRec520 + fTemp254);
			double fTemp258 = (fConst57 * (((0.0136255609 * fTemp50) + (0.014898194599999999 * fTemp51)) - (0.0557105013 * fTemp52)));
			double fTemp259 = (fConst58 * fRec525[1]);
			fRec527[0] = (fTemp258 + (fRec527[1] + fTemp259));
			fRec525[0] = fRec527[0];
			double fRec526 = (fTemp259 + fTemp258);
			double fTemp260 = (fConst60 * (((0.0085057102000000006 * fTemp56) + (0.067367399300000005 * fTemp58)) - (((0.035352712600000002 * fTemp55) + (0.037343438999999999 * fTemp59)) + (0.038255028099999998 * fTemp57))));
			double fTemp261 = (fConst61 * fRec528[1]);
			double fTemp262 = (fConst62 * fRec531[1]);
			fRec533[0] = (fTemp260 + (fTemp261 + (fRec533[1] + fTemp262)));
			fRec531[0] = fRec533[0];
			double fRec532 = ((fTemp262 + fTemp261) + fTemp260);
			fRec530[0] = (fRec531[0] + fRec530[1]);
			fRec528[0] = fRec530[0];
			double fRec529 = fRec532;
			fVec10[(IOTA & 127)] = ((0.020309576900000001 * fTemp7) + (fRec490 + (fRec505 + (fRec517 + (fRec526 + fRec529)))));
			output10[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec10[((IOTA - iConst63) & 127)])));
			double fTemp263 = (fConst65 * fRec534[1]);
			double fTemp264 = (fConst67 * fRec537[1]);
			double fTemp265 = (fConst68 * fRec540[1]);
			double fTemp266 = (fConst70 * ((((0.034617807899999999 * fTemp14) + ((0.046833406500000001 * fTemp17) + (0.018666815 * fTemp13))) + (0.078450290800000003 * fTemp21)) - ((0.038624600000000002 * fTemp20) + ((0.0165080438 * fTemp19) + ((0.0139758225 * fTemp18) + ((((0.0079773524999999998 * fTemp11) + (0.026470719100000002 * fTemp12)) + (0.036892242300000003 * fTemp16)) + (0.0233742116 * fTemp15)))))));
			double fTemp267 = (fConst71 * fRec543[1]);
			double fTemp268 = (fConst72 * fRec546[1]);
			fRec548[0] = (fTemp266 + (fTemp267 + (fRec548[1] + fTemp268)));
			fRec546[0] = fRec548[0];
			double fRec547 = ((fTemp268 + fTemp267) + fTemp266);
			fRec545[0] = (fRec546[0] + fRec545[1]);
			fRec543[0] = fRec545[0];
			double fRec544 = fRec547;
			fRec542[0] = (fTemp264 + (fTemp265 + (fRec544 + fRec542[1])));
			fRec540[0] = fRec542[0];
			double fRec541 = (fTemp264 + (fRec544 + fTemp265));
			fRec539[0] = (fRec540[0] + fRec539[1]);
			fRec537[0] = fRec539[0];
			double fRec538 = fRec541;
			fRec536[0] = (fTemp263 + (fRec538 + fRec536[1]));
			fRec534[0] = fRec536[0];
			double fRec535 = (fRec538 + fTemp263);
			double fTemp269 = (fConst74 * fRec549[1]);
			double fTemp270 = (fConst75 * fRec552[1]);
			double fTemp271 = (fConst77 * ((((0.034635150099999998 * fTemp32) + (((0.038386408400000002 * fTemp28) + (0.042730249099999999 * fTemp30)) + (0.026820651899999999 * fTemp29))) + (0.013328174700000001 * fTemp34)) - ((((0.039803916000000002 * fTemp27) + (0.025697066599999999 * fTemp31)) + (0.0110821249 * fTemp33)) + (0.065147456399999998 * fTemp35))));
			double fTemp272 = (fConst78 * fRec555[1]);
			double fTemp273 = (fConst79 * fRec558[1]);
			fRec560[0] = (fTemp271 + (fTemp272 + (fRec560[1] + fTemp273)));
			fRec558[0] = fRec560[0];
			double fRec559 = ((fTemp273 + fTemp272) + fTemp271);
			fRec557[0] = (fRec558[0] + fRec557[1]);
			fRec555[0] = fRec557[0];
			double fRec556 = fRec559;
			fRec554[0] = (fTemp269 + (fTemp270 + (fRec556 + fRec554[1])));
			fRec552[0] = fRec554[0];
			double fRec553 = (fTemp269 + (fRec556 + fTemp270));
			fRec551[0] = (fRec552[0] + fRec551[1]);
			fRec549[0] = fRec551[0];
			double fRec550 = fRec553;
			double fTemp274 = (fConst81 * fRec561[1]);
			double fTemp275 = (fConst83 * (((0.0254303502 * fTemp46) + ((0.0095778079000000006 * fTemp42) + ((0.064990564599999995 * fTemp40) + (0.0361467855 * fTemp45)))) - (((0.030790567000000001 * fTemp41) + (0.0277165373 * fTemp43)) + (0.0241737707 * fTemp44))));
			double fTemp276 = (fConst84 * fRec564[1]);
			double fTemp277 = (fConst85 * fRec567[1]);
			fRec569[0] = (fTemp275 + (fTemp276 + (fRec569[1] + fTemp277)));
			fRec567[0] = fRec569[0];
			double fRec568 = ((fTemp277 + fTemp276) + fTemp275);
			fRec566[0] = (fRec567[0] + fRec566[1]);
			fRec564[0] = fRec566[0];
			double fRec565 = fRec568;
			fRec563[0] = (fTemp274 + (fRec565 + fRec563[1]));
			fRec561[0] = fRec563[0];
			double fRec562 = (fRec565 + fTemp274);
			double fTemp278 = (fConst87 * (((0.0260005299 * fTemp50) + (0.0081851137999999993 * fTemp51)) - (0.0344149469 * fTemp52)));
			double fTemp279 = (fConst88 * fRec570[1]);
			fRec572[0] = (fTemp278 + (fRec572[1] + fTemp279));
			fRec570[0] = fRec572[0];
			double fRec571 = (fTemp279 + fTemp278);
			double fTemp280 = (fConst90 * (((0.013191336099999999 * fTemp56) + (0.0160282884 * fTemp58)) - (((0.056636752499999998 * fTemp55) + (0.031294055600000002 * fTemp59)) + (0.017939345499999999 * fTemp57))));
			double fTemp281 = (fConst91 * fRec573[1]);
			double fTemp282 = (fConst92 * fRec576[1]);
			fRec578[0] = (fTemp280 + (fTemp281 + (fRec578[1] + fTemp282)));
			fRec576[0] = fRec578[0];
			double fRec577 = ((fTemp282 + fTemp281) + fTemp280);
			fRec575[0] = (fRec576[0] + fRec575[1]);
			fRec573[0] = fRec575[0];
			double fRec574 = fRec577;
			fVec11[(IOTA & 127)] = ((0.014929747599999999 * fTemp7) + (fRec535 + (fRec550 + (fRec562 + (fRec571 + fRec574)))));
			output11[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec11[((IOTA - iConst93) & 127)])));
			double fTemp283 = (fConst4 * fRec579[1]);
			double fTemp284 = (fConst7 * fRec582[1]);
			double fTemp285 = (fConst8 * fRec585[1]);
			double fTemp286 = (fConst10 * ((((0.046235044099999997 * fTemp14) + ((((0.054866021700000003 * fTemp12) + (0.0043336894999999997 * fTemp16)) + (0.060424909399999997 * fTemp17)) + (0.0108093331 * fTemp13))) + (0.030729541499999999 * fTemp18)) - ((0.039708803500000001 * fTemp21) + ((0.043707611200000003 * fTemp20) + (((0.081764830600000005 * fTemp11) + (0.0037244634 * fTemp15)) + (0.029814907500000001 * fTemp19))))));
			double fTemp287 = (fConst11 * fRec588[1]);
			double fTemp288 = (fConst12 * fRec591[1]);
			fRec593[0] = (fTemp286 + (fTemp287 + (fRec593[1] + fTemp288)));
			fRec591[0] = fRec593[0];
			double fRec592 = ((fTemp288 + fTemp287) + fTemp286);
			fRec590[0] = (fRec591[0] + fRec590[1]);
			fRec588[0] = fRec590[0];
			double fRec589 = fRec592;
			fRec587[0] = (fTemp284 + (fTemp285 + (fRec589 + fRec587[1])));
			fRec585[0] = fRec587[0];
			double fRec586 = (fTemp284 + (fRec589 + fTemp285));
			fRec584[0] = (fRec585[0] + fRec584[1]);
			fRec582[0] = fRec584[0];
			double fRec583 = fRec586;
			fRec581[0] = (fTemp283 + (fRec583 + fRec581[1]));
			fRec579[0] = fRec581[0];
			double fRec580 = (fRec583 + fTemp283);
			double fTemp289 = (fConst14 * fRec594[1]);
			double fTemp290 = (fConst15 * fRec597[1]);
			double fTemp291 = (fConst17 * (((0.064468053499999997 * fTemp34) + ((0.020981976900000001 * fTemp33) + ((0.0346489985 * fTemp32) + ((((0.076339643299999996 * fTemp27) + (0.0076396624000000003 * fTemp28)) + (0.0330664798 * fTemp30)) + (0.019769641599999999 * fTemp29))))) - ((0.055704387799999998 * fTemp31) + (0.050999174600000002 * fTemp35))));
			double fTemp292 = (fConst18 * fRec600[1]);
			double fTemp293 = (fConst19 * fRec603[1]);
			fRec605[0] = (fTemp291 + (fTemp292 + (fRec605[1] + fTemp293)));
			fRec603[0] = fRec605[0];
			double fRec604 = ((fTemp293 + fTemp292) + fTemp291);
			fRec602[0] = (fRec603[0] + fRec602[1]);
			fRec600[0] = fRec602[0];
			double fRec601 = fRec604;
			fRec599[0] = (fTemp289 + (fTemp290 + (fRec601 + fRec599[1])));
			fRec597[0] = fRec599[0];
			double fRec598 = (fTemp289 + (fRec601 + fTemp290));
			fRec596[0] = (fRec597[0] + fRec596[1]);
			fRec594[0] = fRec596[0];
			double fRec595 = fRec598;
			double fTemp294 = (fConst21 * fRec606[1]);
			double fTemp295 = (fConst23 * ((((0.0047816266 * fTemp40) + (0.023629899100000001 * fTemp45)) + (0.087036247499999997 * fTemp46)) - ((((0.049170050799999997 * fTemp41) + (0.041100110400000001 * fTemp43)) + (0.039856738199999998 * fTemp44)) + (0.023209618200000001 * fTemp42))));
			double fTemp296 = (fConst24 * fRec609[1]);
			double fTemp297 = (fConst25 * fRec612[1]);
			fRec614[0] = (fTemp295 + (fTemp296 + (fRec614[1] + fTemp297)));
			fRec612[0] = fRec614[0];
			double fRec613 = ((fTemp297 + fTemp296) + fTemp295);
			fRec611[0] = (fRec612[0] + fRec611[1]);
			fRec609[0] = fRec611[0];
			double fRec610 = fRec613;
			fRec608[0] = (fTemp294 + (fRec610 + fRec608[1]));
			fRec606[0] = fRec608[0];
			double fRec607 = (fRec610 + fTemp294);
			double fTemp298 = (fConst27 * (((0.048992347899999997 * fTemp50) + (0.014920154 * fTemp51)) - (0.0297393029 * fTemp52)));
			double fTemp299 = (fConst28 * fRec615[1]);
			fRec617[0] = (fTemp298 + (fRec617[1] + fTemp299));
			fRec615[0] = fRec617[0];
			double fRec616 = (fTemp299 + fTemp298);
			double fTemp300 = (fConst30 * ((0.033100803800000002 * fTemp56) - ((((0.0673100326 * fTemp55) + (0.037280832700000002 * fTemp59)) + (0.0210673405 * fTemp57)) + (0.035321888099999997 * fTemp58))));
			double fTemp301 = (fConst31 * fRec618[1]);
			double fTemp302 = (fConst32 * fRec621[1]);
			fRec623[0] = (fTemp300 + (fTemp301 + (fRec623[1] + fTemp302)));
			fRec621[0] = fRec623[0];
			double fRec622 = ((fTemp302 + fTemp301) + fTemp300);
			fRec620[0] = (fRec621[0] + fRec620[1]);
			fRec618[0] = fRec620[0];
			double fRec619 = fRec622;
			fVec12[(IOTA & 127)] = ((0.0202986639 * fTemp7) + (fRec580 + (fRec595 + (fRec607 + (fRec616 + fRec619)))));
			output12[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec12[((IOTA - iConst33) & 127)])));
			double fTemp303 = (fConst35 * fRec624[1]);
			double fTemp304 = (fConst37 * fRec627[1]);
			double fTemp305 = (fConst38 * fRec630[1]);
			double fTemp306 = (fConst40 * (((((((((0.060982469800000001 * fTemp11) + (0.026372141599999999 * fTemp12)) + (0.037784041300000001 * fTemp16)) + (0.0139428833 * fTemp17)) + (0.029800197399999999 * fTemp13)) + (0.034585324399999999 * fTemp14)) + (0.046772838900000002 * fTemp18)) + (0.038534860599999998 * fTemp20)) - (((0.0033443446000000002 * fTemp15) + (0.014450966399999999 * fTemp19)) + (0.049787216699999998 * fTemp21))));
			double fTemp307 = (fConst41 * fRec633[1]);
			double fTemp308 = (fConst42 * fRec636[1]);
			fRec638[0] = (fTemp306 + (fTemp307 + (fRec638[1] + fTemp308)));
			fRec636[0] = fRec638[0];
			double fRec637 = ((fTemp308 + fTemp307) + fTemp306);
			fRec635[0] = (fRec636[0] + fRec635[1]);
			fRec633[0] = fRec635[0];
			double fRec634 = fRec637;
			fRec632[0] = (fTemp304 + (fTemp305 + (fRec634 + fRec632[1])));
			fRec630[0] = fRec632[0];
			double fRec631 = (fTemp304 + (fRec634 + fTemp305));
			fRec629[0] = (fRec630[0] + fRec629[1]);
			fRec627[0] = fRec629[0];
			double fRec628 = fRec631;
			fRec626[0] = (fTemp303 + (fRec628 + fRec626[1]));
			fRec624[0] = fRec626[0];
			double fRec625 = (fRec628 + fTemp303);
			double fTemp309 = (fConst44 * fRec639[1]);
			double fTemp310 = (fConst45 * fRec642[1]);
			double fTemp311 = (fConst47 * (((0.065008824800000004 * fTemp35) + ((0.017642417000000001 * fTemp34) + ((0.042724883399999997 * fTemp33) + ((0.0062987227999999999 * fTemp32) + (((0.0397471904 * fTemp27) + (0.011092876999999999 * fTemp30)) + (0.026837870699999999 * fTemp29)))))) - ((0.036461632500000001 * fTemp28) + (0.042567339799999999 * fTemp31))));
			double fTemp312 = (fConst48 * fRec645[1]);
			double fTemp313 = (fConst49 * fRec648[1]);
			fRec650[0] = (fTemp311 + (fTemp312 + (fRec650[1] + fTemp313)));
			fRec648[0] = fRec650[0];
			double fRec649 = ((fTemp313 + fTemp312) + fTemp311);
			fRec647[0] = (fRec648[0] + fRec647[1]);
			fRec645[0] = fRec647[0];
			double fRec646 = fRec649;
			fRec644[0] = (fTemp309 + (fTemp310 + (fRec646 + fRec644[1])));
			fRec642[0] = fRec644[0];
			double fRec643 = (fTemp309 + (fRec646 + fTemp310));
			fRec641[0] = (fRec642[0] + fRec641[1]);
			fRec639[0] = fRec641[0];
			double fRec640 = fRec643;
			double fTemp314 = (fConst51 * fRec651[1]);
			double fTemp315 = (fConst53 * (((0.0059588126000000002 * fTemp45) + (0.0279206535 * fTemp46)) - (((((0.063793979099999995 * fTemp40) + (0.0095313327000000007 * fTemp41)) + (0.045114823999999998 * fTemp43)) + (0.024099450599999999 * fTemp44)) + (0.0306850291 * fTemp42))));
			double fTemp316 = (fConst54 * fRec654[1]);
			double fTemp317 = (fConst55 * fRec657[1]);
			fRec659[0] = (fTemp315 + (fTemp316 + (fRec659[1] + fTemp317)));
			fRec657[0] = fRec659[0];
			double fRec658 = ((fTemp317 + fTemp316) + fTemp315);
			fRec656[0] = (fRec657[0] + fRec656[1]);
			fRec654[0] = fRec656[0];
			double fRec655 = fRec658;
			fRec653[0] = (fTemp314 + (fRec655 + fRec653[1]));
			fRec651[0] = fRec653[0];
			double fRec652 = (fRec655 + fTemp314);
			double fTemp318 = (fConst57 * (((0.042609770999999998 * fTemp50) + (0.0081499260999999996 * fTemp51)) - (0.0059345589999999998 * fTemp52)));
			double fTemp319 = (fConst58 * fRec660[1]);
			fRec662[0] = (fTemp318 + (fRec662[1] + fTemp319));
			fRec660[0] = fRec662[0];
			double fRec661 = (fTemp319 + fTemp318);
			double fTemp320 = (fConst60 * ((0.021926979799999999 * fTemp56) - ((((0.0159919728 * fTemp55) + (0.031238016100000002 * fTemp59)) + (0.0033394117999999999 * fTemp57)) + (0.056500430800000001 * fTemp58))));
			double fTemp321 = (fConst61 * fRec663[1]);
			double fTemp322 = (fConst62 * fRec666[1]);
			fRec668[0] = (fTemp320 + (fTemp321 + (fRec668[1] + fTemp322)));
			fRec666[0] = fRec668[0];
			double fRec667 = ((fTemp322 + fTemp321) + fTemp320);
			fRec665[0] = (fRec666[0] + fRec665[1]);
			fRec663[0] = fRec665[0];
			double fRec664 = fRec667;
			fVec13[(IOTA & 127)] = ((0.014888663200000001 * fTemp7) + (fRec625 + (fRec640 + (fRec652 + (fRec661 + fRec664)))));
			output13[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec13[((IOTA - iConst63) & 127)])));
			double fTemp323 = (fConst35 * fRec669[1]);
			double fTemp324 = (fConst37 * fRec672[1]);
			double fTemp325 = (fConst38 * fRec675[1]);
			double fTemp326 = (fConst40 * (((0.085893332599999997 * fTemp21) + ((0.043782375599999999 * fTemp20) + ((0.024174841400000001 * fTemp19) + ((0.060484872500000002 * fTemp18) + ((0.0050236100000000004 * fTemp15) + ((0.046273199700000003 * fTemp14) + (((0.0298884063 * fTemp11) + (0.0181184073 * fTemp16)) + (0.0103732596 * fTemp13)))))))) - ((0.0548174466 * fTemp12) + (0.030702162500000001 * fTemp17))));
			double fTemp327 = (fConst41 * fRec678[1]);
			double fTemp328 = (fConst42 * fRec681[1]);
			fRec683[0] = (fTemp326 + (fTemp327 + (fRec683[1] + fTemp328)));
			fRec681[0] = fRec683[0];
			double fRec682 = ((fTemp328 + fTemp327) + fTemp326);
			fRec680[0] = (fRec681[0] + fRec680[1]);
			fRec678[0] = fRec680[0];
			double fRec679 = fRec682;
			fRec677[0] = (fTemp324 + (fTemp325 + (fRec679 + fRec677[1])));
			fRec675[0] = fRec677[0];
			double fRec676 = (fTemp324 + (fRec679 + fTemp325));
			fRec674[0] = (fRec675[0] + fRec674[1]);
			fRec672[0] = fRec674[0];
			double fRec673 = fRec676;
			fRec671[0] = (fTemp323 + (fRec673 + fRec671[1]));
			fRec669[0] = fRec671[0];
			double fRec670 = (fRec673 + fTemp323);
			double fTemp329 = (fConst44 * fRec684[1]);
			double fTemp330 = (fConst45 * fRec687[1]);
			double fTemp331 = (fConst47 * ((((0.0198317639 * fTemp29) + (0.033158545800000001 * fTemp33)) + (0.051132112399999999 * fTemp35)) - ((((((0.076327265599999999 * fTemp27) + (0.0510348204 * fTemp28)) + (0.020991891499999998 * fTemp30)) + (0.063924795199999995 * fTemp31)) + (0.014872882800000001 * fTemp32)) + (0.040142903399999999 * fTemp34))));
			double fTemp332 = (fConst48 * fRec690[1]);
			double fTemp333 = (fConst49 * fRec693[1]);
			fRec695[0] = (fTemp331 + (fTemp332 + (fRec695[1] + fTemp333)));
			fRec693[0] = fRec695[0];
			double fRec694 = ((fTemp333 + fTemp332) + fTemp331);
			fRec692[0] = (fRec693[0] + fRec692[1]);
			fRec690[0] = fRec692[0];
			double fRec691 = fRec694;
			fRec689[0] = (fTemp329 + (fTemp330 + (fRec691 + fRec689[1])));
			fRec687[0] = fRec689[0];
			double fRec688 = (fTemp329 + (fRec691 + fTemp330));
			fRec686[0] = (fRec687[0] + fRec686[1]);
			fRec684[0] = fRec686[0];
			double fRec685 = fRec688;
			double fTemp334 = (fConst51 * fRec696[1]);
			double fTemp335 = (fConst53 * ((0.023183874600000001 * fTemp41) - ((0.058145986699999999 * fTemp46) + (((((0.065032867199999997 * fTemp40) + (0.045848492599999999 * fTemp43)) + (0.039870407599999998 * fTemp44)) + (0.0123535537 * fTemp45)) + (0.049194931800000001 * fTemp42)))));
			double fTemp336 = (fConst54 * fRec699[1]);
			double fTemp337 = (fConst55 * fRec702[1]);
			fRec704[0] = (fTemp335 + (fTemp336 + (fRec704[1] + fTemp337)));
			fRec702[0] = fRec704[0];
			double fRec703 = ((fTemp337 + fTemp336) + fTemp335);
			fRec701[0] = (fRec702[0] + fRec701[1]);
			fRec699[0] = fRec701[0];
			double fRec700 = fRec703;
			fRec698[0] = (fTemp334 + (fRec700 + fRec698[1]));
			fRec696[0] = fRec698[0];
			double fRec697 = (fRec700 + fTemp334);
			double fTemp338 = (fConst57 * (((0.055723472599999997 * fTemp50) + (0.014923150899999999 * fTemp51)) + (0.0136076102 * fTemp52)));
			double fTemp339 = (fConst58 * fRec705[1]);
			fRec707[0] = (fTemp338 + (fRec707[1] + fTemp339));
			fRec705[0] = fRec707[0];
			double fRec706 = (fTemp339 + fTemp338);
			double fTemp340 = (fConst60 * ((((0.0353080598 * fTemp55) + (0.038313705500000003 * fTemp56)) + (0.0084990055999999998 * fTemp57)) - ((0.037324424100000003 * fTemp59) + (0.067389637099999997 * fTemp58))));
			double fTemp341 = (fConst61 * fRec708[1]);
			double fTemp342 = (fConst62 * fRec711[1]);
			fRec713[0] = (fTemp340 + (fTemp341 + (fRec713[1] + fTemp342)));
			fRec711[0] = fRec713[0];
			double fRec712 = ((fTemp342 + fTemp341) + fTemp340);
			fRec710[0] = (fRec711[0] + fRec710[1]);
			fRec708[0] = fRec710[0];
			double fRec709 = fRec712;
			fVec14[(IOTA & 127)] = ((0.020315367599999998 * fTemp7) + (fRec670 + (fRec685 + (fRec697 + (fRec706 + fRec709)))));
			output14[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec14[((IOTA - iConst63) & 127)])));
			double fTemp343 = (fConst65 * fRec714[1]);
			double fTemp344 = (fConst67 * fRec717[1]);
			double fTemp345 = (fConst68 * fRec720[1]);
			double fTemp346 = (fConst70 * (((0.036883176500000003 * fTemp19) + ((0.013963348699999999 * fTemp18) + ((0.018676555899999999 * fTemp15) + ((0.0233780416 * fTemp13) + (0.034613068499999997 * fTemp14))))) - ((0.0080050056999999997 * fTemp21) + (((((0.078366721 * fTemp11) + (0.0264212027 * fTemp12)) + (0.016515296299999999 * fTemp16)) + (0.046822781700000003 * fTemp17)) + (0.038609438699999998 * fTemp20)))));
			double fTemp347 = (fConst71 * fRec723[1]);
			double fTemp348 = (fConst72 * fRec726[1]);
			fRec728[0] = (fTemp346 + (fTemp347 + (fRec728[1] + fTemp348)));
			fRec726[0] = fRec728[0];
			double fRec727 = ((fTemp348 + fTemp347) + fTemp346);
			fRec725[0] = (fRec726[0] + fRec725[1]);
			fRec723[0] = fRec725[0];
			double fRec724 = fRec727;
			fRec722[0] = (fTemp344 + (fTemp345 + (fRec724 + fRec722[1])));
			fRec720[0] = fRec722[0];
			double fRec721 = (fTemp344 + (fRec724 + fTemp345));
			fRec719[0] = (fRec720[0] + fRec719[1]);
			fRec717[0] = fRec719[0];
			double fRec718 = fRec721;
			fRec716[0] = (fTemp343 + (fRec718 + fRec716[1]));
			fRec714[0] = fRec716[0];
			double fRec715 = (fRec718 + fTemp343);
			double fTemp349 = (fConst74 * fRec729[1]);
			double fTemp350 = (fConst75 * fRec732[1]);
			double fTemp351 = (fConst77 * ((((0.0133293988 * fTemp28) + (0.026810290699999999 * fTemp29)) + (0.011067599500000001 * fTemp33)) - ((0.065078030499999995 * fTemp35) + (((((0.039726134500000003 * fTemp27) + (0.0427061522 * fTemp30)) + (0.034600779800000002 * fTemp31)) + (0.025677240600000002 * fTemp32)) + (0.038329681499999997 * fTemp34)))));
			double fTemp352 = (fConst78 * fRec735[1]);
			double fTemp353 = (fConst79 * fRec738[1]);
			fRec740[0] = (fTemp351 + (fTemp352 + (fRec740[1] + fTemp353)));
			fRec738[0] = fRec740[0];
			double fRec739 = ((fTemp353 + fTemp352) + fTemp351);
			fRec737[0] = (fRec738[0] + fRec737[1]);
			fRec735[0] = fRec737[0];
			double fRec736 = fRec739;
			fRec734[0] = (fTemp349 + (fTemp350 + (fRec736 + fRec734[1])));
			fRec732[0] = fRec734[0];
			double fRec733 = (fTemp349 + (fRec736 + fTemp350));
			fRec731[0] = (fRec732[0] + fRec731[1]);
			fRec729[0] = fRec731[0];
			double fRec730 = fRec733;
			double fTemp354 = (fConst81 * fRec741[1]);
			double fTemp355 = (fConst83 * (((0.025411027700000002 * fTemp40) + (0.030741221400000001 * fTemp41)) - ((0.0648815482 * fTemp46) + ((((0.036105198599999999 * fTemp43) + (0.024137626499999999 * fTemp44)) + (0.027690037800000001 * fTemp45)) + (0.0095517760999999993 * fTemp42)))));
			double fTemp356 = (fConst84 * fRec744[1]);
			double fTemp357 = (fConst85 * fRec747[1]);
			fRec749[0] = (fTemp355 + (fTemp356 + (fRec749[1] + fTemp357)));
			fRec747[0] = fRec749[0];
			double fRec748 = ((fTemp357 + fTemp356) + fTemp355);
			fRec746[0] = (fRec747[0] + fRec746[1]);
			fRec744[0] = fRec746[0];
			double fRec745 = fRec748;
			fRec743[0] = (fTemp354 + (fRec745 + fRec743[1]));
			fRec741[0] = fRec743[0];
			double fRec742 = (fRec745 + fTemp354);
			double fTemp358 = (fConst87 * (((0.034346033800000002 * fTemp50) + (0.0081661475000000001 * fTemp51)) + (0.025954395000000002 * fTemp52)));
			double fTemp359 = (fConst88 * fRec750[1]);
			fRec752[0] = (fTemp358 + (fRec752[1] + fTemp359));
			fRec750[0] = fRec752[0];
			double fRec751 = (fTemp359 + fTemp358);
			double fTemp360 = (fConst90 * ((((0.056540471500000002 * fTemp55) + (0.017900681700000001 * fTemp56)) + (0.0131673502 * fTemp57)) - ((0.031246581999999998 * fTemp59) + (0.015987934400000001 * fTemp58))));
			double fTemp361 = (fConst91 * fRec753[1]);
			double fTemp362 = (fConst92 * fRec756[1]);
			fRec758[0] = (fTemp360 + (fTemp361 + (fRec758[1] + fTemp362)));
			fRec756[0] = fRec758[0];
			double fRec757 = ((fTemp362 + fTemp361) + fTemp360);
			fRec755[0] = (fRec756[0] + fRec755[1]);
			fRec753[0] = fRec755[0];
			double fRec754 = fRec757;
			fVec15[(IOTA & 127)] = ((0.0148994292 * fTemp7) + (fRec715 + (fRec730 + (fRec742 + (fRec751 + fRec754)))));
			output15[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec15[((IOTA - iConst93) & 127)])));
			double fTemp363 = (fConst95 * fRec759[1]);
			double fTemp364 = (fConst97 * fRec762[1]);
			double fTemp365 = (fConst98 * fRec765[1]);
			double fTemp366 = (fConst100 * (((0.030090476200000001 * fTemp17) + (0.0063944604000000004 * fTemp21)) - ((0.0475368101 * fTemp20) + ((0.11497858919999999 * fTemp19) + ((0.0418104989 * fTemp18) + ((0.046797434800000003 * fTemp15) + (((((0.0258053026 * fTemp11) + (0.064942065300000004 * fTemp12)) + (0.0074006324999999996 * fTemp16)) + (0.065501180800000003 * fTemp13)) + (0.0497667574 * fTemp14))))))));
			double fTemp367 = (fConst101 * fRec768[1]);
			double fTemp368 = (fConst102 * fRec771[1]);
			fRec773[0] = (fTemp366 + (fTemp367 + (fRec773[1] + fTemp368)));
			fRec771[0] = fRec773[0];
			double fRec772 = ((fTemp368 + fTemp367) + fTemp366);
			fRec770[0] = (fRec771[0] + fRec770[1]);
			fRec768[0] = fRec770[0];
			double fRec769 = fRec772;
			fRec767[0] = (fTemp364 + (fTemp365 + (fRec769 + fRec767[1])));
			fRec765[0] = fRec767[0];
			double fRec766 = (fTemp364 + (fRec769 + fTemp365));
			fRec764[0] = (fRec765[0] + fRec764[1]);
			fRec762[0] = fRec764[0];
			double fRec763 = fRec766;
			fRec761[0] = (fTemp363 + (fRec763 + fRec761[1]));
			fRec759[0] = fRec761[0];
			double fRec760 = (fRec763 + fTemp363);
			double fTemp369 = (fConst104 * fRec774[1]);
			double fTemp370 = (fConst105 * fRec777[1]);
			double fTemp371 = (fConst107 * ((((0.0041447818000000004 * fTemp28) + (0.1048635136 * fTemp30)) + (0.0042336205000000002 * fTemp31)) - ((0.028000909000000001 * fTemp35) + ((0.1145065529 * fTemp34) + ((0.073002388500000001 * fTemp33) + (((0.033978180400000002 * fTemp27) + (0.087137983000000002 * fTemp29)) + (0.010158956300000001 * fTemp32)))))));
			double fTemp372 = (fConst108 * fRec780[1]);
			double fTemp373 = (fConst109 * fRec783[1]);
			fRec785[0] = (fTemp371 + (fTemp372 + (fRec785[1] + fTemp373)));
			fRec783[0] = fRec785[0];
			double fRec784 = ((fTemp373 + fTemp372) + fTemp371);
			fRec782[0] = (fRec783[0] + fRec782[1]);
			fRec780[0] = fRec782[0];
			double fRec781 = fRec784;
			fRec779[0] = (fTemp369 + (fTemp370 + (fRec781 + fRec779[1])));
			fRec777[0] = fRec779[0];
			double fRec778 = (fTemp369 + (fRec781 + fTemp370));
			fRec776[0] = (fRec777[0] + fRec776[1]);
			fRec774[0] = fRec776[0];
			double fRec775 = fRec778;
			double fTemp374 = (fConst111 * fRec786[1]);
			double fTemp375 = (fConst113 * (((((0.0052889347999999997 * fTemp40) + (0.1202940882 * fTemp41)) + (0.093574874200000005 * fTemp43)) + (0.045274177899999997 * fTemp45)) - ((0.062968760900000004 * fTemp46) + ((0.054973781899999997 * fTemp44) + (0.0702121629 * fTemp42)))));
			double fTemp376 = (fConst114 * fRec789[1]);
			double fTemp377 = (fConst115 * fRec792[1]);
			fRec794[0] = (fTemp375 + (fTemp376 + (fRec794[1] + fTemp377)));
			fRec792[0] = fRec794[0];
			double fRec793 = ((fTemp377 + fTemp376) + fTemp375);
			fRec791[0] = (fRec792[0] + fRec791[1]);
			fRec789[0] = fRec791[0];
			double fRec790 = fRec793;
			fRec788[0] = (fTemp374 + (fRec790 + fRec788[1]));
			fRec786[0] = fRec788[0];
			double fRec787 = (fRec790 + fTemp374);
			double fTemp378 = (fConst117 * (((0.070419014000000002 * fTemp50) + (0.071391873699999997 * fTemp51)) + (0.040731515199999999 * fTemp52)));
			double fTemp379 = (fConst118 * fRec795[1]);
			fRec797[0] = (fTemp378 + (fRec797[1] + fTemp379));
			fRec795[0] = fRec797[0];
			double fRec796 = (fTemp379 + fTemp378);
			double fTemp380 = (fConst120 * (((((0.069363888799999995 * fTemp55) + (0.12224572190000001 * fTemp56)) + (0.024018279199999999 * fTemp59)) + (0.067786083900000002 * fTemp57)) - (0.037380876299999997 * fTemp58)));
			double fTemp381 = (fConst121 * fRec798[1]);
			double fTemp382 = (fConst122 * fRec801[1]);
			fRec803[0] = (fTemp380 + (fTemp381 + (fRec803[1] + fTemp382)));
			fRec801[0] = fRec803[0];
			double fRec802 = ((fTemp382 + fTemp381) + fTemp380);
			fRec800[0] = (fRec801[0] + fRec800[1]);
			fRec798[0] = fRec800[0];
			double fRec799 = fRec802;
			fVec16[(IOTA & 127)] = ((0.038011396400000001 * fTemp7) + (fRec760 + (fRec775 + (fRec787 + (fRec796 + fRec799)))));
			output16[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec16[((IOTA - iConst123) & 127)])));
			double fTemp383 = (fConst95 * fRec804[1]);
			double fTemp384 = (fConst97 * fRec807[1]);
			double fTemp385 = (fConst98 * fRec810[1]);
			double fTemp386 = (fConst100 * (((0.0142086405 * fTemp21) + ((0.049669808699999998 * fTemp20) + ((0.073078142400000004 * fTemp19) + (((((0.0241925087 * fTemp11) + (0.065128708600000002 * fTemp12)) + (0.073652078600000004 * fTemp16)) + (0.016192743400000001 * fTemp17)) + (0.0073126748999999998 * fTemp18))))) - ((0.098391668400000007 * fTemp15) + ((0.022909782199999999 * fTemp13) + (0.028606388699999999 * fTemp14)))));
			double fTemp387 = (fConst101 * fRec813[1]);
			double fTemp388 = (fConst102 * fRec816[1]);
			fRec818[0] = (fTemp386 + (fTemp387 + (fRec818[1] + fTemp388)));
			fRec816[0] = fRec818[0];
			double fRec817 = ((fTemp388 + fTemp387) + fTemp386);
			fRec815[0] = (fRec816[0] + fRec815[1]);
			fRec813[0] = fRec815[0];
			double fRec814 = fRec817;
			fRec812[0] = (fTemp384 + (fTemp385 + (fRec814 + fRec812[1])));
			fRec810[0] = fRec812[0];
			double fRec811 = (fTemp384 + (fRec814 + fTemp385));
			fRec809[0] = (fRec810[0] + fRec809[1]);
			fRec807[0] = fRec809[0];
			double fRec808 = fRec811;
			fRec806[0] = (fTemp383 + (fRec808 + fRec806[1]));
			fRec804[0] = fRec806[0];
			double fRec805 = (fRec808 + fTemp383);
			double fTemp389 = (fConst104 * fRec819[1]);
			double fTemp390 = (fConst105 * fRec822[1]);
			double fTemp391 = (fConst107 * (((0.028821366599999999 * fTemp35) + ((0.082303723699999998 * fTemp34) + ((((0.034112062999999998 * fTemp27) + (0.071048121300000003 * fTemp28)) + (0.052281072900000003 * fTemp30)) + (0.085731005900000004 * fTemp33)))) - (((0.0043342603 * fTemp31) + (0.079673439600000007 * fTemp29)) + (0.036044131799999997 * fTemp32))));
			double fTemp392 = (fConst108 * fRec825[1]);
			double fTemp393 = (fConst109 * fRec828[1]);
			fRec830[0] = (fTemp391 + (fTemp392 + (fRec830[1] + fTemp393)));
			fRec828[0] = fRec830[0];
			double fRec829 = ((fTemp393 + fTemp392) + fTemp391);
			fRec827[0] = (fRec828[0] + fRec827[1]);
			fRec825[0] = fRec827[0];
			double fRec826 = fRec829;
			fRec824[0] = (fTemp389 + (fTemp390 + (fRec826 + fRec824[1])));
			fRec822[0] = fRec824[0];
			double fRec823 = (fTemp389 + (fRec826 + fTemp390));
			fRec821[0] = (fRec822[0] + fRec821[1]);
			fRec819[0] = fRec821[0];
			double fRec820 = fRec823;
			double fTemp394 = (fConst111 * fRec831[1]);
			double fTemp395 = (fConst113 * (((0.047697994600000002 * fTemp46) + ((0.1082953167 * fTemp42) + ((((0.038209709600000002 * fTemp40) + (0.057503765200000001 * fTemp41)) + (0.019567569399999998 * fTemp43)) + (0.064697349799999998 * fTemp45)))) - (0.063294942800000004 * fTemp44)));
			double fTemp396 = (fConst114 * fRec834[1]);
			double fTemp397 = (fConst115 * fRec837[1]);
			fRec839[0] = (fTemp395 + (fTemp396 + (fRec839[1] + fTemp397)));
			fRec837[0] = fRec839[0];
			double fRec838 = ((fTemp397 + fTemp396) + fTemp395);
			fRec836[0] = (fRec837[0] + fRec836[1]);
			fRec834[0] = fRec836[0];
			double fRec835 = fRec838;
			fRec833[0] = (fTemp394 + (fRec835 + fRec833[1]));
			fRec831[0] = fRec833[0];
			double fRec832 = (fRec835 + fTemp394);
			double fTemp398 = (fConst117 * (((0.016552897800000001 * fTemp50) + (0.0533641272 * fTemp51)) + (0.068042738800000002 * fTemp52)));
			double fTemp399 = (fConst118 * fRec840[1]);
			fRec842[0] = (fTemp398 + (fRec842[1] + fTemp399));
			fRec840[0] = fRec842[0];
			double fRec841 = (fTemp399 + fTemp398);
			double fTemp400 = (fConst120 * (((((0.032291960100000003 * fTemp55) + (0.028149608100000001 * fTemp56)) + (0.0055090701000000001 * fTemp59)) + (0.1100413943 * fTemp57)) + (0.064499198699999996 * fTemp58)));
			double fTemp401 = (fConst121 * fRec843[1]);
			double fTemp402 = (fConst122 * fRec846[1]);
			fRec848[0] = (fTemp400 + (fTemp401 + (fRec848[1] + fTemp402)));
			fRec846[0] = fRec848[0];
			double fRec847 = ((fTemp402 + fTemp401) + fTemp400);
			fRec845[0] = (fRec846[0] + fRec845[1]);
			fRec843[0] = fRec845[0];
			double fRec844 = fRec847;
			fVec17[(IOTA & 127)] = ((0.0306211721 * fTemp7) + (fRec805 + (fRec820 + (fRec832 + (fRec841 + fRec844)))));
			output17[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec17[((IOTA - iConst123) & 127)])));
			double fTemp403 = (fConst95 * fRec849[1]);
			double fTemp404 = (fConst97 * fRec852[1]);
			double fTemp405 = (fConst98 * fRec855[1]);
			double fTemp406 = (fConst100 * (((0.0073981732999999997 * fTemp19) + ((0.046806107800000003 * fTemp13) + (0.041825001200000003 * fTemp18))) - ((0.025806042099999999 * fTemp21) + (((0.065490446100000002 * fTemp15) + (((((0.0063845550999999997 * fTemp11) + (0.064948325099999996 * fTemp12)) + (0.1150033816 * fTemp16)) + (0.030129419599999999 * fTemp17)) + (0.049805494899999997 * fTemp14))) + (0.047533985799999998 * fTemp20)))));
			double fTemp407 = (fConst101 * fRec858[1]);
			double fTemp408 = (fConst102 * fRec861[1]);
			fRec863[0] = (fTemp406 + (fTemp407 + (fRec863[1] + fTemp408)));
			fRec861[0] = fRec863[0];
			double fRec862 = ((fTemp408 + fTemp407) + fTemp406);
			fRec860[0] = (fRec861[0] + fRec860[1]);
			fRec858[0] = fRec860[0];
			double fRec859 = fRec862;
			fRec857[0] = (fTemp404 + (fTemp405 + (fRec859 + fRec857[1])));
			fRec855[0] = fRec857[0];
			double fRec856 = (fTemp404 + (fRec859 + fTemp405));
			fRec854[0] = (fRec855[0] + fRec854[1]);
			fRec852[0] = fRec854[0];
			double fRec853 = fRec856;
			fRec851[0] = (fTemp403 + (fRec853 + fRec851[1]));
			fRec849[0] = fRec851[0];
			double fRec850 = (fRec853 + fTemp403);
			double fTemp409 = (fConst104 * fRec864[1]);
			double fTemp410 = (fConst105 * fRec867[1]);
			double fTemp411 = (fConst107 * (((0.0730098208 * fTemp33) + ((0.0101406967 * fTemp31) + (0.00427196 * fTemp32))) - ((0.027996421699999999 * fTemp35) + (((((0.033971424600000001 * fTemp27) + (0.11450058220000001 * fTemp28)) + (0.1048835318 * fTemp30)) + (0.0871444725 * fTemp29)) + (0.0041402097000000004 * fTemp34)))));
			double fTemp412 = (fConst108 * fRec870[1]);
			double fTemp413 = (fConst109 * fRec873[1]);
			fRec875[0] = (fTemp411 + (fTemp412 + (fRec875[1] + fTemp413)));
			fRec873[0] = fRec875[0];
			double fRec874 = ((fTemp413 + fTemp412) + fTemp411);
			fRec872[0] = (fRec873[0] + fRec872[1]);
			fRec870[0] = fRec872[0];
			double fRec871 = fRec874;
			fRec869[0] = (fTemp409 + (fTemp410 + (fRec871 + fRec869[1])));
			fRec867[0] = fRec869[0];
			double fRec868 = (fTemp409 + (fRec871 + fTemp410));
			fRec866[0] = (fRec867[0] + fRec866[1]);
			fRec864[0] = fRec866[0];
			double fRec865 = fRec868;
			double fTemp414 = (fConst111 * fRec876[1]);
			double fTemp415 = (fConst113 * (((0.093594236999999997 * fTemp45) + (0.0702060563 * fTemp42)) - (((((0.062953242500000006 * fTemp40) + (0.120279476 * fTemp41)) + (0.045284256799999999 * fTemp43)) + (0.054949432499999999 * fTemp44)) + (0.0052855645000000001 * fTemp46))));
			double fTemp416 = (fConst114 * fRec879[1]);
			double fTemp417 = (fConst115 * fRec882[1]);
			fRec884[0] = (fTemp415 + (fTemp416 + (fRec884[1] + fTemp417)));
			fRec882[0] = fRec884[0];
			double fRec883 = ((fTemp417 + fTemp416) + fTemp415);
			fRec881[0] = (fRec882[0] + fRec881[1]);
			fRec879[0] = fRec881[0];
			double fRec880 = fRec883;
			fRec878[0] = (fTemp414 + (fRec880 + fRec878[1]));
			fRec876[0] = fRec878[0];
			double fRec877 = (fRec880 + fTemp414);
			double fTemp418 = (fConst117 * (((0.071384467300000004 * fTemp51) + (0.070400406499999998 * fTemp52)) - (0.040719139299999998 * fTemp50)));
			double fTemp419 = (fConst118 * fRec885[1]);
			fRec887[0] = (fTemp418 + (fRec887[1] + fTemp419));
			fRec885[0] = fRec887[0];
			double fRec886 = (fTemp419 + fTemp418);
			double fTemp420 = (fConst120 * ((((0.024035194700000002 * fTemp59) + (0.1222313142 * fTemp57)) + (0.037372044600000001 * fTemp58)) - ((0.069343358699999996 * fTemp55) + (0.067775739400000007 * fTemp56))));
			double fTemp421 = (fConst121 * fRec888[1]);
			double fTemp422 = (fConst122 * fRec891[1]);
			fRec893[0] = (fTemp420 + (fTemp421 + (fRec893[1] + fTemp422)));
			fRec891[0] = fRec893[0];
			double fRec892 = ((fTemp422 + fTemp421) + fTemp420);
			fRec890[0] = (fRec891[0] + fRec890[1]);
			fRec888[0] = fRec890[0];
			double fRec889 = fRec892;
			fVec18[(IOTA & 127)] = ((0.038002752799999998 * fTemp7) + (fRec850 + (fRec865 + (fRec877 + (fRec886 + fRec889)))));
			output18[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec18[((IOTA - iConst123) & 127)])));
			double fTemp423 = (fConst95 * fRec894[1]);
			double fTemp424 = (fConst97 * fRec897[1]);
			double fTemp425 = (fConst98 * fRec900[1]);
			double fTemp426 = (fConst100 * (((0.0242062654 * fTemp21) + ((((0.065107283700000004 * fTemp12) + (0.073068349199999993 * fTemp16)) + (0.098379142500000002 * fTemp13)) + (0.049674152100000001 * fTemp20))) - ((0.0736226933 * fTemp19) + ((0.0072948364999999996 * fTemp18) + ((0.022877380999999999 * fTemp15) + (((0.0141870746 * fTemp11) + (0.016235548999999998 * fTemp17)) + (0.028620153799999999 * fTemp14)))))));
			double fTemp427 = (fConst101 * fRec903[1]);
			double fTemp428 = (fConst102 * fRec906[1]);
			fRec908[0] = (fTemp426 + (fTemp427 + (fRec908[1] + fTemp428)));
			fRec906[0] = fRec908[0];
			double fRec907 = ((fTemp428 + fTemp427) + fTemp426);
			fRec905[0] = (fRec906[0] + fRec905[1]);
			fRec903[0] = fRec905[0];
			double fRec904 = fRec907;
			fRec902[0] = (fTemp424 + (fTemp425 + (fRec904 + fRec902[1])));
			fRec900[0] = fRec902[0];
			double fRec901 = (fTemp424 + (fRec904 + fTemp425));
			fRec899[0] = (fRec900[0] + fRec899[1]);
			fRec897[0] = fRec899[0];
			double fRec898 = fRec901;
			fRec896[0] = (fTemp423 + (fRec898 + fRec896[1]));
			fRec894[0] = fRec896[0];
			double fRec895 = (fRec898 + fTemp423);
			double fTemp429 = (fConst104 * fRec909[1]);
			double fTemp430 = (fConst105 * fRec912[1]);
			double fTemp431 = (fConst107 * (((((0.0341125397 * fTemp27) + (0.082316823499999997 * fTemp28)) + (0.036036336600000003 * fTemp31)) + (0.028822862599999999 * fTemp35)) - ((0.071022644300000007 * fTemp34) + ((0.085731476200000004 * fTemp33) + (((0.0522847148 * fTemp30) + (0.079680596500000006 * fTemp29)) + (0.0043025155000000004 * fTemp32))))));
			double fTemp432 = (fConst108 * fRec915[1]);
			double fTemp433 = (fConst109 * fRec918[1]);
			fRec920[0] = (fTemp431 + (fTemp432 + (fRec920[1] + fTemp433)));
			fRec918[0] = fRec920[0];
			double fRec919 = ((fTemp433 + fTemp432) + fTemp431);
			fRec917[0] = (fRec918[0] + fRec917[1]);
			fRec915[0] = fRec917[0];
			double fRec916 = fRec919;
			fRec914[0] = (fTemp429 + (fTemp430 + (fRec916 + fRec914[1])));
			fRec912[0] = fRec914[0];
			double fRec913 = (fTemp429 + (fRec916 + fTemp430));
			fRec911[0] = (fRec912[0] + fRec911[1]);
			fRec909[0] = fRec911[0];
			double fRec910 = fRec913;
			double fTemp434 = (fConst111 * fRec921[1]);
			double fTemp435 = (fConst113 * (((0.047710902999999999 * fTemp40) + (0.019581777799999998 * fTemp45)) - ((0.038201092999999998 * fTemp46) + ((((0.057491693699999999 * fTemp41) + (0.064715528600000002 * fTemp43)) + (0.063298276000000001 * fTemp44)) + (0.1083150329 * fTemp42)))));
			double fTemp436 = (fConst114 * fRec924[1]);
			double fTemp437 = (fConst115 * fRec927[1]);
			fRec929[0] = (fTemp435 + (fTemp436 + (fRec929[1] + fTemp437)));
			fRec927[0] = fRec929[0];
			double fRec928 = ((fTemp437 + fTemp436) + fTemp435);
			fRec926[0] = (fRec927[0] + fRec926[1]);
			fRec924[0] = fRec926[0];
			double fRec925 = fRec928;
			fRec923[0] = (fTemp434 + (fRec925 + fRec923[1]));
			fRec921[0] = fRec923[0];
			double fRec922 = (fRec925 + fTemp434);
			double fTemp438 = (fConst117 * (((0.053382876199999998 * fTemp51) + (0.016550943200000001 * fTemp52)) - (0.068062192199999996 * fTemp50)));
			double fTemp439 = (fConst118 * fRec930[1]);
			fRec932[0] = (fTemp438 + (fRec932[1] + fTemp439));
			fRec930[0] = fRec932[0];
			double fRec931 = (fTemp439 + fTemp438);
			double fTemp440 = (fConst120 * (((0.0055179063999999996 * fTemp59) + (0.028150457199999999 * fTemp57)) - (((0.032284151099999998 * fTemp55) + (0.1100701746 * fTemp56)) + (0.064516527800000001 * fTemp58))));
			double fTemp441 = (fConst121 * fRec933[1]);
			double fTemp442 = (fConst122 * fRec936[1]);
			fRec938[0] = (fTemp440 + (fTemp441 + (fRec938[1] + fTemp442)));
			fRec936[0] = fRec938[0];
			double fRec937 = ((fTemp442 + fTemp441) + fTemp440);
			fRec935[0] = (fRec936[0] + fRec935[1]);
			fRec933[0] = fRec935[0];
			double fRec934 = fRec937;
			fVec19[(IOTA & 127)] = ((0.030631296299999999 * fTemp7) + (fRec895 + (fRec910 + (fRec922 + (fRec931 + fRec934)))));
			output19[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec19[((IOTA - iConst123) & 127)])));
			double fTemp443 = (fConst95 * fRec939[1]);
			double fTemp444 = (fConst97 * fRec942[1]);
			double fTemp445 = (fConst98 * fRec945[1]);
			double fTemp446 = (fConst100 * (((((((0.025825992799999999 * fTemp11) + (0.0073937598999999996 * fTemp16)) + (0.030094396999999998 * fTemp17)) + (0.065430889300000003 * fTemp13)) + (0.046766572899999997 * fTemp15)) + (0.114995571 * fTemp19)) - ((0.0063608405000000002 * fTemp21) + ((((0.064932673100000005 * fTemp12) + (0.049777326199999999 * fTemp14)) + (0.041861726199999998 * fTemp18)) + (0.047602963599999999 * fTemp20)))));
			double fTemp447 = (fConst101 * fRec948[1]);
			double fTemp448 = (fConst102 * fRec951[1]);
			fRec953[0] = (fTemp446 + (fTemp447 + (fRec953[1] + fTemp448)));
			fRec951[0] = fRec953[0];
			double fRec952 = ((fTemp448 + fTemp447) + fTemp446);
			fRec950[0] = (fRec951[0] + fRec950[1]);
			fRec948[0] = fRec950[0];
			double fRec949 = fRec952;
			fRec947[0] = (fTemp444 + (fTemp445 + (fRec949 + fRec947[1])));
			fRec945[0] = fRec947[0];
			double fRec946 = (fTemp444 + (fRec949 + fTemp445));
			fRec944[0] = (fRec945[0] + fRec944[1]);
			fRec942[0] = fRec944[0];
			double fRec943 = fRec946;
			fRec941[0] = (fTemp443 + (fRec943 + fRec941[1]));
			fRec939[0] = fRec941[0];
			double fRec940 = (fRec943 + fTemp443);
			double fTemp449 = (fConst104 * fRec954[1]);
			double fTemp450 = (fConst105 * fRec957[1]);
			double fTemp451 = (fConst107 * ((((0.1048542385 * fTemp30) + (0.0101488086 * fTemp32)) + (0.1145043437 * fTemp34)) - ((((((0.0339556414 * fTemp27) + (0.0041961758000000002 * fTemp28)) + (0.0042976118000000001 * fTemp31)) + (0.087095462100000007 * fTemp29)) + (0.073005793499999999 * fTemp33)) + (0.028043553999999998 * fTemp35))));
			double fTemp452 = (fConst108 * fRec960[1]);
			double fTemp453 = (fConst109 * fRec963[1]);
			fRec965[0] = (fTemp451 + (fTemp452 + (fRec965[1] + fTemp453)));
			fRec963[0] = fRec965[0];
			double fRec964 = ((fTemp453 + fTemp452) + fTemp451);
			fRec962[0] = (fRec963[0] + fRec962[1]);
			fRec960[0] = fRec962[0];
			double fRec961 = fRec964;
			fRec959[0] = (fTemp449 + (fTemp450 + (fRec961 + fRec959[1])));
			fRec957[0] = fRec959[0];
			double fRec958 = (fTemp449 + (fRec961 + fTemp450));
			fRec956[0] = (fRec957[0] + fRec956[1]);
			fRec954[0] = fRec956[0];
			double fRec955 = fRec958;
			double fTemp454 = (fConst111 * fRec966[1]);
			double fTemp455 = (fConst113 * (((0.1202824868 * fTemp41) + (0.062959801400000001 * fTemp46)) - (((((0.0053327195000000003 * fTemp40) + (0.093581303099999999 * fTemp43)) + (0.054921770000000002 * fTemp44)) + (0.045266623899999997 * fTemp45)) + (0.070170791999999996 * fTemp42))));
			double fTemp456 = (fConst114 * fRec969[1]);
			double fTemp457 = (fConst115 * fRec972[1]);
			fRec974[0] = (fTemp455 + (fTemp456 + (fRec974[1] + fTemp457)));
			fRec972[0] = fRec974[0];
			double fRec973 = ((fTemp457 + fTemp456) + fTemp455);
			fRec971[0] = (fRec972[0] + fRec971[1]);
			fRec969[0] = fRec971[0];
			double fRec970 = fRec973;
			fRec968[0] = (fTemp454 + (fRec970 + fRec968[1]));
			fRec966[0] = fRec968[0];
			double fRec967 = (fRec970 + fTemp454);
			double fTemp458 = (fConst117 * ((0.071377611199999996 * fTemp51) - ((0.070388008899999993 * fTemp50) + (0.040726760399999999 * fTemp52))));
			double fTemp459 = (fConst118 * fRec975[1]);
			fRec977[0] = (fTemp458 + (fRec977[1] + fTemp459));
			fRec975[0] = fRec977[0];
			double fRec976 = (fTemp459 + fTemp458);
			double fTemp460 = (fConst120 * (((0.069357866800000001 * fTemp55) + (0.024036521700000001 * fTemp59)) - (((0.12220778309999999 * fTemp56) + (0.067775720299999995 * fTemp57)) + (0.037343894099999997 * fTemp58))));
			double fTemp461 = (fConst121 * fRec978[1]);
			double fTemp462 = (fConst122 * fRec981[1]);
			fRec983[0] = (fTemp460 + (fTemp461 + (fRec983[1] + fTemp462)));
			fRec981[0] = fRec983[0];
			double fRec982 = ((fTemp462 + fTemp461) + fTemp460);
			fRec980[0] = (fRec981[0] + fRec980[1]);
			fRec978[0] = fRec980[0];
			double fRec979 = fRec982;
			fVec20[(IOTA & 127)] = ((0.037999764599999999 * fTemp7) + (fRec940 + (fRec955 + (fRec967 + (fRec976 + fRec979)))));
			output20[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec20[((IOTA - iConst123) & 127)])));
			double fTemp463 = (fConst95 * fRec984[1]);
			double fTemp464 = (fConst97 * fRec987[1]);
			double fTemp465 = (fConst98 * fRec990[1]);
			double fTemp466 = (fConst100 * ((((0.0072811964000000003 * fTemp18) + ((((0.065142028500000004 * fTemp12) + (0.016183017800000001 * fTemp17)) + (0.0228765763 * fTemp13)) + (0.098387016999999993 * fTemp15))) + (0.0496561924 * fTemp20)) - (((((0.024204461300000001 * fTemp11) + (0.073623973999999995 * fTemp16)) + (0.0285649984 * fTemp14)) + (0.073087242100000005 * fTemp19)) + (0.0141708322 * fTemp21))));
			double fTemp467 = (fConst101 * fRec993[1]);
			double fTemp468 = (fConst102 * fRec996[1]);
			fRec998[0] = (fTemp466 + (fTemp467 + (fRec998[1] + fTemp468)));
			fRec996[0] = fRec998[0];
			double fRec997 = ((fTemp468 + fTemp467) + fTemp466);
			fRec995[0] = (fRec996[0] + fRec995[1]);
			fRec993[0] = fRec995[0];
			double fRec994 = fRec997;
			fRec992[0] = (fTemp464 + (fTemp465 + (fRec994 + fRec992[1])));
			fRec990[0] = fRec992[0];
			double fRec991 = (fTemp464 + (fRec994 + fTemp465));
			fRec989[0] = (fRec990[0] + fRec989[1]);
			fRec987[0] = fRec989[0];
			double fRec988 = fRec991;
			fRec986[0] = (fTemp463 + (fRec988 + fRec986[1]));
			fRec984[0] = fRec986[0];
			double fRec985 = (fRec988 + fTemp463);
			double fTemp469 = (fConst104 * fRec999[1]);
			double fTemp470 = (fConst105 * fRec1002[1]);
			double fTemp471 = (fConst107 * ((((0.085715838500000002 * fTemp33) + ((((0.034129172499999999 * fTemp27) + (0.052249432700000001 * fTemp30)) + (0.0043294913000000001 * fTemp31)) + (0.036075632699999999 * fTemp32))) + (0.028806551999999999 * fTemp35)) - (((0.071043614099999999 * fTemp28) + (0.079647853399999996 * fTemp29)) + (0.082312175400000007 * fTemp34))));
			double fTemp472 = (fConst108 * fRec1005[1]);
			double fTemp473 = (fConst109 * fRec1008[1]);
			fRec1010[0] = (fTemp471 + (fTemp472 + (fRec1010[1] + fTemp473)));
			fRec1008[0] = fRec1010[0];
			double fRec1009 = ((fTemp473 + fTemp472) + fTemp471);
			fRec1007[0] = (fRec1008[0] + fRec1007[1]);
			fRec1005[0] = fRec1007[0];
			double fRec1006 = fRec1009;
			fRec1004[0] = (fTemp469 + (fTemp470 + (fRec1006 + fRec1004[1])));
			fRec1002[0] = fRec1004[0];
			double fRec1003 = (fTemp469 + (fRec1006 + fTemp470));
			fRec1001[0] = (fRec1002[0] + fRec1001[1]);
			fRec999[0] = fRec1001[0];
			double fRec1000 = fRec1003;
			double fTemp474 = (fConst111 * fRec1011[1]);
			double fTemp475 = (fConst113 * (((0.057486007700000001 * fTemp41) + (0.1082990353 * fTemp42)) - (((((0.038218625200000002 * fTemp40) + (0.019553603499999999 * fTemp43)) + (0.063299092400000007 * fTemp44)) + (0.064664790999999999 * fTemp45)) + (0.047701833200000002 * fTemp46))));
			double fTemp476 = (fConst114 * fRec1014[1]);
			double fTemp477 = (fConst115 * fRec1017[1]);
			fRec1019[0] = (fTemp475 + (fTemp476 + (fRec1019[1] + fTemp477)));
			fRec1017[0] = fRec1019[0];
			double fRec1018 = ((fTemp477 + fTemp476) + fTemp475);
			fRec1016[0] = (fRec1017[0] + fRec1016[1]);
			fRec1014[0] = fRec1016[0];
			double fRec1015 = fRec1018;
			fRec1013[0] = (fTemp474 + (fRec1015 + fRec1013[1]));
			fRec1011[0] = fRec1013[0];
			double fRec1012 = (fRec1015 + fTemp474);
			double fTemp478 = (fConst117 * ((0.053354718400000001 * fTemp51) - ((0.016548580800000001 * fTemp50) + (0.068044421800000005 * fTemp52))));
			double fTemp479 = (fConst118 * fRec1020[1]);
			fRec1022[0] = (fTemp478 + (fRec1022[1] + fTemp479));
			fRec1020[0] = fRec1022[0];
			double fRec1021 = (fTemp479 + fTemp478);
			double fTemp480 = (fConst120 * ((((0.0322900754 * fTemp55) + (0.0054927342000000001 * fTemp59)) + (0.064507223000000002 * fTemp58)) - ((0.028137084600000001 * fTemp56) + (0.11003032159999999 * fTemp57))));
			double fTemp481 = (fConst121 * fRec1023[1]);
			double fTemp482 = (fConst122 * fRec1026[1]);
			fRec1028[0] = (fTemp480 + (fTemp481 + (fRec1028[1] + fTemp482)));
			fRec1026[0] = fRec1028[0];
			double fRec1027 = ((fTemp482 + fTemp481) + fTemp480);
			fRec1025[0] = (fRec1026[0] + fRec1025[1]);
			fRec1023[0] = fRec1025[0];
			double fRec1024 = fRec1027;
			fVec21[(IOTA & 127)] = ((0.0306194443 * fTemp7) + (fRec985 + (fRec1000 + (fRec1012 + (fRec1021 + fRec1024)))));
			output21[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec21[((IOTA - iConst123) & 127)])));
			double fTemp483 = (fConst95 * fRec1029[1]);
			double fTemp484 = (fConst97 * fRec1032[1]);
			double fTemp485 = (fConst98 * fRec1035[1]);
			double fTemp486 = (fConst100 * ((((0.041807703600000003 * fTemp18) + (((0.0063982583999999997 * fTemp11) + (0.1149951402 * fTemp16)) + (0.065470731399999996 * fTemp15))) + (0.025804003999999998 * fTemp21)) - ((0.047515727899999999 * fTemp20) + (((((0.0649565738 * fTemp12) + (0.030130829200000001 * fTemp17)) + (0.046759442900000003 * fTemp13)) + (0.049747779300000003 * fTemp14)) + (0.0074199701000000002 * fTemp19)))));
			double fTemp487 = (fConst101 * fRec1038[1]);
			double fTemp488 = (fConst102 * fRec1041[1]);
			fRec1043[0] = (fTemp486 + (fTemp487 + (fRec1043[1] + fTemp488)));
			fRec1041[0] = fRec1043[0];
			double fRec1042 = ((fTemp488 + fTemp487) + fTemp486);
			fRec1040[0] = (fRec1041[0] + fRec1040[1]);
			fRec1038[0] = fRec1040[0];
			double fRec1039 = fRec1042;
			fRec1037[0] = (fTemp484 + (fTemp485 + (fRec1039 + fRec1037[1])));
			fRec1035[0] = fRec1037[0];
			double fRec1036 = (fTemp484 + (fRec1039 + fTemp485));
			fRec1034[0] = (fRec1035[0] + fRec1034[1]);
			fRec1032[0] = fRec1034[0];
			double fRec1033 = fRec1036;
			fRec1031[0] = (fTemp483 + (fRec1033 + fRec1031[1]));
			fRec1029[0] = fRec1031[0];
			double fRec1030 = (fRec1033 + fTemp483);
			double fTemp489 = (fConst104 * fRec1044[1]);
			double fTemp490 = (fConst105 * fRec1047[1]);
			double fTemp491 = (fConst107 * (((0.0041004887 * fTemp34) + ((0.1145119819 * fTemp28) + (0.073033457100000004 * fTemp33))) - ((((((0.033988066999999997 * fTemp27) + (0.1048814014 * fTemp30)) + (0.010117339499999999 * fTemp31)) + (0.087112857099999996 * fTemp29)) + (0.0042768677999999996 * fTemp32)) + (0.027981421100000001 * fTemp35))));
			double fTemp492 = (fConst108 * fRec1050[1]);
			double fTemp493 = (fConst109 * fRec1053[1]);
			fRec1055[0] = (fTemp491 + (fTemp492 + (fRec1055[1] + fTemp493)));
			fRec1053[0] = fRec1055[0];
			double fRec1054 = ((fTemp493 + fTemp492) + fTemp491);
			fRec1052[0] = (fRec1053[0] + fRec1052[1]);
			fRec1050[0] = fRec1052[0];
			double fRec1051 = fRec1054;
			fRec1049[0] = (fTemp489 + (fTemp490 + (fRec1051 + fRec1049[1])));
			fRec1047[0] = fRec1049[0];
			double fRec1048 = (fTemp489 + (fRec1051 + fTemp490));
			fRec1046[0] = (fRec1047[0] + fRec1046[1]);
			fRec1044[0] = fRec1046[0];
			double fRec1045 = fRec1048;
			double fTemp494 = (fConst111 * fRec1056[1]);
			double fTemp495 = (fConst113 * (((0.0052570658000000003 * fTemp46) + (((0.062967061899999996 * fTemp40) + (0.045294227200000002 * fTemp43)) + (0.070254434500000004 * fTemp42))) - (((0.12028478419999999 * fTemp41) + (0.054933005700000002 * fTemp44)) + (0.093623455100000003 * fTemp45))));
			double fTemp496 = (fConst114 * fRec1059[1]);
			double fTemp497 = (fConst115 * fRec1062[1]);
			fRec1064[0] = (fTemp495 + (fTemp496 + (fRec1064[1] + fTemp497)));
			fRec1062[0] = fRec1064[0];
			double fRec1063 = ((fTemp497 + fTemp496) + fTemp495);
			fRec1061[0] = (fRec1062[0] + fRec1061[1]);
			fRec1059[0] = fRec1061[0];
			double fRec1060 = fRec1063;
			fRec1058[0] = (fTemp494 + (fRec1060 + fRec1058[1]));
			fRec1056[0] = fRec1058[0];
			double fRec1057 = (fRec1060 + fTemp494);
			double fTemp498 = (fConst117 * (((0.0407218497 * fTemp50) + (0.071420472099999993 * fTemp51)) - (0.070432630699999998 * fTemp52)));
			double fTemp499 = (fConst118 * fRec1065[1]);
			fRec1067[0] = (fTemp498 + (fRec1067[1] + fTemp499));
			fRec1065[0] = fRec1067[0];
			double fRec1066 = (fTemp499 + fTemp498);
			double fTemp500 = (fConst120 * ((((0.067781079499999994 * fTemp56) + (0.024061545 * fTemp59)) + (0.037406373 * fTemp58)) - ((0.069349797699999993 * fTemp55) + (0.12228017099999999 * fTemp57))));
			double fTemp501 = (fConst121 * fRec1068[1]);
			double fTemp502 = (fConst122 * fRec1071[1]);
			fRec1073[0] = (fTemp500 + (fTemp501 + (fRec1073[1] + fTemp502)));
			fRec1071[0] = fRec1073[0];
			double fRec1072 = ((fTemp502 + fTemp501) + fTemp500);
			fRec1070[0] = (fRec1071[0] + fRec1070[1]);
			fRec1068[0] = fRec1070[0];
			double fRec1069 = fRec1072;
			fVec22[(IOTA & 127)] = ((0.038020542300000001 * fTemp7) + (fRec1030 + (fRec1045 + (fRec1057 + (fRec1066 + fRec1069)))));
			output22[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec22[((IOTA - iConst123) & 127)])));
			double fTemp503 = (fConst95 * fRec1074[1]);
			double fTemp504 = (fConst97 * fRec1077[1]);
			double fTemp505 = (fConst98 * fRec1080[1]);
			double fTemp506 = (fConst100 * (((0.049614387400000001 * fTemp20) + ((((0.0141639551 * fTemp11) + (0.065139645199999999 * fTemp12)) + (0.022911082900000001 * fTemp15)) + (0.073661101600000001 * fTemp19))) - ((((((0.073071023900000004 * fTemp16) + (0.016199443899999999 * fTemp17)) + (0.098388445399999996 * fTemp13)) + (0.028639465900000001 * fTemp14)) + (0.0073486037999999998 * fTemp18)) + (0.024199353100000001 * fTemp21))));
			double fTemp507 = (fConst101 * fRec1083[1]);
			double fTemp508 = (fConst102 * fRec1086[1]);
			fRec1088[0] = (fTemp506 + (fTemp507 + (fRec1088[1] + fTemp508)));
			fRec1086[0] = fRec1088[0];
			double fRec1087 = ((fTemp508 + fTemp507) + fTemp506);
			fRec1085[0] = (fRec1086[0] + fRec1085[1]);
			fRec1083[0] = fRec1085[0];
			double fRec1084 = fRec1087;
			fRec1082[0] = (fTemp504 + (fTemp505 + (fRec1084 + fRec1082[1])));
			fRec1080[0] = fRec1082[0];
			double fRec1081 = (fTemp504 + (fRec1084 + fTemp505));
			fRec1079[0] = (fRec1080[0] + fRec1079[1]);
			fRec1077[0] = fRec1079[0];
			double fRec1078 = fRec1081;
			fRec1076[0] = (fTemp503 + (fRec1078 + fRec1076[1]));
			fRec1074[0] = fRec1076[0];
			double fRec1075 = (fRec1078 + fTemp503);
			double fTemp509 = (fConst104 * fRec1089[1]);
			double fTemp510 = (fConst105 * fRec1092[1]);
			double fTemp511 = (fConst107 * (((0.028772314300000001 * fTemp35) + (((0.034126342599999998 * fTemp27) + (0.0043325257000000001 * fTemp32)) + (0.071074450600000005 * fTemp34))) - (((((0.082256332400000007 * fTemp28) + (0.052302601400000003 * fTemp30)) + (0.036002602299999999 * fTemp31)) + (0.079689907700000007 * fTemp29)) + (0.085746373599999995 * fTemp33))));
			double fTemp512 = (fConst108 * fRec1095[1]);
			double fTemp513 = (fConst109 * fRec1098[1]);
			fRec1100[0] = (fTemp511 + (fTemp512 + (fRec1100[1] + fTemp513)));
			fRec1098[0] = fRec1100[0];
			double fRec1099 = ((fTemp513 + fTemp512) + fTemp511);
			fRec1097[0] = (fRec1098[0] + fRec1097[1]);
			fRec1095[0] = fRec1097[0];
			double fRec1096 = fRec1099;
			fRec1094[0] = (fTemp509 + (fTemp510 + (fRec1096 + fRec1094[1])));
			fRec1092[0] = fRec1094[0];
			double fRec1093 = (fTemp509 + (fRec1096 + fTemp510));
			fRec1091[0] = (fRec1092[0] + fRec1091[1]);
			fRec1089[0] = fRec1091[0];
			double fRec1090 = fRec1093;
			double fTemp514 = (fConst111 * fRec1101[1]);
			double fTemp515 = (fConst113 * (((0.0647337729 * fTemp43) + (0.0382310846 * fTemp46)) - (((((0.0476547056 * fTemp40) + (0.057536119900000002 * fTemp41)) + (0.063280135000000001 * fTemp44)) + (0.019580840400000001 * fTemp45)) + (0.10827217460000001 * fTemp42))));
			double fTemp516 = (fConst114 * fRec1104[1]);
			double fTemp517 = (fConst115 * fRec1107[1]);
			fRec1109[0] = (fTemp515 + (fTemp516 + (fRec1109[1] + fTemp517)));
			fRec1107[0] = fRec1109[0];
			double fRec1108 = ((fTemp517 + fTemp516) + fTemp515);
			fRec1106[0] = (fRec1107[0] + fRec1106[1]);
			fRec1104[0] = fRec1106[0];
			double fRec1105 = fRec1108;
			fRec1103[0] = (fTemp514 + (fRec1105 + fRec1103[1]));
			fRec1101[0] = fRec1103[0];
			double fRec1102 = (fRec1105 + fTemp514);
			double fTemp518 = (fConst117 * (((0.068032778700000004 * fTemp50) + (0.053373362100000002 * fTemp51)) - (0.016565980500000001 * fTemp52)));
			double fTemp519 = (fConst118 * fRec1110[1]);
			fRec1112[0] = (fTemp518 + (fRec1112[1] + fTemp519));
			fRec1110[0] = fRec1112[0];
			double fRec1111 = (fTemp519 + fTemp518);
			double fTemp520 = (fConst120 * (((0.1100449557 * fTemp56) + (0.0055321232 * fTemp59)) - (((0.032314148199999997 * fTemp55) + (0.0281700179 * fTemp57)) + (0.064471198499999993 * fTemp58))));
			double fTemp521 = (fConst121 * fRec1113[1]);
			double fTemp522 = (fConst122 * fRec1116[1]);
			fRec1118[0] = (fTemp520 + (fTemp521 + (fRec1118[1] + fTemp522)));
			fRec1116[0] = fRec1118[0];
			double fRec1117 = ((fTemp522 + fTemp521) + fTemp520);
			fRec1115[0] = (fRec1116[0] + fRec1115[1]);
			fRec1113[0] = fRec1115[0];
			double fRec1114 = fRec1117;
			fVec23[(IOTA & 127)] = ((0.0306213415 * fTemp7) + (fRec1075 + (fRec1090 + (fRec1102 + (fRec1111 + fRec1114)))));
			output23[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec23[((IOTA - iConst123) & 127)])));
			double fTemp523 = (fConst125 * fRec1119[1]);
			double fTemp524 = (fConst127 * fRec1122[1]);
			double fTemp525 = (fConst128 * fRec1125[1]);
			double fTemp526 = (fConst130 * (((((0.00089786689999999997 * fTemp12) + (0.1219692379 * fTemp13)) + (0.028164928200000001 * fTemp19)) + (0.0018380651999999999 * fTemp21)) - (((0.080026943399999995 * fTemp18) + ((0.057334568599999997 * fTemp15) + ((((0.00034342390000000002 * fTemp11) + (0.016898055799999999 * fTemp16)) + (0.071325131999999999 * fTemp17)) + (0.015650774700000002 * fTemp14)))) + (0.0007866444 * fTemp20))));
			double fTemp527 = (fConst131 * fRec1128[1]);
			double fTemp528 = (fConst132 * fRec1131[1]);
			fRec1133[0] = (fTemp526 + (fTemp527 + (fRec1133[1] + fTemp528)));
			fRec1131[0] = fRec1133[0];
			double fRec1132 = ((fTemp528 + fTemp527) + fTemp526);
			fRec1130[0] = (fRec1131[0] + fRec1130[1]);
			fRec1128[0] = fRec1130[0];
			double fRec1129 = fRec1132;
			fRec1127[0] = (fTemp524 + (fTemp525 + (fRec1129 + fRec1127[1])));
			fRec1125[0] = fRec1127[0];
			double fRec1126 = (fTemp524 + (fRec1129 + fTemp525));
			fRec1124[0] = (fRec1125[0] + fRec1124[1]);
			fRec1122[0] = fRec1124[0];
			double fRec1123 = fRec1126;
			fRec1121[0] = (fTemp523 + (fRec1123 + fRec1121[1]));
			fRec1119[0] = fRec1121[0];
			double fRec1120 = (fRec1123 + fTemp523);
			double fTemp529 = (fConst134 * fRec1134[1]);
			double fTemp530 = (fConst135 * fRec1137[1]);
			double fTemp531 = (fConst137 * (((((0.00036988659999999998 * fTemp27) + (0.1489226551 * fTemp31)) + (0.0350328351 * fTemp29)) + (0.016275781199999999 * fTemp34)) - (((0.066697567200000002 * fTemp33) + (((0.0099615417999999994 * fTemp28) + (0.056906549700000003 * fTemp30)) + (0.062940663100000002 * fTemp32))) + (0.00028330519999999999 * fTemp35))));
			double fTemp532 = (fConst138 * fRec1140[1]);
			double fTemp533 = (fConst139 * fRec1143[1]);
			fRec1145[0] = (fTemp531 + (fTemp532 + (fRec1145[1] + fTemp533)));
			fRec1143[0] = fRec1145[0];
			double fRec1144 = ((fTemp533 + fTemp532) + fTemp531);
			fRec1142[0] = (fRec1143[0] + fRec1142[1]);
			fRec1140[0] = fRec1142[0];
			double fRec1141 = fRec1144;
			fRec1139[0] = (fTemp529 + (fTemp530 + (fRec1141 + fRec1139[1])));
			fRec1137[0] = fRec1139[0];
			double fRec1138 = (fTemp529 + (fRec1141 + fTemp530));
			fRec1136[0] = (fRec1137[0] + fRec1136[1]);
			fRec1134[0] = fRec1136[0];
			double fRec1135 = fRec1138;
			double fTemp534 = (fConst141 * fRec1146[1]);
			double fTemp535 = (fConst143 * ((((0.13847193469999999 * fTemp43) + (0.083723758600000003 * fTemp44)) + (0.0062344825999999997 * fTemp46)) - ((((0.0038678001999999999 * fTemp40) + (0.034670622700000001 * fTemp41)) + (0.055250673600000001 * fTemp45)) + (0.041734716800000002 * fTemp42))));
			double fTemp536 = (fConst144 * fRec1149[1]);
			double fTemp537 = (fConst145 * fRec1152[1]);
			fRec1154[0] = (fTemp535 + (fTemp536 + (fRec1154[1] + fTemp537)));
			fRec1152[0] = fRec1154[0];
			double fRec1153 = ((fTemp537 + fTemp536) + fTemp535);
			fRec1151[0] = (fRec1152[0] + fRec1151[1]);
			fRec1149[0] = fRec1151[0];
			double fRec1150 = fRec1153;
			fRec1148[0] = (fTemp534 + (fRec1150 + fRec1148[1]));
			fRec1146[0] = fRec1148[0];
			double fRec1147 = (fRec1150 + fTemp534);
			double fTemp538 = (fConst147 * (((0.039881849099999998 * fTemp50) + (0.088532238999999999 * fTemp51)) - (0.015116001299999999 * fTemp52)));
			double fTemp539 = (fConst148 * fRec1155[1]);
			fRec1157[0] = (fTemp538 + (fRec1157[1] + fTemp539));
			fRec1155[0] = fRec1157[0];
			double fRec1156 = (fTemp539 + fTemp538);
			double fTemp540 = (fConst150 * (((0.094799970499999997 * fTemp56) + (0.10635739380000001 * fTemp59)) - (((0.013823488599999999 * fTemp55) + (0.036598682600000002 * fTemp57)) + (0.016917791000000001 * fTemp58))));
			double fTemp541 = (fConst151 * fRec1158[1]);
			double fTemp542 = (fConst152 * fRec1161[1]);
			fRec1163[0] = (fTemp540 + (fTemp541 + (fRec1163[1] + fTemp542)));
			fRec1161[0] = fRec1163[0];
			double fRec1162 = ((fTemp542 + fTemp541) + fTemp540);
			fRec1160[0] = (fRec1161[0] + fRec1160[1]);
			fRec1158[0] = fRec1160[0];
			double fRec1159 = fRec1162;
			fVec24[0] = ((0.034354885699999997 * fTemp7) + (fRec1120 + (fRec1135 + (fRec1147 + (fRec1156 + fRec1159)))));
			output24[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec24[iConst153])));
			double fTemp543 = (fConst125 * fRec1164[1]);
			double fTemp544 = (fConst127 * fRec1167[1]);
			double fTemp545 = (fConst128 * fRec1170[1]);
			double fTemp546 = (fConst130 * (((0.0168388667 * fTemp19) + ((0.079959720799999995 * fTemp18) + (((((0.00088688120000000002 * fTemp12) + (0.028111043799999999 * fTemp16)) + (0.071284875299999995 * fTemp17)) + (0.057299954799999997 * fTemp13)) + (0.1220212334 * fTemp15)))) - ((0.00034429980000000001 * fTemp21) + (((0.0018336099 * fTemp11) + (0.015664354500000002 * fTemp14)) + (0.0007991993 * fTemp20)))));
			double fTemp547 = (fConst131 * fRec1173[1]);
			double fTemp548 = (fConst132 * fRec1176[1]);
			fRec1178[0] = (fTemp546 + (fTemp547 + (fRec1178[1] + fTemp548)));
			fRec1176[0] = fRec1178[0];
			double fRec1177 = ((fTemp548 + fTemp547) + fTemp546);
			fRec1175[0] = (fRec1176[0] + fRec1175[1]);
			fRec1173[0] = fRec1175[0];
			double fRec1174 = fRec1177;
			fRec1172[0] = (fTemp544 + (fTemp545 + (fRec1174 + fRec1172[1])));
			fRec1170[0] = fRec1172[0];
			double fRec1171 = (fTemp544 + (fRec1174 + fTemp545));
			fRec1169[0] = (fRec1170[0] + fRec1169[1]);
			fRec1167[0] = fRec1169[0];
			double fRec1168 = fRec1171;
			fRec1166[0] = (fTemp543 + (fRec1168 + fRec1166[1]));
			fRec1164[0] = fRec1166[0];
			double fRec1165 = (fRec1168 + fTemp543);
			double fTemp549 = (fConst134 * fRec1179[1]);
			double fTemp550 = (fConst135 * fRec1182[1]);
			double fTemp551 = (fConst137 * (((((((((0.0003674145 * fTemp27) + (0.0162470501 * fTemp28)) + (0.056873225600000001 * fTemp30)) + (0.062919761599999999 * fTemp31)) + (0.035059241200000001 * fTemp29)) + (0.14897413879999999 * fTemp32)) + (0.0666431309 * fTemp33)) + (0.0099293989000000006 * fTemp34)) - (0.00028756579999999999 * fTemp35)));
			double fTemp552 = (fConst138 * fRec1185[1]);
			double fTemp553 = (fConst139 * fRec1188[1]);
			fRec1190[0] = (fTemp551 + (fTemp552 + (fRec1190[1] + fTemp553)));
			fRec1188[0] = fRec1190[0];
			double fRec1189 = ((fTemp553 + fTemp552) + fTemp551);
			fRec1187[0] = (fRec1188[0] + fRec1187[1]);
			fRec1185[0] = fRec1187[0];
			double fRec1186 = fRec1189;
			fRec1184[0] = (fTemp549 + (fTemp550 + (fRec1186 + fRec1184[1])));
			fRec1182[0] = fRec1184[0];
			double fRec1183 = (fTemp549 + (fRec1186 + fTemp550));
			fRec1181[0] = (fRec1182[0] + fRec1181[1]);
			fRec1179[0] = fRec1181[0];
			double fRec1180 = fRec1183;
			double fTemp554 = (fConst141 * fRec1191[1]);
			double fTemp555 = (fConst143 * (((((((0.0062242631999999999 * fTemp40) + (0.034648934300000003 * fTemp41)) + (0.055236739799999997 * fTemp43)) + (0.083775584400000006 * fTemp44)) + (0.13850598359999999 * fTemp45)) + (0.041700136399999997 * fTemp42)) + (0.0038560680999999999 * fTemp46)));
			double fTemp556 = (fConst144 * fRec1194[1]);
			double fTemp557 = (fConst145 * fRec1197[1]);
			fRec1199[0] = (fTemp555 + (fTemp556 + (fRec1199[1] + fTemp557)));
			fRec1197[0] = fRec1199[0];
			double fRec1198 = ((fTemp557 + fTemp556) + fTemp555);
			fRec1196[0] = (fRec1197[0] + fRec1196[1]);
			fRec1194[0] = fRec1196[0];
			double fRec1195 = fRec1198;
			fRec1193[0] = (fTemp554 + (fRec1195 + fRec1193[1]));
			fRec1191[0] = fRec1193[0];
			double fRec1192 = (fRec1195 + fTemp554);
			double fTemp558 = (fConst147 * (((0.015112081600000001 * fTemp50) + (0.088570217199999995 * fTemp51)) + (0.039885551200000001 * fTemp52)));
			double fTemp559 = (fConst148 * fRec1200[1]);
			fRec1202[0] = (fTemp558 + (fRec1202[1] + fTemp559));
			fRec1200[0] = fRec1202[0];
			double fRec1201 = (fTemp559 + fTemp558);
			double fTemp560 = (fConst150 * (((((0.0138143112 * fTemp55) + (0.036589704399999999 * fTemp56)) + (0.106411387 * fTemp59)) + (0.094814867900000002 * fTemp57)) + (0.0169033884 * fTemp58)));
			double fTemp561 = (fConst151 * fRec1203[1]);
			double fTemp562 = (fConst152 * fRec1206[1]);
			fRec1208[0] = (fTemp560 + (fTemp561 + (fRec1208[1] + fTemp562)));
			fRec1206[0] = fRec1208[0];
			double fRec1207 = ((fTemp562 + fTemp561) + fTemp560);
			fRec1205[0] = (fRec1206[0] + fRec1205[1]);
			fRec1203[0] = fRec1205[0];
			double fRec1204 = fRec1207;
			fVec25[0] = ((0.034368230399999998 * fTemp7) + (fRec1165 + (fRec1180 + (fRec1192 + (fRec1201 + fRec1204)))));
			output25[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec25[iConst153])));
			double fTemp563 = (fConst125 * fRec1209[1]);
			double fTemp564 = (fConst127 * fRec1212[1]);
			double fTemp565 = (fConst128 * fRec1215[1]);
			double fTemp566 = (fConst130 * (((((0.00034784239999999998 * fTemp11) + (0.00095683870000000002 * fTemp12)) + (0.016911639400000001 * fTemp16)) + (0.057250342000000003 * fTemp15)) - ((0.0018129146999999999 * fTemp21) + ((0.0007648927 * fTemp20) + ((0.0281986283 * fTemp19) + ((((0.071343861199999997 * fTemp17) + (0.1220141159 * fTemp13)) + (0.0156424137 * fTemp14)) + (0.0799987796 * fTemp18)))))));
			double fTemp567 = (fConst131 * fRec1218[1]);
			double fTemp568 = (fConst132 * fRec1221[1]);
			fRec1223[0] = (fTemp566 + (fTemp567 + (fRec1223[1] + fTemp568)));
			fRec1221[0] = fRec1223[0];
			double fRec1222 = ((fTemp568 + fTemp567) + fTemp566);
			fRec1220[0] = (fRec1221[0] + fRec1220[1]);
			fRec1218[0] = fRec1220[0];
			double fRec1219 = fRec1222;
			fRec1217[0] = (fTemp564 + (fTemp565 + (fRec1219 + fRec1217[1])));
			fRec1215[0] = fRec1217[0];
			double fRec1216 = (fTemp564 + (fRec1219 + fTemp565));
			fRec1214[0] = (fRec1215[0] + fRec1214[1]);
			fRec1212[0] = fRec1214[0];
			double fRec1213 = fRec1216;
			fRec1211[0] = (fTemp563 + (fRec1213 + fRec1211[1]));
			fRec1209[0] = fRec1211[0];
			double fRec1210 = (fRec1213 + fTemp563);
			double fTemp569 = (fConst134 * fRec1224[1]);
			double fTemp570 = (fConst135 * fRec1227[1]);
			double fTemp571 = (fConst137 * (((0.062888960399999999 * fTemp32) + (((0.00039784089999999998 * fTemp27) + (0.0099851135000000001 * fTemp28)) + (0.035041661100000003 * fTemp29))) - ((0.00027412310000000001 * fTemp35) + ((0.016311194099999999 * fTemp34) + (((0.0569313709 * fTemp30) + (0.14896404229999999 * fTemp31)) + (0.066701710999999997 * fTemp33))))));
			double fTemp572 = (fConst138 * fRec1230[1]);
			double fTemp573 = (fConst139 * fRec1233[1]);
			fRec1235[0] = (fTemp571 + (fTemp572 + (fRec1235[1] + fTemp573)));
			fRec1233[0] = fRec1235[0];
			double fRec1234 = ((fTemp573 + fTemp572) + fTemp571);
			fRec1232[0] = (fRec1233[0] + fRec1232[1]);
			fRec1230[0] = fRec1232[0];
			double fRec1231 = fRec1234;
			fRec1229[0] = (fTemp569 + (fTemp570 + (fRec1231 + fRec1229[1])));
			fRec1227[0] = fRec1229[0];
			double fRec1228 = (fTemp569 + (fRec1231 + fTemp570));
			fRec1226[0] = (fRec1227[0] + fRec1226[1]);
			fRec1224[0] = fRec1226[0];
			double fRec1225 = fRec1228;
			double fTemp574 = (fConst141 * fRec1236[1]);
			double fTemp575 = (fConst143 * ((((0.0038815699 * fTemp40) + (0.083737399099999998 * fTemp44)) + (0.055223153599999998 * fTemp45)) - ((0.0062531050000000001 * fTemp46) + (((0.034691040700000002 * fTemp41) + (0.13851131250000001 * fTemp43)) + (0.041751650299999998 * fTemp42)))));
			double fTemp576 = (fConst144 * fRec1239[1]);
			double fTemp577 = (fConst145 * fRec1242[1]);
			fRec1244[0] = (fTemp575 + (fTemp576 + (fRec1244[1] + fTemp577)));
			fRec1242[0] = fRec1244[0];
			double fRec1243 = ((fTemp577 + fTemp576) + fTemp575);
			fRec1241[0] = (fRec1242[0] + fRec1241[1]);
			fRec1239[0] = fRec1241[0];
			double fRec1240 = fRec1243;
			fRec1238[0] = (fTemp574 + (fRec1240 + fRec1238[1]));
			fRec1236[0] = fRec1238[0];
			double fRec1237 = (fRec1240 + fTemp574);
			double fTemp578 = (fConst147 * (((0.088548185599999996 * fTemp51) + (0.0151123496 * fTemp52)) - (0.039895589600000003 * fTemp50)));
			double fTemp579 = (fConst148 * fRec1245[1]);
			fRec1247[0] = (fTemp578 + (fRec1247[1] + fTemp579));
			fRec1245[0] = fRec1247[0];
			double fRec1246 = (fTemp579 + fTemp578);
			double fTemp580 = (fConst150 * (((0.10637524499999999 * fTemp59) + (0.036586640400000002 * fTemp57)) - (((0.0138333298 * fTemp55) + (0.094829860399999993 * fTemp56)) + (0.0169290993 * fTemp58))));
			double fTemp581 = (fConst151 * fRec1248[1]);
			double fTemp582 = (fConst152 * fRec1251[1]);
			fRec1253[0] = (fTemp580 + (fTemp581 + (fRec1253[1] + fTemp582)));
			fRec1251[0] = fRec1253[0];
			double fRec1252 = ((fTemp582 + fTemp581) + fTemp580);
			fRec1250[0] = (fRec1251[0] + fRec1250[1]);
			fRec1248[0] = fRec1250[0];
			double fRec1249 = fRec1252;
			fVec26[0] = ((0.034361336499999999 * fTemp7) + (fRec1210 + (fRec1225 + (fRec1237 + (fRec1246 + fRec1249)))));
			output26[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec26[iConst153])));
			double fTemp583 = (fConst125 * fRec1254[1]);
			double fTemp584 = (fConst127 * fRec1257[1]);
			double fTemp585 = (fConst128 * fRec1260[1]);
			double fTemp586 = (fConst130 * ((((((0.0018331738000000001 * fTemp11) + (0.00089944120000000002 * fTemp12)) + (0.071334030600000001 * fTemp17)) + (0.079994080300000006 * fTemp18)) + (0.00035212850000000001 * fTemp21)) - ((0.00081297539999999999 * fTemp20) + (((0.122013476 * fTemp15) + (((0.0281500428 * fTemp16) + (0.057324708100000003 * fTemp13)) + (0.0156685313 * fTemp14))) + (0.016842529299999999 * fTemp19)))));
			double fTemp587 = (fConst131 * fRec1263[1]);
			double fTemp588 = (fConst132 * fRec1266[1]);
			fRec1268[0] = (fTemp586 + (fTemp587 + (fRec1268[1] + fTemp588)));
			fRec1266[0] = fRec1268[0];
			double fRec1267 = ((fTemp588 + fTemp587) + fTemp586);
			fRec1265[0] = (fRec1266[0] + fRec1265[1]);
			fRec1263[0] = fRec1265[0];
			double fRec1264 = fRec1267;
			fRec1262[0] = (fTemp584 + (fTemp585 + (fRec1264 + fRec1262[1])));
			fRec1260[0] = fRec1262[0];
			double fRec1261 = (fTemp584 + (fRec1264 + fTemp585));
			fRec1259[0] = (fRec1260[0] + fRec1259[1]);
			fRec1257[0] = fRec1259[0];
			double fRec1258 = fRec1261;
			fRec1256[0] = (fTemp583 + (fRec1258 + fRec1256[1]));
			fRec1254[0] = fRec1256[0];
			double fRec1255 = (fRec1258 + fTemp583);
			double fTemp589 = (fConst134 * fRec1269[1]);
			double fTemp590 = (fConst135 * fRec1272[1]);
			double fTemp591 = (fConst137 * (((((0.00037305740000000002 * fTemp27) + (0.056925988300000001 * fTemp30)) + (0.035041152300000003 * fTemp29)) + (0.066669185399999997 * fTemp33)) - ((0.00029503379999999999 * fTemp35) + ((((0.0162765489 * fTemp28) + (0.062950191899999994 * fTemp31)) + (0.1489803931 * fTemp32)) + (0.0099259281000000001 * fTemp34)))));
			double fTemp592 = (fConst138 * fRec1275[1]);
			double fTemp593 = (fConst139 * fRec1278[1]);
			fRec1280[0] = (fTemp591 + (fTemp592 + (fRec1280[1] + fTemp593)));
			fRec1278[0] = fRec1280[0];
			double fRec1279 = ((fTemp593 + fTemp592) + fTemp591);
			fRec1277[0] = (fRec1278[0] + fRec1277[1]);
			fRec1275[0] = fRec1277[0];
			double fRec1276 = fRec1279;
			fRec1274[0] = (fTemp589 + (fTemp590 + (fRec1276 + fRec1274[1])));
			fRec1272[0] = fRec1274[0];
			double fRec1273 = (fTemp589 + (fRec1276 + fTemp590));
			fRec1271[0] = (fRec1272[0] + fRec1271[1]);
			fRec1269[0] = fRec1271[0];
			double fRec1270 = fRec1273;
			double fTemp594 = (fConst141 * fRec1281[1]);
			double fTemp595 = (fConst143 * ((((0.034689685300000002 * fTemp41) + (0.083761760599999999 * fTemp44)) + (0.0417159904 * fTemp42)) - ((((0.0062378497 * fTemp40) + (0.0552722961 * fTemp43)) + (0.13852682529999999 * fTemp45)) + (0.0038529318999999999 * fTemp46))));
			double fTemp596 = (fConst144 * fRec1284[1]);
			double fTemp597 = (fConst145 * fRec1287[1]);
			fRec1289[0] = (fTemp595 + (fTemp596 + (fRec1289[1] + fTemp597)));
			fRec1287[0] = fRec1289[0];
			double fRec1288 = ((fTemp597 + fTemp596) + fTemp595);
			fRec1286[0] = (fRec1287[0] + fRec1286[1]);
			fRec1284[0] = fRec1286[0];
			double fRec1285 = fRec1288;
			fRec1283[0] = (fTemp594 + (fRec1285 + fRec1283[1]));
			fRec1281[0] = fRec1283[0];
			double fRec1282 = (fRec1285 + fTemp594);
			double fTemp598 = (fConst147 * ((0.088579545900000001 * fTemp51) - ((0.015126289899999999 * fTemp50) + (0.0398976973 * fTemp52))));
			double fTemp599 = (fConst148 * fRec1290[1]);
			fRec1292[0] = (fTemp598 + (fRec1292[1] + fTemp599));
			fRec1290[0] = fRec1292[0];
			double fRec1291 = (fTemp599 + fTemp598);
			double fTemp600 = (fConst150 * ((((0.0138334818 * fTemp55) + (0.10641176920000001 * fTemp59)) + (0.016909811800000001 * fTemp58)) - ((0.036619387000000003 * fTemp56) + (0.0948377101 * fTemp57))));
			double fTemp601 = (fConst151 * fRec1293[1]);
			double fTemp602 = (fConst152 * fRec1296[1]);
			fRec1298[0] = (fTemp600 + (fTemp601 + (fRec1298[1] + fTemp602)));
			fRec1296[0] = fRec1298[0];
			double fRec1297 = ((fTemp602 + fTemp601) + fTemp600);
			fRec1295[0] = (fRec1296[0] + fRec1295[1]);
			fRec1293[0] = fRec1295[0];
			double fRec1294 = fRec1297;
			fVec27[0] = ((0.034373545499999998 * fTemp7) + (fRec1255 + (fRec1270 + (fRec1282 + (fRec1291 + fRec1294)))));
			output27[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec27[iConst153])));
			double fTemp603 = (fConst155 * fRec1299[1]);
			double fTemp604 = (fConst157 * fRec1302[1]);
			double fTemp605 = (fConst158 * fRec1305[1]);
			double fTemp606 = (fConst160 * (((1.1270900000000001e-05 * fTemp19) + (((0.10068073399999999 * fTemp14) + ((((0.0001214182 * fTemp12) + (1.9471599999999998e-05 * fTemp16)) + (8.6204999999999999e-06 * fTemp17)) + (0.0001178428 * fTemp13))) + (5.6403400000000003e-05 * fTemp18))) - ((5.3099999999999999e-08 * fTemp21) + (((2.251e-07 * fTemp11) + (5.1301400000000003e-05 * fTemp15)) + (6.3188799999999994e-05 * fTemp20)))));
			double fTemp607 = (fConst161 * fRec1308[1]);
			double fTemp608 = (fConst162 * fRec1311[1]);
			fRec1313[0] = (fTemp606 + (fTemp607 + (fRec1313[1] + fTemp608)));
			fRec1311[0] = fRec1313[0];
			double fRec1312 = ((fTemp608 + fTemp607) + fTemp606);
			fRec1310[0] = (fRec1311[0] + fRec1310[1]);
			fRec1308[0] = fRec1310[0];
			double fRec1309 = fRec1312;
			fRec1307[0] = (fTemp604 + (fTemp605 + (fRec1309 + fRec1307[1])));
			fRec1305[0] = fRec1307[0];
			double fRec1306 = (fTemp604 + (fRec1309 + fTemp605));
			fRec1304[0] = (fRec1305[0] + fRec1304[1]);
			fRec1302[0] = fRec1304[0];
			double fRec1303 = fRec1306;
			fRec1301[0] = (fTemp603 + (fRec1303 + fRec1301[1]));
			fRec1299[0] = fRec1301[0];
			double fRec1300 = (fRec1303 + fTemp603);
			double fTemp609 = (fConst164 * fRec1314[1]);
			double fTemp610 = (fConst165 * fRec1317[1]);
			double fTemp611 = (fConst167 * (((5.0616e-06 * fTemp34) + ((((((3.4548999999999997e-05 * fTemp27) + (8.3846999999999995e-06 * fTemp28)) + (5.7409999999999998e-06 * fTemp30)) + (9.1636600000000003e-05 * fTemp31)) + (0.089343940799999993 * fTemp29)) + (3.2799000000000002e-05 * fTemp33))) - ((4.1664600000000001e-05 * fTemp32) + (1.7976900000000001e-05 * fTemp35))));
			double fTemp612 = (fConst168 * fRec1320[1]);
			double fTemp613 = (fConst169 * fRec1323[1]);
			fRec1325[0] = (fTemp611 + (fTemp612 + (fRec1325[1] + fTemp613)));
			fRec1323[0] = fRec1325[0];
			double fRec1324 = ((fTemp613 + fTemp612) + fTemp611);
			fRec1322[0] = (fRec1323[0] + fRec1322[1]);
			fRec1320[0] = fRec1322[0];
			double fRec1321 = fRec1324;
			fRec1319[0] = (fTemp609 + (fTemp610 + (fRec1321 + fRec1319[1])));
			fRec1317[0] = fRec1319[0];
			double fRec1318 = (fTemp609 + (fRec1321 + fTemp610));
			fRec1316[0] = (fRec1317[0] + fRec1316[1]);
			fRec1314[0] = fRec1316[0];
			double fRec1315 = fRec1318;
			double fTemp614 = (fConst171 * fRec1326[1]);
			double fTemp615 = (fConst173 * (((1.6007e-06 * fTemp46) + (((((2.5671e-06 * fTemp40) + (3.0189999999999998e-06 * fTemp41)) + (6.2012000000000002e-05 * fTemp43)) + (0.074076867699999993 * fTemp44)) + (1.5710999999999999e-05 * fTemp42))) - (2.9040600000000001e-05 * fTemp45)));
			double fTemp616 = (fConst174 * fRec1329[1]);
			double fTemp617 = (fConst175 * fRec1332[1]);
			fRec1334[0] = (fTemp615 + (fTemp616 + (fRec1334[1] + fTemp617)));
			fRec1332[0] = fRec1334[0];
			double fRec1333 = ((fTemp617 + fTemp616) + fTemp615);
			fRec1331[0] = (fRec1332[0] + fRec1331[1]);
			fRec1329[0] = fRec1331[0];
			double fRec1330 = fRec1333;
			fRec1328[0] = (fTemp614 + (fRec1330 + fRec1328[1]));
			fRec1326[0] = fRec1328[0];
			double fRec1327 = (fRec1330 + fTemp614);
			double fTemp618 = (fConst177 * (((1.24741e-05 * fTemp50) + (0.034345824400000002 * fTemp51)) - (6.0310999999999997e-06 * fTemp52)));
			double fTemp619 = (fConst178 * fRec1335[1]);
			fRec1337[0] = (fTemp618 + (fRec1337[1] + fTemp619));
			fRec1335[0] = fRec1337[0];
			double fRec1336 = (fTemp619 + fTemp618);
			double fTemp620 = (fConst180 * (((((1.0774000000000001e-06 * fTemp55) + (3.4079899999999999e-05 * fTemp56)) + (0.055478496199999998 * fTemp59)) + (5.2643999999999999e-06 * fTemp58)) - (1.6277899999999999e-05 * fTemp57)));
			double fTemp621 = (fConst181 * fRec1338[1]);
			double fTemp622 = (fConst182 * fRec1341[1]);
			fRec1343[0] = (fTemp620 + (fTemp621 + (fRec1343[1] + fTemp622)));
			fRec1341[0] = fRec1343[0];
			double fRec1342 = ((fTemp622 + fTemp621) + fTemp620);
			fRec1340[0] = (fRec1341[0] + fRec1340[1]);
			fRec1338[0] = fRec1340[0];
			double fRec1339 = fRec1342;
			output28[i] = FAUSTFLOAT((fRec0[0] * ((0.011628344800000001 * fTemp7) + (fRec1300 + (fRec1315 + (fRec1327 + (fRec1336 + fRec1339)))))));
			double fTemp623 = (fConst184 * fRec1344[1]);
			double fTemp624 = (fConst186 * fRec1347[1]);
			double fTemp625 = (fConst187 * fRec1350[1]);
			double fTemp626 = (fConst189 * ((((0.0040314490000000003 * fTemp18) + ((((0.015567741600000001 * fTemp16) + (0.026006108999999999 * fTemp17)) + (0.0051470624000000001 * fTemp13)) + (0.0058263137000000003 * fTemp15))) + (0.10123748809999999 * fTemp20)) - (((((0.0467226798 * fTemp11) + (0.031686988200000002 * fTemp12)) + (0.0209533527 * fTemp14)) + (0.0093053256000000008 * fTemp19)) + (0.10626197969999999 * fTemp21))));
			double fTemp627 = (fConst190 * fRec1353[1]);
			double fTemp628 = (fConst191 * fRec1356[1]);
			fRec1358[0] = (fTemp626 + (fTemp627 + (fRec1358[1] + fTemp628)));
			fRec1356[0] = fRec1358[0];
			double fRec1357 = ((fTemp628 + fTemp627) + fTemp626);
			fRec1355[0] = (fRec1356[0] + fRec1355[1]);
			fRec1353[0] = fRec1355[0];
			double fRec1354 = fRec1357;
			fRec1352[0] = (fTemp624 + (fTemp625 + (fRec1354 + fRec1352[1])));
			fRec1350[0] = fRec1352[0];
			double fRec1351 = (fTemp624 + (fRec1354 + fTemp625));
			fRec1349[0] = (fRec1350[0] + fRec1349[1]);
			fRec1347[0] = fRec1349[0];
			double fRec1348 = fRec1351;
			fRec1346[0] = (fTemp623 + (fRec1348 + fRec1346[1]));
			fRec1344[0] = fRec1346[0];
			double fRec1345 = (fRec1348 + fTemp623);
			double fTemp629 = (fConst193 * fRec1359[1]);
			double fTemp630 = (fConst194 * fRec1362[1]);
			double fTemp631 = (fConst196 * (((0.056047287799999998 * fTemp34) + ((0.0011899018 * fTemp33) + ((0.033416372399999998 * fTemp32) + ((((0.035044664400000002 * fTemp27) + (0.0063303526000000002 * fTemp30)) + (0.028673619800000001 * fTemp31)) + (0.0019360950000000001 * fTemp29))))) - ((0.0898425313 * fTemp28) + (0.1141657034 * fTemp35))));
			double fTemp632 = (fConst197 * fRec1365[1]);
			double fTemp633 = (fConst198 * fRec1368[1]);
			fRec1370[0] = (fTemp631 + (fTemp632 + (fRec1370[1] + fTemp633)));
			fRec1368[0] = fRec1370[0];
			double fRec1369 = ((fTemp633 + fTemp632) + fTemp631);
			fRec1367[0] = (fRec1368[0] + fRec1367[1]);
			fRec1365[0] = fRec1367[0];
			double fRec1366 = fRec1369;
			fRec1364[0] = (fTemp629 + (fTemp630 + (fRec1366 + fRec1364[1])));
			fRec1362[0] = fRec1364[0];
			double fRec1363 = (fTemp629 + (fRec1366 + fTemp630));
			fRec1361[0] = (fRec1362[0] + fRec1361[1]);
			fRec1359[0] = fRec1361[0];
			double fRec1360 = fRec1363;
			double fTemp634 = (fConst200 * fRec1371[1]);
			double fTemp635 = (fConst202 * (((0.098709739399999996 * fTemp40) + (0.045077498299999998 * fTemp44)) - ((0.0620865798 * fTemp46) + ((((0.097178974400000007 * fTemp41) + (0.0074881662000000002 * fTemp43)) + (0.0085648378000000008 * fTemp45)) + (0.014866345499999999 * fTemp42)))));
			double fTemp636 = (fConst203 * fRec1374[1]);
			double fTemp637 = (fConst204 * fRec1377[1]);
			fRec1379[0] = (fTemp635 + (fTemp636 + (fRec1379[1] + fTemp637)));
			fRec1377[0] = fRec1379[0];
			double fRec1378 = ((fTemp637 + fTemp636) + fTemp635);
			fRec1376[0] = (fRec1377[0] + fRec1376[1]);
			fRec1374[0] = fRec1376[0];
			double fRec1375 = fRec1378;
			fRec1373[0] = (fTemp634 + (fRec1375 + fRec1373[1]));
			fRec1371[0] = fRec1373[0];
			double fRec1372 = (fRec1375 + fTemp634);
			double fTemp638 = (fConst206 * (((0.0555503148 * fTemp50) + (0.064570036499999997 * fTemp52)) - (0.038110248700000002 * fTemp51)));
			double fTemp639 = (fConst207 * fRec1380[1]);
			fRec1382[0] = (fTemp638 + (fRec1382[1] + fTemp639));
			fRec1380[0] = fRec1382[0];
			double fRec1381 = (fTemp639 + fTemp638);
			double fTemp640 = (fConst209 * (((0.1048690719 * fTemp55) + (0.015807961499999999 * fTemp58)) - (((0.0532736038 * fTemp56) + (0.026508827299999999 * fTemp59)) + (0.062044658400000001 * fTemp57))));
			double fTemp641 = (fConst210 * fRec1383[1]);
			double fTemp642 = (fConst211 * fRec1386[1]);
			fRec1388[0] = (fTemp640 + (fTemp641 + (fRec1388[1] + fTemp642)));
			fRec1386[0] = fRec1388[0];
			double fRec1387 = ((fTemp642 + fTemp641) + fTemp640);
			fRec1385[0] = (fRec1386[0] + fRec1385[1]);
			fRec1383[0] = fRec1385[0];
			double fRec1384 = fRec1387;
			fVec28[(IOTA & 511)] = ((0.033283181699999997 * fTemp7) + (fRec1345 + (fRec1360 + (fRec1372 + (fRec1381 + fRec1384)))));
			output29[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec28[((IOTA - iConst212) & 511)])));
			double fTemp643 = (fConst214 * fRec1389[1]);
			double fTemp644 = (fConst216 * fRec1392[1]);
			double fTemp645 = (fConst217 * fRec1395[1]);
			double fTemp646 = (fConst219 * (((0.0106592695 * fTemp19) + ((0.0211450639 * fTemp18) + (((((0.1159641439 * fTemp11) + (0.0147564888 * fTemp16)) + (0.0157376142 * fTemp17)) + (0.0024989598000000001 * fTemp13)) + (0.0072290512000000003 * fTemp15)))) - ((0.0039237372000000001 * fTemp21) + (((0.10165735319999999 * fTemp12) + (0.020958301299999999 * fTemp14)) + (0.030432242299999999 * fTemp20)))));
			double fTemp647 = (fConst220 * fRec1398[1]);
			double fTemp648 = (fConst221 * fRec1401[1]);
			fRec1403[0] = (fTemp646 + (fTemp647 + (fRec1403[1] + fTemp648)));
			fRec1401[0] = fRec1403[0];
			double fRec1402 = ((fTemp648 + fTemp647) + fTemp646);
			fRec1400[0] = (fRec1401[0] + fRec1400[1]);
			fRec1398[0] = fRec1400[0];
			double fRec1399 = fRec1402;
			fRec1397[0] = (fTemp644 + (fTemp645 + (fRec1399 + fRec1397[1])));
			fRec1395[0] = fRec1397[0];
			double fRec1396 = (fTemp644 + (fRec1399 + fTemp645));
			fRec1394[0] = (fRec1395[0] + fRec1394[1]);
			fRec1392[0] = fRec1394[0];
			double fRec1393 = fRec1396;
			fRec1391[0] = (fTemp643 + (fRec1393 + fRec1391[1]));
			fRec1389[0] = fRec1391[0];
			double fRec1390 = (fRec1393 + fTemp643);
			double fTemp649 = (fConst223 * fRec1404[1]);
			double fTemp650 = (fConst224 * fRec1407[1]);
			double fTemp651 = (fConst226 * ((((0.0053189274000000003 * fTemp33) + ((0.041848493299999998 * fTemp32) + ((((0.1144768895 * fTemp27) + (0.0037560648999999998 * fTemp30)) + (0.0138674908 * fTemp31)) + (0.0018571359999999999 * fTemp29)))) + (0.033789075100000003 * fTemp35)) - ((0.086787957400000004 * fTemp28) + (0.060724842299999998 * fTemp34))));
			double fTemp652 = (fConst227 * fRec1410[1]);
			double fTemp653 = (fConst228 * fRec1413[1]);
			fRec1415[0] = (fTemp651 + (fTemp652 + (fRec1415[1] + fTemp653)));
			fRec1413[0] = fRec1415[0];
			double fRec1414 = ((fTemp653 + fTemp652) + fTemp651);
			fRec1412[0] = (fRec1413[0] + fRec1412[1]);
			fRec1410[0] = fRec1412[0];
			double fRec1411 = fRec1414;
			fRec1409[0] = (fTemp649 + (fTemp650 + (fRec1411 + fRec1409[1])));
			fRec1407[0] = fRec1409[0];
			double fRec1408 = (fTemp649 + (fRec1411 + fTemp650));
			fRec1406[0] = (fRec1407[0] + fRec1406[1]);
			fRec1404[0] = fRec1406[0];
			double fRec1405 = fRec1408;
			double fTemp654 = (fConst230 * fRec1416[1]);
			double fTemp655 = (fConst232 * ((((0.095660903800000002 * fTemp40) + (0.045114781399999998 * fTemp44)) + (0.066569255699999996 * fTemp46)) - ((((0.058752662800000001 * fTemp41) + (0.0036296078999999998 * fTemp43)) + (0.0107201437 * fTemp45)) + (0.078853763899999998 * fTemp42))));
			double fTemp656 = (fConst233 * fRec1419[1]);
			double fTemp657 = (fConst234 * fRec1422[1]);
			fRec1424[0] = (fTemp655 + (fTemp656 + (fRec1424[1] + fTemp657)));
			fRec1422[0] = fRec1424[0];
			double fRec1423 = ((fTemp657 + fTemp656) + fTemp655);
			fRec1421[0] = (fRec1422[0] + fRec1421[1]);
			fRec1419[0] = fRec1421[0];
			double fRec1420 = fRec1423;
			fRec1418[0] = (fTemp654 + (fRec1420 + fRec1418[1]));
			fRec1416[0] = fRec1418[0];
			double fRec1417 = (fRec1420 + fTemp654);
			double fTemp658 = (fConst236 * (((0.026849912600000001 * fTemp50) + (0.080783439999999998 * fTemp52)) - (0.038109699300000001 * fTemp51)));
			double fTemp659 = (fConst237 * fRec1425[1]);
			fRec1427[0] = (fTemp658 + (fRec1427[1] + fTemp659));
			fRec1425[0] = fRec1427[0];
			double fRec1426 = (fTemp659 + fTemp658);
			double fTemp660 = (fConst239 * (((0.063454501799999993 * fTemp55) + (0.084898322999999998 * fTemp58)) - (((0.025747456500000002 * fTemp56) + (0.0264804254 * fTemp59)) + (0.077633339100000004 * fTemp57))));
			double fTemp661 = (fConst240 * fRec1428[1]);
			double fTemp662 = (fConst241 * fRec1431[1]);
			fRec1433[0] = (fTemp660 + (fTemp661 + (fRec1433[1] + fTemp662)));
			fRec1431[0] = fRec1433[0];
			double fRec1432 = ((fTemp662 + fTemp661) + fTemp660);
			fRec1430[0] = (fRec1431[0] + fRec1430[1]);
			fRec1428[0] = fRec1430[0];
			double fRec1429 = fRec1432;
			fVec29[(IOTA & 511)] = ((0.033264708800000001 * fTemp7) + (fRec1390 + (fRec1405 + (fRec1417 + (fRec1426 + fRec1429)))));
			output30[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec29[((IOTA - iConst242) & 511)])));
			double fTemp663 = (fConst184 * fRec1434[1]);
			double fTemp664 = (fConst186 * fRec1437[1]);
			double fTemp665 = (fConst187 * fRec1440[1]);
			double fTemp666 = (fConst189 * ((((0.0175372694 * fTemp19) + ((0.0259678913 * fTemp18) + ((0.031716897299999998 * fTemp12) + (0.0078482879000000005 * fTemp15)))) + (0.1082692269 * fTemp21)) - ((((((0.041924418400000003 * fTemp11) + (0.0045808914999999999 * fTemp16)) + (0.0040121705000000004 * fTemp17)) + (0.00042068200000000002 * fTemp13)) + (0.020977332099999999 * fTemp14)) + (0.10121722599999999 * fTemp20))));
			double fTemp667 = (fConst190 * fRec1443[1]);
			double fTemp668 = (fConst191 * fRec1446[1]);
			fRec1448[0] = (fTemp666 + (fTemp667 + (fRec1448[1] + fTemp668)));
			fRec1446[0] = fRec1448[0];
			double fRec1447 = ((fTemp668 + fTemp667) + fTemp666);
			fRec1445[0] = (fRec1446[0] + fRec1445[1]);
			fRec1443[0] = fRec1445[0];
			double fRec1444 = fRec1447;
			fRec1442[0] = (fTemp664 + (fTemp665 + (fRec1444 + fRec1442[1])));
			fRec1440[0] = fRec1442[0];
			double fRec1441 = (fTemp664 + (fRec1444 + fTemp665));
			fRec1439[0] = (fRec1440[0] + fRec1439[1]);
			fRec1437[0] = fRec1439[0];
			double fRec1438 = fRec1441;
			fRec1436[0] = (fTemp663 + (fRec1438 + fRec1436[1]));
			fRec1434[0] = fRec1436[0];
			double fRec1435 = (fRec1438 + fTemp663);
			double fTemp669 = (fConst193 * fRec1449[1]);
			double fTemp670 = (fConst194 * fRec1452[1]);
			double fTemp671 = (fConst196 * ((((0.0063173565999999999 * fTemp33) + ((0.043833602399999998 * fTemp32) + ((0.023924468800000001 * fTemp28) + (0.0019850127999999998 * fTemp29)))) + (0.1142230754 * fTemp35)) - ((((0.034902777900000001 * fTemp27) + (0.0012863905000000001 * fTemp30)) + (0.0033561749999999999 * fTemp31)) + (0.1031383375 * fTemp34))));
			double fTemp672 = (fConst197 * fRec1455[1]);
			double fTemp673 = (fConst198 * fRec1458[1]);
			fRec1460[0] = (fTemp671 + (fTemp672 + (fRec1460[1] + fTemp673)));
			fRec1458[0] = fRec1460[0];
			double fRec1459 = ((fTemp673 + fTemp672) + fTemp671);
			fRec1457[0] = (fRec1458[0] + fRec1457[1]);
			fRec1455[0] = fRec1457[0];
			double fRec1456 = fRec1459;
			fRec1454[0] = (fTemp669 + (fTemp670 + (fRec1456 + fRec1454[1])));
			fRec1452[0] = fRec1454[0];
			double fRec1453 = (fTemp669 + (fRec1456 + fTemp670));
			fRec1451[0] = (fRec1452[0] + fRec1451[1]);
			fRec1449[0] = fRec1451[0];
			double fRec1450 = fRec1453;
			double fTemp674 = (fConst200 * fRec1461[1]);
			double fTemp675 = (fConst202 * (((((0.0148861251 * fTemp41) + (0.00072266569999999996 * fTemp43)) + (0.045025074900000003 * fTemp44)) + (0.1137278704 * fTemp46)) - (((0.0257988961 * fTemp40) + (0.011327129 * fTemp45)) + (0.097165509999999997 * fTemp42))));
			double fTemp676 = (fConst203 * fRec1464[1]);
			double fTemp677 = (fConst204 * fRec1467[1]);
			fRec1469[0] = (fTemp675 + (fTemp676 + (fRec1469[1] + fTemp677)));
			fRec1467[0] = fRec1469[0];
			double fRec1468 = ((fTemp677 + fTemp676) + fTemp675);
			fRec1466[0] = (fRec1467[0] + fRec1466[1]);
			fRec1464[0] = fRec1466[0];
			double fRec1465 = fRec1468;
			fRec1463[0] = (fTemp674 + (fRec1465 + fRec1463[1]));
			fRec1461[0] = fRec1463[0];
			double fRec1462 = (fRec1465 + fTemp674);
			double fTemp678 = (fConst206 * ((0.084942507 * fTemp52) - ((0.0063592984000000003 * fTemp50) + (0.0381259428 * fTemp51))));
			double fTemp679 = (fConst207 * fRec1470[1]);
			fRec1472[0] = (fTemp678 + (fRec1472[1] + fTemp679));
			fRec1470[0] = fRec1472[0];
			double fRec1471 = (fTemp679 + fTemp678);
			double fTemp680 = (fConst209 * (((0.0062100437 * fTemp56) + (0.1048784839 * fTemp58)) - (((0.0157546839 * fTemp55) + (0.026477076400000001 * fTemp59)) + (0.081545686199999995 * fTemp57))));
			double fTemp681 = (fConst210 * fRec1473[1]);
			double fTemp682 = (fConst211 * fRec1476[1]);
			fRec1478[0] = (fTemp680 + (fTemp681 + (fRec1478[1] + fTemp682)));
			fRec1476[0] = fRec1478[0];
			double fRec1477 = ((fTemp682 + fTemp681) + fTemp680);
			fRec1475[0] = (fRec1476[0] + fRec1475[1]);
			fRec1473[0] = fRec1475[0];
			double fRec1474 = fRec1477;
			fVec30[(IOTA & 511)] = ((0.033288954699999998 * fTemp7) + (fRec1435 + (fRec1450 + (fRec1462 + (fRec1471 + fRec1474)))));
			output31[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec30[((IOTA - iConst212) & 511)])));
			double fTemp683 = (fConst214 * fRec1479[1]);
			double fTemp684 = (fConst216 * fRec1482[1]);
			double fTemp685 = (fConst217 * fRec1485[1]);
			double fTemp686 = (fConst219 * (((0.030380761799999999 * fTemp20) + ((0.0029530737999999999 * fTemp19) + ((0.015719100499999999 * fTemp18) + ((0.1016226001 * fTemp12) + (0.0069555950000000002 * fTemp15))))) - ((((((0.0847848977 * fTemp11) + (0.017856617299999999 * fTemp16)) + (0.021116912599999999 * fTemp17)) + (0.0034212515999999999 * fTemp13)) + (0.0209121193 * fTemp14)) + (0.079316631799999995 * fTemp21))));
			double fTemp687 = (fConst220 * fRec1488[1]);
			double fTemp688 = (fConst221 * fRec1491[1]);
			fRec1493[0] = (fTemp686 + (fTemp687 + (fRec1493[1] + fTemp688)));
			fRec1491[0] = fRec1493[0];
			double fRec1492 = ((fTemp688 + fTemp687) + fTemp686);
			fRec1490[0] = (fRec1491[0] + fRec1490[1]);
			fRec1488[0] = fRec1490[0];
			double fRec1489 = fRec1492;
			fRec1487[0] = (fTemp684 + (fTemp685 + (fRec1489 + fRec1487[1])));
			fRec1485[0] = fRec1487[0];
			double fRec1486 = (fTemp684 + (fRec1489 + fTemp685));
			fRec1484[0] = (fRec1485[0] + fRec1484[1]);
			fRec1482[0] = fRec1484[0];
			double fRec1483 = fRec1486;
			fRec1481[0] = (fTemp683 + (fRec1483 + fRec1481[1]));
			fRec1479[0] = fRec1481[0];
			double fRec1480 = (fRec1483 + fTemp683);
			double fTemp689 = (fConst223 * fRec1494[1]);
			double fTemp690 = (fConst224 * fRec1497[1]);
			double fTemp691 = (fConst226 * (((0.0037265244999999999 * fTemp33) + ((0.039366777800000002 * fTemp32) + ((0.1042477044 * fTemp28) + (0.0019129854 * fTemp29)))) - ((0.033850113299999998 * fTemp35) + ((((0.1145386578 * fTemp27) + (0.0052075050000000003 * fTemp30)) + (0.019758842499999998 * fTemp31)) + (0.018452355399999999 * fTemp34)))));
			double fTemp692 = (fConst227 * fRec1500[1]);
			double fTemp693 = (fConst228 * fRec1503[1]);
			fRec1505[0] = (fTemp691 + (fTemp692 + (fRec1505[1] + fTemp693)));
			fRec1503[0] = fRec1505[0];
			double fRec1504 = ((fTemp693 + fTemp692) + fTemp691);
			fRec1502[0] = (fRec1503[0] + fRec1502[1]);
			fRec1500[0] = fRec1502[0];
			double fRec1501 = fRec1504;
			fRec1499[0] = (fTemp689 + (fTemp690 + (fRec1501 + fRec1499[1])));
			fRec1497[0] = fRec1499[0];
			double fRec1498 = (fTemp689 + (fRec1501 + fTemp690));
			fRec1496[0] = (fRec1497[0] + fRec1496[1]);
			fRec1494[0] = fRec1496[0];
			double fRec1495 = fRec1498;
			double fTemp694 = (fConst230 * fRec1506[1]);
			double fTemp695 = (fConst232 * (((((0.078797231100000004 * fTemp41) + (0.0050690268999999998 * fTemp43)) + (0.045098519099999998 * fTemp44)) + (0.0205600427 * fTemp46)) - (((0.1147884329 * fTemp40) + (0.0102268551 * fTemp45)) + (0.058736826300000003 * fTemp42))));
			double fTemp696 = (fConst233 * fRec1509[1]);
			double fTemp697 = (fConst234 * fRec1512[1]);
			fRec1514[0] = (fTemp695 + (fTemp696 + (fRec1514[1] + fTemp697)));
			fRec1512[0] = fRec1514[0];
			double fRec1513 = ((fTemp697 + fTemp696) + fTemp695);
			fRec1511[0] = (fRec1512[0] + fRec1511[1]);
			fRec1509[0] = fRec1511[0];
			double fRec1510 = fRec1513;
			fRec1508[0] = (fTemp694 + (fRec1510 + fRec1508[1]));
			fRec1506[0] = fRec1508[0];
			double fRec1507 = (fRec1510 + fTemp694);
			double fTemp698 = (fConst236 * ((0.076140564800000005 * fTemp52) - ((0.0381565154 * fTemp50) + (0.038081240299999999 * fTemp51))));
			double fTemp699 = (fConst237 * fRec1515[1]);
			fRec1517[0] = (fTemp698 + (fRec1517[1] + fTemp699));
			fRec1515[0] = fRec1517[0];
			double fRec1516 = (fTemp699 + fTemp698);
			double fTemp700 = (fConst239 * (((0.0366610224 * fTemp56) + (0.063480344100000002 * fTemp58)) - (((0.084950796300000006 * fTemp55) + (0.0265425548 * fTemp59)) + (0.073062467300000003 * fTemp57))));
			double fTemp701 = (fConst240 * fRec1518[1]);
			double fTemp702 = (fConst241 * fRec1521[1]);
			fRec1523[0] = (fTemp700 + (fTemp701 + (fRec1523[1] + fTemp702)));
			fRec1521[0] = fRec1523[0];
			double fRec1522 = ((fTemp702 + fTemp701) + fTemp700);
			fRec1520[0] = (fRec1521[0] + fRec1520[1]);
			fRec1518[0] = fRec1520[0];
			double fRec1519 = fRec1522;
			fVec31[(IOTA & 511)] = ((0.033273105499999997 * fTemp7) + (fRec1480 + (fRec1495 + (fRec1507 + (fRec1516 + fRec1519)))));
			output32[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec31[((IOTA - iConst242) & 511)])));
			double fTemp703 = (fConst184 * fRec1524[1]);
			double fTemp704 = (fConst186 * fRec1527[1]);
			double fTemp705 = (fConst187 * fRec1530[1]);
			double fTemp706 = (fConst189 * ((((0.10625787740000001 * fTemp11) + (0.0051312151999999998 * fTemp15)) + (0.1012421013 * fTemp20)) - (((0.015667384499999999 * fTemp19) + ((((((0.0317420406 * fTemp12) + (0.0092974079000000005 * fTemp16)) + (0.025961978399999999 * fTemp17)) + (0.0057835088 * fTemp13)) + (0.020965126000000001 * fTemp14)) + (0.0040183064000000003 * fTemp18))) + (0.046719152299999997 * fTemp21))));
			double fTemp707 = (fConst190 * fRec1533[1]);
			double fTemp708 = (fConst191 * fRec1536[1]);
			fRec1538[0] = (fTemp706 + (fTemp707 + (fRec1538[1] + fTemp708)));
			fRec1536[0] = fRec1538[0];
			double fRec1537 = ((fTemp708 + fTemp707) + fTemp706);
			fRec1535[0] = (fRec1536[0] + fRec1535[1]);
			fRec1533[0] = fRec1535[0];
			double fRec1534 = fRec1537;
			fRec1532[0] = (fTemp704 + (fTemp705 + (fRec1534 + fRec1532[1])));
			fRec1530[0] = fRec1532[0];
			double fRec1531 = (fTemp704 + (fRec1534 + fTemp705));
			fRec1529[0] = (fRec1530[0] + fRec1529[1]);
			fRec1527[0] = fRec1529[0];
			double fRec1528 = fRec1531;
			fRec1526[0] = (fTemp703 + (fRec1528 + fRec1526[1]));
			fRec1524[0] = fRec1526[0];
			double fRec1525 = (fRec1528 + fTemp703);
			double fTemp709 = (fConst193 * fRec1539[1]);
			double fTemp710 = (fConst194 * fRec1542[1]);
			double fTemp711 = (fConst196 * ((((0.028648525399999999 * fTemp32) + (((0.035043847500000003 * fTemp27) + (0.056026102899999999 * fTemp28)) + (0.0019036509000000001 * fTemp29))) + (0.089895163 * fTemp34)) - ((((0.0064292795000000002 * fTemp30) + (0.033390495899999997 * fTemp31)) + (0.0012416939 * fTemp33)) + (0.1141380072 * fTemp35))));
			double fTemp712 = (fConst197 * fRec1545[1]);
			double fTemp713 = (fConst198 * fRec1548[1]);
			fRec1550[0] = (fTemp711 + (fTemp712 + (fRec1550[1] + fTemp713)));
			fRec1548[0] = fRec1550[0];
			double fRec1549 = ((fTemp713 + fTemp712) + fTemp711);
			fRec1547[0] = (fRec1548[0] + fRec1547[1]);
			fRec1545[0] = fRec1547[0];
			double fRec1546 = fRec1549;
			fRec1544[0] = (fTemp709 + (fTemp710 + (fRec1546 + fRec1544[1])));
			fRec1542[0] = fRec1544[0];
			double fRec1543 = (fTemp709 + (fRec1546 + fTemp710));
			fRec1541[0] = (fRec1542[0] + fRec1541[1]);
			fRec1539[0] = fRec1541[0];
			double fRec1540 = fRec1543;
			double fTemp714 = (fConst200 * fRec1551[1]);
			double fTemp715 = (fConst202 * (((((0.097218402800000006 * fTemp41) + (0.0084727716999999994 * fTemp43)) + (0.045056816100000001 * fTemp44)) + (0.014904769999999999 * fTemp42)) - (((0.062058498400000002 * fTemp40) + (0.0074275551000000002 * fTemp45)) + (0.098685277700000004 * fTemp46))));
			double fTemp716 = (fConst203 * fRec1554[1]);
			double fTemp717 = (fConst204 * fRec1557[1]);
			fRec1559[0] = (fTemp715 + (fTemp716 + (fRec1559[1] + fTemp717)));
			fRec1557[0] = fRec1559[0];
			double fRec1558 = ((fTemp717 + fTemp716) + fTemp715);
			fRec1556[0] = (fRec1557[0] + fRec1556[1]);
			fRec1554[0] = fRec1556[0];
			double fRec1555 = fRec1558;
			fRec1553[0] = (fTemp714 + (fRec1555 + fRec1553[1]));
			fRec1551[0] = fRec1553[0];
			double fRec1552 = (fRec1555 + fTemp714);
			double fTemp718 = (fConst206 * ((0.055534124300000001 * fTemp52) - ((0.064560003800000001 * fTemp50) + (0.038148365599999998 * fTemp51))));
			double fTemp719 = (fConst207 * fRec1560[1]);
			fRec1562[0] = (fTemp718 + (fRec1562[1] + fTemp719));
			fRec1560[0] = fRec1562[0];
			double fRec1561 = (fTemp719 + fTemp718);
			double fTemp720 = (fConst209 * ((0.062092499199999998 * fTemp56) - ((((0.1048360638 * fTemp55) + (0.026436373700000002 * fTemp59)) + (0.053295253299999998 * fTemp57)) + (0.015813225 * fTemp58))));
			double fTemp721 = (fConst210 * fRec1563[1]);
			double fTemp722 = (fConst211 * fRec1566[1]);
			fRec1568[0] = (fTemp720 + (fTemp721 + (fRec1568[1] + fTemp722)));
			fRec1566[0] = fRec1568[0];
			double fRec1567 = ((fTemp722 + fTemp721) + fTemp720);
			fRec1565[0] = (fRec1566[0] + fRec1565[1]);
			fRec1563[0] = fRec1565[0];
			double fRec1564 = fRec1567;
			fVec32[(IOTA & 511)] = ((0.0332842348 * fTemp7) + (fRec1525 + (fRec1540 + (fRec1552 + (fRec1561 + fRec1564)))));
			output33[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec32[((IOTA - iConst212) & 511)])));
			double fTemp723 = (fConst214 * fRec1569[1]);
			double fTemp724 = (fConst216 * fRec1572[1]);
			double fTemp725 = (fConst217 * fRec1575[1]);
			double fTemp726 = (fConst219 * (((((0.0038138676000000001 * fTemp11) + (0.0106130081 * fTemp16)) + (0.0024886294000000002 * fTemp15)) + (0.1160031044 * fTemp21)) - ((0.030479802600000001 * fTemp20) + ((0.014705922999999999 * fTemp19) + (((((0.1015912773 * fTemp12) + (0.015737087699999999 * fTemp17)) + (0.0073037351 * fTemp13)) + (0.020953242600000001 * fTemp14)) + (0.021115635600000002 * fTemp18))))));
			double fTemp727 = (fConst220 * fRec1578[1]);
			double fTemp728 = (fConst221 * fRec1581[1]);
			fRec1583[0] = (fTemp726 + (fTemp727 + (fRec1583[1] + fTemp728)));
			fRec1581[0] = fRec1583[0];
			double fRec1582 = ((fTemp728 + fTemp727) + fTemp726);
			fRec1580[0] = (fRec1581[0] + fRec1580[1]);
			fRec1578[0] = fRec1580[0];
			double fRec1579 = fRec1582;
			fRec1577[0] = (fTemp724 + (fTemp725 + (fRec1579 + fRec1577[1])));
			fRec1575[0] = fRec1577[0];
			double fRec1576 = (fTemp724 + (fRec1579 + fTemp725));
			fRec1574[0] = (fRec1575[0] + fRec1574[1]);
			fRec1572[0] = fRec1574[0];
			double fRec1573 = fRec1576;
			fRec1571[0] = (fTemp723 + (fRec1573 + fRec1571[1]));
			fRec1569[0] = fRec1571[0];
			double fRec1570 = (fRec1573 + fTemp723);
			double fTemp729 = (fConst223 * fRec1584[1]);
			double fTemp730 = (fConst224 * fRec1587[1]);
			double fTemp731 = (fConst226 * (((0.033897464600000003 * fTemp35) + (((0.013863962699999999 * fTemp32) + ((0.1144869867 * fTemp27) + (0.0019124491999999999 * fTemp29))) + (0.086714518700000007 * fTemp34))) - ((((0.060743407399999998 * fTemp28) + (0.0037140712999999999 * fTemp30)) + (0.041807355900000003 * fTemp31)) + (0.0052659958000000002 * fTemp33))));
			double fTemp732 = (fConst227 * fRec1590[1]);
			double fTemp733 = (fConst228 * fRec1593[1]);
			fRec1595[0] = (fTemp731 + (fTemp732 + (fRec1595[1] + fTemp733)));
			fRec1593[0] = fRec1595[0];
			double fRec1594 = ((fTemp733 + fTemp732) + fTemp731);
			fRec1592[0] = (fRec1593[0] + fRec1592[1]);
			fRec1590[0] = fRec1592[0];
			double fRec1591 = fRec1594;
			fRec1589[0] = (fTemp729 + (fTemp730 + (fRec1591 + fRec1589[1])));
			fRec1587[0] = fRec1589[0];
			double fRec1588 = (fTemp729 + (fRec1591 + fTemp730));
			fRec1586[0] = (fRec1587[0] + fRec1586[1]);
			fRec1584[0] = fRec1586[0];
			double fRec1585 = fRec1588;
			double fTemp734 = (fConst230 * fRec1596[1]);
			double fTemp735 = (fConst232 * ((((((0.066656725400000005 * fTemp40) + (0.058691351000000003 * fTemp41)) + (0.0107694785 * fTemp43)) + (0.045080427800000003 * fTemp44)) + (0.078843311299999996 * fTemp42)) - ((0.0036500515999999998 * fTemp45) + (0.095647291300000006 * fTemp46))));
			double fTemp736 = (fConst233 * fRec1599[1]);
			double fTemp737 = (fConst234 * fRec1602[1]);
			fRec1604[0] = (fTemp735 + (fTemp736 + (fRec1604[1] + fTemp737)));
			fRec1602[0] = fRec1604[0];
			double fRec1603 = ((fTemp737 + fTemp736) + fTemp735);
			fRec1601[0] = (fRec1602[0] + fRec1601[1]);
			fRec1599[0] = fRec1601[0];
			double fRec1600 = fRec1603;
			fRec1598[0] = (fTemp734 + (fRec1600 + fRec1598[1]));
			fRec1596[0] = fRec1598[0];
			double fRec1597 = (fRec1600 + fTemp734);
			double fTemp738 = (fConst236 * ((0.026835694399999999 * fTemp52) - ((0.080811546499999998 * fTemp50) + (0.0380982391 * fTemp51))));
			double fTemp739 = (fConst237 * fRec1605[1]);
			fRec1607[0] = (fTemp738 + (fRec1607[1] + fTemp739));
			fRec1605[0] = fRec1607[0];
			double fRec1606 = (fTemp739 + fTemp738);
			double fTemp740 = (fConst239 * ((0.0776089425 * fTemp56) - ((((0.063432372299999998 * fTemp55) + (0.026503915499999999 * fTemp59)) + (0.0257158291 * fTemp57)) + (0.084954703100000001 * fTemp58))));
			double fTemp741 = (fConst240 * fRec1608[1]);
			double fTemp742 = (fConst241 * fRec1611[1]);
			fRec1613[0] = (fTemp740 + (fTemp741 + (fRec1613[1] + fTemp742)));
			fRec1611[0] = fRec1613[0];
			double fRec1612 = ((fTemp742 + fTemp741) + fTemp740);
			fRec1610[0] = (fRec1611[0] + fRec1610[1]);
			fRec1608[0] = fRec1610[0];
			double fRec1609 = fRec1612;
			fVec33[(IOTA & 511)] = ((0.033272114499999998 * fTemp7) + (fRec1570 + (fRec1585 + (fRec1597 + (fRec1606 + fRec1609)))));
			output34[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec33[((IOTA - iConst242) & 511)])));
			double fTemp743 = (fConst184 * fRec1614[1]);
			double fTemp744 = (fConst186 * fRec1617[1]);
			double fTemp745 = (fConst187 * fRec1620[1]);
			double fTemp746 = (fConst189 * (((((0.031650208800000003 * fTemp12) + (0.017592697000000001 * fTemp16)) + (0.0040021539000000004 * fTemp17)) + (0.0045475836999999998 * fTemp19)) - ((0.041919655299999997 * fTemp21) + (((0.0259878066 * fTemp18) + ((0.0004232808 * fTemp15) + (((0.1082578573 * fTemp11) + (0.0076914011000000001 * fTemp13)) + (0.020914834300000001 * fTemp14)))) + (0.1012375878 * fTemp20)))));
			double fTemp747 = (fConst190 * fRec1623[1]);
			double fTemp748 = (fConst191 * fRec1626[1]);
			fRec1628[0] = (fTemp746 + (fTemp747 + (fRec1628[1] + fTemp748)));
			fRec1626[0] = fRec1628[0];
			double fRec1627 = ((fTemp748 + fTemp747) + fTemp746);
			fRec1625[0] = (fRec1626[0] + fRec1625[1]);
			fRec1623[0] = fRec1625[0];
			double fRec1624 = fRec1627;
			fRec1622[0] = (fTemp744 + (fTemp745 + (fRec1624 + fRec1622[1])));
			fRec1620[0] = fRec1622[0];
			double fRec1621 = (fTemp744 + (fRec1624 + fTemp745));
			fRec1619[0] = (fRec1620[0] + fRec1619[1]);
			fRec1617[0] = fRec1619[0];
			double fRec1618 = fRec1621;
			fRec1616[0] = (fTemp743 + (fRec1618 + fRec1616[1]));
			fRec1614[0] = fRec1616[0];
			double fRec1615 = (fRec1618 + fTemp743);
			double fTemp749 = (fConst193 * fRec1629[1]);
			double fTemp750 = (fConst194 * fRec1632[1]);
			double fTemp751 = (fConst196 * ((((0.0012697062000000001 * fTemp30) + (0.0018758177999999999 * fTemp29)) + (0.1142017021 * fTemp35)) - ((0.023872140600000001 * fTemp34) + ((0.0063737823000000002 * fTemp33) + ((((0.034883829399999997 * fTemp27) + (0.1031606028 * fTemp28)) + (0.043886616099999998 * fTemp31)) + (0.0033480034000000001 * fTemp32))))));
			double fTemp752 = (fConst197 * fRec1635[1]);
			double fTemp753 = (fConst198 * fRec1638[1]);
			fRec1640[0] = (fTemp751 + (fTemp752 + (fRec1640[1] + fTemp753)));
			fRec1638[0] = fRec1640[0];
			double fRec1639 = ((fTemp753 + fTemp752) + fTemp751);
			fRec1637[0] = (fRec1638[0] + fRec1637[1]);
			fRec1635[0] = fRec1637[0];
			double fRec1636 = fRec1639;
			fRec1634[0] = (fTemp749 + (fTemp750 + (fRec1636 + fRec1634[1])));
			fRec1632[0] = fRec1634[0];
			double fRec1633 = (fTemp749 + (fRec1636 + fTemp750));
			fRec1631[0] = (fRec1632[0] + fRec1631[1]);
			fRec1629[0] = fRec1631[0];
			double fRec1630 = fRec1633;
			double fTemp754 = (fConst200 * fRec1641[1]);
			double fTemp755 = (fConst202 * (((0.025776243099999999 * fTemp46) + ((0.097185107199999995 * fTemp42) + ((((0.1137008253 * fTemp40) + (0.011294923700000001 * fTemp43)) + (0.045081476199999998 * fTemp44)) + (0.00072731870000000004 * fTemp45)))) - (0.014852952799999999 * fTemp41)));
			double fTemp756 = (fConst203 * fRec1644[1]);
			double fTemp757 = (fConst204 * fRec1647[1]);
			fRec1649[0] = (fTemp755 + (fTemp756 + (fRec1649[1] + fTemp757)));
			fRec1647[0] = fRec1649[0];
			double fRec1648 = ((fTemp757 + fTemp756) + fTemp755);
			fRec1646[0] = (fRec1647[0] + fRec1646[1]);
			fRec1644[0] = fRec1646[0];
			double fRec1645 = fRec1648;
			fRec1643[0] = (fTemp754 + (fRec1645 + fRec1643[1]));
			fRec1641[0] = fRec1643[0];
			double fRec1642 = (fRec1645 + fTemp754);
			double fTemp758 = (fConst206 * (0.0 - (((0.0849192104 * fTemp50) + (0.0381146708 * fTemp51)) + (0.0063509984000000002 * fTemp52))));
			double fTemp759 = (fConst207 * fRec1650[1]);
			fRec1652[0] = (fTemp758 + (fRec1652[1] + fTemp759));
			fRec1650[0] = fRec1652[0];
			double fRec1651 = (fTemp759 + fTemp758);
			double fTemp760 = (fConst209 * ((((0.015736912499999998 * fTemp55) + (0.081553025599999995 * fTemp56)) + (0.0061961741999999997 * fTemp57)) - ((0.0264817496 * fTemp59) + (0.1048513973 * fTemp58))));
			double fTemp761 = (fConst210 * fRec1653[1]);
			double fTemp762 = (fConst211 * fRec1656[1]);
			fRec1658[0] = (fTemp760 + (fTemp761 + (fRec1658[1] + fTemp762)));
			fRec1656[0] = fRec1658[0];
			double fRec1657 = ((fTemp762 + fTemp761) + fTemp760);
			fRec1655[0] = (fRec1656[0] + fRec1655[1]);
			fRec1653[0] = fRec1655[0];
			double fRec1654 = fRec1657;
			fVec34[(IOTA & 511)] = ((0.033276484600000003 * fTemp7) + (fRec1615 + (fRec1630 + (fRec1642 + (fRec1651 + fRec1654)))));
			output35[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec34[((IOTA - iConst212) & 511)])));
			double fTemp763 = (fConst214 * fRec1659[1]);
			double fTemp764 = (fConst216 * fRec1662[1]);
			double fTemp765 = (fConst217 * fRec1665[1]);
			double fTemp766 = (fConst219 * (((0.0303990396 * fTemp20) + (((((0.079335644999999996 * fTemp11) + (0.10163163460000001 * fTemp12)) + (0.0029942836000000001 * fTemp16)) + (0.021145309399999999 * fTemp17)) + (0.0178785105 * fTemp19))) - (((0.015704019900000001 * fTemp18) + ((0.0034303630000000001 * fTemp15) + ((0.0069542991999999998 * fTemp13) + (0.0209735411 * fTemp14)))) + (0.084753137199999995 * fTemp21))));
			double fTemp767 = (fConst220 * fRec1668[1]);
			double fTemp768 = (fConst221 * fRec1671[1]);
			fRec1673[0] = (fTemp766 + (fTemp767 + (fRec1673[1] + fTemp768)));
			fRec1671[0] = fRec1673[0];
			double fRec1672 = ((fTemp768 + fTemp767) + fTemp766);
			fRec1670[0] = (fRec1671[0] + fRec1670[1]);
			fRec1668[0] = fRec1670[0];
			double fRec1669 = fRec1672;
			fRec1667[0] = (fTemp764 + (fTemp765 + (fRec1669 + fRec1667[1])));
			fRec1665[0] = fRec1667[0];
			double fRec1666 = (fTemp764 + (fRec1669 + fTemp765));
			fRec1664[0] = (fRec1665[0] + fRec1664[1]);
			fRec1662[0] = fRec1664[0];
			double fRec1663 = fRec1666;
			fRec1661[0] = (fTemp763 + (fRec1663 + fRec1661[1]));
			fRec1659[0] = fRec1661[0];
			double fRec1660 = (fRec1663 + fTemp763);
			double fTemp769 = (fConst223 * fRec1674[1]);
			double fTemp770 = (fConst224 * fRec1677[1]);
			double fTemp771 = (fConst226 * (((0.0052216312999999997 * fTemp30) + (0.0019288978 * fTemp29)) - ((0.0338739947 * fTemp35) + ((0.1042714064 * fTemp34) + ((0.0037685707 * fTemp33) + ((((0.1145178768 * fTemp27) + (0.018450642699999999 * fTemp28)) + (0.039361826699999998 * fTemp31)) + (0.019766645699999998 * fTemp32)))))));
			double fTemp772 = (fConst227 * fRec1680[1]);
			double fTemp773 = (fConst228 * fRec1683[1]);
			fRec1685[0] = (fTemp771 + (fTemp772 + (fRec1685[1] + fTemp773)));
			fRec1683[0] = fRec1685[0];
			double fRec1684 = ((fTemp773 + fTemp772) + fTemp771);
			fRec1682[0] = (fRec1683[0] + fRec1682[1]);
			fRec1680[0] = fRec1682[0];
			double fRec1681 = fRec1684;
			fRec1679[0] = (fTemp769 + (fTemp770 + (fRec1681 + fRec1679[1])));
			fRec1677[0] = fRec1679[0];
			double fRec1678 = (fTemp769 + (fRec1681 + fTemp770));
			fRec1676[0] = (fRec1677[0] + fRec1676[1]);
			fRec1674[0] = fRec1676[0];
			double fRec1675 = fRec1678;
			double fTemp774 = (fConst230 * fRec1686[1]);
			double fTemp775 = (fConst232 * (((0.11477953809999999 * fTemp46) + ((0.058753453300000001 * fTemp42) + ((((0.0205387338 * fTemp40) + (0.010182545499999999 * fTemp43)) + (0.0450816551 * fTemp44)) + (0.0050588908000000002 * fTemp45)))) - (0.078819765700000002 * fTemp41)));
			double fTemp776 = (fConst233 * fRec1689[1]);
			double fTemp777 = (fConst234 * fRec1692[1]);
			fRec1694[0] = (fTemp775 + (fTemp776 + (fRec1694[1] + fTemp777)));
			fRec1692[0] = fRec1694[0];
			double fRec1693 = ((fTemp777 + fTemp776) + fTemp775);
			fRec1691[0] = (fRec1692[0] + fRec1691[1]);
			fRec1689[0] = fRec1691[0];
			double fRec1690 = fRec1693;
			fRec1688[0] = (fTemp774 + (fRec1690 + fRec1688[1]));
			fRec1686[0] = fRec1688[0];
			double fRec1687 = (fRec1690 + fTemp774);
			double fTemp778 = (fConst236 * (0.0 - (((0.076137318100000004 * fTemp50) + (0.0381082248 * fTemp51)) + (0.038158428899999999 * fTemp52))));
			double fTemp779 = (fConst237 * fRec1695[1]);
			fRec1697[0] = (fTemp778 + (fRec1697[1] + fTemp779));
			fRec1695[0] = fRec1697[0];
			double fRec1696 = (fTemp779 + fTemp778);
			double fTemp780 = (fConst239 * ((((0.084949829399999996 * fTemp55) + (0.073090824900000004 * fTemp56)) + (0.036674009200000003 * fTemp57)) - ((0.026502758899999999 * fTemp59) + (0.063467089099999999 * fTemp58))));
			double fTemp781 = (fConst240 * fRec1698[1]);
			double fTemp782 = (fConst241 * fRec1701[1]);
			fRec1703[0] = (fTemp780 + (fTemp781 + (fRec1703[1] + fTemp782)));
			fRec1701[0] = fRec1703[0];
			double fRec1702 = ((fTemp782 + fTemp781) + fTemp780);
			fRec1700[0] = (fRec1701[0] + fRec1700[1]);
			fRec1698[0] = fRec1700[0];
			double fRec1699 = fRec1702;
			fVec35[(IOTA & 511)] = ((0.033278067699999997 * fTemp7) + (fRec1660 + (fRec1675 + (fRec1687 + (fRec1696 + fRec1699)))));
			output36[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec35[((IOTA - iConst242) & 511)])));
			double fTemp783 = (fConst184 * fRec1704[1]);
			double fTemp784 = (fConst186 * fRec1707[1]);
			double fTemp785 = (fConst187 * fRec1710[1]);
			double fTemp786 = (fConst189 * (((0.1062583351 * fTemp21) + ((0.10123153999999999 * fTemp20) + ((0.0092629765000000006 * fTemp19) + (((0.046837363100000001 * fTemp11) + (0.025946591099999999 * fTemp17)) + (0.0040276803000000002 * fTemp18))))) - ((0.0057918522000000002 * fTemp15) + ((((0.031683004600000002 * fTemp12) + (0.015634270499999998 * fTemp16)) + (0.0051694970999999999 * fTemp13)) + (0.020943918200000002 * fTemp14)))));
			double fTemp787 = (fConst190 * fRec1713[1]);
			double fTemp788 = (fConst191 * fRec1716[1]);
			fRec1718[0] = (fTemp786 + (fTemp787 + (fRec1718[1] + fTemp788)));
			fRec1716[0] = fRec1718[0];
			double fRec1717 = ((fTemp788 + fTemp787) + fTemp786);
			fRec1715[0] = (fRec1716[0] + fRec1715[1]);
			fRec1713[0] = fRec1715[0];
			double fRec1714 = fRec1717;
			fRec1712[0] = (fTemp784 + (fTemp785 + (fRec1714 + fRec1712[1])));
			fRec1710[0] = fRec1712[0];
			double fRec1711 = (fTemp784 + (fRec1714 + fTemp785));
			fRec1709[0] = (fRec1710[0] + fRec1709[1]);
			fRec1707[0] = fRec1709[0];
			double fRec1708 = fRec1711;
			fRec1706[0] = (fTemp783 + (fRec1708 + fRec1706[1]));
			fRec1704[0] = fRec1706[0];
			double fRec1705 = (fRec1708 + fTemp783);
			double fTemp789 = (fConst193 * fRec1719[1]);
			double fTemp790 = (fConst194 * fRec1722[1]);
			double fTemp791 = (fConst196 * ((((((0.034963300500000002 * fTemp27) + (0.089837350799999993 * fTemp28)) + (0.0063732414999999997 * fTemp30)) + (0.0019300965 * fTemp29)) + (0.0012383120999999999 * fTemp33)) - ((0.114204951 * fTemp35) + (((0.0286306445 * fTemp31) + (0.033378283699999997 * fTemp32)) + (0.056046316999999998 * fTemp34)))));
			double fTemp792 = (fConst197 * fRec1725[1]);
			double fTemp793 = (fConst198 * fRec1728[1]);
			fRec1730[0] = (fTemp791 + (fTemp792 + (fRec1730[1] + fTemp793)));
			fRec1728[0] = fRec1730[0];
			double fRec1729 = ((fTemp793 + fTemp792) + fTemp791);
			fRec1727[0] = (fRec1728[0] + fRec1727[1]);
			fRec1725[0] = fRec1727[0];
			double fRec1726 = fRec1729;
			fRec1724[0] = (fTemp789 + (fTemp790 + (fRec1726 + fRec1724[1])));
			fRec1722[0] = fRec1724[0];
			double fRec1723 = (fTemp789 + (fRec1726 + fTemp790));
			fRec1721[0] = (fRec1722[0] + fRec1721[1]);
			fRec1719[0] = fRec1721[0];
			double fRec1720 = fRec1723;
			double fTemp794 = (fConst200 * fRec1731[1]);
			double fTemp795 = (fConst202 * (((((0.0074615742000000004 * fTemp43) + (0.045040590800000002 * fTemp44)) + (0.0085114636999999993 * fTemp45)) + (0.062137674699999999 * fTemp46)) - (((0.098670418100000004 * fTemp40) + (0.097180163299999997 * fTemp41)) + (0.014864069800000001 * fTemp42))));
			double fTemp796 = (fConst203 * fRec1734[1]);
			double fTemp797 = (fConst204 * fRec1737[1]);
			fRec1739[0] = (fTemp795 + (fTemp796 + (fRec1739[1] + fTemp797)));
			fRec1737[0] = fRec1739[0];
			double fRec1738 = ((fTemp797 + fTemp796) + fTemp795);
			fRec1736[0] = (fRec1737[0] + fRec1736[1]);
			fRec1734[0] = fRec1736[0];
			double fRec1735 = fRec1738;
			fRec1733[0] = (fTemp794 + (fRec1735 + fRec1733[1]));
			fRec1731[0] = fRec1733[0];
			double fRec1732 = (fRec1735 + fTemp794);
			double fTemp798 = (fConst206 * (0.0 - (((0.055553733899999999 * fTemp50) + (0.038125752300000003 * fTemp51)) + (0.064552007999999994 * fTemp52))));
			double fTemp799 = (fConst207 * fRec1740[1]);
			fRec1742[0] = (fTemp798 + (fRec1742[1] + fTemp799));
			fRec1740[0] = fRec1742[0];
			double fRec1741 = (fTemp799 + fTemp798);
			double fTemp800 = (fConst209 * (((((0.1048604267 * fTemp55) + (0.0532821084 * fTemp56)) + (0.062049975399999999 * fTemp57)) + (0.015769035099999999 * fTemp58)) - (0.026465696600000001 * fTemp59)));
			double fTemp801 = (fConst210 * fRec1743[1]);
			double fTemp802 = (fConst211 * fRec1746[1]);
			fRec1748[0] = (fTemp800 + (fTemp801 + (fRec1748[1] + fTemp802)));
			fRec1746[0] = fRec1748[0];
			double fRec1747 = ((fTemp802 + fTemp801) + fTemp800);
			fRec1745[0] = (fRec1746[0] + fRec1745[1]);
			fRec1743[0] = fRec1745[0];
			double fRec1744 = fRec1747;
			fVec36[(IOTA & 511)] = ((0.033283175399999997 * fTemp7) + (fRec1705 + (fRec1720 + (fRec1732 + (fRec1741 + fRec1744)))));
			output37[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec36[((IOTA - iConst212) & 511)])));
			double fTemp803 = (fConst214 * fRec1749[1]);
			double fTemp804 = (fConst216 * fRec1752[1]);
			double fTemp805 = (fConst217 * fRec1755[1]);
			double fTemp806 = (fConst219 * ((((0.015761323599999998 * fTemp17) + (0.0211084481 * fTemp18)) + (0.0038560119000000002 * fTemp21)) - ((0.030452232900000001 * fTemp20) + (((0.0072634246999999999 * fTemp15) + (((((0.11599028290000001 * fTemp11) + (0.1016397165 * fTemp12)) + (0.0147558584 * fTemp16)) + (0.0024743522 * fTemp13)) + (0.020954784000000001 * fTemp14))) + (0.010654657 * fTemp19)))));
			double fTemp807 = (fConst220 * fRec1758[1]);
			double fTemp808 = (fConst221 * fRec1761[1]);
			fRec1763[0] = (fTemp806 + (fTemp807 + (fRec1763[1] + fTemp808)));
			fRec1761[0] = fRec1763[0];
			double fRec1762 = ((fTemp808 + fTemp807) + fTemp806);
			fRec1760[0] = (fRec1761[0] + fRec1760[1]);
			fRec1758[0] = fRec1760[0];
			double fRec1759 = fRec1762;
			fRec1757[0] = (fTemp804 + (fTemp805 + (fRec1759 + fRec1757[1])));
			fRec1755[0] = fRec1757[0];
			double fRec1756 = (fTemp804 + (fRec1759 + fTemp805));
			fRec1754[0] = (fRec1755[0] + fRec1754[1]);
			fRec1752[0] = fRec1754[0];
			double fRec1753 = fRec1756;
			fRec1751[0] = (fTemp803 + (fRec1753 + fRec1751[1]));
			fRec1749[0] = fRec1751[0];
			double fRec1750 = (fRec1753 + fTemp803);
			double fTemp809 = (fConst223 * fRec1764[1]);
			double fTemp810 = (fConst224 * fRec1767[1]);
			double fTemp811 = (fConst226 * (((0.033852430099999997 * fTemp35) + ((0.060739800199999999 * fTemp34) + (((((0.11446973990000001 * fTemp27) + (0.086762481799999999 * fTemp28)) + (0.0037495468000000001 * fTemp30)) + (0.0018638532 * fTemp29)) + (0.0053231116000000004 * fTemp33)))) - ((0.0138807103 * fTemp31) + (0.041821141300000003 * fTemp32))));
			double fTemp812 = (fConst227 * fRec1770[1]);
			double fTemp813 = (fConst228 * fRec1773[1]);
			fRec1775[0] = (fTemp811 + (fTemp812 + (fRec1775[1] + fTemp813)));
			fRec1773[0] = fRec1775[0];
			double fRec1774 = ((fTemp813 + fTemp812) + fTemp811);
			fRec1772[0] = (fRec1773[0] + fRec1772[1]);
			fRec1770[0] = fRec1772[0];
			double fRec1771 = fRec1774;
			fRec1769[0] = (fTemp809 + (fTemp810 + (fRec1771 + fRec1769[1])));
			fRec1767[0] = fRec1769[0];
			double fRec1768 = (fTemp809 + (fRec1771 + fTemp810));
			fRec1766[0] = (fRec1767[0] + fRec1766[1]);
			fRec1764[0] = fRec1766[0];
			double fRec1765 = fRec1768;
			double fTemp814 = (fConst230 * fRec1776[1]);
			double fTemp815 = (fConst232 * ((((0.0036356788000000001 * fTemp43) + (0.045101522499999998 * fTemp44)) + (0.010711261600000001 * fTemp45)) - ((0.066610599300000004 * fTemp46) + (((0.095632831200000004 * fTemp40) + (0.058725648499999998 * fTemp41)) + (0.078858663800000006 * fTemp42)))));
			double fTemp816 = (fConst233 * fRec1779[1]);
			double fTemp817 = (fConst234 * fRec1782[1]);
			fRec1784[0] = (fTemp815 + (fTemp816 + (fRec1784[1] + fTemp817)));
			fRec1782[0] = fRec1784[0];
			double fRec1783 = ((fTemp817 + fTemp816) + fTemp815);
			fRec1781[0] = (fRec1782[0] + fRec1781[1]);
			fRec1779[0] = fRec1781[0];
			double fRec1780 = fRec1783;
			fRec1778[0] = (fTemp814 + (fRec1780 + fRec1778[1]));
			fRec1776[0] = fRec1778[0];
			double fRec1777 = (fRec1780 + fTemp814);
			double fTemp818 = (fConst236 * (0.0 - (((0.026833309999999999 * fTemp50) + (0.038106907000000002 * fTemp51)) + (0.080781548600000003 * fTemp52))));
			double fTemp819 = (fConst237 * fRec1785[1]);
			fRec1787[0] = (fTemp818 + (fRec1787[1] + fTemp819));
			fRec1785[0] = fRec1787[0];
			double fRec1786 = (fTemp819 + fTemp818);
			double fTemp820 = (fConst239 * (((((0.063424460899999993 * fTemp55) + (0.025729977300000002 * fTemp56)) + (0.077630167700000002 * fTemp57)) + (0.084913400999999999 * fTemp58)) - (0.0264737523 * fTemp59)));
			double fTemp821 = (fConst240 * fRec1788[1]);
			double fTemp822 = (fConst241 * fRec1791[1]);
			fRec1793[0] = (fTemp820 + (fTemp821 + (fRec1793[1] + fTemp822)));
			fRec1791[0] = fRec1793[0];
			double fRec1792 = ((fTemp822 + fTemp821) + fTemp820);
			fRec1790[0] = (fRec1791[0] + fRec1790[1]);
			fRec1788[0] = fRec1790[0];
			double fRec1789 = fRec1792;
			fVec37[(IOTA & 511)] = ((0.033262025000000001 * fTemp7) + (fRec1750 + (fRec1765 + (fRec1777 + (fRec1786 + fRec1789)))));
			output38[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec37[((IOTA - iConst242) & 511)])));
			double fTemp823 = (fConst184 * fRec1794[1]);
			double fTemp824 = (fConst186 * fRec1797[1]);
			double fTemp825 = (fConst187 * fRec1800[1]);
			double fTemp826 = (fConst189 * ((((((0.0420065705 * fTemp11) + (0.031734005400000001 * fTemp12)) + (0.0045288018999999997 * fTemp16)) + (0.0004477571 * fTemp13)) + (0.025992383500000001 * fTemp18)) - ((0.1082450573 * fTemp21) + ((0.1012038358 * fTemp20) + (((0.0078250448 * fTemp15) + ((0.0040178536999999999 * fTemp17) + (0.020957919299999999 * fTemp14))) + (0.0175188184 * fTemp19))))));
			double fTemp827 = (fConst190 * fRec1803[1]);
			double fTemp828 = (fConst191 * fRec1806[1]);
			fRec1808[0] = (fTemp826 + (fTemp827 + (fRec1808[1] + fTemp828)));
			fRec1806[0] = fRec1808[0];
			double fRec1807 = ((fTemp828 + fTemp827) + fTemp826);
			fRec1805[0] = (fRec1806[0] + fRec1805[1]);
			fRec1803[0] = fRec1805[0];
			double fRec1804 = fRec1807;
			fRec1802[0] = (fTemp824 + (fTemp825 + (fRec1804 + fRec1802[1])));
			fRec1800[0] = fRec1802[0];
			double fRec1801 = (fTemp824 + (fRec1804 + fTemp825));
			fRec1799[0] = (fRec1800[0] + fRec1799[1]);
			fRec1797[0] = fRec1799[0];
			double fRec1798 = fRec1801;
			fRec1796[0] = (fTemp823 + (fRec1798 + fRec1796[1]));
			fRec1794[0] = fRec1796[0];
			double fRec1795 = (fRec1798 + fTemp823);
			double fTemp829 = (fConst193 * fRec1809[1]);
			double fTemp830 = (fConst194 * fRec1812[1]);
			double fTemp831 = (fConst196 * (((0.11421576949999999 * fTemp35) + ((0.1031277446 * fTemp34) + (((0.0033561705000000001 * fTemp31) + (0.0019767729999999998 * fTemp29)) + (0.0062842743 * fTemp33)))) - ((((0.034976159299999997 * fTemp27) + (0.0239379552 * fTemp28)) + (0.0012555685 * fTemp30)) + (0.043866424299999998 * fTemp32))));
			double fTemp832 = (fConst197 * fRec1815[1]);
			double fTemp833 = (fConst198 * fRec1818[1]);
			fRec1820[0] = (fTemp831 + (fTemp832 + (fRec1820[1] + fTemp833)));
			fRec1818[0] = fRec1820[0];
			double fRec1819 = ((fTemp833 + fTemp832) + fTemp831);
			fRec1817[0] = (fRec1818[0] + fRec1817[1]);
			fRec1815[0] = fRec1817[0];
			double fRec1816 = fRec1819;
			fRec1814[0] = (fTemp829 + (fTemp830 + (fRec1816 + fRec1814[1])));
			fRec1812[0] = fRec1814[0];
			double fRec1813 = (fTemp829 + (fRec1816 + fTemp830));
			fRec1811[0] = (fRec1812[0] + fRec1811[1]);
			fRec1809[0] = fRec1811[0];
			double fRec1810 = fRec1813;
			double fTemp834 = (fConst200 * fRec1821[1]);
			double fTemp835 = (fConst202 * (((((0.025854279399999999 * fTemp40) + (0.0148955627 * fTemp41)) + (0.045049513100000001 * fTemp44)) + (0.0113706473 * fTemp45)) - ((0.11373347 * fTemp46) + ((0.00073515950000000005 * fTemp43) + (0.097154645900000003 * fTemp42)))));
			double fTemp836 = (fConst203 * fRec1824[1]);
			double fTemp837 = (fConst204 * fRec1827[1]);
			fRec1829[0] = (fTemp835 + (fTemp836 + (fRec1829[1] + fTemp837)));
			fRec1827[0] = fRec1829[0];
			double fRec1828 = ((fTemp837 + fTemp836) + fTemp835);
			fRec1826[0] = (fRec1827[0] + fRec1826[1]);
			fRec1824[0] = fRec1826[0];
			double fRec1825 = fRec1828;
			fRec1823[0] = (fTemp834 + (fRec1825 + fRec1823[1]));
			fRec1821[0] = fRec1823[0];
			double fRec1822 = (fRec1825 + fTemp834);
			double fTemp838 = (fConst206 * ((0.0063723464999999998 * fTemp50) - ((0.038111018900000002 * fTemp51) + (0.084951557600000005 * fTemp52))));
			double fTemp839 = (fConst207 * fRec1830[1]);
			fRec1832[0] = (fTemp838 + (fRec1832[1] + fTemp839));
			fRec1830[0] = fRec1832[0];
			double fRec1831 = (fTemp839 + fTemp838);
			double fTemp840 = (fConst209 * (((0.081531368000000007 * fTemp57) + (0.1048899032 * fTemp58)) - (((0.015788099199999999 * fTemp55) + (0.0062148454000000002 * fTemp56)) + (0.026511586 * fTemp59))));
			double fTemp841 = (fConst210 * fRec1833[1]);
			double fTemp842 = (fConst211 * fRec1836[1]);
			fRec1838[0] = (fTemp840 + (fTemp841 + (fRec1838[1] + fTemp842)));
			fRec1836[0] = fRec1838[0];
			double fRec1837 = ((fTemp842 + fTemp841) + fTemp840);
			fRec1835[0] = (fRec1836[0] + fRec1835[1]);
			fRec1833[0] = fRec1835[0];
			double fRec1834 = fRec1837;
			fVec38[(IOTA & 511)] = ((0.033288936200000001 * fTemp7) + (fRec1795 + (fRec1810 + (fRec1822 + (fRec1831 + fRec1834)))));
			output39[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec38[((IOTA - iConst212) & 511)])));
			double fTemp843 = (fConst214 * fRec1839[1]);
			double fTemp844 = (fConst216 * fRec1842[1]);
			double fTemp845 = (fConst217 * fRec1845[1]);
			double fTemp846 = (fConst219 * (((0.079312063700000004 * fTemp21) + ((((((0.084794564599999997 * fTemp11) + (0.10161841420000001 * fTemp12)) + (0.017872488999999998 * fTemp16)) + (0.0034022102000000002 * fTemp13)) + (0.0156948461 * fTemp18)) + (0.0304225828 * fTemp20))) - (((0.0069500370000000001 * fTemp15) + ((0.0211301287 * fTemp17) + (0.020923185600000001 * fTemp14))) + (0.0029388359999999998 * fTemp19))));
			double fTemp847 = (fConst220 * fRec1848[1]);
			double fTemp848 = (fConst221 * fRec1851[1]);
			fRec1853[0] = (fTemp846 + (fTemp847 + (fRec1853[1] + fTemp848)));
			fRec1851[0] = fRec1853[0];
			double fRec1852 = ((fTemp848 + fTemp847) + fTemp846);
			fRec1850[0] = (fRec1851[0] + fRec1850[1]);
			fRec1848[0] = fRec1850[0];
			double fRec1849 = fRec1852;
			fRec1847[0] = (fTemp844 + (fTemp845 + (fRec1849 + fRec1847[1])));
			fRec1845[0] = fRec1847[0];
			double fRec1846 = (fTemp844 + (fRec1849 + fTemp845));
			fRec1844[0] = (fRec1845[0] + fRec1844[1]);
			fRec1842[0] = fRec1844[0];
			double fRec1843 = fRec1846;
			fRec1841[0] = (fTemp843 + (fRec1843 + fRec1841[1]));
			fRec1839[0] = fRec1841[0];
			double fRec1840 = (fRec1843 + fTemp843);
			double fTemp849 = (fConst223 * fRec1854[1]);
			double fTemp850 = (fConst224 * fRec1857[1]);
			double fTemp851 = (fConst226 * (((0.018425521800000001 * fTemp34) + (((0.0197700858 * fTemp31) + (0.0019149748999999999 * fTemp29)) + (0.0037344672000000001 * fTemp33))) - (((((0.11453679059999999 * fTemp27) + (0.1042617341 * fTemp28)) + (0.0052292166999999999 * fTemp30)) + (0.039355786099999998 * fTemp32)) + (0.03384649 * fTemp35))));
			double fTemp852 = (fConst227 * fRec1860[1]);
			double fTemp853 = (fConst228 * fRec1863[1]);
			fRec1865[0] = (fTemp851 + (fTemp852 + (fRec1865[1] + fTemp853)));
			fRec1863[0] = fRec1865[0];
			double fRec1864 = ((fTemp853 + fTemp852) + fTemp851);
			fRec1862[0] = (fRec1863[0] + fRec1862[1]);
			fRec1860[0] = fRec1862[0];
			double fRec1861 = fRec1864;
			fRec1859[0] = (fTemp849 + (fTemp850 + (fRec1861 + fRec1859[1])));
			fRec1857[0] = fRec1859[0];
			double fRec1858 = (fTemp849 + (fRec1861 + fTemp850));
			fRec1856[0] = (fRec1857[0] + fRec1856[1]);
			fRec1854[0] = fRec1856[0];
			double fRec1855 = fRec1858;
			double fTemp854 = (fConst230 * fRec1866[1]);
			double fTemp855 = (fConst232 * (((((0.11478250199999999 * fTemp40) + (0.078816080199999999 * fTemp41)) + (0.045085587000000003 * fTemp44)) + (0.010204327900000001 * fTemp45)) - ((0.020558122099999999 * fTemp46) + ((0.0050579153000000002 * fTemp43) + (0.0587313785 * fTemp42)))));
			double fTemp856 = (fConst233 * fRec1869[1]);
			double fTemp857 = (fConst234 * fRec1872[1]);
			fRec1874[0] = (fTemp855 + (fTemp856 + (fRec1874[1] + fTemp857)));
			fRec1872[0] = fRec1874[0];
			double fRec1873 = ((fTemp857 + fTemp856) + fTemp855);
			fRec1871[0] = (fRec1872[0] + fRec1871[1]);
			fRec1869[0] = fRec1871[0];
			double fRec1870 = fRec1873;
			fRec1868[0] = (fTemp854 + (fRec1870 + fRec1868[1]));
			fRec1866[0] = fRec1868[0];
			double fRec1867 = (fRec1870 + fTemp854);
			double fTemp858 = (fConst236 * ((0.0381559624 * fTemp50) - ((0.038096090800000003 * fTemp51) + (0.076137778700000006 * fTemp52))));
			double fTemp859 = (fConst237 * fRec1875[1]);
			fRec1877[0] = (fTemp858 + (fRec1877[1] + fTemp859));
			fRec1875[0] = fRec1877[0];
			double fRec1876 = (fTemp859 + fTemp858);
			double fTemp860 = (fConst239 * (((0.073072578400000004 * fTemp57) + (0.063475489100000004 * fTemp58)) - (((0.084947170000000002 * fTemp55) + (0.036671386100000002 * fTemp56)) + (0.026518126900000001 * fTemp59))));
			double fTemp861 = (fConst240 * fRec1878[1]);
			double fTemp862 = (fConst241 * fRec1881[1]);
			fRec1883[0] = (fTemp860 + (fTemp861 + (fRec1883[1] + fTemp862)));
			fRec1881[0] = fRec1883[0];
			double fRec1882 = ((fTemp862 + fTemp861) + fTemp860);
			fRec1880[0] = (fRec1881[0] + fRec1880[1]);
			fRec1878[0] = fRec1880[0];
			double fRec1879 = fRec1882;
			fVec39[(IOTA & 511)] = ((0.0332756908 * fTemp7) + (fRec1840 + (fRec1855 + (fRec1867 + (fRec1876 + fRec1879)))));
			output40[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec39[((IOTA - iConst242) & 511)])));
			double fTemp863 = (fConst184 * fRec1884[1]);
			double fTemp864 = (fConst186 * fRec1887[1]);
			double fTemp865 = (fConst187 * fRec1890[1]);
			double fTemp866 = (fConst189 * (((0.046797430899999999 * fTemp21) + ((0.10122519000000001 * fTemp20) + (((0.0092491304999999992 * fTemp16) + (0.0058275821999999996 * fTemp13)) + (0.0155879365 * fTemp19)))) - ((0.0040637316999999999 * fTemp18) + ((0.0052142910999999998 * fTemp15) + ((((0.1062499199 * fTemp11) + (0.0317195729 * fTemp12)) + (0.025975322700000001 * fTemp17)) + (0.020963398300000002 * fTemp14))))));
			double fTemp867 = (fConst190 * fRec1893[1]);
			double fTemp868 = (fConst191 * fRec1896[1]);
			fRec1898[0] = (fTemp866 + (fTemp867 + (fRec1898[1] + fTemp868)));
			fRec1896[0] = fRec1898[0];
			double fRec1897 = ((fTemp868 + fTemp867) + fTemp866);
			fRec1895[0] = (fRec1896[0] + fRec1895[1]);
			fRec1893[0] = fRec1895[0];
			double fRec1894 = fRec1897;
			fRec1892[0] = (fTemp864 + (fTemp865 + (fRec1894 + fRec1892[1])));
			fRec1890[0] = fRec1892[0];
			double fRec1891 = (fTemp864 + (fRec1894 + fTemp865));
			fRec1889[0] = (fRec1890[0] + fRec1889[1]);
			fRec1887[0] = fRec1889[0];
			double fRec1888 = fRec1891;
			fRec1886[0] = (fTemp863 + (fRec1888 + fRec1886[1]));
			fRec1884[0] = fRec1886[0];
			double fRec1885 = (fRec1888 + fTemp863);
			double fTemp869 = (fConst193 * fRec1899[1]);
			double fTemp870 = (fConst194 * fRec1902[1]);
			double fTemp871 = (fConst196 * ((((0.034996013399999998 * fTemp27) + (0.033408524000000002 * fTemp31)) + (0.0019653728999999998 * fTemp29)) - ((0.1142063656 * fTemp35) + ((0.089858008099999997 * fTemp34) + ((0.0012163095 * fTemp33) + (((0.056028558700000002 * fTemp28) + (0.0063210534999999998 * fTemp30)) + (0.028631855899999999 * fTemp32)))))));
			double fTemp872 = (fConst197 * fRec1905[1]);
			double fTemp873 = (fConst198 * fRec1908[1]);
			fRec1910[0] = (fTemp871 + (fTemp872 + (fRec1910[1] + fTemp873)));
			fRec1908[0] = fRec1910[0];
			double fRec1909 = ((fTemp873 + fTemp872) + fTemp871);
			fRec1907[0] = (fRec1908[0] + fRec1907[1]);
			fRec1905[0] = fRec1907[0];
			double fRec1906 = fRec1909;
			fRec1904[0] = (fTemp869 + (fTemp870 + (fRec1906 + fRec1904[1])));
			fRec1902[0] = fRec1904[0];
			double fRec1903 = (fTemp869 + (fRec1906 + fTemp870));
			fRec1901[0] = (fRec1902[0] + fRec1901[1]);
			fRec1899[0] = fRec1901[0];
			double fRec1900 = fRec1903;
			double fTemp874 = (fConst200 * fRec1911[1]);
			double fTemp875 = (fConst202 * (((0.098711720500000003 * fTemp46) + ((0.014878353299999999 * fTemp42) + ((((0.062135463100000003 * fTemp40) + (0.097186882500000002 * fTemp41)) + (0.045057921299999998 * fTemp44)) + (0.0074884495000000001 * fTemp45)))) - (0.0085588732000000008 * fTemp43)));
			double fTemp876 = (fConst203 * fRec1914[1]);
			double fTemp877 = (fConst204 * fRec1917[1]);
			fRec1919[0] = (fTemp875 + (fTemp876 + (fRec1919[1] + fTemp877)));
			fRec1917[0] = fRec1919[0];
			double fRec1918 = ((fTemp877 + fTemp876) + fTemp875);
			fRec1916[0] = (fRec1917[0] + fRec1916[1]);
			fRec1914[0] = fRec1916[0];
			double fRec1915 = fRec1918;
			fRec1913[0] = (fTemp874 + (fRec1915 + fRec1913[1]));
			fRec1911[0] = fRec1913[0];
			double fRec1912 = (fRec1915 + fTemp874);
			double fTemp878 = (fConst206 * ((0.064583163400000004 * fTemp50) - ((0.038125736 * fTemp51) + (0.055574241699999999 * fTemp52))));
			double fTemp879 = (fConst207 * fRec1920[1]);
			fRec1922[0] = (fTemp878 + (fRec1922[1] + fTemp879));
			fRec1920[0] = fRec1922[0];
			double fRec1921 = (fTemp879 + fTemp878);
			double fTemp880 = (fConst209 * ((0.053285021299999999 * fTemp57) - ((((0.10490024589999999 * fTemp55) + (0.062057665400000003 * fTemp56)) + (0.0265034338 * fTemp59)) + (0.0157893063 * fTemp58))));
			double fTemp881 = (fConst210 * fRec1923[1]);
			double fTemp882 = (fConst211 * fRec1926[1]);
			fRec1928[0] = (fTemp880 + (fTemp881 + (fRec1928[1] + fTemp882)));
			fRec1926[0] = fRec1928[0];
			double fRec1927 = ((fTemp882 + fTemp881) + fTemp880);
			fRec1925[0] = (fRec1926[0] + fRec1925[1]);
			fRec1923[0] = fRec1925[0];
			double fRec1924 = fRec1927;
			fVec40[(IOTA & 511)] = ((0.033295417100000002 * fTemp7) + (fRec1885 + (fRec1900 + (fRec1912 + (fRec1921 + fRec1924)))));
			output41[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec40[((IOTA - iConst212) & 511)])));
			double fTemp883 = (fConst214 * fRec1929[1]);
			double fTemp884 = (fConst216 * fRec1932[1]);
			double fTemp885 = (fConst217 * fRec1935[1]);
			double fTemp886 = (fConst219 * (((0.0072181390000000002 * fTemp13) + (0.0147701077 * fTemp19)) - ((0.11594870259999999 * fTemp21) + (((0.021142105800000002 * fTemp18) + ((0.0025028214999999999 * fTemp15) + (((((0.0038780943 * fTemp11) + (0.1016547523 * fTemp12)) + (0.0106664642 * fTemp16)) + (0.015732499699999999 * fTemp17)) + (0.0209529073 * fTemp14)))) + (0.030444632900000001 * fTemp20)))));
			double fTemp887 = (fConst220 * fRec1938[1]);
			double fTemp888 = (fConst221 * fRec1941[1]);
			fRec1943[0] = (fTemp886 + (fTemp887 + (fRec1943[1] + fTemp888)));
			fRec1941[0] = fRec1943[0];
			double fRec1942 = ((fTemp888 + fTemp887) + fTemp886);
			fRec1940[0] = (fRec1941[0] + fRec1940[1]);
			fRec1938[0] = fRec1940[0];
			double fRec1939 = fRec1942;
			fRec1937[0] = (fTemp884 + (fTemp885 + (fRec1939 + fRec1937[1])));
			fRec1935[0] = fRec1937[0];
			double fRec1936 = (fTemp884 + (fRec1939 + fTemp885));
			fRec1934[0] = (fRec1935[0] + fRec1934[1]);
			fRec1932[0] = fRec1934[0];
			double fRec1933 = fRec1936;
			fRec1931[0] = (fTemp883 + (fRec1933 + fRec1931[1]));
			fRec1929[0] = fRec1931[0];
			double fRec1930 = (fRec1933 + fTemp883);
			double fTemp889 = (fConst223 * fRec1944[1]);
			double fTemp890 = (fConst224 * fRec1947[1]);
			double fTemp891 = (fConst226 * ((((((0.1144481352 * fTemp27) + (0.060735275300000002 * fTemp28)) + (0.041848904200000002 * fTemp31)) + (0.0018425021 * fTemp29)) + (0.033819984900000002 * fTemp35)) - ((0.086782093800000001 * fTemp34) + ((0.0053293350999999997 * fTemp33) + ((0.0037694781999999998 * fTemp30) + (0.0138627157 * fTemp32))))));
			double fTemp892 = (fConst227 * fRec1950[1]);
			double fTemp893 = (fConst228 * fRec1953[1]);
			fRec1955[0] = (fTemp891 + (fTemp892 + (fRec1955[1] + fTemp893)));
			fRec1953[0] = fRec1955[0];
			double fRec1954 = ((fTemp893 + fTemp892) + fTemp891);
			fRec1952[0] = (fRec1953[0] + fRec1952[1]);
			fRec1950[0] = fRec1952[0];
			double fRec1951 = fRec1954;
			fRec1949[0] = (fTemp889 + (fTemp890 + (fRec1951 + fRec1949[1])));
			fRec1947[0] = fRec1949[0];
			double fRec1948 = (fTemp889 + (fRec1951 + fTemp890));
			fRec1946[0] = (fRec1947[0] + fRec1946[1]);
			fRec1944[0] = fRec1946[0];
			double fRec1945 = fRec1948;
			double fTemp894 = (fConst230 * fRec1956[1]);
			double fTemp895 = (fConst232 * (((0.095629328 * fTemp46) + ((0.078858903300000005 * fTemp42) + (((0.058746469900000001 * fTemp41) + (0.045119389099999997 * fTemp44)) + (0.0036205429999999999 * fTemp45)))) - ((0.066581291599999995 * fTemp40) + (0.010707793300000001 * fTemp43))));
			double fTemp896 = (fConst233 * fRec1959[1]);
			double fTemp897 = (fConst234 * fRec1962[1]);
			fRec1964[0] = (fTemp895 + (fTemp896 + (fRec1964[1] + fTemp897)));
			fRec1962[0] = fRec1964[0];
			double fRec1963 = ((fTemp897 + fTemp896) + fTemp895);
			fRec1961[0] = (fRec1962[0] + fRec1961[1]);
			fRec1959[0] = fRec1961[0];
			double fRec1960 = fRec1963;
			fRec1958[0] = (fTemp894 + (fRec1960 + fRec1958[1]));
			fRec1956[0] = fRec1958[0];
			double fRec1957 = (fRec1960 + fTemp894);
			double fTemp898 = (fConst236 * ((0.080772432899999996 * fTemp50) - ((0.038106424999999999 * fTemp51) + (0.026839500700000001 * fTemp52))));
			double fTemp899 = (fConst237 * fRec1965[1]);
			fRec1967[0] = (fTemp898 + (fRec1967[1] + fTemp899));
			fRec1965[0] = fRec1967[0];
			double fRec1966 = (fTemp899 + fTemp898);
			double fTemp900 = (fConst239 * ((0.0257443272 * fTemp57) - ((((0.0634306377 * fTemp55) + (0.077633322199999993 * fTemp56)) + (0.026474699399999999 * fTemp59)) + (0.084894441400000006 * fTemp58))));
			double fTemp901 = (fConst240 * fRec1968[1]);
			double fTemp902 = (fConst241 * fRec1971[1]);
			fRec1973[0] = (fTemp900 + (fTemp901 + (fRec1973[1] + fTemp902)));
			fRec1971[0] = fRec1973[0];
			double fRec1972 = ((fTemp902 + fTemp901) + fTemp900);
			fRec1970[0] = (fRec1971[0] + fRec1970[1]);
			fRec1968[0] = fRec1970[0];
			double fRec1969 = fRec1972;
			fVec41[(IOTA & 511)] = ((0.0332589062 * fTemp7) + (fRec1930 + (fRec1945 + (fRec1957 + (fRec1966 + fRec1969)))));
			output42[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec41[((IOTA - iConst242) & 511)])));
			double fTemp903 = (fConst184 * fRec1974[1]);
			double fTemp904 = (fConst186 * fRec1977[1]);
			double fTemp905 = (fConst187 * fRec1980[1]);
			double fTemp906 = (fConst189 * (((((((0.1082222259 * fTemp11) + (0.031727106499999998 * fTemp12)) + (0.0040080586999999999 * fTemp17)) + (0.0077845980999999998 * fTemp13)) + (0.00044573799999999999 * fTemp15)) + (0.041904105400000002 * fTemp21)) - ((0.1012325779 * fTemp20) + ((0.0045755739000000002 * fTemp19) + (((0.017592053900000001 * fTemp16) + (0.020982178800000001 * fTemp14)) + (0.025974099899999999 * fTemp18))))));
			double fTemp907 = (fConst190 * fRec1983[1]);
			double fTemp908 = (fConst191 * fRec1986[1]);
			fRec1988[0] = (fTemp906 + (fTemp907 + (fRec1988[1] + fTemp908)));
			fRec1986[0] = fRec1988[0];
			double fRec1987 = ((fTemp908 + fTemp907) + fTemp906);
			fRec1985[0] = (fRec1986[0] + fRec1985[1]);
			fRec1983[0] = fRec1985[0];
			double fRec1984 = fRec1987;
			fRec1982[0] = (fTemp904 + (fTemp905 + (fRec1984 + fRec1982[1])));
			fRec1980[0] = fRec1982[0];
			double fRec1981 = (fTemp904 + (fRec1984 + fTemp905));
			fRec1979[0] = (fRec1980[0] + fRec1979[1]);
			fRec1977[0] = fRec1979[0];
			double fRec1978 = fRec1981;
			fRec1976[0] = (fTemp903 + (fRec1978 + fRec1976[1]));
			fRec1974[0] = fRec1976[0];
			double fRec1975 = (fRec1978 + fTemp903);
			double fTemp909 = (fConst193 * fRec1989[1]);
			double fTemp910 = (fConst194 * fRec1992[1]);
			double fTemp911 = (fConst196 * (((0.11418412460000001 * fTemp35) + (((0.0033457879000000001 * fTemp32) + ((((0.103164592 * fTemp28) + (0.0012909985 * fTemp30)) + (0.043861270399999999 * fTemp31)) + (0.0019468815999999999 * fTemp29))) + (0.0239328306 * fTemp34))) - ((0.034890412099999997 * fTemp27) + (0.0063689417999999998 * fTemp33))));
			double fTemp912 = (fConst197 * fRec1995[1]);
			double fTemp913 = (fConst198 * fRec1998[1]);
			fRec2000[0] = (fTemp911 + (fTemp912 + (fRec2000[1] + fTemp913)));
			fRec1998[0] = fRec2000[0];
			double fRec1999 = ((fTemp913 + fTemp912) + fTemp911);
			fRec1997[0] = (fRec1998[0] + fRec1997[1]);
			fRec1995[0] = fRec1997[0];
			double fRec1996 = fRec1999;
			fRec1994[0] = (fTemp909 + (fTemp910 + (fRec1996 + fRec1994[1])));
			fRec1992[0] = fRec1994[0];
			double fRec1993 = (fTemp909 + (fRec1996 + fTemp910));
			fRec1991[0] = (fRec1992[0] + fRec1991[1]);
			fRec1989[0] = fRec1991[0];
			double fRec1990 = fRec1993;
			double fTemp914 = (fConst200 * fRec2001[1]);
			double fTemp915 = (fConst202 * (((0.045046237599999997 * fTemp44) + (0.097195331699999998 * fTemp42)) - (((((0.1136994328 * fTemp40) + (0.0148935161 * fTemp41)) + (0.011291667199999999 * fTemp43)) + (0.00071408759999999996 * fTemp45)) + (0.0257925406 * fTemp46))));
			double fTemp916 = (fConst203 * fRec2004[1]);
			double fTemp917 = (fConst204 * fRec2007[1]);
			fRec2009[0] = (fTemp915 + (fTemp916 + (fRec2009[1] + fTemp917)));
			fRec2007[0] = fRec2009[0];
			double fRec2008 = ((fTemp917 + fTemp916) + fTemp915);
			fRec2006[0] = (fRec2007[0] + fRec2006[1]);
			fRec2004[0] = fRec2006[0];
			double fRec2005 = fRec2008;
			fRec2003[0] = (fTemp914 + (fRec2005 + fRec2003[1]));
			fRec2001[0] = fRec2003[0];
			double fRec2002 = (fRec2005 + fTemp914);
			double fTemp918 = (fConst206 * (((0.084932691599999999 * fTemp50) + (0.0063599618000000002 * fTemp52)) - (0.038136089200000001 * fTemp51)));
			double fTemp919 = (fConst207 * fRec2010[1]);
			fRec2012[0] = (fTemp918 + (fRec2012[1] + fTemp919));
			fRec2010[0] = fRec2012[0];
			double fRec2011 = (fTemp919 + fTemp918);
			double fTemp920 = (fConst209 * ((0.0157526739 * fTemp55) - ((((0.081569276600000004 * fTemp56) + (0.026461297700000001 * fTemp59)) + (0.0062161797000000003 * fTemp57)) + (0.1048605755 * fTemp58))));
			double fTemp921 = (fConst210 * fRec2013[1]);
			double fTemp922 = (fConst211 * fRec2016[1]);
			fRec2018[0] = (fTemp920 + (fTemp921 + (fRec2018[1] + fTemp922)));
			fRec2016[0] = fRec2018[0];
			double fRec2017 = ((fTemp922 + fTemp921) + fTemp920);
			fRec2015[0] = (fRec2016[0] + fRec2015[1]);
			fRec2013[0] = fRec2015[0];
			double fRec2014 = fRec2017;
			fVec42[(IOTA & 511)] = ((0.033286693800000003 * fTemp7) + (fRec1975 + (fRec1990 + (fRec2002 + (fRec2011 + fRec2014)))));
			output43[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec42[((IOTA - iConst212) & 511)])));
			double fTemp923 = (fConst214 * fRec2019[1]);
			double fTemp924 = (fConst216 * fRec2022[1]);
			double fTemp925 = (fConst217 * fRec2025[1]);
			double fTemp926 = (fConst219 * (((0.0848089291 * fTemp21) + (((((0.101600287 * fTemp12) + (0.0211045672 * fTemp17)) + (0.0069372634000000001 * fTemp13)) + (0.0034328653999999999 * fTemp15)) + (0.030439323899999999 * fTemp20))) - ((0.017868153899999999 * fTemp19) + ((((0.079331929699999998 * fTemp11) + (0.0029221923000000002 * fTemp16)) + (0.020930383 * fTemp14)) + (0.015715206299999999 * fTemp18)))));
			double fTemp927 = (fConst220 * fRec2028[1]);
			double fTemp928 = (fConst221 * fRec2031[1]);
			fRec2033[0] = (fTemp926 + (fTemp927 + (fRec2033[1] + fTemp928)));
			fRec2031[0] = fRec2033[0];
			double fRec2032 = ((fTemp928 + fTemp927) + fTemp926);
			fRec2030[0] = (fRec2031[0] + fRec2030[1]);
			fRec2028[0] = fRec2030[0];
			double fRec2029 = fRec2032;
			fRec2027[0] = (fTemp924 + (fTemp925 + (fRec2029 + fRec2027[1])));
			fRec2025[0] = fRec2027[0];
			double fRec2026 = (fTemp924 + (fRec2029 + fTemp925));
			fRec2024[0] = (fRec2025[0] + fRec2024[1]);
			fRec2022[0] = fRec2024[0];
			double fRec2023 = fRec2026;
			fRec2021[0] = (fTemp923 + (fRec2023 + fRec2021[1]));
			fRec2019[0] = fRec2021[0];
			double fRec2020 = (fRec2023 + fTemp923);
			double fTemp929 = (fConst223 * fRec2034[1]);
			double fTemp930 = (fConst224 * fRec2037[1]);
			double fTemp931 = (fConst226 * ((((0.019749163300000001 * fTemp32) + ((((0.018404886400000001 * fTemp28) + (0.0052370094999999997 * fTemp30)) + (0.0393619568 * fTemp31)) + (0.0019212354 * fTemp29))) + (0.1042655446 * fTemp34)) - (((0.1145611803 * fTemp27) + (0.0037124749999999998 * fTemp33)) + (0.0338621952 * fTemp35))));
			double fTemp932 = (fConst227 * fRec2040[1]);
			double fTemp933 = (fConst228 * fRec2043[1]);
			fRec2045[0] = (fTemp931 + (fTemp932 + (fRec2045[1] + fTemp933)));
			fRec2043[0] = fRec2045[0];
			double fRec2044 = ((fTemp933 + fTemp932) + fTemp931);
			fRec2042[0] = (fRec2043[0] + fRec2042[1]);
			fRec2040[0] = fRec2042[0];
			double fRec2041 = fRec2044;
			fRec2039[0] = (fTemp929 + (fTemp930 + (fRec2041 + fRec2039[1])));
			fRec2037[0] = fRec2039[0];
			double fRec2038 = (fTemp929 + (fRec2041 + fTemp930));
			fRec2036[0] = (fRec2037[0] + fRec2036[1]);
			fRec2034[0] = fRec2036[0];
			double fRec2035 = fRec2038;
			double fTemp934 = (fConst230 * fRec2046[1]);
			double fTemp935 = (fConst232 * (((0.045087633299999999 * fTemp44) + (0.058720090199999998 * fTemp42)) - (((((0.020554094700000001 * fTemp40) + (0.078833772999999996 * fTemp41)) + (0.010219548300000001 * fTemp43)) + (0.0050463616000000003 * fTemp45)) + (0.11481363529999999 * fTemp46))));
			double fTemp936 = (fConst233 * fRec2049[1]);
			double fTemp937 = (fConst234 * fRec2052[1]);
			fRec2054[0] = (fTemp935 + (fTemp936 + (fRec2054[1] + fTemp937)));
			fRec2052[0] = fRec2054[0];
			double fRec2053 = ((fTemp937 + fTemp936) + fTemp935);
			fRec2051[0] = (fRec2052[0] + fRec2051[1]);
			fRec2049[0] = fRec2051[0];
			double fRec2050 = fRec2053;
			fRec2048[0] = (fTemp934 + (fRec2050 + fRec2048[1]));
			fRec2046[0] = fRec2048[0];
			double fRec2047 = (fRec2050 + fTemp934);
			double fTemp938 = (fConst236 * (((0.076156538300000007 * fTemp50) + (0.038172035700000002 * fTemp52)) - (0.038101486499999997 * fTemp51)));
			double fTemp939 = (fConst237 * fRec2055[1]);
			fRec2057[0] = (fTemp938 + (fRec2057[1] + fTemp939));
			fRec2055[0] = fRec2057[0];
			double fRec2056 = (fTemp939 + fTemp938);
			double fTemp940 = (fConst239 * ((0.084975672099999996 * fTemp55) - ((((0.073075973599999997 * fTemp56) + (0.026528459000000001 * fTemp59)) + (0.036688060199999997 * fTemp57)) + (0.063485609600000006 * fTemp58))));
			double fTemp941 = (fConst240 * fRec2058[1]);
			double fTemp942 = (fConst241 * fRec2061[1]);
			fRec2063[0] = (fTemp940 + (fTemp941 + (fRec2063[1] + fTemp942)));
			fRec2061[0] = fRec2063[0];
			double fRec2062 = ((fTemp942 + fTemp941) + fTemp940);
			fRec2060[0] = (fRec2061[0] + fRec2060[1]);
			fRec2058[0] = fRec2060[0];
			double fRec2059 = fRec2062;
			fVec43[(IOTA & 511)] = ((0.033284755200000002 * fTemp7) + (fRec2020 + (fRec2035 + (fRec2047 + (fRec2056 + fRec2059)))));
			output44[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec43[((IOTA - iConst242) & 511)])));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
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
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fRec18[1] = fRec18[0];
			fRec16[1] = fRec16[0];
			fRec15[1] = fRec15[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fRec43[2] = fRec43[1];
			fRec43[1] = fRec43[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec47[2] = fRec47[1];
			fRec47[1] = fRec47[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec41[1] = fRec41[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec30[1] = fRec30[0];
			fRec60[2] = fRec60[1];
			fRec60[1] = fRec60[0];
			fRec61[2] = fRec61[1];
			fRec61[1] = fRec61[0];
			fRec62[2] = fRec62[1];
			fRec62[1] = fRec62[0];
			fRec63[2] = fRec63[1];
			fRec63[1] = fRec63[0];
			fRec64[2] = fRec64[1];
			fRec64[1] = fRec64[0];
			fRec65[2] = fRec65[1];
			fRec65[1] = fRec65[0];
			fRec66[2] = fRec66[1];
			fRec66[1] = fRec66[0];
			fRec59[1] = fRec59[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fRec54[1] = fRec54[0];
			fRec53[1] = fRec53[0];
			fRec51[1] = fRec51[0];
			fRec70[2] = fRec70[1];
			fRec70[1] = fRec70[0];
			fRec71[2] = fRec71[1];
			fRec71[1] = fRec71[0];
			fRec72[2] = fRec72[1];
			fRec72[1] = fRec72[0];
			fRec69[1] = fRec69[0];
			fRec67[1] = fRec67[0];
			fRec79[2] = fRec79[1];
			fRec79[1] = fRec79[0];
			fRec80[2] = fRec80[1];
			fRec80[1] = fRec80[0];
			fRec81[2] = fRec81[1];
			fRec81[1] = fRec81[0];
			fRec82[2] = fRec82[1];
			fRec82[1] = fRec82[0];
			fRec83[2] = fRec83[1];
			fRec83[1] = fRec83[0];
			fRec78[1] = fRec78[0];
			fRec76[1] = fRec76[0];
			fRec75[1] = fRec75[0];
			fRec73[1] = fRec73[0];
			IOTA = (IOTA + 1);
			fRec98[1] = fRec98[0];
			fRec96[1] = fRec96[0];
			fRec95[1] = fRec95[0];
			fRec93[1] = fRec93[0];
			fRec92[1] = fRec92[0];
			fRec90[1] = fRec90[0];
			fRec89[1] = fRec89[0];
			fRec87[1] = fRec87[0];
			fRec86[1] = fRec86[0];
			fRec84[1] = fRec84[0];
			fRec110[1] = fRec110[0];
			fRec108[1] = fRec108[0];
			fRec107[1] = fRec107[0];
			fRec105[1] = fRec105[0];
			fRec104[1] = fRec104[0];
			fRec102[1] = fRec102[0];
			fRec101[1] = fRec101[0];
			fRec99[1] = fRec99[0];
			fRec119[1] = fRec119[0];
			fRec117[1] = fRec117[0];
			fRec116[1] = fRec116[0];
			fRec114[1] = fRec114[0];
			fRec113[1] = fRec113[0];
			fRec111[1] = fRec111[0];
			fRec122[1] = fRec122[0];
			fRec120[1] = fRec120[0];
			fRec128[1] = fRec128[0];
			fRec126[1] = fRec126[0];
			fRec125[1] = fRec125[0];
			fRec123[1] = fRec123[0];
			fRec143[1] = fRec143[0];
			fRec141[1] = fRec141[0];
			fRec140[1] = fRec140[0];
			fRec138[1] = fRec138[0];
			fRec137[1] = fRec137[0];
			fRec135[1] = fRec135[0];
			fRec134[1] = fRec134[0];
			fRec132[1] = fRec132[0];
			fRec131[1] = fRec131[0];
			fRec129[1] = fRec129[0];
			fRec155[1] = fRec155[0];
			fRec153[1] = fRec153[0];
			fRec152[1] = fRec152[0];
			fRec150[1] = fRec150[0];
			fRec149[1] = fRec149[0];
			fRec147[1] = fRec147[0];
			fRec146[1] = fRec146[0];
			fRec144[1] = fRec144[0];
			fRec164[1] = fRec164[0];
			fRec162[1] = fRec162[0];
			fRec161[1] = fRec161[0];
			fRec159[1] = fRec159[0];
			fRec158[1] = fRec158[0];
			fRec156[1] = fRec156[0];
			fRec167[1] = fRec167[0];
			fRec165[1] = fRec165[0];
			fRec173[1] = fRec173[0];
			fRec171[1] = fRec171[0];
			fRec170[1] = fRec170[0];
			fRec168[1] = fRec168[0];
			fRec188[1] = fRec188[0];
			fRec186[1] = fRec186[0];
			fRec185[1] = fRec185[0];
			fRec183[1] = fRec183[0];
			fRec182[1] = fRec182[0];
			fRec180[1] = fRec180[0];
			fRec179[1] = fRec179[0];
			fRec177[1] = fRec177[0];
			fRec176[1] = fRec176[0];
			fRec174[1] = fRec174[0];
			fRec200[1] = fRec200[0];
			fRec198[1] = fRec198[0];
			fRec197[1] = fRec197[0];
			fRec195[1] = fRec195[0];
			fRec194[1] = fRec194[0];
			fRec192[1] = fRec192[0];
			fRec191[1] = fRec191[0];
			fRec189[1] = fRec189[0];
			fRec209[1] = fRec209[0];
			fRec207[1] = fRec207[0];
			fRec206[1] = fRec206[0];
			fRec204[1] = fRec204[0];
			fRec203[1] = fRec203[0];
			fRec201[1] = fRec201[0];
			fRec212[1] = fRec212[0];
			fRec210[1] = fRec210[0];
			fRec218[1] = fRec218[0];
			fRec216[1] = fRec216[0];
			fRec215[1] = fRec215[0];
			fRec213[1] = fRec213[0];
			fRec233[1] = fRec233[0];
			fRec231[1] = fRec231[0];
			fRec230[1] = fRec230[0];
			fRec228[1] = fRec228[0];
			fRec227[1] = fRec227[0];
			fRec225[1] = fRec225[0];
			fRec224[1] = fRec224[0];
			fRec222[1] = fRec222[0];
			fRec221[1] = fRec221[0];
			fRec219[1] = fRec219[0];
			fRec245[1] = fRec245[0];
			fRec243[1] = fRec243[0];
			fRec242[1] = fRec242[0];
			fRec240[1] = fRec240[0];
			fRec239[1] = fRec239[0];
			fRec237[1] = fRec237[0];
			fRec236[1] = fRec236[0];
			fRec234[1] = fRec234[0];
			fRec254[1] = fRec254[0];
			fRec252[1] = fRec252[0];
			fRec251[1] = fRec251[0];
			fRec249[1] = fRec249[0];
			fRec248[1] = fRec248[0];
			fRec246[1] = fRec246[0];
			fRec257[1] = fRec257[0];
			fRec255[1] = fRec255[0];
			fRec263[1] = fRec263[0];
			fRec261[1] = fRec261[0];
			fRec260[1] = fRec260[0];
			fRec258[1] = fRec258[0];
			fRec269[1] = fRec269[0];
			fRec267[1] = fRec267[0];
			fRec266[1] = fRec266[0];
			fRec264[1] = fRec264[0];
			fRec272[1] = fRec272[0];
			fRec270[1] = fRec270[0];
			fRec287[1] = fRec287[0];
			fRec285[1] = fRec285[0];
			fRec284[1] = fRec284[0];
			fRec282[1] = fRec282[0];
			fRec281[1] = fRec281[0];
			fRec279[1] = fRec279[0];
			fRec278[1] = fRec278[0];
			fRec276[1] = fRec276[0];
			fRec275[1] = fRec275[0];
			fRec273[1] = fRec273[0];
			fRec296[1] = fRec296[0];
			fRec294[1] = fRec294[0];
			fRec293[1] = fRec293[0];
			fRec291[1] = fRec291[0];
			fRec290[1] = fRec290[0];
			fRec288[1] = fRec288[0];
			fRec308[1] = fRec308[0];
			fRec306[1] = fRec306[0];
			fRec305[1] = fRec305[0];
			fRec303[1] = fRec303[0];
			fRec302[1] = fRec302[0];
			fRec300[1] = fRec300[0];
			fRec299[1] = fRec299[0];
			fRec297[1] = fRec297[0];
			fRec323[1] = fRec323[0];
			fRec321[1] = fRec321[0];
			fRec320[1] = fRec320[0];
			fRec318[1] = fRec318[0];
			fRec317[1] = fRec317[0];
			fRec315[1] = fRec315[0];
			fRec314[1] = fRec314[0];
			fRec312[1] = fRec312[0];
			fRec311[1] = fRec311[0];
			fRec309[1] = fRec309[0];
			fRec335[1] = fRec335[0];
			fRec333[1] = fRec333[0];
			fRec332[1] = fRec332[0];
			fRec330[1] = fRec330[0];
			fRec329[1] = fRec329[0];
			fRec327[1] = fRec327[0];
			fRec326[1] = fRec326[0];
			fRec324[1] = fRec324[0];
			fRec344[1] = fRec344[0];
			fRec342[1] = fRec342[0];
			fRec341[1] = fRec341[0];
			fRec339[1] = fRec339[0];
			fRec338[1] = fRec338[0];
			fRec336[1] = fRec336[0];
			fRec347[1] = fRec347[0];
			fRec345[1] = fRec345[0];
			fRec353[1] = fRec353[0];
			fRec351[1] = fRec351[0];
			fRec350[1] = fRec350[0];
			fRec348[1] = fRec348[0];
			fRec368[1] = fRec368[0];
			fRec366[1] = fRec366[0];
			fRec365[1] = fRec365[0];
			fRec363[1] = fRec363[0];
			fRec362[1] = fRec362[0];
			fRec360[1] = fRec360[0];
			fRec359[1] = fRec359[0];
			fRec357[1] = fRec357[0];
			fRec356[1] = fRec356[0];
			fRec354[1] = fRec354[0];
			fRec380[1] = fRec380[0];
			fRec378[1] = fRec378[0];
			fRec377[1] = fRec377[0];
			fRec375[1] = fRec375[0];
			fRec374[1] = fRec374[0];
			fRec372[1] = fRec372[0];
			fRec371[1] = fRec371[0];
			fRec369[1] = fRec369[0];
			fRec389[1] = fRec389[0];
			fRec387[1] = fRec387[0];
			fRec386[1] = fRec386[0];
			fRec384[1] = fRec384[0];
			fRec383[1] = fRec383[0];
			fRec381[1] = fRec381[0];
			fRec392[1] = fRec392[0];
			fRec390[1] = fRec390[0];
			fRec398[1] = fRec398[0];
			fRec396[1] = fRec396[0];
			fRec395[1] = fRec395[0];
			fRec393[1] = fRec393[0];
			fRec413[1] = fRec413[0];
			fRec411[1] = fRec411[0];
			fRec410[1] = fRec410[0];
			fRec408[1] = fRec408[0];
			fRec407[1] = fRec407[0];
			fRec405[1] = fRec405[0];
			fRec404[1] = fRec404[0];
			fRec402[1] = fRec402[0];
			fRec401[1] = fRec401[0];
			fRec399[1] = fRec399[0];
			fRec425[1] = fRec425[0];
			fRec423[1] = fRec423[0];
			fRec422[1] = fRec422[0];
			fRec420[1] = fRec420[0];
			fRec419[1] = fRec419[0];
			fRec417[1] = fRec417[0];
			fRec416[1] = fRec416[0];
			fRec414[1] = fRec414[0];
			fRec434[1] = fRec434[0];
			fRec432[1] = fRec432[0];
			fRec431[1] = fRec431[0];
			fRec429[1] = fRec429[0];
			fRec428[1] = fRec428[0];
			fRec426[1] = fRec426[0];
			fRec437[1] = fRec437[0];
			fRec435[1] = fRec435[0];
			fRec443[1] = fRec443[0];
			fRec441[1] = fRec441[0];
			fRec440[1] = fRec440[0];
			fRec438[1] = fRec438[0];
			fRec458[1] = fRec458[0];
			fRec456[1] = fRec456[0];
			fRec455[1] = fRec455[0];
			fRec453[1] = fRec453[0];
			fRec452[1] = fRec452[0];
			fRec450[1] = fRec450[0];
			fRec449[1] = fRec449[0];
			fRec447[1] = fRec447[0];
			fRec446[1] = fRec446[0];
			fRec444[1] = fRec444[0];
			fRec470[1] = fRec470[0];
			fRec468[1] = fRec468[0];
			fRec467[1] = fRec467[0];
			fRec465[1] = fRec465[0];
			fRec464[1] = fRec464[0];
			fRec462[1] = fRec462[0];
			fRec461[1] = fRec461[0];
			fRec459[1] = fRec459[0];
			fRec479[1] = fRec479[0];
			fRec477[1] = fRec477[0];
			fRec476[1] = fRec476[0];
			fRec474[1] = fRec474[0];
			fRec473[1] = fRec473[0];
			fRec471[1] = fRec471[0];
			fRec482[1] = fRec482[0];
			fRec480[1] = fRec480[0];
			fRec488[1] = fRec488[0];
			fRec486[1] = fRec486[0];
			fRec485[1] = fRec485[0];
			fRec483[1] = fRec483[0];
			fRec503[1] = fRec503[0];
			fRec501[1] = fRec501[0];
			fRec500[1] = fRec500[0];
			fRec498[1] = fRec498[0];
			fRec497[1] = fRec497[0];
			fRec495[1] = fRec495[0];
			fRec494[1] = fRec494[0];
			fRec492[1] = fRec492[0];
			fRec491[1] = fRec491[0];
			fRec489[1] = fRec489[0];
			fRec515[1] = fRec515[0];
			fRec513[1] = fRec513[0];
			fRec512[1] = fRec512[0];
			fRec510[1] = fRec510[0];
			fRec509[1] = fRec509[0];
			fRec507[1] = fRec507[0];
			fRec506[1] = fRec506[0];
			fRec504[1] = fRec504[0];
			fRec524[1] = fRec524[0];
			fRec522[1] = fRec522[0];
			fRec521[1] = fRec521[0];
			fRec519[1] = fRec519[0];
			fRec518[1] = fRec518[0];
			fRec516[1] = fRec516[0];
			fRec527[1] = fRec527[0];
			fRec525[1] = fRec525[0];
			fRec533[1] = fRec533[0];
			fRec531[1] = fRec531[0];
			fRec530[1] = fRec530[0];
			fRec528[1] = fRec528[0];
			fRec548[1] = fRec548[0];
			fRec546[1] = fRec546[0];
			fRec545[1] = fRec545[0];
			fRec543[1] = fRec543[0];
			fRec542[1] = fRec542[0];
			fRec540[1] = fRec540[0];
			fRec539[1] = fRec539[0];
			fRec537[1] = fRec537[0];
			fRec536[1] = fRec536[0];
			fRec534[1] = fRec534[0];
			fRec560[1] = fRec560[0];
			fRec558[1] = fRec558[0];
			fRec557[1] = fRec557[0];
			fRec555[1] = fRec555[0];
			fRec554[1] = fRec554[0];
			fRec552[1] = fRec552[0];
			fRec551[1] = fRec551[0];
			fRec549[1] = fRec549[0];
			fRec569[1] = fRec569[0];
			fRec567[1] = fRec567[0];
			fRec566[1] = fRec566[0];
			fRec564[1] = fRec564[0];
			fRec563[1] = fRec563[0];
			fRec561[1] = fRec561[0];
			fRec572[1] = fRec572[0];
			fRec570[1] = fRec570[0];
			fRec578[1] = fRec578[0];
			fRec576[1] = fRec576[0];
			fRec575[1] = fRec575[0];
			fRec573[1] = fRec573[0];
			fRec593[1] = fRec593[0];
			fRec591[1] = fRec591[0];
			fRec590[1] = fRec590[0];
			fRec588[1] = fRec588[0];
			fRec587[1] = fRec587[0];
			fRec585[1] = fRec585[0];
			fRec584[1] = fRec584[0];
			fRec582[1] = fRec582[0];
			fRec581[1] = fRec581[0];
			fRec579[1] = fRec579[0];
			fRec605[1] = fRec605[0];
			fRec603[1] = fRec603[0];
			fRec602[1] = fRec602[0];
			fRec600[1] = fRec600[0];
			fRec599[1] = fRec599[0];
			fRec597[1] = fRec597[0];
			fRec596[1] = fRec596[0];
			fRec594[1] = fRec594[0];
			fRec614[1] = fRec614[0];
			fRec612[1] = fRec612[0];
			fRec611[1] = fRec611[0];
			fRec609[1] = fRec609[0];
			fRec608[1] = fRec608[0];
			fRec606[1] = fRec606[0];
			fRec617[1] = fRec617[0];
			fRec615[1] = fRec615[0];
			fRec623[1] = fRec623[0];
			fRec621[1] = fRec621[0];
			fRec620[1] = fRec620[0];
			fRec618[1] = fRec618[0];
			fRec638[1] = fRec638[0];
			fRec636[1] = fRec636[0];
			fRec635[1] = fRec635[0];
			fRec633[1] = fRec633[0];
			fRec632[1] = fRec632[0];
			fRec630[1] = fRec630[0];
			fRec629[1] = fRec629[0];
			fRec627[1] = fRec627[0];
			fRec626[1] = fRec626[0];
			fRec624[1] = fRec624[0];
			fRec650[1] = fRec650[0];
			fRec648[1] = fRec648[0];
			fRec647[1] = fRec647[0];
			fRec645[1] = fRec645[0];
			fRec644[1] = fRec644[0];
			fRec642[1] = fRec642[0];
			fRec641[1] = fRec641[0];
			fRec639[1] = fRec639[0];
			fRec659[1] = fRec659[0];
			fRec657[1] = fRec657[0];
			fRec656[1] = fRec656[0];
			fRec654[1] = fRec654[0];
			fRec653[1] = fRec653[0];
			fRec651[1] = fRec651[0];
			fRec662[1] = fRec662[0];
			fRec660[1] = fRec660[0];
			fRec668[1] = fRec668[0];
			fRec666[1] = fRec666[0];
			fRec665[1] = fRec665[0];
			fRec663[1] = fRec663[0];
			fRec683[1] = fRec683[0];
			fRec681[1] = fRec681[0];
			fRec680[1] = fRec680[0];
			fRec678[1] = fRec678[0];
			fRec677[1] = fRec677[0];
			fRec675[1] = fRec675[0];
			fRec674[1] = fRec674[0];
			fRec672[1] = fRec672[0];
			fRec671[1] = fRec671[0];
			fRec669[1] = fRec669[0];
			fRec695[1] = fRec695[0];
			fRec693[1] = fRec693[0];
			fRec692[1] = fRec692[0];
			fRec690[1] = fRec690[0];
			fRec689[1] = fRec689[0];
			fRec687[1] = fRec687[0];
			fRec686[1] = fRec686[0];
			fRec684[1] = fRec684[0];
			fRec704[1] = fRec704[0];
			fRec702[1] = fRec702[0];
			fRec701[1] = fRec701[0];
			fRec699[1] = fRec699[0];
			fRec698[1] = fRec698[0];
			fRec696[1] = fRec696[0];
			fRec707[1] = fRec707[0];
			fRec705[1] = fRec705[0];
			fRec713[1] = fRec713[0];
			fRec711[1] = fRec711[0];
			fRec710[1] = fRec710[0];
			fRec708[1] = fRec708[0];
			fRec728[1] = fRec728[0];
			fRec726[1] = fRec726[0];
			fRec725[1] = fRec725[0];
			fRec723[1] = fRec723[0];
			fRec722[1] = fRec722[0];
			fRec720[1] = fRec720[0];
			fRec719[1] = fRec719[0];
			fRec717[1] = fRec717[0];
			fRec716[1] = fRec716[0];
			fRec714[1] = fRec714[0];
			fRec740[1] = fRec740[0];
			fRec738[1] = fRec738[0];
			fRec737[1] = fRec737[0];
			fRec735[1] = fRec735[0];
			fRec734[1] = fRec734[0];
			fRec732[1] = fRec732[0];
			fRec731[1] = fRec731[0];
			fRec729[1] = fRec729[0];
			fRec749[1] = fRec749[0];
			fRec747[1] = fRec747[0];
			fRec746[1] = fRec746[0];
			fRec744[1] = fRec744[0];
			fRec743[1] = fRec743[0];
			fRec741[1] = fRec741[0];
			fRec752[1] = fRec752[0];
			fRec750[1] = fRec750[0];
			fRec758[1] = fRec758[0];
			fRec756[1] = fRec756[0];
			fRec755[1] = fRec755[0];
			fRec753[1] = fRec753[0];
			fRec773[1] = fRec773[0];
			fRec771[1] = fRec771[0];
			fRec770[1] = fRec770[0];
			fRec768[1] = fRec768[0];
			fRec767[1] = fRec767[0];
			fRec765[1] = fRec765[0];
			fRec764[1] = fRec764[0];
			fRec762[1] = fRec762[0];
			fRec761[1] = fRec761[0];
			fRec759[1] = fRec759[0];
			fRec785[1] = fRec785[0];
			fRec783[1] = fRec783[0];
			fRec782[1] = fRec782[0];
			fRec780[1] = fRec780[0];
			fRec779[1] = fRec779[0];
			fRec777[1] = fRec777[0];
			fRec776[1] = fRec776[0];
			fRec774[1] = fRec774[0];
			fRec794[1] = fRec794[0];
			fRec792[1] = fRec792[0];
			fRec791[1] = fRec791[0];
			fRec789[1] = fRec789[0];
			fRec788[1] = fRec788[0];
			fRec786[1] = fRec786[0];
			fRec797[1] = fRec797[0];
			fRec795[1] = fRec795[0];
			fRec803[1] = fRec803[0];
			fRec801[1] = fRec801[0];
			fRec800[1] = fRec800[0];
			fRec798[1] = fRec798[0];
			fRec818[1] = fRec818[0];
			fRec816[1] = fRec816[0];
			fRec815[1] = fRec815[0];
			fRec813[1] = fRec813[0];
			fRec812[1] = fRec812[0];
			fRec810[1] = fRec810[0];
			fRec809[1] = fRec809[0];
			fRec807[1] = fRec807[0];
			fRec806[1] = fRec806[0];
			fRec804[1] = fRec804[0];
			fRec830[1] = fRec830[0];
			fRec828[1] = fRec828[0];
			fRec827[1] = fRec827[0];
			fRec825[1] = fRec825[0];
			fRec824[1] = fRec824[0];
			fRec822[1] = fRec822[0];
			fRec821[1] = fRec821[0];
			fRec819[1] = fRec819[0];
			fRec839[1] = fRec839[0];
			fRec837[1] = fRec837[0];
			fRec836[1] = fRec836[0];
			fRec834[1] = fRec834[0];
			fRec833[1] = fRec833[0];
			fRec831[1] = fRec831[0];
			fRec842[1] = fRec842[0];
			fRec840[1] = fRec840[0];
			fRec848[1] = fRec848[0];
			fRec846[1] = fRec846[0];
			fRec845[1] = fRec845[0];
			fRec843[1] = fRec843[0];
			fRec863[1] = fRec863[0];
			fRec861[1] = fRec861[0];
			fRec860[1] = fRec860[0];
			fRec858[1] = fRec858[0];
			fRec857[1] = fRec857[0];
			fRec855[1] = fRec855[0];
			fRec854[1] = fRec854[0];
			fRec852[1] = fRec852[0];
			fRec851[1] = fRec851[0];
			fRec849[1] = fRec849[0];
			fRec875[1] = fRec875[0];
			fRec873[1] = fRec873[0];
			fRec872[1] = fRec872[0];
			fRec870[1] = fRec870[0];
			fRec869[1] = fRec869[0];
			fRec867[1] = fRec867[0];
			fRec866[1] = fRec866[0];
			fRec864[1] = fRec864[0];
			fRec884[1] = fRec884[0];
			fRec882[1] = fRec882[0];
			fRec881[1] = fRec881[0];
			fRec879[1] = fRec879[0];
			fRec878[1] = fRec878[0];
			fRec876[1] = fRec876[0];
			fRec887[1] = fRec887[0];
			fRec885[1] = fRec885[0];
			fRec893[1] = fRec893[0];
			fRec891[1] = fRec891[0];
			fRec890[1] = fRec890[0];
			fRec888[1] = fRec888[0];
			fRec908[1] = fRec908[0];
			fRec906[1] = fRec906[0];
			fRec905[1] = fRec905[0];
			fRec903[1] = fRec903[0];
			fRec902[1] = fRec902[0];
			fRec900[1] = fRec900[0];
			fRec899[1] = fRec899[0];
			fRec897[1] = fRec897[0];
			fRec896[1] = fRec896[0];
			fRec894[1] = fRec894[0];
			fRec920[1] = fRec920[0];
			fRec918[1] = fRec918[0];
			fRec917[1] = fRec917[0];
			fRec915[1] = fRec915[0];
			fRec914[1] = fRec914[0];
			fRec912[1] = fRec912[0];
			fRec911[1] = fRec911[0];
			fRec909[1] = fRec909[0];
			fRec929[1] = fRec929[0];
			fRec927[1] = fRec927[0];
			fRec926[1] = fRec926[0];
			fRec924[1] = fRec924[0];
			fRec923[1] = fRec923[0];
			fRec921[1] = fRec921[0];
			fRec932[1] = fRec932[0];
			fRec930[1] = fRec930[0];
			fRec938[1] = fRec938[0];
			fRec936[1] = fRec936[0];
			fRec935[1] = fRec935[0];
			fRec933[1] = fRec933[0];
			fRec953[1] = fRec953[0];
			fRec951[1] = fRec951[0];
			fRec950[1] = fRec950[0];
			fRec948[1] = fRec948[0];
			fRec947[1] = fRec947[0];
			fRec945[1] = fRec945[0];
			fRec944[1] = fRec944[0];
			fRec942[1] = fRec942[0];
			fRec941[1] = fRec941[0];
			fRec939[1] = fRec939[0];
			fRec965[1] = fRec965[0];
			fRec963[1] = fRec963[0];
			fRec962[1] = fRec962[0];
			fRec960[1] = fRec960[0];
			fRec959[1] = fRec959[0];
			fRec957[1] = fRec957[0];
			fRec956[1] = fRec956[0];
			fRec954[1] = fRec954[0];
			fRec974[1] = fRec974[0];
			fRec972[1] = fRec972[0];
			fRec971[1] = fRec971[0];
			fRec969[1] = fRec969[0];
			fRec968[1] = fRec968[0];
			fRec966[1] = fRec966[0];
			fRec977[1] = fRec977[0];
			fRec975[1] = fRec975[0];
			fRec983[1] = fRec983[0];
			fRec981[1] = fRec981[0];
			fRec980[1] = fRec980[0];
			fRec978[1] = fRec978[0];
			fRec998[1] = fRec998[0];
			fRec996[1] = fRec996[0];
			fRec995[1] = fRec995[0];
			fRec993[1] = fRec993[0];
			fRec992[1] = fRec992[0];
			fRec990[1] = fRec990[0];
			fRec989[1] = fRec989[0];
			fRec987[1] = fRec987[0];
			fRec986[1] = fRec986[0];
			fRec984[1] = fRec984[0];
			fRec1010[1] = fRec1010[0];
			fRec1008[1] = fRec1008[0];
			fRec1007[1] = fRec1007[0];
			fRec1005[1] = fRec1005[0];
			fRec1004[1] = fRec1004[0];
			fRec1002[1] = fRec1002[0];
			fRec1001[1] = fRec1001[0];
			fRec999[1] = fRec999[0];
			fRec1019[1] = fRec1019[0];
			fRec1017[1] = fRec1017[0];
			fRec1016[1] = fRec1016[0];
			fRec1014[1] = fRec1014[0];
			fRec1013[1] = fRec1013[0];
			fRec1011[1] = fRec1011[0];
			fRec1022[1] = fRec1022[0];
			fRec1020[1] = fRec1020[0];
			fRec1028[1] = fRec1028[0];
			fRec1026[1] = fRec1026[0];
			fRec1025[1] = fRec1025[0];
			fRec1023[1] = fRec1023[0];
			fRec1043[1] = fRec1043[0];
			fRec1041[1] = fRec1041[0];
			fRec1040[1] = fRec1040[0];
			fRec1038[1] = fRec1038[0];
			fRec1037[1] = fRec1037[0];
			fRec1035[1] = fRec1035[0];
			fRec1034[1] = fRec1034[0];
			fRec1032[1] = fRec1032[0];
			fRec1031[1] = fRec1031[0];
			fRec1029[1] = fRec1029[0];
			fRec1055[1] = fRec1055[0];
			fRec1053[1] = fRec1053[0];
			fRec1052[1] = fRec1052[0];
			fRec1050[1] = fRec1050[0];
			fRec1049[1] = fRec1049[0];
			fRec1047[1] = fRec1047[0];
			fRec1046[1] = fRec1046[0];
			fRec1044[1] = fRec1044[0];
			fRec1064[1] = fRec1064[0];
			fRec1062[1] = fRec1062[0];
			fRec1061[1] = fRec1061[0];
			fRec1059[1] = fRec1059[0];
			fRec1058[1] = fRec1058[0];
			fRec1056[1] = fRec1056[0];
			fRec1067[1] = fRec1067[0];
			fRec1065[1] = fRec1065[0];
			fRec1073[1] = fRec1073[0];
			fRec1071[1] = fRec1071[0];
			fRec1070[1] = fRec1070[0];
			fRec1068[1] = fRec1068[0];
			fRec1088[1] = fRec1088[0];
			fRec1086[1] = fRec1086[0];
			fRec1085[1] = fRec1085[0];
			fRec1083[1] = fRec1083[0];
			fRec1082[1] = fRec1082[0];
			fRec1080[1] = fRec1080[0];
			fRec1079[1] = fRec1079[0];
			fRec1077[1] = fRec1077[0];
			fRec1076[1] = fRec1076[0];
			fRec1074[1] = fRec1074[0];
			fRec1100[1] = fRec1100[0];
			fRec1098[1] = fRec1098[0];
			fRec1097[1] = fRec1097[0];
			fRec1095[1] = fRec1095[0];
			fRec1094[1] = fRec1094[0];
			fRec1092[1] = fRec1092[0];
			fRec1091[1] = fRec1091[0];
			fRec1089[1] = fRec1089[0];
			fRec1109[1] = fRec1109[0];
			fRec1107[1] = fRec1107[0];
			fRec1106[1] = fRec1106[0];
			fRec1104[1] = fRec1104[0];
			fRec1103[1] = fRec1103[0];
			fRec1101[1] = fRec1101[0];
			fRec1112[1] = fRec1112[0];
			fRec1110[1] = fRec1110[0];
			fRec1118[1] = fRec1118[0];
			fRec1116[1] = fRec1116[0];
			fRec1115[1] = fRec1115[0];
			fRec1113[1] = fRec1113[0];
			fRec1133[1] = fRec1133[0];
			fRec1131[1] = fRec1131[0];
			fRec1130[1] = fRec1130[0];
			fRec1128[1] = fRec1128[0];
			fRec1127[1] = fRec1127[0];
			fRec1125[1] = fRec1125[0];
			fRec1124[1] = fRec1124[0];
			fRec1122[1] = fRec1122[0];
			fRec1121[1] = fRec1121[0];
			fRec1119[1] = fRec1119[0];
			fRec1145[1] = fRec1145[0];
			fRec1143[1] = fRec1143[0];
			fRec1142[1] = fRec1142[0];
			fRec1140[1] = fRec1140[0];
			fRec1139[1] = fRec1139[0];
			fRec1137[1] = fRec1137[0];
			fRec1136[1] = fRec1136[0];
			fRec1134[1] = fRec1134[0];
			fRec1154[1] = fRec1154[0];
			fRec1152[1] = fRec1152[0];
			fRec1151[1] = fRec1151[0];
			fRec1149[1] = fRec1149[0];
			fRec1148[1] = fRec1148[0];
			fRec1146[1] = fRec1146[0];
			fRec1157[1] = fRec1157[0];
			fRec1155[1] = fRec1155[0];
			fRec1163[1] = fRec1163[0];
			fRec1161[1] = fRec1161[0];
			fRec1160[1] = fRec1160[0];
			fRec1158[1] = fRec1158[0];
			for (int j0 = 11; (j0 > 0); j0 = (j0 - 1)) {
				fVec24[j0] = fVec24[(j0 - 1)];
				
			}
			fRec1178[1] = fRec1178[0];
			fRec1176[1] = fRec1176[0];
			fRec1175[1] = fRec1175[0];
			fRec1173[1] = fRec1173[0];
			fRec1172[1] = fRec1172[0];
			fRec1170[1] = fRec1170[0];
			fRec1169[1] = fRec1169[0];
			fRec1167[1] = fRec1167[0];
			fRec1166[1] = fRec1166[0];
			fRec1164[1] = fRec1164[0];
			fRec1190[1] = fRec1190[0];
			fRec1188[1] = fRec1188[0];
			fRec1187[1] = fRec1187[0];
			fRec1185[1] = fRec1185[0];
			fRec1184[1] = fRec1184[0];
			fRec1182[1] = fRec1182[0];
			fRec1181[1] = fRec1181[0];
			fRec1179[1] = fRec1179[0];
			fRec1199[1] = fRec1199[0];
			fRec1197[1] = fRec1197[0];
			fRec1196[1] = fRec1196[0];
			fRec1194[1] = fRec1194[0];
			fRec1193[1] = fRec1193[0];
			fRec1191[1] = fRec1191[0];
			fRec1202[1] = fRec1202[0];
			fRec1200[1] = fRec1200[0];
			fRec1208[1] = fRec1208[0];
			fRec1206[1] = fRec1206[0];
			fRec1205[1] = fRec1205[0];
			fRec1203[1] = fRec1203[0];
			for (int j1 = 11; (j1 > 0); j1 = (j1 - 1)) {
				fVec25[j1] = fVec25[(j1 - 1)];
				
			}
			fRec1223[1] = fRec1223[0];
			fRec1221[1] = fRec1221[0];
			fRec1220[1] = fRec1220[0];
			fRec1218[1] = fRec1218[0];
			fRec1217[1] = fRec1217[0];
			fRec1215[1] = fRec1215[0];
			fRec1214[1] = fRec1214[0];
			fRec1212[1] = fRec1212[0];
			fRec1211[1] = fRec1211[0];
			fRec1209[1] = fRec1209[0];
			fRec1235[1] = fRec1235[0];
			fRec1233[1] = fRec1233[0];
			fRec1232[1] = fRec1232[0];
			fRec1230[1] = fRec1230[0];
			fRec1229[1] = fRec1229[0];
			fRec1227[1] = fRec1227[0];
			fRec1226[1] = fRec1226[0];
			fRec1224[1] = fRec1224[0];
			fRec1244[1] = fRec1244[0];
			fRec1242[1] = fRec1242[0];
			fRec1241[1] = fRec1241[0];
			fRec1239[1] = fRec1239[0];
			fRec1238[1] = fRec1238[0];
			fRec1236[1] = fRec1236[0];
			fRec1247[1] = fRec1247[0];
			fRec1245[1] = fRec1245[0];
			fRec1253[1] = fRec1253[0];
			fRec1251[1] = fRec1251[0];
			fRec1250[1] = fRec1250[0];
			fRec1248[1] = fRec1248[0];
			for (int j2 = 11; (j2 > 0); j2 = (j2 - 1)) {
				fVec26[j2] = fVec26[(j2 - 1)];
				
			}
			fRec1268[1] = fRec1268[0];
			fRec1266[1] = fRec1266[0];
			fRec1265[1] = fRec1265[0];
			fRec1263[1] = fRec1263[0];
			fRec1262[1] = fRec1262[0];
			fRec1260[1] = fRec1260[0];
			fRec1259[1] = fRec1259[0];
			fRec1257[1] = fRec1257[0];
			fRec1256[1] = fRec1256[0];
			fRec1254[1] = fRec1254[0];
			fRec1280[1] = fRec1280[0];
			fRec1278[1] = fRec1278[0];
			fRec1277[1] = fRec1277[0];
			fRec1275[1] = fRec1275[0];
			fRec1274[1] = fRec1274[0];
			fRec1272[1] = fRec1272[0];
			fRec1271[1] = fRec1271[0];
			fRec1269[1] = fRec1269[0];
			fRec1289[1] = fRec1289[0];
			fRec1287[1] = fRec1287[0];
			fRec1286[1] = fRec1286[0];
			fRec1284[1] = fRec1284[0];
			fRec1283[1] = fRec1283[0];
			fRec1281[1] = fRec1281[0];
			fRec1292[1] = fRec1292[0];
			fRec1290[1] = fRec1290[0];
			fRec1298[1] = fRec1298[0];
			fRec1296[1] = fRec1296[0];
			fRec1295[1] = fRec1295[0];
			fRec1293[1] = fRec1293[0];
			for (int j3 = 11; (j3 > 0); j3 = (j3 - 1)) {
				fVec27[j3] = fVec27[(j3 - 1)];
				
			}
			fRec1313[1] = fRec1313[0];
			fRec1311[1] = fRec1311[0];
			fRec1310[1] = fRec1310[0];
			fRec1308[1] = fRec1308[0];
			fRec1307[1] = fRec1307[0];
			fRec1305[1] = fRec1305[0];
			fRec1304[1] = fRec1304[0];
			fRec1302[1] = fRec1302[0];
			fRec1301[1] = fRec1301[0];
			fRec1299[1] = fRec1299[0];
			fRec1325[1] = fRec1325[0];
			fRec1323[1] = fRec1323[0];
			fRec1322[1] = fRec1322[0];
			fRec1320[1] = fRec1320[0];
			fRec1319[1] = fRec1319[0];
			fRec1317[1] = fRec1317[0];
			fRec1316[1] = fRec1316[0];
			fRec1314[1] = fRec1314[0];
			fRec1334[1] = fRec1334[0];
			fRec1332[1] = fRec1332[0];
			fRec1331[1] = fRec1331[0];
			fRec1329[1] = fRec1329[0];
			fRec1328[1] = fRec1328[0];
			fRec1326[1] = fRec1326[0];
			fRec1337[1] = fRec1337[0];
			fRec1335[1] = fRec1335[0];
			fRec1343[1] = fRec1343[0];
			fRec1341[1] = fRec1341[0];
			fRec1340[1] = fRec1340[0];
			fRec1338[1] = fRec1338[0];
			fRec1358[1] = fRec1358[0];
			fRec1356[1] = fRec1356[0];
			fRec1355[1] = fRec1355[0];
			fRec1353[1] = fRec1353[0];
			fRec1352[1] = fRec1352[0];
			fRec1350[1] = fRec1350[0];
			fRec1349[1] = fRec1349[0];
			fRec1347[1] = fRec1347[0];
			fRec1346[1] = fRec1346[0];
			fRec1344[1] = fRec1344[0];
			fRec1370[1] = fRec1370[0];
			fRec1368[1] = fRec1368[0];
			fRec1367[1] = fRec1367[0];
			fRec1365[1] = fRec1365[0];
			fRec1364[1] = fRec1364[0];
			fRec1362[1] = fRec1362[0];
			fRec1361[1] = fRec1361[0];
			fRec1359[1] = fRec1359[0];
			fRec1379[1] = fRec1379[0];
			fRec1377[1] = fRec1377[0];
			fRec1376[1] = fRec1376[0];
			fRec1374[1] = fRec1374[0];
			fRec1373[1] = fRec1373[0];
			fRec1371[1] = fRec1371[0];
			fRec1382[1] = fRec1382[0];
			fRec1380[1] = fRec1380[0];
			fRec1388[1] = fRec1388[0];
			fRec1386[1] = fRec1386[0];
			fRec1385[1] = fRec1385[0];
			fRec1383[1] = fRec1383[0];
			fRec1403[1] = fRec1403[0];
			fRec1401[1] = fRec1401[0];
			fRec1400[1] = fRec1400[0];
			fRec1398[1] = fRec1398[0];
			fRec1397[1] = fRec1397[0];
			fRec1395[1] = fRec1395[0];
			fRec1394[1] = fRec1394[0];
			fRec1392[1] = fRec1392[0];
			fRec1391[1] = fRec1391[0];
			fRec1389[1] = fRec1389[0];
			fRec1415[1] = fRec1415[0];
			fRec1413[1] = fRec1413[0];
			fRec1412[1] = fRec1412[0];
			fRec1410[1] = fRec1410[0];
			fRec1409[1] = fRec1409[0];
			fRec1407[1] = fRec1407[0];
			fRec1406[1] = fRec1406[0];
			fRec1404[1] = fRec1404[0];
			fRec1424[1] = fRec1424[0];
			fRec1422[1] = fRec1422[0];
			fRec1421[1] = fRec1421[0];
			fRec1419[1] = fRec1419[0];
			fRec1418[1] = fRec1418[0];
			fRec1416[1] = fRec1416[0];
			fRec1427[1] = fRec1427[0];
			fRec1425[1] = fRec1425[0];
			fRec1433[1] = fRec1433[0];
			fRec1431[1] = fRec1431[0];
			fRec1430[1] = fRec1430[0];
			fRec1428[1] = fRec1428[0];
			fRec1448[1] = fRec1448[0];
			fRec1446[1] = fRec1446[0];
			fRec1445[1] = fRec1445[0];
			fRec1443[1] = fRec1443[0];
			fRec1442[1] = fRec1442[0];
			fRec1440[1] = fRec1440[0];
			fRec1439[1] = fRec1439[0];
			fRec1437[1] = fRec1437[0];
			fRec1436[1] = fRec1436[0];
			fRec1434[1] = fRec1434[0];
			fRec1460[1] = fRec1460[0];
			fRec1458[1] = fRec1458[0];
			fRec1457[1] = fRec1457[0];
			fRec1455[1] = fRec1455[0];
			fRec1454[1] = fRec1454[0];
			fRec1452[1] = fRec1452[0];
			fRec1451[1] = fRec1451[0];
			fRec1449[1] = fRec1449[0];
			fRec1469[1] = fRec1469[0];
			fRec1467[1] = fRec1467[0];
			fRec1466[1] = fRec1466[0];
			fRec1464[1] = fRec1464[0];
			fRec1463[1] = fRec1463[0];
			fRec1461[1] = fRec1461[0];
			fRec1472[1] = fRec1472[0];
			fRec1470[1] = fRec1470[0];
			fRec1478[1] = fRec1478[0];
			fRec1476[1] = fRec1476[0];
			fRec1475[1] = fRec1475[0];
			fRec1473[1] = fRec1473[0];
			fRec1493[1] = fRec1493[0];
			fRec1491[1] = fRec1491[0];
			fRec1490[1] = fRec1490[0];
			fRec1488[1] = fRec1488[0];
			fRec1487[1] = fRec1487[0];
			fRec1485[1] = fRec1485[0];
			fRec1484[1] = fRec1484[0];
			fRec1482[1] = fRec1482[0];
			fRec1481[1] = fRec1481[0];
			fRec1479[1] = fRec1479[0];
			fRec1505[1] = fRec1505[0];
			fRec1503[1] = fRec1503[0];
			fRec1502[1] = fRec1502[0];
			fRec1500[1] = fRec1500[0];
			fRec1499[1] = fRec1499[0];
			fRec1497[1] = fRec1497[0];
			fRec1496[1] = fRec1496[0];
			fRec1494[1] = fRec1494[0];
			fRec1514[1] = fRec1514[0];
			fRec1512[1] = fRec1512[0];
			fRec1511[1] = fRec1511[0];
			fRec1509[1] = fRec1509[0];
			fRec1508[1] = fRec1508[0];
			fRec1506[1] = fRec1506[0];
			fRec1517[1] = fRec1517[0];
			fRec1515[1] = fRec1515[0];
			fRec1523[1] = fRec1523[0];
			fRec1521[1] = fRec1521[0];
			fRec1520[1] = fRec1520[0];
			fRec1518[1] = fRec1518[0];
			fRec1538[1] = fRec1538[0];
			fRec1536[1] = fRec1536[0];
			fRec1535[1] = fRec1535[0];
			fRec1533[1] = fRec1533[0];
			fRec1532[1] = fRec1532[0];
			fRec1530[1] = fRec1530[0];
			fRec1529[1] = fRec1529[0];
			fRec1527[1] = fRec1527[0];
			fRec1526[1] = fRec1526[0];
			fRec1524[1] = fRec1524[0];
			fRec1550[1] = fRec1550[0];
			fRec1548[1] = fRec1548[0];
			fRec1547[1] = fRec1547[0];
			fRec1545[1] = fRec1545[0];
			fRec1544[1] = fRec1544[0];
			fRec1542[1] = fRec1542[0];
			fRec1541[1] = fRec1541[0];
			fRec1539[1] = fRec1539[0];
			fRec1559[1] = fRec1559[0];
			fRec1557[1] = fRec1557[0];
			fRec1556[1] = fRec1556[0];
			fRec1554[1] = fRec1554[0];
			fRec1553[1] = fRec1553[0];
			fRec1551[1] = fRec1551[0];
			fRec1562[1] = fRec1562[0];
			fRec1560[1] = fRec1560[0];
			fRec1568[1] = fRec1568[0];
			fRec1566[1] = fRec1566[0];
			fRec1565[1] = fRec1565[0];
			fRec1563[1] = fRec1563[0];
			fRec1583[1] = fRec1583[0];
			fRec1581[1] = fRec1581[0];
			fRec1580[1] = fRec1580[0];
			fRec1578[1] = fRec1578[0];
			fRec1577[1] = fRec1577[0];
			fRec1575[1] = fRec1575[0];
			fRec1574[1] = fRec1574[0];
			fRec1572[1] = fRec1572[0];
			fRec1571[1] = fRec1571[0];
			fRec1569[1] = fRec1569[0];
			fRec1595[1] = fRec1595[0];
			fRec1593[1] = fRec1593[0];
			fRec1592[1] = fRec1592[0];
			fRec1590[1] = fRec1590[0];
			fRec1589[1] = fRec1589[0];
			fRec1587[1] = fRec1587[0];
			fRec1586[1] = fRec1586[0];
			fRec1584[1] = fRec1584[0];
			fRec1604[1] = fRec1604[0];
			fRec1602[1] = fRec1602[0];
			fRec1601[1] = fRec1601[0];
			fRec1599[1] = fRec1599[0];
			fRec1598[1] = fRec1598[0];
			fRec1596[1] = fRec1596[0];
			fRec1607[1] = fRec1607[0];
			fRec1605[1] = fRec1605[0];
			fRec1613[1] = fRec1613[0];
			fRec1611[1] = fRec1611[0];
			fRec1610[1] = fRec1610[0];
			fRec1608[1] = fRec1608[0];
			fRec1628[1] = fRec1628[0];
			fRec1626[1] = fRec1626[0];
			fRec1625[1] = fRec1625[0];
			fRec1623[1] = fRec1623[0];
			fRec1622[1] = fRec1622[0];
			fRec1620[1] = fRec1620[0];
			fRec1619[1] = fRec1619[0];
			fRec1617[1] = fRec1617[0];
			fRec1616[1] = fRec1616[0];
			fRec1614[1] = fRec1614[0];
			fRec1640[1] = fRec1640[0];
			fRec1638[1] = fRec1638[0];
			fRec1637[1] = fRec1637[0];
			fRec1635[1] = fRec1635[0];
			fRec1634[1] = fRec1634[0];
			fRec1632[1] = fRec1632[0];
			fRec1631[1] = fRec1631[0];
			fRec1629[1] = fRec1629[0];
			fRec1649[1] = fRec1649[0];
			fRec1647[1] = fRec1647[0];
			fRec1646[1] = fRec1646[0];
			fRec1644[1] = fRec1644[0];
			fRec1643[1] = fRec1643[0];
			fRec1641[1] = fRec1641[0];
			fRec1652[1] = fRec1652[0];
			fRec1650[1] = fRec1650[0];
			fRec1658[1] = fRec1658[0];
			fRec1656[1] = fRec1656[0];
			fRec1655[1] = fRec1655[0];
			fRec1653[1] = fRec1653[0];
			fRec1673[1] = fRec1673[0];
			fRec1671[1] = fRec1671[0];
			fRec1670[1] = fRec1670[0];
			fRec1668[1] = fRec1668[0];
			fRec1667[1] = fRec1667[0];
			fRec1665[1] = fRec1665[0];
			fRec1664[1] = fRec1664[0];
			fRec1662[1] = fRec1662[0];
			fRec1661[1] = fRec1661[0];
			fRec1659[1] = fRec1659[0];
			fRec1685[1] = fRec1685[0];
			fRec1683[1] = fRec1683[0];
			fRec1682[1] = fRec1682[0];
			fRec1680[1] = fRec1680[0];
			fRec1679[1] = fRec1679[0];
			fRec1677[1] = fRec1677[0];
			fRec1676[1] = fRec1676[0];
			fRec1674[1] = fRec1674[0];
			fRec1694[1] = fRec1694[0];
			fRec1692[1] = fRec1692[0];
			fRec1691[1] = fRec1691[0];
			fRec1689[1] = fRec1689[0];
			fRec1688[1] = fRec1688[0];
			fRec1686[1] = fRec1686[0];
			fRec1697[1] = fRec1697[0];
			fRec1695[1] = fRec1695[0];
			fRec1703[1] = fRec1703[0];
			fRec1701[1] = fRec1701[0];
			fRec1700[1] = fRec1700[0];
			fRec1698[1] = fRec1698[0];
			fRec1718[1] = fRec1718[0];
			fRec1716[1] = fRec1716[0];
			fRec1715[1] = fRec1715[0];
			fRec1713[1] = fRec1713[0];
			fRec1712[1] = fRec1712[0];
			fRec1710[1] = fRec1710[0];
			fRec1709[1] = fRec1709[0];
			fRec1707[1] = fRec1707[0];
			fRec1706[1] = fRec1706[0];
			fRec1704[1] = fRec1704[0];
			fRec1730[1] = fRec1730[0];
			fRec1728[1] = fRec1728[0];
			fRec1727[1] = fRec1727[0];
			fRec1725[1] = fRec1725[0];
			fRec1724[1] = fRec1724[0];
			fRec1722[1] = fRec1722[0];
			fRec1721[1] = fRec1721[0];
			fRec1719[1] = fRec1719[0];
			fRec1739[1] = fRec1739[0];
			fRec1737[1] = fRec1737[0];
			fRec1736[1] = fRec1736[0];
			fRec1734[1] = fRec1734[0];
			fRec1733[1] = fRec1733[0];
			fRec1731[1] = fRec1731[0];
			fRec1742[1] = fRec1742[0];
			fRec1740[1] = fRec1740[0];
			fRec1748[1] = fRec1748[0];
			fRec1746[1] = fRec1746[0];
			fRec1745[1] = fRec1745[0];
			fRec1743[1] = fRec1743[0];
			fRec1763[1] = fRec1763[0];
			fRec1761[1] = fRec1761[0];
			fRec1760[1] = fRec1760[0];
			fRec1758[1] = fRec1758[0];
			fRec1757[1] = fRec1757[0];
			fRec1755[1] = fRec1755[0];
			fRec1754[1] = fRec1754[0];
			fRec1752[1] = fRec1752[0];
			fRec1751[1] = fRec1751[0];
			fRec1749[1] = fRec1749[0];
			fRec1775[1] = fRec1775[0];
			fRec1773[1] = fRec1773[0];
			fRec1772[1] = fRec1772[0];
			fRec1770[1] = fRec1770[0];
			fRec1769[1] = fRec1769[0];
			fRec1767[1] = fRec1767[0];
			fRec1766[1] = fRec1766[0];
			fRec1764[1] = fRec1764[0];
			fRec1784[1] = fRec1784[0];
			fRec1782[1] = fRec1782[0];
			fRec1781[1] = fRec1781[0];
			fRec1779[1] = fRec1779[0];
			fRec1778[1] = fRec1778[0];
			fRec1776[1] = fRec1776[0];
			fRec1787[1] = fRec1787[0];
			fRec1785[1] = fRec1785[0];
			fRec1793[1] = fRec1793[0];
			fRec1791[1] = fRec1791[0];
			fRec1790[1] = fRec1790[0];
			fRec1788[1] = fRec1788[0];
			fRec1808[1] = fRec1808[0];
			fRec1806[1] = fRec1806[0];
			fRec1805[1] = fRec1805[0];
			fRec1803[1] = fRec1803[0];
			fRec1802[1] = fRec1802[0];
			fRec1800[1] = fRec1800[0];
			fRec1799[1] = fRec1799[0];
			fRec1797[1] = fRec1797[0];
			fRec1796[1] = fRec1796[0];
			fRec1794[1] = fRec1794[0];
			fRec1820[1] = fRec1820[0];
			fRec1818[1] = fRec1818[0];
			fRec1817[1] = fRec1817[0];
			fRec1815[1] = fRec1815[0];
			fRec1814[1] = fRec1814[0];
			fRec1812[1] = fRec1812[0];
			fRec1811[1] = fRec1811[0];
			fRec1809[1] = fRec1809[0];
			fRec1829[1] = fRec1829[0];
			fRec1827[1] = fRec1827[0];
			fRec1826[1] = fRec1826[0];
			fRec1824[1] = fRec1824[0];
			fRec1823[1] = fRec1823[0];
			fRec1821[1] = fRec1821[0];
			fRec1832[1] = fRec1832[0];
			fRec1830[1] = fRec1830[0];
			fRec1838[1] = fRec1838[0];
			fRec1836[1] = fRec1836[0];
			fRec1835[1] = fRec1835[0];
			fRec1833[1] = fRec1833[0];
			fRec1853[1] = fRec1853[0];
			fRec1851[1] = fRec1851[0];
			fRec1850[1] = fRec1850[0];
			fRec1848[1] = fRec1848[0];
			fRec1847[1] = fRec1847[0];
			fRec1845[1] = fRec1845[0];
			fRec1844[1] = fRec1844[0];
			fRec1842[1] = fRec1842[0];
			fRec1841[1] = fRec1841[0];
			fRec1839[1] = fRec1839[0];
			fRec1865[1] = fRec1865[0];
			fRec1863[1] = fRec1863[0];
			fRec1862[1] = fRec1862[0];
			fRec1860[1] = fRec1860[0];
			fRec1859[1] = fRec1859[0];
			fRec1857[1] = fRec1857[0];
			fRec1856[1] = fRec1856[0];
			fRec1854[1] = fRec1854[0];
			fRec1874[1] = fRec1874[0];
			fRec1872[1] = fRec1872[0];
			fRec1871[1] = fRec1871[0];
			fRec1869[1] = fRec1869[0];
			fRec1868[1] = fRec1868[0];
			fRec1866[1] = fRec1866[0];
			fRec1877[1] = fRec1877[0];
			fRec1875[1] = fRec1875[0];
			fRec1883[1] = fRec1883[0];
			fRec1881[1] = fRec1881[0];
			fRec1880[1] = fRec1880[0];
			fRec1878[1] = fRec1878[0];
			fRec1898[1] = fRec1898[0];
			fRec1896[1] = fRec1896[0];
			fRec1895[1] = fRec1895[0];
			fRec1893[1] = fRec1893[0];
			fRec1892[1] = fRec1892[0];
			fRec1890[1] = fRec1890[0];
			fRec1889[1] = fRec1889[0];
			fRec1887[1] = fRec1887[0];
			fRec1886[1] = fRec1886[0];
			fRec1884[1] = fRec1884[0];
			fRec1910[1] = fRec1910[0];
			fRec1908[1] = fRec1908[0];
			fRec1907[1] = fRec1907[0];
			fRec1905[1] = fRec1905[0];
			fRec1904[1] = fRec1904[0];
			fRec1902[1] = fRec1902[0];
			fRec1901[1] = fRec1901[0];
			fRec1899[1] = fRec1899[0];
			fRec1919[1] = fRec1919[0];
			fRec1917[1] = fRec1917[0];
			fRec1916[1] = fRec1916[0];
			fRec1914[1] = fRec1914[0];
			fRec1913[1] = fRec1913[0];
			fRec1911[1] = fRec1911[0];
			fRec1922[1] = fRec1922[0];
			fRec1920[1] = fRec1920[0];
			fRec1928[1] = fRec1928[0];
			fRec1926[1] = fRec1926[0];
			fRec1925[1] = fRec1925[0];
			fRec1923[1] = fRec1923[0];
			fRec1943[1] = fRec1943[0];
			fRec1941[1] = fRec1941[0];
			fRec1940[1] = fRec1940[0];
			fRec1938[1] = fRec1938[0];
			fRec1937[1] = fRec1937[0];
			fRec1935[1] = fRec1935[0];
			fRec1934[1] = fRec1934[0];
			fRec1932[1] = fRec1932[0];
			fRec1931[1] = fRec1931[0];
			fRec1929[1] = fRec1929[0];
			fRec1955[1] = fRec1955[0];
			fRec1953[1] = fRec1953[0];
			fRec1952[1] = fRec1952[0];
			fRec1950[1] = fRec1950[0];
			fRec1949[1] = fRec1949[0];
			fRec1947[1] = fRec1947[0];
			fRec1946[1] = fRec1946[0];
			fRec1944[1] = fRec1944[0];
			fRec1964[1] = fRec1964[0];
			fRec1962[1] = fRec1962[0];
			fRec1961[1] = fRec1961[0];
			fRec1959[1] = fRec1959[0];
			fRec1958[1] = fRec1958[0];
			fRec1956[1] = fRec1956[0];
			fRec1967[1] = fRec1967[0];
			fRec1965[1] = fRec1965[0];
			fRec1973[1] = fRec1973[0];
			fRec1971[1] = fRec1971[0];
			fRec1970[1] = fRec1970[0];
			fRec1968[1] = fRec1968[0];
			fRec1988[1] = fRec1988[0];
			fRec1986[1] = fRec1986[0];
			fRec1985[1] = fRec1985[0];
			fRec1983[1] = fRec1983[0];
			fRec1982[1] = fRec1982[0];
			fRec1980[1] = fRec1980[0];
			fRec1979[1] = fRec1979[0];
			fRec1977[1] = fRec1977[0];
			fRec1976[1] = fRec1976[0];
			fRec1974[1] = fRec1974[0];
			fRec2000[1] = fRec2000[0];
			fRec1998[1] = fRec1998[0];
			fRec1997[1] = fRec1997[0];
			fRec1995[1] = fRec1995[0];
			fRec1994[1] = fRec1994[0];
			fRec1992[1] = fRec1992[0];
			fRec1991[1] = fRec1991[0];
			fRec1989[1] = fRec1989[0];
			fRec2009[1] = fRec2009[0];
			fRec2007[1] = fRec2007[0];
			fRec2006[1] = fRec2006[0];
			fRec2004[1] = fRec2004[0];
			fRec2003[1] = fRec2003[0];
			fRec2001[1] = fRec2001[0];
			fRec2012[1] = fRec2012[0];
			fRec2010[1] = fRec2010[0];
			fRec2018[1] = fRec2018[0];
			fRec2016[1] = fRec2016[0];
			fRec2015[1] = fRec2015[0];
			fRec2013[1] = fRec2013[0];
			fRec2033[1] = fRec2033[0];
			fRec2031[1] = fRec2031[0];
			fRec2030[1] = fRec2030[0];
			fRec2028[1] = fRec2028[0];
			fRec2027[1] = fRec2027[0];
			fRec2025[1] = fRec2025[0];
			fRec2024[1] = fRec2024[0];
			fRec2022[1] = fRec2022[0];
			fRec2021[1] = fRec2021[0];
			fRec2019[1] = fRec2019[0];
			fRec2045[1] = fRec2045[0];
			fRec2043[1] = fRec2043[0];
			fRec2042[1] = fRec2042[0];
			fRec2040[1] = fRec2040[0];
			fRec2039[1] = fRec2039[0];
			fRec2037[1] = fRec2037[0];
			fRec2036[1] = fRec2036[0];
			fRec2034[1] = fRec2034[0];
			fRec2054[1] = fRec2054[0];
			fRec2052[1] = fRec2052[0];
			fRec2051[1] = fRec2051[0];
			fRec2049[1] = fRec2049[0];
			fRec2048[1] = fRec2048[0];
			fRec2046[1] = fRec2046[0];
			fRec2057[1] = fRec2057[0];
			fRec2055[1] = fRec2055[0];
			fRec2063[1] = fRec2063[0];
			fRec2061[1] = fRec2061[0];
			fRec2060[1] = fRec2060[0];
			fRec2058[1] = fRec2058[0];
			
		}
		
	}

	
};

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

/* Faust code wrapper ------- */

#include "ext.h"
#include "ext_obex.h"
#include "z_dsp.h"
#include "jpatcher_api.h"
#include <string.h>

#define ASSIST_INLET 	1  	/* should be defined somewhere ?? */
#define ASSIST_OUTLET 	2	/* should be defined somewhere ?? */

#define EXTERNAL_VERSION    "0.64"
#define STR_SIZE            512

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
#pragma warning (disable: 4334)
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

ringbuffer_t *ringbuffer_create(size_t sz);
void ringbuffer_free(ringbuffer_t *rb);
void ringbuffer_get_read_vector(const ringbuffer_t *rb,
                                         ringbuffer_data_t *vec);
void ringbuffer_get_write_vector(const ringbuffer_t *rb,
                                          ringbuffer_data_t *vec);
size_t ringbuffer_read(ringbuffer_t *rb, char *dest, size_t cnt);
size_t ringbuffer_peek(ringbuffer_t *rb, char *dest, size_t cnt);
void ringbuffer_read_advance(ringbuffer_t *rb, size_t cnt);
size_t ringbuffer_read_space(const ringbuffer_t *rb);
int ringbuffer_mlock(ringbuffer_t *rb);
void ringbuffer_reset(ringbuffer_t *rb);
void ringbuffer_reset_size (ringbuffer_t * rb, size_t sz);
size_t ringbuffer_write(ringbuffer_t *rb, const char *src,
                                 size_t cnt);
void ringbuffer_write_advance(ringbuffer_t *rb, size_t cnt);
size_t ringbuffer_write_space(const ringbuffer_t *rb);

/* Create a new ringbuffer to hold at least `sz' bytes of data. The
   actual buffer size is rounded up to the next power of two. */

inline ringbuffer_t *
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

inline void
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

inline int
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

inline void
ringbuffer_reset (ringbuffer_t * rb)
{
	rb->read_ptr = 0;
	rb->write_ptr = 0;
    memset(rb->buf, 0, rb->size);
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

inline void
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

inline size_t
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

inline size_t
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

inline size_t
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

inline size_t
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

inline size_t
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

inline void
ringbuffer_read_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->read_ptr + cnt) & rb->size_mask;
	rb->read_ptr = tmp;
}

/* Advance the write pointer `cnt' places. */

inline void
ringbuffer_write_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->write_ptr + cnt) & rb->size_mask;
	rb->write_ptr = tmp;
}

/* The non-copying data reader. `vec' is an array of two places. Set
   the values at `vec' to hold the current readable data at `rb'. If
   the readable data is in one segment the second segment has zero
   length. */

inline void
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

inline void
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

/*******************************************************************************
 * GUI : Abstract Graphic User Interface
 * Provides additional mechanisms to synchronize widgets and zones. Widgets
 * should both reflect the value of a zone and allow to change this value.
 ******************************************************************************/

class uiItem;
typedef void (*uiCallback)(FAUSTFLOAT val, void* data);

class clist : public std::list<uiItem*>
{
    
    public:
    
        virtual ~clist();
        
};

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
        
        void registerZone(FAUSTFLOAT* z, uiItem* c)
        {
            if (fZoneMap.find(z) == fZoneMap.end()) fZoneMap[z] = new clist();
            fZoneMap[z]->push_back(c);
        }

        void updateAllZones();
        
        void updateZone(FAUSTFLOAT* z);
        
        static void updateAllGuis()
        {
            std::list<GUI*>::iterator g;
            for (g = fGuiList.begin(); g != fGuiList.end(); g++) {
                (*g)->updateAllZones();
            }
        }
        void addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data);
        virtual void show() {};	
        virtual bool run() { return false; };
    
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

class uiItem
{
    protected:
          
        GUI* fGUI;
        FAUSTFLOAT* fZone;
        FAUSTFLOAT fCache;

        uiItem(GUI* ui, FAUSTFLOAT* zone):fGUI(ui), fZone(zone), fCache(FAUSTFLOAT(-123456.654321))
        { 
            ui->registerZone(zone, this); 
        }

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
                
        FAUSTFLOAT cache() { return fCache; }
        virtual void reflectZone() = 0;
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

struct uiCallbackItem : public uiItem {
    
	uiCallback fCallback;
	void* fData;
	
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
 * Base class for timed items
 */

// For precise timestamped control
struct DatedControl {
    
    double fDate;
    FAUSTFLOAT fValue;
    
    DatedControl(double d = 0., FAUSTFLOAT v = FAUSTFLOAT(0)):fDate(d), fValue(v) {}
    
};

class uiTimedItem : public uiItem
{
    
    protected:
        
        bool fDelete;
        
    public:
        
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

/**
 * Update all user items reflecting zone z
 */

inline void GUI::updateZone(FAUSTFLOAT* z)
{
	FAUSTFLOAT v = *z;
	clist* l = fZoneMap[z];
	for (clist::iterator c = l->begin(); c != l->end(); c++) {
		if ((*c)->cache() != v) (*c)->reflectZone();
	}
}

/**
 * Update all user items not up to date
 */

inline void GUI::updateAllZones()
{
	for (zmap::iterator m = fZoneMap.begin(); m != fZoneMap.end(); m++) {
		FAUSTFLOAT* z = m->first;
		clist*	l = m->second;
        if (z) {
            FAUSTFLOAT v = *z;
            for (clist::iterator c = l->begin(); c != l->end(); c++) {
                if ((*c)->cache() != v) (*c)->reflectZone();
            }
        }
	}
}

inline void GUI::addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data) 
{ 
	new uiCallbackItem(this, zone, foo, data); 
};

inline clist::~clist() 
{
    std::list<uiItem*>::iterator it;
    for (it = begin(); it != end(); it++) {
        uiOwnedItem* owned = dynamic_cast<uiOwnedItem*>(*it);
        // owned items are deleted by external code
        if (!owned) {
            delete (*it);
        }
    }
}

#endif
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

class MapUI;

//----------------------------------------------------------------
//  MIDI processor definition
//----------------------------------------------------------------

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
        
        virtual void pitchWheel(double, int channel, int wheel)
        {
            pitchWheel(channel, wheel);
        }
           
        virtual void ctrlChange(double, int channel, int ctrl, int value)
        {
            ctrlChange(channel, ctrl, value);
        }
       
        virtual void progChange(double, int channel, int pgm)
        {
            progChange(channel, pgm);
        }
        
        virtual void keyPress(double, int channel, int pitch, int press)
        {
            keyPress(channel, pitch, press);
        }
        
        virtual void chanPress(double date, int channel, int press)
        {
            chanPress(channel, press);
        }
       
        virtual void ctrlChange14bits(double, int channel, int ctrl, int value)
        {
            ctrlChange14bits(channel, ctrl, value);
        }

        // MIDI sync
        virtual void start_sync(double date)  {}
        virtual void stop_sync(double date)   {}
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
            MIDI_STOP = 0xFC

        };

        enum MidiCtrl {

            ALL_NOTES_OFF = 123,
            ALL_SOUND_OFF = 120

        };
};

//----------------------------------------------------------------
//  Base class for MIDI API handling
//----------------------------------------------------------------

class midi_handler : public midi {

    protected:

        std::vector<midi*> fMidiInputs;
        std::string fName;

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

        virtual bool start_midi() { return true; }
        virtual void stop_midi() {}
    
        void setName(const std::string& name) { fName = name; }
        std::string getName() { return fName; }
        
        void handleSync(double time, int type)
        {
            if (type == MIDI_CLOCK) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->clock(time);
                }
            } else if (type == MIDI_START) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->start_sync(time);
                }
            } else if (type == MIDI_STOP) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->stop_sync(time);
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
                    fMidiInputs[i]->pitchWheel(time, channel, (data2 * 128.0) + data1);
                }
            } else if (type == MIDI_POLY_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyPress(time, channel, data1, data2);
                }
            }
        }

};

#endif // __midi__
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
    
    static void analyse(dsp* tmp_dsp, bool& midi_sync, int& nvoices)
    {
        JSONUI jsonui;
        tmp_dsp->buildUserInterface(&jsonui);
        std::string json = jsonui.JSON();
        midi_sync = ((json.find("midi") != std::string::npos) &&
                     ((json.find("start") != std::string::npos) ||
                      (json.find("stop") != std::string::npos) ||
                      (json.find("clock") != std::string::npos)));
    
    #if defined(NVOICES) && NVOICES!=NUM_VOICES
        nvoices = NVOICES;
    #else
        MidiMeta meta;
        tmp_dsp->metadata(&meta);
        std::string numVoices = meta.get("nvoices", "0");
        nvoices = std::atoi(numVoices.c_str());
        if (nvoices < 0) nvoices = 0;
    #endif
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

class uiMidiItem : public uiMidi, public uiItem {
    
    public:
        
        uiMidiItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidi(midi_out, input), uiItem(ui, zone)
        {}
        virtual ~uiMidiItem()
        {}
    
        virtual void reflectZone() {}
    
};

class uiMidiTimedItem : public uiMidi, public uiTimedItem {
    
    public:
        
        uiMidiTimedItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidi(midi_out, input), uiTimedItem(ui, zone)
        {}
        virtual ~uiMidiTimedItem()
        {}
    
        virtual void reflectZone() {}
    
};

// MIDI sync

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
                fMidiOut->start_sync(0);
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
                fMidiOut->stop_sync(0);
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

class uiMidiProgChange : public uiMidiItem
{
    
    private:
        
        int fPgm;
  
    public:
    
        uiMidiProgChange(midi* midi_out, int pgm, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fPgm(pgm)
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

class uiMidiChanPress : public uiMidiItem
{
    private:
        
        int fPress;
  
    public:
    
        uiMidiChanPress(midi* midi_out, int press, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fPress(press)
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

class uiMidiCtrlChange : public uiMidiItem
{
    private:
    
        int fCtrl;
        LinearValueConverter fConverter;
 
    public:
    
        uiMidiCtrlChange(midi* midi_out, int ctrl, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fCtrl(ctrl), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiCtrlChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->ctrlChange(0, fCtrl, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
 
};

class uiMidiPitchWheel : public uiMidiItem
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
            :uiMidiItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiPitchWheel()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->pitchWheel(0, bend2wheel(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(wheel2bend(v));
            }
        }
 
};

class uiMidiKeyOn : public uiMidiItem
{

    private:
        
        int fKeyOn;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOn(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKeyOn(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOn()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOn(0, fKeyOn, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class uiMidiKeyOff : public uiMidiItem
{

    private:
        
        int fKeyOff;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOff(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKeyOff(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOff()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOff(0, fKeyOff, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};


class uiMidiKeyPress : public uiMidiItem
{

    private:
    
        int fKey;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyPress(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKey(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyPress(0, fKey, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class MapUI;

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
                        } else if (strcmp(fMetaAux[i].second.c_str(), "pitchwheel") == 0 
                            || strcmp(fMetaAux[i].second.c_str(), "pitchbend") == 0) {
                            fPitchWheelTable.push_back(new uiMidiPitchWheel(fMidiHandler, this, zone, input));
                        // MIDI sync
                        } else if (strcmp(fMetaAux[i].second.c_str(), "start") == 0) {
                            fStartTable.push_back(new uiMidiStart(fMidiHandler, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "stop") == 0) {
                            fStopTable.push_back(new uiMidiStop(fMidiHandler, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "clock") == 0) {
                            fClockTable.push_back(new uiMidiClock(fMidiHandler, this, zone, input));
                        }
                    }
                }
            }
            fMetaAux.clear();
        }

    public:
    
        MidiUI():fMidiHandler(NULL), fDelete(false)
        {}

        MidiUI(midi_handler* midi_handler, bool delete_handler = false)
        {
            fMidiHandler = midi_handler;
            fMidiHandler->addMidiIn(this);
            fDelete = delete_handler;
        }
 
        virtual ~MidiUI() 
        { 
            fMidiHandler->removeMidiIn(this);
            if (fDelete) delete fMidiHandler;
        }
        
        bool run() { return fMidiHandler->start_midi(); }
        void stop() { fMidiHandler->stop_midi(); }
        
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
                for (unsigned int i = 0; i < fKeyOnTable[note].size(); i++) {
                    fKeyOnTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            // If note is in fKeyTable, handle it as a keyOn
            if (fKeyTable.find(note) != fKeyTable.end()) {
                for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                    fKeyTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            return 0;
        }
        
        void keyOff(double date, int channel, int note, int velocity)
        {
            if (fKeyOffTable.find(note) != fKeyOffTable.end()) {
                for (unsigned int i = 0; i < fKeyOffTable[note].size(); i++) {
                    fKeyOffTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            // If note is in fKeyTable, handle it as a keyOff with a 0 velocity
            if (fKeyTable.find(note) != fKeyTable.end()) {
                for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                    fKeyTable[note][i]->modifyZone(0);
                }
            }
        }
           
        void ctrlChange(double date, int channel, int ctrl, int value)
        {
            if (fCtrlChangeTable.find(ctrl) != fCtrlChangeTable.end()) {
                for (unsigned int i = 0; i < fCtrlChangeTable[ctrl].size(); i++) {
                    fCtrlChangeTable[ctrl][i]->modifyZone(FAUSTFLOAT(value));
                }
            } 
        }
        
        void progChange(double date, int channel, int pgm)
        {
            if (fProgChangeTable.find(pgm) != fProgChangeTable.end()) {
                for (unsigned int i = 0; i < fProgChangeTable[pgm].size(); i++) {
                    fProgChangeTable[pgm][i]->modifyZone(FAUSTFLOAT(1));
                }
            } 
        }
        
        void pitchWheel(double date, int channel, int wheel) 
        {
            for (unsigned int i = 0; i < fPitchWheelTable.size(); i++) {
                fPitchWheelTable[i]->modifyZone(FAUSTFLOAT(wheel));
            }
        }
        
        void keyPress(double date, int channel, int pitch, int press) 
        {
            if (fKeyPressTable.find(pitch) != fKeyPressTable.end()) {
                for (unsigned int i = 0; i < fKeyPressTable[pitch].size(); i++) {
                    fKeyPressTable[pitch][i]->modifyZone(FAUSTFLOAT(press));
                }
            } 
        }
        
        void chanPress(double date, int channel, int press)
        {
            if (fChanPressTable.find(press) != fChanPressTable.end()) {
                for (unsigned int i = 0; i < fChanPressTable[press].size(); i++) {
                    fChanPressTable[press][i]->modifyZone(FAUSTFLOAT(1));
                }
            } 
        }
        
        void ctrlChange14bits(double date, int channel, int ctrl, int value) {}
        
        // MIDI sync
        
        void start_sync(double date)
        {
            for (unsigned int i = 0; i < fStartTable.size(); i++) {
                fStartTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
        
        void stop_sync(double date)
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
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
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
};

#endif // FAUST_MAPUI_H
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
#include <assert.h>
#include <cstdlib>

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

using namespace std;

struct itemInfo {
    std::string type;
    std::string label;
    std::string address;
    std::string index;
    std::string init;
    std::string min;
    std::string max;
    std::string step;
    std::vector<std::pair<std::string, std::string> > meta;
};

bool parseMenuList(const char*& p, vector<string>& names, vector<double>& values);
bool parseMenuItem(const char*& p, string& name, double& value);

void skipBlank(const char*& p);
bool parseChar(const char*& p, char x);
bool parseWord(const char*& p, const char* w);
bool parseString(const char*& p, char quote, string& s);
bool parseSQString(const char*& p, string& s);
bool parseDQString(const char*& p, string& s);
bool parseDouble(const char*& p, double& x);

// ---------------------------------------------------------------------
//
//                          IMPLEMENTATION
// 
// ---------------------------------------------------------------------

/**
 * @brief parseMenuList, parse a menu list {'low' : 440.0; 'mid' : 880.0; 'hi' : 1760.0}...
 * @param p the string to parse, then the remaining string
 * @param names the vector of names found
 * @param values the vector of values found
 * @return true if a menu list was found
 */
inline bool parseMenuList(const char*& p, vector<string>& names, vector<double>& values)
{
    vector<string> tmpnames;
    vector<double> tmpvalues;

    const char* saved = p;

    if (parseChar(p, '{')) {
        do {
            string n;
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

/**
 * @brief parseMenuItem, parse a menu item ...'low':440.0...
 * @param p the string to parse, then the remaining string
 * @param name the name found
 * @param value the value found
 * @return true if a nemu item was found
 */
inline bool parseMenuItem(const char*& p, string& name, double& value)
{
    const char* saved = p;
    if (parseSQString(p, name) && parseChar(p, ':') && parseDouble(p, value)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

// ---------------------------------------------------------------------
//                          Elementary parsers
// ---------------------------------------------------------------------

// Report a parsing error
static bool parseError(const char*& p, const char* errmsg)
{
    std::cerr << "Parse error : " << errmsg << " here : " << p << std::endl;
    return true;
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
 * @brief skipBlank : advance pointer p to the first non blank character
 * @param p the string to parse, then the remaining string
 */
inline void skipBlank(const char*& p)
{
    while (isspace(*p)) { p++; }
}

/**
 * @brief parseChar : parse a specific character x
 * @param p the string to parse, then the remaining string
 * @param x the character to recognize
 * @return true if x was found at the begin of p
 */
inline bool parseChar(const char*& p, char x)
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
inline bool parseWord(const char*& p, const char* w)
{
    skipBlank(p);
    const char* saved = p;
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
inline bool parseDouble(const char*& p, double& x)
{
    double sign = +1.0;    // sign of the number
    double ipart = 0;      // integral part of the number
    double dpart = 0;      // decimal part of the number before division
    double dcoef = 1.0;    // division factor for the decimal part

    bool valid = false;   // true if the number contains at least one digit
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail

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
inline bool parseString(const char*& p, char quote, string& s)
{
    string str;
    skipBlank(p);
 
    const char* saved = p;
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
inline bool parseSQString(const char*& p, string& s)
{
    return parseString(p, '\'', s);
}

/**
 * @brief parseDQString, parse a double quoted string "..." and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
inline bool parseDQString(const char*& p, string& s)
{
    return parseString(p, '"', s);
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
//
static bool parseGlobalMetaData(const char*& p, std::string& key, std::string& value, std::map<std::string, std::string>& metadatas)
{
    if (parseDQString(p, key)) {
        if (key == "meta") {
            return parseMetaData(p, metadatas);
        } else {
            return parseChar(p, ':') && parseDQString(p, value);
        }
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse gui:
// "type" : "...", "label" : "...", "address" : "...", ...
// and store the result in uiItems Vector
//
static bool parseUI(const char*& p, std::vector<itemInfo*>& uiItems, int& numItems)
{
    if (parseChar(p, '{')) {
        
        std::string label;
        std::string value;
        
        do {
            if (parseDQString(p, label)) {
                if (label == "type") {
                    if (uiItems.size() != 0) {
                        numItems++;
                    }
                    if (parseChar(p, ':') && parseDQString(p, value)) {   
                        itemInfo* item = new itemInfo;
                        item->type = value;
                        uiItems.push_back(item);
                    }
                }
                
                else if (label == "label") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->label = value;
                    }
                }
                
                else if (label == "address") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->address = value;
                    }
                }
                
                else if (label == "index") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->index = value;
                    }
                }
                
                else if (label == "meta") {
                    itemInfo* item = uiItems[numItems];
                    if (!parseItemMetaData(p, item->meta)) {
                        return false;
                    }
                }
                
                else if (label == "init") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->init = value;
                    }
                }
                
                else if (label == "min") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->min = value;
                    }
                }
                
                else if (label == "max") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->max = value;
                    }
                }
                
                else if (label == "step"){
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->step = value;
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
                            itemInfo* item = new itemInfo;
                            item->type = "close";
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
//

inline bool parseJson(const char*& p, std::map<std::string, std::string>& metadatas, std::vector<itemInfo*>& uiItems)
{
    parseChar(p, '{');
    
    do {
        std::string key;
        std::string value;
        if (parseGlobalMetaData(p, key, value, metadatas)) {
            if (key != "meta") {
                // keep "name", "inputs", "outputs" key/value pairs
                metadatas[key] = value;
            }
        } else if (key == "ui") {
            int numItems = 0;
            parseChar(p, '[') && parseUI(p, uiItems, numItems);
        }
    } while (tryChar(p, ','));
    
    return parseChar(p, '}');
}

#endif // SIMPLEPARSER_H

#ifdef _WIN32
#include <windows.h>
#define snprintf _snprintf
#endif

inline FAUSTFLOAT STR2REAL(const std::string& s) { return (std::strtod(s.c_str(), NULL)); }

//-------------------------------------------------------------------
//  Decode a dsp JSON description and implement 'buildUserInterface'
//-------------------------------------------------------------------

typedef std::map<std::string, pair <int, FAUSTFLOAT*> > controlMap;

struct JSONUIDecoder {

    std::string fName;
    std::string fFileName;
    
    std::map<std::string, std::string> fMetadatas; 
    std::vector<itemInfo*> fUiItems;     
    
    FAUSTFLOAT* fInControl;
    FAUSTFLOAT* fOutControl;
    
    std::string fJSON;
    
    int fNumInputs, fNumOutputs; 
    int fInputItems, fOutputItems;
    
    std::string fVersion;
    std::string fOptions;
    
    int fDSPSize;
    
    controlMap fPathInputTable;     // [path, <index, zone>]
    controlMap fPathOutputTable;    // [path, <index, zone>]
    
    bool isInput(const string& type) { return (type == "vslider" || type == "hslider" || type == "nentry" || type == "button" || type == "checkbox"); }
    bool isOutput(const string& type) { return (type == "hbargraph" || type == "vbargraph"); }

    JSONUIDecoder(const std::string& json) 
    {
        fJSON = json;
        const char* p = fJSON.c_str();
        parseJson(p, fMetadatas, fUiItems);
        
        // fMetadatas will contain the "meta" section as well as <name : val>, <inputs : val>, <ouputs : val> pairs
        if (fMetadatas.find("name") != fMetadatas.end()) {
            fName = fMetadatas["name"];
            fMetadatas.erase("name");
        } else {
            fName = "";
        }
        
        if (fMetadatas.find("filename") != fMetadatas.end()) {
            fFileName = fMetadatas["filename"];
            fMetadatas.erase("filename");
        } else {
            fName = "";
        }
     
        if (fMetadatas.find("version") != fMetadatas.end()) {
            fVersion = fMetadatas["version"];
            fMetadatas.erase("version");
        } else {
            fVersion = "";
        }
        
        if (fMetadatas.find("options") != fMetadatas.end()) {
            fOptions = fMetadatas["options"];
            fMetadatas.erase("options");
        } else {
            fOptions = "";
        }
        
        if (fMetadatas.find("size") != fMetadatas.end()) {
            fDSPSize = std::atoi(fMetadatas["size"].c_str());
            fMetadatas.erase("size");
        } else {
            fDSPSize = -1;
        }
         
        if (fMetadatas.find("inputs") != fMetadatas.end()) {
            fNumInputs = std::atoi(fMetadatas["inputs"].c_str());
            fMetadatas.erase("inputs");
        } else {
            fNumInputs = -1;
        }
        
        if (fMetadatas.find("outputs") != fMetadatas.end()) {
            fNumOutputs = std::atoi(fMetadatas["outputs"].c_str());
            fMetadatas.erase("outputs");
        } else {
            fNumOutputs = -1;
        }
       
        fInputItems = 0;
        fOutputItems = 0;
        
        vector<itemInfo*>::iterator it;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            string type = (*it)->type;
            if (isInput(type)) {
                fInputItems++;
            } else if (isOutput(type)) {
                fOutputItems++;          
            }
        }
        
        fInControl = new FAUSTFLOAT[fInputItems];
        fOutControl = new FAUSTFLOAT[fOutputItems];
        
        int counterIn = 0;
        int counterOut = 0;
        
        // Prepare the fPathTable and init zone
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            string type = (*it)->type;
            // Meta data declaration for input items
            if (isInput(type)) {
                if ((*it)->address != "") {
                    fPathInputTable[(*it)->address] = make_pair(std::atoi((*it)->index.c_str()), &fInControl[counterIn]);
                }
                fInControl[counterIn] = STR2REAL((*it)->init);
                counterIn++;
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                if ((*it)->address != "") {
                    fPathOutputTable[(*it)->address] = make_pair(std::atoi((*it)->index.c_str()), &fOutControl[counterOut]);
                }
                fOutControl[counterOut] = FAUSTFLOAT(0);
                counterOut++;
            }
        }
    }
    
    virtual ~JSONUIDecoder() 
    {
        vector<itemInfo*>::iterator it;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            delete(*it);
        }
        delete [] fInControl;
        delete [] fOutControl;
    }
    
    void metadata(Meta* m)
    {
        std::map<std::string, std::string>::iterator it;
        for (it = fMetadatas.begin(); it != fMetadatas.end(); it++) {
            m->declare((*it).first.c_str(), (*it).second.c_str());
        }
    }
    
    void resetUserInterface()
    {
        vector<itemInfo*>::iterator it;
        int item = 0;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            if (isInput((*it)->type)) {
                fInControl[item++] = STR2REAL((*it)->init);
            }
        }
    }
   
    void buildUserInterface(UI* ui)
    {
        // To be sure the floats are correctly encoded
        char* tmp_local = setlocale(LC_ALL, NULL);
        setlocale(LC_ALL, "C");

        int counterIn = 0;
        int counterOut = 0;
        vector<itemInfo*>::iterator it;
        
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            
            bool isInItem = false;
            bool isOutItem = false;
            string type = (*it)->type;
            
            FAUSTFLOAT init = STR2REAL((*it)->init);
            FAUSTFLOAT min = STR2REAL((*it)->min);
            FAUSTFLOAT max = STR2REAL((*it)->max);
            FAUSTFLOAT step = STR2REAL((*it)->step);
            
            if (isInput(type)) {
                isInItem = true;
            } else if (isOutput(type)) {
                isOutItem = true;
            }
            
            // Meta data declaration for input items
            if (isInput(type)) {
                fInControl[counterIn] = init;
                for (size_t i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(&fInControl[counterIn], (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                fOutControl[counterOut] = init;
                for (size_t i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(&fOutControl[counterOut], (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(0, (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                ui->openHorizontalBox((*it)->label.c_str());
            } else if (type == "vgroup") { 
                ui->openVerticalBox((*it)->label.c_str());
            } else if (type == "tgroup") {
                ui->openTabBox((*it)->label.c_str());
            } else if (type == "vslider") {
                ui->addVerticalSlider((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);
            } else if (type == "hslider") {
                ui->addHorizontalSlider((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);            
            } else if (type == "checkbox") {
                ui->addCheckButton((*it)->label.c_str(), &fInControl[counterIn]);
            } else if (type == "hbargraph") {
                ui->addHorizontalBargraph((*it)->label.c_str(), &fOutControl[counterOut], min, max);
            } else if (type == "vbargraph") {
                ui->addVerticalBargraph((*it)->label.c_str(), &fOutControl[counterOut], min, max);
            } else if (type == "nentry") {
                ui->addNumEntry((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);
            } else if (type == "button") {
                ui->addButton((*it)->label.c_str(), &fInControl[counterIn]);
            } else if (type == "close") {
                ui->closeBox();
            }
                
            if (isInItem) {
                counterIn++;
            }
                
            if (isOutItem) {
                counterOut++;
            }
        }
        
        setlocale(LC_ALL, tmp_local);
    }
    
};


#endif

//----------------------------------------------------------------
//  Proxy dsp definition created from the DSP JSON description
//  This class allows a 'proxy' dsp to control a real dsp 
//  possibly running somewhere else.
//----------------------------------------------------------------

class proxy_dsp : public dsp {

    private:
    
        int fSamplingFreq;
        JSONUIDecoder* fDecoder;
        
    public:
    
        proxy_dsp(const string& json)
        {
            fDecoder = new JSONUIDecoder(json);
            fSamplingFreq = -1;
        }
          
        proxy_dsp(dsp* dsp)
        {
            JSONUI builder(dsp->getNumInputs(), dsp->getNumOutputs());
            dsp->metadata(&builder);
            dsp->buildUserInterface(&builder);
            fSamplingFreq = dsp->getSampleRate();
            fDecoder = new JSONUIDecoder(builder.JSON());
        }
      
        virtual ~proxy_dsp()
        {
            delete fDecoder;
        }
       
        virtual int getNumInputs() 	{ return fDecoder->fNumInputs; }
        virtual int getNumOutputs() { return fDecoder->fNumOutputs; }
        
        virtual void buildUserInterface(UI* ui) { fDecoder->buildUserInterface(ui); }
        
        // To possibly implement in a concrete proxy dsp 
        virtual void init(int samplingFreq)
        {
            instanceInit(samplingFreq);
        }
        virtual void instanceInit(int samplingFreq)
        {
            instanceConstants(samplingFreq);
            instanceResetUserInterface();
            instanceClear();
        }
        virtual void instanceConstants(int samplingRate) { fSamplingFreq = samplingRate; }
        virtual void instanceResetUserInterface() { fDecoder->resetUserInterface(); }
        virtual void instanceClear() {}
    
        virtual int getSampleRate() { return fSamplingFreq; }
    
        virtual proxy_dsp* clone() { return new proxy_dsp(fDecoder->fJSON); }
        virtual void metadata(Meta* m) { fDecoder->metadata(m); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {}
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {} 
        
};

#endif

#define kActiveVoice      0
#define kFreeVoice        -1
#define kReleaseVoice     -2
#define kNoVoice          -3

#define VOICE_STOP_LEVEL  0.001
#define MIX_BUFFER_SIZE   16384

#define FLOAT_MAX(a, b) (((a) < (b)) ? (b) : (a))

// endsWith(<str>,<end>) : returns true if <str> ends with <end>

static inline bool endsWith(std::string const& str, std::string const& end)
{
    size_t l1 = str.length();
    size_t l2 = end.length();
    return (l1 >= l2) && (0 == str.compare(l1 - l2, l2, end));
}

static inline double midiToFreq(double note)
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
            if (!endsWith(label, "/gate")
                && !endsWith(label, "/freq")
                && !endsWith(label, "/gain")) {

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
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
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

    int fNote;              // Playing note actual pitch
    int fDate;              // KeyOn date
    bool fTrigger;          // True if stolen note and need for envelop trigger
    FAUSTFLOAT fLevel;      // Last audio block level
    std::string fGatePath;  // Path of 'gate' control
    std::string fGainPath;  // Path of 'gain' control
    std::string fFreqPath;  // Path of 'freq' control
    FAUSTFLOAT** fInputsSlice;
    FAUSTFLOAT** fOutputsSlice;
 
    dsp_voice(dsp* dsp):decorator_dsp(dsp)
    {
        dsp->buildUserInterface(this);
        fNote = kFreeVoice;
        fLevel = FAUSTFLOAT(0);
        fDate = 0;
        fTrigger = false;
        extractPaths(fGatePath, fFreqPath, fGainPath);
        fInputsSlice = new FAUSTFLOAT*[dsp->getNumInputs()];
        fOutputsSlice = new FAUSTFLOAT*[dsp->getNumOutputs()];
    }
    virtual ~dsp_voice()
    {
        delete [] fInputsSlice;
        delete [] fOutputsSlice;
    }

    void extractPaths(std::string& gate, std::string& freq, std::string& gain)
    {
        // Keep gain, freq and gate labels
        std::map<std::string, FAUSTFLOAT*>::iterator it;
        for (it = getMap().begin(); it != getMap().end(); it++) {
            std::string path = (*it).first;
            if (endsWith(path, "/gate")) {
                gate = path;
            } else if (endsWith(path, "/freq")) {
                freq = path;
            } else if (endsWith(path, "/gain")) {
                gain = path;
            }
        }
    }

    // MIDI velocity [0..127]
    void keyOn(int pitch, int velocity)
    {
        setParamValue(fFreqPath, midiToFreq(pitch));
        setParamValue(fGainPath, float(velocity)/127.f);
        fNote = pitch;
    }

    // Normalized MIDI velocity [0..1]
    void keyOn(int pitch, float velocity)
    {
        setParamValue(fFreqPath, midiToFreq(pitch));
        setParamValue(fGainPath, velocity);
        fNote = pitch;
    }

    void keyOff(bool hard = false)
    {
        // No use of velocity for now...
        setParamValue(fGatePath, FAUSTFLOAT(0));
        
        if (hard) {
            // Stop immediately
            fNote = kFreeVoice;
            fTrigger = false;
        } else {
            // Release voice
            fNote = kReleaseVoice;
        }
    }

    void play(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        if (fTrigger) {
            // New note, so trigger it
            trigger(count, inputs, outputs);
        } else {
            // Compute the voice
            compute(count, inputs, outputs);
        }
    }

    void trigger(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        setParamValue(fGatePath, FAUSTFLOAT(0));
        computeSlice(0, 1, inputs, outputs);
        setParamValue(fGatePath, FAUSTFLOAT(1));
        computeSlice(1, count - 1, inputs, outputs);
        fTrigger = false;
    }

    void computeSlice(int offset, int slice, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        if (slice > 0) {
            for (int chan = 0; chan < getNumInputs(); chan++) {
                fInputsSlice[chan] = &(inputs[chan][offset]);
            }
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                fOutputsSlice[chan] = &(outputs[chan][offset]);
            }
            compute(slice, fInputsSlice, fOutputsSlice);
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
                    snprintf(buffer, 32, ((fVoiceTable.size() < 8) ? "Voice%ld" : "V%ld"), i+1);
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
 * Base class for Polyphonic DSP.
 */
class dsp_poly : public decorator_dsp, public midi {

    public:
    
        dsp_poly(dsp* dsp):decorator_dsp(dsp)
        {}
    
        virtual ~dsp_poly() {}
};

/**
 * Polyphonic DSP : group a set of DSP to be played together or triggered by MIDI.
 */

class mydsp_poly : public dsp_voice_group, public dsp_poly {

    private:

        FAUSTFLOAT** fMixBuffer;
        int fDate;

        inline FAUSTFLOAT mixVoice(int count, FAUSTFLOAT** outputBuffer, FAUSTFLOAT** mixBuffer)
        {
            FAUSTFLOAT level = 0;
            for (int i = 0; i < getNumOutputs(); i++) {
                FAUSTFLOAT* mixChannel = mixBuffer[i];
                FAUSTFLOAT* outChannel = outputBuffer[i];
                for (int j = 0; j < count; j++) {
                    level = FLOAT_MAX(level, (FAUSTFLOAT)fabs(outChannel[j]));
                    mixChannel[j] += outChannel[j];
                }
            }
            return level;
        }

        inline void clearOutput(int count, FAUSTFLOAT** mixBuffer)
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                memset(mixBuffer[i], 0, count * sizeof(FAUSTFLOAT));
            }
        }
    
        inline int getPlayingVoice(int pitch)
        {
            int voice_playing = kNoVoice;
            int oldest_date_playing = INT_MAX;
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == pitch) {
                    // Keeps oldest playing voice
                    if (fVoiceTable[i]->fDate < oldest_date_playing) {
                        oldest_date_playing = fVoiceTable[i]->fDate;
                        voice_playing = i;
                    }
                }
            }
            
            return voice_playing;
        }
    
        // Always returns a voice
        inline int getFreeVoice()
        {
            int voice = kNoVoice;
            
            // Looks for the first available voice
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == kFreeVoice) {
                    voice = i;
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
                            voice_release = i;
                        }
                    } else {
                        // Otherwise keeps oldest playing voice
                        if (fVoiceTable[i]->fDate < oldest_date_playing) {
                            oldest_date_playing = fVoiceTable[i]->fDate;
                            voice_playing = i;
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
            fVoiceTable[voice]->fDate = fDate++;
            fVoiceTable[voice]->fTrigger = true;    // So that envelop is always re-initialized
            fVoiceTable[voice]->fNote = kActiveVoice;
            return voice;
        }

        static void panic(FAUSTFLOAT val, void* arg)
        {
            if (val == FAUSTFLOAT(1)) {
                static_cast<mydsp_poly*>(arg)->allNotesOff(true);
            }
        }

        inline bool checkPolyphony()
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
         * @param nvoices - number of polyphony voices
         * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
         *                If false all voices are always running.
         * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
         *                a given control on all voices, assuming GUI::updateAllGuis() is called.
         *                If false, all voices can be individually controlled.
         *
         */
        mydsp_poly(dsp* dsp,
                   int nvoices,
                   bool control = false,
                   bool group = true)
        : dsp_voice_group(panic, this, control, group), dsp_poly(dsp)
        {
            fDate = 0;

            // Create voices
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

        void init(int samplingRate)
        {
            decorator_dsp::init(samplingRate);
            fVoiceGroup->init(samplingRate);
            fPanic = FAUSTFLOAT(0);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->init(samplingRate);
            }
        }
    
        void instanceInit(int samplingFreq)
        {
            instanceConstants(samplingFreq);
            instanceResetUserInterface();
            instanceClear();
        }

        void instanceConstants(int samplingRate)
        {
            decorator_dsp::instanceConstants(samplingRate);
            fVoiceGroup->instanceConstants(samplingRate);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceConstants(samplingRate);
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
            assert(count < MIX_BUFFER_SIZE);

            // First clear the outputs
            clearOutput(count, outputs);

            if (fVoiceControl) {
                // Mix all playing voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    dsp_voice* voice = fVoiceTable[i];
                    if (voice->fNote != kFreeVoice) {
                        voice->play(count, inputs, fMixBuffer);
                        // Mix it in result
                        voice->fLevel = mixVoice(count, fMixBuffer, outputs);
                        // Check the level to possibly set the voice in kFreeVoice again
                        if ((voice->fLevel < VOICE_STOP_LEVEL) && (voice->fNote == kReleaseVoice)) {
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

        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            if (checkPolyphony()) {
                int voice = getFreeVoice();
                fVoiceTable[voice]->keyOn(pitch, velocity);
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

        // Terminate all active voices, gently or immediately (depending of 'hard' value)
        void allNotesOff(bool hard = false)
        {
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->keyOff(hard);
            }
        }

};

#endif // __poly_dsp__

std::list<GUI*> GUI::fGuiList;
ztimedmap GUI::gTimedZoneMap;

static const char* getCodeSize()
{
    int tmp;
    return (sizeof(&tmp) == 8) ? "64 bits" : "32 bits";
}

class mspUI;

struct Max_Meta1 : Meta
{
    int fCount;
    
    Max_Meta1():fCount(0)
    {}
     
    void declare(const char* key, const char* value)
    {
        if ((strcmp("name", key) == 0) || (strcmp("author", key) == 0)) {
            fCount++;
        }
    }
};

struct Max_Meta2 : Meta
{
    void declare(const char* key, const char* value)
    {
        if ((strcmp("name", key) == 0) || (strcmp("author", key) == 0)) {
            post("%s : %s", key, value);
        }
    }
};

struct Max_Meta3 : Meta
{
    string fName;
    void declare(const char* key, const char* value)
    {
        if ((strcmp("filename", key) == 0)) {
            fName = "com.grame." + string(value) + "~";
        }
    }
};

/*--------------------------------------------------------------------------*/
typedef struct faust
{
    t_pxobject m_ob;
    t_atom *m_seen, *m_want;
    map<string, vector <t_object*> > m_output_table;
    short m_where;
    bool m_mute;
    void** m_args;
    mspUI* m_dspUI;
    dsp* m_dsp;
    char* m_json;
    t_systhread_mutex m_mutex;    
    int m_Inputs;
    int m_Outputs;
#ifdef MIDICTRL
    MidiUI* m_midiUI;
    midi_handler* m_midiHandler;
#endif
#ifdef SOUNDFILE
    SoundUI* m_soundInterface;
#endif
} t_faust;

void* faust_class;

void faust_create_jsui(t_faust* x);
void faust_make_json(t_faust* x);

/*--------------------------------------------------------------------------*/
class mspUIObject {

	protected:

		string fLabel;
		FAUSTFLOAT* fZone;

		FAUSTFLOAT range(FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT val) {return (val < min) ? min : (val > max) ? max : val;}

	public:

		mspUIObject(const string& label, FAUSTFLOAT* zone):fLabel(label),fZone(zone) {}
		virtual ~mspUIObject() {}

		virtual void setValue(FAUSTFLOAT f) {*fZone = range(0.0,1.0,f);}
        virtual FAUSTFLOAT getValue() { return *fZone; }
		virtual void toString(char* buffer) {}
		virtual string getName() {return fLabel;}
};

/*--------------------------------------------------------------------------*/
class mspCheckButton : public mspUIObject {

	public:

		mspCheckButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
		virtual ~mspCheckButton() {}

		void toString(char* buffer)
		{
            snprintf(buffer, STR_SIZE, "CheckButton(double): %s", fLabel.c_str());
		}
};

/*--------------------------------------------------------------------------*/
class mspButton : public mspUIObject {

	public:

		mspButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
		virtual ~mspButton() {}

		void toString(char* buffer)
		{
            snprintf(buffer, STR_SIZE, "Button(double): %s", fLabel.c_str());
		}
};

/*--------------------------------------------------------------------------*/
class mspSlider : public mspUIObject {

	private:

		FAUSTFLOAT fInit;
		FAUSTFLOAT fMin;
		FAUSTFLOAT fMax;
		FAUSTFLOAT fStep;

	public:

		mspSlider(const string& label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
			:mspUIObject(label,zone),fInit(init),fMin(min),fMax(max),fStep(step) {}
		virtual ~mspSlider() {}

        void toString(char* buffer)
        {
            stringstream str;
            str << "Slider(float): " << fLabel << " [init=" << fInit << ":min=" << fMin << ":max=" << fMax << ":step=" << fStep << ":cur=" << *fZone << "]";
            string res = str.str();
            snprintf(buffer, STR_SIZE, "%s", res.c_str());
        }

		void setValue(FAUSTFLOAT f) {*fZone = range(fMin,fMax,f);}
};

/*--------------------------------------------------------------------------*/
class mspBargraph : public mspUIObject {
    
    private:
        
        FAUSTFLOAT fMin;
        FAUSTFLOAT fMax;
        FAUSTFLOAT fCurrent;
        
    public:
        
        mspBargraph(const string& label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        :mspUIObject(label,zone),fMin(min),fMax(max),fCurrent(*zone) {}
        virtual ~mspBargraph() {}
        
        void toString(char* buffer)
        {
            stringstream str;
            str << "Bargraph(float): " << fLabel << " [min=" << fMin << ":max=" << fMax << ":cur=" << *fZone << "]";
            string res = str.str();
            snprintf(buffer, STR_SIZE, "%s", res.c_str());
        }
    
        virtual FAUSTFLOAT getValue() 
        { 
            if (*fZone != fCurrent) {
                fCurrent = *fZone;
                return fCurrent;
            } else {
                return NAN; 
            }
        }
};

/*--------------------------------------------------------------------------*/

#define MULTI_SIZE  256

class mspUI : public UI
{
	private:

        map<string, mspUIObject*> fUITable1;       // Table using labels
        map<string, mspUIObject*> fUITable2;       // Table using complete path
        map<string, mspUIObject*> fUITable3;       // Table containing bargraph
       
        map<const char*, const char*> fDeclareTable;
        std::vector<std::string> fControlsLevel;
        
        FAUSTFLOAT* fMultiTable[MULTI_SIZE];
        int fMultiIndex;
        int fMultiControl;
        
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
        string createLabel(const char* label)
        {
            map<const char*, const char*>::reverse_iterator it;
            if (fDeclareTable.size() > 0) {
                unsigned int i = 0;
                string res = string(label);
                char sep = '[';
                for (it = fDeclareTable.rbegin(); it != fDeclareTable.rend(); it++, i++) {
                    res = res + sep + (*it).first + ":" + (*it).second;
                    sep = ',';
                }
                res += ']';
                fDeclareTable.clear();
                return res;
            } else {
                return string(label);
            }
        }

	public:
    
		typedef map<string, mspUIObject*>::iterator iterator;

		mspUI() 
        {
     		for (int i = 0; i < MULTI_SIZE; i++) {
                fMultiTable[i] = 0;
            }
            fMultiIndex = fMultiControl = 0;
        }
		virtual ~mspUI()
		{
            clear();
   		}
      
		void addButton(const char* label, FAUSTFLOAT* zone) 
        {
            mspUIObject* obj = new mspButton(createLabel(label), zone);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj;
        }
        
        void addCheckButton(const char* label, FAUSTFLOAT* zone) 
        {
            mspUIObject* obj = new mspCheckButton(createLabel(label), zone);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj; 
        }
        
        void addSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            mspUIObject* obj = new mspSlider(createLabel(label), zone, init, min, max, step);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj; 
        }
        
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }
        
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }
        
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            mspUIObject* obj = new mspSlider(createLabel(label), zone, init, min, max, step);
            fUITable1[string(label)] = obj;
            fUITable2[buildPath(label)] = obj;
        }
        
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {   
            fUITable3[buildPath(label)] = new mspBargraph(createLabel(label), zone, min, max);
            fDeclareTable.clear();
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            fUITable3[buildPath(label)] = new mspBargraph(createLabel(label), zone, min, max);
            fDeclareTable.clear();
        }
    
        void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
    
        void openTabBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void openHorizontalBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void openVerticalBox(const char* label) {fControlsLevel.push_back(label); fDeclareTable.clear();}
        void closeBox() {fControlsLevel.pop_back(); fDeclareTable.clear();}

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            if (strcmp(key,"multi") == 0) {
                int index = atoi(val);
                if (index >= 0 && index < MULTI_SIZE) {
                    fMultiTable[index] = zone;
                    fMultiControl++;
                } else {
                    post("Invalid multi index = %d", index);
                }
            }
            
            fDeclareTable[key] = val;
        }
        
        void setMultiValues(FAUSTFLOAT* multi, int buffer_size)
		{
            for (int read = 0; read < buffer_size; read++) {
                int write = (fMultiIndex + read) & (MULTI_SIZE - 1);
                if (fMultiTable[write]) {
                    *fMultiTable[write] = multi[read];
                }
            }
            fMultiIndex += buffer_size;
		}
        
        bool isMulti() { return fMultiControl > 0; }
    
        bool isValue(string name) 
        {
            return (fUITable1.count(name) || fUITable2.count(name));
        }
        bool isOutputValue(string name) 
        {
            return fUITable3.count(name);
        }
        bool isInputValue(string name) 
        {
            return fUITable2.count(name);
        }
        bool setValue(string name, FAUSTFLOAT f)
        {
            if (fUITable1.count(name)) {
                fUITable1[name]->setValue(f);
                return true;
            } else if (fUITable2.count(name)) {
                fUITable2[name]->setValue(f);
                return true;
            } else {
                return false;
            }
        }
		FAUSTFLOAT getOutputValue(string name) { return fUITable3[name]->getValue(); }
          
        iterator begin1()	{ return fUITable1.begin(); }
        iterator end1()		{ return fUITable1.end(); }
        
        iterator begin2()	{ return fUITable2.begin(); }
        iterator end2()		{ return fUITable2.end(); }

        int itemsCount() { return fUITable1.size(); }
        void clear() 
        { 
            iterator it;
            for (it = begin1(); it != end1(); it++) {
                delete (*it).second;
            }
            fUITable1.clear(); 
            fUITable2.clear(); 
        }
    
        void displayControls()
        {
            iterator it;
            post((char*)"------- labels and ranges ----------");
            for (it = fUITable1.begin(); it != fUITable1.end(); it++) {
                char param[STR_SIZE];
                it->second->toString(param);
                post(param);
            }
            post((char*)"------- complete paths ----------");
            for (it = fUITable2.begin(); it != fUITable2.end(); it++) {
                post(it->first.c_str());
            }
            post((char*)"---------------------------------");
        }
    
};

//--------------------------------------------------------------------------
static bool check_digit(const string& name)
{
    for (int i = name.size() - 1; i >= 0; i--) {
        if (isdigit(name[i])) { return true; }
    }
    return false;
}

static int count_digit(const string& name)
{
    int count = 0;
    for (int i = name.size() - 1; i >= 0; i--) {
        if (isdigit(name[i])) { count++; }
    }
    return count;
}

/*--------------------------------------------------------------------------*/
void faust_anything(t_faust* obj, t_symbol* s, short ac, t_atom* av)
{
    if (ac < 0) return;
    
    bool res = false;
    string name = string((s)->s_name);
    
    // Check if no argument is there, consider it is a toggle message for a button
    if (ac == 0 && obj->m_dspUI->isValue(name)) {
        
        float off = 0.0f;
        float on = 1.0f;
        obj->m_dspUI->setValue(name, off);
        obj->m_dspUI->setValue(name, on);
        
        av[0].a_type = A_FLOAT;
        av[0].a_w.w_float = off;
        faust_anything(obj, s, 1, av);
        
        return;
    }
    
    // List of values
    if (check_digit(name)) {
        
        int ndigit = 0;
        int pos;
        
        for (pos = name.size() - 1; pos >= 0; pos--) {
            if (isdigit(name[pos]) || name[pos] == ' ') {
                ndigit++;
            } else {
                break;
            }
        }
        pos++;
        
        string prefix = name.substr(0, pos);
        string num_base = name.substr(pos);
        int num = atoi(num_base.c_str());
        
        int i;
        t_atom* ap;
       
        // Increment ap each time to get to the next atom
        for (i = 0, ap = av; i < ac; i++, ap++) {
            float value;
            switch (atom_gettype(ap)) {
                case A_LONG: 
                    value = (float)ap[0].a_w.w_long;
                    break;
                
                case A_FLOAT:
                    value = ap[0].a_w.w_float;
                    break;
                    
                default:
                    post("Invalid argument in parameter setting"); 
                    return;         
            }
            
            stringstream num_val;
            num_val << num + i;
            string str = num_val.str();
            char param_name[256];
            
            switch (ndigit - count_digit(str)) {
                case 0:
                    sprintf(param_name, "%s%s", prefix.c_str(), str.c_str());
                    break;
                case 1:
                    sprintf(param_name, "%s %s", prefix.c_str(), str.c_str());
                    break;
                case 2:
                    sprintf(param_name, "%s  %s", prefix.c_str(), str.c_str());
                    break;
            }
            
            // Try special naming scheme for list of parameters
            res = obj->m_dspUI->setValue(param_name, value); 
            
            // Otherwise try standard name
            if (!res) {
                res = obj->m_dspUI->setValue(name, value);
            }
            
            if (!res) {
                post("Unknown parameter : %s", (s)->s_name);
            }
        }
    } else {
        // Standard parameter name
        float value = (av[0].a_type == A_LONG) ? (float)av[0].a_w.w_long : av[0].a_w.w_float;
        res = obj->m_dspUI->setValue(name, value);
    }
    
    if (!res) {
        post("Unknown parameter : %s", (s)->s_name);
    }
}

/*--------------------------------------------------------------------------*/
void faust_polyphony(t_faust* obj, t_symbol* s, short ac, t_atom* av)
{
    if (systhread_mutex_lock(obj->m_mutex) == MAX_ERR_NONE) {
    #ifdef MIDICTRL
        mydsp_poly* poly = dynamic_cast<mydsp_poly*>(obj->m_dsp);
        if (poly) {
            obj->m_midiHandler->removeMidiIn(poly);
        }
    #endif
        // Delete old
        delete obj->m_dsp;
        obj->m_dspUI->clear();
        mydsp_poly* dsp_poly = NULL;
        // Allocate new one
        if (av[0].a_w.w_long > 0) {
            post("polyphonic DSP voices = %d", av[0].a_w.w_long);
            dsp_poly = new mydsp_poly(new mydsp(), av[0].a_w.w_long, true, true);
        #ifdef POLY2
            obj->m_dsp = new dsp_sequencer(dsp_poly, new effect());
        #else
            obj->m_dsp = dsp_poly;
        #endif
        } else {
            obj->m_dsp = new mydsp();
            post("monophonic DSP");
        }
        // Initialize User Interface (here connnection with controls)
        obj->m_dsp->buildUserInterface(obj->m_dspUI);
    #ifdef MIDICTRL
        obj->m_midiHandler->addMidiIn(dsp_poly);
        obj->m_dsp->buildUserInterface(obj->m_midiUI);
    #endif
        // Initialize at the system's sampling rate
        obj->m_dsp->init(long(sys_getsr()));
        
        // Prepare JSON
        faust_make_json(obj);
        
        // Send JSON to JS script
        faust_create_jsui(obj);
        
        systhread_mutex_unlock(obj->m_mutex);
    } else {
        post("Mutex lock cannot be taken...");
    }
}

/*--------------------------------------------------------------------------*/
#ifdef MIDICTRL
void faust_midievent(t_faust* obj, t_symbol* s, short ac, t_atom* av) 
{
    if (ac > 0) {
        int type = (int)av[0].a_w.w_long & 0xf0;
        int channel = (int)av[0].a_w.w_long & 0x0f;
                
        if (ac == 1) {
            obj->m_midiHandler->handleSync(0.0, av[0].a_w.w_long);
        } else if (ac == 2) {
            obj->m_midiHandler->handleData1(0.0, type, channel, av[1].a_w.w_long);
        } else if (ac == 3) {
            obj->m_midiHandler->handleData2(0.0, type, channel, av[1].a_w.w_long, av[2].a_w.w_long);
        }
    }
}
#endif

/*--------------------------------------------------------------------------*/
void faust_create_jsui(t_faust* x)
{
    t_object *patcher, *box, *obj;
    object_obex_lookup((t_object*)x, gensym("#P"), &patcher);
    
    for (box = jpatcher_get_firstobject(patcher); box; box = jbox_get_nextobject(box)) {
        obj = jbox_get_object(box);
        // Notify JSON
        if (obj && strcmp(object_classname(obj)->s_name, "js") == 0) {
            t_atom json;
            atom_setsym(&json, gensym(x->m_json));
            object_method_typed(obj, gensym("anything"), 1, &json, 0);
        }
    }
        
    // Keep all outputs
    x->m_output_table.clear();
    for (box = jpatcher_get_firstobject(patcher); box; box = jbox_get_nextobject(box)) {
        obj = jbox_get_object(box);
        t_symbol* scriptingname = jbox_get_varname(obj); // scripting name
        // Keep control outputs
        if (scriptingname && x->m_dspUI->isOutputValue(scriptingname->s_name)) {
            x->m_output_table[scriptingname->s_name].push_back(obj);
        }
    }
}

void faust_update_outputs(t_faust* x)
{
    map<string, vector<t_object*> >::iterator it1;
    vector<t_object*>::iterator it2;
    for (it1 = x->m_output_table.begin(); it1 != x->m_output_table.end(); it1++) {
        FAUSTFLOAT value = x->m_dspUI->getOutputValue((*it1).first);
        if (value != NAN) {
            t_atom at_value;
            atom_setfloat(&at_value, value);
            for (it2 = (*it1).second.begin(); it2 != (*it1).second.end(); it2++) {
                object_method_typed((*it2), gensym("float"), 1, &at_value, 0);
            }
        }
    }
}

/*--------------------------------------------------------------------------*/
void faust_make_json(t_faust* x)
{
    // Prepare JSON
    if (x->m_json) free(x->m_json);
    JSONUI builder(x->m_dsp->getNumInputs(), x->m_dsp->getNumOutputs());
    x->m_dsp->metadata(&builder);
    x->m_dsp->buildUserInterface(&builder);
    x->m_json = strdup(builder.JSON().c_str());
}

/*--------------------------------------------------------------------------*/
void* faust_new(t_symbol* s, short ac, t_atom* av)
{
    bool midi_sync = false;
    int nvoices = 0;
    mydsp_poly* dsp_poly = NULL;
    
    mydsp* tmp_dsp = new mydsp();
    MidiMeta::analyse(tmp_dsp, midi_sync, nvoices);
    delete tmp_dsp;
    
    t_faust* x = (t_faust*)newobject(faust_class);

    x->m_json = 0;
    x->m_mute = false;
    
#ifdef MIDICTRL
    x->m_midiHandler = new midi_handler();
    x->m_midiUI = new MidiUI(x->m_midiHandler);
#endif
    
    if (nvoices > 0) {
        post("polyphonic DSP voices = %d", nvoices);
        dsp_poly = new mydsp_poly(new mydsp(), nvoices, true, true);
    #ifdef POLY2
        x->m_dsp = new dsp_sequencer(dsp_poly, new effect());
    #else
        x->m_dsp = dsp_poly;
    #endif
        
    #ifdef MIDICTRL
        x->m_midiHandler->addMidiIn(dsp_poly);
        x->m_dsp->buildUserInterface(x->m_midiUI);
    #endif
    } else {
        post("monophonic DSP");
        x->m_dsp = new mydsp();
    }
    
    x->m_Inputs = x->m_dsp->getNumInputs();
    x->m_Outputs = x->m_dsp->getNumOutputs();
   
    x->m_dspUI = new mspUI();

    x->m_dsp->init(long(sys_getsr()));
    x->m_dsp->buildUserInterface(x->m_dspUI);
    
    t_max_err err = systhread_mutex_new(&x->m_mutex, SYSTHREAD_MUTEX_NORMAL);
    if (err != MAX_ERR_NONE) {
        post("Cannot allocate mutex...");
    }
    
    // Prepare JSON
    faust_make_json(x);
    
    int num_input;
    
    if (x->m_dspUI->isMulti()) {
        num_input = x->m_dsp->getNumInputs() + 1;
    } else {
        num_input = x->m_dsp->getNumInputs();
    }
    
    x->m_args = (void**)calloc((num_input + x->m_dsp->getNumOutputs()) + 2, sizeof(void*));
    /* Multi in */
    dsp_setup((t_pxobject*)x, num_input);

    /* Multi out */
    for (int i = 0; i< x->m_dsp->getNumOutputs(); i++) {
        outlet_new((t_pxobject*)x, (char*)"signal");
    }

    ((t_pxobject*)x)->z_misc = Z_NO_INPLACE; // To assure input and output buffers are actually different

#ifdef SOUNDFILE
    Max_Meta3 meta3;
    x->m_dsp->metadata(&meta3);
    string bundle_path_str = SoundUI::getBinaryPathFrom(meta3.fName);
    if (bundle_path_str == "") {
        post("Bundle_path cannot be found!");
    }
    x->m_soundInterface = new SoundUI(bundle_path_str);
    x->m_dsp->buildUserInterface(x->m_soundInterface);
#endif
    
    // Send JSON to JS script
    faust_create_jsui(x);
    return x;
}

/*--------------------------------------------------------------------------*/
void faust_dblclick(t_faust* x, long inlet)
{
    x->m_dspUI->displayControls();
}

/*--------------------------------------------------------------------------*/
//11/13/2015 : faust_assist is actually called at each click in the patcher, so we now use 'faust_dblclick' to display the parameters...
void faust_assist(t_faust* x, void* b, long msg, long a, char* dst)
{
    if (msg == ASSIST_INLET) {
        if (a == 0) {
            if (x->m_dsp->getNumInputs() == 0) {
                sprintf(dst, "(signal) : Unused Input");
            } else {
                sprintf(dst, "(signal) : Audio Input %ld", (a+1));
			}
        } else if (a < x->m_dsp->getNumInputs()) {
            sprintf(dst, "(signal) : Audio Input %ld", (a+1));
        }
    } else if (msg == ASSIST_OUTLET) {
        sprintf(dst, "(signal) : Audio Output %ld", (a+1));
    }
}

/*--------------------------------------------------------------------------*/
void faust_mute(t_faust* obj, t_symbol* s, short ac, t_atom* at)
{
    if (atom_gettype(at) == A_LONG) {
        obj->m_mute = atom_getlong(at);
    }
}

/*--------------------------------------------------------------------------*/
void faust_free(t_faust* x)
{
	dsp_free((t_pxobject*)x);
	delete x->m_dsp;
	delete x->m_dspUI;
	if (x->m_args) free(x->m_args);
    if (x->m_json) free(x->m_json);
    systhread_mutex_free(x->m_mutex);
#ifdef MIDICTRL
    // m_midiUI *must* be deleted before m_midiHandler
    delete x->m_midiUI;
    delete x->m_midiHandler;
#endif
#ifdef SOUNDFILE
    delete x->m_soundInterface;
#endif
}

/*--------------------------------------------------------------------------*/
void faust_perform64(t_faust* x, t_object* dsp64, double** ins, long numins, double** outs, long numouts, long sampleframes, long flags, void* userparam)
{
    AVOIDDENORMALS;
    if (!x->m_mute && systhread_mutex_trylock(x->m_mutex) == MAX_ERR_NONE) {
        if (x->m_dsp) {
            if (x->m_dspUI->isMulti()) {
                x->m_dspUI->setMultiValues(ins[0], sampleframes);
                x->m_dsp->compute(sampleframes, ++ins, outs);
            } else {
                x->m_dsp->compute(sampleframes, ins, outs);
            }
            faust_update_outputs(x);
        }
    #ifdef MIDICTRL
        GUI::updateAllGuis();
    #endif
        systhread_mutex_unlock(x->m_mutex);
    } else {
        // Write null buffers to outs
        for (int i = 0; i < numouts; i++) {
             memset(outs[i], 0, sizeof(double) * sampleframes);
        }
    }
}

/*--------------------------------------------------------------------------*/
void faust_dsp64(t_faust* x, t_object* dsp64, short* count, double samplerate, long maxvectorsize, long flags)
{
    object_method(dsp64, gensym("dsp_add64"), x, faust_perform64, 0, NULL);
}

/*--------------------------------------------------------------------------*/
extern "C" int main(void)
{
	setup((t_messlist**)&faust_class, (method)faust_new, (method)faust_free,
		(short)sizeof(t_faust), 0L, A_DEFFLOAT, 0);

    dsp* tmp_dsp = new mydsp();
    mspUI m_dspUI;
    tmp_dsp->buildUserInterface(&m_dspUI);

    // 03/11/14 : use 'anything' to handle all parameter changes
    addmess((method)faust_anything, (char*)"anything", A_GIMME, 0);
    addmess((method)faust_polyphony, (char*)"polyphony", A_GIMME, 0);
#ifdef MIDICTRL
    addmess((method)faust_midievent, (char*)"midievent", A_GIMME, 0);
#endif
    addmess((method)faust_dsp64, (char*)"dsp64", A_CANT, 0);
    addmess((method)faust_dblclick, (char*)"dblclick", A_CANT, 0);
    addmess((method)faust_assist, (char*)"assist", A_CANT, 0);
    addmess((method)faust_mute, (char*)"mute", A_GIMME, 0);
    dsp_initclass();

    post((char*)"Faust DSP object v%s (sample = 64 bits code = %s)", EXTERNAL_VERSION, getCodeSize());
    post((char*)"Copyright (c) 2012-2018 Grame");
    Max_Meta1 meta1;
    tmp_dsp->metadata(&meta1);
    if (meta1.fCount > 0) {
        Max_Meta2 meta2;
        post("------------------------------");
        tmp_dsp->metadata(&meta2);
        post("------------------------------");
    }
    
    delete(tmp_dsp);
    return 0;
}

/********************END ARCHITECTURE SECTION (part 2/2)****************/





#endif
