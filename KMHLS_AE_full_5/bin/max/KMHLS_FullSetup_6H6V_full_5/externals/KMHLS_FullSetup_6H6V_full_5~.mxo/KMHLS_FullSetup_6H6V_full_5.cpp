/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMHLS_FullSetup_6H6V_full_5"
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
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	double fConst8;
	double fConst9;
	double fConst10;
	double fConst11;
	FAUSTFLOAT fHslider1;
	double fRec20[2];
	double fRec19[3];
	FAUSTFLOAT fHslider2;
	double fRec21[2];
	double fRec22[3];
	double fRec23[3];
	double fRec24[3];
	double fRec25[3];
	double fRec26[3];
	double fRec27[3];
	double fRec28[3];
	double fRec29[3];
	double fRec30[3];
	double fRec31[3];
	double fRec32[3];
	double fRec33[3];
	double fConst12;
	double fConst13;
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
	double fRec3[2];
	double fRec1[2];
	double fConst14;
	double fConst15;
	double fConst16;
	double fConst17;
	double fConst18;
	double fConst19;
	double fConst20;
	double fRec49[3];
	double fRec50[3];
	double fRec51[3];
	double fRec52[3];
	double fRec53[3];
	double fRec54[3];
	double fRec55[3];
	double fRec56[3];
	double fRec57[3];
	double fRec58[3];
	double fRec59[3];
	double fConst21;
	double fConst22;
	double fRec48[2];
	double fRec46[2];
	double fRec45[2];
	double fRec43[2];
	double fRec42[2];
	double fRec40[2];
	double fRec39[2];
	double fRec37[2];
	double fRec36[2];
	double fRec34[2];
	double fConst23;
	double fConst24;
	double fConst25;
	double fRec72[3];
	double fRec73[3];
	double fRec74[3];
	double fRec75[3];
	double fRec76[3];
	double fRec77[3];
	double fRec78[3];
	double fRec79[3];
	double fRec80[3];
	double fConst26;
	double fConst27;
	double fRec71[2];
	double fRec69[2];
	double fRec68[2];
	double fRec66[2];
	double fConst28;
	double fConst29;
	double fRec65[2];
	double fRec63[2];
	double fRec62[2];
	double fRec60[2];
	double fConst30;
	double fConst31;
	double fConst32;
	double fConst33;
	double fRec90[3];
	double fRec91[3];
	double fRec92[3];
	double fRec93[3];
	double fRec94[3];
	double fRec95[3];
	double fRec96[3];
	double fConst34;
	double fConst35;
	double fRec89[2];
	double fRec87[2];
	double fRec86[2];
	double fRec84[2];
	double fRec83[2];
	double fRec81[2];
	double fConst36;
	double fConst37;
	double fRec100[3];
	double fRec101[3];
	double fRec102[3];
	double fConst38;
	double fRec99[2];
	double fRec97[2];
	double fConst39;
	double fConst40;
	double fRec109[3];
	double fRec110[3];
	double fRec111[3];
	double fRec112[3];
	double fRec113[3];
	double fConst41;
	double fConst42;
	double fRec108[2];
	double fRec106[2];
	double fRec105[2];
	double fRec103[2];
	double fRec114[3];
	int IOTA;
	double fVec0[128];
	int iConst43;
	double fConst44;
	double fConst45;
	double fConst46;
	double fConst47;
	double fConst48;
	double fConst49;
	double fConst50;
	double fConst51;
	double fConst52;
	double fConst53;
	double fRec132[2];
	double fRec130[2];
	double fRec129[2];
	double fRec127[2];
	double fRec126[2];
	double fRec124[2];
	double fRec123[2];
	double fRec121[2];
	double fRec120[2];
	double fRec118[2];
	double fRec117[2];
	double fRec115[2];
	double fConst54;
	double fConst55;
	double fConst56;
	double fConst57;
	double fConst58;
	double fConst59;
	double fConst60;
	double fConst61;
	double fConst62;
	double fRec147[2];
	double fRec145[2];
	double fRec144[2];
	double fRec142[2];
	double fRec141[2];
	double fRec139[2];
	double fRec138[2];
	double fRec136[2];
	double fRec135[2];
	double fRec133[2];
	double fConst63;
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fConst68;
	double fConst69;
	double fRec159[2];
	double fRec157[2];
	double fRec156[2];
	double fRec154[2];
	double fRec153[2];
	double fRec151[2];
	double fRec150[2];
	double fRec148[2];
	double fConst70;
	double fConst71;
	double fConst72;
	double fConst73;
	double fConst74;
	double fConst75;
	double fRec168[2];
	double fRec166[2];
	double fRec165[2];
	double fRec163[2];
	double fRec162[2];
	double fRec160[2];
	double fConst76;
	double fConst77;
	double fConst78;
	double fRec171[2];
	double fRec169[2];
	double fConst79;
	double fConst80;
	double fConst81;
	double fConst82;
	double fRec177[2];
	double fRec175[2];
	double fRec174[2];
	double fRec172[2];
	double fVec1[128];
	int iConst83;
	double fRec183[2];
	double fRec181[2];
	double fRec180[2];
	double fRec178[2];
	double fRec186[2];
	double fRec184[2];
	double fRec195[2];
	double fRec193[2];
	double fRec192[2];
	double fRec190[2];
	double fRec189[2];
	double fRec187[2];
	double fRec213[2];
	double fRec211[2];
	double fRec210[2];
	double fRec208[2];
	double fRec207[2];
	double fRec205[2];
	double fRec204[2];
	double fRec202[2];
	double fRec201[2];
	double fRec199[2];
	double fRec198[2];
	double fRec196[2];
	double fRec225[2];
	double fRec223[2];
	double fRec222[2];
	double fRec220[2];
	double fRec219[2];
	double fRec217[2];
	double fRec216[2];
	double fRec214[2];
	double fRec240[2];
	double fRec238[2];
	double fRec237[2];
	double fRec235[2];
	double fRec234[2];
	double fRec232[2];
	double fRec231[2];
	double fRec229[2];
	double fRec228[2];
	double fRec226[2];
	double fVec2[128];
	double fConst84;
	double fConst85;
	double fConst86;
	double fRec243[2];
	double fRec241[2];
	double fConst87;
	double fConst88;
	double fConst89;
	double fConst90;
	double fConst91;
	double fConst92;
	double fConst93;
	double fConst94;
	double fConst95;
	double fConst96;
	double fRec261[2];
	double fRec259[2];
	double fRec258[2];
	double fRec256[2];
	double fRec255[2];
	double fRec253[2];
	double fRec252[2];
	double fRec250[2];
	double fRec249[2];
	double fRec247[2];
	double fRec246[2];
	double fRec244[2];
	double fConst97;
	double fConst98;
	double fConst99;
	double fConst100;
	double fConst101;
	double fConst102;
	double fConst103;
	double fConst104;
	double fConst105;
	double fRec276[2];
	double fRec274[2];
	double fRec273[2];
	double fRec271[2];
	double fRec270[2];
	double fRec268[2];
	double fRec267[2];
	double fRec265[2];
	double fRec264[2];
	double fRec262[2];
	double fConst106;
	double fConst107;
	double fConst108;
	double fConst109;
	double fConst110;
	double fConst111;
	double fConst112;
	double fRec288[2];
	double fRec286[2];
	double fRec285[2];
	double fRec283[2];
	double fRec282[2];
	double fRec280[2];
	double fRec279[2];
	double fRec277[2];
	double fConst113;
	double fConst114;
	double fConst115;
	double fConst116;
	double fRec294[2];
	double fRec292[2];
	double fRec291[2];
	double fRec289[2];
	double fConst117;
	double fConst118;
	double fConst119;
	double fConst120;
	double fConst121;
	double fConst122;
	double fRec303[2];
	double fRec301[2];
	double fRec300[2];
	double fRec298[2];
	double fRec297[2];
	double fRec295[2];
	double fVec3[128];
	int iConst123;
	double fRec321[2];
	double fRec319[2];
	double fRec318[2];
	double fRec316[2];
	double fRec315[2];
	double fRec313[2];
	double fRec312[2];
	double fRec310[2];
	double fRec309[2];
	double fRec307[2];
	double fRec306[2];
	double fRec304[2];
	double fRec336[2];
	double fRec334[2];
	double fRec333[2];
	double fRec331[2];
	double fRec330[2];
	double fRec328[2];
	double fRec327[2];
	double fRec325[2];
	double fRec324[2];
	double fRec322[2];
	double fRec348[2];
	double fRec346[2];
	double fRec345[2];
	double fRec343[2];
	double fRec342[2];
	double fRec340[2];
	double fRec339[2];
	double fRec337[2];
	double fRec357[2];
	double fRec355[2];
	double fRec354[2];
	double fRec352[2];
	double fRec351[2];
	double fRec349[2];
	double fRec360[2];
	double fRec358[2];
	double fRec366[2];
	double fRec364[2];
	double fRec363[2];
	double fRec361[2];
	double fVec4[128];
	double fRec384[2];
	double fRec382[2];
	double fRec381[2];
	double fRec379[2];
	double fRec378[2];
	double fRec376[2];
	double fRec375[2];
	double fRec373[2];
	double fRec372[2];
	double fRec370[2];
	double fRec369[2];
	double fRec367[2];
	double fRec399[2];
	double fRec397[2];
	double fRec396[2];
	double fRec394[2];
	double fRec393[2];
	double fRec391[2];
	double fRec390[2];
	double fRec388[2];
	double fRec387[2];
	double fRec385[2];
	double fRec411[2];
	double fRec409[2];
	double fRec408[2];
	double fRec406[2];
	double fRec405[2];
	double fRec403[2];
	double fRec402[2];
	double fRec400[2];
	double fRec420[2];
	double fRec418[2];
	double fRec417[2];
	double fRec415[2];
	double fRec414[2];
	double fRec412[2];
	double fRec423[2];
	double fRec421[2];
	double fRec429[2];
	double fRec427[2];
	double fRec426[2];
	double fRec424[2];
	double fVec5[128];
	double fRec447[2];
	double fRec445[2];
	double fRec444[2];
	double fRec442[2];
	double fRec441[2];
	double fRec439[2];
	double fRec438[2];
	double fRec436[2];
	double fRec435[2];
	double fRec433[2];
	double fRec432[2];
	double fRec430[2];
	double fRec462[2];
	double fRec460[2];
	double fRec459[2];
	double fRec457[2];
	double fRec456[2];
	double fRec454[2];
	double fRec453[2];
	double fRec451[2];
	double fRec450[2];
	double fRec448[2];
	double fRec474[2];
	double fRec472[2];
	double fRec471[2];
	double fRec469[2];
	double fRec468[2];
	double fRec466[2];
	double fRec465[2];
	double fRec463[2];
	double fRec483[2];
	double fRec481[2];
	double fRec480[2];
	double fRec478[2];
	double fRec477[2];
	double fRec475[2];
	double fRec486[2];
	double fRec484[2];
	double fRec492[2];
	double fRec490[2];
	double fRec489[2];
	double fRec487[2];
	double fVec6[128];
	double fRec510[2];
	double fRec508[2];
	double fRec507[2];
	double fRec505[2];
	double fRec504[2];
	double fRec502[2];
	double fRec501[2];
	double fRec499[2];
	double fRec498[2];
	double fRec496[2];
	double fRec495[2];
	double fRec493[2];
	double fRec525[2];
	double fRec523[2];
	double fRec522[2];
	double fRec520[2];
	double fRec519[2];
	double fRec517[2];
	double fRec516[2];
	double fRec514[2];
	double fRec513[2];
	double fRec511[2];
	double fRec537[2];
	double fRec535[2];
	double fRec534[2];
	double fRec532[2];
	double fRec531[2];
	double fRec529[2];
	double fRec528[2];
	double fRec526[2];
	double fRec546[2];
	double fRec544[2];
	double fRec543[2];
	double fRec541[2];
	double fRec540[2];
	double fRec538[2];
	double fRec549[2];
	double fRec547[2];
	double fRec555[2];
	double fRec553[2];
	double fRec552[2];
	double fRec550[2];
	double fVec7[128];
	double fRec567[2];
	double fRec565[2];
	double fRec564[2];
	double fRec562[2];
	double fRec561[2];
	double fRec559[2];
	double fRec558[2];
	double fRec556[2];
	double fRec576[2];
	double fRec574[2];
	double fRec573[2];
	double fRec571[2];
	double fRec570[2];
	double fRec568[2];
	double fRec582[2];
	double fRec580[2];
	double fRec579[2];
	double fRec577[2];
	double fRec585[2];
	double fRec583[2];
	double fRec603[2];
	double fRec601[2];
	double fRec600[2];
	double fRec598[2];
	double fRec597[2];
	double fRec595[2];
	double fRec594[2];
	double fRec592[2];
	double fRec591[2];
	double fRec589[2];
	double fRec588[2];
	double fRec586[2];
	double fRec618[2];
	double fRec616[2];
	double fRec615[2];
	double fRec613[2];
	double fRec612[2];
	double fRec610[2];
	double fRec609[2];
	double fRec607[2];
	double fRec606[2];
	double fRec604[2];
	double fVec8[128];
	double fRec636[2];
	double fRec634[2];
	double fRec633[2];
	double fRec631[2];
	double fRec630[2];
	double fRec628[2];
	double fRec627[2];
	double fRec625[2];
	double fRec624[2];
	double fRec622[2];
	double fRec621[2];
	double fRec619[2];
	double fRec651[2];
	double fRec649[2];
	double fRec648[2];
	double fRec646[2];
	double fRec645[2];
	double fRec643[2];
	double fRec642[2];
	double fRec640[2];
	double fRec639[2];
	double fRec637[2];
	double fRec663[2];
	double fRec661[2];
	double fRec660[2];
	double fRec658[2];
	double fRec657[2];
	double fRec655[2];
	double fRec654[2];
	double fRec652[2];
	double fRec672[2];
	double fRec670[2];
	double fRec669[2];
	double fRec667[2];
	double fRec666[2];
	double fRec664[2];
	double fRec675[2];
	double fRec673[2];
	double fRec681[2];
	double fRec679[2];
	double fRec678[2];
	double fRec676[2];
	double fVec9[128];
	double fRec699[2];
	double fRec697[2];
	double fRec696[2];
	double fRec694[2];
	double fRec693[2];
	double fRec691[2];
	double fRec690[2];
	double fRec688[2];
	double fRec687[2];
	double fRec685[2];
	double fRec684[2];
	double fRec682[2];
	double fRec714[2];
	double fRec712[2];
	double fRec711[2];
	double fRec709[2];
	double fRec708[2];
	double fRec706[2];
	double fRec705[2];
	double fRec703[2];
	double fRec702[2];
	double fRec700[2];
	double fRec726[2];
	double fRec724[2];
	double fRec723[2];
	double fRec721[2];
	double fRec720[2];
	double fRec718[2];
	double fRec717[2];
	double fRec715[2];
	double fRec735[2];
	double fRec733[2];
	double fRec732[2];
	double fRec730[2];
	double fRec729[2];
	double fRec727[2];
	double fRec738[2];
	double fRec736[2];
	double fRec744[2];
	double fRec742[2];
	double fRec741[2];
	double fRec739[2];
	double fVec10[128];
	double fRec756[2];
	double fRec754[2];
	double fRec753[2];
	double fRec751[2];
	double fRec750[2];
	double fRec748[2];
	double fRec747[2];
	double fRec745[2];
	double fRec765[2];
	double fRec763[2];
	double fRec762[2];
	double fRec760[2];
	double fRec759[2];
	double fRec757[2];
	double fRec771[2];
	double fRec769[2];
	double fRec768[2];
	double fRec766[2];
	double fRec774[2];
	double fRec772[2];
	double fRec792[2];
	double fRec790[2];
	double fRec789[2];
	double fRec787[2];
	double fRec786[2];
	double fRec784[2];
	double fRec783[2];
	double fRec781[2];
	double fRec780[2];
	double fRec778[2];
	double fRec777[2];
	double fRec775[2];
	double fRec807[2];
	double fRec805[2];
	double fRec804[2];
	double fRec802[2];
	double fRec801[2];
	double fRec799[2];
	double fRec798[2];
	double fRec796[2];
	double fRec795[2];
	double fRec793[2];
	double fVec11[128];
	double fRec825[2];
	double fRec823[2];
	double fRec822[2];
	double fRec820[2];
	double fRec819[2];
	double fRec817[2];
	double fRec816[2];
	double fRec814[2];
	double fRec813[2];
	double fRec811[2];
	double fRec810[2];
	double fRec808[2];
	double fRec840[2];
	double fRec838[2];
	double fRec837[2];
	double fRec835[2];
	double fRec834[2];
	double fRec832[2];
	double fRec831[2];
	double fRec829[2];
	double fRec828[2];
	double fRec826[2];
	double fRec852[2];
	double fRec850[2];
	double fRec849[2];
	double fRec847[2];
	double fRec846[2];
	double fRec844[2];
	double fRec843[2];
	double fRec841[2];
	double fRec861[2];
	double fRec859[2];
	double fRec858[2];
	double fRec856[2];
	double fRec855[2];
	double fRec853[2];
	double fRec864[2];
	double fRec862[2];
	double fRec870[2];
	double fRec868[2];
	double fRec867[2];
	double fRec865[2];
	double fVec12[128];
	double fRec888[2];
	double fRec886[2];
	double fRec885[2];
	double fRec883[2];
	double fRec882[2];
	double fRec880[2];
	double fRec879[2];
	double fRec877[2];
	double fRec876[2];
	double fRec874[2];
	double fRec873[2];
	double fRec871[2];
	double fRec903[2];
	double fRec901[2];
	double fRec900[2];
	double fRec898[2];
	double fRec897[2];
	double fRec895[2];
	double fRec894[2];
	double fRec892[2];
	double fRec891[2];
	double fRec889[2];
	double fRec915[2];
	double fRec913[2];
	double fRec912[2];
	double fRec910[2];
	double fRec909[2];
	double fRec907[2];
	double fRec906[2];
	double fRec904[2];
	double fRec924[2];
	double fRec922[2];
	double fRec921[2];
	double fRec919[2];
	double fRec918[2];
	double fRec916[2];
	double fRec927[2];
	double fRec925[2];
	double fRec933[2];
	double fRec931[2];
	double fRec930[2];
	double fRec928[2];
	double fVec13[128];
	double fRec951[2];
	double fRec949[2];
	double fRec948[2];
	double fRec946[2];
	double fRec945[2];
	double fRec943[2];
	double fRec942[2];
	double fRec940[2];
	double fRec939[2];
	double fRec937[2];
	double fRec936[2];
	double fRec934[2];
	double fRec963[2];
	double fRec961[2];
	double fRec960[2];
	double fRec958[2];
	double fRec957[2];
	double fRec955[2];
	double fRec954[2];
	double fRec952[2];
	double fRec972[2];
	double fRec970[2];
	double fRec969[2];
	double fRec967[2];
	double fRec966[2];
	double fRec964[2];
	double fRec975[2];
	double fRec973[2];
	double fRec981[2];
	double fRec979[2];
	double fRec978[2];
	double fRec976[2];
	double fRec996[2];
	double fRec994[2];
	double fRec993[2];
	double fRec991[2];
	double fRec990[2];
	double fRec988[2];
	double fRec987[2];
	double fRec985[2];
	double fRec984[2];
	double fRec982[2];
	double fVec14[128];
	double fRec1014[2];
	double fRec1012[2];
	double fRec1011[2];
	double fRec1009[2];
	double fRec1008[2];
	double fRec1006[2];
	double fRec1005[2];
	double fRec1003[2];
	double fRec1002[2];
	double fRec1000[2];
	double fRec999[2];
	double fRec997[2];
	double fRec1029[2];
	double fRec1027[2];
	double fRec1026[2];
	double fRec1024[2];
	double fRec1023[2];
	double fRec1021[2];
	double fRec1020[2];
	double fRec1018[2];
	double fRec1017[2];
	double fRec1015[2];
	double fRec1041[2];
	double fRec1039[2];
	double fRec1038[2];
	double fRec1036[2];
	double fRec1035[2];
	double fRec1033[2];
	double fRec1032[2];
	double fRec1030[2];
	double fRec1050[2];
	double fRec1048[2];
	double fRec1047[2];
	double fRec1045[2];
	double fRec1044[2];
	double fRec1042[2];
	double fRec1053[2];
	double fRec1051[2];
	double fRec1059[2];
	double fRec1057[2];
	double fRec1056[2];
	double fRec1054[2];
	double fVec15[128];
	double fConst124;
	double fConst125;
	double fConst126;
	double fConst127;
	double fConst128;
	double fConst129;
	double fConst130;
	double fConst131;
	double fConst132;
	double fConst133;
	double fRec1077[2];
	double fRec1075[2];
	double fRec1074[2];
	double fRec1072[2];
	double fRec1071[2];
	double fRec1069[2];
	double fRec1068[2];
	double fRec1066[2];
	double fRec1065[2];
	double fRec1063[2];
	double fRec1062[2];
	double fRec1060[2];
	double fConst134;
	double fConst135;
	double fConst136;
	double fConst137;
	double fConst138;
	double fConst139;
	double fConst140;
	double fConst141;
	double fConst142;
	double fRec1092[2];
	double fRec1090[2];
	double fRec1089[2];
	double fRec1087[2];
	double fRec1086[2];
	double fRec1084[2];
	double fRec1083[2];
	double fRec1081[2];
	double fRec1080[2];
	double fRec1078[2];
	double fConst143;
	double fConst144;
	double fConst145;
	double fConst146;
	double fConst147;
	double fConst148;
	double fConst149;
	double fRec1104[2];
	double fRec1102[2];
	double fRec1101[2];
	double fRec1099[2];
	double fRec1098[2];
	double fRec1096[2];
	double fRec1095[2];
	double fRec1093[2];
	double fConst150;
	double fConst151;
	double fConst152;
	double fConst153;
	double fConst154;
	double fConst155;
	double fRec1113[2];
	double fRec1111[2];
	double fRec1110[2];
	double fRec1108[2];
	double fRec1107[2];
	double fRec1105[2];
	double fConst156;
	double fConst157;
	double fConst158;
	double fRec1116[2];
	double fRec1114[2];
	double fConst159;
	double fConst160;
	double fConst161;
	double fConst162;
	double fRec1122[2];
	double fRec1120[2];
	double fRec1119[2];
	double fRec1117[2];
	double fVec16[128];
	int iConst163;
	double fRec1140[2];
	double fRec1138[2];
	double fRec1137[2];
	double fRec1135[2];
	double fRec1134[2];
	double fRec1132[2];
	double fRec1131[2];
	double fRec1129[2];
	double fRec1128[2];
	double fRec1126[2];
	double fRec1125[2];
	double fRec1123[2];
	double fRec1155[2];
	double fRec1153[2];
	double fRec1152[2];
	double fRec1150[2];
	double fRec1149[2];
	double fRec1147[2];
	double fRec1146[2];
	double fRec1144[2];
	double fRec1143[2];
	double fRec1141[2];
	double fRec1167[2];
	double fRec1165[2];
	double fRec1164[2];
	double fRec1162[2];
	double fRec1161[2];
	double fRec1159[2];
	double fRec1158[2];
	double fRec1156[2];
	double fRec1176[2];
	double fRec1174[2];
	double fRec1173[2];
	double fRec1171[2];
	double fRec1170[2];
	double fRec1168[2];
	double fRec1179[2];
	double fRec1177[2];
	double fRec1185[2];
	double fRec1183[2];
	double fRec1182[2];
	double fRec1180[2];
	double fVec17[128];
	double fRec1203[2];
	double fRec1201[2];
	double fRec1200[2];
	double fRec1198[2];
	double fRec1197[2];
	double fRec1195[2];
	double fRec1194[2];
	double fRec1192[2];
	double fRec1191[2];
	double fRec1189[2];
	double fRec1188[2];
	double fRec1186[2];
	double fRec1218[2];
	double fRec1216[2];
	double fRec1215[2];
	double fRec1213[2];
	double fRec1212[2];
	double fRec1210[2];
	double fRec1209[2];
	double fRec1207[2];
	double fRec1206[2];
	double fRec1204[2];
	double fRec1230[2];
	double fRec1228[2];
	double fRec1227[2];
	double fRec1225[2];
	double fRec1224[2];
	double fRec1222[2];
	double fRec1221[2];
	double fRec1219[2];
	double fRec1239[2];
	double fRec1237[2];
	double fRec1236[2];
	double fRec1234[2];
	double fRec1233[2];
	double fRec1231[2];
	double fRec1242[2];
	double fRec1240[2];
	double fRec1248[2];
	double fRec1246[2];
	double fRec1245[2];
	double fRec1243[2];
	double fVec18[128];
	double fRec1266[2];
	double fRec1264[2];
	double fRec1263[2];
	double fRec1261[2];
	double fRec1260[2];
	double fRec1258[2];
	double fRec1257[2];
	double fRec1255[2];
	double fRec1254[2];
	double fRec1252[2];
	double fRec1251[2];
	double fRec1249[2];
	double fRec1281[2];
	double fRec1279[2];
	double fRec1278[2];
	double fRec1276[2];
	double fRec1275[2];
	double fRec1273[2];
	double fRec1272[2];
	double fRec1270[2];
	double fRec1269[2];
	double fRec1267[2];
	double fRec1293[2];
	double fRec1291[2];
	double fRec1290[2];
	double fRec1288[2];
	double fRec1287[2];
	double fRec1285[2];
	double fRec1284[2];
	double fRec1282[2];
	double fRec1302[2];
	double fRec1300[2];
	double fRec1299[2];
	double fRec1297[2];
	double fRec1296[2];
	double fRec1294[2];
	double fRec1305[2];
	double fRec1303[2];
	double fRec1311[2];
	double fRec1309[2];
	double fRec1308[2];
	double fRec1306[2];
	double fVec19[128];
	double fRec1329[2];
	double fRec1327[2];
	double fRec1326[2];
	double fRec1324[2];
	double fRec1323[2];
	double fRec1321[2];
	double fRec1320[2];
	double fRec1318[2];
	double fRec1317[2];
	double fRec1315[2];
	double fRec1314[2];
	double fRec1312[2];
	double fRec1344[2];
	double fRec1342[2];
	double fRec1341[2];
	double fRec1339[2];
	double fRec1338[2];
	double fRec1336[2];
	double fRec1335[2];
	double fRec1333[2];
	double fRec1332[2];
	double fRec1330[2];
	double fRec1356[2];
	double fRec1354[2];
	double fRec1353[2];
	double fRec1351[2];
	double fRec1350[2];
	double fRec1348[2];
	double fRec1347[2];
	double fRec1345[2];
	double fRec1365[2];
	double fRec1363[2];
	double fRec1362[2];
	double fRec1360[2];
	double fRec1359[2];
	double fRec1357[2];
	double fRec1368[2];
	double fRec1366[2];
	double fRec1374[2];
	double fRec1372[2];
	double fRec1371[2];
	double fRec1369[2];
	double fVec20[128];
	double fRec1392[2];
	double fRec1390[2];
	double fRec1389[2];
	double fRec1387[2];
	double fRec1386[2];
	double fRec1384[2];
	double fRec1383[2];
	double fRec1381[2];
	double fRec1380[2];
	double fRec1378[2];
	double fRec1377[2];
	double fRec1375[2];
	double fRec1407[2];
	double fRec1405[2];
	double fRec1404[2];
	double fRec1402[2];
	double fRec1401[2];
	double fRec1399[2];
	double fRec1398[2];
	double fRec1396[2];
	double fRec1395[2];
	double fRec1393[2];
	double fRec1419[2];
	double fRec1417[2];
	double fRec1416[2];
	double fRec1414[2];
	double fRec1413[2];
	double fRec1411[2];
	double fRec1410[2];
	double fRec1408[2];
	double fRec1428[2];
	double fRec1426[2];
	double fRec1425[2];
	double fRec1423[2];
	double fRec1422[2];
	double fRec1420[2];
	double fRec1431[2];
	double fRec1429[2];
	double fRec1437[2];
	double fRec1435[2];
	double fRec1434[2];
	double fRec1432[2];
	double fVec21[128];
	double fRec1455[2];
	double fRec1453[2];
	double fRec1452[2];
	double fRec1450[2];
	double fRec1449[2];
	double fRec1447[2];
	double fRec1446[2];
	double fRec1444[2];
	double fRec1443[2];
	double fRec1441[2];
	double fRec1440[2];
	double fRec1438[2];
	double fRec1470[2];
	double fRec1468[2];
	double fRec1467[2];
	double fRec1465[2];
	double fRec1464[2];
	double fRec1462[2];
	double fRec1461[2];
	double fRec1459[2];
	double fRec1458[2];
	double fRec1456[2];
	double fRec1482[2];
	double fRec1480[2];
	double fRec1479[2];
	double fRec1477[2];
	double fRec1476[2];
	double fRec1474[2];
	double fRec1473[2];
	double fRec1471[2];
	double fRec1491[2];
	double fRec1489[2];
	double fRec1488[2];
	double fRec1486[2];
	double fRec1485[2];
	double fRec1483[2];
	double fRec1494[2];
	double fRec1492[2];
	double fRec1500[2];
	double fRec1498[2];
	double fRec1497[2];
	double fRec1495[2];
	double fVec22[128];
	double fRec1518[2];
	double fRec1516[2];
	double fRec1515[2];
	double fRec1513[2];
	double fRec1512[2];
	double fRec1510[2];
	double fRec1509[2];
	double fRec1507[2];
	double fRec1506[2];
	double fRec1504[2];
	double fRec1503[2];
	double fRec1501[2];
	double fRec1533[2];
	double fRec1531[2];
	double fRec1530[2];
	double fRec1528[2];
	double fRec1527[2];
	double fRec1525[2];
	double fRec1524[2];
	double fRec1522[2];
	double fRec1521[2];
	double fRec1519[2];
	double fRec1545[2];
	double fRec1543[2];
	double fRec1542[2];
	double fRec1540[2];
	double fRec1539[2];
	double fRec1537[2];
	double fRec1536[2];
	double fRec1534[2];
	double fRec1554[2];
	double fRec1552[2];
	double fRec1551[2];
	double fRec1549[2];
	double fRec1548[2];
	double fRec1546[2];
	double fRec1557[2];
	double fRec1555[2];
	double fRec1563[2];
	double fRec1561[2];
	double fRec1560[2];
	double fRec1558[2];
	double fVec23[128];
	double fConst164;
	double fConst165;
	double fConst166;
	double fConst167;
	double fConst168;
	double fConst169;
	double fConst170;
	double fConst171;
	double fConst172;
	double fConst173;
	double fRec1581[2];
	double fRec1579[2];
	double fRec1578[2];
	double fRec1576[2];
	double fRec1575[2];
	double fRec1573[2];
	double fRec1572[2];
	double fRec1570[2];
	double fRec1569[2];
	double fRec1567[2];
	double fRec1566[2];
	double fRec1564[2];
	double fConst174;
	double fConst175;
	double fConst176;
	double fConst177;
	double fConst178;
	double fConst179;
	double fConst180;
	double fConst181;
	double fConst182;
	double fRec1596[2];
	double fRec1594[2];
	double fRec1593[2];
	double fRec1591[2];
	double fRec1590[2];
	double fRec1588[2];
	double fRec1587[2];
	double fRec1585[2];
	double fRec1584[2];
	double fRec1582[2];
	double fConst183;
	double fConst184;
	double fConst185;
	double fConst186;
	double fConst187;
	double fConst188;
	double fConst189;
	double fRec1608[2];
	double fRec1606[2];
	double fRec1605[2];
	double fRec1603[2];
	double fRec1602[2];
	double fRec1600[2];
	double fRec1599[2];
	double fRec1597[2];
	double fConst190;
	double fConst191;
	double fConst192;
	double fConst193;
	double fConst194;
	double fConst195;
	double fRec1617[2];
	double fRec1615[2];
	double fRec1614[2];
	double fRec1612[2];
	double fRec1611[2];
	double fRec1609[2];
	double fConst196;
	double fConst197;
	double fConst198;
	double fRec1620[2];
	double fRec1618[2];
	double fConst199;
	double fConst200;
	double fConst201;
	double fConst202;
	double fRec1626[2];
	double fRec1624[2];
	double fRec1623[2];
	double fRec1621[2];
	double fVec24[12];
	int iConst203;
	double fRec1638[2];
	double fRec1636[2];
	double fRec1635[2];
	double fRec1633[2];
	double fRec1632[2];
	double fRec1630[2];
	double fRec1629[2];
	double fRec1627[2];
	double fRec1647[2];
	double fRec1645[2];
	double fRec1644[2];
	double fRec1642[2];
	double fRec1641[2];
	double fRec1639[2];
	double fRec1653[2];
	double fRec1651[2];
	double fRec1650[2];
	double fRec1648[2];
	double fRec1656[2];
	double fRec1654[2];
	double fRec1671[2];
	double fRec1669[2];
	double fRec1668[2];
	double fRec1666[2];
	double fRec1665[2];
	double fRec1663[2];
	double fRec1662[2];
	double fRec1660[2];
	double fRec1659[2];
	double fRec1657[2];
	double fRec1689[2];
	double fRec1687[2];
	double fRec1686[2];
	double fRec1684[2];
	double fRec1683[2];
	double fRec1681[2];
	double fRec1680[2];
	double fRec1678[2];
	double fRec1677[2];
	double fRec1675[2];
	double fRec1674[2];
	double fRec1672[2];
	double fVec25[12];
	double fRec1707[2];
	double fRec1705[2];
	double fRec1704[2];
	double fRec1702[2];
	double fRec1701[2];
	double fRec1699[2];
	double fRec1698[2];
	double fRec1696[2];
	double fRec1695[2];
	double fRec1693[2];
	double fRec1692[2];
	double fRec1690[2];
	double fRec1722[2];
	double fRec1720[2];
	double fRec1719[2];
	double fRec1717[2];
	double fRec1716[2];
	double fRec1714[2];
	double fRec1713[2];
	double fRec1711[2];
	double fRec1710[2];
	double fRec1708[2];
	double fRec1734[2];
	double fRec1732[2];
	double fRec1731[2];
	double fRec1729[2];
	double fRec1728[2];
	double fRec1726[2];
	double fRec1725[2];
	double fRec1723[2];
	double fRec1743[2];
	double fRec1741[2];
	double fRec1740[2];
	double fRec1738[2];
	double fRec1737[2];
	double fRec1735[2];
	double fRec1746[2];
	double fRec1744[2];
	double fRec1752[2];
	double fRec1750[2];
	double fRec1749[2];
	double fRec1747[2];
	double fVec26[12];
	double fRec1770[2];
	double fRec1768[2];
	double fRec1767[2];
	double fRec1765[2];
	double fRec1764[2];
	double fRec1762[2];
	double fRec1761[2];
	double fRec1759[2];
	double fRec1758[2];
	double fRec1756[2];
	double fRec1755[2];
	double fRec1753[2];
	double fRec1785[2];
	double fRec1783[2];
	double fRec1782[2];
	double fRec1780[2];
	double fRec1779[2];
	double fRec1777[2];
	double fRec1776[2];
	double fRec1774[2];
	double fRec1773[2];
	double fRec1771[2];
	double fRec1797[2];
	double fRec1795[2];
	double fRec1794[2];
	double fRec1792[2];
	double fRec1791[2];
	double fRec1789[2];
	double fRec1788[2];
	double fRec1786[2];
	double fRec1806[2];
	double fRec1804[2];
	double fRec1803[2];
	double fRec1801[2];
	double fRec1800[2];
	double fRec1798[2];
	double fRec1809[2];
	double fRec1807[2];
	double fRec1815[2];
	double fRec1813[2];
	double fRec1812[2];
	double fRec1810[2];
	double fVec27[12];
	double fConst204;
	double fConst205;
	double fConst206;
	double fConst207;
	double fConst208;
	double fConst209;
	double fRec1833[2];
	double fRec1831[2];
	double fRec1830[2];
	double fRec1828[2];
	double fConst210;
	double fConst211;
	double fRec1827[2];
	double fRec1825[2];
	double fRec1824[2];
	double fRec1822[2];
	double fConst212;
	double fConst213;
	double fRec1821[2];
	double fRec1819[2];
	double fRec1818[2];
	double fRec1816[2];
	double fConst214;
	double fConst215;
	double fConst216;
	double fConst217;
	double fConst218;
	double fConst219;
	double fConst220;
	double fConst221;
	double fConst222;
	double fRec1848[2];
	double fRec1846[2];
	double fRec1845[2];
	double fRec1843[2];
	double fRec1842[2];
	double fRec1840[2];
	double fRec1839[2];
	double fRec1837[2];
	double fRec1836[2];
	double fRec1834[2];
	double fConst223;
	double fConst224;
	double fConst225;
	double fConst226;
	double fConst227;
	double fConst228;
	double fConst229;
	double fRec1860[2];
	double fRec1858[2];
	double fRec1857[2];
	double fRec1855[2];
	double fRec1854[2];
	double fRec1852[2];
	double fRec1851[2];
	double fRec1849[2];
	double fConst230;
	double fConst231;
	double fConst232;
	double fConst233;
	double fConst234;
	double fConst235;
	double fRec1869[2];
	double fRec1867[2];
	double fRec1866[2];
	double fRec1864[2];
	double fRec1863[2];
	double fRec1861[2];
	double fConst236;
	double fConst237;
	double fConst238;
	double fRec1872[2];
	double fRec1870[2];
	double fConst239;
	double fConst240;
	double fConst241;
	double fConst242;
	double fRec1878[2];
	double fRec1876[2];
	double fRec1875[2];
	double fRec1873[2];
	double fConst243;
	double fConst244;
	double fConst245;
	double fRec1881[2];
	double fRec1879[2];
	double fConst246;
	double fConst247;
	double fConst248;
	double fConst249;
	double fRec1887[2];
	double fRec1885[2];
	double fRec1884[2];
	double fRec1882[2];
	double fConst250;
	double fConst251;
	double fConst252;
	double fConst253;
	double fConst254;
	double fConst255;
	double fRec1896[2];
	double fRec1894[2];
	double fRec1893[2];
	double fRec1891[2];
	double fRec1890[2];
	double fRec1888[2];
	double fConst256;
	double fConst257;
	double fConst258;
	double fConst259;
	double fConst260;
	double fConst261;
	double fConst262;
	double fRec1908[2];
	double fRec1906[2];
	double fRec1905[2];
	double fRec1903[2];
	double fRec1902[2];
	double fRec1900[2];
	double fRec1899[2];
	double fRec1897[2];
	double fConst263;
	double fConst264;
	double fConst265;
	double fConst266;
	double fConst267;
	double fConst268;
	double fConst269;
	double fConst270;
	double fConst271;
	double fRec1923[2];
	double fRec1921[2];
	double fRec1920[2];
	double fRec1918[2];
	double fRec1917[2];
	double fRec1915[2];
	double fRec1914[2];
	double fRec1912[2];
	double fRec1911[2];
	double fRec1909[2];
	double fConst272;
	double fConst273;
	double fConst274;
	double fConst275;
	double fConst276;
	double fConst277;
	double fConst278;
	double fConst279;
	double fConst280;
	double fConst281;
	double fRec1941[2];
	double fRec1939[2];
	double fRec1938[2];
	double fRec1936[2];
	double fRec1935[2];
	double fRec1933[2];
	double fRec1932[2];
	double fRec1930[2];
	double fRec1929[2];
	double fRec1927[2];
	double fRec1926[2];
	double fRec1924[2];
	double fVec28[512];
	int iConst282;
	double fConst283;
	double fConst284;
	double fConst285;
	double fRec1944[2];
	double fRec1942[2];
	double fConst286;
	double fConst287;
	double fConst288;
	double fConst289;
	double fRec1950[2];
	double fRec1948[2];
	double fRec1947[2];
	double fRec1945[2];
	double fConst290;
	double fConst291;
	double fConst292;
	double fConst293;
	double fConst294;
	double fConst295;
	double fRec1959[2];
	double fRec1957[2];
	double fRec1956[2];
	double fRec1954[2];
	double fRec1953[2];
	double fRec1951[2];
	double fConst296;
	double fConst297;
	double fConst298;
	double fConst299;
	double fConst300;
	double fConst301;
	double fConst302;
	double fRec1971[2];
	double fRec1969[2];
	double fRec1968[2];
	double fRec1966[2];
	double fRec1965[2];
	double fRec1963[2];
	double fRec1962[2];
	double fRec1960[2];
	double fConst303;
	double fConst304;
	double fConst305;
	double fConst306;
	double fConst307;
	double fConst308;
	double fConst309;
	double fConst310;
	double fConst311;
	double fRec1986[2];
	double fRec1984[2];
	double fRec1983[2];
	double fRec1981[2];
	double fRec1980[2];
	double fRec1978[2];
	double fRec1977[2];
	double fRec1975[2];
	double fRec1974[2];
	double fRec1972[2];
	double fConst312;
	double fConst313;
	double fConst314;
	double fConst315;
	double fConst316;
	double fConst317;
	double fConst318;
	double fConst319;
	double fConst320;
	double fConst321;
	double fRec2004[2];
	double fRec2002[2];
	double fRec2001[2];
	double fRec1999[2];
	double fRec1998[2];
	double fRec1996[2];
	double fRec1995[2];
	double fRec1993[2];
	double fRec1992[2];
	double fRec1990[2];
	double fRec1989[2];
	double fRec1987[2];
	double fVec29[512];
	int iConst322;
	double fRec2007[2];
	double fRec2005[2];
	double fRec2013[2];
	double fRec2011[2];
	double fRec2010[2];
	double fRec2008[2];
	double fRec2022[2];
	double fRec2020[2];
	double fRec2019[2];
	double fRec2017[2];
	double fRec2016[2];
	double fRec2014[2];
	double fRec2034[2];
	double fRec2032[2];
	double fRec2031[2];
	double fRec2029[2];
	double fRec2028[2];
	double fRec2026[2];
	double fRec2025[2];
	double fRec2023[2];
	double fRec2049[2];
	double fRec2047[2];
	double fRec2046[2];
	double fRec2044[2];
	double fRec2043[2];
	double fRec2041[2];
	double fRec2040[2];
	double fRec2038[2];
	double fRec2037[2];
	double fRec2035[2];
	double fRec2067[2];
	double fRec2065[2];
	double fRec2064[2];
	double fRec2062[2];
	double fRec2061[2];
	double fRec2059[2];
	double fRec2058[2];
	double fRec2056[2];
	double fRec2055[2];
	double fRec2053[2];
	double fRec2052[2];
	double fRec2050[2];
	double fVec30[512];
	double fRec2070[2];
	double fRec2068[2];
	double fRec2076[2];
	double fRec2074[2];
	double fRec2073[2];
	double fRec2071[2];
	double fRec2085[2];
	double fRec2083[2];
	double fRec2082[2];
	double fRec2080[2];
	double fRec2079[2];
	double fRec2077[2];
	double fRec2097[2];
	double fRec2095[2];
	double fRec2094[2];
	double fRec2092[2];
	double fRec2091[2];
	double fRec2089[2];
	double fRec2088[2];
	double fRec2086[2];
	double fRec2112[2];
	double fRec2110[2];
	double fRec2109[2];
	double fRec2107[2];
	double fRec2106[2];
	double fRec2104[2];
	double fRec2103[2];
	double fRec2101[2];
	double fRec2100[2];
	double fRec2098[2];
	double fRec2130[2];
	double fRec2128[2];
	double fRec2127[2];
	double fRec2125[2];
	double fRec2124[2];
	double fRec2122[2];
	double fRec2121[2];
	double fRec2119[2];
	double fRec2118[2];
	double fRec2116[2];
	double fRec2115[2];
	double fRec2113[2];
	double fVec31[512];
	double fRec2133[2];
	double fRec2131[2];
	double fRec2139[2];
	double fRec2137[2];
	double fRec2136[2];
	double fRec2134[2];
	double fRec2148[2];
	double fRec2146[2];
	double fRec2145[2];
	double fRec2143[2];
	double fRec2142[2];
	double fRec2140[2];
	double fRec2160[2];
	double fRec2158[2];
	double fRec2157[2];
	double fRec2155[2];
	double fRec2154[2];
	double fRec2152[2];
	double fRec2151[2];
	double fRec2149[2];
	double fRec2175[2];
	double fRec2173[2];
	double fRec2172[2];
	double fRec2170[2];
	double fRec2169[2];
	double fRec2167[2];
	double fRec2166[2];
	double fRec2164[2];
	double fRec2163[2];
	double fRec2161[2];
	double fRec2193[2];
	double fRec2191[2];
	double fRec2190[2];
	double fRec2188[2];
	double fRec2187[2];
	double fRec2185[2];
	double fRec2184[2];
	double fRec2182[2];
	double fRec2181[2];
	double fRec2179[2];
	double fRec2178[2];
	double fRec2176[2];
	double fVec32[512];
	double fRec2196[2];
	double fRec2194[2];
	double fRec2202[2];
	double fRec2200[2];
	double fRec2199[2];
	double fRec2197[2];
	double fRec2211[2];
	double fRec2209[2];
	double fRec2208[2];
	double fRec2206[2];
	double fRec2205[2];
	double fRec2203[2];
	double fRec2223[2];
	double fRec2221[2];
	double fRec2220[2];
	double fRec2218[2];
	double fRec2217[2];
	double fRec2215[2];
	double fRec2214[2];
	double fRec2212[2];
	double fRec2238[2];
	double fRec2236[2];
	double fRec2235[2];
	double fRec2233[2];
	double fRec2232[2];
	double fRec2230[2];
	double fRec2229[2];
	double fRec2227[2];
	double fRec2226[2];
	double fRec2224[2];
	double fRec2256[2];
	double fRec2254[2];
	double fRec2253[2];
	double fRec2251[2];
	double fRec2250[2];
	double fRec2248[2];
	double fRec2247[2];
	double fRec2245[2];
	double fRec2244[2];
	double fRec2242[2];
	double fRec2241[2];
	double fRec2239[2];
	double fVec33[512];
	double fRec2259[2];
	double fRec2257[2];
	double fRec2265[2];
	double fRec2263[2];
	double fRec2262[2];
	double fRec2260[2];
	double fRec2274[2];
	double fRec2272[2];
	double fRec2271[2];
	double fRec2269[2];
	double fRec2268[2];
	double fRec2266[2];
	double fRec2286[2];
	double fRec2284[2];
	double fRec2283[2];
	double fRec2281[2];
	double fRec2280[2];
	double fRec2278[2];
	double fRec2277[2];
	double fRec2275[2];
	double fRec2301[2];
	double fRec2299[2];
	double fRec2298[2];
	double fRec2296[2];
	double fRec2295[2];
	double fRec2293[2];
	double fRec2292[2];
	double fRec2290[2];
	double fRec2289[2];
	double fRec2287[2];
	double fRec2319[2];
	double fRec2317[2];
	double fRec2316[2];
	double fRec2314[2];
	double fRec2313[2];
	double fRec2311[2];
	double fRec2310[2];
	double fRec2308[2];
	double fRec2307[2];
	double fRec2305[2];
	double fRec2304[2];
	double fRec2302[2];
	double fVec34[512];
	double fRec2337[2];
	double fRec2335[2];
	double fRec2334[2];
	double fRec2332[2];
	double fRec2331[2];
	double fRec2329[2];
	double fRec2328[2];
	double fRec2326[2];
	double fRec2325[2];
	double fRec2323[2];
	double fRec2322[2];
	double fRec2320[2];
	double fRec2352[2];
	double fRec2350[2];
	double fRec2349[2];
	double fRec2347[2];
	double fRec2346[2];
	double fRec2344[2];
	double fRec2343[2];
	double fRec2341[2];
	double fRec2340[2];
	double fRec2338[2];
	double fRec2364[2];
	double fRec2362[2];
	double fRec2361[2];
	double fRec2359[2];
	double fRec2358[2];
	double fRec2356[2];
	double fRec2355[2];
	double fRec2353[2];
	double fRec2373[2];
	double fRec2371[2];
	double fRec2370[2];
	double fRec2368[2];
	double fRec2367[2];
	double fRec2365[2];
	double fRec2376[2];
	double fRec2374[2];
	double fRec2382[2];
	double fRec2380[2];
	double fRec2379[2];
	double fRec2377[2];
	double fVec35[512];
	double fRec2400[2];
	double fRec2398[2];
	double fRec2397[2];
	double fRec2395[2];
	double fRec2394[2];
	double fRec2392[2];
	double fRec2391[2];
	double fRec2389[2];
	double fRec2388[2];
	double fRec2386[2];
	double fRec2385[2];
	double fRec2383[2];
	double fRec2415[2];
	double fRec2413[2];
	double fRec2412[2];
	double fRec2410[2];
	double fRec2409[2];
	double fRec2407[2];
	double fRec2406[2];
	double fRec2404[2];
	double fRec2403[2];
	double fRec2401[2];
	double fRec2427[2];
	double fRec2425[2];
	double fRec2424[2];
	double fRec2422[2];
	double fRec2421[2];
	double fRec2419[2];
	double fRec2418[2];
	double fRec2416[2];
	double fRec2436[2];
	double fRec2434[2];
	double fRec2433[2];
	double fRec2431[2];
	double fRec2430[2];
	double fRec2428[2];
	double fRec2439[2];
	double fRec2437[2];
	double fRec2445[2];
	double fRec2443[2];
	double fRec2442[2];
	double fRec2440[2];
	double fVec36[512];
	double fRec2463[2];
	double fRec2461[2];
	double fRec2460[2];
	double fRec2458[2];
	double fRec2457[2];
	double fRec2455[2];
	double fRec2454[2];
	double fRec2452[2];
	double fRec2451[2];
	double fRec2449[2];
	double fRec2448[2];
	double fRec2446[2];
	double fRec2478[2];
	double fRec2476[2];
	double fRec2475[2];
	double fRec2473[2];
	double fRec2472[2];
	double fRec2470[2];
	double fRec2469[2];
	double fRec2467[2];
	double fRec2466[2];
	double fRec2464[2];
	double fRec2490[2];
	double fRec2488[2];
	double fRec2487[2];
	double fRec2485[2];
	double fRec2484[2];
	double fRec2482[2];
	double fRec2481[2];
	double fRec2479[2];
	double fRec2499[2];
	double fRec2497[2];
	double fRec2496[2];
	double fRec2494[2];
	double fRec2493[2];
	double fRec2491[2];
	double fRec2502[2];
	double fRec2500[2];
	double fRec2508[2];
	double fRec2506[2];
	double fRec2505[2];
	double fRec2503[2];
	double fVec37[512];
	double fRec2526[2];
	double fRec2524[2];
	double fRec2523[2];
	double fRec2521[2];
	double fRec2520[2];
	double fRec2518[2];
	double fRec2517[2];
	double fRec2515[2];
	double fRec2514[2];
	double fRec2512[2];
	double fRec2511[2];
	double fRec2509[2];
	double fRec2541[2];
	double fRec2539[2];
	double fRec2538[2];
	double fRec2536[2];
	double fRec2535[2];
	double fRec2533[2];
	double fRec2532[2];
	double fRec2530[2];
	double fRec2529[2];
	double fRec2527[2];
	double fRec2553[2];
	double fRec2551[2];
	double fRec2550[2];
	double fRec2548[2];
	double fRec2547[2];
	double fRec2545[2];
	double fRec2544[2];
	double fRec2542[2];
	double fRec2562[2];
	double fRec2560[2];
	double fRec2559[2];
	double fRec2557[2];
	double fRec2556[2];
	double fRec2554[2];
	double fRec2565[2];
	double fRec2563[2];
	double fRec2571[2];
	double fRec2569[2];
	double fRec2568[2];
	double fRec2566[2];
	double fVec38[512];
	double fRec2589[2];
	double fRec2587[2];
	double fRec2586[2];
	double fRec2584[2];
	double fRec2583[2];
	double fRec2581[2];
	double fRec2580[2];
	double fRec2578[2];
	double fRec2577[2];
	double fRec2575[2];
	double fRec2574[2];
	double fRec2572[2];
	double fRec2604[2];
	double fRec2602[2];
	double fRec2601[2];
	double fRec2599[2];
	double fRec2598[2];
	double fRec2596[2];
	double fRec2595[2];
	double fRec2593[2];
	double fRec2592[2];
	double fRec2590[2];
	double fRec2616[2];
	double fRec2614[2];
	double fRec2613[2];
	double fRec2611[2];
	double fRec2610[2];
	double fRec2608[2];
	double fRec2607[2];
	double fRec2605[2];
	double fRec2625[2];
	double fRec2623[2];
	double fRec2622[2];
	double fRec2620[2];
	double fRec2619[2];
	double fRec2617[2];
	double fRec2628[2];
	double fRec2626[2];
	double fRec2634[2];
	double fRec2632[2];
	double fRec2631[2];
	double fRec2629[2];
	double fVec39[512];
	double fRec2652[2];
	double fRec2650[2];
	double fRec2649[2];
	double fRec2647[2];
	double fRec2646[2];
	double fRec2644[2];
	double fRec2643[2];
	double fRec2641[2];
	double fRec2640[2];
	double fRec2638[2];
	double fRec2637[2];
	double fRec2635[2];
	double fRec2667[2];
	double fRec2665[2];
	double fRec2664[2];
	double fRec2662[2];
	double fRec2661[2];
	double fRec2659[2];
	double fRec2658[2];
	double fRec2656[2];
	double fRec2655[2];
	double fRec2653[2];
	double fRec2679[2];
	double fRec2677[2];
	double fRec2676[2];
	double fRec2674[2];
	double fRec2673[2];
	double fRec2671[2];
	double fRec2670[2];
	double fRec2668[2];
	double fRec2688[2];
	double fRec2686[2];
	double fRec2685[2];
	double fRec2683[2];
	double fRec2682[2];
	double fRec2680[2];
	double fRec2691[2];
	double fRec2689[2];
	double fRec2697[2];
	double fRec2695[2];
	double fRec2694[2];
	double fRec2692[2];
	double fVec40[512];
	double fRec2715[2];
	double fRec2713[2];
	double fRec2712[2];
	double fRec2710[2];
	double fRec2709[2];
	double fRec2707[2];
	double fRec2706[2];
	double fRec2704[2];
	double fRec2703[2];
	double fRec2701[2];
	double fRec2700[2];
	double fRec2698[2];
	double fRec2730[2];
	double fRec2728[2];
	double fRec2727[2];
	double fRec2725[2];
	double fRec2724[2];
	double fRec2722[2];
	double fRec2721[2];
	double fRec2719[2];
	double fRec2718[2];
	double fRec2716[2];
	double fRec2742[2];
	double fRec2740[2];
	double fRec2739[2];
	double fRec2737[2];
	double fRec2736[2];
	double fRec2734[2];
	double fRec2733[2];
	double fRec2731[2];
	double fRec2751[2];
	double fRec2749[2];
	double fRec2748[2];
	double fRec2746[2];
	double fRec2745[2];
	double fRec2743[2];
	double fRec2754[2];
	double fRec2752[2];
	double fRec2760[2];
	double fRec2758[2];
	double fRec2757[2];
	double fRec2755[2];
	double fVec41[512];
	double fRec2778[2];
	double fRec2776[2];
	double fRec2775[2];
	double fRec2773[2];
	double fRec2772[2];
	double fRec2770[2];
	double fRec2769[2];
	double fRec2767[2];
	double fRec2766[2];
	double fRec2764[2];
	double fRec2763[2];
	double fRec2761[2];
	double fRec2793[2];
	double fRec2791[2];
	double fRec2790[2];
	double fRec2788[2];
	double fRec2787[2];
	double fRec2785[2];
	double fRec2784[2];
	double fRec2782[2];
	double fRec2781[2];
	double fRec2779[2];
	double fRec2805[2];
	double fRec2803[2];
	double fRec2802[2];
	double fRec2800[2];
	double fRec2799[2];
	double fRec2797[2];
	double fRec2796[2];
	double fRec2794[2];
	double fRec2814[2];
	double fRec2812[2];
	double fRec2811[2];
	double fRec2809[2];
	double fRec2808[2];
	double fRec2806[2];
	double fRec2817[2];
	double fRec2815[2];
	double fRec2823[2];
	double fRec2821[2];
	double fRec2820[2];
	double fRec2818[2];
	double fVec42[512];
	double fRec2841[2];
	double fRec2839[2];
	double fRec2838[2];
	double fRec2836[2];
	double fRec2835[2];
	double fRec2833[2];
	double fRec2832[2];
	double fRec2830[2];
	double fRec2829[2];
	double fRec2827[2];
	double fRec2826[2];
	double fRec2824[2];
	double fRec2856[2];
	double fRec2854[2];
	double fRec2853[2];
	double fRec2851[2];
	double fRec2850[2];
	double fRec2848[2];
	double fRec2847[2];
	double fRec2845[2];
	double fRec2844[2];
	double fRec2842[2];
	double fRec2868[2];
	double fRec2866[2];
	double fRec2865[2];
	double fRec2863[2];
	double fRec2862[2];
	double fRec2860[2];
	double fRec2859[2];
	double fRec2857[2];
	double fRec2877[2];
	double fRec2875[2];
	double fRec2874[2];
	double fRec2872[2];
	double fRec2871[2];
	double fRec2869[2];
	double fRec2880[2];
	double fRec2878[2];
	double fRec2886[2];
	double fRec2884[2];
	double fRec2883[2];
	double fRec2881[2];
	double fVec43[512];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMHLS_FullSetup_6H6V_full_5");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMHLS_FullSetup_6H6V_full_5");
		m->declare("version", "1.2");
	}

	virtual int getNumInputs() {
		return 49;
		
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
			case 45: {
				rate = 1;
				break;
			}
			case 46: {
				rate = 1;
				break;
			}
			case 47: {
				rate = 1;
				break;
			}
			case 48: {
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
		fConst1 = double(iConst0);
		fConst2 = mydsp_faustpower2_f(fConst1);
		fConst3 = ((((21038.792477813076 / fConst1) + 284.22983763570784) / fConst1) + 1.0);
		fConst4 = (0.0 - (84155.169911252306 / (fConst2 * fConst3)));
		fConst5 = (0.0 - (((84155.169911252306 / fConst1) + 568.45967527141568) / (fConst1 * fConst3)));
		fConst6 = ((((23334.672205785024 / fConst1) + 249.93172202114809) / fConst1) + 1.0);
		fConst7 = (0.0 - (93338.688823140095 / (fConst2 * fConst6)));
		fConst8 = (0.0 - (((93338.688823140095 / fConst1) + 499.86344404229618) / (fConst1 * fConst6)));
		fConst9 = ((((29669.655997962589 / fConst1) + 168.32451016126626) / fConst1) + 1.0);
		fConst10 = (1.0 / ((fConst3 * fConst6) * fConst9));
		fConst11 = (3.1415926535897931 / double(iConst0));
		fConst12 = (0.0 - (118678.62399185036 / (fConst2 * fConst9)));
		fConst13 = (0.0 - (((118678.62399185036 / fConst1) + 336.64902032253252) / (fConst1 * fConst9)));
		fConst14 = ((121.98966968986812 / fConst1) + 1.0);
		fConst15 = (0.0 - (243.97933937973625 / (fConst1 * fConst14)));
		fConst16 = ((((15971.154193732045 / fConst1) + 224.25739781362216) / fConst1) + 1.0);
		fConst17 = (0.0 - (63884.616774928181 / (fConst2 * fConst16)));
		fConst18 = (0.0 - (((63884.616774928181 / fConst1) + 448.51479562724433) / (fConst1 * fConst16)));
		fConst19 = ((((20317.232956903419 / fConst1) + 155.52869665231037) / fConst1) + 1.0);
		fConst20 = (1.0 / ((fConst14 * fConst16) * fConst19));
		fConst21 = (0.0 - (81268.931827613676 / (fConst2 * fConst19)));
		fConst22 = (0.0 - (((81268.931827613676 / fConst1) + 311.05739330462075) / (fConst1 * fConst19)));
		fConst23 = ((((10227.965605817382 / fConst1) + 193.7664384515102) / fConst1) + 1.0);
		fConst24 = ((((12855.048748690073 / fConst1) + 140.75073765235712) / fConst1) + 1.0);
		fConst25 = (1.0 / (fConst23 * fConst24));
		fConst26 = (0.0 - (((51420.194994760292 / fConst1) + 281.50147530471423) / (fConst1 * fConst24)));
		fConst27 = (0.0 - (51420.194994760292 / (fConst2 * fConst24)));
		fConst28 = (0.0 - (((40911.862423269529 / fConst1) + 387.53287690302039) / (fConst1 * fConst23)));
		fConst29 = (0.0 - (40911.862423269529 / (fConst2 * fConst23)));
		fConst30 = ((77.681088721927608 / fConst1) + 1.0);
		fConst31 = (0.0 - (155.36217744385522 / (fConst1 * fConst30)));
		fConst32 = ((((7228.2176497399441 / fConst1) + 123.02921694039281) / fConst1) + 1.0);
		fConst33 = (1.0 / (fConst30 * fConst32));
		fConst34 = (0.0 - (28912.870598959777 / (fConst2 * fConst32)));
		fConst35 = (0.0 - (((28912.870598959777 / fConst1) + 246.05843388078563) / (fConst1 * fConst32)));
		fConst36 = ((33.451717610386737 / fConst1) + 1.0);
		fConst37 = (1.0 / fConst36);
		fConst38 = (0.0 - (66.903435220773474 / (fConst1 * fConst36)));
		fConst39 = ((((3357.0522332551745 / fConst1) + 100.35515283116021) / fConst1) + 1.0);
		fConst40 = (1.0 / fConst39);
		fConst41 = (0.0 - (13428.208933020698 / (fConst2 * fConst39)));
		fConst42 = (0.0 - (((13428.208933020698 / fConst1) + 200.71030566232042) / (fConst1 * fConst39)));
		iConst43 = int(((0.00061186204235308644 * double(iConst0)) + 0.5));
		fConst44 = ((((20981.493974173598 / fConst1) + 283.84252814311498) / fConst1) + 1.0);
		fConst45 = (0.0 - (83925.975896694392 / (fConst2 * fConst44)));
		fConst46 = (0.0 - (((83925.975896694392 / fConst1) + 567.68505628622995) / (fConst1 * fConst44)));
		fConst47 = ((((23271.120944384485 / fConst1) + 249.59114930280123) / fConst1) + 1.0);
		fConst48 = (0.0 - (93084.483777537942 / (fConst2 * fConst47)));
		fConst49 = (0.0 - (((93084.483777537942 / fConst1) + 499.18229860560245) / (fConst1 * fConst47)));
		fConst50 = ((((29588.851603224914 / fConst1) + 168.09514057373877) / fConst1) + 1.0);
		fConst51 = (1.0 / ((fConst44 * fConst47) * fConst50));
		fConst52 = (0.0 - (118355.40641289965 / (fConst2 * fConst50)));
		fConst53 = (0.0 - (((118355.40641289965 / fConst1) + 336.19028114747755) / (fConst1 * fConst50)));
		fConst54 = ((121.82343887658625 / fConst1) + 1.0);
		fConst55 = (0.0 - (243.6468777531725 / (fConst1 * fConst54)));
		fConst56 = ((((15927.657246953317 / fConst1) + 223.95181054776756) / fConst1) + 1.0);
		fConst57 = (0.0 - (63710.628987813267 / (fConst2 * fConst56)));
		fConst58 = (0.0 - (((63710.628987813267 / fConst1) + 447.90362109553513) / (fConst1 * fConst56)));
		fConst59 = ((((20261.899598406115 / fConst1) + 155.31676344682742) / fConst1) + 1.0);
		fConst60 = (1.0 / ((fConst54 * fConst56) * fConst59));
		fConst61 = (0.0 - (81047.598393624459 / (fConst2 * fConst59)));
		fConst62 = (0.0 - (((81047.598393624459 / fConst1) + 310.63352689365485) / (fConst1 * fConst59)));
		fConst63 = ((((10200.110056355246 / fConst1) + 193.50240008881593) / fConst1) + 1.0);
		fConst64 = (0.0 - (40800.440225420985 / (fConst2 * fConst63)));
		fConst65 = (0.0 - (((40800.440225420985 / fConst1) + 387.00480017763186) / (fConst1 * fConst63)));
		fConst66 = ((((12820.038419162405 / fConst1) + 140.55894182530508) / fConst1) + 1.0);
		fConst67 = (1.0 / (fConst63 * fConst66));
		fConst68 = (0.0 - (51280.153676649621 / (fConst2 * fConst66)));
		fConst69 = (0.0 - (((51280.153676649621 / fConst1) + 281.11788365061017) / (fConst1 * fConst66)));
		fConst70 = ((77.575235573970943 / fConst1) + 1.0);
		fConst71 = (0.0 - (155.15047114794189 / (fConst1 * fConst70)));
		fConst72 = ((((7208.5318214897106 / fConst1) + 122.8615695745017) / fConst1) + 1.0);
		fConst73 = (1.0 / (fConst70 * fConst72));
		fConst74 = (0.0 - (28834.127285958843 / (fConst2 * fConst72)));
		fConst75 = (0.0 - (((28834.127285958843 / fConst1) + 245.7231391490034) / (fConst1 * fConst72)));
		fConst76 = ((33.406134191412107 / fConst1) + 1.0);
		fConst77 = (1.0 / fConst76);
		fConst78 = (0.0 - (66.812268382824215 / (fConst1 * fConst76)));
		fConst79 = ((((3347.9094048438992 / fConst1) + 100.21840257423632) / fConst1) + 1.0);
		fConst80 = (1.0 / fConst79);
		fConst81 = (0.0 - (13391.637619375597 / (fConst2 * fConst79)));
		fConst82 = (0.0 - (((13391.637619375597 / fConst1) + 200.43680514847264) / (fConst1 * fConst79)));
		iConst83 = int(((0.00059146664094131783 * double(iConst0)) + 0.5));
		fConst84 = ((33.425654721714835 / fConst1) + 1.0);
		fConst85 = (1.0 / fConst84);
		fConst86 = (0.0 - (66.85130944342967 / (fConst1 * fConst84)));
		fConst87 = ((((21006.021777992148 / fConst1) + 284.00838859976261) / fConst1) + 1.0);
		fConst88 = (0.0 - (84024.087111968591 / (fConst2 * fConst87)));
		fConst89 = (0.0 - (((84024.087111968591 / fConst1) + 568.01677719952522) / (fConst1 * fConst87)));
		fConst90 = ((((23298.325369858867 / fConst1) + 249.73699531914485) / fConst1) + 1.0);
		fConst91 = (0.0 - (93193.301479435468 / (fConst2 * fConst90)));
		fConst92 = (0.0 - (((93193.301479435468 / fConst1) + 499.47399063828971) / (fConst1 * fConst90)));
		fConst93 = ((((29623.441587533631 / fConst1) + 168.19336523710479) / fConst1) + 1.0);
		fConst94 = (1.0 / ((fConst87 * fConst90) * fConst93));
		fConst95 = (0.0 - (118493.76635013452 / (fConst2 * fConst93)));
		fConst96 = (0.0 - (((118493.76635013452 / fConst1) + 336.38673047420957) / (fConst1 * fConst93)));
		fConst97 = ((121.89462514784252 / fConst1) + 1.0);
		fConst98 = (0.0 - (243.78925029568504 / (fConst1 * fConst97)));
		fConst99 = ((((15946.277010289676 / fConst1) + 224.08267448069375) / fConst1) + 1.0);
		fConst100 = (0.0 - (63785.108041158703 / (fConst2 * fConst99)));
		fConst101 = (0.0 - (((63785.108041158703 / fConst1) + 448.16534896138751) / (fConst1 * fConst99)));
		fConst102 = ((((20285.586181399329 / fConst1) + 155.40752119718587) / fConst1) + 1.0);
		fConst103 = (1.0 / ((fConst97 * fConst99) * fConst102));
		fConst104 = (0.0 - (81142.344725597315 / (fConst2 * fConst102)));
		fConst105 = (0.0 - (((81142.344725597315 / fConst1) + 310.81504239437174) / (fConst1 * fConst102)));
		fConst106 = ((((10212.034197634121 / fConst1) + 193.6154712224868) / fConst1) + 1.0);
		fConst107 = (0.0 - (40848.136790536482 / (fConst2 * fConst106)));
		fConst108 = (0.0 - (((40848.136790536482 / fConst1) + 387.23094244497361) / (fConst1 * fConst106)));
		fConst109 = ((((12835.025311310244 / fConst1) + 140.64107599466149) / fConst1) + 1.0);
		fConst110 = (1.0 / (fConst106 * fConst109));
		fConst111 = (0.0 - (51340.101245240978 / (fConst2 * fConst109)));
		fConst112 = (0.0 - (((51340.101245240978 / fConst1) + 281.28215198932298) / (fConst1 * fConst109)));
		fConst113 = ((((3351.8231807258917 / fConst1) + 100.27696416514451) / fConst1) + 1.0);
		fConst114 = (1.0 / fConst113);
		fConst115 = (0.0 - (13407.292722903567 / (fConst2 * fConst113)));
		fConst116 = (0.0 - (((13407.292722903567 / fConst1) + 200.55392833028901) / (fConst1 * fConst113)));
		fConst117 = ((77.620565863554475 / fConst1) + 1.0);
		fConst118 = (0.0 - (155.24113172710895 / (fConst1 * fConst117)));
		fConst119 = ((((7216.9587454520797 / fConst1) + 122.93336246673454) / fConst1) + 1.0);
		fConst120 = (1.0 / (fConst117 * fConst119));
		fConst121 = (0.0 - (28867.834981808319 / (fConst2 * fConst119)));
		fConst122 = (0.0 - (((28867.834981808319 / fConst1) + 245.86672493346907) / (fConst1 * fConst119)));
		iConst123 = int(((0.00060020752726064536 * double(iConst0)) + 0.5));
		fConst124 = ((((20444.710454478012 / fConst1) + 280.18813740799027) / fConst1) + 1.0);
		fConst125 = (0.0 - (81778.841817912049 / (fConst2 * fConst124)));
		fConst126 = (0.0 - (((81778.841817912049 / fConst1) + 560.37627481598054) / (fConst1 * fConst124)));
		fConst127 = ((((22675.760374581194 / fConst1) + 246.37773519763451) / fConst1) + 1.0);
		fConst128 = (0.0 - (90703.041498324776 / (fConst2 * fConst127)));
		fConst129 = (0.0 - (((90703.041498324776 / fConst1) + 492.75547039526901) / (fConst1 * fConst127)));
		fConst130 = ((((28831.860326679984 / fConst1) + 165.9309640905642) / fConst1) + 1.0);
		fConst131 = (1.0 / ((fConst124 * fConst127) * fConst130));
		fConst132 = (0.0 - (115327.44130671993 / (fConst2 * fConst130)));
		fConst133 = (0.0 - (((115327.44130671993 / fConst1) + 331.86192818112841) / (fConst1 * fConst130)));
		fConst134 = ((120.25499721541576 / fConst1) + 1.0);
		fConst135 = (0.0 - (240.50999443083151 / (fConst1 * fConst134)));
		fConst136 = ((((15520.169394656026 / fConst1) + 221.0684955387936) / fConst1) + 1.0);
		fConst137 = (0.0 - (62080.677578624105 / (fConst2 * fConst136)));
		fConst138 = (0.0 - (((62080.677578624105 / fConst1) + 442.1369910775872) / (fConst1 * fConst136)));
		fConst139 = ((((19743.525940384494 / fConst1) + 153.31710488592475) / fConst1) + 1.0);
		fConst140 = (1.0 / ((fConst134 * fConst136) * fConst139));
		fConst141 = (0.0 - (78974.103761537976 / (fConst2 * fConst139)));
		fConst142 = (0.0 - (((78974.103761537976 / fConst1) + 306.6342097718495) / (fConst1 * fConst139)));
		fConst143 = ((((9939.1538544721825 / fConst1) + 191.01111246276852) / fConst1) + 1.0);
		fConst144 = (0.0 - (39756.61541788873 / (fConst2 * fConst143)));
		fConst145 = (0.0 - (((39756.61541788873 / fConst1) + 382.02222492553705) / (fConst1 * fConst143)));
		fConst146 = ((((12492.054846889559 / fConst1) + 138.74928596398775) / fConst1) + 1.0);
		fConst147 = (1.0 / (fConst143 * fConst146));
		fConst148 = (0.0 - (49968.219387558238 / (fConst2 * fConst146)));
		fConst149 = (0.0 - (((49968.219387558238 / fConst1) + 277.49857192797549) / (fConst1 * fConst146)));
		fConst150 = ((76.576476776227651 / fConst1) + 1.0);
		fConst151 = (0.0 - (153.1529535524553 / (fConst1 * fConst150)));
		fConst152 = ((((7024.111155938449 / fConst1) + 121.27976227982614) / fConst1) + 1.0);
		fConst153 = (1.0 / (fConst150 * fConst152));
		fConst154 = (0.0 - (28096.444623753796 / (fConst2 * fConst152)));
		fConst155 = (0.0 - (((28096.444623753796 / fConst1) + 242.55952455965229) / (fConst1 * fConst152)));
		fConst156 = ((32.976039842675632 / fConst1) + 1.0);
		fConst157 = (1.0 / fConst156);
		fConst158 = (0.0 - (65.952079685351265 / (fConst1 * fConst156)));
		fConst159 = ((((3262.257611117192 / fConst1) + 98.928119528026897) / fConst1) + 1.0);
		fConst160 = (1.0 / fConst159);
		fConst161 = (0.0 - (13049.030444468768 / (fConst2 * fConst159)));
		fConst162 = (0.0 - (((13049.030444468768 / fConst1) + 197.85623905605379) / (fConst1 * fConst159)));
		iConst163 = int(((0.00039625351314295164 * double(iConst0)) + 0.5));
		fConst164 = ((((19555.504396696881 / fConst1) + 274.02726312181574) / fConst1) + 1.0);
		fConst165 = (0.0 - (78222.017586787522 / (fConst2 * fConst164)));
		fConst166 = (0.0 - (((78222.017586787522 / fConst1) + 548.05452624363147) / (fConst1 * fConst164)));
		fConst167 = ((((21689.51879709509 / fConst1) + 240.96029580313663) / fConst1) + 1.0);
		fConst168 = (0.0 - (86758.07518838036 / (fConst2 * fConst167)));
		fConst169 = (0.0 - (((86758.07518838036 / fConst1) + 481.92059160627326) / (fConst1 * fConst167)));
		fConst170 = ((((27577.870209448072 / fConst1) + 162.28241629905961) / fConst1) + 1.0);
		fConst171 = (1.0 / ((fConst164 * fConst167) * fConst170));
		fConst172 = (0.0 - (110311.48083779229 / (fConst2 * fConst170)));
		fConst173 = (0.0 - (((110311.48083779229 / fConst1) + 324.56483259811921) / (fConst1 * fConst170)));
		fConst174 = ((117.61078848130494 / fConst1) + 1.0);
		fConst175 = (0.0 - (235.22157696260987 / (fConst1 * fConst174)));
		fConst176 = ((((14845.147428742359 / fConst1) + 216.20756451491863) / fConst1) + 1.0);
		fConst177 = (0.0 - (59380.589714969436 / (fConst2 * fConst176)));
		fConst178 = (0.0 - (((59380.589714969436 / fConst1) + 432.41512902983726) / (fConst1 * fConst176)));
		fConst179 = ((((18884.816646983691 / fConst1) + 149.94591502092698) / fConst1) + 1.0);
		fConst180 = (1.0 / ((fConst174 * fConst176) * fConst179));
		fConst181 = (0.0 - (75539.266587934762 / (fConst2 * fConst179)));
		fConst182 = (0.0 - (((75539.266587934762 / fConst1) + 299.89183004185395) / (fConst1 * fConst179)));
		fConst183 = ((((9506.8681619800409 / fConst1) + 186.81109363958794) / fConst1) + 1.0);
		fConst184 = (0.0 - (38027.472647920164 / (fConst2 * fConst183)));
		fConst185 = (0.0 - (((38027.472647920164 / fConst1) + 373.62218727917588) / (fConst1 * fConst183)));
		fConst186 = ((((11948.735298846983 / fConst1) + 135.69841837184595) / fConst1) + 1.0);
		fConst187 = (1.0 / (fConst183 * fConst186));
		fConst188 = (0.0 - (47794.941195387932 / (fConst2 * fConst186)));
		fConst189 = (0.0 - (((47794.941195387932 / fConst1) + 271.39683674369189) / (fConst1 * fConst186)));
		fConst190 = ((74.892686552055764 / fConst1) + 1.0);
		fConst191 = (0.0 - (149.78537310411153 / (fConst1 * fConst190)));
		fConst192 = ((((6718.6100237851942 / fConst1) + 118.6130206548046) / fConst1) + 1.0);
		fConst193 = (1.0 / (fConst190 * fConst192));
		fConst194 = (0.0 - (26874.440095140777 / (fConst2 * fConst192)));
		fConst195 = (0.0 - (((26874.440095140777 / fConst1) + 237.2260413096092) / (fConst1 * fConst192)));
		fConst196 = ((32.250951201143394 / fConst1) + 1.0);
		fConst197 = (1.0 / fConst196);
		fConst198 = (0.0 - (64.501902402286788 / (fConst1 * fConst196)));
		fConst199 = ((((3120.3715601355971 / fConst1) + 96.752853603430182) / fConst1) + 1.0);
		fConst200 = (1.0 / fConst199);
		fConst201 = (0.0 - (12481.486240542388 / (fConst2 * fConst199)));
		fConst202 = (0.0 - (((12481.486240542388 / fConst1) + 193.50570720686036) / (fConst1 * fConst199)));
		iConst203 = int(((5.5358946689089155e-05 * double(iConst0)) + 0.5));
		fConst204 = ((((27381.972321563702 / fConst1) + 161.70500695267717) / fConst1) + 1.0);
		fConst205 = (0.0 - (((109527.88928625481 / fConst1) + 323.41001390535433) / (fConst1 * fConst204)));
		fConst206 = (0.0 - (109527.88928625481 / (fConst2 * fConst204)));
		fConst207 = ((((19416.592944190514 / fConst1) + 273.05225975115758) / fConst1) + 1.0);
		fConst208 = ((((21535.448490385053 / fConst1) + 240.10294643604678) / fConst1) + 1.0);
		fConst209 = (1.0 / ((fConst207 * fConst208) * fConst204));
		fConst210 = (0.0 - (((86141.793961540214 / fConst1) + 480.20589287209356) / (fConst1 * fConst208)));
		fConst211 = (0.0 - (86141.793961540214 / (fConst2 * fConst208)));
		fConst212 = (0.0 - (((77666.371776762055 / fConst1) + 546.10451950231516) / (fConst1 * fConst207)));
		fConst213 = (0.0 - (77666.371776762055 / (fConst2 * fConst207)));
		fConst214 = ((117.19232312903063 / fConst1) + 1.0);
		fConst215 = (0.0 - (234.38464625806125 / (fConst1 * fConst214)));
		fConst216 = ((((14739.69573850899 / fConst1) + 215.43828666364828) / fConst1) + 1.0);
		fConst217 = (0.0 - (58958.78295403596 / (fConst2 * fConst216)));
		fConst218 = (0.0 - (((58958.78295403596 / fConst1) + 430.87657332729657) / (fConst1 * fConst216)));
		fConst219 = ((((18750.669388107974 / fConst1) + 149.41239959294987) / fConst1) + 1.0);
		fConst220 = (1.0 / ((fConst214 * fConst216) * fConst219));
		fConst221 = (0.0 - (75002.677552431895 / (fConst2 * fConst219)));
		fConst222 = (0.0 - (((75002.677552431895 / fConst1) + 298.82479918589974) / (fConst1 * fConst219)));
		fConst223 = ((((9439.3366456162785 / fConst1) + 186.14640997308004) / fConst1) + 1.0);
		fConst224 = (0.0 - (37757.346582465114 / (fConst2 * fConst223)));
		fConst225 = (0.0 - (((37757.346582465114 / fConst1) + 372.29281994616008) / (fConst1 * fConst223)));
		fConst226 = ((((11863.858113257369 / fConst1) + 135.21559628400601) / fConst1) + 1.0);
		fConst227 = (1.0 / (fConst223 * fConst226));
		fConst228 = (0.0 - (47455.432453029476 / (fConst2 * fConst226)));
		fConst229 = (0.0 - (((47455.432453029476 / fConst1) + 270.43119256801202) / (fConst1 * fConst226)));
		fConst230 = ((74.626214446346196 / fConst1) + 1.0);
		fConst231 = (0.0 - (149.25242889269239 / (fConst1 * fConst230)));
		fConst232 = ((((6670.8847461193591 / fConst1) + 118.19098930790547) / fConst1) + 1.0);
		fConst233 = (0.069540704100000003 / (fConst230 * fConst232));
		fConst234 = (0.0 - (26683.538984477436 / (fConst2 * fConst232)));
		fConst235 = (0.0 - (((26683.538984477436 / fConst1) + 236.38197861581094) / (fConst1 * fConst232)));
		fConst236 = ((32.136200625708611 / fConst1) + 1.0);
		fConst237 = (0.0011297084 / fConst236);
		fConst238 = (0.0 - (64.272401251417222 / (fConst1 * fConst236)));
		fConst239 = ((((3098.2061719673839 / fConst1) + 96.408601877125832) / fConst1) + 1.0);
		fConst240 = (0.039624385200000001 / fConst239);
		fConst241 = (0.0 - (12392.824687869535 / (fConst2 * fConst239)));
		fConst242 = (0.0 - (((12392.824687869535 / fConst1) + 192.81720375425166) / (fConst1 * fConst239)));
		fConst243 = ((36.668228919077777 / fConst1) + 1.0);
		fConst244 = (1.0 / fConst243);
		fConst245 = (0.0 - (73.336457838155553 / (fConst1 * fConst243)));
		fConst246 = ((((4033.6770361856752 / fConst1) + 110.00468675723333) / fConst1) + 1.0);
		fConst247 = (1.0 / fConst246);
		fConst248 = (0.0 - (16134.708144742701 / (fConst2 * fConst246)));
		fConst249 = (0.0 - (((16134.708144742701 / fConst1) + 220.00937351446666) / (fConst1 * fConst246)));
		fConst250 = ((85.150424175959131 / fConst1) + 1.0);
		fConst251 = (0.0 - (170.30084835191826 / (fConst1 * fConst250)));
		fConst252 = ((((8685.0884408302827 / fConst1) + 134.85894933850753) / fConst1) + 1.0);
		fConst253 = (1.0 / (fConst250 * fConst252));
		fConst254 = (0.0 - (34740.353763321131 / (fConst2 * fConst252)));
		fConst255 = (0.0 - (((34740.353763321131 / fConst1) + 269.71789867701506) / (fConst1 * fConst252)));
		fConst256 = ((((12289.445359948479 / fConst1) + 212.39782676415544) / fConst1) + 1.0);
		fConst257 = (0.0 - (49157.781439793915 / (fConst2 * fConst256)));
		fConst258 = (0.0 - (((49157.781439793915 / fConst1) + 424.79565352831088) / (fConst1 * fConst256)));
		fConst259 = ((((15446.025659946026 / fConst1) + 154.28446242662227) / fConst1) + 1.0);
		fConst260 = (1.0 / (fConst256 * fConst259));
		fConst261 = (0.0 - (61784.102639784105 / (fConst2 * fConst259)));
		fConst262 = (0.0 - (((61784.102639784105 / fConst1) + 308.56892485324454) / (fConst1 * fConst259)));
		fConst263 = ((133.71944562158623 / fConst1) + 1.0);
		fConst264 = (0.0 - (267.43889124317246 / (fConst1 * fConst263)));
		fConst265 = ((((19190.192298607777 / fConst1) + 245.82060914185513) / fConst1) + 1.0);
		fConst266 = (0.0 - (76760.769194431108 / (fConst2 * fConst265)));
		fConst267 = (0.0 - (((76760.769194431108 / fConst1) + 491.64121828371026) / (fConst1 * fConst265)));
		fConst268 = ((((24412.237380539653 / fConst1) + 170.48337902272488) / fConst1) + 1.0);
		fConst269 = (1.0 / ((fConst263 * fConst265) * fConst268));
		fConst270 = (0.0 - (97648.949522158611 / (fConst2 * fConst268)));
		fConst271 = (0.0 - (((97648.949522158611 / fConst1) + 340.96675804544975) / (fConst1 * fConst268)));
		fConst272 = ((((25279.229571159281 / fConst1) + 311.55962971606442) / fConst1) + 1.0);
		fConst273 = (0.0 - (101116.91828463713 / (fConst2 * fConst272)));
		fConst274 = (0.0 - (((101116.91828463713 / fConst1) + 623.11925943212884) / (fConst1 * fConst272)));
		fConst275 = ((((28037.851330101908 / fConst1) + 273.96361836933545) / fConst1) + 1.0);
		fConst276 = (0.0 - (112151.40532040763 / (fConst2 * fConst275)));
		fConst277 = (0.0 - (((112151.40532040763 / fConst1) + 547.9272367386709) / (fConst1 * fConst275)));
		fConst278 = ((((35649.671722404026 / fConst1) + 184.50955921523422) / fConst1) + 1.0);
		fConst279 = (1.0 / ((fConst272 * fConst275) * fConst278));
		fConst280 = (0.0 - (142598.6868896161 / (fConst2 * fConst278)));
		fConst281 = (0.0 - (((142598.6868896161 / fConst1) + 369.01911843046844) / (fConst1 * fConst278)));
		iConst282 = int(((0.001922994990252558 * double(iConst0)) + 0.5));
		fConst283 = ((36.746747610553314 / fConst1) + 1.0);
		fConst284 = (1.0 / fConst283);
		fConst285 = (0.0 - (73.493495221106627 / (fConst1 * fConst283)));
		fConst286 = ((((4050.9703798611172 / fConst1) + 110.24024283165994) / fConst1) + 1.0);
		fConst287 = (1.0 / fConst286);
		fConst288 = (0.0 - (16203.881519444469 / (fConst286 * fConst2)));
		fConst289 = (0.0 - (((16203.881519444469 / fConst1) + 220.48048566331988) / (fConst286 * fConst1)));
		fConst290 = ((85.332759131368022 / fConst1) + 1.0);
		fConst291 = (0.0 - (170.66551826273604 / (fConst1 * fConst290)));
		fConst292 = ((((8722.3235040025465 / fConst1) + 135.14772653195186) / fConst1) + 1.0);
		fConst293 = (1.0 / (fConst290 * fConst292));
		fConst294 = (0.0 - (34889.294016010186 / (fConst2 * fConst292)));
		fConst295 = (0.0 - (((34889.294016010186 / fConst1) + 270.29545306390372) / (fConst1 * fConst292)));
		fConst296 = ((((12342.133168189845 / fConst1) + 212.8526400976975) / fConst1) + 1.0);
		fConst297 = (0.0 - (49368.532672759378 / (fConst2 * fConst296)));
		fConst298 = (0.0 - (((49368.532672759378 / fConst1) + 425.70528019539501) / (fConst1 * fConst296)));
		fConst299 = ((((15512.246487186505 / fConst1) + 154.61483600783558) / fConst1) + 1.0);
		fConst300 = (1.0 / (fConst296 * fConst299));
		fConst301 = (0.0 - (62048.98594874602 / (fConst2 * fConst299)));
		fConst302 = (0.0 - (((62048.98594874602 / fConst1) + 309.22967201567116) / (fConst1 * fConst299)));
		fConst303 = ((134.00578276424486 / fConst1) + 1.0);
		fConst304 = (0.0 - (268.01156552848971 / (fConst303 * fConst1)));
		fConst305 = ((((19272.465268813507 / fConst1) + 246.34699160254428) / fConst1) + 1.0);
		fConst306 = (0.0 - (77089.861075254026 / (fConst305 * fConst2)));
		fConst307 = (0.0 - (((77089.861075254026 / fConst1) + 492.69398320508856) / (fConst305 * fConst1)));
		fConst308 = ((((24516.898514071392 / fConst1) + 170.84843979151012) / fConst1) + 1.0);
		fConst309 = (1.0 / ((fConst303 * fConst305) * fConst308));
		fConst310 = (0.0 - (98067.594056285569 / (fConst308 * fConst2)));
		fConst311 = (0.0 - (((98067.594056285569 / fConst1) + 341.69687958302023) / (fConst308 * fConst1)));
		fConst312 = ((((25387.607708750049 / fConst1) + 312.2267809574264) / fConst1) + 1.0);
		fConst313 = (0.0 - (101550.4308350002 / (fConst2 * fConst312)));
		fConst314 = (0.0 - (((101550.4308350002 / fConst1) + 624.4535619148528) / (fConst1 * fConst312)));
		fConst315 = ((((28158.056342705222 / fConst1) + 274.55026423308135) / fConst1) + 1.0);
		fConst316 = (0.0 - (112632.22537082089 / (fConst2 * fConst315)));
		fConst317 = (0.0 - (((112632.22537082089 / fConst1) + 549.1005284661627) / (fConst1 * fConst315)));
		fConst318 = ((((35802.510439902137 / fConst1) + 184.90465463111263) / fConst1) + 1.0);
		fConst319 = (1.0 / ((fConst312 * fConst315) * fConst318));
		fConst320 = (0.0 - (143210.04175960855 / (fConst2 * fConst318)));
		fConst321 = (0.0 - (((143210.04175960855 / fConst1) + 369.80930926222527) / (fConst1 * fConst318)));
		iConst322 = int(((0.0019521312779836569 * double(iConst0)) + 0.5));
		
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
			fRec20[l1] = 0.0;
			
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec19[l2] = 0.0;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec21[l3] = 0.0;
			
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec22[l4] = 0.0;
			
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec23[l5] = 0.0;
			
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec24[l6] = 0.0;
			
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec25[l7] = 0.0;
			
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec26[l8] = 0.0;
			
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec27[l9] = 0.0;
			
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec28[l10] = 0.0;
			
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec29[l11] = 0.0;
			
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec30[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec31[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec32[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec33[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec18[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec16[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec15[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec13[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec12[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec10[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec9[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec7[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec6[l24] = 0.0;
			
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec4[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec3[l26] = 0.0;
			
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec1[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 3); l28 = (l28 + 1)) {
			fRec49[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 3); l29 = (l29 + 1)) {
			fRec50[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) {
			fRec51[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) {
			fRec52[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 3); l32 = (l32 + 1)) {
			fRec53[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 3); l33 = (l33 + 1)) {
			fRec54[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec55[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 3); l35 = (l35 + 1)) {
			fRec56[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 3); l36 = (l36 + 1)) {
			fRec57[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 3); l37 = (l37 + 1)) {
			fRec58[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec59[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec48[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec46[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec45[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec43[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec42[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec40[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec39[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec37[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec36[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec34[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 3); l49 = (l49 + 1)) {
			fRec72[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 3); l50 = (l50 + 1)) {
			fRec73[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 3); l51 = (l51 + 1)) {
			fRec74[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 3); l52 = (l52 + 1)) {
			fRec75[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 3); l53 = (l53 + 1)) {
			fRec76[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) {
			fRec77[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec78[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec79[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 3); l57 = (l57 + 1)) {
			fRec80[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec71[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec69[l59] = 0.0;
			
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			fRec68[l60] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec66[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec65[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec63[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec62[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec60[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 3); l66 = (l66 + 1)) {
			fRec90[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 3); l67 = (l67 + 1)) {
			fRec91[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 3); l68 = (l68 + 1)) {
			fRec92[l68] = 0.0;
			
		}
		for (int l69 = 0; (l69 < 3); l69 = (l69 + 1)) {
			fRec93[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 3); l70 = (l70 + 1)) {
			fRec94[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 3); l71 = (l71 + 1)) {
			fRec95[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 3); l72 = (l72 + 1)) {
			fRec96[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec89[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec87[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 2); l75 = (l75 + 1)) {
			fRec86[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec84[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec83[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec81[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 3); l79 = (l79 + 1)) {
			fRec100[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 3); l80 = (l80 + 1)) {
			fRec101[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 3); l81 = (l81 + 1)) {
			fRec102[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec99[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fRec97[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 3); l84 = (l84 + 1)) {
			fRec109[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 3); l85 = (l85 + 1)) {
			fRec110[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 3); l86 = (l86 + 1)) {
			fRec111[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 3); l87 = (l87 + 1)) {
			fRec112[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 3); l88 = (l88 + 1)) {
			fRec113[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec108[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec106[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec105[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec103[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 3); l93 = (l93 + 1)) {
			fRec114[l93] = 0.0;
			
		}
		IOTA = 0;
		for (int l94 = 0; (l94 < 128); l94 = (l94 + 1)) {
			fVec0[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec132[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fRec130[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec129[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec127[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec126[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 2); l100 = (l100 + 1)) {
			fRec124[l100] = 0.0;
			
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fRec123[l101] = 0.0;
			
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec121[l102] = 0.0;
			
		}
		for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) {
			fRec120[l103] = 0.0;
			
		}
		for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) {
			fRec118[l104] = 0.0;
			
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fRec117[l105] = 0.0;
			
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec115[l106] = 0.0;
			
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fRec147[l107] = 0.0;
			
		}
		for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) {
			fRec145[l108] = 0.0;
			
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec144[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec142[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec141[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec139[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec138[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec136[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec135[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec133[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec159[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec157[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec156[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec154[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec153[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec151[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec150[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec148[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fRec168[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec166[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec165[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec163[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec162[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec160[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 2); l131 = (l131 + 1)) {
			fRec171[l131] = 0.0;
			
		}
		for (int l132 = 0; (l132 < 2); l132 = (l132 + 1)) {
			fRec169[l132] = 0.0;
			
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec177[l133] = 0.0;
			
		}
		for (int l134 = 0; (l134 < 2); l134 = (l134 + 1)) {
			fRec175[l134] = 0.0;
			
		}
		for (int l135 = 0; (l135 < 2); l135 = (l135 + 1)) {
			fRec174[l135] = 0.0;
			
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec172[l136] = 0.0;
			
		}
		for (int l137 = 0; (l137 < 128); l137 = (l137 + 1)) {
			fVec1[l137] = 0.0;
			
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec183[l138] = 0.0;
			
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fRec181[l139] = 0.0;
			
		}
		for (int l140 = 0; (l140 < 2); l140 = (l140 + 1)) {
			fRec180[l140] = 0.0;
			
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fRec178[l141] = 0.0;
			
		}
		for (int l142 = 0; (l142 < 2); l142 = (l142 + 1)) {
			fRec186[l142] = 0.0;
			
		}
		for (int l143 = 0; (l143 < 2); l143 = (l143 + 1)) {
			fRec184[l143] = 0.0;
			
		}
		for (int l144 = 0; (l144 < 2); l144 = (l144 + 1)) {
			fRec195[l144] = 0.0;
			
		}
		for (int l145 = 0; (l145 < 2); l145 = (l145 + 1)) {
			fRec193[l145] = 0.0;
			
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fRec192[l146] = 0.0;
			
		}
		for (int l147 = 0; (l147 < 2); l147 = (l147 + 1)) {
			fRec190[l147] = 0.0;
			
		}
		for (int l148 = 0; (l148 < 2); l148 = (l148 + 1)) {
			fRec189[l148] = 0.0;
			
		}
		for (int l149 = 0; (l149 < 2); l149 = (l149 + 1)) {
			fRec187[l149] = 0.0;
			
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec213[l150] = 0.0;
			
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec211[l151] = 0.0;
			
		}
		for (int l152 = 0; (l152 < 2); l152 = (l152 + 1)) {
			fRec210[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec208[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec207[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec205[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec204[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec202[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec201[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec199[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec198[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec196[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 2); l162 = (l162 + 1)) {
			fRec225[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			fRec223[l163] = 0.0;
			
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			fRec222[l164] = 0.0;
			
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec220[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec219[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fRec217[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec216[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec214[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec240[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fRec238[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec237[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fRec235[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec234[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec232[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec231[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec229[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 2); l178 = (l178 + 1)) {
			fRec228[l178] = 0.0;
			
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec226[l179] = 0.0;
			
		}
		for (int l180 = 0; (l180 < 128); l180 = (l180 + 1)) {
			fVec2[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec243[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec241[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fRec261[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec259[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec258[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fRec256[l186] = 0.0;
			
		}
		for (int l187 = 0; (l187 < 2); l187 = (l187 + 1)) {
			fRec255[l187] = 0.0;
			
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec253[l188] = 0.0;
			
		}
		for (int l189 = 0; (l189 < 2); l189 = (l189 + 1)) {
			fRec252[l189] = 0.0;
			
		}
		for (int l190 = 0; (l190 < 2); l190 = (l190 + 1)) {
			fRec250[l190] = 0.0;
			
		}
		for (int l191 = 0; (l191 < 2); l191 = (l191 + 1)) {
			fRec249[l191] = 0.0;
			
		}
		for (int l192 = 0; (l192 < 2); l192 = (l192 + 1)) {
			fRec247[l192] = 0.0;
			
		}
		for (int l193 = 0; (l193 < 2); l193 = (l193 + 1)) {
			fRec246[l193] = 0.0;
			
		}
		for (int l194 = 0; (l194 < 2); l194 = (l194 + 1)) {
			fRec244[l194] = 0.0;
			
		}
		for (int l195 = 0; (l195 < 2); l195 = (l195 + 1)) {
			fRec276[l195] = 0.0;
			
		}
		for (int l196 = 0; (l196 < 2); l196 = (l196 + 1)) {
			fRec274[l196] = 0.0;
			
		}
		for (int l197 = 0; (l197 < 2); l197 = (l197 + 1)) {
			fRec273[l197] = 0.0;
			
		}
		for (int l198 = 0; (l198 < 2); l198 = (l198 + 1)) {
			fRec271[l198] = 0.0;
			
		}
		for (int l199 = 0; (l199 < 2); l199 = (l199 + 1)) {
			fRec270[l199] = 0.0;
			
		}
		for (int l200 = 0; (l200 < 2); l200 = (l200 + 1)) {
			fRec268[l200] = 0.0;
			
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fRec267[l201] = 0.0;
			
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec265[l202] = 0.0;
			
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fRec264[l203] = 0.0;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec262[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec288[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec286[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec285[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec283[l208] = 0.0;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec282[l209] = 0.0;
			
		}
		for (int l210 = 0; (l210 < 2); l210 = (l210 + 1)) {
			fRec280[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 2); l211 = (l211 + 1)) {
			fRec279[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec277[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec294[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fRec292[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 2); l215 = (l215 + 1)) {
			fRec291[l215] = 0.0;
			
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fRec289[l216] = 0.0;
			
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec303[l217] = 0.0;
			
		}
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fRec301[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec300[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fRec298[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec297[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec295[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 128); l223 = (l223 + 1)) {
			fVec3[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 2); l224 = (l224 + 1)) {
			fRec321[l224] = 0.0;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec319[l225] = 0.0;
			
		}
		for (int l226 = 0; (l226 < 2); l226 = (l226 + 1)) {
			fRec318[l226] = 0.0;
			
		}
		for (int l227 = 0; (l227 < 2); l227 = (l227 + 1)) {
			fRec316[l227] = 0.0;
			
		}
		for (int l228 = 0; (l228 < 2); l228 = (l228 + 1)) {
			fRec315[l228] = 0.0;
			
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fRec313[l229] = 0.0;
			
		}
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec312[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fRec310[l231] = 0.0;
			
		}
		for (int l232 = 0; (l232 < 2); l232 = (l232 + 1)) {
			fRec309[l232] = 0.0;
			
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fRec307[l233] = 0.0;
			
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec306[l234] = 0.0;
			
		}
		for (int l235 = 0; (l235 < 2); l235 = (l235 + 1)) {
			fRec304[l235] = 0.0;
			
		}
		for (int l236 = 0; (l236 < 2); l236 = (l236 + 1)) {
			fRec336[l236] = 0.0;
			
		}
		for (int l237 = 0; (l237 < 2); l237 = (l237 + 1)) {
			fRec334[l237] = 0.0;
			
		}
		for (int l238 = 0; (l238 < 2); l238 = (l238 + 1)) {
			fRec333[l238] = 0.0;
			
		}
		for (int l239 = 0; (l239 < 2); l239 = (l239 + 1)) {
			fRec331[l239] = 0.0;
			
		}
		for (int l240 = 0; (l240 < 2); l240 = (l240 + 1)) {
			fRec330[l240] = 0.0;
			
		}
		for (int l241 = 0; (l241 < 2); l241 = (l241 + 1)) {
			fRec328[l241] = 0.0;
			
		}
		for (int l242 = 0; (l242 < 2); l242 = (l242 + 1)) {
			fRec327[l242] = 0.0;
			
		}
		for (int l243 = 0; (l243 < 2); l243 = (l243 + 1)) {
			fRec325[l243] = 0.0;
			
		}
		for (int l244 = 0; (l244 < 2); l244 = (l244 + 1)) {
			fRec324[l244] = 0.0;
			
		}
		for (int l245 = 0; (l245 < 2); l245 = (l245 + 1)) {
			fRec322[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fRec348[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 2); l247 = (l247 + 1)) {
			fRec346[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 2); l248 = (l248 + 1)) {
			fRec345[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fRec343[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 2); l250 = (l250 + 1)) {
			fRec342[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 2); l251 = (l251 + 1)) {
			fRec340[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 2); l252 = (l252 + 1)) {
			fRec339[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec337[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec357[l254] = 0.0;
			
		}
		for (int l255 = 0; (l255 < 2); l255 = (l255 + 1)) {
			fRec355[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec354[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fRec352[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec351[l258] = 0.0;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec349[l259] = 0.0;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec360[l260] = 0.0;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec358[l261] = 0.0;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec366[l262] = 0.0;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec364[l263] = 0.0;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec363[l264] = 0.0;
			
		}
		for (int l265 = 0; (l265 < 2); l265 = (l265 + 1)) {
			fRec361[l265] = 0.0;
			
		}
		for (int l266 = 0; (l266 < 128); l266 = (l266 + 1)) {
			fVec4[l266] = 0.0;
			
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec384[l267] = 0.0;
			
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec382[l268] = 0.0;
			
		}
		for (int l269 = 0; (l269 < 2); l269 = (l269 + 1)) {
			fRec381[l269] = 0.0;
			
		}
		for (int l270 = 0; (l270 < 2); l270 = (l270 + 1)) {
			fRec379[l270] = 0.0;
			
		}
		for (int l271 = 0; (l271 < 2); l271 = (l271 + 1)) {
			fRec378[l271] = 0.0;
			
		}
		for (int l272 = 0; (l272 < 2); l272 = (l272 + 1)) {
			fRec376[l272] = 0.0;
			
		}
		for (int l273 = 0; (l273 < 2); l273 = (l273 + 1)) {
			fRec375[l273] = 0.0;
			
		}
		for (int l274 = 0; (l274 < 2); l274 = (l274 + 1)) {
			fRec373[l274] = 0.0;
			
		}
		for (int l275 = 0; (l275 < 2); l275 = (l275 + 1)) {
			fRec372[l275] = 0.0;
			
		}
		for (int l276 = 0; (l276 < 2); l276 = (l276 + 1)) {
			fRec370[l276] = 0.0;
			
		}
		for (int l277 = 0; (l277 < 2); l277 = (l277 + 1)) {
			fRec369[l277] = 0.0;
			
		}
		for (int l278 = 0; (l278 < 2); l278 = (l278 + 1)) {
			fRec367[l278] = 0.0;
			
		}
		for (int l279 = 0; (l279 < 2); l279 = (l279 + 1)) {
			fRec399[l279] = 0.0;
			
		}
		for (int l280 = 0; (l280 < 2); l280 = (l280 + 1)) {
			fRec397[l280] = 0.0;
			
		}
		for (int l281 = 0; (l281 < 2); l281 = (l281 + 1)) {
			fRec396[l281] = 0.0;
			
		}
		for (int l282 = 0; (l282 < 2); l282 = (l282 + 1)) {
			fRec394[l282] = 0.0;
			
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec393[l283] = 0.0;
			
		}
		for (int l284 = 0; (l284 < 2); l284 = (l284 + 1)) {
			fRec391[l284] = 0.0;
			
		}
		for (int l285 = 0; (l285 < 2); l285 = (l285 + 1)) {
			fRec390[l285] = 0.0;
			
		}
		for (int l286 = 0; (l286 < 2); l286 = (l286 + 1)) {
			fRec388[l286] = 0.0;
			
		}
		for (int l287 = 0; (l287 < 2); l287 = (l287 + 1)) {
			fRec387[l287] = 0.0;
			
		}
		for (int l288 = 0; (l288 < 2); l288 = (l288 + 1)) {
			fRec385[l288] = 0.0;
			
		}
		for (int l289 = 0; (l289 < 2); l289 = (l289 + 1)) {
			fRec411[l289] = 0.0;
			
		}
		for (int l290 = 0; (l290 < 2); l290 = (l290 + 1)) {
			fRec409[l290] = 0.0;
			
		}
		for (int l291 = 0; (l291 < 2); l291 = (l291 + 1)) {
			fRec408[l291] = 0.0;
			
		}
		for (int l292 = 0; (l292 < 2); l292 = (l292 + 1)) {
			fRec406[l292] = 0.0;
			
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec405[l293] = 0.0;
			
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec403[l294] = 0.0;
			
		}
		for (int l295 = 0; (l295 < 2); l295 = (l295 + 1)) {
			fRec402[l295] = 0.0;
			
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec400[l296] = 0.0;
			
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec420[l297] = 0.0;
			
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec418[l298] = 0.0;
			
		}
		for (int l299 = 0; (l299 < 2); l299 = (l299 + 1)) {
			fRec417[l299] = 0.0;
			
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec415[l300] = 0.0;
			
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec414[l301] = 0.0;
			
		}
		for (int l302 = 0; (l302 < 2); l302 = (l302 + 1)) {
			fRec412[l302] = 0.0;
			
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec423[l303] = 0.0;
			
		}
		for (int l304 = 0; (l304 < 2); l304 = (l304 + 1)) {
			fRec421[l304] = 0.0;
			
		}
		for (int l305 = 0; (l305 < 2); l305 = (l305 + 1)) {
			fRec429[l305] = 0.0;
			
		}
		for (int l306 = 0; (l306 < 2); l306 = (l306 + 1)) {
			fRec427[l306] = 0.0;
			
		}
		for (int l307 = 0; (l307 < 2); l307 = (l307 + 1)) {
			fRec426[l307] = 0.0;
			
		}
		for (int l308 = 0; (l308 < 2); l308 = (l308 + 1)) {
			fRec424[l308] = 0.0;
			
		}
		for (int l309 = 0; (l309 < 128); l309 = (l309 + 1)) {
			fVec5[l309] = 0.0;
			
		}
		for (int l310 = 0; (l310 < 2); l310 = (l310 + 1)) {
			fRec447[l310] = 0.0;
			
		}
		for (int l311 = 0; (l311 < 2); l311 = (l311 + 1)) {
			fRec445[l311] = 0.0;
			
		}
		for (int l312 = 0; (l312 < 2); l312 = (l312 + 1)) {
			fRec444[l312] = 0.0;
			
		}
		for (int l313 = 0; (l313 < 2); l313 = (l313 + 1)) {
			fRec442[l313] = 0.0;
			
		}
		for (int l314 = 0; (l314 < 2); l314 = (l314 + 1)) {
			fRec441[l314] = 0.0;
			
		}
		for (int l315 = 0; (l315 < 2); l315 = (l315 + 1)) {
			fRec439[l315] = 0.0;
			
		}
		for (int l316 = 0; (l316 < 2); l316 = (l316 + 1)) {
			fRec438[l316] = 0.0;
			
		}
		for (int l317 = 0; (l317 < 2); l317 = (l317 + 1)) {
			fRec436[l317] = 0.0;
			
		}
		for (int l318 = 0; (l318 < 2); l318 = (l318 + 1)) {
			fRec435[l318] = 0.0;
			
		}
		for (int l319 = 0; (l319 < 2); l319 = (l319 + 1)) {
			fRec433[l319] = 0.0;
			
		}
		for (int l320 = 0; (l320 < 2); l320 = (l320 + 1)) {
			fRec432[l320] = 0.0;
			
		}
		for (int l321 = 0; (l321 < 2); l321 = (l321 + 1)) {
			fRec430[l321] = 0.0;
			
		}
		for (int l322 = 0; (l322 < 2); l322 = (l322 + 1)) {
			fRec462[l322] = 0.0;
			
		}
		for (int l323 = 0; (l323 < 2); l323 = (l323 + 1)) {
			fRec460[l323] = 0.0;
			
		}
		for (int l324 = 0; (l324 < 2); l324 = (l324 + 1)) {
			fRec459[l324] = 0.0;
			
		}
		for (int l325 = 0; (l325 < 2); l325 = (l325 + 1)) {
			fRec457[l325] = 0.0;
			
		}
		for (int l326 = 0; (l326 < 2); l326 = (l326 + 1)) {
			fRec456[l326] = 0.0;
			
		}
		for (int l327 = 0; (l327 < 2); l327 = (l327 + 1)) {
			fRec454[l327] = 0.0;
			
		}
		for (int l328 = 0; (l328 < 2); l328 = (l328 + 1)) {
			fRec453[l328] = 0.0;
			
		}
		for (int l329 = 0; (l329 < 2); l329 = (l329 + 1)) {
			fRec451[l329] = 0.0;
			
		}
		for (int l330 = 0; (l330 < 2); l330 = (l330 + 1)) {
			fRec450[l330] = 0.0;
			
		}
		for (int l331 = 0; (l331 < 2); l331 = (l331 + 1)) {
			fRec448[l331] = 0.0;
			
		}
		for (int l332 = 0; (l332 < 2); l332 = (l332 + 1)) {
			fRec474[l332] = 0.0;
			
		}
		for (int l333 = 0; (l333 < 2); l333 = (l333 + 1)) {
			fRec472[l333] = 0.0;
			
		}
		for (int l334 = 0; (l334 < 2); l334 = (l334 + 1)) {
			fRec471[l334] = 0.0;
			
		}
		for (int l335 = 0; (l335 < 2); l335 = (l335 + 1)) {
			fRec469[l335] = 0.0;
			
		}
		for (int l336 = 0; (l336 < 2); l336 = (l336 + 1)) {
			fRec468[l336] = 0.0;
			
		}
		for (int l337 = 0; (l337 < 2); l337 = (l337 + 1)) {
			fRec466[l337] = 0.0;
			
		}
		for (int l338 = 0; (l338 < 2); l338 = (l338 + 1)) {
			fRec465[l338] = 0.0;
			
		}
		for (int l339 = 0; (l339 < 2); l339 = (l339 + 1)) {
			fRec463[l339] = 0.0;
			
		}
		for (int l340 = 0; (l340 < 2); l340 = (l340 + 1)) {
			fRec483[l340] = 0.0;
			
		}
		for (int l341 = 0; (l341 < 2); l341 = (l341 + 1)) {
			fRec481[l341] = 0.0;
			
		}
		for (int l342 = 0; (l342 < 2); l342 = (l342 + 1)) {
			fRec480[l342] = 0.0;
			
		}
		for (int l343 = 0; (l343 < 2); l343 = (l343 + 1)) {
			fRec478[l343] = 0.0;
			
		}
		for (int l344 = 0; (l344 < 2); l344 = (l344 + 1)) {
			fRec477[l344] = 0.0;
			
		}
		for (int l345 = 0; (l345 < 2); l345 = (l345 + 1)) {
			fRec475[l345] = 0.0;
			
		}
		for (int l346 = 0; (l346 < 2); l346 = (l346 + 1)) {
			fRec486[l346] = 0.0;
			
		}
		for (int l347 = 0; (l347 < 2); l347 = (l347 + 1)) {
			fRec484[l347] = 0.0;
			
		}
		for (int l348 = 0; (l348 < 2); l348 = (l348 + 1)) {
			fRec492[l348] = 0.0;
			
		}
		for (int l349 = 0; (l349 < 2); l349 = (l349 + 1)) {
			fRec490[l349] = 0.0;
			
		}
		for (int l350 = 0; (l350 < 2); l350 = (l350 + 1)) {
			fRec489[l350] = 0.0;
			
		}
		for (int l351 = 0; (l351 < 2); l351 = (l351 + 1)) {
			fRec487[l351] = 0.0;
			
		}
		for (int l352 = 0; (l352 < 128); l352 = (l352 + 1)) {
			fVec6[l352] = 0.0;
			
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec510[l353] = 0.0;
			
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec508[l354] = 0.0;
			
		}
		for (int l355 = 0; (l355 < 2); l355 = (l355 + 1)) {
			fRec507[l355] = 0.0;
			
		}
		for (int l356 = 0; (l356 < 2); l356 = (l356 + 1)) {
			fRec505[l356] = 0.0;
			
		}
		for (int l357 = 0; (l357 < 2); l357 = (l357 + 1)) {
			fRec504[l357] = 0.0;
			
		}
		for (int l358 = 0; (l358 < 2); l358 = (l358 + 1)) {
			fRec502[l358] = 0.0;
			
		}
		for (int l359 = 0; (l359 < 2); l359 = (l359 + 1)) {
			fRec501[l359] = 0.0;
			
		}
		for (int l360 = 0; (l360 < 2); l360 = (l360 + 1)) {
			fRec499[l360] = 0.0;
			
		}
		for (int l361 = 0; (l361 < 2); l361 = (l361 + 1)) {
			fRec498[l361] = 0.0;
			
		}
		for (int l362 = 0; (l362 < 2); l362 = (l362 + 1)) {
			fRec496[l362] = 0.0;
			
		}
		for (int l363 = 0; (l363 < 2); l363 = (l363 + 1)) {
			fRec495[l363] = 0.0;
			
		}
		for (int l364 = 0; (l364 < 2); l364 = (l364 + 1)) {
			fRec493[l364] = 0.0;
			
		}
		for (int l365 = 0; (l365 < 2); l365 = (l365 + 1)) {
			fRec525[l365] = 0.0;
			
		}
		for (int l366 = 0; (l366 < 2); l366 = (l366 + 1)) {
			fRec523[l366] = 0.0;
			
		}
		for (int l367 = 0; (l367 < 2); l367 = (l367 + 1)) {
			fRec522[l367] = 0.0;
			
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec520[l368] = 0.0;
			
		}
		for (int l369 = 0; (l369 < 2); l369 = (l369 + 1)) {
			fRec519[l369] = 0.0;
			
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec517[l370] = 0.0;
			
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			fRec516[l371] = 0.0;
			
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			fRec514[l372] = 0.0;
			
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fRec513[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec511[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 2); l375 = (l375 + 1)) {
			fRec537[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec535[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec534[l377] = 0.0;
			
		}
		for (int l378 = 0; (l378 < 2); l378 = (l378 + 1)) {
			fRec532[l378] = 0.0;
			
		}
		for (int l379 = 0; (l379 < 2); l379 = (l379 + 1)) {
			fRec531[l379] = 0.0;
			
		}
		for (int l380 = 0; (l380 < 2); l380 = (l380 + 1)) {
			fRec529[l380] = 0.0;
			
		}
		for (int l381 = 0; (l381 < 2); l381 = (l381 + 1)) {
			fRec528[l381] = 0.0;
			
		}
		for (int l382 = 0; (l382 < 2); l382 = (l382 + 1)) {
			fRec526[l382] = 0.0;
			
		}
		for (int l383 = 0; (l383 < 2); l383 = (l383 + 1)) {
			fRec546[l383] = 0.0;
			
		}
		for (int l384 = 0; (l384 < 2); l384 = (l384 + 1)) {
			fRec544[l384] = 0.0;
			
		}
		for (int l385 = 0; (l385 < 2); l385 = (l385 + 1)) {
			fRec543[l385] = 0.0;
			
		}
		for (int l386 = 0; (l386 < 2); l386 = (l386 + 1)) {
			fRec541[l386] = 0.0;
			
		}
		for (int l387 = 0; (l387 < 2); l387 = (l387 + 1)) {
			fRec540[l387] = 0.0;
			
		}
		for (int l388 = 0; (l388 < 2); l388 = (l388 + 1)) {
			fRec538[l388] = 0.0;
			
		}
		for (int l389 = 0; (l389 < 2); l389 = (l389 + 1)) {
			fRec549[l389] = 0.0;
			
		}
		for (int l390 = 0; (l390 < 2); l390 = (l390 + 1)) {
			fRec547[l390] = 0.0;
			
		}
		for (int l391 = 0; (l391 < 2); l391 = (l391 + 1)) {
			fRec555[l391] = 0.0;
			
		}
		for (int l392 = 0; (l392 < 2); l392 = (l392 + 1)) {
			fRec553[l392] = 0.0;
			
		}
		for (int l393 = 0; (l393 < 2); l393 = (l393 + 1)) {
			fRec552[l393] = 0.0;
			
		}
		for (int l394 = 0; (l394 < 2); l394 = (l394 + 1)) {
			fRec550[l394] = 0.0;
			
		}
		for (int l395 = 0; (l395 < 128); l395 = (l395 + 1)) {
			fVec7[l395] = 0.0;
			
		}
		for (int l396 = 0; (l396 < 2); l396 = (l396 + 1)) {
			fRec567[l396] = 0.0;
			
		}
		for (int l397 = 0; (l397 < 2); l397 = (l397 + 1)) {
			fRec565[l397] = 0.0;
			
		}
		for (int l398 = 0; (l398 < 2); l398 = (l398 + 1)) {
			fRec564[l398] = 0.0;
			
		}
		for (int l399 = 0; (l399 < 2); l399 = (l399 + 1)) {
			fRec562[l399] = 0.0;
			
		}
		for (int l400 = 0; (l400 < 2); l400 = (l400 + 1)) {
			fRec561[l400] = 0.0;
			
		}
		for (int l401 = 0; (l401 < 2); l401 = (l401 + 1)) {
			fRec559[l401] = 0.0;
			
		}
		for (int l402 = 0; (l402 < 2); l402 = (l402 + 1)) {
			fRec558[l402] = 0.0;
			
		}
		for (int l403 = 0; (l403 < 2); l403 = (l403 + 1)) {
			fRec556[l403] = 0.0;
			
		}
		for (int l404 = 0; (l404 < 2); l404 = (l404 + 1)) {
			fRec576[l404] = 0.0;
			
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec574[l405] = 0.0;
			
		}
		for (int l406 = 0; (l406 < 2); l406 = (l406 + 1)) {
			fRec573[l406] = 0.0;
			
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec571[l407] = 0.0;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec570[l408] = 0.0;
			
		}
		for (int l409 = 0; (l409 < 2); l409 = (l409 + 1)) {
			fRec568[l409] = 0.0;
			
		}
		for (int l410 = 0; (l410 < 2); l410 = (l410 + 1)) {
			fRec582[l410] = 0.0;
			
		}
		for (int l411 = 0; (l411 < 2); l411 = (l411 + 1)) {
			fRec580[l411] = 0.0;
			
		}
		for (int l412 = 0; (l412 < 2); l412 = (l412 + 1)) {
			fRec579[l412] = 0.0;
			
		}
		for (int l413 = 0; (l413 < 2); l413 = (l413 + 1)) {
			fRec577[l413] = 0.0;
			
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec585[l414] = 0.0;
			
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec583[l415] = 0.0;
			
		}
		for (int l416 = 0; (l416 < 2); l416 = (l416 + 1)) {
			fRec603[l416] = 0.0;
			
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec601[l417] = 0.0;
			
		}
		for (int l418 = 0; (l418 < 2); l418 = (l418 + 1)) {
			fRec600[l418] = 0.0;
			
		}
		for (int l419 = 0; (l419 < 2); l419 = (l419 + 1)) {
			fRec598[l419] = 0.0;
			
		}
		for (int l420 = 0; (l420 < 2); l420 = (l420 + 1)) {
			fRec597[l420] = 0.0;
			
		}
		for (int l421 = 0; (l421 < 2); l421 = (l421 + 1)) {
			fRec595[l421] = 0.0;
			
		}
		for (int l422 = 0; (l422 < 2); l422 = (l422 + 1)) {
			fRec594[l422] = 0.0;
			
		}
		for (int l423 = 0; (l423 < 2); l423 = (l423 + 1)) {
			fRec592[l423] = 0.0;
			
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec591[l424] = 0.0;
			
		}
		for (int l425 = 0; (l425 < 2); l425 = (l425 + 1)) {
			fRec589[l425] = 0.0;
			
		}
		for (int l426 = 0; (l426 < 2); l426 = (l426 + 1)) {
			fRec588[l426] = 0.0;
			
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec586[l427] = 0.0;
			
		}
		for (int l428 = 0; (l428 < 2); l428 = (l428 + 1)) {
			fRec618[l428] = 0.0;
			
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec616[l429] = 0.0;
			
		}
		for (int l430 = 0; (l430 < 2); l430 = (l430 + 1)) {
			fRec615[l430] = 0.0;
			
		}
		for (int l431 = 0; (l431 < 2); l431 = (l431 + 1)) {
			fRec613[l431] = 0.0;
			
		}
		for (int l432 = 0; (l432 < 2); l432 = (l432 + 1)) {
			fRec612[l432] = 0.0;
			
		}
		for (int l433 = 0; (l433 < 2); l433 = (l433 + 1)) {
			fRec610[l433] = 0.0;
			
		}
		for (int l434 = 0; (l434 < 2); l434 = (l434 + 1)) {
			fRec609[l434] = 0.0;
			
		}
		for (int l435 = 0; (l435 < 2); l435 = (l435 + 1)) {
			fRec607[l435] = 0.0;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec606[l436] = 0.0;
			
		}
		for (int l437 = 0; (l437 < 2); l437 = (l437 + 1)) {
			fRec604[l437] = 0.0;
			
		}
		for (int l438 = 0; (l438 < 128); l438 = (l438 + 1)) {
			fVec8[l438] = 0.0;
			
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec636[l439] = 0.0;
			
		}
		for (int l440 = 0; (l440 < 2); l440 = (l440 + 1)) {
			fRec634[l440] = 0.0;
			
		}
		for (int l441 = 0; (l441 < 2); l441 = (l441 + 1)) {
			fRec633[l441] = 0.0;
			
		}
		for (int l442 = 0; (l442 < 2); l442 = (l442 + 1)) {
			fRec631[l442] = 0.0;
			
		}
		for (int l443 = 0; (l443 < 2); l443 = (l443 + 1)) {
			fRec630[l443] = 0.0;
			
		}
		for (int l444 = 0; (l444 < 2); l444 = (l444 + 1)) {
			fRec628[l444] = 0.0;
			
		}
		for (int l445 = 0; (l445 < 2); l445 = (l445 + 1)) {
			fRec627[l445] = 0.0;
			
		}
		for (int l446 = 0; (l446 < 2); l446 = (l446 + 1)) {
			fRec625[l446] = 0.0;
			
		}
		for (int l447 = 0; (l447 < 2); l447 = (l447 + 1)) {
			fRec624[l447] = 0.0;
			
		}
		for (int l448 = 0; (l448 < 2); l448 = (l448 + 1)) {
			fRec622[l448] = 0.0;
			
		}
		for (int l449 = 0; (l449 < 2); l449 = (l449 + 1)) {
			fRec621[l449] = 0.0;
			
		}
		for (int l450 = 0; (l450 < 2); l450 = (l450 + 1)) {
			fRec619[l450] = 0.0;
			
		}
		for (int l451 = 0; (l451 < 2); l451 = (l451 + 1)) {
			fRec651[l451] = 0.0;
			
		}
		for (int l452 = 0; (l452 < 2); l452 = (l452 + 1)) {
			fRec649[l452] = 0.0;
			
		}
		for (int l453 = 0; (l453 < 2); l453 = (l453 + 1)) {
			fRec648[l453] = 0.0;
			
		}
		for (int l454 = 0; (l454 < 2); l454 = (l454 + 1)) {
			fRec646[l454] = 0.0;
			
		}
		for (int l455 = 0; (l455 < 2); l455 = (l455 + 1)) {
			fRec645[l455] = 0.0;
			
		}
		for (int l456 = 0; (l456 < 2); l456 = (l456 + 1)) {
			fRec643[l456] = 0.0;
			
		}
		for (int l457 = 0; (l457 < 2); l457 = (l457 + 1)) {
			fRec642[l457] = 0.0;
			
		}
		for (int l458 = 0; (l458 < 2); l458 = (l458 + 1)) {
			fRec640[l458] = 0.0;
			
		}
		for (int l459 = 0; (l459 < 2); l459 = (l459 + 1)) {
			fRec639[l459] = 0.0;
			
		}
		for (int l460 = 0; (l460 < 2); l460 = (l460 + 1)) {
			fRec637[l460] = 0.0;
			
		}
		for (int l461 = 0; (l461 < 2); l461 = (l461 + 1)) {
			fRec663[l461] = 0.0;
			
		}
		for (int l462 = 0; (l462 < 2); l462 = (l462 + 1)) {
			fRec661[l462] = 0.0;
			
		}
		for (int l463 = 0; (l463 < 2); l463 = (l463 + 1)) {
			fRec660[l463] = 0.0;
			
		}
		for (int l464 = 0; (l464 < 2); l464 = (l464 + 1)) {
			fRec658[l464] = 0.0;
			
		}
		for (int l465 = 0; (l465 < 2); l465 = (l465 + 1)) {
			fRec657[l465] = 0.0;
			
		}
		for (int l466 = 0; (l466 < 2); l466 = (l466 + 1)) {
			fRec655[l466] = 0.0;
			
		}
		for (int l467 = 0; (l467 < 2); l467 = (l467 + 1)) {
			fRec654[l467] = 0.0;
			
		}
		for (int l468 = 0; (l468 < 2); l468 = (l468 + 1)) {
			fRec652[l468] = 0.0;
			
		}
		for (int l469 = 0; (l469 < 2); l469 = (l469 + 1)) {
			fRec672[l469] = 0.0;
			
		}
		for (int l470 = 0; (l470 < 2); l470 = (l470 + 1)) {
			fRec670[l470] = 0.0;
			
		}
		for (int l471 = 0; (l471 < 2); l471 = (l471 + 1)) {
			fRec669[l471] = 0.0;
			
		}
		for (int l472 = 0; (l472 < 2); l472 = (l472 + 1)) {
			fRec667[l472] = 0.0;
			
		}
		for (int l473 = 0; (l473 < 2); l473 = (l473 + 1)) {
			fRec666[l473] = 0.0;
			
		}
		for (int l474 = 0; (l474 < 2); l474 = (l474 + 1)) {
			fRec664[l474] = 0.0;
			
		}
		for (int l475 = 0; (l475 < 2); l475 = (l475 + 1)) {
			fRec675[l475] = 0.0;
			
		}
		for (int l476 = 0; (l476 < 2); l476 = (l476 + 1)) {
			fRec673[l476] = 0.0;
			
		}
		for (int l477 = 0; (l477 < 2); l477 = (l477 + 1)) {
			fRec681[l477] = 0.0;
			
		}
		for (int l478 = 0; (l478 < 2); l478 = (l478 + 1)) {
			fRec679[l478] = 0.0;
			
		}
		for (int l479 = 0; (l479 < 2); l479 = (l479 + 1)) {
			fRec678[l479] = 0.0;
			
		}
		for (int l480 = 0; (l480 < 2); l480 = (l480 + 1)) {
			fRec676[l480] = 0.0;
			
		}
		for (int l481 = 0; (l481 < 128); l481 = (l481 + 1)) {
			fVec9[l481] = 0.0;
			
		}
		for (int l482 = 0; (l482 < 2); l482 = (l482 + 1)) {
			fRec699[l482] = 0.0;
			
		}
		for (int l483 = 0; (l483 < 2); l483 = (l483 + 1)) {
			fRec697[l483] = 0.0;
			
		}
		for (int l484 = 0; (l484 < 2); l484 = (l484 + 1)) {
			fRec696[l484] = 0.0;
			
		}
		for (int l485 = 0; (l485 < 2); l485 = (l485 + 1)) {
			fRec694[l485] = 0.0;
			
		}
		for (int l486 = 0; (l486 < 2); l486 = (l486 + 1)) {
			fRec693[l486] = 0.0;
			
		}
		for (int l487 = 0; (l487 < 2); l487 = (l487 + 1)) {
			fRec691[l487] = 0.0;
			
		}
		for (int l488 = 0; (l488 < 2); l488 = (l488 + 1)) {
			fRec690[l488] = 0.0;
			
		}
		for (int l489 = 0; (l489 < 2); l489 = (l489 + 1)) {
			fRec688[l489] = 0.0;
			
		}
		for (int l490 = 0; (l490 < 2); l490 = (l490 + 1)) {
			fRec687[l490] = 0.0;
			
		}
		for (int l491 = 0; (l491 < 2); l491 = (l491 + 1)) {
			fRec685[l491] = 0.0;
			
		}
		for (int l492 = 0; (l492 < 2); l492 = (l492 + 1)) {
			fRec684[l492] = 0.0;
			
		}
		for (int l493 = 0; (l493 < 2); l493 = (l493 + 1)) {
			fRec682[l493] = 0.0;
			
		}
		for (int l494 = 0; (l494 < 2); l494 = (l494 + 1)) {
			fRec714[l494] = 0.0;
			
		}
		for (int l495 = 0; (l495 < 2); l495 = (l495 + 1)) {
			fRec712[l495] = 0.0;
			
		}
		for (int l496 = 0; (l496 < 2); l496 = (l496 + 1)) {
			fRec711[l496] = 0.0;
			
		}
		for (int l497 = 0; (l497 < 2); l497 = (l497 + 1)) {
			fRec709[l497] = 0.0;
			
		}
		for (int l498 = 0; (l498 < 2); l498 = (l498 + 1)) {
			fRec708[l498] = 0.0;
			
		}
		for (int l499 = 0; (l499 < 2); l499 = (l499 + 1)) {
			fRec706[l499] = 0.0;
			
		}
		for (int l500 = 0; (l500 < 2); l500 = (l500 + 1)) {
			fRec705[l500] = 0.0;
			
		}
		for (int l501 = 0; (l501 < 2); l501 = (l501 + 1)) {
			fRec703[l501] = 0.0;
			
		}
		for (int l502 = 0; (l502 < 2); l502 = (l502 + 1)) {
			fRec702[l502] = 0.0;
			
		}
		for (int l503 = 0; (l503 < 2); l503 = (l503 + 1)) {
			fRec700[l503] = 0.0;
			
		}
		for (int l504 = 0; (l504 < 2); l504 = (l504 + 1)) {
			fRec726[l504] = 0.0;
			
		}
		for (int l505 = 0; (l505 < 2); l505 = (l505 + 1)) {
			fRec724[l505] = 0.0;
			
		}
		for (int l506 = 0; (l506 < 2); l506 = (l506 + 1)) {
			fRec723[l506] = 0.0;
			
		}
		for (int l507 = 0; (l507 < 2); l507 = (l507 + 1)) {
			fRec721[l507] = 0.0;
			
		}
		for (int l508 = 0; (l508 < 2); l508 = (l508 + 1)) {
			fRec720[l508] = 0.0;
			
		}
		for (int l509 = 0; (l509 < 2); l509 = (l509 + 1)) {
			fRec718[l509] = 0.0;
			
		}
		for (int l510 = 0; (l510 < 2); l510 = (l510 + 1)) {
			fRec717[l510] = 0.0;
			
		}
		for (int l511 = 0; (l511 < 2); l511 = (l511 + 1)) {
			fRec715[l511] = 0.0;
			
		}
		for (int l512 = 0; (l512 < 2); l512 = (l512 + 1)) {
			fRec735[l512] = 0.0;
			
		}
		for (int l513 = 0; (l513 < 2); l513 = (l513 + 1)) {
			fRec733[l513] = 0.0;
			
		}
		for (int l514 = 0; (l514 < 2); l514 = (l514 + 1)) {
			fRec732[l514] = 0.0;
			
		}
		for (int l515 = 0; (l515 < 2); l515 = (l515 + 1)) {
			fRec730[l515] = 0.0;
			
		}
		for (int l516 = 0; (l516 < 2); l516 = (l516 + 1)) {
			fRec729[l516] = 0.0;
			
		}
		for (int l517 = 0; (l517 < 2); l517 = (l517 + 1)) {
			fRec727[l517] = 0.0;
			
		}
		for (int l518 = 0; (l518 < 2); l518 = (l518 + 1)) {
			fRec738[l518] = 0.0;
			
		}
		for (int l519 = 0; (l519 < 2); l519 = (l519 + 1)) {
			fRec736[l519] = 0.0;
			
		}
		for (int l520 = 0; (l520 < 2); l520 = (l520 + 1)) {
			fRec744[l520] = 0.0;
			
		}
		for (int l521 = 0; (l521 < 2); l521 = (l521 + 1)) {
			fRec742[l521] = 0.0;
			
		}
		for (int l522 = 0; (l522 < 2); l522 = (l522 + 1)) {
			fRec741[l522] = 0.0;
			
		}
		for (int l523 = 0; (l523 < 2); l523 = (l523 + 1)) {
			fRec739[l523] = 0.0;
			
		}
		for (int l524 = 0; (l524 < 128); l524 = (l524 + 1)) {
			fVec10[l524] = 0.0;
			
		}
		for (int l525 = 0; (l525 < 2); l525 = (l525 + 1)) {
			fRec756[l525] = 0.0;
			
		}
		for (int l526 = 0; (l526 < 2); l526 = (l526 + 1)) {
			fRec754[l526] = 0.0;
			
		}
		for (int l527 = 0; (l527 < 2); l527 = (l527 + 1)) {
			fRec753[l527] = 0.0;
			
		}
		for (int l528 = 0; (l528 < 2); l528 = (l528 + 1)) {
			fRec751[l528] = 0.0;
			
		}
		for (int l529 = 0; (l529 < 2); l529 = (l529 + 1)) {
			fRec750[l529] = 0.0;
			
		}
		for (int l530 = 0; (l530 < 2); l530 = (l530 + 1)) {
			fRec748[l530] = 0.0;
			
		}
		for (int l531 = 0; (l531 < 2); l531 = (l531 + 1)) {
			fRec747[l531] = 0.0;
			
		}
		for (int l532 = 0; (l532 < 2); l532 = (l532 + 1)) {
			fRec745[l532] = 0.0;
			
		}
		for (int l533 = 0; (l533 < 2); l533 = (l533 + 1)) {
			fRec765[l533] = 0.0;
			
		}
		for (int l534 = 0; (l534 < 2); l534 = (l534 + 1)) {
			fRec763[l534] = 0.0;
			
		}
		for (int l535 = 0; (l535 < 2); l535 = (l535 + 1)) {
			fRec762[l535] = 0.0;
			
		}
		for (int l536 = 0; (l536 < 2); l536 = (l536 + 1)) {
			fRec760[l536] = 0.0;
			
		}
		for (int l537 = 0; (l537 < 2); l537 = (l537 + 1)) {
			fRec759[l537] = 0.0;
			
		}
		for (int l538 = 0; (l538 < 2); l538 = (l538 + 1)) {
			fRec757[l538] = 0.0;
			
		}
		for (int l539 = 0; (l539 < 2); l539 = (l539 + 1)) {
			fRec771[l539] = 0.0;
			
		}
		for (int l540 = 0; (l540 < 2); l540 = (l540 + 1)) {
			fRec769[l540] = 0.0;
			
		}
		for (int l541 = 0; (l541 < 2); l541 = (l541 + 1)) {
			fRec768[l541] = 0.0;
			
		}
		for (int l542 = 0; (l542 < 2); l542 = (l542 + 1)) {
			fRec766[l542] = 0.0;
			
		}
		for (int l543 = 0; (l543 < 2); l543 = (l543 + 1)) {
			fRec774[l543] = 0.0;
			
		}
		for (int l544 = 0; (l544 < 2); l544 = (l544 + 1)) {
			fRec772[l544] = 0.0;
			
		}
		for (int l545 = 0; (l545 < 2); l545 = (l545 + 1)) {
			fRec792[l545] = 0.0;
			
		}
		for (int l546 = 0; (l546 < 2); l546 = (l546 + 1)) {
			fRec790[l546] = 0.0;
			
		}
		for (int l547 = 0; (l547 < 2); l547 = (l547 + 1)) {
			fRec789[l547] = 0.0;
			
		}
		for (int l548 = 0; (l548 < 2); l548 = (l548 + 1)) {
			fRec787[l548] = 0.0;
			
		}
		for (int l549 = 0; (l549 < 2); l549 = (l549 + 1)) {
			fRec786[l549] = 0.0;
			
		}
		for (int l550 = 0; (l550 < 2); l550 = (l550 + 1)) {
			fRec784[l550] = 0.0;
			
		}
		for (int l551 = 0; (l551 < 2); l551 = (l551 + 1)) {
			fRec783[l551] = 0.0;
			
		}
		for (int l552 = 0; (l552 < 2); l552 = (l552 + 1)) {
			fRec781[l552] = 0.0;
			
		}
		for (int l553 = 0; (l553 < 2); l553 = (l553 + 1)) {
			fRec780[l553] = 0.0;
			
		}
		for (int l554 = 0; (l554 < 2); l554 = (l554 + 1)) {
			fRec778[l554] = 0.0;
			
		}
		for (int l555 = 0; (l555 < 2); l555 = (l555 + 1)) {
			fRec777[l555] = 0.0;
			
		}
		for (int l556 = 0; (l556 < 2); l556 = (l556 + 1)) {
			fRec775[l556] = 0.0;
			
		}
		for (int l557 = 0; (l557 < 2); l557 = (l557 + 1)) {
			fRec807[l557] = 0.0;
			
		}
		for (int l558 = 0; (l558 < 2); l558 = (l558 + 1)) {
			fRec805[l558] = 0.0;
			
		}
		for (int l559 = 0; (l559 < 2); l559 = (l559 + 1)) {
			fRec804[l559] = 0.0;
			
		}
		for (int l560 = 0; (l560 < 2); l560 = (l560 + 1)) {
			fRec802[l560] = 0.0;
			
		}
		for (int l561 = 0; (l561 < 2); l561 = (l561 + 1)) {
			fRec801[l561] = 0.0;
			
		}
		for (int l562 = 0; (l562 < 2); l562 = (l562 + 1)) {
			fRec799[l562] = 0.0;
			
		}
		for (int l563 = 0; (l563 < 2); l563 = (l563 + 1)) {
			fRec798[l563] = 0.0;
			
		}
		for (int l564 = 0; (l564 < 2); l564 = (l564 + 1)) {
			fRec796[l564] = 0.0;
			
		}
		for (int l565 = 0; (l565 < 2); l565 = (l565 + 1)) {
			fRec795[l565] = 0.0;
			
		}
		for (int l566 = 0; (l566 < 2); l566 = (l566 + 1)) {
			fRec793[l566] = 0.0;
			
		}
		for (int l567 = 0; (l567 < 128); l567 = (l567 + 1)) {
			fVec11[l567] = 0.0;
			
		}
		for (int l568 = 0; (l568 < 2); l568 = (l568 + 1)) {
			fRec825[l568] = 0.0;
			
		}
		for (int l569 = 0; (l569 < 2); l569 = (l569 + 1)) {
			fRec823[l569] = 0.0;
			
		}
		for (int l570 = 0; (l570 < 2); l570 = (l570 + 1)) {
			fRec822[l570] = 0.0;
			
		}
		for (int l571 = 0; (l571 < 2); l571 = (l571 + 1)) {
			fRec820[l571] = 0.0;
			
		}
		for (int l572 = 0; (l572 < 2); l572 = (l572 + 1)) {
			fRec819[l572] = 0.0;
			
		}
		for (int l573 = 0; (l573 < 2); l573 = (l573 + 1)) {
			fRec817[l573] = 0.0;
			
		}
		for (int l574 = 0; (l574 < 2); l574 = (l574 + 1)) {
			fRec816[l574] = 0.0;
			
		}
		for (int l575 = 0; (l575 < 2); l575 = (l575 + 1)) {
			fRec814[l575] = 0.0;
			
		}
		for (int l576 = 0; (l576 < 2); l576 = (l576 + 1)) {
			fRec813[l576] = 0.0;
			
		}
		for (int l577 = 0; (l577 < 2); l577 = (l577 + 1)) {
			fRec811[l577] = 0.0;
			
		}
		for (int l578 = 0; (l578 < 2); l578 = (l578 + 1)) {
			fRec810[l578] = 0.0;
			
		}
		for (int l579 = 0; (l579 < 2); l579 = (l579 + 1)) {
			fRec808[l579] = 0.0;
			
		}
		for (int l580 = 0; (l580 < 2); l580 = (l580 + 1)) {
			fRec840[l580] = 0.0;
			
		}
		for (int l581 = 0; (l581 < 2); l581 = (l581 + 1)) {
			fRec838[l581] = 0.0;
			
		}
		for (int l582 = 0; (l582 < 2); l582 = (l582 + 1)) {
			fRec837[l582] = 0.0;
			
		}
		for (int l583 = 0; (l583 < 2); l583 = (l583 + 1)) {
			fRec835[l583] = 0.0;
			
		}
		for (int l584 = 0; (l584 < 2); l584 = (l584 + 1)) {
			fRec834[l584] = 0.0;
			
		}
		for (int l585 = 0; (l585 < 2); l585 = (l585 + 1)) {
			fRec832[l585] = 0.0;
			
		}
		for (int l586 = 0; (l586 < 2); l586 = (l586 + 1)) {
			fRec831[l586] = 0.0;
			
		}
		for (int l587 = 0; (l587 < 2); l587 = (l587 + 1)) {
			fRec829[l587] = 0.0;
			
		}
		for (int l588 = 0; (l588 < 2); l588 = (l588 + 1)) {
			fRec828[l588] = 0.0;
			
		}
		for (int l589 = 0; (l589 < 2); l589 = (l589 + 1)) {
			fRec826[l589] = 0.0;
			
		}
		for (int l590 = 0; (l590 < 2); l590 = (l590 + 1)) {
			fRec852[l590] = 0.0;
			
		}
		for (int l591 = 0; (l591 < 2); l591 = (l591 + 1)) {
			fRec850[l591] = 0.0;
			
		}
		for (int l592 = 0; (l592 < 2); l592 = (l592 + 1)) {
			fRec849[l592] = 0.0;
			
		}
		for (int l593 = 0; (l593 < 2); l593 = (l593 + 1)) {
			fRec847[l593] = 0.0;
			
		}
		for (int l594 = 0; (l594 < 2); l594 = (l594 + 1)) {
			fRec846[l594] = 0.0;
			
		}
		for (int l595 = 0; (l595 < 2); l595 = (l595 + 1)) {
			fRec844[l595] = 0.0;
			
		}
		for (int l596 = 0; (l596 < 2); l596 = (l596 + 1)) {
			fRec843[l596] = 0.0;
			
		}
		for (int l597 = 0; (l597 < 2); l597 = (l597 + 1)) {
			fRec841[l597] = 0.0;
			
		}
		for (int l598 = 0; (l598 < 2); l598 = (l598 + 1)) {
			fRec861[l598] = 0.0;
			
		}
		for (int l599 = 0; (l599 < 2); l599 = (l599 + 1)) {
			fRec859[l599] = 0.0;
			
		}
		for (int l600 = 0; (l600 < 2); l600 = (l600 + 1)) {
			fRec858[l600] = 0.0;
			
		}
		for (int l601 = 0; (l601 < 2); l601 = (l601 + 1)) {
			fRec856[l601] = 0.0;
			
		}
		for (int l602 = 0; (l602 < 2); l602 = (l602 + 1)) {
			fRec855[l602] = 0.0;
			
		}
		for (int l603 = 0; (l603 < 2); l603 = (l603 + 1)) {
			fRec853[l603] = 0.0;
			
		}
		for (int l604 = 0; (l604 < 2); l604 = (l604 + 1)) {
			fRec864[l604] = 0.0;
			
		}
		for (int l605 = 0; (l605 < 2); l605 = (l605 + 1)) {
			fRec862[l605] = 0.0;
			
		}
		for (int l606 = 0; (l606 < 2); l606 = (l606 + 1)) {
			fRec870[l606] = 0.0;
			
		}
		for (int l607 = 0; (l607 < 2); l607 = (l607 + 1)) {
			fRec868[l607] = 0.0;
			
		}
		for (int l608 = 0; (l608 < 2); l608 = (l608 + 1)) {
			fRec867[l608] = 0.0;
			
		}
		for (int l609 = 0; (l609 < 2); l609 = (l609 + 1)) {
			fRec865[l609] = 0.0;
			
		}
		for (int l610 = 0; (l610 < 128); l610 = (l610 + 1)) {
			fVec12[l610] = 0.0;
			
		}
		for (int l611 = 0; (l611 < 2); l611 = (l611 + 1)) {
			fRec888[l611] = 0.0;
			
		}
		for (int l612 = 0; (l612 < 2); l612 = (l612 + 1)) {
			fRec886[l612] = 0.0;
			
		}
		for (int l613 = 0; (l613 < 2); l613 = (l613 + 1)) {
			fRec885[l613] = 0.0;
			
		}
		for (int l614 = 0; (l614 < 2); l614 = (l614 + 1)) {
			fRec883[l614] = 0.0;
			
		}
		for (int l615 = 0; (l615 < 2); l615 = (l615 + 1)) {
			fRec882[l615] = 0.0;
			
		}
		for (int l616 = 0; (l616 < 2); l616 = (l616 + 1)) {
			fRec880[l616] = 0.0;
			
		}
		for (int l617 = 0; (l617 < 2); l617 = (l617 + 1)) {
			fRec879[l617] = 0.0;
			
		}
		for (int l618 = 0; (l618 < 2); l618 = (l618 + 1)) {
			fRec877[l618] = 0.0;
			
		}
		for (int l619 = 0; (l619 < 2); l619 = (l619 + 1)) {
			fRec876[l619] = 0.0;
			
		}
		for (int l620 = 0; (l620 < 2); l620 = (l620 + 1)) {
			fRec874[l620] = 0.0;
			
		}
		for (int l621 = 0; (l621 < 2); l621 = (l621 + 1)) {
			fRec873[l621] = 0.0;
			
		}
		for (int l622 = 0; (l622 < 2); l622 = (l622 + 1)) {
			fRec871[l622] = 0.0;
			
		}
		for (int l623 = 0; (l623 < 2); l623 = (l623 + 1)) {
			fRec903[l623] = 0.0;
			
		}
		for (int l624 = 0; (l624 < 2); l624 = (l624 + 1)) {
			fRec901[l624] = 0.0;
			
		}
		for (int l625 = 0; (l625 < 2); l625 = (l625 + 1)) {
			fRec900[l625] = 0.0;
			
		}
		for (int l626 = 0; (l626 < 2); l626 = (l626 + 1)) {
			fRec898[l626] = 0.0;
			
		}
		for (int l627 = 0; (l627 < 2); l627 = (l627 + 1)) {
			fRec897[l627] = 0.0;
			
		}
		for (int l628 = 0; (l628 < 2); l628 = (l628 + 1)) {
			fRec895[l628] = 0.0;
			
		}
		for (int l629 = 0; (l629 < 2); l629 = (l629 + 1)) {
			fRec894[l629] = 0.0;
			
		}
		for (int l630 = 0; (l630 < 2); l630 = (l630 + 1)) {
			fRec892[l630] = 0.0;
			
		}
		for (int l631 = 0; (l631 < 2); l631 = (l631 + 1)) {
			fRec891[l631] = 0.0;
			
		}
		for (int l632 = 0; (l632 < 2); l632 = (l632 + 1)) {
			fRec889[l632] = 0.0;
			
		}
		for (int l633 = 0; (l633 < 2); l633 = (l633 + 1)) {
			fRec915[l633] = 0.0;
			
		}
		for (int l634 = 0; (l634 < 2); l634 = (l634 + 1)) {
			fRec913[l634] = 0.0;
			
		}
		for (int l635 = 0; (l635 < 2); l635 = (l635 + 1)) {
			fRec912[l635] = 0.0;
			
		}
		for (int l636 = 0; (l636 < 2); l636 = (l636 + 1)) {
			fRec910[l636] = 0.0;
			
		}
		for (int l637 = 0; (l637 < 2); l637 = (l637 + 1)) {
			fRec909[l637] = 0.0;
			
		}
		for (int l638 = 0; (l638 < 2); l638 = (l638 + 1)) {
			fRec907[l638] = 0.0;
			
		}
		for (int l639 = 0; (l639 < 2); l639 = (l639 + 1)) {
			fRec906[l639] = 0.0;
			
		}
		for (int l640 = 0; (l640 < 2); l640 = (l640 + 1)) {
			fRec904[l640] = 0.0;
			
		}
		for (int l641 = 0; (l641 < 2); l641 = (l641 + 1)) {
			fRec924[l641] = 0.0;
			
		}
		for (int l642 = 0; (l642 < 2); l642 = (l642 + 1)) {
			fRec922[l642] = 0.0;
			
		}
		for (int l643 = 0; (l643 < 2); l643 = (l643 + 1)) {
			fRec921[l643] = 0.0;
			
		}
		for (int l644 = 0; (l644 < 2); l644 = (l644 + 1)) {
			fRec919[l644] = 0.0;
			
		}
		for (int l645 = 0; (l645 < 2); l645 = (l645 + 1)) {
			fRec918[l645] = 0.0;
			
		}
		for (int l646 = 0; (l646 < 2); l646 = (l646 + 1)) {
			fRec916[l646] = 0.0;
			
		}
		for (int l647 = 0; (l647 < 2); l647 = (l647 + 1)) {
			fRec927[l647] = 0.0;
			
		}
		for (int l648 = 0; (l648 < 2); l648 = (l648 + 1)) {
			fRec925[l648] = 0.0;
			
		}
		for (int l649 = 0; (l649 < 2); l649 = (l649 + 1)) {
			fRec933[l649] = 0.0;
			
		}
		for (int l650 = 0; (l650 < 2); l650 = (l650 + 1)) {
			fRec931[l650] = 0.0;
			
		}
		for (int l651 = 0; (l651 < 2); l651 = (l651 + 1)) {
			fRec930[l651] = 0.0;
			
		}
		for (int l652 = 0; (l652 < 2); l652 = (l652 + 1)) {
			fRec928[l652] = 0.0;
			
		}
		for (int l653 = 0; (l653 < 128); l653 = (l653 + 1)) {
			fVec13[l653] = 0.0;
			
		}
		for (int l654 = 0; (l654 < 2); l654 = (l654 + 1)) {
			fRec951[l654] = 0.0;
			
		}
		for (int l655 = 0; (l655 < 2); l655 = (l655 + 1)) {
			fRec949[l655] = 0.0;
			
		}
		for (int l656 = 0; (l656 < 2); l656 = (l656 + 1)) {
			fRec948[l656] = 0.0;
			
		}
		for (int l657 = 0; (l657 < 2); l657 = (l657 + 1)) {
			fRec946[l657] = 0.0;
			
		}
		for (int l658 = 0; (l658 < 2); l658 = (l658 + 1)) {
			fRec945[l658] = 0.0;
			
		}
		for (int l659 = 0; (l659 < 2); l659 = (l659 + 1)) {
			fRec943[l659] = 0.0;
			
		}
		for (int l660 = 0; (l660 < 2); l660 = (l660 + 1)) {
			fRec942[l660] = 0.0;
			
		}
		for (int l661 = 0; (l661 < 2); l661 = (l661 + 1)) {
			fRec940[l661] = 0.0;
			
		}
		for (int l662 = 0; (l662 < 2); l662 = (l662 + 1)) {
			fRec939[l662] = 0.0;
			
		}
		for (int l663 = 0; (l663 < 2); l663 = (l663 + 1)) {
			fRec937[l663] = 0.0;
			
		}
		for (int l664 = 0; (l664 < 2); l664 = (l664 + 1)) {
			fRec936[l664] = 0.0;
			
		}
		for (int l665 = 0; (l665 < 2); l665 = (l665 + 1)) {
			fRec934[l665] = 0.0;
			
		}
		for (int l666 = 0; (l666 < 2); l666 = (l666 + 1)) {
			fRec963[l666] = 0.0;
			
		}
		for (int l667 = 0; (l667 < 2); l667 = (l667 + 1)) {
			fRec961[l667] = 0.0;
			
		}
		for (int l668 = 0; (l668 < 2); l668 = (l668 + 1)) {
			fRec960[l668] = 0.0;
			
		}
		for (int l669 = 0; (l669 < 2); l669 = (l669 + 1)) {
			fRec958[l669] = 0.0;
			
		}
		for (int l670 = 0; (l670 < 2); l670 = (l670 + 1)) {
			fRec957[l670] = 0.0;
			
		}
		for (int l671 = 0; (l671 < 2); l671 = (l671 + 1)) {
			fRec955[l671] = 0.0;
			
		}
		for (int l672 = 0; (l672 < 2); l672 = (l672 + 1)) {
			fRec954[l672] = 0.0;
			
		}
		for (int l673 = 0; (l673 < 2); l673 = (l673 + 1)) {
			fRec952[l673] = 0.0;
			
		}
		for (int l674 = 0; (l674 < 2); l674 = (l674 + 1)) {
			fRec972[l674] = 0.0;
			
		}
		for (int l675 = 0; (l675 < 2); l675 = (l675 + 1)) {
			fRec970[l675] = 0.0;
			
		}
		for (int l676 = 0; (l676 < 2); l676 = (l676 + 1)) {
			fRec969[l676] = 0.0;
			
		}
		for (int l677 = 0; (l677 < 2); l677 = (l677 + 1)) {
			fRec967[l677] = 0.0;
			
		}
		for (int l678 = 0; (l678 < 2); l678 = (l678 + 1)) {
			fRec966[l678] = 0.0;
			
		}
		for (int l679 = 0; (l679 < 2); l679 = (l679 + 1)) {
			fRec964[l679] = 0.0;
			
		}
		for (int l680 = 0; (l680 < 2); l680 = (l680 + 1)) {
			fRec975[l680] = 0.0;
			
		}
		for (int l681 = 0; (l681 < 2); l681 = (l681 + 1)) {
			fRec973[l681] = 0.0;
			
		}
		for (int l682 = 0; (l682 < 2); l682 = (l682 + 1)) {
			fRec981[l682] = 0.0;
			
		}
		for (int l683 = 0; (l683 < 2); l683 = (l683 + 1)) {
			fRec979[l683] = 0.0;
			
		}
		for (int l684 = 0; (l684 < 2); l684 = (l684 + 1)) {
			fRec978[l684] = 0.0;
			
		}
		for (int l685 = 0; (l685 < 2); l685 = (l685 + 1)) {
			fRec976[l685] = 0.0;
			
		}
		for (int l686 = 0; (l686 < 2); l686 = (l686 + 1)) {
			fRec996[l686] = 0.0;
			
		}
		for (int l687 = 0; (l687 < 2); l687 = (l687 + 1)) {
			fRec994[l687] = 0.0;
			
		}
		for (int l688 = 0; (l688 < 2); l688 = (l688 + 1)) {
			fRec993[l688] = 0.0;
			
		}
		for (int l689 = 0; (l689 < 2); l689 = (l689 + 1)) {
			fRec991[l689] = 0.0;
			
		}
		for (int l690 = 0; (l690 < 2); l690 = (l690 + 1)) {
			fRec990[l690] = 0.0;
			
		}
		for (int l691 = 0; (l691 < 2); l691 = (l691 + 1)) {
			fRec988[l691] = 0.0;
			
		}
		for (int l692 = 0; (l692 < 2); l692 = (l692 + 1)) {
			fRec987[l692] = 0.0;
			
		}
		for (int l693 = 0; (l693 < 2); l693 = (l693 + 1)) {
			fRec985[l693] = 0.0;
			
		}
		for (int l694 = 0; (l694 < 2); l694 = (l694 + 1)) {
			fRec984[l694] = 0.0;
			
		}
		for (int l695 = 0; (l695 < 2); l695 = (l695 + 1)) {
			fRec982[l695] = 0.0;
			
		}
		for (int l696 = 0; (l696 < 128); l696 = (l696 + 1)) {
			fVec14[l696] = 0.0;
			
		}
		for (int l697 = 0; (l697 < 2); l697 = (l697 + 1)) {
			fRec1014[l697] = 0.0;
			
		}
		for (int l698 = 0; (l698 < 2); l698 = (l698 + 1)) {
			fRec1012[l698] = 0.0;
			
		}
		for (int l699 = 0; (l699 < 2); l699 = (l699 + 1)) {
			fRec1011[l699] = 0.0;
			
		}
		for (int l700 = 0; (l700 < 2); l700 = (l700 + 1)) {
			fRec1009[l700] = 0.0;
			
		}
		for (int l701 = 0; (l701 < 2); l701 = (l701 + 1)) {
			fRec1008[l701] = 0.0;
			
		}
		for (int l702 = 0; (l702 < 2); l702 = (l702 + 1)) {
			fRec1006[l702] = 0.0;
			
		}
		for (int l703 = 0; (l703 < 2); l703 = (l703 + 1)) {
			fRec1005[l703] = 0.0;
			
		}
		for (int l704 = 0; (l704 < 2); l704 = (l704 + 1)) {
			fRec1003[l704] = 0.0;
			
		}
		for (int l705 = 0; (l705 < 2); l705 = (l705 + 1)) {
			fRec1002[l705] = 0.0;
			
		}
		for (int l706 = 0; (l706 < 2); l706 = (l706 + 1)) {
			fRec1000[l706] = 0.0;
			
		}
		for (int l707 = 0; (l707 < 2); l707 = (l707 + 1)) {
			fRec999[l707] = 0.0;
			
		}
		for (int l708 = 0; (l708 < 2); l708 = (l708 + 1)) {
			fRec997[l708] = 0.0;
			
		}
		for (int l709 = 0; (l709 < 2); l709 = (l709 + 1)) {
			fRec1029[l709] = 0.0;
			
		}
		for (int l710 = 0; (l710 < 2); l710 = (l710 + 1)) {
			fRec1027[l710] = 0.0;
			
		}
		for (int l711 = 0; (l711 < 2); l711 = (l711 + 1)) {
			fRec1026[l711] = 0.0;
			
		}
		for (int l712 = 0; (l712 < 2); l712 = (l712 + 1)) {
			fRec1024[l712] = 0.0;
			
		}
		for (int l713 = 0; (l713 < 2); l713 = (l713 + 1)) {
			fRec1023[l713] = 0.0;
			
		}
		for (int l714 = 0; (l714 < 2); l714 = (l714 + 1)) {
			fRec1021[l714] = 0.0;
			
		}
		for (int l715 = 0; (l715 < 2); l715 = (l715 + 1)) {
			fRec1020[l715] = 0.0;
			
		}
		for (int l716 = 0; (l716 < 2); l716 = (l716 + 1)) {
			fRec1018[l716] = 0.0;
			
		}
		for (int l717 = 0; (l717 < 2); l717 = (l717 + 1)) {
			fRec1017[l717] = 0.0;
			
		}
		for (int l718 = 0; (l718 < 2); l718 = (l718 + 1)) {
			fRec1015[l718] = 0.0;
			
		}
		for (int l719 = 0; (l719 < 2); l719 = (l719 + 1)) {
			fRec1041[l719] = 0.0;
			
		}
		for (int l720 = 0; (l720 < 2); l720 = (l720 + 1)) {
			fRec1039[l720] = 0.0;
			
		}
		for (int l721 = 0; (l721 < 2); l721 = (l721 + 1)) {
			fRec1038[l721] = 0.0;
			
		}
		for (int l722 = 0; (l722 < 2); l722 = (l722 + 1)) {
			fRec1036[l722] = 0.0;
			
		}
		for (int l723 = 0; (l723 < 2); l723 = (l723 + 1)) {
			fRec1035[l723] = 0.0;
			
		}
		for (int l724 = 0; (l724 < 2); l724 = (l724 + 1)) {
			fRec1033[l724] = 0.0;
			
		}
		for (int l725 = 0; (l725 < 2); l725 = (l725 + 1)) {
			fRec1032[l725] = 0.0;
			
		}
		for (int l726 = 0; (l726 < 2); l726 = (l726 + 1)) {
			fRec1030[l726] = 0.0;
			
		}
		for (int l727 = 0; (l727 < 2); l727 = (l727 + 1)) {
			fRec1050[l727] = 0.0;
			
		}
		for (int l728 = 0; (l728 < 2); l728 = (l728 + 1)) {
			fRec1048[l728] = 0.0;
			
		}
		for (int l729 = 0; (l729 < 2); l729 = (l729 + 1)) {
			fRec1047[l729] = 0.0;
			
		}
		for (int l730 = 0; (l730 < 2); l730 = (l730 + 1)) {
			fRec1045[l730] = 0.0;
			
		}
		for (int l731 = 0; (l731 < 2); l731 = (l731 + 1)) {
			fRec1044[l731] = 0.0;
			
		}
		for (int l732 = 0; (l732 < 2); l732 = (l732 + 1)) {
			fRec1042[l732] = 0.0;
			
		}
		for (int l733 = 0; (l733 < 2); l733 = (l733 + 1)) {
			fRec1053[l733] = 0.0;
			
		}
		for (int l734 = 0; (l734 < 2); l734 = (l734 + 1)) {
			fRec1051[l734] = 0.0;
			
		}
		for (int l735 = 0; (l735 < 2); l735 = (l735 + 1)) {
			fRec1059[l735] = 0.0;
			
		}
		for (int l736 = 0; (l736 < 2); l736 = (l736 + 1)) {
			fRec1057[l736] = 0.0;
			
		}
		for (int l737 = 0; (l737 < 2); l737 = (l737 + 1)) {
			fRec1056[l737] = 0.0;
			
		}
		for (int l738 = 0; (l738 < 2); l738 = (l738 + 1)) {
			fRec1054[l738] = 0.0;
			
		}
		for (int l739 = 0; (l739 < 128); l739 = (l739 + 1)) {
			fVec15[l739] = 0.0;
			
		}
		for (int l740 = 0; (l740 < 2); l740 = (l740 + 1)) {
			fRec1077[l740] = 0.0;
			
		}
		for (int l741 = 0; (l741 < 2); l741 = (l741 + 1)) {
			fRec1075[l741] = 0.0;
			
		}
		for (int l742 = 0; (l742 < 2); l742 = (l742 + 1)) {
			fRec1074[l742] = 0.0;
			
		}
		for (int l743 = 0; (l743 < 2); l743 = (l743 + 1)) {
			fRec1072[l743] = 0.0;
			
		}
		for (int l744 = 0; (l744 < 2); l744 = (l744 + 1)) {
			fRec1071[l744] = 0.0;
			
		}
		for (int l745 = 0; (l745 < 2); l745 = (l745 + 1)) {
			fRec1069[l745] = 0.0;
			
		}
		for (int l746 = 0; (l746 < 2); l746 = (l746 + 1)) {
			fRec1068[l746] = 0.0;
			
		}
		for (int l747 = 0; (l747 < 2); l747 = (l747 + 1)) {
			fRec1066[l747] = 0.0;
			
		}
		for (int l748 = 0; (l748 < 2); l748 = (l748 + 1)) {
			fRec1065[l748] = 0.0;
			
		}
		for (int l749 = 0; (l749 < 2); l749 = (l749 + 1)) {
			fRec1063[l749] = 0.0;
			
		}
		for (int l750 = 0; (l750 < 2); l750 = (l750 + 1)) {
			fRec1062[l750] = 0.0;
			
		}
		for (int l751 = 0; (l751 < 2); l751 = (l751 + 1)) {
			fRec1060[l751] = 0.0;
			
		}
		for (int l752 = 0; (l752 < 2); l752 = (l752 + 1)) {
			fRec1092[l752] = 0.0;
			
		}
		for (int l753 = 0; (l753 < 2); l753 = (l753 + 1)) {
			fRec1090[l753] = 0.0;
			
		}
		for (int l754 = 0; (l754 < 2); l754 = (l754 + 1)) {
			fRec1089[l754] = 0.0;
			
		}
		for (int l755 = 0; (l755 < 2); l755 = (l755 + 1)) {
			fRec1087[l755] = 0.0;
			
		}
		for (int l756 = 0; (l756 < 2); l756 = (l756 + 1)) {
			fRec1086[l756] = 0.0;
			
		}
		for (int l757 = 0; (l757 < 2); l757 = (l757 + 1)) {
			fRec1084[l757] = 0.0;
			
		}
		for (int l758 = 0; (l758 < 2); l758 = (l758 + 1)) {
			fRec1083[l758] = 0.0;
			
		}
		for (int l759 = 0; (l759 < 2); l759 = (l759 + 1)) {
			fRec1081[l759] = 0.0;
			
		}
		for (int l760 = 0; (l760 < 2); l760 = (l760 + 1)) {
			fRec1080[l760] = 0.0;
			
		}
		for (int l761 = 0; (l761 < 2); l761 = (l761 + 1)) {
			fRec1078[l761] = 0.0;
			
		}
		for (int l762 = 0; (l762 < 2); l762 = (l762 + 1)) {
			fRec1104[l762] = 0.0;
			
		}
		for (int l763 = 0; (l763 < 2); l763 = (l763 + 1)) {
			fRec1102[l763] = 0.0;
			
		}
		for (int l764 = 0; (l764 < 2); l764 = (l764 + 1)) {
			fRec1101[l764] = 0.0;
			
		}
		for (int l765 = 0; (l765 < 2); l765 = (l765 + 1)) {
			fRec1099[l765] = 0.0;
			
		}
		for (int l766 = 0; (l766 < 2); l766 = (l766 + 1)) {
			fRec1098[l766] = 0.0;
			
		}
		for (int l767 = 0; (l767 < 2); l767 = (l767 + 1)) {
			fRec1096[l767] = 0.0;
			
		}
		for (int l768 = 0; (l768 < 2); l768 = (l768 + 1)) {
			fRec1095[l768] = 0.0;
			
		}
		for (int l769 = 0; (l769 < 2); l769 = (l769 + 1)) {
			fRec1093[l769] = 0.0;
			
		}
		for (int l770 = 0; (l770 < 2); l770 = (l770 + 1)) {
			fRec1113[l770] = 0.0;
			
		}
		for (int l771 = 0; (l771 < 2); l771 = (l771 + 1)) {
			fRec1111[l771] = 0.0;
			
		}
		for (int l772 = 0; (l772 < 2); l772 = (l772 + 1)) {
			fRec1110[l772] = 0.0;
			
		}
		for (int l773 = 0; (l773 < 2); l773 = (l773 + 1)) {
			fRec1108[l773] = 0.0;
			
		}
		for (int l774 = 0; (l774 < 2); l774 = (l774 + 1)) {
			fRec1107[l774] = 0.0;
			
		}
		for (int l775 = 0; (l775 < 2); l775 = (l775 + 1)) {
			fRec1105[l775] = 0.0;
			
		}
		for (int l776 = 0; (l776 < 2); l776 = (l776 + 1)) {
			fRec1116[l776] = 0.0;
			
		}
		for (int l777 = 0; (l777 < 2); l777 = (l777 + 1)) {
			fRec1114[l777] = 0.0;
			
		}
		for (int l778 = 0; (l778 < 2); l778 = (l778 + 1)) {
			fRec1122[l778] = 0.0;
			
		}
		for (int l779 = 0; (l779 < 2); l779 = (l779 + 1)) {
			fRec1120[l779] = 0.0;
			
		}
		for (int l780 = 0; (l780 < 2); l780 = (l780 + 1)) {
			fRec1119[l780] = 0.0;
			
		}
		for (int l781 = 0; (l781 < 2); l781 = (l781 + 1)) {
			fRec1117[l781] = 0.0;
			
		}
		for (int l782 = 0; (l782 < 128); l782 = (l782 + 1)) {
			fVec16[l782] = 0.0;
			
		}
		for (int l783 = 0; (l783 < 2); l783 = (l783 + 1)) {
			fRec1140[l783] = 0.0;
			
		}
		for (int l784 = 0; (l784 < 2); l784 = (l784 + 1)) {
			fRec1138[l784] = 0.0;
			
		}
		for (int l785 = 0; (l785 < 2); l785 = (l785 + 1)) {
			fRec1137[l785] = 0.0;
			
		}
		for (int l786 = 0; (l786 < 2); l786 = (l786 + 1)) {
			fRec1135[l786] = 0.0;
			
		}
		for (int l787 = 0; (l787 < 2); l787 = (l787 + 1)) {
			fRec1134[l787] = 0.0;
			
		}
		for (int l788 = 0; (l788 < 2); l788 = (l788 + 1)) {
			fRec1132[l788] = 0.0;
			
		}
		for (int l789 = 0; (l789 < 2); l789 = (l789 + 1)) {
			fRec1131[l789] = 0.0;
			
		}
		for (int l790 = 0; (l790 < 2); l790 = (l790 + 1)) {
			fRec1129[l790] = 0.0;
			
		}
		for (int l791 = 0; (l791 < 2); l791 = (l791 + 1)) {
			fRec1128[l791] = 0.0;
			
		}
		for (int l792 = 0; (l792 < 2); l792 = (l792 + 1)) {
			fRec1126[l792] = 0.0;
			
		}
		for (int l793 = 0; (l793 < 2); l793 = (l793 + 1)) {
			fRec1125[l793] = 0.0;
			
		}
		for (int l794 = 0; (l794 < 2); l794 = (l794 + 1)) {
			fRec1123[l794] = 0.0;
			
		}
		for (int l795 = 0; (l795 < 2); l795 = (l795 + 1)) {
			fRec1155[l795] = 0.0;
			
		}
		for (int l796 = 0; (l796 < 2); l796 = (l796 + 1)) {
			fRec1153[l796] = 0.0;
			
		}
		for (int l797 = 0; (l797 < 2); l797 = (l797 + 1)) {
			fRec1152[l797] = 0.0;
			
		}
		for (int l798 = 0; (l798 < 2); l798 = (l798 + 1)) {
			fRec1150[l798] = 0.0;
			
		}
		for (int l799 = 0; (l799 < 2); l799 = (l799 + 1)) {
			fRec1149[l799] = 0.0;
			
		}
		for (int l800 = 0; (l800 < 2); l800 = (l800 + 1)) {
			fRec1147[l800] = 0.0;
			
		}
		for (int l801 = 0; (l801 < 2); l801 = (l801 + 1)) {
			fRec1146[l801] = 0.0;
			
		}
		for (int l802 = 0; (l802 < 2); l802 = (l802 + 1)) {
			fRec1144[l802] = 0.0;
			
		}
		for (int l803 = 0; (l803 < 2); l803 = (l803 + 1)) {
			fRec1143[l803] = 0.0;
			
		}
		for (int l804 = 0; (l804 < 2); l804 = (l804 + 1)) {
			fRec1141[l804] = 0.0;
			
		}
		for (int l805 = 0; (l805 < 2); l805 = (l805 + 1)) {
			fRec1167[l805] = 0.0;
			
		}
		for (int l806 = 0; (l806 < 2); l806 = (l806 + 1)) {
			fRec1165[l806] = 0.0;
			
		}
		for (int l807 = 0; (l807 < 2); l807 = (l807 + 1)) {
			fRec1164[l807] = 0.0;
			
		}
		for (int l808 = 0; (l808 < 2); l808 = (l808 + 1)) {
			fRec1162[l808] = 0.0;
			
		}
		for (int l809 = 0; (l809 < 2); l809 = (l809 + 1)) {
			fRec1161[l809] = 0.0;
			
		}
		for (int l810 = 0; (l810 < 2); l810 = (l810 + 1)) {
			fRec1159[l810] = 0.0;
			
		}
		for (int l811 = 0; (l811 < 2); l811 = (l811 + 1)) {
			fRec1158[l811] = 0.0;
			
		}
		for (int l812 = 0; (l812 < 2); l812 = (l812 + 1)) {
			fRec1156[l812] = 0.0;
			
		}
		for (int l813 = 0; (l813 < 2); l813 = (l813 + 1)) {
			fRec1176[l813] = 0.0;
			
		}
		for (int l814 = 0; (l814 < 2); l814 = (l814 + 1)) {
			fRec1174[l814] = 0.0;
			
		}
		for (int l815 = 0; (l815 < 2); l815 = (l815 + 1)) {
			fRec1173[l815] = 0.0;
			
		}
		for (int l816 = 0; (l816 < 2); l816 = (l816 + 1)) {
			fRec1171[l816] = 0.0;
			
		}
		for (int l817 = 0; (l817 < 2); l817 = (l817 + 1)) {
			fRec1170[l817] = 0.0;
			
		}
		for (int l818 = 0; (l818 < 2); l818 = (l818 + 1)) {
			fRec1168[l818] = 0.0;
			
		}
		for (int l819 = 0; (l819 < 2); l819 = (l819 + 1)) {
			fRec1179[l819] = 0.0;
			
		}
		for (int l820 = 0; (l820 < 2); l820 = (l820 + 1)) {
			fRec1177[l820] = 0.0;
			
		}
		for (int l821 = 0; (l821 < 2); l821 = (l821 + 1)) {
			fRec1185[l821] = 0.0;
			
		}
		for (int l822 = 0; (l822 < 2); l822 = (l822 + 1)) {
			fRec1183[l822] = 0.0;
			
		}
		for (int l823 = 0; (l823 < 2); l823 = (l823 + 1)) {
			fRec1182[l823] = 0.0;
			
		}
		for (int l824 = 0; (l824 < 2); l824 = (l824 + 1)) {
			fRec1180[l824] = 0.0;
			
		}
		for (int l825 = 0; (l825 < 128); l825 = (l825 + 1)) {
			fVec17[l825] = 0.0;
			
		}
		for (int l826 = 0; (l826 < 2); l826 = (l826 + 1)) {
			fRec1203[l826] = 0.0;
			
		}
		for (int l827 = 0; (l827 < 2); l827 = (l827 + 1)) {
			fRec1201[l827] = 0.0;
			
		}
		for (int l828 = 0; (l828 < 2); l828 = (l828 + 1)) {
			fRec1200[l828] = 0.0;
			
		}
		for (int l829 = 0; (l829 < 2); l829 = (l829 + 1)) {
			fRec1198[l829] = 0.0;
			
		}
		for (int l830 = 0; (l830 < 2); l830 = (l830 + 1)) {
			fRec1197[l830] = 0.0;
			
		}
		for (int l831 = 0; (l831 < 2); l831 = (l831 + 1)) {
			fRec1195[l831] = 0.0;
			
		}
		for (int l832 = 0; (l832 < 2); l832 = (l832 + 1)) {
			fRec1194[l832] = 0.0;
			
		}
		for (int l833 = 0; (l833 < 2); l833 = (l833 + 1)) {
			fRec1192[l833] = 0.0;
			
		}
		for (int l834 = 0; (l834 < 2); l834 = (l834 + 1)) {
			fRec1191[l834] = 0.0;
			
		}
		for (int l835 = 0; (l835 < 2); l835 = (l835 + 1)) {
			fRec1189[l835] = 0.0;
			
		}
		for (int l836 = 0; (l836 < 2); l836 = (l836 + 1)) {
			fRec1188[l836] = 0.0;
			
		}
		for (int l837 = 0; (l837 < 2); l837 = (l837 + 1)) {
			fRec1186[l837] = 0.0;
			
		}
		for (int l838 = 0; (l838 < 2); l838 = (l838 + 1)) {
			fRec1218[l838] = 0.0;
			
		}
		for (int l839 = 0; (l839 < 2); l839 = (l839 + 1)) {
			fRec1216[l839] = 0.0;
			
		}
		for (int l840 = 0; (l840 < 2); l840 = (l840 + 1)) {
			fRec1215[l840] = 0.0;
			
		}
		for (int l841 = 0; (l841 < 2); l841 = (l841 + 1)) {
			fRec1213[l841] = 0.0;
			
		}
		for (int l842 = 0; (l842 < 2); l842 = (l842 + 1)) {
			fRec1212[l842] = 0.0;
			
		}
		for (int l843 = 0; (l843 < 2); l843 = (l843 + 1)) {
			fRec1210[l843] = 0.0;
			
		}
		for (int l844 = 0; (l844 < 2); l844 = (l844 + 1)) {
			fRec1209[l844] = 0.0;
			
		}
		for (int l845 = 0; (l845 < 2); l845 = (l845 + 1)) {
			fRec1207[l845] = 0.0;
			
		}
		for (int l846 = 0; (l846 < 2); l846 = (l846 + 1)) {
			fRec1206[l846] = 0.0;
			
		}
		for (int l847 = 0; (l847 < 2); l847 = (l847 + 1)) {
			fRec1204[l847] = 0.0;
			
		}
		for (int l848 = 0; (l848 < 2); l848 = (l848 + 1)) {
			fRec1230[l848] = 0.0;
			
		}
		for (int l849 = 0; (l849 < 2); l849 = (l849 + 1)) {
			fRec1228[l849] = 0.0;
			
		}
		for (int l850 = 0; (l850 < 2); l850 = (l850 + 1)) {
			fRec1227[l850] = 0.0;
			
		}
		for (int l851 = 0; (l851 < 2); l851 = (l851 + 1)) {
			fRec1225[l851] = 0.0;
			
		}
		for (int l852 = 0; (l852 < 2); l852 = (l852 + 1)) {
			fRec1224[l852] = 0.0;
			
		}
		for (int l853 = 0; (l853 < 2); l853 = (l853 + 1)) {
			fRec1222[l853] = 0.0;
			
		}
		for (int l854 = 0; (l854 < 2); l854 = (l854 + 1)) {
			fRec1221[l854] = 0.0;
			
		}
		for (int l855 = 0; (l855 < 2); l855 = (l855 + 1)) {
			fRec1219[l855] = 0.0;
			
		}
		for (int l856 = 0; (l856 < 2); l856 = (l856 + 1)) {
			fRec1239[l856] = 0.0;
			
		}
		for (int l857 = 0; (l857 < 2); l857 = (l857 + 1)) {
			fRec1237[l857] = 0.0;
			
		}
		for (int l858 = 0; (l858 < 2); l858 = (l858 + 1)) {
			fRec1236[l858] = 0.0;
			
		}
		for (int l859 = 0; (l859 < 2); l859 = (l859 + 1)) {
			fRec1234[l859] = 0.0;
			
		}
		for (int l860 = 0; (l860 < 2); l860 = (l860 + 1)) {
			fRec1233[l860] = 0.0;
			
		}
		for (int l861 = 0; (l861 < 2); l861 = (l861 + 1)) {
			fRec1231[l861] = 0.0;
			
		}
		for (int l862 = 0; (l862 < 2); l862 = (l862 + 1)) {
			fRec1242[l862] = 0.0;
			
		}
		for (int l863 = 0; (l863 < 2); l863 = (l863 + 1)) {
			fRec1240[l863] = 0.0;
			
		}
		for (int l864 = 0; (l864 < 2); l864 = (l864 + 1)) {
			fRec1248[l864] = 0.0;
			
		}
		for (int l865 = 0; (l865 < 2); l865 = (l865 + 1)) {
			fRec1246[l865] = 0.0;
			
		}
		for (int l866 = 0; (l866 < 2); l866 = (l866 + 1)) {
			fRec1245[l866] = 0.0;
			
		}
		for (int l867 = 0; (l867 < 2); l867 = (l867 + 1)) {
			fRec1243[l867] = 0.0;
			
		}
		for (int l868 = 0; (l868 < 128); l868 = (l868 + 1)) {
			fVec18[l868] = 0.0;
			
		}
		for (int l869 = 0; (l869 < 2); l869 = (l869 + 1)) {
			fRec1266[l869] = 0.0;
			
		}
		for (int l870 = 0; (l870 < 2); l870 = (l870 + 1)) {
			fRec1264[l870] = 0.0;
			
		}
		for (int l871 = 0; (l871 < 2); l871 = (l871 + 1)) {
			fRec1263[l871] = 0.0;
			
		}
		for (int l872 = 0; (l872 < 2); l872 = (l872 + 1)) {
			fRec1261[l872] = 0.0;
			
		}
		for (int l873 = 0; (l873 < 2); l873 = (l873 + 1)) {
			fRec1260[l873] = 0.0;
			
		}
		for (int l874 = 0; (l874 < 2); l874 = (l874 + 1)) {
			fRec1258[l874] = 0.0;
			
		}
		for (int l875 = 0; (l875 < 2); l875 = (l875 + 1)) {
			fRec1257[l875] = 0.0;
			
		}
		for (int l876 = 0; (l876 < 2); l876 = (l876 + 1)) {
			fRec1255[l876] = 0.0;
			
		}
		for (int l877 = 0; (l877 < 2); l877 = (l877 + 1)) {
			fRec1254[l877] = 0.0;
			
		}
		for (int l878 = 0; (l878 < 2); l878 = (l878 + 1)) {
			fRec1252[l878] = 0.0;
			
		}
		for (int l879 = 0; (l879 < 2); l879 = (l879 + 1)) {
			fRec1251[l879] = 0.0;
			
		}
		for (int l880 = 0; (l880 < 2); l880 = (l880 + 1)) {
			fRec1249[l880] = 0.0;
			
		}
		for (int l881 = 0; (l881 < 2); l881 = (l881 + 1)) {
			fRec1281[l881] = 0.0;
			
		}
		for (int l882 = 0; (l882 < 2); l882 = (l882 + 1)) {
			fRec1279[l882] = 0.0;
			
		}
		for (int l883 = 0; (l883 < 2); l883 = (l883 + 1)) {
			fRec1278[l883] = 0.0;
			
		}
		for (int l884 = 0; (l884 < 2); l884 = (l884 + 1)) {
			fRec1276[l884] = 0.0;
			
		}
		for (int l885 = 0; (l885 < 2); l885 = (l885 + 1)) {
			fRec1275[l885] = 0.0;
			
		}
		for (int l886 = 0; (l886 < 2); l886 = (l886 + 1)) {
			fRec1273[l886] = 0.0;
			
		}
		for (int l887 = 0; (l887 < 2); l887 = (l887 + 1)) {
			fRec1272[l887] = 0.0;
			
		}
		for (int l888 = 0; (l888 < 2); l888 = (l888 + 1)) {
			fRec1270[l888] = 0.0;
			
		}
		for (int l889 = 0; (l889 < 2); l889 = (l889 + 1)) {
			fRec1269[l889] = 0.0;
			
		}
		for (int l890 = 0; (l890 < 2); l890 = (l890 + 1)) {
			fRec1267[l890] = 0.0;
			
		}
		for (int l891 = 0; (l891 < 2); l891 = (l891 + 1)) {
			fRec1293[l891] = 0.0;
			
		}
		for (int l892 = 0; (l892 < 2); l892 = (l892 + 1)) {
			fRec1291[l892] = 0.0;
			
		}
		for (int l893 = 0; (l893 < 2); l893 = (l893 + 1)) {
			fRec1290[l893] = 0.0;
			
		}
		for (int l894 = 0; (l894 < 2); l894 = (l894 + 1)) {
			fRec1288[l894] = 0.0;
			
		}
		for (int l895 = 0; (l895 < 2); l895 = (l895 + 1)) {
			fRec1287[l895] = 0.0;
			
		}
		for (int l896 = 0; (l896 < 2); l896 = (l896 + 1)) {
			fRec1285[l896] = 0.0;
			
		}
		for (int l897 = 0; (l897 < 2); l897 = (l897 + 1)) {
			fRec1284[l897] = 0.0;
			
		}
		for (int l898 = 0; (l898 < 2); l898 = (l898 + 1)) {
			fRec1282[l898] = 0.0;
			
		}
		for (int l899 = 0; (l899 < 2); l899 = (l899 + 1)) {
			fRec1302[l899] = 0.0;
			
		}
		for (int l900 = 0; (l900 < 2); l900 = (l900 + 1)) {
			fRec1300[l900] = 0.0;
			
		}
		for (int l901 = 0; (l901 < 2); l901 = (l901 + 1)) {
			fRec1299[l901] = 0.0;
			
		}
		for (int l902 = 0; (l902 < 2); l902 = (l902 + 1)) {
			fRec1297[l902] = 0.0;
			
		}
		for (int l903 = 0; (l903 < 2); l903 = (l903 + 1)) {
			fRec1296[l903] = 0.0;
			
		}
		for (int l904 = 0; (l904 < 2); l904 = (l904 + 1)) {
			fRec1294[l904] = 0.0;
			
		}
		for (int l905 = 0; (l905 < 2); l905 = (l905 + 1)) {
			fRec1305[l905] = 0.0;
			
		}
		for (int l906 = 0; (l906 < 2); l906 = (l906 + 1)) {
			fRec1303[l906] = 0.0;
			
		}
		for (int l907 = 0; (l907 < 2); l907 = (l907 + 1)) {
			fRec1311[l907] = 0.0;
			
		}
		for (int l908 = 0; (l908 < 2); l908 = (l908 + 1)) {
			fRec1309[l908] = 0.0;
			
		}
		for (int l909 = 0; (l909 < 2); l909 = (l909 + 1)) {
			fRec1308[l909] = 0.0;
			
		}
		for (int l910 = 0; (l910 < 2); l910 = (l910 + 1)) {
			fRec1306[l910] = 0.0;
			
		}
		for (int l911 = 0; (l911 < 128); l911 = (l911 + 1)) {
			fVec19[l911] = 0.0;
			
		}
		for (int l912 = 0; (l912 < 2); l912 = (l912 + 1)) {
			fRec1329[l912] = 0.0;
			
		}
		for (int l913 = 0; (l913 < 2); l913 = (l913 + 1)) {
			fRec1327[l913] = 0.0;
			
		}
		for (int l914 = 0; (l914 < 2); l914 = (l914 + 1)) {
			fRec1326[l914] = 0.0;
			
		}
		for (int l915 = 0; (l915 < 2); l915 = (l915 + 1)) {
			fRec1324[l915] = 0.0;
			
		}
		for (int l916 = 0; (l916 < 2); l916 = (l916 + 1)) {
			fRec1323[l916] = 0.0;
			
		}
		for (int l917 = 0; (l917 < 2); l917 = (l917 + 1)) {
			fRec1321[l917] = 0.0;
			
		}
		for (int l918 = 0; (l918 < 2); l918 = (l918 + 1)) {
			fRec1320[l918] = 0.0;
			
		}
		for (int l919 = 0; (l919 < 2); l919 = (l919 + 1)) {
			fRec1318[l919] = 0.0;
			
		}
		for (int l920 = 0; (l920 < 2); l920 = (l920 + 1)) {
			fRec1317[l920] = 0.0;
			
		}
		for (int l921 = 0; (l921 < 2); l921 = (l921 + 1)) {
			fRec1315[l921] = 0.0;
			
		}
		for (int l922 = 0; (l922 < 2); l922 = (l922 + 1)) {
			fRec1314[l922] = 0.0;
			
		}
		for (int l923 = 0; (l923 < 2); l923 = (l923 + 1)) {
			fRec1312[l923] = 0.0;
			
		}
		for (int l924 = 0; (l924 < 2); l924 = (l924 + 1)) {
			fRec1344[l924] = 0.0;
			
		}
		for (int l925 = 0; (l925 < 2); l925 = (l925 + 1)) {
			fRec1342[l925] = 0.0;
			
		}
		for (int l926 = 0; (l926 < 2); l926 = (l926 + 1)) {
			fRec1341[l926] = 0.0;
			
		}
		for (int l927 = 0; (l927 < 2); l927 = (l927 + 1)) {
			fRec1339[l927] = 0.0;
			
		}
		for (int l928 = 0; (l928 < 2); l928 = (l928 + 1)) {
			fRec1338[l928] = 0.0;
			
		}
		for (int l929 = 0; (l929 < 2); l929 = (l929 + 1)) {
			fRec1336[l929] = 0.0;
			
		}
		for (int l930 = 0; (l930 < 2); l930 = (l930 + 1)) {
			fRec1335[l930] = 0.0;
			
		}
		for (int l931 = 0; (l931 < 2); l931 = (l931 + 1)) {
			fRec1333[l931] = 0.0;
			
		}
		for (int l932 = 0; (l932 < 2); l932 = (l932 + 1)) {
			fRec1332[l932] = 0.0;
			
		}
		for (int l933 = 0; (l933 < 2); l933 = (l933 + 1)) {
			fRec1330[l933] = 0.0;
			
		}
		for (int l934 = 0; (l934 < 2); l934 = (l934 + 1)) {
			fRec1356[l934] = 0.0;
			
		}
		for (int l935 = 0; (l935 < 2); l935 = (l935 + 1)) {
			fRec1354[l935] = 0.0;
			
		}
		for (int l936 = 0; (l936 < 2); l936 = (l936 + 1)) {
			fRec1353[l936] = 0.0;
			
		}
		for (int l937 = 0; (l937 < 2); l937 = (l937 + 1)) {
			fRec1351[l937] = 0.0;
			
		}
		for (int l938 = 0; (l938 < 2); l938 = (l938 + 1)) {
			fRec1350[l938] = 0.0;
			
		}
		for (int l939 = 0; (l939 < 2); l939 = (l939 + 1)) {
			fRec1348[l939] = 0.0;
			
		}
		for (int l940 = 0; (l940 < 2); l940 = (l940 + 1)) {
			fRec1347[l940] = 0.0;
			
		}
		for (int l941 = 0; (l941 < 2); l941 = (l941 + 1)) {
			fRec1345[l941] = 0.0;
			
		}
		for (int l942 = 0; (l942 < 2); l942 = (l942 + 1)) {
			fRec1365[l942] = 0.0;
			
		}
		for (int l943 = 0; (l943 < 2); l943 = (l943 + 1)) {
			fRec1363[l943] = 0.0;
			
		}
		for (int l944 = 0; (l944 < 2); l944 = (l944 + 1)) {
			fRec1362[l944] = 0.0;
			
		}
		for (int l945 = 0; (l945 < 2); l945 = (l945 + 1)) {
			fRec1360[l945] = 0.0;
			
		}
		for (int l946 = 0; (l946 < 2); l946 = (l946 + 1)) {
			fRec1359[l946] = 0.0;
			
		}
		for (int l947 = 0; (l947 < 2); l947 = (l947 + 1)) {
			fRec1357[l947] = 0.0;
			
		}
		for (int l948 = 0; (l948 < 2); l948 = (l948 + 1)) {
			fRec1368[l948] = 0.0;
			
		}
		for (int l949 = 0; (l949 < 2); l949 = (l949 + 1)) {
			fRec1366[l949] = 0.0;
			
		}
		for (int l950 = 0; (l950 < 2); l950 = (l950 + 1)) {
			fRec1374[l950] = 0.0;
			
		}
		for (int l951 = 0; (l951 < 2); l951 = (l951 + 1)) {
			fRec1372[l951] = 0.0;
			
		}
		for (int l952 = 0; (l952 < 2); l952 = (l952 + 1)) {
			fRec1371[l952] = 0.0;
			
		}
		for (int l953 = 0; (l953 < 2); l953 = (l953 + 1)) {
			fRec1369[l953] = 0.0;
			
		}
		for (int l954 = 0; (l954 < 128); l954 = (l954 + 1)) {
			fVec20[l954] = 0.0;
			
		}
		for (int l955 = 0; (l955 < 2); l955 = (l955 + 1)) {
			fRec1392[l955] = 0.0;
			
		}
		for (int l956 = 0; (l956 < 2); l956 = (l956 + 1)) {
			fRec1390[l956] = 0.0;
			
		}
		for (int l957 = 0; (l957 < 2); l957 = (l957 + 1)) {
			fRec1389[l957] = 0.0;
			
		}
		for (int l958 = 0; (l958 < 2); l958 = (l958 + 1)) {
			fRec1387[l958] = 0.0;
			
		}
		for (int l959 = 0; (l959 < 2); l959 = (l959 + 1)) {
			fRec1386[l959] = 0.0;
			
		}
		for (int l960 = 0; (l960 < 2); l960 = (l960 + 1)) {
			fRec1384[l960] = 0.0;
			
		}
		for (int l961 = 0; (l961 < 2); l961 = (l961 + 1)) {
			fRec1383[l961] = 0.0;
			
		}
		for (int l962 = 0; (l962 < 2); l962 = (l962 + 1)) {
			fRec1381[l962] = 0.0;
			
		}
		for (int l963 = 0; (l963 < 2); l963 = (l963 + 1)) {
			fRec1380[l963] = 0.0;
			
		}
		for (int l964 = 0; (l964 < 2); l964 = (l964 + 1)) {
			fRec1378[l964] = 0.0;
			
		}
		for (int l965 = 0; (l965 < 2); l965 = (l965 + 1)) {
			fRec1377[l965] = 0.0;
			
		}
		for (int l966 = 0; (l966 < 2); l966 = (l966 + 1)) {
			fRec1375[l966] = 0.0;
			
		}
		for (int l967 = 0; (l967 < 2); l967 = (l967 + 1)) {
			fRec1407[l967] = 0.0;
			
		}
		for (int l968 = 0; (l968 < 2); l968 = (l968 + 1)) {
			fRec1405[l968] = 0.0;
			
		}
		for (int l969 = 0; (l969 < 2); l969 = (l969 + 1)) {
			fRec1404[l969] = 0.0;
			
		}
		for (int l970 = 0; (l970 < 2); l970 = (l970 + 1)) {
			fRec1402[l970] = 0.0;
			
		}
		for (int l971 = 0; (l971 < 2); l971 = (l971 + 1)) {
			fRec1401[l971] = 0.0;
			
		}
		for (int l972 = 0; (l972 < 2); l972 = (l972 + 1)) {
			fRec1399[l972] = 0.0;
			
		}
		for (int l973 = 0; (l973 < 2); l973 = (l973 + 1)) {
			fRec1398[l973] = 0.0;
			
		}
		for (int l974 = 0; (l974 < 2); l974 = (l974 + 1)) {
			fRec1396[l974] = 0.0;
			
		}
		for (int l975 = 0; (l975 < 2); l975 = (l975 + 1)) {
			fRec1395[l975] = 0.0;
			
		}
		for (int l976 = 0; (l976 < 2); l976 = (l976 + 1)) {
			fRec1393[l976] = 0.0;
			
		}
		for (int l977 = 0; (l977 < 2); l977 = (l977 + 1)) {
			fRec1419[l977] = 0.0;
			
		}
		for (int l978 = 0; (l978 < 2); l978 = (l978 + 1)) {
			fRec1417[l978] = 0.0;
			
		}
		for (int l979 = 0; (l979 < 2); l979 = (l979 + 1)) {
			fRec1416[l979] = 0.0;
			
		}
		for (int l980 = 0; (l980 < 2); l980 = (l980 + 1)) {
			fRec1414[l980] = 0.0;
			
		}
		for (int l981 = 0; (l981 < 2); l981 = (l981 + 1)) {
			fRec1413[l981] = 0.0;
			
		}
		for (int l982 = 0; (l982 < 2); l982 = (l982 + 1)) {
			fRec1411[l982] = 0.0;
			
		}
		for (int l983 = 0; (l983 < 2); l983 = (l983 + 1)) {
			fRec1410[l983] = 0.0;
			
		}
		for (int l984 = 0; (l984 < 2); l984 = (l984 + 1)) {
			fRec1408[l984] = 0.0;
			
		}
		for (int l985 = 0; (l985 < 2); l985 = (l985 + 1)) {
			fRec1428[l985] = 0.0;
			
		}
		for (int l986 = 0; (l986 < 2); l986 = (l986 + 1)) {
			fRec1426[l986] = 0.0;
			
		}
		for (int l987 = 0; (l987 < 2); l987 = (l987 + 1)) {
			fRec1425[l987] = 0.0;
			
		}
		for (int l988 = 0; (l988 < 2); l988 = (l988 + 1)) {
			fRec1423[l988] = 0.0;
			
		}
		for (int l989 = 0; (l989 < 2); l989 = (l989 + 1)) {
			fRec1422[l989] = 0.0;
			
		}
		for (int l990 = 0; (l990 < 2); l990 = (l990 + 1)) {
			fRec1420[l990] = 0.0;
			
		}
		for (int l991 = 0; (l991 < 2); l991 = (l991 + 1)) {
			fRec1431[l991] = 0.0;
			
		}
		for (int l992 = 0; (l992 < 2); l992 = (l992 + 1)) {
			fRec1429[l992] = 0.0;
			
		}
		for (int l993 = 0; (l993 < 2); l993 = (l993 + 1)) {
			fRec1437[l993] = 0.0;
			
		}
		for (int l994 = 0; (l994 < 2); l994 = (l994 + 1)) {
			fRec1435[l994] = 0.0;
			
		}
		for (int l995 = 0; (l995 < 2); l995 = (l995 + 1)) {
			fRec1434[l995] = 0.0;
			
		}
		for (int l996 = 0; (l996 < 2); l996 = (l996 + 1)) {
			fRec1432[l996] = 0.0;
			
		}
		for (int l997 = 0; (l997 < 128); l997 = (l997 + 1)) {
			fVec21[l997] = 0.0;
			
		}
		for (int l998 = 0; (l998 < 2); l998 = (l998 + 1)) {
			fRec1455[l998] = 0.0;
			
		}
		for (int l999 = 0; (l999 < 2); l999 = (l999 + 1)) {
			fRec1453[l999] = 0.0;
			
		}
		for (int l1000 = 0; (l1000 < 2); l1000 = (l1000 + 1)) {
			fRec1452[l1000] = 0.0;
			
		}
		for (int l1001 = 0; (l1001 < 2); l1001 = (l1001 + 1)) {
			fRec1450[l1001] = 0.0;
			
		}
		for (int l1002 = 0; (l1002 < 2); l1002 = (l1002 + 1)) {
			fRec1449[l1002] = 0.0;
			
		}
		for (int l1003 = 0; (l1003 < 2); l1003 = (l1003 + 1)) {
			fRec1447[l1003] = 0.0;
			
		}
		for (int l1004 = 0; (l1004 < 2); l1004 = (l1004 + 1)) {
			fRec1446[l1004] = 0.0;
			
		}
		for (int l1005 = 0; (l1005 < 2); l1005 = (l1005 + 1)) {
			fRec1444[l1005] = 0.0;
			
		}
		for (int l1006 = 0; (l1006 < 2); l1006 = (l1006 + 1)) {
			fRec1443[l1006] = 0.0;
			
		}
		for (int l1007 = 0; (l1007 < 2); l1007 = (l1007 + 1)) {
			fRec1441[l1007] = 0.0;
			
		}
		for (int l1008 = 0; (l1008 < 2); l1008 = (l1008 + 1)) {
			fRec1440[l1008] = 0.0;
			
		}
		for (int l1009 = 0; (l1009 < 2); l1009 = (l1009 + 1)) {
			fRec1438[l1009] = 0.0;
			
		}
		for (int l1010 = 0; (l1010 < 2); l1010 = (l1010 + 1)) {
			fRec1470[l1010] = 0.0;
			
		}
		for (int l1011 = 0; (l1011 < 2); l1011 = (l1011 + 1)) {
			fRec1468[l1011] = 0.0;
			
		}
		for (int l1012 = 0; (l1012 < 2); l1012 = (l1012 + 1)) {
			fRec1467[l1012] = 0.0;
			
		}
		for (int l1013 = 0; (l1013 < 2); l1013 = (l1013 + 1)) {
			fRec1465[l1013] = 0.0;
			
		}
		for (int l1014 = 0; (l1014 < 2); l1014 = (l1014 + 1)) {
			fRec1464[l1014] = 0.0;
			
		}
		for (int l1015 = 0; (l1015 < 2); l1015 = (l1015 + 1)) {
			fRec1462[l1015] = 0.0;
			
		}
		for (int l1016 = 0; (l1016 < 2); l1016 = (l1016 + 1)) {
			fRec1461[l1016] = 0.0;
			
		}
		for (int l1017 = 0; (l1017 < 2); l1017 = (l1017 + 1)) {
			fRec1459[l1017] = 0.0;
			
		}
		for (int l1018 = 0; (l1018 < 2); l1018 = (l1018 + 1)) {
			fRec1458[l1018] = 0.0;
			
		}
		for (int l1019 = 0; (l1019 < 2); l1019 = (l1019 + 1)) {
			fRec1456[l1019] = 0.0;
			
		}
		for (int l1020 = 0; (l1020 < 2); l1020 = (l1020 + 1)) {
			fRec1482[l1020] = 0.0;
			
		}
		for (int l1021 = 0; (l1021 < 2); l1021 = (l1021 + 1)) {
			fRec1480[l1021] = 0.0;
			
		}
		for (int l1022 = 0; (l1022 < 2); l1022 = (l1022 + 1)) {
			fRec1479[l1022] = 0.0;
			
		}
		for (int l1023 = 0; (l1023 < 2); l1023 = (l1023 + 1)) {
			fRec1477[l1023] = 0.0;
			
		}
		for (int l1024 = 0; (l1024 < 2); l1024 = (l1024 + 1)) {
			fRec1476[l1024] = 0.0;
			
		}
		for (int l1025 = 0; (l1025 < 2); l1025 = (l1025 + 1)) {
			fRec1474[l1025] = 0.0;
			
		}
		for (int l1026 = 0; (l1026 < 2); l1026 = (l1026 + 1)) {
			fRec1473[l1026] = 0.0;
			
		}
		for (int l1027 = 0; (l1027 < 2); l1027 = (l1027 + 1)) {
			fRec1471[l1027] = 0.0;
			
		}
		for (int l1028 = 0; (l1028 < 2); l1028 = (l1028 + 1)) {
			fRec1491[l1028] = 0.0;
			
		}
		for (int l1029 = 0; (l1029 < 2); l1029 = (l1029 + 1)) {
			fRec1489[l1029] = 0.0;
			
		}
		for (int l1030 = 0; (l1030 < 2); l1030 = (l1030 + 1)) {
			fRec1488[l1030] = 0.0;
			
		}
		for (int l1031 = 0; (l1031 < 2); l1031 = (l1031 + 1)) {
			fRec1486[l1031] = 0.0;
			
		}
		for (int l1032 = 0; (l1032 < 2); l1032 = (l1032 + 1)) {
			fRec1485[l1032] = 0.0;
			
		}
		for (int l1033 = 0; (l1033 < 2); l1033 = (l1033 + 1)) {
			fRec1483[l1033] = 0.0;
			
		}
		for (int l1034 = 0; (l1034 < 2); l1034 = (l1034 + 1)) {
			fRec1494[l1034] = 0.0;
			
		}
		for (int l1035 = 0; (l1035 < 2); l1035 = (l1035 + 1)) {
			fRec1492[l1035] = 0.0;
			
		}
		for (int l1036 = 0; (l1036 < 2); l1036 = (l1036 + 1)) {
			fRec1500[l1036] = 0.0;
			
		}
		for (int l1037 = 0; (l1037 < 2); l1037 = (l1037 + 1)) {
			fRec1498[l1037] = 0.0;
			
		}
		for (int l1038 = 0; (l1038 < 2); l1038 = (l1038 + 1)) {
			fRec1497[l1038] = 0.0;
			
		}
		for (int l1039 = 0; (l1039 < 2); l1039 = (l1039 + 1)) {
			fRec1495[l1039] = 0.0;
			
		}
		for (int l1040 = 0; (l1040 < 128); l1040 = (l1040 + 1)) {
			fVec22[l1040] = 0.0;
			
		}
		for (int l1041 = 0; (l1041 < 2); l1041 = (l1041 + 1)) {
			fRec1518[l1041] = 0.0;
			
		}
		for (int l1042 = 0; (l1042 < 2); l1042 = (l1042 + 1)) {
			fRec1516[l1042] = 0.0;
			
		}
		for (int l1043 = 0; (l1043 < 2); l1043 = (l1043 + 1)) {
			fRec1515[l1043] = 0.0;
			
		}
		for (int l1044 = 0; (l1044 < 2); l1044 = (l1044 + 1)) {
			fRec1513[l1044] = 0.0;
			
		}
		for (int l1045 = 0; (l1045 < 2); l1045 = (l1045 + 1)) {
			fRec1512[l1045] = 0.0;
			
		}
		for (int l1046 = 0; (l1046 < 2); l1046 = (l1046 + 1)) {
			fRec1510[l1046] = 0.0;
			
		}
		for (int l1047 = 0; (l1047 < 2); l1047 = (l1047 + 1)) {
			fRec1509[l1047] = 0.0;
			
		}
		for (int l1048 = 0; (l1048 < 2); l1048 = (l1048 + 1)) {
			fRec1507[l1048] = 0.0;
			
		}
		for (int l1049 = 0; (l1049 < 2); l1049 = (l1049 + 1)) {
			fRec1506[l1049] = 0.0;
			
		}
		for (int l1050 = 0; (l1050 < 2); l1050 = (l1050 + 1)) {
			fRec1504[l1050] = 0.0;
			
		}
		for (int l1051 = 0; (l1051 < 2); l1051 = (l1051 + 1)) {
			fRec1503[l1051] = 0.0;
			
		}
		for (int l1052 = 0; (l1052 < 2); l1052 = (l1052 + 1)) {
			fRec1501[l1052] = 0.0;
			
		}
		for (int l1053 = 0; (l1053 < 2); l1053 = (l1053 + 1)) {
			fRec1533[l1053] = 0.0;
			
		}
		for (int l1054 = 0; (l1054 < 2); l1054 = (l1054 + 1)) {
			fRec1531[l1054] = 0.0;
			
		}
		for (int l1055 = 0; (l1055 < 2); l1055 = (l1055 + 1)) {
			fRec1530[l1055] = 0.0;
			
		}
		for (int l1056 = 0; (l1056 < 2); l1056 = (l1056 + 1)) {
			fRec1528[l1056] = 0.0;
			
		}
		for (int l1057 = 0; (l1057 < 2); l1057 = (l1057 + 1)) {
			fRec1527[l1057] = 0.0;
			
		}
		for (int l1058 = 0; (l1058 < 2); l1058 = (l1058 + 1)) {
			fRec1525[l1058] = 0.0;
			
		}
		for (int l1059 = 0; (l1059 < 2); l1059 = (l1059 + 1)) {
			fRec1524[l1059] = 0.0;
			
		}
		for (int l1060 = 0; (l1060 < 2); l1060 = (l1060 + 1)) {
			fRec1522[l1060] = 0.0;
			
		}
		for (int l1061 = 0; (l1061 < 2); l1061 = (l1061 + 1)) {
			fRec1521[l1061] = 0.0;
			
		}
		for (int l1062 = 0; (l1062 < 2); l1062 = (l1062 + 1)) {
			fRec1519[l1062] = 0.0;
			
		}
		for (int l1063 = 0; (l1063 < 2); l1063 = (l1063 + 1)) {
			fRec1545[l1063] = 0.0;
			
		}
		for (int l1064 = 0; (l1064 < 2); l1064 = (l1064 + 1)) {
			fRec1543[l1064] = 0.0;
			
		}
		for (int l1065 = 0; (l1065 < 2); l1065 = (l1065 + 1)) {
			fRec1542[l1065] = 0.0;
			
		}
		for (int l1066 = 0; (l1066 < 2); l1066 = (l1066 + 1)) {
			fRec1540[l1066] = 0.0;
			
		}
		for (int l1067 = 0; (l1067 < 2); l1067 = (l1067 + 1)) {
			fRec1539[l1067] = 0.0;
			
		}
		for (int l1068 = 0; (l1068 < 2); l1068 = (l1068 + 1)) {
			fRec1537[l1068] = 0.0;
			
		}
		for (int l1069 = 0; (l1069 < 2); l1069 = (l1069 + 1)) {
			fRec1536[l1069] = 0.0;
			
		}
		for (int l1070 = 0; (l1070 < 2); l1070 = (l1070 + 1)) {
			fRec1534[l1070] = 0.0;
			
		}
		for (int l1071 = 0; (l1071 < 2); l1071 = (l1071 + 1)) {
			fRec1554[l1071] = 0.0;
			
		}
		for (int l1072 = 0; (l1072 < 2); l1072 = (l1072 + 1)) {
			fRec1552[l1072] = 0.0;
			
		}
		for (int l1073 = 0; (l1073 < 2); l1073 = (l1073 + 1)) {
			fRec1551[l1073] = 0.0;
			
		}
		for (int l1074 = 0; (l1074 < 2); l1074 = (l1074 + 1)) {
			fRec1549[l1074] = 0.0;
			
		}
		for (int l1075 = 0; (l1075 < 2); l1075 = (l1075 + 1)) {
			fRec1548[l1075] = 0.0;
			
		}
		for (int l1076 = 0; (l1076 < 2); l1076 = (l1076 + 1)) {
			fRec1546[l1076] = 0.0;
			
		}
		for (int l1077 = 0; (l1077 < 2); l1077 = (l1077 + 1)) {
			fRec1557[l1077] = 0.0;
			
		}
		for (int l1078 = 0; (l1078 < 2); l1078 = (l1078 + 1)) {
			fRec1555[l1078] = 0.0;
			
		}
		for (int l1079 = 0; (l1079 < 2); l1079 = (l1079 + 1)) {
			fRec1563[l1079] = 0.0;
			
		}
		for (int l1080 = 0; (l1080 < 2); l1080 = (l1080 + 1)) {
			fRec1561[l1080] = 0.0;
			
		}
		for (int l1081 = 0; (l1081 < 2); l1081 = (l1081 + 1)) {
			fRec1560[l1081] = 0.0;
			
		}
		for (int l1082 = 0; (l1082 < 2); l1082 = (l1082 + 1)) {
			fRec1558[l1082] = 0.0;
			
		}
		for (int l1083 = 0; (l1083 < 128); l1083 = (l1083 + 1)) {
			fVec23[l1083] = 0.0;
			
		}
		for (int l1084 = 0; (l1084 < 2); l1084 = (l1084 + 1)) {
			fRec1581[l1084] = 0.0;
			
		}
		for (int l1085 = 0; (l1085 < 2); l1085 = (l1085 + 1)) {
			fRec1579[l1085] = 0.0;
			
		}
		for (int l1086 = 0; (l1086 < 2); l1086 = (l1086 + 1)) {
			fRec1578[l1086] = 0.0;
			
		}
		for (int l1087 = 0; (l1087 < 2); l1087 = (l1087 + 1)) {
			fRec1576[l1087] = 0.0;
			
		}
		for (int l1088 = 0; (l1088 < 2); l1088 = (l1088 + 1)) {
			fRec1575[l1088] = 0.0;
			
		}
		for (int l1089 = 0; (l1089 < 2); l1089 = (l1089 + 1)) {
			fRec1573[l1089] = 0.0;
			
		}
		for (int l1090 = 0; (l1090 < 2); l1090 = (l1090 + 1)) {
			fRec1572[l1090] = 0.0;
			
		}
		for (int l1091 = 0; (l1091 < 2); l1091 = (l1091 + 1)) {
			fRec1570[l1091] = 0.0;
			
		}
		for (int l1092 = 0; (l1092 < 2); l1092 = (l1092 + 1)) {
			fRec1569[l1092] = 0.0;
			
		}
		for (int l1093 = 0; (l1093 < 2); l1093 = (l1093 + 1)) {
			fRec1567[l1093] = 0.0;
			
		}
		for (int l1094 = 0; (l1094 < 2); l1094 = (l1094 + 1)) {
			fRec1566[l1094] = 0.0;
			
		}
		for (int l1095 = 0; (l1095 < 2); l1095 = (l1095 + 1)) {
			fRec1564[l1095] = 0.0;
			
		}
		for (int l1096 = 0; (l1096 < 2); l1096 = (l1096 + 1)) {
			fRec1596[l1096] = 0.0;
			
		}
		for (int l1097 = 0; (l1097 < 2); l1097 = (l1097 + 1)) {
			fRec1594[l1097] = 0.0;
			
		}
		for (int l1098 = 0; (l1098 < 2); l1098 = (l1098 + 1)) {
			fRec1593[l1098] = 0.0;
			
		}
		for (int l1099 = 0; (l1099 < 2); l1099 = (l1099 + 1)) {
			fRec1591[l1099] = 0.0;
			
		}
		for (int l1100 = 0; (l1100 < 2); l1100 = (l1100 + 1)) {
			fRec1590[l1100] = 0.0;
			
		}
		for (int l1101 = 0; (l1101 < 2); l1101 = (l1101 + 1)) {
			fRec1588[l1101] = 0.0;
			
		}
		for (int l1102 = 0; (l1102 < 2); l1102 = (l1102 + 1)) {
			fRec1587[l1102] = 0.0;
			
		}
		for (int l1103 = 0; (l1103 < 2); l1103 = (l1103 + 1)) {
			fRec1585[l1103] = 0.0;
			
		}
		for (int l1104 = 0; (l1104 < 2); l1104 = (l1104 + 1)) {
			fRec1584[l1104] = 0.0;
			
		}
		for (int l1105 = 0; (l1105 < 2); l1105 = (l1105 + 1)) {
			fRec1582[l1105] = 0.0;
			
		}
		for (int l1106 = 0; (l1106 < 2); l1106 = (l1106 + 1)) {
			fRec1608[l1106] = 0.0;
			
		}
		for (int l1107 = 0; (l1107 < 2); l1107 = (l1107 + 1)) {
			fRec1606[l1107] = 0.0;
			
		}
		for (int l1108 = 0; (l1108 < 2); l1108 = (l1108 + 1)) {
			fRec1605[l1108] = 0.0;
			
		}
		for (int l1109 = 0; (l1109 < 2); l1109 = (l1109 + 1)) {
			fRec1603[l1109] = 0.0;
			
		}
		for (int l1110 = 0; (l1110 < 2); l1110 = (l1110 + 1)) {
			fRec1602[l1110] = 0.0;
			
		}
		for (int l1111 = 0; (l1111 < 2); l1111 = (l1111 + 1)) {
			fRec1600[l1111] = 0.0;
			
		}
		for (int l1112 = 0; (l1112 < 2); l1112 = (l1112 + 1)) {
			fRec1599[l1112] = 0.0;
			
		}
		for (int l1113 = 0; (l1113 < 2); l1113 = (l1113 + 1)) {
			fRec1597[l1113] = 0.0;
			
		}
		for (int l1114 = 0; (l1114 < 2); l1114 = (l1114 + 1)) {
			fRec1617[l1114] = 0.0;
			
		}
		for (int l1115 = 0; (l1115 < 2); l1115 = (l1115 + 1)) {
			fRec1615[l1115] = 0.0;
			
		}
		for (int l1116 = 0; (l1116 < 2); l1116 = (l1116 + 1)) {
			fRec1614[l1116] = 0.0;
			
		}
		for (int l1117 = 0; (l1117 < 2); l1117 = (l1117 + 1)) {
			fRec1612[l1117] = 0.0;
			
		}
		for (int l1118 = 0; (l1118 < 2); l1118 = (l1118 + 1)) {
			fRec1611[l1118] = 0.0;
			
		}
		for (int l1119 = 0; (l1119 < 2); l1119 = (l1119 + 1)) {
			fRec1609[l1119] = 0.0;
			
		}
		for (int l1120 = 0; (l1120 < 2); l1120 = (l1120 + 1)) {
			fRec1620[l1120] = 0.0;
			
		}
		for (int l1121 = 0; (l1121 < 2); l1121 = (l1121 + 1)) {
			fRec1618[l1121] = 0.0;
			
		}
		for (int l1122 = 0; (l1122 < 2); l1122 = (l1122 + 1)) {
			fRec1626[l1122] = 0.0;
			
		}
		for (int l1123 = 0; (l1123 < 2); l1123 = (l1123 + 1)) {
			fRec1624[l1123] = 0.0;
			
		}
		for (int l1124 = 0; (l1124 < 2); l1124 = (l1124 + 1)) {
			fRec1623[l1124] = 0.0;
			
		}
		for (int l1125 = 0; (l1125 < 2); l1125 = (l1125 + 1)) {
			fRec1621[l1125] = 0.0;
			
		}
		for (int l1126 = 0; (l1126 < 12); l1126 = (l1126 + 1)) {
			fVec24[l1126] = 0.0;
			
		}
		for (int l1127 = 0; (l1127 < 2); l1127 = (l1127 + 1)) {
			fRec1638[l1127] = 0.0;
			
		}
		for (int l1128 = 0; (l1128 < 2); l1128 = (l1128 + 1)) {
			fRec1636[l1128] = 0.0;
			
		}
		for (int l1129 = 0; (l1129 < 2); l1129 = (l1129 + 1)) {
			fRec1635[l1129] = 0.0;
			
		}
		for (int l1130 = 0; (l1130 < 2); l1130 = (l1130 + 1)) {
			fRec1633[l1130] = 0.0;
			
		}
		for (int l1131 = 0; (l1131 < 2); l1131 = (l1131 + 1)) {
			fRec1632[l1131] = 0.0;
			
		}
		for (int l1132 = 0; (l1132 < 2); l1132 = (l1132 + 1)) {
			fRec1630[l1132] = 0.0;
			
		}
		for (int l1133 = 0; (l1133 < 2); l1133 = (l1133 + 1)) {
			fRec1629[l1133] = 0.0;
			
		}
		for (int l1134 = 0; (l1134 < 2); l1134 = (l1134 + 1)) {
			fRec1627[l1134] = 0.0;
			
		}
		for (int l1135 = 0; (l1135 < 2); l1135 = (l1135 + 1)) {
			fRec1647[l1135] = 0.0;
			
		}
		for (int l1136 = 0; (l1136 < 2); l1136 = (l1136 + 1)) {
			fRec1645[l1136] = 0.0;
			
		}
		for (int l1137 = 0; (l1137 < 2); l1137 = (l1137 + 1)) {
			fRec1644[l1137] = 0.0;
			
		}
		for (int l1138 = 0; (l1138 < 2); l1138 = (l1138 + 1)) {
			fRec1642[l1138] = 0.0;
			
		}
		for (int l1139 = 0; (l1139 < 2); l1139 = (l1139 + 1)) {
			fRec1641[l1139] = 0.0;
			
		}
		for (int l1140 = 0; (l1140 < 2); l1140 = (l1140 + 1)) {
			fRec1639[l1140] = 0.0;
			
		}
		for (int l1141 = 0; (l1141 < 2); l1141 = (l1141 + 1)) {
			fRec1653[l1141] = 0.0;
			
		}
		for (int l1142 = 0; (l1142 < 2); l1142 = (l1142 + 1)) {
			fRec1651[l1142] = 0.0;
			
		}
		for (int l1143 = 0; (l1143 < 2); l1143 = (l1143 + 1)) {
			fRec1650[l1143] = 0.0;
			
		}
		for (int l1144 = 0; (l1144 < 2); l1144 = (l1144 + 1)) {
			fRec1648[l1144] = 0.0;
			
		}
		for (int l1145 = 0; (l1145 < 2); l1145 = (l1145 + 1)) {
			fRec1656[l1145] = 0.0;
			
		}
		for (int l1146 = 0; (l1146 < 2); l1146 = (l1146 + 1)) {
			fRec1654[l1146] = 0.0;
			
		}
		for (int l1147 = 0; (l1147 < 2); l1147 = (l1147 + 1)) {
			fRec1671[l1147] = 0.0;
			
		}
		for (int l1148 = 0; (l1148 < 2); l1148 = (l1148 + 1)) {
			fRec1669[l1148] = 0.0;
			
		}
		for (int l1149 = 0; (l1149 < 2); l1149 = (l1149 + 1)) {
			fRec1668[l1149] = 0.0;
			
		}
		for (int l1150 = 0; (l1150 < 2); l1150 = (l1150 + 1)) {
			fRec1666[l1150] = 0.0;
			
		}
		for (int l1151 = 0; (l1151 < 2); l1151 = (l1151 + 1)) {
			fRec1665[l1151] = 0.0;
			
		}
		for (int l1152 = 0; (l1152 < 2); l1152 = (l1152 + 1)) {
			fRec1663[l1152] = 0.0;
			
		}
		for (int l1153 = 0; (l1153 < 2); l1153 = (l1153 + 1)) {
			fRec1662[l1153] = 0.0;
			
		}
		for (int l1154 = 0; (l1154 < 2); l1154 = (l1154 + 1)) {
			fRec1660[l1154] = 0.0;
			
		}
		for (int l1155 = 0; (l1155 < 2); l1155 = (l1155 + 1)) {
			fRec1659[l1155] = 0.0;
			
		}
		for (int l1156 = 0; (l1156 < 2); l1156 = (l1156 + 1)) {
			fRec1657[l1156] = 0.0;
			
		}
		for (int l1157 = 0; (l1157 < 2); l1157 = (l1157 + 1)) {
			fRec1689[l1157] = 0.0;
			
		}
		for (int l1158 = 0; (l1158 < 2); l1158 = (l1158 + 1)) {
			fRec1687[l1158] = 0.0;
			
		}
		for (int l1159 = 0; (l1159 < 2); l1159 = (l1159 + 1)) {
			fRec1686[l1159] = 0.0;
			
		}
		for (int l1160 = 0; (l1160 < 2); l1160 = (l1160 + 1)) {
			fRec1684[l1160] = 0.0;
			
		}
		for (int l1161 = 0; (l1161 < 2); l1161 = (l1161 + 1)) {
			fRec1683[l1161] = 0.0;
			
		}
		for (int l1162 = 0; (l1162 < 2); l1162 = (l1162 + 1)) {
			fRec1681[l1162] = 0.0;
			
		}
		for (int l1163 = 0; (l1163 < 2); l1163 = (l1163 + 1)) {
			fRec1680[l1163] = 0.0;
			
		}
		for (int l1164 = 0; (l1164 < 2); l1164 = (l1164 + 1)) {
			fRec1678[l1164] = 0.0;
			
		}
		for (int l1165 = 0; (l1165 < 2); l1165 = (l1165 + 1)) {
			fRec1677[l1165] = 0.0;
			
		}
		for (int l1166 = 0; (l1166 < 2); l1166 = (l1166 + 1)) {
			fRec1675[l1166] = 0.0;
			
		}
		for (int l1167 = 0; (l1167 < 2); l1167 = (l1167 + 1)) {
			fRec1674[l1167] = 0.0;
			
		}
		for (int l1168 = 0; (l1168 < 2); l1168 = (l1168 + 1)) {
			fRec1672[l1168] = 0.0;
			
		}
		for (int l1169 = 0; (l1169 < 12); l1169 = (l1169 + 1)) {
			fVec25[l1169] = 0.0;
			
		}
		for (int l1170 = 0; (l1170 < 2); l1170 = (l1170 + 1)) {
			fRec1707[l1170] = 0.0;
			
		}
		for (int l1171 = 0; (l1171 < 2); l1171 = (l1171 + 1)) {
			fRec1705[l1171] = 0.0;
			
		}
		for (int l1172 = 0; (l1172 < 2); l1172 = (l1172 + 1)) {
			fRec1704[l1172] = 0.0;
			
		}
		for (int l1173 = 0; (l1173 < 2); l1173 = (l1173 + 1)) {
			fRec1702[l1173] = 0.0;
			
		}
		for (int l1174 = 0; (l1174 < 2); l1174 = (l1174 + 1)) {
			fRec1701[l1174] = 0.0;
			
		}
		for (int l1175 = 0; (l1175 < 2); l1175 = (l1175 + 1)) {
			fRec1699[l1175] = 0.0;
			
		}
		for (int l1176 = 0; (l1176 < 2); l1176 = (l1176 + 1)) {
			fRec1698[l1176] = 0.0;
			
		}
		for (int l1177 = 0; (l1177 < 2); l1177 = (l1177 + 1)) {
			fRec1696[l1177] = 0.0;
			
		}
		for (int l1178 = 0; (l1178 < 2); l1178 = (l1178 + 1)) {
			fRec1695[l1178] = 0.0;
			
		}
		for (int l1179 = 0; (l1179 < 2); l1179 = (l1179 + 1)) {
			fRec1693[l1179] = 0.0;
			
		}
		for (int l1180 = 0; (l1180 < 2); l1180 = (l1180 + 1)) {
			fRec1692[l1180] = 0.0;
			
		}
		for (int l1181 = 0; (l1181 < 2); l1181 = (l1181 + 1)) {
			fRec1690[l1181] = 0.0;
			
		}
		for (int l1182 = 0; (l1182 < 2); l1182 = (l1182 + 1)) {
			fRec1722[l1182] = 0.0;
			
		}
		for (int l1183 = 0; (l1183 < 2); l1183 = (l1183 + 1)) {
			fRec1720[l1183] = 0.0;
			
		}
		for (int l1184 = 0; (l1184 < 2); l1184 = (l1184 + 1)) {
			fRec1719[l1184] = 0.0;
			
		}
		for (int l1185 = 0; (l1185 < 2); l1185 = (l1185 + 1)) {
			fRec1717[l1185] = 0.0;
			
		}
		for (int l1186 = 0; (l1186 < 2); l1186 = (l1186 + 1)) {
			fRec1716[l1186] = 0.0;
			
		}
		for (int l1187 = 0; (l1187 < 2); l1187 = (l1187 + 1)) {
			fRec1714[l1187] = 0.0;
			
		}
		for (int l1188 = 0; (l1188 < 2); l1188 = (l1188 + 1)) {
			fRec1713[l1188] = 0.0;
			
		}
		for (int l1189 = 0; (l1189 < 2); l1189 = (l1189 + 1)) {
			fRec1711[l1189] = 0.0;
			
		}
		for (int l1190 = 0; (l1190 < 2); l1190 = (l1190 + 1)) {
			fRec1710[l1190] = 0.0;
			
		}
		for (int l1191 = 0; (l1191 < 2); l1191 = (l1191 + 1)) {
			fRec1708[l1191] = 0.0;
			
		}
		for (int l1192 = 0; (l1192 < 2); l1192 = (l1192 + 1)) {
			fRec1734[l1192] = 0.0;
			
		}
		for (int l1193 = 0; (l1193 < 2); l1193 = (l1193 + 1)) {
			fRec1732[l1193] = 0.0;
			
		}
		for (int l1194 = 0; (l1194 < 2); l1194 = (l1194 + 1)) {
			fRec1731[l1194] = 0.0;
			
		}
		for (int l1195 = 0; (l1195 < 2); l1195 = (l1195 + 1)) {
			fRec1729[l1195] = 0.0;
			
		}
		for (int l1196 = 0; (l1196 < 2); l1196 = (l1196 + 1)) {
			fRec1728[l1196] = 0.0;
			
		}
		for (int l1197 = 0; (l1197 < 2); l1197 = (l1197 + 1)) {
			fRec1726[l1197] = 0.0;
			
		}
		for (int l1198 = 0; (l1198 < 2); l1198 = (l1198 + 1)) {
			fRec1725[l1198] = 0.0;
			
		}
		for (int l1199 = 0; (l1199 < 2); l1199 = (l1199 + 1)) {
			fRec1723[l1199] = 0.0;
			
		}
		for (int l1200 = 0; (l1200 < 2); l1200 = (l1200 + 1)) {
			fRec1743[l1200] = 0.0;
			
		}
		for (int l1201 = 0; (l1201 < 2); l1201 = (l1201 + 1)) {
			fRec1741[l1201] = 0.0;
			
		}
		for (int l1202 = 0; (l1202 < 2); l1202 = (l1202 + 1)) {
			fRec1740[l1202] = 0.0;
			
		}
		for (int l1203 = 0; (l1203 < 2); l1203 = (l1203 + 1)) {
			fRec1738[l1203] = 0.0;
			
		}
		for (int l1204 = 0; (l1204 < 2); l1204 = (l1204 + 1)) {
			fRec1737[l1204] = 0.0;
			
		}
		for (int l1205 = 0; (l1205 < 2); l1205 = (l1205 + 1)) {
			fRec1735[l1205] = 0.0;
			
		}
		for (int l1206 = 0; (l1206 < 2); l1206 = (l1206 + 1)) {
			fRec1746[l1206] = 0.0;
			
		}
		for (int l1207 = 0; (l1207 < 2); l1207 = (l1207 + 1)) {
			fRec1744[l1207] = 0.0;
			
		}
		for (int l1208 = 0; (l1208 < 2); l1208 = (l1208 + 1)) {
			fRec1752[l1208] = 0.0;
			
		}
		for (int l1209 = 0; (l1209 < 2); l1209 = (l1209 + 1)) {
			fRec1750[l1209] = 0.0;
			
		}
		for (int l1210 = 0; (l1210 < 2); l1210 = (l1210 + 1)) {
			fRec1749[l1210] = 0.0;
			
		}
		for (int l1211 = 0; (l1211 < 2); l1211 = (l1211 + 1)) {
			fRec1747[l1211] = 0.0;
			
		}
		for (int l1212 = 0; (l1212 < 12); l1212 = (l1212 + 1)) {
			fVec26[l1212] = 0.0;
			
		}
		for (int l1213 = 0; (l1213 < 2); l1213 = (l1213 + 1)) {
			fRec1770[l1213] = 0.0;
			
		}
		for (int l1214 = 0; (l1214 < 2); l1214 = (l1214 + 1)) {
			fRec1768[l1214] = 0.0;
			
		}
		for (int l1215 = 0; (l1215 < 2); l1215 = (l1215 + 1)) {
			fRec1767[l1215] = 0.0;
			
		}
		for (int l1216 = 0; (l1216 < 2); l1216 = (l1216 + 1)) {
			fRec1765[l1216] = 0.0;
			
		}
		for (int l1217 = 0; (l1217 < 2); l1217 = (l1217 + 1)) {
			fRec1764[l1217] = 0.0;
			
		}
		for (int l1218 = 0; (l1218 < 2); l1218 = (l1218 + 1)) {
			fRec1762[l1218] = 0.0;
			
		}
		for (int l1219 = 0; (l1219 < 2); l1219 = (l1219 + 1)) {
			fRec1761[l1219] = 0.0;
			
		}
		for (int l1220 = 0; (l1220 < 2); l1220 = (l1220 + 1)) {
			fRec1759[l1220] = 0.0;
			
		}
		for (int l1221 = 0; (l1221 < 2); l1221 = (l1221 + 1)) {
			fRec1758[l1221] = 0.0;
			
		}
		for (int l1222 = 0; (l1222 < 2); l1222 = (l1222 + 1)) {
			fRec1756[l1222] = 0.0;
			
		}
		for (int l1223 = 0; (l1223 < 2); l1223 = (l1223 + 1)) {
			fRec1755[l1223] = 0.0;
			
		}
		for (int l1224 = 0; (l1224 < 2); l1224 = (l1224 + 1)) {
			fRec1753[l1224] = 0.0;
			
		}
		for (int l1225 = 0; (l1225 < 2); l1225 = (l1225 + 1)) {
			fRec1785[l1225] = 0.0;
			
		}
		for (int l1226 = 0; (l1226 < 2); l1226 = (l1226 + 1)) {
			fRec1783[l1226] = 0.0;
			
		}
		for (int l1227 = 0; (l1227 < 2); l1227 = (l1227 + 1)) {
			fRec1782[l1227] = 0.0;
			
		}
		for (int l1228 = 0; (l1228 < 2); l1228 = (l1228 + 1)) {
			fRec1780[l1228] = 0.0;
			
		}
		for (int l1229 = 0; (l1229 < 2); l1229 = (l1229 + 1)) {
			fRec1779[l1229] = 0.0;
			
		}
		for (int l1230 = 0; (l1230 < 2); l1230 = (l1230 + 1)) {
			fRec1777[l1230] = 0.0;
			
		}
		for (int l1231 = 0; (l1231 < 2); l1231 = (l1231 + 1)) {
			fRec1776[l1231] = 0.0;
			
		}
		for (int l1232 = 0; (l1232 < 2); l1232 = (l1232 + 1)) {
			fRec1774[l1232] = 0.0;
			
		}
		for (int l1233 = 0; (l1233 < 2); l1233 = (l1233 + 1)) {
			fRec1773[l1233] = 0.0;
			
		}
		for (int l1234 = 0; (l1234 < 2); l1234 = (l1234 + 1)) {
			fRec1771[l1234] = 0.0;
			
		}
		for (int l1235 = 0; (l1235 < 2); l1235 = (l1235 + 1)) {
			fRec1797[l1235] = 0.0;
			
		}
		for (int l1236 = 0; (l1236 < 2); l1236 = (l1236 + 1)) {
			fRec1795[l1236] = 0.0;
			
		}
		for (int l1237 = 0; (l1237 < 2); l1237 = (l1237 + 1)) {
			fRec1794[l1237] = 0.0;
			
		}
		for (int l1238 = 0; (l1238 < 2); l1238 = (l1238 + 1)) {
			fRec1792[l1238] = 0.0;
			
		}
		for (int l1239 = 0; (l1239 < 2); l1239 = (l1239 + 1)) {
			fRec1791[l1239] = 0.0;
			
		}
		for (int l1240 = 0; (l1240 < 2); l1240 = (l1240 + 1)) {
			fRec1789[l1240] = 0.0;
			
		}
		for (int l1241 = 0; (l1241 < 2); l1241 = (l1241 + 1)) {
			fRec1788[l1241] = 0.0;
			
		}
		for (int l1242 = 0; (l1242 < 2); l1242 = (l1242 + 1)) {
			fRec1786[l1242] = 0.0;
			
		}
		for (int l1243 = 0; (l1243 < 2); l1243 = (l1243 + 1)) {
			fRec1806[l1243] = 0.0;
			
		}
		for (int l1244 = 0; (l1244 < 2); l1244 = (l1244 + 1)) {
			fRec1804[l1244] = 0.0;
			
		}
		for (int l1245 = 0; (l1245 < 2); l1245 = (l1245 + 1)) {
			fRec1803[l1245] = 0.0;
			
		}
		for (int l1246 = 0; (l1246 < 2); l1246 = (l1246 + 1)) {
			fRec1801[l1246] = 0.0;
			
		}
		for (int l1247 = 0; (l1247 < 2); l1247 = (l1247 + 1)) {
			fRec1800[l1247] = 0.0;
			
		}
		for (int l1248 = 0; (l1248 < 2); l1248 = (l1248 + 1)) {
			fRec1798[l1248] = 0.0;
			
		}
		for (int l1249 = 0; (l1249 < 2); l1249 = (l1249 + 1)) {
			fRec1809[l1249] = 0.0;
			
		}
		for (int l1250 = 0; (l1250 < 2); l1250 = (l1250 + 1)) {
			fRec1807[l1250] = 0.0;
			
		}
		for (int l1251 = 0; (l1251 < 2); l1251 = (l1251 + 1)) {
			fRec1815[l1251] = 0.0;
			
		}
		for (int l1252 = 0; (l1252 < 2); l1252 = (l1252 + 1)) {
			fRec1813[l1252] = 0.0;
			
		}
		for (int l1253 = 0; (l1253 < 2); l1253 = (l1253 + 1)) {
			fRec1812[l1253] = 0.0;
			
		}
		for (int l1254 = 0; (l1254 < 2); l1254 = (l1254 + 1)) {
			fRec1810[l1254] = 0.0;
			
		}
		for (int l1255 = 0; (l1255 < 12); l1255 = (l1255 + 1)) {
			fVec27[l1255] = 0.0;
			
		}
		for (int l1256 = 0; (l1256 < 2); l1256 = (l1256 + 1)) {
			fRec1833[l1256] = 0.0;
			
		}
		for (int l1257 = 0; (l1257 < 2); l1257 = (l1257 + 1)) {
			fRec1831[l1257] = 0.0;
			
		}
		for (int l1258 = 0; (l1258 < 2); l1258 = (l1258 + 1)) {
			fRec1830[l1258] = 0.0;
			
		}
		for (int l1259 = 0; (l1259 < 2); l1259 = (l1259 + 1)) {
			fRec1828[l1259] = 0.0;
			
		}
		for (int l1260 = 0; (l1260 < 2); l1260 = (l1260 + 1)) {
			fRec1827[l1260] = 0.0;
			
		}
		for (int l1261 = 0; (l1261 < 2); l1261 = (l1261 + 1)) {
			fRec1825[l1261] = 0.0;
			
		}
		for (int l1262 = 0; (l1262 < 2); l1262 = (l1262 + 1)) {
			fRec1824[l1262] = 0.0;
			
		}
		for (int l1263 = 0; (l1263 < 2); l1263 = (l1263 + 1)) {
			fRec1822[l1263] = 0.0;
			
		}
		for (int l1264 = 0; (l1264 < 2); l1264 = (l1264 + 1)) {
			fRec1821[l1264] = 0.0;
			
		}
		for (int l1265 = 0; (l1265 < 2); l1265 = (l1265 + 1)) {
			fRec1819[l1265] = 0.0;
			
		}
		for (int l1266 = 0; (l1266 < 2); l1266 = (l1266 + 1)) {
			fRec1818[l1266] = 0.0;
			
		}
		for (int l1267 = 0; (l1267 < 2); l1267 = (l1267 + 1)) {
			fRec1816[l1267] = 0.0;
			
		}
		for (int l1268 = 0; (l1268 < 2); l1268 = (l1268 + 1)) {
			fRec1848[l1268] = 0.0;
			
		}
		for (int l1269 = 0; (l1269 < 2); l1269 = (l1269 + 1)) {
			fRec1846[l1269] = 0.0;
			
		}
		for (int l1270 = 0; (l1270 < 2); l1270 = (l1270 + 1)) {
			fRec1845[l1270] = 0.0;
			
		}
		for (int l1271 = 0; (l1271 < 2); l1271 = (l1271 + 1)) {
			fRec1843[l1271] = 0.0;
			
		}
		for (int l1272 = 0; (l1272 < 2); l1272 = (l1272 + 1)) {
			fRec1842[l1272] = 0.0;
			
		}
		for (int l1273 = 0; (l1273 < 2); l1273 = (l1273 + 1)) {
			fRec1840[l1273] = 0.0;
			
		}
		for (int l1274 = 0; (l1274 < 2); l1274 = (l1274 + 1)) {
			fRec1839[l1274] = 0.0;
			
		}
		for (int l1275 = 0; (l1275 < 2); l1275 = (l1275 + 1)) {
			fRec1837[l1275] = 0.0;
			
		}
		for (int l1276 = 0; (l1276 < 2); l1276 = (l1276 + 1)) {
			fRec1836[l1276] = 0.0;
			
		}
		for (int l1277 = 0; (l1277 < 2); l1277 = (l1277 + 1)) {
			fRec1834[l1277] = 0.0;
			
		}
		for (int l1278 = 0; (l1278 < 2); l1278 = (l1278 + 1)) {
			fRec1860[l1278] = 0.0;
			
		}
		for (int l1279 = 0; (l1279 < 2); l1279 = (l1279 + 1)) {
			fRec1858[l1279] = 0.0;
			
		}
		for (int l1280 = 0; (l1280 < 2); l1280 = (l1280 + 1)) {
			fRec1857[l1280] = 0.0;
			
		}
		for (int l1281 = 0; (l1281 < 2); l1281 = (l1281 + 1)) {
			fRec1855[l1281] = 0.0;
			
		}
		for (int l1282 = 0; (l1282 < 2); l1282 = (l1282 + 1)) {
			fRec1854[l1282] = 0.0;
			
		}
		for (int l1283 = 0; (l1283 < 2); l1283 = (l1283 + 1)) {
			fRec1852[l1283] = 0.0;
			
		}
		for (int l1284 = 0; (l1284 < 2); l1284 = (l1284 + 1)) {
			fRec1851[l1284] = 0.0;
			
		}
		for (int l1285 = 0; (l1285 < 2); l1285 = (l1285 + 1)) {
			fRec1849[l1285] = 0.0;
			
		}
		for (int l1286 = 0; (l1286 < 2); l1286 = (l1286 + 1)) {
			fRec1869[l1286] = 0.0;
			
		}
		for (int l1287 = 0; (l1287 < 2); l1287 = (l1287 + 1)) {
			fRec1867[l1287] = 0.0;
			
		}
		for (int l1288 = 0; (l1288 < 2); l1288 = (l1288 + 1)) {
			fRec1866[l1288] = 0.0;
			
		}
		for (int l1289 = 0; (l1289 < 2); l1289 = (l1289 + 1)) {
			fRec1864[l1289] = 0.0;
			
		}
		for (int l1290 = 0; (l1290 < 2); l1290 = (l1290 + 1)) {
			fRec1863[l1290] = 0.0;
			
		}
		for (int l1291 = 0; (l1291 < 2); l1291 = (l1291 + 1)) {
			fRec1861[l1291] = 0.0;
			
		}
		for (int l1292 = 0; (l1292 < 2); l1292 = (l1292 + 1)) {
			fRec1872[l1292] = 0.0;
			
		}
		for (int l1293 = 0; (l1293 < 2); l1293 = (l1293 + 1)) {
			fRec1870[l1293] = 0.0;
			
		}
		for (int l1294 = 0; (l1294 < 2); l1294 = (l1294 + 1)) {
			fRec1878[l1294] = 0.0;
			
		}
		for (int l1295 = 0; (l1295 < 2); l1295 = (l1295 + 1)) {
			fRec1876[l1295] = 0.0;
			
		}
		for (int l1296 = 0; (l1296 < 2); l1296 = (l1296 + 1)) {
			fRec1875[l1296] = 0.0;
			
		}
		for (int l1297 = 0; (l1297 < 2); l1297 = (l1297 + 1)) {
			fRec1873[l1297] = 0.0;
			
		}
		for (int l1298 = 0; (l1298 < 2); l1298 = (l1298 + 1)) {
			fRec1881[l1298] = 0.0;
			
		}
		for (int l1299 = 0; (l1299 < 2); l1299 = (l1299 + 1)) {
			fRec1879[l1299] = 0.0;
			
		}
		for (int l1300 = 0; (l1300 < 2); l1300 = (l1300 + 1)) {
			fRec1887[l1300] = 0.0;
			
		}
		for (int l1301 = 0; (l1301 < 2); l1301 = (l1301 + 1)) {
			fRec1885[l1301] = 0.0;
			
		}
		for (int l1302 = 0; (l1302 < 2); l1302 = (l1302 + 1)) {
			fRec1884[l1302] = 0.0;
			
		}
		for (int l1303 = 0; (l1303 < 2); l1303 = (l1303 + 1)) {
			fRec1882[l1303] = 0.0;
			
		}
		for (int l1304 = 0; (l1304 < 2); l1304 = (l1304 + 1)) {
			fRec1896[l1304] = 0.0;
			
		}
		for (int l1305 = 0; (l1305 < 2); l1305 = (l1305 + 1)) {
			fRec1894[l1305] = 0.0;
			
		}
		for (int l1306 = 0; (l1306 < 2); l1306 = (l1306 + 1)) {
			fRec1893[l1306] = 0.0;
			
		}
		for (int l1307 = 0; (l1307 < 2); l1307 = (l1307 + 1)) {
			fRec1891[l1307] = 0.0;
			
		}
		for (int l1308 = 0; (l1308 < 2); l1308 = (l1308 + 1)) {
			fRec1890[l1308] = 0.0;
			
		}
		for (int l1309 = 0; (l1309 < 2); l1309 = (l1309 + 1)) {
			fRec1888[l1309] = 0.0;
			
		}
		for (int l1310 = 0; (l1310 < 2); l1310 = (l1310 + 1)) {
			fRec1908[l1310] = 0.0;
			
		}
		for (int l1311 = 0; (l1311 < 2); l1311 = (l1311 + 1)) {
			fRec1906[l1311] = 0.0;
			
		}
		for (int l1312 = 0; (l1312 < 2); l1312 = (l1312 + 1)) {
			fRec1905[l1312] = 0.0;
			
		}
		for (int l1313 = 0; (l1313 < 2); l1313 = (l1313 + 1)) {
			fRec1903[l1313] = 0.0;
			
		}
		for (int l1314 = 0; (l1314 < 2); l1314 = (l1314 + 1)) {
			fRec1902[l1314] = 0.0;
			
		}
		for (int l1315 = 0; (l1315 < 2); l1315 = (l1315 + 1)) {
			fRec1900[l1315] = 0.0;
			
		}
		for (int l1316 = 0; (l1316 < 2); l1316 = (l1316 + 1)) {
			fRec1899[l1316] = 0.0;
			
		}
		for (int l1317 = 0; (l1317 < 2); l1317 = (l1317 + 1)) {
			fRec1897[l1317] = 0.0;
			
		}
		for (int l1318 = 0; (l1318 < 2); l1318 = (l1318 + 1)) {
			fRec1923[l1318] = 0.0;
			
		}
		for (int l1319 = 0; (l1319 < 2); l1319 = (l1319 + 1)) {
			fRec1921[l1319] = 0.0;
			
		}
		for (int l1320 = 0; (l1320 < 2); l1320 = (l1320 + 1)) {
			fRec1920[l1320] = 0.0;
			
		}
		for (int l1321 = 0; (l1321 < 2); l1321 = (l1321 + 1)) {
			fRec1918[l1321] = 0.0;
			
		}
		for (int l1322 = 0; (l1322 < 2); l1322 = (l1322 + 1)) {
			fRec1917[l1322] = 0.0;
			
		}
		for (int l1323 = 0; (l1323 < 2); l1323 = (l1323 + 1)) {
			fRec1915[l1323] = 0.0;
			
		}
		for (int l1324 = 0; (l1324 < 2); l1324 = (l1324 + 1)) {
			fRec1914[l1324] = 0.0;
			
		}
		for (int l1325 = 0; (l1325 < 2); l1325 = (l1325 + 1)) {
			fRec1912[l1325] = 0.0;
			
		}
		for (int l1326 = 0; (l1326 < 2); l1326 = (l1326 + 1)) {
			fRec1911[l1326] = 0.0;
			
		}
		for (int l1327 = 0; (l1327 < 2); l1327 = (l1327 + 1)) {
			fRec1909[l1327] = 0.0;
			
		}
		for (int l1328 = 0; (l1328 < 2); l1328 = (l1328 + 1)) {
			fRec1941[l1328] = 0.0;
			
		}
		for (int l1329 = 0; (l1329 < 2); l1329 = (l1329 + 1)) {
			fRec1939[l1329] = 0.0;
			
		}
		for (int l1330 = 0; (l1330 < 2); l1330 = (l1330 + 1)) {
			fRec1938[l1330] = 0.0;
			
		}
		for (int l1331 = 0; (l1331 < 2); l1331 = (l1331 + 1)) {
			fRec1936[l1331] = 0.0;
			
		}
		for (int l1332 = 0; (l1332 < 2); l1332 = (l1332 + 1)) {
			fRec1935[l1332] = 0.0;
			
		}
		for (int l1333 = 0; (l1333 < 2); l1333 = (l1333 + 1)) {
			fRec1933[l1333] = 0.0;
			
		}
		for (int l1334 = 0; (l1334 < 2); l1334 = (l1334 + 1)) {
			fRec1932[l1334] = 0.0;
			
		}
		for (int l1335 = 0; (l1335 < 2); l1335 = (l1335 + 1)) {
			fRec1930[l1335] = 0.0;
			
		}
		for (int l1336 = 0; (l1336 < 2); l1336 = (l1336 + 1)) {
			fRec1929[l1336] = 0.0;
			
		}
		for (int l1337 = 0; (l1337 < 2); l1337 = (l1337 + 1)) {
			fRec1927[l1337] = 0.0;
			
		}
		for (int l1338 = 0; (l1338 < 2); l1338 = (l1338 + 1)) {
			fRec1926[l1338] = 0.0;
			
		}
		for (int l1339 = 0; (l1339 < 2); l1339 = (l1339 + 1)) {
			fRec1924[l1339] = 0.0;
			
		}
		for (int l1340 = 0; (l1340 < 512); l1340 = (l1340 + 1)) {
			fVec28[l1340] = 0.0;
			
		}
		for (int l1341 = 0; (l1341 < 2); l1341 = (l1341 + 1)) {
			fRec1944[l1341] = 0.0;
			
		}
		for (int l1342 = 0; (l1342 < 2); l1342 = (l1342 + 1)) {
			fRec1942[l1342] = 0.0;
			
		}
		for (int l1343 = 0; (l1343 < 2); l1343 = (l1343 + 1)) {
			fRec1950[l1343] = 0.0;
			
		}
		for (int l1344 = 0; (l1344 < 2); l1344 = (l1344 + 1)) {
			fRec1948[l1344] = 0.0;
			
		}
		for (int l1345 = 0; (l1345 < 2); l1345 = (l1345 + 1)) {
			fRec1947[l1345] = 0.0;
			
		}
		for (int l1346 = 0; (l1346 < 2); l1346 = (l1346 + 1)) {
			fRec1945[l1346] = 0.0;
			
		}
		for (int l1347 = 0; (l1347 < 2); l1347 = (l1347 + 1)) {
			fRec1959[l1347] = 0.0;
			
		}
		for (int l1348 = 0; (l1348 < 2); l1348 = (l1348 + 1)) {
			fRec1957[l1348] = 0.0;
			
		}
		for (int l1349 = 0; (l1349 < 2); l1349 = (l1349 + 1)) {
			fRec1956[l1349] = 0.0;
			
		}
		for (int l1350 = 0; (l1350 < 2); l1350 = (l1350 + 1)) {
			fRec1954[l1350] = 0.0;
			
		}
		for (int l1351 = 0; (l1351 < 2); l1351 = (l1351 + 1)) {
			fRec1953[l1351] = 0.0;
			
		}
		for (int l1352 = 0; (l1352 < 2); l1352 = (l1352 + 1)) {
			fRec1951[l1352] = 0.0;
			
		}
		for (int l1353 = 0; (l1353 < 2); l1353 = (l1353 + 1)) {
			fRec1971[l1353] = 0.0;
			
		}
		for (int l1354 = 0; (l1354 < 2); l1354 = (l1354 + 1)) {
			fRec1969[l1354] = 0.0;
			
		}
		for (int l1355 = 0; (l1355 < 2); l1355 = (l1355 + 1)) {
			fRec1968[l1355] = 0.0;
			
		}
		for (int l1356 = 0; (l1356 < 2); l1356 = (l1356 + 1)) {
			fRec1966[l1356] = 0.0;
			
		}
		for (int l1357 = 0; (l1357 < 2); l1357 = (l1357 + 1)) {
			fRec1965[l1357] = 0.0;
			
		}
		for (int l1358 = 0; (l1358 < 2); l1358 = (l1358 + 1)) {
			fRec1963[l1358] = 0.0;
			
		}
		for (int l1359 = 0; (l1359 < 2); l1359 = (l1359 + 1)) {
			fRec1962[l1359] = 0.0;
			
		}
		for (int l1360 = 0; (l1360 < 2); l1360 = (l1360 + 1)) {
			fRec1960[l1360] = 0.0;
			
		}
		for (int l1361 = 0; (l1361 < 2); l1361 = (l1361 + 1)) {
			fRec1986[l1361] = 0.0;
			
		}
		for (int l1362 = 0; (l1362 < 2); l1362 = (l1362 + 1)) {
			fRec1984[l1362] = 0.0;
			
		}
		for (int l1363 = 0; (l1363 < 2); l1363 = (l1363 + 1)) {
			fRec1983[l1363] = 0.0;
			
		}
		for (int l1364 = 0; (l1364 < 2); l1364 = (l1364 + 1)) {
			fRec1981[l1364] = 0.0;
			
		}
		for (int l1365 = 0; (l1365 < 2); l1365 = (l1365 + 1)) {
			fRec1980[l1365] = 0.0;
			
		}
		for (int l1366 = 0; (l1366 < 2); l1366 = (l1366 + 1)) {
			fRec1978[l1366] = 0.0;
			
		}
		for (int l1367 = 0; (l1367 < 2); l1367 = (l1367 + 1)) {
			fRec1977[l1367] = 0.0;
			
		}
		for (int l1368 = 0; (l1368 < 2); l1368 = (l1368 + 1)) {
			fRec1975[l1368] = 0.0;
			
		}
		for (int l1369 = 0; (l1369 < 2); l1369 = (l1369 + 1)) {
			fRec1974[l1369] = 0.0;
			
		}
		for (int l1370 = 0; (l1370 < 2); l1370 = (l1370 + 1)) {
			fRec1972[l1370] = 0.0;
			
		}
		for (int l1371 = 0; (l1371 < 2); l1371 = (l1371 + 1)) {
			fRec2004[l1371] = 0.0;
			
		}
		for (int l1372 = 0; (l1372 < 2); l1372 = (l1372 + 1)) {
			fRec2002[l1372] = 0.0;
			
		}
		for (int l1373 = 0; (l1373 < 2); l1373 = (l1373 + 1)) {
			fRec2001[l1373] = 0.0;
			
		}
		for (int l1374 = 0; (l1374 < 2); l1374 = (l1374 + 1)) {
			fRec1999[l1374] = 0.0;
			
		}
		for (int l1375 = 0; (l1375 < 2); l1375 = (l1375 + 1)) {
			fRec1998[l1375] = 0.0;
			
		}
		for (int l1376 = 0; (l1376 < 2); l1376 = (l1376 + 1)) {
			fRec1996[l1376] = 0.0;
			
		}
		for (int l1377 = 0; (l1377 < 2); l1377 = (l1377 + 1)) {
			fRec1995[l1377] = 0.0;
			
		}
		for (int l1378 = 0; (l1378 < 2); l1378 = (l1378 + 1)) {
			fRec1993[l1378] = 0.0;
			
		}
		for (int l1379 = 0; (l1379 < 2); l1379 = (l1379 + 1)) {
			fRec1992[l1379] = 0.0;
			
		}
		for (int l1380 = 0; (l1380 < 2); l1380 = (l1380 + 1)) {
			fRec1990[l1380] = 0.0;
			
		}
		for (int l1381 = 0; (l1381 < 2); l1381 = (l1381 + 1)) {
			fRec1989[l1381] = 0.0;
			
		}
		for (int l1382 = 0; (l1382 < 2); l1382 = (l1382 + 1)) {
			fRec1987[l1382] = 0.0;
			
		}
		for (int l1383 = 0; (l1383 < 512); l1383 = (l1383 + 1)) {
			fVec29[l1383] = 0.0;
			
		}
		for (int l1384 = 0; (l1384 < 2); l1384 = (l1384 + 1)) {
			fRec2007[l1384] = 0.0;
			
		}
		for (int l1385 = 0; (l1385 < 2); l1385 = (l1385 + 1)) {
			fRec2005[l1385] = 0.0;
			
		}
		for (int l1386 = 0; (l1386 < 2); l1386 = (l1386 + 1)) {
			fRec2013[l1386] = 0.0;
			
		}
		for (int l1387 = 0; (l1387 < 2); l1387 = (l1387 + 1)) {
			fRec2011[l1387] = 0.0;
			
		}
		for (int l1388 = 0; (l1388 < 2); l1388 = (l1388 + 1)) {
			fRec2010[l1388] = 0.0;
			
		}
		for (int l1389 = 0; (l1389 < 2); l1389 = (l1389 + 1)) {
			fRec2008[l1389] = 0.0;
			
		}
		for (int l1390 = 0; (l1390 < 2); l1390 = (l1390 + 1)) {
			fRec2022[l1390] = 0.0;
			
		}
		for (int l1391 = 0; (l1391 < 2); l1391 = (l1391 + 1)) {
			fRec2020[l1391] = 0.0;
			
		}
		for (int l1392 = 0; (l1392 < 2); l1392 = (l1392 + 1)) {
			fRec2019[l1392] = 0.0;
			
		}
		for (int l1393 = 0; (l1393 < 2); l1393 = (l1393 + 1)) {
			fRec2017[l1393] = 0.0;
			
		}
		for (int l1394 = 0; (l1394 < 2); l1394 = (l1394 + 1)) {
			fRec2016[l1394] = 0.0;
			
		}
		for (int l1395 = 0; (l1395 < 2); l1395 = (l1395 + 1)) {
			fRec2014[l1395] = 0.0;
			
		}
		for (int l1396 = 0; (l1396 < 2); l1396 = (l1396 + 1)) {
			fRec2034[l1396] = 0.0;
			
		}
		for (int l1397 = 0; (l1397 < 2); l1397 = (l1397 + 1)) {
			fRec2032[l1397] = 0.0;
			
		}
		for (int l1398 = 0; (l1398 < 2); l1398 = (l1398 + 1)) {
			fRec2031[l1398] = 0.0;
			
		}
		for (int l1399 = 0; (l1399 < 2); l1399 = (l1399 + 1)) {
			fRec2029[l1399] = 0.0;
			
		}
		for (int l1400 = 0; (l1400 < 2); l1400 = (l1400 + 1)) {
			fRec2028[l1400] = 0.0;
			
		}
		for (int l1401 = 0; (l1401 < 2); l1401 = (l1401 + 1)) {
			fRec2026[l1401] = 0.0;
			
		}
		for (int l1402 = 0; (l1402 < 2); l1402 = (l1402 + 1)) {
			fRec2025[l1402] = 0.0;
			
		}
		for (int l1403 = 0; (l1403 < 2); l1403 = (l1403 + 1)) {
			fRec2023[l1403] = 0.0;
			
		}
		for (int l1404 = 0; (l1404 < 2); l1404 = (l1404 + 1)) {
			fRec2049[l1404] = 0.0;
			
		}
		for (int l1405 = 0; (l1405 < 2); l1405 = (l1405 + 1)) {
			fRec2047[l1405] = 0.0;
			
		}
		for (int l1406 = 0; (l1406 < 2); l1406 = (l1406 + 1)) {
			fRec2046[l1406] = 0.0;
			
		}
		for (int l1407 = 0; (l1407 < 2); l1407 = (l1407 + 1)) {
			fRec2044[l1407] = 0.0;
			
		}
		for (int l1408 = 0; (l1408 < 2); l1408 = (l1408 + 1)) {
			fRec2043[l1408] = 0.0;
			
		}
		for (int l1409 = 0; (l1409 < 2); l1409 = (l1409 + 1)) {
			fRec2041[l1409] = 0.0;
			
		}
		for (int l1410 = 0; (l1410 < 2); l1410 = (l1410 + 1)) {
			fRec2040[l1410] = 0.0;
			
		}
		for (int l1411 = 0; (l1411 < 2); l1411 = (l1411 + 1)) {
			fRec2038[l1411] = 0.0;
			
		}
		for (int l1412 = 0; (l1412 < 2); l1412 = (l1412 + 1)) {
			fRec2037[l1412] = 0.0;
			
		}
		for (int l1413 = 0; (l1413 < 2); l1413 = (l1413 + 1)) {
			fRec2035[l1413] = 0.0;
			
		}
		for (int l1414 = 0; (l1414 < 2); l1414 = (l1414 + 1)) {
			fRec2067[l1414] = 0.0;
			
		}
		for (int l1415 = 0; (l1415 < 2); l1415 = (l1415 + 1)) {
			fRec2065[l1415] = 0.0;
			
		}
		for (int l1416 = 0; (l1416 < 2); l1416 = (l1416 + 1)) {
			fRec2064[l1416] = 0.0;
			
		}
		for (int l1417 = 0; (l1417 < 2); l1417 = (l1417 + 1)) {
			fRec2062[l1417] = 0.0;
			
		}
		for (int l1418 = 0; (l1418 < 2); l1418 = (l1418 + 1)) {
			fRec2061[l1418] = 0.0;
			
		}
		for (int l1419 = 0; (l1419 < 2); l1419 = (l1419 + 1)) {
			fRec2059[l1419] = 0.0;
			
		}
		for (int l1420 = 0; (l1420 < 2); l1420 = (l1420 + 1)) {
			fRec2058[l1420] = 0.0;
			
		}
		for (int l1421 = 0; (l1421 < 2); l1421 = (l1421 + 1)) {
			fRec2056[l1421] = 0.0;
			
		}
		for (int l1422 = 0; (l1422 < 2); l1422 = (l1422 + 1)) {
			fRec2055[l1422] = 0.0;
			
		}
		for (int l1423 = 0; (l1423 < 2); l1423 = (l1423 + 1)) {
			fRec2053[l1423] = 0.0;
			
		}
		for (int l1424 = 0; (l1424 < 2); l1424 = (l1424 + 1)) {
			fRec2052[l1424] = 0.0;
			
		}
		for (int l1425 = 0; (l1425 < 2); l1425 = (l1425 + 1)) {
			fRec2050[l1425] = 0.0;
			
		}
		for (int l1426 = 0; (l1426 < 512); l1426 = (l1426 + 1)) {
			fVec30[l1426] = 0.0;
			
		}
		for (int l1427 = 0; (l1427 < 2); l1427 = (l1427 + 1)) {
			fRec2070[l1427] = 0.0;
			
		}
		for (int l1428 = 0; (l1428 < 2); l1428 = (l1428 + 1)) {
			fRec2068[l1428] = 0.0;
			
		}
		for (int l1429 = 0; (l1429 < 2); l1429 = (l1429 + 1)) {
			fRec2076[l1429] = 0.0;
			
		}
		for (int l1430 = 0; (l1430 < 2); l1430 = (l1430 + 1)) {
			fRec2074[l1430] = 0.0;
			
		}
		for (int l1431 = 0; (l1431 < 2); l1431 = (l1431 + 1)) {
			fRec2073[l1431] = 0.0;
			
		}
		for (int l1432 = 0; (l1432 < 2); l1432 = (l1432 + 1)) {
			fRec2071[l1432] = 0.0;
			
		}
		for (int l1433 = 0; (l1433 < 2); l1433 = (l1433 + 1)) {
			fRec2085[l1433] = 0.0;
			
		}
		for (int l1434 = 0; (l1434 < 2); l1434 = (l1434 + 1)) {
			fRec2083[l1434] = 0.0;
			
		}
		for (int l1435 = 0; (l1435 < 2); l1435 = (l1435 + 1)) {
			fRec2082[l1435] = 0.0;
			
		}
		for (int l1436 = 0; (l1436 < 2); l1436 = (l1436 + 1)) {
			fRec2080[l1436] = 0.0;
			
		}
		for (int l1437 = 0; (l1437 < 2); l1437 = (l1437 + 1)) {
			fRec2079[l1437] = 0.0;
			
		}
		for (int l1438 = 0; (l1438 < 2); l1438 = (l1438 + 1)) {
			fRec2077[l1438] = 0.0;
			
		}
		for (int l1439 = 0; (l1439 < 2); l1439 = (l1439 + 1)) {
			fRec2097[l1439] = 0.0;
			
		}
		for (int l1440 = 0; (l1440 < 2); l1440 = (l1440 + 1)) {
			fRec2095[l1440] = 0.0;
			
		}
		for (int l1441 = 0; (l1441 < 2); l1441 = (l1441 + 1)) {
			fRec2094[l1441] = 0.0;
			
		}
		for (int l1442 = 0; (l1442 < 2); l1442 = (l1442 + 1)) {
			fRec2092[l1442] = 0.0;
			
		}
		for (int l1443 = 0; (l1443 < 2); l1443 = (l1443 + 1)) {
			fRec2091[l1443] = 0.0;
			
		}
		for (int l1444 = 0; (l1444 < 2); l1444 = (l1444 + 1)) {
			fRec2089[l1444] = 0.0;
			
		}
		for (int l1445 = 0; (l1445 < 2); l1445 = (l1445 + 1)) {
			fRec2088[l1445] = 0.0;
			
		}
		for (int l1446 = 0; (l1446 < 2); l1446 = (l1446 + 1)) {
			fRec2086[l1446] = 0.0;
			
		}
		for (int l1447 = 0; (l1447 < 2); l1447 = (l1447 + 1)) {
			fRec2112[l1447] = 0.0;
			
		}
		for (int l1448 = 0; (l1448 < 2); l1448 = (l1448 + 1)) {
			fRec2110[l1448] = 0.0;
			
		}
		for (int l1449 = 0; (l1449 < 2); l1449 = (l1449 + 1)) {
			fRec2109[l1449] = 0.0;
			
		}
		for (int l1450 = 0; (l1450 < 2); l1450 = (l1450 + 1)) {
			fRec2107[l1450] = 0.0;
			
		}
		for (int l1451 = 0; (l1451 < 2); l1451 = (l1451 + 1)) {
			fRec2106[l1451] = 0.0;
			
		}
		for (int l1452 = 0; (l1452 < 2); l1452 = (l1452 + 1)) {
			fRec2104[l1452] = 0.0;
			
		}
		for (int l1453 = 0; (l1453 < 2); l1453 = (l1453 + 1)) {
			fRec2103[l1453] = 0.0;
			
		}
		for (int l1454 = 0; (l1454 < 2); l1454 = (l1454 + 1)) {
			fRec2101[l1454] = 0.0;
			
		}
		for (int l1455 = 0; (l1455 < 2); l1455 = (l1455 + 1)) {
			fRec2100[l1455] = 0.0;
			
		}
		for (int l1456 = 0; (l1456 < 2); l1456 = (l1456 + 1)) {
			fRec2098[l1456] = 0.0;
			
		}
		for (int l1457 = 0; (l1457 < 2); l1457 = (l1457 + 1)) {
			fRec2130[l1457] = 0.0;
			
		}
		for (int l1458 = 0; (l1458 < 2); l1458 = (l1458 + 1)) {
			fRec2128[l1458] = 0.0;
			
		}
		for (int l1459 = 0; (l1459 < 2); l1459 = (l1459 + 1)) {
			fRec2127[l1459] = 0.0;
			
		}
		for (int l1460 = 0; (l1460 < 2); l1460 = (l1460 + 1)) {
			fRec2125[l1460] = 0.0;
			
		}
		for (int l1461 = 0; (l1461 < 2); l1461 = (l1461 + 1)) {
			fRec2124[l1461] = 0.0;
			
		}
		for (int l1462 = 0; (l1462 < 2); l1462 = (l1462 + 1)) {
			fRec2122[l1462] = 0.0;
			
		}
		for (int l1463 = 0; (l1463 < 2); l1463 = (l1463 + 1)) {
			fRec2121[l1463] = 0.0;
			
		}
		for (int l1464 = 0; (l1464 < 2); l1464 = (l1464 + 1)) {
			fRec2119[l1464] = 0.0;
			
		}
		for (int l1465 = 0; (l1465 < 2); l1465 = (l1465 + 1)) {
			fRec2118[l1465] = 0.0;
			
		}
		for (int l1466 = 0; (l1466 < 2); l1466 = (l1466 + 1)) {
			fRec2116[l1466] = 0.0;
			
		}
		for (int l1467 = 0; (l1467 < 2); l1467 = (l1467 + 1)) {
			fRec2115[l1467] = 0.0;
			
		}
		for (int l1468 = 0; (l1468 < 2); l1468 = (l1468 + 1)) {
			fRec2113[l1468] = 0.0;
			
		}
		for (int l1469 = 0; (l1469 < 512); l1469 = (l1469 + 1)) {
			fVec31[l1469] = 0.0;
			
		}
		for (int l1470 = 0; (l1470 < 2); l1470 = (l1470 + 1)) {
			fRec2133[l1470] = 0.0;
			
		}
		for (int l1471 = 0; (l1471 < 2); l1471 = (l1471 + 1)) {
			fRec2131[l1471] = 0.0;
			
		}
		for (int l1472 = 0; (l1472 < 2); l1472 = (l1472 + 1)) {
			fRec2139[l1472] = 0.0;
			
		}
		for (int l1473 = 0; (l1473 < 2); l1473 = (l1473 + 1)) {
			fRec2137[l1473] = 0.0;
			
		}
		for (int l1474 = 0; (l1474 < 2); l1474 = (l1474 + 1)) {
			fRec2136[l1474] = 0.0;
			
		}
		for (int l1475 = 0; (l1475 < 2); l1475 = (l1475 + 1)) {
			fRec2134[l1475] = 0.0;
			
		}
		for (int l1476 = 0; (l1476 < 2); l1476 = (l1476 + 1)) {
			fRec2148[l1476] = 0.0;
			
		}
		for (int l1477 = 0; (l1477 < 2); l1477 = (l1477 + 1)) {
			fRec2146[l1477] = 0.0;
			
		}
		for (int l1478 = 0; (l1478 < 2); l1478 = (l1478 + 1)) {
			fRec2145[l1478] = 0.0;
			
		}
		for (int l1479 = 0; (l1479 < 2); l1479 = (l1479 + 1)) {
			fRec2143[l1479] = 0.0;
			
		}
		for (int l1480 = 0; (l1480 < 2); l1480 = (l1480 + 1)) {
			fRec2142[l1480] = 0.0;
			
		}
		for (int l1481 = 0; (l1481 < 2); l1481 = (l1481 + 1)) {
			fRec2140[l1481] = 0.0;
			
		}
		for (int l1482 = 0; (l1482 < 2); l1482 = (l1482 + 1)) {
			fRec2160[l1482] = 0.0;
			
		}
		for (int l1483 = 0; (l1483 < 2); l1483 = (l1483 + 1)) {
			fRec2158[l1483] = 0.0;
			
		}
		for (int l1484 = 0; (l1484 < 2); l1484 = (l1484 + 1)) {
			fRec2157[l1484] = 0.0;
			
		}
		for (int l1485 = 0; (l1485 < 2); l1485 = (l1485 + 1)) {
			fRec2155[l1485] = 0.0;
			
		}
		for (int l1486 = 0; (l1486 < 2); l1486 = (l1486 + 1)) {
			fRec2154[l1486] = 0.0;
			
		}
		for (int l1487 = 0; (l1487 < 2); l1487 = (l1487 + 1)) {
			fRec2152[l1487] = 0.0;
			
		}
		for (int l1488 = 0; (l1488 < 2); l1488 = (l1488 + 1)) {
			fRec2151[l1488] = 0.0;
			
		}
		for (int l1489 = 0; (l1489 < 2); l1489 = (l1489 + 1)) {
			fRec2149[l1489] = 0.0;
			
		}
		for (int l1490 = 0; (l1490 < 2); l1490 = (l1490 + 1)) {
			fRec2175[l1490] = 0.0;
			
		}
		for (int l1491 = 0; (l1491 < 2); l1491 = (l1491 + 1)) {
			fRec2173[l1491] = 0.0;
			
		}
		for (int l1492 = 0; (l1492 < 2); l1492 = (l1492 + 1)) {
			fRec2172[l1492] = 0.0;
			
		}
		for (int l1493 = 0; (l1493 < 2); l1493 = (l1493 + 1)) {
			fRec2170[l1493] = 0.0;
			
		}
		for (int l1494 = 0; (l1494 < 2); l1494 = (l1494 + 1)) {
			fRec2169[l1494] = 0.0;
			
		}
		for (int l1495 = 0; (l1495 < 2); l1495 = (l1495 + 1)) {
			fRec2167[l1495] = 0.0;
			
		}
		for (int l1496 = 0; (l1496 < 2); l1496 = (l1496 + 1)) {
			fRec2166[l1496] = 0.0;
			
		}
		for (int l1497 = 0; (l1497 < 2); l1497 = (l1497 + 1)) {
			fRec2164[l1497] = 0.0;
			
		}
		for (int l1498 = 0; (l1498 < 2); l1498 = (l1498 + 1)) {
			fRec2163[l1498] = 0.0;
			
		}
		for (int l1499 = 0; (l1499 < 2); l1499 = (l1499 + 1)) {
			fRec2161[l1499] = 0.0;
			
		}
		for (int l1500 = 0; (l1500 < 2); l1500 = (l1500 + 1)) {
			fRec2193[l1500] = 0.0;
			
		}
		for (int l1501 = 0; (l1501 < 2); l1501 = (l1501 + 1)) {
			fRec2191[l1501] = 0.0;
			
		}
		for (int l1502 = 0; (l1502 < 2); l1502 = (l1502 + 1)) {
			fRec2190[l1502] = 0.0;
			
		}
		for (int l1503 = 0; (l1503 < 2); l1503 = (l1503 + 1)) {
			fRec2188[l1503] = 0.0;
			
		}
		for (int l1504 = 0; (l1504 < 2); l1504 = (l1504 + 1)) {
			fRec2187[l1504] = 0.0;
			
		}
		for (int l1505 = 0; (l1505 < 2); l1505 = (l1505 + 1)) {
			fRec2185[l1505] = 0.0;
			
		}
		for (int l1506 = 0; (l1506 < 2); l1506 = (l1506 + 1)) {
			fRec2184[l1506] = 0.0;
			
		}
		for (int l1507 = 0; (l1507 < 2); l1507 = (l1507 + 1)) {
			fRec2182[l1507] = 0.0;
			
		}
		for (int l1508 = 0; (l1508 < 2); l1508 = (l1508 + 1)) {
			fRec2181[l1508] = 0.0;
			
		}
		for (int l1509 = 0; (l1509 < 2); l1509 = (l1509 + 1)) {
			fRec2179[l1509] = 0.0;
			
		}
		for (int l1510 = 0; (l1510 < 2); l1510 = (l1510 + 1)) {
			fRec2178[l1510] = 0.0;
			
		}
		for (int l1511 = 0; (l1511 < 2); l1511 = (l1511 + 1)) {
			fRec2176[l1511] = 0.0;
			
		}
		for (int l1512 = 0; (l1512 < 512); l1512 = (l1512 + 1)) {
			fVec32[l1512] = 0.0;
			
		}
		for (int l1513 = 0; (l1513 < 2); l1513 = (l1513 + 1)) {
			fRec2196[l1513] = 0.0;
			
		}
		for (int l1514 = 0; (l1514 < 2); l1514 = (l1514 + 1)) {
			fRec2194[l1514] = 0.0;
			
		}
		for (int l1515 = 0; (l1515 < 2); l1515 = (l1515 + 1)) {
			fRec2202[l1515] = 0.0;
			
		}
		for (int l1516 = 0; (l1516 < 2); l1516 = (l1516 + 1)) {
			fRec2200[l1516] = 0.0;
			
		}
		for (int l1517 = 0; (l1517 < 2); l1517 = (l1517 + 1)) {
			fRec2199[l1517] = 0.0;
			
		}
		for (int l1518 = 0; (l1518 < 2); l1518 = (l1518 + 1)) {
			fRec2197[l1518] = 0.0;
			
		}
		for (int l1519 = 0; (l1519 < 2); l1519 = (l1519 + 1)) {
			fRec2211[l1519] = 0.0;
			
		}
		for (int l1520 = 0; (l1520 < 2); l1520 = (l1520 + 1)) {
			fRec2209[l1520] = 0.0;
			
		}
		for (int l1521 = 0; (l1521 < 2); l1521 = (l1521 + 1)) {
			fRec2208[l1521] = 0.0;
			
		}
		for (int l1522 = 0; (l1522 < 2); l1522 = (l1522 + 1)) {
			fRec2206[l1522] = 0.0;
			
		}
		for (int l1523 = 0; (l1523 < 2); l1523 = (l1523 + 1)) {
			fRec2205[l1523] = 0.0;
			
		}
		for (int l1524 = 0; (l1524 < 2); l1524 = (l1524 + 1)) {
			fRec2203[l1524] = 0.0;
			
		}
		for (int l1525 = 0; (l1525 < 2); l1525 = (l1525 + 1)) {
			fRec2223[l1525] = 0.0;
			
		}
		for (int l1526 = 0; (l1526 < 2); l1526 = (l1526 + 1)) {
			fRec2221[l1526] = 0.0;
			
		}
		for (int l1527 = 0; (l1527 < 2); l1527 = (l1527 + 1)) {
			fRec2220[l1527] = 0.0;
			
		}
		for (int l1528 = 0; (l1528 < 2); l1528 = (l1528 + 1)) {
			fRec2218[l1528] = 0.0;
			
		}
		for (int l1529 = 0; (l1529 < 2); l1529 = (l1529 + 1)) {
			fRec2217[l1529] = 0.0;
			
		}
		for (int l1530 = 0; (l1530 < 2); l1530 = (l1530 + 1)) {
			fRec2215[l1530] = 0.0;
			
		}
		for (int l1531 = 0; (l1531 < 2); l1531 = (l1531 + 1)) {
			fRec2214[l1531] = 0.0;
			
		}
		for (int l1532 = 0; (l1532 < 2); l1532 = (l1532 + 1)) {
			fRec2212[l1532] = 0.0;
			
		}
		for (int l1533 = 0; (l1533 < 2); l1533 = (l1533 + 1)) {
			fRec2238[l1533] = 0.0;
			
		}
		for (int l1534 = 0; (l1534 < 2); l1534 = (l1534 + 1)) {
			fRec2236[l1534] = 0.0;
			
		}
		for (int l1535 = 0; (l1535 < 2); l1535 = (l1535 + 1)) {
			fRec2235[l1535] = 0.0;
			
		}
		for (int l1536 = 0; (l1536 < 2); l1536 = (l1536 + 1)) {
			fRec2233[l1536] = 0.0;
			
		}
		for (int l1537 = 0; (l1537 < 2); l1537 = (l1537 + 1)) {
			fRec2232[l1537] = 0.0;
			
		}
		for (int l1538 = 0; (l1538 < 2); l1538 = (l1538 + 1)) {
			fRec2230[l1538] = 0.0;
			
		}
		for (int l1539 = 0; (l1539 < 2); l1539 = (l1539 + 1)) {
			fRec2229[l1539] = 0.0;
			
		}
		for (int l1540 = 0; (l1540 < 2); l1540 = (l1540 + 1)) {
			fRec2227[l1540] = 0.0;
			
		}
		for (int l1541 = 0; (l1541 < 2); l1541 = (l1541 + 1)) {
			fRec2226[l1541] = 0.0;
			
		}
		for (int l1542 = 0; (l1542 < 2); l1542 = (l1542 + 1)) {
			fRec2224[l1542] = 0.0;
			
		}
		for (int l1543 = 0; (l1543 < 2); l1543 = (l1543 + 1)) {
			fRec2256[l1543] = 0.0;
			
		}
		for (int l1544 = 0; (l1544 < 2); l1544 = (l1544 + 1)) {
			fRec2254[l1544] = 0.0;
			
		}
		for (int l1545 = 0; (l1545 < 2); l1545 = (l1545 + 1)) {
			fRec2253[l1545] = 0.0;
			
		}
		for (int l1546 = 0; (l1546 < 2); l1546 = (l1546 + 1)) {
			fRec2251[l1546] = 0.0;
			
		}
		for (int l1547 = 0; (l1547 < 2); l1547 = (l1547 + 1)) {
			fRec2250[l1547] = 0.0;
			
		}
		for (int l1548 = 0; (l1548 < 2); l1548 = (l1548 + 1)) {
			fRec2248[l1548] = 0.0;
			
		}
		for (int l1549 = 0; (l1549 < 2); l1549 = (l1549 + 1)) {
			fRec2247[l1549] = 0.0;
			
		}
		for (int l1550 = 0; (l1550 < 2); l1550 = (l1550 + 1)) {
			fRec2245[l1550] = 0.0;
			
		}
		for (int l1551 = 0; (l1551 < 2); l1551 = (l1551 + 1)) {
			fRec2244[l1551] = 0.0;
			
		}
		for (int l1552 = 0; (l1552 < 2); l1552 = (l1552 + 1)) {
			fRec2242[l1552] = 0.0;
			
		}
		for (int l1553 = 0; (l1553 < 2); l1553 = (l1553 + 1)) {
			fRec2241[l1553] = 0.0;
			
		}
		for (int l1554 = 0; (l1554 < 2); l1554 = (l1554 + 1)) {
			fRec2239[l1554] = 0.0;
			
		}
		for (int l1555 = 0; (l1555 < 512); l1555 = (l1555 + 1)) {
			fVec33[l1555] = 0.0;
			
		}
		for (int l1556 = 0; (l1556 < 2); l1556 = (l1556 + 1)) {
			fRec2259[l1556] = 0.0;
			
		}
		for (int l1557 = 0; (l1557 < 2); l1557 = (l1557 + 1)) {
			fRec2257[l1557] = 0.0;
			
		}
		for (int l1558 = 0; (l1558 < 2); l1558 = (l1558 + 1)) {
			fRec2265[l1558] = 0.0;
			
		}
		for (int l1559 = 0; (l1559 < 2); l1559 = (l1559 + 1)) {
			fRec2263[l1559] = 0.0;
			
		}
		for (int l1560 = 0; (l1560 < 2); l1560 = (l1560 + 1)) {
			fRec2262[l1560] = 0.0;
			
		}
		for (int l1561 = 0; (l1561 < 2); l1561 = (l1561 + 1)) {
			fRec2260[l1561] = 0.0;
			
		}
		for (int l1562 = 0; (l1562 < 2); l1562 = (l1562 + 1)) {
			fRec2274[l1562] = 0.0;
			
		}
		for (int l1563 = 0; (l1563 < 2); l1563 = (l1563 + 1)) {
			fRec2272[l1563] = 0.0;
			
		}
		for (int l1564 = 0; (l1564 < 2); l1564 = (l1564 + 1)) {
			fRec2271[l1564] = 0.0;
			
		}
		for (int l1565 = 0; (l1565 < 2); l1565 = (l1565 + 1)) {
			fRec2269[l1565] = 0.0;
			
		}
		for (int l1566 = 0; (l1566 < 2); l1566 = (l1566 + 1)) {
			fRec2268[l1566] = 0.0;
			
		}
		for (int l1567 = 0; (l1567 < 2); l1567 = (l1567 + 1)) {
			fRec2266[l1567] = 0.0;
			
		}
		for (int l1568 = 0; (l1568 < 2); l1568 = (l1568 + 1)) {
			fRec2286[l1568] = 0.0;
			
		}
		for (int l1569 = 0; (l1569 < 2); l1569 = (l1569 + 1)) {
			fRec2284[l1569] = 0.0;
			
		}
		for (int l1570 = 0; (l1570 < 2); l1570 = (l1570 + 1)) {
			fRec2283[l1570] = 0.0;
			
		}
		for (int l1571 = 0; (l1571 < 2); l1571 = (l1571 + 1)) {
			fRec2281[l1571] = 0.0;
			
		}
		for (int l1572 = 0; (l1572 < 2); l1572 = (l1572 + 1)) {
			fRec2280[l1572] = 0.0;
			
		}
		for (int l1573 = 0; (l1573 < 2); l1573 = (l1573 + 1)) {
			fRec2278[l1573] = 0.0;
			
		}
		for (int l1574 = 0; (l1574 < 2); l1574 = (l1574 + 1)) {
			fRec2277[l1574] = 0.0;
			
		}
		for (int l1575 = 0; (l1575 < 2); l1575 = (l1575 + 1)) {
			fRec2275[l1575] = 0.0;
			
		}
		for (int l1576 = 0; (l1576 < 2); l1576 = (l1576 + 1)) {
			fRec2301[l1576] = 0.0;
			
		}
		for (int l1577 = 0; (l1577 < 2); l1577 = (l1577 + 1)) {
			fRec2299[l1577] = 0.0;
			
		}
		for (int l1578 = 0; (l1578 < 2); l1578 = (l1578 + 1)) {
			fRec2298[l1578] = 0.0;
			
		}
		for (int l1579 = 0; (l1579 < 2); l1579 = (l1579 + 1)) {
			fRec2296[l1579] = 0.0;
			
		}
		for (int l1580 = 0; (l1580 < 2); l1580 = (l1580 + 1)) {
			fRec2295[l1580] = 0.0;
			
		}
		for (int l1581 = 0; (l1581 < 2); l1581 = (l1581 + 1)) {
			fRec2293[l1581] = 0.0;
			
		}
		for (int l1582 = 0; (l1582 < 2); l1582 = (l1582 + 1)) {
			fRec2292[l1582] = 0.0;
			
		}
		for (int l1583 = 0; (l1583 < 2); l1583 = (l1583 + 1)) {
			fRec2290[l1583] = 0.0;
			
		}
		for (int l1584 = 0; (l1584 < 2); l1584 = (l1584 + 1)) {
			fRec2289[l1584] = 0.0;
			
		}
		for (int l1585 = 0; (l1585 < 2); l1585 = (l1585 + 1)) {
			fRec2287[l1585] = 0.0;
			
		}
		for (int l1586 = 0; (l1586 < 2); l1586 = (l1586 + 1)) {
			fRec2319[l1586] = 0.0;
			
		}
		for (int l1587 = 0; (l1587 < 2); l1587 = (l1587 + 1)) {
			fRec2317[l1587] = 0.0;
			
		}
		for (int l1588 = 0; (l1588 < 2); l1588 = (l1588 + 1)) {
			fRec2316[l1588] = 0.0;
			
		}
		for (int l1589 = 0; (l1589 < 2); l1589 = (l1589 + 1)) {
			fRec2314[l1589] = 0.0;
			
		}
		for (int l1590 = 0; (l1590 < 2); l1590 = (l1590 + 1)) {
			fRec2313[l1590] = 0.0;
			
		}
		for (int l1591 = 0; (l1591 < 2); l1591 = (l1591 + 1)) {
			fRec2311[l1591] = 0.0;
			
		}
		for (int l1592 = 0; (l1592 < 2); l1592 = (l1592 + 1)) {
			fRec2310[l1592] = 0.0;
			
		}
		for (int l1593 = 0; (l1593 < 2); l1593 = (l1593 + 1)) {
			fRec2308[l1593] = 0.0;
			
		}
		for (int l1594 = 0; (l1594 < 2); l1594 = (l1594 + 1)) {
			fRec2307[l1594] = 0.0;
			
		}
		for (int l1595 = 0; (l1595 < 2); l1595 = (l1595 + 1)) {
			fRec2305[l1595] = 0.0;
			
		}
		for (int l1596 = 0; (l1596 < 2); l1596 = (l1596 + 1)) {
			fRec2304[l1596] = 0.0;
			
		}
		for (int l1597 = 0; (l1597 < 2); l1597 = (l1597 + 1)) {
			fRec2302[l1597] = 0.0;
			
		}
		for (int l1598 = 0; (l1598 < 512); l1598 = (l1598 + 1)) {
			fVec34[l1598] = 0.0;
			
		}
		for (int l1599 = 0; (l1599 < 2); l1599 = (l1599 + 1)) {
			fRec2337[l1599] = 0.0;
			
		}
		for (int l1600 = 0; (l1600 < 2); l1600 = (l1600 + 1)) {
			fRec2335[l1600] = 0.0;
			
		}
		for (int l1601 = 0; (l1601 < 2); l1601 = (l1601 + 1)) {
			fRec2334[l1601] = 0.0;
			
		}
		for (int l1602 = 0; (l1602 < 2); l1602 = (l1602 + 1)) {
			fRec2332[l1602] = 0.0;
			
		}
		for (int l1603 = 0; (l1603 < 2); l1603 = (l1603 + 1)) {
			fRec2331[l1603] = 0.0;
			
		}
		for (int l1604 = 0; (l1604 < 2); l1604 = (l1604 + 1)) {
			fRec2329[l1604] = 0.0;
			
		}
		for (int l1605 = 0; (l1605 < 2); l1605 = (l1605 + 1)) {
			fRec2328[l1605] = 0.0;
			
		}
		for (int l1606 = 0; (l1606 < 2); l1606 = (l1606 + 1)) {
			fRec2326[l1606] = 0.0;
			
		}
		for (int l1607 = 0; (l1607 < 2); l1607 = (l1607 + 1)) {
			fRec2325[l1607] = 0.0;
			
		}
		for (int l1608 = 0; (l1608 < 2); l1608 = (l1608 + 1)) {
			fRec2323[l1608] = 0.0;
			
		}
		for (int l1609 = 0; (l1609 < 2); l1609 = (l1609 + 1)) {
			fRec2322[l1609] = 0.0;
			
		}
		for (int l1610 = 0; (l1610 < 2); l1610 = (l1610 + 1)) {
			fRec2320[l1610] = 0.0;
			
		}
		for (int l1611 = 0; (l1611 < 2); l1611 = (l1611 + 1)) {
			fRec2352[l1611] = 0.0;
			
		}
		for (int l1612 = 0; (l1612 < 2); l1612 = (l1612 + 1)) {
			fRec2350[l1612] = 0.0;
			
		}
		for (int l1613 = 0; (l1613 < 2); l1613 = (l1613 + 1)) {
			fRec2349[l1613] = 0.0;
			
		}
		for (int l1614 = 0; (l1614 < 2); l1614 = (l1614 + 1)) {
			fRec2347[l1614] = 0.0;
			
		}
		for (int l1615 = 0; (l1615 < 2); l1615 = (l1615 + 1)) {
			fRec2346[l1615] = 0.0;
			
		}
		for (int l1616 = 0; (l1616 < 2); l1616 = (l1616 + 1)) {
			fRec2344[l1616] = 0.0;
			
		}
		for (int l1617 = 0; (l1617 < 2); l1617 = (l1617 + 1)) {
			fRec2343[l1617] = 0.0;
			
		}
		for (int l1618 = 0; (l1618 < 2); l1618 = (l1618 + 1)) {
			fRec2341[l1618] = 0.0;
			
		}
		for (int l1619 = 0; (l1619 < 2); l1619 = (l1619 + 1)) {
			fRec2340[l1619] = 0.0;
			
		}
		for (int l1620 = 0; (l1620 < 2); l1620 = (l1620 + 1)) {
			fRec2338[l1620] = 0.0;
			
		}
		for (int l1621 = 0; (l1621 < 2); l1621 = (l1621 + 1)) {
			fRec2364[l1621] = 0.0;
			
		}
		for (int l1622 = 0; (l1622 < 2); l1622 = (l1622 + 1)) {
			fRec2362[l1622] = 0.0;
			
		}
		for (int l1623 = 0; (l1623 < 2); l1623 = (l1623 + 1)) {
			fRec2361[l1623] = 0.0;
			
		}
		for (int l1624 = 0; (l1624 < 2); l1624 = (l1624 + 1)) {
			fRec2359[l1624] = 0.0;
			
		}
		for (int l1625 = 0; (l1625 < 2); l1625 = (l1625 + 1)) {
			fRec2358[l1625] = 0.0;
			
		}
		for (int l1626 = 0; (l1626 < 2); l1626 = (l1626 + 1)) {
			fRec2356[l1626] = 0.0;
			
		}
		for (int l1627 = 0; (l1627 < 2); l1627 = (l1627 + 1)) {
			fRec2355[l1627] = 0.0;
			
		}
		for (int l1628 = 0; (l1628 < 2); l1628 = (l1628 + 1)) {
			fRec2353[l1628] = 0.0;
			
		}
		for (int l1629 = 0; (l1629 < 2); l1629 = (l1629 + 1)) {
			fRec2373[l1629] = 0.0;
			
		}
		for (int l1630 = 0; (l1630 < 2); l1630 = (l1630 + 1)) {
			fRec2371[l1630] = 0.0;
			
		}
		for (int l1631 = 0; (l1631 < 2); l1631 = (l1631 + 1)) {
			fRec2370[l1631] = 0.0;
			
		}
		for (int l1632 = 0; (l1632 < 2); l1632 = (l1632 + 1)) {
			fRec2368[l1632] = 0.0;
			
		}
		for (int l1633 = 0; (l1633 < 2); l1633 = (l1633 + 1)) {
			fRec2367[l1633] = 0.0;
			
		}
		for (int l1634 = 0; (l1634 < 2); l1634 = (l1634 + 1)) {
			fRec2365[l1634] = 0.0;
			
		}
		for (int l1635 = 0; (l1635 < 2); l1635 = (l1635 + 1)) {
			fRec2376[l1635] = 0.0;
			
		}
		for (int l1636 = 0; (l1636 < 2); l1636 = (l1636 + 1)) {
			fRec2374[l1636] = 0.0;
			
		}
		for (int l1637 = 0; (l1637 < 2); l1637 = (l1637 + 1)) {
			fRec2382[l1637] = 0.0;
			
		}
		for (int l1638 = 0; (l1638 < 2); l1638 = (l1638 + 1)) {
			fRec2380[l1638] = 0.0;
			
		}
		for (int l1639 = 0; (l1639 < 2); l1639 = (l1639 + 1)) {
			fRec2379[l1639] = 0.0;
			
		}
		for (int l1640 = 0; (l1640 < 2); l1640 = (l1640 + 1)) {
			fRec2377[l1640] = 0.0;
			
		}
		for (int l1641 = 0; (l1641 < 512); l1641 = (l1641 + 1)) {
			fVec35[l1641] = 0.0;
			
		}
		for (int l1642 = 0; (l1642 < 2); l1642 = (l1642 + 1)) {
			fRec2400[l1642] = 0.0;
			
		}
		for (int l1643 = 0; (l1643 < 2); l1643 = (l1643 + 1)) {
			fRec2398[l1643] = 0.0;
			
		}
		for (int l1644 = 0; (l1644 < 2); l1644 = (l1644 + 1)) {
			fRec2397[l1644] = 0.0;
			
		}
		for (int l1645 = 0; (l1645 < 2); l1645 = (l1645 + 1)) {
			fRec2395[l1645] = 0.0;
			
		}
		for (int l1646 = 0; (l1646 < 2); l1646 = (l1646 + 1)) {
			fRec2394[l1646] = 0.0;
			
		}
		for (int l1647 = 0; (l1647 < 2); l1647 = (l1647 + 1)) {
			fRec2392[l1647] = 0.0;
			
		}
		for (int l1648 = 0; (l1648 < 2); l1648 = (l1648 + 1)) {
			fRec2391[l1648] = 0.0;
			
		}
		for (int l1649 = 0; (l1649 < 2); l1649 = (l1649 + 1)) {
			fRec2389[l1649] = 0.0;
			
		}
		for (int l1650 = 0; (l1650 < 2); l1650 = (l1650 + 1)) {
			fRec2388[l1650] = 0.0;
			
		}
		for (int l1651 = 0; (l1651 < 2); l1651 = (l1651 + 1)) {
			fRec2386[l1651] = 0.0;
			
		}
		for (int l1652 = 0; (l1652 < 2); l1652 = (l1652 + 1)) {
			fRec2385[l1652] = 0.0;
			
		}
		for (int l1653 = 0; (l1653 < 2); l1653 = (l1653 + 1)) {
			fRec2383[l1653] = 0.0;
			
		}
		for (int l1654 = 0; (l1654 < 2); l1654 = (l1654 + 1)) {
			fRec2415[l1654] = 0.0;
			
		}
		for (int l1655 = 0; (l1655 < 2); l1655 = (l1655 + 1)) {
			fRec2413[l1655] = 0.0;
			
		}
		for (int l1656 = 0; (l1656 < 2); l1656 = (l1656 + 1)) {
			fRec2412[l1656] = 0.0;
			
		}
		for (int l1657 = 0; (l1657 < 2); l1657 = (l1657 + 1)) {
			fRec2410[l1657] = 0.0;
			
		}
		for (int l1658 = 0; (l1658 < 2); l1658 = (l1658 + 1)) {
			fRec2409[l1658] = 0.0;
			
		}
		for (int l1659 = 0; (l1659 < 2); l1659 = (l1659 + 1)) {
			fRec2407[l1659] = 0.0;
			
		}
		for (int l1660 = 0; (l1660 < 2); l1660 = (l1660 + 1)) {
			fRec2406[l1660] = 0.0;
			
		}
		for (int l1661 = 0; (l1661 < 2); l1661 = (l1661 + 1)) {
			fRec2404[l1661] = 0.0;
			
		}
		for (int l1662 = 0; (l1662 < 2); l1662 = (l1662 + 1)) {
			fRec2403[l1662] = 0.0;
			
		}
		for (int l1663 = 0; (l1663 < 2); l1663 = (l1663 + 1)) {
			fRec2401[l1663] = 0.0;
			
		}
		for (int l1664 = 0; (l1664 < 2); l1664 = (l1664 + 1)) {
			fRec2427[l1664] = 0.0;
			
		}
		for (int l1665 = 0; (l1665 < 2); l1665 = (l1665 + 1)) {
			fRec2425[l1665] = 0.0;
			
		}
		for (int l1666 = 0; (l1666 < 2); l1666 = (l1666 + 1)) {
			fRec2424[l1666] = 0.0;
			
		}
		for (int l1667 = 0; (l1667 < 2); l1667 = (l1667 + 1)) {
			fRec2422[l1667] = 0.0;
			
		}
		for (int l1668 = 0; (l1668 < 2); l1668 = (l1668 + 1)) {
			fRec2421[l1668] = 0.0;
			
		}
		for (int l1669 = 0; (l1669 < 2); l1669 = (l1669 + 1)) {
			fRec2419[l1669] = 0.0;
			
		}
		for (int l1670 = 0; (l1670 < 2); l1670 = (l1670 + 1)) {
			fRec2418[l1670] = 0.0;
			
		}
		for (int l1671 = 0; (l1671 < 2); l1671 = (l1671 + 1)) {
			fRec2416[l1671] = 0.0;
			
		}
		for (int l1672 = 0; (l1672 < 2); l1672 = (l1672 + 1)) {
			fRec2436[l1672] = 0.0;
			
		}
		for (int l1673 = 0; (l1673 < 2); l1673 = (l1673 + 1)) {
			fRec2434[l1673] = 0.0;
			
		}
		for (int l1674 = 0; (l1674 < 2); l1674 = (l1674 + 1)) {
			fRec2433[l1674] = 0.0;
			
		}
		for (int l1675 = 0; (l1675 < 2); l1675 = (l1675 + 1)) {
			fRec2431[l1675] = 0.0;
			
		}
		for (int l1676 = 0; (l1676 < 2); l1676 = (l1676 + 1)) {
			fRec2430[l1676] = 0.0;
			
		}
		for (int l1677 = 0; (l1677 < 2); l1677 = (l1677 + 1)) {
			fRec2428[l1677] = 0.0;
			
		}
		for (int l1678 = 0; (l1678 < 2); l1678 = (l1678 + 1)) {
			fRec2439[l1678] = 0.0;
			
		}
		for (int l1679 = 0; (l1679 < 2); l1679 = (l1679 + 1)) {
			fRec2437[l1679] = 0.0;
			
		}
		for (int l1680 = 0; (l1680 < 2); l1680 = (l1680 + 1)) {
			fRec2445[l1680] = 0.0;
			
		}
		for (int l1681 = 0; (l1681 < 2); l1681 = (l1681 + 1)) {
			fRec2443[l1681] = 0.0;
			
		}
		for (int l1682 = 0; (l1682 < 2); l1682 = (l1682 + 1)) {
			fRec2442[l1682] = 0.0;
			
		}
		for (int l1683 = 0; (l1683 < 2); l1683 = (l1683 + 1)) {
			fRec2440[l1683] = 0.0;
			
		}
		for (int l1684 = 0; (l1684 < 512); l1684 = (l1684 + 1)) {
			fVec36[l1684] = 0.0;
			
		}
		for (int l1685 = 0; (l1685 < 2); l1685 = (l1685 + 1)) {
			fRec2463[l1685] = 0.0;
			
		}
		for (int l1686 = 0; (l1686 < 2); l1686 = (l1686 + 1)) {
			fRec2461[l1686] = 0.0;
			
		}
		for (int l1687 = 0; (l1687 < 2); l1687 = (l1687 + 1)) {
			fRec2460[l1687] = 0.0;
			
		}
		for (int l1688 = 0; (l1688 < 2); l1688 = (l1688 + 1)) {
			fRec2458[l1688] = 0.0;
			
		}
		for (int l1689 = 0; (l1689 < 2); l1689 = (l1689 + 1)) {
			fRec2457[l1689] = 0.0;
			
		}
		for (int l1690 = 0; (l1690 < 2); l1690 = (l1690 + 1)) {
			fRec2455[l1690] = 0.0;
			
		}
		for (int l1691 = 0; (l1691 < 2); l1691 = (l1691 + 1)) {
			fRec2454[l1691] = 0.0;
			
		}
		for (int l1692 = 0; (l1692 < 2); l1692 = (l1692 + 1)) {
			fRec2452[l1692] = 0.0;
			
		}
		for (int l1693 = 0; (l1693 < 2); l1693 = (l1693 + 1)) {
			fRec2451[l1693] = 0.0;
			
		}
		for (int l1694 = 0; (l1694 < 2); l1694 = (l1694 + 1)) {
			fRec2449[l1694] = 0.0;
			
		}
		for (int l1695 = 0; (l1695 < 2); l1695 = (l1695 + 1)) {
			fRec2448[l1695] = 0.0;
			
		}
		for (int l1696 = 0; (l1696 < 2); l1696 = (l1696 + 1)) {
			fRec2446[l1696] = 0.0;
			
		}
		for (int l1697 = 0; (l1697 < 2); l1697 = (l1697 + 1)) {
			fRec2478[l1697] = 0.0;
			
		}
		for (int l1698 = 0; (l1698 < 2); l1698 = (l1698 + 1)) {
			fRec2476[l1698] = 0.0;
			
		}
		for (int l1699 = 0; (l1699 < 2); l1699 = (l1699 + 1)) {
			fRec2475[l1699] = 0.0;
			
		}
		for (int l1700 = 0; (l1700 < 2); l1700 = (l1700 + 1)) {
			fRec2473[l1700] = 0.0;
			
		}
		for (int l1701 = 0; (l1701 < 2); l1701 = (l1701 + 1)) {
			fRec2472[l1701] = 0.0;
			
		}
		for (int l1702 = 0; (l1702 < 2); l1702 = (l1702 + 1)) {
			fRec2470[l1702] = 0.0;
			
		}
		for (int l1703 = 0; (l1703 < 2); l1703 = (l1703 + 1)) {
			fRec2469[l1703] = 0.0;
			
		}
		for (int l1704 = 0; (l1704 < 2); l1704 = (l1704 + 1)) {
			fRec2467[l1704] = 0.0;
			
		}
		for (int l1705 = 0; (l1705 < 2); l1705 = (l1705 + 1)) {
			fRec2466[l1705] = 0.0;
			
		}
		for (int l1706 = 0; (l1706 < 2); l1706 = (l1706 + 1)) {
			fRec2464[l1706] = 0.0;
			
		}
		for (int l1707 = 0; (l1707 < 2); l1707 = (l1707 + 1)) {
			fRec2490[l1707] = 0.0;
			
		}
		for (int l1708 = 0; (l1708 < 2); l1708 = (l1708 + 1)) {
			fRec2488[l1708] = 0.0;
			
		}
		for (int l1709 = 0; (l1709 < 2); l1709 = (l1709 + 1)) {
			fRec2487[l1709] = 0.0;
			
		}
		for (int l1710 = 0; (l1710 < 2); l1710 = (l1710 + 1)) {
			fRec2485[l1710] = 0.0;
			
		}
		for (int l1711 = 0; (l1711 < 2); l1711 = (l1711 + 1)) {
			fRec2484[l1711] = 0.0;
			
		}
		for (int l1712 = 0; (l1712 < 2); l1712 = (l1712 + 1)) {
			fRec2482[l1712] = 0.0;
			
		}
		for (int l1713 = 0; (l1713 < 2); l1713 = (l1713 + 1)) {
			fRec2481[l1713] = 0.0;
			
		}
		for (int l1714 = 0; (l1714 < 2); l1714 = (l1714 + 1)) {
			fRec2479[l1714] = 0.0;
			
		}
		for (int l1715 = 0; (l1715 < 2); l1715 = (l1715 + 1)) {
			fRec2499[l1715] = 0.0;
			
		}
		for (int l1716 = 0; (l1716 < 2); l1716 = (l1716 + 1)) {
			fRec2497[l1716] = 0.0;
			
		}
		for (int l1717 = 0; (l1717 < 2); l1717 = (l1717 + 1)) {
			fRec2496[l1717] = 0.0;
			
		}
		for (int l1718 = 0; (l1718 < 2); l1718 = (l1718 + 1)) {
			fRec2494[l1718] = 0.0;
			
		}
		for (int l1719 = 0; (l1719 < 2); l1719 = (l1719 + 1)) {
			fRec2493[l1719] = 0.0;
			
		}
		for (int l1720 = 0; (l1720 < 2); l1720 = (l1720 + 1)) {
			fRec2491[l1720] = 0.0;
			
		}
		for (int l1721 = 0; (l1721 < 2); l1721 = (l1721 + 1)) {
			fRec2502[l1721] = 0.0;
			
		}
		for (int l1722 = 0; (l1722 < 2); l1722 = (l1722 + 1)) {
			fRec2500[l1722] = 0.0;
			
		}
		for (int l1723 = 0; (l1723 < 2); l1723 = (l1723 + 1)) {
			fRec2508[l1723] = 0.0;
			
		}
		for (int l1724 = 0; (l1724 < 2); l1724 = (l1724 + 1)) {
			fRec2506[l1724] = 0.0;
			
		}
		for (int l1725 = 0; (l1725 < 2); l1725 = (l1725 + 1)) {
			fRec2505[l1725] = 0.0;
			
		}
		for (int l1726 = 0; (l1726 < 2); l1726 = (l1726 + 1)) {
			fRec2503[l1726] = 0.0;
			
		}
		for (int l1727 = 0; (l1727 < 512); l1727 = (l1727 + 1)) {
			fVec37[l1727] = 0.0;
			
		}
		for (int l1728 = 0; (l1728 < 2); l1728 = (l1728 + 1)) {
			fRec2526[l1728] = 0.0;
			
		}
		for (int l1729 = 0; (l1729 < 2); l1729 = (l1729 + 1)) {
			fRec2524[l1729] = 0.0;
			
		}
		for (int l1730 = 0; (l1730 < 2); l1730 = (l1730 + 1)) {
			fRec2523[l1730] = 0.0;
			
		}
		for (int l1731 = 0; (l1731 < 2); l1731 = (l1731 + 1)) {
			fRec2521[l1731] = 0.0;
			
		}
		for (int l1732 = 0; (l1732 < 2); l1732 = (l1732 + 1)) {
			fRec2520[l1732] = 0.0;
			
		}
		for (int l1733 = 0; (l1733 < 2); l1733 = (l1733 + 1)) {
			fRec2518[l1733] = 0.0;
			
		}
		for (int l1734 = 0; (l1734 < 2); l1734 = (l1734 + 1)) {
			fRec2517[l1734] = 0.0;
			
		}
		for (int l1735 = 0; (l1735 < 2); l1735 = (l1735 + 1)) {
			fRec2515[l1735] = 0.0;
			
		}
		for (int l1736 = 0; (l1736 < 2); l1736 = (l1736 + 1)) {
			fRec2514[l1736] = 0.0;
			
		}
		for (int l1737 = 0; (l1737 < 2); l1737 = (l1737 + 1)) {
			fRec2512[l1737] = 0.0;
			
		}
		for (int l1738 = 0; (l1738 < 2); l1738 = (l1738 + 1)) {
			fRec2511[l1738] = 0.0;
			
		}
		for (int l1739 = 0; (l1739 < 2); l1739 = (l1739 + 1)) {
			fRec2509[l1739] = 0.0;
			
		}
		for (int l1740 = 0; (l1740 < 2); l1740 = (l1740 + 1)) {
			fRec2541[l1740] = 0.0;
			
		}
		for (int l1741 = 0; (l1741 < 2); l1741 = (l1741 + 1)) {
			fRec2539[l1741] = 0.0;
			
		}
		for (int l1742 = 0; (l1742 < 2); l1742 = (l1742 + 1)) {
			fRec2538[l1742] = 0.0;
			
		}
		for (int l1743 = 0; (l1743 < 2); l1743 = (l1743 + 1)) {
			fRec2536[l1743] = 0.0;
			
		}
		for (int l1744 = 0; (l1744 < 2); l1744 = (l1744 + 1)) {
			fRec2535[l1744] = 0.0;
			
		}
		for (int l1745 = 0; (l1745 < 2); l1745 = (l1745 + 1)) {
			fRec2533[l1745] = 0.0;
			
		}
		for (int l1746 = 0; (l1746 < 2); l1746 = (l1746 + 1)) {
			fRec2532[l1746] = 0.0;
			
		}
		for (int l1747 = 0; (l1747 < 2); l1747 = (l1747 + 1)) {
			fRec2530[l1747] = 0.0;
			
		}
		for (int l1748 = 0; (l1748 < 2); l1748 = (l1748 + 1)) {
			fRec2529[l1748] = 0.0;
			
		}
		for (int l1749 = 0; (l1749 < 2); l1749 = (l1749 + 1)) {
			fRec2527[l1749] = 0.0;
			
		}
		for (int l1750 = 0; (l1750 < 2); l1750 = (l1750 + 1)) {
			fRec2553[l1750] = 0.0;
			
		}
		for (int l1751 = 0; (l1751 < 2); l1751 = (l1751 + 1)) {
			fRec2551[l1751] = 0.0;
			
		}
		for (int l1752 = 0; (l1752 < 2); l1752 = (l1752 + 1)) {
			fRec2550[l1752] = 0.0;
			
		}
		for (int l1753 = 0; (l1753 < 2); l1753 = (l1753 + 1)) {
			fRec2548[l1753] = 0.0;
			
		}
		for (int l1754 = 0; (l1754 < 2); l1754 = (l1754 + 1)) {
			fRec2547[l1754] = 0.0;
			
		}
		for (int l1755 = 0; (l1755 < 2); l1755 = (l1755 + 1)) {
			fRec2545[l1755] = 0.0;
			
		}
		for (int l1756 = 0; (l1756 < 2); l1756 = (l1756 + 1)) {
			fRec2544[l1756] = 0.0;
			
		}
		for (int l1757 = 0; (l1757 < 2); l1757 = (l1757 + 1)) {
			fRec2542[l1757] = 0.0;
			
		}
		for (int l1758 = 0; (l1758 < 2); l1758 = (l1758 + 1)) {
			fRec2562[l1758] = 0.0;
			
		}
		for (int l1759 = 0; (l1759 < 2); l1759 = (l1759 + 1)) {
			fRec2560[l1759] = 0.0;
			
		}
		for (int l1760 = 0; (l1760 < 2); l1760 = (l1760 + 1)) {
			fRec2559[l1760] = 0.0;
			
		}
		for (int l1761 = 0; (l1761 < 2); l1761 = (l1761 + 1)) {
			fRec2557[l1761] = 0.0;
			
		}
		for (int l1762 = 0; (l1762 < 2); l1762 = (l1762 + 1)) {
			fRec2556[l1762] = 0.0;
			
		}
		for (int l1763 = 0; (l1763 < 2); l1763 = (l1763 + 1)) {
			fRec2554[l1763] = 0.0;
			
		}
		for (int l1764 = 0; (l1764 < 2); l1764 = (l1764 + 1)) {
			fRec2565[l1764] = 0.0;
			
		}
		for (int l1765 = 0; (l1765 < 2); l1765 = (l1765 + 1)) {
			fRec2563[l1765] = 0.0;
			
		}
		for (int l1766 = 0; (l1766 < 2); l1766 = (l1766 + 1)) {
			fRec2571[l1766] = 0.0;
			
		}
		for (int l1767 = 0; (l1767 < 2); l1767 = (l1767 + 1)) {
			fRec2569[l1767] = 0.0;
			
		}
		for (int l1768 = 0; (l1768 < 2); l1768 = (l1768 + 1)) {
			fRec2568[l1768] = 0.0;
			
		}
		for (int l1769 = 0; (l1769 < 2); l1769 = (l1769 + 1)) {
			fRec2566[l1769] = 0.0;
			
		}
		for (int l1770 = 0; (l1770 < 512); l1770 = (l1770 + 1)) {
			fVec38[l1770] = 0.0;
			
		}
		for (int l1771 = 0; (l1771 < 2); l1771 = (l1771 + 1)) {
			fRec2589[l1771] = 0.0;
			
		}
		for (int l1772 = 0; (l1772 < 2); l1772 = (l1772 + 1)) {
			fRec2587[l1772] = 0.0;
			
		}
		for (int l1773 = 0; (l1773 < 2); l1773 = (l1773 + 1)) {
			fRec2586[l1773] = 0.0;
			
		}
		for (int l1774 = 0; (l1774 < 2); l1774 = (l1774 + 1)) {
			fRec2584[l1774] = 0.0;
			
		}
		for (int l1775 = 0; (l1775 < 2); l1775 = (l1775 + 1)) {
			fRec2583[l1775] = 0.0;
			
		}
		for (int l1776 = 0; (l1776 < 2); l1776 = (l1776 + 1)) {
			fRec2581[l1776] = 0.0;
			
		}
		for (int l1777 = 0; (l1777 < 2); l1777 = (l1777 + 1)) {
			fRec2580[l1777] = 0.0;
			
		}
		for (int l1778 = 0; (l1778 < 2); l1778 = (l1778 + 1)) {
			fRec2578[l1778] = 0.0;
			
		}
		for (int l1779 = 0; (l1779 < 2); l1779 = (l1779 + 1)) {
			fRec2577[l1779] = 0.0;
			
		}
		for (int l1780 = 0; (l1780 < 2); l1780 = (l1780 + 1)) {
			fRec2575[l1780] = 0.0;
			
		}
		for (int l1781 = 0; (l1781 < 2); l1781 = (l1781 + 1)) {
			fRec2574[l1781] = 0.0;
			
		}
		for (int l1782 = 0; (l1782 < 2); l1782 = (l1782 + 1)) {
			fRec2572[l1782] = 0.0;
			
		}
		for (int l1783 = 0; (l1783 < 2); l1783 = (l1783 + 1)) {
			fRec2604[l1783] = 0.0;
			
		}
		for (int l1784 = 0; (l1784 < 2); l1784 = (l1784 + 1)) {
			fRec2602[l1784] = 0.0;
			
		}
		for (int l1785 = 0; (l1785 < 2); l1785 = (l1785 + 1)) {
			fRec2601[l1785] = 0.0;
			
		}
		for (int l1786 = 0; (l1786 < 2); l1786 = (l1786 + 1)) {
			fRec2599[l1786] = 0.0;
			
		}
		for (int l1787 = 0; (l1787 < 2); l1787 = (l1787 + 1)) {
			fRec2598[l1787] = 0.0;
			
		}
		for (int l1788 = 0; (l1788 < 2); l1788 = (l1788 + 1)) {
			fRec2596[l1788] = 0.0;
			
		}
		for (int l1789 = 0; (l1789 < 2); l1789 = (l1789 + 1)) {
			fRec2595[l1789] = 0.0;
			
		}
		for (int l1790 = 0; (l1790 < 2); l1790 = (l1790 + 1)) {
			fRec2593[l1790] = 0.0;
			
		}
		for (int l1791 = 0; (l1791 < 2); l1791 = (l1791 + 1)) {
			fRec2592[l1791] = 0.0;
			
		}
		for (int l1792 = 0; (l1792 < 2); l1792 = (l1792 + 1)) {
			fRec2590[l1792] = 0.0;
			
		}
		for (int l1793 = 0; (l1793 < 2); l1793 = (l1793 + 1)) {
			fRec2616[l1793] = 0.0;
			
		}
		for (int l1794 = 0; (l1794 < 2); l1794 = (l1794 + 1)) {
			fRec2614[l1794] = 0.0;
			
		}
		for (int l1795 = 0; (l1795 < 2); l1795 = (l1795 + 1)) {
			fRec2613[l1795] = 0.0;
			
		}
		for (int l1796 = 0; (l1796 < 2); l1796 = (l1796 + 1)) {
			fRec2611[l1796] = 0.0;
			
		}
		for (int l1797 = 0; (l1797 < 2); l1797 = (l1797 + 1)) {
			fRec2610[l1797] = 0.0;
			
		}
		for (int l1798 = 0; (l1798 < 2); l1798 = (l1798 + 1)) {
			fRec2608[l1798] = 0.0;
			
		}
		for (int l1799 = 0; (l1799 < 2); l1799 = (l1799 + 1)) {
			fRec2607[l1799] = 0.0;
			
		}
		for (int l1800 = 0; (l1800 < 2); l1800 = (l1800 + 1)) {
			fRec2605[l1800] = 0.0;
			
		}
		for (int l1801 = 0; (l1801 < 2); l1801 = (l1801 + 1)) {
			fRec2625[l1801] = 0.0;
			
		}
		for (int l1802 = 0; (l1802 < 2); l1802 = (l1802 + 1)) {
			fRec2623[l1802] = 0.0;
			
		}
		for (int l1803 = 0; (l1803 < 2); l1803 = (l1803 + 1)) {
			fRec2622[l1803] = 0.0;
			
		}
		for (int l1804 = 0; (l1804 < 2); l1804 = (l1804 + 1)) {
			fRec2620[l1804] = 0.0;
			
		}
		for (int l1805 = 0; (l1805 < 2); l1805 = (l1805 + 1)) {
			fRec2619[l1805] = 0.0;
			
		}
		for (int l1806 = 0; (l1806 < 2); l1806 = (l1806 + 1)) {
			fRec2617[l1806] = 0.0;
			
		}
		for (int l1807 = 0; (l1807 < 2); l1807 = (l1807 + 1)) {
			fRec2628[l1807] = 0.0;
			
		}
		for (int l1808 = 0; (l1808 < 2); l1808 = (l1808 + 1)) {
			fRec2626[l1808] = 0.0;
			
		}
		for (int l1809 = 0; (l1809 < 2); l1809 = (l1809 + 1)) {
			fRec2634[l1809] = 0.0;
			
		}
		for (int l1810 = 0; (l1810 < 2); l1810 = (l1810 + 1)) {
			fRec2632[l1810] = 0.0;
			
		}
		for (int l1811 = 0; (l1811 < 2); l1811 = (l1811 + 1)) {
			fRec2631[l1811] = 0.0;
			
		}
		for (int l1812 = 0; (l1812 < 2); l1812 = (l1812 + 1)) {
			fRec2629[l1812] = 0.0;
			
		}
		for (int l1813 = 0; (l1813 < 512); l1813 = (l1813 + 1)) {
			fVec39[l1813] = 0.0;
			
		}
		for (int l1814 = 0; (l1814 < 2); l1814 = (l1814 + 1)) {
			fRec2652[l1814] = 0.0;
			
		}
		for (int l1815 = 0; (l1815 < 2); l1815 = (l1815 + 1)) {
			fRec2650[l1815] = 0.0;
			
		}
		for (int l1816 = 0; (l1816 < 2); l1816 = (l1816 + 1)) {
			fRec2649[l1816] = 0.0;
			
		}
		for (int l1817 = 0; (l1817 < 2); l1817 = (l1817 + 1)) {
			fRec2647[l1817] = 0.0;
			
		}
		for (int l1818 = 0; (l1818 < 2); l1818 = (l1818 + 1)) {
			fRec2646[l1818] = 0.0;
			
		}
		for (int l1819 = 0; (l1819 < 2); l1819 = (l1819 + 1)) {
			fRec2644[l1819] = 0.0;
			
		}
		for (int l1820 = 0; (l1820 < 2); l1820 = (l1820 + 1)) {
			fRec2643[l1820] = 0.0;
			
		}
		for (int l1821 = 0; (l1821 < 2); l1821 = (l1821 + 1)) {
			fRec2641[l1821] = 0.0;
			
		}
		for (int l1822 = 0; (l1822 < 2); l1822 = (l1822 + 1)) {
			fRec2640[l1822] = 0.0;
			
		}
		for (int l1823 = 0; (l1823 < 2); l1823 = (l1823 + 1)) {
			fRec2638[l1823] = 0.0;
			
		}
		for (int l1824 = 0; (l1824 < 2); l1824 = (l1824 + 1)) {
			fRec2637[l1824] = 0.0;
			
		}
		for (int l1825 = 0; (l1825 < 2); l1825 = (l1825 + 1)) {
			fRec2635[l1825] = 0.0;
			
		}
		for (int l1826 = 0; (l1826 < 2); l1826 = (l1826 + 1)) {
			fRec2667[l1826] = 0.0;
			
		}
		for (int l1827 = 0; (l1827 < 2); l1827 = (l1827 + 1)) {
			fRec2665[l1827] = 0.0;
			
		}
		for (int l1828 = 0; (l1828 < 2); l1828 = (l1828 + 1)) {
			fRec2664[l1828] = 0.0;
			
		}
		for (int l1829 = 0; (l1829 < 2); l1829 = (l1829 + 1)) {
			fRec2662[l1829] = 0.0;
			
		}
		for (int l1830 = 0; (l1830 < 2); l1830 = (l1830 + 1)) {
			fRec2661[l1830] = 0.0;
			
		}
		for (int l1831 = 0; (l1831 < 2); l1831 = (l1831 + 1)) {
			fRec2659[l1831] = 0.0;
			
		}
		for (int l1832 = 0; (l1832 < 2); l1832 = (l1832 + 1)) {
			fRec2658[l1832] = 0.0;
			
		}
		for (int l1833 = 0; (l1833 < 2); l1833 = (l1833 + 1)) {
			fRec2656[l1833] = 0.0;
			
		}
		for (int l1834 = 0; (l1834 < 2); l1834 = (l1834 + 1)) {
			fRec2655[l1834] = 0.0;
			
		}
		for (int l1835 = 0; (l1835 < 2); l1835 = (l1835 + 1)) {
			fRec2653[l1835] = 0.0;
			
		}
		for (int l1836 = 0; (l1836 < 2); l1836 = (l1836 + 1)) {
			fRec2679[l1836] = 0.0;
			
		}
		for (int l1837 = 0; (l1837 < 2); l1837 = (l1837 + 1)) {
			fRec2677[l1837] = 0.0;
			
		}
		for (int l1838 = 0; (l1838 < 2); l1838 = (l1838 + 1)) {
			fRec2676[l1838] = 0.0;
			
		}
		for (int l1839 = 0; (l1839 < 2); l1839 = (l1839 + 1)) {
			fRec2674[l1839] = 0.0;
			
		}
		for (int l1840 = 0; (l1840 < 2); l1840 = (l1840 + 1)) {
			fRec2673[l1840] = 0.0;
			
		}
		for (int l1841 = 0; (l1841 < 2); l1841 = (l1841 + 1)) {
			fRec2671[l1841] = 0.0;
			
		}
		for (int l1842 = 0; (l1842 < 2); l1842 = (l1842 + 1)) {
			fRec2670[l1842] = 0.0;
			
		}
		for (int l1843 = 0; (l1843 < 2); l1843 = (l1843 + 1)) {
			fRec2668[l1843] = 0.0;
			
		}
		for (int l1844 = 0; (l1844 < 2); l1844 = (l1844 + 1)) {
			fRec2688[l1844] = 0.0;
			
		}
		for (int l1845 = 0; (l1845 < 2); l1845 = (l1845 + 1)) {
			fRec2686[l1845] = 0.0;
			
		}
		for (int l1846 = 0; (l1846 < 2); l1846 = (l1846 + 1)) {
			fRec2685[l1846] = 0.0;
			
		}
		for (int l1847 = 0; (l1847 < 2); l1847 = (l1847 + 1)) {
			fRec2683[l1847] = 0.0;
			
		}
		for (int l1848 = 0; (l1848 < 2); l1848 = (l1848 + 1)) {
			fRec2682[l1848] = 0.0;
			
		}
		for (int l1849 = 0; (l1849 < 2); l1849 = (l1849 + 1)) {
			fRec2680[l1849] = 0.0;
			
		}
		for (int l1850 = 0; (l1850 < 2); l1850 = (l1850 + 1)) {
			fRec2691[l1850] = 0.0;
			
		}
		for (int l1851 = 0; (l1851 < 2); l1851 = (l1851 + 1)) {
			fRec2689[l1851] = 0.0;
			
		}
		for (int l1852 = 0; (l1852 < 2); l1852 = (l1852 + 1)) {
			fRec2697[l1852] = 0.0;
			
		}
		for (int l1853 = 0; (l1853 < 2); l1853 = (l1853 + 1)) {
			fRec2695[l1853] = 0.0;
			
		}
		for (int l1854 = 0; (l1854 < 2); l1854 = (l1854 + 1)) {
			fRec2694[l1854] = 0.0;
			
		}
		for (int l1855 = 0; (l1855 < 2); l1855 = (l1855 + 1)) {
			fRec2692[l1855] = 0.0;
			
		}
		for (int l1856 = 0; (l1856 < 512); l1856 = (l1856 + 1)) {
			fVec40[l1856] = 0.0;
			
		}
		for (int l1857 = 0; (l1857 < 2); l1857 = (l1857 + 1)) {
			fRec2715[l1857] = 0.0;
			
		}
		for (int l1858 = 0; (l1858 < 2); l1858 = (l1858 + 1)) {
			fRec2713[l1858] = 0.0;
			
		}
		for (int l1859 = 0; (l1859 < 2); l1859 = (l1859 + 1)) {
			fRec2712[l1859] = 0.0;
			
		}
		for (int l1860 = 0; (l1860 < 2); l1860 = (l1860 + 1)) {
			fRec2710[l1860] = 0.0;
			
		}
		for (int l1861 = 0; (l1861 < 2); l1861 = (l1861 + 1)) {
			fRec2709[l1861] = 0.0;
			
		}
		for (int l1862 = 0; (l1862 < 2); l1862 = (l1862 + 1)) {
			fRec2707[l1862] = 0.0;
			
		}
		for (int l1863 = 0; (l1863 < 2); l1863 = (l1863 + 1)) {
			fRec2706[l1863] = 0.0;
			
		}
		for (int l1864 = 0; (l1864 < 2); l1864 = (l1864 + 1)) {
			fRec2704[l1864] = 0.0;
			
		}
		for (int l1865 = 0; (l1865 < 2); l1865 = (l1865 + 1)) {
			fRec2703[l1865] = 0.0;
			
		}
		for (int l1866 = 0; (l1866 < 2); l1866 = (l1866 + 1)) {
			fRec2701[l1866] = 0.0;
			
		}
		for (int l1867 = 0; (l1867 < 2); l1867 = (l1867 + 1)) {
			fRec2700[l1867] = 0.0;
			
		}
		for (int l1868 = 0; (l1868 < 2); l1868 = (l1868 + 1)) {
			fRec2698[l1868] = 0.0;
			
		}
		for (int l1869 = 0; (l1869 < 2); l1869 = (l1869 + 1)) {
			fRec2730[l1869] = 0.0;
			
		}
		for (int l1870 = 0; (l1870 < 2); l1870 = (l1870 + 1)) {
			fRec2728[l1870] = 0.0;
			
		}
		for (int l1871 = 0; (l1871 < 2); l1871 = (l1871 + 1)) {
			fRec2727[l1871] = 0.0;
			
		}
		for (int l1872 = 0; (l1872 < 2); l1872 = (l1872 + 1)) {
			fRec2725[l1872] = 0.0;
			
		}
		for (int l1873 = 0; (l1873 < 2); l1873 = (l1873 + 1)) {
			fRec2724[l1873] = 0.0;
			
		}
		for (int l1874 = 0; (l1874 < 2); l1874 = (l1874 + 1)) {
			fRec2722[l1874] = 0.0;
			
		}
		for (int l1875 = 0; (l1875 < 2); l1875 = (l1875 + 1)) {
			fRec2721[l1875] = 0.0;
			
		}
		for (int l1876 = 0; (l1876 < 2); l1876 = (l1876 + 1)) {
			fRec2719[l1876] = 0.0;
			
		}
		for (int l1877 = 0; (l1877 < 2); l1877 = (l1877 + 1)) {
			fRec2718[l1877] = 0.0;
			
		}
		for (int l1878 = 0; (l1878 < 2); l1878 = (l1878 + 1)) {
			fRec2716[l1878] = 0.0;
			
		}
		for (int l1879 = 0; (l1879 < 2); l1879 = (l1879 + 1)) {
			fRec2742[l1879] = 0.0;
			
		}
		for (int l1880 = 0; (l1880 < 2); l1880 = (l1880 + 1)) {
			fRec2740[l1880] = 0.0;
			
		}
		for (int l1881 = 0; (l1881 < 2); l1881 = (l1881 + 1)) {
			fRec2739[l1881] = 0.0;
			
		}
		for (int l1882 = 0; (l1882 < 2); l1882 = (l1882 + 1)) {
			fRec2737[l1882] = 0.0;
			
		}
		for (int l1883 = 0; (l1883 < 2); l1883 = (l1883 + 1)) {
			fRec2736[l1883] = 0.0;
			
		}
		for (int l1884 = 0; (l1884 < 2); l1884 = (l1884 + 1)) {
			fRec2734[l1884] = 0.0;
			
		}
		for (int l1885 = 0; (l1885 < 2); l1885 = (l1885 + 1)) {
			fRec2733[l1885] = 0.0;
			
		}
		for (int l1886 = 0; (l1886 < 2); l1886 = (l1886 + 1)) {
			fRec2731[l1886] = 0.0;
			
		}
		for (int l1887 = 0; (l1887 < 2); l1887 = (l1887 + 1)) {
			fRec2751[l1887] = 0.0;
			
		}
		for (int l1888 = 0; (l1888 < 2); l1888 = (l1888 + 1)) {
			fRec2749[l1888] = 0.0;
			
		}
		for (int l1889 = 0; (l1889 < 2); l1889 = (l1889 + 1)) {
			fRec2748[l1889] = 0.0;
			
		}
		for (int l1890 = 0; (l1890 < 2); l1890 = (l1890 + 1)) {
			fRec2746[l1890] = 0.0;
			
		}
		for (int l1891 = 0; (l1891 < 2); l1891 = (l1891 + 1)) {
			fRec2745[l1891] = 0.0;
			
		}
		for (int l1892 = 0; (l1892 < 2); l1892 = (l1892 + 1)) {
			fRec2743[l1892] = 0.0;
			
		}
		for (int l1893 = 0; (l1893 < 2); l1893 = (l1893 + 1)) {
			fRec2754[l1893] = 0.0;
			
		}
		for (int l1894 = 0; (l1894 < 2); l1894 = (l1894 + 1)) {
			fRec2752[l1894] = 0.0;
			
		}
		for (int l1895 = 0; (l1895 < 2); l1895 = (l1895 + 1)) {
			fRec2760[l1895] = 0.0;
			
		}
		for (int l1896 = 0; (l1896 < 2); l1896 = (l1896 + 1)) {
			fRec2758[l1896] = 0.0;
			
		}
		for (int l1897 = 0; (l1897 < 2); l1897 = (l1897 + 1)) {
			fRec2757[l1897] = 0.0;
			
		}
		for (int l1898 = 0; (l1898 < 2); l1898 = (l1898 + 1)) {
			fRec2755[l1898] = 0.0;
			
		}
		for (int l1899 = 0; (l1899 < 512); l1899 = (l1899 + 1)) {
			fVec41[l1899] = 0.0;
			
		}
		for (int l1900 = 0; (l1900 < 2); l1900 = (l1900 + 1)) {
			fRec2778[l1900] = 0.0;
			
		}
		for (int l1901 = 0; (l1901 < 2); l1901 = (l1901 + 1)) {
			fRec2776[l1901] = 0.0;
			
		}
		for (int l1902 = 0; (l1902 < 2); l1902 = (l1902 + 1)) {
			fRec2775[l1902] = 0.0;
			
		}
		for (int l1903 = 0; (l1903 < 2); l1903 = (l1903 + 1)) {
			fRec2773[l1903] = 0.0;
			
		}
		for (int l1904 = 0; (l1904 < 2); l1904 = (l1904 + 1)) {
			fRec2772[l1904] = 0.0;
			
		}
		for (int l1905 = 0; (l1905 < 2); l1905 = (l1905 + 1)) {
			fRec2770[l1905] = 0.0;
			
		}
		for (int l1906 = 0; (l1906 < 2); l1906 = (l1906 + 1)) {
			fRec2769[l1906] = 0.0;
			
		}
		for (int l1907 = 0; (l1907 < 2); l1907 = (l1907 + 1)) {
			fRec2767[l1907] = 0.0;
			
		}
		for (int l1908 = 0; (l1908 < 2); l1908 = (l1908 + 1)) {
			fRec2766[l1908] = 0.0;
			
		}
		for (int l1909 = 0; (l1909 < 2); l1909 = (l1909 + 1)) {
			fRec2764[l1909] = 0.0;
			
		}
		for (int l1910 = 0; (l1910 < 2); l1910 = (l1910 + 1)) {
			fRec2763[l1910] = 0.0;
			
		}
		for (int l1911 = 0; (l1911 < 2); l1911 = (l1911 + 1)) {
			fRec2761[l1911] = 0.0;
			
		}
		for (int l1912 = 0; (l1912 < 2); l1912 = (l1912 + 1)) {
			fRec2793[l1912] = 0.0;
			
		}
		for (int l1913 = 0; (l1913 < 2); l1913 = (l1913 + 1)) {
			fRec2791[l1913] = 0.0;
			
		}
		for (int l1914 = 0; (l1914 < 2); l1914 = (l1914 + 1)) {
			fRec2790[l1914] = 0.0;
			
		}
		for (int l1915 = 0; (l1915 < 2); l1915 = (l1915 + 1)) {
			fRec2788[l1915] = 0.0;
			
		}
		for (int l1916 = 0; (l1916 < 2); l1916 = (l1916 + 1)) {
			fRec2787[l1916] = 0.0;
			
		}
		for (int l1917 = 0; (l1917 < 2); l1917 = (l1917 + 1)) {
			fRec2785[l1917] = 0.0;
			
		}
		for (int l1918 = 0; (l1918 < 2); l1918 = (l1918 + 1)) {
			fRec2784[l1918] = 0.0;
			
		}
		for (int l1919 = 0; (l1919 < 2); l1919 = (l1919 + 1)) {
			fRec2782[l1919] = 0.0;
			
		}
		for (int l1920 = 0; (l1920 < 2); l1920 = (l1920 + 1)) {
			fRec2781[l1920] = 0.0;
			
		}
		for (int l1921 = 0; (l1921 < 2); l1921 = (l1921 + 1)) {
			fRec2779[l1921] = 0.0;
			
		}
		for (int l1922 = 0; (l1922 < 2); l1922 = (l1922 + 1)) {
			fRec2805[l1922] = 0.0;
			
		}
		for (int l1923 = 0; (l1923 < 2); l1923 = (l1923 + 1)) {
			fRec2803[l1923] = 0.0;
			
		}
		for (int l1924 = 0; (l1924 < 2); l1924 = (l1924 + 1)) {
			fRec2802[l1924] = 0.0;
			
		}
		for (int l1925 = 0; (l1925 < 2); l1925 = (l1925 + 1)) {
			fRec2800[l1925] = 0.0;
			
		}
		for (int l1926 = 0; (l1926 < 2); l1926 = (l1926 + 1)) {
			fRec2799[l1926] = 0.0;
			
		}
		for (int l1927 = 0; (l1927 < 2); l1927 = (l1927 + 1)) {
			fRec2797[l1927] = 0.0;
			
		}
		for (int l1928 = 0; (l1928 < 2); l1928 = (l1928 + 1)) {
			fRec2796[l1928] = 0.0;
			
		}
		for (int l1929 = 0; (l1929 < 2); l1929 = (l1929 + 1)) {
			fRec2794[l1929] = 0.0;
			
		}
		for (int l1930 = 0; (l1930 < 2); l1930 = (l1930 + 1)) {
			fRec2814[l1930] = 0.0;
			
		}
		for (int l1931 = 0; (l1931 < 2); l1931 = (l1931 + 1)) {
			fRec2812[l1931] = 0.0;
			
		}
		for (int l1932 = 0; (l1932 < 2); l1932 = (l1932 + 1)) {
			fRec2811[l1932] = 0.0;
			
		}
		for (int l1933 = 0; (l1933 < 2); l1933 = (l1933 + 1)) {
			fRec2809[l1933] = 0.0;
			
		}
		for (int l1934 = 0; (l1934 < 2); l1934 = (l1934 + 1)) {
			fRec2808[l1934] = 0.0;
			
		}
		for (int l1935 = 0; (l1935 < 2); l1935 = (l1935 + 1)) {
			fRec2806[l1935] = 0.0;
			
		}
		for (int l1936 = 0; (l1936 < 2); l1936 = (l1936 + 1)) {
			fRec2817[l1936] = 0.0;
			
		}
		for (int l1937 = 0; (l1937 < 2); l1937 = (l1937 + 1)) {
			fRec2815[l1937] = 0.0;
			
		}
		for (int l1938 = 0; (l1938 < 2); l1938 = (l1938 + 1)) {
			fRec2823[l1938] = 0.0;
			
		}
		for (int l1939 = 0; (l1939 < 2); l1939 = (l1939 + 1)) {
			fRec2821[l1939] = 0.0;
			
		}
		for (int l1940 = 0; (l1940 < 2); l1940 = (l1940 + 1)) {
			fRec2820[l1940] = 0.0;
			
		}
		for (int l1941 = 0; (l1941 < 2); l1941 = (l1941 + 1)) {
			fRec2818[l1941] = 0.0;
			
		}
		for (int l1942 = 0; (l1942 < 512); l1942 = (l1942 + 1)) {
			fVec42[l1942] = 0.0;
			
		}
		for (int l1943 = 0; (l1943 < 2); l1943 = (l1943 + 1)) {
			fRec2841[l1943] = 0.0;
			
		}
		for (int l1944 = 0; (l1944 < 2); l1944 = (l1944 + 1)) {
			fRec2839[l1944] = 0.0;
			
		}
		for (int l1945 = 0; (l1945 < 2); l1945 = (l1945 + 1)) {
			fRec2838[l1945] = 0.0;
			
		}
		for (int l1946 = 0; (l1946 < 2); l1946 = (l1946 + 1)) {
			fRec2836[l1946] = 0.0;
			
		}
		for (int l1947 = 0; (l1947 < 2); l1947 = (l1947 + 1)) {
			fRec2835[l1947] = 0.0;
			
		}
		for (int l1948 = 0; (l1948 < 2); l1948 = (l1948 + 1)) {
			fRec2833[l1948] = 0.0;
			
		}
		for (int l1949 = 0; (l1949 < 2); l1949 = (l1949 + 1)) {
			fRec2832[l1949] = 0.0;
			
		}
		for (int l1950 = 0; (l1950 < 2); l1950 = (l1950 + 1)) {
			fRec2830[l1950] = 0.0;
			
		}
		for (int l1951 = 0; (l1951 < 2); l1951 = (l1951 + 1)) {
			fRec2829[l1951] = 0.0;
			
		}
		for (int l1952 = 0; (l1952 < 2); l1952 = (l1952 + 1)) {
			fRec2827[l1952] = 0.0;
			
		}
		for (int l1953 = 0; (l1953 < 2); l1953 = (l1953 + 1)) {
			fRec2826[l1953] = 0.0;
			
		}
		for (int l1954 = 0; (l1954 < 2); l1954 = (l1954 + 1)) {
			fRec2824[l1954] = 0.0;
			
		}
		for (int l1955 = 0; (l1955 < 2); l1955 = (l1955 + 1)) {
			fRec2856[l1955] = 0.0;
			
		}
		for (int l1956 = 0; (l1956 < 2); l1956 = (l1956 + 1)) {
			fRec2854[l1956] = 0.0;
			
		}
		for (int l1957 = 0; (l1957 < 2); l1957 = (l1957 + 1)) {
			fRec2853[l1957] = 0.0;
			
		}
		for (int l1958 = 0; (l1958 < 2); l1958 = (l1958 + 1)) {
			fRec2851[l1958] = 0.0;
			
		}
		for (int l1959 = 0; (l1959 < 2); l1959 = (l1959 + 1)) {
			fRec2850[l1959] = 0.0;
			
		}
		for (int l1960 = 0; (l1960 < 2); l1960 = (l1960 + 1)) {
			fRec2848[l1960] = 0.0;
			
		}
		for (int l1961 = 0; (l1961 < 2); l1961 = (l1961 + 1)) {
			fRec2847[l1961] = 0.0;
			
		}
		for (int l1962 = 0; (l1962 < 2); l1962 = (l1962 + 1)) {
			fRec2845[l1962] = 0.0;
			
		}
		for (int l1963 = 0; (l1963 < 2); l1963 = (l1963 + 1)) {
			fRec2844[l1963] = 0.0;
			
		}
		for (int l1964 = 0; (l1964 < 2); l1964 = (l1964 + 1)) {
			fRec2842[l1964] = 0.0;
			
		}
		for (int l1965 = 0; (l1965 < 2); l1965 = (l1965 + 1)) {
			fRec2868[l1965] = 0.0;
			
		}
		for (int l1966 = 0; (l1966 < 2); l1966 = (l1966 + 1)) {
			fRec2866[l1966] = 0.0;
			
		}
		for (int l1967 = 0; (l1967 < 2); l1967 = (l1967 + 1)) {
			fRec2865[l1967] = 0.0;
			
		}
		for (int l1968 = 0; (l1968 < 2); l1968 = (l1968 + 1)) {
			fRec2863[l1968] = 0.0;
			
		}
		for (int l1969 = 0; (l1969 < 2); l1969 = (l1969 + 1)) {
			fRec2862[l1969] = 0.0;
			
		}
		for (int l1970 = 0; (l1970 < 2); l1970 = (l1970 + 1)) {
			fRec2860[l1970] = 0.0;
			
		}
		for (int l1971 = 0; (l1971 < 2); l1971 = (l1971 + 1)) {
			fRec2859[l1971] = 0.0;
			
		}
		for (int l1972 = 0; (l1972 < 2); l1972 = (l1972 + 1)) {
			fRec2857[l1972] = 0.0;
			
		}
		for (int l1973 = 0; (l1973 < 2); l1973 = (l1973 + 1)) {
			fRec2877[l1973] = 0.0;
			
		}
		for (int l1974 = 0; (l1974 < 2); l1974 = (l1974 + 1)) {
			fRec2875[l1974] = 0.0;
			
		}
		for (int l1975 = 0; (l1975 < 2); l1975 = (l1975 + 1)) {
			fRec2874[l1975] = 0.0;
			
		}
		for (int l1976 = 0; (l1976 < 2); l1976 = (l1976 + 1)) {
			fRec2872[l1976] = 0.0;
			
		}
		for (int l1977 = 0; (l1977 < 2); l1977 = (l1977 + 1)) {
			fRec2871[l1977] = 0.0;
			
		}
		for (int l1978 = 0; (l1978 < 2); l1978 = (l1978 + 1)) {
			fRec2869[l1978] = 0.0;
			
		}
		for (int l1979 = 0; (l1979 < 2); l1979 = (l1979 + 1)) {
			fRec2880[l1979] = 0.0;
			
		}
		for (int l1980 = 0; (l1980 < 2); l1980 = (l1980 + 1)) {
			fRec2878[l1980] = 0.0;
			
		}
		for (int l1981 = 0; (l1981 < 2); l1981 = (l1981 + 1)) {
			fRec2886[l1981] = 0.0;
			
		}
		for (int l1982 = 0; (l1982 < 2); l1982 = (l1982 + 1)) {
			fRec2884[l1982] = 0.0;
			
		}
		for (int l1983 = 0; (l1983 < 2); l1983 = (l1983 + 1)) {
			fRec2883[l1983] = 0.0;
			
		}
		for (int l1984 = 0; (l1984 < 2); l1984 = (l1984 + 1)) {
			fRec2881[l1984] = 0.0;
			
		}
		for (int l1985 = 0; (l1985 < 512); l1985 = (l1985 + 1)) {
			fVec43[l1985] = 0.0;
			
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
		ui_interface->openVerticalBox("KMHLS_FullSetup_6H6V_full_5");
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
		FAUSTFLOAT* input36 = inputs[36];
		FAUSTFLOAT* input37 = inputs[37];
		FAUSTFLOAT* input38 = inputs[38];
		FAUSTFLOAT* input39 = inputs[39];
		FAUSTFLOAT* input40 = inputs[40];
		FAUSTFLOAT* input41 = inputs[41];
		FAUSTFLOAT* input42 = inputs[42];
		FAUSTFLOAT* input43 = inputs[43];
		FAUSTFLOAT* input44 = inputs[44];
		FAUSTFLOAT* input45 = inputs[45];
		FAUSTFLOAT* input46 = inputs[46];
		FAUSTFLOAT* input47 = inputs[47];
		FAUSTFLOAT* input48 = inputs[48];
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
			double fTemp0 = (fConst4 * fRec1[1]);
			double fTemp1 = (fConst5 * fRec4[1]);
			double fTemp2 = (fConst7 * fRec7[1]);
			double fTemp3 = (fConst8 * fRec10[1]);
			fRec20[0] = (fSlow1 + (0.999 * fRec20[1]));
			double fTemp4 = std::tan((fConst11 * fRec20[0]));
			double fTemp5 = ((fTemp4 * (fTemp4 + -2.0)) + 1.0);
			double fTemp6 = mydsp_faustpower2_f(fTemp4);
			double fTemp7 = (fTemp6 + -1.0);
			double fTemp8 = ((fTemp4 * (fTemp4 + 2.0)) + 1.0);
			fRec19[0] = (double(input37[i]) - (((fRec19[2] * fTemp5) + (2.0 * (fRec19[1] * fTemp7))) / fTemp8));
			fRec21[0] = (fSlow2 + (0.999 * fRec21[1]));
			double fTemp9 = (fRec21[0] * fTemp8);
			double fTemp10 = (0.0 - (2.0 / fTemp8));
			double fTemp11 = ((((fRec19[2] + (fRec19[0] + (2.0 * fRec19[1]))) * fTemp6) / fTemp9) + (0.17682772499999999 * (fRec21[0] * (0.0 - ((fRec19[1] * fTemp10) + ((fRec19[0] + fRec19[2]) / fTemp8))))));
			double fTemp12 = (0.041449476800000003 * fTemp11);
			fRec22[0] = (double(input38[i]) - (((fRec22[2] * fTemp5) + (2.0 * (fRec22[1] * fTemp7))) / fTemp8));
			double fTemp13 = ((((fRec22[2] + (fRec22[0] + (2.0 * fRec22[1]))) * fTemp6) / fTemp9) + (0.17682772499999999 * (fRec21[0] * (0.0 - ((fRec22[1] * fTemp10) + ((fRec22[0] + fRec22[2]) / fTemp8))))));
			double fTemp14 = (0.028449488500000002 * fTemp13);
			fRec23[0] = (double(input41[i]) - (((fRec23[2] * fTemp5) + (2.0 * (fRec23[1] * fTemp7))) / fTemp8));
			double fTemp15 = ((((fRec23[2] + (fRec23[0] + (2.0 * fRec23[1]))) * fTemp6) / fTemp9) + (0.17682772499999999 * (fRec21[0] * (0.0 - ((fRec23[1] * fTemp10) + ((fRec23[0] + fRec23[2]) / fTemp8))))));
			double fTemp16 = (0.045223004099999999 * fTemp15);
			fRec24[0] = (double(input42[i]) - (((fRec24[2] * fTemp5) + (2.0 * (fRec24[1] * fTemp7))) / fTemp8));
			double fTemp17 = ((((fRec24[2] + (fRec24[0] + (2.0 * fRec24[1]))) * fTemp6) / fTemp9) + (0.17682772499999999 * (fRec21[0] * (0.0 - ((fRec24[1] * fTemp10) + ((fRec24[0] + fRec24[2]) / fTemp8))))));
			double fTemp18 = (0.029877424199999999 * fTemp17);
			fRec25[0] = (double(input43[i]) - (((fRec25[2] * fTemp5) + (2.0 * (fRec25[1] * fTemp7))) / fTemp8));
			double fTemp19 = ((((fRec25[2] + (fRec25[0] + (2.0 * fRec25[1]))) * fTemp6) / fTemp9) + (0.17682772499999999 * (fRec21[0] * (0.0 - ((fRec25[1] * fTemp10) + ((fRec25[0] + fRec25[2]) / fTemp8))))));
			double fTemp20 = (0.069031775099999998 * fTemp19);
			fRec26[0] = (double(input36[i]) - (((fRec26[2] * fTemp5) + (2.0 * (fRec26[1] * fTemp7))) / fTemp8));
			double fTemp21 = ((((fRec26[2] + (fRec26[0] + (2.0 * fRec26[1]))) * fTemp6) / fTemp9) + (0.17682772499999999 * (fRec21[0] * (0.0 - ((fRec26[1] * fTemp10) + ((fRec26[0] + fRec26[2]) / fTemp8))))));
			double fTemp22 = (0.0037897285000000002 * fTemp21);
			fRec27[0] = (double(input39[i]) - (((fRec27[2] * fTemp5) + (2.0 * (fRec27[1] * fTemp7))) / fTemp8));
			double fTemp23 = ((((fRec27[2] + (fRec27[0] + (2.0 * fRec27[1]))) * fTemp6) / fTemp9) + (0.17682772499999999 * (fRec21[0] * (0.0 - ((fRec27[1] * fTemp10) + ((fRec27[0] + fRec27[2]) / fTemp8))))));
			double fTemp24 = (0.093133545100000006 * fTemp23);
			fRec28[0] = (double(input40[i]) - (((fRec28[2] * fTemp5) + (2.0 * (fRec28[1] * fTemp7))) / fTemp8));
			double fTemp25 = ((((fRec28[2] + (fRec28[0] + (2.0 * fRec28[1]))) * fTemp6) / fTemp9) + (0.17682772499999999 * (fRec21[0] * (0.0 - ((fRec28[1] * fTemp10) + ((fRec28[0] + fRec28[2]) / fTemp8))))));
			double fTemp26 = (0.011094767700000001 * fTemp25);
			fRec29[0] = (double(input44[i]) - (((fRec29[2] * fTemp5) + (2.0 * (fRec29[1] * fTemp7))) / fTemp8));
			double fTemp27 = ((((fRec29[2] + (fRec29[0] + (2.0 * fRec29[1]))) * fTemp6) / fTemp9) + (0.17682772499999999 * (fRec21[0] * (0.0 - ((fRec29[1] * fTemp10) + ((fRec29[0] + fRec29[2]) / fTemp8))))));
			double fTemp28 = (0.0107694825 * fTemp27);
			fRec30[0] = (double(input45[i]) - (((fRec30[2] * fTemp5) + (2.0 * (fRec30[1] * fTemp7))) / fTemp8));
			double fTemp29 = ((((fRec30[2] + (fRec30[0] + (2.0 * fRec30[1]))) * fTemp6) / fTemp9) + (0.17682772499999999 * (fRec21[0] * (0.0 - ((fRec30[1] * fTemp10) + ((fRec30[0] + fRec30[2]) / fTemp8))))));
			double fTemp30 = (0.035267777399999999 * fTemp29);
			fRec31[0] = (double(input46[i]) - (((fRec31[2] * fTemp5) + (2.0 * (fRec31[1] * fTemp7))) / fTemp8));
			double fTemp31 = ((((fRec31[2] + (fRec31[0] + (2.0 * fRec31[1]))) * fTemp6) / fTemp9) + (0.17682772499999999 * (fRec21[0] * (0.0 - ((fRec31[1] * fTemp10) + ((fRec31[0] + fRec31[2]) / fTemp8))))));
			double fTemp32 = (0.068095481900000004 * fTemp31);
			fRec32[0] = (double(input47[i]) - (((fRec32[2] * fTemp5) + (2.0 * (fRec32[1] * fTemp7))) / fTemp8));
			double fTemp33 = ((((fRec32[2] + (fRec32[0] + (2.0 * fRec32[1]))) * fTemp6) / fTemp9) + (0.17682772499999999 * (fRec21[0] * (0.0 - ((fRec32[1] * fTemp10) + ((fRec32[0] + fRec32[2]) / fTemp8))))));
			double fTemp34 = (0.068071180100000003 * fTemp33);
			fRec33[0] = (double(input48[i]) - (((fRec33[2] * fTemp5) + (2.0 * (fRec33[1] * fTemp7))) / fTemp8));
			double fTemp35 = ((((fRec33[2] + (fRec33[0] + (2.0 * fRec33[1]))) * fTemp6) / fTemp9) + (0.17682772499999999 * (fRec21[0] * (0.0 - ((fRec33[1] * fTemp10) + ((fRec33[0] + fRec33[2]) / fTemp8))))));
			double fTemp36 = (0.10552393960000001 * fTemp35);
			double fTemp37 = (fConst10 * (((((fTemp12 + fTemp14) + fTemp16) + fTemp18) + fTemp20) - (((((((fTemp22 + fTemp24) + fTemp26) + fTemp28) + fTemp30) + fTemp32) + fTemp34) + fTemp36)));
			double fTemp38 = (fConst12 * fRec13[1]);
			double fTemp39 = (fConst13 * fRec16[1]);
			fRec18[0] = (fTemp37 + (fTemp38 + (fRec18[1] + fTemp39)));
			fRec16[0] = fRec18[0];
			double fRec17 = ((fTemp39 + fTemp38) + fTemp37);
			fRec15[0] = (fRec16[0] + fRec15[1]);
			fRec13[0] = fRec15[0];
			double fRec14 = fRec17;
			fRec12[0] = (fTemp2 + (fTemp3 + (fRec14 + fRec12[1])));
			fRec10[0] = fRec12[0];
			double fRec11 = (fTemp2 + (fRec14 + fTemp3));
			fRec9[0] = (fRec10[0] + fRec9[1]);
			fRec7[0] = fRec9[0];
			double fRec8 = fRec11;
			fRec6[0] = (fTemp0 + (fTemp1 + (fRec8 + fRec6[1])));
			fRec4[0] = fRec6[0];
			double fRec5 = (fTemp0 + (fRec8 + fTemp1));
			fRec3[0] = (fRec4[0] + fRec3[1]);
			fRec1[0] = fRec3[0];
			double fRec2 = fRec5;
			double fTemp40 = (fConst15 * fRec34[1]);
			double fTemp41 = (fConst17 * fRec37[1]);
			double fTemp42 = (fConst18 * fRec40[1]);
			fRec49[0] = (double(input25[i]) - (((fRec49[2] * fTemp5) + (2.0 * (fRec49[1] * fTemp7))) / fTemp8));
			double fTemp43 = ((((fRec49[2] + (fRec49[0] + (2.0 * fRec49[1]))) * fTemp6) / fTemp9) + (0.36362861800000001 * (fRec21[0] * (0.0 - ((fRec49[1] * fTemp10) + ((fRec49[0] + fRec49[2]) / fTemp8))))));
			double fTemp44 = (0.057142282799999999 * fTemp43);
			fRec50[0] = (double(input26[i]) - (((fRec50[2] * fTemp5) + (2.0 * (fRec50[1] * fTemp7))) / fTemp8));
			double fTemp45 = ((((fRec50[2] + (fRec50[0] + (2.0 * fRec50[1]))) * fTemp6) / fTemp9) + (0.36362861800000001 * (fRec21[0] * (0.0 - ((fRec50[1] * fTemp10) + ((fRec50[0] + fRec50[2]) / fTemp8))))));
			double fTemp46 = (0.081490060700000005 * fTemp45);
			fRec51[0] = (double(input29[i]) - (((fRec51[2] * fTemp5) + (2.0 * (fRec51[1] * fTemp7))) / fTemp8));
			double fTemp47 = ((((fRec51[2] + (fRec51[0] + (2.0 * fRec51[1]))) * fTemp6) / fTemp9) + (0.36362861800000001 * (fRec21[0] * (0.0 - ((fRec51[1] * fTemp10) + ((fRec51[0] + fRec51[2]) / fTemp8))))));
			double fTemp48 = (0.016947781799999999 * fTemp47);
			fRec52[0] = (double(input30[i]) - (((fRec52[2] * fTemp5) + (2.0 * (fRec52[1] * fTemp7))) / fTemp8));
			double fTemp49 = ((((fRec52[2] + (fRec52[0] + (2.0 * fRec52[1]))) * fTemp6) / fTemp9) + (0.36362861800000001 * (fRec21[0] * (0.0 - ((fRec52[1] * fTemp10) + ((fRec52[0] + fRec52[2]) / fTemp8))))));
			double fTemp50 = (0.053976308200000003 * fTemp49);
			fRec53[0] = (double(input31[i]) - (((fRec53[2] * fTemp5) + (2.0 * (fRec53[1] * fTemp7))) / fTemp8));
			double fTemp51 = ((((fRec53[2] + (fRec53[0] + (2.0 * fRec53[1]))) * fTemp6) / fTemp9) + (0.36362861800000001 * (fRec21[0] * (0.0 - ((fRec53[1] * fTemp10) + ((fRec53[0] + fRec53[2]) / fTemp8))))));
			double fTemp52 = (0.016857897 * fTemp51);
			fRec54[0] = (double(input27[i]) - (((fRec54[2] * fTemp5) + (2.0 * (fRec54[1] * fTemp7))) / fTemp8));
			double fTemp53 = ((((fRec54[2] + (fRec54[0] + (2.0 * fRec54[1]))) * fTemp6) / fTemp9) + (0.36362861800000001 * (fRec21[0] * (0.0 - ((fRec54[1] * fTemp10) + ((fRec54[0] + fRec54[2]) / fTemp8))))));
			double fTemp54 = (0.029642125200000001 * fTemp53);
			fRec55[0] = (double(input28[i]) - (((fRec55[2] * fTemp5) + (2.0 * (fRec55[1] * fTemp7))) / fTemp8));
			double fTemp55 = ((((fRec55[2] + (fRec55[0] + (2.0 * fRec55[1]))) * fTemp6) / fTemp9) + (0.36362861800000001 * (fRec21[0] * (0.0 - ((fRec55[1] * fTemp10) + ((fRec55[0] + fRec55[2]) / fTemp8))))));
			double fTemp56 = (0.040566616299999997 * fTemp55);
			fRec56[0] = (double(input32[i]) - (((fRec56[2] * fTemp5) + (2.0 * (fRec56[1] * fTemp7))) / fTemp8));
			double fTemp57 = ((((fRec56[2] + (fRec56[0] + (2.0 * fRec56[1]))) * fTemp6) / fTemp9) + (0.36362861800000001 * (fRec21[0] * (0.0 - ((fRec56[1] * fTemp10) + ((fRec56[0] + fRec56[2]) / fTemp8))))));
			double fTemp58 = (0.035286754500000003 * fTemp57);
			fRec57[0] = (double(input33[i]) - (((fRec57[2] * fTemp5) + (2.0 * (fRec57[1] * fTemp7))) / fTemp8));
			double fTemp59 = ((((fRec57[2] + (fRec57[0] + (2.0 * fRec57[1]))) * fTemp6) / fTemp9) + (0.36362861800000001 * (fRec21[0] * (0.0 - ((fRec57[1] * fTemp10) + ((fRec57[0] + fRec57[2]) / fTemp8))))));
			double fTemp60 = (0.0421689986 * fTemp59);
			fRec58[0] = (double(input34[i]) - (((fRec58[2] * fTemp5) + (2.0 * (fRec58[1] * fTemp7))) / fTemp8));
			double fTemp61 = ((((fRec58[2] + (fRec58[0] + (2.0 * fRec58[1]))) * fTemp6) / fTemp9) + (0.36362861800000001 * (fRec21[0] * (0.0 - ((fRec58[1] * fTemp10) + ((fRec58[0] + fRec58[2]) / fTemp8))))));
			double fTemp62 = (0.099680502500000004 * fTemp61);
			fRec59[0] = (double(input35[i]) - (((fRec59[2] * fTemp5) + (2.0 * (fRec59[1] * fTemp7))) / fTemp8));
			double fTemp63 = ((((fRec59[2] + (fRec59[0] + (2.0 * fRec59[1]))) * fTemp6) / fTemp9) + (0.36362861800000001 * (fRec21[0] * (0.0 - ((fRec59[1] * fTemp10) + ((fRec59[0] + fRec59[2]) / fTemp8))))));
			double fTemp64 = (0.098174667600000001 * fTemp63);
			double fTemp65 = (fConst20 * (((((fTemp44 + fTemp46) + fTemp48) + fTemp50) + fTemp52) - (((((fTemp54 + fTemp56) + fTemp58) + fTemp60) + fTemp62) + fTemp64)));
			double fTemp66 = (fConst21 * fRec43[1]);
			double fTemp67 = (fConst22 * fRec46[1]);
			fRec48[0] = (fTemp65 + (fTemp66 + (fRec48[1] + fTemp67)));
			fRec46[0] = fRec48[0];
			double fRec47 = ((fTemp67 + fTemp66) + fTemp65);
			fRec45[0] = (fRec46[0] + fRec45[1]);
			fRec43[0] = fRec45[0];
			double fRec44 = fRec47;
			fRec42[0] = (fTemp41 + (fTemp42 + (fRec44 + fRec42[1])));
			fRec40[0] = fRec42[0];
			double fRec41 = (fTemp41 + (fRec44 + fTemp42));
			fRec39[0] = (fRec40[0] + fRec39[1]);
			fRec37[0] = fRec39[0];
			double fRec38 = fRec41;
			fRec36[0] = (fTemp40 + (fRec38 + fRec36[1]));
			fRec34[0] = fRec36[0];
			double fRec35 = (fRec38 + fTemp40);
			fRec72[0] = (double(input16[i]) - (((fTemp5 * fRec72[2]) + (2.0 * (fTemp7 * fRec72[1]))) / fTemp8));
			double fTemp68 = (((fTemp6 * (fRec72[2] + (fRec72[0] + (2.0 * fRec72[1])))) / fTemp9) + (0.54707688669999999 * (fRec21[0] * (0.0 - ((fTemp10 * fRec72[1]) + ((fRec72[0] + fRec72[2]) / fTemp8))))));
			double fTemp69 = (0.084414824799999996 * fTemp68);
			fRec73[0] = (double(input17[i]) - (((fTemp5 * fRec73[2]) + (2.0 * (fTemp7 * fRec73[1]))) / fTemp8));
			double fTemp70 = (((fTemp6 * (fRec73[2] + (fRec73[0] + (2.0 * fRec73[1])))) / fTemp9) + (0.54707688669999999 * (fRec21[0] * (0.0 - ((fTemp10 * fRec73[1]) + ((fRec73[0] + fRec73[2]) / fTemp8))))));
			double fTemp71 = (0.061084264300000003 * fTemp70);
			fRec74[0] = (double(input20[i]) - (((fTemp5 * fRec74[2]) + (2.0 * (fTemp7 * fRec74[1]))) / fTemp8));
			double fTemp72 = (((fTemp6 * (fRec74[2] + (fRec74[0] + (2.0 * fRec74[1])))) / fTemp9) + (0.54707688669999999 * (fRec21[0] * (0.0 - ((fTemp10 * fRec74[1]) + ((fRec74[0] + fRec74[2]) / fTemp8))))));
			double fTemp73 = (0.0257268345 * fTemp72);
			fRec75[0] = (double(input23[i]) - (((fRec75[2] * fTemp5) + (2.0 * (fRec75[1] * fTemp7))) / fTemp8));
			double fTemp74 = ((((fRec75[2] + (fRec75[0] + (2.0 * fRec75[1]))) * fTemp6) / fTemp9) + (0.54707688669999999 * (fRec21[0] * (0.0 - ((fRec75[1] * fTemp10) + ((fRec75[0] + fRec75[2]) / fTemp8))))));
			double fTemp75 = (0.0322351123 * fTemp74);
			fRec76[0] = (double(input24[i]) - (((fRec76[2] * fTemp5) + (2.0 * (fRec76[1] * fTemp7))) / fTemp8));
			double fTemp76 = ((((fRec76[2] + (fRec76[0] + (2.0 * fRec76[1]))) * fTemp6) / fTemp9) + (0.54707688669999999 * (fRec21[0] * (0.0 - ((fRec76[1] * fTemp10) + ((fRec76[0] + fRec76[2]) / fTemp8))))));
			double fTemp77 = (0.064445931499999998 * fTemp76);
			fRec77[0] = (double(input18[i]) - (((fTemp5 * fRec77[2]) + (2.0 * (fTemp7 * fRec77[1]))) / fTemp8));
			double fTemp78 = (((fTemp6 * (fRec77[2] + (fRec77[0] + (2.0 * fRec77[1])))) / fTemp9) + (0.54707688669999999 * (fRec21[0] * (0.0 - ((fTemp10 * fRec77[1]) + ((fRec77[0] + fRec77[2]) / fTemp8))))));
			double fTemp79 = (0.0250683669 * fTemp78);
			fRec78[0] = (double(input19[i]) - (((fTemp5 * fRec78[2]) + (2.0 * (fTemp7 * fRec78[1]))) / fTemp8));
			double fTemp80 = (((fTemp6 * (fRec78[2] + (fRec78[0] + (2.0 * fRec78[1])))) / fTemp9) + (0.54707688669999999 * (fRec21[0] * (0.0 - ((fTemp10 * fRec78[1]) + ((fRec78[0] + fRec78[2]) / fTemp8))))));
			double fTemp81 = (0.022189459299999999 * fTemp80);
			fRec79[0] = (double(input21[i]) - (((fTemp5 * fRec79[2]) + (2.0 * (fTemp7 * fRec79[1]))) / fTemp8));
			double fTemp82 = (((fTemp6 * (fRec79[2] + (fRec79[0] + (2.0 * fRec79[1])))) / fTemp9) + (0.54707688669999999 * (fRec21[0] * (0.0 - ((fTemp10 * fRec79[1]) + ((fRec79[0] + fRec79[2]) / fTemp8))))));
			double fTemp83 = (0.052111776300000003 * fTemp82);
			fRec80[0] = (double(input22[i]) - (((fTemp5 * fRec80[2]) + (2.0 * (fTemp7 * fRec80[1]))) / fTemp8));
			double fTemp84 = (((fTemp6 * (fRec80[2] + (fRec80[0] + (2.0 * fRec80[1])))) / fTemp9) + (0.54707688669999999 * (fRec21[0] * (0.0 - ((fTemp10 * fRec80[1]) + ((fRec80[0] + fRec80[2]) / fTemp8))))));
			double fTemp85 = (0.030851885700000001 * fTemp84);
			double fTemp86 = (fConst25 * (((fTemp69 + fTemp71) + fTemp73) - (((((fTemp75 + fTemp77) + fTemp79) + fTemp81) + fTemp83) + fTemp85)));
			double fTemp87 = (fConst26 * fRec69[1]);
			double fTemp88 = (fConst27 * fRec66[1]);
			fRec71[0] = (((fTemp86 + fRec71[1]) + fTemp87) + fTemp88);
			fRec69[0] = fRec71[0];
			double fRec70 = ((fTemp86 + fTemp87) + fTemp88);
			fRec68[0] = (fRec69[0] + fRec68[1]);
			fRec66[0] = fRec68[0];
			double fRec67 = fRec70;
			double fTemp89 = (fConst28 * fRec63[1]);
			double fTemp90 = (fConst29 * fRec60[1]);
			fRec65[0] = (((fRec67 + fRec65[1]) + fTemp89) + fTemp90);
			fRec63[0] = fRec65[0];
			double fRec64 = ((fRec67 + fTemp89) + fTemp90);
			fRec62[0] = (fRec63[0] + fRec62[1]);
			fRec60[0] = fRec62[0];
			double fRec61 = fRec64;
			double fTemp91 = (fConst31 * fRec81[1]);
			fRec90[0] = (double(input9[i]) - (((fTemp5 * fRec90[2]) + (2.0 * (fTemp7 * fRec90[1]))) / fTemp8));
			double fTemp92 = (((fTemp6 * (fRec90[2] + (fRec90[0] + (2.0 * fRec90[1])))) / fTemp9) + (0.71374298160000005 * (fRec21[0] * (0.0 - ((fTemp10 * fRec90[1]) + ((fRec90[0] + fRec90[2]) / fTemp8))))));
			double fTemp93 = (0.064879342600000001 * fTemp92);
			fRec91[0] = (double(input10[i]) - (((fTemp5 * fRec91[2]) + (2.0 * (fTemp7 * fRec91[1]))) / fTemp8));
			double fTemp94 = (((fTemp6 * (fRec91[2] + (fRec91[0] + (2.0 * fRec91[1])))) / fTemp9) + (0.71374298160000005 * (fRec21[0] * (0.0 - ((fTemp10 * fRec91[1]) + ((fRec91[0] + fRec91[2]) / fTemp8))))));
			double fTemp95 = (0.036213091599999997 * fTemp94);
			fRec92[0] = (double(input14[i]) - (((fTemp5 * fRec92[2]) + (2.0 * (fTemp7 * fRec92[1]))) / fTemp8));
			double fTemp96 = (((fTemp6 * (fRec92[2] + (fRec92[0] + (2.0 * fRec92[1])))) / fTemp9) + (0.71374298160000005 * (fRec21[0] * (0.0 - ((fTemp10 * fRec92[1]) + ((fRec92[0] + fRec92[2]) / fTemp8))))));
			double fTemp97 = (0.0074393491999999997 * fTemp96);
			fRec93[0] = (double(input11[i]) - (((fTemp5 * fRec93[2]) + (2.0 * (fTemp7 * fRec93[1]))) / fTemp8));
			double fTemp98 = (((fTemp6 * (fRec93[2] + (fRec93[0] + (2.0 * fRec93[1])))) / fTemp9) + (0.71374298160000005 * (fRec21[0] * (0.0 - ((fTemp10 * fRec93[1]) + ((fRec93[0] + fRec93[2]) / fTemp8))))));
			double fTemp99 = (0.0162554377 * fTemp98);
			fRec94[0] = (double(input12[i]) - (((fTemp5 * fRec94[2]) + (2.0 * (fTemp7 * fRec94[1]))) / fTemp8));
			double fTemp100 = (((fTemp6 * (fRec94[2] + (fRec94[0] + (2.0 * fRec94[1])))) / fTemp9) + (0.71374298160000005 * (fRec21[0] * (0.0 - ((fTemp10 * fRec94[1]) + ((fRec94[0] + fRec94[2]) / fTemp8))))));
			double fTemp101 = (0.030526009999999999 * fTemp100);
			fRec95[0] = (double(input13[i]) - (((fTemp5 * fRec95[2]) + (2.0 * (fTemp7 * fRec95[1]))) / fTemp8));
			double fTemp102 = (((fTemp6 * (fRec95[2] + (fRec95[0] + (2.0 * fRec95[1])))) / fTemp9) + (0.71374298160000005 * (fRec21[0] * (0.0 - ((fTemp10 * fRec95[1]) + ((fRec95[0] + fRec95[2]) / fTemp8))))));
			double fTemp103 = (0.040498825600000003 * fTemp102);
			fRec96[0] = (double(input15[i]) - (((fTemp5 * fRec96[2]) + (2.0 * (fTemp7 * fRec96[1]))) / fTemp8));
			double fTemp104 = (((fTemp6 * (fRec96[2] + (fRec96[0] + (2.0 * fRec96[1])))) / fTemp9) + (0.71374298160000005 * (fRec21[0] * (0.0 - ((fTemp10 * fRec96[1]) + ((fRec96[0] + fRec96[2]) / fTemp8))))));
			double fTemp105 = (0.0168709784 * fTemp104);
			double fTemp106 = (fConst33 * (((fTemp93 + fTemp95) + fTemp97) - (((fTemp99 + fTemp101) + fTemp103) + fTemp105)));
			double fTemp107 = (fConst34 * fRec84[1]);
			double fTemp108 = (fConst35 * fRec87[1]);
			fRec89[0] = (fTemp106 + (fTemp107 + (fRec89[1] + fTemp108)));
			fRec87[0] = fRec89[0];
			double fRec88 = ((fTemp108 + fTemp107) + fTemp106);
			fRec86[0] = (fRec87[0] + fRec86[1]);
			fRec84[0] = fRec86[0];
			double fRec85 = fRec88;
			fRec83[0] = (fTemp91 + (fRec85 + fRec83[1]));
			fRec81[0] = fRec83[0];
			double fRec82 = (fRec85 + fTemp91);
			fRec100[0] = (double(input1[i]) - (((fTemp5 * fRec100[2]) + (2.0 * (fTemp7 * fRec100[1]))) / fTemp8));
			double fTemp109 = (((fTemp6 * (fRec100[2] + ((2.0 * fRec100[1]) + fRec100[0]))) / fTemp9) + (0.94910791230000002 * (fRec21[0] * (0.0 - ((fTemp10 * fRec100[1]) + ((fRec100[2] + fRec100[0]) / fTemp8))))));
			double fTemp110 = (0.017340396500000001 * fTemp109);
			fRec101[0] = (double(input3[i]) - (((fTemp5 * fRec101[2]) + (2.0 * (fTemp7 * fRec101[1]))) / fTemp8));
			double fTemp111 = (((fTemp6 * (fRec101[2] + (fRec101[0] + (2.0 * fRec101[1])))) / fTemp9) + (0.94910791230000002 * (fRec21[0] * (0.0 - ((fTemp10 * fRec101[1]) + ((fRec101[0] + fRec101[2]) / fTemp8))))));
			double fTemp112 = (0.0273310077 * fTemp111);
			fRec102[0] = (double(input2[i]) - (((fTemp5 * fRec102[2]) + (2.0 * (fTemp7 * fRec102[1]))) / fTemp8));
			double fTemp113 = (((fTemp6 * (fRec102[2] + ((2.0 * fRec102[1]) + fRec102[0]))) / fTemp9) + (0.94910791230000002 * (fRec21[0] * (0.0 - ((fTemp10 * fRec102[1]) + ((fRec102[2] + fRec102[0]) / fTemp8))))));
			double fTemp114 = (0.0041006515999999996 * fTemp113);
			double fTemp115 = (fConst37 * ((fTemp110 + fTemp112) - fTemp114));
			double fTemp116 = (fConst38 * fRec97[1]);
			fRec99[0] = (fTemp115 + (fRec99[1] + fTemp116));
			fRec97[0] = fRec99[0];
			double fRec98 = (fTemp116 + fTemp115);
			fRec109[0] = (double(input4[i]) - (((fTemp5 * fRec109[2]) + (2.0 * (fTemp7 * fRec109[1]))) / fTemp8));
			double fTemp117 = (((fTemp6 * (fRec109[2] + (fRec109[0] + (2.0 * fRec109[1])))) / fTemp9) + (0.85120874390000001 * (fRec21[0] * (0.0 - ((fTemp10 * fRec109[1]) + ((fRec109[0] + fRec109[2]) / fTemp8))))));
			double fTemp118 = (0.054897582 * fTemp117);
			fRec110[0] = (double(input5[i]) - (((fTemp5 * fRec110[2]) + (2.0 * (fTemp7 * fRec110[1]))) / fTemp8));
			double fTemp119 = (((fTemp6 * (fRec110[2] + (fRec110[0] + (2.0 * fRec110[1])))) / fTemp9) + (0.85120874390000001 * (fRec21[0] * (0.0 - ((fTemp10 * fRec110[1]) + ((fRec110[0] + fRec110[2]) / fTemp8))))));
			double fTemp120 = (0.013089181700000001 * fTemp119);
			fRec111[0] = (double(input7[i]) - (((fTemp5 * fRec111[2]) + (2.0 * (fTemp7 * fRec111[1]))) / fTemp8));
			double fTemp121 = (((fTemp6 * (fRec111[2] + (fRec111[0] + (2.0 * fRec111[1])))) / fTemp9) + (0.85120874390000001 * (fRec21[0] * (0.0 - ((fTemp10 * fRec111[1]) + ((fRec111[0] + fRec111[2]) / fTemp8))))));
			double fTemp122 = (0.0149107267 * fTemp121);
			fRec112[0] = (double(input8[i]) - (((fTemp5 * fRec112[2]) + (2.0 * (fTemp7 * fRec112[1]))) / fTemp8));
			double fTemp123 = (((fTemp6 * (fRec112[2] + (fRec112[0] + (2.0 * fRec112[1])))) / fTemp9) + (0.85120874390000001 * (fRec21[0] * (0.0 - ((fTemp10 * fRec112[1]) + ((fRec112[0] + fRec112[2]) / fTemp8))))));
			double fTemp124 = (0.0255152113 * fTemp123);
			fRec113[0] = (double(input6[i]) - (((fTemp5 * fRec113[2]) + (2.0 * (fTemp7 * fRec113[1]))) / fTemp8));
			double fTemp125 = (((fTemp6 * (fRec113[2] + (fRec113[0] + (2.0 * fRec113[1])))) / fTemp9) + (0.85120874390000001 * (fRec21[0] * (0.0 - ((fTemp10 * fRec113[1]) + ((fRec113[0] + fRec113[2]) / fTemp8))))));
			double fTemp126 = (0.040376446699999999 * fTemp125);
			double fTemp127 = (fConst40 * ((((fTemp118 + fTemp120) + fTemp122) + fTemp124) - fTemp126));
			double fTemp128 = (fConst41 * fRec103[1]);
			double fTemp129 = (fConst42 * fRec106[1]);
			fRec108[0] = (fTemp127 + (fTemp128 + (fRec108[1] + fTemp129)));
			fRec106[0] = fRec108[0];
			double fRec107 = ((fTemp129 + fTemp128) + fTemp127);
			fRec105[0] = (fRec106[0] + fRec105[1]);
			fRec103[0] = fRec105[0];
			double fRec104 = fRec107;
			fRec114[0] = (double(input0[i]) - (((fRec114[2] * fTemp5) + (2.0 * (fRec114[1] * fTemp7))) / fTemp8));
			double fTemp130 = (((fTemp6 * (fRec114[2] + (fRec114[0] + (2.0 * fRec114[1])))) / fTemp9) + (fRec21[0] * (0.0 - ((fRec114[1] * fTemp10) + ((fRec114[0] + fRec114[2]) / fTemp8)))));
			double fTemp131 = (0.0085387454000000005 * fTemp130);
			fVec0[(IOTA & 127)] = ((fRec2 + (fRec35 + (fRec61 + (fRec82 + (fRec98 + fRec104))))) + fTemp131);
			output0[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec0[((IOTA - iConst43) & 127)])));
			double fTemp132 = (0.010435007600000001 * fTemp130);
			double fTemp133 = (fConst45 * fRec115[1]);
			double fTemp134 = (fConst46 * fRec118[1]);
			double fTemp135 = (fConst48 * fRec121[1]);
			double fTemp136 = (fConst49 * fRec124[1]);
			double fTemp137 = (0.069157735299999995 * fTemp35);
			double fTemp138 = (0.063422363199999998 * fTemp33);
			double fTemp139 = (0.0816658257 * fTemp19);
			double fTemp140 = (0.025850933100000001 * fTemp17);
			double fTemp141 = (0.020947159 * fTemp15);
			double fTemp142 = (0.067209171299999995 * fTemp21);
			double fTemp143 = (0.048803048199999997 * fTemp11);
			double fTemp144 = (0.024082307000000001 * fTemp25);
			double fTemp145 = (0.025695724100000001 * fTemp31);
			double fTemp146 = (0.1116506973 * fTemp29);
			double fTemp147 = (0.0354612433 * fTemp13);
			double fTemp148 = (0.083365635399999999 * fTemp23);
			double fTemp149 = (0.056327862300000003 * fTemp27);
			double fTemp150 = (fConst51 * ((fTemp137 + (fTemp138 + ((fTemp139 + (fTemp140 + (fTemp141 + ((fTemp142 + fTemp143) + fTemp144)))) + fTemp145))) - (fTemp146 + ((fTemp147 + fTemp148) + fTemp149))));
			double fTemp151 = (fConst52 * fRec127[1]);
			double fTemp152 = (fConst53 * fRec130[1]);
			fRec132[0] = (fTemp150 + (fTemp151 + (fRec132[1] + fTemp152)));
			fRec130[0] = fRec132[0];
			double fRec131 = ((fTemp152 + fTemp151) + fTemp150);
			fRec129[0] = (fRec130[0] + fRec129[1]);
			fRec127[0] = fRec129[0];
			double fRec128 = fRec131;
			fRec126[0] = (fTemp135 + (fTemp136 + (fRec128 + fRec126[1])));
			fRec124[0] = fRec126[0];
			double fRec125 = (fTemp135 + (fRec128 + fTemp136));
			fRec123[0] = (fRec124[0] + fRec123[1]);
			fRec121[0] = fRec123[0];
			double fRec122 = fRec125;
			fRec120[0] = (fTemp133 + (fTemp134 + (fRec122 + fRec120[1])));
			fRec118[0] = fRec120[0];
			double fRec119 = (fTemp133 + (fRec122 + fTemp134));
			fRec117[0] = (fRec118[0] + fRec117[1]);
			fRec115[0] = fRec117[0];
			double fRec116 = fRec119;
			double fTemp153 = (fConst55 * fRec133[1]);
			double fTemp154 = (fConst57 * fRec136[1]);
			double fTemp155 = (fConst58 * fRec139[1]);
			double fTemp156 = (0.090596771899999998 * fTemp63);
			double fTemp157 = (0.021370773499999999 * fTemp51);
			double fTemp158 = (0.050820653399999999 * fTemp49);
			double fTemp159 = (0.068486062599999994 * fTemp43);
			double fTemp160 = (0.017480886800000001 * fTemp55);
			double fTemp161 = (0.0178723371 * fTemp47);
			double fTemp162 = (0.078259427399999998 * fTemp61);
			double fTemp163 = (0.055773845699999998 * fTemp59);
			double fTemp164 = (0.0061947831999999998 * fTemp45);
			double fTemp165 = (0.0680715655 * fTemp53);
			double fTemp166 = (0.10746105960000001 * fTemp57);
			double fTemp167 = (fConst60 * ((fTemp156 + ((fTemp157 + (fTemp158 + ((fTemp159 + fTemp160) + fTemp161))) + fTemp162)) - (fTemp163 + ((fTemp164 + fTemp165) + fTemp166))));
			double fTemp168 = (fConst61 * fRec142[1]);
			double fTemp169 = (fConst62 * fRec145[1]);
			fRec147[0] = (fTemp167 + (fTemp168 + (fRec147[1] + fTemp169)));
			fRec145[0] = fRec147[0];
			double fRec146 = ((fTemp169 + fTemp168) + fTemp167);
			fRec144[0] = (fRec145[0] + fRec144[1]);
			fRec142[0] = fRec144[0];
			double fRec143 = fRec146;
			fRec141[0] = (fTemp154 + (fTemp155 + (fRec143 + fRec141[1])));
			fRec139[0] = fRec141[0];
			double fRec140 = (fTemp154 + (fRec143 + fTemp155));
			fRec138[0] = (fRec139[0] + fRec138[1]);
			fRec136[0] = fRec138[0];
			double fRec137 = fRec140;
			fRec135[0] = (fTemp153 + (fRec137 + fRec135[1]));
			fRec133[0] = fRec135[0];
			double fRec134 = (fRec137 + fTemp153);
			double fTemp170 = (fConst64 * fRec148[1]);
			double fTemp171 = (fConst65 * fRec151[1]);
			double fTemp172 = (0.027191850699999999 * fTemp72);
			double fTemp173 = (0.0087492128999999991 * fTemp80);
			double fTemp174 = (0.0031526543000000001 * fTemp78);
			double fTemp175 = (0.032522042199999997 * fTemp68);
			double fTemp176 = (0.034539284900000002 * fTemp74);
			double fTemp177 = (0.082929560099999994 * fTemp76);
			double fTemp178 = (0.078314329899999993 * fTemp84);
			double fTemp179 = (0.0208388706 * fTemp70);
			double fTemp180 = (0.058035407800000001 * fTemp82);
			double fTemp181 = (fConst67 * ((fTemp172 + (fTemp173 + (fTemp174 + (fTemp175 + (fTemp176 + fTemp177))))) - (fTemp178 + (fTemp179 + fTemp180))));
			double fTemp182 = (fConst68 * fRec154[1]);
			double fTemp183 = (fConst69 * fRec157[1]);
			fRec159[0] = (fTemp181 + (fTemp182 + (fRec159[1] + fTemp183)));
			fRec157[0] = fRec159[0];
			double fRec158 = ((fTemp183 + fTemp182) + fTemp181);
			fRec156[0] = (fRec157[0] + fRec156[1]);
			fRec154[0] = fRec156[0];
			double fRec155 = fRec158;
			fRec153[0] = (fTemp170 + (fTemp171 + (fRec155 + fRec153[1])));
			fRec151[0] = fRec153[0];
			double fRec152 = (fTemp170 + (fRec155 + fTemp171));
			fRec150[0] = (fRec151[0] + fRec150[1]);
			fRec148[0] = fRec150[0];
			double fRec149 = fRec152;
			double fTemp184 = (fConst71 * fRec160[1]);
			double fTemp185 = (0.046898843900000001 * fTemp104);
			double fTemp186 = (0.00081938530000000005 * fTemp92);
			double fTemp187 = (0.011279806700000001 * fTemp94);
			double fTemp188 = (0.0085236648000000005 * fTemp98);
			double fTemp189 = (0.0061467477 * fTemp96);
			double fTemp190 = (0.025974657500000001 * fTemp100);
			double fTemp191 = (0.044600507400000003 * fTemp102);
			double fTemp192 = (fConst73 * ((fTemp185 + (((fTemp186 + fTemp187) + fTemp188) + fTemp189)) - (fTemp190 + fTemp191)));
			double fTemp193 = (fConst74 * fRec163[1]);
			double fTemp194 = (fConst75 * fRec166[1]);
			fRec168[0] = (fTemp192 + (fTemp193 + (fRec168[1] + fTemp194)));
			fRec166[0] = fRec168[0];
			double fRec167 = ((fTemp194 + fTemp193) + fTemp192);
			fRec165[0] = (fRec166[0] + fRec165[1]);
			fRec163[0] = fRec165[0];
			double fRec164 = fRec167;
			fRec162[0] = (fTemp184 + (fRec164 + fRec162[1]));
			fRec160[0] = fRec162[0];
			double fRec161 = (fRec164 + fTemp184);
			double fTemp195 = (0.0076788888999999999 * fTemp109);
			double fTemp196 = (0.00020641680000000001 * fTemp113);
			double fTemp197 = (0.031343059999999999 * fTemp111);
			double fTemp198 = (fConst77 * ((fTemp195 + fTemp196) + fTemp197));
			double fTemp199 = (fConst78 * fRec169[1]);
			fRec171[0] = (fTemp198 + (fRec171[1] + fTemp199));
			fRec169[0] = fRec171[0];
			double fRec170 = (fTemp199 + fTemp198);
			double fTemp200 = (0.0187973242 * fTemp117);
			double fTemp201 = (0.0116788602 * fTemp119);
			double fTemp202 = (0.018087756999999999 * fTemp121);
			double fTemp203 = (0.041002282899999999 * fTemp123);
			double fTemp204 = (0.035415386200000003 * fTemp125);
			double fTemp205 = (fConst80 * ((((fTemp200 + fTemp201) + fTemp202) + fTemp203) - fTemp204));
			double fTemp206 = (fConst81 * fRec172[1]);
			double fTemp207 = (fConst82 * fRec175[1]);
			fRec177[0] = (fTemp205 + (fTemp206 + (fRec177[1] + fTemp207)));
			fRec175[0] = fRec177[0];
			double fRec176 = ((fTemp207 + fTemp206) + fTemp205);
			fRec174[0] = (fRec175[0] + fRec174[1]);
			fRec172[0] = fRec174[0];
			double fRec173 = fRec176;
			fVec1[(IOTA & 127)] = (fTemp132 + (fRec116 + (fRec134 + (fRec149 + (fRec161 + (fRec170 + fRec173))))));
			output1[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec1[((IOTA - iConst83) & 127)])));
			double fTemp208 = (0.011032917099999999 * fTemp130);
			double fTemp209 = (0.0097275085000000008 * fTemp121);
			double fTemp210 = (0.036235222400000003 * fTemp123);
			double fTemp211 = (0.0170286732 * fTemp117);
			double fTemp212 = (0.0066697817999999999 * fTemp119);
			double fTemp213 = (0.033959186600000003 * fTemp125);
			double fTemp214 = (fConst80 * ((fTemp209 + fTemp210) - ((fTemp211 + fTemp212) + fTemp213)));
			double fTemp215 = (fConst81 * fRec178[1]);
			double fTemp216 = (fConst82 * fRec181[1]);
			fRec183[0] = (fTemp214 + (fTemp215 + (fRec183[1] + fTemp216)));
			fRec181[0] = fRec183[0];
			double fRec182 = ((fTemp216 + fTemp215) + fTemp214);
			fRec180[0] = (fRec181[0] + fRec180[1]);
			fRec178[0] = fRec180[0];
			double fRec179 = fRec182;
			double fTemp217 = (0.0015495560999999999 * fTemp113);
			double fTemp218 = (0.0275897882 * fTemp111);
			double fTemp219 = (0.0088826606999999995 * fTemp109);
			double fTemp220 = (fConst77 * ((fTemp217 + fTemp218) - fTemp219));
			double fTemp221 = (fConst78 * fRec184[1]);
			fRec186[0] = (fTemp220 + (fRec186[1] + fTemp221));
			fRec184[0] = fRec186[0];
			double fRec185 = (fTemp221 + fTemp220);
			double fTemp222 = (fConst71 * fRec187[1]);
			double fTemp223 = (0.058080233100000003 * fTemp104);
			double fTemp224 = (0.0065416025000000003 * fTemp94);
			double fTemp225 = (0.0086732855000000008 * fTemp98);
			double fTemp226 = (0.0059675500000000003 * fTemp96);
			double fTemp227 = (0.055677016000000003 * fTemp102);
			double fTemp228 = (0.0341673963 * fTemp92);
			double fTemp229 = (0.024702450000000001 * fTemp100);
			double fTemp230 = (fConst73 * ((fTemp223 + ((fTemp224 + fTemp225) + fTemp226)) - (fTemp227 + (fTemp228 + fTemp229))));
			double fTemp231 = (fConst74 * fRec190[1]);
			double fTemp232 = (fConst75 * fRec193[1]);
			fRec195[0] = (fTemp230 + (fTemp231 + (fRec195[1] + fTemp232)));
			fRec193[0] = fRec195[0];
			double fRec194 = ((fTemp232 + fTemp231) + fTemp230);
			fRec192[0] = (fRec193[0] + fRec192[1]);
			fRec190[0] = fRec192[0];
			double fRec191 = fRec194;
			fRec189[0] = (fTemp222 + (fRec191 + fRec189[1]));
			fRec187[0] = fRec189[0];
			double fRec188 = (fRec191 + fTemp222);
			double fTemp233 = (fConst45 * fRec196[1]);
			double fTemp234 = (fConst46 * fRec199[1]);
			double fTemp235 = (fConst48 * fRec202[1]);
			double fTemp236 = (fConst49 * fRec205[1]);
			double fTemp237 = (0.020568156600000002 * fTemp33);
			double fTemp238 = (0.071417636000000007 * fTemp19);
			double fTemp239 = (0.090670927100000007 * fTemp23);
			double fTemp240 = (0.038697583299999998 * fTemp25);
			double fTemp241 = (0.024533615599999999 * fTemp17);
			double fTemp242 = (0.063949998199999997 * fTemp31);
			double fTemp243 = (0.040755332200000001 * fTemp29);
			double fTemp244 = (0.1012853828 * fTemp21);
			double fTemp245 = (0.078016207700000006 * fTemp11);
			double fTemp246 = (0.024876967699999999 * fTemp13);
			double fTemp247 = (0.024179950400000001 * fTemp15);
			double fTemp248 = (0.070990399300000007 * fTemp27);
			double fTemp249 = (0.00033730050000000002 * fTemp35);
			double fTemp250 = (fConst51 * ((fTemp237 + ((fTemp238 + ((fTemp239 + fTemp240) + fTemp241)) + fTemp242)) - ((fTemp243 + ((((fTemp244 + fTemp245) + fTemp246) + fTemp247) + fTemp248)) + fTemp249)));
			double fTemp251 = (fConst52 * fRec208[1]);
			double fTemp252 = (fConst53 * fRec211[1]);
			fRec213[0] = (fTemp250 + (fTemp251 + (fRec213[1] + fTemp252)));
			fRec211[0] = fRec213[0];
			double fRec212 = ((fTemp252 + fTemp251) + fTemp250);
			fRec210[0] = (fRec211[0] + fRec210[1]);
			fRec208[0] = fRec210[0];
			double fRec209 = fRec212;
			fRec207[0] = (fTemp235 + (fTemp236 + (fRec209 + fRec207[1])));
			fRec205[0] = fRec207[0];
			double fRec206 = (fTemp235 + (fRec209 + fTemp236));
			fRec204[0] = (fRec205[0] + fRec204[1]);
			fRec202[0] = fRec204[0];
			double fRec203 = fRec206;
			fRec201[0] = (fTemp233 + (fTemp234 + (fRec203 + fRec201[1])));
			fRec199[0] = fRec201[0];
			double fRec200 = (fTemp233 + (fRec203 + fTemp234));
			fRec198[0] = (fRec199[0] + fRec198[1]);
			fRec196[0] = fRec198[0];
			double fRec197 = fRec200;
			double fTemp253 = (fConst64 * fRec214[1]);
			double fTemp254 = (fConst65 * fRec217[1]);
			double fTemp255 = (0.027672627799999999 * fTemp72);
			double fTemp256 = (0.011931962399999999 * fTemp80);
			double fTemp257 = (0.055324190799999999 * fTemp78);
			double fTemp258 = (0.066471682599999998 * fTemp74);
			double fTemp259 = (0.063639154899999995 * fTemp76);
			double fTemp260 = (0.078597114300000007 * fTemp84);
			double fTemp261 = (0.084102146399999994 * fTemp68);
			double fTemp262 = (0.0206847444 * fTemp70);
			double fTemp263 = (0.070262175600000004 * fTemp82);
			double fTemp264 = (fConst67 * ((fTemp255 + (fTemp256 + (fTemp257 + (fTemp258 + fTemp259)))) - (fTemp260 + ((fTemp261 + fTemp262) + fTemp263))));
			double fTemp265 = (fConst68 * fRec220[1]);
			double fTemp266 = (fConst69 * fRec223[1]);
			fRec225[0] = (fTemp264 + (fTemp265 + (fRec225[1] + fTemp266)));
			fRec223[0] = fRec225[0];
			double fRec224 = ((fTemp266 + fTemp265) + fTemp264);
			fRec222[0] = (fRec223[0] + fRec222[1]);
			fRec220[0] = fRec222[0];
			double fRec221 = fRec224;
			fRec219[0] = (fTemp253 + (fTemp254 + (fRec221 + fRec219[1])));
			fRec217[0] = fRec219[0];
			double fRec218 = (fTemp253 + (fRec221 + fTemp254));
			fRec216[0] = (fRec217[0] + fRec216[1]);
			fRec214[0] = fRec216[0];
			double fRec215 = fRec218;
			double fTemp267 = (fConst55 * fRec226[1]);
			double fTemp268 = (fConst57 * fRec229[1]);
			double fTemp269 = (fConst58 * fRec232[1]);
			double fTemp270 = (0.0287108511 * fTemp63);
			double fTemp271 = (0.095746234400000005 * fTemp61);
			double fTemp272 = (0.0084126763999999993 * fTemp51);
			double fTemp273 = (0.050512797999999998 * fTemp53);
			double fTemp274 = (0.0711078817 * fTemp55);
			double fTemp275 = (0.049974702699999998 * fTemp49);
			double fTemp276 = (0.0091060373999999993 * fTemp59);
			double fTemp277 = (0.10989283649999999 * fTemp43);
			double fTemp278 = (0.078380701699999999 * fTemp45);
			double fTemp279 = (0.0087722001000000004 * fTemp47);
			double fTemp280 = (0.11902944059999999 * fTemp57);
			double fTemp281 = (fConst60 * ((fTemp270 + (fTemp271 + ((fTemp272 + ((fTemp273 + fTemp274) + fTemp275)) + fTemp276))) - (((fTemp277 + fTemp278) + fTemp279) + fTemp280)));
			double fTemp282 = (fConst61 * fRec235[1]);
			double fTemp283 = (fConst62 * fRec238[1]);
			fRec240[0] = (fTemp281 + (fTemp282 + (fRec240[1] + fTemp283)));
			fRec238[0] = fRec240[0];
			double fRec239 = ((fTemp283 + fTemp282) + fTemp281);
			fRec237[0] = (fRec238[0] + fRec237[1]);
			fRec235[0] = fRec237[0];
			double fRec236 = fRec239;
			fRec234[0] = (fTemp268 + (fTemp269 + (fRec236 + fRec234[1])));
			fRec232[0] = fRec234[0];
			double fRec233 = (fTemp268 + (fRec236 + fTemp269));
			fRec231[0] = (fRec232[0] + fRec231[1]);
			fRec229[0] = fRec231[0];
			double fRec230 = fRec233;
			fRec228[0] = (fTemp267 + (fRec230 + fRec228[1]));
			fRec226[0] = fRec228[0];
			double fRec227 = (fRec230 + fTemp267);
			fVec2[(IOTA & 127)] = (fTemp208 + (fRec179 + (fRec185 + (fRec188 + (fRec197 + (fRec215 + fRec227))))));
			output2[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec2[((IOTA - iConst83) & 127)])));
			double fTemp284 = (0.0091359028999999994 * fTemp130);
			double fTemp285 = (0.0209882757 * fTemp111);
			double fTemp286 = (0.020633909700000001 * fTemp109);
			double fTemp287 = (0.0027726753000000002 * fTemp113);
			double fTemp288 = (fConst85 * (fTemp285 - (fTemp286 + fTemp287)));
			double fTemp289 = (fConst86 * fRec241[1]);
			fRec243[0] = (fTemp288 + (fRec243[1] + fTemp289));
			fRec241[0] = fRec243[0];
			double fRec242 = (fTemp289 + fTemp288);
			double fTemp290 = (fConst88 * fRec244[1]);
			double fTemp291 = (fConst89 * fRec247[1]);
			double fTemp292 = (fConst91 * fRec250[1]);
			double fTemp293 = (fConst92 * fRec253[1]);
			double fTemp294 = (0.052402788700000001 * fTemp19);
			double fTemp295 = (0.076053106499999995 * fTemp21);
			double fTemp296 = (0.0096399316999999998 * fTemp11);
			double fTemp297 = (0.039047955600000003 * fTemp13);
			double fTemp298 = (0.1378065684 * fTemp23);
			double fTemp299 = (0.045083613500000001 * fTemp25);
			double fTemp300 = (0.028502942699999999 * fTemp17);
			double fTemp301 = (0.020415736 * fTemp29);
			double fTemp302 = (0.0686192001 * fTemp35);
			double fTemp303 = (0.078105643799999999 * fTemp33);
			double fTemp304 = (0.0531762452 * fTemp15);
			double fTemp305 = (0.052320902000000002 * fTemp27);
			double fTemp306 = (0.030094124399999998 * fTemp31);
			double fTemp307 = (fConst94 * (((fTemp294 + (((((fTemp295 + fTemp296) + fTemp297) + fTemp298) + fTemp299) + fTemp300)) + fTemp301) - (fTemp302 + (fTemp303 + ((fTemp304 + fTemp305) + fTemp306)))));
			double fTemp308 = (fConst95 * fRec256[1]);
			double fTemp309 = (fConst96 * fRec259[1]);
			fRec261[0] = (fTemp307 + (fTemp308 + (fRec261[1] + fTemp309)));
			fRec259[0] = fRec261[0];
			double fRec260 = ((fTemp309 + fTemp308) + fTemp307);
			fRec258[0] = (fRec259[0] + fRec258[1]);
			fRec256[0] = fRec258[0];
			double fRec257 = fRec260;
			fRec255[0] = (fTemp292 + (fTemp293 + (fRec257 + fRec255[1])));
			fRec253[0] = fRec255[0];
			double fRec254 = (fTemp292 + (fRec257 + fTemp293));
			fRec252[0] = (fRec253[0] + fRec252[1]);
			fRec250[0] = fRec252[0];
			double fRec251 = fRec254;
			fRec249[0] = (fTemp290 + (fTemp291 + (fRec251 + fRec249[1])));
			fRec247[0] = fRec249[0];
			double fRec248 = (fTemp290 + (fRec251 + fTemp291));
			fRec246[0] = (fRec247[0] + fRec246[1]);
			fRec244[0] = fRec246[0];
			double fRec245 = fRec248;
			double fTemp310 = (fConst98 * fRec262[1]);
			double fTemp311 = (fConst100 * fRec265[1]);
			double fTemp312 = (fConst101 * fRec268[1]);
			double fTemp313 = (0.0164026057 * fTemp43);
			double fTemp314 = (0.0095565535000000004 * fTemp45);
			double fTemp315 = (0.087240938399999995 * fTemp53);
			double fTemp316 = (0.093217621599999995 * fTemp55);
			double fTemp317 = (0.053100987699999998 * fTemp49);
			double fTemp318 = (0.1129992022 * fTemp63);
			double fTemp319 = (0.082726264899999999 * fTemp61);
			double fTemp320 = (0.0083578456000000002 * fTemp59);
			double fTemp321 = (0.082713117399999994 * fTemp57);
			double fTemp322 = (0.017965227899999998 * fTemp47);
			double fTemp323 = (0.0011559691 * fTemp51);
			double fTemp324 = (fConst103 * (((((fTemp313 + fTemp314) + fTemp315) + fTemp316) + fTemp317) - (fTemp318 + (fTemp319 + (fTemp320 + (fTemp321 + (fTemp322 + fTemp323)))))));
			double fTemp325 = (fConst104 * fRec271[1]);
			double fTemp326 = (fConst105 * fRec274[1]);
			fRec276[0] = (fTemp324 + (fTemp325 + (fRec276[1] + fTemp326)));
			fRec274[0] = fRec276[0];
			double fRec275 = ((fTemp326 + fTemp325) + fTemp324);
			fRec273[0] = (fRec274[0] + fRec273[1]);
			fRec271[0] = fRec273[0];
			double fRec272 = fRec275;
			fRec270[0] = (fTemp311 + (fTemp312 + (fRec272 + fRec270[1])));
			fRec268[0] = fRec270[0];
			double fRec269 = (fTemp311 + (fRec272 + fTemp312));
			fRec267[0] = (fRec268[0] + fRec267[1]);
			fRec265[0] = fRec267[0];
			double fRec266 = fRec269;
			fRec264[0] = (fTemp310 + (fRec266 + fRec264[1]));
			fRec262[0] = fRec264[0];
			double fRec263 = (fRec266 + fTemp310);
			double fTemp327 = (fConst107 * fRec277[1]);
			double fTemp328 = (fConst108 * fRec280[1]);
			double fTemp329 = (0.068365561300000002 * fTemp78);
			double fTemp330 = (0.030303552899999999 * fTemp80);
			double fTemp331 = (0.0262361316 * fTemp72);
			double fTemp332 = (0.064804100599999998 * fTemp84);
			double fTemp333 = (0.065912215600000004 * fTemp82);
			double fTemp334 = (0.0099295531000000003 * fTemp70);
			double fTemp335 = (0.031861440599999999 * fTemp68);
			double fTemp336 = (0.0389362527 * fTemp74);
			double fTemp337 = (0.084209372199999993 * fTemp76);
			double fTemp338 = (fConst110 * (((fTemp329 + fTemp330) + fTemp331) - (fTemp332 + (fTemp333 + (fTemp334 + (fTemp335 + (fTemp336 + fTemp337)))))));
			double fTemp339 = (fConst111 * fRec283[1]);
			double fTemp340 = (fConst112 * fRec286[1]);
			fRec288[0] = (fTemp338 + (fTemp339 + (fRec288[1] + fTemp340)));
			fRec286[0] = fRec288[0];
			double fRec287 = ((fTemp340 + fTemp339) + fTemp338);
			fRec285[0] = (fRec286[0] + fRec285[1]);
			fRec283[0] = fRec285[0];
			double fRec284 = fRec287;
			fRec282[0] = (fTemp327 + (fTemp328 + (fRec284 + fRec282[1])));
			fRec280[0] = fRec282[0];
			double fRec281 = (fTemp327 + (fRec284 + fTemp328));
			fRec279[0] = (fRec280[0] + fRec279[1]);
			fRec277[0] = fRec279[0];
			double fRec278 = fRec281;
			double fTemp341 = (0.0031724307999999998 * fTemp121);
			double fTemp342 = (0.044553675199999997 * fTemp117);
			double fTemp343 = (0.0140904351 * fTemp119);
			double fTemp344 = (0.038937221399999999 * fTemp125);
			double fTemp345 = (0.0053397317999999997 * fTemp123);
			double fTemp346 = (fConst114 * (fTemp341 - (((fTemp342 + fTemp343) + fTemp344) + fTemp345)));
			double fTemp347 = (fConst115 * fRec289[1]);
			double fTemp348 = (fConst116 * fRec292[1]);
			fRec294[0] = (fTemp346 + (fTemp347 + (fRec294[1] + fTemp348)));
			fRec292[0] = fRec294[0];
			double fRec293 = ((fTemp348 + fTemp347) + fTemp346);
			fRec291[0] = (fRec292[0] + fRec291[1]);
			fRec289[0] = fRec291[0];
			double fRec290 = fRec293;
			double fTemp349 = (fConst118 * fRec295[1]);
			double fTemp350 = (0.0229586206 * fTemp98);
			double fTemp351 = (0.032597388900000003 * fTemp104);
			double fTemp352 = (0.0271472863 * fTemp96);
			double fTemp353 = (0.053150380599999998 * fTemp102);
			double fTemp354 = (0.033875739600000003 * fTemp92);
			double fTemp355 = (0.012073760100000001 * fTemp94);
			double fTemp356 = (0.0292325591 * fTemp100);
			double fTemp357 = (fConst120 * (fTemp350 - (fTemp351 + (fTemp352 + (fTemp353 + ((fTemp354 + fTemp355) + fTemp356))))));
			double fTemp358 = (fConst121 * fRec298[1]);
			double fTemp359 = (fConst122 * fRec301[1]);
			fRec303[0] = (fTemp357 + (fTemp358 + (fRec303[1] + fTemp359)));
			fRec301[0] = fRec303[0];
			double fRec302 = ((fTemp359 + fTemp358) + fTemp357);
			fRec300[0] = (fRec301[0] + fRec300[1]);
			fRec298[0] = fRec300[0];
			double fRec299 = fRec302;
			fRec297[0] = (fTemp349 + (fRec299 + fRec297[1]));
			fRec295[0] = fRec297[0];
			double fRec296 = (fRec299 + fTemp349);
			fVec3[(IOTA & 127)] = (fTemp284 + (fRec242 + (fRec245 + (fRec263 + (fRec278 + (fRec290 + fRec296))))));
			output3[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec3[((IOTA - iConst123) & 127)])));
			double fTemp360 = (fConst4 * fRec304[1]);
			double fTemp361 = (fConst5 * fRec307[1]);
			double fTemp362 = (fConst7 * fRec310[1]);
			double fTemp363 = (fConst8 * fRec313[1]);
			double fTemp364 = (0.093133545100000006 * fTemp29);
			double fTemp365 = (0.045223004099999999 * fTemp19);
			double fTemp366 = (0.068071180100000003 * fTemp11);
			double fTemp367 = (0.041449476800000003 * fTemp33);
			double fTemp368 = (0.035267777399999999 * fTemp23);
			double fTemp369 = (0.069031775099999998 * fTemp15);
			double fTemp370 = (fConst10 * ((fTemp36 + ((fTemp364 + (fTemp28 + (fTemp365 + (fTemp18 + (fTemp26 + (fTemp14 + (fTemp22 + fTemp366))))))) + fTemp367)) - (fTemp32 + (fTemp368 + fTemp369))));
			double fTemp371 = (fConst12 * fRec316[1]);
			double fTemp372 = (fConst13 * fRec319[1]);
			fRec321[0] = (fTemp370 + (fTemp371 + (fRec321[1] + fTemp372)));
			fRec319[0] = fRec321[0];
			double fRec320 = ((fTemp372 + fTemp371) + fTemp370);
			fRec318[0] = (fRec319[0] + fRec318[1]);
			fRec316[0] = fRec318[0];
			double fRec317 = fRec320;
			fRec315[0] = (fTemp362 + (fTemp363 + (fRec317 + fRec315[1])));
			fRec313[0] = fRec315[0];
			double fRec314 = (fTemp362 + (fRec317 + fTemp363));
			fRec312[0] = (fRec313[0] + fRec312[1]);
			fRec310[0] = fRec312[0];
			double fRec311 = fRec314;
			fRec309[0] = (fTemp360 + (fTemp361 + (fRec311 + fRec309[1])));
			fRec307[0] = fRec309[0];
			double fRec308 = (fTemp360 + (fRec311 + fTemp361));
			fRec306[0] = (fRec307[0] + fRec306[1]);
			fRec304[0] = fRec306[0];
			double fRec305 = fRec308;
			double fTemp373 = (fConst15 * fRec322[1]);
			double fTemp374 = (fConst17 * fRec325[1]);
			double fTemp375 = (fConst18 * fRec328[1]);
			double fTemp376 = (0.057142282799999999 * fTemp63);
			double fTemp377 = (0.029642125200000001 * fTemp59);
			double fTemp378 = (0.016947781799999999 * fTemp51);
			double fTemp379 = (0.098174667600000001 * fTemp43);
			double fTemp380 = (0.0421689986 * fTemp53);
			double fTemp381 = (0.016857897 * fTemp47);
			double fTemp382 = (fConst20 * ((fTemp376 + (fTemp377 + (fTemp58 + (fTemp378 + (fTemp50 + (fTemp56 + (fTemp46 + fTemp379))))))) - (fTemp62 + (fTemp380 + fTemp381))));
			double fTemp383 = (fConst21 * fRec331[1]);
			double fTemp384 = (fConst22 * fRec334[1]);
			fRec336[0] = (fTemp382 + (fTemp383 + (fRec336[1] + fTemp384)));
			fRec334[0] = fRec336[0];
			double fRec335 = ((fTemp384 + fTemp383) + fTemp382);
			fRec333[0] = (fRec334[0] + fRec333[1]);
			fRec331[0] = fRec333[0];
			double fRec332 = fRec335;
			fRec330[0] = (fTemp374 + (fTemp375 + (fRec332 + fRec330[1])));
			fRec328[0] = fRec330[0];
			double fRec329 = (fTemp374 + (fRec332 + fTemp375));
			fRec327[0] = (fRec328[0] + fRec327[1]);
			fRec325[0] = fRec327[0];
			double fRec326 = fRec329;
			fRec324[0] = (fTemp373 + (fRec326 + fRec324[1]));
			fRec322[0] = fRec324[0];
			double fRec323 = (fRec326 + fTemp373);
			double fTemp385 = (fConst29 * fRec337[1]);
			double fTemp386 = (fConst28 * fRec340[1]);
			double fTemp387 = (0.052111776300000003 * fTemp80);
			double fTemp388 = (0.022189459299999999 * fTemp82);
			double fTemp389 = (0.0322351123 * fTemp70);
			double fTemp390 = (0.061084264300000003 * fTemp74);
			double fTemp391 = (fConst25 * ((fTemp85 + (fTemp73 + ((fTemp69 + fTemp79) + fTemp387))) - (fTemp388 + (fTemp389 + (fTemp77 + fTemp390)))));
			double fTemp392 = (fConst27 * fRec343[1]);
			double fTemp393 = (fConst26 * fRec346[1]);
			fRec348[0] = (fTemp391 + (fTemp392 + (fRec348[1] + fTemp393)));
			fRec346[0] = fRec348[0];
			double fRec347 = ((fTemp393 + fTemp392) + fTemp391);
			fRec345[0] = (fRec346[0] + fRec345[1]);
			fRec343[0] = fRec345[0];
			double fRec344 = fRec347;
			fRec342[0] = (fTemp385 + (fTemp386 + (fRec344 + fRec342[1])));
			fRec340[0] = fRec342[0];
			double fRec341 = (fTemp385 + (fRec344 + fTemp386));
			fRec339[0] = (fRec340[0] + fRec339[1]);
			fRec337[0] = fRec339[0];
			double fRec338 = fRec341;
			double fTemp394 = (fConst31 * fRec349[1]);
			double fTemp395 = (0.040498825600000003 * fTemp98);
			double fTemp396 = (0.064879342600000001 * fTemp104);
			double fTemp397 = (0.0162554377 * fTemp102);
			double fTemp398 = (0.0168709784 * fTemp92);
			double fTemp399 = (fConst33 * (fTemp395 - (fTemp396 + (fTemp97 + (fTemp397 + (fTemp101 + (fTemp95 + fTemp398)))))));
			double fTemp400 = (fConst34 * fRec352[1]);
			double fTemp401 = (fConst35 * fRec355[1]);
			fRec357[0] = (fTemp399 + (fTemp400 + (fRec357[1] + fTemp401)));
			fRec355[0] = fRec357[0];
			double fRec356 = ((fTemp401 + fTemp400) + fTemp399);
			fRec354[0] = (fRec355[0] + fRec354[1]);
			fRec352[0] = fRec354[0];
			double fRec353 = fRec356;
			fRec351[0] = (fTemp394 + (fRec353 + fRec351[1]));
			fRec349[0] = fRec351[0];
			double fRec350 = (fRec353 + fTemp394);
			double fTemp402 = (0.017340396500000001 * fTemp111);
			double fTemp403 = (0.0273310077 * fTemp109);
			double fTemp404 = (fConst37 * (fTemp402 - (fTemp114 + fTemp403)));
			double fTemp405 = (fConst38 * fRec358[1]);
			fRec360[0] = (fTemp404 + (fRec360[1] + fTemp405));
			fRec358[0] = fRec360[0];
			double fRec359 = (fTemp405 + fTemp404);
			double fTemp406 = (0.013089181700000001 * fTemp121);
			double fTemp407 = (0.0149107267 * fTemp119);
			double fTemp408 = (fConst40 * (fTemp406 - (fTemp124 + (fTemp126 + (fTemp118 + fTemp407)))));
			double fTemp409 = (fConst41 * fRec361[1]);
			double fTemp410 = (fConst42 * fRec364[1]);
			fRec366[0] = (fTemp408 + (fTemp409 + (fRec366[1] + fTemp410)));
			fRec364[0] = fRec366[0];
			double fRec365 = ((fTemp410 + fTemp409) + fTemp408);
			fRec363[0] = (fRec364[0] + fRec363[1]);
			fRec361[0] = fRec363[0];
			double fRec362 = fRec365;
			fVec4[(IOTA & 127)] = (fTemp131 + (fRec305 + (fRec323 + (fRec338 + (fRec350 + (fRec359 + fRec362))))));
			output4[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec4[((IOTA - iConst43) & 127)])));
			double fTemp411 = (fConst45 * fRec367[1]);
			double fTemp412 = (fConst46 * fRec370[1]);
			double fTemp413 = (fConst48 * fRec373[1]);
			double fTemp414 = (fConst49 * fRec376[1]);
			double fTemp415 = (0.048803048199999997 * fTemp33);
			double fTemp416 = (0.083365635399999999 * fTemp29);
			double fTemp417 = (0.020947159 * fTemp19);
			double fTemp418 = (0.0816658257 * fTemp15);
			double fTemp419 = (0.063422363199999998 * fTemp11);
			double fTemp420 = (0.1116506973 * fTemp23);
			double fTemp421 = (fConst51 * ((fTemp415 + (fTemp145 + (fTemp416 + (fTemp149 + (fTemp140 + fTemp417))))) - (fTemp137 + (fTemp418 + (fTemp144 + ((fTemp147 + (fTemp142 + fTemp419)) + fTemp420))))));
			double fTemp422 = (fConst52 * fRec379[1]);
			double fTemp423 = (fConst53 * fRec382[1]);
			fRec384[0] = (fTemp421 + (fTemp422 + (fRec384[1] + fTemp423)));
			fRec382[0] = fRec384[0];
			double fRec383 = ((fTemp423 + fTemp422) + fTemp421);
			fRec381[0] = (fRec382[0] + fRec381[1]);
			fRec379[0] = fRec381[0];
			double fRec380 = fRec383;
			fRec378[0] = (fTemp413 + (fTemp414 + (fRec380 + fRec378[1])));
			fRec376[0] = fRec378[0];
			double fRec377 = (fTemp413 + (fRec380 + fTemp414));
			fRec375[0] = (fRec376[0] + fRec375[1]);
			fRec373[0] = fRec375[0];
			double fRec374 = fRec377;
			fRec372[0] = (fTemp411 + (fTemp412 + (fRec374 + fRec372[1])));
			fRec370[0] = fRec372[0];
			double fRec371 = (fTemp411 + (fRec374 + fTemp412));
			fRec369[0] = (fRec370[0] + fRec369[1]);
			fRec367[0] = fRec369[0];
			double fRec368 = fRec371;
			double fTemp424 = (fConst55 * fRec385[1]);
			double fTemp425 = (fConst57 * fRec388[1]);
			double fTemp426 = (fConst58 * fRec391[1]);
			double fTemp427 = (0.068486062599999994 * fTemp63);
			double fTemp428 = (0.0680715655 * fTemp59);
			double fTemp429 = (0.0178723371 * fTemp51);
			double fTemp430 = (0.021370773499999999 * fTemp47);
			double fTemp431 = (0.090596771899999998 * fTemp43);
			double fTemp432 = (0.055773845699999998 * fTemp53);
			double fTemp433 = (fConst60 * ((fTemp427 + (fTemp162 + (fTemp428 + (fTemp166 + (fTemp158 + fTemp429))))) - (fTemp430 + (fTemp160 + ((fTemp164 + fTemp431) + fTemp432)))));
			double fTemp434 = (fConst61 * fRec394[1]);
			double fTemp435 = (fConst62 * fRec397[1]);
			fRec399[0] = (fTemp433 + (fTemp434 + (fRec399[1] + fTemp435)));
			fRec397[0] = fRec399[0];
			double fRec398 = ((fTemp435 + fTemp434) + fTemp433);
			fRec396[0] = (fRec397[0] + fRec396[1]);
			fRec394[0] = fRec396[0];
			double fRec395 = fRec398;
			fRec393[0] = (fTemp425 + (fTemp426 + (fRec395 + fRec393[1])));
			fRec391[0] = fRec393[0];
			double fRec392 = (fTemp425 + (fRec395 + fTemp426));
			fRec390[0] = (fRec391[0] + fRec390[1]);
			fRec388[0] = fRec390[0];
			double fRec389 = fRec392;
			fRec387[0] = (fTemp424 + (fRec389 + fRec387[1]));
			fRec385[0] = fRec387[0];
			double fRec386 = (fRec389 + fTemp424);
			double fTemp436 = (fConst64 * fRec400[1]);
			double fTemp437 = (fConst65 * fRec403[1]);
			double fTemp438 = (0.0087492128999999991 * fTemp82);
			double fTemp439 = (0.058035407800000001 * fTemp80);
			double fTemp440 = (0.034539284900000002 * fTemp70);
			double fTemp441 = (0.0208388706 * fTemp74);
			double fTemp442 = (fConst67 * ((fTemp178 + (fTemp438 + (fTemp172 + (fTemp439 + (fTemp440 + (fTemp175 + (fTemp177 + fTemp441))))))) - fTemp174));
			double fTemp443 = (fConst68 * fRec406[1]);
			double fTemp444 = (fConst69 * fRec409[1]);
			fRec411[0] = (fTemp442 + (fTemp443 + (fRec411[1] + fTemp444)));
			fRec409[0] = fRec411[0];
			double fRec410 = ((fTemp444 + fTemp443) + fTemp442);
			fRec408[0] = (fRec409[0] + fRec408[1]);
			fRec406[0] = fRec408[0];
			double fRec407 = fRec410;
			fRec405[0] = (fTemp436 + (fTemp437 + (fRec407 + fRec405[1])));
			fRec403[0] = fRec405[0];
			double fRec404 = (fTemp436 + (fRec407 + fTemp437));
			fRec402[0] = (fRec403[0] + fRec402[1]);
			fRec400[0] = fRec402[0];
			double fRec401 = fRec404;
			double fTemp445 = (fConst71 * fRec412[1]);
			double fTemp446 = (0.046898843900000001 * fTemp92);
			double fTemp447 = (0.044600507400000003 * fTemp98);
			double fTemp448 = (0.0085236648000000005 * fTemp102);
			double fTemp449 = (0.00081938530000000005 * fTemp104);
			double fTemp450 = (fConst73 * (((fTemp446 + fTemp447) + fTemp448) - (fTemp449 + (fTemp189 + (fTemp187 + fTemp190)))));
			double fTemp451 = (fConst74 * fRec415[1]);
			double fTemp452 = (fConst75 * fRec418[1]);
			fRec420[0] = (fTemp450 + (fTemp451 + (fRec420[1] + fTemp452)));
			fRec418[0] = fRec420[0];
			double fRec419 = ((fTemp452 + fTemp451) + fTemp450);
			fRec417[0] = (fRec418[0] + fRec417[1]);
			fRec415[0] = fRec417[0];
			double fRec416 = fRec419;
			fRec414[0] = (fTemp445 + (fRec416 + fRec414[1]));
			fRec412[0] = fRec414[0];
			double fRec413 = (fRec416 + fTemp445);
			double fTemp453 = (0.0076788888999999999 * fTemp111);
			double fTemp454 = (0.031343059999999999 * fTemp109);
			double fTemp455 = (fConst77 * ((fTemp196 + fTemp453) - fTemp454));
			double fTemp456 = (fConst78 * fRec421[1]);
			fRec423[0] = (fTemp455 + (fRec423[1] + fTemp456));
			fRec421[0] = fRec423[0];
			double fRec422 = (fTemp456 + fTemp455);
			double fTemp457 = (0.0116788602 * fTemp121);
			double fTemp458 = (0.018087756999999999 * fTemp119);
			double fTemp459 = (fConst80 * (fTemp457 - (fTemp203 + (fTemp204 + (fTemp200 + fTemp458)))));
			double fTemp460 = (fConst81 * fRec424[1]);
			double fTemp461 = (fConst82 * fRec427[1]);
			fRec429[0] = (fTemp459 + (fTemp460 + (fRec429[1] + fTemp461)));
			fRec427[0] = fRec429[0];
			double fRec428 = ((fTemp461 + fTemp460) + fTemp459);
			fRec426[0] = (fRec427[0] + fRec426[1]);
			fRec424[0] = fRec426[0];
			double fRec425 = fRec428;
			fVec5[(IOTA & 127)] = (fTemp132 + (fRec368 + (fRec386 + (fRec401 + (fRec413 + (fRec422 + fRec425))))));
			output5[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec5[((IOTA - iConst83) & 127)])));
			double fTemp462 = (fConst45 * fRec430[1]);
			double fTemp463 = (fConst46 * fRec433[1]);
			double fTemp464 = (fConst48 * fRec436[1]);
			double fTemp465 = (fConst49 * fRec439[1]);
			double fTemp466 = (0.078016207700000006 * fTemp33);
			double fTemp467 = (0.090670927100000007 * fTemp29);
			double fTemp468 = (0.024179950400000001 * fTemp19);
			double fTemp469 = (0.071417636000000007 * fTemp15);
			double fTemp470 = (0.020568156600000002 * fTemp11);
			double fTemp471 = (0.040755332200000001 * fTemp23);
			double fTemp472 = (fConst51 * ((fTemp249 + (fTemp242 + (fTemp248 + (fTemp244 + fTemp241)))) - (fTemp466 + (fTemp467 + (fTemp468 + (fTemp469 + (fTemp240 + ((fTemp246 + fTemp470) + fTemp471))))))));
			double fTemp473 = (fConst52 * fRec442[1]);
			double fTemp474 = (fConst53 * fRec445[1]);
			fRec447[0] = (fTemp472 + (fTemp473 + (fRec447[1] + fTemp474)));
			fRec445[0] = fRec447[0];
			double fRec446 = ((fTemp474 + fTemp473) + fTemp472);
			fRec444[0] = (fRec445[0] + fRec444[1]);
			fRec442[0] = fRec444[0];
			double fRec443 = fRec446;
			fRec441[0] = (fTemp464 + (fTemp465 + (fRec443 + fRec441[1])));
			fRec439[0] = fRec441[0];
			double fRec440 = (fTemp464 + (fRec443 + fTemp465));
			fRec438[0] = (fRec439[0] + fRec438[1]);
			fRec436[0] = fRec438[0];
			double fRec437 = fRec440;
			fRec435[0] = (fTemp462 + (fTemp463 + (fRec437 + fRec435[1])));
			fRec433[0] = fRec435[0];
			double fRec434 = (fTemp462 + (fRec437 + fTemp463));
			fRec432[0] = (fRec433[0] + fRec432[1]);
			fRec430[0] = fRec432[0];
			double fRec431 = fRec434;
			double fTemp475 = (fConst55 * fRec448[1]);
			double fTemp476 = (fConst57 * fRec451[1]);
			double fTemp477 = (fConst58 * fRec454[1]);
			double fTemp478 = (0.0091060373999999993 * fTemp53);
			double fTemp479 = (0.10989283649999999 * fTemp63);
			double fTemp480 = (0.0087722001000000004 * fTemp51);
			double fTemp481 = (0.0084126763999999993 * fTemp47);
			double fTemp482 = (0.0287108511 * fTemp43);
			double fTemp483 = (0.050512797999999998 * fTemp59);
			double fTemp484 = (fConst60 * ((fTemp271 + (fTemp280 + (fTemp275 + fTemp478))) - (fTemp479 + ((fTemp480 + (fTemp481 + (fTemp274 + (fTemp278 + fTemp482)))) + fTemp483))));
			double fTemp485 = (fConst61 * fRec457[1]);
			double fTemp486 = (fConst62 * fRec460[1]);
			fRec462[0] = (fTemp484 + (fTemp485 + (fRec462[1] + fTemp486)));
			fRec460[0] = fRec462[0];
			double fRec461 = ((fTemp486 + fTemp485) + fTemp484);
			fRec459[0] = (fRec460[0] + fRec459[1]);
			fRec457[0] = fRec459[0];
			double fRec458 = fRec461;
			fRec456[0] = (fTemp476 + (fTemp477 + (fRec458 + fRec456[1])));
			fRec454[0] = fRec456[0];
			double fRec455 = (fTemp476 + (fRec458 + fTemp477));
			fRec453[0] = (fRec454[0] + fRec453[1]);
			fRec451[0] = fRec453[0];
			double fRec452 = fRec455;
			fRec450[0] = (fTemp475 + (fRec452 + fRec450[1]));
			fRec448[0] = fRec450[0];
			double fRec449 = (fRec452 + fTemp475);
			double fTemp487 = (fConst64 * fRec463[1]);
			double fTemp488 = (fConst65 * fRec466[1]);
			double fTemp489 = (0.011931962399999999 * fTemp82);
			double fTemp490 = (0.070262175600000004 * fTemp80);
			double fTemp491 = (0.066471682599999998 * fTemp70);
			double fTemp492 = (0.0206847444 * fTemp74);
			double fTemp493 = (fConst67 * ((fTemp260 + (fTemp489 + (fTemp255 + (fTemp490 + (fTemp491 + (fTemp259 + fTemp492)))))) - (fTemp261 + fTemp257)));
			double fTemp494 = (fConst68 * fRec469[1]);
			double fTemp495 = (fConst69 * fRec472[1]);
			fRec474[0] = (fTemp493 + (fTemp494 + (fRec474[1] + fTemp495)));
			fRec472[0] = fRec474[0];
			double fRec473 = ((fTemp495 + fTemp494) + fTemp493);
			fRec471[0] = (fRec472[0] + fRec471[1]);
			fRec469[0] = fRec471[0];
			double fRec470 = fRec473;
			fRec468[0] = (fTemp487 + (fTemp488 + (fRec470 + fRec468[1])));
			fRec466[0] = fRec468[0];
			double fRec467 = (fTemp487 + (fRec470 + fTemp488));
			fRec465[0] = (fRec466[0] + fRec465[1]);
			fRec463[0] = fRec465[0];
			double fRec464 = fRec467;
			double fTemp496 = (fConst71 * fRec475[1]);
			double fTemp497 = (0.058080233100000003 * fTemp92);
			double fTemp498 = (0.055677016000000003 * fTemp98);
			double fTemp499 = (0.0086732855000000008 * fTemp102);
			double fTemp500 = (0.0341673963 * fTemp104);
			double fTemp501 = (fConst73 * ((((fTemp497 + fTemp498) + fTemp499) + fTemp500) - (fTemp226 + (fTemp224 + fTemp229))));
			double fTemp502 = (fConst74 * fRec478[1]);
			double fTemp503 = (fConst75 * fRec481[1]);
			fRec483[0] = (fTemp501 + (fTemp502 + (fRec483[1] + fTemp503)));
			fRec481[0] = fRec483[0];
			double fRec482 = ((fTemp503 + fTemp502) + fTemp501);
			fRec480[0] = (fRec481[0] + fRec480[1]);
			fRec478[0] = fRec480[0];
			double fRec479 = fRec482;
			fRec477[0] = (fTemp496 + (fRec479 + fRec477[1]));
			fRec475[0] = fRec477[0];
			double fRec476 = (fRec479 + fTemp496);
			double fTemp504 = (0.0275897882 * fTemp109);
			double fTemp505 = (0.0088826606999999995 * fTemp111);
			double fTemp506 = (fConst77 * (fTemp217 - (fTemp504 + fTemp505)));
			double fTemp507 = (fConst78 * fRec484[1]);
			fRec486[0] = (fTemp506 + (fRec486[1] + fTemp507));
			fRec484[0] = fRec486[0];
			double fRec485 = (fTemp507 + fTemp506);
			double fTemp508 = (0.0097275085000000008 * fTemp119);
			double fTemp509 = (0.0066697817999999999 * fTemp121);
			double fTemp510 = (fConst80 * (fTemp211 - (fTemp210 + ((fTemp213 + fTemp508) + fTemp509))));
			double fTemp511 = (fConst81 * fRec487[1]);
			double fTemp512 = (fConst82 * fRec490[1]);
			fRec492[0] = (fTemp510 + (fTemp511 + (fRec492[1] + fTemp512)));
			fRec490[0] = fRec492[0];
			double fRec491 = ((fTemp512 + fTemp511) + fTemp510);
			fRec489[0] = (fRec490[0] + fRec489[1]);
			fRec487[0] = fRec489[0];
			double fRec488 = fRec491;
			fVec6[(IOTA & 127)] = (fTemp208 + (fRec431 + (fRec449 + (fRec464 + (fRec476 + (fRec485 + fRec488))))));
			output6[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec6[((IOTA - iConst83) & 127)])));
			double fTemp513 = (fConst88 * fRec493[1]);
			double fTemp514 = (fConst89 * fRec496[1]);
			double fTemp515 = (fConst91 * fRec499[1]);
			double fTemp516 = (fConst92 * fRec502[1]);
			double fTemp517 = (0.078105643799999999 * fTemp11);
			double fTemp518 = (0.020415736 * fTemp23);
			double fTemp519 = (0.0096399316999999998 * fTemp33);
			double fTemp520 = (0.0531762452 * fTemp19);
			double fTemp521 = (0.052402788700000001 * fTemp15);
			double fTemp522 = (0.1378065684 * fTemp29);
			double fTemp523 = (fConst94 * ((fTemp302 + ((fTemp305 + (fTemp300 + ((fTemp297 + fTemp517) + fTemp518))) + fTemp519)) - (fTemp306 + ((fTemp520 + (fTemp521 + (fTemp295 + fTemp299))) + fTemp522))));
			double fTemp524 = (fConst95 * fRec505[1]);
			double fTemp525 = (fConst96 * fRec508[1]);
			fRec510[0] = (fTemp523 + (fTemp524 + (fRec510[1] + fTemp525)));
			fRec508[0] = fRec510[0];
			double fRec509 = ((fTemp525 + fTemp524) + fTemp523);
			fRec507[0] = (fRec508[0] + fRec507[1]);
			fRec505[0] = fRec507[0];
			double fRec506 = fRec509;
			fRec504[0] = (fTemp515 + (fTemp516 + (fRec506 + fRec504[1])));
			fRec502[0] = fRec504[0];
			double fRec503 = (fTemp515 + (fRec506 + fTemp516));
			fRec501[0] = (fRec502[0] + fRec501[1]);
			fRec499[0] = fRec501[0];
			double fRec500 = fRec503;
			fRec498[0] = (fTemp513 + (fTemp514 + (fRec500 + fRec498[1])));
			fRec496[0] = fRec498[0];
			double fRec497 = (fTemp513 + (fRec500 + fTemp514));
			fRec495[0] = (fRec496[0] + fRec495[1]);
			fRec493[0] = fRec495[0];
			double fRec494 = fRec497;
			double fTemp526 = (fConst98 * fRec511[1]);
			double fTemp527 = (fConst100 * fRec514[1]);
			double fTemp528 = (fConst101 * fRec517[1]);
			double fTemp529 = (0.1129992022 * fTemp43);
			double fTemp530 = (0.0011559691 * fTemp47);
			double fTemp531 = (0.0164026057 * fTemp63);
			double fTemp532 = (0.0083578456000000002 * fTemp53);
			double fTemp533 = (0.017965227899999998 * fTemp51);
			double fTemp534 = (0.087240938399999995 * fTemp59);
			double fTemp535 = (fConst103 * (((fTemp321 + (fTemp317 + ((fTemp314 + fTemp529) + fTemp530))) + fTemp531) - (fTemp319 + (((fTemp316 + fTemp532) + fTemp533) + fTemp534))));
			double fTemp536 = (fConst104 * fRec520[1]);
			double fTemp537 = (fConst105 * fRec523[1]);
			fRec525[0] = (fTemp535 + (fTemp536 + (fRec525[1] + fTemp537)));
			fRec523[0] = fRec525[0];
			double fRec524 = ((fTemp537 + fTemp536) + fTemp535);
			fRec522[0] = (fRec523[0] + fRec522[1]);
			fRec520[0] = fRec522[0];
			double fRec521 = fRec524;
			fRec519[0] = (fTemp527 + (fTemp528 + (fRec521 + fRec519[1])));
			fRec517[0] = fRec519[0];
			double fRec518 = (fTemp527 + (fRec521 + fTemp528));
			fRec516[0] = (fRec517[0] + fRec516[1]);
			fRec514[0] = fRec516[0];
			double fRec515 = fRec518;
			fRec513[0] = (fTemp526 + (fRec515 + fRec513[1]));
			fRec511[0] = fRec513[0];
			double fRec512 = (fRec515 + fTemp526);
			double fTemp538 = (fConst107 * fRec526[1]);
			double fTemp539 = (fConst108 * fRec529[1]);
			double fTemp540 = (0.030303552899999999 * fTemp82);
			double fTemp541 = (0.065912215600000004 * fTemp80);
			double fTemp542 = (0.0099295531000000003 * fTemp74);
			double fTemp543 = (0.0389362527 * fTemp70);
			double fTemp544 = (fTemp335 + fTemp337);
			double fTemp545 = (fConst110 * ((fTemp332 + (fTemp540 + (fTemp331 + (fTemp541 + fTemp542)))) - (fTemp329 + (fTemp543 + fTemp544))));
			double fTemp546 = (fConst111 * fRec532[1]);
			double fTemp547 = (fConst112 * fRec535[1]);
			fRec537[0] = (fTemp545 + (fTemp546 + (fRec537[1] + fTemp547)));
			fRec535[0] = fRec537[0];
			double fRec536 = ((fTemp547 + fTemp546) + fTemp545);
			fRec534[0] = (fRec535[0] + fRec534[1]);
			fRec532[0] = fRec534[0];
			double fRec533 = fRec536;
			fRec531[0] = (fTemp538 + (fTemp539 + (fRec533 + fRec531[1])));
			fRec529[0] = fRec531[0];
			double fRec530 = (fTemp538 + (fRec533 + fTemp539));
			fRec528[0] = (fRec529[0] + fRec528[1]);
			fRec526[0] = fRec528[0];
			double fRec527 = fRec530;
			double fTemp548 = (fConst118 * fRec538[1]);
			double fTemp549 = (0.033875739600000003 * fTemp104);
			double fTemp550 = (0.053150380599999998 * fTemp98);
			double fTemp551 = (0.0229586206 * fTemp102);
			double fTemp552 = (0.032597388900000003 * fTemp92);
			double fTemp553 = (fConst120 * ((fTemp549 + (fTemp352 + ((fTemp355 + fTemp550) + fTemp551))) - (fTemp356 + fTemp552)));
			double fTemp554 = (fConst121 * fRec541[1]);
			double fTemp555 = (fConst122 * fRec544[1]);
			fRec546[0] = (fTemp553 + (fTemp554 + (fRec546[1] + fTemp555)));
			fRec544[0] = fRec546[0];
			double fRec545 = ((fTemp555 + fTemp554) + fTemp553);
			fRec543[0] = (fRec544[0] + fRec543[1]);
			fRec541[0] = fRec543[0];
			double fRec542 = fRec545;
			fRec540[0] = (fTemp548 + (fRec542 + fRec540[1]));
			fRec538[0] = fRec540[0];
			double fRec539 = (fRec542 + fTemp548);
			double fTemp556 = (0.0209882757 * fTemp109);
			double fTemp557 = (0.020633909700000001 * fTemp111);
			double fTemp558 = (fConst85 * (0.0 - ((fTemp287 + fTemp556) + fTemp557)));
			double fTemp559 = (fConst86 * fRec547[1]);
			fRec549[0] = (fTemp558 + (fRec549[1] + fTemp559));
			fRec547[0] = fRec549[0];
			double fRec548 = (fTemp559 + fTemp558);
			double fTemp560 = (0.0031724307999999998 * fTemp119);
			double fTemp561 = (0.0140904351 * fTemp121);
			double fTemp562 = (fConst114 * ((fTemp342 + fTemp345) - ((fTemp344 + fTemp560) + fTemp561)));
			double fTemp563 = (fConst115 * fRec550[1]);
			double fTemp564 = (fConst116 * fRec553[1]);
			fRec555[0] = (fTemp562 + (fTemp563 + (fRec555[1] + fTemp564)));
			fRec553[0] = fRec555[0];
			double fRec554 = ((fTemp564 + fTemp563) + fTemp562);
			fRec552[0] = (fRec553[0] + fRec552[1]);
			fRec550[0] = fRec552[0];
			double fRec551 = fRec554;
			fVec7[(IOTA & 127)] = (fTemp284 + (fRec494 + (fRec512 + (fRec527 + (fRec539 + (fRec548 + fRec551))))));
			output7[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec7[((IOTA - iConst123) & 127)])));
			double fTemp565 = (fConst29 * fRec556[1]);
			double fTemp566 = (fConst28 * fRec559[1]);
			double fTemp567 = (fConst25 * ((fTemp83 + (fTemp73 + (fTemp81 + (fTemp75 + fTemp69)))) - (fTemp85 + (fTemp79 + (fTemp77 + fTemp71)))));
			double fTemp568 = (fConst27 * fRec562[1]);
			double fTemp569 = (fConst26 * fRec565[1]);
			fRec567[0] = (fTemp567 + (fTemp568 + (fRec567[1] + fTemp569)));
			fRec565[0] = fRec567[0];
			double fRec566 = ((fTemp569 + fTemp568) + fTemp567);
			fRec564[0] = (fRec565[0] + fRec564[1]);
			fRec562[0] = fRec564[0];
			double fRec563 = fRec566;
			fRec561[0] = (fTemp565 + (fTemp566 + (fRec563 + fRec561[1])));
			fRec559[0] = fRec561[0];
			double fRec560 = (fTemp565 + (fRec563 + fTemp566));
			fRec558[0] = (fRec559[0] + fRec558[1]);
			fRec556[0] = fRec558[0];
			double fRec557 = fRec560;
			double fTemp570 = (fConst31 * fRec568[1]);
			double fTemp571 = (fConst33 * ((fTemp105 + (fTemp97 + (fTemp103 + (fTemp95 + fTemp99)))) - (fTemp93 + fTemp101)));
			double fTemp572 = (fConst34 * fRec571[1]);
			double fTemp573 = (fConst35 * fRec574[1]);
			fRec576[0] = (fTemp571 + (fTemp572 + (fRec576[1] + fTemp573)));
			fRec574[0] = fRec576[0];
			double fRec575 = ((fTemp573 + fTemp572) + fTemp571);
			fRec573[0] = (fRec574[0] + fRec573[1]);
			fRec571[0] = fRec573[0];
			double fRec572 = fRec575;
			fRec570[0] = (fTemp570 + (fRec572 + fRec570[1]));
			fRec568[0] = fRec570[0];
			double fRec569 = (fRec572 + fTemp570);
			double fTemp574 = (fConst40 * ((fTemp118 + fTemp124) - (fTemp122 + (fTemp120 + fTemp126))));
			double fTemp575 = (fConst41 * fRec577[1]);
			double fTemp576 = (fConst42 * fRec580[1]);
			fRec582[0] = (fTemp574 + (fTemp575 + (fRec582[1] + fTemp576)));
			fRec580[0] = fRec582[0];
			double fRec581 = ((fTemp576 + fTemp575) + fTemp574);
			fRec579[0] = (fRec580[0] + fRec579[1]);
			fRec577[0] = fRec579[0];
			double fRec578 = fRec581;
			double fTemp577 = (fConst37 * (0.0 - (fTemp112 + (fTemp110 + fTemp114))));
			double fTemp578 = (fConst38 * fRec583[1]);
			fRec585[0] = (fTemp577 + (fRec585[1] + fTemp578));
			fRec583[0] = fRec585[0];
			double fRec584 = (fTemp578 + fTemp577);
			double fTemp579 = (fConst4 * fRec586[1]);
			double fTemp580 = (fConst5 * fRec589[1]);
			double fTemp581 = (fConst7 * fRec592[1]);
			double fTemp582 = (fConst8 * fRec595[1]);
			double fTemp583 = (fConst10 * ((fTemp34 + (fTemp30 + (fTemp18 + (fTemp14 + fTemp24)))) - (fTemp36 + (fTemp32 + (fTemp28 + (fTemp20 + (fTemp16 + (fTemp26 + (fTemp22 + fTemp12)))))))));
			double fTemp584 = (fConst12 * fRec598[1]);
			double fTemp585 = (fConst13 * fRec601[1]);
			fRec603[0] = (fTemp583 + (fTemp584 + (fRec603[1] + fTemp585)));
			fRec601[0] = fRec603[0];
			double fRec602 = ((fTemp585 + fTemp584) + fTemp583);
			fRec600[0] = (fRec601[0] + fRec600[1]);
			fRec598[0] = fRec600[0];
			double fRec599 = fRec602;
			fRec597[0] = (fTemp581 + (fTemp582 + (fRec599 + fRec597[1])));
			fRec595[0] = fRec597[0];
			double fRec596 = (fTemp581 + (fRec599 + fTemp582));
			fRec594[0] = (fRec595[0] + fRec594[1]);
			fRec592[0] = fRec594[0];
			double fRec593 = fRec596;
			fRec591[0] = (fTemp579 + (fTemp580 + (fRec593 + fRec591[1])));
			fRec589[0] = fRec591[0];
			double fRec590 = (fTemp579 + (fRec593 + fTemp580));
			fRec588[0] = (fRec589[0] + fRec588[1]);
			fRec586[0] = fRec588[0];
			double fRec587 = fRec590;
			double fTemp586 = (fConst15 * fRec604[1]);
			double fTemp587 = (fConst17 * fRec607[1]);
			double fTemp588 = (fConst18 * fRec610[1]);
			double fTemp589 = (fConst20 * ((fTemp64 + (fTemp60 + (fTemp50 + (fTemp46 + fTemp54)))) - (fTemp62 + (fTemp58 + (fTemp52 + (fTemp48 + (fTemp44 + fTemp56)))))));
			double fTemp590 = (fConst21 * fRec613[1]);
			double fTemp591 = (fConst22 * fRec616[1]);
			fRec618[0] = (fTemp589 + (fTemp590 + (fRec618[1] + fTemp591)));
			fRec616[0] = fRec618[0];
			double fRec617 = ((fTemp591 + fTemp590) + fTemp589);
			fRec615[0] = (fRec616[0] + fRec615[1]);
			fRec613[0] = fRec615[0];
			double fRec614 = fRec617;
			fRec612[0] = (fTemp587 + (fTemp588 + (fRec614 + fRec612[1])));
			fRec610[0] = fRec612[0];
			double fRec611 = (fTemp587 + (fRec614 + fTemp588));
			fRec609[0] = (fRec610[0] + fRec609[1]);
			fRec607[0] = fRec609[0];
			double fRec608 = fRec611;
			fRec606[0] = (fTemp586 + (fRec608 + fRec606[1]));
			fRec604[0] = fRec606[0];
			double fRec605 = (fRec608 + fTemp586);
			fVec8[(IOTA & 127)] = (fTemp131 + (fRec557 + (fRec569 + (fRec578 + (fRec584 + (fRec587 + fRec605))))));
			output8[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec8[((IOTA - iConst43) & 127)])));
			double fTemp592 = (fConst45 * fRec619[1]);
			double fTemp593 = (fConst46 * fRec622[1]);
			double fTemp594 = (fConst48 * fRec625[1]);
			double fTemp595 = (fConst49 * fRec628[1]);
			double fTemp596 = (fConst51 * ((fTemp137 + (fTemp145 + (fTemp146 + (fTemp140 + (fTemp144 + (fTemp142 + fTemp148)))))) - (fTemp138 + (fTemp149 + (fTemp139 + (fTemp141 + (fTemp143 + fTemp147)))))));
			double fTemp597 = (fConst52 * fRec631[1]);
			double fTemp598 = (fConst53 * fRec634[1]);
			fRec636[0] = (fTemp596 + (fTemp597 + (fRec636[1] + fTemp598)));
			fRec634[0] = fRec636[0];
			double fRec635 = ((fTemp598 + fTemp597) + fTemp596);
			fRec633[0] = (fRec634[0] + fRec633[1]);
			fRec631[0] = fRec633[0];
			double fRec632 = fRec635;
			fRec630[0] = (fTemp594 + (fTemp595 + (fRec632 + fRec630[1])));
			fRec628[0] = fRec630[0];
			double fRec629 = (fTemp594 + (fRec632 + fTemp595));
			fRec627[0] = (fRec628[0] + fRec627[1]);
			fRec625[0] = fRec627[0];
			double fRec626 = fRec629;
			fRec624[0] = (fTemp592 + (fTemp593 + (fRec626 + fRec624[1])));
			fRec622[0] = fRec624[0];
			double fRec623 = (fTemp592 + (fRec626 + fTemp593));
			fRec621[0] = (fRec622[0] + fRec621[1]);
			fRec619[0] = fRec621[0];
			double fRec620 = fRec623;
			double fTemp599 = (fConst55 * fRec637[1]);
			double fTemp600 = (fConst57 * fRec640[1]);
			double fTemp601 = (fConst58 * fRec643[1]);
			double fTemp602 = (fConst60 * ((fTemp162 + (fTemp163 + (fTemp158 + (fTemp165 + fTemp160)))) - (fTemp156 + (fTemp166 + (fTemp157 + (fTemp161 + (fTemp159 + fTemp164)))))));
			double fTemp603 = (fConst61 * fRec646[1]);
			double fTemp604 = (fConst62 * fRec649[1]);
			fRec651[0] = (fTemp602 + (fTemp603 + (fRec651[1] + fTemp604)));
			fRec649[0] = fRec651[0];
			double fRec650 = ((fTemp604 + fTemp603) + fTemp602);
			fRec648[0] = (fRec649[0] + fRec648[1]);
			fRec646[0] = fRec648[0];
			double fRec647 = fRec650;
			fRec645[0] = (fTemp600 + (fTemp601 + (fRec647 + fRec645[1])));
			fRec643[0] = fRec645[0];
			double fRec644 = (fTemp600 + (fRec647 + fTemp601));
			fRec642[0] = (fRec643[0] + fRec642[1]);
			fRec640[0] = fRec642[0];
			double fRec641 = fRec644;
			fRec639[0] = (fTemp599 + (fRec641 + fRec639[1]));
			fRec637[0] = fRec639[0];
			double fRec638 = (fRec641 + fTemp599);
			double fTemp605 = (fConst64 * fRec652[1]);
			double fTemp606 = (fConst65 * fRec655[1]);
			double fTemp607 = (fTemp175 + fTemp177);
			double fTemp608 = (fConst67 * ((fTemp180 + (fTemp172 + (fTemp174 + (fTemp179 + fTemp607)))) - (fTemp178 + (fTemp173 + fTemp176))));
			double fTemp609 = (fConst68 * fRec658[1]);
			double fTemp610 = (fConst69 * fRec661[1]);
			fRec663[0] = (fTemp608 + (fTemp609 + (fRec663[1] + fTemp610)));
			fRec661[0] = fRec663[0];
			double fRec662 = ((fTemp610 + fTemp609) + fTemp608);
			fRec660[0] = (fRec661[0] + fRec660[1]);
			fRec658[0] = fRec660[0];
			double fRec659 = fRec662;
			fRec657[0] = (fTemp605 + (fTemp606 + (fRec659 + fRec657[1])));
			fRec655[0] = fRec657[0];
			double fRec656 = (fTemp605 + (fRec659 + fTemp606));
			fRec654[0] = (fRec655[0] + fRec654[1]);
			fRec652[0] = fRec654[0];
			double fRec653 = fRec656;
			double fTemp611 = (fConst71 * fRec664[1]);
			double fTemp612 = (fConst73 * ((fTemp189 + (fTemp187 + fTemp191)) - (fTemp185 + (fTemp190 + (fTemp186 + fTemp188)))));
			double fTemp613 = (fConst74 * fRec667[1]);
			double fTemp614 = (fConst75 * fRec670[1]);
			fRec672[0] = (fTemp612 + (fTemp613 + (fRec672[1] + fTemp614)));
			fRec670[0] = fRec672[0];
			double fRec671 = ((fTemp614 + fTemp613) + fTemp612);
			fRec669[0] = (fRec670[0] + fRec669[1]);
			fRec667[0] = fRec669[0];
			double fRec668 = fRec671;
			fRec666[0] = (fTemp611 + (fRec668 + fRec666[1]));
			fRec664[0] = fRec666[0];
			double fRec665 = (fRec668 + fTemp611);
			double fTemp615 = (fConst77 * (fTemp196 - (fTemp195 + fTemp197)));
			double fTemp616 = (fConst78 * fRec673[1]);
			fRec675[0] = (fTemp615 + (fRec675[1] + fTemp616));
			fRec673[0] = fRec675[0];
			double fRec674 = (fTemp616 + fTemp615);
			double fTemp617 = (fConst80 * ((fTemp200 + fTemp203) - (fTemp202 + (fTemp201 + fTemp204))));
			double fTemp618 = (fConst81 * fRec676[1]);
			double fTemp619 = (fConst82 * fRec679[1]);
			fRec681[0] = (fTemp617 + (fTemp618 + (fRec681[1] + fTemp619)));
			fRec679[0] = fRec681[0];
			double fRec680 = ((fTemp619 + fTemp618) + fTemp617);
			fRec678[0] = (fRec679[0] + fRec678[1]);
			fRec676[0] = fRec678[0];
			double fRec677 = fRec680;
			fVec9[(IOTA & 127)] = (fTemp132 + (fRec620 + (fRec638 + (fRec653 + (fRec665 + (fRec674 + fRec677))))));
			output9[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec9[((IOTA - iConst83) & 127)])));
			double fTemp620 = (fConst45 * fRec682[1]);
			double fTemp621 = (fConst46 * fRec685[1]);
			double fTemp622 = (fConst48 * fRec688[1]);
			double fTemp623 = (fConst49 * fRec691[1]);
			double fTemp624 = (fConst51 * ((fTemp242 + (fTemp243 + (fTemp241 + (fTemp247 + (fTemp245 + fTemp240))))) - (fTemp249 + (fTemp237 + (fTemp248 + (fTemp238 + (fTemp239 + (fTemp244 + fTemp246))))))));
			double fTemp625 = (fConst52 * fRec694[1]);
			double fTemp626 = (fConst53 * fRec697[1]);
			fRec699[0] = (fTemp624 + (fTemp625 + (fRec699[1] + fTemp626)));
			fRec697[0] = fRec699[0];
			double fRec698 = ((fTemp626 + fTemp625) + fTemp624);
			fRec696[0] = (fRec697[0] + fRec696[1]);
			fRec694[0] = fRec696[0];
			double fRec695 = fRec698;
			fRec693[0] = (fTemp622 + (fTemp623 + (fRec695 + fRec693[1])));
			fRec691[0] = fRec693[0];
			double fRec692 = (fTemp622 + (fRec695 + fTemp623));
			fRec690[0] = (fRec691[0] + fRec690[1]);
			fRec688[0] = fRec690[0];
			double fRec689 = fRec692;
			fRec687[0] = (fTemp620 + (fTemp621 + (fRec689 + fRec687[1])));
			fRec685[0] = fRec687[0];
			double fRec686 = (fTemp620 + (fRec689 + fTemp621));
			fRec684[0] = (fRec685[0] + fRec684[1]);
			fRec682[0] = fRec684[0];
			double fRec683 = fRec686;
			double fTemp627 = (fConst55 * fRec700[1]);
			double fTemp628 = (fConst57 * fRec703[1]);
			double fTemp629 = (fConst58 * fRec706[1]);
			double fTemp630 = (fConst60 * ((fTemp271 + (fTemp275 + (fTemp279 + (fTemp277 + fTemp274)))) - (fTemp270 + (fTemp276 + (fTemp280 + (fTemp272 + (fTemp278 + fTemp273)))))));
			double fTemp631 = (fConst61 * fRec709[1]);
			double fTemp632 = (fConst62 * fRec712[1]);
			fRec714[0] = (fTemp630 + (fTemp631 + (fRec714[1] + fTemp632)));
			fRec712[0] = fRec714[0];
			double fRec713 = ((fTemp632 + fTemp631) + fTemp630);
			fRec711[0] = (fRec712[0] + fRec711[1]);
			fRec709[0] = fRec711[0];
			double fRec710 = fRec713;
			fRec708[0] = (fTemp628 + (fTemp629 + (fRec710 + fRec708[1])));
			fRec706[0] = fRec708[0];
			double fRec707 = (fTemp628 + (fRec710 + fTemp629));
			fRec705[0] = (fRec706[0] + fRec705[1]);
			fRec703[0] = fRec705[0];
			double fRec704 = fRec707;
			fRec702[0] = (fTemp627 + (fRec704 + fRec702[1]));
			fRec700[0] = fRec702[0];
			double fRec701 = (fRec704 + fTemp627);
			double fTemp633 = (fConst64 * fRec715[1]);
			double fTemp634 = (fConst65 * fRec718[1]);
			double fTemp635 = (fConst67 * ((fTemp263 + (fTemp255 + (fTemp257 + (fTemp262 + fTemp259)))) - (fTemp260 + (fTemp256 + (fTemp261 + fTemp258)))));
			double fTemp636 = (fConst68 * fRec721[1]);
			double fTemp637 = (fConst69 * fRec724[1]);
			fRec726[0] = (fTemp635 + (fTemp636 + (fRec726[1] + fTemp637)));
			fRec724[0] = fRec726[0];
			double fRec725 = ((fTemp637 + fTemp636) + fTemp635);
			fRec723[0] = (fRec724[0] + fRec723[1]);
			fRec721[0] = fRec723[0];
			double fRec722 = fRec725;
			fRec720[0] = (fTemp633 + (fTemp634 + (fRec722 + fRec720[1])));
			fRec718[0] = fRec720[0];
			double fRec719 = (fTemp633 + (fRec722 + fTemp634));
			fRec717[0] = (fRec718[0] + fRec717[1]);
			fRec715[0] = fRec717[0];
			double fRec716 = fRec719;
			double fTemp638 = (fConst71 * fRec727[1]);
			double fTemp639 = (fConst73 * ((fTemp226 + (fTemp227 + (fTemp228 + fTemp224))) - (fTemp223 + (fTemp225 + fTemp229))));
			double fTemp640 = (fConst74 * fRec730[1]);
			double fTemp641 = (fConst75 * fRec733[1]);
			fRec735[0] = (fTemp639 + (fTemp640 + (fRec735[1] + fTemp641)));
			fRec733[0] = fRec735[0];
			double fRec734 = ((fTemp641 + fTemp640) + fTemp639);
			fRec732[0] = (fRec733[0] + fRec732[1]);
			fRec730[0] = fRec732[0];
			double fRec731 = fRec734;
			fRec729[0] = (fTemp638 + (fRec731 + fRec729[1]));
			fRec727[0] = fRec729[0];
			double fRec728 = (fRec731 + fTemp638);
			double fTemp642 = (fConst77 * ((fTemp219 + fTemp217) - fTemp218));
			double fTemp643 = (fConst78 * fRec736[1]);
			fRec738[0] = (fTemp642 + (fRec738[1] + fTemp643));
			fRec736[0] = fRec738[0];
			double fRec737 = (fTemp643 + fTemp642);
			double fTemp644 = (fConst80 * ((fTemp212 + fTemp210) - (fTemp209 + (fTemp211 + fTemp213))));
			double fTemp645 = (fConst81 * fRec739[1]);
			double fTemp646 = (fConst82 * fRec742[1]);
			fRec744[0] = (fTemp644 + (fTemp645 + (fRec744[1] + fTemp646)));
			fRec742[0] = fRec744[0];
			double fRec743 = ((fTemp646 + fTemp645) + fTemp644);
			fRec741[0] = (fRec742[0] + fRec741[1]);
			fRec739[0] = fRec741[0];
			double fRec740 = fRec743;
			fVec10[(IOTA & 127)] = (fTemp208 + (fRec683 + (fRec701 + (fRec716 + (fRec728 + (fRec737 + fRec740))))));
			output10[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec10[((IOTA - iConst83) & 127)])));
			double fTemp647 = (fConst107 * fRec745[1]);
			double fTemp648 = (fConst108 * fRec748[1]);
			double fTemp649 = (fConst110 * ((fTemp333 + (fTemp331 + (fTemp329 + (fTemp334 + fTemp336)))) - (fTemp332 + (fTemp330 + fTemp544))));
			double fTemp650 = (fConst111 * fRec751[1]);
			double fTemp651 = (fConst112 * fRec754[1]);
			fRec756[0] = (fTemp649 + (fTemp650 + (fRec756[1] + fTemp651)));
			fRec754[0] = fRec756[0];
			double fRec755 = ((fTemp651 + fTemp650) + fTemp649);
			fRec753[0] = (fRec754[0] + fRec753[1]);
			fRec751[0] = fRec753[0];
			double fRec752 = fRec755;
			fRec750[0] = (fTemp647 + (fTemp648 + (fRec752 + fRec750[1])));
			fRec748[0] = fRec750[0];
			double fRec749 = (fTemp647 + (fRec752 + fTemp648));
			fRec747[0] = (fRec748[0] + fRec747[1]);
			fRec745[0] = fRec747[0];
			double fRec746 = fRec749;
			double fTemp652 = (fConst118 * fRec757[1]);
			double fTemp653 = (fConst120 * ((fTemp351 + (fTemp354 + fTemp353)) - (fTemp352 + (fTemp356 + (fTemp355 + fTemp350)))));
			double fTemp654 = (fConst121 * fRec760[1]);
			double fTemp655 = (fConst122 * fRec763[1]);
			fRec765[0] = (fTemp653 + (fTemp654 + (fRec765[1] + fTemp655)));
			fRec763[0] = fRec765[0];
			double fRec764 = ((fTemp655 + fTemp654) + fTemp653);
			fRec762[0] = (fRec763[0] + fRec762[1]);
			fRec760[0] = fRec762[0];
			double fRec761 = fRec764;
			fRec759[0] = (fTemp652 + (fRec761 + fRec759[1]));
			fRec757[0] = fRec759[0];
			double fRec758 = (fRec761 + fTemp652);
			double fTemp656 = (fConst114 * (fTemp343 - (fTemp345 + (fTemp341 + (fTemp342 + fTemp344)))));
			double fTemp657 = (fConst115 * fRec766[1]);
			double fTemp658 = (fConst116 * fRec769[1]);
			fRec771[0] = (fTemp656 + (fTemp657 + (fRec771[1] + fTemp658)));
			fRec769[0] = fRec771[0];
			double fRec770 = ((fTemp658 + fTemp657) + fTemp656);
			fRec768[0] = (fRec769[0] + fRec768[1]);
			fRec766[0] = fRec768[0];
			double fRec767 = fRec770;
			double fTemp659 = (fConst85 * (fTemp286 - (fTemp287 + fTemp285)));
			double fTemp660 = (fConst86 * fRec772[1]);
			fRec774[0] = (fTemp659 + (fRec774[1] + fTemp660));
			fRec772[0] = fRec774[0];
			double fRec773 = (fTemp660 + fTemp659);
			double fTemp661 = (fConst88 * fRec775[1]);
			double fTemp662 = (fConst89 * fRec778[1]);
			double fTemp663 = (fConst91 * fRec781[1]);
			double fTemp664 = (fConst92 * fRec784[1]);
			double fTemp665 = (fConst94 * ((fTemp303 + (fTemp300 + (fTemp304 + (fTemp299 + (fTemp295 + fTemp297))))) - (fTemp302 + (fTemp306 + (fTemp301 + (fTemp305 + (fTemp294 + (fTemp296 + fTemp298))))))));
			double fTemp666 = (fConst95 * fRec787[1]);
			double fTemp667 = (fConst96 * fRec790[1]);
			fRec792[0] = (fTemp665 + (fTemp666 + (fRec792[1] + fTemp667)));
			fRec790[0] = fRec792[0];
			double fRec791 = ((fTemp667 + fTemp666) + fTemp665);
			fRec789[0] = (fRec790[0] + fRec789[1]);
			fRec787[0] = fRec789[0];
			double fRec788 = fRec791;
			fRec786[0] = (fTemp663 + (fTemp664 + (fRec788 + fRec786[1])));
			fRec784[0] = fRec786[0];
			double fRec785 = (fTemp663 + (fRec788 + fTemp664));
			fRec783[0] = (fRec784[0] + fRec783[1]);
			fRec781[0] = fRec783[0];
			double fRec782 = fRec785;
			fRec780[0] = (fTemp661 + (fTemp662 + (fRec782 + fRec780[1])));
			fRec778[0] = fRec780[0];
			double fRec779 = (fTemp661 + (fRec782 + fTemp662));
			fRec777[0] = (fRec778[0] + fRec777[1]);
			fRec775[0] = fRec777[0];
			double fRec776 = fRec779;
			double fTemp668 = (fConst98 * fRec793[1]);
			double fTemp669 = (fConst100 * fRec796[1]);
			double fTemp670 = (fConst101 * fRec799[1]);
			double fTemp671 = (fConst103 * ((fTemp318 + (fTemp320 + (fTemp323 + (fTemp317 + (fTemp322 + (fTemp314 + fTemp316)))))) - (fTemp319 + (fTemp321 + (fTemp313 + fTemp315)))));
			double fTemp672 = (fConst104 * fRec802[1]);
			double fTemp673 = (fConst105 * fRec805[1]);
			fRec807[0] = (fTemp671 + (fTemp672 + (fRec807[1] + fTemp673)));
			fRec805[0] = fRec807[0];
			double fRec806 = ((fTemp673 + fTemp672) + fTemp671);
			fRec804[0] = (fRec804[1] + fRec805[0]);
			fRec802[0] = fRec804[0];
			double fRec803 = fRec806;
			fRec801[0] = (fTemp669 + (fTemp670 + (fRec803 + fRec801[1])));
			fRec799[0] = fRec801[0];
			double fRec800 = (fTemp669 + (fRec803 + fTemp670));
			fRec798[0] = (fRec799[0] + fRec798[1]);
			fRec796[0] = fRec798[0];
			double fRec797 = fRec800;
			fRec795[0] = (fTemp668 + (fRec797 + fRec795[1]));
			fRec793[0] = fRec795[0];
			double fRec794 = (fRec797 + fTemp668);
			fVec11[(IOTA & 127)] = (fTemp284 + (fRec746 + (fRec758 + (fRec767 + (fRec773 + (fRec776 + fRec794))))));
			output11[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec11[((IOTA - iConst123) & 127)])));
			double fTemp674 = (fConst4 * fRec808[1]);
			double fTemp675 = (fConst5 * fRec811[1]);
			double fTemp676 = (fConst7 * fRec814[1]);
			double fTemp677 = (fConst8 * fRec817[1]);
			double fTemp678 = (fConst10 * ((fTemp36 + (fTemp28 + (fTemp18 + (fTemp369 + (fTemp26 + (fTemp368 + (fTemp22 + fTemp14))))))) - (fTemp367 + (fTemp32 + (fTemp364 + (fTemp366 + fTemp365))))));
			double fTemp679 = (fConst12 * fRec820[1]);
			double fTemp680 = (fConst13 * fRec823[1]);
			fRec825[0] = (fTemp678 + (fTemp679 + (fRec825[1] + fTemp680)));
			fRec823[0] = fRec825[0];
			double fRec824 = ((fTemp680 + fTemp679) + fTemp678);
			fRec822[0] = (fRec823[0] + fRec822[1]);
			fRec820[0] = fRec822[0];
			double fRec821 = fRec824;
			fRec819[0] = (fTemp676 + (fTemp677 + (fRec821 + fRec819[1])));
			fRec817[0] = fRec819[0];
			double fRec818 = (fTemp676 + (fRec821 + fTemp677));
			fRec816[0] = (fRec817[0] + fRec816[1]);
			fRec814[0] = fRec816[0];
			double fRec815 = fRec818;
			fRec813[0] = (fTemp674 + (fTemp675 + (fRec815 + fRec813[1])));
			fRec811[0] = fRec813[0];
			double fRec812 = (fTemp674 + (fRec815 + fTemp675));
			fRec810[0] = (fRec811[0] + fRec810[1]);
			fRec808[0] = fRec810[0];
			double fRec809 = fRec812;
			double fTemp681 = (fConst15 * fRec826[1]);
			double fTemp682 = (fConst17 * fRec829[1]);
			double fTemp683 = (fConst18 * fRec832[1]);
			double fTemp684 = (fConst20 * ((fTemp58 + (fTemp50 + (fTemp381 + (fTemp56 + (fTemp46 + fTemp380))))) - (fTemp376 + (fTemp62 + (fTemp377 + (fTemp379 + fTemp378))))));
			double fTemp685 = (fConst21 * fRec835[1]);
			double fTemp686 = (fConst22 * fRec838[1]);
			fRec840[0] = (fTemp684 + (fTemp685 + (fRec840[1] + fTemp686)));
			fRec838[0] = fRec840[0];
			double fRec839 = ((fTemp686 + fTemp685) + fTemp684);
			fRec837[0] = (fRec838[0] + fRec837[1]);
			fRec835[0] = fRec837[0];
			double fRec836 = fRec839;
			fRec834[0] = (fTemp682 + (fTemp683 + (fRec836 + fRec834[1])));
			fRec832[0] = fRec834[0];
			double fRec833 = (fTemp682 + (fRec836 + fTemp683));
			fRec831[0] = (fRec832[0] + fRec831[1]);
			fRec829[0] = fRec831[0];
			double fRec830 = fRec833;
			fRec828[0] = (fTemp681 + (fRec830 + fRec828[1]));
			fRec826[0] = fRec828[0];
			double fRec827 = (fRec830 + fTemp681);
			double fTemp687 = (fConst29 * fRec841[1]);
			double fTemp688 = (fConst28 * fRec844[1]);
			double fTemp689 = (fConst25 * ((fTemp85 + (fTemp388 + (fTemp73 + (fTemp79 + (fTemp389 + (fTemp69 + fTemp390)))))) - (fTemp77 + fTemp387)));
			double fTemp690 = (fConst27 * fRec847[1]);
			double fTemp691 = (fConst26 * fRec850[1]);
			fRec852[0] = (fTemp689 + (fTemp690 + (fRec852[1] + fTemp691)));
			fRec850[0] = fRec852[0];
			double fRec851 = ((fTemp691 + fTemp690) + fTemp689);
			fRec849[0] = (fRec850[0] + fRec849[1]);
			fRec847[0] = fRec849[0];
			double fRec848 = fRec851;
			fRec846[0] = (fTemp687 + (fTemp688 + (fRec848 + fRec846[1])));
			fRec844[0] = fRec846[0];
			double fRec845 = (fTemp687 + (fRec848 + fTemp688));
			fRec843[0] = (fRec844[0] + fRec843[1]);
			fRec841[0] = fRec843[0];
			double fRec842 = fRec845;
			double fTemp692 = (fConst31 * fRec853[1]);
			double fTemp693 = (fConst33 * ((fTemp396 + (fTemp398 + fTemp397)) - (fTemp97 + (fTemp101 + (fTemp95 + fTemp395)))));
			double fTemp694 = (fConst34 * fRec856[1]);
			double fTemp695 = (fConst35 * fRec859[1]);
			fRec861[0] = (fTemp693 + (fTemp694 + (fRec861[1] + fTemp695)));
			fRec859[0] = fRec861[0];
			double fRec860 = ((fTemp695 + fTemp694) + fTemp693);
			fRec858[0] = (fRec859[0] + fRec858[1]);
			fRec856[0] = fRec858[0];
			double fRec857 = fRec860;
			fRec855[0] = (fTemp692 + (fRec857 + fRec855[1]));
			fRec853[0] = fRec855[0];
			double fRec854 = (fRec857 + fTemp692);
			double fTemp696 = (fConst37 * (fTemp403 - (fTemp114 + fTemp402)));
			double fTemp697 = (fConst38 * fRec862[1]);
			fRec864[0] = (fTemp696 + (fRec864[1] + fTemp697));
			fRec862[0] = fRec864[0];
			double fRec863 = (fTemp697 + fTemp696);
			double fTemp698 = (fConst40 * (fTemp407 - (fTemp124 + (fTemp406 + (fTemp118 + fTemp126)))));
			double fTemp699 = (fConst41 * fRec865[1]);
			double fTemp700 = (fConst42 * fRec868[1]);
			fRec870[0] = (fTemp698 + (fTemp699 + (fRec870[1] + fTemp700)));
			fRec868[0] = fRec870[0];
			double fRec869 = ((fTemp700 + fTemp699) + fTemp698);
			fRec867[0] = (fRec868[0] + fRec867[1]);
			fRec865[0] = fRec867[0];
			double fRec866 = fRec869;
			fVec12[(IOTA & 127)] = (fTemp131 + (fRec809 + (fRec827 + (fRec842 + (fRec854 + (fRec863 + fRec866))))));
			output12[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec12[((IOTA - iConst43) & 127)])));
			double fTemp701 = (fConst45 * fRec871[1]);
			double fTemp702 = (fConst46 * fRec874[1]);
			double fTemp703 = (fConst48 * fRec877[1]);
			double fTemp704 = (fConst49 * fRec880[1]);
			double fTemp705 = (fConst51 * ((fTemp145 + (fTemp149 + (fTemp140 + (fTemp418 + (fTemp419 + fTemp420))))) - (fTemp137 + (fTemp415 + (fTemp416 + (fTemp417 + (fTemp144 + (fTemp142 + fTemp147))))))));
			double fTemp706 = (fConst52 * fRec883[1]);
			double fTemp707 = (fConst53 * fRec886[1]);
			fRec888[0] = (fTemp705 + (fTemp706 + (fRec888[1] + fTemp707)));
			fRec886[0] = fRec888[0];
			double fRec887 = ((fTemp707 + fTemp706) + fTemp705);
			fRec885[0] = (fRec886[0] + fRec885[1]);
			fRec883[0] = fRec885[0];
			double fRec884 = fRec887;
			fRec882[0] = (fTemp703 + (fTemp704 + (fRec884 + fRec882[1])));
			fRec880[0] = fRec882[0];
			double fRec881 = (fTemp703 + (fRec884 + fTemp704));
			fRec879[0] = (fRec880[0] + fRec879[1]);
			fRec877[0] = fRec879[0];
			double fRec878 = fRec881;
			fRec876[0] = (fTemp701 + (fTemp702 + (fRec878 + fRec876[1])));
			fRec874[0] = fRec876[0];
			double fRec875 = (fTemp701 + (fRec878 + fTemp702));
			fRec873[0] = (fRec874[0] + fRec873[1]);
			fRec871[0] = fRec873[0];
			double fRec872 = fRec875;
			double fTemp708 = (fConst55 * fRec889[1]);
			double fTemp709 = (fConst57 * fRec892[1]);
			double fTemp710 = (fConst58 * fRec895[1]);
			double fTemp711 = (fConst60 * ((fTemp162 + (fTemp166 + (fTemp158 + (fTemp430 + (fTemp431 + fTemp432))))) - (fTemp427 + (fTemp428 + (fTemp429 + (fTemp164 + fTemp160))))));
			double fTemp712 = (fConst61 * fRec898[1]);
			double fTemp713 = (fConst62 * fRec901[1]);
			fRec903[0] = (fTemp711 + (fTemp712 + (fRec903[1] + fTemp713)));
			fRec901[0] = fRec903[0];
			double fRec902 = ((fTemp713 + fTemp712) + fTemp711);
			fRec900[0] = (fRec901[0] + fRec900[1]);
			fRec898[0] = fRec900[0];
			double fRec899 = fRec902;
			fRec897[0] = (fTemp709 + (fTemp710 + (fRec899 + fRec897[1])));
			fRec895[0] = fRec897[0];
			double fRec896 = (fTemp709 + (fRec899 + fTemp710));
			fRec894[0] = (fRec895[0] + fRec894[1]);
			fRec892[0] = fRec894[0];
			double fRec893 = fRec896;
			fRec891[0] = (fTemp708 + (fRec893 + fRec891[1]));
			fRec889[0] = fRec891[0];
			double fRec890 = (fRec893 + fTemp708);
			double fTemp714 = (fConst64 * fRec904[1]);
			double fTemp715 = (fConst65 * fRec907[1]);
			double fTemp716 = (fConst67 * ((fTemp178 + (fTemp172 + fTemp607)) - (fTemp438 + (fTemp439 + (fTemp174 + (fTemp440 + fTemp441))))));
			double fTemp717 = (fConst68 * fRec910[1]);
			double fTemp718 = (fConst69 * fRec913[1]);
			fRec915[0] = (fTemp716 + (fTemp717 + (fRec915[1] + fTemp718)));
			fRec913[0] = fRec915[0];
			double fRec914 = ((fTemp718 + fTemp717) + fTemp716);
			fRec912[0] = (fRec913[0] + fRec912[1]);
			fRec910[0] = fRec912[0];
			double fRec911 = fRec914;
			fRec909[0] = (fTemp714 + (fTemp715 + (fRec911 + fRec909[1])));
			fRec907[0] = fRec909[0];
			double fRec908 = (fTemp714 + (fRec911 + fTemp715));
			fRec906[0] = (fRec907[0] + fRec906[1]);
			fRec904[0] = fRec906[0];
			double fRec905 = fRec908;
			double fTemp719 = (fConst71 * fRec916[1]);
			double fTemp720 = (fConst73 * (fTemp449 - (fTemp189 + (fTemp448 + (fTemp190 + (fTemp447 + (fTemp187 + fTemp446)))))));
			double fTemp721 = (fConst74 * fRec919[1]);
			double fTemp722 = (fConst75 * fRec922[1]);
			fRec924[0] = (fTemp720 + (fTemp721 + (fRec924[1] + fTemp722)));
			fRec922[0] = fRec924[0];
			double fRec923 = ((fTemp722 + fTemp721) + fTemp720);
			fRec921[0] = (fRec922[0] + fRec921[1]);
			fRec919[0] = fRec921[0];
			double fRec920 = fRec923;
			fRec918[0] = (fTemp719 + (fRec920 + fRec918[1]));
			fRec916[0] = fRec918[0];
			double fRec917 = (fRec920 + fTemp719);
			double fTemp723 = (fConst77 * ((fTemp196 + fTemp454) - fTemp453));
			double fTemp724 = (fConst78 * fRec925[1]);
			fRec927[0] = (fTemp723 + (fRec927[1] + fTemp724));
			fRec925[0] = fRec927[0];
			double fRec926 = (fTemp724 + fTemp723);
			double fTemp725 = (fConst80 * (fTemp458 - (fTemp203 + (fTemp457 + (fTemp200 + fTemp204)))));
			double fTemp726 = (fConst81 * fRec928[1]);
			double fTemp727 = (fConst82 * fRec931[1]);
			fRec933[0] = (fTemp725 + (fTemp726 + (fRec933[1] + fTemp727)));
			fRec931[0] = fRec933[0];
			double fRec932 = ((fTemp727 + fTemp726) + fTemp725);
			fRec930[0] = (fRec931[0] + fRec930[1]);
			fRec928[0] = fRec930[0];
			double fRec929 = fRec932;
			fVec13[(IOTA & 127)] = (fTemp132 + (fRec872 + (fRec890 + (fRec905 + (fRec917 + (fRec926 + fRec929))))));
			output13[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec13[((IOTA - iConst83) & 127)])));
			double fTemp728 = (fConst45 * fRec934[1]);
			double fTemp729 = (fConst46 * fRec937[1]);
			double fTemp730 = (fConst48 * fRec940[1]);
			double fTemp731 = (fConst49 * fRec943[1]);
			double fTemp732 = (fConst51 * ((fTemp249 + (fTemp466 + (fTemp242 + (fTemp467 + (fTemp248 + (fTemp468 + (fTemp241 + (fTemp469 + (fTemp471 + (fTemp244 + fTemp470)))))))))) - (fTemp246 + fTemp240)));
			double fTemp733 = (fConst52 * fRec946[1]);
			double fTemp734 = (fConst53 * fRec949[1]);
			fRec951[0] = (fTemp732 + (fTemp733 + (fRec951[1] + fTemp734)));
			fRec949[0] = fRec951[0];
			double fRec950 = ((fTemp734 + fTemp733) + fTemp732);
			fRec948[0] = (fRec949[0] + fRec948[1]);
			fRec946[0] = fRec948[0];
			double fRec947 = fRec950;
			fRec945[0] = (fTemp730 + (fTemp731 + (fRec947 + fRec945[1])));
			fRec943[0] = fRec945[0];
			double fRec944 = (fTemp730 + (fRec947 + fTemp731));
			fRec942[0] = (fRec943[0] + fRec942[1]);
			fRec940[0] = fRec942[0];
			double fRec941 = fRec944;
			fRec939[0] = (fTemp728 + (fTemp729 + (fRec941 + fRec939[1])));
			fRec937[0] = fRec939[0];
			double fRec938 = (fTemp728 + (fRec941 + fTemp729));
			fRec936[0] = (fRec937[0] + fRec936[1]);
			fRec934[0] = fRec936[0];
			double fRec935 = fRec938;
			double fTemp735 = (fConst64 * fRec952[1]);
			double fTemp736 = (fConst65 * fRec955[1]);
			double fTemp737 = (fConst67 * ((fTemp260 + (fTemp255 + fTemp259)) - (fTemp489 + (fTemp490 + (fTemp257 + (fTemp491 + (fTemp261 + fTemp492)))))));
			double fTemp738 = (fConst68 * fRec958[1]);
			double fTemp739 = (fConst69 * fRec961[1]);
			fRec963[0] = (fTemp737 + (fTemp738 + (fRec963[1] + fTemp739)));
			fRec961[0] = fRec963[0];
			double fRec962 = ((fTemp739 + fTemp738) + fTemp737);
			fRec960[0] = (fRec961[0] + fRec960[1]);
			fRec958[0] = fRec960[0];
			double fRec959 = fRec962;
			fRec957[0] = (fTemp735 + (fTemp736 + (fRec959 + fRec957[1])));
			fRec955[0] = fRec957[0];
			double fRec956 = (fTemp735 + (fRec959 + fTemp736));
			fRec954[0] = (fRec955[0] + fRec954[1]);
			fRec952[0] = fRec954[0];
			double fRec953 = fRec956;
			double fTemp740 = (fConst71 * fRec964[1]);
			double fTemp741 = (fConst73 * (0.0 - (fTemp500 + (fTemp226 + (fTemp499 + (fTemp229 + (fTemp498 + (fTemp224 + fTemp497))))))));
			double fTemp742 = (fConst74 * fRec967[1]);
			double fTemp743 = (fConst75 * fRec970[1]);
			fRec972[0] = (fTemp741 + (fTemp742 + (fRec972[1] + fTemp743)));
			fRec970[0] = fRec972[0];
			double fRec971 = ((fTemp743 + fTemp742) + fTemp741);
			fRec969[0] = (fRec970[0] + fRec969[1]);
			fRec967[0] = fRec969[0];
			double fRec968 = fRec971;
			fRec966[0] = (fTemp740 + (fRec968 + fRec966[1]));
			fRec964[0] = fRec966[0];
			double fRec965 = (fRec968 + fTemp740);
			double fTemp744 = (fConst77 * (fTemp505 + (fTemp217 + fTemp504)));
			double fTemp745 = (fConst78 * fRec973[1]);
			fRec975[0] = (fTemp744 + (fRec975[1] + fTemp745));
			fRec973[0] = fRec975[0];
			double fRec974 = (fTemp745 + fTemp744);
			double fTemp746 = (fConst80 * ((fTemp509 + (fTemp211 + fTemp508)) - (fTemp213 + fTemp210)));
			double fTemp747 = (fConst81 * fRec976[1]);
			double fTemp748 = (fConst82 * fRec979[1]);
			fRec981[0] = (fTemp746 + (fTemp747 + (fRec981[1] + fTemp748)));
			fRec979[0] = fRec981[0];
			double fRec980 = ((fTemp748 + fTemp747) + fTemp746);
			fRec978[0] = (fRec979[0] + fRec978[1]);
			fRec976[0] = fRec978[0];
			double fRec977 = fRec980;
			double fTemp749 = (fConst55 * fRec982[1]);
			double fTemp750 = (fConst57 * fRec985[1]);
			double fTemp751 = (fConst58 * fRec988[1]);
			double fTemp752 = (fConst60 * ((fTemp479 + (fTemp271 + (fTemp483 + (fTemp280 + (fTemp480 + (fTemp275 + (fTemp482 + fTemp481))))))) - (fTemp274 + (fTemp278 + fTemp478))));
			double fTemp753 = (fConst61 * fRec991[1]);
			double fTemp754 = (fConst62 * fRec994[1]);
			fRec996[0] = (fTemp752 + (fTemp753 + (fRec996[1] + fTemp754)));
			fRec994[0] = fRec996[0];
			double fRec995 = ((fTemp754 + fTemp753) + fTemp752);
			fRec993[0] = (fRec993[1] + fRec994[0]);
			fRec991[0] = fRec993[0];
			double fRec992 = fRec995;
			fRec990[0] = ((fTemp750 + (fRec990[1] + fTemp751)) + fRec992);
			fRec988[0] = fRec990[0];
			double fRec989 = ((fTemp751 + fTemp750) + fRec992);
			fRec987[0] = (fRec987[1] + fRec988[0]);
			fRec985[0] = fRec987[0];
			double fRec986 = fRec989;
			fRec984[0] = ((fRec984[1] + fTemp749) + fRec986);
			fRec982[0] = fRec984[0];
			double fRec983 = (fTemp749 + fRec986);
			fVec14[(IOTA & 127)] = ((fTemp208 + (fRec935 + (fRec953 + (fRec965 + (fRec974 + fRec977))))) + fRec983);
			output14[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec14[((IOTA - iConst83) & 127)])));
			double fTemp755 = (fConst88 * fRec997[1]);
			double fTemp756 = (fConst89 * fRec1000[1]);
			double fTemp757 = (fConst91 * fRec1003[1]);
			double fTemp758 = (fConst92 * fRec1006[1]);
			double fTemp759 = (fConst94 * ((fTemp302 + (fTemp522 + (fTemp305 + (fTemp520 + (fTemp300 + (fTemp297 + fTemp521)))))) - (fTemp519 + (fTemp306 + (fTemp299 + (fTemp518 + (fTemp295 + fTemp517)))))));
			double fTemp760 = (fConst95 * fRec1009[1]);
			double fTemp761 = (fConst96 * fRec1012[1]);
			fRec1014[0] = (fTemp759 + (fTemp760 + (fRec1014[1] + fTemp761)));
			fRec1012[0] = fRec1014[0];
			double fRec1013 = ((fTemp761 + fTemp760) + fTemp759);
			fRec1011[0] = (fRec1012[0] + fRec1011[1]);
			fRec1009[0] = fRec1011[0];
			double fRec1010 = fRec1013;
			fRec1008[0] = (fTemp757 + (fTemp758 + (fRec1010 + fRec1008[1])));
			fRec1006[0] = fRec1008[0];
			double fRec1007 = (fTemp757 + (fRec1010 + fTemp758));
			fRec1005[0] = (fRec1006[0] + fRec1005[1]);
			fRec1003[0] = fRec1005[0];
			double fRec1004 = fRec1007;
			fRec1002[0] = (fTemp755 + (fTemp756 + (fRec1004 + fRec1002[1])));
			fRec1000[0] = fRec1002[0];
			double fRec1001 = (fTemp755 + (fRec1004 + fTemp756));
			fRec999[0] = (fRec1000[0] + fRec999[1]);
			fRec997[0] = fRec999[0];
			double fRec998 = fRec1001;
			double fTemp762 = (fConst98 * fRec1015[1]);
			double fTemp763 = (fConst100 * fRec1018[1]);
			double fTemp764 = (fConst101 * fRec1021[1]);
			double fTemp765 = (fConst103 * ((fTemp534 + (fTemp321 + (fTemp533 + (fTemp317 + (fTemp314 + fTemp532))))) - (fTemp531 + (fTemp319 + (fTemp530 + (fTemp316 + fTemp529))))));
			double fTemp766 = (fConst104 * fRec1024[1]);
			double fTemp767 = (fConst105 * fRec1027[1]);
			fRec1029[0] = (fTemp765 + (fTemp766 + (fRec1029[1] + fTemp767)));
			fRec1027[0] = fRec1029[0];
			double fRec1028 = ((fTemp767 + fTemp766) + fTemp765);
			fRec1026[0] = (fRec1027[0] + fRec1026[1]);
			fRec1024[0] = fRec1026[0];
			double fRec1025 = fRec1028;
			fRec1023[0] = (fTemp763 + (fTemp764 + (fRec1025 + fRec1023[1])));
			fRec1021[0] = fRec1023[0];
			double fRec1022 = (fTemp763 + (fRec1025 + fTemp764));
			fRec1020[0] = (fRec1021[0] + fRec1020[1]);
			fRec1018[0] = fRec1020[0];
			double fRec1019 = fRec1022;
			fRec1017[0] = (fTemp762 + (fRec1019 + fRec1017[1]));
			fRec1015[0] = fRec1017[0];
			double fRec1016 = (fRec1019 + fTemp762);
			double fTemp768 = (fConst107 * fRec1030[1]);
			double fTemp769 = (fConst108 * fRec1033[1]);
			double fTemp770 = (fConst110 * ((fTemp332 + (fTemp331 + fTemp543)) - (fTemp540 + (fTemp541 + (fTemp329 + (fTemp335 + (fTemp337 + fTemp542)))))));
			double fTemp771 = (fConst111 * fRec1036[1]);
			double fTemp772 = (fConst112 * fRec1039[1]);
			fRec1041[0] = (fTemp770 + (fTemp771 + (fRec1041[1] + fTemp772)));
			fRec1039[0] = fRec1041[0];
			double fRec1040 = ((fTemp772 + fTemp771) + fTemp770);
			fRec1038[0] = (fRec1039[0] + fRec1038[1]);
			fRec1036[0] = fRec1038[0];
			double fRec1037 = fRec1040;
			fRec1035[0] = (fTemp768 + (fTemp769 + (fRec1037 + fRec1035[1])));
			fRec1033[0] = fRec1035[0];
			double fRec1034 = (fTemp768 + (fRec1037 + fTemp769));
			fRec1032[0] = (fRec1033[0] + fRec1032[1]);
			fRec1030[0] = fRec1032[0];
			double fRec1031 = fRec1034;
			double fTemp773 = (fConst118 * fRec1042[1]);
			double fTemp774 = (fConst120 * ((fTemp352 + (fTemp355 + fTemp552)) - (fTemp549 + (fTemp551 + (fTemp356 + fTemp550)))));
			double fTemp775 = (fConst121 * fRec1045[1]);
			double fTemp776 = (fConst122 * fRec1048[1]);
			fRec1050[0] = (fTemp774 + (fTemp775 + (fRec1050[1] + fTemp776)));
			fRec1048[0] = fRec1050[0];
			double fRec1049 = ((fTemp776 + fTemp775) + fTemp774);
			fRec1047[0] = (fRec1048[0] + fRec1047[1]);
			fRec1045[0] = fRec1047[0];
			double fRec1046 = fRec1049;
			fRec1044[0] = (fTemp773 + (fRec1046 + fRec1044[1]));
			fRec1042[0] = fRec1044[0];
			double fRec1043 = (fRec1046 + fTemp773);
			double fTemp777 = (fConst85 * ((fTemp556 + fTemp557) - fTemp287));
			double fTemp778 = (fConst86 * fRec1051[1]);
			fRec1053[0] = (fTemp777 + (fRec1053[1] + fTemp778));
			fRec1051[0] = fRec1053[0];
			double fRec1052 = (fTemp778 + fTemp777);
			double fTemp779 = (fConst114 * ((fTemp345 + (fTemp561 + (fTemp342 + fTemp560))) - fTemp344));
			double fTemp780 = (fConst115 * fRec1054[1]);
			double fTemp781 = (fConst116 * fRec1057[1]);
			fRec1059[0] = (fTemp779 + (fTemp780 + (fRec1059[1] + fTemp781)));
			fRec1057[0] = fRec1059[0];
			double fRec1058 = ((fTemp781 + fTemp780) + fTemp779);
			fRec1056[0] = (fRec1057[0] + fRec1056[1]);
			fRec1054[0] = fRec1056[0];
			double fRec1055 = fRec1058;
			fVec15[(IOTA & 127)] = (fTemp284 + (fRec998 + (fRec1016 + (fRec1031 + (fRec1043 + (fRec1052 + fRec1055))))));
			output15[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec15[((IOTA - iConst123) & 127)])));
			double fTemp782 = (0.0263545219 * fTemp130);
			double fTemp783 = (fConst125 * fRec1060[1]);
			double fTemp784 = (fConst126 * fRec1063[1]);
			double fTemp785 = (fConst128 * fRec1066[1]);
			double fTemp786 = (fConst129 * fRec1069[1]);
			double fTemp787 = (0.0037928382999999999 * fTemp21);
			double fTemp788 = (0.0012228918000000001 * fTemp23);
			double fTemp789 = (0.0103914222 * fTemp25);
			double fTemp790 = (0.0030139182 * fTemp35);
			double fTemp791 = (0.001108384 * fTemp33);
			double fTemp792 = (0.034566168100000003 * fTemp31);
			double fTemp793 = (0.1456857278 * fTemp29);
			double fTemp794 = (0.059366557899999998 * fTemp27);
			double fTemp795 = (0.061708738999999999 * fTemp19);
			double fTemp796 = (0.0054838350999999999 * fTemp17);
			double fTemp797 = (0.00054961490000000001 * fTemp11);
			double fTemp798 = (0.0696277862 * fTemp13);
			double fTemp799 = (0.0754730438 * fTemp15);
			double fTemp800 = (fConst131 * ((((fTemp787 + fTemp788) + fTemp789) + fTemp790) - (fTemp791 + (fTemp792 + (fTemp793 + (fTemp794 + (fTemp795 + (fTemp796 + ((fTemp797 + fTemp798) + fTemp799)))))))));
			double fTemp801 = (fConst132 * fRec1072[1]);
			double fTemp802 = (fConst133 * fRec1075[1]);
			fRec1077[0] = (fTemp800 + (fTemp801 + (fRec1077[1] + fTemp802)));
			fRec1075[0] = fRec1077[0];
			double fRec1076 = ((fTemp802 + fTemp801) + fTemp800);
			fRec1074[0] = (fRec1075[0] + fRec1074[1]);
			fRec1072[0] = fRec1074[0];
			double fRec1073 = fRec1076;
			fRec1071[0] = (fTemp785 + (fTemp786 + (fRec1073 + fRec1071[1])));
			fRec1069[0] = fRec1071[0];
			double fRec1070 = (fTemp785 + (fRec1073 + fTemp786));
			fRec1068[0] = (fRec1069[0] + fRec1068[1]);
			fRec1066[0] = fRec1068[0];
			double fRec1067 = fRec1070;
			fRec1065[0] = (fTemp783 + (fTemp784 + (fRec1067 + fRec1065[1])));
			fRec1063[0] = fRec1065[0];
			double fRec1064 = (fTemp783 + (fRec1067 + fTemp784));
			fRec1062[0] = (fRec1063[0] + fRec1062[1]);
			fRec1060[0] = fRec1062[0];
			double fRec1061 = fRec1064;
			double fTemp803 = (fConst135 * fRec1078[1]);
			double fTemp804 = (fConst137 * fRec1081[1]);
			double fTemp805 = (fConst138 * fRec1084[1]);
			double fTemp806 = (0.00019176140000000001 * fTemp43);
			double fTemp807 = (0.0014505162000000001 * fTemp53);
			double fTemp808 = (0.075928962399999994 * fTemp55);
			double fTemp809 = (0.00042021320000000002 * fTemp63);
			double fTemp810 = (0.035811555299999999 * fTemp61);
			double fTemp811 = (0.17784278810000001 * fTemp59);
			double fTemp812 = (0.1131292969 * fTemp57);
			double fTemp813 = (0.059842723200000003 * fTemp51);
			double fTemp814 = (0.070633483299999994 * fTemp45);
			double fTemp815 = (0.056085061200000001 * fTemp47);
			double fTemp816 = (0.049352419299999999 * fTemp49);
			double fTemp817 = (fConst140 * ((((fTemp806 + fTemp807) + fTemp808) + fTemp809) - (fTemp810 + (fTemp811 + (fTemp812 + (fTemp813 + ((fTemp814 + fTemp815) + fTemp816)))))));
			double fTemp818 = (fConst141 * fRec1087[1]);
			double fTemp819 = (fConst142 * fRec1090[1]);
			fRec1092[0] = (fTemp817 + (fTemp818 + (fRec1092[1] + fTemp819)));
			fRec1090[0] = fRec1092[0];
			double fRec1091 = ((fTemp819 + fTemp818) + fTemp817);
			fRec1089[0] = (fRec1090[0] + fRec1089[1]);
			fRec1087[0] = fRec1089[0];
			double fRec1088 = fRec1091;
			fRec1086[0] = (fTemp804 + (fTemp805 + (fRec1088 + fRec1086[1])));
			fRec1084[0] = fRec1086[0];
			double fRec1085 = (fTemp804 + (fRec1088 + fTemp805));
			fRec1083[0] = (fRec1084[0] + fRec1083[1]);
			fRec1081[0] = fRec1083[0];
			double fRec1082 = fRec1085;
			fRec1080[0] = (fTemp803 + (fRec1082 + fRec1080[1]));
			fRec1078[0] = fRec1080[0];
			double fRec1079 = (fRec1082 + fTemp803);
			double fTemp820 = (fConst144 * fRec1093[1]);
			double fTemp821 = (fConst145 * fRec1096[1]);
			double fTemp822 = (0.001136186 * fTemp70);
			double fTemp823 = (0.1384299205 * fTemp78);
			double fTemp824 = (0.025367565799999998 * fTemp80);
			double fTemp825 = (0.12642364289999999 * fTemp84);
			double fTemp826 = (0.0149837431 * fTemp82);
			double fTemp827 = (0.0802402807 * fTemp72);
			double fTemp828 = (0.020582636299999998 * fTemp68);
			double fTemp829 = (0.1380383265 * fTemp74);
			double fTemp830 = (0.0115010066 * fTemp76);
			double fTemp831 = (fConst147 * (((fTemp822 + fTemp823) + fTemp824) - (fTemp825 + (fTemp826 + (fTemp827 + (fTemp828 + (fTemp829 + fTemp830)))))));
			double fTemp832 = (fConst148 * fRec1099[1]);
			double fTemp833 = (fConst149 * fRec1102[1]);
			fRec1104[0] = (fTemp831 + (fTemp832 + (fRec1104[1] + fTemp833)));
			fRec1102[0] = fRec1104[0];
			double fRec1103 = ((fTemp833 + fTemp832) + fTemp831);
			fRec1101[0] = (fRec1102[0] + fRec1101[1]);
			fRec1099[0] = fRec1101[0];
			double fRec1100 = fRec1103;
			fRec1098[0] = (fTemp820 + (fTemp821 + (fRec1100 + fRec1098[1])));
			fRec1096[0] = fRec1098[0];
			double fRec1097 = (fTemp820 + (fRec1100 + fTemp821));
			fRec1095[0] = (fRec1096[0] + fRec1095[1]);
			fRec1093[0] = fRec1095[0];
			double fRec1094 = fRec1097;
			double fTemp834 = (fConst151 * fRec1105[1]);
			double fTemp835 = (0.00054882010000000003 * fTemp92);
			double fTemp836 = (0.1249579864 * fTemp94);
			double fTemp837 = (0.096633864700000002 * fTemp98);
			double fTemp838 = (0.030199994399999999 * fTemp102);
			double fTemp839 = (0.071812713700000003 * fTemp104);
			double fTemp840 = (0.043869722600000001 * fTemp100);
			double fTemp841 = (0.098212255900000003 * fTemp96);
			double fTemp842 = (fConst153 * ((((fTemp835 + fTemp836) + fTemp837) + fTemp838) - (fTemp839 + (fTemp840 + fTemp841))));
			double fTemp843 = (fConst154 * fRec1108[1]);
			double fTemp844 = (fConst155 * fRec1111[1]);
			fRec1113[0] = (fTemp842 + (fTemp843 + (fRec1113[1] + fTemp844)));
			fRec1111[0] = fRec1113[0];
			double fRec1112 = ((fTemp844 + fTemp843) + fTemp842);
			fRec1110[0] = (fRec1111[0] + fRec1110[1]);
			fRec1108[0] = fRec1110[0];
			double fRec1109 = fRec1112;
			fRec1107[0] = (fTemp834 + (fRec1109 + fRec1107[1]));
			fRec1105[0] = fRec1107[0];
			double fRec1106 = (fRec1109 + fTemp834);
			double fTemp845 = (0.057712014899999997 * fTemp109);
			double fTemp846 = (0.055700226999999998 * fTemp113);
			double fTemp847 = (0.026868948399999999 * fTemp111);
			double fTemp848 = (fConst157 * ((fTemp845 + fTemp846) + fTemp847));
			double fTemp849 = (fConst158 * fRec1114[1]);
			fRec1116[0] = (fTemp848 + (fRec1116[1] + fTemp849));
			fRec1114[0] = fRec1116[0];
			double fRec1115 = (fTemp849 + fTemp848);
			double fTemp850 = (0.056535032700000001 * fTemp117);
			double fTemp851 = (0.10618482379999999 * fTemp119);
			double fTemp852 = (0.026209049700000001 * fTemp125);
			double fTemp853 = (0.044765766899999997 * fTemp121);
			double fTemp854 = (0.049067284199999998 * fTemp123);
			double fTemp855 = (fConst160 * ((((fTemp850 + fTemp851) + fTemp852) + fTemp853) - fTemp854));
			double fTemp856 = (fConst161 * fRec1117[1]);
			double fTemp857 = (fConst162 * fRec1120[1]);
			fRec1122[0] = (fTemp855 + (fTemp856 + (fRec1122[1] + fTemp857)));
			fRec1120[0] = fRec1122[0];
			double fRec1121 = ((fTemp857 + fTemp856) + fTemp855);
			fRec1119[0] = (fRec1120[0] + fRec1119[1]);
			fRec1117[0] = fRec1119[0];
			double fRec1118 = fRec1121;
			fVec16[(IOTA & 127)] = (fTemp782 + (fRec1061 + (fRec1079 + (fRec1094 + (fRec1106 + (fRec1115 + fRec1118))))));
			output16[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec16[((IOTA - iConst163) & 127)])));
			double fTemp858 = (0.040905947400000003 * fTemp31);
			double fTemp859 = (0.1035695636 * fTemp29);
			double fTemp860 = (0.0066786655999999996 * fTemp21);
			double fTemp861 = (0.064280962900000002 * fTemp13);
			double fTemp862 = (0.10265550900000001 * fTemp23);
			double fTemp863 = (0.0082169123000000004 * fTemp27);
			double fTemp864 = (0.0053378482999999997 * fTemp35);
			double fTemp865 = (0.10666509489999999 * fTemp19);
			double fTemp866 = (0.0032348451000000001 * fTemp17);
			double fTemp867 = (0.0444305246 * fTemp15);
			double fTemp868 = (0.00078339200000000005 * fTemp11);
			double fTemp869 = (0.048870159199999999 * fTemp25);
			double fTemp870 = (0.00017135039999999999 * fTemp33);
			double fTemp871 = ((fConst132 * fRec1135[1]) + (fConst131 * (((fTemp858 + (fTemp859 + (((fTemp860 + fTemp861) + fTemp862) + fTemp863))) + fTemp864) - ((fTemp865 + (fTemp866 + (fTemp867 + (fTemp868 + fTemp869)))) + fTemp870))));
			double fTemp872 = (fConst133 * fRec1138[1]);
			fRec1140[0] = ((fTemp871 + fRec1140[1]) + fTemp872);
			fRec1138[0] = fRec1140[0];
			double fRec1139 = (fTemp871 + fTemp872);
			fRec1137[0] = (fRec1138[0] + fRec1137[1]);
			fRec1135[0] = fRec1137[0];
			double fRec1136 = fRec1139;
			double fTemp873 = (fConst129 * fRec1132[1]);
			double fTemp874 = (fConst128 * fRec1129[1]);
			fRec1134[0] = (((fRec1136 + fRec1134[1]) + fTemp873) + fTemp874);
			fRec1132[0] = fRec1134[0];
			double fRec1133 = ((fRec1136 + fTemp873) + fTemp874);
			fRec1131[0] = (fRec1132[0] + fRec1131[1]);
			fRec1129[0] = fRec1131[0];
			double fRec1130 = fRec1133;
			double fTemp875 = (fConst126 * fRec1126[1]);
			double fTemp876 = (fConst125 * fRec1123[1]);
			fRec1128[0] = (((fRec1130 + fRec1128[1]) + fTemp875) + fTemp876);
			fRec1126[0] = fRec1128[0];
			double fRec1127 = ((fRec1130 + fTemp875) + fTemp876);
			fRec1125[0] = (fRec1126[0] + fRec1125[1]);
			fRec1123[0] = fRec1125[0];
			double fRec1124 = fRec1127;
			double fTemp877 = (fConst135 * fRec1141[1]);
			double fTemp878 = (fConst137 * fRec1144[1]);
			double fTemp879 = (fConst138 * fRec1147[1]);
			double fTemp880 = (0.0001320316 * fTemp63);
			double fTemp881 = (0.042179134299999997 * fTemp61);
			double fTemp882 = (0.12655872979999999 * fTemp59);
			double fTemp883 = (0.00027086230000000002 * fTemp43);
			double fTemp884 = (0.065773980999999995 * fTemp45);
			double fTemp885 = (0.12530918690000001 * fTemp53);
			double fTemp886 = (0.072972461700000005 * fTemp57);
			double fTemp887 = (0.097083938100000003 * fTemp51);
			double fTemp888 = (0.028007681499999999 * fTemp55);
			double fTemp889 = (0.050266706000000001 * fTemp47);
			double fTemp890 = (0.047199921800000003 * fTemp49);
			double fTemp891 = (fConst140 * ((fTemp880 + (fTemp881 + (fTemp882 + (((fTemp883 + fTemp884) + fTemp885) + fTemp886)))) - (fTemp887 + ((fTemp888 + fTemp889) + fTemp890))));
			double fTemp892 = (fConst141 * fRec1150[1]);
			double fTemp893 = (fConst142 * fRec1153[1]);
			fRec1155[0] = (fTemp891 + (fTemp892 + (fRec1155[1] + fTemp893)));
			fRec1153[0] = fRec1155[0];
			double fRec1154 = ((fTemp893 + fTemp892) + fTemp891);
			fRec1152[0] = (fRec1153[0] + fRec1152[1]);
			fRec1150[0] = fRec1152[0];
			double fRec1151 = fRec1154;
			fRec1149[0] = (fTemp878 + (fTemp879 + (fRec1151 + fRec1149[1])));
			fRec1147[0] = fRec1149[0];
			double fRec1148 = (fTemp878 + (fRec1151 + fTemp879));
			fRec1146[0] = (fRec1147[0] + fRec1146[1]);
			fRec1144[0] = fRec1146[0];
			double fRec1145 = fRec1148;
			fRec1143[0] = (fTemp877 + (fRec1145 + fRec1143[1]));
			fRec1141[0] = fRec1143[0];
			double fRec1142 = (fRec1145 + fTemp877);
			double fTemp894 = (fConst144 * fRec1156[1]);
			double fTemp895 = (fConst145 * fRec1159[1]);
			double fTemp896 = (0.13650017680000001 * fTemp84);
			double fTemp897 = (0.030618480699999999 * fTemp78);
			double fTemp898 = (0.097240720500000002 * fTemp70);
			double fTemp899 = (0.019817356899999999 * fTemp68);
			double fTemp900 = (0.098184339699999998 * fTemp74);
			double fTemp901 = (0.013101750400000001 * fTemp76);
			double fTemp902 = (0.0091977097000000008 * fTemp82);
			double fTemp903 = (0.0290049213 * fTemp80);
			double fTemp904 = (0.080846708000000003 * fTemp72);
			double fTemp905 = (fConst147 * ((fTemp896 + (fTemp897 + (fTemp898 + (fTemp899 + (fTemp900 + fTemp901))))) - (fTemp902 + (fTemp903 + fTemp904))));
			double fTemp906 = (fConst148 * fRec1162[1]);
			double fTemp907 = (fConst149 * fRec1165[1]);
			fRec1167[0] = (fTemp905 + (fTemp906 + (fRec1167[1] + fTemp907)));
			fRec1165[0] = fRec1167[0];
			double fRec1166 = ((fTemp907 + fTemp906) + fTemp905);
			fRec1164[0] = (fRec1165[0] + fRec1164[1]);
			fRec1162[0] = fRec1164[0];
			double fRec1163 = fRec1166;
			fRec1161[0] = (fTemp894 + (fTemp895 + (fRec1163 + fRec1161[1])));
			fRec1159[0] = fRec1161[0];
			double fRec1160 = (fTemp894 + (fRec1163 + fTemp895));
			fRec1158[0] = (fRec1159[0] + fRec1158[1]);
			fRec1156[0] = fRec1158[0];
			double fRec1157 = fRec1160;
			double fTemp908 = (fConst151 * fRec1168[1]);
			double fTemp909 = (0.051104432300000002 * fTemp104);
			double fTemp910 = (0.123898842 * fTemp96);
			double fTemp911 = (0.050572427599999997 * fTemp92);
			double fTemp912 = (0.043922771100000001 * fTemp94);
			double fTemp913 = (0.075032095399999998 * fTemp102);
			double fTemp914 = (0.0031429367000000001 * fTemp98);
			double fTemp915 = (0.0466070876 * fTemp100);
			double fTemp916 = (fConst153 * ((fTemp909 + (fTemp910 + ((fTemp911 + fTemp912) + fTemp913))) - (fTemp914 + fTemp915)));
			double fTemp917 = (fConst154 * fRec1171[1]);
			double fTemp918 = (fConst155 * fRec1174[1]);
			fRec1176[0] = (fTemp916 + (fTemp917 + (fRec1176[1] + fTemp918)));
			fRec1174[0] = fRec1176[0];
			double fRec1175 = ((fTemp918 + fTemp917) + fTemp916);
			fRec1173[0] = (fRec1174[0] + fRec1173[1]);
			fRec1171[0] = fRec1173[0];
			double fRec1172 = fRec1175;
			fRec1170[0] = (fTemp908 + (fRec1172 + fRec1170[1]));
			fRec1168[0] = fRec1170[0];
			double fRec1169 = (fRec1172 + fTemp908);
			double fTemp919 = (0.0090041101000000005 * fTemp109);
			double fTemp920 = (0.052855355399999998 * fTemp113);
			double fTemp921 = (0.056016100499999999 * fTemp111);
			double fTemp922 = (fConst157 * ((fTemp919 + fTemp920) + fTemp921));
			double fTemp923 = (fConst158 * fRec1177[1]);
			fRec1179[0] = (fTemp922 + (fRec1179[1] + fTemp923));
			fRec1177[0] = fRec1179[0];
			double fRec1178 = (fTemp923 + fTemp922);
			double fTemp924 = (0.015194640299999999 * fTemp117);
			double fTemp925 = (0.0107897219 * fTemp119);
			double fTemp926 = (0.023044496599999999 * fTemp125);
			double fTemp927 = (0.097051638499999995 * fTemp121);
			double fTemp928 = (0.055792875499999998 * fTemp123);
			double fTemp929 = (fConst160 * ((((fTemp924 + fTemp925) + fTemp926) + fTemp927) + fTemp928));
			double fTemp930 = (fConst161 * fRec1180[1]);
			double fTemp931 = (fConst162 * fRec1183[1]);
			fRec1185[0] = (fTemp929 + (fTemp930 + (fRec1185[1] + fTemp931)));
			fRec1183[0] = fRec1185[0];
			double fRec1184 = ((fTemp931 + fTemp930) + fTemp929);
			fRec1182[0] = (fRec1183[0] + fRec1182[1]);
			fRec1180[0] = fRec1182[0];
			double fRec1181 = fRec1184;
			double fTemp932 = (0.025077422200000001 * fTemp130);
			fVec17[(IOTA & 127)] = ((fRec1124 + (fRec1142 + (fRec1157 + (fRec1169 + (fRec1178 + fRec1181))))) + fTemp932);
			output17[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec17[((IOTA - iConst163) & 127)])));
			double fTemp933 = (fConst125 * fRec1186[1]);
			double fTemp934 = (fConst126 * fRec1189[1]);
			double fTemp935 = (fConst128 * fRec1192[1]);
			double fTemp936 = (fConst129 * fRec1195[1]);
			double fTemp937 = (0.001108384 * fTemp11);
			double fTemp938 = (0.061708738999999999 * fTemp15);
			double fTemp939 = (0.00054961490000000001 * fTemp33);
			double fTemp940 = (0.0754730438 * fTemp19);
			double fTemp941 = (0.1456857278 * fTemp23);
			double fTemp942 = (0.0012228918000000001 * fTemp29);
			double fTemp943 = (fConst131 * ((fTemp794 + (fTemp937 + fTemp938)) - (fTemp790 + (fTemp939 + (fTemp792 + ((fTemp940 + (fTemp796 + (fTemp789 + ((fTemp787 + fTemp798) + fTemp941)))) + fTemp942))))));
			double fTemp944 = (fConst132 * fRec1198[1]);
			double fTemp945 = (fConst133 * fRec1201[1]);
			fRec1203[0] = (fTemp943 + (fTemp944 + (fRec1203[1] + fTemp945)));
			fRec1201[0] = fRec1203[0];
			double fRec1202 = ((fTemp945 + fTemp944) + fTemp943);
			fRec1200[0] = (fRec1201[0] + fRec1200[1]);
			fRec1198[0] = fRec1200[0];
			double fRec1199 = fRec1202;
			fRec1197[0] = (fTemp935 + (fTemp936 + (fRec1199 + fRec1197[1])));
			fRec1195[0] = fRec1197[0];
			double fRec1196 = (fTemp935 + (fRec1199 + fTemp936));
			fRec1194[0] = (fRec1195[0] + fRec1194[1]);
			fRec1192[0] = fRec1194[0];
			double fRec1193 = fRec1196;
			fRec1191[0] = (fTemp933 + (fTemp934 + (fRec1193 + fRec1191[1])));
			fRec1189[0] = fRec1191[0];
			double fRec1190 = (fTemp933 + (fRec1193 + fTemp934));
			fRec1188[0] = (fRec1189[0] + fRec1188[1]);
			fRec1186[0] = fRec1188[0];
			double fRec1187 = fRec1190;
			double fTemp946 = (fConst135 * fRec1204[1]);
			double fTemp947 = (fConst137 * fRec1207[1]);
			double fTemp948 = (fConst138 * fRec1210[1]);
			double fTemp949 = (0.059842723200000003 * fTemp47);
			double fTemp950 = (0.00019176140000000001 * fTemp63);
			double fTemp951 = (0.056085061200000001 * fTemp51);
			double fTemp952 = (0.00042021320000000002 * fTemp43);
			double fTemp953 = (0.17784278810000001 * fTemp53);
			double fTemp954 = (0.0014505162000000001 * fTemp59);
			double fTemp955 = (fConst140 * (((fTemp812 + fTemp949) + fTemp950) - (fTemp810 + ((fTemp951 + (fTemp816 + (fTemp808 + ((fTemp814 + fTemp952) + fTemp953)))) + fTemp954))));
			double fTemp956 = (fConst141 * fRec1213[1]);
			double fTemp957 = (fConst142 * fRec1216[1]);
			fRec1218[0] = (fTemp955 + (fTemp956 + (fRec1218[1] + fTemp957)));
			fRec1216[0] = fRec1218[0];
			double fRec1217 = ((fTemp957 + fTemp956) + fTemp955);
			fRec1215[0] = (fRec1216[0] + fRec1215[1]);
			fRec1213[0] = fRec1215[0];
			double fRec1214 = fRec1217;
			fRec1212[0] = (fTemp947 + (fTemp948 + (fRec1214 + fRec1212[1])));
			fRec1210[0] = fRec1212[0];
			double fRec1211 = (fTemp947 + (fRec1214 + fTemp948));
			fRec1209[0] = (fRec1210[0] + fRec1209[1]);
			fRec1207[0] = fRec1209[0];
			double fRec1208 = fRec1211;
			fRec1206[0] = (fTemp946 + (fRec1208 + fRec1206[1]));
			fRec1204[0] = fRec1206[0];
			double fRec1205 = (fRec1208 + fTemp946);
			double fTemp958 = (fConst144 * fRec1219[1]);
			double fTemp959 = (fConst145 * fRec1222[1]);
			double fTemp960 = (0.0149837431 * fTemp80);
			double fTemp961 = (0.025367565799999998 * fTemp82);
			double fTemp962 = (0.1380383265 * fTemp70);
			double fTemp963 = (0.001136186 * fTemp74);
			double fTemp964 = (fConst147 * ((fTemp825 + (fTemp960 + fTemp961)) - (fTemp827 + (fTemp823 + (fTemp962 + (fTemp828 + (fTemp830 + fTemp963)))))));
			double fTemp965 = (fConst148 * fRec1225[1]);
			double fTemp966 = (fConst149 * fRec1228[1]);
			fRec1230[0] = (fTemp964 + (fTemp965 + (fRec1230[1] + fTemp966)));
			fRec1228[0] = fRec1230[0];
			double fRec1229 = ((fTemp966 + fTemp965) + fTemp964);
			fRec1227[0] = (fRec1228[0] + fRec1227[1]);
			fRec1225[0] = fRec1227[0];
			double fRec1226 = fRec1229;
			fRec1224[0] = (fTemp958 + (fTemp959 + (fRec1226 + fRec1224[1])));
			fRec1222[0] = fRec1224[0];
			double fRec1223 = (fTemp958 + (fRec1226 + fTemp959));
			fRec1221[0] = (fRec1222[0] + fRec1221[1]);
			fRec1219[0] = fRec1221[0];
			double fRec1220 = fRec1223;
			double fTemp967 = (fConst151 * fRec1231[1]);
			double fTemp968 = (0.096633864700000002 * fTemp102);
			double fTemp969 = (0.071812713700000003 * fTemp92);
			double fTemp970 = (0.030199994399999999 * fTemp98);
			double fTemp971 = (0.00054882010000000003 * fTemp104);
			double fTemp972 = (fConst153 * ((fTemp841 + fTemp968) - ((fTemp840 + ((fTemp836 + fTemp969) + fTemp970)) + fTemp971)));
			double fTemp973 = (fConst154 * fRec1234[1]);
			double fTemp974 = (fConst155 * fRec1237[1]);
			fRec1239[0] = (fTemp972 + (fTemp973 + (fRec1239[1] + fTemp974)));
			fRec1237[0] = fRec1239[0];
			double fRec1238 = ((fTemp974 + fTemp973) + fTemp972);
			fRec1236[0] = (fRec1237[0] + fRec1236[1]);
			fRec1234[0] = fRec1236[0];
			double fRec1235 = fRec1238;
			fRec1233[0] = (fTemp967 + (fRec1235 + fRec1233[1]));
			fRec1231[0] = fRec1233[0];
			double fRec1232 = (fRec1235 + fTemp967);
			double fTemp975 = (0.057712014899999997 * fTemp111);
			double fTemp976 = (0.026868948399999999 * fTemp109);
			double fTemp977 = (fConst157 * ((fTemp975 + fTemp846) - fTemp976));
			double fTemp978 = (fConst158 * fRec1240[1]);
			fRec1242[0] = (fTemp977 + (fRec1242[1] + fTemp978));
			fRec1240[0] = fRec1242[0];
			double fRec1241 = (fTemp978 + fTemp977);
			double fTemp979 = (0.10618482379999999 * fTemp121);
			double fTemp980 = (0.044765766899999997 * fTemp119);
			double fTemp981 = (fConst160 * ((fTemp854 + (fTemp852 + fTemp979)) - (fTemp850 + fTemp980)));
			double fTemp982 = (fConst161 * fRec1243[1]);
			double fTemp983 = (fConst162 * fRec1246[1]);
			fRec1248[0] = (fTemp981 + (fTemp982 + (fRec1248[1] + fTemp983)));
			fRec1246[0] = fRec1248[0];
			double fRec1247 = ((fTemp983 + fTemp982) + fTemp981);
			fRec1245[0] = (fRec1246[0] + fRec1245[1]);
			fRec1243[0] = fRec1245[0];
			double fRec1244 = fRec1247;
			fVec18[(IOTA & 127)] = (fTemp782 + (fRec1187 + (fRec1205 + (fRec1220 + (fRec1232 + (fRec1241 + fRec1244))))));
			output18[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec18[((IOTA - iConst163) & 127)])));
			double fTemp984 = (fConst125 * fRec1249[1]);
			double fTemp985 = (fConst126 * fRec1252[1]);
			double fTemp986 = (fConst128 * fRec1255[1]);
			double fTemp987 = (fConst129 * fRec1258[1]);
			double fTemp988 = (0.10666509489999999 * fTemp15);
			double fTemp989 = (0.00017135039999999999 * fTemp11);
			double fTemp990 = (0.1035695636 * fTemp23);
			double fTemp991 = (0.10265550900000001 * fTemp29);
			double fTemp992 = (0.0444305246 * fTemp19);
			double fTemp993 = (0.00078339200000000005 * fTemp33);
			double fTemp994 = (fConst131 * ((fTemp858 + (fTemp988 + (fTemp869 + ((fTemp861 + fTemp989) + fTemp990)))) - (fTemp864 + ((fTemp991 + (fTemp863 + (fTemp992 + (fTemp860 + fTemp866)))) + fTemp993))));
			double fTemp995 = (fConst132 * fRec1261[1]);
			double fTemp996 = (fConst133 * fRec1264[1]);
			fRec1266[0] = (fTemp994 + (fTemp995 + (fRec1266[1] + fTemp996)));
			fRec1264[0] = fRec1266[0];
			double fRec1265 = ((fTemp996 + fTemp995) + fTemp994);
			fRec1263[0] = (fRec1264[0] + fRec1263[1]);
			fRec1261[0] = fRec1263[0];
			double fRec1262 = fRec1265;
			fRec1260[0] = (fTemp986 + (fTemp987 + (fRec1262 + fRec1260[1])));
			fRec1258[0] = fRec1260[0];
			double fRec1259 = (fTemp986 + (fRec1262 + fTemp987));
			fRec1257[0] = (fRec1258[0] + fRec1257[1]);
			fRec1255[0] = fRec1257[0];
			double fRec1256 = fRec1259;
			fRec1254[0] = (fTemp984 + (fTemp985 + (fRec1256 + fRec1254[1])));
			fRec1252[0] = fRec1254[0];
			double fRec1253 = (fTemp984 + (fRec1256 + fTemp985));
			fRec1251[0] = (fRec1252[0] + fRec1251[1]);
			fRec1249[0] = fRec1251[0];
			double fRec1250 = fRec1253;
			double fTemp997 = (fConst135 * fRec1267[1]);
			double fTemp998 = (fConst137 * fRec1270[1]);
			double fTemp999 = (fConst138 * fRec1273[1]);
			double fTemp1000 = (0.00027086230000000002 * fTemp63);
			double fTemp1001 = (0.12655872979999999 * fTemp53);
			double fTemp1002 = (0.097083938100000003 * fTemp47);
			double fTemp1003 = (0.12530918690000001 * fTemp59);
			double fTemp1004 = (0.050266706000000001 * fTemp51);
			double fTemp1005 = (0.0001320316 * fTemp43);
			double fTemp1006 = (fConst140 * ((fTemp1000 + (fTemp881 + ((fTemp888 + (fTemp884 + fTemp1001)) + fTemp1002))) - (fTemp1003 + (fTemp886 + (fTemp1004 + (fTemp890 + fTemp1005))))));
			double fTemp1007 = (fConst141 * fRec1276[1]);
			double fTemp1008 = (fConst142 * fRec1279[1]);
			fRec1281[0] = (fTemp1006 + (fTemp1007 + (fRec1281[1] + fTemp1008)));
			fRec1279[0] = fRec1281[0];
			double fRec1280 = ((fTemp1008 + fTemp1007) + fTemp1006);
			fRec1278[0] = (fRec1279[0] + fRec1278[1]);
			fRec1276[0] = fRec1278[0];
			double fRec1277 = fRec1280;
			fRec1275[0] = (fTemp998 + (fTemp999 + (fRec1277 + fRec1275[1])));
			fRec1273[0] = fRec1275[0];
			double fRec1274 = (fTemp998 + (fRec1277 + fTemp999));
			fRec1272[0] = (fRec1273[0] + fRec1272[1]);
			fRec1270[0] = fRec1272[0];
			double fRec1271 = fRec1274;
			fRec1269[0] = (fTemp997 + (fRec1271 + fRec1269[1]));
			fRec1267[0] = fRec1269[0];
			double fRec1268 = (fRec1271 + fTemp997);
			double fTemp1009 = (fConst144 * fRec1282[1]);
			double fTemp1010 = (fConst145 * fRec1285[1]);
			double fTemp1011 = (0.0091977097000000008 * fTemp80);
			double fTemp1012 = (0.098184339699999998 * fTemp70);
			double fTemp1013 = (fTemp899 + fTemp901);
			double fTemp1014 = (0.0290049213 * fTemp82);
			double fTemp1015 = (0.097240720500000002 * fTemp74);
			double fTemp1016 = (fConst147 * ((fTemp1011 + (fTemp1012 + fTemp1013)) - (fTemp896 + (fTemp1014 + (fTemp904 + (fTemp897 + fTemp1015))))));
			double fTemp1017 = (fConst148 * fRec1288[1]);
			double fTemp1018 = (fConst149 * fRec1291[1]);
			fRec1293[0] = (fTemp1016 + (fTemp1017 + (fRec1293[1] + fTemp1018)));
			fRec1291[0] = fRec1293[0];
			double fRec1292 = ((fTemp1018 + fTemp1017) + fTemp1016);
			fRec1290[0] = (fRec1291[0] + fRec1290[1]);
			fRec1288[0] = fRec1290[0];
			double fRec1289 = fRec1292;
			fRec1287[0] = (fTemp1009 + (fTemp1010 + (fRec1289 + fRec1287[1])));
			fRec1285[0] = fRec1287[0];
			double fRec1286 = (fTemp1009 + (fRec1289 + fTemp1010));
			fRec1284[0] = (fRec1285[0] + fRec1284[1]);
			fRec1282[0] = fRec1284[0];
			double fRec1283 = fRec1286;
			double fTemp1019 = (fConst151 * fRec1294[1]);
			double fTemp1020 = (0.051104432300000002 * fTemp92);
			double fTemp1021 = (0.050572427599999997 * fTemp104);
			double fTemp1022 = (0.0031429367000000001 * fTemp102);
			double fTemp1023 = (0.075032095399999998 * fTemp98);
			double fTemp1024 = (fConst153 * (fTemp1020 - (fTemp1021 + (fTemp910 + (fTemp1022 + (fTemp915 + (fTemp912 + fTemp1023)))))));
			double fTemp1025 = (fConst154 * fRec1297[1]);
			double fTemp1026 = (fConst155 * fRec1300[1]);
			fRec1302[0] = (fTemp1024 + (fTemp1025 + (fRec1302[1] + fTemp1026)));
			fRec1300[0] = fRec1302[0];
			double fRec1301 = ((fTemp1026 + fTemp1025) + fTemp1024);
			fRec1299[0] = (fRec1300[0] + fRec1299[1]);
			fRec1297[0] = fRec1299[0];
			double fRec1298 = fRec1301;
			fRec1296[0] = (fTemp1019 + (fRec1298 + fRec1296[1]));
			fRec1294[0] = fRec1296[0];
			double fRec1295 = (fRec1298 + fTemp1019);
			double fTemp1027 = (0.0090041101000000005 * fTemp111);
			double fTemp1028 = (0.056016100499999999 * fTemp109);
			double fTemp1029 = (fConst157 * ((fTemp920 + fTemp1027) - fTemp1028));
			double fTemp1030 = (fConst158 * fRec1303[1]);
			fRec1305[0] = (fTemp1029 + (fRec1305[1] + fTemp1030));
			fRec1303[0] = fRec1305[0];
			double fRec1304 = (fTemp1030 + fTemp1029);
			double fTemp1031 = (0.0107897219 * fTemp121);
			double fTemp1032 = (0.097051638499999995 * fTemp119);
			double fTemp1033 = (fConst160 * ((fTemp926 + fTemp1031) - (fTemp928 + (fTemp924 + fTemp1032))));
			double fTemp1034 = (fConst161 * fRec1306[1]);
			double fTemp1035 = (fConst162 * fRec1309[1]);
			fRec1311[0] = (fTemp1033 + (fTemp1034 + (fRec1311[1] + fTemp1035)));
			fRec1309[0] = fRec1311[0];
			double fRec1310 = ((fTemp1035 + fTemp1034) + fTemp1033);
			fRec1308[0] = (fRec1309[0] + fRec1308[1]);
			fRec1306[0] = fRec1308[0];
			double fRec1307 = fRec1310;
			fVec19[(IOTA & 127)] = (fTemp932 + (fRec1250 + (fRec1268 + (fRec1283 + (fRec1295 + (fRec1304 + fRec1307))))));
			output19[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec19[((IOTA - iConst163) & 127)])));
			double fTemp1036 = (fConst125 * fRec1312[1]);
			double fTemp1037 = (fConst126 * fRec1315[1]);
			double fTemp1038 = (fConst128 * fRec1318[1]);
			double fTemp1039 = (fConst129 * fRec1321[1]);
			double fTemp1040 = (fConst131 * ((fTemp790 + (fTemp791 + (fTemp793 + (fTemp795 + (fTemp799 + (fTemp789 + (fTemp787 + fTemp797))))))) - (fTemp792 + (fTemp794 + (fTemp796 + (fTemp798 + fTemp788))))));
			double fTemp1041 = (fConst132 * fRec1324[1]);
			double fTemp1042 = (fConst133 * fRec1327[1]);
			fRec1329[0] = (fTemp1040 + (fTemp1041 + (fRec1329[1] + fTemp1042)));
			fRec1327[0] = fRec1329[0];
			double fRec1328 = ((fTemp1042 + fTemp1041) + fTemp1040);
			fRec1326[0] = (fRec1327[0] + fRec1326[1]);
			fRec1324[0] = fRec1326[0];
			double fRec1325 = fRec1328;
			fRec1323[0] = (fTemp1038 + (fTemp1039 + (fRec1325 + fRec1323[1])));
			fRec1321[0] = fRec1323[0];
			double fRec1322 = (fTemp1038 + (fRec1325 + fTemp1039));
			fRec1320[0] = (fRec1321[0] + fRec1320[1]);
			fRec1318[0] = fRec1320[0];
			double fRec1319 = fRec1322;
			fRec1317[0] = (fTemp1036 + (fTemp1037 + (fRec1319 + fRec1317[1])));
			fRec1315[0] = fRec1317[0];
			double fRec1316 = (fTemp1036 + (fRec1319 + fTemp1037));
			fRec1314[0] = (fRec1315[0] + fRec1314[1]);
			fRec1312[0] = fRec1314[0];
			double fRec1313 = fRec1316;
			double fTemp1043 = (fConst135 * fRec1330[1]);
			double fTemp1044 = (fConst137 * fRec1333[1]);
			double fTemp1045 = (fConst138 * fRec1336[1]);
			double fTemp1046 = (fConst140 * ((fTemp811 + (fTemp813 + (fTemp808 + fTemp815))) - (fTemp809 + (fTemp810 + (fTemp812 + (fTemp816 + (fTemp807 + (fTemp806 + fTemp814))))))));
			double fTemp1047 = (fConst141 * fRec1339[1]);
			double fTemp1048 = (fConst142 * fRec1342[1]);
			fRec1344[0] = (fTemp1046 + (fTemp1047 + (fRec1344[1] + fTemp1048)));
			fRec1342[0] = fRec1344[0];
			double fRec1343 = ((fTemp1048 + fTemp1047) + fTemp1046);
			fRec1341[0] = (fRec1342[0] + fRec1341[1]);
			fRec1339[0] = fRec1341[0];
			double fRec1340 = fRec1343;
			fRec1338[0] = (fTemp1044 + (fTemp1045 + (fRec1340 + fRec1338[1])));
			fRec1336[0] = fRec1338[0];
			double fRec1337 = (fTemp1044 + (fRec1340 + fTemp1045));
			fRec1335[0] = (fRec1336[0] + fRec1335[1]);
			fRec1333[0] = fRec1335[0];
			double fRec1334 = fRec1337;
			fRec1332[0] = (fTemp1043 + (fRec1334 + fRec1332[1]));
			fRec1330[0] = fRec1332[0];
			double fRec1331 = (fRec1334 + fTemp1043);
			double fTemp1049 = (fConst144 * fRec1345[1]);
			double fTemp1050 = (fConst145 * fRec1348[1]);
			double fTemp1051 = (fTemp828 + fTemp830);
			double fTemp1052 = (fConst147 * ((fTemp826 + (fTemp823 + fTemp829)) - (fTemp825 + (fTemp827 + (fTemp824 + (fTemp822 + fTemp1051))))));
			double fTemp1053 = (fConst148 * fRec1351[1]);
			double fTemp1054 = (fConst149 * fRec1354[1]);
			fRec1356[0] = (fTemp1052 + (fTemp1053 + (fRec1356[1] + fTemp1054)));
			fRec1354[0] = fRec1356[0];
			double fRec1355 = ((fTemp1054 + fTemp1053) + fTemp1052);
			fRec1353[0] = (fRec1354[0] + fRec1353[1]);
			fRec1351[0] = fRec1353[0];
			double fRec1352 = fRec1355;
			fRec1350[0] = (fTemp1049 + (fTemp1050 + (fRec1352 + fRec1350[1])));
			fRec1348[0] = fRec1350[0];
			double fRec1349 = (fTemp1049 + (fRec1352 + fTemp1050));
			fRec1347[0] = (fRec1348[0] + fRec1347[1]);
			fRec1345[0] = fRec1347[0];
			double fRec1346 = fRec1349;
			double fTemp1055 = (fConst151 * fRec1357[1]);
			double fTemp1056 = (fConst153 * ((fTemp836 + fTemp839) - (fTemp841 + (fTemp838 + (fTemp840 + (fTemp835 + fTemp837))))));
			double fTemp1057 = (fConst154 * fRec1360[1]);
			double fTemp1058 = (fConst155 * fRec1363[1]);
			fRec1365[0] = (fTemp1056 + (fTemp1057 + (fRec1365[1] + fTemp1058)));
			fRec1363[0] = fRec1365[0];
			double fRec1364 = ((fTemp1058 + fTemp1057) + fTemp1056);
			fRec1362[0] = (fRec1363[0] + fRec1362[1]);
			fRec1360[0] = fRec1362[0];
			double fRec1361 = fRec1364;
			fRec1359[0] = (fTemp1055 + (fRec1361 + fRec1359[1]));
			fRec1357[0] = fRec1359[0];
			double fRec1358 = (fRec1361 + fTemp1055);
			double fTemp1059 = (fConst157 * (fTemp846 - (fTemp845 + fTemp847)));
			double fTemp1060 = (fConst158 * fRec1366[1]);
			fRec1368[0] = (fTemp1059 + (fRec1368[1] + fTemp1060));
			fRec1366[0] = fRec1368[0];
			double fRec1367 = (fTemp1060 + fTemp1059);
			double fTemp1061 = (fConst160 * ((fTemp850 + fTemp852) - (fTemp854 + (fTemp851 + fTemp853))));
			double fTemp1062 = (fConst161 * fRec1369[1]);
			double fTemp1063 = (fConst162 * fRec1372[1]);
			fRec1374[0] = (fTemp1061 + (fTemp1062 + (fRec1374[1] + fTemp1063)));
			fRec1372[0] = fRec1374[0];
			double fRec1373 = ((fTemp1063 + fTemp1062) + fTemp1061);
			fRec1371[0] = (fRec1372[0] + fRec1371[1]);
			fRec1369[0] = fRec1371[0];
			double fRec1370 = fRec1373;
			fVec20[(IOTA & 127)] = (fTemp782 + (fRec1313 + (fRec1331 + (fRec1346 + (fRec1358 + (fRec1367 + fRec1370))))));
			output20[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec20[((IOTA - iConst163) & 127)])));
			double fTemp1064 = (fConst125 * fRec1375[1]);
			double fTemp1065 = (fConst126 * fRec1378[1]);
			double fTemp1066 = (fConst128 * fRec1381[1]);
			double fTemp1067 = (fConst129 * fRec1384[1]);
			double fTemp1068 = (fConst131 * ((fTemp864 + (fTemp870 + (fTemp858 + (fTemp863 + (fTemp865 + (fTemp867 + (fTemp861 + (fTemp860 + fTemp868)))))))) - (fTemp859 + (fTemp866 + (fTemp862 + fTemp869)))));
			double fTemp1069 = (fConst132 * fRec1387[1]);
			double fTemp1070 = (fConst133 * fRec1390[1]);
			fRec1392[0] = (fTemp1068 + (fTemp1069 + (fRec1392[1] + fTemp1070)));
			fRec1390[0] = fRec1392[0];
			double fRec1391 = ((fTemp1070 + fTemp1069) + fTemp1068);
			fRec1389[0] = (fRec1390[0] + fRec1389[1]);
			fRec1387[0] = fRec1389[0];
			double fRec1388 = fRec1391;
			fRec1386[0] = (fTemp1066 + (fTemp1067 + (fRec1388 + fRec1386[1])));
			fRec1384[0] = fRec1386[0];
			double fRec1385 = (fTemp1066 + (fRec1388 + fTemp1067));
			fRec1383[0] = (fRec1384[0] + fRec1383[1]);
			fRec1381[0] = fRec1383[0];
			double fRec1382 = fRec1385;
			fRec1380[0] = (fTemp1064 + (fTemp1065 + (fRec1382 + fRec1380[1])));
			fRec1378[0] = fRec1380[0];
			double fRec1379 = (fTemp1064 + (fRec1382 + fTemp1065));
			fRec1377[0] = (fRec1378[0] + fRec1377[1]);
			fRec1375[0] = fRec1377[0];
			double fRec1376 = fRec1379;
			double fTemp1071 = (fConst135 * fRec1393[1]);
			double fTemp1072 = (fConst137 * fRec1396[1]);
			double fTemp1073 = (fConst138 * fRec1399[1]);
			double fTemp1074 = (fConst140 * ((fTemp881 + (fTemp886 + (fTemp887 + (fTemp884 + fTemp889)))) - (fTemp880 + (fTemp882 + (fTemp890 + (fTemp888 + (fTemp883 + fTemp885)))))));
			double fTemp1075 = (fConst141 * fRec1402[1]);
			double fTemp1076 = (fConst142 * fRec1405[1]);
			fRec1407[0] = (fTemp1074 + (fTemp1075 + (fRec1407[1] + fTemp1076)));
			fRec1405[0] = fRec1407[0];
			double fRec1406 = ((fTemp1076 + fTemp1075) + fTemp1074);
			fRec1404[0] = (fRec1405[0] + fRec1404[1]);
			fRec1402[0] = fRec1404[0];
			double fRec1403 = fRec1406;
			fRec1401[0] = (fTemp1072 + (fTemp1073 + (fRec1403 + fRec1401[1])));
			fRec1399[0] = fRec1401[0];
			double fRec1400 = (fTemp1072 + (fRec1403 + fTemp1073));
			fRec1398[0] = (fRec1399[0] + fRec1398[1]);
			fRec1396[0] = fRec1398[0];
			double fRec1397 = fRec1400;
			fRec1395[0] = (fTemp1071 + (fRec1397 + fRec1395[1]));
			fRec1393[0] = fRec1395[0];
			double fRec1394 = (fRec1397 + fTemp1071);
			double fTemp1077 = (fConst144 * fRec1408[1]);
			double fTemp1078 = (fConst145 * fRec1411[1]);
			double fTemp1079 = (fConst147 * ((fTemp896 + (fTemp902 + (fTemp903 + (fTemp897 + fTemp1013)))) - (fTemp904 + (fTemp898 + fTemp900))));
			double fTemp1080 = (fConst148 * fRec1414[1]);
			double fTemp1081 = (fConst149 * fRec1417[1]);
			fRec1419[0] = (fTemp1079 + (fTemp1080 + (fRec1419[1] + fTemp1081)));
			fRec1417[0] = fRec1419[0];
			double fRec1418 = ((fTemp1081 + fTemp1080) + fTemp1079);
			fRec1416[0] = (fRec1417[0] + fRec1416[1]);
			fRec1414[0] = fRec1416[0];
			double fRec1415 = fRec1418;
			fRec1413[0] = (fTemp1077 + (fTemp1078 + (fRec1415 + fRec1413[1])));
			fRec1411[0] = fRec1413[0];
			double fRec1412 = (fTemp1077 + (fRec1415 + fTemp1078));
			fRec1410[0] = (fRec1411[0] + fRec1410[1]);
			fRec1408[0] = fRec1410[0];
			double fRec1409 = fRec1412;
			double fTemp1082 = (fConst151 * fRec1420[1]);
			double fTemp1083 = (fConst153 * ((fTemp910 + (fTemp912 + fTemp914)) - (fTemp909 + (fTemp913 + (fTemp911 + fTemp915)))));
			double fTemp1084 = (fConst154 * fRec1423[1]);
			double fTemp1085 = (fConst155 * fRec1426[1]);
			fRec1428[0] = (fTemp1083 + (fTemp1084 + (fRec1428[1] + fTemp1085)));
			fRec1426[0] = fRec1428[0];
			double fRec1427 = ((fTemp1085 + fTemp1084) + fTemp1083);
			fRec1425[0] = (fRec1426[0] + fRec1425[1]);
			fRec1423[0] = fRec1425[0];
			double fRec1424 = fRec1427;
			fRec1422[0] = (fTemp1082 + (fRec1424 + fRec1422[1]));
			fRec1420[0] = fRec1422[0];
			double fRec1421 = (fRec1424 + fTemp1082);
			double fTemp1086 = (fConst157 * (fTemp920 - (fTemp919 + fTemp921)));
			double fTemp1087 = (fConst158 * fRec1429[1]);
			fRec1431[0] = (fTemp1086 + (fRec1431[1] + fTemp1087));
			fRec1429[0] = fRec1431[0];
			double fRec1430 = (fTemp1087 + fTemp1086);
			double fTemp1088 = (fConst160 * ((fTemp928 + (fTemp924 + fTemp926)) - (fTemp925 + fTemp927)));
			double fTemp1089 = (fConst161 * fRec1432[1]);
			double fTemp1090 = (fConst162 * fRec1435[1]);
			fRec1437[0] = (fTemp1088 + (fTemp1089 + (fRec1437[1] + fTemp1090)));
			fRec1435[0] = fRec1437[0];
			double fRec1436 = ((fTemp1090 + fTemp1089) + fTemp1088);
			fRec1434[0] = (fRec1435[0] + fRec1434[1]);
			fRec1432[0] = fRec1434[0];
			double fRec1433 = fRec1436;
			fVec21[(IOTA & 127)] = (fTemp932 + (fRec1376 + (fRec1394 + (fRec1409 + (fRec1421 + (fRec1430 + fRec1433))))));
			output21[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec21[((IOTA - iConst163) & 127)])));
			double fTemp1091 = (fConst125 * fRec1438[1]);
			double fTemp1092 = (fConst126 * fRec1441[1]);
			double fTemp1093 = (fConst128 * fRec1444[1]);
			double fTemp1094 = (fConst129 * fRec1447[1]);
			double fTemp1095 = (fConst131 * ((fTemp939 + (fTemp942 + (fTemp794 + (fTemp941 + fTemp940)))) - (fTemp790 + (fTemp792 + (fTemp796 + (fTemp938 + (fTemp789 + (fTemp798 + (fTemp787 + fTemp937)))))))));
			double fTemp1096 = (fConst132 * fRec1450[1]);
			double fTemp1097 = (fConst133 * fRec1453[1]);
			fRec1455[0] = (fTemp1095 + (fTemp1096 + (fRec1455[1] + fTemp1097)));
			fRec1453[0] = fRec1455[0];
			double fRec1454 = ((fTemp1097 + fTemp1096) + fTemp1095);
			fRec1452[0] = (fRec1453[0] + fRec1452[1]);
			fRec1450[0] = fRec1452[0];
			double fRec1451 = fRec1454;
			fRec1449[0] = (fTemp1093 + (fTemp1094 + (fRec1451 + fRec1449[1])));
			fRec1447[0] = fRec1449[0];
			double fRec1448 = (fTemp1093 + (fRec1451 + fTemp1094));
			fRec1446[0] = (fRec1447[0] + fRec1446[1]);
			fRec1444[0] = fRec1446[0];
			double fRec1445 = fRec1448;
			fRec1443[0] = (fTemp1091 + (fTemp1092 + (fRec1445 + fRec1443[1])));
			fRec1441[0] = fRec1443[0];
			double fRec1442 = (fTemp1091 + (fRec1445 + fTemp1092));
			fRec1440[0] = (fRec1441[0] + fRec1440[1]);
			fRec1438[0] = fRec1440[0];
			double fRec1439 = fRec1442;
			double fTemp1098 = (fConst135 * fRec1456[1]);
			double fTemp1099 = (fConst137 * fRec1459[1]);
			double fTemp1100 = (fConst138 * fRec1462[1]);
			double fTemp1101 = (fConst140 * ((fTemp954 + (fTemp812 + (fTemp951 + (fTemp952 + fTemp953)))) - (fTemp950 + (fTemp810 + (fTemp816 + (fTemp949 + (fTemp814 + fTemp808)))))));
			double fTemp1102 = (fConst141 * fRec1465[1]);
			double fTemp1103 = (fConst142 * fRec1468[1]);
			fRec1470[0] = (fTemp1101 + (fTemp1102 + (fRec1470[1] + fTemp1103)));
			fRec1468[0] = fRec1470[0];
			double fRec1469 = ((fTemp1103 + fTemp1102) + fTemp1101);
			fRec1467[0] = (fRec1468[0] + fRec1467[1]);
			fRec1465[0] = fRec1467[0];
			double fRec1466 = fRec1469;
			fRec1464[0] = (fTemp1099 + (fTemp1100 + (fRec1466 + fRec1464[1])));
			fRec1462[0] = fRec1464[0];
			double fRec1463 = (fTemp1099 + (fRec1466 + fTemp1100));
			fRec1461[0] = (fRec1462[0] + fRec1461[1]);
			fRec1459[0] = fRec1461[0];
			double fRec1460 = fRec1463;
			fRec1458[0] = (fTemp1098 + (fRec1460 + fRec1458[1]));
			fRec1456[0] = fRec1458[0];
			double fRec1457 = (fRec1460 + fTemp1098);
			double fTemp1104 = (fConst144 * fRec1471[1]);
			double fTemp1105 = (fConst145 * fRec1474[1]);
			double fTemp1106 = (fConst147 * ((fTemp825 + (fTemp962 + fTemp963)) - (fTemp961 + (fTemp827 + (fTemp960 + (fTemp823 + fTemp1051))))));
			double fTemp1107 = (fConst148 * fRec1477[1]);
			double fTemp1108 = (fConst149 * fRec1480[1]);
			fRec1482[0] = (fTemp1106 + (fTemp1107 + (fRec1482[1] + fTemp1108)));
			fRec1480[0] = fRec1482[0];
			double fRec1481 = ((fTemp1108 + fTemp1107) + fTemp1106);
			fRec1479[0] = (fRec1480[0] + fRec1479[1]);
			fRec1477[0] = fRec1479[0];
			double fRec1478 = fRec1481;
			fRec1476[0] = (fTemp1104 + (fTemp1105 + (fRec1478 + fRec1476[1])));
			fRec1474[0] = fRec1476[0];
			double fRec1475 = (fTemp1104 + (fRec1478 + fTemp1105));
			fRec1473[0] = (fRec1474[0] + fRec1473[1]);
			fRec1471[0] = fRec1473[0];
			double fRec1472 = fRec1475;
			double fTemp1109 = (fConst151 * fRec1483[1]);
			double fTemp1110 = (fConst153 * ((fTemp971 + (fTemp841 + (fTemp969 + fTemp970))) - (fTemp968 + (fTemp836 + fTemp840))));
			double fTemp1111 = (fConst154 * fRec1486[1]);
			double fTemp1112 = (fConst155 * fRec1489[1]);
			fRec1491[0] = (fTemp1110 + (fTemp1111 + (fRec1491[1] + fTemp1112)));
			fRec1489[0] = fRec1491[0];
			double fRec1490 = ((fTemp1112 + fTemp1111) + fTemp1110);
			fRec1488[0] = (fRec1489[0] + fRec1488[1]);
			fRec1486[0] = fRec1488[0];
			double fRec1487 = fRec1490;
			fRec1485[0] = (fTemp1109 + (fRec1487 + fRec1485[1]));
			fRec1483[0] = fRec1485[0];
			double fRec1484 = (fRec1487 + fTemp1109);
			double fTemp1113 = (fConst157 * ((fTemp976 + fTemp846) - fTemp975));
			double fTemp1114 = (fConst158 * fRec1492[1]);
			fRec1494[0] = (fTemp1113 + (fRec1494[1] + fTemp1114));
			fRec1492[0] = fRec1494[0];
			double fRec1493 = (fTemp1114 + fTemp1113);
			double fTemp1115 = (fConst160 * ((fTemp854 + (fTemp852 + fTemp980)) - (fTemp850 + fTemp979)));
			double fTemp1116 = (fConst161 * fRec1495[1]);
			double fTemp1117 = (fConst162 * fRec1498[1]);
			fRec1500[0] = (fTemp1115 + (fTemp1116 + (fRec1500[1] + fTemp1117)));
			fRec1498[0] = fRec1500[0];
			double fRec1499 = ((fTemp1117 + fTemp1116) + fTemp1115);
			fRec1497[0] = (fRec1498[0] + fRec1497[1]);
			fRec1495[0] = fRec1497[0];
			double fRec1496 = fRec1499;
			fVec22[(IOTA & 127)] = (fTemp782 + (fRec1439 + (fRec1457 + (fRec1472 + (fRec1484 + (fRec1493 + fRec1496))))));
			output22[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec22[((IOTA - iConst163) & 127)])));
			double fTemp1118 = (fConst125 * fRec1501[1]);
			double fTemp1119 = (fConst126 * fRec1504[1]);
			double fTemp1120 = (fConst128 * fRec1507[1]);
			double fTemp1121 = (fConst129 * fRec1510[1]);
			double fTemp1122 = (fConst131 * ((fTemp993 + (fTemp858 + (fTemp991 + (fTemp992 + (fTemp861 + fTemp869))))) - (fTemp864 + (fTemp863 + (fTemp866 + (fTemp988 + (fTemp990 + (fTemp860 + fTemp989))))))));
			double fTemp1123 = (fConst132 * fRec1513[1]);
			double fTemp1124 = (fConst133 * fRec1516[1]);
			fRec1518[0] = (fTemp1122 + (fTemp1123 + (fRec1518[1] + fTemp1124)));
			fRec1516[0] = fRec1518[0];
			double fRec1517 = ((fTemp1124 + fTemp1123) + fTemp1122);
			fRec1515[0] = (fRec1516[0] + fRec1515[1]);
			fRec1513[0] = fRec1515[0];
			double fRec1514 = fRec1517;
			fRec1512[0] = (fTemp1120 + (fTemp1121 + (fRec1514 + fRec1512[1])));
			fRec1510[0] = fRec1512[0];
			double fRec1511 = (fTemp1120 + (fRec1514 + fTemp1121));
			fRec1509[0] = (fRec1510[0] + fRec1509[1]);
			fRec1507[0] = fRec1509[0];
			double fRec1508 = fRec1511;
			fRec1506[0] = (fTemp1118 + (fTemp1119 + (fRec1508 + fRec1506[1])));
			fRec1504[0] = fRec1506[0];
			double fRec1505 = (fTemp1118 + (fRec1508 + fTemp1119));
			fRec1503[0] = (fRec1504[0] + fRec1503[1]);
			fRec1501[0] = fRec1503[0];
			double fRec1502 = fRec1505;
			double fTemp1125 = (fConst135 * fRec1519[1]);
			double fTemp1126 = (fConst137 * fRec1522[1]);
			double fTemp1127 = (fConst138 * fRec1525[1]);
			double fTemp1128 = (fConst140 * ((fTemp881 + (fTemp1003 + (fTemp1004 + (fTemp888 + (fTemp884 + fTemp1005))))) - (fTemp1000 + (fTemp886 + (fTemp890 + (fTemp1001 + fTemp1002))))));
			double fTemp1129 = (fConst141 * fRec1528[1]);
			double fTemp1130 = (fConst142 * fRec1531[1]);
			fRec1533[0] = (fTemp1128 + (fTemp1129 + (fRec1533[1] + fTemp1130)));
			fRec1531[0] = fRec1533[0];
			double fRec1532 = ((fTemp1130 + fTemp1129) + fTemp1128);
			fRec1530[0] = (fRec1531[0] + fRec1530[1]);
			fRec1528[0] = fRec1530[0];
			double fRec1529 = fRec1532;
			fRec1527[0] = (fTemp1126 + (fTemp1127 + (fRec1529 + fRec1527[1])));
			fRec1525[0] = fRec1527[0];
			double fRec1526 = (fTemp1126 + (fRec1529 + fTemp1127));
			fRec1524[0] = (fRec1525[0] + fRec1524[1]);
			fRec1522[0] = fRec1524[0];
			double fRec1523 = fRec1526;
			fRec1521[0] = (fTemp1125 + (fRec1523 + fRec1521[1]));
			fRec1519[0] = fRec1521[0];
			double fRec1520 = (fRec1523 + fTemp1125);
			double fTemp1131 = (fConst144 * fRec1534[1]);
			double fTemp1132 = (fConst145 * fRec1537[1]);
			double fTemp1133 = (fConst147 * ((fTemp1014 + (fTemp899 + (fTemp901 + fTemp1015))) - (fTemp896 + (fTemp904 + (fTemp1011 + (fTemp897 + fTemp1012))))));
			double fTemp1134 = (fConst148 * fRec1540[1]);
			double fTemp1135 = (fConst149 * fRec1543[1]);
			fRec1545[0] = (fTemp1133 + (fTemp1134 + (fRec1545[1] + fTemp1135)));
			fRec1543[0] = fRec1545[0];
			double fRec1544 = ((fTemp1135 + fTemp1134) + fTemp1133);
			fRec1542[0] = (fRec1543[0] + fRec1542[1]);
			fRec1540[0] = fRec1542[0];
			double fRec1541 = fRec1544;
			fRec1539[0] = (fTemp1131 + (fTemp1132 + (fRec1541 + fRec1539[1])));
			fRec1537[0] = fRec1539[0];
			double fRec1538 = (fTemp1131 + (fRec1541 + fTemp1132));
			fRec1536[0] = (fRec1537[0] + fRec1536[1]);
			fRec1534[0] = fRec1536[0];
			double fRec1535 = fRec1538;
			double fTemp1136 = (fConst151 * fRec1546[1]);
			double fTemp1137 = (fConst153 * ((fTemp1021 + (fTemp1023 + fTemp1022)) - (fTemp910 + (fTemp915 + (fTemp912 + fTemp1020)))));
			double fTemp1138 = (fConst154 * fRec1549[1]);
			double fTemp1139 = (fConst155 * fRec1552[1]);
			fRec1554[0] = (fTemp1137 + (fTemp1138 + (fRec1554[1] + fTemp1139)));
			fRec1552[0] = fRec1554[0];
			double fRec1553 = ((fTemp1139 + fTemp1138) + fTemp1137);
			fRec1551[0] = (fRec1552[0] + fRec1551[1]);
			fRec1549[0] = fRec1551[0];
			double fRec1550 = fRec1553;
			fRec1548[0] = (fTemp1136 + (fRec1550 + fRec1548[1]));
			fRec1546[0] = fRec1548[0];
			double fRec1547 = (fRec1550 + fTemp1136);
			double fTemp1140 = (fConst157 * ((fTemp920 + fTemp1028) - fTemp1027));
			double fTemp1141 = (fConst158 * fRec1555[1]);
			fRec1557[0] = (fTemp1140 + (fRec1557[1] + fTemp1141));
			fRec1555[0] = fRec1557[0];
			double fRec1556 = (fTemp1141 + fTemp1140);
			double fTemp1142 = (fConst160 * ((fTemp926 + fTemp1032) - (fTemp928 + (fTemp924 + fTemp1031))));
			double fTemp1143 = (fConst161 * fRec1558[1]);
			double fTemp1144 = (fConst162 * fRec1561[1]);
			fRec1563[0] = (fTemp1142 + (fTemp1143 + (fRec1563[1] + fTemp1144)));
			fRec1561[0] = fRec1563[0];
			double fRec1562 = ((fTemp1144 + fTemp1143) + fTemp1142);
			fRec1560[0] = (fRec1561[0] + fRec1560[1]);
			fRec1558[0] = fRec1560[0];
			double fRec1559 = fRec1562;
			fVec23[(IOTA & 127)] = (fTemp932 + (fRec1502 + (fRec1520 + (fRec1535 + (fRec1547 + (fRec1556 + fRec1559))))));
			output23[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec23[((IOTA - iConst163) & 127)])));
			double fTemp1145 = (0.029770113800000001 * fTemp130);
			double fTemp1146 = (fConst165 * fRec1564[1]);
			double fTemp1147 = (fConst166 * fRec1567[1]);
			double fTemp1148 = (fConst168 * fRec1570[1]);
			double fTemp1149 = (fConst169 * fRec1573[1]);
			double fTemp1150 = (0.0073898818999999999 * fTemp21);
			double fTemp1151 = (0.00041699590000000001 * fTemp11);
			double fTemp1152 = (0.0050776500000000004 * fTemp13);
			double fTemp1153 = (0.083437284900000006 * fTemp15);
			double fTemp1154 = (0.0058793252000000004 * fTemp35);
			double fTemp1155 = (0.00024519039999999998 * fTemp33);
			double fTemp1156 = (0.0059842055 * fTemp31);
			double fTemp1157 = (0.0001242177 * fTemp29);
			double fTemp1158 = (0.053196245500000003 * fTemp27);
			double fTemp1159 = (0.047473814699999999 * fTemp19);
			double fTemp1160 = (2.16913e-05 * fTemp23);
			double fTemp1161 = (0.089950539100000004 * fTemp25);
			double fTemp1162 = (0.059688200599999998 * fTemp17);
			double fTemp1163 = (fConst171 * (((((fTemp1150 + fTemp1151) + fTemp1152) + fTemp1153) + fTemp1154) - (fTemp1155 + (fTemp1156 + (fTemp1157 + (fTemp1158 + (fTemp1159 + ((fTemp1160 + fTemp1161) + fTemp1162))))))));
			double fTemp1164 = (fConst172 * fRec1576[1]);
			double fTemp1165 = (fConst173 * fRec1579[1]);
			fRec1581[0] = (fTemp1163 + (fTemp1164 + (fRec1581[1] + fTemp1165)));
			fRec1579[0] = fRec1581[0];
			double fRec1580 = ((fTemp1165 + fTemp1164) + fTemp1163);
			fRec1578[0] = (fRec1579[0] + fRec1578[1]);
			fRec1576[0] = fRec1578[0];
			double fRec1577 = fRec1580;
			fRec1575[0] = (fTemp1148 + (fTemp1149 + (fRec1577 + fRec1575[1])));
			fRec1573[0] = fRec1575[0];
			double fRec1574 = (fTemp1148 + (fRec1577 + fTemp1149));
			fRec1572[0] = (fRec1573[0] + fRec1572[1]);
			fRec1570[0] = fRec1572[0];
			double fRec1571 = fRec1574;
			fRec1569[0] = (fTemp1146 + (fTemp1147 + (fRec1571 + fRec1569[1])));
			fRec1567[0] = fRec1569[0];
			double fRec1568 = (fTemp1146 + (fRec1571 + fTemp1147));
			fRec1566[0] = (fRec1567[0] + fRec1566[1]);
			fRec1564[0] = fRec1566[0];
			double fRec1565 = fRec1568;
			double fTemp1166 = (fConst175 * fRec1582[1]);
			double fTemp1167 = (fConst177 * fRec1585[1]);
			double fTemp1168 = (fConst178 * fRec1588[1]);
			double fTemp1169 = (0.0046018185999999999 * fTemp45);
			double fTemp1170 = (1.9106400000000001e-05 * fTemp53);
			double fTemp1171 = (0.1284615754 * fTemp47);
			double fTemp1172 = (8.5435900000000006e-05 * fTemp63);
			double fTemp1173 = (0.0060308426999999996 * fTemp61);
			double fTemp1174 = (0.00013197449999999999 * fTemp59);
			double fTemp1175 = (0.069504497799999995 * fTemp57);
			double fTemp1176 = (0.073090988400000001 * fTemp51);
			double fTemp1177 = (0.0001686607 * fTemp43);
			double fTemp1178 = (0.1173911523 * fTemp55);
			double fTemp1179 = (0.052157505999999999 * fTemp49);
			double fTemp1180 = (fConst180 * ((((fTemp1169 + fTemp1170) + fTemp1171) + fTemp1172) - (fTemp1173 + (fTemp1174 + (fTemp1175 + (fTemp1176 + ((fTemp1177 + fTemp1178) + fTemp1179)))))));
			double fTemp1181 = (fConst181 * fRec1591[1]);
			double fTemp1182 = (fConst182 * fRec1594[1]);
			fRec1596[0] = (fTemp1180 + (fTemp1181 + (fRec1596[1] + fTemp1182)));
			fRec1594[0] = fRec1596[0];
			double fRec1595 = ((fTemp1182 + fTemp1181) + fTemp1180);
			fRec1593[0] = (fRec1594[0] + fRec1593[1]);
			fRec1591[0] = fRec1593[0];
			double fRec1592 = fRec1595;
			fRec1590[0] = (fTemp1167 + (fTemp1168 + (fRec1592 + fRec1590[1])));
			fRec1588[0] = fRec1590[0];
			double fRec1589 = (fTemp1167 + (fRec1592 + fTemp1168));
			fRec1587[0] = (fRec1588[0] + fRec1587[1]);
			fRec1585[0] = fRec1587[0];
			double fRec1586 = fRec1589;
			fRec1584[0] = (fTemp1166 + (fRec1586 + fRec1584[1]));
			fRec1582[0] = fRec1584[0];
			double fRec1583 = (fRec1586 + fTemp1166);
			double fTemp1183 = (fConst184 * fRec1597[1]);
			double fTemp1184 = (fConst185 * fRec1600[1]);
			double fTemp1185 = (0.00070791660000000005 * fTemp68);
			double fTemp1186 = (0.14054161200000001 * fTemp80);
			double fTemp1187 = (0.0140617433 * fTemp72);
			double fTemp1188 = (0.047113879599999998 * fTemp84);
			double fTemp1189 = (0.079963793599999999 * fTemp82);
			double fTemp1190 = (0.080013739799999997 * fTemp78);
			double fTemp1191 = (7.6349000000000004e-06 * fTemp70);
			double fTemp1192 = (0.0001077967 * fTemp74);
			double fTemp1193 = (0.0014784857999999999 * fTemp76);
			double fTemp1194 = (fConst187 * (((fTemp1185 + fTemp1186) + fTemp1187) - (fTemp1188 + (fTemp1189 + (fTemp1190 + (fTemp1191 + (fTemp1192 + fTemp1193)))))));
			double fTemp1195 = (fConst188 * fRec1603[1]);
			double fTemp1196 = (fConst189 * fRec1606[1]);
			fRec1608[0] = (fTemp1194 + (fTemp1195 + (fRec1608[1] + fTemp1196)));
			fRec1606[0] = fRec1608[0];
			double fRec1607 = ((fTemp1196 + fTemp1195) + fTemp1194);
			fRec1605[0] = (fRec1606[0] + fRec1605[1]);
			fRec1603[0] = fRec1605[0];
			double fRec1604 = fRec1607;
			fRec1602[0] = (fTemp1183 + (fTemp1184 + (fRec1604 + fRec1602[1])));
			fRec1600[0] = fRec1602[0];
			double fRec1601 = (fTemp1183 + (fRec1604 + fTemp1184));
			fRec1599[0] = (fRec1600[0] + fRec1599[1]);
			fRec1597[0] = fRec1599[0];
			double fRec1598 = fRec1601;
			double fTemp1197 = (fConst191 * fRec1609[1]);
			double fTemp1198 = (8.8789999999999992e-06 * fTemp92);
			double fTemp1199 = (0.1233942308 * fTemp98);
			double fTemp1200 = (0.064449138399999994 * fTemp100);
			double fTemp1201 = (3.8474599999999999e-05 * fTemp104);
			double fTemp1202 = (0.026663153700000001 * fTemp96);
			double fTemp1203 = (0.045500070199999999 * fTemp94);
			double fTemp1204 = (0.070207286499999993 * fTemp102);
			double fTemp1205 = (fConst193 * (((fTemp1198 + fTemp1199) + fTemp1200) - (fTemp1201 + (fTemp1202 + (fTemp1203 + fTemp1204)))));
			double fTemp1206 = (fConst194 * fRec1612[1]);
			double fTemp1207 = (fConst195 * fRec1615[1]);
			fRec1617[0] = (fTemp1205 + (fTemp1206 + (fRec1617[1] + fTemp1207)));
			fRec1615[0] = fRec1617[0];
			double fRec1616 = ((fTemp1207 + fTemp1206) + fTemp1205);
			fRec1614[0] = (fRec1615[0] + fRec1614[1]);
			fRec1612[0] = fRec1614[0];
			double fRec1613 = fRec1616;
			fRec1611[0] = (fTemp1197 + (fRec1613 + fRec1611[1]));
			fRec1609[0] = fRec1611[0];
			double fRec1610 = (fRec1613 + fTemp1197);
			double fTemp1208 = (0.0318087939 * fTemp109);
			double fTemp1209 = (0.067913489199999996 * fTemp113);
			double fTemp1210 = (0.0180981422 * fTemp111);
			double fTemp1211 = (fConst197 * ((fTemp1208 + fTemp1209) - fTemp1210));
			double fTemp1212 = (fConst198 * fRec1618[1]);
			fRec1620[0] = (fTemp1211 + (fRec1620[1] + fTemp1212));
			fRec1618[0] = fRec1620[0];
			double fRec1619 = (fTemp1212 + fTemp1211);
			double fTemp1213 = (0.080890343200000006 * fTemp119);
			double fTemp1214 = (0.076322479299999996 * fTemp125);
			double fTemp1215 = (0.016712360999999998 * fTemp123);
			double fTemp1216 = (0.028250734499999999 * fTemp117);
			double fTemp1217 = (0.046023916800000002 * fTemp121);
			double fTemp1218 = (fConst200 * ((fTemp1213 + fTemp1214) - (fTemp1215 + (fTemp1216 + fTemp1217))));
			double fTemp1219 = (fConst201 * fRec1621[1]);
			double fTemp1220 = (fConst202 * fRec1624[1]);
			fRec1626[0] = (fTemp1218 + (fTemp1219 + (fRec1626[1] + fTemp1220)));
			fRec1624[0] = fRec1626[0];
			double fRec1625 = ((fTemp1220 + fTemp1219) + fTemp1218);
			fRec1623[0] = (fRec1624[0] + fRec1623[1]);
			fRec1621[0] = fRec1623[0];
			double fRec1622 = fRec1625;
			fVec24[0] = (fTemp1145 + (fRec1565 + (fRec1583 + (fRec1598 + (fRec1610 + (fRec1619 + fRec1622))))));
			output24[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec24[iConst203])));
			double fTemp1221 = (fConst184 * fRec1627[1]);
			double fTemp1222 = (fConst185 * fRec1630[1]);
			double fTemp1223 = (0.14054161200000001 * fTemp82);
			double fTemp1224 = (0.079963793599999999 * fTemp80);
			double fTemp1225 = (7.6349000000000004e-06 * fTemp74);
			double fTemp1226 = (0.0001077967 * fTemp70);
			double fTemp1227 = (fConst187 * ((fTemp1188 + (fTemp1223 + (fTemp1187 + (fTemp1224 + (fTemp1190 + (fTemp1185 + fTemp1225)))))) - (fTemp1193 + fTemp1226)));
			double fTemp1228 = (fConst188 * fRec1633[1]);
			double fTemp1229 = (fConst189 * fRec1636[1]);
			fRec1638[0] = (fTemp1227 + (fTemp1228 + (fRec1638[1] + fTemp1229)));
			fRec1636[0] = fRec1638[0];
			double fRec1637 = ((fTemp1229 + fTemp1228) + fTemp1227);
			fRec1635[0] = (fRec1636[0] + fRec1635[1]);
			fRec1633[0] = fRec1635[0];
			double fRec1634 = fRec1637;
			fRec1632[0] = (fTemp1221 + (fTemp1222 + (fRec1634 + fRec1632[1])));
			fRec1630[0] = fRec1632[0];
			double fRec1631 = (fTemp1221 + (fRec1634 + fTemp1222));
			fRec1629[0] = (fRec1630[0] + fRec1629[1]);
			fRec1627[0] = fRec1629[0];
			double fRec1628 = fRec1631;
			double fTemp1230 = (fConst191 * fRec1639[1]);
			double fTemp1231 = (0.1233942308 * fTemp102);
			double fTemp1232 = (0.070207286499999993 * fTemp98);
			double fTemp1233 = (3.8474599999999999e-05 * fTemp92);
			double fTemp1234 = (8.8789999999999992e-06 * fTemp104);
			double fTemp1235 = (fConst193 * ((fTemp1202 + (fTemp1231 + (fTemp1200 + (fTemp1203 + fTemp1232)))) - (fTemp1233 + fTemp1234)));
			double fTemp1236 = (fConst194 * fRec1642[1]);
			double fTemp1237 = (fConst195 * fRec1645[1]);
			fRec1647[0] = (fTemp1235 + (fTemp1236 + (fRec1647[1] + fTemp1237)));
			fRec1645[0] = fRec1647[0];
			double fRec1646 = ((fTemp1237 + fTemp1236) + fTemp1235);
			fRec1644[0] = (fRec1645[0] + fRec1644[1]);
			fRec1642[0] = fRec1644[0];
			double fRec1643 = fRec1646;
			fRec1641[0] = (fTemp1230 + (fRec1643 + fRec1641[1]));
			fRec1639[0] = fRec1641[0];
			double fRec1640 = (fRec1643 + fTemp1230);
			double fTemp1238 = (0.046023916800000002 * fTemp119);
			double fTemp1239 = (0.080890343200000006 * fTemp121);
			double fTemp1240 = (fConst200 * (fTemp1215 + ((fTemp1214 + (fTemp1216 + fTemp1238)) + fTemp1239)));
			double fTemp1241 = (fConst201 * fRec1648[1]);
			double fTemp1242 = (fConst202 * fRec1651[1]);
			fRec1653[0] = (fTemp1240 + (fTemp1241 + (fRec1653[1] + fTemp1242)));
			fRec1651[0] = fRec1653[0];
			double fRec1652 = ((fTemp1242 + fTemp1241) + fTemp1240);
			fRec1650[0] = (fRec1651[0] + fRec1650[1]);
			fRec1648[0] = fRec1650[0];
			double fRec1649 = fRec1652;
			double fTemp1243 = (0.0180981422 * fTemp109);
			double fTemp1244 = (0.0318087939 * fTemp111);
			double fTemp1245 = (fConst197 * ((fTemp1209 + fTemp1243) + fTemp1244));
			double fTemp1246 = (fConst198 * fRec1654[1]);
			fRec1656[0] = (fTemp1245 + (fRec1656[1] + fTemp1246));
			fRec1654[0] = fRec1656[0];
			double fRec1655 = (fTemp1246 + fTemp1245);
			double fTemp1247 = (fConst175 * fRec1657[1]);
			double fTemp1248 = (fConst177 * fRec1660[1]);
			double fTemp1249 = (fConst178 * fRec1663[1]);
			double fTemp1250 = (0.073090988400000001 * fTemp47);
			double fTemp1251 = (0.1284615754 * fTemp51);
			double fTemp1252 = (0.0001686607 * fTemp63);
			double fTemp1253 = (8.5435900000000006e-05 * fTemp43);
			double fTemp1254 = (0.00013197449999999999 * fTemp53);
			double fTemp1255 = (1.9106400000000001e-05 * fTemp59);
			double fTemp1256 = (fConst180 * ((fTemp1175 + (((fTemp1169 + fTemp1178) + fTemp1250) + fTemp1251)) - (fTemp1252 + (fTemp1173 + ((fTemp1179 + (fTemp1253 + fTemp1254)) + fTemp1255)))));
			double fTemp1257 = (fConst181 * fRec1666[1]);
			double fTemp1258 = (fConst182 * fRec1669[1]);
			fRec1671[0] = (fTemp1256 + (fTemp1257 + (fRec1671[1] + fTemp1258)));
			fRec1669[0] = fRec1671[0];
			double fRec1670 = ((fTemp1258 + fTemp1257) + fTemp1256);
			fRec1668[0] = (fRec1669[0] + fRec1668[1]);
			fRec1666[0] = fRec1668[0];
			double fRec1667 = fRec1670;
			fRec1665[0] = (fTemp1248 + (fTemp1249 + (fRec1667 + fRec1665[1])));
			fRec1663[0] = fRec1665[0];
			double fRec1664 = (fTemp1248 + (fRec1667 + fTemp1249));
			fRec1662[0] = (fRec1663[0] + fRec1662[1]);
			fRec1660[0] = fRec1662[0];
			double fRec1661 = fRec1664;
			fRec1659[0] = (fTemp1247 + (fRec1661 + fRec1659[1]));
			fRec1657[0] = fRec1659[0];
			double fRec1658 = (fRec1661 + fTemp1247);
			double fTemp1259 = (fConst165 * fRec1672[1]);
			double fTemp1260 = (fConst166 * fRec1675[1]);
			double fTemp1261 = (fConst168 * fRec1678[1]);
			double fTemp1262 = (fConst169 * fRec1681[1]);
			double fTemp1263 = (2.16913e-05 * fTemp29);
			double fTemp1264 = (0.083437284900000006 * fTemp19);
			double fTemp1265 = (0.047473814699999999 * fTemp15);
			double fTemp1266 = (0.00024519039999999998 * fTemp11);
			double fTemp1267 = (0.00041699590000000001 * fTemp33);
			double fTemp1268 = (0.0001242177 * fTemp23);
			double fTemp1269 = (fConst171 * (((fTemp1263 + (fTemp1158 + (fTemp1264 + (fTemp1265 + (fTemp1161 + (fTemp1152 + fTemp1266)))))) + fTemp1267) - (fTemp1154 + (fTemp1156 + (fTemp1162 + (fTemp1150 + fTemp1268))))));
			double fTemp1270 = (fConst172 * fRec1684[1]);
			double fTemp1271 = (fConst173 * fRec1687[1]);
			fRec1689[0] = (fTemp1269 + (fTemp1270 + (fRec1689[1] + fTemp1271)));
			fRec1687[0] = fRec1689[0];
			double fRec1688 = ((fTemp1271 + fTemp1270) + fTemp1269);
			fRec1686[0] = (fRec1687[0] + fRec1686[1]);
			fRec1684[0] = fRec1686[0];
			double fRec1685 = fRec1688;
			fRec1683[0] = (fTemp1261 + (fTemp1262 + (fRec1685 + fRec1683[1])));
			fRec1681[0] = fRec1683[0];
			double fRec1682 = (fTemp1261 + (fRec1685 + fTemp1262));
			fRec1680[0] = (fRec1681[0] + fRec1680[1]);
			fRec1678[0] = fRec1680[0];
			double fRec1679 = fRec1682;
			fRec1677[0] = (fTemp1259 + (fTemp1260 + (fRec1679 + fRec1677[1])));
			fRec1675[0] = fRec1677[0];
			double fRec1676 = (fTemp1259 + (fRec1679 + fTemp1260));
			fRec1674[0] = (fRec1675[0] + fRec1674[1]);
			fRec1672[0] = fRec1674[0];
			double fRec1673 = fRec1676;
			fVec25[0] = (fTemp1145 + (fRec1628 + (fRec1640 + (fRec1649 + (fRec1655 + (fRec1658 + fRec1673))))));
			output25[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec25[iConst203])));
			double fTemp1272 = (fConst165 * fRec1690[1]);
			double fTemp1273 = (fConst166 * fRec1693[1]);
			double fTemp1274 = (fConst168 * fRec1696[1]);
			double fTemp1275 = (fConst169 * fRec1699[1]);
			double fTemp1276 = (fConst171 * ((fTemp1154 + (fTemp1155 + (fTemp1157 + (fTemp1159 + (fTemp1160 + (fTemp1150 + fTemp1152)))))) - (fTemp1156 + (fTemp1158 + (fTemp1162 + (fTemp1153 + (fTemp1151 + fTemp1161)))))));
			double fTemp1277 = (fConst172 * fRec1702[1]);
			double fTemp1278 = (fConst173 * fRec1705[1]);
			fRec1707[0] = (fTemp1276 + (fTemp1277 + (fRec1707[1] + fTemp1278)));
			fRec1705[0] = fRec1707[0];
			double fRec1706 = ((fTemp1278 + fTemp1277) + fTemp1276);
			fRec1704[0] = (fRec1705[0] + fRec1704[1]);
			fRec1702[0] = fRec1704[0];
			double fRec1703 = fRec1706;
			fRec1701[0] = (fTemp1274 + (fTemp1275 + (fRec1703 + fRec1701[1])));
			fRec1699[0] = fRec1701[0];
			double fRec1700 = (fTemp1274 + (fRec1703 + fTemp1275));
			fRec1698[0] = (fRec1699[0] + fRec1698[1]);
			fRec1696[0] = fRec1698[0];
			double fRec1697 = fRec1700;
			fRec1695[0] = (fTemp1272 + (fTemp1273 + (fRec1697 + fRec1695[1])));
			fRec1693[0] = fRec1695[0];
			double fRec1694 = (fTemp1272 + (fRec1697 + fTemp1273));
			fRec1692[0] = (fRec1693[0] + fRec1692[1]);
			fRec1690[0] = fRec1692[0];
			double fRec1691 = fRec1694;
			double fTemp1279 = (fConst175 * fRec1708[1]);
			double fTemp1280 = (fConst177 * fRec1711[1]);
			double fTemp1281 = (fConst178 * fRec1714[1]);
			double fTemp1282 = (fConst180 * ((fTemp1174 + (fTemp1176 + (fTemp1177 + fTemp1169))) - (fTemp1172 + (fTemp1173 + (fTemp1175 + (fTemp1179 + (fTemp1171 + (fTemp1170 + fTemp1178))))))));
			double fTemp1283 = (fConst181 * fRec1717[1]);
			double fTemp1284 = (fConst182 * fRec1720[1]);
			fRec1722[0] = (fTemp1282 + (fTemp1283 + (fRec1722[1] + fTemp1284)));
			fRec1720[0] = fRec1722[0];
			double fRec1721 = ((fTemp1284 + fTemp1283) + fTemp1282);
			fRec1719[0] = (fRec1720[0] + fRec1719[1]);
			fRec1717[0] = fRec1719[0];
			double fRec1718 = fRec1721;
			fRec1716[0] = (fTemp1280 + (fTemp1281 + (fRec1718 + fRec1716[1])));
			fRec1714[0] = fRec1716[0];
			double fRec1715 = (fTemp1280 + (fRec1718 + fTemp1281));
			fRec1713[0] = (fRec1714[0] + fRec1713[1]);
			fRec1711[0] = fRec1713[0];
			double fRec1712 = fRec1715;
			fRec1710[0] = (fTemp1279 + (fRec1712 + fRec1710[1]));
			fRec1708[0] = fRec1710[0];
			double fRec1709 = (fRec1712 + fTemp1279);
			double fTemp1285 = (fConst184 * fRec1723[1]);
			double fTemp1286 = (fConst185 * fRec1726[1]);
			double fTemp1287 = (fConst187 * ((fTemp1189 + (fTemp1187 + (fTemp1191 + (fTemp1185 + fTemp1192)))) - (fTemp1188 + (fTemp1186 + (fTemp1190 + fTemp1193)))));
			double fTemp1288 = (fConst188 * fRec1729[1]);
			double fTemp1289 = (fConst189 * fRec1732[1]);
			fRec1734[0] = (fTemp1287 + (fTemp1288 + (fRec1734[1] + fTemp1289)));
			fRec1732[0] = fRec1734[0];
			double fRec1733 = ((fTemp1289 + fTemp1288) + fTemp1287);
			fRec1731[0] = (fRec1732[0] + fRec1731[1]);
			fRec1729[0] = fRec1731[0];
			double fRec1730 = fRec1733;
			fRec1728[0] = (fTemp1285 + (fTemp1286 + (fRec1730 + fRec1728[1])));
			fRec1726[0] = fRec1728[0];
			double fRec1727 = (fTemp1285 + (fRec1730 + fTemp1286));
			fRec1725[0] = (fRec1726[0] + fRec1725[1]);
			fRec1723[0] = fRec1725[0];
			double fRec1724 = fRec1727;
			double fTemp1290 = (fConst191 * fRec1735[1]);
			double fTemp1291 = (fConst193 * ((fTemp1201 + (fTemp1200 + fTemp1204)) - (fTemp1202 + (fTemp1199 + (fTemp1198 + fTemp1203)))));
			double fTemp1292 = (fConst194 * fRec1738[1]);
			double fTemp1293 = (fConst195 * fRec1741[1]);
			fRec1743[0] = (fTemp1291 + (fTemp1292 + (fRec1743[1] + fTemp1293)));
			fRec1741[0] = fRec1743[0];
			double fRec1742 = ((fTemp1293 + fTemp1292) + fTemp1291);
			fRec1740[0] = (fRec1741[0] + fRec1740[1]);
			fRec1738[0] = fRec1740[0];
			double fRec1739 = fRec1742;
			fRec1737[0] = (fTemp1290 + (fRec1739 + fRec1737[1]));
			fRec1735[0] = fRec1737[0];
			double fRec1736 = (fRec1739 + fTemp1290);
			double fTemp1294 = (fConst197 * ((fTemp1209 + fTemp1210) - fTemp1208));
			double fTemp1295 = (fConst198 * fRec1744[1]);
			fRec1746[0] = (fTemp1294 + (fRec1746[1] + fTemp1295));
			fRec1744[0] = fRec1746[0];
			double fRec1745 = (fTemp1295 + fTemp1294);
			double fTemp1296 = (fConst200 * ((fTemp1214 + fTemp1217) - (fTemp1215 + (fTemp1216 + fTemp1213))));
			double fTemp1297 = (fConst201 * fRec1747[1]);
			double fTemp1298 = (fConst202 * fRec1750[1]);
			fRec1752[0] = (fTemp1296 + (fTemp1297 + (fRec1752[1] + fTemp1298)));
			fRec1750[0] = fRec1752[0];
			double fRec1751 = ((fTemp1298 + fTemp1297) + fTemp1296);
			fRec1749[0] = (fRec1750[0] + fRec1749[1]);
			fRec1747[0] = fRec1749[0];
			double fRec1748 = fRec1751;
			fVec26[0] = (fTemp1145 + (fRec1691 + (fRec1709 + (fRec1724 + (fRec1736 + (fRec1745 + fRec1748))))));
			output26[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec26[iConst203])));
			double fTemp1299 = (fConst165 * fRec1753[1]);
			double fTemp1300 = (fConst166 * fRec1756[1]);
			double fTemp1301 = (fConst168 * fRec1759[1]);
			double fTemp1302 = (fConst169 * fRec1762[1]);
			double fTemp1303 = (fConst171 * ((fTemp1158 + (fTemp1161 + (fTemp1152 + fTemp1268))) - (fTemp1154 + (fTemp1267 + (fTemp1156 + (fTemp1263 + (fTemp1264 + (fTemp1162 + (fTemp1265 + (fTemp1150 + fTemp1266))))))))));
			double fTemp1304 = (fConst172 * fRec1765[1]);
			double fTemp1305 = (fConst173 * fRec1768[1]);
			fRec1770[0] = (fTemp1303 + (fTemp1304 + (fRec1770[1] + fTemp1305)));
			fRec1768[0] = fRec1770[0];
			double fRec1769 = ((fTemp1305 + fTemp1304) + fTemp1303);
			fRec1767[0] = (fRec1768[0] + fRec1767[1]);
			fRec1765[0] = fRec1767[0];
			double fRec1766 = fRec1769;
			fRec1764[0] = (fTemp1301 + (fTemp1302 + (fRec1766 + fRec1764[1])));
			fRec1762[0] = fRec1764[0];
			double fRec1763 = (fTemp1301 + (fRec1766 + fTemp1302));
			fRec1761[0] = (fRec1762[0] + fRec1761[1]);
			fRec1759[0] = fRec1761[0];
			double fRec1760 = fRec1763;
			fRec1758[0] = (fTemp1299 + (fTemp1300 + (fRec1760 + fRec1758[1])));
			fRec1756[0] = fRec1758[0];
			double fRec1757 = (fTemp1299 + (fRec1760 + fTemp1300));
			fRec1755[0] = (fRec1756[0] + fRec1755[1]);
			fRec1753[0] = fRec1755[0];
			double fRec1754 = fRec1757;
			double fTemp1306 = (fConst175 * fRec1771[1]);
			double fTemp1307 = (fConst177 * fRec1774[1]);
			double fTemp1308 = (fConst178 * fRec1777[1]);
			double fTemp1309 = (fConst180 * ((fTemp1252 + (fTemp1255 + (fTemp1175 + (fTemp1178 + (fTemp1254 + (fTemp1169 + fTemp1253)))))) - (fTemp1173 + (fTemp1251 + (fTemp1179 + fTemp1250)))));
			double fTemp1310 = (fConst181 * fRec1780[1]);
			double fTemp1311 = (fConst182 * fRec1783[1]);
			fRec1785[0] = (fTemp1309 + (fTemp1310 + (fRec1785[1] + fTemp1311)));
			fRec1783[0] = fRec1785[0];
			double fRec1784 = ((fTemp1311 + fTemp1310) + fTemp1309);
			fRec1782[0] = (fRec1783[0] + fRec1782[1]);
			fRec1780[0] = fRec1782[0];
			double fRec1781 = fRec1784;
			fRec1779[0] = (fTemp1307 + (fTemp1308 + (fRec1781 + fRec1779[1])));
			fRec1777[0] = fRec1779[0];
			double fRec1778 = (fTemp1307 + (fRec1781 + fTemp1308));
			fRec1776[0] = (fRec1777[0] + fRec1776[1]);
			fRec1774[0] = fRec1776[0];
			double fRec1775 = fRec1778;
			fRec1773[0] = (fTemp1306 + (fRec1775 + fRec1773[1]));
			fRec1771[0] = fRec1773[0];
			double fRec1772 = (fRec1775 + fTemp1306);
			double fTemp1312 = (fConst184 * fRec1786[1]);
			double fTemp1313 = (fConst185 * fRec1789[1]);
			double fTemp1314 = (fConst187 * ((fTemp1188 + (fTemp1187 + (fTemp1190 + (fTemp1185 + fTemp1226)))) - (fTemp1223 + (fTemp1224 + (fTemp1193 + fTemp1225)))));
			double fTemp1315 = (fConst188 * fRec1792[1]);
			double fTemp1316 = (fConst189 * fRec1795[1]);
			fRec1797[0] = (fTemp1314 + (fTemp1315 + (fRec1797[1] + fTemp1316)));
			fRec1795[0] = fRec1797[0];
			double fRec1796 = ((fTemp1316 + fTemp1315) + fTemp1314);
			fRec1794[0] = (fRec1795[0] + fRec1794[1]);
			fRec1792[0] = fRec1794[0];
			double fRec1793 = fRec1796;
			fRec1791[0] = (fTemp1312 + (fTemp1313 + (fRec1793 + fRec1791[1])));
			fRec1789[0] = fRec1791[0];
			double fRec1790 = (fTemp1312 + (fRec1793 + fTemp1313));
			fRec1788[0] = (fRec1789[0] + fRec1788[1]);
			fRec1786[0] = fRec1788[0];
			double fRec1787 = fRec1790;
			double fTemp1317 = (fConst191 * fRec1798[1]);
			double fTemp1318 = (fConst193 * ((fTemp1234 + (fTemp1202 + (fTemp1200 + (fTemp1203 + fTemp1233)))) - (fTemp1232 + fTemp1231)));
			double fTemp1319 = (fConst194 * fRec1801[1]);
			double fTemp1320 = (fConst195 * fRec1804[1]);
			fRec1806[0] = (fTemp1318 + (fTemp1319 + (fRec1806[1] + fTemp1320)));
			fRec1804[0] = fRec1806[0];
			double fRec1805 = ((fTemp1320 + fTemp1319) + fTemp1318);
			fRec1803[0] = (fRec1804[0] + fRec1803[1]);
			fRec1801[0] = fRec1803[0];
			double fRec1802 = fRec1805;
			fRec1800[0] = (fTemp1317 + (fRec1802 + fRec1800[1]));
			fRec1798[0] = fRec1800[0];
			double fRec1799 = (fRec1802 + fTemp1317);
			double fTemp1321 = (fConst197 * (fTemp1209 - (fTemp1243 + fTemp1244)));
			double fTemp1322 = (fConst198 * fRec1807[1]);
			fRec1809[0] = (fTemp1321 + (fRec1809[1] + fTemp1322));
			fRec1807[0] = fRec1809[0];
			double fRec1808 = (fTemp1322 + fTemp1321);
			double fTemp1323 = (fConst200 * ((fTemp1215 + (fTemp1216 + fTemp1214)) - (fTemp1238 + fTemp1239)));
			double fTemp1324 = (fConst201 * fRec1810[1]);
			double fTemp1325 = (fConst202 * fRec1813[1]);
			fRec1815[0] = (fTemp1323 + (fTemp1324 + (fRec1815[1] + fTemp1325)));
			fRec1813[0] = fRec1815[0];
			double fRec1814 = ((fTemp1325 + fTemp1324) + fTemp1323);
			fRec1812[0] = (fRec1813[0] + fRec1812[1]);
			fRec1810[0] = fRec1812[0];
			double fRec1811 = fRec1814;
			fVec27[0] = (fTemp1145 + (fRec1754 + (fRec1772 + (fRec1787 + (fRec1799 + (fRec1808 + fRec1811))))));
			output27[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec27[iConst203])));
			double fTemp1326 = (fConst205 * fRec1831[1]);
			double fTemp1327 = (fConst206 * fRec1828[1]);
			double fTemp1328 = (fConst209 * (((0.18173183640000001 * fTemp17) + (0.0147009992 * fTemp31)) - (0.012481667599999999 * fTemp13)));
			fRec1833[0] = (((fRec1833[1] + fTemp1326) + fTemp1327) + fTemp1328);
			fRec1831[0] = fRec1833[0];
			double fRec1832 = ((fTemp1326 + fTemp1327) + fTemp1328);
			fRec1830[0] = (fRec1831[0] + fRec1830[1]);
			fRec1828[0] = fRec1830[0];
			double fRec1829 = fRec1832;
			double fTemp1329 = (fConst210 * fRec1825[1]);
			double fTemp1330 = (fConst211 * fRec1822[1]);
			fRec1827[0] = (((fRec1829 + fRec1827[1]) + fTemp1329) + fTemp1330);
			fRec1825[0] = fRec1827[0];
			double fRec1826 = ((fRec1829 + fTemp1329) + fTemp1330);
			fRec1824[0] = (fRec1825[0] + fRec1824[1]);
			fRec1822[0] = fRec1824[0];
			double fRec1823 = fRec1826;
			double fTemp1331 = (fConst212 * fRec1819[1]);
			double fTemp1332 = (fConst213 * fRec1816[1]);
			fRec1821[0] = (((fRec1823 + fRec1821[1]) + fTemp1331) + fTemp1332);
			fRec1819[0] = fRec1821[0];
			double fRec1820 = ((fRec1823 + fTemp1331) + fTemp1332);
			fRec1818[0] = (fRec1819[0] + fRec1818[1]);
			fRec1816[0] = fRec1818[0];
			double fRec1817 = fRec1820;
			double fTemp1333 = (fConst215 * fRec1834[1]);
			double fTemp1334 = (fConst217 * fRec1837[1]);
			double fTemp1335 = (fConst218 * fRec1840[1]);
			double fTemp1336 = (fConst220 * (((0.2299521259 * fTemp49) + (0.014825174599999999 * fTemp61)) - (0.011308703599999999 * fTemp45)));
			double fTemp1337 = (fConst221 * fRec1843[1]);
			double fTemp1338 = (fConst222 * fRec1846[1]);
			fRec1848[0] = (fTemp1336 + (fTemp1337 + (fRec1848[1] + fTemp1338)));
			fRec1846[0] = fRec1848[0];
			double fRec1847 = ((fTemp1338 + fTemp1337) + fTemp1336);
			fRec1845[0] = (fRec1846[0] + fRec1845[1]);
			fRec1843[0] = fRec1845[0];
			double fRec1844 = fRec1847;
			fRec1842[0] = (fTemp1334 + (fTemp1335 + (fRec1844 + fRec1842[1])));
			fRec1840[0] = fRec1842[0];
			double fRec1841 = (fTemp1334 + (fRec1844 + fTemp1335));
			fRec1839[0] = (fRec1840[0] + fRec1839[1]);
			fRec1837[0] = fRec1839[0];
			double fRec1838 = fRec1841;
			fRec1836[0] = (fTemp1333 + (fRec1838 + fRec1836[1]));
			fRec1834[0] = fRec1836[0];
			double fRec1835 = (fRec1838 + fTemp1333);
			double fTemp1339 = (fConst224 * fRec1849[1]);
			double fTemp1340 = (fConst225 * fRec1852[1]);
			double fTemp1341 = (fConst227 * (((0.14317966709999999 * fTemp72) + (0.0036239642 * fTemp76)) - (0.0017354123000000001 * fTemp68)));
			double fTemp1342 = (fConst228 * fRec1855[1]);
			double fTemp1343 = (fConst229 * fRec1858[1]);
			fRec1860[0] = (fTemp1341 + (fTemp1342 + (fRec1860[1] + fTemp1343)));
			fRec1858[0] = fRec1860[0];
			double fRec1859 = ((fTemp1343 + fTemp1342) + fTemp1341);
			fRec1857[0] = (fRec1858[0] + fRec1857[1]);
			fRec1855[0] = fRec1857[0];
			double fRec1856 = fRec1859;
			fRec1854[0] = (fTemp1339 + (fTemp1340 + (fRec1856 + fRec1854[1])));
			fRec1852[0] = fRec1854[0];
			double fRec1853 = (fTemp1339 + (fRec1856 + fTemp1340));
			fRec1851[0] = (fRec1852[0] + fRec1851[1]);
			fRec1849[0] = fRec1851[0];
			double fRec1850 = fRec1853;
			double fTemp1344 = (fConst231 * fRec1861[1]);
			double fTemp1345 = (fConst233 * fTemp100);
			double fTemp1346 = (fConst234 * fRec1864[1]);
			double fTemp1347 = (fConst235 * fRec1867[1]);
			fRec1869[0] = (fTemp1345 + (fTemp1346 + (fRec1869[1] + fTemp1347)));
			fRec1867[0] = fRec1869[0];
			double fRec1868 = ((fTemp1347 + fTemp1346) + fTemp1345);
			fRec1866[0] = (fRec1867[0] + fRec1866[1]);
			fRec1864[0] = fRec1866[0];
			double fRec1865 = fRec1868;
			fRec1863[0] = (fTemp1344 + (fRec1865 + fRec1863[1]));
			fRec1861[0] = fRec1863[0];
			double fRec1862 = (fRec1865 + fTemp1344);
			double fTemp1348 = (fConst237 * fTemp113);
			double fTemp1349 = (fConst238 * fRec1870[1]);
			fRec1872[0] = (fTemp1348 + (fRec1872[1] + fTemp1349));
			fRec1870[0] = fRec1872[0];
			double fRec1871 = (fTemp1349 + fTemp1348);
			double fTemp1350 = (fConst240 * fTemp125);
			double fTemp1351 = (fConst241 * fRec1873[1]);
			double fTemp1352 = (fConst242 * fRec1876[1]);
			fRec1878[0] = (fTemp1350 + (fTemp1351 + (fRec1878[1] + fTemp1352)));
			fRec1876[0] = fRec1878[0];
			double fRec1877 = ((fTemp1352 + fTemp1351) + fTemp1350);
			fRec1875[0] = (fRec1876[0] + fRec1875[1]);
			fRec1873[0] = fRec1875[0];
			double fRec1874 = fRec1877;
			output28[i] = FAUSTFLOAT((fRec0[0] * ((fRec1817 + (fRec1835 + (fRec1850 + (fRec1862 + (fRec1871 + fRec1874))))) - (0.011127189500000001 * fTemp130))));
			double fTemp1353 = (0.0151950364 * fTemp130);
			double fTemp1354 = (0.024877433099999999 * fTemp109);
			double fTemp1355 = (0.0095926594 * fTemp113);
			double fTemp1356 = (0.026616915599999999 * fTemp111);
			double fTemp1357 = (fConst244 * ((fTemp1354 + fTemp1355) + fTemp1356));
			double fTemp1358 = (fConst245 * fRec1879[1]);
			fRec1881[0] = (fTemp1357 + (fRec1881[1] + fTemp1358));
			fRec1879[0] = fRec1881[0];
			double fRec1880 = (fTemp1358 + fTemp1357);
			double fTemp1359 = (0.045051396299999998 * fTemp117);
			double fTemp1360 = (3.60956e-05 * fTemp123);
			double fTemp1361 = (0.0085538755000000005 * fTemp119);
			double fTemp1362 = (0.0091925957000000003 * fTemp125);
			double fTemp1363 = (0.014551550999999999 * fTemp121);
			double fTemp1364 = (fConst247 * ((fTemp1359 + fTemp1360) - ((fTemp1361 + fTemp1362) + fTemp1363)));
			double fTemp1365 = (fConst248 * fRec1882[1]);
			double fTemp1366 = (fConst249 * fRec1885[1]);
			fRec1887[0] = (fTemp1364 + (fTemp1365 + (fRec1887[1] + fTemp1366)));
			fRec1885[0] = fRec1887[0];
			double fRec1886 = ((fTemp1366 + fTemp1365) + fTemp1364);
			fRec1884[0] = (fRec1884[1] + fRec1885[0]);
			fRec1882[0] = fRec1884[0];
			double fRec1883 = fRec1886;
			double fTemp1367 = (fConst251 * fRec1888[1]);
			double fTemp1368 = (0.0686175542 * fTemp92);
			double fTemp1369 = (0.0217008632 * fTemp100);
			double fTemp1370 = (0.038907956 * fTemp104);
			double fTemp1371 = (0.010274810699999999 * fTemp96);
			double fTemp1372 = (0.0019806858000000001 * fTemp94);
			double fTemp1373 = (0.0263719044 * fTemp98);
			double fTemp1374 = (0.037469102499999997 * fTemp102);
			double fTemp1375 = (fConst253 * ((fTemp1368 + fTemp1369) - (fTemp1370 + (fTemp1371 + ((fTemp1372 + fTemp1373) + fTemp1374)))));
			double fTemp1376 = (fConst254 * fRec1891[1]);
			double fTemp1377 = (fConst255 * fRec1894[1]);
			fRec1896[0] = (fTemp1375 + (fTemp1376 + (fRec1896[1] + fTemp1377)));
			fRec1894[0] = fRec1896[0];
			double fRec1895 = ((fTemp1377 + fTemp1376) + fTemp1375);
			fRec1893[0] = (fRec1893[1] + fRec1894[0]);
			fRec1891[0] = fRec1893[0];
			double fRec1892 = fRec1895;
			fRec1890[0] = ((fRec1890[1] + fTemp1367) + fRec1892);
			fRec1888[0] = fRec1890[0];
			double fRec1889 = (fTemp1367 + fRec1892);
			double fTemp1378 = (fConst257 * fRec1897[1]);
			double fTemp1379 = (fConst258 * fRec1900[1]);
			double fTemp1380 = (0.025473697300000001 * fTemp82);
			double fTemp1381 = (0.028501309999999998 * fTemp72);
			double fTemp1382 = (0.029518910499999999 * fTemp80);
			double fTemp1383 = (0.0040835461999999996 * fTemp68);
			double fTemp1384 = (0.0184232654 * fTemp74);
			double fTemp1385 = (0.025691820399999999 * fTemp84);
			double fTemp1386 = (0.027792998999999999 * fTemp78);
			double fTemp1387 = (0.014744688299999999 * fTemp70);
			double fTemp1388 = (0.034069885500000001 * fTemp76);
			double fTemp1389 = (fConst260 * ((fTemp1380 + (fTemp1381 + (fTemp1382 + (fTemp1383 + fTemp1384)))) - (fTemp1385 + (fTemp1386 + (fTemp1387 + fTemp1388)))));
			double fTemp1390 = (fConst261 * fRec1903[1]);
			double fTemp1391 = (fConst262 * fRec1906[1]);
			fRec1908[0] = (fTemp1389 + (fTemp1390 + (fRec1908[1] + fTemp1391)));
			fRec1906[0] = fRec1908[0];
			double fRec1907 = ((fTemp1391 + fTemp1390) + fTemp1389);
			fRec1905[0] = (fRec1905[1] + fRec1906[0]);
			fRec1903[0] = fRec1905[0];
			double fRec1904 = fRec1907;
			fRec1902[0] = ((fTemp1378 + (fRec1902[1] + fTemp1379)) + fRec1904);
			fRec1900[0] = fRec1902[0];
			double fRec1901 = ((fTemp1379 + fTemp1378) + fRec1904);
			fRec1899[0] = (fRec1899[1] + fRec1900[0]);
			fRec1897[0] = fRec1899[0];
			double fRec1898 = fRec1901;
			double fTemp1392 = (fConst264 * fRec1909[1]);
			double fTemp1393 = (fConst266 * fRec1912[1]);
			double fTemp1394 = (fConst267 * fRec1915[1]);
			double fTemp1395 = (0.1097010387 * fTemp61);
			double fTemp1396 = (0.049705542999999998 * fTemp55);
			double fTemp1397 = (0.0302883436 * fTemp47);
			double fTemp1398 = (0.027231439999999999 * fTemp51);
			double fTemp1399 = (0.023095824000000001 * fTemp59);
			double fTemp1400 = (0.017252402600000001 * fTemp43);
			double fTemp1401 = (0.060138381900000003 * fTemp45);
			double fTemp1402 = (0.0173945821 * fTemp53);
			double fTemp1403 = (0.042459960599999999 * fTemp49);
			double fTemp1404 = (0.0290988275 * fTemp57);
			double fTemp1405 = (0.042130927300000003 * fTemp63);
			double fTemp1406 = (fConst269 * ((fTemp1395 + (((fTemp1396 + fTemp1397) + fTemp1398) + fTemp1399)) - (((((fTemp1400 + fTemp1401) + fTemp1402) + fTemp1403) + fTemp1404) + fTemp1405)));
			double fTemp1407 = (fConst270 * fRec1918[1]);
			double fTemp1408 = (fConst271 * fRec1921[1]);
			fRec1923[0] = (fTemp1406 + (fTemp1407 + (fRec1923[1] + fTemp1408)));
			fRec1921[0] = fRec1923[0];
			double fRec1922 = ((fTemp1408 + fTemp1407) + fTemp1406);
			fRec1920[0] = (fRec1920[1] + fRec1921[0]);
			fRec1918[0] = fRec1920[0];
			double fRec1919 = fRec1922;
			fRec1917[0] = ((fTemp1393 + (fRec1917[1] + fTemp1394)) + fRec1919);
			fRec1915[0] = fRec1917[0];
			double fRec1916 = ((fTemp1394 + fTemp1393) + fRec1919);
			fRec1914[0] = (fRec1914[1] + fRec1915[0]);
			fRec1912[0] = fRec1914[0];
			double fRec1913 = fRec1916;
			fRec1911[0] = ((fRec1911[1] + fTemp1392) + fRec1913);
			fRec1909[0] = fRec1911[0];
			double fRec1910 = (fTemp1392 + fRec1913);
			double fTemp1409 = (fConst273 * fRec1924[1]);
			double fTemp1410 = (fConst274 * fRec1927[1]);
			double fTemp1411 = (fConst276 * fRec1930[1]);
			double fTemp1412 = (fConst277 * fRec1933[1]);
			double fTemp1413 = (0.10324761490000001 * fTemp23);
			double fTemp1414 = (0.092812591599999994 * fTemp25);
			double fTemp1415 = (0.16560293549999999 * fTemp31);
			double fTemp1416 = (0.042995762 * fTemp35);
			double fTemp1417 = (0.0555762219 * fTemp29);
			double fTemp1418 = (0.0157411839 * fTemp27);
			double fTemp1419 = (0.064214321699999993 * fTemp19);
			double fTemp1420 = (0.077019775999999998 * fTemp17);
			double fTemp1421 = (0.091557874999999997 * fTemp21);
			double fTemp1422 = (0.016276343700000001 * fTemp11);
			double fTemp1423 = (0.077759960500000003 * fTemp13);
			double fTemp1424 = (0.052326541099999999 * fTemp15);
			double fTemp1425 = (0.033091201100000002 * fTemp33);
			double fTemp1426 = (fConst279 * (((fTemp1413 + fTemp1414) + fTemp1415) - (fTemp1416 + ((fTemp1417 + (fTemp1418 + (fTemp1419 + (fTemp1420 + (((fTemp1421 + fTemp1422) + fTemp1423) + fTemp1424))))) + fTemp1425))));
			double fTemp1427 = (fConst280 * fRec1936[1]);
			double fTemp1428 = (fConst281 * fRec1939[1]);
			fRec1941[0] = (fTemp1426 + (fTemp1427 + (fRec1941[1] + fTemp1428)));
			fRec1939[0] = fRec1941[0];
			double fRec1940 = ((fTemp1428 + fTemp1427) + fTemp1426);
			fRec1938[0] = (fRec1938[1] + fRec1939[0]);
			fRec1936[0] = fRec1938[0];
			double fRec1937 = fRec1940;
			fRec1935[0] = ((fTemp1411 + (fRec1935[1] + fTemp1412)) + fRec1937);
			fRec1933[0] = fRec1935[0];
			double fRec1934 = ((fTemp1412 + fTemp1411) + fRec1937);
			fRec1932[0] = (fRec1932[1] + fRec1933[0]);
			fRec1930[0] = fRec1932[0];
			double fRec1931 = fRec1934;
			fRec1929[0] = ((fTemp1409 + (fRec1929[1] + fTemp1410)) + fRec1931);
			fRec1927[0] = fRec1929[0];
			double fRec1928 = ((fTemp1410 + fTemp1409) + fRec1931);
			fRec1926[0] = (fRec1926[1] + fRec1927[0]);
			fRec1924[0] = fRec1926[0];
			double fRec1925 = fRec1928;
			fVec28[(IOTA & 511)] = (fTemp1353 + (((((fRec1880 + fRec1883) + fRec1889) + fRec1898) + fRec1910) + fRec1925));
			output29[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec28[((IOTA - iConst282) & 511)])));
			double fTemp1429 = (0.0142464467 * fTemp130);
			double fTemp1430 = (0.0116704111 * fTemp109);
			double fTemp1431 = (0.0072743 * fTemp113);
			double fTemp1432 = (0.036026393099999998 * fTemp111);
			double fTemp1433 = (fConst284 * ((fTemp1430 + fTemp1431) + fTemp1432));
			double fTemp1434 = (fConst285 * fRec1942[1]);
			fRec1944[0] = (fTemp1433 + (fRec1944[1] + fTemp1434));
			fRec1942[0] = fRec1944[0];
			double fRec1943 = (fTemp1434 + fTemp1433);
			double fTemp1435 = (0.017860993499999998 * fTemp117);
			double fTemp1436 = (0.032412999900000003 * fTemp123);
			double fTemp1437 = (0.0053400123000000004 * fTemp119);
			double fTemp1438 = (0.0118492489 * fTemp125);
			double fTemp1439 = (0.0134650021 * fTemp121);
			double fTemp1440 = (fConst287 * ((fTemp1435 + fTemp1436) - ((fTemp1437 + fTemp1438) + fTemp1439)));
			double fTemp1441 = (fConst288 * fRec1945[1]);
			double fTemp1442 = (fConst289 * fRec1948[1]);
			fRec1950[0] = (fTemp1440 + (fTemp1441 + (fRec1950[1] + fTemp1442)));
			fRec1948[0] = fRec1950[0];
			double fRec1949 = ((fTemp1442 + fTemp1441) + fTemp1440);
			fRec1947[0] = (fRec1947[1] + fRec1948[0]);
			fRec1945[0] = fRec1947[0];
			double fRec1946 = fRec1949;
			double fTemp1443 = (fConst291 * fRec1951[1]);
			double fTemp1444 = (0.055513575799999999 * fTemp92);
			double fTemp1445 = (0.019513342199999999 * fTemp100);
			double fTemp1446 = (0.034960143999999999 * fTemp104);
			double fTemp1447 = (0.013922485199999999 * fTemp96);
			double fTemp1448 = (0.019359382200000001 * fTemp94);
			double fTemp1449 = (0.0145304557 * fTemp98);
			double fTemp1450 = (0.039622172300000001 * fTemp102);
			double fTemp1451 = (fConst293 * (((fTemp1444 + fTemp1445) + fTemp1446) - (fTemp1447 + ((fTemp1448 + fTemp1449) + fTemp1450))));
			double fTemp1452 = (fConst294 * fRec1954[1]);
			double fTemp1453 = (fConst295 * fRec1957[1]);
			fRec1959[0] = (fTemp1451 + (fTemp1452 + (fRec1959[1] + fTemp1453)));
			fRec1957[0] = fRec1959[0];
			double fRec1958 = ((fTemp1453 + fTemp1452) + fTemp1451);
			fRec1956[0] = (fRec1956[1] + fRec1957[0]);
			fRec1954[0] = fRec1956[0];
			double fRec1955 = fRec1958;
			fRec1953[0] = ((fRec1953[1] + fTemp1443) + fRec1955);
			fRec1951[0] = fRec1953[0];
			double fRec1952 = (fTemp1443 + fRec1955);
			double fTemp1454 = (fConst297 * fRec1960[1]);
			double fTemp1455 = (fConst298 * fRec1963[1]);
			double fTemp1456 = (0.041906025 * fTemp82);
			double fTemp1457 = (0.027688681 * fTemp72);
			double fTemp1458 = (0.012583120099999999 * fTemp80);
			double fTemp1459 = (0.057620078300000002 * fTemp68);
			double fTemp1460 = (0.025620889099999999 * fTemp76);
			double fTemp1461 = (fTemp1459 + fTemp1460);
			double fTemp1462 = (0.030201173000000001 * fTemp84);
			double fTemp1463 = (0.043064454000000002 * fTemp78);
			double fTemp1464 = (0.036978276999999997 * fTemp70);
			double fTemp1465 = (0.035198028499999999 * fTemp74);
			double fTemp1466 = (fConst300 * ((fTemp1456 + (fTemp1457 + (fTemp1458 + fTemp1461))) - (fTemp1462 + (fTemp1463 + (fTemp1464 + fTemp1465)))));
			double fTemp1467 = (fConst301 * fRec1966[1]);
			double fTemp1468 = (fConst302 * fRec1969[1]);
			fRec1971[0] = (fTemp1466 + (fTemp1467 + (fRec1971[1] + fTemp1468)));
			fRec1969[0] = fRec1971[0];
			double fRec1970 = ((fTemp1468 + fTemp1467) + fTemp1466);
			fRec1968[0] = (fRec1968[1] + fRec1969[0]);
			fRec1966[0] = fRec1968[0];
			double fRec1967 = fRec1970;
			fRec1965[0] = ((fTemp1454 + (fRec1965[1] + fTemp1455)) + fRec1967);
			fRec1963[0] = fRec1965[0];
			double fRec1964 = ((fTemp1455 + fTemp1454) + fRec1967);
			fRec1962[0] = (fRec1962[1] + fRec1963[0]);
			fRec1960[0] = fRec1962[0];
			double fRec1961 = fRec1964;
			double fTemp1469 = (fConst304 * fRec1972[1]);
			double fTemp1470 = (fConst306 * fRec1975[1]);
			double fTemp1471 = (fConst307 * fRec1978[1]);
			double fTemp1472 = (0.049821346799999999 * fTemp57);
			double fTemp1473 = (0.047733937999999997 * fTemp43);
			double fTemp1474 = (0.00070592729999999996 * fTemp55);
			double fTemp1475 = (0.012780384299999999 * fTemp47);
			double fTemp1476 = (0.042410310800000003 * fTemp51);
			double fTemp1477 = (0.0183883554 * fTemp61);
			double fTemp1478 = (0.033344066700000001 * fTemp45);
			double fTemp1479 = (0.045285965400000003 * fTemp53);
			double fTemp1480 = (0.041017605499999998 * fTemp49);
			double fTemp1481 = (0.043645281500000001 * fTemp59);
			double fTemp1482 = (0.0014103945000000001 * fTemp63);
			double fTemp1483 = (fConst309 * (((fTemp1472 + (((fTemp1473 + fTemp1474) + fTemp1475) + fTemp1476)) + fTemp1477) - ((((fTemp1478 + fTemp1479) + fTemp1480) + fTemp1481) + fTemp1482)));
			double fTemp1484 = (fConst310 * fRec1981[1]);
			double fTemp1485 = (fConst311 * fRec1984[1]);
			fRec1986[0] = (fTemp1483 + (fTemp1484 + (fRec1986[1] + fTemp1485)));
			fRec1984[0] = fRec1986[0];
			double fRec1985 = ((fTemp1485 + fTemp1484) + fTemp1483);
			fRec1983[0] = (fRec1983[1] + fRec1984[0]);
			fRec1981[0] = fRec1983[0];
			double fRec1982 = fRec1985;
			fRec1980[0] = ((fTemp1470 + (fRec1980[1] + fTemp1471)) + fRec1982);
			fRec1978[0] = fRec1980[0];
			double fRec1979 = ((fTemp1471 + fTemp1470) + fRec1982);
			fRec1977[0] = (fRec1977[1] + fRec1978[0]);
			fRec1975[0] = fRec1977[0];
			double fRec1976 = fRec1979;
			fRec1974[0] = ((fRec1974[1] + fTemp1469) + fRec1976);
			fRec1972[0] = fRec1974[0];
			double fRec1973 = (fTemp1469 + fRec1976);
			double fTemp1486 = (fConst313 * fRec1987[1]);
			double fTemp1487 = (fConst314 * fRec1990[1]);
			double fTemp1488 = (fConst316 * fRec1993[1]);
			double fTemp1489 = (fConst317 * fRec1996[1]);
			double fTemp1490 = (0.0011439819 * fTemp31);
			double fTemp1491 = (0.046086858299999998 * fTemp29);
			double fTemp1492 = (0.1072384222 * fTemp21);
			double fTemp1493 = (0.0303474746 * fTemp11);
			double fTemp1494 = (0.078688450800000004 * fTemp23);
			double fTemp1495 = (0.036399380799999999 * fTemp25);
			double fTemp1496 = (0.089295281000000004 * fTemp27);
			double fTemp1497 = (0.033260467699999997 * fTemp35);
			double fTemp1498 = (0.077204272599999998 * fTemp19);
			double fTemp1499 = (0.074402379699999993 * fTemp17);
			double fTemp1500 = (0.090451678899999999 * fTemp13);
			double fTemp1501 = (0.027508788199999998 * fTemp15);
			double fTemp1502 = (0.0023447347 * fTemp33);
			double fTemp1503 = (fConst319 * ((fTemp1490 + (fTemp1491 + ((((fTemp1492 + fTemp1493) + fTemp1494) + fTemp1495) + fTemp1496))) - (fTemp1497 + ((fTemp1498 + (fTemp1499 + (fTemp1500 + fTemp1501))) + fTemp1502))));
			double fTemp1504 = (fConst320 * fRec1999[1]);
			double fTemp1505 = (fConst321 * fRec2002[1]);
			fRec2004[0] = (fTemp1503 + (fTemp1504 + (fRec2004[1] + fTemp1505)));
			fRec2002[0] = fRec2004[0];
			double fRec2003 = ((fTemp1505 + fTemp1504) + fTemp1503);
			fRec2001[0] = (fRec2001[1] + fRec2002[0]);
			fRec1999[0] = fRec2001[0];
			double fRec2000 = fRec2003;
			fRec1998[0] = ((fTemp1488 + (fRec1998[1] + fTemp1489)) + fRec2000);
			fRec1996[0] = fRec1998[0];
			double fRec1997 = ((fTemp1489 + fTemp1488) + fRec2000);
			fRec1995[0] = (fRec1995[1] + fRec1996[0]);
			fRec1993[0] = fRec1995[0];
			double fRec1994 = fRec1997;
			fRec1992[0] = ((fTemp1486 + (fRec1992[1] + fTemp1487)) + fRec1994);
			fRec1990[0] = fRec1992[0];
			double fRec1991 = ((fTemp1487 + fTemp1486) + fRec1994);
			fRec1989[0] = (fRec1989[1] + fRec1990[0]);
			fRec1987[0] = fRec1989[0];
			double fRec1988 = fRec1991;
			fVec29[(IOTA & 511)] = (fTemp1429 + (((((fRec1943 + fRec1946) + fRec1952) + fRec1961) + fRec1973) + fRec1988));
			output30[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec29[((IOTA - iConst322) & 511)])));
			double fTemp1506 = (0.0115999743 * fTemp130);
			double fTemp1507 = (0.0010910525000000001 * fTemp113);
			double fTemp1508 = (0.040666889400000003 * fTemp111);
			double fTemp1509 = (0.0041616005000000003 * fTemp109);
			double fTemp1510 = (fConst244 * ((fTemp1507 + fTemp1508) - fTemp1509));
			double fTemp1511 = (fConst245 * fRec2005[1]);
			fRec2007[0] = (fTemp1510 + (fRec2007[1] + fTemp1511));
			fRec2005[0] = fRec2007[0];
			double fRec2006 = (fTemp1511 + fTemp1510);
			double fTemp1512 = (0.064035384299999998 * fTemp123);
			double fTemp1513 = (0.022290223299999998 * fTemp117);
			double fTemp1514 = (0.0025480868 * fTemp119);
			double fTemp1515 = (0.0189482822 * fTemp125);
			double fTemp1516 = (0.0079308251999999999 * fTemp121);
			double fTemp1517 = (fConst247 * (fTemp1512 - (((fTemp1513 + fTemp1514) + fTemp1515) + fTemp1516)));
			double fTemp1518 = (fConst248 * fRec2008[1]);
			double fTemp1519 = (fConst249 * fRec2011[1]);
			fRec2013[0] = (fTemp1517 + (fTemp1518 + (fRec2013[1] + fTemp1519)));
			fRec2011[0] = fRec2013[0];
			double fRec2012 = ((fTemp1519 + fTemp1518) + fTemp1517);
			fRec2010[0] = (fRec2010[1] + fRec2011[0]);
			fRec2008[0] = fRec2010[0];
			double fRec2009 = fRec2012;
			double fTemp1520 = (fConst251 * fRec2014[1]);
			double fTemp1521 = (0.075798684800000002 * fTemp104);
			double fTemp1522 = (0.013393052000000001 * fTemp100);
			double fTemp1523 = (0.027878250800000001 * fTemp96);
			double fTemp1524 = (0.020583239199999999 * fTemp92);
			double fTemp1525 = (0.025387571000000001 * fTemp94);
			double fTemp1526 = (0.0024527105 * fTemp98);
			double fTemp1527 = (0.032096285600000003 * fTemp102);
			double fTemp1528 = (fConst253 * ((fTemp1521 + (fTemp1522 + fTemp1523)) - (((fTemp1524 + fTemp1525) + fTemp1526) + fTemp1527)));
			double fTemp1529 = (fConst254 * fRec2017[1]);
			double fTemp1530 = (fConst255 * fRec2020[1]);
			fRec2022[0] = (fTemp1528 + (fTemp1529 + (fRec2022[1] + fTemp1530)));
			fRec2020[0] = fRec2022[0];
			double fRec2021 = ((fTemp1530 + fTemp1529) + fTemp1528);
			fRec2019[0] = (fRec2019[1] + fRec2020[0]);
			fRec2017[0] = fRec2019[0];
			double fRec2018 = fRec2021;
			fRec2016[0] = ((fRec2016[1] + fTemp1520) + fRec2018);
			fRec2014[0] = fRec2016[0];
			double fRec2015 = (fTemp1520 + fRec2018);
			double fTemp1531 = (fConst257 * fRec2023[1]);
			double fTemp1532 = (fConst258 * fRec2026[1]);
			double fTemp1533 = (0.025433468000000001 * fTemp84);
			double fTemp1534 = (0.055715812300000001 * fTemp82);
			double fTemp1535 = (0.025922647199999999 * fTemp72);
			double fTemp1536 = (0.0355287122 * fTemp76);
			double fTemp1537 = (0.0094854719000000004 * fTemp80);
			double fTemp1538 = (0.037377252399999998 * fTemp78);
			double fTemp1539 = (0.0017082521 * fTemp70);
			double fTemp1540 = (0.0046992652999999999 * fTemp68);
			double fTemp1541 = (0.024251957800000001 * fTemp74);
			double fTemp1542 = (fConst260 * ((fTemp1533 + (fTemp1534 + (fTemp1535 + fTemp1536))) - (fTemp1537 + (fTemp1538 + (fTemp1539 + (fTemp1540 + fTemp1541))))));
			double fTemp1543 = (fConst261 * fRec2029[1]);
			double fTemp1544 = (fConst262 * fRec2032[1]);
			fRec2034[0] = (fTemp1542 + (fTemp1543 + (fRec2034[1] + fTemp1544)));
			fRec2032[0] = fRec2034[0];
			double fRec2033 = ((fTemp1544 + fTemp1543) + fTemp1542);
			fRec2031[0] = (fRec2031[1] + fRec2032[0]);
			fRec2029[0] = fRec2031[0];
			double fRec2030 = fRec2033;
			fRec2028[0] = ((fTemp1531 + (fRec2028[1] + fTemp1532)) + fRec2030);
			fRec2026[0] = fRec2028[0];
			double fRec2027 = ((fTemp1532 + fTemp1531) + fRec2030);
			fRec2025[0] = (fRec2025[1] + fRec2026[0]);
			fRec2023[0] = fRec2025[0];
			double fRec2024 = fRec2027;
			double fTemp1545 = (fConst264 * fRec2035[1]);
			double fTemp1546 = (fConst266 * fRec2038[1]);
			double fTemp1547 = (fConst267 * fRec2041[1]);
			double fTemp1548 = (0.12816345370000001 * fTemp57);
			double fTemp1549 = (0.0559876573 * fTemp45);
			double fTemp1550 = (0.054850004000000001 * fTemp51);
			double fTemp1551 = (0.0435996456 * fTemp63);
			double fTemp1552 = (0.10457751849999999 * fTemp61);
			double fTemp1553 = (0.0088531098999999995 * fTemp47);
			double fTemp1554 = (0.017682455600000001 * fTemp43);
			double fTemp1555 = (0.0028676139000000001 * fTemp53);
			double fTemp1556 = (0.063731963200000005 * fTemp55);
			double fTemp1557 = (0.036484608199999997 * fTemp49);
			double fTemp1558 = (0.029111682199999999 * fTemp59);
			double fTemp1559 = (fConst269 * (((fTemp1548 + (fTemp1549 + fTemp1550)) + fTemp1551) - (fTemp1552 + (((fTemp1553 + ((fTemp1554 + fTemp1555) + fTemp1556)) + fTemp1557) + fTemp1558))));
			double fTemp1560 = (fConst270 * fRec2044[1]);
			double fTemp1561 = (fConst271 * fRec2047[1]);
			fRec2049[0] = (fTemp1559 + (fTemp1560 + (fRec2049[1] + fTemp1561)));
			fRec2047[0] = fRec2049[0];
			double fRec2048 = ((fTemp1561 + fTemp1560) + fTemp1559);
			fRec2046[0] = (fRec2046[1] + fRec2047[0]);
			fRec2044[0] = fRec2046[0];
			double fRec2045 = fRec2048;
			fRec2043[0] = ((fTemp1546 + (fRec2043[1] + fTemp1547)) + fRec2045);
			fRec2041[0] = fRec2043[0];
			double fRec2042 = ((fTemp1547 + fTemp1546) + fRec2045);
			fRec2040[0] = (fRec2040[1] + fRec2041[0]);
			fRec2038[0] = fRec2040[0];
			double fRec2039 = fRec2042;
			fRec2037[0] = ((fRec2037[1] + fTemp1545) + fRec2039);
			fRec2035[0] = fRec2037[0];
			double fRec2036 = (fTemp1545 + fRec2039);
			double fTemp1562 = (fConst273 * fRec2050[1]);
			double fTemp1563 = (fConst274 * fRec2053[1]);
			double fTemp1564 = (fConst276 * fRec2056[1]);
			double fTemp1565 = (fConst277 * fRec2059[1]);
			double fTemp1566 = (0.099719503700000003 * fTemp35);
			double fTemp1567 = (0.11157742330000001 * fTemp29);
			double fTemp1568 = (0.073160547399999998 * fTemp13);
			double fTemp1569 = (0.0026314088999999999 * fTemp15);
			double fTemp1570 = (0.15157049410000001 * fTemp27);
			double fTemp1571 = (0.030190259300000001 * fTemp33);
			double fTemp1572 = (0.075579197700000003 * fTemp19);
			double fTemp1573 = (0.055160061199999999 * fTemp25);
			double fTemp1574 = (0.045457129499999999 * fTemp21);
			double fTemp1575 = (0.0115487679 * fTemp11);
			double fTemp1576 = (0.032886280900000002 * fTemp23);
			double fTemp1577 = (0.068290848799999998 * fTemp17);
			double fTemp1578 = (0.15975016880000001 * fTemp31);
			double fTemp1579 = (fConst279 * ((fTemp1566 + ((fTemp1567 + ((fTemp1568 + fTemp1569) + fTemp1570)) + fTemp1571)) - ((fTemp1572 + ((fTemp1573 + ((fTemp1574 + fTemp1575) + fTemp1576)) + fTemp1577)) + fTemp1578)));
			double fTemp1580 = (fConst280 * fRec2062[1]);
			double fTemp1581 = (fConst281 * fRec2065[1]);
			fRec2067[0] = (fTemp1579 + (fTemp1580 + (fRec2067[1] + fTemp1581)));
			fRec2065[0] = fRec2067[0];
			double fRec2066 = ((fTemp1581 + fTemp1580) + fTemp1579);
			fRec2064[0] = (fRec2064[1] + fRec2065[0]);
			fRec2062[0] = fRec2064[0];
			double fRec2063 = fRec2066;
			fRec2061[0] = ((fTemp1564 + (fRec2061[1] + fTemp1565)) + fRec2063);
			fRec2059[0] = fRec2061[0];
			double fRec2060 = ((fTemp1565 + fTemp1564) + fRec2063);
			fRec2058[0] = (fRec2058[1] + fRec2059[0]);
			fRec2056[0] = fRec2058[0];
			double fRec2057 = fRec2060;
			fRec2055[0] = ((fTemp1562 + (fRec2055[1] + fTemp1563)) + fRec2057);
			fRec2053[0] = fRec2055[0];
			double fRec2054 = ((fTemp1563 + fTemp1562) + fRec2057);
			fRec2052[0] = (fRec2052[1] + fRec2053[0]);
			fRec2050[0] = fRec2052[0];
			double fRec2051 = fRec2054;
			fVec30[(IOTA & 511)] = (fTemp1506 + (((((fRec2006 + fRec2009) + fRec2015) + fRec2024) + fRec2036) + fRec2051));
			output31[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec30[((IOTA - iConst282) & 511)])));
			double fTemp1582 = (0.012548564 * fTemp130);
			double fTemp1583 = (0.0034094119000000001 * fTemp113);
			double fTemp1584 = (0.035118094900000001 * fTemp111);
			double fTemp1585 = (0.017857837000000001 * fTemp109);
			double fTemp1586 = (fConst284 * ((fTemp1583 + fTemp1584) - fTemp1585));
			double fTemp1587 = (fConst285 * fRec2068[1]);
			fRec2070[0] = (fTemp1586 + (fRec2070[1] + fTemp1587));
			fRec2068[0] = fRec2070[0];
			double fRec2069 = (fTemp1587 + fTemp1586);
			double fTemp1588 = (0.0052956836 * fTemp119);
			double fTemp1589 = (0.0412878515 * fTemp123);
			double fTemp1590 = (0.037213415600000001 * fTemp117);
			double fTemp1591 = (0.016291628999999998 * fTemp125);
			double fTemp1592 = (0.0083809489000000008 * fTemp121);
			double fTemp1593 = (fConst287 * ((fTemp1588 + fTemp1589) - ((fTemp1590 + fTemp1591) + fTemp1592)));
			double fTemp1594 = (fConst288 * fRec2071[1]);
			double fTemp1595 = (fConst289 * fRec2074[1]);
			fRec2076[0] = (fTemp1593 + (fTemp1594 + (fRec2076[1] + fTemp1595)));
			fRec2074[0] = fRec2076[0];
			double fRec2075 = ((fTemp1595 + fTemp1594) + fTemp1593);
			fRec2073[0] = (fRec2073[1] + fRec2074[0]);
			fRec2071[0] = fRec2073[0];
			double fRec2072 = fRec2075;
			double fTemp1596 = (fConst291 * fRec2077[1]);
			double fTemp1597 = (0.0141527753 * fTemp104);
			double fTemp1598 = (0.0062041898999999996 * fTemp94);
			double fTemp1599 = (0.017402420700000001 * fTemp98);
			double fTemp1600 = (0.015580572900000001 * fTemp100);
			double fTemp1601 = (0.0183468543 * fTemp96);
			double fTemp1602 = (0.063674887099999994 * fTemp92);
			double fTemp1603 = (0.030699223300000002 * fTemp102);
			double fTemp1604 = (fConst293 * ((fTemp1597 + (((fTemp1598 + fTemp1599) + fTemp1600) + fTemp1601)) - (fTemp1602 + fTemp1603)));
			double fTemp1605 = (fConst294 * fRec2080[1]);
			double fTemp1606 = (fConst295 * fRec2083[1]);
			fRec2085[0] = (fTemp1604 + (fTemp1605 + (fRec2085[1] + fTemp1606)));
			fRec2083[0] = fRec2085[0];
			double fRec2084 = ((fTemp1606 + fTemp1605) + fTemp1604);
			fRec2082[0] = (fRec2082[1] + fRec2083[0]);
			fRec2080[0] = fRec2082[0];
			double fRec2081 = fRec2084;
			fRec2079[0] = ((fRec2079[1] + fTemp1596) + fRec2081);
			fRec2077[0] = fRec2079[0];
			double fRec2078 = (fTemp1596 + fRec2081);
			double fTemp1607 = (fConst297 * fRec2086[1]);
			double fTemp1608 = (fConst298 * fRec2089[1]);
			double fTemp1609 = (0.0232754578 * fTemp84);
			double fTemp1610 = (0.045962834799999998 * fTemp82);
			double fTemp1611 = (0.0515462026 * fTemp70);
			double fTemp1612 = (0.016758510099999999 * fTemp78);
			double fTemp1613 = (0.026735276200000001 * fTemp72);
			double fTemp1614 = (0.022327722599999999 * fTemp80);
			double fTemp1615 = (0.058235797399999997 * fTemp68);
			double fTemp1616 = (0.0023428897000000001 * fTemp74);
			double fTemp1617 = (0.0241620624 * fTemp76);
			double fTemp1618 = (fConst300 * ((fTemp1609 + (fTemp1610 + ((fTemp1611 + fTemp1612) + fTemp1613))) - (fTemp1614 + (fTemp1615 + (fTemp1616 + fTemp1617)))));
			double fTemp1619 = (fConst301 * fRec2092[1]);
			double fTemp1620 = (fConst302 * fRec2095[1]);
			fRec2097[0] = (fTemp1618 + (fTemp1619 + (fRec2097[1] + fTemp1620)));
			fRec2095[0] = fRec2097[0];
			double fRec2096 = ((fTemp1620 + fTemp1619) + fTemp1618);
			fRec2094[0] = (fRec2094[1] + fRec2095[0]);
			fRec2092[0] = fRec2094[0];
			double fRec2093 = fRec2096;
			fRec2091[0] = ((fTemp1607 + (fRec2091[1] + fTemp1608)) + fRec2093);
			fRec2089[0] = fRec2091[0];
			double fRec2090 = ((fTemp1608 + fTemp1607) + fRec2093);
			fRec2088[0] = (fRec2088[1] + fRec2089[0]);
			fRec2086[0] = fRec2088[0];
			double fRec2087 = fRec2090;
			double fTemp1621 = (fConst304 * fRec2098[1]);
			double fTemp1622 = (fConst306 * fRec2101[1]);
			double fTemp1623 = (fConst307 * fRec2104[1]);
			double fTemp1624 = (0.098087478500000005 * fTemp57);
			double fTemp1625 = (0.029193342099999998 * fTemp45);
			double fTemp1626 = (0.0637673448 * fTemp53);
			double fTemp1627 = (0.046288734599999999 * fTemp51);
			double fTemp1628 = (0.031309764499999997 * fTemp63);
			double fTemp1629 = (0.0132648352 * fTemp61);
			double fTemp1630 = (0.037926963299999998 * fTemp49);
			double fTemp1631 = (0.022531750999999999 * fTemp47);
			double fTemp1632 = (0.035462563900000001 * fTemp43);
			double fTemp1633 = (0.069800768099999994 * fTemp55);
			double fTemp1634 = (0.0020572938999999998 * fTemp59);
			double fTemp1635 = (fConst309 * ((fTemp1624 + ((fTemp1625 + fTemp1626) + fTemp1627)) - (fTemp1628 + (fTemp1629 + ((fTemp1630 + (fTemp1631 + (fTemp1632 + fTemp1633))) + fTemp1634)))));
			double fTemp1636 = (fConst310 * fRec2107[1]);
			double fTemp1637 = (fConst311 * fRec2110[1]);
			fRec2112[0] = (fTemp1635 + (fTemp1636 + (fRec2112[1] + fTemp1637)));
			fRec2110[0] = fRec2112[0];
			double fRec2111 = ((fTemp1637 + fTemp1636) + fTemp1635);
			fRec2109[0] = (fRec2109[1] + fRec2110[0]);
			fRec2107[0] = fRec2109[0];
			double fRec2108 = fRec2111;
			fRec2106[0] = ((fTemp1622 + (fRec2106[1] + fTemp1623)) + fRec2108);
			fRec2104[0] = fRec2106[0];
			double fRec2105 = ((fTemp1623 + fTemp1622) + fRec2108);
			fRec2103[0] = (fRec2103[1] + fRec2104[0]);
			fRec2101[0] = fRec2103[0];
			double fRec2102 = fRec2105;
			fRec2100[0] = ((fRec2100[1] + fTemp1621) + fRec2102);
			fRec2098[0] = fRec2100[0];
			double fRec2099 = (fTemp1621 + fRec2102);
			double fTemp1638 = (fConst313 * fRec2113[1]);
			double fTemp1639 = (fConst314 * fRec2116[1]);
			double fTemp1640 = (fConst316 * fRec2119[1]);
			double fTemp1641 = (fConst317 * fRec2122[1]);
			double fTemp1642 = (0.0047087848 * fTemp31);
			double fTemp1643 = (0.022061319699999998 * fTemp29);
			double fTemp1644 = (0.085852265799999994 * fTemp13);
			double fTemp1645 = (0.036749970899999998 * fTemp15);
			double fTemp1646 = (0.1110263444 * fTemp27);
			double fTemp1647 = (0.10396268760000001 * fTemp35);
			double fTemp1648 = (0.067070961799999995 * fTemp19);
			double fTemp1649 = (0.1051288499 * fTemp25);
			double fTemp1650 = (0.038981753700000003 * fTemp21);
			double fTemp1651 = (0.020959452100000001 * fTemp11);
			double fTemp1652 = (0.087756814200000005 * fTemp23);
			double fTemp1653 = (0.070908245100000003 * fTemp17);
			double fTemp1654 = (0.024010455399999998 * fTemp33);
			double fTemp1655 = (fConst319 * ((fTemp1642 + (fTemp1643 + ((fTemp1644 + fTemp1645) + fTemp1646))) - (fTemp1647 + ((fTemp1648 + ((fTemp1649 + ((fTemp1650 + fTemp1651) + fTemp1652)) + fTemp1653)) + fTemp1654))));
			double fTemp1656 = (fConst320 * fRec2125[1]);
			double fTemp1657 = (fConst321 * fRec2128[1]);
			fRec2130[0] = (fTemp1655 + (fTemp1656 + (fRec2130[1] + fTemp1657)));
			fRec2128[0] = fRec2130[0];
			double fRec2129 = ((fTemp1657 + fTemp1656) + fTemp1655);
			fRec2127[0] = (fRec2127[1] + fRec2128[0]);
			fRec2125[0] = fRec2127[0];
			double fRec2126 = fRec2129;
			fRec2124[0] = ((fTemp1640 + (fRec2124[1] + fTemp1641)) + fRec2126);
			fRec2122[0] = fRec2124[0];
			double fRec2123 = ((fTemp1641 + fTemp1640) + fRec2126);
			fRec2121[0] = (fRec2121[1] + fRec2122[0]);
			fRec2119[0] = fRec2121[0];
			double fRec2120 = fRec2123;
			fRec2118[0] = ((fTemp1638 + (fRec2118[1] + fTemp1639)) + fRec2120);
			fRec2116[0] = fRec2118[0];
			double fRec2117 = ((fTemp1639 + fTemp1638) + fRec2120);
			fRec2115[0] = (fRec2115[1] + fRec2116[0]);
			fRec2113[0] = fRec2115[0];
			double fRec2114 = fRec2117;
			fVec31[(IOTA & 511)] = (fTemp1582 + (((((fRec2069 + fRec2072) + fRec2078) + fRec2087) + fRec2099) + fRec2114));
			output32[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec31[((IOTA - iConst322) & 511)])));
			double fTemp1658 = (0.024877433099999999 * fTemp111);
			double fTemp1659 = (0.026616915599999999 * fTemp109);
			double fTemp1660 = (fConst244 * ((fTemp1355 + fTemp1658) - fTemp1659));
			double fTemp1661 = (fConst245 * fRec2131[1]);
			fRec2133[0] = (fTemp1660 + (fRec2133[1] + fTemp1661));
			fRec2131[0] = fRec2133[0];
			double fRec2132 = (fTemp1661 + fTemp1660);
			double fTemp1662 = (0.014551550999999999 * fTemp119);
			double fTemp1663 = (0.0085538755000000005 * fTemp121);
			double fTemp1664 = (fConst247 * (fTemp1662 - (fTemp1360 + ((fTemp1359 + fTemp1362) + fTemp1663))));
			double fTemp1665 = (fConst248 * fRec2134[1]);
			double fTemp1666 = (fConst249 * fRec2137[1]);
			fRec2139[0] = (fTemp1664 + (fTemp1665 + (fRec2139[1] + fTemp1666)));
			fRec2137[0] = fRec2139[0];
			double fRec2138 = ((fTemp1666 + fTemp1665) + fTemp1664);
			fRec2136[0] = (fRec2136[1] + fRec2137[0]);
			fRec2134[0] = fRec2136[0];
			double fRec2135 = fRec2138;
			double fTemp1667 = (fConst251 * fRec2140[1]);
			double fTemp1668 = (0.037469102499999997 * fTemp98);
			double fTemp1669 = (0.038907956 * fTemp92);
			double fTemp1670 = (0.0263719044 * fTemp102);
			double fTemp1671 = (0.0686175542 * fTemp104);
			double fTemp1672 = (fConst253 * ((fTemp1371 + (fTemp1369 + (fTemp1372 + fTemp1668))) - ((fTemp1669 + fTemp1670) + fTemp1671)));
			double fTemp1673 = (fConst254 * fRec2143[1]);
			double fTemp1674 = (fConst255 * fRec2146[1]);
			fRec2148[0] = (fTemp1672 + (fTemp1673 + (fRec2148[1] + fTemp1674)));
			fRec2146[0] = fRec2148[0];
			double fRec2147 = ((fTemp1674 + fTemp1673) + fTemp1672);
			fRec2145[0] = (fRec2145[1] + fRec2146[0]);
			fRec2143[0] = fRec2145[0];
			double fRec2144 = fRec2147;
			fRec2142[0] = ((fRec2142[1] + fTemp1667) + fRec2144);
			fRec2140[0] = fRec2142[0];
			double fRec2141 = (fTemp1667 + fRec2144);
			double fTemp1675 = (fConst257 * fRec2149[1]);
			double fTemp1676 = (fConst258 * fRec2152[1]);
			double fTemp1677 = (0.029518910499999999 * fTemp82);
			double fTemp1678 = (0.0184232654 * fTemp70);
			double fTemp1679 = (0.014744688299999999 * fTemp74);
			double fTemp1680 = (0.025473697300000001 * fTemp80);
			double fTemp1681 = (fConst260 * ((fTemp1385 + (fTemp1677 + (fTemp1381 + (fTemp1386 + (fTemp1678 + (fTemp1383 + fTemp1679)))))) - (fTemp1388 + fTemp1680)));
			double fTemp1682 = (fConst261 * fRec2155[1]);
			double fTemp1683 = (fConst262 * fRec2158[1]);
			fRec2160[0] = (fTemp1681 + (fTemp1682 + (fRec2160[1] + fTemp1683)));
			fRec2158[0] = fRec2160[0];
			double fRec2159 = ((fTemp1683 + fTemp1682) + fTemp1681);
			fRec2157[0] = (fRec2157[1] + fRec2158[0]);
			fRec2155[0] = fRec2157[0];
			double fRec2156 = fRec2159;
			fRec2154[0] = ((fTemp1675 + (fRec2154[1] + fTemp1676)) + fRec2156);
			fRec2152[0] = fRec2154[0];
			double fRec2153 = ((fTemp1676 + fTemp1675) + fRec2156);
			fRec2151[0] = (fRec2151[1] + fRec2152[0]);
			fRec2149[0] = fRec2151[0];
			double fRec2150 = fRec2153;
			double fTemp1684 = (fConst264 * fRec2161[1]);
			double fTemp1685 = (fConst266 * fRec2164[1]);
			double fTemp1686 = (fConst267 * fRec2167[1]);
			double fTemp1687 = (0.0173945821 * fTemp59);
			double fTemp1688 = (0.042130927300000003 * fTemp43);
			double fTemp1689 = (0.023095824000000001 * fTemp53);
			double fTemp1690 = (0.0302883436 * fTemp51);
			double fTemp1691 = (0.027231439999999999 * fTemp47);
			double fTemp1692 = (0.017252402600000001 * fTemp63);
			double fTemp1693 = (fConst269 * ((fTemp1395 + (fTemp1687 + (fTemp1404 + ((fTemp1688 + fTemp1689) + fTemp1690)))) - ((fTemp1403 + (fTemp1691 + (fTemp1401 + fTemp1396))) + fTemp1692)));
			double fTemp1694 = (fConst270 * fRec2170[1]);
			double fTemp1695 = (fConst271 * fRec2173[1]);
			fRec2175[0] = (fTemp1693 + (fTemp1694 + (fRec2175[1] + fTemp1695)));
			fRec2173[0] = fRec2175[0];
			double fRec2174 = ((fTemp1695 + fTemp1694) + fTemp1693);
			fRec2172[0] = (fRec2172[1] + fRec2173[0]);
			fRec2170[0] = fRec2172[0];
			double fRec2171 = fRec2174;
			fRec2169[0] = ((fTemp1685 + (fRec2169[1] + fTemp1686)) + fRec2171);
			fRec2167[0] = fRec2169[0];
			double fRec2168 = ((fTemp1686 + fTemp1685) + fRec2171);
			fRec2166[0] = (fRec2166[1] + fRec2167[0]);
			fRec2164[0] = fRec2166[0];
			double fRec2165 = fRec2168;
			fRec2163[0] = ((fRec2163[1] + fTemp1684) + fRec2165);
			fRec2161[0] = fRec2163[0];
			double fRec2162 = (fTemp1684 + fRec2165);
			double fTemp1696 = (fConst273 * fRec2176[1]);
			double fTemp1697 = (fConst274 * fRec2179[1]);
			double fTemp1698 = (fConst276 * fRec2182[1]);
			double fTemp1699 = (fConst277 * fRec2185[1]);
			double fTemp1700 = (0.033091201100000002 * fTemp11);
			double fTemp1701 = (0.064214321699999993 * fTemp15);
			double fTemp1702 = (0.052326541099999999 * fTemp19);
			double fTemp1703 = (0.0555762219 * fTemp23);
			double fTemp1704 = (0.10324761490000001 * fTemp29);
			double fTemp1705 = (0.016276343700000001 * fTemp33);
			double fTemp1706 = (fConst279 * ((fTemp1416 + (fTemp1415 + (fTemp1418 + ((fTemp1421 + fTemp1700) + fTemp1701)))) - (((fTemp1702 + (fTemp1420 + (fTemp1414 + (fTemp1423 + fTemp1703)))) + fTemp1704) + fTemp1705)));
			double fTemp1707 = (fConst280 * fRec2188[1]);
			double fTemp1708 = (fConst281 * fRec2191[1]);
			fRec2193[0] = (fTemp1706 + (fTemp1707 + (fRec2193[1] + fTemp1708)));
			fRec2191[0] = fRec2193[0];
			double fRec2192 = ((fTemp1708 + fTemp1707) + fTemp1706);
			fRec2190[0] = (fRec2190[1] + fRec2191[0]);
			fRec2188[0] = fRec2190[0];
			double fRec2189 = fRec2192;
			fRec2187[0] = ((fTemp1698 + (fRec2187[1] + fTemp1699)) + fRec2189);
			fRec2185[0] = fRec2187[0];
			double fRec2186 = ((fTemp1699 + fTemp1698) + fRec2189);
			fRec2184[0] = (fRec2184[1] + fRec2185[0]);
			fRec2182[0] = fRec2184[0];
			double fRec2183 = fRec2186;
			fRec2181[0] = ((fTemp1696 + (fRec2181[1] + fTemp1697)) + fRec2183);
			fRec2179[0] = fRec2181[0];
			double fRec2180 = ((fTemp1697 + fTemp1696) + fRec2183);
			fRec2178[0] = (fRec2178[1] + fRec2179[0]);
			fRec2176[0] = fRec2178[0];
			double fRec2177 = fRec2180;
			fVec32[(IOTA & 511)] = (fTemp1353 + (((((fRec2132 + fRec2135) + fRec2141) + fRec2150) + fRec2162) + fRec2177));
			output33[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec32[((IOTA - iConst282) & 511)])));
			double fTemp1709 = (0.0116704111 * fTemp111);
			double fTemp1710 = (0.036026393099999998 * fTemp109);
			double fTemp1711 = (fConst284 * ((fTemp1431 + fTemp1709) - fTemp1710));
			double fTemp1712 = (fConst285 * fRec2194[1]);
			fRec2196[0] = (fTemp1711 + (fRec2196[1] + fTemp1712));
			fRec2194[0] = fRec2196[0];
			double fRec2195 = (fTemp1712 + fTemp1711);
			double fTemp1713 = (0.0134650021 * fTemp119);
			double fTemp1714 = (0.0053400123000000004 * fTemp121);
			double fTemp1715 = (fConst287 * (fTemp1713 - (fTemp1436 + ((fTemp1435 + fTemp1438) + fTemp1714))));
			double fTemp1716 = (fConst288 * fRec2197[1]);
			double fTemp1717 = (fConst289 * fRec2200[1]);
			fRec2202[0] = (fTemp1715 + (fTemp1716 + (fRec2202[1] + fTemp1717)));
			fRec2200[0] = fRec2202[0];
			double fRec2201 = ((fTemp1717 + fTemp1716) + fTemp1715);
			fRec2199[0] = (fRec2199[1] + fRec2200[0]);
			fRec2197[0] = fRec2199[0];
			double fRec2198 = fRec2201;
			double fTemp1718 = (fConst291 * fRec2203[1]);
			double fTemp1719 = (0.034960143999999999 * fTemp92);
			double fTemp1720 = (0.039622172300000001 * fTemp98);
			double fTemp1721 = (0.0145304557 * fTemp102);
			double fTemp1722 = (0.055513575799999999 * fTemp104);
			double fTemp1723 = (fConst293 * ((fTemp1447 + (fTemp1445 + ((fTemp1448 + fTemp1719) + fTemp1720))) - (fTemp1721 + fTemp1722)));
			double fTemp1724 = (fConst294 * fRec2206[1]);
			double fTemp1725 = (fConst295 * fRec2209[1]);
			fRec2211[0] = (fTemp1723 + (fTemp1724 + (fRec2211[1] + fTemp1725)));
			fRec2209[0] = fRec2211[0];
			double fRec2210 = ((fTemp1725 + fTemp1724) + fTemp1723);
			fRec2208[0] = (fRec2208[1] + fRec2209[0]);
			fRec2206[0] = fRec2208[0];
			double fRec2207 = fRec2210;
			fRec2205[0] = ((fRec2205[1] + fTemp1718) + fRec2207);
			fRec2203[0] = fRec2205[0];
			double fRec2204 = (fTemp1718 + fRec2207);
			double fTemp1726 = (fConst297 * fRec2212[1]);
			double fTemp1727 = (fConst298 * fRec2215[1]);
			double fTemp1728 = (0.012583120099999999 * fTemp82);
			double fTemp1729 = (0.036978276999999997 * fTemp74);
			double fTemp1730 = (0.035198028499999999 * fTemp70);
			double fTemp1731 = (0.041906025 * fTemp80);
			double fTemp1732 = (fConst300 * ((fTemp1462 + (fTemp1728 + (fTemp1457 + (fTemp1463 + (fTemp1459 + (fTemp1460 + fTemp1729)))))) - (fTemp1730 + fTemp1731)));
			double fTemp1733 = (fConst301 * fRec2218[1]);
			double fTemp1734 = (fConst302 * fRec2221[1]);
			fRec2223[0] = (fTemp1732 + (fTemp1733 + (fRec2223[1] + fTemp1734)));
			fRec2221[0] = fRec2223[0];
			double fRec2222 = ((fTemp1734 + fTemp1733) + fTemp1732);
			fRec2220[0] = (fRec2220[1] + fRec2221[0]);
			fRec2218[0] = fRec2220[0];
			double fRec2219 = fRec2222;
			fRec2217[0] = ((fTemp1726 + (fRec2217[1] + fTemp1727)) + fRec2219);
			fRec2215[0] = fRec2217[0];
			double fRec2216 = ((fTemp1727 + fTemp1726) + fRec2219);
			fRec2214[0] = (fRec2214[1] + fRec2215[0]);
			fRec2212[0] = fRec2214[0];
			double fRec2213 = fRec2216;
			double fTemp1735 = (fConst304 * fRec2224[1]);
			double fTemp1736 = (fConst306 * fRec2227[1]);
			double fTemp1737 = (fConst307 * fRec2230[1]);
			double fTemp1738 = (0.047733937999999997 * fTemp63);
			double fTemp1739 = (0.0014103945000000001 * fTemp43);
			double fTemp1740 = (0.012780384299999999 * fTemp51);
			double fTemp1741 = (0.045285965400000003 * fTemp59);
			double fTemp1742 = (0.042410310800000003 * fTemp47);
			double fTemp1743 = (0.043645281500000001 * fTemp53);
			double fTemp1744 = (fConst309 * ((fTemp1738 + (fTemp1477 + ((fTemp1739 + fTemp1740) + fTemp1741))) - (fTemp1472 + (fTemp1480 + (fTemp1742 + (fTemp1474 + (fTemp1478 + fTemp1743)))))));
			double fTemp1745 = (fConst310 * fRec2233[1]);
			double fTemp1746 = (fConst311 * fRec2236[1]);
			fRec2238[0] = (fTemp1744 + (fTemp1745 + (fRec2238[1] + fTemp1746)));
			fRec2236[0] = fRec2238[0];
			double fRec2237 = ((fTemp1746 + fTemp1745) + fTemp1744);
			fRec2235[0] = (fRec2235[1] + fRec2236[0]);
			fRec2233[0] = fRec2235[0];
			double fRec2234 = fRec2237;
			fRec2232[0] = ((fTemp1736 + (fRec2232[1] + fTemp1737)) + fRec2234);
			fRec2230[0] = fRec2232[0];
			double fRec2231 = ((fTemp1737 + fTemp1736) + fRec2234);
			fRec2229[0] = (fRec2229[1] + fRec2230[0]);
			fRec2227[0] = fRec2229[0];
			double fRec2228 = fRec2231;
			fRec2226[0] = ((fRec2226[1] + fTemp1735) + fRec2228);
			fRec2224[0] = fRec2226[0];
			double fRec2225 = (fTemp1735 + fRec2228);
			double fTemp1747 = (fConst313 * fRec2239[1]);
			double fTemp1748 = (fConst314 * fRec2242[1]);
			double fTemp1749 = (fConst316 * fRec2245[1]);
			double fTemp1750 = (fConst317 * fRec2248[1]);
			double fTemp1751 = (0.0303474746 * fTemp33);
			double fTemp1752 = (0.0023447347 * fTemp11);
			double fTemp1753 = (0.046086858299999998 * fTemp23);
			double fTemp1754 = (0.077204272599999998 * fTemp15);
			double fTemp1755 = (0.078688450800000004 * fTemp29);
			double fTemp1756 = (0.027508788199999998 * fTemp19);
			double fTemp1757 = (fConst319 * ((fTemp1497 + (fTemp1751 + (fTemp1490 + ((fTemp1752 + fTemp1753) + fTemp1754)))) - (fTemp1755 + (fTemp1496 + (fTemp1756 + (fTemp1499 + (fTemp1495 + (fTemp1492 + fTemp1500))))))));
			double fTemp1758 = (fConst320 * fRec2251[1]);
			double fTemp1759 = (fConst321 * fRec2254[1]);
			fRec2256[0] = (fTemp1757 + (fTemp1758 + (fRec2256[1] + fTemp1759)));
			fRec2254[0] = fRec2256[0];
			double fRec2255 = ((fTemp1759 + fTemp1758) + fTemp1757);
			fRec2253[0] = (fRec2253[1] + fRec2254[0]);
			fRec2251[0] = fRec2253[0];
			double fRec2252 = fRec2255;
			fRec2250[0] = ((fTemp1749 + (fRec2250[1] + fTemp1750)) + fRec2252);
			fRec2248[0] = fRec2250[0];
			double fRec2249 = ((fTemp1750 + fTemp1749) + fRec2252);
			fRec2247[0] = (fRec2247[1] + fRec2248[0]);
			fRec2245[0] = fRec2247[0];
			double fRec2246 = fRec2249;
			fRec2244[0] = ((fTemp1747 + (fRec2244[1] + fTemp1748)) + fRec2246);
			fRec2242[0] = fRec2244[0];
			double fRec2243 = ((fTemp1748 + fTemp1747) + fRec2246);
			fRec2241[0] = (fRec2241[1] + fRec2242[0]);
			fRec2239[0] = fRec2241[0];
			double fRec2240 = fRec2243;
			fVec33[(IOTA & 511)] = (fTemp1429 + (((((fRec2195 + fRec2198) + fRec2204) + fRec2213) + fRec2225) + fRec2240));
			output34[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec33[((IOTA - iConst322) & 511)])));
			double fTemp1760 = (0.040666889400000003 * fTemp109);
			double fTemp1761 = (0.0041616005000000003 * fTemp111);
			double fTemp1762 = (fConst244 * (fTemp1507 - (fTemp1760 + fTemp1761)));
			double fTemp1763 = (fConst245 * fRec2257[1]);
			fRec2259[0] = (fTemp1762 + (fRec2259[1] + fTemp1763));
			fRec2257[0] = fRec2259[0];
			double fRec2258 = (fTemp1763 + fTemp1762);
			double fTemp1764 = (0.0079308251999999999 * fTemp119);
			double fTemp1765 = (0.0025480868 * fTemp121);
			double fTemp1766 = (fConst247 * ((fTemp1513 + fTemp1764) - (fTemp1512 + (fTemp1515 + fTemp1765))));
			double fTemp1767 = (fConst248 * fRec2260[1]);
			double fTemp1768 = (fConst249 * fRec2263[1]);
			fRec2265[0] = (fTemp1766 + (fTemp1767 + (fRec2265[1] + fTemp1768)));
			fRec2263[0] = fRec2265[0];
			double fRec2264 = ((fTemp1768 + fTemp1767) + fTemp1766);
			fRec2262[0] = (fRec2262[1] + fRec2263[0]);
			fRec2260[0] = fRec2262[0];
			double fRec2261 = fRec2264;
			double fTemp1769 = (fConst251 * fRec2266[1]);
			double fTemp1770 = (0.075798684800000002 * fTemp92);
			double fTemp1771 = (0.032096285600000003 * fTemp98);
			double fTemp1772 = (0.020583239199999999 * fTemp104);
			double fTemp1773 = (0.0024527105 * fTemp102);
			double fTemp1774 = (fConst253 * (((fTemp1522 + ((fTemp1525 + fTemp1770) + fTemp1771)) + fTemp1772) - (fTemp1523 + fTemp1773)));
			double fTemp1775 = (fConst254 * fRec2269[1]);
			double fTemp1776 = (fConst255 * fRec2272[1]);
			fRec2274[0] = (fTemp1774 + (fTemp1775 + (fRec2274[1] + fTemp1776)));
			fRec2272[0] = fRec2274[0];
			double fRec2273 = ((fTemp1776 + fTemp1775) + fTemp1774);
			fRec2271[0] = (fRec2271[1] + fRec2272[0]);
			fRec2269[0] = fRec2271[0];
			double fRec2270 = fRec2273;
			fRec2268[0] = ((fRec2268[1] + fTemp1769) + fRec2270);
			fRec2266[0] = fRec2268[0];
			double fRec2267 = (fTemp1769 + fRec2270);
			double fTemp1777 = (fConst257 * fRec2275[1]);
			double fTemp1778 = (fConst258 * fRec2278[1]);
			double fTemp1779 = (0.0017082521 * fTemp74);
			double fTemp1780 = (0.0094854719000000004 * fTemp82);
			double fTemp1781 = (0.024251957800000001 * fTemp70);
			double fTemp1782 = (0.055715812300000001 * fTemp80);
			double fTemp1783 = (fConst260 * ((fTemp1535 + (fTemp1538 + (fTemp1536 + fTemp1779))) - (fTemp1533 + (fTemp1780 + ((fTemp1540 + fTemp1781) + fTemp1782)))));
			double fTemp1784 = (fConst261 * fRec2281[1]);
			double fTemp1785 = (fConst262 * fRec2284[1]);
			fRec2286[0] = (fTemp1783 + (fTemp1784 + (fRec2286[1] + fTemp1785)));
			fRec2284[0] = fRec2286[0];
			double fRec2285 = ((fTemp1785 + fTemp1784) + fTemp1783);
			fRec2283[0] = (fRec2283[1] + fRec2284[0]);
			fRec2281[0] = fRec2283[0];
			double fRec2282 = fRec2285;
			fRec2280[0] = ((fTemp1777 + (fRec2280[1] + fTemp1778)) + fRec2282);
			fRec2278[0] = fRec2280[0];
			double fRec2279 = ((fTemp1778 + fTemp1777) + fRec2282);
			fRec2277[0] = (fRec2277[1] + fRec2278[0]);
			fRec2275[0] = fRec2277[0];
			double fRec2276 = fRec2279;
			double fTemp1786 = (fConst264 * fRec2287[1]);
			double fTemp1787 = (fConst266 * fRec2290[1]);
			double fTemp1788 = (fConst267 * fRec2293[1]);
			double fTemp1789 = (0.0028676139000000001 * fTemp59);
			double fTemp1790 = (0.017682455600000001 * fTemp63);
			double fTemp1791 = (0.0088531098999999995 * fTemp51);
			double fTemp1792 = (0.0435996456 * fTemp43);
			double fTemp1793 = (0.029111682199999999 * fTemp53);
			double fTemp1794 = (0.054850004000000001 * fTemp47);
			double fTemp1795 = (fConst269 * (((fTemp1549 + fTemp1556) + fTemp1789) - (fTemp1790 + (fTemp1552 + (fTemp1548 + (fTemp1791 + (fTemp1557 + ((fTemp1792 + fTemp1793) + fTemp1794))))))));
			double fTemp1796 = (fConst270 * fRec2296[1]);
			double fTemp1797 = (fConst271 * fRec2299[1]);
			fRec2301[0] = (fTemp1795 + (fTemp1796 + (fRec2301[1] + fTemp1797)));
			fRec2299[0] = fRec2301[0];
			double fRec2300 = ((fTemp1797 + fTemp1796) + fTemp1795);
			fRec2298[0] = (fRec2298[1] + fRec2299[0]);
			fRec2296[0] = fRec2298[0];
			double fRec2297 = fRec2300;
			fRec2295[0] = ((fTemp1787 + (fRec2295[1] + fTemp1788)) + fRec2297);
			fRec2293[0] = fRec2295[0];
			double fRec2294 = ((fTemp1788 + fTemp1787) + fRec2297);
			fRec2292[0] = (fRec2292[1] + fRec2293[0]);
			fRec2290[0] = fRec2292[0];
			double fRec2291 = fRec2294;
			fRec2289[0] = ((fRec2289[1] + fTemp1786) + fRec2291);
			fRec2287[0] = fRec2289[0];
			double fRec2288 = (fTemp1786 + fRec2291);
			double fTemp1798 = (0.075579197700000003 * fTemp15);
			double fTemp1799 = (0.11157742330000001 * fTemp23);
			double fTemp1800 = (0.0026314088999999999 * fTemp19);
			double fTemp1801 = (0.032886280900000002 * fTemp29);
			double fTemp1802 = (0.0115487679 * fTemp33);
			double fTemp1803 = (0.030190259300000001 * fTemp11);
			double fTemp1804 = (fConst279 * ((((fTemp1798 + (fTemp1573 + ((fTemp1574 + fTemp1568) + fTemp1799))) + fTemp1800) + fTemp1801) - (fTemp1566 + (fTemp1802 + (fTemp1578 + (fTemp1570 + (fTemp1577 + fTemp1803)))))));
			double fTemp1805 = (fConst280 * fRec2314[1]);
			double fTemp1806 = (fConst281 * fRec2317[1]);
			fRec2319[0] = (fTemp1804 + (fTemp1805 + (fRec2319[1] + fTemp1806)));
			fRec2317[0] = fRec2319[0];
			double fRec2318 = ((fTemp1806 + fTemp1805) + fTemp1804);
			fRec2316[0] = (fRec2316[1] + fRec2317[0]);
			fRec2314[0] = fRec2316[0];
			double fRec2315 = fRec2318;
			double fTemp1807 = (fConst276 * fRec2308[1]);
			double fTemp1808 = (fConst277 * fRec2311[1]);
			fRec2313[0] = (fRec2315 + (fTemp1807 + (fRec2313[1] + fTemp1808)));
			fRec2311[0] = fRec2313[0];
			double fRec2312 = ((fTemp1808 + fTemp1807) + fRec2315);
			fRec2310[0] = (fRec2310[1] + fRec2311[0]);
			fRec2308[0] = fRec2310[0];
			double fRec2309 = fRec2312;
			double fTemp1809 = (fConst273 * fRec2302[1]);
			double fTemp1810 = (fConst274 * fRec2305[1]);
			fRec2307[0] = (fRec2309 + (fTemp1809 + (fRec2307[1] + fTemp1810)));
			fRec2305[0] = fRec2307[0];
			double fRec2306 = ((fTemp1810 + fTemp1809) + fRec2309);
			fRec2304[0] = (fRec2304[1] + fRec2305[0]);
			fRec2302[0] = fRec2304[0];
			double fRec2303 = fRec2306;
			fVec34[(IOTA & 511)] = (fTemp1506 + (((((fRec2258 + fRec2261) + fRec2267) + fRec2276) + fRec2288) + fRec2303));
			output35[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec34[((IOTA - iConst282) & 511)])));
			double fTemp1811 = (fConst313 * fRec2320[1]);
			double fTemp1812 = (fConst314 * fRec2323[1]);
			double fTemp1813 = (fConst316 * fRec2326[1]);
			double fTemp1814 = (fConst317 * fRec2329[1]);
			double fTemp1815 = (0.036749970899999998 * fTemp19);
			double fTemp1816 = (0.067070961799999995 * fTemp15);
			double fTemp1817 = (0.024010455399999998 * fTemp11);
			double fTemp1818 = (0.022061319699999998 * fTemp23);
			double fTemp1819 = (0.087756814200000005 * fTemp29);
			double fTemp1820 = (0.020959452100000001 * fTemp33);
			double fTemp1821 = (fConst319 * ((fTemp1647 + (fTemp1642 + ((fTemp1815 + (fTemp1816 + (fTemp1649 + ((fTemp1644 + (fTemp1650 + fTemp1817)) + fTemp1818)))) + fTemp1819))) - ((fTemp1653 + fTemp1646) + fTemp1820)));
			double fTemp1822 = (fConst320 * fRec2332[1]);
			double fTemp1823 = (fConst321 * fRec2335[1]);
			fRec2337[0] = (fTemp1821 + (fTemp1822 + (fRec2337[1] + fTemp1823)));
			fRec2335[0] = fRec2337[0];
			double fRec2336 = ((fTemp1823 + fTemp1822) + fTemp1821);
			fRec2334[0] = (fRec2335[0] + fRec2334[1]);
			fRec2332[0] = fRec2334[0];
			double fRec2333 = fRec2336;
			fRec2331[0] = (fTemp1813 + (fTemp1814 + (fRec2333 + fRec2331[1])));
			fRec2329[0] = fRec2331[0];
			double fRec2330 = (fTemp1813 + (fRec2333 + fTemp1814));
			fRec2328[0] = (fRec2329[0] + fRec2328[1]);
			fRec2326[0] = fRec2328[0];
			double fRec2327 = fRec2330;
			fRec2325[0] = (fTemp1811 + (fTemp1812 + (fRec2327 + fRec2325[1])));
			fRec2323[0] = fRec2325[0];
			double fRec2324 = (fTemp1811 + (fRec2327 + fTemp1812));
			fRec2322[0] = (fRec2323[0] + fRec2322[1]);
			fRec2320[0] = fRec2322[0];
			double fRec2321 = fRec2324;
			double fTemp1824 = (fConst304 * fRec2338[1]);
			double fTemp1825 = (fConst306 * fRec2341[1]);
			double fTemp1826 = (fConst307 * fRec2344[1]);
			double fTemp1827 = (0.031309764499999997 * fTemp43);
			double fTemp1828 = (0.035462563900000001 * fTemp63);
			double fTemp1829 = (0.0637673448 * fTemp59);
			double fTemp1830 = (0.022531750999999999 * fTemp51);
			double fTemp1831 = (0.0020572938999999998 * fTemp53);
			double fTemp1832 = (0.046288734599999999 * fTemp47);
			double fTemp1833 = (fConst309 * ((fTemp1633 + (fTemp1625 + fTemp1827)) - (fTemp1828 + (fTemp1629 + (fTemp1829 + (fTemp1624 + (fTemp1830 + (fTemp1630 + (fTemp1831 + fTemp1832)))))))));
			double fTemp1834 = (fConst310 * fRec2347[1]);
			double fTemp1835 = (fConst311 * fRec2350[1]);
			fRec2352[0] = (fTemp1833 + (fTemp1834 + (fRec2352[1] + fTemp1835)));
			fRec2350[0] = fRec2352[0];
			double fRec2351 = ((fTemp1835 + fTemp1834) + fTemp1833);
			fRec2349[0] = (fRec2350[0] + fRec2349[1]);
			fRec2347[0] = fRec2349[0];
			double fRec2348 = fRec2351;
			fRec2346[0] = (fTemp1825 + (fTemp1826 + (fRec2348 + fRec2346[1])));
			fRec2344[0] = fRec2346[0];
			double fRec2345 = (fTemp1825 + (fRec2348 + fTemp1826));
			fRec2343[0] = (fRec2344[0] + fRec2343[1]);
			fRec2341[0] = fRec2343[0];
			double fRec2342 = fRec2345;
			fRec2340[0] = (fTemp1824 + (fRec2342 + fRec2340[1]));
			fRec2338[0] = fRec2340[0];
			double fRec2339 = (fRec2342 + fTemp1824);
			double fTemp1836 = (fConst297 * fRec2353[1]);
			double fTemp1837 = (fConst298 * fRec2356[1]);
			double fTemp1838 = (0.022327722599999999 * fTemp82);
			double fTemp1839 = (0.045962834799999998 * fTemp80);
			double fTemp1840 = (0.0023428897000000001 * fTemp70);
			double fTemp1841 = (0.0515462026 * fTemp74);
			double fTemp1842 = (fConst300 * (fTemp1613 - (fTemp1609 + (fTemp1838 + (fTemp1839 + (fTemp1612 + (fTemp1840 + (fTemp1615 + (fTemp1617 + fTemp1841)))))))));
			double fTemp1843 = (fConst301 * fRec2359[1]);
			double fTemp1844 = (fConst302 * fRec2362[1]);
			fRec2364[0] = (fTemp1842 + (fTemp1843 + (fRec2364[1] + fTemp1844)));
			fRec2362[0] = fRec2364[0];
			double fRec2363 = ((fTemp1844 + fTemp1843) + fTemp1842);
			fRec2361[0] = (fRec2362[0] + fRec2361[1]);
			fRec2359[0] = fRec2361[0];
			double fRec2360 = fRec2363;
			fRec2358[0] = (fTemp1836 + (fTemp1837 + (fRec2360 + fRec2358[1])));
			fRec2356[0] = fRec2358[0];
			double fRec2357 = (fTemp1836 + (fRec2360 + fTemp1837));
			fRec2355[0] = (fRec2356[0] + fRec2355[1]);
			fRec2353[0] = fRec2355[0];
			double fRec2354 = fRec2357;
			double fTemp1845 = (fConst291 * fRec2365[1]);
			double fTemp1846 = (0.0141527753 * fTemp92);
			double fTemp1847 = (0.030699223300000002 * fTemp98);
			double fTemp1848 = (0.017402420700000001 * fTemp102);
			double fTemp1849 = (0.063674887099999994 * fTemp104);
			double fTemp1850 = (fConst293 * ((((fTemp1600 + (fTemp1846 + fTemp1847)) + fTemp1848) + fTemp1849) - (fTemp1598 + fTemp1601)));
			double fTemp1851 = (fConst294 * fRec2368[1]);
			double fTemp1852 = (fConst295 * fRec2371[1]);
			fRec2373[0] = (fTemp1850 + (fTemp1851 + (fRec2373[1] + fTemp1852)));
			fRec2371[0] = fRec2373[0];
			double fRec2372 = ((fTemp1852 + fTemp1851) + fTemp1850);
			fRec2370[0] = (fRec2371[0] + fRec2370[1]);
			fRec2368[0] = fRec2370[0];
			double fRec2369 = fRec2372;
			fRec2367[0] = (fTemp1845 + (fRec2369 + fRec2367[1]));
			fRec2365[0] = fRec2367[0];
			double fRec2366 = (fRec2369 + fTemp1845);
			double fTemp1853 = (0.035118094900000001 * fTemp109);
			double fTemp1854 = (0.017857837000000001 * fTemp111);
			double fTemp1855 = (fConst284 * (fTemp1583 - (fTemp1853 + fTemp1854)));
			double fTemp1856 = (fConst285 * fRec2374[1]);
			fRec2376[0] = (fTemp1855 + (fRec2376[1] + fTemp1856));
			fRec2374[0] = fRec2376[0];
			double fRec2375 = (fTemp1856 + fTemp1855);
			double fTemp1857 = (0.0083809489000000008 * fTemp119);
			double fTemp1858 = (0.0052956836 * fTemp121);
			double fTemp1859 = (fConst287 * (((fTemp1590 + fTemp1857) + fTemp1858) - (fTemp1591 + fTemp1589)));
			double fTemp1860 = (fConst288 * fRec2377[1]);
			double fTemp1861 = (fConst289 * fRec2380[1]);
			fRec2382[0] = (fTemp1859 + (fTemp1860 + (fRec2382[1] + fTemp1861)));
			fRec2380[0] = fRec2382[0];
			double fRec2381 = ((fTemp1861 + fTemp1860) + fTemp1859);
			fRec2379[0] = (fRec2380[0] + fRec2379[1]);
			fRec2377[0] = fRec2379[0];
			double fRec2378 = fRec2381;
			fVec35[(IOTA & 511)] = (fTemp1582 + (fRec2321 + (fRec2339 + (fRec2354 + (fRec2366 + (fRec2375 + fRec2378))))));
			output36[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec35[((IOTA - iConst322) & 511)])));
			double fTemp1862 = (fConst273 * fRec2383[1]);
			double fTemp1863 = (fConst274 * fRec2386[1]);
			double fTemp1864 = (fConst276 * fRec2389[1]);
			double fTemp1865 = (fConst277 * fRec2392[1]);
			double fTemp1866 = (fConst279 * ((fTemp1425 + (fTemp1415 + (fTemp1417 + (fTemp1419 + (fTemp1424 + (fTemp1422 + fTemp1414)))))) - (fTemp1416 + (fTemp1418 + (fTemp1420 + (fTemp1413 + (fTemp1421 + fTemp1423)))))));
			double fTemp1867 = (fConst280 * fRec2395[1]);
			double fTemp1868 = (fConst281 * fRec2398[1]);
			fRec2400[0] = (fTemp1866 + (fTemp1867 + (fRec2400[1] + fTemp1868)));
			fRec2398[0] = fRec2400[0];
			double fRec2399 = ((fTemp1868 + fTemp1867) + fTemp1866);
			fRec2397[0] = (fRec2398[0] + fRec2397[1]);
			fRec2395[0] = fRec2397[0];
			double fRec2396 = fRec2399;
			fRec2394[0] = (fTemp1864 + (fTemp1865 + (fRec2396 + fRec2394[1])));
			fRec2392[0] = fRec2394[0];
			double fRec2393 = (fTemp1864 + (fRec2396 + fTemp1865));
			fRec2391[0] = (fRec2392[0] + fRec2391[1]);
			fRec2389[0] = fRec2391[0];
			double fRec2390 = fRec2393;
			fRec2388[0] = (fTemp1862 + (fTemp1863 + (fRec2390 + fRec2388[1])));
			fRec2386[0] = fRec2388[0];
			double fRec2387 = (fTemp1862 + (fRec2390 + fTemp1863));
			fRec2385[0] = (fRec2386[0] + fRec2385[1]);
			fRec2383[0] = fRec2385[0];
			double fRec2384 = fRec2387;
			double fTemp1869 = (fConst264 * fRec2401[1]);
			double fTemp1870 = (fConst266 * fRec2404[1]);
			double fTemp1871 = (fConst267 * fRec2407[1]);
			double fTemp1872 = (fConst269 * ((fTemp1405 + (fTemp1395 + (fTemp1396 + (fTemp1400 + fTemp1402)))) - (fTemp1399 + (fTemp1404 + (fTemp1398 + (fTemp1403 + (fTemp1401 + fTemp1397)))))));
			double fTemp1873 = (fConst270 * fRec2410[1]);
			double fTemp1874 = (fConst271 * fRec2413[1]);
			fRec2415[0] = (fTemp1872 + (fTemp1873 + (fRec2415[1] + fTemp1874)));
			fRec2413[0] = fRec2415[0];
			double fRec2414 = ((fTemp1874 + fTemp1873) + fTemp1872);
			fRec2412[0] = (fRec2413[0] + fRec2412[1]);
			fRec2410[0] = fRec2412[0];
			double fRec2411 = fRec2414;
			fRec2409[0] = (fTemp1870 + (fTemp1871 + (fRec2411 + fRec2409[1])));
			fRec2407[0] = fRec2409[0];
			double fRec2408 = (fTemp1870 + (fRec2411 + fTemp1871));
			fRec2406[0] = (fRec2407[0] + fRec2406[1]);
			fRec2404[0] = fRec2406[0];
			double fRec2405 = fRec2408;
			fRec2403[0] = (fTemp1869 + (fRec2405 + fRec2403[1]));
			fRec2401[0] = fRec2403[0];
			double fRec2402 = (fRec2405 + fTemp1869);
			double fTemp1875 = (fConst257 * fRec2416[1]);
			double fTemp1876 = (fConst258 * fRec2419[1]);
			double fTemp1877 = (fConst260 * ((fTemp1381 + (fTemp1383 + fTemp1387)) - (fTemp1385 + (fTemp1380 + (fTemp1382 + (fTemp1386 + (fTemp1384 + fTemp1388)))))));
			double fTemp1878 = (fConst261 * fRec2422[1]);
			double fTemp1879 = (fConst262 * fRec2425[1]);
			fRec2427[0] = (fTemp1877 + (fTemp1878 + (fRec2427[1] + fTemp1879)));
			fRec2425[0] = fRec2427[0];
			double fRec2426 = ((fTemp1879 + fTemp1878) + fTemp1877);
			fRec2424[0] = (fRec2425[0] + fRec2424[1]);
			fRec2422[0] = fRec2424[0];
			double fRec2423 = fRec2426;
			fRec2421[0] = (fTemp1875 + (fTemp1876 + (fRec2423 + fRec2421[1])));
			fRec2419[0] = fRec2421[0];
			double fRec2420 = (fTemp1875 + (fRec2423 + fTemp1876));
			fRec2418[0] = (fRec2419[0] + fRec2418[1]);
			fRec2416[0] = fRec2418[0];
			double fRec2417 = fRec2420;
			double fTemp1880 = (fConst251 * fRec2428[1]);
			double fTemp1881 = (fConst253 * ((fTemp1370 + (fTemp1374 + (fTemp1373 + fTemp1369))) - (fTemp1371 + (fTemp1368 + fTemp1372))));
			double fTemp1882 = (fConst254 * fRec2431[1]);
			double fTemp1883 = (fConst255 * fRec2434[1]);
			fRec2436[0] = (fTemp1881 + (fTemp1882 + (fRec2436[1] + fTemp1883)));
			fRec2434[0] = fRec2436[0];
			double fRec2435 = ((fTemp1883 + fTemp1882) + fTemp1881);
			fRec2433[0] = (fRec2434[0] + fRec2433[1]);
			fRec2431[0] = fRec2433[0];
			double fRec2432 = fRec2435;
			fRec2430[0] = (fTemp1880 + (fRec2432 + fRec2430[1]));
			fRec2428[0] = fRec2430[0];
			double fRec2429 = (fRec2432 + fTemp1880);
			double fTemp1884 = (fConst244 * (fTemp1355 - (fTemp1354 + fTemp1356)));
			double fTemp1885 = (fConst245 * fRec2437[1]);
			fRec2439[0] = (fTemp1884 + (fRec2439[1] + fTemp1885));
			fRec2437[0] = fRec2439[0];
			double fRec2438 = (fTemp1885 + fTemp1884);
			double fTemp1886 = (fConst247 * ((fTemp1360 + (fTemp1363 + (fTemp1359 + fTemp1361))) - fTemp1362));
			double fTemp1887 = (fConst248 * fRec2440[1]);
			double fTemp1888 = (fConst249 * fRec2443[1]);
			fRec2445[0] = (fTemp1886 + (fTemp1887 + (fRec2445[1] + fTemp1888)));
			fRec2443[0] = fRec2445[0];
			double fRec2444 = ((fTemp1888 + fTemp1887) + fTemp1886);
			fRec2442[0] = (fRec2443[0] + fRec2442[1]);
			fRec2440[0] = fRec2442[0];
			double fRec2441 = fRec2444;
			fVec36[(IOTA & 511)] = (fTemp1353 + (fRec2384 + (fRec2402 + (fRec2417 + (fRec2429 + (fRec2438 + fRec2441))))));
			output37[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec36[((IOTA - iConst282) & 511)])));
			double fTemp1889 = (fConst313 * fRec2446[1]);
			double fTemp1890 = (fConst314 * fRec2449[1]);
			double fTemp1891 = (fConst316 * fRec2452[1]);
			double fTemp1892 = (fConst317 * fRec2455[1]);
			double fTemp1893 = (fConst319 * ((fTemp1502 + (fTemp1490 + (fTemp1496 + (fTemp1498 + (fTemp1501 + (fTemp1492 + fTemp1495)))))) - (fTemp1497 + (fTemp1491 + (fTemp1499 + (fTemp1494 + (fTemp1493 + fTemp1500)))))));
			double fTemp1894 = (fConst320 * fRec2458[1]);
			double fTemp1895 = (fConst321 * fRec2461[1]);
			fRec2463[0] = (fTemp1893 + (fTemp1894 + (fRec2463[1] + fTemp1895)));
			fRec2461[0] = fRec2463[0];
			double fRec2462 = ((fTemp1895 + fTemp1894) + fTemp1893);
			fRec2460[0] = (fRec2461[0] + fRec2460[1]);
			fRec2458[0] = fRec2460[0];
			double fRec2459 = fRec2462;
			fRec2457[0] = (fTemp1891 + (fTemp1892 + (fRec2459 + fRec2457[1])));
			fRec2455[0] = fRec2457[0];
			double fRec2456 = (fTemp1891 + (fRec2459 + fTemp1892));
			fRec2454[0] = (fRec2455[0] + fRec2454[1]);
			fRec2452[0] = fRec2454[0];
			double fRec2453 = fRec2456;
			fRec2451[0] = (fTemp1889 + (fTemp1890 + (fRec2453 + fRec2451[1])));
			fRec2449[0] = fRec2451[0];
			double fRec2450 = (fTemp1889 + (fRec2453 + fTemp1890));
			fRec2448[0] = (fRec2449[0] + fRec2448[1]);
			fRec2446[0] = fRec2448[0];
			double fRec2447 = fRec2450;
			double fTemp1896 = (fConst304 * fRec2464[1]);
			double fTemp1897 = (fConst306 * fRec2467[1]);
			double fTemp1898 = (fConst307 * fRec2470[1]);
			double fTemp1899 = (fConst309 * ((fTemp1482 + (fTemp1477 + (fTemp1481 + (fTemp1472 + (fTemp1479 + fTemp1474))))) - (fTemp1476 + (fTemp1480 + (fTemp1475 + (fTemp1473 + fTemp1478))))));
			double fTemp1900 = (fConst310 * fRec2473[1]);
			double fTemp1901 = (fConst311 * fRec2476[1]);
			fRec2478[0] = (fTemp1899 + (fTemp1900 + (fRec2478[1] + fTemp1901)));
			fRec2476[0] = fRec2478[0];
			double fRec2477 = ((fTemp1901 + fTemp1900) + fTemp1899);
			fRec2475[0] = (fRec2476[0] + fRec2475[1]);
			fRec2473[0] = fRec2475[0];
			double fRec2474 = fRec2477;
			fRec2472[0] = (fTemp1897 + (fTemp1898 + (fRec2474 + fRec2472[1])));
			fRec2470[0] = fRec2472[0];
			double fRec2471 = (fTemp1897 + (fRec2474 + fTemp1898));
			fRec2469[0] = (fRec2470[0] + fRec2469[1]);
			fRec2467[0] = fRec2469[0];
			double fRec2468 = fRec2471;
			fRec2466[0] = (fTemp1896 + (fRec2468 + fRec2466[1]));
			fRec2464[0] = fRec2466[0];
			double fRec2465 = (fRec2468 + fTemp1896);
			double fTemp1902 = (fConst297 * fRec2479[1]);
			double fTemp1903 = (fConst298 * fRec2482[1]);
			double fTemp1904 = (fConst300 * ((fTemp1457 + (fTemp1464 + (fTemp1459 + (fTemp1465 + fTemp1460)))) - (fTemp1462 + (fTemp1456 + (fTemp1463 + fTemp1458)))));
			double fTemp1905 = (fConst301 * fRec2485[1]);
			double fTemp1906 = (fConst302 * fRec2488[1]);
			fRec2490[0] = (fTemp1904 + (fTemp1905 + (fRec2490[1] + fTemp1906)));
			fRec2488[0] = fRec2490[0];
			double fRec2489 = ((fTemp1906 + fTemp1905) + fTemp1904);
			fRec2487[0] = (fRec2488[0] + fRec2487[1]);
			fRec2485[0] = fRec2487[0];
			double fRec2486 = fRec2489;
			fRec2484[0] = (fTemp1902 + (fTemp1903 + (fRec2486 + fRec2484[1])));
			fRec2482[0] = fRec2484[0];
			double fRec2483 = (fTemp1902 + (fRec2486 + fTemp1903));
			fRec2481[0] = (fRec2482[0] + fRec2481[1]);
			fRec2479[0] = fRec2481[0];
			double fRec2480 = fRec2483;
			double fTemp1907 = (fConst291 * fRec2491[1]);
			double fTemp1908 = (fConst293 * ((fTemp1450 + (fTemp1449 + fTemp1445)) - (fTemp1446 + (fTemp1447 + (fTemp1444 + fTemp1448)))));
			double fTemp1909 = (fConst294 * fRec2494[1]);
			double fTemp1910 = (fConst295 * fRec2497[1]);
			fRec2499[0] = (fTemp1908 + (fTemp1909 + (fRec2499[1] + fTemp1910)));
			fRec2497[0] = fRec2499[0];
			double fRec2498 = ((fTemp1910 + fTemp1909) + fTemp1908);
			fRec2496[0] = (fRec2497[0] + fRec2496[1]);
			fRec2494[0] = fRec2496[0];
			double fRec2495 = fRec2498;
			fRec2493[0] = (fTemp1907 + (fRec2495 + fRec2493[1]));
			fRec2491[0] = fRec2493[0];
			double fRec2492 = (fRec2495 + fTemp1907);
			double fTemp1911 = (fConst284 * (fTemp1431 - (fTemp1430 + fTemp1432)));
			double fTemp1912 = (fConst285 * fRec2500[1]);
			fRec2502[0] = (fTemp1911 + (fRec2502[1] + fTemp1912));
			fRec2500[0] = fRec2502[0];
			double fRec2501 = (fTemp1912 + fTemp1911);
			double fTemp1913 = (fConst287 * ((fTemp1436 + (fTemp1439 + (fTemp1435 + fTemp1437))) - fTemp1438));
			double fTemp1914 = (fConst288 * fRec2503[1]);
			double fTemp1915 = (fConst289 * fRec2506[1]);
			fRec2508[0] = (fTemp1913 + (fTemp1914 + (fRec2508[1] + fTemp1915)));
			fRec2506[0] = fRec2508[0];
			double fRec2507 = ((fTemp1915 + fTemp1914) + fTemp1913);
			fRec2505[0] = (fRec2506[0] + fRec2505[1]);
			fRec2503[0] = fRec2505[0];
			double fRec2504 = fRec2507;
			fVec37[(IOTA & 511)] = (fTemp1429 + (fRec2447 + (fRec2465 + (fRec2480 + (fRec2492 + (fRec2501 + fRec2504))))));
			output38[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec37[((IOTA - iConst322) & 511)])));
			double fTemp1916 = (fConst273 * fRec2509[1]);
			double fTemp1917 = (fConst274 * fRec2512[1]);
			double fTemp1918 = (fConst276 * fRec2515[1]);
			double fTemp1919 = (fConst277 * fRec2518[1]);
			double fTemp1920 = (fConst279 * ((fTemp1566 + (fTemp1570 + (fTemp1572 + (fTemp1576 + (fTemp1575 + fTemp1568))))) - (fTemp1571 + (fTemp1578 + (fTemp1567 + (fTemp1577 + (fTemp1569 + (fTemp1574 + fTemp1573))))))));
			double fTemp1921 = (fConst280 * fRec2521[1]);
			double fTemp1922 = (fConst281 * fRec2524[1]);
			fRec2526[0] = (fTemp1920 + (fTemp1921 + (fRec2526[1] + fTemp1922)));
			fRec2524[0] = fRec2526[0];
			double fRec2525 = ((fTemp1922 + fTemp1921) + fTemp1920);
			fRec2523[0] = (fRec2524[0] + fRec2523[1]);
			fRec2521[0] = fRec2523[0];
			double fRec2522 = fRec2525;
			fRec2520[0] = (fTemp1918 + (fTemp1919 + (fRec2522 + fRec2520[1])));
			fRec2518[0] = fRec2520[0];
			double fRec2519 = (fTemp1918 + (fRec2522 + fTemp1919));
			fRec2517[0] = (fRec2518[0] + fRec2517[1]);
			fRec2515[0] = fRec2517[0];
			double fRec2516 = fRec2519;
			fRec2514[0] = (fTemp1916 + (fTemp1917 + (fRec2516 + fRec2514[1])));
			fRec2512[0] = fRec2514[0];
			double fRec2513 = (fTemp1916 + (fRec2516 + fTemp1917));
			fRec2511[0] = (fRec2512[0] + fRec2511[1]);
			fRec2509[0] = fRec2511[0];
			double fRec2510 = fRec2513;
			double fTemp1923 = (fConst264 * fRec2527[1]);
			double fTemp1924 = (fConst266 * fRec2530[1]);
			double fTemp1925 = (fConst267 * fRec2533[1]);
			double fTemp1926 = (fConst269 * ((fTemp1558 + (fTemp1548 + (fTemp1553 + (fTemp1555 + (fTemp1554 + fTemp1549))))) - (fTemp1551 + (fTemp1552 + (fTemp1550 + (fTemp1556 + fTemp1557))))));
			double fTemp1927 = (fConst270 * fRec2536[1]);
			double fTemp1928 = (fConst271 * fRec2539[1]);
			fRec2541[0] = (fTemp1926 + (fTemp1927 + (fRec2541[1] + fTemp1928)));
			fRec2539[0] = fRec2541[0];
			double fRec2540 = ((fTemp1928 + fTemp1927) + fTemp1926);
			fRec2538[0] = (fRec2539[0] + fRec2538[1]);
			fRec2536[0] = fRec2538[0];
			double fRec2537 = fRec2540;
			fRec2535[0] = (fTemp1924 + (fTemp1925 + (fRec2537 + fRec2535[1])));
			fRec2533[0] = fRec2535[0];
			double fRec2534 = (fTemp1924 + (fRec2537 + fTemp1925));
			fRec2532[0] = (fRec2533[0] + fRec2532[1]);
			fRec2530[0] = fRec2532[0];
			double fRec2531 = fRec2534;
			fRec2529[0] = (fTemp1923 + (fRec2531 + fRec2529[1]));
			fRec2527[0] = fRec2529[0];
			double fRec2528 = (fRec2531 + fTemp1923);
			double fTemp1929 = (fConst257 * fRec2542[1]);
			double fTemp1930 = (fConst258 * fRec2545[1]);
			double fTemp1931 = (fConst260 * ((fTemp1533 + (fTemp1535 + (fTemp1537 + (fTemp1539 + (fTemp1541 + fTemp1536))))) - (fTemp1534 + (fTemp1540 + fTemp1538))));
			double fTemp1932 = (fConst261 * fRec2548[1]);
			double fTemp1933 = (fConst262 * fRec2551[1]);
			fRec2553[0] = (fTemp1931 + (fTemp1932 + (fRec2553[1] + fTemp1933)));
			fRec2551[0] = fRec2553[0];
			double fRec2552 = ((fTemp1933 + fTemp1932) + fTemp1931);
			fRec2550[0] = (fRec2551[0] + fRec2550[1]);
			fRec2548[0] = fRec2550[0];
			double fRec2549 = fRec2552;
			fRec2547[0] = (fTemp1929 + (fTemp1930 + (fRec2549 + fRec2547[1])));
			fRec2545[0] = fRec2547[0];
			double fRec2546 = (fTemp1929 + (fRec2549 + fTemp1930));
			fRec2544[0] = (fRec2545[0] + fRec2544[1]);
			fRec2542[0] = fRec2544[0];
			double fRec2543 = fRec2546;
			double fTemp1934 = (fConst251 * fRec2554[1]);
			double fTemp1935 = (fConst253 * ((fTemp1523 + (fTemp1527 + (fTemp1522 + (fTemp1524 + fTemp1526)))) - (fTemp1525 + fTemp1521)));
			double fTemp1936 = (fConst254 * fRec2557[1]);
			double fTemp1937 = (fConst255 * fRec2560[1]);
			fRec2562[0] = (fTemp1935 + (fTemp1936 + (fRec2562[1] + fTemp1937)));
			fRec2560[0] = fRec2562[0];
			double fRec2561 = ((fTemp1937 + fTemp1936) + fTemp1935);
			fRec2559[0] = (fRec2560[0] + fRec2559[1]);
			fRec2557[0] = fRec2559[0];
			double fRec2558 = fRec2561;
			fRec2556[0] = (fTemp1934 + (fRec2558 + fRec2556[1]));
			fRec2554[0] = fRec2556[0];
			double fRec2555 = (fRec2558 + fTemp1934);
			double fTemp1938 = (fConst244 * ((fTemp1509 + fTemp1507) - fTemp1508));
			double fTemp1939 = (fConst245 * fRec2563[1]);
			fRec2565[0] = (fTemp1938 + (fRec2565[1] + fTemp1939));
			fRec2563[0] = fRec2565[0];
			double fRec2564 = (fTemp1939 + fTemp1938);
			double fTemp1940 = (fConst247 * ((fTemp1512 + (fTemp1514 + fTemp1516)) - (fTemp1513 + fTemp1515)));
			double fTemp1941 = (fConst248 * fRec2566[1]);
			double fTemp1942 = (fConst249 * fRec2569[1]);
			fRec2571[0] = (fTemp1940 + (fTemp1941 + (fRec2571[1] + fTemp1942)));
			fRec2569[0] = fRec2571[0];
			double fRec2570 = ((fTemp1942 + fTemp1941) + fTemp1940);
			fRec2568[0] = (fRec2569[0] + fRec2568[1]);
			fRec2566[0] = fRec2568[0];
			double fRec2567 = fRec2570;
			fVec38[(IOTA & 511)] = (fTemp1506 + (fRec2510 + (fRec2528 + (fRec2543 + (fRec2555 + (fRec2564 + fRec2567))))));
			output39[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec38[((IOTA - iConst282) & 511)])));
			double fTemp1943 = (fConst313 * fRec2572[1]);
			double fTemp1944 = (fConst314 * fRec2575[1]);
			double fTemp1945 = (fConst316 * fRec2578[1]);
			double fTemp1946 = (fConst317 * fRec2581[1]);
			double fTemp1947 = (fConst319 * ((fTemp1654 + (fTemp1642 + (fTemp1646 + (fTemp1648 + (fTemp1652 + (fTemp1651 + fTemp1644)))))) - (fTemp1647 + (fTemp1643 + (fTemp1653 + (fTemp1645 + (fTemp1650 + fTemp1649)))))));
			double fTemp1948 = (fConst320 * fRec2584[1]);
			double fTemp1949 = (fConst321 * fRec2587[1]);
			fRec2589[0] = (fTemp1947 + (fTemp1948 + (fRec2589[1] + fTemp1949)));
			fRec2587[0] = fRec2589[0];
			double fRec2588 = ((fTemp1949 + fTemp1948) + fTemp1947);
			fRec2586[0] = (fRec2587[0] + fRec2586[1]);
			fRec2584[0] = fRec2586[0];
			double fRec2585 = fRec2588;
			fRec2583[0] = (fTemp1945 + (fTemp1946 + (fRec2585 + fRec2583[1])));
			fRec2581[0] = fRec2583[0];
			double fRec2582 = (fTemp1945 + (fRec2585 + fTemp1946));
			fRec2580[0] = (fRec2581[0] + fRec2580[1]);
			fRec2578[0] = fRec2580[0];
			double fRec2579 = fRec2582;
			fRec2577[0] = (fTemp1943 + (fTemp1944 + (fRec2579 + fRec2577[1])));
			fRec2575[0] = fRec2577[0];
			double fRec2576 = (fTemp1943 + (fRec2579 + fTemp1944));
			fRec2574[0] = (fRec2575[0] + fRec2574[1]);
			fRec2572[0] = fRec2574[0];
			double fRec2573 = fRec2576;
			double fTemp1950 = (fConst304 * fRec2590[1]);
			double fTemp1951 = (fConst306 * fRec2593[1]);
			double fTemp1952 = (fConst307 * fRec2596[1]);
			double fTemp1953 = (fConst309 * ((fTemp1628 + (fTemp1634 + (fTemp1624 + (fTemp1631 + (fTemp1632 + fTemp1625))))) - (fTemp1629 + (fTemp1627 + (fTemp1630 + (fTemp1626 + fTemp1633))))));
			double fTemp1954 = (fConst310 * fRec2599[1]);
			double fTemp1955 = (fConst311 * fRec2602[1]);
			fRec2604[0] = (fTemp1953 + (fTemp1954 + (fRec2604[1] + fTemp1955)));
			fRec2602[0] = fRec2604[0];
			double fRec2603 = ((fTemp1955 + fTemp1954) + fTemp1953);
			fRec2601[0] = (fRec2602[0] + fRec2601[1]);
			fRec2599[0] = fRec2601[0];
			double fRec2600 = fRec2603;
			fRec2598[0] = (fTemp1951 + (fTemp1952 + (fRec2600 + fRec2598[1])));
			fRec2596[0] = fRec2598[0];
			double fRec2597 = (fTemp1951 + (fRec2600 + fTemp1952));
			fRec2595[0] = (fRec2596[0] + fRec2595[1]);
			fRec2593[0] = fRec2595[0];
			double fRec2594 = fRec2597;
			fRec2592[0] = (fTemp1950 + (fRec2594 + fRec2592[1]));
			fRec2590[0] = fRec2592[0];
			double fRec2591 = (fRec2594 + fTemp1950);
			double fTemp1956 = (fConst297 * fRec2605[1]);
			double fTemp1957 = (fConst298 * fRec2608[1]);
			double fTemp1958 = (fTemp1615 + fTemp1617);
			double fTemp1959 = (fConst300 * ((fTemp1609 + (fTemp1613 + (fTemp1614 + (fTemp1612 + fTemp1616)))) - (fTemp1610 + (fTemp1611 + fTemp1958))));
			double fTemp1960 = (fConst301 * fRec2611[1]);
			double fTemp1961 = (fConst302 * fRec2614[1]);
			fRec2616[0] = (fTemp1959 + (fTemp1960 + (fRec2616[1] + fTemp1961)));
			fRec2614[0] = fRec2616[0];
			double fRec2615 = ((fTemp1961 + fTemp1960) + fTemp1959);
			fRec2613[0] = (fRec2614[0] + fRec2613[1]);
			fRec2611[0] = fRec2613[0];
			double fRec2612 = fRec2615;
			fRec2610[0] = (fTemp1956 + (fTemp1957 + (fRec2612 + fRec2610[1])));
			fRec2608[0] = fRec2610[0];
			double fRec2609 = (fTemp1956 + (fRec2612 + fTemp1957));
			fRec2607[0] = (fRec2608[0] + fRec2607[1]);
			fRec2605[0] = fRec2607[0];
			double fRec2606 = fRec2609;
			double fTemp1962 = (fConst291 * fRec2617[1]);
			double fTemp1963 = (fConst293 * ((fTemp1601 + (fTemp1603 + (fTemp1600 + (fTemp1602 + fTemp1598)))) - (fTemp1599 + fTemp1597)));
			double fTemp1964 = (fConst294 * fRec2620[1]);
			double fTemp1965 = (fConst295 * fRec2623[1]);
			fRec2625[0] = (fTemp1963 + (fTemp1964 + (fRec2625[1] + fTemp1965)));
			fRec2623[0] = fRec2625[0];
			double fRec2624 = ((fTemp1965 + fTemp1964) + fTemp1963);
			fRec2622[0] = (fRec2623[0] + fRec2622[1]);
			fRec2620[0] = fRec2622[0];
			double fRec2621 = fRec2624;
			fRec2619[0] = (fTemp1962 + (fRec2621 + fRec2619[1]));
			fRec2617[0] = fRec2619[0];
			double fRec2618 = (fRec2621 + fTemp1962);
			double fTemp1966 = (fConst284 * ((fTemp1585 + fTemp1583) - fTemp1584));
			double fTemp1967 = (fConst285 * fRec2626[1]);
			fRec2628[0] = (fTemp1966 + (fRec2628[1] + fTemp1967));
			fRec2626[0] = fRec2628[0];
			double fRec2627 = (fTemp1967 + fTemp1966);
			double fTemp1968 = (fConst287 * ((fTemp1592 + fTemp1589) - (fTemp1591 + (fTemp1590 + fTemp1588))));
			double fTemp1969 = (fConst288 * fRec2629[1]);
			double fTemp1970 = (fConst289 * fRec2632[1]);
			fRec2634[0] = (fTemp1968 + (fTemp1969 + (fRec2634[1] + fTemp1970)));
			fRec2632[0] = fRec2634[0];
			double fRec2633 = ((fTemp1970 + fTemp1969) + fTemp1968);
			fRec2631[0] = (fRec2632[0] + fRec2631[1]);
			fRec2629[0] = fRec2631[0];
			double fRec2630 = fRec2633;
			fVec39[(IOTA & 511)] = (fTemp1582 + (fRec2573 + (fRec2591 + (fRec2606 + (fRec2618 + (fRec2627 + fRec2630))))));
			output40[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec39[((IOTA - iConst322) & 511)])));
			double fTemp1971 = (fConst273 * fRec2635[1]);
			double fTemp1972 = (fConst274 * fRec2638[1]);
			double fTemp1973 = (fConst276 * fRec2641[1]);
			double fTemp1974 = (fConst277 * fRec2644[1]);
			double fTemp1975 = (fConst279 * ((fTemp1416 + (fTemp1705 + (fTemp1415 + (fTemp1704 + (fTemp1418 + (fTemp1702 + (fTemp1421 + fTemp1703))))))) - (fTemp1420 + (fTemp1701 + (fTemp1414 + (fTemp1423 + fTemp1700))))));
			double fTemp1976 = (fConst280 * fRec2647[1]);
			double fTemp1977 = (fConst281 * fRec2650[1]);
			fRec2652[0] = (fTemp1975 + (fTemp1976 + (fRec2652[1] + fTemp1977)));
			fRec2650[0] = fRec2652[0];
			double fRec2651 = ((fTemp1977 + fTemp1976) + fTemp1975);
			fRec2649[0] = (fRec2650[0] + fRec2649[1]);
			fRec2647[0] = fRec2649[0];
			double fRec2648 = fRec2651;
			fRec2646[0] = (fTemp1973 + (fTemp1974 + (fRec2648 + fRec2646[1])));
			fRec2644[0] = fRec2646[0];
			double fRec2645 = (fTemp1973 + (fRec2648 + fTemp1974));
			fRec2643[0] = (fRec2644[0] + fRec2643[1]);
			fRec2641[0] = fRec2643[0];
			double fRec2642 = fRec2645;
			fRec2640[0] = (fTemp1971 + (fTemp1972 + (fRec2642 + fRec2640[1])));
			fRec2638[0] = fRec2640[0];
			double fRec2639 = (fTemp1971 + (fRec2642 + fTemp1972));
			fRec2637[0] = (fRec2638[0] + fRec2637[1]);
			fRec2635[0] = fRec2637[0];
			double fRec2636 = fRec2639;
			double fTemp1978 = (fConst264 * fRec2653[1]);
			double fTemp1979 = (fConst266 * fRec2656[1]);
			double fTemp1980 = (fConst267 * fRec2659[1]);
			double fTemp1981 = (fConst269 * ((fTemp1692 + (fTemp1395 + (fTemp1404 + fTemp1691))) - (fTemp1687 + (fTemp1690 + (fTemp1403 + (fTemp1396 + (fTemp1689 + (fTemp1401 + fTemp1688))))))));
			double fTemp1982 = (fConst270 * fRec2662[1]);
			double fTemp1983 = (fConst271 * fRec2665[1]);
			fRec2667[0] = (fTemp1981 + (fTemp1982 + (fRec2667[1] + fTemp1983)));
			fRec2665[0] = fRec2667[0];
			double fRec2666 = ((fTemp1983 + fTemp1982) + fTemp1981);
			fRec2664[0] = (fRec2665[0] + fRec2664[1]);
			fRec2662[0] = fRec2664[0];
			double fRec2663 = fRec2666;
			fRec2661[0] = (fTemp1979 + (fTemp1980 + (fRec2663 + fRec2661[1])));
			fRec2659[0] = fRec2661[0];
			double fRec2660 = (fTemp1979 + (fRec2663 + fTemp1980));
			fRec2658[0] = (fRec2659[0] + fRec2658[1]);
			fRec2656[0] = fRec2658[0];
			double fRec2657 = fRec2660;
			fRec2655[0] = (fTemp1978 + (fRec2657 + fRec2655[1]));
			fRec2653[0] = fRec2655[0];
			double fRec2654 = (fRec2657 + fTemp1978);
			double fTemp1984 = (fConst257 * fRec2668[1]);
			double fTemp1985 = (fConst258 * fRec2671[1]);
			double fTemp1986 = (fConst260 * ((fTemp1385 + (fTemp1381 + (fTemp1680 + (fTemp1383 + fTemp1386)))) - (fTemp1677 + (fTemp1678 + (fTemp1388 + fTemp1679)))));
			double fTemp1987 = (fConst261 * fRec2674[1]);
			double fTemp1988 = (fConst262 * fRec2677[1]);
			fRec2679[0] = (fTemp1986 + (fTemp1987 + (fRec2679[1] + fTemp1988)));
			fRec2677[0] = fRec2679[0];
			double fRec2678 = ((fTemp1988 + fTemp1987) + fTemp1986);
			fRec2676[0] = (fRec2677[0] + fRec2676[1]);
			fRec2674[0] = fRec2676[0];
			double fRec2675 = fRec2678;
			fRec2673[0] = (fTemp1984 + (fTemp1985 + (fRec2675 + fRec2673[1])));
			fRec2671[0] = fRec2673[0];
			double fRec2672 = (fTemp1984 + (fRec2675 + fTemp1985));
			fRec2670[0] = (fRec2671[0] + fRec2670[1]);
			fRec2668[0] = fRec2670[0];
			double fRec2669 = fRec2672;
			double fTemp1989 = (fConst251 * fRec2680[1]);
			double fTemp1990 = (fConst253 * ((fTemp1671 + (fTemp1371 + (fTemp1670 + (fTemp1369 + (fTemp1372 + fTemp1669))))) - fTemp1668));
			double fTemp1991 = (fConst254 * fRec2683[1]);
			double fTemp1992 = (fConst255 * fRec2686[1]);
			fRec2688[0] = (fTemp1990 + (fTemp1991 + (fRec2688[1] + fTemp1992)));
			fRec2686[0] = fRec2688[0];
			double fRec2687 = ((fTemp1992 + fTemp1991) + fTemp1990);
			fRec2685[0] = (fRec2686[0] + fRec2685[1]);
			fRec2683[0] = fRec2685[0];
			double fRec2684 = fRec2687;
			fRec2682[0] = (fTemp1989 + (fRec2684 + fRec2682[1]));
			fRec2680[0] = fRec2682[0];
			double fRec2681 = (fRec2684 + fTemp1989);
			double fTemp1993 = (fConst244 * ((fTemp1355 + fTemp1659) - fTemp1658));
			double fTemp1994 = (fConst245 * fRec2689[1]);
			fRec2691[0] = (fTemp1993 + (fRec2691[1] + fTemp1994));
			fRec2689[0] = fRec2691[0];
			double fRec2690 = (fTemp1994 + fTemp1993);
			double fTemp1995 = (fConst247 * (fTemp1663 - (fTemp1360 + (fTemp1362 + (fTemp1359 + fTemp1662)))));
			double fTemp1996 = (fConst248 * fRec2692[1]);
			double fTemp1997 = (fConst249 * fRec2695[1]);
			fRec2697[0] = (fTemp1995 + (fTemp1996 + (fRec2697[1] + fTemp1997)));
			fRec2695[0] = fRec2697[0];
			double fRec2696 = ((fTemp1997 + fTemp1996) + fTemp1995);
			fRec2694[0] = (fRec2695[0] + fRec2694[1]);
			fRec2692[0] = fRec2694[0];
			double fRec2693 = fRec2696;
			fVec40[(IOTA & 511)] = (fTemp1353 + (fRec2636 + (fRec2654 + (fRec2669 + (fRec2681 + (fRec2690 + fRec2693))))));
			output41[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec40[((IOTA - iConst282) & 511)])));
			double fTemp1998 = (fConst313 * fRec2698[1]);
			double fTemp1999 = (fConst314 * fRec2701[1]);
			double fTemp2000 = (fConst316 * fRec2704[1]);
			double fTemp2001 = (fConst317 * fRec2707[1]);
			double fTemp2002 = (fConst319 * ((fTemp1497 + (fTemp1490 + (fTemp1756 + fTemp1755))) - (fTemp1751 + (fTemp1496 + (fTemp1499 + (fTemp1754 + (fTemp1495 + (fTemp1753 + (fTemp1500 + (fTemp1492 + fTemp1752))))))))));
			double fTemp2003 = (fConst320 * fRec2710[1]);
			double fTemp2004 = (fConst321 * fRec2713[1]);
			fRec2715[0] = (fTemp2002 + (fTemp2003 + (fRec2715[1] + fTemp2004)));
			fRec2713[0] = fRec2715[0];
			double fRec2714 = ((fTemp2004 + fTemp2003) + fTemp2002);
			fRec2712[0] = (fRec2713[0] + fRec2712[1]);
			fRec2710[0] = fRec2712[0];
			double fRec2711 = fRec2714;
			fRec2709[0] = (fTemp2000 + (fTemp2001 + (fRec2711 + fRec2709[1])));
			fRec2707[0] = fRec2709[0];
			double fRec2708 = (fTemp2000 + (fRec2711 + fTemp2001));
			fRec2706[0] = (fRec2707[0] + fRec2706[1]);
			fRec2704[0] = fRec2706[0];
			double fRec2705 = fRec2708;
			fRec2703[0] = (fTemp1998 + (fTemp1999 + (fRec2705 + fRec2703[1])));
			fRec2701[0] = fRec2703[0];
			double fRec2702 = (fTemp1998 + (fRec2705 + fTemp1999));
			fRec2700[0] = (fRec2701[0] + fRec2700[1]);
			fRec2698[0] = fRec2700[0];
			double fRec2699 = fRec2702;
			double fTemp2005 = (fConst304 * fRec2716[1]);
			double fTemp2006 = (fConst306 * fRec2719[1]);
			double fTemp2007 = (fConst307 * fRec2722[1]);
			double fTemp2008 = (fConst309 * ((fTemp1477 + (fTemp1743 + fTemp1742)) - (fTemp1738 + (fTemp1741 + (fTemp1472 + (fTemp1740 + (fTemp1480 + (fTemp1474 + (fTemp1478 + fTemp1739)))))))));
			double fTemp2009 = (fConst310 * fRec2725[1]);
			double fTemp2010 = (fConst311 * fRec2728[1]);
			fRec2730[0] = (fTemp2008 + (fTemp2009 + (fRec2730[1] + fTemp2010)));
			fRec2728[0] = fRec2730[0];
			double fRec2729 = ((fTemp2010 + fTemp2009) + fTemp2008);
			fRec2727[0] = (fRec2728[0] + fRec2727[1]);
			fRec2725[0] = fRec2727[0];
			double fRec2726 = fRec2729;
			fRec2724[0] = (fTemp2006 + (fTemp2007 + (fRec2726 + fRec2724[1])));
			fRec2722[0] = fRec2724[0];
			double fRec2723 = (fTemp2006 + (fRec2726 + fTemp2007));
			fRec2721[0] = (fRec2722[0] + fRec2721[1]);
			fRec2719[0] = fRec2721[0];
			double fRec2720 = fRec2723;
			fRec2718[0] = (fTemp2005 + (fRec2720 + fRec2718[1]));
			fRec2716[0] = fRec2718[0];
			double fRec2717 = (fRec2720 + fTemp2005);
			double fTemp2011 = (fConst297 * fRec2731[1]);
			double fTemp2012 = (fConst298 * fRec2734[1]);
			double fTemp2013 = (fConst300 * ((fTemp1462 + (fTemp1457 + (fTemp1731 + (fTemp1463 + (fTemp1461 + fTemp1730))))) - (fTemp1728 + fTemp1729)));
			double fTemp2014 = (fConst301 * fRec2737[1]);
			double fTemp2015 = (fConst302 * fRec2740[1]);
			fRec2742[0] = (fTemp2013 + (fTemp2014 + (fRec2742[1] + fTemp2015)));
			fRec2740[0] = fRec2742[0];
			double fRec2741 = ((fTemp2015 + fTemp2014) + fTemp2013);
			fRec2739[0] = (fRec2740[0] + fRec2739[1]);
			fRec2737[0] = fRec2739[0];
			double fRec2738 = fRec2741;
			fRec2736[0] = (fTemp2011 + (fTemp2012 + (fRec2738 + fRec2736[1])));
			fRec2734[0] = fRec2736[0];
			double fRec2735 = (fTemp2011 + (fRec2738 + fTemp2012));
			fRec2733[0] = (fRec2734[0] + fRec2733[1]);
			fRec2731[0] = fRec2733[0];
			double fRec2732 = fRec2735;
			double fTemp2016 = (fConst291 * fRec2743[1]);
			double fTemp2017 = (fConst293 * ((fTemp1722 + (fTemp1447 + (fTemp1721 + (fTemp1448 + fTemp1445)))) - (fTemp1719 + fTemp1720)));
			double fTemp2018 = (fConst294 * fRec2746[1]);
			double fTemp2019 = (fConst295 * fRec2749[1]);
			fRec2751[0] = (fTemp2017 + (fTemp2018 + (fRec2751[1] + fTemp2019)));
			fRec2749[0] = fRec2751[0];
			double fRec2750 = ((fTemp2019 + fTemp2018) + fTemp2017);
			fRec2748[0] = (fRec2749[0] + fRec2748[1]);
			fRec2746[0] = fRec2748[0];
			double fRec2747 = fRec2750;
			fRec2745[0] = (fTemp2016 + (fRec2747 + fRec2745[1]));
			fRec2743[0] = fRec2745[0];
			double fRec2744 = (fRec2747 + fTemp2016);
			double fTemp2020 = (fConst284 * ((fTemp1431 + fTemp1710) - fTemp1709));
			double fTemp2021 = (fConst285 * fRec2752[1]);
			fRec2754[0] = (fTemp2020 + (fRec2754[1] + fTemp2021));
			fRec2752[0] = fRec2754[0];
			double fRec2753 = (fTemp2021 + fTemp2020);
			double fTemp2022 = (fConst287 * (fTemp1714 - (fTemp1436 + (fTemp1438 + (fTemp1435 + fTemp1713)))));
			double fTemp2023 = (fConst288 * fRec2755[1]);
			double fTemp2024 = (fConst289 * fRec2758[1]);
			fRec2760[0] = (fTemp2022 + (fTemp2023 + (fRec2760[1] + fTemp2024)));
			fRec2758[0] = fRec2760[0];
			double fRec2759 = ((fTemp2024 + fTemp2023) + fTemp2022);
			fRec2757[0] = (fRec2758[0] + fRec2757[1]);
			fRec2755[0] = fRec2757[0];
			double fRec2756 = fRec2759;
			fVec41[(IOTA & 511)] = (fTemp1429 + (fRec2699 + (fRec2717 + (fRec2732 + (fRec2744 + (fRec2753 + fRec2756))))));
			output42[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec41[((IOTA - iConst322) & 511)])));
			double fTemp2025 = (fConst273 * fRec2761[1]);
			double fTemp2026 = (fConst274 * fRec2764[1]);
			double fTemp2027 = (fConst276 * fRec2767[1]);
			double fTemp2028 = (fConst277 * fRec2770[1]);
			double fTemp2029 = (fConst279 * ((fTemp1802 + (fTemp1573 + (fTemp1568 + (fTemp1574 + fTemp1803)))) - (fTemp1566 + (fTemp1578 + (fTemp1801 + (fTemp1570 + (fTemp1800 + (fTemp1577 + (fTemp1799 + fTemp1798)))))))));
			double fTemp2030 = (fConst280 * fRec2773[1]);
			double fTemp2031 = (fConst281 * fRec2776[1]);
			fRec2778[0] = (fTemp2029 + (fTemp2030 + (fRec2778[1] + fTemp2031)));
			fRec2776[0] = fRec2778[0];
			double fRec2777 = ((fTemp2031 + fTemp2030) + fTemp2029);
			fRec2775[0] = (fRec2776[0] + fRec2775[1]);
			fRec2773[0] = fRec2775[0];
			double fRec2774 = fRec2777;
			fRec2772[0] = (fTemp2027 + (fTemp2028 + (fRec2774 + fRec2772[1])));
			fRec2770[0] = fRec2772[0];
			double fRec2771 = (fTemp2027 + (fRec2774 + fTemp2028));
			fRec2769[0] = (fRec2770[0] + fRec2769[1]);
			fRec2767[0] = fRec2769[0];
			double fRec2768 = fRec2771;
			fRec2766[0] = (fTemp2025 + (fTemp2026 + (fRec2768 + fRec2766[1])));
			fRec2764[0] = fRec2766[0];
			double fRec2765 = (fTemp2025 + (fRec2768 + fTemp2026));
			fRec2763[0] = (fRec2764[0] + fRec2763[1]);
			fRec2761[0] = fRec2763[0];
			double fRec2762 = fRec2765;
			double fTemp2032 = (fConst264 * fRec2779[1]);
			double fTemp2033 = (fConst266 * fRec2782[1]);
			double fTemp2034 = (fConst267 * fRec2785[1]);
			double fTemp2035 = (fConst269 * ((fTemp1790 + (fTemp1791 + (fTemp1794 + (fTemp1556 + (fTemp1793 + (fTemp1549 + fTemp1792)))))) - (fTemp1552 + (fTemp1789 + (fTemp1557 + fTemp1548)))));
			double fTemp2036 = (fConst270 * fRec2788[1]);
			double fTemp2037 = (fConst271 * fRec2791[1]);
			fRec2793[0] = (fTemp2035 + (fTemp2036 + (fRec2793[1] + fTemp2037)));
			fRec2791[0] = fRec2793[0];
			double fRec2792 = ((fTemp2037 + fTemp2036) + fTemp2035);
			fRec2790[0] = (fRec2791[0] + fRec2790[1]);
			fRec2788[0] = fRec2790[0];
			double fRec2789 = fRec2792;
			fRec2787[0] = (fTemp2033 + (fTemp2034 + (fRec2789 + fRec2787[1])));
			fRec2785[0] = fRec2787[0];
			double fRec2786 = (fTemp2033 + (fRec2789 + fTemp2034));
			fRec2784[0] = (fRec2785[0] + fRec2784[1]);
			fRec2782[0] = fRec2784[0];
			double fRec2783 = fRec2786;
			fRec2781[0] = (fTemp2032 + (fRec2783 + fRec2781[1]));
			fRec2779[0] = fRec2781[0];
			double fRec2780 = (fRec2783 + fTemp2032);
			double fTemp2038 = (fConst257 * fRec2794[1]);
			double fTemp2039 = (fConst258 * fRec2797[1]);
			double fTemp2040 = (fConst260 * ((fTemp1780 + (fTemp1535 + (fTemp1782 + (fTemp1538 + (fTemp1536 + fTemp1781))))) - (fTemp1533 + (fTemp1540 + fTemp1779))));
			double fTemp2041 = (fConst261 * fRec2800[1]);
			double fTemp2042 = (fConst262 * fRec2803[1]);
			fRec2805[0] = (fTemp2040 + (fTemp2041 + (fRec2805[1] + fTemp2042)));
			fRec2803[0] = fRec2805[0];
			double fRec2804 = ((fTemp2042 + fTemp2041) + fTemp2040);
			fRec2802[0] = (fRec2803[0] + fRec2802[1]);
			fRec2800[0] = fRec2802[0];
			double fRec2801 = fRec2804;
			fRec2799[0] = (fTemp2038 + (fTemp2039 + (fRec2801 + fRec2799[1])));
			fRec2797[0] = fRec2799[0];
			double fRec2798 = (fTemp2038 + (fRec2801 + fTemp2039));
			fRec2796[0] = (fRec2797[0] + fRec2796[1]);
			fRec2794[0] = fRec2796[0];
			double fRec2795 = fRec2798;
			double fTemp2043 = (fConst251 * fRec2806[1]);
			double fTemp2044 = (fConst253 * ((fTemp1773 + (fTemp1525 + fTemp1522)) - (fTemp1772 + (fTemp1523 + (fTemp1770 + fTemp1771)))));
			double fTemp2045 = (fConst254 * fRec2809[1]);
			double fTemp2046 = (fConst255 * fRec2812[1]);
			fRec2814[0] = (fTemp2044 + (fTemp2045 + (fRec2814[1] + fTemp2046)));
			fRec2812[0] = fRec2814[0];
			double fRec2813 = ((fTemp2046 + fTemp2045) + fTemp2044);
			fRec2811[0] = (fRec2812[0] + fRec2811[1]);
			fRec2809[0] = fRec2811[0];
			double fRec2810 = fRec2813;
			fRec2808[0] = (fTemp2043 + (fRec2810 + fRec2808[1]));
			fRec2806[0] = fRec2808[0];
			double fRec2807 = (fRec2810 + fTemp2043);
			double fTemp2047 = (fConst244 * (fTemp1761 + (fTemp1507 + fTemp1760)));
			double fTemp2048 = (fConst245 * fRec2815[1]);
			fRec2817[0] = (fTemp2047 + (fRec2817[1] + fTemp2048));
			fRec2815[0] = fRec2817[0];
			double fRec2816 = (fTemp2048 + fTemp2047);
			double fTemp2049 = (fConst247 * ((fTemp1513 + fTemp1765) - (fTemp1512 + (fTemp1515 + fTemp1764))));
			double fTemp2050 = (fConst248 * fRec2818[1]);
			double fTemp2051 = (fConst249 * fRec2821[1]);
			fRec2823[0] = (fTemp2049 + (fTemp2050 + (fRec2823[1] + fTemp2051)));
			fRec2821[0] = fRec2823[0];
			double fRec2822 = ((fTemp2051 + fTemp2050) + fTemp2049);
			fRec2820[0] = (fRec2821[0] + fRec2820[1]);
			fRec2818[0] = fRec2820[0];
			double fRec2819 = fRec2822;
			fVec42[(IOTA & 511)] = (fTemp1506 + (fRec2762 + (fRec2780 + (fRec2795 + (fRec2807 + (fRec2816 + fRec2819))))));
			output43[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec42[((IOTA - iConst282) & 511)])));
			double fTemp2052 = (fConst313 * fRec2824[1]);
			double fTemp2053 = (fConst314 * fRec2827[1]);
			double fTemp2054 = (fConst316 * fRec2830[1]);
			double fTemp2055 = (fConst317 * fRec2833[1]);
			double fTemp2056 = (fConst319 * ((fTemp1647 + (fTemp1820 + (fTemp1642 + (fTemp1649 + (fTemp1650 + fTemp1644))))) - (fTemp1819 + (fTemp1646 + (fTemp1815 + (fTemp1653 + (fTemp1816 + (fTemp1817 + fTemp1818))))))));
			double fTemp2057 = (fConst320 * fRec2836[1]);
			double fTemp2058 = (fConst321 * fRec2839[1]);
			fRec2841[0] = (fTemp2056 + (fTemp2057 + (fRec2841[1] + fTemp2058)));
			fRec2839[0] = fRec2841[0];
			double fRec2840 = ((fTemp2058 + fTemp2057) + fTemp2056);
			fRec2838[0] = (fRec2839[0] + fRec2838[1]);
			fRec2836[0] = fRec2838[0];
			double fRec2837 = fRec2840;
			fRec2835[0] = (fTemp2054 + (fTemp2055 + (fRec2837 + fRec2835[1])));
			fRec2833[0] = fRec2835[0];
			double fRec2834 = (fTemp2054 + (fRec2837 + fTemp2055));
			fRec2832[0] = (fRec2833[0] + fRec2832[1]);
			fRec2830[0] = fRec2832[0];
			double fRec2831 = fRec2834;
			fRec2829[0] = (fTemp2052 + (fTemp2053 + (fRec2831 + fRec2829[1])));
			fRec2827[0] = fRec2829[0];
			double fRec2828 = (fTemp2052 + (fRec2831 + fTemp2053));
			fRec2826[0] = (fRec2827[0] + fRec2826[1]);
			fRec2824[0] = fRec2826[0];
			double fRec2825 = fRec2828;
			double fTemp2059 = (fConst304 * fRec2842[1]);
			double fTemp2060 = (fConst306 * fRec2845[1]);
			double fTemp2061 = (fConst307 * fRec2848[1]);
			double fTemp2062 = (fConst309 * ((fTemp1828 + (fTemp1829 + (fTemp1830 + (fTemp1832 + (fTemp1633 + (fTemp1625 + fTemp1831)))))) - (fTemp1629 + (fTemp1624 + (fTemp1630 + fTemp1827)))));
			double fTemp2063 = (fConst310 * fRec2851[1]);
			double fTemp2064 = (fConst311 * fRec2854[1]);
			fRec2856[0] = (fTemp2062 + (fTemp2063 + (fRec2856[1] + fTemp2064)));
			fRec2854[0] = fRec2856[0];
			double fRec2855 = ((fTemp2064 + fTemp2063) + fTemp2062);
			fRec2853[0] = (fRec2854[0] + fRec2853[1]);
			fRec2851[0] = fRec2853[0];
			double fRec2852 = fRec2855;
			fRec2850[0] = (fTemp2060 + (fTemp2061 + (fRec2852 + fRec2850[1])));
			fRec2848[0] = fRec2850[0];
			double fRec2849 = (fTemp2060 + (fRec2852 + fTemp2061));
			fRec2847[0] = (fRec2848[0] + fRec2847[1]);
			fRec2845[0] = fRec2847[0];
			double fRec2846 = fRec2849;
			fRec2844[0] = (fTemp2059 + (fRec2846 + fRec2844[1]));
			fRec2842[0] = fRec2844[0];
			double fRec2843 = (fRec2846 + fTemp2059);
			double fTemp2065 = (fConst297 * fRec2857[1]);
			double fTemp2066 = (fConst298 * fRec2860[1]);
			double fTemp2067 = (fConst300 * ((fTemp1838 + (fTemp1613 + (fTemp1839 + (fTemp1840 + fTemp1841)))) - (fTemp1609 + (fTemp1612 + fTemp1958))));
			double fTemp2068 = (fConst301 * fRec2863[1]);
			double fTemp2069 = (fConst302 * fRec2866[1]);
			fRec2868[0] = (fTemp2067 + (fTemp2068 + (fRec2868[1] + fTemp2069)));
			fRec2866[0] = fRec2868[0];
			double fRec2867 = ((fTemp2069 + fTemp2068) + fTemp2067);
			fRec2865[0] = (fRec2866[0] + fRec2865[1]);
			fRec2863[0] = fRec2865[0];
			double fRec2864 = fRec2867;
			fRec2862[0] = (fTemp2065 + (fTemp2066 + (fRec2864 + fRec2862[1])));
			fRec2860[0] = fRec2862[0];
			double fRec2861 = (fTemp2065 + (fRec2864 + fTemp2066));
			fRec2859[0] = (fRec2860[0] + fRec2859[1]);
			fRec2857[0] = fRec2859[0];
			double fRec2858 = fRec2861;
			double fTemp2070 = (fConst291 * fRec2869[1]);
			double fTemp2071 = (fConst293 * (fTemp1600 - (fTemp1849 + (fTemp1601 + (fTemp1848 + (fTemp1847 + (fTemp1598 + fTemp1846)))))));
			double fTemp2072 = (fConst294 * fRec2872[1]);
			double fTemp2073 = (fConst295 * fRec2875[1]);
			fRec2877[0] = (fTemp2071 + (fTemp2072 + (fRec2877[1] + fTemp2073)));
			fRec2875[0] = fRec2877[0];
			double fRec2876 = ((fTemp2073 + fTemp2072) + fTemp2071);
			fRec2874[0] = (fRec2875[0] + fRec2874[1]);
			fRec2872[0] = fRec2874[0];
			double fRec2873 = fRec2876;
			fRec2871[0] = (fTemp2070 + (fRec2873 + fRec2871[1]));
			fRec2869[0] = fRec2871[0];
			double fRec2870 = (fRec2873 + fTemp2070);
			double fTemp2074 = (fConst284 * (fTemp1854 + (fTemp1583 + fTemp1853)));
			double fTemp2075 = (fConst285 * fRec2878[1]);
			fRec2880[0] = (fTemp2074 + (fRec2880[1] + fTemp2075));
			fRec2878[0] = fRec2880[0];
			double fRec2879 = (fTemp2075 + fTemp2074);
			double fTemp2076 = (fConst287 * (fTemp1590 - (fTemp1589 + (fTemp1858 + (fTemp1591 + fTemp1857)))));
			double fTemp2077 = (fConst288 * fRec2881[1]);
			double fTemp2078 = (fConst289 * fRec2884[1]);
			fRec2886[0] = (fTemp2076 + (fTemp2077 + (fRec2886[1] + fTemp2078)));
			fRec2884[0] = fRec2886[0];
			double fRec2885 = ((fTemp2078 + fTemp2077) + fTemp2076);
			fRec2883[0] = (fRec2884[0] + fRec2883[1]);
			fRec2881[0] = fRec2883[0];
			double fRec2882 = fRec2885;
			fVec43[(IOTA & 511)] = (fTemp1582 + (fRec2825 + (fRec2843 + (fRec2858 + (fRec2870 + (fRec2879 + fRec2882))))));
			output44[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec43[((IOTA - iConst322) & 511)])));
			fRec0[1] = fRec0[0];
			fRec20[1] = fRec20[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
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
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
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
			fRec3[1] = fRec3[0];
			fRec1[1] = fRec1[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec51[2] = fRec51[1];
			fRec51[1] = fRec51[0];
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
			fRec57[2] = fRec57[1];
			fRec57[1] = fRec57[0];
			fRec58[2] = fRec58[1];
			fRec58[1] = fRec58[0];
			fRec59[2] = fRec59[1];
			fRec59[1] = fRec59[0];
			fRec48[1] = fRec48[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec34[1] = fRec34[0];
			fRec72[2] = fRec72[1];
			fRec72[1] = fRec72[0];
			fRec73[2] = fRec73[1];
			fRec73[1] = fRec73[0];
			fRec74[2] = fRec74[1];
			fRec74[1] = fRec74[0];
			fRec75[2] = fRec75[1];
			fRec75[1] = fRec75[0];
			fRec76[2] = fRec76[1];
			fRec76[1] = fRec76[0];
			fRec77[2] = fRec77[1];
			fRec77[1] = fRec77[0];
			fRec78[2] = fRec78[1];
			fRec78[1] = fRec78[0];
			fRec79[2] = fRec79[1];
			fRec79[1] = fRec79[0];
			fRec80[2] = fRec80[1];
			fRec80[1] = fRec80[0];
			fRec71[1] = fRec71[0];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			fRec66[1] = fRec66[0];
			fRec65[1] = fRec65[0];
			fRec63[1] = fRec63[0];
			fRec62[1] = fRec62[0];
			fRec60[1] = fRec60[0];
			fRec90[2] = fRec90[1];
			fRec90[1] = fRec90[0];
			fRec91[2] = fRec91[1];
			fRec91[1] = fRec91[0];
			fRec92[2] = fRec92[1];
			fRec92[1] = fRec92[0];
			fRec93[2] = fRec93[1];
			fRec93[1] = fRec93[0];
			fRec94[2] = fRec94[1];
			fRec94[1] = fRec94[0];
			fRec95[2] = fRec95[1];
			fRec95[1] = fRec95[0];
			fRec96[2] = fRec96[1];
			fRec96[1] = fRec96[0];
			fRec89[1] = fRec89[0];
			fRec87[1] = fRec87[0];
			fRec86[1] = fRec86[0];
			fRec84[1] = fRec84[0];
			fRec83[1] = fRec83[0];
			fRec81[1] = fRec81[0];
			fRec100[2] = fRec100[1];
			fRec100[1] = fRec100[0];
			fRec101[2] = fRec101[1];
			fRec101[1] = fRec101[0];
			fRec102[2] = fRec102[1];
			fRec102[1] = fRec102[0];
			fRec99[1] = fRec99[0];
			fRec97[1] = fRec97[0];
			fRec109[2] = fRec109[1];
			fRec109[1] = fRec109[0];
			fRec110[2] = fRec110[1];
			fRec110[1] = fRec110[0];
			fRec111[2] = fRec111[1];
			fRec111[1] = fRec111[0];
			fRec112[2] = fRec112[1];
			fRec112[1] = fRec112[0];
			fRec113[2] = fRec113[1];
			fRec113[1] = fRec113[0];
			fRec108[1] = fRec108[0];
			fRec106[1] = fRec106[0];
			fRec105[1] = fRec105[0];
			fRec103[1] = fRec103[0];
			fRec114[2] = fRec114[1];
			fRec114[1] = fRec114[0];
			IOTA = (IOTA + 1);
			fRec132[1] = fRec132[0];
			fRec130[1] = fRec130[0];
			fRec129[1] = fRec129[0];
			fRec127[1] = fRec127[0];
			fRec126[1] = fRec126[0];
			fRec124[1] = fRec124[0];
			fRec123[1] = fRec123[0];
			fRec121[1] = fRec121[0];
			fRec120[1] = fRec120[0];
			fRec118[1] = fRec118[0];
			fRec117[1] = fRec117[0];
			fRec115[1] = fRec115[0];
			fRec147[1] = fRec147[0];
			fRec145[1] = fRec145[0];
			fRec144[1] = fRec144[0];
			fRec142[1] = fRec142[0];
			fRec141[1] = fRec141[0];
			fRec139[1] = fRec139[0];
			fRec138[1] = fRec138[0];
			fRec136[1] = fRec136[0];
			fRec135[1] = fRec135[0];
			fRec133[1] = fRec133[0];
			fRec159[1] = fRec159[0];
			fRec157[1] = fRec157[0];
			fRec156[1] = fRec156[0];
			fRec154[1] = fRec154[0];
			fRec153[1] = fRec153[0];
			fRec151[1] = fRec151[0];
			fRec150[1] = fRec150[0];
			fRec148[1] = fRec148[0];
			fRec168[1] = fRec168[0];
			fRec166[1] = fRec166[0];
			fRec165[1] = fRec165[0];
			fRec163[1] = fRec163[0];
			fRec162[1] = fRec162[0];
			fRec160[1] = fRec160[0];
			fRec171[1] = fRec171[0];
			fRec169[1] = fRec169[0];
			fRec177[1] = fRec177[0];
			fRec175[1] = fRec175[0];
			fRec174[1] = fRec174[0];
			fRec172[1] = fRec172[0];
			fRec183[1] = fRec183[0];
			fRec181[1] = fRec181[0];
			fRec180[1] = fRec180[0];
			fRec178[1] = fRec178[0];
			fRec186[1] = fRec186[0];
			fRec184[1] = fRec184[0];
			fRec195[1] = fRec195[0];
			fRec193[1] = fRec193[0];
			fRec192[1] = fRec192[0];
			fRec190[1] = fRec190[0];
			fRec189[1] = fRec189[0];
			fRec187[1] = fRec187[0];
			fRec213[1] = fRec213[0];
			fRec211[1] = fRec211[0];
			fRec210[1] = fRec210[0];
			fRec208[1] = fRec208[0];
			fRec207[1] = fRec207[0];
			fRec205[1] = fRec205[0];
			fRec204[1] = fRec204[0];
			fRec202[1] = fRec202[0];
			fRec201[1] = fRec201[0];
			fRec199[1] = fRec199[0];
			fRec198[1] = fRec198[0];
			fRec196[1] = fRec196[0];
			fRec225[1] = fRec225[0];
			fRec223[1] = fRec223[0];
			fRec222[1] = fRec222[0];
			fRec220[1] = fRec220[0];
			fRec219[1] = fRec219[0];
			fRec217[1] = fRec217[0];
			fRec216[1] = fRec216[0];
			fRec214[1] = fRec214[0];
			fRec240[1] = fRec240[0];
			fRec238[1] = fRec238[0];
			fRec237[1] = fRec237[0];
			fRec235[1] = fRec235[0];
			fRec234[1] = fRec234[0];
			fRec232[1] = fRec232[0];
			fRec231[1] = fRec231[0];
			fRec229[1] = fRec229[0];
			fRec228[1] = fRec228[0];
			fRec226[1] = fRec226[0];
			fRec243[1] = fRec243[0];
			fRec241[1] = fRec241[0];
			fRec261[1] = fRec261[0];
			fRec259[1] = fRec259[0];
			fRec258[1] = fRec258[0];
			fRec256[1] = fRec256[0];
			fRec255[1] = fRec255[0];
			fRec253[1] = fRec253[0];
			fRec252[1] = fRec252[0];
			fRec250[1] = fRec250[0];
			fRec249[1] = fRec249[0];
			fRec247[1] = fRec247[0];
			fRec246[1] = fRec246[0];
			fRec244[1] = fRec244[0];
			fRec276[1] = fRec276[0];
			fRec274[1] = fRec274[0];
			fRec273[1] = fRec273[0];
			fRec271[1] = fRec271[0];
			fRec270[1] = fRec270[0];
			fRec268[1] = fRec268[0];
			fRec267[1] = fRec267[0];
			fRec265[1] = fRec265[0];
			fRec264[1] = fRec264[0];
			fRec262[1] = fRec262[0];
			fRec288[1] = fRec288[0];
			fRec286[1] = fRec286[0];
			fRec285[1] = fRec285[0];
			fRec283[1] = fRec283[0];
			fRec282[1] = fRec282[0];
			fRec280[1] = fRec280[0];
			fRec279[1] = fRec279[0];
			fRec277[1] = fRec277[0];
			fRec294[1] = fRec294[0];
			fRec292[1] = fRec292[0];
			fRec291[1] = fRec291[0];
			fRec289[1] = fRec289[0];
			fRec303[1] = fRec303[0];
			fRec301[1] = fRec301[0];
			fRec300[1] = fRec300[0];
			fRec298[1] = fRec298[0];
			fRec297[1] = fRec297[0];
			fRec295[1] = fRec295[0];
			fRec321[1] = fRec321[0];
			fRec319[1] = fRec319[0];
			fRec318[1] = fRec318[0];
			fRec316[1] = fRec316[0];
			fRec315[1] = fRec315[0];
			fRec313[1] = fRec313[0];
			fRec312[1] = fRec312[0];
			fRec310[1] = fRec310[0];
			fRec309[1] = fRec309[0];
			fRec307[1] = fRec307[0];
			fRec306[1] = fRec306[0];
			fRec304[1] = fRec304[0];
			fRec336[1] = fRec336[0];
			fRec334[1] = fRec334[0];
			fRec333[1] = fRec333[0];
			fRec331[1] = fRec331[0];
			fRec330[1] = fRec330[0];
			fRec328[1] = fRec328[0];
			fRec327[1] = fRec327[0];
			fRec325[1] = fRec325[0];
			fRec324[1] = fRec324[0];
			fRec322[1] = fRec322[0];
			fRec348[1] = fRec348[0];
			fRec346[1] = fRec346[0];
			fRec345[1] = fRec345[0];
			fRec343[1] = fRec343[0];
			fRec342[1] = fRec342[0];
			fRec340[1] = fRec340[0];
			fRec339[1] = fRec339[0];
			fRec337[1] = fRec337[0];
			fRec357[1] = fRec357[0];
			fRec355[1] = fRec355[0];
			fRec354[1] = fRec354[0];
			fRec352[1] = fRec352[0];
			fRec351[1] = fRec351[0];
			fRec349[1] = fRec349[0];
			fRec360[1] = fRec360[0];
			fRec358[1] = fRec358[0];
			fRec366[1] = fRec366[0];
			fRec364[1] = fRec364[0];
			fRec363[1] = fRec363[0];
			fRec361[1] = fRec361[0];
			fRec384[1] = fRec384[0];
			fRec382[1] = fRec382[0];
			fRec381[1] = fRec381[0];
			fRec379[1] = fRec379[0];
			fRec378[1] = fRec378[0];
			fRec376[1] = fRec376[0];
			fRec375[1] = fRec375[0];
			fRec373[1] = fRec373[0];
			fRec372[1] = fRec372[0];
			fRec370[1] = fRec370[0];
			fRec369[1] = fRec369[0];
			fRec367[1] = fRec367[0];
			fRec399[1] = fRec399[0];
			fRec397[1] = fRec397[0];
			fRec396[1] = fRec396[0];
			fRec394[1] = fRec394[0];
			fRec393[1] = fRec393[0];
			fRec391[1] = fRec391[0];
			fRec390[1] = fRec390[0];
			fRec388[1] = fRec388[0];
			fRec387[1] = fRec387[0];
			fRec385[1] = fRec385[0];
			fRec411[1] = fRec411[0];
			fRec409[1] = fRec409[0];
			fRec408[1] = fRec408[0];
			fRec406[1] = fRec406[0];
			fRec405[1] = fRec405[0];
			fRec403[1] = fRec403[0];
			fRec402[1] = fRec402[0];
			fRec400[1] = fRec400[0];
			fRec420[1] = fRec420[0];
			fRec418[1] = fRec418[0];
			fRec417[1] = fRec417[0];
			fRec415[1] = fRec415[0];
			fRec414[1] = fRec414[0];
			fRec412[1] = fRec412[0];
			fRec423[1] = fRec423[0];
			fRec421[1] = fRec421[0];
			fRec429[1] = fRec429[0];
			fRec427[1] = fRec427[0];
			fRec426[1] = fRec426[0];
			fRec424[1] = fRec424[0];
			fRec447[1] = fRec447[0];
			fRec445[1] = fRec445[0];
			fRec444[1] = fRec444[0];
			fRec442[1] = fRec442[0];
			fRec441[1] = fRec441[0];
			fRec439[1] = fRec439[0];
			fRec438[1] = fRec438[0];
			fRec436[1] = fRec436[0];
			fRec435[1] = fRec435[0];
			fRec433[1] = fRec433[0];
			fRec432[1] = fRec432[0];
			fRec430[1] = fRec430[0];
			fRec462[1] = fRec462[0];
			fRec460[1] = fRec460[0];
			fRec459[1] = fRec459[0];
			fRec457[1] = fRec457[0];
			fRec456[1] = fRec456[0];
			fRec454[1] = fRec454[0];
			fRec453[1] = fRec453[0];
			fRec451[1] = fRec451[0];
			fRec450[1] = fRec450[0];
			fRec448[1] = fRec448[0];
			fRec474[1] = fRec474[0];
			fRec472[1] = fRec472[0];
			fRec471[1] = fRec471[0];
			fRec469[1] = fRec469[0];
			fRec468[1] = fRec468[0];
			fRec466[1] = fRec466[0];
			fRec465[1] = fRec465[0];
			fRec463[1] = fRec463[0];
			fRec483[1] = fRec483[0];
			fRec481[1] = fRec481[0];
			fRec480[1] = fRec480[0];
			fRec478[1] = fRec478[0];
			fRec477[1] = fRec477[0];
			fRec475[1] = fRec475[0];
			fRec486[1] = fRec486[0];
			fRec484[1] = fRec484[0];
			fRec492[1] = fRec492[0];
			fRec490[1] = fRec490[0];
			fRec489[1] = fRec489[0];
			fRec487[1] = fRec487[0];
			fRec510[1] = fRec510[0];
			fRec508[1] = fRec508[0];
			fRec507[1] = fRec507[0];
			fRec505[1] = fRec505[0];
			fRec504[1] = fRec504[0];
			fRec502[1] = fRec502[0];
			fRec501[1] = fRec501[0];
			fRec499[1] = fRec499[0];
			fRec498[1] = fRec498[0];
			fRec496[1] = fRec496[0];
			fRec495[1] = fRec495[0];
			fRec493[1] = fRec493[0];
			fRec525[1] = fRec525[0];
			fRec523[1] = fRec523[0];
			fRec522[1] = fRec522[0];
			fRec520[1] = fRec520[0];
			fRec519[1] = fRec519[0];
			fRec517[1] = fRec517[0];
			fRec516[1] = fRec516[0];
			fRec514[1] = fRec514[0];
			fRec513[1] = fRec513[0];
			fRec511[1] = fRec511[0];
			fRec537[1] = fRec537[0];
			fRec535[1] = fRec535[0];
			fRec534[1] = fRec534[0];
			fRec532[1] = fRec532[0];
			fRec531[1] = fRec531[0];
			fRec529[1] = fRec529[0];
			fRec528[1] = fRec528[0];
			fRec526[1] = fRec526[0];
			fRec546[1] = fRec546[0];
			fRec544[1] = fRec544[0];
			fRec543[1] = fRec543[0];
			fRec541[1] = fRec541[0];
			fRec540[1] = fRec540[0];
			fRec538[1] = fRec538[0];
			fRec549[1] = fRec549[0];
			fRec547[1] = fRec547[0];
			fRec555[1] = fRec555[0];
			fRec553[1] = fRec553[0];
			fRec552[1] = fRec552[0];
			fRec550[1] = fRec550[0];
			fRec567[1] = fRec567[0];
			fRec565[1] = fRec565[0];
			fRec564[1] = fRec564[0];
			fRec562[1] = fRec562[0];
			fRec561[1] = fRec561[0];
			fRec559[1] = fRec559[0];
			fRec558[1] = fRec558[0];
			fRec556[1] = fRec556[0];
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
			fRec603[1] = fRec603[0];
			fRec601[1] = fRec601[0];
			fRec600[1] = fRec600[0];
			fRec598[1] = fRec598[0];
			fRec597[1] = fRec597[0];
			fRec595[1] = fRec595[0];
			fRec594[1] = fRec594[0];
			fRec592[1] = fRec592[0];
			fRec591[1] = fRec591[0];
			fRec589[1] = fRec589[0];
			fRec588[1] = fRec588[0];
			fRec586[1] = fRec586[0];
			fRec618[1] = fRec618[0];
			fRec616[1] = fRec616[0];
			fRec615[1] = fRec615[0];
			fRec613[1] = fRec613[0];
			fRec612[1] = fRec612[0];
			fRec610[1] = fRec610[0];
			fRec609[1] = fRec609[0];
			fRec607[1] = fRec607[0];
			fRec606[1] = fRec606[0];
			fRec604[1] = fRec604[0];
			fRec636[1] = fRec636[0];
			fRec634[1] = fRec634[0];
			fRec633[1] = fRec633[0];
			fRec631[1] = fRec631[0];
			fRec630[1] = fRec630[0];
			fRec628[1] = fRec628[0];
			fRec627[1] = fRec627[0];
			fRec625[1] = fRec625[0];
			fRec624[1] = fRec624[0];
			fRec622[1] = fRec622[0];
			fRec621[1] = fRec621[0];
			fRec619[1] = fRec619[0];
			fRec651[1] = fRec651[0];
			fRec649[1] = fRec649[0];
			fRec648[1] = fRec648[0];
			fRec646[1] = fRec646[0];
			fRec645[1] = fRec645[0];
			fRec643[1] = fRec643[0];
			fRec642[1] = fRec642[0];
			fRec640[1] = fRec640[0];
			fRec639[1] = fRec639[0];
			fRec637[1] = fRec637[0];
			fRec663[1] = fRec663[0];
			fRec661[1] = fRec661[0];
			fRec660[1] = fRec660[0];
			fRec658[1] = fRec658[0];
			fRec657[1] = fRec657[0];
			fRec655[1] = fRec655[0];
			fRec654[1] = fRec654[0];
			fRec652[1] = fRec652[0];
			fRec672[1] = fRec672[0];
			fRec670[1] = fRec670[0];
			fRec669[1] = fRec669[0];
			fRec667[1] = fRec667[0];
			fRec666[1] = fRec666[0];
			fRec664[1] = fRec664[0];
			fRec675[1] = fRec675[0];
			fRec673[1] = fRec673[0];
			fRec681[1] = fRec681[0];
			fRec679[1] = fRec679[0];
			fRec678[1] = fRec678[0];
			fRec676[1] = fRec676[0];
			fRec699[1] = fRec699[0];
			fRec697[1] = fRec697[0];
			fRec696[1] = fRec696[0];
			fRec694[1] = fRec694[0];
			fRec693[1] = fRec693[0];
			fRec691[1] = fRec691[0];
			fRec690[1] = fRec690[0];
			fRec688[1] = fRec688[0];
			fRec687[1] = fRec687[0];
			fRec685[1] = fRec685[0];
			fRec684[1] = fRec684[0];
			fRec682[1] = fRec682[0];
			fRec714[1] = fRec714[0];
			fRec712[1] = fRec712[0];
			fRec711[1] = fRec711[0];
			fRec709[1] = fRec709[0];
			fRec708[1] = fRec708[0];
			fRec706[1] = fRec706[0];
			fRec705[1] = fRec705[0];
			fRec703[1] = fRec703[0];
			fRec702[1] = fRec702[0];
			fRec700[1] = fRec700[0];
			fRec726[1] = fRec726[0];
			fRec724[1] = fRec724[0];
			fRec723[1] = fRec723[0];
			fRec721[1] = fRec721[0];
			fRec720[1] = fRec720[0];
			fRec718[1] = fRec718[0];
			fRec717[1] = fRec717[0];
			fRec715[1] = fRec715[0];
			fRec735[1] = fRec735[0];
			fRec733[1] = fRec733[0];
			fRec732[1] = fRec732[0];
			fRec730[1] = fRec730[0];
			fRec729[1] = fRec729[0];
			fRec727[1] = fRec727[0];
			fRec738[1] = fRec738[0];
			fRec736[1] = fRec736[0];
			fRec744[1] = fRec744[0];
			fRec742[1] = fRec742[0];
			fRec741[1] = fRec741[0];
			fRec739[1] = fRec739[0];
			fRec756[1] = fRec756[0];
			fRec754[1] = fRec754[0];
			fRec753[1] = fRec753[0];
			fRec751[1] = fRec751[0];
			fRec750[1] = fRec750[0];
			fRec748[1] = fRec748[0];
			fRec747[1] = fRec747[0];
			fRec745[1] = fRec745[0];
			fRec765[1] = fRec765[0];
			fRec763[1] = fRec763[0];
			fRec762[1] = fRec762[0];
			fRec760[1] = fRec760[0];
			fRec759[1] = fRec759[0];
			fRec757[1] = fRec757[0];
			fRec771[1] = fRec771[0];
			fRec769[1] = fRec769[0];
			fRec768[1] = fRec768[0];
			fRec766[1] = fRec766[0];
			fRec774[1] = fRec774[0];
			fRec772[1] = fRec772[0];
			fRec792[1] = fRec792[0];
			fRec790[1] = fRec790[0];
			fRec789[1] = fRec789[0];
			fRec787[1] = fRec787[0];
			fRec786[1] = fRec786[0];
			fRec784[1] = fRec784[0];
			fRec783[1] = fRec783[0];
			fRec781[1] = fRec781[0];
			fRec780[1] = fRec780[0];
			fRec778[1] = fRec778[0];
			fRec777[1] = fRec777[0];
			fRec775[1] = fRec775[0];
			fRec807[1] = fRec807[0];
			fRec805[1] = fRec805[0];
			fRec804[1] = fRec804[0];
			fRec802[1] = fRec802[0];
			fRec801[1] = fRec801[0];
			fRec799[1] = fRec799[0];
			fRec798[1] = fRec798[0];
			fRec796[1] = fRec796[0];
			fRec795[1] = fRec795[0];
			fRec793[1] = fRec793[0];
			fRec825[1] = fRec825[0];
			fRec823[1] = fRec823[0];
			fRec822[1] = fRec822[0];
			fRec820[1] = fRec820[0];
			fRec819[1] = fRec819[0];
			fRec817[1] = fRec817[0];
			fRec816[1] = fRec816[0];
			fRec814[1] = fRec814[0];
			fRec813[1] = fRec813[0];
			fRec811[1] = fRec811[0];
			fRec810[1] = fRec810[0];
			fRec808[1] = fRec808[0];
			fRec840[1] = fRec840[0];
			fRec838[1] = fRec838[0];
			fRec837[1] = fRec837[0];
			fRec835[1] = fRec835[0];
			fRec834[1] = fRec834[0];
			fRec832[1] = fRec832[0];
			fRec831[1] = fRec831[0];
			fRec829[1] = fRec829[0];
			fRec828[1] = fRec828[0];
			fRec826[1] = fRec826[0];
			fRec852[1] = fRec852[0];
			fRec850[1] = fRec850[0];
			fRec849[1] = fRec849[0];
			fRec847[1] = fRec847[0];
			fRec846[1] = fRec846[0];
			fRec844[1] = fRec844[0];
			fRec843[1] = fRec843[0];
			fRec841[1] = fRec841[0];
			fRec861[1] = fRec861[0];
			fRec859[1] = fRec859[0];
			fRec858[1] = fRec858[0];
			fRec856[1] = fRec856[0];
			fRec855[1] = fRec855[0];
			fRec853[1] = fRec853[0];
			fRec864[1] = fRec864[0];
			fRec862[1] = fRec862[0];
			fRec870[1] = fRec870[0];
			fRec868[1] = fRec868[0];
			fRec867[1] = fRec867[0];
			fRec865[1] = fRec865[0];
			fRec888[1] = fRec888[0];
			fRec886[1] = fRec886[0];
			fRec885[1] = fRec885[0];
			fRec883[1] = fRec883[0];
			fRec882[1] = fRec882[0];
			fRec880[1] = fRec880[0];
			fRec879[1] = fRec879[0];
			fRec877[1] = fRec877[0];
			fRec876[1] = fRec876[0];
			fRec874[1] = fRec874[0];
			fRec873[1] = fRec873[0];
			fRec871[1] = fRec871[0];
			fRec903[1] = fRec903[0];
			fRec901[1] = fRec901[0];
			fRec900[1] = fRec900[0];
			fRec898[1] = fRec898[0];
			fRec897[1] = fRec897[0];
			fRec895[1] = fRec895[0];
			fRec894[1] = fRec894[0];
			fRec892[1] = fRec892[0];
			fRec891[1] = fRec891[0];
			fRec889[1] = fRec889[0];
			fRec915[1] = fRec915[0];
			fRec913[1] = fRec913[0];
			fRec912[1] = fRec912[0];
			fRec910[1] = fRec910[0];
			fRec909[1] = fRec909[0];
			fRec907[1] = fRec907[0];
			fRec906[1] = fRec906[0];
			fRec904[1] = fRec904[0];
			fRec924[1] = fRec924[0];
			fRec922[1] = fRec922[0];
			fRec921[1] = fRec921[0];
			fRec919[1] = fRec919[0];
			fRec918[1] = fRec918[0];
			fRec916[1] = fRec916[0];
			fRec927[1] = fRec927[0];
			fRec925[1] = fRec925[0];
			fRec933[1] = fRec933[0];
			fRec931[1] = fRec931[0];
			fRec930[1] = fRec930[0];
			fRec928[1] = fRec928[0];
			fRec951[1] = fRec951[0];
			fRec949[1] = fRec949[0];
			fRec948[1] = fRec948[0];
			fRec946[1] = fRec946[0];
			fRec945[1] = fRec945[0];
			fRec943[1] = fRec943[0];
			fRec942[1] = fRec942[0];
			fRec940[1] = fRec940[0];
			fRec939[1] = fRec939[0];
			fRec937[1] = fRec937[0];
			fRec936[1] = fRec936[0];
			fRec934[1] = fRec934[0];
			fRec963[1] = fRec963[0];
			fRec961[1] = fRec961[0];
			fRec960[1] = fRec960[0];
			fRec958[1] = fRec958[0];
			fRec957[1] = fRec957[0];
			fRec955[1] = fRec955[0];
			fRec954[1] = fRec954[0];
			fRec952[1] = fRec952[0];
			fRec972[1] = fRec972[0];
			fRec970[1] = fRec970[0];
			fRec969[1] = fRec969[0];
			fRec967[1] = fRec967[0];
			fRec966[1] = fRec966[0];
			fRec964[1] = fRec964[0];
			fRec975[1] = fRec975[0];
			fRec973[1] = fRec973[0];
			fRec981[1] = fRec981[0];
			fRec979[1] = fRec979[0];
			fRec978[1] = fRec978[0];
			fRec976[1] = fRec976[0];
			fRec996[1] = fRec996[0];
			fRec994[1] = fRec994[0];
			fRec993[1] = fRec993[0];
			fRec991[1] = fRec991[0];
			fRec990[1] = fRec990[0];
			fRec988[1] = fRec988[0];
			fRec987[1] = fRec987[0];
			fRec985[1] = fRec985[0];
			fRec984[1] = fRec984[0];
			fRec982[1] = fRec982[0];
			fRec1014[1] = fRec1014[0];
			fRec1012[1] = fRec1012[0];
			fRec1011[1] = fRec1011[0];
			fRec1009[1] = fRec1009[0];
			fRec1008[1] = fRec1008[0];
			fRec1006[1] = fRec1006[0];
			fRec1005[1] = fRec1005[0];
			fRec1003[1] = fRec1003[0];
			fRec1002[1] = fRec1002[0];
			fRec1000[1] = fRec1000[0];
			fRec999[1] = fRec999[0];
			fRec997[1] = fRec997[0];
			fRec1029[1] = fRec1029[0];
			fRec1027[1] = fRec1027[0];
			fRec1026[1] = fRec1026[0];
			fRec1024[1] = fRec1024[0];
			fRec1023[1] = fRec1023[0];
			fRec1021[1] = fRec1021[0];
			fRec1020[1] = fRec1020[0];
			fRec1018[1] = fRec1018[0];
			fRec1017[1] = fRec1017[0];
			fRec1015[1] = fRec1015[0];
			fRec1041[1] = fRec1041[0];
			fRec1039[1] = fRec1039[0];
			fRec1038[1] = fRec1038[0];
			fRec1036[1] = fRec1036[0];
			fRec1035[1] = fRec1035[0];
			fRec1033[1] = fRec1033[0];
			fRec1032[1] = fRec1032[0];
			fRec1030[1] = fRec1030[0];
			fRec1050[1] = fRec1050[0];
			fRec1048[1] = fRec1048[0];
			fRec1047[1] = fRec1047[0];
			fRec1045[1] = fRec1045[0];
			fRec1044[1] = fRec1044[0];
			fRec1042[1] = fRec1042[0];
			fRec1053[1] = fRec1053[0];
			fRec1051[1] = fRec1051[0];
			fRec1059[1] = fRec1059[0];
			fRec1057[1] = fRec1057[0];
			fRec1056[1] = fRec1056[0];
			fRec1054[1] = fRec1054[0];
			fRec1077[1] = fRec1077[0];
			fRec1075[1] = fRec1075[0];
			fRec1074[1] = fRec1074[0];
			fRec1072[1] = fRec1072[0];
			fRec1071[1] = fRec1071[0];
			fRec1069[1] = fRec1069[0];
			fRec1068[1] = fRec1068[0];
			fRec1066[1] = fRec1066[0];
			fRec1065[1] = fRec1065[0];
			fRec1063[1] = fRec1063[0];
			fRec1062[1] = fRec1062[0];
			fRec1060[1] = fRec1060[0];
			fRec1092[1] = fRec1092[0];
			fRec1090[1] = fRec1090[0];
			fRec1089[1] = fRec1089[0];
			fRec1087[1] = fRec1087[0];
			fRec1086[1] = fRec1086[0];
			fRec1084[1] = fRec1084[0];
			fRec1083[1] = fRec1083[0];
			fRec1081[1] = fRec1081[0];
			fRec1080[1] = fRec1080[0];
			fRec1078[1] = fRec1078[0];
			fRec1104[1] = fRec1104[0];
			fRec1102[1] = fRec1102[0];
			fRec1101[1] = fRec1101[0];
			fRec1099[1] = fRec1099[0];
			fRec1098[1] = fRec1098[0];
			fRec1096[1] = fRec1096[0];
			fRec1095[1] = fRec1095[0];
			fRec1093[1] = fRec1093[0];
			fRec1113[1] = fRec1113[0];
			fRec1111[1] = fRec1111[0];
			fRec1110[1] = fRec1110[0];
			fRec1108[1] = fRec1108[0];
			fRec1107[1] = fRec1107[0];
			fRec1105[1] = fRec1105[0];
			fRec1116[1] = fRec1116[0];
			fRec1114[1] = fRec1114[0];
			fRec1122[1] = fRec1122[0];
			fRec1120[1] = fRec1120[0];
			fRec1119[1] = fRec1119[0];
			fRec1117[1] = fRec1117[0];
			fRec1140[1] = fRec1140[0];
			fRec1138[1] = fRec1138[0];
			fRec1137[1] = fRec1137[0];
			fRec1135[1] = fRec1135[0];
			fRec1134[1] = fRec1134[0];
			fRec1132[1] = fRec1132[0];
			fRec1131[1] = fRec1131[0];
			fRec1129[1] = fRec1129[0];
			fRec1128[1] = fRec1128[0];
			fRec1126[1] = fRec1126[0];
			fRec1125[1] = fRec1125[0];
			fRec1123[1] = fRec1123[0];
			fRec1155[1] = fRec1155[0];
			fRec1153[1] = fRec1153[0];
			fRec1152[1] = fRec1152[0];
			fRec1150[1] = fRec1150[0];
			fRec1149[1] = fRec1149[0];
			fRec1147[1] = fRec1147[0];
			fRec1146[1] = fRec1146[0];
			fRec1144[1] = fRec1144[0];
			fRec1143[1] = fRec1143[0];
			fRec1141[1] = fRec1141[0];
			fRec1167[1] = fRec1167[0];
			fRec1165[1] = fRec1165[0];
			fRec1164[1] = fRec1164[0];
			fRec1162[1] = fRec1162[0];
			fRec1161[1] = fRec1161[0];
			fRec1159[1] = fRec1159[0];
			fRec1158[1] = fRec1158[0];
			fRec1156[1] = fRec1156[0];
			fRec1176[1] = fRec1176[0];
			fRec1174[1] = fRec1174[0];
			fRec1173[1] = fRec1173[0];
			fRec1171[1] = fRec1171[0];
			fRec1170[1] = fRec1170[0];
			fRec1168[1] = fRec1168[0];
			fRec1179[1] = fRec1179[0];
			fRec1177[1] = fRec1177[0];
			fRec1185[1] = fRec1185[0];
			fRec1183[1] = fRec1183[0];
			fRec1182[1] = fRec1182[0];
			fRec1180[1] = fRec1180[0];
			fRec1203[1] = fRec1203[0];
			fRec1201[1] = fRec1201[0];
			fRec1200[1] = fRec1200[0];
			fRec1198[1] = fRec1198[0];
			fRec1197[1] = fRec1197[0];
			fRec1195[1] = fRec1195[0];
			fRec1194[1] = fRec1194[0];
			fRec1192[1] = fRec1192[0];
			fRec1191[1] = fRec1191[0];
			fRec1189[1] = fRec1189[0];
			fRec1188[1] = fRec1188[0];
			fRec1186[1] = fRec1186[0];
			fRec1218[1] = fRec1218[0];
			fRec1216[1] = fRec1216[0];
			fRec1215[1] = fRec1215[0];
			fRec1213[1] = fRec1213[0];
			fRec1212[1] = fRec1212[0];
			fRec1210[1] = fRec1210[0];
			fRec1209[1] = fRec1209[0];
			fRec1207[1] = fRec1207[0];
			fRec1206[1] = fRec1206[0];
			fRec1204[1] = fRec1204[0];
			fRec1230[1] = fRec1230[0];
			fRec1228[1] = fRec1228[0];
			fRec1227[1] = fRec1227[0];
			fRec1225[1] = fRec1225[0];
			fRec1224[1] = fRec1224[0];
			fRec1222[1] = fRec1222[0];
			fRec1221[1] = fRec1221[0];
			fRec1219[1] = fRec1219[0];
			fRec1239[1] = fRec1239[0];
			fRec1237[1] = fRec1237[0];
			fRec1236[1] = fRec1236[0];
			fRec1234[1] = fRec1234[0];
			fRec1233[1] = fRec1233[0];
			fRec1231[1] = fRec1231[0];
			fRec1242[1] = fRec1242[0];
			fRec1240[1] = fRec1240[0];
			fRec1248[1] = fRec1248[0];
			fRec1246[1] = fRec1246[0];
			fRec1245[1] = fRec1245[0];
			fRec1243[1] = fRec1243[0];
			fRec1266[1] = fRec1266[0];
			fRec1264[1] = fRec1264[0];
			fRec1263[1] = fRec1263[0];
			fRec1261[1] = fRec1261[0];
			fRec1260[1] = fRec1260[0];
			fRec1258[1] = fRec1258[0];
			fRec1257[1] = fRec1257[0];
			fRec1255[1] = fRec1255[0];
			fRec1254[1] = fRec1254[0];
			fRec1252[1] = fRec1252[0];
			fRec1251[1] = fRec1251[0];
			fRec1249[1] = fRec1249[0];
			fRec1281[1] = fRec1281[0];
			fRec1279[1] = fRec1279[0];
			fRec1278[1] = fRec1278[0];
			fRec1276[1] = fRec1276[0];
			fRec1275[1] = fRec1275[0];
			fRec1273[1] = fRec1273[0];
			fRec1272[1] = fRec1272[0];
			fRec1270[1] = fRec1270[0];
			fRec1269[1] = fRec1269[0];
			fRec1267[1] = fRec1267[0];
			fRec1293[1] = fRec1293[0];
			fRec1291[1] = fRec1291[0];
			fRec1290[1] = fRec1290[0];
			fRec1288[1] = fRec1288[0];
			fRec1287[1] = fRec1287[0];
			fRec1285[1] = fRec1285[0];
			fRec1284[1] = fRec1284[0];
			fRec1282[1] = fRec1282[0];
			fRec1302[1] = fRec1302[0];
			fRec1300[1] = fRec1300[0];
			fRec1299[1] = fRec1299[0];
			fRec1297[1] = fRec1297[0];
			fRec1296[1] = fRec1296[0];
			fRec1294[1] = fRec1294[0];
			fRec1305[1] = fRec1305[0];
			fRec1303[1] = fRec1303[0];
			fRec1311[1] = fRec1311[0];
			fRec1309[1] = fRec1309[0];
			fRec1308[1] = fRec1308[0];
			fRec1306[1] = fRec1306[0];
			fRec1329[1] = fRec1329[0];
			fRec1327[1] = fRec1327[0];
			fRec1326[1] = fRec1326[0];
			fRec1324[1] = fRec1324[0];
			fRec1323[1] = fRec1323[0];
			fRec1321[1] = fRec1321[0];
			fRec1320[1] = fRec1320[0];
			fRec1318[1] = fRec1318[0];
			fRec1317[1] = fRec1317[0];
			fRec1315[1] = fRec1315[0];
			fRec1314[1] = fRec1314[0];
			fRec1312[1] = fRec1312[0];
			fRec1344[1] = fRec1344[0];
			fRec1342[1] = fRec1342[0];
			fRec1341[1] = fRec1341[0];
			fRec1339[1] = fRec1339[0];
			fRec1338[1] = fRec1338[0];
			fRec1336[1] = fRec1336[0];
			fRec1335[1] = fRec1335[0];
			fRec1333[1] = fRec1333[0];
			fRec1332[1] = fRec1332[0];
			fRec1330[1] = fRec1330[0];
			fRec1356[1] = fRec1356[0];
			fRec1354[1] = fRec1354[0];
			fRec1353[1] = fRec1353[0];
			fRec1351[1] = fRec1351[0];
			fRec1350[1] = fRec1350[0];
			fRec1348[1] = fRec1348[0];
			fRec1347[1] = fRec1347[0];
			fRec1345[1] = fRec1345[0];
			fRec1365[1] = fRec1365[0];
			fRec1363[1] = fRec1363[0];
			fRec1362[1] = fRec1362[0];
			fRec1360[1] = fRec1360[0];
			fRec1359[1] = fRec1359[0];
			fRec1357[1] = fRec1357[0];
			fRec1368[1] = fRec1368[0];
			fRec1366[1] = fRec1366[0];
			fRec1374[1] = fRec1374[0];
			fRec1372[1] = fRec1372[0];
			fRec1371[1] = fRec1371[0];
			fRec1369[1] = fRec1369[0];
			fRec1392[1] = fRec1392[0];
			fRec1390[1] = fRec1390[0];
			fRec1389[1] = fRec1389[0];
			fRec1387[1] = fRec1387[0];
			fRec1386[1] = fRec1386[0];
			fRec1384[1] = fRec1384[0];
			fRec1383[1] = fRec1383[0];
			fRec1381[1] = fRec1381[0];
			fRec1380[1] = fRec1380[0];
			fRec1378[1] = fRec1378[0];
			fRec1377[1] = fRec1377[0];
			fRec1375[1] = fRec1375[0];
			fRec1407[1] = fRec1407[0];
			fRec1405[1] = fRec1405[0];
			fRec1404[1] = fRec1404[0];
			fRec1402[1] = fRec1402[0];
			fRec1401[1] = fRec1401[0];
			fRec1399[1] = fRec1399[0];
			fRec1398[1] = fRec1398[0];
			fRec1396[1] = fRec1396[0];
			fRec1395[1] = fRec1395[0];
			fRec1393[1] = fRec1393[0];
			fRec1419[1] = fRec1419[0];
			fRec1417[1] = fRec1417[0];
			fRec1416[1] = fRec1416[0];
			fRec1414[1] = fRec1414[0];
			fRec1413[1] = fRec1413[0];
			fRec1411[1] = fRec1411[0];
			fRec1410[1] = fRec1410[0];
			fRec1408[1] = fRec1408[0];
			fRec1428[1] = fRec1428[0];
			fRec1426[1] = fRec1426[0];
			fRec1425[1] = fRec1425[0];
			fRec1423[1] = fRec1423[0];
			fRec1422[1] = fRec1422[0];
			fRec1420[1] = fRec1420[0];
			fRec1431[1] = fRec1431[0];
			fRec1429[1] = fRec1429[0];
			fRec1437[1] = fRec1437[0];
			fRec1435[1] = fRec1435[0];
			fRec1434[1] = fRec1434[0];
			fRec1432[1] = fRec1432[0];
			fRec1455[1] = fRec1455[0];
			fRec1453[1] = fRec1453[0];
			fRec1452[1] = fRec1452[0];
			fRec1450[1] = fRec1450[0];
			fRec1449[1] = fRec1449[0];
			fRec1447[1] = fRec1447[0];
			fRec1446[1] = fRec1446[0];
			fRec1444[1] = fRec1444[0];
			fRec1443[1] = fRec1443[0];
			fRec1441[1] = fRec1441[0];
			fRec1440[1] = fRec1440[0];
			fRec1438[1] = fRec1438[0];
			fRec1470[1] = fRec1470[0];
			fRec1468[1] = fRec1468[0];
			fRec1467[1] = fRec1467[0];
			fRec1465[1] = fRec1465[0];
			fRec1464[1] = fRec1464[0];
			fRec1462[1] = fRec1462[0];
			fRec1461[1] = fRec1461[0];
			fRec1459[1] = fRec1459[0];
			fRec1458[1] = fRec1458[0];
			fRec1456[1] = fRec1456[0];
			fRec1482[1] = fRec1482[0];
			fRec1480[1] = fRec1480[0];
			fRec1479[1] = fRec1479[0];
			fRec1477[1] = fRec1477[0];
			fRec1476[1] = fRec1476[0];
			fRec1474[1] = fRec1474[0];
			fRec1473[1] = fRec1473[0];
			fRec1471[1] = fRec1471[0];
			fRec1491[1] = fRec1491[0];
			fRec1489[1] = fRec1489[0];
			fRec1488[1] = fRec1488[0];
			fRec1486[1] = fRec1486[0];
			fRec1485[1] = fRec1485[0];
			fRec1483[1] = fRec1483[0];
			fRec1494[1] = fRec1494[0];
			fRec1492[1] = fRec1492[0];
			fRec1500[1] = fRec1500[0];
			fRec1498[1] = fRec1498[0];
			fRec1497[1] = fRec1497[0];
			fRec1495[1] = fRec1495[0];
			fRec1518[1] = fRec1518[0];
			fRec1516[1] = fRec1516[0];
			fRec1515[1] = fRec1515[0];
			fRec1513[1] = fRec1513[0];
			fRec1512[1] = fRec1512[0];
			fRec1510[1] = fRec1510[0];
			fRec1509[1] = fRec1509[0];
			fRec1507[1] = fRec1507[0];
			fRec1506[1] = fRec1506[0];
			fRec1504[1] = fRec1504[0];
			fRec1503[1] = fRec1503[0];
			fRec1501[1] = fRec1501[0];
			fRec1533[1] = fRec1533[0];
			fRec1531[1] = fRec1531[0];
			fRec1530[1] = fRec1530[0];
			fRec1528[1] = fRec1528[0];
			fRec1527[1] = fRec1527[0];
			fRec1525[1] = fRec1525[0];
			fRec1524[1] = fRec1524[0];
			fRec1522[1] = fRec1522[0];
			fRec1521[1] = fRec1521[0];
			fRec1519[1] = fRec1519[0];
			fRec1545[1] = fRec1545[0];
			fRec1543[1] = fRec1543[0];
			fRec1542[1] = fRec1542[0];
			fRec1540[1] = fRec1540[0];
			fRec1539[1] = fRec1539[0];
			fRec1537[1] = fRec1537[0];
			fRec1536[1] = fRec1536[0];
			fRec1534[1] = fRec1534[0];
			fRec1554[1] = fRec1554[0];
			fRec1552[1] = fRec1552[0];
			fRec1551[1] = fRec1551[0];
			fRec1549[1] = fRec1549[0];
			fRec1548[1] = fRec1548[0];
			fRec1546[1] = fRec1546[0];
			fRec1557[1] = fRec1557[0];
			fRec1555[1] = fRec1555[0];
			fRec1563[1] = fRec1563[0];
			fRec1561[1] = fRec1561[0];
			fRec1560[1] = fRec1560[0];
			fRec1558[1] = fRec1558[0];
			fRec1581[1] = fRec1581[0];
			fRec1579[1] = fRec1579[0];
			fRec1578[1] = fRec1578[0];
			fRec1576[1] = fRec1576[0];
			fRec1575[1] = fRec1575[0];
			fRec1573[1] = fRec1573[0];
			fRec1572[1] = fRec1572[0];
			fRec1570[1] = fRec1570[0];
			fRec1569[1] = fRec1569[0];
			fRec1567[1] = fRec1567[0];
			fRec1566[1] = fRec1566[0];
			fRec1564[1] = fRec1564[0];
			fRec1596[1] = fRec1596[0];
			fRec1594[1] = fRec1594[0];
			fRec1593[1] = fRec1593[0];
			fRec1591[1] = fRec1591[0];
			fRec1590[1] = fRec1590[0];
			fRec1588[1] = fRec1588[0];
			fRec1587[1] = fRec1587[0];
			fRec1585[1] = fRec1585[0];
			fRec1584[1] = fRec1584[0];
			fRec1582[1] = fRec1582[0];
			fRec1608[1] = fRec1608[0];
			fRec1606[1] = fRec1606[0];
			fRec1605[1] = fRec1605[0];
			fRec1603[1] = fRec1603[0];
			fRec1602[1] = fRec1602[0];
			fRec1600[1] = fRec1600[0];
			fRec1599[1] = fRec1599[0];
			fRec1597[1] = fRec1597[0];
			fRec1617[1] = fRec1617[0];
			fRec1615[1] = fRec1615[0];
			fRec1614[1] = fRec1614[0];
			fRec1612[1] = fRec1612[0];
			fRec1611[1] = fRec1611[0];
			fRec1609[1] = fRec1609[0];
			fRec1620[1] = fRec1620[0];
			fRec1618[1] = fRec1618[0];
			fRec1626[1] = fRec1626[0];
			fRec1624[1] = fRec1624[0];
			fRec1623[1] = fRec1623[0];
			fRec1621[1] = fRec1621[0];
			for (int j0 = 11; (j0 > 0); j0 = (j0 - 1)) {
				fVec24[j0] = fVec24[(j0 - 1)];
				
			}
			fRec1638[1] = fRec1638[0];
			fRec1636[1] = fRec1636[0];
			fRec1635[1] = fRec1635[0];
			fRec1633[1] = fRec1633[0];
			fRec1632[1] = fRec1632[0];
			fRec1630[1] = fRec1630[0];
			fRec1629[1] = fRec1629[0];
			fRec1627[1] = fRec1627[0];
			fRec1647[1] = fRec1647[0];
			fRec1645[1] = fRec1645[0];
			fRec1644[1] = fRec1644[0];
			fRec1642[1] = fRec1642[0];
			fRec1641[1] = fRec1641[0];
			fRec1639[1] = fRec1639[0];
			fRec1653[1] = fRec1653[0];
			fRec1651[1] = fRec1651[0];
			fRec1650[1] = fRec1650[0];
			fRec1648[1] = fRec1648[0];
			fRec1656[1] = fRec1656[0];
			fRec1654[1] = fRec1654[0];
			fRec1671[1] = fRec1671[0];
			fRec1669[1] = fRec1669[0];
			fRec1668[1] = fRec1668[0];
			fRec1666[1] = fRec1666[0];
			fRec1665[1] = fRec1665[0];
			fRec1663[1] = fRec1663[0];
			fRec1662[1] = fRec1662[0];
			fRec1660[1] = fRec1660[0];
			fRec1659[1] = fRec1659[0];
			fRec1657[1] = fRec1657[0];
			fRec1689[1] = fRec1689[0];
			fRec1687[1] = fRec1687[0];
			fRec1686[1] = fRec1686[0];
			fRec1684[1] = fRec1684[0];
			fRec1683[1] = fRec1683[0];
			fRec1681[1] = fRec1681[0];
			fRec1680[1] = fRec1680[0];
			fRec1678[1] = fRec1678[0];
			fRec1677[1] = fRec1677[0];
			fRec1675[1] = fRec1675[0];
			fRec1674[1] = fRec1674[0];
			fRec1672[1] = fRec1672[0];
			for (int j1 = 11; (j1 > 0); j1 = (j1 - 1)) {
				fVec25[j1] = fVec25[(j1 - 1)];
				
			}
			fRec1707[1] = fRec1707[0];
			fRec1705[1] = fRec1705[0];
			fRec1704[1] = fRec1704[0];
			fRec1702[1] = fRec1702[0];
			fRec1701[1] = fRec1701[0];
			fRec1699[1] = fRec1699[0];
			fRec1698[1] = fRec1698[0];
			fRec1696[1] = fRec1696[0];
			fRec1695[1] = fRec1695[0];
			fRec1693[1] = fRec1693[0];
			fRec1692[1] = fRec1692[0];
			fRec1690[1] = fRec1690[0];
			fRec1722[1] = fRec1722[0];
			fRec1720[1] = fRec1720[0];
			fRec1719[1] = fRec1719[0];
			fRec1717[1] = fRec1717[0];
			fRec1716[1] = fRec1716[0];
			fRec1714[1] = fRec1714[0];
			fRec1713[1] = fRec1713[0];
			fRec1711[1] = fRec1711[0];
			fRec1710[1] = fRec1710[0];
			fRec1708[1] = fRec1708[0];
			fRec1734[1] = fRec1734[0];
			fRec1732[1] = fRec1732[0];
			fRec1731[1] = fRec1731[0];
			fRec1729[1] = fRec1729[0];
			fRec1728[1] = fRec1728[0];
			fRec1726[1] = fRec1726[0];
			fRec1725[1] = fRec1725[0];
			fRec1723[1] = fRec1723[0];
			fRec1743[1] = fRec1743[0];
			fRec1741[1] = fRec1741[0];
			fRec1740[1] = fRec1740[0];
			fRec1738[1] = fRec1738[0];
			fRec1737[1] = fRec1737[0];
			fRec1735[1] = fRec1735[0];
			fRec1746[1] = fRec1746[0];
			fRec1744[1] = fRec1744[0];
			fRec1752[1] = fRec1752[0];
			fRec1750[1] = fRec1750[0];
			fRec1749[1] = fRec1749[0];
			fRec1747[1] = fRec1747[0];
			for (int j2 = 11; (j2 > 0); j2 = (j2 - 1)) {
				fVec26[j2] = fVec26[(j2 - 1)];
				
			}
			fRec1770[1] = fRec1770[0];
			fRec1768[1] = fRec1768[0];
			fRec1767[1] = fRec1767[0];
			fRec1765[1] = fRec1765[0];
			fRec1764[1] = fRec1764[0];
			fRec1762[1] = fRec1762[0];
			fRec1761[1] = fRec1761[0];
			fRec1759[1] = fRec1759[0];
			fRec1758[1] = fRec1758[0];
			fRec1756[1] = fRec1756[0];
			fRec1755[1] = fRec1755[0];
			fRec1753[1] = fRec1753[0];
			fRec1785[1] = fRec1785[0];
			fRec1783[1] = fRec1783[0];
			fRec1782[1] = fRec1782[0];
			fRec1780[1] = fRec1780[0];
			fRec1779[1] = fRec1779[0];
			fRec1777[1] = fRec1777[0];
			fRec1776[1] = fRec1776[0];
			fRec1774[1] = fRec1774[0];
			fRec1773[1] = fRec1773[0];
			fRec1771[1] = fRec1771[0];
			fRec1797[1] = fRec1797[0];
			fRec1795[1] = fRec1795[0];
			fRec1794[1] = fRec1794[0];
			fRec1792[1] = fRec1792[0];
			fRec1791[1] = fRec1791[0];
			fRec1789[1] = fRec1789[0];
			fRec1788[1] = fRec1788[0];
			fRec1786[1] = fRec1786[0];
			fRec1806[1] = fRec1806[0];
			fRec1804[1] = fRec1804[0];
			fRec1803[1] = fRec1803[0];
			fRec1801[1] = fRec1801[0];
			fRec1800[1] = fRec1800[0];
			fRec1798[1] = fRec1798[0];
			fRec1809[1] = fRec1809[0];
			fRec1807[1] = fRec1807[0];
			fRec1815[1] = fRec1815[0];
			fRec1813[1] = fRec1813[0];
			fRec1812[1] = fRec1812[0];
			fRec1810[1] = fRec1810[0];
			for (int j3 = 11; (j3 > 0); j3 = (j3 - 1)) {
				fVec27[j3] = fVec27[(j3 - 1)];
				
			}
			fRec1833[1] = fRec1833[0];
			fRec1831[1] = fRec1831[0];
			fRec1830[1] = fRec1830[0];
			fRec1828[1] = fRec1828[0];
			fRec1827[1] = fRec1827[0];
			fRec1825[1] = fRec1825[0];
			fRec1824[1] = fRec1824[0];
			fRec1822[1] = fRec1822[0];
			fRec1821[1] = fRec1821[0];
			fRec1819[1] = fRec1819[0];
			fRec1818[1] = fRec1818[0];
			fRec1816[1] = fRec1816[0];
			fRec1848[1] = fRec1848[0];
			fRec1846[1] = fRec1846[0];
			fRec1845[1] = fRec1845[0];
			fRec1843[1] = fRec1843[0];
			fRec1842[1] = fRec1842[0];
			fRec1840[1] = fRec1840[0];
			fRec1839[1] = fRec1839[0];
			fRec1837[1] = fRec1837[0];
			fRec1836[1] = fRec1836[0];
			fRec1834[1] = fRec1834[0];
			fRec1860[1] = fRec1860[0];
			fRec1858[1] = fRec1858[0];
			fRec1857[1] = fRec1857[0];
			fRec1855[1] = fRec1855[0];
			fRec1854[1] = fRec1854[0];
			fRec1852[1] = fRec1852[0];
			fRec1851[1] = fRec1851[0];
			fRec1849[1] = fRec1849[0];
			fRec1869[1] = fRec1869[0];
			fRec1867[1] = fRec1867[0];
			fRec1866[1] = fRec1866[0];
			fRec1864[1] = fRec1864[0];
			fRec1863[1] = fRec1863[0];
			fRec1861[1] = fRec1861[0];
			fRec1872[1] = fRec1872[0];
			fRec1870[1] = fRec1870[0];
			fRec1878[1] = fRec1878[0];
			fRec1876[1] = fRec1876[0];
			fRec1875[1] = fRec1875[0];
			fRec1873[1] = fRec1873[0];
			fRec1881[1] = fRec1881[0];
			fRec1879[1] = fRec1879[0];
			fRec1887[1] = fRec1887[0];
			fRec1885[1] = fRec1885[0];
			fRec1884[1] = fRec1884[0];
			fRec1882[1] = fRec1882[0];
			fRec1896[1] = fRec1896[0];
			fRec1894[1] = fRec1894[0];
			fRec1893[1] = fRec1893[0];
			fRec1891[1] = fRec1891[0];
			fRec1890[1] = fRec1890[0];
			fRec1888[1] = fRec1888[0];
			fRec1908[1] = fRec1908[0];
			fRec1906[1] = fRec1906[0];
			fRec1905[1] = fRec1905[0];
			fRec1903[1] = fRec1903[0];
			fRec1902[1] = fRec1902[0];
			fRec1900[1] = fRec1900[0];
			fRec1899[1] = fRec1899[0];
			fRec1897[1] = fRec1897[0];
			fRec1923[1] = fRec1923[0];
			fRec1921[1] = fRec1921[0];
			fRec1920[1] = fRec1920[0];
			fRec1918[1] = fRec1918[0];
			fRec1917[1] = fRec1917[0];
			fRec1915[1] = fRec1915[0];
			fRec1914[1] = fRec1914[0];
			fRec1912[1] = fRec1912[0];
			fRec1911[1] = fRec1911[0];
			fRec1909[1] = fRec1909[0];
			fRec1941[1] = fRec1941[0];
			fRec1939[1] = fRec1939[0];
			fRec1938[1] = fRec1938[0];
			fRec1936[1] = fRec1936[0];
			fRec1935[1] = fRec1935[0];
			fRec1933[1] = fRec1933[0];
			fRec1932[1] = fRec1932[0];
			fRec1930[1] = fRec1930[0];
			fRec1929[1] = fRec1929[0];
			fRec1927[1] = fRec1927[0];
			fRec1926[1] = fRec1926[0];
			fRec1924[1] = fRec1924[0];
			fRec1944[1] = fRec1944[0];
			fRec1942[1] = fRec1942[0];
			fRec1950[1] = fRec1950[0];
			fRec1948[1] = fRec1948[0];
			fRec1947[1] = fRec1947[0];
			fRec1945[1] = fRec1945[0];
			fRec1959[1] = fRec1959[0];
			fRec1957[1] = fRec1957[0];
			fRec1956[1] = fRec1956[0];
			fRec1954[1] = fRec1954[0];
			fRec1953[1] = fRec1953[0];
			fRec1951[1] = fRec1951[0];
			fRec1971[1] = fRec1971[0];
			fRec1969[1] = fRec1969[0];
			fRec1968[1] = fRec1968[0];
			fRec1966[1] = fRec1966[0];
			fRec1965[1] = fRec1965[0];
			fRec1963[1] = fRec1963[0];
			fRec1962[1] = fRec1962[0];
			fRec1960[1] = fRec1960[0];
			fRec1986[1] = fRec1986[0];
			fRec1984[1] = fRec1984[0];
			fRec1983[1] = fRec1983[0];
			fRec1981[1] = fRec1981[0];
			fRec1980[1] = fRec1980[0];
			fRec1978[1] = fRec1978[0];
			fRec1977[1] = fRec1977[0];
			fRec1975[1] = fRec1975[0];
			fRec1974[1] = fRec1974[0];
			fRec1972[1] = fRec1972[0];
			fRec2004[1] = fRec2004[0];
			fRec2002[1] = fRec2002[0];
			fRec2001[1] = fRec2001[0];
			fRec1999[1] = fRec1999[0];
			fRec1998[1] = fRec1998[0];
			fRec1996[1] = fRec1996[0];
			fRec1995[1] = fRec1995[0];
			fRec1993[1] = fRec1993[0];
			fRec1992[1] = fRec1992[0];
			fRec1990[1] = fRec1990[0];
			fRec1989[1] = fRec1989[0];
			fRec1987[1] = fRec1987[0];
			fRec2007[1] = fRec2007[0];
			fRec2005[1] = fRec2005[0];
			fRec2013[1] = fRec2013[0];
			fRec2011[1] = fRec2011[0];
			fRec2010[1] = fRec2010[0];
			fRec2008[1] = fRec2008[0];
			fRec2022[1] = fRec2022[0];
			fRec2020[1] = fRec2020[0];
			fRec2019[1] = fRec2019[0];
			fRec2017[1] = fRec2017[0];
			fRec2016[1] = fRec2016[0];
			fRec2014[1] = fRec2014[0];
			fRec2034[1] = fRec2034[0];
			fRec2032[1] = fRec2032[0];
			fRec2031[1] = fRec2031[0];
			fRec2029[1] = fRec2029[0];
			fRec2028[1] = fRec2028[0];
			fRec2026[1] = fRec2026[0];
			fRec2025[1] = fRec2025[0];
			fRec2023[1] = fRec2023[0];
			fRec2049[1] = fRec2049[0];
			fRec2047[1] = fRec2047[0];
			fRec2046[1] = fRec2046[0];
			fRec2044[1] = fRec2044[0];
			fRec2043[1] = fRec2043[0];
			fRec2041[1] = fRec2041[0];
			fRec2040[1] = fRec2040[0];
			fRec2038[1] = fRec2038[0];
			fRec2037[1] = fRec2037[0];
			fRec2035[1] = fRec2035[0];
			fRec2067[1] = fRec2067[0];
			fRec2065[1] = fRec2065[0];
			fRec2064[1] = fRec2064[0];
			fRec2062[1] = fRec2062[0];
			fRec2061[1] = fRec2061[0];
			fRec2059[1] = fRec2059[0];
			fRec2058[1] = fRec2058[0];
			fRec2056[1] = fRec2056[0];
			fRec2055[1] = fRec2055[0];
			fRec2053[1] = fRec2053[0];
			fRec2052[1] = fRec2052[0];
			fRec2050[1] = fRec2050[0];
			fRec2070[1] = fRec2070[0];
			fRec2068[1] = fRec2068[0];
			fRec2076[1] = fRec2076[0];
			fRec2074[1] = fRec2074[0];
			fRec2073[1] = fRec2073[0];
			fRec2071[1] = fRec2071[0];
			fRec2085[1] = fRec2085[0];
			fRec2083[1] = fRec2083[0];
			fRec2082[1] = fRec2082[0];
			fRec2080[1] = fRec2080[0];
			fRec2079[1] = fRec2079[0];
			fRec2077[1] = fRec2077[0];
			fRec2097[1] = fRec2097[0];
			fRec2095[1] = fRec2095[0];
			fRec2094[1] = fRec2094[0];
			fRec2092[1] = fRec2092[0];
			fRec2091[1] = fRec2091[0];
			fRec2089[1] = fRec2089[0];
			fRec2088[1] = fRec2088[0];
			fRec2086[1] = fRec2086[0];
			fRec2112[1] = fRec2112[0];
			fRec2110[1] = fRec2110[0];
			fRec2109[1] = fRec2109[0];
			fRec2107[1] = fRec2107[0];
			fRec2106[1] = fRec2106[0];
			fRec2104[1] = fRec2104[0];
			fRec2103[1] = fRec2103[0];
			fRec2101[1] = fRec2101[0];
			fRec2100[1] = fRec2100[0];
			fRec2098[1] = fRec2098[0];
			fRec2130[1] = fRec2130[0];
			fRec2128[1] = fRec2128[0];
			fRec2127[1] = fRec2127[0];
			fRec2125[1] = fRec2125[0];
			fRec2124[1] = fRec2124[0];
			fRec2122[1] = fRec2122[0];
			fRec2121[1] = fRec2121[0];
			fRec2119[1] = fRec2119[0];
			fRec2118[1] = fRec2118[0];
			fRec2116[1] = fRec2116[0];
			fRec2115[1] = fRec2115[0];
			fRec2113[1] = fRec2113[0];
			fRec2133[1] = fRec2133[0];
			fRec2131[1] = fRec2131[0];
			fRec2139[1] = fRec2139[0];
			fRec2137[1] = fRec2137[0];
			fRec2136[1] = fRec2136[0];
			fRec2134[1] = fRec2134[0];
			fRec2148[1] = fRec2148[0];
			fRec2146[1] = fRec2146[0];
			fRec2145[1] = fRec2145[0];
			fRec2143[1] = fRec2143[0];
			fRec2142[1] = fRec2142[0];
			fRec2140[1] = fRec2140[0];
			fRec2160[1] = fRec2160[0];
			fRec2158[1] = fRec2158[0];
			fRec2157[1] = fRec2157[0];
			fRec2155[1] = fRec2155[0];
			fRec2154[1] = fRec2154[0];
			fRec2152[1] = fRec2152[0];
			fRec2151[1] = fRec2151[0];
			fRec2149[1] = fRec2149[0];
			fRec2175[1] = fRec2175[0];
			fRec2173[1] = fRec2173[0];
			fRec2172[1] = fRec2172[0];
			fRec2170[1] = fRec2170[0];
			fRec2169[1] = fRec2169[0];
			fRec2167[1] = fRec2167[0];
			fRec2166[1] = fRec2166[0];
			fRec2164[1] = fRec2164[0];
			fRec2163[1] = fRec2163[0];
			fRec2161[1] = fRec2161[0];
			fRec2193[1] = fRec2193[0];
			fRec2191[1] = fRec2191[0];
			fRec2190[1] = fRec2190[0];
			fRec2188[1] = fRec2188[0];
			fRec2187[1] = fRec2187[0];
			fRec2185[1] = fRec2185[0];
			fRec2184[1] = fRec2184[0];
			fRec2182[1] = fRec2182[0];
			fRec2181[1] = fRec2181[0];
			fRec2179[1] = fRec2179[0];
			fRec2178[1] = fRec2178[0];
			fRec2176[1] = fRec2176[0];
			fRec2196[1] = fRec2196[0];
			fRec2194[1] = fRec2194[0];
			fRec2202[1] = fRec2202[0];
			fRec2200[1] = fRec2200[0];
			fRec2199[1] = fRec2199[0];
			fRec2197[1] = fRec2197[0];
			fRec2211[1] = fRec2211[0];
			fRec2209[1] = fRec2209[0];
			fRec2208[1] = fRec2208[0];
			fRec2206[1] = fRec2206[0];
			fRec2205[1] = fRec2205[0];
			fRec2203[1] = fRec2203[0];
			fRec2223[1] = fRec2223[0];
			fRec2221[1] = fRec2221[0];
			fRec2220[1] = fRec2220[0];
			fRec2218[1] = fRec2218[0];
			fRec2217[1] = fRec2217[0];
			fRec2215[1] = fRec2215[0];
			fRec2214[1] = fRec2214[0];
			fRec2212[1] = fRec2212[0];
			fRec2238[1] = fRec2238[0];
			fRec2236[1] = fRec2236[0];
			fRec2235[1] = fRec2235[0];
			fRec2233[1] = fRec2233[0];
			fRec2232[1] = fRec2232[0];
			fRec2230[1] = fRec2230[0];
			fRec2229[1] = fRec2229[0];
			fRec2227[1] = fRec2227[0];
			fRec2226[1] = fRec2226[0];
			fRec2224[1] = fRec2224[0];
			fRec2256[1] = fRec2256[0];
			fRec2254[1] = fRec2254[0];
			fRec2253[1] = fRec2253[0];
			fRec2251[1] = fRec2251[0];
			fRec2250[1] = fRec2250[0];
			fRec2248[1] = fRec2248[0];
			fRec2247[1] = fRec2247[0];
			fRec2245[1] = fRec2245[0];
			fRec2244[1] = fRec2244[0];
			fRec2242[1] = fRec2242[0];
			fRec2241[1] = fRec2241[0];
			fRec2239[1] = fRec2239[0];
			fRec2259[1] = fRec2259[0];
			fRec2257[1] = fRec2257[0];
			fRec2265[1] = fRec2265[0];
			fRec2263[1] = fRec2263[0];
			fRec2262[1] = fRec2262[0];
			fRec2260[1] = fRec2260[0];
			fRec2274[1] = fRec2274[0];
			fRec2272[1] = fRec2272[0];
			fRec2271[1] = fRec2271[0];
			fRec2269[1] = fRec2269[0];
			fRec2268[1] = fRec2268[0];
			fRec2266[1] = fRec2266[0];
			fRec2286[1] = fRec2286[0];
			fRec2284[1] = fRec2284[0];
			fRec2283[1] = fRec2283[0];
			fRec2281[1] = fRec2281[0];
			fRec2280[1] = fRec2280[0];
			fRec2278[1] = fRec2278[0];
			fRec2277[1] = fRec2277[0];
			fRec2275[1] = fRec2275[0];
			fRec2301[1] = fRec2301[0];
			fRec2299[1] = fRec2299[0];
			fRec2298[1] = fRec2298[0];
			fRec2296[1] = fRec2296[0];
			fRec2295[1] = fRec2295[0];
			fRec2293[1] = fRec2293[0];
			fRec2292[1] = fRec2292[0];
			fRec2290[1] = fRec2290[0];
			fRec2289[1] = fRec2289[0];
			fRec2287[1] = fRec2287[0];
			fRec2319[1] = fRec2319[0];
			fRec2317[1] = fRec2317[0];
			fRec2316[1] = fRec2316[0];
			fRec2314[1] = fRec2314[0];
			fRec2313[1] = fRec2313[0];
			fRec2311[1] = fRec2311[0];
			fRec2310[1] = fRec2310[0];
			fRec2308[1] = fRec2308[0];
			fRec2307[1] = fRec2307[0];
			fRec2305[1] = fRec2305[0];
			fRec2304[1] = fRec2304[0];
			fRec2302[1] = fRec2302[0];
			fRec2337[1] = fRec2337[0];
			fRec2335[1] = fRec2335[0];
			fRec2334[1] = fRec2334[0];
			fRec2332[1] = fRec2332[0];
			fRec2331[1] = fRec2331[0];
			fRec2329[1] = fRec2329[0];
			fRec2328[1] = fRec2328[0];
			fRec2326[1] = fRec2326[0];
			fRec2325[1] = fRec2325[0];
			fRec2323[1] = fRec2323[0];
			fRec2322[1] = fRec2322[0];
			fRec2320[1] = fRec2320[0];
			fRec2352[1] = fRec2352[0];
			fRec2350[1] = fRec2350[0];
			fRec2349[1] = fRec2349[0];
			fRec2347[1] = fRec2347[0];
			fRec2346[1] = fRec2346[0];
			fRec2344[1] = fRec2344[0];
			fRec2343[1] = fRec2343[0];
			fRec2341[1] = fRec2341[0];
			fRec2340[1] = fRec2340[0];
			fRec2338[1] = fRec2338[0];
			fRec2364[1] = fRec2364[0];
			fRec2362[1] = fRec2362[0];
			fRec2361[1] = fRec2361[0];
			fRec2359[1] = fRec2359[0];
			fRec2358[1] = fRec2358[0];
			fRec2356[1] = fRec2356[0];
			fRec2355[1] = fRec2355[0];
			fRec2353[1] = fRec2353[0];
			fRec2373[1] = fRec2373[0];
			fRec2371[1] = fRec2371[0];
			fRec2370[1] = fRec2370[0];
			fRec2368[1] = fRec2368[0];
			fRec2367[1] = fRec2367[0];
			fRec2365[1] = fRec2365[0];
			fRec2376[1] = fRec2376[0];
			fRec2374[1] = fRec2374[0];
			fRec2382[1] = fRec2382[0];
			fRec2380[1] = fRec2380[0];
			fRec2379[1] = fRec2379[0];
			fRec2377[1] = fRec2377[0];
			fRec2400[1] = fRec2400[0];
			fRec2398[1] = fRec2398[0];
			fRec2397[1] = fRec2397[0];
			fRec2395[1] = fRec2395[0];
			fRec2394[1] = fRec2394[0];
			fRec2392[1] = fRec2392[0];
			fRec2391[1] = fRec2391[0];
			fRec2389[1] = fRec2389[0];
			fRec2388[1] = fRec2388[0];
			fRec2386[1] = fRec2386[0];
			fRec2385[1] = fRec2385[0];
			fRec2383[1] = fRec2383[0];
			fRec2415[1] = fRec2415[0];
			fRec2413[1] = fRec2413[0];
			fRec2412[1] = fRec2412[0];
			fRec2410[1] = fRec2410[0];
			fRec2409[1] = fRec2409[0];
			fRec2407[1] = fRec2407[0];
			fRec2406[1] = fRec2406[0];
			fRec2404[1] = fRec2404[0];
			fRec2403[1] = fRec2403[0];
			fRec2401[1] = fRec2401[0];
			fRec2427[1] = fRec2427[0];
			fRec2425[1] = fRec2425[0];
			fRec2424[1] = fRec2424[0];
			fRec2422[1] = fRec2422[0];
			fRec2421[1] = fRec2421[0];
			fRec2419[1] = fRec2419[0];
			fRec2418[1] = fRec2418[0];
			fRec2416[1] = fRec2416[0];
			fRec2436[1] = fRec2436[0];
			fRec2434[1] = fRec2434[0];
			fRec2433[1] = fRec2433[0];
			fRec2431[1] = fRec2431[0];
			fRec2430[1] = fRec2430[0];
			fRec2428[1] = fRec2428[0];
			fRec2439[1] = fRec2439[0];
			fRec2437[1] = fRec2437[0];
			fRec2445[1] = fRec2445[0];
			fRec2443[1] = fRec2443[0];
			fRec2442[1] = fRec2442[0];
			fRec2440[1] = fRec2440[0];
			fRec2463[1] = fRec2463[0];
			fRec2461[1] = fRec2461[0];
			fRec2460[1] = fRec2460[0];
			fRec2458[1] = fRec2458[0];
			fRec2457[1] = fRec2457[0];
			fRec2455[1] = fRec2455[0];
			fRec2454[1] = fRec2454[0];
			fRec2452[1] = fRec2452[0];
			fRec2451[1] = fRec2451[0];
			fRec2449[1] = fRec2449[0];
			fRec2448[1] = fRec2448[0];
			fRec2446[1] = fRec2446[0];
			fRec2478[1] = fRec2478[0];
			fRec2476[1] = fRec2476[0];
			fRec2475[1] = fRec2475[0];
			fRec2473[1] = fRec2473[0];
			fRec2472[1] = fRec2472[0];
			fRec2470[1] = fRec2470[0];
			fRec2469[1] = fRec2469[0];
			fRec2467[1] = fRec2467[0];
			fRec2466[1] = fRec2466[0];
			fRec2464[1] = fRec2464[0];
			fRec2490[1] = fRec2490[0];
			fRec2488[1] = fRec2488[0];
			fRec2487[1] = fRec2487[0];
			fRec2485[1] = fRec2485[0];
			fRec2484[1] = fRec2484[0];
			fRec2482[1] = fRec2482[0];
			fRec2481[1] = fRec2481[0];
			fRec2479[1] = fRec2479[0];
			fRec2499[1] = fRec2499[0];
			fRec2497[1] = fRec2497[0];
			fRec2496[1] = fRec2496[0];
			fRec2494[1] = fRec2494[0];
			fRec2493[1] = fRec2493[0];
			fRec2491[1] = fRec2491[0];
			fRec2502[1] = fRec2502[0];
			fRec2500[1] = fRec2500[0];
			fRec2508[1] = fRec2508[0];
			fRec2506[1] = fRec2506[0];
			fRec2505[1] = fRec2505[0];
			fRec2503[1] = fRec2503[0];
			fRec2526[1] = fRec2526[0];
			fRec2524[1] = fRec2524[0];
			fRec2523[1] = fRec2523[0];
			fRec2521[1] = fRec2521[0];
			fRec2520[1] = fRec2520[0];
			fRec2518[1] = fRec2518[0];
			fRec2517[1] = fRec2517[0];
			fRec2515[1] = fRec2515[0];
			fRec2514[1] = fRec2514[0];
			fRec2512[1] = fRec2512[0];
			fRec2511[1] = fRec2511[0];
			fRec2509[1] = fRec2509[0];
			fRec2541[1] = fRec2541[0];
			fRec2539[1] = fRec2539[0];
			fRec2538[1] = fRec2538[0];
			fRec2536[1] = fRec2536[0];
			fRec2535[1] = fRec2535[0];
			fRec2533[1] = fRec2533[0];
			fRec2532[1] = fRec2532[0];
			fRec2530[1] = fRec2530[0];
			fRec2529[1] = fRec2529[0];
			fRec2527[1] = fRec2527[0];
			fRec2553[1] = fRec2553[0];
			fRec2551[1] = fRec2551[0];
			fRec2550[1] = fRec2550[0];
			fRec2548[1] = fRec2548[0];
			fRec2547[1] = fRec2547[0];
			fRec2545[1] = fRec2545[0];
			fRec2544[1] = fRec2544[0];
			fRec2542[1] = fRec2542[0];
			fRec2562[1] = fRec2562[0];
			fRec2560[1] = fRec2560[0];
			fRec2559[1] = fRec2559[0];
			fRec2557[1] = fRec2557[0];
			fRec2556[1] = fRec2556[0];
			fRec2554[1] = fRec2554[0];
			fRec2565[1] = fRec2565[0];
			fRec2563[1] = fRec2563[0];
			fRec2571[1] = fRec2571[0];
			fRec2569[1] = fRec2569[0];
			fRec2568[1] = fRec2568[0];
			fRec2566[1] = fRec2566[0];
			fRec2589[1] = fRec2589[0];
			fRec2587[1] = fRec2587[0];
			fRec2586[1] = fRec2586[0];
			fRec2584[1] = fRec2584[0];
			fRec2583[1] = fRec2583[0];
			fRec2581[1] = fRec2581[0];
			fRec2580[1] = fRec2580[0];
			fRec2578[1] = fRec2578[0];
			fRec2577[1] = fRec2577[0];
			fRec2575[1] = fRec2575[0];
			fRec2574[1] = fRec2574[0];
			fRec2572[1] = fRec2572[0];
			fRec2604[1] = fRec2604[0];
			fRec2602[1] = fRec2602[0];
			fRec2601[1] = fRec2601[0];
			fRec2599[1] = fRec2599[0];
			fRec2598[1] = fRec2598[0];
			fRec2596[1] = fRec2596[0];
			fRec2595[1] = fRec2595[0];
			fRec2593[1] = fRec2593[0];
			fRec2592[1] = fRec2592[0];
			fRec2590[1] = fRec2590[0];
			fRec2616[1] = fRec2616[0];
			fRec2614[1] = fRec2614[0];
			fRec2613[1] = fRec2613[0];
			fRec2611[1] = fRec2611[0];
			fRec2610[1] = fRec2610[0];
			fRec2608[1] = fRec2608[0];
			fRec2607[1] = fRec2607[0];
			fRec2605[1] = fRec2605[0];
			fRec2625[1] = fRec2625[0];
			fRec2623[1] = fRec2623[0];
			fRec2622[1] = fRec2622[0];
			fRec2620[1] = fRec2620[0];
			fRec2619[1] = fRec2619[0];
			fRec2617[1] = fRec2617[0];
			fRec2628[1] = fRec2628[0];
			fRec2626[1] = fRec2626[0];
			fRec2634[1] = fRec2634[0];
			fRec2632[1] = fRec2632[0];
			fRec2631[1] = fRec2631[0];
			fRec2629[1] = fRec2629[0];
			fRec2652[1] = fRec2652[0];
			fRec2650[1] = fRec2650[0];
			fRec2649[1] = fRec2649[0];
			fRec2647[1] = fRec2647[0];
			fRec2646[1] = fRec2646[0];
			fRec2644[1] = fRec2644[0];
			fRec2643[1] = fRec2643[0];
			fRec2641[1] = fRec2641[0];
			fRec2640[1] = fRec2640[0];
			fRec2638[1] = fRec2638[0];
			fRec2637[1] = fRec2637[0];
			fRec2635[1] = fRec2635[0];
			fRec2667[1] = fRec2667[0];
			fRec2665[1] = fRec2665[0];
			fRec2664[1] = fRec2664[0];
			fRec2662[1] = fRec2662[0];
			fRec2661[1] = fRec2661[0];
			fRec2659[1] = fRec2659[0];
			fRec2658[1] = fRec2658[0];
			fRec2656[1] = fRec2656[0];
			fRec2655[1] = fRec2655[0];
			fRec2653[1] = fRec2653[0];
			fRec2679[1] = fRec2679[0];
			fRec2677[1] = fRec2677[0];
			fRec2676[1] = fRec2676[0];
			fRec2674[1] = fRec2674[0];
			fRec2673[1] = fRec2673[0];
			fRec2671[1] = fRec2671[0];
			fRec2670[1] = fRec2670[0];
			fRec2668[1] = fRec2668[0];
			fRec2688[1] = fRec2688[0];
			fRec2686[1] = fRec2686[0];
			fRec2685[1] = fRec2685[0];
			fRec2683[1] = fRec2683[0];
			fRec2682[1] = fRec2682[0];
			fRec2680[1] = fRec2680[0];
			fRec2691[1] = fRec2691[0];
			fRec2689[1] = fRec2689[0];
			fRec2697[1] = fRec2697[0];
			fRec2695[1] = fRec2695[0];
			fRec2694[1] = fRec2694[0];
			fRec2692[1] = fRec2692[0];
			fRec2715[1] = fRec2715[0];
			fRec2713[1] = fRec2713[0];
			fRec2712[1] = fRec2712[0];
			fRec2710[1] = fRec2710[0];
			fRec2709[1] = fRec2709[0];
			fRec2707[1] = fRec2707[0];
			fRec2706[1] = fRec2706[0];
			fRec2704[1] = fRec2704[0];
			fRec2703[1] = fRec2703[0];
			fRec2701[1] = fRec2701[0];
			fRec2700[1] = fRec2700[0];
			fRec2698[1] = fRec2698[0];
			fRec2730[1] = fRec2730[0];
			fRec2728[1] = fRec2728[0];
			fRec2727[1] = fRec2727[0];
			fRec2725[1] = fRec2725[0];
			fRec2724[1] = fRec2724[0];
			fRec2722[1] = fRec2722[0];
			fRec2721[1] = fRec2721[0];
			fRec2719[1] = fRec2719[0];
			fRec2718[1] = fRec2718[0];
			fRec2716[1] = fRec2716[0];
			fRec2742[1] = fRec2742[0];
			fRec2740[1] = fRec2740[0];
			fRec2739[1] = fRec2739[0];
			fRec2737[1] = fRec2737[0];
			fRec2736[1] = fRec2736[0];
			fRec2734[1] = fRec2734[0];
			fRec2733[1] = fRec2733[0];
			fRec2731[1] = fRec2731[0];
			fRec2751[1] = fRec2751[0];
			fRec2749[1] = fRec2749[0];
			fRec2748[1] = fRec2748[0];
			fRec2746[1] = fRec2746[0];
			fRec2745[1] = fRec2745[0];
			fRec2743[1] = fRec2743[0];
			fRec2754[1] = fRec2754[0];
			fRec2752[1] = fRec2752[0];
			fRec2760[1] = fRec2760[0];
			fRec2758[1] = fRec2758[0];
			fRec2757[1] = fRec2757[0];
			fRec2755[1] = fRec2755[0];
			fRec2778[1] = fRec2778[0];
			fRec2776[1] = fRec2776[0];
			fRec2775[1] = fRec2775[0];
			fRec2773[1] = fRec2773[0];
			fRec2772[1] = fRec2772[0];
			fRec2770[1] = fRec2770[0];
			fRec2769[1] = fRec2769[0];
			fRec2767[1] = fRec2767[0];
			fRec2766[1] = fRec2766[0];
			fRec2764[1] = fRec2764[0];
			fRec2763[1] = fRec2763[0];
			fRec2761[1] = fRec2761[0];
			fRec2793[1] = fRec2793[0];
			fRec2791[1] = fRec2791[0];
			fRec2790[1] = fRec2790[0];
			fRec2788[1] = fRec2788[0];
			fRec2787[1] = fRec2787[0];
			fRec2785[1] = fRec2785[0];
			fRec2784[1] = fRec2784[0];
			fRec2782[1] = fRec2782[0];
			fRec2781[1] = fRec2781[0];
			fRec2779[1] = fRec2779[0];
			fRec2805[1] = fRec2805[0];
			fRec2803[1] = fRec2803[0];
			fRec2802[1] = fRec2802[0];
			fRec2800[1] = fRec2800[0];
			fRec2799[1] = fRec2799[0];
			fRec2797[1] = fRec2797[0];
			fRec2796[1] = fRec2796[0];
			fRec2794[1] = fRec2794[0];
			fRec2814[1] = fRec2814[0];
			fRec2812[1] = fRec2812[0];
			fRec2811[1] = fRec2811[0];
			fRec2809[1] = fRec2809[0];
			fRec2808[1] = fRec2808[0];
			fRec2806[1] = fRec2806[0];
			fRec2817[1] = fRec2817[0];
			fRec2815[1] = fRec2815[0];
			fRec2823[1] = fRec2823[0];
			fRec2821[1] = fRec2821[0];
			fRec2820[1] = fRec2820[0];
			fRec2818[1] = fRec2818[0];
			fRec2841[1] = fRec2841[0];
			fRec2839[1] = fRec2839[0];
			fRec2838[1] = fRec2838[0];
			fRec2836[1] = fRec2836[0];
			fRec2835[1] = fRec2835[0];
			fRec2833[1] = fRec2833[0];
			fRec2832[1] = fRec2832[0];
			fRec2830[1] = fRec2830[0];
			fRec2829[1] = fRec2829[0];
			fRec2827[1] = fRec2827[0];
			fRec2826[1] = fRec2826[0];
			fRec2824[1] = fRec2824[0];
			fRec2856[1] = fRec2856[0];
			fRec2854[1] = fRec2854[0];
			fRec2853[1] = fRec2853[0];
			fRec2851[1] = fRec2851[0];
			fRec2850[1] = fRec2850[0];
			fRec2848[1] = fRec2848[0];
			fRec2847[1] = fRec2847[0];
			fRec2845[1] = fRec2845[0];
			fRec2844[1] = fRec2844[0];
			fRec2842[1] = fRec2842[0];
			fRec2868[1] = fRec2868[0];
			fRec2866[1] = fRec2866[0];
			fRec2865[1] = fRec2865[0];
			fRec2863[1] = fRec2863[0];
			fRec2862[1] = fRec2862[0];
			fRec2860[1] = fRec2860[0];
			fRec2859[1] = fRec2859[0];
			fRec2857[1] = fRec2857[0];
			fRec2877[1] = fRec2877[0];
			fRec2875[1] = fRec2875[0];
			fRec2874[1] = fRec2874[0];
			fRec2872[1] = fRec2872[0];
			fRec2871[1] = fRec2871[0];
			fRec2869[1] = fRec2869[0];
			fRec2880[1] = fRec2880[0];
			fRec2878[1] = fRec2878[0];
			fRec2886[1] = fRec2886[0];
			fRec2884[1] = fRec2884[0];
			fRec2883[1] = fRec2883[0];
			fRec2881[1] = fRec2881[0];
			
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
