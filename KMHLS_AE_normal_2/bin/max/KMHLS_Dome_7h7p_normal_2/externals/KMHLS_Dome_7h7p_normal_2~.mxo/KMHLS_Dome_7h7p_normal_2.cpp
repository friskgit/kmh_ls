/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMHLS_Dome_7h7p_normal_2"
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
	double fRec141[2];
	double fRec139[2];
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
	double fConst14;
	double fConst15;
	double fConst16;
	double fConst17;
	double fConst18;
	double fConst19;
	double fConst20;
	double fConst21;
	double fConst22;
	double fRec157[2];
	double fRec155[2];
	double fRec154[2];
	double fRec152[2];
	double fRec151[2];
	double fRec149[2];
	double fRec148[2];
	double fRec146[2];
	double fRec145[2];
	double fRec143[2];
	double fRec142[3];
	double fRec173[2];
	double fRec171[2];
	double fRec170[2];
	double fRec168[2];
	double fRec167[2];
	double fRec165[2];
	double fRec164[2];
	double fRec162[2];
	double fRec161[2];
	double fRec159[2];
	double fRec158[3];
	double fRec189[2];
	double fRec187[2];
	double fRec186[2];
	double fRec184[2];
	double fRec183[2];
	double fRec181[2];
	double fRec180[2];
	double fRec178[2];
	double fRec177[2];
	double fRec175[2];
	double fRec174[3];
	double fRec205[2];
	double fRec203[2];
	double fRec202[2];
	double fRec200[2];
	double fRec199[2];
	double fRec197[2];
	double fRec196[2];
	double fRec194[2];
	double fRec193[2];
	double fRec191[2];
	double fRec190[3];
	double fConst23;
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fConst28;
	double fConst29;
	double fRec218[2];
	double fRec216[2];
	double fRec215[2];
	double fRec213[2];
	double fRec212[2];
	double fRec210[2];
	double fRec209[2];
	double fRec207[2];
	double fRec206[3];
	double fRec231[2];
	double fRec229[2];
	double fRec228[2];
	double fRec226[2];
	double fRec225[2];
	double fRec223[2];
	double fRec222[2];
	double fRec220[2];
	double fRec219[3];
	double fConst30;
	double fConst31;
	double fConst32;
	double fConst33;
	double fConst34;
	double fConst35;
	double fRec241[2];
	double fRec239[2];
	double fRec238[2];
	double fRec236[2];
	double fRec235[2];
	double fRec233[2];
	double fRec232[3];
	double fRec251[2];
	double fRec249[2];
	double fRec248[2];
	double fRec246[2];
	double fRec245[2];
	double fRec243[2];
	double fRec242[3];
	double fConst36;
	double fConst37;
	double fConst38;
	double fConst39;
	double fRec258[2];
	double fRec256[2];
	double fRec255[2];
	double fRec253[2];
	double fRec252[3];
	double fRec265[2];
	double fRec263[2];
	double fRec262[2];
	double fRec260[2];
	double fRec259[3];
	double fRec272[2];
	double fRec270[2];
	double fRec269[2];
	double fRec267[2];
	double fRec266[3];
	double fConst40;
	double fConst41;
	double fConst42;
	double fRec276[2];
	double fRec274[2];
	double fRec273[3];
	double fRec280[2];
	double fRec278[2];
	double fRec277[3];
	double fRec281[3];
	double fRec285[2];
	double fRec283[2];
	double fRec282[3];
	double fRec292[2];
	double fRec290[2];
	double fRec289[2];
	double fRec287[2];
	double fRec286[3];
	double fRec302[2];
	double fRec300[2];
	double fRec299[2];
	double fRec297[2];
	double fRec296[2];
	double fRec294[2];
	double fRec293[3];
	double fRec315[2];
	double fRec313[2];
	double fRec312[2];
	double fRec310[2];
	double fRec309[2];
	double fRec307[2];
	double fRec306[2];
	double fRec304[2];
	double fRec303[3];
	double fRec331[2];
	double fRec329[2];
	double fRec328[2];
	double fRec326[2];
	double fRec325[2];
	double fRec323[2];
	double fRec322[2];
	double fRec320[2];
	double fRec319[2];
	double fRec317[2];
	double fRec316[3];
	double fRec350[2];
	double fRec348[2];
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
	double fRec332[3];
	double fRec351[3];
	double fRec352[3];
	double fRec353[3];
	double fRec354[3];
	double fRec355[3];
	double fRec356[3];
	double fRec357[3];
	double fRec358[3];
	double fRec377[2];
	double fRec375[2];
	double fRec374[2];
	double fRec372[2];
	double fRec371[2];
	double fRec369[2];
	double fRec368[2];
	double fRec366[2];
	double fRec365[2];
	double fRec363[2];
	double fRec362[2];
	double fRec360[2];
	double fRec359[3];
	double fRec396[2];
	double fRec394[2];
	double fRec393[2];
	double fRec391[2];
	double fRec390[2];
	double fRec388[2];
	double fRec387[2];
	double fRec385[2];
	double fRec384[2];
	double fRec382[2];
	double fRec381[2];
	double fRec379[2];
	double fRec378[3];
	double fRec415[2];
	double fRec413[2];
	double fRec412[2];
	double fRec410[2];
	double fRec409[2];
	double fRec407[2];
	double fRec406[2];
	double fRec404[2];
	double fRec403[2];
	double fRec401[2];
	double fRec400[2];
	double fRec398[2];
	double fRec397[3];
	double fRec434[2];
	double fRec432[2];
	double fRec431[2];
	double fRec429[2];
	double fRec428[2];
	double fRec426[2];
	double fRec425[2];
	double fRec423[2];
	double fRec422[2];
	double fRec420[2];
	double fRec419[2];
	double fRec417[2];
	double fRec416[3];
	double fRec450[2];
	double fRec448[2];
	double fRec447[2];
	double fRec445[2];
	double fRec444[2];
	double fRec442[2];
	double fRec441[2];
	double fRec439[2];
	double fRec438[2];
	double fRec436[2];
	double fRec435[3];
	double fRec466[2];
	double fRec464[2];
	double fRec463[2];
	double fRec461[2];
	double fRec460[2];
	double fRec458[2];
	double fRec457[2];
	double fRec455[2];
	double fRec454[2];
	double fRec452[2];
	double fRec451[3];
	double fRec482[2];
	double fRec480[2];
	double fRec479[2];
	double fRec477[2];
	double fRec476[2];
	double fRec474[2];
	double fRec473[2];
	double fRec471[2];
	double fRec470[2];
	double fRec468[2];
	double fRec467[3];
	double fRec498[2];
	double fRec496[2];
	double fRec495[2];
	double fRec493[2];
	double fRec492[2];
	double fRec490[2];
	double fRec489[2];
	double fRec487[2];
	double fRec486[2];
	double fRec484[2];
	double fRec483[3];
	double fRec514[2];
	double fRec512[2];
	double fRec511[2];
	double fRec509[2];
	double fRec508[2];
	double fRec506[2];
	double fRec505[2];
	double fRec503[2];
	double fRec502[2];
	double fRec500[2];
	double fRec499[3];
	double fRec527[2];
	double fRec525[2];
	double fRec524[2];
	double fRec522[2];
	double fRec521[2];
	double fRec519[2];
	double fRec518[2];
	double fRec516[2];
	double fRec515[3];
	double fRec540[2];
	double fRec538[2];
	double fRec537[2];
	double fRec535[2];
	double fRec534[2];
	double fRec532[2];
	double fRec531[2];
	double fRec529[2];
	double fRec528[3];
	double fRec553[2];
	double fRec551[2];
	double fRec550[2];
	double fRec548[2];
	double fRec547[2];
	double fRec545[2];
	double fRec544[2];
	double fRec542[2];
	double fRec541[3];
	double fRec566[2];
	double fRec564[2];
	double fRec563[2];
	double fRec561[2];
	double fRec560[2];
	double fRec558[2];
	double fRec557[2];
	double fRec555[2];
	double fRec554[3];
	double fRec579[2];
	double fRec577[2];
	double fRec576[2];
	double fRec574[2];
	double fRec573[2];
	double fRec571[2];
	double fRec570[2];
	double fRec568[2];
	double fRec567[3];
	double fRec589[2];
	double fRec587[2];
	double fRec586[2];
	double fRec584[2];
	double fRec583[2];
	double fRec581[2];
	double fRec580[3];
	double fRec599[2];
	double fRec597[2];
	double fRec596[2];
	double fRec594[2];
	double fRec593[2];
	double fRec591[2];
	double fRec590[3];
	double fRec609[2];
	double fRec607[2];
	double fRec606[2];
	double fRec604[2];
	double fRec603[2];
	double fRec601[2];
	double fRec600[3];
	double fRec616[2];
	double fRec614[2];
	double fRec613[2];
	double fRec611[2];
	double fRec610[3];
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
		m->declare("filename", "KMHLS_Dome_7h7p_normal_2");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMHLS_Dome_7h7p_normal_2");
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
		fConst11 = (1.0 / ((fConst4 * fConst7) * fConst10));
		fConst12 = (0.0 - (116107.78912435773 / (fConst3 * fConst10)));
		fConst13 = (0.0 - (((116107.78912435773 / fConst2) + 332.98278518019771) / (fConst2 * fConst10)));
		fConst14 = ((120.66115605394451 / fConst2) + 1.0);
		fConst15 = (0.0 - (241.32231210788902 / (fConst2 * fConst14)));
		fConst16 = ((((15625.184559991036 / fConst2) + 221.81514994370366) / fConst2) + 1.0);
		fConst17 = (0.0 - (62500.738239964143 / (fConst3 * fConst16)));
		fConst18 = (0.0 - (((62500.738239964143 / fConst2) + 443.63029988740732) / (fConst2 * fConst16)));
		fConst19 = ((((19877.11788698009 / fConst2) + 153.83493032926589) / fConst2) + 1.0);
		fConst20 = (1.0 / ((fConst14 * fConst16) * fConst19));
		fConst21 = (0.0 - (79508.471547920359 / (fConst3 * fConst19)));
		fConst22 = (0.0 - (((79508.471547920359 / fConst2) + 307.66986065853177) / (fConst2 * fConst19)));
		fConst23 = ((((10006.405819239841 / fConst2) + 191.65624865985308) / fConst2) + 1.0);
		fConst24 = (0.0 - (40025.623276959363 / (fConst3 * fConst23)));
		fConst25 = (0.0 - (((40025.623276959363 / fConst2) + 383.31249731970615) / (fConst2 * fConst23)));
		fConst26 = ((((12576.580677230806 / fConst2) + 139.21790889142318) / fConst2) + 1.0);
		fConst27 = (1.0 / (fConst23 * fConst26));
		fConst28 = (0.0 - (50306.322708923224 / (fConst3 * fConst26)));
		fConst29 = (0.0 - (((50306.322708923224 / fConst2) + 278.43581778284636) / (fConst2 * fConst26)));
		fConst30 = ((76.835112288981804 / fConst2) + 1.0);
		fConst31 = (0.0 - (153.67022457796361 / (fConst2 * fConst30)));
		fConst32 = ((((7071.6388713657261 / fConst2) + 121.68938224178397) / fConst2) + 1.0);
		fConst33 = (1.0 / (fConst30 * fConst32));
		fConst34 = (0.0 - (28286.555485462904 / (fConst3 * fConst32)));
		fConst35 = (0.0 - (((28286.555485462904 / fConst2) + 243.37876448356795) / (fConst2 * fConst32)));
		fConst36 = ((((3284.3312440580044 / fConst2) + 99.262247265382882) / fConst2) + 1.0);
		fConst37 = (1.0 / fConst36);
		fConst38 = (0.0 - (13137.324976232017 / (fConst3 * fConst36)));
		fConst39 = (0.0 - (((13137.324976232017 / fConst2) + 198.52449453076576) / (fConst2 * fConst36)));
		fConst40 = ((33.08741575512763 / fConst2) + 1.0);
		fConst41 = (1.0 / fConst40);
		fConst42 = (0.0 - (66.17483151025526 / (fConst2 * fConst40)));
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
			fRec141[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			fRec139[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec138[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec136[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec135[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec133[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec132[l93] = 0.0;
			
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec130[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec129[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fRec127[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec126[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec124[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 3); l99 = (l99 + 1)) {
			fRec123[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 2); l100 = (l100 + 1)) {
			fRec157[l100] = 0.0;
			
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fRec155[l101] = 0.0;
			
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec154[l102] = 0.0;
			
		}
		for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) {
			fRec152[l103] = 0.0;
			
		}
		for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) {
			fRec151[l104] = 0.0;
			
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fRec149[l105] = 0.0;
			
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec148[l106] = 0.0;
			
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fRec146[l107] = 0.0;
			
		}
		for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) {
			fRec145[l108] = 0.0;
			
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec143[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 3); l110 = (l110 + 1)) {
			fRec142[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec173[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec171[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec170[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec168[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec167[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec165[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec164[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec162[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec161[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec159[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 3); l121 = (l121 + 1)) {
			fRec158[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec189[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec187[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec186[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fRec184[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec183[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec181[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec180[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec178[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec177[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 2); l131 = (l131 + 1)) {
			fRec175[l131] = 0.0;
			
		}
		for (int l132 = 0; (l132 < 3); l132 = (l132 + 1)) {
			fRec174[l132] = 0.0;
			
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec205[l133] = 0.0;
			
		}
		for (int l134 = 0; (l134 < 2); l134 = (l134 + 1)) {
			fRec203[l134] = 0.0;
			
		}
		for (int l135 = 0; (l135 < 2); l135 = (l135 + 1)) {
			fRec202[l135] = 0.0;
			
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec200[l136] = 0.0;
			
		}
		for (int l137 = 0; (l137 < 2); l137 = (l137 + 1)) {
			fRec199[l137] = 0.0;
			
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec197[l138] = 0.0;
			
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fRec196[l139] = 0.0;
			
		}
		for (int l140 = 0; (l140 < 2); l140 = (l140 + 1)) {
			fRec194[l140] = 0.0;
			
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fRec193[l141] = 0.0;
			
		}
		for (int l142 = 0; (l142 < 2); l142 = (l142 + 1)) {
			fRec191[l142] = 0.0;
			
		}
		for (int l143 = 0; (l143 < 3); l143 = (l143 + 1)) {
			fRec190[l143] = 0.0;
			
		}
		for (int l144 = 0; (l144 < 2); l144 = (l144 + 1)) {
			fRec218[l144] = 0.0;
			
		}
		for (int l145 = 0; (l145 < 2); l145 = (l145 + 1)) {
			fRec216[l145] = 0.0;
			
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fRec215[l146] = 0.0;
			
		}
		for (int l147 = 0; (l147 < 2); l147 = (l147 + 1)) {
			fRec213[l147] = 0.0;
			
		}
		for (int l148 = 0; (l148 < 2); l148 = (l148 + 1)) {
			fRec212[l148] = 0.0;
			
		}
		for (int l149 = 0; (l149 < 2); l149 = (l149 + 1)) {
			fRec210[l149] = 0.0;
			
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec209[l150] = 0.0;
			
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec207[l151] = 0.0;
			
		}
		for (int l152 = 0; (l152 < 3); l152 = (l152 + 1)) {
			fRec206[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec231[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec229[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec228[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec226[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec225[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec223[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec222[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec220[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 3); l161 = (l161 + 1)) {
			fRec219[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 2); l162 = (l162 + 1)) {
			fRec241[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			fRec239[l163] = 0.0;
			
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			fRec238[l164] = 0.0;
			
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec236[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec235[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fRec233[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 3); l168 = (l168 + 1)) {
			fRec232[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec251[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec249[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fRec248[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec246[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fRec245[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec243[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 3); l175 = (l175 + 1)) {
			fRec242[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec258[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec256[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 2); l178 = (l178 + 1)) {
			fRec255[l178] = 0.0;
			
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec253[l179] = 0.0;
			
		}
		for (int l180 = 0; (l180 < 3); l180 = (l180 + 1)) {
			fRec252[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec265[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec263[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fRec262[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec260[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 3); l185 = (l185 + 1)) {
			fRec259[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fRec272[l186] = 0.0;
			
		}
		for (int l187 = 0; (l187 < 2); l187 = (l187 + 1)) {
			fRec270[l187] = 0.0;
			
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec269[l188] = 0.0;
			
		}
		for (int l189 = 0; (l189 < 2); l189 = (l189 + 1)) {
			fRec267[l189] = 0.0;
			
		}
		for (int l190 = 0; (l190 < 3); l190 = (l190 + 1)) {
			fRec266[l190] = 0.0;
			
		}
		for (int l191 = 0; (l191 < 2); l191 = (l191 + 1)) {
			fRec276[l191] = 0.0;
			
		}
		for (int l192 = 0; (l192 < 2); l192 = (l192 + 1)) {
			fRec274[l192] = 0.0;
			
		}
		for (int l193 = 0; (l193 < 3); l193 = (l193 + 1)) {
			fRec273[l193] = 0.0;
			
		}
		for (int l194 = 0; (l194 < 2); l194 = (l194 + 1)) {
			fRec280[l194] = 0.0;
			
		}
		for (int l195 = 0; (l195 < 2); l195 = (l195 + 1)) {
			fRec278[l195] = 0.0;
			
		}
		for (int l196 = 0; (l196 < 3); l196 = (l196 + 1)) {
			fRec277[l196] = 0.0;
			
		}
		for (int l197 = 0; (l197 < 3); l197 = (l197 + 1)) {
			fRec281[l197] = 0.0;
			
		}
		for (int l198 = 0; (l198 < 2); l198 = (l198 + 1)) {
			fRec285[l198] = 0.0;
			
		}
		for (int l199 = 0; (l199 < 2); l199 = (l199 + 1)) {
			fRec283[l199] = 0.0;
			
		}
		for (int l200 = 0; (l200 < 3); l200 = (l200 + 1)) {
			fRec282[l200] = 0.0;
			
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fRec292[l201] = 0.0;
			
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec290[l202] = 0.0;
			
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fRec289[l203] = 0.0;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec287[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 3); l205 = (l205 + 1)) {
			fRec286[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec302[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec300[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec299[l208] = 0.0;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec297[l209] = 0.0;
			
		}
		for (int l210 = 0; (l210 < 2); l210 = (l210 + 1)) {
			fRec296[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 2); l211 = (l211 + 1)) {
			fRec294[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 3); l212 = (l212 + 1)) {
			fRec293[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec315[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fRec313[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 2); l215 = (l215 + 1)) {
			fRec312[l215] = 0.0;
			
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fRec310[l216] = 0.0;
			
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec309[l217] = 0.0;
			
		}
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fRec307[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec306[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fRec304[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 3); l221 = (l221 + 1)) {
			fRec303[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec331[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec329[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 2); l224 = (l224 + 1)) {
			fRec328[l224] = 0.0;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec326[l225] = 0.0;
			
		}
		for (int l226 = 0; (l226 < 2); l226 = (l226 + 1)) {
			fRec325[l226] = 0.0;
			
		}
		for (int l227 = 0; (l227 < 2); l227 = (l227 + 1)) {
			fRec323[l227] = 0.0;
			
		}
		for (int l228 = 0; (l228 < 2); l228 = (l228 + 1)) {
			fRec322[l228] = 0.0;
			
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fRec320[l229] = 0.0;
			
		}
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec319[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fRec317[l231] = 0.0;
			
		}
		for (int l232 = 0; (l232 < 3); l232 = (l232 + 1)) {
			fRec316[l232] = 0.0;
			
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fRec350[l233] = 0.0;
			
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec348[l234] = 0.0;
			
		}
		for (int l235 = 0; (l235 < 2); l235 = (l235 + 1)) {
			fRec347[l235] = 0.0;
			
		}
		for (int l236 = 0; (l236 < 2); l236 = (l236 + 1)) {
			fRec345[l236] = 0.0;
			
		}
		for (int l237 = 0; (l237 < 2); l237 = (l237 + 1)) {
			fRec344[l237] = 0.0;
			
		}
		for (int l238 = 0; (l238 < 2); l238 = (l238 + 1)) {
			fRec342[l238] = 0.0;
			
		}
		for (int l239 = 0; (l239 < 2); l239 = (l239 + 1)) {
			fRec341[l239] = 0.0;
			
		}
		for (int l240 = 0; (l240 < 2); l240 = (l240 + 1)) {
			fRec339[l240] = 0.0;
			
		}
		for (int l241 = 0; (l241 < 2); l241 = (l241 + 1)) {
			fRec338[l241] = 0.0;
			
		}
		for (int l242 = 0; (l242 < 2); l242 = (l242 + 1)) {
			fRec336[l242] = 0.0;
			
		}
		for (int l243 = 0; (l243 < 2); l243 = (l243 + 1)) {
			fRec335[l243] = 0.0;
			
		}
		for (int l244 = 0; (l244 < 2); l244 = (l244 + 1)) {
			fRec333[l244] = 0.0;
			
		}
		for (int l245 = 0; (l245 < 3); l245 = (l245 + 1)) {
			fRec332[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 3); l246 = (l246 + 1)) {
			fRec351[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 3); l247 = (l247 + 1)) {
			fRec352[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 3); l248 = (l248 + 1)) {
			fRec353[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 3); l249 = (l249 + 1)) {
			fRec354[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 3); l250 = (l250 + 1)) {
			fRec355[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 3); l251 = (l251 + 1)) {
			fRec356[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 3); l252 = (l252 + 1)) {
			fRec357[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 3); l253 = (l253 + 1)) {
			fRec358[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec377[l254] = 0.0;
			
		}
		for (int l255 = 0; (l255 < 2); l255 = (l255 + 1)) {
			fRec375[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec374[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fRec372[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec371[l258] = 0.0;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec369[l259] = 0.0;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec368[l260] = 0.0;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec366[l261] = 0.0;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec365[l262] = 0.0;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec363[l263] = 0.0;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec362[l264] = 0.0;
			
		}
		for (int l265 = 0; (l265 < 2); l265 = (l265 + 1)) {
			fRec360[l265] = 0.0;
			
		}
		for (int l266 = 0; (l266 < 3); l266 = (l266 + 1)) {
			fRec359[l266] = 0.0;
			
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec396[l267] = 0.0;
			
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec394[l268] = 0.0;
			
		}
		for (int l269 = 0; (l269 < 2); l269 = (l269 + 1)) {
			fRec393[l269] = 0.0;
			
		}
		for (int l270 = 0; (l270 < 2); l270 = (l270 + 1)) {
			fRec391[l270] = 0.0;
			
		}
		for (int l271 = 0; (l271 < 2); l271 = (l271 + 1)) {
			fRec390[l271] = 0.0;
			
		}
		for (int l272 = 0; (l272 < 2); l272 = (l272 + 1)) {
			fRec388[l272] = 0.0;
			
		}
		for (int l273 = 0; (l273 < 2); l273 = (l273 + 1)) {
			fRec387[l273] = 0.0;
			
		}
		for (int l274 = 0; (l274 < 2); l274 = (l274 + 1)) {
			fRec385[l274] = 0.0;
			
		}
		for (int l275 = 0; (l275 < 2); l275 = (l275 + 1)) {
			fRec384[l275] = 0.0;
			
		}
		for (int l276 = 0; (l276 < 2); l276 = (l276 + 1)) {
			fRec382[l276] = 0.0;
			
		}
		for (int l277 = 0; (l277 < 2); l277 = (l277 + 1)) {
			fRec381[l277] = 0.0;
			
		}
		for (int l278 = 0; (l278 < 2); l278 = (l278 + 1)) {
			fRec379[l278] = 0.0;
			
		}
		for (int l279 = 0; (l279 < 3); l279 = (l279 + 1)) {
			fRec378[l279] = 0.0;
			
		}
		for (int l280 = 0; (l280 < 2); l280 = (l280 + 1)) {
			fRec415[l280] = 0.0;
			
		}
		for (int l281 = 0; (l281 < 2); l281 = (l281 + 1)) {
			fRec413[l281] = 0.0;
			
		}
		for (int l282 = 0; (l282 < 2); l282 = (l282 + 1)) {
			fRec412[l282] = 0.0;
			
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec410[l283] = 0.0;
			
		}
		for (int l284 = 0; (l284 < 2); l284 = (l284 + 1)) {
			fRec409[l284] = 0.0;
			
		}
		for (int l285 = 0; (l285 < 2); l285 = (l285 + 1)) {
			fRec407[l285] = 0.0;
			
		}
		for (int l286 = 0; (l286 < 2); l286 = (l286 + 1)) {
			fRec406[l286] = 0.0;
			
		}
		for (int l287 = 0; (l287 < 2); l287 = (l287 + 1)) {
			fRec404[l287] = 0.0;
			
		}
		for (int l288 = 0; (l288 < 2); l288 = (l288 + 1)) {
			fRec403[l288] = 0.0;
			
		}
		for (int l289 = 0; (l289 < 2); l289 = (l289 + 1)) {
			fRec401[l289] = 0.0;
			
		}
		for (int l290 = 0; (l290 < 2); l290 = (l290 + 1)) {
			fRec400[l290] = 0.0;
			
		}
		for (int l291 = 0; (l291 < 2); l291 = (l291 + 1)) {
			fRec398[l291] = 0.0;
			
		}
		for (int l292 = 0; (l292 < 3); l292 = (l292 + 1)) {
			fRec397[l292] = 0.0;
			
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec434[l293] = 0.0;
			
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec432[l294] = 0.0;
			
		}
		for (int l295 = 0; (l295 < 2); l295 = (l295 + 1)) {
			fRec431[l295] = 0.0;
			
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec429[l296] = 0.0;
			
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec428[l297] = 0.0;
			
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec426[l298] = 0.0;
			
		}
		for (int l299 = 0; (l299 < 2); l299 = (l299 + 1)) {
			fRec425[l299] = 0.0;
			
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec423[l300] = 0.0;
			
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec422[l301] = 0.0;
			
		}
		for (int l302 = 0; (l302 < 2); l302 = (l302 + 1)) {
			fRec420[l302] = 0.0;
			
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec419[l303] = 0.0;
			
		}
		for (int l304 = 0; (l304 < 2); l304 = (l304 + 1)) {
			fRec417[l304] = 0.0;
			
		}
		for (int l305 = 0; (l305 < 3); l305 = (l305 + 1)) {
			fRec416[l305] = 0.0;
			
		}
		for (int l306 = 0; (l306 < 2); l306 = (l306 + 1)) {
			fRec450[l306] = 0.0;
			
		}
		for (int l307 = 0; (l307 < 2); l307 = (l307 + 1)) {
			fRec448[l307] = 0.0;
			
		}
		for (int l308 = 0; (l308 < 2); l308 = (l308 + 1)) {
			fRec447[l308] = 0.0;
			
		}
		for (int l309 = 0; (l309 < 2); l309 = (l309 + 1)) {
			fRec445[l309] = 0.0;
			
		}
		for (int l310 = 0; (l310 < 2); l310 = (l310 + 1)) {
			fRec444[l310] = 0.0;
			
		}
		for (int l311 = 0; (l311 < 2); l311 = (l311 + 1)) {
			fRec442[l311] = 0.0;
			
		}
		for (int l312 = 0; (l312 < 2); l312 = (l312 + 1)) {
			fRec441[l312] = 0.0;
			
		}
		for (int l313 = 0; (l313 < 2); l313 = (l313 + 1)) {
			fRec439[l313] = 0.0;
			
		}
		for (int l314 = 0; (l314 < 2); l314 = (l314 + 1)) {
			fRec438[l314] = 0.0;
			
		}
		for (int l315 = 0; (l315 < 2); l315 = (l315 + 1)) {
			fRec436[l315] = 0.0;
			
		}
		for (int l316 = 0; (l316 < 3); l316 = (l316 + 1)) {
			fRec435[l316] = 0.0;
			
		}
		for (int l317 = 0; (l317 < 2); l317 = (l317 + 1)) {
			fRec466[l317] = 0.0;
			
		}
		for (int l318 = 0; (l318 < 2); l318 = (l318 + 1)) {
			fRec464[l318] = 0.0;
			
		}
		for (int l319 = 0; (l319 < 2); l319 = (l319 + 1)) {
			fRec463[l319] = 0.0;
			
		}
		for (int l320 = 0; (l320 < 2); l320 = (l320 + 1)) {
			fRec461[l320] = 0.0;
			
		}
		for (int l321 = 0; (l321 < 2); l321 = (l321 + 1)) {
			fRec460[l321] = 0.0;
			
		}
		for (int l322 = 0; (l322 < 2); l322 = (l322 + 1)) {
			fRec458[l322] = 0.0;
			
		}
		for (int l323 = 0; (l323 < 2); l323 = (l323 + 1)) {
			fRec457[l323] = 0.0;
			
		}
		for (int l324 = 0; (l324 < 2); l324 = (l324 + 1)) {
			fRec455[l324] = 0.0;
			
		}
		for (int l325 = 0; (l325 < 2); l325 = (l325 + 1)) {
			fRec454[l325] = 0.0;
			
		}
		for (int l326 = 0; (l326 < 2); l326 = (l326 + 1)) {
			fRec452[l326] = 0.0;
			
		}
		for (int l327 = 0; (l327 < 3); l327 = (l327 + 1)) {
			fRec451[l327] = 0.0;
			
		}
		for (int l328 = 0; (l328 < 2); l328 = (l328 + 1)) {
			fRec482[l328] = 0.0;
			
		}
		for (int l329 = 0; (l329 < 2); l329 = (l329 + 1)) {
			fRec480[l329] = 0.0;
			
		}
		for (int l330 = 0; (l330 < 2); l330 = (l330 + 1)) {
			fRec479[l330] = 0.0;
			
		}
		for (int l331 = 0; (l331 < 2); l331 = (l331 + 1)) {
			fRec477[l331] = 0.0;
			
		}
		for (int l332 = 0; (l332 < 2); l332 = (l332 + 1)) {
			fRec476[l332] = 0.0;
			
		}
		for (int l333 = 0; (l333 < 2); l333 = (l333 + 1)) {
			fRec474[l333] = 0.0;
			
		}
		for (int l334 = 0; (l334 < 2); l334 = (l334 + 1)) {
			fRec473[l334] = 0.0;
			
		}
		for (int l335 = 0; (l335 < 2); l335 = (l335 + 1)) {
			fRec471[l335] = 0.0;
			
		}
		for (int l336 = 0; (l336 < 2); l336 = (l336 + 1)) {
			fRec470[l336] = 0.0;
			
		}
		for (int l337 = 0; (l337 < 2); l337 = (l337 + 1)) {
			fRec468[l337] = 0.0;
			
		}
		for (int l338 = 0; (l338 < 3); l338 = (l338 + 1)) {
			fRec467[l338] = 0.0;
			
		}
		for (int l339 = 0; (l339 < 2); l339 = (l339 + 1)) {
			fRec498[l339] = 0.0;
			
		}
		for (int l340 = 0; (l340 < 2); l340 = (l340 + 1)) {
			fRec496[l340] = 0.0;
			
		}
		for (int l341 = 0; (l341 < 2); l341 = (l341 + 1)) {
			fRec495[l341] = 0.0;
			
		}
		for (int l342 = 0; (l342 < 2); l342 = (l342 + 1)) {
			fRec493[l342] = 0.0;
			
		}
		for (int l343 = 0; (l343 < 2); l343 = (l343 + 1)) {
			fRec492[l343] = 0.0;
			
		}
		for (int l344 = 0; (l344 < 2); l344 = (l344 + 1)) {
			fRec490[l344] = 0.0;
			
		}
		for (int l345 = 0; (l345 < 2); l345 = (l345 + 1)) {
			fRec489[l345] = 0.0;
			
		}
		for (int l346 = 0; (l346 < 2); l346 = (l346 + 1)) {
			fRec487[l346] = 0.0;
			
		}
		for (int l347 = 0; (l347 < 2); l347 = (l347 + 1)) {
			fRec486[l347] = 0.0;
			
		}
		for (int l348 = 0; (l348 < 2); l348 = (l348 + 1)) {
			fRec484[l348] = 0.0;
			
		}
		for (int l349 = 0; (l349 < 3); l349 = (l349 + 1)) {
			fRec483[l349] = 0.0;
			
		}
		for (int l350 = 0; (l350 < 2); l350 = (l350 + 1)) {
			fRec514[l350] = 0.0;
			
		}
		for (int l351 = 0; (l351 < 2); l351 = (l351 + 1)) {
			fRec512[l351] = 0.0;
			
		}
		for (int l352 = 0; (l352 < 2); l352 = (l352 + 1)) {
			fRec511[l352] = 0.0;
			
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec509[l353] = 0.0;
			
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec508[l354] = 0.0;
			
		}
		for (int l355 = 0; (l355 < 2); l355 = (l355 + 1)) {
			fRec506[l355] = 0.0;
			
		}
		for (int l356 = 0; (l356 < 2); l356 = (l356 + 1)) {
			fRec505[l356] = 0.0;
			
		}
		for (int l357 = 0; (l357 < 2); l357 = (l357 + 1)) {
			fRec503[l357] = 0.0;
			
		}
		for (int l358 = 0; (l358 < 2); l358 = (l358 + 1)) {
			fRec502[l358] = 0.0;
			
		}
		for (int l359 = 0; (l359 < 2); l359 = (l359 + 1)) {
			fRec500[l359] = 0.0;
			
		}
		for (int l360 = 0; (l360 < 3); l360 = (l360 + 1)) {
			fRec499[l360] = 0.0;
			
		}
		for (int l361 = 0; (l361 < 2); l361 = (l361 + 1)) {
			fRec527[l361] = 0.0;
			
		}
		for (int l362 = 0; (l362 < 2); l362 = (l362 + 1)) {
			fRec525[l362] = 0.0;
			
		}
		for (int l363 = 0; (l363 < 2); l363 = (l363 + 1)) {
			fRec524[l363] = 0.0;
			
		}
		for (int l364 = 0; (l364 < 2); l364 = (l364 + 1)) {
			fRec522[l364] = 0.0;
			
		}
		for (int l365 = 0; (l365 < 2); l365 = (l365 + 1)) {
			fRec521[l365] = 0.0;
			
		}
		for (int l366 = 0; (l366 < 2); l366 = (l366 + 1)) {
			fRec519[l366] = 0.0;
			
		}
		for (int l367 = 0; (l367 < 2); l367 = (l367 + 1)) {
			fRec518[l367] = 0.0;
			
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec516[l368] = 0.0;
			
		}
		for (int l369 = 0; (l369 < 3); l369 = (l369 + 1)) {
			fRec515[l369] = 0.0;
			
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec540[l370] = 0.0;
			
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			fRec538[l371] = 0.0;
			
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			fRec537[l372] = 0.0;
			
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fRec535[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec534[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 2); l375 = (l375 + 1)) {
			fRec532[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec531[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec529[l377] = 0.0;
			
		}
		for (int l378 = 0; (l378 < 3); l378 = (l378 + 1)) {
			fRec528[l378] = 0.0;
			
		}
		for (int l379 = 0; (l379 < 2); l379 = (l379 + 1)) {
			fRec553[l379] = 0.0;
			
		}
		for (int l380 = 0; (l380 < 2); l380 = (l380 + 1)) {
			fRec551[l380] = 0.0;
			
		}
		for (int l381 = 0; (l381 < 2); l381 = (l381 + 1)) {
			fRec550[l381] = 0.0;
			
		}
		for (int l382 = 0; (l382 < 2); l382 = (l382 + 1)) {
			fRec548[l382] = 0.0;
			
		}
		for (int l383 = 0; (l383 < 2); l383 = (l383 + 1)) {
			fRec547[l383] = 0.0;
			
		}
		for (int l384 = 0; (l384 < 2); l384 = (l384 + 1)) {
			fRec545[l384] = 0.0;
			
		}
		for (int l385 = 0; (l385 < 2); l385 = (l385 + 1)) {
			fRec544[l385] = 0.0;
			
		}
		for (int l386 = 0; (l386 < 2); l386 = (l386 + 1)) {
			fRec542[l386] = 0.0;
			
		}
		for (int l387 = 0; (l387 < 3); l387 = (l387 + 1)) {
			fRec541[l387] = 0.0;
			
		}
		for (int l388 = 0; (l388 < 2); l388 = (l388 + 1)) {
			fRec566[l388] = 0.0;
			
		}
		for (int l389 = 0; (l389 < 2); l389 = (l389 + 1)) {
			fRec564[l389] = 0.0;
			
		}
		for (int l390 = 0; (l390 < 2); l390 = (l390 + 1)) {
			fRec563[l390] = 0.0;
			
		}
		for (int l391 = 0; (l391 < 2); l391 = (l391 + 1)) {
			fRec561[l391] = 0.0;
			
		}
		for (int l392 = 0; (l392 < 2); l392 = (l392 + 1)) {
			fRec560[l392] = 0.0;
			
		}
		for (int l393 = 0; (l393 < 2); l393 = (l393 + 1)) {
			fRec558[l393] = 0.0;
			
		}
		for (int l394 = 0; (l394 < 2); l394 = (l394 + 1)) {
			fRec557[l394] = 0.0;
			
		}
		for (int l395 = 0; (l395 < 2); l395 = (l395 + 1)) {
			fRec555[l395] = 0.0;
			
		}
		for (int l396 = 0; (l396 < 3); l396 = (l396 + 1)) {
			fRec554[l396] = 0.0;
			
		}
		for (int l397 = 0; (l397 < 2); l397 = (l397 + 1)) {
			fRec579[l397] = 0.0;
			
		}
		for (int l398 = 0; (l398 < 2); l398 = (l398 + 1)) {
			fRec577[l398] = 0.0;
			
		}
		for (int l399 = 0; (l399 < 2); l399 = (l399 + 1)) {
			fRec576[l399] = 0.0;
			
		}
		for (int l400 = 0; (l400 < 2); l400 = (l400 + 1)) {
			fRec574[l400] = 0.0;
			
		}
		for (int l401 = 0; (l401 < 2); l401 = (l401 + 1)) {
			fRec573[l401] = 0.0;
			
		}
		for (int l402 = 0; (l402 < 2); l402 = (l402 + 1)) {
			fRec571[l402] = 0.0;
			
		}
		for (int l403 = 0; (l403 < 2); l403 = (l403 + 1)) {
			fRec570[l403] = 0.0;
			
		}
		for (int l404 = 0; (l404 < 2); l404 = (l404 + 1)) {
			fRec568[l404] = 0.0;
			
		}
		for (int l405 = 0; (l405 < 3); l405 = (l405 + 1)) {
			fRec567[l405] = 0.0;
			
		}
		for (int l406 = 0; (l406 < 2); l406 = (l406 + 1)) {
			fRec589[l406] = 0.0;
			
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec587[l407] = 0.0;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec586[l408] = 0.0;
			
		}
		for (int l409 = 0; (l409 < 2); l409 = (l409 + 1)) {
			fRec584[l409] = 0.0;
			
		}
		for (int l410 = 0; (l410 < 2); l410 = (l410 + 1)) {
			fRec583[l410] = 0.0;
			
		}
		for (int l411 = 0; (l411 < 2); l411 = (l411 + 1)) {
			fRec581[l411] = 0.0;
			
		}
		for (int l412 = 0; (l412 < 3); l412 = (l412 + 1)) {
			fRec580[l412] = 0.0;
			
		}
		for (int l413 = 0; (l413 < 2); l413 = (l413 + 1)) {
			fRec599[l413] = 0.0;
			
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec597[l414] = 0.0;
			
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec596[l415] = 0.0;
			
		}
		for (int l416 = 0; (l416 < 2); l416 = (l416 + 1)) {
			fRec594[l416] = 0.0;
			
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec593[l417] = 0.0;
			
		}
		for (int l418 = 0; (l418 < 2); l418 = (l418 + 1)) {
			fRec591[l418] = 0.0;
			
		}
		for (int l419 = 0; (l419 < 3); l419 = (l419 + 1)) {
			fRec590[l419] = 0.0;
			
		}
		for (int l420 = 0; (l420 < 2); l420 = (l420 + 1)) {
			fRec609[l420] = 0.0;
			
		}
		for (int l421 = 0; (l421 < 2); l421 = (l421 + 1)) {
			fRec607[l421] = 0.0;
			
		}
		for (int l422 = 0; (l422 < 2); l422 = (l422 + 1)) {
			fRec606[l422] = 0.0;
			
		}
		for (int l423 = 0; (l423 < 2); l423 = (l423 + 1)) {
			fRec604[l423] = 0.0;
			
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec603[l424] = 0.0;
			
		}
		for (int l425 = 0; (l425 < 2); l425 = (l425 + 1)) {
			fRec601[l425] = 0.0;
			
		}
		for (int l426 = 0; (l426 < 3); l426 = (l426 + 1)) {
			fRec600[l426] = 0.0;
			
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec616[l427] = 0.0;
			
		}
		for (int l428 = 0; (l428 < 2); l428 = (l428 + 1)) {
			fRec614[l428] = 0.0;
			
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec613[l429] = 0.0;
			
		}
		for (int l430 = 0; (l430 < 2); l430 = (l430 + 1)) {
			fRec611[l430] = 0.0;
			
		}
		for (int l431 = 0; (l431 < 3); l431 = (l431 + 1)) {
			fRec610[l431] = 0.0;
			
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
		ui_interface->openVerticalBox("KMHLS_Dome_7h7p_normal_2");
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
			double fTemp8 = (2.2195680229999999 * fTemp7);
			fRec4[0] = (double(input60[i]) - (((fTemp2 * fRec4[2]) + (2.0 * (fTemp3 * fRec4[1]))) / fTemp4));
			double fTemp9 = (((fTemp1 * (fRec4[2] + (fRec4[0] + (2.0 * fRec4[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec4[1]) + ((fRec4[0] + fRec4[2]) / fTemp4))))));
			double fTemp10 = (1.281441512 * fTemp9);
			fRec5[0] = (double(input59[i]) - (((fTemp2 * fRec5[2]) + (2.0 * (fTemp3 * fRec5[1]))) / fTemp4));
			double fTemp11 = (((fTemp1 * (fRec5[2] + (fRec5[0] + (2.0 * fRec5[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec5[1]) + ((fRec5[0] + fRec5[2]) / fTemp4))))));
			double fTemp12 = (0.43071832789999998 * fTemp11);
			fRec6[0] = (double(input58[i]) - (((fTemp2 * fRec6[2]) + (2.0 * (fTemp3 * fRec6[1]))) / fTemp4));
			double fTemp13 = (((fTemp1 * (fRec6[2] + (fRec6[0] + (2.0 * fRec6[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec6[1]) + ((fRec6[0] + fRec6[2]) / fTemp4))))));
			double fTemp14 = (3.2418949549999998 * fTemp13);
			fRec7[0] = (double(input57[i]) - (((fTemp2 * fRec7[2]) + (2.0 * (fTemp3 * fRec7[1]))) / fTemp4));
			double fTemp15 = (((fTemp1 * (fRec7[2] + (fRec7[0] + (2.0 * fRec7[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec7[1]) + ((fRec7[0] + fRec7[2]) / fTemp4))))));
			double fTemp16 = (0.35205137149999999 * fTemp15);
			fRec8[0] = (double(input55[i]) - (((fTemp2 * fRec8[2]) + (2.0 * (fTemp3 * fRec8[1]))) / fTemp4));
			double fTemp17 = (((fTemp1 * (fRec8[2] + (fRec8[0] + (2.0 * fRec8[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec8[1]) + ((fRec8[0] + fRec8[2]) / fTemp4))))));
			double fTemp18 = (0.26697909409999998 * fTemp17);
			double fTemp19 = (fConst5 * fRec10[1]);
			double fTemp20 = (fConst6 * fRec13[1]);
			double fTemp21 = (fConst8 * fRec16[1]);
			double fTemp22 = (fConst9 * fRec19[1]);
			double fTemp23 = (fConst11 * double(input44[i]));
			double fTemp24 = (fConst12 * fRec22[1]);
			double fTemp25 = (fConst13 * fRec25[1]);
			fRec27[0] = (fTemp23 + (fTemp24 + (fRec27[1] + fTemp25)));
			fRec25[0] = fRec27[0];
			double fRec26 = ((fTemp25 + fTemp24) + fTemp23);
			fRec24[0] = (fRec25[0] + fRec24[1]);
			fRec22[0] = fRec24[0];
			double fRec23 = fRec26;
			fRec21[0] = (fTemp21 + (fTemp22 + (fRec23 + fRec21[1])));
			fRec19[0] = fRec21[0];
			double fRec20 = (fTemp21 + (fRec23 + fTemp22));
			fRec18[0] = (fRec19[0] + fRec18[1]);
			fRec16[0] = fRec18[0];
			double fRec17 = fRec20;
			fRec15[0] = (fTemp19 + (fTemp20 + (fRec17 + fRec15[1])));
			fRec13[0] = fRec15[0];
			double fRec14 = (fTemp19 + (fRec17 + fTemp20));
			fRec12[0] = (fRec13[0] + fRec12[1]);
			fRec10[0] = fRec12[0];
			double fRec11 = fRec14;
			fRec9[0] = (fRec11 - (((fTemp2 * fRec9[2]) + (2.0 * (fTemp3 * fRec9[1]))) / fTemp4));
			double fTemp26 = (((fTemp1 * (fRec9[2] + (fRec9[0] + (2.0 * fRec9[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec9[1]) + ((fRec9[0] + fRec9[2]) / fTemp4))))));
			double fTemp27 = (0.91846784979999996 * fTemp26);
			double fTemp28 = (fConst5 * fRec29[1]);
			double fTemp29 = (fConst6 * fRec32[1]);
			double fTemp30 = (fConst8 * fRec35[1]);
			double fTemp31 = (fConst9 * fRec38[1]);
			double fTemp32 = (fConst11 * double(input43[i]));
			double fTemp33 = (fConst12 * fRec41[1]);
			double fTemp34 = (fConst13 * fRec44[1]);
			fRec46[0] = (fTemp32 + (fTemp33 + (fRec46[1] + fTemp34)));
			fRec44[0] = fRec46[0];
			double fRec45 = ((fTemp34 + fTemp33) + fTemp32);
			fRec43[0] = (fRec44[0] + fRec43[1]);
			fRec41[0] = fRec43[0];
			double fRec42 = fRec45;
			fRec40[0] = (fTemp30 + (fTemp31 + (fRec42 + fRec40[1])));
			fRec38[0] = fRec40[0];
			double fRec39 = (fTemp30 + (fRec42 + fTemp31));
			fRec37[0] = (fRec38[0] + fRec37[1]);
			fRec35[0] = fRec37[0];
			double fRec36 = fRec39;
			fRec34[0] = (fTemp28 + (fTemp29 + (fRec36 + fRec34[1])));
			fRec32[0] = fRec34[0];
			double fRec33 = (fTemp28 + (fRec36 + fTemp29));
			fRec31[0] = (fRec32[0] + fRec31[1]);
			fRec29[0] = fRec31[0];
			double fRec30 = fRec33;
			fRec28[0] = (fRec30 - (((fTemp2 * fRec28[2]) + (2.0 * (fTemp3 * fRec28[1]))) / fTemp4));
			double fTemp35 = (((fTemp1 * (fRec28[2] + (fRec28[0] + (2.0 * fRec28[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec28[1]) + ((fRec28[0] + fRec28[2]) / fTemp4))))));
			double fTemp36 = (4.92779554 * fTemp35);
			double fTemp37 = (fConst5 * fRec48[1]);
			double fTemp38 = (fConst6 * fRec51[1]);
			double fTemp39 = (fConst8 * fRec54[1]);
			double fTemp40 = (fConst9 * fRec57[1]);
			double fTemp41 = (fConst11 * double(input42[i]));
			double fTemp42 = (fConst12 * fRec60[1]);
			double fTemp43 = (fConst13 * fRec63[1]);
			fRec65[0] = (fTemp41 + (fTemp42 + (fRec65[1] + fTemp43)));
			fRec63[0] = fRec65[0];
			double fRec64 = ((fTemp43 + fTemp42) + fTemp41);
			fRec62[0] = (fRec63[0] + fRec62[1]);
			fRec60[0] = fRec62[0];
			double fRec61 = fRec64;
			fRec59[0] = (fTemp39 + (fTemp40 + (fRec61 + fRec59[1])));
			fRec57[0] = fRec59[0];
			double fRec58 = (fTemp39 + (fRec61 + fTemp40));
			fRec56[0] = (fRec57[0] + fRec56[1]);
			fRec54[0] = fRec56[0];
			double fRec55 = fRec58;
			fRec53[0] = (fTemp37 + (fTemp38 + (fRec55 + fRec53[1])));
			fRec51[0] = fRec53[0];
			double fRec52 = (fTemp37 + (fRec55 + fTemp38));
			fRec50[0] = (fRec51[0] + fRec50[1]);
			fRec48[0] = fRec50[0];
			double fRec49 = fRec52;
			fRec47[0] = (fRec49 - (((fTemp2 * fRec47[2]) + (2.0 * (fTemp3 * fRec47[1]))) / fTemp4));
			double fTemp44 = (((fTemp1 * (fRec47[2] + (fRec47[0] + (2.0 * fRec47[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec47[1]) + ((fRec47[0] + fRec47[2]) / fTemp4))))));
			double fTemp45 = (1.6504022140000001 * fTemp44);
			double fTemp46 = (fConst5 * fRec67[1]);
			double fTemp47 = (fConst6 * fRec70[1]);
			double fTemp48 = (fConst8 * fRec73[1]);
			double fTemp49 = (fConst9 * fRec76[1]);
			double fTemp50 = (fConst11 * double(input41[i]));
			double fTemp51 = (fConst12 * fRec79[1]);
			double fTemp52 = (fConst13 * fRec82[1]);
			fRec84[0] = (fTemp50 + (fTemp51 + (fRec84[1] + fTemp52)));
			fRec82[0] = fRec84[0];
			double fRec83 = ((fTemp52 + fTemp51) + fTemp50);
			fRec81[0] = (fRec82[0] + fRec81[1]);
			fRec79[0] = fRec81[0];
			double fRec80 = fRec83;
			fRec78[0] = (fTemp48 + (fTemp49 + (fRec80 + fRec78[1])));
			fRec76[0] = fRec78[0];
			double fRec77 = (fTemp48 + (fRec80 + fTemp49));
			fRec75[0] = (fRec76[0] + fRec75[1]);
			fRec73[0] = fRec75[0];
			double fRec74 = fRec77;
			fRec72[0] = (fTemp46 + (fTemp47 + (fRec74 + fRec72[1])));
			fRec70[0] = fRec72[0];
			double fRec71 = (fTemp46 + (fRec74 + fTemp47));
			fRec69[0] = (fRec70[0] + fRec69[1]);
			fRec67[0] = fRec69[0];
			double fRec68 = fRec71;
			fRec66[0] = (fRec68 - (((fTemp2 * fRec66[2]) + (2.0 * (fTemp3 * fRec66[1]))) / fTemp4));
			double fTemp53 = (((fTemp1 * (fRec66[2] + (fRec66[0] + (2.0 * fRec66[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec66[1]) + ((fRec66[0] + fRec66[2]) / fTemp4))))));
			double fTemp54 = (2.399475518 * fTemp53);
			double fTemp55 = (fConst5 * fRec86[1]);
			double fTemp56 = (fConst6 * fRec89[1]);
			double fTemp57 = (fConst8 * fRec92[1]);
			double fTemp58 = (fConst9 * fRec95[1]);
			double fTemp59 = (fConst11 * double(input40[i]));
			double fTemp60 = (fConst12 * fRec98[1]);
			double fTemp61 = (fConst13 * fRec101[1]);
			fRec103[0] = (fTemp59 + (fTemp60 + (fRec103[1] + fTemp61)));
			fRec101[0] = fRec103[0];
			double fRec102 = ((fTemp61 + fTemp60) + fTemp59);
			fRec100[0] = (fRec101[0] + fRec100[1]);
			fRec98[0] = fRec100[0];
			double fRec99 = fRec102;
			fRec97[0] = (fTemp57 + (fTemp58 + (fRec99 + fRec97[1])));
			fRec95[0] = fRec97[0];
			double fRec96 = (fTemp57 + (fRec99 + fTemp58));
			fRec94[0] = (fRec95[0] + fRec94[1]);
			fRec92[0] = fRec94[0];
			double fRec93 = fRec96;
			fRec91[0] = (fTemp55 + (fTemp56 + (fRec93 + fRec91[1])));
			fRec89[0] = fRec91[0];
			double fRec90 = (fTemp55 + (fRec93 + fTemp56));
			fRec88[0] = (fRec89[0] + fRec88[1]);
			fRec86[0] = fRec88[0];
			double fRec87 = fRec90;
			fRec85[0] = (fRec87 - (((fTemp2 * fRec85[2]) + (2.0 * (fTemp3 * fRec85[1]))) / fTemp4));
			double fTemp62 = (((fTemp1 * (fRec85[2] + (fRec85[0] + (2.0 * fRec85[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec85[1]) + ((fRec85[0] + fRec85[2]) / fTemp4))))));
			double fTemp63 = (0.073879302100000002 * fTemp62);
			double fTemp64 = (fConst5 * fRec105[1]);
			double fTemp65 = (fConst6 * fRec108[1]);
			double fTemp66 = (fConst8 * fRec111[1]);
			double fTemp67 = (fConst9 * fRec114[1]);
			double fTemp68 = (fConst11 * double(input38[i]));
			double fTemp69 = (fConst12 * fRec117[1]);
			double fTemp70 = (fConst13 * fRec120[1]);
			fRec122[0] = (fTemp68 + (fTemp69 + (fRec122[1] + fTemp70)));
			fRec120[0] = fRec122[0];
			double fRec121 = ((fTemp70 + fTemp69) + fTemp68);
			fRec119[0] = (fRec120[0] + fRec119[1]);
			fRec117[0] = fRec119[0];
			double fRec118 = fRec121;
			fRec116[0] = (fTemp66 + (fTemp67 + (fRec118 + fRec116[1])));
			fRec114[0] = fRec116[0];
			double fRec115 = (fTemp66 + (fRec118 + fTemp67));
			fRec113[0] = (fRec114[0] + fRec113[1]);
			fRec111[0] = fRec113[0];
			double fRec112 = fRec115;
			fRec110[0] = (fTemp64 + (fTemp65 + (fRec112 + fRec110[1])));
			fRec108[0] = fRec110[0];
			double fRec109 = (fTemp64 + (fRec112 + fTemp65));
			fRec107[0] = (fRec108[0] + fRec107[1]);
			fRec105[0] = fRec107[0];
			double fRec106 = fRec109;
			fRec104[0] = (fRec106 - (((fTemp2 * fRec104[2]) + (2.0 * (fTemp3 * fRec104[1]))) / fTemp4));
			double fTemp71 = (((fTemp1 * (fRec104[2] + (fRec104[0] + (2.0 * fRec104[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec104[1]) + ((fRec104[0] + fRec104[2]) / fTemp4))))));
			double fTemp72 = (1.9628066150000001 * fTemp71);
			double fTemp73 = (fConst5 * fRec124[1]);
			double fTemp74 = (fConst6 * fRec127[1]);
			double fTemp75 = (fConst8 * fRec130[1]);
			double fTemp76 = (fConst9 * fRec133[1]);
			double fTemp77 = (fConst11 * double(input37[i]));
			double fTemp78 = (fConst12 * fRec136[1]);
			double fTemp79 = (fConst13 * fRec139[1]);
			fRec141[0] = (fTemp77 + (fTemp78 + (fRec141[1] + fTemp79)));
			fRec139[0] = fRec141[0];
			double fRec140 = ((fTemp79 + fTemp78) + fTemp77);
			fRec138[0] = (fRec139[0] + fRec138[1]);
			fRec136[0] = fRec138[0];
			double fRec137 = fRec140;
			fRec135[0] = (fTemp75 + (fTemp76 + (fRec137 + fRec135[1])));
			fRec133[0] = fRec135[0];
			double fRec134 = (fTemp75 + (fRec137 + fTemp76));
			fRec132[0] = (fRec133[0] + fRec132[1]);
			fRec130[0] = fRec132[0];
			double fRec131 = fRec134;
			fRec129[0] = (fTemp73 + (fTemp74 + (fRec131 + fRec129[1])));
			fRec127[0] = fRec129[0];
			double fRec128 = (fTemp73 + (fRec131 + fTemp74));
			fRec126[0] = (fRec127[0] + fRec126[1]);
			fRec124[0] = fRec126[0];
			double fRec125 = fRec128;
			fRec123[0] = (fRec125 - (((fTemp2 * fRec123[2]) + (2.0 * (fTemp3 * fRec123[1]))) / fTemp4));
			double fTemp80 = (((fTemp1 * (fRec123[2] + (fRec123[0] + (2.0 * fRec123[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec123[1]) + ((fRec123[0] + fRec123[2]) / fTemp4))))));
			double fTemp81 = (3.5468706820000002 * fTemp80);
			double fTemp82 = (fConst15 * fRec143[1]);
			double fTemp83 = (fConst17 * fRec146[1]);
			double fTemp84 = (fConst18 * fRec149[1]);
			double fTemp85 = (fConst20 * double(input31[i]));
			double fTemp86 = (fConst21 * fRec152[1]);
			double fTemp87 = (fConst22 * fRec155[1]);
			fRec157[0] = (fTemp85 + (fTemp86 + (fRec157[1] + fTemp87)));
			fRec155[0] = fRec157[0];
			double fRec156 = ((fTemp87 + fTemp86) + fTemp85);
			fRec154[0] = (fRec155[0] + fRec154[1]);
			fRec152[0] = fRec154[0];
			double fRec153 = fRec156;
			fRec151[0] = (fTemp83 + (fTemp84 + (fRec153 + fRec151[1])));
			fRec149[0] = fRec151[0];
			double fRec150 = (fTemp83 + (fRec153 + fTemp84));
			fRec148[0] = (fRec149[0] + fRec148[1]);
			fRec146[0] = fRec148[0];
			double fRec147 = fRec150;
			fRec145[0] = (fTemp82 + (fRec147 + fRec145[1]));
			fRec143[0] = fRec145[0];
			double fRec144 = (fRec147 + fTemp82);
			fRec142[0] = (fRec144 - (((fTemp2 * fRec142[2]) + (2.0 * (fTemp3 * fRec142[1]))) / fTemp4));
			double fTemp88 = (((fTemp1 * (fRec142[2] + (fRec142[0] + (2.0 * fRec142[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec142[1]) + ((fRec142[0] + fRec142[2]) / fTemp4))))));
			double fTemp89 = (fConst15 * fRec159[1]);
			double fTemp90 = (fConst17 * fRec162[1]);
			double fTemp91 = (fConst18 * fRec165[1]);
			double fTemp92 = (fConst20 * double(input30[i]));
			double fTemp93 = (fConst21 * fRec168[1]);
			double fTemp94 = (fConst22 * fRec171[1]);
			fRec173[0] = (fTemp92 + (fTemp93 + (fRec173[1] + fTemp94)));
			fRec171[0] = fRec173[0];
			double fRec172 = ((fTemp94 + fTemp93) + fTemp92);
			fRec170[0] = (fRec171[0] + fRec170[1]);
			fRec168[0] = fRec170[0];
			double fRec169 = fRec172;
			fRec167[0] = (fTemp90 + (fTemp91 + (fRec169 + fRec167[1])));
			fRec165[0] = fRec167[0];
			double fRec166 = (fTemp90 + (fRec169 + fTemp91));
			fRec164[0] = (fRec165[0] + fRec164[1]);
			fRec162[0] = fRec164[0];
			double fRec163 = fRec166;
			fRec161[0] = (fTemp89 + (fRec163 + fRec161[1]));
			fRec159[0] = fRec161[0];
			double fRec160 = (fRec163 + fTemp89);
			fRec158[0] = (fRec160 - (((fTemp2 * fRec158[2]) + (2.0 * (fTemp3 * fRec158[1]))) / fTemp4));
			double fTemp95 = (((fTemp1 * (fRec158[2] + (fRec158[0] + (2.0 * fRec158[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec158[1]) + ((fRec158[0] + fRec158[2]) / fTemp4))))));
			double fTemp96 = (4.9291799049999998 * fTemp95);
			double fTemp97 = (fConst15 * fRec175[1]);
			double fTemp98 = (fConst17 * fRec178[1]);
			double fTemp99 = (fConst18 * fRec181[1]);
			double fTemp100 = (fConst20 * double(input29[i]));
			double fTemp101 = (fConst21 * fRec184[1]);
			double fTemp102 = (fConst22 * fRec187[1]);
			fRec189[0] = (fTemp100 + (fTemp101 + (fRec189[1] + fTemp102)));
			fRec187[0] = fRec189[0];
			double fRec188 = ((fTemp102 + fTemp101) + fTemp100);
			fRec186[0] = (fRec187[0] + fRec186[1]);
			fRec184[0] = fRec186[0];
			double fRec185 = fRec188;
			fRec183[0] = (fTemp98 + (fTemp99 + (fRec185 + fRec183[1])));
			fRec181[0] = fRec183[0];
			double fRec182 = (fTemp98 + (fRec185 + fTemp99));
			fRec180[0] = (fRec181[0] + fRec180[1]);
			fRec178[0] = fRec180[0];
			double fRec179 = fRec182;
			fRec177[0] = (fTemp97 + (fRec179 + fRec177[1]));
			fRec175[0] = fRec177[0];
			double fRec176 = (fRec179 + fTemp97);
			fRec174[0] = (fRec176 - (((fTemp2 * fRec174[2]) + (2.0 * (fTemp3 * fRec174[1]))) / fTemp4));
			double fTemp103 = (((fTemp1 * (fRec174[2] + (fRec174[0] + (2.0 * fRec174[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec174[1]) + ((fRec174[0] + fRec174[2]) / fTemp4))))));
			double fTemp104 = (0.89280991779999996 * fTemp103);
			double fTemp105 = (fConst15 * fRec191[1]);
			double fTemp106 = (fConst17 * fRec194[1]);
			double fTemp107 = (fConst18 * fRec197[1]);
			double fTemp108 = (fConst20 * double(input26[i]));
			double fTemp109 = (fConst21 * fRec200[1]);
			double fTemp110 = (fConst22 * fRec203[1]);
			fRec205[0] = (fTemp108 + (fTemp109 + (fRec205[1] + fTemp110)));
			fRec203[0] = fRec205[0];
			double fRec204 = ((fTemp110 + fTemp109) + fTemp108);
			fRec202[0] = (fRec203[0] + fRec202[1]);
			fRec200[0] = fRec202[0];
			double fRec201 = fRec204;
			fRec199[0] = (fTemp106 + (fTemp107 + (fRec201 + fRec199[1])));
			fRec197[0] = fRec199[0];
			double fRec198 = (fTemp106 + (fRec201 + fTemp107));
			fRec196[0] = (fRec197[0] + fRec196[1]);
			fRec194[0] = fRec196[0];
			double fRec195 = fRec198;
			fRec193[0] = (fTemp105 + (fRec195 + fRec193[1]));
			fRec191[0] = fRec193[0];
			double fRec192 = (fRec195 + fTemp105);
			fRec190[0] = (fRec192 - (((fTemp2 * fRec190[2]) + (2.0 * (fTemp3 * fRec190[1]))) / fTemp4));
			double fTemp111 = (((fTemp1 * (fRec190[2] + (fRec190[0] + (2.0 * fRec190[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec190[1]) + ((fRec190[0] + fRec190[2]) / fTemp4))))));
			double fTemp112 = (8.156603531 * fTemp111);
			double fTemp113 = (fConst24 * fRec207[1]);
			double fTemp114 = (fConst25 * fRec210[1]);
			double fTemp115 = (fConst27 * double(input20[i]));
			double fTemp116 = (fConst28 * fRec213[1]);
			double fTemp117 = (fConst29 * fRec216[1]);
			fRec218[0] = (fTemp115 + (fTemp116 + (fRec218[1] + fTemp117)));
			fRec216[0] = fRec218[0];
			double fRec217 = ((fTemp117 + fTemp116) + fTemp115);
			fRec215[0] = (fRec216[0] + fRec215[1]);
			fRec213[0] = fRec215[0];
			double fRec214 = fRec217;
			fRec212[0] = (fTemp113 + (fTemp114 + (fRec214 + fRec212[1])));
			fRec210[0] = fRec212[0];
			double fRec211 = (fTemp113 + (fRec214 + fTemp114));
			fRec209[0] = (fRec210[0] + fRec209[1]);
			fRec207[0] = fRec209[0];
			double fRec208 = fRec211;
			fRec206[0] = (fRec208 - (((fTemp2 * fRec206[2]) + (2.0 * (fTemp3 * fRec206[1]))) / fTemp4));
			double fTemp118 = (((fTemp1 * (fRec206[2] + (fRec206[0] + (2.0 * fRec206[1])))) / fTemp5) + (0.77210283830000004 * (fRec3[0] * (0.0 - ((fTemp6 * fRec206[1]) + ((fRec206[0] + fRec206[2]) / fTemp4))))));
			double fTemp119 = (1.4006267349999999 * fTemp118);
			double fTemp120 = (fConst24 * fRec220[1]);
			double fTemp121 = (fConst25 * fRec223[1]);
			double fTemp122 = (fConst27 * double(input17[i]));
			double fTemp123 = (fConst28 * fRec226[1]);
			double fTemp124 = (fConst29 * fRec229[1]);
			fRec231[0] = (fTemp122 + (fTemp123 + (fRec231[1] + fTemp124)));
			fRec229[0] = fRec231[0];
			double fRec230 = ((fTemp124 + fTemp123) + fTemp122);
			fRec228[0] = (fRec229[0] + fRec228[1]);
			fRec226[0] = fRec228[0];
			double fRec227 = fRec230;
			fRec225[0] = (fTemp120 + (fTemp121 + (fRec227 + fRec225[1])));
			fRec223[0] = fRec225[0];
			double fRec224 = (fTemp120 + (fRec227 + fTemp121));
			fRec222[0] = (fRec223[0] + fRec222[1]);
			fRec220[0] = fRec222[0];
			double fRec221 = fRec224;
			fRec219[0] = (fRec221 - (((fTemp2 * fRec219[2]) + (2.0 * (fTemp3 * fRec219[1]))) / fTemp4));
			double fTemp125 = (((fTemp1 * (fRec219[2] + (fRec219[0] + (2.0 * fRec219[1])))) / fTemp5) + (0.77210283830000004 * (fRec3[0] * (0.0 - ((fTemp6 * fRec219[1]) + ((fRec219[0] + fRec219[2]) / fTemp4))))));
			double fTemp126 = (5.6362862649999999 * fTemp125);
			double fTemp127 = (fConst31 * fRec233[1]);
			double fTemp128 = (fConst33 * double(input14[i]));
			double fTemp129 = (fConst34 * fRec236[1]);
			double fTemp130 = (fConst35 * fRec239[1]);
			fRec241[0] = (fTemp128 + (fTemp129 + (fRec241[1] + fTemp130)));
			fRec239[0] = fRec241[0];
			double fRec240 = ((fTemp130 + fTemp129) + fTemp128);
			fRec238[0] = (fRec239[0] + fRec238[1]);
			fRec236[0] = fRec238[0];
			double fRec237 = fRec240;
			fRec235[0] = (fTemp127 + (fRec237 + fRec235[1]));
			fRec233[0] = fRec235[0];
			double fRec234 = (fRec237 + fTemp127);
			fRec232[0] = (fRec234 - (((fTemp2 * fRec232[2]) + (2.0 * (fTemp3 * fRec232[1]))) / fTemp4));
			double fTemp131 = (((fTemp1 * (fRec232[2] + (fRec232[0] + (2.0 * fRec232[1])))) / fTemp5) + (0.93701139950000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec232[1]) + ((fRec232[0] + fRec232[2]) / fTemp4))))));
			double fTemp132 = (1.27645071 * fTemp131);
			double fTemp133 = (fConst31 * fRec243[1]);
			double fTemp134 = (fConst33 * double(input10[i]));
			double fTemp135 = (fConst34 * fRec246[1]);
			double fTemp136 = (fConst35 * fRec249[1]);
			fRec251[0] = (fTemp134 + (fTemp135 + (fRec251[1] + fTemp136)));
			fRec249[0] = fRec251[0];
			double fRec250 = ((fTemp136 + fTemp135) + fTemp134);
			fRec248[0] = (fRec249[0] + fRec248[1]);
			fRec246[0] = fRec248[0];
			double fRec247 = fRec250;
			fRec245[0] = (fTemp133 + (fRec247 + fRec245[1]));
			fRec243[0] = fRec245[0];
			double fRec244 = (fRec247 + fTemp133);
			fRec242[0] = (fRec244 - (((fTemp2 * fRec242[2]) + (2.0 * (fTemp3 * fRec242[1]))) / fTemp4));
			double fTemp137 = (((fTemp1 * (fRec242[2] + (fRec242[0] + (2.0 * fRec242[1])))) / fTemp5) + (0.93701139950000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec242[1]) + ((fRec242[0] + fRec242[2]) / fTemp4))))));
			double fTemp138 = (4.5065457489999998 * fTemp137);
			double fTemp139 = (fConst37 * double(input8[i]));
			double fTemp140 = (fConst38 * fRec253[1]);
			double fTemp141 = (fConst39 * fRec256[1]);
			fRec258[0] = (fTemp139 + (fTemp140 + (fRec258[1] + fTemp141)));
			fRec256[0] = fRec258[0];
			double fRec257 = ((fTemp141 + fTemp140) + fTemp139);
			fRec255[0] = (fRec256[0] + fRec255[1]);
			fRec253[0] = fRec255[0];
			double fRec254 = fRec257;
			fRec252[0] = (fRec254 - (((fTemp2 * fRec252[2]) + (2.0 * (fTemp3 * fRec252[1]))) / fTemp4));
			double fTemp142 = (((fTemp1 * (fRec252[2] + (fRec252[0] + (2.0 * fRec252[1])))) / fTemp5) + (1.0700688140000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec252[1]) + ((fRec252[0] + fRec252[2]) / fTemp4))))));
			double fTemp143 = (4.1512615999999998 * fTemp142);
			double fTemp144 = (fConst37 * double(input7[i]));
			double fTemp145 = (fConst38 * fRec260[1]);
			double fTemp146 = (fConst39 * fRec263[1]);
			fRec265[0] = (fTemp144 + (fTemp145 + (fRec265[1] + fTemp146)));
			fRec263[0] = fRec265[0];
			double fRec264 = ((fTemp146 + fTemp145) + fTemp144);
			fRec262[0] = (fRec263[0] + fRec262[1]);
			fRec260[0] = fRec262[0];
			double fRec261 = fRec264;
			fRec259[0] = (fRec261 - (((fTemp2 * fRec259[2]) + (2.0 * (fTemp3 * fRec259[1]))) / fTemp4));
			double fTemp147 = (((fTemp1 * (fRec259[2] + (fRec259[0] + (2.0 * fRec259[1])))) / fTemp5) + (1.0700688140000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec259[1]) + ((fRec259[0] + fRec259[2]) / fTemp4))))));
			double fTemp148 = (2.062082545 * fTemp147);
			double fTemp149 = (fConst37 * double(input5[i]));
			double fTemp150 = (fConst38 * fRec267[1]);
			double fTemp151 = (fConst39 * fRec270[1]);
			fRec272[0] = (fTemp149 + (fTemp150 + (fRec272[1] + fTemp151)));
			fRec270[0] = fRec272[0];
			double fRec271 = ((fTemp151 + fTemp150) + fTemp149);
			fRec269[0] = (fRec270[0] + fRec269[1]);
			fRec267[0] = fRec269[0];
			double fRec268 = fRec271;
			fRec266[0] = (fRec268 - (((fTemp2 * fRec266[2]) + (2.0 * (fTemp3 * fRec266[1]))) / fTemp4));
			double fTemp152 = (((fTemp1 * (fRec266[2] + (fRec266[0] + (2.0 * fRec266[1])))) / fTemp5) + (1.0700688140000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec266[1]) + ((fRec266[0] + fRec266[2]) / fTemp4))))));
			double fTemp153 = (1.778687012 * fTemp152);
			double fTemp154 = (fConst41 * double(input3[i]));
			double fTemp155 = (fConst42 * fRec274[1]);
			fRec276[0] = (fTemp154 + (fRec276[1] + fTemp155));
			fRec274[0] = fRec276[0];
			double fRec275 = (fTemp155 + fTemp154);
			fRec273[0] = (fRec275 - (((fTemp2 * fRec273[2]) + (2.0 * (fTemp3 * fRec273[1]))) / fTemp4));
			double fTemp156 = (((fTemp1 * (fRec273[2] + (fRec273[0] + (2.0 * fRec273[1])))) / fTemp5) + (1.163423471 * (fRec3[0] * (0.0 - ((fTemp6 * fRec273[1]) + ((fRec273[0] + fRec273[2]) / fTemp4))))));
			double fTemp157 = (7.8623176140000002 * fTemp156);
			double fTemp158 = (fConst41 * double(input2[i]));
			double fTemp159 = (fConst42 * fRec278[1]);
			fRec280[0] = (fTemp158 + (fRec280[1] + fTemp159));
			fRec278[0] = fRec280[0];
			double fRec279 = (fTemp159 + fTemp158);
			fRec277[0] = (fRec279 - (((fTemp2 * fRec277[2]) + (2.0 * (fTemp3 * fRec277[1]))) / fTemp4));
			double fTemp160 = (((fTemp1 * (fRec277[2] + (fRec277[0] + (2.0 * fRec277[1])))) / fTemp5) + (1.163423471 * (fRec3[0] * (0.0 - ((fTemp6 * fRec277[1]) + ((fRec277[0] + fRec277[2]) / fTemp4))))));
			double fTemp161 = (1.0164701089999999 * fTemp160);
			fRec281[0] = (double(input0[i]) - (((fRec281[2] * fTemp2) + (2.0 * (fRec281[1] * fTemp3))) / fTemp4));
			double fTemp162 = (((fTemp1 * (fRec281[2] + (fRec281[0] + (2.0 * fRec281[1])))) / fTemp5) + (1.2115336459999999 * (fRec3[0] * (0.0 - ((fRec281[1] * fTemp6) + ((fRec281[0] + fRec281[2]) / fTemp4))))));
			double fTemp163 = (5.2632448969999999 * fTemp162);
			double fTemp164 = (fConst41 * double(input1[i]));
			double fTemp165 = (fConst42 * fRec283[1]);
			fRec285[0] = (fTemp164 + (fRec285[1] + fTemp165));
			fRec283[0] = fRec285[0];
			double fRec284 = (fTemp165 + fTemp164);
			fRec282[0] = (fRec284 - (((fTemp2 * fRec282[2]) + (2.0 * (fTemp3 * fRec282[1]))) / fTemp4));
			double fTemp166 = (((fTemp1 * (fRec282[2] + (fRec282[0] + (2.0 * fRec282[1])))) / fTemp5) + (1.163423471 * (fRec3[0] * (0.0 - ((fTemp6 * fRec282[1]) + ((fRec282[0] + fRec282[2]) / fTemp4))))));
			double fTemp167 = (4.8791292029999997 * fTemp166);
			double fTemp168 = (fConst37 * double(input4[i]));
			double fTemp169 = (fConst38 * fRec287[1]);
			double fTemp170 = (fConst39 * fRec290[1]);
			fRec292[0] = (fTemp168 + (fTemp169 + (fRec292[1] + fTemp170)));
			fRec290[0] = fRec292[0];
			double fRec291 = ((fTemp170 + fTemp169) + fTemp168);
			fRec289[0] = (fRec290[0] + fRec289[1]);
			fRec287[0] = fRec289[0];
			double fRec288 = fRec291;
			fRec286[0] = (fRec288 - (((fTemp2 * fRec286[2]) + (2.0 * (fTemp3 * fRec286[1]))) / fTemp4));
			double fTemp171 = (((fTemp1 * (fRec286[2] + (fRec286[0] + (2.0 * fRec286[1])))) / fTemp5) + (1.0700688140000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec286[1]) + ((fRec286[0] + fRec286[2]) / fTemp4))))));
			double fTemp172 = (8.4886022010000008 * fTemp171);
			double fTemp173 = (fConst31 * fRec294[1]);
			double fTemp174 = (fConst33 * double(input9[i]));
			double fTemp175 = (fConst34 * fRec297[1]);
			double fTemp176 = (fConst35 * fRec300[1]);
			fRec302[0] = (fTemp174 + (fTemp175 + (fRec302[1] + fTemp176)));
			fRec300[0] = fRec302[0];
			double fRec301 = ((fTemp176 + fTemp175) + fTemp174);
			fRec299[0] = (fRec300[0] + fRec299[1]);
			fRec297[0] = fRec299[0];
			double fRec298 = fRec301;
			fRec296[0] = (fTemp173 + (fRec298 + fRec296[1]));
			fRec294[0] = fRec296[0];
			double fRec295 = (fRec298 + fTemp173);
			fRec293[0] = (fRec295 - (((fTemp2 * fRec293[2]) + (2.0 * (fTemp3 * fRec293[1]))) / fTemp4));
			double fTemp177 = (((fTemp1 * (fRec293[2] + (fRec293[0] + (2.0 * fRec293[1])))) / fTemp5) + (0.93701139950000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec293[1]) + ((fRec293[0] + fRec293[2]) / fTemp4))))));
			double fTemp178 = (9.7683374569999994 * fTemp177);
			double fTemp179 = (fConst24 * fRec304[1]);
			double fTemp180 = (fConst27 * double(input16[i]));
			double fTemp181 = (fConst28 * fRec310[1]);
			double fTemp182 = (fConst29 * fRec313[1]);
			fRec315[0] = (fTemp180 + (fTemp181 + (fRec315[1] + fTemp182)));
			fRec313[0] = fRec315[0];
			double fRec314 = ((fTemp182 + fTemp181) + fTemp180);
			fRec312[0] = (fRec313[0] + fRec312[1]);
			fRec310[0] = fRec312[0];
			double fRec311 = fRec314;
			double fTemp183 = (fRec311 + (fConst25 * fRec307[1]));
			fRec309[0] = (fTemp179 + (fRec309[1] + fTemp183));
			fRec307[0] = fRec309[0];
			double fRec308 = (fTemp179 + fTemp183);
			fRec306[0] = (fRec307[0] + fRec306[1]);
			fRec304[0] = fRec306[0];
			double fRec305 = fRec308;
			fRec303[0] = (fRec305 - (((fTemp2 * fRec303[2]) + (2.0 * (fTemp3 * fRec303[1]))) / fTemp4));
			double fTemp184 = (((fTemp1 * (fRec303[2] + (fRec303[0] + (2.0 * fRec303[1])))) / fTemp5) + (0.77210283830000004 * (fRec3[0] * (0.0 - ((fTemp6 * fRec303[1]) + ((fRec303[0] + fRec303[2]) / fTemp4))))));
			double fTemp185 = (4.7433712540000004 * fTemp184);
			double fTemp186 = (fConst17 * fRec320[1]);
			double fTemp187 = (fConst18 * fRec323[1]);
			double fTemp188 = (fConst20 * double(input25[i]));
			double fTemp189 = (fConst21 * fRec326[1]);
			double fTemp190 = (fConst22 * fRec329[1]);
			fRec331[0] = (fTemp188 + (fTemp189 + (fRec331[1] + fTemp190)));
			fRec329[0] = fRec331[0];
			double fRec330 = ((fTemp190 + fTemp189) + fTemp188);
			fRec328[0] = (fRec329[0] + fRec328[1]);
			fRec326[0] = fRec328[0];
			double fRec327 = fRec330;
			fRec325[0] = (fTemp186 + (fTemp187 + (fRec327 + fRec325[1])));
			fRec323[0] = fRec325[0];
			double fRec324 = (fTemp186 + (fRec327 + fTemp187));
			fRec322[0] = (fRec323[0] + fRec322[1]);
			fRec320[0] = fRec322[0];
			double fRec321 = fRec324;
			double fTemp191 = (fRec321 + (fConst15 * fRec317[1]));
			fRec319[0] = (fRec319[1] + fTemp191);
			fRec317[0] = fRec319[0];
			double fRec318 = fTemp191;
			fRec316[0] = (fRec318 - (((fTemp2 * fRec316[2]) + (2.0 * (fTemp3 * fRec316[1]))) / fTemp4));
			double fTemp192 = (((fTemp1 * (fRec316[2] + (fRec316[0] + (2.0 * fRec316[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec316[1]) + ((fRec316[0] + fRec316[2]) / fTemp4))))));
			double fTemp193 = (5.3847432929999997 * fTemp192);
			double fTemp194 = (fConst8 * fRec339[1]);
			double fTemp195 = (fConst9 * fRec342[1]);
			double fTemp196 = (fConst11 * double(input36[i]));
			double fTemp197 = (fConst12 * fRec345[1]);
			double fTemp198 = (fConst13 * fRec348[1]);
			fRec350[0] = (fTemp196 + (fTemp197 + (fRec350[1] + fTemp198)));
			fRec348[0] = fRec350[0];
			double fRec349 = ((fTemp198 + fTemp197) + fTemp196);
			fRec347[0] = (fRec348[0] + fRec347[1]);
			fRec345[0] = fRec347[0];
			double fRec346 = fRec349;
			fRec344[0] = (fTemp194 + (fTemp195 + (fRec346 + fRec344[1])));
			fRec342[0] = fRec344[0];
			double fRec343 = (fTemp194 + (fRec346 + fTemp195));
			fRec341[0] = (fRec342[0] + fRec341[1]);
			fRec339[0] = fRec341[0];
			double fRec340 = fRec343;
			double fTemp199 = ((fConst5 * fRec333[1]) + (fRec340 + (fConst6 * fRec336[1])));
			fRec338[0] = (fRec338[1] + fTemp199);
			fRec336[0] = fRec338[0];
			double fRec337 = fTemp199;
			fRec335[0] = (fRec336[0] + fRec335[1]);
			fRec333[0] = fRec335[0];
			double fRec334 = fRec337;
			fRec332[0] = (fRec334 - (((fTemp2 * fRec332[2]) + (2.0 * (fTemp3 * fRec332[1]))) / fTemp4));
			double fTemp200 = (((fTemp1 * (fRec332[2] + (fRec332[0] + (2.0 * fRec332[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec332[1]) + ((fRec332[0] + fRec332[2]) / fTemp4))))));
			double fTemp201 = (0.11448366460000001 * fTemp200);
			fRec351[0] = (double(input54[i]) - (((fTemp2 * fRec351[2]) + (2.0 * (fTemp3 * fRec351[1]))) / fTemp4));
			double fTemp202 = (((fTemp1 * (fRec351[2] + (fRec351[0] + (2.0 * fRec351[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec351[1]) + ((fRec351[0] + fRec351[2]) / fTemp4))))));
			double fTemp203 = (3.5879007380000001 * fTemp202);
			fRec352[0] = (double(input63[i]) - (((fTemp2 * fRec352[2]) + (2.0 * (fTemp3 * fRec352[1]))) / fTemp4));
			double fTemp204 = (((fTemp1 * (fRec352[2] + (fRec352[0] + (2.0 * fRec352[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec352[1]) + ((fRec352[0] + fRec352[2]) / fTemp4))))));
			double fTemp205 = (11.888618689999999 * fTemp204);
			fRec353[0] = (double(input62[i]) - (((fTemp2 * fRec353[2]) + (2.0 * (fTemp3 * fRec353[1]))) / fTemp4));
			double fTemp206 = (((fTemp1 * (fRec353[2] + (fRec353[0] + (2.0 * fRec353[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec353[1]) + ((fRec353[0] + fRec353[2]) / fTemp4))))));
			double fTemp207 = (8.3969624140000008 * fTemp206);
			fRec354[0] = (double(input56[i]) - (((fTemp2 * fRec354[2]) + (2.0 * (fTemp3 * fRec354[1]))) / fTemp4));
			double fTemp208 = (((fTemp1 * (fRec354[2] + (fRec354[0] + (2.0 * fRec354[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec354[1]) + ((fRec354[0] + fRec354[2]) / fTemp4))))));
			double fTemp209 = (5.4921676210000001 * fTemp208);
			fRec355[0] = (double(input53[i]) - (((fTemp2 * fRec355[2]) + (2.0 * (fTemp3 * fRec355[1]))) / fTemp4));
			double fTemp210 = (((fTemp1 * (fRec355[2] + (fRec355[0] + (2.0 * fRec355[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec355[1]) + ((fRec355[0] + fRec355[2]) / fTemp4))))));
			double fTemp211 = (0.020180471500000002 * fTemp210);
			fRec356[0] = (double(input52[i]) - (((fTemp2 * fRec356[2]) + (2.0 * (fTemp3 * fRec356[1]))) / fTemp4));
			double fTemp212 = (((fTemp1 * (fRec356[2] + (fRec356[0] + (2.0 * fRec356[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec356[1]) + ((fRec356[0] + fRec356[2]) / fTemp4))))));
			double fTemp213 = (10.34373482 * fTemp212);
			fRec357[0] = (double(input51[i]) - (((fTemp2 * fRec357[2]) + (2.0 * (fTemp3 * fRec357[1]))) / fTemp4));
			double fTemp214 = (((fTemp1 * (fRec357[2] + (fRec357[0] + (2.0 * fRec357[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec357[1]) + ((fRec357[0] + fRec357[2]) / fTemp4))))));
			double fTemp215 = (2.306399592 * fTemp214);
			fRec358[0] = (double(input50[i]) - (((fTemp2 * fRec358[2]) + (2.0 * (fTemp3 * fRec358[1]))) / fTemp4));
			double fTemp216 = (((fTemp1 * (fRec358[2] + (fRec358[0] + (2.0 * fRec358[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec358[1]) + ((fRec358[0] + fRec358[2]) / fTemp4))))));
			double fTemp217 = (0.20890721719999999 * fTemp216);
			double fTemp218 = (fConst5 * fRec360[1]);
			double fTemp219 = (fConst6 * fRec363[1]);
			double fTemp220 = (fConst8 * fRec366[1]);
			double fTemp221 = (fConst9 * fRec369[1]);
			double fTemp222 = (fConst11 * double(input48[i]));
			double fTemp223 = (fConst12 * fRec372[1]);
			double fTemp224 = (fConst13 * fRec375[1]);
			fRec377[0] = (fTemp222 + (fTemp223 + (fRec377[1] + fTemp224)));
			fRec375[0] = fRec377[0];
			double fRec376 = ((fTemp224 + fTemp223) + fTemp222);
			fRec374[0] = (fRec375[0] + fRec374[1]);
			fRec372[0] = fRec374[0];
			double fRec373 = fRec376;
			fRec371[0] = (fTemp220 + (fTemp221 + (fRec373 + fRec371[1])));
			fRec369[0] = fRec371[0];
			double fRec370 = (fTemp220 + (fRec373 + fTemp221));
			fRec368[0] = (fRec369[0] + fRec368[1]);
			fRec366[0] = fRec368[0];
			double fRec367 = fRec370;
			fRec365[0] = (fTemp218 + (fTemp219 + (fRec367 + fRec365[1])));
			fRec363[0] = fRec365[0];
			double fRec364 = (fTemp218 + (fRec367 + fTemp219));
			fRec362[0] = (fRec363[0] + fRec362[1]);
			fRec360[0] = fRec362[0];
			double fRec361 = fRec364;
			fRec359[0] = (fRec361 - (((fTemp2 * fRec359[2]) + (2.0 * (fTemp3 * fRec359[1]))) / fTemp4));
			double fTemp225 = (((fTemp1 * (fRec359[2] + (fRec359[0] + (2.0 * fRec359[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec359[1]) + ((fRec359[0] + fRec359[2]) / fTemp4))))));
			double fTemp226 = (10.63728759 * fTemp225);
			double fTemp227 = (fConst5 * fRec379[1]);
			double fTemp228 = (fConst6 * fRec382[1]);
			double fTemp229 = (fConst8 * fRec385[1]);
			double fTemp230 = (fConst9 * fRec388[1]);
			double fTemp231 = (fConst11 * double(input47[i]));
			double fTemp232 = (fConst12 * fRec391[1]);
			double fTemp233 = (fConst13 * fRec394[1]);
			fRec396[0] = (fTemp231 + (fTemp232 + (fRec396[1] + fTemp233)));
			fRec394[0] = fRec396[0];
			double fRec395 = ((fTemp233 + fTemp232) + fTemp231);
			fRec393[0] = (fRec394[0] + fRec393[1]);
			fRec391[0] = fRec393[0];
			double fRec392 = fRec395;
			fRec390[0] = (fTemp229 + (fTemp230 + (fRec392 + fRec390[1])));
			fRec388[0] = fRec390[0];
			double fRec389 = (fTemp229 + (fRec392 + fTemp230));
			fRec387[0] = (fRec388[0] + fRec387[1]);
			fRec385[0] = fRec387[0];
			double fRec386 = fRec389;
			fRec384[0] = (fTemp227 + (fTemp228 + (fRec386 + fRec384[1])));
			fRec382[0] = fRec384[0];
			double fRec383 = (fTemp227 + (fRec386 + fTemp228));
			fRec381[0] = (fRec382[0] + fRec381[1]);
			fRec379[0] = fRec381[0];
			double fRec380 = fRec383;
			fRec378[0] = (fRec380 - (((fTemp2 * fRec378[2]) + (2.0 * (fTemp3 * fRec378[1]))) / fTemp4));
			double fTemp234 = (((fTemp1 * (fRec378[2] + (fRec378[0] + (2.0 * fRec378[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec378[1]) + ((fRec378[0] + fRec378[2]) / fTemp4))))));
			double fTemp235 = (6.9309434830000001 * fTemp234);
			double fTemp236 = (fConst5 * fRec398[1]);
			double fTemp237 = (fConst6 * fRec401[1]);
			double fTemp238 = (fConst8 * fRec404[1]);
			double fTemp239 = (fConst9 * fRec407[1]);
			double fTemp240 = (fConst11 * double(input46[i]));
			double fTemp241 = (fConst12 * fRec410[1]);
			double fTemp242 = (fConst13 * fRec413[1]);
			fRec415[0] = (fTemp240 + (fTemp241 + (fRec415[1] + fTemp242)));
			fRec413[0] = fRec415[0];
			double fRec414 = ((fTemp242 + fTemp241) + fTemp240);
			fRec412[0] = (fRec413[0] + fRec412[1]);
			fRec410[0] = fRec412[0];
			double fRec411 = fRec414;
			fRec409[0] = (fTemp238 + (fTemp239 + (fRec411 + fRec409[1])));
			fRec407[0] = fRec409[0];
			double fRec408 = (fTemp238 + (fRec411 + fTemp239));
			fRec406[0] = (fRec407[0] + fRec406[1]);
			fRec404[0] = fRec406[0];
			double fRec405 = fRec408;
			fRec403[0] = (fTemp236 + (fTemp237 + (fRec405 + fRec403[1])));
			fRec401[0] = fRec403[0];
			double fRec402 = (fTemp236 + (fRec405 + fTemp237));
			fRec400[0] = (fRec401[0] + fRec400[1]);
			fRec398[0] = fRec400[0];
			double fRec399 = fRec402;
			fRec397[0] = (fRec399 - (((fTemp2 * fRec397[2]) + (2.0 * (fTemp3 * fRec397[1]))) / fTemp4));
			double fTemp243 = (((fTemp1 * (fRec397[2] + (fRec397[0] + (2.0 * fRec397[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec397[1]) + ((fRec397[0] + fRec397[2]) / fTemp4))))));
			double fTemp244 = (1.4596072090000001 * fTemp243);
			double fTemp245 = (fConst5 * fRec417[1]);
			double fTemp246 = (fConst6 * fRec420[1]);
			double fTemp247 = (fConst8 * fRec423[1]);
			double fTemp248 = (fConst9 * fRec426[1]);
			double fTemp249 = (fConst11 * double(input45[i]));
			double fTemp250 = (fConst12 * fRec429[1]);
			double fTemp251 = (fConst13 * fRec432[1]);
			fRec434[0] = (fTemp249 + (fTemp250 + (fRec434[1] + fTemp251)));
			fRec432[0] = fRec434[0];
			double fRec433 = ((fTemp251 + fTemp250) + fTemp249);
			fRec431[0] = (fRec432[0] + fRec431[1]);
			fRec429[0] = fRec431[0];
			double fRec430 = fRec433;
			fRec428[0] = (fTemp247 + (fTemp248 + (fRec430 + fRec428[1])));
			fRec426[0] = fRec428[0];
			double fRec427 = (fTemp247 + (fRec430 + fTemp248));
			fRec425[0] = (fRec426[0] + fRec425[1]);
			fRec423[0] = fRec425[0];
			double fRec424 = fRec427;
			fRec422[0] = (fTemp245 + (fTemp246 + (fRec424 + fRec422[1])));
			fRec420[0] = fRec422[0];
			double fRec421 = (fTemp245 + (fRec424 + fTemp246));
			fRec419[0] = (fRec420[0] + fRec419[1]);
			fRec417[0] = fRec419[0];
			double fRec418 = fRec421;
			fRec416[0] = (fRec418 - (((fTemp2 * fRec416[2]) + (2.0 * (fTemp3 * fRec416[1]))) / fTemp4));
			double fTemp252 = (((fTemp1 * (fRec416[2] + (fRec416[0] + (2.0 * fRec416[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec416[1]) + ((fRec416[0] + fRec416[2]) / fTemp4))))));
			double fTemp253 = (0.57046219320000002 * fTemp252);
			double fTemp254 = (fConst15 * fRec436[1]);
			double fTemp255 = (fConst17 * fRec439[1]);
			double fTemp256 = (fConst18 * fRec442[1]);
			double fTemp257 = (fConst20 * double(input35[i]));
			double fTemp258 = (fConst21 * fRec445[1]);
			double fTemp259 = (fConst22 * fRec448[1]);
			fRec450[0] = (fTemp257 + (fTemp258 + (fRec450[1] + fTemp259)));
			fRec448[0] = fRec450[0];
			double fRec449 = ((fTemp259 + fTemp258) + fTemp257);
			fRec447[0] = (fRec448[0] + fRec447[1]);
			fRec445[0] = fRec447[0];
			double fRec446 = fRec449;
			fRec444[0] = (fTemp255 + (fTemp256 + (fRec446 + fRec444[1])));
			fRec442[0] = fRec444[0];
			double fRec443 = (fTemp255 + (fRec446 + fTemp256));
			fRec441[0] = (fRec442[0] + fRec441[1]);
			fRec439[0] = fRec441[0];
			double fRec440 = fRec443;
			fRec438[0] = (fTemp254 + (fRec440 + fRec438[1]));
			fRec436[0] = fRec438[0];
			double fRec437 = (fRec440 + fTemp254);
			fRec435[0] = (fRec437 - (((fTemp2 * fRec435[2]) + (2.0 * (fTemp3 * fRec435[1]))) / fTemp4));
			double fTemp260 = (((fTemp1 * (fRec435[2] + (fRec435[0] + (2.0 * fRec435[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec435[1]) + ((fRec435[0] + fRec435[2]) / fTemp4))))));
			double fTemp261 = (9.2773047549999994 * fTemp260);
			double fTemp262 = (fConst17 * fRec455[1]);
			double fTemp263 = (fConst18 * fRec458[1]);
			double fTemp264 = (fConst20 * double(input34[i]));
			double fTemp265 = (fConst21 * fRec461[1]);
			double fTemp266 = (fConst22 * fRec464[1]);
			fRec466[0] = (fTemp264 + (fTemp265 + (fRec466[1] + fTemp266)));
			fRec464[0] = fRec466[0];
			double fRec465 = ((fTemp266 + fTemp265) + fTemp264);
			fRec463[0] = (fRec464[0] + fRec463[1]);
			fRec461[0] = fRec463[0];
			double fRec462 = fRec465;
			fRec460[0] = (fTemp262 + (fTemp263 + (fRec462 + fRec460[1])));
			fRec458[0] = fRec460[0];
			double fRec459 = (fTemp262 + (fRec462 + fTemp263));
			fRec457[0] = (fRec458[0] + fRec457[1]);
			fRec455[0] = fRec457[0];
			double fRec456 = fRec459;
			double fTemp267 = (fRec456 + (fConst15 * fRec452[1]));
			fRec454[0] = (fRec454[1] + fTemp267);
			fRec452[0] = fRec454[0];
			double fRec453 = fTemp267;
			fRec451[0] = (fRec453 - (((fTemp2 * fRec451[2]) + (2.0 * (fTemp3 * fRec451[1]))) / fTemp4));
			double fTemp268 = (((fTemp1 * (fRec451[2] + (fRec451[0] + (2.0 * fRec451[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec451[1]) + ((fRec451[0] + fRec451[2]) / fTemp4))))));
			double fTemp269 = (5.3233331579999996 * fTemp268);
			double fTemp270 = (fConst15 * fRec468[1]);
			double fTemp271 = (fConst17 * fRec471[1]);
			double fTemp272 = (fConst18 * fRec474[1]);
			double fTemp273 = (fConst20 * double(input33[i]));
			double fTemp274 = (fConst21 * fRec477[1]);
			double fTemp275 = (fConst22 * fRec480[1]);
			fRec482[0] = (fTemp273 + (fTemp274 + (fRec482[1] + fTemp275)));
			fRec480[0] = fRec482[0];
			double fRec481 = ((fTemp275 + fTemp274) + fTemp273);
			fRec479[0] = (fRec480[0] + fRec479[1]);
			fRec477[0] = fRec479[0];
			double fRec478 = fRec481;
			fRec476[0] = (fTemp271 + (fTemp272 + (fRec478 + fRec476[1])));
			fRec474[0] = fRec476[0];
			double fRec475 = (fTemp271 + (fRec478 + fTemp272));
			fRec473[0] = (fRec474[0] + fRec473[1]);
			fRec471[0] = fRec473[0];
			double fRec472 = fRec475;
			fRec470[0] = (fTemp270 + (fRec472 + fRec470[1]));
			fRec468[0] = fRec470[0];
			double fRec469 = (fRec472 + fTemp270);
			fRec467[0] = (fRec469 - (((fTemp2 * fRec467[2]) + (2.0 * (fTemp3 * fRec467[1]))) / fTemp4));
			double fTemp276 = (((fTemp1 * (fRec467[2] + (fRec467[0] + (2.0 * fRec467[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec467[1]) + ((fRec467[0] + fRec467[2]) / fTemp4))))));
			double fTemp277 = (1.103383668 * fTemp276);
			double fTemp278 = (fConst15 * fRec484[1]);
			double fTemp279 = (fConst17 * fRec487[1]);
			double fTemp280 = (fConst18 * fRec490[1]);
			double fTemp281 = (fConst20 * double(input32[i]));
			double fTemp282 = (fConst21 * fRec493[1]);
			double fTemp283 = (fConst22 * fRec496[1]);
			fRec498[0] = (fTemp281 + (fTemp282 + (fRec498[1] + fTemp283)));
			fRec496[0] = fRec498[0];
			double fRec497 = ((fTemp283 + fTemp282) + fTemp281);
			fRec495[0] = (fRec496[0] + fRec495[1]);
			fRec493[0] = fRec495[0];
			double fRec494 = fRec497;
			fRec492[0] = (fTemp279 + (fTemp280 + (fRec494 + fRec492[1])));
			fRec490[0] = fRec492[0];
			double fRec491 = (fTemp279 + (fRec494 + fTemp280));
			fRec489[0] = (fRec490[0] + fRec489[1]);
			fRec487[0] = fRec489[0];
			double fRec488 = fRec491;
			fRec486[0] = (fTemp278 + (fRec488 + fRec486[1]));
			fRec484[0] = fRec486[0];
			double fRec485 = (fRec488 + fTemp278);
			fRec483[0] = (fRec485 - (((fTemp2 * fRec483[2]) + (2.0 * (fTemp3 * fRec483[1]))) / fTemp4));
			double fTemp284 = (((fTemp1 * (fRec483[2] + (fRec483[0] + (2.0 * fRec483[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec483[1]) + ((fRec483[0] + fRec483[2]) / fTemp4))))));
			double fTemp285 = (3.1175058199999999 * fTemp284);
			double fTemp286 = (fConst15 * fRec500[1]);
			double fTemp287 = (fConst17 * fRec503[1]);
			double fTemp288 = (fConst18 * fRec506[1]);
			double fTemp289 = (fConst20 * double(input28[i]));
			double fTemp290 = (fConst21 * fRec509[1]);
			double fTemp291 = (fConst22 * fRec512[1]);
			fRec514[0] = (fTemp289 + (fTemp290 + (fRec514[1] + fTemp291)));
			fRec512[0] = fRec514[0];
			double fRec513 = ((fTemp291 + fTemp290) + fTemp289);
			fRec511[0] = (fRec512[0] + fRec511[1]);
			fRec509[0] = fRec511[0];
			double fRec510 = fRec513;
			fRec508[0] = (fTemp287 + (fTemp288 + (fRec510 + fRec508[1])));
			fRec506[0] = fRec508[0];
			double fRec507 = (fTemp287 + (fRec510 + fTemp288));
			fRec505[0] = (fRec506[0] + fRec505[1]);
			fRec503[0] = fRec505[0];
			double fRec504 = fRec507;
			fRec502[0] = (fTemp286 + (fRec504 + fRec502[1]));
			fRec500[0] = fRec502[0];
			double fRec501 = (fRec504 + fTemp286);
			fRec499[0] = (fRec501 - (((fTemp2 * fRec499[2]) + (2.0 * (fTemp3 * fRec499[1]))) / fTemp4));
			double fTemp292 = (((fTemp1 * (fRec499[2] + (fRec499[0] + (2.0 * fRec499[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec499[1]) + ((fRec499[0] + fRec499[2]) / fTemp4))))));
			double fTemp293 = (4.947528954 * fTemp292);
			double fTemp294 = (fConst24 * fRec516[1]);
			double fTemp295 = (fConst25 * fRec519[1]);
			double fTemp296 = (fConst27 * double(input24[i]));
			double fTemp297 = (fConst28 * fRec522[1]);
			double fTemp298 = (fConst29 * fRec525[1]);
			fRec527[0] = (fTemp296 + (fTemp297 + (fRec527[1] + fTemp298)));
			fRec525[0] = fRec527[0];
			double fRec526 = ((fTemp298 + fTemp297) + fTemp296);
			fRec524[0] = (fRec525[0] + fRec524[1]);
			fRec522[0] = fRec524[0];
			double fRec523 = fRec526;
			fRec521[0] = (fTemp294 + (fTemp295 + (fRec523 + fRec521[1])));
			fRec519[0] = fRec521[0];
			double fRec520 = (fTemp294 + (fRec523 + fTemp295));
			fRec518[0] = (fRec519[0] + fRec518[1]);
			fRec516[0] = fRec518[0];
			double fRec517 = fRec520;
			fRec515[0] = (fRec517 - (((fTemp2 * fRec515[2]) + (2.0 * (fTemp3 * fRec515[1]))) / fTemp4));
			double fTemp299 = (((fTemp1 * (fRec515[2] + (fRec515[0] + (2.0 * fRec515[1])))) / fTemp5) + (0.77210283830000004 * (fRec3[0] * (0.0 - ((fTemp6 * fRec515[1]) + ((fRec515[0] + fRec515[2]) / fTemp4))))));
			double fTemp300 = (5.5419875850000002 * fTemp299);
			double fTemp301 = (fConst24 * fRec529[1]);
			double fTemp302 = (fConst25 * fRec532[1]);
			double fTemp303 = (fConst27 * double(input23[i]));
			double fTemp304 = (fConst28 * fRec535[1]);
			double fTemp305 = (fConst29 * fRec538[1]);
			fRec540[0] = (fTemp303 + (fTemp304 + (fRec540[1] + fTemp305)));
			fRec538[0] = fRec540[0];
			double fRec539 = ((fTemp305 + fTemp304) + fTemp303);
			fRec537[0] = (fRec538[0] + fRec537[1]);
			fRec535[0] = fRec537[0];
			double fRec536 = fRec539;
			fRec534[0] = (fTemp301 + (fTemp302 + (fRec536 + fRec534[1])));
			fRec532[0] = fRec534[0];
			double fRec533 = (fTemp301 + (fRec536 + fTemp302));
			fRec531[0] = (fRec532[0] + fRec531[1]);
			fRec529[0] = fRec531[0];
			double fRec530 = fRec533;
			fRec528[0] = (fRec530 - (((fTemp2 * fRec528[2]) + (2.0 * (fTemp3 * fRec528[1]))) / fTemp4));
			double fTemp306 = (((fTemp1 * (fRec528[2] + (fRec528[0] + (2.0 * fRec528[1])))) / fTemp5) + (0.77210283830000004 * (fRec3[0] * (0.0 - ((fTemp6 * fRec528[1]) + ((fRec528[0] + fRec528[2]) / fTemp4))))));
			double fTemp307 = (0.85967434779999996 * fTemp306);
			double fTemp308 = (fConst24 * fRec542[1]);
			double fTemp309 = (fConst25 * fRec545[1]);
			double fTemp310 = (fConst27 * double(input22[i]));
			double fTemp311 = (fConst28 * fRec548[1]);
			double fTemp312 = (fConst29 * fRec551[1]);
			fRec553[0] = (fTemp310 + (fTemp311 + (fRec553[1] + fTemp312)));
			fRec551[0] = fRec553[0];
			double fRec552 = ((fTemp312 + fTemp311) + fTemp310);
			fRec550[0] = (fRec551[0] + fRec550[1]);
			fRec548[0] = fRec550[0];
			double fRec549 = fRec552;
			fRec547[0] = (fTemp308 + (fTemp309 + (fRec549 + fRec547[1])));
			fRec545[0] = fRec547[0];
			double fRec546 = (fTemp308 + (fRec549 + fTemp309));
			fRec544[0] = (fRec545[0] + fRec544[1]);
			fRec542[0] = fRec544[0];
			double fRec543 = fRec546;
			fRec541[0] = (fRec543 - (((fTemp2 * fRec541[2]) + (2.0 * (fTemp3 * fRec541[1]))) / fTemp4));
			double fTemp313 = (((fTemp1 * (fRec541[2] + (fRec541[0] + (2.0 * fRec541[1])))) / fTemp5) + (0.77210283830000004 * (fRec3[0] * (0.0 - ((fTemp6 * fRec541[1]) + ((fRec541[0] + fRec541[2]) / fTemp4))))));
			double fTemp314 = (3.1135790189999999 * fTemp313);
			double fTemp315 = (fConst24 * fRec555[1]);
			double fTemp316 = (fConst25 * fRec558[1]);
			double fTemp317 = (fConst27 * double(input21[i]));
			double fTemp318 = (fConst28 * fRec561[1]);
			double fTemp319 = (fConst29 * fRec564[1]);
			fRec566[0] = (fTemp317 + (fTemp318 + (fRec566[1] + fTemp319)));
			fRec564[0] = fRec566[0];
			double fRec565 = ((fTemp319 + fTemp318) + fTemp317);
			fRec563[0] = (fRec564[0] + fRec563[1]);
			fRec561[0] = fRec563[0];
			double fRec562 = fRec565;
			fRec560[0] = (fTemp315 + (fTemp316 + (fRec562 + fRec560[1])));
			fRec558[0] = fRec560[0];
			double fRec559 = (fTemp315 + (fRec562 + fTemp316));
			fRec557[0] = (fRec558[0] + fRec557[1]);
			fRec555[0] = fRec557[0];
			double fRec556 = fRec559;
			fRec554[0] = (fRec556 - (((fTemp2 * fRec554[2]) + (2.0 * (fTemp3 * fRec554[1]))) / fTemp4));
			double fTemp320 = (((fTemp1 * (fRec554[2] + (fRec554[0] + (2.0 * fRec554[1])))) / fTemp5) + (0.77210283830000004 * (fRec3[0] * (0.0 - ((fTemp6 * fRec554[1]) + ((fRec554[0] + fRec554[2]) / fTemp4))))));
			double fTemp321 = (4.2143797479999998 * fTemp320);
			double fTemp322 = (fConst24 * fRec568[1]);
			double fTemp323 = (fConst25 * fRec571[1]);
			double fTemp324 = (fConst27 * double(input19[i]));
			double fTemp325 = (fConst28 * fRec574[1]);
			double fTemp326 = (fConst29 * fRec577[1]);
			fRec579[0] = (fTemp324 + (fTemp325 + (fRec579[1] + fTemp326)));
			fRec577[0] = fRec579[0];
			double fRec578 = ((fTemp326 + fTemp325) + fTemp324);
			fRec576[0] = (fRec577[0] + fRec576[1]);
			fRec574[0] = fRec576[0];
			double fRec575 = fRec578;
			fRec573[0] = (fTemp322 + (fTemp323 + (fRec575 + fRec573[1])));
			fRec571[0] = fRec573[0];
			double fRec572 = (fTemp322 + (fRec575 + fTemp323));
			fRec570[0] = (fRec571[0] + fRec570[1]);
			fRec568[0] = fRec570[0];
			double fRec569 = fRec572;
			fRec567[0] = (fRec569 - (((fTemp2 * fRec567[2]) + (2.0 * (fTemp3 * fRec567[1]))) / fTemp4));
			double fTemp327 = (((fTemp1 * (fRec567[2] + (fRec567[0] + (2.0 * fRec567[1])))) / fTemp5) + (0.77210283830000004 * (fRec3[0] * (0.0 - ((fTemp6 * fRec567[1]) + ((fRec567[0] + fRec567[2]) / fTemp4))))));
			double fTemp328 = (2.4142196359999999 * fTemp327);
			double fTemp329 = (fConst31 * fRec581[1]);
			double fTemp330 = (fConst33 * double(input15[i]));
			double fTemp331 = (fConst34 * fRec584[1]);
			double fTemp332 = (fConst35 * fRec587[1]);
			fRec589[0] = (fTemp330 + (fTemp331 + (fRec589[1] + fTemp332)));
			fRec587[0] = fRec589[0];
			double fRec588 = ((fTemp332 + fTemp331) + fTemp330);
			fRec586[0] = (fRec587[0] + fRec586[1]);
			fRec584[0] = fRec586[0];
			double fRec585 = fRec588;
			fRec583[0] = (fTemp329 + (fRec585 + fRec583[1]));
			fRec581[0] = fRec583[0];
			double fRec582 = (fRec585 + fTemp329);
			fRec580[0] = (fRec582 - (((fTemp2 * fRec580[2]) + (2.0 * (fTemp3 * fRec580[1]))) / fTemp4));
			double fTemp333 = (((fTemp1 * (fRec580[2] + (fRec580[0] + (2.0 * fRec580[1])))) / fTemp5) + (0.93701139950000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec580[1]) + ((fRec580[0] + fRec580[2]) / fTemp4))))));
			double fTemp334 = (0.3121038377 * fTemp333);
			double fTemp335 = (fConst31 * fRec591[1]);
			double fTemp336 = (fConst33 * double(input13[i]));
			double fTemp337 = (fConst34 * fRec594[1]);
			double fTemp338 = (fConst35 * fRec597[1]);
			fRec599[0] = (fTemp336 + (fTemp337 + (fRec599[1] + fTemp338)));
			fRec597[0] = fRec599[0];
			double fRec598 = ((fTemp338 + fTemp337) + fTemp336);
			fRec596[0] = (fRec597[0] + fRec596[1]);
			fRec594[0] = fRec596[0];
			double fRec595 = fRec598;
			fRec593[0] = (fTemp335 + (fRec595 + fRec593[1]));
			fRec591[0] = fRec593[0];
			double fRec592 = (fRec595 + fTemp335);
			fRec590[0] = (fRec592 - (((fTemp2 * fRec590[2]) + (2.0 * (fTemp3 * fRec590[1]))) / fTemp4));
			double fTemp339 = (((fTemp1 * (fRec590[2] + (fRec590[0] + (2.0 * fRec590[1])))) / fTemp5) + (0.93701139950000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec590[1]) + ((fRec590[0] + fRec590[2]) / fTemp4))))));
			double fTemp340 = (5.1071324929999999 * fTemp339);
			double fTemp341 = (fConst31 * fRec601[1]);
			double fTemp342 = (fConst33 * double(input12[i]));
			double fTemp343 = (fConst34 * fRec604[1]);
			double fTemp344 = (fConst35 * fRec607[1]);
			fRec609[0] = (fTemp342 + (fTemp343 + (fRec609[1] + fTemp344)));
			fRec607[0] = fRec609[0];
			double fRec608 = ((fTemp344 + fTemp343) + fTemp342);
			fRec606[0] = (fRec607[0] + fRec606[1]);
			fRec604[0] = fRec606[0];
			double fRec605 = fRec608;
			fRec603[0] = (fTemp341 + (fRec605 + fRec603[1]));
			fRec601[0] = fRec603[0];
			double fRec602 = (fRec605 + fTemp341);
			fRec600[0] = (fRec602 - (((fTemp2 * fRec600[2]) + (2.0 * (fTemp3 * fRec600[1]))) / fTemp4));
			double fTemp345 = (((fTemp1 * (fRec600[2] + (fRec600[0] + (2.0 * fRec600[1])))) / fTemp5) + (0.93701139950000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec600[1]) + ((fRec600[0] + fRec600[2]) / fTemp4))))));
			double fTemp346 = (3.3679172799999999 * fTemp345);
			double fTemp347 = (fConst37 * double(input6[i]));
			double fTemp348 = (fConst38 * fRec611[1]);
			double fTemp349 = (fConst39 * fRec614[1]);
			fRec616[0] = (fTemp347 + (fTemp348 + (fRec616[1] + fTemp349)));
			fRec614[0] = fRec616[0];
			double fRec615 = ((fTemp349 + fTemp348) + fTemp347);
			fRec613[0] = (fRec614[0] + fRec613[1]);
			fRec611[0] = fRec613[0];
			double fRec612 = fRec615;
			fRec610[0] = (fRec612 - (((fTemp2 * fRec610[2]) + (2.0 * (fTemp3 * fRec610[1]))) / fTemp4));
			double fTemp350 = (((fTemp1 * (fRec610[2] + (fRec610[0] + (2.0 * fRec610[1])))) / fTemp5) + (1.0700688140000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec610[1]) + ((fRec610[0] + fRec610[2]) / fTemp4))))));
			double fTemp351 = (3.4381782689999998 * fTemp350);
			double fTemp352 = (fConst31 * fRec618[1]);
			double fTemp353 = (fConst33 * double(input11[i]));
			double fTemp354 = (fConst34 * fRec621[1]);
			double fTemp355 = (fConst35 * fRec624[1]);
			fRec626[0] = (fTemp353 + (fTemp354 + (fRec626[1] + fTemp355)));
			fRec624[0] = fRec626[0];
			double fRec625 = ((fTemp355 + fTemp354) + fTemp353);
			fRec623[0] = (fRec624[0] + fRec623[1]);
			fRec621[0] = fRec623[0];
			double fRec622 = fRec625;
			fRec620[0] = (fTemp352 + (fRec622 + fRec620[1]));
			fRec618[0] = fRec620[0];
			double fRec619 = (fRec622 + fTemp352);
			fRec617[0] = (fRec619 - (((fTemp2 * fRec617[2]) + (2.0 * (fTemp3 * fRec617[1]))) / fTemp4));
			double fTemp356 = (((fTemp1 * (fRec617[2] + (fRec617[0] + (2.0 * fRec617[1])))) / fTemp5) + (0.93701139950000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec617[1]) + ((fRec617[0] + fRec617[2]) / fTemp4))))));
			double fTemp357 = (2.4397211940000001 * fTemp356);
			double fTemp358 = (fConst24 * fRec628[1]);
			double fTemp359 = (fConst25 * fRec631[1]);
			double fTemp360 = (fConst27 * double(input18[i]));
			double fTemp361 = (fConst28 * fRec634[1]);
			double fTemp362 = (fConst29 * fRec637[1]);
			fRec639[0] = (fTemp360 + (fTemp361 + (fRec639[1] + fTemp362)));
			fRec637[0] = fRec639[0];
			double fRec638 = ((fTemp362 + fTemp361) + fTemp360);
			fRec636[0] = (fRec637[0] + fRec636[1]);
			fRec634[0] = fRec636[0];
			double fRec635 = fRec638;
			fRec633[0] = (fTemp358 + (fTemp359 + (fRec635 + fRec633[1])));
			fRec631[0] = fRec633[0];
			double fRec632 = (fTemp358 + (fRec635 + fTemp359));
			fRec630[0] = (fRec631[0] + fRec630[1]);
			fRec628[0] = fRec630[0];
			double fRec629 = fRec632;
			fRec627[0] = (fRec629 - (((fTemp2 * fRec627[2]) + (2.0 * (fTemp3 * fRec627[1]))) / fTemp4));
			double fTemp363 = (((fTemp1 * (fRec627[2] + (fRec627[0] + (2.0 * fRec627[1])))) / fTemp5) + (0.77210283830000004 * (fRec3[0] * (0.0 - ((fTemp6 * fRec627[1]) + ((fRec627[0] + fRec627[2]) / fTemp4))))));
			double fTemp364 = (3.2674158969999998 * fTemp363);
			double fTemp365 = (fConst15 * fRec641[1]);
			double fTemp366 = (fConst17 * fRec644[1]);
			double fTemp367 = (fConst18 * fRec647[1]);
			double fTemp368 = (fConst20 * double(input27[i]));
			double fTemp369 = (fConst21 * fRec650[1]);
			double fTemp370 = (fConst22 * fRec653[1]);
			fRec655[0] = (fTemp368 + (fTemp369 + (fRec655[1] + fTemp370)));
			fRec653[0] = fRec655[0];
			double fRec654 = ((fTemp370 + fTemp369) + fTemp368);
			fRec652[0] = (fRec653[0] + fRec652[1]);
			fRec650[0] = fRec652[0];
			double fRec651 = fRec654;
			fRec649[0] = (fTemp366 + (fTemp367 + (fRec651 + fRec649[1])));
			fRec647[0] = fRec649[0];
			double fRec648 = (fTemp366 + (fRec651 + fTemp367));
			fRec646[0] = (fRec647[0] + fRec646[1]);
			fRec644[0] = fRec646[0];
			double fRec645 = fRec648;
			fRec643[0] = (fTemp365 + (fRec645 + fRec643[1]));
			fRec641[0] = fRec643[0];
			double fRec642 = (fRec645 + fTemp365);
			fRec640[0] = (fRec642 - (((fTemp2 * fRec640[2]) + (2.0 * (fTemp3 * fRec640[1]))) / fTemp4));
			double fTemp371 = (((fTemp1 * (fRec640[2] + (fRec640[0] + (2.0 * fRec640[1])))) / fTemp5) + (0.58498742319999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec640[1]) + ((fRec640[0] + fRec640[2]) / fTemp4))))));
			double fTemp372 = (3.9178197880000001 * fTemp371);
			double fTemp373 = (fConst5 * fRec657[1]);
			double fTemp374 = (fConst6 * fRec660[1]);
			double fTemp375 = (fConst8 * fRec663[1]);
			double fTemp376 = (fConst9 * fRec666[1]);
			double fTemp377 = (fConst11 * double(input39[i]));
			double fTemp378 = (fConst12 * fRec669[1]);
			double fTemp379 = (fConst13 * fRec672[1]);
			fRec674[0] = (fTemp377 + (fTemp378 + (fRec674[1] + fTemp379)));
			fRec672[0] = fRec674[0];
			double fRec673 = ((fTemp379 + fTemp378) + fTemp377);
			fRec671[0] = (fRec672[0] + fRec671[1]);
			fRec669[0] = fRec671[0];
			double fRec670 = fRec673;
			fRec668[0] = (fTemp375 + (fTemp376 + (fRec670 + fRec668[1])));
			fRec666[0] = fRec668[0];
			double fRec667 = (fTemp375 + (fRec670 + fTemp376));
			fRec665[0] = (fRec666[0] + fRec665[1]);
			fRec663[0] = fRec665[0];
			double fRec664 = fRec667;
			fRec662[0] = (fTemp373 + (fTemp374 + (fRec664 + fRec662[1])));
			fRec660[0] = fRec662[0];
			double fRec661 = (fTemp373 + (fRec664 + fTemp374));
			fRec659[0] = (fRec660[0] + fRec659[1]);
			fRec657[0] = fRec659[0];
			double fRec658 = fRec661;
			fRec656[0] = (fRec658 - (((fTemp2 * fRec656[2]) + (2.0 * (fTemp3 * fRec656[1]))) / fTemp4));
			double fTemp380 = (((fTemp1 * (fRec656[2] + (fRec656[0] + (2.0 * fRec656[1])))) / fTemp5) + (0.38646969730000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec656[1]) + ((fRec656[0] + fRec656[2]) / fTemp4))))));
			double fTemp381 = (6.5457981600000004 * fTemp380);
			fRec675[0] = (double(input49[i]) - (((fTemp2 * fRec675[2]) + (2.0 * (fTemp3 * fRec675[1]))) / fTemp4));
			double fTemp382 = (((fTemp1 * (fRec675[2] + (fRec675[0] + (2.0 * fRec675[1])))) / fTemp5) + (0.18781050760000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec675[1]) + ((fRec675[0] + fRec675[2]) / fTemp4))))));
			double fTemp383 = (6.8569768079999998 * fTemp382);
			fVec0[(IOTA & 127)] = ((fTemp8 + (fTemp10 + (fTemp12 + (fTemp14 + (fTemp16 + (fTemp18 + ((fTemp27 + (fTemp36 + (fTemp45 + (fTemp54 + (fTemp63 + (fTemp72 + (fTemp81 + (((2.3575297229999999 * fTemp88) + (fTemp96 + (fTemp104 + (fTemp112 + ((fTemp119 + (fTemp126 + ((fTemp132 + (fTemp138 + ((fTemp143 + (fTemp148 + (fTemp153 + ((fTemp157 + (fTemp161 + (fTemp163 + fTemp167))) + fTemp172)))) + fTemp178))) + fTemp185))) + fTemp193))))) + fTemp201)))))))) + fTemp203))))))) - (fTemp205 + (fTemp207 + (fTemp209 + (fTemp211 + (fTemp213 + (fTemp215 + (fTemp217 + ((fTemp226 + (fTemp235 + (fTemp244 + (fTemp253 + ((fTemp261 + (fTemp269 + (fTemp277 + (fTemp285 + (fTemp293 + ((fTemp300 + (fTemp307 + (fTemp314 + (fTemp321 + (fTemp328 + ((fTemp334 + (fTemp340 + (fTemp346 + (fTemp351 + fTemp357)))) + fTemp364)))))) + fTemp372)))))) + fTemp381))))) + fTemp383)))))))));
			output0[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec0[((IOTA - iConst43) & 127)])));
			double fTemp384 = (8.4395894219999992 * fTemp204);
			double fTemp385 = (5.9211169330000004 * fTemp206);
			double fTemp386 = (0.54110604110000005 * fTemp11);
			double fTemp387 = (5.6172143490000002 * fTemp13);
			double fTemp388 = (0.29897007790000002 * fTemp15);
			double fTemp389 = (0.1791621716 * fTemp17);
			double fTemp390 = (2.2594032999999998 * fTemp202);
			double fTemp391 = (0.51564971069999999 * fTemp210);
			double fTemp392 = (0.3595666092 * fTemp212);
			double fTemp393 = (5.4515879380000003 * fTemp216);
			double fTemp394 = (10.612866970000001 * fTemp382);
			double fTemp395 = (7.5748722319999997 * fTemp225);
			double fTemp396 = (6.0453180050000004 * fTemp234);
			double fTemp397 = (1.3476110619999999 * fTemp26);
			double fTemp398 = (5.7434544179999998 * fTemp35);
			double fTemp399 = (1.3713416199999999 * fTemp53);
			double fTemp400 = (0.87780960370000005 * fTemp62);
			double fTemp401 = (3.99960263 * fTemp80);
			double fTemp402 = (7.5097299780000002 * fTemp200);
			double fTemp403 = (8.5289061880000006 * fTemp260);
			double fTemp404 = (7.1955406130000004 * fTemp268);
			double fTemp405 = (2.814325486 * fTemp88);
			double fTemp406 = (1.7471486140000001 * fTemp95);
			double fTemp407 = (1.070778335 * fTemp103);
			double fTemp408 = (6.4047795269999996 * fTemp192);
			double fTemp409 = (8.9014818229999992 * fTemp299);
			double fTemp410 = (4.6364495459999997 * fTemp306);
			double fTemp411 = (3.8729810929999999 * fTemp118);
			double fTemp412 = (0.91407428889999998 * fTemp125);
			double fTemp413 = (7.9145823960000001 * fTemp184);
			double fTemp414 = (8.8364827219999995 * fTemp333);
			double fTemp415 = (3.4309343609999998 * fTemp131);
			double fTemp416 = (3.2183772849999999 * fTemp177);
			double fTemp417 = (8.5416983119999994 * fTemp142);
			double fTemp418 = (2.0521014599999998 * fTemp147);
			double fTemp419 = (8.8324839009999998 * fTemp156);
			double fTemp420 = (7.3029041589999997 * fTemp162);
			double fTemp421 = (0.91657790859999999 * fTemp166);
			double fTemp422 = (1.538114891 * fTemp171);
			double fTemp423 = (2.729758436 * fTemp7);
			double fTemp424 = (4.161037887 * fTemp9);
			double fTemp425 = (1.035370218 * fTemp208);
			double fTemp426 = (3.20495777 * fTemp214);
			double fTemp427 = (0.32454824230000001 * fTemp243);
			double fTemp428 = (6.3031492020000002 * fTemp252);
			double fTemp429 = (2.8822869550000001 * fTemp44);
			double fTemp430 = (3.266616527 * fTemp380);
			double fTemp431 = (7.1638311100000003 * fTemp71);
			double fTemp432 = (4.3357249260000001 * fTemp276);
			double fTemp433 = (5.6722848780000001 * fTemp284);
			double fTemp434 = (1.992482723 * fTemp292);
			double fTemp435 = (3.0006363380000001 * fTemp371);
			double fTemp436 = (0.26956347219999999 * fTemp111);
			double fTemp437 = (5.0487827259999998 * fTemp313);
			double fTemp438 = (4.9187251459999999 * fTemp320);
			double fTemp439 = (0.31310593190000002 * fTemp327);
			double fTemp440 = (2.6534281690000001 * fTemp363);
			double fTemp441 = (6.1462573899999997 * fTemp339);
			double fTemp442 = (1.1491923799999999 * fTemp345);
			double fTemp443 = (0.93425236290000002 * fTemp356);
			double fTemp444 = (0.41505633199999997 * fTemp137);
			double fTemp445 = (5.3447273319999997 * fTemp350);
			double fTemp446 = (0.70598839489999998 * fTemp160);
			double fTemp447 = (0.0568591367 * fTemp152);
			fVec1[(IOTA & 127)] = ((fTemp384 + (fTemp385 + (fTemp386 + (fTemp387 + (fTemp388 + (fTemp389 + (fTemp390 + (fTemp391 + (fTemp392 + (fTemp393 + (fTemp394 + (fTemp395 + (fTemp396 + (fTemp397 + (fTemp398 + (fTemp399 + (fTemp400 + (fTemp401 + (fTemp402 + (fTemp403 + (fTemp404 + (fTemp405 + (fTemp406 + (fTemp407 + (fTemp408 + (fTemp409 + (fTemp410 + (fTemp411 + (fTemp412 + (fTemp413 + (fTemp414 + (fTemp415 + (fTemp416 + (fTemp417 + (fTemp418 + ((fTemp419 + (fTemp420 + fTemp421)) + fTemp422)))))))))))))))))))))))))))))))))))) - (fTemp423 + (fTemp424 + (fTemp425 + (fTemp426 + (fTemp427 + (fTemp428 + (fTemp429 + (fTemp430 + (fTemp431 + (fTemp432 + (fTemp433 + (fTemp434 + (fTemp435 + (fTemp436 + (fTemp437 + (fTemp438 + (fTemp439 + (fTemp440 + (fTemp441 + (fTemp442 + (fTemp443 + (fTemp444 + (fTemp445 + (fTemp446 + fTemp447)))))))))))))))))))))))));
			output1[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec1[((IOTA - iConst44) & 127)])));
			double fTemp448 = (0.2203770981 * fTemp206);
			double fTemp449 = (0.1163826604 * fTemp7);
			double fTemp450 = (3.9767373880000001 * fTemp13);
			double fTemp451 = (0.1784932629 * fTemp15);
			double fTemp452 = (1.676016884 * fTemp212);
			double fTemp453 = (3.1760346639999999 * fTemp214);
			double fTemp454 = (2.4219971619999998 * fTemp234);
			double fTemp455 = (0.45219406210000002 * fTemp26);
			double fTemp456 = (4.9043245830000002 * fTemp35);
			double fTemp457 = (1.859430653 * fTemp44);
			double fTemp458 = (4.891442241 * fTemp380);
			double fTemp459 = (7.7379759650000004 * fTemp71);
			double fTemp460 = (2.7578853570000001 * fTemp260);
			double fTemp461 = (1.6989723919999999 * fTemp268);
			double fTemp462 = (1.959338813 * fTemp88);
			double fTemp463 = (5.0659738860000001 * fTemp95);
			double fTemp464 = (3.0124193520000002 * fTemp292);
			double fTemp465 = (3.4960551249999998 * fTemp371);
			double fTemp466 = (4.2187972970000001 * fTemp299);
			double fTemp467 = (4.6512357590000004 * fTemp306);
			double fTemp468 = (1.3828027540000001 * fTemp118);
			double fTemp469 = (1.273132291 * fTemp327);
			double fTemp470 = (7.2002982309999997 * fTemp333);
			double fTemp471 = (4.6574754370000004 * fTemp131);
			double fTemp472 = (8.5489581189999999 * fTemp142);
			double fTemp473 = (8.9305626300000007 * fTemp156);
			double fTemp474 = (5.1381098659999997 * fTemp162);
			double fTemp475 = (0.74659142710000004 * fTemp160);
			double fTemp476 = (fTemp474 + fTemp475);
			double fTemp477 = (2.4612888860000002 * fTemp147);
			double fTemp478 = (1.8925891990000001 * fTemp356);
			double fTemp479 = (3.0426798979999998 * fTemp363);
			double fTemp480 = (3.5285475019999999 * fTemp204);
			double fTemp481 = (4.7797723889999997 * fTemp9);
			double fTemp482 = (0.061137593400000002 * fTemp11);
			double fTemp483 = (5.1951910830000001 * fTemp208);
			double fTemp484 = (0.052882122400000002 * fTemp17);
			double fTemp485 = (3.3627803979999999 * fTemp202);
			double fTemp486 = (0.57055175540000003 * fTemp210);
			double fTemp487 = (8.3670239419999994 * fTemp216);
			double fTemp488 = (13.22492334 * fTemp382);
			double fTemp489 = (0.1024954238 * fTemp225);
			double fTemp490 = (3.5691076559999999 * fTemp243);
			double fTemp491 = (4.1120035110000002 * fTemp252);
			double fTemp492 = (1.785931242 * fTemp53);
			double fTemp493 = (1.040949366 * fTemp62);
			double fTemp494 = (7.3980432179999998 * fTemp80);
			double fTemp495 = (10.62038997 * fTemp200);
			double fTemp496 = (1.9490334739999999 * fTemp276);
			double fTemp497 = (4.6082651630000004 * fTemp284);
			double fTemp498 = (1.038564697 * fTemp103);
			double fTemp499 = (2.5351135070000002 * fTemp111);
			double fTemp500 = (10.35278666 * fTemp192);
			double fTemp501 = (3.0106514190000002 * fTemp313);
			double fTemp502 = (5.10879321 * fTemp320);
			double fTemp503 = (3.4277050199999999 * fTemp125);
			double fTemp504 = (11.662576489999999 * fTemp184);
			double fTemp505 = (5.7432743740000003 * fTemp339);
			double fTemp506 = (3.6048257719999999 * fTemp345);
			double fTemp507 = (1.3126674540000001 * fTemp137);
			double fTemp508 = (6.7436779160000002 * fTemp177);
			double fTemp509 = (3.7909209850000001 * fTemp350);
			double fTemp510 = (0.1927811016 * fTemp152);
			double fTemp511 = (2.105671531 * fTemp166);
			double fTemp512 = (4.1644046750000001 * fTemp171);
			fVec2[(IOTA & 127)] = ((fTemp448 + (fTemp449 + (fTemp450 + (fTemp451 + (fTemp452 + (fTemp453 + (fTemp454 + (fTemp455 + (fTemp456 + (fTemp457 + (fTemp458 + (fTemp459 + (fTemp460 + (fTemp461 + (fTemp462 + (fTemp463 + (fTemp464 + (fTemp465 + (fTemp466 + (fTemp467 + (fTemp468 + (fTemp469 + ((fTemp470 + (fTemp471 + ((fTemp472 + ((fTemp473 + fTemp476) + fTemp477)) + fTemp478))) + fTemp479))))))))))))))))))))))) - (fTemp480 + (fTemp481 + (fTemp482 + (fTemp483 + (fTemp484 + (fTemp485 + (fTemp486 + (fTemp487 + (fTemp488 + (fTemp489 + (fTemp490 + (fTemp491 + (fTemp492 + (fTemp493 + (fTemp494 + (fTemp495 + (fTemp496 + (fTemp497 + (fTemp498 + (fTemp499 + (fTemp500 + (fTemp501 + (fTemp502 + (fTemp503 + (fTemp504 + (fTemp505 + (fTemp506 + (fTemp507 + (fTemp508 + (fTemp509 + (fTemp510 + (fTemp511 + fTemp512)))))))))))))))))))))))))))))))));
			output2[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec2[((IOTA - iConst44) & 127)])));
			double fTemp513 = (4.2055520680000003 * fTemp7);
			double fTemp514 = (7.9044882769999996 * fTemp9);
			double fTemp515 = (0.30055312360000003 * fTemp11);
			double fTemp516 = (2.6953747859999999 * fTemp13);
			double fTemp517 = (0.071751242800000004 * fTemp15);
			double fTemp518 = (7.9775668270000004 * fTemp212);
			double fTemp519 = (0.29208783989999998 * fTemp214);
			double fTemp520 = (5.9497140789999996 * fTemp216);
			double fTemp521 = (13.46258967 * fTemp382);
			double fTemp522 = (5.5207582469999998 * fTemp243);
			double fTemp523 = (2.3441937350000002 * fTemp252);
			double fTemp524 = (1.311349289 * fTemp26);
			double fTemp525 = (4.6967721080000002 * fTemp35);
			double fTemp526 = (6.6971546220000002 * fTemp380);
			double fTemp527 = (1.442771942 * fTemp80);
			double fTemp528 = (7.5789951630000001 * fTemp200);
			double fTemp529 = (1.0494268739999999 * fTemp276);
			double fTemp530 = (2.3261295560000002 * fTemp88);
			double fTemp531 = (1.7891220459999999 * fTemp95);
			double fTemp532 = (5.6958280099999996 * fTemp292);
			double fTemp533 = (5.1472328520000001 * fTemp371);
			double fTemp534 = (1.518140255 * fTemp192);
			double fTemp535 = (3.8622761529999998 * fTemp118);
			double fTemp536 = (2.9143359649999998 * fTemp327);
			double fTemp537 = (1.580656933 * fTemp142);
			double fTemp538 = (6.7966180090000003 * fTemp156);
			double fTemp539 = (7.2781719110000003 * fTemp162);
			double fTemp540 = (1.1508721930000001 * fTemp147);
			double fTemp541 = (3.373745574 * fTemp356);
			double fTemp542 = (5.0586923989999999 * fTemp363);
			double fTemp543 = (1.4970003080000001 * fTemp204);
			double fTemp544 = (5.4478933300000003 * fTemp206);
			double fTemp545 = (0.97313179620000001 * fTemp208);
			double fTemp546 = (0.29481214579999998 * fTemp17);
			double fTemp547 = (5.6067593760000003 * fTemp202);
			double fTemp548 = (0.87532884789999998 * fTemp210);
			double fTemp549 = (7.4789848259999996 * fTemp225);
			double fTemp550 = (7.0913049050000003 * fTemp234);
			double fTemp551 = (2.817590161 * fTemp44);
			double fTemp552 = (3.3484267139999999 * fTemp53);
			double fTemp553 = (1.326083779 * fTemp62);
			double fTemp554 = (2.6610319009999999 * fTemp71);
			double fTemp555 = (10.54843412 * fTemp260);
			double fTemp556 = (3.4436644420000002 * fTemp268);
			double fTemp557 = (1.5396933989999999 * fTemp284);
			double fTemp558 = (1.5404490609999999 * fTemp103);
			double fTemp559 = (5.4313215719999999 * fTemp111);
			double fTemp560 = (7.4961685390000001 * fTemp299);
			double fTemp561 = (2.5749304300000002 * fTemp306);
			double fTemp562 = (2.2715035079999999 * fTemp313);
			double fTemp563 = (4.1742355709999996 * fTemp320);
			double fTemp564 = (3.9562190039999998 * fTemp125);
			double fTemp565 = (1.068383144 * fTemp184);
			double fTemp566 = (3.9417172219999999 * fTemp333);
			double fTemp567 = (0.20932173400000001 * fTemp131);
			double fTemp568 = (5.4257584400000001 * fTemp339);
			double fTemp569 = (1.2096455100000001 * fTemp345);
			double fTemp570 = (3.4384828330000001 * fTemp137);
			double fTemp571 = (8.5456471809999996 * fTemp177);
			double fTemp572 = (5.4183019080000001 * fTemp350);
			double fTemp573 = (1.6995944789999999 * fTemp152);
			double fTemp574 = (0.75701016229999996 * fTemp160);
			double fTemp575 = (5.6879492620000001 * fTemp166);
			double fTemp576 = (8.5546384680000003 * fTemp171);
			fVec3[(IOTA & 127)] = ((fTemp513 + (fTemp514 + (fTemp515 + (fTemp516 + (fTemp517 + (fTemp518 + (fTemp519 + (fTemp520 + (fTemp521 + (fTemp522 + (fTemp523 + (fTemp524 + (fTemp525 + (fTemp526 + (fTemp527 + (fTemp528 + (fTemp529 + (fTemp530 + (fTemp531 + (fTemp532 + (fTemp533 + (fTemp534 + (fTemp535 + (fTemp536 + (((fTemp537 + ((fTemp538 + fTemp539) + fTemp540)) + fTemp541) + fTemp542))))))))))))))))))))))))) - (fTemp543 + (fTemp544 + (fTemp545 + (fTemp546 + (fTemp547 + (fTemp548 + (fTemp549 + (fTemp550 + (fTemp551 + (fTemp552 + (fTemp553 + (fTemp554 + (fTemp555 + (fTemp556 + (fTemp557 + (fTemp558 + (fTemp559 + (fTemp560 + (fTemp561 + (fTemp562 + (fTemp563 + (fTemp564 + (fTemp565 + (fTemp566 + (fTemp567 + (fTemp568 + (fTemp569 + (fTemp570 + (fTemp571 + (fTemp572 + (fTemp573 + ((fTemp574 + fTemp575) + fTemp576)))))))))))))))))))))))))))))))));
			output3[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec3[((IOTA - iConst45) & 127)])));
			double fTemp577 = (6.8569768079999998 * fTemp204);
			double fTemp578 = (0.020180471500000002 * fTemp11);
			double fTemp579 = (0.26697909409999998 * fTemp15);
			double fTemp580 = (0.43071832789999998 * fTemp210);
			double fTemp581 = (3.5468706820000002 * fTemp234);
			double fTemp582 = (6.5457981600000004 * fTemp252);
			double fTemp583 = (2.399475518 * fTemp35);
			double fTemp584 = (6.9309434830000001 * fTemp80);
			double fTemp585 = (5.3847432929999997 * fTemp260);
			double fTemp586 = (3.9178197880000001 * fTemp276);
			double fTemp587 = (0.89280991779999996 * fTemp88);
			double fTemp588 = (9.2773047549999994 * fTemp192);
			double fTemp589 = (4.2143797479999998 * fTemp327);
			double fTemp590 = (4.8791292029999997 * fTemp156);
			double fTemp591 = (fTemp163 + fTemp161);
			double fTemp592 = (1.778687012 * fTemp147);
			double fTemp593 = (5.1071324929999999 * fTemp356);
			double fTemp594 = (2.306399592 * fTemp7);
			double fTemp595 = (0.35205137149999999 * fTemp17);
			double fTemp596 = (2.2195680229999999 * fTemp214);
			double fTemp597 = (11.888618689999999 * fTemp382);
			double fTemp598 = (4.92779554 * fTemp53);
			double fTemp599 = (0.57046219320000002 * fTemp380);
			double fTemp600 = (2.3575297239999999 * fTemp103);
			double fTemp601 = (1.103383668 * fTemp371);
			double fTemp602 = (5.6362862649999999 * fTemp306);
			double fTemp603 = (2.4142196359999999 * fTemp320);
			double fTemp604 = (0.85967434779999996 * fTemp125);
			double fTemp605 = (9.7683374569999994 * fTemp333);
			double fTemp606 = (2.4397211940000001 * fTemp339);
			double fTemp607 = (0.3121038377 * fTemp177);
			double fTemp608 = (2.062082545 * fTemp152);
			double fTemp609 = (7.8623176140000002 * fTemp166);
			fVec4[(IOTA & 127)] = ((fTemp577 + (fTemp207 + (fTemp10 + (fTemp578 + (fTemp579 + (fTemp580 + (fTemp217 + (fTemp226 + (fTemp581 + (fTemp582 + (fTemp583 + (fTemp45 + (fTemp72 + (fTemp584 + (fTemp585 + (fTemp586 + (fTemp285 + (fTemp587 + (fTemp96 + (fTemp293 + (fTemp112 + (fTemp588 + (fTemp314 + (fTemp119 + (fTemp589 + (fTemp364 + (fTemp185 + (((fTemp590 + fTemp591) + fTemp592) + fTemp593)))))))))))))))))))))))))))) - (fTemp594 + (fTemp14 + (fTemp209 + (fTemp595 + (fTemp203 + (fTemp213 + (fTemp596 + (fTemp597 + (fTemp244 + (fTemp27 + (fTemp598 + (fTemp63 + (fTemp599 + (fTemp201 + (fTemp269 + (fTemp600 + (fTemp601 + (fTemp300 + (fTemp602 + (fTemp603 + (fTemp604 + (fTemp605 + (fTemp132 + (fTemp606 + (fTemp346 + (fTemp138 + (fTemp607 + (fTemp143 + (fTemp351 + (fTemp608 + (fTemp172 + fTemp609))))))))))))))))))))))))))))))));
			output4[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec4[((IOTA - iConst43) & 127)])));
			double fTemp610 = (0.1791621716 * fTemp15);
			double fTemp611 = (0.54110604110000005 * fTemp210);
			double fTemp612 = (2.729758436 * fTemp214);
			double fTemp613 = (8.4395894219999992 * fTemp382);
			double fTemp614 = (3.99960263 * fTemp234);
			double fTemp615 = (3.266616527 * fTemp252);
			double fTemp616 = (6.4047795269999996 * fTemp260);
			double fTemp617 = (3.0006363380000001 * fTemp276);
			double fTemp618 = (1.070778335 * fTemp88);
			double fTemp619 = (4.9187251459999999 * fTemp327);
			double fTemp620 = (4.6364495459999997 * fTemp125);
			double fTemp621 = (6.1462573899999997 * fTemp356);
			double fTemp622 = (0.91657790859999999 * fTemp156);
			double fTemp623 = (8.8364827219999995 * fTemp177);
			double fTemp624 = (1.3713416199999999 * fTemp35);
			double fTemp625 = (10.612866970000001 * fTemp204);
			double fTemp626 = (3.20495777 * fTemp7);
			double fTemp627 = (0.51564971069999999 * fTemp11);
			double fTemp628 = (0.29897007790000002 * fTemp17);
			double fTemp629 = (5.7434544179999998 * fTemp53);
			double fTemp630 = (6.3031492020000002 * fTemp380);
			double fTemp631 = (6.0453180050000004 * fTemp80);
			double fTemp632 = (2.814325486 * fTemp103);
			double fTemp633 = (4.3357249260000001 * fTemp371);
			double fTemp634 = (8.5289061880000006 * fTemp192);
			double fTemp635 = (0.91407428889999998 * fTemp306);
			double fTemp636 = (3.2183772849999999 * fTemp333);
			double fTemp637 = (0.93425236290000002 * fTemp339);
			double fTemp638 = (0.0568591367 * fTemp147);
			double fTemp639 = (2.0521014599999998 * fTemp152);
			double fTemp640 = (8.8324839009999998 * fTemp166);
			double fTemp641 = (0.31310593190000002 * fTemp320);
			fVec5[(IOTA & 127)] = ((fTemp610 + (fTemp611 + (fTemp392 + (fTemp612 + (fTemp613 + (fTemp614 + (fTemp615 + ((fTemp616 + (fTemp404 + (fTemp617 + (fTemp433 + (fTemp618 + (fTemp406 + (fTemp434 + (fTemp409 + (fTemp437 + (fTemp411 + (fTemp619 + (fTemp440 + (fTemp620 + (fTemp413 + (fTemp621 + (fTemp444 + ((fTemp420 + fTemp622) + fTemp623))))))))))))))))) + fTemp624)))))))) - (fTemp625 + (fTemp385 + (fTemp626 + (fTemp424 + (fTemp627 + (fTemp387 + (fTemp425 + (fTemp628 + (fTemp390 + (fTemp393 + (fTemp395 + (fTemp427 + (fTemp397 + (fTemp429 + (fTemp629 + (fTemp400 + (fTemp630 + (fTemp431 + (fTemp631 + (fTemp402 + (fTemp632 + (fTemp633 + (fTemp436 + (fTemp634 + (fTemp635 + ((fTemp636 + (fTemp415 + (fTemp637 + (fTemp442 + (fTemp417 + (fTemp638 + (fTemp445 + (fTemp639 + (fTemp422 + (fTemp446 + fTemp640)))))))))) + fTemp641)))))))))))))))))))))))))));
			output5[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec5[((IOTA - iConst44) & 127)])));
			double fTemp642 = (13.22492334 * fTemp204);
			double fTemp643 = (3.1760346639999999 * fTemp7);
			double fTemp644 = (0.57055175540000003 * fTemp11);
			double fTemp645 = (3.4277050199999999 * fTemp306);
			double fTemp646 = (1.273132291 * fTemp320);
			double fTemp647 = (5.10879321 * fTemp327);
			double fTemp648 = (4.6512357590000004 * fTemp125);
			double fTemp649 = (6.7436779160000002 * fTemp333);
			double fTemp650 = (1.8925891990000001 * fTemp339);
			double fTemp651 = (5.7432743740000003 * fTemp356);
			double fTemp652 = (7.2002982309999997 * fTemp177);
			double fTemp653 = (0.052882122400000002 * fTemp15);
			double fTemp654 = (0.1784932629 * fTemp17);
			double fTemp655 = (0.061137593400000002 * fTemp210);
			double fTemp656 = (0.1163826604 * fTemp214);
			double fTemp657 = (3.5285475019999999 * fTemp382);
			double fTemp658 = (7.3980432179999998 * fTemp234);
			double fTemp659 = (4.891442241 * fTemp252);
			double fTemp660 = (1.785931242 * fTemp35);
			double fTemp661 = (4.9043245830000002 * fTemp53);
			double fTemp662 = (4.1120035110000002 * fTemp380);
			double fTemp663 = (2.4219971619999998 * fTemp80);
			double fTemp664 = (10.35278666 * fTemp260);
			double fTemp665 = (3.4960551249999998 * fTemp276);
			double fTemp666 = (1.038564697 * fTemp88);
			double fTemp667 = (1.959338813 * fTemp103);
			double fTemp668 = (1.9490334739999999 * fTemp371);
			double fTemp669 = (2.7578853570000001 * fTemp192);
			double fTemp670 = (0.1927811016 * fTemp147);
			double fTemp671 = (8.9305626300000007 * fTemp166);
			double fTemp672 = (2.105671531 * fTemp156);
			double fTemp673 = (2.4612888860000002 * fTemp152);
			fVec6[(IOTA & 127)] = ((fTemp642 + (fTemp643 + (fTemp644 + (fTemp485 + (fTemp452 + (fTemp487 + (fTemp489 + (fTemp457 + (fTemp493 + (fTemp459 + (fTemp495 + (fTemp461 + (fTemp497 + (fTemp463 + (fTemp466 + (fTemp645 + (fTemp501 + (fTemp646 + (fTemp468 + (fTemp647 + (fTemp648 + (fTemp649 + (fTemp650 + (fTemp651 + (fTemp507 + (fTemp652 + (fTemp512 + fTemp476))))))))))))))))))))))))))) - (fTemp448 + (fTemp481 + (fTemp450 + (fTemp653 + (fTemp483 + (fTemp654 + (fTemp655 + (fTemp656 + (fTemp657 + (fTemp658 + (fTemp490 + (fTemp659 + (fTemp455 + (fTemp660 + (fTemp661 + (fTemp662 + (fTemp663 + (fTemp664 + (fTemp665 + (fTemp666 + (fTemp667 + (fTemp464 + (fTemp668 + (fTemp499 + (fTemp669 + (fTemp479 + (fTemp504 + (fTemp471 + (fTemp506 + (fTemp472 + (fTemp670 + (fTemp509 + ((fTemp671 + fTemp672) + fTemp673))))))))))))))))))))))))))))))))));
			output6[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec6[((IOTA - iConst44) & 127)])));
			double fTemp674 = (0.29208783989999998 * fTemp7);
			double fTemp675 = (0.87532884789999998 * fTemp11);
			double fTemp676 = (0.30055312360000003 * fTemp210);
			double fTemp677 = (1.442771942 * fTemp234);
			double fTemp678 = (2.3441937350000002 * fTemp380);
			double fTemp679 = (7.0913049050000003 * fTemp80);
			double fTemp680 = (1.518140255 * fTemp260);
			double fTemp681 = (1.0494268739999999 * fTemp371);
			double fTemp682 = (10.54843412 * fTemp192);
			double fTemp683 = (3.9562190039999998 * fTemp306);
			double fTemp684 = (2.9143359649999998 * fTemp320);
			double fTemp685 = (8.5456471809999996 * fTemp333);
			double fTemp686 = (3.373745574 * fTemp339);
			double fTemp687 = (5.4257584400000001 * fTemp356);
			double fTemp688 = (4.1742355709999996 * fTemp327);
			double fTemp689 = (13.46258967 * fTemp204);
			double fTemp690 = (0.29481214579999998 * fTemp15);
			double fTemp691 = (0.071751242800000004 * fTemp17);
			double fTemp692 = (4.2055520680000003 * fTemp214);
			double fTemp693 = (1.4970003080000001 * fTemp382);
			double fTemp694 = (6.6971546220000002 * fTemp252);
			double fTemp695 = (3.3484267139999999 * fTemp35);
			double fTemp696 = (4.6967721080000002 * fTemp53);
			double fTemp697 = (5.1472328520000001 * fTemp276);
			double fTemp698 = (1.5404490609999999 * fTemp88);
			double fTemp699 = (2.3261295560000002 * fTemp103);
			double fTemp700 = (2.5749304300000002 * fTemp125);
			double fTemp701 = (3.9417172219999999 * fTemp177);
			double fTemp702 = (1.6995944789999999 * fTemp147);
			double fTemp703 = (6.7966180090000003 * fTemp166);
			double fTemp704 = (5.6879492620000001 * fTemp156);
			double fTemp705 = (1.1508721930000001 * fTemp152);
			fVec7[(IOTA & 127)] = ((fTemp544 + (fTemp674 + (fTemp514 + (fTemp675 + (fTemp547 + (fTemp676 + (fTemp518 + (fTemp549 + (fTemp677 + (fTemp522 + (fTemp553 + (fTemp678 + (fTemp679 + (fTemp680 + (fTemp557 + (fTemp531 + (fTemp681 + (fTemp682 + (fTemp683 + (fTemp562 + (fTemp684 + (fTemp535 + ((fTemp685 + (fTemp567 + (fTemp686 + (fTemp687 + (fTemp570 + (fTemp576 + fTemp539)))))) + fTemp688))))))))))))))))))))))) - (fTemp689 + (fTemp516 + (fTemp690 + (fTemp545 + (fTemp691 + (fTemp692 + (fTemp520 + (fTemp693 + (fTemp694 + (fTemp524 + (fTemp695 + (fTemp551 + (fTemp696 + (fTemp554 + (fTemp528 + (fTemp556 + (fTemp697 + (fTemp698 + (fTemp699 + (fTemp532 + (fTemp559 + (fTemp560 + (fTemp542 + (fTemp700 + (fTemp565 + (fTemp569 + (fTemp701 + (fTemp537 + (fTemp702 + (fTemp572 + (((fTemp574 + fTemp703) + fTemp704) + fTemp705))))))))))))))))))))))))))))))));
			output7[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec7[((IOTA - iConst45) & 127)])));
			fVec8[(IOTA & 127)] = ((fTemp205 + (fTemp10 + (fTemp14 + (fTemp203 + (fTemp211 + (fTemp215 + (fTemp383 + (fTemp235 + (fTemp253 + (fTemp27 + (fTemp45 + (fTemp63 + (fTemp381 + (fTemp72 + (fTemp201 + (fTemp261 + (fTemp277 + (fTemp96 + (fTemp372 + (fTemp112 + (fTemp307 + (fTemp321 + (fTemp119 + (fTemp328 + (fTemp185 + (fTemp334 + (fTemp132 + (fTemp340 + (fTemp357 + (fTemp138 + (fTemp143 + (fTemp172 + fTemp591)))))))))))))))))))))))))))))))) - (fTemp207 + (fTemp8 + (fTemp12 + (fTemp16 + (fTemp209 + (fTemp18 + (fTemp213 + (fTemp217 + (fTemp226 + (fTemp244 + (fTemp36 + (fTemp54 + (fTemp81 + (fTemp269 + (fTemp285 + ((2.3575297239999999 * fTemp88) + (fTemp104 + (fTemp293 + (fTemp193 + (fTemp300 + (fTemp314 + (fTemp364 + (fTemp126 + (fTemp346 + (fTemp178 + (fTemp148 + (fTemp351 + (fTemp153 + (fTemp167 + fTemp157))))))))))))))))))))))))))))));
			output8[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec8[((IOTA - iConst43) & 127)])));
			fVec9[(IOTA & 127)] = ((fTemp385 + (fTemp423 + (fTemp387 + (fTemp390 + (fTemp392 + (fTemp426 + (fTemp393 + (fTemp395 + (fTemp428 + (fTemp397 + (fTemp400 + (fTemp430 + (fTemp402 + (fTemp404 + (fTemp432 + (fTemp406 + (fTemp435 + (fTemp409 + (fTemp438 + (fTemp411 + (fTemp439 + (fTemp413 + (fTemp415 + (fTemp441 + (fTemp443 + (fTemp417 + (fTemp447 + (fTemp420 + fTemp422)))))))))))))))))))))))))))) - (fTemp384 + (fTemp424 + (fTemp386 + (fTemp388 + (fTemp425 + (fTemp389 + (fTemp391 + (fTemp394 + (fTemp396 + (fTemp427 + (fTemp398 + (fTemp429 + (fTemp399 + (fTemp431 + (fTemp401 + (fTemp403 + (fTemp433 + (fTemp405 + (fTemp407 + (fTemp434 + (fTemp436 + (fTemp408 + (fTemp410 + (fTemp437 + (fTemp440 + (fTemp412 + (fTemp414 + (fTemp442 + (fTemp444 + (fTemp416 + (fTemp418 + (fTemp445 + (fTemp419 + (fTemp421 + fTemp446)))))))))))))))))))))))))))))))))));
			output9[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec9[((IOTA - iConst44) & 127)])));
			fVec10[(IOTA & 127)] = ((fTemp480 + (fTemp448 + (fTemp482 + (fTemp450 + (fTemp484 + (fTemp486 + (fTemp452 + (fTemp488 + (fTemp491 + (fTemp455 + (fTemp457 + (fTemp492 + (fTemp459 + (fTemp494 + (fTemp461 + (fTemp496 + (fTemp463 + (fTemp498 + (fTemp464 + (fTemp500 + (fTemp466 + (fTemp502 + (fTemp468 + (fTemp479 + (fTemp503 + (fTemp471 + (fTemp505 + (fTemp508 + (fTemp472 + (fTemp510 + (fTemp475 + (fTemp474 + fTemp511)))))))))))))))))))))))))))))))) - (fTemp449 + (fTemp481 + (fTemp451 + (fTemp483 + (fTemp485 + (fTemp453 + (fTemp487 + (fTemp489 + (fTemp454 + (fTemp490 + (fTemp456 + (fTemp493 + (fTemp458 + (fTemp495 + (fTemp460 + (fTemp497 + (fTemp462 + (fTemp465 + (fTemp499 + (fTemp467 + (fTemp501 + (fTemp469 + (fTemp504 + (fTemp470 + (fTemp506 + (fTemp478 + (fTemp507 + (fTemp477 + (fTemp509 + (fTemp473 + fTemp512)))))))))))))))))))))))))))))));
			output10[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec10[((IOTA - iConst44) & 127)])));
			fVec11[(IOTA & 127)] = ((fTemp543 + (fTemp514 + (fTemp516 + (fTemp546 + (fTemp548 + (fTemp518 + (fTemp520 + (fTemp550 + (fTemp522 + (fTemp524 + (fTemp552 + (fTemp528 + (fTemp555 + (fTemp531 + (fTemp558 + (fTemp532 + (fTemp561 + (fTemp563 + (fTemp535 + (fTemp542 + (fTemp564 + (fTemp566 + (fTemp568 + (fTemp571 + (fTemp537 + (fTemp573 + (fTemp539 + fTemp575))))))))))))))))))))))))))) - (fTemp544 + (fTemp513 + (fTemp515 + (fTemp517 + (fTemp545 + (fTemp547 + (fTemp519 + (fTemp521 + (fTemp549 + (fTemp523 + (fTemp525 + (fTemp551 + (fTemp553 + (fTemp526 + (fTemp554 + (fTemp527 + (fTemp556 + (fTemp529 + (fTemp557 + (fTemp530 + (fTemp533 + (fTemp559 + (fTemp534 + (fTemp560 + (fTemp562 + (fTemp536 + (fTemp565 + (fTemp567 + (fTemp569 + (fTemp541 + (fTemp570 + (fTemp540 + (fTemp572 + (fTemp576 + (fTemp574 + fTemp538))))))))))))))))))))))))))))))))))));
			output11[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec11[((IOTA - iConst45) & 127)])));
			fVec12[(IOTA & 127)] = ((fTemp207 + (fTemp594 + (fTemp10 + (fTemp595 + (fTemp596 + (fTemp217 + (fTemp597 + (fTemp226 + (fTemp45 + (fTemp598 + (fTemp599 + (fTemp72 + (fTemp285 + (fTemp96 + (fTemp600 + (fTemp293 + (fTemp601 + (fTemp112 + (fTemp602 + (fTemp314 + (fTemp603 + (fTemp119 + (fTemp364 + (fTemp604 + (fTemp185 + (fTemp605 + (fTemp606 + (fTemp607 + (fTemp608 + (fTemp161 + (fTemp163 + fTemp609))))))))))))))))))))))))))))))) - (fTemp577 + (fTemp578 + (fTemp14 + (fTemp579 + (fTemp209 + (fTemp203 + (fTemp580 + (fTemp213 + (fTemp581 + (fTemp244 + (fTemp582 + (fTemp27 + (fTemp583 + (fTemp63 + (fTemp584 + (fTemp201 + (fTemp585 + (fTemp269 + (fTemp586 + (fTemp587 + (fTemp588 + (fTemp300 + (fTemp589 + (fTemp132 + (fTemp346 + (fTemp593 + (fTemp138 + (fTemp143 + (fTemp592 + (fTemp351 + (fTemp172 + fTemp590))))))))))))))))))))))))))))))));
			output12[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec12[((IOTA - iConst43) & 127)])));
			fVec13[(IOTA & 127)] = ((fTemp625 + (fTemp626 + (fTemp627 + (fTemp628 + (fTemp392 + (fTemp629 + (fTemp630 + (fTemp631 + (fTemp404 + (fTemp433 + (fTemp406 + (fTemp632 + (fTemp434 + (fTemp633 + (fTemp634 + (fTemp409 + (fTemp635 + (fTemp437 + (fTemp641 + (fTemp411 + (fTemp440 + (fTemp413 + (fTemp636 + (fTemp637 + (fTemp444 + (fTemp638 + (fTemp639 + (fTemp420 + fTemp640)))))))))))))))))))))))))))) - (fTemp385 + (fTemp424 + (fTemp387 + (fTemp610 + (fTemp425 + (fTemp390 + (fTemp611 + (fTemp612 + (fTemp393 + (fTemp613 + (fTemp395 + (fTemp614 + (fTemp427 + (fTemp615 + (fTemp397 + (fTemp624 + (fTemp429 + (fTemp400 + (fTemp431 + (fTemp402 + (fTemp616 + (fTemp617 + (fTemp618 + (fTemp436 + (fTemp619 + (fTemp620 + (fTemp415 + (fTemp442 + (fTemp621 + (fTemp623 + (fTemp417 + (fTemp445 + (fTemp422 + (fTemp446 + fTemp622)))))))))))))))))))))))))))))))))));
			output13[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec13[((IOTA - iConst44) & 127)])));
			fVec14[(IOTA & 127)] = ((((((((((((((((((((fTemp495 + (fTemp664 + (fTemp461 + (fTemp665 + (fTemp497 + (fTemp666 + (fTemp463 + (fTemp667 + (fTemp668 + (fTemp669 + (fTemp466 + (fTemp501 + (fTemp468 + (fTemp507 + (fTemp670 + (fTemp673 + (fTemp512 + (fTemp672 + (fTemp475 + (fTemp474 + fTemp671)))))))))))))))))))) + fTemp663) + fTemp459) + fTemp662) + fTemp493) + fTemp661) + fTemp457) + fTemp660) + fTemp659) + fTemp658) + fTemp489) + fTemp657) + fTemp487) + fTemp656) + fTemp452) + fTemp655) + fTemp485) + fTemp654) + fTemp653) - (((((((((fTemp455 + (fTemp464 + (fTemp499 + (fTemp645 + (fTemp646 + (fTemp647 + (fTemp479 + (fTemp648 + (fTemp504 + (fTemp649 + (fTemp471 + (fTemp650 + (fTemp506 + (fTemp651 + (fTemp652 + (fTemp509 + fTemp472)))))))))))))))) + fTemp490) + fTemp483) + fTemp450) + fTemp644) + fTemp481) + fTemp643) + fTemp448) + fTemp642));
			output14[i] = FAUSTFLOAT((0.9619850187265917 * (fVec14[((IOTA - iConst44) & 127)] * fRec0[0])));
			fVec15[(IOTA & 127)] = ((((((((((((((((((((((((((((((((fTemp539 + fTemp703) + fTemp704) + fTemp576) + fTemp705) + fTemp702) + fTemp701) + fTemp570) + fTemp567) + fTemp700) + fTemp535) + fTemp562) + fTemp699) + fTemp531) + fTemp698) + fTemp557) + fTemp697) + fTemp553) + fTemp696) + fTemp695) + fTemp694) + fTemp522) + fTemp549) + fTemp693) + fTemp692) + fTemp518) + fTemp547) + fTemp691) + fTemp690) + fTemp514) + fTemp544) + fTemp689) - (((((((((((((((((((((((((((((((fTemp574 + fTemp572) + fTemp537) + fTemp687) + fTemp569) + fTemp686) + fTemp685) + fTemp565) + fTemp542) + fTemp688) + fTemp684) + fTemp683) + fTemp560) + fTemp682) + fTemp559) + fTemp681) + fTemp532) + fTemp556) + fTemp680) + fTemp528) + fTemp679) + fTemp554) + fTemp678) + fTemp551) + fTemp524) + fTemp677) + fTemp520) + fTemp676) + fTemp545) + fTemp516) + fTemp675) + fTemp674));
			output15[i] = FAUSTFLOAT((0.96142322097378285 * (fVec15[((IOTA - iConst45) & 127)] * fRec0[0])));
			double fTemp706 = (0.75129727530000001 * fTemp204);
			double fTemp707 = (4.6165465140000004 * fTemp206);
			double fTemp708 = (4.8419174040000001 * fTemp7);
			double fTemp709 = (4.0712036390000002 * fTemp11);
			double fTemp710 = (4.2428821330000002 * fTemp13);
			double fTemp711 = (0.24772585850000001 * fTemp15);
			double fTemp712 = (5.2973372599999999 * fTemp208);
			double fTemp713 = (0.77074563620000003 * fTemp17);
			double fTemp714 = (1.2880689219999999 * fTemp382);
			double fTemp715 = (0.77134026219999996 * fTemp225);
			double fTemp716 = (2.997798688 * fTemp234);
			double fTemp717 = (3.4040783769999998 * fTemp26);
			double fTemp718 = (2.5459661859999998 * fTemp44);
			double fTemp719 = (0.0098641100000000006 * fTemp380);
			double fTemp720 = (0.84800542680000002 * fTemp260);
			double fTemp721 = (1.28082246 * fTemp292);
			double fTemp722 = (0.034950011000000003 * fTemp371);
			double fTemp723 = (7.779972828 * fTemp363);
			double fTemp724 = (0.031497049899999997 * fTemp125);
			double fTemp725 = (3.376093429 * fTemp339);
			double fTemp726 = (6.3600805669999998 * fTemp356);
			double fTemp727 = (9.3569121890000009 * fTemp137);
			double fTemp728 = (0.0137563318 * fTemp177);
			double fTemp729 = (5.3136734179999996 * fTemp147);
			double fTemp730 = (1.0268632950000001 * fTemp350);
			double fTemp731 = (9.5108290209999993 * fTemp152);
			double fTemp732 = (4.0629427070000004 * fTemp156);
			double fTemp733 = (5.1598493559999996 * fTemp160);
			double fTemp734 = (6.7007492580000001 * fTemp162);
			double fTemp735 = (7.1422865010000001 * fTemp166);
			double fTemp736 = (6.0359550300000002 * fTemp171);
			double fTemp737 = (2.7996487970000001 * fTemp9);
			double fTemp738 = (6.9511394299999996 * fTemp202);
			double fTemp739 = (0.0309136146 * fTemp210);
			double fTemp740 = (4.9526301310000003 * fTemp212);
			double fTemp741 = (8.5029220389999995 * fTemp214);
			double fTemp742 = (0.017827306800000001 * fTemp216);
			double fTemp743 = (4.5559875559999998 * fTemp243);
			double fTemp744 = (4.4311452300000003 * fTemp252);
			double fTemp745 = (3.895475791 * fTemp35);
			double fTemp746 = (6.3096703810000001 * fTemp53);
			double fTemp747 = (5.4946778859999998 * fTemp62);
			double fTemp748 = (7.9003001529999999 * fTemp71);
			double fTemp749 = (5.2556838370000003 * fTemp80);
			double fTemp750 = (0.0056019811999999999 * fTemp200);
			double fTemp751 = (3.8248314470000002 * fTemp268);
			double fTemp752 = (9.9263573919999999 * fTemp276);
			double fTemp753 = (0.47878633869999998 * fTemp284);
			double fTemp754 = (4.5743107619999996 * fTemp88);
			double fTemp755 = (3.5482697999999999 * fTemp95);
			double fTemp756 = (7.3829387369999999 * fTemp103);
			double fTemp757 = (6.6253734790000003 * fTemp111);
			double fTemp758 = (1.483426838 * fTemp192);
			double fTemp759 = (1.8306905819999999 * fTemp299);
			double fTemp760 = (9.103935044 * fTemp306);
			double fTemp761 = (4.2490024589999997 * fTemp313);
			double fTemp762 = (1.0769006219999999 * fTemp320);
			double fTemp763 = (6.8547684650000003 * fTemp118);
			double fTemp764 = (1.2715701100000001 * fTemp327);
			double fTemp765 = (3.18615205 * fTemp184);
			double fTemp766 = (4.5227457680000001 * fTemp333);
			double fTemp767 = (5.2472893169999999 * fTemp131);
			double fTemp768 = (3.4302582780000002 * fTemp142);
			double fTemp769 = (4.4133753210000002 * fTemp345);
			fVec16[(IOTA & 127)] = ((fTemp706 + (fTemp707 + (fTemp708 + (fTemp709 + (fTemp710 + (fTemp711 + (fTemp712 + (fTemp713 + (fTemp714 + (fTemp715 + (fTemp716 + (fTemp717 + (fTemp718 + (fTemp719 + (fTemp720 + (fTemp721 + (fTemp722 + (fTemp723 + (fTemp724 + (fTemp725 + (fTemp726 + (fTemp727 + (fTemp728 + (fTemp729 + (fTemp730 + (fTemp731 + ((fTemp732 + (fTemp733 + (fTemp734 + fTemp735))) + fTemp736))))))))))))))))))))))))))) - (fTemp737 + (fTemp738 + (fTemp739 + (fTemp740 + (fTemp741 + (fTemp742 + (fTemp743 + (fTemp744 + (fTemp745 + (fTemp746 + (fTemp747 + (fTemp748 + (fTemp749 + (fTemp750 + (fTemp751 + (fTemp752 + (fTemp753 + (fTemp754 + (fTemp755 + (fTemp756 + (fTemp757 + (fTemp758 + (fTemp759 + (fTemp760 + (fTemp761 + (fTemp762 + (fTemp763 + (fTemp764 + (fTemp765 + (fTemp766 + (fTemp767 + (fTemp768 + fTemp769)))))))))))))))))))))))))))))))));
			output16[i] = FAUSTFLOAT((0.97453183520599251 * (fVec16[((IOTA - iConst46) & 127)] * fRec0[0])));
			double fTemp770 = (0.082661583299999994 * fTemp206);
			double fTemp771 = (2.6781261249999999 * fTemp7);
			double fTemp772 = (2.9765368410000002 * fTemp9);
			double fTemp773 = (0.53514945920000001 * fTemp15);
			double fTemp774 = (5.6588847019999999 * fTemp208);
			double fTemp775 = (4.7428954020000003 * fTemp212);
			double fTemp776 = (9.4152120190000002 * fTemp214);
			double fTemp777 = (4.6214548219999996 * fTemp216);
			double fTemp778 = (1.4464887319999999 * fTemp382);
			double fTemp779 = (0.0142531306 * fTemp225);
			double fTemp780 = (1.6535447569999999 * fTemp234);
			double fTemp781 = (4.7128046560000003 * fTemp243);
			double fTemp782 = (3.1628148509999998 * fTemp252);
			double fTemp783 = (2.8259487079999999 * fTemp44);
			double fTemp784 = (3.0667214249999999 * fTemp380);
			double fTemp785 = (7.7908945300000001 * fTemp71);
			double fTemp786 = (5.8197728309999999 * fTemp80);
			double fTemp787 = (0.76237776020000003 * fTemp200);
			double fTemp788 = (0.4668541692 * fTemp260);
			double fTemp789 = (3.9504072520000002 * fTemp268);
			double fTemp790 = (7.0763739460000004 * fTemp276);
			double fTemp791 = (1.2877476859999999 * fTemp284);
			double fTemp792 = (0.9878478812 * fTemp292);
			double fTemp793 = (6.9432423170000002 * fTemp371);
			double fTemp794 = (6.5370798639999999 * fTemp111);
			double fTemp795 = (1.6399428709999999 * fTemp192);
			double fTemp796 = (1.902496803 * fTemp299);
			double fTemp797 = (6.4904161299999998 * fTemp306);
			double fTemp798 = (7.7886388850000001 * fTemp313);
			double fTemp799 = (4.6600241330000003 * fTemp363);
			double fTemp800 = (6.3678964990000004 * fTemp125);
			double fTemp801 = (3.1172956279999999 * fTemp184);
			double fTemp802 = (3.2254921740000002 * fTemp333);
			double fTemp803 = (9.3643585139999992 * fTemp131);
			double fTemp804 = (6.5991740679999999 * fTemp339);
			double fTemp805 = (1.4760703770000001 * fTemp356);
			double fTemp806 = (5.4677444230000001 * fTemp137);
			double fTemp807 = (3.1552963439999999 * fTemp177);
			double fTemp808 = (6.0400353669999998 * fTemp142);
			double fTemp809 = (10.301661340000001 * fTemp147);
			double fTemp810 = (0.61796994230000002 * fTemp350);
			double fTemp811 = (2.5601082499999999 * fTemp152);
			double fTemp812 = (7.8543733400000004 * fTemp156);
			double fTemp813 = (4.8447308070000004 * fTemp160);
			double fTemp814 = (6.532490686 * fTemp162);
			double fTemp815 = (2.019133493 * fTemp166);
			double fTemp816 = (3.4821767690000001 * fTemp171);
			double fTemp817 = (0.35128411269999998 * fTemp204);
			double fTemp818 = (2.8903348050000002 * fTemp11);
			double fTemp819 = (6.9473216969999996 * fTemp13);
			double fTemp820 = (0.036604562100000002 * fTemp17);
			double fTemp821 = (3.7194424869999998 * fTemp202);
			double fTemp822 = (2.9376236809999998 * fTemp210);
			double fTemp823 = (5.4904610119999999 * fTemp26);
			double fTemp824 = (7.4422989020000001 * fTemp35);
			double fTemp825 = (2.1923480369999999 * fTemp53);
			double fTemp826 = (2.8889069300000001 * fTemp62);
			double fTemp827 = (8.7342677739999992 * fTemp88);
			double fTemp828 = (3.3812435660000002 * fTemp95);
			double fTemp829 = (1.977535866 * fTemp320);
			double fTemp830 = (6.9024250509999998 * fTemp118);
			double fTemp831 = (4.7109369389999998 * fTemp345);
			double fTemp832 = (0.83022903069999998 * fTemp327);
			double fTemp833 = (2.586273781 * fTemp103);
			fVec17[(IOTA & 127)] = ((fTemp770 + (fTemp771 + (fTemp772 + (fTemp773 + (fTemp774 + (fTemp775 + (fTemp776 + (fTemp777 + (fTemp778 + (fTemp779 + (fTemp780 + (fTemp781 + (fTemp782 + (fTemp783 + (fTemp784 + (fTemp785 + (fTemp786 + (fTemp787 + (fTemp788 + (fTemp789 + (fTemp790 + (fTemp791 + (fTemp792 + (fTemp793 + (fTemp794 + (fTemp795 + (fTemp796 + (fTemp797 + (fTemp798 + (fTemp799 + (fTemp800 + (fTemp801 + (fTemp802 + (fTemp803 + (fTemp804 + (fTemp805 + (fTemp806 + (fTemp807 + (fTemp808 + (fTemp809 + (fTemp810 + (fTemp811 + ((fTemp812 + (fTemp813 + (fTemp814 + fTemp815))) + fTemp816))))))))))))))))))))))))))))))))))))))))))) - (fTemp817 + (fTemp818 + (fTemp819 + (fTemp820 + (fTemp821 + (fTemp822 + (fTemp823 + (fTemp824 + (fTemp825 + (fTemp826 + (fTemp827 + (fTemp828 + ((fTemp829 + (fTemp830 + (fTemp831 + fTemp832))) + fTemp833))))))))))))));
			output17[i] = FAUSTFLOAT((0.97453183520599251 * (fVec17[((IOTA - iConst46) & 127)] * fRec0[0])));
			double fTemp834 = (0.0309136146 * fTemp11);
			double fTemp835 = (0.77074563620000003 * fTemp15);
			double fTemp836 = (4.0712036390000002 * fTemp210);
			double fTemp837 = (0.75129727530000001 * fTemp382);
			double fTemp838 = (3.895475791 * fTemp53);
			double fTemp839 = (9.5108290209999993 * fTemp147);
			double fTemp840 = (7.1422865010000001 * fTemp156);
			double fTemp841 = (fTemp734 + fTemp733);
			double fTemp842 = (6.3600805669999998 * fTemp339);
			double fTemp843 = (1.0769006219999999 * fTemp327);
			double fTemp844 = (4.5743107619999996 * fTemp103);
			double fTemp845 = (1.2880689219999999 * fTemp204);
			double fTemp846 = (8.5029220389999995 * fTemp7);
			double fTemp847 = (0.24772585850000001 * fTemp17);
			double fTemp848 = (4.8419174040000001 * fTemp214);
			double fTemp849 = (5.2556838370000003 * fTemp234);
			double fTemp850 = (0.0098641100000000006 * fTemp252);
			double fTemp851 = (6.3096703810000001 * fTemp35);
			double fTemp852 = (4.4311452300000003 * fTemp380);
			double fTemp853 = (2.997798688 * fTemp80);
			double fTemp854 = (1.483426838 * fTemp260);
			double fTemp855 = (0.034950011000000003 * fTemp276);
			double fTemp856 = (7.3829387369999999 * fTemp88);
			double fTemp857 = (9.9263573919999999 * fTemp371);
			double fTemp858 = (0.84800542680000002 * fTemp192);
			double fTemp859 = (0.031497049899999997 * fTemp306);
			double fTemp860 = (1.2715701100000001 * fTemp320);
			double fTemp861 = (9.103935044 * fTemp125);
			double fTemp862 = (0.0137563318 * fTemp333);
			double fTemp863 = (3.376093429 * fTemp356);
			double fTemp864 = (4.5227457680000001 * fTemp177);
			double fTemp865 = (5.3136734179999996 * fTemp152);
			double fTemp866 = (4.0629427070000004 * fTemp166);
			fVec18[(IOTA & 127)] = ((fTemp834 + (fTemp835 + (fTemp712 + (fTemp738 + (fTemp836 + (fTemp742 + (fTemp837 + (fTemp718 + (fTemp838 + (fTemp747 + (fTemp750 + (fTemp753 + ((fTemp761 + ((fTemp767 + ((fTemp768 + (fTemp839 + (fTemp730 + (fTemp840 + fTemp841)))) + fTemp842)) + fTemp843)) + fTemp844))))))))))))) - (fTemp845 + (fTemp707 + (fTemp846 + (fTemp737 + (fTemp710 + (fTemp847 + (fTemp740 + (fTemp848 + (fTemp715 + (fTemp849 + (fTemp743 + (fTemp850 + (fTemp717 + (fTemp851 + (fTemp852 + (fTemp748 + (fTemp853 + (fTemp854 + (fTemp751 + (fTemp855 + (fTemp856 + (fTemp755 + (fTemp721 + (fTemp857 + (fTemp757 + (fTemp858 + (fTemp759 + (fTemp859 + (fTemp860 + (fTemp763 + (fTemp723 + (fTemp861 + (fTemp765 + (fTemp862 + (fTemp769 + (fTemp863 + (fTemp727 + (fTemp864 + (fTemp865 + (fTemp736 + fTemp866)))))))))))))))))))))))))))))))))))))))));
			output18[i] = FAUSTFLOAT((0.97453183520599251 * (fVec18[((IOTA - iConst46) & 127)] * fRec0[0])));
			double fTemp867 = (9.4152120190000002 * fTemp7);
			double fTemp868 = (2.9376236809999998 * fTemp11);
			double fTemp869 = (5.8197728309999999 * fTemp234);
			double fTemp870 = (7.4422989020000001 * fTemp53);
			double fTemp871 = (3.1628148509999998 * fTemp380);
			double fTemp872 = (1.6399428709999999 * fTemp260);
			double fTemp873 = (8.7342677739999992 * fTemp103);
			double fTemp874 = (7.0763739460000004 * fTemp371);
			double fTemp875 = (1.977535866 * fTemp327);
			double fTemp876 = (6.4904161299999998 * fTemp125);
			double fTemp877 = (1.4760703770000001 * fTemp339);
			double fTemp878 = (3.2254921740000002 * fTemp177);
			double fTemp879 = (2.5601082499999999 * fTemp147);
			double fTemp880 = (2.019133493 * fTemp156);
			double fTemp881 = (fTemp814 + fTemp813);
			double fTemp882 = (1.4464887319999999 * fTemp204);
			double fTemp883 = (0.036604562100000002 * fTemp15);
			double fTemp884 = (0.53514945920000001 * fTemp17);
			double fTemp885 = (2.8903348050000002 * fTemp210);
			double fTemp886 = (2.6781261249999999 * fTemp214);
			double fTemp887 = (0.35128411269999998 * fTemp382);
			double fTemp888 = (3.0667214249999999 * fTemp252);
			double fTemp889 = (2.1923480369999999 * fTemp35);
			double fTemp890 = (1.6535447569999999 * fTemp80);
			double fTemp891 = (6.9432423170000002 * fTemp276);
			double fTemp892 = (2.586273781 * fTemp88);
			double fTemp893 = (0.4668541692 * fTemp192);
			double fTemp894 = (6.3678964990000004 * fTemp306);
			double fTemp895 = (0.83022903069999998 * fTemp320);
			double fTemp896 = (3.1552963439999999 * fTemp333);
			double fTemp897 = (6.5991740679999999 * fTemp356);
			double fTemp898 = (10.301661340000001 * fTemp152);
			double fTemp899 = (7.8543733400000004 * fTemp166);
			fVec19[(IOTA & 127)] = ((fTemp867 + (fTemp772 + (fTemp868 + (fTemp819 + (fTemp774 + (fTemp821 + (fTemp775 + (fTemp869 + (fTemp781 + (fTemp823 + (fTemp783 + (fTemp870 + (fTemp826 + (fTemp871 + (fTemp785 + (fTemp872 + (fTemp789 + (fTemp873 + (fTemp874 + (fTemp794 + (fTemp796 + (fTemp875 + (fTemp876 + (fTemp801 + (fTemp877 + (fTemp878 + (fTemp879 + (fTemp810 + (fTemp880 + fTemp881))))))))))))))))))))))))))))) - (fTemp882 + (fTemp770 + (fTemp883 + (fTemp884 + (fTemp885 + (fTemp886 + (fTemp777 + (fTemp887 + (fTemp779 + (fTemp888 + (fTemp889 + (fTemp890 + (fTemp787 + (fTemp891 + (fTemp791 + (fTemp892 + (fTemp828 + (fTemp792 + (fTemp893 + (fTemp894 + (fTemp798 + (fTemp895 + (fTemp830 + (fTemp799 + (fTemp896 + (fTemp803 + (fTemp831 + (fTemp897 + (fTemp806 + (fTemp808 + (fTemp898 + (fTemp816 + fTemp899)))))))))))))))))))))))))))))))));
			output19[i] = FAUSTFLOAT((0.97453183520599251 * (fVec19[((IOTA - iConst46) & 127)] * fRec0[0])));
			fVec20[(IOTA & 127)] = ((fTemp707 + (fTemp710 + (fTemp712 + (fTemp739 + (fTemp741 + (fTemp715 + (fTemp744 + (fTemp717 + (fTemp745 + (fTemp718 + (fTemp746 + (fTemp749 + (fTemp752 + (fTemp754 + (fTemp756 + (fTemp721 + (fTemp758 + (fTemp760 + (fTemp762 + (fTemp764 + (fTemp723 + (fTemp766 + (fTemp727 + (fTemp730 + (fTemp736 + fTemp841))))))))))))))))))))))))) - (fTemp706 + (fTemp708 + (fTemp737 + (fTemp709 + (fTemp711 + (fTemp713 + (fTemp738 + (fTemp740 + (fTemp742 + (fTemp714 + (fTemp716 + (fTemp743 + (fTemp747 + (fTemp719 + (fTemp748 + (fTemp750 + (fTemp720 + (fTemp751 + (fTemp753 + (fTemp755 + (fTemp722 + (fTemp757 + (fTemp759 + (fTemp761 + (fTemp763 + (fTemp724 + (fTemp765 + (fTemp767 + (fTemp725 + (fTemp769 + (fTemp726 + (fTemp728 + (fTemp768 + (fTemp729 + (fTemp731 + (fTemp735 + fTemp732)))))))))))))))))))))))))))))))))))));
			output20[i] = FAUSTFLOAT((0.97453183520599251 * (fVec20[((IOTA - iConst46) & 127)] * fRec0[0])));
			fVec21[(IOTA & 127)] = ((fTemp817 + (fTemp770 + (fTemp772 + (fTemp818 + (fTemp774 + (fTemp820 + (fTemp822 + (fTemp775 + (fTemp777 + (fTemp779 + (fTemp781 + (fTemp824 + (fTemp783 + (fTemp825 + (fTemp785 + (fTemp787 + (fTemp789 + (fTemp791 + (fTemp827 + (fTemp833 + (fTemp792 + (fTemp794 + (fTemp796 + (fTemp798 + (fTemp829 + (fTemp832 + (fTemp799 + (fTemp801 + (fTemp803 + (fTemp806 + (fTemp808 + (fTemp810 + (fTemp816 + fTemp881))))))))))))))))))))))))))))))))) - (fTemp771 + (fTemp819 + (fTemp773 + (fTemp821 + (fTemp776 + (fTemp778 + (fTemp780 + (fTemp782 + (fTemp823 + (fTemp826 + (fTemp784 + (fTemp786 + (fTemp788 + (fTemp790 + (fTemp828 + (fTemp793 + (fTemp795 + (fTemp797 + (fTemp830 + (fTemp800 + (fTemp802 + (fTemp804 + (fTemp831 + (fTemp805 + (fTemp807 + (fTemp809 + (fTemp811 + (fTemp815 + fTemp812)))))))))))))))))))))))))))));
			output21[i] = FAUSTFLOAT((0.97453183520599251 * (fVec21[((IOTA - iConst46) & 127)] * fRec0[0])));
			fVec22[(IOTA & 127)] = ((fTemp845 + (fTemp846 + (fTemp712 + (fTemp847 + (fTemp738 + (fTemp848 + (fTemp742 + (fTemp849 + (fTemp850 + (fTemp851 + (fTemp718 + (fTemp747 + (fTemp852 + (fTemp853 + (fTemp750 + (fTemp854 + (fTemp855 + (fTemp753 + (fTemp856 + (fTemp857 + (fTemp858 + (fTemp859 + (fTemp761 + (fTemp860 + (fTemp861 + (fTemp862 + (fTemp767 + (fTemp863 + (fTemp864 + (fTemp768 + (fTemp730 + (fTemp865 + (fTemp733 + (fTemp734 + fTemp866)))))))))))))))))))))))))))))))))) - (fTemp707 + (fTemp737 + (fTemp834 + (fTemp710 + (fTemp835 + (fTemp836 + (fTemp740 + (fTemp837 + (fTemp715 + (fTemp743 + (fTemp717 + (fTemp838 + (fTemp748 + (fTemp751 + (fTemp755 + (fTemp844 + (fTemp721 + (fTemp757 + (fTemp759 + (fTemp763 + (fTemp843 + (fTemp723 + (fTemp765 + (fTemp842 + (fTemp769 + (fTemp727 + (fTemp839 + (fTemp736 + fTemp840)))))))))))))))))))))))))))));
			output22[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec22[((IOTA - iConst46) & 127)])));
			fVec23[(IOTA & 127)] = ((fTemp882 + (fTemp772 + (fTemp819 + (fTemp883 + (fTemp774 + (fTemp884 + (fTemp821 + (fTemp885 + (fTemp775 + (fTemp886 + (fTemp887 + (fTemp781 + (fTemp888 + (fTemp823 + (fTemp889 + (fTemp783 + (fTemp826 + (fTemp785 + (fTemp890 + (fTemp789 + (fTemp891 + (fTemp892 + (fTemp794 + (fTemp893 + (fTemp796 + (fTemp894 + (fTemp895 + (fTemp801 + (fTemp896 + (fTemp897 + (fTemp810 + (fTemp898 + (fTemp813 + (fTemp814 + fTemp899)))))))))))))))))))))))))))))))))) - (fTemp770 + (fTemp867 + (fTemp868 + (fTemp777 + (fTemp779 + (fTemp869 + (fTemp870 + (fTemp871 + (fTemp787 + (fTemp872 + (fTemp791 + (fTemp828 + (fTemp873 + (fTemp792 + (fTemp874 + (fTemp798 + (fTemp830 + (fTemp875 + (fTemp799 + (fTemp876 + (fTemp803 + (fTemp877 + (fTemp831 + (fTemp806 + (fTemp878 + (fTemp808 + (fTemp879 + (fTemp816 + fTemp880)))))))))))))))))))))))))))));
			output23[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec23[((IOTA - iConst46) & 127)])));
			double fTemp900 = (0.038965435700000002 * fTemp7);
			double fTemp901 = (6.0171417690000002 * fTemp11);
			double fTemp902 = (6.8821432409999996 * fTemp17);
			double fTemp903 = (1.5299071099999999 * fTemp212);
			double fTemp904 = (0.0064769347 * fTemp382);
			double fTemp905 = (0.0162970084 * fTemp225);
			double fTemp906 = (0.055722914700000001 * fTemp234);
			double fTemp907 = (3.6018216760000001 * fTemp252);
			double fTemp908 = (8.5336788670000008 * fTemp53);
			double fTemp909 = (0.69463649189999999 * fTemp71);
			double fTemp910 = (0.030469274099999999 * fTemp200);
			double fTemp911 = (2.020737274 * fTemp276);
			double fTemp912 = (10.285835349999999 * fTemp103);
			double fTemp913 = (0.040448873900000001 * fTemp371);
			double fTemp914 = (0.4793677717 * fTemp111);
			double fTemp915 = (1.447422097 * fTemp306);
			double fTemp916 = (2.6260260780000002 * fTemp118);
			double fTemp917 = (11.374075059999999 * fTemp327);
			double fTemp918 = (0.037739054399999999 * fTemp125);
			double fTemp919 = (0.37829416669999999 * fTemp184);
			double fTemp920 = (1.0414951180000001 * fTemp333);
			double fTemp921 = (7.8199679870000001 * fTemp345);
			double fTemp922 = (10.320174 * fTemp356);
			double fTemp923 = (0.0074973289 * fTemp177);
			double fTemp924 = (10.33791387 * fTemp350);
			double fTemp925 = (8.9754057469999999 * fTemp160);
			double fTemp926 = (6.4915337969999998 * fTemp162);
			double fTemp927 = (3.2141915050000001 * fTemp166);
			double fTemp928 = (7.010265586 * fTemp152);
			double fTemp929 = (0.0250286095 * fTemp204);
			double fTemp930 = (0.019192830599999999 * fTemp206);
			double fTemp931 = (1.113720678 * fTemp9);
			double fTemp932 = (5.3411400870000003 * fTemp13);
			double fTemp933 = (3.9158972109999999 * fTemp15);
			double fTemp934 = (6.6566273259999997 * fTemp208);
			double fTemp935 = (8.9808795729999993 * fTemp202);
			double fTemp936 = (0.14368163959999999 * fTemp210);
			double fTemp937 = (0.87248924490000002 * fTemp214);
			double fTemp938 = (0.16608544489999999 * fTemp216);
			double fTemp939 = (0.80475541979999998 * fTemp243);
			double fTemp940 = (5.1261180389999996 * fTemp26);
			double fTemp941 = (4.854937939 * fTemp35);
			double fTemp942 = (4.7147495399999997 * fTemp44);
			double fTemp943 = (8.6205356070000008 * fTemp62);
			double fTemp944 = (0.028860171 * fTemp380);
			double fTemp945 = (0.3846485804 * fTemp80);
			double fTemp946 = (0.0046519118999999998 * fTemp260);
			double fTemp947 = (0.59036465439999997 * fTemp268);
			double fTemp948 = (4.7963182670000002 * fTemp284);
			double fTemp949 = (5.8516345489999999 * fTemp88);
			double fTemp950 = (2.0089750830000002 * fTemp95);
			double fTemp951 = (8.0713344449999997 * fTemp292);
			double fTemp952 = (0.049904365700000002 * fTemp192);
			double fTemp953 = (0.34359817259999997 * fTemp299);
			double fTemp954 = (3.8004328599999999 * fTemp313);
			double fTemp955 = (6.4712709520000002 * fTemp320);
			double fTemp956 = (6.4013392329999999 * fTemp363);
			double fTemp957 = (2.1847903209999999 * fTemp131);
			double fTemp958 = (5.872304346 * fTemp339);
			double fTemp959 = (3.6847115549999998 * fTemp137);
			double fTemp960 = (0.72325702059999997 * fTemp142);
			double fTemp961 = (3.9893380220000001 * fTemp147);
			double fTemp962 = (1.829278298 * fTemp156);
			double fTemp963 = (1.2229323219999999 * fTemp171);
			fVec24[0] = ((fTemp900 + (fTemp901 + (fTemp902 + (fTemp903 + (fTemp904 + (fTemp905 + (fTemp906 + (fTemp907 + (fTemp908 + (fTemp909 + (fTemp910 + (fTemp911 + (fTemp912 + (fTemp913 + (fTemp914 + (fTemp915 + (fTemp916 + (fTemp917 + (fTemp918 + (fTemp919 + (fTemp920 + (fTemp921 + (fTemp922 + (fTemp923 + (fTemp924 + ((fTemp925 + (fTemp926 + fTemp927)) + fTemp928)))))))))))))))))))))))))) - (fTemp929 + (fTemp930 + (fTemp931 + (fTemp932 + (fTemp933 + (fTemp934 + (fTemp935 + (fTemp936 + (fTemp937 + (fTemp938 + (fTemp939 + (fTemp940 + (fTemp941 + (fTemp942 + (fTemp943 + (fTemp944 + (fTemp945 + (fTemp946 + (fTemp947 + (fTemp948 + (fTemp949 + (fTemp950 + (fTemp951 + (fTemp952 + (fTemp953 + (fTemp954 + (fTemp955 + (fTemp956 + (fTemp957 + (fTemp958 + (fTemp959 + (fTemp960 + (fTemp961 + (fTemp962 + fTemp963)))))))))))))))))))))))))))))))))));
			output24[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec24[iConst47])));
			double fTemp964 = (0.14368163959999999 * fTemp11);
			double fTemp965 = (6.8821432409999996 * fTemp15);
			double fTemp966 = (3.9158972109999999 * fTemp17);
			double fTemp967 = (6.0171417690000002 * fTemp210);
			double fTemp968 = (0.028860171 * fTemp252);
			double fTemp969 = (8.5336788670000008 * fTemp35);
			double fTemp970 = (4.854937939 * fTemp53);
			double fTemp971 = (3.6018216760000001 * fTemp380);
			double fTemp972 = (10.285835349999999 * fTemp88);
			double fTemp973 = (5.8516345489999999 * fTemp103);
			double fTemp974 = (2.020737274 * fTemp371);
			double fTemp975 = (0.0046519118999999998 * fTemp192);
			double fTemp976 = (11.374075059999999 * fTemp320);
			double fTemp977 = (6.4712709520000002 * fTemp327);
			double fTemp978 = (1.447422097 * fTemp125);
			double fTemp979 = (10.320174 * fTemp339);
			double fTemp980 = (5.872304346 * fTemp356);
			double fTemp981 = (1.0414951180000001 * fTemp177);
			double fTemp982 = (7.010265586 * fTemp147);
			double fTemp983 = (3.9893380220000001 * fTemp152);
			double fTemp984 = (3.2141915050000001 * fTemp156);
			double fTemp985 = (1.829278298 * fTemp166);
			double fTemp986 = (0.0064769347 * fTemp204);
			double fTemp987 = (0.87248924490000002 * fTemp7);
			double fTemp988 = (0.038965435700000002 * fTemp214);
			double fTemp989 = (0.0250286095 * fTemp382);
			double fTemp990 = (0.3846485804 * fTemp234);
			double fTemp991 = (0.055722914700000001 * fTemp80);
			double fTemp992 = (0.049904365700000002 * fTemp260);
			double fTemp993 = (0.040448873900000001 * fTemp276);
			double fTemp994 = (0.0074973289 * fTemp333);
			double fTemp995 = (0.037739054399999999 * fTemp306);
			fVec25[0] = ((fTemp930 + (fTemp964 + (fTemp932 + (fTemp965 + (fTemp966 + (fTemp935 + (fTemp967 + (fTemp903 + (fTemp938 + (fTemp968 + (fTemp940 + (fTemp969 + (fTemp970 + (fTemp943 + (fTemp971 + (fTemp909 + (fTemp948 + (fTemp972 + (fTemp973 + (fTemp951 + (fTemp974 + (fTemp914 + (fTemp975 + (fTemp954 + (fTemp976 + (fTemp916 + (fTemp977 + (fTemp956 + (fTemp978 + (fTemp919 + (fTemp957 + (fTemp979 + (fTemp921 + (fTemp980 + (fTemp959 + (fTemp981 + (fTemp960 + (fTemp982 + (fTemp924 + (fTemp983 + (fTemp963 + (fTemp984 + (fTemp925 + (fTemp926 + fTemp985)))))))))))))))))))))))))))))))))))))))))))) - (fTemp986 + (fTemp987 + (fTemp931 + (fTemp934 + (fTemp988 + (fTemp989 + (fTemp905 + (fTemp990 + (fTemp939 + (fTemp942 + (fTemp991 + (fTemp910 + (fTemp992 + (fTemp947 + (fTemp993 + (fTemp950 + (fTemp953 + (fTemp994 + fTemp995)))))))))))))))))));
			output25[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec25[iConst47])));
			double fTemp996 = (fTemp926 + fTemp925);
			fVec26[0] = ((fTemp929 + (fTemp933 + (fTemp936 + (fTemp903 + (fTemp937 + (fTemp905 + (fTemp941 + (fTemp944 + (fTemp909 + (fTemp945 + (fTemp910 + (fTemp946 + (fTemp949 + (fTemp914 + (fTemp952 + (fTemp955 + (fTemp916 + (fTemp919 + (fTemp958 + (fTemp921 + (fTemp961 + (fTemp924 + (fTemp962 + fTemp996))))))))))))))))))))))) - (fTemp930 + (fTemp900 + (fTemp931 + (fTemp901 + (fTemp932 + (fTemp934 + (fTemp902 + (fTemp935 + (fTemp938 + (fTemp904 + (fTemp906 + (fTemp939 + (fTemp907 + (fTemp940 + (fTemp942 + (fTemp908 + (fTemp943 + (fTemp947 + (fTemp911 + (fTemp948 + (fTemp950 + (fTemp912 + (fTemp951 + (fTemp913 + (fTemp953 + (fTemp915 + (fTemp954 + (fTemp917 + (fTemp956 + (fTemp918 + (fTemp920 + (fTemp957 + (fTemp922 + (fTemp959 + (fTemp923 + (fTemp960 + (fTemp928 + (fTemp927 + fTemp963)))))))))))))))))))))))))))))))))))))));
			output26[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec26[iConst47])));
			fVec27[0] = ((fTemp986 + (fTemp930 + (fTemp987 + (fTemp932 + (fTemp935 + (fTemp903 + (fTemp988 + (fTemp938 + (fTemp989 + (fTemp990 + (fTemp940 + (fTemp943 + (fTemp909 + (fTemp991 + (fTemp992 + (fTemp993 + (fTemp948 + (fTemp951 + (fTemp914 + (fTemp995 + (fTemp954 + (fTemp916 + (fTemp956 + (fTemp919 + (fTemp994 + (fTemp957 + (fTemp921 + (fTemp959 + (fTemp960 + (fTemp924 + (fTemp963 + fTemp996))))))))))))))))))))))))))))))) - (fTemp931 + (fTemp964 + (fTemp965 + (fTemp934 + (fTemp966 + (fTemp967 + (fTemp905 + (fTemp939 + (fTemp968 + (fTemp969 + (fTemp942 + (fTemp970 + (fTemp971 + (fTemp910 + (fTemp947 + (fTemp972 + (fTemp950 + (fTemp973 + (fTemp974 + (fTemp975 + (fTemp953 + (fTemp976 + (fTemp977 + (fTemp978 + (fTemp979 + (fTemp980 + (fTemp981 + (fTemp982 + (fTemp983 + (fTemp985 + fTemp984)))))))))))))))))))))))))))))));
			output27[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec27[iConst47])));
			output28[i] = FAUSTFLOAT((fRec0[0] * (((1.0022556920000001 * fTemp9) + (((0.77675457079999999 * fTemp243) + (((0.62289750610000005 * fTemp268) + (((0.3862189157 * fTemp299) + (((((4.5334054090000002 * fTemp160) + (4.3090696590000004 * fTemp162)) + (6.5394628079999997 * fTemp350)) + (10.77861688 * fTemp345)) + (15.277198569999999 * fTemp118))) + (17.805356270000001 * fTemp95))) + (18.61539063 * fTemp44))) + (19.897858889999998 * fTemp208))) - ((1.1763901450000001 * fTemp212) + ((0.43139866300000002 * fTemp71) + ((0.4069261992 * fTemp184) + (0.39133584519999998 * fTemp111)))))));
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
			fRec141[1] = fRec141[0];
			fRec139[1] = fRec139[0];
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
			fRec157[1] = fRec157[0];
			fRec155[1] = fRec155[0];
			fRec154[1] = fRec154[0];
			fRec152[1] = fRec152[0];
			fRec151[1] = fRec151[0];
			fRec149[1] = fRec149[0];
			fRec148[1] = fRec148[0];
			fRec146[1] = fRec146[0];
			fRec145[1] = fRec145[0];
			fRec143[1] = fRec143[0];
			fRec142[2] = fRec142[1];
			fRec142[1] = fRec142[0];
			fRec173[1] = fRec173[0];
			fRec171[1] = fRec171[0];
			fRec170[1] = fRec170[0];
			fRec168[1] = fRec168[0];
			fRec167[1] = fRec167[0];
			fRec165[1] = fRec165[0];
			fRec164[1] = fRec164[0];
			fRec162[1] = fRec162[0];
			fRec161[1] = fRec161[0];
			fRec159[1] = fRec159[0];
			fRec158[2] = fRec158[1];
			fRec158[1] = fRec158[0];
			fRec189[1] = fRec189[0];
			fRec187[1] = fRec187[0];
			fRec186[1] = fRec186[0];
			fRec184[1] = fRec184[0];
			fRec183[1] = fRec183[0];
			fRec181[1] = fRec181[0];
			fRec180[1] = fRec180[0];
			fRec178[1] = fRec178[0];
			fRec177[1] = fRec177[0];
			fRec175[1] = fRec175[0];
			fRec174[2] = fRec174[1];
			fRec174[1] = fRec174[0];
			fRec205[1] = fRec205[0];
			fRec203[1] = fRec203[0];
			fRec202[1] = fRec202[0];
			fRec200[1] = fRec200[0];
			fRec199[1] = fRec199[0];
			fRec197[1] = fRec197[0];
			fRec196[1] = fRec196[0];
			fRec194[1] = fRec194[0];
			fRec193[1] = fRec193[0];
			fRec191[1] = fRec191[0];
			fRec190[2] = fRec190[1];
			fRec190[1] = fRec190[0];
			fRec218[1] = fRec218[0];
			fRec216[1] = fRec216[0];
			fRec215[1] = fRec215[0];
			fRec213[1] = fRec213[0];
			fRec212[1] = fRec212[0];
			fRec210[1] = fRec210[0];
			fRec209[1] = fRec209[0];
			fRec207[1] = fRec207[0];
			fRec206[2] = fRec206[1];
			fRec206[1] = fRec206[0];
			fRec231[1] = fRec231[0];
			fRec229[1] = fRec229[0];
			fRec228[1] = fRec228[0];
			fRec226[1] = fRec226[0];
			fRec225[1] = fRec225[0];
			fRec223[1] = fRec223[0];
			fRec222[1] = fRec222[0];
			fRec220[1] = fRec220[0];
			fRec219[2] = fRec219[1];
			fRec219[1] = fRec219[0];
			fRec241[1] = fRec241[0];
			fRec239[1] = fRec239[0];
			fRec238[1] = fRec238[0];
			fRec236[1] = fRec236[0];
			fRec235[1] = fRec235[0];
			fRec233[1] = fRec233[0];
			fRec232[2] = fRec232[1];
			fRec232[1] = fRec232[0];
			fRec251[1] = fRec251[0];
			fRec249[1] = fRec249[0];
			fRec248[1] = fRec248[0];
			fRec246[1] = fRec246[0];
			fRec245[1] = fRec245[0];
			fRec243[1] = fRec243[0];
			fRec242[2] = fRec242[1];
			fRec242[1] = fRec242[0];
			fRec258[1] = fRec258[0];
			fRec256[1] = fRec256[0];
			fRec255[1] = fRec255[0];
			fRec253[1] = fRec253[0];
			fRec252[2] = fRec252[1];
			fRec252[1] = fRec252[0];
			fRec265[1] = fRec265[0];
			fRec263[1] = fRec263[0];
			fRec262[1] = fRec262[0];
			fRec260[1] = fRec260[0];
			fRec259[2] = fRec259[1];
			fRec259[1] = fRec259[0];
			fRec272[1] = fRec272[0];
			fRec270[1] = fRec270[0];
			fRec269[1] = fRec269[0];
			fRec267[1] = fRec267[0];
			fRec266[2] = fRec266[1];
			fRec266[1] = fRec266[0];
			fRec276[1] = fRec276[0];
			fRec274[1] = fRec274[0];
			fRec273[2] = fRec273[1];
			fRec273[1] = fRec273[0];
			fRec280[1] = fRec280[0];
			fRec278[1] = fRec278[0];
			fRec277[2] = fRec277[1];
			fRec277[1] = fRec277[0];
			fRec281[2] = fRec281[1];
			fRec281[1] = fRec281[0];
			fRec285[1] = fRec285[0];
			fRec283[1] = fRec283[0];
			fRec282[2] = fRec282[1];
			fRec282[1] = fRec282[0];
			fRec292[1] = fRec292[0];
			fRec290[1] = fRec290[0];
			fRec289[1] = fRec289[0];
			fRec287[1] = fRec287[0];
			fRec286[2] = fRec286[1];
			fRec286[1] = fRec286[0];
			fRec302[1] = fRec302[0];
			fRec300[1] = fRec300[0];
			fRec299[1] = fRec299[0];
			fRec297[1] = fRec297[0];
			fRec296[1] = fRec296[0];
			fRec294[1] = fRec294[0];
			fRec293[2] = fRec293[1];
			fRec293[1] = fRec293[0];
			fRec315[1] = fRec315[0];
			fRec313[1] = fRec313[0];
			fRec312[1] = fRec312[0];
			fRec310[1] = fRec310[0];
			fRec309[1] = fRec309[0];
			fRec307[1] = fRec307[0];
			fRec306[1] = fRec306[0];
			fRec304[1] = fRec304[0];
			fRec303[2] = fRec303[1];
			fRec303[1] = fRec303[0];
			fRec331[1] = fRec331[0];
			fRec329[1] = fRec329[0];
			fRec328[1] = fRec328[0];
			fRec326[1] = fRec326[0];
			fRec325[1] = fRec325[0];
			fRec323[1] = fRec323[0];
			fRec322[1] = fRec322[0];
			fRec320[1] = fRec320[0];
			fRec319[1] = fRec319[0];
			fRec317[1] = fRec317[0];
			fRec316[2] = fRec316[1];
			fRec316[1] = fRec316[0];
			fRec350[1] = fRec350[0];
			fRec348[1] = fRec348[0];
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
			fRec332[2] = fRec332[1];
			fRec332[1] = fRec332[0];
			fRec351[2] = fRec351[1];
			fRec351[1] = fRec351[0];
			fRec352[2] = fRec352[1];
			fRec352[1] = fRec352[0];
			fRec353[2] = fRec353[1];
			fRec353[1] = fRec353[0];
			fRec354[2] = fRec354[1];
			fRec354[1] = fRec354[0];
			fRec355[2] = fRec355[1];
			fRec355[1] = fRec355[0];
			fRec356[2] = fRec356[1];
			fRec356[1] = fRec356[0];
			fRec357[2] = fRec357[1];
			fRec357[1] = fRec357[0];
			fRec358[2] = fRec358[1];
			fRec358[1] = fRec358[0];
			fRec377[1] = fRec377[0];
			fRec375[1] = fRec375[0];
			fRec374[1] = fRec374[0];
			fRec372[1] = fRec372[0];
			fRec371[1] = fRec371[0];
			fRec369[1] = fRec369[0];
			fRec368[1] = fRec368[0];
			fRec366[1] = fRec366[0];
			fRec365[1] = fRec365[0];
			fRec363[1] = fRec363[0];
			fRec362[1] = fRec362[0];
			fRec360[1] = fRec360[0];
			fRec359[2] = fRec359[1];
			fRec359[1] = fRec359[0];
			fRec396[1] = fRec396[0];
			fRec394[1] = fRec394[0];
			fRec393[1] = fRec393[0];
			fRec391[1] = fRec391[0];
			fRec390[1] = fRec390[0];
			fRec388[1] = fRec388[0];
			fRec387[1] = fRec387[0];
			fRec385[1] = fRec385[0];
			fRec384[1] = fRec384[0];
			fRec382[1] = fRec382[0];
			fRec381[1] = fRec381[0];
			fRec379[1] = fRec379[0];
			fRec378[2] = fRec378[1];
			fRec378[1] = fRec378[0];
			fRec415[1] = fRec415[0];
			fRec413[1] = fRec413[0];
			fRec412[1] = fRec412[0];
			fRec410[1] = fRec410[0];
			fRec409[1] = fRec409[0];
			fRec407[1] = fRec407[0];
			fRec406[1] = fRec406[0];
			fRec404[1] = fRec404[0];
			fRec403[1] = fRec403[0];
			fRec401[1] = fRec401[0];
			fRec400[1] = fRec400[0];
			fRec398[1] = fRec398[0];
			fRec397[2] = fRec397[1];
			fRec397[1] = fRec397[0];
			fRec434[1] = fRec434[0];
			fRec432[1] = fRec432[0];
			fRec431[1] = fRec431[0];
			fRec429[1] = fRec429[0];
			fRec428[1] = fRec428[0];
			fRec426[1] = fRec426[0];
			fRec425[1] = fRec425[0];
			fRec423[1] = fRec423[0];
			fRec422[1] = fRec422[0];
			fRec420[1] = fRec420[0];
			fRec419[1] = fRec419[0];
			fRec417[1] = fRec417[0];
			fRec416[2] = fRec416[1];
			fRec416[1] = fRec416[0];
			fRec450[1] = fRec450[0];
			fRec448[1] = fRec448[0];
			fRec447[1] = fRec447[0];
			fRec445[1] = fRec445[0];
			fRec444[1] = fRec444[0];
			fRec442[1] = fRec442[0];
			fRec441[1] = fRec441[0];
			fRec439[1] = fRec439[0];
			fRec438[1] = fRec438[0];
			fRec436[1] = fRec436[0];
			fRec435[2] = fRec435[1];
			fRec435[1] = fRec435[0];
			fRec466[1] = fRec466[0];
			fRec464[1] = fRec464[0];
			fRec463[1] = fRec463[0];
			fRec461[1] = fRec461[0];
			fRec460[1] = fRec460[0];
			fRec458[1] = fRec458[0];
			fRec457[1] = fRec457[0];
			fRec455[1] = fRec455[0];
			fRec454[1] = fRec454[0];
			fRec452[1] = fRec452[0];
			fRec451[2] = fRec451[1];
			fRec451[1] = fRec451[0];
			fRec482[1] = fRec482[0];
			fRec480[1] = fRec480[0];
			fRec479[1] = fRec479[0];
			fRec477[1] = fRec477[0];
			fRec476[1] = fRec476[0];
			fRec474[1] = fRec474[0];
			fRec473[1] = fRec473[0];
			fRec471[1] = fRec471[0];
			fRec470[1] = fRec470[0];
			fRec468[1] = fRec468[0];
			fRec467[2] = fRec467[1];
			fRec467[1] = fRec467[0];
			fRec498[1] = fRec498[0];
			fRec496[1] = fRec496[0];
			fRec495[1] = fRec495[0];
			fRec493[1] = fRec493[0];
			fRec492[1] = fRec492[0];
			fRec490[1] = fRec490[0];
			fRec489[1] = fRec489[0];
			fRec487[1] = fRec487[0];
			fRec486[1] = fRec486[0];
			fRec484[1] = fRec484[0];
			fRec483[2] = fRec483[1];
			fRec483[1] = fRec483[0];
			fRec514[1] = fRec514[0];
			fRec512[1] = fRec512[0];
			fRec511[1] = fRec511[0];
			fRec509[1] = fRec509[0];
			fRec508[1] = fRec508[0];
			fRec506[1] = fRec506[0];
			fRec505[1] = fRec505[0];
			fRec503[1] = fRec503[0];
			fRec502[1] = fRec502[0];
			fRec500[1] = fRec500[0];
			fRec499[2] = fRec499[1];
			fRec499[1] = fRec499[0];
			fRec527[1] = fRec527[0];
			fRec525[1] = fRec525[0];
			fRec524[1] = fRec524[0];
			fRec522[1] = fRec522[0];
			fRec521[1] = fRec521[0];
			fRec519[1] = fRec519[0];
			fRec518[1] = fRec518[0];
			fRec516[1] = fRec516[0];
			fRec515[2] = fRec515[1];
			fRec515[1] = fRec515[0];
			fRec540[1] = fRec540[0];
			fRec538[1] = fRec538[0];
			fRec537[1] = fRec537[0];
			fRec535[1] = fRec535[0];
			fRec534[1] = fRec534[0];
			fRec532[1] = fRec532[0];
			fRec531[1] = fRec531[0];
			fRec529[1] = fRec529[0];
			fRec528[2] = fRec528[1];
			fRec528[1] = fRec528[0];
			fRec553[1] = fRec553[0];
			fRec551[1] = fRec551[0];
			fRec550[1] = fRec550[0];
			fRec548[1] = fRec548[0];
			fRec547[1] = fRec547[0];
			fRec545[1] = fRec545[0];
			fRec544[1] = fRec544[0];
			fRec542[1] = fRec542[0];
			fRec541[2] = fRec541[1];
			fRec541[1] = fRec541[0];
			fRec566[1] = fRec566[0];
			fRec564[1] = fRec564[0];
			fRec563[1] = fRec563[0];
			fRec561[1] = fRec561[0];
			fRec560[1] = fRec560[0];
			fRec558[1] = fRec558[0];
			fRec557[1] = fRec557[0];
			fRec555[1] = fRec555[0];
			fRec554[2] = fRec554[1];
			fRec554[1] = fRec554[0];
			fRec579[1] = fRec579[0];
			fRec577[1] = fRec577[0];
			fRec576[1] = fRec576[0];
			fRec574[1] = fRec574[0];
			fRec573[1] = fRec573[0];
			fRec571[1] = fRec571[0];
			fRec570[1] = fRec570[0];
			fRec568[1] = fRec568[0];
			fRec567[2] = fRec567[1];
			fRec567[1] = fRec567[0];
			fRec589[1] = fRec589[0];
			fRec587[1] = fRec587[0];
			fRec586[1] = fRec586[0];
			fRec584[1] = fRec584[0];
			fRec583[1] = fRec583[0];
			fRec581[1] = fRec581[0];
			fRec580[2] = fRec580[1];
			fRec580[1] = fRec580[0];
			fRec599[1] = fRec599[0];
			fRec597[1] = fRec597[0];
			fRec596[1] = fRec596[0];
			fRec594[1] = fRec594[0];
			fRec593[1] = fRec593[0];
			fRec591[1] = fRec591[0];
			fRec590[2] = fRec590[1];
			fRec590[1] = fRec590[0];
			fRec609[1] = fRec609[0];
			fRec607[1] = fRec607[0];
			fRec606[1] = fRec606[0];
			fRec604[1] = fRec604[0];
			fRec603[1] = fRec603[0];
			fRec601[1] = fRec601[0];
			fRec600[2] = fRec600[1];
			fRec600[1] = fRec600[0];
			fRec616[1] = fRec616[0];
			fRec614[1] = fRec614[0];
			fRec613[1] = fRec613[0];
			fRec611[1] = fRec611[0];
			fRec610[2] = fRec610[1];
			fRec610[1] = fRec610[0];
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
