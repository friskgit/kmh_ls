/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMHLS_Dome_7h7p_normal_6"
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
	double fRec9[3];
	double fRec10[3];
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
	double fRec29[2];
	double fRec27[2];
	double fRec26[2];
	double fRec24[2];
	double fRec23[2];
	double fRec21[2];
	double fRec20[2];
	double fRec18[2];
	double fRec17[2];
	double fRec15[2];
	double fRec14[2];
	double fRec12[2];
	double fRec11[3];
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
	double fRec33[2];
	double fRec31[2];
	double fRec30[3];
	double fRec67[2];
	double fRec65[2];
	double fRec64[2];
	double fRec62[2];
	double fRec61[2];
	double fRec59[2];
	double fRec58[2];
	double fRec56[2];
	double fRec55[2];
	double fRec53[2];
	double fRec52[2];
	double fRec50[2];
	double fRec49[3];
	double fRec86[2];
	double fRec84[2];
	double fRec83[2];
	double fRec81[2];
	double fRec80[2];
	double fRec78[2];
	double fRec77[2];
	double fRec75[2];
	double fRec74[2];
	double fRec72[2];
	double fRec71[2];
	double fRec69[2];
	double fRec68[3];
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
	double fRec87[3];
	double fRec124[2];
	double fRec122[2];
	double fRec121[2];
	double fRec119[2];
	double fRec118[2];
	double fRec116[2];
	double fRec115[2];
	double fRec113[2];
	double fRec112[2];
	double fRec110[2];
	double fRec109[2];
	double fRec107[2];
	double fRec106[3];
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
	double fRec128[2];
	double fRec126[2];
	double fRec125[3];
	double fConst14;
	double fConst15;
	double fConst16;
	double fConst17;
	double fConst18;
	double fConst19;
	double fConst20;
	double fConst21;
	double fConst22;
	double fRec159[2];
	double fRec157[2];
	double fRec156[2];
	double fRec154[2];
	double fRec153[2];
	double fRec151[2];
	double fRec150[2];
	double fRec148[2];
	double fRec147[2];
	double fRec145[2];
	double fRec144[3];
	double fRec175[2];
	double fRec173[2];
	double fRec172[2];
	double fRec170[2];
	double fRec169[2];
	double fRec167[2];
	double fRec166[2];
	double fRec164[2];
	double fRec163[2];
	double fRec161[2];
	double fRec160[3];
	double fRec191[2];
	double fRec189[2];
	double fRec188[2];
	double fRec186[2];
	double fRec185[2];
	double fRec183[2];
	double fRec182[2];
	double fRec180[2];
	double fRec179[2];
	double fRec177[2];
	double fRec176[3];
	double fRec207[2];
	double fRec205[2];
	double fRec204[2];
	double fRec202[2];
	double fRec201[2];
	double fRec199[2];
	double fRec198[2];
	double fRec196[2];
	double fRec195[2];
	double fRec193[2];
	double fRec192[3];
	double fConst23;
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fConst28;
	double fConst29;
	double fRec220[2];
	double fRec218[2];
	double fRec217[2];
	double fRec215[2];
	double fRec214[2];
	double fRec212[2];
	double fRec211[2];
	double fRec209[2];
	double fRec208[3];
	double fConst30;
	double fConst31;
	double fConst32;
	double fConst33;
	double fRec227[2];
	double fRec225[2];
	double fRec224[2];
	double fRec222[2];
	double fRec221[3];
	double fConst34;
	double fConst35;
	double fConst36;
	double fRec231[2];
	double fRec229[2];
	double fRec228[3];
	double fRec232[3];
	double fRec236[2];
	double fRec234[2];
	double fRec233[3];
	double fRec243[2];
	double fRec241[2];
	double fRec240[2];
	double fRec238[2];
	double fRec237[3];
	double fConst37;
	double fConst38;
	double fConst39;
	double fConst40;
	double fConst41;
	double fConst42;
	double fRec253[2];
	double fRec251[2];
	double fRec250[2];
	double fRec248[2];
	double fRec247[2];
	double fRec245[2];
	double fRec244[3];
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
	double fRec326[2];
	double fRec324[2];
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
	double fRec308[3];
	double fRec345[2];
	double fRec343[2];
	double fRec342[2];
	double fRec340[2];
	double fRec339[2];
	double fRec337[2];
	double fRec336[2];
	double fRec334[2];
	double fRec333[2];
	double fRec331[2];
	double fRec330[2];
	double fRec328[2];
	double fRec327[3];
	double fRec364[2];
	double fRec362[2];
	double fRec361[2];
	double fRec359[2];
	double fRec358[2];
	double fRec356[2];
	double fRec355[2];
	double fRec353[2];
	double fRec352[2];
	double fRec350[2];
	double fRec349[2];
	double fRec347[2];
	double fRec346[3];
	double fRec383[2];
	double fRec381[2];
	double fRec380[2];
	double fRec378[2];
	double fRec377[2];
	double fRec375[2];
	double fRec374[2];
	double fRec372[2];
	double fRec371[2];
	double fRec369[2];
	double fRec368[2];
	double fRec366[2];
	double fRec365[3];
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
	double fRec384[3];
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
	double fRec400[3];
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
	double fRec432[3];
	double fRec463[2];
	double fRec461[2];
	double fRec460[2];
	double fRec458[2];
	double fRec457[2];
	double fRec455[2];
	double fRec454[2];
	double fRec452[2];
	double fRec451[2];
	double fRec449[2];
	double fRec448[3];
	double fRec476[2];
	double fRec474[2];
	double fRec473[2];
	double fRec471[2];
	double fRec470[2];
	double fRec468[2];
	double fRec467[2];
	double fRec465[2];
	double fRec464[3];
	double fRec489[2];
	double fRec487[2];
	double fRec486[2];
	double fRec484[2];
	double fRec483[2];
	double fRec481[2];
	double fRec480[2];
	double fRec478[2];
	double fRec477[3];
	double fRec502[2];
	double fRec500[2];
	double fRec499[2];
	double fRec497[2];
	double fRec496[2];
	double fRec494[2];
	double fRec493[2];
	double fRec491[2];
	double fRec490[3];
	double fRec515[2];
	double fRec513[2];
	double fRec512[2];
	double fRec510[2];
	double fRec509[2];
	double fRec507[2];
	double fRec506[2];
	double fRec504[2];
	double fRec503[3];
	double fRec528[2];
	double fRec526[2];
	double fRec525[2];
	double fRec523[2];
	double fRec522[2];
	double fRec520[2];
	double fRec519[2];
	double fRec517[2];
	double fRec516[3];
	double fRec541[2];
	double fRec539[2];
	double fRec538[2];
	double fRec536[2];
	double fRec535[2];
	double fRec533[2];
	double fRec532[2];
	double fRec530[2];
	double fRec529[3];
	double fRec551[2];
	double fRec549[2];
	double fRec548[2];
	double fRec546[2];
	double fRec545[2];
	double fRec543[2];
	double fRec542[3];
	double fRec561[2];
	double fRec559[2];
	double fRec558[2];
	double fRec556[2];
	double fRec555[2];
	double fRec553[2];
	double fRec552[3];
	double fRec571[2];
	double fRec569[2];
	double fRec568[2];
	double fRec566[2];
	double fRec565[2];
	double fRec563[2];
	double fRec562[3];
	double fRec581[2];
	double fRec579[2];
	double fRec578[2];
	double fRec576[2];
	double fRec575[2];
	double fRec573[2];
	double fRec572[3];
	double fRec591[2];
	double fRec589[2];
	double fRec588[2];
	double fRec586[2];
	double fRec585[2];
	double fRec583[2];
	double fRec582[3];
	double fRec598[2];
	double fRec596[2];
	double fRec595[2];
	double fRec593[2];
	double fRec592[3];
	double fRec605[2];
	double fRec603[2];
	double fRec602[2];
	double fRec600[2];
	double fRec599[3];
	double fRec609[2];
	double fRec607[2];
	double fRec606[3];
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
		m->declare("filename", "KMHLS_Dome_7h7p_normal_6");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMHLS_Dome_7h7p_normal_6");
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
		fConst30 = ((((3284.3312440580044 / fConst2) + 99.262247265382882) / fConst2) + 1.0);
		fConst31 = (1.0 / fConst30);
		fConst32 = (0.0 - (13137.324976232017 / (fConst3 * fConst30)));
		fConst33 = (0.0 - (((13137.324976232017 / fConst2) + 198.52449453076576) / (fConst2 * fConst30)));
		fConst34 = ((33.08741575512763 / fConst2) + 1.0);
		fConst35 = (1.0 / fConst34);
		fConst36 = (0.0 - (66.17483151025526 / (fConst2 * fConst34)));
		fConst37 = ((76.835112288981804 / fConst2) + 1.0);
		fConst38 = (0.0 - (153.67022457796361 / (fConst2 * fConst37)));
		fConst39 = ((((7071.6388713657261 / fConst2) + 121.68938224178397) / fConst2) + 1.0);
		fConst40 = (1.0 / (fConst37 * fConst39));
		fConst41 = (0.0 - (28286.555485462904 / (fConst3 * fConst39)));
		fConst42 = (0.0 - (((28286.555485462904 / fConst2) + 243.37876448356795) / (fConst2 * fConst39)));
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
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec9[l9] = 0.0;
			
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec10[l10] = 0.0;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec29[l11] = 0.0;
			
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec27[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec26[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec24[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec23[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec21[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec20[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec18[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec17[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec15[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec14[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec12[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec11[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec48[l24] = 0.0;
			
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec46[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec45[l26] = 0.0;
			
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec43[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec42[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec40[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec39[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec37[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec36[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec34[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec33[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec31[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 3); l36 = (l36 + 1)) {
			fRec30[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec67[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec65[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec64[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec62[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec61[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec59[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec58[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec56[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec55[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec53[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec52[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec50[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 3); l49 = (l49 + 1)) {
			fRec49[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec86[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec84[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec83[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fRec81[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec80[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec78[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fRec77[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fRec75[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec74[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec72[l59] = 0.0;
			
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			fRec71[l60] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec69[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 3); l62 = (l62 + 1)) {
			fRec68[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec105[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec103[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec102[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec100[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec99[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec97[l68] = 0.0;
			
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec96[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec94[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec93[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec91[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec90[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec88[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 3); l75 = (l75 + 1)) {
			fRec87[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec124[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec122[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec121[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fRec119[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec118[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec116[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec115[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fRec113[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec112[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec110[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec109[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 2); l87 = (l87 + 1)) {
			fRec107[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 3); l88 = (l88 + 1)) {
			fRec106[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec143[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec141[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec140[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec138[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec137[l93] = 0.0;
			
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec135[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec134[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fRec132[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec131[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec129[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec128[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 2); l100 = (l100 + 1)) {
			fRec126[l100] = 0.0;
			
		}
		for (int l101 = 0; (l101 < 3); l101 = (l101 + 1)) {
			fRec125[l101] = 0.0;
			
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec159[l102] = 0.0;
			
		}
		for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) {
			fRec157[l103] = 0.0;
			
		}
		for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) {
			fRec156[l104] = 0.0;
			
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fRec154[l105] = 0.0;
			
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec153[l106] = 0.0;
			
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fRec151[l107] = 0.0;
			
		}
		for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) {
			fRec150[l108] = 0.0;
			
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec148[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec147[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec145[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 3); l112 = (l112 + 1)) {
			fRec144[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec175[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec173[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec172[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec170[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec169[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec167[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec166[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec164[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec163[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec161[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 3); l123 = (l123 + 1)) {
			fRec160[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec191[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fRec189[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec188[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec186[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec185[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec183[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec182[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 2); l131 = (l131 + 1)) {
			fRec180[l131] = 0.0;
			
		}
		for (int l132 = 0; (l132 < 2); l132 = (l132 + 1)) {
			fRec179[l132] = 0.0;
			
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec177[l133] = 0.0;
			
		}
		for (int l134 = 0; (l134 < 3); l134 = (l134 + 1)) {
			fRec176[l134] = 0.0;
			
		}
		for (int l135 = 0; (l135 < 2); l135 = (l135 + 1)) {
			fRec207[l135] = 0.0;
			
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec205[l136] = 0.0;
			
		}
		for (int l137 = 0; (l137 < 2); l137 = (l137 + 1)) {
			fRec204[l137] = 0.0;
			
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec202[l138] = 0.0;
			
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fRec201[l139] = 0.0;
			
		}
		for (int l140 = 0; (l140 < 2); l140 = (l140 + 1)) {
			fRec199[l140] = 0.0;
			
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fRec198[l141] = 0.0;
			
		}
		for (int l142 = 0; (l142 < 2); l142 = (l142 + 1)) {
			fRec196[l142] = 0.0;
			
		}
		for (int l143 = 0; (l143 < 2); l143 = (l143 + 1)) {
			fRec195[l143] = 0.0;
			
		}
		for (int l144 = 0; (l144 < 2); l144 = (l144 + 1)) {
			fRec193[l144] = 0.0;
			
		}
		for (int l145 = 0; (l145 < 3); l145 = (l145 + 1)) {
			fRec192[l145] = 0.0;
			
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fRec220[l146] = 0.0;
			
		}
		for (int l147 = 0; (l147 < 2); l147 = (l147 + 1)) {
			fRec218[l147] = 0.0;
			
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
		for (int l152 = 0; (l152 < 2); l152 = (l152 + 1)) {
			fRec211[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec209[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 3); l154 = (l154 + 1)) {
			fRec208[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec227[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec225[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec224[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec222[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 3); l159 = (l159 + 1)) {
			fRec221[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec231[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec229[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 3); l162 = (l162 + 1)) {
			fRec228[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 3); l163 = (l163 + 1)) {
			fRec232[l163] = 0.0;
			
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
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fRec326[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec324[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fRec323[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec321[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec320[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec318[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 2); l224 = (l224 + 1)) {
			fRec317[l224] = 0.0;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec315[l225] = 0.0;
			
		}
		for (int l226 = 0; (l226 < 2); l226 = (l226 + 1)) {
			fRec314[l226] = 0.0;
			
		}
		for (int l227 = 0; (l227 < 2); l227 = (l227 + 1)) {
			fRec312[l227] = 0.0;
			
		}
		for (int l228 = 0; (l228 < 2); l228 = (l228 + 1)) {
			fRec311[l228] = 0.0;
			
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fRec309[l229] = 0.0;
			
		}
		for (int l230 = 0; (l230 < 3); l230 = (l230 + 1)) {
			fRec308[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fRec345[l231] = 0.0;
			
		}
		for (int l232 = 0; (l232 < 2); l232 = (l232 + 1)) {
			fRec343[l232] = 0.0;
			
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fRec342[l233] = 0.0;
			
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec340[l234] = 0.0;
			
		}
		for (int l235 = 0; (l235 < 2); l235 = (l235 + 1)) {
			fRec339[l235] = 0.0;
			
		}
		for (int l236 = 0; (l236 < 2); l236 = (l236 + 1)) {
			fRec337[l236] = 0.0;
			
		}
		for (int l237 = 0; (l237 < 2); l237 = (l237 + 1)) {
			fRec336[l237] = 0.0;
			
		}
		for (int l238 = 0; (l238 < 2); l238 = (l238 + 1)) {
			fRec334[l238] = 0.0;
			
		}
		for (int l239 = 0; (l239 < 2); l239 = (l239 + 1)) {
			fRec333[l239] = 0.0;
			
		}
		for (int l240 = 0; (l240 < 2); l240 = (l240 + 1)) {
			fRec331[l240] = 0.0;
			
		}
		for (int l241 = 0; (l241 < 2); l241 = (l241 + 1)) {
			fRec330[l241] = 0.0;
			
		}
		for (int l242 = 0; (l242 < 2); l242 = (l242 + 1)) {
			fRec328[l242] = 0.0;
			
		}
		for (int l243 = 0; (l243 < 3); l243 = (l243 + 1)) {
			fRec327[l243] = 0.0;
			
		}
		for (int l244 = 0; (l244 < 2); l244 = (l244 + 1)) {
			fRec364[l244] = 0.0;
			
		}
		for (int l245 = 0; (l245 < 2); l245 = (l245 + 1)) {
			fRec362[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fRec361[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 2); l247 = (l247 + 1)) {
			fRec359[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 2); l248 = (l248 + 1)) {
			fRec358[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fRec356[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 2); l250 = (l250 + 1)) {
			fRec355[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 2); l251 = (l251 + 1)) {
			fRec353[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 2); l252 = (l252 + 1)) {
			fRec352[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec350[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec349[l254] = 0.0;
			
		}
		for (int l255 = 0; (l255 < 2); l255 = (l255 + 1)) {
			fRec347[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 3); l256 = (l256 + 1)) {
			fRec346[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fRec383[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec381[l258] = 0.0;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec380[l259] = 0.0;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec378[l260] = 0.0;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec377[l261] = 0.0;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec375[l262] = 0.0;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec374[l263] = 0.0;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec372[l264] = 0.0;
			
		}
		for (int l265 = 0; (l265 < 2); l265 = (l265 + 1)) {
			fRec371[l265] = 0.0;
			
		}
		for (int l266 = 0; (l266 < 2); l266 = (l266 + 1)) {
			fRec369[l266] = 0.0;
			
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec368[l267] = 0.0;
			
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec366[l268] = 0.0;
			
		}
		for (int l269 = 0; (l269 < 3); l269 = (l269 + 1)) {
			fRec365[l269] = 0.0;
			
		}
		for (int l270 = 0; (l270 < 2); l270 = (l270 + 1)) {
			fRec399[l270] = 0.0;
			
		}
		for (int l271 = 0; (l271 < 2); l271 = (l271 + 1)) {
			fRec397[l271] = 0.0;
			
		}
		for (int l272 = 0; (l272 < 2); l272 = (l272 + 1)) {
			fRec396[l272] = 0.0;
			
		}
		for (int l273 = 0; (l273 < 2); l273 = (l273 + 1)) {
			fRec394[l273] = 0.0;
			
		}
		for (int l274 = 0; (l274 < 2); l274 = (l274 + 1)) {
			fRec393[l274] = 0.0;
			
		}
		for (int l275 = 0; (l275 < 2); l275 = (l275 + 1)) {
			fRec391[l275] = 0.0;
			
		}
		for (int l276 = 0; (l276 < 2); l276 = (l276 + 1)) {
			fRec390[l276] = 0.0;
			
		}
		for (int l277 = 0; (l277 < 2); l277 = (l277 + 1)) {
			fRec388[l277] = 0.0;
			
		}
		for (int l278 = 0; (l278 < 2); l278 = (l278 + 1)) {
			fRec387[l278] = 0.0;
			
		}
		for (int l279 = 0; (l279 < 2); l279 = (l279 + 1)) {
			fRec385[l279] = 0.0;
			
		}
		for (int l280 = 0; (l280 < 3); l280 = (l280 + 1)) {
			fRec384[l280] = 0.0;
			
		}
		for (int l281 = 0; (l281 < 2); l281 = (l281 + 1)) {
			fRec415[l281] = 0.0;
			
		}
		for (int l282 = 0; (l282 < 2); l282 = (l282 + 1)) {
			fRec413[l282] = 0.0;
			
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec412[l283] = 0.0;
			
		}
		for (int l284 = 0; (l284 < 2); l284 = (l284 + 1)) {
			fRec410[l284] = 0.0;
			
		}
		for (int l285 = 0; (l285 < 2); l285 = (l285 + 1)) {
			fRec409[l285] = 0.0;
			
		}
		for (int l286 = 0; (l286 < 2); l286 = (l286 + 1)) {
			fRec407[l286] = 0.0;
			
		}
		for (int l287 = 0; (l287 < 2); l287 = (l287 + 1)) {
			fRec406[l287] = 0.0;
			
		}
		for (int l288 = 0; (l288 < 2); l288 = (l288 + 1)) {
			fRec404[l288] = 0.0;
			
		}
		for (int l289 = 0; (l289 < 2); l289 = (l289 + 1)) {
			fRec403[l289] = 0.0;
			
		}
		for (int l290 = 0; (l290 < 2); l290 = (l290 + 1)) {
			fRec401[l290] = 0.0;
			
		}
		for (int l291 = 0; (l291 < 3); l291 = (l291 + 1)) {
			fRec400[l291] = 0.0;
			
		}
		for (int l292 = 0; (l292 < 2); l292 = (l292 + 1)) {
			fRec431[l292] = 0.0;
			
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec429[l293] = 0.0;
			
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec428[l294] = 0.0;
			
		}
		for (int l295 = 0; (l295 < 2); l295 = (l295 + 1)) {
			fRec426[l295] = 0.0;
			
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec425[l296] = 0.0;
			
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec423[l297] = 0.0;
			
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec422[l298] = 0.0;
			
		}
		for (int l299 = 0; (l299 < 2); l299 = (l299 + 1)) {
			fRec420[l299] = 0.0;
			
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec419[l300] = 0.0;
			
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec417[l301] = 0.0;
			
		}
		for (int l302 = 0; (l302 < 3); l302 = (l302 + 1)) {
			fRec416[l302] = 0.0;
			
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec447[l303] = 0.0;
			
		}
		for (int l304 = 0; (l304 < 2); l304 = (l304 + 1)) {
			fRec445[l304] = 0.0;
			
		}
		for (int l305 = 0; (l305 < 2); l305 = (l305 + 1)) {
			fRec444[l305] = 0.0;
			
		}
		for (int l306 = 0; (l306 < 2); l306 = (l306 + 1)) {
			fRec442[l306] = 0.0;
			
		}
		for (int l307 = 0; (l307 < 2); l307 = (l307 + 1)) {
			fRec441[l307] = 0.0;
			
		}
		for (int l308 = 0; (l308 < 2); l308 = (l308 + 1)) {
			fRec439[l308] = 0.0;
			
		}
		for (int l309 = 0; (l309 < 2); l309 = (l309 + 1)) {
			fRec438[l309] = 0.0;
			
		}
		for (int l310 = 0; (l310 < 2); l310 = (l310 + 1)) {
			fRec436[l310] = 0.0;
			
		}
		for (int l311 = 0; (l311 < 2); l311 = (l311 + 1)) {
			fRec435[l311] = 0.0;
			
		}
		for (int l312 = 0; (l312 < 2); l312 = (l312 + 1)) {
			fRec433[l312] = 0.0;
			
		}
		for (int l313 = 0; (l313 < 3); l313 = (l313 + 1)) {
			fRec432[l313] = 0.0;
			
		}
		for (int l314 = 0; (l314 < 2); l314 = (l314 + 1)) {
			fRec463[l314] = 0.0;
			
		}
		for (int l315 = 0; (l315 < 2); l315 = (l315 + 1)) {
			fRec461[l315] = 0.0;
			
		}
		for (int l316 = 0; (l316 < 2); l316 = (l316 + 1)) {
			fRec460[l316] = 0.0;
			
		}
		for (int l317 = 0; (l317 < 2); l317 = (l317 + 1)) {
			fRec458[l317] = 0.0;
			
		}
		for (int l318 = 0; (l318 < 2); l318 = (l318 + 1)) {
			fRec457[l318] = 0.0;
			
		}
		for (int l319 = 0; (l319 < 2); l319 = (l319 + 1)) {
			fRec455[l319] = 0.0;
			
		}
		for (int l320 = 0; (l320 < 2); l320 = (l320 + 1)) {
			fRec454[l320] = 0.0;
			
		}
		for (int l321 = 0; (l321 < 2); l321 = (l321 + 1)) {
			fRec452[l321] = 0.0;
			
		}
		for (int l322 = 0; (l322 < 2); l322 = (l322 + 1)) {
			fRec451[l322] = 0.0;
			
		}
		for (int l323 = 0; (l323 < 2); l323 = (l323 + 1)) {
			fRec449[l323] = 0.0;
			
		}
		for (int l324 = 0; (l324 < 3); l324 = (l324 + 1)) {
			fRec448[l324] = 0.0;
			
		}
		for (int l325 = 0; (l325 < 2); l325 = (l325 + 1)) {
			fRec476[l325] = 0.0;
			
		}
		for (int l326 = 0; (l326 < 2); l326 = (l326 + 1)) {
			fRec474[l326] = 0.0;
			
		}
		for (int l327 = 0; (l327 < 2); l327 = (l327 + 1)) {
			fRec473[l327] = 0.0;
			
		}
		for (int l328 = 0; (l328 < 2); l328 = (l328 + 1)) {
			fRec471[l328] = 0.0;
			
		}
		for (int l329 = 0; (l329 < 2); l329 = (l329 + 1)) {
			fRec470[l329] = 0.0;
			
		}
		for (int l330 = 0; (l330 < 2); l330 = (l330 + 1)) {
			fRec468[l330] = 0.0;
			
		}
		for (int l331 = 0; (l331 < 2); l331 = (l331 + 1)) {
			fRec467[l331] = 0.0;
			
		}
		for (int l332 = 0; (l332 < 2); l332 = (l332 + 1)) {
			fRec465[l332] = 0.0;
			
		}
		for (int l333 = 0; (l333 < 3); l333 = (l333 + 1)) {
			fRec464[l333] = 0.0;
			
		}
		for (int l334 = 0; (l334 < 2); l334 = (l334 + 1)) {
			fRec489[l334] = 0.0;
			
		}
		for (int l335 = 0; (l335 < 2); l335 = (l335 + 1)) {
			fRec487[l335] = 0.0;
			
		}
		for (int l336 = 0; (l336 < 2); l336 = (l336 + 1)) {
			fRec486[l336] = 0.0;
			
		}
		for (int l337 = 0; (l337 < 2); l337 = (l337 + 1)) {
			fRec484[l337] = 0.0;
			
		}
		for (int l338 = 0; (l338 < 2); l338 = (l338 + 1)) {
			fRec483[l338] = 0.0;
			
		}
		for (int l339 = 0; (l339 < 2); l339 = (l339 + 1)) {
			fRec481[l339] = 0.0;
			
		}
		for (int l340 = 0; (l340 < 2); l340 = (l340 + 1)) {
			fRec480[l340] = 0.0;
			
		}
		for (int l341 = 0; (l341 < 2); l341 = (l341 + 1)) {
			fRec478[l341] = 0.0;
			
		}
		for (int l342 = 0; (l342 < 3); l342 = (l342 + 1)) {
			fRec477[l342] = 0.0;
			
		}
		for (int l343 = 0; (l343 < 2); l343 = (l343 + 1)) {
			fRec502[l343] = 0.0;
			
		}
		for (int l344 = 0; (l344 < 2); l344 = (l344 + 1)) {
			fRec500[l344] = 0.0;
			
		}
		for (int l345 = 0; (l345 < 2); l345 = (l345 + 1)) {
			fRec499[l345] = 0.0;
			
		}
		for (int l346 = 0; (l346 < 2); l346 = (l346 + 1)) {
			fRec497[l346] = 0.0;
			
		}
		for (int l347 = 0; (l347 < 2); l347 = (l347 + 1)) {
			fRec496[l347] = 0.0;
			
		}
		for (int l348 = 0; (l348 < 2); l348 = (l348 + 1)) {
			fRec494[l348] = 0.0;
			
		}
		for (int l349 = 0; (l349 < 2); l349 = (l349 + 1)) {
			fRec493[l349] = 0.0;
			
		}
		for (int l350 = 0; (l350 < 2); l350 = (l350 + 1)) {
			fRec491[l350] = 0.0;
			
		}
		for (int l351 = 0; (l351 < 3); l351 = (l351 + 1)) {
			fRec490[l351] = 0.0;
			
		}
		for (int l352 = 0; (l352 < 2); l352 = (l352 + 1)) {
			fRec515[l352] = 0.0;
			
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec513[l353] = 0.0;
			
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec512[l354] = 0.0;
			
		}
		for (int l355 = 0; (l355 < 2); l355 = (l355 + 1)) {
			fRec510[l355] = 0.0;
			
		}
		for (int l356 = 0; (l356 < 2); l356 = (l356 + 1)) {
			fRec509[l356] = 0.0;
			
		}
		for (int l357 = 0; (l357 < 2); l357 = (l357 + 1)) {
			fRec507[l357] = 0.0;
			
		}
		for (int l358 = 0; (l358 < 2); l358 = (l358 + 1)) {
			fRec506[l358] = 0.0;
			
		}
		for (int l359 = 0; (l359 < 2); l359 = (l359 + 1)) {
			fRec504[l359] = 0.0;
			
		}
		for (int l360 = 0; (l360 < 3); l360 = (l360 + 1)) {
			fRec503[l360] = 0.0;
			
		}
		for (int l361 = 0; (l361 < 2); l361 = (l361 + 1)) {
			fRec528[l361] = 0.0;
			
		}
		for (int l362 = 0; (l362 < 2); l362 = (l362 + 1)) {
			fRec526[l362] = 0.0;
			
		}
		for (int l363 = 0; (l363 < 2); l363 = (l363 + 1)) {
			fRec525[l363] = 0.0;
			
		}
		for (int l364 = 0; (l364 < 2); l364 = (l364 + 1)) {
			fRec523[l364] = 0.0;
			
		}
		for (int l365 = 0; (l365 < 2); l365 = (l365 + 1)) {
			fRec522[l365] = 0.0;
			
		}
		for (int l366 = 0; (l366 < 2); l366 = (l366 + 1)) {
			fRec520[l366] = 0.0;
			
		}
		for (int l367 = 0; (l367 < 2); l367 = (l367 + 1)) {
			fRec519[l367] = 0.0;
			
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec517[l368] = 0.0;
			
		}
		for (int l369 = 0; (l369 < 3); l369 = (l369 + 1)) {
			fRec516[l369] = 0.0;
			
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec541[l370] = 0.0;
			
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			fRec539[l371] = 0.0;
			
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			fRec538[l372] = 0.0;
			
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fRec536[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec535[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 2); l375 = (l375 + 1)) {
			fRec533[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec532[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec530[l377] = 0.0;
			
		}
		for (int l378 = 0; (l378 < 3); l378 = (l378 + 1)) {
			fRec529[l378] = 0.0;
			
		}
		for (int l379 = 0; (l379 < 2); l379 = (l379 + 1)) {
			fRec551[l379] = 0.0;
			
		}
		for (int l380 = 0; (l380 < 2); l380 = (l380 + 1)) {
			fRec549[l380] = 0.0;
			
		}
		for (int l381 = 0; (l381 < 2); l381 = (l381 + 1)) {
			fRec548[l381] = 0.0;
			
		}
		for (int l382 = 0; (l382 < 2); l382 = (l382 + 1)) {
			fRec546[l382] = 0.0;
			
		}
		for (int l383 = 0; (l383 < 2); l383 = (l383 + 1)) {
			fRec545[l383] = 0.0;
			
		}
		for (int l384 = 0; (l384 < 2); l384 = (l384 + 1)) {
			fRec543[l384] = 0.0;
			
		}
		for (int l385 = 0; (l385 < 3); l385 = (l385 + 1)) {
			fRec542[l385] = 0.0;
			
		}
		for (int l386 = 0; (l386 < 2); l386 = (l386 + 1)) {
			fRec561[l386] = 0.0;
			
		}
		for (int l387 = 0; (l387 < 2); l387 = (l387 + 1)) {
			fRec559[l387] = 0.0;
			
		}
		for (int l388 = 0; (l388 < 2); l388 = (l388 + 1)) {
			fRec558[l388] = 0.0;
			
		}
		for (int l389 = 0; (l389 < 2); l389 = (l389 + 1)) {
			fRec556[l389] = 0.0;
			
		}
		for (int l390 = 0; (l390 < 2); l390 = (l390 + 1)) {
			fRec555[l390] = 0.0;
			
		}
		for (int l391 = 0; (l391 < 2); l391 = (l391 + 1)) {
			fRec553[l391] = 0.0;
			
		}
		for (int l392 = 0; (l392 < 3); l392 = (l392 + 1)) {
			fRec552[l392] = 0.0;
			
		}
		for (int l393 = 0; (l393 < 2); l393 = (l393 + 1)) {
			fRec571[l393] = 0.0;
			
		}
		for (int l394 = 0; (l394 < 2); l394 = (l394 + 1)) {
			fRec569[l394] = 0.0;
			
		}
		for (int l395 = 0; (l395 < 2); l395 = (l395 + 1)) {
			fRec568[l395] = 0.0;
			
		}
		for (int l396 = 0; (l396 < 2); l396 = (l396 + 1)) {
			fRec566[l396] = 0.0;
			
		}
		for (int l397 = 0; (l397 < 2); l397 = (l397 + 1)) {
			fRec565[l397] = 0.0;
			
		}
		for (int l398 = 0; (l398 < 2); l398 = (l398 + 1)) {
			fRec563[l398] = 0.0;
			
		}
		for (int l399 = 0; (l399 < 3); l399 = (l399 + 1)) {
			fRec562[l399] = 0.0;
			
		}
		for (int l400 = 0; (l400 < 2); l400 = (l400 + 1)) {
			fRec581[l400] = 0.0;
			
		}
		for (int l401 = 0; (l401 < 2); l401 = (l401 + 1)) {
			fRec579[l401] = 0.0;
			
		}
		for (int l402 = 0; (l402 < 2); l402 = (l402 + 1)) {
			fRec578[l402] = 0.0;
			
		}
		for (int l403 = 0; (l403 < 2); l403 = (l403 + 1)) {
			fRec576[l403] = 0.0;
			
		}
		for (int l404 = 0; (l404 < 2); l404 = (l404 + 1)) {
			fRec575[l404] = 0.0;
			
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec573[l405] = 0.0;
			
		}
		for (int l406 = 0; (l406 < 3); l406 = (l406 + 1)) {
			fRec572[l406] = 0.0;
			
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec591[l407] = 0.0;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec589[l408] = 0.0;
			
		}
		for (int l409 = 0; (l409 < 2); l409 = (l409 + 1)) {
			fRec588[l409] = 0.0;
			
		}
		for (int l410 = 0; (l410 < 2); l410 = (l410 + 1)) {
			fRec586[l410] = 0.0;
			
		}
		for (int l411 = 0; (l411 < 2); l411 = (l411 + 1)) {
			fRec585[l411] = 0.0;
			
		}
		for (int l412 = 0; (l412 < 2); l412 = (l412 + 1)) {
			fRec583[l412] = 0.0;
			
		}
		for (int l413 = 0; (l413 < 3); l413 = (l413 + 1)) {
			fRec582[l413] = 0.0;
			
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec598[l414] = 0.0;
			
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec596[l415] = 0.0;
			
		}
		for (int l416 = 0; (l416 < 2); l416 = (l416 + 1)) {
			fRec595[l416] = 0.0;
			
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec593[l417] = 0.0;
			
		}
		for (int l418 = 0; (l418 < 3); l418 = (l418 + 1)) {
			fRec592[l418] = 0.0;
			
		}
		for (int l419 = 0; (l419 < 2); l419 = (l419 + 1)) {
			fRec605[l419] = 0.0;
			
		}
		for (int l420 = 0; (l420 < 2); l420 = (l420 + 1)) {
			fRec603[l420] = 0.0;
			
		}
		for (int l421 = 0; (l421 < 2); l421 = (l421 + 1)) {
			fRec602[l421] = 0.0;
			
		}
		for (int l422 = 0; (l422 < 2); l422 = (l422 + 1)) {
			fRec600[l422] = 0.0;
			
		}
		for (int l423 = 0; (l423 < 3); l423 = (l423 + 1)) {
			fRec599[l423] = 0.0;
			
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec609[l424] = 0.0;
			
		}
		for (int l425 = 0; (l425 < 2); l425 = (l425 + 1)) {
			fRec607[l425] = 0.0;
			
		}
		for (int l426 = 0; (l426 < 3); l426 = (l426 + 1)) {
			fRec606[l426] = 0.0;
			
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
		ui_interface->openVerticalBox("KMHLS_Dome_7h7p_normal_6");
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
			fRec2[0] = (double(input62[i]) - (((fTemp2 * fRec2[2]) + (2.0 * (fTemp3 * fRec2[1]))) / fTemp4));
			fRec3[0] = (fSlow2 + (0.999 * fRec3[1]));
			double fTemp5 = (fRec3[0] * fTemp4);
			double fTemp6 = (0.0 - (2.0 / fTemp4));
			double fTemp7 = (((fTemp1 * (fRec2[2] + (fRec2[0] + (2.0 * fRec2[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec2[1]) + ((fRec2[0] + fRec2[2]) / fTemp4))))));
			fRec4[0] = (double(input60[i]) - (((fTemp2 * fRec4[2]) + (2.0 * (fTemp3 * fRec4[1]))) / fTemp4));
			double fTemp8 = (((fTemp1 * (fRec4[2] + (fRec4[0] + (2.0 * fRec4[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec4[1]) + ((fRec4[0] + fRec4[2]) / fTemp4))))));
			fRec5[0] = (double(input59[i]) - (((fTemp2 * fRec5[2]) + (2.0 * (fTemp3 * fRec5[1]))) / fTemp4));
			double fTemp9 = (((fTemp1 * (fRec5[2] + (fRec5[0] + (2.0 * fRec5[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec5[1]) + ((fRec5[0] + fRec5[2]) / fTemp4))))));
			fRec6[0] = (double(input58[i]) - (((fTemp2 * fRec6[2]) + (2.0 * (fTemp3 * fRec6[1]))) / fTemp4));
			double fTemp10 = (((fTemp1 * (fRec6[2] + (fRec6[0] + (2.0 * fRec6[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec6[1]) + ((fRec6[0] + fRec6[2]) / fTemp4))))));
			fRec7[0] = (double(input57[i]) - (((fTemp2 * fRec7[2]) + (2.0 * (fTemp3 * fRec7[1]))) / fTemp4));
			double fTemp11 = (((fTemp1 * (fRec7[2] + (fRec7[0] + (2.0 * fRec7[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec7[1]) + ((fRec7[0] + fRec7[2]) / fTemp4))))));
			fRec8[0] = (double(input55[i]) - (((fTemp2 * fRec8[2]) + (2.0 * (fTemp3 * fRec8[1]))) / fTemp4));
			double fTemp12 = (((fTemp1 * (fRec8[2] + (fRec8[0] + (2.0 * fRec8[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec8[1]) + ((fRec8[0] + fRec8[2]) / fTemp4))))));
			fRec9[0] = (double(input54[i]) - (((fTemp2 * fRec9[2]) + (2.0 * (fTemp3 * fRec9[1]))) / fTemp4));
			double fTemp13 = (((fTemp1 * (fRec9[2] + (fRec9[0] + (2.0 * fRec9[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec9[1]) + ((fRec9[0] + fRec9[2]) / fTemp4))))));
			fRec10[0] = (double(input53[i]) - (((fTemp2 * fRec10[2]) + (2.0 * (fTemp3 * fRec10[1]))) / fTemp4));
			double fTemp14 = (((fTemp1 * (fRec10[2] + (fRec10[0] + (2.0 * fRec10[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec10[1]) + ((fRec10[0] + fRec10[2]) / fTemp4))))));
			double fTemp15 = (fConst5 * fRec12[1]);
			double fTemp16 = (fConst6 * fRec15[1]);
			double fTemp17 = (fConst8 * fRec18[1]);
			double fTemp18 = (fConst9 * fRec21[1]);
			double fTemp19 = (fConst11 * double(input47[i]));
			double fTemp20 = (fConst12 * fRec24[1]);
			double fTemp21 = (fConst13 * fRec27[1]);
			fRec29[0] = (fTemp19 + (fTemp20 + (fRec29[1] + fTemp21)));
			fRec27[0] = fRec29[0];
			double fRec28 = ((fTemp21 + fTemp20) + fTemp19);
			fRec26[0] = (fRec27[0] + fRec26[1]);
			fRec24[0] = fRec26[0];
			double fRec25 = fRec28;
			fRec23[0] = (fTemp17 + (fTemp18 + (fRec25 + fRec23[1])));
			fRec21[0] = fRec23[0];
			double fRec22 = (fTemp17 + (fRec25 + fTemp18));
			fRec20[0] = (fRec21[0] + fRec20[1]);
			fRec18[0] = fRec20[0];
			double fRec19 = fRec22;
			fRec17[0] = (fTemp15 + (fTemp16 + (fRec19 + fRec17[1])));
			fRec15[0] = fRec17[0];
			double fRec16 = (fTemp15 + (fRec19 + fTemp16));
			fRec14[0] = (fRec15[0] + fRec14[1]);
			fRec12[0] = fRec14[0];
			double fRec13 = fRec16;
			fRec11[0] = (fRec13 - (((fTemp2 * fRec11[2]) + (2.0 * (fTemp3 * fRec11[1]))) / fTemp4));
			double fTemp22 = (((fTemp1 * (fRec11[2] + (fRec11[0] + (2.0 * fRec11[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec11[1]) + ((fRec11[0] + fRec11[2]) / fTemp4))))));
			double fTemp23 = (fConst5 * fRec31[1]);
			double fTemp24 = (fConst6 * fRec34[1]);
			double fTemp25 = (fConst8 * fRec37[1]);
			double fTemp26 = (fConst9 * fRec40[1]);
			double fTemp27 = (fConst11 * double(input45[i]));
			double fTemp28 = (fConst12 * fRec43[1]);
			double fTemp29 = (fConst13 * fRec46[1]);
			fRec48[0] = (fTemp27 + (fTemp28 + (fRec48[1] + fTemp29)));
			fRec46[0] = fRec48[0];
			double fRec47 = ((fTemp29 + fTemp28) + fTemp27);
			fRec45[0] = (fRec46[0] + fRec45[1]);
			fRec43[0] = fRec45[0];
			double fRec44 = fRec47;
			fRec42[0] = (fTemp25 + (fTemp26 + (fRec44 + fRec42[1])));
			fRec40[0] = fRec42[0];
			double fRec41 = (fTemp25 + (fRec44 + fTemp26));
			fRec39[0] = (fRec40[0] + fRec39[1]);
			fRec37[0] = fRec39[0];
			double fRec38 = fRec41;
			fRec36[0] = (fTemp23 + (fTemp24 + (fRec38 + fRec36[1])));
			fRec34[0] = fRec36[0];
			double fRec35 = (fTemp23 + (fRec38 + fTemp24));
			fRec33[0] = (fRec34[0] + fRec33[1]);
			fRec31[0] = fRec33[0];
			double fRec32 = fRec35;
			fRec30[0] = (fRec32 - (((fTemp2 * fRec30[2]) + (2.0 * (fTemp3 * fRec30[1]))) / fTemp4));
			double fTemp30 = (((fTemp1 * (fRec30[2] + (fRec30[0] + (2.0 * fRec30[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec30[1]) + ((fRec30[0] + fRec30[2]) / fTemp4))))));
			double fTemp31 = (fConst5 * fRec50[1]);
			double fTemp32 = (fConst6 * fRec53[1]);
			double fTemp33 = (fConst8 * fRec56[1]);
			double fTemp34 = (fConst9 * fRec59[1]);
			double fTemp35 = (fConst11 * double(input44[i]));
			double fTemp36 = (fConst12 * fRec62[1]);
			double fTemp37 = (fConst13 * fRec65[1]);
			fRec67[0] = (fTemp35 + (fTemp36 + (fRec67[1] + fTemp37)));
			fRec65[0] = fRec67[0];
			double fRec66 = ((fTemp37 + fTemp36) + fTemp35);
			fRec64[0] = (fRec65[0] + fRec64[1]);
			fRec62[0] = fRec64[0];
			double fRec63 = fRec66;
			fRec61[0] = (fTemp33 + (fTemp34 + (fRec63 + fRec61[1])));
			fRec59[0] = fRec61[0];
			double fRec60 = (fTemp33 + (fRec63 + fTemp34));
			fRec58[0] = (fRec59[0] + fRec58[1]);
			fRec56[0] = fRec58[0];
			double fRec57 = fRec60;
			fRec55[0] = (fTemp31 + (fTemp32 + (fRec57 + fRec55[1])));
			fRec53[0] = fRec55[0];
			double fRec54 = (fTemp31 + (fRec57 + fTemp32));
			fRec52[0] = (fRec53[0] + fRec52[1]);
			fRec50[0] = fRec52[0];
			double fRec51 = fRec54;
			fRec49[0] = (fRec51 - (((fTemp2 * fRec49[2]) + (2.0 * (fTemp3 * fRec49[1]))) / fTemp4));
			double fTemp38 = (((fTemp1 * (fRec49[2] + (fRec49[0] + (2.0 * fRec49[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec49[1]) + ((fRec49[0] + fRec49[2]) / fTemp4))))));
			double fTemp39 = (fConst5 * fRec69[1]);
			double fTemp40 = (fConst6 * fRec72[1]);
			double fTemp41 = (fConst8 * fRec75[1]);
			double fTemp42 = (fConst9 * fRec78[1]);
			double fTemp43 = (fConst11 * double(input43[i]));
			double fTemp44 = (fConst12 * fRec81[1]);
			double fTemp45 = (fConst13 * fRec84[1]);
			fRec86[0] = (fTemp43 + (fTemp44 + (fRec86[1] + fTemp45)));
			fRec84[0] = fRec86[0];
			double fRec85 = ((fTemp45 + fTemp44) + fTemp43);
			fRec83[0] = (fRec84[0] + fRec83[1]);
			fRec81[0] = fRec83[0];
			double fRec82 = fRec85;
			fRec80[0] = (fTemp41 + (fTemp42 + (fRec82 + fRec80[1])));
			fRec78[0] = fRec80[0];
			double fRec79 = (fTemp41 + (fRec82 + fTemp42));
			fRec77[0] = (fRec78[0] + fRec77[1]);
			fRec75[0] = fRec77[0];
			double fRec76 = fRec79;
			fRec74[0] = (fTemp39 + (fTemp40 + (fRec76 + fRec74[1])));
			fRec72[0] = fRec74[0];
			double fRec73 = (fTemp39 + (fRec76 + fTemp40));
			fRec71[0] = (fRec72[0] + fRec71[1]);
			fRec69[0] = fRec71[0];
			double fRec70 = fRec73;
			fRec68[0] = (fRec70 - (((fTemp2 * fRec68[2]) + (2.0 * (fTemp3 * fRec68[1]))) / fTemp4));
			double fTemp46 = (((fTemp1 * (fRec68[2] + (fRec68[0] + (2.0 * fRec68[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec68[1]) + ((fRec68[0] + fRec68[2]) / fTemp4))))));
			double fTemp47 = (fConst5 * fRec88[1]);
			double fTemp48 = (fConst6 * fRec91[1]);
			double fTemp49 = (fConst8 * fRec94[1]);
			double fTemp50 = (fConst9 * fRec97[1]);
			double fTemp51 = (fConst11 * double(input42[i]));
			double fTemp52 = (fConst12 * fRec100[1]);
			double fTemp53 = (fConst13 * fRec103[1]);
			fRec105[0] = (fTemp51 + (fTemp52 + (fRec105[1] + fTemp53)));
			fRec103[0] = fRec105[0];
			double fRec104 = ((fTemp53 + fTemp52) + fTemp51);
			fRec102[0] = (fRec103[0] + fRec102[1]);
			fRec100[0] = fRec102[0];
			double fRec101 = fRec104;
			fRec99[0] = (fTemp49 + (fTemp50 + (fRec101 + fRec99[1])));
			fRec97[0] = fRec99[0];
			double fRec98 = (fTemp49 + (fRec101 + fTemp50));
			fRec96[0] = (fRec97[0] + fRec96[1]);
			fRec94[0] = fRec96[0];
			double fRec95 = fRec98;
			fRec93[0] = (fTemp47 + (fTemp48 + (fRec95 + fRec93[1])));
			fRec91[0] = fRec93[0];
			double fRec92 = (fTemp47 + (fRec95 + fTemp48));
			fRec90[0] = (fRec91[0] + fRec90[1]);
			fRec88[0] = fRec90[0];
			double fRec89 = fRec92;
			fRec87[0] = (fRec89 - (((fTemp2 * fRec87[2]) + (2.0 * (fTemp3 * fRec87[1]))) / fTemp4));
			double fTemp54 = (((fTemp1 * (fRec87[2] + (fRec87[0] + (2.0 * fRec87[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec87[1]) + ((fRec87[0] + fRec87[2]) / fTemp4))))));
			double fTemp55 = (fConst5 * fRec107[1]);
			double fTemp56 = (fConst6 * fRec110[1]);
			double fTemp57 = (fConst8 * fRec113[1]);
			double fTemp58 = (fConst9 * fRec116[1]);
			double fTemp59 = (fConst11 * double(input41[i]));
			double fTemp60 = (fConst12 * fRec119[1]);
			double fTemp61 = (fConst13 * fRec122[1]);
			fRec124[0] = (fTemp59 + (fTemp60 + (fRec124[1] + fTemp61)));
			fRec122[0] = fRec124[0];
			double fRec123 = ((fTemp61 + fTemp60) + fTemp59);
			fRec121[0] = (fRec122[0] + fRec121[1]);
			fRec119[0] = fRec121[0];
			double fRec120 = fRec123;
			fRec118[0] = (fTemp57 + (fTemp58 + (fRec120 + fRec118[1])));
			fRec116[0] = fRec118[0];
			double fRec117 = (fTemp57 + (fRec120 + fTemp58));
			fRec115[0] = (fRec116[0] + fRec115[1]);
			fRec113[0] = fRec115[0];
			double fRec114 = fRec117;
			fRec112[0] = (fTemp55 + (fTemp56 + (fRec114 + fRec112[1])));
			fRec110[0] = fRec112[0];
			double fRec111 = (fTemp55 + (fRec114 + fTemp56));
			fRec109[0] = (fRec110[0] + fRec109[1]);
			fRec107[0] = fRec109[0];
			double fRec108 = fRec111;
			fRec106[0] = (fRec108 - (((fTemp2 * fRec106[2]) + (2.0 * (fTemp3 * fRec106[1]))) / fTemp4));
			double fTemp62 = (((fTemp1 * (fRec106[2] + (fRec106[0] + (2.0 * fRec106[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec106[1]) + ((fRec106[0] + fRec106[2]) / fTemp4))))));
			double fTemp63 = (fConst5 * fRec126[1]);
			double fTemp64 = (fConst6 * fRec129[1]);
			double fTemp65 = (fConst8 * fRec132[1]);
			double fTemp66 = (fConst9 * fRec135[1]);
			double fTemp67 = (fConst11 * double(input40[i]));
			double fTemp68 = (fConst12 * fRec138[1]);
			double fTemp69 = (fConst13 * fRec141[1]);
			fRec143[0] = (fTemp67 + (fTemp68 + (fRec143[1] + fTemp69)));
			fRec141[0] = fRec143[0];
			double fRec142 = ((fTemp69 + fTemp68) + fTemp67);
			fRec140[0] = (fRec141[0] + fRec140[1]);
			fRec138[0] = fRec140[0];
			double fRec139 = fRec142;
			fRec137[0] = (fTemp65 + (fTemp66 + (fRec139 + fRec137[1])));
			fRec135[0] = fRec137[0];
			double fRec136 = (fTemp65 + (fRec139 + fTemp66));
			fRec134[0] = (fRec135[0] + fRec134[1]);
			fRec132[0] = fRec134[0];
			double fRec133 = fRec136;
			fRec131[0] = (fTemp63 + (fTemp64 + (fRec133 + fRec131[1])));
			fRec129[0] = fRec131[0];
			double fRec130 = (fTemp63 + (fRec133 + fTemp64));
			fRec128[0] = (fRec129[0] + fRec128[1]);
			fRec126[0] = fRec128[0];
			double fRec127 = fRec130;
			fRec125[0] = (fRec127 - (((fTemp2 * fRec125[2]) + (2.0 * (fTemp3 * fRec125[1]))) / fTemp4));
			double fTemp70 = (((fTemp1 * (fRec125[2] + (fRec125[0] + (2.0 * fRec125[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec125[1]) + ((fRec125[0] + fRec125[2]) / fTemp4))))));
			double fTemp71 = (fConst15 * fRec145[1]);
			double fTemp72 = (fConst17 * fRec148[1]);
			double fTemp73 = (fConst18 * fRec151[1]);
			double fTemp74 = (fConst20 * double(input34[i]));
			double fTemp75 = (fConst21 * fRec154[1]);
			double fTemp76 = (fConst22 * fRec157[1]);
			fRec159[0] = (fTemp74 + (fTemp75 + (fRec159[1] + fTemp76)));
			fRec157[0] = fRec159[0];
			double fRec158 = ((fTemp76 + fTemp75) + fTemp74);
			fRec156[0] = (fRec157[0] + fRec156[1]);
			fRec154[0] = fRec156[0];
			double fRec155 = fRec158;
			fRec153[0] = (fTemp72 + (fTemp73 + (fRec155 + fRec153[1])));
			fRec151[0] = fRec153[0];
			double fRec152 = (fTemp72 + (fRec155 + fTemp73));
			fRec150[0] = (fRec151[0] + fRec150[1]);
			fRec148[0] = fRec150[0];
			double fRec149 = fRec152;
			fRec147[0] = (fTemp71 + (fRec149 + fRec147[1]));
			fRec145[0] = fRec147[0];
			double fRec146 = (fRec149 + fTemp71);
			fRec144[0] = (fRec146 - (((fTemp2 * fRec144[2]) + (2.0 * (fTemp3 * fRec144[1]))) / fTemp4));
			double fTemp77 = (((fTemp1 * (fRec144[2] + (fRec144[0] + (2.0 * fRec144[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec144[1]) + ((fRec144[0] + fRec144[2]) / fTemp4))))));
			double fTemp78 = (fConst15 * fRec161[1]);
			double fTemp79 = (fConst17 * fRec164[1]);
			double fTemp80 = (fConst18 * fRec167[1]);
			double fTemp81 = (fConst20 * double(input31[i]));
			double fTemp82 = (fConst21 * fRec170[1]);
			double fTemp83 = (fConst22 * fRec173[1]);
			fRec175[0] = (fTemp81 + (fTemp82 + (fRec175[1] + fTemp83)));
			fRec173[0] = fRec175[0];
			double fRec174 = ((fTemp83 + fTemp82) + fTemp81);
			fRec172[0] = (fRec173[0] + fRec172[1]);
			fRec170[0] = fRec172[0];
			double fRec171 = fRec174;
			fRec169[0] = (fTemp79 + (fTemp80 + (fRec171 + fRec169[1])));
			fRec167[0] = fRec169[0];
			double fRec168 = (fTemp79 + (fRec171 + fTemp80));
			fRec166[0] = (fRec167[0] + fRec166[1]);
			fRec164[0] = fRec166[0];
			double fRec165 = fRec168;
			fRec163[0] = (fTemp78 + (fRec165 + fRec163[1]));
			fRec161[0] = fRec163[0];
			double fRec162 = (fRec165 + fTemp78);
			fRec160[0] = (fRec162 - (((fTemp2 * fRec160[2]) + (2.0 * (fTemp3 * fRec160[1]))) / fTemp4));
			double fTemp84 = (((fTemp1 * (fRec160[2] + (fRec160[0] + (2.0 * fRec160[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec160[1]) + ((fRec160[0] + fRec160[2]) / fTemp4))))));
			double fTemp85 = (fConst15 * fRec177[1]);
			double fTemp86 = (fConst17 * fRec180[1]);
			double fTemp87 = (fConst18 * fRec183[1]);
			double fTemp88 = (fConst20 * double(input30[i]));
			double fTemp89 = (fConst21 * fRec186[1]);
			double fTemp90 = (fConst22 * fRec189[1]);
			fRec191[0] = (fTemp88 + (fTemp89 + (fRec191[1] + fTemp90)));
			fRec189[0] = fRec191[0];
			double fRec190 = ((fTemp90 + fTemp89) + fTemp88);
			fRec188[0] = (fRec189[0] + fRec188[1]);
			fRec186[0] = fRec188[0];
			double fRec187 = fRec190;
			fRec185[0] = (fTemp86 + (fTemp87 + (fRec187 + fRec185[1])));
			fRec183[0] = fRec185[0];
			double fRec184 = (fTemp86 + (fRec187 + fTemp87));
			fRec182[0] = (fRec183[0] + fRec182[1]);
			fRec180[0] = fRec182[0];
			double fRec181 = fRec184;
			fRec179[0] = (fTemp85 + (fRec181 + fRec179[1]));
			fRec177[0] = fRec179[0];
			double fRec178 = (fRec181 + fTemp85);
			fRec176[0] = (fRec178 - (((fTemp2 * fRec176[2]) + (2.0 * (fTemp3 * fRec176[1]))) / fTemp4));
			double fTemp91 = (((fTemp1 * (fRec176[2] + (fRec176[0] + (2.0 * fRec176[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec176[1]) + ((fRec176[0] + fRec176[2]) / fTemp4))))));
			double fTemp92 = (fConst15 * fRec193[1]);
			double fTemp93 = (fConst17 * fRec196[1]);
			double fTemp94 = (fConst18 * fRec199[1]);
			double fTemp95 = (fConst20 * double(input29[i]));
			double fTemp96 = (fConst21 * fRec202[1]);
			double fTemp97 = (fConst22 * fRec205[1]);
			fRec207[0] = (fTemp95 + (fTemp96 + (fRec207[1] + fTemp97)));
			fRec205[0] = fRec207[0];
			double fRec206 = ((fTemp97 + fTemp96) + fTemp95);
			fRec204[0] = (fRec205[0] + fRec204[1]);
			fRec202[0] = fRec204[0];
			double fRec203 = fRec206;
			fRec201[0] = (fTemp93 + (fTemp94 + (fRec203 + fRec201[1])));
			fRec199[0] = fRec201[0];
			double fRec200 = (fTemp93 + (fRec203 + fTemp94));
			fRec198[0] = (fRec199[0] + fRec198[1]);
			fRec196[0] = fRec198[0];
			double fRec197 = fRec200;
			fRec195[0] = (fTemp92 + (fRec197 + fRec195[1]));
			fRec193[0] = fRec195[0];
			double fRec194 = (fRec197 + fTemp92);
			fRec192[0] = (fRec194 - (((fTemp2 * fRec192[2]) + (2.0 * (fTemp3 * fRec192[1]))) / fTemp4));
			double fTemp98 = (((fTemp1 * (fRec192[2] + (fRec192[0] + (2.0 * fRec192[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec192[1]) + ((fRec192[0] + fRec192[2]) / fTemp4))))));
			double fTemp99 = (fConst24 * fRec209[1]);
			double fTemp100 = (fConst25 * fRec212[1]);
			double fTemp101 = (fConst27 * double(input20[i]));
			double fTemp102 = (fConst28 * fRec215[1]);
			double fTemp103 = (fConst29 * fRec218[1]);
			fRec220[0] = (fTemp101 + (fTemp102 + (fRec220[1] + fTemp103)));
			fRec218[0] = fRec220[0];
			double fRec219 = ((fTemp103 + fTemp102) + fTemp101);
			fRec217[0] = (fRec218[0] + fRec217[1]);
			fRec215[0] = fRec217[0];
			double fRec216 = fRec219;
			fRec214[0] = (fTemp99 + (fTemp100 + (fRec216 + fRec214[1])));
			fRec212[0] = fRec214[0];
			double fRec213 = (fTemp99 + (fRec216 + fTemp100));
			fRec211[0] = (fRec212[0] + fRec211[1]);
			fRec209[0] = fRec211[0];
			double fRec210 = fRec213;
			fRec208[0] = (fRec210 - (((fTemp2 * fRec208[2]) + (2.0 * (fTemp3 * fRec208[1]))) / fTemp4));
			double fTemp104 = (((fTemp1 * (fRec208[2] + (fRec208[0] + (2.0 * fRec208[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec208[1]) + ((fRec208[0] + fRec208[2]) / fTemp4))))));
			double fTemp105 = (fConst31 * double(input8[i]));
			double fTemp106 = (fConst32 * fRec222[1]);
			double fTemp107 = (fConst33 * fRec225[1]);
			fRec227[0] = (fTemp105 + (fTemp106 + (fRec227[1] + fTemp107)));
			fRec225[0] = fRec227[0];
			double fRec226 = ((fTemp107 + fTemp106) + fTemp105);
			fRec224[0] = (fRec225[0] + fRec224[1]);
			fRec222[0] = fRec224[0];
			double fRec223 = fRec226;
			fRec221[0] = (fRec223 - (((fTemp2 * fRec221[2]) + (2.0 * (fTemp3 * fRec221[1]))) / fTemp4));
			double fTemp108 = (((fTemp1 * (fRec221[2] + (fRec221[0] + (2.0 * fRec221[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec221[1]) + ((fRec221[0] + fRec221[2]) / fTemp4))))));
			double fTemp109 = (fConst35 * double(input3[i]));
			double fTemp110 = (fConst36 * fRec229[1]);
			fRec231[0] = (fTemp109 + (fRec231[1] + fTemp110));
			fRec229[0] = fRec231[0];
			double fRec230 = (fTemp110 + fTemp109);
			fRec228[0] = (fRec230 - (((fTemp2 * fRec228[2]) + (2.0 * (fTemp3 * fRec228[1]))) / fTemp4));
			double fTemp111 = (((fTemp1 * (fRec228[2] + (fRec228[0] + (2.0 * fRec228[1])))) / fTemp5) + (0.96028985649999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec228[1]) + ((fRec228[0] + fRec228[2]) / fTemp4))))));
			fRec232[0] = (double(input0[i]) - (((fRec232[2] * fTemp2) + (2.0 * (fRec232[1] * fTemp3))) / fTemp4));
			double fTemp112 = (((fTemp1 * (fRec232[2] + (fRec232[0] + (2.0 * fRec232[1])))) / fTemp5) + (fRec3[0] * (0.0 - ((fRec232[1] * fTemp6) + ((fRec232[0] + fRec232[2]) / fTemp4)))));
			double fTemp113 = (fConst35 * double(input1[i]));
			double fTemp114 = (fConst36 * fRec234[1]);
			fRec236[0] = (fTemp113 + (fRec236[1] + fTemp114));
			fRec234[0] = fRec236[0];
			double fRec235 = (fTemp114 + fTemp113);
			fRec233[0] = (fRec235 - (((fTemp2 * fRec233[2]) + (2.0 * (fTemp3 * fRec233[1]))) / fTemp4));
			double fTemp115 = (((fTemp1 * (fRec233[2] + (fRec233[0] + (2.0 * fRec233[1])))) / fTemp5) + (0.96028985649999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec233[1]) + ((fRec233[0] + fRec233[2]) / fTemp4))))));
			double fTemp116 = (fConst31 * double(input4[i]));
			double fTemp117 = (fConst32 * fRec238[1]);
			double fTemp118 = (fConst33 * fRec241[1]);
			fRec243[0] = (fTemp116 + (fTemp117 + (fRec243[1] + fTemp118)));
			fRec241[0] = fRec243[0];
			double fRec242 = ((fTemp118 + fTemp117) + fTemp116);
			fRec240[0] = (fRec241[0] + fRec240[1]);
			fRec238[0] = fRec240[0];
			double fRec239 = fRec242;
			fRec237[0] = (fRec239 - (((fTemp2 * fRec237[2]) + (2.0 * (fTemp3 * fRec237[1]))) / fTemp4));
			double fTemp119 = (((fTemp1 * (fRec237[2] + (fRec237[0] + (2.0 * fRec237[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec237[1]) + ((fRec237[0] + fRec237[2]) / fTemp4))))));
			double fTemp120 = (fConst38 * fRec245[1]);
			double fTemp121 = (fConst40 * double(input9[i]));
			double fTemp122 = (fConst41 * fRec248[1]);
			double fTemp123 = (fConst42 * fRec251[1]);
			fRec253[0] = (fTemp121 + (fTemp122 + (fRec253[1] + fTemp123)));
			fRec251[0] = fRec253[0];
			double fRec252 = ((fTemp123 + fTemp122) + fTemp121);
			fRec250[0] = (fRec251[0] + fRec250[1]);
			fRec248[0] = fRec250[0];
			double fRec249 = fRec252;
			fRec247[0] = (fTemp120 + (fRec249 + fRec247[1]));
			fRec245[0] = fRec247[0];
			double fRec246 = (fRec249 + fTemp120);
			fRec244[0] = (fRec246 - (((fTemp2 * fRec244[2]) + (2.0 * (fTemp3 * fRec244[1]))) / fTemp4));
			double fTemp124 = (((fTemp1 * (fRec244[2] + (fRec244[0] + (2.0 * fRec244[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec244[1]) + ((fRec244[0] + fRec244[2]) / fTemp4))))));
			double fTemp125 = (fConst24 * fRec255[1]);
			double fTemp126 = (fConst25 * fRec258[1]);
			double fTemp127 = (fConst27 * double(input16[i]));
			double fTemp128 = (fConst28 * fRec261[1]);
			double fTemp129 = (fConst29 * fRec264[1]);
			fRec266[0] = (fTemp127 + (fTemp128 + (fRec266[1] + fTemp129)));
			fRec264[0] = fRec266[0];
			double fRec265 = ((fTemp129 + fTemp128) + fTemp127);
			fRec263[0] = (fRec264[0] + fRec263[1]);
			fRec261[0] = fRec263[0];
			double fRec262 = fRec265;
			fRec260[0] = (fTemp125 + (fTemp126 + (fRec262 + fRec260[1])));
			fRec258[0] = fRec260[0];
			double fRec259 = (fTemp125 + (fRec262 + fTemp126));
			fRec257[0] = (fRec258[0] + fRec257[1]);
			fRec255[0] = fRec257[0];
			double fRec256 = fRec259;
			fRec254[0] = (fRec256 - (((fTemp2 * fRec254[2]) + (2.0 * (fTemp3 * fRec254[1]))) / fTemp4));
			double fTemp130 = (((fTemp1 * (fRec254[2] + (fRec254[0] + (2.0 * fRec254[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec254[1]) + ((fRec254[0] + fRec254[2]) / fTemp4))))));
			double fTemp131 = (fConst17 * fRec271[1]);
			double fTemp132 = (fConst18 * fRec274[1]);
			double fTemp133 = (fConst20 * double(input25[i]));
			double fTemp134 = (fConst21 * fRec277[1]);
			double fTemp135 = (fConst22 * fRec280[1]);
			fRec282[0] = (fTemp133 + (fTemp134 + (fRec282[1] + fTemp135)));
			fRec280[0] = fRec282[0];
			double fRec281 = ((fTemp135 + fTemp134) + fTemp133);
			fRec279[0] = (fRec280[0] + fRec279[1]);
			fRec277[0] = fRec279[0];
			double fRec278 = fRec281;
			fRec276[0] = (fTemp131 + (fTemp132 + (fRec278 + fRec276[1])));
			fRec274[0] = fRec276[0];
			double fRec275 = (fTemp131 + (fRec278 + fTemp132));
			fRec273[0] = (fRec274[0] + fRec273[1]);
			fRec271[0] = fRec273[0];
			double fRec272 = fRec275;
			double fTemp136 = (fRec272 + (fConst15 * fRec268[1]));
			fRec270[0] = (fRec270[1] + fTemp136);
			fRec268[0] = fRec270[0];
			double fRec269 = fTemp136;
			fRec267[0] = (fRec269 - (((fTemp2 * fRec267[2]) + (2.0 * (fTemp3 * fRec267[1]))) / fTemp4));
			double fTemp137 = (((fTemp1 * (fRec267[2] + (fRec267[0] + (2.0 * fRec267[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec267[1]) + ((fRec267[0] + fRec267[2]) / fTemp4))))));
			double fTemp138 = (fConst5 * fRec284[1]);
			double fTemp139 = (fConst6 * fRec287[1]);
			double fTemp140 = (fConst8 * fRec290[1]);
			double fTemp141 = (fConst9 * fRec293[1]);
			double fTemp142 = (fConst11 * double(input38[i]));
			double fTemp143 = (fConst12 * fRec296[1]);
			double fTemp144 = (fConst13 * fRec299[1]);
			fRec301[0] = (fTemp142 + (fTemp143 + (fRec301[1] + fTemp144)));
			fRec299[0] = fRec301[0];
			double fRec300 = ((fTemp144 + fTemp143) + fTemp142);
			fRec298[0] = (fRec299[0] + fRec298[1]);
			fRec296[0] = fRec298[0];
			double fRec297 = fRec300;
			fRec295[0] = (fTemp140 + (fTemp141 + (fRec297 + fRec295[1])));
			fRec293[0] = fRec295[0];
			double fRec294 = (fTemp140 + (fRec297 + fTemp141));
			fRec292[0] = (fRec293[0] + fRec292[1]);
			fRec290[0] = fRec292[0];
			double fRec291 = fRec294;
			fRec289[0] = (fTemp138 + (fTemp139 + (fRec291 + fRec289[1])));
			fRec287[0] = fRec289[0];
			double fRec288 = (fTemp138 + (fRec291 + fTemp139));
			fRec286[0] = (fRec287[0] + fRec286[1]);
			fRec284[0] = fRec286[0];
			double fRec285 = fRec288;
			fRec283[0] = (fRec285 - (((fTemp2 * fRec283[2]) + (2.0 * (fTemp3 * fRec283[1]))) / fTemp4));
			double fTemp145 = (((fTemp1 * (fRec283[2] + (fRec283[0] + (2.0 * fRec283[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec283[1]) + ((fRec283[0] + fRec283[2]) / fTemp4))))));
			fRec302[0] = (double(input51[i]) - (((fTemp2 * fRec302[2]) + (2.0 * (fTemp3 * fRec302[1]))) / fTemp4));
			double fTemp146 = (((fTemp1 * (fRec302[2] + (fRec302[0] + (2.0 * fRec302[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec302[1]) + ((fRec302[0] + fRec302[2]) / fTemp4))))));
			fRec303[0] = (double(input63[i]) - (((fTemp2 * fRec303[2]) + (2.0 * (fTemp3 * fRec303[1]))) / fTemp4));
			double fTemp147 = (((fTemp1 * (fRec303[2] + (fRec303[0] + (2.0 * fRec303[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec303[1]) + ((fRec303[0] + fRec303[2]) / fTemp4))))));
			fRec304[0] = (double(input61[i]) - (((fTemp2 * fRec304[2]) + (2.0 * (fTemp3 * fRec304[1]))) / fTemp4));
			double fTemp148 = (((fTemp1 * (fRec304[2] + (fRec304[0] + (2.0 * fRec304[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec304[1]) + ((fRec304[0] + fRec304[2]) / fTemp4))))));
			fRec305[0] = (double(input56[i]) - (((fTemp2 * fRec305[2]) + (2.0 * (fTemp3 * fRec305[1]))) / fTemp4));
			double fTemp149 = (((fTemp1 * (fRec305[2] + (fRec305[0] + (2.0 * fRec305[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec305[1]) + ((fRec305[0] + fRec305[2]) / fTemp4))))));
			fRec306[0] = (double(input52[i]) - (((fTemp2 * fRec306[2]) + (2.0 * (fTemp3 * fRec306[1]))) / fTemp4));
			double fTemp150 = (((fTemp1 * (fRec306[2] + (fRec306[0] + (2.0 * fRec306[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec306[1]) + ((fRec306[0] + fRec306[2]) / fTemp4))))));
			fRec307[0] = (double(input50[i]) - (((fTemp2 * fRec307[2]) + (2.0 * (fTemp3 * fRec307[1]))) / fTemp4));
			double fTemp151 = (((fTemp1 * (fRec307[2] + (fRec307[0] + (2.0 * fRec307[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec307[1]) + ((fRec307[0] + fRec307[2]) / fTemp4))))));
			double fTemp152 = (fConst5 * fRec309[1]);
			double fTemp153 = (fConst6 * fRec312[1]);
			double fTemp154 = (fConst8 * fRec315[1]);
			double fTemp155 = (fConst9 * fRec318[1]);
			double fTemp156 = (fConst11 * double(input48[i]));
			double fTemp157 = (fConst12 * fRec321[1]);
			double fTemp158 = (fConst13 * fRec324[1]);
			fRec326[0] = (fTemp156 + (fTemp157 + (fRec326[1] + fTemp158)));
			fRec324[0] = fRec326[0];
			double fRec325 = ((fTemp158 + fTemp157) + fTemp156);
			fRec323[0] = (fRec324[0] + fRec323[1]);
			fRec321[0] = fRec323[0];
			double fRec322 = fRec325;
			fRec320[0] = (fTemp154 + (fTemp155 + (fRec322 + fRec320[1])));
			fRec318[0] = fRec320[0];
			double fRec319 = (fTemp154 + (fRec322 + fTemp155));
			fRec317[0] = (fRec318[0] + fRec317[1]);
			fRec315[0] = fRec317[0];
			double fRec316 = fRec319;
			fRec314[0] = (fTemp152 + (fTemp153 + (fRec316 + fRec314[1])));
			fRec312[0] = fRec314[0];
			double fRec313 = (fTemp152 + (fRec316 + fTemp153));
			fRec311[0] = (fRec312[0] + fRec311[1]);
			fRec309[0] = fRec311[0];
			double fRec310 = fRec313;
			fRec308[0] = (fRec310 - (((fTemp2 * fRec308[2]) + (2.0 * (fTemp3 * fRec308[1]))) / fTemp4));
			double fTemp159 = (((fTemp1 * (fRec308[2] + (fRec308[0] + (2.0 * fRec308[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec308[1]) + ((fRec308[0] + fRec308[2]) / fTemp4))))));
			double fTemp160 = (fConst5 * fRec328[1]);
			double fTemp161 = (fConst6 * fRec331[1]);
			double fTemp162 = (fConst8 * fRec334[1]);
			double fTemp163 = (fConst9 * fRec337[1]);
			double fTemp164 = (fConst11 * double(input46[i]));
			double fTemp165 = (fConst12 * fRec340[1]);
			double fTemp166 = (fConst13 * fRec343[1]);
			fRec345[0] = (fTemp164 + (fTemp165 + (fRec345[1] + fTemp166)));
			fRec343[0] = fRec345[0];
			double fRec344 = ((fTemp166 + fTemp165) + fTemp164);
			fRec342[0] = (fRec343[0] + fRec342[1]);
			fRec340[0] = fRec342[0];
			double fRec341 = fRec344;
			fRec339[0] = (fTemp162 + (fTemp163 + (fRec341 + fRec339[1])));
			fRec337[0] = fRec339[0];
			double fRec338 = (fTemp162 + (fRec341 + fTemp163));
			fRec336[0] = (fRec337[0] + fRec336[1]);
			fRec334[0] = fRec336[0];
			double fRec335 = fRec338;
			fRec333[0] = (fTemp160 + (fTemp161 + (fRec335 + fRec333[1])));
			fRec331[0] = fRec333[0];
			double fRec332 = (fTemp160 + (fRec335 + fTemp161));
			fRec330[0] = (fRec331[0] + fRec330[1]);
			fRec328[0] = fRec330[0];
			double fRec329 = fRec332;
			fRec327[0] = (fRec329 - (((fTemp2 * fRec327[2]) + (2.0 * (fTemp3 * fRec327[1]))) / fTemp4));
			double fTemp167 = (((fTemp1 * (fRec327[2] + (fRec327[0] + (2.0 * fRec327[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec327[1]) + ((fRec327[0] + fRec327[2]) / fTemp4))))));
			double fTemp168 = (fConst5 * fRec347[1]);
			double fTemp169 = (fConst6 * fRec350[1]);
			double fTemp170 = (fConst8 * fRec353[1]);
			double fTemp171 = (fConst9 * fRec356[1]);
			double fTemp172 = (fConst11 * double(input39[i]));
			double fTemp173 = (fConst12 * fRec359[1]);
			double fTemp174 = (fConst13 * fRec362[1]);
			fRec364[0] = (fTemp172 + (fTemp173 + (fRec364[1] + fTemp174)));
			fRec362[0] = fRec364[0];
			double fRec363 = ((fTemp174 + fTemp173) + fTemp172);
			fRec361[0] = (fRec362[0] + fRec361[1]);
			fRec359[0] = fRec361[0];
			double fRec360 = fRec363;
			fRec358[0] = (fTemp170 + (fTemp171 + (fRec360 + fRec358[1])));
			fRec356[0] = fRec358[0];
			double fRec357 = (fTemp170 + (fRec360 + fTemp171));
			fRec355[0] = (fRec356[0] + fRec355[1]);
			fRec353[0] = fRec355[0];
			double fRec354 = fRec357;
			fRec352[0] = (fTemp168 + (fTemp169 + (fRec354 + fRec352[1])));
			fRec350[0] = fRec352[0];
			double fRec351 = (fTemp168 + (fRec354 + fTemp169));
			fRec349[0] = (fRec350[0] + fRec349[1]);
			fRec347[0] = fRec349[0];
			double fRec348 = fRec351;
			fRec346[0] = (fRec348 - (((fTemp2 * fRec346[2]) + (2.0 * (fTemp3 * fRec346[1]))) / fTemp4));
			double fTemp175 = (((fTemp1 * (fRec346[2] + (fRec346[0] + (2.0 * fRec346[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec346[1]) + ((fRec346[0] + fRec346[2]) / fTemp4))))));
			double fTemp176 = (fConst5 * fRec366[1]);
			double fTemp177 = (fConst6 * fRec369[1]);
			double fTemp178 = (fConst8 * fRec372[1]);
			double fTemp179 = (fConst9 * fRec375[1]);
			double fTemp180 = (fConst11 * double(input37[i]));
			double fTemp181 = (fConst12 * fRec378[1]);
			double fTemp182 = (fConst13 * fRec381[1]);
			fRec383[0] = (fTemp180 + (fTemp181 + (fRec383[1] + fTemp182)));
			fRec381[0] = fRec383[0];
			double fRec382 = ((fTemp182 + fTemp181) + fTemp180);
			fRec380[0] = (fRec381[0] + fRec380[1]);
			fRec378[0] = fRec380[0];
			double fRec379 = fRec382;
			fRec377[0] = (fTemp178 + (fTemp179 + (fRec379 + fRec377[1])));
			fRec375[0] = fRec377[0];
			double fRec376 = (fTemp178 + (fRec379 + fTemp179));
			fRec374[0] = (fRec375[0] + fRec374[1]);
			fRec372[0] = fRec374[0];
			double fRec373 = fRec376;
			fRec371[0] = (fTemp176 + (fTemp177 + (fRec373 + fRec371[1])));
			fRec369[0] = fRec371[0];
			double fRec370 = (fTemp176 + (fRec373 + fTemp177));
			fRec368[0] = (fRec369[0] + fRec368[1]);
			fRec366[0] = fRec368[0];
			double fRec367 = fRec370;
			fRec365[0] = (fRec367 - (((fTemp2 * fRec365[2]) + (2.0 * (fTemp3 * fRec365[1]))) / fTemp4));
			double fTemp183 = (((fTemp1 * (fRec365[2] + (fRec365[0] + (2.0 * fRec365[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec365[1]) + ((fRec365[0] + fRec365[2]) / fTemp4))))));
			double fTemp184 = (fConst15 * fRec385[1]);
			double fTemp185 = (fConst17 * fRec388[1]);
			double fTemp186 = (fConst18 * fRec391[1]);
			double fTemp187 = (fConst20 * double(input35[i]));
			double fTemp188 = (fConst21 * fRec394[1]);
			double fTemp189 = (fConst22 * fRec397[1]);
			fRec399[0] = (fTemp187 + (fTemp188 + (fRec399[1] + fTemp189)));
			fRec397[0] = fRec399[0];
			double fRec398 = ((fTemp189 + fTemp188) + fTemp187);
			fRec396[0] = (fRec397[0] + fRec396[1]);
			fRec394[0] = fRec396[0];
			double fRec395 = fRec398;
			fRec393[0] = (fTemp185 + (fTemp186 + (fRec395 + fRec393[1])));
			fRec391[0] = fRec393[0];
			double fRec392 = (fTemp185 + (fRec395 + fTemp186));
			fRec390[0] = (fRec391[0] + fRec390[1]);
			fRec388[0] = fRec390[0];
			double fRec389 = fRec392;
			fRec387[0] = (fTemp184 + (fRec389 + fRec387[1]));
			fRec385[0] = fRec387[0];
			double fRec386 = (fRec389 + fTemp184);
			fRec384[0] = (fRec386 - (((fTemp2 * fRec384[2]) + (2.0 * (fTemp3 * fRec384[1]))) / fTemp4));
			double fTemp190 = (((fTemp1 * (fRec384[2] + (fRec384[0] + (2.0 * fRec384[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec384[1]) + ((fRec384[0] + fRec384[2]) / fTemp4))))));
			double fTemp191 = (fConst15 * fRec401[1]);
			double fTemp192 = (fConst17 * fRec404[1]);
			double fTemp193 = (fConst18 * fRec407[1]);
			double fTemp194 = (fConst20 * double(input33[i]));
			double fTemp195 = (fConst21 * fRec410[1]);
			double fTemp196 = (fConst22 * fRec413[1]);
			fRec415[0] = (fTemp194 + (fTemp195 + (fRec415[1] + fTemp196)));
			fRec413[0] = fRec415[0];
			double fRec414 = ((fTemp196 + fTemp195) + fTemp194);
			fRec412[0] = (fRec413[0] + fRec412[1]);
			fRec410[0] = fRec412[0];
			double fRec411 = fRec414;
			fRec409[0] = (fTemp192 + (fTemp193 + (fRec411 + fRec409[1])));
			fRec407[0] = fRec409[0];
			double fRec408 = (fTemp192 + (fRec411 + fTemp193));
			fRec406[0] = (fRec407[0] + fRec406[1]);
			fRec404[0] = fRec406[0];
			double fRec405 = fRec408;
			fRec403[0] = (fTemp191 + (fRec405 + fRec403[1]));
			fRec401[0] = fRec403[0];
			double fRec402 = (fRec405 + fTemp191);
			fRec400[0] = (fRec402 - (((fTemp2 * fRec400[2]) + (2.0 * (fTemp3 * fRec400[1]))) / fTemp4));
			double fTemp197 = (((fTemp1 * (fRec400[2] + (fRec400[0] + (2.0 * fRec400[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec400[1]) + ((fRec400[0] + fRec400[2]) / fTemp4))))));
			double fTemp198 = (fConst15 * fRec417[1]);
			double fTemp199 = (fConst17 * fRec420[1]);
			double fTemp200 = (fConst18 * fRec423[1]);
			double fTemp201 = (fConst20 * double(input32[i]));
			double fTemp202 = (fConst21 * fRec426[1]);
			double fTemp203 = (fConst22 * fRec429[1]);
			fRec431[0] = (fTemp201 + (fTemp202 + (fRec431[1] + fTemp203)));
			fRec429[0] = fRec431[0];
			double fRec430 = ((fTemp203 + fTemp202) + fTemp201);
			fRec428[0] = (fRec429[0] + fRec428[1]);
			fRec426[0] = fRec428[0];
			double fRec427 = fRec430;
			fRec425[0] = (fTemp199 + (fTemp200 + (fRec427 + fRec425[1])));
			fRec423[0] = fRec425[0];
			double fRec424 = (fTemp199 + (fRec427 + fTemp200));
			fRec422[0] = (fRec423[0] + fRec422[1]);
			fRec420[0] = fRec422[0];
			double fRec421 = fRec424;
			fRec419[0] = (fTemp198 + (fRec421 + fRec419[1]));
			fRec417[0] = fRec419[0];
			double fRec418 = (fRec421 + fTemp198);
			fRec416[0] = (fRec418 - (((fTemp2 * fRec416[2]) + (2.0 * (fTemp3 * fRec416[1]))) / fTemp4));
			double fTemp204 = (((fTemp1 * (fRec416[2] + (fRec416[0] + (2.0 * fRec416[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec416[1]) + ((fRec416[0] + fRec416[2]) / fTemp4))))));
			double fTemp205 = (fConst15 * fRec433[1]);
			double fTemp206 = (fConst17 * fRec436[1]);
			double fTemp207 = (fConst18 * fRec439[1]);
			double fTemp208 = (fConst20 * double(input28[i]));
			double fTemp209 = (fConst21 * fRec442[1]);
			double fTemp210 = (fConst22 * fRec445[1]);
			fRec447[0] = (fTemp208 + (fTemp209 + (fRec447[1] + fTemp210)));
			fRec445[0] = fRec447[0];
			double fRec446 = ((fTemp210 + fTemp209) + fTemp208);
			fRec444[0] = (fRec445[0] + fRec444[1]);
			fRec442[0] = fRec444[0];
			double fRec443 = fRec446;
			fRec441[0] = (fTemp206 + (fTemp207 + (fRec443 + fRec441[1])));
			fRec439[0] = fRec441[0];
			double fRec440 = (fTemp206 + (fRec443 + fTemp207));
			fRec438[0] = (fRec439[0] + fRec438[1]);
			fRec436[0] = fRec438[0];
			double fRec437 = fRec440;
			fRec435[0] = (fTemp205 + (fRec437 + fRec435[1]));
			fRec433[0] = fRec435[0];
			double fRec434 = (fRec437 + fTemp205);
			fRec432[0] = (fRec434 - (((fTemp2 * fRec432[2]) + (2.0 * (fTemp3 * fRec432[1]))) / fTemp4));
			double fTemp211 = (((fTemp1 * (fRec432[2] + (fRec432[0] + (2.0 * fRec432[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec432[1]) + ((fRec432[0] + fRec432[2]) / fTemp4))))));
			double fTemp212 = (fConst15 * fRec449[1]);
			double fTemp213 = (fConst17 * fRec452[1]);
			double fTemp214 = (fConst18 * fRec455[1]);
			double fTemp215 = (fConst20 * double(input27[i]));
			double fTemp216 = (fConst21 * fRec458[1]);
			double fTemp217 = (fConst22 * fRec461[1]);
			fRec463[0] = (fTemp215 + (fTemp216 + (fRec463[1] + fTemp217)));
			fRec461[0] = fRec463[0];
			double fRec462 = ((fTemp217 + fTemp216) + fTemp215);
			fRec460[0] = (fRec461[0] + fRec460[1]);
			fRec458[0] = fRec460[0];
			double fRec459 = fRec462;
			fRec457[0] = (fTemp213 + (fTemp214 + (fRec459 + fRec457[1])));
			fRec455[0] = fRec457[0];
			double fRec456 = (fTemp213 + (fRec459 + fTemp214));
			fRec454[0] = (fRec455[0] + fRec454[1]);
			fRec452[0] = fRec454[0];
			double fRec453 = fRec456;
			fRec451[0] = (fTemp212 + (fRec453 + fRec451[1]));
			fRec449[0] = fRec451[0];
			double fRec450 = (fRec453 + fTemp212);
			fRec448[0] = (fRec450 - (((fTemp2 * fRec448[2]) + (2.0 * (fTemp3 * fRec448[1]))) / fTemp4));
			double fTemp218 = (((fTemp1 * (fRec448[2] + (fRec448[0] + (2.0 * fRec448[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec448[1]) + ((fRec448[0] + fRec448[2]) / fTemp4))))));
			double fTemp219 = (fConst24 * fRec465[1]);
			double fTemp220 = (fConst25 * fRec468[1]);
			double fTemp221 = (fConst27 * double(input24[i]));
			double fTemp222 = (fConst28 * fRec471[1]);
			double fTemp223 = (fConst29 * fRec474[1]);
			fRec476[0] = (fTemp221 + (fTemp222 + (fRec476[1] + fTemp223)));
			fRec474[0] = fRec476[0];
			double fRec475 = ((fTemp223 + fTemp222) + fTemp221);
			fRec473[0] = (fRec474[0] + fRec473[1]);
			fRec471[0] = fRec473[0];
			double fRec472 = fRec475;
			fRec470[0] = (fTemp219 + (fTemp220 + (fRec472 + fRec470[1])));
			fRec468[0] = fRec470[0];
			double fRec469 = (fTemp219 + (fRec472 + fTemp220));
			fRec467[0] = (fRec468[0] + fRec467[1]);
			fRec465[0] = fRec467[0];
			double fRec466 = fRec469;
			fRec464[0] = (fRec466 - (((fTemp2 * fRec464[2]) + (2.0 * (fTemp3 * fRec464[1]))) / fTemp4));
			double fTemp224 = (((fTemp1 * (fRec464[2] + (fRec464[0] + (2.0 * fRec464[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec464[1]) + ((fRec464[0] + fRec464[2]) / fTemp4))))));
			double fTemp225 = (fConst24 * fRec478[1]);
			double fTemp226 = (fConst25 * fRec481[1]);
			double fTemp227 = (fConst27 * double(input23[i]));
			double fTemp228 = (fConst28 * fRec484[1]);
			double fTemp229 = (fConst29 * fRec487[1]);
			fRec489[0] = (fTemp227 + (fTemp228 + (fRec489[1] + fTemp229)));
			fRec487[0] = fRec489[0];
			double fRec488 = ((fTemp229 + fTemp228) + fTemp227);
			fRec486[0] = (fRec487[0] + fRec486[1]);
			fRec484[0] = fRec486[0];
			double fRec485 = fRec488;
			fRec483[0] = (fTemp225 + (fTemp226 + (fRec485 + fRec483[1])));
			fRec481[0] = fRec483[0];
			double fRec482 = (fTemp225 + (fRec485 + fTemp226));
			fRec480[0] = (fRec481[0] + fRec480[1]);
			fRec478[0] = fRec480[0];
			double fRec479 = fRec482;
			fRec477[0] = (fRec479 - (((fTemp2 * fRec477[2]) + (2.0 * (fTemp3 * fRec477[1]))) / fTemp4));
			double fTemp230 = (((fTemp1 * (fRec477[2] + (fRec477[0] + (2.0 * fRec477[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec477[1]) + ((fRec477[0] + fRec477[2]) / fTemp4))))));
			double fTemp231 = (fConst24 * fRec491[1]);
			double fTemp232 = (fConst25 * fRec494[1]);
			double fTemp233 = (fConst27 * double(input22[i]));
			double fTemp234 = (fConst28 * fRec497[1]);
			double fTemp235 = (fConst29 * fRec500[1]);
			fRec502[0] = (fTemp233 + (fTemp234 + (fRec502[1] + fTemp235)));
			fRec500[0] = fRec502[0];
			double fRec501 = ((fTemp235 + fTemp234) + fTemp233);
			fRec499[0] = (fRec500[0] + fRec499[1]);
			fRec497[0] = fRec499[0];
			double fRec498 = fRec501;
			fRec496[0] = (fTemp231 + (fTemp232 + (fRec498 + fRec496[1])));
			fRec494[0] = fRec496[0];
			double fRec495 = (fTemp231 + (fRec498 + fTemp232));
			fRec493[0] = (fRec494[0] + fRec493[1]);
			fRec491[0] = fRec493[0];
			double fRec492 = fRec495;
			fRec490[0] = (fRec492 - (((fTemp2 * fRec490[2]) + (2.0 * (fTemp3 * fRec490[1]))) / fTemp4));
			double fTemp236 = (((fTemp1 * (fRec490[2] + (fRec490[0] + (2.0 * fRec490[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec490[1]) + ((fRec490[0] + fRec490[2]) / fTemp4))))));
			double fTemp237 = (fConst24 * fRec504[1]);
			double fTemp238 = (fConst25 * fRec507[1]);
			double fTemp239 = (fConst27 * double(input21[i]));
			double fTemp240 = (fConst28 * fRec510[1]);
			double fTemp241 = (fConst29 * fRec513[1]);
			fRec515[0] = (fTemp239 + (fTemp240 + (fRec515[1] + fTemp241)));
			fRec513[0] = fRec515[0];
			double fRec514 = ((fTemp241 + fTemp240) + fTemp239);
			fRec512[0] = (fRec513[0] + fRec512[1]);
			fRec510[0] = fRec512[0];
			double fRec511 = fRec514;
			fRec509[0] = (fTemp237 + (fTemp238 + (fRec511 + fRec509[1])));
			fRec507[0] = fRec509[0];
			double fRec508 = (fTemp237 + (fRec511 + fTemp238));
			fRec506[0] = (fRec507[0] + fRec506[1]);
			fRec504[0] = fRec506[0];
			double fRec505 = fRec508;
			fRec503[0] = (fRec505 - (((fTemp2 * fRec503[2]) + (2.0 * (fTemp3 * fRec503[1]))) / fTemp4));
			double fTemp242 = (((fTemp1 * (fRec503[2] + (fRec503[0] + (2.0 * fRec503[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec503[1]) + ((fRec503[0] + fRec503[2]) / fTemp4))))));
			double fTemp243 = (fConst24 * fRec517[1]);
			double fTemp244 = (fConst25 * fRec520[1]);
			double fTemp245 = (fConst27 * double(input19[i]));
			double fTemp246 = (fConst28 * fRec523[1]);
			double fTemp247 = (fConst29 * fRec526[1]);
			fRec528[0] = (fTemp245 + (fTemp246 + (fRec528[1] + fTemp247)));
			fRec526[0] = fRec528[0];
			double fRec527 = ((fTemp247 + fTemp246) + fTemp245);
			fRec525[0] = (fRec526[0] + fRec525[1]);
			fRec523[0] = fRec525[0];
			double fRec524 = fRec527;
			fRec522[0] = (fTemp243 + (fTemp244 + (fRec524 + fRec522[1])));
			fRec520[0] = fRec522[0];
			double fRec521 = (fTemp243 + (fRec524 + fTemp244));
			fRec519[0] = (fRec520[0] + fRec519[1]);
			fRec517[0] = fRec519[0];
			double fRec518 = fRec521;
			fRec516[0] = (fRec518 - (((fTemp2 * fRec516[2]) + (2.0 * (fTemp3 * fRec516[1]))) / fTemp4));
			double fTemp248 = (((fTemp1 * (fRec516[2] + (fRec516[0] + (2.0 * fRec516[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec516[1]) + ((fRec516[0] + fRec516[2]) / fTemp4))))));
			double fTemp249 = (fConst24 * fRec530[1]);
			double fTemp250 = (fConst25 * fRec533[1]);
			double fTemp251 = (fConst27 * double(input18[i]));
			double fTemp252 = (fConst28 * fRec536[1]);
			double fTemp253 = (fConst29 * fRec539[1]);
			fRec541[0] = (fTemp251 + (fTemp252 + (fRec541[1] + fTemp253)));
			fRec539[0] = fRec541[0];
			double fRec540 = ((fTemp253 + fTemp252) + fTemp251);
			fRec538[0] = (fRec539[0] + fRec538[1]);
			fRec536[0] = fRec538[0];
			double fRec537 = fRec540;
			fRec535[0] = (fTemp249 + (fTemp250 + (fRec537 + fRec535[1])));
			fRec533[0] = fRec535[0];
			double fRec534 = (fTemp249 + (fRec537 + fTemp250));
			fRec532[0] = (fRec533[0] + fRec532[1]);
			fRec530[0] = fRec532[0];
			double fRec531 = fRec534;
			fRec529[0] = (fRec531 - (((fTemp2 * fRec529[2]) + (2.0 * (fTemp3 * fRec529[1]))) / fTemp4));
			double fTemp254 = (((fTemp1 * (fRec529[2] + (fRec529[0] + (2.0 * fRec529[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec529[1]) + ((fRec529[0] + fRec529[2]) / fTemp4))))));
			double fTemp255 = (fConst38 * fRec543[1]);
			double fTemp256 = (fConst40 * double(input15[i]));
			double fTemp257 = (fConst41 * fRec546[1]);
			double fTemp258 = (fConst42 * fRec549[1]);
			fRec551[0] = (fTemp256 + (fTemp257 + (fRec551[1] + fTemp258)));
			fRec549[0] = fRec551[0];
			double fRec550 = ((fTemp258 + fTemp257) + fTemp256);
			fRec548[0] = (fRec549[0] + fRec548[1]);
			fRec546[0] = fRec548[0];
			double fRec547 = fRec550;
			fRec545[0] = (fTemp255 + (fRec547 + fRec545[1]));
			fRec543[0] = fRec545[0];
			double fRec544 = (fRec547 + fTemp255);
			fRec542[0] = (fRec544 - (((fTemp2 * fRec542[2]) + (2.0 * (fTemp3 * fRec542[1]))) / fTemp4));
			double fTemp259 = (((fTemp1 * (fRec542[2] + (fRec542[0] + (2.0 * fRec542[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec542[1]) + ((fRec542[0] + fRec542[2]) / fTemp4))))));
			double fTemp260 = (fConst38 * fRec553[1]);
			double fTemp261 = (fConst40 * double(input14[i]));
			double fTemp262 = (fConst41 * fRec556[1]);
			double fTemp263 = (fConst42 * fRec559[1]);
			fRec561[0] = (fTemp261 + (fTemp262 + (fRec561[1] + fTemp263)));
			fRec559[0] = fRec561[0];
			double fRec560 = ((fTemp263 + fTemp262) + fTemp261);
			fRec558[0] = (fRec559[0] + fRec558[1]);
			fRec556[0] = fRec558[0];
			double fRec557 = fRec560;
			fRec555[0] = (fTemp260 + (fRec557 + fRec555[1]));
			fRec553[0] = fRec555[0];
			double fRec554 = (fRec557 + fTemp260);
			fRec552[0] = (fRec554 - (((fTemp2 * fRec552[2]) + (2.0 * (fTemp3 * fRec552[1]))) / fTemp4));
			double fTemp264 = (((fTemp1 * (fRec552[2] + (fRec552[0] + (2.0 * fRec552[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec552[1]) + ((fRec552[0] + fRec552[2]) / fTemp4))))));
			double fTemp265 = (fConst38 * fRec563[1]);
			double fTemp266 = (fConst40 * double(input13[i]));
			double fTemp267 = (fConst41 * fRec566[1]);
			double fTemp268 = (fConst42 * fRec569[1]);
			fRec571[0] = (fTemp266 + (fTemp267 + (fRec571[1] + fTemp268)));
			fRec569[0] = fRec571[0];
			double fRec570 = ((fTemp268 + fTemp267) + fTemp266);
			fRec568[0] = (fRec569[0] + fRec568[1]);
			fRec566[0] = fRec568[0];
			double fRec567 = fRec570;
			fRec565[0] = (fTemp265 + (fRec567 + fRec565[1]));
			fRec563[0] = fRec565[0];
			double fRec564 = (fRec567 + fTemp265);
			fRec562[0] = (fRec564 - (((fTemp2 * fRec562[2]) + (2.0 * (fTemp3 * fRec562[1]))) / fTemp4));
			double fTemp269 = (((fTemp1 * (fRec562[2] + (fRec562[0] + (2.0 * fRec562[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec562[1]) + ((fRec562[0] + fRec562[2]) / fTemp4))))));
			double fTemp270 = (fConst38 * fRec573[1]);
			double fTemp271 = (fConst40 * double(input12[i]));
			double fTemp272 = (fConst41 * fRec576[1]);
			double fTemp273 = (fConst42 * fRec579[1]);
			fRec581[0] = (fTemp271 + (fTemp272 + (fRec581[1] + fTemp273)));
			fRec579[0] = fRec581[0];
			double fRec580 = ((fTemp273 + fTemp272) + fTemp271);
			fRec578[0] = (fRec579[0] + fRec578[1]);
			fRec576[0] = fRec578[0];
			double fRec577 = fRec580;
			fRec575[0] = (fTemp270 + (fRec577 + fRec575[1]));
			fRec573[0] = fRec575[0];
			double fRec574 = (fRec577 + fTemp270);
			fRec572[0] = (fRec574 - (((fTemp2 * fRec572[2]) + (2.0 * (fTemp3 * fRec572[1]))) / fTemp4));
			double fTemp274 = (((fTemp1 * (fRec572[2] + (fRec572[0] + (2.0 * fRec572[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec572[1]) + ((fRec572[0] + fRec572[2]) / fTemp4))))));
			double fTemp275 = (fConst38 * fRec583[1]);
			double fTemp276 = (fConst40 * double(input11[i]));
			double fTemp277 = (fConst41 * fRec586[1]);
			double fTemp278 = (fConst42 * fRec589[1]);
			fRec591[0] = (fTemp276 + (fTemp277 + (fRec591[1] + fTemp278)));
			fRec589[0] = fRec591[0];
			double fRec590 = ((fTemp278 + fTemp277) + fTemp276);
			fRec588[0] = (fRec589[0] + fRec588[1]);
			fRec586[0] = fRec588[0];
			double fRec587 = fRec590;
			fRec585[0] = (fTemp275 + (fRec587 + fRec585[1]));
			fRec583[0] = fRec585[0];
			double fRec584 = (fRec587 + fTemp275);
			fRec582[0] = (fRec584 - (((fTemp2 * fRec582[2]) + (2.0 * (fTemp3 * fRec582[1]))) / fTemp4));
			double fTemp279 = (((fTemp1 * (fRec582[2] + (fRec582[0] + (2.0 * fRec582[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec582[1]) + ((fRec582[0] + fRec582[2]) / fTemp4))))));
			double fTemp280 = (fConst31 * double(input7[i]));
			double fTemp281 = (fConst32 * fRec593[1]);
			double fTemp282 = (fConst33 * fRec596[1]);
			fRec598[0] = (fTemp280 + (fTemp281 + (fRec598[1] + fTemp282)));
			fRec596[0] = fRec598[0];
			double fRec597 = ((fTemp282 + fTemp281) + fTemp280);
			fRec595[0] = (fRec596[0] + fRec595[1]);
			fRec593[0] = fRec595[0];
			double fRec594 = fRec597;
			fRec592[0] = (fRec594 - (((fTemp2 * fRec592[2]) + (2.0 * (fTemp3 * fRec592[1]))) / fTemp4));
			double fTemp283 = (((fTemp1 * (fRec592[2] + (fRec592[0] + (2.0 * fRec592[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec592[1]) + ((fRec592[0] + fRec592[2]) / fTemp4))))));
			double fTemp284 = (fConst31 * double(input6[i]));
			double fTemp285 = (fConst32 * fRec600[1]);
			double fTemp286 = (fConst33 * fRec603[1]);
			fRec605[0] = (fTemp284 + (fTemp285 + (fRec605[1] + fTemp286)));
			fRec603[0] = fRec605[0];
			double fRec604 = ((fTemp286 + fTemp285) + fTemp284);
			fRec602[0] = (fRec603[0] + fRec602[1]);
			fRec600[0] = fRec602[0];
			double fRec601 = fRec604;
			fRec599[0] = (fRec601 - (((fTemp2 * fRec599[2]) + (2.0 * (fTemp3 * fRec599[1]))) / fTemp4));
			double fTemp287 = (((fTemp1 * (fRec599[2] + (fRec599[0] + (2.0 * fRec599[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec599[1]) + ((fRec599[0] + fRec599[2]) / fTemp4))))));
			double fTemp288 = (fConst35 * double(input2[i]));
			double fTemp289 = (fConst36 * fRec607[1]);
			fRec609[0] = (fTemp288 + (fRec609[1] + fTemp289));
			fRec607[0] = fRec609[0];
			double fRec608 = (fTemp289 + fTemp288);
			fRec606[0] = (fRec608 - (((fTemp2 * fRec606[2]) + (2.0 * (fTemp3 * fRec606[1]))) / fTemp4));
			double fTemp290 = (((fTemp1 * (fRec606[2] + (fRec606[0] + (2.0 * fRec606[1])))) / fTemp5) + (0.96028985649999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec606[1]) + ((fRec606[0] + fRec606[2]) / fTemp4))))));
			double fTemp291 = (fConst31 * double(input5[i]));
			double fTemp292 = (fConst32 * fRec611[1]);
			double fTemp293 = (fConst33 * fRec614[1]);
			fRec616[0] = (fTemp291 + (fTemp292 + (fRec616[1] + fTemp293)));
			fRec614[0] = fRec616[0];
			double fRec615 = ((fTemp293 + fTemp292) + fTemp291);
			fRec613[0] = (fRec614[0] + fRec613[1]);
			fRec611[0] = fRec613[0];
			double fRec612 = fRec615;
			fRec610[0] = (fRec612 - (((fTemp2 * fRec610[2]) + (2.0 * (fTemp3 * fRec610[1]))) / fTemp4));
			double fTemp294 = (((fTemp1 * (fRec610[2] + (fRec610[0] + (2.0 * fRec610[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec610[1]) + ((fRec610[0] + fRec610[2]) / fTemp4))))));
			double fTemp295 = (fConst38 * fRec618[1]);
			double fTemp296 = (fConst40 * double(input10[i]));
			double fTemp297 = (fConst41 * fRec621[1]);
			double fTemp298 = (fConst42 * fRec624[1]);
			fRec626[0] = (fTemp296 + (fTemp297 + (fRec626[1] + fTemp298)));
			fRec624[0] = fRec626[0];
			double fRec625 = ((fTemp298 + fTemp297) + fTemp296);
			fRec623[0] = (fRec624[0] + fRec623[1]);
			fRec621[0] = fRec623[0];
			double fRec622 = fRec625;
			fRec620[0] = (fTemp295 + (fRec622 + fRec620[1]));
			fRec618[0] = fRec620[0];
			double fRec619 = (fRec622 + fTemp295);
			fRec617[0] = (fRec619 - (((fTemp2 * fRec617[2]) + (2.0 * (fTemp3 * fRec617[1]))) / fTemp4));
			double fTemp299 = (((fTemp1 * (fRec617[2] + (fRec617[0] + (2.0 * fRec617[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec617[1]) + ((fRec617[0] + fRec617[2]) / fTemp4))))));
			double fTemp300 = (fConst24 * fRec628[1]);
			double fTemp301 = (fConst25 * fRec631[1]);
			double fTemp302 = (fConst27 * double(input17[i]));
			double fTemp303 = (fConst28 * fRec634[1]);
			double fTemp304 = (fConst29 * fRec637[1]);
			fRec639[0] = (fTemp302 + (fTemp303 + (fRec639[1] + fTemp304)));
			fRec637[0] = fRec639[0];
			double fRec638 = ((fTemp304 + fTemp303) + fTemp302);
			fRec636[0] = (fRec637[0] + fRec636[1]);
			fRec634[0] = fRec636[0];
			double fRec635 = fRec638;
			fRec633[0] = (fTemp300 + (fTemp301 + (fRec635 + fRec633[1])));
			fRec631[0] = fRec633[0];
			double fRec632 = (fTemp300 + (fRec635 + fTemp301));
			fRec630[0] = (fRec631[0] + fRec630[1]);
			fRec628[0] = fRec630[0];
			double fRec629 = fRec632;
			fRec627[0] = (fRec629 - (((fTemp2 * fRec627[2]) + (2.0 * (fTemp3 * fRec627[1]))) / fTemp4));
			double fTemp305 = (((fTemp1 * (fRec627[2] + (fRec627[0] + (2.0 * fRec627[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec627[1]) + ((fRec627[0] + fRec627[2]) / fTemp4))))));
			double fTemp306 = (fConst15 * fRec641[1]);
			double fTemp307 = (fConst17 * fRec644[1]);
			double fTemp308 = (fConst18 * fRec647[1]);
			double fTemp309 = (fConst20 * double(input26[i]));
			double fTemp310 = (fConst21 * fRec650[1]);
			double fTemp311 = (fConst22 * fRec653[1]);
			fRec655[0] = (fTemp309 + (fTemp310 + (fRec655[1] + fTemp311)));
			fRec653[0] = fRec655[0];
			double fRec654 = ((fTemp311 + fTemp310) + fTemp309);
			fRec652[0] = (fRec653[0] + fRec652[1]);
			fRec650[0] = fRec652[0];
			double fRec651 = fRec654;
			fRec649[0] = (fTemp307 + (fTemp308 + (fRec651 + fRec649[1])));
			fRec647[0] = fRec649[0];
			double fRec648 = (fTemp307 + (fRec651 + fTemp308));
			fRec646[0] = (fRec647[0] + fRec646[1]);
			fRec644[0] = fRec646[0];
			double fRec645 = fRec648;
			fRec643[0] = (fTemp306 + (fRec645 + fRec643[1]));
			fRec641[0] = fRec643[0];
			double fRec642 = (fRec645 + fTemp306);
			fRec640[0] = (fRec642 - (((fTemp2 * fRec640[2]) + (2.0 * (fTemp3 * fRec640[1]))) / fTemp4));
			double fTemp312 = (((fTemp1 * (fRec640[2] + (fRec640[0] + (2.0 * fRec640[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec640[1]) + ((fRec640[0] + fRec640[2]) / fTemp4))))));
			double fTemp313 = (fConst8 * fRec663[1]);
			double fTemp314 = (fConst9 * fRec666[1]);
			double fTemp315 = (fConst11 * double(input36[i]));
			double fTemp316 = (fConst12 * fRec669[1]);
			double fTemp317 = (fConst13 * fRec672[1]);
			fRec674[0] = (fTemp315 + (fTemp316 + (fRec674[1] + fTemp317)));
			fRec672[0] = fRec674[0];
			double fRec673 = ((fTemp317 + fTemp316) + fTemp315);
			fRec671[0] = (fRec672[0] + fRec671[1]);
			fRec669[0] = fRec671[0];
			double fRec670 = fRec673;
			fRec668[0] = (fTemp313 + (fTemp314 + (fRec670 + fRec668[1])));
			fRec666[0] = fRec668[0];
			double fRec667 = (fTemp313 + (fRec670 + fTemp314));
			fRec665[0] = (fRec666[0] + fRec665[1]);
			fRec663[0] = fRec665[0];
			double fRec664 = fRec667;
			double fTemp318 = ((fConst5 * fRec657[1]) + (fRec664 + (fConst6 * fRec660[1])));
			fRec662[0] = (fRec662[1] + fTemp318);
			fRec660[0] = fRec662[0];
			double fRec661 = fTemp318;
			fRec659[0] = (fRec660[0] + fRec659[1]);
			fRec657[0] = fRec659[0];
			double fRec658 = fRec661;
			fRec656[0] = (fRec658 - (((fTemp2 * fRec656[2]) + (2.0 * (fTemp3 * fRec656[1]))) / fTemp4));
			double fTemp319 = (((fTemp1 * (fRec656[2] + (fRec656[0] + (2.0 * fRec656[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec656[1]) + ((fRec656[0] + fRec656[2]) / fTemp4))))));
			fRec675[0] = (double(input49[i]) - (((fTemp2 * fRec675[2]) + (2.0 * (fTemp3 * fRec675[1]))) / fTemp4));
			double fTemp320 = (((fTemp1 * (fRec675[2] + (fRec675[0] + (2.0 * fRec675[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec675[1]) + ((fRec675[0] + fRec675[2]) / fTemp4))))));
			fVec0[(IOTA & 127)] = (((0.0135353674 * fTemp7) + ((0.027864751399999999 * fTemp8) + ((0.0078933409000000003 * fTemp9) + ((0.0095645728000000006 * fTemp10) + ((0.0151611144 * fTemp11) + ((0.011787540500000001 * fTemp12) + ((0.0149760008 * fTemp13) + ((0.00040828700000000002 * fTemp14) + (((0.0074995846000000003 * fTemp22) + ((0.0038508665999999999 * fTemp30) + ((0.0066403892999999997 * fTemp38) + ((0.0256695781 * fTemp46) + ((0.0039190859999999996 * fTemp54) + ((0.015466961099999999 * fTemp62) + ((0.0012815834999999999 * fTemp70) + (((0.00025295899999999997 * fTemp77) + ((0.011857038800000001 * fTemp84) + ((0.025740849400000002 * fTemp91) + ((0.0044399158000000003 * fTemp98) + (((0.0183491112 * fTemp104) + ((((0.075109717199999995 * fTemp108) + (((0.1052099765 * fTemp111) + ((0.045956324899999998 * fTemp112) + (0.062193089999999999 * fTemp115))) + (0.13626246889999999 * fTemp119))) + (0.17263790139999999 * fTemp124)) + (0.1497434872 * fTemp130))) + (0.078830609400000001 * fTemp137)))))) + (0.0042194724000000003 * fTemp145))))))))) + (0.0017560332 * fTemp146)))))))))) - ((0.1112139538 * fTemp147) + ((0.0220249343 * fTemp148) + ((0.012370116800000001 * fTemp149) + ((0.042943655800000001 * fTemp150) + ((0.013513445299999999 * fTemp151) + (((0.15364381529999999 * fTemp159) + ((0.0103454363 * fTemp167) + ((0.0498611396 * fTemp175) + ((0.019239224199999998 * fTemp183) + (((0.1500373049 * fTemp190) + ((0.0038882569 * fTemp197) + ((0.018102749899999999 * fTemp204) + ((0.038750377000000003 * fTemp211) + ((0.0073052669000000002 * fTemp218) + (((0.093553807000000003 * fTemp224) + ((0.0080451097000000006 * fTemp230) + ((0.0150595152 * fTemp236) + ((0.0228112816 * fTemp242) + ((0.0157270334 * fTemp248) + ((0.023327264399999999 * fTemp254) + (((0.0048525382999999997 * fTemp259) + ((0.017482805899999999 * fTemp264) + ((0.0445264654 * fTemp269) + ((0.0026487787999999999 * fTemp274) + ((0.0257282954 * fTemp279) + (((0.025019118600000001 * fTemp283) + ((0.055424969999999997 * fTemp287) + ((0.016333785 * fTemp290) + (0.012369500199999999 * fTemp294)))) + (0.0208168335 * fTemp299))))))) + (0.0233715777 * fTemp305)))))))) + (0.022383276800000001 * fTemp312))))))) + (0.0066031068000000004 * fTemp319)))))) + (0.070897923099999996 * fTemp320))))))));
			output0[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec0[((IOTA - iConst43) & 127)])));
			fVec1[(IOTA & 127)] = (((0.075596612800000004 * fTemp147) + ((0.0026293156999999999 * fTemp148) + ((0.023495919699999999 * fTemp9) + ((0.019139733400000001 * fTemp10) + ((0.0057411848999999997 * fTemp13) + ((0.0069602429999999996 * fTemp14) + ((0.0055576273000000004 * fTemp146) + ((0.10439831149999999 * fTemp320) + ((0.1012760311 * fTemp159) + ((0.0277150361 * fTemp38) + ((0.022559289699999999 * fTemp46) + ((0.0034965869999999998 * fTemp62) + ((0.0059634655 * fTemp70) + ((0.1058136043 * fTemp319) + ((0.1236998898 * fTemp190) + ((0.0316193273 * fTemp84) + ((0.0141628777 * fTemp91) + ((0.0036684661 * fTemp98) + ((0.098343373600000006 * fTemp137) + ((0.13899644450000001 * fTemp224) + ((0.025778590300000001 * fTemp104) + ((0.082711457899999993 * fTemp130) + ((0.14349751490000001 * fTemp259) + ((0.013127613 * fTemp274) + ((0.061056288299999997 * fTemp124) + ((0.1340064779 * fTemp108) + (((0.10745397080000001 * fTemp111) + ((0.040721593200000003 * fTemp112) + (0.0144763767 * fTemp115))) + (0.0368024791 * fTemp119)))))))))))))))))))))))))))) - ((0.023409550500000001 * fTemp7) + ((0.037653095300000002 * fTemp8) + ((0.0077856840000000002 * fTemp11) + ((0.016326396100000001 * fTemp149) + ((0.0001756754 * fTemp12) + ((0.0241873074 * fTemp150) + ((0.0140881103 * fTemp151) + ((0.031030047500000001 * fTemp22) + ((0.0055081768000000003 * fTemp167) + ((0.033393651000000003 * fTemp30) + ((0.014739254300000001 * fTemp54) + ((0.015957575299999999 * fTemp175) + ((0.0013197561999999999 * fTemp145) + ((0.017028858800000001 * fTemp183) + ((0.038686374000000003 * fTemp77) + ((0.017271780899999999 * fTemp197) + ((0.0225895555 * fTemp204) + ((0.0075584863999999998 * fTemp211) + ((0.0064241717999999996 * fTemp218) + ((0.017677386100000001 * fTemp312) + ((0.044862103200000003 * fTemp230) + ((0.032132426999999998 * fTemp236) + ((0.0049741305 * fTemp242) + ((0.0013952232 * fTemp248) + ((0.0085242375999999998 * fTemp254) + ((0.015677994300000001 * fTemp305) + ((0.047630788100000002 * fTemp264) + ((0.049568594899999999 * fTemp269) + ((0.0066556484000000003 * fTemp279) + (((0.044635640999999997 * fTemp283) + ((0.049717737300000002 * fTemp287) + ((0.023143284699999999 * fTemp290) + (0.0053357303 * fTemp294)))) + (0.011240098699999999 * fTemp299))))))))))))))))))))))))))))))));
			output1[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec1[((IOTA - iConst44) & 127)])));
			fVec2[(IOTA & 127)] = (((0.0135215518 * fTemp7) + ((0.0143320149 * fTemp148) + ((0.0150947832 * fTemp10) + ((0.018901688600000001 * fTemp11) + ((0.042970315600000003 * fTemp150) + ((0.013598842700000001 * fTemp151) + ((0.0067141261000000004 * fTemp159) + ((0.0083012820000000001 * fTemp22) + ((0.0103397171 * fTemp167) + ((0.0013368062999999999 * fTemp38) + ((0.029185298500000002 * fTemp46) + ((0.0038277772000000002 * fTemp54) + ((0.032516628200000001 * fTemp175) + ((0.019044099500000002 * fTemp183) + ((0.0504478748 * fTemp190) + ((0.011573252799999999 * fTemp84) + ((0.025759067199999999 * fTemp91) + ((0.018049670100000002 * fTemp211) + ((0.0079599933000000008 * fTemp218) + ((0.022569763499999999 * fTemp312) + ((((((0.0224027532 * fTemp305) + ((0.1257620019 * fTemp259) + ((0.013338374700000001 * fTemp279) + (((0.13658517319999999 * fTemp108) + (((0.0460748692 * fTemp112) + (0.1186753133 * fTemp111)) + (0.0090050255999999992 * fTemp294))) + (0.017620700499999999 * fTemp299))))) + (0.0151153682 * fTemp254)) + (0.0049569973999999996 * fTemp248)) + (0.0183942998 * fTemp104)) + (0.093715238899999997 * fTemp224)))))))))))))))))))))) - ((0.028292667699999999 * fTemp147) + ((0.027944516400000001 * fTemp8) + ((0.0052455017000000003 * fTemp9) + ((0.0124228099 * fTemp149) + ((0.0023222583999999999 * fTemp12) + ((0.0096193213000000007 * fTemp13) + ((0.0059408270000000001 * fTemp14) + ((0.016793100599999999 * fTemp146) + ((0.12859453370000001 * fTemp320) + ((0.038025411299999999 * fTemp30) + ((0.0072373892000000004 * fTemp62) + ((0.0066810304999999999 * fTemp70) + ((0.0041894530999999997 * fTemp145) + ((0.153590368 * fTemp319) + ((0.00030526130000000002 * fTemp77) + ((0.0024465800999999999 * fTemp197) + ((0.038730773900000001 * fTemp204) + ((0.0052584470000000003 * fTemp98) + ((0.16192639819999999 * fTemp137) + (((((0.14994270239999999 * fTemp130) + ((0.020996298600000001 * fTemp264) + ((0.049832618100000003 * fTemp269) + ((0.0025157714000000001 * fTemp274) + ((0.11886973520000001 * fTemp124) + ((0.0266199991 * fTemp283) + ((0.055592276000000003 * fTemp287) + (((0.030494917 * fTemp115) + (0.016417657299999999 * fTemp290)) + (0.0752845231 * fTemp119))))))))) + (0.0271406137 * fTemp242)) + (0.0234077543 * fTemp236)) + (0.010961900199999999 * fTemp230))))))))))))))))))))));
			output2[i] = FAUSTFLOAT((0.9619850187265917 * (fVec2[((IOTA - iConst44) & 127)] * fRec0[0])));
			fVec3[(IOTA & 127)] = (((0.0139548287 * fTemp7) + ((0.037679090999999998 * fTemp8) + ((0.005630197 * fTemp10) + ((0.0054591507000000001 * fTemp12) + ((0.024145227200000001 * fTemp150) + ((0.12713311399999999 * fTemp320) + ((0.033988649400000001 * fTemp22) + ((0.0055472009999999999 * fTemp167) + ((0.012311499300000001 * fTemp30) + ((0.0060449644 * fTemp38) + ((0.0184409195 * fTemp46) + ((0.034900422700000003 * fTemp175) + ((0.0013531566999999999 * fTemp145) + ((0.1014850504 * fTemp319) + ((0.038816228500000001 * fTemp77) + ((0.0077166481999999996 * fTemp197) + ((0.0250192186 * fTemp84) + ((0.014220806000000001 * fTemp91) + ((0.022550012299999998 * fTemp211) + ((0.0168098359 * fTemp218) + ((0.017551615400000001 * fTemp312) + ((0.018287934299999999 * fTemp137) + ((0.020779329799999999 * fTemp230) + ((0.0257921999 * fTemp104) + ((0.0024518664000000002 * fTemp248) + ((0.032234464400000003 * fTemp254) + ((0.042815318499999998 * fTemp305) + ((0.0132065412 * fTemp274) + ((0.030453841200000002 * fTemp279) + (((0.036716895700000002 * fTemp108) + (((0.040764204300000002 * fTemp112) + (0.086291308100000005 * fTemp111)) + (0.0278374147 * fTemp294))) + (0.047710452700000003 * fTemp299))))))))))))))))))))))))))))))) - ((0.0199430092 * fTemp147) + ((0.0057405255000000004 * fTemp148) + ((0.011663302299999999 * fTemp9) + ((0.0056415132 * fTemp11) + ((0.016339845200000001 * fTemp149) + ((0.019268909599999998 * fTemp13) + ((0.021595531000000001 * fTemp14) + ((0.0020457204000000001 * fTemp146) + ((0.023559769599999999 * fTemp151) + ((0.1054628447 * fTemp159) + ((0.0148334599 * fTemp54) + ((0.0135745837 * fTemp62) + ((0.027736759999999999 * fTemp70) + ((0.010100630399999999 * fTemp183) + ((0.15695703799999999 * fTemp190) + ((0.0076133336000000001 * fTemp204) + (((0.13921415600000001 * fTemp224) + ((0.0085013417999999993 * fTemp236) + ((0.0044966475000000001 * fTemp242) + ((0.082489759600000004 * fTemp130) + ((0.058548216100000001 * fTemp259) + ((0.011186135999999999 * fTemp264) + ((0.0398224301 * fTemp269) + ((0.14467973370000001 * fTemp124) + ((0.035362475499999997 * fTemp283) + ((0.049833269899999998 * fTemp287) + (((0.065861253199999997 * fTemp115) + (0.023150213900000001 * fTemp290)) + (0.13418582530000001 * fTemp119)))))))))))) + (0.019755657900000001 * fTemp98)))))))))))))))))));
			output3[i] = FAUSTFLOAT((0.96142322097378285 * (fVec3[((IOTA - iConst45) & 127)] * fRec0[0])));
			fVec4[(IOTA & 127)] = (((0.070910273900000001 * fTemp147) + ((0.0017314685000000001 * fTemp148) + ((0.0278889958 * fTemp8) + ((0.0118753136 * fTemp11) + ((0.0078903702999999995 * fTemp14) + ((0.0220865045 * fTemp146) + ((0.0135838366 * fTemp151) + ((0.1536453914 * fTemp159) + ((0.049872187300000002 * fTemp30) + ((0.015391672800000001 * fTemp46) + ((0.0040486958999999996 * fTemp54) + ((0.0039008093 * fTemp175) + ((0.0042467058999999998 * fTemp145) + ((0.0066225998999999997 * fTemp319) + ((0.078820735000000003 * fTemp190) + ((0.00016350450000000001 * fTemp77) + ((0.0072405704999999997 * fTemp197) + ((0.0180569584 * fTemp204) + ((0.0044427649 * fTemp84) + ((0.0256509615 * fTemp91) + ((0.038798073699999998 * fTemp211) + ((0.15006181909999999 * fTemp137) + ((0.023338990099999998 * fTemp230) + ((0.015062076799999999 * fTemp236) + ((0.0183784608 * fTemp104) + ((0.0228183533 * fTemp248) + ((0.0232620828 * fTemp254) + ((0.1497618768 * fTemp130) + ((0.017497469500000001 * fTemp264) + ((0.0445058209 * fTemp279) + ((((0.045986689300000001 * fTemp112) + (0.0622286799 * fTemp111)) + (0.025018373 * fTemp294)) + (0.020788514800000001 * fTemp299)))))))))))))))))))))))))))))))) - ((0.0134276226 * fTemp7) + ((0.00040433679999999999 * fTemp9) + ((0.0096023692000000004 * fTemp10) + ((0.0124098318 * fTemp149) + ((0.015195236900000001 * fTemp12) + ((0.0148629725 * fTemp13) + ((0.042941547300000001 * fTemp150) + ((0.1111979297 * fTemp320) + ((0.019267685100000001 * fTemp22) + ((0.010417227100000001 * fTemp167) + ((0.0066015118000000003 * fTemp38) + ((0.025623336900000002 * fTemp62) + ((0.0012635188 * fTemp70) + ((0.0073923236999999999 * fTemp183) + ((0.0118135572 * fTemp98) + ((0.0039305258000000001 * fTemp218) + ((0.022373841500000002 * fTemp312) + ((0.093588864199999997 * fTemp224) + ((0.0157854971 * fTemp242) + ((0.0080989307999999992 * fTemp305) + ((0.17268661220000001 * fTemp259) + ((0.0256900992 * fTemp269) + ((0.0027169400000000002 * fTemp274) + ((0.0048721195999999996 * fTemp124) + ((0.075124711400000002 * fTemp108) + ((0.0123649615 * fTemp283) + ((0.055391283299999997 * fTemp287) + (((0.1052528902 * fTemp115) + (0.016356983700000001 * fTemp290)) + (0.1363198873 * fTemp119))))))))))))))))))))))))))))));
			output4[i] = FAUSTFLOAT((0.9606741573033708 * (fVec4[((IOTA - iConst43) & 127)] * fRec0[0])));
			fVec5[(IOTA & 127)] = (((0.023455793400000001 * fTemp7) + ((0.0056083464999999999 * fTemp148) + ((0.0078726368000000008 * fTemp12) + ((0.023575668399999999 * fTemp14) + ((0.013997662900000001 * fTemp151) + ((0.075530381300000005 * fTemp320) + ((0.015947668799999998 * fTemp30) + ((0.0034597237999999999 * fTemp46) + ((0.0310813047 * fTemp183) + ((0.098274377499999996 * fTemp190) + ((0.0063789946 * fTemp197) + ((0.022512124299999998 * fTemp204) + ((0.0036725362000000002 * fTemp84) + ((0.014176062499999999 * fTemp91) + (((0.13897491670000001 * fTemp224) + ((0.015642075799999999 * fTemp230) + ((0.032134085499999999 * fTemp236) + ((0.0257129834 * fTemp104) + ((0.0048830426 * fTemp248) + ((0.0084896998000000001 * fTemp254) + ((0.082655685600000001 * fTemp130) + ((0.047670590800000003 * fTemp264) + ((0.0132180823 * fTemp274) + ((0.0495788011 * fTemp279) + ((0.011221274700000001 * fTemp299) + ((0.14348552170000001 * fTemp124) + (((0.040712956100000003 * fTemp112) + (0.014469774899999999 * fTemp111)) + (0.044654862199999999 * fTemp294)))))))))))))) + (0.0075679222000000004 * fTemp211)))))))))))))))) - ((0.1043233656 * fTemp147) + ((0.037621905400000002 * fTemp8) + ((0.0069539976999999998 * fTemp9) + ((0.0190742003 * fTemp10) + ((0.00013876270000000001 * fTemp11) + ((0.016178431 * fTemp149) + ((0.0056717136999999999 * fTemp13) + ((0.024158058400000001 * fTemp150) + ((0.0025649185 * fTemp146) + ((0.101227398 * fTemp159) + ((0.016956723100000001 * fTemp22) + ((0.0055408643 * fTemp167) + ((0.027751685700000001 * fTemp38) + ((0.0148479844 * fTemp54) + ((0.022503769900000001 * fTemp62) + ((0.0059643398000000002 * fTemp70) + ((0.033334630900000002 * fTemp175) + ((0.0012679824000000001 * fTemp145) + ((0.1057377469 * fTemp319) + ((0.038740381999999997 * fTemp77) + ((0.0316058699 * fTemp98) + ((0.0172822488 * fTemp218) + ((0.017623675500000002 * fTemp312) + ((0.12366611030000001 * fTemp137) + ((0.0014099892 * fTemp242) + ((0.044912976399999999 * fTemp305) + ((0.061017564699999999 * fTemp259) + (((0.13400071729999999 * fTemp108) + ((0.0053307212000000001 * fTemp283) + ((0.049756250100000003 * fTemp287) + (((0.10744966760000001 * fTemp115) + (0.023126902599999999 * fTemp290)) + (0.0367814593 * fTemp119))))) + (0.0066359421000000002 * fTemp269))))))))))))))))))))))))))))));
			output5[i] = FAUSTFLOAT((0.9619850187265917 * (fVec5[((IOTA - iConst44) & 127)] * fRec0[0])));
			fVec6[(IOTA & 127)] = (((0.12860610880000001 * fTemp147) + ((0.0059972856 * fTemp9) + ((0.0096093268999999995 * fTemp13) + ((0.042993614600000001 * fTemp150) + ((0.018986500399999998 * fTemp22) + ((0.010404095699999999 * fTemp167) + ((0.0038829445999999999 * fTemp54) + ((0.0067207309999999998 * fTemp70) + ((0.15358737720000001 * fTemp319) + ((0.038736597499999997 * fTemp204) + ((0.025697811399999999 * fTemp91) + ((0.0225325977 * fTemp312) + ((0.093778654500000003 * fTemp224) + ((0.0233866649 * fTemp236) + ((0.0049647787000000002 * fTemp242) + ((0.0184347742 * fTemp104) + (((0.1188204588 * fTemp259) + ((0.020998267000000001 * fTemp264) + ((0.013329655100000001 * fTemp269) + ((0.049806075900000003 * fTemp279) + ((0.1257974221 * fTemp124) + ((0.0090017427000000007 * fTemp283) + ((0.026629753900000001 * fTemp294) + ((0.046075117399999997 * fTemp112) + (0.075246520299999994 * fTemp119))))))))) + (0.0271623995 * fTemp248)))))))))))))))))) - ((0.013553790499999999 * fTemp7) + ((0.016791104099999999 * fTemp148) + ((0.027918286099999998 * fTemp8) + ((0.0150244278 * fTemp10) + ((0.0023184264999999999 * fTemp11) + ((0.0124673287 * fTemp149) + ((0.0189962085 * fTemp12) + ((0.0052611176000000003 * fTemp14) + ((0.0144286541 * fTemp146) + ((0.013519278900000001 * fTemp151) + ((0.0282344242 * fTemp320) + ((0.0067921635000000001 * fTemp159) + ((0.032539213599999998 * fTemp30) + ((0.0013463628000000001 * fTemp38) + ((0.0072327206999999996 * fTemp46) + ((0.029100977199999999 * fTemp62) + ((0.038019398900000001 * fTemp175) + ((0.0041826462 * fTemp145) + ((0.0083287252999999992 * fTemp183) + ((0.16190072820000001 * fTemp190) + ((0.000287514 * fTemp77) + ((0.0079622184000000002 * fTemp197) + ((0.0052751415000000003 * fTemp84) + ((0.0116148877 * fTemp98) + ((0.018065580599999999 * fTemp211) + ((0.0024106239000000001 * fTemp218) + ((0.050527952000000001 * fTemp137) + ((0.022381718799999999 * fTemp230) + ((0.0151094023 * fTemp254) + ((0.0109550906 * fTemp305) + ((0.14989837349999999 * fTemp130) + ((0.0025460910999999999 * fTemp274) + (((0.13659366249999999 * fTemp108) + ((((0.1186703607 * fTemp115) + (0.0164329252 * fTemp290)) + (0.030477931400000002 * fTemp111)) + (0.055559497100000001 * fTemp287))) + (0.0176106969 * fTemp299)))))))))))))))))))))))))))))))))));
			output6[i] = FAUSTFLOAT((0.9619850187265917 * (fVec6[((IOTA - iConst44) & 127)] * fRec0[0])));
			fVec7[(IOTA & 127)] = (((0.037739753100000002 * fTemp8) + ((0.021463716800000001 * fTemp9) + ((0.0053128556999999998 * fTemp11) + ((0.0054997819000000003 * fTemp12) + ((0.019183921199999999 * fTemp13) + ((0.024149098800000001 * fTemp150) + ((0.0058420542000000002 * fTemp146) + ((0.023470309500000001 * fTemp151) + ((0.1055598031 * fTemp159) + ((0.0054660875999999999 * fTemp167) + ((0.027652923900000001 * fTemp70) + ((0.012372071700000001 * fTemp175) + ((0.0013012814 * fTemp145) + ((0.018190271500000001 * fTemp190) + ((0.038712033100000001 * fTemp77) + ((0.0076050531000000001 * fTemp204) + ((0.0141672299 * fTemp91) + ((0.0076686527000000004 * fTemp218) + ((0.0174911741 * fTemp312) + ((0.1570430589 * fTemp137) + ((0.0085216252000000006 * fTemp236) + ((0.0025478879999999999 * fTemp242) + ((0.0258301877 * fTemp104) + ((0.0045721972999999997 * fTemp248) + ((0.020742889 * fTemp305) + ((0.14481047450000001 * fTemp259) + ((0.0111589611 * fTemp264) + ((0.030418881799999999 * fTemp269) + ((0.013081291199999999 * fTemp274) + (((0.027816703000000002 * fTemp283) + ((0.035319429999999999 * fTemp294) + ((0.040808799799999997 * fTemp112) + (0.1342776852 * fTemp119)))) + (0.039830035999999999 * fTemp279))))))))))))))))))))))))))))))) - ((0.1271423273 * fTemp147) + ((0.013862903100000001 * fTemp7) + ((0.0020605325000000001 * fTemp148) + ((0.0056535511999999998 * fTemp10) + ((0.016413099699999999 * fTemp149) + ((0.0116900237 * fTemp14) + ((0.020000024299999999 * fTemp320) + ((0.0100836871 * fTemp22) + ((0.034962488 * fTemp30) + ((0.0059566326000000001 * fTemp38) + ((0.013523709 * fTemp46) + ((0.014623699400000001 * fTemp54) + ((0.018436476600000001 * fTemp62) + ((0.033860005700000001 * fTemp183) + ((0.1014521652 * fTemp319) + ((0.0167437642 * fTemp197) + ((0.019744625299999999 * fTemp84) + ((0.024938672700000001 * fTemp98) + ((0.022658006299999998 * fTemp211) + ((0.13924438 * fTemp224) + ((0.042719620700000002 * fTemp230) + ((0.032177546899999999 * fTemp254) + ((0.082626669599999994 * fTemp130) + ((0.047637282900000001 * fTemp299) + ((0.058514262499999997 * fTemp124) + ((0.036792192500000001 * fTemp108) + ((((0.086374975000000007 * fTemp115) + (0.023160262899999999 * fTemp290)) + (0.065904380700000001 * fTemp111)) + (0.049816418100000003 * fTemp287)))))))))))))))))))))))))))));
			output7[i] = FAUSTFLOAT((0.96142322097378285 * (fVec7[((IOTA - iConst45) & 127)] * fRec0[0])));
			fVec8[(IOTA & 127)] = (((0.111262734 * fTemp147) + ((0.0134290017 * fTemp7) + ((0.022050839900000001 * fTemp148) + ((0.027849103699999999 * fTemp8) + ((0.0095330064999999999 * fTemp10) + ((0.014908623100000001 * fTemp13) + ((0.070931807499999999 * fTemp320) + ((0.0066340293999999998 * fTemp38) + ((0.0038643883 * fTemp54) + ((0.0012319045 * fTemp70) + ((0.049856236499999998 * fTemp175) + ((0.0042726109999999999 * fTemp145) + ((0.019272900799999999 * fTemp183) + ((0.15007054610000001 * fTemp190) + ((0.00016244529999999999 * fTemp77) + ((0.0038791493999999998 * fTemp197) + ((0.025786653 * fTemp91) + ((0.0072305191 * fTemp218) + ((0.0081110682 * fTemp230) + ((0.022792869600000001 * fTemp242) + ((0.0182356818 * fTemp104) + ((0.015723588600000001 * fTemp248) + ((0.0233542617 * fTemp305) + ((0.14977584990000001 * fTemp130) + ((0.0048451372999999999 * fTemp259) + ((0.044479412000000003 * fTemp269) + (((0.075128725300000004 * fTemp108) + ((0.025031978900000001 * fTemp283) + ((0.0123543835 * fTemp294) + ((0.045962519100000002 * fTemp112) + (0.1362831189 * fTemp119))))) + (0.025708132500000001 * fTemp279)))))))))))))))))))))))))))) - ((0.0079252119999999992 * fTemp9) + ((0.0151275874 * fTemp11) + ((0.0122034615 * fTemp149) + ((0.011770935999999999 * fTemp12) + ((0.00039778300000000002 * fTemp14) + ((0.042954199399999997 * fTemp150) + ((0.0017717357 * fTemp146) + ((0.013583617500000001 * fTemp151) + ((0.15369411199999999 * fTemp159) + ((0.0073946808999999997 * fTemp22) + ((0.010369387000000001 * fTemp167) + ((0.0038451939000000001 * fTemp30) + ((0.025641397999999999 * fTemp46) + ((0.015453339700000001 * fTemp62) + ((0.0066027938999999999 * fTemp319) + ((0.0180951616 * fTemp204) + ((0.0117813655 * fTemp84) + ((0.0043860566000000004 * fTemp98) + ((0.038746324899999997 * fTemp211) + ((0.022386208800000001 * fTemp312) + ((0.078854875500000005 * fTemp137) + ((0.093564590099999997 * fTemp224) + ((0.015013922900000001 * fTemp236) + (((0.0175203754 * fTemp264) + ((0.0026032866 * fTemp274) + ((0.020794305400000001 * fTemp299) + ((0.17266697449999999 * fTemp124) + ((((0.062202348599999999 * fTemp115) + (0.016320951399999999 * fTemp290)) + (0.1052328951 * fTemp111)) + (0.055438628199999999 * fTemp287)))))) + (0.023266667500000001 * fTemp254))))))))))))))))))))))))));
			output8[i] = FAUSTFLOAT((0.9606741573033708 * (fVec8[((IOTA - iConst43) & 127)] * fRec0[0])));
			fVec9[(IOTA & 127)] = (((0.019166083399999999 * fTemp10) + ((0.0077357199999999997 * fTemp11) + ((0.00012294119999999999 * fTemp12) + (((0.1012818845 * fTemp159) + ((0.0309830465 * fTemp22) + ((0.033361524400000002 * fTemp30) + ((0.027560904399999999 * fTemp38) + ((0.0059390961000000001 * fTemp70) + ((0.015948911499999999 * fTemp175) + ((0.016909061999999999 * fTemp183) + ((0.1057909392 * fTemp319) + ((0.017237834699999999 * fTemp197) + ((0.0141536962 * fTemp91) + ((0.0063972895999999998 * fTemp218) + ((0.13902911239999999 * fTemp224) + ((0.044786607800000003 * fTemp230) + ((0.0049608177999999996 * fTemp242) + ((0.025732627899999999 * fTemp104) + ((0.0014193566999999999 * fTemp248) + ((0.0155979282 * fTemp305) + ((0.082691803699999997 * fTemp130) + ((0.049600516999999997 * fTemp269) + ((0.0131036552 * fTemp274) + (((0.1340445321 * fTemp108) + ((0.044553464100000002 * fTemp283) + ((0.0053186859 * fTemp294) + ((0.040729694599999998 * fTemp112) + (0.036794505800000002 * fTemp119))))) + (0.0066446984999999998 * fTemp279)))))))))))))))))))))) + (0.0056869010999999999 * fTemp13))))) - ((0.075584698300000003 * fTemp147) + ((0.023379179600000001 * fTemp7) + ((0.0026548154000000002 * fTemp148) + ((0.037612025299999997 * fTemp8) + ((0.023390207400000002 * fTemp9) + ((0.016350473399999999 * fTemp149) + ((0.0069106884 * fTemp14) + ((0.024142961300000002 * fTemp150) + ((0.0056001957999999999 * fTemp146) + ((0.0139641924 * fTemp151) + ((0.1043796647 * fTemp320) + ((0.0054681527999999998 * fTemp167) + ((0.022592483100000001 * fTemp46) + ((0.0146255024 * fTemp54) + ((0.0034636560999999999 * fTemp62) + ((0.0012820218 * fTemp145) + ((0.1237209121 * fTemp190) + ((0.038623628100000001 * fTemp77) + ((0.022562711799999999 * fTemp204) + ((0.031468240699999997 * fTemp84) + ((0.0036694410999999999 * fTemp98) + ((0.0075755756000000004 * fTemp211) + ((0.017572497400000001 * fTemp312) + ((0.098320537299999997 * fTemp137) + ((0.032126663600000001 * fTemp236) + (((0.1435366495 * fTemp259) + ((0.047547405600000002 * fTemp264) + ((0.0111916567 * fTemp299) + ((0.061042002999999997 * fTemp124) + ((((0.0144742459 * fTemp115) + (0.023101546600000002 * fTemp290)) + (0.1074817423 * fTemp111)) + (0.049750542699999997 * fTemp287)))))) + (0.0085071621 * fTemp254))))))))))))))))))))))))))));
			output9[i] = FAUSTFLOAT((0.9619850187265917 * (fVec9[((IOTA - iConst44) & 127)] * fRec0[0])));
			fVec10[(IOTA & 127)] = (((0.028275312800000001 * fTemp147) + ((0.01347492 * fTemp7) + ((0.0051188264999999997 * fTemp9) + ((0.0150694726 * fTemp10) + ((0.0022806020000000001 * fTemp12) + ((0.0058797095000000001 * fTemp14) + ((0.042913448899999998 * fTemp150) + ((0.016838063399999999 * fTemp146) + ((0.013423001 * fTemp151) + ((0.1287217547 * fTemp320) + ((0.0067686645000000004 * fTemp159) + ((0.010305998 * fTemp167) + ((0.038054449400000002 * fTemp30) + ((0.0014513712 * fTemp38) + ((0.0037205285 * fTemp54) + (((0.0024702611000000001 * fTemp197) + ((0.025791558799999999 * fTemp91) + ((0.0051905900999999997 * fTemp98) + ((0.018008545399999999 * fTemp211) + ((0.022453823299999998 * fTemp312) + ((0.1619635432 * fTemp137) + ((0.0937480381 * fTemp224) + ((0.0110647131 * fTemp230) + ((0.027073205100000001 * fTemp242) + ((0.0183651526 * fTemp104) + (((0.0498164288 * fTemp269) + ((0.017557400000000001 * fTemp299) + ((0.1188273346 * fTemp124) + ((0.13653479639999999 * fTemp108) + (((0.046041830899999997 * fTemp112) + (0.030470613899999999 * fTemp115)) + (0.026689343099999999 * fTemp283)))))) + (0.015108554099999999 * fTemp254)))))))))))) + (0.0072740575000000002 * fTemp62))))))))))))))))) - ((0.0143081257 * fTemp148) + ((0.027993302599999999 * fTemp8) + ((0.018876241299999999 * fTemp11) + ((0.012376110100000001 * fTemp149) + ((0.0096395122999999999 * fTemp13) + ((0.0082309944000000003 * fTemp22) + ((0.029186204600000001 * fTemp46) + ((0.0065971453000000001 * fTemp70) + ((0.032470822099999998 * fTemp175) + ((0.0042288634000000004 * fTemp145) + ((0.018898386400000002 * fTemp183) + ((0.15368266189999999 * fTemp319) + ((0.050507825800000003 * fTemp190) + ((0.00039688670000000002 * fTemp77) + ((0.038719509700000002 * fTemp204) + ((0.011633547899999999 * fTemp84) + ((0.0079332333999999997 * fTemp218) + ((0.023409328600000001 * fTemp236) + ((0.0049248136999999999 * fTemp248) + ((0.022314177800000001 * fTemp305) + ((0.1499287215 * fTemp130) + ((0.12575033360000001 * fTemp259) + ((0.021093298900000002 * fTemp264) + ((0.0024197083000000001 * fTemp274) + (((0.055588797099999997 * fTemp287) + ((0.0089681128000000006 * fTemp294) + (((0.016427320400000001 * fTemp290) + (0.1186111118 * fTemp111)) + (0.075241517300000005 * fTemp119)))) + (0.0133487941 * fTemp279)))))))))))))))))))))))))));
			output10[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec10[((IOTA - iConst44) & 127)])));
			fVec11[(IOTA & 127)] = (((0.019926990200000001 * fTemp147) + ((0.0138372392 * fTemp7) + ((0.0058938968000000003 * fTemp148) + ((0.037748645900000002 * fTemp8) + ((0.0117286938 * fTemp9) + ((0.0056317086999999998 * fTemp10) + ((0.0053560012000000001 * fTemp11) + ((0.021515116500000001 * fTemp14) + ((0.024138417700000001 * fTemp150) + ((0.0020892323 * fTemp146) + ((0.0054429001000000001 * fTemp167) + ((0.0059552588 * fTemp38) + ((0.013407758699999999 * fTemp62) + ((0.0012359646 * fTemp145) + ((0.010082347199999999 * fTemp183) + ((0.1015218304 * fTemp319) + ((0.15702917599999999 * fTemp190) + ((0.038702629199999998 * fTemp77) + ((0.014039417300000001 * fTemp91) + ((0.019839211499999999 * fTemp98) + ((0.0227349289 * fTemp211) + ((0.0174823905 * fTemp312) + ((0.0046761601999999996 * fTemp242) + ((0.025943944199999999 * fTemp104) + (((0.0586030622 * fTemp259) + ((0.039736452300000003 * fTemp269) + ((0.012956158299999999 * fTemp274) + ((0.047659383600000001 * fTemp299) + ((0.1448001119 * fTemp124) + ((0.036750169300000003 * fTemp108) + (((0.040842764400000002 * fTemp112) + (0.065946663200000005 * fTemp115)) + (0.035359935600000003 * fTemp283)))))))) + (0.032114929600000001 * fTemp254)))))))))))))))))))))))))) - ((0.0165023914 * fTemp149) + ((0.0052069999000000002 * fTemp12) + ((0.019035946599999999 * fTemp13) + ((0.023445213699999998 * fTemp151) + ((0.1271382667 * fTemp320) + ((0.10547886419999999 * fTemp159) + ((0.033834848100000002 * fTemp22) + ((0.012397446899999999 * fTemp30) + ((0.018280478700000002 * fTemp46) + ((0.014507135399999999 * fTemp54) + ((0.027747128699999998 * fTemp70) + ((0.0349909027 * fTemp175) + ((0.0076867144999999996 * fTemp197) + ((0.0076150541999999996 * fTemp204) + ((0.025040960599999999 * fTemp84) + ((0.016671206000000001 * fTemp218) + ((0.018308786600000002 * fTemp137) + ((0.13931126529999999 * fTemp224) + ((0.020747108399999999 * fTemp230) + ((0.0084694209999999995 * fTemp236) + ((0.0026297209999999998 * fTemp248) + ((0.0427204573 * fTemp305) + ((0.082537255200000006 * fTemp130) + ((0.0111611299 * fTemp264) + (((0.0497167154 * fTemp287) + ((0.027849603699999999 * fTemp294) + (((0.023229842800000001 * fTemp290) + (0.086396963899999998 * fTemp111)) + (0.13432427259999999 * fTemp119)))) + (0.03037219 * fTemp279)))))))))))))))))))))))))));
			output11[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec11[((IOTA - iConst45) & 127)])));
			fVec12[(IOTA & 127)] = (((0.027822079 * fTemp8) + ((0.00035400779999999999 * fTemp9) + ((0.0150210802 * fTemp12) + ((0.0135081704 * fTemp151) + ((0.1113069656 * fTemp320) + ((0.15369687060000001 * fTemp159) + ((0.019196264099999999 * fTemp22) + ((0.0038134865999999998 * fTemp54) + ((0.025767254699999999 * fTemp62) + ((0.0042510248999999998 * fTemp145) + ((0.0074307178999999998 * fTemp183) + ((0.0065167265000000002 * fTemp319) + ((0.00022545749999999999 * fTemp77) + ((0.018110405600000001 * fTemp204) + ((0.025859409399999998 * fTemp91) + ((0.0117039997 * fTemp98) + ((0.038671873900000001 * fTemp211) + ((0.0038706703000000002 * fTemp218) + ((0.0150346614 * fTemp236) + ((0.015640646000000001 * fTemp242) + ((0.018173488200000001 * fTemp104) + ((0.023318772000000001 * fTemp254) + ((0.0080516237999999993 * fTemp305) + ((0.1497976627 * fTemp130) + ((0.17263145490000001 * fTemp259) + ((0.017480803400000001 * fTemp264) + ((0.025752011200000001 * fTemp269) + ((0.020791580600000002 * fTemp299) + ((0.0047786171000000002 * fTemp124) + (((0.045931892699999997 * fTemp112) + (0.1051992492 * fTemp115)) + (0.0123406664 * fTemp283))))))))))))))))))))))))))))))) - ((0.070879514300000002 * fTemp147) + ((0.013426088900000001 * fTemp7) + ((0.0017645199000000001 * fTemp148) + ((0.0095467334000000001 * fTemp10) + ((0.011696887099999999 * fTemp11) + ((0.0122013157 * fTemp149) + ((0.015049353999999999 * fTemp13) + ((0.0079784567000000008 * fTemp14) + ((0.042959784600000002 * fTemp150) + ((0.022030698099999999 * fTemp146) + ((0.010349122400000001 * fTemp167) + ((0.049830539899999998 * fTemp30) + ((0.0066326131000000003 * fTemp38) + ((0.0155571084 * fTemp46) + ((0.0011507913000000001 * fTemp70) + ((0.0038009171 * fTemp175) + ((0.078929065199999995 * fTemp190) + ((0.0072708219999999997 * fTemp197) + ((0.0043133303000000003 * fTemp84) + ((0.022338310300000001 * fTemp312) + ((0.1500164564 * fTemp137) + ((0.093480284900000002 * fTemp224) + ((0.023340740400000001 * fTemp230) + (((0.0025229244999999999 * fTemp274) + (((0.075143735500000003 * fTemp108) + ((0.055497996700000003 * fTemp287) + ((0.024991681200000001 * fTemp294) + (((0.016273485099999999 * fTemp290) + (0.062160868000000001 * fTemp111)) + (0.13622281950000001 * fTemp119))))) + (0.044542254599999997 * fTemp279))) + (0.022723813400000001 * fTemp248))))))))))))))))))))))))));
			output12[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec12[((IOTA - iConst43) & 127)])));
			fVec13[(IOTA & 127)] = (((0.1043404196 * fTemp147) + ((0.023380013700000001 * fTemp7) + ((0.0070162779999999999 * fTemp9) + ((0.00013156880000000001 * fTemp11) + ((0.0026102528999999998 * fTemp146) + ((0.0140279011 * fTemp151) + ((0.016991158100000001 * fTemp22) + ((0.022503249999999999 * fTemp62) + (((0.022508560399999999 * fTemp204) + ((0.014112640799999999 * fTemp91) + ((0.031600371799999999 * fTemp98) + ((0.0075771587000000003 * fTemp211) + ((0.0172880069 * fTemp218) + ((0.12365718959999999 * fTemp137) + ((0.1389692713 * fTemp224) + ((0.032157000599999999 * fTemp236) + ((0.0014188155000000001 * fTemp242) + ((0.025779797100000001 * fTemp104) + ((0.0085298601999999994 * fTemp254) + ((0.044878932699999999 * fTemp305) + ((0.0827150943 * fTemp130) + ((0.061067870000000003 * fTemp259) + ((0.047650259799999997 * fTemp264) + ((0.0066472068000000004 * fTemp269) + ((0.013165396100000001 * fTemp274) + ((((0.0407238797 * fTemp112) + (0.1074623049 * fTemp115)) + (0.0053446837000000001 * fTemp283)) + (0.0112451892 * fTemp299))))))))))))))))))) + (0.033328668999999998 * fTemp175)))))))))) - ((0.0054923404999999998 * fTemp148) + ((0.037616388600000002 * fTemp8) + ((0.019166207000000001 * fTemp10) + ((0.016340723000000001 * fTemp149) + ((0.0076877487999999997 * fTemp12) + ((0.0056777564000000001 * fTemp13) + ((0.023432313900000001 * fTemp14) + ((0.024177768400000001 * fTemp150) + ((0.075553777700000005 * fTemp320) + ((0.1012267552 * fTemp159) + ((0.0055205658000000001 * fTemp167) + ((0.0159606204 * fTemp30) + ((0.027653216599999999 * fTemp38) + ((0.0034473707000000002 * fTemp46) + ((0.014696192199999999 * fTemp54) + ((0.0060254056000000004 * fTemp70) + ((0.0013658826999999999 * fTemp145) + ((0.0310179121 * fTemp183) + ((0.1057782317 * fTemp319) + ((0.098330445700000005 * fTemp190) + ((0.038691709300000002 * fTemp77) + ((0.0064504313999999997 * fTemp197) + ((0.0037155486000000001 * fTemp84) + ((0.017658922899999999 * fTemp312) + ((0.0156736338 * fTemp230) + (((0.049593489800000001 * fTemp279) + ((0.1434879446 * fTemp124) + ((0.1340098509 * fTemp108) + ((0.049736756799999997 * fTemp287) + ((0.044651880200000001 * fTemp294) + (((0.023145844799999999 * fTemp290) + (0.014483971700000001 * fTemp111)) + (0.036814384999999998 * fTemp119))))))) + (0.0049064156000000001 * fTemp248))))))))))))))))))))))))))));
			output13[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec13[((IOTA - iConst44) & 127)])));
			fVec14[(IOTA & 127)] = ((((((((((0.028290032900000001 * fTemp320) + ((0.0103679259 * fTemp167) + ((0.032515417599999999 * fTemp30) + ((0.0072612924999999997 * fTemp46) + ((0.0038182673999999999 * fTemp54) + ((0.0291460212 * fTemp62) + ((0.0066796277999999999 * fTemp70) + ((0.038037683599999997 * fTemp175) + ((0.0082513893000000001 * fTemp183) + ((0.153584368 * fTemp319) + ((0.16191537149999999 * fTemp190) + ((0.0079402194000000002 * fTemp197) + ((0.038754882499999997 * fTemp204) + ((0.0052375043999999997 * fTemp84) + ((0.025723142599999999 * fTemp91) + ((0.0116133368 * fTemp98) + ((0.0024129337000000002 * fTemp218) + ((0.022491199 * fTemp312) + ((0.050454637599999998 * fTemp137) + ((0.0937177124 * fTemp224) + ((0.022336460900000001 * fTemp230) + ((0.023367030800000001 * fTemp236) + ((0.018418988899999999 * fTemp104) + ((0.010995890100000001 * fTemp305) + ((((0.0304883564 * fTemp111) + ((0.046076517999999997 * fTemp112) + (0.118668385 * fTemp115))) + (0.075272632899999997 * fTemp119)) + (0.021019755300000002 * fTemp264)))))))))))))))))))))))))) + (0.014360520999999999 * fTemp146)) + (0.042949734900000001 * fTemp150)) + (0.0051770258999999999 * fTemp14)) + (0.0096316643000000004 * fTemp13)) + (0.018828635699999999 * fTemp12)) + (0.0022583894000000001 * fTemp11)) + (0.016826707699999999 * fTemp148)) - ((((((((0.013516893699999999 * fTemp151) + ((0.0067209556 * fTemp159) + ((0.018961556399999999 * fTemp22) + ((0.0014118647999999999 * fTemp38) + ((0.0042167821999999997 * fTemp145) + ((0.00034955499999999998 * fTemp77) + ((0.018051950300000001 * fTemp211) + ((0.0049546737000000004 * fTemp242) + ((0.027162351099999999 * fTemp248) + ((0.0151073049 * fTemp254) + ((0.14992786820000001 * fTemp130) + ((0.1188545692 * fTemp259) + ((0.0133415554 * fTemp269) + ((0.0025442787999999999 * fTemp274) + ((0.049791180400000003 * fTemp279) + ((0.017573826599999998 * fTemp299) + ((0.12575854680000001 * fTemp124) + ((0.13657774419999999 * fTemp108) + ((0.0089809396999999992 * fTemp283) + ((0.055553855499999999 * fTemp287) + ((0.016434371199999999 * fTemp290) + (0.026635282199999999 * fTemp294)))))))))))))))))))))) + (0.0124353395 * fTemp149)) + (0.015002740299999999 * fTemp10)) + (0.0059814198000000002 * fTemp9)) + (0.027939457800000001 * fTemp8)) + (0.013474999 * fTemp7)) + (0.12859185079999999 * fTemp147)));
			output14[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec14[((IOTA - iConst44) & 127)])));
			fVec15[(IOTA & 127)] = (((0.1272431168 * fTemp147) + ((0.0021015871999999999 * fTemp148) + ((0.037743878000000002 * fTemp8) + ((0.0191280887 * fTemp13) + ((0.011757824700000001 * fTemp14) + ((0.024095354999999999 * fTemp150) + ((0.0233943047 * fTemp151) + ((0.019926423200000001 * fTemp320) + ((0.1055142803 * fTemp159) + ((0.010013210599999999 * fTemp22) + ((0.0055178579999999996 * fTemp167) + ((0.034905683200000003 * fTemp30) + ((0.0135035196 * fTemp46) + ((0.018350354100000001 * fTemp62) + ((0.0277215863 * fTemp70) + ((0.0012801077 * fTemp145) + ((0.033873905099999997 * fTemp183) + ((0.0387138255 * fTemp77) + ((0.016737150400000001 * fTemp197) + ((0.0075614834000000001 * fTemp204) + ((0.0197724609 * fTemp84) + ((0.014159288000000001 * fTemp91) + ((0.0249741302 * fTemp98) + ((0.017562034399999999 * fTemp312) + ((0.042789270599999998 * fTemp230) + ((0.0084819856000000002 * fTemp236) + (((0.0111996747 * fTemp264) + ((0.0131488713 * fTemp274) + ((0.058570164600000002 * fTemp124) + (((0.065886647600000001 * fTemp111) + ((0.040786719499999999 * fTemp112) + (0.086322134800000005 * fTemp115))) + (0.1342300712 * fTemp119))))) + (0.025796904799999999 * fTemp104)))))))))))))))))))))))))))) - ((0.0138895909 * fTemp7) + ((0.021496886199999999 * fTemp9) + ((0.0056139518999999997 * fTemp10) + ((0.0053783857000000001 * fTemp11) + ((0.0163089784 * fTemp149) + ((0.0055005658000000001 * fTemp12) + ((0.0058023299999999996 * fTemp146) + ((0.0059478986999999999 * fTemp38) + ((0.0147187632 * fTemp54) + ((0.012400852400000001 * fTemp175) + ((0.10156793309999999 * fTemp319) + ((0.0183114069 * fTemp190) + ((0.0226160067 * fTemp211) + ((0.0077123364000000003 * fTemp218) + ((0.15703436039999999 * fTemp137) + ((0.13927332440000001 * fTemp224) + ((0.0025186606 * fTemp242) + ((0.0045237215999999998 * fTemp248) + ((0.032167257999999997 * fTemp254) + ((0.0207253469 * fTemp305) + ((0.082517210499999993 * fTemp130) + ((0.1447283945 * fTemp259) + ((0.030409230999999998 * fTemp269) + ((0.039777396299999997 * fTemp279) + (((0.036727913799999998 * fTemp108) + ((0.027842426999999999 * fTemp283) + ((0.049792349499999999 * fTemp287) + ((0.023175389800000001 * fTemp290) + (0.035371967599999998 * fTemp294))))) + (0.047693208299999998 * fTemp299)))))))))))))))))))))))))));
			output15[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec15[((IOTA - iConst45) & 127)])));
			fVec16[(IOTA & 127)] = (((0.0039926709999999997 * fTemp147) + ((0.0201999834 * fTemp7) + ((0.0196674581 * fTemp148) + ((0.0027278711999999998 * fTemp9) + ((0.016035579599999999 * fTemp10) + ((0.031029200100000001 * fTemp149) + ((0.0010690882 * fTemp320) + ((0.0118585819 * fTemp159) + ((0.0141543259 * fTemp22) + (((0.0063944604000000004 * fTemp190) + (((0.0042336205000000002 * fTemp248) + ((0.1048635136 * fTemp254) + ((0.0041447818000000004 * fTemp305) + ((0.045274177899999997 * fTemp269) + ((0.093574874200000005 * fTemp279) + ((0.1202940882 * fTemp299) + ((0.0052889347999999997 * fTemp124) + ((0.067786083900000002 * fTemp283) + ((0.024018279199999999 * fTemp287) + ((0.12224572190000001 * fTemp294) + (((0.040731515199999999 * fTemp111) + ((0.071391873699999997 * fTemp290) + ((0.070419014000000002 * fTemp115) + (0.038011396400000001 * fTemp112)))) + (0.069363888799999995 * fTemp119)))))))))))) + (0.030090476200000001 * fTemp211))) + (0.0086491183999999992 * fTemp54))))))))))) - ((0.0090428409999999994 * fTemp8) + ((0.0022791012 * fTemp11) + ((0.018654746100000001 * fTemp12) + ((0.047683692799999997 * fTemp13) + ((0.0288682343 * fTemp14) + ((0.049596291000000001 * fTemp150) + ((0.043029529800000001 * fTemp146) + ((0.0089648273000000004 * fTemp151) + ((0.040831345800000002 * fTemp167) + ((0.059998209500000003 * fTemp30) + ((0.0027948386999999998 * fTemp38) + ((0.036707691600000002 * fTemp46) + ((0.064678272499999995 * fTemp62) + ((0.0380987427 * fTemp70) + ((0.022871921699999999 * fTemp175) + ((0.072456232800000006 * fTemp145) + ((0.045576220600000002 * fTemp183) + ((0.0056906066000000002 * fTemp319) + ((0.0475368101 * fTemp77) + ((0.11497858919999999 * fTemp197) + ((0.0418104989 * fTemp204) + ((0.046797434800000003 * fTemp84) + ((0.0497667574 * fTemp91) + ((0.065501180800000003 * fTemp98) + ((0.0074006324999999996 * fTemp218) + ((0.064942065300000004 * fTemp312) + ((0.0258053026 * fTemp137) + ((0.028000909000000001 * fTemp224) + ((0.1145065529 * fTemp230) + ((0.073002388500000001 * fTemp236) + ((0.010158956300000001 * fTemp242) + ((0.087137983000000002 * fTemp104) + ((0.033978180400000002 * fTemp130) + ((0.062968760900000004 * fTemp259) + ((0.0702121629 * fTemp264) + ((0.037380876299999997 * fTemp108) + (0.054973781899999997 * fTemp274))))))))))))))))))))))))))))))))))))));
			output16[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec16[((IOTA - iConst46) & 127)])));
			fVec17[(IOTA & 127)] = (((0.0017626132 * fTemp147) + ((0.0083576984999999999 * fTemp7) + ((0.0186796467 * fTemp148) + ((0.014233516599999999 * fTemp8) + ((0.0020074826999999999 * fTemp11) + ((0.053276281799999999 * fTemp149) + ((0.047764573999999997 * fTemp150) + ((0.052022434100000001 * fTemp146) + ((0.024331470000000001 * fTemp151) + ((0.0043099838999999997 * fTemp320) + ((0.0055724470000000003 * fTemp159) + ((0.023440287399999999 * fTemp22) + ((0.044592842299999998 * fTemp167) + ((0.021937387400000001 * fTemp30) + ((0.0352789981 * fTemp54) + ((0.039909270900000002 * fTemp175) + ((0.072182524299999995 * fTemp145) + ((0.046306349199999999 * fTemp183) + ((0.013214867 * fTemp319) + ((0.0142086405 * fTemp190) + ((0.049669808699999998 * fTemp77) + ((0.073078142400000004 * fTemp197) + ((0.0073126748999999998 * fTemp204) + ((0.016192743400000001 * fTemp211) + ((0.073652078600000004 * fTemp218) + ((0.065128708600000002 * fTemp312) + ((0.0241925087 * fTemp137) + ((0.028821366599999999 * fTemp224) + ((0.082303723699999998 * fTemp230) + ((0.085731005900000004 * fTemp236) + ((0.052281072900000003 * fTemp254) + ((0.071048121300000003 * fTemp305) + ((0.034112062999999998 * fTemp130) + ((0.047697994600000002 * fTemp259) + ((0.1082953167 * fTemp264) + ((0.064697349799999998 * fTemp269) + ((0.019567569399999998 * fTemp279) + ((0.057503765200000001 * fTemp299) + ((0.038209709600000002 * fTemp124) + ((0.064499198699999996 * fTemp108) + ((0.1100413943 * fTemp283) + ((0.0055090701000000001 * fTemp287) + ((0.028149608100000001 * fTemp294) + ((0.032291960100000003 * fTemp119) + ((0.068042738800000002 * fTemp111) + ((0.0533641272 * fTemp290) + ((0.0306211721 * fTemp112) + (0.016552897800000001 * fTemp115)))))))))))))))))))))))))))))))))))))))))))))))) - ((0.027380326300000001 * fTemp9) + ((0.061097380399999998 * fTemp10) + ((0.0059091687999999996 * fTemp12) + ((0.034359653499999997 * fTemp13) + ((0.0039529198000000003 * fTemp14) + ((0.058844398200000002 * fTemp38) + ((0.071826815099999997 * fTemp46) + ((0.021711689999999999 * fTemp62) + ((0.022091027499999999 * fTemp70) + ((0.098391668400000007 * fTemp84) + ((0.028606388699999999 * fTemp91) + (((0.036044131799999997 * fTemp242) + ((0.079673439600000007 * fTemp104) + ((0.063294942800000004 * fTemp274) + (0.0043342603 * fTemp248)))) + (0.022909782199999999 * fTemp98))))))))))))));
			output17[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec17[((IOTA - iConst46) & 127)])));
			fVec18[(IOTA & 127)] = (((0.028852915 * fTemp9) + ((0.0310411058 * fTemp149) + ((0.0023283465 * fTemp12) + ((0.047733121900000001 * fTemp13) + ((0.0027240950000000002 * fTemp14) + ((0.0089884205999999998 * fTemp151) + ((0.0040253051000000003 * fTemp320) + ((0.022857013900000001 * fTemp30) + ((0.0028026773 * fTemp38) + ((0.0086214016999999997 * fTemp54) + ((0.036753430400000002 * fTemp62) + ((0.0380934697 * fTemp70) + ((0.0057154739000000003 * fTemp319) + ((0.0073981732999999997 * fTemp197) + ((0.041825001200000003 * fTemp204) + (((0.0730098208 * fTemp236) + ((0.00427196 * fTemp242) + (((0.0702060563 * fTemp264) + (((0.037372044600000001 * fTemp108) + ((0.1222313142 * fTemp283) + (((0.070400406499999998 * fTemp111) + ((0.038002752799999998 * fTemp112) + (0.071384467300000004 * fTemp290))) + (0.024035194700000002 * fTemp287)))) + (0.093594236999999997 * fTemp269))) + (0.0101406967 * fTemp248)))) + (0.046806107800000003 * fTemp98))))))))))))))))) - ((0.0010394667 * fTemp147) + ((0.020202636 * fTemp7) + ((0.043045385899999997 * fTemp148) + ((0.0090662060000000003 * fTemp8) + ((0.016030583300000002 * fTemp10) + ((0.018683046500000001 * fTemp11) + ((0.049619550700000001 * fTemp150) + ((0.019690576099999999 * fTemp146) + ((0.0118532867 * fTemp159) + ((0.045583768199999999 * fTemp22) + ((0.040840608100000002 * fTemp167) + ((0.064707459499999995 * fTemp46) + ((0.060035029199999999 * fTemp175) + ((0.072483714500000004 * fTemp145) + ((0.014155940800000001 * fTemp183) + ((0.025806042099999999 * fTemp190) + ((0.047533985799999998 * fTemp77) + ((0.065490446100000002 * fTemp84) + ((0.049805494899999997 * fTemp91) + ((0.030129419599999999 * fTemp211) + ((0.1150033816 * fTemp218) + ((0.064948325099999996 * fTemp312) + ((0.0063845550999999997 * fTemp137) + ((0.027996421699999999 * fTemp224) + ((0.0041402097000000004 * fTemp230) + ((0.0871444725 * fTemp104) + ((0.1048835318 * fTemp254) + ((0.11450058220000001 * fTemp305) + ((0.033971424600000001 * fTemp130) + ((0.0052855645000000001 * fTemp259) + ((0.054949432499999999 * fTemp274) + ((0.045284256799999999 * fTemp279) + ((0.120279476 * fTemp299) + ((0.062953242500000006 * fTemp124) + ((0.067775739400000007 * fTemp294) + ((0.040719139299999998 * fTemp115) + (0.069343358699999996 * fTemp119))))))))))))))))))))))))))))))))))))));
			output18[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec18[((IOTA - iConst46) & 127)])));
			fVec19[(IOTA & 127)] = (((0.051981864599999997 * fTemp148) + ((0.0142063902 * fTemp8) + ((0.0038959339000000002 * fTemp9) + ((0.061079201 * fTemp10) + ((0.053238720099999998 * fTemp149) + ((0.034311255700000001 * fTemp13) + ((0.047712846400000002 * fTemp150) + ((0.0016841637 * fTemp320) + ((0.046306332399999997 * fTemp22) + ((0.044590881499999999 * fTemp167) + ((0.058853132099999997 * fTemp38) + ((0.035248227200000003 * fTemp54) + ((0.071814388100000001 * fTemp62) + ((0.022018603300000002 * fTemp70) + ((0.021894563499999999 * fTemp175) + ((0.072130878100000004 * fTemp145) + ((0.0242062654 * fTemp190) + ((0.049674152100000001 * fTemp77) + ((0.098379142500000002 * fTemp98) + ((0.073068349199999993 * fTemp218) + ((0.065107283700000004 * fTemp312) + ((0.028822862599999999 * fTemp224) + ((0.036036336600000003 * fTemp248) + ((0.082316823499999997 * fTemp305) + ((0.0341125397 * fTemp130) + ((0.019581777799999998 * fTemp269) + ((0.047710902999999999 * fTemp124) + ((0.028150457199999999 * fTemp283) + (((0.016550943200000001 * fTemp111) + ((0.030631296299999999 * fTemp112) + (0.053382876199999998 * fTemp290))) + (0.0055179063999999996 * fTemp287)))))))))))))))))))))))))))))) - ((0.0043230131000000002 * fTemp147) + ((0.0082907333999999999 * fTemp7) + ((0.0059492013 * fTemp11) + ((0.0019915114999999998 * fTemp12) + ((0.027433833500000001 * fTemp14) + ((0.018683052200000001 * fTemp146) + ((0.024351716400000001 * fTemp151) + ((0.0055200598000000002 * fTemp159) + ((0.039913482600000001 * fTemp30) + ((0.0217096411 * fTemp46) + ((0.023419229900000001 * fTemp183) + ((0.0132350418 * fTemp319) + ((0.0736226933 * fTemp197) + ((0.0072948364999999996 * fTemp204) + ((0.022877380999999999 * fTemp84) + ((0.028620153799999999 * fTemp91) + ((0.016235548999999998 * fTemp211) + ((0.0141870746 * fTemp137) + ((0.071022644300000007 * fTemp230) + ((0.085731476200000004 * fTemp236) + ((0.0043025155000000004 * fTemp242) + ((0.079680596500000006 * fTemp104) + (((0.038201092999999998 * fTemp259) + ((0.1083150329 * fTemp264) + ((0.063298276000000001 * fTemp274) + ((0.064715528600000002 * fTemp279) + (((0.064516527800000001 * fTemp108) + ((0.1100701746 * fTemp294) + ((0.068062192199999996 * fTemp115) + (0.032284151099999998 * fTemp119)))) + (0.057491693699999999 * fTemp299)))))) + (0.0522847148 * fTemp254)))))))))))))))))))))))));
			output19[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec19[((IOTA - iConst46) & 127)])));
			fVec20[(IOTA & 127)] = (((0.020210879099999999 * fTemp7) + ((0.0160516814 * fTemp10) + ((0.0022764781000000002 * fTemp11) + ((0.0309776688 * fTemp149) + ((0.018698904299999999 * fTemp12) + ((0.0289086723 * fTemp14) + ((0.043103839499999998 * fTemp146) + ((0.011849361100000001 * fTemp159) + ((0.0600184567 * fTemp30) + ((0.0366770872 * fTemp46) + ((0.0085917635000000003 * fTemp54) + ((0.064663743699999998 * fTemp62) + ((0.022916585999999999 * fTemp175) + ((0.0456294265 * fTemp183) + ((0.114995571 * fTemp197) + ((0.046766572899999997 * fTemp84) + ((0.065430889300000003 * fTemp98) + ((0.030094396999999998 * fTemp211) + ((0.0073937598999999996 * fTemp218) + ((0.025825992799999999 * fTemp137) + ((0.1145043437 * fTemp230) + ((0.0101488086 * fTemp242) + (((0.062959801400000001 * fTemp259) + (((0.024036521700000001 * fTemp287) + (((0.037999764599999999 * fTemp112) + (0.071377611199999996 * fTemp290)) + (0.069357866800000001 * fTemp119))) + (0.1202824868 * fTemp299))) + (0.1048542385 * fTemp254)))))))))))))))))))))))) - ((0.0039789159000000003 * fTemp147) + ((0.019677195500000001 * fTemp148) + ((0.0090375374000000001 * fTemp8) + ((0.0027401029000000002 * fTemp9) + ((0.0476628147 * fTemp13) + ((0.049647475099999998 * fTemp150) + ((0.0089926017 * fTemp151) + ((0.0010524529 * fTemp320) + ((0.0141228723 * fTemp22) + ((0.040878079300000002 * fTemp167) + ((0.0028365853000000001 * fTemp38) + ((0.038080408699999999 * fTemp70) + ((0.072490549599999995 * fTemp145) + ((0.0057107457000000004 * fTemp319) + ((0.0063608405000000002 * fTemp190) + ((0.047602963599999999 * fTemp77) + ((0.041861726199999998 * fTemp204) + ((0.049777326199999999 * fTemp91) + ((0.064932673100000005 * fTemp312) + ((0.028043553999999998 * fTemp224) + ((0.073005793499999999 * fTemp236) + ((0.087095462100000007 * fTemp104) + ((0.0042976118000000001 * fTemp248) + ((0.0041961758000000002 * fTemp305) + ((0.0339556414 * fTemp130) + ((0.070170791999999996 * fTemp264) + ((0.045266623899999997 * fTemp269) + ((0.054921770000000002 * fTemp274) + ((0.093581303099999999 * fTemp279) + ((0.0053327195000000003 * fTemp124) + ((0.037343894099999997 * fTemp108) + ((0.067775720299999995 * fTemp283) + (((0.070388008899999993 * fTemp115) + (0.040726760399999999 * fTemp111)) + (0.12220778309999999 * fTemp294)))))))))))))))))))))))))))))))))));
			output20[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec20[((IOTA - iConst46) & 127)])));
			fVec21[(IOTA & 127)] = (((0.0082788931000000003 * fTemp7) + ((0.0142592672 * fTemp8) + ((0.0274052358 * fTemp9) + ((0.053263672400000003 * fTemp149) + ((0.0059115425000000003 * fTemp12) + ((0.0039156258999999997 * fTemp14) + ((0.047760973599999999 * fTemp150) + ((0.024319090099999999 * fTemp151) + ((0.0055229197000000001 * fTemp159) + ((0.044600697699999997 * fTemp167) + ((0.071783693300000007 * fTemp46) + ((0.035300383400000003 * fTemp54) + ((0.021675314800000001 * fTemp62) + ((0.072177164899999993 * fTemp145) + ((0.013209058900000001 * fTemp319) + ((0.0496561924 * fTemp77) + ((0.0072811964000000003 * fTemp204) + ((0.098387016999999993 * fTemp84) + ((0.0228765763 * fTemp98) + ((0.016183017800000001 * fTemp211) + ((0.065142028500000004 * fTemp312) + ((0.028806551999999999 * fTemp224) + ((0.085715838500000002 * fTemp236) + ((0.036075632699999999 * fTemp242) + ((0.0043294913000000001 * fTemp248) + ((0.052249432700000001 * fTemp254) + ((0.034129172499999999 * fTemp130) + ((0.1082990353 * fTemp264) + (((0.064507223000000002 * fTemp108) + ((0.0054927342000000001 * fTemp287) + (((0.0306194443 * fTemp112) + (0.053354718400000001 * fTemp290)) + (0.0322900754 * fTemp119)))) + (0.057486007700000001 * fTemp299)))))))))))))))))))))))))))))) - ((0.0017207385 * fTemp147) + ((0.018654249000000001 * fTemp148) + ((0.061103699599999999 * fTemp10) + ((0.0020531430999999999 * fTemp11) + ((0.034283363800000001 * fTemp13) + ((0.052030989200000002 * fTemp146) + ((0.0042851616999999998 * fTemp320) + ((0.023387818000000001 * fTemp22) + ((0.021935633499999999 * fTemp30) + ((0.058872026399999999 * fTemp38) + ((0.022045015300000002 * fTemp70) + ((0.039890292700000003 * fTemp175) + ((0.046318982600000003 * fTemp183) + ((0.0141708322 * fTemp190) + ((0.073087242100000005 * fTemp197) + ((0.0285649984 * fTemp91) + ((0.073623973999999995 * fTemp218) + ((0.024204461300000001 * fTemp137) + ((0.082312175400000007 * fTemp230) + ((0.079647853399999996 * fTemp104) + ((0.071043614099999999 * fTemp305) + ((0.047701833200000002 * fTemp259) + ((0.064664790999999999 * fTemp269) + ((0.063299092400000007 * fTemp274) + ((0.019553603499999999 * fTemp279) + ((0.038218625200000002 * fTemp124) + ((0.11003032159999999 * fTemp283) + (((0.016548580800000001 * fTemp115) + (0.068044421800000005 * fTemp111)) + (0.028137084600000001 * fTemp294))))))))))))))))))))))))))))));
			output21[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec21[((IOTA - iConst46) & 127)])));
			fVec22[(IOTA & 127)] = (((0.0010625246 * fTemp147) + ((0.043045095899999997 * fTemp148) + ((0.018570661400000001 * fTemp11) + ((0.0310612054 * fTemp149) + ((0.047663176500000001 * fTemp13) + ((0.019637951599999998 * fTemp146) + ((0.0090084712999999993 * fTemp151) + ((0.0455812762 * fTemp22) + ((0.0027691412999999998 * fTemp38) + ((0.064636786900000007 * fTemp46) + ((0.0086795263000000004 * fTemp54) + ((0.038063687700000001 * fTemp70) + ((0.060014399099999997 * fTemp175) + ((0.0141475218 * fTemp183) + ((0.0057046413000000004 * fTemp319) + ((0.025804003999999998 * fTemp190) + ((0.041807703600000003 * fTemp204) + ((0.065470731399999996 * fTemp84) + ((0.1149951402 * fTemp218) + ((0.0063982583999999997 * fTemp137) + ((0.0041004887 * fTemp230) + ((0.073033457100000004 * fTemp236) + ((0.1145119819 * fTemp305) + ((0.0052570658000000003 * fTemp259) + ((0.070254434500000004 * fTemp264) + ((0.045294227200000002 * fTemp279) + ((0.062967061899999996 * fTemp124) + ((0.037406373 * fTemp108) + ((0.024061545 * fTemp287) + (((0.071420472099999993 * fTemp290) + ((0.038020542300000001 * fTemp112) + (0.0407218497 * fTemp115))) + (0.067781079499999994 * fTemp294))))))))))))))))))))))))))))))) - ((0.020202592299999999 * fTemp7) + ((0.0090734610999999993 * fTemp8) + ((0.028819032299999998 * fTemp9) + ((0.016044867899999999 * fTemp10) + ((0.0022582491 * fTemp12) + ((0.0027275518000000002 * fTemp14) + ((0.049585686099999998 * fTemp150) + ((0.0040182975000000003 * fTemp320) + ((0.011862200200000001 * fTemp159) + ((0.040833476799999997 * fTemp167) + ((0.0228463421 * fTemp30) + ((0.036685820899999999 * fTemp62) + ((0.072462844100000007 * fTemp145) + ((0.047515727899999999 * fTemp77) + ((0.0074199701000000002 * fTemp197) + ((0.049747779300000003 * fTemp91) + ((0.046759442900000003 * fTemp98) + ((0.030130829200000001 * fTemp211) + ((0.0649565738 * fTemp312) + ((0.027981421100000001 * fTemp224) + ((0.0042768677999999996 * fTemp242) + ((0.087112857099999996 * fTemp104) + ((0.010117339499999999 * fTemp248) + ((0.1048814014 * fTemp254) + ((0.033988066999999997 * fTemp130) + ((0.093623455100000003 * fTemp269) + ((0.054933005700000002 * fTemp274) + (((0.12228017099999999 * fTemp283) + ((0.070432630699999998 * fTemp111) + (0.069349797699999993 * fTemp119))) + (0.12028478419999999 * fTemp299))))))))))))))))))))))))))))));
			output22[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec22[((IOTA - iConst46) & 127)])));
			fVec23[(IOTA & 127)] = (((0.0043127755000000002 * fTemp147) + ((0.014261661700000001 * fTemp8) + ((0.061118446700000002 * fTemp10) + ((0.0059160254999999998 * fTemp11) + ((0.053282586600000001 * fTemp149) + ((0.0020000769999999998 * fTemp12) + ((0.034340739199999998 * fTemp13) + ((0.027382893700000001 * fTemp14) + ((0.0477321406 * fTemp150) + ((0.0186814992 * fTemp146) + ((0.044581874100000002 * fTemp167) + ((0.039901425599999998 * fTemp30) + ((0.058836390600000003 * fTemp38) + ((0.021711588800000001 * fTemp46) + ((0.035264581000000003 * fTemp54) + ((0.022082187999999999 * fTemp70) + ((0.072169944599999994 * fTemp145) + ((0.023392970900000001 * fTemp183) + ((0.049614387400000001 * fTemp77) + ((0.073661101600000001 * fTemp197) + ((0.022911082900000001 * fTemp84) + ((0.065139645199999999 * fTemp312) + ((0.0141639551 * fTemp137) + ((0.028772314300000001 * fTemp224) + ((0.071074450600000005 * fTemp230) + ((0.0043325257000000001 * fTemp242) + ((0.034126342599999998 * fTemp130) + ((0.0382310846 * fTemp259) + (((0.0055321232 * fTemp287) + (((0.053373362100000002 * fTemp290) + ((0.0306213415 * fTemp112) + (0.068032778700000004 * fTemp115))) + (0.1100449557 * fTemp294))) + (0.0647337729 * fTemp279)))))))))))))))))))))))))))))) - ((0.0083258150000000003 * fTemp7) + ((0.051999526300000001 * fTemp148) + ((0.0039512311 * fTemp9) + ((0.024329822099999999 * fTemp151) + ((0.0017424923999999999 * fTemp320) + ((0.0055388418000000003 * fTemp159) + ((0.046305671100000001 * fTemp22) + ((0.071853804399999999 * fTemp62) + ((0.021960169799999998 * fTemp175) + ((0.0132177457 * fTemp319) + ((0.024199353100000001 * fTemp190) + ((0.0073486037999999998 * fTemp204) + ((0.028639465900000001 * fTemp91) + ((0.098388445399999996 * fTemp98) + ((0.016199443899999999 * fTemp211) + ((0.073071023900000004 * fTemp218) + ((0.085746373599999995 * fTemp236) + ((0.079689907700000007 * fTemp104) + ((0.036002602299999999 * fTemp248) + ((0.052302601400000003 * fTemp254) + ((0.082256332400000007 * fTemp305) + ((0.10827217460000001 * fTemp264) + ((0.019580840400000001 * fTemp269) + ((0.063280135000000001 * fTemp274) + ((0.057536119900000002 * fTemp299) + ((0.0476547056 * fTemp124) + ((0.064471198499999993 * fTemp108) + ((0.0281700179 * fTemp283) + ((0.016565980500000001 * fTemp111) + (0.032314148199999997 * fTemp119)))))))))))))))))))))))))))))));
			output23[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec23[((IOTA - iConst46) & 127)])));
			fVec24[0] = (((0.0107613147 * fTemp148) + ((0.038650755799999999 * fTemp9) + ((0.022083609099999998 * fTemp12) + ((0.0010312278000000001 * fTemp150) + ((0.0046679911000000003 * fTemp151) + ((0.0053892753999999999 * fTemp22) + ((0.037116086100000001 * fTemp30) + ((0.071899315500000005 * fTemp62) + ((0.0013063155999999999 * fTemp145) + ((0.0015313633000000001 * fTemp319) + (((((0.00089786689999999997 * fTemp312) + ((0.016275781199999999 * fTemp230) + ((0.0350328351 * fTemp104) + ((0.1489226551 * fTemp248) + ((0.00036988659999999998 * fTemp130) + ((0.0062344825999999997 * fTemp259) + ((0.083723758600000003 * fTemp274) + (((0.10635739380000001 * fTemp287) + (((0.088532238999999999 * fTemp290) + ((0.034354885699999997 * fTemp112) + (0.039881849099999998 * fTemp115))) + (0.094799970499999997 * fTemp294))) + (0.13847193469999999 * fTemp279))))))))) + (0.1219692379 * fTemp98)) + (0.028164928200000001 * fTemp197)) + (0.0018380651999999999 * fTemp190)))))))))))) - ((0.00051111530000000002 * fTemp147) + ((0.0008531697 * fTemp7) + ((0.0021115942000000001 * fTemp8) + ((0.0523673162 * fTemp10) + ((0.0254600101 * fTemp11) + ((0.053051593399999999 * fTemp149) + ((0.0586536774 * fTemp13) + ((0.021421420100000001 * fTemp14) + ((0.0017050991999999999 * fTemp146) + ((0.0003231493 * fTemp320) + ((0.00026841849999999998 * fTemp159) + ((0.0014685182999999999 * fTemp167) + ((0.074635780600000007 * fTemp38) + ((0.042380235799999999 * fTemp46) + ((0.0475891518 * fTemp54) + ((0.071792914099999994 * fTemp70) + ((0.0216072564 * fTemp175) + ((0.00094315149999999999 * fTemp183) + ((((((((0.00034342390000000002 * fTemp137) + ((0.00028330519999999999 * fTemp224) + ((0.066697567200000002 * fTemp236) + ((0.062940663100000002 * fTemp242) + ((0.056906549700000003 * fTemp254) + ((0.0099615417999999994 * fTemp305) + ((0.041734716800000002 * fTemp264) + ((0.055250673600000001 * fTemp269) + ((0.034670622700000001 * fTemp299) + ((0.0038678001999999999 * fTemp124) + ((0.016917791000000001 * fTemp108) + ((0.036598682600000002 * fTemp283) + ((0.015116001299999999 * fTemp111) + (0.013823488599999999 * fTemp119)))))))))))))) + (0.016898055799999999 * fTemp218)) + (0.071325131999999999 * fTemp211)) + (0.015650774700000002 * fTemp91)) + (0.057334568599999997 * fTemp84)) + (0.080026943399999995 * fTemp204)) + (0.0007866444 * fTemp77)))))))))))))))))))));
			output24[i] = FAUSTFLOAT((0.99644194756554305 * (fVec24[iConst47] * fRec0[0])));
			fVec25[0] = (((0.00032829039999999999 * fTemp147) + ((0.00085618119999999998 * fTemp7) + ((0.021323585700000001 * fTemp9) + ((0.052295665800000002 * fTemp10) + ((0.0220768927 * fTemp11) + ((0.0253763919 * fTemp12) + ((0.058603265100000003 * fTemp13) + ((0.038562451599999999 * fTemp14) + ((0.0009799543 * fTemp150) + ((0.0002700275 * fTemp159) + ((0.021522796600000001 * fTemp30) + ((0.074564049800000004 * fTemp38) + ((0.071927905200000003 * fTemp46) + ((0.042322893399999999 * fTemp62) + ((0.071748967600000005 * fTemp70) + ((0.037038816600000003 * fTemp175) + ((0.0012778684000000001 * fTemp145) + ((0.0168388667 * fTemp197) + ((0.079959720799999995 * fTemp204) + ((0.1220212334 * fTemp84) + ((0.057299954799999997 * fTemp98) + ((0.071284875299999995 * fTemp211) + ((0.028111043799999999 * fTemp218) + ((0.00088688120000000002 * fTemp312) + ((0.0099293989000000006 * fTemp230) + ((0.0666431309 * fTemp236) + ((0.14897413879999999 * fTemp242) + ((0.035059241200000001 * fTemp104) + ((0.062919761599999999 * fTemp248) + ((0.056873225600000001 * fTemp254) + ((0.0162470501 * fTemp305) + ((0.0003674145 * fTemp130) + ((0.0038560680999999999 * fTemp259) + ((0.041700136399999997 * fTemp264) + ((0.13850598359999999 * fTemp269) + ((0.083775584400000006 * fTemp274) + ((0.055236739799999997 * fTemp279) + ((0.034648934300000003 * fTemp299) + ((0.0062242631999999999 * fTemp124) + ((0.0169033884 * fTemp108) + ((0.094814867900000002 * fTemp283) + ((0.106411387 * fTemp287) + ((0.036589704399999999 * fTemp294) + (((0.039885551200000001 * fTemp111) + ((0.088570217199999995 * fTemp290) + ((0.034368230399999998 * fTemp112) + (0.015112081600000001 * fTemp115)))) + (0.0138143112 * fTemp119))))))))))))))))))))))))))))))))))))))))))))) - ((0.0017109121 * fTemp148) + ((0.0021465634999999999 * fTemp8) + ((0.053098159499999999 * fTemp149) + ((0.0107495083 * fTemp146) + ((0.0046514049999999999 * fTemp151) + ((0.00050549419999999996 * fTemp320) + ((0.00094608989999999998 * fTemp22) + ((0.0014928806 * fTemp167) + ((0.0476347217 * fTemp54) + ((0.0053798242999999997 * fTemp183) + ((0.0015253681000000001 * fTemp319) + ((0.00034429980000000001 * fTemp190) + ((0.0007991993 * fTemp77) + ((0.015664354500000002 * fTemp91) + ((0.00028756579999999999 * fTemp224) + (0.0018336099 * fTemp137)))))))))))))))));
			output25[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec25[iConst47])));
			fVec26[0] = (((0.00051645700000000001 * fTemp147) + ((0.025305222299999999 * fTemp11) + ((0.021334878200000001 * fTemp14) + ((0.0010679193 * fTemp150) + ((0.0017114617999999999 * fTemp146) + ((0.0046429573999999998 * fTemp151) + ((0.00031931519999999999 * fTemp320) + ((0.042258923300000001 * fTemp46) + ((0.021580580799999999 * fTemp175) + ((0.0013762603999999999 * fTemp145) + ((0.00095165600000000005 * fTemp183) + ((0.0015219953 * fTemp319) + ((0.057250342000000003 * fTemp84) + ((0.016911639400000001 * fTemp218) + ((0.00095683870000000002 * fTemp312) + ((0.00034784239999999998 * fTemp137) + ((0.062888960399999999 * fTemp242) + ((0.035041661100000003 * fTemp104) + ((0.0099851135000000001 * fTemp305) + ((0.00039784089999999998 * fTemp130) + ((0.055223153599999998 * fTemp269) + ((0.083737399099999998 * fTemp274) + ((0.0038815699 * fTemp124) + ((0.036586640400000002 * fTemp283) + (((0.0151123496 * fTemp111) + ((0.034361336499999999 * fTemp112) + (0.088548185599999996 * fTemp290))) + (0.10637524499999999 * fTemp287)))))))))))))))))))))))))) - ((0.00082550069999999998 * fTemp7) + ((0.0106728164 * fTemp148) + ((0.0020763011 * fTemp8) + ((0.038606718399999997 * fTemp9) + ((0.052302689399999998 * fTemp10) + ((0.053030549599999997 * fTemp149) + ((0.022167124199999999 * fTemp12) + ((0.058645916399999998 * fTemp13) + ((0.00025761179999999999 * fTemp159) + ((0.0053294019999999996 * fTemp22) + ((0.0014357327999999999 * fTemp167) + ((0.037118971799999997 * fTemp30) + ((0.0745752742 * fTemp38) + ((0.047575907700000003 * fTemp54) + ((0.071958571200000002 * fTemp62) + ((0.071798333500000006 * fTemp70) + ((0.0018129146999999999 * fTemp190) + ((0.0007648927 * fTemp77) + ((0.0281986283 * fTemp197) + ((0.0799987796 * fTemp204) + ((0.0156424137 * fTemp91) + ((0.1220141159 * fTemp98) + ((0.071343861199999997 * fTemp211) + ((0.00027412310000000001 * fTemp224) + ((0.016311194099999999 * fTemp230) + ((0.066701710999999997 * fTemp236) + ((0.14896404229999999 * fTemp248) + (((0.0062531050000000001 * fTemp259) + ((0.041751650299999998 * fTemp264) + ((0.13851131250000001 * fTemp279) + (((0.0169290993 * fTemp108) + ((0.094829860399999993 * fTemp294) + ((0.039895589600000003 * fTemp115) + (0.0138333298 * fTemp119)))) + (0.034691040700000002 * fTemp299))))) + (0.0569313709 * fTemp254))))))))))))))))))))))))))))));
			output26[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec26[iConst47])));
			fVec27[0] = (((0.00083903600000000004 * fTemp7) + ((0.0017302127999999999 * fTemp148) + ((0.052341656799999997 * fTemp10) + ((0.058648183200000002 * fTemp13) + ((0.00099093079999999995 * fTemp150) + ((0.0107476759 * fTemp146) + ((0.00051052879999999995 * fTemp320) + ((0.00026279560000000001 * fTemp159) + ((0.00096254070000000003 * fTemp22) + ((0.074604449599999997 * fTemp38) + ((0.071789134399999996 * fTemp70) + ((0.0012941545 * fTemp145) + ((0.0053785428000000003 * fTemp183) + ((0.00035212850000000001 * fTemp190) + ((0.079994080300000006 * fTemp204) + ((0.071334030600000001 * fTemp211) + ((0.00089944120000000002 * fTemp312) + ((0.0018331738000000001 * fTemp137) + ((0.066669185399999997 * fTemp236) + ((0.035041152300000003 * fTemp104) + ((0.056925988300000001 * fTemp254) + ((0.00037305740000000002 * fTemp130) + ((0.0417159904 * fTemp264) + ((0.083761760599999999 * fTemp274) + (((0.016909811800000001 * fTemp108) + ((0.10641176920000001 * fTemp287) + (((0.034373545499999998 * fTemp112) + (0.088579545900000001 * fTemp290)) + (0.0138334818 * fTemp119)))) + (0.034689685300000002 * fTemp299)))))))))))))))))))))))))) - ((0.00032171400000000002 * fTemp147) + ((0.0021428520000000002 * fTemp8) + ((0.0213596151 * fTemp9) + ((0.022086618799999999 * fTemp11) + ((0.053060559100000002 * fTemp149) + ((0.025426749700000001 * fTemp12) + ((0.038584060500000003 * fTemp14) + ((0.0046575846000000004 * fTemp151) + ((0.0015045161 * fTemp167) + ((0.021541909800000002 * fTemp30) + ((0.071920919299999997 * fTemp46) + ((0.047614389999999999 * fTemp54) + ((0.042353747999999997 * fTemp62) + ((0.037073559700000001 * fTemp175) + ((0.0015278881000000001 * fTemp319) + ((0.00081297539999999999 * fTemp77) + ((0.016842529299999999 * fTemp197) + ((0.122013476 * fTemp84) + ((0.0156685313 * fTemp91) + ((0.057324708100000003 * fTemp98) + ((0.0281500428 * fTemp218) + ((0.00029503379999999999 * fTemp224) + ((0.0099259281000000001 * fTemp230) + ((0.1489803931 * fTemp242) + ((0.062950191899999994 * fTemp248) + ((0.0162765489 * fTemp305) + ((0.0038529318999999999 * fTemp259) + ((0.13852682529999999 * fTemp269) + ((0.0552722961 * fTemp279) + ((0.0062378497 * fTemp124) + ((0.0948377101 * fTemp283) + (((0.015126289899999999 * fTemp115) + (0.0398976973 * fTemp111)) + (0.036619387000000003 * fTemp294))))))))))))))))))))))))))))))))));
			output27[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec27[iConst47])));
			output28[i] = FAUSTFLOAT((fRec0[0] * (((3.2643900000000001e-05 * fTemp9) + ((0.0001168735 * fTemp10) + ((0.1103310052 * fTemp149) + ((0.00014157850000000001 * fTemp12) + ((1.0553100000000001e-05 * fTemp13) + ((6.3477699999999997e-05 * fTemp14) + ((0.00063428699999999998 * fTemp150) + ((2.114e-07 * fTemp151) + ((1.2299999999999999e-08 * fTemp320) + ((2.05631e-05 * fTemp30) + ((8.5221200000000003e-05 * fTemp38) + ((0.1077178359 * fTemp54) + ((0.0001357823 * fTemp62) + ((1.06448e-05 * fTemp70) + ((3.7452900000000002e-05 * fTemp175) + ((0.00030485640000000002 * fTemp145) + ((5.2899999999999997e-08 * fTemp319) + ((1.1270900000000001e-05 * fTemp197) + ((5.6403400000000003e-05 * fTemp204) + ((0.10068073399999999 * fTemp91) + ((0.0001178428 * fTemp98) + ((8.6204999999999999e-06 * fTemp211) + ((1.9471599999999998e-05 * fTemp218) + ((0.0001214182 * fTemp312) + ((5.0616e-06 * fTemp230) + ((3.2799000000000002e-05 * fTemp236) + ((0.089343940799999993 * fTemp104) + ((9.1636600000000003e-05 * fTemp248) + ((5.7409999999999998e-06 * fTemp254) + ((8.3846999999999995e-06 * fTemp305) + ((3.4548999999999997e-05 * fTemp130) + ((1.6007e-06 * fTemp259) + ((1.5710999999999999e-05 * fTemp264) + ((0.074076867699999993 * fTemp274) + ((6.2012000000000002e-05 * fTemp279) + ((3.0189999999999998e-06 * fTemp299) + ((2.5671e-06 * fTemp124) + ((5.2643999999999999e-06 * fTemp108) + ((0.055478496199999998 * fTemp287) + ((3.4079899999999999e-05 * fTemp294) + (((0.034345824400000002 * fTemp290) + ((0.011628344800000001 * fTemp112) + (1.24741e-05 * fTemp115))) + (1.0774000000000001e-06 * fTemp119)))))))))))))))))))))))))))))))))))))))))) - ((4.3000000000000001e-08 * fTemp147) + ((3.1969999999999998e-07 * fTemp7) + ((4.9539999999999995e-07 * fTemp148) + ((0.00033026079999999997 * fTemp8) + ((5.2036800000000003e-05 * fTemp11) + ((2.1436000000000001e-06 * fTemp146) + ((8.1899999999999999e-08 * fTemp159) + ((1.924e-07 * fTemp22) + ((0.00015868910000000001 * fTemp167) + ((5.5377799999999997e-05 * fTemp46) + ((8.2330000000000002e-07 * fTemp183) + ((5.3099999999999999e-08 * fTemp190) + ((6.3188799999999994e-05 * fTemp77) + ((5.1301400000000003e-05 * fTemp84) + ((2.251e-07 * fTemp137) + ((1.7976900000000001e-05 * fTemp224) + ((((6.0310999999999997e-06 * fTemp111) + (1.6277899999999999e-05 * fTemp283)) + (2.9040600000000001e-05 * fTemp269)) + (4.1664600000000001e-05 * fTemp242)))))))))))))))))))));
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
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec29[1] = fRec29[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec18[1] = fRec18[0];
			fRec17[1] = fRec17[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec12[1] = fRec12[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
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
			fRec33[1] = fRec33[0];
			fRec31[1] = fRec31[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec67[1] = fRec67[0];
			fRec65[1] = fRec65[0];
			fRec64[1] = fRec64[0];
			fRec62[1] = fRec62[0];
			fRec61[1] = fRec61[0];
			fRec59[1] = fRec59[0];
			fRec58[1] = fRec58[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec53[1] = fRec53[0];
			fRec52[1] = fRec52[0];
			fRec50[1] = fRec50[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fRec86[1] = fRec86[0];
			fRec84[1] = fRec84[0];
			fRec83[1] = fRec83[0];
			fRec81[1] = fRec81[0];
			fRec80[1] = fRec80[0];
			fRec78[1] = fRec78[0];
			fRec77[1] = fRec77[0];
			fRec75[1] = fRec75[0];
			fRec74[1] = fRec74[0];
			fRec72[1] = fRec72[0];
			fRec71[1] = fRec71[0];
			fRec69[1] = fRec69[0];
			fRec68[2] = fRec68[1];
			fRec68[1] = fRec68[0];
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
			fRec87[2] = fRec87[1];
			fRec87[1] = fRec87[0];
			fRec124[1] = fRec124[0];
			fRec122[1] = fRec122[0];
			fRec121[1] = fRec121[0];
			fRec119[1] = fRec119[0];
			fRec118[1] = fRec118[0];
			fRec116[1] = fRec116[0];
			fRec115[1] = fRec115[0];
			fRec113[1] = fRec113[0];
			fRec112[1] = fRec112[0];
			fRec110[1] = fRec110[0];
			fRec109[1] = fRec109[0];
			fRec107[1] = fRec107[0];
			fRec106[2] = fRec106[1];
			fRec106[1] = fRec106[0];
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
			fRec128[1] = fRec128[0];
			fRec126[1] = fRec126[0];
			fRec125[2] = fRec125[1];
			fRec125[1] = fRec125[0];
			fRec159[1] = fRec159[0];
			fRec157[1] = fRec157[0];
			fRec156[1] = fRec156[0];
			fRec154[1] = fRec154[0];
			fRec153[1] = fRec153[0];
			fRec151[1] = fRec151[0];
			fRec150[1] = fRec150[0];
			fRec148[1] = fRec148[0];
			fRec147[1] = fRec147[0];
			fRec145[1] = fRec145[0];
			fRec144[2] = fRec144[1];
			fRec144[1] = fRec144[0];
			fRec175[1] = fRec175[0];
			fRec173[1] = fRec173[0];
			fRec172[1] = fRec172[0];
			fRec170[1] = fRec170[0];
			fRec169[1] = fRec169[0];
			fRec167[1] = fRec167[0];
			fRec166[1] = fRec166[0];
			fRec164[1] = fRec164[0];
			fRec163[1] = fRec163[0];
			fRec161[1] = fRec161[0];
			fRec160[2] = fRec160[1];
			fRec160[1] = fRec160[0];
			fRec191[1] = fRec191[0];
			fRec189[1] = fRec189[0];
			fRec188[1] = fRec188[0];
			fRec186[1] = fRec186[0];
			fRec185[1] = fRec185[0];
			fRec183[1] = fRec183[0];
			fRec182[1] = fRec182[0];
			fRec180[1] = fRec180[0];
			fRec179[1] = fRec179[0];
			fRec177[1] = fRec177[0];
			fRec176[2] = fRec176[1];
			fRec176[1] = fRec176[0];
			fRec207[1] = fRec207[0];
			fRec205[1] = fRec205[0];
			fRec204[1] = fRec204[0];
			fRec202[1] = fRec202[0];
			fRec201[1] = fRec201[0];
			fRec199[1] = fRec199[0];
			fRec198[1] = fRec198[0];
			fRec196[1] = fRec196[0];
			fRec195[1] = fRec195[0];
			fRec193[1] = fRec193[0];
			fRec192[2] = fRec192[1];
			fRec192[1] = fRec192[0];
			fRec220[1] = fRec220[0];
			fRec218[1] = fRec218[0];
			fRec217[1] = fRec217[0];
			fRec215[1] = fRec215[0];
			fRec214[1] = fRec214[0];
			fRec212[1] = fRec212[0];
			fRec211[1] = fRec211[0];
			fRec209[1] = fRec209[0];
			fRec208[2] = fRec208[1];
			fRec208[1] = fRec208[0];
			fRec227[1] = fRec227[0];
			fRec225[1] = fRec225[0];
			fRec224[1] = fRec224[0];
			fRec222[1] = fRec222[0];
			fRec221[2] = fRec221[1];
			fRec221[1] = fRec221[0];
			fRec231[1] = fRec231[0];
			fRec229[1] = fRec229[0];
			fRec228[2] = fRec228[1];
			fRec228[1] = fRec228[0];
			fRec232[2] = fRec232[1];
			fRec232[1] = fRec232[0];
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
			fRec326[1] = fRec326[0];
			fRec324[1] = fRec324[0];
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
			fRec308[2] = fRec308[1];
			fRec308[1] = fRec308[0];
			fRec345[1] = fRec345[0];
			fRec343[1] = fRec343[0];
			fRec342[1] = fRec342[0];
			fRec340[1] = fRec340[0];
			fRec339[1] = fRec339[0];
			fRec337[1] = fRec337[0];
			fRec336[1] = fRec336[0];
			fRec334[1] = fRec334[0];
			fRec333[1] = fRec333[0];
			fRec331[1] = fRec331[0];
			fRec330[1] = fRec330[0];
			fRec328[1] = fRec328[0];
			fRec327[2] = fRec327[1];
			fRec327[1] = fRec327[0];
			fRec364[1] = fRec364[0];
			fRec362[1] = fRec362[0];
			fRec361[1] = fRec361[0];
			fRec359[1] = fRec359[0];
			fRec358[1] = fRec358[0];
			fRec356[1] = fRec356[0];
			fRec355[1] = fRec355[0];
			fRec353[1] = fRec353[0];
			fRec352[1] = fRec352[0];
			fRec350[1] = fRec350[0];
			fRec349[1] = fRec349[0];
			fRec347[1] = fRec347[0];
			fRec346[2] = fRec346[1];
			fRec346[1] = fRec346[0];
			fRec383[1] = fRec383[0];
			fRec381[1] = fRec381[0];
			fRec380[1] = fRec380[0];
			fRec378[1] = fRec378[0];
			fRec377[1] = fRec377[0];
			fRec375[1] = fRec375[0];
			fRec374[1] = fRec374[0];
			fRec372[1] = fRec372[0];
			fRec371[1] = fRec371[0];
			fRec369[1] = fRec369[0];
			fRec368[1] = fRec368[0];
			fRec366[1] = fRec366[0];
			fRec365[2] = fRec365[1];
			fRec365[1] = fRec365[0];
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
			fRec384[2] = fRec384[1];
			fRec384[1] = fRec384[0];
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
			fRec400[2] = fRec400[1];
			fRec400[1] = fRec400[0];
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
			fRec432[2] = fRec432[1];
			fRec432[1] = fRec432[0];
			fRec463[1] = fRec463[0];
			fRec461[1] = fRec461[0];
			fRec460[1] = fRec460[0];
			fRec458[1] = fRec458[0];
			fRec457[1] = fRec457[0];
			fRec455[1] = fRec455[0];
			fRec454[1] = fRec454[0];
			fRec452[1] = fRec452[0];
			fRec451[1] = fRec451[0];
			fRec449[1] = fRec449[0];
			fRec448[2] = fRec448[1];
			fRec448[1] = fRec448[0];
			fRec476[1] = fRec476[0];
			fRec474[1] = fRec474[0];
			fRec473[1] = fRec473[0];
			fRec471[1] = fRec471[0];
			fRec470[1] = fRec470[0];
			fRec468[1] = fRec468[0];
			fRec467[1] = fRec467[0];
			fRec465[1] = fRec465[0];
			fRec464[2] = fRec464[1];
			fRec464[1] = fRec464[0];
			fRec489[1] = fRec489[0];
			fRec487[1] = fRec487[0];
			fRec486[1] = fRec486[0];
			fRec484[1] = fRec484[0];
			fRec483[1] = fRec483[0];
			fRec481[1] = fRec481[0];
			fRec480[1] = fRec480[0];
			fRec478[1] = fRec478[0];
			fRec477[2] = fRec477[1];
			fRec477[1] = fRec477[0];
			fRec502[1] = fRec502[0];
			fRec500[1] = fRec500[0];
			fRec499[1] = fRec499[0];
			fRec497[1] = fRec497[0];
			fRec496[1] = fRec496[0];
			fRec494[1] = fRec494[0];
			fRec493[1] = fRec493[0];
			fRec491[1] = fRec491[0];
			fRec490[2] = fRec490[1];
			fRec490[1] = fRec490[0];
			fRec515[1] = fRec515[0];
			fRec513[1] = fRec513[0];
			fRec512[1] = fRec512[0];
			fRec510[1] = fRec510[0];
			fRec509[1] = fRec509[0];
			fRec507[1] = fRec507[0];
			fRec506[1] = fRec506[0];
			fRec504[1] = fRec504[0];
			fRec503[2] = fRec503[1];
			fRec503[1] = fRec503[0];
			fRec528[1] = fRec528[0];
			fRec526[1] = fRec526[0];
			fRec525[1] = fRec525[0];
			fRec523[1] = fRec523[0];
			fRec522[1] = fRec522[0];
			fRec520[1] = fRec520[0];
			fRec519[1] = fRec519[0];
			fRec517[1] = fRec517[0];
			fRec516[2] = fRec516[1];
			fRec516[1] = fRec516[0];
			fRec541[1] = fRec541[0];
			fRec539[1] = fRec539[0];
			fRec538[1] = fRec538[0];
			fRec536[1] = fRec536[0];
			fRec535[1] = fRec535[0];
			fRec533[1] = fRec533[0];
			fRec532[1] = fRec532[0];
			fRec530[1] = fRec530[0];
			fRec529[2] = fRec529[1];
			fRec529[1] = fRec529[0];
			fRec551[1] = fRec551[0];
			fRec549[1] = fRec549[0];
			fRec548[1] = fRec548[0];
			fRec546[1] = fRec546[0];
			fRec545[1] = fRec545[0];
			fRec543[1] = fRec543[0];
			fRec542[2] = fRec542[1];
			fRec542[1] = fRec542[0];
			fRec561[1] = fRec561[0];
			fRec559[1] = fRec559[0];
			fRec558[1] = fRec558[0];
			fRec556[1] = fRec556[0];
			fRec555[1] = fRec555[0];
			fRec553[1] = fRec553[0];
			fRec552[2] = fRec552[1];
			fRec552[1] = fRec552[0];
			fRec571[1] = fRec571[0];
			fRec569[1] = fRec569[0];
			fRec568[1] = fRec568[0];
			fRec566[1] = fRec566[0];
			fRec565[1] = fRec565[0];
			fRec563[1] = fRec563[0];
			fRec562[2] = fRec562[1];
			fRec562[1] = fRec562[0];
			fRec581[1] = fRec581[0];
			fRec579[1] = fRec579[0];
			fRec578[1] = fRec578[0];
			fRec576[1] = fRec576[0];
			fRec575[1] = fRec575[0];
			fRec573[1] = fRec573[0];
			fRec572[2] = fRec572[1];
			fRec572[1] = fRec572[0];
			fRec591[1] = fRec591[0];
			fRec589[1] = fRec589[0];
			fRec588[1] = fRec588[0];
			fRec586[1] = fRec586[0];
			fRec585[1] = fRec585[0];
			fRec583[1] = fRec583[0];
			fRec582[2] = fRec582[1];
			fRec582[1] = fRec582[0];
			fRec598[1] = fRec598[0];
			fRec596[1] = fRec596[0];
			fRec595[1] = fRec595[0];
			fRec593[1] = fRec593[0];
			fRec592[2] = fRec592[1];
			fRec592[1] = fRec592[0];
			fRec605[1] = fRec605[0];
			fRec603[1] = fRec603[0];
			fRec602[1] = fRec602[0];
			fRec600[1] = fRec600[0];
			fRec599[2] = fRec599[1];
			fRec599[1] = fRec599[0];
			fRec609[1] = fRec609[0];
			fRec607[1] = fRec607[0];
			fRec606[2] = fRec606[1];
			fRec606[1] = fRec606[0];
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
