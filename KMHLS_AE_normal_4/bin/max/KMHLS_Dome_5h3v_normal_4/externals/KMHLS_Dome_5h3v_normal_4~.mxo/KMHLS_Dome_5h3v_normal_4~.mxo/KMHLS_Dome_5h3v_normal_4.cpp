/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMHLS_Dome_5h3v_normal_4"
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
	FAUSTFLOAT fHslider1;
	double fRec11[2];
	double fRec10[3];
	FAUSTFLOAT fHslider2;
	double fRec12[2];
	double fRec13[3];
	double fRec14[3];
	double fRec15[3];
	double fRec16[3];
	double fRec17[3];
	double fRec18[3];
	double fConst7;
	double fConst8;
	double fConst9;
	double fRec9[2];
	double fRec7[2];
	double fRec6[2];
	double fRec4[2];
	double fRec3[2];
	double fRec1[2];
	double fConst10;
	double fConst11;
	double fRec25[3];
	double fRec26[3];
	double fRec27[3];
	double fRec28[3];
	double fRec29[3];
	double fConst12;
	double fConst13;
	double fRec24[2];
	double fRec22[2];
	double fRec21[2];
	double fRec19[2];
	double fConst14;
	double fConst15;
	double fRec33[3];
	double fRec34[3];
	double fRec35[3];
	double fConst16;
	double fRec32[2];
	double fRec30[2];
	double fConst17;
	double fConst18;
	double fConst19;
	double fRec48[3];
	double fRec49[3];
	double fRec50[3];
	double fRec51[3];
	double fRec52[3];
	double fRec53[3];
	double fRec54[3];
	double fRec55[3];
	double fConst20;
	double fConst21;
	double fRec47[2];
	double fRec45[2];
	double fRec44[2];
	double fRec42[2];
	double fConst22;
	double fConst23;
	double fRec41[2];
	double fRec39[2];
	double fRec38[2];
	double fRec36[2];
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fConst28;
	double fConst29;
	double fConst30;
	double fRec71[3];
	double fRec72[3];
	double fRec73[3];
	double fRec74[3];
	double fRec75[3];
	double fRec76[3];
	double fRec77[3];
	double fRec78[3];
	double fConst31;
	double fConst32;
	double fRec70[2];
	double fRec68[2];
	double fRec67[2];
	double fRec65[2];
	double fRec64[2];
	double fRec62[2];
	double fRec61[2];
	double fRec59[2];
	double fRec58[2];
	double fRec56[2];
	double fRec79[3];
	int IOTA;
	double fVec0[1024];
	int iConst33;
	double fRec94[2];
	double fRec92[2];
	double fRec91[2];
	double fRec89[2];
	double fRec88[2];
	double fRec86[2];
	double fRec85[2];
	double fRec83[2];
	double fRec82[2];
	double fRec80[2];
	double fRec106[2];
	double fRec104[2];
	double fRec103[2];
	double fRec101[2];
	double fRec100[2];
	double fRec98[2];
	double fRec97[2];
	double fRec95[2];
	double fRec115[2];
	double fRec113[2];
	double fRec112[2];
	double fRec110[2];
	double fRec109[2];
	double fRec107[2];
	double fRec118[2];
	double fRec116[2];
	double fRec124[2];
	double fRec122[2];
	double fRec121[2];
	double fRec119[2];
	double fVec1[1024];
	double fRec139[2];
	double fRec137[2];
	double fRec136[2];
	double fRec134[2];
	double fRec133[2];
	double fRec131[2];
	double fRec130[2];
	double fRec128[2];
	double fRec127[2];
	double fRec125[2];
	double fRec151[2];
	double fRec149[2];
	double fRec148[2];
	double fRec146[2];
	double fRec145[2];
	double fRec143[2];
	double fRec142[2];
	double fRec140[2];
	double fRec160[2];
	double fRec158[2];
	double fRec157[2];
	double fRec155[2];
	double fRec154[2];
	double fRec152[2];
	double fRec163[2];
	double fRec161[2];
	double fRec169[2];
	double fRec167[2];
	double fRec166[2];
	double fRec164[2];
	double fVec2[1024];
	double fRec184[2];
	double fRec182[2];
	double fRec181[2];
	double fRec179[2];
	double fRec178[2];
	double fRec176[2];
	double fRec175[2];
	double fRec173[2];
	double fRec172[2];
	double fRec170[2];
	double fRec196[2];
	double fRec194[2];
	double fRec193[2];
	double fRec191[2];
	double fRec190[2];
	double fRec188[2];
	double fRec187[2];
	double fRec185[2];
	double fRec205[2];
	double fRec203[2];
	double fRec202[2];
	double fRec200[2];
	double fRec199[2];
	double fRec197[2];
	double fRec208[2];
	double fRec206[2];
	double fRec214[2];
	double fRec212[2];
	double fRec211[2];
	double fRec209[2];
	double fVec3[1024];
	double fRec229[2];
	double fRec227[2];
	double fRec226[2];
	double fRec224[2];
	double fRec223[2];
	double fRec221[2];
	double fRec220[2];
	double fRec218[2];
	double fRec217[2];
	double fRec215[2];
	double fRec241[2];
	double fRec239[2];
	double fRec238[2];
	double fRec236[2];
	double fRec235[2];
	double fRec233[2];
	double fRec232[2];
	double fRec230[2];
	double fRec250[2];
	double fRec248[2];
	double fRec247[2];
	double fRec245[2];
	double fRec244[2];
	double fRec242[2];
	double fRec253[2];
	double fRec251[2];
	double fRec259[2];
	double fRec257[2];
	double fRec256[2];
	double fRec254[2];
	double fVec4[1024];
	double fRec274[2];
	double fRec272[2];
	double fRec271[2];
	double fRec269[2];
	double fRec268[2];
	double fRec266[2];
	double fRec265[2];
	double fRec263[2];
	double fRec262[2];
	double fRec260[2];
	double fRec286[2];
	double fRec284[2];
	double fRec283[2];
	double fRec281[2];
	double fRec280[2];
	double fRec278[2];
	double fRec277[2];
	double fRec275[2];
	double fRec295[2];
	double fRec293[2];
	double fRec292[2];
	double fRec290[2];
	double fRec289[2];
	double fRec287[2];
	double fRec298[2];
	double fRec296[2];
	double fRec304[2];
	double fRec302[2];
	double fRec301[2];
	double fRec299[2];
	double fVec5[1024];
	double fRec319[2];
	double fRec317[2];
	double fRec316[2];
	double fRec314[2];
	double fRec313[2];
	double fRec311[2];
	double fRec310[2];
	double fRec308[2];
	double fRec307[2];
	double fRec305[2];
	double fRec331[2];
	double fRec329[2];
	double fRec328[2];
	double fRec326[2];
	double fRec325[2];
	double fRec323[2];
	double fRec322[2];
	double fRec320[2];
	double fRec340[2];
	double fRec338[2];
	double fRec337[2];
	double fRec335[2];
	double fRec334[2];
	double fRec332[2];
	double fRec343[2];
	double fRec341[2];
	double fRec349[2];
	double fRec347[2];
	double fRec346[2];
	double fRec344[2];
	double fVec6[1024];
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
	double fRec376[2];
	double fRec374[2];
	double fRec373[2];
	double fRec371[2];
	double fRec370[2];
	double fRec368[2];
	double fRec367[2];
	double fRec365[2];
	double fRec385[2];
	double fRec383[2];
	double fRec382[2];
	double fRec380[2];
	double fRec379[2];
	double fRec377[2];
	double fRec388[2];
	double fRec386[2];
	double fRec394[2];
	double fRec392[2];
	double fRec391[2];
	double fRec389[2];
	double fVec7[1024];
	double fRec409[2];
	double fRec407[2];
	double fRec406[2];
	double fRec404[2];
	double fRec403[2];
	double fRec401[2];
	double fRec400[2];
	double fRec398[2];
	double fRec397[2];
	double fRec395[2];
	double fRec421[2];
	double fRec419[2];
	double fRec418[2];
	double fRec416[2];
	double fRec415[2];
	double fRec413[2];
	double fRec412[2];
	double fRec410[2];
	double fRec430[2];
	double fRec428[2];
	double fRec427[2];
	double fRec425[2];
	double fRec424[2];
	double fRec422[2];
	double fRec433[2];
	double fRec431[2];
	double fRec439[2];
	double fRec437[2];
	double fRec436[2];
	double fRec434[2];
	double fVec8[1024];
	double fRec451[2];
	double fRec449[2];
	double fRec448[2];
	double fRec446[2];
	double fRec445[2];
	double fRec443[2];
	double fRec442[2];
	double fRec440[2];
	double fRec460[2];
	double fRec458[2];
	double fRec457[2];
	double fRec455[2];
	double fRec454[2];
	double fRec452[2];
	double fRec466[2];
	double fRec464[2];
	double fRec463[2];
	double fRec461[2];
	double fRec481[2];
	double fRec479[2];
	double fRec478[2];
	double fRec476[2];
	double fRec475[2];
	double fRec473[2];
	double fRec472[2];
	double fRec470[2];
	double fRec469[2];
	double fRec467[2];
	double fRec484[2];
	double fRec482[2];
	double fVec9[1024];
	double fRec499[2];
	double fRec497[2];
	double fRec496[2];
	double fRec494[2];
	double fRec493[2];
	double fRec491[2];
	double fRec490[2];
	double fRec488[2];
	double fRec487[2];
	double fRec485[2];
	double fRec511[2];
	double fRec509[2];
	double fRec508[2];
	double fRec506[2];
	double fRec505[2];
	double fRec503[2];
	double fRec502[2];
	double fRec500[2];
	double fRec520[2];
	double fRec518[2];
	double fRec517[2];
	double fRec515[2];
	double fRec514[2];
	double fRec512[2];
	double fRec523[2];
	double fRec521[2];
	double fRec529[2];
	double fRec527[2];
	double fRec526[2];
	double fRec524[2];
	double fVec10[1024];
	double fRec544[2];
	double fRec542[2];
	double fRec541[2];
	double fRec539[2];
	double fRec538[2];
	double fRec536[2];
	double fRec535[2];
	double fRec533[2];
	double fRec532[2];
	double fRec530[2];
	double fRec553[2];
	double fRec551[2];
	double fRec550[2];
	double fRec548[2];
	double fRec547[2];
	double fRec545[2];
	double fRec559[2];
	double fRec557[2];
	double fRec556[2];
	double fRec554[2];
	double fRec571[2];
	double fRec569[2];
	double fRec568[2];
	double fRec566[2];
	double fRec565[2];
	double fRec563[2];
	double fRec562[2];
	double fRec560[2];
	double fRec574[2];
	double fRec572[2];
	double fVec11[1024];
	double fRec577[2];
	double fRec575[2];
	double fRec592[2];
	double fRec590[2];
	double fRec589[2];
	double fRec587[2];
	double fRec586[2];
	double fRec584[2];
	double fRec583[2];
	double fRec581[2];
	double fRec580[2];
	double fRec578[2];
	double fRec604[2];
	double fRec602[2];
	double fRec601[2];
	double fRec599[2];
	double fRec598[2];
	double fRec596[2];
	double fRec595[2];
	double fRec593[2];
	double fRec610[2];
	double fRec608[2];
	double fRec607[2];
	double fRec605[2];
	double fRec619[2];
	double fRec617[2];
	double fRec616[2];
	double fRec614[2];
	double fRec613[2];
	double fRec611[2];
	double fVec12[1024];
	double fRec634[2];
	double fRec632[2];
	double fRec631[2];
	double fRec629[2];
	double fRec628[2];
	double fRec626[2];
	double fRec625[2];
	double fRec623[2];
	double fRec622[2];
	double fRec620[2];
	double fRec646[2];
	double fRec644[2];
	double fRec643[2];
	double fRec641[2];
	double fRec640[2];
	double fRec638[2];
	double fRec637[2];
	double fRec635[2];
	double fRec655[2];
	double fRec653[2];
	double fRec652[2];
	double fRec650[2];
	double fRec649[2];
	double fRec647[2];
	double fRec658[2];
	double fRec656[2];
	double fRec664[2];
	double fRec662[2];
	double fRec661[2];
	double fRec659[2];
	double fVec13[1024];
	double fRec676[2];
	double fRec674[2];
	double fRec673[2];
	double fRec671[2];
	double fRec670[2];
	double fRec668[2];
	double fRec667[2];
	double fRec665[2];
	double fRec685[2];
	double fRec683[2];
	double fRec682[2];
	double fRec680[2];
	double fRec679[2];
	double fRec677[2];
	double fRec691[2];
	double fRec689[2];
	double fRec688[2];
	double fRec686[2];
	double fRec706[2];
	double fRec704[2];
	double fRec703[2];
	double fRec701[2];
	double fRec700[2];
	double fRec698[2];
	double fRec697[2];
	double fRec695[2];
	double fRec694[2];
	double fRec692[2];
	double fRec709[2];
	double fRec707[2];
	double fVec14[1024];
	double fRec724[2];
	double fRec722[2];
	double fRec721[2];
	double fRec719[2];
	double fRec718[2];
	double fRec716[2];
	double fRec715[2];
	double fRec713[2];
	double fRec712[2];
	double fRec710[2];
	double fRec736[2];
	double fRec734[2];
	double fRec733[2];
	double fRec731[2];
	double fRec730[2];
	double fRec728[2];
	double fRec727[2];
	double fRec725[2];
	double fRec745[2];
	double fRec743[2];
	double fRec742[2];
	double fRec740[2];
	double fRec739[2];
	double fRec737[2];
	double fRec748[2];
	double fRec746[2];
	double fRec754[2];
	double fRec752[2];
	double fRec751[2];
	double fRec749[2];
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
	double fRec769[2];
	double fRec767[2];
	double fRec766[2];
	double fRec764[2];
	double fRec763[2];
	double fRec761[2];
	double fRec760[2];
	double fRec758[2];
	double fRec757[2];
	double fRec755[2];
	double fConst43;
	double fConst44;
	double fConst45;
	double fConst46;
	double fConst47;
	double fConst48;
	double fConst49;
	double fRec781[2];
	double fRec779[2];
	double fRec778[2];
	double fRec776[2];
	double fRec775[2];
	double fRec773[2];
	double fRec772[2];
	double fRec770[2];
	double fConst50;
	double fConst51;
	double fConst52;
	double fConst53;
	double fConst54;
	double fConst55;
	double fRec790[2];
	double fRec788[2];
	double fRec787[2];
	double fRec785[2];
	double fRec784[2];
	double fRec782[2];
	double fConst56;
	double fConst57;
	double fConst58;
	double fRec793[2];
	double fRec791[2];
	double fConst59;
	double fConst60;
	double fConst61;
	double fConst62;
	double fRec799[2];
	double fRec797[2];
	double fRec796[2];
	double fRec794[2];
	double fVec16[2];
	int iConst63;
	double fRec814[2];
	double fRec812[2];
	double fRec811[2];
	double fRec809[2];
	double fRec808[2];
	double fRec806[2];
	double fRec805[2];
	double fRec803[2];
	double fRec802[2];
	double fRec800[2];
	double fRec826[2];
	double fRec824[2];
	double fRec823[2];
	double fRec821[2];
	double fRec820[2];
	double fRec818[2];
	double fRec817[2];
	double fRec815[2];
	double fRec835[2];
	double fRec833[2];
	double fRec832[2];
	double fRec830[2];
	double fRec829[2];
	double fRec827[2];
	double fRec838[2];
	double fRec836[2];
	double fRec844[2];
	double fRec842[2];
	double fRec841[2];
	double fRec839[2];
	double fVec17[2];
	double fRec859[2];
	double fRec857[2];
	double fRec856[2];
	double fRec854[2];
	double fRec853[2];
	double fRec851[2];
	double fRec850[2];
	double fRec848[2];
	double fRec847[2];
	double fRec845[2];
	double fRec871[2];
	double fRec869[2];
	double fRec868[2];
	double fRec866[2];
	double fRec865[2];
	double fRec863[2];
	double fRec862[2];
	double fRec860[2];
	double fRec880[2];
	double fRec878[2];
	double fRec877[2];
	double fRec875[2];
	double fRec874[2];
	double fRec872[2];
	double fRec883[2];
	double fRec881[2];
	double fRec889[2];
	double fRec887[2];
	double fRec886[2];
	double fRec884[2];
	double fVec18[2];
	double fRec904[2];
	double fRec902[2];
	double fRec901[2];
	double fRec899[2];
	double fRec898[2];
	double fRec896[2];
	double fRec895[2];
	double fRec893[2];
	double fRec892[2];
	double fRec890[2];
	double fRec916[2];
	double fRec914[2];
	double fRec913[2];
	double fRec911[2];
	double fRec910[2];
	double fRec908[2];
	double fRec907[2];
	double fRec905[2];
	double fRec925[2];
	double fRec923[2];
	double fRec922[2];
	double fRec920[2];
	double fRec919[2];
	double fRec917[2];
	double fRec928[2];
	double fRec926[2];
	double fRec934[2];
	double fRec932[2];
	double fRec931[2];
	double fRec929[2];
	double fVec19[2];
	double fRec940[2];
	double fRec938[2];
	double fRec937[2];
	double fRec935[2];
	double fRec943[2];
	double fRec941[2];
	double fRec958[2];
	double fRec956[2];
	double fRec955[2];
	double fRec953[2];
	double fRec952[2];
	double fRec950[2];
	double fRec949[2];
	double fRec947[2];
	double fRec946[2];
	double fRec944[2];
	double fRec970[2];
	double fRec968[2];
	double fRec967[2];
	double fRec965[2];
	double fRec964[2];
	double fRec962[2];
	double fRec961[2];
	double fRec959[2];
	double fRec979[2];
	double fRec977[2];
	double fRec976[2];
	double fRec974[2];
	double fRec973[2];
	double fRec971[2];
	double fVec20[2];
	double fRec994[2];
	double fRec992[2];
	double fRec991[2];
	double fRec989[2];
	double fRec988[2];
	double fRec986[2];
	double fRec985[2];
	double fRec983[2];
	double fRec982[2];
	double fRec980[2];
	double fRec1006[2];
	double fRec1004[2];
	double fRec1003[2];
	double fRec1001[2];
	double fRec1000[2];
	double fRec998[2];
	double fRec997[2];
	double fRec995[2];
	double fRec1015[2];
	double fRec1013[2];
	double fRec1012[2];
	double fRec1010[2];
	double fRec1009[2];
	double fRec1007[2];
	double fRec1018[2];
	double fRec1016[2];
	double fRec1024[2];
	double fRec1022[2];
	double fRec1021[2];
	double fRec1019[2];
	double fVec21[2];
	double fRec1036[2];
	double fRec1034[2];
	double fRec1033[2];
	double fRec1031[2];
	double fRec1030[2];
	double fRec1028[2];
	double fRec1027[2];
	double fRec1025[2];
	double fRec1045[2];
	double fRec1043[2];
	double fRec1042[2];
	double fRec1040[2];
	double fRec1039[2];
	double fRec1037[2];
	double fRec1051[2];
	double fRec1049[2];
	double fRec1048[2];
	double fRec1046[2];
	double fRec1066[2];
	double fRec1064[2];
	double fRec1063[2];
	double fRec1061[2];
	double fRec1060[2];
	double fRec1058[2];
	double fRec1057[2];
	double fRec1055[2];
	double fRec1054[2];
	double fRec1052[2];
	double fRec1069[2];
	double fRec1067[2];
	double fVec22[2];
	double fRec1084[2];
	double fRec1082[2];
	double fRec1081[2];
	double fRec1079[2];
	double fRec1078[2];
	double fRec1076[2];
	double fRec1075[2];
	double fRec1073[2];
	double fRec1072[2];
	double fRec1070[2];
	double fRec1093[2];
	double fRec1091[2];
	double fRec1090[2];
	double fRec1088[2];
	double fRec1087[2];
	double fRec1085[2];
	double fRec1096[2];
	double fRec1094[2];
	double fRec1102[2];
	double fRec1100[2];
	double fRec1099[2];
	double fRec1097[2];
	double fRec1114[2];
	double fRec1112[2];
	double fRec1111[2];
	double fRec1109[2];
	double fRec1108[2];
	double fRec1106[2];
	double fRec1105[2];
	double fRec1103[2];
	double fVec23[2];
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fConst68;
	double fConst69;
	double fRec1129[2];
	double fRec1127[2];
	double fRec1126[2];
	double fRec1124[2];
	double fConst70;
	double fConst71;
	double fRec1123[2];
	double fRec1121[2];
	double fRec1120[2];
	double fRec1118[2];
	double fConst72;
	double fRec1117[2];
	double fRec1115[2];
	double fConst73;
	double fConst74;
	double fConst75;
	double fConst76;
	double fConst77;
	double fConst78;
	double fConst79;
	double fRec1141[2];
	double fRec1139[2];
	double fRec1138[2];
	double fRec1136[2];
	double fRec1135[2];
	double fRec1133[2];
	double fRec1132[2];
	double fRec1130[2];
	double fConst80;
	double fConst81;
	double fConst82;
	double fConst83;
	double fConst84;
	double fConst85;
	double fRec1150[2];
	double fRec1148[2];
	double fRec1147[2];
	double fRec1145[2];
	double fRec1144[2];
	double fRec1142[2];
	double fConst86;
	double fConst87;
	double fConst88;
	double fRec1153[2];
	double fRec1151[2];
	double fConst89;
	double fConst90;
	double fConst91;
	double fConst92;
	double fRec1159[2];
	double fRec1157[2];
	double fRec1156[2];
	double fRec1154[2];
	double fVec24[512];
	int iConst93;
	double fRec1174[2];
	double fRec1172[2];
	double fRec1171[2];
	double fRec1169[2];
	double fRec1168[2];
	double fRec1166[2];
	double fRec1165[2];
	double fRec1163[2];
	double fRec1162[2];
	double fRec1160[2];
	double fRec1177[2];
	double fRec1175[2];
	double fRec1183[2];
	double fRec1181[2];
	double fRec1180[2];
	double fRec1178[2];
	double fRec1192[2];
	double fRec1190[2];
	double fRec1189[2];
	double fRec1187[2];
	double fRec1186[2];
	double fRec1184[2];
	double fRec1204[2];
	double fRec1202[2];
	double fRec1201[2];
	double fRec1199[2];
	double fRec1198[2];
	double fRec1196[2];
	double fRec1195[2];
	double fRec1193[2];
	double fVec25[512];
	double fRec1216[2];
	double fRec1214[2];
	double fRec1213[2];
	double fRec1211[2];
	double fRec1210[2];
	double fRec1208[2];
	double fRec1207[2];
	double fRec1205[2];
	double fRec1225[2];
	double fRec1223[2];
	double fRec1222[2];
	double fRec1220[2];
	double fRec1219[2];
	double fRec1217[2];
	double fRec1228[2];
	double fRec1226[2];
	double fRec1234[2];
	double fRec1232[2];
	double fRec1231[2];
	double fRec1229[2];
	double fRec1249[2];
	double fRec1247[2];
	double fRec1246[2];
	double fRec1244[2];
	double fRec1243[2];
	double fRec1241[2];
	double fRec1240[2];
	double fRec1238[2];
	double fRec1237[2];
	double fRec1235[2];
	double fVec26[512];
	double fRec1252[2];
	double fRec1250[2];
	double fRec1258[2];
	double fRec1256[2];
	double fRec1255[2];
	double fRec1253[2];
	double fRec1267[2];
	double fRec1265[2];
	double fRec1264[2];
	double fRec1262[2];
	double fRec1261[2];
	double fRec1259[2];
	double fRec1279[2];
	double fRec1277[2];
	double fRec1276[2];
	double fRec1274[2];
	double fRec1273[2];
	double fRec1271[2];
	double fRec1270[2];
	double fRec1268[2];
	double fRec1294[2];
	double fRec1292[2];
	double fRec1291[2];
	double fRec1289[2];
	double fRec1288[2];
	double fRec1286[2];
	double fRec1285[2];
	double fRec1283[2];
	double fRec1282[2];
	double fRec1280[2];
	double fVec27[512];
	double fConst94;
	double fConst95;
	double fConst96;
	double fRec1297[2];
	double fRec1295[2];
	double fConst97;
	double fConst98;
	double fConst99;
	double fConst100;
	double fRec1303[2];
	double fRec1301[2];
	double fRec1300[2];
	double fRec1298[2];
	double fConst101;
	double fConst102;
	double fConst103;
	double fConst104;
	double fConst105;
	double fConst106;
	double fRec1312[2];
	double fRec1310[2];
	double fRec1309[2];
	double fRec1307[2];
	double fRec1306[2];
	double fRec1304[2];
	double fConst107;
	double fConst108;
	double fConst109;
	double fConst110;
	double fConst111;
	double fConst112;
	double fConst113;
	double fRec1324[2];
	double fRec1322[2];
	double fRec1321[2];
	double fRec1319[2];
	double fRec1318[2];
	double fRec1316[2];
	double fRec1315[2];
	double fRec1313[2];
	double fConst114;
	double fConst115;
	double fConst116;
	double fConst117;
	double fConst118;
	double fConst119;
	double fConst120;
	double fConst121;
	double fConst122;
	double fRec1339[2];
	double fRec1337[2];
	double fRec1336[2];
	double fRec1334[2];
	double fRec1333[2];
	double fRec1331[2];
	double fRec1330[2];
	double fRec1328[2];
	double fRec1327[2];
	double fRec1325[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMHLS_Dome_5h3v_normal_4");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMHLS_Dome_5h3v_normal_4");
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
				rate = 0;
				break;
			}
			case 30: {
				rate = 0;
				break;
			}
			case 31: {
				rate = 0;
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
		fConst2 = ((87.085661089049111 / fConst1) + 1.0);
		fConst3 = (0.0 - (174.17132217809822 / (fConst1 * fConst2)));
		fConst4 = ((((9084.3512875420056 / fConst1) + 137.92392545983725) / fConst1) + 1.0);
		fConst5 = (1.0 / (fConst2 * fConst4));
		fConst6 = (3.1415926535897931 / double(iConst0));
		fConst7 = mydsp_faustpower2_f(fConst1);
		fConst8 = (0.0 - (36337.405150168022 / (fConst7 * fConst4)));
		fConst9 = (0.0 - (((36337.405150168022 / fConst1) + 275.8478509196745) / (fConst1 * fConst4)));
		fConst10 = ((((4219.1095032417315 / fConst1) + 112.50479327444317) / fConst1) + 1.0);
		fConst11 = (1.0 / fConst10);
		fConst12 = (0.0 - (((16876.438012966926 / fConst1) + 225.00958654888635) / (fConst1 * fConst10)));
		fConst13 = (0.0 - (16876.438012966926 / (fConst7 * fConst10)));
		fConst14 = ((37.501597758147724 / fConst1) + 1.0);
		fConst15 = (1.0 / fConst14);
		fConst16 = (0.0 - (75.003195516295449 / (fConst1 * fConst14)));
		fConst17 = ((((12854.404366681647 / fConst1) + 217.22505009970442) / fConst1) + 1.0);
		fConst18 = ((((16156.096054437347 / fConst1) + 157.79092748177277) / fConst1) + 1.0);
		fConst19 = (1.0 / (fConst17 * fConst18));
		fConst20 = (0.0 - (64624.384217749386 / (fConst7 * fConst18)));
		fConst21 = (0.0 - (((64624.384217749386 / fConst1) + 315.58185496354554) / (fConst1 * fConst18)));
		fConst22 = (0.0 - (51417.617466726588 / (fConst7 * fConst17)));
		fConst23 = (0.0 - (((51417.617466726588 / fConst1) + 434.45010019940884) / (fConst1 * fConst17)));
		fConst24 = ((136.75852393116773 / fConst1) + 1.0);
		fConst25 = (0.0 - (273.51704786233546 / (fConst1 * fConst24)));
		fConst26 = ((((20072.386056136751 / fConst1) + 251.40744116780635) / fConst1) + 1.0);
		fConst27 = (0.0 - (80289.544224547004 / (fConst7 * fConst26)));
		fConst28 = (0.0 - (((80289.544224547004 / fConst1) + 502.81488233561271) / (fConst1 * fConst26)));
		fConst29 = ((((25534.494160946691 / fConst1) + 174.35800127324134) / fConst1) + 1.0);
		fConst30 = (1.0 / ((fConst24 * fConst26) * fConst29));
		fConst31 = (0.0 - (102137.97664378677 / (fConst7 * fConst29)));
		fConst32 = (0.0 - (((102137.97664378677 / fConst1) + 348.71600254648268) / (fConst1 * fConst29)));
		iConst33 = int(((0.002913628773109936 * double(iConst0)) + 0.5));
		fConst34 = ((112.25237766978 / fConst1) + 1.0);
		fConst35 = (0.0 - (224.50475533956001 / (fConst1 * fConst34)));
		fConst36 = ((((13523.256620516057 / fConst1) + 206.35703153074112) / fConst1) + 1.0);
		fConst37 = (0.0 - (54093.026482064226 / (fConst7 * fConst36)));
		fConst38 = (0.0 - (((54093.026482064226 / fConst1) + 412.71406306148225) / (fConst1 * fConst36)));
		fConst39 = ((((17203.21222637999 / fConst1) + 143.11429844418876) / fConst1) + 1.0);
		fConst40 = (1.0 / ((fConst34 * fConst36) * fConst39));
		fConst41 = (0.0 - (68812.848905519961 / (fConst7 * fConst39)));
		fConst42 = (0.0 - (((68812.848905519961 / fConst1) + 286.22859688837752) / (fConst1 * fConst39)));
		fConst43 = ((((8660.3261051454228 / fConst1) + 178.29987968721923) / fConst1) + 1.0);
		fConst44 = (0.0 - (34641.304420581691 / (fConst7 * fConst43)));
		fConst45 = (0.0 - (((34641.304420581691 / fConst1) + 356.59975937443846) / (fConst1 * fConst43)));
		fConst46 = ((((10884.756417041221 / fConst1) + 129.51592540925418) / fConst1) + 1.0);
		fConst47 = (1.0 / (fConst43 * fConst46));
		fConst48 = (0.0 - (43539.025668164883 / (fConst7 * fConst46)));
		fConst49 = (0.0 - (((43539.025668164883 / fConst1) + 259.03185081850836) / (fConst1 * fConst46)));
		fConst50 = ((71.480535451746846 / fConst1) + 1.0);
		fConst51 = (0.0 - (142.96107090349369 / (fConst1 * fConst50)));
		fConst52 = ((((6120.3492872630823 / fConst1) + 113.20894760613724) / fConst1) + 1.0);
		fConst53 = (1.0 / (fConst50 * fConst52));
		fConst54 = (0.0 - (24481.397149052329 / (fConst7 * fConst52)));
		fConst55 = (0.0 - (((24481.397149052329 / fConst1) + 226.41789521227449) / (fConst1 * fConst52)));
		fConst56 = ((30.781580509647348 / fConst1) + 1.0);
		fConst57 = (1.0 / fConst56);
		fConst58 = (0.0 - (61.563161019294697 / (fConst1 * fConst56)));
		fConst59 = ((((2842.5170960157047 / fConst1) + 92.344741528942052) / fConst1) + 1.0);
		fConst60 = (1.0 / fConst59);
		fConst61 = (0.0 - (11370.068384062819 / (fConst7 * fConst59)));
		fConst62 = (0.0 - (((11370.068384062819 / fConst1) + 184.6894830578841) / (fConst1 * fConst59)));
		iConst63 = int(((2.9136287731083211e-06 * double(iConst0)) + 0.5));
		fConst64 = ((((20678.421137748988 / fConst1) + 156.90505679967598) / fConst1) + 1.0);
		fConst65 = ((123.06922428889351 / fConst1) + 1.0);
		fConst66 = ((((16255.080264839977 / fConst1) + 226.24197655533564) / fConst1) + 1.0);
		fConst67 = (1.0 / ((fConst64 * fConst65) * fConst66));
		fConst68 = (0.0 - (82713.684550995953 / (fConst64 * fConst7)));
		fConst69 = (0.0 - (((82713.684550995953 / fConst1) + 313.81011359935195) / (fConst64 * fConst1)));
		fConst70 = (0.0 - (((65020.321059359907 / fConst1) + 452.48395311067128) / (fConst1 * fConst66)));
		fConst71 = (0.0 - (65020.321059359907 / (fConst7 * fConst66)));
		fConst72 = (0.0 - (246.13844857778702 / (fConst1 * fConst65)));
		fConst73 = ((((10409.79254547754 / fConst1) + 195.48118569444392) / fConst1) + 1.0);
		fConst74 = (0.0 - (41639.170181910158 / (fConst7 * fConst73)));
		fConst75 = (0.0 - (((41639.170181910158 / fConst1) + 390.96237138888785) / (fConst1 * fConst73)));
		fConst76 = ((((13083.578474271766 / fConst1) + 141.99631940149303) / fConst1) + 1.0);
		fConst77 = (1.0 / (fConst73 * fConst76));
		fConst78 = (0.0 - (52334.313897087064 / (fConst7 * fConst76)));
		fConst79 = (0.0 - (((52334.313897087064 / fConst1) + 283.99263880298605) / (fConst1 * fConst76)));
		fConst80 = ((78.36853198495352 / fConst1) + 1.0);
		fConst81 = (0.0 - (156.73706396990704 / (fConst1 * fConst80)));
		fConst82 = ((((7356.7167809554639 / fConst1) + 124.11797107260868) / fConst1) + 1.0);
		fConst83 = (1.0 / (fConst80 * fConst82));
		fConst84 = (0.0 - (29426.867123821856 / (fConst7 * fConst82)));
		fConst85 = (0.0 - (((29426.867123821856 / fConst1) + 248.23594214521736) / (fConst1 * fConst82)));
		fConst86 = ((33.7477505095937 / fConst1) + 1.0);
		fConst87 = (1.0 / fConst86);
		fConst88 = (0.0 - (67.495501019187401 / (fConst86 * fConst1)));
		fConst89 = ((((3416.7319933733456 / fConst1) + 101.2432515287811) / fConst1) + 1.0);
		fConst90 = (1.0 / fConst89);
		fConst91 = (0.0 - (13666.927973493383 / (fConst7 * fConst89)));
		fConst92 = (0.0 - (((13666.927973493383 / fConst1) + 202.4865030575622) / (fConst1 * fConst89)));
		iConst93 = int(((0.0014305917275969774 * double(iConst0)) + 0.5));
		fConst94 = ((30.776060140115494 / fConst1) + 1.0);
		fConst95 = (1.0 / fConst94);
		fConst96 = (0.0 - (61.552120280230987 / (fConst1 * fConst94)));
		fConst97 = ((((2841.4976332440169 / fConst1) + 92.328180420346484) / fConst1) + 1.0);
		fConst98 = (1.0 / fConst97);
		fConst99 = (0.0 - (11365.990532976068 / (fConst7 * fConst97)));
		fConst100 = (0.0 - (((11365.990532976068 / fConst1) + 184.65636084069297) / (fConst1 * fConst97)));
		fConst101 = ((71.467716130467849 / fConst1) + 1.0);
		fConst102 = (0.0 - (142.9354322609357 / (fConst101 * fConst1)));
		fConst103 = ((((6118.1542368773398 / fConst1) + 113.18864471022512) / fConst1) + 1.0);
		fConst104 = (1.0 / (fConst101 * fConst103));
		fConst105 = (0.0 - (24472.616947509359 / (fConst103 * fConst7)));
		fConst106 = (0.0 - (((24472.616947509359 / fConst1) + 226.37728942045024) / (fConst103 * fConst1)));
		fConst107 = ((((8657.2200974217594 / fConst1) + 178.26790338167996) / fConst1) + 1.0);
		fConst108 = (0.0 - (34628.880389687038 / (fConst107 * fConst7)));
		fConst109 = (0.0 - (((34628.880389687038 / fConst1) + 356.53580676335991) / (fConst107 * fConst1)));
		fConst110 = ((((10880.852622069639 / fConst1) + 129.49269801947491) / fConst1) + 1.0);
		fConst111 = (1.0 / (fConst107 * fConst110));
		fConst112 = (0.0 - (43523.410488278554 / (fConst110 * fConst7)));
		fConst113 = (0.0 - (((43523.410488278554 / fConst1) + 258.98539603894983) / (fConst110 * fConst1)));
		fConst114 = ((112.2322463251477 / fConst1) + 1.0);
		fConst115 = (0.0 - (224.4644926502954 / (fConst1 * fConst114)));
		fConst116 = ((((13518.406533001747 / fConst1) + 206.32002345478514) / fConst1) + 1.0);
		fConst117 = (0.0 - (54073.62613200699 / (fConst7 * fConst116)));
		fConst118 = (0.0 - (((54073.62613200699 / fConst1) + 412.64004690957029) / (fConst1 * fConst116)));
		fConst119 = ((((17197.042330535627 / fConst1) + 143.0886323217992) / fConst1) + 1.0);
		fConst120 = (1.0 / ((fConst114 * fConst116) * fConst119));
		fConst121 = (0.0 - (68788.169322142508 / (fConst7 * fConst119)));
		fConst122 = (0.0 - (((68788.169322142508 / fConst1) + 286.17726464359839) / (fConst1 * fConst119)));
		
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
			fRec11[l1] = 0.0;
			
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec10[l2] = 0.0;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec12[l3] = 0.0;
			
		}
		for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
			fRec13[l4] = 0.0;
			
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec14[l5] = 0.0;
			
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec15[l6] = 0.0;
			
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec16[l7] = 0.0;
			
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec17[l8] = 0.0;
			
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec18[l9] = 0.0;
			
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec9[l10] = 0.0;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec7[l11] = 0.0;
			
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec6[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec4[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec3[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec1[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec25[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec26[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec27[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec28[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec29[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec24[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec22[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec21[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec19[l24] = 0.0;
			
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec33[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec34[l26] = 0.0;
			
		}
		for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) {
			fRec35[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec32[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec30[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) {
			fRec48[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) {
			fRec49[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 3); l32 = (l32 + 1)) {
			fRec50[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 3); l33 = (l33 + 1)) {
			fRec51[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec52[l34] = 0.0;
			
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
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec47[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec45[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec44[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec42[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec41[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec39[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec38[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec36[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec71[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec72[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec73[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 3); l49 = (l49 + 1)) {
			fRec74[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 3); l50 = (l50 + 1)) {
			fRec75[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 3); l51 = (l51 + 1)) {
			fRec76[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 3); l52 = (l52 + 1)) {
			fRec77[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 3); l53 = (l53 + 1)) {
			fRec78[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec70[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec68[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) {
			fRec67[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fRec65[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec64[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec62[l59] = 0.0;
			
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			fRec61[l60] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec59[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec58[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec56[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 3); l64 = (l64 + 1)) {
			fRec79[l64] = 0.0;
			
		}
		IOTA = 0;
		for (int l65 = 0; (l65 < 1024); l65 = (l65 + 1)) {
			fVec0[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec94[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec92[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec91[l68] = 0.0;
			
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec89[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec88[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec86[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec85[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec83[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec82[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 2); l75 = (l75 + 1)) {
			fRec80[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec106[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec104[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec103[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fRec101[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec100[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec98[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec97[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fRec95[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec115[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec113[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec112[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 2); l87 = (l87 + 1)) {
			fRec110[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			fRec109[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec107[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec118[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec116[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec124[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec122[l93] = 0.0;
			
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec121[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec119[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 1024); l96 = (l96 + 1)) {
			fVec1[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec139[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec137[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec136[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 2); l100 = (l100 + 1)) {
			fRec134[l100] = 0.0;
			
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fRec133[l101] = 0.0;
			
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec131[l102] = 0.0;
			
		}
		for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) {
			fRec130[l103] = 0.0;
			
		}
		for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) {
			fRec128[l104] = 0.0;
			
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fRec127[l105] = 0.0;
			
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec125[l106] = 0.0;
			
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fRec151[l107] = 0.0;
			
		}
		for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) {
			fRec149[l108] = 0.0;
			
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec148[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec146[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec145[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec143[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec142[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec140[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec160[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec158[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec157[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec155[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec154[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec152[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec163[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec161[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec169[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec167[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fRec166[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec164[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 1024); l127 = (l127 + 1)) {
			fVec2[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec184[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec182[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec181[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 2); l131 = (l131 + 1)) {
			fRec179[l131] = 0.0;
			
		}
		for (int l132 = 0; (l132 < 2); l132 = (l132 + 1)) {
			fRec178[l132] = 0.0;
			
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec176[l133] = 0.0;
			
		}
		for (int l134 = 0; (l134 < 2); l134 = (l134 + 1)) {
			fRec175[l134] = 0.0;
			
		}
		for (int l135 = 0; (l135 < 2); l135 = (l135 + 1)) {
			fRec173[l135] = 0.0;
			
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec172[l136] = 0.0;
			
		}
		for (int l137 = 0; (l137 < 2); l137 = (l137 + 1)) {
			fRec170[l137] = 0.0;
			
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec196[l138] = 0.0;
			
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fRec194[l139] = 0.0;
			
		}
		for (int l140 = 0; (l140 < 2); l140 = (l140 + 1)) {
			fRec193[l140] = 0.0;
			
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fRec191[l141] = 0.0;
			
		}
		for (int l142 = 0; (l142 < 2); l142 = (l142 + 1)) {
			fRec190[l142] = 0.0;
			
		}
		for (int l143 = 0; (l143 < 2); l143 = (l143 + 1)) {
			fRec188[l143] = 0.0;
			
		}
		for (int l144 = 0; (l144 < 2); l144 = (l144 + 1)) {
			fRec187[l144] = 0.0;
			
		}
		for (int l145 = 0; (l145 < 2); l145 = (l145 + 1)) {
			fRec185[l145] = 0.0;
			
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fRec205[l146] = 0.0;
			
		}
		for (int l147 = 0; (l147 < 2); l147 = (l147 + 1)) {
			fRec203[l147] = 0.0;
			
		}
		for (int l148 = 0; (l148 < 2); l148 = (l148 + 1)) {
			fRec202[l148] = 0.0;
			
		}
		for (int l149 = 0; (l149 < 2); l149 = (l149 + 1)) {
			fRec200[l149] = 0.0;
			
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec199[l150] = 0.0;
			
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec197[l151] = 0.0;
			
		}
		for (int l152 = 0; (l152 < 2); l152 = (l152 + 1)) {
			fRec208[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec206[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec214[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec212[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec211[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec209[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 1024); l158 = (l158 + 1)) {
			fVec3[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec229[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec227[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec226[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 2); l162 = (l162 + 1)) {
			fRec224[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			fRec223[l163] = 0.0;
			
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			fRec221[l164] = 0.0;
			
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec220[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec218[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fRec217[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec215[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec241[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec239[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fRec238[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec236[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fRec235[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec233[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec232[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec230[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec250[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 2); l178 = (l178 + 1)) {
			fRec248[l178] = 0.0;
			
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec247[l179] = 0.0;
			
		}
		for (int l180 = 0; (l180 < 2); l180 = (l180 + 1)) {
			fRec245[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec244[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec242[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fRec253[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec251[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec259[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fRec257[l186] = 0.0;
			
		}
		for (int l187 = 0; (l187 < 2); l187 = (l187 + 1)) {
			fRec256[l187] = 0.0;
			
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec254[l188] = 0.0;
			
		}
		for (int l189 = 0; (l189 < 1024); l189 = (l189 + 1)) {
			fVec4[l189] = 0.0;
			
		}
		for (int l190 = 0; (l190 < 2); l190 = (l190 + 1)) {
			fRec274[l190] = 0.0;
			
		}
		for (int l191 = 0; (l191 < 2); l191 = (l191 + 1)) {
			fRec272[l191] = 0.0;
			
		}
		for (int l192 = 0; (l192 < 2); l192 = (l192 + 1)) {
			fRec271[l192] = 0.0;
			
		}
		for (int l193 = 0; (l193 < 2); l193 = (l193 + 1)) {
			fRec269[l193] = 0.0;
			
		}
		for (int l194 = 0; (l194 < 2); l194 = (l194 + 1)) {
			fRec268[l194] = 0.0;
			
		}
		for (int l195 = 0; (l195 < 2); l195 = (l195 + 1)) {
			fRec266[l195] = 0.0;
			
		}
		for (int l196 = 0; (l196 < 2); l196 = (l196 + 1)) {
			fRec265[l196] = 0.0;
			
		}
		for (int l197 = 0; (l197 < 2); l197 = (l197 + 1)) {
			fRec263[l197] = 0.0;
			
		}
		for (int l198 = 0; (l198 < 2); l198 = (l198 + 1)) {
			fRec262[l198] = 0.0;
			
		}
		for (int l199 = 0; (l199 < 2); l199 = (l199 + 1)) {
			fRec260[l199] = 0.0;
			
		}
		for (int l200 = 0; (l200 < 2); l200 = (l200 + 1)) {
			fRec286[l200] = 0.0;
			
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fRec284[l201] = 0.0;
			
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec283[l202] = 0.0;
			
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fRec281[l203] = 0.0;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec280[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec278[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec277[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec275[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec295[l208] = 0.0;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec293[l209] = 0.0;
			
		}
		for (int l210 = 0; (l210 < 2); l210 = (l210 + 1)) {
			fRec292[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 2); l211 = (l211 + 1)) {
			fRec290[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec289[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec287[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fRec298[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 2); l215 = (l215 + 1)) {
			fRec296[l215] = 0.0;
			
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fRec304[l216] = 0.0;
			
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec302[l217] = 0.0;
			
		}
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fRec301[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec299[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 1024); l220 = (l220 + 1)) {
			fVec5[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec319[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec317[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec316[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 2); l224 = (l224 + 1)) {
			fRec314[l224] = 0.0;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec313[l225] = 0.0;
			
		}
		for (int l226 = 0; (l226 < 2); l226 = (l226 + 1)) {
			fRec311[l226] = 0.0;
			
		}
		for (int l227 = 0; (l227 < 2); l227 = (l227 + 1)) {
			fRec310[l227] = 0.0;
			
		}
		for (int l228 = 0; (l228 < 2); l228 = (l228 + 1)) {
			fRec308[l228] = 0.0;
			
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fRec307[l229] = 0.0;
			
		}
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec305[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fRec331[l231] = 0.0;
			
		}
		for (int l232 = 0; (l232 < 2); l232 = (l232 + 1)) {
			fRec329[l232] = 0.0;
			
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fRec328[l233] = 0.0;
			
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec326[l234] = 0.0;
			
		}
		for (int l235 = 0; (l235 < 2); l235 = (l235 + 1)) {
			fRec325[l235] = 0.0;
			
		}
		for (int l236 = 0; (l236 < 2); l236 = (l236 + 1)) {
			fRec323[l236] = 0.0;
			
		}
		for (int l237 = 0; (l237 < 2); l237 = (l237 + 1)) {
			fRec322[l237] = 0.0;
			
		}
		for (int l238 = 0; (l238 < 2); l238 = (l238 + 1)) {
			fRec320[l238] = 0.0;
			
		}
		for (int l239 = 0; (l239 < 2); l239 = (l239 + 1)) {
			fRec340[l239] = 0.0;
			
		}
		for (int l240 = 0; (l240 < 2); l240 = (l240 + 1)) {
			fRec338[l240] = 0.0;
			
		}
		for (int l241 = 0; (l241 < 2); l241 = (l241 + 1)) {
			fRec337[l241] = 0.0;
			
		}
		for (int l242 = 0; (l242 < 2); l242 = (l242 + 1)) {
			fRec335[l242] = 0.0;
			
		}
		for (int l243 = 0; (l243 < 2); l243 = (l243 + 1)) {
			fRec334[l243] = 0.0;
			
		}
		for (int l244 = 0; (l244 < 2); l244 = (l244 + 1)) {
			fRec332[l244] = 0.0;
			
		}
		for (int l245 = 0; (l245 < 2); l245 = (l245 + 1)) {
			fRec343[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fRec341[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 2); l247 = (l247 + 1)) {
			fRec349[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 2); l248 = (l248 + 1)) {
			fRec347[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fRec346[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 2); l250 = (l250 + 1)) {
			fRec344[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 1024); l251 = (l251 + 1)) {
			fVec6[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 2); l252 = (l252 + 1)) {
			fRec364[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec362[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec361[l254] = 0.0;
			
		}
		for (int l255 = 0; (l255 < 2); l255 = (l255 + 1)) {
			fRec359[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec358[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fRec356[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec355[l258] = 0.0;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec353[l259] = 0.0;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec352[l260] = 0.0;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec350[l261] = 0.0;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec376[l262] = 0.0;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec374[l263] = 0.0;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec373[l264] = 0.0;
			
		}
		for (int l265 = 0; (l265 < 2); l265 = (l265 + 1)) {
			fRec371[l265] = 0.0;
			
		}
		for (int l266 = 0; (l266 < 2); l266 = (l266 + 1)) {
			fRec370[l266] = 0.0;
			
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec368[l267] = 0.0;
			
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec367[l268] = 0.0;
			
		}
		for (int l269 = 0; (l269 < 2); l269 = (l269 + 1)) {
			fRec365[l269] = 0.0;
			
		}
		for (int l270 = 0; (l270 < 2); l270 = (l270 + 1)) {
			fRec385[l270] = 0.0;
			
		}
		for (int l271 = 0; (l271 < 2); l271 = (l271 + 1)) {
			fRec383[l271] = 0.0;
			
		}
		for (int l272 = 0; (l272 < 2); l272 = (l272 + 1)) {
			fRec382[l272] = 0.0;
			
		}
		for (int l273 = 0; (l273 < 2); l273 = (l273 + 1)) {
			fRec380[l273] = 0.0;
			
		}
		for (int l274 = 0; (l274 < 2); l274 = (l274 + 1)) {
			fRec379[l274] = 0.0;
			
		}
		for (int l275 = 0; (l275 < 2); l275 = (l275 + 1)) {
			fRec377[l275] = 0.0;
			
		}
		for (int l276 = 0; (l276 < 2); l276 = (l276 + 1)) {
			fRec388[l276] = 0.0;
			
		}
		for (int l277 = 0; (l277 < 2); l277 = (l277 + 1)) {
			fRec386[l277] = 0.0;
			
		}
		for (int l278 = 0; (l278 < 2); l278 = (l278 + 1)) {
			fRec394[l278] = 0.0;
			
		}
		for (int l279 = 0; (l279 < 2); l279 = (l279 + 1)) {
			fRec392[l279] = 0.0;
			
		}
		for (int l280 = 0; (l280 < 2); l280 = (l280 + 1)) {
			fRec391[l280] = 0.0;
			
		}
		for (int l281 = 0; (l281 < 2); l281 = (l281 + 1)) {
			fRec389[l281] = 0.0;
			
		}
		for (int l282 = 0; (l282 < 1024); l282 = (l282 + 1)) {
			fVec7[l282] = 0.0;
			
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec409[l283] = 0.0;
			
		}
		for (int l284 = 0; (l284 < 2); l284 = (l284 + 1)) {
			fRec407[l284] = 0.0;
			
		}
		for (int l285 = 0; (l285 < 2); l285 = (l285 + 1)) {
			fRec406[l285] = 0.0;
			
		}
		for (int l286 = 0; (l286 < 2); l286 = (l286 + 1)) {
			fRec404[l286] = 0.0;
			
		}
		for (int l287 = 0; (l287 < 2); l287 = (l287 + 1)) {
			fRec403[l287] = 0.0;
			
		}
		for (int l288 = 0; (l288 < 2); l288 = (l288 + 1)) {
			fRec401[l288] = 0.0;
			
		}
		for (int l289 = 0; (l289 < 2); l289 = (l289 + 1)) {
			fRec400[l289] = 0.0;
			
		}
		for (int l290 = 0; (l290 < 2); l290 = (l290 + 1)) {
			fRec398[l290] = 0.0;
			
		}
		for (int l291 = 0; (l291 < 2); l291 = (l291 + 1)) {
			fRec397[l291] = 0.0;
			
		}
		for (int l292 = 0; (l292 < 2); l292 = (l292 + 1)) {
			fRec395[l292] = 0.0;
			
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec421[l293] = 0.0;
			
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec419[l294] = 0.0;
			
		}
		for (int l295 = 0; (l295 < 2); l295 = (l295 + 1)) {
			fRec418[l295] = 0.0;
			
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec416[l296] = 0.0;
			
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec415[l297] = 0.0;
			
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec413[l298] = 0.0;
			
		}
		for (int l299 = 0; (l299 < 2); l299 = (l299 + 1)) {
			fRec412[l299] = 0.0;
			
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec410[l300] = 0.0;
			
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec430[l301] = 0.0;
			
		}
		for (int l302 = 0; (l302 < 2); l302 = (l302 + 1)) {
			fRec428[l302] = 0.0;
			
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec427[l303] = 0.0;
			
		}
		for (int l304 = 0; (l304 < 2); l304 = (l304 + 1)) {
			fRec425[l304] = 0.0;
			
		}
		for (int l305 = 0; (l305 < 2); l305 = (l305 + 1)) {
			fRec424[l305] = 0.0;
			
		}
		for (int l306 = 0; (l306 < 2); l306 = (l306 + 1)) {
			fRec422[l306] = 0.0;
			
		}
		for (int l307 = 0; (l307 < 2); l307 = (l307 + 1)) {
			fRec433[l307] = 0.0;
			
		}
		for (int l308 = 0; (l308 < 2); l308 = (l308 + 1)) {
			fRec431[l308] = 0.0;
			
		}
		for (int l309 = 0; (l309 < 2); l309 = (l309 + 1)) {
			fRec439[l309] = 0.0;
			
		}
		for (int l310 = 0; (l310 < 2); l310 = (l310 + 1)) {
			fRec437[l310] = 0.0;
			
		}
		for (int l311 = 0; (l311 < 2); l311 = (l311 + 1)) {
			fRec436[l311] = 0.0;
			
		}
		for (int l312 = 0; (l312 < 2); l312 = (l312 + 1)) {
			fRec434[l312] = 0.0;
			
		}
		for (int l313 = 0; (l313 < 1024); l313 = (l313 + 1)) {
			fVec8[l313] = 0.0;
			
		}
		for (int l314 = 0; (l314 < 2); l314 = (l314 + 1)) {
			fRec451[l314] = 0.0;
			
		}
		for (int l315 = 0; (l315 < 2); l315 = (l315 + 1)) {
			fRec449[l315] = 0.0;
			
		}
		for (int l316 = 0; (l316 < 2); l316 = (l316 + 1)) {
			fRec448[l316] = 0.0;
			
		}
		for (int l317 = 0; (l317 < 2); l317 = (l317 + 1)) {
			fRec446[l317] = 0.0;
			
		}
		for (int l318 = 0; (l318 < 2); l318 = (l318 + 1)) {
			fRec445[l318] = 0.0;
			
		}
		for (int l319 = 0; (l319 < 2); l319 = (l319 + 1)) {
			fRec443[l319] = 0.0;
			
		}
		for (int l320 = 0; (l320 < 2); l320 = (l320 + 1)) {
			fRec442[l320] = 0.0;
			
		}
		for (int l321 = 0; (l321 < 2); l321 = (l321 + 1)) {
			fRec440[l321] = 0.0;
			
		}
		for (int l322 = 0; (l322 < 2); l322 = (l322 + 1)) {
			fRec460[l322] = 0.0;
			
		}
		for (int l323 = 0; (l323 < 2); l323 = (l323 + 1)) {
			fRec458[l323] = 0.0;
			
		}
		for (int l324 = 0; (l324 < 2); l324 = (l324 + 1)) {
			fRec457[l324] = 0.0;
			
		}
		for (int l325 = 0; (l325 < 2); l325 = (l325 + 1)) {
			fRec455[l325] = 0.0;
			
		}
		for (int l326 = 0; (l326 < 2); l326 = (l326 + 1)) {
			fRec454[l326] = 0.0;
			
		}
		for (int l327 = 0; (l327 < 2); l327 = (l327 + 1)) {
			fRec452[l327] = 0.0;
			
		}
		for (int l328 = 0; (l328 < 2); l328 = (l328 + 1)) {
			fRec466[l328] = 0.0;
			
		}
		for (int l329 = 0; (l329 < 2); l329 = (l329 + 1)) {
			fRec464[l329] = 0.0;
			
		}
		for (int l330 = 0; (l330 < 2); l330 = (l330 + 1)) {
			fRec463[l330] = 0.0;
			
		}
		for (int l331 = 0; (l331 < 2); l331 = (l331 + 1)) {
			fRec461[l331] = 0.0;
			
		}
		for (int l332 = 0; (l332 < 2); l332 = (l332 + 1)) {
			fRec481[l332] = 0.0;
			
		}
		for (int l333 = 0; (l333 < 2); l333 = (l333 + 1)) {
			fRec479[l333] = 0.0;
			
		}
		for (int l334 = 0; (l334 < 2); l334 = (l334 + 1)) {
			fRec478[l334] = 0.0;
			
		}
		for (int l335 = 0; (l335 < 2); l335 = (l335 + 1)) {
			fRec476[l335] = 0.0;
			
		}
		for (int l336 = 0; (l336 < 2); l336 = (l336 + 1)) {
			fRec475[l336] = 0.0;
			
		}
		for (int l337 = 0; (l337 < 2); l337 = (l337 + 1)) {
			fRec473[l337] = 0.0;
			
		}
		for (int l338 = 0; (l338 < 2); l338 = (l338 + 1)) {
			fRec472[l338] = 0.0;
			
		}
		for (int l339 = 0; (l339 < 2); l339 = (l339 + 1)) {
			fRec470[l339] = 0.0;
			
		}
		for (int l340 = 0; (l340 < 2); l340 = (l340 + 1)) {
			fRec469[l340] = 0.0;
			
		}
		for (int l341 = 0; (l341 < 2); l341 = (l341 + 1)) {
			fRec467[l341] = 0.0;
			
		}
		for (int l342 = 0; (l342 < 2); l342 = (l342 + 1)) {
			fRec484[l342] = 0.0;
			
		}
		for (int l343 = 0; (l343 < 2); l343 = (l343 + 1)) {
			fRec482[l343] = 0.0;
			
		}
		for (int l344 = 0; (l344 < 1024); l344 = (l344 + 1)) {
			fVec9[l344] = 0.0;
			
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
		for (int l351 = 0; (l351 < 2); l351 = (l351 + 1)) {
			fRec490[l351] = 0.0;
			
		}
		for (int l352 = 0; (l352 < 2); l352 = (l352 + 1)) {
			fRec488[l352] = 0.0;
			
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec487[l353] = 0.0;
			
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec485[l354] = 0.0;
			
		}
		for (int l355 = 0; (l355 < 2); l355 = (l355 + 1)) {
			fRec511[l355] = 0.0;
			
		}
		for (int l356 = 0; (l356 < 2); l356 = (l356 + 1)) {
			fRec509[l356] = 0.0;
			
		}
		for (int l357 = 0; (l357 < 2); l357 = (l357 + 1)) {
			fRec508[l357] = 0.0;
			
		}
		for (int l358 = 0; (l358 < 2); l358 = (l358 + 1)) {
			fRec506[l358] = 0.0;
			
		}
		for (int l359 = 0; (l359 < 2); l359 = (l359 + 1)) {
			fRec505[l359] = 0.0;
			
		}
		for (int l360 = 0; (l360 < 2); l360 = (l360 + 1)) {
			fRec503[l360] = 0.0;
			
		}
		for (int l361 = 0; (l361 < 2); l361 = (l361 + 1)) {
			fRec502[l361] = 0.0;
			
		}
		for (int l362 = 0; (l362 < 2); l362 = (l362 + 1)) {
			fRec500[l362] = 0.0;
			
		}
		for (int l363 = 0; (l363 < 2); l363 = (l363 + 1)) {
			fRec520[l363] = 0.0;
			
		}
		for (int l364 = 0; (l364 < 2); l364 = (l364 + 1)) {
			fRec518[l364] = 0.0;
			
		}
		for (int l365 = 0; (l365 < 2); l365 = (l365 + 1)) {
			fRec517[l365] = 0.0;
			
		}
		for (int l366 = 0; (l366 < 2); l366 = (l366 + 1)) {
			fRec515[l366] = 0.0;
			
		}
		for (int l367 = 0; (l367 < 2); l367 = (l367 + 1)) {
			fRec514[l367] = 0.0;
			
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec512[l368] = 0.0;
			
		}
		for (int l369 = 0; (l369 < 2); l369 = (l369 + 1)) {
			fRec523[l369] = 0.0;
			
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec521[l370] = 0.0;
			
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			fRec529[l371] = 0.0;
			
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			fRec527[l372] = 0.0;
			
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fRec526[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec524[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 1024); l375 = (l375 + 1)) {
			fVec10[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec544[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec542[l377] = 0.0;
			
		}
		for (int l378 = 0; (l378 < 2); l378 = (l378 + 1)) {
			fRec541[l378] = 0.0;
			
		}
		for (int l379 = 0; (l379 < 2); l379 = (l379 + 1)) {
			fRec539[l379] = 0.0;
			
		}
		for (int l380 = 0; (l380 < 2); l380 = (l380 + 1)) {
			fRec538[l380] = 0.0;
			
		}
		for (int l381 = 0; (l381 < 2); l381 = (l381 + 1)) {
			fRec536[l381] = 0.0;
			
		}
		for (int l382 = 0; (l382 < 2); l382 = (l382 + 1)) {
			fRec535[l382] = 0.0;
			
		}
		for (int l383 = 0; (l383 < 2); l383 = (l383 + 1)) {
			fRec533[l383] = 0.0;
			
		}
		for (int l384 = 0; (l384 < 2); l384 = (l384 + 1)) {
			fRec532[l384] = 0.0;
			
		}
		for (int l385 = 0; (l385 < 2); l385 = (l385 + 1)) {
			fRec530[l385] = 0.0;
			
		}
		for (int l386 = 0; (l386 < 2); l386 = (l386 + 1)) {
			fRec553[l386] = 0.0;
			
		}
		for (int l387 = 0; (l387 < 2); l387 = (l387 + 1)) {
			fRec551[l387] = 0.0;
			
		}
		for (int l388 = 0; (l388 < 2); l388 = (l388 + 1)) {
			fRec550[l388] = 0.0;
			
		}
		for (int l389 = 0; (l389 < 2); l389 = (l389 + 1)) {
			fRec548[l389] = 0.0;
			
		}
		for (int l390 = 0; (l390 < 2); l390 = (l390 + 1)) {
			fRec547[l390] = 0.0;
			
		}
		for (int l391 = 0; (l391 < 2); l391 = (l391 + 1)) {
			fRec545[l391] = 0.0;
			
		}
		for (int l392 = 0; (l392 < 2); l392 = (l392 + 1)) {
			fRec559[l392] = 0.0;
			
		}
		for (int l393 = 0; (l393 < 2); l393 = (l393 + 1)) {
			fRec557[l393] = 0.0;
			
		}
		for (int l394 = 0; (l394 < 2); l394 = (l394 + 1)) {
			fRec556[l394] = 0.0;
			
		}
		for (int l395 = 0; (l395 < 2); l395 = (l395 + 1)) {
			fRec554[l395] = 0.0;
			
		}
		for (int l396 = 0; (l396 < 2); l396 = (l396 + 1)) {
			fRec571[l396] = 0.0;
			
		}
		for (int l397 = 0; (l397 < 2); l397 = (l397 + 1)) {
			fRec569[l397] = 0.0;
			
		}
		for (int l398 = 0; (l398 < 2); l398 = (l398 + 1)) {
			fRec568[l398] = 0.0;
			
		}
		for (int l399 = 0; (l399 < 2); l399 = (l399 + 1)) {
			fRec566[l399] = 0.0;
			
		}
		for (int l400 = 0; (l400 < 2); l400 = (l400 + 1)) {
			fRec565[l400] = 0.0;
			
		}
		for (int l401 = 0; (l401 < 2); l401 = (l401 + 1)) {
			fRec563[l401] = 0.0;
			
		}
		for (int l402 = 0; (l402 < 2); l402 = (l402 + 1)) {
			fRec562[l402] = 0.0;
			
		}
		for (int l403 = 0; (l403 < 2); l403 = (l403 + 1)) {
			fRec560[l403] = 0.0;
			
		}
		for (int l404 = 0; (l404 < 2); l404 = (l404 + 1)) {
			fRec574[l404] = 0.0;
			
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec572[l405] = 0.0;
			
		}
		for (int l406 = 0; (l406 < 1024); l406 = (l406 + 1)) {
			fVec11[l406] = 0.0;
			
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec577[l407] = 0.0;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec575[l408] = 0.0;
			
		}
		for (int l409 = 0; (l409 < 2); l409 = (l409 + 1)) {
			fRec592[l409] = 0.0;
			
		}
		for (int l410 = 0; (l410 < 2); l410 = (l410 + 1)) {
			fRec590[l410] = 0.0;
			
		}
		for (int l411 = 0; (l411 < 2); l411 = (l411 + 1)) {
			fRec589[l411] = 0.0;
			
		}
		for (int l412 = 0; (l412 < 2); l412 = (l412 + 1)) {
			fRec587[l412] = 0.0;
			
		}
		for (int l413 = 0; (l413 < 2); l413 = (l413 + 1)) {
			fRec586[l413] = 0.0;
			
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec584[l414] = 0.0;
			
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec583[l415] = 0.0;
			
		}
		for (int l416 = 0; (l416 < 2); l416 = (l416 + 1)) {
			fRec581[l416] = 0.0;
			
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec580[l417] = 0.0;
			
		}
		for (int l418 = 0; (l418 < 2); l418 = (l418 + 1)) {
			fRec578[l418] = 0.0;
			
		}
		for (int l419 = 0; (l419 < 2); l419 = (l419 + 1)) {
			fRec604[l419] = 0.0;
			
		}
		for (int l420 = 0; (l420 < 2); l420 = (l420 + 1)) {
			fRec602[l420] = 0.0;
			
		}
		for (int l421 = 0; (l421 < 2); l421 = (l421 + 1)) {
			fRec601[l421] = 0.0;
			
		}
		for (int l422 = 0; (l422 < 2); l422 = (l422 + 1)) {
			fRec599[l422] = 0.0;
			
		}
		for (int l423 = 0; (l423 < 2); l423 = (l423 + 1)) {
			fRec598[l423] = 0.0;
			
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec596[l424] = 0.0;
			
		}
		for (int l425 = 0; (l425 < 2); l425 = (l425 + 1)) {
			fRec595[l425] = 0.0;
			
		}
		for (int l426 = 0; (l426 < 2); l426 = (l426 + 1)) {
			fRec593[l426] = 0.0;
			
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec610[l427] = 0.0;
			
		}
		for (int l428 = 0; (l428 < 2); l428 = (l428 + 1)) {
			fRec608[l428] = 0.0;
			
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec607[l429] = 0.0;
			
		}
		for (int l430 = 0; (l430 < 2); l430 = (l430 + 1)) {
			fRec605[l430] = 0.0;
			
		}
		for (int l431 = 0; (l431 < 2); l431 = (l431 + 1)) {
			fRec619[l431] = 0.0;
			
		}
		for (int l432 = 0; (l432 < 2); l432 = (l432 + 1)) {
			fRec617[l432] = 0.0;
			
		}
		for (int l433 = 0; (l433 < 2); l433 = (l433 + 1)) {
			fRec616[l433] = 0.0;
			
		}
		for (int l434 = 0; (l434 < 2); l434 = (l434 + 1)) {
			fRec614[l434] = 0.0;
			
		}
		for (int l435 = 0; (l435 < 2); l435 = (l435 + 1)) {
			fRec613[l435] = 0.0;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec611[l436] = 0.0;
			
		}
		for (int l437 = 0; (l437 < 1024); l437 = (l437 + 1)) {
			fVec12[l437] = 0.0;
			
		}
		for (int l438 = 0; (l438 < 2); l438 = (l438 + 1)) {
			fRec634[l438] = 0.0;
			
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec632[l439] = 0.0;
			
		}
		for (int l440 = 0; (l440 < 2); l440 = (l440 + 1)) {
			fRec631[l440] = 0.0;
			
		}
		for (int l441 = 0; (l441 < 2); l441 = (l441 + 1)) {
			fRec629[l441] = 0.0;
			
		}
		for (int l442 = 0; (l442 < 2); l442 = (l442 + 1)) {
			fRec628[l442] = 0.0;
			
		}
		for (int l443 = 0; (l443 < 2); l443 = (l443 + 1)) {
			fRec626[l443] = 0.0;
			
		}
		for (int l444 = 0; (l444 < 2); l444 = (l444 + 1)) {
			fRec625[l444] = 0.0;
			
		}
		for (int l445 = 0; (l445 < 2); l445 = (l445 + 1)) {
			fRec623[l445] = 0.0;
			
		}
		for (int l446 = 0; (l446 < 2); l446 = (l446 + 1)) {
			fRec622[l446] = 0.0;
			
		}
		for (int l447 = 0; (l447 < 2); l447 = (l447 + 1)) {
			fRec620[l447] = 0.0;
			
		}
		for (int l448 = 0; (l448 < 2); l448 = (l448 + 1)) {
			fRec646[l448] = 0.0;
			
		}
		for (int l449 = 0; (l449 < 2); l449 = (l449 + 1)) {
			fRec644[l449] = 0.0;
			
		}
		for (int l450 = 0; (l450 < 2); l450 = (l450 + 1)) {
			fRec643[l450] = 0.0;
			
		}
		for (int l451 = 0; (l451 < 2); l451 = (l451 + 1)) {
			fRec641[l451] = 0.0;
			
		}
		for (int l452 = 0; (l452 < 2); l452 = (l452 + 1)) {
			fRec640[l452] = 0.0;
			
		}
		for (int l453 = 0; (l453 < 2); l453 = (l453 + 1)) {
			fRec638[l453] = 0.0;
			
		}
		for (int l454 = 0; (l454 < 2); l454 = (l454 + 1)) {
			fRec637[l454] = 0.0;
			
		}
		for (int l455 = 0; (l455 < 2); l455 = (l455 + 1)) {
			fRec635[l455] = 0.0;
			
		}
		for (int l456 = 0; (l456 < 2); l456 = (l456 + 1)) {
			fRec655[l456] = 0.0;
			
		}
		for (int l457 = 0; (l457 < 2); l457 = (l457 + 1)) {
			fRec653[l457] = 0.0;
			
		}
		for (int l458 = 0; (l458 < 2); l458 = (l458 + 1)) {
			fRec652[l458] = 0.0;
			
		}
		for (int l459 = 0; (l459 < 2); l459 = (l459 + 1)) {
			fRec650[l459] = 0.0;
			
		}
		for (int l460 = 0; (l460 < 2); l460 = (l460 + 1)) {
			fRec649[l460] = 0.0;
			
		}
		for (int l461 = 0; (l461 < 2); l461 = (l461 + 1)) {
			fRec647[l461] = 0.0;
			
		}
		for (int l462 = 0; (l462 < 2); l462 = (l462 + 1)) {
			fRec658[l462] = 0.0;
			
		}
		for (int l463 = 0; (l463 < 2); l463 = (l463 + 1)) {
			fRec656[l463] = 0.0;
			
		}
		for (int l464 = 0; (l464 < 2); l464 = (l464 + 1)) {
			fRec664[l464] = 0.0;
			
		}
		for (int l465 = 0; (l465 < 2); l465 = (l465 + 1)) {
			fRec662[l465] = 0.0;
			
		}
		for (int l466 = 0; (l466 < 2); l466 = (l466 + 1)) {
			fRec661[l466] = 0.0;
			
		}
		for (int l467 = 0; (l467 < 2); l467 = (l467 + 1)) {
			fRec659[l467] = 0.0;
			
		}
		for (int l468 = 0; (l468 < 1024); l468 = (l468 + 1)) {
			fVec13[l468] = 0.0;
			
		}
		for (int l469 = 0; (l469 < 2); l469 = (l469 + 1)) {
			fRec676[l469] = 0.0;
			
		}
		for (int l470 = 0; (l470 < 2); l470 = (l470 + 1)) {
			fRec674[l470] = 0.0;
			
		}
		for (int l471 = 0; (l471 < 2); l471 = (l471 + 1)) {
			fRec673[l471] = 0.0;
			
		}
		for (int l472 = 0; (l472 < 2); l472 = (l472 + 1)) {
			fRec671[l472] = 0.0;
			
		}
		for (int l473 = 0; (l473 < 2); l473 = (l473 + 1)) {
			fRec670[l473] = 0.0;
			
		}
		for (int l474 = 0; (l474 < 2); l474 = (l474 + 1)) {
			fRec668[l474] = 0.0;
			
		}
		for (int l475 = 0; (l475 < 2); l475 = (l475 + 1)) {
			fRec667[l475] = 0.0;
			
		}
		for (int l476 = 0; (l476 < 2); l476 = (l476 + 1)) {
			fRec665[l476] = 0.0;
			
		}
		for (int l477 = 0; (l477 < 2); l477 = (l477 + 1)) {
			fRec685[l477] = 0.0;
			
		}
		for (int l478 = 0; (l478 < 2); l478 = (l478 + 1)) {
			fRec683[l478] = 0.0;
			
		}
		for (int l479 = 0; (l479 < 2); l479 = (l479 + 1)) {
			fRec682[l479] = 0.0;
			
		}
		for (int l480 = 0; (l480 < 2); l480 = (l480 + 1)) {
			fRec680[l480] = 0.0;
			
		}
		for (int l481 = 0; (l481 < 2); l481 = (l481 + 1)) {
			fRec679[l481] = 0.0;
			
		}
		for (int l482 = 0; (l482 < 2); l482 = (l482 + 1)) {
			fRec677[l482] = 0.0;
			
		}
		for (int l483 = 0; (l483 < 2); l483 = (l483 + 1)) {
			fRec691[l483] = 0.0;
			
		}
		for (int l484 = 0; (l484 < 2); l484 = (l484 + 1)) {
			fRec689[l484] = 0.0;
			
		}
		for (int l485 = 0; (l485 < 2); l485 = (l485 + 1)) {
			fRec688[l485] = 0.0;
			
		}
		for (int l486 = 0; (l486 < 2); l486 = (l486 + 1)) {
			fRec686[l486] = 0.0;
			
		}
		for (int l487 = 0; (l487 < 2); l487 = (l487 + 1)) {
			fRec706[l487] = 0.0;
			
		}
		for (int l488 = 0; (l488 < 2); l488 = (l488 + 1)) {
			fRec704[l488] = 0.0;
			
		}
		for (int l489 = 0; (l489 < 2); l489 = (l489 + 1)) {
			fRec703[l489] = 0.0;
			
		}
		for (int l490 = 0; (l490 < 2); l490 = (l490 + 1)) {
			fRec701[l490] = 0.0;
			
		}
		for (int l491 = 0; (l491 < 2); l491 = (l491 + 1)) {
			fRec700[l491] = 0.0;
			
		}
		for (int l492 = 0; (l492 < 2); l492 = (l492 + 1)) {
			fRec698[l492] = 0.0;
			
		}
		for (int l493 = 0; (l493 < 2); l493 = (l493 + 1)) {
			fRec697[l493] = 0.0;
			
		}
		for (int l494 = 0; (l494 < 2); l494 = (l494 + 1)) {
			fRec695[l494] = 0.0;
			
		}
		for (int l495 = 0; (l495 < 2); l495 = (l495 + 1)) {
			fRec694[l495] = 0.0;
			
		}
		for (int l496 = 0; (l496 < 2); l496 = (l496 + 1)) {
			fRec692[l496] = 0.0;
			
		}
		for (int l497 = 0; (l497 < 2); l497 = (l497 + 1)) {
			fRec709[l497] = 0.0;
			
		}
		for (int l498 = 0; (l498 < 2); l498 = (l498 + 1)) {
			fRec707[l498] = 0.0;
			
		}
		for (int l499 = 0; (l499 < 1024); l499 = (l499 + 1)) {
			fVec14[l499] = 0.0;
			
		}
		for (int l500 = 0; (l500 < 2); l500 = (l500 + 1)) {
			fRec724[l500] = 0.0;
			
		}
		for (int l501 = 0; (l501 < 2); l501 = (l501 + 1)) {
			fRec722[l501] = 0.0;
			
		}
		for (int l502 = 0; (l502 < 2); l502 = (l502 + 1)) {
			fRec721[l502] = 0.0;
			
		}
		for (int l503 = 0; (l503 < 2); l503 = (l503 + 1)) {
			fRec719[l503] = 0.0;
			
		}
		for (int l504 = 0; (l504 < 2); l504 = (l504 + 1)) {
			fRec718[l504] = 0.0;
			
		}
		for (int l505 = 0; (l505 < 2); l505 = (l505 + 1)) {
			fRec716[l505] = 0.0;
			
		}
		for (int l506 = 0; (l506 < 2); l506 = (l506 + 1)) {
			fRec715[l506] = 0.0;
			
		}
		for (int l507 = 0; (l507 < 2); l507 = (l507 + 1)) {
			fRec713[l507] = 0.0;
			
		}
		for (int l508 = 0; (l508 < 2); l508 = (l508 + 1)) {
			fRec712[l508] = 0.0;
			
		}
		for (int l509 = 0; (l509 < 2); l509 = (l509 + 1)) {
			fRec710[l509] = 0.0;
			
		}
		for (int l510 = 0; (l510 < 2); l510 = (l510 + 1)) {
			fRec736[l510] = 0.0;
			
		}
		for (int l511 = 0; (l511 < 2); l511 = (l511 + 1)) {
			fRec734[l511] = 0.0;
			
		}
		for (int l512 = 0; (l512 < 2); l512 = (l512 + 1)) {
			fRec733[l512] = 0.0;
			
		}
		for (int l513 = 0; (l513 < 2); l513 = (l513 + 1)) {
			fRec731[l513] = 0.0;
			
		}
		for (int l514 = 0; (l514 < 2); l514 = (l514 + 1)) {
			fRec730[l514] = 0.0;
			
		}
		for (int l515 = 0; (l515 < 2); l515 = (l515 + 1)) {
			fRec728[l515] = 0.0;
			
		}
		for (int l516 = 0; (l516 < 2); l516 = (l516 + 1)) {
			fRec727[l516] = 0.0;
			
		}
		for (int l517 = 0; (l517 < 2); l517 = (l517 + 1)) {
			fRec725[l517] = 0.0;
			
		}
		for (int l518 = 0; (l518 < 2); l518 = (l518 + 1)) {
			fRec745[l518] = 0.0;
			
		}
		for (int l519 = 0; (l519 < 2); l519 = (l519 + 1)) {
			fRec743[l519] = 0.0;
			
		}
		for (int l520 = 0; (l520 < 2); l520 = (l520 + 1)) {
			fRec742[l520] = 0.0;
			
		}
		for (int l521 = 0; (l521 < 2); l521 = (l521 + 1)) {
			fRec740[l521] = 0.0;
			
		}
		for (int l522 = 0; (l522 < 2); l522 = (l522 + 1)) {
			fRec739[l522] = 0.0;
			
		}
		for (int l523 = 0; (l523 < 2); l523 = (l523 + 1)) {
			fRec737[l523] = 0.0;
			
		}
		for (int l524 = 0; (l524 < 2); l524 = (l524 + 1)) {
			fRec748[l524] = 0.0;
			
		}
		for (int l525 = 0; (l525 < 2); l525 = (l525 + 1)) {
			fRec746[l525] = 0.0;
			
		}
		for (int l526 = 0; (l526 < 2); l526 = (l526 + 1)) {
			fRec754[l526] = 0.0;
			
		}
		for (int l527 = 0; (l527 < 2); l527 = (l527 + 1)) {
			fRec752[l527] = 0.0;
			
		}
		for (int l528 = 0; (l528 < 2); l528 = (l528 + 1)) {
			fRec751[l528] = 0.0;
			
		}
		for (int l529 = 0; (l529 < 2); l529 = (l529 + 1)) {
			fRec749[l529] = 0.0;
			
		}
		for (int l530 = 0; (l530 < 1024); l530 = (l530 + 1)) {
			fVec15[l530] = 0.0;
			
		}
		for (int l531 = 0; (l531 < 2); l531 = (l531 + 1)) {
			fRec769[l531] = 0.0;
			
		}
		for (int l532 = 0; (l532 < 2); l532 = (l532 + 1)) {
			fRec767[l532] = 0.0;
			
		}
		for (int l533 = 0; (l533 < 2); l533 = (l533 + 1)) {
			fRec766[l533] = 0.0;
			
		}
		for (int l534 = 0; (l534 < 2); l534 = (l534 + 1)) {
			fRec764[l534] = 0.0;
			
		}
		for (int l535 = 0; (l535 < 2); l535 = (l535 + 1)) {
			fRec763[l535] = 0.0;
			
		}
		for (int l536 = 0; (l536 < 2); l536 = (l536 + 1)) {
			fRec761[l536] = 0.0;
			
		}
		for (int l537 = 0; (l537 < 2); l537 = (l537 + 1)) {
			fRec760[l537] = 0.0;
			
		}
		for (int l538 = 0; (l538 < 2); l538 = (l538 + 1)) {
			fRec758[l538] = 0.0;
			
		}
		for (int l539 = 0; (l539 < 2); l539 = (l539 + 1)) {
			fRec757[l539] = 0.0;
			
		}
		for (int l540 = 0; (l540 < 2); l540 = (l540 + 1)) {
			fRec755[l540] = 0.0;
			
		}
		for (int l541 = 0; (l541 < 2); l541 = (l541 + 1)) {
			fRec781[l541] = 0.0;
			
		}
		for (int l542 = 0; (l542 < 2); l542 = (l542 + 1)) {
			fRec779[l542] = 0.0;
			
		}
		for (int l543 = 0; (l543 < 2); l543 = (l543 + 1)) {
			fRec778[l543] = 0.0;
			
		}
		for (int l544 = 0; (l544 < 2); l544 = (l544 + 1)) {
			fRec776[l544] = 0.0;
			
		}
		for (int l545 = 0; (l545 < 2); l545 = (l545 + 1)) {
			fRec775[l545] = 0.0;
			
		}
		for (int l546 = 0; (l546 < 2); l546 = (l546 + 1)) {
			fRec773[l546] = 0.0;
			
		}
		for (int l547 = 0; (l547 < 2); l547 = (l547 + 1)) {
			fRec772[l547] = 0.0;
			
		}
		for (int l548 = 0; (l548 < 2); l548 = (l548 + 1)) {
			fRec770[l548] = 0.0;
			
		}
		for (int l549 = 0; (l549 < 2); l549 = (l549 + 1)) {
			fRec790[l549] = 0.0;
			
		}
		for (int l550 = 0; (l550 < 2); l550 = (l550 + 1)) {
			fRec788[l550] = 0.0;
			
		}
		for (int l551 = 0; (l551 < 2); l551 = (l551 + 1)) {
			fRec787[l551] = 0.0;
			
		}
		for (int l552 = 0; (l552 < 2); l552 = (l552 + 1)) {
			fRec785[l552] = 0.0;
			
		}
		for (int l553 = 0; (l553 < 2); l553 = (l553 + 1)) {
			fRec784[l553] = 0.0;
			
		}
		for (int l554 = 0; (l554 < 2); l554 = (l554 + 1)) {
			fRec782[l554] = 0.0;
			
		}
		for (int l555 = 0; (l555 < 2); l555 = (l555 + 1)) {
			fRec793[l555] = 0.0;
			
		}
		for (int l556 = 0; (l556 < 2); l556 = (l556 + 1)) {
			fRec791[l556] = 0.0;
			
		}
		for (int l557 = 0; (l557 < 2); l557 = (l557 + 1)) {
			fRec799[l557] = 0.0;
			
		}
		for (int l558 = 0; (l558 < 2); l558 = (l558 + 1)) {
			fRec797[l558] = 0.0;
			
		}
		for (int l559 = 0; (l559 < 2); l559 = (l559 + 1)) {
			fRec796[l559] = 0.0;
			
		}
		for (int l560 = 0; (l560 < 2); l560 = (l560 + 1)) {
			fRec794[l560] = 0.0;
			
		}
		for (int l561 = 0; (l561 < 2); l561 = (l561 + 1)) {
			fVec16[l561] = 0.0;
			
		}
		for (int l562 = 0; (l562 < 2); l562 = (l562 + 1)) {
			fRec814[l562] = 0.0;
			
		}
		for (int l563 = 0; (l563 < 2); l563 = (l563 + 1)) {
			fRec812[l563] = 0.0;
			
		}
		for (int l564 = 0; (l564 < 2); l564 = (l564 + 1)) {
			fRec811[l564] = 0.0;
			
		}
		for (int l565 = 0; (l565 < 2); l565 = (l565 + 1)) {
			fRec809[l565] = 0.0;
			
		}
		for (int l566 = 0; (l566 < 2); l566 = (l566 + 1)) {
			fRec808[l566] = 0.0;
			
		}
		for (int l567 = 0; (l567 < 2); l567 = (l567 + 1)) {
			fRec806[l567] = 0.0;
			
		}
		for (int l568 = 0; (l568 < 2); l568 = (l568 + 1)) {
			fRec805[l568] = 0.0;
			
		}
		for (int l569 = 0; (l569 < 2); l569 = (l569 + 1)) {
			fRec803[l569] = 0.0;
			
		}
		for (int l570 = 0; (l570 < 2); l570 = (l570 + 1)) {
			fRec802[l570] = 0.0;
			
		}
		for (int l571 = 0; (l571 < 2); l571 = (l571 + 1)) {
			fRec800[l571] = 0.0;
			
		}
		for (int l572 = 0; (l572 < 2); l572 = (l572 + 1)) {
			fRec826[l572] = 0.0;
			
		}
		for (int l573 = 0; (l573 < 2); l573 = (l573 + 1)) {
			fRec824[l573] = 0.0;
			
		}
		for (int l574 = 0; (l574 < 2); l574 = (l574 + 1)) {
			fRec823[l574] = 0.0;
			
		}
		for (int l575 = 0; (l575 < 2); l575 = (l575 + 1)) {
			fRec821[l575] = 0.0;
			
		}
		for (int l576 = 0; (l576 < 2); l576 = (l576 + 1)) {
			fRec820[l576] = 0.0;
			
		}
		for (int l577 = 0; (l577 < 2); l577 = (l577 + 1)) {
			fRec818[l577] = 0.0;
			
		}
		for (int l578 = 0; (l578 < 2); l578 = (l578 + 1)) {
			fRec817[l578] = 0.0;
			
		}
		for (int l579 = 0; (l579 < 2); l579 = (l579 + 1)) {
			fRec815[l579] = 0.0;
			
		}
		for (int l580 = 0; (l580 < 2); l580 = (l580 + 1)) {
			fRec835[l580] = 0.0;
			
		}
		for (int l581 = 0; (l581 < 2); l581 = (l581 + 1)) {
			fRec833[l581] = 0.0;
			
		}
		for (int l582 = 0; (l582 < 2); l582 = (l582 + 1)) {
			fRec832[l582] = 0.0;
			
		}
		for (int l583 = 0; (l583 < 2); l583 = (l583 + 1)) {
			fRec830[l583] = 0.0;
			
		}
		for (int l584 = 0; (l584 < 2); l584 = (l584 + 1)) {
			fRec829[l584] = 0.0;
			
		}
		for (int l585 = 0; (l585 < 2); l585 = (l585 + 1)) {
			fRec827[l585] = 0.0;
			
		}
		for (int l586 = 0; (l586 < 2); l586 = (l586 + 1)) {
			fRec838[l586] = 0.0;
			
		}
		for (int l587 = 0; (l587 < 2); l587 = (l587 + 1)) {
			fRec836[l587] = 0.0;
			
		}
		for (int l588 = 0; (l588 < 2); l588 = (l588 + 1)) {
			fRec844[l588] = 0.0;
			
		}
		for (int l589 = 0; (l589 < 2); l589 = (l589 + 1)) {
			fRec842[l589] = 0.0;
			
		}
		for (int l590 = 0; (l590 < 2); l590 = (l590 + 1)) {
			fRec841[l590] = 0.0;
			
		}
		for (int l591 = 0; (l591 < 2); l591 = (l591 + 1)) {
			fRec839[l591] = 0.0;
			
		}
		for (int l592 = 0; (l592 < 2); l592 = (l592 + 1)) {
			fVec17[l592] = 0.0;
			
		}
		for (int l593 = 0; (l593 < 2); l593 = (l593 + 1)) {
			fRec859[l593] = 0.0;
			
		}
		for (int l594 = 0; (l594 < 2); l594 = (l594 + 1)) {
			fRec857[l594] = 0.0;
			
		}
		for (int l595 = 0; (l595 < 2); l595 = (l595 + 1)) {
			fRec856[l595] = 0.0;
			
		}
		for (int l596 = 0; (l596 < 2); l596 = (l596 + 1)) {
			fRec854[l596] = 0.0;
			
		}
		for (int l597 = 0; (l597 < 2); l597 = (l597 + 1)) {
			fRec853[l597] = 0.0;
			
		}
		for (int l598 = 0; (l598 < 2); l598 = (l598 + 1)) {
			fRec851[l598] = 0.0;
			
		}
		for (int l599 = 0; (l599 < 2); l599 = (l599 + 1)) {
			fRec850[l599] = 0.0;
			
		}
		for (int l600 = 0; (l600 < 2); l600 = (l600 + 1)) {
			fRec848[l600] = 0.0;
			
		}
		for (int l601 = 0; (l601 < 2); l601 = (l601 + 1)) {
			fRec847[l601] = 0.0;
			
		}
		for (int l602 = 0; (l602 < 2); l602 = (l602 + 1)) {
			fRec845[l602] = 0.0;
			
		}
		for (int l603 = 0; (l603 < 2); l603 = (l603 + 1)) {
			fRec871[l603] = 0.0;
			
		}
		for (int l604 = 0; (l604 < 2); l604 = (l604 + 1)) {
			fRec869[l604] = 0.0;
			
		}
		for (int l605 = 0; (l605 < 2); l605 = (l605 + 1)) {
			fRec868[l605] = 0.0;
			
		}
		for (int l606 = 0; (l606 < 2); l606 = (l606 + 1)) {
			fRec866[l606] = 0.0;
			
		}
		for (int l607 = 0; (l607 < 2); l607 = (l607 + 1)) {
			fRec865[l607] = 0.0;
			
		}
		for (int l608 = 0; (l608 < 2); l608 = (l608 + 1)) {
			fRec863[l608] = 0.0;
			
		}
		for (int l609 = 0; (l609 < 2); l609 = (l609 + 1)) {
			fRec862[l609] = 0.0;
			
		}
		for (int l610 = 0; (l610 < 2); l610 = (l610 + 1)) {
			fRec860[l610] = 0.0;
			
		}
		for (int l611 = 0; (l611 < 2); l611 = (l611 + 1)) {
			fRec880[l611] = 0.0;
			
		}
		for (int l612 = 0; (l612 < 2); l612 = (l612 + 1)) {
			fRec878[l612] = 0.0;
			
		}
		for (int l613 = 0; (l613 < 2); l613 = (l613 + 1)) {
			fRec877[l613] = 0.0;
			
		}
		for (int l614 = 0; (l614 < 2); l614 = (l614 + 1)) {
			fRec875[l614] = 0.0;
			
		}
		for (int l615 = 0; (l615 < 2); l615 = (l615 + 1)) {
			fRec874[l615] = 0.0;
			
		}
		for (int l616 = 0; (l616 < 2); l616 = (l616 + 1)) {
			fRec872[l616] = 0.0;
			
		}
		for (int l617 = 0; (l617 < 2); l617 = (l617 + 1)) {
			fRec883[l617] = 0.0;
			
		}
		for (int l618 = 0; (l618 < 2); l618 = (l618 + 1)) {
			fRec881[l618] = 0.0;
			
		}
		for (int l619 = 0; (l619 < 2); l619 = (l619 + 1)) {
			fRec889[l619] = 0.0;
			
		}
		for (int l620 = 0; (l620 < 2); l620 = (l620 + 1)) {
			fRec887[l620] = 0.0;
			
		}
		for (int l621 = 0; (l621 < 2); l621 = (l621 + 1)) {
			fRec886[l621] = 0.0;
			
		}
		for (int l622 = 0; (l622 < 2); l622 = (l622 + 1)) {
			fRec884[l622] = 0.0;
			
		}
		for (int l623 = 0; (l623 < 2); l623 = (l623 + 1)) {
			fVec18[l623] = 0.0;
			
		}
		for (int l624 = 0; (l624 < 2); l624 = (l624 + 1)) {
			fRec904[l624] = 0.0;
			
		}
		for (int l625 = 0; (l625 < 2); l625 = (l625 + 1)) {
			fRec902[l625] = 0.0;
			
		}
		for (int l626 = 0; (l626 < 2); l626 = (l626 + 1)) {
			fRec901[l626] = 0.0;
			
		}
		for (int l627 = 0; (l627 < 2); l627 = (l627 + 1)) {
			fRec899[l627] = 0.0;
			
		}
		for (int l628 = 0; (l628 < 2); l628 = (l628 + 1)) {
			fRec898[l628] = 0.0;
			
		}
		for (int l629 = 0; (l629 < 2); l629 = (l629 + 1)) {
			fRec896[l629] = 0.0;
			
		}
		for (int l630 = 0; (l630 < 2); l630 = (l630 + 1)) {
			fRec895[l630] = 0.0;
			
		}
		for (int l631 = 0; (l631 < 2); l631 = (l631 + 1)) {
			fRec893[l631] = 0.0;
			
		}
		for (int l632 = 0; (l632 < 2); l632 = (l632 + 1)) {
			fRec892[l632] = 0.0;
			
		}
		for (int l633 = 0; (l633 < 2); l633 = (l633 + 1)) {
			fRec890[l633] = 0.0;
			
		}
		for (int l634 = 0; (l634 < 2); l634 = (l634 + 1)) {
			fRec916[l634] = 0.0;
			
		}
		for (int l635 = 0; (l635 < 2); l635 = (l635 + 1)) {
			fRec914[l635] = 0.0;
			
		}
		for (int l636 = 0; (l636 < 2); l636 = (l636 + 1)) {
			fRec913[l636] = 0.0;
			
		}
		for (int l637 = 0; (l637 < 2); l637 = (l637 + 1)) {
			fRec911[l637] = 0.0;
			
		}
		for (int l638 = 0; (l638 < 2); l638 = (l638 + 1)) {
			fRec910[l638] = 0.0;
			
		}
		for (int l639 = 0; (l639 < 2); l639 = (l639 + 1)) {
			fRec908[l639] = 0.0;
			
		}
		for (int l640 = 0; (l640 < 2); l640 = (l640 + 1)) {
			fRec907[l640] = 0.0;
			
		}
		for (int l641 = 0; (l641 < 2); l641 = (l641 + 1)) {
			fRec905[l641] = 0.0;
			
		}
		for (int l642 = 0; (l642 < 2); l642 = (l642 + 1)) {
			fRec925[l642] = 0.0;
			
		}
		for (int l643 = 0; (l643 < 2); l643 = (l643 + 1)) {
			fRec923[l643] = 0.0;
			
		}
		for (int l644 = 0; (l644 < 2); l644 = (l644 + 1)) {
			fRec922[l644] = 0.0;
			
		}
		for (int l645 = 0; (l645 < 2); l645 = (l645 + 1)) {
			fRec920[l645] = 0.0;
			
		}
		for (int l646 = 0; (l646 < 2); l646 = (l646 + 1)) {
			fRec919[l646] = 0.0;
			
		}
		for (int l647 = 0; (l647 < 2); l647 = (l647 + 1)) {
			fRec917[l647] = 0.0;
			
		}
		for (int l648 = 0; (l648 < 2); l648 = (l648 + 1)) {
			fRec928[l648] = 0.0;
			
		}
		for (int l649 = 0; (l649 < 2); l649 = (l649 + 1)) {
			fRec926[l649] = 0.0;
			
		}
		for (int l650 = 0; (l650 < 2); l650 = (l650 + 1)) {
			fRec934[l650] = 0.0;
			
		}
		for (int l651 = 0; (l651 < 2); l651 = (l651 + 1)) {
			fRec932[l651] = 0.0;
			
		}
		for (int l652 = 0; (l652 < 2); l652 = (l652 + 1)) {
			fRec931[l652] = 0.0;
			
		}
		for (int l653 = 0; (l653 < 2); l653 = (l653 + 1)) {
			fRec929[l653] = 0.0;
			
		}
		for (int l654 = 0; (l654 < 2); l654 = (l654 + 1)) {
			fVec19[l654] = 0.0;
			
		}
		for (int l655 = 0; (l655 < 2); l655 = (l655 + 1)) {
			fRec940[l655] = 0.0;
			
		}
		for (int l656 = 0; (l656 < 2); l656 = (l656 + 1)) {
			fRec938[l656] = 0.0;
			
		}
		for (int l657 = 0; (l657 < 2); l657 = (l657 + 1)) {
			fRec937[l657] = 0.0;
			
		}
		for (int l658 = 0; (l658 < 2); l658 = (l658 + 1)) {
			fRec935[l658] = 0.0;
			
		}
		for (int l659 = 0; (l659 < 2); l659 = (l659 + 1)) {
			fRec943[l659] = 0.0;
			
		}
		for (int l660 = 0; (l660 < 2); l660 = (l660 + 1)) {
			fRec941[l660] = 0.0;
			
		}
		for (int l661 = 0; (l661 < 2); l661 = (l661 + 1)) {
			fRec958[l661] = 0.0;
			
		}
		for (int l662 = 0; (l662 < 2); l662 = (l662 + 1)) {
			fRec956[l662] = 0.0;
			
		}
		for (int l663 = 0; (l663 < 2); l663 = (l663 + 1)) {
			fRec955[l663] = 0.0;
			
		}
		for (int l664 = 0; (l664 < 2); l664 = (l664 + 1)) {
			fRec953[l664] = 0.0;
			
		}
		for (int l665 = 0; (l665 < 2); l665 = (l665 + 1)) {
			fRec952[l665] = 0.0;
			
		}
		for (int l666 = 0; (l666 < 2); l666 = (l666 + 1)) {
			fRec950[l666] = 0.0;
			
		}
		for (int l667 = 0; (l667 < 2); l667 = (l667 + 1)) {
			fRec949[l667] = 0.0;
			
		}
		for (int l668 = 0; (l668 < 2); l668 = (l668 + 1)) {
			fRec947[l668] = 0.0;
			
		}
		for (int l669 = 0; (l669 < 2); l669 = (l669 + 1)) {
			fRec946[l669] = 0.0;
			
		}
		for (int l670 = 0; (l670 < 2); l670 = (l670 + 1)) {
			fRec944[l670] = 0.0;
			
		}
		for (int l671 = 0; (l671 < 2); l671 = (l671 + 1)) {
			fRec970[l671] = 0.0;
			
		}
		for (int l672 = 0; (l672 < 2); l672 = (l672 + 1)) {
			fRec968[l672] = 0.0;
			
		}
		for (int l673 = 0; (l673 < 2); l673 = (l673 + 1)) {
			fRec967[l673] = 0.0;
			
		}
		for (int l674 = 0; (l674 < 2); l674 = (l674 + 1)) {
			fRec965[l674] = 0.0;
			
		}
		for (int l675 = 0; (l675 < 2); l675 = (l675 + 1)) {
			fRec964[l675] = 0.0;
			
		}
		for (int l676 = 0; (l676 < 2); l676 = (l676 + 1)) {
			fRec962[l676] = 0.0;
			
		}
		for (int l677 = 0; (l677 < 2); l677 = (l677 + 1)) {
			fRec961[l677] = 0.0;
			
		}
		for (int l678 = 0; (l678 < 2); l678 = (l678 + 1)) {
			fRec959[l678] = 0.0;
			
		}
		for (int l679 = 0; (l679 < 2); l679 = (l679 + 1)) {
			fRec979[l679] = 0.0;
			
		}
		for (int l680 = 0; (l680 < 2); l680 = (l680 + 1)) {
			fRec977[l680] = 0.0;
			
		}
		for (int l681 = 0; (l681 < 2); l681 = (l681 + 1)) {
			fRec976[l681] = 0.0;
			
		}
		for (int l682 = 0; (l682 < 2); l682 = (l682 + 1)) {
			fRec974[l682] = 0.0;
			
		}
		for (int l683 = 0; (l683 < 2); l683 = (l683 + 1)) {
			fRec973[l683] = 0.0;
			
		}
		for (int l684 = 0; (l684 < 2); l684 = (l684 + 1)) {
			fRec971[l684] = 0.0;
			
		}
		for (int l685 = 0; (l685 < 2); l685 = (l685 + 1)) {
			fVec20[l685] = 0.0;
			
		}
		for (int l686 = 0; (l686 < 2); l686 = (l686 + 1)) {
			fRec994[l686] = 0.0;
			
		}
		for (int l687 = 0; (l687 < 2); l687 = (l687 + 1)) {
			fRec992[l687] = 0.0;
			
		}
		for (int l688 = 0; (l688 < 2); l688 = (l688 + 1)) {
			fRec991[l688] = 0.0;
			
		}
		for (int l689 = 0; (l689 < 2); l689 = (l689 + 1)) {
			fRec989[l689] = 0.0;
			
		}
		for (int l690 = 0; (l690 < 2); l690 = (l690 + 1)) {
			fRec988[l690] = 0.0;
			
		}
		for (int l691 = 0; (l691 < 2); l691 = (l691 + 1)) {
			fRec986[l691] = 0.0;
			
		}
		for (int l692 = 0; (l692 < 2); l692 = (l692 + 1)) {
			fRec985[l692] = 0.0;
			
		}
		for (int l693 = 0; (l693 < 2); l693 = (l693 + 1)) {
			fRec983[l693] = 0.0;
			
		}
		for (int l694 = 0; (l694 < 2); l694 = (l694 + 1)) {
			fRec982[l694] = 0.0;
			
		}
		for (int l695 = 0; (l695 < 2); l695 = (l695 + 1)) {
			fRec980[l695] = 0.0;
			
		}
		for (int l696 = 0; (l696 < 2); l696 = (l696 + 1)) {
			fRec1006[l696] = 0.0;
			
		}
		for (int l697 = 0; (l697 < 2); l697 = (l697 + 1)) {
			fRec1004[l697] = 0.0;
			
		}
		for (int l698 = 0; (l698 < 2); l698 = (l698 + 1)) {
			fRec1003[l698] = 0.0;
			
		}
		for (int l699 = 0; (l699 < 2); l699 = (l699 + 1)) {
			fRec1001[l699] = 0.0;
			
		}
		for (int l700 = 0; (l700 < 2); l700 = (l700 + 1)) {
			fRec1000[l700] = 0.0;
			
		}
		for (int l701 = 0; (l701 < 2); l701 = (l701 + 1)) {
			fRec998[l701] = 0.0;
			
		}
		for (int l702 = 0; (l702 < 2); l702 = (l702 + 1)) {
			fRec997[l702] = 0.0;
			
		}
		for (int l703 = 0; (l703 < 2); l703 = (l703 + 1)) {
			fRec995[l703] = 0.0;
			
		}
		for (int l704 = 0; (l704 < 2); l704 = (l704 + 1)) {
			fRec1015[l704] = 0.0;
			
		}
		for (int l705 = 0; (l705 < 2); l705 = (l705 + 1)) {
			fRec1013[l705] = 0.0;
			
		}
		for (int l706 = 0; (l706 < 2); l706 = (l706 + 1)) {
			fRec1012[l706] = 0.0;
			
		}
		for (int l707 = 0; (l707 < 2); l707 = (l707 + 1)) {
			fRec1010[l707] = 0.0;
			
		}
		for (int l708 = 0; (l708 < 2); l708 = (l708 + 1)) {
			fRec1009[l708] = 0.0;
			
		}
		for (int l709 = 0; (l709 < 2); l709 = (l709 + 1)) {
			fRec1007[l709] = 0.0;
			
		}
		for (int l710 = 0; (l710 < 2); l710 = (l710 + 1)) {
			fRec1018[l710] = 0.0;
			
		}
		for (int l711 = 0; (l711 < 2); l711 = (l711 + 1)) {
			fRec1016[l711] = 0.0;
			
		}
		for (int l712 = 0; (l712 < 2); l712 = (l712 + 1)) {
			fRec1024[l712] = 0.0;
			
		}
		for (int l713 = 0; (l713 < 2); l713 = (l713 + 1)) {
			fRec1022[l713] = 0.0;
			
		}
		for (int l714 = 0; (l714 < 2); l714 = (l714 + 1)) {
			fRec1021[l714] = 0.0;
			
		}
		for (int l715 = 0; (l715 < 2); l715 = (l715 + 1)) {
			fRec1019[l715] = 0.0;
			
		}
		for (int l716 = 0; (l716 < 2); l716 = (l716 + 1)) {
			fVec21[l716] = 0.0;
			
		}
		for (int l717 = 0; (l717 < 2); l717 = (l717 + 1)) {
			fRec1036[l717] = 0.0;
			
		}
		for (int l718 = 0; (l718 < 2); l718 = (l718 + 1)) {
			fRec1034[l718] = 0.0;
			
		}
		for (int l719 = 0; (l719 < 2); l719 = (l719 + 1)) {
			fRec1033[l719] = 0.0;
			
		}
		for (int l720 = 0; (l720 < 2); l720 = (l720 + 1)) {
			fRec1031[l720] = 0.0;
			
		}
		for (int l721 = 0; (l721 < 2); l721 = (l721 + 1)) {
			fRec1030[l721] = 0.0;
			
		}
		for (int l722 = 0; (l722 < 2); l722 = (l722 + 1)) {
			fRec1028[l722] = 0.0;
			
		}
		for (int l723 = 0; (l723 < 2); l723 = (l723 + 1)) {
			fRec1027[l723] = 0.0;
			
		}
		for (int l724 = 0; (l724 < 2); l724 = (l724 + 1)) {
			fRec1025[l724] = 0.0;
			
		}
		for (int l725 = 0; (l725 < 2); l725 = (l725 + 1)) {
			fRec1045[l725] = 0.0;
			
		}
		for (int l726 = 0; (l726 < 2); l726 = (l726 + 1)) {
			fRec1043[l726] = 0.0;
			
		}
		for (int l727 = 0; (l727 < 2); l727 = (l727 + 1)) {
			fRec1042[l727] = 0.0;
			
		}
		for (int l728 = 0; (l728 < 2); l728 = (l728 + 1)) {
			fRec1040[l728] = 0.0;
			
		}
		for (int l729 = 0; (l729 < 2); l729 = (l729 + 1)) {
			fRec1039[l729] = 0.0;
			
		}
		for (int l730 = 0; (l730 < 2); l730 = (l730 + 1)) {
			fRec1037[l730] = 0.0;
			
		}
		for (int l731 = 0; (l731 < 2); l731 = (l731 + 1)) {
			fRec1051[l731] = 0.0;
			
		}
		for (int l732 = 0; (l732 < 2); l732 = (l732 + 1)) {
			fRec1049[l732] = 0.0;
			
		}
		for (int l733 = 0; (l733 < 2); l733 = (l733 + 1)) {
			fRec1048[l733] = 0.0;
			
		}
		for (int l734 = 0; (l734 < 2); l734 = (l734 + 1)) {
			fRec1046[l734] = 0.0;
			
		}
		for (int l735 = 0; (l735 < 2); l735 = (l735 + 1)) {
			fRec1066[l735] = 0.0;
			
		}
		for (int l736 = 0; (l736 < 2); l736 = (l736 + 1)) {
			fRec1064[l736] = 0.0;
			
		}
		for (int l737 = 0; (l737 < 2); l737 = (l737 + 1)) {
			fRec1063[l737] = 0.0;
			
		}
		for (int l738 = 0; (l738 < 2); l738 = (l738 + 1)) {
			fRec1061[l738] = 0.0;
			
		}
		for (int l739 = 0; (l739 < 2); l739 = (l739 + 1)) {
			fRec1060[l739] = 0.0;
			
		}
		for (int l740 = 0; (l740 < 2); l740 = (l740 + 1)) {
			fRec1058[l740] = 0.0;
			
		}
		for (int l741 = 0; (l741 < 2); l741 = (l741 + 1)) {
			fRec1057[l741] = 0.0;
			
		}
		for (int l742 = 0; (l742 < 2); l742 = (l742 + 1)) {
			fRec1055[l742] = 0.0;
			
		}
		for (int l743 = 0; (l743 < 2); l743 = (l743 + 1)) {
			fRec1054[l743] = 0.0;
			
		}
		for (int l744 = 0; (l744 < 2); l744 = (l744 + 1)) {
			fRec1052[l744] = 0.0;
			
		}
		for (int l745 = 0; (l745 < 2); l745 = (l745 + 1)) {
			fRec1069[l745] = 0.0;
			
		}
		for (int l746 = 0; (l746 < 2); l746 = (l746 + 1)) {
			fRec1067[l746] = 0.0;
			
		}
		for (int l747 = 0; (l747 < 2); l747 = (l747 + 1)) {
			fVec22[l747] = 0.0;
			
		}
		for (int l748 = 0; (l748 < 2); l748 = (l748 + 1)) {
			fRec1084[l748] = 0.0;
			
		}
		for (int l749 = 0; (l749 < 2); l749 = (l749 + 1)) {
			fRec1082[l749] = 0.0;
			
		}
		for (int l750 = 0; (l750 < 2); l750 = (l750 + 1)) {
			fRec1081[l750] = 0.0;
			
		}
		for (int l751 = 0; (l751 < 2); l751 = (l751 + 1)) {
			fRec1079[l751] = 0.0;
			
		}
		for (int l752 = 0; (l752 < 2); l752 = (l752 + 1)) {
			fRec1078[l752] = 0.0;
			
		}
		for (int l753 = 0; (l753 < 2); l753 = (l753 + 1)) {
			fRec1076[l753] = 0.0;
			
		}
		for (int l754 = 0; (l754 < 2); l754 = (l754 + 1)) {
			fRec1075[l754] = 0.0;
			
		}
		for (int l755 = 0; (l755 < 2); l755 = (l755 + 1)) {
			fRec1073[l755] = 0.0;
			
		}
		for (int l756 = 0; (l756 < 2); l756 = (l756 + 1)) {
			fRec1072[l756] = 0.0;
			
		}
		for (int l757 = 0; (l757 < 2); l757 = (l757 + 1)) {
			fRec1070[l757] = 0.0;
			
		}
		for (int l758 = 0; (l758 < 2); l758 = (l758 + 1)) {
			fRec1093[l758] = 0.0;
			
		}
		for (int l759 = 0; (l759 < 2); l759 = (l759 + 1)) {
			fRec1091[l759] = 0.0;
			
		}
		for (int l760 = 0; (l760 < 2); l760 = (l760 + 1)) {
			fRec1090[l760] = 0.0;
			
		}
		for (int l761 = 0; (l761 < 2); l761 = (l761 + 1)) {
			fRec1088[l761] = 0.0;
			
		}
		for (int l762 = 0; (l762 < 2); l762 = (l762 + 1)) {
			fRec1087[l762] = 0.0;
			
		}
		for (int l763 = 0; (l763 < 2); l763 = (l763 + 1)) {
			fRec1085[l763] = 0.0;
			
		}
		for (int l764 = 0; (l764 < 2); l764 = (l764 + 1)) {
			fRec1096[l764] = 0.0;
			
		}
		for (int l765 = 0; (l765 < 2); l765 = (l765 + 1)) {
			fRec1094[l765] = 0.0;
			
		}
		for (int l766 = 0; (l766 < 2); l766 = (l766 + 1)) {
			fRec1102[l766] = 0.0;
			
		}
		for (int l767 = 0; (l767 < 2); l767 = (l767 + 1)) {
			fRec1100[l767] = 0.0;
			
		}
		for (int l768 = 0; (l768 < 2); l768 = (l768 + 1)) {
			fRec1099[l768] = 0.0;
			
		}
		for (int l769 = 0; (l769 < 2); l769 = (l769 + 1)) {
			fRec1097[l769] = 0.0;
			
		}
		for (int l770 = 0; (l770 < 2); l770 = (l770 + 1)) {
			fRec1114[l770] = 0.0;
			
		}
		for (int l771 = 0; (l771 < 2); l771 = (l771 + 1)) {
			fRec1112[l771] = 0.0;
			
		}
		for (int l772 = 0; (l772 < 2); l772 = (l772 + 1)) {
			fRec1111[l772] = 0.0;
			
		}
		for (int l773 = 0; (l773 < 2); l773 = (l773 + 1)) {
			fRec1109[l773] = 0.0;
			
		}
		for (int l774 = 0; (l774 < 2); l774 = (l774 + 1)) {
			fRec1108[l774] = 0.0;
			
		}
		for (int l775 = 0; (l775 < 2); l775 = (l775 + 1)) {
			fRec1106[l775] = 0.0;
			
		}
		for (int l776 = 0; (l776 < 2); l776 = (l776 + 1)) {
			fRec1105[l776] = 0.0;
			
		}
		for (int l777 = 0; (l777 < 2); l777 = (l777 + 1)) {
			fRec1103[l777] = 0.0;
			
		}
		for (int l778 = 0; (l778 < 2); l778 = (l778 + 1)) {
			fVec23[l778] = 0.0;
			
		}
		for (int l779 = 0; (l779 < 2); l779 = (l779 + 1)) {
			fRec1129[l779] = 0.0;
			
		}
		for (int l780 = 0; (l780 < 2); l780 = (l780 + 1)) {
			fRec1127[l780] = 0.0;
			
		}
		for (int l781 = 0; (l781 < 2); l781 = (l781 + 1)) {
			fRec1126[l781] = 0.0;
			
		}
		for (int l782 = 0; (l782 < 2); l782 = (l782 + 1)) {
			fRec1124[l782] = 0.0;
			
		}
		for (int l783 = 0; (l783 < 2); l783 = (l783 + 1)) {
			fRec1123[l783] = 0.0;
			
		}
		for (int l784 = 0; (l784 < 2); l784 = (l784 + 1)) {
			fRec1121[l784] = 0.0;
			
		}
		for (int l785 = 0; (l785 < 2); l785 = (l785 + 1)) {
			fRec1120[l785] = 0.0;
			
		}
		for (int l786 = 0; (l786 < 2); l786 = (l786 + 1)) {
			fRec1118[l786] = 0.0;
			
		}
		for (int l787 = 0; (l787 < 2); l787 = (l787 + 1)) {
			fRec1117[l787] = 0.0;
			
		}
		for (int l788 = 0; (l788 < 2); l788 = (l788 + 1)) {
			fRec1115[l788] = 0.0;
			
		}
		for (int l789 = 0; (l789 < 2); l789 = (l789 + 1)) {
			fRec1141[l789] = 0.0;
			
		}
		for (int l790 = 0; (l790 < 2); l790 = (l790 + 1)) {
			fRec1139[l790] = 0.0;
			
		}
		for (int l791 = 0; (l791 < 2); l791 = (l791 + 1)) {
			fRec1138[l791] = 0.0;
			
		}
		for (int l792 = 0; (l792 < 2); l792 = (l792 + 1)) {
			fRec1136[l792] = 0.0;
			
		}
		for (int l793 = 0; (l793 < 2); l793 = (l793 + 1)) {
			fRec1135[l793] = 0.0;
			
		}
		for (int l794 = 0; (l794 < 2); l794 = (l794 + 1)) {
			fRec1133[l794] = 0.0;
			
		}
		for (int l795 = 0; (l795 < 2); l795 = (l795 + 1)) {
			fRec1132[l795] = 0.0;
			
		}
		for (int l796 = 0; (l796 < 2); l796 = (l796 + 1)) {
			fRec1130[l796] = 0.0;
			
		}
		for (int l797 = 0; (l797 < 2); l797 = (l797 + 1)) {
			fRec1150[l797] = 0.0;
			
		}
		for (int l798 = 0; (l798 < 2); l798 = (l798 + 1)) {
			fRec1148[l798] = 0.0;
			
		}
		for (int l799 = 0; (l799 < 2); l799 = (l799 + 1)) {
			fRec1147[l799] = 0.0;
			
		}
		for (int l800 = 0; (l800 < 2); l800 = (l800 + 1)) {
			fRec1145[l800] = 0.0;
			
		}
		for (int l801 = 0; (l801 < 2); l801 = (l801 + 1)) {
			fRec1144[l801] = 0.0;
			
		}
		for (int l802 = 0; (l802 < 2); l802 = (l802 + 1)) {
			fRec1142[l802] = 0.0;
			
		}
		for (int l803 = 0; (l803 < 2); l803 = (l803 + 1)) {
			fRec1153[l803] = 0.0;
			
		}
		for (int l804 = 0; (l804 < 2); l804 = (l804 + 1)) {
			fRec1151[l804] = 0.0;
			
		}
		for (int l805 = 0; (l805 < 2); l805 = (l805 + 1)) {
			fRec1159[l805] = 0.0;
			
		}
		for (int l806 = 0; (l806 < 2); l806 = (l806 + 1)) {
			fRec1157[l806] = 0.0;
			
		}
		for (int l807 = 0; (l807 < 2); l807 = (l807 + 1)) {
			fRec1156[l807] = 0.0;
			
		}
		for (int l808 = 0; (l808 < 2); l808 = (l808 + 1)) {
			fRec1154[l808] = 0.0;
			
		}
		for (int l809 = 0; (l809 < 512); l809 = (l809 + 1)) {
			fVec24[l809] = 0.0;
			
		}
		for (int l810 = 0; (l810 < 2); l810 = (l810 + 1)) {
			fRec1174[l810] = 0.0;
			
		}
		for (int l811 = 0; (l811 < 2); l811 = (l811 + 1)) {
			fRec1172[l811] = 0.0;
			
		}
		for (int l812 = 0; (l812 < 2); l812 = (l812 + 1)) {
			fRec1171[l812] = 0.0;
			
		}
		for (int l813 = 0; (l813 < 2); l813 = (l813 + 1)) {
			fRec1169[l813] = 0.0;
			
		}
		for (int l814 = 0; (l814 < 2); l814 = (l814 + 1)) {
			fRec1168[l814] = 0.0;
			
		}
		for (int l815 = 0; (l815 < 2); l815 = (l815 + 1)) {
			fRec1166[l815] = 0.0;
			
		}
		for (int l816 = 0; (l816 < 2); l816 = (l816 + 1)) {
			fRec1165[l816] = 0.0;
			
		}
		for (int l817 = 0; (l817 < 2); l817 = (l817 + 1)) {
			fRec1163[l817] = 0.0;
			
		}
		for (int l818 = 0; (l818 < 2); l818 = (l818 + 1)) {
			fRec1162[l818] = 0.0;
			
		}
		for (int l819 = 0; (l819 < 2); l819 = (l819 + 1)) {
			fRec1160[l819] = 0.0;
			
		}
		for (int l820 = 0; (l820 < 2); l820 = (l820 + 1)) {
			fRec1177[l820] = 0.0;
			
		}
		for (int l821 = 0; (l821 < 2); l821 = (l821 + 1)) {
			fRec1175[l821] = 0.0;
			
		}
		for (int l822 = 0; (l822 < 2); l822 = (l822 + 1)) {
			fRec1183[l822] = 0.0;
			
		}
		for (int l823 = 0; (l823 < 2); l823 = (l823 + 1)) {
			fRec1181[l823] = 0.0;
			
		}
		for (int l824 = 0; (l824 < 2); l824 = (l824 + 1)) {
			fRec1180[l824] = 0.0;
			
		}
		for (int l825 = 0; (l825 < 2); l825 = (l825 + 1)) {
			fRec1178[l825] = 0.0;
			
		}
		for (int l826 = 0; (l826 < 2); l826 = (l826 + 1)) {
			fRec1192[l826] = 0.0;
			
		}
		for (int l827 = 0; (l827 < 2); l827 = (l827 + 1)) {
			fRec1190[l827] = 0.0;
			
		}
		for (int l828 = 0; (l828 < 2); l828 = (l828 + 1)) {
			fRec1189[l828] = 0.0;
			
		}
		for (int l829 = 0; (l829 < 2); l829 = (l829 + 1)) {
			fRec1187[l829] = 0.0;
			
		}
		for (int l830 = 0; (l830 < 2); l830 = (l830 + 1)) {
			fRec1186[l830] = 0.0;
			
		}
		for (int l831 = 0; (l831 < 2); l831 = (l831 + 1)) {
			fRec1184[l831] = 0.0;
			
		}
		for (int l832 = 0; (l832 < 2); l832 = (l832 + 1)) {
			fRec1204[l832] = 0.0;
			
		}
		for (int l833 = 0; (l833 < 2); l833 = (l833 + 1)) {
			fRec1202[l833] = 0.0;
			
		}
		for (int l834 = 0; (l834 < 2); l834 = (l834 + 1)) {
			fRec1201[l834] = 0.0;
			
		}
		for (int l835 = 0; (l835 < 2); l835 = (l835 + 1)) {
			fRec1199[l835] = 0.0;
			
		}
		for (int l836 = 0; (l836 < 2); l836 = (l836 + 1)) {
			fRec1198[l836] = 0.0;
			
		}
		for (int l837 = 0; (l837 < 2); l837 = (l837 + 1)) {
			fRec1196[l837] = 0.0;
			
		}
		for (int l838 = 0; (l838 < 2); l838 = (l838 + 1)) {
			fRec1195[l838] = 0.0;
			
		}
		for (int l839 = 0; (l839 < 2); l839 = (l839 + 1)) {
			fRec1193[l839] = 0.0;
			
		}
		for (int l840 = 0; (l840 < 512); l840 = (l840 + 1)) {
			fVec25[l840] = 0.0;
			
		}
		for (int l841 = 0; (l841 < 2); l841 = (l841 + 1)) {
			fRec1216[l841] = 0.0;
			
		}
		for (int l842 = 0; (l842 < 2); l842 = (l842 + 1)) {
			fRec1214[l842] = 0.0;
			
		}
		for (int l843 = 0; (l843 < 2); l843 = (l843 + 1)) {
			fRec1213[l843] = 0.0;
			
		}
		for (int l844 = 0; (l844 < 2); l844 = (l844 + 1)) {
			fRec1211[l844] = 0.0;
			
		}
		for (int l845 = 0; (l845 < 2); l845 = (l845 + 1)) {
			fRec1210[l845] = 0.0;
			
		}
		for (int l846 = 0; (l846 < 2); l846 = (l846 + 1)) {
			fRec1208[l846] = 0.0;
			
		}
		for (int l847 = 0; (l847 < 2); l847 = (l847 + 1)) {
			fRec1207[l847] = 0.0;
			
		}
		for (int l848 = 0; (l848 < 2); l848 = (l848 + 1)) {
			fRec1205[l848] = 0.0;
			
		}
		for (int l849 = 0; (l849 < 2); l849 = (l849 + 1)) {
			fRec1225[l849] = 0.0;
			
		}
		for (int l850 = 0; (l850 < 2); l850 = (l850 + 1)) {
			fRec1223[l850] = 0.0;
			
		}
		for (int l851 = 0; (l851 < 2); l851 = (l851 + 1)) {
			fRec1222[l851] = 0.0;
			
		}
		for (int l852 = 0; (l852 < 2); l852 = (l852 + 1)) {
			fRec1220[l852] = 0.0;
			
		}
		for (int l853 = 0; (l853 < 2); l853 = (l853 + 1)) {
			fRec1219[l853] = 0.0;
			
		}
		for (int l854 = 0; (l854 < 2); l854 = (l854 + 1)) {
			fRec1217[l854] = 0.0;
			
		}
		for (int l855 = 0; (l855 < 2); l855 = (l855 + 1)) {
			fRec1228[l855] = 0.0;
			
		}
		for (int l856 = 0; (l856 < 2); l856 = (l856 + 1)) {
			fRec1226[l856] = 0.0;
			
		}
		for (int l857 = 0; (l857 < 2); l857 = (l857 + 1)) {
			fRec1234[l857] = 0.0;
			
		}
		for (int l858 = 0; (l858 < 2); l858 = (l858 + 1)) {
			fRec1232[l858] = 0.0;
			
		}
		for (int l859 = 0; (l859 < 2); l859 = (l859 + 1)) {
			fRec1231[l859] = 0.0;
			
		}
		for (int l860 = 0; (l860 < 2); l860 = (l860 + 1)) {
			fRec1229[l860] = 0.0;
			
		}
		for (int l861 = 0; (l861 < 2); l861 = (l861 + 1)) {
			fRec1249[l861] = 0.0;
			
		}
		for (int l862 = 0; (l862 < 2); l862 = (l862 + 1)) {
			fRec1247[l862] = 0.0;
			
		}
		for (int l863 = 0; (l863 < 2); l863 = (l863 + 1)) {
			fRec1246[l863] = 0.0;
			
		}
		for (int l864 = 0; (l864 < 2); l864 = (l864 + 1)) {
			fRec1244[l864] = 0.0;
			
		}
		for (int l865 = 0; (l865 < 2); l865 = (l865 + 1)) {
			fRec1243[l865] = 0.0;
			
		}
		for (int l866 = 0; (l866 < 2); l866 = (l866 + 1)) {
			fRec1241[l866] = 0.0;
			
		}
		for (int l867 = 0; (l867 < 2); l867 = (l867 + 1)) {
			fRec1240[l867] = 0.0;
			
		}
		for (int l868 = 0; (l868 < 2); l868 = (l868 + 1)) {
			fRec1238[l868] = 0.0;
			
		}
		for (int l869 = 0; (l869 < 2); l869 = (l869 + 1)) {
			fRec1237[l869] = 0.0;
			
		}
		for (int l870 = 0; (l870 < 2); l870 = (l870 + 1)) {
			fRec1235[l870] = 0.0;
			
		}
		for (int l871 = 0; (l871 < 512); l871 = (l871 + 1)) {
			fVec26[l871] = 0.0;
			
		}
		for (int l872 = 0; (l872 < 2); l872 = (l872 + 1)) {
			fRec1252[l872] = 0.0;
			
		}
		for (int l873 = 0; (l873 < 2); l873 = (l873 + 1)) {
			fRec1250[l873] = 0.0;
			
		}
		for (int l874 = 0; (l874 < 2); l874 = (l874 + 1)) {
			fRec1258[l874] = 0.0;
			
		}
		for (int l875 = 0; (l875 < 2); l875 = (l875 + 1)) {
			fRec1256[l875] = 0.0;
			
		}
		for (int l876 = 0; (l876 < 2); l876 = (l876 + 1)) {
			fRec1255[l876] = 0.0;
			
		}
		for (int l877 = 0; (l877 < 2); l877 = (l877 + 1)) {
			fRec1253[l877] = 0.0;
			
		}
		for (int l878 = 0; (l878 < 2); l878 = (l878 + 1)) {
			fRec1267[l878] = 0.0;
			
		}
		for (int l879 = 0; (l879 < 2); l879 = (l879 + 1)) {
			fRec1265[l879] = 0.0;
			
		}
		for (int l880 = 0; (l880 < 2); l880 = (l880 + 1)) {
			fRec1264[l880] = 0.0;
			
		}
		for (int l881 = 0; (l881 < 2); l881 = (l881 + 1)) {
			fRec1262[l881] = 0.0;
			
		}
		for (int l882 = 0; (l882 < 2); l882 = (l882 + 1)) {
			fRec1261[l882] = 0.0;
			
		}
		for (int l883 = 0; (l883 < 2); l883 = (l883 + 1)) {
			fRec1259[l883] = 0.0;
			
		}
		for (int l884 = 0; (l884 < 2); l884 = (l884 + 1)) {
			fRec1279[l884] = 0.0;
			
		}
		for (int l885 = 0; (l885 < 2); l885 = (l885 + 1)) {
			fRec1277[l885] = 0.0;
			
		}
		for (int l886 = 0; (l886 < 2); l886 = (l886 + 1)) {
			fRec1276[l886] = 0.0;
			
		}
		for (int l887 = 0; (l887 < 2); l887 = (l887 + 1)) {
			fRec1274[l887] = 0.0;
			
		}
		for (int l888 = 0; (l888 < 2); l888 = (l888 + 1)) {
			fRec1273[l888] = 0.0;
			
		}
		for (int l889 = 0; (l889 < 2); l889 = (l889 + 1)) {
			fRec1271[l889] = 0.0;
			
		}
		for (int l890 = 0; (l890 < 2); l890 = (l890 + 1)) {
			fRec1270[l890] = 0.0;
			
		}
		for (int l891 = 0; (l891 < 2); l891 = (l891 + 1)) {
			fRec1268[l891] = 0.0;
			
		}
		for (int l892 = 0; (l892 < 2); l892 = (l892 + 1)) {
			fRec1294[l892] = 0.0;
			
		}
		for (int l893 = 0; (l893 < 2); l893 = (l893 + 1)) {
			fRec1292[l893] = 0.0;
			
		}
		for (int l894 = 0; (l894 < 2); l894 = (l894 + 1)) {
			fRec1291[l894] = 0.0;
			
		}
		for (int l895 = 0; (l895 < 2); l895 = (l895 + 1)) {
			fRec1289[l895] = 0.0;
			
		}
		for (int l896 = 0; (l896 < 2); l896 = (l896 + 1)) {
			fRec1288[l896] = 0.0;
			
		}
		for (int l897 = 0; (l897 < 2); l897 = (l897 + 1)) {
			fRec1286[l897] = 0.0;
			
		}
		for (int l898 = 0; (l898 < 2); l898 = (l898 + 1)) {
			fRec1285[l898] = 0.0;
			
		}
		for (int l899 = 0; (l899 < 2); l899 = (l899 + 1)) {
			fRec1283[l899] = 0.0;
			
		}
		for (int l900 = 0; (l900 < 2); l900 = (l900 + 1)) {
			fRec1282[l900] = 0.0;
			
		}
		for (int l901 = 0; (l901 < 2); l901 = (l901 + 1)) {
			fRec1280[l901] = 0.0;
			
		}
		for (int l902 = 0; (l902 < 512); l902 = (l902 + 1)) {
			fVec27[l902] = 0.0;
			
		}
		for (int l903 = 0; (l903 < 2); l903 = (l903 + 1)) {
			fRec1297[l903] = 0.0;
			
		}
		for (int l904 = 0; (l904 < 2); l904 = (l904 + 1)) {
			fRec1295[l904] = 0.0;
			
		}
		for (int l905 = 0; (l905 < 2); l905 = (l905 + 1)) {
			fRec1303[l905] = 0.0;
			
		}
		for (int l906 = 0; (l906 < 2); l906 = (l906 + 1)) {
			fRec1301[l906] = 0.0;
			
		}
		for (int l907 = 0; (l907 < 2); l907 = (l907 + 1)) {
			fRec1300[l907] = 0.0;
			
		}
		for (int l908 = 0; (l908 < 2); l908 = (l908 + 1)) {
			fRec1298[l908] = 0.0;
			
		}
		for (int l909 = 0; (l909 < 2); l909 = (l909 + 1)) {
			fRec1312[l909] = 0.0;
			
		}
		for (int l910 = 0; (l910 < 2); l910 = (l910 + 1)) {
			fRec1310[l910] = 0.0;
			
		}
		for (int l911 = 0; (l911 < 2); l911 = (l911 + 1)) {
			fRec1309[l911] = 0.0;
			
		}
		for (int l912 = 0; (l912 < 2); l912 = (l912 + 1)) {
			fRec1307[l912] = 0.0;
			
		}
		for (int l913 = 0; (l913 < 2); l913 = (l913 + 1)) {
			fRec1306[l913] = 0.0;
			
		}
		for (int l914 = 0; (l914 < 2); l914 = (l914 + 1)) {
			fRec1304[l914] = 0.0;
			
		}
		for (int l915 = 0; (l915 < 2); l915 = (l915 + 1)) {
			fRec1324[l915] = 0.0;
			
		}
		for (int l916 = 0; (l916 < 2); l916 = (l916 + 1)) {
			fRec1322[l916] = 0.0;
			
		}
		for (int l917 = 0; (l917 < 2); l917 = (l917 + 1)) {
			fRec1321[l917] = 0.0;
			
		}
		for (int l918 = 0; (l918 < 2); l918 = (l918 + 1)) {
			fRec1319[l918] = 0.0;
			
		}
		for (int l919 = 0; (l919 < 2); l919 = (l919 + 1)) {
			fRec1318[l919] = 0.0;
			
		}
		for (int l920 = 0; (l920 < 2); l920 = (l920 + 1)) {
			fRec1316[l920] = 0.0;
			
		}
		for (int l921 = 0; (l921 < 2); l921 = (l921 + 1)) {
			fRec1315[l921] = 0.0;
			
		}
		for (int l922 = 0; (l922 < 2); l922 = (l922 + 1)) {
			fRec1313[l922] = 0.0;
			
		}
		for (int l923 = 0; (l923 < 2); l923 = (l923 + 1)) {
			fRec1339[l923] = 0.0;
			
		}
		for (int l924 = 0; (l924 < 2); l924 = (l924 + 1)) {
			fRec1337[l924] = 0.0;
			
		}
		for (int l925 = 0; (l925 < 2); l925 = (l925 + 1)) {
			fRec1336[l925] = 0.0;
			
		}
		for (int l926 = 0; (l926 < 2); l926 = (l926 + 1)) {
			fRec1334[l926] = 0.0;
			
		}
		for (int l927 = 0; (l927 < 2); l927 = (l927 + 1)) {
			fRec1333[l927] = 0.0;
			
		}
		for (int l928 = 0; (l928 < 2); l928 = (l928 + 1)) {
			fRec1331[l928] = 0.0;
			
		}
		for (int l929 = 0; (l929 < 2); l929 = (l929 + 1)) {
			fRec1330[l929] = 0.0;
			
		}
		for (int l930 = 0; (l930 < 2); l930 = (l930 + 1)) {
			fRec1328[l930] = 0.0;
			
		}
		for (int l931 = 0; (l931 < 2); l931 = (l931 + 1)) {
			fRec1327[l931] = 0.0;
			
		}
		for (int l932 = 0; (l932 < 2); l932 = (l932 + 1)) {
			fRec1325[l932] = 0.0;
			
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
		ui_interface->openVerticalBox("KMHLS_Dome_5h3v_normal_4");
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
		double fSlow0 = (0.0010000000000000009 * (double((double(fCheckbox0) < 0.5)) * std::pow(10.0, (0.050000000000000003 * double(fHslider0)))));
		double fSlow1 = (0.0010000000000000009 * double(fHslider1));
		double fSlow2 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fHslider2))));
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec0[0] = (fSlow0 + (0.999 * fRec0[1]));
			double fTemp0 = (fConst3 * fRec1[1]);
			fRec11[0] = (fSlow1 + (0.999 * fRec11[1]));
			double fTemp1 = std::tan((fConst6 * fRec11[0]));
			double fTemp2 = ((fTemp1 * (fTemp1 + -2.0)) + 1.0);
			double fTemp3 = mydsp_faustpower2_f(fTemp1);
			double fTemp4 = (fTemp3 + -1.0);
			double fTemp5 = ((fTemp1 * (fTemp1 + 2.0)) + 1.0);
			fRec10[0] = (double(input10[i]) - (((fRec10[2] * fTemp2) + (2.0 * (fRec10[1] * fTemp4))) / fTemp5));
			fRec12[0] = (fSlow2 + (0.999 * fRec12[1]));
			double fTemp6 = (fRec12[0] * fTemp5);
			double fTemp7 = (0.0 - (2.0 / fTemp5));
			double fTemp8 = ((((fRec10[2] + (fRec10[0] + (2.0 * fRec10[1]))) * fTemp3) / fTemp6) + (1.0034039079999999 * (fRec12[0] * (0.0 - ((fRec10[1] * fTemp7) + ((fRec10[0] + fRec10[2]) / fTemp5))))));
			fRec13[0] = (double(input11[i]) - (((fRec13[2] * fTemp2) + (2.0 * (fRec13[1] * fTemp4))) / fTemp5));
			double fTemp9 = ((((fRec13[2] + (fRec13[0] + (2.0 * fRec13[1]))) * fTemp3) / fTemp6) + (1.0034039079999999 * (fRec12[0] * (0.0 - ((fRec13[1] * fTemp7) + ((fRec13[0] + fRec13[2]) / fTemp5))))));
			fRec14[0] = (double(input12[i]) - (((fRec14[2] * fTemp2) + (2.0 * (fRec14[1] * fTemp4))) / fTemp5));
			double fTemp10 = ((((fRec14[2] + (fRec14[0] + (2.0 * fRec14[1]))) * fTemp3) / fTemp6) + (1.0034039079999999 * (fRec12[0] * (0.0 - ((fRec14[1] * fTemp7) + ((fRec14[0] + fRec14[2]) / fTemp5))))));
			fRec15[0] = (double(input13[i]) - (((fRec15[2] * fTemp2) + (2.0 * (fRec15[1] * fTemp4))) / fTemp5));
			double fTemp11 = ((((fRec15[2] + (fRec15[0] + (2.0 * fRec15[1]))) * fTemp3) / fTemp6) + (1.0034039079999999 * (fRec12[0] * (0.0 - ((fRec15[1] * fTemp7) + ((fRec15[0] + fRec15[2]) / fTemp5))))));
			fRec16[0] = (double(input14[i]) - (((fRec16[2] * fTemp2) + (2.0 * (fRec16[1] * fTemp4))) / fTemp5));
			double fTemp12 = ((((fRec16[2] + (fRec16[0] + (2.0 * fRec16[1]))) * fTemp3) / fTemp6) + (1.0034039079999999 * (fRec12[0] * (0.0 - ((fRec16[1] * fTemp7) + ((fRec16[0] + fRec16[2]) / fTemp5))))));
			fRec17[0] = (double(input15[i]) - (((fRec17[2] * fTemp2) + (2.0 * (fRec17[1] * fTemp4))) / fTemp5));
			double fTemp13 = ((((fRec17[2] + (fRec17[0] + (2.0 * fRec17[1]))) * fTemp3) / fTemp6) + (1.0034039079999999 * (fRec12[0] * (0.0 - ((fRec17[1] * fTemp7) + ((fRec17[0] + fRec17[2]) / fTemp5))))));
			fRec18[0] = (double(input9[i]) - (((fRec18[2] * fTemp2) + (2.0 * (fRec18[1] * fTemp4))) / fTemp5));
			double fTemp14 = ((((fRec18[2] + (fRec18[0] + (2.0 * fRec18[1]))) * fTemp3) / fTemp6) + (1.0034039079999999 * (fRec12[0] * (0.0 - ((fRec18[1] * fTemp7) + ((fRec18[0] + fRec18[2]) / fTemp5))))));
			double fTemp15 = (fConst5 * (((((((342396534500000.0 * fTemp8) + (29837546950000.0 * fTemp9)) + (7278900684000.0 * fTemp10)) + (39493874780000.0 * fTemp11)) + (52493813120000.0 * fTemp12)) + (185612881100000.0 * fTemp13)) - (90024083840000.0 * fTemp14)));
			double fTemp16 = (fConst8 * fRec4[1]);
			double fTemp17 = (fConst9 * fRec7[1]);
			fRec9[0] = (fTemp15 + (fTemp16 + (fRec9[1] + fTemp17)));
			fRec7[0] = fRec9[0];
			double fRec8 = ((fTemp17 + fTemp16) + fTemp15);
			fRec6[0] = (fRec7[0] + fRec6[1]);
			fRec4[0] = fRec6[0];
			double fRec5 = fRec8;
			fRec3[0] = (fTemp0 + (fRec5 + fRec3[1]));
			fRec1[0] = fRec3[0];
			double fRec2 = (fRec5 + fTemp0);
			fRec25[0] = (double(input4[i]) - (((fTemp2 * fRec25[2]) + (2.0 * (fTemp4 * fRec25[1]))) / fTemp5));
			double fTemp18 = ((1.2844994489999999 * (fRec12[0] * (0.0 - ((fTemp7 * fRec25[1]) + ((fRec25[0] + fRec25[2]) / fTemp5))))) + ((fTemp3 * (fRec25[2] + (fRec25[0] + (2.0 * fRec25[1])))) / fTemp6));
			fRec26[0] = (double(input5[i]) - (((fRec26[2] * fTemp2) + (2.0 * (fRec26[1] * fTemp4))) / fTemp5));
			double fTemp19 = ((((fRec26[2] + (fRec26[0] + (2.0 * fRec26[1]))) * fTemp3) / fTemp6) + (1.2844994489999999 * (fRec12[0] * (0.0 - ((fRec26[1] * fTemp7) + ((fRec26[0] + fRec26[2]) / fTemp5))))));
			fRec27[0] = (double(input6[i]) - (((fRec27[2] * fTemp2) + (2.0 * (fRec27[1] * fTemp4))) / fTemp5));
			double fTemp20 = ((((fRec27[2] + (fRec27[0] + (2.0 * fRec27[1]))) * fTemp3) / fTemp6) + (1.2844994489999999 * (fRec12[0] * (0.0 - ((fRec27[1] * fTemp7) + ((fRec27[0] + fRec27[2]) / fTemp5))))));
			fRec28[0] = (double(input7[i]) - (((fRec28[2] * fTemp2) + (2.0 * (fRec28[1] * fTemp4))) / fTemp5));
			double fTemp21 = ((((fRec28[2] + (fRec28[0] + (2.0 * fRec28[1]))) * fTemp3) / fTemp6) + (1.2844994489999999 * (fRec12[0] * (0.0 - ((fRec28[1] * fTemp7) + ((fRec28[0] + fRec28[2]) / fTemp5))))));
			fRec29[0] = (double(input8[i]) - (((2.0 * (fRec29[1] * fTemp4)) + (fRec29[2] * fTemp2)) / fTemp5));
			double fTemp22 = ((((fRec29[2] + (fRec29[0] + (2.0 * fRec29[1]))) * fTemp3) / fTemp6) + (1.2844994489999999 * (fRec12[0] * (0.0 - ((fRec29[1] * fTemp7) + ((fRec29[0] + fRec29[2]) / fTemp5))))));
			double fTemp23 = (fConst11 * (0.0 - (((((183133489600000.0 * fTemp18) + (64494636600000.0 * fTemp19)) + (7574794675000.0 * fTemp20)) + (99160530510000.0 * fTemp21)) + (68584812180000.0 * fTemp22))));
			double fTemp24 = (fConst12 * fRec22[1]);
			double fTemp25 = (fConst13 * fRec19[1]);
			fRec24[0] = (((fTemp23 + fRec24[1]) + fTemp24) + fTemp25);
			fRec22[0] = fRec24[0];
			double fRec23 = ((fTemp23 + fTemp24) + fTemp25);
			fRec21[0] = (fRec22[0] + fRec21[1]);
			fRec19[0] = fRec21[0];
			double fRec20 = fRec23;
			fRec33[0] = (double(input1[i]) - (((fTemp2 * fRec33[2]) + (2.0 * (fTemp4 * fRec33[1]))) / fTemp5));
			double fTemp26 = (((fTemp3 * (fRec33[2] + (fRec33[0] + (2.0 * fRec33[1])))) / fTemp6) + (1.4892855819999999 * (fRec12[0] * (0.0 - ((fTemp7 * fRec33[1]) + ((fRec33[0] + fRec33[2]) / fTemp5))))));
			fRec34[0] = (double(input3[i]) - (((fTemp2 * fRec34[2]) + (2.0 * (fTemp4 * fRec34[1]))) / fTemp5));
			double fTemp27 = (((fTemp3 * (fRec34[2] + (fRec34[0] + (2.0 * fRec34[1])))) / fTemp6) + (1.4892855819999999 * (fRec12[0] * (0.0 - ((fTemp7 * fRec34[1]) + ((fRec34[0] + fRec34[2]) / fTemp5))))));
			fRec35[0] = (double(input2[i]) - (((fTemp2 * fRec35[2]) + (2.0 * (fTemp4 * fRec35[1]))) / fTemp5));
			double fTemp28 = (((fTemp3 * (fRec35[2] + (fRec35[0] + (2.0 * fRec35[1])))) / fTemp6) + (1.4892855819999999 * (fRec12[0] * (0.0 - ((fTemp7 * fRec35[1]) + ((fRec35[0] + fRec35[2]) / fTemp5))))));
			double fTemp29 = (fConst15 * (((70826771490000.0 * fTemp26) + (109476521800000.0 * fTemp27)) - (47871497790000.0 * fTemp28)));
			double fTemp30 = (fConst16 * fRec30[1]);
			fRec32[0] = (fTemp29 + (fRec32[1] + fTemp30));
			fRec30[0] = fRec32[0];
			double fRec31 = (fTemp30 + fTemp29);
			fRec48[0] = (double(input16[i]) - (((fRec48[2] * fTemp2) + (2.0 * (fRec48[1] * fTemp4))) / fTemp5));
			double fTemp31 = ((((fRec48[2] + (fRec48[0] + (2.0 * fRec48[1]))) * fTemp3) / fTemp6) + (0.67400163359999998 * (fRec12[0] * (0.0 - ((fRec48[1] * fTemp7) + ((fRec48[0] + fRec48[2]) / fTemp5))))));
			fRec49[0] = (double(input17[i]) - (((fRec49[2] * fTemp2) + (2.0 * (fRec49[1] * fTemp4))) / fTemp5));
			double fTemp32 = ((((fRec49[2] + (fRec49[0] + (2.0 * fRec49[1]))) * fTemp3) / fTemp6) + (0.67400163359999998 * (fRec12[0] * (0.0 - ((fRec49[1] * fTemp7) + ((fRec49[0] + fRec49[2]) / fTemp5))))));
			fRec50[0] = (double(input24[i]) - (((fRec50[2] * fTemp2) + (2.0 * (fRec50[1] * fTemp4))) / fTemp5));
			double fTemp33 = ((((fRec50[2] + (fRec50[0] + (2.0 * fRec50[1]))) * fTemp3) / fTemp6) + (0.67400163359999998 * (fRec12[0] * (0.0 - ((fRec50[1] * fTemp7) + ((fRec50[0] + fRec50[2]) / fTemp5))))));
			fRec51[0] = (double(input18[i]) - (((fRec51[2] * fTemp2) + (2.0 * (fRec51[1] * fTemp4))) / fTemp5));
			double fTemp34 = ((((fRec51[2] + (fRec51[0] + (2.0 * fRec51[1]))) * fTemp3) / fTemp6) + (0.67400163359999998 * (fRec12[0] * (0.0 - ((fRec51[1] * fTemp7) + ((fRec51[0] + fRec51[2]) / fTemp5))))));
			fRec52[0] = (double(input19[i]) - (((fRec52[2] * fTemp2) + (2.0 * (fRec52[1] * fTemp4))) / fTemp5));
			double fTemp35 = ((((fRec52[2] + (fRec52[0] + (2.0 * fRec52[1]))) * fTemp3) / fTemp6) + (0.67400163359999998 * (fRec12[0] * (0.0 - ((fRec52[1] * fTemp7) + ((fRec52[0] + fRec52[2]) / fTemp5))))));
			fRec53[0] = (double(input21[i]) - (((fRec53[2] * fTemp2) + (2.0 * (fRec53[1] * fTemp4))) / fTemp5));
			double fTemp36 = ((((fRec53[2] + (fRec53[0] + (2.0 * fRec53[1]))) * fTemp3) / fTemp6) + (0.67400163359999998 * (fRec12[0] * (0.0 - ((fRec53[1] * fTemp7) + ((fRec53[0] + fRec53[2]) / fTemp5))))));
			fRec54[0] = (double(input22[i]) - (((fRec54[2] * fTemp2) + (2.0 * (fRec54[1] * fTemp4))) / fTemp5));
			double fTemp37 = ((((fRec54[2] + (fRec54[0] + (2.0 * fRec54[1]))) * fTemp3) / fTemp6) + (0.67400163359999998 * (fRec12[0] * (0.0 - ((fRec54[1] * fTemp7) + ((fRec54[0] + fRec54[2]) / fTemp5))))));
			fRec55[0] = (double(input23[i]) - (((fRec55[2] * fTemp2) + (2.0 * (fRec55[1] * fTemp4))) / fTemp5));
			double fTemp38 = ((((fRec55[2] + (fRec55[0] + (2.0 * fRec55[1]))) * fTemp3) / fTemp6) + (0.67400163359999998 * (fRec12[0] * (0.0 - ((fRec55[1] * fTemp7) + ((fRec55[0] + fRec55[2]) / fTemp5))))));
			double fTemp39 = (fConst19 * ((((48170581170000.0 * fTemp31) + (191468364700000.0 * fTemp32)) + (38909559130000.0 * fTemp33)) - (((((261031808100000.0 * fTemp34) + (8706489479000.0 * fTemp35)) + (18889165450000.0 * fTemp36)) + (29663027710000.0 * fTemp37)) + (239174555800000.0 * fTemp38))));
			double fTemp40 = (fConst20 * fRec42[1]);
			double fTemp41 = (fConst21 * fRec45[1]);
			fRec47[0] = (fTemp39 + (fTemp40 + (fRec47[1] + fTemp41)));
			fRec45[0] = fRec47[0];
			double fRec46 = ((fTemp41 + fTemp40) + fTemp39);
			fRec44[0] = (fRec45[0] + fRec44[1]);
			fRec42[0] = fRec44[0];
			double fRec43 = fRec46;
			double fTemp42 = (fRec43 + (fConst22 * fRec36[1]));
			double fTemp43 = (fConst23 * fRec39[1]);
			fRec41[0] = ((fTemp42 + fRec41[1]) + fTemp43);
			fRec39[0] = fRec41[0];
			double fRec40 = (fTemp42 + fTemp43);
			fRec38[0] = (fRec39[0] + fRec38[1]);
			fRec36[0] = fRec38[0];
			double fRec37 = fRec40;
			double fTemp44 = (fConst25 * fRec56[1]);
			double fTemp45 = (fConst27 * fRec59[1]);
			double fTemp46 = (fConst28 * fRec62[1]);
			fRec71[0] = (double(input25[i]) - (((fRec71[2] * fTemp2) + (2.0 * (fRec71[1] * fTemp4))) / fTemp5));
			double fTemp47 = ((((fRec71[2] + (fRec71[0] + (2.0 * fRec71[1]))) * fTemp3) / fTemp6) + (0.32855163009999999 * (fRec12[0] * (0.0 - ((fRec71[1] * fTemp7) + ((fRec71[0] + fRec71[2]) / fTemp5))))));
			fRec72[0] = (double(input26[i]) - (((fRec72[2] * fTemp2) + (2.0 * (fRec72[1] * fTemp4))) / fTemp5));
			double fTemp48 = ((((fRec72[2] + (fRec72[0] + (2.0 * fRec72[1]))) * fTemp3) / fTemp6) + (0.32855163009999999 * (fRec12[0] * (0.0 - ((fRec72[1] * fTemp7) + ((fRec72[0] + fRec72[2]) / fTemp5))))));
			fRec73[0] = (double(input28[i]) - (((fRec73[2] * fTemp2) + (2.0 * (fRec73[1] * fTemp4))) / fTemp5));
			double fTemp49 = ((((fRec73[2] + (fRec73[0] + (2.0 * fRec73[1]))) * fTemp3) / fTemp6) + (0.32855163009999999 * (fRec12[0] * (0.0 - ((fRec73[1] * fTemp7) + ((fRec73[0] + fRec73[2]) / fTemp5))))));
			fRec74[0] = (double(input33[i]) - (((fRec74[2] * fTemp2) + (2.0 * (fRec74[1] * fTemp4))) / fTemp5));
			double fTemp50 = ((((fRec74[2] + (fRec74[0] + (2.0 * fRec74[1]))) * fTemp3) / fTemp6) + (0.32855163009999999 * (fRec12[0] * (0.0 - ((fRec74[1] * fTemp7) + ((fRec74[0] + fRec74[2]) / fTemp5))))));
			fRec75[0] = (double(input27[i]) - (((fRec75[2] * fTemp2) + (2.0 * (fRec75[1] * fTemp4))) / fTemp5));
			double fTemp51 = ((((fRec75[2] + (fRec75[0] + (2.0 * fRec75[1]))) * fTemp3) / fTemp6) + (0.32855163009999999 * (fRec12[0] * (0.0 - ((fRec75[1] * fTemp7) + ((fRec75[0] + fRec75[2]) / fTemp5))))));
			fRec76[0] = (double(input32[i]) - (((fRec76[2] * fTemp2) + (2.0 * (fRec76[1] * fTemp4))) / fTemp5));
			double fTemp52 = ((((fRec76[2] + (fRec76[0] + (2.0 * fRec76[1]))) * fTemp3) / fTemp6) + (0.32855163009999999 * (fRec12[0] * (0.0 - ((fRec76[1] * fTemp7) + ((fRec76[0] + fRec76[2]) / fTemp5))))));
			fRec77[0] = (double(input34[i]) - (((fRec77[2] * fTemp2) + (2.0 * (fRec77[1] * fTemp4))) / fTemp5));
			double fTemp53 = ((((fRec77[2] + (fRec77[0] + (2.0 * fRec77[1]))) * fTemp3) / fTemp6) + (0.32855163009999999 * (fRec12[0] * (0.0 - ((fRec77[1] * fTemp7) + ((fRec77[0] + fRec77[2]) / fTemp5))))));
			fRec78[0] = (double(input35[i]) - (((fRec78[2] * fTemp2) + (2.0 * (fRec78[1] * fTemp4))) / fTemp5));
			double fTemp54 = ((((fRec78[2] + (fRec78[0] + (2.0 * fRec78[1]))) * fTemp3) / fTemp6) + (0.32855163009999999 * (fRec12[0] * (0.0 - ((fRec78[1] * fTemp7) + ((fRec78[0] + fRec78[2]) / fTemp5))))));
			double fTemp55 = (fConst30 * (((((31750470320000.0 * fTemp47) + (15088242590000.0 * fTemp48)) + (54219129930000.0 * fTemp49)) + (121255771400000.0 * fTemp50)) - ((((135304812800000.0 * fTemp51) + (123604114600000.0 * fTemp52)) + (109524344100000.0 * fTemp53)) + (51585726100000.0 * fTemp54))));
			double fTemp56 = (fConst31 * fRec65[1]);
			double fTemp57 = (fConst32 * fRec68[1]);
			fRec70[0] = (fTemp55 + (fTemp56 + (fRec70[1] + fTemp57)));
			fRec68[0] = fRec70[0];
			double fRec69 = ((fTemp57 + fTemp56) + fTemp55);
			fRec67[0] = (fRec68[0] + fRec67[1]);
			fRec65[0] = fRec67[0];
			double fRec66 = fRec69;
			fRec64[0] = (fTemp45 + (fTemp46 + (fRec66 + fRec64[1])));
			fRec62[0] = fRec64[0];
			double fRec63 = (fTemp45 + (fRec66 + fTemp46));
			fRec61[0] = (fRec62[0] + fRec61[1]);
			fRec59[0] = fRec61[0];
			double fRec60 = fRec63;
			fRec58[0] = (fTemp44 + (fRec60 + fRec58[1]));
			fRec56[0] = fRec58[0];
			double fRec57 = (fRec60 + fTemp44);
			fRec79[0] = (double(input0[i]) - (((fRec79[2] * fTemp2) + (2.0 * (fRec79[1] * fTemp4))) / fTemp5));
			double fTemp58 = (((fTemp3 * (fRec79[2] + (fRec79[0] + (2.0 * fRec79[1])))) / fTemp6) + (1.5971413109999999 * (fRec12[0] * (0.0 - ((fRec79[1] * fTemp7) + ((fRec79[0] + fRec79[2]) / fTemp5))))));
			fVec0[(IOTA & 1023)] = ((fRec2 + (fRec20 + (fRec31 + (fRec37 + fRec57)))) + (53505687000000.0 * fTemp58));
			output0[i] = FAUSTFLOAT((0.82065997130559543 * (fRec0[0] * fVec0[((IOTA - iConst33) & 1023)])));
			double fTemp59 = (fConst25 * fRec80[1]);
			double fTemp60 = (fConst27 * fRec83[1]);
			double fTemp61 = (fConst28 * fRec86[1]);
			double fTemp62 = (fConst30 * (((47890165120000.0 * fTemp54) + ((((36510484600000.0 * fTemp47) + (65771052340000.0 * fTemp51)) + (130644250400000.0 * fTemp52)) + (61029493350000.0 * fTemp53))) - (((4437765125000.0 * fTemp48) + (37293455260000.0 * fTemp49)) + (206243327500000.0 * fTemp50))));
			double fTemp63 = (fConst31 * fRec89[1]);
			double fTemp64 = (fConst32 * fRec92[1]);
			fRec94[0] = (fTemp62 + (fTemp63 + (fRec94[1] + fTemp64)));
			fRec92[0] = fRec94[0];
			double fRec93 = ((fTemp64 + fTemp63) + fTemp62);
			fRec91[0] = (fRec92[0] + fRec91[1]);
			fRec89[0] = fRec91[0];
			double fRec90 = fRec93;
			fRec88[0] = (fTemp60 + (fTemp61 + (fRec90 + fRec88[1])));
			fRec86[0] = fRec88[0];
			double fRec87 = (fTemp60 + (fRec90 + fTemp61));
			fRec85[0] = (fRec86[0] + fRec85[1]);
			fRec83[0] = fRec85[0];
			double fRec84 = fRec87;
			fRec82[0] = (fTemp59 + (fRec84 + fRec82[1]));
			fRec80[0] = fRec82[0];
			double fRec81 = (fRec84 + fTemp59);
			double fTemp65 = (fConst22 * fRec95[1]);
			double fTemp66 = (fConst23 * fRec98[1]);
			double fTemp67 = (fConst19 * (((21298200970000.0 * fTemp33) + ((333850069000000.0 * fTemp38) + ((77285507510000.0 * fTemp37) + ((((34053424660000.0 * fTemp31) + (110810485200000.0 * fTemp34)) + (2580678107000.0 * fTemp35)) + (26935737020000.0 * fTemp36))))) - (151074920700000.0 * fTemp32)));
			double fTemp68 = (fConst20 * fRec101[1]);
			double fTemp69 = (fConst21 * fRec104[1]);
			fRec106[0] = (fTemp67 + (fTemp68 + (fRec106[1] + fTemp69)));
			fRec104[0] = fRec106[0];
			double fRec105 = ((fTemp69 + fTemp68) + fTemp67);
			fRec103[0] = (fRec104[0] + fRec103[1]);
			fRec101[0] = fRec103[0];
			double fRec102 = fRec105;
			fRec100[0] = (fTemp65 + (fTemp66 + (fRec102 + fRec100[1])));
			fRec98[0] = fRec100[0];
			double fRec99 = (fTemp65 + (fRec102 + fTemp66));
			fRec97[0] = (fRec98[0] + fRec97[1]);
			fRec95[0] = fRec97[0];
			double fRec96 = fRec99;
			double fTemp70 = (fConst3 * fRec107[1]);
			double fTemp71 = (fConst5 * ((137679642600000.0 * fTemp14) - ((204520983700000.0 * fTemp13) + (((((173784171800000.0 * fTemp8) + (33191892870000.0 * fTemp9)) + (5005612116000.0 * fTemp10)) + (174740966200000.0 * fTemp11)) + (199036473600000.0 * fTemp12)))));
			double fTemp72 = (fConst8 * fRec110[1]);
			double fTemp73 = (fConst9 * fRec113[1]);
			fRec115[0] = (fTemp71 + (fTemp72 + (fRec115[1] + fTemp73)));
			fRec113[0] = fRec115[0];
			double fRec114 = ((fTemp73 + fTemp72) + fTemp71);
			fRec112[0] = (fRec113[0] + fRec112[1]);
			fRec110[0] = fRec112[0];
			double fRec111 = fRec114;
			fRec109[0] = (fTemp70 + (fRec111 + fRec109[1]));
			fRec107[0] = fRec109[0];
			double fRec108 = (fRec111 + fTemp70);
			double fTemp74 = (fConst15 * ((11782130630000.0 * fTemp28) - ((23528556900000.0 * fTemp26) + (71395421170000.0 * fTemp27))));
			double fTemp75 = (fConst16 * fRec116[1]);
			fRec118[0] = (fTemp74 + (fRec118[1] + fTemp75));
			fRec116[0] = fRec118[0];
			double fRec117 = (fTemp75 + fTemp74);
			double fTemp76 = (fConst11 * (((((131555414700000.0 * fTemp18) + (46755536890000.0 * fTemp19)) + (191213325800000.0 * fTemp21)) + (280447373700000.0 * fTemp22)) - (29042842640000.0 * fTemp20)));
			double fTemp77 = (fConst13 * fRec119[1]);
			double fTemp78 = (fConst12 * fRec122[1]);
			fRec124[0] = (fTemp76 + (fTemp77 + (fRec124[1] + fTemp78)));
			fRec122[0] = fRec124[0];
			double fRec123 = ((fTemp78 + fTemp77) + fTemp76);
			fRec121[0] = (fRec122[0] + fRec121[1]);
			fRec119[0] = fRec121[0];
			double fRec120 = fRec123;
			fVec1[(IOTA & 1023)] = ((28513916750000.0 * fTemp58) + (fRec81 + (fRec96 + (fRec108 + (fRec117 + fRec120)))));
			output1[i] = FAUSTFLOAT((0.82065997130559543 * (fRec0[0] * fVec1[((IOTA - iConst33) & 1023)])));
			double fTemp79 = (fConst25 * fRec125[1]);
			double fTemp80 = (fConst27 * fRec128[1]);
			double fTemp81 = (fConst28 * fRec131[1]);
			double fTemp82 = (fConst30 * (((130402026800000.0 * fTemp50) + (24950349010000.0 * fTemp54)) - ((((((58965881410000.0 * fTemp47) + (5076780616000.0 * fTemp48)) + (7259780621000.0 * fTemp51)) + (2689096067000.0 * fTemp49)) + (152700723200000.0 * fTemp52)) + (16725463630000.0 * fTemp53))));
			double fTemp83 = (fConst31 * fRec134[1]);
			double fTemp84 = (fConst32 * fRec137[1]);
			fRec139[0] = (fTemp82 + (fTemp83 + (fRec139[1] + fTemp84)));
			fRec137[0] = fRec139[0];
			double fRec138 = ((fTemp84 + fTemp83) + fTemp82);
			fRec136[0] = (fRec137[0] + fRec136[1]);
			fRec134[0] = fRec136[0];
			double fRec135 = fRec138;
			fRec133[0] = (fTemp80 + (fTemp81 + (fRec135 + fRec133[1])));
			fRec131[0] = fRec133[0];
			double fRec132 = (fTemp80 + (fRec135 + fTemp81));
			fRec130[0] = (fRec131[0] + fRec130[1]);
			fRec128[0] = fRec130[0];
			double fRec129 = fRec132;
			fRec127[0] = (fTemp79 + (fRec129 + fRec127[1]));
			fRec125[0] = fRec127[0];
			double fRec126 = (fRec129 + fTemp79);
			double fTemp85 = (fConst22 * fRec140[1]);
			double fTemp86 = (fConst23 * fRec143[1]);
			double fTemp87 = (fConst19 * (((((57139249180000.0 * fTemp32) + (37494968780000.0 * fTemp34)) + (19999753790000.0 * fTemp35)) + (58248463720000.0 * fTemp33)) - ((227139388800000.0 * fTemp38) + (((52502803460000.0 * fTemp31) + (52077780290000.0 * fTemp36)) + (201857036200000.0 * fTemp37)))));
			double fTemp88 = (fConst20 * fRec146[1]);
			double fTemp89 = (fConst21 * fRec149[1]);
			fRec151[0] = (fTemp87 + (fTemp88 + (fRec151[1] + fTemp89)));
			fRec149[0] = fRec151[0];
			double fRec150 = ((fTemp89 + fTemp88) + fTemp87);
			fRec148[0] = (fRec149[0] + fRec148[1]);
			fRec146[0] = fRec148[0];
			double fRec147 = fRec150;
			fRec145[0] = (fTemp85 + (fTemp86 + (fRec147 + fRec145[1])));
			fRec143[0] = fRec145[0];
			double fRec144 = (fTemp85 + (fRec147 + fTemp86));
			fRec142[0] = (fRec143[0] + fRec142[1]);
			fRec140[0] = fRec142[0];
			double fRec141 = fRec144;
			double fTemp90 = (fConst3 * fRec152[1]);
			double fTemp91 = (fConst5 * (((238792799600000.0 * fTemp13) + ((312356901500000.0 * fTemp12) + ((1396782534000.0 * fTemp10) + (124651983800000.0 * fTemp11)))) - (((82554367700000.0 * fTemp14) + (27303313240000.0 * fTemp8)) + (37200140580000.0 * fTemp9))));
			double fTemp92 = (fConst8 * fRec155[1]);
			double fTemp93 = (fConst9 * fRec158[1]);
			fRec160[0] = (fTemp91 + (fTemp92 + (fRec160[1] + fTemp93)));
			fRec158[0] = fRec160[0];
			double fRec159 = ((fTemp93 + fTemp92) + fTemp91);
			fRec157[0] = (fRec158[0] + fRec157[1]);
			fRec155[0] = fRec157[0];
			double fRec156 = fRec159;
			fRec154[0] = (fTemp90 + (fRec156 + fRec154[1]));
			fRec152[0] = fRec154[0];
			double fRec153 = (fRec156 + fTemp90);
			double fTemp94 = (fConst15 * ((180762524000000.0 * fTemp27) - ((43408663680000.0 * fTemp26) + (24509465410000.0 * fTemp28))));
			double fTemp95 = (fConst16 * fRec161[1]);
			fRec163[0] = (fTemp94 + (fRec163[1] + fTemp95));
			fRec161[0] = fRec163[0];
			double fRec162 = (fTemp95 + fTemp94);
			double fTemp96 = (fConst11 * ((48246818370000.0 * fTemp19) - ((((8880255442000.0 * fTemp18) + (15461321150000.0 * fTemp20)) + (196867256800000.0 * fTemp21)) + (257315251500000.0 * fTemp22))));
			double fTemp97 = (fConst13 * fRec164[1]);
			double fTemp98 = (fConst12 * fRec167[1]);
			fRec169[0] = (fTemp96 + (fTemp97 + (fRec169[1] + fTemp98)));
			fRec167[0] = fRec169[0];
			double fRec168 = ((fTemp98 + fTemp97) + fTemp96);
			fRec166[0] = (fRec167[0] + fRec166[1]);
			fRec164[0] = fRec166[0];
			double fRec165 = fRec168;
			fVec2[(IOTA & 1023)] = ((44977571390000.0 * fTemp58) + (fRec126 + (fRec141 + (fRec153 + (fRec162 + fRec165)))));
			output2[i] = FAUSTFLOAT((0.82065997130559543 * (fRec0[0] * fVec2[((IOTA - iConst33) & 1023)])));
			double fTemp99 = (fConst25 * fRec170[1]);
			double fTemp100 = (fConst27 * fRec173[1]);
			double fTemp101 = (fConst28 * fRec176[1]);
			double fTemp102 = (fConst30 * ((((((5478041407000.0 * fTemp47) + (31909951220000.0 * fTemp51)) + (61815540550000.0 * fTemp49)) + (37293431010000.0 * fTemp52)) + (135121476600000.0 * fTemp53)) - (((10616258220000.0 * fTemp48) + (21574651460000.0 * fTemp50)) + (58840493320000.0 * fTemp54))));
			double fTemp103 = (fConst31 * fRec179[1]);
			double fTemp104 = (fConst32 * fRec182[1]);
			fRec184[0] = (fTemp102 + (fTemp103 + (fRec184[1] + fTemp104)));
			fRec182[0] = fRec184[0];
			double fRec183 = ((fTemp104 + fTemp103) + fTemp102);
			fRec181[0] = (fRec182[0] + fRec181[1]);
			fRec179[0] = fRec181[0];
			double fRec180 = fRec183;
			fRec178[0] = (fTemp100 + (fTemp101 + (fRec180 + fRec178[1])));
			fRec176[0] = fRec178[0];
			double fRec177 = (fTemp100 + (fRec180 + fTemp101));
			fRec175[0] = (fRec176[0] + fRec175[1]);
			fRec173[0] = fRec175[0];
			double fRec174 = fRec177;
			fRec172[0] = (fTemp99 + (fRec174 + fRec172[1]));
			fRec170[0] = fRec172[0];
			double fRec171 = (fRec174 + fTemp99);
			double fTemp105 = (fConst22 * fRec185[1]);
			double fTemp106 = (fConst23 * fRec188[1]);
			double fTemp107 = (fConst19 * (((56821417320000.0 * fTemp38) + ((39820057380000.0 * fTemp36) + (195106155600000.0 * fTemp37))) - (((((26142064160000.0 * fTemp31) + (30356246120000.0 * fTemp32)) + (102118709200000.0 * fTemp34)) + (55570136190000.0 * fTemp35)) + (150404875900000.0 * fTemp33))));
			double fTemp108 = (fConst20 * fRec191[1]);
			double fTemp109 = (fConst21 * fRec194[1]);
			fRec196[0] = (fTemp107 + (fTemp108 + (fRec196[1] + fTemp109)));
			fRec194[0] = fRec196[0];
			double fRec195 = ((fTemp109 + fTemp108) + fTemp107);
			fRec193[0] = (fRec194[0] + fRec193[1]);
			fRec191[0] = fRec193[0];
			double fRec192 = fRec195;
			fRec190[0] = (fTemp105 + (fTemp106 + (fRec192 + fRec190[1])));
			fRec188[0] = fRec190[0];
			double fRec189 = (fTemp105 + (fRec192 + fTemp106));
			fRec187[0] = (fRec188[0] + fRec187[1]);
			fRec185[0] = fRec187[0];
			double fRec186 = fRec189;
			double fTemp110 = (fConst3 * fRec197[1]);
			double fTemp111 = (fConst5 * (((152472910700000.0 * fTemp8) + (175053152100000.0 * fTemp9)) - ((68332182800000.0 * fTemp13) + ((((37654039010000.0 * fTemp14) + (3050369821000.0 * fTemp10)) + (167122260600000.0 * fTemp11)) + (318934117000000.0 * fTemp12)))));
			double fTemp112 = (fConst8 * fRec200[1]);
			double fTemp113 = (fConst9 * fRec203[1]);
			fRec205[0] = (fTemp111 + (fTemp112 + (fRec205[1] + fTemp113)));
			fRec203[0] = fRec205[0];
			double fRec204 = ((fTemp113 + fTemp112) + fTemp111);
			fRec202[0] = (fRec203[0] + fRec202[1]);
			fRec200[0] = fRec202[0];
			double fRec201 = fRec204;
			fRec199[0] = (fTemp110 + (fRec201 + fRec199[1]));
			fRec197[0] = fRec199[0];
			double fRec198 = (fRec201 + fTemp110);
			double fTemp114 = (fConst15 * (((84233969920000.0 * fTemp26) + (56849842200000.0 * fTemp28)) - (72964989140000.0 * fTemp27)));
			double fTemp115 = (fConst16 * fRec206[1]);
			fRec208[0] = (fTemp114 + (fRec208[1] + fTemp115));
			fRec206[0] = fRec208[0];
			double fRec207 = (fTemp115 + fTemp114);
			double fTemp116 = (fConst11 * (((183998767700000.0 * fTemp21) + (285595539000000.0 * fTemp22)) - (((156880580900000.0 * fTemp18) + (185181606000000.0 * fTemp19)) + (54705848360000.0 * fTemp20))));
			double fTemp117 = (fConst13 * fRec209[1]);
			double fTemp118 = (fConst12 * fRec212[1]);
			fRec214[0] = (fTemp116 + (fTemp117 + (fRec214[1] + fTemp118)));
			fRec212[0] = fRec214[0];
			double fRec213 = ((fTemp118 + fTemp117) + fTemp116);
			fRec211[0] = (fRec212[0] + fRec211[1]);
			fRec209[0] = fRec211[0];
			double fRec210 = fRec213;
			fVec3[(IOTA & 1023)] = ((6149305525000.0 * fTemp58) + (fRec171 + (fRec186 + (fRec198 + (fRec207 + fRec210)))));
			output3[i] = FAUSTFLOAT((0.82065997130559543 * (fRec0[0] * fVec3[((IOTA - iConst33) & 1023)])));
			double fTemp119 = (fConst25 * fRec215[1]);
			double fTemp120 = (fConst27 * fRec218[1]);
			double fTemp121 = (fConst28 * fRec221[1]);
			double fTemp122 = (fConst30 * ((((50683869440000.0 * fTemp52) + ((57218118630000.0 * fTemp47) + (32388322130000.0 * fTemp48))) + (17243784680000.0 * fTemp54)) - ((299637530100000.0 * fTemp53) + (((51081119270000.0 * fTemp49) + (23282387980000.0 * fTemp51)) + (94409679550000.0 * fTemp50)))));
			double fTemp123 = (fConst31 * fRec224[1]);
			double fTemp124 = (fConst32 * fRec227[1]);
			fRec229[0] = (fTemp122 + (fTemp123 + (fRec229[1] + fTemp124)));
			fRec227[0] = fRec229[0];
			double fRec228 = ((fTemp124 + fTemp123) + fTemp122);
			fRec226[0] = (fRec227[0] + fRec226[1]);
			fRec224[0] = fRec226[0];
			double fRec225 = fRec228;
			fRec223[0] = (fTemp120 + (fTemp121 + (fRec225 + fRec223[1])));
			fRec221[0] = fRec223[0];
			double fRec222 = (fTemp120 + (fRec225 + fTemp121));
			fRec220[0] = (fRec221[0] + fRec220[1]);
			fRec218[0] = fRec220[0];
			double fRec219 = fRec222;
			fRec217[0] = (fTemp119 + (fRec219 + fRec217[1]));
			fRec215[0] = fRec217[0];
			double fRec216 = (fRec219 + fTemp119);
			double fTemp125 = (fConst22 * fRec230[1]);
			double fTemp126 = (fConst23 * fRec233[1]);
			double fTemp127 = (fConst19 * (((156558845400000.0 * fTemp33) + (((((26928341240000.0 * fTemp31) + (64378307100000.0 * fTemp32)) + (185091151900000.0 * fTemp34)) + (83072749590000.0 * fTemp35)) + (130056207400000.0 * fTemp38))) - ((36534987820000.0 * fTemp36) + (171438757800000.0 * fTemp37))));
			double fTemp128 = (fConst20 * fRec236[1]);
			double fTemp129 = (fConst21 * fRec239[1]);
			fRec241[0] = (fTemp127 + (fTemp128 + (fRec241[1] + fTemp129)));
			fRec239[0] = fRec241[0];
			double fRec240 = ((fTemp129 + fTemp128) + fTemp127);
			fRec238[0] = (fRec239[0] + fRec238[1]);
			fRec236[0] = fRec238[0];
			double fRec237 = fRec240;
			fRec235[0] = (fTemp125 + (fTemp126 + (fRec237 + fRec235[1])));
			fRec233[0] = fRec235[0];
			double fRec234 = (fTemp125 + (fRec237 + fTemp126));
			fRec232[0] = (fRec233[0] + fRec232[1]);
			fRec230[0] = fRec232[0];
			double fRec231 = fRec234;
			double fTemp130 = (fConst3 * fRec242[1]);
			double fTemp131 = (fConst5 * (((260150052100000.0 * fTemp12) + ((16383884490000.0 * fTemp10) + (70703270890000.0 * fTemp11))) - ((((58075043120000.0 * fTemp14) + (174465639600000.0 * fTemp8)) + (172225464600000.0 * fTemp9)) + (177911633600000.0 * fTemp13))));
			double fTemp132 = (fConst8 * fRec245[1]);
			double fTemp133 = (fConst9 * fRec248[1]);
			fRec250[0] = (fTemp131 + (fTemp132 + (fRec250[1] + fTemp133)));
			fRec248[0] = fRec250[0];
			double fRec249 = ((fTemp133 + fTemp132) + fTemp131);
			fRec247[0] = (fRec248[0] + fRec247[1]);
			fRec245[0] = fRec247[0];
			double fRec246 = fRec249;
			fRec244[0] = (fTemp130 + (fRec246 + fRec244[1]));
			fRec242[0] = fRec244[0];
			double fRec243 = (fRec246 + fTemp130);
			double fTemp134 = (fConst15 * ((101257113700000.0 * fTemp27) - ((188560881900000.0 * fTemp26) + (127414229200000.0 * fTemp28))));
			double fTemp135 = (fConst16 * fRec251[1]);
			fRec253[0] = (fTemp134 + (fRec253[1] + fTemp135));
			fRec251[0] = fRec253[0];
			double fRec252 = (fTemp135 + fTemp134);
			double fTemp136 = (fConst11 * ((((71484859440000.0 * fTemp18) + (234276112000000.0 * fTemp19)) + (28052227450000.0 * fTemp20)) - ((129329370900000.0 * fTemp21) + (205203270200000.0 * fTemp22))));
			double fTemp137 = (fConst13 * fRec254[1]);
			double fTemp138 = (fConst12 * fRec257[1]);
			fRec259[0] = (fTemp136 + (fTemp137 + (fRec259[1] + fTemp138)));
			fRec257[0] = fRec259[0];
			double fRec258 = ((fTemp138 + fTemp137) + fTemp136);
			fRec256[0] = (fRec257[0] + fRec256[1]);
			fRec254[0] = fRec256[0];
			double fRec255 = fRec258;
			fVec4[(IOTA & 1023)] = ((88025731230000.0 * fTemp58) + (fRec216 + (fRec231 + (fRec243 + (fRec252 + fRec255)))));
			output4[i] = FAUSTFLOAT((0.82065997130559543 * (fRec0[0] * fVec4[((IOTA - iConst33) & 1023)])));
			double fTemp139 = (fConst25 * fRec260[1]);
			double fTemp140 = (fConst27 * fRec263[1]);
			double fTemp141 = (fConst28 * fRec266[1]);
			double fTemp142 = (fConst30 * (((49499757640000.0 * fTemp54) + ((309819782200000.0 * fTemp53) + (((55883747260000.0 * fTemp51) + (43235223370000.0 * fTemp49)) + (242831446300000.0 * fTemp50)))) - (((32788524290000.0 * fTemp47) + (29116395860000.0 * fTemp48)) + (55496037870000.0 * fTemp52))));
			double fTemp143 = (fConst31 * fRec269[1]);
			double fTemp144 = (fConst32 * fRec272[1]);
			fRec274[0] = (fTemp142 + (fTemp143 + (fRec274[1] + fTemp144)));
			fRec272[0] = fRec274[0];
			double fRec273 = ((fTemp144 + fTemp143) + fTemp142);
			fRec271[0] = (fRec272[0] + fRec271[1]);
			fRec269[0] = fRec271[0];
			double fRec270 = fRec273;
			fRec268[0] = (fTemp140 + (fTemp141 + (fRec270 + fRec268[1])));
			fRec266[0] = fRec268[0];
			double fRec267 = (fTemp140 + (fRec270 + fTemp141));
			fRec265[0] = (fRec266[0] + fRec265[1]);
			fRec263[0] = fRec265[0];
			double fRec264 = fRec267;
			fRec262[0] = (fTemp139 + (fRec264 + fRec262[1]));
			fRec260[0] = fRec262[0];
			double fRec261 = (fRec264 + fTemp139);
			double fTemp145 = (fConst22 * fRec275[1]);
			double fTemp146 = (fConst23 * fRec278[1]);
			double fTemp147 = (fConst19 * (((125437039300000.0 * fTemp37) + ((64960155440000.0 * fTemp31) + (17197964250000.0 * fTemp36))) - ((158598853500000.0 * fTemp33) + ((((160867262800000.0 * fTemp32) + (57644176440000.0 * fTemp34)) + (45467434810000.0 * fTemp35)) + (293742082000000.0 * fTemp38)))));
			double fTemp148 = (fConst20 * fRec281[1]);
			double fTemp149 = (fConst21 * fRec284[1]);
			fRec286[0] = (fTemp147 + (fTemp148 + (fRec286[1] + fTemp149)));
			fRec284[0] = fRec286[0];
			double fRec285 = ((fTemp149 + fTemp148) + fTemp147);
			fRec283[0] = (fRec284[0] + fRec283[1]);
			fRec281[0] = fRec283[0];
			double fRec282 = fRec285;
			fRec280[0] = (fTemp145 + (fTemp146 + (fRec282 + fRec280[1])));
			fRec278[0] = fRec280[0];
			double fRec279 = (fTemp145 + (fRec282 + fTemp146));
			fRec277[0] = (fRec278[0] + fRec277[1]);
			fRec275[0] = fRec277[0];
			double fRec276 = fRec279;
			double fTemp150 = (fConst3 * fRec287[1]);
			double fTemp151 = (fConst5 * (((((176950342900000.0 * fTemp14) + (42575446940000.0 * fTemp8)) + (149721651300000.0 * fTemp9)) + (221431304500000.0 * fTemp13)) - (((14426788790000.0 * fTemp10) + (26596474610000.0 * fTemp11)) + (127048728000000.0 * fTemp12))));
			double fTemp152 = (fConst8 * fRec290[1]);
			double fTemp153 = (fConst9 * fRec293[1]);
			fRec295[0] = (fTemp151 + (fTemp152 + (fRec295[1] + fTemp153)));
			fRec293[0] = fRec295[0];
			double fRec294 = ((fTemp153 + fTemp152) + fTemp151);
			fRec292[0] = (fRec293[0] + fRec292[1]);
			fRec290[0] = fRec292[0];
			double fRec291 = fRec294;
			fRec289[0] = (fTemp150 + (fRec291 + fRec289[1]));
			fRec287[0] = fRec289[0];
			double fRec288 = (fRec291 + fTemp150);
			double fTemp154 = (fConst15 * (((28197708960000.0 * fTemp26) + (119004390800000.0 * fTemp28)) - (7641697586000.0 * fTemp27)));
			double fTemp155 = (fConst16 * fRec296[1]);
			fRec298[0] = (fTemp154 + (fRec298[1] + fTemp155));
			fRec296[0] = fRec298[0];
			double fRec297 = (fTemp155 + fTemp154);
			double fTemp156 = (fConst11 * (((47147891250000.0 * fTemp21) + (12817339820000.0 * fTemp22)) - (((52449872840000.0 * fTemp18) + (128110062300000.0 * fTemp19)) + (78129281710000.0 * fTemp20))));
			double fTemp157 = (fConst13 * fRec299[1]);
			double fTemp158 = (fConst12 * fRec302[1]);
			fRec304[0] = (fTemp156 + (fTemp157 + (fRec304[1] + fTemp158)));
			fRec302[0] = fRec304[0];
			double fRec303 = ((fTemp158 + fTemp157) + fTemp156);
			fRec301[0] = (fRec302[0] + fRec301[1]);
			fRec299[0] = fRec301[0];
			double fRec300 = fRec303;
			fVec5[(IOTA & 1023)] = ((fRec261 + (fRec276 + (fRec288 + (fRec297 + fRec300)))) - (20387940210000.0 * fTemp58));
			output5[i] = FAUSTFLOAT((0.82065997130559543 * (fRec0[0] * fVec5[((IOTA - iConst33) & 1023)])));
			double fTemp159 = (fConst25 * fRec305[1]);
			double fTemp160 = (fConst27 * fRec308[1]);
			double fTemp161 = (fConst28 * fRec311[1]);
			double fTemp162 = (fConst30 * (((13296740710000.0 * fTemp48) + (87515858630000.0 * fTemp52)) - ((50610960240000.0 * fTemp54) + ((184087433200000.0 * fTemp53) + ((((39633221440000.0 * fTemp47) + (166677948400000.0 * fTemp51)) + (9737130530000.0 * fTemp49)) + (238168524000000.0 * fTemp50))))));
			double fTemp163 = (fConst31 * fRec314[1]);
			double fTemp164 = (fConst32 * fRec317[1]);
			fRec319[0] = (fTemp162 + (fTemp163 + (fRec319[1] + fTemp164)));
			fRec317[0] = fRec319[0];
			double fRec318 = ((fTemp164 + fTemp163) + fTemp162);
			fRec316[0] = (fRec317[0] + fRec316[1]);
			fRec314[0] = fRec316[0];
			double fRec315 = fRec318;
			fRec313[0] = (fTemp160 + (fTemp161 + (fRec315 + fRec313[1])));
			fRec311[0] = fRec313[0];
			double fRec312 = (fTemp160 + (fRec315 + fTemp161));
			fRec310[0] = (fRec311[0] + fRec310[1]);
			fRec308[0] = fRec310[0];
			double fRec309 = fRec312;
			fRec307[0] = (fTemp159 + (fRec309 + fRec307[1]));
			fRec305[0] = fRec307[0];
			double fRec306 = (fRec309 + fTemp159);
			double fTemp165 = (fConst22 * fRec320[1]);
			double fTemp166 = (fConst23 * fRec323[1]);
			double fTemp167 = (fConst19 * (((181135644900000.0 * fTemp33) + ((317045060600000.0 * fTemp38) + (((289499312200000.0 * fTemp32) + (8908593319000.0 * fTemp35)) + (8011093238000.0 * fTemp37)))) - (((55482163070000.0 * fTemp31) + (33302553400000.0 * fTemp34)) + (7167308976000.0 * fTemp36))));
			double fTemp168 = (fConst20 * fRec326[1]);
			double fTemp169 = (fConst21 * fRec329[1]);
			fRec331[0] = (fTemp167 + (fTemp168 + (fRec331[1] + fTemp169)));
			fRec329[0] = fRec331[0];
			double fRec330 = ((fTemp169 + fTemp168) + fTemp167);
			fRec328[0] = (fRec329[0] + fRec328[1]);
			fRec326[0] = fRec328[0];
			double fRec327 = fRec330;
			fRec325[0] = (fTemp165 + (fTemp166 + (fRec327 + fRec325[1])));
			fRec323[0] = fRec325[0];
			double fRec324 = (fTemp165 + (fRec327 + fTemp166));
			fRec322[0] = (fRec323[0] + fRec322[1]);
			fRec320[0] = fRec322[0];
			double fRec321 = fRec324;
			double fTemp170 = (fConst3 * fRec332[1]);
			double fTemp171 = (fConst5 * (((((66590256290000.0 * fTemp8) + (77751755810000.0 * fTemp9)) + (9178365865000.0 * fTemp10)) + (13622589480000.0 * fTemp12)) - (((169327319900000.0 * fTemp14) + (9456762204000.0 * fTemp11)) + (236772444500000.0 * fTemp13))));
			double fTemp172 = (fConst8 * fRec335[1]);
			double fTemp173 = (fConst9 * fRec338[1]);
			fRec340[0] = (fTemp171 + (fTemp172 + (fRec340[1] + fTemp173)));
			fRec338[0] = fRec340[0];
			double fRec339 = ((fTemp173 + fTemp172) + fTemp171);
			fRec337[0] = (fRec338[0] + fRec337[1]);
			fRec335[0] = fRec337[0];
			double fRec336 = fRec339;
			fRec334[0] = (fTemp170 + (fRec336 + fRec334[1]));
			fRec332[0] = fRec334[0];
			double fRec333 = (fRec336 + fTemp170);
			double fTemp174 = (fConst15 * (0.0 - (((394452907600.0 * fTemp26) + (96147782100000.0 * fTemp28)) + (23698575250000.0 * fTemp27))));
			double fTemp175 = (fConst16 * fRec341[1]);
			fRec343[0] = (fTemp174 + (fRec343[1] + fTemp175));
			fRec341[0] = fRec343[0];
			double fRec342 = (fTemp175 + fTemp174);
			double fTemp176 = (fConst11 * (((16497269600000.0 * fTemp20) + (7865849466000.0 * fTemp21)) - (((25097483360000.0 * fTemp18) + (79341102300000.0 * fTemp19)) + (26760532110000.0 * fTemp22))));
			double fTemp177 = (fConst13 * fRec344[1]);
			double fTemp178 = (fConst12 * fRec347[1]);
			fRec349[0] = (fTemp176 + (fTemp177 + (fRec349[1] + fTemp178)));
			fRec347[0] = fRec349[0];
			double fRec348 = ((fTemp178 + fTemp177) + fTemp176);
			fRec346[0] = (fRec347[0] + fRec346[1]);
			fRec344[0] = fRec346[0];
			double fRec345 = fRec348;
			fVec6[(IOTA & 1023)] = ((76791352790000.0 * fTemp58) + (fRec306 + (fRec321 + (fRec333 + (fRec342 + fRec345)))));
			output6[i] = FAUSTFLOAT((0.82065997130559543 * (fRec0[0] * fVec6[((IOTA - iConst33) & 1023)])));
			double fTemp179 = (fConst25 * fRec350[1]);
			double fTemp180 = (fConst27 * fRec353[1]);
			double fTemp181 = (fConst28 * fRec356[1]);
			double fTemp182 = (fConst30 * (((94804965270000.0 * fTemp53) + (((60710547310000.0 * fTemp47) + (148176600700000.0 * fTemp51)) + (118111707500000.0 * fTemp50))) - ((((7144244029000.0 * fTemp48) + (21210508750000.0 * fTemp49)) + (3396574316000.0 * fTemp52)) + (6938547303000.0 * fTemp54))));
			double fTemp183 = (fConst31 * fRec359[1]);
			double fTemp184 = (fConst32 * fRec362[1]);
			fRec364[0] = (fTemp182 + (fTemp183 + (fRec364[1] + fTemp184)));
			fRec362[0] = fRec364[0];
			double fRec363 = ((fTemp184 + fTemp183) + fTemp182);
			fRec361[0] = (fRec362[0] + fRec361[1]);
			fRec359[0] = fRec361[0];
			double fRec360 = fRec363;
			fRec358[0] = (fTemp180 + (fTemp181 + (fRec360 + fRec358[1])));
			fRec356[0] = fRec358[0];
			double fRec357 = (fTemp180 + (fRec360 + fTemp181));
			fRec355[0] = (fRec356[0] + fRec355[1]);
			fRec353[0] = fRec355[0];
			double fRec354 = fRec357;
			fRec352[0] = (fTemp179 + (fRec354 + fRec352[1]));
			fRec350[0] = fRec352[0];
			double fRec351 = (fRec354 + fTemp179);
			double fTemp185 = (fConst21 * fRec374[1]);
			double fTemp186 = (fConst20 * fRec371[1]);
			double fTemp187 = (fConst19 * (((21049242050000.0 * fTemp37) + (((14742730370000.0 * fTemp34) + (43804228980000.0 * fTemp35)) + (5786037419000.0 * fTemp36))) - ((117463327400000.0 * fTemp33) + (((38728655690000.0 * fTemp31) + (267020504500000.0 * fTemp32)) + (214429298000000.0 * fTemp38)))));
			fRec376[0] = (((fRec376[1] + fTemp185) + fTemp186) + fTemp187);
			fRec374[0] = fRec376[0];
			double fRec375 = ((fTemp185 + fTemp186) + fTemp187);
			fRec373[0] = (fRec374[0] + fRec373[1]);
			fRec371[0] = fRec373[0];
			double fRec372 = fRec375;
			double fTemp188 = (fConst23 * fRec368[1]);
			double fTemp189 = (fConst22 * fRec365[1]);
			fRec370[0] = (((fRec372 + fRec370[1]) + fTemp188) + fTemp189);
			fRec368[0] = fRec370[0];
			double fRec369 = ((fRec372 + fTemp188) + fTemp189);
			fRec367[0] = (fRec368[0] + fRec367[1]);
			fRec365[0] = fRec367[0];
			double fRec366 = fRec369;
			double fTemp190 = (fConst3 * fRec377[1]);
			double fTemp191 = (fConst5 * ((((195444401600000.0 * fTemp14) + (37839987750000.0 * fTemp11)) + (243999291700000.0 * fTemp13)) - ((((74634577360000.0 * fTemp8) + (128582367100000.0 * fTemp9)) + (1128044925000.0 * fTemp10)) + (18552800450000.0 * fTemp12))));
			double fTemp192 = (fConst8 * fRec380[1]);
			double fTemp193 = (fConst9 * fRec383[1]);
			fRec385[0] = (fTemp191 + (fTemp192 + (fRec385[1] + fTemp193)));
			fRec383[0] = fRec385[0];
			double fRec384 = ((fTemp193 + fTemp192) + fTemp191);
			fRec382[0] = (fRec383[0] + fRec382[1]);
			fRec380[0] = fRec382[0];
			double fRec381 = fRec384;
			fRec379[0] = (fTemp190 + (fRec381 + fRec379[1]));
			fRec377[0] = fRec379[0];
			double fRec378 = (fRec381 + fTemp190);
			double fTemp194 = (fConst15 * ((40275545800000.0 * fTemp28) - ((186297220100000.0 * fTemp26) + (13287516300000.0 * fTemp27))));
			double fTemp195 = (fConst16 * fRec386[1]);
			fRec388[0] = (fTemp194 + (fRec388[1] + fTemp195));
			fRec386[0] = fRec388[0];
			double fRec387 = (fTemp195 + fTemp194);
			double fTemp196 = (fConst11 * (((106799788900000.0 * fTemp18) + (220757885100000.0 * fTemp19)) - (((49276171540000.0 * fTemp20) + (21665143040000.0 * fTemp21)) + (15032669120000.0 * fTemp22))));
			double fTemp197 = (fConst13 * fRec389[1]);
			double fTemp198 = (fConst12 * fRec392[1]);
			fRec394[0] = (fTemp196 + (fTemp197 + (fRec394[1] + fTemp198)));
			fRec392[0] = fRec394[0];
			double fRec393 = ((fTemp198 + fTemp197) + fTemp196);
			fRec391[0] = (fRec392[0] + fRec391[1]);
			fRec389[0] = fRec391[0];
			double fRec390 = fRec393;
			fVec7[(IOTA & 1023)] = ((fRec351 + (fRec366 + (fRec378 + (fRec387 + fRec390)))) + (15282527450000.0 * fTemp58));
			output7[i] = FAUSTFLOAT((0.82065997130559543 * (fRec0[0] * fVec7[((IOTA - iConst33) & 1023)])));
			double fTemp199 = (fConst25 * fRec395[1]);
			double fTemp200 = (fConst27 * fRec398[1]);
			double fTemp201 = (fConst28 * fRec401[1]);
			double fTemp202 = (fConst30 * (((4915071990000.0 * fTemp48) + (57024480040000.0 * fTemp54)) - ((56401671180000.0 * fTemp53) + (((((23987462430000.0 * fTemp47) + (63293246470000.0 * fTemp51)) + (7912041025000.0 * fTemp49)) + (55653843390000.0 * fTemp52)) + (73957069690000.0 * fTemp50)))));
			double fTemp203 = (fConst31 * fRec404[1]);
			double fTemp204 = (fConst32 * fRec407[1]);
			fRec409[0] = (fTemp202 + (fTemp203 + (fRec409[1] + fTemp204)));
			fRec407[0] = fRec409[0];
			double fRec408 = ((fTemp204 + fTemp203) + fTemp202);
			fRec406[0] = (fRec407[0] + fRec406[1]);
			fRec404[0] = fRec406[0];
			double fRec405 = fRec408;
			fRec403[0] = (fTemp200 + (fTemp201 + (fRec405 + fRec403[1])));
			fRec401[0] = fRec403[0];
			double fRec402 = (fTemp200 + (fRec405 + fTemp201));
			fRec400[0] = (fRec401[0] + fRec400[1]);
			fRec398[0] = fRec400[0];
			double fRec399 = fRec402;
			fRec397[0] = (fTemp199 + (fRec399 + fRec397[1]));
			fRec395[0] = fRec397[0];
			double fRec396 = (fRec399 + fTemp199);
			double fTemp205 = (fConst22 * fRec410[1]);
			double fTemp206 = (fConst23 * fRec413[1]);
			double fTemp207 = (fConst19 * (((((52006198840000.0 * fTemp31) + (148968489000000.0 * fTemp32)) + (224578674600.0 * fTemp36)) + (126860763100000.0 * fTemp38)) - ((((52628420120000.0 * fTemp34) + (81142472400000.0 * fTemp35)) + (50452495610000.0 * fTemp37)) + (5705534450000.0 * fTemp33))));
			double fTemp208 = (fConst20 * fRec416[1]);
			double fTemp209 = (fConst21 * fRec419[1]);
			fRec421[0] = (fTemp207 + (fTemp208 + (fRec421[1] + fTemp209)));
			fRec419[0] = fRec421[0];
			double fRec420 = ((fTemp209 + fTemp208) + fTemp207);
			fRec418[0] = (fRec419[0] + fRec418[1]);
			fRec416[0] = fRec418[0];
			double fRec417 = fRec420;
			fRec415[0] = (fTemp205 + (fTemp206 + (fRec417 + fRec415[1])));
			fRec413[0] = fRec415[0];
			double fRec414 = (fTemp205 + (fRec417 + fTemp206));
			fRec412[0] = (fRec413[0] + fRec412[1]);
			fRec410[0] = fRec412[0];
			double fRec411 = fRec414;
			double fTemp210 = (fConst3 * fRec422[1]);
			double fTemp211 = (fConst5 * (((73361600510000.0 * fTemp12) + ((((48675090290000.0 * fTemp8) + (293901697900000.0 * fTemp9)) + (7528005038000.0 * fTemp10)) + (29471659760000.0 * fTemp11))) - ((186883396700000.0 * fTemp14) + (98421751050000.0 * fTemp13))));
			double fTemp212 = (fConst8 * fRec425[1]);
			double fTemp213 = (fConst9 * fRec428[1]);
			fRec430[0] = (fTemp211 + (fTemp212 + (fRec430[1] + fTemp213)));
			fRec428[0] = fRec430[0];
			double fRec429 = ((fTemp213 + fTemp212) + fTemp211);
			fRec427[0] = (fRec428[0] + fRec427[1]);
			fRec425[0] = fRec427[0];
			double fRec426 = fRec429;
			fRec424[0] = (fTemp210 + (fRec426 + fRec424[1]));
			fRec422[0] = fRec424[0];
			double fRec423 = (fRec426 + fTemp210);
			double fTemp214 = (fConst15 * ((202190404000000.0 * fTemp26) - ((26102959090000.0 * fTemp28) + (53505262520000.0 * fTemp27))));
			double fTemp215 = (fConst16 * fRec431[1]);
			fRec433[0] = (fTemp214 + (fRec433[1] + fTemp215));
			fRec431[0] = fRec433[0];
			double fRec432 = (fTemp215 + fTemp214);
			double fTemp216 = (fConst11 * (((20123260670000.0 * fTemp18) + (5881218350000.0 * fTemp21)) - (((368186889800000.0 * fTemp19) + (21068521250000.0 * fTemp20)) + (49478975490000.0 * fTemp22))));
			double fTemp217 = (fConst13 * fRec434[1]);
			double fTemp218 = (fConst12 * fRec437[1]);
			fRec439[0] = (fTemp216 + (fTemp217 + (fRec439[1] + fTemp218)));
			fRec437[0] = fRec439[0];
			double fRec438 = ((fTemp218 + fTemp217) + fTemp216);
			fRec436[0] = (fRec437[0] + fRec436[1]);
			fRec434[0] = fRec436[0];
			double fRec435 = fRec438;
			fVec8[(IOTA & 1023)] = ((44967371790000.0 * fTemp58) + (fRec396 + (fRec411 + (fRec423 + (fRec432 + fRec435)))));
			output8[i] = FAUSTFLOAT((0.82065997130559543 * (fRec0[0] * fVec8[((IOTA - iConst33) & 1023)])));
			double fTemp219 = (fConst22 * fRec440[1]);
			double fTemp220 = (fConst23 * fRec443[1]);
			double fTemp221 = (fConst19 * ((((47553744760000.0 * fTemp37) + (((34670298400000.0 * fTemp31) + (113114658000000.0 * fTemp35)) + (9013297573000.0 * fTemp36))) + (24016722520000.0 * fTemp33)) - (((12081901770000.0 * fTemp32) + (50444779120000.0 * fTemp34)) + (57547400260000.0 * fTemp38))));
			double fTemp222 = (fConst20 * fRec446[1]);
			double fTemp223 = (fConst21 * fRec449[1]);
			fRec451[0] = (fTemp221 + (fTemp222 + (fRec451[1] + fTemp223)));
			fRec449[0] = fRec451[0];
			double fRec450 = ((fTemp223 + fTemp222) + fTemp221);
			fRec448[0] = (fRec449[0] + fRec448[1]);
			fRec446[0] = fRec448[0];
			double fRec447 = fRec450;
			fRec445[0] = (fTemp219 + (fTemp220 + (fRec447 + fRec445[1])));
			fRec443[0] = fRec445[0];
			double fRec444 = (fTemp219 + (fRec447 + fTemp220));
			fRec442[0] = (fRec443[0] + fRec442[1]);
			fRec440[0] = fRec442[0];
			double fRec441 = fRec444;
			double fTemp224 = (fConst3 * fRec452[1]);
			double fTemp225 = (fConst5 * (((50859689060000.0 * fTemp8) + (34560602140000.0 * fTemp11)) - ((13790178370000.0 * fTemp13) + ((((12675137090000.0 * fTemp14) + (341783887600000.0 * fTemp9)) + (3235517907000.0 * fTemp10)) + (134511908100000.0 * fTemp12)))));
			double fTemp226 = (fConst8 * fRec455[1]);
			double fTemp227 = (fConst9 * fRec458[1]);
			fRec460[0] = (fTemp225 + (fTemp226 + (fRec460[1] + fTemp227)));
			fRec458[0] = fRec460[0];
			double fRec459 = ((fTemp227 + fTemp226) + fTemp225);
			fRec457[0] = (fRec458[0] + fRec457[1]);
			fRec455[0] = fRec457[0];
			double fRec456 = fRec459;
			fRec454[0] = (fTemp224 + (fRec456 + fRec454[1]));
			fRec452[0] = fRec454[0];
			double fRec453 = (fRec456 + fTemp224);
			double fTemp228 = (fConst11 * (((188640202800000.0 * fTemp22) + (454676701500000.0 * fTemp19)) - (((20083753950000.0 * fTemp18) + (28918263970000.0 * fTemp20)) + (4531790526000.0 * fTemp21))));
			double fTemp229 = (fConst12 * fRec464[1]);
			double fTemp230 = (fConst13 * fRec461[1]);
			fRec466[0] = (((fTemp228 + fRec466[1]) + fTemp229) + fTemp230);
			fRec464[0] = fRec466[0];
			double fRec465 = ((fTemp228 + fTemp229) + fTemp230);
			fRec463[0] = (fRec464[0] + fRec463[1]);
			fRec461[0] = fRec463[0];
			double fRec462 = fRec465;
			double fTemp231 = (fConst25 * fRec467[1]);
			double fTemp232 = (fConst27 * fRec470[1]);
			double fTemp233 = (fConst28 * fRec473[1]);
			double fTemp234 = (fConst30 * (((60574861760000.0 * fTemp53) + ((53341718870000.0 * fTemp50) + (((22006989790000.0 * fTemp51) + (11064878950000.0 * fTemp49)) + (48628352870000.0 * fTemp52)))) - (((36937834530000.0 * fTemp47) + (4312167991000.0 * fTemp48)) + (50908106710000.0 * fTemp54))));
			double fTemp235 = (fConst31 * fRec476[1]);
			double fTemp236 = (fConst32 * fRec479[1]);
			fRec481[0] = (fTemp234 + (fTemp235 + (fRec481[1] + fTemp236)));
			fRec479[0] = fRec481[0];
			double fRec480 = ((fTemp236 + fTemp235) + fTemp234);
			fRec478[0] = (fRec479[0] + fRec478[1]);
			fRec476[0] = fRec478[0];
			double fRec477 = fRec480;
			fRec475[0] = (fTemp232 + (fTemp233 + (fRec477 + fRec475[1])));
			fRec473[0] = fRec475[0];
			double fRec474 = (fTemp232 + (fRec477 + fTemp233));
			fRec472[0] = (fRec473[0] + fRec472[1]);
			fRec470[0] = fRec472[0];
			double fRec471 = fRec474;
			fRec469[0] = (fTemp231 + (fRec471 + fRec469[1]));
			fRec467[0] = fRec469[0];
			double fRec468 = (fRec471 + fTemp231);
			double fTemp237 = (fConst15 * ((9533885971000.0 * fTemp28) - ((290533922400000.0 * fTemp26) + (47233734620000.0 * fTemp27))));
			double fTemp238 = (fConst16 * fRec482[1]);
			fRec484[0] = (fTemp237 + (fRec484[1] + fTemp238));
			fRec482[0] = fRec484[0];
			double fRec483 = (fTemp238 + fTemp237);
			fVec9[(IOTA & 1023)] = ((fRec441 + (fRec453 + (fRec462 + (fRec468 + fRec483)))) + (28949211180000.0 * fTemp58));
			output9[i] = FAUSTFLOAT((0.82065997130559543 * (fRec0[0] * fVec9[((IOTA - iConst33) & 1023)])));
			double fTemp239 = (fConst25 * fRec485[1]);
			double fTemp240 = (fConst27 * fRec488[1]);
			double fTemp241 = (fConst28 * fRec491[1]);
			double fTemp242 = (fConst30 * (((((52448070390000.0 * fTemp47) + (8113313181000.0 * fTemp48)) + (122618748600000.0 * fTemp51)) + (32239939870000.0 * fTemp50)) - ((26442583320000.0 * fTemp54) + (((29596507970000.0 * fTemp49) + (83891990190000.0 * fTemp52)) + (83865357440000.0 * fTemp53)))));
			double fTemp243 = (fConst31 * fRec494[1]);
			double fTemp244 = (fConst32 * fRec497[1]);
			fRec499[0] = (fTemp242 + (fTemp243 + (fRec499[1] + fTemp244)));
			fRec497[0] = fRec499[0];
			double fRec498 = ((fTemp244 + fTemp243) + fTemp242);
			fRec496[0] = (fRec497[0] + fRec496[1]);
			fRec494[0] = fRec496[0];
			double fRec495 = fRec498;
			fRec493[0] = (fTemp240 + (fTemp241 + (fRec495 + fRec493[1])));
			fRec491[0] = fRec493[0];
			double fRec492 = (fTemp240 + (fRec495 + fTemp241));
			fRec490[0] = (fRec491[0] + fRec490[1]);
			fRec488[0] = fRec490[0];
			double fRec489 = fRec492;
			fRec487[0] = (fTemp239 + (fRec489 + fRec487[1]));
			fRec485[0] = fRec487[0];
			double fRec486 = (fRec489 + fTemp239);
			double fTemp245 = (fConst22 * fRec500[1]);
			double fTemp246 = (fConst23 * fRec503[1]);
			double fTemp247 = (fConst19 * ((((116376210600000.0 * fTemp34) + (13456727020000.0 * fTemp36)) + (103110652300000.0 * fTemp33)) - ((54514963270000.0 * fTemp38) + ((((55227470000000.0 * fTemp31) + (224047428900000.0 * fTemp32)) + (102989057000000.0 * fTemp35)) + (138452783200000.0 * fTemp37)))));
			double fTemp248 = (fConst20 * fRec506[1]);
			double fTemp249 = (fConst21 * fRec509[1]);
			fRec511[0] = (fTemp247 + (fTemp248 + (fRec511[1] + fTemp249)));
			fRec509[0] = fRec511[0];
			double fRec510 = ((fTemp249 + fTemp248) + fTemp247);
			fRec508[0] = (fRec509[0] + fRec508[1]);
			fRec506[0] = fRec508[0];
			double fRec507 = fRec510;
			fRec505[0] = (fTemp245 + (fTemp246 + (fRec507 + fRec505[1])));
			fRec503[0] = fRec505[0];
			double fRec504 = (fTemp245 + (fRec507 + fTemp246));
			fRec502[0] = (fRec503[0] + fRec502[1]);
			fRec500[0] = fRec502[0];
			double fRec501 = fRec504;
			double fTemp250 = (fConst3 * fRec512[1]);
			double fTemp251 = (fConst8 * fRec515[1]);
			double fTemp252 = (fConst9 * fRec518[1]);
			double fTemp253 = (fConst5 * (((185642349700000.0 * fTemp12) + ((((222541798100000.0 * fTemp14) + (276572225200000.0 * fTemp9)) + (2703087023000.0 * fTemp10)) + (22555408860000.0 * fTemp11))) - ((129898492500000.0 * fTemp8) + (11038374010000.0 * fTemp13))));
			fRec520[0] = ((fTemp251 + (fRec520[1] + fTemp252)) + fTemp253);
			fRec518[0] = fRec520[0];
			double fRec519 = ((fTemp252 + fTemp251) + fTemp253);
			fRec517[0] = (fRec518[0] + fRec517[1]);
			fRec515[0] = fRec517[0];
			double fRec516 = fRec519;
			fRec514[0] = (fTemp250 + (fRec516 + fRec514[1]));
			fRec512[0] = fRec514[0];
			double fRec513 = (fRec516 + fTemp250);
			double fTemp254 = (fConst15 * ((240733790800000.0 * fTemp26) - ((49028589890000.0 * fTemp28) + (51265903140000.0 * fTemp27))));
			double fTemp255 = (fConst16 * fRec521[1]);
			fRec523[0] = (fTemp254 + (fRec523[1] + fTemp255));
			fRec521[0] = fRec523[0];
			double fRec522 = (fTemp255 + fTemp254);
			double fTemp256 = (fConst11 * (((61889381050000.0 * fTemp18) + (1082710866000.0 * fTemp21)) - (((372625277900000.0 * fTemp19) + (1996406766000.0 * fTemp20)) + (130961176900000.0 * fTemp22))));
			double fTemp257 = (fConst12 * fRec527[1]);
			double fTemp258 = (fConst13 * fRec524[1]);
			fRec529[0] = (((fTemp256 + fRec529[1]) + fTemp257) + fTemp258);
			fRec527[0] = fRec529[0];
			double fRec528 = ((fTemp256 + fTemp257) + fTemp258);
			fRec526[0] = (fRec527[0] + fRec526[1]);
			fRec524[0] = fRec526[0];
			double fRec525 = fRec528;
			fVec10[(IOTA & 1023)] = ((54231368680000.0 * fTemp58) + (fRec486 + (fRec501 + (fRec513 + (fRec522 + fRec525)))));
			output10[i] = FAUSTFLOAT((0.82065997130559543 * (fRec0[0] * fVec10[((IOTA - iConst33) & 1023)])));
			double fTemp259 = (fConst25 * fRec530[1]);
			double fTemp260 = (fConst27 * fRec533[1]);
			double fTemp261 = (fConst28 * fRec536[1]);
			double fTemp262 = (fConst30 * (((61271527700000.0 * fTemp54) + (((7324073383000.0 * fTemp47) + (49946685060000.0 * fTemp49)) + (193943793000000.0 * fTemp53))) - ((((21877158800000.0 * fTemp48) + (268704201100000.0 * fTemp51)) + (4123922494000.0 * fTemp52)) + (5728123571000.0 * fTemp50))));
			double fTemp263 = (fConst31 * fRec539[1]);
			double fTemp264 = (fConst32 * fRec542[1]);
			fRec544[0] = (fTemp262 + (fTemp263 + (fRec544[1] + fTemp264)));
			fRec542[0] = fRec544[0];
			double fRec543 = ((fTemp264 + fTemp263) + fTemp262);
			fRec541[0] = (fRec542[0] + fRec541[1]);
			fRec539[0] = fRec541[0];
			double fRec540 = fRec543;
			fRec538[0] = (fTemp260 + (fTemp261 + (fRec540 + fRec538[1])));
			fRec536[0] = fRec538[0];
			double fRec537 = (fTemp260 + (fRec540 + fTemp261));
			fRec535[0] = (fRec536[0] + fRec535[1]);
			fRec533[0] = fRec535[0];
			double fRec534 = fRec537;
			fRec532[0] = (fTemp259 + (fRec534 + fRec532[1]));
			fRec530[0] = fRec532[0];
			double fRec531 = (fRec534 + fTemp259);
			double fTemp265 = (fConst3 * fRec545[1]);
			double fTemp266 = (fConst5 * (((79969633220000.0 * fTemp8) + (64619121260000.0 * fTemp11)) - ((17857797320000.0 * fTemp13) + ((((245293897200000.0 * fTemp14) + (146394418000000.0 * fTemp9)) + (4704393478000.0 * fTemp10)) + (113312211200000.0 * fTemp12)))));
			double fTemp267 = (fConst8 * fRec548[1]);
			double fTemp268 = (fConst9 * fRec551[1]);
			fRec553[0] = (fTemp266 + (fTemp267 + (fRec553[1] + fTemp268)));
			fRec551[0] = fRec553[0];
			double fRec552 = ((fTemp268 + fTemp267) + fTemp266);
			fRec550[0] = (fRec551[0] + fRec550[1]);
			fRec548[0] = fRec550[0];
			double fRec549 = fRec552;
			fRec547[0] = (fTemp265 + (fRec549 + fRec547[1]));
			fRec545[0] = fRec547[0];
			double fRec546 = (fRec549 + fTemp265);
			double fTemp269 = (fConst11 * (((182137616100000.0 * fTemp19) + (111155998300000.0 * fTemp22)) - (((104510877400000.0 * fTemp18) + (66740778700000.0 * fTemp20)) + (31774874930000.0 * fTemp21))));
			double fTemp270 = (fConst13 * fRec554[1]);
			double fTemp271 = (fConst12 * fRec557[1]);
			fRec559[0] = (fTemp269 + (fTemp270 + (fRec559[1] + fTemp271)));
			fRec557[0] = fRec559[0];
			double fRec558 = ((fTemp271 + fTemp270) + fTemp269);
			fRec556[0] = (fRec557[0] + fRec556[1]);
			fRec554[0] = fRec556[0];
			double fRec555 = fRec558;
			double fTemp272 = (fConst22 * fRec560[1]);
			double fTemp273 = (fConst23 * fRec563[1]);
			double fTemp274 = (fConst19 * (((55728679490000.0 * fTemp38) + (((364955525500000.0 * fTemp32) + (50671247600000.0 * fTemp35)) + (66117682540000.0 * fTemp37))) - ((((28517523090000.0 * fTemp31) + (56363310320000.0 * fTemp34)) + (9674830787000.0 * fTemp36)) + (185269324500000.0 * fTemp33))));
			double fTemp275 = (fConst20 * fRec566[1]);
			double fTemp276 = (fConst21 * fRec569[1]);
			fRec571[0] = (fTemp274 + (fTemp275 + (fRec571[1] + fTemp276)));
			fRec569[0] = fRec571[0];
			double fRec570 = ((fTemp276 + fTemp275) + fTemp274);
			fRec568[0] = (fRec569[0] + fRec568[1]);
			fRec566[0] = fRec568[0];
			double fRec567 = fRec570;
			fRec565[0] = (fTemp272 + (fTemp273 + (fRec567 + fRec565[1])));
			fRec563[0] = fRec565[0];
			double fRec564 = (fTemp272 + (fRec567 + fTemp273));
			fRec562[0] = (fRec563[0] + fRec562[1]);
			fRec560[0] = fRec562[0];
			double fRec561 = fRec564;
			double fTemp277 = (fConst15 * ((80987440810000.0 * fTemp28) - ((75309676510000.0 * fTemp26) + (21485328390000.0 * fTemp27))));
			double fTemp278 = (fConst16 * fRec572[1]);
			fRec574[0] = (fTemp277 + (fRec574[1] + fTemp278));
			fRec572[0] = fRec574[0];
			double fRec573 = (fTemp278 + fTemp277);
			fVec11[(IOTA & 1023)] = ((fRec531 + (fRec546 + (fRec555 + (fRec561 + fRec573)))) - (4489356042000.0 * fTemp58));
			output11[i] = FAUSTFLOAT((0.82065997130559543 * (fRec0[0] * fVec11[((IOTA - iConst33) & 1023)])));
			double fTemp279 = (fConst15 * ((35362142140000.0 * fTemp26) - ((147615512500000.0 * fTemp28) + (67857869870000.0 * fTemp27))));
			double fTemp280 = (fConst16 * fRec575[1]);
			fRec577[0] = (fTemp279 + (fRec577[1] + fTemp280));
			fRec575[0] = fRec577[0];
			double fRec576 = (fTemp280 + fTemp279);
			double fTemp281 = (fConst25 * fRec578[1]);
			double fTemp282 = (fConst27 * fRec581[1]);
			double fTemp283 = (fConst28 * fRec584[1]);
			double fTemp284 = (fConst30 * ((((30508673140000.0 * fTemp48) + (235643937500000.0 * fTemp51)) + (62702634890000.0 * fTemp52)) - ((20110848860000.0 * fTemp54) + ((332532796200000.0 * fTemp53) + (((55402248130000.0 * fTemp47) + (6128778676000.0 * fTemp49)) + (64239598310000.0 * fTemp50))))));
			double fTemp285 = (fConst31 * fRec587[1]);
			double fTemp286 = (fConst32 * fRec590[1]);
			fRec592[0] = (fTemp284 + (fTemp285 + (fRec592[1] + fTemp286)));
			fRec590[0] = fRec592[0];
			double fRec591 = ((fTemp286 + fTemp285) + fTemp284);
			fRec589[0] = (fRec590[0] + fRec589[1]);
			fRec587[0] = fRec589[0];
			double fRec588 = fRec591;
			fRec586[0] = (fTemp282 + (fTemp283 + (fRec588 + fRec586[1])));
			fRec584[0] = fRec586[0];
			double fRec585 = (fTemp282 + (fRec588 + fTemp283));
			fRec583[0] = (fRec584[0] + fRec583[1]);
			fRec581[0] = fRec583[0];
			double fRec582 = fRec585;
			fRec580[0] = (fTemp281 + (fRec582 + fRec580[1]));
			fRec578[0] = fRec580[0];
			double fRec579 = (fRec582 + fTemp281);
			double fTemp287 = (fConst22 * fRec593[1]);
			double fTemp288 = (fConst23 * fRec596[1]);
			double fTemp289 = (fConst19 * ((((8202263832000.0 * fTemp37) + ((((30265066450000.0 * fTemp31) + (31538538350000.0 * fTemp34)) + (709395799200.0 * fTemp35)) + (19307760420000.0 * fTemp36))) + (181833434400000.0 * fTemp33)) - ((324859334600000.0 * fTemp32) + (6779417920000.0 * fTemp38))));
			double fTemp290 = (fConst20 * fRec599[1]);
			double fTemp291 = (fConst21 * fRec602[1]);
			fRec604[0] = (fTemp289 + (fTemp290 + (fRec604[1] + fTemp291)));
			fRec602[0] = fRec604[0];
			double fRec603 = ((fTemp291 + fTemp290) + fTemp289);
			fRec601[0] = (fRec602[0] + fRec601[1]);
			fRec599[0] = fRec601[0];
			double fRec600 = fRec603;
			fRec598[0] = (fTemp287 + (fTemp288 + (fRec600 + fRec598[1])));
			fRec596[0] = fRec598[0];
			double fRec597 = (fTemp287 + (fRec600 + fTemp288));
			fRec595[0] = (fRec596[0] + fRec595[1]);
			fRec593[0] = fRec595[0];
			double fRec594 = fRec597;
			double fTemp292 = (fConst11 * ((((34311284150000.0 * fTemp20) + (58629005050000.0 * fTemp21)) + (3362538669000.0 * fTemp22)) - ((86350568510000.0 * fTemp18) + (1461029618000.0 * fTemp19))));
			double fTemp293 = (fConst13 * fRec605[1]);
			double fTemp294 = (fConst12 * fRec608[1]);
			fRec610[0] = (fTemp292 + (fTemp293 + (fRec610[1] + fTemp294)));
			fRec608[0] = fRec610[0];
			double fRec609 = ((fTemp294 + fTemp293) + fTemp292);
			fRec607[0] = (fRec608[0] + fRec607[1]);
			fRec605[0] = fRec607[0];
			double fRec606 = fRec609;
			double fTemp295 = (fConst3 * fRec611[1]);
			double fTemp296 = (fConst5 * (((53067256580000.0 * fTemp13) + ((((286680226900000.0 * fTemp14) + (53087323260000.0 * fTemp8)) + (20485543480000.0 * fTemp10)) + (389520855900.0 * fTemp12))) - ((56982048590000.0 * fTemp9) + (37535684280000.0 * fTemp11))));
			double fTemp297 = (fConst8 * fRec614[1]);
			double fTemp298 = (fConst9 * fRec617[1]);
			fRec619[0] = (fTemp296 + (fTemp297 + (fRec619[1] + fTemp298)));
			fRec617[0] = fRec619[0];
			double fRec618 = ((fTemp298 + fTemp297) + fTemp296);
			fRec616[0] = (fRec617[0] + fRec616[1]);
			fRec614[0] = fRec616[0];
			double fRec615 = fRec618;
			fRec613[0] = (fTemp295 + (fRec615 + fRec613[1]));
			fRec611[0] = fRec613[0];
			double fRec612 = (fRec615 + fTemp295);
			fVec12[(IOTA & 1023)] = ((fRec576 + (fRec579 + (fRec594 + (fRec606 + fRec612)))) + (98296442710000.0 * fTemp58));
			output12[i] = FAUSTFLOAT((0.82065997130559543 * (fRec0[0] * fVec12[((IOTA - iConst33) & 1023)])));
			double fTemp299 = (fConst25 * fRec620[1]);
			double fTemp300 = (fConst27 * fRec623[1]);
			double fTemp301 = (fConst28 * fRec626[1]);
			double fTemp302 = (fConst30 * (((398449900400000.0 * fTemp53) + ((42198495480000.0 * fTemp47) + (16708540920000.0 * fTemp50))) - (((((27523286550000.0 * fTemp48) + (147218433600000.0 * fTemp51)) + (11229079560000.0 * fTemp49)) + (39919122900000.0 * fTemp52)) + (47646775400000.0 * fTemp54))));
			double fTemp303 = (fConst31 * fRec629[1]);
			double fTemp304 = (fConst32 * fRec632[1]);
			fRec634[0] = (fTemp302 + (fTemp303 + (fRec634[1] + fTemp304)));
			fRec632[0] = fRec634[0];
			double fRec633 = ((fTemp304 + fTemp303) + fTemp302);
			fRec631[0] = (fRec632[0] + fRec631[1]);
			fRec629[0] = fRec631[0];
			double fRec630 = fRec633;
			fRec628[0] = (fTemp300 + (fTemp301 + (fRec630 + fRec628[1])));
			fRec626[0] = fRec628[0];
			double fRec627 = (fTemp300 + (fRec630 + fTemp301));
			fRec625[0] = (fRec626[0] + fRec625[1]);
			fRec623[0] = fRec625[0];
			double fRec624 = fRec627;
			fRec622[0] = (fTemp299 + (fRec624 + fRec622[1]));
			fRec620[0] = fRec622[0];
			double fRec621 = (fRec624 + fTemp299);
			double fTemp305 = (fConst22 * fRec635[1]);
			double fTemp306 = (fConst23 * fRec638[1]);
			double fTemp307 = (fConst19 * (((((61755187250000.0 * fTemp31) + (192756303600000.0 * fTemp32)) + (131487630300000.0 * fTemp34)) + (21061019550000.0 * fTemp38)) - ((((39372382280000.0 * fTemp35) + (20311734500000.0 * fTemp36)) + (26742730440000.0 * fTemp37)) + (208907163400000.0 * fTemp33))));
			double fTemp308 = (fConst20 * fRec641[1]);
			double fTemp309 = (fConst21 * fRec644[1]);
			fRec646[0] = (fTemp307 + (fTemp308 + (fRec646[1] + fTemp309)));
			fRec644[0] = fRec646[0];
			double fRec645 = ((fTemp309 + fTemp308) + fTemp307);
			fRec643[0] = (fRec644[0] + fRec643[1]);
			fRec641[0] = fRec643[0];
			double fRec642 = fRec645;
			fRec640[0] = (fTemp305 + (fTemp306 + (fRec642 + fRec640[1])));
			fRec638[0] = fRec640[0];
			double fRec639 = (fTemp305 + (fRec642 + fTemp306));
			fRec637[0] = (fRec638[0] + fRec637[1]);
			fRec635[0] = fRec637[0];
			double fRec636 = fRec639;
			double fTemp310 = (fConst3 * fRec647[1]);
			double fTemp311 = (fConst5 * (((29045630830000.0 * fTemp13) + ((67851371110000.0 * fTemp12) + ((45649660450000.0 * fTemp9) + (70578172950000.0 * fTemp11)))) - (((231793726800000.0 * fTemp14) + (236582292900000.0 * fTemp8)) + (21583111820000.0 * fTemp10))));
			double fTemp312 = (fConst8 * fRec650[1]);
			double fTemp313 = (fConst9 * fRec653[1]);
			fRec655[0] = (fTemp311 + (fTemp312 + (fRec655[1] + fTemp313)));
			fRec653[0] = fRec655[0];
			double fRec654 = ((fTemp313 + fTemp312) + fTemp311);
			fRec652[0] = (fRec653[0] + fRec652[1]);
			fRec650[0] = fRec652[0];
			double fRec651 = fRec654;
			fRec649[0] = (fTemp310 + (fRec651 + fRec649[1]));
			fRec647[0] = fRec649[0];
			double fRec648 = (fRec651 + fTemp310);
			double fTemp314 = (fConst15 * (((94734934880000.0 * fTemp26) + (155474265400000.0 * fTemp28)) + (37745102380000.0 * fTemp27)));
			double fTemp315 = (fConst16 * fRec656[1]);
			fRec658[0] = (fTemp314 + (fRec658[1] + fTemp315));
			fRec656[0] = fRec658[0];
			double fRec657 = (fTemp315 + fTemp314);
			double fTemp316 = (fConst11 * ((139676578200000.0 * fTemp18) - ((((50568464610000.0 * fTemp19) + (92065272500000.0 * fTemp20)) + (71955171590000.0 * fTemp21)) + (142062975900000.0 * fTemp22))));
			double fTemp317 = (fConst13 * fRec659[1]);
			double fTemp318 = (fConst12 * fRec662[1]);
			fRec664[0] = (fTemp316 + (fTemp317 + (fRec664[1] + fTemp318)));
			fRec662[0] = fRec664[0];
			double fRec663 = ((fTemp318 + fTemp317) + fTemp316);
			fRec661[0] = (fRec662[0] + fRec661[1]);
			fRec659[0] = fRec661[0];
			double fRec660 = fRec663;
			fVec13[(IOTA & 1023)] = ((fRec621 + (fRec636 + (fRec648 + (fRec657 + fRec660)))) - (35467608230000.0 * fTemp58));
			output13[i] = FAUSTFLOAT((0.82065997130559543 * (fRec0[0] * fVec13[((IOTA - iConst33) & 1023)])));
			double fTemp319 = (fConst22 * fRec665[1]);
			double fTemp320 = (fConst23 * fRec668[1]);
			double fTemp321 = (fConst19 * ((((107373336300000.0 * fTemp37) + ((16515257630000.0 * fTemp35) + (14759419800000.0 * fTemp36))) + (226629103900000.0 * fTemp33)) - ((((66497240540000.0 * fTemp31) + (55418719610000.0 * fTemp32)) + (227239143600000.0 * fTemp34)) + (46615431410000.0 * fTemp38))));
			double fTemp322 = (fConst20 * fRec671[1]);
			double fTemp323 = (fConst21 * fRec674[1]);
			fRec676[0] = (fTemp321 + (fTemp322 + (fRec676[1] + fTemp323)));
			fRec674[0] = fRec676[0];
			double fRec675 = ((fTemp323 + fTemp322) + fTemp321);
			fRec673[0] = (fRec674[0] + fRec673[1]);
			fRec671[0] = fRec673[0];
			double fRec672 = fRec675;
			fRec670[0] = (fTemp319 + (fTemp320 + (fRec672 + fRec670[1])));
			fRec668[0] = fRec670[0];
			double fRec669 = (fTemp319 + (fRec672 + fTemp320));
			fRec667[0] = (fRec668[0] + fRec667[1]);
			fRec665[0] = fRec667[0];
			double fRec666 = fRec669;
			double fTemp324 = (fConst3 * fRec677[1]);
			double fTemp325 = (fConst5 * (((334808572900000.0 * fTemp8) + (11304803420000.0 * fTemp10)) - ((7648923346000.0 * fTemp13) + ((((6420716527000.0 * fTemp14) + (85861237210000.0 * fTemp9)) + (46625287330000.0 * fTemp11)) + (118217737100000.0 * fTemp12)))));
			double fTemp326 = (fConst8 * fRec680[1]);
			double fTemp327 = (fConst9 * fRec683[1]);
			fRec685[0] = (fTemp325 + (fTemp326 + (fRec685[1] + fTemp327)));
			fRec683[0] = fRec685[0];
			double fRec684 = ((fTemp327 + fTemp326) + fTemp325);
			fRec682[0] = (fRec683[0] + fRec682[1]);
			fRec680[0] = fRec682[0];
			double fRec681 = fRec684;
			fRec679[0] = (fTemp324 + (fRec681 + fRec679[1]));
			fRec677[0] = fRec679[0];
			double fRec678 = (fRec681 + fTemp324);
			double fTemp328 = (fConst11 * (((((43651010590000.0 * fTemp19) + (30317780380000.0 * fTemp20)) + (41498539910000.0 * fTemp21)) + (61690238850000.0 * fTemp22)) - (203294225100000.0 * fTemp18)));
			double fTemp329 = (fConst13 * fRec686[1]);
			double fTemp330 = (fConst12 * fRec689[1]);
			fRec691[0] = (fTemp328 + (fTemp329 + (fRec691[1] + fTemp330)));
			fRec689[0] = fRec691[0];
			double fRec690 = ((fTemp330 + fTemp329) + fTemp328);
			fRec688[0] = (fRec689[0] + fRec688[1]);
			fRec686[0] = fRec688[0];
			double fRec687 = fRec690;
			double fTemp331 = (fConst25 * fRec692[1]);
			double fTemp332 = (fConst27 * fRec695[1]);
			double fTemp333 = (fConst28 * fRec698[1]);
			double fTemp334 = (fConst30 * ((((((((30603667340000.0 * fTemp47) + (23679316260000.0 * fTemp48)) + (64397222970000.0 * fTemp51)) + (44767862400000.0 * fTemp49)) + (55711319450000.0 * fTemp52)) + (24062530010000.0 * fTemp50)) + (53683425050000.0 * fTemp54)) - (261774107300000.0 * fTemp53)));
			double fTemp335 = (fConst31 * fRec701[1]);
			double fTemp336 = (fConst32 * fRec704[1]);
			fRec706[0] = (fTemp334 + (fTemp335 + (fRec706[1] + fTemp336)));
			fRec704[0] = fRec706[0];
			double fRec705 = ((fTemp336 + fTemp335) + fTemp334);
			fRec703[0] = (fRec704[0] + fRec703[1]);
			fRec701[0] = fRec703[0];
			double fRec702 = fRec705;
			fRec700[0] = (fTemp332 + (fTemp333 + (fRec702 + fRec700[1])));
			fRec698[0] = fRec700[0];
			double fRec699 = (fTemp332 + (fRec702 + fTemp333));
			fRec697[0] = (fRec698[0] + fRec697[1]);
			fRec695[0] = fRec697[0];
			double fRec696 = fRec699;
			fRec694[0] = (fTemp331 + (fRec696 + fRec694[1]));
			fRec692[0] = fRec694[0];
			double fRec693 = (fRec696 + fTemp331);
			double fTemp337 = (fConst15 * ((24268434410000.0 * fTemp26) - ((126974439500000.0 * fTemp28) + (14563872650000.0 * fTemp27))));
			double fTemp338 = (fConst16 * fRec707[1]);
			fRec709[0] = (fTemp337 + (fRec709[1] + fTemp338));
			fRec707[0] = fRec709[0];
			double fRec708 = (fTemp338 + fTemp337);
			fVec14[(IOTA & 1023)] = ((91597005870000.0 * fTemp58) + (fRec666 + (fRec678 + (fRec687 + (fRec693 + fRec708)))));
			output14[i] = FAUSTFLOAT((0.82065997130559543 * (fRec0[0] * fVec14[((IOTA - iConst33) & 1023)])));
			double fTemp339 = (fConst25 * fRec710[1]);
			double fTemp340 = (fConst27 * fRec713[1]);
			double fTemp341 = (fConst28 * fRec716[1]);
			double fTemp342 = (fConst30 * ((((49381409990000.0 * fTemp51) + (43449322160000.0 * fTemp52)) + (161702279600000.0 * fTemp53)) - (((((63890004680000.0 * fTemp47) + (18660987830000.0 * fTemp48)) + (81671746670000.0 * fTemp49)) + (22524239350000.0 * fTemp50)) + (7378796714000.0 * fTemp54))));
			double fTemp343 = (fConst31 * fRec719[1]);
			double fTemp344 = (fConst32 * fRec722[1]);
			fRec724[0] = (fTemp342 + (fTemp343 + (fRec724[1] + fTemp344)));
			fRec722[0] = fRec724[0];
			double fRec723 = ((fTemp344 + fTemp343) + fTemp342);
			fRec721[0] = (fRec722[0] + fRec721[1]);
			fRec719[0] = fRec721[0];
			double fRec720 = fRec723;
			fRec718[0] = (fTemp340 + (fTemp341 + (fRec720 + fRec718[1])));
			fRec716[0] = fRec718[0];
			double fRec717 = (fTemp340 + (fRec720 + fTemp341));
			fRec715[0] = (fRec716[0] + fRec715[1]);
			fRec713[0] = fRec715[0];
			double fRec714 = fRec717;
			fRec712[0] = (fTemp339 + (fRec714 + fRec712[1]));
			fRec710[0] = fRec712[0];
			double fRec711 = (fRec714 + fTemp339);
			double fTemp345 = (fConst22 * fRec725[1]);
			double fTemp346 = (fConst23 * fRec728[1]);
			double fTemp347 = (fConst19 * (((218429149500000.0 * fTemp34) + (103098818800000.0 * fTemp38)) - ((((((22512905670000.0 * fTemp31) + (92173865060000.0 * fTemp32)) + (8929449820000.0 * fTemp35)) + (5049158432000.0 * fTemp36)) + (42406364930000.0 * fTemp37)) + (172801900400000.0 * fTemp33))));
			double fTemp348 = (fConst20 * fRec731[1]);
			double fTemp349 = (fConst21 * fRec734[1]);
			fRec736[0] = (fTemp347 + (fTemp348 + (fRec736[1] + fTemp349)));
			fRec734[0] = fRec736[0];
			double fRec735 = ((fTemp349 + fTemp348) + fTemp347);
			fRec733[0] = (fRec734[0] + fRec733[1]);
			fRec731[0] = fRec733[0];
			double fRec732 = fRec735;
			fRec730[0] = (fTemp345 + (fTemp346 + (fRec732 + fRec730[1])));
			fRec728[0] = fRec730[0];
			double fRec729 = (fTemp345 + (fRec732 + fTemp346));
			fRec727[0] = (fRec728[0] + fRec727[1]);
			fRec725[0] = fRec727[0];
			double fRec726 = fRec729;
			double fTemp350 = (fConst3 * fRec737[1]);
			double fTemp351 = (fConst5 * (((102558696900000.0 * fTemp14) + (62270773540000.0 * fTemp12)) - (((((357914554000000.0 * fTemp8) + (39926419890000.0 * fTemp9)) + (1864468678000.0 * fTemp10)) + (30586734060000.0 * fTemp11)) + (139105960400000.0 * fTemp13))));
			double fTemp352 = (fConst8 * fRec740[1]);
			double fTemp353 = (fConst9 * fRec743[1]);
			fRec745[0] = (fTemp351 + (fTemp352 + (fRec745[1] + fTemp353)));
			fRec743[0] = fRec745[0];
			double fRec744 = ((fTemp353 + fTemp352) + fTemp351);
			fRec742[0] = (fRec743[0] + fRec742[1]);
			fRec740[0] = fRec742[0];
			double fRec741 = fRec744;
			fRec739[0] = (fTemp350 + (fRec741 + fRec739[1]));
			fRec737[0] = fRec739[0];
			double fRec738 = (fRec741 + fTemp350);
			double fTemp354 = (fConst15 * (((26322823560000.0 * fTemp26) + (67636522730000.0 * fTemp28)) + (19947483910000.0 * fTemp27)));
			double fTemp355 = (fConst16 * fRec746[1]);
			fRec748[0] = (fTemp354 + (fRec748[1] + fTemp355));
			fRec746[0] = fRec748[0];
			double fRec747 = (fTemp355 + fTemp354);
			double fTemp356 = (fConst11 * ((((301092729200000.0 * fTemp18) + (24351864490000.0 * fTemp19)) + (22849748200000.0 * fTemp21)) - ((63196633820000.0 * fTemp20) + (45948995760000.0 * fTemp22))));
			double fTemp357 = (fConst13 * fRec749[1]);
			double fTemp358 = (fConst12 * fRec752[1]);
			fRec754[0] = (fTemp356 + (fTemp357 + (fRec754[1] + fTemp358)));
			fRec752[0] = fRec754[0];
			double fRec753 = ((fTemp358 + fTemp357) + fTemp356);
			fRec751[0] = (fRec752[0] + fRec751[1]);
			fRec749[0] = fRec751[0];
			double fRec750 = fRec753;
			fVec15[(IOTA & 1023)] = ((2741736566000.0 * fTemp58) + (fRec711 + (fRec726 + (fRec738 + (fRec747 + fRec750)))));
			output15[i] = FAUSTFLOAT((0.82065997130559543 * (fRec0[0] * fVec15[((IOTA - iConst33) & 1023)])));
			double fTemp359 = (fConst35 * fRec755[1]);
			double fTemp360 = (fConst37 * fRec758[1]);
			double fTemp361 = (fConst38 * fRec761[1]);
			double fTemp362 = (fConst40 * (((((16876297630000.0 * fTemp47) + (57638690840000.0 * fTemp48)) + (54050237820000.0 * fTemp51)) + (26739227280000.0 * fTemp50)) - ((7483857761000.0 * fTemp54) + (((21849160950000.0 * fTemp49) + (809373674200.0 * fTemp52)) + (3052566528000.0 * fTemp53)))));
			double fTemp363 = (fConst41 * fRec764[1]);
			double fTemp364 = (fConst42 * fRec767[1]);
			fRec769[0] = (fTemp362 + (fTemp363 + (fRec769[1] + fTemp364)));
			fRec767[0] = fRec769[0];
			double fRec768 = ((fTemp364 + fTemp363) + fTemp362);
			fRec766[0] = (fRec767[0] + fRec766[1]);
			fRec764[0] = fRec766[0];
			double fRec765 = fRec768;
			fRec763[0] = (fTemp360 + (fTemp361 + (fRec765 + fRec763[1])));
			fRec761[0] = fRec763[0];
			double fRec762 = (fTemp360 + (fRec765 + fTemp361));
			fRec760[0] = (fRec761[0] + fRec760[1]);
			fRec758[0] = fRec760[0];
			double fRec759 = fRec762;
			fRec757[0] = (fTemp359 + (fRec759 + fRec757[1]));
			fRec755[0] = fRec757[0];
			double fRec756 = (fRec759 + fTemp359);
			double fTemp365 = (fConst44 * fRec770[1]);
			double fTemp366 = (fConst45 * fRec773[1]);
			double fTemp367 = (fConst47 * (((1960080576000.0 * fTemp33) + ((22083733680000.0 * fTemp38) + ((((327880054800.0 * fTemp31) + (49582517540000.0 * fTemp32)) + (36998073570000.0 * fTemp34)) + (45678111950000.0 * fTemp37)))) - ((19489270080000.0 * fTemp35) + (47758734750000.0 * fTemp36))));
			double fTemp368 = (fConst48 * fRec776[1]);
			double fTemp369 = (fConst49 * fRec779[1]);
			fRec781[0] = (fTemp367 + (fTemp368 + (fRec781[1] + fTemp369)));
			fRec779[0] = fRec781[0];
			double fRec780 = ((fTemp369 + fTemp368) + fTemp367);
			fRec778[0] = (fRec779[0] + fRec778[1]);
			fRec776[0] = fRec778[0];
			double fRec777 = fRec780;
			fRec775[0] = (fTemp365 + (fTemp366 + (fRec777 + fRec775[1])));
			fRec773[0] = fRec775[0];
			double fRec774 = (fTemp365 + (fRec777 + fTemp366));
			fRec772[0] = (fRec773[0] + fRec772[1]);
			fRec770[0] = fRec772[0];
			double fRec771 = fRec774;
			double fTemp370 = (fConst51 * fRec782[1]);
			double fTemp371 = (fConst53 * (((8707384529000.0 * fTemp13) + ((48582058770000.0 * fTemp12) + ((((19286025820000.0 * fTemp14) + (39805807280000.0 * fTemp8)) + (9917071795000.0 * fTemp9)) + (43054024400000.0 * fTemp11)))) - (45917603350000.0 * fTemp10)));
			double fTemp372 = (fConst54 * fRec785[1]);
			double fTemp373 = (fConst55 * fRec788[1]);
			fRec790[0] = (fTemp371 + (fTemp372 + (fRec790[1] + fTemp373)));
			fRec788[0] = fRec790[0];
			double fRec789 = ((fTemp373 + fTemp372) + fTemp371);
			fRec787[0] = (fRec788[0] + fRec787[1]);
			fRec785[0] = fRec787[0];
			double fRec786 = fRec789;
			fRec784[0] = (fTemp370 + (fRec786 + fRec784[1]));
			fRec782[0] = fRec784[0];
			double fRec783 = (fRec786 + fTemp370);
			double fTemp374 = (fConst57 * (((5879177869000.0 * fTemp26) + (39663754150000.0 * fTemp28)) + (18163591690000.0 * fTemp27)));
			double fTemp375 = (fConst58 * fRec791[1]);
			fRec793[0] = (fTemp374 + (fRec793[1] + fTemp375));
			fRec791[0] = fRec793[0];
			double fRec792 = (fTemp375 + fTemp374);
			double fTemp376 = (fConst60 * (((((11500799320000.0 * fTemp18) + (16307512050000.0 * fTemp19)) + (7080140816000.0 * fTemp20)) + (56748458230000.0 * fTemp21)) + (22000326970000.0 * fTemp22)));
			double fTemp377 = (fConst61 * fRec794[1]);
			double fTemp378 = (fConst62 * fRec797[1]);
			fRec799[0] = (fTemp376 + (fTemp377 + (fRec799[1] + fTemp378)));
			fRec797[0] = fRec799[0];
			double fRec798 = ((fTemp378 + fTemp377) + fTemp376);
			fRec796[0] = (fRec797[0] + fRec796[1]);
			fRec794[0] = fRec796[0];
			double fRec795 = fRec798;
			fVec16[0] = ((14702925660000.0 * fTemp58) + (fRec756 + (fRec771 + (fRec783 + (fRec792 + fRec795)))));
			output16[i] = FAUSTFLOAT((0.99982065997130565 * (fRec0[0] * fVec16[iConst63])));
			double fTemp379 = (fConst35 * fRec800[1]);
			double fTemp380 = (fConst37 * fRec803[1]);
			double fTemp381 = (fConst38 * fRec806[1]);
			double fTemp382 = (fConst40 * (((25697147120000.0 * fTemp49) + (9392598847000.0 * fTemp50)) - ((18102437350000.0 * fTemp54) + (((((8631104957000.0 * fTemp47) + (55204037250000.0 * fTemp48)) + (59982606350000.0 * fTemp51)) + (504357650800.0 * fTemp52)) + (33158043630000.0 * fTemp53)))));
			double fTemp383 = (fConst41 * fRec809[1]);
			double fTemp384 = (fConst42 * fRec812[1]);
			fRec814[0] = (fTemp382 + (fTemp383 + (fRec814[1] + fTemp384)));
			fRec812[0] = fRec814[0];
			double fRec813 = ((fTemp384 + fTemp383) + fTemp382);
			fRec811[0] = (fRec812[0] + fRec811[1]);
			fRec809[0] = fRec811[0];
			double fRec810 = fRec813;
			fRec808[0] = (fTemp380 + (fTemp381 + (fRec810 + fRec808[1])));
			fRec806[0] = fRec808[0];
			double fRec807 = (fTemp380 + (fRec810 + fTemp381));
			fRec805[0] = (fRec806[0] + fRec805[1]);
			fRec803[0] = fRec805[0];
			double fRec804 = fRec807;
			fRec802[0] = (fTemp379 + (fRec804 + fRec802[1]));
			fRec800[0] = fRec802[0];
			double fRec801 = (fRec804 + fTemp379);
			double fTemp385 = (fConst44 * fRec815[1]);
			double fTemp386 = (fConst45 * fRec818[1]);
			double fTemp387 = (fConst47 * (((1060679439000.0 * fTemp33) + ((5245398743000.0 * fTemp38) + (((1508793191000.0 * fTemp31) + (27872344670000.0 * fTemp35)) + (33380050830000.0 * fTemp37)))) - (((55341372030000.0 * fTemp32) + (44643967570000.0 * fTemp34)) + (44392902440000.0 * fTemp36))));
			double fTemp388 = (fConst48 * fRec821[1]);
			double fTemp389 = (fConst49 * fRec824[1]);
			fRec826[0] = (fTemp387 + (fTemp388 + (fRec826[1] + fTemp389)));
			fRec824[0] = fRec826[0];
			double fRec825 = ((fTemp389 + fTemp388) + fTemp387);
			fRec823[0] = (fRec824[0] + fRec823[1]);
			fRec821[0] = fRec823[0];
			double fRec822 = fRec825;
			fRec820[0] = (fTemp385 + (fTemp386 + (fRec822 + fRec820[1])));
			fRec818[0] = fRec820[0];
			double fRec819 = (fTemp385 + (fRec822 + fTemp386));
			fRec817[0] = (fRec818[0] + fRec817[1]);
			fRec815[0] = fRec817[0];
			double fRec816 = fRec819;
			double fTemp390 = (fConst51 * fRec827[1]);
			double fTemp391 = (fConst53 * (((1015610941000.0 * fTemp13) + ((38296024720000.0 * fTemp11) + (35358043500000.0 * fTemp12))) - ((((21518923940000.0 * fTemp14) + (48054169430000.0 * fTemp8)) + (16490372100000.0 * fTemp9)) + (46147401120000.0 * fTemp10))));
			double fTemp392 = (fConst54 * fRec830[1]);
			double fTemp393 = (fConst55 * fRec833[1]);
			fRec835[0] = (fTemp391 + (fTemp392 + (fRec835[1] + fTemp393)));
			fRec833[0] = fRec835[0];
			double fRec834 = ((fTemp393 + fTemp392) + fTemp391);
			fRec832[0] = (fRec833[0] + fRec832[1]);
			fRec830[0] = fRec832[0];
			double fRec831 = fRec834;
			fRec829[0] = (fTemp390 + (fRec831 + fRec829[1]));
			fRec827[0] = fRec829[0];
			double fRec828 = (fRec831 + fTemp390);
			double fTemp394 = (fConst57 * (((40143693240000.0 * fTemp28) + (16786869840000.0 * fTemp27)) - (7229365433000.0 * fTemp26)));
			double fTemp395 = (fConst58 * fRec836[1]);
			fRec838[0] = (fTemp394 + (fRec838[1] + fTemp395));
			fRec836[0] = fRec838[0];
			double fRec837 = (fTemp395 + fTemp394);
			double fTemp396 = (fConst60 * ((((6522129650000.0 * fTemp20) + (51360489990000.0 * fTemp21)) + (15894273350000.0 * fTemp22)) - ((14130159960000.0 * fTemp18) + (24368317800000.0 * fTemp19))));
			double fTemp397 = (fConst61 * fRec839[1]);
			double fTemp398 = (fConst62 * fRec842[1]);
			fRec844[0] = (fTemp396 + (fTemp397 + (fRec844[1] + fTemp398)));
			fRec842[0] = fRec844[0];
			double fRec843 = ((fTemp398 + fTemp397) + fTemp396);
			fRec841[0] = (fRec842[0] + fRec841[1]);
			fRec839[0] = fRec841[0];
			double fRec840 = fRec843;
			fVec17[0] = ((14296728110000.0 * fTemp58) + (fRec801 + (fRec816 + (fRec828 + (fRec837 + fRec840)))));
			output17[i] = FAUSTFLOAT((0.99982065997130565 * (fRec0[0] * fVec17[iConst63])));
			double fTemp399 = (fConst35 * fRec845[1]);
			double fTemp400 = (fConst37 * fRec848[1]);
			double fTemp401 = (fConst38 * fRec851[1]);
			double fTemp402 = (fConst40 * (((17603484830000.0 * fTemp54) + ((((((3922726079000.0 * fTemp47) + (66167550040000.0 * fTemp48)) + (35969832080000.0 * fTemp51)) + (18389888340000.0 * fTemp49)) + (1047704893000.0 * fTemp52)) + (4178969735000.0 * fTemp53))) - (56978951480000.0 * fTemp50)));
			double fTemp403 = (fConst41 * fRec854[1]);
			double fTemp404 = (fConst42 * fRec857[1]);
			fRec859[0] = (fTemp402 + (fTemp403 + (fRec859[1] + fTemp404)));
			fRec857[0] = fRec859[0];
			double fRec858 = ((fTemp404 + fTemp403) + fTemp402);
			fRec856[0] = (fRec857[0] + fRec856[1]);
			fRec854[0] = fRec856[0];
			double fRec855 = fRec858;
			fRec853[0] = (fTemp400 + (fTemp401 + (fRec855 + fRec853[1])));
			fRec851[0] = fRec853[0];
			double fRec852 = (fTemp400 + (fRec855 + fTemp401));
			fRec850[0] = (fRec851[0] + fRec850[1]);
			fRec848[0] = fRec850[0];
			double fRec849 = fRec852;
			fRec847[0] = (fTemp399 + (fRec849 + fRec847[1]));
			fRec845[0] = fRec847[0];
			double fRec846 = (fRec849 + fTemp399);
			double fTemp405 = (fConst44 * fRec860[1]);
			double fTemp406 = (fConst45 * fRec863[1]);
			double fTemp407 = (fConst47 * ((((30079988370000.0 * fTemp32) + (42354568010000.0 * fTemp35)) + (2681931080000.0 * fTemp33)) - ((50316640060000.0 * fTemp38) + ((((3996547375000.0 * fTemp31) + (33128992980000.0 * fTemp34)) + (18205959430000.0 * fTemp36)) + (46119648160000.0 * fTemp37)))));
			double fTemp408 = (fConst48 * fRec866[1]);
			double fTemp409 = (fConst49 * fRec869[1]);
			fRec871[0] = (fTemp407 + (fTemp408 + (fRec871[1] + fTemp409)));
			fRec869[0] = fRec871[0];
			double fRec870 = ((fTemp409 + fTemp408) + fTemp407);
			fRec868[0] = (fRec869[0] + fRec868[1]);
			fRec866[0] = fRec868[0];
			double fRec867 = fRec870;
			fRec865[0] = (fTemp405 + (fTemp406 + (fRec867 + fRec865[1])));
			fRec863[0] = fRec865[0];
			double fRec864 = (fTemp405 + (fRec867 + fTemp406));
			fRec862[0] = (fRec863[0] + fRec862[1]);
			fRec860[0] = fRec862[0];
			double fRec861 = fRec864;
			double fTemp410 = (fConst51 * fRec872[1]);
			double fTemp411 = (fConst53 * (((11277289080000.0 * fTemp14) + (8998426536000.0 * fTemp11)) - ((18011099760000.0 * fTemp13) + ((((35422943180000.0 * fTemp8) + (39748342950000.0 * fTemp9)) + (41761093790000.0 * fTemp10)) + (49433037150000.0 * fTemp12)))));
			double fTemp412 = (fConst54 * fRec875[1]);
			double fTemp413 = (fConst55 * fRec878[1]);
			fRec880[0] = (fTemp411 + (fTemp412 + (fRec880[1] + fTemp413)));
			fRec878[0] = fRec880[0];
			double fRec879 = ((fTemp413 + fTemp412) + fTemp411);
			fRec877[0] = (fRec878[0] + fRec877[1]);
			fRec875[0] = fRec877[0];
			double fRec876 = fRec879;
			fRec874[0] = (fTemp410 + (fRec876 + fRec874[1]));
			fRec872[0] = fRec874[0];
			double fRec873 = (fRec876 + fTemp410);
			double fTemp414 = (fConst57 * (((35763550110000.0 * fTemp28) + (4579615219000.0 * fTemp27)) - (19287967630000.0 * fTemp26)));
			double fTemp415 = (fConst58 * fRec881[1]);
			fRec883[0] = (fTemp414 + (fRec883[1] + fTemp415));
			fRec881[0] = fRec883[0];
			double fRec882 = (fTemp415 + fTemp414);
			double fTemp416 = (fConst60 * (((6491978763000.0 * fTemp20) + (14462143220000.0 * fTemp21)) - (((10362115440000.0 * fTemp18) + (53509438900000.0 * fTemp19)) + (22696827390000.0 * fTemp22))));
			double fTemp417 = (fConst61 * fRec884[1]);
			double fTemp418 = (fConst62 * fRec887[1]);
			fRec889[0] = (fTemp416 + (fTemp417 + (fRec889[1] + fTemp418)));
			fRec887[0] = fRec889[0];
			double fRec888 = ((fTemp418 + fTemp417) + fTemp416);
			fRec886[0] = (fRec887[0] + fRec886[1]);
			fRec884[0] = fRec886[0];
			double fRec885 = fRec888;
			fVec18[0] = ((15434782950000.0 * fTemp58) + (fRec846 + (fRec861 + (fRec873 + (fRec882 + fRec885)))));
			output18[i] = FAUSTFLOAT((0.99982065997130565 * (fRec0[0] * fVec18[iConst63])));
			double fTemp419 = (fConst35 * fRec890[1]);
			double fTemp420 = (fConst37 * fRec893[1]);
			double fTemp421 = (fConst38 * fRec896[1]);
			double fTemp422 = (fConst40 * (((58664752860000.0 * fTemp50) + (((11606006160000.0 * fTemp47) + (17169670130000.0 * fTemp51)) + (1318123435000.0 * fTemp52))) - ((13074761270000.0 * fTemp54) + (((63747076270000.0 * fTemp48) + (24968321370000.0 * fTemp49)) + (14150182640000.0 * fTemp53)))));
			double fTemp423 = (fConst41 * fRec899[1]);
			double fTemp424 = (fConst42 * fRec902[1]);
			fRec904[0] = (fTemp422 + (fTemp423 + (fRec904[1] + fTemp424)));
			fRec902[0] = fRec904[0];
			double fRec903 = ((fTemp424 + fTemp423) + fTemp422);
			fRec901[0] = (fRec902[0] + fRec901[1]);
			fRec899[0] = fRec901[0];
			double fRec900 = fRec903;
			fRec898[0] = (fTemp420 + (fTemp421 + (fRec900 + fRec898[1])));
			fRec896[0] = fRec898[0];
			double fRec897 = (fTemp420 + (fRec900 + fTemp421));
			fRec895[0] = (fRec896[0] + fRec895[1]);
			fRec893[0] = fRec895[0];
			double fRec894 = fRec897;
			fRec892[0] = (fTemp419 + (fRec894 + fRec892[1]));
			fRec890[0] = fRec892[0];
			double fRec891 = (fRec894 + fTemp419);
			double fTemp425 = (fConst44 * fRec905[1]);
			double fTemp426 = (fConst45 * fRec908[1]);
			double fTemp427 = (fConst47 * (((368528984100.0 * fTemp33) + ((((((3324988099000.0 * fTemp31) + (12778477980000.0 * fTemp32)) + (41801517350000.0 * fTemp34)) + (45895528860000.0 * fTemp35)) + (24564936970000.0 * fTemp36)) + (53913414540000.0 * fTemp38))) - (35462752170000.0 * fTemp37)));
			double fTemp428 = (fConst48 * fRec911[1]);
			double fTemp429 = (fConst49 * fRec914[1]);
			fRec916[0] = (fTemp427 + (fTemp428 + (fRec916[1] + fTemp429)));
			fRec914[0] = fRec916[0];
			double fRec915 = ((fTemp429 + fTemp428) + fTemp427);
			fRec913[0] = (fRec914[0] + fRec913[1]);
			fRec911[0] = fRec913[0];
			double fRec912 = fRec915;
			fRec910[0] = (fTemp425 + (fTemp426 + (fRec912 + fRec910[1])));
			fRec908[0] = fRec910[0];
			double fRec909 = (fTemp425 + (fRec912 + fTemp426));
			fRec907[0] = (fRec908[0] + fRec907[1]);
			fRec905[0] = fRec907[0];
			double fRec906 = fRec909;
			double fTemp430 = (fConst51 * fRec917[1]);
			double fTemp431 = (fConst53 * ((((4427587372000.0 * fTemp14) + (45052068110000.0 * fTemp8)) + (20895869490000.0 * fTemp13)) - ((((39640735420000.0 * fTemp9) + (45912237860000.0 * fTemp10)) + (13496891880000.0 * fTemp11)) + (38858459450000.0 * fTemp12))));
			double fTemp432 = (fConst54 * fRec920[1]);
			double fTemp433 = (fConst55 * fRec923[1]);
			fRec925[0] = (fTemp431 + (fTemp432 + (fRec925[1] + fTemp433)));
			fRec923[0] = fRec925[0];
			double fRec924 = ((fTemp433 + fTemp432) + fTemp431);
			fRec922[0] = (fRec923[0] + fRec922[1]);
			fRec920[0] = fRec922[0];
			double fRec921 = fRec924;
			fRec919[0] = (fTemp430 + (fRec921 + fRec919[1]));
			fRec917[0] = fRec919[0];
			double fRec918 = (fRec921 + fTemp430);
			double fTemp434 = (fConst57 * ((39563455270000.0 * fTemp28) - ((18172641630000.0 * fTemp26) + (6453576175000.0 * fTemp27))));
			double fTemp435 = (fConst58 * fRec926[1]);
			fRec928[0] = (fTemp434 + (fRec928[1] + fTemp435));
			fRec926[0] = fRec928[0];
			double fRec927 = (fTemp435 + fTemp434);
			double fTemp436 = (fConst60 * (((13015729730000.0 * fTemp18) + (6435738220000.0 * fTemp20)) - (((53644197300000.0 * fTemp19) + (20728673950000.0 * fTemp21)) + (18528030120000.0 * fTemp22))));
			double fTemp437 = (fConst61 * fRec929[1]);
			double fTemp438 = (fConst62 * fRec932[1]);
			fRec934[0] = (fTemp436 + (fTemp437 + (fRec934[1] + fTemp438)));
			fRec932[0] = fRec934[0];
			double fRec933 = ((fTemp438 + fTemp437) + fTemp436);
			fRec931[0] = (fRec932[0] + fRec931[1]);
			fRec929[0] = fRec931[0];
			double fRec930 = fRec933;
			fVec19[0] = ((15145906500000.0 * fTemp58) + (fRec891 + (fRec906 + (fRec918 + (fRec927 + fRec930)))));
			output19[i] = FAUSTFLOAT((0.99982065997130565 * (fRec0[0] * fVec19[iConst63])));
			double fTemp439 = (fConst60 * ((((11503817370000.0 * fTemp18) + (7040482895000.0 * fTemp20)) + (21577494660000.0 * fTemp22)) - ((16162703220000.0 * fTemp19) + (55526185030000.0 * fTemp21))));
			double fTemp440 = (fConst61 * fRec935[1]);
			double fTemp441 = (fConst62 * fRec938[1]);
			fRec940[0] = (fTemp439 + (fTemp440 + (fRec940[1] + fTemp441)));
			fRec938[0] = fRec940[0];
			double fRec939 = ((fTemp441 + fTemp440) + fTemp439);
			fRec937[0] = (fRec938[0] + fRec937[1]);
			fRec935[0] = fRec937[0];
			double fRec936 = fRec939;
			double fTemp442 = (fConst57 * ((40258644230000.0 * fTemp28) - ((5484793804000.0 * fTemp26) + (19306381700000.0 * fTemp27))));
			double fTemp443 = (fConst58 * fRec941[1]);
			fRec943[0] = (fTemp442 + (fRec943[1] + fTemp443));
			fRec941[0] = fRec943[0];
			double fRec942 = (fTemp443 + fTemp442);
			double fTemp444 = (fConst35 * fRec944[1]);
			double fTemp445 = (fConst37 * fRec947[1]);
			double fTemp446 = (fConst38 * fRec950[1]);
			double fTemp447 = (fConst40 * (((6063030725000.0 * fTemp54) + ((66512032500000.0 * fTemp48) + (1703847466000.0 * fTemp53))) - (((((16824772310000.0 * fTemp47) + (54494472770000.0 * fTemp51)) + (20571617820000.0 * fTemp49)) + (1525459007000.0 * fTemp52)) + (29323433750000.0 * fTemp50))));
			double fTemp448 = (fConst41 * fRec953[1]);
			double fTemp449 = (fConst42 * fRec956[1]);
			fRec958[0] = (fTemp447 + (fTemp448 + (fRec958[1] + fTemp449)));
			fRec956[0] = fRec958[0];
			double fRec957 = ((fTemp449 + fTemp448) + fTemp447);
			fRec955[0] = (fRec956[0] + fRec955[1]);
			fRec953[0] = fRec955[0];
			double fRec954 = fRec957;
			fRec952[0] = (fTemp445 + (fTemp446 + (fRec954 + fRec952[1])));
			fRec950[0] = fRec952[0];
			double fRec951 = (fTemp445 + (fRec954 + fTemp446));
			fRec949[0] = (fRec950[0] + fRec949[1]);
			fRec947[0] = fRec949[0];
			double fRec948 = fRec951;
			fRec946[0] = (fTemp444 + (fRec948 + fRec946[1]));
			fRec944[0] = fRec946[0];
			double fRec945 = (fRec948 + fTemp444);
			double fTemp450 = (fConst44 * fRec959[1]);
			double fTemp451 = (fConst45 * fRec962[1]);
			double fTemp452 = (fConst47 * ((((41344829210000.0 * fTemp37) + (((34462958780000.0 * fTemp34) + (19886607600000.0 * fTemp35)) + (46031216500000.0 * fTemp36))) + (1060217962000.0 * fTemp33)) - (((3918661019000.0 * fTemp31) + (49785627200000.0 * fTemp32)) + (24050322560000.0 * fTemp38))));
			double fTemp453 = (fConst48 * fRec965[1]);
			double fTemp454 = (fConst49 * fRec968[1]);
			fRec970[0] = (fTemp452 + (fTemp453 + (fRec970[1] + fTemp454)));
			fRec968[0] = fRec970[0];
			double fRec969 = ((fTemp454 + fTemp453) + fTemp452);
			fRec967[0] = (fRec968[0] + fRec967[1]);
			fRec965[0] = fRec967[0];
			double fRec966 = fRec969;
			fRec964[0] = (fTemp450 + (fTemp451 + (fRec966 + fRec964[1])));
			fRec962[0] = fRec964[0];
			double fRec963 = (fTemp450 + (fRec966 + fTemp451));
			fRec961[0] = (fRec962[0] + fRec961[1]);
			fRec959[0] = fRec961[0];
			double fRec960 = fRec963;
			double fTemp455 = (fConst51 * fRec971[1]);
			double fTemp456 = (fConst53 * (((37666500160000.0 * fTemp8) + (45285079720000.0 * fTemp12)) - (((((19172221510000.0 * fTemp14) + (9914499594000.0 * fTemp9)) + (46699661190000.0 * fTemp10)) + (41123446540000.0 * fTemp11)) + (9065964825000.0 * fTemp13))));
			double fTemp457 = (fConst54 * fRec974[1]);
			double fTemp458 = (fConst55 * fRec977[1]);
			fRec979[0] = (fTemp456 + (fTemp457 + (fRec979[1] + fTemp458)));
			fRec977[0] = fRec979[0];
			double fRec978 = ((fTemp458 + fTemp457) + fTemp456);
			fRec976[0] = (fRec977[0] + fRec976[1]);
			fRec974[0] = fRec976[0];
			double fRec975 = fRec978;
			fRec973[0] = (fTemp455 + (fRec975 + fRec973[1]));
			fRec971[0] = fRec973[0];
			double fRec972 = (fRec975 + fTemp455);
			fVec20[0] = ((14861983860000.0 * fTemp58) + (fRec936 + (fRec942 + (fRec945 + (fRec960 + fRec972)))));
			output20[i] = FAUSTFLOAT((0.99982065997130565 * (fRec0[0] * fVec20[iConst63])));
			double fTemp459 = (fConst35 * fRec980[1]);
			double fTemp460 = (fConst37 * fRec983[1]);
			double fTemp461 = (fConst38 * fRec986[1]);
			double fTemp462 = (fConst40 * (((((14583848070000.0 * fTemp47) + (63815336690000.0 * fTemp51)) + (19987907910000.0 * fTemp49)) + (11256829530000.0 * fTemp54)) - ((12286689940000.0 * fTemp53) + (((71177575260000.0 * fTemp48) + (247992959000.0 * fTemp52)) + (28258846050000.0 * fTemp50)))));
			double fTemp463 = (fConst41 * fRec989[1]);
			double fTemp464 = (fConst42 * fRec992[1]);
			fRec994[0] = (fTemp462 + (fTemp463 + (fRec994[1] + fTemp464)));
			fRec992[0] = fRec994[0];
			double fRec993 = ((fTemp464 + fTemp463) + fTemp462);
			fRec991[0] = (fRec992[0] + fRec991[1]);
			fRec989[0] = fRec991[0];
			double fRec990 = fRec993;
			fRec988[0] = (fTemp460 + (fTemp461 + (fRec990 + fRec988[1])));
			fRec986[0] = fRec988[0];
			double fRec987 = (fTemp460 + (fRec990 + fTemp461));
			fRec985[0] = (fRec986[0] + fRec985[1]);
			fRec983[0] = fRec985[0];
			double fRec984 = fRec987;
			fRec982[0] = (fTemp459 + (fRec984 + fRec982[1]));
			fRec980[0] = fRec982[0];
			double fRec981 = (fRec984 + fTemp459);
			double fTemp465 = (fConst44 * fRec995[1]);
			double fTemp466 = (fConst45 * fRec998[1]);
			double fTemp467 = (fConst47 * ((((43519286600000.0 * fTemp37) + (((6327824577000.0 * fTemp31) + (56185411770000.0 * fTemp32)) + (40019932910000.0 * fTemp36))) + (1168321797000.0 * fTemp33)) - (((35506559040000.0 * fTemp34) + (18821395300000.0 * fTemp35)) + (21546640550000.0 * fTemp38))));
			double fTemp468 = (fConst48 * fRec1001[1]);
			double fTemp469 = (fConst49 * fRec1004[1]);
			fRec1006[0] = (fTemp467 + (fTemp468 + (fRec1006[1] + fTemp469)));
			fRec1004[0] = fRec1006[0];
			double fRec1005 = ((fTemp469 + fTemp468) + fTemp467);
			fRec1003[0] = (fRec1004[0] + fRec1003[1]);
			fRec1001[0] = fRec1003[0];
			double fRec1002 = fRec1005;
			fRec1000[0] = (fTemp465 + (fTemp466 + (fRec1002 + fRec1000[1])));
			fRec998[0] = fRec1000[0];
			double fRec999 = (fTemp465 + (fRec1002 + fTemp466));
			fRec997[0] = (fRec998[0] + fRec997[1]);
			fRec995[0] = fRec997[0];
			double fRec996 = fRec999;
			double fTemp470 = (fConst51 * fRec1007[1]);
			double fTemp471 = (fConst53 * ((((20073172210000.0 * fTemp14) + (7892552042000.0 * fTemp9)) + (45420478820000.0 * fTemp12)) - ((((39078499430000.0 * fTemp8) + (38495004110000.0 * fTemp10)) + (36913751000000.0 * fTemp11)) + (6537829763000.0 * fTemp13))));
			double fTemp472 = (fConst54 * fRec1010[1]);
			double fTemp473 = (fConst55 * fRec1013[1]);
			fRec1015[0] = (fTemp471 + (fTemp472 + (fRec1015[1] + fTemp473)));
			fRec1013[0] = fRec1015[0];
			double fRec1014 = ((fTemp473 + fTemp472) + fTemp471);
			fRec1012[0] = (fRec1013[0] + fRec1012[1]);
			fRec1010[0] = fRec1012[0];
			double fRec1011 = fRec1014;
			fRec1009[0] = (fTemp470 + (fRec1011 + fRec1009[1]));
			fRec1007[0] = fRec1009[0];
			double fRec1008 = (fRec1011 + fTemp470);
			double fTemp474 = (fConst57 * (((6671670258000.0 * fTemp26) + (32846913120000.0 * fTemp28)) - (18577673370000.0 * fTemp27)));
			double fTemp475 = (fConst58 * fRec1016[1]);
			fRec1018[0] = (fTemp474 + (fRec1018[1] + fTemp475));
			fRec1016[0] = fRec1018[0];
			double fRec1017 = (fTemp475 + fTemp474);
			double fTemp476 = (fConst60 * ((((15067709590000.0 * fTemp19) + (5200405672000.0 * fTemp20)) + (19862498100000.0 * fTemp22)) - ((12648409170000.0 * fTemp18) + (50283095190000.0 * fTemp21))));
			double fTemp477 = (fConst61 * fRec1019[1]);
			double fTemp478 = (fConst62 * fRec1022[1]);
			fRec1024[0] = (fTemp476 + (fTemp477 + (fRec1024[1] + fTemp478)));
			fRec1022[0] = fRec1024[0];
			double fRec1023 = ((fTemp478 + fTemp477) + fTemp476);
			fRec1021[0] = (fRec1022[0] + fRec1021[1]);
			fRec1019[0] = fRec1021[0];
			double fRec1020 = fRec1023;
			fVec21[0] = ((16255093580000.0 * fTemp58) + (fRec981 + (fRec996 + (fRec1008 + (fRec1017 + fRec1020)))));
			output21[i] = FAUSTFLOAT((0.99982065997130565 * (fRec0[0] * fVec21[iConst63])));
			double fTemp479 = (fConst44 * fRec1025[1]);
			double fTemp480 = (fConst45 * fRec1028[1]);
			double fTemp481 = (fConst47 * (((26311034490000.0 * fTemp36) + (54622016350000.0 * fTemp38)) - ((((((6043237637000.0 * fTemp31) + (7749100993000.0 * fTemp32)) + (41788022630000.0 * fTemp34)) + (43694496020000.0 * fTemp35)) + (35548353200000.0 * fTemp37)) + (1181164103000.0 * fTemp33))));
			double fTemp482 = (fConst48 * fRec1031[1]);
			double fTemp483 = (fConst49 * fRec1034[1]);
			fRec1036[0] = (fTemp481 + (fTemp482 + (fRec1036[1] + fTemp483)));
			fRec1034[0] = fRec1036[0];
			double fRec1035 = ((fTemp483 + fTemp482) + fTemp481);
			fRec1033[0] = (fRec1033[1] + fRec1034[0]);
			fRec1031[0] = fRec1033[0];
			double fRec1032 = fRec1035;
			fRec1030[0] = ((fTemp479 + (fRec1030[1] + fTemp480)) + fRec1032);
			fRec1028[0] = fRec1030[0];
			double fRec1029 = ((fTemp480 + fTemp479) + fRec1032);
			fRec1027[0] = (fRec1027[1] + fRec1028[0]);
			fRec1025[0] = fRec1027[0];
			double fRec1026 = fRec1029;
			double fTemp484 = (fConst51 * fRec1037[1]);
			double fTemp485 = (fConst53 * (((21247253560000.0 * fTemp13) + (38469262490000.0 * fTemp9)) - ((((45362112740000.0 * fTemp10) + ((193933621200.0 * fTemp14) + (45954982520000.0 * fTemp8))) + (14750796730000.0 * fTemp11)) + (36562949330000.0 * fTemp12))));
			double fTemp486 = (fConst55 * fRec1043[1]);
			double fTemp487 = (fConst54 * fRec1040[1]);
			fRec1045[0] = (((fTemp485 + fRec1045[1]) + fTemp486) + fTemp487);
			fRec1043[0] = fRec1045[0];
			double fRec1044 = ((fTemp485 + fTemp486) + fTemp487);
			fRec1042[0] = (fRec1042[1] + fRec1043[0]);
			fRec1040[0] = fRec1042[0];
			double fRec1041 = fRec1044;
			fRec1039[0] = ((fRec1039[1] + fTemp484) + fRec1041);
			fRec1037[0] = fRec1039[0];
			double fRec1038 = (fTemp484 + fRec1041);
			double fTemp488 = (fConst60 * (((51225684940000.0 * fTemp19) + (6178801279000.0 * fTemp20)) - (((14647744590000.0 * fTemp18) + (23156942470000.0 * fTemp21)) + (15541481560000.0 * fTemp22))));
			double fTemp489 = (fConst61 * fRec1046[1]);
			double fTemp490 = (fConst62 * fRec1049[1]);
			fRec1051[0] = (fTemp488 + (fTemp489 + (fRec1051[1] + fTemp490)));
			fRec1049[0] = fRec1051[0];
			double fRec1050 = ((fTemp490 + fTemp489) + fTemp488);
			fRec1048[0] = (fRec1049[0] + fRec1048[1]);
			fRec1046[0] = fRec1048[0];
			double fRec1047 = fRec1050;
			double fTemp491 = (fConst35 * fRec1052[1]);
			double fTemp492 = (fConst37 * fRec1055[1]);
			double fTemp493 = (fConst38 * fRec1058[1]);
			double fTemp494 = (fConst40 * ((((60579957290000.0 * fTemp48) + (24082452930000.0 * fTemp49)) + (59294272560000.0 * fTemp50)) - ((5504028626000.0 * fTemp54) + ((((20214876730000.0 * fTemp47) + (14520384370000.0 * fTemp51)) + (122832818400.0 * fTemp52)) + (32886502810000.0 * fTemp53)))));
			double fTemp495 = (fConst41 * fRec1061[1]);
			double fTemp496 = (fConst42 * fRec1064[1]);
			fRec1066[0] = (fTemp494 + (fTemp495 + (fRec1066[1] + fTemp496)));
			fRec1064[0] = fRec1066[0];
			double fRec1065 = ((fTemp496 + fTemp495) + fTemp494);
			fRec1063[0] = (fRec1064[0] + fRec1063[1]);
			fRec1061[0] = fRec1063[0];
			double fRec1062 = fRec1065;
			fRec1060[0] = (fTemp492 + (fTemp493 + (fRec1062 + fRec1060[1])));
			fRec1058[0] = fRec1060[0];
			double fRec1059 = (fTemp492 + (fRec1062 + fTemp493));
			fRec1057[0] = (fRec1058[0] + fRec1057[1]);
			fRec1055[0] = fRec1057[0];
			double fRec1056 = fRec1059;
			fRec1054[0] = (fTemp491 + (fRec1056 + fRec1054[1]));
			fRec1052[0] = fRec1054[0];
			double fRec1053 = (fRec1056 + fTemp491);
			double fTemp497 = (fConst57 * (((16644042010000.0 * fTemp26) + (39544601730000.0 * fTemp28)) - (8083926765000.0 * fTemp27)));
			double fTemp498 = (fConst58 * fRec1067[1]);
			fRec1069[0] = (fTemp497 + (fRec1069[1] + fTemp498));
			fRec1067[0] = fRec1069[0];
			double fRec1068 = (fTemp498 + fTemp497);
			fVec22[0] = ((14366407760000.0 * fTemp58) + (fRec1026 + (fRec1038 + (fRec1047 + (fRec1053 + fRec1068)))));
			output22[i] = FAUSTFLOAT((0.99982065997130565 * (fRec0[0] * fVec22[iConst63])));
			double fTemp499 = (fConst35 * fRec1070[1]);
			double fTemp500 = (fConst37 * fRec1073[1]);
			double fTemp501 = (fConst38 * fRec1076[1]);
			double fTemp502 = (fConst40 * (((1106042669000.0 * fTemp52) + (15732819340000.0 * fTemp54)) - ((14339473890000.0 * fTemp53) + (((((11322310770000.0 * fTemp47) + (56336228660000.0 * fTemp48)) + (20019249900000.0 * fTemp51)) + (22937785520000.0 * fTemp49)) + (55200196960000.0 * fTemp50)))));
			double fTemp503 = (fConst41 * fRec1079[1]);
			double fTemp504 = (fConst42 * fRec1082[1]);
			fRec1084[0] = (fTemp502 + (fTemp503 + (fRec1084[1] + fTemp504)));
			fRec1082[0] = fRec1084[0];
			double fRec1083 = ((fTemp504 + fTemp503) + fTemp502);
			fRec1081[0] = (fRec1082[0] + fRec1081[1]);
			fRec1079[0] = fRec1081[0];
			double fRec1080 = fRec1083;
			fRec1078[0] = (fTemp500 + (fTemp501 + (fRec1080 + fRec1078[1])));
			fRec1076[0] = fRec1078[0];
			double fRec1077 = (fTemp500 + (fRec1080 + fTemp501));
			fRec1075[0] = (fRec1076[0] + fRec1075[1]);
			fRec1073[0] = fRec1075[0];
			double fRec1074 = fRec1077;
			fRec1072[0] = (fTemp499 + (fRec1074 + fRec1072[1]));
			fRec1070[0] = fRec1072[0];
			double fRec1071 = (fRec1074 + fTemp499);
			double fTemp505 = (fConst53 * ((((42130396270000.0 * fTemp8) + (42123685330000.0 * fTemp9)) + (11487155070000.0 * fTemp11)) - ((20595820820000.0 * fTemp13) + (((6993019793000.0 * fTemp14) + (47172945220000.0 * fTemp10)) + (45250446930000.0 * fTemp12)))));
			double fTemp506 = (fConst55 * fRec1091[1]);
			double fTemp507 = (fConst54 * fRec1088[1]);
			fRec1093[0] = (((fTemp505 + fRec1093[1]) + fTemp506) + fTemp507);
			fRec1091[0] = fRec1093[0];
			double fRec1092 = ((fTemp505 + fTemp506) + fTemp507);
			fRec1090[0] = (fRec1091[0] + fRec1090[1]);
			fRec1088[0] = fRec1090[0];
			double fRec1089 = fRec1092;
			double fTemp508 = (fConst51 * fRec1085[1]);
			fRec1087[0] = ((fRec1089 + fRec1087[1]) + fTemp508);
			fRec1085[0] = fRec1087[0];
			double fRec1086 = (fRec1089 + fTemp508);
			double fTemp509 = (fConst57 * (((18405321730000.0 * fTemp26) + (40882160840000.0 * fTemp28)) + (6683645734000.0 * fTemp27)));
			double fTemp510 = (fConst58 * fRec1094[1]);
			fRec1096[0] = (fTemp509 + (fRec1096[1] + fTemp510));
			fRec1094[0] = fRec1096[0];
			double fRec1095 = (fTemp510 + fTemp509);
			double fTemp511 = (fConst60 * (((((12702822910000.0 * fTemp18) + (56348004360000.0 * fTemp19)) + (6465415086000.0 * fTemp20)) + (18617969050000.0 * fTemp21)) - (20980443220000.0 * fTemp22)));
			double fTemp512 = (fConst61 * fRec1097[1]);
			double fTemp513 = (fConst62 * fRec1100[1]);
			fRec1102[0] = (fTemp511 + (fTemp512 + (fRec1102[1] + fTemp513)));
			fRec1100[0] = fRec1102[0];
			double fRec1101 = ((fTemp513 + fTemp512) + fTemp511);
			fRec1099[0] = (fRec1100[0] + fRec1099[1]);
			fRec1097[0] = fRec1099[0];
			double fRec1098 = fRec1101;
			double fTemp514 = (fConst47 * (((38722273690000.0 * fTemp34) + (2689505849000.0 * fTemp33)) - ((51431846910000.0 * fTemp38) + (((((1730707651000.0 * fTemp31) + (16533857350000.0 * fTemp32)) + (48405916580000.0 * fTemp35)) + (21824744090000.0 * fTemp36)) + (41982277570000.0 * fTemp37)))));
			double fTemp515 = (fConst48 * fRec1109[1]);
			double fTemp516 = (fConst49 * fRec1112[1]);
			fRec1114[0] = (fTemp514 + (fTemp515 + (fRec1114[1] + fTemp516)));
			fRec1112[0] = fRec1114[0];
			double fRec1113 = ((fTemp516 + fTemp515) + fTemp514);
			fRec1111[0] = (fRec1112[0] + fRec1111[1]);
			fRec1109[0] = fRec1111[0];
			double fRec1110 = fRec1113;
			double fTemp517 = (fConst44 * fRec1103[1]);
			double fTemp518 = (fConst45 * fRec1106[1]);
			fRec1108[0] = (fRec1110 + (fTemp517 + (fRec1108[1] + fTemp518)));
			fRec1106[0] = fRec1108[0];
			double fRec1107 = ((fTemp518 + fTemp517) + fRec1110);
			fRec1105[0] = (fRec1105[1] + fRec1106[0]);
			fRec1103[0] = fRec1105[0];
			double fRec1104 = fRec1107;
			fVec23[0] = ((fRec1071 + ((fRec1086 + (fRec1095 + fRec1098)) + fRec1104)) + (14993197720000.0 * fTemp58));
			output23[i] = FAUSTFLOAT((0.99982065997130565 * (fRec0[0] * fVec23[iConst63])));
			double fTemp519 = (fConst67 * ((((5892312260000.0 * fTemp51) + (80550745980000.0 * fTemp49)) + (10791146150000.0 * fTemp53)) - (((((772830014400.0 * fTemp47) + (969609300400.0 * fTemp48)) + (103382765800.0 * fTemp52)) + (5914025111000.0 * fTemp50)) + (734612398600.0 * fTemp54))));
			double fTemp520 = (fConst68 * fRec1124[1]);
			double fTemp521 = (fConst69 * fRec1127[1]);
			fRec1129[0] = (fTemp519 + (fTemp520 + (fRec1129[1] + fTemp521)));
			fRec1127[0] = fRec1129[0];
			double fRec1128 = ((fTemp521 + fTemp520) + fTemp519);
			fRec1126[0] = (fRec1126[1] + fRec1127[0]);
			fRec1124[0] = fRec1126[0];
			double fRec1125 = fRec1128;
			double fTemp522 = (fConst70 * fRec1121[1]);
			double fTemp523 = (fConst71 * fRec1118[1]);
			fRec1123[0] = (((fRec1125 + fRec1123[1]) + fTemp522) + fTemp523);
			fRec1121[0] = fRec1123[0];
			double fRec1122 = ((fRec1125 + fTemp522) + fTemp523);
			fRec1120[0] = (fRec1121[0] + fRec1120[1]);
			fRec1118[0] = fRec1120[0];
			double fRec1119 = fRec1122;
			double fTemp524 = (fConst72 * fRec1115[1]);
			fRec1117[0] = ((fRec1119 + fRec1117[1]) + fTemp524);
			fRec1115[0] = fRec1117[0];
			double fRec1116 = (fRec1119 + fTemp524);
			double fTemp525 = (fConst74 * fRec1130[1]);
			double fTemp526 = (fConst75 * fRec1133[1]);
			double fTemp527 = (fConst77 * ((((((797119450400.0 * fTemp31) + (1104441963000.0 * fTemp32)) + (17590370120000.0 * fTemp34)) + (70064158200000.0 * fTemp35)) + (70717574770000.0 * fTemp36)) - ((7901628548000.0 * fTemp33) + ((503038057100.0 * fTemp37) + (797069864600.0 * fTemp38)))));
			double fTemp528 = (fConst78 * fRec1136[1]);
			double fTemp529 = (fConst79 * fRec1139[1]);
			fRec1141[0] = (fTemp527 + (fTemp528 + (fRec1141[1] + fTemp529)));
			fRec1139[0] = fRec1141[0];
			double fRec1140 = ((fTemp529 + fTemp528) + fTemp527);
			fRec1138[0] = (fRec1139[0] + fRec1138[1]);
			fRec1136[0] = fRec1138[0];
			double fRec1137 = fRec1140;
			fRec1135[0] = (fTemp525 + (fTemp526 + (fRec1137 + fRec1135[1])));
			fRec1133[0] = fRec1135[0];
			double fRec1134 = (fTemp525 + (fRec1137 + fTemp526));
			fRec1132[0] = (fRec1133[0] + fRec1132[1]);
			fRec1130[0] = fRec1132[0];
			double fRec1131 = fRec1134;
			double fTemp530 = (fConst81 * fRec1142[1]);
			double fTemp531 = (fConst83 * ((((((1069678304000.0 * fTemp14) + (15999202850000.0 * fTemp8)) + (35058694610000.0 * fTemp9)) + (26649170120000.0 * fTemp10)) + (34536640650000.0 * fTemp11)) - ((349225757300.0 * fTemp12) + (711513427300.0 * fTemp13))));
			double fTemp532 = (fConst84 * fRec1145[1]);
			double fTemp533 = (fConst85 * fRec1148[1]);
			fRec1150[0] = (fTemp531 + (fTemp532 + (fRec1150[1] + fTemp533)));
			fRec1148[0] = fRec1150[0];
			double fRec1149 = ((fTemp533 + fTemp532) + fTemp531);
			fRec1147[0] = (fRec1148[0] + fRec1147[1]);
			fRec1145[0] = fRec1147[0];
			double fRec1146 = fRec1149;
			fRec1144[0] = (fTemp530 + (fRec1146 + fRec1144[1]));
			fRec1142[0] = fRec1144[0];
			double fRec1143 = (fRec1146 + fTemp530);
			double fTemp534 = (fConst87 * (((30261004160000.0 * fTemp26) + (7139763816000.0 * fTemp28)) + (30443467470000.0 * fTemp27)));
			double fTemp535 = (fConst88 * fRec1151[1]);
			fRec1153[0] = (fTemp534 + (fRec1153[1] + fTemp535));
			fRec1151[0] = fRec1153[0];
			double fRec1152 = (fTemp535 + fTemp534);
			double fTemp536 = (fConst90 * (((((31155858580000.0 * fTemp18) + (27802903320000.0 * fTemp19)) + (68899389470000.0 * fTemp20)) + (27345859600000.0 * fTemp21)) + (2019191531.0 * fTemp22)));
			double fTemp537 = (fConst91 * fRec1154[1]);
			double fTemp538 = (fConst92 * fRec1157[1]);
			fRec1159[0] = (fTemp536 + (fTemp537 + (fRec1159[1] + fTemp538)));
			fRec1157[0] = fRec1159[0];
			double fRec1158 = ((fTemp538 + fTemp537) + fTemp536);
			fRec1156[0] = (fRec1157[0] + fRec1156[1]);
			fRec1154[0] = fRec1156[0];
			double fRec1155 = fRec1158;
			fVec24[(IOTA & 511)] = ((fRec1116 + (fRec1131 + (fRec1143 + (fRec1152 + fRec1155)))) + (46144495460000.0 * fTemp58));
			output24[i] = FAUSTFLOAT((0.91194404591104739 * (fVec24[((IOTA - iConst93) & 511)] * fRec0[0])));
			double fTemp539 = (fConst72 * fRec1160[1]);
			double fTemp540 = (fConst71 * fRec1163[1]);
			double fTemp541 = (fConst70 * fRec1166[1]);
			double fTemp542 = (fConst67 * (((1050658598000.0 * fTemp54) + (((536368516700.0 * fTemp47) + (88717695680.0 * fTemp52)) + (15566716170000.0 * fTemp53))) - ((((1794914061000.0 * fTemp48) + (8293975781000.0 * fTemp51)) + (78535959580000.0 * fTemp49)) + (4305514946000.0 * fTemp50))));
			double fTemp543 = (fConst68 * fRec1169[1]);
			double fTemp544 = (fConst69 * fRec1172[1]);
			fRec1174[0] = (fTemp542 + (fTemp543 + (fRec1174[1] + fTemp544)));
			fRec1172[0] = fRec1174[0];
			double fRec1173 = ((fTemp544 + fTemp543) + fTemp542);
			fRec1171[0] = (fRec1172[0] + fRec1171[1]);
			fRec1169[0] = fRec1171[0];
			double fRec1170 = fRec1173;
			fRec1168[0] = (fTemp540 + (fTemp541 + (fRec1170 + fRec1168[1])));
			fRec1166[0] = fRec1168[0];
			double fRec1167 = (fTemp540 + (fRec1170 + fTemp541));
			fRec1165[0] = (fRec1166[0] + fRec1165[1]);
			fRec1163[0] = fRec1165[0];
			double fRec1164 = fRec1167;
			fRec1162[0] = (fTemp539 + (fRec1164 + fRec1162[1]));
			fRec1160[0] = fRec1162[0];
			double fRec1161 = (fRec1164 + fTemp539);
			double fTemp545 = (fConst87 * (((6965466628000.0 * fTemp28) + (30538424470000.0 * fTemp27)) - (30710678990000.0 * fTemp26)));
			double fTemp546 = (fConst88 * fRec1175[1]);
			fRec1177[0] = (fTemp545 + (fRec1177[1] + fTemp546));
			fRec1175[0] = fRec1177[0];
			double fRec1176 = (fTemp546 + fTemp545);
			double fTemp547 = (fConst90 * ((((68628084560000.0 * fTemp20) + (27534398200000.0 * fTemp21)) + (49089561610.0 * fTemp22)) - ((30071711110000.0 * fTemp18) + (26040646670000.0 * fTemp19))));
			double fTemp548 = (fConst91 * fRec1178[1]);
			double fTemp549 = (fConst92 * fRec1181[1]);
			fRec1183[0] = (fTemp547 + (fTemp548 + (fRec1183[1] + fTemp549)));
			fRec1181[0] = fRec1183[0];
			double fRec1182 = ((fTemp549 + fTemp548) + fTemp547);
			fRec1180[0] = (fRec1180[1] + fRec1181[0]);
			fRec1178[0] = fRec1180[0];
			double fRec1179 = fRec1182;
			double fTemp550 = (fConst81 * fRec1184[1]);
			double fTemp551 = (fConst83 * (((400800798300.0 * fTemp12) + ((26945522620000.0 * fTemp10) + (34691073820000.0 * fTemp11))) - ((((1294047586000.0 * fTemp14) + (17333468000000.0 * fTemp8)) + (33013721580000.0 * fTemp9)) + (1006696538000.0 * fTemp13))));
			double fTemp552 = (fConst84 * fRec1187[1]);
			double fTemp553 = (fConst85 * fRec1190[1]);
			fRec1192[0] = (fTemp551 + (fTemp552 + (fRec1192[1] + fTemp553)));
			fRec1190[0] = fRec1192[0];
			double fRec1191 = ((fTemp553 + fTemp552) + fTemp551);
			fRec1189[0] = (fRec1189[1] + fRec1190[0]);
			fRec1187[0] = fRec1189[0];
			double fRec1188 = fRec1191;
			fRec1186[0] = ((fRec1186[1] + fTemp550) + fRec1188);
			fRec1184[0] = fRec1186[0];
			double fRec1185 = (fTemp550 + fRec1188);
			double fTemp554 = (fConst77 * (((529445264900.0 * fTemp37) + ((1189006267000.0 * fTemp31) + (70676661720000.0 * fTemp36))) - ((10362299680000.0 * fTemp33) + ((((2686689226000.0 * fTemp32) + (19805391780000.0 * fTemp34)) + (71874239460000.0 * fTemp35)) + (49601520440.0 * fTemp38)))));
			double fTemp555 = (fConst78 * fRec1199[1]);
			double fTemp556 = (fConst79 * fRec1202[1]);
			fRec1204[0] = (fTemp554 + (fTemp555 + (fRec1204[1] + fTemp556)));
			fRec1202[0] = fRec1204[0];
			double fRec1203 = ((fTemp556 + fTemp555) + fTemp554);
			fRec1201[0] = (fRec1201[1] + fRec1202[0]);
			fRec1199[0] = fRec1201[0];
			double fRec1200 = fRec1203;
			double fTemp557 = (fConst74 * fRec1193[1]);
			double fTemp558 = (fConst75 * fRec1196[1]);
			fRec1198[0] = (fRec1200 + (fTemp557 + (fRec1198[1] + fTemp558)));
			fRec1196[0] = fRec1198[0];
			double fRec1197 = ((fTemp558 + fTemp557) + fRec1200);
			fRec1195[0] = (fRec1195[1] + fRec1196[0]);
			fRec1193[0] = fRec1195[0];
			double fRec1194 = fRec1197;
			fVec25[(IOTA & 511)] = ((46295575820000.0 * fTemp58) + (fRec1161 + (((fRec1176 + fRec1179) + fRec1185) + fRec1194)));
			output25[i] = FAUSTFLOAT((0.91194404591104739 * (fRec0[0] * fVec25[((IOTA - iConst93) & 511)])));
			double fTemp559 = (fConst79 * fRec1214[1]);
			double fTemp560 = (fConst78 * fRec1211[1]);
			double fTemp561 = (fConst77 * ((((466179981600.0 * fTemp31) + (18149416450000.0 * fTemp34)) + (2629904809000.0 * fTemp38)) - (((((2206749126000.0 * fTemp32) + (71348688380000.0 * fTemp35)) + (70919289710000.0 * fTemp36)) + (197153174800.0 * fTemp37)) + (6701102772000.0 * fTemp33))));
			fRec1216[0] = (((fRec1216[1] + fTemp559) + fTemp560) + fTemp561);
			fRec1214[0] = fRec1216[0];
			double fRec1215 = ((fTemp559 + fTemp560) + fTemp561);
			fRec1213[0] = (fRec1214[0] + fRec1213[1]);
			fRec1211[0] = fRec1213[0];
			double fRec1212 = fRec1215;
			double fTemp562 = (fConst75 * fRec1208[1]);
			double fTemp563 = (fConst74 * fRec1205[1]);
			fRec1210[0] = (((fRec1212 + fRec1210[1]) + fTemp562) + fTemp563);
			fRec1208[0] = fRec1210[0];
			double fRec1209 = ((fRec1212 + fTemp562) + fTemp563);
			fRec1207[0] = (fRec1208[0] + fRec1207[1]);
			fRec1205[0] = fRec1207[0];
			double fRec1206 = fRec1209;
			double fTemp564 = (fConst81 * fRec1217[1]);
			double fTemp565 = (fConst83 * ((((16375702560000.0 * fTemp8) + (27386321800000.0 * fTemp10)) + (1108324667000.0 * fTemp13)) - ((((986682833600.0 * fTemp14) + (33879740230000.0 * fTemp9)) + (34025117300000.0 * fTemp11)) + (149865783200.0 * fTemp12))));
			double fTemp566 = (fConst84 * fRec1220[1]);
			double fTemp567 = (fConst85 * fRec1223[1]);
			fRec1225[0] = (fTemp565 + (fTemp566 + (fRec1225[1] + fTemp567)));
			fRec1223[0] = fRec1225[0];
			double fRec1224 = ((fTemp567 + fTemp566) + fTemp565);
			fRec1222[0] = (fRec1223[0] + fRec1222[1]);
			fRec1220[0] = fRec1222[0];
			double fRec1221 = fRec1224;
			fRec1219[0] = (fTemp564 + (fRec1221 + fRec1219[1]));
			fRec1217[0] = fRec1219[0];
			double fRec1218 = (fRec1221 + fTemp564);
			double fTemp568 = (fConst87 * ((6663711933000.0 * fTemp28) - ((30415435770000.0 * fTemp26) + (30347266890000.0 * fTemp27))));
			double fTemp569 = (fConst88 * fRec1226[1]);
			fRec1228[0] = (fTemp568 + (fRec1228[1] + fTemp569));
			fRec1226[0] = fRec1228[0];
			double fRec1227 = (fTemp569 + fTemp568);
			double fTemp570 = (fConst90 * (((31034647250000.0 * fTemp18) + (68610744630000.0 * fTemp20)) - (((26659854140000.0 * fTemp19) + (26839974540000.0 * fTemp21)) + (19062383000.0 * fTemp22))));
			double fTemp571 = (fConst91 * fRec1229[1]);
			double fTemp572 = (fConst92 * fRec1232[1]);
			fRec1234[0] = (fTemp570 + (fTemp571 + (fRec1234[1] + fTemp572)));
			fRec1232[0] = fRec1234[0];
			double fRec1233 = ((fTemp572 + fTemp571) + fTemp570);
			fRec1231[0] = (fRec1232[0] + fRec1231[1]);
			fRec1229[0] = fRec1231[0];
			double fRec1230 = fRec1233;
			double fTemp573 = (fConst72 * fRec1235[1]);
			double fTemp574 = (fConst71 * fRec1238[1]);
			double fTemp575 = (fConst70 * fRec1241[1]);
			double fTemp576 = (fConst67 * (((259041250200.0 * fTemp54) + ((8506723648000.0 * fTemp53) + ((80327546190000.0 * fTemp49) + (8378864406000.0 * fTemp50)))) - ((((355260298400.0 * fTemp47) + (1019223863000.0 * fTemp48)) + (7880811657000.0 * fTemp51)) + (32663594110.0 * fTemp52))));
			double fTemp577 = (fConst68 * fRec1244[1]);
			double fTemp578 = (fConst69 * fRec1247[1]);
			fRec1249[0] = (fTemp576 + (fTemp577 + (fRec1249[1] + fTemp578)));
			fRec1247[0] = fRec1249[0];
			double fRec1248 = ((fTemp578 + fTemp577) + fTemp576);
			fRec1246[0] = (fRec1246[1] + fRec1247[0]);
			fRec1244[0] = fRec1246[0];
			double fRec1245 = fRec1248;
			fRec1243[0] = ((fTemp574 + (fRec1243[1] + fTemp575)) + fRec1245);
			fRec1241[0] = fRec1243[0];
			double fRec1242 = ((fTemp575 + fTemp574) + fRec1245);
			fRec1240[0] = (fRec1240[1] + fRec1241[0]);
			fRec1238[0] = fRec1240[0];
			double fRec1239 = fRec1242;
			fRec1237[0] = ((fRec1237[1] + fTemp573) + fRec1239);
			fRec1235[0] = fRec1237[0];
			double fRec1236 = (fTemp573 + fRec1239);
			fVec26[(IOTA & 511)] = (((fRec1206 + (fRec1218 + (fRec1227 + fRec1230))) + fRec1236) + (46145348260000.0 * fTemp58));
			output26[i] = FAUSTFLOAT((0.91194404591104739 * (fRec0[0] * fVec26[((IOTA - iConst93) & 511)])));
			double fTemp579 = (fConst87 * (((30224415310000.0 * fTemp26) + (7132357979000.0 * fTemp28)) - (30441589720000.0 * fTemp27)));
			double fTemp580 = (fConst88 * fRec1250[1]);
			fRec1252[0] = (fTemp579 + (fRec1252[1] + fTemp580));
			fRec1250[0] = fRec1252[0];
			double fRec1251 = (fTemp580 + fTemp579);
			double fTemp581 = (fConst90 * (((27986908500000.0 * fTemp19) + (68850376510000.0 * fTemp20)) - (((29843240790000.0 * fTemp18) + (26182961730000.0 * fTemp21)) + (364392013700.0 * fTemp22))));
			double fTemp582 = (fConst91 * fRec1253[1]);
			double fTemp583 = (fConst92 * fRec1256[1]);
			fRec1258[0] = (fTemp581 + (fTemp582 + (fRec1258[1] + fTemp583)));
			fRec1256[0] = fRec1258[0];
			double fRec1257 = ((fTemp583 + fTemp582) + fTemp581);
			fRec1255[0] = (fRec1255[1] + fRec1256[0]);
			fRec1253[0] = fRec1255[0];
			double fRec1254 = fRec1257;
			double fTemp584 = (fConst81 * fRec1259[1]);
			double fTemp585 = (fConst83 * (((((515884351300.0 * fTemp14) + (35319415420000.0 * fTemp9)) + (26752515770000.0 * fTemp10)) + (895930636400.0 * fTemp13)) - (((17088310300000.0 * fTemp8) + (33289144660000.0 * fTemp11)) + (1155218850000.0 * fTemp12))));
			double fTemp586 = (fConst84 * fRec1262[1]);
			double fTemp587 = (fConst85 * fRec1265[1]);
			fRec1267[0] = (fTemp585 + (fTemp586 + (fRec1267[1] + fTemp587)));
			fRec1265[0] = fRec1267[0];
			double fRec1266 = ((fTemp587 + fTemp586) + fTemp585);
			fRec1264[0] = (fRec1264[1] + fRec1265[0]);
			fRec1262[0] = fRec1264[0];
			double fRec1263 = fRec1266;
			fRec1261[0] = ((fRec1261[1] + fTemp584) + fRec1263);
			fRec1259[0] = fRec1261[0];
			double fRec1260 = (fTemp584 + fRec1263);
			double fTemp588 = (fConst74 * fRec1268[1]);
			double fTemp589 = (fConst75 * fRec1271[1]);
			double fTemp590 = (fConst77 * ((((786811521000.0 * fTemp31) + (70041651710000.0 * fTemp35)) + (2381097841000.0 * fTemp38)) - (((((552083169200.0 * fTemp32) + (19701474020000.0 * fTemp34)) + (71496246900000.0 * fTemp36)) + (1269118901000.0 * fTemp37)) + (10658825440000.0 * fTemp33))));
			double fTemp591 = (fConst78 * fRec1274[1]);
			double fTemp592 = (fConst79 * fRec1277[1]);
			fRec1279[0] = (fTemp590 + (fTemp591 + (fRec1279[1] + fTemp592)));
			fRec1277[0] = fRec1279[0];
			double fRec1278 = ((fTemp592 + fTemp591) + fTemp590);
			fRec1276[0] = (fRec1276[1] + fRec1277[0]);
			fRec1274[0] = fRec1276[0];
			double fRec1275 = fRec1278;
			fRec1273[0] = ((fTemp588 + (fRec1273[1] + fTemp589)) + fRec1275);
			fRec1271[0] = fRec1273[0];
			double fRec1272 = ((fTemp589 + fTemp588) + fRec1275);
			fRec1270[0] = (fRec1270[1] + fRec1271[0]);
			fRec1268[0] = fRec1270[0];
			double fRec1269 = fRec1272;
			double fTemp593 = (fConst72 * fRec1280[1]);
			double fTemp594 = (fConst71 * fRec1283[1]);
			double fTemp595 = (fConst70 * fRec1286[1]);
			double fTemp596 = (fConst67 * (((18327189330000.0 * fTemp53) + (((1696624601000.0 * fTemp47) + (3929788673000.0 * fTemp51)) + (8293912356000.0 * fTemp50))) - ((((1034169901000.0 * fTemp48) + (78596087150000.0 * fTemp49)) + (95121763710.0 * fTemp52)) + (769998033900.0 * fTemp54))));
			double fTemp597 = (fConst68 * fRec1289[1]);
			double fTemp598 = (fConst69 * fRec1292[1]);
			fRec1294[0] = (fTemp596 + (fTemp597 + (fRec1294[1] + fTemp598)));
			fRec1292[0] = fRec1294[0];
			double fRec1293 = ((fTemp598 + fTemp597) + fTemp596);
			fRec1291[0] = (fRec1291[1] + fRec1292[0]);
			fRec1289[0] = fRec1291[0];
			double fRec1290 = fRec1293;
			fRec1288[0] = ((fTemp594 + (fRec1288[1] + fTemp595)) + fRec1290);
			fRec1286[0] = fRec1288[0];
			double fRec1287 = ((fTemp595 + fTemp594) + fRec1290);
			fRec1285[0] = (fRec1285[1] + fRec1286[0]);
			fRec1283[0] = fRec1285[0];
			double fRec1284 = fRec1287;
			fRec1282[0] = ((fRec1282[1] + fTemp593) + fRec1284);
			fRec1280[0] = fRec1282[0];
			double fRec1281 = (fTemp593 + fRec1284);
			fVec27[(IOTA & 511)] = ((46110625810000.0 * fTemp58) + ((((fRec1251 + fRec1254) + fRec1260) + fRec1269) + fRec1281));
			output27[i] = FAUSTFLOAT((0.91194404591104739 * (fRec0[0] * fVec27[((IOTA - iConst93) & 511)])));
			double fTemp599 = (fConst95 * (((694228646200.0 * fTemp26) + (123819501200000.0 * fTemp28)) + (144911167100.0 * fTemp27)));
			double fTemp600 = (fConst96 * fRec1295[1]);
			fRec1297[0] = (fTemp599 + (fRec1297[1] + fTemp600));
			fRec1295[0] = fRec1297[0];
			double fRec1296 = (fTemp600 + fTemp599);
			double fTemp601 = (fConst98 * ((61692596280.0 * fTemp22) - ((((1373544044000.0 * fTemp18) + (1688208646000.0 * fTemp19)) + (41566429620000.0 * fTemp20)) + (821778202900.0 * fTemp21))));
			double fTemp602 = (fConst99 * fRec1298[1]);
			double fTemp603 = (fConst100 * fRec1301[1]);
			fRec1303[0] = (fTemp601 + (fTemp602 + (fRec1303[1] + fTemp603)));
			fRec1301[0] = fRec1303[0];
			double fRec1302 = ((fTemp603 + fTemp602) + fTemp601);
			fRec1300[0] = (fRec1300[1] + fRec1301[0]);
			fRec1298[0] = fRec1300[0];
			double fRec1299 = fRec1302;
			double fTemp604 = (fConst102 * fRec1304[1]);
			double fTemp605 = (fConst104 * (((44315821780.0 * fTemp13) + (((2008971818000.0 * fTemp8) + (111338433100000.0 * fTemp10)) + (562384918000.0 * fTemp12))) - (((45714586700.0 * fTemp14) + (2090289828000.0 * fTemp9)) + (1028145855000.0 * fTemp11))));
			double fTemp606 = (fConst105 * fRec1307[1]);
			double fTemp607 = (fConst106 * fRec1310[1]);
			fRec1312[0] = (fTemp605 + (fTemp606 + (fRec1312[1] + fTemp607)));
			fRec1310[0] = fRec1312[0];
			double fRec1311 = ((fTemp607 + fTemp606) + fTemp605);
			fRec1309[0] = (fRec1309[1] + fRec1310[0]);
			fRec1307[0] = fRec1309[0];
			double fRec1308 = fRec1311;
			fRec1306[0] = ((fRec1306[1] + fTemp604) + fRec1308);
			fRec1304[0] = fRec1306[0];
			double fRec1305 = (fTemp604 + fRec1308);
			double fTemp608 = (fConst108 * fRec1313[1]);
			double fTemp609 = (fConst109 * fRec1316[1]);
			double fTemp610 = (fConst111 * ((((751176302300.0 * fTemp37) + ((((1773316443000.0 * fTemp32) + (3119760053000.0 * fTemp34)) + (1977096755000.0 * fTemp35)) + (464196028400.0 * fTemp36))) + (26012400050000.0 * fTemp33)) - ((2369530913000.0 * fTemp31) + (2249768843000.0 * fTemp38))));
			double fTemp611 = (fConst112 * fRec1319[1]);
			double fTemp612 = (fConst113 * fRec1322[1]);
			fRec1324[0] = (fTemp610 + (fTemp611 + (fRec1324[1] + fTemp612)));
			fRec1322[0] = fRec1324[0];
			double fRec1323 = ((fTemp612 + fTemp611) + fTemp610);
			fRec1321[0] = (fRec1321[1] + fRec1322[0]);
			fRec1319[0] = fRec1321[0];
			double fRec1320 = fRec1323;
			fRec1318[0] = ((fTemp608 + (fRec1318[1] + fTemp609)) + fRec1320);
			fRec1316[0] = fRec1318[0];
			double fRec1317 = ((fTemp609 + fTemp608) + fRec1320);
			fRec1315[0] = (fRec1315[1] + fRec1316[0]);
			fRec1313[0] = fRec1315[0];
			double fRec1314 = fRec1317;
			double fTemp613 = (fConst115 * fRec1325[1]);
			double fTemp614 = (fConst117 * fRec1328[1]);
			double fTemp615 = (fConst118 * fRec1331[1]);
			double fTemp616 = (fConst120 * ((((3399886057000.0 * fTemp48) + (3089959137000.0 * fTemp51)) + (129662719100.0 * fTemp52)) - ((112812235900.0 * fTemp54) + ((36932404320000.0 * fTemp53) + (((222416792800.0 * fTemp47) + (2949933872000.0 * fTemp49)) + (3752916009000.0 * fTemp50))))));
			double fTemp617 = (fConst121 * fRec1334[1]);
			double fTemp618 = (fConst122 * fRec1337[1]);
			fRec1339[0] = (fTemp616 + (fTemp617 + (fRec1339[1] + fTemp618)));
			fRec1337[0] = fRec1339[0];
			double fRec1338 = ((fTemp618 + fTemp617) + fTemp616);
			fRec1336[0] = (fRec1336[1] + fRec1337[0]);
			fRec1334[0] = fRec1336[0];
			double fRec1335 = fRec1338;
			fRec1333[0] = ((fTemp614 + (fRec1333[1] + fTemp615)) + fRec1335);
			fRec1331[0] = fRec1333[0];
			double fRec1332 = ((fTemp615 + fTemp614) + fRec1335);
			fRec1330[0] = (fRec1330[1] + fRec1331[0]);
			fRec1328[0] = fRec1330[0];
			double fRec1329 = fRec1332;
			fRec1327[0] = ((fRec1327[1] + fTemp613) + fRec1329);
			fRec1325[0] = fRec1327[0];
			double fRec1326 = (fTemp613 + fRec1329);
			output28[i] = FAUSTFLOAT((fRec0[0] * (((((fRec1296 + fRec1299) + fRec1305) + fRec1314) + fRec1326) - (5349803625000.0 * fTemp58))));
			fRec0[1] = fRec0[0];
			fRec11[1] = fRec11[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec12[1] = fRec12[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec9[1] = fRec9[0];
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec1[1] = fRec1[0];
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
			fRec24[1] = fRec24[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec19[1] = fRec19[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec32[1] = fRec32[0];
			fRec30[1] = fRec30[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
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
			fRec47[1] = fRec47[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			fRec42[1] = fRec42[0];
			fRec41[1] = fRec41[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec36[1] = fRec36[0];
			fRec71[2] = fRec71[1];
			fRec71[1] = fRec71[0];
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
			fRec70[1] = fRec70[0];
			fRec68[1] = fRec68[0];
			fRec67[1] = fRec67[0];
			fRec65[1] = fRec65[0];
			fRec64[1] = fRec64[0];
			fRec62[1] = fRec62[0];
			fRec61[1] = fRec61[0];
			fRec59[1] = fRec59[0];
			fRec58[1] = fRec58[0];
			fRec56[1] = fRec56[0];
			fRec79[2] = fRec79[1];
			fRec79[1] = fRec79[0];
			IOTA = (IOTA + 1);
			fRec94[1] = fRec94[0];
			fRec92[1] = fRec92[0];
			fRec91[1] = fRec91[0];
			fRec89[1] = fRec89[0];
			fRec88[1] = fRec88[0];
			fRec86[1] = fRec86[0];
			fRec85[1] = fRec85[0];
			fRec83[1] = fRec83[0];
			fRec82[1] = fRec82[0];
			fRec80[1] = fRec80[0];
			fRec106[1] = fRec106[0];
			fRec104[1] = fRec104[0];
			fRec103[1] = fRec103[0];
			fRec101[1] = fRec101[0];
			fRec100[1] = fRec100[0];
			fRec98[1] = fRec98[0];
			fRec97[1] = fRec97[0];
			fRec95[1] = fRec95[0];
			fRec115[1] = fRec115[0];
			fRec113[1] = fRec113[0];
			fRec112[1] = fRec112[0];
			fRec110[1] = fRec110[0];
			fRec109[1] = fRec109[0];
			fRec107[1] = fRec107[0];
			fRec118[1] = fRec118[0];
			fRec116[1] = fRec116[0];
			fRec124[1] = fRec124[0];
			fRec122[1] = fRec122[0];
			fRec121[1] = fRec121[0];
			fRec119[1] = fRec119[0];
			fRec139[1] = fRec139[0];
			fRec137[1] = fRec137[0];
			fRec136[1] = fRec136[0];
			fRec134[1] = fRec134[0];
			fRec133[1] = fRec133[0];
			fRec131[1] = fRec131[0];
			fRec130[1] = fRec130[0];
			fRec128[1] = fRec128[0];
			fRec127[1] = fRec127[0];
			fRec125[1] = fRec125[0];
			fRec151[1] = fRec151[0];
			fRec149[1] = fRec149[0];
			fRec148[1] = fRec148[0];
			fRec146[1] = fRec146[0];
			fRec145[1] = fRec145[0];
			fRec143[1] = fRec143[0];
			fRec142[1] = fRec142[0];
			fRec140[1] = fRec140[0];
			fRec160[1] = fRec160[0];
			fRec158[1] = fRec158[0];
			fRec157[1] = fRec157[0];
			fRec155[1] = fRec155[0];
			fRec154[1] = fRec154[0];
			fRec152[1] = fRec152[0];
			fRec163[1] = fRec163[0];
			fRec161[1] = fRec161[0];
			fRec169[1] = fRec169[0];
			fRec167[1] = fRec167[0];
			fRec166[1] = fRec166[0];
			fRec164[1] = fRec164[0];
			fRec184[1] = fRec184[0];
			fRec182[1] = fRec182[0];
			fRec181[1] = fRec181[0];
			fRec179[1] = fRec179[0];
			fRec178[1] = fRec178[0];
			fRec176[1] = fRec176[0];
			fRec175[1] = fRec175[0];
			fRec173[1] = fRec173[0];
			fRec172[1] = fRec172[0];
			fRec170[1] = fRec170[0];
			fRec196[1] = fRec196[0];
			fRec194[1] = fRec194[0];
			fRec193[1] = fRec193[0];
			fRec191[1] = fRec191[0];
			fRec190[1] = fRec190[0];
			fRec188[1] = fRec188[0];
			fRec187[1] = fRec187[0];
			fRec185[1] = fRec185[0];
			fRec205[1] = fRec205[0];
			fRec203[1] = fRec203[0];
			fRec202[1] = fRec202[0];
			fRec200[1] = fRec200[0];
			fRec199[1] = fRec199[0];
			fRec197[1] = fRec197[0];
			fRec208[1] = fRec208[0];
			fRec206[1] = fRec206[0];
			fRec214[1] = fRec214[0];
			fRec212[1] = fRec212[0];
			fRec211[1] = fRec211[0];
			fRec209[1] = fRec209[0];
			fRec229[1] = fRec229[0];
			fRec227[1] = fRec227[0];
			fRec226[1] = fRec226[0];
			fRec224[1] = fRec224[0];
			fRec223[1] = fRec223[0];
			fRec221[1] = fRec221[0];
			fRec220[1] = fRec220[0];
			fRec218[1] = fRec218[0];
			fRec217[1] = fRec217[0];
			fRec215[1] = fRec215[0];
			fRec241[1] = fRec241[0];
			fRec239[1] = fRec239[0];
			fRec238[1] = fRec238[0];
			fRec236[1] = fRec236[0];
			fRec235[1] = fRec235[0];
			fRec233[1] = fRec233[0];
			fRec232[1] = fRec232[0];
			fRec230[1] = fRec230[0];
			fRec250[1] = fRec250[0];
			fRec248[1] = fRec248[0];
			fRec247[1] = fRec247[0];
			fRec245[1] = fRec245[0];
			fRec244[1] = fRec244[0];
			fRec242[1] = fRec242[0];
			fRec253[1] = fRec253[0];
			fRec251[1] = fRec251[0];
			fRec259[1] = fRec259[0];
			fRec257[1] = fRec257[0];
			fRec256[1] = fRec256[0];
			fRec254[1] = fRec254[0];
			fRec274[1] = fRec274[0];
			fRec272[1] = fRec272[0];
			fRec271[1] = fRec271[0];
			fRec269[1] = fRec269[0];
			fRec268[1] = fRec268[0];
			fRec266[1] = fRec266[0];
			fRec265[1] = fRec265[0];
			fRec263[1] = fRec263[0];
			fRec262[1] = fRec262[0];
			fRec260[1] = fRec260[0];
			fRec286[1] = fRec286[0];
			fRec284[1] = fRec284[0];
			fRec283[1] = fRec283[0];
			fRec281[1] = fRec281[0];
			fRec280[1] = fRec280[0];
			fRec278[1] = fRec278[0];
			fRec277[1] = fRec277[0];
			fRec275[1] = fRec275[0];
			fRec295[1] = fRec295[0];
			fRec293[1] = fRec293[0];
			fRec292[1] = fRec292[0];
			fRec290[1] = fRec290[0];
			fRec289[1] = fRec289[0];
			fRec287[1] = fRec287[0];
			fRec298[1] = fRec298[0];
			fRec296[1] = fRec296[0];
			fRec304[1] = fRec304[0];
			fRec302[1] = fRec302[0];
			fRec301[1] = fRec301[0];
			fRec299[1] = fRec299[0];
			fRec319[1] = fRec319[0];
			fRec317[1] = fRec317[0];
			fRec316[1] = fRec316[0];
			fRec314[1] = fRec314[0];
			fRec313[1] = fRec313[0];
			fRec311[1] = fRec311[0];
			fRec310[1] = fRec310[0];
			fRec308[1] = fRec308[0];
			fRec307[1] = fRec307[0];
			fRec305[1] = fRec305[0];
			fRec331[1] = fRec331[0];
			fRec329[1] = fRec329[0];
			fRec328[1] = fRec328[0];
			fRec326[1] = fRec326[0];
			fRec325[1] = fRec325[0];
			fRec323[1] = fRec323[0];
			fRec322[1] = fRec322[0];
			fRec320[1] = fRec320[0];
			fRec340[1] = fRec340[0];
			fRec338[1] = fRec338[0];
			fRec337[1] = fRec337[0];
			fRec335[1] = fRec335[0];
			fRec334[1] = fRec334[0];
			fRec332[1] = fRec332[0];
			fRec343[1] = fRec343[0];
			fRec341[1] = fRec341[0];
			fRec349[1] = fRec349[0];
			fRec347[1] = fRec347[0];
			fRec346[1] = fRec346[0];
			fRec344[1] = fRec344[0];
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
			fRec376[1] = fRec376[0];
			fRec374[1] = fRec374[0];
			fRec373[1] = fRec373[0];
			fRec371[1] = fRec371[0];
			fRec370[1] = fRec370[0];
			fRec368[1] = fRec368[0];
			fRec367[1] = fRec367[0];
			fRec365[1] = fRec365[0];
			fRec385[1] = fRec385[0];
			fRec383[1] = fRec383[0];
			fRec382[1] = fRec382[0];
			fRec380[1] = fRec380[0];
			fRec379[1] = fRec379[0];
			fRec377[1] = fRec377[0];
			fRec388[1] = fRec388[0];
			fRec386[1] = fRec386[0];
			fRec394[1] = fRec394[0];
			fRec392[1] = fRec392[0];
			fRec391[1] = fRec391[0];
			fRec389[1] = fRec389[0];
			fRec409[1] = fRec409[0];
			fRec407[1] = fRec407[0];
			fRec406[1] = fRec406[0];
			fRec404[1] = fRec404[0];
			fRec403[1] = fRec403[0];
			fRec401[1] = fRec401[0];
			fRec400[1] = fRec400[0];
			fRec398[1] = fRec398[0];
			fRec397[1] = fRec397[0];
			fRec395[1] = fRec395[0];
			fRec421[1] = fRec421[0];
			fRec419[1] = fRec419[0];
			fRec418[1] = fRec418[0];
			fRec416[1] = fRec416[0];
			fRec415[1] = fRec415[0];
			fRec413[1] = fRec413[0];
			fRec412[1] = fRec412[0];
			fRec410[1] = fRec410[0];
			fRec430[1] = fRec430[0];
			fRec428[1] = fRec428[0];
			fRec427[1] = fRec427[0];
			fRec425[1] = fRec425[0];
			fRec424[1] = fRec424[0];
			fRec422[1] = fRec422[0];
			fRec433[1] = fRec433[0];
			fRec431[1] = fRec431[0];
			fRec439[1] = fRec439[0];
			fRec437[1] = fRec437[0];
			fRec436[1] = fRec436[0];
			fRec434[1] = fRec434[0];
			fRec451[1] = fRec451[0];
			fRec449[1] = fRec449[0];
			fRec448[1] = fRec448[0];
			fRec446[1] = fRec446[0];
			fRec445[1] = fRec445[0];
			fRec443[1] = fRec443[0];
			fRec442[1] = fRec442[0];
			fRec440[1] = fRec440[0];
			fRec460[1] = fRec460[0];
			fRec458[1] = fRec458[0];
			fRec457[1] = fRec457[0];
			fRec455[1] = fRec455[0];
			fRec454[1] = fRec454[0];
			fRec452[1] = fRec452[0];
			fRec466[1] = fRec466[0];
			fRec464[1] = fRec464[0];
			fRec463[1] = fRec463[0];
			fRec461[1] = fRec461[0];
			fRec481[1] = fRec481[0];
			fRec479[1] = fRec479[0];
			fRec478[1] = fRec478[0];
			fRec476[1] = fRec476[0];
			fRec475[1] = fRec475[0];
			fRec473[1] = fRec473[0];
			fRec472[1] = fRec472[0];
			fRec470[1] = fRec470[0];
			fRec469[1] = fRec469[0];
			fRec467[1] = fRec467[0];
			fRec484[1] = fRec484[0];
			fRec482[1] = fRec482[0];
			fRec499[1] = fRec499[0];
			fRec497[1] = fRec497[0];
			fRec496[1] = fRec496[0];
			fRec494[1] = fRec494[0];
			fRec493[1] = fRec493[0];
			fRec491[1] = fRec491[0];
			fRec490[1] = fRec490[0];
			fRec488[1] = fRec488[0];
			fRec487[1] = fRec487[0];
			fRec485[1] = fRec485[0];
			fRec511[1] = fRec511[0];
			fRec509[1] = fRec509[0];
			fRec508[1] = fRec508[0];
			fRec506[1] = fRec506[0];
			fRec505[1] = fRec505[0];
			fRec503[1] = fRec503[0];
			fRec502[1] = fRec502[0];
			fRec500[1] = fRec500[0];
			fRec520[1] = fRec520[0];
			fRec518[1] = fRec518[0];
			fRec517[1] = fRec517[0];
			fRec515[1] = fRec515[0];
			fRec514[1] = fRec514[0];
			fRec512[1] = fRec512[0];
			fRec523[1] = fRec523[0];
			fRec521[1] = fRec521[0];
			fRec529[1] = fRec529[0];
			fRec527[1] = fRec527[0];
			fRec526[1] = fRec526[0];
			fRec524[1] = fRec524[0];
			fRec544[1] = fRec544[0];
			fRec542[1] = fRec542[0];
			fRec541[1] = fRec541[0];
			fRec539[1] = fRec539[0];
			fRec538[1] = fRec538[0];
			fRec536[1] = fRec536[0];
			fRec535[1] = fRec535[0];
			fRec533[1] = fRec533[0];
			fRec532[1] = fRec532[0];
			fRec530[1] = fRec530[0];
			fRec553[1] = fRec553[0];
			fRec551[1] = fRec551[0];
			fRec550[1] = fRec550[0];
			fRec548[1] = fRec548[0];
			fRec547[1] = fRec547[0];
			fRec545[1] = fRec545[0];
			fRec559[1] = fRec559[0];
			fRec557[1] = fRec557[0];
			fRec556[1] = fRec556[0];
			fRec554[1] = fRec554[0];
			fRec571[1] = fRec571[0];
			fRec569[1] = fRec569[0];
			fRec568[1] = fRec568[0];
			fRec566[1] = fRec566[0];
			fRec565[1] = fRec565[0];
			fRec563[1] = fRec563[0];
			fRec562[1] = fRec562[0];
			fRec560[1] = fRec560[0];
			fRec574[1] = fRec574[0];
			fRec572[1] = fRec572[0];
			fRec577[1] = fRec577[0];
			fRec575[1] = fRec575[0];
			fRec592[1] = fRec592[0];
			fRec590[1] = fRec590[0];
			fRec589[1] = fRec589[0];
			fRec587[1] = fRec587[0];
			fRec586[1] = fRec586[0];
			fRec584[1] = fRec584[0];
			fRec583[1] = fRec583[0];
			fRec581[1] = fRec581[0];
			fRec580[1] = fRec580[0];
			fRec578[1] = fRec578[0];
			fRec604[1] = fRec604[0];
			fRec602[1] = fRec602[0];
			fRec601[1] = fRec601[0];
			fRec599[1] = fRec599[0];
			fRec598[1] = fRec598[0];
			fRec596[1] = fRec596[0];
			fRec595[1] = fRec595[0];
			fRec593[1] = fRec593[0];
			fRec610[1] = fRec610[0];
			fRec608[1] = fRec608[0];
			fRec607[1] = fRec607[0];
			fRec605[1] = fRec605[0];
			fRec619[1] = fRec619[0];
			fRec617[1] = fRec617[0];
			fRec616[1] = fRec616[0];
			fRec614[1] = fRec614[0];
			fRec613[1] = fRec613[0];
			fRec611[1] = fRec611[0];
			fRec634[1] = fRec634[0];
			fRec632[1] = fRec632[0];
			fRec631[1] = fRec631[0];
			fRec629[1] = fRec629[0];
			fRec628[1] = fRec628[0];
			fRec626[1] = fRec626[0];
			fRec625[1] = fRec625[0];
			fRec623[1] = fRec623[0];
			fRec622[1] = fRec622[0];
			fRec620[1] = fRec620[0];
			fRec646[1] = fRec646[0];
			fRec644[1] = fRec644[0];
			fRec643[1] = fRec643[0];
			fRec641[1] = fRec641[0];
			fRec640[1] = fRec640[0];
			fRec638[1] = fRec638[0];
			fRec637[1] = fRec637[0];
			fRec635[1] = fRec635[0];
			fRec655[1] = fRec655[0];
			fRec653[1] = fRec653[0];
			fRec652[1] = fRec652[0];
			fRec650[1] = fRec650[0];
			fRec649[1] = fRec649[0];
			fRec647[1] = fRec647[0];
			fRec658[1] = fRec658[0];
			fRec656[1] = fRec656[0];
			fRec664[1] = fRec664[0];
			fRec662[1] = fRec662[0];
			fRec661[1] = fRec661[0];
			fRec659[1] = fRec659[0];
			fRec676[1] = fRec676[0];
			fRec674[1] = fRec674[0];
			fRec673[1] = fRec673[0];
			fRec671[1] = fRec671[0];
			fRec670[1] = fRec670[0];
			fRec668[1] = fRec668[0];
			fRec667[1] = fRec667[0];
			fRec665[1] = fRec665[0];
			fRec685[1] = fRec685[0];
			fRec683[1] = fRec683[0];
			fRec682[1] = fRec682[0];
			fRec680[1] = fRec680[0];
			fRec679[1] = fRec679[0];
			fRec677[1] = fRec677[0];
			fRec691[1] = fRec691[0];
			fRec689[1] = fRec689[0];
			fRec688[1] = fRec688[0];
			fRec686[1] = fRec686[0];
			fRec706[1] = fRec706[0];
			fRec704[1] = fRec704[0];
			fRec703[1] = fRec703[0];
			fRec701[1] = fRec701[0];
			fRec700[1] = fRec700[0];
			fRec698[1] = fRec698[0];
			fRec697[1] = fRec697[0];
			fRec695[1] = fRec695[0];
			fRec694[1] = fRec694[0];
			fRec692[1] = fRec692[0];
			fRec709[1] = fRec709[0];
			fRec707[1] = fRec707[0];
			fRec724[1] = fRec724[0];
			fRec722[1] = fRec722[0];
			fRec721[1] = fRec721[0];
			fRec719[1] = fRec719[0];
			fRec718[1] = fRec718[0];
			fRec716[1] = fRec716[0];
			fRec715[1] = fRec715[0];
			fRec713[1] = fRec713[0];
			fRec712[1] = fRec712[0];
			fRec710[1] = fRec710[0];
			fRec736[1] = fRec736[0];
			fRec734[1] = fRec734[0];
			fRec733[1] = fRec733[0];
			fRec731[1] = fRec731[0];
			fRec730[1] = fRec730[0];
			fRec728[1] = fRec728[0];
			fRec727[1] = fRec727[0];
			fRec725[1] = fRec725[0];
			fRec745[1] = fRec745[0];
			fRec743[1] = fRec743[0];
			fRec742[1] = fRec742[0];
			fRec740[1] = fRec740[0];
			fRec739[1] = fRec739[0];
			fRec737[1] = fRec737[0];
			fRec748[1] = fRec748[0];
			fRec746[1] = fRec746[0];
			fRec754[1] = fRec754[0];
			fRec752[1] = fRec752[0];
			fRec751[1] = fRec751[0];
			fRec749[1] = fRec749[0];
			fRec769[1] = fRec769[0];
			fRec767[1] = fRec767[0];
			fRec766[1] = fRec766[0];
			fRec764[1] = fRec764[0];
			fRec763[1] = fRec763[0];
			fRec761[1] = fRec761[0];
			fRec760[1] = fRec760[0];
			fRec758[1] = fRec758[0];
			fRec757[1] = fRec757[0];
			fRec755[1] = fRec755[0];
			fRec781[1] = fRec781[0];
			fRec779[1] = fRec779[0];
			fRec778[1] = fRec778[0];
			fRec776[1] = fRec776[0];
			fRec775[1] = fRec775[0];
			fRec773[1] = fRec773[0];
			fRec772[1] = fRec772[0];
			fRec770[1] = fRec770[0];
			fRec790[1] = fRec790[0];
			fRec788[1] = fRec788[0];
			fRec787[1] = fRec787[0];
			fRec785[1] = fRec785[0];
			fRec784[1] = fRec784[0];
			fRec782[1] = fRec782[0];
			fRec793[1] = fRec793[0];
			fRec791[1] = fRec791[0];
			fRec799[1] = fRec799[0];
			fRec797[1] = fRec797[0];
			fRec796[1] = fRec796[0];
			fRec794[1] = fRec794[0];
			fVec16[1] = fVec16[0];
			fRec814[1] = fRec814[0];
			fRec812[1] = fRec812[0];
			fRec811[1] = fRec811[0];
			fRec809[1] = fRec809[0];
			fRec808[1] = fRec808[0];
			fRec806[1] = fRec806[0];
			fRec805[1] = fRec805[0];
			fRec803[1] = fRec803[0];
			fRec802[1] = fRec802[0];
			fRec800[1] = fRec800[0];
			fRec826[1] = fRec826[0];
			fRec824[1] = fRec824[0];
			fRec823[1] = fRec823[0];
			fRec821[1] = fRec821[0];
			fRec820[1] = fRec820[0];
			fRec818[1] = fRec818[0];
			fRec817[1] = fRec817[0];
			fRec815[1] = fRec815[0];
			fRec835[1] = fRec835[0];
			fRec833[1] = fRec833[0];
			fRec832[1] = fRec832[0];
			fRec830[1] = fRec830[0];
			fRec829[1] = fRec829[0];
			fRec827[1] = fRec827[0];
			fRec838[1] = fRec838[0];
			fRec836[1] = fRec836[0];
			fRec844[1] = fRec844[0];
			fRec842[1] = fRec842[0];
			fRec841[1] = fRec841[0];
			fRec839[1] = fRec839[0];
			fVec17[1] = fVec17[0];
			fRec859[1] = fRec859[0];
			fRec857[1] = fRec857[0];
			fRec856[1] = fRec856[0];
			fRec854[1] = fRec854[0];
			fRec853[1] = fRec853[0];
			fRec851[1] = fRec851[0];
			fRec850[1] = fRec850[0];
			fRec848[1] = fRec848[0];
			fRec847[1] = fRec847[0];
			fRec845[1] = fRec845[0];
			fRec871[1] = fRec871[0];
			fRec869[1] = fRec869[0];
			fRec868[1] = fRec868[0];
			fRec866[1] = fRec866[0];
			fRec865[1] = fRec865[0];
			fRec863[1] = fRec863[0];
			fRec862[1] = fRec862[0];
			fRec860[1] = fRec860[0];
			fRec880[1] = fRec880[0];
			fRec878[1] = fRec878[0];
			fRec877[1] = fRec877[0];
			fRec875[1] = fRec875[0];
			fRec874[1] = fRec874[0];
			fRec872[1] = fRec872[0];
			fRec883[1] = fRec883[0];
			fRec881[1] = fRec881[0];
			fRec889[1] = fRec889[0];
			fRec887[1] = fRec887[0];
			fRec886[1] = fRec886[0];
			fRec884[1] = fRec884[0];
			fVec18[1] = fVec18[0];
			fRec904[1] = fRec904[0];
			fRec902[1] = fRec902[0];
			fRec901[1] = fRec901[0];
			fRec899[1] = fRec899[0];
			fRec898[1] = fRec898[0];
			fRec896[1] = fRec896[0];
			fRec895[1] = fRec895[0];
			fRec893[1] = fRec893[0];
			fRec892[1] = fRec892[0];
			fRec890[1] = fRec890[0];
			fRec916[1] = fRec916[0];
			fRec914[1] = fRec914[0];
			fRec913[1] = fRec913[0];
			fRec911[1] = fRec911[0];
			fRec910[1] = fRec910[0];
			fRec908[1] = fRec908[0];
			fRec907[1] = fRec907[0];
			fRec905[1] = fRec905[0];
			fRec925[1] = fRec925[0];
			fRec923[1] = fRec923[0];
			fRec922[1] = fRec922[0];
			fRec920[1] = fRec920[0];
			fRec919[1] = fRec919[0];
			fRec917[1] = fRec917[0];
			fRec928[1] = fRec928[0];
			fRec926[1] = fRec926[0];
			fRec934[1] = fRec934[0];
			fRec932[1] = fRec932[0];
			fRec931[1] = fRec931[0];
			fRec929[1] = fRec929[0];
			fVec19[1] = fVec19[0];
			fRec940[1] = fRec940[0];
			fRec938[1] = fRec938[0];
			fRec937[1] = fRec937[0];
			fRec935[1] = fRec935[0];
			fRec943[1] = fRec943[0];
			fRec941[1] = fRec941[0];
			fRec958[1] = fRec958[0];
			fRec956[1] = fRec956[0];
			fRec955[1] = fRec955[0];
			fRec953[1] = fRec953[0];
			fRec952[1] = fRec952[0];
			fRec950[1] = fRec950[0];
			fRec949[1] = fRec949[0];
			fRec947[1] = fRec947[0];
			fRec946[1] = fRec946[0];
			fRec944[1] = fRec944[0];
			fRec970[1] = fRec970[0];
			fRec968[1] = fRec968[0];
			fRec967[1] = fRec967[0];
			fRec965[1] = fRec965[0];
			fRec964[1] = fRec964[0];
			fRec962[1] = fRec962[0];
			fRec961[1] = fRec961[0];
			fRec959[1] = fRec959[0];
			fRec979[1] = fRec979[0];
			fRec977[1] = fRec977[0];
			fRec976[1] = fRec976[0];
			fRec974[1] = fRec974[0];
			fRec973[1] = fRec973[0];
			fRec971[1] = fRec971[0];
			fVec20[1] = fVec20[0];
			fRec994[1] = fRec994[0];
			fRec992[1] = fRec992[0];
			fRec991[1] = fRec991[0];
			fRec989[1] = fRec989[0];
			fRec988[1] = fRec988[0];
			fRec986[1] = fRec986[0];
			fRec985[1] = fRec985[0];
			fRec983[1] = fRec983[0];
			fRec982[1] = fRec982[0];
			fRec980[1] = fRec980[0];
			fRec1006[1] = fRec1006[0];
			fRec1004[1] = fRec1004[0];
			fRec1003[1] = fRec1003[0];
			fRec1001[1] = fRec1001[0];
			fRec1000[1] = fRec1000[0];
			fRec998[1] = fRec998[0];
			fRec997[1] = fRec997[0];
			fRec995[1] = fRec995[0];
			fRec1015[1] = fRec1015[0];
			fRec1013[1] = fRec1013[0];
			fRec1012[1] = fRec1012[0];
			fRec1010[1] = fRec1010[0];
			fRec1009[1] = fRec1009[0];
			fRec1007[1] = fRec1007[0];
			fRec1018[1] = fRec1018[0];
			fRec1016[1] = fRec1016[0];
			fRec1024[1] = fRec1024[0];
			fRec1022[1] = fRec1022[0];
			fRec1021[1] = fRec1021[0];
			fRec1019[1] = fRec1019[0];
			fVec21[1] = fVec21[0];
			fRec1036[1] = fRec1036[0];
			fRec1034[1] = fRec1034[0];
			fRec1033[1] = fRec1033[0];
			fRec1031[1] = fRec1031[0];
			fRec1030[1] = fRec1030[0];
			fRec1028[1] = fRec1028[0];
			fRec1027[1] = fRec1027[0];
			fRec1025[1] = fRec1025[0];
			fRec1045[1] = fRec1045[0];
			fRec1043[1] = fRec1043[0];
			fRec1042[1] = fRec1042[0];
			fRec1040[1] = fRec1040[0];
			fRec1039[1] = fRec1039[0];
			fRec1037[1] = fRec1037[0];
			fRec1051[1] = fRec1051[0];
			fRec1049[1] = fRec1049[0];
			fRec1048[1] = fRec1048[0];
			fRec1046[1] = fRec1046[0];
			fRec1066[1] = fRec1066[0];
			fRec1064[1] = fRec1064[0];
			fRec1063[1] = fRec1063[0];
			fRec1061[1] = fRec1061[0];
			fRec1060[1] = fRec1060[0];
			fRec1058[1] = fRec1058[0];
			fRec1057[1] = fRec1057[0];
			fRec1055[1] = fRec1055[0];
			fRec1054[1] = fRec1054[0];
			fRec1052[1] = fRec1052[0];
			fRec1069[1] = fRec1069[0];
			fRec1067[1] = fRec1067[0];
			fVec22[1] = fVec22[0];
			fRec1084[1] = fRec1084[0];
			fRec1082[1] = fRec1082[0];
			fRec1081[1] = fRec1081[0];
			fRec1079[1] = fRec1079[0];
			fRec1078[1] = fRec1078[0];
			fRec1076[1] = fRec1076[0];
			fRec1075[1] = fRec1075[0];
			fRec1073[1] = fRec1073[0];
			fRec1072[1] = fRec1072[0];
			fRec1070[1] = fRec1070[0];
			fRec1093[1] = fRec1093[0];
			fRec1091[1] = fRec1091[0];
			fRec1090[1] = fRec1090[0];
			fRec1088[1] = fRec1088[0];
			fRec1087[1] = fRec1087[0];
			fRec1085[1] = fRec1085[0];
			fRec1096[1] = fRec1096[0];
			fRec1094[1] = fRec1094[0];
			fRec1102[1] = fRec1102[0];
			fRec1100[1] = fRec1100[0];
			fRec1099[1] = fRec1099[0];
			fRec1097[1] = fRec1097[0];
			fRec1114[1] = fRec1114[0];
			fRec1112[1] = fRec1112[0];
			fRec1111[1] = fRec1111[0];
			fRec1109[1] = fRec1109[0];
			fRec1108[1] = fRec1108[0];
			fRec1106[1] = fRec1106[0];
			fRec1105[1] = fRec1105[0];
			fRec1103[1] = fRec1103[0];
			fVec23[1] = fVec23[0];
			fRec1129[1] = fRec1129[0];
			fRec1127[1] = fRec1127[0];
			fRec1126[1] = fRec1126[0];
			fRec1124[1] = fRec1124[0];
			fRec1123[1] = fRec1123[0];
			fRec1121[1] = fRec1121[0];
			fRec1120[1] = fRec1120[0];
			fRec1118[1] = fRec1118[0];
			fRec1117[1] = fRec1117[0];
			fRec1115[1] = fRec1115[0];
			fRec1141[1] = fRec1141[0];
			fRec1139[1] = fRec1139[0];
			fRec1138[1] = fRec1138[0];
			fRec1136[1] = fRec1136[0];
			fRec1135[1] = fRec1135[0];
			fRec1133[1] = fRec1133[0];
			fRec1132[1] = fRec1132[0];
			fRec1130[1] = fRec1130[0];
			fRec1150[1] = fRec1150[0];
			fRec1148[1] = fRec1148[0];
			fRec1147[1] = fRec1147[0];
			fRec1145[1] = fRec1145[0];
			fRec1144[1] = fRec1144[0];
			fRec1142[1] = fRec1142[0];
			fRec1153[1] = fRec1153[0];
			fRec1151[1] = fRec1151[0];
			fRec1159[1] = fRec1159[0];
			fRec1157[1] = fRec1157[0];
			fRec1156[1] = fRec1156[0];
			fRec1154[1] = fRec1154[0];
			fRec1174[1] = fRec1174[0];
			fRec1172[1] = fRec1172[0];
			fRec1171[1] = fRec1171[0];
			fRec1169[1] = fRec1169[0];
			fRec1168[1] = fRec1168[0];
			fRec1166[1] = fRec1166[0];
			fRec1165[1] = fRec1165[0];
			fRec1163[1] = fRec1163[0];
			fRec1162[1] = fRec1162[0];
			fRec1160[1] = fRec1160[0];
			fRec1177[1] = fRec1177[0];
			fRec1175[1] = fRec1175[0];
			fRec1183[1] = fRec1183[0];
			fRec1181[1] = fRec1181[0];
			fRec1180[1] = fRec1180[0];
			fRec1178[1] = fRec1178[0];
			fRec1192[1] = fRec1192[0];
			fRec1190[1] = fRec1190[0];
			fRec1189[1] = fRec1189[0];
			fRec1187[1] = fRec1187[0];
			fRec1186[1] = fRec1186[0];
			fRec1184[1] = fRec1184[0];
			fRec1204[1] = fRec1204[0];
			fRec1202[1] = fRec1202[0];
			fRec1201[1] = fRec1201[0];
			fRec1199[1] = fRec1199[0];
			fRec1198[1] = fRec1198[0];
			fRec1196[1] = fRec1196[0];
			fRec1195[1] = fRec1195[0];
			fRec1193[1] = fRec1193[0];
			fRec1216[1] = fRec1216[0];
			fRec1214[1] = fRec1214[0];
			fRec1213[1] = fRec1213[0];
			fRec1211[1] = fRec1211[0];
			fRec1210[1] = fRec1210[0];
			fRec1208[1] = fRec1208[0];
			fRec1207[1] = fRec1207[0];
			fRec1205[1] = fRec1205[0];
			fRec1225[1] = fRec1225[0];
			fRec1223[1] = fRec1223[0];
			fRec1222[1] = fRec1222[0];
			fRec1220[1] = fRec1220[0];
			fRec1219[1] = fRec1219[0];
			fRec1217[1] = fRec1217[0];
			fRec1228[1] = fRec1228[0];
			fRec1226[1] = fRec1226[0];
			fRec1234[1] = fRec1234[0];
			fRec1232[1] = fRec1232[0];
			fRec1231[1] = fRec1231[0];
			fRec1229[1] = fRec1229[0];
			fRec1249[1] = fRec1249[0];
			fRec1247[1] = fRec1247[0];
			fRec1246[1] = fRec1246[0];
			fRec1244[1] = fRec1244[0];
			fRec1243[1] = fRec1243[0];
			fRec1241[1] = fRec1241[0];
			fRec1240[1] = fRec1240[0];
			fRec1238[1] = fRec1238[0];
			fRec1237[1] = fRec1237[0];
			fRec1235[1] = fRec1235[0];
			fRec1252[1] = fRec1252[0];
			fRec1250[1] = fRec1250[0];
			fRec1258[1] = fRec1258[0];
			fRec1256[1] = fRec1256[0];
			fRec1255[1] = fRec1255[0];
			fRec1253[1] = fRec1253[0];
			fRec1267[1] = fRec1267[0];
			fRec1265[1] = fRec1265[0];
			fRec1264[1] = fRec1264[0];
			fRec1262[1] = fRec1262[0];
			fRec1261[1] = fRec1261[0];
			fRec1259[1] = fRec1259[0];
			fRec1279[1] = fRec1279[0];
			fRec1277[1] = fRec1277[0];
			fRec1276[1] = fRec1276[0];
			fRec1274[1] = fRec1274[0];
			fRec1273[1] = fRec1273[0];
			fRec1271[1] = fRec1271[0];
			fRec1270[1] = fRec1270[0];
			fRec1268[1] = fRec1268[0];
			fRec1294[1] = fRec1294[0];
			fRec1292[1] = fRec1292[0];
			fRec1291[1] = fRec1291[0];
			fRec1289[1] = fRec1289[0];
			fRec1288[1] = fRec1288[0];
			fRec1286[1] = fRec1286[0];
			fRec1285[1] = fRec1285[0];
			fRec1283[1] = fRec1283[0];
			fRec1282[1] = fRec1282[0];
			fRec1280[1] = fRec1280[0];
			fRec1297[1] = fRec1297[0];
			fRec1295[1] = fRec1295[0];
			fRec1303[1] = fRec1303[0];
			fRec1301[1] = fRec1301[0];
			fRec1300[1] = fRec1300[0];
			fRec1298[1] = fRec1298[0];
			fRec1312[1] = fRec1312[0];
			fRec1310[1] = fRec1310[0];
			fRec1309[1] = fRec1309[0];
			fRec1307[1] = fRec1307[0];
			fRec1306[1] = fRec1306[0];
			fRec1304[1] = fRec1304[0];
			fRec1324[1] = fRec1324[0];
			fRec1322[1] = fRec1322[0];
			fRec1321[1] = fRec1321[0];
			fRec1319[1] = fRec1319[0];
			fRec1318[1] = fRec1318[0];
			fRec1316[1] = fRec1316[0];
			fRec1315[1] = fRec1315[0];
			fRec1313[1] = fRec1313[0];
			fRec1339[1] = fRec1339[0];
			fRec1337[1] = fRec1337[0];
			fRec1336[1] = fRec1336[0];
			fRec1334[1] = fRec1334[0];
			fRec1333[1] = fRec1333[0];
			fRec1331[1] = fRec1331[0];
			fRec1330[1] = fRec1330[0];
			fRec1328[1] = fRec1328[0];
			fRec1327[1] = fRec1327[0];
			fRec1325[1] = fRec1325[0];
			
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
