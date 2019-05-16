/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMHLS_Dome_5H5P_normal_5"
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
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	FAUSTFLOAT fHslider0;
	double fRec15[2];
	double fRec16[3];
	FAUSTFLOAT fHslider1;
	double fRec17[2];
	double fRec18[3];
	double fRec19[3];
	double fRec20[3];
	double fRec21[3];
	double fRec22[3];
	double fRec23[3];
	double fRec24[3];
	double fRec25[3];
	double fRec26[3];
	double fRec27[3];
	double fConst7;
	double fConst8;
	double fConst9;
	double fRec14[2];
	double fRec12[2];
	double fRec11[2];
	double fRec9[2];
	double fConst10;
	double fConst11;
	double fRec8[2];
	double fRec6[2];
	double fRec5[2];
	double fRec3[2];
	double fConst12;
	double fRec2[2];
	double fRec0[2];
	double fConst13;
	double fConst14;
	double fConst15;
	double fConst16;
	double fConst17;
	double fRec40[3];
	double fRec41[3];
	double fRec42[3];
	double fRec43[3];
	double fRec44[3];
	double fRec45[3];
	double fRec46[3];
	double fRec47[3];
	double fRec48[3];
	double fConst18;
	double fConst19;
	double fRec39[2];
	double fRec37[2];
	double fRec36[2];
	double fRec34[2];
	double fRec33[2];
	double fRec31[2];
	double fRec30[2];
	double fRec28[2];
	double fConst20;
	double fConst21;
	double fConst22;
	double fConst23;
	double fRec58[3];
	double fRec59[3];
	double fRec60[3];
	double fRec61[3];
	double fRec62[3];
	double fRec63[3];
	double fRec64[3];
	double fConst24;
	double fConst25;
	double fRec57[2];
	double fRec55[2];
	double fRec54[2];
	double fRec52[2];
	double fRec51[2];
	double fRec49[2];
	double fConst26;
	double fConst27;
	double fRec68[3];
	double fRec69[3];
	double fRec70[3];
	double fConst28;
	double fRec67[2];
	double fRec65[2];
	double fConst29;
	double fConst30;
	double fRec77[3];
	double fRec78[3];
	double fRec79[3];
	double fRec80[3];
	double fRec81[3];
	double fConst31;
	double fConst32;
	double fRec76[2];
	double fRec74[2];
	double fRec73[2];
	double fRec71[2];
	double fRec82[3];
	int IOTA;
	double fVec0[1024];
	int iConst33;
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fHslider2;
	double fRec83[2];
	double fRec86[2];
	double fRec84[2];
	double fRec92[2];
	double fRec90[2];
	double fRec89[2];
	double fRec87[2];
	double fRec101[2];
	double fRec99[2];
	double fRec98[2];
	double fRec96[2];
	double fRec95[2];
	double fRec93[2];
	double fRec113[2];
	double fRec111[2];
	double fRec110[2];
	double fRec108[2];
	double fRec107[2];
	double fRec105[2];
	double fRec104[2];
	double fRec102[2];
	double fRec128[2];
	double fRec126[2];
	double fRec125[2];
	double fRec123[2];
	double fRec122[2];
	double fRec120[2];
	double fRec119[2];
	double fRec117[2];
	double fRec116[2];
	double fRec114[2];
	double fVec1[1024];
	double fRec131[2];
	double fRec129[2];
	double fRec137[2];
	double fRec135[2];
	double fRec134[2];
	double fRec132[2];
	double fRec146[2];
	double fRec144[2];
	double fRec143[2];
	double fRec141[2];
	double fRec140[2];
	double fRec138[2];
	double fRec158[2];
	double fRec156[2];
	double fRec155[2];
	double fRec153[2];
	double fRec152[2];
	double fRec150[2];
	double fRec149[2];
	double fRec147[2];
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
	double fVec2[1024];
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
	double fRec200[2];
	double fRec198[2];
	double fRec197[2];
	double fRec195[2];
	double fRec194[2];
	double fRec192[2];
	double fRec191[2];
	double fRec189[2];
	double fRec203[2];
	double fRec201[2];
	double fRec209[2];
	double fRec207[2];
	double fRec206[2];
	double fRec204[2];
	double fRec218[2];
	double fRec216[2];
	double fRec215[2];
	double fRec213[2];
	double fRec212[2];
	double fRec210[2];
	double fVec3[1024];
	double fRec230[2];
	double fRec228[2];
	double fRec227[2];
	double fRec225[2];
	double fRec224[2];
	double fRec222[2];
	double fRec221[2];
	double fRec219[2];
	double fRec239[2];
	double fRec237[2];
	double fRec236[2];
	double fRec234[2];
	double fRec233[2];
	double fRec231[2];
	double fRec245[2];
	double fRec243[2];
	double fRec242[2];
	double fRec240[2];
	double fRec260[2];
	double fRec258[2];
	double fRec257[2];
	double fRec255[2];
	double fRec254[2];
	double fRec252[2];
	double fRec251[2];
	double fRec249[2];
	double fRec248[2];
	double fRec246[2];
	double fRec263[2];
	double fRec261[2];
	double fVec4[1024];
	double fRec278[2];
	double fRec276[2];
	double fRec275[2];
	double fRec273[2];
	double fRec272[2];
	double fRec270[2];
	double fRec269[2];
	double fRec267[2];
	double fRec266[2];
	double fRec264[2];
	double fRec290[2];
	double fRec288[2];
	double fRec287[2];
	double fRec285[2];
	double fRec284[2];
	double fRec282[2];
	double fRec281[2];
	double fRec279[2];
	double fRec299[2];
	double fRec297[2];
	double fRec296[2];
	double fRec294[2];
	double fRec293[2];
	double fRec291[2];
	double fRec302[2];
	double fRec300[2];
	double fRec308[2];
	double fRec306[2];
	double fRec305[2];
	double fRec303[2];
	double fVec5[1024];
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
	double fVec6[1024];
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
	double fVec7[1024];
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
	double fVec8[1024];
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
	double fVec9[1024];
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
	double fRec518[2];
	double fRec516[2];
	double fRec524[2];
	double fRec522[2];
	double fRec521[2];
	double fRec519[2];
	double fRec533[2];
	double fRec531[2];
	double fRec530[2];
	double fRec528[2];
	double fRec527[2];
	double fRec525[2];
	double fVec10[1024];
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
	double fVec11[1024];
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
	double fVec12[1024];
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
	double fVec13[1024];
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
	double fVec14[1024];
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
	double fVec15[1024];
	double fConst34;
	double fConst35;
	double fConst36;
	double fConst37;
	double fConst38;
	double fConst39;
	double fConst40;
	double fConst41;
	double fConst42;
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
	double fConst43;
	double fConst44;
	double fConst45;
	double fConst46;
	double fConst47;
	double fConst48;
	double fConst49;
	double fRec785[2];
	double fRec783[2];
	double fRec782[2];
	double fRec780[2];
	double fRec779[2];
	double fRec777[2];
	double fRec776[2];
	double fRec774[2];
	double fConst50;
	double fConst51;
	double fConst52;
	double fConst53;
	double fConst54;
	double fConst55;
	double fRec794[2];
	double fRec792[2];
	double fRec791[2];
	double fRec789[2];
	double fRec788[2];
	double fRec786[2];
	double fConst56;
	double fConst57;
	double fConst58;
	double fRec797[2];
	double fRec795[2];
	double fConst59;
	double fConst60;
	double fConst61;
	double fConst62;
	double fRec803[2];
	double fRec801[2];
	double fRec800[2];
	double fRec798[2];
	double fVec16[512];
	int iConst63;
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
	double fVec17[512];
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
	double fVec18[512];
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
	double fVec19[512];
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
	double fVec20[512];
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
	double fVec21[512];
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
	double fVec22[512];
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
	double fVec23[512];
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fConst68;
	double fConst69;
	double fConst70;
	double fConst71;
	double fConst72;
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
	double fConst73;
	double fConst74;
	double fConst75;
	double fConst76;
	double fConst77;
	double fConst78;
	double fConst79;
	double fRec1145[2];
	double fRec1143[2];
	double fRec1142[2];
	double fRec1140[2];
	double fRec1139[2];
	double fRec1137[2];
	double fRec1136[2];
	double fRec1134[2];
	double fConst80;
	double fConst81;
	double fConst82;
	double fConst83;
	double fConst84;
	double fConst85;
	double fRec1154[2];
	double fRec1152[2];
	double fRec1151[2];
	double fRec1149[2];
	double fRec1148[2];
	double fRec1146[2];
	double fConst86;
	double fConst87;
	double fConst88;
	double fRec1157[2];
	double fRec1155[2];
	double fConst89;
	double fConst90;
	double fConst91;
	double fConst92;
	double fRec1163[2];
	double fRec1161[2];
	double fRec1160[2];
	double fRec1158[2];
	double fVec24[256];
	int iConst93;
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
	double fVec25[256];
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
	double fVec26[256];
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
	double fVec27[256];
	double fConst94;
	double fConst95;
	double fConst96;
	double fConst97;
	double fConst98;
	double fConst99;
	double fConst100;
	double fConst101;
	double fConst102;
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
	double fConst103;
	double fConst104;
	double fConst105;
	double fConst106;
	double fConst107;
	double fConst108;
	double fConst109;
	double fRec1325[2];
	double fRec1323[2];
	double fRec1322[2];
	double fRec1320[2];
	double fRec1319[2];
	double fRec1317[2];
	double fRec1316[2];
	double fRec1314[2];
	double fConst110;
	double fConst111;
	double fConst112;
	double fConst113;
	double fConst114;
	double fConst115;
	double fRec1334[2];
	double fRec1332[2];
	double fRec1331[2];
	double fRec1329[2];
	double fRec1328[2];
	double fRec1326[2];
	double fConst116;
	double fConst117;
	double fConst118;
	double fRec1337[2];
	double fRec1335[2];
	double fConst119;
	double fConst120;
	double fConst121;
	double fConst122;
	double fRec1343[2];
	double fRec1341[2];
	double fRec1340[2];
	double fRec1338[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMHLS_Dome_5H5P_normal_5");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMHLS_Dome_5H5P_normal_5");
		m->declare("version", "1.2");
	}

	virtual int getNumInputs() {
		return 36;
		
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
		fConst1 = double(iConst0);
		fConst2 = ((135.74989273514609 / fConst1) + 1.0);
		fConst3 = ((((19777.399306469804 / fConst1) + 249.5532431201479) / fConst1) + 1.0);
		fConst4 = ((((25159.235463955636 / fConst1) + 173.07206373673586) / fConst1) + 1.0);
		fConst5 = (1.0 / ((fConst2 * fConst3) * fConst4));
		fConst6 = (3.1415926535897931 / double(iConst0));
		fConst7 = (0.0 - (((100636.94185582254 / fConst1) + 346.14412747347171) / (fConst1 * fConst4)));
		fConst8 = mydsp_faustpower2_f(fConst1);
		fConst9 = (0.0 - (100636.94185582254 / (fConst8 * fConst4)));
		fConst10 = (0.0 - (((79109.597225879217 / fConst1) + 499.10648624029579) / (fConst1 * fConst3)));
		fConst11 = (0.0 - (79109.597225879217 / (fConst8 * fConst3)));
		fConst12 = (0.0 - (271.49978547029218 / (fConst1 * fConst2)));
		fConst13 = ((((12665.494141837065 / fConst1) + 215.62295645471744) / fConst1) + 1.0);
		fConst14 = (0.0 - (50661.976567348262 / (fConst8 * fConst13)));
		fConst15 = (0.0 - (((50661.976567348262 / fConst1) + 431.24591290943488) / (fConst1 * fConst13)));
		fConst16 = ((((15918.663680972788 / fConst1) + 156.62717660663603) / fConst1) + 1.0);
		fConst17 = (1.0 / (fConst13 * fConst16));
		fConst18 = (0.0 - (63674.654723891152 / (fConst8 * fConst16)));
		fConst19 = (0.0 - (((63674.654723891152 / fConst1) + 313.25435321327205) / (fConst1 * fConst16)));
		fConst20 = ((86.443380725268696 / fConst1) + 1.0);
		fConst21 = (0.0 - (172.88676145053739 / (fConst1 * fConst20)));
		fConst22 = ((((8950.8463194903634 / fConst1) + 136.90669911154342) / fConst1) + 1.0);
		fConst23 = (1.0 / (fConst20 * fConst22));
		fConst24 = (0.0 - (35803.385277961454 / (fConst8 * fConst22)));
		fConst25 = (0.0 - (((35803.385277961454 / fConst1) + 273.81339822308684) / (fConst1 * fConst22)));
		fConst26 = ((37.225013306135352 / fConst1) + 1.0);
		fConst27 = (1.0 / fConst26);
		fConst28 = (0.0 - (74.450026612270705 / (fConst1 * fConst26)));
		fConst29 = ((((4157.1048469258621 / fConst1) + 111.67503991840606) / fConst1) + 1.0);
		fConst30 = (1.0 / fConst29);
		fConst31 = (0.0 - (16628.419387703449 / (fConst8 * fConst29)));
		fConst32 = (0.0 - (((16628.419387703449 / fConst1) + 223.35007983681211) / (fConst1 * fConst29)));
		iConst33 = int(((0.0028145653948241961 * double(iConst0)) + 0.5));
		fConst34 = ((128.18660497931657 / fConst1) + 1.0);
		fConst35 = (0.0 - (256.37320995863314 / (fConst1 * fConst34)));
		fConst36 = ((((17635.000757786547 / fConst1) + 235.6494163834252) / fConst1) + 1.0);
		fConst37 = (0.0 - (70540.003031146189 / (fConst8 * fConst36)));
		fConst38 = (0.0 - (((70540.003031146189 / fConst1) + 471.29883276685041) / (fConst1 * fConst36)));
		fConst39 = ((((22433.846310978071 / fConst1) + 163.42937603980999) / fConst1) + 1.0);
		fConst40 = (1.0 / ((fConst34 * fConst36) * fConst39));
		fConst41 = (0.0 - (89735.385243912286 / (fConst8 * fConst39)));
		fConst42 = (0.0 - (((89735.385243912286 / fConst1) + 326.85875207961999) / (fConst1 * fConst39)));
		fConst43 = ((((11293.496952148356 / fConst1) + 203.6095512610093) / fConst1) + 1.0);
		fConst44 = (0.0 - (45173.987808593425 / (fConst8 * fConst43)));
		fConst45 = (0.0 - (((45173.987808593425 / fConst1) + 407.2191025220186) / (fConst1 * fConst43)));
		fConst46 = ((((14194.264965114509 / fConst1) + 147.90071367402544) / fConst1) + 1.0);
		fConst47 = (1.0 / (fConst43 * fConst46));
		fConst48 = (0.0 - (56777.059860458037 / (fConst8 * fConst46)));
		fConst49 = (0.0 - (((56777.059860458037 / fConst1) + 295.80142734805088) / (fConst1 * fConst46)));
		fConst50 = ((81.627198923287324 / fConst1) + 1.0);
		fConst51 = (0.0 - (163.25439784657465 / (fConst1 * fConst50)));
		fConst52 = ((((7981.2405656089695 / fConst1) + 129.27896003773355) / fConst1) + 1.0);
		fConst53 = (1.0 / (fConst50 * fConst52));
		fConst54 = (0.0 - (31924.962262435878 / (fConst8 * fConst52)));
		fConst55 = (0.0 - (((31924.962262435878 / fConst1) + 258.55792007546711) / (fConst1 * fConst52)));
		fConst56 = ((35.15102649350348 / fConst1) + 1.0);
		fConst57 = (1.0 / fConst56);
		fConst58 = (0.0 - (70.302052987006959 / (fConst1 * fConst56)));
		fConst59 = ((((3706.7839906409508 / fConst1) + 105.45307948051044) / fConst1) + 1.0);
		fConst60 = (1.0 / fConst59);
		fConst61 = (0.0 - (14827.135962563803 / (fConst8 * fConst59)));
		fConst62 = (0.0 - (((14827.135962563803 / fConst1) + 210.90615896102088) / (fConst1 * fConst59)));
		iConst63 = int(((0.0020220583685382951 * double(iConst0)) + 0.5));
		fConst64 = ((117.6992675397825 / fConst1) + 1.0);
		fConst65 = (0.0 - (235.39853507956499 / (fConst1 * fConst64)));
		fConst66 = ((((14867.491956047414 / fConst1) + 216.37021831556928) / fConst1) + 1.0);
		fConst67 = (0.0 - (59469.967824189654 / (fConst8 * fConst66)));
		fConst68 = (0.0 - (((59469.967824189654 / fConst1) + 432.74043663113855) / (fConst1 * fConst66)));
		fConst69 = ((((18913.241578648733 / fConst1) + 150.05871992220281) / fConst1) + 1.0);
		fConst70 = (1.0 / ((fConst64 * fConst66) * fConst69));
		fConst71 = (0.0 - (75652.966314594931 / (fConst8 * fConst69)));
		fConst72 = (0.0 - (((75652.966314594931 / fConst1) + 300.11743984440562) / (fConst1 * fConst69)));
		fConst73 = ((((9521.1776510740765 / fConst1) + 186.95163235964782) / fConst1) + 1.0);
		fConst74 = (0.0 - (38084.710604296306 / (fConst8 * fConst73)));
		fConst75 = (0.0 - (((38084.710604296306 / fConst1) + 373.90326471929563) / (fConst1 * fConst73)));
		fConst76 = ((((11966.720222434136 / fConst1) + 135.80050482538877) / fConst1) + 1.0);
		fConst77 = (1.0 / (fConst73 * fConst76));
		fConst78 = (0.0 - (47866.880889736545 / (fConst8 * fConst76)));
		fConst79 = (0.0 - (((47866.880889736545 / fConst1) + 271.60100965077754) / (fConst1 * fConst76)));
		fConst80 = ((74.949028614536147 / fConst1) + 1.0);
		fConst81 = (0.0 - (149.89805722907229 / (fConst1 * fConst80)));
		fConst82 = ((((6728.7226997184644 / fConst1) + 118.70225369648584) / fConst1) + 1.0);
		fConst83 = (1.0 / (fConst80 * fConst82));
		fConst84 = (0.0 - (26914.890798873857 / (fConst8 * fConst82)));
		fConst85 = (0.0 - (((26914.890798873857 / fConst1) + 237.40450739297168) / (fConst1 * fConst82)));
		fConst86 = ((32.275213718503664 / fConst1) + 1.0);
		fConst87 = (1.0 / fConst86);
		fConst88 = (0.0 - (64.550427437007329 / (fConst1 * fConst86)));
		fConst89 = ((((3125.0682617252614 / fConst1) + 96.825641155510993) / fConst1) + 1.0);
		fConst90 = (1.0 / fConst89);
		fConst91 = (0.0 - (12500.273046901046 / (fConst8 * fConst89)));
		fConst92 = (0.0 - (((12500.273046901046 / fConst1) + 193.65128231102199) / (fConst1 * fConst89)));
		iConst93 = int(((0.0007546298522354718 * double(iConst0)) + 0.5));
		fConst94 = ((112.2322463251477 / fConst1) + 1.0);
		fConst95 = (0.0 - (224.4644926502954 / (fConst1 * fConst94)));
		fConst96 = ((((13518.406533001747 / fConst1) + 206.32002345478514) / fConst1) + 1.0);
		fConst97 = (0.0 - (54073.62613200699 / (fConst8 * fConst96)));
		fConst98 = (0.0 - (((54073.62613200699 / fConst1) + 412.64004690957029) / (fConst1 * fConst96)));
		fConst99 = ((((17197.042330535627 / fConst1) + 143.0886323217992) / fConst1) + 1.0);
		fConst100 = (1.0 / ((fConst94 * fConst96) * fConst99));
		fConst101 = (0.0 - (68788.169322142508 / (fConst8 * fConst99)));
		fConst102 = (0.0 - (((68788.169322142508 / fConst1) + 286.17726464359839) / (fConst1 * fConst99)));
		fConst103 = ((((8657.2200974217594 / fConst1) + 178.26790338167996) / fConst1) + 1.0);
		fConst104 = (0.0 - (34628.880389687038 / (fConst103 * fConst8)));
		fConst105 = (0.0 - (((34628.880389687038 / fConst1) + 356.53580676335991) / (fConst103 * fConst1)));
		fConst106 = ((((10880.852622069639 / fConst1) + 129.49269801947491) / fConst1) + 1.0);
		fConst107 = (1.0 / (fConst103 * fConst106));
		fConst108 = (0.0 - (43523.410488278554 / (fConst106 * fConst8)));
		fConst109 = (0.0 - (((43523.410488278554 / fConst1) + 258.98539603894983) / (fConst106 * fConst1)));
		fConst110 = ((71.467716130467849 / fConst1) + 1.0);
		fConst111 = (0.0 - (142.9354322609357 / (fConst110 * fConst1)));
		fConst112 = ((((6118.1542368773398 / fConst1) + 113.18864471022512) / fConst1) + 1.0);
		fConst113 = (1.0 / (fConst110 * fConst112));
		fConst114 = (0.0 - (24472.616947509359 / (fConst112 * fConst8)));
		fConst115 = (0.0 - (((24472.616947509359 / fConst1) + 226.37728942045024) / (fConst112 * fConst1)));
		fConst116 = ((30.776060140115494 / fConst1) + 1.0);
		fConst117 = (1.0 / fConst116);
		fConst118 = (0.0 - (61.552120280230987 / (fConst1 * fConst116)));
		fConst119 = ((((2841.4976332440169 / fConst1) + 92.328180420346484) / fConst1) + 1.0);
		fConst120 = (1.0 / fConst119);
		fConst121 = (0.0 - (11365.990532976068 / (fConst8 * fConst119)));
		fConst122 = (0.0 - (((11365.990532976068 / fConst1) + 184.65636084069297) / (fConst1 * fConst119)));
		
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(400.0);
		fHslider1 = FAUSTFLOAT(0.0);
		fCheckbox0 = FAUSTFLOAT(0.0);
		fHslider2 = FAUSTFLOAT(-10.0);
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec15[l0] = 0.0;
			
		}
		for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
			fRec16[l1] = 0.0;
			
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec17[l2] = 0.0;
			
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec18[l3] = 0.0;
			
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
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec14[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec12[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec11[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec9[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec8[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec6[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec5[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec3[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec2[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec0[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec40[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 3); l24 = (l24 + 1)) {
			fRec41[l24] = 0.0;
			
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
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec39[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec37[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec36[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec34[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec33[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec31[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec30[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec28[l39] = 0.0;
			
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
		for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) {
			fRec62[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec63[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec64[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec57[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec55[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec54[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec52[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec51[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec49[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 3); l53 = (l53 + 1)) {
			fRec68[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) {
			fRec69[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec70[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fRec67[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fRec65[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 3); l58 = (l58 + 1)) {
			fRec77[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 3); l59 = (l59 + 1)) {
			fRec78[l59] = 0.0;
			
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
		for (int l67 = 0; (l67 < 3); l67 = (l67 + 1)) {
			fRec82[l67] = 0.0;
			
		}
		IOTA = 0;
		for (int l68 = 0; (l68 < 1024); l68 = (l68 + 1)) {
			fVec0[l68] = 0.0;
			
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec83[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec86[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec84[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec92[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec90[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec89[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 2); l75 = (l75 + 1)) {
			fRec87[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec101[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec99[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec98[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fRec96[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec95[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec93[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec113[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fRec111[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec110[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec108[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec107[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 2); l87 = (l87 + 1)) {
			fRec105[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			fRec104[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec102[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec128[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec126[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec125[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec123[l93] = 0.0;
			
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec122[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec120[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fRec119[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec117[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec116[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec114[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 1024); l100 = (l100 + 1)) {
			fVec1[l100] = 0.0;
			
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fRec131[l101] = 0.0;
			
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec129[l102] = 0.0;
			
		}
		for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) {
			fRec137[l103] = 0.0;
			
		}
		for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) {
			fRec135[l104] = 0.0;
			
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fRec134[l105] = 0.0;
			
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec132[l106] = 0.0;
			
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fRec146[l107] = 0.0;
			
		}
		for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) {
			fRec144[l108] = 0.0;
			
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec143[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec141[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec140[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec138[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec158[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec156[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec155[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec153[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec152[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec150[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec149[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec147[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec173[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec171[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec170[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec168[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fRec167[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec165[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec164[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec162[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec161[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec159[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 1024); l131 = (l131 + 1)) {
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
			fRec203[l150] = 0.0;
			
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec201[l151] = 0.0;
			
		}
		for (int l152 = 0; (l152 < 2); l152 = (l152 + 1)) {
			fRec209[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec207[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec206[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec204[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec218[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec216[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec215[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec213[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec212[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec210[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 1024); l162 = (l162 + 1)) {
			fVec3[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			fRec230[l163] = 0.0;
			
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			fRec228[l164] = 0.0;
			
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec227[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec225[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fRec224[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec222[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec221[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec219[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fRec239[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec237[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fRec236[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec234[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec233[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec231[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec245[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 2); l178 = (l178 + 1)) {
			fRec243[l178] = 0.0;
			
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec242[l179] = 0.0;
			
		}
		for (int l180 = 0; (l180 < 2); l180 = (l180 + 1)) {
			fRec240[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec260[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec258[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fRec257[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec255[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec254[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fRec252[l186] = 0.0;
			
		}
		for (int l187 = 0; (l187 < 2); l187 = (l187 + 1)) {
			fRec251[l187] = 0.0;
			
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec249[l188] = 0.0;
			
		}
		for (int l189 = 0; (l189 < 2); l189 = (l189 + 1)) {
			fRec248[l189] = 0.0;
			
		}
		for (int l190 = 0; (l190 < 2); l190 = (l190 + 1)) {
			fRec246[l190] = 0.0;
			
		}
		for (int l191 = 0; (l191 < 2); l191 = (l191 + 1)) {
			fRec263[l191] = 0.0;
			
		}
		for (int l192 = 0; (l192 < 2); l192 = (l192 + 1)) {
			fRec261[l192] = 0.0;
			
		}
		for (int l193 = 0; (l193 < 1024); l193 = (l193 + 1)) {
			fVec4[l193] = 0.0;
			
		}
		for (int l194 = 0; (l194 < 2); l194 = (l194 + 1)) {
			fRec278[l194] = 0.0;
			
		}
		for (int l195 = 0; (l195 < 2); l195 = (l195 + 1)) {
			fRec276[l195] = 0.0;
			
		}
		for (int l196 = 0; (l196 < 2); l196 = (l196 + 1)) {
			fRec275[l196] = 0.0;
			
		}
		for (int l197 = 0; (l197 < 2); l197 = (l197 + 1)) {
			fRec273[l197] = 0.0;
			
		}
		for (int l198 = 0; (l198 < 2); l198 = (l198 + 1)) {
			fRec272[l198] = 0.0;
			
		}
		for (int l199 = 0; (l199 < 2); l199 = (l199 + 1)) {
			fRec270[l199] = 0.0;
			
		}
		for (int l200 = 0; (l200 < 2); l200 = (l200 + 1)) {
			fRec269[l200] = 0.0;
			
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fRec267[l201] = 0.0;
			
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec266[l202] = 0.0;
			
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fRec264[l203] = 0.0;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec290[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec288[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec287[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec285[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec284[l208] = 0.0;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec282[l209] = 0.0;
			
		}
		for (int l210 = 0; (l210 < 2); l210 = (l210 + 1)) {
			fRec281[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 2); l211 = (l211 + 1)) {
			fRec279[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec299[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec297[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fRec296[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 2); l215 = (l215 + 1)) {
			fRec294[l215] = 0.0;
			
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fRec293[l216] = 0.0;
			
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec291[l217] = 0.0;
			
		}
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fRec302[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec300[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fRec308[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec306[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec305[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec303[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 1024); l224 = (l224 + 1)) {
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
		for (int l255 = 0; (l255 < 1024); l255 = (l255 + 1)) {
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
		for (int l286 = 0; (l286 < 1024); l286 = (l286 + 1)) {
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
		for (int l317 = 0; (l317 < 1024); l317 = (l317 + 1)) {
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
		for (int l348 = 0; (l348 < 1024); l348 = (l348 + 1)) {
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
			fRec518[l367] = 0.0;
			
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec516[l368] = 0.0;
			
		}
		for (int l369 = 0; (l369 < 2); l369 = (l369 + 1)) {
			fRec524[l369] = 0.0;
			
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec522[l370] = 0.0;
			
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			fRec521[l371] = 0.0;
			
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			fRec519[l372] = 0.0;
			
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fRec533[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec531[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 2); l375 = (l375 + 1)) {
			fRec530[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec528[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec527[l377] = 0.0;
			
		}
		for (int l378 = 0; (l378 < 2); l378 = (l378 + 1)) {
			fRec525[l378] = 0.0;
			
		}
		for (int l379 = 0; (l379 < 1024); l379 = (l379 + 1)) {
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
		for (int l410 = 0; (l410 < 1024); l410 = (l410 + 1)) {
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
		for (int l441 = 0; (l441 < 1024); l441 = (l441 + 1)) {
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
		for (int l472 = 0; (l472 < 1024); l472 = (l472 + 1)) {
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
		for (int l503 = 0; (l503 < 1024); l503 = (l503 + 1)) {
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
		for (int l534 = 0; (l534 < 1024); l534 = (l534 + 1)) {
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
		for (int l565 = 0; (l565 < 512); l565 = (l565 + 1)) {
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
		for (int l596 = 0; (l596 < 512); l596 = (l596 + 1)) {
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
		for (int l627 = 0; (l627 < 512); l627 = (l627 + 1)) {
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
		for (int l658 = 0; (l658 < 512); l658 = (l658 + 1)) {
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
		for (int l689 = 0; (l689 < 512); l689 = (l689 + 1)) {
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
		for (int l720 = 0; (l720 < 512); l720 = (l720 + 1)) {
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
		for (int l751 = 0; (l751 < 512); l751 = (l751 + 1)) {
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
		for (int l782 = 0; (l782 < 512); l782 = (l782 + 1)) {
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
		for (int l813 = 0; (l813 < 256); l813 = (l813 + 1)) {
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
		for (int l844 = 0; (l844 < 256); l844 = (l844 + 1)) {
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
		for (int l875 = 0; (l875 < 256); l875 = (l875 + 1)) {
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
		for (int l906 = 0; (l906 < 256); l906 = (l906 + 1)) {
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
		ui_interface->openVerticalBox("KMHLS_Dome_5H5P_normal_5");
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
		double fSlow2 = (0.0010000000000000009 * (double((double(fCheckbox0) < 0.5)) * std::pow(10.0, (0.050000000000000003 * double(fHslider2)))));
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec15[0] = (fSlow0 + (0.999 * fRec15[1]));
			double fTemp0 = std::tan((fConst6 * fRec15[0]));
			double fTemp1 = mydsp_faustpower2_f(fTemp0);
			double fTemp2 = ((fTemp0 * (fTemp0 + -2.0)) + 1.0);
			double fTemp3 = (fTemp1 + -1.0);
			double fTemp4 = ((fTemp0 * (fTemp0 + 2.0)) + 1.0);
			fRec16[0] = (double(input25[i]) - (((fTemp2 * fRec16[2]) + (2.0 * (fTemp3 * fRec16[1]))) / fTemp4));
			fRec17[0] = (fSlow1 + (0.999 * fRec17[1]));
			double fTemp5 = (fRec17[0] * fTemp4);
			double fTemp6 = (0.0 - (2.0 / fTemp4));
			double fTemp7 = (((fTemp1 * (fRec16[2] + (fRec16[0] + (2.0 * fRec16[1])))) / fTemp5) + (0.20571231109999999 * (fRec17[0] * (0.0 - ((fTemp6 * fRec16[1]) + ((fRec16[0] + fRec16[2]) / fTemp4))))));
			fRec18[0] = (double(input26[i]) - (((fTemp2 * fRec18[2]) + (2.0 * (fTemp3 * fRec18[1]))) / fTemp4));
			double fTemp8 = (((fTemp1 * (fRec18[2] + (fRec18[0] + (2.0 * fRec18[1])))) / fTemp5) + (0.20571231109999999 * (fRec17[0] * (0.0 - ((fTemp6 * fRec18[1]) + ((fRec18[0] + fRec18[2]) / fTemp4))))));
			fRec19[0] = (double(input28[i]) - (((fTemp2 * fRec19[2]) + (2.0 * (fTemp3 * fRec19[1]))) / fTemp4));
			double fTemp9 = (((fTemp1 * (fRec19[2] + (fRec19[0] + (2.0 * fRec19[1])))) / fTemp5) + (0.20571231109999999 * (fRec17[0] * (0.0 - ((fTemp6 * fRec19[1]) + ((fRec19[0] + fRec19[2]) / fTemp4))))));
			fRec20[0] = (double(input29[i]) - (((fTemp2 * fRec20[2]) + (2.0 * (fTemp3 * fRec20[1]))) / fTemp4));
			double fTemp10 = (((fTemp1 * (fRec20[2] + (fRec20[0] + (2.0 * fRec20[1])))) / fTemp5) + (0.20571231109999999 * (fRec17[0] * (0.0 - ((fTemp6 * fRec20[1]) + ((fRec20[0] + fRec20[2]) / fTemp4))))));
			fRec21[0] = (double(input31[i]) - (((fTemp2 * fRec21[2]) + (2.0 * (fTemp3 * fRec21[1]))) / fTemp4));
			double fTemp11 = (((fTemp1 * (fRec21[2] + (fRec21[0] + (2.0 * fRec21[1])))) / fTemp5) + (0.20571231109999999 * (fRec17[0] * (0.0 - ((fTemp6 * fRec21[1]) + ((fRec21[0] + fRec21[2]) / fTemp4))))));
			fRec22[0] = (double(input33[i]) - (((fTemp2 * fRec22[2]) + (2.0 * (fTemp3 * fRec22[1]))) / fTemp4));
			double fTemp12 = ((((((2.0 * fRec22[1]) + fRec22[0]) + fRec22[2]) * fTemp1) / fTemp5) + (0.20571231109999999 * (fRec17[0] * (0.0 - ((fTemp6 * fRec22[1]) + ((fRec22[0] + fRec22[2]) / fTemp4))))));
			fRec23[0] = (double(input34[i]) - (((fRec23[2] * fTemp2) + (2.0 * (fRec23[1] * fTemp3))) / fTemp4));
			double fTemp13 = ((((fRec23[2] + ((2.0 * fRec23[1]) + fRec23[0])) * fTemp1) / fTemp5) + (0.20571231109999999 * (fRec17[0] * (0.0 - ((fRec23[1] * fTemp6) + ((fRec23[2] + fRec23[0]) / fTemp4))))));
			fRec24[0] = (double(input35[i]) - (((fRec24[2] * fTemp2) + (2.0 * (fRec24[1] * fTemp3))) / fTemp4));
			double fTemp14 = ((((fRec24[2] + ((2.0 * fRec24[1]) + fRec24[0])) * fTemp1) / fTemp5) + (0.20571231109999999 * (fRec17[0] * (0.0 - ((fRec24[1] * fTemp6) + ((fRec24[2] + fRec24[0]) / fTemp4))))));
			fRec25[0] = (double(input27[i]) - (((fTemp2 * fRec25[2]) + (2.0 * (fTemp3 * fRec25[1]))) / fTemp4));
			double fTemp15 = (((fTemp1 * (fRec25[2] + (fRec25[0] + (2.0 * fRec25[1])))) / fTemp5) + (0.20571231109999999 * (fRec17[0] * (0.0 - ((fTemp6 * fRec25[1]) + ((fRec25[0] + fRec25[2]) / fTemp4))))));
			fRec26[0] = (double(input30[i]) - (((fTemp2 * fRec26[2]) + (2.0 * (fTemp3 * fRec26[1]))) / fTemp4));
			double fTemp16 = (((fTemp1 * (fRec26[2] + (fRec26[0] + (2.0 * fRec26[1])))) / fTemp5) + (0.20571231109999999 * (fRec17[0] * (0.0 - ((fTemp6 * fRec26[1]) + ((fRec26[0] + fRec26[2]) / fTemp4))))));
			fRec27[0] = (double(input32[i]) - (((fTemp2 * fRec27[2]) + (2.0 * (fTemp3 * fRec27[1]))) / fTemp4));
			double fTemp17 = (((fTemp1 * (fRec27[2] + (fRec27[0] + (2.0 * fRec27[1])))) / fTemp5) + (0.20571231109999999 * (fRec17[0] * (0.0 - ((fTemp6 * fRec27[1]) + ((fRec27[0] + fRec27[2]) / fTemp4))))));
			double fTemp18 = (fConst5 * ((((((0.0137266999 * fTemp7) + (0.035457260900000002 * fTemp8)) + (0.074667142800000003 * fTemp9)) + (0.0429355685 * fTemp10)) + (0.0476818964 * fTemp11)) - ((((((0.028159575499999999 * fTemp12) + (0.073585827000000006 * fTemp13)) + (0.20435698159999999 * fTemp14)) + (0.10784851400000001 * fTemp15)) + (0.034524270900000001 * fTemp16)) + (0.032927149099999997 * fTemp17))));
			double fTemp19 = (fConst7 * fRec12[1]);
			double fTemp20 = (fConst9 * fRec9[1]);
			fRec14[0] = (((fTemp18 + fRec14[1]) + fTemp19) + fTemp20);
			fRec12[0] = fRec14[0];
			double fRec13 = ((fTemp18 + fTemp19) + fTemp20);
			fRec11[0] = (fRec12[0] + fRec11[1]);
			fRec9[0] = fRec11[0];
			double fRec10 = fRec13;
			double fTemp21 = (fConst10 * fRec6[1]);
			double fTemp22 = (fConst11 * fRec3[1]);
			fRec8[0] = (((fRec10 + fRec8[1]) + fTemp21) + fTemp22);
			fRec6[0] = fRec8[0];
			double fRec7 = ((fRec10 + fTemp21) + fTemp22);
			fRec5[0] = (fRec6[0] + fRec5[1]);
			fRec3[0] = fRec5[0];
			double fRec4 = fRec7;
			double fTemp23 = (fConst12 * fRec0[1]);
			fRec2[0] = ((fRec4 + fRec2[1]) + fTemp23);
			fRec0[0] = fRec2[0];
			double fRec1 = (fRec4 + fTemp23);
			double fTemp24 = (fConst14 * fRec28[1]);
			double fTemp25 = (fConst15 * fRec31[1]);
			fRec40[0] = (double(input16[i]) - (((fTemp2 * fRec40[2]) + (2.0 * (fTemp3 * fRec40[1]))) / fTemp4));
			double fTemp26 = (((fTemp1 * (fRec40[2] + (fRec40[0] + (2.0 * fRec40[1])))) / fTemp5) + (0.42200500930000001 * (fRec17[0] * (0.0 - ((fTemp6 * fRec40[1]) + ((fRec40[0] + fRec40[2]) / fTemp4))))));
			fRec41[0] = (double(input17[i]) - (((fTemp2 * fRec41[2]) + (2.0 * (fTemp3 * fRec41[1]))) / fTemp4));
			double fTemp27 = (((fTemp1 * (fRec41[2] + (fRec41[0] + (2.0 * fRec41[1])))) / fTemp5) + (0.42200500930000001 * (fRec17[0] * (0.0 - ((fTemp6 * fRec41[1]) + ((fRec41[0] + fRec41[2]) / fTemp4))))));
			fRec42[0] = (double(input20[i]) - (((fTemp2 * fRec42[2]) + (2.0 * (fTemp3 * fRec42[1]))) / fTemp4));
			double fTemp28 = (((fTemp1 * (fRec42[2] + (fRec42[0] + (2.0 * fRec42[1])))) / fTemp5) + (0.42200500930000001 * (fRec17[0] * (0.0 - ((fTemp6 * fRec42[1]) + ((fRec42[0] + fRec42[2]) / fTemp4))))));
			fRec43[0] = (double(input18[i]) - (((fTemp2 * fRec43[2]) + (2.0 * (fTemp3 * fRec43[1]))) / fTemp4));
			double fTemp29 = (((fTemp1 * (fRec43[2] + (fRec43[0] + (2.0 * fRec43[1])))) / fTemp5) + (0.42200500930000001 * (fRec17[0] * (0.0 - ((fTemp6 * fRec43[1]) + ((fRec43[0] + fRec43[2]) / fTemp4))))));
			fRec44[0] = (double(input19[i]) - (((fTemp2 * fRec44[2]) + (2.0 * (fTemp3 * fRec44[1]))) / fTemp4));
			double fTemp30 = (((fTemp1 * (fRec44[2] + (fRec44[0] + (2.0 * fRec44[1])))) / fTemp5) + (0.42200500930000001 * (fRec17[0] * (0.0 - ((fTemp6 * fRec44[1]) + ((fRec44[0] + fRec44[2]) / fTemp4))))));
			fRec45[0] = (double(input21[i]) - (((fTemp2 * fRec45[2]) + (2.0 * (fTemp3 * fRec45[1]))) / fTemp4));
			double fTemp31 = (((fTemp1 * (fRec45[2] + (fRec45[0] + (2.0 * fRec45[1])))) / fTemp5) + (0.42200500930000001 * (fRec17[0] * (0.0 - ((fTemp6 * fRec45[1]) + ((fRec45[0] + fRec45[2]) / fTemp4))))));
			fRec46[0] = (double(input22[i]) - (((fTemp2 * fRec46[2]) + (2.0 * (fTemp3 * fRec46[1]))) / fTemp4));
			double fTemp32 = (((fTemp1 * (fRec46[2] + (fRec46[0] + (2.0 * fRec46[1])))) / fTemp5) + (0.42200500930000001 * (fRec17[0] * (0.0 - ((fTemp6 * fRec46[1]) + ((fRec46[0] + fRec46[2]) / fTemp4))))));
			fRec47[0] = (double(input23[i]) - (((fTemp2 * fRec47[2]) + (2.0 * (fTemp3 * fRec47[1]))) / fTemp4));
			double fTemp33 = (((fTemp1 * (fRec47[2] + (fRec47[0] + (2.0 * fRec47[1])))) / fTemp5) + (0.42200500930000001 * (fRec17[0] * (0.0 - ((fTemp6 * fRec47[1]) + ((fRec47[0] + fRec47[2]) / fTemp4))))));
			fRec48[0] = (double(input24[i]) - (((fTemp2 * fRec48[2]) + (2.0 * (fTemp3 * fRec48[1]))) / fTemp4));
			double fTemp34 = (((fTemp1 * (fRec48[2] + (fRec48[0] + (2.0 * fRec48[1])))) / fTemp5) + (0.42200500930000001 * (fRec17[0] * (0.0 - ((fTemp6 * fRec48[1]) + ((fRec48[0] + fRec48[2]) / fTemp4))))));
			double fTemp35 = (fConst17 * ((((0.050248680499999997 * fTemp26) + (0.0012755430000000001 * fTemp27)) + (0.072456145999999999 * fTemp28)) - ((((((0.1265282281 * fTemp29) + (0.0062067171000000001 * fTemp30)) + (0.0222463231 * fTemp31)) + (0.031582233699999997 * fTemp32)) + (0.046196568600000001 * fTemp33)) + (0.099346722900000003 * fTemp34))));
			double fTemp36 = (fConst18 * fRec34[1]);
			double fTemp37 = (fConst19 * fRec37[1]);
			fRec39[0] = (fTemp35 + (fTemp36 + (fRec39[1] + fTemp37)));
			fRec37[0] = fRec39[0];
			double fRec38 = ((fTemp37 + fTemp36) + fTemp35);
			fRec36[0] = (fRec37[0] + fRec36[1]);
			fRec34[0] = fRec36[0];
			double fRec35 = fRec38;
			fRec33[0] = (fTemp24 + (fTemp25 + (fRec35 + fRec33[1])));
			fRec31[0] = fRec33[0];
			double fRec32 = (fTemp24 + (fRec35 + fTemp25));
			fRec30[0] = (fRec31[0] + fRec30[1]);
			fRec28[0] = fRec30[0];
			double fRec29 = fRec32;
			double fTemp38 = (fConst21 * fRec49[1]);
			fRec58[0] = (double(input9[i]) - (((fTemp2 * fRec58[2]) + (2.0 * (fTemp3 * fRec58[1]))) / fTemp4));
			double fTemp39 = (((fTemp1 * (fRec58[2] + (fRec58[0] + (2.0 * fRec58[1])))) / fTemp5) + (0.62824992459999995 * (fRec17[0] * (0.0 - ((fTemp6 * fRec58[1]) + ((fRec58[0] + fRec58[2]) / fTemp4))))));
			fRec59[0] = (double(input12[i]) - (((fTemp2 * fRec59[2]) + (2.0 * (fTemp3 * fRec59[1]))) / fTemp4));
			double fTemp40 = (((fTemp1 * (fRec59[2] + (fRec59[0] + (2.0 * fRec59[1])))) / fTemp5) + (0.62824992459999995 * (fRec17[0] * (0.0 - ((fTemp6 * fRec59[1]) + ((fRec59[0] + fRec59[2]) / fTemp4))))));
			fRec60[0] = (double(input14[i]) - (((fTemp2 * fRec60[2]) + (2.0 * (fTemp3 * fRec60[1]))) / fTemp4));
			double fTemp41 = (((fTemp1 * (fRec60[2] + (fRec60[0] + (2.0 * fRec60[1])))) / fTemp5) + (0.62824992459999995 * (fRec17[0] * (0.0 - ((fTemp6 * fRec60[1]) + ((fRec60[0] + fRec60[2]) / fTemp4))))));
			fRec61[0] = (double(input10[i]) - (((fTemp2 * fRec61[2]) + (2.0 * (fTemp3 * fRec61[1]))) / fTemp4));
			double fTemp42 = (((fTemp1 * (fRec61[2] + (fRec61[0] + (2.0 * fRec61[1])))) / fTemp5) + (0.62824992459999995 * (fRec17[0] * (0.0 - ((fTemp6 * fRec61[1]) + ((fRec61[0] + fRec61[2]) / fTemp4))))));
			fRec62[0] = (double(input11[i]) - (((fTemp2 * fRec62[2]) + (2.0 * (fTemp3 * fRec62[1]))) / fTemp4));
			double fTemp43 = (((fTemp1 * (fRec62[2] + (fRec62[0] + (2.0 * fRec62[1])))) / fTemp5) + (0.62824992459999995 * (fRec17[0] * (0.0 - ((fTemp6 * fRec62[1]) + ((fRec62[0] + fRec62[2]) / fTemp4))))));
			fRec63[0] = (double(input13[i]) - (((fTemp2 * fRec63[2]) + (2.0 * (fTemp3 * fRec63[1]))) / fTemp4));
			double fTemp44 = (((fTemp1 * (fRec63[2] + (fRec63[0] + (2.0 * fRec63[1])))) / fTemp5) + (0.62824992459999995 * (fRec17[0] * (0.0 - ((fTemp6 * fRec63[1]) + ((fRec63[0] + fRec63[2]) / fTemp4))))));
			fRec64[0] = (double(input15[i]) - (((fTemp2 * fRec64[2]) + (2.0 * (fTemp3 * fRec64[1]))) / fTemp4));
			double fTemp45 = (((fTemp1 * (fRec64[2] + (fRec64[0] + (2.0 * fRec64[1])))) / fTemp5) + (0.62824992459999995 * (fRec17[0] * (0.0 - ((fTemp6 * fRec64[1]) + ((fRec64[0] + fRec64[2]) / fTemp4))))));
			double fTemp46 = (fConst23 * ((((0.12132750439999999 * fTemp39) + (0.011766338899999999 * fTemp40)) + (0.0012266477 * fTemp41)) - ((((0.029528833899999999 * fTemp42) + (0.045699549300000003 * fTemp43)) + (0.0703779717 * fTemp44)) + (0.032522493600000001 * fTemp45))));
			double fTemp47 = (fConst24 * fRec52[1]);
			double fTemp48 = (fConst25 * fRec55[1]);
			fRec57[0] = (fTemp46 + (fTemp47 + (fRec57[1] + fTemp48)));
			fRec55[0] = fRec57[0];
			double fRec56 = ((fTemp48 + fTemp47) + fTemp46);
			fRec54[0] = (fRec55[0] + fRec54[1]);
			fRec52[0] = fRec54[0];
			double fRec53 = fRec56;
			fRec51[0] = (fTemp38 + (fRec53 + fRec51[1]));
			fRec49[0] = fRec51[0];
			double fRec50 = (fRec53 + fTemp38);
			fRec68[0] = (double(input1[i]) - (((fTemp2 * fRec68[2]) + (2.0 * (fTemp3 * fRec68[1]))) / fTemp4));
			double fTemp49 = (((fTemp1 * (fRec68[2] + (fRec68[0] + (2.0 * fRec68[1])))) / fTemp5) + (0.93246951420000002 * (fRec17[0] * (0.0 - ((fTemp6 * fRec68[1]) + ((fRec68[0] + fRec68[2]) / fTemp4))))));
			fRec69[0] = (double(input3[i]) - (((fTemp2 * fRec69[2]) + (2.0 * (fTemp3 * fRec69[1]))) / fTemp4));
			double fTemp50 = (((fTemp1 * (fRec69[2] + (fRec69[0] + (2.0 * fRec69[1])))) / fTemp5) + (0.93246951420000002 * (fRec17[0] * (0.0 - ((fTemp6 * fRec69[1]) + ((fRec69[0] + fRec69[2]) / fTemp4))))));
			fRec70[0] = (double(input2[i]) - (((fTemp2 * fRec70[2]) + (2.0 * (fTemp3 * fRec70[1]))) / fTemp4));
			double fTemp51 = (((fTemp1 * (fRec70[2] + (fRec70[0] + (2.0 * fRec70[1])))) / fTemp5) + (0.93246951420000002 * (fRec17[0] * (0.0 - ((fTemp6 * fRec70[1]) + ((fRec70[0] + fRec70[2]) / fTemp4))))));
			double fTemp52 = (fConst27 * (((0.038825610000000003 * fTemp49) + (0.051703716300000001 * fTemp50)) - (0.0060103965000000001 * fTemp51)));
			double fTemp53 = (fConst28 * fRec65[1]);
			fRec67[0] = (fTemp52 + (fRec67[1] + fTemp53));
			fRec65[0] = fRec67[0];
			double fRec66 = (fTemp53 + fTemp52);
			fRec77[0] = (double(input4[i]) - (((fTemp2 * fRec77[2]) + (2.0 * (fTemp3 * fRec77[1]))) / fTemp4));
			double fTemp54 = (((fTemp1 * (fRec77[2] + (fRec77[0] + (2.0 * fRec77[1])))) / fTemp5) + (0.80424909239999998 * (fRec17[0] * (0.0 - ((fTemp6 * fRec77[1]) + ((fRec77[0] + fRec77[2]) / fTemp4))))));
			fRec78[0] = (double(input5[i]) - (((fTemp2 * fRec78[2]) + (2.0 * (fTemp3 * fRec78[1]))) / fTemp4));
			double fTemp55 = (((fTemp1 * (fRec78[2] + (fRec78[0] + (2.0 * fRec78[1])))) / fTemp5) + (0.80424909239999998 * (fRec17[0] * (0.0 - ((fTemp6 * fRec78[1]) + ((fRec78[0] + fRec78[2]) / fTemp4))))));
			fRec79[0] = (double(input7[i]) - (((fTemp2 * fRec79[2]) + (2.0 * (fTemp3 * fRec79[1]))) / fTemp4));
			double fTemp56 = (((fTemp1 * (fRec79[2] + (fRec79[0] + (2.0 * fRec79[1])))) / fTemp5) + (0.80424909239999998 * (fRec17[0] * (0.0 - ((fTemp6 * fRec79[1]) + ((fRec79[0] + fRec79[2]) / fTemp4))))));
			fRec80[0] = (double(input8[i]) - (((fTemp2 * fRec80[2]) + (2.0 * (fTemp3 * fRec80[1]))) / fTemp4));
			double fTemp57 = (((fTemp1 * (fRec80[2] + (fRec80[0] + (2.0 * fRec80[1])))) / fTemp5) + (0.80424909239999998 * (fRec17[0] * (0.0 - ((fTemp6 * fRec80[1]) + ((fRec80[0] + fRec80[2]) / fTemp4))))));
			fRec81[0] = (double(input6[i]) - (((fTemp2 * fRec81[2]) + (2.0 * (fTemp3 * fRec81[1]))) / fTemp4));
			double fTemp58 = (((fTemp1 * (fRec81[2] + (fRec81[0] + (2.0 * fRec81[1])))) / fTemp5) + (0.80424909239999998 * (fRec17[0] * (0.0 - ((fTemp6 * fRec81[1]) + ((fRec81[0] + fRec81[2]) / fTemp4))))));
			double fTemp59 = (fConst30 * (((((0.14486916829999999 * fTemp54) + (0.0040650935999999999 * fTemp55)) + (0.0026062296 * fTemp56)) + (0.018466460899999999 * fTemp57)) - (0.075698130399999994 * fTemp58)));
			double fTemp60 = (fConst31 * fRec71[1]);
			double fTemp61 = (fConst32 * fRec74[1]);
			fRec76[0] = (fTemp59 + (fTemp60 + (fRec76[1] + fTemp61)));
			fRec74[0] = fRec76[0];
			double fRec75 = ((fTemp61 + fTemp60) + fTemp59);
			fRec73[0] = (fRec74[0] + fRec73[1]);
			fRec71[0] = fRec73[0];
			double fRec72 = fRec75;
			fRec82[0] = (double(input0[i]) - (((fRec82[2] * fTemp2) + (2.0 * (fRec82[1] * fTemp3))) / fTemp4));
			double fTemp62 = (((fTemp1 * (fRec82[2] + (fRec82[0] + (2.0 * fRec82[1])))) / fTemp5) + (fRec17[0] * (0.0 - ((fRec82[1] * fTemp6) + ((fRec82[0] + fRec82[2]) / fTemp4)))));
			fVec0[(IOTA & 1023)] = ((fRec1 + (fRec29 + (fRec50 + (fRec66 + fRec72)))) + (0.031915903699999998 * fTemp62));
			fRec83[0] = (fSlow2 + (0.999 * fRec83[1]));
			output0[i] = FAUSTFLOAT((0.8267575322812053 * (fVec0[((IOTA - iConst33) & 1023)] * fRec83[0])));
			double fTemp63 = (fConst27 * (((0.0185912996 * fTemp49) + (0.063627414500000007 * fTemp50)) - (0.0054241354999999998 * fTemp51)));
			double fTemp64 = (fConst28 * fRec84[1]);
			fRec86[0] = (fTemp63 + (fRec86[1] + fTemp64));
			fRec84[0] = fRec86[0];
			double fRec85 = (fTemp64 + fTemp63);
			double fTemp65 = (fConst30 * (((((0.071481362500000006 * fTemp54) + (0.0062330284999999996 * fTemp55)) + (0.0020855811 * fTemp56)) + (0.0513046079 * fTemp57)) - (0.081468374499999996 * fTemp58)));
			double fTemp66 = (fConst31 * fRec87[1]);
			double fTemp67 = (fConst32 * fRec90[1]);
			fRec92[0] = (fTemp65 + (fTemp66 + (fRec92[1] + fTemp67)));
			fRec90[0] = fRec92[0];
			double fRec91 = ((fTemp67 + fTemp66) + fTemp65);
			fRec89[0] = (fRec89[1] + fRec90[0]);
			fRec87[0] = fRec89[0];
			double fRec88 = fRec91;
			double fTemp68 = (fConst21 * fRec93[1]);
			double fTemp69 = (fConst23 * (((0.10134842619999999 * fTemp45) + (((0.081123957600000005 * fTemp39) + (0.020721644899999999 * fTemp40)) + (0.0078097631000000004 * fTemp41))) - (((0.019429051100000001 * fTemp42) + (0.0132151039 * fTemp43)) + (0.085447933899999995 * fTemp44))));
			double fTemp70 = (fConst24 * fRec96[1]);
			double fTemp71 = (fConst25 * fRec99[1]);
			fRec101[0] = (fTemp69 + (fTemp70 + (fRec101[1] + fTemp71)));
			fRec99[0] = fRec101[0];
			double fRec100 = ((fTemp71 + fTemp70) + fTemp69);
			fRec98[0] = (fRec98[1] + fRec99[0]);
			fRec96[0] = fRec98[0];
			double fRec97 = fRec100;
			fRec95[0] = ((fRec95[1] + fTemp68) + fRec97);
			fRec93[0] = fRec95[0];
			double fRec94 = (fTemp68 + fRec97);
			double fTemp72 = (fConst14 * fRec102[1]);
			double fTemp73 = (fConst15 * fRec105[1]);
			double fTemp74 = (fConst17 * (((0.084218105599999996 * fTemp34) + ((((0.065716091300000001 * fTemp26) + (0.0032426294 * fTemp30)) + (0.081084263500000003 * fTemp28)) + (0.0254465488 * fTemp33))) - ((0.080398074700000002 * fTemp32) + (((0.038328204800000001 * fTemp27) + (0.065865644599999995 * fTemp29)) + (0.021208278899999999 * fTemp31)))));
			double fTemp75 = (fConst18 * fRec108[1]);
			double fTemp76 = (fConst19 * fRec111[1]);
			fRec113[0] = (fTemp74 + (fTemp75 + (fRec113[1] + fTemp76)));
			fRec111[0] = fRec113[0];
			double fRec112 = ((fTemp76 + fTemp75) + fTemp74);
			fRec110[0] = (fRec110[1] + fRec111[0]);
			fRec108[0] = fRec110[0];
			double fRec109 = fRec112;
			fRec107[0] = ((fTemp72 + (fRec107[1] + fTemp73)) + fRec109);
			fRec105[0] = fRec107[0];
			double fRec106 = ((fTemp73 + fTemp72) + fRec109);
			fRec104[0] = (fRec104[1] + fRec105[0]);
			fRec102[0] = fRec104[0];
			double fRec103 = fRec106;
			double fTemp77 = (fConst12 * fRec114[1]);
			double fTemp78 = (fConst11 * fRec117[1]);
			double fTemp79 = (fConst10 * fRec120[1]);
			double fTemp80 = (fConst5 * (((0.064020723399999993 * fTemp11) + ((0.0212372124 * fTemp10) + ((0.041637842799999998 * fTemp9) + ((0.046371617499999997 * fTemp8) + ((0.18187072200000001 * fTemp7) + ((0.055604408299999998 * fTemp13) + (0.0959051764 * fTemp14))))))) - ((0.087442927200000006 * fTemp17) + ((0.051943191800000003 * fTemp16) + ((0.12100047260000001 * fTemp15) + (0.059188233999999999 * fTemp12))))));
			double fTemp81 = (fConst9 * fRec123[1]);
			double fTemp82 = (fConst7 * fRec126[1]);
			fRec128[0] = (fTemp80 + (fTemp81 + (fRec128[1] + fTemp82)));
			fRec126[0] = fRec128[0];
			double fRec127 = ((fTemp82 + fTemp81) + fTemp80);
			fRec125[0] = (fRec125[1] + fRec126[0]);
			fRec123[0] = fRec125[0];
			double fRec124 = fRec127;
			fRec122[0] = ((fTemp78 + (fRec122[1] + fTemp79)) + fRec124);
			fRec120[0] = fRec122[0];
			double fRec121 = ((fTemp79 + fTemp78) + fRec124);
			fRec119[0] = (fRec119[1] + fRec120[0]);
			fRec117[0] = fRec119[0];
			double fRec118 = fRec121;
			fRec116[0] = ((fRec116[1] + fTemp77) + fRec118);
			fRec114[0] = fRec116[0];
			double fRec115 = (fTemp77 + fRec118);
			fVec1[(IOTA & 1023)] = ((0.0369129183 * fTemp62) + ((((fRec85 + fRec88) + fRec94) + fRec103) + fRec115));
			output1[i] = FAUSTFLOAT((0.8267575322812053 * (fVec1[((IOTA - iConst33) & 1023)] * fRec83[0])));
			double fTemp83 = (fConst27 * ((0.066118168399999996 * fTemp50) - ((0.0142672398 * fTemp49) + (0.0050757312999999997 * fTemp51))));
			double fTemp84 = (fConst28 * fRec129[1]);
			fRec131[0] = (fTemp83 + (fRec131[1] + fTemp84));
			fRec129[0] = fRec131[0];
			double fRec130 = (fTemp84 + fTemp83);
			double fTemp85 = (fConst30 * (((0.0016040052 * fTemp56) + (0.053804925199999999 * fTemp57)) - (((0.057862144400000003 * fTemp54) + (0.0047049437999999999 * fTemp55)) + (0.080640596999999994 * fTemp58))));
			double fTemp86 = (fConst31 * fRec132[1]);
			double fTemp87 = (fConst32 * fRec135[1]);
			fRec137[0] = (fTemp85 + (fTemp86 + (fRec137[1] + fTemp87)));
			fRec135[0] = fRec137[0];
			double fRec136 = ((fTemp87 + fTemp86) + fTemp85);
			fRec134[0] = (fRec134[1] + fRec135[0]);
			fRec132[0] = fRec134[0];
			double fRec133 = fRec136;
			double fTemp88 = (fConst21 * fRec138[1]);
			double fTemp89 = (fConst23 * (((0.1114698152 * fTemp45) + ((((0.016818358700000001 * fTemp42) + (0.010107059599999999 * fTemp43)) + (0.0208561302 * fTemp40)) + (0.0086314637999999992 * fTemp41))) - ((0.064687567000000001 * fTemp39) + (0.088810663900000003 * fTemp44))));
			double fTemp90 = (fConst24 * fRec141[1]);
			double fTemp91 = (fConst25 * fRec144[1]);
			fRec146[0] = (fTemp89 + (fTemp90 + (fRec146[1] + fTemp91)));
			fRec144[0] = fRec146[0];
			double fRec145 = ((fTemp91 + fTemp90) + fTemp89);
			fRec143[0] = (fRec143[1] + fRec144[0]);
			fRec141[0] = fRec143[0];
			double fRec142 = fRec145;
			fRec140[0] = ((fRec140[1] + fTemp88) + fRec142);
			fRec138[0] = fRec140[0];
			double fRec139 = (fTemp88 + fRec142);
			double fTemp92 = (fConst14 * fRec147[1]);
			double fTemp93 = (fConst15 * fRec150[1]);
			double fTemp94 = (fConst17 * (((0.1043893675 * fTemp34) + ((((0.030307607600000001 * fTemp27) + (0.054087512499999997 * fTemp29)) + (0.0803864564 * fTemp28)) + (0.039002649399999999 * fTemp33))) - ((0.083580178300000002 * fTemp32) + (((0.054389761799999999 * fTemp26) + (0.0028430129000000001 * fTemp30)) + (0.020090476999999999 * fTemp31)))));
			double fTemp95 = (fConst18 * fRec153[1]);
			double fTemp96 = (fConst19 * fRec156[1]);
			fRec158[0] = (fTemp94 + (fTemp95 + (fRec158[1] + fTemp96)));
			fRec156[0] = fRec158[0];
			double fRec157 = ((fTemp96 + fTemp95) + fTemp94);
			fRec155[0] = (fRec155[1] + fRec156[0]);
			fRec153[0] = fRec155[0];
			double fRec154 = fRec157;
			fRec152[0] = ((fTemp92 + (fRec152[1] + fTemp93)) + fRec154);
			fRec150[0] = fRec152[0];
			double fRec151 = ((fTemp93 + fTemp92) + fRec154);
			fRec149[0] = (fRec149[1] + fRec150[0]);
			fRec147[0] = fRec149[0];
			double fRec148 = fRec151;
			double fTemp97 = (fConst12 * fRec159[1]);
			double fTemp98 = (fConst11 * fRec162[1]);
			double fTemp99 = (fConst10 * fRec165[1]);
			double fTemp100 = (fConst5 * (((0.068769898100000004 * fTemp11) + ((0.096145960099999997 * fTemp15) + ((0.069892949300000007 * fTemp13) + (0.1371724775 * fTemp14)))) - ((0.091299878400000006 * fTemp17) + ((0.0522860001 * fTemp16) + ((0.016668330799999999 * fTemp10) + ((0.034781521199999998 * fTemp9) + ((0.038379355499999997 * fTemp8) + ((0.15328913920000001 * fTemp7) + (0.0513229771 * fTemp12)))))))));
			double fTemp101 = (fConst9 * fRec168[1]);
			double fTemp102 = (fConst7 * fRec171[1]);
			fRec173[0] = (fTemp100 + (fTemp101 + (fRec173[1] + fTemp102)));
			fRec171[0] = fRec173[0];
			double fRec172 = ((fTemp102 + fTemp101) + fTemp100);
			fRec170[0] = (fRec170[1] + fRec171[0]);
			fRec168[0] = fRec170[0];
			double fRec169 = fRec172;
			fRec167[0] = ((fTemp98 + (fRec167[1] + fTemp99)) + fRec169);
			fRec165[0] = fRec167[0];
			double fRec166 = ((fTemp99 + fTemp98) + fRec169);
			fRec164[0] = (fRec164[1] + fRec165[0]);
			fRec162[0] = fRec164[0];
			double fRec163 = fRec166;
			fRec161[0] = ((fRec161[1] + fTemp97) + fRec163);
			fRec159[0] = fRec161[0];
			double fRec160 = (fTemp97 + fRec163);
			fVec2[(IOTA & 1023)] = ((0.036848998199999997 * fTemp62) + ((((fRec130 + fRec133) + fRec139) + fRec148) + fRec160));
			output2[i] = FAUSTFLOAT((0.8267575322812053 * (fVec2[((IOTA - iConst33) & 1023)] * fRec83[0])));
			double fTemp103 = (fConst12 * fRec174[1]);
			double fTemp104 = (fConst11 * fRec177[1]);
			double fTemp105 = (fConst10 * fRec180[1]);
			double fTemp106 = (fConst5 * (((0.12966754159999999 * fTemp15) + (0.050761161399999997 * fTemp11)) - ((0.0418594433 * fTemp17) + ((0.035600671299999997 * fTemp16) + ((0.042285400500000001 * fTemp10) + ((0.074000902499999993 * fTemp9) + ((0.044177802799999999 * fTemp8) + ((0.059223297699999997 * fTemp7) + ((0.19778170510000001 * fTemp14) + ((0.036504425299999997 * fTemp12) + (0.062536989500000001 * fTemp13)))))))))));
			double fTemp107 = (fConst9 * fRec183[1]);
			double fTemp108 = (fConst7 * fRec186[1]);
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
			double fTemp109 = (fConst14 * fRec189[1]);
			double fTemp110 = (fConst15 * fRec192[1]);
			double fTemp111 = (fConst17 * (((((0.011552084400000001 * fTemp27) + (0.1244178437 * fTemp29)) + (0.0044020494999999996 * fTemp30)) + (0.073523955000000002 * fTemp28)) - ((0.083645878899999998 * fTemp34) + ((0.041625152399999997 * fTemp33) + ((0.040349084299999997 * fTemp32) + ((0.062607100600000007 * fTemp26) + (0.023139957999999999 * fTemp31)))))));
			double fTemp112 = (fConst18 * fRec195[1]);
			double fTemp113 = (fConst19 * fRec198[1]);
			fRec200[0] = (fTemp111 + (fTemp112 + (fRec200[1] + fTemp113)));
			fRec198[0] = fRec200[0];
			double fRec199 = ((fTemp113 + fTemp112) + fTemp111);
			fRec197[0] = (fRec198[0] + fRec197[1]);
			fRec195[0] = fRec197[0];
			double fRec196 = fRec199;
			fRec194[0] = (fTemp109 + (fTemp110 + (fRec196 + fRec194[1])));
			fRec192[0] = fRec194[0];
			double fRec193 = (fTemp109 + (fRec196 + fTemp110));
			fRec191[0] = (fRec191[1] + fRec192[0]);
			fRec189[0] = fRec191[0];
			double fRec190 = fRec193;
			double fTemp114 = (fConst27 * ((0.054453409299999998 * fTemp50) - ((0.038670070100000002 * fTemp49) + (0.0058798358999999998 * fTemp51))));
			double fTemp115 = (fConst28 * fRec201[1]);
			fRec203[0] = (fTemp114 + (fRec203[1] + fTemp115));
			fRec201[0] = fRec203[0];
			double fRec202 = (fTemp115 + fTemp114);
			double fTemp116 = (fConst30 * (((0.0023833714000000002 * fTemp56) + (0.0233459536 * fTemp57)) - (((0.14163052719999999 * fTemp54) + (0.0059285444000000001 * fTemp55)) + (0.076677825599999999 * fTemp58))));
			double fTemp117 = (fConst31 * fRec204[1]);
			double fTemp118 = (fConst32 * fRec207[1]);
			fRec209[0] = (fTemp116 + (fTemp117 + (fRec209[1] + fTemp118)));
			fRec207[0] = fRec209[0];
			double fRec208 = ((fTemp118 + fTemp117) + fTemp116);
			fRec206[0] = (fRec206[1] + fRec207[0]);
			fRec204[0] = fRec206[0];
			double fRec205 = fRec208;
			double fTemp119 = (fConst21 * fRec210[1]);
			double fTemp120 = (fConst23 * (((((0.0298849401 * fTemp42) + (0.042104462400000001 * fTemp43)) + (0.0122011844 * fTemp40)) + (0.0012980638 * fTemp41)) - (((0.127746515 * fTemp39) + (0.074500082100000004 * fTemp44)) + (0.016875958399999998 * fTemp45))));
			double fTemp121 = (fConst24 * fRec213[1]);
			double fTemp122 = (fConst25 * fRec216[1]);
			fRec218[0] = (fTemp120 + (fTemp121 + (fRec218[1] + fTemp122)));
			fRec216[0] = fRec218[0];
			double fRec217 = ((fTemp122 + fTemp121) + fTemp120);
			fRec215[0] = (fRec215[1] + fRec216[0]);
			fRec213[0] = fRec215[0];
			double fRec214 = fRec217;
			fRec212[0] = ((fRec212[1] + fTemp119) + fRec214);
			fRec210[0] = fRec212[0];
			double fRec211 = (fTemp119 + fRec214);
			fVec3[(IOTA & 1023)] = ((0.032556310800000002 * fTemp62) + (fRec175 + (fRec190 + ((fRec202 + fRec205) + fRec211))));
			output3[i] = FAUSTFLOAT((0.8267575322812053 * (fRec83[0] * fVec3[((IOTA - iConst33) & 1023)])));
			double fTemp123 = (fConst14 * fRec219[1]);
			double fTemp124 = (fConst15 * fRec222[1]);
			double fTemp125 = (fConst17 * ((((((0.059164053600000002 * fTemp26) + (0.12143845640000001 * fTemp29)) + (0.021413306900000002 * fTemp30)) + (0.075425401399999994 * fTemp28)) + (0.037325058199999997 * fTemp32)) - ((0.098118552900000003 * fTemp34) + (((0.046228425300000001 * fTemp27) + (0.0077005208 * fTemp31)) + (0.011912267900000001 * fTemp33)))));
			double fTemp126 = (fConst18 * fRec225[1]);
			double fTemp127 = (fConst19 * fRec228[1]);
			fRec230[0] = (fTemp125 + (fTemp126 + (fRec230[1] + fTemp127)));
			fRec228[0] = fRec230[0];
			double fRec229 = ((fTemp127 + fTemp126) + fTemp125);
			fRec227[0] = (fRec228[0] + fRec227[1]);
			fRec225[0] = fRec227[0];
			double fRec226 = fRec229;
			fRec224[0] = (fTemp123 + (fTemp124 + (fRec226 + fRec224[1])));
			fRec222[0] = fRec224[0];
			double fRec223 = (fTemp123 + (fRec226 + fTemp124));
			fRec221[0] = (fRec222[0] + fRec221[1]);
			fRec219[0] = fRec221[0];
			double fRec220 = fRec223;
			double fTemp128 = (fConst21 * fRec231[1]);
			double fTemp129 = (fConst23 * (((((0.0223062539 * fTemp42) + (0.077789424999999995 * fTemp43)) + (0.012909207900000001 * fTemp40)) + (0.00041155309999999997 * fTemp41)) - (((0.030270827 * fTemp39) + (0.046459995699999999 * fTemp44)) + (0.12721546310000001 * fTemp45))));
			double fTemp130 = (fConst24 * fRec234[1]);
			double fTemp131 = (fConst25 * fRec237[1]);
			fRec239[0] = (fTemp129 + (fTemp130 + (fRec239[1] + fTemp131)));
			fRec237[0] = fRec239[0];
			double fRec238 = ((fTemp131 + fTemp130) + fTemp129);
			fRec236[0] = (fRec237[0] + fRec236[1]);
			fRec234[0] = fRec236[0];
			double fRec235 = fRec238;
			fRec233[0] = (fTemp128 + (fRec235 + fRec233[1]));
			fRec231[0] = fRec233[0];
			double fRec232 = (fRec235 + fTemp128);
			double fTemp132 = (fConst30 * (((0.0011418178999999999 * fTemp55) + (0.0042795486000000004 * fTemp56)) - (((0.14488948739999999 * fTemp54) + (0.078398546099999994 * fTemp58)) + (0.0201188024 * fTemp57))));
			double fTemp133 = (fConst31 * fRec240[1]);
			double fTemp134 = (fConst32 * fRec243[1]);
			fRec245[0] = (fTemp132 + (fTemp133 + (fRec245[1] + fTemp134)));
			fRec243[0] = fRec245[0];
			double fRec244 = ((fTemp134 + fTemp133) + fTemp132);
			fRec242[0] = (fRec243[0] + fRec242[1]);
			fRec240[0] = fRec242[0];
			double fRec241 = fRec244;
			double fTemp135 = (fConst12 * fRec246[1]);
			double fTemp136 = (fConst11 * fRec249[1]);
			double fTemp137 = (fConst10 * fRec252[1]);
			double fTemp138 = (fConst5 * (((0.0374765788 * fTemp17) + ((0.041856115899999997 * fTemp11) + ((0.041748265999999999 * fTemp8) + ((0.20438640790000001 * fTemp7) + ((0.0997563063 * fTemp12) + (0.022775990900000001 * fTemp14)))))) - ((0.036560098300000003 * fTemp16) + ((0.054935586299999999 * fTemp10) + ((0.067545126699999999 * fTemp9) + ((0.030202557000000001 * fTemp15) + (0.072861358000000001 * fTemp13)))))));
			double fTemp139 = (fConst9 * fRec255[1]);
			double fTemp140 = (fConst7 * fRec258[1]);
			fRec260[0] = (fTemp138 + (fTemp139 + (fRec260[1] + fTemp140)));
			fRec258[0] = fRec260[0];
			double fRec259 = ((fTemp140 + fTemp139) + fTemp138);
			fRec257[0] = (fRec258[0] + fRec257[1]);
			fRec255[0] = fRec257[0];
			double fRec256 = fRec259;
			fRec254[0] = (fTemp136 + (fTemp137 + (fRec256 + fRec254[1])));
			fRec252[0] = fRec254[0];
			double fRec253 = (fTemp136 + (fRec256 + fTemp137));
			fRec251[0] = (fRec252[0] + fRec251[1]);
			fRec249[0] = fRec251[0];
			double fRec250 = fRec253;
			fRec248[0] = (fTemp135 + (fRec250 + fRec248[1]));
			fRec246[0] = fRec248[0];
			double fRec247 = (fRec250 + fTemp135);
			double fTemp141 = (fConst27 * ((0.039215482000000003 * fTemp50) - ((0.053579492100000001 * fTemp49) + (0.0064722301000000003 * fTemp51))));
			double fTemp142 = (fConst28 * fRec261[1]);
			fRec263[0] = (fTemp141 + (fRec263[1] + fTemp142));
			fRec261[0] = fRec263[0];
			double fRec262 = (fTemp142 + fTemp141);
			fVec4[(IOTA & 1023)] = ((0.033002012099999999 * fTemp62) + (fRec220 + (fRec232 + (fRec241 + (fRec247 + fRec262)))));
			output4[i] = FAUSTFLOAT((0.8267575322812053 * (fRec83[0] * fVec4[((IOTA - iConst33) & 1023)])));
			double fTemp143 = (fConst12 * fRec264[1]);
			double fTemp144 = (fConst11 * fRec267[1]);
			double fTemp145 = (fConst10 * fRec270[1]);
			double fTemp146 = (fConst5 * (((0.089776510700000006 * fTemp17) + ((0.0244482806 * fTemp11) + ((0.040416472000000002 * fTemp8) + ((0.1730603205 * fTemp14) + ((0.1105277009 * fTemp12) + (0.0614972503 * fTemp13)))))) - (((((0.10412815910000001 * fTemp7) + (0.069660156200000004 * fTemp15)) + (0.039207167000000001 * fTemp9)) + (0.063541491699999994 * fTemp10)) + (0.053014165100000003 * fTemp16))));
			double fTemp147 = (fConst9 * fRec273[1]);
			double fTemp148 = (fConst7 * fRec276[1]);
			fRec278[0] = (fTemp146 + (fTemp147 + (fRec278[1] + fTemp148)));
			fRec276[0] = fRec278[0];
			double fRec277 = ((fTemp148 + fTemp147) + fTemp146);
			fRec275[0] = (fRec276[0] + fRec275[1]);
			fRec273[0] = fRec275[0];
			double fRec274 = fRec277;
			fRec272[0] = (fTemp144 + (fTemp145 + (fRec274 + fRec272[1])));
			fRec270[0] = fRec272[0];
			double fRec271 = (fTemp144 + (fRec274 + fTemp145));
			fRec269[0] = (fRec270[0] + fRec269[1]);
			fRec267[0] = fRec269[0];
			double fRec268 = fRec271;
			fRec266[0] = (fTemp143 + (fRec268 + fRec266[1]));
			fRec264[0] = fRec266[0];
			double fRec265 = (fRec268 + fTemp143);
			double fTemp149 = (fConst14 * fRec279[1]);
			double fTemp150 = (fConst15 * fRec282[1]);
			double fTemp151 = (fConst17 * (((((((((0.057276685799999998 * fTemp26) + (0.020912804300000001 * fTemp27)) + (0.061704646500000002 * fTemp29)) + (0.022814019899999999 * fTemp30)) + (0.081989500100000001 * fTemp28)) + (0.0042275252000000003 * fTemp31)) + (0.083958765899999996 * fTemp32)) + (0.0348468501 * fTemp33)) + (0.0926261471 * fTemp34)));
			double fTemp152 = (fConst18 * fRec285[1]);
			double fTemp153 = (fConst19 * fRec288[1]);
			fRec290[0] = (fTemp151 + (fTemp152 + (fRec290[1] + fTemp153)));
			fRec288[0] = fRec290[0];
			double fRec289 = ((fTemp153 + fTemp152) + fTemp151);
			fRec287[0] = (fRec288[0] + fRec287[1]);
			fRec285[0] = fRec287[0];
			double fRec286 = fRec289;
			fRec284[0] = (fTemp149 + (fTemp150 + (fRec286 + fRec284[1])));
			fRec282[0] = fRec284[0];
			double fRec283 = (fTemp149 + (fRec286 + fTemp150));
			fRec281[0] = (fRec282[0] + fRec281[1]);
			fRec279[0] = fRec281[0];
			double fRec280 = fRec283;
			double fTemp154 = (fConst21 * fRec291[1]);
			double fTemp155 = (fConst23 * (((((0.10662735080000001 * fTemp39) + (0.0184943404 * fTemp42)) + (0.086745120199999998 * fTemp43)) + (0.021183794799999999 * fTemp40)) - ((0.074329073499999995 * fTemp45) + ((0.016708374299999999 * fTemp44) + (0.0061634515999999997 * fTemp41)))));
			double fTemp156 = (fConst24 * fRec294[1]);
			double fTemp157 = (fConst25 * fRec297[1]);
			fRec299[0] = (fTemp155 + (fTemp156 + (fRec299[1] + fTemp157)));
			fRec297[0] = fRec299[0];
			double fRec298 = ((fTemp157 + fTemp156) + fTemp155);
			fRec296[0] = (fRec297[0] + fRec296[1]);
			fRec294[0] = fRec296[0];
			double fRec295 = fRec298;
			fRec293[0] = (fTemp154 + (fRec295 + fRec293[1]));
			fRec291[0] = fRec293[0];
			double fRec292 = (fRec295 + fTemp154);
			double fTemp158 = (fConst27 * ((0.017286134599999999 * fTemp50) - ((0.064869700299999999 * fTemp49) + (0.0053982073999999996 * fTemp51))));
			double fTemp159 = (fConst28 * fRec300[1]);
			fRec302[0] = (fTemp158 + (fRec302[1] + fTemp159));
			fRec300[0] = fRec302[0];
			double fRec301 = (fTemp159 + fTemp158);
			double fTemp160 = (fConst30 * ((0.0023768713000000001 * fTemp56) - ((((0.066681959400000004 * fTemp54) + (0.0027025223999999999 * fTemp55)) + (0.082299095399999994 * fTemp58)) + (0.051751264700000001 * fTemp57))));
			double fTemp161 = (fConst31 * fRec303[1]);
			double fTemp162 = (fConst32 * fRec306[1]);
			fRec308[0] = (fTemp160 + (fTemp161 + (fRec308[1] + fTemp162)));
			fRec306[0] = fRec308[0];
			double fRec307 = ((fTemp162 + fTemp161) + fTemp160);
			fRec305[0] = (fRec306[0] + fRec305[1]);
			fRec303[0] = fRec305[0];
			double fRec304 = fRec307;
			fVec5[(IOTA & 1023)] = ((0.0374096893 * fTemp62) + (fRec265 + (fRec280 + (fRec292 + (fRec301 + fRec304)))));
			output5[i] = FAUSTFLOAT((0.8267575322812053 * (fRec83[0] * fVec5[((IOTA - iConst33) & 1023)])));
			double fTemp163 = (fConst12 * fRec309[1]);
			double fTemp164 = (fConst11 * fRec312[1]);
			double fTemp165 = (fConst10 * fRec315[1]);
			double fTemp166 = (fConst5 * (((0.088247828200000003 * fTemp17) + ((0.0274919278 * fTemp9) + (0.062405966 * fTemp13))) - ((0.021423617999999998 * fTemp11) + ((0.052141916500000003 * fTemp16) + ((0.064851481399999994 * fTemp10) + ((0.056318213899999997 * fTemp15) + ((0.044225964899999998 * fTemp8) + ((0.1164055676 * fTemp7) + ((0.090800493100000004 * fTemp12) + (0.1732095692 * fTemp14))))))))));
			double fTemp167 = (fConst9 * fRec318[1]);
			double fTemp168 = (fConst7 * fRec321[1]);
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
			double fTemp169 = (fConst14 * fRec324[1]);
			double fTemp170 = (fConst15 * fRec327[1]);
			double fTemp171 = (fConst17 * ((((((0.032682388700000002 * fTemp27) + (0.022455359099999999 * fTemp30)) + (0.081933381099999994 * fTemp28)) + (0.075156038600000002 * fTemp32)) + (0.093884656699999999 * fTemp34)) - ((((0.062675354099999997 * fTemp26) + (0.051068333399999999 * fTemp29)) + (0.0019029863000000001 * fTemp31)) + (0.0189869867 * fTemp33))));
			double fTemp172 = (fConst18 * fRec330[1]);
			double fTemp173 = (fConst19 * fRec333[1]);
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
			double fTemp174 = (fConst21 * fRec336[1]);
			double fTemp175 = (fConst23 * ((((((0.1082267473 * fTemp39) + (0.086702091999999994 * fTemp43)) + (0.020319278699999999 * fTemp40)) + (0.016734131700000002 * fTemp44)) + (0.074580207600000004 * fTemp45)) - ((0.0080429993000000009 * fTemp42) + (0.0157221276 * fTemp41))));
			double fTemp176 = (fConst24 * fRec339[1]);
			double fTemp177 = (fConst25 * fRec342[1]);
			fRec344[0] = (fTemp175 + (fTemp176 + (fRec344[1] + fTemp177)));
			fRec342[0] = fRec344[0];
			double fRec343 = ((fTemp177 + fTemp176) + fTemp175);
			fRec341[0] = (fRec342[0] + fRec341[1]);
			fRec339[0] = fRec341[0];
			double fRec340 = fRec343;
			fRec338[0] = (fTemp174 + (fRec340 + fRec338[1]));
			fRec336[0] = fRec338[0];
			double fRec337 = (fRec340 + fTemp174);
			double fTemp178 = (fConst27 * (0.0 - (((0.067097908400000003 * fTemp49) + (0.0050188408000000004 * fTemp51)) + (0.016695940999999999 * fTemp50))));
			double fTemp179 = (fConst28 * fRec345[1]);
			fRec347[0] = (fTemp178 + (fRec347[1] + fTemp179));
			fRec345[0] = fRec347[0];
			double fRec346 = (fTemp179 + fTemp178);
			double fTemp180 = (fConst30 * ((0.062226164799999997 * fTemp54) - ((((0.0045938784000000002 * fTemp55) + (0.082699632499999995 * fTemp58)) + (0.002466644 * fTemp56)) + (0.055676557100000003 * fTemp57))));
			double fTemp181 = (fConst31 * fRec348[1]);
			double fTemp182 = (fConst32 * fRec351[1]);
			fRec353[0] = (fTemp180 + (fTemp181 + (fRec353[1] + fTemp182)));
			fRec351[0] = fRec353[0];
			double fRec352 = ((fTemp182 + fTemp181) + fTemp180);
			fRec350[0] = (fRec351[0] + fRec350[1]);
			fRec348[0] = fRec350[0];
			double fRec349 = fRec352;
			fVec6[(IOTA & 1023)] = ((0.037718380699999998 * fTemp62) + (fRec310 + (fRec325 + (fRec337 + (fRec346 + fRec349)))));
			output6[i] = FAUSTFLOAT((0.8267575322812053 * (fRec83[0] * fVec6[((IOTA - iConst33) & 1023)])));
			double fTemp183 = (fConst12 * fRec354[1]);
			double fTemp184 = (fConst11 * fRec357[1]);
			double fTemp185 = (fConst10 * fRec360[1]);
			double fTemp186 = (fConst5 * ((((0.1996674061 * fTemp7) + (0.088963915300000002 * fTemp9)) + (0.036553115900000002 * fTemp17)) - ((0.047167287699999998 * fTemp11) + ((0.036103065500000003 * fTemp16) + ((0.056095484000000001 * fTemp10) + ((0.018354847000000001 * fTemp15) + ((0.036040297200000002 * fTemp8) + ((0.0203859043 * fTemp14) + ((0.1249186868 * fTemp12) + (0.072783185599999994 * fTemp13))))))))));
			double fTemp187 = (fConst9 * fRec363[1]);
			double fTemp188 = (fConst7 * fRec366[1]);
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
			double fTemp189 = (fConst14 * fRec369[1]);
			double fTemp190 = (fConst15 * fRec372[1]);
			double fTemp191 = (fConst17 * (((0.035216031500000002 * fTemp32) + ((0.0051551801000000001 * fTemp31) + ((0.0207759946 * fTemp30) + (0.075656136900000004 * fTemp28)))) - ((0.098012779300000005 * fTemp34) + ((((0.051074937500000001 * fTemp26) + (0.038198428100000001 * fTemp27)) + (0.14212083759999999 * fTemp29)) + (0.0069380257000000002 * fTemp33)))));
			double fTemp192 = (fConst18 * fRec375[1]);
			double fTemp193 = (fConst19 * fRec378[1]);
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
			double fTemp194 = (fConst21 * fRec381[1]);
			double fTemp195 = (fConst23 * (((((0.077650412799999999 * fTemp43) + (0.012570947799999999 * fTemp40)) + (0.048356337700000002 * fTemp44)) + (0.12880852719999999 * fTemp45)) - (((0.0322185397 * fTemp39) + (0.040633841599999998 * fTemp42)) + (0.0011573505999999999 * fTemp41))));
			double fTemp196 = (fConst24 * fRec384[1]);
			double fTemp197 = (fConst25 * fRec387[1]);
			fRec389[0] = (fTemp195 + (fTemp196 + (fRec389[1] + fTemp197)));
			fRec387[0] = fRec389[0];
			double fRec388 = ((fTemp197 + fTemp196) + fTemp195);
			fRec386[0] = (fRec387[0] + fRec386[1]);
			fRec384[0] = fRec386[0];
			double fRec385 = fRec388;
			fRec383[0] = (fTemp194 + (fRec385 + fRec383[1]));
			fRec381[0] = fRec383[0];
			double fRec382 = (fRec385 + fTemp194);
			double fTemp198 = (fConst27 * (0.0 - (((0.054767478100000003 * fTemp49) + (0.0063893832000000003 * fTemp51)) + (0.041206921600000002 * fTemp50))));
			double fTemp199 = (fConst28 * fRec390[1]);
			fRec392[0] = (fTemp198 + (fRec392[1] + fTemp199));
			fRec390[0] = fRec392[0];
			double fRec391 = (fTemp199 + fTemp198);
			double fTemp200 = (fConst30 * (((0.15548714629999999 * fTemp54) + (0.00017056619999999999 * fTemp55)) - (((0.0787746904 * fTemp58) + (0.0040260169999999998 * fTemp56)) + (0.0203983511 * fTemp57))));
			double fTemp201 = (fConst31 * fRec393[1]);
			double fTemp202 = (fConst32 * fRec396[1]);
			fRec398[0] = (fTemp200 + (fTemp201 + (fRec398[1] + fTemp202)));
			fRec396[0] = fRec398[0];
			double fRec397 = ((fTemp202 + fTemp201) + fTemp200);
			fRec395[0] = (fRec396[0] + fRec395[1]);
			fRec393[0] = fRec395[0];
			double fRec394 = fRec397;
			fVec7[(IOTA & 1023)] = ((0.0331655098 * fTemp62) + (fRec355 + (fRec370 + (fRec382 + (fRec391 + fRec394)))));
			output7[i] = FAUSTFLOAT((0.8267575322812053 * (fRec83[0] * fVec7[((IOTA - iConst33) & 1023)])));
			double fTemp203 = (fConst12 * fRec399[1]);
			double fTemp204 = (fConst11 * fRec402[1]);
			double fTemp205 = (fConst10 * fRec405[1]);
			double fTemp206 = (fConst5 * (((0.070510830199999999 * fTemp9) + ((0.1131714181 * fTemp15) + ((0.043403162100000003 * fTemp8) + ((0.0208688785 * fTemp12) + (0.1920699515 * fTemp14))))) - ((0.037381227000000003 * fTemp17) + ((0.050608693099999998 * fTemp11) + ((0.036636271400000003 * fTemp16) + ((0.041372498799999997 * fTemp10) + ((0.051906412800000003 * fTemp7) + (0.060042992599999997 * fTemp13))))))));
			double fTemp207 = (fConst9 * fRec408[1]);
			double fTemp208 = (fConst7 * fRec411[1]);
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
			double fTemp211 = (fConst17 * ((((0.020895256099999999 * fTemp31) + ((((0.061509309200000001 * fTemp26) + (0.00049522430000000005 * fTemp27)) + (0.0049728766000000004 * fTemp30)) + (0.073200529 * fTemp28))) + (0.028978002499999999 * fTemp33)) - (((0.1205530373 * fTemp29) + (0.0280639177 * fTemp32)) + (0.080109256300000001 * fTemp34))));
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
			double fTemp215 = (fConst23 * (((0.0165944697 * fTemp45) + ((0.0116032172 * fTemp41) + (((0.042839800300000001 * fTemp43) + (0.013233296800000001 * fTemp40)) + (0.071438072199999994 * fTemp44)))) - ((0.1248582384 * fTemp39) + (0.027210898300000001 * fTemp42))));
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
			double fTemp218 = (fConst27 * (0.0 - (((0.0368298362 * fTemp49) + (0.0062292472000000003 * fTemp51)) + (0.0530919719 * fTemp50))));
			double fTemp219 = (fConst28 * fRec435[1]);
			fRec437[0] = (fTemp218 + (fRec437[1] + fTemp219));
			fRec435[0] = fRec437[0];
			double fRec436 = (fTemp219 + fTemp218);
			double fTemp220 = (fConst30 * (((0.1389227083 * fTemp54) + (0.026043000399999999 * fTemp57)) - (((0.0039483186000000003 * fTemp55) + (0.075771452700000005 * fTemp58)) + (0.0027106964 * fTemp56))));
			double fTemp221 = (fConst31 * fRec438[1]);
			double fTemp222 = (fConst32 * fRec441[1]);
			fRec443[0] = (fTemp220 + (fTemp221 + (fRec443[1] + fTemp222)));
			fRec441[0] = fRec443[0];
			double fRec442 = ((fTemp222 + fTemp221) + fTemp220);
			fRec440[0] = (fRec441[0] + fRec440[1]);
			fRec438[0] = fRec440[0];
			double fRec439 = fRec442;
			fVec8[(IOTA & 1023)] = ((0.032078024900000002 * fTemp62) + (fRec400 + (fRec415 + (fRec427 + (fRec436 + fRec439)))));
			output8[i] = FAUSTFLOAT((0.8267575322812053 * (fRec83[0] * fVec8[((IOTA - iConst33) & 1023)])));
			double fTemp223 = (fConst12 * fRec444[1]);
			double fTemp224 = (fConst11 * fRec447[1]);
			double fTemp225 = (fConst10 * fRec450[1]);
			double fTemp226 = (fConst5 * (((0.017805514099999999 * fTemp9) + ((0.089435550000000003 * fTemp15) + ((0.035312753099999997 * fTemp8) + ((0.074061578200000006 * fTemp12) + (0.063335743200000003 * fTemp13))))) - ((0.090496970800000007 * fTemp17) + ((0.062737669800000007 * fTemp11) + ((0.050671260000000003 * fTemp16) + ((0.015569609200000001 * fTemp10) + ((0.15226587499999999 * fTemp7) + (0.12497131440000001 * fTemp14))))))));
			double fTemp227 = (fConst9 * fRec453[1]);
			double fTemp228 = (fConst7 * fRec456[1]);
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
			double fTemp229 = (fConst14 * fRec459[1]);
			double fTemp230 = (fConst15 * fRec462[1]);
			double fTemp231 = (fConst17 * ((((0.022278112799999999 * fTemp31) + (((0.050043889500000001 * fTemp26) + (0.024799689100000001 * fTemp27)) + (0.078136899699999998 * fTemp28))) + (0.094967559800000004 * fTemp34)) - ((0.018995331800000001 * fTemp33) + (((0.037519194700000001 * fTemp29) + (0.0021347090999999999 * fTemp30)) + (0.087492656099999996 * fTemp32)))));
			double fTemp232 = (fConst18 * fRec465[1]);
			double fTemp233 = (fConst19 * fRec468[1]);
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
			double fTemp234 = (fConst21 * fRec471[1]);
			double fTemp235 = (fConst23 * (((0.0024642763000000002 * fTemp41) + (((0.0099894992999999994 * fTemp43) + (0.0199360328 * fTemp40)) + (0.085825365799999997 * fTemp44))) - (((0.064928955299999994 * fTemp39) + (0.0024034564000000001 * fTemp42)) + (0.1087851235 * fTemp45))));
			double fTemp236 = (fConst24 * fRec474[1]);
			double fTemp237 = (fConst25 * fRec477[1]);
			fRec479[0] = (fTemp235 + (fTemp236 + (fRec479[1] + fTemp237)));
			fRec477[0] = fRec479[0];
			double fRec478 = ((fTemp237 + fTemp236) + fTemp235);
			fRec476[0] = (fRec477[0] + fRec476[1]);
			fRec474[0] = fRec476[0];
			double fRec475 = fRec478;
			fRec473[0] = (fTemp234 + (fRec475 + fRec473[1]));
			fRec471[0] = fRec473[0];
			double fRec472 = (fRec475 + fTemp234);
			double fTemp238 = (fConst27 * (0.0 - (((0.013880590199999999 * fTemp49) + (0.0048236802000000004 * fTemp51)) + (0.063194563300000006 * fTemp50))));
			double fTemp239 = (fConst28 * fRec480[1]);
			fRec482[0] = (fTemp238 + (fRec482[1] + fTemp239));
			fRec480[0] = fRec482[0];
			double fRec481 = (fTemp239 + fTemp238);
			double fTemp240 = (fConst30 * (((0.049113772299999997 * fTemp54) + (0.0503020733 * fTemp57)) - (((0.0046381034999999999 * fTemp55) + (0.078667115400000001 * fTemp58)) + (0.0017092895999999999 * fTemp56))));
			double fTemp241 = (fConst31 * fRec483[1]);
			double fTemp242 = (fConst32 * fRec486[1]);
			fRec488[0] = (fTemp240 + (fTemp241 + (fRec488[1] + fTemp242)));
			fRec486[0] = fRec488[0];
			double fRec487 = ((fTemp242 + fTemp241) + fTemp240);
			fRec485[0] = (fRec486[0] + fRec485[1]);
			fRec483[0] = fRec485[0];
			double fRec484 = fRec487;
			fVec9[(IOTA & 1023)] = ((0.035971087499999999 * fTemp62) + (fRec445 + (fRec460 + (fRec472 + (fRec481 + fRec484)))));
			output9[i] = FAUSTFLOAT((0.8267575322812053 * (fRec83[0] * fVec9[((IOTA - iConst33) & 1023)])));
			double fTemp243 = (fConst12 * fRec489[1]);
			double fTemp244 = (fConst11 * fRec492[1]);
			double fTemp245 = (fConst10 * fRec495[1]);
			double fTemp246 = (fConst5 * (((0.0196338634 * fTemp10) + ((0.16888266690000001 * fTemp7) + ((0.070094166299999996 * fTemp12) + (0.0593069367 * fTemp13)))) - ((0.090247121 * fTemp17) + ((0.0646979736 * fTemp11) + ((0.050975128699999997 * fTemp16) + ((0.026599327499999999 * fTemp9) + ((0.1022625996 * fTemp15) + ((0.041601812100000003 * fTemp8) + (0.1055876498 * fTemp14)))))))));
			double fTemp247 = (fConst9 * fRec498[1]);
			double fTemp248 = (fConst7 * fRec501[1]);
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
			double fTemp249 = (fConst14 * fRec504[1]);
			double fTemp250 = (fConst15 * fRec507[1]);
			double fTemp251 = (fConst17 * ((((0.022331621699999998 * fTemp31) + (((0.050411412099999997 * fTemp29) + (0.002415997 * fTemp30)) + (0.080208881699999998 * fTemp28))) + (0.089378991300000002 * fTemp34)) - ((0.0182310376 * fTemp33) + (((0.058956504600000001 * fTemp26) + (0.027138249400000002 * fTemp27)) + (0.087580682300000004 * fTemp32)))));
			double fTemp252 = (fConst18 * fRec510[1]);
			double fTemp253 = (fConst19 * fRec513[1]);
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
			double fTemp254 = (fConst27 * ((0.0166327621 * fTemp49) - ((0.0050725312 * fTemp51) + (0.064337694000000001 * fTemp50))));
			double fTemp255 = (fConst28 * fRec516[1]);
			fRec518[0] = (fTemp254 + (fRec518[1] + fTemp255));
			fRec516[0] = fRec518[0];
			double fRec517 = (fTemp255 + fTemp254);
			double fTemp256 = (fConst30 * (((0.0045441995999999998 * fTemp55) + (0.049948343499999999 * fTemp57)) - (((0.062190993700000002 * fTemp54) + (0.080824460700000003 * fTemp58)) + (0.0013458698 * fTemp56))));
			double fTemp257 = (fConst31 * fRec519[1]);
			double fTemp258 = (fConst32 * fRec522[1]);
			fRec524[0] = (fTemp256 + (fTemp257 + (fRec524[1] + fTemp258)));
			fRec522[0] = fRec524[0];
			double fRec523 = ((fTemp258 + fTemp257) + fTemp256);
			fRec521[0] = (fRec521[1] + fRec522[0]);
			fRec519[0] = fRec521[0];
			double fRec520 = fRec523;
			double fTemp259 = (fConst23 * (((0.002025504 * fTemp41) + ((((0.075922754699999997 * fTemp39) + (0.0071498042999999997 * fTemp42)) + (0.0200334515 * fTemp40)) + (0.087829762699999994 * fTemp44))) - ((0.013485794799999999 * fTemp43) + (0.1033652783 * fTemp45))));
			double fTemp260 = (fConst24 * fRec528[1]);
			double fTemp261 = (fConst25 * fRec531[1]);
			fRec533[0] = (fTemp259 + (fTemp260 + (fRec533[1] + fTemp261)));
			fRec531[0] = fRec533[0];
			double fRec532 = ((fTemp261 + fTemp260) + fTemp259);
			fRec530[0] = (fRec530[1] + fRec531[0]);
			fRec528[0] = fRec530[0];
			double fRec529 = fRec532;
			double fTemp262 = (fConst21 * fRec525[1]);
			fRec527[0] = (fRec529 + (fRec527[1] + fTemp262));
			fRec525[0] = fRec527[0];
			double fRec526 = (fTemp262 + fRec529);
			fVec10[(IOTA & 1023)] = ((0.036760854199999998 * fTemp62) + (fRec490 + (fRec505 + ((fRec517 + fRec520) + fRec526))));
			output10[i] = FAUSTFLOAT((0.8267575322812053 * (fRec83[0] * fVec10[((IOTA - iConst33) & 1023)])));
			double fTemp263 = (fConst12 * fRec534[1]);
			double fTemp264 = (fConst11 * fRec537[1]);
			double fTemp265 = (fConst10 * fRec540[1]);
			double fTemp266 = (fConst5 * (((0.041027857899999999 * fTemp10) + ((0.023563855599999999 * fTemp7) + ((0.013562060799999999 * fTemp12) + (0.20137291539999999 * fTemp14)))) - ((0.032815340599999999 * fTemp17) + ((0.049821568900000002 * fTemp11) + ((0.034862594300000001 * fTemp16) + ((0.067800431499999994 * fTemp9) + ((0.1052764387 * fTemp15) + ((0.037107540100000003 * fTemp8) + (0.066581064699999998 * fTemp13)))))))));
			double fTemp267 = (fConst9 * fRec543[1]);
			double fTemp268 = (fConst7 * fRec546[1]);
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
			double fTemp269 = (fConst14 * fRec549[1]);
			double fTemp270 = (fConst15 * fRec552[1]);
			double fTemp271 = (fConst17 * ((((0.0202585653 * fTemp31) + (((0.0038118874000000001 * fTemp27) + (0.1181578632 * fTemp29)) + (0.072148191900000005 * fTemp28))) + (0.030405642100000001 * fTemp33)) - ((((0.052587393400000002 * fTemp26) + (0.0064780044999999996 * fTemp30)) + (0.023971681200000001 * fTemp32)) + (0.089461457899999999 * fTemp34))));
			double fTemp272 = (fConst18 * fRec555[1]);
			double fTemp273 = (fConst19 * fRec558[1]);
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
			double fTemp274 = (fConst21 * fRec561[1]);
			double fTemp275 = (fConst23 * (((0.026683141 * fTemp45) + ((0.0110567598 * fTemp41) + ((((0.12204248719999999 * fTemp39) + (0.0247514907 * fTemp42)) + (0.0123911925 * fTemp40)) + (0.069869992500000005 * fTemp44)))) - (0.044065707199999998 * fTemp43)));
			double fTemp276 = (fConst24 * fRec564[1]);
			double fTemp277 = (fConst25 * fRec567[1]);
			fRec569[0] = (fTemp275 + (fTemp276 + (fRec569[1] + fTemp277)));
			fRec567[0] = fRec569[0];
			double fRec568 = ((fTemp277 + fTemp276) + fTemp275);
			fRec566[0] = (fRec567[0] + fRec566[1]);
			fRec564[0] = fRec566[0];
			double fRec565 = fRec568;
			fRec563[0] = (fTemp274 + (fRec565 + fRec563[1]));
			fRec561[0] = fRec563[0];
			double fRec562 = (fRec565 + fTemp274);
			double fTemp278 = (fConst27 * ((0.037992065399999997 * fTemp49) - ((0.0061970760999999997 * fTemp51) + (0.052047968799999997 * fTemp50))));
			double fTemp279 = (fConst28 * fRec570[1]);
			fRec572[0] = (fTemp278 + (fRec572[1] + fTemp279));
			fRec570[0] = fRec572[0];
			double fRec571 = (fTemp279 + fTemp278);
			double fTemp280 = (fConst30 * (((0.0045390105999999998 * fTemp55) + (0.023295129099999999 * fTemp57)) - (((0.1380219234 * fTemp54) + (0.074891309000000003 * fTemp58)) + (0.0027228533 * fTemp56))));
			double fTemp281 = (fConst31 * fRec573[1]);
			double fTemp282 = (fConst32 * fRec576[1]);
			fRec578[0] = (fTemp280 + (fTemp281 + (fRec578[1] + fTemp282)));
			fRec576[0] = fRec578[0];
			double fRec577 = ((fTemp282 + fTemp281) + fTemp280);
			fRec575[0] = (fRec576[0] + fRec575[1]);
			fRec573[0] = fRec575[0];
			double fRec574 = fRec577;
			fVec11[(IOTA & 1023)] = ((0.031521938700000002 * fTemp62) + (fRec535 + (fRec550 + (fRec562 + (fRec571 + fRec574)))));
			output11[i] = FAUSTFLOAT((0.8267575322812053 * (fRec83[0] * fVec11[((IOTA - iConst33) & 1023)])));
			double fTemp283 = (fConst12 * fRec579[1]);
			double fTemp284 = (fConst11 * fRec582[1]);
			double fTemp285 = (fConst10 * fRec585[1]);
			double fTemp286 = (fConst5 * (((((0.036701127700000002 * fTemp8) + (0.024123129600000001 * fTemp15)) + (0.051729212099999998 * fTemp10)) + (0.037096526800000001 * fTemp17)) - ((0.041699573400000002 * fTemp11) + ((0.0334795227 * fTemp16) + ((0.079593004600000003 * fTemp9) + ((0.1885736533 * fTemp7) + ((0.034515979000000002 * fTemp14) + ((0.1156622571 * fTemp12) + (0.066203739499999997 * fTemp13)))))))));
			double fTemp287 = (fConst9 * fRec588[1]);
			double fTemp288 = (fConst7 * fRec591[1]);
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
			double fTemp291 = (fConst17 * (((0.036123277000000002 * fTemp32) + ((0.0046682542000000002 * fTemp31) + ((((0.052011441300000003 * fTemp26) + (0.0369830014 * fTemp27)) + (0.12835427399999999 * fTemp29)) + (0.0691564915 * fTemp28)))) - ((0.089109834900000004 * fTemp34) + ((0.0198132879 * fTemp30) + (0.0059444779 * fTemp33)))));
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
			double fTemp295 = (fConst23 * ((((((0.024164325300000001 * fTemp39) + (0.035593872999999998 * fTemp42)) + (0.011607717700000001 * fTemp40)) + (0.042590732300000003 * fTemp44)) + (0.1199763705 * fTemp45)) - ((0.072480144799999993 * fTemp43) + (0.00067164060000000003 * fTemp41))));
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
			double fTemp298 = (fConst27 * ((0.050842183200000002 * fTemp49) - ((0.0057692511999999996 * fTemp51) + (0.037089783600000002 * fTemp50))));
			double fTemp299 = (fConst28 * fRec615[1]);
			fRec617[0] = (fTemp298 + (fRec617[1] + fTemp299));
			fRec615[0] = fRec617[0];
			double fRec616 = (fTemp299 + fTemp298);
			double fTemp300 = (fConst30 * (0.0 - (((((0.14149563239999999 * fTemp54) + (0.00029298449999999999 * fTemp55)) + (0.072065268200000004 * fTemp58)) + (0.0042767087000000004 * fTemp56)) + (0.020451459599999999 * fTemp57))));
			double fTemp301 = (fConst31 * fRec618[1]);
			double fTemp302 = (fConst32 * fRec621[1]);
			fRec623[0] = (fTemp300 + (fTemp301 + (fRec623[1] + fTemp302)));
			fRec621[0] = fRec623[0];
			double fRec622 = ((fTemp302 + fTemp301) + fTemp300);
			fRec620[0] = (fRec621[0] + fRec620[1]);
			fRec618[0] = fRec620[0];
			double fRec619 = fRec622;
			fVec12[(IOTA & 1023)] = ((0.030431291400000001 * fTemp62) + (fRec580 + (fRec595 + (fRec607 + (fRec616 + fRec619)))));
			output12[i] = FAUSTFLOAT((0.8267575322812053 * (fRec83[0] * fVec12[((IOTA - iConst33) & 1023)])));
			double fTemp303 = (fConst12 * fRec624[1]);
			double fTemp304 = (fConst11 * fRec627[1]);
			double fTemp305 = (fConst10 * fRec630[1]);
			double fTemp306 = (fConst5 * (((0.0825056386 * fTemp17) + ((0.061202251399999998 * fTemp10) + ((0.054242456699999997 * fTemp15) + ((0.042597415499999999 * fTemp8) + ((0.10149720180000001 * fTemp7) + (0.055691889500000001 * fTemp13)))))) - ((0.022575107099999998 * fTemp11) + ((0.049756525199999999 * fTemp16) + ((0.031942525399999998 * fTemp9) + ((0.097449777200000004 * fTemp12) + (0.1760101989 * fTemp14)))))));
			double fTemp307 = (fConst9 * fRec633[1]);
			double fTemp308 = (fConst7 * fRec636[1]);
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
			double fTemp309 = (fConst14 * fRec639[1]);
			double fTemp310 = (fConst15 * fRec642[1]);
			double fTemp311 = (fConst17 * ((((((0.060367435900000002 * fTemp26) + (0.055040693000000002 * fTemp29)) + (0.077739710500000003 * fTemp28)) + (0.070209961299999998 * fTemp32)) + (0.084114352399999995 * fTemp34)) - ((((0.028579108400000001 * fTemp27) + (0.0206470344 * fTemp30)) + (0.0027835558999999999 * fTemp31)) + (0.023189359999999999 * fTemp33))));
			double fTemp312 = (fConst18 * fRec645[1]);
			double fTemp313 = (fConst19 * fRec648[1]);
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
			double fTemp314 = (fConst21 * fRec651[1]);
			double fTemp315 = (fConst23 * (((((0.012056599600000001 * fTemp42) + (0.019527567700000002 * fTemp40)) + (0.016861300900000001 * fTemp44)) + (0.076097885099999998 * fTemp45)) - (((0.10020605959999999 * fTemp39) + (0.081617254200000003 * fTemp43)) + (0.0147721832 * fTemp41))));
			double fTemp316 = (fConst24 * fRec654[1]);
			double fTemp317 = (fConst25 * fRec657[1]);
			fRec659[0] = (fTemp315 + (fTemp316 + (fRec659[1] + fTemp317)));
			fRec657[0] = fRec659[0];
			double fRec658 = ((fTemp317 + fTemp316) + fTemp315);
			fRec656[0] = (fRec657[0] + fRec656[1]);
			fRec654[0] = fRec656[0];
			double fRec655 = fRec658;
			fRec653[0] = (fTemp314 + (fRec655 + fRec653[1]));
			fRec651[0] = fRec653[0];
			double fRec652 = (fRec655 + fTemp314);
			double fTemp318 = (fConst27 * ((0.0620770987 * fTemp49) - ((0.0049212615999999999 * fTemp51) + (0.016704297600000001 * fTemp50))));
			double fTemp319 = (fConst28 * fRec660[1]);
			fRec662[0] = (fTemp318 + (fRec662[1] + fTemp319));
			fRec660[0] = fRec662[0];
			double fRec661 = (fTemp319 + fTemp318);
			double fTemp320 = (fConst30 * ((0.0032390552999999999 * fTemp55) - ((((0.063783370699999994 * fTemp54) + (0.078373328800000003 * fTemp58)) + (0.0021462826 * fTemp56)) + (0.052090091599999999 * fTemp57))));
			double fTemp321 = (fConst31 * fRec663[1]);
			double fTemp322 = (fConst32 * fRec666[1]);
			fRec668[0] = (fTemp320 + (fTemp321 + (fRec668[1] + fTemp322)));
			fRec666[0] = fRec668[0];
			double fRec667 = ((fTemp322 + fTemp321) + fTemp320);
			fRec665[0] = (fRec666[0] + fRec665[1]);
			fRec663[0] = fRec665[0];
			double fRec664 = fRec667;
			fVec13[(IOTA & 1023)] = ((0.035670528600000001 * fTemp62) + (fRec625 + (fRec640 + (fRec652 + (fRec661 + fRec664)))));
			output13[i] = FAUSTFLOAT((0.8267575322812053 * (fRec83[0] * fVec13[((IOTA - iConst33) & 1023)])));
			double fTemp323 = (fConst12 * fRec669[1]);
			double fTemp324 = (fConst11 * fRec672[1]);
			double fTemp325 = (fConst10 * fRec675[1]);
			double fTemp326 = (fConst5 * (((0.088421999500000001 * fTemp17) + ((0.020143512999999998 * fTemp11) + ((0.062899474900000002 * fTemp10) + ((0.0340650282 * fTemp9) + ((0.061012234999999998 * fTemp15) + ((0.1288904619 * fTemp7) + ((0.15647763149999999 * fTemp14) + ((0.096500336300000003 * fTemp12) + (0.068209236199999995 * fTemp13))))))))) - ((0.0346112357 * fTemp8) + (0.052528503499999997 * fTemp16))));
			double fTemp327 = (fConst9 * fRec678[1]);
			double fTemp328 = (fConst7 * fRec681[1]);
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
			double fTemp329 = (fConst14 * fRec684[1]);
			double fTemp330 = (fConst15 * fRec687[1]);
			double fTemp331 = (fConst17 * (((0.1020428265 * fTemp34) + ((0.031465581499999999 * fTemp33) + ((0.081428922700000003 * fTemp32) + ((0.080962306900000003 * fTemp28) + (0.0038951124000000002 * fTemp31))))) - ((((0.0490497259 * fTemp26) + (0.029311830899999999 * fTemp27)) + (0.052933911200000003 * fTemp29)) + (0.021985468800000001 * fTemp30))));
			double fTemp332 = (fConst18 * fRec690[1]);
			double fTemp333 = (fConst19 * fRec693[1]);
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
			double fTemp334 = (fConst21 * fRec696[1]);
			double fTemp335 = (fConst23 * ((0.021065771699999999 * fTemp40) - ((0.063459594699999997 * fTemp45) + (((((0.10869436690000001 * fTemp39) + (0.016496783399999999 * fTemp42)) + (0.084663697600000004 * fTemp43)) + (0.013095174899999999 * fTemp44)) + (0.0077259627999999997 * fTemp41)))));
			double fTemp336 = (fConst24 * fRec699[1]);
			double fTemp337 = (fConst25 * fRec702[1]);
			fRec704[0] = (fTemp335 + (fTemp336 + (fRec704[1] + fTemp337)));
			fRec702[0] = fRec704[0];
			double fRec703 = ((fTemp337 + fTemp336) + fTemp335);
			fRec701[0] = (fRec702[0] + fRec701[1]);
			fRec699[0] = fRec701[0];
			double fRec700 = fRec703;
			fRec698[0] = (fTemp334 + (fRec700 + fRec698[1]));
			fRec696[0] = fRec698[0];
			double fRec697 = (fRec700 + fTemp334);
			double fTemp338 = (fConst27 * (((0.064786896799999993 * fTemp49) + (0.0143146309 * fTemp50)) - (0.0052391981000000001 * fTemp51)));
			double fTemp339 = (fConst28 * fRec705[1]);
			fRec707[0] = (fTemp338 + (fRec707[1] + fTemp339));
			fRec705[0] = fRec707[0];
			double fRec706 = (fTemp339 + fTemp338);
			double fTemp340 = (fConst30 * ((((0.0565920522 * fTemp54) + (0.0038443382000000002 * fTemp55)) + (0.0023727754999999999 * fTemp56)) - ((0.081137620899999999 * fTemp58) + (0.051793877000000002 * fTemp57))));
			double fTemp341 = (fConst31 * fRec708[1]);
			double fTemp342 = (fConst32 * fRec711[1]);
			fRec713[0] = (fTemp340 + (fTemp341 + (fRec713[1] + fTemp342)));
			fRec711[0] = fRec713[0];
			double fRec712 = ((fTemp342 + fTemp341) + fTemp340);
			fRec710[0] = (fRec711[0] + fRec710[1]);
			fRec708[0] = fRec710[0];
			double fRec709 = fRec712;
			fVec14[(IOTA & 1023)] = ((0.036983426299999997 * fTemp62) + (fRec670 + (fRec685 + (fRec697 + (fRec706 + fRec709)))));
			output14[i] = FAUSTFLOAT((0.8267575322812053 * (fRec83[0] * fVec14[((IOTA - iConst33) & 1023)])));
			double fTemp343 = (fConst12 * fRec714[1]);
			double fTemp344 = (fConst11 * fRec717[1]);
			double fTemp345 = (fConst10 * fRec720[1]);
			double fTemp346 = (fConst5 * (((0.044655254300000002 * fTemp17) + ((0.042819441799999997 * fTemp11) + ((0.054617348199999999 * fTemp10) + ((0.066594522599999997 * fTemp9) + ((0.043276939 * fTemp15) + ((0.1167575064 * fTemp12) + (0.057989522299999999 * fTemp14))))))) - ((0.035427453499999997 * fTemp16) + ((0.045773642000000003 * fTemp8) + ((0.19671080390000001 * fTemp7) + (0.060858719399999997 * fTemp13))))));
			double fTemp347 = (fConst9 * fRec723[1]);
			double fTemp348 = (fConst7 * fRec726[1]);
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
			double fTemp349 = (fConst14 * fRec729[1]);
			double fTemp350 = (fConst15 * fRec732[1]);
			double fTemp351 = (fConst17 * (((0.00048017969999999998 * fTemp33) + (((0.045076107999999997 * fTemp27) + (0.072574273300000006 * fTemp28)) + (0.044312087 * fTemp32))) - (((((0.064868663199999996 * fTemp26) + (0.117289216 * fTemp29)) + (0.022406232599999999 * fTemp30)) + (0.0048340136999999997 * fTemp31)) + (0.081330087600000003 * fTemp34))));
			double fTemp352 = (fConst18 * fRec735[1]);
			double fTemp353 = (fConst19 * fRec738[1]);
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
			double fTemp354 = (fConst21 * fRec741[1]);
			double fTemp355 = (fConst23 * ((((0.0141643972 * fTemp39) + (0.0124138727 * fTemp40)) + (0.00027724359999999998 * fTemp41)) - ((((0.023532872699999999 * fTemp42) + (0.078688231999999997 * fTemp43)) + (0.044147789 * fTemp44)) + (0.12886762700000001 * fTemp45))));
			double fTemp356 = (fConst24 * fRec744[1]);
			double fTemp357 = (fConst25 * fRec747[1]);
			fRec749[0] = (fTemp355 + (fTemp356 + (fRec749[1] + fTemp357)));
			fRec747[0] = fRec749[0];
			double fRec748 = ((fTemp357 + fTemp356) + fTemp355);
			fRec746[0] = (fRec747[0] + fRec746[1]);
			fRec744[0] = fRec746[0];
			double fRec745 = fRec748;
			fRec743[0] = (fTemp354 + (fRec745 + fRec743[1]));
			fRec741[0] = fRec743[0];
			double fRec742 = (fRec745 + fTemp354);
			double fTemp358 = (fConst27 * (((0.054211412200000003 * fTemp49) + (0.037590833400000002 * fTemp50)) - (0.0059673703000000002 * fTemp51)));
			double fTemp359 = (fConst28 * fRec750[1]);
			fRec752[0] = (fTemp358 + (fRec752[1] + fTemp359));
			fRec750[0] = fRec752[0];
			double fRec751 = (fTemp359 + fTemp358);
			double fTemp360 = (fConst30 * (((0.1380118001 * fTemp54) + (0.0036671247000000001 * fTemp56)) - (((0.00095578199999999996 * fTemp55) + (0.075451245099999995 * fTemp58)) + (0.0240785918 * fTemp57))));
			double fTemp361 = (fConst31 * fRec753[1]);
			double fTemp362 = (fConst32 * fRec756[1]);
			fRec758[0] = (fTemp360 + (fTemp361 + (fRec758[1] + fTemp362)));
			fRec756[0] = fRec758[0];
			double fRec757 = ((fTemp362 + fTemp361) + fTemp360);
			fRec755[0] = (fRec756[0] + fRec755[1]);
			fRec753[0] = fRec755[0];
			double fRec754 = fRec757;
			fVec15[(IOTA & 1023)] = ((0.031971349500000003 * fTemp62) + (fRec715 + (fRec730 + (fRec742 + (fRec751 + fRec754)))));
			output15[i] = FAUSTFLOAT((0.8267575322812053 * (fRec83[0] * fVec15[((IOTA - iConst33) & 1023)])));
			double fTemp363 = (fConst35 * fRec759[1]);
			double fTemp364 = (fConst37 * fRec762[1]);
			double fTemp365 = (fConst38 * fRec765[1]);
			double fTemp366 = (fConst40 * (((0.054658263700000001 * fTemp17) + ((0.16630141239999999 * fTemp16) + ((0.23763654140000001 * fTemp15) + ((0.038777275999999999 * fTemp8) + ((0.0020084518999999999 * fTemp14) + ((0.094679016800000002 * fTemp12) + (0.0072687218 * fTemp13))))))) - ((((0.0074988067999999996 * fTemp7) + (0.2287650011 * fTemp9)) + (0.081105981699999996 * fTemp10)) + (0.13582360969999999 * fTemp11))));
			double fTemp367 = (fConst41 * fRec768[1]);
			double fTemp368 = (fConst42 * fRec771[1]);
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
			double fTemp369 = (fConst44 * fRec774[1]);
			double fTemp370 = (fConst45 * fRec777[1]);
			double fTemp371 = (fConst47 * (((0.070124764699999995 * fTemp33) + ((((0.054953679599999999 * fTemp26) + (0.1760975451 * fTemp27)) + (0.22865629409999999 * fTemp29)) + (0.14774861110000001 * fTemp32))) - ((((0.042734234699999998 * fTemp30) + (0.18570811549999999 * fTemp28)) + (0.041200020499999997 * fTemp31)) + (0.0027572720999999999 * fTemp34))));
			double fTemp372 = (fConst48 * fRec780[1]);
			double fTemp373 = (fConst49 * fRec783[1]);
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
			double fTemp374 = (fConst51 * fRec786[1]);
			double fTemp375 = (fConst53 * (((0.1228995207 * fTemp41) + (((0.19085225089999999 * fTemp42) + (0.038977067800000001 * fTemp43)) + (0.12764914560000001 * fTemp44))) - (((0.017724420300000002 * fTemp39) + (0.14306343969999999 * fTemp40)) + (0.0076537302000000002 * fTemp45))));
			double fTemp376 = (fConst54 * fRec789[1]);
			double fTemp377 = (fConst55 * fRec792[1]);
			fRec794[0] = (fTemp375 + (fTemp376 + (fRec794[1] + fTemp377)));
			fRec792[0] = fRec794[0];
			double fRec793 = ((fTemp377 + fTemp376) + fTemp375);
			fRec791[0] = (fRec792[0] + fRec791[1]);
			fRec789[0] = fRec791[0];
			double fRec790 = fRec793;
			fRec788[0] = (fTemp374 + (fRec790 + fRec788[1]));
			fRec786[0] = fRec788[0];
			double fRec787 = (fRec790 + fTemp374);
			double fTemp378 = (fConst57 * (((0.069867188100000005 * fTemp51) + (0.018208263200000002 * fTemp50)) - (0.0023901119999999998 * fTemp49)));
			double fTemp379 = (fConst58 * fRec795[1]);
			fRec797[0] = (fTemp378 + (fRec797[1] + fTemp379));
			fRec795[0] = fRec797[0];
			double fRec796 = (fTemp379 + fTemp378);
			double fTemp380 = (fConst60 * (((((0.036665115800000002 * fTemp55) + (0.1194106702 * fTemp58)) + (0.1163672514 * fTemp56)) + (0.031486665300000001 * fTemp57)) - (0.12856946850000001 * fTemp54)));
			double fTemp381 = (fConst61 * fRec798[1]);
			double fTemp382 = (fConst62 * fRec801[1]);
			fRec803[0] = (fTemp380 + (fTemp381 + (fRec803[1] + fTemp382)));
			fRec801[0] = fRec803[0];
			double fRec802 = ((fTemp382 + fTemp381) + fTemp380);
			fRec800[0] = (fRec801[0] + fRec800[1]);
			fRec798[0] = fRec800[0];
			double fRec799 = fRec802;
			fVec16[(IOTA & 511)] = ((fRec760 + (fRec775 + (fRec787 + (fRec796 + fRec799)))) - (0.026605464700000001 * fTemp62));
			output16[i] = FAUSTFLOAT((0.87553802008608317 * (fRec83[0] * fVec16[((IOTA - iConst63) & 511)])));
			double fTemp383 = (fConst35 * fRec804[1]);
			double fTemp384 = (fConst37 * fRec807[1]);
			double fTemp385 = (fConst38 * fRec810[1]);
			double fTemp386 = (fConst40 * (((0.053723331700000002 * fTemp17) + ((0.16512002379999999 * fTemp16) + ((0.082804776299999994 * fTemp10) + ((0.23413192590000001 * fTemp9) + ((0.0074707163000000002 * fTemp7) + ((0.082108471000000002 * fTemp12) + (0.005192772 * fTemp13))))))) - ((0.1383744287 * fTemp11) + ((0.23931953149999999 * fTemp15) + ((0.038632016900000003 * fTemp8) + (0.0020009283 * fTemp14))))));
			double fTemp387 = (fConst41 * fRec813[1]);
			double fTemp388 = (fConst42 * fRec816[1]);
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
			double fTemp389 = (fConst44 * fRec819[1]);
			double fTemp390 = (fConst45 * fRec822[1]);
			double fTemp391 = (fConst47 * (((0.061490590300000002 * fTemp33) + ((0.043424484499999999 * fTemp30) + (0.14493551939999999 * fTemp32))) - ((((((0.054747823899999999 * fTemp26) + (0.17734382000000001 * fTemp27)) + (0.23401375290000001 * fTemp29)) + (0.1845810199 * fTemp28)) + (0.042411346099999997 * fTemp31)) + (0.0055875209000000002 * fTemp34))));
			double fTemp392 = (fConst48 * fRec825[1]);
			double fTemp393 = (fConst49 * fRec828[1]);
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
			double fTemp394 = (fConst51 * fRec831[1]);
			double fTemp395 = (fConst53 * (((0.1204226736 * fTemp41) + ((0.017847359899999998 * fTemp39) + (0.12856705869999999 * fTemp44))) - ((((0.19533409230000001 * fTemp42) + (0.040211809199999997 * fTemp43)) + (0.14282278279999999 * fTemp40)) + (0.0057529597999999996 * fTemp45))));
			double fTemp396 = (fConst54 * fRec834[1]);
			double fTemp397 = (fConst55 * fRec837[1]);
			fRec839[0] = (fTemp395 + (fTemp396 + (fRec839[1] + fTemp397)));
			fRec837[0] = fRec839[0];
			double fRec838 = ((fTemp397 + fTemp396) + fTemp395);
			fRec836[0] = (fRec837[0] + fRec836[1]);
			fRec834[0] = fRec836[0];
			double fRec835 = fRec838;
			fRec833[0] = (fTemp394 + (fRec835 + fRec833[1]));
			fRec831[0] = fRec833[0];
			double fRec832 = (fRec835 + fTemp394);
			double fTemp398 = (fConst57 * (((0.0022940093000000002 * fTemp49) + (0.069916242099999998 * fTemp51)) + (0.017207201799999999 * fTemp50)));
			double fTemp399 = (fConst58 * fRec840[1]);
			fRec842[0] = (fTemp398 + (fRec842[1] + fTemp399));
			fRec840[0] = fRec842[0];
			double fRec841 = (fTemp399 + fTemp398);
			double fTemp400 = (fConst60 * (((((0.1315720501 * fTemp54) + (0.1180553795 * fTemp58)) + (0.11645398 * fTemp56)) + (0.0307617434 * fTemp57)) - (0.0377988914 * fTemp55)));
			double fTemp401 = (fConst61 * fRec843[1]);
			double fTemp402 = (fConst62 * fRec846[1]);
			fRec848[0] = (fTemp400 + (fTemp401 + (fRec848[1] + fTemp402)));
			fRec846[0] = fRec848[0];
			double fRec847 = ((fTemp402 + fTemp401) + fTemp400);
			fRec845[0] = (fRec846[0] + fRec845[1]);
			fRec843[0] = fRec845[0];
			double fRec844 = fRec847;
			fVec17[(IOTA & 511)] = ((fRec805 + (fRec820 + (fRec832 + (fRec841 + fRec844)))) - (0.025889335900000001 * fTemp62));
			output17[i] = FAUSTFLOAT((0.87553802008608317 * (fRec83[0] * fVec17[((IOTA - iConst63) & 511)])));
			double fTemp403 = (fConst35 * fRec849[1]);
			double fTemp404 = (fConst37 * fRec852[1]);
			double fTemp405 = (fConst38 * fRec855[1]);
			double fTemp406 = (fConst40 * (((0.17249767220000001 * fTemp16) + ((0.1415650993 * fTemp10) + ((0.207801134 * fTemp9) + ((0.1136483973 * fTemp15) + ((0.038964576100000002 * fTemp8) + ((0.0075065464000000004 * fTemp13) + (0.0020181531 * fTemp14))))))) - ((0.058755958800000001 * fTemp17) + ((0.076663301899999994 * fTemp11) + ((0.0075350271000000002 * fTemp7) + (0.2110113686 * fTemp12))))));
			double fTemp407 = (fConst41 * fRec858[1]);
			double fTemp408 = (fConst42 * fRec861[1]);
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
			double fTemp409 = (fConst44 * fRec864[1]);
			double fTemp410 = (fConst45 * fRec867[1]);
			double fTemp411 = (fConst47 * ((((0.055219114100000001 * fTemp26) + (0.084465526499999999 * fTemp27)) + (0.041758727599999997 * fTemp30)) - ((0.0029064667000000001 * fTemp34) + ((0.15678414930000001 * fTemp33) + ((0.15852484820000001 * fTemp32) + (((0.20721606949999999 * fTemp29) + (0.19263058650000001 * fTemp28)) + (0.039755600100000003 * fTemp31)))))));
			double fTemp412 = (fConst48 * fRec870[1]);
			double fTemp413 = (fConst49 * fRec873[1]);
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
			double fTemp414 = (fConst51 * fRec876[1]);
			double fTemp415 = (fConst53 * (((0.038405105000000002 * fTemp44) + (0.015122981299999999 * fTemp45)) - (((((0.0087235781000000005 * fTemp39) + (0.17366971019999999 * fTemp42)) + (0.13512849460000001 * fTemp43)) + (0.14840651639999999 * fTemp40)) + (0.13171952119999999 * fTemp41))));
			double fTemp416 = (fConst54 * fRec879[1]);
			double fTemp417 = (fConst55 * fRec882[1]);
			fRec884[0] = (fTemp415 + (fTemp416 + (fRec884[1] + fTemp417)));
			fRec882[0] = fRec884[0];
			double fRec883 = ((fTemp417 + fTemp416) + fTemp415);
			fRec881[0] = (fRec882[0] + fRec881[1]);
			fRec879[0] = fRec881[0];
			double fRec880 = fRec883;
			fRec878[0] = (fTemp414 + (fRec880 + fRec878[1]));
			fRec876[0] = fRec878[0];
			double fRec877 = (fRec880 + fTemp414);
			double fTemp418 = (fConst57 * ((0.072479275999999995 * fTemp51) - ((0.019275259900000001 * fTemp49) + (0.0013046266999999999 * fTemp50))));
			double fTemp419 = (fConst58 * fRec885[1]);
			fRec887[0] = (fTemp418 + (fRec887[1] + fTemp419));
			fRec885[0] = fRec887[0];
			double fRec886 = (fTemp419 + fTemp418);
			double fTemp420 = (fConst60 * ((((0.1158231341 * fTemp54) + (0.1238515521 * fTemp58)) + (0.036413946599999997 * fTemp56)) - ((0.1226813179 * fTemp55) + (0.033651382899999999 * fTemp57))));
			double fTemp421 = (fConst61 * fRec888[1]);
			double fTemp422 = (fConst62 * fRec891[1]);
			fRec893[0] = (fTemp420 + (fTemp421 + (fRec893[1] + fTemp422)));
			fRec891[0] = fRec893[0];
			double fRec892 = ((fTemp422 + fTemp421) + fTemp420);
			fRec890[0] = (fRec891[0] + fRec890[1]);
			fRec888[0] = fRec890[0];
			double fRec889 = fRec892;
			fVec18[(IOTA & 511)] = ((fRec850 + (fRec865 + (fRec877 + (fRec886 + fRec889)))) - (0.0275881696 * fTemp62));
			output18[i] = FAUSTFLOAT((0.87553802008608317 * (fRec83[0] * fVec18[((IOTA - iConst63) & 511)])));
			double fTemp423 = (fConst35 * fRec894[1]);
			double fTemp424 = (fConst37 * fRec897[1]);
			double fTemp425 = (fConst38 * fRec900[1]);
			double fTemp426 = (fConst40 * (((0.087688514999999995 * fTemp11) + ((0.16441631540000001 * fTemp16) + ((0.13482338739999999 * fTemp10) + ((0.075608722599999997 * fTemp15) + ((0.0082911901 * fTemp7) + ((0.22857838550000001 * fTemp12) + (0.0050549725000000002 * fTemp13))))))) - ((0.049406031699999998 * fTemp17) + ((0.2356046983 * fTemp9) + ((0.042874790099999997 * fTemp8) + (0.0022206808999999999 * fTemp14))))));
			double fTemp427 = (fConst41 * fRec903[1]);
			double fTemp428 = (fConst42 * fRec906[1]);
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
			double fTemp429 = (fConst44 * fRec909[1]);
			double fTemp430 = (fConst45 * fRec912[1]);
			double fTemp431 = (fConst47 * ((((((0.056415530399999997 * fTemp27) + (0.23494989560000001 * fTemp29)) + (0.041835980799999999 * fTemp30)) + (0.044670576900000002 * fTemp31)) + (0.16983502689999999 * fTemp33)) - ((((0.060760520599999999 * fTemp26) + (0.18380535240000001 * fTemp28)) + (0.13358026410000001 * fTemp32)) + (0.0057265472000000003 * fTemp34))));
			double fTemp432 = (fConst48 * fRec915[1]);
			double fTemp433 = (fConst49 * fRec918[1]);
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
			double fTemp434 = (fConst53 * ((0.19690113400000001 * fTemp42) - ((0.016369178599999999 * fTemp45) + (((((0.0055962611000000004 * fTemp39) + (0.1245381146 * fTemp43)) + (0.1422584214 * fTemp40)) + (0.0455578892 * fTemp44)) + (0.1111280296 * fTemp41)))));
			double fTemp435 = (fConst55 * fRec927[1]);
			double fTemp436 = (fConst54 * fRec924[1]);
			fRec929[0] = (((fTemp434 + fRec929[1]) + fTemp435) + fTemp436);
			fRec927[0] = fRec929[0];
			double fRec928 = ((fTemp434 + fTemp435) + fTemp436);
			fRec926[0] = (fRec927[0] + fRec926[1]);
			fRec924[0] = fRec926[0];
			double fRec925 = fRec928;
			double fTemp437 = (fConst51 * fRec921[1]);
			fRec923[0] = ((fRec925 + fRec923[1]) + fTemp437);
			fRec921[0] = fRec923[0];
			double fRec922 = (fRec925 + fTemp437);
			double fTemp438 = (fConst57 * (((0.069649436300000006 * fTemp51) + (0.00094041329999999996 * fTemp50)) - (0.016912689299999999 * fTemp49)));
			double fTemp439 = (fConst58 * fRec930[1]);
			fRec932[0] = (fTemp438 + (fRec932[1] + fTemp439));
			fRec930[0] = fRec932[0];
			double fRec931 = (fTemp439 + fTemp438);
			double fTemp440 = (fConst60 * ((0.1175232808 * fTemp58) - ((((0.1313370821 * fTemp54) + (0.1132278979 * fTemp55)) + (0.043059468599999998 * fTemp56)) + (0.028480038999999999 * fTemp57))));
			double fTemp441 = (fConst61 * fRec933[1]);
			double fTemp442 = (fConst62 * fRec936[1]);
			fRec938[0] = (fTemp440 + (fTemp441 + (fRec938[1] + fTemp442)));
			fRec936[0] = fRec938[0];
			double fRec937 = ((fTemp442 + fTemp441) + fTemp440);
			fRec935[0] = (fRec936[0] + fRec935[1]);
			fRec933[0] = fRec935[0];
			double fRec934 = fRec937;
			fVec19[(IOTA & 511)] = ((fRec895 + (fRec910 + (fRec922 + (fRec931 + fRec934)))) - (0.025748880799999999 * fTemp62));
			output19[i] = FAUSTFLOAT((0.87553802008608317 * (fRec83[0] * fVec19[((IOTA - iConst63) & 511)])));
			double fTemp443 = (fConst35 * fRec939[1]);
			double fTemp444 = (fConst37 * fRec942[1]);
			double fTemp445 = (fConst38 * fRec945[1]);
			double fTemp446 = (fConst40 * (((0.053788580099999997 * fTemp17) + ((0.1272838959 * fTemp11) + ((0.1546635468 * fTemp16) + ((0.072929094299999997 * fTemp10) + ((0.047464846999999998 * fTemp8) + ((0.0070592683999999998 * fTemp13) + (0.0024584208000000001 * fTemp14))))))) - ((0.20184101099999999 * fTemp9) + ((0.22807476169999999 * fTemp15) + ((0.0091788219999999997 * fTemp7) + (0.10265007380000001 * fTemp12))))));
			double fTemp447 = (fConst41 * fRec948[1]);
			double fTemp448 = (fConst42 * fRec951[1]);
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
			double fTemp449 = (fConst44 * fRec954[1]);
			double fTemp450 = (fConst45 * fRec957[1]);
			double fTemp451 = (fConst47 * (((0.1454323954 * fTemp32) + ((((0.067265374500000003 * fTemp26) + (0.20183196340000001 * fTemp29)) + (0.039275270899999999 * fTemp30)) + (0.037260847200000002 * fTemp31))) - ((0.0021430796000000002 * fTemp34) + (((0.16921135130000001 * fTemp27) + (0.1726837551 * fTemp28)) + (0.076792178500000002 * fTemp33)))));
			double fTemp452 = (fConst48 * fRec960[1]);
			double fTemp453 = (fConst49 * fRec963[1]);
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
			double fTemp454 = (fConst51 * fRec966[1]);
			double fTemp455 = (fConst53 * (((0.0071585844000000001 * fTemp45) + (((0.016712468300000002 * fTemp39) + (0.16833547709999999 * fTemp42)) + (0.120989452 * fTemp41))) - (((0.033233919299999998 * fTemp43) + (0.13293713060000001 * fTemp40)) + (0.1217577269 * fTemp44))));
			double fTemp456 = (fConst54 * fRec969[1]);
			double fTemp457 = (fConst55 * fRec972[1]);
			fRec974[0] = (fTemp455 + (fTemp456 + (fRec974[1] + fTemp457)));
			fRec972[0] = fRec974[0];
			double fRec973 = ((fTemp457 + fTemp456) + fTemp455);
			fRec971[0] = (fRec972[0] + fRec971[1]);
			fRec969[0] = fRec971[0];
			double fRec970 = fRec973;
			fRec968[0] = (fTemp454 + (fRec970 + fRec968[1]));
			fRec966[0] = fRec968[0];
			double fRec967 = (fRec970 + fTemp454);
			double fTemp458 = (fConst57 * (((0.0027915142999999998 * fTemp49) + (0.064897229599999995 * fTemp51)) - (0.016923941000000001 * fTemp50)));
			double fTemp459 = (fConst58 * fRec975[1]);
			fRec977[0] = (fTemp458 + (fRec977[1] + fTemp459));
			fRec975[0] = fRec977[0];
			double fRec976 = (fTemp459 + fTemp458);
			double fTemp460 = (fConst60 * (((0.1111291864 * fTemp58) + (0.031008263500000001 * fTemp57)) - (((0.113610014 * fTemp54) + (0.031355407000000002 * fTemp55)) + (0.110056324 * fTemp56))));
			double fTemp461 = (fConst61 * fRec978[1]);
			double fTemp462 = (fConst62 * fRec981[1]);
			fRec983[0] = (fTemp460 + (fTemp461 + (fRec983[1] + fTemp462)));
			fRec981[0] = fRec983[0];
			double fRec982 = ((fTemp462 + fTemp461) + fTemp460);
			fRec980[0] = (fRec981[0] + fRec980[1]);
			fRec978[0] = fRec980[0];
			double fRec979 = fRec982;
			fVec20[(IOTA & 511)] = ((fRec940 + (fRec955 + (fRec967 + (fRec976 + fRec979)))) - (0.024821514499999999 * fTemp62));
			output20[i] = FAUSTFLOAT((0.87553802008608317 * (fRec83[0] * fVec20[((IOTA - iConst63) & 511)])));
			double fTemp463 = (fConst35 * fRec984[1]);
			double fTemp464 = (fConst37 * fRec987[1]);
			double fTemp465 = (fConst38 * fRec990[1]);
			double fTemp466 = (fConst40 * (((0.053742353999999999 * fTemp17) + ((0.12923621539999999 * fTemp11) + ((0.1556743921 * fTemp16) + ((0.20527408699999999 * fTemp9) + ((0.22810496659999999 * fTemp15) + ((0.0090294446000000004 * fTemp7) + (0.0046261855000000003 * fTemp13))))))) - ((0.074094947600000002 * fTemp10) + ((0.046692397599999998 * fTemp8) + ((0.097617073999999998 * fTemp12) + (0.0024184122000000001 * fTemp14))))));
			double fTemp467 = (fConst41 * fRec993[1]);
			double fTemp468 = (fConst42 * fRec996[1]);
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
			double fTemp469 = (fConst44 * fRec999[1]);
			double fTemp470 = (fConst45 * fRec1002[1]);
			double fTemp471 = (fConst47 * (((0.1449568678 * fTemp32) + ((0.16923011560000001 * fTemp27) + (0.038791516300000002 * fTemp31))) - ((0.0056473423000000002 * fTemp34) + (((((0.066170688599999999 * fTemp26) + (0.20525452990000001 * fTemp29)) + (0.039679674499999998 * fTemp30)) + (0.1740477144 * fTemp28)) + (0.072223551799999994 * fTemp33)))));
			double fTemp472 = (fConst48 * fRec1005[1]);
			double fTemp473 = (fConst49 * fRec1008[1]);
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
			double fTemp474 = (fConst51 * fRec1011[1]);
			double fTemp475 = (fConst53 * (((0.0079648351999999992 * fTemp45) + ((0.034223936699999999 * fTemp43) + (0.12042603189999999 * fTemp41))) - ((((0.016716358600000002 * fTemp39) + (0.1712052017 * fTemp42)) + (0.13475593429999999 * fTemp40)) + (0.1223711842 * fTemp44))));
			double fTemp476 = (fConst54 * fRec1014[1]);
			double fTemp477 = (fConst55 * fRec1017[1]);
			fRec1019[0] = (fTemp475 + (fTemp476 + (fRec1019[1] + fTemp477)));
			fRec1017[0] = fRec1019[0];
			double fRec1018 = ((fTemp477 + fTemp476) + fTemp475);
			fRec1016[0] = (fRec1017[0] + fRec1016[1]);
			fRec1014[0] = fRec1016[0];
			double fRec1015 = fRec1018;
			fRec1013[0] = (fTemp474 + (fRec1015 + fRec1013[1]));
			fRec1011[0] = fRec1013[0];
			double fRec1012 = (fRec1015 + fTemp474);
			double fTemp478 = (fConst57 * ((0.065989326000000001 * fTemp51) - ((0.0026756052999999998 * fTemp49) + (0.017747884799999999 * fTemp50))));
			double fTemp479 = (fConst58 * fRec1020[1]);
			fRec1022[0] = (fTemp478 + (fRec1022[1] + fTemp479));
			fRec1020[0] = fRec1022[0];
			double fRec1021 = (fTemp479 + fTemp478);
			double fTemp480 = (fConst60 * (((((0.11552185130000001 * fTemp54) + (0.0322585996 * fTemp55)) + (0.11123455610000001 * fTemp58)) + (0.030753097900000002 * fTemp57)) - (0.1116232573 * fTemp56)));
			double fTemp481 = (fConst61 * fRec1023[1]);
			double fTemp482 = (fConst62 * fRec1026[1]);
			fRec1028[0] = (fTemp480 + (fTemp481 + (fRec1028[1] + fTemp482)));
			fRec1026[0] = fRec1028[0];
			double fRec1027 = ((fTemp482 + fTemp481) + fTemp480);
			fRec1025[0] = (fRec1026[0] + fRec1025[1]);
			fRec1023[0] = fRec1025[0];
			double fRec1024 = fRec1027;
			fVec21[(IOTA & 511)] = ((fRec985 + (fRec1000 + (fRec1012 + (fRec1021 + fRec1024)))) - (0.024338159299999999 * fTemp62));
			output21[i] = FAUSTFLOAT((0.87553802008608317 * (fRec83[0] * fVec21[((IOTA - iConst63) & 511)])));
			double fTemp483 = (fConst35 * fRec1029[1]);
			double fTemp484 = (fConst37 * fRec1032[1]);
			double fTemp485 = (fConst38 * fRec1035[1]);
			double fTemp486 = (fConst40 * (((0.087322235400000003 * fTemp11) + ((0.1682093304 * fTemp16) + ((0.2332465856 * fTemp9) + ((0.0419138197 * fTemp8) + ((0.0021709078 * fTemp14) + ((0.22729814840000001 * fTemp12) + (0.0074227538999999997 * fTemp13))))))) - ((((0.0081053562000000003 * fTemp7) + (0.079272364900000003 * fTemp15)) + (0.13695292449999999 * fTemp10)) + (0.050915207800000001 * fTemp17))));
			double fTemp487 = (fConst41 * fRec1038[1]);
			double fTemp488 = (fConst42 * fRec1041[1]);
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
			double fTemp489 = (fConst44 * fRec1044[1]);
			double fTemp490 = (fConst45 * fRec1047[1]);
			double fTemp491 = (fConst47 * ((((0.059398670000000001 * fTemp26) + (0.0439739564 * fTemp31)) + (0.1681315565 * fTemp33)) - ((((((0.059135114699999998 * fTemp27) + (0.23260182300000001 * fTemp29)) + (0.042342755099999997 * fTemp30)) + (0.18783197430000001 * fTemp28)) + (0.13733998110000001 * fTemp32)) + (0.0026894572999999998 * fTemp34))));
			double fTemp492 = (fConst48 * fRec1050[1]);
			double fTemp493 = (fConst49 * fRec1053[1]);
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
			double fTemp494 = (fConst51 * fRec1056[1]);
			double fTemp495 = (fConst53 * (((0.0058740768 * fTemp39) + (0.1268189378 * fTemp43)) - ((0.017335587 * fTemp45) + ((((0.1949281953 * fTemp42) + (0.1446776894 * fTemp40)) + (0.045779269400000003 * fTemp44)) + (0.1141022904 * fTemp41)))));
			double fTemp496 = (fConst54 * fRec1059[1]);
			double fTemp497 = (fConst55 * fRec1062[1]);
			fRec1064[0] = (fTemp495 + (fTemp496 + (fRec1064[1] + fTemp497)));
			fRec1062[0] = fRec1064[0];
			double fRec1063 = ((fTemp497 + fTemp496) + fTemp495);
			fRec1061[0] = (fRec1062[0] + fRec1061[1]);
			fRec1059[0] = fRec1061[0];
			double fRec1060 = fRec1063;
			fRec1058[0] = (fTemp494 + (fRec1060 + fRec1058[1]));
			fRec1056[0] = fRec1058[0];
			double fRec1057 = (fRec1060 + fTemp494);
			double fTemp498 = (fConst57 * (((0.017289348199999999 * fTemp49) + (0.070649718200000003 * fTemp51)) + (0.0016867649 * fTemp50)));
			double fTemp499 = (fConst58 * fRec1065[1]);
			fRec1067[0] = (fTemp498 + (fRec1067[1] + fTemp499));
			fRec1065[0] = fRec1067[0];
			double fRec1066 = (fTemp499 + fTemp498);
			double fTemp500 = (fConst60 * ((((0.13002947279999999 * fTemp54) + (0.1152903814 * fTemp55)) + (0.1207983197 * fTemp58)) - ((0.0423692549 * fTemp56) + (0.029140952800000001 * fTemp57))));
			double fTemp501 = (fConst61 * fRec1068[1]);
			double fTemp502 = (fConst62 * fRec1071[1]);
			fRec1073[0] = (fTemp500 + (fTemp501 + (fRec1073[1] + fTemp502)));
			fRec1071[0] = fRec1073[0];
			double fRec1072 = ((fTemp502 + fTemp501) + fTemp500);
			fRec1070[0] = (fRec1071[0] + fRec1070[1]);
			fRec1068[0] = fRec1070[0];
			double fRec1069 = fRec1072;
			fVec22[(IOTA & 511)] = ((fRec1030 + (fRec1045 + (fRec1057 + (fRec1066 + fRec1069)))) - (0.0269290945 * fTemp62));
			output22[i] = FAUSTFLOAT((0.87553802008608317 * (fRec83[0] * fVec22[((IOTA - iConst63) & 511)])));
			double fTemp503 = (fConst35 * fRec1074[1]);
			double fTemp504 = (fConst37 * fRec1077[1]);
			double fTemp505 = (fConst38 * fRec1080[1]);
			double fTemp506 = (fConst40 * (((0.16912089969999999 * fTemp16) + ((0.0075485531999999996 * fTemp7) + (0.0053325960999999998 * fTemp13))) - ((0.057165088599999997 * fTemp17) + ((0.080380996400000002 * fTemp11) + ((0.1399220638 * fTemp10) + ((0.2145769381 * fTemp9) + ((0.1085215536 * fTemp15) + ((0.039034521000000003 * fTemp8) + ((0.21903448280000001 * fTemp12) + (0.0020217757999999998 * fTemp14))))))))));
			double fTemp507 = (fConst41 * fRec1083[1]);
			double fTemp508 = (fConst42 * fRec1086[1]);
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
			double fTemp509 = (fConst44 * fRec1089[1]);
			double fTemp510 = (fConst45 * fRec1092[1]);
			double fTemp511 = (fConst47 * ((0.21398066639999999 * fTemp29) - ((0.0057031940999999996 * fTemp34) + ((0.16203715160000001 * fTemp33) + ((0.15451922879999999 * fTemp32) + (((((0.055318237300000003 * fTemp26) + (0.080658764100000002 * fTemp27)) + (0.041509963300000001 * fTemp30)) + (0.1890521087 * fTemp28)) + (0.041083939899999998 * fTemp31)))))));
			double fTemp512 = (fConst48 * fRec1095[1]);
			double fTemp513 = (fConst49 * fRec1098[1]);
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
			double fTemp514 = (fConst51 * fRec1101[1]);
			double fTemp515 = (fConst53 * ((((((0.0083411658999999992 * fTemp39) + (0.17932761699999999 * fTemp42)) + (0.13307688679999999 * fTemp43)) + (0.040897704899999998 * fTemp44)) + (0.0166919975 * fTemp45)) - ((0.1462780289 * fTemp40) + (0.1285287094 * fTemp41))));
			double fTemp516 = (fConst54 * fRec1104[1]);
			double fTemp517 = (fConst55 * fRec1107[1]);
			fRec1109[0] = (fTemp515 + (fTemp516 + (fRec1109[1] + fTemp517)));
			fRec1107[0] = fRec1109[0];
			double fRec1108 = ((fTemp517 + fTemp516) + fTemp515);
			fRec1106[0] = (fRec1107[0] + fRec1106[1]);
			fRec1104[0] = fRec1106[0];
			double fRec1105 = fRec1108;
			fRec1103[0] = (fTemp514 + (fRec1105 + fRec1103[1]));
			fRec1101[0] = fRec1103[0];
			double fRec1102 = (fRec1105 + fTemp514);
			double fTemp518 = (fConst57 * (((0.018882534600000001 * fTemp49) + (0.071606547600000001 * fTemp51)) - (0.0019918847 * fTemp50)));
			double fTemp519 = (fConst58 * fRec1110[1]);
			fRec1112[0] = (fTemp518 + (fRec1112[1] + fTemp519));
			fRec1110[0] = fRec1112[0];
			double fRec1111 = (fTemp519 + fTemp518);
			double fTemp520 = (fConst60 * ((((0.1208343536 * fTemp55) + (0.1209193812 * fTemp58)) + (0.0379092506 * fTemp56)) - ((0.1196154026 * fTemp54) + (0.032927063700000002 * fTemp57))));
			double fTemp521 = (fConst61 * fRec1113[1]);
			double fTemp522 = (fConst62 * fRec1116[1]);
			fRec1118[0] = (fTemp520 + (fTemp521 + (fRec1118[1] + fTemp522)));
			fRec1116[0] = fRec1118[0];
			double fRec1117 = ((fTemp522 + fTemp521) + fTemp520);
			fRec1115[0] = (fRec1116[0] + fRec1115[1]);
			fRec1113[0] = fRec1115[0];
			double fRec1114 = fRec1117;
			fVec23[(IOTA & 511)] = ((fRec1075 + (fRec1090 + (fRec1102 + (fRec1111 + fRec1114)))) - (0.0265202836 * fTemp62));
			output23[i] = FAUSTFLOAT((0.87553802008608317 * (fRec83[0] * fVec23[((IOTA - iConst63) & 511)])));
			double fTemp523 = (0.17366778560000001 * fTemp62);
			double fTemp524 = (fConst65 * fRec1119[1]);
			double fTemp525 = (fConst67 * fRec1122[1]);
			double fTemp526 = (fConst68 * fRec1125[1]);
			double fTemp527 = (0.0001199645 * fTemp17);
			double fTemp528 = (0.14644675670000001 * fTemp11);
			double fTemp529 = (0.14653482640000001 * fTemp10);
			double fTemp530 = (0.6237730628 * fTemp9);
			double fTemp531 = ((4.1184199999999998e-05 * fTemp8) + (2.1331e-06 * fTemp14));
			double fTemp532 = ((6.0729999999999999e-07 * fTemp15) + fTemp531);
			double fTemp533 = (0.64623961799999996 * fTemp16);
			double fTemp534 = (7.9642999999999993e-06 * fTemp7);
			double fTemp535 = (0.017994754299999999 * fTemp13);
			double fTemp536 = (fTemp534 + ((0.00078693070000000005 * fTemp12) + fTemp535));
			double fTemp537 = (fConst70 * ((fTemp527 + (fTemp528 + (fTemp529 + (fTemp530 + fTemp532)))) - (fTemp533 + fTemp536)));
			double fTemp538 = (fConst71 * fRec1128[1]);
			double fTemp539 = (fConst72 * fRec1131[1]);
			fRec1133[0] = (fTemp537 + (fTemp538 + (fRec1133[1] + fTemp539)));
			fRec1131[0] = fRec1133[0];
			double fRec1132 = ((fTemp539 + fTemp538) + fTemp537);
			fRec1130[0] = (fRec1131[0] + fRec1130[1]);
			fRec1128[0] = fRec1130[0];
			double fRec1129 = fRec1132;
			fRec1127[0] = (fTemp525 + (fTemp526 + (fRec1129 + fRec1127[1])));
			fRec1125[0] = fRec1127[0];
			double fRec1126 = (fTemp525 + (fRec1129 + fTemp526));
			fRec1124[0] = (fRec1125[0] + fRec1124[1]);
			fRec1122[0] = fRec1124[0];
			double fRec1123 = fRec1126;
			fRec1121[0] = (fTemp524 + (fRec1123 + fRec1121[1]));
			fRec1119[0] = fRec1121[0];
			double fRec1120 = (fRec1123 + fTemp524);
			double fTemp540 = (fConst74 * fRec1134[1]);
			double fTemp541 = (fConst75 * fRec1137[1]);
			double fTemp542 = (0.00032411650000000001 * fTemp32);
			double fTemp543 = (0.1505321906 * fTemp31);
			double fTemp544 = (5.83647e-05 * fTemp26);
			double fTemp545 = (fTemp544 + (0.00017297640000000001 * fTemp27));
			double fTemp546 = (0.15061155409999999 * fTemp30);
			double fTemp547 = (0.28928390380000002 * fTemp28);
			double fTemp548 = (0.012063806099999999 * fTemp34);
			double fTemp549 = (0.16971473209999999 * fTemp29);
			double fTemp550 = (0.00075671479999999997 * fTemp33);
			double fTemp551 = (fConst77 * (((fTemp542 + (fTemp543 + ((fTemp545 + fTemp546) + fTemp547))) + fTemp548) - (fTemp549 + fTemp550)));
			double fTemp552 = (fConst78 * fRec1140[1]);
			double fTemp553 = (fConst79 * fRec1143[1]);
			fRec1145[0] = (fTemp551 + (fTemp552 + (fRec1145[1] + fTemp553)));
			fRec1143[0] = fRec1145[0];
			double fRec1144 = ((fTemp553 + fTemp552) + fTemp551);
			fRec1142[0] = (fRec1143[0] + fRec1142[1]);
			fRec1140[0] = fRec1142[0];
			double fRec1141 = fRec1144;
			fRec1139[0] = (fTemp540 + (fTemp541 + (fRec1141 + fRec1139[1])));
			fRec1137[0] = fRec1139[0];
			double fRec1138 = (fTemp540 + (fRec1141 + fTemp541));
			fRec1136[0] = (fRec1137[0] + fRec1136[1]);
			fRec1134[0] = fRec1136[0];
			double fRec1135 = fRec1138;
			double fTemp554 = (fConst81 * fRec1146[1]);
			double fTemp555 = (0.0001599332 * fTemp45);
			double fTemp556 = (0.00026952669999999999 * fTemp41);
			double fTemp557 = (0.074508424200000006 * fTemp43);
			double fTemp558 = (0.33328122049999998 * fTemp40);
			double fTemp559 = (0.0744835212 * fTemp44);
			double fTemp560 = (0.0001022335 * fTemp39);
			double fTemp561 = (0.14375684750000001 * fTemp42);
			double fTemp562 = (fConst83 * ((fTemp555 + (fTemp556 + ((fTemp557 + fTemp558) + fTemp559))) - (fTemp560 + fTemp561)));
			double fTemp563 = (fConst84 * fRec1149[1]);
			double fTemp564 = (fConst85 * fRec1152[1]);
			fRec1154[0] = (fTemp562 + (fTemp563 + (fRec1154[1] + fTemp564)));
			fRec1152[0] = fRec1154[0];
			double fRec1153 = ((fTemp564 + fTemp563) + fTemp562);
			fRec1151[0] = (fRec1152[0] + fRec1151[1]);
			fRec1149[0] = fRec1151[0];
			double fRec1150 = fRec1153;
			fRec1148[0] = (fTemp554 + (fRec1150 + fRec1148[1]));
			fRec1146[0] = fRec1148[0];
			double fRec1147 = (fRec1150 + fTemp554);
			double fTemp565 = (0.0277235438 * fTemp51);
			double fTemp566 = ((0.056348557399999999 * fTemp49) + fTemp565);
			double fTemp567 = (0.056322885599999997 * fTemp50);
			double fTemp568 = (fConst87 * (fTemp566 + fTemp567));
			double fTemp569 = (fConst88 * fRec1155[1]);
			fRec1157[0] = (fTemp568 + (fRec1157[1] + fTemp569));
			fRec1155[0] = fRec1157[0];
			double fRec1156 = (fTemp569 + fTemp568);
			double fTemp570 = (0.35106751780000001 * fTemp54);
			double fTemp571 = (0.060283826499999998 * fTemp55);
			double fTemp572 = (0.060265204599999997 * fTemp56);
			double fTemp573 = (6.9000599999999998e-05 * fTemp57);
			double fTemp574 = (0.17771662099999999 * fTemp58);
			double fTemp575 = (fConst90 * ((((fTemp570 + fTemp571) + fTemp572) + fTemp573) - fTemp574));
			double fTemp576 = (fConst91 * fRec1158[1]);
			double fTemp577 = (fConst92 * fRec1161[1]);
			fRec1163[0] = (fTemp575 + (fTemp576 + (fRec1163[1] + fTemp577)));
			fRec1161[0] = fRec1163[0];
			double fRec1162 = ((fTemp577 + fTemp576) + fTemp575);
			fRec1160[0] = (fRec1161[0] + fRec1160[1]);
			fRec1158[0] = fRec1160[0];
			double fRec1159 = fRec1162;
			fVec24[(IOTA & 255)] = (fTemp523 + (fRec1120 + (fRec1135 + (fRec1147 + (fRec1156 + fRec1159)))));
			output24[i] = FAUSTFLOAT((0.95355093256814927 * (fRec83[0] * fVec24[((IOTA - iConst93) & 255)])));
			double fTemp578 = (fConst65 * fRec1164[1]);
			double fTemp579 = (fConst67 * fRec1167[1]);
			double fTemp580 = (fConst68 * fRec1170[1]);
			double fTemp581 = (fTemp531 + (0.00013733260000000001 * fTemp15));
			double fTemp582 = (0.14656861560000001 * fTemp10);
			double fTemp583 = (0.62353010789999996 * fTemp9);
			double fTemp584 = (fConst70 * ((fTemp527 + (fTemp528 + fTemp581)) - (fTemp533 + (fTemp582 + (fTemp536 + fTemp583)))));
			double fTemp585 = (fConst71 * fRec1173[1]);
			double fTemp586 = (fConst72 * fRec1176[1]);
			fRec1178[0] = (fTemp584 + (fTemp585 + (fRec1178[1] + fTemp586)));
			fRec1176[0] = fRec1178[0];
			double fRec1177 = ((fTemp586 + fTemp585) + fTemp584);
			fRec1175[0] = (fRec1176[0] + fRec1175[1]);
			fRec1173[0] = fRec1175[0];
			double fRec1174 = fRec1177;
			fRec1172[0] = (fTemp579 + (fTemp580 + (fRec1174 + fRec1172[1])));
			fRec1170[0] = fRec1172[0];
			double fRec1171 = (fTemp579 + (fRec1174 + fTemp580));
			fRec1169[0] = (fRec1170[0] + fRec1169[1]);
			fRec1167[0] = fRec1169[0];
			double fRec1168 = fRec1171;
			fRec1166[0] = (fTemp578 + (fRec1168 + fRec1166[1]));
			fRec1164[0] = fRec1166[0];
			double fRec1165 = (fRec1168 + fTemp578);
			double fTemp587 = (fConst74 * fRec1179[1]);
			double fTemp588 = (fConst75 * fRec1182[1]);
			double fTemp589 = (0.1694727026 * fTemp29);
			double fTemp590 = (7.0871500000000001e-05 * fTemp27);
			double fTemp591 = (0.1506318076 * fTemp30);
			double fTemp592 = (fConst77 * ((fTemp548 + (fTemp542 + (fTemp543 + (fTemp547 + (fTemp544 + fTemp589))))) - (fTemp550 + (fTemp590 + fTemp591))));
			double fTemp593 = (fConst78 * fRec1185[1]);
			double fTemp594 = (fConst79 * fRec1188[1]);
			fRec1190[0] = (fTemp592 + (fTemp593 + (fRec1190[1] + fTemp594)));
			fRec1188[0] = fRec1190[0];
			double fRec1189 = ((fTemp594 + fTemp593) + fTemp592);
			fRec1187[0] = (fRec1188[0] + fRec1187[1]);
			fRec1185[0] = fRec1187[0];
			double fRec1186 = fRec1189;
			fRec1184[0] = (fTemp587 + (fTemp588 + (fRec1186 + fRec1184[1])));
			fRec1182[0] = fRec1184[0];
			double fRec1183 = (fTemp587 + (fRec1186 + fTemp588));
			fRec1181[0] = (fRec1182[0] + fRec1181[1]);
			fRec1179[0] = fRec1181[0];
			double fRec1180 = fRec1183;
			double fTemp595 = (fConst81 * fRec1191[1]);
			double fTemp596 = (9.1717699999999998e-05 * fTemp39);
			double fTemp597 = (0.14355364570000001 * fTemp42);
			double fTemp598 = (0.074497140200000006 * fTemp43);
			double fTemp599 = (fConst83 * ((fTemp555 + (fTemp556 + (fTemp559 + (fTemp558 + (fTemp596 + fTemp597))))) - fTemp598));
			double fTemp600 = (fConst84 * fRec1194[1]);
			double fTemp601 = (fConst85 * fRec1197[1]);
			fRec1199[0] = (fTemp599 + (fTemp600 + (fRec1199[1] + fTemp601)));
			fRec1197[0] = fRec1199[0];
			double fRec1198 = ((fTemp601 + fTemp600) + fTemp599);
			fRec1196[0] = (fRec1197[0] + fRec1196[1]);
			fRec1194[0] = fRec1196[0];
			double fRec1195 = fRec1198;
			fRec1193[0] = (fTemp595 + (fRec1195 + fRec1193[1]));
			fRec1191[0] = fRec1193[0];
			double fRec1192 = (fRec1195 + fTemp595);
			double fTemp602 = (0.056351278400000003 * fTemp49);
			double fTemp603 = (fConst87 * ((fTemp565 + fTemp567) - fTemp602));
			double fTemp604 = (fConst88 * fRec1200[1]);
			fRec1202[0] = (fTemp603 + (fRec1202[1] + fTemp604));
			fRec1200[0] = fRec1202[0];
			double fRec1201 = (fTemp604 + fTemp603);
			double fTemp605 = (0.3509325794 * fTemp54);
			double fTemp606 = (0.060272866000000001 * fTemp55);
			double fTemp607 = (fConst90 * ((fTemp572 + fTemp573) - (fTemp574 + (fTemp605 + fTemp606))));
			double fTemp608 = (fConst91 * fRec1203[1]);
			double fTemp609 = (fConst92 * fRec1206[1]);
			fRec1208[0] = (fTemp607 + (fTemp608 + (fRec1208[1] + fTemp609)));
			fRec1206[0] = fRec1208[0];
			double fRec1207 = ((fTemp609 + fTemp608) + fTemp607);
			fRec1205[0] = (fRec1206[0] + fRec1205[1]);
			fRec1203[0] = fRec1205[0];
			double fRec1204 = fRec1207;
			fVec25[(IOTA & 255)] = (fTemp523 + (fRec1165 + (fRec1180 + (fRec1192 + (fRec1201 + fRec1204)))));
			output25[i] = FAUSTFLOAT((0.95355093256814927 * (fRec83[0] * fVec25[((IOTA - iConst93) & 255)])));
			double fTemp610 = (fConst65 * fRec1209[1]);
			double fTemp611 = (fConst67 * fRec1212[1]);
			double fTemp612 = (fConst68 * fRec1215[1]);
			double fTemp613 = (0.14665668530000001 * fTemp11);
			double fTemp614 = (fTemp534 + (fTemp535 + (0.00092365600000000002 * fTemp12)));
			double fTemp615 = (fConst70 * ((fTemp527 + (fTemp530 + fTemp581)) - (fTemp613 + (fTemp533 + (fTemp582 + fTemp614)))));
			double fTemp616 = (fConst71 * fRec1218[1]);
			double fTemp617 = (fConst72 * fRec1221[1]);
			fRec1223[0] = (fTemp615 + (fTemp616 + (fRec1223[1] + fTemp617)));
			fRec1221[0] = fRec1223[0];
			double fRec1222 = ((fTemp617 + fTemp616) + fTemp615);
			fRec1220[0] = (fRec1221[0] + fRec1220[1]);
			fRec1218[0] = fRec1220[0];
			double fRec1219 = fRec1222;
			fRec1217[0] = (fTemp611 + (fTemp612 + (fRec1219 + fRec1217[1])));
			fRec1215[0] = fRec1217[0];
			double fRec1216 = (fTemp611 + (fRec1219 + fTemp612));
			fRec1214[0] = (fRec1215[0] + fRec1214[1]);
			fRec1212[0] = fRec1214[0];
			double fRec1213 = fRec1216;
			fRec1211[0] = (fTemp610 + (fRec1213 + fRec1211[1]));
			fRec1209[0] = fRec1211[0];
			double fRec1210 = (fRec1213 + fTemp610);
			double fTemp618 = (fConst74 * fRec1224[1]);
			double fTemp619 = (fConst75 * fRec1227[1]);
			double fTemp620 = (0.00051286690000000004 * fTemp33);
			double fTemp621 = (0.15071117119999999 * fTemp31);
			double fTemp622 = (fConst77 * ((fTemp548 + (fTemp542 + (fTemp544 + fTemp547))) - (fTemp620 + ((fTemp591 + (fTemp549 + fTemp590)) + fTemp621))));
			double fTemp623 = (fConst78 * fRec1230[1]);
			double fTemp624 = (fConst79 * fRec1233[1]);
			fRec1235[0] = (fTemp622 + (fTemp623 + (fRec1235[1] + fTemp624)));
			fRec1233[0] = fRec1235[0];
			double fRec1234 = ((fTemp624 + fTemp623) + fTemp622);
			fRec1232[0] = (fRec1233[0] + fRec1232[1]);
			fRec1230[0] = fRec1232[0];
			double fRec1231 = fRec1234;
			fRec1229[0] = (fTemp618 + (fTemp619 + (fRec1231 + fRec1229[1])));
			fRec1227[0] = fRec1229[0];
			double fRec1228 = (fTemp618 + (fRec1231 + fTemp619));
			fRec1226[0] = (fRec1227[0] + fRec1226[1]);
			fRec1224[0] = fRec1226[0];
			double fRec1225 = fRec1228;
			double fTemp625 = (fConst81 * fRec1236[1]);
			double fTemp626 = (3.4017999999999999e-05 * fTemp45);
			double fTemp627 = (0.074522043299999993 * fTemp44);
			double fTemp628 = (fConst83 * ((fTemp556 + (fTemp558 + fTemp596)) - (fTemp626 + ((fTemp561 + fTemp598) + fTemp627))));
			double fTemp629 = (fConst84 * fRec1239[1]);
			double fTemp630 = (fConst85 * fRec1242[1]);
			fRec1244[0] = (fTemp628 + (fTemp629 + (fRec1244[1] + fTemp630)));
			fRec1242[0] = fRec1244[0];
			double fRec1243 = ((fTemp630 + fTemp629) + fTemp628);
			fRec1241[0] = (fRec1242[0] + fRec1241[1]);
			fRec1239[0] = fRec1241[0];
			double fRec1240 = fRec1243;
			fRec1238[0] = (fTemp625 + (fRec1240 + fRec1238[1]));
			fRec1236[0] = fRec1238[0];
			double fRec1237 = (fRec1240 + fTemp625);
			double fTemp631 = (0.056376950199999998 * fTemp50);
			double fTemp632 = (fConst87 * (fTemp565 - (fTemp602 + fTemp631)));
			double fTemp633 = (fConst88 * fRec1245[1]);
			fRec1247[0] = (fTemp632 + (fRec1247[1] + fTemp633));
			fRec1245[0] = fRec1247[0];
			double fRec1246 = (fTemp633 + fTemp632);
			double fTemp634 = (0.060291487900000003 * fTemp56);
			double fTemp635 = (fConst90 * ((fTemp570 + fTemp573) - ((fTemp574 + fTemp606) + fTemp634)));
			double fTemp636 = (fConst91 * fRec1248[1]);
			double fTemp637 = (fConst92 * fRec1251[1]);
			fRec1253[0] = (fTemp635 + (fTemp636 + (fRec1253[1] + fTemp637)));
			fRec1251[0] = fRec1253[0];
			double fRec1252 = ((fTemp637 + fTemp636) + fTemp635);
			fRec1250[0] = (fRec1251[0] + fRec1250[1]);
			fRec1248[0] = fRec1250[0];
			double fRec1249 = fRec1252;
			fVec26[(IOTA & 255)] = (fTemp523 + (fRec1210 + (fRec1225 + (fRec1237 + (fRec1246 + fRec1249)))));
			output26[i] = FAUSTFLOAT((0.95355093256814927 * (fRec83[0] * fVec26[((IOTA - iConst93) & 255)])));
			double fTemp638 = (fConst65 * fRec1254[1]);
			double fTemp639 = (fConst67 * fRec1257[1]);
			double fTemp640 = (fConst68 * fRec1260[1]);
			double fTemp641 = (fConst70 * ((fTemp527 + (fTemp529 + fTemp532)) - (fTemp613 + (fTemp533 + (fTemp583 + fTemp614)))));
			double fTemp642 = (fConst71 * fRec1263[1]);
			double fTemp643 = (fConst72 * fRec1266[1]);
			fRec1268[0] = (fTemp641 + (fTemp642 + (fRec1268[1] + fTemp643)));
			fRec1266[0] = fRec1268[0];
			double fRec1267 = ((fTemp643 + fTemp642) + fTemp641);
			fRec1265[0] = (fRec1266[0] + fRec1265[1]);
			fRec1263[0] = fRec1265[0];
			double fRec1264 = fRec1267;
			fRec1262[0] = (fTemp639 + (fTemp640 + (fRec1264 + fRec1262[1])));
			fRec1260[0] = fRec1262[0];
			double fRec1261 = (fTemp639 + (fRec1264 + fTemp640));
			fRec1259[0] = (fRec1260[0] + fRec1259[1]);
			fRec1257[0] = fRec1259[0];
			double fRec1258 = fRec1261;
			fRec1256[0] = (fTemp638 + (fRec1258 + fRec1256[1]));
			fRec1254[0] = fRec1256[0];
			double fRec1255 = (fRec1258 + fTemp638);
			double fTemp644 = (fConst74 * fRec1269[1]);
			double fTemp645 = (fConst75 * fRec1272[1]);
			double fTemp646 = (fConst77 * ((fTemp548 + (fTemp542 + (fTemp547 + (fTemp546 + (fTemp545 + fTemp589))))) - (fTemp621 + fTemp620)));
			double fTemp647 = (fConst78 * fRec1275[1]);
			double fTemp648 = (fConst79 * fRec1278[1]);
			fRec1280[0] = (fTemp646 + (fTemp647 + (fRec1280[1] + fTemp648)));
			fRec1278[0] = fRec1280[0];
			double fRec1279 = ((fTemp648 + fTemp647) + fTemp646);
			fRec1277[0] = (fRec1278[0] + fRec1277[1]);
			fRec1275[0] = fRec1277[0];
			double fRec1276 = fRec1279;
			fRec1274[0] = (fTemp644 + (fTemp645 + (fRec1276 + fRec1274[1])));
			fRec1272[0] = fRec1274[0];
			double fRec1273 = (fTemp644 + (fRec1276 + fTemp645));
			fRec1271[0] = (fRec1272[0] + fRec1271[1]);
			fRec1269[0] = fRec1271[0];
			double fRec1270 = fRec1273;
			double fTemp649 = (fConst81 * fRec1281[1]);
			double fTemp650 = (fConst83 * ((fTemp556 + (fTemp558 + (fTemp557 + fTemp597))) - (fTemp626 + (fTemp560 + fTemp627))));
			double fTemp651 = (fConst84 * fRec1284[1]);
			double fTemp652 = (fConst85 * fRec1287[1]);
			fRec1289[0] = (fTemp650 + (fTemp651 + (fRec1289[1] + fTemp652)));
			fRec1287[0] = fRec1289[0];
			double fRec1288 = ((fTemp652 + fTemp651) + fTemp650);
			fRec1286[0] = (fRec1287[0] + fRec1286[1]);
			fRec1284[0] = fRec1286[0];
			double fRec1285 = fRec1288;
			fRec1283[0] = (fTemp649 + (fRec1285 + fRec1283[1]));
			fRec1281[0] = fRec1283[0];
			double fRec1282 = (fRec1285 + fTemp649);
			double fTemp653 = (fConst87 * (fTemp566 - fTemp631));
			double fTemp654 = (fConst88 * fRec1290[1]);
			fRec1292[0] = (fTemp653 + (fRec1292[1] + fTemp654));
			fRec1290[0] = fRec1292[0];
			double fRec1291 = (fTemp654 + fTemp653);
			double fTemp655 = (fConst90 * ((fTemp571 + fTemp573) - (fTemp634 + (fTemp574 + fTemp605))));
			double fTemp656 = (fConst91 * fRec1293[1]);
			double fTemp657 = (fConst92 * fRec1296[1]);
			fRec1298[0] = (fTemp655 + (fTemp656 + (fRec1298[1] + fTemp657)));
			fRec1296[0] = fRec1298[0];
			double fRec1297 = ((fTemp657 + fTemp656) + fTemp655);
			fRec1295[0] = (fRec1296[0] + fRec1295[1]);
			fRec1293[0] = fRec1295[0];
			double fRec1294 = fRec1297;
			fVec27[(IOTA & 255)] = (fTemp523 + (fRec1255 + (fRec1270 + (fRec1282 + (fRec1291 + fRec1294)))));
			output27[i] = FAUSTFLOAT((0.95355093256814927 * (fRec83[0] * fVec27[((IOTA - iConst93) & 255)])));
			double fTemp658 = (fConst95 * fRec1299[1]);
			double fTemp659 = (fConst97 * fRec1302[1]);
			double fTemp660 = (fConst98 * fRec1305[1]);
			double fTemp661 = (fConst100 * (((0.00028913190000000002 * fTemp11) + ((1.862014643 * fTemp16) + ((4.65375e-05 * fTemp10) + ((2.1938099999999999e-05 * fTemp7) + ((0.0023559682 * fTemp12) + (0.049567868199999997 * fTemp13)))))) - ((0.000330451 * fTemp17) + ((0.00033461850000000002 * fTemp9) + ((0.00018998269999999999 * fTemp15) + ((0.0001134449 * fTemp8) + (5.8757999999999997e-06 * fTemp14)))))));
			double fTemp662 = (fConst101 * fRec1308[1]);
			double fTemp663 = (fConst102 * fRec1311[1]);
			fRec1313[0] = (fTemp661 + (fTemp662 + (fRec1313[1] + fTemp663)));
			fRec1311[0] = fRec1313[0];
			double fRec1312 = ((fTemp663 + fTemp662) + fTemp661);
			fRec1310[0] = (fRec1311[0] + fRec1310[1]);
			fRec1308[0] = fRec1310[0];
			double fRec1309 = fRec1312;
			fRec1307[0] = (fTemp659 + (fTemp660 + (fRec1309 + fRec1307[1])));
			fRec1305[0] = fRec1307[0];
			double fRec1306 = (fTemp659 + (fRec1309 + fTemp660));
			fRec1304[0] = (fRec1305[0] + fRec1304[1]);
			fRec1302[0] = fRec1304[0];
			double fRec1303 = fRec1306;
			fRec1301[0] = (fTemp658 + (fRec1303 + fRec1301[1]));
			fRec1299[0] = fRec1301[0];
			double fRec1300 = (fRec1303 + fTemp658);
			double fTemp664 = (fConst104 * fRec1314[1]);
			double fTemp665 = (fConst105 * fRec1317[1]);
			double fTemp666 = (fConst107 * (((((0.00033334400000000001 * fTemp29) + (2.7894799999999999e-05 * fTemp30)) + (0.00024650760000000002 * fTemp31)) + (0.0017485778999999999 * fTemp33)) - (((((0.0001607697 * fTemp26) + (0.00014062769999999999 * fTemp27)) + (0.61195173650000001 * fTemp28)) + (0.00089280260000000004 * fTemp32)) + (0.033230637 * fTemp34))));
			double fTemp667 = (fConst108 * fRec1320[1]);
			double fTemp668 = (fConst109 * fRec1323[1]);
			fRec1325[0] = (fTemp666 + (fTemp667 + (fRec1325[1] + fTemp668)));
			fRec1323[0] = fRec1325[0];
			double fRec1324 = ((fTemp668 + fTemp667) + fTemp666);
			fRec1322[0] = (fRec1323[0] + fRec1322[1]);
			fRec1320[0] = fRec1322[0];
			double fRec1321 = fRec1324;
			fRec1319[0] = (fTemp664 + (fTemp665 + (fRec1321 + fRec1319[1])));
			fRec1317[0] = fRec1319[0];
			double fRec1318 = (fTemp664 + (fRec1321 + fTemp665));
			fRec1316[0] = (fRec1317[0] + fRec1316[1]);
			fRec1314[0] = fRec1316[0];
			double fRec1315 = fRec1318;
			double fTemp669 = (fConst111 * fRec1326[1]);
			double fTemp670 = (fConst113 * ((((1.4483200000000001e-05 * fTemp39) + (0.00027986709999999998 * fTemp42)) + (5.3056000000000002e-05 * fTemp44)) - ((0.00017342130000000001 * fTemp45) + (((1.55413e-05 * fTemp43) + (0.67593365890000001 * fTemp40)) + (0.00074243089999999996 * fTemp41)))));
			double fTemp671 = (fConst114 * fRec1329[1]);
			double fTemp672 = (fConst115 * fRec1332[1]);
			fRec1334[0] = (fTemp670 + (fTemp671 + (fRec1334[1] + fTemp672)));
			fRec1332[0] = fRec1334[0];
			double fRec1333 = ((fTemp672 + fTemp671) + fTemp670);
			fRec1331[0] = (fRec1332[0] + fRec1331[1]);
			fRec1329[0] = fRec1331[0];
			double fRec1330 = fRec1333;
			fRec1328[0] = (fTemp669 + (fRec1330 + fRec1328[1]));
			fRec1326[0] = fRec1328[0];
			double fRec1327 = (fRec1330 + fTemp669);
			double fTemp673 = (fConst117 * (((3.7477000000000001e-06 * fTemp49) + (0.1061069068 * fTemp51)) + (7.4462399999999994e-05 * fTemp50)));
			double fTemp674 = (fConst118 * fRec1335[1]);
			fRec1337[0] = (fTemp673 + (fRec1337[1] + fTemp674));
			fRec1335[0] = fRec1337[0];
			double fRec1336 = (fTemp674 + fTemp673);
			double fTemp675 = (fConst120 * (((0.72699112200000005 * fTemp58) + (3.6199699999999998e-05 * fTemp56)) - (((0.0001858489 * fTemp54) + (1.50956e-05 * fTemp55)) + (0.0001900672 * fTemp57))));
			double fTemp676 = (fConst121 * fRec1338[1]);
			double fTemp677 = (fConst122 * fRec1341[1]);
			fRec1343[0] = (fTemp675 + (fTemp676 + (fRec1343[1] + fTemp677)));
			fRec1341[0] = fRec1343[0];
			double fRec1342 = ((fTemp677 + fTemp676) + fTemp675);
			fRec1340[0] = (fRec1341[0] + fRec1340[1]);
			fRec1338[0] = fRec1340[0];
			double fRec1339 = fRec1342;
			output28[i] = FAUSTFLOAT((fRec83[0] * ((fRec1300 + (fRec1315 + (fRec1327 + (fRec1336 + fRec1339)))) - (0.4072278681 * fTemp62))));
			fRec15[1] = fRec15[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
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
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
			fRec14[1] = fRec14[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec9[1] = fRec9[0];
			fRec8[1] = fRec8[0];
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
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
			fRec39[1] = fRec39[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec34[1] = fRec34[0];
			fRec33[1] = fRec33[0];
			fRec31[1] = fRec31[0];
			fRec30[1] = fRec30[0];
			fRec28[1] = fRec28[0];
			fRec58[2] = fRec58[1];
			fRec58[1] = fRec58[0];
			fRec59[2] = fRec59[1];
			fRec59[1] = fRec59[0];
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
			fRec57[1] = fRec57[0];
			fRec55[1] = fRec55[0];
			fRec54[1] = fRec54[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec49[1] = fRec49[0];
			fRec68[2] = fRec68[1];
			fRec68[1] = fRec68[0];
			fRec69[2] = fRec69[1];
			fRec69[1] = fRec69[0];
			fRec70[2] = fRec70[1];
			fRec70[1] = fRec70[0];
			fRec67[1] = fRec67[0];
			fRec65[1] = fRec65[0];
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
			fRec76[1] = fRec76[0];
			fRec74[1] = fRec74[0];
			fRec73[1] = fRec73[0];
			fRec71[1] = fRec71[0];
			fRec82[2] = fRec82[1];
			fRec82[1] = fRec82[0];
			IOTA = (IOTA + 1);
			fRec83[1] = fRec83[0];
			fRec86[1] = fRec86[0];
			fRec84[1] = fRec84[0];
			fRec92[1] = fRec92[0];
			fRec90[1] = fRec90[0];
			fRec89[1] = fRec89[0];
			fRec87[1] = fRec87[0];
			fRec101[1] = fRec101[0];
			fRec99[1] = fRec99[0];
			fRec98[1] = fRec98[0];
			fRec96[1] = fRec96[0];
			fRec95[1] = fRec95[0];
			fRec93[1] = fRec93[0];
			fRec113[1] = fRec113[0];
			fRec111[1] = fRec111[0];
			fRec110[1] = fRec110[0];
			fRec108[1] = fRec108[0];
			fRec107[1] = fRec107[0];
			fRec105[1] = fRec105[0];
			fRec104[1] = fRec104[0];
			fRec102[1] = fRec102[0];
			fRec128[1] = fRec128[0];
			fRec126[1] = fRec126[0];
			fRec125[1] = fRec125[0];
			fRec123[1] = fRec123[0];
			fRec122[1] = fRec122[0];
			fRec120[1] = fRec120[0];
			fRec119[1] = fRec119[0];
			fRec117[1] = fRec117[0];
			fRec116[1] = fRec116[0];
			fRec114[1] = fRec114[0];
			fRec131[1] = fRec131[0];
			fRec129[1] = fRec129[0];
			fRec137[1] = fRec137[0];
			fRec135[1] = fRec135[0];
			fRec134[1] = fRec134[0];
			fRec132[1] = fRec132[0];
			fRec146[1] = fRec146[0];
			fRec144[1] = fRec144[0];
			fRec143[1] = fRec143[0];
			fRec141[1] = fRec141[0];
			fRec140[1] = fRec140[0];
			fRec138[1] = fRec138[0];
			fRec158[1] = fRec158[0];
			fRec156[1] = fRec156[0];
			fRec155[1] = fRec155[0];
			fRec153[1] = fRec153[0];
			fRec152[1] = fRec152[0];
			fRec150[1] = fRec150[0];
			fRec149[1] = fRec149[0];
			fRec147[1] = fRec147[0];
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
			fRec203[1] = fRec203[0];
			fRec201[1] = fRec201[0];
			fRec209[1] = fRec209[0];
			fRec207[1] = fRec207[0];
			fRec206[1] = fRec206[0];
			fRec204[1] = fRec204[0];
			fRec218[1] = fRec218[0];
			fRec216[1] = fRec216[0];
			fRec215[1] = fRec215[0];
			fRec213[1] = fRec213[0];
			fRec212[1] = fRec212[0];
			fRec210[1] = fRec210[0];
			fRec230[1] = fRec230[0];
			fRec228[1] = fRec228[0];
			fRec227[1] = fRec227[0];
			fRec225[1] = fRec225[0];
			fRec224[1] = fRec224[0];
			fRec222[1] = fRec222[0];
			fRec221[1] = fRec221[0];
			fRec219[1] = fRec219[0];
			fRec239[1] = fRec239[0];
			fRec237[1] = fRec237[0];
			fRec236[1] = fRec236[0];
			fRec234[1] = fRec234[0];
			fRec233[1] = fRec233[0];
			fRec231[1] = fRec231[0];
			fRec245[1] = fRec245[0];
			fRec243[1] = fRec243[0];
			fRec242[1] = fRec242[0];
			fRec240[1] = fRec240[0];
			fRec260[1] = fRec260[0];
			fRec258[1] = fRec258[0];
			fRec257[1] = fRec257[0];
			fRec255[1] = fRec255[0];
			fRec254[1] = fRec254[0];
			fRec252[1] = fRec252[0];
			fRec251[1] = fRec251[0];
			fRec249[1] = fRec249[0];
			fRec248[1] = fRec248[0];
			fRec246[1] = fRec246[0];
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
			fRec266[1] = fRec266[0];
			fRec264[1] = fRec264[0];
			fRec290[1] = fRec290[0];
			fRec288[1] = fRec288[0];
			fRec287[1] = fRec287[0];
			fRec285[1] = fRec285[0];
			fRec284[1] = fRec284[0];
			fRec282[1] = fRec282[0];
			fRec281[1] = fRec281[0];
			fRec279[1] = fRec279[0];
			fRec299[1] = fRec299[0];
			fRec297[1] = fRec297[0];
			fRec296[1] = fRec296[0];
			fRec294[1] = fRec294[0];
			fRec293[1] = fRec293[0];
			fRec291[1] = fRec291[0];
			fRec302[1] = fRec302[0];
			fRec300[1] = fRec300[0];
			fRec308[1] = fRec308[0];
			fRec306[1] = fRec306[0];
			fRec305[1] = fRec305[0];
			fRec303[1] = fRec303[0];
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
			fRec518[1] = fRec518[0];
			fRec516[1] = fRec516[0];
			fRec524[1] = fRec524[0];
			fRec522[1] = fRec522[0];
			fRec521[1] = fRec521[0];
			fRec519[1] = fRec519[0];
			fRec533[1] = fRec533[0];
			fRec531[1] = fRec531[0];
			fRec530[1] = fRec530[0];
			fRec528[1] = fRec528[0];
			fRec527[1] = fRec527[0];
			fRec525[1] = fRec525[0];
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
