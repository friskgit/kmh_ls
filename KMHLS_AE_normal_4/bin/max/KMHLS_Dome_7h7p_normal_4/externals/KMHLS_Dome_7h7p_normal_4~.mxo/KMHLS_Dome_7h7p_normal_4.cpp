/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMHLS_Dome_7h7p_normal_4"
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
	
	int fSamplingFreq;
	int iConst0;
	double fConst1;
	FAUSTFLOAT fHslider0;
	double fRec0[2];
	double fRec1[3];
	FAUSTFLOAT fHslider1;
	double fRec2[2];
	double fRec3[3];
	double fRec4[3];
	double fRec5[3];
	double fRec6[3];
	double fRec7[3];
	double fConst2;
	double fConst3;
	double fConst4;
	double fRec11[3];
	double fRec12[3];
	double fRec13[3];
	double fConst5;
	double fRec10[2];
	double fRec8[2];
	double fConst6;
	double fConst7;
	double fRec20[3];
	double fRec21[3];
	double fRec22[3];
	double fRec23[3];
	double fRec24[3];
	double fConst8;
	double fConst9;
	double fConst10;
	double fRec19[2];
	double fRec17[2];
	double fRec16[2];
	double fRec14[2];
	double fConst11;
	double fConst12;
	double fConst13;
	double fConst14;
	double fRec34[3];
	double fRec35[3];
	double fRec36[3];
	double fRec37[3];
	double fRec38[3];
	double fRec39[3];
	double fRec40[3];
	double fConst15;
	double fConst16;
	double fRec33[2];
	double fRec31[2];
	double fRec30[2];
	double fRec28[2];
	double fRec27[2];
	double fRec25[2];
	double fConst17;
	double fConst18;
	double fConst19;
	double fConst20;
	double fConst21;
	double fRec53[3];
	double fRec54[3];
	double fRec55[3];
	double fRec56[3];
	double fRec57[3];
	double fRec58[3];
	double fRec59[3];
	double fRec60[3];
	double fRec61[3];
	double fConst22;
	double fConst23;
	double fRec52[2];
	double fRec50[2];
	double fRec49[2];
	double fRec47[2];
	double fRec46[2];
	double fRec44[2];
	double fRec43[2];
	double fRec41[2];
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fConst28;
	double fConst29;
	double fConst30;
	double fRec77[3];
	double fRec78[3];
	double fRec79[3];
	double fRec80[3];
	double fRec81[3];
	double fRec82[3];
	double fRec83[3];
	double fRec84[3];
	double fRec85[3];
	double fRec86[3];
	double fRec87[3];
	double fConst31;
	double fConst32;
	double fRec76[2];
	double fRec74[2];
	double fRec73[2];
	double fRec71[2];
	double fRec70[2];
	double fRec68[2];
	double fRec67[2];
	double fRec65[2];
	double fRec64[2];
	double fRec62[2];
	double fConst33;
	double fConst34;
	double fConst35;
	double fConst36;
	double fConst37;
	double fConst38;
	double fConst39;
	double fConst40;
	double fRec106[3];
	double fRec107[3];
	double fRec108[3];
	double fRec109[3];
	double fRec110[3];
	double fRec111[3];
	double fRec112[3];
	double fRec113[3];
	double fRec114[3];
	double fRec115[3];
	double fRec116[3];
	double fRec117[3];
	double fRec118[3];
	double fConst41;
	double fConst42;
	double fRec105[2];
	double fRec103[2];
	double fRec102[2];
	double fRec100[2];
	double fRec99[2];
	double fRec97[2];
	double fRec96[2];
	double fRec94[2];
	double fRec93[2];
	double fRec91[2];
	double fRec90[2];
	double fRec88[2];
	double fRec119[3];
	double fRec120[3];
	double fRec121[3];
	double fRec122[3];
	double fRec123[3];
	double fRec124[3];
	double fRec125[3];
	double fRec126[3];
	double fRec127[3];
	double fRec128[3];
	int IOTA;
	double fVec0[1024];
	int iConst43;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fCheckbox0;
	double fRec129[2];
	double fRec132[2];
	double fRec130[2];
	double fRec138[2];
	double fRec136[2];
	double fRec135[2];
	double fRec133[2];
	double fRec147[2];
	double fRec145[2];
	double fRec144[2];
	double fRec142[2];
	double fRec141[2];
	double fRec139[2];
	double fRec159[2];
	double fRec157[2];
	double fRec156[2];
	double fRec154[2];
	double fRec153[2];
	double fRec151[2];
	double fRec150[2];
	double fRec148[2];
	double fRec174[2];
	double fRec172[2];
	double fRec171[2];
	double fRec169[2];
	double fRec168[2];
	double fRec166[2];
	double fRec165[2];
	double fRec163[2];
	double fRec162[2];
	double fRec160[2];
	double fRec192[2];
	double fRec190[2];
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
	double fVec1[1024];
	double fRec195[2];
	double fRec193[2];
	double fRec201[2];
	double fRec199[2];
	double fRec198[2];
	double fRec196[2];
	double fRec210[2];
	double fRec208[2];
	double fRec207[2];
	double fRec205[2];
	double fRec204[2];
	double fRec202[2];
	double fRec222[2];
	double fRec220[2];
	double fRec219[2];
	double fRec217[2];
	double fRec216[2];
	double fRec214[2];
	double fRec213[2];
	double fRec211[2];
	double fRec237[2];
	double fRec235[2];
	double fRec234[2];
	double fRec232[2];
	double fRec231[2];
	double fRec229[2];
	double fRec228[2];
	double fRec226[2];
	double fRec225[2];
	double fRec223[2];
	double fRec255[2];
	double fRec253[2];
	double fRec252[2];
	double fRec250[2];
	double fRec249[2];
	double fRec247[2];
	double fRec246[2];
	double fRec244[2];
	double fRec243[2];
	double fRec241[2];
	double fRec240[2];
	double fRec238[2];
	double fVec2[1024];
	double fRec261[2];
	double fRec259[2];
	double fRec258[2];
	double fRec256[2];
	double fRec264[2];
	double fRec262[2];
	double fRec273[2];
	double fRec271[2];
	double fRec270[2];
	double fRec268[2];
	double fRec267[2];
	double fRec265[2];
	double fRec285[2];
	double fRec283[2];
	double fRec282[2];
	double fRec280[2];
	double fRec279[2];
	double fRec277[2];
	double fRec276[2];
	double fRec274[2];
	double fRec300[2];
	double fRec298[2];
	double fRec297[2];
	double fRec295[2];
	double fRec294[2];
	double fRec292[2];
	double fRec291[2];
	double fRec289[2];
	double fRec288[2];
	double fRec286[2];
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
	double fRec303[2];
	double fRec301[2];
	double fVec3[1024];
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
	double fRec321[2];
	double fRec319[2];
	double fRec339[2];
	double fRec337[2];
	double fRec345[2];
	double fRec343[2];
	double fRec342[2];
	double fRec340[2];
	double fRec354[2];
	double fRec352[2];
	double fRec351[2];
	double fRec349[2];
	double fRec348[2];
	double fRec346[2];
	double fRec366[2];
	double fRec364[2];
	double fRec363[2];
	double fRec361[2];
	double fRec360[2];
	double fRec358[2];
	double fRec357[2];
	double fRec355[2];
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
	double fVec4[1024];
	double fRec384[2];
	double fRec382[2];
	double fRec390[2];
	double fRec388[2];
	double fRec387[2];
	double fRec385[2];
	double fRec399[2];
	double fRec397[2];
	double fRec396[2];
	double fRec394[2];
	double fRec393[2];
	double fRec391[2];
	double fRec411[2];
	double fRec409[2];
	double fRec408[2];
	double fRec406[2];
	double fRec405[2];
	double fRec403[2];
	double fRec402[2];
	double fRec400[2];
	double fRec426[2];
	double fRec424[2];
	double fRec423[2];
	double fRec421[2];
	double fRec420[2];
	double fRec418[2];
	double fRec417[2];
	double fRec415[2];
	double fRec414[2];
	double fRec412[2];
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
	double fRec429[2];
	double fRec427[2];
	double fVec5[1024];
	double fRec447[2];
	double fRec445[2];
	double fRec453[2];
	double fRec451[2];
	double fRec450[2];
	double fRec448[2];
	double fRec462[2];
	double fRec460[2];
	double fRec459[2];
	double fRec457[2];
	double fRec456[2];
	double fRec454[2];
	double fRec474[2];
	double fRec472[2];
	double fRec471[2];
	double fRec469[2];
	double fRec468[2];
	double fRec466[2];
	double fRec465[2];
	double fRec463[2];
	double fRec489[2];
	double fRec487[2];
	double fRec486[2];
	double fRec484[2];
	double fRec483[2];
	double fRec481[2];
	double fRec480[2];
	double fRec478[2];
	double fRec477[2];
	double fRec475[2];
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
	double fRec492[2];
	double fRec490[2];
	double fVec6[1024];
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
	double fRec510[2];
	double fRec508[2];
	double fRec540[2];
	double fRec538[2];
	double fRec537[2];
	double fRec535[2];
	double fRec534[2];
	double fRec532[2];
	double fRec531[2];
	double fRec529[2];
	double fRec528[2];
	double fRec526[2];
	double fRec543[2];
	double fRec541[2];
	double fRec549[2];
	double fRec547[2];
	double fRec546[2];
	double fRec544[2];
	double fRec558[2];
	double fRec556[2];
	double fRec555[2];
	double fRec553[2];
	double fRec552[2];
	double fRec550[2];
	double fRec570[2];
	double fRec568[2];
	double fRec567[2];
	double fRec565[2];
	double fRec564[2];
	double fRec562[2];
	double fRec561[2];
	double fRec559[2];
	double fVec7[1024];
	double fRec585[2];
	double fRec583[2];
	double fRec582[2];
	double fRec580[2];
	double fRec579[2];
	double fRec577[2];
	double fRec576[2];
	double fRec574[2];
	double fRec573[2];
	double fRec571[2];
	double fRec597[2];
	double fRec595[2];
	double fRec594[2];
	double fRec592[2];
	double fRec591[2];
	double fRec589[2];
	double fRec588[2];
	double fRec586[2];
	double fRec606[2];
	double fRec604[2];
	double fRec603[2];
	double fRec601[2];
	double fRec600[2];
	double fRec598[2];
	double fRec609[2];
	double fRec607[2];
	double fRec615[2];
	double fRec613[2];
	double fRec612[2];
	double fRec610[2];
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
	double fRec618[2];
	double fRec616[2];
	double fVec8[1024];
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
	double fRec636[2];
	double fRec634[2];
	double fRec666[2];
	double fRec664[2];
	double fRec663[2];
	double fRec661[2];
	double fRec660[2];
	double fRec658[2];
	double fRec657[2];
	double fRec655[2];
	double fRec654[2];
	double fRec652[2];
	double fRec678[2];
	double fRec676[2];
	double fRec675[2];
	double fRec673[2];
	double fRec672[2];
	double fRec670[2];
	double fRec669[2];
	double fRec667[2];
	double fRec687[2];
	double fRec685[2];
	double fRec684[2];
	double fRec682[2];
	double fRec681[2];
	double fRec679[2];
	double fRec693[2];
	double fRec691[2];
	double fRec690[2];
	double fRec688[2];
	double fRec696[2];
	double fRec694[2];
	double fVec9[1024];
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
	double fRec699[2];
	double fRec697[2];
	double fRec729[2];
	double fRec727[2];
	double fRec726[2];
	double fRec724[2];
	double fRec723[2];
	double fRec721[2];
	double fRec720[2];
	double fRec718[2];
	double fRec717[2];
	double fRec715[2];
	double fRec741[2];
	double fRec739[2];
	double fRec738[2];
	double fRec736[2];
	double fRec735[2];
	double fRec733[2];
	double fRec732[2];
	double fRec730[2];
	double fRec750[2];
	double fRec748[2];
	double fRec747[2];
	double fRec745[2];
	double fRec744[2];
	double fRec742[2];
	double fRec756[2];
	double fRec754[2];
	double fRec753[2];
	double fRec751[2];
	double fRec759[2];
	double fRec757[2];
	double fVec10[1024];
	double fRec777[2];
	double fRec775[2];
	double fRec774[2];
	double fRec772[2];
	double fRec771[2];
	double fRec769[2];
	double fRec768[2];
	double fRec766[2];
	double fRec765[2];
	double fRec763[2];
	double fRec762[2];
	double fRec760[2];
	double fRec780[2];
	double fRec778[2];
	double fRec786[2];
	double fRec784[2];
	double fRec783[2];
	double fRec781[2];
	double fRec795[2];
	double fRec793[2];
	double fRec792[2];
	double fRec790[2];
	double fRec789[2];
	double fRec787[2];
	double fRec807[2];
	double fRec805[2];
	double fRec804[2];
	double fRec802[2];
	double fRec801[2];
	double fRec799[2];
	double fRec798[2];
	double fRec796[2];
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
	double fVec11[1024];
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
	double fRec825[2];
	double fRec823[2];
	double fRec855[2];
	double fRec853[2];
	double fRec852[2];
	double fRec850[2];
	double fRec849[2];
	double fRec847[2];
	double fRec846[2];
	double fRec844[2];
	double fRec843[2];
	double fRec841[2];
	double fRec867[2];
	double fRec865[2];
	double fRec864[2];
	double fRec862[2];
	double fRec861[2];
	double fRec859[2];
	double fRec858[2];
	double fRec856[2];
	double fRec876[2];
	double fRec874[2];
	double fRec873[2];
	double fRec871[2];
	double fRec870[2];
	double fRec868[2];
	double fRec879[2];
	double fRec877[2];
	double fRec885[2];
	double fRec883[2];
	double fRec882[2];
	double fRec880[2];
	double fVec12[1024];
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
	double fRec888[2];
	double fRec886[2];
	double fRec918[2];
	double fRec916[2];
	double fRec915[2];
	double fRec913[2];
	double fRec912[2];
	double fRec910[2];
	double fRec909[2];
	double fRec907[2];
	double fRec906[2];
	double fRec904[2];
	double fRec930[2];
	double fRec928[2];
	double fRec927[2];
	double fRec925[2];
	double fRec924[2];
	double fRec922[2];
	double fRec921[2];
	double fRec919[2];
	double fRec939[2];
	double fRec937[2];
	double fRec936[2];
	double fRec934[2];
	double fRec933[2];
	double fRec931[2];
	double fRec942[2];
	double fRec940[2];
	double fRec948[2];
	double fRec946[2];
	double fRec945[2];
	double fRec943[2];
	double fVec13[1024];
	double fRec966[2];
	double fRec964[2];
	double fRec963[2];
	double fRec961[2];
	double fRec960[2];
	double fRec958[2];
	double fRec957[2];
	double fRec955[2];
	double fRec954[2];
	double fRec952[2];
	double fRec951[2];
	double fRec949[2];
	double fRec981[2];
	double fRec979[2];
	double fRec978[2];
	double fRec976[2];
	double fRec975[2];
	double fRec973[2];
	double fRec972[2];
	double fRec970[2];
	double fRec969[2];
	double fRec967[2];
	double fRec993[2];
	double fRec991[2];
	double fRec990[2];
	double fRec988[2];
	double fRec987[2];
	double fRec985[2];
	double fRec984[2];
	double fRec982[2];
	double fRec1002[2];
	double fRec1000[2];
	double fRec999[2];
	double fRec997[2];
	double fRec996[2];
	double fRec994[2];
	double fRec1005[2];
	double fRec1003[2];
	double fRec1011[2];
	double fRec1009[2];
	double fRec1008[2];
	double fRec1006[2];
	double fVec14[1024];
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
	double fRec1014[2];
	double fRec1012[2];
	double fRec1044[2];
	double fRec1042[2];
	double fRec1041[2];
	double fRec1039[2];
	double fRec1038[2];
	double fRec1036[2];
	double fRec1035[2];
	double fRec1033[2];
	double fRec1032[2];
	double fRec1030[2];
	double fRec1056[2];
	double fRec1054[2];
	double fRec1053[2];
	double fRec1051[2];
	double fRec1050[2];
	double fRec1048[2];
	double fRec1047[2];
	double fRec1045[2];
	double fRec1065[2];
	double fRec1063[2];
	double fRec1062[2];
	double fRec1060[2];
	double fRec1059[2];
	double fRec1057[2];
	double fRec1068[2];
	double fRec1066[2];
	double fRec1074[2];
	double fRec1072[2];
	double fRec1071[2];
	double fRec1069[2];
	double fVec15[1024];
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
	double fRec1077[2];
	double fRec1075[2];
	double fConst54;
	double fConst55;
	double fConst56;
	double fConst57;
	double fConst58;
	double fConst59;
	double fConst60;
	double fConst61;
	double fConst62;
	double fRec1107[2];
	double fRec1105[2];
	double fRec1104[2];
	double fRec1102[2];
	double fRec1101[2];
	double fRec1099[2];
	double fRec1098[2];
	double fRec1096[2];
	double fRec1095[2];
	double fRec1093[2];
	double fConst63;
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fConst68;
	double fConst69;
	double fRec1119[2];
	double fRec1117[2];
	double fRec1116[2];
	double fRec1114[2];
	double fRec1113[2];
	double fRec1111[2];
	double fRec1110[2];
	double fRec1108[2];
	double fConst70;
	double fConst71;
	double fConst72;
	double fConst73;
	double fConst74;
	double fConst75;
	double fRec1128[2];
	double fRec1126[2];
	double fRec1125[2];
	double fRec1123[2];
	double fRec1122[2];
	double fRec1120[2];
	double fConst76;
	double fConst77;
	double fConst78;
	double fRec1131[2];
	double fRec1129[2];
	double fConst79;
	double fConst80;
	double fConst81;
	double fConst82;
	double fRec1137[2];
	double fRec1135[2];
	double fRec1134[2];
	double fRec1132[2];
	double fVec16[512];
	int iConst83;
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
	double fRec1140[2];
	double fRec1138[2];
	double fRec1170[2];
	double fRec1168[2];
	double fRec1167[2];
	double fRec1165[2];
	double fRec1164[2];
	double fRec1162[2];
	double fRec1161[2];
	double fRec1159[2];
	double fRec1158[2];
	double fRec1156[2];
	double fRec1182[2];
	double fRec1180[2];
	double fRec1179[2];
	double fRec1177[2];
	double fRec1176[2];
	double fRec1174[2];
	double fRec1173[2];
	double fRec1171[2];
	double fRec1191[2];
	double fRec1189[2];
	double fRec1188[2];
	double fRec1186[2];
	double fRec1185[2];
	double fRec1183[2];
	double fRec1194[2];
	double fRec1192[2];
	double fRec1200[2];
	double fRec1198[2];
	double fRec1197[2];
	double fRec1195[2];
	double fVec17[512];
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
	double fRec1203[2];
	double fRec1201[2];
	double fRec1233[2];
	double fRec1231[2];
	double fRec1230[2];
	double fRec1228[2];
	double fRec1227[2];
	double fRec1225[2];
	double fRec1224[2];
	double fRec1222[2];
	double fRec1221[2];
	double fRec1219[2];
	double fRec1245[2];
	double fRec1243[2];
	double fRec1242[2];
	double fRec1240[2];
	double fRec1239[2];
	double fRec1237[2];
	double fRec1236[2];
	double fRec1234[2];
	double fRec1254[2];
	double fRec1252[2];
	double fRec1251[2];
	double fRec1249[2];
	double fRec1248[2];
	double fRec1246[2];
	double fRec1257[2];
	double fRec1255[2];
	double fRec1263[2];
	double fRec1261[2];
	double fRec1260[2];
	double fRec1258[2];
	double fVec18[512];
	double fRec1278[2];
	double fRec1276[2];
	double fRec1275[2];
	double fRec1273[2];
	double fRec1272[2];
	double fRec1270[2];
	double fRec1269[2];
	double fRec1267[2];
	double fRec1266[2];
	double fRec1264[2];
	double fRec1290[2];
	double fRec1288[2];
	double fRec1287[2];
	double fRec1285[2];
	double fRec1284[2];
	double fRec1282[2];
	double fRec1281[2];
	double fRec1279[2];
	double fRec1299[2];
	double fRec1297[2];
	double fRec1296[2];
	double fRec1294[2];
	double fRec1293[2];
	double fRec1291[2];
	double fRec1305[2];
	double fRec1303[2];
	double fRec1302[2];
	double fRec1300[2];
	double fRec1323[2];
	double fRec1321[2];
	double fRec1320[2];
	double fRec1318[2];
	double fRec1317[2];
	double fRec1315[2];
	double fRec1314[2];
	double fRec1312[2];
	double fRec1311[2];
	double fRec1309[2];
	double fRec1308[2];
	double fRec1306[2];
	double fRec1326[2];
	double fRec1324[2];
	double fVec19[512];
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
	double fRec1329[2];
	double fRec1327[2];
	double fRec1359[2];
	double fRec1357[2];
	double fRec1356[2];
	double fRec1354[2];
	double fRec1353[2];
	double fRec1351[2];
	double fRec1350[2];
	double fRec1348[2];
	double fRec1347[2];
	double fRec1345[2];
	double fRec1371[2];
	double fRec1369[2];
	double fRec1368[2];
	double fRec1366[2];
	double fRec1365[2];
	double fRec1363[2];
	double fRec1362[2];
	double fRec1360[2];
	double fRec1380[2];
	double fRec1378[2];
	double fRec1377[2];
	double fRec1375[2];
	double fRec1374[2];
	double fRec1372[2];
	double fRec1383[2];
	double fRec1381[2];
	double fRec1389[2];
	double fRec1387[2];
	double fRec1386[2];
	double fRec1384[2];
	double fVec20[512];
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
	double fRec1392[2];
	double fRec1390[2];
	double fRec1422[2];
	double fRec1420[2];
	double fRec1419[2];
	double fRec1417[2];
	double fRec1416[2];
	double fRec1414[2];
	double fRec1413[2];
	double fRec1411[2];
	double fRec1410[2];
	double fRec1408[2];
	double fRec1434[2];
	double fRec1432[2];
	double fRec1431[2];
	double fRec1429[2];
	double fRec1428[2];
	double fRec1426[2];
	double fRec1425[2];
	double fRec1423[2];
	double fRec1443[2];
	double fRec1441[2];
	double fRec1440[2];
	double fRec1438[2];
	double fRec1437[2];
	double fRec1435[2];
	double fRec1446[2];
	double fRec1444[2];
	double fRec1452[2];
	double fRec1450[2];
	double fRec1449[2];
	double fRec1447[2];
	double fVec21[512];
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
	double fRec1455[2];
	double fRec1453[2];
	double fRec1485[2];
	double fRec1483[2];
	double fRec1482[2];
	double fRec1480[2];
	double fRec1479[2];
	double fRec1477[2];
	double fRec1476[2];
	double fRec1474[2];
	double fRec1473[2];
	double fRec1471[2];
	double fRec1497[2];
	double fRec1495[2];
	double fRec1494[2];
	double fRec1492[2];
	double fRec1491[2];
	double fRec1489[2];
	double fRec1488[2];
	double fRec1486[2];
	double fRec1506[2];
	double fRec1504[2];
	double fRec1503[2];
	double fRec1501[2];
	double fRec1500[2];
	double fRec1498[2];
	double fRec1509[2];
	double fRec1507[2];
	double fRec1515[2];
	double fRec1513[2];
	double fRec1512[2];
	double fRec1510[2];
	double fVec22[512];
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
	double fRec1518[2];
	double fRec1516[2];
	double fRec1548[2];
	double fRec1546[2];
	double fRec1545[2];
	double fRec1543[2];
	double fRec1542[2];
	double fRec1540[2];
	double fRec1539[2];
	double fRec1537[2];
	double fRec1536[2];
	double fRec1534[2];
	double fRec1560[2];
	double fRec1558[2];
	double fRec1557[2];
	double fRec1555[2];
	double fRec1554[2];
	double fRec1552[2];
	double fRec1551[2];
	double fRec1549[2];
	double fRec1569[2];
	double fRec1567[2];
	double fRec1566[2];
	double fRec1564[2];
	double fRec1563[2];
	double fRec1561[2];
	double fRec1572[2];
	double fRec1570[2];
	double fRec1578[2];
	double fRec1576[2];
	double fRec1575[2];
	double fRec1573[2];
	double fVec23[512];
	double fConst84;
	double fConst85;
	double fConst86;
	double fConst87;
	double fConst88;
	double fConst89;
	double fConst90;
	double fConst91;
	double fConst92;
	double fConst93;
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
	double fRec1581[2];
	double fRec1579[2];
	double fConst94;
	double fConst95;
	double fConst96;
	double fConst97;
	double fConst98;
	double fConst99;
	double fConst100;
	double fRec1608[2];
	double fRec1606[2];
	double fRec1605[2];
	double fRec1603[2];
	double fRec1602[2];
	double fRec1600[2];
	double fRec1599[2];
	double fRec1597[2];
	double fConst101;
	double fConst102;
	double fConst103;
	double fConst104;
	double fConst105;
	double fConst106;
	double fRec1617[2];
	double fRec1615[2];
	double fRec1614[2];
	double fRec1612[2];
	double fRec1611[2];
	double fRec1609[2];
	double fConst107;
	double fConst108;
	double fConst109;
	double fRec1620[2];
	double fRec1618[2];
	double fConst110;
	double fConst111;
	double fConst112;
	double fConst113;
	double fRec1626[2];
	double fRec1624[2];
	double fRec1623[2];
	double fRec1621[2];
	double fConst114;
	double fConst115;
	double fConst116;
	double fConst117;
	double fConst118;
	double fConst119;
	double fConst120;
	double fConst121;
	double fConst122;
	double fRec1641[2];
	double fRec1639[2];
	double fRec1638[2];
	double fRec1636[2];
	double fRec1635[2];
	double fRec1633[2];
	double fRec1632[2];
	double fRec1630[2];
	double fRec1629[2];
	double fRec1627[2];
	double fVec24[256];
	int iConst123;
	double fRec1659[2];
	double fRec1657[2];
	double fRec1656[2];
	double fRec1654[2];
	double fRec1653[2];
	double fRec1651[2];
	double fRec1650[2];
	double fRec1648[2];
	double fRec1647[2];
	double fRec1645[2];
	double fRec1644[2];
	double fRec1642[2];
	double fRec1674[2];
	double fRec1672[2];
	double fRec1671[2];
	double fRec1669[2];
	double fRec1668[2];
	double fRec1666[2];
	double fRec1665[2];
	double fRec1663[2];
	double fRec1662[2];
	double fRec1660[2];
	double fRec1686[2];
	double fRec1684[2];
	double fRec1683[2];
	double fRec1681[2];
	double fRec1680[2];
	double fRec1678[2];
	double fRec1677[2];
	double fRec1675[2];
	double fRec1695[2];
	double fRec1693[2];
	double fRec1692[2];
	double fRec1690[2];
	double fRec1689[2];
	double fRec1687[2];
	double fRec1698[2];
	double fRec1696[2];
	double fRec1704[2];
	double fRec1702[2];
	double fRec1701[2];
	double fRec1699[2];
	double fVec25[256];
	double fRec1719[2];
	double fRec1717[2];
	double fRec1716[2];
	double fRec1714[2];
	double fRec1713[2];
	double fRec1711[2];
	double fRec1710[2];
	double fRec1708[2];
	double fRec1707[2];
	double fRec1705[2];
	double fRec1731[2];
	double fRec1729[2];
	double fRec1728[2];
	double fRec1726[2];
	double fRec1725[2];
	double fRec1723[2];
	double fRec1722[2];
	double fRec1720[2];
	double fRec1740[2];
	double fRec1738[2];
	double fRec1737[2];
	double fRec1735[2];
	double fRec1734[2];
	double fRec1732[2];
	double fRec1743[2];
	double fRec1741[2];
	double fRec1749[2];
	double fRec1747[2];
	double fRec1746[2];
	double fRec1744[2];
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
	double fRec1752[2];
	double fRec1750[2];
	double fVec26[256];
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
	double fRec1770[2];
	double fRec1768[2];
	double fRec1800[2];
	double fRec1798[2];
	double fRec1797[2];
	double fRec1795[2];
	double fRec1794[2];
	double fRec1792[2];
	double fRec1791[2];
	double fRec1789[2];
	double fRec1788[2];
	double fRec1786[2];
	double fRec1812[2];
	double fRec1810[2];
	double fRec1809[2];
	double fRec1807[2];
	double fRec1806[2];
	double fRec1804[2];
	double fRec1803[2];
	double fRec1801[2];
	double fRec1818[2];
	double fRec1816[2];
	double fRec1815[2];
	double fRec1813[2];
	double fRec1827[2];
	double fRec1825[2];
	double fRec1824[2];
	double fRec1822[2];
	double fRec1821[2];
	double fRec1819[2];
	double fRec1830[2];
	double fRec1828[2];
	double fVec27[256];
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
	double fRec1833[2];
	double fRec1831[2];
	double fConst134;
	double fConst135;
	double fConst136;
	double fConst137;
	double fConst138;
	double fConst139;
	double fConst140;
	double fConst141;
	double fConst142;
	double fRec1863[2];
	double fRec1861[2];
	double fRec1860[2];
	double fRec1858[2];
	double fRec1857[2];
	double fRec1855[2];
	double fRec1854[2];
	double fRec1852[2];
	double fRec1851[2];
	double fRec1849[2];
	double fConst143;
	double fConst144;
	double fConst145;
	double fConst146;
	double fConst147;
	double fConst148;
	double fConst149;
	double fRec1875[2];
	double fRec1873[2];
	double fRec1872[2];
	double fRec1870[2];
	double fRec1869[2];
	double fRec1867[2];
	double fRec1866[2];
	double fRec1864[2];
	double fConst150;
	double fConst151;
	double fConst152;
	double fConst153;
	double fConst154;
	double fConst155;
	double fRec1884[2];
	double fRec1882[2];
	double fRec1881[2];
	double fRec1879[2];
	double fRec1878[2];
	double fRec1876[2];
	double fConst156;
	double fConst157;
	double fConst158;
	double fRec1887[2];
	double fRec1885[2];
	double fConst159;
	double fConst160;
	double fConst161;
	double fConst162;
	double fRec1893[2];
	double fRec1891[2];
	double fRec1890[2];
	double fRec1888[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMHLS_Dome_7h7p_normal_4");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMHLS_Dome_7h7p_normal_4");
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
		fConst3 = ((37.225013306135352 / fConst2) + 1.0);
		fConst4 = (1.0 / fConst3);
		fConst5 = (0.0 - (74.450026612270705 / (fConst2 * fConst3)));
		fConst6 = ((((4157.1048469258621 / fConst2) + 111.67503991840606) / fConst2) + 1.0);
		fConst7 = (1.0 / fConst6);
		fConst8 = mydsp_faustpower2_f(fConst2);
		fConst9 = (0.0 - (16628.419387703449 / (fConst8 * fConst6)));
		fConst10 = (0.0 - (((16628.419387703449 / fConst2) + 223.35007983681211) / (fConst2 * fConst6)));
		fConst11 = ((86.443380725268696 / fConst2) + 1.0);
		fConst12 = (0.0 - (172.88676145053739 / (fConst2 * fConst11)));
		fConst13 = ((((8950.8463194903634 / fConst2) + 136.90669911154342) / fConst2) + 1.0);
		fConst14 = (1.0 / (fConst11 * fConst13));
		fConst15 = (0.0 - (35803.385277961454 / (fConst8 * fConst13)));
		fConst16 = (0.0 - (((35803.385277961454 / fConst2) + 273.81339822308684) / (fConst2 * fConst13)));
		fConst17 = ((((12665.494141837065 / fConst2) + 215.62295645471744) / fConst2) + 1.0);
		fConst18 = (0.0 - (50661.976567348262 / (fConst8 * fConst17)));
		fConst19 = (0.0 - (((50661.976567348262 / fConst2) + 431.24591290943488) / (fConst2 * fConst17)));
		fConst20 = ((((15918.663680972788 / fConst2) + 156.62717660663603) / fConst2) + 1.0);
		fConst21 = (1.0 / (fConst17 * fConst20));
		fConst22 = (0.0 - (63674.654723891152 / (fConst8 * fConst20)));
		fConst23 = (0.0 - (((63674.654723891152 / fConst2) + 313.25435321327205) / (fConst2 * fConst20)));
		fConst24 = ((135.74989273514609 / fConst2) + 1.0);
		fConst25 = (0.0 - (271.49978547029218 / (fConst2 * fConst24)));
		fConst26 = ((((19777.399306469804 / fConst2) + 249.5532431201479) / fConst2) + 1.0);
		fConst27 = (0.0 - (79109.597225879217 / (fConst8 * fConst26)));
		fConst28 = (0.0 - (((79109.597225879217 / fConst2) + 499.10648624029579) / (fConst2 * fConst26)));
		fConst29 = ((((25159.235463955636 / fConst2) + 173.07206373673586) / fConst2) + 1.0);
		fConst30 = (1.0 / ((fConst24 * fConst26) * fConst29));
		fConst31 = (0.0 - (100636.94185582254 / (fConst8 * fConst29)));
		fConst32 = (0.0 - (((100636.94185582254 / fConst2) + 346.14412747347171) / (fConst2 * fConst29)));
		fConst33 = ((((26052.757033862956 / fConst2) + 316.29047008051657) / fConst2) + 1.0);
		fConst34 = (0.0 - (104211.02813545182 / (fConst8 * fConst33)));
		fConst35 = (0.0 - (((104211.02813545182 / fConst2) + 632.58094016103314) / (fConst2 * fConst33)));
		fConst36 = ((((28895.790767614679 / fConst2) + 278.12358654414095) / fConst2) + 1.0);
		fConst37 = (0.0 - (115583.16307045872 / (fConst8 * fConst36)));
		fConst38 = (0.0 - (((115583.16307045872 / fConst2) + 556.2471730882819) / (fConst2 * fConst36)));
		fConst39 = ((((36740.52775644674 / fConst2) + 187.31122280418569) / fConst2) + 1.0);
		fConst40 = (1.0 / ((fConst33 * fConst36) * fConst39));
		fConst41 = (0.0 - (146962.11102578696 / (fConst8 * fConst39)));
		fConst42 = (0.0 - (((146962.11102578696 / fConst2) + 374.62244560837138) / (fConst2 * fConst39)));
		iConst43 = int(((0.0028145653948241961 * double(iConst0)) + 0.5));
		fConst44 = ((((23230.576625123042 / fConst2) + 298.668387355834) / fConst2) + 1.0);
		fConst45 = (0.0 - (92922.306500492166 / (fConst8 * fConst44)));
		fConst46 = (0.0 - (((92922.306500492166 / fConst2) + 597.336774711668) / (fConst2 * fConst44)));
		fConst47 = ((((25765.637037880293 / fConst2) + 262.62796681042397) / fConst2) + 1.0);
		fConst48 = (0.0 - (103062.54815152117 / (fConst8 * fConst47)));
		fConst49 = (0.0 - (((103062.54815152117 / fConst2) + 525.25593362084794) / (fConst2 * fConst47)));
		fConst50 = ((((32760.588224279891 / fConst2) + 176.87520219731587) / fConst2) + 1.0);
		fConst51 = (1.0 / ((fConst44 * fConst47) * fConst50));
		fConst52 = (0.0 - (131042.35289711956 / (fConst8 * fConst50)));
		fConst53 = (0.0 - (((131042.35289711956 / fConst2) + 353.75040439463174) / (fConst2 * fConst50)));
		fConst54 = ((128.18660497931657 / fConst2) + 1.0);
		fConst55 = (0.0 - (256.37320995863314 / (fConst2 * fConst54)));
		fConst56 = ((((17635.000757786547 / fConst2) + 235.6494163834252) / fConst2) + 1.0);
		fConst57 = (0.0 - (70540.003031146189 / (fConst8 * fConst56)));
		fConst58 = (0.0 - (((70540.003031146189 / fConst2) + 471.29883276685041) / (fConst2 * fConst56)));
		fConst59 = ((((22433.846310978071 / fConst2) + 163.42937603980999) / fConst2) + 1.0);
		fConst60 = (1.0 / ((fConst54 * fConst56) * fConst59));
		fConst61 = (0.0 - (89735.385243912286 / (fConst8 * fConst59)));
		fConst62 = (0.0 - (((89735.385243912286 / fConst2) + 326.85875207961999) / (fConst2 * fConst59)));
		fConst63 = ((((11293.496952148356 / fConst2) + 203.6095512610093) / fConst2) + 1.0);
		fConst64 = (0.0 - (45173.987808593425 / (fConst8 * fConst63)));
		fConst65 = (0.0 - (((45173.987808593425 / fConst2) + 407.2191025220186) / (fConst2 * fConst63)));
		fConst66 = ((((14194.264965114509 / fConst2) + 147.90071367402544) / fConst2) + 1.0);
		fConst67 = (1.0 / (fConst63 * fConst66));
		fConst68 = (0.0 - (56777.059860458037 / (fConst8 * fConst66)));
		fConst69 = (0.0 - (((56777.059860458037 / fConst2) + 295.80142734805088) / (fConst2 * fConst66)));
		fConst70 = ((81.627198923287324 / fConst2) + 1.0);
		fConst71 = (0.0 - (163.25439784657465 / (fConst2 * fConst70)));
		fConst72 = ((((7981.2405656089695 / fConst2) + 129.27896003773355) / fConst2) + 1.0);
		fConst73 = (1.0 / (fConst70 * fConst72));
		fConst74 = (0.0 - (31924.962262435878 / (fConst8 * fConst72)));
		fConst75 = (0.0 - (((31924.962262435878 / fConst2) + 258.55792007546711) / (fConst2 * fConst72)));
		fConst76 = ((35.15102649350348 / fConst2) + 1.0);
		fConst77 = (1.0 / fConst76);
		fConst78 = (0.0 - (70.302052987006959 / (fConst2 * fConst76)));
		fConst79 = ((((3706.7839906409508 / fConst2) + 105.45307948051044) / fConst2) + 1.0);
		fConst80 = (1.0 / fConst79);
		fConst81 = (0.0 - (14827.135962563803 / (fConst8 * fConst79)));
		fConst82 = (0.0 - (((14827.135962563803 / fConst2) + 210.90615896102088) / (fConst2 * fConst79)));
		iConst83 = int(((0.0020220583685382951 * double(iConst0)) + 0.5));
		fConst84 = ((((19584.938830006053 / fConst2) + 274.23341490900532) / fConst2) + 1.0);
		fConst85 = (0.0 - (78339.755320024211 / (fConst8 * fConst84)));
		fConst86 = (0.0 - (((78339.755320024211 / fConst2) + 548.46682981801064) / (fConst2 * fConst84)));
		fConst87 = ((((21722.165293017177 / fConst2) + 241.14157118083315) / fConst2) + 1.0);
		fConst88 = (0.0 - (86888.661172068707 / (fConst8 * fConst87)));
		fConst89 = (0.0 - (((86888.661172068707 / fConst2) + 482.28314236166631) / (fConst2 * fConst87)));
		fConst90 = ((((27619.379697775363 / fConst2) + 162.40450199873914) / fConst2) + 1.0);
		fConst91 = (1.0 / ((fConst84 * fConst87) * fConst90));
		fConst92 = (0.0 - (110477.51879110145 / (fConst8 * fConst90)));
		fConst93 = (0.0 - (((110477.51879110145 / fConst2) + 324.80900399747827) / (fConst2 * fConst90)));
		fConst94 = ((((9521.1776510740765 / fConst2) + 186.95163235964782) / fConst2) + 1.0);
		fConst95 = (0.0 - (38084.710604296306 / (fConst8 * fConst94)));
		fConst96 = (0.0 - (((38084.710604296306 / fConst2) + 373.90326471929563) / (fConst2 * fConst94)));
		fConst97 = ((((11966.720222434136 / fConst2) + 135.80050482538877) / fConst2) + 1.0);
		fConst98 = (1.0 / (fConst94 * fConst97));
		fConst99 = (0.0 - (47866.880889736545 / (fConst8 * fConst97)));
		fConst100 = (0.0 - (((47866.880889736545 / fConst2) + 271.60100965077754) / (fConst2 * fConst97)));
		fConst101 = ((74.949028614536147 / fConst2) + 1.0);
		fConst102 = (0.0 - (149.89805722907229 / (fConst2 * fConst101)));
		fConst103 = ((((6728.7226997184644 / fConst2) + 118.70225369648584) / fConst2) + 1.0);
		fConst104 = (1.0 / (fConst101 * fConst103));
		fConst105 = (0.0 - (26914.890798873857 / (fConst8 * fConst103)));
		fConst106 = (0.0 - (((26914.890798873857 / fConst2) + 237.40450739297168) / (fConst2 * fConst103)));
		fConst107 = ((32.275213718503664 / fConst2) + 1.0);
		fConst108 = (1.0 / fConst107);
		fConst109 = (0.0 - (64.550427437007329 / (fConst2 * fConst107)));
		fConst110 = ((((3125.0682617252614 / fConst2) + 96.825641155510993) / fConst2) + 1.0);
		fConst111 = (1.0 / fConst110);
		fConst112 = (0.0 - (12500.273046901046 / (fConst8 * fConst110)));
		fConst113 = (0.0 - (((12500.273046901046 / fConst2) + 193.65128231102199) / (fConst2 * fConst110)));
		fConst114 = ((117.6992675397825 / fConst2) + 1.0);
		fConst115 = (0.0 - (235.39853507956499 / (fConst2 * fConst114)));
		fConst116 = ((((14867.491956047414 / fConst2) + 216.37021831556928) / fConst2) + 1.0);
		fConst117 = (0.0 - (59469.967824189654 / (fConst8 * fConst116)));
		fConst118 = (0.0 - (((59469.967824189654 / fConst2) + 432.74043663113855) / (fConst2 * fConst116)));
		fConst119 = ((((18913.241578648733 / fConst2) + 150.05871992220281) / fConst2) + 1.0);
		fConst120 = (1.0 / ((fConst114 * fConst116) * fConst119));
		fConst121 = (0.0 - (75652.966314594931 / (fConst8 * fConst119)));
		fConst122 = (0.0 - (((75652.966314594931 / fConst2) + 300.11743984440562) / (fConst2 * fConst119)));
		iConst123 = int(((0.0007546298522354718 * double(iConst0)) + 0.5));
		fConst124 = ((((17807.789357525253 / fConst2) + 261.49552852783023) / fConst2) + 1.0);
		fConst125 = (0.0 - (71231.157430101011 / (fConst8 * fConst124)));
		fConst126 = (0.0 - (((71231.157430101011 / fConst2) + 522.99105705566046) / (fConst2 * fConst124)));
		fConst127 = ((((19751.082568342958 / fConst2) + 229.9407700804322) / fConst2) + 1.0);
		fConst128 = (0.0 - (79004.33027337183 / (fConst8 * fConst127)));
		fConst129 = (0.0 - (((79004.33027337183 / fConst2) + 459.8815401608644) / (fConst2 * fConst127)));
		fConst130 = ((((25113.18008764703 / fConst2) + 154.86096433416358) / fConst2) + 1.0);
		fConst131 = (1.0 / ((fConst124 * fConst127) * fConst130));
		fConst132 = (0.0 - (100452.72035058812 / (fConst8 * fConst130)));
		fConst133 = (0.0 - (((100452.72035058812 / fConst2) + 309.72192866832717) / (fConst2 * fConst130)));
		fConst134 = ((112.2322463251477 / fConst2) + 1.0);
		fConst135 = (0.0 - (224.4644926502954 / (fConst2 * fConst134)));
		fConst136 = ((((13518.406533001747 / fConst2) + 206.32002345478514) / fConst2) + 1.0);
		fConst137 = (0.0 - (54073.62613200699 / (fConst8 * fConst136)));
		fConst138 = (0.0 - (((54073.62613200699 / fConst2) + 412.64004690957029) / (fConst2 * fConst136)));
		fConst139 = ((((17197.042330535627 / fConst2) + 143.0886323217992) / fConst2) + 1.0);
		fConst140 = (1.0 / ((fConst134 * fConst136) * fConst139));
		fConst141 = (0.0 - (68788.169322142508 / (fConst8 * fConst139)));
		fConst142 = (0.0 - (((68788.169322142508 / fConst2) + 286.17726464359839) / (fConst2 * fConst139)));
		fConst143 = ((((8657.2200974217594 / fConst2) + 178.26790338167996) / fConst2) + 1.0);
		fConst144 = (0.0 - (34628.880389687038 / (fConst8 * fConst143)));
		fConst145 = (0.0 - (((34628.880389687038 / fConst2) + 356.53580676335991) / (fConst2 * fConst143)));
		fConst146 = ((((10880.852622069639 / fConst2) + 129.49269801947491) / fConst2) + 1.0);
		fConst147 = (1.0 / (fConst143 * fConst146));
		fConst148 = (0.0 - (43523.410488278554 / (fConst8 * fConst146)));
		fConst149 = (0.0 - (((43523.410488278554 / fConst2) + 258.98539603894983) / (fConst2 * fConst146)));
		fConst150 = ((71.467716130467849 / fConst2) + 1.0);
		fConst151 = (0.0 - (142.9354322609357 / (fConst2 * fConst150)));
		fConst152 = ((((6118.1542368773398 / fConst2) + 113.18864471022512) / fConst2) + 1.0);
		fConst153 = (1.0 / (fConst150 * fConst152));
		fConst154 = (0.0 - (24472.616947509359 / (fConst8 * fConst152)));
		fConst155 = (0.0 - (((24472.616947509359 / fConst2) + 226.37728942045024) / (fConst2 * fConst152)));
		fConst156 = ((30.776060140115494 / fConst2) + 1.0);
		fConst157 = (1.0 / fConst156);
		fConst158 = (0.0 - (61.552120280230987 / (fConst2 * fConst156)));
		fConst159 = ((((2841.4976332440169 / fConst2) + 92.328180420346484) / fConst2) + 1.0);
		fConst160 = (1.0 / fConst159);
		fConst161 = (0.0 - (11365.990532976068 / (fConst8 * fConst159)));
		fConst162 = (0.0 - (((11365.990532976068 / fConst2) + 184.65636084069297) / (fConst2 * fConst159)));
		
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(400.0);
		fHslider1 = FAUSTFLOAT(0.0);
		fHslider2 = FAUSTFLOAT(-10.0);
		fCheckbox0 = FAUSTFLOAT(0.0);
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0;
			
		}
		for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0;
			
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0;
			
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
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
			fRec11[l8] = 0.0;
			
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec12[l9] = 0.0;
			
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec13[l10] = 0.0;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec10[l11] = 0.0;
			
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec8[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec20[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec21[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec22[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec23[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec24[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec19[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec17[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec16[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec14[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec34[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec35[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 3); l24 = (l24 + 1)) {
			fRec36[l24] = 0.0;
			
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec37[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec38[l26] = 0.0;
			
		}
		for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) {
			fRec39[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 3); l28 = (l28 + 1)) {
			fRec40[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec33[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec31[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec30[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec28[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec27[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec25[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 3); l35 = (l35 + 1)) {
			fRec53[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 3); l36 = (l36 + 1)) {
			fRec54[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 3); l37 = (l37 + 1)) {
			fRec55[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec56[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 3); l39 = (l39 + 1)) {
			fRec57[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 3); l40 = (l40 + 1)) {
			fRec58[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 3); l41 = (l41 + 1)) {
			fRec59[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec60[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) {
			fRec61[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec52[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec50[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec49[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec47[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec46[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec44[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec43[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec41[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 3); l52 = (l52 + 1)) {
			fRec77[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 3); l53 = (l53 + 1)) {
			fRec78[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) {
			fRec79[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec80[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec81[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 3); l57 = (l57 + 1)) {
			fRec82[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 3); l58 = (l58 + 1)) {
			fRec83[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 3); l59 = (l59 + 1)) {
			fRec84[l59] = 0.0;
			
		}
		for (int l60 = 0; (l60 < 3); l60 = (l60 + 1)) {
			fRec85[l60] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 3); l61 = (l61 + 1)) {
			fRec86[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 3); l62 = (l62 + 1)) {
			fRec87[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec76[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec74[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec73[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec71[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec70[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec68[l68] = 0.0;
			
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec67[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec65[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec64[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec62[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 3); l73 = (l73 + 1)) {
			fRec106[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 3); l74 = (l74 + 1)) {
			fRec107[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 3); l75 = (l75 + 1)) {
			fRec108[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 3); l76 = (l76 + 1)) {
			fRec109[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 3); l77 = (l77 + 1)) {
			fRec110[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 3); l78 = (l78 + 1)) {
			fRec111[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 3); l79 = (l79 + 1)) {
			fRec112[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 3); l80 = (l80 + 1)) {
			fRec113[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 3); l81 = (l81 + 1)) {
			fRec114[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 3); l82 = (l82 + 1)) {
			fRec115[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 3); l83 = (l83 + 1)) {
			fRec116[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 3); l84 = (l84 + 1)) {
			fRec117[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 3); l85 = (l85 + 1)) {
			fRec118[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec105[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 2); l87 = (l87 + 1)) {
			fRec103[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			fRec102[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec100[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec99[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec97[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec96[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec94[l93] = 0.0;
			
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec93[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec91[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fRec90[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec88[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 3); l98 = (l98 + 1)) {
			fRec119[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 3); l99 = (l99 + 1)) {
			fRec120[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 3); l100 = (l100 + 1)) {
			fRec121[l100] = 0.0;
			
		}
		for (int l101 = 0; (l101 < 3); l101 = (l101 + 1)) {
			fRec122[l101] = 0.0;
			
		}
		for (int l102 = 0; (l102 < 3); l102 = (l102 + 1)) {
			fRec123[l102] = 0.0;
			
		}
		for (int l103 = 0; (l103 < 3); l103 = (l103 + 1)) {
			fRec124[l103] = 0.0;
			
		}
		for (int l104 = 0; (l104 < 3); l104 = (l104 + 1)) {
			fRec125[l104] = 0.0;
			
		}
		for (int l105 = 0; (l105 < 3); l105 = (l105 + 1)) {
			fRec126[l105] = 0.0;
			
		}
		for (int l106 = 0; (l106 < 3); l106 = (l106 + 1)) {
			fRec127[l106] = 0.0;
			
		}
		for (int l107 = 0; (l107 < 3); l107 = (l107 + 1)) {
			fRec128[l107] = 0.0;
			
		}
		IOTA = 0;
		for (int l108 = 0; (l108 < 1024); l108 = (l108 + 1)) {
			fVec0[l108] = 0.0;
			
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec129[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec132[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec130[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec138[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec136[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec135[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec133[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec147[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec145[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec144[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec142[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec141[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec139[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec159[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec157[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec156[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fRec154[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec153[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec151[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec150[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec148[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec174[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 2); l131 = (l131 + 1)) {
			fRec172[l131] = 0.0;
			
		}
		for (int l132 = 0; (l132 < 2); l132 = (l132 + 1)) {
			fRec171[l132] = 0.0;
			
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec169[l133] = 0.0;
			
		}
		for (int l134 = 0; (l134 < 2); l134 = (l134 + 1)) {
			fRec168[l134] = 0.0;
			
		}
		for (int l135 = 0; (l135 < 2); l135 = (l135 + 1)) {
			fRec166[l135] = 0.0;
			
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec165[l136] = 0.0;
			
		}
		for (int l137 = 0; (l137 < 2); l137 = (l137 + 1)) {
			fRec163[l137] = 0.0;
			
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec162[l138] = 0.0;
			
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fRec160[l139] = 0.0;
			
		}
		for (int l140 = 0; (l140 < 2); l140 = (l140 + 1)) {
			fRec192[l140] = 0.0;
			
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fRec190[l141] = 0.0;
			
		}
		for (int l142 = 0; (l142 < 2); l142 = (l142 + 1)) {
			fRec189[l142] = 0.0;
			
		}
		for (int l143 = 0; (l143 < 2); l143 = (l143 + 1)) {
			fRec187[l143] = 0.0;
			
		}
		for (int l144 = 0; (l144 < 2); l144 = (l144 + 1)) {
			fRec186[l144] = 0.0;
			
		}
		for (int l145 = 0; (l145 < 2); l145 = (l145 + 1)) {
			fRec184[l145] = 0.0;
			
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fRec183[l146] = 0.0;
			
		}
		for (int l147 = 0; (l147 < 2); l147 = (l147 + 1)) {
			fRec181[l147] = 0.0;
			
		}
		for (int l148 = 0; (l148 < 2); l148 = (l148 + 1)) {
			fRec180[l148] = 0.0;
			
		}
		for (int l149 = 0; (l149 < 2); l149 = (l149 + 1)) {
			fRec178[l149] = 0.0;
			
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec177[l150] = 0.0;
			
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec175[l151] = 0.0;
			
		}
		for (int l152 = 0; (l152 < 1024); l152 = (l152 + 1)) {
			fVec1[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec195[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec193[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec201[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec199[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec198[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec196[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec210[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec208[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec207[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 2); l162 = (l162 + 1)) {
			fRec205[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			fRec204[l163] = 0.0;
			
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			fRec202[l164] = 0.0;
			
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec222[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec220[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fRec219[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec217[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec216[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec214[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fRec213[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec211[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fRec237[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec235[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec234[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec232[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec231[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 2); l178 = (l178 + 1)) {
			fRec229[l178] = 0.0;
			
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec228[l179] = 0.0;
			
		}
		for (int l180 = 0; (l180 < 2); l180 = (l180 + 1)) {
			fRec226[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec225[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec223[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fRec255[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec253[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec252[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fRec250[l186] = 0.0;
			
		}
		for (int l187 = 0; (l187 < 2); l187 = (l187 + 1)) {
			fRec249[l187] = 0.0;
			
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec247[l188] = 0.0;
			
		}
		for (int l189 = 0; (l189 < 2); l189 = (l189 + 1)) {
			fRec246[l189] = 0.0;
			
		}
		for (int l190 = 0; (l190 < 2); l190 = (l190 + 1)) {
			fRec244[l190] = 0.0;
			
		}
		for (int l191 = 0; (l191 < 2); l191 = (l191 + 1)) {
			fRec243[l191] = 0.0;
			
		}
		for (int l192 = 0; (l192 < 2); l192 = (l192 + 1)) {
			fRec241[l192] = 0.0;
			
		}
		for (int l193 = 0; (l193 < 2); l193 = (l193 + 1)) {
			fRec240[l193] = 0.0;
			
		}
		for (int l194 = 0; (l194 < 2); l194 = (l194 + 1)) {
			fRec238[l194] = 0.0;
			
		}
		for (int l195 = 0; (l195 < 1024); l195 = (l195 + 1)) {
			fVec2[l195] = 0.0;
			
		}
		for (int l196 = 0; (l196 < 2); l196 = (l196 + 1)) {
			fRec261[l196] = 0.0;
			
		}
		for (int l197 = 0; (l197 < 2); l197 = (l197 + 1)) {
			fRec259[l197] = 0.0;
			
		}
		for (int l198 = 0; (l198 < 2); l198 = (l198 + 1)) {
			fRec258[l198] = 0.0;
			
		}
		for (int l199 = 0; (l199 < 2); l199 = (l199 + 1)) {
			fRec256[l199] = 0.0;
			
		}
		for (int l200 = 0; (l200 < 2); l200 = (l200 + 1)) {
			fRec264[l200] = 0.0;
			
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fRec262[l201] = 0.0;
			
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec273[l202] = 0.0;
			
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fRec271[l203] = 0.0;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec270[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec268[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec267[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec265[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec285[l208] = 0.0;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec283[l209] = 0.0;
			
		}
		for (int l210 = 0; (l210 < 2); l210 = (l210 + 1)) {
			fRec282[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 2); l211 = (l211 + 1)) {
			fRec280[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec279[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec277[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fRec276[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 2); l215 = (l215 + 1)) {
			fRec274[l215] = 0.0;
			
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fRec300[l216] = 0.0;
			
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec298[l217] = 0.0;
			
		}
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fRec297[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec295[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fRec294[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec292[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec291[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec289[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 2); l224 = (l224 + 1)) {
			fRec288[l224] = 0.0;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec286[l225] = 0.0;
			
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
			fRec303[l236] = 0.0;
			
		}
		for (int l237 = 0; (l237 < 2); l237 = (l237 + 1)) {
			fRec301[l237] = 0.0;
			
		}
		for (int l238 = 0; (l238 < 1024); l238 = (l238 + 1)) {
			fVec3[l238] = 0.0;
			
		}
		for (int l239 = 0; (l239 < 2); l239 = (l239 + 1)) {
			fRec336[l239] = 0.0;
			
		}
		for (int l240 = 0; (l240 < 2); l240 = (l240 + 1)) {
			fRec334[l240] = 0.0;
			
		}
		for (int l241 = 0; (l241 < 2); l241 = (l241 + 1)) {
			fRec333[l241] = 0.0;
			
		}
		for (int l242 = 0; (l242 < 2); l242 = (l242 + 1)) {
			fRec331[l242] = 0.0;
			
		}
		for (int l243 = 0; (l243 < 2); l243 = (l243 + 1)) {
			fRec330[l243] = 0.0;
			
		}
		for (int l244 = 0; (l244 < 2); l244 = (l244 + 1)) {
			fRec328[l244] = 0.0;
			
		}
		for (int l245 = 0; (l245 < 2); l245 = (l245 + 1)) {
			fRec327[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fRec325[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 2); l247 = (l247 + 1)) {
			fRec324[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 2); l248 = (l248 + 1)) {
			fRec322[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fRec321[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 2); l250 = (l250 + 1)) {
			fRec319[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 2); l251 = (l251 + 1)) {
			fRec339[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 2); l252 = (l252 + 1)) {
			fRec337[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec345[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec343[l254] = 0.0;
			
		}
		for (int l255 = 0; (l255 < 2); l255 = (l255 + 1)) {
			fRec342[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec340[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fRec354[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec352[l258] = 0.0;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec351[l259] = 0.0;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec349[l260] = 0.0;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec348[l261] = 0.0;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec346[l262] = 0.0;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec366[l263] = 0.0;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec364[l264] = 0.0;
			
		}
		for (int l265 = 0; (l265 < 2); l265 = (l265 + 1)) {
			fRec363[l265] = 0.0;
			
		}
		for (int l266 = 0; (l266 < 2); l266 = (l266 + 1)) {
			fRec361[l266] = 0.0;
			
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec360[l267] = 0.0;
			
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec358[l268] = 0.0;
			
		}
		for (int l269 = 0; (l269 < 2); l269 = (l269 + 1)) {
			fRec357[l269] = 0.0;
			
		}
		for (int l270 = 0; (l270 < 2); l270 = (l270 + 1)) {
			fRec355[l270] = 0.0;
			
		}
		for (int l271 = 0; (l271 < 2); l271 = (l271 + 1)) {
			fRec381[l271] = 0.0;
			
		}
		for (int l272 = 0; (l272 < 2); l272 = (l272 + 1)) {
			fRec379[l272] = 0.0;
			
		}
		for (int l273 = 0; (l273 < 2); l273 = (l273 + 1)) {
			fRec378[l273] = 0.0;
			
		}
		for (int l274 = 0; (l274 < 2); l274 = (l274 + 1)) {
			fRec376[l274] = 0.0;
			
		}
		for (int l275 = 0; (l275 < 2); l275 = (l275 + 1)) {
			fRec375[l275] = 0.0;
			
		}
		for (int l276 = 0; (l276 < 2); l276 = (l276 + 1)) {
			fRec373[l276] = 0.0;
			
		}
		for (int l277 = 0; (l277 < 2); l277 = (l277 + 1)) {
			fRec372[l277] = 0.0;
			
		}
		for (int l278 = 0; (l278 < 2); l278 = (l278 + 1)) {
			fRec370[l278] = 0.0;
			
		}
		for (int l279 = 0; (l279 < 2); l279 = (l279 + 1)) {
			fRec369[l279] = 0.0;
			
		}
		for (int l280 = 0; (l280 < 2); l280 = (l280 + 1)) {
			fRec367[l280] = 0.0;
			
		}
		for (int l281 = 0; (l281 < 1024); l281 = (l281 + 1)) {
			fVec4[l281] = 0.0;
			
		}
		for (int l282 = 0; (l282 < 2); l282 = (l282 + 1)) {
			fRec384[l282] = 0.0;
			
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec382[l283] = 0.0;
			
		}
		for (int l284 = 0; (l284 < 2); l284 = (l284 + 1)) {
			fRec390[l284] = 0.0;
			
		}
		for (int l285 = 0; (l285 < 2); l285 = (l285 + 1)) {
			fRec388[l285] = 0.0;
			
		}
		for (int l286 = 0; (l286 < 2); l286 = (l286 + 1)) {
			fRec387[l286] = 0.0;
			
		}
		for (int l287 = 0; (l287 < 2); l287 = (l287 + 1)) {
			fRec385[l287] = 0.0;
			
		}
		for (int l288 = 0; (l288 < 2); l288 = (l288 + 1)) {
			fRec399[l288] = 0.0;
			
		}
		for (int l289 = 0; (l289 < 2); l289 = (l289 + 1)) {
			fRec397[l289] = 0.0;
			
		}
		for (int l290 = 0; (l290 < 2); l290 = (l290 + 1)) {
			fRec396[l290] = 0.0;
			
		}
		for (int l291 = 0; (l291 < 2); l291 = (l291 + 1)) {
			fRec394[l291] = 0.0;
			
		}
		for (int l292 = 0; (l292 < 2); l292 = (l292 + 1)) {
			fRec393[l292] = 0.0;
			
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec391[l293] = 0.0;
			
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec411[l294] = 0.0;
			
		}
		for (int l295 = 0; (l295 < 2); l295 = (l295 + 1)) {
			fRec409[l295] = 0.0;
			
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec408[l296] = 0.0;
			
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec406[l297] = 0.0;
			
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec405[l298] = 0.0;
			
		}
		for (int l299 = 0; (l299 < 2); l299 = (l299 + 1)) {
			fRec403[l299] = 0.0;
			
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec402[l300] = 0.0;
			
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec400[l301] = 0.0;
			
		}
		for (int l302 = 0; (l302 < 2); l302 = (l302 + 1)) {
			fRec426[l302] = 0.0;
			
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec424[l303] = 0.0;
			
		}
		for (int l304 = 0; (l304 < 2); l304 = (l304 + 1)) {
			fRec423[l304] = 0.0;
			
		}
		for (int l305 = 0; (l305 < 2); l305 = (l305 + 1)) {
			fRec421[l305] = 0.0;
			
		}
		for (int l306 = 0; (l306 < 2); l306 = (l306 + 1)) {
			fRec420[l306] = 0.0;
			
		}
		for (int l307 = 0; (l307 < 2); l307 = (l307 + 1)) {
			fRec418[l307] = 0.0;
			
		}
		for (int l308 = 0; (l308 < 2); l308 = (l308 + 1)) {
			fRec417[l308] = 0.0;
			
		}
		for (int l309 = 0; (l309 < 2); l309 = (l309 + 1)) {
			fRec415[l309] = 0.0;
			
		}
		for (int l310 = 0; (l310 < 2); l310 = (l310 + 1)) {
			fRec414[l310] = 0.0;
			
		}
		for (int l311 = 0; (l311 < 2); l311 = (l311 + 1)) {
			fRec412[l311] = 0.0;
			
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
			fRec429[l322] = 0.0;
			
		}
		for (int l323 = 0; (l323 < 2); l323 = (l323 + 1)) {
			fRec427[l323] = 0.0;
			
		}
		for (int l324 = 0; (l324 < 1024); l324 = (l324 + 1)) {
			fVec5[l324] = 0.0;
			
		}
		for (int l325 = 0; (l325 < 2); l325 = (l325 + 1)) {
			fRec447[l325] = 0.0;
			
		}
		for (int l326 = 0; (l326 < 2); l326 = (l326 + 1)) {
			fRec445[l326] = 0.0;
			
		}
		for (int l327 = 0; (l327 < 2); l327 = (l327 + 1)) {
			fRec453[l327] = 0.0;
			
		}
		for (int l328 = 0; (l328 < 2); l328 = (l328 + 1)) {
			fRec451[l328] = 0.0;
			
		}
		for (int l329 = 0; (l329 < 2); l329 = (l329 + 1)) {
			fRec450[l329] = 0.0;
			
		}
		for (int l330 = 0; (l330 < 2); l330 = (l330 + 1)) {
			fRec448[l330] = 0.0;
			
		}
		for (int l331 = 0; (l331 < 2); l331 = (l331 + 1)) {
			fRec462[l331] = 0.0;
			
		}
		for (int l332 = 0; (l332 < 2); l332 = (l332 + 1)) {
			fRec460[l332] = 0.0;
			
		}
		for (int l333 = 0; (l333 < 2); l333 = (l333 + 1)) {
			fRec459[l333] = 0.0;
			
		}
		for (int l334 = 0; (l334 < 2); l334 = (l334 + 1)) {
			fRec457[l334] = 0.0;
			
		}
		for (int l335 = 0; (l335 < 2); l335 = (l335 + 1)) {
			fRec456[l335] = 0.0;
			
		}
		for (int l336 = 0; (l336 < 2); l336 = (l336 + 1)) {
			fRec454[l336] = 0.0;
			
		}
		for (int l337 = 0; (l337 < 2); l337 = (l337 + 1)) {
			fRec474[l337] = 0.0;
			
		}
		for (int l338 = 0; (l338 < 2); l338 = (l338 + 1)) {
			fRec472[l338] = 0.0;
			
		}
		for (int l339 = 0; (l339 < 2); l339 = (l339 + 1)) {
			fRec471[l339] = 0.0;
			
		}
		for (int l340 = 0; (l340 < 2); l340 = (l340 + 1)) {
			fRec469[l340] = 0.0;
			
		}
		for (int l341 = 0; (l341 < 2); l341 = (l341 + 1)) {
			fRec468[l341] = 0.0;
			
		}
		for (int l342 = 0; (l342 < 2); l342 = (l342 + 1)) {
			fRec466[l342] = 0.0;
			
		}
		for (int l343 = 0; (l343 < 2); l343 = (l343 + 1)) {
			fRec465[l343] = 0.0;
			
		}
		for (int l344 = 0; (l344 < 2); l344 = (l344 + 1)) {
			fRec463[l344] = 0.0;
			
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
		for (int l349 = 0; (l349 < 2); l349 = (l349 + 1)) {
			fRec483[l349] = 0.0;
			
		}
		for (int l350 = 0; (l350 < 2); l350 = (l350 + 1)) {
			fRec481[l350] = 0.0;
			
		}
		for (int l351 = 0; (l351 < 2); l351 = (l351 + 1)) {
			fRec480[l351] = 0.0;
			
		}
		for (int l352 = 0; (l352 < 2); l352 = (l352 + 1)) {
			fRec478[l352] = 0.0;
			
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec477[l353] = 0.0;
			
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec475[l354] = 0.0;
			
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
			fRec492[l365] = 0.0;
			
		}
		for (int l366 = 0; (l366 < 2); l366 = (l366 + 1)) {
			fRec490[l366] = 0.0;
			
		}
		for (int l367 = 0; (l367 < 1024); l367 = (l367 + 1)) {
			fVec6[l367] = 0.0;
			
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec525[l368] = 0.0;
			
		}
		for (int l369 = 0; (l369 < 2); l369 = (l369 + 1)) {
			fRec523[l369] = 0.0;
			
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec522[l370] = 0.0;
			
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			fRec520[l371] = 0.0;
			
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			fRec519[l372] = 0.0;
			
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fRec517[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec516[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 2); l375 = (l375 + 1)) {
			fRec514[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec513[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec511[l377] = 0.0;
			
		}
		for (int l378 = 0; (l378 < 2); l378 = (l378 + 1)) {
			fRec510[l378] = 0.0;
			
		}
		for (int l379 = 0; (l379 < 2); l379 = (l379 + 1)) {
			fRec508[l379] = 0.0;
			
		}
		for (int l380 = 0; (l380 < 2); l380 = (l380 + 1)) {
			fRec540[l380] = 0.0;
			
		}
		for (int l381 = 0; (l381 < 2); l381 = (l381 + 1)) {
			fRec538[l381] = 0.0;
			
		}
		for (int l382 = 0; (l382 < 2); l382 = (l382 + 1)) {
			fRec537[l382] = 0.0;
			
		}
		for (int l383 = 0; (l383 < 2); l383 = (l383 + 1)) {
			fRec535[l383] = 0.0;
			
		}
		for (int l384 = 0; (l384 < 2); l384 = (l384 + 1)) {
			fRec534[l384] = 0.0;
			
		}
		for (int l385 = 0; (l385 < 2); l385 = (l385 + 1)) {
			fRec532[l385] = 0.0;
			
		}
		for (int l386 = 0; (l386 < 2); l386 = (l386 + 1)) {
			fRec531[l386] = 0.0;
			
		}
		for (int l387 = 0; (l387 < 2); l387 = (l387 + 1)) {
			fRec529[l387] = 0.0;
			
		}
		for (int l388 = 0; (l388 < 2); l388 = (l388 + 1)) {
			fRec528[l388] = 0.0;
			
		}
		for (int l389 = 0; (l389 < 2); l389 = (l389 + 1)) {
			fRec526[l389] = 0.0;
			
		}
		for (int l390 = 0; (l390 < 2); l390 = (l390 + 1)) {
			fRec543[l390] = 0.0;
			
		}
		for (int l391 = 0; (l391 < 2); l391 = (l391 + 1)) {
			fRec541[l391] = 0.0;
			
		}
		for (int l392 = 0; (l392 < 2); l392 = (l392 + 1)) {
			fRec549[l392] = 0.0;
			
		}
		for (int l393 = 0; (l393 < 2); l393 = (l393 + 1)) {
			fRec547[l393] = 0.0;
			
		}
		for (int l394 = 0; (l394 < 2); l394 = (l394 + 1)) {
			fRec546[l394] = 0.0;
			
		}
		for (int l395 = 0; (l395 < 2); l395 = (l395 + 1)) {
			fRec544[l395] = 0.0;
			
		}
		for (int l396 = 0; (l396 < 2); l396 = (l396 + 1)) {
			fRec558[l396] = 0.0;
			
		}
		for (int l397 = 0; (l397 < 2); l397 = (l397 + 1)) {
			fRec556[l397] = 0.0;
			
		}
		for (int l398 = 0; (l398 < 2); l398 = (l398 + 1)) {
			fRec555[l398] = 0.0;
			
		}
		for (int l399 = 0; (l399 < 2); l399 = (l399 + 1)) {
			fRec553[l399] = 0.0;
			
		}
		for (int l400 = 0; (l400 < 2); l400 = (l400 + 1)) {
			fRec552[l400] = 0.0;
			
		}
		for (int l401 = 0; (l401 < 2); l401 = (l401 + 1)) {
			fRec550[l401] = 0.0;
			
		}
		for (int l402 = 0; (l402 < 2); l402 = (l402 + 1)) {
			fRec570[l402] = 0.0;
			
		}
		for (int l403 = 0; (l403 < 2); l403 = (l403 + 1)) {
			fRec568[l403] = 0.0;
			
		}
		for (int l404 = 0; (l404 < 2); l404 = (l404 + 1)) {
			fRec567[l404] = 0.0;
			
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec565[l405] = 0.0;
			
		}
		for (int l406 = 0; (l406 < 2); l406 = (l406 + 1)) {
			fRec564[l406] = 0.0;
			
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec562[l407] = 0.0;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec561[l408] = 0.0;
			
		}
		for (int l409 = 0; (l409 < 2); l409 = (l409 + 1)) {
			fRec559[l409] = 0.0;
			
		}
		for (int l410 = 0; (l410 < 1024); l410 = (l410 + 1)) {
			fVec7[l410] = 0.0;
			
		}
		for (int l411 = 0; (l411 < 2); l411 = (l411 + 1)) {
			fRec585[l411] = 0.0;
			
		}
		for (int l412 = 0; (l412 < 2); l412 = (l412 + 1)) {
			fRec583[l412] = 0.0;
			
		}
		for (int l413 = 0; (l413 < 2); l413 = (l413 + 1)) {
			fRec582[l413] = 0.0;
			
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec580[l414] = 0.0;
			
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec579[l415] = 0.0;
			
		}
		for (int l416 = 0; (l416 < 2); l416 = (l416 + 1)) {
			fRec577[l416] = 0.0;
			
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec576[l417] = 0.0;
			
		}
		for (int l418 = 0; (l418 < 2); l418 = (l418 + 1)) {
			fRec574[l418] = 0.0;
			
		}
		for (int l419 = 0; (l419 < 2); l419 = (l419 + 1)) {
			fRec573[l419] = 0.0;
			
		}
		for (int l420 = 0; (l420 < 2); l420 = (l420 + 1)) {
			fRec571[l420] = 0.0;
			
		}
		for (int l421 = 0; (l421 < 2); l421 = (l421 + 1)) {
			fRec597[l421] = 0.0;
			
		}
		for (int l422 = 0; (l422 < 2); l422 = (l422 + 1)) {
			fRec595[l422] = 0.0;
			
		}
		for (int l423 = 0; (l423 < 2); l423 = (l423 + 1)) {
			fRec594[l423] = 0.0;
			
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec592[l424] = 0.0;
			
		}
		for (int l425 = 0; (l425 < 2); l425 = (l425 + 1)) {
			fRec591[l425] = 0.0;
			
		}
		for (int l426 = 0; (l426 < 2); l426 = (l426 + 1)) {
			fRec589[l426] = 0.0;
			
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec588[l427] = 0.0;
			
		}
		for (int l428 = 0; (l428 < 2); l428 = (l428 + 1)) {
			fRec586[l428] = 0.0;
			
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec606[l429] = 0.0;
			
		}
		for (int l430 = 0; (l430 < 2); l430 = (l430 + 1)) {
			fRec604[l430] = 0.0;
			
		}
		for (int l431 = 0; (l431 < 2); l431 = (l431 + 1)) {
			fRec603[l431] = 0.0;
			
		}
		for (int l432 = 0; (l432 < 2); l432 = (l432 + 1)) {
			fRec601[l432] = 0.0;
			
		}
		for (int l433 = 0; (l433 < 2); l433 = (l433 + 1)) {
			fRec600[l433] = 0.0;
			
		}
		for (int l434 = 0; (l434 < 2); l434 = (l434 + 1)) {
			fRec598[l434] = 0.0;
			
		}
		for (int l435 = 0; (l435 < 2); l435 = (l435 + 1)) {
			fRec609[l435] = 0.0;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec607[l436] = 0.0;
			
		}
		for (int l437 = 0; (l437 < 2); l437 = (l437 + 1)) {
			fRec615[l437] = 0.0;
			
		}
		for (int l438 = 0; (l438 < 2); l438 = (l438 + 1)) {
			fRec613[l438] = 0.0;
			
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec612[l439] = 0.0;
			
		}
		for (int l440 = 0; (l440 < 2); l440 = (l440 + 1)) {
			fRec610[l440] = 0.0;
			
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
			fRec618[l451] = 0.0;
			
		}
		for (int l452 = 0; (l452 < 2); l452 = (l452 + 1)) {
			fRec616[l452] = 0.0;
			
		}
		for (int l453 = 0; (l453 < 1024); l453 = (l453 + 1)) {
			fVec8[l453] = 0.0;
			
		}
		for (int l454 = 0; (l454 < 2); l454 = (l454 + 1)) {
			fRec651[l454] = 0.0;
			
		}
		for (int l455 = 0; (l455 < 2); l455 = (l455 + 1)) {
			fRec649[l455] = 0.0;
			
		}
		for (int l456 = 0; (l456 < 2); l456 = (l456 + 1)) {
			fRec648[l456] = 0.0;
			
		}
		for (int l457 = 0; (l457 < 2); l457 = (l457 + 1)) {
			fRec646[l457] = 0.0;
			
		}
		for (int l458 = 0; (l458 < 2); l458 = (l458 + 1)) {
			fRec645[l458] = 0.0;
			
		}
		for (int l459 = 0; (l459 < 2); l459 = (l459 + 1)) {
			fRec643[l459] = 0.0;
			
		}
		for (int l460 = 0; (l460 < 2); l460 = (l460 + 1)) {
			fRec642[l460] = 0.0;
			
		}
		for (int l461 = 0; (l461 < 2); l461 = (l461 + 1)) {
			fRec640[l461] = 0.0;
			
		}
		for (int l462 = 0; (l462 < 2); l462 = (l462 + 1)) {
			fRec639[l462] = 0.0;
			
		}
		for (int l463 = 0; (l463 < 2); l463 = (l463 + 1)) {
			fRec637[l463] = 0.0;
			
		}
		for (int l464 = 0; (l464 < 2); l464 = (l464 + 1)) {
			fRec636[l464] = 0.0;
			
		}
		for (int l465 = 0; (l465 < 2); l465 = (l465 + 1)) {
			fRec634[l465] = 0.0;
			
		}
		for (int l466 = 0; (l466 < 2); l466 = (l466 + 1)) {
			fRec666[l466] = 0.0;
			
		}
		for (int l467 = 0; (l467 < 2); l467 = (l467 + 1)) {
			fRec664[l467] = 0.0;
			
		}
		for (int l468 = 0; (l468 < 2); l468 = (l468 + 1)) {
			fRec663[l468] = 0.0;
			
		}
		for (int l469 = 0; (l469 < 2); l469 = (l469 + 1)) {
			fRec661[l469] = 0.0;
			
		}
		for (int l470 = 0; (l470 < 2); l470 = (l470 + 1)) {
			fRec660[l470] = 0.0;
			
		}
		for (int l471 = 0; (l471 < 2); l471 = (l471 + 1)) {
			fRec658[l471] = 0.0;
			
		}
		for (int l472 = 0; (l472 < 2); l472 = (l472 + 1)) {
			fRec657[l472] = 0.0;
			
		}
		for (int l473 = 0; (l473 < 2); l473 = (l473 + 1)) {
			fRec655[l473] = 0.0;
			
		}
		for (int l474 = 0; (l474 < 2); l474 = (l474 + 1)) {
			fRec654[l474] = 0.0;
			
		}
		for (int l475 = 0; (l475 < 2); l475 = (l475 + 1)) {
			fRec652[l475] = 0.0;
			
		}
		for (int l476 = 0; (l476 < 2); l476 = (l476 + 1)) {
			fRec678[l476] = 0.0;
			
		}
		for (int l477 = 0; (l477 < 2); l477 = (l477 + 1)) {
			fRec676[l477] = 0.0;
			
		}
		for (int l478 = 0; (l478 < 2); l478 = (l478 + 1)) {
			fRec675[l478] = 0.0;
			
		}
		for (int l479 = 0; (l479 < 2); l479 = (l479 + 1)) {
			fRec673[l479] = 0.0;
			
		}
		for (int l480 = 0; (l480 < 2); l480 = (l480 + 1)) {
			fRec672[l480] = 0.0;
			
		}
		for (int l481 = 0; (l481 < 2); l481 = (l481 + 1)) {
			fRec670[l481] = 0.0;
			
		}
		for (int l482 = 0; (l482 < 2); l482 = (l482 + 1)) {
			fRec669[l482] = 0.0;
			
		}
		for (int l483 = 0; (l483 < 2); l483 = (l483 + 1)) {
			fRec667[l483] = 0.0;
			
		}
		for (int l484 = 0; (l484 < 2); l484 = (l484 + 1)) {
			fRec687[l484] = 0.0;
			
		}
		for (int l485 = 0; (l485 < 2); l485 = (l485 + 1)) {
			fRec685[l485] = 0.0;
			
		}
		for (int l486 = 0; (l486 < 2); l486 = (l486 + 1)) {
			fRec684[l486] = 0.0;
			
		}
		for (int l487 = 0; (l487 < 2); l487 = (l487 + 1)) {
			fRec682[l487] = 0.0;
			
		}
		for (int l488 = 0; (l488 < 2); l488 = (l488 + 1)) {
			fRec681[l488] = 0.0;
			
		}
		for (int l489 = 0; (l489 < 2); l489 = (l489 + 1)) {
			fRec679[l489] = 0.0;
			
		}
		for (int l490 = 0; (l490 < 2); l490 = (l490 + 1)) {
			fRec693[l490] = 0.0;
			
		}
		for (int l491 = 0; (l491 < 2); l491 = (l491 + 1)) {
			fRec691[l491] = 0.0;
			
		}
		for (int l492 = 0; (l492 < 2); l492 = (l492 + 1)) {
			fRec690[l492] = 0.0;
			
		}
		for (int l493 = 0; (l493 < 2); l493 = (l493 + 1)) {
			fRec688[l493] = 0.0;
			
		}
		for (int l494 = 0; (l494 < 2); l494 = (l494 + 1)) {
			fRec696[l494] = 0.0;
			
		}
		for (int l495 = 0; (l495 < 2); l495 = (l495 + 1)) {
			fRec694[l495] = 0.0;
			
		}
		for (int l496 = 0; (l496 < 1024); l496 = (l496 + 1)) {
			fVec9[l496] = 0.0;
			
		}
		for (int l497 = 0; (l497 < 2); l497 = (l497 + 1)) {
			fRec714[l497] = 0.0;
			
		}
		for (int l498 = 0; (l498 < 2); l498 = (l498 + 1)) {
			fRec712[l498] = 0.0;
			
		}
		for (int l499 = 0; (l499 < 2); l499 = (l499 + 1)) {
			fRec711[l499] = 0.0;
			
		}
		for (int l500 = 0; (l500 < 2); l500 = (l500 + 1)) {
			fRec709[l500] = 0.0;
			
		}
		for (int l501 = 0; (l501 < 2); l501 = (l501 + 1)) {
			fRec708[l501] = 0.0;
			
		}
		for (int l502 = 0; (l502 < 2); l502 = (l502 + 1)) {
			fRec706[l502] = 0.0;
			
		}
		for (int l503 = 0; (l503 < 2); l503 = (l503 + 1)) {
			fRec705[l503] = 0.0;
			
		}
		for (int l504 = 0; (l504 < 2); l504 = (l504 + 1)) {
			fRec703[l504] = 0.0;
			
		}
		for (int l505 = 0; (l505 < 2); l505 = (l505 + 1)) {
			fRec702[l505] = 0.0;
			
		}
		for (int l506 = 0; (l506 < 2); l506 = (l506 + 1)) {
			fRec700[l506] = 0.0;
			
		}
		for (int l507 = 0; (l507 < 2); l507 = (l507 + 1)) {
			fRec699[l507] = 0.0;
			
		}
		for (int l508 = 0; (l508 < 2); l508 = (l508 + 1)) {
			fRec697[l508] = 0.0;
			
		}
		for (int l509 = 0; (l509 < 2); l509 = (l509 + 1)) {
			fRec729[l509] = 0.0;
			
		}
		for (int l510 = 0; (l510 < 2); l510 = (l510 + 1)) {
			fRec727[l510] = 0.0;
			
		}
		for (int l511 = 0; (l511 < 2); l511 = (l511 + 1)) {
			fRec726[l511] = 0.0;
			
		}
		for (int l512 = 0; (l512 < 2); l512 = (l512 + 1)) {
			fRec724[l512] = 0.0;
			
		}
		for (int l513 = 0; (l513 < 2); l513 = (l513 + 1)) {
			fRec723[l513] = 0.0;
			
		}
		for (int l514 = 0; (l514 < 2); l514 = (l514 + 1)) {
			fRec721[l514] = 0.0;
			
		}
		for (int l515 = 0; (l515 < 2); l515 = (l515 + 1)) {
			fRec720[l515] = 0.0;
			
		}
		for (int l516 = 0; (l516 < 2); l516 = (l516 + 1)) {
			fRec718[l516] = 0.0;
			
		}
		for (int l517 = 0; (l517 < 2); l517 = (l517 + 1)) {
			fRec717[l517] = 0.0;
			
		}
		for (int l518 = 0; (l518 < 2); l518 = (l518 + 1)) {
			fRec715[l518] = 0.0;
			
		}
		for (int l519 = 0; (l519 < 2); l519 = (l519 + 1)) {
			fRec741[l519] = 0.0;
			
		}
		for (int l520 = 0; (l520 < 2); l520 = (l520 + 1)) {
			fRec739[l520] = 0.0;
			
		}
		for (int l521 = 0; (l521 < 2); l521 = (l521 + 1)) {
			fRec738[l521] = 0.0;
			
		}
		for (int l522 = 0; (l522 < 2); l522 = (l522 + 1)) {
			fRec736[l522] = 0.0;
			
		}
		for (int l523 = 0; (l523 < 2); l523 = (l523 + 1)) {
			fRec735[l523] = 0.0;
			
		}
		for (int l524 = 0; (l524 < 2); l524 = (l524 + 1)) {
			fRec733[l524] = 0.0;
			
		}
		for (int l525 = 0; (l525 < 2); l525 = (l525 + 1)) {
			fRec732[l525] = 0.0;
			
		}
		for (int l526 = 0; (l526 < 2); l526 = (l526 + 1)) {
			fRec730[l526] = 0.0;
			
		}
		for (int l527 = 0; (l527 < 2); l527 = (l527 + 1)) {
			fRec750[l527] = 0.0;
			
		}
		for (int l528 = 0; (l528 < 2); l528 = (l528 + 1)) {
			fRec748[l528] = 0.0;
			
		}
		for (int l529 = 0; (l529 < 2); l529 = (l529 + 1)) {
			fRec747[l529] = 0.0;
			
		}
		for (int l530 = 0; (l530 < 2); l530 = (l530 + 1)) {
			fRec745[l530] = 0.0;
			
		}
		for (int l531 = 0; (l531 < 2); l531 = (l531 + 1)) {
			fRec744[l531] = 0.0;
			
		}
		for (int l532 = 0; (l532 < 2); l532 = (l532 + 1)) {
			fRec742[l532] = 0.0;
			
		}
		for (int l533 = 0; (l533 < 2); l533 = (l533 + 1)) {
			fRec756[l533] = 0.0;
			
		}
		for (int l534 = 0; (l534 < 2); l534 = (l534 + 1)) {
			fRec754[l534] = 0.0;
			
		}
		for (int l535 = 0; (l535 < 2); l535 = (l535 + 1)) {
			fRec753[l535] = 0.0;
			
		}
		for (int l536 = 0; (l536 < 2); l536 = (l536 + 1)) {
			fRec751[l536] = 0.0;
			
		}
		for (int l537 = 0; (l537 < 2); l537 = (l537 + 1)) {
			fRec759[l537] = 0.0;
			
		}
		for (int l538 = 0; (l538 < 2); l538 = (l538 + 1)) {
			fRec757[l538] = 0.0;
			
		}
		for (int l539 = 0; (l539 < 1024); l539 = (l539 + 1)) {
			fVec10[l539] = 0.0;
			
		}
		for (int l540 = 0; (l540 < 2); l540 = (l540 + 1)) {
			fRec777[l540] = 0.0;
			
		}
		for (int l541 = 0; (l541 < 2); l541 = (l541 + 1)) {
			fRec775[l541] = 0.0;
			
		}
		for (int l542 = 0; (l542 < 2); l542 = (l542 + 1)) {
			fRec774[l542] = 0.0;
			
		}
		for (int l543 = 0; (l543 < 2); l543 = (l543 + 1)) {
			fRec772[l543] = 0.0;
			
		}
		for (int l544 = 0; (l544 < 2); l544 = (l544 + 1)) {
			fRec771[l544] = 0.0;
			
		}
		for (int l545 = 0; (l545 < 2); l545 = (l545 + 1)) {
			fRec769[l545] = 0.0;
			
		}
		for (int l546 = 0; (l546 < 2); l546 = (l546 + 1)) {
			fRec768[l546] = 0.0;
			
		}
		for (int l547 = 0; (l547 < 2); l547 = (l547 + 1)) {
			fRec766[l547] = 0.0;
			
		}
		for (int l548 = 0; (l548 < 2); l548 = (l548 + 1)) {
			fRec765[l548] = 0.0;
			
		}
		for (int l549 = 0; (l549 < 2); l549 = (l549 + 1)) {
			fRec763[l549] = 0.0;
			
		}
		for (int l550 = 0; (l550 < 2); l550 = (l550 + 1)) {
			fRec762[l550] = 0.0;
			
		}
		for (int l551 = 0; (l551 < 2); l551 = (l551 + 1)) {
			fRec760[l551] = 0.0;
			
		}
		for (int l552 = 0; (l552 < 2); l552 = (l552 + 1)) {
			fRec780[l552] = 0.0;
			
		}
		for (int l553 = 0; (l553 < 2); l553 = (l553 + 1)) {
			fRec778[l553] = 0.0;
			
		}
		for (int l554 = 0; (l554 < 2); l554 = (l554 + 1)) {
			fRec786[l554] = 0.0;
			
		}
		for (int l555 = 0; (l555 < 2); l555 = (l555 + 1)) {
			fRec784[l555] = 0.0;
			
		}
		for (int l556 = 0; (l556 < 2); l556 = (l556 + 1)) {
			fRec783[l556] = 0.0;
			
		}
		for (int l557 = 0; (l557 < 2); l557 = (l557 + 1)) {
			fRec781[l557] = 0.0;
			
		}
		for (int l558 = 0; (l558 < 2); l558 = (l558 + 1)) {
			fRec795[l558] = 0.0;
			
		}
		for (int l559 = 0; (l559 < 2); l559 = (l559 + 1)) {
			fRec793[l559] = 0.0;
			
		}
		for (int l560 = 0; (l560 < 2); l560 = (l560 + 1)) {
			fRec792[l560] = 0.0;
			
		}
		for (int l561 = 0; (l561 < 2); l561 = (l561 + 1)) {
			fRec790[l561] = 0.0;
			
		}
		for (int l562 = 0; (l562 < 2); l562 = (l562 + 1)) {
			fRec789[l562] = 0.0;
			
		}
		for (int l563 = 0; (l563 < 2); l563 = (l563 + 1)) {
			fRec787[l563] = 0.0;
			
		}
		for (int l564 = 0; (l564 < 2); l564 = (l564 + 1)) {
			fRec807[l564] = 0.0;
			
		}
		for (int l565 = 0; (l565 < 2); l565 = (l565 + 1)) {
			fRec805[l565] = 0.0;
			
		}
		for (int l566 = 0; (l566 < 2); l566 = (l566 + 1)) {
			fRec804[l566] = 0.0;
			
		}
		for (int l567 = 0; (l567 < 2); l567 = (l567 + 1)) {
			fRec802[l567] = 0.0;
			
		}
		for (int l568 = 0; (l568 < 2); l568 = (l568 + 1)) {
			fRec801[l568] = 0.0;
			
		}
		for (int l569 = 0; (l569 < 2); l569 = (l569 + 1)) {
			fRec799[l569] = 0.0;
			
		}
		for (int l570 = 0; (l570 < 2); l570 = (l570 + 1)) {
			fRec798[l570] = 0.0;
			
		}
		for (int l571 = 0; (l571 < 2); l571 = (l571 + 1)) {
			fRec796[l571] = 0.0;
			
		}
		for (int l572 = 0; (l572 < 2); l572 = (l572 + 1)) {
			fRec822[l572] = 0.0;
			
		}
		for (int l573 = 0; (l573 < 2); l573 = (l573 + 1)) {
			fRec820[l573] = 0.0;
			
		}
		for (int l574 = 0; (l574 < 2); l574 = (l574 + 1)) {
			fRec819[l574] = 0.0;
			
		}
		for (int l575 = 0; (l575 < 2); l575 = (l575 + 1)) {
			fRec817[l575] = 0.0;
			
		}
		for (int l576 = 0; (l576 < 2); l576 = (l576 + 1)) {
			fRec816[l576] = 0.0;
			
		}
		for (int l577 = 0; (l577 < 2); l577 = (l577 + 1)) {
			fRec814[l577] = 0.0;
			
		}
		for (int l578 = 0; (l578 < 2); l578 = (l578 + 1)) {
			fRec813[l578] = 0.0;
			
		}
		for (int l579 = 0; (l579 < 2); l579 = (l579 + 1)) {
			fRec811[l579] = 0.0;
			
		}
		for (int l580 = 0; (l580 < 2); l580 = (l580 + 1)) {
			fRec810[l580] = 0.0;
			
		}
		for (int l581 = 0; (l581 < 2); l581 = (l581 + 1)) {
			fRec808[l581] = 0.0;
			
		}
		for (int l582 = 0; (l582 < 1024); l582 = (l582 + 1)) {
			fVec11[l582] = 0.0;
			
		}
		for (int l583 = 0; (l583 < 2); l583 = (l583 + 1)) {
			fRec840[l583] = 0.0;
			
		}
		for (int l584 = 0; (l584 < 2); l584 = (l584 + 1)) {
			fRec838[l584] = 0.0;
			
		}
		for (int l585 = 0; (l585 < 2); l585 = (l585 + 1)) {
			fRec837[l585] = 0.0;
			
		}
		for (int l586 = 0; (l586 < 2); l586 = (l586 + 1)) {
			fRec835[l586] = 0.0;
			
		}
		for (int l587 = 0; (l587 < 2); l587 = (l587 + 1)) {
			fRec834[l587] = 0.0;
			
		}
		for (int l588 = 0; (l588 < 2); l588 = (l588 + 1)) {
			fRec832[l588] = 0.0;
			
		}
		for (int l589 = 0; (l589 < 2); l589 = (l589 + 1)) {
			fRec831[l589] = 0.0;
			
		}
		for (int l590 = 0; (l590 < 2); l590 = (l590 + 1)) {
			fRec829[l590] = 0.0;
			
		}
		for (int l591 = 0; (l591 < 2); l591 = (l591 + 1)) {
			fRec828[l591] = 0.0;
			
		}
		for (int l592 = 0; (l592 < 2); l592 = (l592 + 1)) {
			fRec826[l592] = 0.0;
			
		}
		for (int l593 = 0; (l593 < 2); l593 = (l593 + 1)) {
			fRec825[l593] = 0.0;
			
		}
		for (int l594 = 0; (l594 < 2); l594 = (l594 + 1)) {
			fRec823[l594] = 0.0;
			
		}
		for (int l595 = 0; (l595 < 2); l595 = (l595 + 1)) {
			fRec855[l595] = 0.0;
			
		}
		for (int l596 = 0; (l596 < 2); l596 = (l596 + 1)) {
			fRec853[l596] = 0.0;
			
		}
		for (int l597 = 0; (l597 < 2); l597 = (l597 + 1)) {
			fRec852[l597] = 0.0;
			
		}
		for (int l598 = 0; (l598 < 2); l598 = (l598 + 1)) {
			fRec850[l598] = 0.0;
			
		}
		for (int l599 = 0; (l599 < 2); l599 = (l599 + 1)) {
			fRec849[l599] = 0.0;
			
		}
		for (int l600 = 0; (l600 < 2); l600 = (l600 + 1)) {
			fRec847[l600] = 0.0;
			
		}
		for (int l601 = 0; (l601 < 2); l601 = (l601 + 1)) {
			fRec846[l601] = 0.0;
			
		}
		for (int l602 = 0; (l602 < 2); l602 = (l602 + 1)) {
			fRec844[l602] = 0.0;
			
		}
		for (int l603 = 0; (l603 < 2); l603 = (l603 + 1)) {
			fRec843[l603] = 0.0;
			
		}
		for (int l604 = 0; (l604 < 2); l604 = (l604 + 1)) {
			fRec841[l604] = 0.0;
			
		}
		for (int l605 = 0; (l605 < 2); l605 = (l605 + 1)) {
			fRec867[l605] = 0.0;
			
		}
		for (int l606 = 0; (l606 < 2); l606 = (l606 + 1)) {
			fRec865[l606] = 0.0;
			
		}
		for (int l607 = 0; (l607 < 2); l607 = (l607 + 1)) {
			fRec864[l607] = 0.0;
			
		}
		for (int l608 = 0; (l608 < 2); l608 = (l608 + 1)) {
			fRec862[l608] = 0.0;
			
		}
		for (int l609 = 0; (l609 < 2); l609 = (l609 + 1)) {
			fRec861[l609] = 0.0;
			
		}
		for (int l610 = 0; (l610 < 2); l610 = (l610 + 1)) {
			fRec859[l610] = 0.0;
			
		}
		for (int l611 = 0; (l611 < 2); l611 = (l611 + 1)) {
			fRec858[l611] = 0.0;
			
		}
		for (int l612 = 0; (l612 < 2); l612 = (l612 + 1)) {
			fRec856[l612] = 0.0;
			
		}
		for (int l613 = 0; (l613 < 2); l613 = (l613 + 1)) {
			fRec876[l613] = 0.0;
			
		}
		for (int l614 = 0; (l614 < 2); l614 = (l614 + 1)) {
			fRec874[l614] = 0.0;
			
		}
		for (int l615 = 0; (l615 < 2); l615 = (l615 + 1)) {
			fRec873[l615] = 0.0;
			
		}
		for (int l616 = 0; (l616 < 2); l616 = (l616 + 1)) {
			fRec871[l616] = 0.0;
			
		}
		for (int l617 = 0; (l617 < 2); l617 = (l617 + 1)) {
			fRec870[l617] = 0.0;
			
		}
		for (int l618 = 0; (l618 < 2); l618 = (l618 + 1)) {
			fRec868[l618] = 0.0;
			
		}
		for (int l619 = 0; (l619 < 2); l619 = (l619 + 1)) {
			fRec879[l619] = 0.0;
			
		}
		for (int l620 = 0; (l620 < 2); l620 = (l620 + 1)) {
			fRec877[l620] = 0.0;
			
		}
		for (int l621 = 0; (l621 < 2); l621 = (l621 + 1)) {
			fRec885[l621] = 0.0;
			
		}
		for (int l622 = 0; (l622 < 2); l622 = (l622 + 1)) {
			fRec883[l622] = 0.0;
			
		}
		for (int l623 = 0; (l623 < 2); l623 = (l623 + 1)) {
			fRec882[l623] = 0.0;
			
		}
		for (int l624 = 0; (l624 < 2); l624 = (l624 + 1)) {
			fRec880[l624] = 0.0;
			
		}
		for (int l625 = 0; (l625 < 1024); l625 = (l625 + 1)) {
			fVec12[l625] = 0.0;
			
		}
		for (int l626 = 0; (l626 < 2); l626 = (l626 + 1)) {
			fRec903[l626] = 0.0;
			
		}
		for (int l627 = 0; (l627 < 2); l627 = (l627 + 1)) {
			fRec901[l627] = 0.0;
			
		}
		for (int l628 = 0; (l628 < 2); l628 = (l628 + 1)) {
			fRec900[l628] = 0.0;
			
		}
		for (int l629 = 0; (l629 < 2); l629 = (l629 + 1)) {
			fRec898[l629] = 0.0;
			
		}
		for (int l630 = 0; (l630 < 2); l630 = (l630 + 1)) {
			fRec897[l630] = 0.0;
			
		}
		for (int l631 = 0; (l631 < 2); l631 = (l631 + 1)) {
			fRec895[l631] = 0.0;
			
		}
		for (int l632 = 0; (l632 < 2); l632 = (l632 + 1)) {
			fRec894[l632] = 0.0;
			
		}
		for (int l633 = 0; (l633 < 2); l633 = (l633 + 1)) {
			fRec892[l633] = 0.0;
			
		}
		for (int l634 = 0; (l634 < 2); l634 = (l634 + 1)) {
			fRec891[l634] = 0.0;
			
		}
		for (int l635 = 0; (l635 < 2); l635 = (l635 + 1)) {
			fRec889[l635] = 0.0;
			
		}
		for (int l636 = 0; (l636 < 2); l636 = (l636 + 1)) {
			fRec888[l636] = 0.0;
			
		}
		for (int l637 = 0; (l637 < 2); l637 = (l637 + 1)) {
			fRec886[l637] = 0.0;
			
		}
		for (int l638 = 0; (l638 < 2); l638 = (l638 + 1)) {
			fRec918[l638] = 0.0;
			
		}
		for (int l639 = 0; (l639 < 2); l639 = (l639 + 1)) {
			fRec916[l639] = 0.0;
			
		}
		for (int l640 = 0; (l640 < 2); l640 = (l640 + 1)) {
			fRec915[l640] = 0.0;
			
		}
		for (int l641 = 0; (l641 < 2); l641 = (l641 + 1)) {
			fRec913[l641] = 0.0;
			
		}
		for (int l642 = 0; (l642 < 2); l642 = (l642 + 1)) {
			fRec912[l642] = 0.0;
			
		}
		for (int l643 = 0; (l643 < 2); l643 = (l643 + 1)) {
			fRec910[l643] = 0.0;
			
		}
		for (int l644 = 0; (l644 < 2); l644 = (l644 + 1)) {
			fRec909[l644] = 0.0;
			
		}
		for (int l645 = 0; (l645 < 2); l645 = (l645 + 1)) {
			fRec907[l645] = 0.0;
			
		}
		for (int l646 = 0; (l646 < 2); l646 = (l646 + 1)) {
			fRec906[l646] = 0.0;
			
		}
		for (int l647 = 0; (l647 < 2); l647 = (l647 + 1)) {
			fRec904[l647] = 0.0;
			
		}
		for (int l648 = 0; (l648 < 2); l648 = (l648 + 1)) {
			fRec930[l648] = 0.0;
			
		}
		for (int l649 = 0; (l649 < 2); l649 = (l649 + 1)) {
			fRec928[l649] = 0.0;
			
		}
		for (int l650 = 0; (l650 < 2); l650 = (l650 + 1)) {
			fRec927[l650] = 0.0;
			
		}
		for (int l651 = 0; (l651 < 2); l651 = (l651 + 1)) {
			fRec925[l651] = 0.0;
			
		}
		for (int l652 = 0; (l652 < 2); l652 = (l652 + 1)) {
			fRec924[l652] = 0.0;
			
		}
		for (int l653 = 0; (l653 < 2); l653 = (l653 + 1)) {
			fRec922[l653] = 0.0;
			
		}
		for (int l654 = 0; (l654 < 2); l654 = (l654 + 1)) {
			fRec921[l654] = 0.0;
			
		}
		for (int l655 = 0; (l655 < 2); l655 = (l655 + 1)) {
			fRec919[l655] = 0.0;
			
		}
		for (int l656 = 0; (l656 < 2); l656 = (l656 + 1)) {
			fRec939[l656] = 0.0;
			
		}
		for (int l657 = 0; (l657 < 2); l657 = (l657 + 1)) {
			fRec937[l657] = 0.0;
			
		}
		for (int l658 = 0; (l658 < 2); l658 = (l658 + 1)) {
			fRec936[l658] = 0.0;
			
		}
		for (int l659 = 0; (l659 < 2); l659 = (l659 + 1)) {
			fRec934[l659] = 0.0;
			
		}
		for (int l660 = 0; (l660 < 2); l660 = (l660 + 1)) {
			fRec933[l660] = 0.0;
			
		}
		for (int l661 = 0; (l661 < 2); l661 = (l661 + 1)) {
			fRec931[l661] = 0.0;
			
		}
		for (int l662 = 0; (l662 < 2); l662 = (l662 + 1)) {
			fRec942[l662] = 0.0;
			
		}
		for (int l663 = 0; (l663 < 2); l663 = (l663 + 1)) {
			fRec940[l663] = 0.0;
			
		}
		for (int l664 = 0; (l664 < 2); l664 = (l664 + 1)) {
			fRec948[l664] = 0.0;
			
		}
		for (int l665 = 0; (l665 < 2); l665 = (l665 + 1)) {
			fRec946[l665] = 0.0;
			
		}
		for (int l666 = 0; (l666 < 2); l666 = (l666 + 1)) {
			fRec945[l666] = 0.0;
			
		}
		for (int l667 = 0; (l667 < 2); l667 = (l667 + 1)) {
			fRec943[l667] = 0.0;
			
		}
		for (int l668 = 0; (l668 < 1024); l668 = (l668 + 1)) {
			fVec13[l668] = 0.0;
			
		}
		for (int l669 = 0; (l669 < 2); l669 = (l669 + 1)) {
			fRec966[l669] = 0.0;
			
		}
		for (int l670 = 0; (l670 < 2); l670 = (l670 + 1)) {
			fRec964[l670] = 0.0;
			
		}
		for (int l671 = 0; (l671 < 2); l671 = (l671 + 1)) {
			fRec963[l671] = 0.0;
			
		}
		for (int l672 = 0; (l672 < 2); l672 = (l672 + 1)) {
			fRec961[l672] = 0.0;
			
		}
		for (int l673 = 0; (l673 < 2); l673 = (l673 + 1)) {
			fRec960[l673] = 0.0;
			
		}
		for (int l674 = 0; (l674 < 2); l674 = (l674 + 1)) {
			fRec958[l674] = 0.0;
			
		}
		for (int l675 = 0; (l675 < 2); l675 = (l675 + 1)) {
			fRec957[l675] = 0.0;
			
		}
		for (int l676 = 0; (l676 < 2); l676 = (l676 + 1)) {
			fRec955[l676] = 0.0;
			
		}
		for (int l677 = 0; (l677 < 2); l677 = (l677 + 1)) {
			fRec954[l677] = 0.0;
			
		}
		for (int l678 = 0; (l678 < 2); l678 = (l678 + 1)) {
			fRec952[l678] = 0.0;
			
		}
		for (int l679 = 0; (l679 < 2); l679 = (l679 + 1)) {
			fRec951[l679] = 0.0;
			
		}
		for (int l680 = 0; (l680 < 2); l680 = (l680 + 1)) {
			fRec949[l680] = 0.0;
			
		}
		for (int l681 = 0; (l681 < 2); l681 = (l681 + 1)) {
			fRec981[l681] = 0.0;
			
		}
		for (int l682 = 0; (l682 < 2); l682 = (l682 + 1)) {
			fRec979[l682] = 0.0;
			
		}
		for (int l683 = 0; (l683 < 2); l683 = (l683 + 1)) {
			fRec978[l683] = 0.0;
			
		}
		for (int l684 = 0; (l684 < 2); l684 = (l684 + 1)) {
			fRec976[l684] = 0.0;
			
		}
		for (int l685 = 0; (l685 < 2); l685 = (l685 + 1)) {
			fRec975[l685] = 0.0;
			
		}
		for (int l686 = 0; (l686 < 2); l686 = (l686 + 1)) {
			fRec973[l686] = 0.0;
			
		}
		for (int l687 = 0; (l687 < 2); l687 = (l687 + 1)) {
			fRec972[l687] = 0.0;
			
		}
		for (int l688 = 0; (l688 < 2); l688 = (l688 + 1)) {
			fRec970[l688] = 0.0;
			
		}
		for (int l689 = 0; (l689 < 2); l689 = (l689 + 1)) {
			fRec969[l689] = 0.0;
			
		}
		for (int l690 = 0; (l690 < 2); l690 = (l690 + 1)) {
			fRec967[l690] = 0.0;
			
		}
		for (int l691 = 0; (l691 < 2); l691 = (l691 + 1)) {
			fRec993[l691] = 0.0;
			
		}
		for (int l692 = 0; (l692 < 2); l692 = (l692 + 1)) {
			fRec991[l692] = 0.0;
			
		}
		for (int l693 = 0; (l693 < 2); l693 = (l693 + 1)) {
			fRec990[l693] = 0.0;
			
		}
		for (int l694 = 0; (l694 < 2); l694 = (l694 + 1)) {
			fRec988[l694] = 0.0;
			
		}
		for (int l695 = 0; (l695 < 2); l695 = (l695 + 1)) {
			fRec987[l695] = 0.0;
			
		}
		for (int l696 = 0; (l696 < 2); l696 = (l696 + 1)) {
			fRec985[l696] = 0.0;
			
		}
		for (int l697 = 0; (l697 < 2); l697 = (l697 + 1)) {
			fRec984[l697] = 0.0;
			
		}
		for (int l698 = 0; (l698 < 2); l698 = (l698 + 1)) {
			fRec982[l698] = 0.0;
			
		}
		for (int l699 = 0; (l699 < 2); l699 = (l699 + 1)) {
			fRec1002[l699] = 0.0;
			
		}
		for (int l700 = 0; (l700 < 2); l700 = (l700 + 1)) {
			fRec1000[l700] = 0.0;
			
		}
		for (int l701 = 0; (l701 < 2); l701 = (l701 + 1)) {
			fRec999[l701] = 0.0;
			
		}
		for (int l702 = 0; (l702 < 2); l702 = (l702 + 1)) {
			fRec997[l702] = 0.0;
			
		}
		for (int l703 = 0; (l703 < 2); l703 = (l703 + 1)) {
			fRec996[l703] = 0.0;
			
		}
		for (int l704 = 0; (l704 < 2); l704 = (l704 + 1)) {
			fRec994[l704] = 0.0;
			
		}
		for (int l705 = 0; (l705 < 2); l705 = (l705 + 1)) {
			fRec1005[l705] = 0.0;
			
		}
		for (int l706 = 0; (l706 < 2); l706 = (l706 + 1)) {
			fRec1003[l706] = 0.0;
			
		}
		for (int l707 = 0; (l707 < 2); l707 = (l707 + 1)) {
			fRec1011[l707] = 0.0;
			
		}
		for (int l708 = 0; (l708 < 2); l708 = (l708 + 1)) {
			fRec1009[l708] = 0.0;
			
		}
		for (int l709 = 0; (l709 < 2); l709 = (l709 + 1)) {
			fRec1008[l709] = 0.0;
			
		}
		for (int l710 = 0; (l710 < 2); l710 = (l710 + 1)) {
			fRec1006[l710] = 0.0;
			
		}
		for (int l711 = 0; (l711 < 1024); l711 = (l711 + 1)) {
			fVec14[l711] = 0.0;
			
		}
		for (int l712 = 0; (l712 < 2); l712 = (l712 + 1)) {
			fRec1029[l712] = 0.0;
			
		}
		for (int l713 = 0; (l713 < 2); l713 = (l713 + 1)) {
			fRec1027[l713] = 0.0;
			
		}
		for (int l714 = 0; (l714 < 2); l714 = (l714 + 1)) {
			fRec1026[l714] = 0.0;
			
		}
		for (int l715 = 0; (l715 < 2); l715 = (l715 + 1)) {
			fRec1024[l715] = 0.0;
			
		}
		for (int l716 = 0; (l716 < 2); l716 = (l716 + 1)) {
			fRec1023[l716] = 0.0;
			
		}
		for (int l717 = 0; (l717 < 2); l717 = (l717 + 1)) {
			fRec1021[l717] = 0.0;
			
		}
		for (int l718 = 0; (l718 < 2); l718 = (l718 + 1)) {
			fRec1020[l718] = 0.0;
			
		}
		for (int l719 = 0; (l719 < 2); l719 = (l719 + 1)) {
			fRec1018[l719] = 0.0;
			
		}
		for (int l720 = 0; (l720 < 2); l720 = (l720 + 1)) {
			fRec1017[l720] = 0.0;
			
		}
		for (int l721 = 0; (l721 < 2); l721 = (l721 + 1)) {
			fRec1015[l721] = 0.0;
			
		}
		for (int l722 = 0; (l722 < 2); l722 = (l722 + 1)) {
			fRec1014[l722] = 0.0;
			
		}
		for (int l723 = 0; (l723 < 2); l723 = (l723 + 1)) {
			fRec1012[l723] = 0.0;
			
		}
		for (int l724 = 0; (l724 < 2); l724 = (l724 + 1)) {
			fRec1044[l724] = 0.0;
			
		}
		for (int l725 = 0; (l725 < 2); l725 = (l725 + 1)) {
			fRec1042[l725] = 0.0;
			
		}
		for (int l726 = 0; (l726 < 2); l726 = (l726 + 1)) {
			fRec1041[l726] = 0.0;
			
		}
		for (int l727 = 0; (l727 < 2); l727 = (l727 + 1)) {
			fRec1039[l727] = 0.0;
			
		}
		for (int l728 = 0; (l728 < 2); l728 = (l728 + 1)) {
			fRec1038[l728] = 0.0;
			
		}
		for (int l729 = 0; (l729 < 2); l729 = (l729 + 1)) {
			fRec1036[l729] = 0.0;
			
		}
		for (int l730 = 0; (l730 < 2); l730 = (l730 + 1)) {
			fRec1035[l730] = 0.0;
			
		}
		for (int l731 = 0; (l731 < 2); l731 = (l731 + 1)) {
			fRec1033[l731] = 0.0;
			
		}
		for (int l732 = 0; (l732 < 2); l732 = (l732 + 1)) {
			fRec1032[l732] = 0.0;
			
		}
		for (int l733 = 0; (l733 < 2); l733 = (l733 + 1)) {
			fRec1030[l733] = 0.0;
			
		}
		for (int l734 = 0; (l734 < 2); l734 = (l734 + 1)) {
			fRec1056[l734] = 0.0;
			
		}
		for (int l735 = 0; (l735 < 2); l735 = (l735 + 1)) {
			fRec1054[l735] = 0.0;
			
		}
		for (int l736 = 0; (l736 < 2); l736 = (l736 + 1)) {
			fRec1053[l736] = 0.0;
			
		}
		for (int l737 = 0; (l737 < 2); l737 = (l737 + 1)) {
			fRec1051[l737] = 0.0;
			
		}
		for (int l738 = 0; (l738 < 2); l738 = (l738 + 1)) {
			fRec1050[l738] = 0.0;
			
		}
		for (int l739 = 0; (l739 < 2); l739 = (l739 + 1)) {
			fRec1048[l739] = 0.0;
			
		}
		for (int l740 = 0; (l740 < 2); l740 = (l740 + 1)) {
			fRec1047[l740] = 0.0;
			
		}
		for (int l741 = 0; (l741 < 2); l741 = (l741 + 1)) {
			fRec1045[l741] = 0.0;
			
		}
		for (int l742 = 0; (l742 < 2); l742 = (l742 + 1)) {
			fRec1065[l742] = 0.0;
			
		}
		for (int l743 = 0; (l743 < 2); l743 = (l743 + 1)) {
			fRec1063[l743] = 0.0;
			
		}
		for (int l744 = 0; (l744 < 2); l744 = (l744 + 1)) {
			fRec1062[l744] = 0.0;
			
		}
		for (int l745 = 0; (l745 < 2); l745 = (l745 + 1)) {
			fRec1060[l745] = 0.0;
			
		}
		for (int l746 = 0; (l746 < 2); l746 = (l746 + 1)) {
			fRec1059[l746] = 0.0;
			
		}
		for (int l747 = 0; (l747 < 2); l747 = (l747 + 1)) {
			fRec1057[l747] = 0.0;
			
		}
		for (int l748 = 0; (l748 < 2); l748 = (l748 + 1)) {
			fRec1068[l748] = 0.0;
			
		}
		for (int l749 = 0; (l749 < 2); l749 = (l749 + 1)) {
			fRec1066[l749] = 0.0;
			
		}
		for (int l750 = 0; (l750 < 2); l750 = (l750 + 1)) {
			fRec1074[l750] = 0.0;
			
		}
		for (int l751 = 0; (l751 < 2); l751 = (l751 + 1)) {
			fRec1072[l751] = 0.0;
			
		}
		for (int l752 = 0; (l752 < 2); l752 = (l752 + 1)) {
			fRec1071[l752] = 0.0;
			
		}
		for (int l753 = 0; (l753 < 2); l753 = (l753 + 1)) {
			fRec1069[l753] = 0.0;
			
		}
		for (int l754 = 0; (l754 < 1024); l754 = (l754 + 1)) {
			fVec15[l754] = 0.0;
			
		}
		for (int l755 = 0; (l755 < 2); l755 = (l755 + 1)) {
			fRec1092[l755] = 0.0;
			
		}
		for (int l756 = 0; (l756 < 2); l756 = (l756 + 1)) {
			fRec1090[l756] = 0.0;
			
		}
		for (int l757 = 0; (l757 < 2); l757 = (l757 + 1)) {
			fRec1089[l757] = 0.0;
			
		}
		for (int l758 = 0; (l758 < 2); l758 = (l758 + 1)) {
			fRec1087[l758] = 0.0;
			
		}
		for (int l759 = 0; (l759 < 2); l759 = (l759 + 1)) {
			fRec1086[l759] = 0.0;
			
		}
		for (int l760 = 0; (l760 < 2); l760 = (l760 + 1)) {
			fRec1084[l760] = 0.0;
			
		}
		for (int l761 = 0; (l761 < 2); l761 = (l761 + 1)) {
			fRec1083[l761] = 0.0;
			
		}
		for (int l762 = 0; (l762 < 2); l762 = (l762 + 1)) {
			fRec1081[l762] = 0.0;
			
		}
		for (int l763 = 0; (l763 < 2); l763 = (l763 + 1)) {
			fRec1080[l763] = 0.0;
			
		}
		for (int l764 = 0; (l764 < 2); l764 = (l764 + 1)) {
			fRec1078[l764] = 0.0;
			
		}
		for (int l765 = 0; (l765 < 2); l765 = (l765 + 1)) {
			fRec1077[l765] = 0.0;
			
		}
		for (int l766 = 0; (l766 < 2); l766 = (l766 + 1)) {
			fRec1075[l766] = 0.0;
			
		}
		for (int l767 = 0; (l767 < 2); l767 = (l767 + 1)) {
			fRec1107[l767] = 0.0;
			
		}
		for (int l768 = 0; (l768 < 2); l768 = (l768 + 1)) {
			fRec1105[l768] = 0.0;
			
		}
		for (int l769 = 0; (l769 < 2); l769 = (l769 + 1)) {
			fRec1104[l769] = 0.0;
			
		}
		for (int l770 = 0; (l770 < 2); l770 = (l770 + 1)) {
			fRec1102[l770] = 0.0;
			
		}
		for (int l771 = 0; (l771 < 2); l771 = (l771 + 1)) {
			fRec1101[l771] = 0.0;
			
		}
		for (int l772 = 0; (l772 < 2); l772 = (l772 + 1)) {
			fRec1099[l772] = 0.0;
			
		}
		for (int l773 = 0; (l773 < 2); l773 = (l773 + 1)) {
			fRec1098[l773] = 0.0;
			
		}
		for (int l774 = 0; (l774 < 2); l774 = (l774 + 1)) {
			fRec1096[l774] = 0.0;
			
		}
		for (int l775 = 0; (l775 < 2); l775 = (l775 + 1)) {
			fRec1095[l775] = 0.0;
			
		}
		for (int l776 = 0; (l776 < 2); l776 = (l776 + 1)) {
			fRec1093[l776] = 0.0;
			
		}
		for (int l777 = 0; (l777 < 2); l777 = (l777 + 1)) {
			fRec1119[l777] = 0.0;
			
		}
		for (int l778 = 0; (l778 < 2); l778 = (l778 + 1)) {
			fRec1117[l778] = 0.0;
			
		}
		for (int l779 = 0; (l779 < 2); l779 = (l779 + 1)) {
			fRec1116[l779] = 0.0;
			
		}
		for (int l780 = 0; (l780 < 2); l780 = (l780 + 1)) {
			fRec1114[l780] = 0.0;
			
		}
		for (int l781 = 0; (l781 < 2); l781 = (l781 + 1)) {
			fRec1113[l781] = 0.0;
			
		}
		for (int l782 = 0; (l782 < 2); l782 = (l782 + 1)) {
			fRec1111[l782] = 0.0;
			
		}
		for (int l783 = 0; (l783 < 2); l783 = (l783 + 1)) {
			fRec1110[l783] = 0.0;
			
		}
		for (int l784 = 0; (l784 < 2); l784 = (l784 + 1)) {
			fRec1108[l784] = 0.0;
			
		}
		for (int l785 = 0; (l785 < 2); l785 = (l785 + 1)) {
			fRec1128[l785] = 0.0;
			
		}
		for (int l786 = 0; (l786 < 2); l786 = (l786 + 1)) {
			fRec1126[l786] = 0.0;
			
		}
		for (int l787 = 0; (l787 < 2); l787 = (l787 + 1)) {
			fRec1125[l787] = 0.0;
			
		}
		for (int l788 = 0; (l788 < 2); l788 = (l788 + 1)) {
			fRec1123[l788] = 0.0;
			
		}
		for (int l789 = 0; (l789 < 2); l789 = (l789 + 1)) {
			fRec1122[l789] = 0.0;
			
		}
		for (int l790 = 0; (l790 < 2); l790 = (l790 + 1)) {
			fRec1120[l790] = 0.0;
			
		}
		for (int l791 = 0; (l791 < 2); l791 = (l791 + 1)) {
			fRec1131[l791] = 0.0;
			
		}
		for (int l792 = 0; (l792 < 2); l792 = (l792 + 1)) {
			fRec1129[l792] = 0.0;
			
		}
		for (int l793 = 0; (l793 < 2); l793 = (l793 + 1)) {
			fRec1137[l793] = 0.0;
			
		}
		for (int l794 = 0; (l794 < 2); l794 = (l794 + 1)) {
			fRec1135[l794] = 0.0;
			
		}
		for (int l795 = 0; (l795 < 2); l795 = (l795 + 1)) {
			fRec1134[l795] = 0.0;
			
		}
		for (int l796 = 0; (l796 < 2); l796 = (l796 + 1)) {
			fRec1132[l796] = 0.0;
			
		}
		for (int l797 = 0; (l797 < 512); l797 = (l797 + 1)) {
			fVec16[l797] = 0.0;
			
		}
		for (int l798 = 0; (l798 < 2); l798 = (l798 + 1)) {
			fRec1155[l798] = 0.0;
			
		}
		for (int l799 = 0; (l799 < 2); l799 = (l799 + 1)) {
			fRec1153[l799] = 0.0;
			
		}
		for (int l800 = 0; (l800 < 2); l800 = (l800 + 1)) {
			fRec1152[l800] = 0.0;
			
		}
		for (int l801 = 0; (l801 < 2); l801 = (l801 + 1)) {
			fRec1150[l801] = 0.0;
			
		}
		for (int l802 = 0; (l802 < 2); l802 = (l802 + 1)) {
			fRec1149[l802] = 0.0;
			
		}
		for (int l803 = 0; (l803 < 2); l803 = (l803 + 1)) {
			fRec1147[l803] = 0.0;
			
		}
		for (int l804 = 0; (l804 < 2); l804 = (l804 + 1)) {
			fRec1146[l804] = 0.0;
			
		}
		for (int l805 = 0; (l805 < 2); l805 = (l805 + 1)) {
			fRec1144[l805] = 0.0;
			
		}
		for (int l806 = 0; (l806 < 2); l806 = (l806 + 1)) {
			fRec1143[l806] = 0.0;
			
		}
		for (int l807 = 0; (l807 < 2); l807 = (l807 + 1)) {
			fRec1141[l807] = 0.0;
			
		}
		for (int l808 = 0; (l808 < 2); l808 = (l808 + 1)) {
			fRec1140[l808] = 0.0;
			
		}
		for (int l809 = 0; (l809 < 2); l809 = (l809 + 1)) {
			fRec1138[l809] = 0.0;
			
		}
		for (int l810 = 0; (l810 < 2); l810 = (l810 + 1)) {
			fRec1170[l810] = 0.0;
			
		}
		for (int l811 = 0; (l811 < 2); l811 = (l811 + 1)) {
			fRec1168[l811] = 0.0;
			
		}
		for (int l812 = 0; (l812 < 2); l812 = (l812 + 1)) {
			fRec1167[l812] = 0.0;
			
		}
		for (int l813 = 0; (l813 < 2); l813 = (l813 + 1)) {
			fRec1165[l813] = 0.0;
			
		}
		for (int l814 = 0; (l814 < 2); l814 = (l814 + 1)) {
			fRec1164[l814] = 0.0;
			
		}
		for (int l815 = 0; (l815 < 2); l815 = (l815 + 1)) {
			fRec1162[l815] = 0.0;
			
		}
		for (int l816 = 0; (l816 < 2); l816 = (l816 + 1)) {
			fRec1161[l816] = 0.0;
			
		}
		for (int l817 = 0; (l817 < 2); l817 = (l817 + 1)) {
			fRec1159[l817] = 0.0;
			
		}
		for (int l818 = 0; (l818 < 2); l818 = (l818 + 1)) {
			fRec1158[l818] = 0.0;
			
		}
		for (int l819 = 0; (l819 < 2); l819 = (l819 + 1)) {
			fRec1156[l819] = 0.0;
			
		}
		for (int l820 = 0; (l820 < 2); l820 = (l820 + 1)) {
			fRec1182[l820] = 0.0;
			
		}
		for (int l821 = 0; (l821 < 2); l821 = (l821 + 1)) {
			fRec1180[l821] = 0.0;
			
		}
		for (int l822 = 0; (l822 < 2); l822 = (l822 + 1)) {
			fRec1179[l822] = 0.0;
			
		}
		for (int l823 = 0; (l823 < 2); l823 = (l823 + 1)) {
			fRec1177[l823] = 0.0;
			
		}
		for (int l824 = 0; (l824 < 2); l824 = (l824 + 1)) {
			fRec1176[l824] = 0.0;
			
		}
		for (int l825 = 0; (l825 < 2); l825 = (l825 + 1)) {
			fRec1174[l825] = 0.0;
			
		}
		for (int l826 = 0; (l826 < 2); l826 = (l826 + 1)) {
			fRec1173[l826] = 0.0;
			
		}
		for (int l827 = 0; (l827 < 2); l827 = (l827 + 1)) {
			fRec1171[l827] = 0.0;
			
		}
		for (int l828 = 0; (l828 < 2); l828 = (l828 + 1)) {
			fRec1191[l828] = 0.0;
			
		}
		for (int l829 = 0; (l829 < 2); l829 = (l829 + 1)) {
			fRec1189[l829] = 0.0;
			
		}
		for (int l830 = 0; (l830 < 2); l830 = (l830 + 1)) {
			fRec1188[l830] = 0.0;
			
		}
		for (int l831 = 0; (l831 < 2); l831 = (l831 + 1)) {
			fRec1186[l831] = 0.0;
			
		}
		for (int l832 = 0; (l832 < 2); l832 = (l832 + 1)) {
			fRec1185[l832] = 0.0;
			
		}
		for (int l833 = 0; (l833 < 2); l833 = (l833 + 1)) {
			fRec1183[l833] = 0.0;
			
		}
		for (int l834 = 0; (l834 < 2); l834 = (l834 + 1)) {
			fRec1194[l834] = 0.0;
			
		}
		for (int l835 = 0; (l835 < 2); l835 = (l835 + 1)) {
			fRec1192[l835] = 0.0;
			
		}
		for (int l836 = 0; (l836 < 2); l836 = (l836 + 1)) {
			fRec1200[l836] = 0.0;
			
		}
		for (int l837 = 0; (l837 < 2); l837 = (l837 + 1)) {
			fRec1198[l837] = 0.0;
			
		}
		for (int l838 = 0; (l838 < 2); l838 = (l838 + 1)) {
			fRec1197[l838] = 0.0;
			
		}
		for (int l839 = 0; (l839 < 2); l839 = (l839 + 1)) {
			fRec1195[l839] = 0.0;
			
		}
		for (int l840 = 0; (l840 < 512); l840 = (l840 + 1)) {
			fVec17[l840] = 0.0;
			
		}
		for (int l841 = 0; (l841 < 2); l841 = (l841 + 1)) {
			fRec1218[l841] = 0.0;
			
		}
		for (int l842 = 0; (l842 < 2); l842 = (l842 + 1)) {
			fRec1216[l842] = 0.0;
			
		}
		for (int l843 = 0; (l843 < 2); l843 = (l843 + 1)) {
			fRec1215[l843] = 0.0;
			
		}
		for (int l844 = 0; (l844 < 2); l844 = (l844 + 1)) {
			fRec1213[l844] = 0.0;
			
		}
		for (int l845 = 0; (l845 < 2); l845 = (l845 + 1)) {
			fRec1212[l845] = 0.0;
			
		}
		for (int l846 = 0; (l846 < 2); l846 = (l846 + 1)) {
			fRec1210[l846] = 0.0;
			
		}
		for (int l847 = 0; (l847 < 2); l847 = (l847 + 1)) {
			fRec1209[l847] = 0.0;
			
		}
		for (int l848 = 0; (l848 < 2); l848 = (l848 + 1)) {
			fRec1207[l848] = 0.0;
			
		}
		for (int l849 = 0; (l849 < 2); l849 = (l849 + 1)) {
			fRec1206[l849] = 0.0;
			
		}
		for (int l850 = 0; (l850 < 2); l850 = (l850 + 1)) {
			fRec1204[l850] = 0.0;
			
		}
		for (int l851 = 0; (l851 < 2); l851 = (l851 + 1)) {
			fRec1203[l851] = 0.0;
			
		}
		for (int l852 = 0; (l852 < 2); l852 = (l852 + 1)) {
			fRec1201[l852] = 0.0;
			
		}
		for (int l853 = 0; (l853 < 2); l853 = (l853 + 1)) {
			fRec1233[l853] = 0.0;
			
		}
		for (int l854 = 0; (l854 < 2); l854 = (l854 + 1)) {
			fRec1231[l854] = 0.0;
			
		}
		for (int l855 = 0; (l855 < 2); l855 = (l855 + 1)) {
			fRec1230[l855] = 0.0;
			
		}
		for (int l856 = 0; (l856 < 2); l856 = (l856 + 1)) {
			fRec1228[l856] = 0.0;
			
		}
		for (int l857 = 0; (l857 < 2); l857 = (l857 + 1)) {
			fRec1227[l857] = 0.0;
			
		}
		for (int l858 = 0; (l858 < 2); l858 = (l858 + 1)) {
			fRec1225[l858] = 0.0;
			
		}
		for (int l859 = 0; (l859 < 2); l859 = (l859 + 1)) {
			fRec1224[l859] = 0.0;
			
		}
		for (int l860 = 0; (l860 < 2); l860 = (l860 + 1)) {
			fRec1222[l860] = 0.0;
			
		}
		for (int l861 = 0; (l861 < 2); l861 = (l861 + 1)) {
			fRec1221[l861] = 0.0;
			
		}
		for (int l862 = 0; (l862 < 2); l862 = (l862 + 1)) {
			fRec1219[l862] = 0.0;
			
		}
		for (int l863 = 0; (l863 < 2); l863 = (l863 + 1)) {
			fRec1245[l863] = 0.0;
			
		}
		for (int l864 = 0; (l864 < 2); l864 = (l864 + 1)) {
			fRec1243[l864] = 0.0;
			
		}
		for (int l865 = 0; (l865 < 2); l865 = (l865 + 1)) {
			fRec1242[l865] = 0.0;
			
		}
		for (int l866 = 0; (l866 < 2); l866 = (l866 + 1)) {
			fRec1240[l866] = 0.0;
			
		}
		for (int l867 = 0; (l867 < 2); l867 = (l867 + 1)) {
			fRec1239[l867] = 0.0;
			
		}
		for (int l868 = 0; (l868 < 2); l868 = (l868 + 1)) {
			fRec1237[l868] = 0.0;
			
		}
		for (int l869 = 0; (l869 < 2); l869 = (l869 + 1)) {
			fRec1236[l869] = 0.0;
			
		}
		for (int l870 = 0; (l870 < 2); l870 = (l870 + 1)) {
			fRec1234[l870] = 0.0;
			
		}
		for (int l871 = 0; (l871 < 2); l871 = (l871 + 1)) {
			fRec1254[l871] = 0.0;
			
		}
		for (int l872 = 0; (l872 < 2); l872 = (l872 + 1)) {
			fRec1252[l872] = 0.0;
			
		}
		for (int l873 = 0; (l873 < 2); l873 = (l873 + 1)) {
			fRec1251[l873] = 0.0;
			
		}
		for (int l874 = 0; (l874 < 2); l874 = (l874 + 1)) {
			fRec1249[l874] = 0.0;
			
		}
		for (int l875 = 0; (l875 < 2); l875 = (l875 + 1)) {
			fRec1248[l875] = 0.0;
			
		}
		for (int l876 = 0; (l876 < 2); l876 = (l876 + 1)) {
			fRec1246[l876] = 0.0;
			
		}
		for (int l877 = 0; (l877 < 2); l877 = (l877 + 1)) {
			fRec1257[l877] = 0.0;
			
		}
		for (int l878 = 0; (l878 < 2); l878 = (l878 + 1)) {
			fRec1255[l878] = 0.0;
			
		}
		for (int l879 = 0; (l879 < 2); l879 = (l879 + 1)) {
			fRec1263[l879] = 0.0;
			
		}
		for (int l880 = 0; (l880 < 2); l880 = (l880 + 1)) {
			fRec1261[l880] = 0.0;
			
		}
		for (int l881 = 0; (l881 < 2); l881 = (l881 + 1)) {
			fRec1260[l881] = 0.0;
			
		}
		for (int l882 = 0; (l882 < 2); l882 = (l882 + 1)) {
			fRec1258[l882] = 0.0;
			
		}
		for (int l883 = 0; (l883 < 512); l883 = (l883 + 1)) {
			fVec18[l883] = 0.0;
			
		}
		for (int l884 = 0; (l884 < 2); l884 = (l884 + 1)) {
			fRec1278[l884] = 0.0;
			
		}
		for (int l885 = 0; (l885 < 2); l885 = (l885 + 1)) {
			fRec1276[l885] = 0.0;
			
		}
		for (int l886 = 0; (l886 < 2); l886 = (l886 + 1)) {
			fRec1275[l886] = 0.0;
			
		}
		for (int l887 = 0; (l887 < 2); l887 = (l887 + 1)) {
			fRec1273[l887] = 0.0;
			
		}
		for (int l888 = 0; (l888 < 2); l888 = (l888 + 1)) {
			fRec1272[l888] = 0.0;
			
		}
		for (int l889 = 0; (l889 < 2); l889 = (l889 + 1)) {
			fRec1270[l889] = 0.0;
			
		}
		for (int l890 = 0; (l890 < 2); l890 = (l890 + 1)) {
			fRec1269[l890] = 0.0;
			
		}
		for (int l891 = 0; (l891 < 2); l891 = (l891 + 1)) {
			fRec1267[l891] = 0.0;
			
		}
		for (int l892 = 0; (l892 < 2); l892 = (l892 + 1)) {
			fRec1266[l892] = 0.0;
			
		}
		for (int l893 = 0; (l893 < 2); l893 = (l893 + 1)) {
			fRec1264[l893] = 0.0;
			
		}
		for (int l894 = 0; (l894 < 2); l894 = (l894 + 1)) {
			fRec1290[l894] = 0.0;
			
		}
		for (int l895 = 0; (l895 < 2); l895 = (l895 + 1)) {
			fRec1288[l895] = 0.0;
			
		}
		for (int l896 = 0; (l896 < 2); l896 = (l896 + 1)) {
			fRec1287[l896] = 0.0;
			
		}
		for (int l897 = 0; (l897 < 2); l897 = (l897 + 1)) {
			fRec1285[l897] = 0.0;
			
		}
		for (int l898 = 0; (l898 < 2); l898 = (l898 + 1)) {
			fRec1284[l898] = 0.0;
			
		}
		for (int l899 = 0; (l899 < 2); l899 = (l899 + 1)) {
			fRec1282[l899] = 0.0;
			
		}
		for (int l900 = 0; (l900 < 2); l900 = (l900 + 1)) {
			fRec1281[l900] = 0.0;
			
		}
		for (int l901 = 0; (l901 < 2); l901 = (l901 + 1)) {
			fRec1279[l901] = 0.0;
			
		}
		for (int l902 = 0; (l902 < 2); l902 = (l902 + 1)) {
			fRec1299[l902] = 0.0;
			
		}
		for (int l903 = 0; (l903 < 2); l903 = (l903 + 1)) {
			fRec1297[l903] = 0.0;
			
		}
		for (int l904 = 0; (l904 < 2); l904 = (l904 + 1)) {
			fRec1296[l904] = 0.0;
			
		}
		for (int l905 = 0; (l905 < 2); l905 = (l905 + 1)) {
			fRec1294[l905] = 0.0;
			
		}
		for (int l906 = 0; (l906 < 2); l906 = (l906 + 1)) {
			fRec1293[l906] = 0.0;
			
		}
		for (int l907 = 0; (l907 < 2); l907 = (l907 + 1)) {
			fRec1291[l907] = 0.0;
			
		}
		for (int l908 = 0; (l908 < 2); l908 = (l908 + 1)) {
			fRec1305[l908] = 0.0;
			
		}
		for (int l909 = 0; (l909 < 2); l909 = (l909 + 1)) {
			fRec1303[l909] = 0.0;
			
		}
		for (int l910 = 0; (l910 < 2); l910 = (l910 + 1)) {
			fRec1302[l910] = 0.0;
			
		}
		for (int l911 = 0; (l911 < 2); l911 = (l911 + 1)) {
			fRec1300[l911] = 0.0;
			
		}
		for (int l912 = 0; (l912 < 2); l912 = (l912 + 1)) {
			fRec1323[l912] = 0.0;
			
		}
		for (int l913 = 0; (l913 < 2); l913 = (l913 + 1)) {
			fRec1321[l913] = 0.0;
			
		}
		for (int l914 = 0; (l914 < 2); l914 = (l914 + 1)) {
			fRec1320[l914] = 0.0;
			
		}
		for (int l915 = 0; (l915 < 2); l915 = (l915 + 1)) {
			fRec1318[l915] = 0.0;
			
		}
		for (int l916 = 0; (l916 < 2); l916 = (l916 + 1)) {
			fRec1317[l916] = 0.0;
			
		}
		for (int l917 = 0; (l917 < 2); l917 = (l917 + 1)) {
			fRec1315[l917] = 0.0;
			
		}
		for (int l918 = 0; (l918 < 2); l918 = (l918 + 1)) {
			fRec1314[l918] = 0.0;
			
		}
		for (int l919 = 0; (l919 < 2); l919 = (l919 + 1)) {
			fRec1312[l919] = 0.0;
			
		}
		for (int l920 = 0; (l920 < 2); l920 = (l920 + 1)) {
			fRec1311[l920] = 0.0;
			
		}
		for (int l921 = 0; (l921 < 2); l921 = (l921 + 1)) {
			fRec1309[l921] = 0.0;
			
		}
		for (int l922 = 0; (l922 < 2); l922 = (l922 + 1)) {
			fRec1308[l922] = 0.0;
			
		}
		for (int l923 = 0; (l923 < 2); l923 = (l923 + 1)) {
			fRec1306[l923] = 0.0;
			
		}
		for (int l924 = 0; (l924 < 2); l924 = (l924 + 1)) {
			fRec1326[l924] = 0.0;
			
		}
		for (int l925 = 0; (l925 < 2); l925 = (l925 + 1)) {
			fRec1324[l925] = 0.0;
			
		}
		for (int l926 = 0; (l926 < 512); l926 = (l926 + 1)) {
			fVec19[l926] = 0.0;
			
		}
		for (int l927 = 0; (l927 < 2); l927 = (l927 + 1)) {
			fRec1344[l927] = 0.0;
			
		}
		for (int l928 = 0; (l928 < 2); l928 = (l928 + 1)) {
			fRec1342[l928] = 0.0;
			
		}
		for (int l929 = 0; (l929 < 2); l929 = (l929 + 1)) {
			fRec1341[l929] = 0.0;
			
		}
		for (int l930 = 0; (l930 < 2); l930 = (l930 + 1)) {
			fRec1339[l930] = 0.0;
			
		}
		for (int l931 = 0; (l931 < 2); l931 = (l931 + 1)) {
			fRec1338[l931] = 0.0;
			
		}
		for (int l932 = 0; (l932 < 2); l932 = (l932 + 1)) {
			fRec1336[l932] = 0.0;
			
		}
		for (int l933 = 0; (l933 < 2); l933 = (l933 + 1)) {
			fRec1335[l933] = 0.0;
			
		}
		for (int l934 = 0; (l934 < 2); l934 = (l934 + 1)) {
			fRec1333[l934] = 0.0;
			
		}
		for (int l935 = 0; (l935 < 2); l935 = (l935 + 1)) {
			fRec1332[l935] = 0.0;
			
		}
		for (int l936 = 0; (l936 < 2); l936 = (l936 + 1)) {
			fRec1330[l936] = 0.0;
			
		}
		for (int l937 = 0; (l937 < 2); l937 = (l937 + 1)) {
			fRec1329[l937] = 0.0;
			
		}
		for (int l938 = 0; (l938 < 2); l938 = (l938 + 1)) {
			fRec1327[l938] = 0.0;
			
		}
		for (int l939 = 0; (l939 < 2); l939 = (l939 + 1)) {
			fRec1359[l939] = 0.0;
			
		}
		for (int l940 = 0; (l940 < 2); l940 = (l940 + 1)) {
			fRec1357[l940] = 0.0;
			
		}
		for (int l941 = 0; (l941 < 2); l941 = (l941 + 1)) {
			fRec1356[l941] = 0.0;
			
		}
		for (int l942 = 0; (l942 < 2); l942 = (l942 + 1)) {
			fRec1354[l942] = 0.0;
			
		}
		for (int l943 = 0; (l943 < 2); l943 = (l943 + 1)) {
			fRec1353[l943] = 0.0;
			
		}
		for (int l944 = 0; (l944 < 2); l944 = (l944 + 1)) {
			fRec1351[l944] = 0.0;
			
		}
		for (int l945 = 0; (l945 < 2); l945 = (l945 + 1)) {
			fRec1350[l945] = 0.0;
			
		}
		for (int l946 = 0; (l946 < 2); l946 = (l946 + 1)) {
			fRec1348[l946] = 0.0;
			
		}
		for (int l947 = 0; (l947 < 2); l947 = (l947 + 1)) {
			fRec1347[l947] = 0.0;
			
		}
		for (int l948 = 0; (l948 < 2); l948 = (l948 + 1)) {
			fRec1345[l948] = 0.0;
			
		}
		for (int l949 = 0; (l949 < 2); l949 = (l949 + 1)) {
			fRec1371[l949] = 0.0;
			
		}
		for (int l950 = 0; (l950 < 2); l950 = (l950 + 1)) {
			fRec1369[l950] = 0.0;
			
		}
		for (int l951 = 0; (l951 < 2); l951 = (l951 + 1)) {
			fRec1368[l951] = 0.0;
			
		}
		for (int l952 = 0; (l952 < 2); l952 = (l952 + 1)) {
			fRec1366[l952] = 0.0;
			
		}
		for (int l953 = 0; (l953 < 2); l953 = (l953 + 1)) {
			fRec1365[l953] = 0.0;
			
		}
		for (int l954 = 0; (l954 < 2); l954 = (l954 + 1)) {
			fRec1363[l954] = 0.0;
			
		}
		for (int l955 = 0; (l955 < 2); l955 = (l955 + 1)) {
			fRec1362[l955] = 0.0;
			
		}
		for (int l956 = 0; (l956 < 2); l956 = (l956 + 1)) {
			fRec1360[l956] = 0.0;
			
		}
		for (int l957 = 0; (l957 < 2); l957 = (l957 + 1)) {
			fRec1380[l957] = 0.0;
			
		}
		for (int l958 = 0; (l958 < 2); l958 = (l958 + 1)) {
			fRec1378[l958] = 0.0;
			
		}
		for (int l959 = 0; (l959 < 2); l959 = (l959 + 1)) {
			fRec1377[l959] = 0.0;
			
		}
		for (int l960 = 0; (l960 < 2); l960 = (l960 + 1)) {
			fRec1375[l960] = 0.0;
			
		}
		for (int l961 = 0; (l961 < 2); l961 = (l961 + 1)) {
			fRec1374[l961] = 0.0;
			
		}
		for (int l962 = 0; (l962 < 2); l962 = (l962 + 1)) {
			fRec1372[l962] = 0.0;
			
		}
		for (int l963 = 0; (l963 < 2); l963 = (l963 + 1)) {
			fRec1383[l963] = 0.0;
			
		}
		for (int l964 = 0; (l964 < 2); l964 = (l964 + 1)) {
			fRec1381[l964] = 0.0;
			
		}
		for (int l965 = 0; (l965 < 2); l965 = (l965 + 1)) {
			fRec1389[l965] = 0.0;
			
		}
		for (int l966 = 0; (l966 < 2); l966 = (l966 + 1)) {
			fRec1387[l966] = 0.0;
			
		}
		for (int l967 = 0; (l967 < 2); l967 = (l967 + 1)) {
			fRec1386[l967] = 0.0;
			
		}
		for (int l968 = 0; (l968 < 2); l968 = (l968 + 1)) {
			fRec1384[l968] = 0.0;
			
		}
		for (int l969 = 0; (l969 < 512); l969 = (l969 + 1)) {
			fVec20[l969] = 0.0;
			
		}
		for (int l970 = 0; (l970 < 2); l970 = (l970 + 1)) {
			fRec1407[l970] = 0.0;
			
		}
		for (int l971 = 0; (l971 < 2); l971 = (l971 + 1)) {
			fRec1405[l971] = 0.0;
			
		}
		for (int l972 = 0; (l972 < 2); l972 = (l972 + 1)) {
			fRec1404[l972] = 0.0;
			
		}
		for (int l973 = 0; (l973 < 2); l973 = (l973 + 1)) {
			fRec1402[l973] = 0.0;
			
		}
		for (int l974 = 0; (l974 < 2); l974 = (l974 + 1)) {
			fRec1401[l974] = 0.0;
			
		}
		for (int l975 = 0; (l975 < 2); l975 = (l975 + 1)) {
			fRec1399[l975] = 0.0;
			
		}
		for (int l976 = 0; (l976 < 2); l976 = (l976 + 1)) {
			fRec1398[l976] = 0.0;
			
		}
		for (int l977 = 0; (l977 < 2); l977 = (l977 + 1)) {
			fRec1396[l977] = 0.0;
			
		}
		for (int l978 = 0; (l978 < 2); l978 = (l978 + 1)) {
			fRec1395[l978] = 0.0;
			
		}
		for (int l979 = 0; (l979 < 2); l979 = (l979 + 1)) {
			fRec1393[l979] = 0.0;
			
		}
		for (int l980 = 0; (l980 < 2); l980 = (l980 + 1)) {
			fRec1392[l980] = 0.0;
			
		}
		for (int l981 = 0; (l981 < 2); l981 = (l981 + 1)) {
			fRec1390[l981] = 0.0;
			
		}
		for (int l982 = 0; (l982 < 2); l982 = (l982 + 1)) {
			fRec1422[l982] = 0.0;
			
		}
		for (int l983 = 0; (l983 < 2); l983 = (l983 + 1)) {
			fRec1420[l983] = 0.0;
			
		}
		for (int l984 = 0; (l984 < 2); l984 = (l984 + 1)) {
			fRec1419[l984] = 0.0;
			
		}
		for (int l985 = 0; (l985 < 2); l985 = (l985 + 1)) {
			fRec1417[l985] = 0.0;
			
		}
		for (int l986 = 0; (l986 < 2); l986 = (l986 + 1)) {
			fRec1416[l986] = 0.0;
			
		}
		for (int l987 = 0; (l987 < 2); l987 = (l987 + 1)) {
			fRec1414[l987] = 0.0;
			
		}
		for (int l988 = 0; (l988 < 2); l988 = (l988 + 1)) {
			fRec1413[l988] = 0.0;
			
		}
		for (int l989 = 0; (l989 < 2); l989 = (l989 + 1)) {
			fRec1411[l989] = 0.0;
			
		}
		for (int l990 = 0; (l990 < 2); l990 = (l990 + 1)) {
			fRec1410[l990] = 0.0;
			
		}
		for (int l991 = 0; (l991 < 2); l991 = (l991 + 1)) {
			fRec1408[l991] = 0.0;
			
		}
		for (int l992 = 0; (l992 < 2); l992 = (l992 + 1)) {
			fRec1434[l992] = 0.0;
			
		}
		for (int l993 = 0; (l993 < 2); l993 = (l993 + 1)) {
			fRec1432[l993] = 0.0;
			
		}
		for (int l994 = 0; (l994 < 2); l994 = (l994 + 1)) {
			fRec1431[l994] = 0.0;
			
		}
		for (int l995 = 0; (l995 < 2); l995 = (l995 + 1)) {
			fRec1429[l995] = 0.0;
			
		}
		for (int l996 = 0; (l996 < 2); l996 = (l996 + 1)) {
			fRec1428[l996] = 0.0;
			
		}
		for (int l997 = 0; (l997 < 2); l997 = (l997 + 1)) {
			fRec1426[l997] = 0.0;
			
		}
		for (int l998 = 0; (l998 < 2); l998 = (l998 + 1)) {
			fRec1425[l998] = 0.0;
			
		}
		for (int l999 = 0; (l999 < 2); l999 = (l999 + 1)) {
			fRec1423[l999] = 0.0;
			
		}
		for (int l1000 = 0; (l1000 < 2); l1000 = (l1000 + 1)) {
			fRec1443[l1000] = 0.0;
			
		}
		for (int l1001 = 0; (l1001 < 2); l1001 = (l1001 + 1)) {
			fRec1441[l1001] = 0.0;
			
		}
		for (int l1002 = 0; (l1002 < 2); l1002 = (l1002 + 1)) {
			fRec1440[l1002] = 0.0;
			
		}
		for (int l1003 = 0; (l1003 < 2); l1003 = (l1003 + 1)) {
			fRec1438[l1003] = 0.0;
			
		}
		for (int l1004 = 0; (l1004 < 2); l1004 = (l1004 + 1)) {
			fRec1437[l1004] = 0.0;
			
		}
		for (int l1005 = 0; (l1005 < 2); l1005 = (l1005 + 1)) {
			fRec1435[l1005] = 0.0;
			
		}
		for (int l1006 = 0; (l1006 < 2); l1006 = (l1006 + 1)) {
			fRec1446[l1006] = 0.0;
			
		}
		for (int l1007 = 0; (l1007 < 2); l1007 = (l1007 + 1)) {
			fRec1444[l1007] = 0.0;
			
		}
		for (int l1008 = 0; (l1008 < 2); l1008 = (l1008 + 1)) {
			fRec1452[l1008] = 0.0;
			
		}
		for (int l1009 = 0; (l1009 < 2); l1009 = (l1009 + 1)) {
			fRec1450[l1009] = 0.0;
			
		}
		for (int l1010 = 0; (l1010 < 2); l1010 = (l1010 + 1)) {
			fRec1449[l1010] = 0.0;
			
		}
		for (int l1011 = 0; (l1011 < 2); l1011 = (l1011 + 1)) {
			fRec1447[l1011] = 0.0;
			
		}
		for (int l1012 = 0; (l1012 < 512); l1012 = (l1012 + 1)) {
			fVec21[l1012] = 0.0;
			
		}
		for (int l1013 = 0; (l1013 < 2); l1013 = (l1013 + 1)) {
			fRec1470[l1013] = 0.0;
			
		}
		for (int l1014 = 0; (l1014 < 2); l1014 = (l1014 + 1)) {
			fRec1468[l1014] = 0.0;
			
		}
		for (int l1015 = 0; (l1015 < 2); l1015 = (l1015 + 1)) {
			fRec1467[l1015] = 0.0;
			
		}
		for (int l1016 = 0; (l1016 < 2); l1016 = (l1016 + 1)) {
			fRec1465[l1016] = 0.0;
			
		}
		for (int l1017 = 0; (l1017 < 2); l1017 = (l1017 + 1)) {
			fRec1464[l1017] = 0.0;
			
		}
		for (int l1018 = 0; (l1018 < 2); l1018 = (l1018 + 1)) {
			fRec1462[l1018] = 0.0;
			
		}
		for (int l1019 = 0; (l1019 < 2); l1019 = (l1019 + 1)) {
			fRec1461[l1019] = 0.0;
			
		}
		for (int l1020 = 0; (l1020 < 2); l1020 = (l1020 + 1)) {
			fRec1459[l1020] = 0.0;
			
		}
		for (int l1021 = 0; (l1021 < 2); l1021 = (l1021 + 1)) {
			fRec1458[l1021] = 0.0;
			
		}
		for (int l1022 = 0; (l1022 < 2); l1022 = (l1022 + 1)) {
			fRec1456[l1022] = 0.0;
			
		}
		for (int l1023 = 0; (l1023 < 2); l1023 = (l1023 + 1)) {
			fRec1455[l1023] = 0.0;
			
		}
		for (int l1024 = 0; (l1024 < 2); l1024 = (l1024 + 1)) {
			fRec1453[l1024] = 0.0;
			
		}
		for (int l1025 = 0; (l1025 < 2); l1025 = (l1025 + 1)) {
			fRec1485[l1025] = 0.0;
			
		}
		for (int l1026 = 0; (l1026 < 2); l1026 = (l1026 + 1)) {
			fRec1483[l1026] = 0.0;
			
		}
		for (int l1027 = 0; (l1027 < 2); l1027 = (l1027 + 1)) {
			fRec1482[l1027] = 0.0;
			
		}
		for (int l1028 = 0; (l1028 < 2); l1028 = (l1028 + 1)) {
			fRec1480[l1028] = 0.0;
			
		}
		for (int l1029 = 0; (l1029 < 2); l1029 = (l1029 + 1)) {
			fRec1479[l1029] = 0.0;
			
		}
		for (int l1030 = 0; (l1030 < 2); l1030 = (l1030 + 1)) {
			fRec1477[l1030] = 0.0;
			
		}
		for (int l1031 = 0; (l1031 < 2); l1031 = (l1031 + 1)) {
			fRec1476[l1031] = 0.0;
			
		}
		for (int l1032 = 0; (l1032 < 2); l1032 = (l1032 + 1)) {
			fRec1474[l1032] = 0.0;
			
		}
		for (int l1033 = 0; (l1033 < 2); l1033 = (l1033 + 1)) {
			fRec1473[l1033] = 0.0;
			
		}
		for (int l1034 = 0; (l1034 < 2); l1034 = (l1034 + 1)) {
			fRec1471[l1034] = 0.0;
			
		}
		for (int l1035 = 0; (l1035 < 2); l1035 = (l1035 + 1)) {
			fRec1497[l1035] = 0.0;
			
		}
		for (int l1036 = 0; (l1036 < 2); l1036 = (l1036 + 1)) {
			fRec1495[l1036] = 0.0;
			
		}
		for (int l1037 = 0; (l1037 < 2); l1037 = (l1037 + 1)) {
			fRec1494[l1037] = 0.0;
			
		}
		for (int l1038 = 0; (l1038 < 2); l1038 = (l1038 + 1)) {
			fRec1492[l1038] = 0.0;
			
		}
		for (int l1039 = 0; (l1039 < 2); l1039 = (l1039 + 1)) {
			fRec1491[l1039] = 0.0;
			
		}
		for (int l1040 = 0; (l1040 < 2); l1040 = (l1040 + 1)) {
			fRec1489[l1040] = 0.0;
			
		}
		for (int l1041 = 0; (l1041 < 2); l1041 = (l1041 + 1)) {
			fRec1488[l1041] = 0.0;
			
		}
		for (int l1042 = 0; (l1042 < 2); l1042 = (l1042 + 1)) {
			fRec1486[l1042] = 0.0;
			
		}
		for (int l1043 = 0; (l1043 < 2); l1043 = (l1043 + 1)) {
			fRec1506[l1043] = 0.0;
			
		}
		for (int l1044 = 0; (l1044 < 2); l1044 = (l1044 + 1)) {
			fRec1504[l1044] = 0.0;
			
		}
		for (int l1045 = 0; (l1045 < 2); l1045 = (l1045 + 1)) {
			fRec1503[l1045] = 0.0;
			
		}
		for (int l1046 = 0; (l1046 < 2); l1046 = (l1046 + 1)) {
			fRec1501[l1046] = 0.0;
			
		}
		for (int l1047 = 0; (l1047 < 2); l1047 = (l1047 + 1)) {
			fRec1500[l1047] = 0.0;
			
		}
		for (int l1048 = 0; (l1048 < 2); l1048 = (l1048 + 1)) {
			fRec1498[l1048] = 0.0;
			
		}
		for (int l1049 = 0; (l1049 < 2); l1049 = (l1049 + 1)) {
			fRec1509[l1049] = 0.0;
			
		}
		for (int l1050 = 0; (l1050 < 2); l1050 = (l1050 + 1)) {
			fRec1507[l1050] = 0.0;
			
		}
		for (int l1051 = 0; (l1051 < 2); l1051 = (l1051 + 1)) {
			fRec1515[l1051] = 0.0;
			
		}
		for (int l1052 = 0; (l1052 < 2); l1052 = (l1052 + 1)) {
			fRec1513[l1052] = 0.0;
			
		}
		for (int l1053 = 0; (l1053 < 2); l1053 = (l1053 + 1)) {
			fRec1512[l1053] = 0.0;
			
		}
		for (int l1054 = 0; (l1054 < 2); l1054 = (l1054 + 1)) {
			fRec1510[l1054] = 0.0;
			
		}
		for (int l1055 = 0; (l1055 < 512); l1055 = (l1055 + 1)) {
			fVec22[l1055] = 0.0;
			
		}
		for (int l1056 = 0; (l1056 < 2); l1056 = (l1056 + 1)) {
			fRec1533[l1056] = 0.0;
			
		}
		for (int l1057 = 0; (l1057 < 2); l1057 = (l1057 + 1)) {
			fRec1531[l1057] = 0.0;
			
		}
		for (int l1058 = 0; (l1058 < 2); l1058 = (l1058 + 1)) {
			fRec1530[l1058] = 0.0;
			
		}
		for (int l1059 = 0; (l1059 < 2); l1059 = (l1059 + 1)) {
			fRec1528[l1059] = 0.0;
			
		}
		for (int l1060 = 0; (l1060 < 2); l1060 = (l1060 + 1)) {
			fRec1527[l1060] = 0.0;
			
		}
		for (int l1061 = 0; (l1061 < 2); l1061 = (l1061 + 1)) {
			fRec1525[l1061] = 0.0;
			
		}
		for (int l1062 = 0; (l1062 < 2); l1062 = (l1062 + 1)) {
			fRec1524[l1062] = 0.0;
			
		}
		for (int l1063 = 0; (l1063 < 2); l1063 = (l1063 + 1)) {
			fRec1522[l1063] = 0.0;
			
		}
		for (int l1064 = 0; (l1064 < 2); l1064 = (l1064 + 1)) {
			fRec1521[l1064] = 0.0;
			
		}
		for (int l1065 = 0; (l1065 < 2); l1065 = (l1065 + 1)) {
			fRec1519[l1065] = 0.0;
			
		}
		for (int l1066 = 0; (l1066 < 2); l1066 = (l1066 + 1)) {
			fRec1518[l1066] = 0.0;
			
		}
		for (int l1067 = 0; (l1067 < 2); l1067 = (l1067 + 1)) {
			fRec1516[l1067] = 0.0;
			
		}
		for (int l1068 = 0; (l1068 < 2); l1068 = (l1068 + 1)) {
			fRec1548[l1068] = 0.0;
			
		}
		for (int l1069 = 0; (l1069 < 2); l1069 = (l1069 + 1)) {
			fRec1546[l1069] = 0.0;
			
		}
		for (int l1070 = 0; (l1070 < 2); l1070 = (l1070 + 1)) {
			fRec1545[l1070] = 0.0;
			
		}
		for (int l1071 = 0; (l1071 < 2); l1071 = (l1071 + 1)) {
			fRec1543[l1071] = 0.0;
			
		}
		for (int l1072 = 0; (l1072 < 2); l1072 = (l1072 + 1)) {
			fRec1542[l1072] = 0.0;
			
		}
		for (int l1073 = 0; (l1073 < 2); l1073 = (l1073 + 1)) {
			fRec1540[l1073] = 0.0;
			
		}
		for (int l1074 = 0; (l1074 < 2); l1074 = (l1074 + 1)) {
			fRec1539[l1074] = 0.0;
			
		}
		for (int l1075 = 0; (l1075 < 2); l1075 = (l1075 + 1)) {
			fRec1537[l1075] = 0.0;
			
		}
		for (int l1076 = 0; (l1076 < 2); l1076 = (l1076 + 1)) {
			fRec1536[l1076] = 0.0;
			
		}
		for (int l1077 = 0; (l1077 < 2); l1077 = (l1077 + 1)) {
			fRec1534[l1077] = 0.0;
			
		}
		for (int l1078 = 0; (l1078 < 2); l1078 = (l1078 + 1)) {
			fRec1560[l1078] = 0.0;
			
		}
		for (int l1079 = 0; (l1079 < 2); l1079 = (l1079 + 1)) {
			fRec1558[l1079] = 0.0;
			
		}
		for (int l1080 = 0; (l1080 < 2); l1080 = (l1080 + 1)) {
			fRec1557[l1080] = 0.0;
			
		}
		for (int l1081 = 0; (l1081 < 2); l1081 = (l1081 + 1)) {
			fRec1555[l1081] = 0.0;
			
		}
		for (int l1082 = 0; (l1082 < 2); l1082 = (l1082 + 1)) {
			fRec1554[l1082] = 0.0;
			
		}
		for (int l1083 = 0; (l1083 < 2); l1083 = (l1083 + 1)) {
			fRec1552[l1083] = 0.0;
			
		}
		for (int l1084 = 0; (l1084 < 2); l1084 = (l1084 + 1)) {
			fRec1551[l1084] = 0.0;
			
		}
		for (int l1085 = 0; (l1085 < 2); l1085 = (l1085 + 1)) {
			fRec1549[l1085] = 0.0;
			
		}
		for (int l1086 = 0; (l1086 < 2); l1086 = (l1086 + 1)) {
			fRec1569[l1086] = 0.0;
			
		}
		for (int l1087 = 0; (l1087 < 2); l1087 = (l1087 + 1)) {
			fRec1567[l1087] = 0.0;
			
		}
		for (int l1088 = 0; (l1088 < 2); l1088 = (l1088 + 1)) {
			fRec1566[l1088] = 0.0;
			
		}
		for (int l1089 = 0; (l1089 < 2); l1089 = (l1089 + 1)) {
			fRec1564[l1089] = 0.0;
			
		}
		for (int l1090 = 0; (l1090 < 2); l1090 = (l1090 + 1)) {
			fRec1563[l1090] = 0.0;
			
		}
		for (int l1091 = 0; (l1091 < 2); l1091 = (l1091 + 1)) {
			fRec1561[l1091] = 0.0;
			
		}
		for (int l1092 = 0; (l1092 < 2); l1092 = (l1092 + 1)) {
			fRec1572[l1092] = 0.0;
			
		}
		for (int l1093 = 0; (l1093 < 2); l1093 = (l1093 + 1)) {
			fRec1570[l1093] = 0.0;
			
		}
		for (int l1094 = 0; (l1094 < 2); l1094 = (l1094 + 1)) {
			fRec1578[l1094] = 0.0;
			
		}
		for (int l1095 = 0; (l1095 < 2); l1095 = (l1095 + 1)) {
			fRec1576[l1095] = 0.0;
			
		}
		for (int l1096 = 0; (l1096 < 2); l1096 = (l1096 + 1)) {
			fRec1575[l1096] = 0.0;
			
		}
		for (int l1097 = 0; (l1097 < 2); l1097 = (l1097 + 1)) {
			fRec1573[l1097] = 0.0;
			
		}
		for (int l1098 = 0; (l1098 < 512); l1098 = (l1098 + 1)) {
			fVec23[l1098] = 0.0;
			
		}
		for (int l1099 = 0; (l1099 < 2); l1099 = (l1099 + 1)) {
			fRec1596[l1099] = 0.0;
			
		}
		for (int l1100 = 0; (l1100 < 2); l1100 = (l1100 + 1)) {
			fRec1594[l1100] = 0.0;
			
		}
		for (int l1101 = 0; (l1101 < 2); l1101 = (l1101 + 1)) {
			fRec1593[l1101] = 0.0;
			
		}
		for (int l1102 = 0; (l1102 < 2); l1102 = (l1102 + 1)) {
			fRec1591[l1102] = 0.0;
			
		}
		for (int l1103 = 0; (l1103 < 2); l1103 = (l1103 + 1)) {
			fRec1590[l1103] = 0.0;
			
		}
		for (int l1104 = 0; (l1104 < 2); l1104 = (l1104 + 1)) {
			fRec1588[l1104] = 0.0;
			
		}
		for (int l1105 = 0; (l1105 < 2); l1105 = (l1105 + 1)) {
			fRec1587[l1105] = 0.0;
			
		}
		for (int l1106 = 0; (l1106 < 2); l1106 = (l1106 + 1)) {
			fRec1585[l1106] = 0.0;
			
		}
		for (int l1107 = 0; (l1107 < 2); l1107 = (l1107 + 1)) {
			fRec1584[l1107] = 0.0;
			
		}
		for (int l1108 = 0; (l1108 < 2); l1108 = (l1108 + 1)) {
			fRec1582[l1108] = 0.0;
			
		}
		for (int l1109 = 0; (l1109 < 2); l1109 = (l1109 + 1)) {
			fRec1581[l1109] = 0.0;
			
		}
		for (int l1110 = 0; (l1110 < 2); l1110 = (l1110 + 1)) {
			fRec1579[l1110] = 0.0;
			
		}
		for (int l1111 = 0; (l1111 < 2); l1111 = (l1111 + 1)) {
			fRec1608[l1111] = 0.0;
			
		}
		for (int l1112 = 0; (l1112 < 2); l1112 = (l1112 + 1)) {
			fRec1606[l1112] = 0.0;
			
		}
		for (int l1113 = 0; (l1113 < 2); l1113 = (l1113 + 1)) {
			fRec1605[l1113] = 0.0;
			
		}
		for (int l1114 = 0; (l1114 < 2); l1114 = (l1114 + 1)) {
			fRec1603[l1114] = 0.0;
			
		}
		for (int l1115 = 0; (l1115 < 2); l1115 = (l1115 + 1)) {
			fRec1602[l1115] = 0.0;
			
		}
		for (int l1116 = 0; (l1116 < 2); l1116 = (l1116 + 1)) {
			fRec1600[l1116] = 0.0;
			
		}
		for (int l1117 = 0; (l1117 < 2); l1117 = (l1117 + 1)) {
			fRec1599[l1117] = 0.0;
			
		}
		for (int l1118 = 0; (l1118 < 2); l1118 = (l1118 + 1)) {
			fRec1597[l1118] = 0.0;
			
		}
		for (int l1119 = 0; (l1119 < 2); l1119 = (l1119 + 1)) {
			fRec1617[l1119] = 0.0;
			
		}
		for (int l1120 = 0; (l1120 < 2); l1120 = (l1120 + 1)) {
			fRec1615[l1120] = 0.0;
			
		}
		for (int l1121 = 0; (l1121 < 2); l1121 = (l1121 + 1)) {
			fRec1614[l1121] = 0.0;
			
		}
		for (int l1122 = 0; (l1122 < 2); l1122 = (l1122 + 1)) {
			fRec1612[l1122] = 0.0;
			
		}
		for (int l1123 = 0; (l1123 < 2); l1123 = (l1123 + 1)) {
			fRec1611[l1123] = 0.0;
			
		}
		for (int l1124 = 0; (l1124 < 2); l1124 = (l1124 + 1)) {
			fRec1609[l1124] = 0.0;
			
		}
		for (int l1125 = 0; (l1125 < 2); l1125 = (l1125 + 1)) {
			fRec1620[l1125] = 0.0;
			
		}
		for (int l1126 = 0; (l1126 < 2); l1126 = (l1126 + 1)) {
			fRec1618[l1126] = 0.0;
			
		}
		for (int l1127 = 0; (l1127 < 2); l1127 = (l1127 + 1)) {
			fRec1626[l1127] = 0.0;
			
		}
		for (int l1128 = 0; (l1128 < 2); l1128 = (l1128 + 1)) {
			fRec1624[l1128] = 0.0;
			
		}
		for (int l1129 = 0; (l1129 < 2); l1129 = (l1129 + 1)) {
			fRec1623[l1129] = 0.0;
			
		}
		for (int l1130 = 0; (l1130 < 2); l1130 = (l1130 + 1)) {
			fRec1621[l1130] = 0.0;
			
		}
		for (int l1131 = 0; (l1131 < 2); l1131 = (l1131 + 1)) {
			fRec1641[l1131] = 0.0;
			
		}
		for (int l1132 = 0; (l1132 < 2); l1132 = (l1132 + 1)) {
			fRec1639[l1132] = 0.0;
			
		}
		for (int l1133 = 0; (l1133 < 2); l1133 = (l1133 + 1)) {
			fRec1638[l1133] = 0.0;
			
		}
		for (int l1134 = 0; (l1134 < 2); l1134 = (l1134 + 1)) {
			fRec1636[l1134] = 0.0;
			
		}
		for (int l1135 = 0; (l1135 < 2); l1135 = (l1135 + 1)) {
			fRec1635[l1135] = 0.0;
			
		}
		for (int l1136 = 0; (l1136 < 2); l1136 = (l1136 + 1)) {
			fRec1633[l1136] = 0.0;
			
		}
		for (int l1137 = 0; (l1137 < 2); l1137 = (l1137 + 1)) {
			fRec1632[l1137] = 0.0;
			
		}
		for (int l1138 = 0; (l1138 < 2); l1138 = (l1138 + 1)) {
			fRec1630[l1138] = 0.0;
			
		}
		for (int l1139 = 0; (l1139 < 2); l1139 = (l1139 + 1)) {
			fRec1629[l1139] = 0.0;
			
		}
		for (int l1140 = 0; (l1140 < 2); l1140 = (l1140 + 1)) {
			fRec1627[l1140] = 0.0;
			
		}
		for (int l1141 = 0; (l1141 < 256); l1141 = (l1141 + 1)) {
			fVec24[l1141] = 0.0;
			
		}
		for (int l1142 = 0; (l1142 < 2); l1142 = (l1142 + 1)) {
			fRec1659[l1142] = 0.0;
			
		}
		for (int l1143 = 0; (l1143 < 2); l1143 = (l1143 + 1)) {
			fRec1657[l1143] = 0.0;
			
		}
		for (int l1144 = 0; (l1144 < 2); l1144 = (l1144 + 1)) {
			fRec1656[l1144] = 0.0;
			
		}
		for (int l1145 = 0; (l1145 < 2); l1145 = (l1145 + 1)) {
			fRec1654[l1145] = 0.0;
			
		}
		for (int l1146 = 0; (l1146 < 2); l1146 = (l1146 + 1)) {
			fRec1653[l1146] = 0.0;
			
		}
		for (int l1147 = 0; (l1147 < 2); l1147 = (l1147 + 1)) {
			fRec1651[l1147] = 0.0;
			
		}
		for (int l1148 = 0; (l1148 < 2); l1148 = (l1148 + 1)) {
			fRec1650[l1148] = 0.0;
			
		}
		for (int l1149 = 0; (l1149 < 2); l1149 = (l1149 + 1)) {
			fRec1648[l1149] = 0.0;
			
		}
		for (int l1150 = 0; (l1150 < 2); l1150 = (l1150 + 1)) {
			fRec1647[l1150] = 0.0;
			
		}
		for (int l1151 = 0; (l1151 < 2); l1151 = (l1151 + 1)) {
			fRec1645[l1151] = 0.0;
			
		}
		for (int l1152 = 0; (l1152 < 2); l1152 = (l1152 + 1)) {
			fRec1644[l1152] = 0.0;
			
		}
		for (int l1153 = 0; (l1153 < 2); l1153 = (l1153 + 1)) {
			fRec1642[l1153] = 0.0;
			
		}
		for (int l1154 = 0; (l1154 < 2); l1154 = (l1154 + 1)) {
			fRec1674[l1154] = 0.0;
			
		}
		for (int l1155 = 0; (l1155 < 2); l1155 = (l1155 + 1)) {
			fRec1672[l1155] = 0.0;
			
		}
		for (int l1156 = 0; (l1156 < 2); l1156 = (l1156 + 1)) {
			fRec1671[l1156] = 0.0;
			
		}
		for (int l1157 = 0; (l1157 < 2); l1157 = (l1157 + 1)) {
			fRec1669[l1157] = 0.0;
			
		}
		for (int l1158 = 0; (l1158 < 2); l1158 = (l1158 + 1)) {
			fRec1668[l1158] = 0.0;
			
		}
		for (int l1159 = 0; (l1159 < 2); l1159 = (l1159 + 1)) {
			fRec1666[l1159] = 0.0;
			
		}
		for (int l1160 = 0; (l1160 < 2); l1160 = (l1160 + 1)) {
			fRec1665[l1160] = 0.0;
			
		}
		for (int l1161 = 0; (l1161 < 2); l1161 = (l1161 + 1)) {
			fRec1663[l1161] = 0.0;
			
		}
		for (int l1162 = 0; (l1162 < 2); l1162 = (l1162 + 1)) {
			fRec1662[l1162] = 0.0;
			
		}
		for (int l1163 = 0; (l1163 < 2); l1163 = (l1163 + 1)) {
			fRec1660[l1163] = 0.0;
			
		}
		for (int l1164 = 0; (l1164 < 2); l1164 = (l1164 + 1)) {
			fRec1686[l1164] = 0.0;
			
		}
		for (int l1165 = 0; (l1165 < 2); l1165 = (l1165 + 1)) {
			fRec1684[l1165] = 0.0;
			
		}
		for (int l1166 = 0; (l1166 < 2); l1166 = (l1166 + 1)) {
			fRec1683[l1166] = 0.0;
			
		}
		for (int l1167 = 0; (l1167 < 2); l1167 = (l1167 + 1)) {
			fRec1681[l1167] = 0.0;
			
		}
		for (int l1168 = 0; (l1168 < 2); l1168 = (l1168 + 1)) {
			fRec1680[l1168] = 0.0;
			
		}
		for (int l1169 = 0; (l1169 < 2); l1169 = (l1169 + 1)) {
			fRec1678[l1169] = 0.0;
			
		}
		for (int l1170 = 0; (l1170 < 2); l1170 = (l1170 + 1)) {
			fRec1677[l1170] = 0.0;
			
		}
		for (int l1171 = 0; (l1171 < 2); l1171 = (l1171 + 1)) {
			fRec1675[l1171] = 0.0;
			
		}
		for (int l1172 = 0; (l1172 < 2); l1172 = (l1172 + 1)) {
			fRec1695[l1172] = 0.0;
			
		}
		for (int l1173 = 0; (l1173 < 2); l1173 = (l1173 + 1)) {
			fRec1693[l1173] = 0.0;
			
		}
		for (int l1174 = 0; (l1174 < 2); l1174 = (l1174 + 1)) {
			fRec1692[l1174] = 0.0;
			
		}
		for (int l1175 = 0; (l1175 < 2); l1175 = (l1175 + 1)) {
			fRec1690[l1175] = 0.0;
			
		}
		for (int l1176 = 0; (l1176 < 2); l1176 = (l1176 + 1)) {
			fRec1689[l1176] = 0.0;
			
		}
		for (int l1177 = 0; (l1177 < 2); l1177 = (l1177 + 1)) {
			fRec1687[l1177] = 0.0;
			
		}
		for (int l1178 = 0; (l1178 < 2); l1178 = (l1178 + 1)) {
			fRec1698[l1178] = 0.0;
			
		}
		for (int l1179 = 0; (l1179 < 2); l1179 = (l1179 + 1)) {
			fRec1696[l1179] = 0.0;
			
		}
		for (int l1180 = 0; (l1180 < 2); l1180 = (l1180 + 1)) {
			fRec1704[l1180] = 0.0;
			
		}
		for (int l1181 = 0; (l1181 < 2); l1181 = (l1181 + 1)) {
			fRec1702[l1181] = 0.0;
			
		}
		for (int l1182 = 0; (l1182 < 2); l1182 = (l1182 + 1)) {
			fRec1701[l1182] = 0.0;
			
		}
		for (int l1183 = 0; (l1183 < 2); l1183 = (l1183 + 1)) {
			fRec1699[l1183] = 0.0;
			
		}
		for (int l1184 = 0; (l1184 < 256); l1184 = (l1184 + 1)) {
			fVec25[l1184] = 0.0;
			
		}
		for (int l1185 = 0; (l1185 < 2); l1185 = (l1185 + 1)) {
			fRec1719[l1185] = 0.0;
			
		}
		for (int l1186 = 0; (l1186 < 2); l1186 = (l1186 + 1)) {
			fRec1717[l1186] = 0.0;
			
		}
		for (int l1187 = 0; (l1187 < 2); l1187 = (l1187 + 1)) {
			fRec1716[l1187] = 0.0;
			
		}
		for (int l1188 = 0; (l1188 < 2); l1188 = (l1188 + 1)) {
			fRec1714[l1188] = 0.0;
			
		}
		for (int l1189 = 0; (l1189 < 2); l1189 = (l1189 + 1)) {
			fRec1713[l1189] = 0.0;
			
		}
		for (int l1190 = 0; (l1190 < 2); l1190 = (l1190 + 1)) {
			fRec1711[l1190] = 0.0;
			
		}
		for (int l1191 = 0; (l1191 < 2); l1191 = (l1191 + 1)) {
			fRec1710[l1191] = 0.0;
			
		}
		for (int l1192 = 0; (l1192 < 2); l1192 = (l1192 + 1)) {
			fRec1708[l1192] = 0.0;
			
		}
		for (int l1193 = 0; (l1193 < 2); l1193 = (l1193 + 1)) {
			fRec1707[l1193] = 0.0;
			
		}
		for (int l1194 = 0; (l1194 < 2); l1194 = (l1194 + 1)) {
			fRec1705[l1194] = 0.0;
			
		}
		for (int l1195 = 0; (l1195 < 2); l1195 = (l1195 + 1)) {
			fRec1731[l1195] = 0.0;
			
		}
		for (int l1196 = 0; (l1196 < 2); l1196 = (l1196 + 1)) {
			fRec1729[l1196] = 0.0;
			
		}
		for (int l1197 = 0; (l1197 < 2); l1197 = (l1197 + 1)) {
			fRec1728[l1197] = 0.0;
			
		}
		for (int l1198 = 0; (l1198 < 2); l1198 = (l1198 + 1)) {
			fRec1726[l1198] = 0.0;
			
		}
		for (int l1199 = 0; (l1199 < 2); l1199 = (l1199 + 1)) {
			fRec1725[l1199] = 0.0;
			
		}
		for (int l1200 = 0; (l1200 < 2); l1200 = (l1200 + 1)) {
			fRec1723[l1200] = 0.0;
			
		}
		for (int l1201 = 0; (l1201 < 2); l1201 = (l1201 + 1)) {
			fRec1722[l1201] = 0.0;
			
		}
		for (int l1202 = 0; (l1202 < 2); l1202 = (l1202 + 1)) {
			fRec1720[l1202] = 0.0;
			
		}
		for (int l1203 = 0; (l1203 < 2); l1203 = (l1203 + 1)) {
			fRec1740[l1203] = 0.0;
			
		}
		for (int l1204 = 0; (l1204 < 2); l1204 = (l1204 + 1)) {
			fRec1738[l1204] = 0.0;
			
		}
		for (int l1205 = 0; (l1205 < 2); l1205 = (l1205 + 1)) {
			fRec1737[l1205] = 0.0;
			
		}
		for (int l1206 = 0; (l1206 < 2); l1206 = (l1206 + 1)) {
			fRec1735[l1206] = 0.0;
			
		}
		for (int l1207 = 0; (l1207 < 2); l1207 = (l1207 + 1)) {
			fRec1734[l1207] = 0.0;
			
		}
		for (int l1208 = 0; (l1208 < 2); l1208 = (l1208 + 1)) {
			fRec1732[l1208] = 0.0;
			
		}
		for (int l1209 = 0; (l1209 < 2); l1209 = (l1209 + 1)) {
			fRec1743[l1209] = 0.0;
			
		}
		for (int l1210 = 0; (l1210 < 2); l1210 = (l1210 + 1)) {
			fRec1741[l1210] = 0.0;
			
		}
		for (int l1211 = 0; (l1211 < 2); l1211 = (l1211 + 1)) {
			fRec1749[l1211] = 0.0;
			
		}
		for (int l1212 = 0; (l1212 < 2); l1212 = (l1212 + 1)) {
			fRec1747[l1212] = 0.0;
			
		}
		for (int l1213 = 0; (l1213 < 2); l1213 = (l1213 + 1)) {
			fRec1746[l1213] = 0.0;
			
		}
		for (int l1214 = 0; (l1214 < 2); l1214 = (l1214 + 1)) {
			fRec1744[l1214] = 0.0;
			
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
			fRec1752[l1225] = 0.0;
			
		}
		for (int l1226 = 0; (l1226 < 2); l1226 = (l1226 + 1)) {
			fRec1750[l1226] = 0.0;
			
		}
		for (int l1227 = 0; (l1227 < 256); l1227 = (l1227 + 1)) {
			fVec26[l1227] = 0.0;
			
		}
		for (int l1228 = 0; (l1228 < 2); l1228 = (l1228 + 1)) {
			fRec1785[l1228] = 0.0;
			
		}
		for (int l1229 = 0; (l1229 < 2); l1229 = (l1229 + 1)) {
			fRec1783[l1229] = 0.0;
			
		}
		for (int l1230 = 0; (l1230 < 2); l1230 = (l1230 + 1)) {
			fRec1782[l1230] = 0.0;
			
		}
		for (int l1231 = 0; (l1231 < 2); l1231 = (l1231 + 1)) {
			fRec1780[l1231] = 0.0;
			
		}
		for (int l1232 = 0; (l1232 < 2); l1232 = (l1232 + 1)) {
			fRec1779[l1232] = 0.0;
			
		}
		for (int l1233 = 0; (l1233 < 2); l1233 = (l1233 + 1)) {
			fRec1777[l1233] = 0.0;
			
		}
		for (int l1234 = 0; (l1234 < 2); l1234 = (l1234 + 1)) {
			fRec1776[l1234] = 0.0;
			
		}
		for (int l1235 = 0; (l1235 < 2); l1235 = (l1235 + 1)) {
			fRec1774[l1235] = 0.0;
			
		}
		for (int l1236 = 0; (l1236 < 2); l1236 = (l1236 + 1)) {
			fRec1773[l1236] = 0.0;
			
		}
		for (int l1237 = 0; (l1237 < 2); l1237 = (l1237 + 1)) {
			fRec1771[l1237] = 0.0;
			
		}
		for (int l1238 = 0; (l1238 < 2); l1238 = (l1238 + 1)) {
			fRec1770[l1238] = 0.0;
			
		}
		for (int l1239 = 0; (l1239 < 2); l1239 = (l1239 + 1)) {
			fRec1768[l1239] = 0.0;
			
		}
		for (int l1240 = 0; (l1240 < 2); l1240 = (l1240 + 1)) {
			fRec1800[l1240] = 0.0;
			
		}
		for (int l1241 = 0; (l1241 < 2); l1241 = (l1241 + 1)) {
			fRec1798[l1241] = 0.0;
			
		}
		for (int l1242 = 0; (l1242 < 2); l1242 = (l1242 + 1)) {
			fRec1797[l1242] = 0.0;
			
		}
		for (int l1243 = 0; (l1243 < 2); l1243 = (l1243 + 1)) {
			fRec1795[l1243] = 0.0;
			
		}
		for (int l1244 = 0; (l1244 < 2); l1244 = (l1244 + 1)) {
			fRec1794[l1244] = 0.0;
			
		}
		for (int l1245 = 0; (l1245 < 2); l1245 = (l1245 + 1)) {
			fRec1792[l1245] = 0.0;
			
		}
		for (int l1246 = 0; (l1246 < 2); l1246 = (l1246 + 1)) {
			fRec1791[l1246] = 0.0;
			
		}
		for (int l1247 = 0; (l1247 < 2); l1247 = (l1247 + 1)) {
			fRec1789[l1247] = 0.0;
			
		}
		for (int l1248 = 0; (l1248 < 2); l1248 = (l1248 + 1)) {
			fRec1788[l1248] = 0.0;
			
		}
		for (int l1249 = 0; (l1249 < 2); l1249 = (l1249 + 1)) {
			fRec1786[l1249] = 0.0;
			
		}
		for (int l1250 = 0; (l1250 < 2); l1250 = (l1250 + 1)) {
			fRec1812[l1250] = 0.0;
			
		}
		for (int l1251 = 0; (l1251 < 2); l1251 = (l1251 + 1)) {
			fRec1810[l1251] = 0.0;
			
		}
		for (int l1252 = 0; (l1252 < 2); l1252 = (l1252 + 1)) {
			fRec1809[l1252] = 0.0;
			
		}
		for (int l1253 = 0; (l1253 < 2); l1253 = (l1253 + 1)) {
			fRec1807[l1253] = 0.0;
			
		}
		for (int l1254 = 0; (l1254 < 2); l1254 = (l1254 + 1)) {
			fRec1806[l1254] = 0.0;
			
		}
		for (int l1255 = 0; (l1255 < 2); l1255 = (l1255 + 1)) {
			fRec1804[l1255] = 0.0;
			
		}
		for (int l1256 = 0; (l1256 < 2); l1256 = (l1256 + 1)) {
			fRec1803[l1256] = 0.0;
			
		}
		for (int l1257 = 0; (l1257 < 2); l1257 = (l1257 + 1)) {
			fRec1801[l1257] = 0.0;
			
		}
		for (int l1258 = 0; (l1258 < 2); l1258 = (l1258 + 1)) {
			fRec1818[l1258] = 0.0;
			
		}
		for (int l1259 = 0; (l1259 < 2); l1259 = (l1259 + 1)) {
			fRec1816[l1259] = 0.0;
			
		}
		for (int l1260 = 0; (l1260 < 2); l1260 = (l1260 + 1)) {
			fRec1815[l1260] = 0.0;
			
		}
		for (int l1261 = 0; (l1261 < 2); l1261 = (l1261 + 1)) {
			fRec1813[l1261] = 0.0;
			
		}
		for (int l1262 = 0; (l1262 < 2); l1262 = (l1262 + 1)) {
			fRec1827[l1262] = 0.0;
			
		}
		for (int l1263 = 0; (l1263 < 2); l1263 = (l1263 + 1)) {
			fRec1825[l1263] = 0.0;
			
		}
		for (int l1264 = 0; (l1264 < 2); l1264 = (l1264 + 1)) {
			fRec1824[l1264] = 0.0;
			
		}
		for (int l1265 = 0; (l1265 < 2); l1265 = (l1265 + 1)) {
			fRec1822[l1265] = 0.0;
			
		}
		for (int l1266 = 0; (l1266 < 2); l1266 = (l1266 + 1)) {
			fRec1821[l1266] = 0.0;
			
		}
		for (int l1267 = 0; (l1267 < 2); l1267 = (l1267 + 1)) {
			fRec1819[l1267] = 0.0;
			
		}
		for (int l1268 = 0; (l1268 < 2); l1268 = (l1268 + 1)) {
			fRec1830[l1268] = 0.0;
			
		}
		for (int l1269 = 0; (l1269 < 2); l1269 = (l1269 + 1)) {
			fRec1828[l1269] = 0.0;
			
		}
		for (int l1270 = 0; (l1270 < 256); l1270 = (l1270 + 1)) {
			fVec27[l1270] = 0.0;
			
		}
		for (int l1271 = 0; (l1271 < 2); l1271 = (l1271 + 1)) {
			fRec1848[l1271] = 0.0;
			
		}
		for (int l1272 = 0; (l1272 < 2); l1272 = (l1272 + 1)) {
			fRec1846[l1272] = 0.0;
			
		}
		for (int l1273 = 0; (l1273 < 2); l1273 = (l1273 + 1)) {
			fRec1845[l1273] = 0.0;
			
		}
		for (int l1274 = 0; (l1274 < 2); l1274 = (l1274 + 1)) {
			fRec1843[l1274] = 0.0;
			
		}
		for (int l1275 = 0; (l1275 < 2); l1275 = (l1275 + 1)) {
			fRec1842[l1275] = 0.0;
			
		}
		for (int l1276 = 0; (l1276 < 2); l1276 = (l1276 + 1)) {
			fRec1840[l1276] = 0.0;
			
		}
		for (int l1277 = 0; (l1277 < 2); l1277 = (l1277 + 1)) {
			fRec1839[l1277] = 0.0;
			
		}
		for (int l1278 = 0; (l1278 < 2); l1278 = (l1278 + 1)) {
			fRec1837[l1278] = 0.0;
			
		}
		for (int l1279 = 0; (l1279 < 2); l1279 = (l1279 + 1)) {
			fRec1836[l1279] = 0.0;
			
		}
		for (int l1280 = 0; (l1280 < 2); l1280 = (l1280 + 1)) {
			fRec1834[l1280] = 0.0;
			
		}
		for (int l1281 = 0; (l1281 < 2); l1281 = (l1281 + 1)) {
			fRec1833[l1281] = 0.0;
			
		}
		for (int l1282 = 0; (l1282 < 2); l1282 = (l1282 + 1)) {
			fRec1831[l1282] = 0.0;
			
		}
		for (int l1283 = 0; (l1283 < 2); l1283 = (l1283 + 1)) {
			fRec1863[l1283] = 0.0;
			
		}
		for (int l1284 = 0; (l1284 < 2); l1284 = (l1284 + 1)) {
			fRec1861[l1284] = 0.0;
			
		}
		for (int l1285 = 0; (l1285 < 2); l1285 = (l1285 + 1)) {
			fRec1860[l1285] = 0.0;
			
		}
		for (int l1286 = 0; (l1286 < 2); l1286 = (l1286 + 1)) {
			fRec1858[l1286] = 0.0;
			
		}
		for (int l1287 = 0; (l1287 < 2); l1287 = (l1287 + 1)) {
			fRec1857[l1287] = 0.0;
			
		}
		for (int l1288 = 0; (l1288 < 2); l1288 = (l1288 + 1)) {
			fRec1855[l1288] = 0.0;
			
		}
		for (int l1289 = 0; (l1289 < 2); l1289 = (l1289 + 1)) {
			fRec1854[l1289] = 0.0;
			
		}
		for (int l1290 = 0; (l1290 < 2); l1290 = (l1290 + 1)) {
			fRec1852[l1290] = 0.0;
			
		}
		for (int l1291 = 0; (l1291 < 2); l1291 = (l1291 + 1)) {
			fRec1851[l1291] = 0.0;
			
		}
		for (int l1292 = 0; (l1292 < 2); l1292 = (l1292 + 1)) {
			fRec1849[l1292] = 0.0;
			
		}
		for (int l1293 = 0; (l1293 < 2); l1293 = (l1293 + 1)) {
			fRec1875[l1293] = 0.0;
			
		}
		for (int l1294 = 0; (l1294 < 2); l1294 = (l1294 + 1)) {
			fRec1873[l1294] = 0.0;
			
		}
		for (int l1295 = 0; (l1295 < 2); l1295 = (l1295 + 1)) {
			fRec1872[l1295] = 0.0;
			
		}
		for (int l1296 = 0; (l1296 < 2); l1296 = (l1296 + 1)) {
			fRec1870[l1296] = 0.0;
			
		}
		for (int l1297 = 0; (l1297 < 2); l1297 = (l1297 + 1)) {
			fRec1869[l1297] = 0.0;
			
		}
		for (int l1298 = 0; (l1298 < 2); l1298 = (l1298 + 1)) {
			fRec1867[l1298] = 0.0;
			
		}
		for (int l1299 = 0; (l1299 < 2); l1299 = (l1299 + 1)) {
			fRec1866[l1299] = 0.0;
			
		}
		for (int l1300 = 0; (l1300 < 2); l1300 = (l1300 + 1)) {
			fRec1864[l1300] = 0.0;
			
		}
		for (int l1301 = 0; (l1301 < 2); l1301 = (l1301 + 1)) {
			fRec1884[l1301] = 0.0;
			
		}
		for (int l1302 = 0; (l1302 < 2); l1302 = (l1302 + 1)) {
			fRec1882[l1302] = 0.0;
			
		}
		for (int l1303 = 0; (l1303 < 2); l1303 = (l1303 + 1)) {
			fRec1881[l1303] = 0.0;
			
		}
		for (int l1304 = 0; (l1304 < 2); l1304 = (l1304 + 1)) {
			fRec1879[l1304] = 0.0;
			
		}
		for (int l1305 = 0; (l1305 < 2); l1305 = (l1305 + 1)) {
			fRec1878[l1305] = 0.0;
			
		}
		for (int l1306 = 0; (l1306 < 2); l1306 = (l1306 + 1)) {
			fRec1876[l1306] = 0.0;
			
		}
		for (int l1307 = 0; (l1307 < 2); l1307 = (l1307 + 1)) {
			fRec1887[l1307] = 0.0;
			
		}
		for (int l1308 = 0; (l1308 < 2); l1308 = (l1308 + 1)) {
			fRec1885[l1308] = 0.0;
			
		}
		for (int l1309 = 0; (l1309 < 2); l1309 = (l1309 + 1)) {
			fRec1893[l1309] = 0.0;
			
		}
		for (int l1310 = 0; (l1310 < 2); l1310 = (l1310 + 1)) {
			fRec1891[l1310] = 0.0;
			
		}
		for (int l1311 = 0; (l1311 < 2); l1311 = (l1311 + 1)) {
			fRec1890[l1311] = 0.0;
			
		}
		for (int l1312 = 0; (l1312 < 2); l1312 = (l1312 + 1)) {
			fRec1888[l1312] = 0.0;
			
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
		ui_interface->openVerticalBox("KMHLS_Dome_7h7p_normal_4");
		ui_interface->declare(&fHslider2, "unit", "dB");
		ui_interface->addHorizontalSlider("gain", &fHslider2, -10.0, -30.0, 10.0, 1.0);
		ui_interface->declare(&fHslider1, "unit", "dB");
		ui_interface->addHorizontalSlider("lf/hf", &fHslider1, 0.0, -3.0, 3.0, 0.10000000000000001);
		ui_interface->addCheckButton("mute", &fCheckbox0);
		ui_interface->declare(&fHslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("xover", &fHslider0, 400.0, 200.0, 800.0, 20.0);
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
		double fSlow0 = (0.0010000000000000009 * double(fHslider0));
		double fSlow1 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fHslider1))));
		double fSlow2 = (0.0010000000000000009 * (std::pow(10.0, (0.050000000000000003 * double(fHslider2))) * double((double(fCheckbox0) < 0.5))));
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec0[0] = (fSlow0 + (0.999 * fRec0[1]));
			double fTemp0 = std::tan((fConst1 * fRec0[0]));
			double fTemp1 = mydsp_faustpower2_f(fTemp0);
			double fTemp2 = ((fTemp0 * (fTemp0 + -2.0)) + 1.0);
			double fTemp3 = (fTemp1 + -1.0);
			double fTemp4 = ((fTemp0 * (fTemp0 + 2.0)) + 1.0);
			fRec1[0] = (double(input59[i]) - (((fTemp2 * fRec1[2]) + (2.0 * (fTemp3 * fRec1[1]))) / fTemp4));
			fRec2[0] = (fSlow1 + (0.999 * fRec2[1]));
			double fTemp5 = (fTemp4 * fRec2[0]);
			double fTemp6 = (0.0 - (2.0 / fTemp4));
			double fTemp7 = (((fTemp1 * (fRec1[2] + ((2.0 * fRec1[1]) + fRec1[0]))) / fTemp5) + (0.18781050760000001 * ((0.0 - ((fTemp6 * fRec1[1]) + ((fRec1[2] + fRec1[0]) / fTemp4))) * fRec2[0])));
			fRec3[0] = (double(input56[i]) - (((fTemp2 * fRec3[2]) + (2.0 * (fTemp3 * fRec3[1]))) / fTemp4));
			double fTemp8 = (((fTemp1 * (fRec3[2] + ((2.0 * fRec3[1]) + fRec3[0]))) / fTemp5) + (0.18781050760000001 * ((0.0 - ((fTemp6 * fRec3[1]) + ((fRec3[2] + fRec3[0]) / fTemp4))) * fRec2[0])));
			fRec4[0] = (double(input55[i]) - (((fTemp2 * fRec4[2]) + (2.0 * (fTemp3 * fRec4[1]))) / fTemp4));
			double fTemp9 = (((fTemp1 * (fRec4[2] + ((2.0 * fRec4[1]) + fRec4[0]))) / fTemp5) + (0.18781050760000001 * ((0.0 - ((fTemp6 * fRec4[1]) + ((fRec4[2] + fRec4[0]) / fTemp4))) * fRec2[0])));
			fRec5[0] = (double(input53[i]) - (((fTemp2 * fRec5[2]) + (2.0 * (fTemp3 * fRec5[1]))) / fTemp4));
			double fTemp10 = (((fTemp1 * (fRec5[2] + ((2.0 * fRec5[1]) + fRec5[0]))) / fTemp5) + (0.18781050760000001 * ((0.0 - ((fTemp6 * fRec5[1]) + ((fRec5[2] + fRec5[0]) / fTemp4))) * fRec2[0])));
			fRec6[0] = (double(input0[i]) - (((fRec6[2] * fTemp2) + (2.0 * (fRec6[1] * fTemp3))) / fTemp4));
			double fTemp11 = (((fTemp1 * (fRec6[2] + ((2.0 * fRec6[1]) + fRec6[0]))) / fTemp5) + (1.2115336459999999 * ((0.0 - ((fRec6[1] * fTemp6) + ((fRec6[2] + fRec6[0]) / fTemp4))) * fRec2[0])));
			fRec7[0] = (double(input50[i]) - (((fTemp2 * fRec7[2]) + (2.0 * (fTemp3 * fRec7[1]))) / fTemp4));
			double fTemp12 = (((fTemp1 * (fRec7[2] + ((2.0 * fRec7[1]) + fRec7[0]))) / fTemp5) + (0.18781050760000001 * ((0.0 - ((fTemp6 * fRec7[1]) + ((fRec7[2] + fRec7[0]) / fTemp4))) * fRec2[0])));
			fRec11[0] = (double(input1[i]) - (((fTemp2 * fRec11[2]) + (2.0 * (fTemp3 * fRec11[1]))) / fTemp4));
			double fTemp13 = (((fTemp1 * (fRec11[2] + ((2.0 * fRec11[1]) + fRec11[0]))) / fTemp5) + (1.163423471 * ((0.0 - ((fTemp6 * fRec11[1]) + ((fRec11[2] + fRec11[0]) / fTemp4))) * fRec2[0])));
			fRec12[0] = (double(input3[i]) - (((fTemp2 * fRec12[2]) + (2.0 * (fTemp3 * fRec12[1]))) / fTemp4));
			double fTemp14 = (((fTemp1 * (fRec12[2] + ((2.0 * fRec12[1]) + fRec12[0]))) / fTemp5) + (1.163423471 * ((0.0 - ((fTemp6 * fRec12[1]) + ((fRec12[2] + fRec12[0]) / fTemp4))) * fRec2[0])));
			fRec13[0] = (double(input2[i]) - (((fTemp2 * fRec13[2]) + (2.0 * (fTemp3 * fRec13[1]))) / fTemp4));
			double fTemp15 = (((fTemp1 * (fRec13[2] + ((2.0 * fRec13[1]) + fRec13[0]))) / fTemp5) + (1.163423471 * ((0.0 - ((fTemp6 * fRec13[1]) + ((fRec13[2] + fRec13[0]) / fTemp4))) * fRec2[0])));
			double fTemp16 = (fConst4 * (((4426254701000.0 * fTemp13) + (10723763420000.0 * fTemp14)) - (21478214730000.0 * fTemp15)));
			double fTemp17 = (fConst5 * fRec8[1]);
			fRec10[0] = (fTemp16 + (fRec10[1] + fTemp17));
			fRec8[0] = fRec10[0];
			double fRec9 = (fTemp17 + fTemp16);
			fRec20[0] = (double(input8[i]) - (((fTemp2 * fRec20[2]) + (2.0 * (fTemp3 * fRec20[1]))) / fTemp4));
			double fTemp18 = (((fTemp1 * (fRec20[2] + ((2.0 * fRec20[1]) + fRec20[0]))) / fTemp5) + (1.0700688140000001 * ((0.0 - ((fTemp6 * fRec20[1]) + ((fRec20[2] + fRec20[0]) / fTemp4))) * fRec2[0])));
			fRec21[0] = (double(input4[i]) - (((fTemp2 * fRec21[2]) + (2.0 * (fTemp3 * fRec21[1]))) / fTemp4));
			double fTemp19 = (((fTemp1 * (fRec21[2] + ((2.0 * fRec21[1]) + fRec21[0]))) / fTemp5) + (1.0700688140000001 * ((0.0 - ((fTemp6 * fRec21[1]) + ((fRec21[2] + fRec21[0]) / fTemp4))) * fRec2[0])));
			fRec22[0] = (double(input5[i]) - (((fTemp2 * fRec22[2]) + (2.0 * (fTemp3 * fRec22[1]))) / fTemp4));
			double fTemp20 = (((fTemp1 * (fRec22[2] + ((2.0 * fRec22[1]) + fRec22[0]))) / fTemp5) + (1.0700688140000001 * ((0.0 - ((fTemp6 * fRec22[1]) + ((fRec22[2] + fRec22[0]) / fTemp4))) * fRec2[0])));
			fRec23[0] = (double(input6[i]) - (((fTemp2 * fRec23[2]) + (2.0 * (fTemp3 * fRec23[1]))) / fTemp4));
			double fTemp21 = (((fTemp1 * (fRec23[2] + ((2.0 * fRec23[1]) + fRec23[0]))) / fTemp5) + (1.0700688140000001 * ((0.0 - ((fTemp6 * fRec23[1]) + ((fRec23[2] + fRec23[0]) / fTemp4))) * fRec2[0])));
			fRec24[0] = (double(input7[i]) - (((fTemp2 * fRec24[2]) + (2.0 * (fTemp3 * fRec24[1]))) / fTemp4));
			double fTemp22 = (((fTemp1 * (fRec24[2] + ((2.0 * fRec24[1]) + fRec24[0]))) / fTemp5) + (1.0700688140000001 * ((0.0 - ((fTemp6 * fRec24[1]) + ((fRec24[2] + fRec24[0]) / fTemp4))) * fRec2[0])));
			double fTemp23 = (fConst7 * ((10873858940000.0 * fTemp18) - ((((3003682021000.0 * fTemp19) + (3439891937000.0 * fTemp20)) + (1216726861000.0 * fTemp21)) + (10065757090000.0 * fTemp22))));
			double fTemp24 = (fConst9 * fRec14[1]);
			double fTemp25 = (fConst10 * fRec17[1]);
			fRec19[0] = (fTemp23 + (fTemp24 + (fRec19[1] + fTemp25)));
			fRec17[0] = fRec19[0];
			double fRec18 = ((fTemp25 + fTemp24) + fTemp23);
			fRec16[0] = (fRec16[1] + fRec17[0]);
			fRec14[0] = fRec16[0];
			double fRec15 = fRec18;
			double fTemp26 = (fConst12 * fRec25[1]);
			fRec34[0] = (double(input10[i]) - (((fTemp2 * fRec34[2]) + (2.0 * (fTemp3 * fRec34[1]))) / fTemp4));
			double fTemp27 = (((fTemp1 * (fRec34[2] + ((2.0 * fRec34[1]) + fRec34[0]))) / fTemp5) + (0.93701139950000001 * ((0.0 - ((fTemp6 * fRec34[1]) + ((fRec34[2] + fRec34[0]) / fTemp4))) * fRec2[0])));
			fRec35[0] = (double(input12[i]) - (((fTemp2 * fRec35[2]) + (2.0 * (fTemp3 * fRec35[1]))) / fTemp4));
			double fTemp28 = (((fTemp1 * (fRec35[2] + ((2.0 * fRec35[1]) + fRec35[0]))) / fTemp5) + (0.93701139950000001 * ((0.0 - ((fTemp6 * fRec35[1]) + ((fRec35[2] + fRec35[0]) / fTemp4))) * fRec2[0])));
			fRec36[0] = (double(input13[i]) - (((fTemp2 * fRec36[2]) + (2.0 * (fTemp3 * fRec36[1]))) / fTemp4));
			double fTemp29 = (((fTemp1 * (fRec36[2] + ((2.0 * fRec36[1]) + fRec36[0]))) / fTemp5) + (0.93701139950000001 * ((0.0 - ((fTemp6 * fRec36[1]) + ((fRec36[2] + fRec36[0]) / fTemp4))) * fRec2[0])));
			fRec37[0] = (double(input9[i]) - (((fTemp2 * fRec37[2]) + (2.0 * (fTemp3 * fRec37[1]))) / fTemp4));
			double fTemp30 = (((fTemp1 * (fRec37[2] + ((2.0 * fRec37[1]) + fRec37[0]))) / fTemp5) + (0.93701139950000001 * ((0.0 - ((fTemp6 * fRec37[1]) + ((fRec37[2] + fRec37[0]) / fTemp4))) * fRec2[0])));
			fRec38[0] = (double(input11[i]) - (((fTemp2 * fRec38[2]) + (2.0 * (fTemp3 * fRec38[1]))) / fTemp4));
			double fTemp31 = (((fTemp1 * (fRec38[2] + ((2.0 * fRec38[1]) + fRec38[0]))) / fTemp5) + (0.93701139950000001 * ((0.0 - ((fTemp6 * fRec38[1]) + ((fRec38[2] + fRec38[0]) / fTemp4))) * fRec2[0])));
			fRec39[0] = (double(input14[i]) - (((fTemp2 * fRec39[2]) + (2.0 * (fTemp3 * fRec39[1]))) / fTemp4));
			double fTemp32 = (((fTemp1 * (fRec39[2] + ((2.0 * fRec39[1]) + fRec39[0]))) / fTemp5) + (0.93701139950000001 * ((0.0 - ((fTemp6 * fRec39[1]) + ((fRec39[2] + fRec39[0]) / fTemp4))) * fRec2[0])));
			fRec40[0] = (double(input15[i]) - (((fTemp2 * fRec40[2]) + (2.0 * (fTemp3 * fRec40[1]))) / fTemp4));
			double fTemp33 = (((fTemp1 * (fRec40[2] + ((2.0 * fRec40[1]) + fRec40[0]))) / fTemp5) + (0.93701139950000001 * ((0.0 - ((fTemp6 * fRec40[1]) + ((fRec40[2] + fRec40[0]) / fTemp4))) * fRec2[0])));
			double fTemp34 = (fConst14 * ((((7527979750000.0 * fTemp27) + (15283845260000.0 * fTemp28)) + (8987155332000.0 * fTemp29)) - ((((3632879093000.0 * fTemp30) + (4674451042000.0 * fTemp31)) + (15611314090000.0 * fTemp32)) + (570592054200.0 * fTemp33))));
			double fTemp35 = (fConst15 * fRec28[1]);
			double fTemp36 = (fConst16 * fRec31[1]);
			fRec33[0] = (fTemp34 + (fTemp35 + (fRec33[1] + fTemp36)));
			fRec31[0] = fRec33[0];
			double fRec32 = ((fTemp36 + fTemp35) + fTemp34);
			fRec30[0] = (fRec30[1] + fRec31[0]);
			fRec28[0] = fRec30[0];
			double fRec29 = fRec32;
			fRec27[0] = ((fRec27[1] + fTemp26) + fRec29);
			fRec25[0] = fRec27[0];
			double fRec26 = (fTemp26 + fRec29);
			double fTemp37 = (fConst18 * fRec41[1]);
			double fTemp38 = (fConst19 * fRec44[1]);
			fRec53[0] = (double(input17[i]) - (((fTemp2 * fRec53[2]) + (2.0 * (fTemp3 * fRec53[1]))) / fTemp4));
			double fTemp39 = (((fTemp1 * (fRec53[2] + ((2.0 * fRec53[1]) + fRec53[0]))) / fTemp5) + (0.77210283830000004 * ((0.0 - ((fTemp6 * fRec53[1]) + ((fRec53[2] + fRec53[0]) / fTemp4))) * fRec2[0])));
			fRec54[0] = (double(input19[i]) - (((fTemp2 * fRec54[2]) + (2.0 * (fTemp3 * fRec54[1]))) / fTemp4));
			double fTemp40 = (((fTemp1 * (fRec54[2] + ((2.0 * fRec54[1]) + fRec54[0]))) / fTemp5) + (0.77210283830000004 * ((0.0 - ((fTemp6 * fRec54[1]) + ((fRec54[2] + fRec54[0]) / fTemp4))) * fRec2[0])));
			fRec55[0] = (double(input21[i]) - (((fTemp2 * fRec55[2]) + (2.0 * (fTemp3 * fRec55[1]))) / fTemp4));
			double fTemp41 = (((fTemp1 * (fRec55[2] + ((2.0 * fRec55[1]) + fRec55[0]))) / fTemp5) + (0.77210283830000004 * ((0.0 - ((fTemp6 * fRec55[1]) + ((fRec55[2] + fRec55[0]) / fTemp4))) * fRec2[0])));
			fRec56[0] = (double(input22[i]) - (((fTemp2 * fRec56[2]) + (2.0 * (fTemp3 * fRec56[1]))) / fTemp4));
			double fTemp42 = (((fTemp1 * (fRec56[2] + ((2.0 * fRec56[1]) + fRec56[0]))) / fTemp5) + (0.77210283830000004 * ((0.0 - ((fTemp6 * fRec56[1]) + ((fRec56[2] + fRec56[0]) / fTemp4))) * fRec2[0])));
			fRec57[0] = (double(input16[i]) - (((fTemp2 * fRec57[2]) + (2.0 * (fTemp3 * fRec57[1]))) / fTemp4));
			double fTemp43 = (((fTemp1 * (fRec57[2] + ((2.0 * fRec57[1]) + fRec57[0]))) / fTemp5) + (0.77210283830000004 * ((0.0 - ((fTemp6 * fRec57[1]) + ((fRec57[2] + fRec57[0]) / fTemp4))) * fRec2[0])));
			fRec58[0] = (double(input18[i]) - (((fTemp2 * fRec58[2]) + (2.0 * (fTemp3 * fRec58[1]))) / fTemp4));
			double fTemp44 = (((fTemp1 * (fRec58[2] + ((2.0 * fRec58[1]) + fRec58[0]))) / fTemp5) + (0.77210283830000004 * ((0.0 - ((fTemp6 * fRec58[1]) + ((fRec58[2] + fRec58[0]) / fTemp4))) * fRec2[0])));
			fRec59[0] = (double(input20[i]) - (((fTemp2 * fRec59[2]) + (2.0 * (fTemp3 * fRec59[1]))) / fTemp4));
			double fTemp45 = (((fTemp1 * (fRec59[2] + ((2.0 * fRec59[1]) + fRec59[0]))) / fTemp5) + (0.77210283830000004 * ((0.0 - ((fTemp6 * fRec59[1]) + ((fRec59[2] + fRec59[0]) / fTemp4))) * fRec2[0])));
			fRec60[0] = (double(input23[i]) - (((fTemp2 * fRec60[2]) + (2.0 * (fTemp3 * fRec60[1]))) / fTemp4));
			double fTemp46 = (((fTemp1 * (fRec60[2] + ((2.0 * fRec60[1]) + fRec60[0]))) / fTemp5) + (0.77210283830000004 * ((0.0 - ((fTemp6 * fRec60[1]) + ((fRec60[2] + fRec60[0]) / fTemp4))) * fRec2[0])));
			fRec61[0] = (double(input24[i]) - (((fTemp2 * fRec61[2]) + (2.0 * (fTemp3 * fRec61[1]))) / fTemp4));
			double fTemp47 = (((fTemp1 * (fRec61[2] + ((2.0 * fRec61[1]) + fRec61[0]))) / fTemp5) + (0.77210283830000004 * ((0.0 - ((fTemp6 * fRec61[1]) + ((fRec61[2] + fRec61[0]) / fTemp4))) * fRec2[0])));
			double fTemp48 = (fConst21 * (((((9617623614000.0 * fTemp39) + (4626983500000.0 * fTemp40)) + (603302115500.0 * fTemp41)) + (3768371966000.0 * fTemp42)) - (((((812612673200.0 * fTemp43) + (5765890063000.0 * fTemp44)) + (2993201063000.0 * fTemp45)) + (815100436400.0 * fTemp46)) + (918055509700.0 * fTemp47))));
			double fTemp49 = (fConst22 * fRec47[1]);
			double fTemp50 = (fConst23 * fRec50[1]);
			fRec52[0] = (fTemp48 + (fTemp49 + (fRec52[1] + fTemp50)));
			fRec50[0] = fRec52[0];
			double fRec51 = ((fTemp50 + fTemp49) + fTemp48);
			fRec49[0] = (fRec49[1] + fRec50[0]);
			fRec47[0] = fRec49[0];
			double fRec48 = fRec51;
			fRec46[0] = ((fTemp37 + (fRec46[1] + fTemp38)) + fRec48);
			fRec44[0] = fRec46[0];
			double fRec45 = ((fTemp38 + fTemp37) + fRec48);
			fRec43[0] = (fRec43[1] + fRec44[0]);
			fRec41[0] = fRec43[0];
			double fRec42 = fRec45;
			double fTemp51 = (fConst25 * fRec62[1]);
			double fTemp52 = (fConst27 * fRec65[1]);
			double fTemp53 = (fConst28 * fRec68[1]);
			fRec77[0] = (double(input25[i]) - (((fTemp2 * fRec77[2]) + (2.0 * (fTemp3 * fRec77[1]))) / fTemp4));
			double fTemp54 = (((fTemp1 * (fRec77[2] + ((2.0 * fRec77[1]) + fRec77[0]))) / fTemp5) + (0.58498742319999997 * ((0.0 - ((fTemp6 * fRec77[1]) + ((fRec77[2] + fRec77[0]) / fTemp4))) * fRec2[0])));
			fRec78[0] = (double(input26[i]) - (((fTemp2 * fRec78[2]) + (2.0 * (fTemp3 * fRec78[1]))) / fTemp4));
			double fTemp55 = (((fTemp1 * (fRec78[2] + ((2.0 * fRec78[1]) + fRec78[0]))) / fTemp5) + (0.58498742319999997 * ((0.0 - ((fTemp6 * fRec78[1]) + ((fRec78[2] + fRec78[0]) / fTemp4))) * fRec2[0])));
			fRec79[0] = (double(input28[i]) - (((fTemp2 * fRec79[2]) + (2.0 * (fTemp3 * fRec79[1]))) / fTemp4));
			double fTemp56 = (((fTemp1 * (fRec79[2] + ((2.0 * fRec79[1]) + fRec79[0]))) / fTemp5) + (0.58498742319999997 * ((0.0 - ((fTemp6 * fRec79[1]) + ((fRec79[2] + fRec79[0]) / fTemp4))) * fRec2[0])));
			fRec80[0] = (double(input31[i]) - (((fTemp2 * fRec80[2]) + (2.0 * (fTemp3 * fRec80[1]))) / fTemp4));
			double fTemp57 = (((fTemp1 * (fRec80[2] + ((2.0 * fRec80[1]) + fRec80[0]))) / fTemp5) + (0.58498742319999997 * ((0.0 - ((fTemp6 * fRec80[1]) + ((fRec80[2] + fRec80[0]) / fTemp4))) * fRec2[0])));
			fRec81[0] = (double(input35[i]) - (((fTemp2 * fRec81[2]) + (2.0 * (fTemp3 * fRec81[1]))) / fTemp4));
			double fTemp58 = (((fTemp1 * (fRec81[2] + ((2.0 * fRec81[1]) + fRec81[0]))) / fTemp5) + (0.58498742319999997 * ((0.0 - ((fTemp6 * fRec81[1]) + ((fRec81[2] + fRec81[0]) / fTemp4))) * fRec2[0])));
			fRec82[0] = (double(input27[i]) - (((fTemp2 * fRec82[2]) + (2.0 * (fTemp3 * fRec82[1]))) / fTemp4));
			double fTemp59 = (((fTemp1 * (fRec82[2] + ((2.0 * fRec82[1]) + fRec82[0]))) / fTemp5) + (0.58498742319999997 * ((0.0 - ((fTemp6 * fRec82[1]) + ((fRec82[2] + fRec82[0]) / fTemp4))) * fRec2[0])));
			fRec83[0] = (double(input29[i]) - (((fTemp2 * fRec83[2]) + (2.0 * (fTemp3 * fRec83[1]))) / fTemp4));
			double fTemp60 = (((fTemp1 * (fRec83[2] + ((2.0 * fRec83[1]) + fRec83[0]))) / fTemp5) + (0.58498742319999997 * ((0.0 - ((fTemp6 * fRec83[1]) + ((fRec83[2] + fRec83[0]) / fTemp4))) * fRec2[0])));
			fRec84[0] = (double(input30[i]) - (((fTemp2 * fRec84[2]) + (2.0 * (fTemp3 * fRec84[1]))) / fTemp4));
			double fTemp61 = (((fTemp1 * (fRec84[2] + ((2.0 * fRec84[1]) + fRec84[0]))) / fTemp5) + (0.58498742319999997 * ((0.0 - ((fTemp6 * fRec84[1]) + ((fRec84[2] + fRec84[0]) / fTemp4))) * fRec2[0])));
			fRec85[0] = (double(input32[i]) - (((fTemp2 * fRec85[2]) + (2.0 * (fTemp3 * fRec85[1]))) / fTemp4));
			double fTemp62 = (((fTemp1 * (fRec85[2] + ((2.0 * fRec85[1]) + fRec85[0]))) / fTemp5) + (0.58498742319999997 * ((0.0 - ((fTemp6 * fRec85[1]) + ((fRec85[2] + fRec85[0]) / fTemp4))) * fRec2[0])));
			fRec86[0] = (double(input33[i]) - (((fTemp2 * fRec86[2]) + (2.0 * (fTemp3 * fRec86[1]))) / fTemp4));
			double fTemp63 = (((fTemp1 * (fRec86[2] + ((2.0 * fRec86[1]) + fRec86[0]))) / fTemp5) + (0.58498742319999997 * ((0.0 - ((fTemp6 * fRec86[1]) + ((fRec86[2] + fRec86[0]) / fTemp4))) * fRec2[0])));
			fRec87[0] = (double(input34[i]) - (((fTemp2 * fRec87[2]) + (2.0 * (fTemp3 * fRec87[1]))) / fTemp4));
			double fTemp64 = (((fTemp1 * (fRec87[2] + ((2.0 * fRec87[1]) + fRec87[0]))) / fTemp5) + (0.58498742319999997 * ((0.0 - ((fTemp6 * fRec87[1]) + ((fRec87[2] + fRec87[0]) / fTemp4))) * fRec2[0])));
			double fTemp65 = (fConst30 * ((((((2908739556000.0 * fTemp54) + (2805609186000.0 * fTemp55)) + (169008881000.0 * fTemp56)) + (3486297809000.0 * fTemp57)) + (149800088500.0 * fTemp58)) - ((((((1242228713000.0 * fTemp59) + (1814500163000.0 * fTemp60)) + (8661653416000.0 * fTemp61)) + (2566000821000.0 * fTemp62)) + (228425146400.0 * fTemp63)) + (2989587433000.0 * fTemp64))));
			double fTemp66 = (fConst31 * fRec71[1]);
			double fTemp67 = (fConst32 * fRec74[1]);
			fRec76[0] = (fTemp65 + (fTemp66 + (fRec76[1] + fTemp67)));
			fRec74[0] = fRec76[0];
			double fRec75 = ((fTemp67 + fTemp66) + fTemp65);
			fRec73[0] = (fRec73[1] + fRec74[0]);
			fRec71[0] = fRec73[0];
			double fRec72 = fRec75;
			fRec70[0] = ((fTemp52 + (fRec70[1] + fTemp53)) + fRec72);
			fRec68[0] = fRec70[0];
			double fRec69 = ((fTemp53 + fTemp52) + fRec72);
			fRec67[0] = (fRec67[1] + fRec68[0]);
			fRec65[0] = fRec67[0];
			double fRec66 = fRec69;
			fRec64[0] = ((fRec64[1] + fTemp51) + fRec66);
			fRec62[0] = fRec64[0];
			double fRec63 = (fTemp51 + fRec66);
			double fTemp68 = (fConst34 * fRec88[1]);
			double fTemp69 = (fConst35 * fRec91[1]);
			double fTemp70 = (fConst37 * fRec94[1]);
			double fTemp71 = (fConst38 * fRec97[1]);
			fRec106[0] = (double(input40[i]) - (((fTemp2 * fRec106[2]) + (2.0 * (fTemp3 * fRec106[1]))) / fTemp4));
			double fTemp72 = (((fTemp1 * (fRec106[2] + ((2.0 * fRec106[1]) + fRec106[0]))) / fTemp5) + (0.38646969730000003 * ((0.0 - ((fTemp6 * fRec106[1]) + ((fRec106[2] + fRec106[0]) / fTemp4))) * fRec2[0])));
			fRec107[0] = (double(input46[i]) - (((fTemp2 * fRec107[2]) + (2.0 * (fTemp3 * fRec107[1]))) / fTemp4));
			double fTemp73 = (((fTemp1 * (fRec107[2] + ((2.0 * fRec107[1]) + fRec107[0]))) / fTemp5) + (0.38646969730000003 * ((0.0 - ((fTemp6 * fRec107[1]) + ((fRec107[2] + fRec107[0]) / fTemp4))) * fRec2[0])));
			fRec108[0] = (double(input36[i]) - (((fTemp2 * fRec108[2]) + (2.0 * (fTemp3 * fRec108[1]))) / fTemp4));
			double fTemp74 = (((fTemp1 * (fRec108[2] + ((2.0 * fRec108[1]) + fRec108[0]))) / fTemp5) + (0.38646969730000003 * ((0.0 - ((fTemp6 * fRec108[1]) + ((fRec108[2] + fRec108[0]) / fTemp4))) * fRec2[0])));
			fRec109[0] = (double(input37[i]) - (((fTemp2 * fRec109[2]) + (2.0 * (fTemp3 * fRec109[1]))) / fTemp4));
			double fTemp75 = (((fTemp1 * (fRec109[2] + ((2.0 * fRec109[1]) + fRec109[0]))) / fTemp5) + (0.38646969730000003 * ((0.0 - ((fTemp6 * fRec109[1]) + ((fRec109[2] + fRec109[0]) / fTemp4))) * fRec2[0])));
			fRec110[0] = (double(input38[i]) - (((fTemp2 * fRec110[2]) + (2.0 * (fTemp3 * fRec110[1]))) / fTemp4));
			double fTemp76 = (((fTemp1 * (fRec110[2] + ((2.0 * fRec110[1]) + fRec110[0]))) / fTemp5) + (0.38646969730000003 * ((0.0 - ((fTemp6 * fRec110[1]) + ((fRec110[2] + fRec110[0]) / fTemp4))) * fRec2[0])));
			fRec111[0] = (double(input39[i]) - (((fTemp2 * fRec111[2]) + (2.0 * (fTemp3 * fRec111[1]))) / fTemp4));
			double fTemp77 = (((fTemp1 * (fRec111[2] + ((2.0 * fRec111[1]) + fRec111[0]))) / fTemp5) + (0.38646969730000003 * ((0.0 - ((fTemp6 * fRec111[1]) + ((fRec111[2] + fRec111[0]) / fTemp4))) * fRec2[0])));
			fRec112[0] = (double(input41[i]) - (((fTemp2 * fRec112[2]) + (2.0 * (fTemp3 * fRec112[1]))) / fTemp4));
			double fTemp78 = (((fTemp1 * (fRec112[2] + ((2.0 * fRec112[1]) + fRec112[0]))) / fTemp5) + (0.38646969730000003 * ((0.0 - ((fTemp6 * fRec112[1]) + ((fRec112[2] + fRec112[0]) / fTemp4))) * fRec2[0])));
			fRec113[0] = (double(input42[i]) - (((fTemp2 * fRec113[2]) + (2.0 * (fTemp3 * fRec113[1]))) / fTemp4));
			double fTemp79 = (((fTemp1 * (fRec113[2] + ((2.0 * fRec113[1]) + fRec113[0]))) / fTemp5) + (0.38646969730000003 * ((0.0 - ((fTemp6 * fRec113[1]) + ((fRec113[2] + fRec113[0]) / fTemp4))) * fRec2[0])));
			fRec114[0] = (double(input43[i]) - (((fTemp2 * fRec114[2]) + (2.0 * (fTemp3 * fRec114[1]))) / fTemp4));
			double fTemp80 = (((fTemp1 * (fRec114[2] + ((2.0 * fRec114[1]) + fRec114[0]))) / fTemp5) + (0.38646969730000003 * ((0.0 - ((fTemp6 * fRec114[1]) + ((fRec114[2] + fRec114[0]) / fTemp4))) * fRec2[0])));
			fRec115[0] = (double(input44[i]) - (((fTemp2 * fRec115[2]) + (2.0 * (fTemp3 * fRec115[1]))) / fTemp4));
			double fTemp81 = (((fTemp1 * (fRec115[2] + ((2.0 * fRec115[1]) + fRec115[0]))) / fTemp5) + (0.38646969730000003 * ((0.0 - ((fTemp6 * fRec115[1]) + ((fRec115[2] + fRec115[0]) / fTemp4))) * fRec2[0])));
			fRec116[0] = (double(input45[i]) - (((fTemp2 * fRec116[2]) + (2.0 * (fTemp3 * fRec116[1]))) / fTemp4));
			double fTemp82 = (((fTemp1 * (fRec116[2] + ((2.0 * fRec116[1]) + fRec116[0]))) / fTemp5) + (0.38646969730000003 * ((0.0 - ((fTemp6 * fRec116[1]) + ((fRec116[2] + fRec116[0]) / fTemp4))) * fRec2[0])));
			fRec117[0] = (double(input47[i]) - (((fTemp2 * fRec117[2]) + (2.0 * (fTemp3 * fRec117[1]))) / fTemp4));
			double fTemp83 = (((fTemp1 * (fRec117[2] + ((2.0 * fRec117[1]) + fRec117[0]))) / fTemp5) + (0.38646969730000003 * ((0.0 - ((fTemp6 * fRec117[1]) + ((fRec117[2] + fRec117[0]) / fTemp4))) * fRec2[0])));
			fRec118[0] = (double(input48[i]) - (((fTemp2 * fRec118[2]) + (2.0 * (fTemp3 * fRec118[1]))) / fTemp4));
			double fTemp84 = (((fTemp1 * (fRec118[2] + ((2.0 * fRec118[1]) + fRec118[0]))) / fTemp5) + (0.38646969730000003 * ((0.0 - ((fTemp6 * fRec118[1]) + ((fRec118[2] + fRec118[0]) / fTemp4))) * fRec2[0])));
			double fTemp85 = (fConst40 * (((2004878112000.0 * fTemp72) + (1946763568000.0 * fTemp73)) - (((((((((((2849773178000.0 * fTemp74) + (4457061053000.0 * fTemp75)) + (2599982788000.0 * fTemp76)) + (610719323900.0 * fTemp77)) + (2735746730000.0 * fTemp78)) + (2642651858000.0 * fTemp79)) + (390216657300.0 * fTemp80)) + (4140083828000.0 * fTemp81)) + (116525744500.0 * fTemp82)) + (4222124157000.0 * fTemp83)) + (1806516775000.0 * fTemp84))));
			double fTemp86 = (fConst41 * fRec100[1]);
			double fTemp87 = (fConst42 * fRec103[1]);
			fRec105[0] = (fTemp85 + (fTemp86 + (fRec105[1] + fTemp87)));
			fRec103[0] = fRec105[0];
			double fRec104 = ((fTemp87 + fTemp86) + fTemp85);
			fRec102[0] = (fRec102[1] + fRec103[0]);
			fRec100[0] = fRec102[0];
			double fRec101 = fRec104;
			fRec99[0] = ((fTemp70 + (fRec99[1] + fTemp71)) + fRec101);
			fRec97[0] = fRec99[0];
			double fRec98 = ((fTemp71 + fTemp70) + fRec101);
			fRec96[0] = (fRec96[1] + fRec97[0]);
			fRec94[0] = fRec96[0];
			double fRec95 = fRec98;
			fRec93[0] = ((fTemp68 + (fRec93[1] + fTemp69)) + fRec95);
			fRec91[0] = fRec93[0];
			double fRec92 = ((fTemp69 + fTemp68) + fRec95);
			fRec90[0] = (fRec90[1] + fRec91[0]);
			fRec88[0] = fRec90[0];
			double fRec89 = fRec92;
			fRec119[0] = (double(input49[i]) - (((fTemp2 * fRec119[2]) + (2.0 * (fTemp3 * fRec119[1]))) / fTemp4));
			double fTemp88 = (((fTemp1 * (fRec119[2] + ((2.0 * fRec119[1]) + fRec119[0]))) / fTemp5) + (0.18781050760000001 * ((0.0 - ((fTemp6 * fRec119[1]) + ((fRec119[2] + fRec119[0]) / fTemp4))) * fRec2[0])));
			fRec120[0] = (double(input51[i]) - (((fTemp2 * fRec120[2]) + (2.0 * (fTemp3 * fRec120[1]))) / fTemp4));
			double fTemp89 = (((fTemp1 * (fRec120[2] + ((2.0 * fRec120[1]) + fRec120[0]))) / fTemp5) + (0.18781050760000001 * ((0.0 - ((fTemp6 * fRec120[1]) + ((fRec120[2] + fRec120[0]) / fTemp4))) * fRec2[0])));
			fRec121[0] = (double(input52[i]) - (((fTemp2 * fRec121[2]) + (2.0 * (fTemp3 * fRec121[1]))) / fTemp4));
			double fTemp90 = (((fTemp1 * (fRec121[2] + ((2.0 * fRec121[1]) + fRec121[0]))) / fTemp5) + (0.18781050760000001 * ((0.0 - ((fTemp6 * fRec121[1]) + ((fRec121[2] + fRec121[0]) / fTemp4))) * fRec2[0])));
			fRec122[0] = (double(input54[i]) - (((fTemp2 * fRec122[2]) + (2.0 * (fTemp3 * fRec122[1]))) / fTemp4));
			double fTemp91 = (((fTemp1 * (fRec122[2] + ((2.0 * fRec122[1]) + fRec122[0]))) / fTemp5) + (0.18781050760000001 * ((0.0 - ((fTemp6 * fRec122[1]) + ((fRec122[2] + fRec122[0]) / fTemp4))) * fRec2[0])));
			fRec123[0] = (double(input57[i]) - (((fTemp2 * fRec123[2]) + (2.0 * (fTemp3 * fRec123[1]))) / fTemp4));
			double fTemp92 = (((fTemp1 * (fRec123[2] + ((2.0 * fRec123[1]) + fRec123[0]))) / fTemp5) + (0.18781050760000001 * ((0.0 - ((fTemp6 * fRec123[1]) + ((fRec123[2] + fRec123[0]) / fTemp4))) * fRec2[0])));
			fRec124[0] = (double(input58[i]) - (((fTemp2 * fRec124[2]) + (2.0 * (fTemp3 * fRec124[1]))) / fTemp4));
			double fTemp93 = (((fTemp1 * (fRec124[2] + ((2.0 * fRec124[1]) + fRec124[0]))) / fTemp5) + (0.18781050760000001 * ((0.0 - ((fTemp6 * fRec124[1]) + ((fRec124[2] + fRec124[0]) / fTemp4))) * fRec2[0])));
			fRec125[0] = (double(input60[i]) - (((fTemp2 * fRec125[2]) + (2.0 * (fTemp3 * fRec125[1]))) / fTemp4));
			double fTemp94 = (((fTemp1 * (fRec125[2] + ((2.0 * fRec125[1]) + fRec125[0]))) / fTemp5) + (0.18781050760000001 * ((0.0 - ((fTemp6 * fRec125[1]) + ((fRec125[2] + fRec125[0]) / fTemp4))) * fRec2[0])));
			fRec126[0] = (double(input61[i]) - (((fTemp2 * fRec126[2]) + (2.0 * (fTemp3 * fRec126[1]))) / fTemp4));
			double fTemp95 = (((fTemp1 * (fRec126[2] + ((2.0 * fRec126[1]) + fRec126[0]))) / fTemp5) + (0.18781050760000001 * ((0.0 - ((fTemp6 * fRec126[1]) + ((fRec126[2] + fRec126[0]) / fTemp4))) * fRec2[0])));
			fRec127[0] = (double(input62[i]) - (((fTemp2 * fRec127[2]) + (2.0 * (fTemp3 * fRec127[1]))) / fTemp4));
			double fTemp96 = (((fTemp1 * (fRec127[2] + ((2.0 * fRec127[1]) + fRec127[0]))) / fTemp5) + (0.18781050760000001 * ((0.0 - ((fTemp6 * fRec127[1]) + ((fRec127[2] + fRec127[0]) / fTemp4))) * fRec2[0])));
			fRec128[0] = (double(input63[i]) - (((fTemp2 * fRec128[2]) + (2.0 * (fTemp3 * fRec128[1]))) / fTemp4));
			double fTemp97 = (((fTemp1 * (fRec128[2] + ((2.0 * fRec128[1]) + fRec128[0]))) / fTemp5) + (0.18781050760000001 * ((0.0 - ((fTemp6 * fRec128[1]) + ((fRec128[2] + fRec128[0]) / fTemp4))) * fRec2[0])));
			fVec0[(IOTA & 1023)] = (((((((((3830111359000.0 * fTemp7) + ((6060940325000.0 * fTemp8) + ((4431177853000.0 * fTemp9) + ((1367334604000.0 * fTemp10) + ((15934802410000.0 * fTemp11) + (1689201312000.0 * fTemp12)))))) + fRec9) + fRec15) + fRec26) + fRec42) + fRec63) + fRec89) - ((((((((((2071666428000.0 * fTemp88) + (2405629628000.0 * fTemp89)) + (181714021500.0 * fTemp90)) + (606717710100.0 * fTemp91)) + (10096649150000.0 * fTemp92)) + (2982039759000.0 * fTemp93)) + (1594854928000.0 * fTemp94)) + (684666169000.0 * fTemp95)) + (748557997200.0 * fTemp96)) + (871653242300.0 * fTemp97)));
			fRec129[0] = (fSlow2 + (0.999 * fRec129[1]));
			output0[i] = FAUSTFLOAT((0.8267575322812053 * (fVec0[((IOTA - iConst43) & 1023)] * fRec129[0])));
			double fTemp98 = (fConst4 * ((20409410720000.0 * fTemp15) - ((3077285425000.0 * fTemp13) + (7638296925000.0 * fTemp14))));
			double fTemp99 = (fConst5 * fRec130[1]);
			fRec132[0] = (fTemp98 + (fRec132[1] + fTemp99));
			fRec130[0] = fRec132[0];
			double fRec131 = (fTemp99 + fTemp98);
			double fTemp100 = (fConst7 * ((((4734207751000.0 * fTemp19) + (3546695943000.0 * fTemp20)) + (10113036070000.0 * fTemp22)) - ((271087407200.0 * fTemp21) + (8597091122000.0 * fTemp18))));
			double fTemp101 = (fConst9 * fRec133[1]);
			double fTemp102 = (fConst10 * fRec136[1]);
			fRec138[0] = (fTemp100 + (fTemp101 + (fRec138[1] + fTemp102)));
			fRec136[0] = fRec138[0];
			double fRec137 = ((fTemp102 + fTemp101) + fTemp100);
			fRec135[0] = (fRec135[1] + fRec136[0]);
			fRec133[0] = fRec135[0];
			double fRec134 = fRec137;
			double fTemp103 = (fConst12 * fRec139[1]);
			double fTemp104 = (fConst14 * (((1351387124000.0 * fTemp33) + (((5788430093000.0 * fTemp30) + (3705651141000.0 * fTemp31)) + (15463333730000.0 * fTemp32))) - (((6455227302000.0 * fTemp27) + (15230313120000.0 * fTemp28)) + (10343485720000.0 * fTemp29))));
			double fTemp105 = (fConst15 * fRec142[1]);
			double fTemp106 = (fConst16 * fRec145[1]);
			fRec147[0] = (fTemp104 + (fTemp105 + (fRec147[1] + fTemp106)));
			fRec145[0] = fRec147[0];
			double fRec146 = ((fTemp106 + fTemp105) + fTemp104);
			fRec144[0] = (fRec144[1] + fRec145[0]);
			fRec142[0] = fRec144[0];
			double fRec143 = fRec146;
			fRec141[0] = ((fRec141[1] + fTemp103) + fRec143);
			fRec139[0] = fRec141[0];
			double fRec140 = (fTemp103 + fRec143);
			double fTemp107 = (fConst18 * fRec148[1]);
			double fTemp108 = (fConst19 * fRec151[1]);
			double fTemp109 = (fConst21 * (((713220091000.0 * fTemp47) + ((((2856036577000.0 * fTemp43) + (4260726201000.0 * fTemp44)) + (3688929733000.0 * fTemp45)) + (1143431257000.0 * fTemp46))) - ((4654955087000.0 * fTemp42) + (((8020995995000.0 * fTemp39) + (4951864406000.0 * fTemp40)) + (2001294441000.0 * fTemp41)))));
			double fTemp110 = (fConst22 * fRec154[1]);
			double fTemp111 = (fConst23 * fRec157[1]);
			fRec159[0] = (fTemp109 + (fTemp110 + (fRec159[1] + fTemp111)));
			fRec157[0] = fRec159[0];
			double fRec158 = ((fTemp111 + fTemp110) + fTemp109);
			fRec156[0] = (fRec156[1] + fRec157[0]);
			fRec154[0] = fRec156[0];
			double fRec155 = fRec158;
			fRec153[0] = ((fTemp107 + (fRec153[1] + fTemp108)) + fRec155);
			fRec151[0] = fRec153[0];
			double fRec152 = ((fTemp108 + fTemp107) + fRec155);
			fRec150[0] = (fRec150[1] + fRec151[0]);
			fRec148[0] = fRec150[0];
			double fRec149 = fRec152;
			double fTemp112 = (fConst25 * fRec160[1]);
			double fTemp113 = (fConst27 * fRec163[1]);
			double fTemp114 = (fConst28 * fRec166[1]);
			double fTemp115 = (fConst30 * (((((2130418313000.0 * fTemp60) + (9269786588000.0 * fTemp61)) + (1319528062000.0 * fTemp62)) + (2739683737000.0 * fTemp64)) - (((((((1082275393000.0 * fTemp54) + (1424956340000.0 * fTemp55)) + (159964806100.0 * fTemp59)) + (1465446829000.0 * fTemp56)) + (2507593511000.0 * fTemp57)) + (263889435700.0 * fTemp63)) + (1032244163000.0 * fTemp58))));
			double fTemp116 = (fConst31 * fRec169[1]);
			double fTemp117 = (fConst32 * fRec172[1]);
			fRec174[0] = (fTemp115 + (fTemp116 + (fRec174[1] + fTemp117)));
			fRec172[0] = fRec174[0];
			double fRec173 = ((fTemp117 + fTemp116) + fTemp115);
			fRec171[0] = (fRec171[1] + fRec172[0]);
			fRec169[0] = fRec171[0];
			double fRec170 = fRec173;
			fRec168[0] = ((fTemp113 + (fRec168[1] + fTemp114)) + fRec170);
			fRec166[0] = fRec168[0];
			double fRec167 = ((fTemp114 + fTemp113) + fRec170);
			fRec165[0] = (fRec165[1] + fRec166[0]);
			fRec163[0] = fRec165[0];
			double fRec164 = fRec167;
			fRec162[0] = ((fRec162[1] + fTemp112) + fRec164);
			fRec160[0] = fRec162[0];
			double fRec161 = (fTemp112 + fRec164);
			double fTemp118 = (fConst34 * fRec175[1]);
			double fTemp119 = (fConst35 * fRec178[1]);
			double fTemp120 = (fConst37 * fRec181[1]);
			double fTemp121 = (fConst38 * fRec184[1]);
			double fTemp122 = (fConst40 * (((665253387400.0 * fTemp84) + (((4327137268000.0 * fTemp81) + ((1962362813000.0 * fTemp80) + ((2289639282000.0 * fTemp79) + ((((3565597798000.0 * fTemp74) + (5259006858000.0 * fTemp75)) + (1528561477000.0 * fTemp76)) + (3341670086000.0 * fTemp78))))) + (3433899564000.0 * fTemp83))) - ((1778935646000.0 * fTemp73) + (((1184371019000.0 * fTemp77) + (1605215493000.0 * fTemp72)) + (484310672600.0 * fTemp82)))));
			double fTemp123 = (fConst41 * fRec187[1]);
			double fTemp124 = (fConst42 * fRec190[1]);
			fRec192[0] = (fTemp122 + (fTemp123 + (fRec192[1] + fTemp124)));
			fRec190[0] = fRec192[0];
			double fRec191 = ((fTemp124 + fTemp123) + fTemp122);
			fRec189[0] = (fRec189[1] + fRec190[0]);
			fRec187[0] = fRec189[0];
			double fRec188 = fRec191;
			fRec186[0] = ((fTemp120 + (fRec186[1] + fTemp121)) + fRec188);
			fRec184[0] = fRec186[0];
			double fRec185 = ((fTemp121 + fTemp120) + fRec188);
			fRec183[0] = (fRec183[1] + fRec184[0]);
			fRec181[0] = fRec183[0];
			double fRec182 = fRec185;
			fRec180[0] = ((fTemp118 + (fRec180[1] + fTemp119)) + fRec182);
			fRec178[0] = fRec180[0];
			double fRec179 = ((fTemp119 + fTemp118) + fRec182);
			fRec177[0] = (fRec177[1] + fRec178[0]);
			fRec175[0] = fRec177[0];
			double fRec176 = fRec179;
			fVec1[(IOTA & 1023)] = (((((((((10274574860.0 * fTemp97) + ((1041885609000.0 * fTemp95) + (((4080768930000.0 * fTemp93) + ((((2247687314000.0 * fTemp88) + (1428852242000.0 * fTemp89)) + (1785748905000.0 * fTemp91)) + (9567429917000.0 * fTemp92))) + (1658038767000.0 * fTemp94)))) + fRec131) + fRec134) + fRec140) + fRec149) + fRec161) + fRec176) - ((12439572380.0 * fTemp96) + ((3490773127000.0 * fTemp7) + ((6766197187000.0 * fTemp8) + ((4169975067000.0 * fTemp9) + ((1084775866000.0 * fTemp10) + ((1472762784000.0 * fTemp90) + ((13141523710000.0 * fTemp11) + (1031854691000.0 * fTemp12)))))))));
			output1[i] = FAUSTFLOAT((0.8267575322812053 * (fVec1[((IOTA - iConst43) & 1023)] * fRec129[0])));
			double fTemp125 = (fConst4 * (((2967193275000.0 * fTemp13) + (10081705300000.0 * fTemp14)) - (19342502640000.0 * fTemp15)));
			double fTemp126 = (fConst5 * fRec193[1]);
			fRec195[0] = (fTemp125 + (fRec195[1] + fTemp126));
			fRec193[0] = fRec195[0];
			double fRec194 = (fTemp126 + fTemp125);
			double fTemp127 = (fConst7 * ((10926161810000.0 * fTemp18) - ((((4393199263000.0 * fTemp19) + (3346339382000.0 * fTemp20)) + (1215966196000.0 * fTemp21)) + (8888364506000.0 * fTemp22))));
			double fTemp128 = (fConst9 * fRec196[1]);
			double fTemp129 = (fConst10 * fRec199[1]);
			fRec201[0] = (fTemp127 + (fTemp128 + (fRec201[1] + fTemp129)));
			fRec199[0] = fRec201[0];
			double fRec200 = ((fTemp129 + fTemp128) + fTemp127);
			fRec198[0] = (fRec198[1] + fRec199[0]);
			fRec196[0] = fRec198[0];
			double fRec197 = fRec200;
			double fTemp130 = (fConst12 * fRec202[1]);
			double fTemp131 = (fConst14 * (((((6131236744000.0 * fTemp27) + (13681586240000.0 * fTemp28)) + (7849728283000.0 * fTemp29)) + (1345087697000.0 * fTemp33)) - (((5343438238000.0 * fTemp30) + (3544752811000.0 * fTemp31)) + (13311619520000.0 * fTemp32))));
			double fTemp132 = (fConst15 * fRec205[1]);
			double fTemp133 = (fConst16 * fRec208[1]);
			fRec210[0] = (fTemp131 + (fTemp132 + (fRec210[1] + fTemp133)));
			fRec208[0] = fRec210[0];
			double fRec209 = ((fTemp133 + fTemp132) + fTemp131);
			fRec207[0] = (fRec207[1] + fRec208[0]);
			fRec205[0] = fRec207[0];
			double fRec206 = fRec209;
			fRec204[0] = ((fRec204[1] + fTemp130) + fRec206);
			fRec202[0] = fRec204[0];
			double fRec203 = (fTemp130 + fRec206);
			double fTemp134 = (fConst18 * fRec211[1]);
			double fTemp135 = (fConst19 * fRec214[1]);
			double fTemp136 = (fConst21 * (((1501698139000.0 * fTemp47) + ((422603854000.0 * fTemp46) + ((3142122279000.0 * fTemp42) + (((7651189853000.0 * fTemp39) + (4663806211000.0 * fTemp40)) + (291971233600.0 * fTemp41))))) - (((2559429720000.0 * fTemp43) + (4116449468000.0 * fTemp44)) + (2628278338000.0 * fTemp45))));
			double fTemp137 = (fConst22 * fRec217[1]);
			double fTemp138 = (fConst23 * fRec220[1]);
			fRec222[0] = (fTemp136 + (fTemp137 + (fRec222[1] + fTemp138)));
			fRec220[0] = fRec222[0];
			double fRec221 = ((fTemp138 + fTemp137) + fTemp136);
			fRec219[0] = (fRec219[1] + fRec220[0]);
			fRec217[0] = fRec219[0];
			double fRec218 = fRec221;
			fRec216[0] = ((fTemp134 + (fRec216[1] + fTemp135)) + fRec218);
			fRec214[0] = fRec216[0];
			double fRec215 = ((fTemp135 + fTemp134) + fRec218);
			fRec213[0] = (fRec213[1] + fRec214[0]);
			fRec211[0] = fRec213[0];
			double fRec212 = fRec215;
			double fTemp139 = (fConst25 * fRec223[1]);
			double fTemp140 = (fConst27 * fRec226[1]);
			double fTemp141 = (fConst28 * fRec229[1]);
			double fTemp142 = (fConst30 * (((((((1181132673000.0 * fTemp54) + (1432546976000.0 * fTemp55)) + (55333091900.0 * fTemp59)) + (1313777501000.0 * fTemp56)) + (3158859540000.0 * fTemp57)) + (2859641307000.0 * fTemp58)) - ((1122488674000.0 * fTemp64) + ((777888927100.0 * fTemp63) + (((1994605148000.0 * fTemp60) + (7702563134000.0 * fTemp61)) + (2854622888000.0 * fTemp62))))));
			double fTemp143 = (fConst31 * fRec232[1]);
			double fTemp144 = (fConst32 * fRec235[1]);
			fRec237[0] = (fTemp142 + (fTemp143 + (fRec237[1] + fTemp144)));
			fRec235[0] = fRec237[0];
			double fRec236 = ((fTemp144 + fTemp143) + fTemp142);
			fRec234[0] = (fRec234[1] + fRec235[0]);
			fRec232[0] = fRec234[0];
			double fRec233 = fRec236;
			fRec231[0] = ((fTemp140 + (fRec231[1] + fTemp141)) + fRec233);
			fRec229[0] = fRec231[0];
			double fRec230 = ((fTemp141 + fTemp140) + fRec233);
			fRec228[0] = (fRec228[1] + fRec229[0]);
			fRec226[0] = fRec228[0];
			double fRec227 = fRec230;
			fRec225[0] = ((fRec225[1] + fTemp139) + fRec227);
			fRec223[0] = fRec225[0];
			double fRec224 = (fTemp139 + fRec227);
			double fTemp145 = (fConst34 * fRec238[1]);
			double fTemp146 = (fConst35 * fRec241[1]);
			double fTemp147 = (fConst37 * fRec244[1]);
			double fTemp148 = (fConst38 * fRec247[1]);
			double fTemp149 = (fConst40 * (((((1007299345000.0 * fTemp77) + (1546065020000.0 * fTemp72)) + (1058496242000.0 * fTemp73)) + (613782175400.0 * fTemp84)) - (((1198892669000.0 * fTemp82) + ((3766995830000.0 * fTemp81) + ((192203439500.0 * fTemp80) + ((2373907087000.0 * fTemp79) + ((((3272949879000.0 * fTemp74) + (4885305168000.0 * fTemp75)) + (1518768409000.0 * fTemp76)) + (3125789910000.0 * fTemp78)))))) + (1821556670000.0 * fTemp83))));
			double fTemp150 = (fConst41 * fRec250[1]);
			double fTemp151 = (fConst42 * fRec253[1]);
			fRec255[0] = (fTemp149 + (fTemp150 + (fRec255[1] + fTemp151)));
			fRec253[0] = fRec255[0];
			double fRec254 = ((fTemp151 + fTemp150) + fTemp149);
			fRec252[0] = (fRec252[1] + fRec253[0]);
			fRec250[0] = fRec252[0];
			double fRec251 = fRec254;
			fRec249[0] = ((fTemp147 + (fRec249[1] + fTemp148)) + fRec251);
			fRec247[0] = fRec249[0];
			double fRec248 = ((fTemp148 + fTemp147) + fRec251);
			fRec246[0] = (fRec246[1] + fRec247[0]);
			fRec244[0] = fRec246[0];
			double fRec245 = fRec248;
			fRec243[0] = ((fTemp145 + (fRec243[1] + fTemp146)) + fRec245);
			fRec241[0] = fRec243[0];
			double fRec242 = ((fTemp146 + fTemp145) + fRec245);
			fRec240[0] = (fRec240[1] + fRec241[0]);
			fRec238[0] = fRec240[0];
			double fRec239 = fRec242;
			fVec2[(IOTA & 1023)] = (((((((((794155460700.0 * fTemp97) + ((1053076105000.0 * fTemp96) + ((3443918619000.0 * fTemp7) + ((5403052474000.0 * fTemp8) + ((3951208288000.0 * fTemp9) + ((1046962951000.0 * fTemp10) + ((1275570173000.0 * fTemp90) + ((14422587730000.0 * fTemp11) + (1047530540000.0 * fTemp12))))))))) + fRec194) + fRec197) + fRec203) + fRec212) + fRec224) + fRec239) - ((1357588513000.0 * fTemp95) + (((2330341821000.0 * fTemp93) + ((((2122527494000.0 * fTemp88) + (1434592095000.0 * fTemp89)) + (1613548130000.0 * fTemp91)) + (9083990589000.0 * fTemp92))) + (2989332720000.0 * fTemp94))));
			output2[i] = FAUSTFLOAT((0.8267575322812053 * (fVec2[((IOTA - iConst43) & 1023)] * fRec129[0])));
			double fTemp152 = (fConst7 * ((((2512109066000.0 * fTemp19) + (2991277370000.0 * fTemp20)) + (9193121506000.0 * fTemp22)) - ((276679004500.0 * fTemp21) + (8667795354000.0 * fTemp18))));
			double fTemp153 = (fConst9 * fRec256[1]);
			double fTemp154 = (fConst10 * fRec259[1]);
			fRec261[0] = (fTemp152 + (fTemp153 + (fRec261[1] + fTemp154)));
			fRec259[0] = fRec261[0];
			double fRec260 = ((fTemp154 + fTemp153) + fTemp152);
			fRec258[0] = (fRec259[0] + fRec258[1]);
			fRec256[0] = fRec258[0];
			double fRec257 = fRec260;
			double fTemp155 = (fConst4 * ((18755909170000.0 * fTemp15) - ((3911636908000.0 * fTemp13) + (7142580253000.0 * fTemp14))));
			double fTemp156 = (fConst5 * fRec262[1]);
			fRec264[0] = (fTemp155 + (fRec264[1] + fTemp156));
			fRec262[0] = fRec264[0];
			double fRec263 = (fTemp156 + fTemp155);
			double fTemp157 = (fConst12 * fRec265[1]);
			double fTemp158 = (fConst14 * ((((2928053796000.0 * fTemp30) + (4118627741000.0 * fTemp31)) + (13651582280000.0 * fTemp32)) - ((((6552048020000.0 * fTemp27) + (13990062590000.0 * fTemp28)) + (9474127557000.0 * fTemp29)) + (197971935000.0 * fTemp33))));
			double fTemp159 = (fConst15 * fRec268[1]);
			double fTemp160 = (fConst16 * fRec271[1]);
			fRec273[0] = (fTemp158 + (fTemp159 + (fRec273[1] + fTemp160)));
			fRec271[0] = fRec273[0];
			double fRec272 = ((fTemp160 + fTemp159) + fTemp158);
			fRec270[0] = (fRec270[1] + fRec271[0]);
			fRec268[0] = fRec270[0];
			double fRec269 = fRec272;
			fRec267[0] = ((fRec267[1] + fTemp157) + fRec269);
			fRec265[0] = fRec267[0];
			double fRec266 = (fTemp157 + fRec269);
			double fTemp161 = (fConst18 * fRec274[1]);
			double fTemp162 = (fConst19 * fRec277[1]);
			double fTemp163 = (fConst21 * (((((383597466200.0 * fTemp43) + (5164535849000.0 * fTemp44)) + (3413920433000.0 * fTemp45)) + (143507832500.0 * fTemp46)) - (((4184709442000.0 * fTemp42) + (((8465520778000.0 * fTemp39) + (4006121675000.0 * fTemp40)) + (1761202859000.0 * fTemp41))) + (1285612757000.0 * fTemp47))));
			double fTemp164 = (fConst22 * fRec280[1]);
			double fTemp165 = (fConst23 * fRec283[1]);
			fRec285[0] = (fTemp163 + (fTemp164 + (fRec285[1] + fTemp165)));
			fRec283[0] = fRec285[0];
			double fRec284 = ((fTemp165 + fTemp164) + fTemp163);
			fRec282[0] = (fRec282[1] + fRec283[0]);
			fRec280[0] = fRec282[0];
			double fRec281 = fRec284;
			fRec279[0] = ((fTemp161 + (fRec279[1] + fTemp162)) + fRec281);
			fRec277[0] = fRec279[0];
			double fRec278 = ((fTemp162 + fTemp161) + fRec281);
			fRec276[0] = (fRec276[1] + fRec277[0]);
			fRec274[0] = fRec276[0];
			double fRec275 = fRec278;
			double fTemp166 = (fConst25 * fRec286[1]);
			double fTemp167 = (fConst27 * fRec289[1]);
			double fTemp168 = (fConst28 * fRec292[1]);
			double fTemp169 = (fConst30 * (((1215055065000.0 * fTemp64) + ((181066702300.0 * fTemp63) + (((8533183132000.0 * fTemp61) + ((1263779043000.0 * fTemp59) + (1542568877000.0 * fTemp60))) + (1548610459000.0 * fTemp62)))) - (((((2949380349000.0 * fTemp54) + (2636749415000.0 * fTemp55)) + (38648452050.0 * fTemp56)) + (2242306782000.0 * fTemp57)) + (3347663783000.0 * fTemp58))));
			double fTemp170 = (fConst31 * fRec295[1]);
			double fTemp171 = (fConst32 * fRec298[1]);
			fRec300[0] = (fTemp169 + (fTemp170 + (fRec300[1] + fTemp171)));
			fRec298[0] = fRec300[0];
			double fRec299 = ((fTemp171 + fTemp170) + fTemp169);
			fRec297[0] = (fRec297[1] + fRec298[0]);
			fRec295[0] = fRec297[0];
			double fRec296 = fRec299;
			fRec294[0] = ((fTemp167 + (fRec294[1] + fTemp168)) + fRec296);
			fRec292[0] = fRec294[0];
			double fRec293 = ((fTemp168 + fTemp167) + fRec296);
			fRec291[0] = (fRec291[1] + fRec292[0]);
			fRec289[0] = fRec291[0];
			double fRec290 = fRec293;
			fRec288[0] = ((fRec288[1] + fTemp166) + fRec290);
			fRec286[0] = fRec288[0];
			double fRec287 = (fTemp166 + fRec290);
			double fTemp172 = (fConst34 * fRec301[1]);
			double fTemp173 = (fConst35 * fRec304[1]);
			double fTemp174 = (fConst37 * fRec307[1]);
			double fTemp175 = (fConst38 * fRec310[1]);
			double fTemp176 = (fConst40 * ((((392336352800.0 * fTemp82) + ((4053252929000.0 * fTemp81) + ((1821315214000.0 * fTemp80) + ((2077965502000.0 * fTemp79) + (((((2153244473000.0 * fTemp74) + (3614345580000.0 * fTemp75)) + (2411884210000.0 * fTemp76)) + (737920806400.0 * fTemp77)) + (2328531379000.0 * fTemp78)))))) + (1429245862000.0 * fTemp83)) - (((1799609319000.0 * fTemp72) + (1043850666000.0 * fTemp73)) + (1455112338000.0 * fTemp84))));
			double fTemp177 = (fConst41 * fRec313[1]);
			double fTemp178 = (fConst42 * fRec316[1]);
			fRec318[0] = (fTemp176 + (fTemp177 + (fRec318[1] + fTemp178)));
			fRec316[0] = fRec318[0];
			double fRec317 = ((fTemp178 + fTemp177) + fTemp176);
			fRec315[0] = (fRec315[1] + fRec316[0]);
			fRec313[0] = fRec315[0];
			double fRec314 = fRec317;
			fRec312[0] = ((fTemp174 + (fRec312[1] + fTemp175)) + fRec314);
			fRec310[0] = fRec312[0];
			double fRec311 = ((fTemp175 + fTemp174) + fRec314);
			fRec309[0] = (fRec309[1] + fRec310[0]);
			fRec307[0] = fRec309[0];
			double fRec308 = fRec311;
			fRec306[0] = ((fTemp172 + (fRec306[1] + fTemp173)) + fRec308);
			fRec304[0] = fRec306[0];
			double fRec305 = ((fTemp173 + fTemp172) + fRec308);
			fRec303[0] = (fRec303[1] + fRec304[0]);
			fRec301[0] = fRec303[0];
			double fRec302 = fRec305;
			fVec3[(IOTA & 1023)] = (((((((fRec257 + ((1645850843000.0 * fTemp95) + (((3588515236000.0 * fTemp93) + (((((1705264888000.0 * fTemp88) + (2276596426000.0 * fTemp89)) + (414714991900.0 * fTemp90)) + (400388175800.0 * fTemp91)) + (8783088960000.0 * fTemp92))) + (2829498875000.0 * fTemp94)))) + fRec263) + fRec266) + fRec275) + fRec287) + fRec302) - ((1483754253000.0 * fTemp97) + ((1586540597000.0 * fTemp96) + ((3191134223000.0 * fTemp7) + ((6266069514000.0 * fTemp8) + ((3864237422000.0 * fTemp9) + ((1232371391000.0 * fTemp10) + ((11964183360000.0 * fTemp11) + (1716218506000.0 * fTemp12)))))))));
			output3[i] = FAUSTFLOAT((0.8267575322812053 * (fVec3[((IOTA - iConst43) & 1023)] * fRec129[0])));
			double fTemp179 = (fConst34 * fRec319[1]);
			double fTemp180 = (fConst35 * fRec322[1]);
			double fTemp181 = (fConst37 * fRec325[1]);
			double fTemp182 = (fConst38 * fRec328[1]);
			double fTemp183 = (fConst40 * ((((1661809999000.0 * fTemp73) + (((564714788100.0 * fTemp77) + (1493020732000.0 * fTemp72)) + (784191067000.0 * fTemp82))) + (1331737230000.0 * fTemp84)) - (((3826200491000.0 * fTemp81) + ((492280846200.0 * fTemp80) + ((2216582393000.0 * fTemp79) + ((((824429297600.0 * fTemp74) + (2467327414000.0 * fTemp75)) + (2229674488000.0 * fTemp76)) + (3425766110000.0 * fTemp78))))) + (2405783750000.0 * fTemp83))));
			double fTemp184 = (fConst41 * fRec331[1]);
			double fTemp185 = (fConst42 * fRec334[1]);
			fRec336[0] = (fTemp183 + (fTemp184 + (fRec336[1] + fTemp185)));
			fRec334[0] = fRec336[0];
			double fRec335 = ((fTemp185 + fTemp184) + fTemp183);
			fRec333[0] = (fRec333[1] + fRec334[0]);
			fRec331[0] = fRec333[0];
			double fRec332 = fRec335;
			fRec330[0] = ((fTemp181 + (fRec330[1] + fTemp182)) + fRec332);
			fRec328[0] = fRec330[0];
			double fRec329 = ((fTemp182 + fTemp181) + fRec332);
			fRec327[0] = (fRec327[1] + fRec328[0]);
			fRec325[0] = fRec327[0];
			double fRec326 = fRec329;
			fRec324[0] = ((fTemp179 + (fRec324[1] + fTemp180)) + fRec326);
			fRec322[0] = fRec324[0];
			double fRec323 = ((fTemp180 + fTemp179) + fRec326);
			fRec321[0] = (fRec321[1] + fRec322[0]);
			fRec319[0] = fRec321[0];
			double fRec320 = fRec323;
			double fTemp186 = (fConst4 * (((1697965133000.0 * fTemp13) + (8861322789000.0 * fTemp14)) - (17818393710000.0 * fTemp15)));
			double fTemp187 = (fConst5 * fRec337[1]);
			fRec339[0] = (fTemp186 + (fRec339[1] + fTemp187));
			fRec337[0] = fRec339[0];
			double fRec338 = (fTemp187 + fTemp186);
			double fTemp188 = (fConst7 * ((8292186539000.0 * fTemp18) - ((((5177669100000.0 * fTemp19) + (3381148981000.0 * fTemp20)) + (1155361087000.0 * fTemp21)) + (8222807441000.0 * fTemp22))));
			double fTemp189 = (fConst9 * fRec340[1]);
			double fTemp190 = (fConst10 * fRec343[1]);
			fRec345[0] = (fTemp188 + (fTemp189 + (fRec345[1] + fTemp190)));
			fRec343[0] = fRec345[0];
			double fRec344 = ((fTemp190 + fTemp189) + fTemp188);
			fRec342[0] = (fRec342[1] + fRec343[0]);
			fRec340[0] = fRec342[0];
			double fRec341 = fRec344;
			double fTemp191 = (fConst12 * fRec346[1]);
			double fTemp192 = (fConst14 * ((((4952416513000.0 * fTemp27) + (12607863380000.0 * fTemp28)) + (7675188516000.0 * fTemp29)) - ((1610117053000.0 * fTemp33) + (((4693110300000.0 * fTemp30) + (2619382813000.0 * fTemp31)) + (13004265720000.0 * fTemp32)))));
			double fTemp193 = (fConst15 * fRec349[1]);
			double fTemp194 = (fConst16 * fRec352[1]);
			fRec354[0] = (fTemp192 + (fTemp193 + (fRec354[1] + fTemp194)));
			fRec352[0] = fRec354[0];
			double fRec353 = ((fTemp194 + fTemp193) + fTemp192);
			fRec351[0] = (fRec351[1] + fRec352[0]);
			fRec349[0] = fRec351[0];
			double fRec350 = fRec353;
			fRec348[0] = ((fRec348[1] + fTemp191) + fRec350);
			fRec346[0] = fRec348[0];
			double fRec347 = (fTemp191 + fRec350);
			double fTemp195 = (fConst18 * fRec355[1]);
			double fTemp196 = (fConst19 * fRec358[1]);
			double fTemp197 = (fConst21 * (((3923190786000.0 * fTemp42) + (((6986523082000.0 * fTemp39) + (4881105111000.0 * fTemp40)) + (582681936400.0 * fTemp41))) - ((936214999600.0 * fTemp47) + ((((453629566400.0 * fTemp43) + (3549756715000.0 * fTemp44)) + (2390062872000.0 * fTemp45)) + (1186796110000.0 * fTemp46)))));
			double fTemp198 = (fConst22 * fRec361[1]);
			double fTemp199 = (fConst23 * fRec364[1]);
			fRec366[0] = (fTemp197 + (fTemp198 + (fRec366[1] + fTemp199)));
			fRec364[0] = fRec366[0];
			double fRec365 = ((fTemp199 + fTemp198) + fTemp197);
			fRec363[0] = (fRec363[1] + fRec364[0]);
			fRec361[0] = fRec363[0];
			double fRec362 = fRec365;
			fRec360[0] = ((fTemp195 + (fRec360[1] + fTemp196)) + fRec362);
			fRec358[0] = fRec360[0];
			double fRec359 = ((fTemp196 + fTemp195) + fRec362);
			fRec357[0] = (fRec357[1] + fRec358[0]);
			fRec355[0] = fRec357[0];
			double fRec356 = fRec359;
			double fTemp200 = (fConst25 * fRec367[1]);
			double fTemp201 = (fConst27 * fRec370[1]);
			double fTemp202 = (fConst28 * fRec373[1]);
			double fTemp203 = (fConst30 * (((((((4074786558000.0 * fTemp54) + (2471424146000.0 * fTemp55)) + (1763262582000.0 * fTemp56)) + (2749942934000.0 * fTemp57)) + (510192737500.0 * fTemp63)) + (1793052669000.0 * fTemp58)) - (((((410046761800.0 * fTemp59) + (2063624184000.0 * fTemp60)) + (7074618457000.0 * fTemp61)) + (1515156712000.0 * fTemp62)) + (2600077541000.0 * fTemp64))));
			double fTemp204 = (fConst31 * fRec376[1]);
			double fTemp205 = (fConst32 * fRec379[1]);
			fRec381[0] = (fTemp203 + (fTemp204 + (fRec381[1] + fTemp205)));
			fRec379[0] = fRec381[0];
			double fRec380 = ((fTemp205 + fTemp204) + fTemp203);
			fRec378[0] = (fRec378[1] + fRec379[0]);
			fRec376[0] = fRec378[0];
			double fRec377 = fRec380;
			fRec375[0] = ((fTemp201 + (fRec375[1] + fTemp202)) + fRec377);
			fRec373[0] = fRec375[0];
			double fRec374 = ((fTemp202 + fTemp201) + fRec377);
			fRec372[0] = (fRec372[1] + fRec373[0]);
			fRec370[0] = fRec372[0];
			double fRec371 = fRec374;
			fRec369[0] = ((fRec369[1] + fTemp200) + fRec371);
			fRec367[0] = fRec369[0];
			double fRec368 = (fTemp200 + fRec371);
			fVec4[(IOTA & 1023)] = (((((((((1961876777000.0 * fTemp97) + ((1490432434000.0 * fTemp96) + ((3039024388000.0 * fTemp7) + ((4919655289000.0 * fTemp8) + ((3651407598000.0 * fTemp9) + ((1142719742000.0 * fTemp10) + ((13411213780000.0 * fTemp11) + (2675155950000.0 * fTemp12)))))))) + fRec320) + fRec338) + fRec341) + fRec347) + fRec356) + fRec368) - ((1260278281000.0 * fTemp95) + (((3350829567000.0 * fTemp93) + (((((1083352299000.0 * fTemp88) + (2395705604000.0 * fTemp89)) + (304446735500.0 * fTemp90)) + (1805893320000.0 * fTemp91)) + (8338700524000.0 * fTemp92))) + (1207235156000.0 * fTemp94))));
			output4[i] = FAUSTFLOAT((0.8267575322812053 * (fVec4[((IOTA - iConst43) & 1023)] * fRec129[0])));
			double fTemp206 = (fConst4 * ((17676913120000.0 * fTemp15) - ((4323901992000.0 * fTemp13) + (7634708323000.0 * fTemp14))));
			double fTemp207 = (fConst5 * fRec382[1]);
			fRec384[0] = (fTemp206 + (fRec384[1] + fTemp207));
			fRec382[0] = fRec384[0];
			double fRec383 = (fTemp207 + fTemp206);
			double fTemp208 = (fConst7 * ((((3224985928000.0 * fTemp19) + (2778746878000.0 * fTemp20)) + (8465055370000.0 * fTemp22)) - ((338699254400.0 * fTemp21) + (10047873700000.0 * fTemp18))));
			double fTemp209 = (fConst9 * fRec385[1]);
			double fTemp210 = (fConst10 * fRec388[1]);
			fRec390[0] = (fTemp208 + (fTemp209 + (fRec390[1] + fTemp210)));
			fRec388[0] = fRec390[0];
			double fRec389 = ((fTemp210 + fTemp209) + fTemp208);
			fRec387[0] = (fRec387[1] + fRec388[0]);
			fRec385[0] = fRec387[0];
			double fRec386 = fRec389;
			double fTemp211 = (fConst12 * fRec391[1]);
			double fTemp212 = (fConst14 * ((((5554206668000.0 * fTemp30) + (4484247227000.0 * fTemp31)) + (12214639540000.0 * fTemp32)) - ((((5623682021000.0 * fTemp27) + (13243084930000.0 * fTemp28)) + (8336437654000.0 * fTemp29)) + (776504240500.0 * fTemp33))));
			double fTemp213 = (fConst15 * fRec394[1]);
			double fTemp214 = (fConst16 * fRec397[1]);
			fRec399[0] = (fTemp212 + (fTemp213 + (fRec399[1] + fTemp214)));
			fRec397[0] = fRec399[0];
			double fRec398 = ((fTemp214 + fTemp213) + fTemp212);
			fRec396[0] = (fRec396[1] + fRec397[0]);
			fRec394[0] = fRec396[0];
			double fRec395 = fRec398;
			fRec393[0] = ((fRec393[1] + fTemp211) + fRec395);
			fRec391[0] = fRec393[0];
			double fRec392 = (fTemp211 + fRec395);
			double fTemp215 = (fConst18 * fRec400[1]);
			double fTemp216 = (fConst19 * fRec403[1]);
			double fTemp217 = (fConst21 * (((849614664600.0 * fTemp47) + ((((2572668498000.0 * fTemp43) + (4737522486000.0 * fTemp44)) + (3267307340000.0 * fTemp45)) + (49203242700.0 * fTemp46))) - ((2763746308000.0 * fTemp42) + (((6533893140000.0 * fTemp39) + (3354123447000.0 * fTemp40)) + (1147381271000.0 * fTemp41)))));
			double fTemp218 = (fConst22 * fRec406[1]);
			double fTemp219 = (fConst23 * fRec409[1]);
			fRec411[0] = (fTemp217 + (fTemp218 + (fRec411[1] + fTemp219)));
			fRec409[0] = fRec411[0];
			double fRec410 = ((fTemp219 + fTemp218) + fTemp217);
			fRec408[0] = (fRec408[1] + fRec409[0]);
			fRec406[0] = fRec408[0];
			double fRec407 = fRec410;
			fRec405[0] = ((fTemp215 + (fRec405[1] + fTemp216)) + fRec407);
			fRec403[0] = fRec405[0];
			double fRec404 = ((fTemp216 + fTemp215) + fRec407);
			fRec402[0] = (fRec402[1] + fRec403[0]);
			fRec400[0] = fRec402[0];
			double fRec401 = fRec404;
			double fTemp220 = (fConst25 * fRec412[1]);
			double fTemp221 = (fConst27 * fRec415[1]);
			double fTemp222 = (fConst28 * fRec418[1]);
			double fTemp223 = (fConst30 * (((2506537884000.0 * fTemp64) + ((849022686200.0 * fTemp63) + (((1215548537000.0 * fTemp60) + (8113845544000.0 * fTemp61)) + (2677776065000.0 * fTemp62)))) - ((((((3250786652000.0 * fTemp54) + (1177393495000.0 * fTemp55)) + (152908155100.0 * fTemp59)) + (430755267700.0 * fTemp56)) + (2336671262000.0 * fTemp57)) + (66939077900.0 * fTemp58))));
			double fTemp224 = (fConst31 * fRec421[1]);
			double fTemp225 = (fConst32 * fRec424[1]);
			fRec426[0] = (fTemp223 + (fTemp224 + (fRec426[1] + fTemp225)));
			fRec424[0] = fRec426[0];
			double fRec425 = ((fTemp225 + fTemp224) + fTemp223);
			fRec423[0] = (fRec423[1] + fRec424[0]);
			fRec421[0] = fRec423[0];
			double fRec422 = fRec425;
			fRec420[0] = ((fTemp221 + (fRec420[1] + fTemp222)) + fRec422);
			fRec418[0] = fRec420[0];
			double fRec419 = ((fTemp222 + fTemp221) + fRec422);
			fRec417[0] = (fRec417[1] + fRec418[0]);
			fRec415[0] = fRec417[0];
			double fRec416 = fRec419;
			fRec414[0] = ((fRec414[1] + fTemp220) + fRec416);
			fRec412[0] = fRec414[0];
			double fRec413 = (fTemp220 + fRec416);
			double fTemp226 = (fConst34 * fRec427[1]);
			double fTemp227 = (fConst35 * fRec430[1]);
			double fTemp228 = (fConst37 * fRec433[1]);
			double fTemp229 = (fConst38 * fRec436[1]);
			double fTemp230 = (fConst40 * ((((1009765441000.0 * fTemp82) + ((3382896034000.0 * fTemp81) + ((1223203679000.0 * fTemp80) + ((1968151280000.0 * fTemp79) + (((2949844960000.0 * fTemp75) + (1279555440000.0 * fTemp76)) + (1745984227000.0 * fTemp78)))))) + (3432550471000.0 * fTemp83)) - (((((60563551510.0 * fTemp74) + (1237708274000.0 * fTemp77)) + (1773967890000.0 * fTemp72)) + (1655611642000.0 * fTemp73)) + (375629702500.0 * fTemp84))));
			double fTemp231 = (fConst41 * fRec439[1]);
			double fTemp232 = (fConst42 * fRec442[1]);
			fRec444[0] = (fTemp230 + (fTemp231 + (fRec444[1] + fTemp232)));
			fRec442[0] = fRec444[0];
			double fRec443 = ((fTemp232 + fTemp231) + fTemp230);
			fRec441[0] = (fRec441[1] + fRec442[0]);
			fRec439[0] = fRec441[0];
			double fRec440 = fRec443;
			fRec438[0] = ((fTemp228 + (fRec438[1] + fTemp229)) + fRec440);
			fRec436[0] = fRec438[0];
			double fRec437 = ((fTemp229 + fTemp228) + fRec440);
			fRec435[0] = (fRec435[1] + fRec436[0]);
			fRec433[0] = fRec435[0];
			double fRec434 = fRec437;
			fRec432[0] = ((fTemp226 + (fRec432[1] + fTemp227)) + fRec434);
			fRec430[0] = fRec432[0];
			double fRec431 = ((fTemp227 + fTemp226) + fRec434);
			fRec429[0] = (fRec429[1] + fRec430[0]);
			fRec427[0] = fRec429[0];
			double fRec428 = fRec431;
			fVec5[(IOTA & 1023)] = (((((((((376051870200.0 * fTemp95) + (((2014253301000.0 * fTemp93) + ((((391471470000.0 * fTemp88) + (2010719944000.0 * fTemp89)) + (578456155000.0 * fTemp91)) + (8311357630000.0 * fTemp92))) + (1248579325000.0 * fTemp94))) + fRec383) + fRec386) + fRec392) + fRec401) + fRec413) + fRec428) - ((2182777509000.0 * fTemp97) + ((817949918800.0 * fTemp96) + ((3229471329000.0 * fTemp7) + ((5937773578000.0 * fTemp8) + ((3600468112000.0 * fTemp9) + ((965151743900.0 * fTemp10) + ((1354179324000.0 * fTemp90) + ((11263008570000.0 * fTemp11) + (3204088530000.0 * fTemp12))))))))));
			output5[i] = FAUSTFLOAT((0.8267575322812053 * (fVec5[((IOTA - iConst43) & 1023)] * fRec129[0])));
			double fTemp233 = (fConst4 * (((1337753378000.0 * fTemp13) + (7519862352000.0 * fTemp14)) - (17455776990000.0 * fTemp15)));
			double fTemp234 = (fConst5 * fRec445[1]);
			fRec447[0] = (fTemp233 + (fRec447[1] + fTemp234));
			fRec445[0] = fRec447[0];
			double fRec446 = (fTemp234 + fTemp233);
			double fTemp235 = (fConst7 * ((7065785828000.0 * fTemp18) - ((((3154193143000.0 * fTemp19) + (3458020042000.0 * fTemp20)) + (1173211606000.0 * fTemp21)) + (8379931522000.0 * fTemp22))));
			double fTemp236 = (fConst9 * fRec448[1]);
			double fTemp237 = (fConst10 * fRec451[1]);
			fRec453[0] = (fTemp235 + (fTemp236 + (fRec453[1] + fTemp237)));
			fRec451[0] = fRec453[0];
			double fRec452 = ((fTemp237 + fTemp236) + fTemp235);
			fRec450[0] = (fRec450[1] + fRec451[0]);
			fRec448[0] = fRec450[0];
			double fRec449 = fRec452;
			double fTemp238 = (fConst12 * fRec454[1]);
			double fTemp239 = (fConst14 * (((((5597553357000.0 * fTemp27) + (12301118700000.0 * fTemp28)) + (8214639501000.0 * fTemp29)) + (791859199300.0 * fTemp33)) - (((2784480517000.0 * fTemp30) + (2435993878000.0 * fTemp31)) + (13412346920000.0 * fTemp32))));
			double fTemp240 = (fConst15 * fRec457[1]);
			double fTemp241 = (fConst16 * fRec460[1]);
			fRec462[0] = (fTemp239 + (fTemp240 + (fRec462[1] + fTemp241)));
			fRec460[0] = fRec462[0];
			double fRec461 = ((fTemp241 + fTemp240) + fTemp239);
			fRec459[0] = (fRec459[1] + fRec460[0]);
			fRec457[0] = fRec459[0];
			double fRec458 = fRec461;
			fRec456[0] = ((fRec456[1] + fTemp238) + fRec458);
			fRec454[0] = fRec456[0];
			double fRec455 = (fTemp238 + fRec458);
			double fTemp242 = (fConst18 * fRec463[1]);
			double fTemp243 = (fConst19 * fRec466[1]);
			double fTemp244 = (fConst21 * ((((4040942308000.0 * fTemp42) + (((8020637736000.0 * fTemp39) + (4956925742000.0 * fTemp40)) + (1138480980000.0 * fTemp41))) + (1373554279000.0 * fTemp47)) - ((((2572644621000.0 * fTemp43) + (4638328304000.0 * fTemp44)) + (2359676739000.0 * fTemp45)) + (905317684.5 * fTemp46))));
			double fTemp245 = (fConst22 * fRec469[1]);
			double fTemp246 = (fConst23 * fRec472[1]);
			fRec474[0] = (fTemp244 + (fTemp245 + (fRec474[1] + fTemp246)));
			fRec472[0] = fRec474[0];
			double fRec473 = ((fTemp246 + fTemp245) + fTemp244);
			fRec471[0] = (fRec471[1] + fRec472[0]);
			fRec469[0] = fRec471[0];
			double fRec470 = fRec473;
			fRec468[0] = ((fTemp242 + (fRec468[1] + fTemp243)) + fRec470);
			fRec466[0] = fRec468[0];
			double fRec467 = ((fTemp243 + fTemp242) + fRec470);
			fRec465[0] = (fRec465[1] + fRec466[0]);
			fRec463[0] = fRec465[0];
			double fRec464 = fRec467;
			double fTemp247 = (fConst25 * fRec475[1]);
			double fTemp248 = (fConst28 * fRec481[1]);
			double fTemp249 = (fConst27 * fRec478[1]);
			double fTemp250 = (fConst30 * ((((((1317934485000.0 * fTemp54) + (1101394891000.0 * fTemp55)) + (432713897100.0 * fTemp56)) + (2329156223000.0 * fTemp57)) + (56202392620.0 * fTemp58)) - ((982524242500.0 * fTemp64) + ((789128047500.0 * fTemp63) + ((((2000639171000.0 * fTemp60) + (865306176100.0 * fTemp59)) + (6918839701000.0 * fTemp61)) + (992529891500.0 * fTemp62))))));
			double fTemp251 = (fConst32 * fRec487[1]);
			double fTemp252 = (fConst31 * fRec484[1]);
			fRec489[0] = (((fTemp250 + fRec489[1]) + fTemp251) + fTemp252);
			fRec487[0] = fRec489[0];
			double fRec488 = ((fTemp250 + fTemp251) + fTemp252);
			fRec486[0] = (fRec486[1] + fRec487[0]);
			fRec484[0] = fRec486[0];
			double fRec485 = fRec488;
			fRec483[0] = (((fRec483[1] + fTemp248) + fTemp249) + fRec485);
			fRec481[0] = fRec483[0];
			double fRec482 = ((fTemp248 + fTemp249) + fRec485);
			fRec480[0] = (fRec480[1] + fRec481[0]);
			fRec478[0] = fRec480[0];
			double fRec479 = fRec482;
			fRec477[0] = ((fRec477[1] + fTemp247) + fRec479);
			fRec475[0] = fRec477[0];
			double fRec476 = (fTemp247 + fRec479);
			double fTemp253 = (fConst34 * fRec490[1]);
			double fTemp254 = (fConst35 * fRec493[1]);
			double fTemp255 = (fConst37 * fRec496[1]);
			double fTemp256 = (fConst38 * fRec499[1]);
			double fTemp257 = (fConst40 * ((((54982167680.0 * fTemp74) + (1727188756000.0 * fTemp72)) + (991080623900.0 * fTemp73)) - ((857346285400.0 * fTemp84) + (((977499075900.0 * fTemp82) + ((3688530882000.0 * fTemp81) + ((1188814307000.0 * fTemp80) + ((2146703073000.0 * fTemp79) + ((((4351602673000.0 * fTemp75) + (1328946935000.0 * fTemp76)) + (457962147300.0 * fTemp77)) + (3430550795000.0 * fTemp78)))))) + (3431513960000.0 * fTemp83)))));
			double fTemp258 = (fConst41 * fRec502[1]);
			double fTemp259 = (fConst42 * fRec505[1]);
			fRec507[0] = (fTemp257 + (fTemp258 + (fRec507[1] + fTemp259)));
			fRec505[0] = fRec507[0];
			double fRec506 = ((fTemp259 + fTemp258) + fTemp257);
			fRec504[0] = (fRec504[1] + fRec505[0]);
			fRec502[0] = fRec504[0];
			double fRec503 = fRec506;
			fRec501[0] = ((fTemp255 + (fRec501[1] + fTemp256)) + fRec503);
			fRec499[0] = fRec501[0];
			double fRec500 = ((fTemp256 + fTemp255) + fRec503);
			fRec498[0] = (fRec498[1] + fRec499[0]);
			fRec496[0] = fRec498[0];
			double fRec497 = fRec500;
			fRec495[0] = ((fTemp253 + (fRec495[1] + fTemp254)) + fRec497);
			fRec493[0] = fRec495[0];
			double fRec494 = ((fTemp254 + fTemp253) + fRec497);
			fRec492[0] = (fRec492[1] + fRec493[0]);
			fRec490[0] = fRec492[0];
			double fRec491 = fRec494;
			fVec6[(IOTA & 1023)] = (((((((((2158077900000.0 * fTemp97) + ((3165401409000.0 * fTemp7) + ((4847650426000.0 * fTemp8) + ((3577141626000.0 * fTemp9) + ((1078720338000.0 * fTemp10) + ((1300591319000.0 * fTemp90) + ((3208577495000.0 * fTemp12) + ((378533732800.0 * fTemp88) + (13158989540000.0 * fTemp11))))))))) + fRec446) + fRec449) + fRec455) + fRec464) + fRec476) + fRec491) - ((228103156400.0 * fTemp96) + ((443803306500.0 * fTemp95) + (((3576003913000.0 * fTemp93) + (((1617469648000.0 * fTemp89) + (600051351900.0 * fTemp91)) + (8206490717000.0 * fTemp92))) + (2679810737000.0 * fTemp94)))));
			output6[i] = FAUSTFLOAT((0.8267575322812053 * (fVec6[((IOTA - iConst43) & 1023)] * fRec129[0])));
			double fTemp260 = (fConst34 * fRec508[1]);
			double fTemp261 = (fConst35 * fRec511[1]);
			double fTemp262 = (fConst37 * fRec514[1]);
			double fTemp263 = (fConst38 * fRec517[1]);
			double fTemp264 = (fConst40 * (((1806800390000.0 * fTemp84) + (((3494180868000.0 * fTemp81) + ((464727986400.0 * fTemp80) + ((2020808431000.0 * fTemp79) + ((((846443359700.0 * fTemp74) + (5001885499000.0 * fTemp75)) + (2357638584000.0 * fTemp76)) + (1920100928000.0 * fTemp78))))) + (2515239111000.0 * fTemp83))) - ((914136132300.0 * fTemp73) + (((184031172700.0 * fTemp77) + (1496326820000.0 * fTemp72)) + (834389098500.0 * fTemp82)))));
			double fTemp265 = (fConst41 * fRec520[1]);
			double fTemp266 = (fConst42 * fRec523[1]);
			fRec525[0] = (fTemp264 + (fTemp265 + (fRec525[1] + fTemp266)));
			fRec523[0] = fRec525[0];
			double fRec524 = ((fTemp266 + fTemp265) + fTemp264);
			fRec522[0] = (fRec523[0] + fRec522[1]);
			fRec520[0] = fRec522[0];
			double fRec521 = fRec524;
			fRec519[0] = (fTemp262 + (fTemp263 + (fRec521 + fRec519[1])));
			fRec517[0] = fRec519[0];
			double fRec518 = (fTemp262 + (fRec521 + fTemp263));
			fRec516[0] = (fRec517[0] + fRec516[1]);
			fRec514[0] = fRec516[0];
			double fRec515 = fRec518;
			fRec513[0] = (fTemp260 + (fTemp261 + (fRec515 + fRec513[1])));
			fRec511[0] = fRec513[0];
			double fRec512 = (fTemp260 + (fRec515 + fTemp261));
			fRec510[0] = (fRec511[0] + fRec510[1]);
			fRec508[0] = fRec510[0];
			double fRec509 = fRec512;
			double fTemp267 = (fConst25 * fRec526[1]);
			double fTemp268 = (fConst27 * fRec529[1]);
			double fTemp269 = (fConst28 * fRec532[1]);
			double fTemp270 = (fConst30 * (((((8428876436000.0 * fTemp61) + ((433827096800.0 * fTemp59) + (1270495334000.0 * fTemp60))) + (2268553552000.0 * fTemp62)) + (1104370968000.0 * fTemp64)) - ((((((644146534000.0 * fTemp54) + (2462474187000.0 * fTemp55)) + (1823560083000.0 * fTemp56)) + (2897055061000.0 * fTemp57)) + (622184552100.0 * fTemp63)) + (1817729912000.0 * fTemp58))));
			double fTemp271 = (fConst31 * fRec535[1]);
			double fTemp272 = (fConst32 * fRec538[1]);
			fRec540[0] = (fTemp270 + (fTemp271 + (fRec540[1] + fTemp272)));
			fRec538[0] = fRec540[0];
			double fRec539 = ((fTemp272 + fTemp271) + fTemp270);
			fRec537[0] = (fRec537[1] + fRec538[0]);
			fRec535[0] = fRec537[0];
			double fRec536 = fRec539;
			fRec534[0] = ((fTemp268 + (fRec534[1] + fTemp269)) + fRec536);
			fRec532[0] = fRec534[0];
			double fRec533 = ((fTemp269 + fTemp268) + fRec536);
			fRec531[0] = (fRec531[1] + fRec532[0]);
			fRec529[0] = fRec531[0];
			double fRec530 = fRec533;
			fRec528[0] = ((fRec528[1] + fTemp267) + fRec530);
			fRec526[0] = fRec528[0];
			double fRec527 = (fTemp267 + fRec530);
			double fTemp273 = (fConst4 * ((18415503600000.0 * fTemp15) - ((4182360234000.0 * fTemp13) + (9089136794000.0 * fTemp14))));
			double fTemp274 = (fConst5 * fRec541[1]);
			fRec543[0] = (fTemp273 + (fRec543[1] + fTemp274));
			fRec541[0] = fRec543[0];
			double fRec542 = (fTemp274 + fTemp273);
			double fTemp275 = (fConst7 * ((((5269431535000.0 * fTemp19) + (3010954920000.0 * fTemp20)) + (8557958458000.0 * fTemp22)) - ((300243101500.0 * fTemp21) + (9389048704000.0 * fTemp18))));
			double fTemp276 = (fConst9 * fRec544[1]);
			double fTemp277 = (fConst10 * fRec547[1]);
			fRec549[0] = (fTemp275 + (fTemp276 + (fRec549[1] + fTemp277)));
			fRec547[0] = fRec549[0];
			double fRec548 = ((fTemp277 + fTemp276) + fTemp275);
			fRec546[0] = (fRec546[1] + fRec547[0]);
			fRec544[0] = fRec546[0];
			double fRec545 = fRec548;
			double fTemp278 = (fConst12 * fRec550[1]);
			double fTemp279 = (fConst14 * (((1582046958000.0 * fTemp33) + (((3931653406000.0 * fTemp30) + (4503113122000.0 * fTemp31)) + (13373041410000.0 * fTemp32))) - (((5211821744000.0 * fTemp27) + (13736636170000.0 * fTemp28)) + (7891608282000.0 * fTemp29))));
			double fTemp280 = (fConst15 * fRec553[1]);
			double fTemp281 = (fConst16 * fRec556[1]);
			fRec558[0] = (fTemp279 + (fTemp280 + (fRec558[1] + fTemp281)));
			fRec556[0] = fRec558[0];
			double fRec557 = ((fTemp281 + fTemp280) + fTemp279);
			fRec555[0] = (fRec555[1] + fRec556[0]);
			fRec553[0] = fRec555[0];
			double fRec554 = fRec557;
			fRec552[0] = ((fRec552[1] + fTemp278) + fRec554);
			fRec550[0] = fRec552[0];
			double fRec551 = (fTemp278 + fRec554);
			double fTemp282 = (fConst18 * fRec559[1]);
			double fTemp283 = (fConst19 * fRec562[1]);
			double fTemp284 = (fConst21 * (((((542091320200.0 * fTemp43) + (3599226215000.0 * fTemp44)) + (3414551438000.0 * fTemp45)) + (1107757029000.0 * fTemp46)) - (((3127821678000.0 * fTemp42) + (((7938917544000.0 * fTemp39) + (3677854355000.0 * fTemp40)) + (624347388300.0 * fTemp41))) + (1442485933000.0 * fTemp47))));
			double fTemp285 = (fConst22 * fRec565[1]);
			double fTemp286 = (fConst23 * fRec568[1]);
			fRec570[0] = (fTemp284 + (fTemp285 + (fRec570[1] + fTemp286)));
			fRec568[0] = fRec570[0];
			double fRec569 = ((fTemp286 + fTemp285) + fTemp284);
			fRec567[0] = (fRec567[1] + fRec568[0]);
			fRec565[0] = fRec567[0];
			double fRec566 = fRec569;
			fRec564[0] = ((fTemp282 + (fRec564[1] + fTemp283)) + fRec566);
			fRec562[0] = fRec564[0];
			double fRec563 = ((fTemp283 + fTemp282) + fRec566);
			fRec561[0] = (fRec561[1] + fRec562[0]);
			fRec559[0] = fRec561[0];
			double fRec560 = fRec563;
			fVec7[(IOTA & 1023)] = ((((((((798183582800.0 * fTemp96) + ((1306627526000.0 * fTemp95) + ((2946096887000.0 * fTemp94) + ((2445660788000.0 * fTemp93) + ((8614501421000.0 * fTemp92) + ((1911248842000.0 * fTemp91) + ((324635382800.0 * fTemp90) + (fRec509 + (1234314784000.0 * fTemp89))))))))) + fRec527) + fRec542) + fRec545) + fRec551) + fRec560) - ((1939970603000.0 * fTemp97) + ((3088926366000.0 * fTemp7) + ((6213510280000.0 * fTemp8) + ((3756531881000.0 * fTemp9) + ((1011558387000.0 * fTemp10) + ((2732497645000.0 * fTemp12) + ((11750194650000.0 * fTemp11) + (998491131900.0 * fTemp88)))))))));
			output7[i] = FAUSTFLOAT((0.8267575322812053 * (fVec7[((IOTA - iConst43) & 1023)] * fRec129[0])));
			double fTemp287 = (fConst25 * fRec571[1]);
			double fTemp288 = (fConst27 * fRec574[1]);
			double fTemp289 = (fConst28 * fRec577[1]);
			double fTemp290 = (fConst30 * (((((((2185200177000.0 * fTemp54) + (2868151812000.0 * fTemp55)) + (307733807100.0 * fTemp59)) + (171917958100.0 * fTemp56)) + (2605802280000.0 * fTemp57)) + (3547791223000.0 * fTemp58)) - ((2816987184000.0 * fTemp64) + ((135243846400.0 * fTemp63) + (((2147842858000.0 * fTemp60) + (8396210423000.0 * fTemp61)) + (2586544333000.0 * fTemp62))))));
			double fTemp291 = (fConst31 * fRec580[1]);
			double fTemp292 = (fConst32 * fRec583[1]);
			fRec585[0] = (fTemp290 + (fTemp291 + (fRec585[1] + fTemp292)));
			fRec583[0] = fRec585[0];
			double fRec584 = ((fTemp292 + fTemp291) + fTemp290);
			fRec582[0] = (fRec583[0] + fRec582[1]);
			fRec580[0] = fRec582[0];
			double fRec581 = fRec584;
			fRec579[0] = (fTemp288 + (fTemp289 + (fRec581 + fRec579[1])));
			fRec577[0] = fRec579[0];
			double fRec578 = (fTemp288 + (fRec581 + fTemp289));
			fRec576[0] = (fRec577[0] + fRec576[1]);
			fRec574[0] = fRec576[0];
			double fRec575 = fRec578;
			fRec573[0] = (fTemp287 + (fRec575 + fRec573[1]));
			fRec571[0] = fRec573[0];
			double fRec572 = (fRec575 + fTemp287);
			double fTemp293 = (fConst18 * fRec586[1]);
			double fTemp294 = (fConst19 * fRec589[1]);
			double fTemp295 = (fConst21 * (((3563242577000.0 * fTemp42) + (((7803759644000.0 * fTemp39) + (5329576973000.0 * fTemp40)) + (1888339709000.0 * fTemp41))) - ((731482018900.0 * fTemp47) + ((((556286245700.0 * fTemp43) + (5620946752000.0 * fTemp44)) + (2905903939000.0 * fTemp45)) + (152955476000.0 * fTemp46)))));
			double fTemp296 = (fConst22 * fRec592[1]);
			double fTemp297 = (fConst23 * fRec595[1]);
			fRec597[0] = (fTemp295 + (fTemp296 + (fRec597[1] + fTemp297)));
			fRec595[0] = fRec597[0];
			double fRec596 = ((fTemp297 + fTemp296) + fTemp295);
			fRec594[0] = (fRec595[0] + fRec594[1]);
			fRec592[0] = fRec594[0];
			double fRec593 = fRec596;
			fRec591[0] = (fTemp293 + (fTemp294 + (fRec593 + fRec591[1])));
			fRec589[0] = fRec591[0];
			double fRec590 = (fTemp293 + (fRec593 + fTemp294));
			fRec588[0] = (fRec589[0] + fRec588[1]);
			fRec586[0] = fRec588[0];
			double fRec587 = fRec590;
			double fTemp298 = (fConst12 * fRec598[1]);
			double fTemp299 = (fConst14 * (((((7253234592000.0 * fTemp27) + (14811837080000.0 * fTemp28)) + (10403369380000.0 * fTemp29)) + (182593124800.0 * fTemp33)) - (((6517413871000.0 * fTemp30) + (3627935217000.0 * fTemp31)) + (15099503250000.0 * fTemp32))));
			double fTemp300 = (fConst15 * fRec601[1]);
			double fTemp301 = (fConst16 * fRec604[1]);
			fRec606[0] = (fTemp299 + (fTemp300 + (fRec606[1] + fTemp301)));
			fRec604[0] = fRec606[0];
			double fRec605 = ((fTemp301 + fTemp300) + fTemp299);
			fRec603[0] = (fRec604[0] + fRec603[1]);
			fRec601[0] = fRec603[0];
			double fRec602 = fRec605;
			fRec600[0] = (fTemp298 + (fRec602 + fRec600[1]));
			fRec598[0] = fRec600[0];
			double fRec599 = (fRec602 + fTemp298);
			double fTemp302 = (fConst4 * (((2568185456000.0 * fTemp13) + (8070701176000.0 * fTemp14)) - (20843328650000.0 * fTemp15)));
			double fTemp303 = (fConst5 * fRec607[1]);
			fRec609[0] = (fTemp302 + (fRec609[1] + fTemp303));
			fRec607[0] = fRec609[0];
			double fRec608 = (fTemp303 + fTemp302);
			double fTemp304 = (fConst7 * ((10700710550000.0 * fTemp18) - ((((2965675019000.0 * fTemp19) + (3927891946000.0 * fTemp20)) + (1206215738000.0 * fTemp21)) + (10267895820000.0 * fTemp22))));
			double fTemp305 = (fConst9 * fRec610[1]);
			double fTemp306 = (fConst10 * fRec613[1]);
			fRec615[0] = (fTemp304 + (fTemp305 + (fRec615[1] + fTemp306)));
			fRec613[0] = fRec615[0];
			double fRec614 = ((fTemp306 + fTemp305) + fTemp304);
			fRec612[0] = (fRec613[0] + fRec612[1]);
			fRec610[0] = fRec612[0];
			double fRec611 = fRec614;
			double fTemp307 = (fConst34 * fRec616[1]);
			double fTemp308 = (fConst35 * fRec619[1]);
			double fTemp309 = (fConst37 * fRec622[1]);
			double fTemp310 = (fConst38 * fRec625[1]);
			double fTemp311 = (fConst40 * ((((1544487019000.0 * fTemp77) + (1967950902000.0 * fTemp72)) + (1798190334000.0 * fTemp73)) - ((2016803894000.0 * fTemp84) + (((380308760900.0 * fTemp82) + ((3982807218000.0 * fTemp81) + ((1881959375000.0 * fTemp80) + ((2560588640000.0 * fTemp79) + ((((2348268280000.0 * fTemp74) + (4609779457000.0 * fTemp75)) + (2614806984000.0 * fTemp76)) + (3547720405000.0 * fTemp78)))))) + (1707589230000.0 * fTemp83)))));
			double fTemp312 = (fConst41 * fRec628[1]);
			double fTemp313 = (fConst42 * fRec631[1]);
			fRec633[0] = (fTemp311 + (fTemp312 + (fRec633[1] + fTemp313)));
			fRec631[0] = fRec633[0];
			double fRec632 = ((fTemp313 + fTemp312) + fTemp311);
			fRec630[0] = (fRec630[1] + fRec631[0]);
			fRec628[0] = fRec630[0];
			double fRec629 = fRec632;
			fRec627[0] = ((fTemp309 + (fRec627[1] + fTemp310)) + fRec629);
			fRec625[0] = fRec627[0];
			double fRec626 = ((fTemp310 + fTemp309) + fRec629);
			fRec624[0] = (fRec624[1] + fRec625[0]);
			fRec622[0] = fRec624[0];
			double fRec623 = fRec626;
			fRec621[0] = ((fTemp307 + (fRec621[1] + fTemp308)) + fRec623);
			fRec619[0] = fRec621[0];
			double fRec620 = ((fTemp308 + fTemp307) + fRec623);
			fRec618[0] = (fRec618[1] + fRec619[0]);
			fRec616[0] = fRec618[0];
			double fRec617 = fRec620;
			fVec8[(IOTA & 1023)] = ((((1488293728000.0 * fTemp97) + ((3536789411000.0 * fTemp7) + ((5881168597000.0 * fTemp8) + ((4236984879000.0 * fTemp9) + ((1137493949000.0 * fTemp10) + ((1946431894000.0 * fTemp12) + (((15502088510000.0 * fTemp11) + (fRec572 + (fRec587 + (fRec599 + (fRec608 + fRec611))))) + (1715761675000.0 * fTemp88)))))))) + fRec617) - ((934371035600.0 * fTemp96) + ((1749589381000.0 * fTemp95) + ((1687769933000.0 * fTemp94) + ((2785337529000.0 * fTemp93) + ((((1785819121000.0 * fTemp89) + (349390901200.0 * fTemp90)) + (571846894400.0 * fTemp91)) + (9790416763000.0 * fTemp92)))))));
			output8[i] = FAUSTFLOAT((0.8267575322812053 * (fVec8[((IOTA - iConst43) & 1023)] * fRec129[0])));
			double fTemp314 = (fConst40 * (((1140700879000.0 * fTemp84) + (((1212695512000.0 * fTemp82) + ((4660441939000.0 * fTemp81) + ((328418987100.0 * fTemp80) + ((((((3560623442000.0 * fTemp74) + (3717010961000.0 * fTemp75)) + (1756626372000.0 * fTemp76)) + (184221930500.0 * fTemp77)) + (3054652349000.0 * fTemp78)) + (2492357512000.0 * fTemp79))))) + (2245278273000.0 * fTemp83))) - ((1784968082000.0 * fTemp72) + (1965504158000.0 * fTemp73))));
			double fTemp315 = (fConst41 * fRec646[1]);
			double fTemp316 = (fConst42 * fRec649[1]);
			fRec651[0] = (fTemp314 + (fTemp315 + (fRec651[1] + fTemp316)));
			fRec649[0] = fRec651[0];
			double fRec650 = ((fTemp316 + fTemp315) + fTemp314);
			fRec648[0] = (fRec648[1] + fRec649[0]);
			fRec646[0] = fRec648[0];
			double fRec647 = fRec650;
			double fTemp317 = (fConst37 * fRec640[1]);
			double fTemp318 = (fConst38 * fRec643[1]);
			fRec645[0] = (fRec647 + (fTemp317 + (fRec645[1] + fTemp318)));
			fRec643[0] = fRec645[0];
			double fRec644 = ((fTemp318 + fTemp317) + fRec647);
			fRec642[0] = (fRec642[1] + fRec643[0]);
			fRec640[0] = fRec642[0];
			double fRec641 = fRec644;
			double fTemp319 = (fConst34 * fRec634[1]);
			double fTemp320 = (fConst35 * fRec637[1]);
			fRec639[0] = (fRec641 + (fTemp319 + (fRec639[1] + fTemp320)));
			fRec637[0] = fRec639[0];
			double fRec638 = ((fTemp320 + fTemp319) + fRec641);
			fRec636[0] = (fRec636[1] + fRec637[0]);
			fRec634[0] = fRec636[0];
			double fRec635 = fRec638;
			double fTemp321 = (fConst25 * fRec652[1]);
			double fTemp322 = (fConst27 * fRec655[1]);
			double fTemp323 = (fConst28 * fRec658[1]);
			double fTemp324 = (fConst30 * (((3037456182000.0 * fTemp64) + ((795614130700.0 * fTemp63) + (((10003636260000.0 * fTemp61) + ((1090244128000.0 * fTemp59) + (1899871249000.0 * fTemp60))) + (1489643608000.0 * fTemp62)))) - (((((4229666639000.0 * fTemp54) + (1735200421000.0 * fTemp55)) + (1475945177000.0 * fTemp56)) + (3589141036000.0 * fTemp57)) + (3070888555000.0 * fTemp58))));
			double fTemp325 = (fConst31 * fRec661[1]);
			double fTemp326 = (fConst32 * fRec664[1]);
			fRec666[0] = (fTemp324 + (fTemp325 + (fRec666[1] + fTemp326)));
			fRec664[0] = fRec666[0];
			double fRec665 = ((fTemp326 + fTemp325) + fTemp324);
			fRec663[0] = (fRec663[1] + fRec664[0]);
			fRec661[0] = fRec663[0];
			double fRec662 = fRec665;
			fRec660[0] = ((fTemp322 + (fRec660[1] + fTemp323)) + fRec662);
			fRec658[0] = fRec660[0];
			double fRec659 = ((fTemp323 + fTemp322) + fRec662);
			fRec657[0] = (fRec657[1] + fRec658[0]);
			fRec655[0] = fRec657[0];
			double fRec656 = fRec659;
			fRec654[0] = ((fRec654[1] + fTemp321) + fRec656);
			fRec652[0] = fRec654[0];
			double fRec653 = (fTemp321 + fRec656);
			double fTemp327 = (fConst18 * fRec667[1]);
			double fTemp328 = (fConst19 * fRec670[1]);
			double fTemp329 = (fConst21 * (((((2806113791000.0 * fTemp43) + (4750349683000.0 * fTemp44)) + (3963511099000.0 * fTemp45)) + (875952507500.0 * fTemp47)) - ((331388908400.0 * fTemp46) + ((4978156282000.0 * fTemp42) + (((9368525334000.0 * fTemp39) + (5111186929000.0 * fTemp40)) + (476326691700.0 * fTemp41))))));
			double fTemp330 = (fConst22 * fRec673[1]);
			double fTemp331 = (fConst23 * fRec676[1]);
			fRec678[0] = (fTemp329 + (fTemp330 + (fRec678[1] + fTemp331)));
			fRec676[0] = fRec678[0];
			double fRec677 = ((fTemp331 + fTemp330) + fTemp329);
			fRec675[0] = (fRec675[1] + fRec676[0]);
			fRec673[0] = fRec675[0];
			double fRec674 = fRec677;
			fRec672[0] = ((fTemp327 + (fRec672[1] + fTemp328)) + fRec674);
			fRec670[0] = fRec672[0];
			double fRec671 = ((fTemp328 + fTemp327) + fRec674);
			fRec669[0] = (fRec669[1] + fRec670[0]);
			fRec667[0] = fRec669[0];
			double fRec668 = fRec671;
			double fTemp332 = (fConst12 * fRec679[1]);
			double fTemp333 = (fConst14 * ((((4544115969000.0 * fTemp30) + (4537578683000.0 * fTemp31)) + (16756682930000.0 * fTemp32)) - ((((7024147149000.0 * fTemp27) + (16478164780000.0 * fTemp28)) + (9125393345000.0 * fTemp29)) + (1280772814000.0 * fTemp33))));
			double fTemp334 = (fConst15 * fRec682[1]);
			double fTemp335 = (fConst16 * fRec685[1]);
			fRec687[0] = (fTemp333 + (fTemp334 + (fRec687[1] + fTemp335)));
			fRec685[0] = fRec687[0];
			double fRec686 = ((fTemp335 + fTemp334) + fTemp333);
			fRec684[0] = (fRec684[1] + fRec685[0]);
			fRec682[0] = fRec684[0];
			double fRec683 = fRec686;
			fRec681[0] = ((fRec681[1] + fTemp332) + fRec683);
			fRec679[0] = fRec681[0];
			double fRec680 = (fTemp332 + fRec683);
			double fTemp336 = (fConst7 * ((((4999864200000.0 * fTemp19) + (3864609448000.0 * fTemp20)) + (10277784280000.0 * fTemp22)) - ((222727266900.0 * fTemp21) + (9399592877000.0 * fTemp18))));
			double fTemp337 = (fConst9 * fRec688[1]);
			double fTemp338 = (fConst10 * fRec691[1]);
			fRec693[0] = (fTemp336 + (fTemp337 + (fRec693[1] + fTemp338)));
			fRec691[0] = fRec693[0];
			double fRec692 = ((fTemp338 + fTemp337) + fTemp336);
			fRec690[0] = (fRec690[1] + fRec691[0]);
			fRec688[0] = fRec690[0];
			double fRec689 = fRec692;
			double fTemp339 = (fConst4 * ((22130974100000.0 * fTemp15) - ((3837499561000.0 * fTemp13) + (11279567360000.0 * fTemp14))));
			double fTemp340 = (fConst5 * fRec694[1]);
			fRec696[0] = (fTemp339 + (fRec696[1] + fTemp340));
			fRec694[0] = fRec696[0];
			double fRec695 = (fTemp340 + fTemp339);
			fVec9[(IOTA & 1023)] = ((fRec635 + (fRec653 + (fRec668 + (fRec680 + (fRec689 + (fRec695 + ((292793224500.0 * fTemp96) + ((1522683482000.0 * fTemp95) + (((4347381937000.0 * fTemp93) + (((2860766389000.0 * fTemp89) + (1812924604000.0 * fTemp91)) + (10405649130000.0 * fTemp92))) + (1723948527000.0 * fTemp94)))))))))) - ((683699467400.0 * fTemp97) + ((3933731848000.0 * fTemp7) + ((7291219388000.0 * fTemp8) + ((4537105821000.0 * fTemp9) + ((1448068337000.0 * fTemp10) + ((1392391857000.0 * fTemp90) + ((1353792940000.0 * fTemp12) + ((14355521270000.0 * fTemp11) + (2151509128000.0 * fTemp88))))))))));
			output9[i] = FAUSTFLOAT((0.8267575322812053 * (fRec129[0] * fVec9[((IOTA - iConst43) & 1023)])));
			double fTemp341 = (fConst34 * fRec697[1]);
			double fTemp342 = (fConst35 * fRec700[1]);
			double fTemp343 = (fConst37 * fRec703[1]);
			double fTemp344 = (fConst38 * fRec706[1]);
			double fTemp345 = (fConst40 * ((((1333868918000.0 * fTemp73) + ((1818318940000.0 * fTemp72) + (477763967600.0 * fTemp82))) + (190866056800.0 * fTemp84)) - (((4391160150000.0 * fTemp81) + ((2094666737000.0 * fTemp80) + ((2770384745000.0 * fTemp79) + (((((3693489918000.0 * fTemp74) + (3747378752000.0 * fTemp75)) + (1750263255000.0 * fTemp76)) + (259463200000.0 * fTemp77)) + (3105384670000.0 * fTemp78))))) + (3799557374000.0 * fTemp83))));
			double fTemp346 = (fConst41 * fRec709[1]);
			double fTemp347 = (fConst42 * fRec712[1]);
			fRec714[0] = (fTemp345 + (fTemp346 + (fRec714[1] + fTemp347)));
			fRec712[0] = fRec714[0];
			double fRec713 = ((fTemp347 + fTemp346) + fTemp345);
			fRec711[0] = (fRec712[0] + fRec711[1]);
			fRec709[0] = fRec711[0];
			double fRec710 = fRec713;
			fRec708[0] = (fTemp343 + (fTemp344 + (fRec710 + fRec708[1])));
			fRec706[0] = fRec708[0];
			double fRec707 = (fTemp343 + (fRec710 + fTemp344));
			fRec705[0] = (fRec706[0] + fRec705[1]);
			fRec703[0] = fRec705[0];
			double fRec704 = fRec707;
			fRec702[0] = (fTemp341 + (fTemp342 + (fRec704 + fRec702[1])));
			fRec700[0] = fRec702[0];
			double fRec701 = (fTemp341 + (fRec704 + fTemp342));
			fRec699[0] = (fRec700[0] + fRec699[1]);
			fRec697[0] = fRec699[0];
			double fRec698 = fRec701;
			double fTemp348 = (fConst25 * fRec715[1]);
			double fTemp349 = (fConst27 * fRec718[1]);
			double fTemp350 = (fConst28 * fRec721[1]);
			double fTemp351 = (fConst30 * (((((((4427033661000.0 * fTemp54) + (1720352330000.0 * fTemp55)) + (1554566072000.0 * fTemp56)) + (2820860153000.0 * fTemp57)) + (255244223100.0 * fTemp63)) + (1156167189000.0 * fTemp58)) - ((((9124541794000.0 * fTemp61) + ((1171358376000.0 * fTemp59) + (1932196624000.0 * fTemp60))) + (3192255626000.0 * fTemp62)) + (1591491236000.0 * fTemp64))));
			double fTemp352 = (fConst31 * fRec724[1]);
			double fTemp353 = (fConst32 * fRec727[1]);
			fRec729[0] = (fTemp351 + (fTemp352 + (fRec729[1] + fTemp353)));
			fRec727[0] = fRec729[0];
			double fRec728 = ((fTemp353 + fTemp352) + fTemp351);
			fRec726[0] = (fRec727[0] + fRec726[1]);
			fRec724[0] = fRec726[0];
			double fRec725 = fRec728;
			fRec723[0] = (fTemp349 + (fTemp350 + (fRec725 + fRec723[1])));
			fRec721[0] = fRec723[0];
			double fRec722 = (fTemp349 + (fRec725 + fTemp350));
			fRec720[0] = (fRec721[0] + fRec720[1]);
			fRec718[0] = fRec720[0];
			double fRec719 = fRec722;
			fRec717[0] = (fTemp348 + (fRec719 + fRec717[1]));
			fRec715[0] = fRec717[0];
			double fRec716 = (fRec719 + fTemp348);
			double fTemp354 = (fConst18 * fRec730[1]);
			double fTemp355 = (fConst19 * fRec733[1]);
			double fTemp356 = (fConst21 * ((((3738380119000.0 * fTemp42) + (((9635957876000.0 * fTemp39) + (5218821549000.0 * fTemp40)) + (2135500079000.0 * fTemp41))) + (1369922791000.0 * fTemp47)) - ((((2972002859000.0 * fTemp43) + (4824068610000.0 * fTemp44)) + (3149146549000.0 * fTemp45)) + (1215470087000.0 * fTemp46))));
			double fTemp357 = (fConst22 * fRec736[1]);
			double fTemp358 = (fConst23 * fRec739[1]);
			fRec741[0] = (fTemp356 + (fTemp357 + (fRec741[1] + fTemp358)));
			fRec739[0] = fRec741[0];
			double fRec740 = ((fTemp358 + fTemp357) + fTemp356);
			fRec738[0] = (fRec739[0] + fRec738[1]);
			fRec736[0] = fRec738[0];
			double fRec737 = fRec740;
			fRec735[0] = (fTemp354 + (fTemp355 + (fRec737 + fRec735[1])));
			fRec733[0] = fRec735[0];
			double fRec734 = (fTemp354 + (fRec737 + fTemp355));
			fRec732[0] = (fRec733[0] + fRec732[1]);
			fRec730[0] = fRec732[0];
			double fRec731 = fRec734;
			double fTemp359 = (fConst12 * fRec742[1]);
			double fTemp360 = (fConst14 * ((((7170337265000.0 * fTemp27) + (16119172910000.0 * fTemp28)) + (11388280210000.0 * fTemp29)) - ((1405390838000.0 * fTemp33) + (((4560717230000.0 * fTemp30) + (4667463982000.0 * fTemp31)) + (15840442450000.0 * fTemp32)))));
			double fTemp361 = (fConst15 * fRec745[1]);
			double fTemp362 = (fConst16 * fRec748[1]);
			fRec750[0] = (fTemp360 + (fTemp361 + (fRec750[1] + fTemp362)));
			fRec748[0] = fRec750[0];
			double fRec749 = ((fTemp362 + fTemp361) + fTemp360);
			fRec747[0] = (fRec748[0] + fRec747[1]);
			fRec745[0] = fRec747[0];
			double fRec746 = fRec749;
			fRec744[0] = (fTemp359 + (fRec746 + fRec744[1]));
			fRec742[0] = fRec744[0];
			double fRec743 = (fRec746 + fTemp359);
			double fTemp363 = (fConst7 * ((12469575130000.0 * fTemp18) - ((((5181396445000.0 * fTemp19) + (3950189590000.0 * fTemp20)) + (1294022324000.0 * fTemp21)) + (11185488780000.0 * fTemp22))));
			double fTemp364 = (fConst9 * fRec751[1]);
			double fTemp365 = (fConst10 * fRec754[1]);
			fRec756[0] = (fTemp363 + (fTemp364 + (fRec756[1] + fTemp365)));
			fRec754[0] = fRec756[0];
			double fRec755 = ((fTemp365 + fTemp364) + fTemp363);
			fRec753[0] = (fRec754[0] + fRec753[1]);
			fRec751[0] = fRec753[0];
			double fRec752 = fRec755;
			double fTemp366 = (fConst4 * (((3960781197000.0 * fTemp13) + (8642269102000.0 * fTemp14)) - (22687532370000.0 * fTemp15)));
			double fTemp367 = (fConst5 * fRec757[1]);
			fRec759[0] = (fTemp366 + (fRec759[1] + fTemp367));
			fRec757[0] = fRec759[0];
			double fRec758 = (fTemp367 + fTemp366);
			fVec10[(IOTA & 1023)] = ((fRec698 + (fRec716 + (fRec731 + (fRec743 + (fRec752 + (fRec758 + ((816880777400.0 * fTemp96) + ((3882979734000.0 * fTemp7) + ((6417199571000.0 * fTemp8) + ((4647335510000.0 * fTemp9) + ((1492319251000.0 * fTemp10) + ((1506734311000.0 * fTemp90) + ((1357790559000.0 * fTemp12) + ((16731537250000.0 * fTemp11) + (2176326280000.0 * fTemp88))))))))))))))) - ((237106423900.0 * fTemp97) + ((1145207170000.0 * fTemp95) + (((2817304137000.0 * fTemp93) + (((2977960669000.0 * fTemp89) + (1895783626000.0 * fTemp91)) + (10625008280000.0 * fTemp92))) + (3264300778000.0 * fTemp94)))));
			output10[i] = FAUSTFLOAT((0.8267575322812053 * (fRec129[0] * fVec10[((IOTA - iConst43) & 1023)])));
			double fTemp368 = (fConst34 * fRec760[1]);
			double fTemp369 = (fConst35 * fRec763[1]);
			double fTemp370 = (fConst37 * fRec766[1]);
			double fTemp371 = (fConst38 * fRec769[1]);
			double fTemp372 = (fConst40 * ((((225377519900.0 * fTemp82) + ((5154036284000.0 * fTemp81) + ((567094094000.0 * fTemp80) + ((2751989116000.0 * fTemp79) + ((((2938847749000.0 * fTemp74) + (5169076018000.0 * fTemp75)) + (2897469407000.0 * fTemp76)) + (4092605515000.0 * fTemp78)))))) + (4591822050000.0 * fTemp83)) - ((((1586820786000.0 * fTemp77) + (2274664452000.0 * fTemp72)) + (1462092348000.0 * fTemp73)) + (1218514106000.0 * fTemp84))));
			double fTemp373 = (fConst41 * fRec772[1]);
			double fTemp374 = (fConst42 * fRec775[1]);
			fRec777[0] = (fTemp372 + (fTemp373 + (fRec777[1] + fTemp374)));
			fRec775[0] = fRec777[0];
			double fRec776 = ((fTemp374 + fTemp373) + fTemp372);
			fRec774[0] = (fRec775[0] + fRec774[1]);
			fRec772[0] = fRec774[0];
			double fRec773 = fRec776;
			fRec771[0] = (fTemp370 + (fTemp371 + (fRec773 + fRec771[1])));
			fRec769[0] = fRec771[0];
			double fRec770 = (fTemp370 + (fRec773 + fTemp371));
			fRec768[0] = (fRec769[0] + fRec768[1]);
			fRec766[0] = fRec768[0];
			double fRec767 = fRec770;
			fRec765[0] = (fTemp368 + (fTemp369 + (fRec767 + fRec765[1])));
			fRec763[0] = fRec765[0];
			double fRec764 = (fTemp368 + (fRec767 + fTemp369));
			fRec762[0] = (fRec763[0] + fRec762[1]);
			fRec760[0] = fRec762[0];
			double fRec761 = fRec764;
			double fTemp375 = (fConst4 * ((24435145260000.0 * fTemp15) - ((3094810856000.0 * fTemp13) + (12039050100000.0 * fTemp14))));
			double fTemp376 = (fConst5 * fRec778[1]);
			fRec780[0] = ((fTemp375 + fRec780[1]) + fTemp376);
			fRec778[0] = fRec780[0];
			double fRec779 = (fTemp375 + fTemp376);
			double fTemp377 = (fConst7 * ((((3643781805000.0 * fTemp19) + (4563068167000.0 * fTemp20)) + (11425883180000.0 * fTemp22)) - ((133723471700.0 * fTemp21) + (11507153010000.0 * fTemp18))));
			double fTemp378 = (fConst9 * fRec781[1]);
			double fTemp379 = (fConst10 * fRec784[1]);
			fRec786[0] = (fTemp377 + (fTemp378 + (fRec786[1] + fTemp379)));
			fRec784[0] = fRec786[0];
			double fRec785 = ((fTemp379 + fTemp378) + fTemp377);
			fRec783[0] = (fRec783[1] + fRec784[0]);
			fRec781[0] = fRec783[0];
			double fRec782 = fRec785;
			double fTemp380 = (fConst12 * fRec787[1]);
			double fTemp381 = (fConst14 * (((529249785200.0 * fTemp33) + (((7338865952000.0 * fTemp30) + (4291681813000.0 * fTemp31)) + (17774482230000.0 * fTemp32))) - (((8413374769000.0 * fTemp27) + (18122659060000.0 * fTemp28)) + (10327212930000.0 * fTemp29))));
			double fTemp382 = (fConst15 * fRec790[1]);
			double fTemp383 = (fConst16 * fRec793[1]);
			fRec795[0] = (fTemp381 + (fTemp382 + (fRec795[1] + fTemp383)));
			fRec793[0] = fRec795[0];
			double fRec794 = ((fTemp383 + fTemp382) + fTemp381);
			fRec792[0] = (fRec792[1] + fRec793[0]);
			fRec790[0] = fRec792[0];
			double fRec791 = fRec794;
			fRec789[0] = ((fRec789[1] + fTemp380) + fRec791);
			fRec787[0] = fRec789[0];
			double fRec788 = (fTemp380 + fRec791);
			double fTemp384 = (fConst18 * fRec796[1]);
			double fTemp385 = (fConst19 * fRec799[1]);
			double fTemp386 = (fConst21 * (((((983898998700.0 * fTemp43) + (6462800734000.0 * fTemp44)) + (4291662299000.0 * fTemp45)) + (871744162600.0 * fTemp46)) - (((5199880915000.0 * fTemp42) + (((9251024526000.0 * fTemp39) + (6190146800000.0 * fTemp40)) + (760540384100.0 * fTemp41))) + (1499179258000.0 * fTemp47))));
			double fTemp387 = (fConst22 * fRec802[1]);
			double fTemp388 = (fConst23 * fRec805[1]);
			fRec807[0] = (fTemp386 + (fTemp387 + (fRec807[1] + fTemp388)));
			fRec805[0] = fRec807[0];
			double fRec806 = ((fTemp388 + fTemp387) + fTemp386);
			fRec804[0] = (fRec804[1] + fRec805[0]);
			fRec802[0] = fRec804[0];
			double fRec803 = fRec806;
			fRec801[0] = ((fTemp384 + (fRec801[1] + fTemp385)) + fRec803);
			fRec799[0] = fRec801[0];
			double fRec800 = ((fTemp385 + fTemp384) + fRec803);
			fRec798[0] = (fRec798[1] + fRec799[0]);
			fRec796[0] = fRec798[0];
			double fRec797 = fRec800;
			double fTemp389 = (fConst25 * fRec808[1]);
			double fTemp390 = (fConst27 * fRec811[1]);
			double fTemp391 = (fConst28 * fRec814[1]);
			double fTemp392 = (fConst30 * (((1675459753000.0 * fTemp64) + ((332238168000.0 * fTemp63) + (((2482367930000.0 * fTemp60) + (10939070000000.0 * fTemp61)) + (2205475631000.0 * fTemp62)))) - ((((((2903820275000.0 * fTemp54) + (3160231521000.0 * fTemp55)) + (186688125700.0 * fTemp59)) + (320895082900.0 * fTemp56)) + (3874491997000.0 * fTemp57)) + (460425302400.0 * fTemp58))));
			double fTemp393 = (fConst31 * fRec817[1]);
			double fTemp394 = (fConst32 * fRec820[1]);
			fRec822[0] = (fTemp392 + (fTemp393 + (fRec822[1] + fTemp394)));
			fRec820[0] = fRec822[0];
			double fRec821 = ((fTemp394 + fTemp393) + fTemp392);
			fRec819[0] = (fRec819[1] + fRec820[0]);
			fRec817[0] = fRec819[0];
			double fRec818 = fRec821;
			fRec816[0] = ((fTemp390 + (fRec816[1] + fTemp391)) + fRec818);
			fRec814[0] = fRec816[0];
			double fRec815 = ((fTemp391 + fTemp390) + fRec818);
			fRec813[0] = (fRec813[1] + fRec814[0]);
			fRec811[0] = fRec813[0];
			double fRec812 = fRec815;
			fRec810[0] = ((fRec810[1] + fTemp389) + fRec812);
			fRec808[0] = fRec810[0];
			double fRec809 = (fTemp389 + fRec812);
			fVec11[(IOTA & 1023)] = ((((((((1105963564000.0 * fTemp97) + (((((((fRec761 + (2250263909000.0 * fTemp89)) + (137994506600.0 * fTemp90)) + (778958478700.0 * fTemp91)) + (11456569410000.0 * fTemp92)) + (4399211985000.0 * fTemp93)) + (3526814052000.0 * fTemp94)) + (878821370600.0 * fTemp95))) + fRec779) + fRec782) + fRec788) + fRec797) + fRec809) - ((1591398049000.0 * fTemp96) + (((((((1926573532000.0 * fTemp88) + (15894266690000.0 * fTemp11)) + (2138000077000.0 * fTemp12)) + (1361531997000.0 * fTemp10)) + (4959565029000.0 * fTemp9)) + (7981116681000.0 * fTemp8)) + (4357613381000.0 * fTemp7))));
			output11[i] = FAUSTFLOAT((0.8267575322812053 * (fVec11[((IOTA - iConst43) & 1023)] * fRec129[0])));
			double fTemp395 = (fConst34 * fRec823[1]);
			double fTemp396 = (fConst35 * fRec826[1]);
			double fTemp397 = (fConst37 * fRec829[1]);
			double fTemp398 = (fConst38 * fRec832[1]);
			double fTemp399 = (fConst40 * (((((404930755100.0 * fTemp77) + (2157939739000.0 * fTemp72)) + (2267259718000.0 * fTemp73)) + (1244463840000.0 * fTemp84)) - (((1500076601000.0 * fTemp82) + ((5443549373000.0 * fTemp81) + ((1853518943000.0 * fTemp80) + ((3149092635000.0 * fTemp79) + ((((1626065104000.0 * fTemp74) + (6499902490000.0 * fTemp75)) + (3099837724000.0 * fTemp76)) + (3035401977000.0 * fTemp78)))))) + (3692782609000.0 * fTemp83))));
			double fTemp400 = (fConst41 * fRec835[1]);
			double fTemp401 = (fConst42 * fRec838[1]);
			fRec840[0] = (fTemp399 + (fTemp400 + (fRec840[1] + fTemp401)));
			fRec838[0] = fRec840[0];
			double fRec839 = ((fTemp401 + fTemp400) + fTemp399);
			fRec837[0] = (fRec838[0] + fRec837[1]);
			fRec835[0] = fRec837[0];
			double fRec836 = fRec839;
			fRec834[0] = (fTemp397 + (fTemp398 + (fRec836 + fRec834[1])));
			fRec832[0] = fRec834[0];
			double fRec833 = (fTemp397 + (fRec836 + fTemp398));
			fRec831[0] = (fRec832[0] + fRec831[1]);
			fRec829[0] = fRec831[0];
			double fRec830 = fRec833;
			fRec828[0] = (fTemp395 + (fTemp396 + (fRec830 + fRec828[1])));
			fRec826[0] = fRec828[0];
			double fRec827 = (fTemp395 + (fRec830 + fTemp396));
			fRec825[0] = (fRec826[0] + fRec825[1]);
			fRec823[0] = fRec825[0];
			double fRec824 = fRec827;
			double fTemp402 = (fConst25 * fRec841[1]);
			double fTemp403 = (fConst27 * fRec844[1]);
			double fTemp404 = (fConst28 * fRec847[1]);
			double fTemp405 = (fConst30 * ((((((1626656097000.0 * fTemp54) + (3259537577000.0 * fTemp55)) + (2124675749000.0 * fTemp56)) + (3464328653000.0 * fTemp57)) + (1988936218000.0 * fTemp58)) - ((3302804501000.0 * fTemp64) + ((1125721346000.0 * fTemp63) + ((((555029565500.0 * fTemp59) + (1969136132000.0 * fTemp60)) + (10448002640000.0 * fTemp61)) + (2327051002000.0 * fTemp62))))));
			double fTemp406 = (fConst31 * fRec850[1]);
			double fTemp407 = (fConst32 * fRec853[1]);
			fRec855[0] = (fTemp405 + (fTemp406 + (fRec855[1] + fTemp407)));
			fRec853[0] = fRec855[0];
			double fRec854 = ((fTemp407 + fTemp406) + fTemp405);
			fRec852[0] = (fRec853[0] + fRec852[1]);
			fRec850[0] = fRec852[0];
			double fRec851 = fRec854;
			fRec849[0] = (fTemp403 + (fTemp404 + (fRec851 + fRec849[1])));
			fRec847[0] = fRec849[0];
			double fRec848 = (fTemp403 + (fRec851 + fTemp404));
			fRec846[0] = (fRec847[0] + fRec846[1]);
			fRec844[0] = fRec846[0];
			double fRec845 = fRec848;
			fRec843[0] = (fTemp402 + (fRec845 + fRec843[1]));
			fRec841[0] = fRec843[0];
			double fRec842 = (fRec845 + fTemp402);
			double fTemp408 = (fConst18 * fRec856[1]);
			double fTemp409 = (fConst19 * fRec859[1]);
			double fTemp410 = (fConst21 * (((174818651500.0 * fTemp46) + ((5492462444000.0 * fTemp42) + (((10892897870000.0 * fTemp39) + (5422908267000.0 * fTemp40)) + (1910583980000.0 * fTemp41)))) - ((((1093390011000.0 * fTemp43) + (5383481354000.0 * fTemp44)) + (3631990147000.0 * fTemp45)) + (730653147800.0 * fTemp47))));
			double fTemp411 = (fConst22 * fRec862[1]);
			double fTemp412 = (fConst23 * fRec865[1]);
			fRec867[0] = (fTemp410 + (fTemp411 + (fRec867[1] + fTemp412)));
			fRec865[0] = fRec867[0];
			double fRec866 = ((fTemp412 + fTemp411) + fTemp410);
			fRec864[0] = (fRec865[0] + fRec864[1]);
			fRec862[0] = fRec864[0];
			double fRec863 = fRec866;
			fRec861[0] = (fTemp408 + (fTemp409 + (fRec863 + fRec861[1])));
			fRec859[0] = fRec861[0];
			double fRec860 = (fTemp408 + (fRec863 + fTemp409));
			fRec858[0] = (fRec859[0] + fRec858[1]);
			fRec856[0] = fRec858[0];
			double fRec857 = fRec860;
			double fTemp413 = (fConst12 * fRec868[1]);
			double fTemp414 = (fConst14 * (((((7552354453000.0 * fTemp27) + (18375409710000.0 * fTemp28)) + (12236639170000.0 * fTemp29)) + (1360998537000.0 * fTemp33)) - (((5767368938000.0 * fTemp30) + (5896607894000.0 * fTemp31)) + (18705481670000.0 * fTemp32))));
			double fTemp415 = (fConst15 * fRec871[1]);
			double fTemp416 = (fConst16 * fRec874[1]);
			fRec876[0] = (fTemp414 + (fTemp415 + (fRec876[1] + fTemp416)));
			fRec874[0] = fRec876[0];
			double fRec875 = ((fTemp416 + fTemp415) + fTemp414);
			fRec873[0] = (fRec874[0] + fRec873[1]);
			fRec871[0] = fRec873[0];
			double fRec872 = fRec875;
			fRec870[0] = (fTemp413 + (fRec872 + fRec870[1]));
			fRec868[0] = fRec870[0];
			double fRec869 = (fRec872 + fTemp413);
			double fTemp417 = (fConst4 * (((5332422326000.0 * fTemp13) + (10583600240000.0 * fTemp14)) - (25708129210000.0 * fTemp15)));
			double fTemp418 = (fConst5 * fRec877[1]);
			fRec879[0] = (fTemp417 + (fRec879[1] + fTemp418));
			fRec877[0] = fRec879[0];
			double fRec878 = (fTemp418 + fTemp417);
			double fTemp419 = (fConst7 * ((12147538860000.0 * fTemp18) - ((((6710759333000.0 * fTemp19) + (4293724854000.0 * fTemp20)) + (1309873305000.0 * fTemp21)) + (12591695730000.0 * fTemp22))));
			double fTemp420 = (fConst9 * fRec880[1]);
			double fTemp421 = (fConst10 * fRec883[1]);
			fRec885[0] = (fTemp419 + (fTemp420 + (fRec885[1] + fTemp421)));
			fRec883[0] = fRec885[0];
			double fRec884 = ((fTemp421 + fTemp420) + fTemp419);
			fRec882[0] = (fRec883[0] + fRec882[1]);
			fRec880[0] = fRec882[0];
			double fRec881 = fRec884;
			fVec12[(IOTA & 1023)] = (((1604898013000.0 * fTemp96) + ((4612454816000.0 * fTemp7) + ((7328652751000.0 * fTemp8) + ((5249613471000.0 * fTemp9) + ((1440168842000.0 * fTemp10) + ((3468302151000.0 * fTemp12) + ((1189742478000.0 * fTemp88) + ((18822702570000.0 * fTemp11) + (fRec824 + (fRec842 + (fRec857 + (fRec869 + (fRec878 + fRec881))))))))))))) - ((1890835472000.0 * fTemp97) + ((1217639836000.0 * fTemp95) + ((2118654626000.0 * fTemp94) + ((4647140675000.0 * fTemp93) + ((((2010624170000.0 * fTemp89) + (156398215000.0 * fTemp90)) + (2307685063000.0 * fTemp91)) + (12100100530000.0 * fTemp92)))))));
			output12[i] = FAUSTFLOAT((0.8267575322812053 * (fVec12[((IOTA - iConst43) & 1023)] * fRec129[0])));
			double fTemp422 = (fConst34 * fRec886[1]);
			double fTemp423 = (fConst35 * fRec889[1]);
			double fTemp424 = (fConst37 * fRec892[1]);
			double fTemp425 = (fConst38 * fRec895[1]);
			double fTemp426 = (fConst40 * ((((4862475647000.0 * fTemp81) + ((1055671362000.0 * fTemp80) + ((2812412760000.0 * fTemp79) + (((((578833860500.0 * fTemp74) + (5791022455000.0 * fTemp75)) + (2052671258000.0 * fTemp76)) + (251683030300.0 * fTemp77)) + (4502447235000.0 * fTemp78))))) + (2433337202000.0 * fTemp83)) - (((2076307239000.0 * fTemp73) + ((2389662286000.0 * fTemp72) + (325359731800.0 * fTemp82))) + (146230833900.0 * fTemp84))));
			double fTemp427 = (fConst41 * fRec898[1]);
			double fTemp428 = (fConst42 * fRec901[1]);
			fRec903[0] = (fTemp426 + (fTemp427 + (fRec903[1] + fTemp428)));
			fRec901[0] = fRec903[0];
			double fRec902 = ((fTemp428 + fTemp427) + fTemp426);
			fRec900[0] = (fRec901[0] + fRec900[1]);
			fRec898[0] = fRec900[0];
			double fRec899 = fRec902;
			fRec897[0] = (fTemp424 + (fTemp425 + (fRec899 + fRec897[1])));
			fRec895[0] = fRec897[0];
			double fRec896 = (fTemp424 + (fRec899 + fTemp425));
			fRec894[0] = (fRec895[0] + fRec894[1]);
			fRec892[0] = fRec894[0];
			double fRec893 = fRec896;
			fRec891[0] = (fTemp422 + (fTemp423 + (fRec893 + fRec891[1])));
			fRec889[0] = fRec891[0];
			double fRec890 = (fTemp422 + (fRec893 + fTemp423));
			fRec888[0] = (fRec889[0] + fRec888[1]);
			fRec886[0] = fRec888[0];
			double fRec887 = fRec890;
			double fTemp429 = (fConst25 * fRec904[1]);
			double fTemp430 = (fConst27 * fRec907[1]);
			double fTemp431 = (fConst28 * fRec910[1]);
			double fTemp432 = (fConst30 * (((((11122062580000.0 * fTemp61) + ((1013840459000.0 * fTemp59) + (2683041153000.0 * fTemp60))) + (3385399692000.0 * fTemp62)) + (3222087151000.0 * fTemp64)) - ((((((2372287807000.0 * fTemp54) + (1863099835000.0 * fTemp55)) + (772844219500.0 * fTemp56)) + (3751076565000.0 * fTemp57)) + (295057924400.0 * fTemp63)) + (3713415344000.0 * fTemp58))));
			double fTemp433 = (fConst31 * fRec913[1]);
			double fTemp434 = (fConst32 * fRec916[1]);
			fRec918[0] = (fTemp432 + (fTemp433 + (fRec918[1] + fTemp434)));
			fRec916[0] = fRec918[0];
			double fRec917 = ((fTemp434 + fTemp433) + fTemp432);
			fRec915[0] = (fRec916[0] + fRec915[1]);
			fRec913[0] = fRec915[0];
			double fRec914 = fRec917;
			fRec912[0] = (fTemp430 + (fTemp431 + (fRec914 + fRec912[1])));
			fRec910[0] = fRec912[0];
			double fRec911 = (fTemp430 + (fRec914 + fTemp431));
			fRec909[0] = (fRec910[0] + fRec909[1]);
			fRec907[0] = fRec909[0];
			double fRec908 = fRec911;
			fRec906[0] = (fTemp429 + (fRec908 + fRec906[1]));
			fRec904[0] = fRec906[0];
			double fRec905 = (fRec908 + fTemp429);
			double fTemp435 = (fConst18 * fRec919[1]);
			double fTemp436 = (fConst19 * fRec922[1]);
			double fTemp437 = (fConst21 * (((684787760700.0 * fTemp47) + ((((3187712932000.0 * fTemp43) + (6400978081000.0 * fTemp44)) + (4356976728000.0 * fTemp45)) + (885235655300.0 * fTemp46))) - ((4217187298000.0 * fTemp42) + (((10970533420000.0 * fTemp39) + (6657725134000.0 * fTemp40)) + (1310784891000.0 * fTemp41)))));
			double fTemp438 = (fConst22 * fRec925[1]);
			double fTemp439 = (fConst23 * fRec928[1]);
			fRec930[0] = (fTemp437 + (fTemp438 + (fRec930[1] + fTemp439)));
			fRec928[0] = fRec930[0];
			double fRec929 = ((fTemp439 + fTemp438) + fTemp437);
			fRec927[0] = (fRec928[0] + fRec927[1]);
			fRec925[0] = fRec927[0];
			double fRec926 = fRec929;
			fRec924[0] = (fTemp435 + (fTemp436 + (fRec926 + fRec924[1])));
			fRec922[0] = fRec924[0];
			double fRec923 = (fTemp435 + (fRec926 + fTemp436));
			fRec921[0] = (fRec922[0] + fRec921[1]);
			fRec919[0] = fRec921[0];
			double fRec920 = fRec923;
			double fTemp440 = (fConst12 * fRec931[1]);
			double fTemp441 = (fConst14 * (((986061307600.0 * fTemp33) + (((4633242989000.0 * fTemp30) + (3894368091000.0 * fTemp31)) + (17351749440000.0 * fTemp32))) - (((7924626520000.0 * fTemp27) + (18428897380000.0 * fTemp28)) + (11089060180000.0 * fTemp29))));
			double fTemp442 = (fConst15 * fRec934[1]);
			double fTemp443 = (fConst16 * fRec937[1]);
			fRec939[0] = (fTemp441 + (fTemp442 + (fRec939[1] + fTemp443)));
			fRec937[0] = fRec939[0];
			double fRec938 = ((fTemp443 + fTemp442) + fTemp441);
			fRec936[0] = (fRec937[0] + fRec936[1]);
			fRec934[0] = fRec936[0];
			double fRec935 = fRec938;
			fRec933[0] = (fTemp440 + (fRec935 + fRec933[1]));
			fRec931[0] = fRec933[0];
			double fRec932 = (fRec935 + fTemp440);
			double fTemp444 = (fConst4 * ((24809333610000.0 * fTemp15) - ((2588974089000.0 * fTemp13) + (11281014120000.0 * fTemp14))));
			double fTemp445 = (fConst5 * fRec940[1]);
			fRec942[0] = (fTemp444 + (fRec942[1] + fTemp445));
			fRec940[0] = fRec942[0];
			double fRec941 = (fTemp445 + fTemp444);
			double fTemp446 = (fConst7 * ((((4658543029000.0 * fTemp19) + (4718762154000.0 * fTemp20)) + (11884929590000.0 * fTemp22)) - ((153730191600.0 * fTemp21) + (13502367990000.0 * fTemp18))));
			double fTemp447 = (fConst9 * fRec943[1]);
			double fTemp448 = (fConst10 * fRec946[1]);
			fRec948[0] = (fTemp446 + (fTemp447 + (fRec948[1] + fTemp448)));
			fRec946[0] = fRec948[0];
			double fRec947 = ((fTemp448 + fTemp447) + fTemp446);
			fRec945[0] = (fRec946[0] + fRec945[1]);
			fRec943[0] = fRec945[0];
			double fRec944 = fRec947;
			fVec13[(IOTA & 1023)] = (((2196480051000.0 * fTemp97) + ((2026833650000.0 * fTemp95) + ((2156839362000.0 * fTemp94) + ((3224284521000.0 * fTemp93) + ((11632195970000.0 * fTemp92) + ((1025110863000.0 * fTemp91) + ((fRec887 + (fRec905 + (fRec920 + (fRec932 + (fRec941 + fRec944))))) + (2379740673000.0 * fTemp89)))))))) - ((858621624400.0 * fTemp96) + ((4211778041000.0 * fTemp7) + ((8086656129000.0 * fTemp8) + ((5077156793000.0 * fTemp9) + ((1517411734000.0 * fTemp10) + ((1513607972000.0 * fTemp90) + ((4048027371000.0 * fTemp12) + ((16177874010000.0 * fTemp11) + (211198432900.0 * fTemp88))))))))));
			output13[i] = FAUSTFLOAT((0.8267575322812053 * (fVec13[((IOTA - iConst43) & 1023)] * fRec129[0])));
			double fTemp449 = (fConst34 * fRec949[1]);
			double fTemp450 = (fConst35 * fRec952[1]);
			double fTemp451 = (fConst37 * fRec955[1]);
			double fTemp452 = (fConst38 * fRec958[1]);
			double fTemp453 = (fConst40 * (((1313011062000.0 * fTemp73) + (((1384088306000.0 * fTemp77) + (2237956069000.0 * fTemp72)) + (245140956000.0 * fTemp82))) - ((1185147290000.0 * fTemp84) + (((4868069168000.0 * fTemp81) + ((1001304893000.0 * fTemp80) + ((2824998143000.0 * fTemp79) + ((((603280147100.0 * fTemp74) + (3958924372000.0 * fTemp75)) + (1912781650000.0 * fTemp76)) + (2595503717000.0 * fTemp78))))) + (2359683740000.0 * fTemp83)))));
			double fTemp454 = (fConst41 * fRec961[1]);
			double fTemp455 = (fConst42 * fRec964[1]);
			fRec966[0] = (fTemp453 + (fTemp454 + (fRec966[1] + fTemp455)));
			fRec964[0] = fRec966[0];
			double fRec965 = ((fTemp455 + fTemp454) + fTemp453);
			fRec963[0] = (fRec964[0] + fRec963[1]);
			fRec961[0] = fRec963[0];
			double fRec962 = fRec965;
			fRec960[0] = (fTemp451 + (fTemp452 + (fRec962 + fRec960[1])));
			fRec958[0] = fRec960[0];
			double fRec959 = (fTemp451 + (fRec962 + fTemp452));
			fRec957[0] = (fRec958[0] + fRec957[1]);
			fRec955[0] = fRec957[0];
			double fRec956 = fRec959;
			fRec954[0] = (fTemp449 + (fTemp450 + (fRec956 + fRec954[1])));
			fRec952[0] = fRec954[0];
			double fRec953 = (fTemp449 + (fRec956 + fTemp450));
			fRec951[0] = (fRec952[0] + fRec951[1]);
			fRec949[0] = fRec951[0];
			double fRec950 = fRec953;
			double fTemp456 = (fConst25 * fRec967[1]);
			double fTemp457 = (fConst27 * fRec970[1]);
			double fTemp458 = (fConst28 * fRec973[1]);
			double fTemp459 = (fConst30 * ((((((((4145090050000.0 * fTemp54) + (1840668840000.0 * fTemp55)) + (19700688990.0 * fTemp59)) + (767053674500.0 * fTemp56)) + (3510963453000.0 * fTemp57)) + (250070115200.0 * fTemp63)) + (3373843034000.0 * fTemp58)) - ((((1761632120000.0 * fTemp60) + (9366332063000.0 * fTemp61)) + (1584201591000.0 * fTemp62)) + (1540590604000.0 * fTemp64))));
			double fTemp460 = (fConst31 * fRec976[1]);
			double fTemp461 = (fConst32 * fRec979[1]);
			fRec981[0] = (fTemp459 + (fTemp460 + (fRec981[1] + fTemp461)));
			fRec979[0] = fRec981[0];
			double fRec980 = ((fTemp461 + fTemp460) + fTemp459);
			fRec978[0] = (fRec979[0] + fRec978[1]);
			fRec976[0] = fRec978[0];
			double fRec977 = fRec980;
			fRec975[0] = (fTemp457 + (fTemp458 + (fRec977 + fRec975[1])));
			fRec973[0] = fRec975[0];
			double fRec974 = (fTemp457 + (fRec977 + fTemp458));
			fRec972[0] = (fRec973[0] + fRec972[1]);
			fRec970[0] = fRec972[0];
			double fRec971 = fRec974;
			fRec969[0] = (fTemp456 + (fRec971 + fRec969[1]));
			fRec967[0] = fRec969[0];
			double fRec968 = (fRec971 + fTemp456);
			double fTemp462 = (fConst18 * fRec982[1]);
			double fTemp463 = (fConst19 * fRec985[1]);
			double fTemp464 = (fConst21 * ((((5185576826000.0 * fTemp42) + (((8732072609000.0 * fTemp39) + (4655716310000.0 * fTemp40)) + (1250115107000.0 * fTemp41))) + (1541586687000.0 * fTemp47)) - ((((2869740995000.0 * fTemp43) + (5965723947000.0 * fTemp44)) + (3253998329000.0 * fTemp45)) + (757868710200.0 * fTemp46))));
			double fTemp465 = (fConst22 * fRec988[1]);
			double fTemp466 = (fConst23 * fRec991[1]);
			fRec993[0] = (fTemp464 + (fTemp465 + (fRec993[1] + fTemp466)));
			fRec991[0] = fRec993[0];
			double fRec992 = ((fTemp466 + fTemp465) + fTemp464);
			fRec990[0] = (fRec991[0] + fRec990[1]);
			fRec988[0] = fRec990[0];
			double fRec989 = fRec992;
			fRec987[0] = (fTemp462 + (fTemp463 + (fRec989 + fRec987[1])));
			fRec985[0] = fRec987[0];
			double fRec986 = (fTemp462 + (fRec989 + fTemp463));
			fRec984[0] = (fRec985[0] + fRec984[1]);
			fRec982[0] = fRec984[0];
			double fRec983 = fRec986;
			double fTemp467 = (fConst12 * fRec994[1]);
			double fTemp468 = (fConst14 * ((((7364716507000.0 * fTemp27) + (16502469550000.0 * fTemp28)) + (10391095870000.0 * fTemp29)) - ((815774653200.0 * fTemp33) + (((6952857319000.0 * fTemp30) + (5530283638000.0 * fTemp31)) + (17563108760000.0 * fTemp32)))));
			double fTemp469 = (fConst15 * fRec997[1]);
			double fTemp470 = (fConst16 * fRec1000[1]);
			fRec1002[0] = (fTemp468 + (fTemp469 + (fRec1002[1] + fTemp470)));
			fRec1000[0] = fRec1002[0];
			double fRec1001 = ((fTemp470 + fTemp469) + fTemp468);
			fRec999[0] = (fRec1000[0] + fRec999[1]);
			fRec997[0] = fRec999[0];
			double fRec998 = fRec1001;
			fRec996[0] = (fTemp467 + (fRec998 + fRec996[1]));
			fRec994[0] = fRec996[0];
			double fRec995 = (fRec998 + fTemp467);
			double fTemp471 = (fConst4 * (((5237777855000.0 * fTemp13) + (10503432560000.0 * fTemp14)) - (23213271230000.0 * fTemp15)));
			double fTemp472 = (fConst5 * fRec1003[1]);
			fRec1005[0] = (fTemp471 + (fRec1005[1] + fTemp472));
			fRec1003[0] = fRec1005[0];
			double fRec1004 = (fTemp472 + fTemp471);
			double fTemp473 = (fConst7 * ((9876466955000.0 * fTemp18) - ((((4444377706000.0 * fTemp19) + (3710726752000.0 * fTemp20)) + (1295997255000.0 * fTemp21)) + (11147654690000.0 * fTemp22))));
			double fTemp474 = (fConst9 * fRec1006[1]);
			double fTemp475 = (fConst10 * fRec1009[1]);
			fRec1011[0] = (fTemp473 + (fTemp474 + (fRec1011[1] + fTemp475)));
			fRec1009[0] = fRec1011[0];
			double fRec1010 = ((fTemp475 + fTemp474) + fTemp473);
			fRec1008[0] = (fRec1009[0] + fRec1008[1]);
			fRec1006[0] = fRec1008[0];
			double fRec1007 = fRec1010;
			fVec14[(IOTA & 1023)] = (((3936952552000.0 * fTemp7) + ((6599825622000.0 * fTemp8) + ((4732593694000.0 * fTemp9) + ((1306406907000.0 * fTemp10) + ((1372528904000.0 * fTemp90) + (((17096863620000.0 * fTemp11) + (fRec950 + (fRec968 + (fRec983 + (fRec995 + (fRec1004 + fRec1007)))))) + (3712336559000.0 * fTemp12))))))) - ((2037138463000.0 * fTemp97) + ((303166553200.0 * fTemp96) + ((1889559227000.0 * fTemp95) + (((4521638178000.0 * fTemp93) + ((((767404707600.0 * fTemp88) + (2613042550000.0 * fTemp89)) + (988177053100.0 * fTemp91)) + (10887068880000.0 * fTemp92))) + (3443015789000.0 * fTemp94))))));
			output14[i] = FAUSTFLOAT((0.8267575322812053 * (fVec14[((IOTA - iConst43) & 1023)] * fRec129[0])));
			double fTemp476 = (fConst34 * fRec1012[1]);
			double fTemp477 = (fConst35 * fRec1015[1]);
			double fTemp478 = (fConst37 * fRec1018[1]);
			double fTemp479 = (fConst38 * fRec1021[1]);
			double fTemp480 = (fConst40 * (((1990236966000.0 * fTemp84) + (((1463245561000.0 * fTemp82) + ((4208020605000.0 * fTemp81) + ((1626558689000.0 * fTemp80) + ((2457156328000.0 * fTemp79) + ((((1593237306000.0 * fTemp74) + (3420523742000.0 * fTemp75)) + (2734721738000.0 * fTemp76)) + (4080147967000.0 * fTemp78)))))) + (3349798366000.0 * fTemp83))) - (((539042088700.0 * fTemp77) + (1828808627000.0 * fTemp72)) + (1301294279000.0 * fTemp73))));
			double fTemp481 = (fConst41 * fRec1024[1]);
			double fTemp482 = (fConst42 * fRec1027[1]);
			fRec1029[0] = (fTemp480 + (fTemp481 + (fRec1029[1] + fTemp482)));
			fRec1027[0] = fRec1029[0];
			double fRec1028 = ((fTemp482 + fTemp481) + fTemp480);
			fRec1026[0] = (fRec1027[0] + fRec1026[1]);
			fRec1024[0] = fRec1026[0];
			double fRec1025 = fRec1028;
			fRec1023[0] = (fTemp478 + (fTemp479 + (fRec1025 + fRec1023[1])));
			fRec1021[0] = fRec1023[0];
			double fRec1022 = (fTemp478 + (fRec1025 + fTemp479));
			fRec1020[0] = (fRec1021[0] + fRec1020[1]);
			fRec1018[0] = fRec1020[0];
			double fRec1019 = fRec1022;
			fRec1017[0] = (fTemp476 + (fTemp477 + (fRec1019 + fRec1017[1])));
			fRec1015[0] = fRec1017[0];
			double fRec1016 = (fTemp476 + (fRec1019 + fTemp477));
			fRec1014[0] = (fRec1015[0] + fRec1014[1]);
			fRec1012[0] = fRec1014[0];
			double fRec1013 = fRec1016;
			double fTemp483 = (fConst25 * fRec1030[1]);
			double fTemp484 = (fConst27 * fRec1033[1]);
			double fTemp485 = (fConst28 * fRec1036[1]);
			double fTemp486 = (fConst30 * (((1553928372000.0 * fTemp64) + ((1067031038000.0 * fTemp63) + (((9941255508000.0 * fTemp61) + ((576922947600.0 * fTemp59) + (2486421467000.0 * fTemp60))) + (2703302367000.0 * fTemp62)))) - (((((4507348318000.0 * fTemp54) + (2989371700000.0 * fTemp55)) + (1948335263000.0 * fTemp56)) + (2961397455000.0 * fTemp57)) + (1408833723000.0 * fTemp58))));
			double fTemp487 = (fConst31 * fRec1039[1]);
			double fTemp488 = (fConst32 * fRec1042[1]);
			fRec1044[0] = (fTemp486 + (fTemp487 + (fRec1044[1] + fTemp488)));
			fRec1042[0] = fRec1044[0];
			double fRec1043 = ((fTemp488 + fTemp487) + fTemp486);
			fRec1041[0] = (fRec1042[0] + fRec1041[1]);
			fRec1039[0] = fRec1041[0];
			double fRec1040 = fRec1043;
			fRec1038[0] = (fTemp484 + (fTemp485 + (fRec1040 + fRec1038[1])));
			fRec1036[0] = fRec1038[0];
			double fRec1037 = (fTemp484 + (fRec1040 + fTemp485));
			fRec1035[0] = (fRec1036[0] + fRec1035[1]);
			fRec1033[0] = fRec1035[0];
			double fRec1034 = fRec1037;
			fRec1032[0] = (fTemp483 + (fRec1034 + fRec1032[1]));
			fRec1030[0] = fRec1032[0];
			double fRec1031 = (fRec1034 + fTemp483);
			double fTemp489 = (fConst18 * fRec1045[1]);
			double fTemp490 = (fConst19 * fRec1048[1]);
			double fTemp491 = (fConst21 * ((((640774481800.0 * fTemp43) + (4500029479000.0 * fTemp44)) + (3949792758000.0 * fTemp45)) - ((1309134464000.0 * fTemp47) + ((319541481900.0 * fTemp46) + ((3780152303000.0 * fTemp42) + (((8798484076000.0 * fTemp39) + (5870728453000.0 * fTemp40)) + (1696771196000.0 * fTemp41)))))));
			double fTemp492 = (fConst22 * fRec1051[1]);
			double fTemp493 = (fConst23 * fRec1054[1]);
			fRec1056[0] = (fTemp491 + (fTemp492 + (fRec1056[1] + fTemp493)));
			fRec1054[0] = fRec1056[0];
			double fRec1055 = ((fTemp493 + fTemp492) + fTemp491);
			fRec1053[0] = (fRec1054[0] + fRec1053[1]);
			fRec1051[0] = fRec1053[0];
			double fRec1052 = fRec1055;
			fRec1050[0] = (fTemp489 + (fTemp490 + (fRec1052 + fRec1050[1])));
			fRec1048[0] = fRec1050[0];
			double fRec1049 = (fTemp489 + (fRec1052 + fTemp490));
			fRec1047[0] = (fRec1048[0] + fRec1047[1]);
			fRec1045[0] = fRec1047[0];
			double fRec1046 = fRec1049;
			double fTemp494 = (fConst12 * fRec1057[1]);
			double fTemp495 = (fConst14 * ((((5511906623000.0 * fTemp30) + (3393121798000.0 * fTemp31)) + (15926605810000.0 * fTemp32)) - ((((6368333248000.0 * fTemp27) + (16363972840000.0 * fTemp28)) + (10512465610000.0 * fTemp29)) + (1451299961000.0 * fTemp33))));
			double fTemp496 = (fConst15 * fRec1060[1]);
			double fTemp497 = (fConst16 * fRec1063[1]);
			fRec1065[0] = (fTemp495 + (fTemp496 + (fRec1065[1] + fTemp497)));
			fRec1063[0] = fRec1065[0];
			double fRec1064 = ((fTemp497 + fTemp496) + fTemp495);
			fRec1062[0] = (fRec1063[0] + fRec1062[1]);
			fRec1060[0] = fRec1062[0];
			double fRec1061 = fRec1064;
			fRec1059[0] = (fTemp494 + (fRec1061 + fRec1059[1]));
			fRec1057[0] = fRec1059[0];
			double fRec1058 = (fRec1061 + fTemp494);
			double fTemp498 = (fConst4 * ((22012736420000.0 * fTemp15) - ((2384024415000.0 * fTemp13) + (8917299037000.0 * fTemp14))));
			double fTemp499 = (fConst5 * fRec1066[1]);
			fRec1068[0] = (fTemp498 + (fRec1068[1] + fTemp499));
			fRec1066[0] = fRec1068[0];
			double fRec1067 = (fTemp499 + fTemp498);
			double fTemp500 = (fConst7 * ((((5947881419000.0 * fTemp19) + (4076932895000.0 * fTemp20)) + (10839626020000.0 * fTemp22)) - ((211421940400.0 * fTemp21) + (11245694850000.0 * fTemp18))));
			double fTemp501 = (fConst9 * fRec1069[1]);
			double fTemp502 = (fConst10 * fRec1072[1]);
			fRec1074[0] = (fTemp500 + (fTemp501 + (fRec1074[1] + fTemp502)));
			fRec1072[0] = fRec1074[0];
			double fRec1073 = ((fTemp502 + fTemp501) + fTemp500);
			fRec1071[0] = (fRec1072[0] + fRec1071[1]);
			fRec1069[0] = fRec1071[0];
			double fRec1070 = fRec1073;
			fVec15[(IOTA & 1023)] = (((1576769237000.0 * fTemp97) + ((875281644300.0 * fTemp96) + ((916648886500.0 * fTemp95) + ((3174701552000.0 * fTemp94) + ((2963610476000.0 * fTemp93) + ((10359023290000.0 * fTemp92) + ((2082172147000.0 * fTemp91) + ((327690156400.0 * fTemp90) + ((2816224165000.0 * fTemp89) + ((1507429783000.0 * fTemp88) + (fRec1013 + (fRec1031 + (fRec1046 + (fRec1058 + (fRec1067 + fRec1070))))))))))))))) - ((3948456272000.0 * fTemp7) + ((7278677938000.0 * fTemp8) + ((4508854430000.0 * fTemp9) + ((1396494965000.0 * fTemp10) + ((14227434820000.0 * fTemp11) + (2844978814000.0 * fTemp12)))))));
			output15[i] = FAUSTFLOAT((0.8267575322812053 * (fVec15[((IOTA - iConst43) & 1023)] * fRec129[0])));
			double fTemp503 = (fConst45 * fRec1075[1]);
			double fTemp504 = (fConst46 * fRec1078[1]);
			double fTemp505 = (fConst48 * fRec1081[1]);
			double fTemp506 = (fConst49 * fRec1084[1]);
			double fTemp507 = (fConst51 * (((24534127150.0 * fTemp73) + ((((((90358523310.0 * fTemp74) + (933439434200.0 * fTemp75)) + (1508100106000.0 * fTemp76)) + (609039857400.0 * fTemp77)) + (461624517500.0 * fTemp79)) + (254428781000.0 * fTemp82))) - ((84264080290.0 * fTemp84) + (((789525060900.0 * fTemp81) + (((707681424200.0 * fTemp72) + (490824500200.0 * fTemp78)) + (1092858741000.0 * fTemp80))) + (370508160800.0 * fTemp83)))));
			double fTemp508 = (fConst52 * fRec1087[1]);
			double fTemp509 = (fConst53 * fRec1090[1]);
			fRec1092[0] = (fTemp507 + (fTemp508 + (fRec1092[1] + fTemp509)));
			fRec1090[0] = fRec1092[0];
			double fRec1091 = ((fTemp509 + fTemp508) + fTemp507);
			fRec1089[0] = (fRec1090[0] + fRec1089[1]);
			fRec1087[0] = fRec1089[0];
			double fRec1088 = fRec1091;
			fRec1086[0] = (fTemp505 + (fTemp506 + (fRec1088 + fRec1086[1])));
			fRec1084[0] = fRec1086[0];
			double fRec1085 = (fTemp505 + (fRec1088 + fTemp506));
			fRec1083[0] = (fRec1084[0] + fRec1083[1]);
			fRec1081[0] = fRec1083[0];
			double fRec1082 = fRec1085;
			fRec1080[0] = (fTemp503 + (fTemp504 + (fRec1082 + fRec1080[1])));
			fRec1078[0] = fRec1080[0];
			double fRec1079 = (fTemp503 + (fRec1082 + fTemp504));
			fRec1077[0] = (fRec1078[0] + fRec1077[1]);
			fRec1075[0] = fRec1077[0];
			double fRec1076 = fRec1079;
			double fTemp510 = (fConst55 * fRec1093[1]);
			double fTemp511 = (fConst57 * fRec1096[1]);
			double fTemp512 = (fConst58 * fRec1099[1]);
			double fTemp513 = (fConst60 * (((21222504350.0 * fTemp64) + ((614914264700.0 * fTemp63) + (((((270151296900.0 * fTemp54) + (1277132606000.0 * fTemp55)) + (1458673739000.0 * fTemp59)) + (177272256000.0 * fTemp56)) + (100142491100.0 * fTemp62)))) - (((1346496597000.0 * fTemp57) + ((601294139300.0 * fTemp60) + (548503240600.0 * fTemp61))) + (106985641000.0 * fTemp58))));
			double fTemp514 = (fConst61 * fRec1102[1]);
			double fTemp515 = (fConst62 * fRec1105[1]);
			fRec1107[0] = (fTemp513 + (fTemp514 + (fRec1107[1] + fTemp515)));
			fRec1105[0] = fRec1107[0];
			double fRec1106 = ((fTemp515 + fTemp514) + fTemp513);
			fRec1104[0] = (fRec1105[0] + fRec1104[1]);
			fRec1102[0] = fRec1104[0];
			double fRec1103 = fRec1106;
			fRec1101[0] = (fTemp511 + (fTemp512 + (fRec1103 + fRec1101[1])));
			fRec1099[0] = fRec1101[0];
			double fRec1100 = (fTemp511 + (fRec1103 + fTemp512));
			fRec1098[0] = (fRec1099[0] + fRec1098[1]);
			fRec1096[0] = fRec1098[0];
			double fRec1097 = fRec1100;
			fRec1095[0] = (fTemp510 + (fRec1097 + fRec1095[1]));
			fRec1093[0] = fRec1095[0];
			double fRec1094 = (fRec1097 + fTemp510);
			double fTemp516 = (fConst64 * fRec1108[1]);
			double fTemp517 = (fConst65 * fRec1111[1]);
			double fTemp518 = (fConst67 * (((12582895780.0 * fTemp47) + ((574094214300.0 * fTemp46) + ((((610147020300.0 * fTemp43) + (1357530726000.0 * fTemp39)) + (1044128341000.0 * fTemp44)) + (986643900300.0 * fTemp42)))) - (((164079460200.0 * fTemp40) + (1131553601000.0 * fTemp45)) + (291673579900.0 * fTemp41))));
			double fTemp519 = (fConst68 * fRec1114[1]);
			double fTemp520 = (fConst69 * fRec1117[1]);
			fRec1119[0] = (fTemp518 + (fTemp519 + (fRec1119[1] + fTemp520)));
			fRec1117[0] = fRec1119[0];
			double fRec1118 = ((fTemp520 + fTemp519) + fTemp518);
			fRec1116[0] = (fRec1117[0] + fRec1116[1]);
			fRec1114[0] = fRec1116[0];
			double fRec1115 = fRec1118;
			fRec1113[0] = (fTemp516 + (fTemp517 + (fRec1115 + fRec1113[1])));
			fRec1111[0] = fRec1113[0];
			double fRec1112 = (fTemp516 + (fRec1115 + fTemp517));
			fRec1110[0] = (fRec1111[0] + fRec1110[1]);
			fRec1108[0] = fRec1110[0];
			double fRec1109 = fRec1112;
			double fTemp521 = (fConst71 * fRec1120[1]);
			double fTemp522 = (fConst73 * (((287321404700.0 * fTemp33) + ((1225739380000.0 * fTemp32) + ((((676993277300.0 * fTemp30) + (1251001564000.0 * fTemp27)) + (409446794700.0 * fTemp31)) + (1073583137000.0 * fTemp29)))) - (761442288000.0 * fTemp28)));
			double fTemp523 = (fConst74 * fRec1123[1]);
			double fTemp524 = (fConst75 * fRec1126[1]);
			fRec1128[0] = (fTemp522 + (fTemp523 + (fRec1128[1] + fTemp524)));
			fRec1126[0] = fRec1128[0];
			double fRec1127 = ((fTemp524 + fTemp523) + fTemp522);
			fRec1125[0] = (fRec1126[0] + fRec1125[1]);
			fRec1123[0] = fRec1125[0];
			double fRec1124 = fRec1127;
			fRec1122[0] = (fTemp521 + (fRec1124 + fRec1122[1]));
			fRec1120[0] = fRec1122[0];
			double fRec1121 = (fRec1124 + fTemp521);
			double fTemp525 = (fConst77 * (((508827858000.0 * fTemp13) + (823798204300.0 * fTemp15)) + (1250958387000.0 * fTemp14)));
			double fTemp526 = (fConst78 * fRec1129[1]);
			fRec1131[0] = (fTemp525 + (fRec1131[1] + fTemp526));
			fRec1129[0] = fRec1131[0];
			double fRec1130 = (fTemp526 + fTemp525);
			double fTemp527 = (fConst80 * (((((801241459700.0 * fTemp19) + (663770443400.0 * fTemp20)) + (129850427700.0 * fTemp21)) + (1655376472000.0 * fTemp22)) + (800451388700.0 * fTemp18)));
			double fTemp528 = (fConst81 * fRec1132[1]);
			double fTemp529 = (fConst82 * fRec1135[1]);
			fRec1137[0] = (fTemp527 + (fTemp528 + (fRec1137[1] + fTemp529)));
			fRec1135[0] = fRec1137[0];
			double fRec1136 = ((fTemp529 + fTemp528) + fTemp527);
			fRec1134[0] = (fRec1135[0] + fRec1134[1]);
			fRec1132[0] = fRec1134[0];
			double fRec1133 = fRec1136;
			fVec16[(IOTA & 511)] = ((((((((((102631002500.0 * fTemp88) + ((1089675063000.0 * fTemp11) + (fRec1076 + (fRec1094 + (fRec1109 + (fRec1121 + (fRec1130 + fRec1133))))))) + (553331934000.0 * fTemp12)) + (1478479467000.0 * fTemp89)) + (894801832100.0 * fTemp90)) + (54031562780.0 * fTemp9)) + (877638040100.0 * fTemp8)) + (202614406300.0 * fTemp92)) + (24071566500.0 * fTemp94)) - (((((281638502100.0 * fTemp7) + (((658452336900.0 * fTemp10) + (852612928600.0 * fTemp91)) + (938176927100.0 * fTemp93))) + (587381837500.0 * fTemp95)) + (534799634200.0 * fTemp96)) + (214442107600.0 * fTemp97)));
			output16[i] = FAUSTFLOAT((0.87553802008608317 * (fVec16[((IOTA - iConst83) & 511)] * fRec129[0])));
			double fTemp530 = (fConst45 * fRec1138[1]);
			double fTemp531 = (fConst46 * fRec1141[1]);
			double fTemp532 = (fConst48 * fRec1144[1]);
			double fTemp533 = (fConst49 * fRec1147[1]);
			double fTemp534 = (fConst51 * ((((463985994600.0 * fTemp79) + ((720732889000.0 * fTemp72) + (502847921000.0 * fTemp78))) + (241169077400.0 * fTemp82)) - ((94329724690.0 * fTemp84) + ((411977698500.0 * fTemp83) + (((774221684900.0 * fTemp81) + (((((85206777300.0 * fTemp74) + (916819403600.0 * fTemp75)) + (1503418415000.0 * fTemp76)) + (613032597200.0 * fTemp77)) + (1087858904000.0 * fTemp80))) + (26209450810.0 * fTemp73))))));
			double fTemp535 = (fConst52 * fRec1150[1]);
			double fTemp536 = (fConst53 * fRec1153[1]);
			fRec1155[0] = (fTemp534 + (fTemp535 + (fRec1155[1] + fTemp536)));
			fRec1153[0] = fRec1155[0];
			double fRec1154 = ((fTemp536 + fTemp535) + fTemp534);
			fRec1152[0] = (fRec1153[0] + fRec1152[1]);
			fRec1150[0] = fRec1152[0];
			double fRec1151 = fRec1154;
			fRec1149[0] = (fTemp532 + (fTemp533 + (fRec1151 + fRec1149[1])));
			fRec1147[0] = fRec1149[0];
			double fRec1148 = (fTemp532 + (fRec1151 + fTemp533));
			fRec1146[0] = (fRec1147[0] + fRec1146[1]);
			fRec1144[0] = fRec1146[0];
			double fRec1145 = fRec1148;
			fRec1143[0] = (fTemp530 + (fTemp531 + (fRec1145 + fRec1143[1])));
			fRec1141[0] = fRec1143[0];
			double fRec1142 = (fTemp530 + (fRec1145 + fTemp531));
			fRec1140[0] = (fRec1141[0] + fRec1140[1]);
			fRec1138[0] = fRec1140[0];
			double fRec1139 = fRec1142;
			double fTemp537 = (fConst55 * fRec1156[1]);
			double fTemp538 = (fConst57 * fRec1159[1]);
			double fTemp539 = (fConst58 * fRec1162[1]);
			double fTemp540 = (fConst60 * (((579638580700.0 * fTemp63) + ((616938676800.0 * fTemp60) + (98536206340.0 * fTemp62))) - ((120516464100.0 * fTemp58) + (((1340715073000.0 * fTemp57) + (((((265608688000.0 * fTemp54) + (1275083612000.0 * fTemp55)) + (1471775884000.0 * fTemp59)) + (178996627000.0 * fTemp56)) + (549618956300.0 * fTemp61))) + (24780417340.0 * fTemp64)))));
			double fTemp541 = (fConst61 * fRec1165[1]);
			double fTemp542 = (fConst62 * fRec1168[1]);
			fRec1170[0] = (fTemp540 + (fTemp541 + (fRec1170[1] + fTemp542)));
			fRec1168[0] = fRec1170[0];
			double fRec1169 = ((fTemp542 + fTemp541) + fTemp540);
			fRec1167[0] = (fRec1168[0] + fRec1167[1]);
			fRec1165[0] = fRec1167[0];
			double fRec1166 = fRec1169;
			fRec1164[0] = (fTemp538 + (fTemp539 + (fRec1166 + fRec1164[1])));
			fRec1162[0] = fRec1164[0];
			double fRec1163 = (fTemp538 + (fRec1166 + fTemp539));
			fRec1161[0] = (fRec1162[0] + fRec1161[1]);
			fRec1159[0] = fRec1161[0];
			double fRec1160 = fRec1163;
			fRec1158[0] = (fTemp537 + (fRec1160 + fRec1158[1]));
			fRec1156[0] = fRec1158[0];
			double fRec1157 = (fRec1160 + fTemp537);
			double fTemp543 = (fConst64 * fRec1171[1]);
			double fTemp544 = (fConst65 * fRec1174[1]);
			double fTemp545 = (fConst67 * (((538578963300.0 * fTemp46) + ((169194393000.0 * fTemp40) + (967702400800.0 * fTemp42))) - ((((((610573782900.0 * fTemp43) + (1372561821000.0 * fTemp39)) + (1062412831000.0 * fTemp44)) + (1135183491000.0 * fTemp45)) + (292050607000.0 * fTemp41)) + (11565230380.0 * fTemp47))));
			double fTemp546 = (fConst68 * fRec1177[1]);
			double fTemp547 = (fConst69 * fRec1180[1]);
			fRec1182[0] = (fTemp545 + (fTemp546 + (fRec1182[1] + fTemp547)));
			fRec1180[0] = fRec1182[0];
			double fRec1181 = ((fTemp547 + fTemp546) + fTemp545);
			fRec1179[0] = (fRec1180[0] + fRec1179[1]);
			fRec1177[0] = fRec1179[0];
			double fRec1178 = fRec1181;
			fRec1176[0] = (fTemp543 + (fTemp544 + (fRec1178 + fRec1176[1])));
			fRec1174[0] = fRec1176[0];
			double fRec1175 = (fTemp543 + (fRec1178 + fTemp544));
			fRec1173[0] = (fRec1174[0] + fRec1173[1]);
			fRec1171[0] = fRec1173[0];
			double fRec1172 = fRec1175;
			double fTemp548 = (fConst71 * fRec1183[1]);
			double fTemp549 = (fConst73 * (((267598749300.0 * fTemp33) + ((1066485514000.0 * fTemp29) + (1201585809000.0 * fTemp32))) - ((((686633308800.0 * fTemp30) + (1275601865000.0 * fTemp27)) + (419980812000.0 * fTemp31)) + (764938530700.0 * fTemp28))));
			double fTemp550 = (fConst74 * fRec1186[1]);
			double fTemp551 = (fConst75 * fRec1189[1]);
			fRec1191[0] = (fTemp549 + (fTemp550 + (fRec1191[1] + fTemp551)));
			fRec1189[0] = fRec1191[0];
			double fRec1190 = ((fTemp551 + fTemp550) + fTemp549);
			fRec1188[0] = (fRec1189[0] + fRec1188[1]);
			fRec1186[0] = fRec1188[0];
			double fRec1187 = fRec1190;
			fRec1185[0] = (fTemp548 + (fRec1187 + fRec1185[1]));
			fRec1183[0] = fRec1185[0];
			double fRec1184 = (fRec1187 + fTemp548);
			double fTemp552 = (fConst77 * (((824306902400.0 * fTemp15) + (1245513952000.0 * fTemp14)) - (525118898700.0 * fTemp13)));
			double fTemp553 = (fConst78 * fRec1192[1]);
			fRec1194[0] = (fTemp552 + (fRec1194[1] + fTemp553));
			fRec1192[0] = fRec1194[0];
			double fRec1193 = (fTemp553 + fTemp552);
			double fTemp554 = (fConst80 * ((((128353618600.0 * fTemp21) + (1646741761000.0 * fTemp22)) + (784267959400.0 * fTemp18)) - ((818804635000.0 * fTemp19) + (683048245200.0 * fTemp20))));
			double fTemp555 = (fConst81 * fRec1195[1]);
			double fTemp556 = (fConst82 * fRec1198[1]);
			fRec1200[0] = (fTemp554 + (fTemp555 + (fRec1200[1] + fTemp556)));
			fRec1198[0] = fRec1200[0];
			double fRec1199 = ((fTemp556 + fTemp555) + fTemp554);
			fRec1197[0] = (fRec1198[0] + fRec1197[1]);
			fRec1195[0] = fRec1197[0];
			double fRec1196 = fRec1199;
			fVec17[(IOTA & 511)] = (((125843212.0 * fTemp94) + ((200742173600.0 * fTemp92) + ((881682268200.0 * fTemp8) + ((867269601700.0 * fTemp91) + (((1091191276000.0 * fTemp11) + (fRec1139 + (fRec1157 + (fRec1172 + (fRec1184 + (fRec1193 + fRec1196)))))) + (664910230000.0 * fTemp10)))))) - ((225268994500.0 * fTemp97) + ((566881854300.0 * fTemp96) + (((265009894000.0 * fTemp7) + ((((((82094146990.0 * fTemp88) + (522229697400.0 * fTemp12)) + (1451685789000.0 * fTemp89)) + (890999873900.0 * fTemp90)) + (55918014460.0 * fTemp9)) + (920236618600.0 * fTemp93))) + (650289045500.0 * fTemp95)))));
			output17[i] = FAUSTFLOAT((0.87553802008608317 * (fVec17[((IOTA - iConst83) & 511)] * fRec129[0])));
			double fTemp557 = (fConst45 * fRec1201[1]);
			double fTemp558 = (fConst46 * fRec1204[1]);
			double fTemp559 = (fConst48 * fRec1207[1]);
			double fTemp560 = (fConst49 * fRec1210[1]);
			double fTemp561 = (fConst51 * (((76889666470.0 * fTemp84) + ((966165822900.0 * fTemp83) + ((((461677792100.0 * fTemp79) + ((1101501485000.0 * fTemp78) + ((((270616476300.0 * fTemp75) + (1464635634000.0 * fTemp76)) + (302280489300.0 * fTemp77)) + (679909136800.0 * fTemp72)))) + (826913707300.0 * fTemp81)) + (174740771200.0 * fTemp73)))) - (((102725545000.0 * fTemp74) + (449967332200.0 * fTemp80)) + (585004464800.0 * fTemp82))));
			double fTemp562 = (fConst52 * fRec1213[1]);
			double fTemp563 = (fConst53 * fRec1216[1]);
			fRec1218[0] = (fTemp561 + (fTemp562 + (fRec1218[1] + fTemp563)));
			fRec1216[0] = fRec1218[0];
			double fRec1217 = ((fTemp563 + fTemp562) + fTemp561);
			fRec1215[0] = (fRec1216[0] + fRec1215[1]);
			fRec1213[0] = fRec1215[0];
			double fRec1214 = fRec1217;
			fRec1212[0] = (fTemp559 + (fTemp560 + (fRec1214 + fRec1212[1])));
			fRec1210[0] = fRec1212[0];
			double fRec1211 = (fTemp559 + (fRec1214 + fTemp560));
			fRec1209[0] = (fRec1210[0] + fRec1209[1]);
			fRec1207[0] = fRec1209[0];
			double fRec1208 = fRec1211;
			fRec1206[0] = (fTemp557 + (fTemp558 + (fRec1208 + fRec1206[1])));
			fRec1204[0] = fRec1206[0];
			double fRec1205 = (fTemp557 + (fRec1208 + fTemp558));
			fRec1203[0] = (fRec1204[0] + fRec1203[1]);
			fRec1201[0] = fRec1203[0];
			double fRec1202 = fRec1205;
			double fTemp564 = (fConst55 * fRec1219[1]);
			double fTemp565 = (fConst57 * fRec1222[1]);
			double fTemp566 = (fConst58 * fRec1225[1]);
			double fTemp567 = (fConst60 * (((285870134800.0 * fTemp58) + (((((75739273240.0 * fTemp54) + (1248652036000.0 * fTemp55)) + (730979000500.0 * fTemp59)) + (1358104341000.0 * fTemp60)) + (148310330000.0 * fTemp64))) - ((1406718710000.0 * fTemp63) + ((103557483600.0 * fTemp62) + ((553731911600.0 * fTemp57) + ((170077370300.0 * fTemp56) + (556135620500.0 * fTemp61)))))));
			double fTemp568 = (fConst61 * fRec1228[1]);
			double fTemp569 = (fConst62 * fRec1231[1]);
			fRec1233[0] = (fTemp567 + (fTemp568 + (fRec1233[1] + fTemp569)));
			fRec1231[0] = fRec1233[0];
			double fRec1232 = ((fTemp569 + fTemp568) + fTemp567);
			fRec1230[0] = (fRec1231[0] + fRec1230[1]);
			fRec1228[0] = fRec1230[0];
			double fRec1229 = fRec1232;
			fRec1227[0] = (fTemp565 + (fTemp566 + (fRec1229 + fRec1227[1])));
			fRec1225[0] = fRec1227[0];
			double fRec1226 = (fTemp565 + (fRec1229 + fTemp566));
			fRec1224[0] = (fRec1225[0] + fRec1224[1]);
			fRec1222[0] = fRec1224[0];
			double fRec1223 = fRec1226;
			fRec1221[0] = (fTemp564 + (fRec1223 + fRec1221[1]));
			fRec1219[0] = fRec1221[0];
			double fRec1220 = (fRec1223 + fTemp564);
			double fTemp570 = (fConst64 * fRec1234[1]);
			double fTemp571 = (fConst65 * fRec1237[1]);
			double fTemp572 = (fConst67 * (((((602650743100.0 * fTemp43) + (682732046100.0 * fTemp39)) + (291761256900.0 * fTemp40)) + (73105687860.0 * fTemp47)) - ((1313805987000.0 * fTemp46) + ((1032643167000.0 * fTemp42) + (((1003811391000.0 * fTemp44) + (1141807439000.0 * fTemp45)) + (155538941300.0 * fTemp41))))));
			double fTemp573 = (fConst68 * fRec1240[1]);
			double fTemp574 = (fConst69 * fRec1243[1]);
			fRec1245[0] = (fTemp572 + (fTemp573 + (fRec1245[1] + fTemp574)));
			fRec1243[0] = fRec1245[0];
			double fRec1244 = ((fTemp574 + fTemp573) + fTemp572);
			fRec1242[0] = (fRec1243[0] + fRec1242[1]);
			fRec1240[0] = fRec1242[0];
			double fRec1241 = fRec1244;
			fRec1239[0] = (fTemp570 + (fTemp571 + (fRec1241 + fRec1239[1])));
			fRec1237[0] = fRec1239[0];
			double fRec1238 = (fTemp570 + (fRec1241 + fTemp571));
			fRec1236[0] = (fRec1237[0] + fRec1236[1]);
			fRec1234[0] = fRec1236[0];
			double fRec1235 = fRec1238;
			double fTemp575 = (fConst71 * fRec1246[1]);
			double fTemp576 = (fConst73 * (((341894833900.0 * fTemp30) + (372670543100.0 * fTemp29)) - ((658702221200.0 * fTemp33) + ((((1203987586000.0 * fTemp27) + (1089011655000.0 * fTemp31)) + (765308978800.0 * fTemp28)) + (1285351628000.0 * fTemp32)))));
			double fTemp577 = (fConst74 * fRec1249[1]);
			double fTemp578 = (fConst75 * fRec1252[1]);
			fRec1254[0] = (fTemp576 + (fTemp577 + (fRec1254[1] + fTemp578)));
			fRec1252[0] = fRec1254[0];
			double fRec1253 = ((fTemp578 + fTemp577) + fTemp576);
			fRec1251[0] = (fRec1252[0] + fRec1251[1]);
			fRec1249[0] = fRec1251[0];
			double fRec1250 = fRec1253;
			fRec1248[0] = (fTemp575 + (fRec1250 + fRec1248[1]));
			fRec1246[0] = fRec1248[0];
			double fRec1247 = (fRec1250 + fTemp575);
			double fTemp579 = (fConst77 * (((834407929300.0 * fTemp15) + (474672490700.0 * fTemp14)) - (1268355948000.0 * fTemp13)));
			double fTemp580 = (fConst78 * fRec1255[1]);
			fRec1257[0] = (fTemp579 + (fRec1257[1] + fTemp580));
			fRec1255[0] = fRec1257[0];
			double fRec1256 = (fTemp580 + fTemp579);
			double fTemp581 = (fConst80 * (((135365869000.0 * fTemp21) + (612809226000.0 * fTemp22)) - (((772092280600.0 * fTemp19) + (1677815608000.0 * fTemp20)) + (841007033900.0 * fTemp18))));
			double fTemp582 = (fConst81 * fRec1258[1]);
			double fTemp583 = (fConst82 * fRec1261[1]);
			fRec1263[0] = (fTemp581 + (fTemp582 + (fRec1263[1] + fTemp583)));
			fRec1261[0] = fRec1263[0];
			double fRec1262 = ((fTemp583 + fTemp582) + fTemp581);
			fRec1260[0] = (fRec1261[0] + fRec1260[1]);
			fRec1258[0] = fRec1260[0];
			double fRec1259 = fRec1262;
			fVec18[(IOTA & 511)] = (((446257741900.0 * fTemp96) + (((((((((((1100877244000.0 * fTemp11) + (fRec1202 + (fRec1220 + (fRec1235 + (fRec1247 + (fRec1256 + fRec1259)))))) + (433442586600.0 * fTemp89)) + (864561103000.0 * fTemp90)) + (818611714200.0 * fTemp91)) + (880336917300.0 * fTemp8)) + (49065792440.0 * fTemp92)) + (981636150600.0 * fTemp93)) + (635702626800.0 * fTemp7)) + (112752217900.0 * fTemp94)) + (1519066933000.0 * fTemp95))) - ((130666384400.0 * fTemp97) + ((((209943045800.0 * fTemp88) + (631851374100.0 * fTemp12)) + (334923730000.0 * fTemp10)) + (207960675400.0 * fTemp9))));
			output18[i] = FAUSTFLOAT((0.87553802008608317 * (fVec18[((IOTA - iConst83) & 511)] * fRec129[0])));
			double fTemp584 = (fConst55 * fRec1264[1]);
			double fTemp585 = (fConst57 * fRec1267[1]);
			double fTemp586 = (fConst58 * fRec1270[1]);
			double fTemp587 = (fConst60 * (((((((182617475000.0 * fTemp54) + (362790424100.0 * fTemp59)) + (184542587500.0 * fTemp56)) + (1312196754000.0 * fTemp60)) + (643904455300.0 * fTemp57)) + (1571396811000.0 * fTemp63)) - ((239842935100.0 * fTemp58) + ((((1237803677000.0 * fTemp55) + (538243627800.0 * fTemp61)) + (93584214270.0 * fTemp62)) + (277384805900.0 * fTemp64)))));
			double fTemp588 = (fConst61 * fRec1273[1]);
			double fTemp589 = (fConst62 * fRec1276[1]);
			fRec1278[0] = (fTemp587 + (fTemp588 + (fRec1278[1] + fTemp589)));
			fRec1276[0] = fRec1278[0];
			double fRec1277 = ((fTemp589 + fTemp588) + fTemp587);
			fRec1275[0] = (fRec1276[0] + fRec1275[1]);
			fRec1273[0] = fRec1275[0];
			double fRec1274 = fRec1277;
			fRec1272[0] = (fTemp585 + (fTemp586 + (fRec1274 + fRec1272[1])));
			fRec1270[0] = fRec1272[0];
			double fRec1271 = (fTemp585 + (fRec1274 + fTemp586));
			fRec1269[0] = (fRec1270[0] + fRec1269[1]);
			fRec1267[0] = fRec1269[0];
			double fRec1268 = fRec1271;
			fRec1266[0] = (fTemp584 + (fRec1268 + fRec1266[1]));
			fRec1264[0] = fRec1266[0];
			double fRec1265 = (fRec1268 + fTemp584);
			double fTemp590 = (fConst64 * fRec1279[1]);
			double fTemp591 = (fConst65 * fRec1282[1]);
			double fTemp592 = (fConst67 * ((((((338945672200.0 * fTemp39) + (1125213732000.0 * fTemp44)) + (296143665000.0 * fTemp40)) + (183294648800.0 * fTemp41)) + (1467907603000.0 * fTemp46)) - ((((599295185100.0 * fTemp43) + (1125925029000.0 * fTemp45)) + (913729909300.0 * fTemp42)) + (129778785500.0 * fTemp47))));
			double fTemp593 = (fConst68 * fRec1285[1]);
			double fTemp594 = (fConst69 * fRec1288[1]);
			fRec1290[0] = (fTemp592 + (fTemp593 + (fRec1290[1] + fTemp594)));
			fRec1288[0] = fRec1290[0];
			double fRec1289 = ((fTemp594 + fTemp593) + fTemp592);
			fRec1287[0] = (fRec1288[0] + fRec1287[1]);
			fRec1285[0] = fRec1287[0];
			double fRec1286 = fRec1289;
			fRec1284[0] = (fTemp590 + (fTemp591 + (fRec1286 + fRec1284[1])));
			fRec1282[0] = fRec1284[0];
			double fRec1283 = (fTemp590 + (fRec1286 + fTemp591));
			fRec1281[0] = (fRec1282[0] + fRec1281[1]);
			fRec1279[0] = fRec1281[0];
			double fRec1280 = fRec1283;
			double fTemp595 = (fConst71 * fRec1291[1]);
			double fTemp596 = (fConst73 * ((((169842686800.0 * fTemp30) + (1359448906000.0 * fTemp27)) + (736083033000.0 * fTemp33)) - ((((1028442823000.0 * fTemp31) + (769289220500.0 * fTemp28)) + (430737694200.0 * fTemp29)) + (1133499366000.0 * fTemp32))));
			double fTemp597 = (fConst74 * fRec1294[1]);
			double fTemp598 = (fConst75 * fRec1297[1]);
			fRec1299[0] = (fTemp596 + (fTemp597 + (fRec1299[1] + fTemp598)));
			fRec1297[0] = fRec1299[0];
			double fRec1298 = ((fTemp598 + fTemp597) + fTemp596);
			fRec1296[0] = (fRec1297[0] + fRec1296[1]);
			fRec1294[0] = fRec1296[0];
			double fRec1295 = fRec1298;
			fRec1293[0] = (fTemp595 + (fRec1295 + fRec1293[1]));
			fRec1291[0] = fRec1293[0];
			double fRec1292 = (fRec1295 + fTemp595);
			double fTemp599 = (fConst80 * (((878062018800.0 * fTemp19) + (112703745300.0 * fTemp21)) - (((1602958418000.0 * fTemp20) + (712919810900.0 * fTemp22)) + (739122517000.0 * fTemp18))));
			double fTemp600 = (fConst81 * fRec1300[1]);
			double fTemp601 = (fConst82 * fRec1303[1]);
			fRec1305[0] = (fTemp599 + (fTemp600 + (fRec1305[1] + fTemp601)));
			fRec1303[0] = fRec1305[0];
			double fRec1304 = ((fTemp601 + fTemp600) + fTemp599);
			fRec1302[0] = (fRec1303[0] + fRec1302[1]);
			fRec1300[0] = fRec1302[0];
			double fRec1301 = fRec1304;
			double fTemp602 = (fConst45 * fRec1306[1]);
			double fTemp603 = (fConst46 * fRec1309[1]);
			double fTemp604 = (fConst48 * fRec1312[1]);
			double fTemp605 = (fConst49 * fRec1315[1]);
			double fTemp606 = (fConst51 * ((((652911861700.0 * fTemp82) + ((730789072200.0 * fTemp81) + ((522240900300.0 * fTemp80) + ((467766824000.0 * fTemp79) + ((((64217098830.0 * fTemp74) + (606659069900.0 * fTemp75)) + (150095210100.0 * fTemp77)) + (1062585995000.0 * fTemp78)))))) + (121076856900.0 * fTemp84)) - ((809641828300.0 * fTemp83) + (((1448884815000.0 * fTemp76) + (767133786900.0 * fTemp72)) + (328021918000.0 * fTemp73)))));
			double fTemp607 = (fConst52 * fRec1318[1]);
			double fTemp608 = (fConst53 * fRec1321[1]);
			fRec1323[0] = (fTemp606 + (fTemp607 + (fRec1323[1] + fTemp608)));
			fRec1321[0] = fRec1323[0];
			double fRec1322 = ((fTemp608 + fTemp607) + fTemp606);
			fRec1320[0] = (fRec1321[0] + fRec1320[1]);
			fRec1318[0] = fRec1320[0];
			double fRec1319 = fRec1322;
			fRec1317[0] = (fTemp604 + (fTemp605 + (fRec1319 + fRec1317[1])));
			fRec1315[0] = fRec1317[0];
			double fRec1316 = (fTemp604 + (fRec1319 + fTemp605));
			fRec1314[0] = (fRec1315[0] + fRec1314[1]);
			fRec1312[0] = fRec1314[0];
			double fRec1313 = fRec1316;
			fRec1311[0] = (fTemp602 + (fTemp603 + (fRec1313 + fRec1311[1])));
			fRec1309[0] = fRec1311[0];
			double fRec1310 = (fTemp602 + (fRec1313 + fTemp603));
			fRec1308[0] = (fRec1309[0] + fRec1308[1]);
			fRec1306[0] = fRec1308[0];
			double fRec1307 = fRec1310;
			double fTemp609 = (fConst77 * ((810108499700.0 * fTemp15) - ((1219553108000.0 * fTemp13) + (554721818400.0 * fTemp14))));
			double fTemp610 = (fConst78 * fRec1324[1]);
			fRec1326[0] = (fTemp609 + (fRec1326[1] + fTemp610));
			fRec1324[0] = fRec1326[0];
			double fRec1325 = (fTemp610 + fTemp609);
			fVec19[(IOTA & 511)] = (((1946651207.0 * fTemp97) + ((704369028800.0 * fTemp96) + ((869033084900.0 * fTemp93) + ((882741760800.0 * fTemp8) + ((948143774600.0 * fTemp89) + (((1084359807000.0 * fTemp11) + (fRec1265 + (fRec1280 + (fRec1292 + (fRec1301 + (fRec1307 + fRec1325)))))) + (348024800400.0 * fTemp12))))))) - ((1272577183000.0 * fTemp95) + ((183562287900.0 * fTemp94) + ((((190455630400.0 * fTemp9) + ((((261055889400.0 * fTemp88) + (853884347700.0 * fTemp90)) + (165909499500.0 * fTemp10)) + (919829228500.0 * fTemp91))) + (56489515580.0 * fTemp92)) + (711317991900.0 * fTemp7)))));
			output19[i] = FAUSTFLOAT((0.87553802008608317 * (fVec19[((IOTA - iConst83) & 511)] * fRec129[0])));
			double fTemp611 = (fConst45 * fRec1327[1]);
			double fTemp612 = (fConst46 * fRec1330[1]);
			double fTemp613 = (fConst48 * fRec1333[1]);
			double fTemp614 = (fConst49 * fRec1336[1]);
			double fTemp615 = (fConst51 * (((278591777200.0 * fTemp83) + (((1062811460000.0 * fTemp80) + ((443975615000.0 * fTemp79) + (((95165330520.0 * fTemp74) + (1511695678000.0 * fTemp76)) + (452959021200.0 * fTemp78)))) + (165160056200.0 * fTemp73))) - (((306303126000.0 * fTemp82) + ((((981803393500.0 * fTemp75) + (611584180900.0 * fTemp77)) + (693286972800.0 * fTemp72)) + (823327861300.0 * fTemp81))) + (73542976480.0 * fTemp84))));
			double fTemp616 = (fConst52 * fRec1339[1]);
			double fTemp617 = (fConst53 * fRec1342[1]);
			fRec1344[0] = (fTemp615 + (fTemp616 + (fRec1344[1] + fTemp617)));
			fRec1342[0] = fRec1344[0];
			double fRec1343 = ((fTemp617 + fTemp616) + fTemp615);
			fRec1341[0] = (fRec1342[0] + fRec1341[1]);
			fRec1339[0] = fRec1341[0];
			double fRec1340 = fRec1343;
			fRec1338[0] = (fTemp613 + (fTemp614 + (fRec1340 + fRec1338[1])));
			fRec1336[0] = fRec1338[0];
			double fRec1337 = (fTemp613 + (fRec1340 + fTemp614));
			fRec1335[0] = (fRec1336[0] + fRec1335[1]);
			fRec1333[0] = fRec1335[0];
			double fRec1334 = fRec1337;
			fRec1332[0] = (fTemp611 + (fTemp612 + (fRec1334 + fRec1332[1])));
			fRec1330[0] = fRec1332[0];
			double fRec1331 = (fTemp611 + (fRec1334 + fTemp612));
			fRec1329[0] = (fRec1330[0] + fRec1329[1]);
			fRec1327[0] = fRec1329[0];
			double fRec1328 = fRec1331;
			double fTemp618 = (fConst55 * fRec1345[1]);
			double fTemp619 = (fConst57 * fRec1348[1]);
			double fTemp620 = (fConst58 * fRec1351[1]);
			double fTemp621 = (fConst60 * (((76432808060.0 * fTemp58) + (((105232458900.0 * fTemp62) + ((((1279552951000.0 * fTemp55) + (176036555500.0 * fTemp56)) + (557103806800.0 * fTemp60)) + (1311955657000.0 * fTemp57))) + (138604548400.0 * fTemp64))) - ((((279115861500.0 * fTemp54) + (1460686384000.0 * fTemp59)) + (528687328800.0 * fTemp61)) + (735592022500.0 * fTemp63))));
			double fTemp622 = (fConst61 * fRec1354[1]);
			double fTemp623 = (fConst62 * fRec1357[1]);
			fRec1359[0] = (fTemp621 + (fTemp622 + (fRec1359[1] + fTemp623)));
			fRec1357[0] = fRec1359[0];
			double fRec1358 = ((fTemp623 + fTemp622) + fTemp621);
			fRec1356[0] = (fRec1357[0] + fRec1356[1]);
			fRec1354[0] = fRec1356[0];
			double fRec1355 = fRec1358;
			fRec1353[0] = (fTemp619 + (fTemp620 + (fRec1355 + fRec1353[1])));
			fRec1351[0] = fRec1353[0];
			double fRec1352 = (fTemp619 + (fRec1355 + fTemp620));
			fRec1350[0] = (fRec1351[0] + fRec1350[1]);
			fRec1348[0] = fRec1350[0];
			double fRec1349 = fRec1352;
			fRec1347[0] = (fTemp618 + (fRec1349 + fRec1347[1]));
			fRec1345[0] = fRec1347[0];
			double fRec1346 = (fRec1349 + fTemp618);
			double fTemp624 = (fConst64 * fRec1360[1]);
			double fTemp625 = (fConst65 * fRec1363[1]);
			double fTemp626 = (fConst67 * ((((1029323935000.0 * fTemp42) + ((((610845054000.0 * fTemp43) + (1026039466000.0 * fTemp44)) + (157684151000.0 * fTemp40)) + (283115074400.0 * fTemp41))) + (67185383400.0 * fTemp47)) - (((1355824398000.0 * fTemp39) + (1090787863000.0 * fTemp45)) + (682968626000.0 * fTemp46))));
			double fTemp627 = (fConst68 * fRec1366[1]);
			double fTemp628 = (fConst69 * fRec1369[1]);
			fRec1371[0] = (fTemp626 + (fTemp627 + (fRec1371[1] + fTemp628)));
			fRec1369[0] = fRec1371[0];
			double fRec1370 = ((fTemp628 + fTemp627) + fTemp626);
			fRec1368[0] = (fRec1369[0] + fRec1368[1]);
			fRec1366[0] = fRec1368[0];
			double fRec1367 = fRec1370;
			fRec1365[0] = (fTemp624 + (fTemp625 + (fRec1367 + fRec1365[1])));
			fRec1363[0] = fRec1365[0];
			double fRec1364 = (fTemp624 + (fRec1367 + fTemp625));
			fRec1362[0] = (fRec1363[0] + fRec1362[1]);
			fRec1360[0] = fRec1362[0];
			double fRec1361 = fRec1364;
			double fTemp629 = (fConst71 * fRec1372[1]);
			double fTemp630 = (fConst73 * (((1226993857000.0 * fTemp27) + (1277271383000.0 * fTemp32)) - (((((673396650600.0 * fTemp30) + (372156935900.0 * fTemp31)) + (733301948300.0 * fTemp28)) + (1052110326000.0 * fTemp29)) + (338943337900.0 * fTemp33))));
			double fTemp631 = (fConst74 * fRec1375[1]);
			double fTemp632 = (fConst75 * fRec1378[1]);
			fRec1380[0] = (fTemp630 + (fTemp631 + (fRec1380[1] + fTemp632)));
			fRec1378[0] = fRec1380[0];
			double fRec1379 = ((fTemp632 + fTemp631) + fTemp630);
			fRec1377[0] = (fRec1378[0] + fRec1377[1]);
			fRec1375[0] = fRec1377[0];
			double fRec1376 = fRec1379;
			fRec1374[0] = (fTemp629 + (fRec1376 + fRec1374[1]));
			fRec1372[0] = fRec1374[0];
			double fRec1373 = (fRec1376 + fTemp629);
			double fTemp633 = (fConst77 * ((805501400200.0 * fTemp15) - ((474995973400.0 * fTemp13) + (1230575073000.0 * fTemp14))));
			double fTemp634 = (fConst78 * fRec1381[1]);
			fRec1383[0] = (fTemp633 + (fRec1383[1] + fTemp634));
			fRec1381[0] = fRec1383[0];
			double fRec1382 = (fTemp634 + fTemp633);
			double fTemp635 = (fConst80 * ((((784495142400.0 * fTemp19) + (129799101900.0 * fTemp21)) + (833120164700.0 * fTemp18)) - ((613140621300.0 * fTemp20) + (1624485823000.0 * fTemp22))));
			double fTemp636 = (fConst81 * fRec1384[1]);
			double fTemp637 = (fConst82 * fRec1387[1]);
			fRec1389[0] = (fTemp635 + (fTemp636 + (fRec1389[1] + fTemp637)));
			fRec1387[0] = fRec1389[0];
			double fRec1388 = ((fTemp637 + fTemp636) + fTemp635);
			fRec1386[0] = (fRec1387[0] + fRec1386[1]);
			fRec1384[0] = fRec1386[0];
			double fRec1385 = fRec1388;
			fVec20[(IOTA & 511)] = (((205930441800.0 * fTemp97) + ((448971440700.0 * fTemp95) + ((107389275300.0 * fTemp94) + ((336272923800.0 * fTemp7) + ((842953650300.0 * fTemp8) + ((659109856000.0 * fTemp10) + ((897269098500.0 * fTemp90) + (((1067294107000.0 * fTemp11) + (fRec1328 + (fRec1346 + (fRec1361 + (fRec1373 + (fRec1382 + fRec1385)))))) + (631238887600.0 * fTemp12))))))))) - (((978929917800.0 * fTemp93) + (((47813574610.0 * fTemp9) + (((128086695300.0 * fTemp88) + (1564113264000.0 * fTemp89)) + (836135899800.0 * fTemp91))) + (201855245600.0 * fTemp92))) + (466971005300.0 * fTemp96)));
			output20[i] = FAUSTFLOAT((0.87553802008608317 * (fVec20[((IOTA - iConst83) & 511)] * fRec129[0])));
			double fTemp638 = (fConst45 * fRec1390[1]);
			double fTemp639 = (fConst46 * fRec1393[1]);
			double fTemp640 = (fConst48 * fRec1396[1]);
			double fTemp641 = (fConst49 * fRec1399[1]);
			double fTemp642 = (fConst51 * (((282268071600.0 * fTemp83) + (((1062586767000.0 * fTemp80) + ((((980692332000.0 * fTemp75) + (609131527000.0 * fTemp77)) + (698183864700.0 * fTemp72)) + (446273944200.0 * fTemp79))) + (167873223800.0 * fTemp73))) - (((302547892500.0 * fTemp82) + ((((104705142900.0 * fTemp74) + (1502845768000.0 * fTemp76)) + (460710815200.0 * fTemp78)) + (815181257100.0 * fTemp81))) + (81111603280.0 * fTemp84))));
			double fTemp643 = (fConst52 * fRec1402[1]);
			double fTemp644 = (fConst53 * fRec1405[1]);
			fRec1407[0] = (fTemp642 + (fTemp643 + (fRec1407[1] + fTemp644)));
			fRec1405[0] = fRec1407[0];
			double fRec1406 = ((fTemp644 + fTemp643) + fTemp642);
			fRec1404[0] = (fRec1405[0] + fRec1404[1]);
			fRec1402[0] = fRec1404[0];
			double fRec1403 = fRec1406;
			fRec1401[0] = (fTemp640 + (fTemp641 + (fRec1403 + fRec1401[1])));
			fRec1399[0] = fRec1401[0];
			double fRec1400 = (fTemp640 + (fRec1403 + fTemp641));
			fRec1398[0] = (fRec1399[0] + fRec1398[1]);
			fRec1396[0] = fRec1398[0];
			double fRec1397 = fRec1400;
			fRec1395[0] = (fTemp638 + (fTemp639 + (fRec1397 + fRec1395[1])));
			fRec1393[0] = fRec1395[0];
			double fRec1394 = (fTemp638 + (fRec1397 + fTemp639));
			fRec1392[0] = (fRec1393[0] + fRec1392[1]);
			fRec1390[0] = fRec1392[0];
			double fRec1391 = fRec1394;
			double fTemp645 = (fConst55 * fRec1408[1]);
			double fTemp646 = (fConst57 * fRec1411[1]);
			double fTemp647 = (fConst58 * fRec1414[1]);
			double fTemp648 = (fConst60 * (((81108669790.0 * fTemp58) + (((101675023100.0 * fTemp62) + (((285672313700.0 * fTemp54) + (1457542972000.0 * fTemp59)) + (1312952737000.0 * fTemp57))) + (141458310200.0 * fTemp64))) - (((((1276736368000.0 * fTemp55) + (177729128400.0 * fTemp56)) + (565598733200.0 * fTemp60)) + (532207636500.0 * fTemp61)) + (730665276400.0 * fTemp63))));
			double fTemp649 = (fConst61 * fRec1417[1]);
			double fTemp650 = (fConst62 * fRec1420[1]);
			fRec1422[0] = (fTemp648 + (fTemp649 + (fRec1422[1] + fTemp650)));
			fRec1420[0] = fRec1422[0];
			double fRec1421 = ((fTemp650 + fTemp649) + fTemp648);
			fRec1419[0] = (fRec1420[0] + fRec1419[1]);
			fRec1417[0] = fRec1419[0];
			double fRec1418 = fRec1421;
			fRec1416[0] = (fTemp646 + (fTemp647 + (fRec1418 + fRec1416[1])));
			fRec1414[0] = fRec1416[0];
			double fRec1415 = (fTemp646 + (fRec1418 + fTemp647));
			fRec1413[0] = (fRec1414[0] + fRec1413[1]);
			fRec1411[0] = fRec1413[0];
			double fRec1412 = fRec1415;
			fRec1410[0] = (fTemp645 + (fRec1412 + fRec1410[1]));
			fRec1408[0] = fRec1410[0];
			double fRec1409 = (fRec1412 + fTemp645);
			double fTemp651 = (fConst64 * fRec1423[1]);
			double fTemp652 = (fConst65 * fRec1426[1]);
			double fTemp653 = (fConst67 * ((((1017766383000.0 * fTemp42) + ((1355162942000.0 * fTemp39) + (285311511600.0 * fTemp41))) + (68973001090.0 * fTemp47)) - (((((612931951500.0 * fTemp43) + (1033950156000.0 * fTemp44)) + (158157369600.0 * fTemp40)) + (1097722180000.0 * fTemp45)) + (681804775600.0 * fTemp46))));
			double fTemp654 = (fConst68 * fRec1429[1]);
			double fTemp655 = (fConst69 * fRec1432[1]);
			fRec1434[0] = (fTemp653 + (fTemp654 + (fRec1434[1] + fTemp655)));
			fRec1432[0] = fRec1434[0];
			double fRec1433 = ((fTemp655 + fTemp654) + fTemp653);
			fRec1431[0] = (fRec1432[0] + fRec1431[1]);
			fRec1429[0] = fRec1431[0];
			double fRec1430 = fRec1433;
			fRec1428[0] = (fTemp651 + (fTemp652 + (fRec1430 + fRec1428[1])));
			fRec1426[0] = fRec1428[0];
			double fRec1427 = (fTemp651 + (fRec1430 + fTemp652));
			fRec1425[0] = (fRec1426[0] + fRec1425[1]);
			fRec1423[0] = fRec1425[0];
			double fRec1424 = fRec1427;
			double fTemp656 = (fConst71 * fRec1435[1]);
			double fTemp657 = (fConst73 * ((((674787511100.0 * fTemp30) + (379820980300.0 * fTemp31)) + (1267602291000.0 * fTemp32)) - ((((1236085131000.0 * fTemp27) + (738215470500.0 * fTemp28)) + (1051199739000.0 * fTemp29)) + (340969583300.0 * fTemp33))));
			double fTemp658 = (fConst74 * fRec1438[1]);
			double fTemp659 = (fConst75 * fRec1441[1]);
			fRec1443[0] = (fTemp657 + (fTemp658 + (fRec1443[1] + fTemp659)));
			fRec1441[0] = fRec1443[0];
			double fRec1442 = ((fTemp659 + fTemp658) + fTemp657);
			fRec1440[0] = (fRec1441[0] + fRec1440[1]);
			fRec1438[0] = fRec1440[0];
			double fRec1439 = fRec1442;
			fRec1437[0] = (fTemp656 + (fRec1439 + fRec1437[1]));
			fRec1435[0] = fRec1437[0];
			double fRec1436 = (fRec1439 + fTemp656);
			double fTemp660 = (fConst77 * (((479796871900.0 * fTemp13) + (809634552600.0 * fTemp15)) - (1234887009000.0 * fTemp14)));
			double fTemp661 = (fConst78 * fRec1444[1]);
			fRec1446[0] = (fTemp660 + (fRec1446[1] + fTemp661));
			fRec1444[0] = fRec1446[0];
			double fRec1445 = (fTemp661 + fTemp660);
			double fTemp662 = (fConst80 * ((((622008237000.0 * fTemp20) + (129935378200.0 * fTemp21)) + (829899357000.0 * fTemp18)) - ((790105022100.0 * fTemp19) + (1627004356000.0 * fTemp22))));
			double fTemp663 = (fConst81 * fRec1447[1]);
			double fTemp664 = (fConst82 * fRec1450[1]);
			fRec1452[0] = (fTemp662 + (fTemp663 + (fRec1452[1] + fTemp664)));
			fRec1450[0] = fRec1452[0];
			double fRec1451 = ((fTemp664 + fTemp663) + fTemp662);
			fRec1449[0] = (fRec1450[0] + fRec1449[1]);
			fRec1447[0] = fRec1449[0];
			double fRec1448 = fRec1451;
			fVec21[(IOTA & 511)] = (((216887707100.0 * fTemp97) + ((448300920200.0 * fTemp95) + ((108776314000.0 * fTemp94) + ((334477294600.0 * fTemp7) + ((847665713900.0 * fTemp8) + ((48911484780.0 * fTemp9) + ((842174717500.0 * fTemp91) + ((1549997076000.0 * fTemp89) + ((136605144400.0 * fTemp88) + ((1072998168000.0 * fTemp11) + (fRec1391 + (fRec1409 + (fRec1424 + (fRec1436 + (fRec1445 + fRec1448))))))))))))))) - (((967406852500.0 * fTemp93) + ((((636276321000.0 * fTemp12) + (889517244000.0 * fTemp90)) + (658018939000.0 * fTemp10)) + (201912512500.0 * fTemp92))) + (469925263200.0 * fTemp96)));
			output21[i] = FAUSTFLOAT((0.87553802008608317 * (fVec21[((IOTA - iConst83) & 511)] * fRec129[0])));
			double fTemp665 = (fConst45 * fRec1453[1]);
			double fTemp666 = (fConst46 * fRec1456[1]);
			double fTemp667 = (fConst48 * fRec1459[1]);
			double fTemp668 = (fConst49 * fRec1462[1]);
			double fTemp669 = (fConst51 * ((((649257203000.0 * fTemp82) + ((753657256000.0 * fTemp81) + ((514804972100.0 * fTemp80) + (((1461972137000.0 * fTemp76) + (752497038100.0 * fTemp72)) + (468612908900.0 * fTemp79))))) + (106204730600.0 * fTemp84)) - ((848376037700.0 * fTemp83) + (((((65126763810.0 * fTemp74) + (536250258900.0 * fTemp75)) + (179732950200.0 * fTemp77)) + (1075343311000.0 * fTemp78)) + (233616068500.0 * fTemp73)))));
			double fTemp670 = (fConst52 * fRec1465[1]);
			double fTemp671 = (fConst53 * fRec1468[1]);
			fRec1470[0] = (fTemp669 + (fTemp670 + (fRec1470[1] + fTemp671)));
			fRec1468[0] = fRec1470[0];
			double fRec1469 = ((fTemp671 + fTemp670) + fTemp669);
			fRec1467[0] = (fRec1468[0] + fRec1467[1]);
			fRec1465[0] = fRec1467[0];
			double fRec1466 = fRec1469;
			fRec1464[0] = (fTemp667 + (fTemp668 + (fRec1466 + fRec1464[1])));
			fRec1462[0] = fRec1464[0];
			double fRec1463 = (fTemp667 + (fRec1466 + fTemp668));
			fRec1461[0] = (fRec1462[0] + fRec1461[1]);
			fRec1459[0] = fRec1461[0];
			double fRec1460 = fRec1463;
			fRec1458[0] = (fTemp665 + (fTemp666 + (fRec1460 + fRec1458[1])));
			fRec1456[0] = fRec1458[0];
			double fRec1457 = (fTemp665 + (fRec1460 + fTemp666));
			fRec1455[0] = (fRec1456[0] + fRec1455[1]);
			fRec1453[0] = fRec1455[0];
			double fRec1454 = fRec1457;
			double fTemp672 = (fConst55 * fRec1471[1]);
			double fTemp673 = (fConst57 * fRec1474[1]);
			double fTemp674 = (fConst58 * fRec1477[1]);
			double fTemp675 = (fConst60 * ((((1240821860000.0 * fTemp55) + (632586576500.0 * fTemp57)) + (1552675125000.0 * fTemp63)) - ((244706400500.0 * fTemp58) + (((((((158509917300.0 * fTemp54) + (432596334200.0 * fTemp59)) + (186918715500.0 * fTemp56)) + (1323810682000.0 * fTemp60)) + (546296763300.0 * fTemp61)) + (99133609020.0 * fTemp62)) + (196523084400.0 * fTemp64)))));
			double fTemp676 = (fConst61 * fRec1480[1]);
			double fTemp677 = (fConst62 * fRec1483[1]);
			fRec1485[0] = (fTemp675 + (fTemp676 + (fRec1485[1] + fTemp677)));
			fRec1483[0] = fRec1485[0];
			double fRec1484 = ((fTemp677 + fTemp676) + fTemp675);
			fRec1482[0] = (fRec1483[0] + fRec1482[1]);
			fRec1480[0] = fRec1482[0];
			double fRec1481 = fRec1484;
			fRec1479[0] = (fTemp673 + (fTemp674 + (fRec1481 + fRec1479[1])));
			fRec1477[0] = fRec1479[0];
			double fRec1478 = (fTemp673 + (fRec1481 + fTemp674));
			fRec1476[0] = (fRec1477[0] + fRec1476[1]);
			fRec1474[0] = fRec1476[0];
			double fRec1475 = fRec1478;
			fRec1473[0] = (fTemp672 + (fRec1475 + fRec1473[1]));
			fRec1471[0] = fRec1473[0];
			double fRec1472 = (fRec1475 + fTemp672);
			double fTemp678 = (fConst64 * fRec1486[1]);
			double fTemp679 = (fConst65 * fRec1489[1]);
			double fTemp680 = (fConst67 * ((((594819455900.0 * fTemp43) + (176969892800.0 * fTemp41)) + (1442527484000.0 * fTemp46)) - ((((((402461456400.0 * fTemp39) + (1107828148000.0 * fTemp44)) + (290878555500.0 * fTemp40)) + (1134632778000.0 * fTemp45)) + (943752565700.0 * fTemp42)) + (90561829380.0 * fTemp47))));
			double fTemp681 = (fConst68 * fRec1492[1]);
			double fTemp682 = (fConst69 * fRec1495[1]);
			fRec1497[0] = (fTemp680 + (fTemp681 + (fRec1497[1] + fTemp682)));
			fRec1495[0] = fRec1497[0];
			double fRec1496 = ((fTemp682 + fTemp681) + fTemp680);
			fRec1494[0] = (fRec1495[0] + fRec1494[1]);
			fRec1492[0] = fRec1494[0];
			double fRec1493 = fRec1496;
			fRec1491[0] = (fTemp678 + (fTemp679 + (fRec1493 + fRec1491[1])));
			fRec1489[0] = fRec1491[0];
			double fRec1490 = (fTemp678 + (fRec1493 + fTemp679));
			fRec1488[0] = (fRec1489[0] + fRec1488[1]);
			fRec1486[0] = fRec1488[0];
			double fRec1487 = fRec1490;
			double fTemp683 = (fConst71 * fRec1498[1]);
			double fTemp684 = (fConst73 * (((1045863404000.0 * fTemp31) + (717418397200.0 * fTemp33)) - (((((200354836800.0 * fTemp30) + (1328528317000.0 * fTemp27)) + (768511876600.0 * fTemp28)) + (425592455200.0 * fTemp29)) + (1165876607000.0 * fTemp32))));
			double fTemp685 = (fConst74 * fRec1501[1]);
			double fTemp686 = (fConst75 * fRec1504[1]);
			fRec1506[0] = (fTemp684 + (fTemp685 + (fRec1506[1] + fTemp686)));
			fRec1504[0] = fRec1506[0];
			double fRec1505 = ((fTemp686 + fTemp685) + fTemp684);
			fRec1503[0] = (fRec1504[0] + fRec1503[1]);
			fRec1501[0] = fRec1503[0];
			double fRec1502 = fRec1505;
			fRec1500[0] = (fTemp683 + (fRec1502 + fRec1500[1]));
			fRec1498[0] = fRec1500[0];
			double fRec1499 = (fRec1502 + fTemp683);
			double fTemp687 = (fConst77 * (((1220888436000.0 * fTemp13) + (816657151300.0 * fTemp15)) - (539017281200.0 * fTemp14)));
			double fTemp688 = (fConst78 * fRec1507[1]);
			fRec1509[0] = (fTemp687 + (fRec1509[1] + fTemp688));
			fRec1507[0] = fRec1509[0];
			double fRec1508 = (fTemp688 + fTemp687);
			double fTemp689 = (fConst80 * (((1615643755000.0 * fTemp20) + (121526240300.0 * fTemp21)) - (((851535482600.0 * fTemp19) + (697774696500.0 * fTemp22)) + (757019738200.0 * fTemp18))));
			double fTemp690 = (fConst81 * fRec1510[1]);
			double fTemp691 = (fConst82 * fRec1513[1]);
			fRec1515[0] = (fTemp689 + (fTemp690 + (fRec1515[1] + fTemp691)));
			fRec1513[0] = fRec1515[0];
			double fRec1514 = ((fTemp691 + fTemp690) + fTemp689);
			fRec1512[0] = (fRec1513[0] + fRec1512[1]);
			fRec1510[0] = fRec1512[0];
			double fRec1511 = fRec1514;
			fVec22[(IOTA & 511)] = (((30729022000.0 * fTemp97) + ((660240988800.0 * fTemp96) + ((898140534300.0 * fTemp93) + ((887891129700.0 * fTemp8) + ((193813773600.0 * fTemp9) + ((906180461700.0 * fTemp91) + ((197856998900.0 * fTemp10) + ((865961067100.0 * fTemp90) + ((242100300400.0 * fTemp88) + ((1084115730000.0 * fTemp11) + (fRec1454 + (fRec1472 + (fRec1487 + (fRec1499 + (fRec1508 + fRec1511))))))))))))))) - ((1345303869000.0 * fTemp95) + ((128430586300.0 * fTemp94) + ((((405521630700.0 * fTemp12) + (843381689900.0 * fTemp89)) + (55431534690.0 * fTemp92)) + (701293305700.0 * fTemp7)))));
			output22[i] = FAUSTFLOAT((0.87553802008608317 * (fVec22[((IOTA - iConst83) & 511)] * fRec129[0])));
			double fTemp692 = (fConst45 * fRec1516[1]);
			double fTemp693 = (fConst46 * fRec1519[1]);
			double fTemp694 = (fConst48 * fRec1522[1]);
			double fTemp695 = (fConst49 * fRec1525[1]);
			double fTemp696 = (fConst51 * (((88181684270.0 * fTemp84) + ((944405231400.0 * fTemp83) + ((((94212709890.0 * fTemp74) + (463226788800.0 * fTemp79)) + (806223536200.0 * fTemp81)) + (85823306420.0 * fTemp73)))) - (((((((339419664800.0 * fTemp75) + (1479732820000.0 * fTemp76)) + (275759492600.0 * fTemp77)) + (698878091400.0 * fTemp72)) + (1099545954000.0 * fTemp78)) + (463501974200.0 * fTemp80)) + (598939860300.0 * fTemp82))));
			double fTemp697 = (fConst52 * fRec1528[1]);
			double fTemp698 = (fConst53 * fRec1531[1]);
			fRec1533[0] = (fTemp696 + (fTemp697 + (fRec1533[1] + fTemp698)));
			fRec1531[0] = fRec1533[0];
			double fRec1532 = ((fTemp698 + fTemp697) + fTemp696);
			fRec1530[0] = (fRec1531[0] + fRec1530[1]);
			fRec1528[0] = fRec1530[0];
			double fRec1529 = fRec1532;
			fRec1527[0] = (fTemp694 + (fTemp695 + (fRec1529 + fRec1527[1])));
			fRec1525[0] = fRec1527[0];
			double fRec1526 = (fTemp694 + (fRec1529 + fTemp695));
			fRec1524[0] = (fRec1525[0] + fRec1524[1]);
			fRec1522[0] = fRec1524[0];
			double fRec1523 = fRec1526;
			fRec1521[0] = (fTemp692 + (fTemp693 + (fRec1523 + fRec1521[1])));
			fRec1519[0] = fRec1521[0];
			double fRec1520 = (fTemp692 + (fRec1523 + fTemp693));
			fRec1518[0] = (fRec1519[0] + fRec1518[1]);
			fRec1516[0] = fRec1518[0];
			double fRec1517 = fRec1520;
			double fTemp699 = (fConst55 * fRec1534[1]);
			double fTemp700 = (fConst57 * fRec1537[1]);
			double fTemp701 = (fConst58 * fRec1540[1]);
			double fTemp702 = (fConst60 * (((277269124600.0 * fTemp58) + ((174214674800.0 * fTemp56) + (72681330130.0 * fTemp64))) - ((1439177167000.0 * fTemp63) + ((102718314500.0 * fTemp62) + ((571209640800.0 * fTemp57) + (((((96811949600.0 * fTemp54) + (1258383524000.0 * fTemp55)) + (664918487300.0 * fTemp59)) + (1354198143000.0 * fTemp60)) + (554709003800.0 * fTemp61)))))));
			double fTemp703 = (fConst61 * fRec1543[1]);
			double fTemp704 = (fConst62 * fRec1546[1]);
			fRec1548[0] = (fTemp702 + (fTemp703 + (fRec1548[1] + fTemp704)));
			fRec1546[0] = fRec1548[0];
			double fRec1547 = ((fTemp704 + fTemp703) + fTemp702);
			fRec1545[0] = (fRec1546[0] + fRec1545[1]);
			fRec1543[0] = fRec1545[0];
			double fRec1544 = fRec1547;
			fRec1542[0] = (fTemp700 + (fTemp701 + (fRec1544 + fRec1542[1])));
			fRec1540[0] = fRec1542[0];
			double fRec1541 = (fTemp700 + (fRec1544 + fTemp701));
			fRec1539[0] = (fRec1540[0] + fRec1539[1]);
			fRec1537[0] = fRec1539[0];
			double fRec1538 = fRec1541;
			fRec1536[0] = (fTemp699 + (fRec1538 + fRec1536[1]));
			fRec1534[0] = fRec1536[0];
			double fRec1535 = (fRec1538 + fTemp699);
			double fTemp705 = (fConst64 * fRec1549[1]);
			double fTemp706 = (fConst65 * fRec1552[1]);
			double fTemp707 = (fConst67 * (((1031139866000.0 * fTemp44) + (36802192470.0 * fTemp47)) - ((1343123221000.0 * fTemp46) + ((1007761195000.0 * fTemp42) + (((((605059356900.0 * fTemp43) + (619480787700.0 * fTemp39)) + (291072516100.0 * fTemp40)) + (1140614534000.0 * fTemp45)) + (161625540100.0 * fTemp41))))));
			double fTemp708 = (fConst68 * fRec1555[1]);
			double fTemp709 = (fConst69 * fRec1558[1]);
			fRec1560[0] = (fTemp707 + (fTemp708 + (fRec1560[1] + fTemp709)));
			fRec1558[0] = fRec1560[0];
			double fRec1559 = ((fTemp709 + fTemp708) + fTemp707);
			fRec1557[0] = (fRec1558[0] + fRec1557[1]);
			fRec1555[0] = fRec1557[0];
			double fRec1556 = fRec1559;
			fRec1554[0] = (fTemp705 + (fTemp706 + (fRec1556 + fRec1554[1])));
			fRec1552[0] = fRec1554[0];
			double fRec1553 = (fTemp705 + (fRec1556 + fTemp706));
			fRec1551[0] = (fRec1552[0] + fRec1551[1]);
			fRec1549[0] = fRec1551[0];
			double fRec1550 = fRec1553;
			double fTemp710 = (fConst71 * fRec1561[1]);
			double fTemp711 = (fConst73 * ((((1237506606000.0 * fTemp27) + (1083172166000.0 * fTemp31)) + (383525898100.0 * fTemp29)) - ((672628967200.0 * fTemp33) + (((309048691400.0 * fTemp30) + (765128706100.0 * fTemp28)) + (1251123577000.0 * fTemp32)))));
			double fTemp712 = (fConst74 * fRec1564[1]);
			double fTemp713 = (fConst75 * fRec1567[1]);
			fRec1569[0] = (fTemp711 + (fTemp712 + (fRec1569[1] + fTemp713)));
			fRec1567[0] = fRec1569[0];
			double fRec1568 = ((fTemp713 + fTemp712) + fTemp711);
			fRec1566[0] = (fRec1567[0] + fRec1566[1]);
			fRec1564[0] = fRec1566[0];
			double fRec1565 = fRec1568;
			fRec1563[0] = (fTemp710 + (fRec1565 + fRec1563[1]));
			fRec1561[0] = fRec1563[0];
			double fRec1562 = (fRec1565 + fTemp710);
			double fTemp714 = (fConst77 * (((1258171619000.0 * fTemp13) + (830545191900.0 * fTemp15)) + (491947758700.0 * fTemp14)));
			double fTemp715 = (fConst78 * fRec1570[1]);
			fRec1572[0] = (fTemp714 + (fRec1572[1] + fTemp715));
			fRec1570[0] = fRec1572[0];
			double fRec1571 = (fTemp715 + fTemp714);
			double fTemp716 = (fConst80 * (((((794048899400.0 * fTemp19) + (1666931733000.0 * fTemp20)) + (133652423700.0 * fTemp21)) + (633174207500.0 * fTemp22)) - (816467105000.0 * fTemp18)));
			double fTemp717 = (fConst81 * fRec1573[1]);
			double fTemp718 = (fConst82 * fRec1576[1]);
			fRec1578[0] = (fTemp716 + (fTemp717 + (fRec1578[1] + fTemp718)));
			fRec1576[0] = fRec1578[0];
			double fRec1577 = ((fTemp718 + fTemp717) + fTemp716);
			fRec1575[0] = (fRec1576[0] + fRec1575[1]);
			fRec1573[0] = fRec1575[0];
			double fRec1574 = fRec1577;
			fVec23[(IOTA & 511)] = (((501527406400.0 * fTemp96) + ((1488757731000.0 * fTemp95) + ((60492228810.0 * fTemp94) + ((650403134700.0 * fTemp7) + ((958353593000.0 * fTemp93) + ((50650169980.0 * fTemp92) + ((882528353000.0 * fTemp8) + ((205155030200.0 * fTemp9) + ((304388184300.0 * fTemp10) + ((589622446700.0 * fTemp12) + ((225387758900.0 * fTemp88) + ((1095585524000.0 * fTemp11) + (fRec1517 + (fRec1535 + (fRec1550 + (fRec1562 + (fRec1571 + fRec1574))))))))))))))))) - ((((540285231800.0 * fTemp89) + (875151214000.0 * fTemp90)) + (841167736900.0 * fTemp91)) + (108953411800.0 * fTemp97)));
			output23[i] = FAUSTFLOAT((0.87553802008608317 * (fVec23[((IOTA - iConst83) & 511)] * fRec129[0])));
			double fTemp719 = (fConst85 * fRec1579[1]);
			double fTemp720 = (fConst86 * fRec1582[1]);
			double fTemp721 = (fConst88 * fRec1585[1]);
			double fTemp722 = (fConst89 * fRec1588[1]);
			double fTemp723 = (fConst91 * (((((1187122913000.0 * fTemp78) + (((1372692148.0 * fTemp76) + (368579055800.0 * fTemp77)) + (1614835720000.0 * fTemp72))) + (1183918539000.0 * fTemp80)) + (1905527712.0 * fTemp84)) - ((34714222650.0 * fTemp83) + ((171634902400.0 * fTemp73) + ((373039605900.0 * fTemp82) + ((((1183478889.0 * fTemp74) + (31721443520.0 * fTemp75)) + (671031826000.0 * fTemp79)) + (432242658.30000001 * fTemp81)))))));
			double fTemp724 = (fConst92 * fRec1591[1]);
			double fTemp725 = (fConst93 * fRec1594[1]);
			fRec1596[0] = (fTemp723 + (fTemp724 + (fRec1596[1] + fTemp725)));
			fRec1594[0] = fRec1596[0];
			double fRec1595 = ((fTemp725 + fTemp724) + fTemp723);
			fRec1593[0] = (fRec1594[0] + fRec1593[1]);
			fRec1591[0] = fRec1593[0];
			double fRec1592 = fRec1595;
			fRec1590[0] = (fTemp721 + (fTemp722 + (fRec1592 + fRec1590[1])));
			fRec1588[0] = fRec1590[0];
			double fRec1589 = (fTemp721 + (fRec1592 + fTemp722));
			fRec1587[0] = (fRec1588[0] + fRec1587[1]);
			fRec1585[0] = fRec1587[0];
			double fRec1586 = fRec1589;
			fRec1584[0] = (fTemp719 + (fTemp720 + (fRec1586 + fRec1584[1])));
			fRec1582[0] = fRec1584[0];
			double fRec1583 = (fTemp719 + (fRec1586 + fTemp720));
			fRec1581[0] = (fRec1582[0] + fRec1581[1]);
			fRec1579[0] = fRec1581[0];
			double fRec1580 = fRec1583;
			double fTemp726 = (fConst95 * fRec1597[1]);
			double fTemp727 = (fConst96 * fRec1600[1]);
			double fTemp728 = (fConst98 * ((((((((1770556455.0 * fTemp43) + (147475826100.0 * fTemp39)) + (1225325247000.0 * fTemp44)) + (1487318330000.0 * fTemp40)) + (477352239800.0 * fTemp45)) + (1485378436000.0 * fTemp41)) + (595117601.39999998 * fTemp42)) - ((153761603500.0 * fTemp46) + (81761295080.0 * fTemp47))));
			double fTemp729 = (fConst99 * fRec1603[1]);
			double fTemp730 = (fConst100 * fRec1606[1]);
			fRec1608[0] = (fTemp728 + (fTemp729 + (fRec1608[1] + fTemp730)));
			fRec1606[0] = fRec1608[0];
			double fRec1607 = ((fTemp730 + fTemp729) + fTemp728);
			fRec1605[0] = (fRec1606[0] + fRec1605[1]);
			fRec1603[0] = fRec1605[0];
			double fRec1604 = fRec1607;
			fRec1602[0] = (fTemp726 + (fTemp727 + (fRec1604 + fRec1602[1])));
			fRec1600[0] = fRec1602[0];
			double fRec1601 = (fTemp726 + (fRec1604 + fTemp727));
			fRec1599[0] = (fRec1600[0] + fRec1599[1]);
			fRec1597[0] = fRec1599[0];
			double fRec1598 = fRec1601;
			double fTemp731 = (fConst102 * fRec1609[1]);
			double fTemp732 = (fConst104 * (((((((104664530700.0 * fTemp30) + (701342321000.0 * fTemp27)) + (1345255216000.0 * fTemp31)) + (1319295870000.0 * fTemp28)) + (1347488902000.0 * fTemp29)) + (552180940.89999998 * fTemp32)) - (106451608200.0 * fTemp33)));
			double fTemp733 = (fConst105 * fRec1612[1]);
			double fTemp734 = (fConst106 * fRec1615[1]);
			fRec1617[0] = (fTemp732 + (fTemp733 + (fRec1617[1] + fTemp734)));
			fRec1615[0] = fRec1617[0];
			double fRec1616 = ((fTemp734 + fTemp733) + fTemp732);
			fRec1614[0] = (fRec1615[0] + fRec1614[1]);
			fRec1612[0] = fRec1614[0];
			double fRec1613 = fRec1616;
			fRec1611[0] = (fTemp731 + (fRec1613 + fRec1611[1]));
			fRec1609[0] = fRec1611[0];
			double fRec1610 = (fRec1613 + fTemp731);
			double fTemp735 = (fConst108 * (((398629431000.0 * fTemp13) + (1488932585000.0 * fTemp15)) + (403377252400.0 * fTemp14)));
			double fTemp736 = (fConst109 * fRec1618[1]);
			fRec1620[0] = (fTemp735 + (fRec1620[1] + fTemp736));
			fRec1618[0] = fRec1620[0];
			double fRec1619 = (fTemp736 + fTemp735);
			double fTemp737 = (fConst111 * (((((219109658300.0 * fTemp19) + (902027852500.0 * fTemp20)) + (1728601791000.0 * fTemp21)) + (907124313000.0 * fTemp22)) + (237130249.40000001 * fTemp18)));
			double fTemp738 = (fConst112 * fRec1621[1]);
			double fTemp739 = (fConst113 * fRec1624[1]);
			fRec1626[0] = (fTemp737 + (fTemp738 + (fRec1626[1] + fTemp739)));
			fRec1624[0] = fRec1626[0];
			double fRec1625 = ((fTemp739 + fTemp738) + fTemp737);
			fRec1623[0] = (fRec1624[0] + fRec1623[1]);
			fRec1621[0] = fRec1623[0];
			double fRec1622 = fRec1625;
			double fTemp740 = (fConst115 * fRec1627[1]);
			double fTemp741 = (fConst117 * fRec1630[1]);
			double fTemp742 = (fConst118 * fRec1633[1]);
			double fTemp743 = (fConst120 * (((155566294.90000001 * fTemp62) + ((((((134007235.0 * fTemp54) + (712438842.0 * fTemp55)) + (207830105900.0 * fTemp59)) + (1523884278000.0 * fTemp56)) + (1362491110000.0 * fTemp60)) + (1358136505000.0 * fTemp57))) - ((97961569.0 * fTemp58) + ((124839277700.0 * fTemp64) + ((253235497300.0 * fTemp61) + (216476281700.0 * fTemp63))))));
			double fTemp744 = (fConst121 * fRec1636[1]);
			double fTemp745 = (fConst122 * fRec1639[1]);
			fRec1641[0] = (fTemp743 + (fTemp744 + (fRec1641[1] + fTemp745)));
			fRec1639[0] = fRec1641[0];
			double fRec1640 = ((fTemp745 + fTemp744) + fTemp743);
			fRec1638[0] = (fRec1638[1] + fRec1639[0]);
			fRec1636[0] = fRec1638[0];
			double fRec1637 = fRec1640;
			fRec1635[0] = ((fTemp741 + (fRec1635[1] + fTemp742)) + fRec1637);
			fRec1633[0] = fRec1635[0];
			double fRec1634 = ((fTemp742 + fTemp741) + fRec1637);
			fRec1632[0] = (fRec1632[1] + fRec1633[0]);
			fRec1630[0] = fRec1632[0];
			double fRec1631 = fRec1634;
			fRec1629[0] = ((fRec1629[1] + fTemp740) + fRec1631);
			fRec1627[0] = fRec1629[0];
			double fRec1628 = (fTemp740 + fRec1631);
			fVec24[(IOTA & 255)] = ((((1050382074000.0 * fTemp92) + ((1050097903000.0 * fTemp9) + ((1728669675000.0 * fTemp91) + ((614432839300.0 * fTemp10) + (((1061999120000.0 * fTemp11) + (fRec1580 + (fRec1598 + (fRec1610 + (fRec1619 + fRec1622))))) + (37069631540.0 * fTemp12)))))) + fRec1628) - ((132742816.0 * fTemp97) + ((325678806.19999999 * fTemp96) + ((80575064040.0 * fTemp95) + ((284056482700.0 * fTemp94) + ((610686603400.0 * fTemp7) + (((((495519118.0 * fTemp88) + (74701563530.0 * fTemp89)) + (1141619753.0 * fTemp90)) + (1006868969000.0 * fTemp8)) + (587166483.60000002 * fTemp93))))))));
			output24[i] = FAUSTFLOAT((0.95355093256814927 * (fVec24[((IOTA - iConst123) & 255)] * fRec129[0])));
			double fTemp746 = (fConst85 * fRec1642[1]);
			double fTemp747 = (fConst86 * fRec1645[1]);
			double fTemp748 = (fConst88 * fRec1648[1]);
			double fTemp749 = (fConst89 * fRec1651[1]);
			double fTemp750 = (fConst91 * ((((((11027451790.0 * fTemp74) + (34293314110.0 * fTemp75)) + (270558414.0 * fTemp76)) + (1183267589000.0 * fTemp80)) + (1683279446.0 * fTemp84)) - ((34762170880.0 * fTemp83) + ((166555130100.0 * fTemp73) + ((373662211700.0 * fTemp82) + (((671601020100.0 * fTemp79) + (((368022852400.0 * fTemp77) + (1613218853000.0 * fTemp72)) + (1188694883000.0 * fTemp78))) + (82927150.670000002 * fTemp81)))))));
			double fTemp751 = (fConst92 * fRec1654[1]);
			double fTemp752 = (fConst93 * fRec1657[1]);
			fRec1659[0] = (fTemp750 + (fTemp751 + (fRec1659[1] + fTemp752)));
			fRec1657[0] = fRec1659[0];
			double fRec1658 = ((fTemp752 + fTemp751) + fTemp750);
			fRec1656[0] = (fRec1657[0] + fRec1656[1]);
			fRec1654[0] = fRec1656[0];
			double fRec1655 = fRec1658;
			fRec1653[0] = (fTemp748 + (fTemp749 + (fRec1655 + fRec1653[1])));
			fRec1651[0] = fRec1653[0];
			double fRec1652 = (fTemp748 + (fRec1655 + fTemp749));
			fRec1650[0] = (fRec1651[0] + fRec1650[1]);
			fRec1648[0] = fRec1650[0];
			double fRec1649 = fRec1652;
			fRec1647[0] = (fTemp746 + (fTemp747 + (fRec1649 + fRec1647[1])));
			fRec1645[0] = fRec1647[0];
			double fRec1646 = (fTemp746 + (fRec1649 + fTemp747));
			fRec1644[0] = (fRec1645[0] + fRec1644[1]);
			fRec1642[0] = fRec1644[0];
			double fRec1643 = fRec1646;
			double fTemp753 = (fConst115 * fRec1660[1]);
			double fTemp754 = (fConst117 * fRec1663[1]);
			double fTemp755 = (fConst118 * fRec1666[1]);
			double fTemp756 = (fConst120 * (((321078336.80000001 * fTemp62) + ((1408437146.0 * fTemp54) + (1357349675000.0 * fTemp57))) - ((240173514.0 * fTemp58) + ((120658972400.0 * fTemp64) + ((((((2016410065.0 * fTemp55) + (206281635700.0 * fTemp59)) + (1524814255000.0 * fTemp56)) + (1363237246000.0 * fTemp60)) + (252561864800.0 * fTemp61)) + (218477357200.0 * fTemp63))))));
			double fTemp757 = (fConst121 * fRec1669[1]);
			double fTemp758 = (fConst122 * fRec1672[1]);
			fRec1674[0] = (fTemp756 + (fTemp757 + (fRec1674[1] + fTemp758)));
			fRec1672[0] = fRec1674[0];
			double fRec1673 = ((fTemp758 + fTemp757) + fTemp756);
			fRec1671[0] = (fRec1672[0] + fRec1671[1]);
			fRec1669[0] = fRec1671[0];
			double fRec1670 = fRec1673;
			fRec1668[0] = (fTemp754 + (fTemp755 + (fRec1670 + fRec1668[1])));
			fRec1666[0] = fRec1668[0];
			double fRec1667 = (fTemp754 + (fRec1670 + fTemp755));
			fRec1665[0] = (fRec1666[0] + fRec1665[1]);
			fRec1663[0] = fRec1665[0];
			double fRec1664 = fRec1667;
			fRec1662[0] = (fTemp753 + (fRec1664 + fRec1662[1]));
			fRec1660[0] = fRec1662[0];
			double fRec1661 = (fRec1664 + fTemp753);
			double fTemp759 = (fConst95 * fRec1675[1]);
			double fTemp760 = (fConst96 * fRec1678[1]);
			double fTemp761 = (fConst98 * (((273053149.60000002 * fTemp42) + ((478385684600.0 * fTemp45) + (1485147056000.0 * fTemp41))) - ((79860314010.0 * fTemp47) + (((((1836862213.0 * fTemp43) + (145824988200.0 * fTemp39)) + (1228114608000.0 * fTemp44)) + (1485904926000.0 * fTemp40)) + (156030792700.0 * fTemp46)))));
			double fTemp762 = (fConst99 * fRec1681[1]);
			double fTemp763 = (fConst100 * fRec1684[1]);
			fRec1686[0] = (fTemp761 + (fTemp762 + (fRec1686[1] + fTemp763)));
			fRec1684[0] = fRec1686[0];
			double fRec1685 = ((fTemp763 + fTemp762) + fTemp761);
			fRec1683[0] = (fRec1684[0] + fRec1683[1]);
			fRec1681[0] = fRec1683[0];
			double fRec1682 = fRec1685;
			fRec1680[0] = (fTemp759 + (fTemp760 + (fRec1682 + fRec1680[1])));
			fRec1678[0] = fRec1680[0];
			double fRec1679 = (fTemp759 + (fRec1682 + fTemp760));
			fRec1677[0] = (fRec1678[0] + fRec1677[1]);
			fRec1675[0] = fRec1677[0];
			double fRec1676 = fRec1679;
			double fTemp764 = (fConst102 * fRec1687[1]);
			double fTemp765 = (fConst104 * (((1319537968000.0 * fTemp28) + (1347975631000.0 * fTemp29)) - ((107890433200.0 * fTemp33) + ((((103677952600.0 * fTemp30) + (703848972200.0 * fTemp27)) + (1343591561000.0 * fTemp31)) + (237722994.69999999 * fTemp32)))));
			double fTemp766 = (fConst105 * fRec1690[1]);
			double fTemp767 = (fConst106 * fRec1693[1]);
			fRec1695[0] = (fTemp765 + (fTemp766 + (fRec1695[1] + fTemp767)));
			fRec1693[0] = fRec1695[0];
			double fRec1694 = ((fTemp767 + fTemp766) + fTemp765);
			fRec1692[0] = (fRec1693[0] + fRec1692[1]);
			fRec1690[0] = fRec1692[0];
			double fRec1691 = fRec1694;
			fRec1689[0] = (fTemp764 + (fRec1691 + fRec1689[1]));
			fRec1687[0] = fRec1689[0];
			double fRec1688 = (fRec1691 + fTemp764);
			double fTemp768 = (fConst108 * (((1488753925000.0 * fTemp15) + (403980139500.0 * fTemp14)) - (401386906100.0 * fTemp13)));
			double fTemp769 = (fConst109 * fRec1696[1]);
			fRec1698[0] = (fTemp768 + (fRec1698[1] + fTemp769));
			fRec1696[0] = fRec1698[0];
			double fRec1697 = (fTemp769 + fTemp768);
			double fTemp770 = (fConst111 * (((1728117316000.0 * fTemp21) + (907920909500.0 * fTemp22)) - (((220163293300.0 * fTemp19) + (902825688400.0 * fTemp20)) + (535849129.60000002 * fTemp18))));
			double fTemp771 = (fConst112 * fRec1699[1]);
			double fTemp772 = (fConst113 * fRec1702[1]);
			fRec1704[0] = (fTemp770 + (fTemp771 + (fRec1704[1] + fTemp772)));
			fRec1702[0] = fRec1704[0];
			double fRec1703 = ((fTemp772 + fTemp771) + fTemp770);
			fRec1701[0] = (fRec1702[0] + fRec1701[1]);
			fRec1699[0] = fRec1701[0];
			double fRec1700 = fRec1703;
			fVec25[(IOTA & 255)] = (((80093690.0 * fTemp96) + ((1050422376000.0 * fTemp92) + ((1459416692.0 * fTemp90) + (((1062568647000.0 * fTemp11) + (fRec1643 + (fRec1661 + (fRec1676 + (fRec1688 + (fRec1697 + fRec1700)))))) + (77339905970.0 * fTemp89))))) - (((80419637250.0 * fTemp95) + ((281009808900.0 * fTemp94) + ((609702663000.0 * fTemp7) + (((1008119809000.0 * fTemp8) + ((1050157421000.0 * fTemp9) + ((((245641116.0 * fTemp88) + (34396439160.0 * fTemp12)) + (615120722000.0 * fTemp10)) + (1726393166000.0 * fTemp91)))) + (325249810.80000001 * fTemp93))))) + (208652702.0 * fTemp97)));
			output25[i] = FAUSTFLOAT((0.95355093256814927 * (fVec25[((IOTA - iConst123) & 255)] * fRec129[0])));
			double fTemp773 = (fConst115 * fRec1705[1]);
			double fTemp774 = (fConst117 * fRec1708[1]);
			double fTemp775 = (fConst118 * fRec1711[1]);
			double fTemp776 = (fConst120 * ((((196115939500.0 * fTemp63) + ((1522604975000.0 * fTemp56) + (1696995049.0 * fTemp62))) + (320040062.0 * fTemp58)) - (((1361563312000.0 * fTemp57) + (((((2045200719.0 * fTemp54) + (61966196.0 * fTemp55)) + (216806017700.0 * fTemp59)) + (1361733568000.0 * fTemp60)) + (252892747200.0 * fTemp61))) + (114570827600.0 * fTemp64))));
			double fTemp777 = (fConst121 * fRec1714[1]);
			double fTemp778 = (fConst122 * fRec1717[1]);
			fRec1719[0] = (fTemp776 + (fTemp777 + (fRec1719[1] + fTemp778)));
			fRec1717[0] = fRec1719[0];
			double fRec1718 = ((fTemp778 + fTemp777) + fTemp776);
			fRec1716[0] = (fRec1717[0] + fRec1716[1]);
			fRec1714[0] = fRec1716[0];
			double fRec1715 = fRec1718;
			fRec1713[0] = (fTemp774 + (fTemp775 + (fRec1715 + fRec1713[1])));
			fRec1711[0] = fRec1713[0];
			double fRec1712 = (fTemp774 + (fRec1715 + fTemp775));
			fRec1710[0] = (fRec1711[0] + fRec1710[1]);
			fRec1708[0] = fRec1710[0];
			double fRec1709 = fRec1712;
			fRec1707[0] = (fTemp773 + (fRec1709 + fRec1707[1]));
			fRec1705[0] = fRec1707[0];
			double fRec1706 = (fRec1709 + fTemp773);
			double fTemp779 = (fConst95 * fRec1720[1]);
			double fTemp780 = (fConst96 * fRec1723[1]);
			double fTemp781 = (fConst98 * (((138574091300.0 * fTemp46) + ((((345515686.80000001 * fTemp43) + (1219711738000.0 * fTemp44)) + (478279694400.0 * fTemp45)) + (1091574211.0 * fTemp42))) - ((((153591419900.0 * fTemp39) + (1485379342000.0 * fTemp40)) + (1487268290000.0 * fTemp41)) + (77711806480.0 * fTemp47))));
			double fTemp782 = (fConst99 * fRec1726[1]);
			double fTemp783 = (fConst100 * fRec1729[1]);
			fRec1731[0] = (fTemp781 + (fTemp782 + (fRec1731[1] + fTemp783)));
			fRec1729[0] = fRec1731[0];
			double fRec1730 = ((fTemp783 + fTemp782) + fTemp781);
			fRec1728[0] = (fRec1729[0] + fRec1728[1]);
			fRec1726[0] = fRec1728[0];
			double fRec1727 = fRec1730;
			fRec1725[0] = (fTemp779 + (fTemp780 + (fRec1727 + fRec1725[1])));
			fRec1723[0] = fRec1725[0];
			double fRec1724 = (fTemp779 + (fRec1727 + fTemp780));
			fRec1722[0] = (fRec1723[0] + fRec1722[1]);
			fRec1720[0] = fRec1722[0];
			double fRec1721 = fRec1724;
			double fTemp784 = (fConst102 * fRec1732[1]);
			double fTemp785 = (fConst104 * (((101746128000.0 * fTemp33) + (((695015923700.0 * fTemp27) + (1319871370000.0 * fTemp28)) + (134719380.0 * fTemp32))) - (((105996304300.0 * fTemp30) + (1343962534000.0 * fTemp31)) + (1346462980000.0 * fTemp29))));
			double fTemp786 = (fConst105 * fRec1735[1]);
			double fTemp787 = (fConst106 * fRec1738[1]);
			fRec1740[0] = (fTemp785 + (fTemp786 + (fRec1740[1] + fTemp787)));
			fRec1738[0] = fRec1740[0];
			double fRec1739 = ((fTemp787 + fTemp786) + fTemp785);
			fRec1737[0] = (fRec1738[0] + fRec1737[1]);
			fRec1735[0] = fRec1737[0];
			double fRec1736 = fRec1739;
			fRec1734[0] = (fTemp784 + (fRec1736 + fRec1734[1]));
			fRec1732[0] = fRec1734[0];
			double fRec1733 = (fRec1736 + fTemp784);
			double fTemp788 = (fConst108 * ((1489138404000.0 * fTemp15) - ((401397208000.0 * fTemp13) + (400124226800.0 * fTemp14))));
			double fTemp789 = (fConst109 * fRec1741[1]);
			fRec1743[0] = (fTemp788 + (fRec1743[1] + fTemp789));
			fRec1741[0] = fRec1743[0];
			double fRec1742 = (fTemp789 + fTemp788);
			double fTemp790 = (fConst111 * ((((215288201600.0 * fTemp19) + (1728690646000.0 * fTemp21)) + (1400392048.0 * fTemp18)) - ((903238501000.0 * fTemp20) + (903877267400.0 * fTemp22))));
			double fTemp791 = (fConst112 * fRec1744[1]);
			double fTemp792 = (fConst113 * fRec1747[1]);
			fRec1749[0] = (fTemp790 + (fTemp791 + (fRec1749[1] + fTemp792)));
			fRec1747[0] = fRec1749[0];
			double fRec1748 = ((fTemp792 + fTemp791) + fTemp790);
			fRec1746[0] = (fRec1747[0] + fRec1746[1]);
			fRec1744[0] = fRec1746[0];
			double fRec1745 = fRec1748;
			double fTemp793 = (fConst85 * fRec1750[1]);
			double fTemp794 = (fConst86 * fRec1753[1]);
			double fTemp795 = (fConst88 * fRec1756[1]);
			double fTemp796 = (fConst89 * fRec1759[1]);
			double fTemp797 = (fConst91 * (((1813164924.0 * fTemp84) + (((362683169200.0 * fTemp82) + (((45253517910.0 * fTemp75) + (1618245199000.0 * fTemp72)) + (516167431.0 * fTemp81))) + (43810893610.0 * fTemp83))) - (((1186460398000.0 * fTemp80) + ((671892472800.0 * fTemp79) + ((((252881073.0 * fTemp74) + (892938626.0 * fTemp76)) + (373386774900.0 * fTemp77)) + (1187250305000.0 * fTemp78)))) + (158162167700.0 * fTemp73))));
			double fTemp798 = (fConst92 * fRec1762[1]);
			double fTemp799 = (fConst93 * fRec1765[1]);
			fRec1767[0] = (fTemp797 + (fTemp798 + (fRec1767[1] + fTemp799)));
			fRec1765[0] = fRec1767[0];
			double fRec1766 = ((fTemp799 + fTemp798) + fTemp797);
			fRec1764[0] = (fRec1764[1] + fRec1765[0]);
			fRec1762[0] = fRec1764[0];
			double fRec1763 = fRec1766;
			fRec1761[0] = ((fTemp795 + (fRec1761[1] + fTemp796)) + fRec1763);
			fRec1759[0] = fRec1761[0];
			double fRec1760 = ((fTemp796 + fTemp795) + fRec1763);
			fRec1758[0] = (fRec1758[1] + fRec1759[0]);
			fRec1756[0] = fRec1758[0];
			double fRec1757 = fRec1760;
			fRec1755[0] = ((fTemp793 + (fRec1755[1] + fTemp794)) + fRec1757);
			fRec1753[0] = fRec1755[0];
			double fRec1754 = ((fTemp794 + fTemp793) + fRec1757);
			fRec1752[0] = (fRec1752[1] + fRec1753[0]);
			fRec1750[0] = fRec1752[0];
			double fRec1751 = fRec1754;
			fVec26[(IOTA & 255)] = ((((99318750890.0 * fTemp95) + ((619437515800.0 * fTemp7) + ((1732924241000.0 * fTemp91) + ((1493606416.0 * fTemp90) + ((98876130950.0 * fTemp89) + ((30844281540.0 * fTemp12) + (((1062633626000.0 * fTemp11) + (fRec1706 + (fRec1721 + (fRec1733 + (fRec1742 + fRec1745))))) + (399138954.0 * fTemp88)))))))) + fRec1751) - ((1843077172.0 * fTemp97) + ((1684632061.0 * fTemp96) + (((1084225105.0 * fTemp93) + ((1050533141000.0 * fTemp92) + ((1008419747000.0 * fTemp8) + ((610523451100.0 * fTemp10) + (1049814494000.0 * fTemp9))))) + (275540623700.0 * fTemp94)))));
			output26[i] = FAUSTFLOAT((0.95355093256814927 * (fVec26[((IOTA - iConst123) & 255)] * fRec129[0])));
			double fTemp800 = (fConst85 * fRec1768[1]);
			double fTemp801 = (fConst86 * fRec1771[1]);
			double fTemp802 = (fConst88 * fRec1774[1]);
			double fTemp803 = (fConst89 * fRec1777[1]);
			double fTemp804 = (fConst91 * (((102006342.0 * fTemp84) + (((365129061400.0 * fTemp82) + ((((1032517490.0 * fTemp76) + (373693553400.0 * fTemp77)) + (1184824173000.0 * fTemp78)) + (1046447010.0 * fTemp81))) + (40626243710.0 * fTemp83))) - (((1185380907000.0 * fTemp80) + ((((1106343414.0 * fTemp74) + (45890830690.0 * fTemp75)) + (1616270957000.0 * fTemp72)) + (671855732800.0 * fTemp79))) + (155634940300.0 * fTemp73))));
			double fTemp805 = (fConst92 * fRec1780[1]);
			double fTemp806 = (fConst93 * fRec1783[1]);
			fRec1785[0] = (fTemp804 + (fTemp805 + (fRec1785[1] + fTemp806)));
			fRec1783[0] = fRec1785[0];
			double fRec1784 = ((fTemp806 + fTemp805) + fTemp804);
			fRec1782[0] = (fRec1783[0] + fRec1782[1]);
			fRec1780[0] = fRec1782[0];
			double fRec1781 = fRec1784;
			fRec1779[0] = (fTemp802 + (fTemp803 + (fRec1781 + fRec1779[1])));
			fRec1777[0] = fRec1779[0];
			double fRec1778 = (fTemp802 + (fRec1781 + fTemp803));
			fRec1776[0] = (fRec1777[0] + fRec1776[1]);
			fRec1774[0] = fRec1776[0];
			double fRec1775 = fRec1778;
			fRec1773[0] = (fTemp800 + (fTemp801 + (fRec1775 + fRec1773[1])));
			fRec1771[0] = fRec1773[0];
			double fRec1772 = (fTemp800 + (fRec1775 + fTemp801));
			fRec1770[0] = (fRec1771[0] + fRec1770[1]);
			fRec1768[0] = fRec1770[0];
			double fRec1769 = fRec1772;
			double fTemp807 = (fConst115 * fRec1786[1]);
			double fTemp808 = (fConst117 * fRec1789[1]);
			double fTemp809 = (fConst118 * fRec1792[1]);
			double fTemp810 = (fConst120 * ((((198728824100.0 * fTemp63) + (((((81449526.0 * fTemp54) + (1160465500.0 * fTemp55)) + (218874425800.0 * fTemp59)) + (1359893290000.0 * fTemp60)) + (582781597.0 * fTemp62))) + (902340014.0 * fTemp58)) - (((1360718183000.0 * fTemp57) + ((1523804315000.0 * fTemp56) + (253705974700.0 * fTemp61))) + (112303330200.0 * fTemp64))));
			double fTemp811 = (fConst122 * fRec1798[1]);
			double fTemp812 = (fConst121 * fRec1795[1]);
			fRec1800[0] = (fTemp810 + (fTemp811 + (fTemp812 + fRec1800[1])));
			fRec1798[0] = fRec1800[0];
			double fRec1799 = ((fTemp812 + fTemp811) + fTemp810);
			fRec1797[0] = (fRec1798[0] + fRec1797[1]);
			fRec1795[0] = fRec1797[0];
			double fRec1796 = fRec1799;
			fRec1794[0] = (fTemp808 + (fTemp809 + (fRec1796 + fRec1794[1])));
			fRec1792[0] = fRec1794[0];
			double fRec1793 = (fTemp808 + (fRec1796 + fTemp809));
			fRec1791[0] = (fRec1792[0] + fRec1791[1]);
			fRec1789[0] = fRec1791[0];
			double fRec1790 = fRec1793;
			fRec1788[0] = (fTemp807 + (fRec1790 + fRec1788[1]));
			fRec1786[0] = fRec1788[0];
			double fRec1787 = (fRec1790 + fTemp807);
			double fTemp813 = (fConst95 * fRec1801[1]);
			double fTemp814 = (fConst96 * fRec1804[1]);
			double fTemp815 = (fConst98 * (((((156618189800.0 * fTemp39) + (1486414316000.0 * fTemp40)) + (477756654300.0 * fTemp45)) + (138365349200.0 * fTemp46)) - (((142250244.0 * fTemp42) + (((1770241117.0 * fTemp43) + (1223168076000.0 * fTemp44)) + (1487694945000.0 * fTemp41))) + (76542932280.0 * fTemp47))));
			double fTemp816 = (fConst99 * fRec1807[1]);
			double fTemp817 = (fConst100 * fRec1810[1]);
			fRec1812[0] = (fTemp815 + (fTemp816 + (fRec1812[1] + fTemp817)));
			fRec1810[0] = fRec1812[0];
			double fRec1811 = ((fTemp817 + fTemp816) + fTemp815);
			fRec1809[0] = (fRec1810[0] + fRec1809[1]);
			fRec1807[0] = fRec1809[0];
			double fRec1808 = fRec1811;
			fRec1806[0] = (fTemp813 + (fTemp814 + (fRec1808 + fRec1806[1])));
			fRec1804[0] = fRec1806[0];
			double fRec1805 = (fTemp813 + (fRec1808 + fTemp814));
			fRec1803[0] = (fRec1804[0] + fRec1803[1]);
			fRec1801[0] = fRec1803[0];
			double fRec1802 = fRec1805;
			double fTemp818 = (fConst111 * (((903687609400.0 * fTemp20) + (1729981286000.0 * fTemp21)) - (((216483420500.0 * fTemp19) + (904159553500.0 * fTemp22)) + (1342318536.0 * fTemp18))));
			double fTemp819 = (fConst112 * fRec1813[1]);
			double fTemp820 = (fConst113 * fRec1816[1]);
			fRec1818[0] = (fTemp818 + (fTemp819 + (fRec1818[1] + fTemp820)));
			fRec1816[0] = fRec1818[0];
			double fRec1817 = ((fTemp820 + fTemp819) + fTemp818);
			fRec1815[0] = (fRec1816[0] + fRec1815[1]);
			fRec1813[0] = fRec1815[0];
			double fRec1814 = fRec1817;
			double fTemp821 = (fConst102 * fRec1819[1]);
			double fTemp822 = (fConst104 * (((99641604310.0 * fTemp33) + ((((108342634900.0 * fTemp30) + (1346297011000.0 * fTemp31)) + (1320636546000.0 * fTemp28)) + (546887209.0 * fTemp32))) - ((698036996200.0 * fTemp27) + (1347511712000.0 * fTemp29))));
			double fTemp823 = (fConst105 * fRec1822[1]);
			double fTemp824 = (fConst106 * fRec1825[1]);
			fRec1827[0] = (fTemp822 + (fTemp823 + (fRec1827[1] + fTemp824)));
			fRec1825[0] = fRec1827[0];
			double fRec1826 = ((fTemp824 + fTemp823) + fTemp822);
			fRec1824[0] = (fRec1825[0] + fRec1824[1]);
			fRec1822[0] = fRec1824[0];
			double fRec1823 = fRec1826;
			fRec1821[0] = (fTemp821 + (fRec1823 + fRec1821[1]));
			fRec1819[0] = fRec1821[0];
			double fRec1820 = (fRec1823 + fTemp821);
			double fTemp825 = (fConst108 * (((399687786100.0 * fTemp13) + (1489223342000.0 * fTemp15)) - (399471220600.0 * fTemp14)));
			double fTemp826 = (fConst109 * fRec1828[1]);
			fRec1830[0] = (fTemp825 + (fRec1830[1] + fTemp826));
			fRec1828[0] = fRec1830[0];
			double fRec1829 = (fTemp826 + fTemp825);
			fVec27[(IOTA & 255)] = ((((91574063290.0 * fTemp95) + ((618708865300.0 * fTemp7) + ((310172765.0 * fTemp93) + ((1049844903000.0 * fTemp9) + (((1061118828000.0 * fTemp11) + (fRec1769 + (fRec1787 + (fRec1802 + (fRec1814 + fRec1820))))) + (609424787300.0 * fTemp10)))))) + fRec1829) - ((1865452176.0 * fTemp97) + ((10832700850.0 * fTemp96) + (((1050560656000.0 * fTemp92) + ((((((379784318.69999999 * fTemp88) + (30160937540.0 * fTemp12)) + (104404089400.0 * fTemp89)) + (1736992121.0 * fTemp90)) + (1730105260000.0 * fTemp91)) + (1007842163000.0 * fTemp8))) + (274145326200.0 * fTemp94)))));
			output27[i] = FAUSTFLOAT((0.95355093256814927 * (fVec27[((IOTA - iConst123) & 255)] * fRec129[0])));
			double fTemp827 = (fConst125 * fRec1831[1]);
			double fTemp828 = (fConst126 * fRec1834[1]);
			double fTemp829 = (fConst128 * fRec1837[1]);
			double fTemp830 = (fConst129 * fRec1840[1]);
			double fTemp831 = (fConst131 * (((1345972977.0 * fTemp83) + (((3087286635000.0 * fTemp79) + ((624151157.0 * fTemp76) + (384212044.0 * fTemp78))) + (162136317900.0 * fTemp73))) - (((1466525610.0 * fTemp82) + ((1823279423.0 * fTemp81) + (((((295096915.69999999 * fTemp74) + (384423429.39999998 * fTemp75)) + (235520729.80000001 * fTemp77)) + (538282102.79999995 * fTemp72)) + (757459871.29999995 * fTemp80)))) + (951348649.0 * fTemp84))));
			double fTemp832 = (fConst132 * fRec1843[1]);
			double fTemp833 = (fConst133 * fRec1846[1]);
			fRec1848[0] = (fTemp831 + (fTemp832 + (fRec1848[1] + fTemp833)));
			fRec1846[0] = fRec1848[0];
			double fRec1847 = ((fTemp833 + fTemp832) + fTemp831);
			fRec1845[0] = (fRec1846[0] + fRec1845[1]);
			fRec1843[0] = fRec1845[0];
			double fRec1844 = fRec1847;
			fRec1842[0] = (fTemp829 + (fTemp830 + (fRec1844 + fRec1842[1])));
			fRec1840[0] = fRec1842[0];
			double fRec1841 = (fTemp829 + (fRec1844 + fTemp830));
			fRec1839[0] = (fRec1840[0] + fRec1839[1]);
			fRec1837[0] = fRec1839[0];
			double fRec1838 = fRec1841;
			fRec1836[0] = (fTemp827 + (fTemp828 + (fRec1838 + fRec1836[1])));
			fRec1834[0] = fRec1836[0];
			double fRec1835 = (fTemp827 + (fRec1838 + fTemp828));
			fRec1833[0] = (fRec1834[0] + fRec1833[1]);
			fRec1831[0] = fRec1833[0];
			double fRec1832 = fRec1835;
			double fTemp834 = (fConst135 * fRec1849[1]);
			double fTemp835 = (fConst137 * fRec1852[1]);
			double fTemp836 = (fConst138 * fRec1855[1]);
			double fTemp837 = (fConst140 * (((136110082200.0 * fTemp64) + (((2947263084000.0 * fTemp61) + (((1649546811.0 * fTemp55) + (376656839.80000001 * fTemp56)) + (385502486.0 * fTemp60))) + (14664660540.0 * fTemp63))) - (((1314209678.0 * fTemp62) + (((287993884.30000001 * fTemp54) + (604408555.5 * fTemp59)) + (1004071618.0 * fTemp57))) + (415352369.0 * fTemp58))));
			double fTemp838 = (fConst141 * fRec1858[1]);
			double fTemp839 = (fConst142 * fRec1861[1]);
			fRec1863[0] = (fTemp837 + (fTemp838 + (fRec1863[1] + fTemp839)));
			fRec1861[0] = fRec1863[0];
			double fRec1862 = ((fTemp839 + fTemp838) + fTemp837);
			fRec1860[0] = (fRec1861[0] + fRec1860[1]);
			fRec1858[0] = fRec1860[0];
			double fRec1859 = fRec1862;
			fRec1857[0] = (fTemp835 + (fTemp836 + (fRec1859 + fRec1857[1])));
			fRec1855[0] = fRec1857[0];
			double fRec1856 = (fTemp835 + (fRec1859 + fTemp836));
			fRec1854[0] = (fRec1855[0] + fRec1854[1]);
			fRec1852[0] = fRec1854[0];
			double fRec1853 = fRec1856;
			fRec1851[0] = (fTemp834 + (fRec1853 + fRec1851[1]));
			fRec1849[0] = fRec1851[0];
			double fRec1850 = (fRec1853 + fTemp834);
			double fTemp840 = (fConst144 * fRec1864[1]);
			double fTemp841 = (fConst145 * fRec1867[1]);
			double fTemp842 = (fConst147 * (((102199101500.0 * fTemp47) + (((210954619.0 * fTemp41) + ((1075560884.0 * fTemp44) + (2475435918000.0 * fTemp45))) + (11591632400.0 * fTemp46))) - ((((923959766.60000002 * fTemp43) + (600861333.79999995 * fTemp39)) + (25527737.010000002 * fTemp40)) + (114864171.0 * fTemp42))));
			double fTemp843 = (fConst148 * fRec1870[1]);
			double fTemp844 = (fConst149 * fRec1873[1]);
			fRec1875[0] = (fTemp842 + (fTemp843 + (fRec1875[1] + fTemp844)));
			fRec1873[0] = fRec1875[0];
			double fRec1874 = ((fTemp844 + fTemp843) + fTemp842);
			fRec1872[0] = (fRec1873[0] + fRec1872[1]);
			fRec1870[0] = fRec1872[0];
			double fRec1871 = fRec1874;
			fRec1869[0] = (fTemp840 + (fTemp841 + (fRec1871 + fRec1869[1])));
			fRec1867[0] = fRec1869[0];
			double fRec1868 = (fTemp840 + (fRec1871 + fTemp841));
			fRec1866[0] = (fRec1867[0] + fRec1866[1]);
			fRec1864[0] = fRec1866[0];
			double fRec1865 = fRec1868;
			double fTemp845 = (fConst151 * fRec1876[1]);
			double fTemp846 = (fConst153 * ((((1007174762.0 * fTemp27) + (1621015177000.0 * fTemp28)) + (1730870544.0 * fTemp29)) - ((86022893.0 * fTemp33) + (((329436474.5 * fTemp30) + (372515552.69999999 * fTemp31)) + (1377299488.0 * fTemp32)))));
			double fTemp847 = (fConst154 * fRec1879[1]);
			double fTemp848 = (fConst155 * fRec1882[1]);
			fRec1884[0] = (fTemp846 + (fTemp847 + (fRec1884[1] + fTemp848)));
			fRec1882[0] = fRec1884[0];
			double fRec1883 = ((fTemp848 + fTemp847) + fTemp846);
			fRec1881[0] = (fRec1882[0] + fRec1881[1]);
			fRec1879[0] = fRec1881[0];
			double fRec1880 = fRec1883;
			fRec1878[0] = (fTemp845 + (fRec1880 + fRec1878[1]));
			fRec1876[0] = fRec1878[0];
			double fRec1877 = (fRec1880 + fTemp845);
			double fTemp849 = (fConst157 * (((576961921600.0 * fTemp15) + (1679721381.0 * fTemp14)) - (95980319.129999995 * fTemp13)));
			double fTemp850 = (fConst158 * fRec1885[1]);
			fRec1887[0] = (fTemp849 + (fRec1887[1] + fTemp850));
			fRec1885[0] = fRec1887[0];
			double fRec1886 = (fTemp850 + fTemp849);
			double fTemp851 = (fConst160 * (((471537687.19999999 * fTemp19) + (857090937000.0 * fTemp21)) - (((334095218.19999999 * fTemp20) + (1999638114.0 * fTemp22)) + (1655219064.0 * fTemp18))));
			double fTemp852 = (fConst161 * fRec1888[1]);
			double fTemp853 = (fConst162 * fRec1891[1]);
			fRec1893[0] = (fTemp851 + (fTemp852 + (fRec1893[1] + fTemp853)));
			fRec1891[0] = fRec1893[0];
			double fRec1892 = ((fTemp853 + fTemp852) + fTemp851);
			fRec1890[0] = (fRec1891[0] + fRec1890[1]);
			fRec1888[0] = fRec1890[0];
			double fRec1889 = fRec1892;
			output28[i] = FAUSTFLOAT(((((856406494.0 * fTemp97) + ((272152924500.0 * fTemp94) + ((650329981.5 * fTemp92) + ((3357829494000.0 * fTemp8) + ((271659752.19999999 * fTemp10) + (((627880682400.0 * fTemp11) + (fRec1832 + (fRec1850 + (fRec1865 + (fRec1877 + (fRec1886 + fRec1889)))))) + (1869320593.0 * fTemp90))))))) - ((1312362800.0 * fTemp96) + (((2121898767.0 * fTemp7) + (((38571704.18 * fTemp9) + ((((599122979.0 * fTemp88) + (1805430047.0 * fTemp12)) + (291250827.39999998 * fTemp89)) + (755417608.79999995 * fTemp91))) + (216420062.0 * fTemp93))) + (14497299730.0 * fTemp95)))) * fRec129[0]));
			fRec0[1] = fRec0[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec10[1] = fRec10[0];
			fRec8[1] = fRec8[0];
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
			fRec19[1] = fRec19[0];
			fRec17[1] = fRec17[0];
			fRec16[1] = fRec16[0];
			fRec14[1] = fRec14[0];
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
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fRec33[1] = fRec33[0];
			fRec31[1] = fRec31[0];
			fRec30[1] = fRec30[0];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			fRec25[1] = fRec25[0];
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
			fRec60[2] = fRec60[1];
			fRec60[1] = fRec60[0];
			fRec61[2] = fRec61[1];
			fRec61[1] = fRec61[0];
			fRec52[1] = fRec52[0];
			fRec50[1] = fRec50[0];
			fRec49[1] = fRec49[0];
			fRec47[1] = fRec47[0];
			fRec46[1] = fRec46[0];
			fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec41[1] = fRec41[0];
			fRec77[2] = fRec77[1];
			fRec77[1] = fRec77[0];
			fRec78[2] = fRec78[1];
			fRec78[1] = fRec78[0];
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
			fRec84[2] = fRec84[1];
			fRec84[1] = fRec84[0];
			fRec85[2] = fRec85[1];
			fRec85[1] = fRec85[0];
			fRec86[2] = fRec86[1];
			fRec86[1] = fRec86[0];
			fRec87[2] = fRec87[1];
			fRec87[1] = fRec87[0];
			fRec76[1] = fRec76[0];
			fRec74[1] = fRec74[0];
			fRec73[1] = fRec73[0];
			fRec71[1] = fRec71[0];
			fRec70[1] = fRec70[0];
			fRec68[1] = fRec68[0];
			fRec67[1] = fRec67[0];
			fRec65[1] = fRec65[0];
			fRec64[1] = fRec64[0];
			fRec62[1] = fRec62[0];
			fRec106[2] = fRec106[1];
			fRec106[1] = fRec106[0];
			fRec107[2] = fRec107[1];
			fRec107[1] = fRec107[0];
			fRec108[2] = fRec108[1];
			fRec108[1] = fRec108[0];
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
			fRec114[2] = fRec114[1];
			fRec114[1] = fRec114[0];
			fRec115[2] = fRec115[1];
			fRec115[1] = fRec115[0];
			fRec116[2] = fRec116[1];
			fRec116[1] = fRec116[0];
			fRec117[2] = fRec117[1];
			fRec117[1] = fRec117[0];
			fRec118[2] = fRec118[1];
			fRec118[1] = fRec118[0];
			fRec105[1] = fRec105[0];
			fRec103[1] = fRec103[0];
			fRec102[1] = fRec102[0];
			fRec100[1] = fRec100[0];
			fRec99[1] = fRec99[0];
			fRec97[1] = fRec97[0];
			fRec96[1] = fRec96[0];
			fRec94[1] = fRec94[0];
			fRec93[1] = fRec93[0];
			fRec91[1] = fRec91[0];
			fRec90[1] = fRec90[0];
			fRec88[1] = fRec88[0];
			fRec119[2] = fRec119[1];
			fRec119[1] = fRec119[0];
			fRec120[2] = fRec120[1];
			fRec120[1] = fRec120[0];
			fRec121[2] = fRec121[1];
			fRec121[1] = fRec121[0];
			fRec122[2] = fRec122[1];
			fRec122[1] = fRec122[0];
			fRec123[2] = fRec123[1];
			fRec123[1] = fRec123[0];
			fRec124[2] = fRec124[1];
			fRec124[1] = fRec124[0];
			fRec125[2] = fRec125[1];
			fRec125[1] = fRec125[0];
			fRec126[2] = fRec126[1];
			fRec126[1] = fRec126[0];
			fRec127[2] = fRec127[1];
			fRec127[1] = fRec127[0];
			fRec128[2] = fRec128[1];
			fRec128[1] = fRec128[0];
			IOTA = (IOTA + 1);
			fRec129[1] = fRec129[0];
			fRec132[1] = fRec132[0];
			fRec130[1] = fRec130[0];
			fRec138[1] = fRec138[0];
			fRec136[1] = fRec136[0];
			fRec135[1] = fRec135[0];
			fRec133[1] = fRec133[0];
			fRec147[1] = fRec147[0];
			fRec145[1] = fRec145[0];
			fRec144[1] = fRec144[0];
			fRec142[1] = fRec142[0];
			fRec141[1] = fRec141[0];
			fRec139[1] = fRec139[0];
			fRec159[1] = fRec159[0];
			fRec157[1] = fRec157[0];
			fRec156[1] = fRec156[0];
			fRec154[1] = fRec154[0];
			fRec153[1] = fRec153[0];
			fRec151[1] = fRec151[0];
			fRec150[1] = fRec150[0];
			fRec148[1] = fRec148[0];
			fRec174[1] = fRec174[0];
			fRec172[1] = fRec172[0];
			fRec171[1] = fRec171[0];
			fRec169[1] = fRec169[0];
			fRec168[1] = fRec168[0];
			fRec166[1] = fRec166[0];
			fRec165[1] = fRec165[0];
			fRec163[1] = fRec163[0];
			fRec162[1] = fRec162[0];
			fRec160[1] = fRec160[0];
			fRec192[1] = fRec192[0];
			fRec190[1] = fRec190[0];
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
			fRec195[1] = fRec195[0];
			fRec193[1] = fRec193[0];
			fRec201[1] = fRec201[0];
			fRec199[1] = fRec199[0];
			fRec198[1] = fRec198[0];
			fRec196[1] = fRec196[0];
			fRec210[1] = fRec210[0];
			fRec208[1] = fRec208[0];
			fRec207[1] = fRec207[0];
			fRec205[1] = fRec205[0];
			fRec204[1] = fRec204[0];
			fRec202[1] = fRec202[0];
			fRec222[1] = fRec222[0];
			fRec220[1] = fRec220[0];
			fRec219[1] = fRec219[0];
			fRec217[1] = fRec217[0];
			fRec216[1] = fRec216[0];
			fRec214[1] = fRec214[0];
			fRec213[1] = fRec213[0];
			fRec211[1] = fRec211[0];
			fRec237[1] = fRec237[0];
			fRec235[1] = fRec235[0];
			fRec234[1] = fRec234[0];
			fRec232[1] = fRec232[0];
			fRec231[1] = fRec231[0];
			fRec229[1] = fRec229[0];
			fRec228[1] = fRec228[0];
			fRec226[1] = fRec226[0];
			fRec225[1] = fRec225[0];
			fRec223[1] = fRec223[0];
			fRec255[1] = fRec255[0];
			fRec253[1] = fRec253[0];
			fRec252[1] = fRec252[0];
			fRec250[1] = fRec250[0];
			fRec249[1] = fRec249[0];
			fRec247[1] = fRec247[0];
			fRec246[1] = fRec246[0];
			fRec244[1] = fRec244[0];
			fRec243[1] = fRec243[0];
			fRec241[1] = fRec241[0];
			fRec240[1] = fRec240[0];
			fRec238[1] = fRec238[0];
			fRec261[1] = fRec261[0];
			fRec259[1] = fRec259[0];
			fRec258[1] = fRec258[0];
			fRec256[1] = fRec256[0];
			fRec264[1] = fRec264[0];
			fRec262[1] = fRec262[0];
			fRec273[1] = fRec273[0];
			fRec271[1] = fRec271[0];
			fRec270[1] = fRec270[0];
			fRec268[1] = fRec268[0];
			fRec267[1] = fRec267[0];
			fRec265[1] = fRec265[0];
			fRec285[1] = fRec285[0];
			fRec283[1] = fRec283[0];
			fRec282[1] = fRec282[0];
			fRec280[1] = fRec280[0];
			fRec279[1] = fRec279[0];
			fRec277[1] = fRec277[0];
			fRec276[1] = fRec276[0];
			fRec274[1] = fRec274[0];
			fRec300[1] = fRec300[0];
			fRec298[1] = fRec298[0];
			fRec297[1] = fRec297[0];
			fRec295[1] = fRec295[0];
			fRec294[1] = fRec294[0];
			fRec292[1] = fRec292[0];
			fRec291[1] = fRec291[0];
			fRec289[1] = fRec289[0];
			fRec288[1] = fRec288[0];
			fRec286[1] = fRec286[0];
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
			fRec303[1] = fRec303[0];
			fRec301[1] = fRec301[0];
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
			fRec321[1] = fRec321[0];
			fRec319[1] = fRec319[0];
			fRec339[1] = fRec339[0];
			fRec337[1] = fRec337[0];
			fRec345[1] = fRec345[0];
			fRec343[1] = fRec343[0];
			fRec342[1] = fRec342[0];
			fRec340[1] = fRec340[0];
			fRec354[1] = fRec354[0];
			fRec352[1] = fRec352[0];
			fRec351[1] = fRec351[0];
			fRec349[1] = fRec349[0];
			fRec348[1] = fRec348[0];
			fRec346[1] = fRec346[0];
			fRec366[1] = fRec366[0];
			fRec364[1] = fRec364[0];
			fRec363[1] = fRec363[0];
			fRec361[1] = fRec361[0];
			fRec360[1] = fRec360[0];
			fRec358[1] = fRec358[0];
			fRec357[1] = fRec357[0];
			fRec355[1] = fRec355[0];
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
			fRec384[1] = fRec384[0];
			fRec382[1] = fRec382[0];
			fRec390[1] = fRec390[0];
			fRec388[1] = fRec388[0];
			fRec387[1] = fRec387[0];
			fRec385[1] = fRec385[0];
			fRec399[1] = fRec399[0];
			fRec397[1] = fRec397[0];
			fRec396[1] = fRec396[0];
			fRec394[1] = fRec394[0];
			fRec393[1] = fRec393[0];
			fRec391[1] = fRec391[0];
			fRec411[1] = fRec411[0];
			fRec409[1] = fRec409[0];
			fRec408[1] = fRec408[0];
			fRec406[1] = fRec406[0];
			fRec405[1] = fRec405[0];
			fRec403[1] = fRec403[0];
			fRec402[1] = fRec402[0];
			fRec400[1] = fRec400[0];
			fRec426[1] = fRec426[0];
			fRec424[1] = fRec424[0];
			fRec423[1] = fRec423[0];
			fRec421[1] = fRec421[0];
			fRec420[1] = fRec420[0];
			fRec418[1] = fRec418[0];
			fRec417[1] = fRec417[0];
			fRec415[1] = fRec415[0];
			fRec414[1] = fRec414[0];
			fRec412[1] = fRec412[0];
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
			fRec429[1] = fRec429[0];
			fRec427[1] = fRec427[0];
			fRec447[1] = fRec447[0];
			fRec445[1] = fRec445[0];
			fRec453[1] = fRec453[0];
			fRec451[1] = fRec451[0];
			fRec450[1] = fRec450[0];
			fRec448[1] = fRec448[0];
			fRec462[1] = fRec462[0];
			fRec460[1] = fRec460[0];
			fRec459[1] = fRec459[0];
			fRec457[1] = fRec457[0];
			fRec456[1] = fRec456[0];
			fRec454[1] = fRec454[0];
			fRec474[1] = fRec474[0];
			fRec472[1] = fRec472[0];
			fRec471[1] = fRec471[0];
			fRec469[1] = fRec469[0];
			fRec468[1] = fRec468[0];
			fRec466[1] = fRec466[0];
			fRec465[1] = fRec465[0];
			fRec463[1] = fRec463[0];
			fRec489[1] = fRec489[0];
			fRec487[1] = fRec487[0];
			fRec486[1] = fRec486[0];
			fRec484[1] = fRec484[0];
			fRec483[1] = fRec483[0];
			fRec481[1] = fRec481[0];
			fRec480[1] = fRec480[0];
			fRec478[1] = fRec478[0];
			fRec477[1] = fRec477[0];
			fRec475[1] = fRec475[0];
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
			fRec492[1] = fRec492[0];
			fRec490[1] = fRec490[0];
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
			fRec510[1] = fRec510[0];
			fRec508[1] = fRec508[0];
			fRec540[1] = fRec540[0];
			fRec538[1] = fRec538[0];
			fRec537[1] = fRec537[0];
			fRec535[1] = fRec535[0];
			fRec534[1] = fRec534[0];
			fRec532[1] = fRec532[0];
			fRec531[1] = fRec531[0];
			fRec529[1] = fRec529[0];
			fRec528[1] = fRec528[0];
			fRec526[1] = fRec526[0];
			fRec543[1] = fRec543[0];
			fRec541[1] = fRec541[0];
			fRec549[1] = fRec549[0];
			fRec547[1] = fRec547[0];
			fRec546[1] = fRec546[0];
			fRec544[1] = fRec544[0];
			fRec558[1] = fRec558[0];
			fRec556[1] = fRec556[0];
			fRec555[1] = fRec555[0];
			fRec553[1] = fRec553[0];
			fRec552[1] = fRec552[0];
			fRec550[1] = fRec550[0];
			fRec570[1] = fRec570[0];
			fRec568[1] = fRec568[0];
			fRec567[1] = fRec567[0];
			fRec565[1] = fRec565[0];
			fRec564[1] = fRec564[0];
			fRec562[1] = fRec562[0];
			fRec561[1] = fRec561[0];
			fRec559[1] = fRec559[0];
			fRec585[1] = fRec585[0];
			fRec583[1] = fRec583[0];
			fRec582[1] = fRec582[0];
			fRec580[1] = fRec580[0];
			fRec579[1] = fRec579[0];
			fRec577[1] = fRec577[0];
			fRec576[1] = fRec576[0];
			fRec574[1] = fRec574[0];
			fRec573[1] = fRec573[0];
			fRec571[1] = fRec571[0];
			fRec597[1] = fRec597[0];
			fRec595[1] = fRec595[0];
			fRec594[1] = fRec594[0];
			fRec592[1] = fRec592[0];
			fRec591[1] = fRec591[0];
			fRec589[1] = fRec589[0];
			fRec588[1] = fRec588[0];
			fRec586[1] = fRec586[0];
			fRec606[1] = fRec606[0];
			fRec604[1] = fRec604[0];
			fRec603[1] = fRec603[0];
			fRec601[1] = fRec601[0];
			fRec600[1] = fRec600[0];
			fRec598[1] = fRec598[0];
			fRec609[1] = fRec609[0];
			fRec607[1] = fRec607[0];
			fRec615[1] = fRec615[0];
			fRec613[1] = fRec613[0];
			fRec612[1] = fRec612[0];
			fRec610[1] = fRec610[0];
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
			fRec618[1] = fRec618[0];
			fRec616[1] = fRec616[0];
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
			fRec636[1] = fRec636[0];
			fRec634[1] = fRec634[0];
			fRec666[1] = fRec666[0];
			fRec664[1] = fRec664[0];
			fRec663[1] = fRec663[0];
			fRec661[1] = fRec661[0];
			fRec660[1] = fRec660[0];
			fRec658[1] = fRec658[0];
			fRec657[1] = fRec657[0];
			fRec655[1] = fRec655[0];
			fRec654[1] = fRec654[0];
			fRec652[1] = fRec652[0];
			fRec678[1] = fRec678[0];
			fRec676[1] = fRec676[0];
			fRec675[1] = fRec675[0];
			fRec673[1] = fRec673[0];
			fRec672[1] = fRec672[0];
			fRec670[1] = fRec670[0];
			fRec669[1] = fRec669[0];
			fRec667[1] = fRec667[0];
			fRec687[1] = fRec687[0];
			fRec685[1] = fRec685[0];
			fRec684[1] = fRec684[0];
			fRec682[1] = fRec682[0];
			fRec681[1] = fRec681[0];
			fRec679[1] = fRec679[0];
			fRec693[1] = fRec693[0];
			fRec691[1] = fRec691[0];
			fRec690[1] = fRec690[0];
			fRec688[1] = fRec688[0];
			fRec696[1] = fRec696[0];
			fRec694[1] = fRec694[0];
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
			fRec699[1] = fRec699[0];
			fRec697[1] = fRec697[0];
			fRec729[1] = fRec729[0];
			fRec727[1] = fRec727[0];
			fRec726[1] = fRec726[0];
			fRec724[1] = fRec724[0];
			fRec723[1] = fRec723[0];
			fRec721[1] = fRec721[0];
			fRec720[1] = fRec720[0];
			fRec718[1] = fRec718[0];
			fRec717[1] = fRec717[0];
			fRec715[1] = fRec715[0];
			fRec741[1] = fRec741[0];
			fRec739[1] = fRec739[0];
			fRec738[1] = fRec738[0];
			fRec736[1] = fRec736[0];
			fRec735[1] = fRec735[0];
			fRec733[1] = fRec733[0];
			fRec732[1] = fRec732[0];
			fRec730[1] = fRec730[0];
			fRec750[1] = fRec750[0];
			fRec748[1] = fRec748[0];
			fRec747[1] = fRec747[0];
			fRec745[1] = fRec745[0];
			fRec744[1] = fRec744[0];
			fRec742[1] = fRec742[0];
			fRec756[1] = fRec756[0];
			fRec754[1] = fRec754[0];
			fRec753[1] = fRec753[0];
			fRec751[1] = fRec751[0];
			fRec759[1] = fRec759[0];
			fRec757[1] = fRec757[0];
			fRec777[1] = fRec777[0];
			fRec775[1] = fRec775[0];
			fRec774[1] = fRec774[0];
			fRec772[1] = fRec772[0];
			fRec771[1] = fRec771[0];
			fRec769[1] = fRec769[0];
			fRec768[1] = fRec768[0];
			fRec766[1] = fRec766[0];
			fRec765[1] = fRec765[0];
			fRec763[1] = fRec763[0];
			fRec762[1] = fRec762[0];
			fRec760[1] = fRec760[0];
			fRec780[1] = fRec780[0];
			fRec778[1] = fRec778[0];
			fRec786[1] = fRec786[0];
			fRec784[1] = fRec784[0];
			fRec783[1] = fRec783[0];
			fRec781[1] = fRec781[0];
			fRec795[1] = fRec795[0];
			fRec793[1] = fRec793[0];
			fRec792[1] = fRec792[0];
			fRec790[1] = fRec790[0];
			fRec789[1] = fRec789[0];
			fRec787[1] = fRec787[0];
			fRec807[1] = fRec807[0];
			fRec805[1] = fRec805[0];
			fRec804[1] = fRec804[0];
			fRec802[1] = fRec802[0];
			fRec801[1] = fRec801[0];
			fRec799[1] = fRec799[0];
			fRec798[1] = fRec798[0];
			fRec796[1] = fRec796[0];
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
			fRec825[1] = fRec825[0];
			fRec823[1] = fRec823[0];
			fRec855[1] = fRec855[0];
			fRec853[1] = fRec853[0];
			fRec852[1] = fRec852[0];
			fRec850[1] = fRec850[0];
			fRec849[1] = fRec849[0];
			fRec847[1] = fRec847[0];
			fRec846[1] = fRec846[0];
			fRec844[1] = fRec844[0];
			fRec843[1] = fRec843[0];
			fRec841[1] = fRec841[0];
			fRec867[1] = fRec867[0];
			fRec865[1] = fRec865[0];
			fRec864[1] = fRec864[0];
			fRec862[1] = fRec862[0];
			fRec861[1] = fRec861[0];
			fRec859[1] = fRec859[0];
			fRec858[1] = fRec858[0];
			fRec856[1] = fRec856[0];
			fRec876[1] = fRec876[0];
			fRec874[1] = fRec874[0];
			fRec873[1] = fRec873[0];
			fRec871[1] = fRec871[0];
			fRec870[1] = fRec870[0];
			fRec868[1] = fRec868[0];
			fRec879[1] = fRec879[0];
			fRec877[1] = fRec877[0];
			fRec885[1] = fRec885[0];
			fRec883[1] = fRec883[0];
			fRec882[1] = fRec882[0];
			fRec880[1] = fRec880[0];
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
			fRec888[1] = fRec888[0];
			fRec886[1] = fRec886[0];
			fRec918[1] = fRec918[0];
			fRec916[1] = fRec916[0];
			fRec915[1] = fRec915[0];
			fRec913[1] = fRec913[0];
			fRec912[1] = fRec912[0];
			fRec910[1] = fRec910[0];
			fRec909[1] = fRec909[0];
			fRec907[1] = fRec907[0];
			fRec906[1] = fRec906[0];
			fRec904[1] = fRec904[0];
			fRec930[1] = fRec930[0];
			fRec928[1] = fRec928[0];
			fRec927[1] = fRec927[0];
			fRec925[1] = fRec925[0];
			fRec924[1] = fRec924[0];
			fRec922[1] = fRec922[0];
			fRec921[1] = fRec921[0];
			fRec919[1] = fRec919[0];
			fRec939[1] = fRec939[0];
			fRec937[1] = fRec937[0];
			fRec936[1] = fRec936[0];
			fRec934[1] = fRec934[0];
			fRec933[1] = fRec933[0];
			fRec931[1] = fRec931[0];
			fRec942[1] = fRec942[0];
			fRec940[1] = fRec940[0];
			fRec948[1] = fRec948[0];
			fRec946[1] = fRec946[0];
			fRec945[1] = fRec945[0];
			fRec943[1] = fRec943[0];
			fRec966[1] = fRec966[0];
			fRec964[1] = fRec964[0];
			fRec963[1] = fRec963[0];
			fRec961[1] = fRec961[0];
			fRec960[1] = fRec960[0];
			fRec958[1] = fRec958[0];
			fRec957[1] = fRec957[0];
			fRec955[1] = fRec955[0];
			fRec954[1] = fRec954[0];
			fRec952[1] = fRec952[0];
			fRec951[1] = fRec951[0];
			fRec949[1] = fRec949[0];
			fRec981[1] = fRec981[0];
			fRec979[1] = fRec979[0];
			fRec978[1] = fRec978[0];
			fRec976[1] = fRec976[0];
			fRec975[1] = fRec975[0];
			fRec973[1] = fRec973[0];
			fRec972[1] = fRec972[0];
			fRec970[1] = fRec970[0];
			fRec969[1] = fRec969[0];
			fRec967[1] = fRec967[0];
			fRec993[1] = fRec993[0];
			fRec991[1] = fRec991[0];
			fRec990[1] = fRec990[0];
			fRec988[1] = fRec988[0];
			fRec987[1] = fRec987[0];
			fRec985[1] = fRec985[0];
			fRec984[1] = fRec984[0];
			fRec982[1] = fRec982[0];
			fRec1002[1] = fRec1002[0];
			fRec1000[1] = fRec1000[0];
			fRec999[1] = fRec999[0];
			fRec997[1] = fRec997[0];
			fRec996[1] = fRec996[0];
			fRec994[1] = fRec994[0];
			fRec1005[1] = fRec1005[0];
			fRec1003[1] = fRec1003[0];
			fRec1011[1] = fRec1011[0];
			fRec1009[1] = fRec1009[0];
			fRec1008[1] = fRec1008[0];
			fRec1006[1] = fRec1006[0];
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
			fRec1014[1] = fRec1014[0];
			fRec1012[1] = fRec1012[0];
			fRec1044[1] = fRec1044[0];
			fRec1042[1] = fRec1042[0];
			fRec1041[1] = fRec1041[0];
			fRec1039[1] = fRec1039[0];
			fRec1038[1] = fRec1038[0];
			fRec1036[1] = fRec1036[0];
			fRec1035[1] = fRec1035[0];
			fRec1033[1] = fRec1033[0];
			fRec1032[1] = fRec1032[0];
			fRec1030[1] = fRec1030[0];
			fRec1056[1] = fRec1056[0];
			fRec1054[1] = fRec1054[0];
			fRec1053[1] = fRec1053[0];
			fRec1051[1] = fRec1051[0];
			fRec1050[1] = fRec1050[0];
			fRec1048[1] = fRec1048[0];
			fRec1047[1] = fRec1047[0];
			fRec1045[1] = fRec1045[0];
			fRec1065[1] = fRec1065[0];
			fRec1063[1] = fRec1063[0];
			fRec1062[1] = fRec1062[0];
			fRec1060[1] = fRec1060[0];
			fRec1059[1] = fRec1059[0];
			fRec1057[1] = fRec1057[0];
			fRec1068[1] = fRec1068[0];
			fRec1066[1] = fRec1066[0];
			fRec1074[1] = fRec1074[0];
			fRec1072[1] = fRec1072[0];
			fRec1071[1] = fRec1071[0];
			fRec1069[1] = fRec1069[0];
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
			fRec1077[1] = fRec1077[0];
			fRec1075[1] = fRec1075[0];
			fRec1107[1] = fRec1107[0];
			fRec1105[1] = fRec1105[0];
			fRec1104[1] = fRec1104[0];
			fRec1102[1] = fRec1102[0];
			fRec1101[1] = fRec1101[0];
			fRec1099[1] = fRec1099[0];
			fRec1098[1] = fRec1098[0];
			fRec1096[1] = fRec1096[0];
			fRec1095[1] = fRec1095[0];
			fRec1093[1] = fRec1093[0];
			fRec1119[1] = fRec1119[0];
			fRec1117[1] = fRec1117[0];
			fRec1116[1] = fRec1116[0];
			fRec1114[1] = fRec1114[0];
			fRec1113[1] = fRec1113[0];
			fRec1111[1] = fRec1111[0];
			fRec1110[1] = fRec1110[0];
			fRec1108[1] = fRec1108[0];
			fRec1128[1] = fRec1128[0];
			fRec1126[1] = fRec1126[0];
			fRec1125[1] = fRec1125[0];
			fRec1123[1] = fRec1123[0];
			fRec1122[1] = fRec1122[0];
			fRec1120[1] = fRec1120[0];
			fRec1131[1] = fRec1131[0];
			fRec1129[1] = fRec1129[0];
			fRec1137[1] = fRec1137[0];
			fRec1135[1] = fRec1135[0];
			fRec1134[1] = fRec1134[0];
			fRec1132[1] = fRec1132[0];
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
			fRec1140[1] = fRec1140[0];
			fRec1138[1] = fRec1138[0];
			fRec1170[1] = fRec1170[0];
			fRec1168[1] = fRec1168[0];
			fRec1167[1] = fRec1167[0];
			fRec1165[1] = fRec1165[0];
			fRec1164[1] = fRec1164[0];
			fRec1162[1] = fRec1162[0];
			fRec1161[1] = fRec1161[0];
			fRec1159[1] = fRec1159[0];
			fRec1158[1] = fRec1158[0];
			fRec1156[1] = fRec1156[0];
			fRec1182[1] = fRec1182[0];
			fRec1180[1] = fRec1180[0];
			fRec1179[1] = fRec1179[0];
			fRec1177[1] = fRec1177[0];
			fRec1176[1] = fRec1176[0];
			fRec1174[1] = fRec1174[0];
			fRec1173[1] = fRec1173[0];
			fRec1171[1] = fRec1171[0];
			fRec1191[1] = fRec1191[0];
			fRec1189[1] = fRec1189[0];
			fRec1188[1] = fRec1188[0];
			fRec1186[1] = fRec1186[0];
			fRec1185[1] = fRec1185[0];
			fRec1183[1] = fRec1183[0];
			fRec1194[1] = fRec1194[0];
			fRec1192[1] = fRec1192[0];
			fRec1200[1] = fRec1200[0];
			fRec1198[1] = fRec1198[0];
			fRec1197[1] = fRec1197[0];
			fRec1195[1] = fRec1195[0];
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
			fRec1203[1] = fRec1203[0];
			fRec1201[1] = fRec1201[0];
			fRec1233[1] = fRec1233[0];
			fRec1231[1] = fRec1231[0];
			fRec1230[1] = fRec1230[0];
			fRec1228[1] = fRec1228[0];
			fRec1227[1] = fRec1227[0];
			fRec1225[1] = fRec1225[0];
			fRec1224[1] = fRec1224[0];
			fRec1222[1] = fRec1222[0];
			fRec1221[1] = fRec1221[0];
			fRec1219[1] = fRec1219[0];
			fRec1245[1] = fRec1245[0];
			fRec1243[1] = fRec1243[0];
			fRec1242[1] = fRec1242[0];
			fRec1240[1] = fRec1240[0];
			fRec1239[1] = fRec1239[0];
			fRec1237[1] = fRec1237[0];
			fRec1236[1] = fRec1236[0];
			fRec1234[1] = fRec1234[0];
			fRec1254[1] = fRec1254[0];
			fRec1252[1] = fRec1252[0];
			fRec1251[1] = fRec1251[0];
			fRec1249[1] = fRec1249[0];
			fRec1248[1] = fRec1248[0];
			fRec1246[1] = fRec1246[0];
			fRec1257[1] = fRec1257[0];
			fRec1255[1] = fRec1255[0];
			fRec1263[1] = fRec1263[0];
			fRec1261[1] = fRec1261[0];
			fRec1260[1] = fRec1260[0];
			fRec1258[1] = fRec1258[0];
			fRec1278[1] = fRec1278[0];
			fRec1276[1] = fRec1276[0];
			fRec1275[1] = fRec1275[0];
			fRec1273[1] = fRec1273[0];
			fRec1272[1] = fRec1272[0];
			fRec1270[1] = fRec1270[0];
			fRec1269[1] = fRec1269[0];
			fRec1267[1] = fRec1267[0];
			fRec1266[1] = fRec1266[0];
			fRec1264[1] = fRec1264[0];
			fRec1290[1] = fRec1290[0];
			fRec1288[1] = fRec1288[0];
			fRec1287[1] = fRec1287[0];
			fRec1285[1] = fRec1285[0];
			fRec1284[1] = fRec1284[0];
			fRec1282[1] = fRec1282[0];
			fRec1281[1] = fRec1281[0];
			fRec1279[1] = fRec1279[0];
			fRec1299[1] = fRec1299[0];
			fRec1297[1] = fRec1297[0];
			fRec1296[1] = fRec1296[0];
			fRec1294[1] = fRec1294[0];
			fRec1293[1] = fRec1293[0];
			fRec1291[1] = fRec1291[0];
			fRec1305[1] = fRec1305[0];
			fRec1303[1] = fRec1303[0];
			fRec1302[1] = fRec1302[0];
			fRec1300[1] = fRec1300[0];
			fRec1323[1] = fRec1323[0];
			fRec1321[1] = fRec1321[0];
			fRec1320[1] = fRec1320[0];
			fRec1318[1] = fRec1318[0];
			fRec1317[1] = fRec1317[0];
			fRec1315[1] = fRec1315[0];
			fRec1314[1] = fRec1314[0];
			fRec1312[1] = fRec1312[0];
			fRec1311[1] = fRec1311[0];
			fRec1309[1] = fRec1309[0];
			fRec1308[1] = fRec1308[0];
			fRec1306[1] = fRec1306[0];
			fRec1326[1] = fRec1326[0];
			fRec1324[1] = fRec1324[0];
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
			fRec1329[1] = fRec1329[0];
			fRec1327[1] = fRec1327[0];
			fRec1359[1] = fRec1359[0];
			fRec1357[1] = fRec1357[0];
			fRec1356[1] = fRec1356[0];
			fRec1354[1] = fRec1354[0];
			fRec1353[1] = fRec1353[0];
			fRec1351[1] = fRec1351[0];
			fRec1350[1] = fRec1350[0];
			fRec1348[1] = fRec1348[0];
			fRec1347[1] = fRec1347[0];
			fRec1345[1] = fRec1345[0];
			fRec1371[1] = fRec1371[0];
			fRec1369[1] = fRec1369[0];
			fRec1368[1] = fRec1368[0];
			fRec1366[1] = fRec1366[0];
			fRec1365[1] = fRec1365[0];
			fRec1363[1] = fRec1363[0];
			fRec1362[1] = fRec1362[0];
			fRec1360[1] = fRec1360[0];
			fRec1380[1] = fRec1380[0];
			fRec1378[1] = fRec1378[0];
			fRec1377[1] = fRec1377[0];
			fRec1375[1] = fRec1375[0];
			fRec1374[1] = fRec1374[0];
			fRec1372[1] = fRec1372[0];
			fRec1383[1] = fRec1383[0];
			fRec1381[1] = fRec1381[0];
			fRec1389[1] = fRec1389[0];
			fRec1387[1] = fRec1387[0];
			fRec1386[1] = fRec1386[0];
			fRec1384[1] = fRec1384[0];
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
			fRec1392[1] = fRec1392[0];
			fRec1390[1] = fRec1390[0];
			fRec1422[1] = fRec1422[0];
			fRec1420[1] = fRec1420[0];
			fRec1419[1] = fRec1419[0];
			fRec1417[1] = fRec1417[0];
			fRec1416[1] = fRec1416[0];
			fRec1414[1] = fRec1414[0];
			fRec1413[1] = fRec1413[0];
			fRec1411[1] = fRec1411[0];
			fRec1410[1] = fRec1410[0];
			fRec1408[1] = fRec1408[0];
			fRec1434[1] = fRec1434[0];
			fRec1432[1] = fRec1432[0];
			fRec1431[1] = fRec1431[0];
			fRec1429[1] = fRec1429[0];
			fRec1428[1] = fRec1428[0];
			fRec1426[1] = fRec1426[0];
			fRec1425[1] = fRec1425[0];
			fRec1423[1] = fRec1423[0];
			fRec1443[1] = fRec1443[0];
			fRec1441[1] = fRec1441[0];
			fRec1440[1] = fRec1440[0];
			fRec1438[1] = fRec1438[0];
			fRec1437[1] = fRec1437[0];
			fRec1435[1] = fRec1435[0];
			fRec1446[1] = fRec1446[0];
			fRec1444[1] = fRec1444[0];
			fRec1452[1] = fRec1452[0];
			fRec1450[1] = fRec1450[0];
			fRec1449[1] = fRec1449[0];
			fRec1447[1] = fRec1447[0];
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
			fRec1455[1] = fRec1455[0];
			fRec1453[1] = fRec1453[0];
			fRec1485[1] = fRec1485[0];
			fRec1483[1] = fRec1483[0];
			fRec1482[1] = fRec1482[0];
			fRec1480[1] = fRec1480[0];
			fRec1479[1] = fRec1479[0];
			fRec1477[1] = fRec1477[0];
			fRec1476[1] = fRec1476[0];
			fRec1474[1] = fRec1474[0];
			fRec1473[1] = fRec1473[0];
			fRec1471[1] = fRec1471[0];
			fRec1497[1] = fRec1497[0];
			fRec1495[1] = fRec1495[0];
			fRec1494[1] = fRec1494[0];
			fRec1492[1] = fRec1492[0];
			fRec1491[1] = fRec1491[0];
			fRec1489[1] = fRec1489[0];
			fRec1488[1] = fRec1488[0];
			fRec1486[1] = fRec1486[0];
			fRec1506[1] = fRec1506[0];
			fRec1504[1] = fRec1504[0];
			fRec1503[1] = fRec1503[0];
			fRec1501[1] = fRec1501[0];
			fRec1500[1] = fRec1500[0];
			fRec1498[1] = fRec1498[0];
			fRec1509[1] = fRec1509[0];
			fRec1507[1] = fRec1507[0];
			fRec1515[1] = fRec1515[0];
			fRec1513[1] = fRec1513[0];
			fRec1512[1] = fRec1512[0];
			fRec1510[1] = fRec1510[0];
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
			fRec1518[1] = fRec1518[0];
			fRec1516[1] = fRec1516[0];
			fRec1548[1] = fRec1548[0];
			fRec1546[1] = fRec1546[0];
			fRec1545[1] = fRec1545[0];
			fRec1543[1] = fRec1543[0];
			fRec1542[1] = fRec1542[0];
			fRec1540[1] = fRec1540[0];
			fRec1539[1] = fRec1539[0];
			fRec1537[1] = fRec1537[0];
			fRec1536[1] = fRec1536[0];
			fRec1534[1] = fRec1534[0];
			fRec1560[1] = fRec1560[0];
			fRec1558[1] = fRec1558[0];
			fRec1557[1] = fRec1557[0];
			fRec1555[1] = fRec1555[0];
			fRec1554[1] = fRec1554[0];
			fRec1552[1] = fRec1552[0];
			fRec1551[1] = fRec1551[0];
			fRec1549[1] = fRec1549[0];
			fRec1569[1] = fRec1569[0];
			fRec1567[1] = fRec1567[0];
			fRec1566[1] = fRec1566[0];
			fRec1564[1] = fRec1564[0];
			fRec1563[1] = fRec1563[0];
			fRec1561[1] = fRec1561[0];
			fRec1572[1] = fRec1572[0];
			fRec1570[1] = fRec1570[0];
			fRec1578[1] = fRec1578[0];
			fRec1576[1] = fRec1576[0];
			fRec1575[1] = fRec1575[0];
			fRec1573[1] = fRec1573[0];
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
			fRec1581[1] = fRec1581[0];
			fRec1579[1] = fRec1579[0];
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
			fRec1641[1] = fRec1641[0];
			fRec1639[1] = fRec1639[0];
			fRec1638[1] = fRec1638[0];
			fRec1636[1] = fRec1636[0];
			fRec1635[1] = fRec1635[0];
			fRec1633[1] = fRec1633[0];
			fRec1632[1] = fRec1632[0];
			fRec1630[1] = fRec1630[0];
			fRec1629[1] = fRec1629[0];
			fRec1627[1] = fRec1627[0];
			fRec1659[1] = fRec1659[0];
			fRec1657[1] = fRec1657[0];
			fRec1656[1] = fRec1656[0];
			fRec1654[1] = fRec1654[0];
			fRec1653[1] = fRec1653[0];
			fRec1651[1] = fRec1651[0];
			fRec1650[1] = fRec1650[0];
			fRec1648[1] = fRec1648[0];
			fRec1647[1] = fRec1647[0];
			fRec1645[1] = fRec1645[0];
			fRec1644[1] = fRec1644[0];
			fRec1642[1] = fRec1642[0];
			fRec1674[1] = fRec1674[0];
			fRec1672[1] = fRec1672[0];
			fRec1671[1] = fRec1671[0];
			fRec1669[1] = fRec1669[0];
			fRec1668[1] = fRec1668[0];
			fRec1666[1] = fRec1666[0];
			fRec1665[1] = fRec1665[0];
			fRec1663[1] = fRec1663[0];
			fRec1662[1] = fRec1662[0];
			fRec1660[1] = fRec1660[0];
			fRec1686[1] = fRec1686[0];
			fRec1684[1] = fRec1684[0];
			fRec1683[1] = fRec1683[0];
			fRec1681[1] = fRec1681[0];
			fRec1680[1] = fRec1680[0];
			fRec1678[1] = fRec1678[0];
			fRec1677[1] = fRec1677[0];
			fRec1675[1] = fRec1675[0];
			fRec1695[1] = fRec1695[0];
			fRec1693[1] = fRec1693[0];
			fRec1692[1] = fRec1692[0];
			fRec1690[1] = fRec1690[0];
			fRec1689[1] = fRec1689[0];
			fRec1687[1] = fRec1687[0];
			fRec1698[1] = fRec1698[0];
			fRec1696[1] = fRec1696[0];
			fRec1704[1] = fRec1704[0];
			fRec1702[1] = fRec1702[0];
			fRec1701[1] = fRec1701[0];
			fRec1699[1] = fRec1699[0];
			fRec1719[1] = fRec1719[0];
			fRec1717[1] = fRec1717[0];
			fRec1716[1] = fRec1716[0];
			fRec1714[1] = fRec1714[0];
			fRec1713[1] = fRec1713[0];
			fRec1711[1] = fRec1711[0];
			fRec1710[1] = fRec1710[0];
			fRec1708[1] = fRec1708[0];
			fRec1707[1] = fRec1707[0];
			fRec1705[1] = fRec1705[0];
			fRec1731[1] = fRec1731[0];
			fRec1729[1] = fRec1729[0];
			fRec1728[1] = fRec1728[0];
			fRec1726[1] = fRec1726[0];
			fRec1725[1] = fRec1725[0];
			fRec1723[1] = fRec1723[0];
			fRec1722[1] = fRec1722[0];
			fRec1720[1] = fRec1720[0];
			fRec1740[1] = fRec1740[0];
			fRec1738[1] = fRec1738[0];
			fRec1737[1] = fRec1737[0];
			fRec1735[1] = fRec1735[0];
			fRec1734[1] = fRec1734[0];
			fRec1732[1] = fRec1732[0];
			fRec1743[1] = fRec1743[0];
			fRec1741[1] = fRec1741[0];
			fRec1749[1] = fRec1749[0];
			fRec1747[1] = fRec1747[0];
			fRec1746[1] = fRec1746[0];
			fRec1744[1] = fRec1744[0];
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
			fRec1752[1] = fRec1752[0];
			fRec1750[1] = fRec1750[0];
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
			fRec1770[1] = fRec1770[0];
			fRec1768[1] = fRec1768[0];
			fRec1800[1] = fRec1800[0];
			fRec1798[1] = fRec1798[0];
			fRec1797[1] = fRec1797[0];
			fRec1795[1] = fRec1795[0];
			fRec1794[1] = fRec1794[0];
			fRec1792[1] = fRec1792[0];
			fRec1791[1] = fRec1791[0];
			fRec1789[1] = fRec1789[0];
			fRec1788[1] = fRec1788[0];
			fRec1786[1] = fRec1786[0];
			fRec1812[1] = fRec1812[0];
			fRec1810[1] = fRec1810[0];
			fRec1809[1] = fRec1809[0];
			fRec1807[1] = fRec1807[0];
			fRec1806[1] = fRec1806[0];
			fRec1804[1] = fRec1804[0];
			fRec1803[1] = fRec1803[0];
			fRec1801[1] = fRec1801[0];
			fRec1818[1] = fRec1818[0];
			fRec1816[1] = fRec1816[0];
			fRec1815[1] = fRec1815[0];
			fRec1813[1] = fRec1813[0];
			fRec1827[1] = fRec1827[0];
			fRec1825[1] = fRec1825[0];
			fRec1824[1] = fRec1824[0];
			fRec1822[1] = fRec1822[0];
			fRec1821[1] = fRec1821[0];
			fRec1819[1] = fRec1819[0];
			fRec1830[1] = fRec1830[0];
			fRec1828[1] = fRec1828[0];
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
			fRec1833[1] = fRec1833[0];
			fRec1831[1] = fRec1831[0];
			fRec1863[1] = fRec1863[0];
			fRec1861[1] = fRec1861[0];
			fRec1860[1] = fRec1860[0];
			fRec1858[1] = fRec1858[0];
			fRec1857[1] = fRec1857[0];
			fRec1855[1] = fRec1855[0];
			fRec1854[1] = fRec1854[0];
			fRec1852[1] = fRec1852[0];
			fRec1851[1] = fRec1851[0];
			fRec1849[1] = fRec1849[0];
			fRec1875[1] = fRec1875[0];
			fRec1873[1] = fRec1873[0];
			fRec1872[1] = fRec1872[0];
			fRec1870[1] = fRec1870[0];
			fRec1869[1] = fRec1869[0];
			fRec1867[1] = fRec1867[0];
			fRec1866[1] = fRec1866[0];
			fRec1864[1] = fRec1864[0];
			fRec1884[1] = fRec1884[0];
			fRec1882[1] = fRec1882[0];
			fRec1881[1] = fRec1881[0];
			fRec1879[1] = fRec1879[0];
			fRec1878[1] = fRec1878[0];
			fRec1876[1] = fRec1876[0];
			fRec1887[1] = fRec1887[0];
			fRec1885[1] = fRec1885[0];
			fRec1893[1] = fRec1893[0];
			fRec1891[1] = fRec1891[0];
			fRec1890[1] = fRec1890[0];
			fRec1888[1] = fRec1888[0];
			
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
