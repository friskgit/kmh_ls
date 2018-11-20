/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMHLS_Dome_7h7v_normal_2"
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
	double fRec4[3];
	double fRec5[3];
	double fRec6[3];
	double fRec7[3];
	double fRec8[3];
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
	double fConst12;
	double fConst13;
	double fRec27[2];
	double fRec25[2];
	double fRec24[2];
	double fRec22[2];
	double fRec21[2];
	double fRec19[2];
	double fRec18[2];
	double fRec16[2];
	double fRec15[2];
	double fRec13[2];
	double fRec12[2];
	double fRec10[2];
	double fRec9[3];
	double fRec46[2];
	double fRec44[2];
	double fRec43[2];
	double fRec41[2];
	double fRec40[2];
	double fRec38[2];
	double fRec37[2];
	double fRec35[2];
	double fRec34[2];
	double fRec32[2];
	double fRec31[2];
	double fRec29[2];
	double fRec28[3];
	double fRec65[2];
	double fRec63[2];
	double fRec62[2];
	double fRec60[2];
	double fRec59[2];
	double fRec57[2];
	double fRec56[2];
	double fRec54[2];
	double fRec53[2];
	double fRec51[2];
	double fRec50[2];
	double fRec48[2];
	double fRec47[3];
	double fRec84[2];
	double fRec82[2];
	double fRec81[2];
	double fRec79[2];
	double fRec78[2];
	double fRec76[2];
	double fRec75[2];
	double fRec73[2];
	double fRec72[2];
	double fRec70[2];
	double fRec69[2];
	double fRec67[2];
	double fRec66[3];
	double fRec103[2];
	double fRec101[2];
	double fRec100[2];
	double fRec98[2];
	double fRec97[2];
	double fRec95[2];
	double fRec94[2];
	double fRec92[2];
	double fRec91[2];
	double fRec89[2];
	double fRec88[2];
	double fRec86[2];
	double fRec85[3];
	double fRec122[2];
	double fRec120[2];
	double fRec119[2];
	double fRec117[2];
	double fRec116[2];
	double fRec114[2];
	double fRec113[2];
	double fRec111[2];
	double fRec110[2];
	double fRec108[2];
	double fRec107[2];
	double fRec105[2];
	double fRec104[3];
	double fConst14;
	double fConst15;
	double fConst16;
	double fConst17;
	double fConst18;
	double fConst19;
	double fConst20;
	double fConst21;
	double fConst22;
	double fRec138[2];
	double fRec136[2];
	double fRec135[2];
	double fRec133[2];
	double fRec132[2];
	double fRec130[2];
	double fRec129[2];
	double fRec127[2];
	double fRec126[2];
	double fRec124[2];
	double fRec123[3];
	double fRec154[2];
	double fRec152[2];
	double fRec151[2];
	double fRec149[2];
	double fRec148[2];
	double fRec146[2];
	double fRec145[2];
	double fRec143[2];
	double fRec142[2];
	double fRec140[2];
	double fRec139[3];
	double fRec170[2];
	double fRec168[2];
	double fRec167[2];
	double fRec165[2];
	double fRec164[2];
	double fRec162[2];
	double fRec161[2];
	double fRec159[2];
	double fRec158[2];
	double fRec156[2];
	double fRec155[3];
	double fRec186[2];
	double fRec184[2];
	double fRec183[2];
	double fRec181[2];
	double fRec180[2];
	double fRec178[2];
	double fRec177[2];
	double fRec175[2];
	double fRec174[2];
	double fRec172[2];
	double fRec171[3];
	double fConst23;
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fConst28;
	double fRec196[2];
	double fRec194[2];
	double fRec193[2];
	double fRec191[2];
	double fRec190[2];
	double fRec188[2];
	double fRec187[3];
	double fConst29;
	double fConst30;
	double fConst31;
	double fConst32;
	double fRec203[2];
	double fRec201[2];
	double fRec200[2];
	double fRec198[2];
	double fRec197[3];
	double fRec210[2];
	double fRec208[2];
	double fRec207[2];
	double fRec205[2];
	double fRec204[3];
	double fRec217[2];
	double fRec215[2];
	double fRec214[2];
	double fRec212[2];
	double fRec211[3];
	double fRec224[2];
	double fRec222[2];
	double fRec221[2];
	double fRec219[2];
	double fRec218[3];
	double fConst33;
	double fConst34;
	double fConst35;
	double fRec228[2];
	double fRec226[2];
	double fRec225[3];
	double fRec232[2];
	double fRec230[2];
	double fRec229[3];
	double fRec236[2];
	double fRec234[2];
	double fRec233[3];
	double fRec243[2];
	double fRec241[2];
	double fRec240[2];
	double fRec238[2];
	double fRec237[3];
	double fRec253[2];
	double fRec251[2];
	double fRec250[2];
	double fRec248[2];
	double fRec247[2];
	double fRec245[2];
	double fRec244[3];
	double fConst36;
	double fConst37;
	double fConst38;
	double fConst39;
	double fConst40;
	double fConst41;
	double fConst42;
	double fRec266[2];
	double fRec264[2];
	double fRec263[2];
	double fRec261[2];
	double fRec260[2];
	double fRec258[2];
	double fRec257[2];
	double fRec255[2];
	double fRec254[3];
	double fRec282[2];
	double fRec280[2];
	double fRec279[2];
	double fRec277[2];
	double fRec276[2];
	double fRec274[2];
	double fRec273[2];
	double fRec271[2];
	double fRec270[2];
	double fRec268[2];
	double fRec267[3];
	double fRec301[2];
	double fRec299[2];
	double fRec298[2];
	double fRec296[2];
	double fRec295[2];
	double fRec293[2];
	double fRec292[2];
	double fRec290[2];
	double fRec289[2];
	double fRec287[2];
	double fRec286[2];
	double fRec284[2];
	double fRec283[3];
	double fRec302[3];
	double fRec303[3];
	double fRec304[3];
	double fRec305[3];
	double fRec306[3];
	double fRec307[3];
	double fRec308[3];
	double fRec309[3];
	double fRec328[2];
	double fRec326[2];
	double fRec325[2];
	double fRec323[2];
	double fRec322[2];
	double fRec320[2];
	double fRec319[2];
	double fRec317[2];
	double fRec316[2];
	double fRec314[2];
	double fRec313[2];
	double fRec311[2];
	double fRec310[3];
	double fRec347[2];
	double fRec345[2];
	double fRec344[2];
	double fRec342[2];
	double fRec341[2];
	double fRec339[2];
	double fRec338[2];
	double fRec336[2];
	double fRec335[2];
	double fRec333[2];
	double fRec332[2];
	double fRec330[2];
	double fRec329[3];
	double fRec366[2];
	double fRec364[2];
	double fRec363[2];
	double fRec361[2];
	double fRec360[2];
	double fRec358[2];
	double fRec357[2];
	double fRec355[2];
	double fRec354[2];
	double fRec352[2];
	double fRec351[2];
	double fRec349[2];
	double fRec348[3];
	double fRec385[2];
	double fRec383[2];
	double fRec382[2];
	double fRec380[2];
	double fRec379[2];
	double fRec377[2];
	double fRec376[2];
	double fRec374[2];
	double fRec373[2];
	double fRec371[2];
	double fRec370[2];
	double fRec368[2];
	double fRec367[3];
	double fRec404[2];
	double fRec402[2];
	double fRec401[2];
	double fRec399[2];
	double fRec398[2];
	double fRec396[2];
	double fRec395[2];
	double fRec393[2];
	double fRec392[2];
	double fRec390[2];
	double fRec389[2];
	double fRec387[2];
	double fRec386[3];
	double fRec420[2];
	double fRec418[2];
	double fRec417[2];
	double fRec415[2];
	double fRec414[2];
	double fRec412[2];
	double fRec411[2];
	double fRec409[2];
	double fRec408[2];
	double fRec406[2];
	double fRec405[3];
	double fRec436[2];
	double fRec434[2];
	double fRec433[2];
	double fRec431[2];
	double fRec430[2];
	double fRec428[2];
	double fRec427[2];
	double fRec425[2];
	double fRec424[2];
	double fRec422[2];
	double fRec421[3];
	double fRec452[2];
	double fRec450[2];
	double fRec449[2];
	double fRec447[2];
	double fRec446[2];
	double fRec444[2];
	double fRec443[2];
	double fRec441[2];
	double fRec440[2];
	double fRec438[2];
	double fRec437[3];
	double fRec468[2];
	double fRec466[2];
	double fRec465[2];
	double fRec463[2];
	double fRec462[2];
	double fRec460[2];
	double fRec459[2];
	double fRec457[2];
	double fRec456[2];
	double fRec454[2];
	double fRec453[3];
	double fRec484[2];
	double fRec482[2];
	double fRec481[2];
	double fRec479[2];
	double fRec478[2];
	double fRec476[2];
	double fRec475[2];
	double fRec473[2];
	double fRec472[2];
	double fRec470[2];
	double fRec469[3];
	double fRec497[2];
	double fRec495[2];
	double fRec494[2];
	double fRec492[2];
	double fRec491[2];
	double fRec489[2];
	double fRec488[2];
	double fRec486[2];
	double fRec485[3];
	double fRec510[2];
	double fRec508[2];
	double fRec507[2];
	double fRec505[2];
	double fRec504[2];
	double fRec502[2];
	double fRec501[2];
	double fRec499[2];
	double fRec498[3];
	double fRec523[2];
	double fRec521[2];
	double fRec520[2];
	double fRec518[2];
	double fRec517[2];
	double fRec515[2];
	double fRec514[2];
	double fRec512[2];
	double fRec511[3];
	double fRec536[2];
	double fRec534[2];
	double fRec533[2];
	double fRec531[2];
	double fRec530[2];
	double fRec528[2];
	double fRec527[2];
	double fRec525[2];
	double fRec524[3];
	double fRec549[2];
	double fRec547[2];
	double fRec546[2];
	double fRec544[2];
	double fRec543[2];
	double fRec541[2];
	double fRec540[2];
	double fRec538[2];
	double fRec537[3];
	double fRec562[2];
	double fRec560[2];
	double fRec559[2];
	double fRec557[2];
	double fRec556[2];
	double fRec554[2];
	double fRec553[2];
	double fRec551[2];
	double fRec550[3];
	double fRec575[2];
	double fRec573[2];
	double fRec572[2];
	double fRec570[2];
	double fRec569[2];
	double fRec567[2];
	double fRec566[2];
	double fRec564[2];
	double fRec563[3];
	double fRec585[2];
	double fRec583[2];
	double fRec582[2];
	double fRec580[2];
	double fRec579[2];
	double fRec577[2];
	double fRec576[3];
	double fRec595[2];
	double fRec593[2];
	double fRec592[2];
	double fRec590[2];
	double fRec589[2];
	double fRec587[2];
	double fRec586[3];
	double fRec605[2];
	double fRec603[2];
	double fRec602[2];
	double fRec600[2];
	double fRec599[2];
	double fRec597[2];
	double fRec596[3];
	double fRec615[2];
	double fRec613[2];
	double fRec612[2];
	double fRec610[2];
	double fRec609[2];
	double fRec607[2];
	double fRec606[3];
	double fRec616[3];
	double fRec626[2];
	double fRec624[2];
	double fRec623[2];
	double fRec621[2];
	double fRec620[2];
	double fRec618[2];
	double fRec617[3];
	double fRec639[2];
	double fRec637[2];
	double fRec636[2];
	double fRec634[2];
	double fRec633[2];
	double fRec631[2];
	double fRec630[2];
	double fRec628[2];
	double fRec627[3];
	double fRec655[2];
	double fRec653[2];
	double fRec652[2];
	double fRec650[2];
	double fRec649[2];
	double fRec647[2];
	double fRec646[2];
	double fRec644[2];
	double fRec643[2];
	double fRec641[2];
	double fRec640[3];
	double fRec674[2];
	double fRec672[2];
	double fRec671[2];
	double fRec669[2];
	double fRec668[2];
	double fRec666[2];
	double fRec665[2];
	double fRec663[2];
	double fRec662[2];
	double fRec660[2];
	double fRec659[2];
	double fRec657[2];
	double fRec656[3];
	double fRec675[3];
	int IOTA;
	double fVec0[128];
	int iConst43;
	double fVec1[128];
	int iConst44;
	double fVec2[128];
	double fVec3[128];
	int iConst45;
	double fVec4[128];
	double fVec5[128];
	double fVec6[128];
	double fVec7[128];
	double fVec8[128];
	double fVec9[128];
	double fVec10[128];
	double fVec11[128];
	double fVec12[128];
	double fVec13[128];
	double fVec14[128];
	double fVec15[128];
	double fVec16[128];
	int iConst46;
	double fVec17[128];
	double fVec18[128];
	double fVec19[128];
	double fVec20[128];
	double fVec21[128];
	double fVec22[128];
	double fVec23[128];
	double fVec24[12];
	int iConst47;
	double fVec25[12];
	double fVec26[12];
	double fVec27[12];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMHLS_Dome_7h7v_normal_2");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMHLS_Dome_7h7v_normal_2");
		m->declare("version", "1.2");
	}

	virtual int getNumInputs() {
		return 64;
		
	}
	virtual int getNumOutputs() {
		return 29;
		
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
			case 49: {
				rate = 1;
				break;
			}
			case 50: {
				rate = 1;
				break;
			}
			case 51: {
				rate = 1;
				break;
			}
			case 52: {
				rate = 1;
				break;
			}
			case 53: {
				rate = 1;
				break;
			}
			case 54: {
				rate = 1;
				break;
			}
			case 55: {
				rate = 1;
				break;
			}
			case 56: {
				rate = 1;
				break;
			}
			case 57: {
				rate = 1;
				break;
			}
			case 58: {
				rate = 1;
				break;
			}
			case 59: {
				rate = 1;
				break;
			}
			case 60: {
				rate = 1;
				break;
			}
			case 61: {
				rate = 1;
				break;
			}
			case 62: {
				rate = 1;
				break;
			}
			case 63: {
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
		fConst3 = mydsp_faustpower2_f(fConst2);
		fConst4 = ((((20583.046872980165 / fConst2) + 281.1344672162669) / fConst2) + 1.0);
		fConst5 = (0.0 - (82332.18749192066 / (fConst3 * fConst4)));
		fConst6 = (0.0 - (((82332.18749192066 / fConst2) + 562.2689344325338) / (fConst2 * fConst4)));
		fConst7 = ((((22829.192896113698 / fConst2) + 247.20987105131519) / fConst2) + 1.0);
		fConst8 = (0.0 - (91316.771584454793 / (fConst3 * fConst7)));
		fConst9 = (0.0 - (((91316.771584454793 / fConst2) + 494.41974210263038) / (fConst2 * fConst7)));
		fConst10 = ((((29026.947281089433 / fConst2) + 166.49139259009885) / fConst2) + 1.0);
		fConst11 = (1.0 / ((fConst10 * fConst4) * fConst7));
		fConst12 = (0.0 - (116107.78912435773 / (fConst10 * fConst3)));
		fConst13 = (0.0 - (((116107.78912435773 / fConst2) + 332.98278518019771) / (fConst10 * fConst2)));
		fConst14 = ((120.66115605394451 / fConst2) + 1.0);
		fConst15 = (0.0 - (241.32231210788902 / (fConst2 * fConst14)));
		fConst16 = ((((15625.184559991036 / fConst2) + 221.81514994370366) / fConst2) + 1.0);
		fConst17 = (0.0 - (62500.738239964143 / (fConst3 * fConst16)));
		fConst18 = (0.0 - (((62500.738239964143 / fConst2) + 443.63029988740732) / (fConst2 * fConst16)));
		fConst19 = ((((19877.11788698009 / fConst2) + 153.83493032926589) / fConst2) + 1.0);
		fConst20 = (1.0 / ((fConst14 * fConst16) * fConst19));
		fConst21 = (0.0 - (79508.471547920359 / (fConst3 * fConst19)));
		fConst22 = (0.0 - (((79508.471547920359 / fConst2) + 307.66986065853177) / (fConst2 * fConst19)));
		fConst23 = ((76.835112288981804 / fConst2) + 1.0);
		fConst24 = (0.0 - (153.67022457796361 / (fConst2 * fConst23)));
		fConst25 = ((((7071.6388713657261 / fConst2) + 121.68938224178397) / fConst2) + 1.0);
		fConst26 = (1.0 / (fConst23 * fConst25));
		fConst27 = (0.0 - (28286.555485462904 / (fConst3 * fConst25)));
		fConst28 = (0.0 - (((28286.555485462904 / fConst2) + 243.37876448356795) / (fConst2 * fConst25)));
		fConst29 = ((((3284.3312440580044 / fConst2) + 99.262247265382882) / fConst2) + 1.0);
		fConst30 = (1.0 / fConst29);
		fConst31 = (0.0 - (13137.324976232017 / (fConst3 * fConst29)));
		fConst32 = (0.0 - (((13137.324976232017 / fConst2) + 198.52449453076576) / (fConst2 * fConst29)));
		fConst33 = ((33.08741575512763 / fConst2) + 1.0);
		fConst34 = (1.0 / fConst33);
		fConst35 = (0.0 - (66.17483151025526 / (fConst2 * fConst33)));
		fConst36 = ((((10006.405819239841 / fConst2) + 191.65624865985308) / fConst2) + 1.0);
		fConst37 = (0.0 - (40025.623276959363 / (fConst3 * fConst36)));
		fConst38 = (0.0 - (((40025.623276959363 / fConst2) + 383.31249731970615) / (fConst2 * fConst36)));
		fConst39 = ((((12576.580677230806 / fConst2) + 139.21790889142318) / fConst2) + 1.0);
		fConst40 = (1.0 / (fConst36 * fConst39));
		fConst41 = (0.0 - (50306.322708923224 / (fConst3 * fConst39)));
		fConst42 = (0.0 - (((50306.322708923224 / fConst2) + 278.43581778284636) / (fConst2 * fConst39)));
		iConst43 = int(((0.00061186204235308644 * double(iConst0)) + 0.5));
		iConst44 = int(((0.00059146664094131783 * double(iConst0)) + 0.5));
		iConst45 = int(((0.00060020752726064536 * double(iConst0)) + 0.5));
		iConst46 = int(((0.00039625351314295164 * double(iConst0)) + 0.5));
		iConst47 = int(((5.5358946689089155e-05 * double(iConst0)) + 0.5));
		
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
			fRec4[l4] = 0.0;
			
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec5[l5] = 0.0;
			
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec6[l6] = 0.0;
			
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec7[l7] = 0.0;
			
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec8[l8] = 0.0;
			
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec27[l9] = 0.0;
			
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec25[l10] = 0.0;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec24[l11] = 0.0;
			
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec22[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec21[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec19[l14] = 0.0;
			
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
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec9[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec46[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec44[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec43[l24] = 0.0;
			
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec41[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec40[l26] = 0.0;
			
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec38[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec37[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec35[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec34[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec32[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec31[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec29[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec28[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec65[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec63[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec62[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec60[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec59[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec57[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec56[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec54[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec53[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec51[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec50[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec48[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec47[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec84[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec82[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec81[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec79[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec78[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fRec76[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec75[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec73[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fRec72[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fRec70[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec69[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec67[l59] = 0.0;
			
		}
		for (int l60 = 0; (l60 < 3); l60 = (l60 + 1)) {
			fRec66[l60] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec103[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec101[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec100[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec98[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec97[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec95[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec94[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec92[l68] = 0.0;
			
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec91[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec89[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec88[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec86[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 3); l73 = (l73 + 1)) {
			fRec85[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec122[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 2); l75 = (l75 + 1)) {
			fRec120[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec119[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec117[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec116[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fRec114[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec113[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec111[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec110[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fRec108[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec107[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec105[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 3); l86 = (l86 + 1)) {
			fRec104[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 2); l87 = (l87 + 1)) {
			fRec138[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			fRec136[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec135[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec133[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec132[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec130[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec129[l93] = 0.0;
			
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec127[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec126[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fRec124[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 3); l97 = (l97 + 1)) {
			fRec123[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec154[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec152[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 2); l100 = (l100 + 1)) {
			fRec151[l100] = 0.0;
			
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fRec149[l101] = 0.0;
			
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec148[l102] = 0.0;
			
		}
		for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) {
			fRec146[l103] = 0.0;
			
		}
		for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) {
			fRec145[l104] = 0.0;
			
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fRec143[l105] = 0.0;
			
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec142[l106] = 0.0;
			
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fRec140[l107] = 0.0;
			
		}
		for (int l108 = 0; (l108 < 3); l108 = (l108 + 1)) {
			fRec139[l108] = 0.0;
			
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec170[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec168[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec167[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec165[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec164[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec162[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec161[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec159[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec158[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec156[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 3); l119 = (l119 + 1)) {
			fRec155[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec186[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec184[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec183[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec181[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec180[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fRec178[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec177[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec175[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec174[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec172[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 3); l130 = (l130 + 1)) {
			fRec171[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 2); l131 = (l131 + 1)) {
			fRec196[l131] = 0.0;
			
		}
		for (int l132 = 0; (l132 < 2); l132 = (l132 + 1)) {
			fRec194[l132] = 0.0;
			
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec193[l133] = 0.0;
			
		}
		for (int l134 = 0; (l134 < 2); l134 = (l134 + 1)) {
			fRec191[l134] = 0.0;
			
		}
		for (int l135 = 0; (l135 < 2); l135 = (l135 + 1)) {
			fRec190[l135] = 0.0;
			
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec188[l136] = 0.0;
			
		}
		for (int l137 = 0; (l137 < 3); l137 = (l137 + 1)) {
			fRec187[l137] = 0.0;
			
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec203[l138] = 0.0;
			
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fRec201[l139] = 0.0;
			
		}
		for (int l140 = 0; (l140 < 2); l140 = (l140 + 1)) {
			fRec200[l140] = 0.0;
			
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fRec198[l141] = 0.0;
			
		}
		for (int l142 = 0; (l142 < 3); l142 = (l142 + 1)) {
			fRec197[l142] = 0.0;
			
		}
		for (int l143 = 0; (l143 < 2); l143 = (l143 + 1)) {
			fRec210[l143] = 0.0;
			
		}
		for (int l144 = 0; (l144 < 2); l144 = (l144 + 1)) {
			fRec208[l144] = 0.0;
			
		}
		for (int l145 = 0; (l145 < 2); l145 = (l145 + 1)) {
			fRec207[l145] = 0.0;
			
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fRec205[l146] = 0.0;
			
		}
		for (int l147 = 0; (l147 < 3); l147 = (l147 + 1)) {
			fRec204[l147] = 0.0;
			
		}
		for (int l148 = 0; (l148 < 2); l148 = (l148 + 1)) {
			fRec217[l148] = 0.0;
			
		}
		for (int l149 = 0; (l149 < 2); l149 = (l149 + 1)) {
			fRec215[l149] = 0.0;
			
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec214[l150] = 0.0;
			
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec212[l151] = 0.0;
			
		}
		for (int l152 = 0; (l152 < 3); l152 = (l152 + 1)) {
			fRec211[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec224[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec222[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec221[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec219[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 3); l157 = (l157 + 1)) {
			fRec218[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec228[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec226[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 3); l160 = (l160 + 1)) {
			fRec225[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec232[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 2); l162 = (l162 + 1)) {
			fRec230[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 3); l163 = (l163 + 1)) {
			fRec229[l163] = 0.0;
			
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			fRec236[l164] = 0.0;
			
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec234[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 3); l166 = (l166 + 1)) {
			fRec233[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fRec243[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec241[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec240[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec238[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 3); l171 = (l171 + 1)) {
			fRec237[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec253[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fRec251[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec250[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec248[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec247[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec245[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 3); l178 = (l178 + 1)) {
			fRec244[l178] = 0.0;
			
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec266[l179] = 0.0;
			
		}
		for (int l180 = 0; (l180 < 2); l180 = (l180 + 1)) {
			fRec264[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec263[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec261[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fRec260[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec258[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec257[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fRec255[l186] = 0.0;
			
		}
		for (int l187 = 0; (l187 < 3); l187 = (l187 + 1)) {
			fRec254[l187] = 0.0;
			
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec282[l188] = 0.0;
			
		}
		for (int l189 = 0; (l189 < 2); l189 = (l189 + 1)) {
			fRec280[l189] = 0.0;
			
		}
		for (int l190 = 0; (l190 < 2); l190 = (l190 + 1)) {
			fRec279[l190] = 0.0;
			
		}
		for (int l191 = 0; (l191 < 2); l191 = (l191 + 1)) {
			fRec277[l191] = 0.0;
			
		}
		for (int l192 = 0; (l192 < 2); l192 = (l192 + 1)) {
			fRec276[l192] = 0.0;
			
		}
		for (int l193 = 0; (l193 < 2); l193 = (l193 + 1)) {
			fRec274[l193] = 0.0;
			
		}
		for (int l194 = 0; (l194 < 2); l194 = (l194 + 1)) {
			fRec273[l194] = 0.0;
			
		}
		for (int l195 = 0; (l195 < 2); l195 = (l195 + 1)) {
			fRec271[l195] = 0.0;
			
		}
		for (int l196 = 0; (l196 < 2); l196 = (l196 + 1)) {
			fRec270[l196] = 0.0;
			
		}
		for (int l197 = 0; (l197 < 2); l197 = (l197 + 1)) {
			fRec268[l197] = 0.0;
			
		}
		for (int l198 = 0; (l198 < 3); l198 = (l198 + 1)) {
			fRec267[l198] = 0.0;
			
		}
		for (int l199 = 0; (l199 < 2); l199 = (l199 + 1)) {
			fRec301[l199] = 0.0;
			
		}
		for (int l200 = 0; (l200 < 2); l200 = (l200 + 1)) {
			fRec299[l200] = 0.0;
			
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fRec298[l201] = 0.0;
			
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec296[l202] = 0.0;
			
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fRec295[l203] = 0.0;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec293[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec292[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec290[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec289[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec287[l208] = 0.0;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec286[l209] = 0.0;
			
		}
		for (int l210 = 0; (l210 < 2); l210 = (l210 + 1)) {
			fRec284[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 3); l211 = (l211 + 1)) {
			fRec283[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 3); l212 = (l212 + 1)) {
			fRec302[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 3); l213 = (l213 + 1)) {
			fRec303[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 3); l214 = (l214 + 1)) {
			fRec304[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 3); l215 = (l215 + 1)) {
			fRec305[l215] = 0.0;
			
		}
		for (int l216 = 0; (l216 < 3); l216 = (l216 + 1)) {
			fRec306[l216] = 0.0;
			
		}
		for (int l217 = 0; (l217 < 3); l217 = (l217 + 1)) {
			fRec307[l217] = 0.0;
			
		}
		for (int l218 = 0; (l218 < 3); l218 = (l218 + 1)) {
			fRec308[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 3); l219 = (l219 + 1)) {
			fRec309[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fRec328[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec326[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec325[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec323[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 2); l224 = (l224 + 1)) {
			fRec322[l224] = 0.0;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec320[l225] = 0.0;
			
		}
		for (int l226 = 0; (l226 < 2); l226 = (l226 + 1)) {
			fRec319[l226] = 0.0;
			
		}
		for (int l227 = 0; (l227 < 2); l227 = (l227 + 1)) {
			fRec317[l227] = 0.0;
			
		}
		for (int l228 = 0; (l228 < 2); l228 = (l228 + 1)) {
			fRec316[l228] = 0.0;
			
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fRec314[l229] = 0.0;
			
		}
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec313[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fRec311[l231] = 0.0;
			
		}
		for (int l232 = 0; (l232 < 3); l232 = (l232 + 1)) {
			fRec310[l232] = 0.0;
			
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fRec347[l233] = 0.0;
			
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec345[l234] = 0.0;
			
		}
		for (int l235 = 0; (l235 < 2); l235 = (l235 + 1)) {
			fRec344[l235] = 0.0;
			
		}
		for (int l236 = 0; (l236 < 2); l236 = (l236 + 1)) {
			fRec342[l236] = 0.0;
			
		}
		for (int l237 = 0; (l237 < 2); l237 = (l237 + 1)) {
			fRec341[l237] = 0.0;
			
		}
		for (int l238 = 0; (l238 < 2); l238 = (l238 + 1)) {
			fRec339[l238] = 0.0;
			
		}
		for (int l239 = 0; (l239 < 2); l239 = (l239 + 1)) {
			fRec338[l239] = 0.0;
			
		}
		for (int l240 = 0; (l240 < 2); l240 = (l240 + 1)) {
			fRec336[l240] = 0.0;
			
		}
		for (int l241 = 0; (l241 < 2); l241 = (l241 + 1)) {
			fRec335[l241] = 0.0;
			
		}
		for (int l242 = 0; (l242 < 2); l242 = (l242 + 1)) {
			fRec333[l242] = 0.0;
			
		}
		for (int l243 = 0; (l243 < 2); l243 = (l243 + 1)) {
			fRec332[l243] = 0.0;
			
		}
		for (int l244 = 0; (l244 < 2); l244 = (l244 + 1)) {
			fRec330[l244] = 0.0;
			
		}
		for (int l245 = 0; (l245 < 3); l245 = (l245 + 1)) {
			fRec329[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fRec366[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 2); l247 = (l247 + 1)) {
			fRec364[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 2); l248 = (l248 + 1)) {
			fRec363[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fRec361[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 2); l250 = (l250 + 1)) {
			fRec360[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 2); l251 = (l251 + 1)) {
			fRec358[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 2); l252 = (l252 + 1)) {
			fRec357[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec355[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec354[l254] = 0.0;
			
		}
		for (int l255 = 0; (l255 < 2); l255 = (l255 + 1)) {
			fRec352[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec351[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fRec349[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 3); l258 = (l258 + 1)) {
			fRec348[l258] = 0.0;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec385[l259] = 0.0;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec383[l260] = 0.0;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec382[l261] = 0.0;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec380[l262] = 0.0;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec379[l263] = 0.0;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec377[l264] = 0.0;
			
		}
		for (int l265 = 0; (l265 < 2); l265 = (l265 + 1)) {
			fRec376[l265] = 0.0;
			
		}
		for (int l266 = 0; (l266 < 2); l266 = (l266 + 1)) {
			fRec374[l266] = 0.0;
			
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec373[l267] = 0.0;
			
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec371[l268] = 0.0;
			
		}
		for (int l269 = 0; (l269 < 2); l269 = (l269 + 1)) {
			fRec370[l269] = 0.0;
			
		}
		for (int l270 = 0; (l270 < 2); l270 = (l270 + 1)) {
			fRec368[l270] = 0.0;
			
		}
		for (int l271 = 0; (l271 < 3); l271 = (l271 + 1)) {
			fRec367[l271] = 0.0;
			
		}
		for (int l272 = 0; (l272 < 2); l272 = (l272 + 1)) {
			fRec404[l272] = 0.0;
			
		}
		for (int l273 = 0; (l273 < 2); l273 = (l273 + 1)) {
			fRec402[l273] = 0.0;
			
		}
		for (int l274 = 0; (l274 < 2); l274 = (l274 + 1)) {
			fRec401[l274] = 0.0;
			
		}
		for (int l275 = 0; (l275 < 2); l275 = (l275 + 1)) {
			fRec399[l275] = 0.0;
			
		}
		for (int l276 = 0; (l276 < 2); l276 = (l276 + 1)) {
			fRec398[l276] = 0.0;
			
		}
		for (int l277 = 0; (l277 < 2); l277 = (l277 + 1)) {
			fRec396[l277] = 0.0;
			
		}
		for (int l278 = 0; (l278 < 2); l278 = (l278 + 1)) {
			fRec395[l278] = 0.0;
			
		}
		for (int l279 = 0; (l279 < 2); l279 = (l279 + 1)) {
			fRec393[l279] = 0.0;
			
		}
		for (int l280 = 0; (l280 < 2); l280 = (l280 + 1)) {
			fRec392[l280] = 0.0;
			
		}
		for (int l281 = 0; (l281 < 2); l281 = (l281 + 1)) {
			fRec390[l281] = 0.0;
			
		}
		for (int l282 = 0; (l282 < 2); l282 = (l282 + 1)) {
			fRec389[l282] = 0.0;
			
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec387[l283] = 0.0;
			
		}
		for (int l284 = 0; (l284 < 3); l284 = (l284 + 1)) {
			fRec386[l284] = 0.0;
			
		}
		for (int l285 = 0; (l285 < 2); l285 = (l285 + 1)) {
			fRec420[l285] = 0.0;
			
		}
		for (int l286 = 0; (l286 < 2); l286 = (l286 + 1)) {
			fRec418[l286] = 0.0;
			
		}
		for (int l287 = 0; (l287 < 2); l287 = (l287 + 1)) {
			fRec417[l287] = 0.0;
			
		}
		for (int l288 = 0; (l288 < 2); l288 = (l288 + 1)) {
			fRec415[l288] = 0.0;
			
		}
		for (int l289 = 0; (l289 < 2); l289 = (l289 + 1)) {
			fRec414[l289] = 0.0;
			
		}
		for (int l290 = 0; (l290 < 2); l290 = (l290 + 1)) {
			fRec412[l290] = 0.0;
			
		}
		for (int l291 = 0; (l291 < 2); l291 = (l291 + 1)) {
			fRec411[l291] = 0.0;
			
		}
		for (int l292 = 0; (l292 < 2); l292 = (l292 + 1)) {
			fRec409[l292] = 0.0;
			
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec408[l293] = 0.0;
			
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec406[l294] = 0.0;
			
		}
		for (int l295 = 0; (l295 < 3); l295 = (l295 + 1)) {
			fRec405[l295] = 0.0;
			
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec436[l296] = 0.0;
			
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec434[l297] = 0.0;
			
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec433[l298] = 0.0;
			
		}
		for (int l299 = 0; (l299 < 2); l299 = (l299 + 1)) {
			fRec431[l299] = 0.0;
			
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec430[l300] = 0.0;
			
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec428[l301] = 0.0;
			
		}
		for (int l302 = 0; (l302 < 2); l302 = (l302 + 1)) {
			fRec427[l302] = 0.0;
			
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec425[l303] = 0.0;
			
		}
		for (int l304 = 0; (l304 < 2); l304 = (l304 + 1)) {
			fRec424[l304] = 0.0;
			
		}
		for (int l305 = 0; (l305 < 2); l305 = (l305 + 1)) {
			fRec422[l305] = 0.0;
			
		}
		for (int l306 = 0; (l306 < 3); l306 = (l306 + 1)) {
			fRec421[l306] = 0.0;
			
		}
		for (int l307 = 0; (l307 < 2); l307 = (l307 + 1)) {
			fRec452[l307] = 0.0;
			
		}
		for (int l308 = 0; (l308 < 2); l308 = (l308 + 1)) {
			fRec450[l308] = 0.0;
			
		}
		for (int l309 = 0; (l309 < 2); l309 = (l309 + 1)) {
			fRec449[l309] = 0.0;
			
		}
		for (int l310 = 0; (l310 < 2); l310 = (l310 + 1)) {
			fRec447[l310] = 0.0;
			
		}
		for (int l311 = 0; (l311 < 2); l311 = (l311 + 1)) {
			fRec446[l311] = 0.0;
			
		}
		for (int l312 = 0; (l312 < 2); l312 = (l312 + 1)) {
			fRec444[l312] = 0.0;
			
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
		for (int l317 = 0; (l317 < 3); l317 = (l317 + 1)) {
			fRec437[l317] = 0.0;
			
		}
		for (int l318 = 0; (l318 < 2); l318 = (l318 + 1)) {
			fRec468[l318] = 0.0;
			
		}
		for (int l319 = 0; (l319 < 2); l319 = (l319 + 1)) {
			fRec466[l319] = 0.0;
			
		}
		for (int l320 = 0; (l320 < 2); l320 = (l320 + 1)) {
			fRec465[l320] = 0.0;
			
		}
		for (int l321 = 0; (l321 < 2); l321 = (l321 + 1)) {
			fRec463[l321] = 0.0;
			
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
		for (int l328 = 0; (l328 < 3); l328 = (l328 + 1)) {
			fRec453[l328] = 0.0;
			
		}
		for (int l329 = 0; (l329 < 2); l329 = (l329 + 1)) {
			fRec484[l329] = 0.0;
			
		}
		for (int l330 = 0; (l330 < 2); l330 = (l330 + 1)) {
			fRec482[l330] = 0.0;
			
		}
		for (int l331 = 0; (l331 < 2); l331 = (l331 + 1)) {
			fRec481[l331] = 0.0;
			
		}
		for (int l332 = 0; (l332 < 2); l332 = (l332 + 1)) {
			fRec479[l332] = 0.0;
			
		}
		for (int l333 = 0; (l333 < 2); l333 = (l333 + 1)) {
			fRec478[l333] = 0.0;
			
		}
		for (int l334 = 0; (l334 < 2); l334 = (l334 + 1)) {
			fRec476[l334] = 0.0;
			
		}
		for (int l335 = 0; (l335 < 2); l335 = (l335 + 1)) {
			fRec475[l335] = 0.0;
			
		}
		for (int l336 = 0; (l336 < 2); l336 = (l336 + 1)) {
			fRec473[l336] = 0.0;
			
		}
		for (int l337 = 0; (l337 < 2); l337 = (l337 + 1)) {
			fRec472[l337] = 0.0;
			
		}
		for (int l338 = 0; (l338 < 2); l338 = (l338 + 1)) {
			fRec470[l338] = 0.0;
			
		}
		for (int l339 = 0; (l339 < 3); l339 = (l339 + 1)) {
			fRec469[l339] = 0.0;
			
		}
		for (int l340 = 0; (l340 < 2); l340 = (l340 + 1)) {
			fRec497[l340] = 0.0;
			
		}
		for (int l341 = 0; (l341 < 2); l341 = (l341 + 1)) {
			fRec495[l341] = 0.0;
			
		}
		for (int l342 = 0; (l342 < 2); l342 = (l342 + 1)) {
			fRec494[l342] = 0.0;
			
		}
		for (int l343 = 0; (l343 < 2); l343 = (l343 + 1)) {
			fRec492[l343] = 0.0;
			
		}
		for (int l344 = 0; (l344 < 2); l344 = (l344 + 1)) {
			fRec491[l344] = 0.0;
			
		}
		for (int l345 = 0; (l345 < 2); l345 = (l345 + 1)) {
			fRec489[l345] = 0.0;
			
		}
		for (int l346 = 0; (l346 < 2); l346 = (l346 + 1)) {
			fRec488[l346] = 0.0;
			
		}
		for (int l347 = 0; (l347 < 2); l347 = (l347 + 1)) {
			fRec486[l347] = 0.0;
			
		}
		for (int l348 = 0; (l348 < 3); l348 = (l348 + 1)) {
			fRec485[l348] = 0.0;
			
		}
		for (int l349 = 0; (l349 < 2); l349 = (l349 + 1)) {
			fRec510[l349] = 0.0;
			
		}
		for (int l350 = 0; (l350 < 2); l350 = (l350 + 1)) {
			fRec508[l350] = 0.0;
			
		}
		for (int l351 = 0; (l351 < 2); l351 = (l351 + 1)) {
			fRec507[l351] = 0.0;
			
		}
		for (int l352 = 0; (l352 < 2); l352 = (l352 + 1)) {
			fRec505[l352] = 0.0;
			
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec504[l353] = 0.0;
			
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec502[l354] = 0.0;
			
		}
		for (int l355 = 0; (l355 < 2); l355 = (l355 + 1)) {
			fRec501[l355] = 0.0;
			
		}
		for (int l356 = 0; (l356 < 2); l356 = (l356 + 1)) {
			fRec499[l356] = 0.0;
			
		}
		for (int l357 = 0; (l357 < 3); l357 = (l357 + 1)) {
			fRec498[l357] = 0.0;
			
		}
		for (int l358 = 0; (l358 < 2); l358 = (l358 + 1)) {
			fRec523[l358] = 0.0;
			
		}
		for (int l359 = 0; (l359 < 2); l359 = (l359 + 1)) {
			fRec521[l359] = 0.0;
			
		}
		for (int l360 = 0; (l360 < 2); l360 = (l360 + 1)) {
			fRec520[l360] = 0.0;
			
		}
		for (int l361 = 0; (l361 < 2); l361 = (l361 + 1)) {
			fRec518[l361] = 0.0;
			
		}
		for (int l362 = 0; (l362 < 2); l362 = (l362 + 1)) {
			fRec517[l362] = 0.0;
			
		}
		for (int l363 = 0; (l363 < 2); l363 = (l363 + 1)) {
			fRec515[l363] = 0.0;
			
		}
		for (int l364 = 0; (l364 < 2); l364 = (l364 + 1)) {
			fRec514[l364] = 0.0;
			
		}
		for (int l365 = 0; (l365 < 2); l365 = (l365 + 1)) {
			fRec512[l365] = 0.0;
			
		}
		for (int l366 = 0; (l366 < 3); l366 = (l366 + 1)) {
			fRec511[l366] = 0.0;
			
		}
		for (int l367 = 0; (l367 < 2); l367 = (l367 + 1)) {
			fRec536[l367] = 0.0;
			
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec534[l368] = 0.0;
			
		}
		for (int l369 = 0; (l369 < 2); l369 = (l369 + 1)) {
			fRec533[l369] = 0.0;
			
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec531[l370] = 0.0;
			
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			fRec530[l371] = 0.0;
			
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			fRec528[l372] = 0.0;
			
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fRec527[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec525[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 3); l375 = (l375 + 1)) {
			fRec524[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec549[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec547[l377] = 0.0;
			
		}
		for (int l378 = 0; (l378 < 2); l378 = (l378 + 1)) {
			fRec546[l378] = 0.0;
			
		}
		for (int l379 = 0; (l379 < 2); l379 = (l379 + 1)) {
			fRec544[l379] = 0.0;
			
		}
		for (int l380 = 0; (l380 < 2); l380 = (l380 + 1)) {
			fRec543[l380] = 0.0;
			
		}
		for (int l381 = 0; (l381 < 2); l381 = (l381 + 1)) {
			fRec541[l381] = 0.0;
			
		}
		for (int l382 = 0; (l382 < 2); l382 = (l382 + 1)) {
			fRec540[l382] = 0.0;
			
		}
		for (int l383 = 0; (l383 < 2); l383 = (l383 + 1)) {
			fRec538[l383] = 0.0;
			
		}
		for (int l384 = 0; (l384 < 3); l384 = (l384 + 1)) {
			fRec537[l384] = 0.0;
			
		}
		for (int l385 = 0; (l385 < 2); l385 = (l385 + 1)) {
			fRec562[l385] = 0.0;
			
		}
		for (int l386 = 0; (l386 < 2); l386 = (l386 + 1)) {
			fRec560[l386] = 0.0;
			
		}
		for (int l387 = 0; (l387 < 2); l387 = (l387 + 1)) {
			fRec559[l387] = 0.0;
			
		}
		for (int l388 = 0; (l388 < 2); l388 = (l388 + 1)) {
			fRec557[l388] = 0.0;
			
		}
		for (int l389 = 0; (l389 < 2); l389 = (l389 + 1)) {
			fRec556[l389] = 0.0;
			
		}
		for (int l390 = 0; (l390 < 2); l390 = (l390 + 1)) {
			fRec554[l390] = 0.0;
			
		}
		for (int l391 = 0; (l391 < 2); l391 = (l391 + 1)) {
			fRec553[l391] = 0.0;
			
		}
		for (int l392 = 0; (l392 < 2); l392 = (l392 + 1)) {
			fRec551[l392] = 0.0;
			
		}
		for (int l393 = 0; (l393 < 3); l393 = (l393 + 1)) {
			fRec550[l393] = 0.0;
			
		}
		for (int l394 = 0; (l394 < 2); l394 = (l394 + 1)) {
			fRec575[l394] = 0.0;
			
		}
		for (int l395 = 0; (l395 < 2); l395 = (l395 + 1)) {
			fRec573[l395] = 0.0;
			
		}
		for (int l396 = 0; (l396 < 2); l396 = (l396 + 1)) {
			fRec572[l396] = 0.0;
			
		}
		for (int l397 = 0; (l397 < 2); l397 = (l397 + 1)) {
			fRec570[l397] = 0.0;
			
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
		for (int l402 = 0; (l402 < 3); l402 = (l402 + 1)) {
			fRec563[l402] = 0.0;
			
		}
		for (int l403 = 0; (l403 < 2); l403 = (l403 + 1)) {
			fRec585[l403] = 0.0;
			
		}
		for (int l404 = 0; (l404 < 2); l404 = (l404 + 1)) {
			fRec583[l404] = 0.0;
			
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec582[l405] = 0.0;
			
		}
		for (int l406 = 0; (l406 < 2); l406 = (l406 + 1)) {
			fRec580[l406] = 0.0;
			
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec579[l407] = 0.0;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec577[l408] = 0.0;
			
		}
		for (int l409 = 0; (l409 < 3); l409 = (l409 + 1)) {
			fRec576[l409] = 0.0;
			
		}
		for (int l410 = 0; (l410 < 2); l410 = (l410 + 1)) {
			fRec595[l410] = 0.0;
			
		}
		for (int l411 = 0; (l411 < 2); l411 = (l411 + 1)) {
			fRec593[l411] = 0.0;
			
		}
		for (int l412 = 0; (l412 < 2); l412 = (l412 + 1)) {
			fRec592[l412] = 0.0;
			
		}
		for (int l413 = 0; (l413 < 2); l413 = (l413 + 1)) {
			fRec590[l413] = 0.0;
			
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec589[l414] = 0.0;
			
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec587[l415] = 0.0;
			
		}
		for (int l416 = 0; (l416 < 3); l416 = (l416 + 1)) {
			fRec586[l416] = 0.0;
			
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec605[l417] = 0.0;
			
		}
		for (int l418 = 0; (l418 < 2); l418 = (l418 + 1)) {
			fRec603[l418] = 0.0;
			
		}
		for (int l419 = 0; (l419 < 2); l419 = (l419 + 1)) {
			fRec602[l419] = 0.0;
			
		}
		for (int l420 = 0; (l420 < 2); l420 = (l420 + 1)) {
			fRec600[l420] = 0.0;
			
		}
		for (int l421 = 0; (l421 < 2); l421 = (l421 + 1)) {
			fRec599[l421] = 0.0;
			
		}
		for (int l422 = 0; (l422 < 2); l422 = (l422 + 1)) {
			fRec597[l422] = 0.0;
			
		}
		for (int l423 = 0; (l423 < 3); l423 = (l423 + 1)) {
			fRec596[l423] = 0.0;
			
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec615[l424] = 0.0;
			
		}
		for (int l425 = 0; (l425 < 2); l425 = (l425 + 1)) {
			fRec613[l425] = 0.0;
			
		}
		for (int l426 = 0; (l426 < 2); l426 = (l426 + 1)) {
			fRec612[l426] = 0.0;
			
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec610[l427] = 0.0;
			
		}
		for (int l428 = 0; (l428 < 2); l428 = (l428 + 1)) {
			fRec609[l428] = 0.0;
			
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec607[l429] = 0.0;
			
		}
		for (int l430 = 0; (l430 < 3); l430 = (l430 + 1)) {
			fRec606[l430] = 0.0;
			
		}
		for (int l431 = 0; (l431 < 3); l431 = (l431 + 1)) {
			fRec616[l431] = 0.0;
			
		}
		for (int l432 = 0; (l432 < 2); l432 = (l432 + 1)) {
			fRec626[l432] = 0.0;
			
		}
		for (int l433 = 0; (l433 < 2); l433 = (l433 + 1)) {
			fRec624[l433] = 0.0;
			
		}
		for (int l434 = 0; (l434 < 2); l434 = (l434 + 1)) {
			fRec623[l434] = 0.0;
			
		}
		for (int l435 = 0; (l435 < 2); l435 = (l435 + 1)) {
			fRec621[l435] = 0.0;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec620[l436] = 0.0;
			
		}
		for (int l437 = 0; (l437 < 2); l437 = (l437 + 1)) {
			fRec618[l437] = 0.0;
			
		}
		for (int l438 = 0; (l438 < 3); l438 = (l438 + 1)) {
			fRec617[l438] = 0.0;
			
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec639[l439] = 0.0;
			
		}
		for (int l440 = 0; (l440 < 2); l440 = (l440 + 1)) {
			fRec637[l440] = 0.0;
			
		}
		for (int l441 = 0; (l441 < 2); l441 = (l441 + 1)) {
			fRec636[l441] = 0.0;
			
		}
		for (int l442 = 0; (l442 < 2); l442 = (l442 + 1)) {
			fRec634[l442] = 0.0;
			
		}
		for (int l443 = 0; (l443 < 2); l443 = (l443 + 1)) {
			fRec633[l443] = 0.0;
			
		}
		for (int l444 = 0; (l444 < 2); l444 = (l444 + 1)) {
			fRec631[l444] = 0.0;
			
		}
		for (int l445 = 0; (l445 < 2); l445 = (l445 + 1)) {
			fRec630[l445] = 0.0;
			
		}
		for (int l446 = 0; (l446 < 2); l446 = (l446 + 1)) {
			fRec628[l446] = 0.0;
			
		}
		for (int l447 = 0; (l447 < 3); l447 = (l447 + 1)) {
			fRec627[l447] = 0.0;
			
		}
		for (int l448 = 0; (l448 < 2); l448 = (l448 + 1)) {
			fRec655[l448] = 0.0;
			
		}
		for (int l449 = 0; (l449 < 2); l449 = (l449 + 1)) {
			fRec653[l449] = 0.0;
			
		}
		for (int l450 = 0; (l450 < 2); l450 = (l450 + 1)) {
			fRec652[l450] = 0.0;
			
		}
		for (int l451 = 0; (l451 < 2); l451 = (l451 + 1)) {
			fRec650[l451] = 0.0;
			
		}
		for (int l452 = 0; (l452 < 2); l452 = (l452 + 1)) {
			fRec649[l452] = 0.0;
			
		}
		for (int l453 = 0; (l453 < 2); l453 = (l453 + 1)) {
			fRec647[l453] = 0.0;
			
		}
		for (int l454 = 0; (l454 < 2); l454 = (l454 + 1)) {
			fRec646[l454] = 0.0;
			
		}
		for (int l455 = 0; (l455 < 2); l455 = (l455 + 1)) {
			fRec644[l455] = 0.0;
			
		}
		for (int l456 = 0; (l456 < 2); l456 = (l456 + 1)) {
			fRec643[l456] = 0.0;
			
		}
		for (int l457 = 0; (l457 < 2); l457 = (l457 + 1)) {
			fRec641[l457] = 0.0;
			
		}
		for (int l458 = 0; (l458 < 3); l458 = (l458 + 1)) {
			fRec640[l458] = 0.0;
			
		}
		for (int l459 = 0; (l459 < 2); l459 = (l459 + 1)) {
			fRec674[l459] = 0.0;
			
		}
		for (int l460 = 0; (l460 < 2); l460 = (l460 + 1)) {
			fRec672[l460] = 0.0;
			
		}
		for (int l461 = 0; (l461 < 2); l461 = (l461 + 1)) {
			fRec671[l461] = 0.0;
			
		}
		for (int l462 = 0; (l462 < 2); l462 = (l462 + 1)) {
			fRec669[l462] = 0.0;
			
		}
		for (int l463 = 0; (l463 < 2); l463 = (l463 + 1)) {
			fRec668[l463] = 0.0;
			
		}
		for (int l464 = 0; (l464 < 2); l464 = (l464 + 1)) {
			fRec666[l464] = 0.0;
			
		}
		for (int l465 = 0; (l465 < 2); l465 = (l465 + 1)) {
			fRec665[l465] = 0.0;
			
		}
		for (int l466 = 0; (l466 < 2); l466 = (l466 + 1)) {
			fRec663[l466] = 0.0;
			
		}
		for (int l467 = 0; (l467 < 2); l467 = (l467 + 1)) {
			fRec662[l467] = 0.0;
			
		}
		for (int l468 = 0; (l468 < 2); l468 = (l468 + 1)) {
			fRec660[l468] = 0.0;
			
		}
		for (int l469 = 0; (l469 < 2); l469 = (l469 + 1)) {
			fRec659[l469] = 0.0;
			
		}
		for (int l470 = 0; (l470 < 2); l470 = (l470 + 1)) {
			fRec657[l470] = 0.0;
			
		}
		for (int l471 = 0; (l471 < 3); l471 = (l471 + 1)) {
			fRec656[l471] = 0.0;
			
		}
		for (int l472 = 0; (l472 < 3); l472 = (l472 + 1)) {
			fRec675[l472] = 0.0;
			
		}
		IOTA = 0;
		for (int l473 = 0; (l473 < 128); l473 = (l473 + 1)) {
			fVec0[l473] = 0.0;
			
		}
		for (int l474 = 0; (l474 < 128); l474 = (l474 + 1)) {
			fVec1[l474] = 0.0;
			
		}
		for (int l475 = 0; (l475 < 128); l475 = (l475 + 1)) {
			fVec2[l475] = 0.0;
			
		}
		for (int l476 = 0; (l476 < 128); l476 = (l476 + 1)) {
			fVec3[l476] = 0.0;
			
		}
		for (int l477 = 0; (l477 < 128); l477 = (l477 + 1)) {
			fVec4[l477] = 0.0;
			
		}
		for (int l478 = 0; (l478 < 128); l478 = (l478 + 1)) {
			fVec5[l478] = 0.0;
			
		}
		for (int l479 = 0; (l479 < 128); l479 = (l479 + 1)) {
			fVec6[l479] = 0.0;
			
		}
		for (int l480 = 0; (l480 < 128); l480 = (l480 + 1)) {
			fVec7[l480] = 0.0;
			
		}
		for (int l481 = 0; (l481 < 128); l481 = (l481 + 1)) {
			fVec8[l481] = 0.0;
			
		}
		for (int l482 = 0; (l482 < 128); l482 = (l482 + 1)) {
			fVec9[l482] = 0.0;
			
		}
		for (int l483 = 0; (l483 < 128); l483 = (l483 + 1)) {
			fVec10[l483] = 0.0;
			
		}
		for (int l484 = 0; (l484 < 128); l484 = (l484 + 1)) {
			fVec11[l484] = 0.0;
			
		}
		for (int l485 = 0; (l485 < 128); l485 = (l485 + 1)) {
			fVec12[l485] = 0.0;
			
		}
		for (int l486 = 0; (l486 < 128); l486 = (l486 + 1)) {
			fVec13[l486] = 0.0;
			
		}
		for (int l487 = 0; (l487 < 128); l487 = (l487 + 1)) {
			fVec14[l487] = 0.0;
			
		}
		for (int l488 = 0; (l488 < 128); l488 = (l488 + 1)) {
			fVec15[l488] = 0.0;
			
		}
		for (int l489 = 0; (l489 < 128); l489 = (l489 + 1)) {
			fVec16[l489] = 0.0;
			
		}
		for (int l490 = 0; (l490 < 128); l490 = (l490 + 1)) {
			fVec17[l490] = 0.0;
			
		}
		for (int l491 = 0; (l491 < 128); l491 = (l491 + 1)) {
			fVec18[l491] = 0.0;
			
		}
		for (int l492 = 0; (l492 < 128); l492 = (l492 + 1)) {
			fVec19[l492] = 0.0;
			
		}
		for (int l493 = 0; (l493 < 128); l493 = (l493 + 1)) {
			fVec20[l493] = 0.0;
			
		}
		for (int l494 = 0; (l494 < 128); l494 = (l494 + 1)) {
			fVec21[l494] = 0.0;
			
		}
		for (int l495 = 0; (l495 < 128); l495 = (l495 + 1)) {
			fVec22[l495] = 0.0;
			
		}
		for (int l496 = 0; (l496 < 128); l496 = (l496 + 1)) {
			fVec23[l496] = 0.0;
			
		}
		for (int l497 = 0; (l497 < 12); l497 = (l497 + 1)) {
			fVec24[l497] = 0.0;
			
		}
		for (int l498 = 0; (l498 < 12); l498 = (l498 + 1)) {
			fVec25[l498] = 0.0;
			
		}
		for (int l499 = 0; (l499 < 12); l499 = (l499 + 1)) {
			fVec26[l499] = 0.0;
			
		}
		for (int l500 = 0; (l500 < 12); l500 = (l500 + 1)) {
			fVec27[l500] = 0.0;
			
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
		ui_interface->openVerticalBox("KMHLS_Dome_7h7v_normal_2");
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
		FAUSTFLOAT* input49 = inputs[49];
		FAUSTFLOAT* input50 = inputs[50];
		FAUSTFLOAT* input51 = inputs[51];
		FAUSTFLOAT* input52 = inputs[52];
		FAUSTFLOAT* input53 = inputs[53];
		FAUSTFLOAT* input54 = inputs[54];
		FAUSTFLOAT* input55 = inputs[55];
		FAUSTFLOAT* input56 = inputs[56];
		FAUSTFLOAT* input57 = inputs[57];
		FAUSTFLOAT* input58 = inputs[58];
		FAUSTFLOAT* input59 = inputs[59];
		FAUSTFLOAT* input60 = inputs[60];
		FAUSTFLOAT* input61 = inputs[61];
		FAUSTFLOAT* input62 = inputs[62];
		FAUSTFLOAT* input63 = inputs[63];
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
			fRec2[0] = (double(input61[i]) - (((fTemp2 * fRec2[2]) + (2.0 * (fTemp3 * fRec2[1]))) / fTemp4));
			fRec3[0] = (fSlow2 + (0.999 * fRec3[1]));
			double fTemp5 = (fRec3[0] * fTemp4);
			double fTemp6 = (0.0 - (2.0 / fTemp4));
			double fTemp7 = (((fTemp1 * (fRec2[2] + (fRec2[0] + (2.0 * fRec2[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec2[1]) + ((fRec2[0] + fRec2[2]) / fTemp4))))));
			fRec4[0] = (double(input59[i]) - (((fTemp2 * fRec4[2]) + (2.0 * (fTemp3 * fRec4[1]))) / fTemp4));
			double fTemp8 = (((fTemp1 * (fRec4[2] + (fRec4[0] + (2.0 * fRec4[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec4[1]) + ((fRec4[0] + fRec4[2]) / fTemp4))))));
			double fTemp9 = (0.010248360499999999 * fTemp8);
			fRec5[0] = (double(input58[i]) - (((fTemp2 * fRec5[2]) + (2.0 * (fTemp3 * fRec5[1]))) / fTemp4));
			double fTemp10 = (((fTemp1 * (fRec5[2] + (fRec5[0] + (2.0 * fRec5[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec5[1]) + ((fRec5[0] + fRec5[2]) / fTemp4))))));
			double fTemp11 = (0.037563724299999997 * fTemp10);
			fRec6[0] = (double(input57[i]) - (((fTemp2 * fRec6[2]) + (2.0 * (fTemp3 * fRec6[1]))) / fTemp4));
			double fTemp12 = (((fTemp1 * (fRec6[2] + (fRec6[0] + (2.0 * fRec6[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec6[1]) + ((fRec6[0] + fRec6[2]) / fTemp4))))));
			fRec7[0] = (double(input55[i]) - (((fTemp2 * fRec7[2]) + (2.0 * (fTemp3 * fRec7[1]))) / fTemp4));
			double fTemp13 = (((fTemp1 * (fRec7[2] + (fRec7[0] + (2.0 * fRec7[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec7[1]) + ((fRec7[0] + fRec7[2]) / fTemp4))))));
			double fTemp14 = (0.0023381298999999999 * fTemp13);
			fRec8[0] = (double(input54[i]) - (((fTemp2 * fRec8[2]) + (2.0 * (fTemp3 * fRec8[1]))) / fTemp4));
			double fTemp15 = (((fTemp1 * (fRec8[2] + (fRec8[0] + (2.0 * fRec8[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec8[1]) + ((fRec8[0] + fRec8[2]) / fTemp4))))));
			double fTemp16 = (0.0156893216 * fTemp15);
			double fTemp17 = (fConst5 * fRec10[1]);
			double fTemp18 = (fConst6 * fRec13[1]);
			double fTemp19 = (fConst8 * fRec16[1]);
			double fTemp20 = (fConst9 * fRec19[1]);
			double fTemp21 = (fConst11 * double(input44[i]));
			double fTemp22 = (fConst12 * fRec22[1]);
			double fTemp23 = (fConst13 * fRec25[1]);
			fRec27[0] = (fTemp21 + (fTemp22 + (fRec27[1] + fTemp23)));
			fRec25[0] = fRec27[0];
			double fRec26 = ((fTemp23 + fTemp22) + fTemp21);
			fRec24[0] = (fRec25[0] + fRec24[1]);
			fRec22[0] = fRec24[0];
			double fRec23 = fRec26;
			fRec21[0] = (fTemp19 + (fTemp20 + (fRec23 + fRec21[1])));
			fRec19[0] = fRec21[0];
			double fRec20 = (fTemp19 + (fRec23 + fTemp20));
			fRec18[0] = (fRec19[0] + fRec18[1]);
			fRec16[0] = fRec18[0];
			double fRec17 = fRec20;
			fRec15[0] = (fTemp17 + (fTemp18 + (fRec17 + fRec15[1])));
			fRec13[0] = fRec15[0];
			double fRec14 = (fTemp17 + (fRec17 + fTemp18));
			fRec12[0] = (fRec13[0] + fRec12[1]);
			fRec10[0] = fRec12[0];
			double fRec11 = fRec14;
			fRec9[0] = (fRec11 - (((fTemp2 * fRec9[2]) + (2.0 * (fTemp3 * fRec9[1]))) / fTemp4));
			double fTemp24 = (((fTemp1 * (fRec9[2] + (fRec9[0] + (2.0 * fRec9[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec9[1]) + ((fRec9[0] + fRec9[2]) / fTemp4))))));
			double fTemp25 = (0.015468411899999999 * fTemp24);
			double fTemp26 = (fConst5 * fRec29[1]);
			double fTemp27 = (fConst6 * fRec32[1]);
			double fTemp28 = (fConst8 * fRec35[1]);
			double fTemp29 = (fConst9 * fRec38[1]);
			double fTemp30 = (fConst11 * double(input43[i]));
			double fTemp31 = (fConst12 * fRec41[1]);
			double fTemp32 = (fConst13 * fRec44[1]);
			fRec46[0] = (fTemp30 + (fTemp31 + (fRec46[1] + fTemp32)));
			fRec44[0] = fRec46[0];
			double fRec45 = ((fTemp32 + fTemp31) + fTemp30);
			fRec43[0] = (fRec44[0] + fRec43[1]);
			fRec41[0] = fRec43[0];
			double fRec42 = fRec45;
			fRec40[0] = (fTemp28 + (fTemp29 + (fRec42 + fRec40[1])));
			fRec38[0] = fRec40[0];
			double fRec39 = (fTemp28 + (fRec42 + fTemp29));
			fRec37[0] = (fRec38[0] + fRec37[1]);
			fRec35[0] = fRec37[0];
			double fRec36 = fRec39;
			fRec34[0] = (fTemp26 + (fTemp27 + (fRec36 + fRec34[1])));
			fRec32[0] = fRec34[0];
			double fRec33 = (fTemp26 + (fRec36 + fTemp27));
			fRec31[0] = (fRec32[0] + fRec31[1]);
			fRec29[0] = fRec31[0];
			double fRec30 = fRec33;
			fRec28[0] = (fRec30 - (((fTemp2 * fRec28[2]) + (2.0 * (fTemp3 * fRec28[1]))) / fTemp4));
			double fTemp33 = (((fTemp1 * (fRec28[2] + (fRec28[0] + (2.0 * fRec28[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec28[1]) + ((fRec28[0] + fRec28[2]) / fTemp4))))));
			double fTemp34 = (0.045623510999999999 * fTemp33);
			double fTemp35 = (fConst5 * fRec48[1]);
			double fTemp36 = (fConst6 * fRec51[1]);
			double fTemp37 = (fConst8 * fRec54[1]);
			double fTemp38 = (fConst9 * fRec57[1]);
			double fTemp39 = (fConst11 * double(input42[i]));
			double fTemp40 = (fConst12 * fRec60[1]);
			double fTemp41 = (fConst13 * fRec63[1]);
			fRec65[0] = (fTemp39 + (fTemp40 + (fRec65[1] + fTemp41)));
			fRec63[0] = fRec65[0];
			double fRec64 = ((fTemp41 + fTemp40) + fTemp39);
			fRec62[0] = (fRec63[0] + fRec62[1]);
			fRec60[0] = fRec62[0];
			double fRec61 = fRec64;
			fRec59[0] = (fTemp37 + (fTemp38 + (fRec61 + fRec59[1])));
			fRec57[0] = fRec59[0];
			double fRec58 = (fTemp37 + (fRec61 + fTemp38));
			fRec56[0] = (fRec57[0] + fRec56[1]);
			fRec54[0] = fRec56[0];
			double fRec55 = fRec58;
			fRec53[0] = (fTemp35 + (fTemp36 + (fRec55 + fRec53[1])));
			fRec51[0] = fRec53[0];
			double fRec52 = (fTemp35 + (fRec55 + fTemp36));
			fRec50[0] = (fRec51[0] + fRec50[1]);
			fRec48[0] = fRec50[0];
			double fRec49 = fRec52;
			fRec47[0] = (fRec49 - (((fTemp2 * fRec47[2]) + (2.0 * (fTemp3 * fRec47[1]))) / fTemp4));
			double fTemp42 = (((fTemp1 * (fRec47[2] + (fRec47[0] + (2.0 * fRec47[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec47[1]) + ((fRec47[0] + fRec47[2]) / fTemp4))))));
			double fTemp43 = (66.222855969999998 * fTemp42);
			double fTemp44 = (fConst5 * fRec67[1]);
			double fTemp45 = (fConst6 * fRec70[1]);
			double fTemp46 = (fConst8 * fRec73[1]);
			double fTemp47 = (fConst9 * fRec76[1]);
			double fTemp48 = (fConst11 * double(input41[i]));
			double fTemp49 = (fConst12 * fRec79[1]);
			double fTemp50 = (fConst13 * fRec82[1]);
			fRec84[0] = (fTemp48 + (fTemp49 + (fRec84[1] + fTemp50)));
			fRec82[0] = fRec84[0];
			double fRec83 = ((fTemp50 + fTemp49) + fTemp48);
			fRec81[0] = (fRec82[0] + fRec81[1]);
			fRec79[0] = fRec81[0];
			double fRec80 = fRec83;
			fRec78[0] = (fTemp46 + (fTemp47 + (fRec80 + fRec78[1])));
			fRec76[0] = fRec78[0];
			double fRec77 = (fTemp46 + (fRec80 + fTemp47));
			fRec75[0] = (fRec76[0] + fRec75[1]);
			fRec73[0] = fRec75[0];
			double fRec74 = fRec77;
			fRec72[0] = (fTemp44 + (fTemp45 + (fRec74 + fRec72[1])));
			fRec70[0] = fRec72[0];
			double fRec71 = (fTemp44 + (fRec74 + fTemp45));
			fRec69[0] = (fRec70[0] + fRec69[1]);
			fRec67[0] = fRec69[0];
			double fRec68 = fRec71;
			fRec66[0] = (fRec68 - (((fTemp2 * fRec66[2]) + (2.0 * (fTemp3 * fRec66[1]))) / fTemp4));
			double fTemp51 = (((fTemp1 * (fRec66[2] + (fRec66[0] + (2.0 * fRec66[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec66[1]) + ((fRec66[0] + fRec66[2]) / fTemp4))))));
			double fTemp52 = (fConst5 * fRec86[1]);
			double fTemp53 = (fConst6 * fRec89[1]);
			double fTemp54 = (fConst8 * fRec92[1]);
			double fTemp55 = (fConst9 * fRec95[1]);
			double fTemp56 = (fConst11 * double(input38[i]));
			double fTemp57 = (fConst12 * fRec98[1]);
			double fTemp58 = (fConst13 * fRec101[1]);
			fRec103[0] = (fTemp56 + (fTemp57 + (fRec103[1] + fTemp58)));
			fRec101[0] = fRec103[0];
			double fRec102 = ((fTemp58 + fTemp57) + fTemp56);
			fRec100[0] = (fRec101[0] + fRec100[1]);
			fRec98[0] = fRec100[0];
			double fRec99 = fRec102;
			fRec97[0] = (fTemp54 + (fTemp55 + (fRec99 + fRec97[1])));
			fRec95[0] = fRec97[0];
			double fRec96 = (fTemp54 + (fRec99 + fTemp55));
			fRec94[0] = (fRec95[0] + fRec94[1]);
			fRec92[0] = fRec94[0];
			double fRec93 = fRec96;
			fRec91[0] = (fTemp52 + (fTemp53 + (fRec93 + fRec91[1])));
			fRec89[0] = fRec91[0];
			double fRec90 = (fTemp52 + (fRec93 + fTemp53));
			fRec88[0] = (fRec89[0] + fRec88[1]);
			fRec86[0] = fRec88[0];
			double fRec87 = fRec90;
			fRec85[0] = (fRec87 - (((fTemp2 * fRec85[2]) + (2.0 * (fTemp3 * fRec85[1]))) / fTemp4));
			double fTemp59 = (((fTemp1 * (fRec85[2] + (fRec85[0] + (2.0 * fRec85[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec85[1]) + ((fRec85[0] + fRec85[2]) / fTemp4))))));
			double fTemp60 = (140.32588910000001 * fTemp59);
			double fTemp61 = (fConst5 * fRec105[1]);
			double fTemp62 = (fConst6 * fRec108[1]);
			double fTemp63 = (fConst8 * fRec111[1]);
			double fTemp64 = (fConst9 * fRec114[1]);
			double fTemp65 = (fConst11 * double(input37[i]));
			double fTemp66 = (fConst12 * fRec117[1]);
			double fTemp67 = (fConst13 * fRec120[1]);
			fRec122[0] = (fTemp65 + (fTemp66 + (fRec122[1] + fTemp67)));
			fRec120[0] = fRec122[0];
			double fRec121 = ((fTemp67 + fTemp66) + fTemp65);
			fRec119[0] = (fRec120[0] + fRec119[1]);
			fRec117[0] = fRec119[0];
			double fRec118 = fRec121;
			fRec116[0] = (fTemp63 + (fTemp64 + (fRec118 + fRec116[1])));
			fRec114[0] = fRec116[0];
			double fRec115 = (fTemp63 + (fRec118 + fTemp64));
			fRec113[0] = (fRec114[0] + fRec113[1]);
			fRec111[0] = fRec113[0];
			double fRec112 = fRec115;
			fRec110[0] = (fTemp61 + (fTemp62 + (fRec112 + fRec110[1])));
			fRec108[0] = fRec110[0];
			double fRec109 = (fTemp61 + (fRec112 + fTemp62));
			fRec107[0] = (fRec108[0] + fRec107[1]);
			fRec105[0] = fRec107[0];
			double fRec106 = fRec109;
			fRec104[0] = (fRec106 - (((fTemp2 * fRec104[2]) + (2.0 * (fTemp3 * fRec104[1]))) / fTemp4));
			double fTemp68 = (((fTemp1 * (fRec104[2] + (fRec104[0] + (2.0 * fRec104[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec104[1]) + ((fRec104[0] + fRec104[2]) / fTemp4))))));
			double fTemp69 = (fConst15 * fRec124[1]);
			double fTemp70 = (fConst17 * fRec127[1]);
			double fTemp71 = (fConst18 * fRec130[1]);
			double fTemp72 = (fConst20 * double(input31[i]));
			double fTemp73 = (fConst21 * fRec133[1]);
			double fTemp74 = (fConst22 * fRec136[1]);
			fRec138[0] = (fTemp72 + (fTemp73 + (fRec138[1] + fTemp74)));
			fRec136[0] = fRec138[0];
			double fRec137 = ((fTemp74 + fTemp73) + fTemp72);
			fRec135[0] = (fRec136[0] + fRec135[1]);
			fRec133[0] = fRec135[0];
			double fRec134 = fRec137;
			fRec132[0] = (fTemp70 + (fTemp71 + (fRec134 + fRec132[1])));
			fRec130[0] = fRec132[0];
			double fRec131 = (fTemp70 + (fRec134 + fTemp71));
			fRec129[0] = (fRec130[0] + fRec129[1]);
			fRec127[0] = fRec129[0];
			double fRec128 = fRec131;
			fRec126[0] = (fTemp69 + (fRec128 + fRec126[1]));
			fRec124[0] = fRec126[0];
			double fRec125 = (fRec128 + fTemp69);
			fRec123[0] = (fRec125 - (((fTemp2 * fRec123[2]) + (2.0 * (fTemp3 * fRec123[1]))) / fTemp4));
			double fTemp75 = (((fTemp1 * (fRec123[2] + (fRec123[0] + (2.0 * fRec123[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec123[1]) + ((fRec123[0] + fRec123[2]) / fTemp4))))));
			double fTemp76 = (fConst15 * fRec140[1]);
			double fTemp77 = (fConst17 * fRec143[1]);
			double fTemp78 = (fConst18 * fRec146[1]);
			double fTemp79 = (fConst20 * double(input30[i]));
			double fTemp80 = (fConst21 * fRec149[1]);
			double fTemp81 = (fConst22 * fRec152[1]);
			fRec154[0] = (fTemp79 + (fTemp80 + (fRec154[1] + fTemp81)));
			fRec152[0] = fRec154[0];
			double fRec153 = ((fTemp81 + fTemp80) + fTemp79);
			fRec151[0] = (fRec152[0] + fRec151[1]);
			fRec149[0] = fRec151[0];
			double fRec150 = fRec153;
			fRec148[0] = (fTemp77 + (fTemp78 + (fRec150 + fRec148[1])));
			fRec146[0] = fRec148[0];
			double fRec147 = (fTemp77 + (fRec150 + fTemp78));
			fRec145[0] = (fRec146[0] + fRec145[1]);
			fRec143[0] = fRec145[0];
			double fRec144 = fRec147;
			fRec142[0] = (fTemp76 + (fRec144 + fRec142[1]));
			fRec140[0] = fRec142[0];
			double fRec141 = (fRec144 + fTemp76);
			fRec139[0] = (fRec141 - (((fTemp2 * fRec139[2]) + (2.0 * (fTemp3 * fRec139[1]))) / fTemp4));
			double fTemp82 = (((fTemp1 * (fRec139[2] + (fRec139[0] + (2.0 * fRec139[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec139[1]) + ((fRec139[0] + fRec139[2]) / fTemp4))))));
			double fTemp83 = (46.492379370000002 * fTemp82);
			double fTemp84 = (fConst15 * fRec156[1]);
			double fTemp85 = (fConst17 * fRec159[1]);
			double fTemp86 = (fConst18 * fRec162[1]);
			double fTemp87 = (fConst20 * double(input29[i]));
			double fTemp88 = (fConst21 * fRec165[1]);
			double fTemp89 = (fConst22 * fRec168[1]);
			fRec170[0] = (fTemp87 + (fTemp88 + (fRec170[1] + fTemp89)));
			fRec168[0] = fRec170[0];
			double fRec169 = ((fTemp89 + fTemp88) + fTemp87);
			fRec167[0] = (fRec168[0] + fRec167[1]);
			fRec165[0] = fRec167[0];
			double fRec166 = fRec169;
			fRec164[0] = (fTemp85 + (fTemp86 + (fRec166 + fRec164[1])));
			fRec162[0] = fRec164[0];
			double fRec163 = (fTemp85 + (fRec166 + fTemp86));
			fRec161[0] = (fRec162[0] + fRec161[1]);
			fRec159[0] = fRec161[0];
			double fRec160 = fRec163;
			fRec158[0] = (fTemp84 + (fRec160 + fRec158[1]));
			fRec156[0] = fRec158[0];
			double fRec157 = (fRec160 + fTemp84);
			fRec155[0] = (fRec157 - (((fTemp2 * fRec155[2]) + (2.0 * (fTemp3 * fRec155[1]))) / fTemp4));
			double fTemp90 = (((fTemp1 * (fRec155[2] + (fRec155[0] + (2.0 * fRec155[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec155[1]) + ((fRec155[0] + fRec155[2]) / fTemp4))))));
			double fTemp91 = (0.0029092989000000001 * fTemp90);
			double fTemp92 = (fConst15 * fRec172[1]);
			double fTemp93 = (fConst17 * fRec175[1]);
			double fTemp94 = (fConst18 * fRec178[1]);
			double fTemp95 = (fConst20 * double(input26[i]));
			double fTemp96 = (fConst21 * fRec181[1]);
			double fTemp97 = (fConst22 * fRec184[1]);
			fRec186[0] = (fTemp95 + (fTemp96 + (fRec186[1] + fTemp97)));
			fRec184[0] = fRec186[0];
			double fRec185 = ((fTemp97 + fTemp96) + fTemp95);
			fRec183[0] = (fRec184[0] + fRec183[1]);
			fRec181[0] = fRec183[0];
			double fRec182 = fRec185;
			fRec180[0] = (fTemp93 + (fTemp94 + (fRec182 + fRec180[1])));
			fRec178[0] = fRec180[0];
			double fRec179 = (fTemp93 + (fRec182 + fTemp94));
			fRec177[0] = (fRec178[0] + fRec177[1]);
			fRec175[0] = fRec177[0];
			double fRec176 = fRec179;
			fRec174[0] = (fTemp92 + (fRec176 + fRec174[1]));
			fRec172[0] = fRec174[0];
			double fRec173 = (fRec176 + fTemp92);
			fRec171[0] = (fRec173 - (((fTemp2 * fRec171[2]) + (2.0 * (fTemp3 * fRec171[1]))) / fTemp4));
			double fTemp98 = (((fTemp1 * (fRec171[2] + (fRec171[0] + (2.0 * fRec171[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec171[1]) + ((fRec171[0] + fRec171[2]) / fTemp4))))));
			double fTemp99 = (81.61519466 * fTemp98);
			double fTemp100 = (fConst24 * fRec188[1]);
			double fTemp101 = (fConst26 * double(input10[i]));
			double fTemp102 = (fConst27 * fRec191[1]);
			double fTemp103 = (fConst28 * fRec194[1]);
			fRec196[0] = (fTemp101 + (fTemp102 + (fRec196[1] + fTemp103)));
			fRec194[0] = fRec196[0];
			double fRec195 = ((fTemp103 + fTemp102) + fTemp101);
			fRec193[0] = (fRec194[0] + fRec193[1]);
			fRec191[0] = fRec193[0];
			double fRec192 = fRec195;
			fRec190[0] = (fTemp100 + (fRec192 + fRec190[1]));
			fRec188[0] = fRec190[0];
			double fRec189 = (fRec192 + fTemp100);
			fRec187[0] = (fRec189 - (((fTemp2 * fRec187[2]) + (2.0 * (fTemp3 * fRec187[1]))) / fTemp4));
			double fTemp104 = (((fTemp1 * (fRec187[2] + (fRec187[0] + (2.0 * fRec187[1])))) / fTemp5) + (0.93701139950000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec187[1]) + ((fRec187[0] + fRec187[2]) / fTemp4))))));
			double fTemp105 = (0.043413802500000001 * fTemp104);
			double fTemp106 = (fConst30 * double(input8[i]));
			double fTemp107 = (fConst31 * fRec198[1]);
			double fTemp108 = (fConst32 * fRec201[1]);
			fRec203[0] = (fTemp106 + (fTemp107 + (fRec203[1] + fTemp108)));
			fRec201[0] = fRec203[0];
			double fRec202 = ((fTemp108 + fTemp107) + fTemp106);
			fRec200[0] = (fRec201[0] + fRec200[1]);
			fRec198[0] = fRec200[0];
			double fRec199 = fRec202;
			fRec197[0] = (fRec199 - (((fTemp2 * fRec197[2]) + (2.0 * (fTemp3 * fRec197[1]))) / fTemp4));
			double fTemp109 = (((fTemp1 * (fRec197[2] + (fRec197[0] + (2.0 * fRec197[1])))) / fTemp5) + (1.0700688140000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec197[1]) + ((fRec197[0] + fRec197[2]) / fTemp4))))));
			double fTemp110 = (0.024715628399999998 * fTemp109);
			double fTemp111 = (fConst30 * double(input7[i]));
			double fTemp112 = (fConst31 * fRec205[1]);
			double fTemp113 = (fConst32 * fRec208[1]);
			fRec210[0] = (fTemp111 + (fTemp112 + (fRec210[1] + fTemp113)));
			fRec208[0] = fRec210[0];
			double fRec209 = ((fTemp113 + fTemp112) + fTemp111);
			fRec207[0] = (fRec208[0] + fRec207[1]);
			fRec205[0] = fRec207[0];
			double fRec206 = fRec209;
			fRec204[0] = (fRec206 - (((fTemp2 * fRec204[2]) + (2.0 * (fTemp3 * fRec204[1]))) / fTemp4));
			double fTemp114 = (((fTemp1 * (fRec204[2] + (fRec204[0] + (2.0 * fRec204[1])))) / fTemp5) + (1.0700688140000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec204[1]) + ((fRec204[0] + fRec204[2]) / fTemp4))))));
			double fTemp115 = (0.00051923400000000004 * fTemp114);
			double fTemp116 = (fConst30 * double(input6[i]));
			double fTemp117 = (fConst31 * fRec212[1]);
			double fTemp118 = (fConst32 * fRec215[1]);
			fRec217[0] = (fTemp116 + (fTemp117 + (fRec217[1] + fTemp118)));
			fRec215[0] = fRec217[0];
			double fRec216 = ((fTemp118 + fTemp117) + fTemp116);
			fRec214[0] = (fRec215[0] + fRec214[1]);
			fRec212[0] = fRec214[0];
			double fRec213 = fRec216;
			fRec211[0] = (fRec213 - (((fTemp2 * fRec211[2]) + (2.0 * (fTemp3 * fRec211[1]))) / fTemp4));
			double fTemp119 = (((fTemp1 * (fRec211[2] + (fRec211[0] + (2.0 * fRec211[1])))) / fTemp5) + (1.0700688140000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec211[1]) + ((fRec211[0] + fRec211[2]) / fTemp4))))));
			double fTemp120 = (25.397094849999998 * fTemp119);
			double fTemp121 = (fConst30 * double(input5[i]));
			double fTemp122 = (fConst31 * fRec219[1]);
			double fTemp123 = (fConst32 * fRec222[1]);
			fRec224[0] = (fTemp121 + (fTemp122 + (fRec224[1] + fTemp123)));
			fRec222[0] = fRec224[0];
			double fRec223 = ((fTemp123 + fTemp122) + fTemp121);
			fRec221[0] = (fRec222[0] + fRec221[1]);
			fRec219[0] = fRec221[0];
			double fRec220 = fRec223;
			fRec218[0] = (fRec220 - (((fTemp2 * fRec218[2]) + (2.0 * (fTemp3 * fRec218[1]))) / fTemp4));
			double fTemp124 = (((fTemp1 * (fRec218[2] + (fRec218[0] + (2.0 * fRec218[1])))) / fTemp5) + (1.0700688140000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec218[1]) + ((fRec218[0] + fRec218[2]) / fTemp4))))));
			double fTemp125 = (fConst34 * double(input1[i]));
			double fTemp126 = (fConst35 * fRec226[1]);
			fRec228[0] = (fTemp125 + (fRec228[1] + fTemp126));
			fRec226[0] = fRec228[0];
			double fRec227 = (fTemp126 + fTemp125);
			fRec225[0] = (fRec227 - (((fTemp2 * fRec225[2]) + (2.0 * (fTemp3 * fRec225[1]))) / fTemp4));
			double fTemp127 = (((fTemp1 * (fRec225[2] + (fRec225[0] + (2.0 * fRec225[1])))) / fTemp5) + (1.163423471 * (fRec3[0] * (0.0 - ((fTemp6 * fRec225[1]) + ((fRec225[0] + fRec225[2]) / fTemp4))))));
			double fTemp128 = (fConst34 * double(input2[i]));
			double fTemp129 = (fConst35 * fRec230[1]);
			fRec232[0] = (fTemp128 + (fRec232[1] + fTemp129));
			fRec230[0] = fRec232[0];
			double fRec231 = (fTemp129 + fTemp128);
			fRec229[0] = (fRec231 - (((fTemp2 * fRec229[2]) + (2.0 * (fTemp3 * fRec229[1]))) / fTemp4));
			double fTemp130 = (((fTemp1 * (fRec229[2] + (fRec229[0] + (2.0 * fRec229[1])))) / fTemp5) + (1.163423471 * (fRec3[0] * (0.0 - ((fTemp6 * fRec229[1]) + ((fRec229[0] + fRec229[2]) / fTemp4))))));
			double fTemp131 = (23.19757177 * fTemp130);
			double fTemp132 = (fConst34 * double(input3[i]));
			double fTemp133 = (fConst35 * fRec234[1]);
			fRec236[0] = (fTemp132 + (fRec236[1] + fTemp133));
			fRec234[0] = fRec236[0];
			double fRec235 = (fTemp133 + fTemp132);
			fRec233[0] = (fRec235 - (((fTemp2 * fRec233[2]) + (2.0 * (fTemp3 * fRec233[1]))) / fTemp4));
			double fTemp134 = (((fTemp1 * (fRec233[2] + (fRec233[0] + (2.0 * fRec233[1])))) / fTemp5) + (1.163423471 * (fRec3[0] * (0.0 - ((fTemp6 * fRec233[1]) + ((fRec233[0] + fRec233[2]) / fTemp4))))));
			double fTemp135 = (0.048182628499999998 * fTemp134);
			double fTemp136 = (fConst30 * double(input4[i]));
			double fTemp137 = (fConst31 * fRec238[1]);
			double fTemp138 = (fConst32 * fRec241[1]);
			fRec243[0] = (fTemp136 + (fTemp137 + (fRec243[1] + fTemp138)));
			fRec241[0] = fRec243[0];
			double fRec242 = ((fTemp138 + fTemp137) + fTemp136);
			fRec240[0] = (fRec241[0] + fRec240[1]);
			fRec238[0] = fRec240[0];
			double fRec239 = fRec242;
			fRec237[0] = (fRec239 - (((fTemp2 * fRec237[2]) + (2.0 * (fTemp3 * fRec237[1]))) / fTemp4));
			double fTemp139 = (((fTemp1 * (fRec237[2] + (fRec237[0] + (2.0 * fRec237[1])))) / fTemp5) + (1.0700688140000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec237[1]) + ((fRec237[0] + fRec237[2]) / fTemp4))))));
			double fTemp140 = (0.071252663399999999 * fTemp139);
			double fTemp141 = (fConst24 * fRec245[1]);
			double fTemp142 = (fConst26 * double(input9[i]));
			double fTemp143 = (fConst27 * fRec248[1]);
			double fTemp144 = (fConst28 * fRec251[1]);
			fRec253[0] = (fTemp142 + (fTemp143 + (fRec253[1] + fTemp144)));
			fRec251[0] = fRec253[0];
			double fRec252 = ((fTemp144 + fTemp143) + fTemp142);
			fRec250[0] = (fRec251[0] + fRec250[1]);
			fRec248[0] = fRec250[0];
			double fRec249 = fRec252;
			fRec247[0] = (fTemp141 + (fRec249 + fRec247[1]));
			fRec245[0] = fRec247[0];
			double fRec246 = (fRec249 + fTemp141);
			fRec244[0] = (fRec246 - (((fTemp2 * fRec244[2]) + (2.0 * (fTemp3 * fRec244[1]))) / fTemp4));
			double fTemp145 = (((fTemp1 * (fRec244[2] + (fRec244[0] + (2.0 * fRec244[1])))) / fTemp5) + (0.93701139950000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec244[1]) + ((fRec244[0] + fRec244[2]) / fTemp4))))));
			double fTemp146 = (fConst37 * fRec255[1]);
			double fTemp147 = (fConst38 * fRec258[1]);
			double fTemp148 = (fConst40 * double(input17[i]));
			double fTemp149 = (fConst41 * fRec261[1]);
			double fTemp150 = (fConst42 * fRec264[1]);
			fRec266[0] = (fTemp148 + (fTemp149 + (fRec266[1] + fTemp150)));
			fRec264[0] = fRec266[0];
			double fRec265 = ((fTemp150 + fTemp149) + fTemp148);
			fRec263[0] = (fRec264[0] + fRec263[1]);
			fRec261[0] = fRec263[0];
			double fRec262 = fRec265;
			fRec260[0] = (fTemp146 + (fTemp147 + (fRec262 + fRec260[1])));
			fRec258[0] = fRec260[0];
			double fRec259 = (fTemp146 + (fRec262 + fTemp147));
			fRec257[0] = (fRec258[0] + fRec257[1]);
			fRec255[0] = fRec257[0];
			double fRec256 = fRec259;
			fRec254[0] = (fRec256 - (((fTemp2 * fRec254[2]) + (2.0 * (fTemp3 * fRec254[1]))) / fTemp4));
			double fTemp151 = (((fTemp1 * (fRec254[2] + (fRec254[0] + (2.0 * fRec254[1])))) / fTemp5) + (0.77210283830000004 * (fRec3[0] * (0.0 - ((fTemp6 * fRec254[1]) + ((fRec254[0] + fRec254[2]) / fTemp4))))));
			double fTemp152 = (fConst15 * fRec268[1]);
			double fTemp153 = (fConst17 * fRec271[1]);
			double fTemp154 = (fConst20 * double(input25[i]));
			double fTemp155 = (fConst21 * fRec277[1]);
			double fTemp156 = (fConst22 * fRec280[1]);
			fRec282[0] = (fTemp154 + (fTemp155 + (fRec282[1] + fTemp156)));
			fRec280[0] = fRec282[0];
			double fRec281 = ((fTemp156 + fTemp155) + fTemp154);
			fRec279[0] = (fRec280[0] + fRec279[1]);
			fRec277[0] = fRec279[0];
			double fRec278 = fRec281;
			double fTemp157 = (fRec278 + (fConst18 * fRec274[1]));
			fRec276[0] = (fTemp153 + (fRec276[1] + fTemp157));
			fRec274[0] = fRec276[0];
			double fRec275 = (fTemp153 + fTemp157);
			fRec273[0] = (fRec274[0] + fRec273[1]);
			fRec271[0] = fRec273[0];
			double fRec272 = fRec275;
			fRec270[0] = (fTemp152 + (fRec272 + fRec270[1]));
			fRec268[0] = fRec270[0];
			double fRec269 = (fRec272 + fTemp152);
			fRec267[0] = (fRec269 - (((fTemp2 * fRec267[2]) + (2.0 * (fTemp3 * fRec267[1]))) / fTemp4));
			double fTemp158 = (((fTemp1 * (fRec267[2] + (fRec267[0] + (2.0 * fRec267[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec267[1]) + ((fRec267[0] + fRec267[2]) / fTemp4))))));
			double fTemp159 = (0.065632599599999994 * fTemp158);
			double fTemp160 = (fConst8 * fRec290[1]);
			double fTemp161 = (fConst9 * fRec293[1]);
			double fTemp162 = (fConst11 * double(input36[i]));
			double fTemp163 = (fConst12 * fRec296[1]);
			double fTemp164 = (fConst13 * fRec299[1]);
			fRec301[0] = (fTemp162 + (fTemp163 + (fRec301[1] + fTemp164)));
			fRec299[0] = fRec301[0];
			double fRec300 = ((fTemp164 + fTemp163) + fTemp162);
			fRec298[0] = (fRec299[0] + fRec298[1]);
			fRec296[0] = fRec298[0];
			double fRec297 = fRec300;
			fRec295[0] = (fTemp160 + (fTemp161 + (fRec297 + fRec295[1])));
			fRec293[0] = fRec295[0];
			double fRec294 = (fTemp160 + (fRec297 + fTemp161));
			fRec292[0] = (fRec293[0] + fRec292[1]);
			fRec290[0] = fRec292[0];
			double fRec291 = fRec294;
			double fTemp165 = ((fConst5 * fRec284[1]) + (fRec291 + (fConst6 * fRec287[1])));
			fRec289[0] = (fRec289[1] + fTemp165);
			fRec287[0] = fRec289[0];
			double fRec288 = fTemp165;
			fRec286[0] = (fRec287[0] + fRec286[1]);
			fRec284[0] = fRec286[0];
			double fRec285 = fRec288;
			fRec283[0] = (fRec285 - (((fTemp2 * fRec283[2]) + (2.0 * (fTemp3 * fRec283[1]))) / fTemp4));
			double fTemp166 = (((fTemp1 * (fRec283[2] + (fRec283[0] + (2.0 * fRec283[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec283[1]) + ((fRec283[0] + fRec283[2]) / fTemp4))))));
			double fTemp167 = (0.0038041129 * fTemp166);
			fRec302[0] = (double(input53[i]) - (((fTemp2 * fRec302[2]) + (2.0 * (fTemp3 * fRec302[1]))) / fTemp4));
			double fTemp168 = (((fTemp1 * (fRec302[2] + (fRec302[0] + (2.0 * fRec302[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec302[1]) + ((fRec302[0] + fRec302[2]) / fTemp4))))));
			double fTemp169 = (0.00037173479999999998 * fTemp168);
			fRec303[0] = (double(input63[i]) - (((fTemp2 * fRec303[2]) + (2.0 * (fTemp3 * fRec303[1]))) / fTemp4));
			double fTemp170 = (((fTemp1 * (fRec303[2] + (fRec303[0] + (2.0 * fRec303[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec303[1]) + ((fRec303[0] + fRec303[2]) / fTemp4))))));
			double fTemp171 = (0.20310094719999999 * fTemp170);
			fRec304[0] = (double(input62[i]) - (((fTemp2 * fRec304[2]) + (2.0 * (fTemp3 * fRec304[1]))) / fTemp4));
			double fTemp172 = (((fTemp1 * (fRec304[2] + (fRec304[0] + (2.0 * fRec304[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec304[1]) + ((fRec304[0] + fRec304[2]) / fTemp4))))));
			double fTemp173 = (0.1020111098 * fTemp172);
			fRec305[0] = (double(input60[i]) - (((fTemp2 * fRec305[2]) + (2.0 * (fTemp3 * fRec305[1]))) / fTemp4));
			double fTemp174 = (((fTemp1 * (fRec305[2] + (fRec305[0] + (2.0 * fRec305[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec305[1]) + ((fRec305[0] + fRec305[2]) / fTemp4))))));
			double fTemp175 = (51.88017799 * fTemp174);
			fRec306[0] = (double(input56[i]) - (((fTemp2 * fRec306[2]) + (2.0 * (fTemp3 * fRec306[1]))) / fTemp4));
			double fTemp176 = (((fTemp1 * (fRec306[2] + (fRec306[0] + (2.0 * fRec306[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec306[1]) + ((fRec306[0] + fRec306[2]) / fTemp4))))));
			double fTemp177 = (62.501232549999997 * fTemp176);
			fRec307[0] = (double(input52[i]) - (((fTemp2 * fRec307[2]) + (2.0 * (fTemp3 * fRec307[1]))) / fTemp4));
			double fTemp178 = (((fTemp1 * (fRec307[2] + (fRec307[0] + (2.0 * fRec307[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec307[1]) + ((fRec307[0] + fRec307[2]) / fTemp4))))));
			double fTemp179 = (122.56985450000001 * fTemp178);
			fRec308[0] = (double(input51[i]) - (((fTemp2 * fRec308[2]) + (2.0 * (fTemp3 * fRec308[1]))) / fTemp4));
			double fTemp180 = (((fTemp1 * (fRec308[2] + (fRec308[0] + (2.0 * fRec308[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec308[1]) + ((fRec308[0] + fRec308[2]) / fTemp4))))));
			double fTemp181 = (0.039247927600000003 * fTemp180);
			fRec309[0] = (double(input50[i]) - (((fTemp2 * fRec309[2]) + (2.0 * (fTemp3 * fRec309[1]))) / fTemp4));
			double fTemp182 = (((fTemp1 * (fRec309[2] + (fRec309[0] + (2.0 * fRec309[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec309[1]) + ((fRec309[0] + fRec309[2]) / fTemp4))))));
			double fTemp183 = (0.0027472950999999999 * fTemp182);
			double fTemp184 = (fConst5 * fRec311[1]);
			double fTemp185 = (fConst6 * fRec314[1]);
			double fTemp186 = (fConst8 * fRec317[1]);
			double fTemp187 = (fConst9 * fRec320[1]);
			double fTemp188 = (fConst11 * double(input48[i]));
			double fTemp189 = (fConst12 * fRec323[1]);
			double fTemp190 = (fConst13 * fRec326[1]);
			fRec328[0] = (fTemp188 + (fTemp189 + (fRec328[1] + fTemp190)));
			fRec326[0] = fRec328[0];
			double fRec327 = ((fTemp190 + fTemp189) + fTemp188);
			fRec325[0] = (fRec326[0] + fRec325[1]);
			fRec323[0] = fRec325[0];
			double fRec324 = fRec327;
			fRec322[0] = (fTemp186 + (fTemp187 + (fRec324 + fRec322[1])));
			fRec320[0] = fRec322[0];
			double fRec321 = (fTemp186 + (fRec324 + fTemp187));
			fRec319[0] = (fRec320[0] + fRec319[1]);
			fRec317[0] = fRec319[0];
			double fRec318 = fRec321;
			fRec316[0] = (fTemp184 + (fTemp185 + (fRec318 + fRec316[1])));
			fRec314[0] = fRec316[0];
			double fRec315 = (fTemp184 + (fRec318 + fTemp185));
			fRec313[0] = (fRec314[0] + fRec313[1]);
			fRec311[0] = fRec313[0];
			double fRec312 = fRec315;
			fRec310[0] = (fRec312 - (((fTemp2 * fRec310[2]) + (2.0 * (fTemp3 * fRec310[1]))) / fTemp4));
			double fTemp191 = (((fTemp1 * (fRec310[2] + (fRec310[0] + (2.0 * fRec310[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec310[1]) + ((fRec310[0] + fRec310[2]) / fTemp4))))));
			double fTemp192 = (0.13509899149999999 * fTemp191);
			double fTemp193 = (fConst5 * fRec330[1]);
			double fTemp194 = (fConst6 * fRec333[1]);
			double fTemp195 = (fConst8 * fRec336[1]);
			double fTemp196 = (fConst9 * fRec339[1]);
			double fTemp197 = (fConst11 * double(input47[i]));
			double fTemp198 = (fConst12 * fRec342[1]);
			double fTemp199 = (fConst13 * fRec345[1]);
			fRec347[0] = (fTemp197 + (fTemp198 + (fRec347[1] + fTemp199)));
			fRec345[0] = fRec347[0];
			double fRec346 = ((fTemp199 + fTemp198) + fTemp197);
			fRec344[0] = (fRec345[0] + fRec344[1]);
			fRec342[0] = fRec344[0];
			double fRec343 = fRec346;
			fRec341[0] = (fTemp195 + (fTemp196 + (fRec343 + fRec341[1])));
			fRec339[0] = fRec341[0];
			double fRec340 = (fTemp195 + (fRec343 + fTemp196));
			fRec338[0] = (fRec339[0] + fRec338[1]);
			fRec336[0] = fRec338[0];
			double fRec337 = fRec340;
			fRec335[0] = (fTemp193 + (fTemp194 + (fRec337 + fRec335[1])));
			fRec333[0] = fRec335[0];
			double fRec334 = (fTemp193 + (fRec337 + fTemp194));
			fRec332[0] = (fRec333[0] + fRec332[1]);
			fRec330[0] = fRec332[0];
			double fRec331 = fRec334;
			fRec329[0] = (fRec331 - (((fTemp2 * fRec329[2]) + (2.0 * (fTemp3 * fRec329[1]))) / fTemp4));
			double fTemp200 = (((fTemp1 * (fRec329[2] + (fRec329[0] + (2.0 * fRec329[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec329[1]) + ((fRec329[0] + fRec329[2]) / fTemp4))))));
			double fTemp201 = (fConst5 * fRec349[1]);
			double fTemp202 = (fConst6 * fRec352[1]);
			double fTemp203 = (fConst8 * fRec355[1]);
			double fTemp204 = (fConst9 * fRec358[1]);
			double fTemp205 = (fConst11 * double(input46[i]));
			double fTemp206 = (fConst12 * fRec361[1]);
			double fTemp207 = (fConst13 * fRec364[1]);
			fRec366[0] = (fTemp205 + (fTemp206 + (fRec366[1] + fTemp207)));
			fRec364[0] = fRec366[0];
			double fRec365 = ((fTemp207 + fTemp206) + fTemp205);
			fRec363[0] = (fRec364[0] + fRec363[1]);
			fRec361[0] = fRec363[0];
			double fRec362 = fRec365;
			fRec360[0] = (fTemp203 + (fTemp204 + (fRec362 + fRec360[1])));
			fRec358[0] = fRec360[0];
			double fRec359 = (fTemp203 + (fRec362 + fTemp204));
			fRec357[0] = (fRec358[0] + fRec357[1]);
			fRec355[0] = fRec357[0];
			double fRec356 = fRec359;
			fRec354[0] = (fTemp201 + (fTemp202 + (fRec356 + fRec354[1])));
			fRec352[0] = fRec354[0];
			double fRec353 = (fTemp201 + (fRec356 + fTemp202));
			fRec351[0] = (fRec352[0] + fRec351[1]);
			fRec349[0] = fRec351[0];
			double fRec350 = fRec353;
			fRec348[0] = (fRec350 - (((fTemp2 * fRec348[2]) + (2.0 * (fTemp3 * fRec348[1]))) / fTemp4));
			double fTemp208 = (((fTemp1 * (fRec348[2] + (fRec348[0] + (2.0 * fRec348[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec348[1]) + ((fRec348[0] + fRec348[2]) / fTemp4))))));
			double fTemp209 = (73.490278709999998 * fTemp208);
			double fTemp210 = (fConst5 * fRec368[1]);
			double fTemp211 = (fConst6 * fRec371[1]);
			double fTemp212 = (fConst8 * fRec374[1]);
			double fTemp213 = (fConst9 * fRec377[1]);
			double fTemp214 = (fConst11 * double(input45[i]));
			double fTemp215 = (fConst12 * fRec380[1]);
			double fTemp216 = (fConst13 * fRec383[1]);
			fRec385[0] = (fTemp214 + (fTemp215 + (fRec385[1] + fTemp216)));
			fRec383[0] = fRec385[0];
			double fRec384 = ((fTemp216 + fTemp215) + fTemp214);
			fRec382[0] = (fRec383[0] + fRec382[1]);
			fRec380[0] = fRec382[0];
			double fRec381 = fRec384;
			fRec379[0] = (fTemp212 + (fTemp213 + (fRec381 + fRec379[1])));
			fRec377[0] = fRec379[0];
			double fRec378 = (fTemp212 + (fRec381 + fTemp213));
			fRec376[0] = (fRec377[0] + fRec376[1]);
			fRec374[0] = fRec376[0];
			double fRec375 = fRec378;
			fRec373[0] = (fTemp210 + (fTemp211 + (fRec375 + fRec373[1])));
			fRec371[0] = fRec373[0];
			double fRec372 = (fTemp210 + (fRec375 + fTemp211));
			fRec370[0] = (fRec371[0] + fRec370[1]);
			fRec368[0] = fRec370[0];
			double fRec369 = fRec372;
			fRec367[0] = (fRec369 - (((fTemp2 * fRec367[2]) + (2.0 * (fTemp3 * fRec367[1]))) / fTemp4));
			double fTemp217 = (((fTemp1 * (fRec367[2] + (fRec367[0] + (2.0 * fRec367[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec367[1]) + ((fRec367[0] + fRec367[2]) / fTemp4))))));
			double fTemp218 = (0.014058451099999999 * fTemp217);
			double fTemp219 = (fConst5 * fRec387[1]);
			double fTemp220 = (fConst6 * fRec390[1]);
			double fTemp221 = (fConst8 * fRec393[1]);
			double fTemp222 = (fConst9 * fRec396[1]);
			double fTemp223 = (fConst11 * double(input40[i]));
			double fTemp224 = (fConst12 * fRec399[1]);
			double fTemp225 = (fConst13 * fRec402[1]);
			fRec404[0] = (fTemp223 + (fTemp224 + (fRec404[1] + fTemp225)));
			fRec402[0] = fRec404[0];
			double fRec403 = ((fTemp225 + fTemp224) + fTemp223);
			fRec401[0] = (fRec402[0] + fRec401[1]);
			fRec399[0] = fRec401[0];
			double fRec400 = fRec403;
			fRec398[0] = (fTemp221 + (fTemp222 + (fRec400 + fRec398[1])));
			fRec396[0] = fRec398[0];
			double fRec397 = (fTemp221 + (fRec400 + fTemp222));
			fRec395[0] = (fRec396[0] + fRec395[1]);
			fRec393[0] = fRec395[0];
			double fRec394 = fRec397;
			fRec392[0] = (fTemp219 + (fTemp220 + (fRec394 + fRec392[1])));
			fRec390[0] = fRec392[0];
			double fRec391 = (fTemp219 + (fRec394 + fTemp220));
			fRec389[0] = (fRec390[0] + fRec389[1]);
			fRec387[0] = fRec389[0];
			double fRec388 = fRec391;
			fRec386[0] = (fRec388 - (((fTemp2 * fRec386[2]) + (2.0 * (fTemp3 * fRec386[1]))) / fTemp4));
			double fTemp226 = (((fTemp1 * (fRec386[2] + (fRec386[0] + (2.0 * fRec386[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec386[1]) + ((fRec386[0] + fRec386[2]) / fTemp4))))));
			double fTemp227 = (0.0094479630999999998 * fTemp226);
			double fTemp228 = (fConst15 * fRec406[1]);
			double fTemp229 = (fConst17 * fRec409[1]);
			double fTemp230 = (fConst18 * fRec412[1]);
			double fTemp231 = (fConst20 * double(input35[i]));
			double fTemp232 = (fConst21 * fRec415[1]);
			double fTemp233 = (fConst22 * fRec418[1]);
			fRec420[0] = (fTemp231 + (fTemp232 + (fRec420[1] + fTemp233)));
			fRec418[0] = fRec420[0];
			double fRec419 = ((fTemp233 + fTemp232) + fTemp231);
			fRec417[0] = (fRec418[0] + fRec417[1]);
			fRec415[0] = fRec417[0];
			double fRec416 = fRec419;
			fRec414[0] = (fTemp229 + (fTemp230 + (fRec416 + fRec414[1])));
			fRec412[0] = fRec414[0];
			double fRec413 = (fTemp229 + (fRec416 + fTemp230));
			fRec411[0] = (fRec412[0] + fRec411[1]);
			fRec409[0] = fRec411[0];
			double fRec410 = fRec413;
			fRec408[0] = (fTemp228 + (fRec410 + fRec408[1]));
			fRec406[0] = fRec408[0];
			double fRec407 = (fRec410 + fTemp228);
			fRec405[0] = (fRec407 - (((fTemp2 * fRec405[2]) + (2.0 * (fTemp3 * fRec405[1]))) / fTemp4));
			double fTemp234 = (((fTemp1 * (fRec405[2] + (fRec405[0] + (2.0 * fRec405[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec405[1]) + ((fRec405[0] + fRec405[2]) / fTemp4))))));
			double fTemp235 = (0.1093362358 * fTemp234);
			double fTemp236 = (fConst17 * fRec425[1]);
			double fTemp237 = (fConst18 * fRec428[1]);
			double fTemp238 = (fConst20 * double(input34[i]));
			double fTemp239 = (fConst21 * fRec431[1]);
			double fTemp240 = (fConst22 * fRec434[1]);
			fRec436[0] = (fTemp238 + (fTemp239 + (fRec436[1] + fTemp240)));
			fRec434[0] = fRec436[0];
			double fRec435 = ((fTemp240 + fTemp239) + fTemp238);
			fRec433[0] = (fRec434[0] + fRec433[1]);
			fRec431[0] = fRec433[0];
			double fRec432 = fRec435;
			fRec430[0] = (fTemp236 + (fTemp237 + (fRec432 + fRec430[1])));
			fRec428[0] = fRec430[0];
			double fRec429 = (fTemp236 + (fRec432 + fTemp237));
			fRec427[0] = (fRec428[0] + fRec427[1]);
			fRec425[0] = fRec427[0];
			double fRec426 = fRec429;
			double fTemp241 = (fRec426 + (fConst15 * fRec422[1]));
			fRec424[0] = (fRec424[1] + fTemp241);
			fRec422[0] = fRec424[0];
			double fRec423 = fTemp241;
			fRec421[0] = (fRec423 - (((fTemp2 * fRec421[2]) + (2.0 * (fTemp3 * fRec421[1]))) / fTemp4));
			double fTemp242 = (((fTemp1 * (fRec421[2] + (fRec421[0] + (2.0 * fRec421[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec421[1]) + ((fRec421[0] + fRec421[2]) / fTemp4))))));
			double fTemp243 = (53.332068020000001 * fTemp242);
			double fTemp244 = (fConst15 * fRec438[1]);
			double fTemp245 = (fConst17 * fRec441[1]);
			double fTemp246 = (fConst18 * fRec444[1]);
			double fTemp247 = (fConst20 * double(input33[i]));
			double fTemp248 = (fConst21 * fRec447[1]);
			double fTemp249 = (fConst22 * fRec450[1]);
			fRec452[0] = (fTemp247 + (fTemp248 + (fRec452[1] + fTemp249)));
			fRec450[0] = fRec452[0];
			double fRec451 = ((fTemp249 + fTemp248) + fTemp247);
			fRec449[0] = (fRec450[0] + fRec449[1]);
			fRec447[0] = fRec449[0];
			double fRec448 = fRec451;
			fRec446[0] = (fTemp245 + (fTemp246 + (fRec448 + fRec446[1])));
			fRec444[0] = fRec446[0];
			double fRec445 = (fTemp245 + (fRec448 + fTemp246));
			fRec443[0] = (fRec444[0] + fRec443[1]);
			fRec441[0] = fRec443[0];
			double fRec442 = fRec445;
			fRec440[0] = (fTemp244 + (fRec442 + fRec440[1]));
			fRec438[0] = fRec440[0];
			double fRec439 = (fRec442 + fTemp244);
			fRec437[0] = (fRec439 - (((fTemp2 * fRec437[2]) + (2.0 * (fTemp3 * fRec437[1]))) / fTemp4));
			double fTemp250 = (((fTemp1 * (fRec437[2] + (fRec437[0] + (2.0 * fRec437[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec437[1]) + ((fRec437[0] + fRec437[2]) / fTemp4))))));
			double fTemp251 = (0.026125421400000001 * fTemp250);
			double fTemp252 = (fConst15 * fRec454[1]);
			double fTemp253 = (fConst17 * fRec457[1]);
			double fTemp254 = (fConst18 * fRec460[1]);
			double fTemp255 = (fConst20 * double(input32[i]));
			double fTemp256 = (fConst21 * fRec463[1]);
			double fTemp257 = (fConst22 * fRec466[1]);
			fRec468[0] = (fTemp255 + (fTemp256 + (fRec468[1] + fTemp257)));
			fRec466[0] = fRec468[0];
			double fRec467 = ((fTemp257 + fTemp256) + fTemp255);
			fRec465[0] = (fRec466[0] + fRec465[1]);
			fRec463[0] = fRec465[0];
			double fRec464 = fRec467;
			fRec462[0] = (fTemp253 + (fTemp254 + (fRec464 + fRec462[1])));
			fRec460[0] = fRec462[0];
			double fRec461 = (fTemp253 + (fRec464 + fTemp254));
			fRec459[0] = (fRec460[0] + fRec459[1]);
			fRec457[0] = fRec459[0];
			double fRec458 = fRec461;
			fRec456[0] = (fTemp252 + (fRec458 + fRec456[1]));
			fRec454[0] = fRec456[0];
			double fRec455 = (fRec458 + fTemp252);
			fRec453[0] = (fRec455 - (((fTemp2 * fRec453[2]) + (2.0 * (fTemp3 * fRec453[1]))) / fTemp4));
			double fTemp258 = (((fTemp1 * (fRec453[2] + (fRec453[0] + (2.0 * fRec453[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec453[1]) + ((fRec453[0] + fRec453[2]) / fTemp4))))));
			double fTemp259 = (0.030058242999999998 * fTemp258);
			double fTemp260 = (fConst15 * fRec470[1]);
			double fTemp261 = (fConst17 * fRec473[1]);
			double fTemp262 = (fConst18 * fRec476[1]);
			double fTemp263 = (fConst20 * double(input28[i]));
			double fTemp264 = (fConst21 * fRec479[1]);
			double fTemp265 = (fConst22 * fRec482[1]);
			fRec484[0] = (fTemp263 + (fTemp264 + (fRec484[1] + fTemp265)));
			fRec482[0] = fRec484[0];
			double fRec483 = ((fTemp265 + fTemp264) + fTemp263);
			fRec481[0] = (fRec482[0] + fRec481[1]);
			fRec479[0] = fRec481[0];
			double fRec480 = fRec483;
			fRec478[0] = (fTemp261 + (fTemp262 + (fRec480 + fRec478[1])));
			fRec476[0] = fRec478[0];
			double fRec477 = (fTemp261 + (fRec480 + fTemp262));
			fRec475[0] = (fRec476[0] + fRec475[1]);
			fRec473[0] = fRec475[0];
			double fRec474 = fRec477;
			fRec472[0] = (fTemp260 + (fRec474 + fRec472[1]));
			fRec470[0] = fRec472[0];
			double fRec471 = (fRec474 + fTemp260);
			fRec469[0] = (fRec471 - (((fTemp2 * fRec469[2]) + (2.0 * (fTemp3 * fRec469[1]))) / fTemp4));
			double fTemp266 = (((fTemp1 * (fRec469[2] + (fRec469[0] + (2.0 * fRec469[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec469[1]) + ((fRec469[0] + fRec469[2]) / fTemp4))))));
			double fTemp267 = (0.040033236600000001 * fTemp266);
			double fTemp268 = (fConst37 * fRec486[1]);
			double fTemp269 = (fConst38 * fRec489[1]);
			double fTemp270 = (fConst40 * double(input24[i]));
			double fTemp271 = (fConst41 * fRec492[1]);
			double fTemp272 = (fConst42 * fRec495[1]);
			fRec497[0] = (fTemp270 + (fTemp271 + (fRec497[1] + fTemp272)));
			fRec495[0] = fRec497[0];
			double fRec496 = ((fTemp272 + fTemp271) + fTemp270);
			fRec494[0] = (fRec495[0] + fRec494[1]);
			fRec492[0] = fRec494[0];
			double fRec493 = fRec496;
			fRec491[0] = (fTemp268 + (fTemp269 + (fRec493 + fRec491[1])));
			fRec489[0] = fRec491[0];
			double fRec490 = (fTemp268 + (fRec493 + fTemp269));
			fRec488[0] = (fRec489[0] + fRec488[1]);
			fRec486[0] = fRec488[0];
			double fRec487 = fRec490;
			fRec485[0] = (fRec487 - (((fTemp2 * fRec485[2]) + (2.0 * (fTemp3 * fRec485[1]))) / fTemp4));
			double fTemp273 = (((fTemp1 * (fRec485[2] + (fRec485[0] + (2.0 * fRec485[1])))) / fTemp5) + (0.77210283830000004 * (fRec3[0] * (0.0 - ((fTemp6 * fRec485[1]) + ((fRec485[0] + fRec485[2]) / fTemp4))))));
			double fTemp274 = (19.992979779999999 * fTemp273);
			double fTemp275 = (fConst37 * fRec499[1]);
			double fTemp276 = (fConst38 * fRec502[1]);
			double fTemp277 = (fConst40 * double(input23[i]));
			double fTemp278 = (fConst41 * fRec505[1]);
			double fTemp279 = (fConst42 * fRec508[1]);
			fRec510[0] = (fTemp277 + (fTemp278 + (fRec510[1] + fTemp279)));
			fRec508[0] = fRec510[0];
			double fRec509 = ((fTemp279 + fTemp278) + fTemp277);
			fRec507[0] = (fRec508[0] + fRec507[1]);
			fRec505[0] = fRec507[0];
			double fRec506 = fRec509;
			fRec504[0] = (fTemp275 + (fTemp276 + (fRec506 + fRec504[1])));
			fRec502[0] = fRec504[0];
			double fRec503 = (fTemp275 + (fRec506 + fTemp276));
			fRec501[0] = (fRec502[0] + fRec501[1]);
			fRec499[0] = fRec501[0];
			double fRec500 = fRec503;
			fRec498[0] = (fRec500 - (((fTemp2 * fRec498[2]) + (2.0 * (fTemp3 * fRec498[1]))) / fTemp4));
			double fTemp280 = (((fTemp1 * (fRec498[2] + (fRec498[0] + (2.0 * fRec498[1])))) / fTemp5) + (0.77210283830000004 * (fRec3[0] * (0.0 - ((fTemp6 * fRec498[1]) + ((fRec498[0] + fRec498[2]) / fTemp4))))));
			double fTemp281 = (fConst37 * fRec512[1]);
			double fTemp282 = (fConst38 * fRec515[1]);
			double fTemp283 = (fConst40 * double(input22[i]));
			double fTemp284 = (fConst41 * fRec518[1]);
			double fTemp285 = (fConst42 * fRec521[1]);
			fRec523[0] = (fTemp283 + (fTemp284 + (fRec523[1] + fTemp285)));
			fRec521[0] = fRec523[0];
			double fRec522 = ((fTemp285 + fTemp284) + fTemp283);
			fRec520[0] = (fRec521[0] + fRec520[1]);
			fRec518[0] = fRec520[0];
			double fRec519 = fRec522;
			fRec517[0] = (fTemp281 + (fTemp282 + (fRec519 + fRec517[1])));
			fRec515[0] = fRec517[0];
			double fRec516 = (fTemp281 + (fRec519 + fTemp282));
			fRec514[0] = (fRec515[0] + fRec514[1]);
			fRec512[0] = fRec514[0];
			double fRec513 = fRec516;
			fRec511[0] = (fRec513 - (((fTemp2 * fRec511[2]) + (2.0 * (fTemp3 * fRec511[1]))) / fTemp4));
			double fTemp286 = (((fTemp1 * (fRec511[2] + (fRec511[0] + (2.0 * fRec511[1])))) / fTemp5) + (0.77210283830000004 * (fRec3[0] * (0.0 - ((fTemp6 * fRec511[1]) + ((fRec511[0] + fRec511[2]) / fTemp4))))));
			double fTemp287 = (0.0406904222 * fTemp286);
			double fTemp288 = (fConst37 * fRec525[1]);
			double fTemp289 = (fConst38 * fRec528[1]);
			double fTemp290 = (fConst40 * double(input21[i]));
			double fTemp291 = (fConst41 * fRec531[1]);
			double fTemp292 = (fConst42 * fRec534[1]);
			fRec536[0] = (fTemp290 + (fTemp291 + (fRec536[1] + fTemp292)));
			fRec534[0] = fRec536[0];
			double fRec535 = ((fTemp292 + fTemp291) + fTemp290);
			fRec533[0] = (fRec534[0] + fRec533[1]);
			fRec531[0] = fRec533[0];
			double fRec532 = fRec535;
			fRec530[0] = (fTemp288 + (fTemp289 + (fRec532 + fRec530[1])));
			fRec528[0] = fRec530[0];
			double fRec529 = (fTemp288 + (fRec532 + fTemp289));
			fRec527[0] = (fRec528[0] + fRec527[1]);
			fRec525[0] = fRec527[0];
			double fRec526 = fRec529;
			fRec524[0] = (fRec526 - (((fTemp2 * fRec524[2]) + (2.0 * (fTemp3 * fRec524[1]))) / fTemp4));
			double fTemp293 = (((fTemp1 * (fRec524[2] + (fRec524[0] + (2.0 * fRec524[1])))) / fTemp5) + (0.77210283830000004 * (fRec3[0] * (0.0 - ((fTemp6 * fRec524[1]) + ((fRec524[0] + fRec524[2]) / fTemp4))))));
			double fTemp294 = (fConst37 * fRec538[1]);
			double fTemp295 = (fConst38 * fRec541[1]);
			double fTemp296 = (fConst40 * double(input20[i]));
			double fTemp297 = (fConst41 * fRec544[1]);
			double fTemp298 = (fConst42 * fRec547[1]);
			fRec549[0] = (fTemp296 + (fTemp297 + (fRec549[1] + fTemp298)));
			fRec547[0] = fRec549[0];
			double fRec548 = ((fTemp298 + fTemp297) + fTemp296);
			fRec546[0] = (fRec547[0] + fRec546[1]);
			fRec544[0] = fRec546[0];
			double fRec545 = fRec548;
			fRec543[0] = (fTemp294 + (fTemp295 + (fRec545 + fRec543[1])));
			fRec541[0] = fRec543[0];
			double fRec542 = (fTemp294 + (fRec545 + fTemp295));
			fRec540[0] = (fRec541[0] + fRec540[1]);
			fRec538[0] = fRec540[0];
			double fRec539 = fRec542;
			fRec537[0] = (fRec539 - (((fTemp2 * fRec537[2]) + (2.0 * (fTemp3 * fRec537[1]))) / fTemp4));
			double fTemp299 = (((fTemp1 * (fRec537[2] + (fRec537[0] + (2.0 * fRec537[1])))) / fTemp5) + (0.77210283830000004 * (fRec3[0] * (0.0 - ((fTemp6 * fRec537[1]) + ((fRec537[0] + fRec537[2]) / fTemp4))))));
			double fTemp300 = (35.579428270000001 * fTemp299);
			double fTemp301 = (fConst37 * fRec551[1]);
			double fTemp302 = (fConst38 * fRec554[1]);
			double fTemp303 = (fConst40 * double(input19[i]));
			double fTemp304 = (fConst41 * fRec557[1]);
			double fTemp305 = (fConst42 * fRec560[1]);
			fRec562[0] = (fTemp303 + (fTemp304 + (fRec562[1] + fTemp305)));
			fRec560[0] = fRec562[0];
			double fRec561 = ((fTemp305 + fTemp304) + fTemp303);
			fRec559[0] = (fRec560[0] + fRec559[1]);
			fRec557[0] = fRec559[0];
			double fRec558 = fRec561;
			fRec556[0] = (fTemp301 + (fTemp302 + (fRec558 + fRec556[1])));
			fRec554[0] = fRec556[0];
			double fRec555 = (fTemp301 + (fRec558 + fTemp302));
			fRec553[0] = (fRec554[0] + fRec553[1]);
			fRec551[0] = fRec553[0];
			double fRec552 = fRec555;
			fRec550[0] = (fRec552 - (((fTemp2 * fRec550[2]) + (2.0 * (fTemp3 * fRec550[1]))) / fTemp4));
			double fTemp306 = (((fTemp1 * (fRec550[2] + (fRec550[0] + (2.0 * fRec550[1])))) / fTemp5) + (0.77210283830000004 * (fRec3[0] * (0.0 - ((fTemp6 * fRec550[1]) + ((fRec550[0] + fRec550[2]) / fTemp4))))));
			double fTemp307 = (fConst37 * fRec564[1]);
			double fTemp308 = (fConst38 * fRec567[1]);
			double fTemp309 = (fConst40 * double(input18[i]));
			double fTemp310 = (fConst41 * fRec570[1]);
			double fTemp311 = (fConst42 * fRec573[1]);
			fRec575[0] = (fTemp309 + (fTemp310 + (fRec575[1] + fTemp311)));
			fRec573[0] = fRec575[0];
			double fRec574 = ((fTemp311 + fTemp310) + fTemp309);
			fRec572[0] = (fRec573[0] + fRec572[1]);
			fRec570[0] = fRec572[0];
			double fRec571 = fRec574;
			fRec569[0] = (fTemp307 + (fTemp308 + (fRec571 + fRec569[1])));
			fRec567[0] = fRec569[0];
			double fRec568 = (fTemp307 + (fRec571 + fTemp308));
			fRec566[0] = (fRec567[0] + fRec566[1]);
			fRec564[0] = fRec566[0];
			double fRec565 = fRec568;
			fRec563[0] = (fRec565 - (((fTemp2 * fRec563[2]) + (2.0 * (fTemp3 * fRec563[1]))) / fTemp4));
			double fTemp312 = (((fTemp1 * (fRec563[2] + (fRec563[0] + (2.0 * fRec563[1])))) / fTemp5) + (0.77210283830000004 * (fRec3[0] * (0.0 - ((fTemp6 * fRec563[1]) + ((fRec563[0] + fRec563[2]) / fTemp4))))));
			double fTemp313 = (0.0190986779 * fTemp312);
			double fTemp314 = (fConst24 * fRec577[1]);
			double fTemp315 = (fConst26 * double(input15[i]));
			double fTemp316 = (fConst27 * fRec580[1]);
			double fTemp317 = (fConst28 * fRec583[1]);
			fRec585[0] = (fTemp315 + (fTemp316 + (fRec585[1] + fTemp317)));
			fRec583[0] = fRec585[0];
			double fRec584 = ((fTemp317 + fTemp316) + fTemp315);
			fRec582[0] = (fRec583[0] + fRec582[1]);
			fRec580[0] = fRec582[0];
			double fRec581 = fRec584;
			fRec579[0] = (fTemp314 + (fRec581 + fRec579[1]));
			fRec577[0] = fRec579[0];
			double fRec578 = (fRec581 + fTemp314);
			fRec576[0] = (fRec578 - (((fTemp2 * fRec576[2]) + (2.0 * (fTemp3 * fRec576[1]))) / fTemp4));
			double fTemp318 = (((fTemp1 * (fRec576[2] + (fRec576[0] + (2.0 * fRec576[1])))) / fTemp5) + (0.93701139950000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec576[1]) + ((fRec576[0] + fRec576[2]) / fTemp4))))));
			double fTemp319 = (fConst24 * fRec587[1]);
			double fTemp320 = (fConst26 * double(input14[i]));
			double fTemp321 = (fConst27 * fRec590[1]);
			double fTemp322 = (fConst28 * fRec593[1]);
			fRec595[0] = (fTemp320 + (fTemp321 + (fRec595[1] + fTemp322)));
			fRec593[0] = fRec595[0];
			double fRec594 = ((fTemp322 + fTemp321) + fTemp320);
			fRec592[0] = (fRec593[0] + fRec592[1]);
			fRec590[0] = fRec592[0];
			double fRec591 = fRec594;
			fRec589[0] = (fTemp319 + (fRec591 + fRec589[1]));
			fRec587[0] = fRec589[0];
			double fRec588 = (fRec591 + fTemp319);
			fRec586[0] = (fRec588 - (((fTemp2 * fRec586[2]) + (2.0 * (fTemp3 * fRec586[1]))) / fTemp4));
			double fTemp323 = (((fTemp1 * (fRec586[2] + (fRec586[0] + (2.0 * fRec586[1])))) / fTemp5) + (0.93701139950000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec586[1]) + ((fRec586[0] + fRec586[2]) / fTemp4))))));
			double fTemp324 = (0.0056840729 * fTemp323);
			double fTemp325 = (fConst24 * fRec597[1]);
			double fTemp326 = (fConst26 * double(input13[i]));
			double fTemp327 = (fConst27 * fRec600[1]);
			double fTemp328 = (fConst28 * fRec603[1]);
			fRec605[0] = (fTemp326 + (fTemp327 + (fRec605[1] + fTemp328)));
			fRec603[0] = fRec605[0];
			double fRec604 = ((fTemp328 + fTemp327) + fTemp326);
			fRec602[0] = (fRec603[0] + fRec602[1]);
			fRec600[0] = fRec602[0];
			double fRec601 = fRec604;
			fRec599[0] = (fTemp325 + (fRec601 + fRec599[1]));
			fRec597[0] = fRec599[0];
			double fRec598 = (fRec601 + fTemp325);
			fRec596[0] = (fRec598 - (((fTemp2 * fRec596[2]) + (2.0 * (fTemp3 * fRec596[1]))) / fTemp4));
			double fTemp329 = (((fTemp1 * (fRec596[2] + (fRec596[0] + (2.0 * fRec596[1])))) / fTemp5) + (0.93701139950000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec596[1]) + ((fRec596[0] + fRec596[2]) / fTemp4))))));
			double fTemp330 = (0.049169337299999998 * fTemp329);
			double fTemp331 = (fConst24 * fRec607[1]);
			double fTemp332 = (fConst26 * double(input12[i]));
			double fTemp333 = (fConst27 * fRec610[1]);
			double fTemp334 = (fConst28 * fRec613[1]);
			fRec615[0] = (fTemp332 + (fTemp333 + (fRec615[1] + fTemp334)));
			fRec613[0] = fRec615[0];
			double fRec614 = ((fTemp334 + fTemp333) + fTemp332);
			fRec612[0] = (fRec613[0] + fRec612[1]);
			fRec610[0] = fRec612[0];
			double fRec611 = fRec614;
			fRec609[0] = (fTemp331 + (fRec611 + fRec609[1]));
			fRec607[0] = fRec609[0];
			double fRec608 = (fRec611 + fTemp331);
			fRec606[0] = (fRec608 - (((fTemp2 * fRec606[2]) + (2.0 * (fTemp3 * fRec606[1]))) / fTemp4));
			double fTemp335 = (((fTemp1 * (fRec606[2] + (fRec606[0] + (2.0 * fRec606[1])))) / fTemp5) + (0.93701139950000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec606[1]) + ((fRec606[0] + fRec606[2]) / fTemp4))))));
			double fTemp336 = (33.185239090000003 * fTemp335);
			fRec616[0] = (double(input0[i]) - (((fRec616[2] * fTemp2) + (2.0 * (fRec616[1] * fTemp3))) / fTemp4));
			double fTemp337 = (((fTemp1 * (fRec616[2] + (fRec616[0] + (2.0 * fRec616[1])))) / fTemp5) + (1.2115336459999999 * (fRec3[0] * (0.0 - ((fRec616[1] * fTemp6) + ((fRec616[0] + fRec616[2]) / fTemp4))))));
			double fTemp338 = (30.04400205 * fTemp337);
			double fTemp339 = (fConst24 * fRec618[1]);
			double fTemp340 = (fConst26 * double(input11[i]));
			double fTemp341 = (fConst27 * fRec621[1]);
			double fTemp342 = (fConst28 * fRec624[1]);
			fRec626[0] = (fTemp340 + (fTemp341 + (fRec626[1] + fTemp342)));
			fRec624[0] = fRec626[0];
			double fRec625 = ((fTemp342 + fTemp341) + fTemp340);
			fRec623[0] = (fRec624[0] + fRec623[1]);
			fRec621[0] = fRec623[0];
			double fRec622 = fRec625;
			fRec620[0] = (fTemp339 + (fRec622 + fRec620[1]));
			fRec618[0] = fRec620[0];
			double fRec619 = (fRec622 + fTemp339);
			fRec617[0] = (fRec619 - (((fTemp2 * fRec617[2]) + (2.0 * (fTemp3 * fRec617[1]))) / fTemp4));
			double fTemp343 = (((fTemp1 * (fRec617[2] + (fRec617[0] + (2.0 * fRec617[1])))) / fTemp5) + (0.93701139950000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec617[1]) + ((fRec617[0] + fRec617[2]) / fTemp4))))));
			double fTemp344 = (fConst37 * fRec628[1]);
			double fTemp345 = (fConst40 * double(input16[i]));
			double fTemp346 = (fConst41 * fRec634[1]);
			double fTemp347 = (fConst42 * fRec637[1]);
			fRec639[0] = (fTemp345 + (fTemp346 + (fRec639[1] + fTemp347)));
			fRec637[0] = fRec639[0];
			double fRec638 = ((fTemp347 + fTemp346) + fTemp345);
			fRec636[0] = (fRec637[0] + fRec636[1]);
			fRec634[0] = fRec636[0];
			double fRec635 = fRec638;
			double fTemp348 = (fRec635 + (fConst38 * fRec631[1]));
			fRec633[0] = (fTemp344 + (fRec633[1] + fTemp348));
			fRec631[0] = fRec633[0];
			double fRec632 = (fTemp344 + fTemp348);
			fRec630[0] = (fRec631[0] + fRec630[1]);
			fRec628[0] = fRec630[0];
			double fRec629 = fRec632;
			fRec627[0] = (fRec629 - (((fTemp2 * fRec627[2]) + (2.0 * (fTemp3 * fRec627[1]))) / fTemp4));
			double fTemp349 = (((fTemp1 * (fRec627[2] + (fRec627[0] + (2.0 * fRec627[1])))) / fTemp5) + (0.77210283830000004 * (fRec3[0] * (0.0 - ((fTemp6 * fRec627[1]) + ((fRec627[0] + fRec627[2]) / fTemp4))))));
			double fTemp350 = (98.745397580000002 * fTemp349);
			double fTemp351 = (fConst15 * fRec641[1]);
			double fTemp352 = (fConst17 * fRec644[1]);
			double fTemp353 = (fConst18 * fRec647[1]);
			double fTemp354 = (fConst20 * double(input27[i]));
			double fTemp355 = (fConst21 * fRec650[1]);
			double fTemp356 = (fConst22 * fRec653[1]);
			fRec655[0] = (fTemp354 + (fTemp355 + (fRec655[1] + fTemp356)));
			fRec653[0] = fRec655[0];
			double fRec654 = ((fTemp356 + fTemp355) + fTemp354);
			fRec652[0] = (fRec653[0] + fRec652[1]);
			fRec650[0] = fRec652[0];
			double fRec651 = fRec654;
			fRec649[0] = (fTemp352 + (fTemp353 + (fRec651 + fRec649[1])));
			fRec647[0] = fRec649[0];
			double fRec648 = (fTemp352 + (fRec651 + fTemp353));
			fRec646[0] = (fRec647[0] + fRec646[1]);
			fRec644[0] = fRec646[0];
			double fRec645 = fRec648;
			fRec643[0] = (fTemp351 + (fRec645 + fRec643[1]));
			fRec641[0] = fRec643[0];
			double fRec642 = (fRec645 + fTemp351);
			fRec640[0] = (fRec642 - (((fTemp2 * fRec640[2]) + (2.0 * (fTemp3 * fRec640[1]))) / fTemp4));
			double fTemp357 = (((fTemp1 * (fRec640[2] + (fRec640[0] + (2.0 * fRec640[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec640[1]) + ((fRec640[0] + fRec640[2]) / fTemp4))))));
			double fTemp358 = (0.038796093199999999 * fTemp357);
			double fTemp359 = (fConst5 * fRec657[1]);
			double fTemp360 = (fConst6 * fRec660[1]);
			double fTemp361 = (fConst8 * fRec663[1]);
			double fTemp362 = (fConst9 * fRec666[1]);
			double fTemp363 = (fConst11 * double(input39[i]));
			double fTemp364 = (fConst12 * fRec669[1]);
			double fTemp365 = (fConst13 * fRec672[1]);
			fRec674[0] = (fTemp363 + (fTemp364 + (fRec674[1] + fTemp365)));
			fRec672[0] = fRec674[0];
			double fRec673 = ((fTemp365 + fTemp364) + fTemp363);
			fRec671[0] = (fRec672[0] + fRec671[1]);
			fRec669[0] = fRec671[0];
			double fRec670 = fRec673;
			fRec668[0] = (fTemp361 + (fTemp362 + (fRec670 + fRec668[1])));
			fRec666[0] = fRec668[0];
			double fRec667 = (fTemp361 + (fRec670 + fTemp362));
			fRec665[0] = (fRec666[0] + fRec665[1]);
			fRec663[0] = fRec665[0];
			double fRec664 = fRec667;
			fRec662[0] = (fTemp359 + (fTemp360 + (fRec664 + fRec662[1])));
			fRec660[0] = fRec662[0];
			double fRec661 = (fTemp359 + (fRec664 + fTemp360));
			fRec659[0] = (fRec660[0] + fRec659[1]);
			fRec657[0] = fRec659[0];
			double fRec658 = fRec661;
			fRec656[0] = (fRec658 - (((fTemp2 * fRec656[2]) + (2.0 * (fTemp3 * fRec656[1]))) / fTemp4));
			double fTemp366 = (((fTemp1 * (fRec656[2] + (fRec656[0] + (2.0 * fRec656[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec656[1]) + ((fRec656[0] + fRec656[2]) / fTemp4))))));
			double fTemp367 = (0.061640906600000003 * fTemp366);
			fRec675[0] = (double(input49[i]) - (((fTemp2 * fRec675[2]) + (2.0 * (fTemp3 * fRec675[1]))) / fTemp4));
			double fTemp368 = (((fTemp1 * (fRec675[2] + (fRec675[0] + (2.0 * fRec675[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec675[1]) + ((fRec675[0] + fRec675[2]) / fTemp4))))));
			double fTemp369 = (0.114890667 * fTemp368);
			fVec0[(IOTA & 127)] = (((0.030675982300000001 * fTemp7) + (fTemp9 + (fTemp11 + ((0.00076638420000000001 * fTemp12) + (fTemp14 + (fTemp16 + ((fTemp25 + (fTemp34 + (fTemp43 + ((0.013620024999999999 * fTemp51) + (fTemp60 + ((0.038027969199999997 * fTemp68) + (((0.027613645199999998 * fTemp75) + (fTemp83 + (fTemp91 + (fTemp99 + (((fTemp105 + ((fTemp110 + (fTemp115 + (fTemp120 + ((0.016573616699999998 * fTemp124) + ((((0.0364657351 * fTemp127) + fTemp131) + fTemp135) + fTemp140))))) + (0.088448560400000001 * fTemp145))) + (0.049250909900000001 * fTemp151)) + fTemp159))))) + fTemp167))))))) + fTemp169))))))) - (fTemp171 + (fTemp173 + (fTemp175 + (fTemp177 + (fTemp179 + (fTemp181 + (fTemp183 + ((fTemp192 + ((0.079567520099999997 * fTemp200) + (fTemp209 + (fTemp218 + (fTemp227 + ((fTemp235 + (fTemp243 + (fTemp251 + (fTemp259 + (fTemp267 + ((fTemp274 + ((0.019101968099999998 * fTemp280) + (fTemp287 + ((0.031174372799999999 * fTemp293) + (fTemp300 + ((0.016747739399999999 * fTemp306) + (fTemp313 + (((0.0057958719000000001 * fTemp318) + (fTemp324 + (fTemp330 + (fTemp336 + (fTemp338 + (0.0134504967 * fTemp343)))))) + fTemp350)))))))) + fTemp358)))))) + fTemp367)))))) + fTemp369)))))))));
			output0[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec0[((IOTA - iConst43) & 127)])));
			double fTemp370 = (0.1436434855 * fTemp170);
			double fTemp371 = (0.071969357299999995 * fTemp172);
			double fTemp372 = (51.772145510000001 * fTemp174);
			double fTemp373 = (0.0119548717 * fTemp8);
			double fTemp374 = (0.055034671200000003 * fTemp10);
			double fTemp375 = (62.360611169999999 * fTemp176);
			double fTemp376 = (0.0029113803 * fTemp13);
			double fTemp377 = (0.034080690800000001 * fTemp15);
			double fTemp378 = (0.013106275400000001 * fTemp168);
			double fTemp379 = (122.2866709 * fTemp178);
			double fTemp380 = (0.065803931600000004 * fTemp182);
			double fTemp381 = (0.18341458090000001 * fTemp368);
			double fTemp382 = (0.096859278800000004 * fTemp191);
			double fTemp383 = (0.067753557699999994 * fTemp200);
			double fTemp384 = (73.359389559999997 * fTemp208);
			double fTemp385 = (0.017741871999999999 * fTemp24);
			double fTemp386 = (0.056905669399999997 * fTemp33);
			double fTemp387 = (0.017436168299999999 * fTemp226);
			double fTemp388 = (0.041366283099999998 * fTemp68);
			double fTemp389 = (0.099084466900000001 * fTemp166);
			double fTemp390 = (0.1021567571 * fTemp234);
			double fTemp391 = (53.268442790000002 * fTemp242);
			double fTemp392 = (0.036523046500000003 * fTemp75);
			double fTemp393 = (0.023122649299999999 * fTemp90);
			double fTemp394 = (0.078955882599999999 * fTemp158);
			double fTemp395 = (19.99554118 * fTemp273);
			double fTemp396 = (0.0327449842 * fTemp280);
			double fTemp397 = (35.584767720000002 * fTemp299);
			double fTemp398 = (98.722814360000001 * fTemp349);
			double fTemp399 = (0.078561382200000002 * fTemp318);
			double fTemp400 = (0.011006451800000001 * fTemp323);
			double fTemp401 = (33.11979556 * fTemp335);
			double fTemp402 = (0.024996654699999999 * fTemp145);
			double fTemp403 = (0.059252749200000003 * fTemp109);
			double fTemp404 = (0.051626846300000001 * fTemp134);
			double fTemp405 = (30.052390719999998 * fTemp337);
			double fTemp406 = (6.1811199999999995e-05 * fTemp139);
			double fTemp407 = (0.00050495749999999995 * fTemp12);
			double fTemp408 = (0.056458576400000002 * fTemp180);
			double fTemp409 = (0.064825714399999998 * fTemp217);
			double fTemp410 = (66.137755929999997 * fTemp42);
			double fTemp411 = (0.042790446699999998 * fTemp366);
			double fTemp412 = (140.18901 * fTemp59);
			double fTemp413 = (0.0536057084 * fTemp250);
			double fTemp414 = (0.051079064 * fTemp258);
			double fTemp415 = (46.367642750000002 * fTemp82);
			double fTemp416 = (0.026150739400000001 * fTemp266);
			double fTemp417 = (0.050559997600000003 * fTemp357);
			double fTemp418 = (81.431509680000005 * fTemp98);
			double fTemp419 = (0.056541131500000001 * fTemp286);
			double fTemp420 = (0.036740197199999998 * fTemp293);
			double fTemp421 = (0.047149307500000001 * fTemp312);
			double fTemp422 = (0.063012542000000005 * fTemp329);
			double fTemp423 = (0.013879208699999999 * fTemp343);
			double fTemp424 = (0.027896699300000001 * fTemp104);
			double fTemp425 = (0.0064153945000000002 * fTemp114);
			double fTemp426 = (25.426095310000001 * fTemp119);
			double fTemp427 = (23.186071179999999 * fTemp130);
			fVec1[(IOTA & 127)] = ((fTemp370 + (fTemp371 + (fTemp372 + (fTemp373 + (fTemp374 + (fTemp375 + (fTemp376 + (fTemp377 + (fTemp378 + (fTemp379 + (fTemp380 + (fTemp381 + (fTemp382 + (fTemp383 + (fTemp384 + (fTemp385 + (fTemp386 + ((0.024040066999999998 * fTemp51) + (fTemp387 + (fTemp388 + (fTemp389 + (fTemp390 + (fTemp391 + (fTemp392 + (fTemp393 + (fTemp394 + (fTemp395 + (fTemp396 + (fTemp397 + ((0.0022958853999999998 * fTemp306) + (fTemp398 + (fTemp399 + (fTemp400 + (fTemp401 + (fTemp402 + (fTemp403 + ((fTemp404 + (fTemp405 + (0.00058322720000000003 * fTemp127))) + fTemp406))))))))))))))))))))))))))))))))))))) - ((0.042667694300000003 * fTemp7) + (fTemp407 + (fTemp408 + (fTemp409 + (fTemp410 + (fTemp411 + (fTemp412 + (fTemp413 + (fTemp414 + (fTemp415 + (fTemp416 + (fTemp417 + (fTemp418 + (fTemp419 + (fTemp420 + (fTemp421 + ((0.0079693786000000003 * fTemp151) + (fTemp422 + (fTemp423 + (fTemp424 + (fTemp425 + (fTemp426 + (fTemp427 + (0.0106037332 * fTemp124)))))))))))))))))))))))));
			output1[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec1[((IOTA - iConst44) & 127)])));
			double fTemp428 = (0.0026682247000000001 * fTemp172);
			double fTemp429 = (0.0077637534000000001 * fTemp7);
			double fTemp430 = (0.023364603899999999 * fTemp10);
			double fTemp431 = (0.00050323410000000001 * fTemp13);
			double fTemp432 = (0.048792926299999997 * fTemp180);
			double fTemp433 = (0.029737467199999999 * fTemp200);
			double fTemp434 = (0.0363575592 * fTemp33);
			double fTemp435 = (65.90225658 * fTemp42);
			double fTemp436 = (0.051578467400000001 * fTemp366);
			double fTemp437 = (139.69935380000001 * fTemp59);
			double fTemp438 = (0.0304130037 * fTemp234);
			double fTemp439 = (0.014556871399999999 * fTemp75);
			double fTemp440 = (46.26759534 * fTemp82);
			double fTemp441 = (0.029145299900000001 * fTemp266);
			double fTemp442 = (81.115689829999994 * fTemp98);
			double fTemp443 = (0.067999887499999995 * fTemp318);
			double fTemp444 = (0.046580827800000002 * fTemp323);
			double fTemp445 = (0.072225722699999995 * fTemp109);
			double fTemp446 = (0.0068898922 * fTemp114);
			double fTemp447 = (25.264148500000001 * fTemp119);
			double fTemp448 = (23.077517749999998 * fTemp130);
			double fTemp449 = (0.058401310300000002 * fTemp134);
			double fTemp450 = (0.0054526176999999997 * fTemp104);
			double fTemp451 = (0.040191268400000001 * fTemp312);
			double fTemp452 = (0.0621695544 * fTemp170);
			double fTemp453 = (51.67759993 * fTemp174);
			double fTemp454 = (0.0024697122999999999 * fTemp8);
			double fTemp455 = (62.184679340000002 * fTemp176);
			double fTemp456 = (0.038795304799999999 * fTemp15);
			double fTemp457 = (0.012466269699999999 * fTemp168);
			double fTemp458 = (121.84139140000001 * fTemp178);
			double fTemp459 = (0.1012919704 * fTemp182);
			double fTemp460 = (0.22368093150000001 * fTemp368);
			double fTemp461 = (0.0039644105000000004 * fTemp191);
			double fTemp462 = (73.141051309999995 * fTemp208);
			double fTemp463 = (0.032097805799999997 * fTemp217);
			double fTemp464 = (0.0019027527 * fTemp24);
			double fTemp465 = (0.0166922537 * fTemp226);
			double fTemp466 = (0.082825697000000004 * fTemp68);
			double fTemp467 = (0.1346147208 * fTemp166);
			double fTemp468 = (52.996124530000003 * fTemp242);
			double fTemp469 = (0.032846847899999997 * fTemp258);
			double fTemp470 = (0.018586752500000001 * fTemp90);
			double fTemp471 = (0.1231636554 * fTemp158);
			double fTemp472 = (19.798255709999999 * fTemp273);
			double fTemp473 = (0.0134296322 * fTemp286);
			double fTemp474 = (35.402988829999998 * fTemp299);
			double fTemp475 = (98.414694519999998 * fTemp349);
			double fTemp476 = (0.052833860099999998 * fTemp329);
			double fTemp477 = (33.026136319999999 * fTemp335);
			double fTemp478 = (0.024835428900000001 * fTemp139);
			double fTemp479 = (29.89771369 * fTemp337);
			fVec2[(IOTA & 127)] = ((fTemp428 + (fTemp429 + (fTemp430 + (fTemp431 + (fTemp432 + (fTemp433 + (fTemp434 + (fTemp435 + (fTemp436 + (fTemp437 + (fTemp438 + (fTemp439 + (fTemp440 + (fTemp441 + ((0.045501592600000001 * fTemp357) + (fTemp442 + ((0.049175667800000003 * fTemp280) + ((0.0090228289999999996 * fTemp306) + ((fTemp443 + (fTemp444 + ((0.024295898600000001 * fTemp343) + ((fTemp445 + (fTemp446 + (fTemp447 + ((fTemp448 + fTemp449) + (0.0107713898 * fTemp124))))) + fTemp450)))) + fTemp451))))))))))))))))))) - (fTemp452 + (fTemp453 + (fTemp454 + ((0.0030235434000000002 * fTemp12) + (fTemp455 + (fTemp456 + (fTemp457 + (fTemp458 + (fTemp459 + (fTemp460 + (fTemp461 + (fTemp462 + (fTemp463 + (fTemp464 + ((0.023497357199999999 * fTemp51) + (fTemp465 + (fTemp466 + (fTemp467 + (fTemp468 + ((0.0087253606000000008 * fTemp250) + (fTemp469 + (fTemp470 + (fTemp471 + (fTemp472 + (fTemp473 + ((0.042804429800000002 * fTemp293) + (fTemp474 + ((0.022119309899999998 * fTemp151) + (fTemp475 + (fTemp476 + (fTemp477 + ((0.059712700700000003 * fTemp145) + (fTemp478 + (fTemp479 + (0.0085247403999999995 * fTemp127))))))))))))))))))))))))))))))))))));
			output2[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec2[((IOTA - iConst44) & 127)])));
			double fTemp480 = (51.78071654 * fTemp174);
			double fTemp481 = (0.0062558869999999999 * fTemp8);
			double fTemp482 = (0.043346762099999998 * fTemp10);
			double fTemp483 = (62.222730589999998 * fTemp176);
			double fTemp484 = (122.09883809999999 * fTemp178);
			double fTemp485 = (0.072037087099999994 * fTemp182);
			double fTemp486 = (0.2307684321 * fTemp368);
			double fTemp487 = (73.262321439999994 * fTemp208);
			double fTemp488 = (0.018486106200000001 * fTemp217);
			double fTemp489 = (0.0268134025 * fTemp24);
			double fTemp490 = (0.0493748855 * fTemp33);
			double fTemp491 = (0.075231391999999994 * fTemp366);
			double fTemp492 = (0.096118614699999994 * fTemp166);
			double fTemp493 = (53.053180619999999 * fTemp242);
			double fTemp494 = (0.0035908088999999999 * fTemp250);
			double fTemp495 = (0.032194949700000003 * fTemp75);
			double fTemp496 = (0.050611289699999999 * fTemp266);
			double fTemp497 = (0.015947550099999999 * fTemp158);
			double fTemp498 = (19.794032130000002 * fTemp273);
			double fTemp499 = (35.50499421 * fTemp299);
			double fTemp500 = (0.056104905500000003 * fTemp312);
			double fTemp501 = (98.417783420000006 * fTemp349);
			double fTemp502 = (33.043982440000001 * fTemp335);
			double fTemp503 = (29.984370779999999 * fTemp337);
			double fTemp504 = (0.034939071600000003 * fTemp134);
			double fTemp505 = (0.001189905 * fTemp109);
			double fTemp506 = (0.028376518399999998 * fTemp343);
			double fTemp507 = (0.028358727300000001 * fTemp170);
			double fTemp508 = (0.066134938899999995 * fTemp172);
			double fTemp509 = (0.0017269582000000001 * fTemp13);
			double fTemp510 = (0.055781562799999997 * fTemp15);
			double fTemp511 = (0.098843145499999993 * fTemp191);
			double fTemp512 = (0.0768508792 * fTemp200);
			double fTemp513 = (65.987340990000007 * fTemp42);
			double fTemp514 = (0.018326975200000001 * fTemp226);
			double fTemp515 = (139.81227580000001 * fTemp59);
			double fTemp516 = (0.12789377909999999 * fTemp234);
			double fTemp517 = (0.015900518900000001 * fTemp258);
			double fTemp518 = (46.262111760000003 * fTemp82);
			double fTemp519 = (0.0156762714 * fTemp90);
			double fTemp520 = (81.286366409999999 * fTemp98);
			double fTemp521 = (0.027650067399999999 * fTemp280);
			double fTemp522 = (0.038177482399999997 * fTemp286);
			double fTemp523 = (0.035931979500000003 * fTemp293);
			double fTemp524 = (0.036914365900000003 * fTemp318);
			double fTemp525 = (0.022899525300000001 * fTemp323);
			double fTemp526 = (0.064709982799999996 * fTemp329);
			double fTemp527 = (0.0114025564 * fTemp104);
			double fTemp528 = (0.073780409800000002 * fTemp145);
			double fTemp529 = (25.37112617 * fTemp119);
			double fTemp530 = (23.135499110000001 * fTemp130);
			double fTemp531 = (0.059511944800000001 * fTemp139);
			fVec3[(IOTA & 127)] = (((0.070515001600000002 * fTemp7) + (fTemp480 + (fTemp481 + (fTemp482 + (fTemp483 + (fTemp484 + ((0.0090952410000000004 * fTemp180) + (fTemp485 + (fTemp486 + (fTemp487 + (fTemp488 + (fTemp489 + (fTemp490 + (fTemp491 + ((0.017993115099999998 * fTemp68) + (fTemp492 + (fTemp493 + (fTemp494 + (fTemp495 + (fTemp496 + ((0.073348031800000005 * fTemp357) + (fTemp497 + (fTemp498 + (fTemp499 + ((0.020529494700000001 * fTemp306) + (fTemp500 + (fTemp501 + (fTemp502 + (((fTemp503 + fTemp504) + fTemp505) + fTemp506))))))))))))))))))))))))))))) - (fTemp507 + (fTemp508 + ((0.0047909262999999997 * fTemp12) + (fTemp509 + (fTemp510 + ((0.019989118899999998 * fTemp168) + (fTemp511 + (fTemp512 + (fTemp513 + ((0.028262194500000001 * fTemp51) + (fTemp514 + (fTemp515 + (fTemp516 + (fTemp517 + (fTemp518 + (fTemp519 + (fTemp520 + (fTemp521 + (fTemp522 + (fTemp523 + ((0.017992755900000001 * fTemp151) + (fTemp524 + (fTemp525 + (fTemp526 + (fTemp527 + (fTemp528 + ((0.018233707200000001 * fTemp114) + (fTemp529 + ((0.0069333509999999999 * fTemp124) + (((0.037526814399999997 * fTemp127) + fTemp530) + fTemp531)))))))))))))))))))))))))))))));
			output3[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec3[((IOTA - iConst45) & 127)])));
			double fTemp532 = (0.114890667 * fTemp170);
			double fTemp533 = (0.10201110989999999 * fTemp172);
			double fTemp534 = (0.0023381298999999999 * fTemp12);
			double fTemp535 = (0.010248360499999999 * fTemp168);
			double fTemp536 = (0.061640906600000003 * fTemp217);
			double fTemp537 = (0.0094479630000000002 * fTemp226);
			double fTemp538 = (0.065632599599999994 * fTemp234);
			double fTemp539 = (0.038796093199999999 * fTemp250);
			double fTemp540 = (0.0029092989000000001 * fTemp75);
			double fTemp541 = (0.1093362358 * fTemp158);
			double fTemp542 = (0.0056840730000000004 * fTemp323);
			double fTemp543 = (0.0165736166 * fTemp114);
			double fTemp544 = (0.036465735200000002 * fTemp134);
			double fTemp545 = (0.039247927600000003 * fTemp7);
			double fTemp546 = (0.00037173479999999998 * fTemp8);
			double fTemp547 = (0.20310094719999999 * fTemp368);
			double fTemp548 = (0.014058451099999999 * fTemp366);
			double fTemp549 = (0.0276136453 * fTemp90);
			double fTemp550 = (0.026125421400000001 * fTemp357);
			double fTemp551 = (0.049250909900000001 * fTemp280);
			double fTemp552 = (0.016747739300000002 * fTemp293);
			double fTemp553 = (0.088448560300000006 * fTemp318);
			double fTemp554 = (0.0134504966 * fTemp329);
			double fTemp555 = (0.0434138024 * fTemp104);
			double fTemp556 = (0.071252663499999994 * fTemp139);
			fVec4[(IOTA & 127)] = ((fTemp532 + (fTemp533 + (fTemp534 + (fTemp535 + (fTemp183 + (fTemp192 + ((0.038027969199999997 * fTemp200) + (fTemp536 + ((0.013620024999999999 * fTemp33) + (fTemp43 + (fTemp537 + (fTemp60 + ((0.079567520200000005 * fTemp68) + (fTemp538 + (fTemp539 + (fTemp259 + (fTemp540 + (fTemp83 + (fTemp267 + (fTemp99 + (fTemp541 + (fTemp287 + ((0.031174372700000001 * fTemp306) + (fTemp313 + (fTemp542 + ((fTemp543 + (fTemp120 + (fTemp131 + fTemp544))) + (0.049169337200000003 * fTemp343))))))))))))))))))))))))))) - (fTemp545 + (fTemp175 + (fTemp546 + (fTemp11 + (fTemp177 + ((0.00076638409999999998 * fTemp13) + (fTemp16 + (fTemp179 + ((0.030675982399999999 * fTemp180) + (fTemp547 + (fTemp209 + (fTemp25 + ((0.045623510899999997 * fTemp51) + (fTemp548 + (fTemp167 + (fTemp243 + (fTemp549 + (fTemp550 + (fTemp274 + (fTemp551 + (fTemp552 + (fTemp300 + ((0.019101968099999998 * fTemp151) + (fTemp350 + (fTemp553 + (fTemp554 + (fTemp336 + (fTemp555 + ((0.0057958719000000001 * fTemp145) + (fTemp110 + ((0.0005192339 * fTemp124) + ((fTemp338 + (0.048182628599999999 * fTemp127)) + fTemp556)))))))))))))))))))))))))))))))));
			output4[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec4[((IOTA - iConst43) & 127)])));
			double fTemp557 = (0.0029113803 * fTemp12);
			double fTemp558 = (0.00050495749999999995 * fTemp13);
			double fTemp559 = (0.0119548717 * fTemp168);
			double fTemp560 = (0.042667694300000003 * fTemp180);
			double fTemp561 = (0.1436434855 * fTemp368);
			double fTemp562 = (0.041366283099999998 * fTemp200);
			double fTemp563 = (0.078955882599999999 * fTemp234);
			double fTemp564 = (0.050559997600000003 * fTemp250);
			double fTemp565 = (0.0079693786999999999 * fTemp280);
			double fTemp566 = (0.063012542000000005 * fTemp343);
			double fTemp567 = (0.18341458090000001 * fTemp170);
			double fTemp568 = (0.056458576400000002 * fTemp7);
			double fTemp569 = (0.013106275400000001 * fTemp8);
			double fTemp570 = (0.034080690900000002 * fTemp15);
			double fTemp571 = (0.0177418721 * fTemp24);
			double fTemp572 = (0.017436168200000001 * fTemp226);
			double fTemp573 = (0.064825714399999998 * fTemp366);
			double fTemp574 = (0.067753557699999994 * fTemp68);
			double fTemp575 = (0.036523046500000003 * fTemp90);
			double fTemp576 = (0.0536057084 * fTemp357);
			double fTemp577 = (0.024996654699999999 * fTemp318);
			double fTemp578 = (0.013879208699999999 * fTemp329);
			double fTemp579 = (0.1021567571 * fTemp158);
			fVec5[(IOTA & 127)] = ((fTemp372 + (fTemp557 + (fTemp375 + (fTemp558 + (fTemp559 + (fTemp379 + (fTemp560 + (fTemp561 + (fTemp562 + (fTemp384 + ((0.042790446599999997 * fTemp217) + ((fTemp563 + (fTemp391 + (fTemp564 + (fTemp414 + ((0.023122649299999999 * fTemp75) + (fTemp416 + (fTemp395 + (fTemp565 + (fTemp419 + ((0.0022958853999999998 * fTemp293) + (fTemp397 + ((0.036740197199999998 * fTemp306) + (fTemp421 + ((0.032744984300000002 * fTemp151) + (fTemp398 + (fTemp401 + (fTemp566 + (fTemp424 + ((0.078561382099999993 * fTemp145) + ((fTemp405 + (0.0005832271 * fTemp134)) + (0.0064153943999999997 * fTemp124))))))))))))))))))))) + (0.024040066999999998 * fTemp33))))))))))))) - (fTemp567 + (fTemp371 + (fTemp568 + (fTemp569 + (fTemp374 + (fTemp570 + (fTemp380 + (fTemp382 + (fTemp571 + (fTemp410 + ((0.056905669499999999 * fTemp51) + (fTemp572 + (fTemp573 + (fTemp412 + (fTemp574 + (fTemp389 + (fTemp415 + (fTemp575 + (fTemp576 + (fTemp418 + ((fTemp577 + (fTemp400 + ((fTemp403 + ((0.010603733000000001 * fTemp114) + (fTemp426 + (fTemp406 + (fTemp427 + (0.0516268462 * fTemp127)))))) + fTemp578))) + fTemp579))))))))))))))))))))));
			output5[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec5[((IOTA - iConst44) & 127)])));
			double fTemp580 = (0.22368093150000001 * fTemp170);
			double fTemp581 = (0.048792926299999997 * fTemp7);
			double fTemp582 = (0.012466269699999999 * fTemp8);
			double fTemp583 = (0.00050323410000000001 * fTemp12);
			double fTemp584 = (0.0039644103999999999 * fTemp191);
			double fTemp585 = (0.022119309899999998 * fTemp280);
			double fTemp586 = (0.059712700799999997 * fTemp318);
			double fTemp587 = (0.067999887499999995 * fTemp145);
			double fTemp588 = (0.0107713897 * fTemp114);
			double fTemp589 = (0.0026682246000000001 * fTemp172);
			double fTemp590 = (0.023364603800000001 * fTemp10);
			double fTemp591 = (0.0024697122999999999 * fTemp168);
			double fTemp592 = (0.0077637534000000001 * fTemp180);
			double fTemp593 = (0.0621695544 * fTemp368);
			double fTemp594 = (0.082825697000000004 * fTemp200);
			double fTemp595 = (0.051578467400000001 * fTemp217);
			double fTemp596 = (0.023497357199999999 * fTemp33);
			double fTemp597 = (0.032097805799999997 * fTemp366);
			double fTemp598 = (0.029737467199999999 * fTemp68);
			double fTemp599 = (0.1231636554 * fTemp234);
			double fTemp600 = (0.0455015925 * fTemp250);
			double fTemp601 = (0.018586752500000001 * fTemp75);
			double fTemp602 = (0.014556871399999999 * fTemp90);
			double fTemp603 = (0.0304130037 * fTemp158);
			double fTemp604 = (0.046580827700000001 * fTemp323);
			double fTemp605 = (0.072225722800000003 * fTemp109);
			double fTemp606 = (0.0085247402999999999 * fTemp134);
			fVec6[(IOTA & 127)] = ((fTemp580 + (fTemp581 + (fTemp582 + (fTemp583 + ((0.0030235434999999998 * fTemp13) + (fTemp456 + (fTemp459 + (fTemp584 + (fTemp464 + (fTemp435 + (fTemp465 + (fTemp437 + (fTemp467 + (fTemp469 + (fTemp440 + (fTemp442 + (fTemp585 + (fTemp473 + ((0.0090228289999999996 * fTemp293) + ((0.0428044297 * fTemp306) + ((0.049175667800000003 * fTemp151) + (fTemp586 + ((0.024295898699999999 * fTemp329) + ((0.052833860000000003 * fTemp343) + (fTemp587 + (fTemp588 + (fTemp447 + (fTemp448 + fTemp478)))))))))))))))))))))))))))) - (fTemp589 + (fTemp453 + (fTemp590 + (fTemp455 + (fTemp591 + (fTemp458 + (fTemp592 + (fTemp593 + (fTemp594 + (fTemp462 + (fTemp595 + (fTemp596 + ((0.0363575592 * fTemp51) + (fTemp597 + (fTemp598 + (fTemp599 + (fTemp468 + (fTemp600 + (fTemp601 + (fTemp602 + (fTemp441 + ((0.0087253604999999995 * fTemp357) + (fTemp603 + (fTemp472 + (fTemp474 + (fTemp451 + (fTemp475 + (fTemp604 + (fTemp477 + (fTemp450 + (fTemp605 + ((fTemp606 + (fTemp479 + (0.058401310400000003 * fTemp127))) + (0.0068898921000000004 * fTemp124))))))))))))))))))))))))))))))))));
			output6[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec6[((IOTA - iConst44) & 127)])));
			double fTemp607 = (0.0062558869999999999 * fTemp168);
			double fTemp608 = (0.098843145600000001 * fTemp191);
			double fTemp609 = (0.018486106200000001 * fTemp366);
			double fTemp610 = (0.0768508792 * fTemp68);
			double fTemp611 = (0.015947550099999999 * fTemp234);
			double fTemp612 = (0.0035908088999999999 * fTemp357);
			double fTemp613 = (0.12789377909999999 * fTemp158);
			double fTemp614 = (0.017992755900000001 * fTemp280);
			double fTemp615 = (0.0205294946 * fTemp293);
			double fTemp616 = (0.073780409800000002 * fTemp318);
			double fTemp617 = (0.028376518399999998 * fTemp329);
			double fTemp618 = (0.064709982799999996 * fTemp343);
			double fTemp619 = (0.059511944900000002 * fTemp139);
			double fTemp620 = (0.2307684321 * fTemp170);
			double fTemp621 = (0.0017269582000000001 * fTemp12);
			double fTemp622 = (0.070515001600000002 * fTemp180);
			double fTemp623 = (0.028358727300000001 * fTemp368);
			double fTemp624 = (0.075231391999999994 * fTemp217);
			double fTemp625 = (0.073348031899999999 * fTemp250);
			double fTemp626 = (0.032194949700000003 * fTemp90);
			double fTemp627 = (0.036914365900000003 * fTemp145);
			double fTemp628 = (0.0011899049 * fTemp109);
			double fTemp629 = (0.0069333509000000003 * fTemp114);
			double fTemp630 = (0.037526814499999998 * fTemp134);
			fVec7[(IOTA & 127)] = ((fTemp508 + ((0.0090952410000000004 * fTemp7) + (fTemp480 + ((0.019989118899999998 * fTemp8) + (fTemp483 + ((0.0047909262000000001 * fTemp13) + (fTemp510 + (fTemp607 + (fTemp484 + (fTemp608 + ((0.017993115099999998 * fTemp200) + (fTemp487 + (fTemp514 + (fTemp609 + (fTemp610 + (fTemp611 + (fTemp493 + (fTemp517 + (fTemp612 + (fTemp613 + (fTemp498 + (fTemp614 + (fTemp522 + (fTemp615 + (fTemp499 + ((0.035931979599999997 * fTemp306) + (fTemp501 + (fTemp616 + (fTemp525 + (fTemp617 + (fTemp502 + (fTemp618 + (fTemp527 + ((0.0182337071 * fTemp124) + (fTemp503 + fTemp619))))))))))))))))))))))))))))))))))) - (fTemp620 + (fTemp482 + (fTemp621 + (fTemp622 + (fTemp485 + (fTemp623 + (fTemp624 + (fTemp489 + ((0.028262194500000001 * fTemp33) + (fTemp513 + ((0.049374885600000001 * fTemp51) + (fTemp515 + (fTemp492 + (fTemp625 + ((0.015676271299999999 * fTemp75) + (fTemp518 + (fTemp626 + (fTemp496 + (fTemp520 + (fTemp500 + ((0.027650067399999999 * fTemp151) + (fTemp627 + (fTemp628 + (fTemp629 + (fTemp529 + ((fTemp530 + (0.034939071500000002 * fTemp127)) + fTemp630)))))))))))))))))))))))))));
			output7[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec7[((IOTA - iConst45) & 127)])));
			fVec8[(IOTA & 127)] = ((fTemp171 + (fTemp11 + (fTemp16 + (fTemp181 + (fTemp369 + ((0.079567520200000005 * fTemp200) + (fTemp218 + (fTemp25 + (fTemp43 + (fTemp367 + (fTemp60 + (fTemp167 + (fTemp235 + (fTemp251 + (fTemp83 + (fTemp358 + (fTemp99 + ((0.019101968 * fTemp280) + ((0.031174372700000001 * fTemp293) + (((0.0057958719999999997 * fTemp318) + (fTemp330 + ((0.0134504966 * fTemp343) + (fTemp105 + (fTemp110 + (fTemp120 + (fTemp131 + fTemp140))))))) + (0.016747739300000002 * fTemp306))))))))))))))))))))) - (fTemp173 + ((0.030675982399999999 * fTemp7) + (fTemp175 + (fTemp9 + ((0.00076638409999999998 * fTemp12) + (fTemp177 + (fTemp14 + (fTemp169 + (fTemp179 + (fTemp183 + (fTemp192 + (fTemp209 + (fTemp34 + ((0.0136200249 * fTemp51) + (fTemp227 + ((0.038027969100000003 * fTemp68) + (fTemp243 + (fTemp259 + ((0.0276136453 * fTemp75) + (fTemp91 + (fTemp267 + (fTemp159 + (fTemp274 + (fTemp287 + (fTemp300 + (fTemp313 + ((0.049250910000000002 * fTemp151) + (fTemp350 + (fTemp324 + (fTemp336 + ((0.088448560300000006 * fTemp145) + (fTemp115 + ((fTemp135 + (fTemp338 + (0.036465735300000003 * fTemp127))) + (0.016573616499999999 * fTemp124)))))))))))))))))))))))))))))))))));
			output8[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec8[((IOTA - iConst43) & 127)])));
			fVec9[(IOTA & 127)] = ((fTemp371 + ((0.042667694399999997 * fTemp7) + (fTemp372 + (fTemp374 + (fTemp407 + (fTemp375 + (fTemp377 + (fTemp379 + (fTemp408 + (fTemp380 + (fTemp382 + (fTemp384 + (fTemp409 + (fTemp385 + (fTemp387 + (fTemp411 + (fTemp389 + (fTemp391 + (fTemp413 + (fTemp417 + (fTemp395 + (fTemp420 + (fTemp397 + ((0.0079693786999999999 * fTemp151) + (fTemp398 + (fTemp400 + (fTemp422 + (fTemp401 + (fTemp423 + (fTemp403 + (fTemp425 + ((0.010603732899999999 * fTemp124) + (fTemp405 + fTemp406))))))))))))))))))))))))))))))))) - (fTemp370 + (fTemp373 + (fTemp376 + (fTemp378 + (fTemp381 + (fTemp383 + (fTemp386 + (fTemp410 + ((0.0240400671 * fTemp51) + (fTemp412 + (fTemp388 + (fTemp390 + (fTemp414 + (fTemp392 + (fTemp415 + (fTemp393 + (fTemp416 + (fTemp418 + (fTemp394 + (fTemp396 + (fTemp419 + ((0.0022958853000000002 * fTemp306) + (fTemp421 + (fTemp399 + (fTemp424 + (fTemp402 + (fTemp426 + (fTemp404 + (fTemp427 + (0.00058322690000000004 * fTemp127)))))))))))))))))))))))))))))));
			output9[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec9[((IOTA - iConst44) & 127)])));
			fVec10[(IOTA & 127)] = ((fTemp452 + (fTemp428 + (fTemp454 + (fTemp430 + ((0.0030235434999999998 * fTemp12) + (fTemp457 + (fTemp460 + (fTemp463 + (fTemp435 + ((0.023497357300000001 * fTemp51) + (fTemp437 + (fTemp466 + ((0.0087253604999999995 * fTemp250) + (fTemp440 + (fTemp470 + (fTemp441 + (fTemp442 + (fTemp471 + ((0.0428044297 * fTemp293) + (fTemp451 + ((0.0221193098 * fTemp151) + (fTemp444 + (fTemp476 + (fTemp450 + ((0.059712700799999997 * fTemp145) + (fTemp445 + (fTemp447 + (fTemp448 + (0.0085247402000000003 * fTemp127))))))))))))))))))))))))))))) - (fTemp429 + (fTemp453 + (fTemp455 + (fTemp431 + (fTemp456 + (fTemp458 + (fTemp432 + (fTemp459 + (fTemp461 + (fTemp433 + (fTemp462 + (fTemp464 + (fTemp434 + (fTemp465 + (fTemp436 + (fTemp467 + (fTemp438 + (fTemp468 + (fTemp469 + (fTemp439 + ((0.0455015925 * fTemp357) + (fTemp472 + ((0.049175667899999997 * fTemp280) + (fTemp473 + (fTemp474 + ((0.0090228290999999992 * fTemp306) + (fTemp475 + (fTemp443 + (fTemp477 + ((fTemp446 + ((0.0107713896 * fTemp124) + (fTemp478 + (fTemp479 + fTemp449)))) + (0.024295898699999999 * fTemp343))))))))))))))))))))))))))))))));
			output10[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec10[((IOTA - iConst44) & 127)])));
			fVec11[(IOTA & 127)] = ((fTemp507 + (fTemp480 + (fTemp482 + ((0.0047909262000000001 * fTemp12) + (fTemp483 + (fTemp509 + ((0.0199891188 * fTemp168) + (fTemp484 + (fTemp485 + (fTemp512 + (fTemp487 + (fTemp489 + ((0.028262194399999999 * fTemp51) + (fTemp492 + (fTemp516 + (fTemp493 + (fTemp519 + (fTemp496 + (fTemp498 + (fTemp521 + (fTemp523 + (fTemp499 + (fTemp500 + ((0.017992755999999999 * fTemp151) + (fTemp501 + (fTemp524 + (fTemp526 + (fTemp502 + (fTemp528 + (fTemp505 + ((0.018233707299999999 * fTemp114) + ((fTemp503 + (0.0375268146 * fTemp127)) + (0.0069333507999999999 * fTemp124))))))))))))))))))))))))))))))))) - (fTemp508 + ((0.070515001499999994 * fTemp7) + (fTemp481 + (fTemp510 + ((0.0090952409000000008 * fTemp180) + (fTemp486 + (fTemp511 + (fTemp488 + (fTemp490 + (fTemp513 + (fTemp514 + (fTemp491 + (fTemp515 + ((0.0179931152 * fTemp68) + (fTemp494 + (fTemp517 + (fTemp495 + (fTemp518 + ((0.073348031899999999 * fTemp357) + (fTemp520 + (fTemp497 + (fTemp522 + ((0.0205294946 * fTemp306) + (fTemp525 + (fTemp506 + (fTemp527 + (fTemp529 + (fTemp531 + (fTemp530 + fTemp504))))))))))))))))))))))))))))));
			output11[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec11[((IOTA - iConst45) & 127)])));
			fVec12[(IOTA & 127)] = ((fTemp533 + (fTemp545 + (fTemp546 + ((0.00076638420000000001 * fTemp13) + ((0.030675982300000001 * fTemp180) + (fTemp183 + (fTemp547 + (fTemp192 + (fTemp43 + ((0.045623510999999999 * fTemp51) + (fTemp537 + (fTemp548 + (fTemp60 + (fTemp259 + (fTemp83 + (fTemp549 + (fTemp267 + (fTemp550 + (fTemp99 + (fTemp551 + (fTemp287 + (fTemp552 + (fTemp313 + ((0.019101968 * fTemp151) + (fTemp553 + (fTemp542 + (fTemp554 + ((0.0057958719999999997 * fTemp145) + (fTemp120 + ((fTemp131 + (0.048182628399999997 * fTemp127)) + (0.00051923409999999996 * fTemp124))))))))))))))))))))))))))))))) - (fTemp532 + (fTemp175 + (fTemp11 + (fTemp534 + (fTemp177 + (fTemp16 + (fTemp535 + (fTemp179 + ((0.038027969100000003 * fTemp200) + (fTemp209 + (fTemp536 + (fTemp25 + ((0.0136200249 * fTemp33) + ((0.079567520099999997 * fTemp68) + (fTemp167 + (fTemp538 + (fTemp243 + (fTemp539 + (fTemp540 + (fTemp541 + (fTemp274 + (fTemp300 + ((0.031174372799999999 * fTemp306) + (fTemp350 + (fTemp336 + ((0.049169337299999998 * fTemp343) + (fTemp555 + (fTemp110 + (fTemp543 + (fTemp556 + (fTemp338 + fTemp544))))))))))))))))))))))))))))))));
			output12[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec12[((IOTA - iConst43) & 127)])));
			fVec13[(IOTA & 127)] = ((fTemp567 + (fTemp568 + (fTemp372 + (fTemp569 + (fTemp375 + (fTemp379 + (fTemp384 + ((0.056905669399999997 * fTemp51) + (fTemp573 + (fTemp574 + (fTemp391 + (fTemp414 + (fTemp575 + (fTemp416 + (fTemp576 + (fTemp579 + (fTemp395 + (fTemp419 + (fTemp397 + (fTemp421 + (fTemp398 + (fTemp577 + (fTemp578 + (fTemp401 + (fTemp424 + ((fTemp405 + (0.051626846400000002 * fTemp127)) + (0.0106037331 * fTemp114))))))))))))))))))))))))))) - (fTemp371 + (fTemp374 + (fTemp557 + (fTemp558 + (fTemp570 + (fTemp559 + (fTemp560 + (fTemp380 + (fTemp561 + (fTemp382 + (fTemp562 + ((0.042790446699999998 * fTemp217) + (fTemp571 + ((0.0240400671 * fTemp33) + (fTemp410 + (fTemp572 + (fTemp412 + (fTemp389 + (fTemp563 + (fTemp564 + ((0.023122649200000001 * fTemp75) + (fTemp415 + (fTemp418 + (fTemp565 + ((0.0022958853000000002 * fTemp293) + ((0.036740197099999997 * fTemp306) + ((0.0327449842 * fTemp151) + (fTemp400 + (fTemp566 + ((0.078561382200000002 * fTemp145) + (fTemp403 + (fTemp426 + ((0.0064153945999999998 * fTemp124) + (fTemp406 + (fTemp427 + (0.00058322699999999996 * fTemp134)))))))))))))))))))))))))))))))))))));
			output13[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec13[((IOTA - iConst44) & 127)])));
			fVec14[(IOTA & 127)] = ((fTemp456 + (fTemp591 + (fTemp592 + (fTemp459 + (fTemp593 + (fTemp584 + (fTemp594 + (fTemp595 + (fTemp464 + (fTemp596 + (fTemp435 + ((0.036357559300000002 * fTemp51) + (fTemp465 + (fTemp597 + (fTemp437 + (fTemp598 + (fTemp467 + (fTemp599 + (fTemp600 + (fTemp469 + (fTemp601 + (fTemp440 + (fTemp602 + ((0.0087253606000000008 * fTemp357) + (fTemp442 + (fTemp603 + (fTemp473 + (fTemp447 + ((0.0068898923000000004 * fTemp124) + (fTemp478 + (fTemp606 + (fTemp448 + (0.058401310200000001 * fTemp127))))))))))))))))))))))))))))))))) - (fTemp580 + (fTemp589 + (fTemp581 + (fTemp453 + (fTemp582 + (fTemp590 + (fTemp583 + (fTemp455 + ((0.0030235434000000002 * fTemp13) + (fTemp458 + (fTemp462 + (fTemp468 + (fTemp441 + (fTemp472 + (fTemp585 + ((0.0090228290999999992 * fTemp293) + (fTemp474 + ((0.042804429800000002 * fTemp306) + (fTemp451 + ((0.049175667899999997 * fTemp151) + (fTemp475 + (fTemp586 + (fTemp604 + ((0.024295898600000001 * fTemp329) + (fTemp477 + ((0.052833860099999998 * fTemp343) + (fTemp450 + (fTemp587 + (fTemp605 + (fTemp479 + fTemp588)))))))))))))))))))))))))))))));
			output14[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec14[((IOTA - iConst44) & 127)])));
			fVec15[(IOTA & 127)] = ((fTemp620 + (fTemp508 + (fTemp480 + (fTemp621 + (fTemp483 + (fTemp510 + (fTemp484 + (fTemp622 + (fTemp623 + (fTemp608 + (fTemp487 + (fTemp624 + ((0.028262194399999999 * fTemp33) + ((0.0493748855 * fTemp51) + (fTemp514 + (fTemp493 + (fTemp625 + (fTemp517 + ((0.0156762714 * fTemp75) + (fTemp626 + (fTemp498 + (fTemp522 + (fTemp499 + ((0.0276500675 * fTemp151) + (fTemp501 + (fTemp525 + (fTemp502 + (fTemp527 + (fTemp627 + (fTemp629 + (fTemp619 + (fTemp630 + (fTemp503 + (0.034939071699999998 * fTemp127)))))))))))))))))))))))))))))))))) - ((0.0090952409000000008 * fTemp7) + ((0.0199891188 * fTemp8) + (fTemp482 + ((0.0047909262999999997 * fTemp13) + (fTemp607 + (fTemp485 + ((0.0179931152 * fTemp200) + (fTemp489 + (fTemp513 + (fTemp609 + (fTemp515 + (fTemp610 + (fTemp492 + (fTemp611 + (fTemp518 + (fTemp496 + (fTemp612 + (fTemp520 + (fTemp613 + (fTemp614 + (fTemp615 + ((0.035931979400000001 * fTemp306) + (fTemp500 + (fTemp616 + (fTemp617 + (fTemp618 + (fTemp628 + (fTemp529 + (fTemp530 + (0.0182337074 * fTemp124)))))))))))))))))))))))))))))));
			output15[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec15[((IOTA - iConst45) & 127)])));
			double fTemp631 = (0.026496524600000002 * fTemp172);
			double fTemp632 = (0.057943717999999998 * fTemp7);
			double fTemp633 = (0.047873619899999997 * fTemp8);
			double fTemp634 = (0.053213955799999997 * fTemp10);
			double fTemp635 = (0.00081671100000000002 * fTemp12);
			double fTemp636 = (0.0407989115 * fTemp176);
			double fTemp637 = (0.0092075859000000006 * fTemp13);
			double fTemp638 = (7.6425800000000003e-05 * fTemp182);
			double fTemp639 = (8.8928000000000006e-06 * fTemp368);
			double fTemp640 = (0.023144911399999999 * fTemp200);
			double fTemp641 = (0.0400508735 * fTemp24);
			double fTemp642 = (0.032278688100000001 * fTemp42);
			double fTemp643 = (0.00041465250000000001 * fTemp366);
			double fTemp644 = (0.025983795300000001 * fTemp266);
			double fTemp645 = (0.00065164490000000003 * fTemp357);
			double fTemp646 = (0.0082756579000000004 * fTemp158);
			double fTemp647 = (0.0035280969 * fTemp306);
			double fTemp648 = (0.095478578699999997 * fTemp312);
			double fTemp649 = (0.00047650209999999999 * fTemp151);
			double fTemp650 = (0.042013054399999999 * fTemp329);
			double fTemp651 = (0.084822552499999995 * fTemp343);
			double fTemp652 = (0.097537344999999998 * fTemp104);
			double fTemp653 = (0.00016022200000000001 * fTemp145);
			double fTemp654 = (0.0503169459 * fTemp114);
			double fTemp655 = (0.022256174399999998 * fTemp119);
			double fTemp656 = (0.094348982200000001 * fTemp124);
			double fTemp657 = (0.028016392300000002 * fTemp134);
			double fTemp658 = (0.043616592099999997 * fTemp130);
			double fTemp659 = (0.026883979799999999 * fTemp337);
			double fTemp660 = (0.050833699000000003 * fTemp127);
			double fTemp661 = (0.051847117499999998 * fTemp139);
			double fTemp662 = (7.8203199999999997e-05 * fTemp170);
			double fTemp663 = (0.042703895800000002 * fTemp174);
			double fTemp664 = (0.082881343400000002 * fTemp15);
			double fTemp665 = (7.8425300000000003e-05 * fTemp168);
			double fTemp666 = (0.080658271899999995 * fTemp178);
			double fTemp667 = (0.1019812501 * fTemp180);
			double fTemp668 = (0.021756410300000001 * fTemp191);
			double fTemp669 = (0.062172827999999999 * fTemp208);
			double fTemp670 = (0.063259840799999995 * fTemp217);
			double fTemp671 = (0.050272720399999998 * fTemp33);
			double fTemp672 = (0.077462295200000003 * fTemp51);
			double fTemp673 = (0.059824481999999998 * fTemp226);
			double fTemp674 = (0.055682601700000001 * fTemp59);
			double fTemp675 = (0.0406268667 * fTemp68);
			double fTemp676 = (1.0959e-05 * fTemp166);
			double fTemp677 = (0.0046955036000000004 * fTemp234);
			double fTemp678 = (0.044843385600000001 * fTemp242);
			double fTemp679 = (0.1196077924 * fTemp250);
			double fTemp680 = (0.0087027784999999993 * fTemp258);
			double fTemp681 = (0.053204508400000003 * fTemp75);
			double fTemp682 = (0.039081774700000002 * fTemp82);
			double fTemp683 = (0.080132019099999993 * fTemp90);
			double fTemp684 = (0.0440488141 * fTemp98);
			double fTemp685 = (0.016240128900000001 * fTemp273);
			double fTemp686 = (0.088944856599999997 * fTemp280);
			double fTemp687 = (0.049363782100000003 * fTemp286);
			double fTemp688 = (0.0058496622000000003 * fTemp293);
			double fTemp689 = (0.082393359299999996 * fTemp299);
			double fTemp690 = (0.0408404832 * fTemp349);
			double fTemp691 = (0.0282808495 * fTemp318);
			double fTemp692 = (0.052899533200000001 * fTemp323);
			double fTemp693 = (0.0289897616 * fTemp109);
			double fTemp694 = (0.044359211900000001 * fTemp335);
			fVec16[(IOTA & 127)] = ((fTemp631 + (fTemp632 + (fTemp633 + (fTemp634 + (fTemp635 + (fTemp636 + (fTemp637 + (fTemp638 + (fTemp639 + (fTemp640 + (fTemp641 + (fTemp642 + (fTemp643 + (fTemp644 + (fTemp645 + (fTemp646 + (fTemp647 + (fTemp648 + (fTemp649 + (fTemp650 + (fTemp651 + (fTemp652 + (fTemp653 + (fTemp654 + (fTemp655 + (fTemp656 + ((fTemp657 + (fTemp658 + (fTemp659 + fTemp660))) + fTemp661))))))))))))))))))))))))))) - (fTemp662 + (fTemp663 + (fTemp664 + (fTemp665 + (fTemp666 + (fTemp667 + (fTemp668 + (fTemp669 + (fTemp670 + (fTemp671 + (fTemp672 + (fTemp673 + (fTemp674 + (fTemp675 + (fTemp676 + (fTemp677 + (fTemp678 + (fTemp679 + (fTemp680 + (fTemp681 + (fTemp682 + (fTemp683 + (fTemp684 + (fTemp685 + (fTemp686 + (fTemp687 + (fTemp688 + (fTemp689 + (fTemp690 + (fTemp691 + (fTemp692 + (fTemp693 + fTemp694)))))))))))))))))))))))))))))))));
			output16[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec16[((IOTA - iConst46) & 127)])));
			double fTemp695 = (0.00012352519999999999 * fTemp170);
			double fTemp696 = (0.00064792210000000003 * fTemp172);
			double fTemp697 = (0.032313203700000001 * fTemp7);
			double fTemp698 = (0.062592863100000007 * fTemp174);
			double fTemp699 = (0.0030103411000000002 * fTemp12);
			double fTemp700 = (0.096047584300000002 * fTemp176);
			double fTemp701 = (0.1200630713 * fTemp178);
			double fTemp702 = (0.11284305729999999 * fTemp180);
			double fTemp703 = (0.0267199688 * fTemp182);
			double fTemp704 = (0.0001107106 * fTemp368);
			double fTemp705 = (0.0129118714 * fTemp200);
			double fTemp706 = (0.089209011300000002 * fTemp208);
			double fTemp707 = (0.0452043138 * fTemp217);
			double fTemp708 = (0.043973263800000002 * fTemp366);
			double fTemp709 = (0.0074131986000000004 * fTemp59);
			double fTemp710 = (0.044982333100000001 * fTemp68);
			double fTemp711 = (0.0646936293 * fTemp242);
			double fTemp712 = (0.085288070300000005 * fTemp250);
			double fTemp713 = (0.026150729399999999 * fTemp258);
			double fTemp714 = (0.021087531400000002 * fTemp266);
			double fTemp715 = (0.083767716500000006 * fTemp357);
			double fTemp716 = (0.015489596899999999 * fTemp98);
			double fTemp717 = (0.0240627793 * fTemp273);
			double fTemp718 = (0.063473716599999994 * fTemp280);
			double fTemp719 = (0.095517163000000002 * fTemp286);
			double fTemp720 = (0.059913561599999998 * fTemp312);
			double fTemp721 = (0.062194404600000003 * fTemp151);
			double fTemp722 = (0.073253852800000005 * fTemp349);
			double fTemp723 = (0.0202572918 * fTemp318);
			double fTemp724 = (0.097517002899999997 * fTemp323);
			double fTemp725 = (0.083211966999999998 * fTemp329);
			double fTemp726 = (0.015711706700000001 * fTemp343);
			double fTemp727 = (0.058727388800000002 * fTemp104);
			double fTemp728 = (0.019589071699999999 * fTemp145);
			double fTemp729 = (0.051830101199999999 * fTemp109);
			double fTemp730 = (0.098325733200000001 * fTemp114);
			double fTemp731 = (0.022221562300000001 * fTemp124);
			double fTemp732 = (0.054443566499999999 * fTemp134);
			double fTemp733 = (0.0202882084 * fTemp130);
			double fTemp734 = (0.045821205199999999 * fTemp337);
			double fTemp735 = (0.013179120399999999 * fTemp127);
			double fTemp736 = (0.030362070599999999 * fTemp139);
			double fTemp737 = (0.0337995491 * fTemp8);
			double fTemp738 = (0.082557385699999999 * fTemp10);
			double fTemp739 = (0.0032600607999999998 * fTemp13);
			double fTemp740 = (0.041570006399999998 * fTemp15);
			double fTemp741 = (0.034562308700000002 * fTemp168);
			double fTemp742 = (0.00040862420000000002 * fTemp191);
			double fTemp743 = (0.059533214899999999 * fTemp24);
			double fTemp744 = (0.095125888500000005 * fTemp33);
			double fTemp745 = (0.0076406453999999999 * fTemp42);
			double fTemp746 = (0.0301040913 * fTemp51);
			double fTemp747 = (0.028326167400000001 * fTemp226);
			double fTemp748 = (0.021926994799999999 * fTemp166);
			double fTemp749 = (0.0025425575000000001 * fTemp234);
			double fTemp750 = (0.1003231742 * fTemp75);
			double fTemp751 = (0.067207030200000004 * fTemp82);
			double fTemp752 = (0.032714796300000001 * fTemp90);
			double fTemp753 = (0.0091821331999999995 * fTemp158);
			double fTemp754 = (0.0087437856999999994 * fTemp293);
			double fTemp755 = (0.0561968984 * fTemp299);
			double fTemp756 = (0.0049380878000000001 * fTemp119);
			double fTemp757 = (0.026174335900000002 * fTemp335);
			double fTemp758 = (0.0093901434000000002 * fTemp306);
			fVec17[(IOTA & 127)] = ((fTemp695 + (fTemp696 + (fTemp697 + (fTemp698 + (fTemp699 + (fTemp700 + (fTemp701 + (fTemp702 + (fTemp703 + (fTemp704 + (fTemp705 + (fTemp706 + (fTemp707 + (fTemp708 + (fTemp709 + (fTemp710 + (fTemp711 + (fTemp712 + (fTemp713 + (fTemp714 + (fTemp715 + (fTemp716 + (fTemp717 + (fTemp718 + (fTemp719 + (fTemp720 + (fTemp721 + (fTemp722 + (fTemp723 + (fTemp724 + (fTemp725 + (fTemp726 + (fTemp727 + (fTemp728 + (fTemp729 + (fTemp730 + (fTemp731 + ((fTemp732 + (fTemp733 + (fTemp734 + fTemp735))) + fTemp736)))))))))))))))))))))))))))))))))))))) - (fTemp737 + (fTemp738 + (fTemp739 + (fTemp740 + (fTemp741 + (fTemp742 + (fTemp743 + (fTemp744 + (fTemp745 + (fTemp746 + (fTemp747 + (fTemp748 + (fTemp749 + (fTemp750 + (fTemp751 + (fTemp752 + (fTemp753 + (fTemp754 + (fTemp755 + ((fTemp756 + fTemp757) + fTemp758)))))))))))))))))))));
			output17[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec17[((IOTA - iConst46) & 127)])));
			double fTemp759 = (7.8425300000000003e-05 * fTemp8);
			double fTemp760 = (0.0092075859000000006 * fTemp12);
			double fTemp761 = (0.047873619899999997 * fTemp168);
			double fTemp762 = (0.050272720399999998 * fTemp51);
			double fTemp763 = (0.0082756579000000004 * fTemp234);
			double fTemp764 = (0.053204508400000003 * fTemp90);
			double fTemp765 = (0.0046955036000000004 * fTemp158);
			double fTemp766 = (0.0035280969 * fTemp293);
			double fTemp767 = (0.094348982200000001 * fTemp114);
			double fTemp768 = (0.050833699000000003 * fTemp134);
			double fTemp769 = (fTemp659 + fTemp658);
			double fTemp770 = (0.084822552499999995 * fTemp329);
			double fTemp771 = (0.0058496622000000003 * fTemp306);
			double fTemp772 = (8.8928000000000006e-06 * fTemp170);
			double fTemp773 = (0.1019812501 * fTemp7);
			double fTemp774 = (0.00081671100000000002 * fTemp13);
			double fTemp775 = (0.057943717999999998 * fTemp180);
			double fTemp776 = (7.8203199999999997e-05 * fTemp368);
			double fTemp777 = (0.0406268667 * fTemp200);
			double fTemp778 = (0.00041465250000000001 * fTemp217);
			double fTemp779 = (0.077462295200000003 * fTemp33);
			double fTemp780 = (0.063259840799999995 * fTemp366);
			double fTemp781 = (0.023144911399999999 * fTemp68);
			double fTemp782 = (0.00065164490000000003 * fTemp250);
			double fTemp783 = (0.080132019099999993 * fTemp75);
			double fTemp784 = (0.1196077924 * fTemp357);
			double fTemp785 = (0.00047650209999999999 * fTemp280);
			double fTemp786 = (0.088944856599999997 * fTemp151);
			double fTemp787 = (0.00016022200000000001 * fTemp318);
			double fTemp788 = (0.042013054399999999 * fTemp343);
			double fTemp789 = (0.0282808495 * fTemp145);
			double fTemp790 = (0.0503169459 * fTemp124);
			double fTemp791 = (0.028016392300000002 * fTemp127);
			fVec18[(IOTA & 127)] = ((fTemp759 + (fTemp760 + (fTemp636 + (fTemp664 + (fTemp761 + (fTemp668 + (fTemp642 + (fTemp762 + (fTemp673 + (fTemp676 + (fTemp763 + (fTemp680 + (fTemp764 + (fTemp765 + (fTemp687 + (fTemp766 + ((fTemp692 + ((fTemp693 + (fTemp767 + (fTemp655 + (fTemp768 + fTemp769)))) + fTemp770)) + fTemp771))))))))))))))))) - (fTemp772 + (fTemp631 + (fTemp773 + (fTemp663 + (fTemp634 + (fTemp774 + (fTemp666 + (fTemp775 + (fTemp638 + (fTemp776 + (fTemp777 + (fTemp669 + (fTemp778 + (fTemp641 + (fTemp779 + (fTemp780 + (fTemp674 + (fTemp781 + (fTemp678 + (fTemp782 + (fTemp783 + (fTemp682 + (fTemp644 + (fTemp784 + (fTemp684 + (fTemp685 + (fTemp785 + (fTemp689 + (fTemp648 + (fTemp786 + (fTemp690 + (fTemp787 + (fTemp694 + (fTemp788 + (fTemp652 + (fTemp789 + (fTemp790 + (fTemp661 + fTemp791)))))))))))))))))))))))))))))))))))))));
			output18[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec18[((IOTA - iConst46) & 127)])));
			double fTemp792 = (0.11284305729999999 * fTemp7);
			double fTemp793 = (0.034562308700000002 * fTemp8);
			double fTemp794 = (0.00012352519999999999 * fTemp368);
			double fTemp795 = (0.044982333100000001 * fTemp200);
			double fTemp796 = (0.095125888500000005 * fTemp51);
			double fTemp797 = (0.0452043138 * fTemp366);
			double fTemp798 = (0.1003231742 * fTemp90);
			double fTemp799 = (0.085288070300000005 * fTemp357);
			double fTemp800 = (0.0025425575000000001 * fTemp158);
			double fTemp801 = (0.0087437856999999994 * fTemp306);
			double fTemp802 = (0.063473716599999994 * fTemp151);
			double fTemp803 = (0.015711706700000001 * fTemp329);
			double fTemp804 = (0.0202572918 * fTemp145);
			double fTemp805 = (0.013179120399999999 * fTemp134);
			double fTemp806 = (fTemp734 + fTemp733);
			double fTemp807 = (0.022221562300000001 * fTemp114);
			double fTemp808 = (0.0001107106 * fTemp170);
			double fTemp809 = (0.0032600607999999998 * fTemp12);
			double fTemp810 = (0.0030103411000000002 * fTemp13);
			double fTemp811 = (0.0337995491 * fTemp168);
			double fTemp812 = (0.032313203700000001 * fTemp180);
			double fTemp813 = (0.043973263800000002 * fTemp217);
			double fTemp814 = (0.0301040913 * fTemp33);
			double fTemp815 = (0.0129118714 * fTemp68);
			double fTemp816 = (0.0091821331999999995 * fTemp234);
			double fTemp817 = (0.083767716500000006 * fTemp250);
			double fTemp818 = (0.032714796300000001 * fTemp75);
			double fTemp819 = (0.062194404600000003 * fTemp280);
			double fTemp820 = (0.0093901434000000002 * fTemp293);
			double fTemp821 = (0.019589071699999999 * fTemp318);
			double fTemp822 = (0.083211966999999998 * fTemp343);
			double fTemp823 = (0.098325733200000001 * fTemp124);
			double fTemp824 = (0.054443566499999999 * fTemp127);
			fVec19[(IOTA & 127)] = ((fTemp792 + (fTemp698 + (fTemp793 + (fTemp738 + (fTemp700 + (fTemp740 + (fTemp701 + (fTemp794 + (fTemp742 + (fTemp795 + (fTemp706 + (fTemp743 + (fTemp796 + (fTemp747 + (fTemp797 + (fTemp709 + (fTemp748 + (fTemp711 + (fTemp798 + (fTemp799 + (fTemp716 + (fTemp800 + (fTemp717 + (fTemp801 + (fTemp802 + (fTemp722 + (fTemp803 + (fTemp804 + ((fTemp805 + fTemp806) + fTemp807))))))))))))))))))))))))))))) - (fTemp808 + (fTemp696 + (fTemp809 + (fTemp810 + (fTemp811 + (fTemp812 + (fTemp703 + (fTemp813 + (fTemp814 + (fTemp745 + (fTemp815 + (fTemp816 + (fTemp817 + (fTemp713 + (fTemp818 + (fTemp751 + (fTemp714 + (fTemp819 + (fTemp719 + (fTemp820 + (fTemp755 + (fTemp720 + (fTemp821 + (fTemp724 + (fTemp757 + (fTemp822 + (fTemp727 + (fTemp729 + (fTemp756 + (fTemp823 + (fTemp736 + fTemp824))))))))))))))))))))))))))))))));
			output19[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec19[((IOTA - iConst46) & 127)])));
			fVec20[(IOTA & 127)] = ((fTemp662 + (fTemp631 + (fTemp634 + (fTemp636 + (fTemp665 + (fTemp667 + (fTemp638 + (fTemp670 + (fTemp641 + (fTemp671 + (fTemp642 + (fTemp672 + (fTemp675 + (fTemp677 + (fTemp679 + (fTemp681 + (fTemp683 + (fTemp644 + (fTemp686 + (fTemp688 + (fTemp648 + (fTemp691 + (fTemp652 + (fTemp655 + (fTemp661 + fTemp769))))))))))))))))))))))))) - (fTemp632 + (fTemp663 + (fTemp633 + (fTemp635 + (fTemp637 + (fTemp664 + (fTemp666 + (fTemp639 + (fTemp668 + (fTemp640 + (fTemp669 + (fTemp673 + (fTemp643 + (fTemp674 + (fTemp676 + (fTemp678 + (fTemp680 + (fTemp682 + (fTemp645 + (fTemp684 + (fTemp646 + (fTemp685 + (fTemp687 + (fTemp689 + (fTemp647 + (fTemp649 + (fTemp690 + (fTemp692 + (fTemp650 + (fTemp694 + (fTemp651 + (fTemp653 + (fTemp693 + (fTemp654 + (fTemp656 + (fTemp660 + fTemp657)))))))))))))))))))))))))))))))))))));
			output20[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec20[((IOTA - iConst46) & 127)])));
			fVec21[(IOTA & 127)] = ((fTemp696 + (fTemp698 + (fTemp737 + (fTemp700 + (fTemp739 + (fTemp741 + (fTemp701 + (fTemp703 + (fTemp706 + (fTemp744 + (fTemp746 + (fTemp709 + (fTemp749 + (fTemp711 + (fTemp713 + (fTemp750 + (fTemp752 + (fTemp714 + (fTemp716 + (fTemp753 + (fTemp717 + (fTemp719 + (fTemp754 + (fTemp758 + (fTemp720 + (fTemp722 + (fTemp724 + (fTemp727 + (fTemp729 + (fTemp736 + fTemp806)))))))))))))))))))))))))))))) - (fTemp695 + (fTemp697 + (fTemp738 + (fTemp699 + (fTemp740 + (fTemp702 + (fTemp704 + (fTemp742 + (fTemp705 + (fTemp707 + (fTemp743 + (fTemp745 + (fTemp747 + (fTemp708 + (fTemp710 + (fTemp748 + (fTemp712 + (fTemp751 + (fTemp715 + (fTemp718 + (fTemp755 + (fTemp721 + (fTemp723 + (fTemp725 + (fTemp757 + (fTemp726 + (fTemp728 + (fTemp730 + (fTemp756 + (fTemp731 + (fTemp735 + fTemp732))))))))))))))))))))))))))))))));
			output21[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec21[((IOTA - iConst46) & 127)])));
			fVec22[(IOTA & 127)] = ((fTemp772 + (fTemp773 + (fTemp636 + (fTemp774 + (fTemp664 + (fTemp775 + (fTemp776 + (fTemp668 + (fTemp777 + (fTemp778 + (fTemp779 + (fTemp642 + (fTemp673 + (fTemp780 + (fTemp781 + (fTemp676 + (fTemp782 + (fTemp680 + (fTemp783 + (fTemp784 + (fTemp785 + (fTemp687 + (fTemp786 + (fTemp787 + (fTemp692 + (fTemp788 + (fTemp789 + (fTemp693 + (fTemp655 + (fTemp790 + (fTemp658 + (fTemp659 + fTemp791)))))))))))))))))))))))))))))))) - (fTemp631 + (fTemp663 + (fTemp759 + (fTemp634 + (fTemp760 + (fTemp761 + (fTemp666 + (fTemp638 + (fTemp669 + (fTemp641 + (fTemp762 + (fTemp674 + (fTemp763 + (fTemp678 + (fTemp682 + (fTemp764 + (fTemp644 + (fTemp684 + (fTemp765 + (fTemp685 + (fTemp766 + (fTemp689 + (fTemp771 + (fTemp648 + (fTemp690 + (fTemp770 + (fTemp694 + (fTemp652 + (fTemp767 + (fTemp661 + fTemp768)))))))))))))))))))))))))))))));
			output22[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec22[((IOTA - iConst46) & 127)])));
			fVec23[(IOTA & 127)] = ((fTemp808 + (fTemp698 + (fTemp738 + (fTemp809 + (fTemp700 + (fTemp810 + (fTemp740 + (fTemp811 + (fTemp701 + (fTemp812 + (fTemp742 + (fTemp706 + (fTemp813 + (fTemp743 + (fTemp814 + (fTemp747 + (fTemp709 + (fTemp815 + (fTemp748 + (fTemp816 + (fTemp711 + (fTemp817 + (fTemp818 + (fTemp716 + (fTemp717 + (fTemp819 + (fTemp820 + (fTemp722 + (fTemp821 + (fTemp822 + (fTemp823 + (fTemp733 + (fTemp734 + fTemp824))))))))))))))))))))))))))))))))) - (fTemp696 + (fTemp792 + (fTemp793 + (fTemp703 + (fTemp794 + (fTemp795 + (fTemp745 + (fTemp796 + (fTemp797 + (fTemp713 + (fTemp751 + (fTemp798 + (fTemp714 + (fTemp799 + (fTemp800 + (fTemp719 + (fTemp755 + (fTemp801 + (fTemp720 + (fTemp802 + (fTemp724 + (fTemp803 + (fTemp757 + (fTemp727 + (fTemp804 + (fTemp729 + (fTemp807 + (fTemp756 + (fTemp736 + fTemp805))))))))))))))))))))))))))))));
			output23[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec23[((IOTA - iConst46) & 127)])));
			double fTemp825 = (0.0045794399999999997 * fTemp7);
			double fTemp826 = (0.062296362100000002 * fTemp8);
			double fTemp827 = (0.067756715300000006 * fTemp13);
			double fTemp828 = (4.3398999999999997e-06 * fTemp368);
			double fTemp829 = (0.00088787009999999995 * fTemp191);
			double fTemp830 = (0.0020724862000000002 * fTemp200);
			double fTemp831 = (0.028267255200000001 * fTemp217);
			double fTemp832 = (0.079937879200000006 * fTemp51);
			double fTemp833 = (0.00038511570000000002 * fTemp366);
			double fTemp834 = (0.022145379900000001 * fTemp59);
			double fTemp835 = (0.0022203816999999998 * fTemp166);
			double fTemp836 = (0.0110183286 * fTemp250);
			double fTemp837 = (0.10043925250000001 * fTemp90);
			double fTemp838 = (0.0014904110999999999 * fTemp357);
			double fTemp839 = (0.016111082200000001 * fTemp98);
			double fTemp840 = (0.00085654820000000001 * fTemp158);
			double fTemp841 = (0.0127478426 * fTemp280);
			double fTemp842 = (0.1178827425 * fTemp306);
			double fTemp843 = (0.0010244061999999999 * fTemp151);
			double fTemp844 = (0.0145768896 * fTemp318);
			double fTemp845 = (0.064531995100000003 * fTemp335);
			double fTemp846 = (0.10729538080000001 * fTemp343);
			double fTemp847 = (0.00013496299999999999 * fTemp145);
			double fTemp848 = (0.1059349249 * fTemp119);
			double fTemp849 = (0.079211325099999993 * fTemp130);
			double fTemp850 = (0.029716256100000001 * fTemp337);
			double fTemp851 = (0.021712743199999999 * fTemp127);
			double fTemp852 = (0.065704865299999998 * fTemp124);
			double fTemp853 = (2.6056800000000001e-05 * fTemp170);
			double fTemp854 = (0.0010293005000000001 * fTemp172);
			double fTemp855 = (0.021867207100000001 * fTemp174);
			double fTemp856 = (0.054287144500000002 * fTemp10);
			double fTemp857 = (0.038554597599999997 * fTemp12);
			double fTemp858 = (0.1246986673 * fTemp176);
			double fTemp859 = (0.091257016100000005 * fTemp15);
			double fTemp860 = (0.0018004073000000001 * fTemp168);
			double fTemp861 = (0.0021434651999999998 * fTemp178);
			double fTemp862 = (0.014276636699999999 * fTemp180);
			double fTemp863 = (0.0026856243999999999 * fTemp182);
			double fTemp864 = (0.0222326178 * fTemp208);
			double fTemp865 = (0.0544339894 * fTemp24);
			double fTemp866 = (0.0454774555 * fTemp33);
			double fTemp867 = (0.086408781399999995 * fTemp42);
			double fTemp868 = (0.0915303217 * fTemp226);
			double fTemp869 = (0.0052870462000000002 * fTemp68);
			double fTemp870 = (0.00056442129999999995 * fTemp234);
			double fTemp871 = (0.017590550699999999 * fTemp242);
			double fTemp872 = (0.056420539499999998 * fTemp258);
			double fTemp873 = (0.0571380259 * fTemp75);
			double fTemp874 = (0.059239951899999997 * fTemp82);
			double fTemp875 = (0.094954179400000005 * fTemp266);
			double fTemp876 = (0.0092865776999999997 * fTemp273);
			double fTemp877 = (0.0472628821 * fTemp286);
			double fTemp878 = (0.067067680899999996 * fTemp293);
			double fTemp879 = (0.0090471006 * fTemp299);
			double fTemp880 = (0.079616049699999997 * fTemp312);
			double fTemp881 = (0.0060864989 * fTemp349);
			double fTemp882 = (0.025801310000000001 * fTemp323);
			double fTemp883 = (0.061052835 * fTemp329);
			double fTemp884 = (0.043518627599999998 * fTemp104);
			double fTemp885 = (0.0060009460000000001 * fTemp109);
			double fTemp886 = (0.037394059 * fTemp114);
			double fTemp887 = (0.012361960599999999 * fTemp134);
			double fTemp888 = (0.010164259599999999 * fTemp139);
			fVec24[0] = ((fTemp825 + (fTemp826 + (fTemp827 + (fTemp828 + (fTemp829 + (fTemp830 + (fTemp831 + (fTemp832 + (fTemp833 + (fTemp834 + (fTemp835 + (fTemp836 + (fTemp837 + (fTemp838 + (fTemp839 + (fTemp840 + (fTemp841 + (fTemp842 + (fTemp843 + (fTemp844 + (fTemp845 + (fTemp846 + (fTemp847 + (fTemp848 + ((fTemp849 + (fTemp850 + fTemp851)) + fTemp852))))))))))))))))))))))))) - (fTemp853 + (fTemp854 + (fTemp855 + (fTemp856 + (fTemp857 + (fTemp858 + (fTemp859 + (fTemp860 + (fTemp861 + (fTemp862 + (fTemp863 + (fTemp864 + (fTemp865 + (fTemp866 + (fTemp867 + (fTemp868 + (fTemp869 + (fTemp870 + (fTemp871 + (fTemp872 + (fTemp873 + (fTemp874 + (fTemp875 + (fTemp876 + (fTemp877 + (fTemp878 + (fTemp879 + (fTemp880 + (fTemp881 + (fTemp882 + (fTemp883 + (fTemp884 + (fTemp885 + (fTemp886 + (fTemp887 + fTemp888))))))))))))))))))))))))))))))))))));
			output24[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec24[iConst47])));
			double fTemp889 = (0.0018004073000000001 * fTemp8);
			double fTemp890 = (0.067756715300000006 * fTemp12);
			double fTemp891 = (0.038554597599999997 * fTemp13);
			double fTemp892 = (0.062296362100000002 * fTemp168);
			double fTemp893 = (0.079937879200000006 * fTemp33);
			double fTemp894 = (0.0454774555 * fTemp51);
			double fTemp895 = (0.028267255200000001 * fTemp366);
			double fTemp896 = (0.00085654820000000001 * fTemp234);
			double fTemp897 = (0.10043925250000001 * fTemp75);
			double fTemp898 = (0.0571380259 * fTemp90);
			double fTemp899 = (0.0110183286 * fTemp357);
			double fTemp900 = (0.00056442129999999995 * fTemp158);
			double fTemp901 = (0.1178827425 * fTemp293);
			double fTemp902 = (0.067067680899999996 * fTemp306);
			double fTemp903 = (0.0127478426 * fTemp151);
			double fTemp904 = (0.10729538080000001 * fTemp329);
			double fTemp905 = (0.061052835 * fTemp343);
			double fTemp906 = (0.0145768896 * fTemp145);
			double fTemp907 = (0.065704865299999998 * fTemp114);
			double fTemp908 = (0.037394059 * fTemp124);
			double fTemp909 = (0.021712743199999999 * fTemp134);
			double fTemp910 = (0.012361960599999999 * fTemp127);
			double fTemp911 = (4.3398999999999997e-06 * fTemp170);
			double fTemp912 = (0.014276636699999999 * fTemp7);
			double fTemp913 = (0.0045794399999999997 * fTemp180);
			double fTemp914 = (2.6056800000000001e-05 * fTemp368);
			double fTemp915 = (0.0052870462000000002 * fTemp200);
			double fTemp916 = (0.00038511570000000002 * fTemp217);
			double fTemp917 = (0.0020724862000000002 * fTemp68);
			double fTemp918 = (0.0014904110999999999 * fTemp250);
			double fTemp919 = (0.0010244061999999999 * fTemp280);
			double fTemp920 = (0.00013496299999999999 * fTemp318);
			fVec25[0] = ((fTemp854 + (fTemp889 + (fTemp856 + (fTemp890 + (fTemp891 + (fTemp859 + (fTemp892 + (fTemp863 + (fTemp865 + (fTemp893 + (fTemp894 + (fTemp868 + (fTemp895 + (fTemp834 + (fTemp896 + (fTemp872 + (fTemp897 + (fTemp898 + (fTemp875 + (fTemp899 + (fTemp839 + (fTemp900 + (fTemp877 + (fTemp901 + (fTemp902 + (fTemp880 + (fTemp903 + (fTemp882 + (fTemp904 + (fTemp845 + (fTemp905 + (fTemp884 + (fTemp906 + (fTemp885 + (fTemp907 + (fTemp848 + (fTemp908 + (fTemp888 + (fTemp909 + (fTemp849 + (fTemp850 + fTemp910))))))))))))))))))))))))))))))))))))))))) - (fTemp911 + (fTemp912 + (fTemp855 + (fTemp858 + (fTemp861 + (fTemp913 + (fTemp914 + (fTemp829 + (fTemp915 + (fTemp864 + (fTemp916 + (fTemp867 + (fTemp917 + (fTemp835 + (fTemp871 + (fTemp918 + (fTemp874 + (fTemp876 + (fTemp919 + (fTemp879 + (fTemp881 + fTemp920))))))))))))))))))))));
			output25[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec25[iConst47])));
			double fTemp921 = (fTemp850 + fTemp849);
			fVec26[0] = ((fTemp853 + (fTemp857 + (fTemp860 + (fTemp862 + (fTemp829 + (fTemp866 + (fTemp834 + (fTemp869 + (fTemp835 + (fTemp870 + (fTemp873 + (fTemp839 + (fTemp878 + (fTemp883 + (fTemp845 + (fTemp886 + (fTemp848 + (fTemp887 + fTemp921)))))))))))))))))) - (fTemp854 + (fTemp825 + (fTemp855 + (fTemp826 + (fTemp856 + (fTemp858 + (fTemp827 + (fTemp859 + (fTemp861 + (fTemp863 + (fTemp828 + (fTemp830 + (fTemp864 + (fTemp831 + (fTemp865 + (fTemp867 + (fTemp832 + (fTemp868 + (fTemp833 + (fTemp871 + (fTemp836 + (fTemp872 + (fTemp874 + (fTemp837 + (fTemp875 + (fTemp838 + (fTemp840 + (fTemp876 + (fTemp841 + (fTemp877 + (fTemp879 + (fTemp842 + (fTemp880 + (fTemp843 + (fTemp881 + (fTemp844 + (fTemp882 + (fTemp846 + (fTemp884 + (fTemp847 + (fTemp885 + (fTemp852 + (fTemp851 + fTemp888))))))))))))))))))))))))))))))))))))))))))));
			output26[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec26[iConst47])));
			fVec27[0] = ((fTemp911 + (fTemp854 + (fTemp912 + (fTemp856 + (fTemp859 + (fTemp913 + (fTemp863 + (fTemp914 + (fTemp915 + (fTemp916 + (fTemp865 + (fTemp868 + (fTemp834 + (fTemp917 + (fTemp918 + (fTemp872 + (fTemp875 + (fTemp839 + (fTemp919 + (fTemp877 + (fTemp880 + (fTemp920 + (fTemp882 + (fTemp845 + (fTemp884 + (fTemp885 + (fTemp848 + (fTemp888 + fTemp921)))))))))))))))))))))))))))) - (fTemp855 + (fTemp889 + (fTemp890 + (fTemp858 + (fTemp891 + (fTemp892 + (fTemp861 + (fTemp829 + (fTemp864 + (fTemp893 + (fTemp867 + (fTemp894 + (fTemp895 + (fTemp835 + (fTemp896 + (fTemp871 + (fTemp897 + (fTemp874 + (fTemp898 + (fTemp899 + (fTemp900 + (fTemp876 + (fTemp901 + (fTemp879 + (fTemp902 + (fTemp903 + (fTemp881 + (fTemp904 + (fTemp905 + (fTemp906 + (fTemp907 + (fTemp908 + (fTemp910 + fTemp909))))))))))))))))))))))))))))))))));
			output27[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec27[iConst47])));
			output28[i] = FAUSTFLOAT((fRec0[0] * (((0.037911060599999998 * fTemp174) + ((0.30936045239999999 * fTemp176) + ((0.010942965400000001 * fTemp178) + ((0.039758849700000001 * fTemp208) + (((0.031182260400000002 * fTemp242) + (((0.015989956499999999 * fTemp273) + ((0.19689938009999999 * fTemp299) + ((0.076824149199999997 * fTemp335) + (0.0157391549 * fTemp349)))) + (0.24298715779999999 * fTemp82))) + (0.2514422308 * fTemp42)))))) - ((0.043759243199999999 * fTemp59) + ((((0.044351905699999999 * fTemp130) + (0.0011972612000000001 * fTemp337)) + (0.031964203400000002 * fTemp119)) + (0.0305905915 * fTemp98))))));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec27[1] = fRec27[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec16[1] = fRec16[0];
			fRec15[1] = fRec15[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec46[1] = fRec46[0];
			fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec29[1] = fRec29[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fRec65[1] = fRec65[0];
			fRec63[1] = fRec63[0];
			fRec62[1] = fRec62[0];
			fRec60[1] = fRec60[0];
			fRec59[1] = fRec59[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fRec54[1] = fRec54[0];
			fRec53[1] = fRec53[0];
			fRec51[1] = fRec51[0];
			fRec50[1] = fRec50[0];
			fRec48[1] = fRec48[0];
			fRec47[2] = fRec47[1];
			fRec47[1] = fRec47[0];
			fRec84[1] = fRec84[0];
			fRec82[1] = fRec82[0];
			fRec81[1] = fRec81[0];
			fRec79[1] = fRec79[0];
			fRec78[1] = fRec78[0];
			fRec76[1] = fRec76[0];
			fRec75[1] = fRec75[0];
			fRec73[1] = fRec73[0];
			fRec72[1] = fRec72[0];
			fRec70[1] = fRec70[0];
			fRec69[1] = fRec69[0];
			fRec67[1] = fRec67[0];
			fRec66[2] = fRec66[1];
			fRec66[1] = fRec66[0];
			fRec103[1] = fRec103[0];
			fRec101[1] = fRec101[0];
			fRec100[1] = fRec100[0];
			fRec98[1] = fRec98[0];
			fRec97[1] = fRec97[0];
			fRec95[1] = fRec95[0];
			fRec94[1] = fRec94[0];
			fRec92[1] = fRec92[0];
			fRec91[1] = fRec91[0];
			fRec89[1] = fRec89[0];
			fRec88[1] = fRec88[0];
			fRec86[1] = fRec86[0];
			fRec85[2] = fRec85[1];
			fRec85[1] = fRec85[0];
			fRec122[1] = fRec122[0];
			fRec120[1] = fRec120[0];
			fRec119[1] = fRec119[0];
			fRec117[1] = fRec117[0];
			fRec116[1] = fRec116[0];
			fRec114[1] = fRec114[0];
			fRec113[1] = fRec113[0];
			fRec111[1] = fRec111[0];
			fRec110[1] = fRec110[0];
			fRec108[1] = fRec108[0];
			fRec107[1] = fRec107[0];
			fRec105[1] = fRec105[0];
			fRec104[2] = fRec104[1];
			fRec104[1] = fRec104[0];
			fRec138[1] = fRec138[0];
			fRec136[1] = fRec136[0];
			fRec135[1] = fRec135[0];
			fRec133[1] = fRec133[0];
			fRec132[1] = fRec132[0];
			fRec130[1] = fRec130[0];
			fRec129[1] = fRec129[0];
			fRec127[1] = fRec127[0];
			fRec126[1] = fRec126[0];
			fRec124[1] = fRec124[0];
			fRec123[2] = fRec123[1];
			fRec123[1] = fRec123[0];
			fRec154[1] = fRec154[0];
			fRec152[1] = fRec152[0];
			fRec151[1] = fRec151[0];
			fRec149[1] = fRec149[0];
			fRec148[1] = fRec148[0];
			fRec146[1] = fRec146[0];
			fRec145[1] = fRec145[0];
			fRec143[1] = fRec143[0];
			fRec142[1] = fRec142[0];
			fRec140[1] = fRec140[0];
			fRec139[2] = fRec139[1];
			fRec139[1] = fRec139[0];
			fRec170[1] = fRec170[0];
			fRec168[1] = fRec168[0];
			fRec167[1] = fRec167[0];
			fRec165[1] = fRec165[0];
			fRec164[1] = fRec164[0];
			fRec162[1] = fRec162[0];
			fRec161[1] = fRec161[0];
			fRec159[1] = fRec159[0];
			fRec158[1] = fRec158[0];
			fRec156[1] = fRec156[0];
			fRec155[2] = fRec155[1];
			fRec155[1] = fRec155[0];
			fRec186[1] = fRec186[0];
			fRec184[1] = fRec184[0];
			fRec183[1] = fRec183[0];
			fRec181[1] = fRec181[0];
			fRec180[1] = fRec180[0];
			fRec178[1] = fRec178[0];
			fRec177[1] = fRec177[0];
			fRec175[1] = fRec175[0];
			fRec174[1] = fRec174[0];
			fRec172[1] = fRec172[0];
			fRec171[2] = fRec171[1];
			fRec171[1] = fRec171[0];
			fRec196[1] = fRec196[0];
			fRec194[1] = fRec194[0];
			fRec193[1] = fRec193[0];
			fRec191[1] = fRec191[0];
			fRec190[1] = fRec190[0];
			fRec188[1] = fRec188[0];
			fRec187[2] = fRec187[1];
			fRec187[1] = fRec187[0];
			fRec203[1] = fRec203[0];
			fRec201[1] = fRec201[0];
			fRec200[1] = fRec200[0];
			fRec198[1] = fRec198[0];
			fRec197[2] = fRec197[1];
			fRec197[1] = fRec197[0];
			fRec210[1] = fRec210[0];
			fRec208[1] = fRec208[0];
			fRec207[1] = fRec207[0];
			fRec205[1] = fRec205[0];
			fRec204[2] = fRec204[1];
			fRec204[1] = fRec204[0];
			fRec217[1] = fRec217[0];
			fRec215[1] = fRec215[0];
			fRec214[1] = fRec214[0];
			fRec212[1] = fRec212[0];
			fRec211[2] = fRec211[1];
			fRec211[1] = fRec211[0];
			fRec224[1] = fRec224[0];
			fRec222[1] = fRec222[0];
			fRec221[1] = fRec221[0];
			fRec219[1] = fRec219[0];
			fRec218[2] = fRec218[1];
			fRec218[1] = fRec218[0];
			fRec228[1] = fRec228[0];
			fRec226[1] = fRec226[0];
			fRec225[2] = fRec225[1];
			fRec225[1] = fRec225[0];
			fRec232[1] = fRec232[0];
			fRec230[1] = fRec230[0];
			fRec229[2] = fRec229[1];
			fRec229[1] = fRec229[0];
			fRec236[1] = fRec236[0];
			fRec234[1] = fRec234[0];
			fRec233[2] = fRec233[1];
			fRec233[1] = fRec233[0];
			fRec243[1] = fRec243[0];
			fRec241[1] = fRec241[0];
			fRec240[1] = fRec240[0];
			fRec238[1] = fRec238[0];
			fRec237[2] = fRec237[1];
			fRec237[1] = fRec237[0];
			fRec253[1] = fRec253[0];
			fRec251[1] = fRec251[0];
			fRec250[1] = fRec250[0];
			fRec248[1] = fRec248[0];
			fRec247[1] = fRec247[0];
			fRec245[1] = fRec245[0];
			fRec244[2] = fRec244[1];
			fRec244[1] = fRec244[0];
			fRec266[1] = fRec266[0];
			fRec264[1] = fRec264[0];
			fRec263[1] = fRec263[0];
			fRec261[1] = fRec261[0];
			fRec260[1] = fRec260[0];
			fRec258[1] = fRec258[0];
			fRec257[1] = fRec257[0];
			fRec255[1] = fRec255[0];
			fRec254[2] = fRec254[1];
			fRec254[1] = fRec254[0];
			fRec282[1] = fRec282[0];
			fRec280[1] = fRec280[0];
			fRec279[1] = fRec279[0];
			fRec277[1] = fRec277[0];
			fRec276[1] = fRec276[0];
			fRec274[1] = fRec274[0];
			fRec273[1] = fRec273[0];
			fRec271[1] = fRec271[0];
			fRec270[1] = fRec270[0];
			fRec268[1] = fRec268[0];
			fRec267[2] = fRec267[1];
			fRec267[1] = fRec267[0];
			fRec301[1] = fRec301[0];
			fRec299[1] = fRec299[0];
			fRec298[1] = fRec298[0];
			fRec296[1] = fRec296[0];
			fRec295[1] = fRec295[0];
			fRec293[1] = fRec293[0];
			fRec292[1] = fRec292[0];
			fRec290[1] = fRec290[0];
			fRec289[1] = fRec289[0];
			fRec287[1] = fRec287[0];
			fRec286[1] = fRec286[0];
			fRec284[1] = fRec284[0];
			fRec283[2] = fRec283[1];
			fRec283[1] = fRec283[0];
			fRec302[2] = fRec302[1];
			fRec302[1] = fRec302[0];
			fRec303[2] = fRec303[1];
			fRec303[1] = fRec303[0];
			fRec304[2] = fRec304[1];
			fRec304[1] = fRec304[0];
			fRec305[2] = fRec305[1];
			fRec305[1] = fRec305[0];
			fRec306[2] = fRec306[1];
			fRec306[1] = fRec306[0];
			fRec307[2] = fRec307[1];
			fRec307[1] = fRec307[0];
			fRec308[2] = fRec308[1];
			fRec308[1] = fRec308[0];
			fRec309[2] = fRec309[1];
			fRec309[1] = fRec309[0];
			fRec328[1] = fRec328[0];
			fRec326[1] = fRec326[0];
			fRec325[1] = fRec325[0];
			fRec323[1] = fRec323[0];
			fRec322[1] = fRec322[0];
			fRec320[1] = fRec320[0];
			fRec319[1] = fRec319[0];
			fRec317[1] = fRec317[0];
			fRec316[1] = fRec316[0];
			fRec314[1] = fRec314[0];
			fRec313[1] = fRec313[0];
			fRec311[1] = fRec311[0];
			fRec310[2] = fRec310[1];
			fRec310[1] = fRec310[0];
			fRec347[1] = fRec347[0];
			fRec345[1] = fRec345[0];
			fRec344[1] = fRec344[0];
			fRec342[1] = fRec342[0];
			fRec341[1] = fRec341[0];
			fRec339[1] = fRec339[0];
			fRec338[1] = fRec338[0];
			fRec336[1] = fRec336[0];
			fRec335[1] = fRec335[0];
			fRec333[1] = fRec333[0];
			fRec332[1] = fRec332[0];
			fRec330[1] = fRec330[0];
			fRec329[2] = fRec329[1];
			fRec329[1] = fRec329[0];
			fRec366[1] = fRec366[0];
			fRec364[1] = fRec364[0];
			fRec363[1] = fRec363[0];
			fRec361[1] = fRec361[0];
			fRec360[1] = fRec360[0];
			fRec358[1] = fRec358[0];
			fRec357[1] = fRec357[0];
			fRec355[1] = fRec355[0];
			fRec354[1] = fRec354[0];
			fRec352[1] = fRec352[0];
			fRec351[1] = fRec351[0];
			fRec349[1] = fRec349[0];
			fRec348[2] = fRec348[1];
			fRec348[1] = fRec348[0];
			fRec385[1] = fRec385[0];
			fRec383[1] = fRec383[0];
			fRec382[1] = fRec382[0];
			fRec380[1] = fRec380[0];
			fRec379[1] = fRec379[0];
			fRec377[1] = fRec377[0];
			fRec376[1] = fRec376[0];
			fRec374[1] = fRec374[0];
			fRec373[1] = fRec373[0];
			fRec371[1] = fRec371[0];
			fRec370[1] = fRec370[0];
			fRec368[1] = fRec368[0];
			fRec367[2] = fRec367[1];
			fRec367[1] = fRec367[0];
			fRec404[1] = fRec404[0];
			fRec402[1] = fRec402[0];
			fRec401[1] = fRec401[0];
			fRec399[1] = fRec399[0];
			fRec398[1] = fRec398[0];
			fRec396[1] = fRec396[0];
			fRec395[1] = fRec395[0];
			fRec393[1] = fRec393[0];
			fRec392[1] = fRec392[0];
			fRec390[1] = fRec390[0];
			fRec389[1] = fRec389[0];
			fRec387[1] = fRec387[0];
			fRec386[2] = fRec386[1];
			fRec386[1] = fRec386[0];
			fRec420[1] = fRec420[0];
			fRec418[1] = fRec418[0];
			fRec417[1] = fRec417[0];
			fRec415[1] = fRec415[0];
			fRec414[1] = fRec414[0];
			fRec412[1] = fRec412[0];
			fRec411[1] = fRec411[0];
			fRec409[1] = fRec409[0];
			fRec408[1] = fRec408[0];
			fRec406[1] = fRec406[0];
			fRec405[2] = fRec405[1];
			fRec405[1] = fRec405[0];
			fRec436[1] = fRec436[0];
			fRec434[1] = fRec434[0];
			fRec433[1] = fRec433[0];
			fRec431[1] = fRec431[0];
			fRec430[1] = fRec430[0];
			fRec428[1] = fRec428[0];
			fRec427[1] = fRec427[0];
			fRec425[1] = fRec425[0];
			fRec424[1] = fRec424[0];
			fRec422[1] = fRec422[0];
			fRec421[2] = fRec421[1];
			fRec421[1] = fRec421[0];
			fRec452[1] = fRec452[0];
			fRec450[1] = fRec450[0];
			fRec449[1] = fRec449[0];
			fRec447[1] = fRec447[0];
			fRec446[1] = fRec446[0];
			fRec444[1] = fRec444[0];
			fRec443[1] = fRec443[0];
			fRec441[1] = fRec441[0];
			fRec440[1] = fRec440[0];
			fRec438[1] = fRec438[0];
			fRec437[2] = fRec437[1];
			fRec437[1] = fRec437[0];
			fRec468[1] = fRec468[0];
			fRec466[1] = fRec466[0];
			fRec465[1] = fRec465[0];
			fRec463[1] = fRec463[0];
			fRec462[1] = fRec462[0];
			fRec460[1] = fRec460[0];
			fRec459[1] = fRec459[0];
			fRec457[1] = fRec457[0];
			fRec456[1] = fRec456[0];
			fRec454[1] = fRec454[0];
			fRec453[2] = fRec453[1];
			fRec453[1] = fRec453[0];
			fRec484[1] = fRec484[0];
			fRec482[1] = fRec482[0];
			fRec481[1] = fRec481[0];
			fRec479[1] = fRec479[0];
			fRec478[1] = fRec478[0];
			fRec476[1] = fRec476[0];
			fRec475[1] = fRec475[0];
			fRec473[1] = fRec473[0];
			fRec472[1] = fRec472[0];
			fRec470[1] = fRec470[0];
			fRec469[2] = fRec469[1];
			fRec469[1] = fRec469[0];
			fRec497[1] = fRec497[0];
			fRec495[1] = fRec495[0];
			fRec494[1] = fRec494[0];
			fRec492[1] = fRec492[0];
			fRec491[1] = fRec491[0];
			fRec489[1] = fRec489[0];
			fRec488[1] = fRec488[0];
			fRec486[1] = fRec486[0];
			fRec485[2] = fRec485[1];
			fRec485[1] = fRec485[0];
			fRec510[1] = fRec510[0];
			fRec508[1] = fRec508[0];
			fRec507[1] = fRec507[0];
			fRec505[1] = fRec505[0];
			fRec504[1] = fRec504[0];
			fRec502[1] = fRec502[0];
			fRec501[1] = fRec501[0];
			fRec499[1] = fRec499[0];
			fRec498[2] = fRec498[1];
			fRec498[1] = fRec498[0];
			fRec523[1] = fRec523[0];
			fRec521[1] = fRec521[0];
			fRec520[1] = fRec520[0];
			fRec518[1] = fRec518[0];
			fRec517[1] = fRec517[0];
			fRec515[1] = fRec515[0];
			fRec514[1] = fRec514[0];
			fRec512[1] = fRec512[0];
			fRec511[2] = fRec511[1];
			fRec511[1] = fRec511[0];
			fRec536[1] = fRec536[0];
			fRec534[1] = fRec534[0];
			fRec533[1] = fRec533[0];
			fRec531[1] = fRec531[0];
			fRec530[1] = fRec530[0];
			fRec528[1] = fRec528[0];
			fRec527[1] = fRec527[0];
			fRec525[1] = fRec525[0];
			fRec524[2] = fRec524[1];
			fRec524[1] = fRec524[0];
			fRec549[1] = fRec549[0];
			fRec547[1] = fRec547[0];
			fRec546[1] = fRec546[0];
			fRec544[1] = fRec544[0];
			fRec543[1] = fRec543[0];
			fRec541[1] = fRec541[0];
			fRec540[1] = fRec540[0];
			fRec538[1] = fRec538[0];
			fRec537[2] = fRec537[1];
			fRec537[1] = fRec537[0];
			fRec562[1] = fRec562[0];
			fRec560[1] = fRec560[0];
			fRec559[1] = fRec559[0];
			fRec557[1] = fRec557[0];
			fRec556[1] = fRec556[0];
			fRec554[1] = fRec554[0];
			fRec553[1] = fRec553[0];
			fRec551[1] = fRec551[0];
			fRec550[2] = fRec550[1];
			fRec550[1] = fRec550[0];
			fRec575[1] = fRec575[0];
			fRec573[1] = fRec573[0];
			fRec572[1] = fRec572[0];
			fRec570[1] = fRec570[0];
			fRec569[1] = fRec569[0];
			fRec567[1] = fRec567[0];
			fRec566[1] = fRec566[0];
			fRec564[1] = fRec564[0];
			fRec563[2] = fRec563[1];
			fRec563[1] = fRec563[0];
			fRec585[1] = fRec585[0];
			fRec583[1] = fRec583[0];
			fRec582[1] = fRec582[0];
			fRec580[1] = fRec580[0];
			fRec579[1] = fRec579[0];
			fRec577[1] = fRec577[0];
			fRec576[2] = fRec576[1];
			fRec576[1] = fRec576[0];
			fRec595[1] = fRec595[0];
			fRec593[1] = fRec593[0];
			fRec592[1] = fRec592[0];
			fRec590[1] = fRec590[0];
			fRec589[1] = fRec589[0];
			fRec587[1] = fRec587[0];
			fRec586[2] = fRec586[1];
			fRec586[1] = fRec586[0];
			fRec605[1] = fRec605[0];
			fRec603[1] = fRec603[0];
			fRec602[1] = fRec602[0];
			fRec600[1] = fRec600[0];
			fRec599[1] = fRec599[0];
			fRec597[1] = fRec597[0];
			fRec596[2] = fRec596[1];
			fRec596[1] = fRec596[0];
			fRec615[1] = fRec615[0];
			fRec613[1] = fRec613[0];
			fRec612[1] = fRec612[0];
			fRec610[1] = fRec610[0];
			fRec609[1] = fRec609[0];
			fRec607[1] = fRec607[0];
			fRec606[2] = fRec606[1];
			fRec606[1] = fRec606[0];
			fRec616[2] = fRec616[1];
			fRec616[1] = fRec616[0];
			fRec626[1] = fRec626[0];
			fRec624[1] = fRec624[0];
			fRec623[1] = fRec623[0];
			fRec621[1] = fRec621[0];
			fRec620[1] = fRec620[0];
			fRec618[1] = fRec618[0];
			fRec617[2] = fRec617[1];
			fRec617[1] = fRec617[0];
			fRec639[1] = fRec639[0];
			fRec637[1] = fRec637[0];
			fRec636[1] = fRec636[0];
			fRec634[1] = fRec634[0];
			fRec633[1] = fRec633[0];
			fRec631[1] = fRec631[0];
			fRec630[1] = fRec630[0];
			fRec628[1] = fRec628[0];
			fRec627[2] = fRec627[1];
			fRec627[1] = fRec627[0];
			fRec655[1] = fRec655[0];
			fRec653[1] = fRec653[0];
			fRec652[1] = fRec652[0];
			fRec650[1] = fRec650[0];
			fRec649[1] = fRec649[0];
			fRec647[1] = fRec647[0];
			fRec646[1] = fRec646[0];
			fRec644[1] = fRec644[0];
			fRec643[1] = fRec643[0];
			fRec641[1] = fRec641[0];
			fRec640[2] = fRec640[1];
			fRec640[1] = fRec640[0];
			fRec674[1] = fRec674[0];
			fRec672[1] = fRec672[0];
			fRec671[1] = fRec671[0];
			fRec669[1] = fRec669[0];
			fRec668[1] = fRec668[0];
			fRec666[1] = fRec666[0];
			fRec665[1] = fRec665[0];
			fRec663[1] = fRec663[0];
			fRec662[1] = fRec662[0];
			fRec660[1] = fRec660[0];
			fRec659[1] = fRec659[0];
			fRec657[1] = fRec657[0];
			fRec656[2] = fRec656[1];
			fRec656[1] = fRec656[0];
			fRec675[2] = fRec675[1];
			fRec675[1] = fRec675[0];
			IOTA = (IOTA + 1);
			for (int j0 = 11; (j0 > 0); j0 = (j0 - 1)) {
				fVec24[j0] = fVec24[(j0 - 1)];
				
			}
			for (int j1 = 11; (j1 > 0); j1 = (j1 - 1)) {
				fVec25[j1] = fVec25[(j1 - 1)];
				
			}
			for (int j2 = 11; (j2 > 0); j2 = (j2 - 1)) {
				fVec26[j2] = fVec26[(j2 - 1)];
				
			}
			for (int j3 = 11; (j3 > 0); j3 = (j3 - 1)) {
				fVec27[j3] = fVec27[(j3 - 1)];
				
			}
			
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
