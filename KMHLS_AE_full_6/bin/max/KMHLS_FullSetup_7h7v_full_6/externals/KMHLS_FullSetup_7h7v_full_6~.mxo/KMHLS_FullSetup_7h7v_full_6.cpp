/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMHLS_FullSetup_7h7v_full_6"
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
	double fRec28[3];
	double fRec29[3];
	double fRec30[3];
	double fRec31[3];
	double fRec32[3];
	double fRec33[3];
	double fRec34[3];
	double fRec35[3];
	double fRec36[3];
	double fRec37[3];
	double fRec38[3];
	double fRec39[3];
	double fRec40[3];
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
	double fConst14;
	double fConst15;
	double fConst16;
	double fConst17;
	double fConst18;
	double fConst19;
	double fConst20;
	double fRec56[3];
	double fRec57[3];
	double fRec58[3];
	double fRec59[3];
	double fRec60[3];
	double fRec61[3];
	double fRec62[3];
	double fRec63[3];
	double fRec64[3];
	double fRec65[3];
	double fRec66[3];
	double fConst21;
	double fConst22;
	double fRec55[2];
	double fRec53[2];
	double fRec52[2];
	double fRec50[2];
	double fRec49[2];
	double fRec47[2];
	double fRec46[2];
	double fRec44[2];
	double fRec43[2];
	double fRec41[2];
	double fConst23;
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fRec79[3];
	double fRec80[3];
	double fRec81[3];
	double fRec82[3];
	double fRec83[3];
	double fRec84[3];
	double fRec85[3];
	double fRec86[3];
	double fRec87[3];
	double fConst28;
	double fConst29;
	double fRec78[2];
	double fRec76[2];
	double fRec75[2];
	double fRec73[2];
	double fRec72[2];
	double fRec70[2];
	double fRec69[2];
	double fRec67[2];
	double fConst30;
	double fConst31;
	double fConst32;
	double fConst33;
	double fRec97[3];
	double fRec98[3];
	double fRec99[3];
	double fRec100[3];
	double fRec101[3];
	double fRec102[3];
	double fRec103[3];
	double fConst34;
	double fConst35;
	double fRec96[2];
	double fRec94[2];
	double fRec93[2];
	double fRec91[2];
	double fRec90[2];
	double fRec88[2];
	double fConst36;
	double fConst37;
	double fRec107[3];
	double fRec108[3];
	double fRec109[3];
	double fConst38;
	double fRec106[2];
	double fRec104[2];
	double fConst39;
	double fConst40;
	double fRec116[3];
	double fRec117[3];
	double fRec118[3];
	double fRec119[3];
	double fRec120[3];
	double fConst41;
	double fConst42;
	double fRec115[2];
	double fRec113[2];
	double fRec112[2];
	double fRec110[2];
	double fRec121[3];
	double fRec122[3];
	double fRec123[3];
	double fRec124[3];
	double fRec125[3];
	double fRec126[3];
	double fRec127[3];
	double fRec128[3];
	double fRec129[3];
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
	double fRec132[2];
	double fRec130[2];
	double fConst54;
	double fConst55;
	double fConst56;
	double fConst57;
	double fConst58;
	double fConst59;
	double fConst60;
	double fConst61;
	double fConst62;
	double fRec162[2];
	double fRec160[2];
	double fRec159[2];
	double fRec157[2];
	double fRec156[2];
	double fRec154[2];
	double fRec153[2];
	double fRec151[2];
	double fRec150[2];
	double fRec148[2];
	double fConst63;
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fConst68;
	double fConst69;
	double fRec174[2];
	double fRec172[2];
	double fRec171[2];
	double fRec169[2];
	double fRec168[2];
	double fRec166[2];
	double fRec165[2];
	double fRec163[2];
	double fConst70;
	double fConst71;
	double fConst72;
	double fConst73;
	double fConst74;
	double fConst75;
	double fRec183[2];
	double fRec181[2];
	double fRec180[2];
	double fRec178[2];
	double fRec177[2];
	double fRec175[2];
	double fConst76;
	double fConst77;
	double fConst78;
	double fRec186[2];
	double fRec184[2];
	double fConst79;
	double fConst80;
	double fConst81;
	double fConst82;
	double fRec192[2];
	double fRec190[2];
	double fRec189[2];
	double fRec187[2];
	double fVec1[128];
	int iConst83;
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
	double fRec195[2];
	double fRec193[2];
	double fRec225[2];
	double fRec223[2];
	double fRec222[2];
	double fRec220[2];
	double fRec219[2];
	double fRec217[2];
	double fRec216[2];
	double fRec214[2];
	double fRec213[2];
	double fRec211[2];
	double fRec234[2];
	double fRec232[2];
	double fRec231[2];
	double fRec229[2];
	double fRec228[2];
	double fRec226[2];
	double fRec237[2];
	double fRec235[2];
	double fRec243[2];
	double fRec241[2];
	double fRec240[2];
	double fRec238[2];
	double fRec255[2];
	double fRec253[2];
	double fRec252[2];
	double fRec250[2];
	double fRec249[2];
	double fRec247[2];
	double fRec246[2];
	double fRec244[2];
	double fVec2[128];
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
	double fRec273[2];
	double fRec271[2];
	double fRec270[2];
	double fRec268[2];
	double fRec267[2];
	double fRec265[2];
	double fRec264[2];
	double fRec262[2];
	double fRec261[2];
	double fRec259[2];
	double fRec258[2];
	double fRec256[2];
	double fConst94;
	double fConst95;
	double fConst96;
	double fConst97;
	double fConst98;
	double fConst99;
	double fConst100;
	double fConst101;
	double fConst102;
	double fRec288[2];
	double fRec286[2];
	double fRec285[2];
	double fRec283[2];
	double fRec282[2];
	double fRec280[2];
	double fRec279[2];
	double fRec277[2];
	double fRec276[2];
	double fRec274[2];
	double fConst103;
	double fConst104;
	double fConst105;
	double fConst106;
	double fConst107;
	double fConst108;
	double fConst109;
	double fRec300[2];
	double fRec298[2];
	double fRec297[2];
	double fRec295[2];
	double fRec294[2];
	double fRec292[2];
	double fRec291[2];
	double fRec289[2];
	double fConst110;
	double fConst111;
	double fConst112;
	double fConst113;
	double fConst114;
	double fConst115;
	double fRec309[2];
	double fRec307[2];
	double fRec306[2];
	double fRec304[2];
	double fRec303[2];
	double fRec301[2];
	double fConst116;
	double fConst117;
	double fConst118;
	double fRec312[2];
	double fRec310[2];
	double fConst119;
	double fConst120;
	double fConst121;
	double fConst122;
	double fRec318[2];
	double fRec316[2];
	double fRec315[2];
	double fRec313[2];
	double fVec3[128];
	int iConst123;
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
	double fRec351[2];
	double fRec349[2];
	double fRec348[2];
	double fRec346[2];
	double fRec345[2];
	double fRec343[2];
	double fRec342[2];
	double fRec340[2];
	double fRec339[2];
	double fRec337[2];
	double fRec363[2];
	double fRec361[2];
	double fRec360[2];
	double fRec358[2];
	double fRec357[2];
	double fRec355[2];
	double fRec354[2];
	double fRec352[2];
	double fRec372[2];
	double fRec370[2];
	double fRec369[2];
	double fRec367[2];
	double fRec366[2];
	double fRec364[2];
	double fRec375[2];
	double fRec373[2];
	double fRec381[2];
	double fRec379[2];
	double fRec378[2];
	double fRec376[2];
	double fVec4[128];
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
	double fRec384[2];
	double fRec382[2];
	double fRec414[2];
	double fRec412[2];
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
	double fRec435[2];
	double fRec433[2];
	double fRec432[2];
	double fRec430[2];
	double fRec429[2];
	double fRec427[2];
	double fRec438[2];
	double fRec436[2];
	double fRec444[2];
	double fRec442[2];
	double fRec441[2];
	double fRec439[2];
	double fVec5[128];
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
	double fRec447[2];
	double fRec445[2];
	double fRec477[2];
	double fRec475[2];
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
	double fRec498[2];
	double fRec496[2];
	double fRec495[2];
	double fRec493[2];
	double fRec492[2];
	double fRec490[2];
	double fRec501[2];
	double fRec499[2];
	double fRec507[2];
	double fRec505[2];
	double fRec504[2];
	double fRec502[2];
	double fVec6[128];
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
	double fRec552[2];
	double fRec550[2];
	double fRec549[2];
	double fRec547[2];
	double fRec546[2];
	double fRec544[2];
	double fRec543[2];
	double fRec541[2];
	double fRec561[2];
	double fRec559[2];
	double fRec558[2];
	double fRec556[2];
	double fRec555[2];
	double fRec553[2];
	double fRec564[2];
	double fRec562[2];
	double fRec570[2];
	double fRec568[2];
	double fRec567[2];
	double fRec565[2];
	double fVec7[128];
	double fRec588[2];
	double fRec586[2];
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
	double fRec615[2];
	double fRec613[2];
	double fRec612[2];
	double fRec610[2];
	double fRec609[2];
	double fRec607[2];
	double fRec606[2];
	double fRec604[2];
	double fRec624[2];
	double fRec622[2];
	double fRec621[2];
	double fRec619[2];
	double fRec618[2];
	double fRec616[2];
	double fRec627[2];
	double fRec625[2];
	double fRec633[2];
	double fRec631[2];
	double fRec630[2];
	double fRec628[2];
	double fVec8[128];
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
	double fRec690[2];
	double fRec688[2];
	double fRec696[2];
	double fRec694[2];
	double fRec693[2];
	double fRec691[2];
	double fVec9[128];
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
	double fRec753[2];
	double fRec751[2];
	double fRec759[2];
	double fRec757[2];
	double fRec756[2];
	double fRec754[2];
	double fVec10[128];
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
	double fRec804[2];
	double fRec802[2];
	double fRec801[2];
	double fRec799[2];
	double fRec798[2];
	double fRec796[2];
	double fRec795[2];
	double fRec793[2];
	double fRec813[2];
	double fRec811[2];
	double fRec810[2];
	double fRec808[2];
	double fRec807[2];
	double fRec805[2];
	double fRec816[2];
	double fRec814[2];
	double fRec822[2];
	double fRec820[2];
	double fRec819[2];
	double fRec817[2];
	double fVec11[128];
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
	double fVec12[128];
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
	double fVec13[128];
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
	double fVec14[128];
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
	double fConst134;
	double fConst135;
	double fConst136;
	double fConst137;
	double fConst138;
	double fConst139;
	double fConst140;
	double fConst141;
	double fConst142;
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
	double fConst143;
	double fConst144;
	double fConst145;
	double fConst146;
	double fConst147;
	double fConst148;
	double fConst149;
	double fRec1119[2];
	double fRec1117[2];
	double fRec1116[2];
	double fRec1114[2];
	double fRec1113[2];
	double fRec1111[2];
	double fRec1110[2];
	double fRec1108[2];
	double fConst150;
	double fConst151;
	double fConst152;
	double fConst153;
	double fConst154;
	double fConst155;
	double fRec1128[2];
	double fRec1126[2];
	double fRec1125[2];
	double fRec1123[2];
	double fRec1122[2];
	double fRec1120[2];
	double fConst156;
	double fConst157;
	double fConst158;
	double fRec1131[2];
	double fRec1129[2];
	double fConst159;
	double fConst160;
	double fConst161;
	double fConst162;
	double fRec1137[2];
	double fRec1135[2];
	double fRec1134[2];
	double fRec1132[2];
	double fVec16[128];
	int iConst163;
	double fRec1140[2];
	double fRec1138[2];
	double fRec1158[2];
	double fRec1156[2];
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
	double fRec1173[2];
	double fRec1171[2];
	double fRec1170[2];
	double fRec1168[2];
	double fRec1167[2];
	double fRec1165[2];
	double fRec1164[2];
	double fRec1162[2];
	double fRec1161[2];
	double fRec1159[2];
	double fRec1185[2];
	double fRec1183[2];
	double fRec1182[2];
	double fRec1180[2];
	double fRec1179[2];
	double fRec1177[2];
	double fRec1176[2];
	double fRec1174[2];
	double fRec1191[2];
	double fRec1189[2];
	double fRec1188[2];
	double fRec1186[2];
	double fRec1200[2];
	double fRec1198[2];
	double fRec1197[2];
	double fRec1195[2];
	double fRec1194[2];
	double fRec1192[2];
	double fVec17[128];
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
	double fVec18[128];
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
	double fRec1266[2];
	double fRec1264[2];
	double fRec1296[2];
	double fRec1294[2];
	double fRec1293[2];
	double fRec1291[2];
	double fRec1290[2];
	double fRec1288[2];
	double fRec1287[2];
	double fRec1285[2];
	double fRec1284[2];
	double fRec1282[2];
	double fRec1308[2];
	double fRec1306[2];
	double fRec1305[2];
	double fRec1303[2];
	double fRec1302[2];
	double fRec1300[2];
	double fRec1299[2];
	double fRec1297[2];
	double fRec1317[2];
	double fRec1315[2];
	double fRec1314[2];
	double fRec1312[2];
	double fRec1311[2];
	double fRec1309[2];
	double fRec1320[2];
	double fRec1318[2];
	double fRec1326[2];
	double fRec1324[2];
	double fRec1323[2];
	double fRec1321[2];
	double fVec19[128];
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
	double fVec20[128];
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
	double fVec21[128];
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
	double fVec22[128];
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
	double fConst174;
	double fConst175;
	double fConst176;
	double fConst177;
	double fConst178;
	double fConst179;
	double fConst180;
	double fConst181;
	double fConst182;
	double fRec1611[2];
	double fRec1609[2];
	double fRec1608[2];
	double fRec1606[2];
	double fRec1605[2];
	double fRec1603[2];
	double fRec1602[2];
	double fRec1600[2];
	double fRec1599[2];
	double fRec1597[2];
	double fConst183;
	double fConst184;
	double fConst185;
	double fConst186;
	double fConst187;
	double fConst188;
	double fConst189;
	double fRec1623[2];
	double fRec1621[2];
	double fRec1620[2];
	double fRec1618[2];
	double fRec1617[2];
	double fRec1615[2];
	double fRec1614[2];
	double fRec1612[2];
	double fConst190;
	double fConst191;
	double fConst192;
	double fConst193;
	double fConst194;
	double fConst195;
	double fRec1632[2];
	double fRec1630[2];
	double fRec1629[2];
	double fRec1627[2];
	double fRec1626[2];
	double fRec1624[2];
	double fConst196;
	double fConst197;
	double fConst198;
	double fRec1635[2];
	double fRec1633[2];
	double fConst199;
	double fConst200;
	double fConst201;
	double fConst202;
	double fRec1641[2];
	double fRec1639[2];
	double fRec1638[2];
	double fRec1636[2];
	double fVec24[12];
	int iConst203;
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
	double fVec25[12];
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
	double fRec1707[2];
	double fRec1705[2];
	double fRec1737[2];
	double fRec1735[2];
	double fRec1734[2];
	double fRec1732[2];
	double fRec1731[2];
	double fRec1729[2];
	double fRec1728[2];
	double fRec1726[2];
	double fRec1725[2];
	double fRec1723[2];
	double fRec1749[2];
	double fRec1747[2];
	double fRec1746[2];
	double fRec1744[2];
	double fRec1743[2];
	double fRec1741[2];
	double fRec1740[2];
	double fRec1738[2];
	double fRec1758[2];
	double fRec1756[2];
	double fRec1755[2];
	double fRec1753[2];
	double fRec1752[2];
	double fRec1750[2];
	double fRec1761[2];
	double fRec1759[2];
	double fRec1767[2];
	double fRec1765[2];
	double fRec1764[2];
	double fRec1762[2];
	double fVec26[12];
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
	double fRec1821[2];
	double fRec1819[2];
	double fRec1818[2];
	double fRec1816[2];
	double fRec1815[2];
	double fRec1813[2];
	double fRec1824[2];
	double fRec1822[2];
	double fRec1830[2];
	double fRec1828[2];
	double fRec1827[2];
	double fRec1825[2];
	double fVec27[12];
	double fConst204;
	double fConst205;
	double fConst206;
	double fConst207;
	double fConst208;
	double fConst209;
	double fConst210;
	double fConst211;
	double fConst212;
	double fConst213;
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
	double fConst214;
	double fConst215;
	double fConst216;
	double fConst217;
	double fConst218;
	double fConst219;
	double fConst220;
	double fConst221;
	double fConst222;
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
	double fConst223;
	double fConst224;
	double fConst225;
	double fConst226;
	double fConst227;
	double fConst228;
	double fConst229;
	double fRec1875[2];
	double fRec1873[2];
	double fRec1872[2];
	double fRec1870[2];
	double fRec1869[2];
	double fRec1867[2];
	double fRec1866[2];
	double fRec1864[2];
	double fConst230;
	double fConst231;
	double fConst232;
	double fConst233;
	double fConst234;
	double fConst235;
	double fRec1884[2];
	double fRec1882[2];
	double fRec1881[2];
	double fRec1879[2];
	double fRec1878[2];
	double fRec1876[2];
	double fConst236;
	double fConst237;
	double fConst238;
	double fRec1887[2];
	double fRec1885[2];
	double fConst239;
	double fConst240;
	double fConst241;
	double fConst242;
	double fRec1893[2];
	double fRec1891[2];
	double fRec1890[2];
	double fRec1888[2];
	double fConst243;
	double fConst244;
	double fConst245;
	double fConst246;
	double fConst247;
	double fConst248;
	double fConst249;
	double fConst250;
	double fConst251;
	double fConst252;
	double fRec1911[2];
	double fRec1909[2];
	double fRec1908[2];
	double fRec1906[2];
	double fRec1905[2];
	double fRec1903[2];
	double fRec1902[2];
	double fRec1900[2];
	double fRec1899[2];
	double fRec1897[2];
	double fRec1896[2];
	double fRec1894[2];
	double fConst253;
	double fConst254;
	double fConst255;
	double fConst256;
	double fConst257;
	double fConst258;
	double fConst259;
	double fConst260;
	double fConst261;
	double fRec1926[2];
	double fRec1924[2];
	double fRec1923[2];
	double fRec1921[2];
	double fRec1920[2];
	double fRec1918[2];
	double fRec1917[2];
	double fRec1915[2];
	double fRec1914[2];
	double fRec1912[2];
	double fConst262;
	double fConst263;
	double fConst264;
	double fConst265;
	double fConst266;
	double fConst267;
	double fConst268;
	double fRec1938[2];
	double fRec1936[2];
	double fRec1935[2];
	double fRec1933[2];
	double fRec1932[2];
	double fRec1930[2];
	double fRec1929[2];
	double fRec1927[2];
	double fConst269;
	double fConst270;
	double fConst271;
	double fConst272;
	double fConst273;
	double fConst274;
	double fRec1947[2];
	double fRec1945[2];
	double fRec1944[2];
	double fRec1942[2];
	double fRec1941[2];
	double fRec1939[2];
	double fConst275;
	double fConst276;
	double fConst277;
	double fRec1950[2];
	double fRec1948[2];
	double fConst278;
	double fConst279;
	double fConst280;
	double fConst281;
	double fRec1956[2];
	double fRec1954[2];
	double fRec1953[2];
	double fRec1951[2];
	double fVec28[512];
	int iConst282;
	double fConst283;
	double fConst284;
	double fConst285;
	double fConst286;
	double fConst287;
	double fConst288;
	double fConst289;
	double fConst290;
	double fConst291;
	double fConst292;
	double fRec1974[2];
	double fRec1972[2];
	double fRec1971[2];
	double fRec1969[2];
	double fRec1968[2];
	double fRec1966[2];
	double fRec1965[2];
	double fRec1963[2];
	double fRec1962[2];
	double fRec1960[2];
	double fRec1959[2];
	double fRec1957[2];
	double fConst293;
	double fConst294;
	double fConst295;
	double fConst296;
	double fConst297;
	double fConst298;
	double fConst299;
	double fConst300;
	double fConst301;
	double fRec1989[2];
	double fRec1987[2];
	double fRec1986[2];
	double fRec1984[2];
	double fRec1983[2];
	double fRec1981[2];
	double fRec1980[2];
	double fRec1978[2];
	double fRec1977[2];
	double fRec1975[2];
	double fConst302;
	double fConst303;
	double fConst304;
	double fConst305;
	double fConst306;
	double fConst307;
	double fConst308;
	double fRec2001[2];
	double fRec1999[2];
	double fRec1998[2];
	double fRec1996[2];
	double fRec1995[2];
	double fRec1993[2];
	double fRec1992[2];
	double fRec1990[2];
	double fConst309;
	double fConst310;
	double fConst311;
	double fConst312;
	double fConst313;
	double fConst314;
	double fRec2010[2];
	double fRec2008[2];
	double fRec2007[2];
	double fRec2005[2];
	double fRec2004[2];
	double fRec2002[2];
	double fConst315;
	double fConst316;
	double fConst317;
	double fRec2013[2];
	double fRec2011[2];
	double fConst318;
	double fConst319;
	double fConst320;
	double fConst321;
	double fRec2019[2];
	double fRec2017[2];
	double fRec2016[2];
	double fRec2014[2];
	double fVec29[512];
	int iConst322;
	double fRec2037[2];
	double fRec2035[2];
	double fRec2034[2];
	double fRec2032[2];
	double fRec2031[2];
	double fRec2029[2];
	double fRec2028[2];
	double fRec2026[2];
	double fRec2025[2];
	double fRec2023[2];
	double fRec2022[2];
	double fRec2020[2];
	double fRec2052[2];
	double fRec2050[2];
	double fRec2049[2];
	double fRec2047[2];
	double fRec2046[2];
	double fRec2044[2];
	double fRec2043[2];
	double fRec2041[2];
	double fRec2040[2];
	double fRec2038[2];
	double fRec2064[2];
	double fRec2062[2];
	double fRec2061[2];
	double fRec2059[2];
	double fRec2058[2];
	double fRec2056[2];
	double fRec2055[2];
	double fRec2053[2];
	double fRec2073[2];
	double fRec2071[2];
	double fRec2070[2];
	double fRec2068[2];
	double fRec2067[2];
	double fRec2065[2];
	double fRec2076[2];
	double fRec2074[2];
	double fRec2082[2];
	double fRec2080[2];
	double fRec2079[2];
	double fRec2077[2];
	double fVec30[512];
	double fRec2100[2];
	double fRec2098[2];
	double fRec2097[2];
	double fRec2095[2];
	double fRec2094[2];
	double fRec2092[2];
	double fRec2091[2];
	double fRec2089[2];
	double fRec2088[2];
	double fRec2086[2];
	double fRec2085[2];
	double fRec2083[2];
	double fRec2115[2];
	double fRec2113[2];
	double fRec2112[2];
	double fRec2110[2];
	double fRec2109[2];
	double fRec2107[2];
	double fRec2106[2];
	double fRec2104[2];
	double fRec2103[2];
	double fRec2101[2];
	double fRec2127[2];
	double fRec2125[2];
	double fRec2124[2];
	double fRec2122[2];
	double fRec2121[2];
	double fRec2119[2];
	double fRec2118[2];
	double fRec2116[2];
	double fRec2136[2];
	double fRec2134[2];
	double fRec2133[2];
	double fRec2131[2];
	double fRec2130[2];
	double fRec2128[2];
	double fRec2139[2];
	double fRec2137[2];
	double fRec2145[2];
	double fRec2143[2];
	double fRec2142[2];
	double fRec2140[2];
	double fVec31[512];
	double fRec2163[2];
	double fRec2161[2];
	double fRec2160[2];
	double fRec2158[2];
	double fRec2157[2];
	double fRec2155[2];
	double fRec2154[2];
	double fRec2152[2];
	double fRec2151[2];
	double fRec2149[2];
	double fRec2148[2];
	double fRec2146[2];
	double fRec2178[2];
	double fRec2176[2];
	double fRec2175[2];
	double fRec2173[2];
	double fRec2172[2];
	double fRec2170[2];
	double fRec2169[2];
	double fRec2167[2];
	double fRec2166[2];
	double fRec2164[2];
	double fRec2190[2];
	double fRec2188[2];
	double fRec2187[2];
	double fRec2185[2];
	double fRec2184[2];
	double fRec2182[2];
	double fRec2181[2];
	double fRec2179[2];
	double fRec2199[2];
	double fRec2197[2];
	double fRec2196[2];
	double fRec2194[2];
	double fRec2193[2];
	double fRec2191[2];
	double fRec2202[2];
	double fRec2200[2];
	double fRec2208[2];
	double fRec2206[2];
	double fRec2205[2];
	double fRec2203[2];
	double fVec32[512];
	double fRec2226[2];
	double fRec2224[2];
	double fRec2223[2];
	double fRec2221[2];
	double fRec2220[2];
	double fRec2218[2];
	double fRec2217[2];
	double fRec2215[2];
	double fRec2214[2];
	double fRec2212[2];
	double fRec2211[2];
	double fRec2209[2];
	double fRec2241[2];
	double fRec2239[2];
	double fRec2238[2];
	double fRec2236[2];
	double fRec2235[2];
	double fRec2233[2];
	double fRec2232[2];
	double fRec2230[2];
	double fRec2229[2];
	double fRec2227[2];
	double fRec2253[2];
	double fRec2251[2];
	double fRec2250[2];
	double fRec2248[2];
	double fRec2247[2];
	double fRec2245[2];
	double fRec2244[2];
	double fRec2242[2];
	double fRec2262[2];
	double fRec2260[2];
	double fRec2259[2];
	double fRec2257[2];
	double fRec2256[2];
	double fRec2254[2];
	double fRec2265[2];
	double fRec2263[2];
	double fRec2271[2];
	double fRec2269[2];
	double fRec2268[2];
	double fRec2266[2];
	double fVec33[512];
	double fRec2289[2];
	double fRec2287[2];
	double fRec2286[2];
	double fRec2284[2];
	double fRec2283[2];
	double fRec2281[2];
	double fRec2280[2];
	double fRec2278[2];
	double fRec2277[2];
	double fRec2275[2];
	double fRec2274[2];
	double fRec2272[2];
	double fRec2304[2];
	double fRec2302[2];
	double fRec2301[2];
	double fRec2299[2];
	double fRec2298[2];
	double fRec2296[2];
	double fRec2295[2];
	double fRec2293[2];
	double fRec2292[2];
	double fRec2290[2];
	double fRec2316[2];
	double fRec2314[2];
	double fRec2313[2];
	double fRec2311[2];
	double fRec2310[2];
	double fRec2308[2];
	double fRec2307[2];
	double fRec2305[2];
	double fRec2325[2];
	double fRec2323[2];
	double fRec2322[2];
	double fRec2320[2];
	double fRec2319[2];
	double fRec2317[2];
	double fRec2328[2];
	double fRec2326[2];
	double fRec2334[2];
	double fRec2332[2];
	double fRec2331[2];
	double fRec2329[2];
	double fVec34[512];
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
	double fRec2337[2];
	double fRec2335[2];
	double fRec2367[2];
	double fRec2365[2];
	double fRec2364[2];
	double fRec2362[2];
	double fRec2361[2];
	double fRec2359[2];
	double fRec2358[2];
	double fRec2356[2];
	double fRec2355[2];
	double fRec2353[2];
	double fRec2379[2];
	double fRec2377[2];
	double fRec2376[2];
	double fRec2374[2];
	double fRec2373[2];
	double fRec2371[2];
	double fRec2370[2];
	double fRec2368[2];
	double fRec2388[2];
	double fRec2386[2];
	double fRec2385[2];
	double fRec2383[2];
	double fRec2382[2];
	double fRec2380[2];
	double fRec2391[2];
	double fRec2389[2];
	double fRec2397[2];
	double fRec2395[2];
	double fRec2394[2];
	double fRec2392[2];
	double fVec35[512];
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
	double fRec2400[2];
	double fRec2398[2];
	double fRec2430[2];
	double fRec2428[2];
	double fRec2427[2];
	double fRec2425[2];
	double fRec2424[2];
	double fRec2422[2];
	double fRec2421[2];
	double fRec2419[2];
	double fRec2418[2];
	double fRec2416[2];
	double fRec2442[2];
	double fRec2440[2];
	double fRec2439[2];
	double fRec2437[2];
	double fRec2436[2];
	double fRec2434[2];
	double fRec2433[2];
	double fRec2431[2];
	double fRec2451[2];
	double fRec2449[2];
	double fRec2448[2];
	double fRec2446[2];
	double fRec2445[2];
	double fRec2443[2];
	double fRec2454[2];
	double fRec2452[2];
	double fRec2460[2];
	double fRec2458[2];
	double fRec2457[2];
	double fRec2455[2];
	double fVec36[512];
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
	double fRec2463[2];
	double fRec2461[2];
	double fRec2493[2];
	double fRec2491[2];
	double fRec2490[2];
	double fRec2488[2];
	double fRec2487[2];
	double fRec2485[2];
	double fRec2484[2];
	double fRec2482[2];
	double fRec2481[2];
	double fRec2479[2];
	double fRec2505[2];
	double fRec2503[2];
	double fRec2502[2];
	double fRec2500[2];
	double fRec2499[2];
	double fRec2497[2];
	double fRec2496[2];
	double fRec2494[2];
	double fRec2514[2];
	double fRec2512[2];
	double fRec2511[2];
	double fRec2509[2];
	double fRec2508[2];
	double fRec2506[2];
	double fRec2517[2];
	double fRec2515[2];
	double fRec2523[2];
	double fRec2521[2];
	double fRec2520[2];
	double fRec2518[2];
	double fVec37[512];
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
	double fRec2526[2];
	double fRec2524[2];
	double fRec2556[2];
	double fRec2554[2];
	double fRec2553[2];
	double fRec2551[2];
	double fRec2550[2];
	double fRec2548[2];
	double fRec2547[2];
	double fRec2545[2];
	double fRec2544[2];
	double fRec2542[2];
	double fRec2568[2];
	double fRec2566[2];
	double fRec2565[2];
	double fRec2563[2];
	double fRec2562[2];
	double fRec2560[2];
	double fRec2559[2];
	double fRec2557[2];
	double fRec2577[2];
	double fRec2575[2];
	double fRec2574[2];
	double fRec2572[2];
	double fRec2571[2];
	double fRec2569[2];
	double fRec2580[2];
	double fRec2578[2];
	double fRec2586[2];
	double fRec2584[2];
	double fRec2583[2];
	double fRec2581[2];
	double fVec38[512];
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
	double fRec2589[2];
	double fRec2587[2];
	double fRec2619[2];
	double fRec2617[2];
	double fRec2616[2];
	double fRec2614[2];
	double fRec2613[2];
	double fRec2611[2];
	double fRec2610[2];
	double fRec2608[2];
	double fRec2607[2];
	double fRec2605[2];
	double fRec2631[2];
	double fRec2629[2];
	double fRec2628[2];
	double fRec2626[2];
	double fRec2625[2];
	double fRec2623[2];
	double fRec2622[2];
	double fRec2620[2];
	double fRec2640[2];
	double fRec2638[2];
	double fRec2637[2];
	double fRec2635[2];
	double fRec2634[2];
	double fRec2632[2];
	double fRec2643[2];
	double fRec2641[2];
	double fRec2649[2];
	double fRec2647[2];
	double fRec2646[2];
	double fRec2644[2];
	double fVec39[512];
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
	double fRec2652[2];
	double fRec2650[2];
	double fRec2682[2];
	double fRec2680[2];
	double fRec2679[2];
	double fRec2677[2];
	double fRec2676[2];
	double fRec2674[2];
	double fRec2673[2];
	double fRec2671[2];
	double fRec2670[2];
	double fRec2668[2];
	double fRec2694[2];
	double fRec2692[2];
	double fRec2691[2];
	double fRec2689[2];
	double fRec2688[2];
	double fRec2686[2];
	double fRec2685[2];
	double fRec2683[2];
	double fRec2703[2];
	double fRec2701[2];
	double fRec2700[2];
	double fRec2698[2];
	double fRec2697[2];
	double fRec2695[2];
	double fRec2706[2];
	double fRec2704[2];
	double fRec2712[2];
	double fRec2710[2];
	double fRec2709[2];
	double fRec2707[2];
	double fVec40[512];
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
	double fRec2715[2];
	double fRec2713[2];
	double fRec2745[2];
	double fRec2743[2];
	double fRec2742[2];
	double fRec2740[2];
	double fRec2739[2];
	double fRec2737[2];
	double fRec2736[2];
	double fRec2734[2];
	double fRec2733[2];
	double fRec2731[2];
	double fRec2757[2];
	double fRec2755[2];
	double fRec2754[2];
	double fRec2752[2];
	double fRec2751[2];
	double fRec2749[2];
	double fRec2748[2];
	double fRec2746[2];
	double fRec2766[2];
	double fRec2764[2];
	double fRec2763[2];
	double fRec2761[2];
	double fRec2760[2];
	double fRec2758[2];
	double fRec2769[2];
	double fRec2767[2];
	double fRec2775[2];
	double fRec2773[2];
	double fRec2772[2];
	double fRec2770[2];
	double fVec41[512];
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
	double fRec2778[2];
	double fRec2776[2];
	double fRec2808[2];
	double fRec2806[2];
	double fRec2805[2];
	double fRec2803[2];
	double fRec2802[2];
	double fRec2800[2];
	double fRec2799[2];
	double fRec2797[2];
	double fRec2796[2];
	double fRec2794[2];
	double fRec2820[2];
	double fRec2818[2];
	double fRec2817[2];
	double fRec2815[2];
	double fRec2814[2];
	double fRec2812[2];
	double fRec2811[2];
	double fRec2809[2];
	double fRec2829[2];
	double fRec2827[2];
	double fRec2826[2];
	double fRec2824[2];
	double fRec2823[2];
	double fRec2821[2];
	double fRec2832[2];
	double fRec2830[2];
	double fRec2838[2];
	double fRec2836[2];
	double fRec2835[2];
	double fRec2833[2];
	double fVec42[512];
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
	double fRec2841[2];
	double fRec2839[2];
	double fRec2871[2];
	double fRec2869[2];
	double fRec2868[2];
	double fRec2866[2];
	double fRec2865[2];
	double fRec2863[2];
	double fRec2862[2];
	double fRec2860[2];
	double fRec2859[2];
	double fRec2857[2];
	double fRec2883[2];
	double fRec2881[2];
	double fRec2880[2];
	double fRec2878[2];
	double fRec2877[2];
	double fRec2875[2];
	double fRec2874[2];
	double fRec2872[2];
	double fRec2892[2];
	double fRec2890[2];
	double fRec2889[2];
	double fRec2887[2];
	double fRec2886[2];
	double fRec2884[2];
	double fRec2895[2];
	double fRec2893[2];
	double fRec2901[2];
	double fRec2899[2];
	double fRec2898[2];
	double fRec2896[2];
	double fVec43[512];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMHLS_FullSetup_7h7v_full_6");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMHLS_FullSetup_7h7v_full_6");
		m->declare("version", "1.2");
	}

	virtual int getNumInputs() {
		return 64;
		
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
		fConst3 = ((((21038.792477813076 / fConst2) + 284.22983763570784) / fConst2) + 1.0);
		fConst4 = mydsp_faustpower2_f(fConst2);
		fConst5 = (0.0 - (84155.169911252306 / (fConst3 * fConst4)));
		fConst6 = (0.0 - (((84155.169911252306 / fConst2) + 568.45967527141568) / (fConst3 * fConst2)));
		fConst7 = ((((23334.672205785024 / fConst2) + 249.93172202114809) / fConst2) + 1.0);
		fConst8 = (0.0 - (93338.688823140095 / (fConst7 * fConst4)));
		fConst9 = (0.0 - (((93338.688823140095 / fConst2) + 499.86344404229618) / (fConst7 * fConst2)));
		fConst10 = ((((29669.655997962589 / fConst2) + 168.32451016126626) / fConst2) + 1.0);
		fConst11 = (1.0 / ((fConst3 * fConst7) * fConst10));
		fConst12 = (0.0 - (118678.62399185036 / (fConst10 * fConst4)));
		fConst13 = (0.0 - (((118678.62399185036 / fConst2) + 336.64902032253252) / (fConst10 * fConst2)));
		fConst14 = ((121.98966968986812 / fConst2) + 1.0);
		fConst15 = (0.0 - (243.97933937973625 / (fConst14 * fConst2)));
		fConst16 = ((((15971.154193732045 / fConst2) + 224.25739781362216) / fConst2) + 1.0);
		fConst17 = (0.0 - (63884.616774928181 / (fConst16 * fConst4)));
		fConst18 = (0.0 - (((63884.616774928181 / fConst2) + 448.51479562724433) / (fConst16 * fConst2)));
		fConst19 = ((((20317.232956903419 / fConst2) + 155.52869665231037) / fConst2) + 1.0);
		fConst20 = (1.0 / ((fConst14 * fConst16) * fConst19));
		fConst21 = (0.0 - (81268.931827613676 / (fConst19 * fConst4)));
		fConst22 = (0.0 - (((81268.931827613676 / fConst2) + 311.05739330462075) / (fConst19 * fConst2)));
		fConst23 = ((((10227.965605817382 / fConst2) + 193.7664384515102) / fConst2) + 1.0);
		fConst24 = (0.0 - (40911.862423269529 / (fConst23 * fConst4)));
		fConst25 = (0.0 - (((40911.862423269529 / fConst2) + 387.53287690302039) / (fConst23 * fConst2)));
		fConst26 = ((((12855.048748690073 / fConst2) + 140.75073765235712) / fConst2) + 1.0);
		fConst27 = (1.0 / (fConst23 * fConst26));
		fConst28 = (0.0 - (51420.194994760292 / (fConst26 * fConst4)));
		fConst29 = (0.0 - (((51420.194994760292 / fConst2) + 281.50147530471423) / (fConst26 * fConst2)));
		fConst30 = ((77.681088721927608 / fConst2) + 1.0);
		fConst31 = (0.0 - (155.36217744385522 / (fConst30 * fConst2)));
		fConst32 = ((((7228.2176497399441 / fConst2) + 123.02921694039281) / fConst2) + 1.0);
		fConst33 = (1.0 / (fConst30 * fConst32));
		fConst34 = (0.0 - (28912.870598959777 / (fConst32 * fConst4)));
		fConst35 = (0.0 - (((28912.870598959777 / fConst2) + 246.05843388078563) / (fConst32 * fConst2)));
		fConst36 = ((33.451717610386737 / fConst2) + 1.0);
		fConst37 = (1.0 / fConst36);
		fConst38 = (0.0 - (66.903435220773474 / (fConst36 * fConst2)));
		fConst39 = ((((3357.0522332551745 / fConst2) + 100.35515283116021) / fConst2) + 1.0);
		fConst40 = (1.0 / fConst39);
		fConst41 = (0.0 - (13428.208933020698 / (fConst39 * fConst4)));
		fConst42 = (0.0 - (((13428.208933020698 / fConst2) + 200.71030566232042) / (fConst39 * fConst2)));
		iConst43 = int(((0.00061186204235308644 * double(iConst0)) + 0.5));
		fConst44 = ((((20981.493974173598 / fConst2) + 283.84252814311498) / fConst2) + 1.0);
		fConst45 = (0.0 - (83925.975896694392 / (fConst4 * fConst44)));
		fConst46 = (0.0 - (((83925.975896694392 / fConst2) + 567.68505628622995) / (fConst2 * fConst44)));
		fConst47 = ((((23271.120944384485 / fConst2) + 249.59114930280123) / fConst2) + 1.0);
		fConst48 = (0.0 - (93084.483777537942 / (fConst4 * fConst47)));
		fConst49 = (0.0 - (((93084.483777537942 / fConst2) + 499.18229860560245) / (fConst2 * fConst47)));
		fConst50 = ((((29588.851603224914 / fConst2) + 168.09514057373877) / fConst2) + 1.0);
		fConst51 = (1.0 / ((fConst44 * fConst47) * fConst50));
		fConst52 = (0.0 - (118355.40641289965 / (fConst4 * fConst50)));
		fConst53 = (0.0 - (((118355.40641289965 / fConst2) + 336.19028114747755) / (fConst2 * fConst50)));
		fConst54 = ((121.82343887658625 / fConst2) + 1.0);
		fConst55 = (0.0 - (243.6468777531725 / (fConst2 * fConst54)));
		fConst56 = ((((15927.657246953317 / fConst2) + 223.95181054776756) / fConst2) + 1.0);
		fConst57 = (0.0 - (63710.628987813267 / (fConst4 * fConst56)));
		fConst58 = (0.0 - (((63710.628987813267 / fConst2) + 447.90362109553513) / (fConst2 * fConst56)));
		fConst59 = ((((20261.899598406115 / fConst2) + 155.31676344682742) / fConst2) + 1.0);
		fConst60 = (1.0 / ((fConst54 * fConst56) * fConst59));
		fConst61 = (0.0 - (81047.598393624459 / (fConst4 * fConst59)));
		fConst62 = (0.0 - (((81047.598393624459 / fConst2) + 310.63352689365485) / (fConst2 * fConst59)));
		fConst63 = ((((10200.110056355246 / fConst2) + 193.50240008881593) / fConst2) + 1.0);
		fConst64 = (0.0 - (40800.440225420985 / (fConst4 * fConst63)));
		fConst65 = (0.0 - (((40800.440225420985 / fConst2) + 387.00480017763186) / (fConst2 * fConst63)));
		fConst66 = ((((12820.038419162405 / fConst2) + 140.55894182530508) / fConst2) + 1.0);
		fConst67 = (1.0 / (fConst63 * fConst66));
		fConst68 = (0.0 - (51280.153676649621 / (fConst4 * fConst66)));
		fConst69 = (0.0 - (((51280.153676649621 / fConst2) + 281.11788365061017) / (fConst2 * fConst66)));
		fConst70 = ((77.575235573970943 / fConst2) + 1.0);
		fConst71 = (0.0 - (155.15047114794189 / (fConst2 * fConst70)));
		fConst72 = ((((7208.5318214897106 / fConst2) + 122.8615695745017) / fConst2) + 1.0);
		fConst73 = (1.0 / (fConst70 * fConst72));
		fConst74 = (0.0 - (28834.127285958843 / (fConst4 * fConst72)));
		fConst75 = (0.0 - (((28834.127285958843 / fConst2) + 245.7231391490034) / (fConst2 * fConst72)));
		fConst76 = ((33.406134191412107 / fConst2) + 1.0);
		fConst77 = (1.0 / fConst76);
		fConst78 = (0.0 - (66.812268382824215 / (fConst2 * fConst76)));
		fConst79 = ((((3347.9094048438992 / fConst2) + 100.21840257423632) / fConst2) + 1.0);
		fConst80 = (1.0 / fConst79);
		fConst81 = (0.0 - (13391.637619375597 / (fConst4 * fConst79)));
		fConst82 = (0.0 - (((13391.637619375597 / fConst2) + 200.43680514847264) / (fConst2 * fConst79)));
		iConst83 = int(((0.00059146664094131783 * double(iConst0)) + 0.5));
		fConst84 = ((((21006.021777992148 / fConst2) + 284.00838859976261) / fConst2) + 1.0);
		fConst85 = (0.0 - (84024.087111968591 / (fConst4 * fConst84)));
		fConst86 = (0.0 - (((84024.087111968591 / fConst2) + 568.01677719952522) / (fConst2 * fConst84)));
		fConst87 = ((((23298.325369858867 / fConst2) + 249.73699531914485) / fConst2) + 1.0);
		fConst88 = (0.0 - (93193.301479435468 / (fConst4 * fConst87)));
		fConst89 = (0.0 - (((93193.301479435468 / fConst2) + 499.47399063828971) / (fConst2 * fConst87)));
		fConst90 = ((((29623.441587533631 / fConst2) + 168.19336523710479) / fConst2) + 1.0);
		fConst91 = (1.0 / ((fConst84 * fConst87) * fConst90));
		fConst92 = (0.0 - (118493.76635013452 / (fConst4 * fConst90)));
		fConst93 = (0.0 - (((118493.76635013452 / fConst2) + 336.38673047420957) / (fConst2 * fConst90)));
		fConst94 = ((121.89462514784252 / fConst2) + 1.0);
		fConst95 = (0.0 - (243.78925029568504 / (fConst2 * fConst94)));
		fConst96 = ((((15946.277010289676 / fConst2) + 224.08267448069375) / fConst2) + 1.0);
		fConst97 = (0.0 - (63785.108041158703 / (fConst4 * fConst96)));
		fConst98 = (0.0 - (((63785.108041158703 / fConst2) + 448.16534896138751) / (fConst2 * fConst96)));
		fConst99 = ((((20285.586181399329 / fConst2) + 155.40752119718587) / fConst2) + 1.0);
		fConst100 = (1.0 / ((fConst94 * fConst96) * fConst99));
		fConst101 = (0.0 - (81142.344725597315 / (fConst4 * fConst99)));
		fConst102 = (0.0 - (((81142.344725597315 / fConst2) + 310.81504239437174) / (fConst2 * fConst99)));
		fConst103 = ((((10212.034197634121 / fConst2) + 193.6154712224868) / fConst2) + 1.0);
		fConst104 = (0.0 - (40848.136790536482 / (fConst4 * fConst103)));
		fConst105 = (0.0 - (((40848.136790536482 / fConst2) + 387.23094244497361) / (fConst2 * fConst103)));
		fConst106 = ((((12835.025311310244 / fConst2) + 140.64107599466149) / fConst2) + 1.0);
		fConst107 = (1.0 / (fConst103 * fConst106));
		fConst108 = (0.0 - (51340.101245240978 / (fConst4 * fConst106)));
		fConst109 = (0.0 - (((51340.101245240978 / fConst2) + 281.28215198932298) / (fConst2 * fConst106)));
		fConst110 = ((77.620565863554475 / fConst2) + 1.0);
		fConst111 = (0.0 - (155.24113172710895 / (fConst2 * fConst110)));
		fConst112 = ((((7216.9587454520797 / fConst2) + 122.93336246673454) / fConst2) + 1.0);
		fConst113 = (1.0 / (fConst110 * fConst112));
		fConst114 = (0.0 - (28867.834981808319 / (fConst4 * fConst112)));
		fConst115 = (0.0 - (((28867.834981808319 / fConst2) + 245.86672493346907) / (fConst2 * fConst112)));
		fConst116 = ((33.425654721714835 / fConst2) + 1.0);
		fConst117 = (1.0 / fConst116);
		fConst118 = (0.0 - (66.85130944342967 / (fConst2 * fConst116)));
		fConst119 = ((((3351.8231807258917 / fConst2) + 100.27696416514451) / fConst2) + 1.0);
		fConst120 = (1.0 / fConst119);
		fConst121 = (0.0 - (13407.292722903567 / (fConst4 * fConst119)));
		fConst122 = (0.0 - (((13407.292722903567 / fConst2) + 200.55392833028901) / (fConst2 * fConst119)));
		iConst123 = int(((0.00060020752726064536 * double(iConst0)) + 0.5));
		fConst124 = ((((20444.710454478012 / fConst2) + 280.18813740799027) / fConst2) + 1.0);
		fConst125 = (0.0 - (81778.841817912049 / (fConst4 * fConst124)));
		fConst126 = (0.0 - (((81778.841817912049 / fConst2) + 560.37627481598054) / (fConst2 * fConst124)));
		fConst127 = ((((22675.760374581194 / fConst2) + 246.37773519763451) / fConst2) + 1.0);
		fConst128 = (0.0 - (90703.041498324776 / (fConst4 * fConst127)));
		fConst129 = (0.0 - (((90703.041498324776 / fConst2) + 492.75547039526901) / (fConst2 * fConst127)));
		fConst130 = ((((28831.860326679984 / fConst2) + 165.9309640905642) / fConst2) + 1.0);
		fConst131 = (1.0 / ((fConst124 * fConst127) * fConst130));
		fConst132 = (0.0 - (115327.44130671993 / (fConst4 * fConst130)));
		fConst133 = (0.0 - (((115327.44130671993 / fConst2) + 331.86192818112841) / (fConst2 * fConst130)));
		fConst134 = ((120.25499721541576 / fConst2) + 1.0);
		fConst135 = (0.0 - (240.50999443083151 / (fConst2 * fConst134)));
		fConst136 = ((((15520.169394656026 / fConst2) + 221.0684955387936) / fConst2) + 1.0);
		fConst137 = (0.0 - (62080.677578624105 / (fConst4 * fConst136)));
		fConst138 = (0.0 - (((62080.677578624105 / fConst2) + 442.1369910775872) / (fConst2 * fConst136)));
		fConst139 = ((((19743.525940384494 / fConst2) + 153.31710488592475) / fConst2) + 1.0);
		fConst140 = (1.0 / ((fConst134 * fConst136) * fConst139));
		fConst141 = (0.0 - (78974.103761537976 / (fConst4 * fConst139)));
		fConst142 = (0.0 - (((78974.103761537976 / fConst2) + 306.6342097718495) / (fConst2 * fConst139)));
		fConst143 = ((((9939.1538544721825 / fConst2) + 191.01111246276852) / fConst2) + 1.0);
		fConst144 = (0.0 - (39756.61541788873 / (fConst4 * fConst143)));
		fConst145 = (0.0 - (((39756.61541788873 / fConst2) + 382.02222492553705) / (fConst2 * fConst143)));
		fConst146 = ((((12492.054846889559 / fConst2) + 138.74928596398775) / fConst2) + 1.0);
		fConst147 = (1.0 / (fConst143 * fConst146));
		fConst148 = (0.0 - (49968.219387558238 / (fConst4 * fConst146)));
		fConst149 = (0.0 - (((49968.219387558238 / fConst2) + 277.49857192797549) / (fConst2 * fConst146)));
		fConst150 = ((76.576476776227651 / fConst2) + 1.0);
		fConst151 = (0.0 - (153.1529535524553 / (fConst2 * fConst150)));
		fConst152 = ((((7024.111155938449 / fConst2) + 121.27976227982614) / fConst2) + 1.0);
		fConst153 = (1.0 / (fConst150 * fConst152));
		fConst154 = (0.0 - (28096.444623753796 / (fConst4 * fConst152)));
		fConst155 = (0.0 - (((28096.444623753796 / fConst2) + 242.55952455965229) / (fConst2 * fConst152)));
		fConst156 = ((32.976039842675632 / fConst2) + 1.0);
		fConst157 = (1.0 / fConst156);
		fConst158 = (0.0 - (65.952079685351265 / (fConst2 * fConst156)));
		fConst159 = ((((3262.257611117192 / fConst2) + 98.928119528026897) / fConst2) + 1.0);
		fConst160 = (1.0 / fConst159);
		fConst161 = (0.0 - (13049.030444468768 / (fConst4 * fConst159)));
		fConst162 = (0.0 - (((13049.030444468768 / fConst2) + 197.85623905605379) / (fConst2 * fConst159)));
		iConst163 = int(((0.00039625351314295164 * double(iConst0)) + 0.5));
		fConst164 = ((((19555.504396696881 / fConst2) + 274.02726312181574) / fConst2) + 1.0);
		fConst165 = (0.0 - (78222.017586787522 / (fConst4 * fConst164)));
		fConst166 = (0.0 - (((78222.017586787522 / fConst2) + 548.05452624363147) / (fConst2 * fConst164)));
		fConst167 = ((((21689.51879709509 / fConst2) + 240.96029580313663) / fConst2) + 1.0);
		fConst168 = (0.0 - (86758.07518838036 / (fConst4 * fConst167)));
		fConst169 = (0.0 - (((86758.07518838036 / fConst2) + 481.92059160627326) / (fConst2 * fConst167)));
		fConst170 = ((((27577.870209448072 / fConst2) + 162.28241629905961) / fConst2) + 1.0);
		fConst171 = (1.0 / ((fConst164 * fConst167) * fConst170));
		fConst172 = (0.0 - (110311.48083779229 / (fConst4 * fConst170)));
		fConst173 = (0.0 - (((110311.48083779229 / fConst2) + 324.56483259811921) / (fConst2 * fConst170)));
		fConst174 = ((117.61078848130494 / fConst2) + 1.0);
		fConst175 = (0.0 - (235.22157696260987 / (fConst2 * fConst174)));
		fConst176 = ((((14845.147428742359 / fConst2) + 216.20756451491863) / fConst2) + 1.0);
		fConst177 = (0.0 - (59380.589714969436 / (fConst4 * fConst176)));
		fConst178 = (0.0 - (((59380.589714969436 / fConst2) + 432.41512902983726) / (fConst2 * fConst176)));
		fConst179 = ((((18884.816646983691 / fConst2) + 149.94591502092698) / fConst2) + 1.0);
		fConst180 = (1.0 / ((fConst174 * fConst176) * fConst179));
		fConst181 = (0.0 - (75539.266587934762 / (fConst4 * fConst179)));
		fConst182 = (0.0 - (((75539.266587934762 / fConst2) + 299.89183004185395) / (fConst2 * fConst179)));
		fConst183 = ((((9506.8681619800409 / fConst2) + 186.81109363958794) / fConst2) + 1.0);
		fConst184 = (0.0 - (38027.472647920164 / (fConst4 * fConst183)));
		fConst185 = (0.0 - (((38027.472647920164 / fConst2) + 373.62218727917588) / (fConst2 * fConst183)));
		fConst186 = ((((11948.735298846983 / fConst2) + 135.69841837184595) / fConst2) + 1.0);
		fConst187 = (1.0 / (fConst183 * fConst186));
		fConst188 = (0.0 - (47794.941195387932 / (fConst4 * fConst186)));
		fConst189 = (0.0 - (((47794.941195387932 / fConst2) + 271.39683674369189) / (fConst2 * fConst186)));
		fConst190 = ((74.892686552055764 / fConst2) + 1.0);
		fConst191 = (0.0 - (149.78537310411153 / (fConst2 * fConst190)));
		fConst192 = ((((6718.6100237851942 / fConst2) + 118.6130206548046) / fConst2) + 1.0);
		fConst193 = (1.0 / (fConst190 * fConst192));
		fConst194 = (0.0 - (26874.440095140777 / (fConst4 * fConst192)));
		fConst195 = (0.0 - (((26874.440095140777 / fConst2) + 237.2260413096092) / (fConst2 * fConst192)));
		fConst196 = ((32.250951201143394 / fConst2) + 1.0);
		fConst197 = (1.0 / fConst196);
		fConst198 = (0.0 - (64.501902402286788 / (fConst2 * fConst196)));
		fConst199 = ((((3120.3715601355971 / fConst2) + 96.752853603430182) / fConst2) + 1.0);
		fConst200 = (1.0 / fConst199);
		fConst201 = (0.0 - (12481.486240542388 / (fConst4 * fConst199)));
		fConst202 = (0.0 - (((12481.486240542388 / fConst2) + 193.50570720686036) / (fConst2 * fConst199)));
		iConst203 = int(((5.5358946689089155e-05 * double(iConst0)) + 0.5));
		fConst204 = ((((19416.592944190514 / fConst2) + 273.05225975115758) / fConst2) + 1.0);
		fConst205 = (0.0 - (77666.371776762055 / (fConst4 * fConst204)));
		fConst206 = (0.0 - (((77666.371776762055 / fConst2) + 546.10451950231516) / (fConst2 * fConst204)));
		fConst207 = ((((21535.448490385053 / fConst2) + 240.10294643604678) / fConst2) + 1.0);
		fConst208 = (0.0 - (86141.793961540214 / (fConst4 * fConst207)));
		fConst209 = (0.0 - (((86141.793961540214 / fConst2) + 480.20589287209356) / (fConst2 * fConst207)));
		fConst210 = ((((27381.972321563702 / fConst2) + 161.70500695267717) / fConst2) + 1.0);
		fConst211 = (1.0 / ((fConst204 * fConst207) * fConst210));
		fConst212 = (0.0 - (109527.88928625481 / (fConst4 * fConst210)));
		fConst213 = (0.0 - (((109527.88928625481 / fConst2) + 323.41001390535433) / (fConst2 * fConst210)));
		fConst214 = ((117.19232312903063 / fConst2) + 1.0);
		fConst215 = (0.0 - (234.38464625806125 / (fConst2 * fConst214)));
		fConst216 = ((((14739.69573850899 / fConst2) + 215.43828666364828) / fConst2) + 1.0);
		fConst217 = (0.0 - (58958.78295403596 / (fConst4 * fConst216)));
		fConst218 = (0.0 - (((58958.78295403596 / fConst2) + 430.87657332729657) / (fConst2 * fConst216)));
		fConst219 = ((((18750.669388107974 / fConst2) + 149.41239959294987) / fConst2) + 1.0);
		fConst220 = (1.0 / ((fConst214 * fConst216) * fConst219));
		fConst221 = (0.0 - (75002.677552431895 / (fConst4 * fConst219)));
		fConst222 = (0.0 - (((75002.677552431895 / fConst2) + 298.82479918589974) / (fConst2 * fConst219)));
		fConst223 = ((((9439.3366456162785 / fConst2) + 186.14640997308004) / fConst2) + 1.0);
		fConst224 = (0.0 - (37757.346582465114 / (fConst4 * fConst223)));
		fConst225 = (0.0 - (((37757.346582465114 / fConst2) + 372.29281994616008) / (fConst2 * fConst223)));
		fConst226 = ((((11863.858113257369 / fConst2) + 135.21559628400601) / fConst2) + 1.0);
		fConst227 = (1.0 / (fConst223 * fConst226));
		fConst228 = (0.0 - (47455.432453029476 / (fConst4 * fConst226)));
		fConst229 = (0.0 - (((47455.432453029476 / fConst2) + 270.43119256801202) / (fConst2 * fConst226)));
		fConst230 = ((74.626214446346196 / fConst2) + 1.0);
		fConst231 = (0.0 - (149.25242889269239 / (fConst2 * fConst230)));
		fConst232 = ((((6670.8847461193591 / fConst2) + 118.19098930790547) / fConst2) + 1.0);
		fConst233 = (1.0 / (fConst230 * fConst232));
		fConst234 = (0.0 - (26683.538984477436 / (fConst4 * fConst232)));
		fConst235 = (0.0 - (((26683.538984477436 / fConst2) + 236.38197861581094) / (fConst2 * fConst232)));
		fConst236 = ((32.136200625708611 / fConst2) + 1.0);
		fConst237 = (1.0 / fConst236);
		fConst238 = (0.0 - (64.272401251417222 / (fConst2 * fConst236)));
		fConst239 = ((((3098.2061719673839 / fConst2) + 96.408601877125832) / fConst2) + 1.0);
		fConst240 = (1.0 / fConst239);
		fConst241 = (0.0 - (12392.824687869535 / (fConst4 * fConst239)));
		fConst242 = (0.0 - (((12392.824687869535 / fConst2) + 192.81720375425166) / (fConst2 * fConst239)));
		fConst243 = ((((25279.229571159281 / fConst2) + 311.55962971606442) / fConst2) + 1.0);
		fConst244 = (0.0 - (101116.91828463713 / (fConst4 * fConst243)));
		fConst245 = (0.0 - (((101116.91828463713 / fConst2) + 623.11925943212884) / (fConst2 * fConst243)));
		fConst246 = ((((28037.851330101908 / fConst2) + 273.96361836933545) / fConst2) + 1.0);
		fConst247 = (0.0 - (112151.40532040763 / (fConst4 * fConst246)));
		fConst248 = (0.0 - (((112151.40532040763 / fConst2) + 547.9272367386709) / (fConst2 * fConst246)));
		fConst249 = ((((35649.671722404026 / fConst2) + 184.50955921523422) / fConst2) + 1.0);
		fConst250 = (1.0 / ((fConst243 * fConst246) * fConst249));
		fConst251 = (0.0 - (142598.6868896161 / (fConst4 * fConst249)));
		fConst252 = (0.0 - (((142598.6868896161 / fConst2) + 369.01911843046844) / (fConst2 * fConst249)));
		fConst253 = ((133.71944562158623 / fConst2) + 1.0);
		fConst254 = (0.0 - (267.43889124317246 / (fConst2 * fConst253)));
		fConst255 = ((((19190.192298607777 / fConst2) + 245.82060914185513) / fConst2) + 1.0);
		fConst256 = (0.0 - (76760.769194431108 / (fConst4 * fConst255)));
		fConst257 = (0.0 - (((76760.769194431108 / fConst2) + 491.64121828371026) / (fConst2 * fConst255)));
		fConst258 = ((((24412.237380539653 / fConst2) + 170.48337902272488) / fConst2) + 1.0);
		fConst259 = (1.0 / ((fConst253 * fConst255) * fConst258));
		fConst260 = (0.0 - (97648.949522158611 / (fConst4 * fConst258)));
		fConst261 = (0.0 - (((97648.949522158611 / fConst2) + 340.96675804544975) / (fConst2 * fConst258)));
		fConst262 = ((((12289.445359948479 / fConst2) + 212.39782676415544) / fConst2) + 1.0);
		fConst263 = (0.0 - (49157.781439793915 / (fConst4 * fConst262)));
		fConst264 = (0.0 - (((49157.781439793915 / fConst2) + 424.79565352831088) / (fConst2 * fConst262)));
		fConst265 = ((((15446.025659946026 / fConst2) + 154.28446242662227) / fConst2) + 1.0);
		fConst266 = (1.0 / (fConst262 * fConst265));
		fConst267 = (0.0 - (61784.102639784105 / (fConst4 * fConst265)));
		fConst268 = (0.0 - (((61784.102639784105 / fConst2) + 308.56892485324454) / (fConst2 * fConst265)));
		fConst269 = ((85.150424175959131 / fConst2) + 1.0);
		fConst270 = (0.0 - (170.30084835191826 / (fConst2 * fConst269)));
		fConst271 = ((((8685.0884408302827 / fConst2) + 134.85894933850753) / fConst2) + 1.0);
		fConst272 = (1.0 / (fConst269 * fConst271));
		fConst273 = (0.0 - (34740.353763321131 / (fConst4 * fConst271)));
		fConst274 = (0.0 - (((34740.353763321131 / fConst2) + 269.71789867701506) / (fConst2 * fConst271)));
		fConst275 = ((36.668228919077777 / fConst2) + 1.0);
		fConst276 = (1.0 / fConst275);
		fConst277 = (0.0 - (73.336457838155553 / (fConst275 * fConst2)));
		fConst278 = ((((4033.6770361856752 / fConst2) + 110.00468675723333) / fConst2) + 1.0);
		fConst279 = (1.0 / fConst278);
		fConst280 = (0.0 - (16134.708144742701 / (fConst4 * fConst278)));
		fConst281 = (0.0 - (((16134.708144742701 / fConst2) + 220.00937351446666) / (fConst2 * fConst278)));
		iConst282 = int(((0.001922994990252558 * double(iConst0)) + 0.5));
		fConst283 = ((((25387.607708750049 / fConst2) + 312.2267809574264) / fConst2) + 1.0);
		fConst284 = (0.0 - (101550.4308350002 / (fConst4 * fConst283)));
		fConst285 = (0.0 - (((101550.4308350002 / fConst2) + 624.4535619148528) / (fConst2 * fConst283)));
		fConst286 = ((((28158.056342705222 / fConst2) + 274.55026423308135) / fConst2) + 1.0);
		fConst287 = (0.0 - (112632.22537082089 / (fConst4 * fConst286)));
		fConst288 = (0.0 - (((112632.22537082089 / fConst2) + 549.1005284661627) / (fConst2 * fConst286)));
		fConst289 = ((((35802.510439902137 / fConst2) + 184.90465463111263) / fConst2) + 1.0);
		fConst290 = (1.0 / ((fConst283 * fConst286) * fConst289));
		fConst291 = (0.0 - (143210.04175960855 / (fConst4 * fConst289)));
		fConst292 = (0.0 - (((143210.04175960855 / fConst2) + 369.80930926222527) / (fConst2 * fConst289)));
		fConst293 = ((134.00578276424486 / fConst2) + 1.0);
		fConst294 = (0.0 - (268.01156552848971 / (fConst293 * fConst2)));
		fConst295 = ((((19272.465268813507 / fConst2) + 246.34699160254428) / fConst2) + 1.0);
		fConst296 = (0.0 - (77089.861075254026 / (fConst295 * fConst4)));
		fConst297 = (0.0 - (((77089.861075254026 / fConst2) + 492.69398320508856) / (fConst295 * fConst2)));
		fConst298 = ((((24516.898514071392 / fConst2) + 170.84843979151012) / fConst2) + 1.0);
		fConst299 = (1.0 / ((fConst293 * fConst295) * fConst298));
		fConst300 = (0.0 - (98067.594056285569 / (fConst298 * fConst4)));
		fConst301 = (0.0 - (((98067.594056285569 / fConst2) + 341.69687958302023) / (fConst298 * fConst2)));
		fConst302 = ((((12342.133168189845 / fConst2) + 212.8526400976975) / fConst2) + 1.0);
		fConst303 = (0.0 - (49368.532672759378 / (fConst4 * fConst302)));
		fConst304 = (0.0 - (((49368.532672759378 / fConst2) + 425.70528019539501) / (fConst2 * fConst302)));
		fConst305 = ((((15512.246487186505 / fConst2) + 154.61483600783558) / fConst2) + 1.0);
		fConst306 = (1.0 / (fConst302 * fConst305));
		fConst307 = (0.0 - (62048.98594874602 / (fConst4 * fConst305)));
		fConst308 = (0.0 - (((62048.98594874602 / fConst2) + 309.22967201567116) / (fConst2 * fConst305)));
		fConst309 = ((85.332759131368022 / fConst2) + 1.0);
		fConst310 = (0.0 - (170.66551826273604 / (fConst2 * fConst309)));
		fConst311 = ((((8722.3235040025465 / fConst2) + 135.14772653195186) / fConst2) + 1.0);
		fConst312 = (1.0 / (fConst309 * fConst311));
		fConst313 = (0.0 - (34889.294016010186 / (fConst4 * fConst311)));
		fConst314 = (0.0 - (((34889.294016010186 / fConst2) + 270.29545306390372) / (fConst2 * fConst311)));
		fConst315 = ((36.746747610553314 / fConst2) + 1.0);
		fConst316 = (1.0 / fConst315);
		fConst317 = (0.0 - (73.493495221106627 / (fConst2 * fConst315)));
		fConst318 = ((((4050.9703798611172 / fConst2) + 110.24024283165994) / fConst2) + 1.0);
		fConst319 = (1.0 / fConst318);
		fConst320 = (0.0 - (16203.881519444469 / (fConst4 * fConst318)));
		fConst321 = (0.0 - (((16203.881519444469 / fConst2) + 220.48048566331988) / (fConst2 * fConst318)));
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
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec34[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec35[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec36[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec37[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec38[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec39[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec40[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec27[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec25[l24] = 0.0;
			
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec24[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec22[l26] = 0.0;
			
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec21[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec19[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec18[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec16[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec15[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec13[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec12[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec10[l34] = 0.0;
			
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
		for (int l39 = 0; (l39 < 3); l39 = (l39 + 1)) {
			fRec60[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 3); l40 = (l40 + 1)) {
			fRec61[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 3); l41 = (l41 + 1)) {
			fRec62[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec63[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) {
			fRec64[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) {
			fRec65[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec66[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec55[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec53[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec52[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec50[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec49[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec47[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec46[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fRec44[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec43[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec41[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec79[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 3); l57 = (l57 + 1)) {
			fRec80[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 3); l58 = (l58 + 1)) {
			fRec81[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 3); l59 = (l59 + 1)) {
			fRec82[l59] = 0.0;
			
		}
		for (int l60 = 0; (l60 < 3); l60 = (l60 + 1)) {
			fRec83[l60] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 3); l61 = (l61 + 1)) {
			fRec84[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 3); l62 = (l62 + 1)) {
			fRec85[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 3); l63 = (l63 + 1)) {
			fRec86[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 3); l64 = (l64 + 1)) {
			fRec87[l64] = 0.0;
			
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
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec72[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec70[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec69[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec67[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 3); l73 = (l73 + 1)) {
			fRec97[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 3); l74 = (l74 + 1)) {
			fRec98[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 3); l75 = (l75 + 1)) {
			fRec99[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 3); l76 = (l76 + 1)) {
			fRec100[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 3); l77 = (l77 + 1)) {
			fRec101[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 3); l78 = (l78 + 1)) {
			fRec102[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 3); l79 = (l79 + 1)) {
			fRec103[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec96[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec94[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec93[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fRec91[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec90[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec88[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 3); l86 = (l86 + 1)) {
			fRec107[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 3); l87 = (l87 + 1)) {
			fRec108[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 3); l88 = (l88 + 1)) {
			fRec109[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) {
			fRec106[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec104[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 3); l91 = (l91 + 1)) {
			fRec116[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 3); l92 = (l92 + 1)) {
			fRec117[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 3); l93 = (l93 + 1)) {
			fRec118[l93] = 0.0;
			
		}
		for (int l94 = 0; (l94 < 3); l94 = (l94 + 1)) {
			fRec119[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 3); l95 = (l95 + 1)) {
			fRec120[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fRec115[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec113[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec112[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec110[l99] = 0.0;
			
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
		for (int l108 = 0; (l108 < 3); l108 = (l108 + 1)) {
			fRec129[l108] = 0.0;
			
		}
		IOTA = 0;
		for (int l109 = 0; (l109 < 128); l109 = (l109 + 1)) {
			fVec0[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec147[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec145[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec144[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec142[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec141[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec139[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec138[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec136[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec135[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec133[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec132[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec130[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec162[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec160[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec159[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fRec157[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec156[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec154[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec153[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec151[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec150[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 2); l131 = (l131 + 1)) {
			fRec148[l131] = 0.0;
			
		}
		for (int l132 = 0; (l132 < 2); l132 = (l132 + 1)) {
			fRec174[l132] = 0.0;
			
		}
		for (int l133 = 0; (l133 < 2); l133 = (l133 + 1)) {
			fRec172[l133] = 0.0;
			
		}
		for (int l134 = 0; (l134 < 2); l134 = (l134 + 1)) {
			fRec171[l134] = 0.0;
			
		}
		for (int l135 = 0; (l135 < 2); l135 = (l135 + 1)) {
			fRec169[l135] = 0.0;
			
		}
		for (int l136 = 0; (l136 < 2); l136 = (l136 + 1)) {
			fRec168[l136] = 0.0;
			
		}
		for (int l137 = 0; (l137 < 2); l137 = (l137 + 1)) {
			fRec166[l137] = 0.0;
			
		}
		for (int l138 = 0; (l138 < 2); l138 = (l138 + 1)) {
			fRec165[l138] = 0.0;
			
		}
		for (int l139 = 0; (l139 < 2); l139 = (l139 + 1)) {
			fRec163[l139] = 0.0;
			
		}
		for (int l140 = 0; (l140 < 2); l140 = (l140 + 1)) {
			fRec183[l140] = 0.0;
			
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fRec181[l141] = 0.0;
			
		}
		for (int l142 = 0; (l142 < 2); l142 = (l142 + 1)) {
			fRec180[l142] = 0.0;
			
		}
		for (int l143 = 0; (l143 < 2); l143 = (l143 + 1)) {
			fRec178[l143] = 0.0;
			
		}
		for (int l144 = 0; (l144 < 2); l144 = (l144 + 1)) {
			fRec177[l144] = 0.0;
			
		}
		for (int l145 = 0; (l145 < 2); l145 = (l145 + 1)) {
			fRec175[l145] = 0.0;
			
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fRec186[l146] = 0.0;
			
		}
		for (int l147 = 0; (l147 < 2); l147 = (l147 + 1)) {
			fRec184[l147] = 0.0;
			
		}
		for (int l148 = 0; (l148 < 2); l148 = (l148 + 1)) {
			fRec192[l148] = 0.0;
			
		}
		for (int l149 = 0; (l149 < 2); l149 = (l149 + 1)) {
			fRec190[l149] = 0.0;
			
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec189[l150] = 0.0;
			
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec187[l151] = 0.0;
			
		}
		for (int l152 = 0; (l152 < 128); l152 = (l152 + 1)) {
			fVec1[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec210[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec208[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec207[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec205[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec204[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec202[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec201[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec199[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec198[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 2); l162 = (l162 + 1)) {
			fRec196[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			fRec195[l163] = 0.0;
			
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			fRec193[l164] = 0.0;
			
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec225[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec223[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fRec222[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec220[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec219[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec217[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fRec216[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec214[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fRec213[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec211[l174] = 0.0;
			
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
			fRec237[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec235[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fRec243[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec241[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec240[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fRec238[l186] = 0.0;
			
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
		for (int l195 = 0; (l195 < 128); l195 = (l195 + 1)) {
			fVec2[l195] = 0.0;
			
		}
		for (int l196 = 0; (l196 < 2); l196 = (l196 + 1)) {
			fRec273[l196] = 0.0;
			
		}
		for (int l197 = 0; (l197 < 2); l197 = (l197 + 1)) {
			fRec271[l197] = 0.0;
			
		}
		for (int l198 = 0; (l198 < 2); l198 = (l198 + 1)) {
			fRec270[l198] = 0.0;
			
		}
		for (int l199 = 0; (l199 < 2); l199 = (l199 + 1)) {
			fRec268[l199] = 0.0;
			
		}
		for (int l200 = 0; (l200 < 2); l200 = (l200 + 1)) {
			fRec267[l200] = 0.0;
			
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fRec265[l201] = 0.0;
			
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec264[l202] = 0.0;
			
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fRec262[l203] = 0.0;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec261[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec259[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec258[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec256[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec288[l208] = 0.0;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec286[l209] = 0.0;
			
		}
		for (int l210 = 0; (l210 < 2); l210 = (l210 + 1)) {
			fRec285[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 2); l211 = (l211 + 1)) {
			fRec283[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec282[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec280[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fRec279[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 2); l215 = (l215 + 1)) {
			fRec277[l215] = 0.0;
			
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fRec276[l216] = 0.0;
			
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec274[l217] = 0.0;
			
		}
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fRec300[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec298[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fRec297[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec295[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec294[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec292[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 2); l224 = (l224 + 1)) {
			fRec291[l224] = 0.0;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec289[l225] = 0.0;
			
		}
		for (int l226 = 0; (l226 < 2); l226 = (l226 + 1)) {
			fRec309[l226] = 0.0;
			
		}
		for (int l227 = 0; (l227 < 2); l227 = (l227 + 1)) {
			fRec307[l227] = 0.0;
			
		}
		for (int l228 = 0; (l228 < 2); l228 = (l228 + 1)) {
			fRec306[l228] = 0.0;
			
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fRec304[l229] = 0.0;
			
		}
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec303[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fRec301[l231] = 0.0;
			
		}
		for (int l232 = 0; (l232 < 2); l232 = (l232 + 1)) {
			fRec312[l232] = 0.0;
			
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fRec310[l233] = 0.0;
			
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec318[l234] = 0.0;
			
		}
		for (int l235 = 0; (l235 < 2); l235 = (l235 + 1)) {
			fRec316[l235] = 0.0;
			
		}
		for (int l236 = 0; (l236 < 2); l236 = (l236 + 1)) {
			fRec315[l236] = 0.0;
			
		}
		for (int l237 = 0; (l237 < 2); l237 = (l237 + 1)) {
			fRec313[l237] = 0.0;
			
		}
		for (int l238 = 0; (l238 < 128); l238 = (l238 + 1)) {
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
			fRec351[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 2); l252 = (l252 + 1)) {
			fRec349[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec348[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec346[l254] = 0.0;
			
		}
		for (int l255 = 0; (l255 < 2); l255 = (l255 + 1)) {
			fRec345[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec343[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fRec342[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec340[l258] = 0.0;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec339[l259] = 0.0;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec337[l260] = 0.0;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec363[l261] = 0.0;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec361[l262] = 0.0;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec360[l263] = 0.0;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec358[l264] = 0.0;
			
		}
		for (int l265 = 0; (l265 < 2); l265 = (l265 + 1)) {
			fRec357[l265] = 0.0;
			
		}
		for (int l266 = 0; (l266 < 2); l266 = (l266 + 1)) {
			fRec355[l266] = 0.0;
			
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec354[l267] = 0.0;
			
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec352[l268] = 0.0;
			
		}
		for (int l269 = 0; (l269 < 2); l269 = (l269 + 1)) {
			fRec372[l269] = 0.0;
			
		}
		for (int l270 = 0; (l270 < 2); l270 = (l270 + 1)) {
			fRec370[l270] = 0.0;
			
		}
		for (int l271 = 0; (l271 < 2); l271 = (l271 + 1)) {
			fRec369[l271] = 0.0;
			
		}
		for (int l272 = 0; (l272 < 2); l272 = (l272 + 1)) {
			fRec367[l272] = 0.0;
			
		}
		for (int l273 = 0; (l273 < 2); l273 = (l273 + 1)) {
			fRec366[l273] = 0.0;
			
		}
		for (int l274 = 0; (l274 < 2); l274 = (l274 + 1)) {
			fRec364[l274] = 0.0;
			
		}
		for (int l275 = 0; (l275 < 2); l275 = (l275 + 1)) {
			fRec375[l275] = 0.0;
			
		}
		for (int l276 = 0; (l276 < 2); l276 = (l276 + 1)) {
			fRec373[l276] = 0.0;
			
		}
		for (int l277 = 0; (l277 < 2); l277 = (l277 + 1)) {
			fRec381[l277] = 0.0;
			
		}
		for (int l278 = 0; (l278 < 2); l278 = (l278 + 1)) {
			fRec379[l278] = 0.0;
			
		}
		for (int l279 = 0; (l279 < 2); l279 = (l279 + 1)) {
			fRec378[l279] = 0.0;
			
		}
		for (int l280 = 0; (l280 < 2); l280 = (l280 + 1)) {
			fRec376[l280] = 0.0;
			
		}
		for (int l281 = 0; (l281 < 128); l281 = (l281 + 1)) {
			fVec4[l281] = 0.0;
			
		}
		for (int l282 = 0; (l282 < 2); l282 = (l282 + 1)) {
			fRec399[l282] = 0.0;
			
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec397[l283] = 0.0;
			
		}
		for (int l284 = 0; (l284 < 2); l284 = (l284 + 1)) {
			fRec396[l284] = 0.0;
			
		}
		for (int l285 = 0; (l285 < 2); l285 = (l285 + 1)) {
			fRec394[l285] = 0.0;
			
		}
		for (int l286 = 0; (l286 < 2); l286 = (l286 + 1)) {
			fRec393[l286] = 0.0;
			
		}
		for (int l287 = 0; (l287 < 2); l287 = (l287 + 1)) {
			fRec391[l287] = 0.0;
			
		}
		for (int l288 = 0; (l288 < 2); l288 = (l288 + 1)) {
			fRec390[l288] = 0.0;
			
		}
		for (int l289 = 0; (l289 < 2); l289 = (l289 + 1)) {
			fRec388[l289] = 0.0;
			
		}
		for (int l290 = 0; (l290 < 2); l290 = (l290 + 1)) {
			fRec387[l290] = 0.0;
			
		}
		for (int l291 = 0; (l291 < 2); l291 = (l291 + 1)) {
			fRec385[l291] = 0.0;
			
		}
		for (int l292 = 0; (l292 < 2); l292 = (l292 + 1)) {
			fRec384[l292] = 0.0;
			
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec382[l293] = 0.0;
			
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec414[l294] = 0.0;
			
		}
		for (int l295 = 0; (l295 < 2); l295 = (l295 + 1)) {
			fRec412[l295] = 0.0;
			
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec411[l296] = 0.0;
			
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec409[l297] = 0.0;
			
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec408[l298] = 0.0;
			
		}
		for (int l299 = 0; (l299 < 2); l299 = (l299 + 1)) {
			fRec406[l299] = 0.0;
			
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec405[l300] = 0.0;
			
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec403[l301] = 0.0;
			
		}
		for (int l302 = 0; (l302 < 2); l302 = (l302 + 1)) {
			fRec402[l302] = 0.0;
			
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec400[l303] = 0.0;
			
		}
		for (int l304 = 0; (l304 < 2); l304 = (l304 + 1)) {
			fRec426[l304] = 0.0;
			
		}
		for (int l305 = 0; (l305 < 2); l305 = (l305 + 1)) {
			fRec424[l305] = 0.0;
			
		}
		for (int l306 = 0; (l306 < 2); l306 = (l306 + 1)) {
			fRec423[l306] = 0.0;
			
		}
		for (int l307 = 0; (l307 < 2); l307 = (l307 + 1)) {
			fRec421[l307] = 0.0;
			
		}
		for (int l308 = 0; (l308 < 2); l308 = (l308 + 1)) {
			fRec420[l308] = 0.0;
			
		}
		for (int l309 = 0; (l309 < 2); l309 = (l309 + 1)) {
			fRec418[l309] = 0.0;
			
		}
		for (int l310 = 0; (l310 < 2); l310 = (l310 + 1)) {
			fRec417[l310] = 0.0;
			
		}
		for (int l311 = 0; (l311 < 2); l311 = (l311 + 1)) {
			fRec415[l311] = 0.0;
			
		}
		for (int l312 = 0; (l312 < 2); l312 = (l312 + 1)) {
			fRec435[l312] = 0.0;
			
		}
		for (int l313 = 0; (l313 < 2); l313 = (l313 + 1)) {
			fRec433[l313] = 0.0;
			
		}
		for (int l314 = 0; (l314 < 2); l314 = (l314 + 1)) {
			fRec432[l314] = 0.0;
			
		}
		for (int l315 = 0; (l315 < 2); l315 = (l315 + 1)) {
			fRec430[l315] = 0.0;
			
		}
		for (int l316 = 0; (l316 < 2); l316 = (l316 + 1)) {
			fRec429[l316] = 0.0;
			
		}
		for (int l317 = 0; (l317 < 2); l317 = (l317 + 1)) {
			fRec427[l317] = 0.0;
			
		}
		for (int l318 = 0; (l318 < 2); l318 = (l318 + 1)) {
			fRec438[l318] = 0.0;
			
		}
		for (int l319 = 0; (l319 < 2); l319 = (l319 + 1)) {
			fRec436[l319] = 0.0;
			
		}
		for (int l320 = 0; (l320 < 2); l320 = (l320 + 1)) {
			fRec444[l320] = 0.0;
			
		}
		for (int l321 = 0; (l321 < 2); l321 = (l321 + 1)) {
			fRec442[l321] = 0.0;
			
		}
		for (int l322 = 0; (l322 < 2); l322 = (l322 + 1)) {
			fRec441[l322] = 0.0;
			
		}
		for (int l323 = 0; (l323 < 2); l323 = (l323 + 1)) {
			fRec439[l323] = 0.0;
			
		}
		for (int l324 = 0; (l324 < 128); l324 = (l324 + 1)) {
			fVec5[l324] = 0.0;
			
		}
		for (int l325 = 0; (l325 < 2); l325 = (l325 + 1)) {
			fRec462[l325] = 0.0;
			
		}
		for (int l326 = 0; (l326 < 2); l326 = (l326 + 1)) {
			fRec460[l326] = 0.0;
			
		}
		for (int l327 = 0; (l327 < 2); l327 = (l327 + 1)) {
			fRec459[l327] = 0.0;
			
		}
		for (int l328 = 0; (l328 < 2); l328 = (l328 + 1)) {
			fRec457[l328] = 0.0;
			
		}
		for (int l329 = 0; (l329 < 2); l329 = (l329 + 1)) {
			fRec456[l329] = 0.0;
			
		}
		for (int l330 = 0; (l330 < 2); l330 = (l330 + 1)) {
			fRec454[l330] = 0.0;
			
		}
		for (int l331 = 0; (l331 < 2); l331 = (l331 + 1)) {
			fRec453[l331] = 0.0;
			
		}
		for (int l332 = 0; (l332 < 2); l332 = (l332 + 1)) {
			fRec451[l332] = 0.0;
			
		}
		for (int l333 = 0; (l333 < 2); l333 = (l333 + 1)) {
			fRec450[l333] = 0.0;
			
		}
		for (int l334 = 0; (l334 < 2); l334 = (l334 + 1)) {
			fRec448[l334] = 0.0;
			
		}
		for (int l335 = 0; (l335 < 2); l335 = (l335 + 1)) {
			fRec447[l335] = 0.0;
			
		}
		for (int l336 = 0; (l336 < 2); l336 = (l336 + 1)) {
			fRec445[l336] = 0.0;
			
		}
		for (int l337 = 0; (l337 < 2); l337 = (l337 + 1)) {
			fRec477[l337] = 0.0;
			
		}
		for (int l338 = 0; (l338 < 2); l338 = (l338 + 1)) {
			fRec475[l338] = 0.0;
			
		}
		for (int l339 = 0; (l339 < 2); l339 = (l339 + 1)) {
			fRec474[l339] = 0.0;
			
		}
		for (int l340 = 0; (l340 < 2); l340 = (l340 + 1)) {
			fRec472[l340] = 0.0;
			
		}
		for (int l341 = 0; (l341 < 2); l341 = (l341 + 1)) {
			fRec471[l341] = 0.0;
			
		}
		for (int l342 = 0; (l342 < 2); l342 = (l342 + 1)) {
			fRec469[l342] = 0.0;
			
		}
		for (int l343 = 0; (l343 < 2); l343 = (l343 + 1)) {
			fRec468[l343] = 0.0;
			
		}
		for (int l344 = 0; (l344 < 2); l344 = (l344 + 1)) {
			fRec466[l344] = 0.0;
			
		}
		for (int l345 = 0; (l345 < 2); l345 = (l345 + 1)) {
			fRec465[l345] = 0.0;
			
		}
		for (int l346 = 0; (l346 < 2); l346 = (l346 + 1)) {
			fRec463[l346] = 0.0;
			
		}
		for (int l347 = 0; (l347 < 2); l347 = (l347 + 1)) {
			fRec489[l347] = 0.0;
			
		}
		for (int l348 = 0; (l348 < 2); l348 = (l348 + 1)) {
			fRec487[l348] = 0.0;
			
		}
		for (int l349 = 0; (l349 < 2); l349 = (l349 + 1)) {
			fRec486[l349] = 0.0;
			
		}
		for (int l350 = 0; (l350 < 2); l350 = (l350 + 1)) {
			fRec484[l350] = 0.0;
			
		}
		for (int l351 = 0; (l351 < 2); l351 = (l351 + 1)) {
			fRec483[l351] = 0.0;
			
		}
		for (int l352 = 0; (l352 < 2); l352 = (l352 + 1)) {
			fRec481[l352] = 0.0;
			
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec480[l353] = 0.0;
			
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec478[l354] = 0.0;
			
		}
		for (int l355 = 0; (l355 < 2); l355 = (l355 + 1)) {
			fRec498[l355] = 0.0;
			
		}
		for (int l356 = 0; (l356 < 2); l356 = (l356 + 1)) {
			fRec496[l356] = 0.0;
			
		}
		for (int l357 = 0; (l357 < 2); l357 = (l357 + 1)) {
			fRec495[l357] = 0.0;
			
		}
		for (int l358 = 0; (l358 < 2); l358 = (l358 + 1)) {
			fRec493[l358] = 0.0;
			
		}
		for (int l359 = 0; (l359 < 2); l359 = (l359 + 1)) {
			fRec492[l359] = 0.0;
			
		}
		for (int l360 = 0; (l360 < 2); l360 = (l360 + 1)) {
			fRec490[l360] = 0.0;
			
		}
		for (int l361 = 0; (l361 < 2); l361 = (l361 + 1)) {
			fRec501[l361] = 0.0;
			
		}
		for (int l362 = 0; (l362 < 2); l362 = (l362 + 1)) {
			fRec499[l362] = 0.0;
			
		}
		for (int l363 = 0; (l363 < 2); l363 = (l363 + 1)) {
			fRec507[l363] = 0.0;
			
		}
		for (int l364 = 0; (l364 < 2); l364 = (l364 + 1)) {
			fRec505[l364] = 0.0;
			
		}
		for (int l365 = 0; (l365 < 2); l365 = (l365 + 1)) {
			fRec504[l365] = 0.0;
			
		}
		for (int l366 = 0; (l366 < 2); l366 = (l366 + 1)) {
			fRec502[l366] = 0.0;
			
		}
		for (int l367 = 0; (l367 < 128); l367 = (l367 + 1)) {
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
			fRec552[l390] = 0.0;
			
		}
		for (int l391 = 0; (l391 < 2); l391 = (l391 + 1)) {
			fRec550[l391] = 0.0;
			
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
			fRec543[l396] = 0.0;
			
		}
		for (int l397 = 0; (l397 < 2); l397 = (l397 + 1)) {
			fRec541[l397] = 0.0;
			
		}
		for (int l398 = 0; (l398 < 2); l398 = (l398 + 1)) {
			fRec561[l398] = 0.0;
			
		}
		for (int l399 = 0; (l399 < 2); l399 = (l399 + 1)) {
			fRec559[l399] = 0.0;
			
		}
		for (int l400 = 0; (l400 < 2); l400 = (l400 + 1)) {
			fRec558[l400] = 0.0;
			
		}
		for (int l401 = 0; (l401 < 2); l401 = (l401 + 1)) {
			fRec556[l401] = 0.0;
			
		}
		for (int l402 = 0; (l402 < 2); l402 = (l402 + 1)) {
			fRec555[l402] = 0.0;
			
		}
		for (int l403 = 0; (l403 < 2); l403 = (l403 + 1)) {
			fRec553[l403] = 0.0;
			
		}
		for (int l404 = 0; (l404 < 2); l404 = (l404 + 1)) {
			fRec564[l404] = 0.0;
			
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec562[l405] = 0.0;
			
		}
		for (int l406 = 0; (l406 < 2); l406 = (l406 + 1)) {
			fRec570[l406] = 0.0;
			
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec568[l407] = 0.0;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec567[l408] = 0.0;
			
		}
		for (int l409 = 0; (l409 < 2); l409 = (l409 + 1)) {
			fRec565[l409] = 0.0;
			
		}
		for (int l410 = 0; (l410 < 128); l410 = (l410 + 1)) {
			fVec7[l410] = 0.0;
			
		}
		for (int l411 = 0; (l411 < 2); l411 = (l411 + 1)) {
			fRec588[l411] = 0.0;
			
		}
		for (int l412 = 0; (l412 < 2); l412 = (l412 + 1)) {
			fRec586[l412] = 0.0;
			
		}
		for (int l413 = 0; (l413 < 2); l413 = (l413 + 1)) {
			fRec585[l413] = 0.0;
			
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec583[l414] = 0.0;
			
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec582[l415] = 0.0;
			
		}
		for (int l416 = 0; (l416 < 2); l416 = (l416 + 1)) {
			fRec580[l416] = 0.0;
			
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec579[l417] = 0.0;
			
		}
		for (int l418 = 0; (l418 < 2); l418 = (l418 + 1)) {
			fRec577[l418] = 0.0;
			
		}
		for (int l419 = 0; (l419 < 2); l419 = (l419 + 1)) {
			fRec576[l419] = 0.0;
			
		}
		for (int l420 = 0; (l420 < 2); l420 = (l420 + 1)) {
			fRec574[l420] = 0.0;
			
		}
		for (int l421 = 0; (l421 < 2); l421 = (l421 + 1)) {
			fRec573[l421] = 0.0;
			
		}
		for (int l422 = 0; (l422 < 2); l422 = (l422 + 1)) {
			fRec571[l422] = 0.0;
			
		}
		for (int l423 = 0; (l423 < 2); l423 = (l423 + 1)) {
			fRec603[l423] = 0.0;
			
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec601[l424] = 0.0;
			
		}
		for (int l425 = 0; (l425 < 2); l425 = (l425 + 1)) {
			fRec600[l425] = 0.0;
			
		}
		for (int l426 = 0; (l426 < 2); l426 = (l426 + 1)) {
			fRec598[l426] = 0.0;
			
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec597[l427] = 0.0;
			
		}
		for (int l428 = 0; (l428 < 2); l428 = (l428 + 1)) {
			fRec595[l428] = 0.0;
			
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec594[l429] = 0.0;
			
		}
		for (int l430 = 0; (l430 < 2); l430 = (l430 + 1)) {
			fRec592[l430] = 0.0;
			
		}
		for (int l431 = 0; (l431 < 2); l431 = (l431 + 1)) {
			fRec591[l431] = 0.0;
			
		}
		for (int l432 = 0; (l432 < 2); l432 = (l432 + 1)) {
			fRec589[l432] = 0.0;
			
		}
		for (int l433 = 0; (l433 < 2); l433 = (l433 + 1)) {
			fRec615[l433] = 0.0;
			
		}
		for (int l434 = 0; (l434 < 2); l434 = (l434 + 1)) {
			fRec613[l434] = 0.0;
			
		}
		for (int l435 = 0; (l435 < 2); l435 = (l435 + 1)) {
			fRec612[l435] = 0.0;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec610[l436] = 0.0;
			
		}
		for (int l437 = 0; (l437 < 2); l437 = (l437 + 1)) {
			fRec609[l437] = 0.0;
			
		}
		for (int l438 = 0; (l438 < 2); l438 = (l438 + 1)) {
			fRec607[l438] = 0.0;
			
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec606[l439] = 0.0;
			
		}
		for (int l440 = 0; (l440 < 2); l440 = (l440 + 1)) {
			fRec604[l440] = 0.0;
			
		}
		for (int l441 = 0; (l441 < 2); l441 = (l441 + 1)) {
			fRec624[l441] = 0.0;
			
		}
		for (int l442 = 0; (l442 < 2); l442 = (l442 + 1)) {
			fRec622[l442] = 0.0;
			
		}
		for (int l443 = 0; (l443 < 2); l443 = (l443 + 1)) {
			fRec621[l443] = 0.0;
			
		}
		for (int l444 = 0; (l444 < 2); l444 = (l444 + 1)) {
			fRec619[l444] = 0.0;
			
		}
		for (int l445 = 0; (l445 < 2); l445 = (l445 + 1)) {
			fRec618[l445] = 0.0;
			
		}
		for (int l446 = 0; (l446 < 2); l446 = (l446 + 1)) {
			fRec616[l446] = 0.0;
			
		}
		for (int l447 = 0; (l447 < 2); l447 = (l447 + 1)) {
			fRec627[l447] = 0.0;
			
		}
		for (int l448 = 0; (l448 < 2); l448 = (l448 + 1)) {
			fRec625[l448] = 0.0;
			
		}
		for (int l449 = 0; (l449 < 2); l449 = (l449 + 1)) {
			fRec633[l449] = 0.0;
			
		}
		for (int l450 = 0; (l450 < 2); l450 = (l450 + 1)) {
			fRec631[l450] = 0.0;
			
		}
		for (int l451 = 0; (l451 < 2); l451 = (l451 + 1)) {
			fRec630[l451] = 0.0;
			
		}
		for (int l452 = 0; (l452 < 2); l452 = (l452 + 1)) {
			fRec628[l452] = 0.0;
			
		}
		for (int l453 = 0; (l453 < 128); l453 = (l453 + 1)) {
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
			fRec690[l490] = 0.0;
			
		}
		for (int l491 = 0; (l491 < 2); l491 = (l491 + 1)) {
			fRec688[l491] = 0.0;
			
		}
		for (int l492 = 0; (l492 < 2); l492 = (l492 + 1)) {
			fRec696[l492] = 0.0;
			
		}
		for (int l493 = 0; (l493 < 2); l493 = (l493 + 1)) {
			fRec694[l493] = 0.0;
			
		}
		for (int l494 = 0; (l494 < 2); l494 = (l494 + 1)) {
			fRec693[l494] = 0.0;
			
		}
		for (int l495 = 0; (l495 < 2); l495 = (l495 + 1)) {
			fRec691[l495] = 0.0;
			
		}
		for (int l496 = 0; (l496 < 128); l496 = (l496 + 1)) {
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
			fRec753[l533] = 0.0;
			
		}
		for (int l534 = 0; (l534 < 2); l534 = (l534 + 1)) {
			fRec751[l534] = 0.0;
			
		}
		for (int l535 = 0; (l535 < 2); l535 = (l535 + 1)) {
			fRec759[l535] = 0.0;
			
		}
		for (int l536 = 0; (l536 < 2); l536 = (l536 + 1)) {
			fRec757[l536] = 0.0;
			
		}
		for (int l537 = 0; (l537 < 2); l537 = (l537 + 1)) {
			fRec756[l537] = 0.0;
			
		}
		for (int l538 = 0; (l538 < 2); l538 = (l538 + 1)) {
			fRec754[l538] = 0.0;
			
		}
		for (int l539 = 0; (l539 < 128); l539 = (l539 + 1)) {
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
			fRec792[l552] = 0.0;
			
		}
		for (int l553 = 0; (l553 < 2); l553 = (l553 + 1)) {
			fRec790[l553] = 0.0;
			
		}
		for (int l554 = 0; (l554 < 2); l554 = (l554 + 1)) {
			fRec789[l554] = 0.0;
			
		}
		for (int l555 = 0; (l555 < 2); l555 = (l555 + 1)) {
			fRec787[l555] = 0.0;
			
		}
		for (int l556 = 0; (l556 < 2); l556 = (l556 + 1)) {
			fRec786[l556] = 0.0;
			
		}
		for (int l557 = 0; (l557 < 2); l557 = (l557 + 1)) {
			fRec784[l557] = 0.0;
			
		}
		for (int l558 = 0; (l558 < 2); l558 = (l558 + 1)) {
			fRec783[l558] = 0.0;
			
		}
		for (int l559 = 0; (l559 < 2); l559 = (l559 + 1)) {
			fRec781[l559] = 0.0;
			
		}
		for (int l560 = 0; (l560 < 2); l560 = (l560 + 1)) {
			fRec780[l560] = 0.0;
			
		}
		for (int l561 = 0; (l561 < 2); l561 = (l561 + 1)) {
			fRec778[l561] = 0.0;
			
		}
		for (int l562 = 0; (l562 < 2); l562 = (l562 + 1)) {
			fRec804[l562] = 0.0;
			
		}
		for (int l563 = 0; (l563 < 2); l563 = (l563 + 1)) {
			fRec802[l563] = 0.0;
			
		}
		for (int l564 = 0; (l564 < 2); l564 = (l564 + 1)) {
			fRec801[l564] = 0.0;
			
		}
		for (int l565 = 0; (l565 < 2); l565 = (l565 + 1)) {
			fRec799[l565] = 0.0;
			
		}
		for (int l566 = 0; (l566 < 2); l566 = (l566 + 1)) {
			fRec798[l566] = 0.0;
			
		}
		for (int l567 = 0; (l567 < 2); l567 = (l567 + 1)) {
			fRec796[l567] = 0.0;
			
		}
		for (int l568 = 0; (l568 < 2); l568 = (l568 + 1)) {
			fRec795[l568] = 0.0;
			
		}
		for (int l569 = 0; (l569 < 2); l569 = (l569 + 1)) {
			fRec793[l569] = 0.0;
			
		}
		for (int l570 = 0; (l570 < 2); l570 = (l570 + 1)) {
			fRec813[l570] = 0.0;
			
		}
		for (int l571 = 0; (l571 < 2); l571 = (l571 + 1)) {
			fRec811[l571] = 0.0;
			
		}
		for (int l572 = 0; (l572 < 2); l572 = (l572 + 1)) {
			fRec810[l572] = 0.0;
			
		}
		for (int l573 = 0; (l573 < 2); l573 = (l573 + 1)) {
			fRec808[l573] = 0.0;
			
		}
		for (int l574 = 0; (l574 < 2); l574 = (l574 + 1)) {
			fRec807[l574] = 0.0;
			
		}
		for (int l575 = 0; (l575 < 2); l575 = (l575 + 1)) {
			fRec805[l575] = 0.0;
			
		}
		for (int l576 = 0; (l576 < 2); l576 = (l576 + 1)) {
			fRec816[l576] = 0.0;
			
		}
		for (int l577 = 0; (l577 < 2); l577 = (l577 + 1)) {
			fRec814[l577] = 0.0;
			
		}
		for (int l578 = 0; (l578 < 2); l578 = (l578 + 1)) {
			fRec822[l578] = 0.0;
			
		}
		for (int l579 = 0; (l579 < 2); l579 = (l579 + 1)) {
			fRec820[l579] = 0.0;
			
		}
		for (int l580 = 0; (l580 < 2); l580 = (l580 + 1)) {
			fRec819[l580] = 0.0;
			
		}
		for (int l581 = 0; (l581 < 2); l581 = (l581 + 1)) {
			fRec817[l581] = 0.0;
			
		}
		for (int l582 = 0; (l582 < 128); l582 = (l582 + 1)) {
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
		for (int l625 = 0; (l625 < 128); l625 = (l625 + 1)) {
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
		for (int l668 = 0; (l668 < 128); l668 = (l668 + 1)) {
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
		for (int l711 = 0; (l711 < 128); l711 = (l711 + 1)) {
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
		for (int l754 = 0; (l754 < 128); l754 = (l754 + 1)) {
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
		for (int l797 = 0; (l797 < 128); l797 = (l797 + 1)) {
			fVec16[l797] = 0.0;
			
		}
		for (int l798 = 0; (l798 < 2); l798 = (l798 + 1)) {
			fRec1140[l798] = 0.0;
			
		}
		for (int l799 = 0; (l799 < 2); l799 = (l799 + 1)) {
			fRec1138[l799] = 0.0;
			
		}
		for (int l800 = 0; (l800 < 2); l800 = (l800 + 1)) {
			fRec1158[l800] = 0.0;
			
		}
		for (int l801 = 0; (l801 < 2); l801 = (l801 + 1)) {
			fRec1156[l801] = 0.0;
			
		}
		for (int l802 = 0; (l802 < 2); l802 = (l802 + 1)) {
			fRec1155[l802] = 0.0;
			
		}
		for (int l803 = 0; (l803 < 2); l803 = (l803 + 1)) {
			fRec1153[l803] = 0.0;
			
		}
		for (int l804 = 0; (l804 < 2); l804 = (l804 + 1)) {
			fRec1152[l804] = 0.0;
			
		}
		for (int l805 = 0; (l805 < 2); l805 = (l805 + 1)) {
			fRec1150[l805] = 0.0;
			
		}
		for (int l806 = 0; (l806 < 2); l806 = (l806 + 1)) {
			fRec1149[l806] = 0.0;
			
		}
		for (int l807 = 0; (l807 < 2); l807 = (l807 + 1)) {
			fRec1147[l807] = 0.0;
			
		}
		for (int l808 = 0; (l808 < 2); l808 = (l808 + 1)) {
			fRec1146[l808] = 0.0;
			
		}
		for (int l809 = 0; (l809 < 2); l809 = (l809 + 1)) {
			fRec1144[l809] = 0.0;
			
		}
		for (int l810 = 0; (l810 < 2); l810 = (l810 + 1)) {
			fRec1143[l810] = 0.0;
			
		}
		for (int l811 = 0; (l811 < 2); l811 = (l811 + 1)) {
			fRec1141[l811] = 0.0;
			
		}
		for (int l812 = 0; (l812 < 2); l812 = (l812 + 1)) {
			fRec1173[l812] = 0.0;
			
		}
		for (int l813 = 0; (l813 < 2); l813 = (l813 + 1)) {
			fRec1171[l813] = 0.0;
			
		}
		for (int l814 = 0; (l814 < 2); l814 = (l814 + 1)) {
			fRec1170[l814] = 0.0;
			
		}
		for (int l815 = 0; (l815 < 2); l815 = (l815 + 1)) {
			fRec1168[l815] = 0.0;
			
		}
		for (int l816 = 0; (l816 < 2); l816 = (l816 + 1)) {
			fRec1167[l816] = 0.0;
			
		}
		for (int l817 = 0; (l817 < 2); l817 = (l817 + 1)) {
			fRec1165[l817] = 0.0;
			
		}
		for (int l818 = 0; (l818 < 2); l818 = (l818 + 1)) {
			fRec1164[l818] = 0.0;
			
		}
		for (int l819 = 0; (l819 < 2); l819 = (l819 + 1)) {
			fRec1162[l819] = 0.0;
			
		}
		for (int l820 = 0; (l820 < 2); l820 = (l820 + 1)) {
			fRec1161[l820] = 0.0;
			
		}
		for (int l821 = 0; (l821 < 2); l821 = (l821 + 1)) {
			fRec1159[l821] = 0.0;
			
		}
		for (int l822 = 0; (l822 < 2); l822 = (l822 + 1)) {
			fRec1185[l822] = 0.0;
			
		}
		for (int l823 = 0; (l823 < 2); l823 = (l823 + 1)) {
			fRec1183[l823] = 0.0;
			
		}
		for (int l824 = 0; (l824 < 2); l824 = (l824 + 1)) {
			fRec1182[l824] = 0.0;
			
		}
		for (int l825 = 0; (l825 < 2); l825 = (l825 + 1)) {
			fRec1180[l825] = 0.0;
			
		}
		for (int l826 = 0; (l826 < 2); l826 = (l826 + 1)) {
			fRec1179[l826] = 0.0;
			
		}
		for (int l827 = 0; (l827 < 2); l827 = (l827 + 1)) {
			fRec1177[l827] = 0.0;
			
		}
		for (int l828 = 0; (l828 < 2); l828 = (l828 + 1)) {
			fRec1176[l828] = 0.0;
			
		}
		for (int l829 = 0; (l829 < 2); l829 = (l829 + 1)) {
			fRec1174[l829] = 0.0;
			
		}
		for (int l830 = 0; (l830 < 2); l830 = (l830 + 1)) {
			fRec1191[l830] = 0.0;
			
		}
		for (int l831 = 0; (l831 < 2); l831 = (l831 + 1)) {
			fRec1189[l831] = 0.0;
			
		}
		for (int l832 = 0; (l832 < 2); l832 = (l832 + 1)) {
			fRec1188[l832] = 0.0;
			
		}
		for (int l833 = 0; (l833 < 2); l833 = (l833 + 1)) {
			fRec1186[l833] = 0.0;
			
		}
		for (int l834 = 0; (l834 < 2); l834 = (l834 + 1)) {
			fRec1200[l834] = 0.0;
			
		}
		for (int l835 = 0; (l835 < 2); l835 = (l835 + 1)) {
			fRec1198[l835] = 0.0;
			
		}
		for (int l836 = 0; (l836 < 2); l836 = (l836 + 1)) {
			fRec1197[l836] = 0.0;
			
		}
		for (int l837 = 0; (l837 < 2); l837 = (l837 + 1)) {
			fRec1195[l837] = 0.0;
			
		}
		for (int l838 = 0; (l838 < 2); l838 = (l838 + 1)) {
			fRec1194[l838] = 0.0;
			
		}
		for (int l839 = 0; (l839 < 2); l839 = (l839 + 1)) {
			fRec1192[l839] = 0.0;
			
		}
		for (int l840 = 0; (l840 < 128); l840 = (l840 + 1)) {
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
		for (int l883 = 0; (l883 < 128); l883 = (l883 + 1)) {
			fVec18[l883] = 0.0;
			
		}
		for (int l884 = 0; (l884 < 2); l884 = (l884 + 1)) {
			fRec1281[l884] = 0.0;
			
		}
		for (int l885 = 0; (l885 < 2); l885 = (l885 + 1)) {
			fRec1279[l885] = 0.0;
			
		}
		for (int l886 = 0; (l886 < 2); l886 = (l886 + 1)) {
			fRec1278[l886] = 0.0;
			
		}
		for (int l887 = 0; (l887 < 2); l887 = (l887 + 1)) {
			fRec1276[l887] = 0.0;
			
		}
		for (int l888 = 0; (l888 < 2); l888 = (l888 + 1)) {
			fRec1275[l888] = 0.0;
			
		}
		for (int l889 = 0; (l889 < 2); l889 = (l889 + 1)) {
			fRec1273[l889] = 0.0;
			
		}
		for (int l890 = 0; (l890 < 2); l890 = (l890 + 1)) {
			fRec1272[l890] = 0.0;
			
		}
		for (int l891 = 0; (l891 < 2); l891 = (l891 + 1)) {
			fRec1270[l891] = 0.0;
			
		}
		for (int l892 = 0; (l892 < 2); l892 = (l892 + 1)) {
			fRec1269[l892] = 0.0;
			
		}
		for (int l893 = 0; (l893 < 2); l893 = (l893 + 1)) {
			fRec1267[l893] = 0.0;
			
		}
		for (int l894 = 0; (l894 < 2); l894 = (l894 + 1)) {
			fRec1266[l894] = 0.0;
			
		}
		for (int l895 = 0; (l895 < 2); l895 = (l895 + 1)) {
			fRec1264[l895] = 0.0;
			
		}
		for (int l896 = 0; (l896 < 2); l896 = (l896 + 1)) {
			fRec1296[l896] = 0.0;
			
		}
		for (int l897 = 0; (l897 < 2); l897 = (l897 + 1)) {
			fRec1294[l897] = 0.0;
			
		}
		for (int l898 = 0; (l898 < 2); l898 = (l898 + 1)) {
			fRec1293[l898] = 0.0;
			
		}
		for (int l899 = 0; (l899 < 2); l899 = (l899 + 1)) {
			fRec1291[l899] = 0.0;
			
		}
		for (int l900 = 0; (l900 < 2); l900 = (l900 + 1)) {
			fRec1290[l900] = 0.0;
			
		}
		for (int l901 = 0; (l901 < 2); l901 = (l901 + 1)) {
			fRec1288[l901] = 0.0;
			
		}
		for (int l902 = 0; (l902 < 2); l902 = (l902 + 1)) {
			fRec1287[l902] = 0.0;
			
		}
		for (int l903 = 0; (l903 < 2); l903 = (l903 + 1)) {
			fRec1285[l903] = 0.0;
			
		}
		for (int l904 = 0; (l904 < 2); l904 = (l904 + 1)) {
			fRec1284[l904] = 0.0;
			
		}
		for (int l905 = 0; (l905 < 2); l905 = (l905 + 1)) {
			fRec1282[l905] = 0.0;
			
		}
		for (int l906 = 0; (l906 < 2); l906 = (l906 + 1)) {
			fRec1308[l906] = 0.0;
			
		}
		for (int l907 = 0; (l907 < 2); l907 = (l907 + 1)) {
			fRec1306[l907] = 0.0;
			
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
			fRec1299[l912] = 0.0;
			
		}
		for (int l913 = 0; (l913 < 2); l913 = (l913 + 1)) {
			fRec1297[l913] = 0.0;
			
		}
		for (int l914 = 0; (l914 < 2); l914 = (l914 + 1)) {
			fRec1317[l914] = 0.0;
			
		}
		for (int l915 = 0; (l915 < 2); l915 = (l915 + 1)) {
			fRec1315[l915] = 0.0;
			
		}
		for (int l916 = 0; (l916 < 2); l916 = (l916 + 1)) {
			fRec1314[l916] = 0.0;
			
		}
		for (int l917 = 0; (l917 < 2); l917 = (l917 + 1)) {
			fRec1312[l917] = 0.0;
			
		}
		for (int l918 = 0; (l918 < 2); l918 = (l918 + 1)) {
			fRec1311[l918] = 0.0;
			
		}
		for (int l919 = 0; (l919 < 2); l919 = (l919 + 1)) {
			fRec1309[l919] = 0.0;
			
		}
		for (int l920 = 0; (l920 < 2); l920 = (l920 + 1)) {
			fRec1320[l920] = 0.0;
			
		}
		for (int l921 = 0; (l921 < 2); l921 = (l921 + 1)) {
			fRec1318[l921] = 0.0;
			
		}
		for (int l922 = 0; (l922 < 2); l922 = (l922 + 1)) {
			fRec1326[l922] = 0.0;
			
		}
		for (int l923 = 0; (l923 < 2); l923 = (l923 + 1)) {
			fRec1324[l923] = 0.0;
			
		}
		for (int l924 = 0; (l924 < 2); l924 = (l924 + 1)) {
			fRec1323[l924] = 0.0;
			
		}
		for (int l925 = 0; (l925 < 2); l925 = (l925 + 1)) {
			fRec1321[l925] = 0.0;
			
		}
		for (int l926 = 0; (l926 < 128); l926 = (l926 + 1)) {
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
		for (int l969 = 0; (l969 < 128); l969 = (l969 + 1)) {
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
		for (int l1012 = 0; (l1012 < 128); l1012 = (l1012 + 1)) {
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
		for (int l1055 = 0; (l1055 < 128); l1055 = (l1055 + 1)) {
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
		for (int l1098 = 0; (l1098 < 128); l1098 = (l1098 + 1)) {
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
			fRec1611[l1111] = 0.0;
			
		}
		for (int l1112 = 0; (l1112 < 2); l1112 = (l1112 + 1)) {
			fRec1609[l1112] = 0.0;
			
		}
		for (int l1113 = 0; (l1113 < 2); l1113 = (l1113 + 1)) {
			fRec1608[l1113] = 0.0;
			
		}
		for (int l1114 = 0; (l1114 < 2); l1114 = (l1114 + 1)) {
			fRec1606[l1114] = 0.0;
			
		}
		for (int l1115 = 0; (l1115 < 2); l1115 = (l1115 + 1)) {
			fRec1605[l1115] = 0.0;
			
		}
		for (int l1116 = 0; (l1116 < 2); l1116 = (l1116 + 1)) {
			fRec1603[l1116] = 0.0;
			
		}
		for (int l1117 = 0; (l1117 < 2); l1117 = (l1117 + 1)) {
			fRec1602[l1117] = 0.0;
			
		}
		for (int l1118 = 0; (l1118 < 2); l1118 = (l1118 + 1)) {
			fRec1600[l1118] = 0.0;
			
		}
		for (int l1119 = 0; (l1119 < 2); l1119 = (l1119 + 1)) {
			fRec1599[l1119] = 0.0;
			
		}
		for (int l1120 = 0; (l1120 < 2); l1120 = (l1120 + 1)) {
			fRec1597[l1120] = 0.0;
			
		}
		for (int l1121 = 0; (l1121 < 2); l1121 = (l1121 + 1)) {
			fRec1623[l1121] = 0.0;
			
		}
		for (int l1122 = 0; (l1122 < 2); l1122 = (l1122 + 1)) {
			fRec1621[l1122] = 0.0;
			
		}
		for (int l1123 = 0; (l1123 < 2); l1123 = (l1123 + 1)) {
			fRec1620[l1123] = 0.0;
			
		}
		for (int l1124 = 0; (l1124 < 2); l1124 = (l1124 + 1)) {
			fRec1618[l1124] = 0.0;
			
		}
		for (int l1125 = 0; (l1125 < 2); l1125 = (l1125 + 1)) {
			fRec1617[l1125] = 0.0;
			
		}
		for (int l1126 = 0; (l1126 < 2); l1126 = (l1126 + 1)) {
			fRec1615[l1126] = 0.0;
			
		}
		for (int l1127 = 0; (l1127 < 2); l1127 = (l1127 + 1)) {
			fRec1614[l1127] = 0.0;
			
		}
		for (int l1128 = 0; (l1128 < 2); l1128 = (l1128 + 1)) {
			fRec1612[l1128] = 0.0;
			
		}
		for (int l1129 = 0; (l1129 < 2); l1129 = (l1129 + 1)) {
			fRec1632[l1129] = 0.0;
			
		}
		for (int l1130 = 0; (l1130 < 2); l1130 = (l1130 + 1)) {
			fRec1630[l1130] = 0.0;
			
		}
		for (int l1131 = 0; (l1131 < 2); l1131 = (l1131 + 1)) {
			fRec1629[l1131] = 0.0;
			
		}
		for (int l1132 = 0; (l1132 < 2); l1132 = (l1132 + 1)) {
			fRec1627[l1132] = 0.0;
			
		}
		for (int l1133 = 0; (l1133 < 2); l1133 = (l1133 + 1)) {
			fRec1626[l1133] = 0.0;
			
		}
		for (int l1134 = 0; (l1134 < 2); l1134 = (l1134 + 1)) {
			fRec1624[l1134] = 0.0;
			
		}
		for (int l1135 = 0; (l1135 < 2); l1135 = (l1135 + 1)) {
			fRec1635[l1135] = 0.0;
			
		}
		for (int l1136 = 0; (l1136 < 2); l1136 = (l1136 + 1)) {
			fRec1633[l1136] = 0.0;
			
		}
		for (int l1137 = 0; (l1137 < 2); l1137 = (l1137 + 1)) {
			fRec1641[l1137] = 0.0;
			
		}
		for (int l1138 = 0; (l1138 < 2); l1138 = (l1138 + 1)) {
			fRec1639[l1138] = 0.0;
			
		}
		for (int l1139 = 0; (l1139 < 2); l1139 = (l1139 + 1)) {
			fRec1638[l1139] = 0.0;
			
		}
		for (int l1140 = 0; (l1140 < 2); l1140 = (l1140 + 1)) {
			fRec1636[l1140] = 0.0;
			
		}
		for (int l1141 = 0; (l1141 < 12); l1141 = (l1141 + 1)) {
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
		for (int l1184 = 0; (l1184 < 12); l1184 = (l1184 + 1)) {
			fVec25[l1184] = 0.0;
			
		}
		for (int l1185 = 0; (l1185 < 2); l1185 = (l1185 + 1)) {
			fRec1722[l1185] = 0.0;
			
		}
		for (int l1186 = 0; (l1186 < 2); l1186 = (l1186 + 1)) {
			fRec1720[l1186] = 0.0;
			
		}
		for (int l1187 = 0; (l1187 < 2); l1187 = (l1187 + 1)) {
			fRec1719[l1187] = 0.0;
			
		}
		for (int l1188 = 0; (l1188 < 2); l1188 = (l1188 + 1)) {
			fRec1717[l1188] = 0.0;
			
		}
		for (int l1189 = 0; (l1189 < 2); l1189 = (l1189 + 1)) {
			fRec1716[l1189] = 0.0;
			
		}
		for (int l1190 = 0; (l1190 < 2); l1190 = (l1190 + 1)) {
			fRec1714[l1190] = 0.0;
			
		}
		for (int l1191 = 0; (l1191 < 2); l1191 = (l1191 + 1)) {
			fRec1713[l1191] = 0.0;
			
		}
		for (int l1192 = 0; (l1192 < 2); l1192 = (l1192 + 1)) {
			fRec1711[l1192] = 0.0;
			
		}
		for (int l1193 = 0; (l1193 < 2); l1193 = (l1193 + 1)) {
			fRec1710[l1193] = 0.0;
			
		}
		for (int l1194 = 0; (l1194 < 2); l1194 = (l1194 + 1)) {
			fRec1708[l1194] = 0.0;
			
		}
		for (int l1195 = 0; (l1195 < 2); l1195 = (l1195 + 1)) {
			fRec1707[l1195] = 0.0;
			
		}
		for (int l1196 = 0; (l1196 < 2); l1196 = (l1196 + 1)) {
			fRec1705[l1196] = 0.0;
			
		}
		for (int l1197 = 0; (l1197 < 2); l1197 = (l1197 + 1)) {
			fRec1737[l1197] = 0.0;
			
		}
		for (int l1198 = 0; (l1198 < 2); l1198 = (l1198 + 1)) {
			fRec1735[l1198] = 0.0;
			
		}
		for (int l1199 = 0; (l1199 < 2); l1199 = (l1199 + 1)) {
			fRec1734[l1199] = 0.0;
			
		}
		for (int l1200 = 0; (l1200 < 2); l1200 = (l1200 + 1)) {
			fRec1732[l1200] = 0.0;
			
		}
		for (int l1201 = 0; (l1201 < 2); l1201 = (l1201 + 1)) {
			fRec1731[l1201] = 0.0;
			
		}
		for (int l1202 = 0; (l1202 < 2); l1202 = (l1202 + 1)) {
			fRec1729[l1202] = 0.0;
			
		}
		for (int l1203 = 0; (l1203 < 2); l1203 = (l1203 + 1)) {
			fRec1728[l1203] = 0.0;
			
		}
		for (int l1204 = 0; (l1204 < 2); l1204 = (l1204 + 1)) {
			fRec1726[l1204] = 0.0;
			
		}
		for (int l1205 = 0; (l1205 < 2); l1205 = (l1205 + 1)) {
			fRec1725[l1205] = 0.0;
			
		}
		for (int l1206 = 0; (l1206 < 2); l1206 = (l1206 + 1)) {
			fRec1723[l1206] = 0.0;
			
		}
		for (int l1207 = 0; (l1207 < 2); l1207 = (l1207 + 1)) {
			fRec1749[l1207] = 0.0;
			
		}
		for (int l1208 = 0; (l1208 < 2); l1208 = (l1208 + 1)) {
			fRec1747[l1208] = 0.0;
			
		}
		for (int l1209 = 0; (l1209 < 2); l1209 = (l1209 + 1)) {
			fRec1746[l1209] = 0.0;
			
		}
		for (int l1210 = 0; (l1210 < 2); l1210 = (l1210 + 1)) {
			fRec1744[l1210] = 0.0;
			
		}
		for (int l1211 = 0; (l1211 < 2); l1211 = (l1211 + 1)) {
			fRec1743[l1211] = 0.0;
			
		}
		for (int l1212 = 0; (l1212 < 2); l1212 = (l1212 + 1)) {
			fRec1741[l1212] = 0.0;
			
		}
		for (int l1213 = 0; (l1213 < 2); l1213 = (l1213 + 1)) {
			fRec1740[l1213] = 0.0;
			
		}
		for (int l1214 = 0; (l1214 < 2); l1214 = (l1214 + 1)) {
			fRec1738[l1214] = 0.0;
			
		}
		for (int l1215 = 0; (l1215 < 2); l1215 = (l1215 + 1)) {
			fRec1758[l1215] = 0.0;
			
		}
		for (int l1216 = 0; (l1216 < 2); l1216 = (l1216 + 1)) {
			fRec1756[l1216] = 0.0;
			
		}
		for (int l1217 = 0; (l1217 < 2); l1217 = (l1217 + 1)) {
			fRec1755[l1217] = 0.0;
			
		}
		for (int l1218 = 0; (l1218 < 2); l1218 = (l1218 + 1)) {
			fRec1753[l1218] = 0.0;
			
		}
		for (int l1219 = 0; (l1219 < 2); l1219 = (l1219 + 1)) {
			fRec1752[l1219] = 0.0;
			
		}
		for (int l1220 = 0; (l1220 < 2); l1220 = (l1220 + 1)) {
			fRec1750[l1220] = 0.0;
			
		}
		for (int l1221 = 0; (l1221 < 2); l1221 = (l1221 + 1)) {
			fRec1761[l1221] = 0.0;
			
		}
		for (int l1222 = 0; (l1222 < 2); l1222 = (l1222 + 1)) {
			fRec1759[l1222] = 0.0;
			
		}
		for (int l1223 = 0; (l1223 < 2); l1223 = (l1223 + 1)) {
			fRec1767[l1223] = 0.0;
			
		}
		for (int l1224 = 0; (l1224 < 2); l1224 = (l1224 + 1)) {
			fRec1765[l1224] = 0.0;
			
		}
		for (int l1225 = 0; (l1225 < 2); l1225 = (l1225 + 1)) {
			fRec1764[l1225] = 0.0;
			
		}
		for (int l1226 = 0; (l1226 < 2); l1226 = (l1226 + 1)) {
			fRec1762[l1226] = 0.0;
			
		}
		for (int l1227 = 0; (l1227 < 12); l1227 = (l1227 + 1)) {
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
			fRec1821[l1258] = 0.0;
			
		}
		for (int l1259 = 0; (l1259 < 2); l1259 = (l1259 + 1)) {
			fRec1819[l1259] = 0.0;
			
		}
		for (int l1260 = 0; (l1260 < 2); l1260 = (l1260 + 1)) {
			fRec1818[l1260] = 0.0;
			
		}
		for (int l1261 = 0; (l1261 < 2); l1261 = (l1261 + 1)) {
			fRec1816[l1261] = 0.0;
			
		}
		for (int l1262 = 0; (l1262 < 2); l1262 = (l1262 + 1)) {
			fRec1815[l1262] = 0.0;
			
		}
		for (int l1263 = 0; (l1263 < 2); l1263 = (l1263 + 1)) {
			fRec1813[l1263] = 0.0;
			
		}
		for (int l1264 = 0; (l1264 < 2); l1264 = (l1264 + 1)) {
			fRec1824[l1264] = 0.0;
			
		}
		for (int l1265 = 0; (l1265 < 2); l1265 = (l1265 + 1)) {
			fRec1822[l1265] = 0.0;
			
		}
		for (int l1266 = 0; (l1266 < 2); l1266 = (l1266 + 1)) {
			fRec1830[l1266] = 0.0;
			
		}
		for (int l1267 = 0; (l1267 < 2); l1267 = (l1267 + 1)) {
			fRec1828[l1267] = 0.0;
			
		}
		for (int l1268 = 0; (l1268 < 2); l1268 = (l1268 + 1)) {
			fRec1827[l1268] = 0.0;
			
		}
		for (int l1269 = 0; (l1269 < 2); l1269 = (l1269 + 1)) {
			fRec1825[l1269] = 0.0;
			
		}
		for (int l1270 = 0; (l1270 < 12); l1270 = (l1270 + 1)) {
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
		for (int l1313 = 0; (l1313 < 2); l1313 = (l1313 + 1)) {
			fRec1911[l1313] = 0.0;
			
		}
		for (int l1314 = 0; (l1314 < 2); l1314 = (l1314 + 1)) {
			fRec1909[l1314] = 0.0;
			
		}
		for (int l1315 = 0; (l1315 < 2); l1315 = (l1315 + 1)) {
			fRec1908[l1315] = 0.0;
			
		}
		for (int l1316 = 0; (l1316 < 2); l1316 = (l1316 + 1)) {
			fRec1906[l1316] = 0.0;
			
		}
		for (int l1317 = 0; (l1317 < 2); l1317 = (l1317 + 1)) {
			fRec1905[l1317] = 0.0;
			
		}
		for (int l1318 = 0; (l1318 < 2); l1318 = (l1318 + 1)) {
			fRec1903[l1318] = 0.0;
			
		}
		for (int l1319 = 0; (l1319 < 2); l1319 = (l1319 + 1)) {
			fRec1902[l1319] = 0.0;
			
		}
		for (int l1320 = 0; (l1320 < 2); l1320 = (l1320 + 1)) {
			fRec1900[l1320] = 0.0;
			
		}
		for (int l1321 = 0; (l1321 < 2); l1321 = (l1321 + 1)) {
			fRec1899[l1321] = 0.0;
			
		}
		for (int l1322 = 0; (l1322 < 2); l1322 = (l1322 + 1)) {
			fRec1897[l1322] = 0.0;
			
		}
		for (int l1323 = 0; (l1323 < 2); l1323 = (l1323 + 1)) {
			fRec1896[l1323] = 0.0;
			
		}
		for (int l1324 = 0; (l1324 < 2); l1324 = (l1324 + 1)) {
			fRec1894[l1324] = 0.0;
			
		}
		for (int l1325 = 0; (l1325 < 2); l1325 = (l1325 + 1)) {
			fRec1926[l1325] = 0.0;
			
		}
		for (int l1326 = 0; (l1326 < 2); l1326 = (l1326 + 1)) {
			fRec1924[l1326] = 0.0;
			
		}
		for (int l1327 = 0; (l1327 < 2); l1327 = (l1327 + 1)) {
			fRec1923[l1327] = 0.0;
			
		}
		for (int l1328 = 0; (l1328 < 2); l1328 = (l1328 + 1)) {
			fRec1921[l1328] = 0.0;
			
		}
		for (int l1329 = 0; (l1329 < 2); l1329 = (l1329 + 1)) {
			fRec1920[l1329] = 0.0;
			
		}
		for (int l1330 = 0; (l1330 < 2); l1330 = (l1330 + 1)) {
			fRec1918[l1330] = 0.0;
			
		}
		for (int l1331 = 0; (l1331 < 2); l1331 = (l1331 + 1)) {
			fRec1917[l1331] = 0.0;
			
		}
		for (int l1332 = 0; (l1332 < 2); l1332 = (l1332 + 1)) {
			fRec1915[l1332] = 0.0;
			
		}
		for (int l1333 = 0; (l1333 < 2); l1333 = (l1333 + 1)) {
			fRec1914[l1333] = 0.0;
			
		}
		for (int l1334 = 0; (l1334 < 2); l1334 = (l1334 + 1)) {
			fRec1912[l1334] = 0.0;
			
		}
		for (int l1335 = 0; (l1335 < 2); l1335 = (l1335 + 1)) {
			fRec1938[l1335] = 0.0;
			
		}
		for (int l1336 = 0; (l1336 < 2); l1336 = (l1336 + 1)) {
			fRec1936[l1336] = 0.0;
			
		}
		for (int l1337 = 0; (l1337 < 2); l1337 = (l1337 + 1)) {
			fRec1935[l1337] = 0.0;
			
		}
		for (int l1338 = 0; (l1338 < 2); l1338 = (l1338 + 1)) {
			fRec1933[l1338] = 0.0;
			
		}
		for (int l1339 = 0; (l1339 < 2); l1339 = (l1339 + 1)) {
			fRec1932[l1339] = 0.0;
			
		}
		for (int l1340 = 0; (l1340 < 2); l1340 = (l1340 + 1)) {
			fRec1930[l1340] = 0.0;
			
		}
		for (int l1341 = 0; (l1341 < 2); l1341 = (l1341 + 1)) {
			fRec1929[l1341] = 0.0;
			
		}
		for (int l1342 = 0; (l1342 < 2); l1342 = (l1342 + 1)) {
			fRec1927[l1342] = 0.0;
			
		}
		for (int l1343 = 0; (l1343 < 2); l1343 = (l1343 + 1)) {
			fRec1947[l1343] = 0.0;
			
		}
		for (int l1344 = 0; (l1344 < 2); l1344 = (l1344 + 1)) {
			fRec1945[l1344] = 0.0;
			
		}
		for (int l1345 = 0; (l1345 < 2); l1345 = (l1345 + 1)) {
			fRec1944[l1345] = 0.0;
			
		}
		for (int l1346 = 0; (l1346 < 2); l1346 = (l1346 + 1)) {
			fRec1942[l1346] = 0.0;
			
		}
		for (int l1347 = 0; (l1347 < 2); l1347 = (l1347 + 1)) {
			fRec1941[l1347] = 0.0;
			
		}
		for (int l1348 = 0; (l1348 < 2); l1348 = (l1348 + 1)) {
			fRec1939[l1348] = 0.0;
			
		}
		for (int l1349 = 0; (l1349 < 2); l1349 = (l1349 + 1)) {
			fRec1950[l1349] = 0.0;
			
		}
		for (int l1350 = 0; (l1350 < 2); l1350 = (l1350 + 1)) {
			fRec1948[l1350] = 0.0;
			
		}
		for (int l1351 = 0; (l1351 < 2); l1351 = (l1351 + 1)) {
			fRec1956[l1351] = 0.0;
			
		}
		for (int l1352 = 0; (l1352 < 2); l1352 = (l1352 + 1)) {
			fRec1954[l1352] = 0.0;
			
		}
		for (int l1353 = 0; (l1353 < 2); l1353 = (l1353 + 1)) {
			fRec1953[l1353] = 0.0;
			
		}
		for (int l1354 = 0; (l1354 < 2); l1354 = (l1354 + 1)) {
			fRec1951[l1354] = 0.0;
			
		}
		for (int l1355 = 0; (l1355 < 512); l1355 = (l1355 + 1)) {
			fVec28[l1355] = 0.0;
			
		}
		for (int l1356 = 0; (l1356 < 2); l1356 = (l1356 + 1)) {
			fRec1974[l1356] = 0.0;
			
		}
		for (int l1357 = 0; (l1357 < 2); l1357 = (l1357 + 1)) {
			fRec1972[l1357] = 0.0;
			
		}
		for (int l1358 = 0; (l1358 < 2); l1358 = (l1358 + 1)) {
			fRec1971[l1358] = 0.0;
			
		}
		for (int l1359 = 0; (l1359 < 2); l1359 = (l1359 + 1)) {
			fRec1969[l1359] = 0.0;
			
		}
		for (int l1360 = 0; (l1360 < 2); l1360 = (l1360 + 1)) {
			fRec1968[l1360] = 0.0;
			
		}
		for (int l1361 = 0; (l1361 < 2); l1361 = (l1361 + 1)) {
			fRec1966[l1361] = 0.0;
			
		}
		for (int l1362 = 0; (l1362 < 2); l1362 = (l1362 + 1)) {
			fRec1965[l1362] = 0.0;
			
		}
		for (int l1363 = 0; (l1363 < 2); l1363 = (l1363 + 1)) {
			fRec1963[l1363] = 0.0;
			
		}
		for (int l1364 = 0; (l1364 < 2); l1364 = (l1364 + 1)) {
			fRec1962[l1364] = 0.0;
			
		}
		for (int l1365 = 0; (l1365 < 2); l1365 = (l1365 + 1)) {
			fRec1960[l1365] = 0.0;
			
		}
		for (int l1366 = 0; (l1366 < 2); l1366 = (l1366 + 1)) {
			fRec1959[l1366] = 0.0;
			
		}
		for (int l1367 = 0; (l1367 < 2); l1367 = (l1367 + 1)) {
			fRec1957[l1367] = 0.0;
			
		}
		for (int l1368 = 0; (l1368 < 2); l1368 = (l1368 + 1)) {
			fRec1989[l1368] = 0.0;
			
		}
		for (int l1369 = 0; (l1369 < 2); l1369 = (l1369 + 1)) {
			fRec1987[l1369] = 0.0;
			
		}
		for (int l1370 = 0; (l1370 < 2); l1370 = (l1370 + 1)) {
			fRec1986[l1370] = 0.0;
			
		}
		for (int l1371 = 0; (l1371 < 2); l1371 = (l1371 + 1)) {
			fRec1984[l1371] = 0.0;
			
		}
		for (int l1372 = 0; (l1372 < 2); l1372 = (l1372 + 1)) {
			fRec1983[l1372] = 0.0;
			
		}
		for (int l1373 = 0; (l1373 < 2); l1373 = (l1373 + 1)) {
			fRec1981[l1373] = 0.0;
			
		}
		for (int l1374 = 0; (l1374 < 2); l1374 = (l1374 + 1)) {
			fRec1980[l1374] = 0.0;
			
		}
		for (int l1375 = 0; (l1375 < 2); l1375 = (l1375 + 1)) {
			fRec1978[l1375] = 0.0;
			
		}
		for (int l1376 = 0; (l1376 < 2); l1376 = (l1376 + 1)) {
			fRec1977[l1376] = 0.0;
			
		}
		for (int l1377 = 0; (l1377 < 2); l1377 = (l1377 + 1)) {
			fRec1975[l1377] = 0.0;
			
		}
		for (int l1378 = 0; (l1378 < 2); l1378 = (l1378 + 1)) {
			fRec2001[l1378] = 0.0;
			
		}
		for (int l1379 = 0; (l1379 < 2); l1379 = (l1379 + 1)) {
			fRec1999[l1379] = 0.0;
			
		}
		for (int l1380 = 0; (l1380 < 2); l1380 = (l1380 + 1)) {
			fRec1998[l1380] = 0.0;
			
		}
		for (int l1381 = 0; (l1381 < 2); l1381 = (l1381 + 1)) {
			fRec1996[l1381] = 0.0;
			
		}
		for (int l1382 = 0; (l1382 < 2); l1382 = (l1382 + 1)) {
			fRec1995[l1382] = 0.0;
			
		}
		for (int l1383 = 0; (l1383 < 2); l1383 = (l1383 + 1)) {
			fRec1993[l1383] = 0.0;
			
		}
		for (int l1384 = 0; (l1384 < 2); l1384 = (l1384 + 1)) {
			fRec1992[l1384] = 0.0;
			
		}
		for (int l1385 = 0; (l1385 < 2); l1385 = (l1385 + 1)) {
			fRec1990[l1385] = 0.0;
			
		}
		for (int l1386 = 0; (l1386 < 2); l1386 = (l1386 + 1)) {
			fRec2010[l1386] = 0.0;
			
		}
		for (int l1387 = 0; (l1387 < 2); l1387 = (l1387 + 1)) {
			fRec2008[l1387] = 0.0;
			
		}
		for (int l1388 = 0; (l1388 < 2); l1388 = (l1388 + 1)) {
			fRec2007[l1388] = 0.0;
			
		}
		for (int l1389 = 0; (l1389 < 2); l1389 = (l1389 + 1)) {
			fRec2005[l1389] = 0.0;
			
		}
		for (int l1390 = 0; (l1390 < 2); l1390 = (l1390 + 1)) {
			fRec2004[l1390] = 0.0;
			
		}
		for (int l1391 = 0; (l1391 < 2); l1391 = (l1391 + 1)) {
			fRec2002[l1391] = 0.0;
			
		}
		for (int l1392 = 0; (l1392 < 2); l1392 = (l1392 + 1)) {
			fRec2013[l1392] = 0.0;
			
		}
		for (int l1393 = 0; (l1393 < 2); l1393 = (l1393 + 1)) {
			fRec2011[l1393] = 0.0;
			
		}
		for (int l1394 = 0; (l1394 < 2); l1394 = (l1394 + 1)) {
			fRec2019[l1394] = 0.0;
			
		}
		for (int l1395 = 0; (l1395 < 2); l1395 = (l1395 + 1)) {
			fRec2017[l1395] = 0.0;
			
		}
		for (int l1396 = 0; (l1396 < 2); l1396 = (l1396 + 1)) {
			fRec2016[l1396] = 0.0;
			
		}
		for (int l1397 = 0; (l1397 < 2); l1397 = (l1397 + 1)) {
			fRec2014[l1397] = 0.0;
			
		}
		for (int l1398 = 0; (l1398 < 512); l1398 = (l1398 + 1)) {
			fVec29[l1398] = 0.0;
			
		}
		for (int l1399 = 0; (l1399 < 2); l1399 = (l1399 + 1)) {
			fRec2037[l1399] = 0.0;
			
		}
		for (int l1400 = 0; (l1400 < 2); l1400 = (l1400 + 1)) {
			fRec2035[l1400] = 0.0;
			
		}
		for (int l1401 = 0; (l1401 < 2); l1401 = (l1401 + 1)) {
			fRec2034[l1401] = 0.0;
			
		}
		for (int l1402 = 0; (l1402 < 2); l1402 = (l1402 + 1)) {
			fRec2032[l1402] = 0.0;
			
		}
		for (int l1403 = 0; (l1403 < 2); l1403 = (l1403 + 1)) {
			fRec2031[l1403] = 0.0;
			
		}
		for (int l1404 = 0; (l1404 < 2); l1404 = (l1404 + 1)) {
			fRec2029[l1404] = 0.0;
			
		}
		for (int l1405 = 0; (l1405 < 2); l1405 = (l1405 + 1)) {
			fRec2028[l1405] = 0.0;
			
		}
		for (int l1406 = 0; (l1406 < 2); l1406 = (l1406 + 1)) {
			fRec2026[l1406] = 0.0;
			
		}
		for (int l1407 = 0; (l1407 < 2); l1407 = (l1407 + 1)) {
			fRec2025[l1407] = 0.0;
			
		}
		for (int l1408 = 0; (l1408 < 2); l1408 = (l1408 + 1)) {
			fRec2023[l1408] = 0.0;
			
		}
		for (int l1409 = 0; (l1409 < 2); l1409 = (l1409 + 1)) {
			fRec2022[l1409] = 0.0;
			
		}
		for (int l1410 = 0; (l1410 < 2); l1410 = (l1410 + 1)) {
			fRec2020[l1410] = 0.0;
			
		}
		for (int l1411 = 0; (l1411 < 2); l1411 = (l1411 + 1)) {
			fRec2052[l1411] = 0.0;
			
		}
		for (int l1412 = 0; (l1412 < 2); l1412 = (l1412 + 1)) {
			fRec2050[l1412] = 0.0;
			
		}
		for (int l1413 = 0; (l1413 < 2); l1413 = (l1413 + 1)) {
			fRec2049[l1413] = 0.0;
			
		}
		for (int l1414 = 0; (l1414 < 2); l1414 = (l1414 + 1)) {
			fRec2047[l1414] = 0.0;
			
		}
		for (int l1415 = 0; (l1415 < 2); l1415 = (l1415 + 1)) {
			fRec2046[l1415] = 0.0;
			
		}
		for (int l1416 = 0; (l1416 < 2); l1416 = (l1416 + 1)) {
			fRec2044[l1416] = 0.0;
			
		}
		for (int l1417 = 0; (l1417 < 2); l1417 = (l1417 + 1)) {
			fRec2043[l1417] = 0.0;
			
		}
		for (int l1418 = 0; (l1418 < 2); l1418 = (l1418 + 1)) {
			fRec2041[l1418] = 0.0;
			
		}
		for (int l1419 = 0; (l1419 < 2); l1419 = (l1419 + 1)) {
			fRec2040[l1419] = 0.0;
			
		}
		for (int l1420 = 0; (l1420 < 2); l1420 = (l1420 + 1)) {
			fRec2038[l1420] = 0.0;
			
		}
		for (int l1421 = 0; (l1421 < 2); l1421 = (l1421 + 1)) {
			fRec2064[l1421] = 0.0;
			
		}
		for (int l1422 = 0; (l1422 < 2); l1422 = (l1422 + 1)) {
			fRec2062[l1422] = 0.0;
			
		}
		for (int l1423 = 0; (l1423 < 2); l1423 = (l1423 + 1)) {
			fRec2061[l1423] = 0.0;
			
		}
		for (int l1424 = 0; (l1424 < 2); l1424 = (l1424 + 1)) {
			fRec2059[l1424] = 0.0;
			
		}
		for (int l1425 = 0; (l1425 < 2); l1425 = (l1425 + 1)) {
			fRec2058[l1425] = 0.0;
			
		}
		for (int l1426 = 0; (l1426 < 2); l1426 = (l1426 + 1)) {
			fRec2056[l1426] = 0.0;
			
		}
		for (int l1427 = 0; (l1427 < 2); l1427 = (l1427 + 1)) {
			fRec2055[l1427] = 0.0;
			
		}
		for (int l1428 = 0; (l1428 < 2); l1428 = (l1428 + 1)) {
			fRec2053[l1428] = 0.0;
			
		}
		for (int l1429 = 0; (l1429 < 2); l1429 = (l1429 + 1)) {
			fRec2073[l1429] = 0.0;
			
		}
		for (int l1430 = 0; (l1430 < 2); l1430 = (l1430 + 1)) {
			fRec2071[l1430] = 0.0;
			
		}
		for (int l1431 = 0; (l1431 < 2); l1431 = (l1431 + 1)) {
			fRec2070[l1431] = 0.0;
			
		}
		for (int l1432 = 0; (l1432 < 2); l1432 = (l1432 + 1)) {
			fRec2068[l1432] = 0.0;
			
		}
		for (int l1433 = 0; (l1433 < 2); l1433 = (l1433 + 1)) {
			fRec2067[l1433] = 0.0;
			
		}
		for (int l1434 = 0; (l1434 < 2); l1434 = (l1434 + 1)) {
			fRec2065[l1434] = 0.0;
			
		}
		for (int l1435 = 0; (l1435 < 2); l1435 = (l1435 + 1)) {
			fRec2076[l1435] = 0.0;
			
		}
		for (int l1436 = 0; (l1436 < 2); l1436 = (l1436 + 1)) {
			fRec2074[l1436] = 0.0;
			
		}
		for (int l1437 = 0; (l1437 < 2); l1437 = (l1437 + 1)) {
			fRec2082[l1437] = 0.0;
			
		}
		for (int l1438 = 0; (l1438 < 2); l1438 = (l1438 + 1)) {
			fRec2080[l1438] = 0.0;
			
		}
		for (int l1439 = 0; (l1439 < 2); l1439 = (l1439 + 1)) {
			fRec2079[l1439] = 0.0;
			
		}
		for (int l1440 = 0; (l1440 < 2); l1440 = (l1440 + 1)) {
			fRec2077[l1440] = 0.0;
			
		}
		for (int l1441 = 0; (l1441 < 512); l1441 = (l1441 + 1)) {
			fVec30[l1441] = 0.0;
			
		}
		for (int l1442 = 0; (l1442 < 2); l1442 = (l1442 + 1)) {
			fRec2100[l1442] = 0.0;
			
		}
		for (int l1443 = 0; (l1443 < 2); l1443 = (l1443 + 1)) {
			fRec2098[l1443] = 0.0;
			
		}
		for (int l1444 = 0; (l1444 < 2); l1444 = (l1444 + 1)) {
			fRec2097[l1444] = 0.0;
			
		}
		for (int l1445 = 0; (l1445 < 2); l1445 = (l1445 + 1)) {
			fRec2095[l1445] = 0.0;
			
		}
		for (int l1446 = 0; (l1446 < 2); l1446 = (l1446 + 1)) {
			fRec2094[l1446] = 0.0;
			
		}
		for (int l1447 = 0; (l1447 < 2); l1447 = (l1447 + 1)) {
			fRec2092[l1447] = 0.0;
			
		}
		for (int l1448 = 0; (l1448 < 2); l1448 = (l1448 + 1)) {
			fRec2091[l1448] = 0.0;
			
		}
		for (int l1449 = 0; (l1449 < 2); l1449 = (l1449 + 1)) {
			fRec2089[l1449] = 0.0;
			
		}
		for (int l1450 = 0; (l1450 < 2); l1450 = (l1450 + 1)) {
			fRec2088[l1450] = 0.0;
			
		}
		for (int l1451 = 0; (l1451 < 2); l1451 = (l1451 + 1)) {
			fRec2086[l1451] = 0.0;
			
		}
		for (int l1452 = 0; (l1452 < 2); l1452 = (l1452 + 1)) {
			fRec2085[l1452] = 0.0;
			
		}
		for (int l1453 = 0; (l1453 < 2); l1453 = (l1453 + 1)) {
			fRec2083[l1453] = 0.0;
			
		}
		for (int l1454 = 0; (l1454 < 2); l1454 = (l1454 + 1)) {
			fRec2115[l1454] = 0.0;
			
		}
		for (int l1455 = 0; (l1455 < 2); l1455 = (l1455 + 1)) {
			fRec2113[l1455] = 0.0;
			
		}
		for (int l1456 = 0; (l1456 < 2); l1456 = (l1456 + 1)) {
			fRec2112[l1456] = 0.0;
			
		}
		for (int l1457 = 0; (l1457 < 2); l1457 = (l1457 + 1)) {
			fRec2110[l1457] = 0.0;
			
		}
		for (int l1458 = 0; (l1458 < 2); l1458 = (l1458 + 1)) {
			fRec2109[l1458] = 0.0;
			
		}
		for (int l1459 = 0; (l1459 < 2); l1459 = (l1459 + 1)) {
			fRec2107[l1459] = 0.0;
			
		}
		for (int l1460 = 0; (l1460 < 2); l1460 = (l1460 + 1)) {
			fRec2106[l1460] = 0.0;
			
		}
		for (int l1461 = 0; (l1461 < 2); l1461 = (l1461 + 1)) {
			fRec2104[l1461] = 0.0;
			
		}
		for (int l1462 = 0; (l1462 < 2); l1462 = (l1462 + 1)) {
			fRec2103[l1462] = 0.0;
			
		}
		for (int l1463 = 0; (l1463 < 2); l1463 = (l1463 + 1)) {
			fRec2101[l1463] = 0.0;
			
		}
		for (int l1464 = 0; (l1464 < 2); l1464 = (l1464 + 1)) {
			fRec2127[l1464] = 0.0;
			
		}
		for (int l1465 = 0; (l1465 < 2); l1465 = (l1465 + 1)) {
			fRec2125[l1465] = 0.0;
			
		}
		for (int l1466 = 0; (l1466 < 2); l1466 = (l1466 + 1)) {
			fRec2124[l1466] = 0.0;
			
		}
		for (int l1467 = 0; (l1467 < 2); l1467 = (l1467 + 1)) {
			fRec2122[l1467] = 0.0;
			
		}
		for (int l1468 = 0; (l1468 < 2); l1468 = (l1468 + 1)) {
			fRec2121[l1468] = 0.0;
			
		}
		for (int l1469 = 0; (l1469 < 2); l1469 = (l1469 + 1)) {
			fRec2119[l1469] = 0.0;
			
		}
		for (int l1470 = 0; (l1470 < 2); l1470 = (l1470 + 1)) {
			fRec2118[l1470] = 0.0;
			
		}
		for (int l1471 = 0; (l1471 < 2); l1471 = (l1471 + 1)) {
			fRec2116[l1471] = 0.0;
			
		}
		for (int l1472 = 0; (l1472 < 2); l1472 = (l1472 + 1)) {
			fRec2136[l1472] = 0.0;
			
		}
		for (int l1473 = 0; (l1473 < 2); l1473 = (l1473 + 1)) {
			fRec2134[l1473] = 0.0;
			
		}
		for (int l1474 = 0; (l1474 < 2); l1474 = (l1474 + 1)) {
			fRec2133[l1474] = 0.0;
			
		}
		for (int l1475 = 0; (l1475 < 2); l1475 = (l1475 + 1)) {
			fRec2131[l1475] = 0.0;
			
		}
		for (int l1476 = 0; (l1476 < 2); l1476 = (l1476 + 1)) {
			fRec2130[l1476] = 0.0;
			
		}
		for (int l1477 = 0; (l1477 < 2); l1477 = (l1477 + 1)) {
			fRec2128[l1477] = 0.0;
			
		}
		for (int l1478 = 0; (l1478 < 2); l1478 = (l1478 + 1)) {
			fRec2139[l1478] = 0.0;
			
		}
		for (int l1479 = 0; (l1479 < 2); l1479 = (l1479 + 1)) {
			fRec2137[l1479] = 0.0;
			
		}
		for (int l1480 = 0; (l1480 < 2); l1480 = (l1480 + 1)) {
			fRec2145[l1480] = 0.0;
			
		}
		for (int l1481 = 0; (l1481 < 2); l1481 = (l1481 + 1)) {
			fRec2143[l1481] = 0.0;
			
		}
		for (int l1482 = 0; (l1482 < 2); l1482 = (l1482 + 1)) {
			fRec2142[l1482] = 0.0;
			
		}
		for (int l1483 = 0; (l1483 < 2); l1483 = (l1483 + 1)) {
			fRec2140[l1483] = 0.0;
			
		}
		for (int l1484 = 0; (l1484 < 512); l1484 = (l1484 + 1)) {
			fVec31[l1484] = 0.0;
			
		}
		for (int l1485 = 0; (l1485 < 2); l1485 = (l1485 + 1)) {
			fRec2163[l1485] = 0.0;
			
		}
		for (int l1486 = 0; (l1486 < 2); l1486 = (l1486 + 1)) {
			fRec2161[l1486] = 0.0;
			
		}
		for (int l1487 = 0; (l1487 < 2); l1487 = (l1487 + 1)) {
			fRec2160[l1487] = 0.0;
			
		}
		for (int l1488 = 0; (l1488 < 2); l1488 = (l1488 + 1)) {
			fRec2158[l1488] = 0.0;
			
		}
		for (int l1489 = 0; (l1489 < 2); l1489 = (l1489 + 1)) {
			fRec2157[l1489] = 0.0;
			
		}
		for (int l1490 = 0; (l1490 < 2); l1490 = (l1490 + 1)) {
			fRec2155[l1490] = 0.0;
			
		}
		for (int l1491 = 0; (l1491 < 2); l1491 = (l1491 + 1)) {
			fRec2154[l1491] = 0.0;
			
		}
		for (int l1492 = 0; (l1492 < 2); l1492 = (l1492 + 1)) {
			fRec2152[l1492] = 0.0;
			
		}
		for (int l1493 = 0; (l1493 < 2); l1493 = (l1493 + 1)) {
			fRec2151[l1493] = 0.0;
			
		}
		for (int l1494 = 0; (l1494 < 2); l1494 = (l1494 + 1)) {
			fRec2149[l1494] = 0.0;
			
		}
		for (int l1495 = 0; (l1495 < 2); l1495 = (l1495 + 1)) {
			fRec2148[l1495] = 0.0;
			
		}
		for (int l1496 = 0; (l1496 < 2); l1496 = (l1496 + 1)) {
			fRec2146[l1496] = 0.0;
			
		}
		for (int l1497 = 0; (l1497 < 2); l1497 = (l1497 + 1)) {
			fRec2178[l1497] = 0.0;
			
		}
		for (int l1498 = 0; (l1498 < 2); l1498 = (l1498 + 1)) {
			fRec2176[l1498] = 0.0;
			
		}
		for (int l1499 = 0; (l1499 < 2); l1499 = (l1499 + 1)) {
			fRec2175[l1499] = 0.0;
			
		}
		for (int l1500 = 0; (l1500 < 2); l1500 = (l1500 + 1)) {
			fRec2173[l1500] = 0.0;
			
		}
		for (int l1501 = 0; (l1501 < 2); l1501 = (l1501 + 1)) {
			fRec2172[l1501] = 0.0;
			
		}
		for (int l1502 = 0; (l1502 < 2); l1502 = (l1502 + 1)) {
			fRec2170[l1502] = 0.0;
			
		}
		for (int l1503 = 0; (l1503 < 2); l1503 = (l1503 + 1)) {
			fRec2169[l1503] = 0.0;
			
		}
		for (int l1504 = 0; (l1504 < 2); l1504 = (l1504 + 1)) {
			fRec2167[l1504] = 0.0;
			
		}
		for (int l1505 = 0; (l1505 < 2); l1505 = (l1505 + 1)) {
			fRec2166[l1505] = 0.0;
			
		}
		for (int l1506 = 0; (l1506 < 2); l1506 = (l1506 + 1)) {
			fRec2164[l1506] = 0.0;
			
		}
		for (int l1507 = 0; (l1507 < 2); l1507 = (l1507 + 1)) {
			fRec2190[l1507] = 0.0;
			
		}
		for (int l1508 = 0; (l1508 < 2); l1508 = (l1508 + 1)) {
			fRec2188[l1508] = 0.0;
			
		}
		for (int l1509 = 0; (l1509 < 2); l1509 = (l1509 + 1)) {
			fRec2187[l1509] = 0.0;
			
		}
		for (int l1510 = 0; (l1510 < 2); l1510 = (l1510 + 1)) {
			fRec2185[l1510] = 0.0;
			
		}
		for (int l1511 = 0; (l1511 < 2); l1511 = (l1511 + 1)) {
			fRec2184[l1511] = 0.0;
			
		}
		for (int l1512 = 0; (l1512 < 2); l1512 = (l1512 + 1)) {
			fRec2182[l1512] = 0.0;
			
		}
		for (int l1513 = 0; (l1513 < 2); l1513 = (l1513 + 1)) {
			fRec2181[l1513] = 0.0;
			
		}
		for (int l1514 = 0; (l1514 < 2); l1514 = (l1514 + 1)) {
			fRec2179[l1514] = 0.0;
			
		}
		for (int l1515 = 0; (l1515 < 2); l1515 = (l1515 + 1)) {
			fRec2199[l1515] = 0.0;
			
		}
		for (int l1516 = 0; (l1516 < 2); l1516 = (l1516 + 1)) {
			fRec2197[l1516] = 0.0;
			
		}
		for (int l1517 = 0; (l1517 < 2); l1517 = (l1517 + 1)) {
			fRec2196[l1517] = 0.0;
			
		}
		for (int l1518 = 0; (l1518 < 2); l1518 = (l1518 + 1)) {
			fRec2194[l1518] = 0.0;
			
		}
		for (int l1519 = 0; (l1519 < 2); l1519 = (l1519 + 1)) {
			fRec2193[l1519] = 0.0;
			
		}
		for (int l1520 = 0; (l1520 < 2); l1520 = (l1520 + 1)) {
			fRec2191[l1520] = 0.0;
			
		}
		for (int l1521 = 0; (l1521 < 2); l1521 = (l1521 + 1)) {
			fRec2202[l1521] = 0.0;
			
		}
		for (int l1522 = 0; (l1522 < 2); l1522 = (l1522 + 1)) {
			fRec2200[l1522] = 0.0;
			
		}
		for (int l1523 = 0; (l1523 < 2); l1523 = (l1523 + 1)) {
			fRec2208[l1523] = 0.0;
			
		}
		for (int l1524 = 0; (l1524 < 2); l1524 = (l1524 + 1)) {
			fRec2206[l1524] = 0.0;
			
		}
		for (int l1525 = 0; (l1525 < 2); l1525 = (l1525 + 1)) {
			fRec2205[l1525] = 0.0;
			
		}
		for (int l1526 = 0; (l1526 < 2); l1526 = (l1526 + 1)) {
			fRec2203[l1526] = 0.0;
			
		}
		for (int l1527 = 0; (l1527 < 512); l1527 = (l1527 + 1)) {
			fVec32[l1527] = 0.0;
			
		}
		for (int l1528 = 0; (l1528 < 2); l1528 = (l1528 + 1)) {
			fRec2226[l1528] = 0.0;
			
		}
		for (int l1529 = 0; (l1529 < 2); l1529 = (l1529 + 1)) {
			fRec2224[l1529] = 0.0;
			
		}
		for (int l1530 = 0; (l1530 < 2); l1530 = (l1530 + 1)) {
			fRec2223[l1530] = 0.0;
			
		}
		for (int l1531 = 0; (l1531 < 2); l1531 = (l1531 + 1)) {
			fRec2221[l1531] = 0.0;
			
		}
		for (int l1532 = 0; (l1532 < 2); l1532 = (l1532 + 1)) {
			fRec2220[l1532] = 0.0;
			
		}
		for (int l1533 = 0; (l1533 < 2); l1533 = (l1533 + 1)) {
			fRec2218[l1533] = 0.0;
			
		}
		for (int l1534 = 0; (l1534 < 2); l1534 = (l1534 + 1)) {
			fRec2217[l1534] = 0.0;
			
		}
		for (int l1535 = 0; (l1535 < 2); l1535 = (l1535 + 1)) {
			fRec2215[l1535] = 0.0;
			
		}
		for (int l1536 = 0; (l1536 < 2); l1536 = (l1536 + 1)) {
			fRec2214[l1536] = 0.0;
			
		}
		for (int l1537 = 0; (l1537 < 2); l1537 = (l1537 + 1)) {
			fRec2212[l1537] = 0.0;
			
		}
		for (int l1538 = 0; (l1538 < 2); l1538 = (l1538 + 1)) {
			fRec2211[l1538] = 0.0;
			
		}
		for (int l1539 = 0; (l1539 < 2); l1539 = (l1539 + 1)) {
			fRec2209[l1539] = 0.0;
			
		}
		for (int l1540 = 0; (l1540 < 2); l1540 = (l1540 + 1)) {
			fRec2241[l1540] = 0.0;
			
		}
		for (int l1541 = 0; (l1541 < 2); l1541 = (l1541 + 1)) {
			fRec2239[l1541] = 0.0;
			
		}
		for (int l1542 = 0; (l1542 < 2); l1542 = (l1542 + 1)) {
			fRec2238[l1542] = 0.0;
			
		}
		for (int l1543 = 0; (l1543 < 2); l1543 = (l1543 + 1)) {
			fRec2236[l1543] = 0.0;
			
		}
		for (int l1544 = 0; (l1544 < 2); l1544 = (l1544 + 1)) {
			fRec2235[l1544] = 0.0;
			
		}
		for (int l1545 = 0; (l1545 < 2); l1545 = (l1545 + 1)) {
			fRec2233[l1545] = 0.0;
			
		}
		for (int l1546 = 0; (l1546 < 2); l1546 = (l1546 + 1)) {
			fRec2232[l1546] = 0.0;
			
		}
		for (int l1547 = 0; (l1547 < 2); l1547 = (l1547 + 1)) {
			fRec2230[l1547] = 0.0;
			
		}
		for (int l1548 = 0; (l1548 < 2); l1548 = (l1548 + 1)) {
			fRec2229[l1548] = 0.0;
			
		}
		for (int l1549 = 0; (l1549 < 2); l1549 = (l1549 + 1)) {
			fRec2227[l1549] = 0.0;
			
		}
		for (int l1550 = 0; (l1550 < 2); l1550 = (l1550 + 1)) {
			fRec2253[l1550] = 0.0;
			
		}
		for (int l1551 = 0; (l1551 < 2); l1551 = (l1551 + 1)) {
			fRec2251[l1551] = 0.0;
			
		}
		for (int l1552 = 0; (l1552 < 2); l1552 = (l1552 + 1)) {
			fRec2250[l1552] = 0.0;
			
		}
		for (int l1553 = 0; (l1553 < 2); l1553 = (l1553 + 1)) {
			fRec2248[l1553] = 0.0;
			
		}
		for (int l1554 = 0; (l1554 < 2); l1554 = (l1554 + 1)) {
			fRec2247[l1554] = 0.0;
			
		}
		for (int l1555 = 0; (l1555 < 2); l1555 = (l1555 + 1)) {
			fRec2245[l1555] = 0.0;
			
		}
		for (int l1556 = 0; (l1556 < 2); l1556 = (l1556 + 1)) {
			fRec2244[l1556] = 0.0;
			
		}
		for (int l1557 = 0; (l1557 < 2); l1557 = (l1557 + 1)) {
			fRec2242[l1557] = 0.0;
			
		}
		for (int l1558 = 0; (l1558 < 2); l1558 = (l1558 + 1)) {
			fRec2262[l1558] = 0.0;
			
		}
		for (int l1559 = 0; (l1559 < 2); l1559 = (l1559 + 1)) {
			fRec2260[l1559] = 0.0;
			
		}
		for (int l1560 = 0; (l1560 < 2); l1560 = (l1560 + 1)) {
			fRec2259[l1560] = 0.0;
			
		}
		for (int l1561 = 0; (l1561 < 2); l1561 = (l1561 + 1)) {
			fRec2257[l1561] = 0.0;
			
		}
		for (int l1562 = 0; (l1562 < 2); l1562 = (l1562 + 1)) {
			fRec2256[l1562] = 0.0;
			
		}
		for (int l1563 = 0; (l1563 < 2); l1563 = (l1563 + 1)) {
			fRec2254[l1563] = 0.0;
			
		}
		for (int l1564 = 0; (l1564 < 2); l1564 = (l1564 + 1)) {
			fRec2265[l1564] = 0.0;
			
		}
		for (int l1565 = 0; (l1565 < 2); l1565 = (l1565 + 1)) {
			fRec2263[l1565] = 0.0;
			
		}
		for (int l1566 = 0; (l1566 < 2); l1566 = (l1566 + 1)) {
			fRec2271[l1566] = 0.0;
			
		}
		for (int l1567 = 0; (l1567 < 2); l1567 = (l1567 + 1)) {
			fRec2269[l1567] = 0.0;
			
		}
		for (int l1568 = 0; (l1568 < 2); l1568 = (l1568 + 1)) {
			fRec2268[l1568] = 0.0;
			
		}
		for (int l1569 = 0; (l1569 < 2); l1569 = (l1569 + 1)) {
			fRec2266[l1569] = 0.0;
			
		}
		for (int l1570 = 0; (l1570 < 512); l1570 = (l1570 + 1)) {
			fVec33[l1570] = 0.0;
			
		}
		for (int l1571 = 0; (l1571 < 2); l1571 = (l1571 + 1)) {
			fRec2289[l1571] = 0.0;
			
		}
		for (int l1572 = 0; (l1572 < 2); l1572 = (l1572 + 1)) {
			fRec2287[l1572] = 0.0;
			
		}
		for (int l1573 = 0; (l1573 < 2); l1573 = (l1573 + 1)) {
			fRec2286[l1573] = 0.0;
			
		}
		for (int l1574 = 0; (l1574 < 2); l1574 = (l1574 + 1)) {
			fRec2284[l1574] = 0.0;
			
		}
		for (int l1575 = 0; (l1575 < 2); l1575 = (l1575 + 1)) {
			fRec2283[l1575] = 0.0;
			
		}
		for (int l1576 = 0; (l1576 < 2); l1576 = (l1576 + 1)) {
			fRec2281[l1576] = 0.0;
			
		}
		for (int l1577 = 0; (l1577 < 2); l1577 = (l1577 + 1)) {
			fRec2280[l1577] = 0.0;
			
		}
		for (int l1578 = 0; (l1578 < 2); l1578 = (l1578 + 1)) {
			fRec2278[l1578] = 0.0;
			
		}
		for (int l1579 = 0; (l1579 < 2); l1579 = (l1579 + 1)) {
			fRec2277[l1579] = 0.0;
			
		}
		for (int l1580 = 0; (l1580 < 2); l1580 = (l1580 + 1)) {
			fRec2275[l1580] = 0.0;
			
		}
		for (int l1581 = 0; (l1581 < 2); l1581 = (l1581 + 1)) {
			fRec2274[l1581] = 0.0;
			
		}
		for (int l1582 = 0; (l1582 < 2); l1582 = (l1582 + 1)) {
			fRec2272[l1582] = 0.0;
			
		}
		for (int l1583 = 0; (l1583 < 2); l1583 = (l1583 + 1)) {
			fRec2304[l1583] = 0.0;
			
		}
		for (int l1584 = 0; (l1584 < 2); l1584 = (l1584 + 1)) {
			fRec2302[l1584] = 0.0;
			
		}
		for (int l1585 = 0; (l1585 < 2); l1585 = (l1585 + 1)) {
			fRec2301[l1585] = 0.0;
			
		}
		for (int l1586 = 0; (l1586 < 2); l1586 = (l1586 + 1)) {
			fRec2299[l1586] = 0.0;
			
		}
		for (int l1587 = 0; (l1587 < 2); l1587 = (l1587 + 1)) {
			fRec2298[l1587] = 0.0;
			
		}
		for (int l1588 = 0; (l1588 < 2); l1588 = (l1588 + 1)) {
			fRec2296[l1588] = 0.0;
			
		}
		for (int l1589 = 0; (l1589 < 2); l1589 = (l1589 + 1)) {
			fRec2295[l1589] = 0.0;
			
		}
		for (int l1590 = 0; (l1590 < 2); l1590 = (l1590 + 1)) {
			fRec2293[l1590] = 0.0;
			
		}
		for (int l1591 = 0; (l1591 < 2); l1591 = (l1591 + 1)) {
			fRec2292[l1591] = 0.0;
			
		}
		for (int l1592 = 0; (l1592 < 2); l1592 = (l1592 + 1)) {
			fRec2290[l1592] = 0.0;
			
		}
		for (int l1593 = 0; (l1593 < 2); l1593 = (l1593 + 1)) {
			fRec2316[l1593] = 0.0;
			
		}
		for (int l1594 = 0; (l1594 < 2); l1594 = (l1594 + 1)) {
			fRec2314[l1594] = 0.0;
			
		}
		for (int l1595 = 0; (l1595 < 2); l1595 = (l1595 + 1)) {
			fRec2313[l1595] = 0.0;
			
		}
		for (int l1596 = 0; (l1596 < 2); l1596 = (l1596 + 1)) {
			fRec2311[l1596] = 0.0;
			
		}
		for (int l1597 = 0; (l1597 < 2); l1597 = (l1597 + 1)) {
			fRec2310[l1597] = 0.0;
			
		}
		for (int l1598 = 0; (l1598 < 2); l1598 = (l1598 + 1)) {
			fRec2308[l1598] = 0.0;
			
		}
		for (int l1599 = 0; (l1599 < 2); l1599 = (l1599 + 1)) {
			fRec2307[l1599] = 0.0;
			
		}
		for (int l1600 = 0; (l1600 < 2); l1600 = (l1600 + 1)) {
			fRec2305[l1600] = 0.0;
			
		}
		for (int l1601 = 0; (l1601 < 2); l1601 = (l1601 + 1)) {
			fRec2325[l1601] = 0.0;
			
		}
		for (int l1602 = 0; (l1602 < 2); l1602 = (l1602 + 1)) {
			fRec2323[l1602] = 0.0;
			
		}
		for (int l1603 = 0; (l1603 < 2); l1603 = (l1603 + 1)) {
			fRec2322[l1603] = 0.0;
			
		}
		for (int l1604 = 0; (l1604 < 2); l1604 = (l1604 + 1)) {
			fRec2320[l1604] = 0.0;
			
		}
		for (int l1605 = 0; (l1605 < 2); l1605 = (l1605 + 1)) {
			fRec2319[l1605] = 0.0;
			
		}
		for (int l1606 = 0; (l1606 < 2); l1606 = (l1606 + 1)) {
			fRec2317[l1606] = 0.0;
			
		}
		for (int l1607 = 0; (l1607 < 2); l1607 = (l1607 + 1)) {
			fRec2328[l1607] = 0.0;
			
		}
		for (int l1608 = 0; (l1608 < 2); l1608 = (l1608 + 1)) {
			fRec2326[l1608] = 0.0;
			
		}
		for (int l1609 = 0; (l1609 < 2); l1609 = (l1609 + 1)) {
			fRec2334[l1609] = 0.0;
			
		}
		for (int l1610 = 0; (l1610 < 2); l1610 = (l1610 + 1)) {
			fRec2332[l1610] = 0.0;
			
		}
		for (int l1611 = 0; (l1611 < 2); l1611 = (l1611 + 1)) {
			fRec2331[l1611] = 0.0;
			
		}
		for (int l1612 = 0; (l1612 < 2); l1612 = (l1612 + 1)) {
			fRec2329[l1612] = 0.0;
			
		}
		for (int l1613 = 0; (l1613 < 512); l1613 = (l1613 + 1)) {
			fVec34[l1613] = 0.0;
			
		}
		for (int l1614 = 0; (l1614 < 2); l1614 = (l1614 + 1)) {
			fRec2352[l1614] = 0.0;
			
		}
		for (int l1615 = 0; (l1615 < 2); l1615 = (l1615 + 1)) {
			fRec2350[l1615] = 0.0;
			
		}
		for (int l1616 = 0; (l1616 < 2); l1616 = (l1616 + 1)) {
			fRec2349[l1616] = 0.0;
			
		}
		for (int l1617 = 0; (l1617 < 2); l1617 = (l1617 + 1)) {
			fRec2347[l1617] = 0.0;
			
		}
		for (int l1618 = 0; (l1618 < 2); l1618 = (l1618 + 1)) {
			fRec2346[l1618] = 0.0;
			
		}
		for (int l1619 = 0; (l1619 < 2); l1619 = (l1619 + 1)) {
			fRec2344[l1619] = 0.0;
			
		}
		for (int l1620 = 0; (l1620 < 2); l1620 = (l1620 + 1)) {
			fRec2343[l1620] = 0.0;
			
		}
		for (int l1621 = 0; (l1621 < 2); l1621 = (l1621 + 1)) {
			fRec2341[l1621] = 0.0;
			
		}
		for (int l1622 = 0; (l1622 < 2); l1622 = (l1622 + 1)) {
			fRec2340[l1622] = 0.0;
			
		}
		for (int l1623 = 0; (l1623 < 2); l1623 = (l1623 + 1)) {
			fRec2338[l1623] = 0.0;
			
		}
		for (int l1624 = 0; (l1624 < 2); l1624 = (l1624 + 1)) {
			fRec2337[l1624] = 0.0;
			
		}
		for (int l1625 = 0; (l1625 < 2); l1625 = (l1625 + 1)) {
			fRec2335[l1625] = 0.0;
			
		}
		for (int l1626 = 0; (l1626 < 2); l1626 = (l1626 + 1)) {
			fRec2367[l1626] = 0.0;
			
		}
		for (int l1627 = 0; (l1627 < 2); l1627 = (l1627 + 1)) {
			fRec2365[l1627] = 0.0;
			
		}
		for (int l1628 = 0; (l1628 < 2); l1628 = (l1628 + 1)) {
			fRec2364[l1628] = 0.0;
			
		}
		for (int l1629 = 0; (l1629 < 2); l1629 = (l1629 + 1)) {
			fRec2362[l1629] = 0.0;
			
		}
		for (int l1630 = 0; (l1630 < 2); l1630 = (l1630 + 1)) {
			fRec2361[l1630] = 0.0;
			
		}
		for (int l1631 = 0; (l1631 < 2); l1631 = (l1631 + 1)) {
			fRec2359[l1631] = 0.0;
			
		}
		for (int l1632 = 0; (l1632 < 2); l1632 = (l1632 + 1)) {
			fRec2358[l1632] = 0.0;
			
		}
		for (int l1633 = 0; (l1633 < 2); l1633 = (l1633 + 1)) {
			fRec2356[l1633] = 0.0;
			
		}
		for (int l1634 = 0; (l1634 < 2); l1634 = (l1634 + 1)) {
			fRec2355[l1634] = 0.0;
			
		}
		for (int l1635 = 0; (l1635 < 2); l1635 = (l1635 + 1)) {
			fRec2353[l1635] = 0.0;
			
		}
		for (int l1636 = 0; (l1636 < 2); l1636 = (l1636 + 1)) {
			fRec2379[l1636] = 0.0;
			
		}
		for (int l1637 = 0; (l1637 < 2); l1637 = (l1637 + 1)) {
			fRec2377[l1637] = 0.0;
			
		}
		for (int l1638 = 0; (l1638 < 2); l1638 = (l1638 + 1)) {
			fRec2376[l1638] = 0.0;
			
		}
		for (int l1639 = 0; (l1639 < 2); l1639 = (l1639 + 1)) {
			fRec2374[l1639] = 0.0;
			
		}
		for (int l1640 = 0; (l1640 < 2); l1640 = (l1640 + 1)) {
			fRec2373[l1640] = 0.0;
			
		}
		for (int l1641 = 0; (l1641 < 2); l1641 = (l1641 + 1)) {
			fRec2371[l1641] = 0.0;
			
		}
		for (int l1642 = 0; (l1642 < 2); l1642 = (l1642 + 1)) {
			fRec2370[l1642] = 0.0;
			
		}
		for (int l1643 = 0; (l1643 < 2); l1643 = (l1643 + 1)) {
			fRec2368[l1643] = 0.0;
			
		}
		for (int l1644 = 0; (l1644 < 2); l1644 = (l1644 + 1)) {
			fRec2388[l1644] = 0.0;
			
		}
		for (int l1645 = 0; (l1645 < 2); l1645 = (l1645 + 1)) {
			fRec2386[l1645] = 0.0;
			
		}
		for (int l1646 = 0; (l1646 < 2); l1646 = (l1646 + 1)) {
			fRec2385[l1646] = 0.0;
			
		}
		for (int l1647 = 0; (l1647 < 2); l1647 = (l1647 + 1)) {
			fRec2383[l1647] = 0.0;
			
		}
		for (int l1648 = 0; (l1648 < 2); l1648 = (l1648 + 1)) {
			fRec2382[l1648] = 0.0;
			
		}
		for (int l1649 = 0; (l1649 < 2); l1649 = (l1649 + 1)) {
			fRec2380[l1649] = 0.0;
			
		}
		for (int l1650 = 0; (l1650 < 2); l1650 = (l1650 + 1)) {
			fRec2391[l1650] = 0.0;
			
		}
		for (int l1651 = 0; (l1651 < 2); l1651 = (l1651 + 1)) {
			fRec2389[l1651] = 0.0;
			
		}
		for (int l1652 = 0; (l1652 < 2); l1652 = (l1652 + 1)) {
			fRec2397[l1652] = 0.0;
			
		}
		for (int l1653 = 0; (l1653 < 2); l1653 = (l1653 + 1)) {
			fRec2395[l1653] = 0.0;
			
		}
		for (int l1654 = 0; (l1654 < 2); l1654 = (l1654 + 1)) {
			fRec2394[l1654] = 0.0;
			
		}
		for (int l1655 = 0; (l1655 < 2); l1655 = (l1655 + 1)) {
			fRec2392[l1655] = 0.0;
			
		}
		for (int l1656 = 0; (l1656 < 512); l1656 = (l1656 + 1)) {
			fVec35[l1656] = 0.0;
			
		}
		for (int l1657 = 0; (l1657 < 2); l1657 = (l1657 + 1)) {
			fRec2415[l1657] = 0.0;
			
		}
		for (int l1658 = 0; (l1658 < 2); l1658 = (l1658 + 1)) {
			fRec2413[l1658] = 0.0;
			
		}
		for (int l1659 = 0; (l1659 < 2); l1659 = (l1659 + 1)) {
			fRec2412[l1659] = 0.0;
			
		}
		for (int l1660 = 0; (l1660 < 2); l1660 = (l1660 + 1)) {
			fRec2410[l1660] = 0.0;
			
		}
		for (int l1661 = 0; (l1661 < 2); l1661 = (l1661 + 1)) {
			fRec2409[l1661] = 0.0;
			
		}
		for (int l1662 = 0; (l1662 < 2); l1662 = (l1662 + 1)) {
			fRec2407[l1662] = 0.0;
			
		}
		for (int l1663 = 0; (l1663 < 2); l1663 = (l1663 + 1)) {
			fRec2406[l1663] = 0.0;
			
		}
		for (int l1664 = 0; (l1664 < 2); l1664 = (l1664 + 1)) {
			fRec2404[l1664] = 0.0;
			
		}
		for (int l1665 = 0; (l1665 < 2); l1665 = (l1665 + 1)) {
			fRec2403[l1665] = 0.0;
			
		}
		for (int l1666 = 0; (l1666 < 2); l1666 = (l1666 + 1)) {
			fRec2401[l1666] = 0.0;
			
		}
		for (int l1667 = 0; (l1667 < 2); l1667 = (l1667 + 1)) {
			fRec2400[l1667] = 0.0;
			
		}
		for (int l1668 = 0; (l1668 < 2); l1668 = (l1668 + 1)) {
			fRec2398[l1668] = 0.0;
			
		}
		for (int l1669 = 0; (l1669 < 2); l1669 = (l1669 + 1)) {
			fRec2430[l1669] = 0.0;
			
		}
		for (int l1670 = 0; (l1670 < 2); l1670 = (l1670 + 1)) {
			fRec2428[l1670] = 0.0;
			
		}
		for (int l1671 = 0; (l1671 < 2); l1671 = (l1671 + 1)) {
			fRec2427[l1671] = 0.0;
			
		}
		for (int l1672 = 0; (l1672 < 2); l1672 = (l1672 + 1)) {
			fRec2425[l1672] = 0.0;
			
		}
		for (int l1673 = 0; (l1673 < 2); l1673 = (l1673 + 1)) {
			fRec2424[l1673] = 0.0;
			
		}
		for (int l1674 = 0; (l1674 < 2); l1674 = (l1674 + 1)) {
			fRec2422[l1674] = 0.0;
			
		}
		for (int l1675 = 0; (l1675 < 2); l1675 = (l1675 + 1)) {
			fRec2421[l1675] = 0.0;
			
		}
		for (int l1676 = 0; (l1676 < 2); l1676 = (l1676 + 1)) {
			fRec2419[l1676] = 0.0;
			
		}
		for (int l1677 = 0; (l1677 < 2); l1677 = (l1677 + 1)) {
			fRec2418[l1677] = 0.0;
			
		}
		for (int l1678 = 0; (l1678 < 2); l1678 = (l1678 + 1)) {
			fRec2416[l1678] = 0.0;
			
		}
		for (int l1679 = 0; (l1679 < 2); l1679 = (l1679 + 1)) {
			fRec2442[l1679] = 0.0;
			
		}
		for (int l1680 = 0; (l1680 < 2); l1680 = (l1680 + 1)) {
			fRec2440[l1680] = 0.0;
			
		}
		for (int l1681 = 0; (l1681 < 2); l1681 = (l1681 + 1)) {
			fRec2439[l1681] = 0.0;
			
		}
		for (int l1682 = 0; (l1682 < 2); l1682 = (l1682 + 1)) {
			fRec2437[l1682] = 0.0;
			
		}
		for (int l1683 = 0; (l1683 < 2); l1683 = (l1683 + 1)) {
			fRec2436[l1683] = 0.0;
			
		}
		for (int l1684 = 0; (l1684 < 2); l1684 = (l1684 + 1)) {
			fRec2434[l1684] = 0.0;
			
		}
		for (int l1685 = 0; (l1685 < 2); l1685 = (l1685 + 1)) {
			fRec2433[l1685] = 0.0;
			
		}
		for (int l1686 = 0; (l1686 < 2); l1686 = (l1686 + 1)) {
			fRec2431[l1686] = 0.0;
			
		}
		for (int l1687 = 0; (l1687 < 2); l1687 = (l1687 + 1)) {
			fRec2451[l1687] = 0.0;
			
		}
		for (int l1688 = 0; (l1688 < 2); l1688 = (l1688 + 1)) {
			fRec2449[l1688] = 0.0;
			
		}
		for (int l1689 = 0; (l1689 < 2); l1689 = (l1689 + 1)) {
			fRec2448[l1689] = 0.0;
			
		}
		for (int l1690 = 0; (l1690 < 2); l1690 = (l1690 + 1)) {
			fRec2446[l1690] = 0.0;
			
		}
		for (int l1691 = 0; (l1691 < 2); l1691 = (l1691 + 1)) {
			fRec2445[l1691] = 0.0;
			
		}
		for (int l1692 = 0; (l1692 < 2); l1692 = (l1692 + 1)) {
			fRec2443[l1692] = 0.0;
			
		}
		for (int l1693 = 0; (l1693 < 2); l1693 = (l1693 + 1)) {
			fRec2454[l1693] = 0.0;
			
		}
		for (int l1694 = 0; (l1694 < 2); l1694 = (l1694 + 1)) {
			fRec2452[l1694] = 0.0;
			
		}
		for (int l1695 = 0; (l1695 < 2); l1695 = (l1695 + 1)) {
			fRec2460[l1695] = 0.0;
			
		}
		for (int l1696 = 0; (l1696 < 2); l1696 = (l1696 + 1)) {
			fRec2458[l1696] = 0.0;
			
		}
		for (int l1697 = 0; (l1697 < 2); l1697 = (l1697 + 1)) {
			fRec2457[l1697] = 0.0;
			
		}
		for (int l1698 = 0; (l1698 < 2); l1698 = (l1698 + 1)) {
			fRec2455[l1698] = 0.0;
			
		}
		for (int l1699 = 0; (l1699 < 512); l1699 = (l1699 + 1)) {
			fVec36[l1699] = 0.0;
			
		}
		for (int l1700 = 0; (l1700 < 2); l1700 = (l1700 + 1)) {
			fRec2478[l1700] = 0.0;
			
		}
		for (int l1701 = 0; (l1701 < 2); l1701 = (l1701 + 1)) {
			fRec2476[l1701] = 0.0;
			
		}
		for (int l1702 = 0; (l1702 < 2); l1702 = (l1702 + 1)) {
			fRec2475[l1702] = 0.0;
			
		}
		for (int l1703 = 0; (l1703 < 2); l1703 = (l1703 + 1)) {
			fRec2473[l1703] = 0.0;
			
		}
		for (int l1704 = 0; (l1704 < 2); l1704 = (l1704 + 1)) {
			fRec2472[l1704] = 0.0;
			
		}
		for (int l1705 = 0; (l1705 < 2); l1705 = (l1705 + 1)) {
			fRec2470[l1705] = 0.0;
			
		}
		for (int l1706 = 0; (l1706 < 2); l1706 = (l1706 + 1)) {
			fRec2469[l1706] = 0.0;
			
		}
		for (int l1707 = 0; (l1707 < 2); l1707 = (l1707 + 1)) {
			fRec2467[l1707] = 0.0;
			
		}
		for (int l1708 = 0; (l1708 < 2); l1708 = (l1708 + 1)) {
			fRec2466[l1708] = 0.0;
			
		}
		for (int l1709 = 0; (l1709 < 2); l1709 = (l1709 + 1)) {
			fRec2464[l1709] = 0.0;
			
		}
		for (int l1710 = 0; (l1710 < 2); l1710 = (l1710 + 1)) {
			fRec2463[l1710] = 0.0;
			
		}
		for (int l1711 = 0; (l1711 < 2); l1711 = (l1711 + 1)) {
			fRec2461[l1711] = 0.0;
			
		}
		for (int l1712 = 0; (l1712 < 2); l1712 = (l1712 + 1)) {
			fRec2493[l1712] = 0.0;
			
		}
		for (int l1713 = 0; (l1713 < 2); l1713 = (l1713 + 1)) {
			fRec2491[l1713] = 0.0;
			
		}
		for (int l1714 = 0; (l1714 < 2); l1714 = (l1714 + 1)) {
			fRec2490[l1714] = 0.0;
			
		}
		for (int l1715 = 0; (l1715 < 2); l1715 = (l1715 + 1)) {
			fRec2488[l1715] = 0.0;
			
		}
		for (int l1716 = 0; (l1716 < 2); l1716 = (l1716 + 1)) {
			fRec2487[l1716] = 0.0;
			
		}
		for (int l1717 = 0; (l1717 < 2); l1717 = (l1717 + 1)) {
			fRec2485[l1717] = 0.0;
			
		}
		for (int l1718 = 0; (l1718 < 2); l1718 = (l1718 + 1)) {
			fRec2484[l1718] = 0.0;
			
		}
		for (int l1719 = 0; (l1719 < 2); l1719 = (l1719 + 1)) {
			fRec2482[l1719] = 0.0;
			
		}
		for (int l1720 = 0; (l1720 < 2); l1720 = (l1720 + 1)) {
			fRec2481[l1720] = 0.0;
			
		}
		for (int l1721 = 0; (l1721 < 2); l1721 = (l1721 + 1)) {
			fRec2479[l1721] = 0.0;
			
		}
		for (int l1722 = 0; (l1722 < 2); l1722 = (l1722 + 1)) {
			fRec2505[l1722] = 0.0;
			
		}
		for (int l1723 = 0; (l1723 < 2); l1723 = (l1723 + 1)) {
			fRec2503[l1723] = 0.0;
			
		}
		for (int l1724 = 0; (l1724 < 2); l1724 = (l1724 + 1)) {
			fRec2502[l1724] = 0.0;
			
		}
		for (int l1725 = 0; (l1725 < 2); l1725 = (l1725 + 1)) {
			fRec2500[l1725] = 0.0;
			
		}
		for (int l1726 = 0; (l1726 < 2); l1726 = (l1726 + 1)) {
			fRec2499[l1726] = 0.0;
			
		}
		for (int l1727 = 0; (l1727 < 2); l1727 = (l1727 + 1)) {
			fRec2497[l1727] = 0.0;
			
		}
		for (int l1728 = 0; (l1728 < 2); l1728 = (l1728 + 1)) {
			fRec2496[l1728] = 0.0;
			
		}
		for (int l1729 = 0; (l1729 < 2); l1729 = (l1729 + 1)) {
			fRec2494[l1729] = 0.0;
			
		}
		for (int l1730 = 0; (l1730 < 2); l1730 = (l1730 + 1)) {
			fRec2514[l1730] = 0.0;
			
		}
		for (int l1731 = 0; (l1731 < 2); l1731 = (l1731 + 1)) {
			fRec2512[l1731] = 0.0;
			
		}
		for (int l1732 = 0; (l1732 < 2); l1732 = (l1732 + 1)) {
			fRec2511[l1732] = 0.0;
			
		}
		for (int l1733 = 0; (l1733 < 2); l1733 = (l1733 + 1)) {
			fRec2509[l1733] = 0.0;
			
		}
		for (int l1734 = 0; (l1734 < 2); l1734 = (l1734 + 1)) {
			fRec2508[l1734] = 0.0;
			
		}
		for (int l1735 = 0; (l1735 < 2); l1735 = (l1735 + 1)) {
			fRec2506[l1735] = 0.0;
			
		}
		for (int l1736 = 0; (l1736 < 2); l1736 = (l1736 + 1)) {
			fRec2517[l1736] = 0.0;
			
		}
		for (int l1737 = 0; (l1737 < 2); l1737 = (l1737 + 1)) {
			fRec2515[l1737] = 0.0;
			
		}
		for (int l1738 = 0; (l1738 < 2); l1738 = (l1738 + 1)) {
			fRec2523[l1738] = 0.0;
			
		}
		for (int l1739 = 0; (l1739 < 2); l1739 = (l1739 + 1)) {
			fRec2521[l1739] = 0.0;
			
		}
		for (int l1740 = 0; (l1740 < 2); l1740 = (l1740 + 1)) {
			fRec2520[l1740] = 0.0;
			
		}
		for (int l1741 = 0; (l1741 < 2); l1741 = (l1741 + 1)) {
			fRec2518[l1741] = 0.0;
			
		}
		for (int l1742 = 0; (l1742 < 512); l1742 = (l1742 + 1)) {
			fVec37[l1742] = 0.0;
			
		}
		for (int l1743 = 0; (l1743 < 2); l1743 = (l1743 + 1)) {
			fRec2541[l1743] = 0.0;
			
		}
		for (int l1744 = 0; (l1744 < 2); l1744 = (l1744 + 1)) {
			fRec2539[l1744] = 0.0;
			
		}
		for (int l1745 = 0; (l1745 < 2); l1745 = (l1745 + 1)) {
			fRec2538[l1745] = 0.0;
			
		}
		for (int l1746 = 0; (l1746 < 2); l1746 = (l1746 + 1)) {
			fRec2536[l1746] = 0.0;
			
		}
		for (int l1747 = 0; (l1747 < 2); l1747 = (l1747 + 1)) {
			fRec2535[l1747] = 0.0;
			
		}
		for (int l1748 = 0; (l1748 < 2); l1748 = (l1748 + 1)) {
			fRec2533[l1748] = 0.0;
			
		}
		for (int l1749 = 0; (l1749 < 2); l1749 = (l1749 + 1)) {
			fRec2532[l1749] = 0.0;
			
		}
		for (int l1750 = 0; (l1750 < 2); l1750 = (l1750 + 1)) {
			fRec2530[l1750] = 0.0;
			
		}
		for (int l1751 = 0; (l1751 < 2); l1751 = (l1751 + 1)) {
			fRec2529[l1751] = 0.0;
			
		}
		for (int l1752 = 0; (l1752 < 2); l1752 = (l1752 + 1)) {
			fRec2527[l1752] = 0.0;
			
		}
		for (int l1753 = 0; (l1753 < 2); l1753 = (l1753 + 1)) {
			fRec2526[l1753] = 0.0;
			
		}
		for (int l1754 = 0; (l1754 < 2); l1754 = (l1754 + 1)) {
			fRec2524[l1754] = 0.0;
			
		}
		for (int l1755 = 0; (l1755 < 2); l1755 = (l1755 + 1)) {
			fRec2556[l1755] = 0.0;
			
		}
		for (int l1756 = 0; (l1756 < 2); l1756 = (l1756 + 1)) {
			fRec2554[l1756] = 0.0;
			
		}
		for (int l1757 = 0; (l1757 < 2); l1757 = (l1757 + 1)) {
			fRec2553[l1757] = 0.0;
			
		}
		for (int l1758 = 0; (l1758 < 2); l1758 = (l1758 + 1)) {
			fRec2551[l1758] = 0.0;
			
		}
		for (int l1759 = 0; (l1759 < 2); l1759 = (l1759 + 1)) {
			fRec2550[l1759] = 0.0;
			
		}
		for (int l1760 = 0; (l1760 < 2); l1760 = (l1760 + 1)) {
			fRec2548[l1760] = 0.0;
			
		}
		for (int l1761 = 0; (l1761 < 2); l1761 = (l1761 + 1)) {
			fRec2547[l1761] = 0.0;
			
		}
		for (int l1762 = 0; (l1762 < 2); l1762 = (l1762 + 1)) {
			fRec2545[l1762] = 0.0;
			
		}
		for (int l1763 = 0; (l1763 < 2); l1763 = (l1763 + 1)) {
			fRec2544[l1763] = 0.0;
			
		}
		for (int l1764 = 0; (l1764 < 2); l1764 = (l1764 + 1)) {
			fRec2542[l1764] = 0.0;
			
		}
		for (int l1765 = 0; (l1765 < 2); l1765 = (l1765 + 1)) {
			fRec2568[l1765] = 0.0;
			
		}
		for (int l1766 = 0; (l1766 < 2); l1766 = (l1766 + 1)) {
			fRec2566[l1766] = 0.0;
			
		}
		for (int l1767 = 0; (l1767 < 2); l1767 = (l1767 + 1)) {
			fRec2565[l1767] = 0.0;
			
		}
		for (int l1768 = 0; (l1768 < 2); l1768 = (l1768 + 1)) {
			fRec2563[l1768] = 0.0;
			
		}
		for (int l1769 = 0; (l1769 < 2); l1769 = (l1769 + 1)) {
			fRec2562[l1769] = 0.0;
			
		}
		for (int l1770 = 0; (l1770 < 2); l1770 = (l1770 + 1)) {
			fRec2560[l1770] = 0.0;
			
		}
		for (int l1771 = 0; (l1771 < 2); l1771 = (l1771 + 1)) {
			fRec2559[l1771] = 0.0;
			
		}
		for (int l1772 = 0; (l1772 < 2); l1772 = (l1772 + 1)) {
			fRec2557[l1772] = 0.0;
			
		}
		for (int l1773 = 0; (l1773 < 2); l1773 = (l1773 + 1)) {
			fRec2577[l1773] = 0.0;
			
		}
		for (int l1774 = 0; (l1774 < 2); l1774 = (l1774 + 1)) {
			fRec2575[l1774] = 0.0;
			
		}
		for (int l1775 = 0; (l1775 < 2); l1775 = (l1775 + 1)) {
			fRec2574[l1775] = 0.0;
			
		}
		for (int l1776 = 0; (l1776 < 2); l1776 = (l1776 + 1)) {
			fRec2572[l1776] = 0.0;
			
		}
		for (int l1777 = 0; (l1777 < 2); l1777 = (l1777 + 1)) {
			fRec2571[l1777] = 0.0;
			
		}
		for (int l1778 = 0; (l1778 < 2); l1778 = (l1778 + 1)) {
			fRec2569[l1778] = 0.0;
			
		}
		for (int l1779 = 0; (l1779 < 2); l1779 = (l1779 + 1)) {
			fRec2580[l1779] = 0.0;
			
		}
		for (int l1780 = 0; (l1780 < 2); l1780 = (l1780 + 1)) {
			fRec2578[l1780] = 0.0;
			
		}
		for (int l1781 = 0; (l1781 < 2); l1781 = (l1781 + 1)) {
			fRec2586[l1781] = 0.0;
			
		}
		for (int l1782 = 0; (l1782 < 2); l1782 = (l1782 + 1)) {
			fRec2584[l1782] = 0.0;
			
		}
		for (int l1783 = 0; (l1783 < 2); l1783 = (l1783 + 1)) {
			fRec2583[l1783] = 0.0;
			
		}
		for (int l1784 = 0; (l1784 < 2); l1784 = (l1784 + 1)) {
			fRec2581[l1784] = 0.0;
			
		}
		for (int l1785 = 0; (l1785 < 512); l1785 = (l1785 + 1)) {
			fVec38[l1785] = 0.0;
			
		}
		for (int l1786 = 0; (l1786 < 2); l1786 = (l1786 + 1)) {
			fRec2604[l1786] = 0.0;
			
		}
		for (int l1787 = 0; (l1787 < 2); l1787 = (l1787 + 1)) {
			fRec2602[l1787] = 0.0;
			
		}
		for (int l1788 = 0; (l1788 < 2); l1788 = (l1788 + 1)) {
			fRec2601[l1788] = 0.0;
			
		}
		for (int l1789 = 0; (l1789 < 2); l1789 = (l1789 + 1)) {
			fRec2599[l1789] = 0.0;
			
		}
		for (int l1790 = 0; (l1790 < 2); l1790 = (l1790 + 1)) {
			fRec2598[l1790] = 0.0;
			
		}
		for (int l1791 = 0; (l1791 < 2); l1791 = (l1791 + 1)) {
			fRec2596[l1791] = 0.0;
			
		}
		for (int l1792 = 0; (l1792 < 2); l1792 = (l1792 + 1)) {
			fRec2595[l1792] = 0.0;
			
		}
		for (int l1793 = 0; (l1793 < 2); l1793 = (l1793 + 1)) {
			fRec2593[l1793] = 0.0;
			
		}
		for (int l1794 = 0; (l1794 < 2); l1794 = (l1794 + 1)) {
			fRec2592[l1794] = 0.0;
			
		}
		for (int l1795 = 0; (l1795 < 2); l1795 = (l1795 + 1)) {
			fRec2590[l1795] = 0.0;
			
		}
		for (int l1796 = 0; (l1796 < 2); l1796 = (l1796 + 1)) {
			fRec2589[l1796] = 0.0;
			
		}
		for (int l1797 = 0; (l1797 < 2); l1797 = (l1797 + 1)) {
			fRec2587[l1797] = 0.0;
			
		}
		for (int l1798 = 0; (l1798 < 2); l1798 = (l1798 + 1)) {
			fRec2619[l1798] = 0.0;
			
		}
		for (int l1799 = 0; (l1799 < 2); l1799 = (l1799 + 1)) {
			fRec2617[l1799] = 0.0;
			
		}
		for (int l1800 = 0; (l1800 < 2); l1800 = (l1800 + 1)) {
			fRec2616[l1800] = 0.0;
			
		}
		for (int l1801 = 0; (l1801 < 2); l1801 = (l1801 + 1)) {
			fRec2614[l1801] = 0.0;
			
		}
		for (int l1802 = 0; (l1802 < 2); l1802 = (l1802 + 1)) {
			fRec2613[l1802] = 0.0;
			
		}
		for (int l1803 = 0; (l1803 < 2); l1803 = (l1803 + 1)) {
			fRec2611[l1803] = 0.0;
			
		}
		for (int l1804 = 0; (l1804 < 2); l1804 = (l1804 + 1)) {
			fRec2610[l1804] = 0.0;
			
		}
		for (int l1805 = 0; (l1805 < 2); l1805 = (l1805 + 1)) {
			fRec2608[l1805] = 0.0;
			
		}
		for (int l1806 = 0; (l1806 < 2); l1806 = (l1806 + 1)) {
			fRec2607[l1806] = 0.0;
			
		}
		for (int l1807 = 0; (l1807 < 2); l1807 = (l1807 + 1)) {
			fRec2605[l1807] = 0.0;
			
		}
		for (int l1808 = 0; (l1808 < 2); l1808 = (l1808 + 1)) {
			fRec2631[l1808] = 0.0;
			
		}
		for (int l1809 = 0; (l1809 < 2); l1809 = (l1809 + 1)) {
			fRec2629[l1809] = 0.0;
			
		}
		for (int l1810 = 0; (l1810 < 2); l1810 = (l1810 + 1)) {
			fRec2628[l1810] = 0.0;
			
		}
		for (int l1811 = 0; (l1811 < 2); l1811 = (l1811 + 1)) {
			fRec2626[l1811] = 0.0;
			
		}
		for (int l1812 = 0; (l1812 < 2); l1812 = (l1812 + 1)) {
			fRec2625[l1812] = 0.0;
			
		}
		for (int l1813 = 0; (l1813 < 2); l1813 = (l1813 + 1)) {
			fRec2623[l1813] = 0.0;
			
		}
		for (int l1814 = 0; (l1814 < 2); l1814 = (l1814 + 1)) {
			fRec2622[l1814] = 0.0;
			
		}
		for (int l1815 = 0; (l1815 < 2); l1815 = (l1815 + 1)) {
			fRec2620[l1815] = 0.0;
			
		}
		for (int l1816 = 0; (l1816 < 2); l1816 = (l1816 + 1)) {
			fRec2640[l1816] = 0.0;
			
		}
		for (int l1817 = 0; (l1817 < 2); l1817 = (l1817 + 1)) {
			fRec2638[l1817] = 0.0;
			
		}
		for (int l1818 = 0; (l1818 < 2); l1818 = (l1818 + 1)) {
			fRec2637[l1818] = 0.0;
			
		}
		for (int l1819 = 0; (l1819 < 2); l1819 = (l1819 + 1)) {
			fRec2635[l1819] = 0.0;
			
		}
		for (int l1820 = 0; (l1820 < 2); l1820 = (l1820 + 1)) {
			fRec2634[l1820] = 0.0;
			
		}
		for (int l1821 = 0; (l1821 < 2); l1821 = (l1821 + 1)) {
			fRec2632[l1821] = 0.0;
			
		}
		for (int l1822 = 0; (l1822 < 2); l1822 = (l1822 + 1)) {
			fRec2643[l1822] = 0.0;
			
		}
		for (int l1823 = 0; (l1823 < 2); l1823 = (l1823 + 1)) {
			fRec2641[l1823] = 0.0;
			
		}
		for (int l1824 = 0; (l1824 < 2); l1824 = (l1824 + 1)) {
			fRec2649[l1824] = 0.0;
			
		}
		for (int l1825 = 0; (l1825 < 2); l1825 = (l1825 + 1)) {
			fRec2647[l1825] = 0.0;
			
		}
		for (int l1826 = 0; (l1826 < 2); l1826 = (l1826 + 1)) {
			fRec2646[l1826] = 0.0;
			
		}
		for (int l1827 = 0; (l1827 < 2); l1827 = (l1827 + 1)) {
			fRec2644[l1827] = 0.0;
			
		}
		for (int l1828 = 0; (l1828 < 512); l1828 = (l1828 + 1)) {
			fVec39[l1828] = 0.0;
			
		}
		for (int l1829 = 0; (l1829 < 2); l1829 = (l1829 + 1)) {
			fRec2667[l1829] = 0.0;
			
		}
		for (int l1830 = 0; (l1830 < 2); l1830 = (l1830 + 1)) {
			fRec2665[l1830] = 0.0;
			
		}
		for (int l1831 = 0; (l1831 < 2); l1831 = (l1831 + 1)) {
			fRec2664[l1831] = 0.0;
			
		}
		for (int l1832 = 0; (l1832 < 2); l1832 = (l1832 + 1)) {
			fRec2662[l1832] = 0.0;
			
		}
		for (int l1833 = 0; (l1833 < 2); l1833 = (l1833 + 1)) {
			fRec2661[l1833] = 0.0;
			
		}
		for (int l1834 = 0; (l1834 < 2); l1834 = (l1834 + 1)) {
			fRec2659[l1834] = 0.0;
			
		}
		for (int l1835 = 0; (l1835 < 2); l1835 = (l1835 + 1)) {
			fRec2658[l1835] = 0.0;
			
		}
		for (int l1836 = 0; (l1836 < 2); l1836 = (l1836 + 1)) {
			fRec2656[l1836] = 0.0;
			
		}
		for (int l1837 = 0; (l1837 < 2); l1837 = (l1837 + 1)) {
			fRec2655[l1837] = 0.0;
			
		}
		for (int l1838 = 0; (l1838 < 2); l1838 = (l1838 + 1)) {
			fRec2653[l1838] = 0.0;
			
		}
		for (int l1839 = 0; (l1839 < 2); l1839 = (l1839 + 1)) {
			fRec2652[l1839] = 0.0;
			
		}
		for (int l1840 = 0; (l1840 < 2); l1840 = (l1840 + 1)) {
			fRec2650[l1840] = 0.0;
			
		}
		for (int l1841 = 0; (l1841 < 2); l1841 = (l1841 + 1)) {
			fRec2682[l1841] = 0.0;
			
		}
		for (int l1842 = 0; (l1842 < 2); l1842 = (l1842 + 1)) {
			fRec2680[l1842] = 0.0;
			
		}
		for (int l1843 = 0; (l1843 < 2); l1843 = (l1843 + 1)) {
			fRec2679[l1843] = 0.0;
			
		}
		for (int l1844 = 0; (l1844 < 2); l1844 = (l1844 + 1)) {
			fRec2677[l1844] = 0.0;
			
		}
		for (int l1845 = 0; (l1845 < 2); l1845 = (l1845 + 1)) {
			fRec2676[l1845] = 0.0;
			
		}
		for (int l1846 = 0; (l1846 < 2); l1846 = (l1846 + 1)) {
			fRec2674[l1846] = 0.0;
			
		}
		for (int l1847 = 0; (l1847 < 2); l1847 = (l1847 + 1)) {
			fRec2673[l1847] = 0.0;
			
		}
		for (int l1848 = 0; (l1848 < 2); l1848 = (l1848 + 1)) {
			fRec2671[l1848] = 0.0;
			
		}
		for (int l1849 = 0; (l1849 < 2); l1849 = (l1849 + 1)) {
			fRec2670[l1849] = 0.0;
			
		}
		for (int l1850 = 0; (l1850 < 2); l1850 = (l1850 + 1)) {
			fRec2668[l1850] = 0.0;
			
		}
		for (int l1851 = 0; (l1851 < 2); l1851 = (l1851 + 1)) {
			fRec2694[l1851] = 0.0;
			
		}
		for (int l1852 = 0; (l1852 < 2); l1852 = (l1852 + 1)) {
			fRec2692[l1852] = 0.0;
			
		}
		for (int l1853 = 0; (l1853 < 2); l1853 = (l1853 + 1)) {
			fRec2691[l1853] = 0.0;
			
		}
		for (int l1854 = 0; (l1854 < 2); l1854 = (l1854 + 1)) {
			fRec2689[l1854] = 0.0;
			
		}
		for (int l1855 = 0; (l1855 < 2); l1855 = (l1855 + 1)) {
			fRec2688[l1855] = 0.0;
			
		}
		for (int l1856 = 0; (l1856 < 2); l1856 = (l1856 + 1)) {
			fRec2686[l1856] = 0.0;
			
		}
		for (int l1857 = 0; (l1857 < 2); l1857 = (l1857 + 1)) {
			fRec2685[l1857] = 0.0;
			
		}
		for (int l1858 = 0; (l1858 < 2); l1858 = (l1858 + 1)) {
			fRec2683[l1858] = 0.0;
			
		}
		for (int l1859 = 0; (l1859 < 2); l1859 = (l1859 + 1)) {
			fRec2703[l1859] = 0.0;
			
		}
		for (int l1860 = 0; (l1860 < 2); l1860 = (l1860 + 1)) {
			fRec2701[l1860] = 0.0;
			
		}
		for (int l1861 = 0; (l1861 < 2); l1861 = (l1861 + 1)) {
			fRec2700[l1861] = 0.0;
			
		}
		for (int l1862 = 0; (l1862 < 2); l1862 = (l1862 + 1)) {
			fRec2698[l1862] = 0.0;
			
		}
		for (int l1863 = 0; (l1863 < 2); l1863 = (l1863 + 1)) {
			fRec2697[l1863] = 0.0;
			
		}
		for (int l1864 = 0; (l1864 < 2); l1864 = (l1864 + 1)) {
			fRec2695[l1864] = 0.0;
			
		}
		for (int l1865 = 0; (l1865 < 2); l1865 = (l1865 + 1)) {
			fRec2706[l1865] = 0.0;
			
		}
		for (int l1866 = 0; (l1866 < 2); l1866 = (l1866 + 1)) {
			fRec2704[l1866] = 0.0;
			
		}
		for (int l1867 = 0; (l1867 < 2); l1867 = (l1867 + 1)) {
			fRec2712[l1867] = 0.0;
			
		}
		for (int l1868 = 0; (l1868 < 2); l1868 = (l1868 + 1)) {
			fRec2710[l1868] = 0.0;
			
		}
		for (int l1869 = 0; (l1869 < 2); l1869 = (l1869 + 1)) {
			fRec2709[l1869] = 0.0;
			
		}
		for (int l1870 = 0; (l1870 < 2); l1870 = (l1870 + 1)) {
			fRec2707[l1870] = 0.0;
			
		}
		for (int l1871 = 0; (l1871 < 512); l1871 = (l1871 + 1)) {
			fVec40[l1871] = 0.0;
			
		}
		for (int l1872 = 0; (l1872 < 2); l1872 = (l1872 + 1)) {
			fRec2730[l1872] = 0.0;
			
		}
		for (int l1873 = 0; (l1873 < 2); l1873 = (l1873 + 1)) {
			fRec2728[l1873] = 0.0;
			
		}
		for (int l1874 = 0; (l1874 < 2); l1874 = (l1874 + 1)) {
			fRec2727[l1874] = 0.0;
			
		}
		for (int l1875 = 0; (l1875 < 2); l1875 = (l1875 + 1)) {
			fRec2725[l1875] = 0.0;
			
		}
		for (int l1876 = 0; (l1876 < 2); l1876 = (l1876 + 1)) {
			fRec2724[l1876] = 0.0;
			
		}
		for (int l1877 = 0; (l1877 < 2); l1877 = (l1877 + 1)) {
			fRec2722[l1877] = 0.0;
			
		}
		for (int l1878 = 0; (l1878 < 2); l1878 = (l1878 + 1)) {
			fRec2721[l1878] = 0.0;
			
		}
		for (int l1879 = 0; (l1879 < 2); l1879 = (l1879 + 1)) {
			fRec2719[l1879] = 0.0;
			
		}
		for (int l1880 = 0; (l1880 < 2); l1880 = (l1880 + 1)) {
			fRec2718[l1880] = 0.0;
			
		}
		for (int l1881 = 0; (l1881 < 2); l1881 = (l1881 + 1)) {
			fRec2716[l1881] = 0.0;
			
		}
		for (int l1882 = 0; (l1882 < 2); l1882 = (l1882 + 1)) {
			fRec2715[l1882] = 0.0;
			
		}
		for (int l1883 = 0; (l1883 < 2); l1883 = (l1883 + 1)) {
			fRec2713[l1883] = 0.0;
			
		}
		for (int l1884 = 0; (l1884 < 2); l1884 = (l1884 + 1)) {
			fRec2745[l1884] = 0.0;
			
		}
		for (int l1885 = 0; (l1885 < 2); l1885 = (l1885 + 1)) {
			fRec2743[l1885] = 0.0;
			
		}
		for (int l1886 = 0; (l1886 < 2); l1886 = (l1886 + 1)) {
			fRec2742[l1886] = 0.0;
			
		}
		for (int l1887 = 0; (l1887 < 2); l1887 = (l1887 + 1)) {
			fRec2740[l1887] = 0.0;
			
		}
		for (int l1888 = 0; (l1888 < 2); l1888 = (l1888 + 1)) {
			fRec2739[l1888] = 0.0;
			
		}
		for (int l1889 = 0; (l1889 < 2); l1889 = (l1889 + 1)) {
			fRec2737[l1889] = 0.0;
			
		}
		for (int l1890 = 0; (l1890 < 2); l1890 = (l1890 + 1)) {
			fRec2736[l1890] = 0.0;
			
		}
		for (int l1891 = 0; (l1891 < 2); l1891 = (l1891 + 1)) {
			fRec2734[l1891] = 0.0;
			
		}
		for (int l1892 = 0; (l1892 < 2); l1892 = (l1892 + 1)) {
			fRec2733[l1892] = 0.0;
			
		}
		for (int l1893 = 0; (l1893 < 2); l1893 = (l1893 + 1)) {
			fRec2731[l1893] = 0.0;
			
		}
		for (int l1894 = 0; (l1894 < 2); l1894 = (l1894 + 1)) {
			fRec2757[l1894] = 0.0;
			
		}
		for (int l1895 = 0; (l1895 < 2); l1895 = (l1895 + 1)) {
			fRec2755[l1895] = 0.0;
			
		}
		for (int l1896 = 0; (l1896 < 2); l1896 = (l1896 + 1)) {
			fRec2754[l1896] = 0.0;
			
		}
		for (int l1897 = 0; (l1897 < 2); l1897 = (l1897 + 1)) {
			fRec2752[l1897] = 0.0;
			
		}
		for (int l1898 = 0; (l1898 < 2); l1898 = (l1898 + 1)) {
			fRec2751[l1898] = 0.0;
			
		}
		for (int l1899 = 0; (l1899 < 2); l1899 = (l1899 + 1)) {
			fRec2749[l1899] = 0.0;
			
		}
		for (int l1900 = 0; (l1900 < 2); l1900 = (l1900 + 1)) {
			fRec2748[l1900] = 0.0;
			
		}
		for (int l1901 = 0; (l1901 < 2); l1901 = (l1901 + 1)) {
			fRec2746[l1901] = 0.0;
			
		}
		for (int l1902 = 0; (l1902 < 2); l1902 = (l1902 + 1)) {
			fRec2766[l1902] = 0.0;
			
		}
		for (int l1903 = 0; (l1903 < 2); l1903 = (l1903 + 1)) {
			fRec2764[l1903] = 0.0;
			
		}
		for (int l1904 = 0; (l1904 < 2); l1904 = (l1904 + 1)) {
			fRec2763[l1904] = 0.0;
			
		}
		for (int l1905 = 0; (l1905 < 2); l1905 = (l1905 + 1)) {
			fRec2761[l1905] = 0.0;
			
		}
		for (int l1906 = 0; (l1906 < 2); l1906 = (l1906 + 1)) {
			fRec2760[l1906] = 0.0;
			
		}
		for (int l1907 = 0; (l1907 < 2); l1907 = (l1907 + 1)) {
			fRec2758[l1907] = 0.0;
			
		}
		for (int l1908 = 0; (l1908 < 2); l1908 = (l1908 + 1)) {
			fRec2769[l1908] = 0.0;
			
		}
		for (int l1909 = 0; (l1909 < 2); l1909 = (l1909 + 1)) {
			fRec2767[l1909] = 0.0;
			
		}
		for (int l1910 = 0; (l1910 < 2); l1910 = (l1910 + 1)) {
			fRec2775[l1910] = 0.0;
			
		}
		for (int l1911 = 0; (l1911 < 2); l1911 = (l1911 + 1)) {
			fRec2773[l1911] = 0.0;
			
		}
		for (int l1912 = 0; (l1912 < 2); l1912 = (l1912 + 1)) {
			fRec2772[l1912] = 0.0;
			
		}
		for (int l1913 = 0; (l1913 < 2); l1913 = (l1913 + 1)) {
			fRec2770[l1913] = 0.0;
			
		}
		for (int l1914 = 0; (l1914 < 512); l1914 = (l1914 + 1)) {
			fVec41[l1914] = 0.0;
			
		}
		for (int l1915 = 0; (l1915 < 2); l1915 = (l1915 + 1)) {
			fRec2793[l1915] = 0.0;
			
		}
		for (int l1916 = 0; (l1916 < 2); l1916 = (l1916 + 1)) {
			fRec2791[l1916] = 0.0;
			
		}
		for (int l1917 = 0; (l1917 < 2); l1917 = (l1917 + 1)) {
			fRec2790[l1917] = 0.0;
			
		}
		for (int l1918 = 0; (l1918 < 2); l1918 = (l1918 + 1)) {
			fRec2788[l1918] = 0.0;
			
		}
		for (int l1919 = 0; (l1919 < 2); l1919 = (l1919 + 1)) {
			fRec2787[l1919] = 0.0;
			
		}
		for (int l1920 = 0; (l1920 < 2); l1920 = (l1920 + 1)) {
			fRec2785[l1920] = 0.0;
			
		}
		for (int l1921 = 0; (l1921 < 2); l1921 = (l1921 + 1)) {
			fRec2784[l1921] = 0.0;
			
		}
		for (int l1922 = 0; (l1922 < 2); l1922 = (l1922 + 1)) {
			fRec2782[l1922] = 0.0;
			
		}
		for (int l1923 = 0; (l1923 < 2); l1923 = (l1923 + 1)) {
			fRec2781[l1923] = 0.0;
			
		}
		for (int l1924 = 0; (l1924 < 2); l1924 = (l1924 + 1)) {
			fRec2779[l1924] = 0.0;
			
		}
		for (int l1925 = 0; (l1925 < 2); l1925 = (l1925 + 1)) {
			fRec2778[l1925] = 0.0;
			
		}
		for (int l1926 = 0; (l1926 < 2); l1926 = (l1926 + 1)) {
			fRec2776[l1926] = 0.0;
			
		}
		for (int l1927 = 0; (l1927 < 2); l1927 = (l1927 + 1)) {
			fRec2808[l1927] = 0.0;
			
		}
		for (int l1928 = 0; (l1928 < 2); l1928 = (l1928 + 1)) {
			fRec2806[l1928] = 0.0;
			
		}
		for (int l1929 = 0; (l1929 < 2); l1929 = (l1929 + 1)) {
			fRec2805[l1929] = 0.0;
			
		}
		for (int l1930 = 0; (l1930 < 2); l1930 = (l1930 + 1)) {
			fRec2803[l1930] = 0.0;
			
		}
		for (int l1931 = 0; (l1931 < 2); l1931 = (l1931 + 1)) {
			fRec2802[l1931] = 0.0;
			
		}
		for (int l1932 = 0; (l1932 < 2); l1932 = (l1932 + 1)) {
			fRec2800[l1932] = 0.0;
			
		}
		for (int l1933 = 0; (l1933 < 2); l1933 = (l1933 + 1)) {
			fRec2799[l1933] = 0.0;
			
		}
		for (int l1934 = 0; (l1934 < 2); l1934 = (l1934 + 1)) {
			fRec2797[l1934] = 0.0;
			
		}
		for (int l1935 = 0; (l1935 < 2); l1935 = (l1935 + 1)) {
			fRec2796[l1935] = 0.0;
			
		}
		for (int l1936 = 0; (l1936 < 2); l1936 = (l1936 + 1)) {
			fRec2794[l1936] = 0.0;
			
		}
		for (int l1937 = 0; (l1937 < 2); l1937 = (l1937 + 1)) {
			fRec2820[l1937] = 0.0;
			
		}
		for (int l1938 = 0; (l1938 < 2); l1938 = (l1938 + 1)) {
			fRec2818[l1938] = 0.0;
			
		}
		for (int l1939 = 0; (l1939 < 2); l1939 = (l1939 + 1)) {
			fRec2817[l1939] = 0.0;
			
		}
		for (int l1940 = 0; (l1940 < 2); l1940 = (l1940 + 1)) {
			fRec2815[l1940] = 0.0;
			
		}
		for (int l1941 = 0; (l1941 < 2); l1941 = (l1941 + 1)) {
			fRec2814[l1941] = 0.0;
			
		}
		for (int l1942 = 0; (l1942 < 2); l1942 = (l1942 + 1)) {
			fRec2812[l1942] = 0.0;
			
		}
		for (int l1943 = 0; (l1943 < 2); l1943 = (l1943 + 1)) {
			fRec2811[l1943] = 0.0;
			
		}
		for (int l1944 = 0; (l1944 < 2); l1944 = (l1944 + 1)) {
			fRec2809[l1944] = 0.0;
			
		}
		for (int l1945 = 0; (l1945 < 2); l1945 = (l1945 + 1)) {
			fRec2829[l1945] = 0.0;
			
		}
		for (int l1946 = 0; (l1946 < 2); l1946 = (l1946 + 1)) {
			fRec2827[l1946] = 0.0;
			
		}
		for (int l1947 = 0; (l1947 < 2); l1947 = (l1947 + 1)) {
			fRec2826[l1947] = 0.0;
			
		}
		for (int l1948 = 0; (l1948 < 2); l1948 = (l1948 + 1)) {
			fRec2824[l1948] = 0.0;
			
		}
		for (int l1949 = 0; (l1949 < 2); l1949 = (l1949 + 1)) {
			fRec2823[l1949] = 0.0;
			
		}
		for (int l1950 = 0; (l1950 < 2); l1950 = (l1950 + 1)) {
			fRec2821[l1950] = 0.0;
			
		}
		for (int l1951 = 0; (l1951 < 2); l1951 = (l1951 + 1)) {
			fRec2832[l1951] = 0.0;
			
		}
		for (int l1952 = 0; (l1952 < 2); l1952 = (l1952 + 1)) {
			fRec2830[l1952] = 0.0;
			
		}
		for (int l1953 = 0; (l1953 < 2); l1953 = (l1953 + 1)) {
			fRec2838[l1953] = 0.0;
			
		}
		for (int l1954 = 0; (l1954 < 2); l1954 = (l1954 + 1)) {
			fRec2836[l1954] = 0.0;
			
		}
		for (int l1955 = 0; (l1955 < 2); l1955 = (l1955 + 1)) {
			fRec2835[l1955] = 0.0;
			
		}
		for (int l1956 = 0; (l1956 < 2); l1956 = (l1956 + 1)) {
			fRec2833[l1956] = 0.0;
			
		}
		for (int l1957 = 0; (l1957 < 512); l1957 = (l1957 + 1)) {
			fVec42[l1957] = 0.0;
			
		}
		for (int l1958 = 0; (l1958 < 2); l1958 = (l1958 + 1)) {
			fRec2856[l1958] = 0.0;
			
		}
		for (int l1959 = 0; (l1959 < 2); l1959 = (l1959 + 1)) {
			fRec2854[l1959] = 0.0;
			
		}
		for (int l1960 = 0; (l1960 < 2); l1960 = (l1960 + 1)) {
			fRec2853[l1960] = 0.0;
			
		}
		for (int l1961 = 0; (l1961 < 2); l1961 = (l1961 + 1)) {
			fRec2851[l1961] = 0.0;
			
		}
		for (int l1962 = 0; (l1962 < 2); l1962 = (l1962 + 1)) {
			fRec2850[l1962] = 0.0;
			
		}
		for (int l1963 = 0; (l1963 < 2); l1963 = (l1963 + 1)) {
			fRec2848[l1963] = 0.0;
			
		}
		for (int l1964 = 0; (l1964 < 2); l1964 = (l1964 + 1)) {
			fRec2847[l1964] = 0.0;
			
		}
		for (int l1965 = 0; (l1965 < 2); l1965 = (l1965 + 1)) {
			fRec2845[l1965] = 0.0;
			
		}
		for (int l1966 = 0; (l1966 < 2); l1966 = (l1966 + 1)) {
			fRec2844[l1966] = 0.0;
			
		}
		for (int l1967 = 0; (l1967 < 2); l1967 = (l1967 + 1)) {
			fRec2842[l1967] = 0.0;
			
		}
		for (int l1968 = 0; (l1968 < 2); l1968 = (l1968 + 1)) {
			fRec2841[l1968] = 0.0;
			
		}
		for (int l1969 = 0; (l1969 < 2); l1969 = (l1969 + 1)) {
			fRec2839[l1969] = 0.0;
			
		}
		for (int l1970 = 0; (l1970 < 2); l1970 = (l1970 + 1)) {
			fRec2871[l1970] = 0.0;
			
		}
		for (int l1971 = 0; (l1971 < 2); l1971 = (l1971 + 1)) {
			fRec2869[l1971] = 0.0;
			
		}
		for (int l1972 = 0; (l1972 < 2); l1972 = (l1972 + 1)) {
			fRec2868[l1972] = 0.0;
			
		}
		for (int l1973 = 0; (l1973 < 2); l1973 = (l1973 + 1)) {
			fRec2866[l1973] = 0.0;
			
		}
		for (int l1974 = 0; (l1974 < 2); l1974 = (l1974 + 1)) {
			fRec2865[l1974] = 0.0;
			
		}
		for (int l1975 = 0; (l1975 < 2); l1975 = (l1975 + 1)) {
			fRec2863[l1975] = 0.0;
			
		}
		for (int l1976 = 0; (l1976 < 2); l1976 = (l1976 + 1)) {
			fRec2862[l1976] = 0.0;
			
		}
		for (int l1977 = 0; (l1977 < 2); l1977 = (l1977 + 1)) {
			fRec2860[l1977] = 0.0;
			
		}
		for (int l1978 = 0; (l1978 < 2); l1978 = (l1978 + 1)) {
			fRec2859[l1978] = 0.0;
			
		}
		for (int l1979 = 0; (l1979 < 2); l1979 = (l1979 + 1)) {
			fRec2857[l1979] = 0.0;
			
		}
		for (int l1980 = 0; (l1980 < 2); l1980 = (l1980 + 1)) {
			fRec2883[l1980] = 0.0;
			
		}
		for (int l1981 = 0; (l1981 < 2); l1981 = (l1981 + 1)) {
			fRec2881[l1981] = 0.0;
			
		}
		for (int l1982 = 0; (l1982 < 2); l1982 = (l1982 + 1)) {
			fRec2880[l1982] = 0.0;
			
		}
		for (int l1983 = 0; (l1983 < 2); l1983 = (l1983 + 1)) {
			fRec2878[l1983] = 0.0;
			
		}
		for (int l1984 = 0; (l1984 < 2); l1984 = (l1984 + 1)) {
			fRec2877[l1984] = 0.0;
			
		}
		for (int l1985 = 0; (l1985 < 2); l1985 = (l1985 + 1)) {
			fRec2875[l1985] = 0.0;
			
		}
		for (int l1986 = 0; (l1986 < 2); l1986 = (l1986 + 1)) {
			fRec2874[l1986] = 0.0;
			
		}
		for (int l1987 = 0; (l1987 < 2); l1987 = (l1987 + 1)) {
			fRec2872[l1987] = 0.0;
			
		}
		for (int l1988 = 0; (l1988 < 2); l1988 = (l1988 + 1)) {
			fRec2892[l1988] = 0.0;
			
		}
		for (int l1989 = 0; (l1989 < 2); l1989 = (l1989 + 1)) {
			fRec2890[l1989] = 0.0;
			
		}
		for (int l1990 = 0; (l1990 < 2); l1990 = (l1990 + 1)) {
			fRec2889[l1990] = 0.0;
			
		}
		for (int l1991 = 0; (l1991 < 2); l1991 = (l1991 + 1)) {
			fRec2887[l1991] = 0.0;
			
		}
		for (int l1992 = 0; (l1992 < 2); l1992 = (l1992 + 1)) {
			fRec2886[l1992] = 0.0;
			
		}
		for (int l1993 = 0; (l1993 < 2); l1993 = (l1993 + 1)) {
			fRec2884[l1993] = 0.0;
			
		}
		for (int l1994 = 0; (l1994 < 2); l1994 = (l1994 + 1)) {
			fRec2895[l1994] = 0.0;
			
		}
		for (int l1995 = 0; (l1995 < 2); l1995 = (l1995 + 1)) {
			fRec2893[l1995] = 0.0;
			
		}
		for (int l1996 = 0; (l1996 < 2); l1996 = (l1996 + 1)) {
			fRec2901[l1996] = 0.0;
			
		}
		for (int l1997 = 0; (l1997 < 2); l1997 = (l1997 + 1)) {
			fRec2899[l1997] = 0.0;
			
		}
		for (int l1998 = 0; (l1998 < 2); l1998 = (l1998 + 1)) {
			fRec2898[l1998] = 0.0;
			
		}
		for (int l1999 = 0; (l1999 < 2); l1999 = (l1999 + 1)) {
			fRec2896[l1999] = 0.0;
			
		}
		for (int l2000 = 0; (l2000 < 512); l2000 = (l2000 + 1)) {
			fVec43[l2000] = 0.0;
			
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
		ui_interface->openVerticalBox("KMHLS_FullSetup_7h7v_full_6");
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
			fRec2[0] = (double(input61[i]) - (((fTemp2 * fRec2[2]) + (2.0 * (fTemp3 * fRec2[1]))) / fTemp4));
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
			fRec9[0] = (double(input0[i]) - (((fRec9[2] * fTemp2) + (2.0 * (fRec9[1] * fTemp3))) / fTemp4));
			double fTemp13 = (((fTemp1 * (fRec9[2] + (fRec9[0] + (2.0 * fRec9[1])))) / fTemp5) + (fRec3[0] * (0.0 - ((fRec9[1] * fTemp6) + ((fRec9[0] + fRec9[2]) / fTemp4)))));
			double fTemp14 = (fConst5 * fRec10[1]);
			double fTemp15 = (fConst6 * fRec13[1]);
			double fTemp16 = (fConst8 * fRec16[1]);
			double fTemp17 = (fConst9 * fRec19[1]);
			fRec28[0] = (double(input37[i]) - (((fTemp2 * fRec28[2]) + (2.0 * (fTemp3 * fRec28[1]))) / fTemp4));
			double fTemp18 = (((fTemp1 * (fRec28[2] + (fRec28[0] + (2.0 * fRec28[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec28[1]) + ((fRec28[0] + fRec28[2]) / fTemp4))))));
			fRec29[0] = (double(input41[i]) - (((fTemp2 * fRec29[2]) + (2.0 * (fTemp3 * fRec29[1]))) / fTemp4));
			double fTemp19 = (((fTemp1 * (fRec29[2] + (fRec29[0] + (2.0 * fRec29[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec29[1]) + ((fRec29[0] + fRec29[2]) / fTemp4))))));
			fRec30[0] = (double(input42[i]) - (((fTemp2 * fRec30[2]) + (2.0 * (fTemp3 * fRec30[1]))) / fTemp4));
			double fTemp20 = (((fTemp1 * (fRec30[2] + (fRec30[0] + (2.0 * fRec30[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec30[1]) + ((fRec30[0] + fRec30[2]) / fTemp4))))));
			fRec31[0] = (double(input43[i]) - (((fTemp2 * fRec31[2]) + (2.0 * (fTemp3 * fRec31[1]))) / fTemp4));
			double fTemp21 = (((fTemp1 * (fRec31[2] + (fRec31[0] + (2.0 * fRec31[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec31[1]) + ((fRec31[0] + fRec31[2]) / fTemp4))))));
			fRec32[0] = (double(input44[i]) - (((fTemp2 * fRec32[2]) + (2.0 * (fTemp3 * fRec32[1]))) / fTemp4));
			double fTemp22 = (((fTemp1 * (fRec32[2] + (fRec32[0] + (2.0 * fRec32[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec32[1]) + ((fRec32[0] + fRec32[2]) / fTemp4))))));
			fRec33[0] = (double(input45[i]) - (((fTemp2 * fRec33[2]) + (2.0 * (fTemp3 * fRec33[1]))) / fTemp4));
			double fTemp23 = (((fTemp1 * (fRec33[2] + (fRec33[0] + (2.0 * fRec33[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec33[1]) + ((fRec33[0] + fRec33[2]) / fTemp4))))));
			fRec34[0] = (double(input46[i]) - (((fTemp2 * fRec34[2]) + (2.0 * (fTemp3 * fRec34[1]))) / fTemp4));
			double fTemp24 = (((fTemp1 * (fRec34[2] + (fRec34[0] + (2.0 * fRec34[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec34[1]) + ((fRec34[0] + fRec34[2]) / fTemp4))))));
			fRec35[0] = (double(input36[i]) - (((fTemp2 * fRec35[2]) + (2.0 * (fTemp3 * fRec35[1]))) / fTemp4));
			double fTemp25 = (((fTemp1 * (fRec35[2] + (fRec35[0] + (2.0 * fRec35[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec35[1]) + ((fRec35[0] + fRec35[2]) / fTemp4))))));
			fRec36[0] = (double(input38[i]) - (((fTemp2 * fRec36[2]) + (2.0 * (fTemp3 * fRec36[1]))) / fTemp4));
			double fTemp26 = (((fTemp1 * (fRec36[2] + (fRec36[0] + (2.0 * fRec36[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec36[1]) + ((fRec36[0] + fRec36[2]) / fTemp4))))));
			fRec37[0] = (double(input39[i]) - (((fTemp2 * fRec37[2]) + (2.0 * (fTemp3 * fRec37[1]))) / fTemp4));
			double fTemp27 = (((fTemp1 * (fRec37[2] + (fRec37[0] + (2.0 * fRec37[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec37[1]) + ((fRec37[0] + fRec37[2]) / fTemp4))))));
			fRec38[0] = (double(input40[i]) - (((fTemp2 * fRec38[2]) + (2.0 * (fTemp3 * fRec38[1]))) / fTemp4));
			double fTemp28 = (((fTemp1 * (fRec38[2] + (fRec38[0] + (2.0 * fRec38[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec38[1]) + ((fRec38[0] + fRec38[2]) / fTemp4))))));
			fRec39[0] = (double(input47[i]) - (((fTemp2 * fRec39[2]) + (2.0 * (fTemp3 * fRec39[1]))) / fTemp4));
			double fTemp29 = (((fTemp1 * (fRec39[2] + (fRec39[0] + (2.0 * fRec39[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec39[1]) + ((fRec39[0] + fRec39[2]) / fTemp4))))));
			fRec40[0] = (double(input48[i]) - (((fTemp2 * fRec40[2]) + (2.0 * (fTemp3 * fRec40[1]))) / fTemp4));
			double fTemp30 = (((fTemp1 * (fRec40[2] + (fRec40[0] + (2.0 * fRec40[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec40[1]) + ((fRec40[0] + fRec40[2]) / fTemp4))))));
			double fTemp31 = (fConst11 * ((((((((0.023845565400000001 * fTemp18) + (0.029336089499999999 * fTemp19)) + (0.0053710855 * fTemp20)) + (0.049850232100000003 * fTemp21)) + (0.0038374785999999998 * fTemp22)) + (0.0037345669999999998 * fTemp23)) + (0.0041198601 * fTemp24)) - ((((((0.0062287489999999996 * fTemp25) + (0.022185455100000001 * fTemp26)) + (0.064227270099999997 * fTemp27)) + (0.0040083230000000003 * fTemp28)) + (0.065841868200000001 * fTemp29)) + (0.085238888099999993 * fTemp30))));
			double fTemp32 = (fConst12 * fRec22[1]);
			double fTemp33 = (fConst13 * fRec25[1]);
			fRec27[0] = (fTemp31 + (fTemp32 + (fRec27[1] + fTemp33)));
			fRec25[0] = fRec27[0];
			double fRec26 = ((fTemp33 + fTemp32) + fTemp31);
			fRec24[0] = (fRec25[0] + fRec24[1]);
			fRec22[0] = fRec24[0];
			double fRec23 = fRec26;
			fRec21[0] = (fTemp16 + (fTemp17 + (fRec23 + fRec21[1])));
			fRec19[0] = fRec21[0];
			double fRec20 = (fTemp16 + (fRec23 + fTemp17));
			fRec18[0] = (fRec19[0] + fRec18[1]);
			fRec16[0] = fRec18[0];
			double fRec17 = fRec20;
			fRec15[0] = (fTemp14 + (fTemp15 + (fRec17 + fRec15[1])));
			fRec13[0] = fRec15[0];
			double fRec14 = (fTemp14 + (fRec17 + fTemp15));
			fRec12[0] = (fRec13[0] + fRec12[1]);
			fRec10[0] = fRec12[0];
			double fRec11 = fRec14;
			double fTemp34 = (fConst15 * fRec41[1]);
			double fTemp35 = (fConst17 * fRec44[1]);
			double fTemp36 = (fConst18 * fRec47[1]);
			fRec56[0] = (double(input25[i]) - (((fTemp2 * fRec56[2]) + (2.0 * (fTemp3 * fRec56[1]))) / fTemp4));
			double fTemp37 = (((fTemp1 * (fRec56[2] + (fRec56[0] + (2.0 * fRec56[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec56[1]) + ((fRec56[0] + fRec56[2]) / fTemp4))))));
			fRec57[0] = (double(input26[i]) - (((fTemp2 * fRec57[2]) + (2.0 * (fTemp3 * fRec57[1]))) / fTemp4));
			double fTemp38 = (((fTemp1 * (fRec57[2] + (fRec57[0] + (2.0 * fRec57[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec57[1]) + ((fRec57[0] + fRec57[2]) / fTemp4))))));
			fRec58[0] = (double(input29[i]) - (((fTemp2 * fRec58[2]) + (2.0 * (fTemp3 * fRec58[1]))) / fTemp4));
			double fTemp39 = (((fTemp1 * (fRec58[2] + (fRec58[0] + (2.0 * fRec58[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec58[1]) + ((fRec58[0] + fRec58[2]) / fTemp4))))));
			fRec59[0] = (double(input30[i]) - (((fTemp2 * fRec59[2]) + (2.0 * (fTemp3 * fRec59[1]))) / fTemp4));
			double fTemp40 = (((fTemp1 * (fRec59[2] + (fRec59[0] + (2.0 * fRec59[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec59[1]) + ((fRec59[0] + fRec59[2]) / fTemp4))))));
			fRec60[0] = (double(input31[i]) - (((fTemp2 * fRec60[2]) + (2.0 * (fTemp3 * fRec60[1]))) / fTemp4));
			double fTemp41 = (((fTemp1 * (fRec60[2] + (fRec60[0] + (2.0 * fRec60[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec60[1]) + ((fRec60[0] + fRec60[2]) / fTemp4))))));
			fRec61[0] = (double(input27[i]) - (((fTemp2 * fRec61[2]) + (2.0 * (fTemp3 * fRec61[1]))) / fTemp4));
			double fTemp42 = (((fTemp1 * (fRec61[2] + (fRec61[0] + (2.0 * fRec61[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec61[1]) + ((fRec61[0] + fRec61[2]) / fTemp4))))));
			fRec62[0] = (double(input28[i]) - (((fTemp2 * fRec62[2]) + (2.0 * (fTemp3 * fRec62[1]))) / fTemp4));
			double fTemp43 = (((fTemp1 * (fRec62[2] + (fRec62[0] + (2.0 * fRec62[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec62[1]) + ((fRec62[0] + fRec62[2]) / fTemp4))))));
			fRec63[0] = (double(input32[i]) - (((fTemp2 * fRec63[2]) + (2.0 * (fTemp3 * fRec63[1]))) / fTemp4));
			double fTemp44 = (((fTemp1 * (fRec63[2] + (fRec63[0] + (2.0 * fRec63[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec63[1]) + ((fRec63[0] + fRec63[2]) / fTemp4))))));
			fRec64[0] = (double(input33[i]) - (((fTemp2 * fRec64[2]) + (2.0 * (fTemp3 * fRec64[1]))) / fTemp4));
			double fTemp45 = (((fTemp1 * (fRec64[2] + (fRec64[0] + (2.0 * fRec64[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec64[1]) + ((fRec64[0] + fRec64[2]) / fTemp4))))));
			fRec65[0] = (double(input34[i]) - (((fTemp2 * fRec65[2]) + (2.0 * (fTemp3 * fRec65[1]))) / fTemp4));
			double fTemp46 = (((fTemp1 * (fRec65[2] + (fRec65[0] + (2.0 * fRec65[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec65[1]) + ((fRec65[0] + fRec65[2]) / fTemp4))))));
			fRec66[0] = (double(input35[i]) - (((fTemp2 * fRec66[2]) + (2.0 * (fTemp3 * fRec66[1]))) / fTemp4));
			double fTemp47 = (((fTemp1 * (fRec66[2] + (fRec66[0] + (2.0 * fRec66[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec66[1]) + ((fRec66[0] + fRec66[2]) / fTemp4))))));
			double fTemp48 = (fConst20 * ((((((0.0396892732 * fTemp37) + (0.054817154200000003 * fTemp38)) + (0.0037084573000000002 * fTemp39)) + (0.046224300400000001 * fTemp40)) + (0.0108019012 * fTemp41)) - ((((((0.0298172794 * fTemp42) + (0.060413297800000001 * fTemp43)) + (0.030717128999999999 * fTemp44)) + (0.0043576392 * fTemp45)) + (0.043713218900000003 * fTemp46)) + (0.081740197299999998 * fTemp47))));
			double fTemp49 = (fConst21 * fRec50[1]);
			double fTemp50 = (fConst22 * fRec53[1]);
			fRec55[0] = (fTemp48 + (fTemp49 + (fRec55[1] + fTemp50)));
			fRec53[0] = fRec55[0];
			double fRec54 = ((fTemp50 + fTemp49) + fTemp48);
			fRec52[0] = (fRec53[0] + fRec52[1]);
			fRec50[0] = fRec52[0];
			double fRec51 = fRec54;
			fRec49[0] = (fTemp35 + (fTemp36 + (fRec51 + fRec49[1])));
			fRec47[0] = fRec49[0];
			double fRec48 = (fTemp35 + (fRec51 + fTemp36));
			fRec46[0] = (fRec47[0] + fRec46[1]);
			fRec44[0] = fRec46[0];
			double fRec45 = fRec48;
			fRec43[0] = (fTemp34 + (fRec45 + fRec43[1]));
			fRec41[0] = fRec43[0];
			double fRec42 = (fRec45 + fTemp34);
			double fTemp51 = (fConst24 * fRec67[1]);
			double fTemp52 = (fConst25 * fRec70[1]);
			fRec79[0] = (double(input16[i]) - (((fTemp2 * fRec79[2]) + (2.0 * (fTemp3 * fRec79[1]))) / fTemp4));
			double fTemp53 = (((fTemp1 * (fRec79[2] + (fRec79[0] + (2.0 * fRec79[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec79[1]) + ((fRec79[0] + fRec79[2]) / fTemp4))))));
			fRec80[0] = (double(input17[i]) - (((fTemp2 * fRec80[2]) + (2.0 * (fTemp3 * fRec80[1]))) / fTemp4));
			double fTemp54 = (((fTemp1 * (fRec80[2] + (fRec80[0] + (2.0 * fRec80[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec80[1]) + ((fRec80[0] + fRec80[2]) / fTemp4))))));
			fRec81[0] = (double(input20[i]) - (((fTemp2 * fRec81[2]) + (2.0 * (fTemp3 * fRec81[1]))) / fTemp4));
			double fTemp55 = (((fTemp1 * (fRec81[2] + (fRec81[0] + (2.0 * fRec81[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec81[1]) + ((fRec81[0] + fRec81[2]) / fTemp4))))));
			fRec82[0] = (double(input18[i]) - (((fTemp2 * fRec82[2]) + (2.0 * (fTemp3 * fRec82[1]))) / fTemp4));
			double fTemp56 = (((fTemp1 * (fRec82[2] + (fRec82[0] + (2.0 * fRec82[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec82[1]) + ((fRec82[0] + fRec82[2]) / fTemp4))))));
			fRec83[0] = (double(input19[i]) - (((fTemp2 * fRec83[2]) + (2.0 * (fTemp3 * fRec83[1]))) / fTemp4));
			double fTemp57 = (((fTemp1 * (fRec83[2] + (fRec83[0] + (2.0 * fRec83[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec83[1]) + ((fRec83[0] + fRec83[2]) / fTemp4))))));
			fRec84[0] = (double(input21[i]) - (((fTemp2 * fRec84[2]) + (2.0 * (fTemp3 * fRec84[1]))) / fTemp4));
			double fTemp58 = (((fTemp1 * (fRec84[2] + (fRec84[0] + (2.0 * fRec84[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec84[1]) + ((fRec84[0] + fRec84[2]) / fTemp4))))));
			fRec85[0] = (double(input22[i]) - (((fTemp2 * fRec85[2]) + (2.0 * (fTemp3 * fRec85[1]))) / fTemp4));
			double fTemp59 = (((fTemp1 * (fRec85[2] + (fRec85[0] + (2.0 * fRec85[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec85[1]) + ((fRec85[0] + fRec85[2]) / fTemp4))))));
			fRec86[0] = (double(input23[i]) - (((fTemp2 * fRec86[2]) + (2.0 * (fTemp3 * fRec86[1]))) / fTemp4));
			double fTemp60 = (((fTemp1 * (fRec86[2] + (fRec86[0] + (2.0 * fRec86[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec86[1]) + ((fRec86[0] + fRec86[2]) / fTemp4))))));
			fRec87[0] = (double(input24[i]) - (((fTemp2 * fRec87[2]) + (2.0 * (fTemp3 * fRec87[1]))) / fTemp4));
			double fTemp61 = (((fTemp1 * (fRec87[2] + (fRec87[0] + (2.0 * fRec87[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec87[1]) + ((fRec87[0] + fRec87[2]) / fTemp4))))));
			double fTemp62 = (fConst27 * ((((0.076301153100000005 * fTemp53) + (0.064431403900000003 * fTemp54)) + (0.019758352 * fTemp55)) - ((((((0.033049796200000002 * fTemp56) + (0.034642695199999997 * fTemp57)) + (0.055682894599999998 * fTemp58)) + (0.020987958099999999 * fTemp59)) + (0.0076640474000000004 * fTemp60)) + (0.050985000599999997 * fTemp61))));
			double fTemp63 = (fConst28 * fRec73[1]);
			double fTemp64 = (fConst29 * fRec76[1]);
			fRec78[0] = (fTemp62 + (fTemp63 + (fRec78[1] + fTemp64)));
			fRec76[0] = fRec78[0];
			double fRec77 = ((fTemp64 + fTemp63) + fTemp62);
			fRec75[0] = (fRec76[0] + fRec75[1]);
			fRec73[0] = fRec75[0];
			double fRec74 = fRec77;
			fRec72[0] = (fTemp51 + (fTemp52 + (fRec74 + fRec72[1])));
			fRec70[0] = fRec72[0];
			double fRec71 = (fTemp51 + (fRec74 + fTemp52));
			fRec69[0] = (fRec70[0] + fRec69[1]);
			fRec67[0] = fRec69[0];
			double fRec68 = fRec71;
			double fTemp65 = (fConst31 * fRec88[1]);
			fRec97[0] = (double(input9[i]) - (((fTemp2 * fRec97[2]) + (2.0 * (fTemp3 * fRec97[1]))) / fTemp4));
			double fTemp66 = (((fTemp1 * (fRec97[2] + (fRec97[0] + (2.0 * fRec97[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec97[1]) + ((fRec97[0] + fRec97[2]) / fTemp4))))));
			fRec98[0] = (double(input10[i]) - (((fTemp2 * fRec98[2]) + (2.0 * (fTemp3 * fRec98[1]))) / fTemp4));
			double fTemp67 = (((fTemp1 * (fRec98[2] + (fRec98[0] + (2.0 * fRec98[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec98[1]) + ((fRec98[0] + fRec98[2]) / fTemp4))))));
			fRec99[0] = (double(input14[i]) - (((fTemp2 * fRec99[2]) + (2.0 * (fTemp3 * fRec99[1]))) / fTemp4));
			double fTemp68 = (((fTemp1 * (fRec99[2] + (fRec99[0] + (2.0 * fRec99[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec99[1]) + ((fRec99[0] + fRec99[2]) / fTemp4))))));
			fRec100[0] = (double(input11[i]) - (((fTemp2 * fRec100[2]) + (2.0 * (fTemp3 * fRec100[1]))) / fTemp4));
			double fTemp69 = (((fTemp1 * (fRec100[2] + (fRec100[0] + (2.0 * fRec100[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec100[1]) + ((fRec100[0] + fRec100[2]) / fTemp4))))));
			fRec101[0] = (double(input12[i]) - (((fTemp2 * fRec101[2]) + (2.0 * (fTemp3 * fRec101[1]))) / fTemp4));
			double fTemp70 = (((fTemp1 * (fRec101[2] + (fRec101[0] + (2.0 * fRec101[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec101[1]) + ((fRec101[0] + fRec101[2]) / fTemp4))))));
			fRec102[0] = (double(input13[i]) - (((fTemp2 * fRec102[2]) + (2.0 * (fTemp3 * fRec102[1]))) / fTemp4));
			double fTemp71 = (((fTemp1 * (fRec102[2] + (fRec102[0] + (2.0 * fRec102[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec102[1]) + ((fRec102[0] + fRec102[2]) / fTemp4))))));
			fRec103[0] = (double(input15[i]) - (((fTemp2 * fRec103[2]) + (2.0 * (fTemp3 * fRec103[1]))) / fTemp4));
			double fTemp72 = (((fTemp1 * (fRec103[2] + (fRec103[0] + (2.0 * fRec103[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec103[1]) + ((fRec103[0] + fRec103[2]) / fTemp4))))));
			double fTemp73 = (fConst33 * ((((0.086992999000000001 * fTemp66) + (0.049152279799999997 * fTemp67)) + (0.023180860599999999 * fTemp68)) - ((((0.023616205899999999 * fTemp69) + (0.039840277200000003 * fTemp70)) + (0.041084534700000001 * fTemp71)) + (0.0047892942000000004 * fTemp72))));
			double fTemp74 = (fConst34 * fRec91[1]);
			double fTemp75 = (fConst35 * fRec94[1]);
			fRec96[0] = (fTemp73 + (fTemp74 + (fRec96[1] + fTemp75)));
			fRec94[0] = fRec96[0];
			double fRec95 = ((fTemp75 + fTemp74) + fTemp73);
			fRec93[0] = (fRec94[0] + fRec93[1]);
			fRec91[0] = fRec93[0];
			double fRec92 = fRec95;
			fRec90[0] = (fTemp65 + (fRec92 + fRec90[1]));
			fRec88[0] = fRec90[0];
			double fRec89 = (fRec92 + fTemp65);
			fRec107[0] = (double(input1[i]) - (((fTemp2 * fRec107[2]) + (2.0 * (fTemp3 * fRec107[1]))) / fTemp4));
			double fTemp76 = (((fTemp1 * (fRec107[2] + (fRec107[0] + (2.0 * fRec107[1])))) / fTemp5) + (0.96028985649999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec107[1]) + ((fRec107[0] + fRec107[2]) / fTemp4))))));
			fRec108[0] = (double(input2[i]) - (((fTemp2 * fRec108[2]) + (2.0 * (fTemp3 * fRec108[1]))) / fTemp4));
			double fTemp77 = (((fTemp1 * (fRec108[2] + (fRec108[0] + (2.0 * fRec108[1])))) / fTemp5) + (0.96028985649999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec108[1]) + ((fRec108[0] + fRec108[2]) / fTemp4))))));
			fRec109[0] = (double(input3[i]) - (((fTemp2 * fRec109[2]) + (2.0 * (fTemp3 * fRec109[1]))) / fTemp4));
			double fTemp78 = (((fTemp1 * (fRec109[2] + (fRec109[0] + (2.0 * fRec109[1])))) / fTemp5) + (0.96028985649999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec109[1]) + ((fRec109[0] + fRec109[2]) / fTemp4))))));
			double fTemp79 = (fConst37 * (((0.029726642500000001 * fTemp76) + (0.014911744100000001 * fTemp77)) + (0.048964367199999997 * fTemp78)));
			double fTemp80 = (fConst38 * fRec104[1]);
			fRec106[0] = (fTemp79 + (fRec106[1] + fTemp80));
			fRec104[0] = fRec106[0];
			double fRec105 = (fTemp80 + fTemp79);
			fRec116[0] = (double(input4[i]) - (((fTemp2 * fRec116[2]) + (2.0 * (fTemp3 * fRec116[1]))) / fTemp4));
			double fTemp81 = (((fTemp1 * (fRec116[2] + (fRec116[0] + (2.0 * fRec116[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec116[1]) + ((fRec116[0] + fRec116[2]) / fTemp4))))));
			fRec117[0] = (double(input5[i]) - (((fTemp2 * fRec117[2]) + (2.0 * (fTemp3 * fRec117[1]))) / fTemp4));
			double fTemp82 = (((fTemp1 * (fRec117[2] + (fRec117[0] + (2.0 * fRec117[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec117[1]) + ((fRec117[0] + fRec117[2]) / fTemp4))))));
			fRec118[0] = (double(input7[i]) - (((fTemp2 * fRec118[2]) + (2.0 * (fTemp3 * fRec118[1]))) / fTemp4));
			double fTemp83 = (((fTemp1 * (fRec118[2] + (fRec118[0] + (2.0 * fRec118[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec118[1]) + ((fRec118[0] + fRec118[2]) / fTemp4))))));
			fRec119[0] = (double(input8[i]) - (((fTemp2 * fRec119[2]) + (2.0 * (fTemp3 * fRec119[1]))) / fTemp4));
			double fTemp84 = (((fTemp1 * (fRec119[2] + (fRec119[0] + (2.0 * fRec119[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec119[1]) + ((fRec119[0] + fRec119[2]) / fTemp4))))));
			fRec120[0] = (double(input6[i]) - (((fTemp2 * fRec120[2]) + (2.0 * (fTemp3 * fRec120[1]))) / fTemp4));
			double fTemp85 = (((fTemp1 * (fRec120[2] + (fRec120[0] + (2.0 * fRec120[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec120[1]) + ((fRec120[0] + fRec120[2]) / fTemp4))))));
			double fTemp86 = (fConst40 * (((((0.067278733399999999 * fTemp81) + (0.0210625147 * fTemp82)) + (0.033079176799999999 * fTemp83)) + (0.035296655400000002 * fTemp84)) - (0.037263030000000003 * fTemp85)));
			double fTemp87 = (fConst41 * fRec110[1]);
			double fTemp88 = (fConst42 * fRec113[1]);
			fRec115[0] = (fTemp86 + (fTemp87 + (fRec115[1] + fTemp88)));
			fRec113[0] = fRec115[0];
			double fRec114 = ((fTemp88 + fTemp87) + fTemp86);
			fRec112[0] = (fRec113[0] + fRec112[1]);
			fRec110[0] = fRec112[0];
			double fRec111 = fRec114;
			fRec121[0] = (double(input54[i]) - (((fTemp2 * fRec121[2]) + (2.0 * (fTemp3 * fRec121[1]))) / fTemp4));
			double fTemp89 = (((fTemp1 * (fRec121[2] + (fRec121[0] + (2.0 * fRec121[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec121[1]) + ((fRec121[0] + fRec121[2]) / fTemp4))))));
			fRec122[0] = (double(input49[i]) - (((fTemp2 * fRec122[2]) + (2.0 * (fTemp3 * fRec122[1]))) / fTemp4));
			double fTemp90 = (((fTemp1 * (fRec122[2] + (fRec122[0] + (2.0 * fRec122[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec122[1]) + ((fRec122[0] + fRec122[2]) / fTemp4))))));
			fRec123[0] = (double(input50[i]) - (((fTemp2 * fRec123[2]) + (2.0 * (fTemp3 * fRec123[1]))) / fTemp4));
			double fTemp91 = (((fTemp1 * (fRec123[2] + (fRec123[0] + (2.0 * fRec123[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec123[1]) + ((fRec123[0] + fRec123[2]) / fTemp4))))));
			fRec124[0] = (double(input51[i]) - (((fTemp2 * fRec124[2]) + (2.0 * (fTemp3 * fRec124[1]))) / fTemp4));
			double fTemp92 = (((fTemp1 * (fRec124[2] + (fRec124[0] + (2.0 * fRec124[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec124[1]) + ((fRec124[0] + fRec124[2]) / fTemp4))))));
			fRec125[0] = (double(input52[i]) - (((fTemp2 * fRec125[2]) + (2.0 * (fTemp3 * fRec125[1]))) / fTemp4));
			double fTemp93 = (((fTemp1 * (fRec125[2] + (fRec125[0] + (2.0 * fRec125[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec125[1]) + ((fRec125[0] + fRec125[2]) / fTemp4))))));
			fRec126[0] = (double(input53[i]) - (((fTemp2 * fRec126[2]) + (2.0 * (fTemp3 * fRec126[1]))) / fTemp4));
			double fTemp94 = (((fTemp1 * (fRec126[2] + (fRec126[0] + (2.0 * fRec126[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec126[1]) + ((fRec126[0] + fRec126[2]) / fTemp4))))));
			fRec127[0] = (double(input56[i]) - (((fTemp2 * fRec127[2]) + (2.0 * (fTemp3 * fRec127[1]))) / fTemp4));
			double fTemp95 = (((fTemp1 * (fRec127[2] + (fRec127[0] + (2.0 * fRec127[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec127[1]) + ((fRec127[0] + fRec127[2]) / fTemp4))))));
			fRec128[0] = (double(input62[i]) - (((fTemp2 * fRec128[2]) + (2.0 * (fTemp3 * fRec128[1]))) / fTemp4));
			double fTemp96 = (((fTemp1 * (fRec128[2] + (fRec128[0] + (2.0 * fRec128[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec128[1]) + ((fRec128[0] + fRec128[2]) / fTemp4))))));
			fRec129[0] = (double(input63[i]) - (((fTemp2 * fRec129[2]) + (2.0 * (fTemp3 * fRec129[1]))) / fTemp4));
			double fTemp97 = (((fTemp1 * (fRec129[2] + (fRec129[0] + (2.0 * fRec129[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec129[1]) + ((fRec129[0] + fRec129[2]) / fTemp4))))));
			fVec0[(IOTA & 127)] = (((0.0075145211000000002 * fTemp7) + ((0.0307251851 * fTemp8) + ((0.0082210489999999994 * fTemp9) + ((0.0241185979 * fTemp10) + ((0.014166315299999999 * fTemp11) + ((0.011383981099999999 * fTemp12) + (((0.020287651300000001 * fTemp13) + (fRec11 + (fRec42 + (fRec68 + (fRec89 + (fRec105 + fRec111)))))) + (0.039867788600000002 * fTemp89)))))))) - ((((((((0.0428301398 * fTemp90) + (0.012795581699999999 * fTemp91)) + (0.016300118700000001 * fTemp92)) + (0.048140259599999999 * fTemp93)) + (0.0095403430999999993 * fTemp94)) + (0.0300060233 * fTemp95)) + (0.063940729299999999 * fTemp96)) + (0.063604320800000003 * fTemp97)));
			output0[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec0[((IOTA - iConst43) & 127)])));
			double fTemp98 = (fConst45 * fRec130[1]);
			double fTemp99 = (fConst46 * fRec133[1]);
			double fTemp100 = (fConst48 * fRec136[1]);
			double fTemp101 = (fConst49 * fRec139[1]);
			double fTemp102 = (fConst51 * (((0.052955559700000002 * fTemp30) + (((0.0213893429 * fTemp22) + (((0.0070331500000000002 * fTemp19) + (((0.056850246899999998 * fTemp25) + (0.034372175499999998 * fTemp18)) + (0.0040910149000000003 * fTemp28))) + (0.050055093600000003 * fTemp21))) + (0.036782274699999999 * fTemp29))) - ((0.0314903053 * fTemp24) + ((((0.015633572799999999 * fTemp26) + (0.021331154200000001 * fTemp27)) + (0.012795265599999999 * fTemp20)) + (0.046589116399999998 * fTemp23)))));
			double fTemp103 = (fConst52 * fRec142[1]);
			double fTemp104 = (fConst53 * fRec145[1]);
			fRec147[0] = (fTemp102 + (fTemp103 + (fRec147[1] + fTemp104)));
			fRec145[0] = fRec147[0];
			double fRec146 = ((fTemp104 + fTemp103) + fTemp102);
			fRec144[0] = (fRec145[0] + fRec144[1]);
			fRec142[0] = fRec144[0];
			double fRec143 = fRec146;
			fRec141[0] = (fTemp100 + (fTemp101 + (fRec143 + fRec141[1])));
			fRec139[0] = fRec141[0];
			double fRec140 = (fTemp100 + (fRec143 + fTemp101));
			fRec138[0] = (fRec139[0] + fRec138[1]);
			fRec136[0] = fRec138[0];
			double fRec137 = fRec140;
			fRec135[0] = (fTemp98 + (fTemp99 + (fRec137 + fRec135[1])));
			fRec133[0] = fRec135[0];
			double fRec134 = (fTemp98 + (fRec137 + fTemp99));
			fRec132[0] = (fRec133[0] + fRec132[1]);
			fRec130[0] = fRec132[0];
			double fRec131 = fRec134;
			double fTemp105 = (fConst55 * fRec148[1]);
			double fTemp106 = (fConst57 * fRec151[1]);
			double fTemp107 = (fConst58 * fRec154[1]);
			double fTemp108 = (fConst60 * (((0.0610103715 * fTemp47) + (((0.029800903600000001 * fTemp41) + ((0.034537388099999997 * fTemp40) + (((0.0498576274 * fTemp37) + (0.026404712600000001 * fTemp38)) + (0.0033494699999999998 * fTemp39)))) + (0.038495813300000001 * fTemp46))) - ((0.037791204799999999 * fTemp45) + (((0.0144749578 * fTemp42) + (0.013960914899999999 * fTemp43)) + (0.046713316599999999 * fTemp44)))));
			double fTemp109 = (fConst61 * fRec157[1]);
			double fTemp110 = (fConst62 * fRec160[1]);
			fRec162[0] = (fTemp108 + (fTemp109 + (fRec162[1] + fTemp110)));
			fRec160[0] = fRec162[0];
			double fRec161 = ((fTemp110 + fTemp109) + fTemp108);
			fRec159[0] = (fRec160[0] + fRec159[1]);
			fRec157[0] = fRec159[0];
			double fRec158 = fRec161;
			fRec156[0] = (fTemp106 + (fTemp107 + (fRec158 + fRec156[1])));
			fRec154[0] = fRec156[0];
			double fRec155 = (fTemp106 + (fRec158 + fTemp107));
			fRec153[0] = (fRec154[0] + fRec153[1]);
			fRec151[0] = fRec153[0];
			double fRec152 = fRec155;
			fRec150[0] = (fTemp105 + (fRec152 + fRec150[1]));
			fRec148[0] = fRec150[0];
			double fRec149 = (fRec152 + fTemp105);
			double fTemp111 = (fConst64 * fRec163[1]);
			double fTemp112 = (fConst65 * fRec166[1]);
			double fTemp113 = (fConst67 * (((0.065033544400000004 * fTemp61) + ((((0.039804079899999997 * fTemp53) + (0.017662780699999998 * fTemp54)) + (0.026841980200000001 * fTemp55)) + (0.036427192300000001 * fTemp60))) - ((0.042734200999999999 * fTemp59) + (((0.0111106212 * fTemp56) + (0.0063062444999999996 * fTemp57)) + (0.042520284899999997 * fTemp58)))));
			double fTemp114 = (fConst68 * fRec169[1]);
			double fTemp115 = (fConst69 * fRec172[1]);
			fRec174[0] = (fTemp113 + (fTemp114 + (fRec174[1] + fTemp115)));
			fRec172[0] = fRec174[0];
			double fRec173 = ((fTemp115 + fTemp114) + fTemp113);
			fRec171[0] = (fRec172[0] + fRec171[1]);
			fRec169[0] = fRec171[0];
			double fRec170 = fRec173;
			fRec168[0] = (fTemp111 + (fTemp112 + (fRec170 + fRec168[1])));
			fRec166[0] = fRec168[0];
			double fRec167 = (fTemp111 + (fRec170 + fTemp112));
			fRec165[0] = (fRec166[0] + fRec165[1]);
			fRec163[0] = fRec165[0];
			double fRec164 = fRec167;
			double fTemp116 = (fConst71 * fRec175[1]);
			double fTemp117 = (fConst73 * (((0.063815383899999994 * fTemp72) + (((0.0279606001 * fTemp66) + (0.0095417018999999995 * fTemp67)) + (0.030657757000000001 * fTemp68))) - (((0.0059679968999999996 * fTemp69) + (0.024076274200000001 * fTemp70)) + (0.045125815 * fTemp71))));
			double fTemp118 = (fConst74 * fRec178[1]);
			double fTemp119 = (fConst75 * fRec181[1]);
			fRec183[0] = (fTemp117 + (fTemp118 + (fRec183[1] + fTemp119)));
			fRec181[0] = fRec183[0];
			double fRec182 = ((fTemp119 + fTemp118) + fTemp117);
			fRec180[0] = (fRec181[0] + fRec180[1]);
			fRec178[0] = fRec180[0];
			double fRec179 = fRec182;
			fRec177[0] = (fTemp116 + (fRec179 + fRec177[1]));
			fRec175[0] = fRec177[0];
			double fRec176 = (fRec179 + fTemp116);
			double fTemp120 = (fConst77 * (((0.0059429141000000001 * fTemp76) + (0.0081434539 * fTemp77)) + (0.042622415099999998 * fTemp78)));
			double fTemp121 = (fConst78 * fRec184[1]);
			fRec186[0] = (fTemp120 + (fRec186[1] + fTemp121));
			fRec184[0] = fRec186[0];
			double fRec185 = (fTemp121 + fTemp120);
			double fTemp122 = (fConst80 * (((((0.016014700199999999 * fTemp81) + (0.0033428676 * fTemp82)) + (0.021908569900000001 * fTemp83)) + (0.0565179216 * fTemp84)) - (0.031246433099999998 * fTemp85)));
			double fTemp123 = (fConst81 * fRec187[1]);
			double fTemp124 = (fConst82 * fRec190[1]);
			fRec192[0] = (fTemp122 + (fTemp123 + (fRec192[1] + fTemp124)));
			fRec190[0] = fRec192[0];
			double fRec191 = ((fTemp124 + fTemp123) + fTemp122);
			fRec189[0] = (fRec190[0] + fRec189[1]);
			fRec187[0] = fRec189[0];
			double fRec188 = fRec191;
			fVec1[(IOTA & 127)] = (((0.0423314916 * fTemp97) + ((0.031787290599999997 * fTemp96) + ((0.013861735700000001 * fTemp9) + ((0.046929367800000003 * fTemp10) + ((0.013012011 * fTemp89) + ((0.0026655201999999999 * fTemp94) + ((0.040324676599999998 * fTemp91) + ((0.060027058899999999 * fTemp90) + ((0.0148930529 * fTemp13) + (fRec131 + (fRec149 + (fRec164 + (fRec176 + (fRec185 + fRec188)))))))))))))) - ((0.0249995865 * fTemp7) + (((0.0081492144000000002 * fTemp11) + ((0.033919433999999998 * fTemp95) + (((0.014671735999999999 * fTemp92) + (0.027015092899999999 * fTemp93)) + (7.6346600000000005e-05 * fTemp12)))) + (0.0427511681 * fTemp8))));
			output1[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec1[((IOTA - iConst83) & 127)])));
			double fTemp125 = (fConst45 * fRec193[1]);
			double fTemp126 = (fConst46 * fRec196[1]);
			double fTemp127 = (fConst48 * fRec199[1]);
			double fTemp128 = (fConst49 * fRec202[1]);
			double fTemp129 = (fConst51 * (((0.0063727163999999998 * fTemp30) + (((0.056099170599999998 * fTemp21) + (((0.022252841900000001 * fTemp26) + (0.042788733000000002 * fTemp27)) + (0.0053198574 * fTemp20))) + (0.0297577329 * fTemp29))) - ((0.0042289394999999999 * fTemp24) + ((0.048139648200000003 * fTemp23) + (((((0.085286380199999998 * fTemp25) + (0.063374327899999999 * fTemp18)) + (0.0038621548999999999 * fTemp28)) + (0.0145187926 * fTemp19)) + (0.0039222594000000001 * fTemp22))))));
			double fTemp130 = (fConst52 * fRec205[1]);
			double fTemp131 = (fConst53 * fRec208[1]);
			fRec210[0] = (fTemp129 + (fTemp130 + (fRec210[1] + fTemp131)));
			fRec208[0] = fRec210[0];
			double fRec209 = ((fTemp131 + fTemp130) + fTemp129);
			fRec207[0] = (fRec208[0] + fRec207[1]);
			fRec205[0] = fRec207[0];
			double fRec206 = fRec209;
			fRec204[0] = (fTemp127 + (fTemp128 + (fRec206 + fRec204[1])));
			fRec202[0] = fRec204[0];
			double fRec203 = (fTemp127 + (fRec206 + fTemp128));
			fRec201[0] = (fRec202[0] + fRec201[1]);
			fRec199[0] = fRec201[0];
			double fRec200 = fRec203;
			fRec198[0] = (fTemp125 + (fTemp126 + (fRec200 + fRec198[1])));
			fRec196[0] = fRec198[0];
			double fRec197 = (fTemp125 + (fRec200 + fTemp126));
			fRec195[0] = (fRec196[0] + fRec195[1]);
			fRec193[0] = fRec195[0];
			double fRec194 = fRec197;
			double fTemp132 = (fConst55 * fRec211[1]);
			double fTemp133 = (fConst57 * fRec214[1]);
			double fTemp134 = (fConst58 * fRec217[1]);
			double fTemp135 = (fConst60 * (((0.029884990399999999 * fTemp47) + (((0.0103474541 * fTemp41) + (((0.024205872699999999 * fTemp42) + (0.030722377799999999 * fTemp43)) + (0.046285968800000001 * fTemp40))) + (0.043768999500000003 * fTemp46))) - ((0.018109806199999998 * fTemp45) + ((((0.085898492199999996 * fTemp37) + (0.0547875372 * fTemp38)) + (0.0050272477999999997 * fTemp39)) + (0.060489767399999998 * fTemp44)))));
			double fTemp136 = (fConst61 * fRec220[1]);
			double fTemp137 = (fConst62 * fRec223[1]);
			fRec225[0] = (fTemp135 + (fTemp136 + (fRec225[1] + fTemp137)));
			fRec223[0] = fRec225[0];
			double fRec224 = ((fTemp137 + fTemp136) + fTemp135);
			fRec222[0] = (fRec223[0] + fRec222[1]);
			fRec220[0] = fRec222[0];
			double fRec221 = fRec224;
			fRec219[0] = (fTemp133 + (fTemp134 + (fRec221 + fRec219[1])));
			fRec217[0] = fRec219[0];
			double fRec218 = (fTemp133 + (fRec221 + fTemp134));
			fRec216[0] = (fRec217[0] + fRec216[1]);
			fRec214[0] = fRec216[0];
			double fRec215 = fRec218;
			fRec213[0] = (fTemp132 + (fRec215 + fRec213[1]));
			fRec211[0] = fRec213[0];
			double fRec212 = (fRec215 + fTemp132);
			double fTemp138 = (fConst71 * fRec226[1]);
			double fTemp139 = (fConst73 * (((0.065029318399999994 * fTemp72) + ((0.0123580171 * fTemp69) + (0.049193511199999998 * fTemp68))) - ((((0.058135137599999998 * fTemp66) + (0.023170943100000001 * fTemp67)) + (0.039874397800000003 * fTemp70)) + (0.045841434700000003 * fTemp71))));
			double fTemp140 = (fConst74 * fRec229[1]);
			double fTemp141 = (fConst75 * fRec232[1]);
			fRec234[0] = (fTemp139 + (fTemp140 + (fRec234[1] + fTemp141)));
			fRec232[0] = fRec234[0];
			double fRec233 = ((fTemp141 + fTemp140) + fTemp139);
			fRec231[0] = (fRec232[0] + fRec231[1]);
			fRec229[0] = fRec231[0];
			double fRec230 = fRec233;
			fRec228[0] = (fTemp138 + (fRec230 + fRec228[1]));
			fRec226[0] = fRec228[0];
			double fRec227 = (fRec230 + fTemp138);
			double fTemp142 = (fConst77 * (((0.0149225192 * fTemp77) + (0.055717587200000002 * fTemp78)) - (0.0136027847 * fTemp76)));
			double fTemp143 = (fConst78 * fRec235[1]);
			fRec237[0] = (fTemp142 + (fRec237[1] + fTemp143));
			fRec235[0] = fRec237[0];
			double fRec236 = (fTemp143 + fTemp142);
			double fTemp144 = (fConst80 * (((0.038313226700000001 * fTemp83) + (0.067383992200000006 * fTemp84)) - (((0.0352983147 * fTemp81) + (0.0084932597000000002 * fTemp82)) + (0.037320288799999997 * fTemp85))));
			double fTemp145 = (fConst81 * fRec238[1]);
			double fTemp146 = (fConst82 * fRec241[1]);
			fRec243[0] = (fTemp144 + (fTemp145 + (fRec243[1] + fTemp146)));
			fRec241[0] = fRec243[0];
			double fRec242 = ((fTemp146 + fTemp145) + fTemp144);
			fRec240[0] = (fRec241[0] + fRec240[1]);
			fRec238[0] = fRec240[0];
			double fRec239 = fRec242;
			double fTemp147 = (fConst64 * fRec244[1]);
			double fTemp148 = (fConst65 * fRec247[1]);
			double fTemp149 = (fConst67 * (((0.0511303491 * fTemp61) + ((((0.021007529899999999 * fTemp56) + (0.014877479399999999 * fTemp57)) + (0.019820992499999999 * fTemp55)) + (0.051029004900000001 * fTemp60))) - ((0.033150009199999997 * fTemp59) + (((0.076321344499999999 * fTemp53) + (0.040122302200000001 * fTemp54)) + (0.063934425599999997 * fTemp58)))));
			double fTemp150 = (fConst68 * fRec250[1]);
			double fTemp151 = (fConst69 * fRec253[1]);
			fRec255[0] = (fTemp149 + (fTemp150 + (fRec255[1] + fTemp151)));
			fRec253[0] = fRec255[0];
			double fRec254 = ((fTemp151 + fTemp150) + fTemp149);
			fRec252[0] = (fRec253[0] + fRec252[1]);
			fRec250[0] = fRec252[0];
			double fRec251 = fRec254;
			fRec249[0] = (fTemp147 + (fTemp148 + (fRec251 + fRec249[1])));
			fRec247[0] = fRec249[0];
			double fRec248 = (fTemp147 + (fRec251 + fTemp148));
			fRec246[0] = (fRec247[0] + fRec246[1]);
			fRec244[0] = fRec246[0];
			double fRec245 = fRec248;
			fVec2[(IOTA & 127)] = ((((0.0128674736 * fTemp96) + ((0.0061100538999999997 * fTemp7) + ((0.039985163599999998 * fTemp10) + ((0.0180102122 * fTemp11) + ((0.00089390300000000004 * fTemp94) + ((0.048161613200000002 * fTemp93) + (((0.020312997499999999 * fTemp13) + (fRec194 + (fRec212 + (fRec227 + (fRec236 + fRec239))))) + (0.016935604999999999 * fTemp92)))))))) + fRec245) - (((0.030812155500000001 * fTemp8) + (((0.030099852199999999 * fTemp95) + ((0.0019634594 * fTemp12) + (((0.075312573600000002 * fTemp90) + (0.063879778799999995 * fTemp91)) + (0.024153195999999998 * fTemp89)))) + (0.0124750069 * fTemp9))) + (0.0145614058 * fTemp97)));
			output2[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec2[((IOTA - iConst83) & 127)])));
			double fTemp152 = (fConst85 * fRec256[1]);
			double fTemp153 = (fConst86 * fRec259[1]);
			double fTemp154 = (fConst88 * fRec262[1]);
			double fTemp155 = (fConst89 * fRec265[1]);
			double fTemp156 = (fConst91 * (((0.031539304099999999 * fTemp24) + ((0.0179378514 * fTemp23) + ((0.0040771703000000003 * fTemp22) + (((((0.053022890000000003 * fTemp25) + (0.0017732303000000001 * fTemp18)) + (0.0155823968 * fTemp26)) + (0.048040300700000003 * fTemp27)) + (0.040435180500000001 * fTemp21))))) - ((0.056694326099999998 * fTemp30) + (((0.0128115069 * fTemp20) + ((0.021420805300000002 * fTemp28) + (0.030503810999999999 * fTemp19))) + (0.050256363700000001 * fTemp29)))));
			double fTemp157 = (fConst92 * fRec268[1]);
			double fTemp158 = (fConst93 * fRec271[1]);
			fRec273[0] = (fTemp156 + (fTemp157 + (fRec273[1] + fTemp158)));
			fRec271[0] = fRec273[0];
			double fRec272 = ((fTemp158 + fTemp157) + fTemp156);
			fRec270[0] = (fRec271[0] + fRec270[1]);
			fRec268[0] = fRec270[0];
			double fRec269 = fRec272;
			fRec267[0] = (fTemp154 + (fTemp155 + (fRec269 + fRec267[1])));
			fRec265[0] = fRec267[0];
			double fRec266 = (fTemp154 + (fRec269 + fTemp155));
			fRec264[0] = (fRec265[0] + fRec264[1]);
			fRec262[0] = fRec264[0];
			double fRec263 = fRec266;
			fRec261[0] = (fTemp152 + (fTemp153 + (fRec263 + fRec261[1])));
			fRec259[0] = fRec261[0];
			double fRec260 = (fTemp152 + (fRec263 + fTemp153));
			fRec258[0] = (fRec259[0] + fRec258[1]);
			fRec256[0] = fRec258[0];
			double fRec257 = fRec260;
			double fTemp159 = (fConst95 * fRec274[1]);
			double fTemp160 = (fConst97 * fRec277[1]);
			double fTemp161 = (fConst98 * fRec280[1]);
			double fTemp162 = (fConst100 * ((((0.023458194299999999 * fTemp41) + ((((0.0080179275000000008 * fTemp37) + (0.036957929100000002 * fTemp42)) + (0.046776700300000001 * fTemp43)) + (0.034595999299999999 * fTemp40))) + (0.016546496599999998 * fTemp45)) - ((0.078341055000000007 * fTemp47) + ((((0.026347488299999999 * fTemp38) + (0.018734932400000001 * fTemp39)) + (0.013936473 * fTemp44)) + (0.038515220599999997 * fTemp46)))));
			double fTemp163 = (fConst101 * fRec283[1]);
			double fTemp164 = (fConst102 * fRec286[1]);
			fRec288[0] = (fTemp162 + (fTemp163 + (fRec288[1] + fTemp164)));
			fRec286[0] = fRec288[0];
			double fRec287 = ((fTemp164 + fTemp163) + fTemp162);
			fRec285[0] = (fRec286[0] + fRec285[1]);
			fRec283[0] = fRec285[0];
			double fRec284 = fRec287;
			fRec282[0] = (fTemp160 + (fTemp161 + (fRec284 + fRec282[1])));
			fRec280[0] = fRec282[0];
			double fRec281 = (fTemp160 + (fRec284 + fTemp161));
			fRec279[0] = (fRec280[0] + fRec279[1]);
			fRec277[0] = fRec279[0];
			double fRec278 = fRec281;
			fRec276[0] = (fTemp159 + (fRec278 + fRec276[1]));
			fRec274[0] = fRec276[0];
			double fRec275 = (fRec278 + fTemp159);
			double fTemp165 = (fConst104 * fRec289[1]);
			double fTemp166 = (fConst105 * fRec292[1]);
			double fTemp167 = (fConst107 * ((((0.0427717523 * fTemp56) + (0.025651679300000001 * fTemp57)) + (0.026866896800000001 * fTemp55)) - ((0.065078857599999998 * fTemp61) + ((0.0133093237 * fTemp60) + ((0.011081738799999999 * fTemp59) + (((0.039704409000000003 * fTemp53) + (0.0382424835 * fTemp54)) + (0.0345562674 * fTemp58)))))));
			double fTemp168 = (fConst108 * fRec295[1]);
			double fTemp169 = (fConst109 * fRec298[1]);
			fRec300[0] = (fTemp167 + (fTemp168 + (fRec300[1] + fTemp169)));
			fRec298[0] = fRec300[0];
			double fRec299 = ((fTemp169 + fTemp168) + fTemp167);
			fRec297[0] = (fRec298[0] + fRec297[1]);
			fRec295[0] = fRec297[0];
			double fRec296 = fRec299;
			fRec294[0] = (fTemp165 + (fTemp166 + (fRec296 + fRec294[1])));
			fRec292[0] = fRec294[0];
			double fRec293 = (fTemp165 + (fRec296 + fTemp166));
			fRec291[0] = (fRec292[0] + fRec291[1]);
			fRec289[0] = fRec291[0];
			double fRec290 = fRec293;
			double fTemp170 = (fConst111 * fRec301[1]);
			double fTemp171 = (fConst113 * (((0.027722318400000001 * fTemp69) + (0.0095264601000000001 * fTemp68)) - (((((0.064875679500000005 * fTemp66) + (0.030682623900000001 * fTemp67)) + (0.024102140099999999 * fTemp70)) + (0.036142177400000003 * fTemp71)) + (0.0254269453 * fTemp72))));
			double fTemp172 = (fConst114 * fRec304[1]);
			double fTemp173 = (fConst115 * fRec307[1]);
			fRec309[0] = (fTemp171 + (fTemp172 + (fRec309[1] + fTemp173)));
			fRec307[0] = fRec309[0];
			double fRec308 = ((fTemp173 + fTemp172) + fTemp171);
			fRec306[0] = (fRec307[0] + fRec306[1]);
			fRec304[0] = fRec306[0];
			double fRec305 = fRec308;
			fRec303[0] = (fTemp170 + (fRec305 + fRec303[1]));
			fRec301[0] = fRec303[0];
			double fRec302 = (fRec305 + fTemp170);
			double fTemp174 = (fConst117 * (((0.0081500327000000004 * fTemp77) + (0.034347769799999997 * fTemp78)) - (0.025961405699999999 * fTemp76)));
			double fTemp175 = (fConst118 * fRec310[1]);
			fRec312[0] = (fTemp174 + (fRec312[1] + fTemp175));
			fRec310[0] = fRec312[0];
			double fRec311 = (fTemp175 + fTemp174);
			double fTemp176 = (fConst120 * (((0.017865129099999998 * fTemp83) + (0.0159787136 * fTemp84)) - (((0.0565492067 * fTemp81) + (0.013144476 * fTemp82)) + (0.031266058399999998 * fTemp85))));
			double fTemp177 = (fConst121 * fRec313[1]);
			double fTemp178 = (fConst122 * fRec316[1]);
			fRec318[0] = (fTemp176 + (fTemp177 + (fRec318[1] + fTemp178)));
			fRec316[0] = fRec318[0];
			double fRec317 = ((fTemp178 + fTemp177) + fTemp176);
			fRec315[0] = (fRec316[0] + fRec315[1]);
			fRec313[0] = fRec315[0];
			double fRec314 = fRec317;
			fVec3[(IOTA & 127)] = (((0.028055532099999999 * fTemp7) + ((0.042808336299999999 * fTemp8) + ((0.012989889900000001 * fTemp10) + ((0.0057142885999999999 * fTemp12) + ((0.026940527700000001 * fTemp93) + ((0.031782121500000003 * fTemp91) + ((0.072319400300000003 * fTemp90) + ((0.0149006869 * fTemp13) + (fRec257 + (fRec275 + (fRec290 + (fRec302 + (fRec311 + fRec314))))))))))))) - ((0.012337106299999999 * fTemp97) + ((((0.0058193791 * fTemp11) + ((((0.0073837277999999999 * fTemp92) + (0.0116997466 * fTemp94)) + (0.0470470136 * fTemp89)) + (0.034020597200000002 * fTemp95))) + (0.0079463655999999997 * fTemp9)) + (0.040198327499999999 * fTemp96))));
			output3[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec3[((IOTA - iConst123) & 127)])));
			double fTemp179 = (fConst5 * fRec319[1]);
			double fTemp180 = (fConst6 * fRec322[1]);
			double fTemp181 = (fConst8 * fRec325[1]);
			double fTemp182 = (fConst9 * fRec328[1]);
			double fTemp183 = (fConst11 * (((0.0852753344 * fTemp30) + ((0.0238017703 * fTemp29) + ((0.0041110100999999996 * fTemp24) + (((0.029344067000000001 * fTemp21) + (((((0.0063384872000000004 * fTemp25) + (0.065934042700000001 * fTemp18)) + (0.0037734960999999999 * fTemp27)) + (0.0040380954000000004 * fTemp28)) + (0.0053939440000000003 * fTemp20))) + (0.064239374099999996 * fTemp23))))) - (((0.022153505600000001 * fTemp26) + (0.049845003999999998 * fTemp19)) + (0.0038267895999999999 * fTemp22))));
			double fTemp184 = (fConst12 * fRec331[1]);
			double fTemp185 = (fConst13 * fRec334[1]);
			fRec336[0] = (fTemp183 + (fTemp184 + (fRec336[1] + fTemp185)));
			fRec334[0] = fRec336[0];
			double fRec335 = ((fTemp185 + fTemp184) + fTemp183);
			fRec333[0] = (fRec334[0] + fRec333[1]);
			fRec331[0] = fRec333[0];
			double fRec332 = fRec335;
			fRec330[0] = (fTemp181 + (fTemp182 + (fRec332 + fRec330[1])));
			fRec328[0] = fRec330[0];
			double fRec329 = (fTemp181 + (fRec332 + fTemp182));
			fRec327[0] = (fRec328[0] + fRec327[1]);
			fRec325[0] = fRec327[0];
			double fRec326 = fRec329;
			fRec324[0] = (fTemp179 + (fTemp180 + (fRec326 + fRec324[1])));
			fRec322[0] = fRec324[0];
			double fRec323 = (fTemp179 + (fRec326 + fTemp180));
			fRec321[0] = (fRec322[0] + fRec321[1]);
			fRec319[0] = fRec321[0];
			double fRec320 = fRec323;
			double fTemp186 = (fConst15 * fRec337[1]);
			double fTemp187 = (fConst17 * fRec340[1]);
			double fTemp188 = (fConst18 * fRec343[1]);
			double fTemp189 = (fConst20 * ((((0.0297898495 * fTemp45) + ((0.0307044517 * fTemp44) + ((0.0036895679999999998 * fTemp41) + ((((0.081833013499999996 * fTemp37) + (0.054834235699999997 * fTemp38)) + (0.060459402099999997 * fTemp43)) + (0.046242541800000002 * fTemp40))))) + (0.039613907699999999 * fTemp47)) - (((0.0043437364999999997 * fTemp42) + (0.0107702131 * fTemp39)) + (0.0438127642 * fTemp46))));
			double fTemp190 = (fConst21 * fRec346[1]);
			double fTemp191 = (fConst22 * fRec349[1]);
			fRec351[0] = (fTemp189 + (fTemp190 + (fRec351[1] + fTemp191)));
			fRec349[0] = fRec351[0];
			double fRec350 = ((fTemp191 + fTemp190) + fTemp189);
			fRec348[0] = (fRec349[0] + fRec348[1]);
			fRec346[0] = fRec348[0];
			double fRec347 = fRec350;
			fRec345[0] = (fTemp187 + (fTemp188 + (fRec347 + fRec345[1])));
			fRec343[0] = fRec345[0];
			double fRec344 = (fTemp187 + (fRec347 + fTemp188));
			fRec342[0] = (fRec343[0] + fRec342[1]);
			fRec340[0] = fRec342[0];
			double fRec341 = fRec344;
			fRec339[0] = (fTemp186 + (fRec341 + fRec339[1]));
			fRec337[0] = fRec339[0];
			double fRec338 = (fRec341 + fTemp186);
			double fTemp192 = (fConst24 * fRec352[1]);
			double fTemp193 = (fConst25 * fRec355[1]);
			double fTemp194 = (fConst27 * ((((((0.076292876199999998 * fTemp53) + (0.033044275999999997 * fTemp56)) + (0.055717674699999997 * fTemp57)) + (0.0197401109 * fTemp55)) + (0.020965751000000001 * fTemp59)) - ((0.051095692800000002 * fTemp61) + (((0.0077241684000000001 * fTemp54) + (0.034685050799999999 * fTemp58)) + (0.064498979999999997 * fTemp60)))));
			double fTemp195 = (fConst28 * fRec358[1]);
			double fTemp196 = (fConst29 * fRec361[1]);
			fRec363[0] = (fTemp194 + (fTemp195 + (fRec363[1] + fTemp196)));
			fRec361[0] = fRec363[0];
			double fRec362 = ((fTemp196 + fTemp195) + fTemp194);
			fRec360[0] = (fRec361[0] + fRec360[1]);
			fRec358[0] = fRec360[0];
			double fRec359 = fRec362;
			fRec357[0] = (fTemp192 + (fTemp193 + (fRec359 + fRec357[1])));
			fRec355[0] = fRec357[0];
			double fRec356 = (fTemp192 + (fRec359 + fTemp193));
			fRec354[0] = (fRec355[0] + fRec354[1]);
			fRec352[0] = fRec354[0];
			double fRec353 = fRec356;
			double fTemp197 = (fConst31 * fRec364[1]);
			double fTemp198 = (fConst33 * ((0.041079877600000002 * fTemp69) - ((0.087044369400000002 * fTemp72) + (((((0.0048662371000000003 * fTemp66) + (0.049225619300000002 * fTemp67)) + (0.039881970900000001 * fTemp70)) + (0.0236276347 * fTemp71)) + (0.023181087900000001 * fTemp68)))));
			double fTemp199 = (fConst34 * fRec367[1]);
			double fTemp200 = (fConst35 * fRec370[1]);
			fRec372[0] = (fTemp198 + (fTemp199 + (fRec372[1] + fTemp200)));
			fRec370[0] = fRec372[0];
			double fRec371 = ((fTemp200 + fTemp199) + fTemp198);
			fRec369[0] = (fRec370[0] + fRec369[1]);
			fRec367[0] = fRec369[0];
			double fRec368 = fRec371;
			fRec366[0] = (fTemp197 + (fRec368 + fRec366[1]));
			fRec364[0] = fRec366[0];
			double fRec365 = (fRec368 + fTemp197);
			double fTemp201 = (fConst37 * (((0.014932782 * fTemp77) + (0.029763579500000002 * fTemp78)) - (0.0489911445 * fTemp76)));
			double fTemp202 = (fConst38 * fRec373[1]);
			fRec375[0] = (fTemp201 + (fRec375[1] + fTemp202));
			fRec373[0] = fRec375[0];
			double fRec374 = (fTemp202 + fTemp201);
			double fTemp203 = (fConst40 * ((0.0211000418 * fTemp83) - ((((0.067345779199999997 * fTemp81) + (0.033116199399999997 * fTemp82)) + (0.037278278400000003 * fTemp85)) + (0.035280652199999998 * fTemp84))));
			double fTemp204 = (fConst41 * fRec376[1]);
			double fTemp205 = (fConst42 * fRec379[1]);
			fRec381[0] = (fTemp203 + (fTemp204 + (fRec381[1] + fTemp205)));
			fRec379[0] = fRec381[0];
			double fRec380 = ((fTemp205 + fTemp204) + fTemp203);
			fRec378[0] = (fRec379[0] + fRec378[1]);
			fRec376[0] = fRec378[0];
			double fRec377 = fRec380;
			fVec4[(IOTA & 127)] = (((0.042926965900000003 * fTemp97) + ((0.063991845699999994 * fTemp96) + ((0.0307503875 * fTemp8) + ((0.0095517207999999999 * fTemp9) + ((0.011390989299999999 * fTemp11) + ((0.0082284643000000001 * fTemp94) + (((0.020303679599999999 * fTemp13) + (fRec320 + (fRec338 + (fRec353 + (fRec365 + (fRec374 + fRec377)))))) + (0.0128728822 * fTemp91)))))))) - ((((0.029989871899999999 * fTemp95) + ((0.0141738384 * fTemp12) + ((((0.063583088600000004 * fTemp90) + (0.0074886934000000004 * fTemp92)) + (0.048116648099999999 * fTemp93)) + (0.039855634000000001 * fTemp89)))) + (0.024103117399999999 * fTemp10)) + (0.016280880599999999 * fTemp7)));
			output4[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec4[((IOTA - iConst43) & 127)])));
			double fTemp206 = (fConst45 * fRec382[1]);
			double fTemp207 = (fConst46 * fRec385[1]);
			double fTemp208 = (fConst48 * fRec388[1]);
			double fTemp209 = (fConst49 * fRec391[1]);
			double fTemp210 = (fConst51 * ((((0.0070229806000000001 * fTemp21) + (0.021307871999999999 * fTemp23)) + (0.0343861705 * fTemp29)) - (((((0.012781703 * fTemp20) + ((((((0.056799112200000001 * fTemp25) + (0.036748901399999999 * fTemp18)) + (0.0155577379 * fTemp26)) + (0.046588053900000002 * fTemp27)) + (0.0040612034999999999 * fTemp28)) + (0.050065874599999997 * fTemp19))) + (0.0213688387 * fTemp22)) + (0.031470864100000003 * fTemp24)) + (0.052895171400000003 * fTemp30))));
			double fTemp211 = (fConst52 * fRec394[1]);
			double fTemp212 = (fConst53 * fRec397[1]);
			fRec399[0] = (fTemp210 + (fTemp211 + (fRec399[1] + fTemp212)));
			fRec397[0] = fRec399[0];
			double fRec398 = ((fTemp212 + fTemp211) + fTemp210);
			fRec396[0] = (fRec397[0] + fRec396[1]);
			fRec394[0] = fRec396[0];
			double fRec395 = fRec398;
			fRec393[0] = (fTemp208 + (fTemp209 + (fRec395 + fRec393[1])));
			fRec391[0] = fRec393[0];
			double fRec392 = (fTemp208 + (fRec395 + fTemp209));
			fRec390[0] = (fRec391[0] + fRec390[1]);
			fRec388[0] = fRec390[0];
			double fRec389 = fRec392;
			fRec387[0] = (fTemp206 + (fTemp207 + (fRec389 + fRec387[1])));
			fRec385[0] = fRec387[0];
			double fRec386 = (fTemp206 + (fRec389 + fTemp207));
			fRec384[0] = (fRec385[0] + fRec384[1]);
			fRec382[0] = fRec384[0];
			double fRec383 = fRec386;
			double fTemp213 = (fConst55 * fRec400[1]);
			double fTemp214 = (fConst57 * fRec403[1]);
			double fTemp215 = (fConst58 * fRec406[1]);
			double fTemp216 = (fConst60 * (((0.049801534699999997 * fTemp47) + ((0.038476119000000003 * fTemp46) + ((0.014415492699999999 * fTemp45) + ((0.046709437600000001 * fTemp44) + ((0.00333103 * fTemp41) + (((0.026420590300000001 * fTemp38) + (0.013953110899999999 * fTemp43)) + (0.034537437800000001 * fTemp40))))))) - (((0.060931701800000002 * fTemp37) + (0.037739563400000002 * fTemp42)) + (0.0297501869 * fTemp39))));
			double fTemp217 = (fConst61 * fRec409[1]);
			double fTemp218 = (fConst62 * fRec412[1]);
			fRec414[0] = (fTemp216 + (fTemp217 + (fRec414[1] + fTemp218)));
			fRec412[0] = fRec414[0];
			double fRec413 = ((fTemp218 + fTemp217) + fTemp216);
			fRec411[0] = (fRec412[0] + fRec411[1]);
			fRec409[0] = fRec411[0];
			double fRec410 = fRec413;
			fRec408[0] = (fTemp214 + (fTemp215 + (fRec410 + fRec408[1])));
			fRec406[0] = fRec408[0];
			double fRec407 = (fTemp214 + (fRec410 + fTemp215));
			fRec405[0] = (fRec406[0] + fRec405[1]);
			fRec403[0] = fRec405[0];
			double fRec404 = fRec407;
			fRec402[0] = (fTemp213 + (fRec404 + fRec402[1]));
			fRec400[0] = fRec402[0];
			double fRec401 = (fRec404 + fTemp213);
			double fTemp219 = (fConst64 * fRec415[1]);
			double fTemp220 = (fConst65 * fRec418[1]);
			double fTemp221 = (fConst67 * ((((((((0.039754495799999998 * fTemp53) + (0.0364189397 * fTemp54)) + (0.011072909000000001 * fTemp56)) + (0.042518380500000001 * fTemp57)) + (0.026792149099999999 * fTemp55)) + (0.042662779200000001 * fTemp59)) + (0.064943307899999997 * fTemp61)) - ((0.0063062281999999997 * fTemp58) + (0.017677154800000001 * fTemp60))));
			double fTemp222 = (fConst68 * fRec421[1]);
			double fTemp223 = (fConst69 * fRec424[1]);
			fRec426[0] = (fTemp221 + (fTemp222 + (fRec426[1] + fTemp223)));
			fRec424[0] = fRec426[0];
			double fRec425 = ((fTemp223 + fTemp222) + fTemp221);
			fRec423[0] = (fRec424[0] + fRec423[1]);
			fRec421[0] = fRec423[0];
			double fRec422 = fRec425;
			fRec420[0] = (fTemp219 + (fTemp220 + (fRec422 + fRec420[1])));
			fRec418[0] = fRec420[0];
			double fRec419 = (fTemp219 + (fRec422 + fTemp220));
			fRec417[0] = (fRec418[0] + fRec417[1]);
			fRec415[0] = fRec417[0];
			double fRec416 = fRec419;
			double fTemp224 = (fConst71 * fRec427[1]);
			double fTemp225 = (fConst73 * (((0.063723541300000006 * fTemp66) + (0.045048390200000003 * fTemp69)) - ((0.027924622400000002 * fTemp72) + ((((0.0095516922999999993 * fTemp67) + (0.024077398900000001 * fTemp70)) + (0.0059519671999999999 * fTemp71)) + (0.030657397100000001 * fTemp68)))));
			double fTemp226 = (fConst74 * fRec430[1]);
			double fTemp227 = (fConst75 * fRec433[1]);
			fRec435[0] = (fTemp225 + (fTemp226 + (fRec435[1] + fTemp227)));
			fRec433[0] = fRec435[0];
			double fRec434 = ((fTemp227 + fTemp226) + fTemp225);
			fRec432[0] = (fRec433[0] + fRec432[1]);
			fRec430[0] = fRec432[0];
			double fRec431 = fRec434;
			fRec429[0] = (fTemp224 + (fRec431 + fRec429[1]));
			fRec427[0] = fRec429[0];
			double fRec428 = (fRec431 + fTemp224);
			double fTemp228 = (fConst77 * (((0.0081455725999999996 * fTemp77) + (0.0059358450000000004 * fTemp78)) - (0.042561055899999999 * fTemp76)));
			double fTemp229 = (fConst78 * fRec436[1]);
			fRec438[0] = (fTemp228 + (fRec438[1] + fTemp229));
			fRec436[0] = fRec438[0];
			double fRec437 = (fTemp229 + fTemp228);
			double fTemp230 = (fConst80 * ((0.0033472354000000002 * fTemp83) - ((((0.015994445400000001 * fTemp81) + (0.021911849000000001 * fTemp82)) + (0.031196030900000001 * fTemp85)) + (0.0564357786 * fTemp84))));
			double fTemp231 = (fConst81 * fRec439[1]);
			double fTemp232 = (fConst82 * fRec442[1]);
			fRec444[0] = (fTemp230 + (fTemp231 + (fRec444[1] + fTemp232)));
			fRec442[0] = fRec444[0];
			double fRec443 = ((fTemp232 + fTemp231) + fTemp230);
			fRec441[0] = (fRec442[0] + fRec441[1]);
			fRec439[0] = fRec441[0];
			double fRec440 = fRec443;
			fVec5[(IOTA & 127)] = (((0.0081648411000000004 * fTemp12) + ((0.0138754286 * fTemp94) + ((0.025021253699999999 * fTemp92) + ((0.042291155499999997 * fTemp90) + ((0.0148720972 * fTemp13) + (fRec383 + (fRec401 + (fRec416 + (fRec428 + (fRec437 + fRec440)))))))))) - ((0.059995132399999998 * fTemp97) + ((0.031739395599999998 * fTemp96) + ((0.014588901600000001 * fTemp7) + ((0.042760027499999999 * fTemp8) + ((0.0026372886 * fTemp9) + ((0.046960860600000001 * fTemp10) + ((7.1952099999999998e-05 * fTemp11) + ((((0.040334024500000003 * fTemp91) + (0.026970923599999998 * fTemp93)) + (0.012987298499999999 * fTemp89)) + (0.033948507500000003 * fTemp95))))))))));
			output5[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec5[((IOTA - iConst83) & 127)])));
			double fTemp233 = (fConst45 * fRec445[1]);
			double fTemp234 = (fConst46 * fRec448[1]);
			double fTemp235 = (fConst48 * fRec451[1]);
			double fTemp236 = (fConst49 * fRec454[1]);
			double fTemp237 = (fConst51 * ((((((0.085301436499999994 * fTemp25) + (0.022309709399999999 * fTemp26)) + (0.0039328447000000002 * fTemp28)) + (0.0052381772999999998 * fTemp20)) + (0.0038539568999999998 * fTemp22)) - ((0.0063980953 * fTemp30) + ((0.0633593717 * fTemp29) + ((0.004198579 * fTemp24) + (((((0.029841346500000001 * fTemp18) + (0.0481317073 * fTemp27)) + (0.056071481200000002 * fTemp19)) + (0.0145041532 * fTemp21)) + (0.042746519099999998 * fTemp23)))))));
			double fTemp238 = (fConst52 * fRec457[1]);
			double fTemp239 = (fConst53 * fRec460[1]);
			fRec462[0] = (fTemp237 + (fTemp238 + (fRec462[1] + fTemp239)));
			fRec460[0] = fRec462[0];
			double fRec461 = ((fTemp239 + fTemp238) + fTemp237);
			fRec459[0] = (fRec460[0] + fRec459[1]);
			fRec457[0] = fRec459[0];
			double fRec458 = fRec461;
			fRec456[0] = (fTemp235 + (fTemp236 + (fRec458 + fRec456[1])));
			fRec454[0] = fRec456[0];
			double fRec455 = (fTemp235 + (fRec458 + fTemp236));
			fRec453[0] = (fRec454[0] + fRec453[1]);
			fRec451[0] = fRec453[0];
			double fRec452 = fRec455;
			fRec450[0] = (fTemp233 + (fTemp234 + (fRec452 + fRec450[1])));
			fRec448[0] = fRec450[0];
			double fRec449 = (fTemp233 + (fRec452 + fTemp234));
			fRec447[0] = (fRec448[0] + fRec447[1]);
			fRec445[0] = fRec447[0];
			double fRec446 = fRec449;
			double fTemp240 = (fConst55 * fRec463[1]);
			double fTemp241 = (fConst57 * fRec466[1]);
			double fTemp242 = (fConst58 * fRec469[1]);
			double fTemp243 = (fConst60 * ((((0.046266294999999999 * fTemp40) + (0.060477216299999997 * fTemp44)) + (0.043826655700000001 * fTemp46)) - ((((((((0.0299252224 * fTemp37) + (0.0547572105 * fTemp38)) + (0.018137263099999999 * fTemp42)) + (0.030689946499999999 * fTemp43)) + (0.0104456286 * fTemp39)) + (0.0050640388999999997 * fTemp41)) + (0.024272888699999998 * fTemp45)) + (0.085945946800000006 * fTemp47))));
			double fTemp244 = (fConst61 * fRec472[1]);
			double fTemp245 = (fConst62 * fRec475[1]);
			fRec477[0] = (fTemp243 + (fTemp244 + (fRec477[1] + fTemp245)));
			fRec475[0] = fRec477[0];
			double fRec476 = ((fTemp245 + fTemp244) + fTemp243);
			fRec474[0] = (fRec475[0] + fRec474[1]);
			fRec472[0] = fRec474[0];
			double fRec473 = fRec476;
			fRec471[0] = (fTemp241 + (fTemp242 + (fRec473 + fRec471[1])));
			fRec469[0] = fRec471[0];
			double fRec470 = (fTemp241 + (fRec473 + fTemp242));
			fRec468[0] = (fRec469[0] + fRec468[1]);
			fRec466[0] = fRec468[0];
			double fRec467 = fRec470;
			fRec465[0] = (fTemp240 + (fRec467 + fRec465[1]));
			fRec463[0] = fRec465[0];
			double fRec464 = (fRec467 + fTemp240);
			double fTemp246 = (fConst64 * fRec478[1]);
			double fTemp247 = (fConst65 * fRec481[1]);
			double fTemp248 = (fConst67 * (((0.051192006700000001 * fTemp61) + ((0.040089391299999999 * fTemp60) + ((0.0332188452 * fTemp59) + ((0.014860421 * fTemp58) + (((0.051056363799999997 * fTemp54) + (0.063915328499999993 * fTemp57)) + (0.0198919441 * fTemp55)))))) - ((0.076380795400000007 * fTemp53) + (0.021058597599999999 * fTemp56))));
			double fTemp249 = (fConst68 * fRec484[1]);
			double fTemp250 = (fConst69 * fRec487[1]);
			fRec489[0] = (fTemp248 + (fTemp249 + (fRec489[1] + fTemp250)));
			fRec487[0] = fRec489[0];
			double fRec488 = ((fTemp250 + fTemp249) + fTemp248);
			fRec486[0] = (fRec487[0] + fRec486[1]);
			fRec484[0] = fRec486[0];
			double fRec485 = fRec488;
			fRec483[0] = (fTemp246 + (fTemp247 + (fRec485 + fRec483[1])));
			fRec481[0] = fRec483[0];
			double fRec482 = (fTemp246 + (fRec485 + fTemp247));
			fRec480[0] = (fRec481[0] + fRec480[1]);
			fRec478[0] = fRec480[0];
			double fRec479 = fRec482;
			double fTemp251 = (fConst71 * fRec490[1]);
			double fTemp252 = (fConst73 * ((((((0.065106436899999995 * fTemp66) + (0.023147146699999999 * fTemp67)) + (0.045924851199999998 * fTemp69)) + (0.0123815399 * fTemp71)) + (0.058187098499999999 * fTemp72)) - ((0.039861520099999999 * fTemp70) + (0.049196949800000001 * fTemp68))));
			double fTemp253 = (fConst74 * fRec493[1]);
			double fTemp254 = (fConst75 * fRec496[1]);
			fRec498[0] = (fTemp252 + (fTemp253 + (fRec498[1] + fTemp254)));
			fRec496[0] = fRec498[0];
			double fRec497 = ((fTemp254 + fTemp253) + fTemp252);
			fRec495[0] = (fRec496[0] + fRec495[1]);
			fRec493[0] = fRec495[0];
			double fRec494 = fRec497;
			fRec492[0] = (fTemp251 + (fRec494 + fRec492[1]));
			fRec490[0] = fRec492[0];
			double fRec491 = (fRec494 + fTemp251);
			double fTemp255 = (fConst77 * ((0.014918545300000001 * fTemp77) - ((0.055779355500000002 * fTemp76) + (0.0136150345 * fTemp78))));
			double fTemp256 = (fConst78 * fRec499[1]);
			fRec501[0] = (fTemp255 + (fRec501[1] + fTemp256));
			fRec499[0] = fRec501[0];
			double fRec500 = (fTemp256 + fTemp255);
			double fTemp257 = (fConst80 * ((0.035331008300000001 * fTemp81) - ((((0.038305967500000003 * fTemp82) + (0.037373407400000003 * fTemp85)) + (0.0084833896000000002 * fTemp83)) + (0.0674619682 * fTemp84))));
			double fTemp258 = (fConst81 * fRec502[1]);
			double fTemp259 = (fConst82 * fRec505[1]);
			fRec507[0] = (fTemp257 + (fTemp258 + (fRec507[1] + fTemp259)));
			fRec505[0] = fRec507[0];
			double fRec506 = ((fTemp259 + fTemp258) + fTemp257);
			fRec504[0] = (fRec505[0] + fRec504[1]);
			fRec502[0] = fRec504[0];
			double fRec503 = fRec506;
			fVec6[(IOTA & 127)] = (((0.075282293 * fTemp97) + ((0.016951642400000001 * fTemp7) + ((0.0241306097 * fTemp89) + ((0.048112724799999999 * fTemp93) + (((0.020334412400000001 * fTemp13) + (fRec446 + (fRec464 + (fRec479 + (fRec491 + (fRec500 + fRec503)))))) + (0.063887755399999996 * fTemp91)))))) - ((0.012963223100000001 * fTemp96) + ((0.030799159900000001 * fTemp8) + ((0.00080932390000000001 * fTemp9) + ((0.039954108600000003 * fTemp10) + ((0.0019201501000000001 * fTemp11) + ((0.030081546000000001 * fTemp95) + ((((0.014532586300000001 * fTemp90) + (0.0061939381999999996 * fTemp92)) + (0.012454086099999999 * fTemp94)) + (0.017905310399999999 * fTemp12)))))))));
			output6[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec6[((IOTA - iConst83) & 127)])));
			double fTemp260 = (fConst85 * fRec508[1]);
			double fTemp261 = (fConst86 * fRec511[1]);
			double fTemp262 = (fConst88 * fRec514[1]);
			double fTemp263 = (fConst89 * fRec517[1]);
			double fTemp264 = (fConst91 * (((0.056783211799999997 * fTemp30) + ((0.0016684776 * fTemp29) + (((((0.050437570199999997 * fTemp18) + (0.015522059899999999 * fTemp26)) + (0.0178872089 * fTemp27)) + (0.0212214885 * fTemp28)) + (0.031404108799999997 * fTemp24)))) - ((0.048171660900000003 * fTemp23) + ((0.0040178920999999999 * fTemp22) + ((0.030507620499999999 * fTemp21) + ((0.012654312500000001 * fTemp20) + ((0.052961546700000001 * fTemp25) + (0.040498353399999999 * fTemp19))))))));
			double fTemp265 = (fConst92 * fRec520[1]);
			double fTemp266 = (fConst93 * fRec523[1]);
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
			double fTemp267 = (fConst95 * fRec526[1]);
			double fTemp268 = (fConst97 * fRec529[1]);
			double fTemp269 = (fConst98 * fRec532[1]);
			double fTemp270 = (fConst100 * ((((((0.078365057599999996 * fTemp37) + (0.016469102999999999 * fTemp42)) + (0.034664118399999999 * fTemp40)) + (0.014030683800000001 * fTemp44)) + (0.0079017691000000008 * fTemp47)) - ((0.038600158199999998 * fTemp46) + (((((0.026523832600000002 * fTemp38) + (0.046873431 * fTemp43)) + (0.023311165299999999 * fTemp39)) + (0.018617883299999999 * fTemp41)) + (0.036838917999999998 * fTemp45)))));
			double fTemp271 = (fConst101 * fRec535[1]);
			double fTemp272 = (fConst102 * fRec538[1]);
			fRec540[0] = (fTemp270 + (fTemp271 + (fRec540[1] + fTemp272)));
			fRec538[0] = fRec540[0];
			double fRec539 = ((fTemp272 + fTemp271) + fTemp270);
			fRec537[0] = (fRec538[0] + fRec537[1]);
			fRec535[0] = fRec537[0];
			double fRec536 = fRec539;
			fRec534[0] = (fTemp268 + (fTemp269 + (fRec536 + fRec534[1])));
			fRec532[0] = fRec534[0];
			double fRec533 = (fTemp268 + (fRec536 + fTemp269));
			fRec531[0] = (fRec532[0] + fRec531[1]);
			fRec529[0] = fRec531[0];
			double fRec530 = fRec533;
			fRec528[0] = (fTemp267 + (fRec530 + fRec528[1]));
			fRec526[0] = fRec528[0];
			double fRec527 = (fRec530 + fTemp267);
			double fTemp273 = (fConst104 * fRec541[1]);
			double fTemp274 = (fConst105 * fRec544[1]);
			double fTemp275 = (fConst107 * (((0.038409235399999998 * fTemp60) + ((0.011077795 * fTemp59) + ((0.0257042837 * fTemp58) + ((0.034674740900000001 * fTemp57) + (0.026766206800000001 * fTemp55))))) - ((((0.039800237299999999 * fTemp53) + (0.013292439499999999 * fTemp54)) + (0.042654017900000001 * fTemp56)) + (0.065025436399999997 * fTemp61))));
			double fTemp276 = (fConst108 * fRec547[1]);
			double fTemp277 = (fConst109 * fRec550[1]);
			fRec552[0] = (fTemp275 + (fTemp276 + (fRec552[1] + fTemp277)));
			fRec550[0] = fRec552[0];
			double fRec551 = ((fTemp277 + fTemp276) + fTemp275);
			fRec549[0] = (fRec550[0] + fRec549[1]);
			fRec547[0] = fRec549[0];
			double fRec548 = fRec551;
			fRec546[0] = (fTemp273 + (fTemp274 + (fRec548 + fRec546[1])));
			fRec544[0] = fRec546[0];
			double fRec545 = (fTemp273 + (fRec548 + fTemp274));
			fRec543[0] = (fRec544[0] + fRec543[1]);
			fRec541[0] = fRec543[0];
			double fRec542 = fRec545;
			double fTemp278 = (fConst111 * fRec553[1]);
			double fTemp279 = (fConst113 * (((((0.030790350300000002 * fTemp67) + (0.0360911441 * fTemp69)) + (0.0276617423 * fTemp71)) + (0.064907633800000003 * fTemp72)) - (((0.025348098499999999 * fTemp66) + (0.024186315999999999 * fTemp70)) + (0.0096018156000000007 * fTemp68))));
			double fTemp280 = (fConst114 * fRec556[1]);
			double fTemp281 = (fConst115 * fRec559[1]);
			fRec561[0] = (fTemp279 + (fTemp280 + (fRec561[1] + fTemp281)));
			fRec559[0] = fRec561[0];
			double fRec560 = ((fTemp281 + fTemp280) + fTemp279);
			fRec558[0] = (fRec559[0] + fRec558[1]);
			fRec556[0] = fRec558[0];
			double fRec557 = fRec560;
			fRec555[0] = (fTemp278 + (fRec557 + fRec555[1]));
			fRec553[0] = fRec555[0];
			double fRec554 = (fRec557 + fTemp278);
			double fTemp282 = (fConst117 * ((0.0081851201999999998 * fTemp77) - ((0.034363525800000003 * fTemp76) + (0.025948127299999998 * fTemp78))));
			double fTemp283 = (fConst118 * fRec562[1]);
			fRec564[0] = (fTemp282 + (fRec564[1] + fTemp283));
			fRec562[0] = fRec564[0];
			double fRec563 = (fTemp283 + fTemp282);
			double fTemp284 = (fConst120 * ((0.056536760899999997 * fTemp81) - ((((0.017946540300000001 * fTemp82) + (0.031241391699999999 * fTemp85)) + (0.013186598500000001 * fTemp83)) + (0.016029248199999999 * fTemp84))));
			double fTemp285 = (fConst121 * fRec565[1]);
			double fTemp286 = (fConst122 * fRec568[1]);
			fRec570[0] = (fTemp284 + (fTemp285 + (fRec570[1] + fTemp286)));
			fRec568[0] = fRec570[0];
			double fRec569 = ((fTemp286 + fTemp285) + fTemp284);
			fRec567[0] = (fRec568[0] + fRec567[1]);
			fRec565[0] = fRec567[0];
			double fRec566 = fRec569;
			fVec7[(IOTA & 127)] = (((0.040398669599999999 * fTemp96) + ((0.042825023599999998 * fTemp8) + ((0.0115049473 * fTemp9) + ((0.0055906339000000001 * fTemp11) + ((0.0056389159999999999 * fTemp12) + ((0.047039059299999998 * fTemp89) + (((0.0149042737 * fTemp13) + (fRec509 + (fRec527 + (fRec542 + (fRec554 + (fRec563 + fRec566)))))) + (0.0270832383 * fTemp93)))))))) - ((0.072341845599999996 * fTemp97) + (((((((0.012413231699999999 * fTemp90) + (0.031808815099999999 * fTemp91)) + (0.0279203334 * fTemp92)) + (0.0078902361999999993 * fTemp94)) + (0.034006900600000001 * fTemp95)) + (0.0130571422 * fTemp10)) + (0.0073674172000000003 * fTemp7))));
			output7[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec7[((IOTA - iConst123) & 127)])));
			double fTemp287 = (fConst5 * fRec571[1]);
			double fTemp288 = (fConst6 * fRec574[1]);
			double fTemp289 = (fConst8 * fRec577[1]);
			double fTemp290 = (fConst9 * fRec580[1]);
			double fTemp291 = (fConst11 * (((0.065892859999999998 * fTemp29) + ((((0.064184768200000006 * fTemp27) + (0.0053708502 * fTemp20)) + (0.0038458903999999999 * fTemp22)) + (0.0040796731999999999 * fTemp24))) - ((((((((0.0062293195000000003 * fTemp25) + (0.023822200700000001 * fTemp18)) + (0.022178792999999999 * fTemp26)) + (0.0040264404000000002 * fTemp28)) + (0.0292989723 * fTemp19)) + (0.049787085500000001 * fTemp21)) + (0.0037437271000000001 * fTemp23)) + (0.085296565199999994 * fTemp30))));
			double fTemp292 = (fConst12 * fRec583[1]);
			double fTemp293 = (fConst13 * fRec586[1]);
			fRec588[0] = (fTemp291 + (fTemp292 + (fRec588[1] + fTemp293)));
			fRec586[0] = fRec588[0];
			double fRec587 = ((fTemp293 + fTemp292) + fTemp291);
			fRec585[0] = (fRec586[0] + fRec585[1]);
			fRec583[0] = fRec585[0];
			double fRec584 = fRec587;
			fRec582[0] = (fTemp289 + (fTemp290 + (fRec584 + fRec582[1])));
			fRec580[0] = fRec582[0];
			double fRec581 = (fTemp289 + (fRec584 + fTemp290));
			fRec579[0] = (fRec580[0] + fRec579[1]);
			fRec577[0] = fRec579[0];
			double fRec578 = fRec581;
			fRec576[0] = (fTemp287 + (fTemp288 + (fRec578 + fRec576[1])));
			fRec574[0] = fRec576[0];
			double fRec575 = (fTemp287 + (fRec578 + fTemp288));
			fRec573[0] = (fRec574[0] + fRec573[1]);
			fRec571[0] = fRec573[0];
			double fRec572 = fRec575;
			double fTemp294 = (fConst15 * fRec589[1]);
			double fTemp295 = (fConst17 * fRec592[1]);
			double fTemp296 = (fConst18 * fRec595[1]);
			double fTemp297 = (fConst20 * ((((((0.054824273200000002 * fTemp38) + (0.029798077999999999 * fTemp42)) + (0.046192445800000002 * fTemp40)) + (0.0043782910999999999 * fTemp45)) + (0.081796242800000002 * fTemp47)) - (((0.030694920800000001 * fTemp44) + ((((0.0397107695 * fTemp37) + (0.060395179200000003 * fTemp43)) + (0.003692084 * fTemp39)) + (0.0107898712 * fTemp41))) + (0.043762866499999997 * fTemp46))));
			double fTemp298 = (fConst21 * fRec598[1]);
			double fTemp299 = (fConst22 * fRec601[1]);
			fRec603[0] = (fTemp297 + (fTemp298 + (fRec603[1] + fTemp299)));
			fRec601[0] = fRec603[0];
			double fRec602 = ((fTemp299 + fTemp298) + fTemp297);
			fRec600[0] = (fRec601[0] + fRec600[1]);
			fRec598[0] = fRec600[0];
			double fRec599 = fRec602;
			fRec597[0] = (fTemp295 + (fTemp296 + (fRec599 + fRec597[1])));
			fRec595[0] = fRec597[0];
			double fRec596 = (fTemp295 + (fRec599 + fTemp296));
			fRec594[0] = (fRec595[0] + fRec594[1]);
			fRec592[0] = fRec594[0];
			double fRec593 = fRec596;
			fRec591[0] = (fTemp294 + (fRec593 + fRec591[1]));
			fRec589[0] = fRec591[0];
			double fRec590 = (fRec593 + fTemp294);
			double fTemp300 = (fConst24 * fRec604[1]);
			double fTemp301 = (fConst25 * fRec607[1]);
			double fTemp302 = (fConst27 * ((((0.055673970599999997 * fTemp58) + (((0.076344546200000002 * fTemp53) + (0.034645651999999999 * fTemp57)) + (0.019746962999999999 * fTemp55))) + (0.0076935431999999998 * fTemp60)) - ((((0.064461201600000004 * fTemp54) + (0.033036260300000002 * fTemp56)) + (0.020991414600000001 * fTemp59)) + (0.051025525299999999 * fTemp61))));
			double fTemp303 = (fConst28 * fRec610[1]);
			double fTemp304 = (fConst29 * fRec613[1]);
			fRec615[0] = (fTemp302 + (fTemp303 + (fRec615[1] + fTemp304)));
			fRec613[0] = fRec615[0];
			double fRec614 = ((fTemp304 + fTemp303) + fTemp302);
			fRec612[0] = (fRec613[0] + fRec612[1]);
			fRec610[0] = fRec612[0];
			double fRec611 = fRec614;
			fRec609[0] = (fTemp300 + (fTemp301 + (fRec611 + fRec609[1])));
			fRec607[0] = fRec609[0];
			double fRec608 = (fTemp300 + (fRec611 + fTemp301));
			fRec606[0] = (fRec607[0] + fRec606[1]);
			fRec604[0] = fRec606[0];
			double fRec605 = fRec608;
			double fTemp305 = (fConst31 * fRec616[1]);
			double fTemp306 = (fConst33 * (((0.0048022951000000003 * fTemp72) + ((0.023179443500000001 * fTemp68) + (((0.049185379100000003 * fTemp67) + (0.0236157169 * fTemp69)) + (0.0410878561 * fTemp71)))) - ((0.087046728399999995 * fTemp66) + (0.039849832500000001 * fTemp70))));
			double fTemp307 = (fConst34 * fRec619[1]);
			double fTemp308 = (fConst35 * fRec622[1]);
			fRec624[0] = (fTemp306 + (fTemp307 + (fRec624[1] + fTemp308)));
			fRec622[0] = fRec624[0];
			double fRec623 = ((fTemp308 + fTemp307) + fTemp306);
			fRec621[0] = (fRec622[0] + fRec621[1]);
			fRec619[0] = fRec621[0];
			double fRec620 = fRec623;
			fRec618[0] = (fTemp305 + (fRec620 + fRec618[1]));
			fRec616[0] = fRec618[0];
			double fRec617 = (fRec620 + fTemp305);
			double fTemp309 = (fConst37 * ((0.0149227358 * fTemp77) - ((0.029748477400000001 * fTemp76) + (0.048993963699999997 * fTemp78))));
			double fTemp310 = (fConst38 * fRec625[1]);
			fRec627[0] = (fTemp309 + (fRec627[1] + fTemp310));
			fRec625[0] = fRec627[0];
			double fRec626 = (fTemp310 + fTemp309);
			double fTemp311 = (fConst40 * (((0.067324036099999998 * fTemp81) + (0.035312055600000003 * fTemp84)) - (((0.0210804279 * fTemp82) + (0.0372758714 * fTemp85)) + (0.033096336300000001 * fTemp83))));
			double fTemp312 = (fConst41 * fRec628[1]);
			double fTemp313 = (fConst42 * fRec631[1]);
			fRec633[0] = (fTemp311 + (fTemp312 + (fRec633[1] + fTemp313)));
			fRec631[0] = fRec633[0];
			double fRec632 = ((fTemp313 + fTemp312) + fTemp311);
			fRec630[0] = (fRec631[0] + fRec630[1]);
			fRec628[0] = fRec630[0];
			double fRec629 = fRec632;
			fVec8[(IOTA & 127)] = (((0.063656310699999996 * fTemp97) + ((0.0307052069 * fTemp8) + ((0.024080925600000001 * fTemp10) + ((0.039790668600000002 * fTemp89) + ((0.0095422804000000003 * fTemp94) + ((0.0163181999 * fTemp92) + ((0.042845247400000001 * fTemp90) + ((0.0203014626 * fTemp13) + (fRec572 + (fRec590 + (fRec605 + (fRec617 + (fRec626 + fRec629))))))))))))) - ((0.063975188299999999 * fTemp96) + ((((0.014140056099999999 * fTemp11) + ((0.029941033999999998 * fTemp95) + (((0.012843054 * fTemp91) + (0.048093086899999998 * fTemp93)) + (0.0113737557 * fTemp12)))) + (0.0082417451999999992 * fTemp9)) + (0.0074678695999999996 * fTemp7))));
			output8[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec8[((IOTA - iConst43) & 127)])));
			double fTemp314 = (fConst45 * fRec634[1]);
			double fTemp315 = (fConst46 * fRec637[1]);
			double fTemp316 = (fConst48 * fRec640[1]);
			double fTemp317 = (fConst49 * fRec643[1]);
			double fTemp318 = (fConst51 * ((((0.046621868400000002 * fTemp23) + ((((0.056808109599999997 * fTemp25) + (0.021304158199999999 * fTemp27)) + (0.0040171075000000004 * fTemp28)) + (0.021254869999999999 * fTemp22))) + (0.052981261799999999 * fTemp30)) - ((0.0368587347 * fTemp29) + (((0.050059243199999999 * fTemp21) + ((0.0126893908 * fTemp20) + (((0.034409563099999999 * fTemp18) + (0.01550261 * fTemp26)) + (0.0070177284999999997 * fTemp19)))) + (0.031406419800000002 * fTemp24)))));
			double fTemp319 = (fConst52 * fRec646[1]);
			double fTemp320 = (fConst53 * fRec649[1]);
			fRec651[0] = (fTemp318 + (fTemp319 + (fRec651[1] + fTemp320)));
			fRec649[0] = fRec651[0];
			double fRec650 = ((fTemp320 + fTemp319) + fTemp318);
			fRec648[0] = (fRec649[0] + fRec648[1]);
			fRec646[0] = fRec648[0];
			double fRec647 = fRec650;
			fRec645[0] = (fTemp316 + (fTemp317 + (fRec647 + fRec645[1])));
			fRec643[0] = fRec645[0];
			double fRec644 = (fTemp316 + (fRec647 + fTemp317));
			fRec642[0] = (fRec643[0] + fRec642[1]);
			fRec640[0] = fRec642[0];
			double fRec641 = fRec644;
			fRec639[0] = (fTemp314 + (fTemp315 + (fRec641 + fRec639[1])));
			fRec637[0] = fRec639[0];
			double fRec638 = (fTemp314 + (fRec641 + fTemp315));
			fRec636[0] = (fRec637[0] + fRec636[1]);
			fRec634[0] = fRec636[0];
			double fRec635 = fRec638;
			double fTemp321 = (fConst55 * fRec652[1]);
			double fTemp322 = (fConst57 * fRec655[1]);
			double fTemp323 = (fConst58 * fRec658[1]);
			double fTemp324 = (fConst60 * (((0.0385799639 * fTemp46) + ((((0.026439957300000001 * fTemp38) + (0.014376998699999999 * fTemp42)) + (0.034563989599999997 * fTemp40)) + (0.0376880531 * fTemp45))) - (((0.046764931199999998 * fTemp44) + ((((0.049802605100000001 * fTemp37) + (0.013955334600000001 * fTemp43)) + (0.0033124104000000001 * fTemp39)) + (0.029655717500000001 * fTemp41))) + (0.061018189399999999 * fTemp47))));
			double fTemp325 = (fConst61 * fRec661[1]);
			double fTemp326 = (fConst62 * fRec664[1]);
			fRec666[0] = (fTemp324 + (fTemp325 + (fRec666[1] + fTemp326)));
			fRec664[0] = fRec666[0];
			double fRec665 = ((fTemp326 + fTemp325) + fTemp324);
			fRec663[0] = (fRec664[0] + fRec663[1]);
			fRec661[0] = fRec663[0];
			double fRec662 = fRec665;
			fRec660[0] = (fTemp322 + (fTemp323 + (fRec662 + fRec660[1])));
			fRec658[0] = fRec660[0];
			double fRec659 = (fTemp322 + (fRec662 + fTemp323));
			fRec657[0] = (fRec658[0] + fRec657[1]);
			fRec655[0] = fRec657[0];
			double fRec656 = fRec659;
			fRec654[0] = (fTemp321 + (fRec656 + fRec654[1]));
			fRec652[0] = fRec654[0];
			double fRec653 = (fRec656 + fTemp321);
			double fTemp327 = (fConst64 * fRec667[1]);
			double fTemp328 = (fConst65 * fRec670[1]);
			double fTemp329 = (fConst67 * ((((0.042588462399999999 * fTemp58) + (((0.039751654499999997 * fTemp53) + (0.0063091683000000001 * fTemp57)) + (0.026752755400000001 * fTemp55))) + (0.065025200699999994 * fTemp61)) - ((0.0365129098 * fTemp60) + (((0.0176913956 * fTemp54) + (0.0110519412 * fTemp56)) + (0.0426323537 * fTemp59)))));
			double fTemp330 = (fConst68 * fRec673[1]);
			double fTemp331 = (fConst69 * fRec676[1]);
			fRec678[0] = (fTemp329 + (fTemp330 + (fRec678[1] + fTemp331)));
			fRec676[0] = fRec678[0];
			double fRec677 = ((fTemp331 + fTemp330) + fTemp329);
			fRec675[0] = (fRec676[0] + fRec675[1]);
			fRec673[0] = fRec675[0];
			double fRec674 = fRec677;
			fRec672[0] = (fTemp327 + (fTemp328 + (fRec674 + fRec672[1])));
			fRec670[0] = fRec672[0];
			double fRec671 = (fTemp327 + (fRec674 + fTemp328));
			fRec669[0] = (fRec670[0] + fRec669[1]);
			fRec667[0] = fRec669[0];
			double fRec668 = fRec671;
			double fTemp332 = (fConst71 * fRec679[1]);
			double fTemp333 = (fConst73 * (((0.0307363241 * fTemp68) + (((0.0095601817999999995 * fTemp67) + (0.0059447804000000003 * fTemp69)) + (0.0450445976 * fTemp71))) - (((0.027921281199999998 * fTemp66) + (0.0241286036 * fTemp70)) + (0.063797515599999993 * fTemp72))));
			double fTemp334 = (fConst74 * fRec682[1]);
			double fTemp335 = (fConst75 * fRec685[1]);
			fRec687[0] = (fTemp333 + (fTemp334 + (fRec687[1] + fTemp335)));
			fRec685[0] = fRec687[0];
			double fRec686 = ((fTemp335 + fTemp334) + fTemp333);
			fRec684[0] = (fRec685[0] + fRec684[1]);
			fRec682[0] = fRec684[0];
			double fRec683 = fRec686;
			fRec681[0] = (fTemp332 + (fRec683 + fRec681[1]));
			fRec679[0] = fRec681[0];
			double fRec680 = (fRec683 + fTemp332);
			double fTemp336 = (fConst77 * ((0.0081684841999999994 * fTemp77) - ((0.0059353063999999997 * fTemp76) + (0.042609599499999998 * fTemp78))));
			double fTemp337 = (fConst78 * fRec688[1]);
			fRec690[0] = (fTemp336 + (fRec690[1] + fTemp337));
			fRec688[0] = fRec690[0];
			double fRec689 = (fTemp337 + fTemp336);
			double fTemp338 = (fConst80 * (((0.015992447399999998 * fTemp81) + (0.056499036900000001 * fTemp84)) - (((0.0033505019 * fTemp82) + (0.031212528199999999 * fTemp85)) + (0.021970014199999999 * fTemp83))));
			double fTemp339 = (fConst81 * fRec691[1]);
			double fTemp340 = (fConst82 * fRec694[1]);
			fRec696[0] = (fTemp338 + (fTemp339 + (fRec696[1] + fTemp340)));
			fRec694[0] = fRec696[0];
			double fRec695 = ((fTemp340 + fTemp339) + fTemp338);
			fRec693[0] = (fRec694[0] + fRec693[1]);
			fRec691[0] = fRec693[0];
			double fRec692 = fRec695;
			fVec9[(IOTA & 127)] = (((0.031852775999999999 * fTemp96) + ((0.024951468800000001 * fTemp7) + ((0.046909785599999997 * fTemp10) + ((0.0080289203000000007 * fTemp11) + ((4.34846e-05 * fTemp12) + ((0.0129668839 * fTemp89) + ((0.0145228579 * fTemp92) + (((0.014890234299999999 * fTemp13) + (fRec635 + (fRec653 + (fRec668 + (fRec680 + (fRec689 + fRec692)))))) + (0.040360640500000003 * fTemp91))))))))) - (((0.0427703444 * fTemp8) + (((((0.0600151607 * fTemp90) + (0.026956826499999999 * fTemp93)) + (0.0025683628000000001 * fTemp94)) + (0.0338966952 * fTemp95)) + (0.013764184699999999 * fTemp9))) + (0.042369818400000002 * fTemp97)));
			output9[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec9[((IOTA - iConst83) & 127)])));
			double fTemp341 = (fConst45 * fRec697[1]);
			double fTemp342 = (fConst46 * fRec700[1]);
			double fTemp343 = (fConst48 * fRec703[1]);
			double fTemp344 = (fConst49 * fRec706[1]);
			double fTemp345 = (fConst51 * (((((0.0052146281999999999 * fTemp20) + (((0.063459887399999998 * fTemp18) + (0.022218869499999998 * fTemp26)) + (0.0145262625 * fTemp19))) + (0.048115148500000003 * fTemp23)) + (0.0063237112999999998 * fTemp30)) - ((0.029691722699999999 * fTemp29) + (((0.0038109947000000001 * fTemp22) + ((((0.085293902500000005 * fTemp25) + (0.042797914800000003 * fTemp27)) + (0.0038911843999999999 * fTemp28)) + (0.056143524700000003 * fTemp21))) + (0.0042472606000000003 * fTemp24)))));
			double fTemp346 = (fConst52 * fRec709[1]);
			double fTemp347 = (fConst53 * fRec712[1]);
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
			double fTemp348 = (fConst55 * fRec715[1]);
			double fTemp349 = (fConst57 * fRec718[1]);
			double fTemp350 = (fConst58 * fRec721[1]);
			double fTemp351 = (fConst60 * (((0.043693265199999998 * fTemp46) + (((0.046285479599999999 * fTemp40) + (((0.085947763799999993 * fTemp37) + (0.0307415446 * fTemp43)) + (0.0050440883999999997 * fTemp39))) + (0.018162974500000002 * fTemp45))) - (((0.060457105599999998 * fTemp44) + (((0.054861647399999998 * fTemp38) + (0.0242158328 * fTemp42)) + (0.0104845211 * fTemp41))) + (0.0298178217 * fTemp47))));
			double fTemp352 = (fConst61 * fRec724[1]);
			double fTemp353 = (fConst62 * fRec727[1]);
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
			double fTemp354 = (fConst64 * fRec730[1]);
			double fTemp355 = (fConst65 * fRec733[1]);
			double fTemp356 = (fConst67 * ((((0.063884093200000006 * fTemp58) + (((0.040177372000000003 * fTemp54) + (0.021033395100000001 * fTemp56)) + (0.019905962900000001 * fTemp55))) + (0.0510720759 * fTemp61)) - ((0.050950990000000002 * fTemp60) + (((0.076397032700000006 * fTemp53) + (0.0148908033 * fTemp57)) + (0.033221765299999997 * fTemp59)))));
			double fTemp357 = (fConst68 * fRec736[1]);
			double fTemp358 = (fConst69 * fRec739[1]);
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
			double fTemp359 = (fConst71 * fRec742[1]);
			double fTemp360 = (fConst73 * (((0.049120922300000001 * fTemp68) + ((0.058211639599999997 * fTemp66) + (0.045905278600000002 * fTemp71))) - ((((0.023203534599999999 * fTemp67) + (0.012376945699999999 * fTemp69)) + (0.0398291375 * fTemp70)) + (0.064992922999999994 * fTemp72))));
			double fTemp361 = (fConst74 * fRec745[1]);
			double fTemp362 = (fConst75 * fRec748[1]);
			fRec750[0] = (fTemp360 + (fTemp361 + (fRec750[1] + fTemp362)));
			fRec748[0] = fRec750[0];
			double fRec749 = ((fTemp362 + fTemp361) + fTemp360);
			fRec747[0] = (fRec748[0] + fRec747[1]);
			fRec745[0] = fRec747[0];
			double fRec746 = fRec749;
			fRec744[0] = (fTemp359 + (fRec746 + fRec744[1]));
			fRec742[0] = fRec744[0];
			double fRec743 = (fRec746 + fTemp359);
			double fTemp363 = (fConst77 * (((0.0136255609 * fTemp76) + (0.014898194599999999 * fTemp77)) - (0.0557105013 * fTemp78)));
			double fTemp364 = (fConst78 * fRec751[1]);
			fRec753[0] = (fTemp363 + (fRec753[1] + fTemp364));
			fRec751[0] = fRec753[0];
			double fRec752 = (fTemp364 + fTemp363);
			double fTemp365 = (fConst80 * (((0.0085057102000000006 * fTemp82) + (0.067367399300000005 * fTemp84)) - (((0.035352712600000002 * fTemp81) + (0.037343438999999999 * fTemp85)) + (0.038255028099999998 * fTemp83))));
			double fTemp366 = (fConst81 * fRec754[1]);
			double fTemp367 = (fConst82 * fRec757[1]);
			fRec759[0] = (fTemp365 + (fTemp366 + (fRec759[1] + fTemp367)));
			fRec757[0] = fRec759[0];
			double fRec758 = ((fTemp367 + fTemp366) + fTemp365);
			fRec756[0] = (fRec757[0] + fRec756[1]);
			fRec754[0] = fRec756[0];
			double fRec755 = fRec758;
			fVec10[(IOTA & 127)] = (((0.0145601463 * fTemp97) + ((0.0128190878 * fTemp96) + ((0.0124172877 * fTemp9) + ((0.040044168499999998 * fTemp10) + ((0.0019342133000000001 * fTemp12) + ((0.0481385613 * fTemp93) + ((0.075282926700000002 * fTemp90) + ((0.020309576900000001 * fTemp13) + (fRec698 + (fRec716 + (fRec731 + (fRec743 + (fRec752 + fRec755))))))))))))) - ((0.0061249056999999997 * fTemp7) + (((0.017900609200000001 * fTemp11) + (((((0.0639685792 * fTemp91) + (0.0168350627 * fTemp92)) + (0.00086240990000000005 * fTemp94)) + (0.024161711499999999 * fTemp89)) + (0.030176356099999999 * fTemp95))) + (0.030781766700000001 * fTemp8))));
			output10[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec10[((IOTA - iConst83) & 127)])));
			double fTemp368 = (fConst85 * fRec760[1]);
			double fTemp369 = (fConst86 * fRec763[1]);
			double fTemp370 = (fConst88 * fRec766[1]);
			double fTemp371 = (fConst89 * fRec769[1]);
			double fTemp372 = (fConst91 * (((0.050429937699999997 * fTemp29) + (((((0.053052990600000002 * fTemp25) + (0.015535908100000001 * fTemp26)) + (0.030474236799999999 * fTemp19)) + (0.0040485772000000003 * fTemp22)) + (0.031447456499999998 * fTemp24))) - ((((0.040412862299999998 * fTemp21) + ((((0.0017346612 * fTemp18) + (0.048084817000000002 * fTemp27)) + (0.021296823999999999 * fTemp28)) + (0.012722222199999999 * fTemp20))) + (0.017923382700000001 * fTemp23)) + (0.056789569999999998 * fTemp30))));
			double fTemp373 = (fConst92 * fRec772[1]);
			double fTemp374 = (fConst93 * fRec775[1]);
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
			double fTemp375 = (fConst95 * fRec778[1]);
			double fTemp376 = (fConst97 * fRec781[1]);
			double fTemp377 = (fConst98 * fRec784[1]);
			double fTemp378 = (fConst100 * ((((0.034617807899999999 * fTemp40) + ((0.046833406500000001 * fTemp43) + (0.018666815 * fTemp39))) + (0.078450290800000003 * fTemp47)) - ((0.038624600000000002 * fTemp46) + ((0.0165080438 * fTemp45) + ((0.0139758225 * fTemp44) + ((((0.0079773524999999998 * fTemp37) + (0.026470719100000002 * fTemp38)) + (0.036892242300000003 * fTemp42)) + (0.0233742116 * fTemp41)))))));
			double fTemp379 = (fConst101 * fRec787[1]);
			double fTemp380 = (fConst102 * fRec790[1]);
			fRec792[0] = (fTemp378 + (fTemp379 + (fRec792[1] + fTemp380)));
			fRec790[0] = fRec792[0];
			double fRec791 = ((fTemp380 + fTemp379) + fTemp378);
			fRec789[0] = (fRec790[0] + fRec789[1]);
			fRec787[0] = fRec789[0];
			double fRec788 = fRec791;
			fRec786[0] = (fTemp376 + (fTemp377 + (fRec788 + fRec786[1])));
			fRec784[0] = fRec786[0];
			double fRec785 = (fTemp376 + (fRec788 + fTemp377));
			fRec783[0] = (fRec784[0] + fRec783[1]);
			fRec781[0] = fRec783[0];
			double fRec782 = fRec785;
			fRec780[0] = (fTemp375 + (fRec782 + fRec780[1]));
			fRec778[0] = fRec780[0];
			double fRec779 = (fRec782 + fTemp375);
			double fTemp381 = (fConst104 * fRec793[1]);
			double fTemp382 = (fConst105 * fRec796[1]);
			double fTemp383 = (fConst107 * ((((0.034635150099999998 * fTemp58) + (((0.038386408400000002 * fTemp54) + (0.042730249099999999 * fTemp56)) + (0.026820651899999999 * fTemp55))) + (0.013328174700000001 * fTemp60)) - ((((0.039803916000000002 * fTemp53) + (0.025697066599999999 * fTemp57)) + (0.0110821249 * fTemp59)) + (0.065147456399999998 * fTemp61))));
			double fTemp384 = (fConst108 * fRec799[1]);
			double fTemp385 = (fConst109 * fRec802[1]);
			fRec804[0] = (fTemp383 + (fTemp384 + (fRec804[1] + fTemp385)));
			fRec802[0] = fRec804[0];
			double fRec803 = ((fTemp385 + fTemp384) + fTemp383);
			fRec801[0] = (fRec802[0] + fRec801[1]);
			fRec799[0] = fRec801[0];
			double fRec800 = fRec803;
			fRec798[0] = (fTemp381 + (fTemp382 + (fRec800 + fRec798[1])));
			fRec796[0] = fRec798[0];
			double fRec797 = (fTemp381 + (fRec800 + fTemp382));
			fRec795[0] = (fRec796[0] + fRec795[1]);
			fRec793[0] = fRec795[0];
			double fRec794 = fRec797;
			double fTemp386 = (fConst111 * fRec805[1]);
			double fTemp387 = (fConst113 * (((0.0254303502 * fTemp72) + ((0.0095778079000000006 * fTemp68) + ((0.064990564599999995 * fTemp66) + (0.0361467855 * fTemp71)))) - (((0.030790567000000001 * fTemp67) + (0.0277165373 * fTemp69)) + (0.0241737707 * fTemp70))));
			double fTemp388 = (fConst114 * fRec808[1]);
			double fTemp389 = (fConst115 * fRec811[1]);
			fRec813[0] = (fTemp387 + (fTemp388 + (fRec813[1] + fTemp389)));
			fRec811[0] = fRec813[0];
			double fRec812 = ((fTemp389 + fTemp388) + fTemp387);
			fRec810[0] = (fRec811[0] + fRec810[1]);
			fRec808[0] = fRec810[0];
			double fRec809 = fRec812;
			fRec807[0] = (fTemp386 + (fRec809 + fRec807[1]));
			fRec805[0] = fRec807[0];
			double fRec806 = (fRec809 + fTemp386);
			double fTemp390 = (fConst117 * (((0.0260005299 * fTemp76) + (0.0081851137999999993 * fTemp77)) - (0.0344149469 * fTemp78)));
			double fTemp391 = (fConst118 * fRec814[1]);
			fRec816[0] = (fTemp390 + (fRec816[1] + fTemp391));
			fRec814[0] = fRec816[0];
			double fRec815 = (fTemp391 + fTemp390);
			double fTemp392 = (fConst120 * (((0.013191336099999999 * fTemp82) + (0.0160282884 * fTemp84)) - (((0.056636752499999998 * fTemp81) + (0.031294055600000002 * fTemp85)) + (0.017939345499999999 * fTemp83))));
			double fTemp393 = (fConst121 * fRec817[1]);
			double fTemp394 = (fConst122 * fRec820[1]);
			fRec822[0] = (fTemp392 + (fTemp393 + (fRec822[1] + fTemp394)));
			fRec820[0] = fRec822[0];
			double fRec821 = ((fTemp394 + fTemp393) + fTemp392);
			fRec819[0] = (fRec820[0] + fRec819[1]);
			fRec817[0] = fRec819[0];
			double fRec818 = fRec821;
			fVec11[(IOTA & 127)] = (((0.0123711476 * fTemp97) + ((0.042801908800000003 * fTemp8) + ((0.0078914381000000002 * fTemp9) + ((0.012982114899999999 * fTemp10) + ((0.0057375172000000002 * fTemp11) + ((0.011586837500000001 * fTemp94) + ((0.026972684300000001 * fTemp93) + ((0.0073695499000000003 * fTemp92) + (((0.014929747599999999 * fTemp13) + (fRec761 + (fRec779 + (fRec794 + (fRec806 + (fRec815 + fRec818)))))) + (0.0318610509 * fTemp91)))))))))) - ((0.040363779199999998 * fTemp96) + (((0.033932445300000003 * fTemp95) + ((0.0056461300000000001 * fTemp12) + ((0.072380907600000002 * fTemp90) + (0.046954442399999997 * fTemp89)))) + (0.0279355157 * fTemp7))));
			output11[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec11[((IOTA - iConst123) & 127)])));
			double fTemp395 = (fConst5 * fRec823[1]);
			double fTemp396 = (fConst6 * fRec826[1]);
			double fTemp397 = (fConst8 * fRec829[1]);
			double fTemp398 = (fConst9 * fRec832[1]);
			double fTemp399 = (fConst11 * (((((0.0053534992999999999 * fTemp20) + ((0.049856821199999998 * fTemp19) + ((0.0062273232 * fTemp25) + (0.0039888305999999998 * fTemp28)))) + (0.0041368571000000003 * fTemp24)) + (0.085255123799999999 * fTemp30)) - (((0.064232265799999994 * fTemp23) + ((0.0038279616000000002 * fTemp22) + ((((0.065858074000000003 * fTemp18) + (0.0221532651 * fTemp26)) + (0.0037344174 * fTemp27)) + (0.029345212200000002 * fTemp21)))) + (0.023889762599999999 * fTemp29))));
			double fTemp400 = (fConst12 * fRec835[1]);
			double fTemp401 = (fConst13 * fRec838[1]);
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
			double fTemp402 = (fConst15 * fRec841[1]);
			double fTemp403 = (fConst17 * fRec844[1]);
			double fTemp404 = (fConst18 * fRec847[1]);
			double fTemp405 = (fConst20 * ((((0.046235044099999997 * fTemp40) + ((((0.054866021700000003 * fTemp38) + (0.0043336894999999997 * fTemp42)) + (0.060424909399999997 * fTemp43)) + (0.0108093331 * fTemp39))) + (0.030729541499999999 * fTemp44)) - ((0.039708803500000001 * fTemp47) + ((0.043707611200000003 * fTemp46) + (((0.081764830600000005 * fTemp37) + (0.0037244634 * fTemp41)) + (0.029814907500000001 * fTemp45))))));
			double fTemp406 = (fConst21 * fRec850[1]);
			double fTemp407 = (fConst22 * fRec853[1]);
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
			double fTemp408 = (fConst24 * fRec856[1]);
			double fTemp409 = (fConst25 * fRec859[1]);
			double fTemp410 = (fConst27 * (((0.064468053499999997 * fTemp60) + ((0.020981976900000001 * fTemp59) + ((0.0346489985 * fTemp58) + ((((0.076339643299999996 * fTemp53) + (0.0076396624000000003 * fTemp54)) + (0.0330664798 * fTemp56)) + (0.019769641599999999 * fTemp55))))) - ((0.055704387799999998 * fTemp57) + (0.050999174600000002 * fTemp61))));
			double fTemp411 = (fConst28 * fRec862[1]);
			double fTemp412 = (fConst29 * fRec865[1]);
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
			double fTemp413 = (fConst31 * fRec868[1]);
			double fTemp414 = (fConst33 * ((((0.0047816266 * fTemp66) + (0.023629899100000001 * fTemp71)) + (0.087036247499999997 * fTemp72)) - ((((0.049170050799999997 * fTemp67) + (0.041100110400000001 * fTemp69)) + (0.039856738199999998 * fTemp70)) + (0.023209618200000001 * fTemp68))));
			double fTemp415 = (fConst34 * fRec871[1]);
			double fTemp416 = (fConst35 * fRec874[1]);
			fRec876[0] = (fTemp414 + (fTemp415 + (fRec876[1] + fTemp416)));
			fRec874[0] = fRec876[0];
			double fRec875 = ((fTemp416 + fTemp415) + fTemp414);
			fRec873[0] = (fRec874[0] + fRec873[1]);
			fRec871[0] = fRec873[0];
			double fRec872 = fRec875;
			fRec870[0] = (fTemp413 + (fRec872 + fRec870[1]));
			fRec868[0] = fRec870[0];
			double fRec869 = (fRec872 + fTemp413);
			double fTemp417 = (fConst37 * (((0.048992347899999997 * fTemp76) + (0.014920154 * fTemp77)) - (0.0297393029 * fTemp78)));
			double fTemp418 = (fConst38 * fRec877[1]);
			fRec879[0] = (fTemp417 + (fRec879[1] + fTemp418));
			fRec877[0] = fRec879[0];
			double fRec878 = (fTemp418 + fTemp417);
			double fTemp419 = (fConst40 * ((0.033100803800000002 * fTemp82) - ((((0.0673100326 * fTemp81) + (0.037280832700000002 * fTemp85)) + (0.0210673405 * fTemp83)) + (0.035321888099999997 * fTemp84))));
			double fTemp420 = (fConst41 * fRec880[1]);
			double fTemp421 = (fConst42 * fRec883[1]);
			fRec885[0] = (fTemp419 + (fTemp420 + (fRec885[1] + fTemp421)));
			fRec883[0] = fRec885[0];
			double fRec884 = ((fTemp421 + fTemp420) + fTemp419);
			fRec882[0] = (fRec883[0] + fRec882[1]);
			fRec880[0] = fRec882[0];
			double fRec881 = fRec884;
			fVec12[(IOTA & 127)] = (((0.063966189699999995 * fTemp96) + ((0.016254710499999998 * fTemp7) + ((0.030723080400000002 * fTemp8) + ((0.014139159300000001 * fTemp12) + ((0.0074993483 * fTemp92) + ((0.0127676734 * fTemp91) + ((0.063601609099999998 * fTemp90) + ((0.0202986639 * fTemp13) + (fRec824 + (fRec842 + (fRec857 + (fRec869 + (fRec878 + fRec881))))))))))))) - (((0.0095308728999999991 * fTemp9) + ((0.024108229700000001 * fTemp10) + ((0.011364239 * fTemp11) + ((((0.048127627100000001 * fTemp93) + (0.0082020879000000001 * fTemp94)) + (0.039877715699999997 * fTemp89)) + (0.0300172267 * fTemp95))))) + (0.042830610200000001 * fTemp97)));
			output12[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec12[((IOTA - iConst43) & 127)])));
			double fTemp422 = (fConst45 * fRec886[1]);
			double fTemp423 = (fConst46 * fRec889[1]);
			double fTemp424 = (fConst48 * fRec892[1]);
			double fTemp425 = (fConst49 * fRec895[1]);
			double fTemp426 = (fConst51 * ((((0.0368229947 * fTemp18) + (0.046657721800000003 * fTemp27)) + (0.050142181600000002 * fTemp19)) - ((0.052923766599999998 * fTemp30) + ((0.0343265798 * fTemp29) + ((0.0314855458 * fTemp24) + ((0.021300577000000001 * fTemp23) + ((0.0213931698 * fTemp22) + ((0.0070241647000000001 * fTemp21) + ((((0.056772643099999999 * fTemp25) + (0.0156066399 * fTemp26)) + (0.0040859789000000004 * fTemp28)) + (0.0127994819 * fTemp20))))))))));
			double fTemp427 = (fConst52 * fRec898[1]);
			double fTemp428 = (fConst53 * fRec901[1]);
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
			double fTemp429 = (fConst55 * fRec904[1]);
			double fTemp430 = (fConst57 * fRec907[1]);
			double fTemp431 = (fConst58 * fRec910[1]);
			double fTemp432 = (fConst60 * (((((((((0.060982469800000001 * fTemp37) + (0.026372141599999999 * fTemp38)) + (0.037784041300000001 * fTemp42)) + (0.0139428833 * fTemp43)) + (0.029800197399999999 * fTemp39)) + (0.034585324399999999 * fTemp40)) + (0.046772838900000002 * fTemp44)) + (0.038534860599999998 * fTemp46)) - (((0.0033443446000000002 * fTemp41) + (0.014450966399999999 * fTemp45)) + (0.049787216699999998 * fTemp47))));
			double fTemp433 = (fConst61 * fRec913[1]);
			double fTemp434 = (fConst62 * fRec916[1]);
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
			double fTemp435 = (fConst64 * fRec919[1]);
			double fTemp436 = (fConst65 * fRec922[1]);
			double fTemp437 = (fConst67 * (((0.065008824800000004 * fTemp61) + ((0.017642417000000001 * fTemp60) + ((0.042724883399999997 * fTemp59) + ((0.0062987227999999999 * fTemp58) + (((0.0397471904 * fTemp53) + (0.011092876999999999 * fTemp56)) + (0.026837870699999999 * fTemp55)))))) - ((0.036461632500000001 * fTemp54) + (0.042567339799999999 * fTemp57))));
			double fTemp438 = (fConst68 * fRec925[1]);
			double fTemp439 = (fConst69 * fRec928[1]);
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
			double fTemp440 = (fConst71 * fRec931[1]);
			double fTemp441 = (fConst73 * (((0.0059588126000000002 * fTemp71) + (0.0279206535 * fTemp72)) - (((((0.063793979099999995 * fTemp66) + (0.0095313327000000007 * fTemp67)) + (0.045114823999999998 * fTemp69)) + (0.024099450599999999 * fTemp70)) + (0.0306850291 * fTemp68))));
			double fTemp442 = (fConst74 * fRec934[1]);
			double fTemp443 = (fConst75 * fRec937[1]);
			fRec939[0] = (fTemp441 + (fTemp442 + (fRec939[1] + fTemp443)));
			fRec937[0] = fRec939[0];
			double fRec938 = ((fTemp443 + fTemp442) + fTemp441);
			fRec936[0] = (fRec937[0] + fRec936[1]);
			fRec934[0] = fRec936[0];
			double fRec935 = fRec938;
			fRec933[0] = (fTemp440 + (fRec935 + fRec933[1]));
			fRec931[0] = fRec933[0];
			double fRec932 = (fRec935 + fTemp440);
			double fTemp444 = (fConst77 * (((0.042609770999999998 * fTemp76) + (0.0081499260999999996 * fTemp77)) - (0.0059345589999999998 * fTemp78)));
			double fTemp445 = (fConst78 * fRec940[1]);
			fRec942[0] = (fTemp444 + (fRec942[1] + fTemp445));
			fRec940[0] = fRec942[0];
			double fRec941 = (fTemp445 + fTemp444);
			double fTemp446 = (fConst80 * ((0.021926979799999999 * fTemp82) - ((((0.0159919728 * fTemp81) + (0.031238016100000002 * fTemp85)) + (0.0033394117999999999 * fTemp83)) + (0.056500430800000001 * fTemp84))));
			double fTemp447 = (fConst81 * fRec943[1]);
			double fTemp448 = (fConst82 * fRec946[1]);
			fRec948[0] = (fTemp446 + (fTemp447 + (fRec948[1] + fTemp448)));
			fRec946[0] = fRec948[0];
			double fRec947 = ((fTemp448 + fTemp447) + fTemp446);
			fRec945[0] = (fRec946[0] + fRec945[1]);
			fRec943[0] = fRec945[0];
			double fRec944 = fRec947;
			fVec13[(IOTA & 127)] = (((0.059950823899999998 * fTemp97) + ((0.014645373600000001 * fTemp7) + ((0.0026659915000000001 * fTemp9) + (((0.014888663200000001 * fTemp13) + (fRec887 + (fRec905 + (fRec920 + (fRec932 + (fRec941 + fRec944)))))) + (7.8700200000000002e-05 * fTemp11))))) - ((0.031826719599999997 * fTemp96) + ((((0.033999951100000002 * fTemp95) + ((0.0081591667999999992 * fTemp12) + ((((((0.042293773999999999 * fTemp90) + (0.040267153999999999 * fTemp91)) + (0.024997331099999999 * fTemp92)) + (0.026970649400000001 * fTemp93)) + (0.0138692634 * fTemp94)) + (0.0129948206 * fTemp89)))) + (0.047031282200000003 * fTemp10)) + (0.042824696099999997 * fTemp8))));
			output13[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec13[((IOTA - iConst83) & 127)])));
			double fTemp449 = (fConst45 * fRec949[1]);
			double fTemp450 = (fConst46 * fRec952[1]);
			double fTemp451 = (fConst48 * fRec955[1]);
			double fTemp452 = (fConst49 * fRec958[1]);
			double fTemp453 = (fConst51 * ((((((((((((0.085266326700000006 * fTemp25) + (0.029778792700000001 * fTemp18)) + (0.022203483499999999 * fTemp26)) + (0.048149110699999997 * fTemp27)) + (0.0038646843999999999 * fTemp28)) + (0.056085540400000002 * fTemp19)) + (0.0052844366999999998 * fTemp20)) + (0.0144970842 * fTemp21)) + (0.0038927626999999999 * fTemp22)) + (0.042749258800000002 * fTemp23)) + (0.063416383600000001 * fTemp29)) - ((0.0042356735999999999 * fTemp24) + (0.0063843253000000003 * fTemp30))));
			double fTemp454 = (fConst52 * fRec961[1]);
			double fTemp455 = (fConst53 * fRec964[1]);
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
			double fTemp456 = (fConst55 * fRec967[1]);
			double fTemp457 = (fConst57 * fRec970[1]);
			double fTemp458 = (fConst58 * fRec973[1]);
			double fTemp459 = (fConst60 * (((0.085893332599999997 * fTemp47) + ((0.043782375599999999 * fTemp46) + ((0.024174841400000001 * fTemp45) + ((0.060484872500000002 * fTemp44) + ((0.0050236100000000004 * fTemp41) + ((0.046273199700000003 * fTemp40) + (((0.0298884063 * fTemp37) + (0.0181184073 * fTemp42)) + (0.0103732596 * fTemp39)))))))) - ((0.0548174466 * fTemp38) + (0.030702162500000001 * fTemp43))));
			double fTemp460 = (fConst61 * fRec976[1]);
			double fTemp461 = (fConst62 * fRec979[1]);
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
			double fTemp462 = (fConst64 * fRec982[1]);
			double fTemp463 = (fConst65 * fRec985[1]);
			double fTemp464 = (fConst67 * ((((0.0198317639 * fTemp55) + (0.033158545800000001 * fTemp59)) + (0.051132112399999999 * fTemp61)) - ((((((0.076327265599999999 * fTemp53) + (0.0510348204 * fTemp54)) + (0.020991891499999998 * fTemp56)) + (0.063924795199999995 * fTemp57)) + (0.014872882800000001 * fTemp58)) + (0.040142903399999999 * fTemp60))));
			double fTemp465 = (fConst68 * fRec988[1]);
			double fTemp466 = (fConst69 * fRec991[1]);
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
			double fTemp467 = (fConst71 * fRec994[1]);
			double fTemp468 = (fConst73 * ((0.023183874600000001 * fTemp67) - ((0.058145986699999999 * fTemp72) + (((((0.065032867199999997 * fTemp66) + (0.045848492599999999 * fTemp69)) + (0.039870407599999998 * fTemp70)) + (0.0123535537 * fTemp71)) + (0.049194931800000001 * fTemp68)))));
			double fTemp469 = (fConst74 * fRec997[1]);
			double fTemp470 = (fConst75 * fRec1000[1]);
			fRec1002[0] = (fTemp468 + (fTemp469 + (fRec1002[1] + fTemp470)));
			fRec1000[0] = fRec1002[0];
			double fRec1001 = ((fTemp470 + fTemp469) + fTemp468);
			fRec999[0] = (fRec1000[0] + fRec999[1]);
			fRec997[0] = fRec999[0];
			double fRec998 = fRec1001;
			fRec996[0] = (fTemp467 + (fRec998 + fRec996[1]));
			fRec994[0] = fRec996[0];
			double fRec995 = (fRec998 + fTemp467);
			double fTemp471 = (fConst77 * (((0.055723472599999997 * fTemp76) + (0.014923150899999999 * fTemp77)) + (0.0136076102 * fTemp78)));
			double fTemp472 = (fConst78 * fRec1003[1]);
			fRec1005[0] = (fTemp471 + (fRec1005[1] + fTemp472));
			fRec1003[0] = fRec1005[0];
			double fRec1004 = (fTemp472 + fTemp471);
			double fTemp473 = (fConst80 * ((((0.0353080598 * fTemp81) + (0.038313705500000003 * fTemp82)) + (0.0084990055999999998 * fTemp83)) - ((0.037324424100000003 * fTemp85) + (0.067389637200000005 * fTemp84))));
			double fTemp474 = (fConst81 * fRec1006[1]);
			double fTemp475 = (fConst82 * fRec1009[1]);
			fRec1011[0] = (fTemp473 + (fTemp474 + (fRec1011[1] + fTemp475)));
			fRec1009[0] = fRec1011[0];
			double fRec1010 = ((fTemp475 + fTemp474) + fTemp473);
			fRec1008[0] = (fRec1009[0] + fRec1008[1]);
			fRec1006[0] = fRec1008[0];
			double fRec1007 = fRec1010;
			fVec14[(IOTA & 127)] = (((0.00087785390000000004 * fTemp9) + ((0.0019421338 * fTemp11) + ((0.017946095799999999 * fTemp12) + ((0.024109985099999998 * fTemp89) + ((0.0124551531 * fTemp94) + ((0.048107820799999999 * fTemp93) + ((0.0061051246999999998 * fTemp92) + ((0.063936194799999999 * fTemp91) + ((0.0145333501 * fTemp90) + ((0.020315367599999998 * fTemp13) + (fRec950 + (fRec968 + (fRec983 + (fRec995 + (fRec1004 + fRec1007))))))))))))))) - ((0.075278349899999999 * fTemp97) + ((0.0128918152 * fTemp96) + ((0.0168659112 * fTemp7) + (((0.030096586099999999 * fTemp95) + (0.039987273099999998 * fTemp10)) + (0.0308404135 * fTemp8))))));
			output14[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec14[((IOTA - iConst83) & 127)])));
			double fTemp476 = (fConst85 * fRec1012[1]);
			double fTemp477 = (fConst86 * fRec1015[1]);
			double fTemp478 = (fConst88 * fRec1018[1]);
			double fTemp479 = (fConst89 * fRec1021[1]);
			double fTemp480 = (fConst91 * ((((0.031462172699999999 * fTemp24) + ((((0.040437487699999997 * fTemp19) + ((0.0155320761 * fTemp26) + (0.0213193536 * fTemp28))) + (0.030496424599999999 * fTemp21)) + (0.048100045000000001 * fTemp23))) + (0.056724715000000002 * fTemp30)) - ((((((0.053043311500000002 * fTemp25) + (0.0504092451 * fTemp18)) + (0.017942631800000001 * fTemp27)) + (0.0127375418 * fTemp20)) + (0.0040392639000000003 * fTemp22)) + (0.0017815708 * fTemp29))));
			double fTemp481 = (fConst92 * fRec1024[1]);
			double fTemp482 = (fConst93 * fRec1027[1]);
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
			double fTemp483 = (fConst95 * fRec1030[1]);
			double fTemp484 = (fConst97 * fRec1033[1]);
			double fTemp485 = (fConst98 * fRec1036[1]);
			double fTemp486 = (fConst100 * (((0.036883176500000003 * fTemp45) + ((0.013963348699999999 * fTemp44) + ((0.018676555899999999 * fTemp41) + ((0.0233780416 * fTemp39) + (0.034613068499999997 * fTemp40))))) - ((0.0080050056999999997 * fTemp47) + (((((0.078366721 * fTemp37) + (0.0264212027 * fTemp38)) + (0.016515296299999999 * fTemp42)) + (0.046822781700000003 * fTemp43)) + (0.038609438699999998 * fTemp46)))));
			double fTemp487 = (fConst101 * fRec1039[1]);
			double fTemp488 = (fConst102 * fRec1042[1]);
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
			double fTemp489 = (fConst104 * fRec1045[1]);
			double fTemp490 = (fConst105 * fRec1048[1]);
			double fTemp491 = (fConst107 * ((((0.0133293988 * fTemp54) + (0.026810290699999999 * fTemp55)) + (0.011067599500000001 * fTemp59)) - ((0.065078030499999995 * fTemp61) + (((((0.039726134500000003 * fTemp53) + (0.0427061522 * fTemp56)) + (0.034600779800000002 * fTemp57)) + (0.025677240600000002 * fTemp58)) + (0.038329681499999997 * fTemp60)))));
			double fTemp492 = (fConst108 * fRec1051[1]);
			double fTemp493 = (fConst109 * fRec1054[1]);
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
			double fTemp494 = (fConst111 * fRec1057[1]);
			double fTemp495 = (fConst113 * (((0.025411027700000002 * fTemp66) + (0.030741221400000001 * fTemp67)) - ((0.0648815482 * fTemp72) + ((((0.036105198599999999 * fTemp69) + (0.024137626499999999 * fTemp70)) + (0.027690037800000001 * fTemp71)) + (0.0095517760999999993 * fTemp68)))));
			double fTemp496 = (fConst114 * fRec1060[1]);
			double fTemp497 = (fConst115 * fRec1063[1]);
			fRec1065[0] = (fTemp495 + (fTemp496 + (fRec1065[1] + fTemp497)));
			fRec1063[0] = fRec1065[0];
			double fRec1064 = ((fTemp497 + fTemp496) + fTemp495);
			fRec1062[0] = (fRec1063[0] + fRec1062[1]);
			fRec1060[0] = fRec1062[0];
			double fRec1061 = fRec1064;
			fRec1059[0] = (fTemp494 + (fRec1061 + fRec1059[1]));
			fRec1057[0] = fRec1059[0];
			double fRec1058 = (fRec1061 + fTemp494);
			double fTemp498 = (fConst117 * (((0.034346033800000002 * fTemp76) + (0.0081661475000000001 * fTemp77)) + (0.025954395000000002 * fTemp78)));
			double fTemp499 = (fConst118 * fRec1066[1]);
			fRec1068[0] = (fTemp498 + (fRec1068[1] + fTemp499));
			fRec1066[0] = fRec1068[0];
			double fRec1067 = (fTemp499 + fTemp498);
			double fTemp500 = (fConst120 * ((((0.056540471500000002 * fTemp81) + (0.017900681700000001 * fTemp82)) + (0.0131673502 * fTemp83)) - ((0.031246581999999998 * fTemp85) + (0.015987934400000001 * fTemp84))));
			double fTemp501 = (fConst121 * fRec1069[1]);
			double fTemp502 = (fConst122 * fRec1072[1]);
			fRec1074[0] = (fTemp500 + (fTemp501 + (fRec1074[1] + fTemp502)));
			fRec1072[0] = fRec1074[0];
			double fRec1073 = ((fTemp502 + fTemp501) + fTemp500);
			fRec1071[0] = (fRec1072[0] + fRec1071[1]);
			fRec1069[0] = fRec1071[0];
			double fRec1070 = fRec1073;
			fVec15[(IOTA & 127)] = (((0.072361754400000006 * fTemp97) + ((0.040328929200000002 * fTemp96) + ((0.0073802201000000003 * fTemp7) + ((0.042859930900000003 * fTemp8) + ((0.047024532700000003 * fTemp89) + ((0.0079240192000000001 * fTemp94) + ((0.0269906704 * fTemp93) + ((0.027953685299999999 * fTemp92) + ((0.0123350934 * fTemp90) + ((0.0148994292 * fTemp13) + (fRec1013 + (fRec1031 + (fRec1046 + (fRec1058 + (fRec1067 + fRec1070))))))))))))))) - ((0.011589791 * fTemp9) + ((0.012995667400000001 * fTemp10) + ((0.0056671695999999999 * fTemp11) + ((0.033984505300000002 * fTemp95) + ((0.0319166029 * fTemp91) + (0.0057412653999999999 * fTemp12)))))));
			output15[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec15[((IOTA - iConst123) & 127)])));
			double fTemp503 = (fConst125 * fRec1075[1]);
			double fTemp504 = (fConst126 * fRec1078[1]);
			double fTemp505 = (fConst128 * fRec1081[1]);
			double fTemp506 = (fConst129 * fRec1084[1]);
			double fTemp507 = (fConst131 * (((0.0118585819 * fTemp30) + ((0.0086491183999999992 * fTemp20) + (0.0141543259 * fTemp29))) - ((0.040831345800000002 * fTemp24) + ((0.059998209500000003 * fTemp23) + ((0.0027948386999999998 * fTemp22) + (((((((0.0056906066000000002 * fTemp25) + (0.045576220600000002 * fTemp18)) + (0.072456232800000006 * fTemp26)) + (0.022871921699999999 * fTemp27)) + (0.0380987427 * fTemp28)) + (0.064678272499999995 * fTemp19)) + (0.036707691600000002 * fTemp21)))))));
			double fTemp508 = (fConst132 * fRec1087[1]);
			double fTemp509 = (fConst133 * fRec1090[1]);
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
			double fTemp510 = (fConst135 * fRec1093[1]);
			double fTemp511 = (fConst137 * fRec1096[1]);
			double fTemp512 = (fConst138 * fRec1099[1]);
			double fTemp513 = (fConst140 * (((0.030090476200000001 * fTemp43) + (0.0063944604000000004 * fTemp47)) - ((0.0475368101 * fTemp46) + ((0.11497858919999999 * fTemp45) + ((0.0418104989 * fTemp44) + ((0.046797434800000003 * fTemp41) + (((((0.0258053026 * fTemp37) + (0.064942065300000004 * fTemp38)) + (0.0074006324999999996 * fTemp42)) + (0.065501180800000003 * fTemp39)) + (0.0497667574 * fTemp40))))))));
			double fTemp514 = (fConst141 * fRec1102[1]);
			double fTemp515 = (fConst142 * fRec1105[1]);
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
			double fTemp516 = (fConst144 * fRec1108[1]);
			double fTemp517 = (fConst145 * fRec1111[1]);
			double fTemp518 = (fConst147 * ((((0.0041447818000000004 * fTemp54) + (0.1048635136 * fTemp56)) + (0.0042336205000000002 * fTemp57)) - ((0.028000909000000001 * fTemp61) + ((0.1145065529 * fTemp60) + ((0.073002388500000001 * fTemp59) + (((0.033978180400000002 * fTemp53) + (0.087137983000000002 * fTemp55)) + (0.010158956300000001 * fTemp58)))))));
			double fTemp519 = (fConst148 * fRec1114[1]);
			double fTemp520 = (fConst149 * fRec1117[1]);
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
			double fTemp521 = (fConst151 * fRec1120[1]);
			double fTemp522 = (fConst153 * (((((0.0052889347999999997 * fTemp66) + (0.1202940882 * fTemp67)) + (0.093574874200000005 * fTemp69)) + (0.045274177899999997 * fTemp71)) - ((0.062968760900000004 * fTemp72) + ((0.054973781899999997 * fTemp70) + (0.0702121629 * fTemp68)))));
			double fTemp523 = (fConst154 * fRec1123[1]);
			double fTemp524 = (fConst155 * fRec1126[1]);
			fRec1128[0] = (fTemp522 + (fTemp523 + (fRec1128[1] + fTemp524)));
			fRec1126[0] = fRec1128[0];
			double fRec1127 = ((fTemp524 + fTemp523) + fTemp522);
			fRec1125[0] = (fRec1126[0] + fRec1125[1]);
			fRec1123[0] = fRec1125[0];
			double fRec1124 = fRec1127;
			fRec1122[0] = (fTemp521 + (fRec1124 + fRec1122[1]));
			fRec1120[0] = fRec1122[0];
			double fRec1121 = (fRec1124 + fTemp521);
			double fTemp525 = (fConst157 * (((0.070419014000000002 * fTemp76) + (0.071391873699999997 * fTemp77)) + (0.040731515199999999 * fTemp78)));
			double fTemp526 = (fConst158 * fRec1129[1]);
			fRec1131[0] = (fTemp525 + (fRec1131[1] + fTemp526));
			fRec1129[0] = fRec1131[0];
			double fRec1130 = (fTemp526 + fTemp525);
			double fTemp527 = (fConst160 * (((((0.069363888799999995 * fTemp81) + (0.12224572190000001 * fTemp82)) + (0.024018279199999999 * fTemp85)) + (0.067786083900000002 * fTemp83)) - (0.037380876299999997 * fTemp84)));
			double fTemp528 = (fConst161 * fRec1132[1]);
			double fTemp529 = (fConst162 * fRec1135[1]);
			fRec1137[0] = (fTemp527 + (fTemp528 + (fRec1137[1] + fTemp529)));
			fRec1135[0] = fRec1137[0];
			double fRec1136 = ((fTemp529 + fTemp528) + fTemp527);
			fRec1134[0] = (fRec1135[0] + fRec1134[1]);
			fRec1132[0] = fRec1134[0];
			double fRec1133 = fRec1136;
			fVec16[(IOTA & 127)] = (((0.0039926709999999997 * fTemp97) + ((0.0201999834 * fTemp96) + ((0.0196674581 * fTemp7) + ((0.0027278711999999998 * fTemp9) + ((0.016035579599999999 * fTemp10) + ((0.031029200100000001 * fTemp95) + ((0.0010690882 * fTemp90) + ((0.038011396400000001 * fTemp13) + (fRec1076 + (fRec1094 + (fRec1109 + (fRec1121 + (fRec1130 + fRec1133))))))))))))) - ((((0.018654746100000001 * fTemp12) + (((((0.0089648273000000004 * fTemp91) + (0.043029529800000001 * fTemp92)) + (0.049596291000000001 * fTemp93)) + (0.0288682343 * fTemp94)) + (0.047683692799999997 * fTemp89))) + (0.0022791012 * fTemp11)) + (0.0090428409999999994 * fTemp8)));
			output16[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec16[((IOTA - iConst163) & 127)])));
			double fTemp530 = (fConst157 * (((0.016552897800000001 * fTemp76) + (0.0533641272 * fTemp77)) + (0.068042738800000002 * fTemp78)));
			double fTemp531 = (fConst158 * fRec1138[1]);
			fRec1140[0] = (fTemp530 + (fRec1140[1] + fTemp531));
			fRec1138[0] = fRec1140[0];
			double fRec1139 = (fTemp531 + fTemp530);
			double fTemp532 = (fConst125 * fRec1141[1]);
			double fTemp533 = (fConst126 * fRec1144[1]);
			double fTemp534 = (fConst128 * fRec1147[1]);
			double fTemp535 = (fConst129 * fRec1150[1]);
			double fTemp536 = (fConst131 * (((0.0055724470000000003 * fTemp30) + ((0.023440287399999999 * fTemp29) + ((0.044592842299999998 * fTemp24) + ((((((0.013214867 * fTemp25) + (0.046306349199999999 * fTemp18)) + (0.072182524299999995 * fTemp26)) + (0.039909270900000002 * fTemp27)) + (0.0352789981 * fTemp20)) + (0.021937387400000001 * fTemp23))))) - ((0.058844398200000002 * fTemp22) + (((0.022091027499999999 * fTemp28) + (0.021711689999999999 * fTemp19)) + (0.071826815099999997 * fTemp21)))));
			double fTemp537 = (fConst132 * fRec1153[1]);
			double fTemp538 = (fConst133 * fRec1156[1]);
			fRec1158[0] = (fTemp536 + (fTemp537 + (fRec1158[1] + fTemp538)));
			fRec1156[0] = fRec1158[0];
			double fRec1157 = ((fTemp538 + fTemp537) + fTemp536);
			fRec1155[0] = (fRec1156[0] + fRec1155[1]);
			fRec1153[0] = fRec1155[0];
			double fRec1154 = fRec1157;
			fRec1152[0] = (fTemp534 + (fTemp535 + (fRec1154 + fRec1152[1])));
			fRec1150[0] = fRec1152[0];
			double fRec1151 = (fTemp534 + (fRec1154 + fTemp535));
			fRec1149[0] = (fRec1150[0] + fRec1149[1]);
			fRec1147[0] = fRec1149[0];
			double fRec1148 = fRec1151;
			fRec1146[0] = (fTemp532 + (fTemp533 + (fRec1148 + fRec1146[1])));
			fRec1144[0] = fRec1146[0];
			double fRec1145 = (fTemp532 + (fRec1148 + fTemp533));
			fRec1143[0] = (fRec1144[0] + fRec1143[1]);
			fRec1141[0] = fRec1143[0];
			double fRec1142 = fRec1145;
			double fTemp539 = (fConst135 * fRec1159[1]);
			double fTemp540 = (fConst137 * fRec1162[1]);
			double fTemp541 = (fConst138 * fRec1165[1]);
			double fTemp542 = (fConst140 * (((0.0142086405 * fTemp47) + ((0.049669808699999998 * fTemp46) + ((0.073078142400000004 * fTemp45) + (((((0.0241925087 * fTemp37) + (0.065128708600000002 * fTemp38)) + (0.073652078600000004 * fTemp42)) + (0.016192743400000001 * fTemp43)) + (0.0073126748999999998 * fTemp44))))) - ((0.098391668400000007 * fTemp41) + ((0.022909782199999999 * fTemp39) + (0.028606388699999999 * fTemp40)))));
			double fTemp543 = (fConst141 * fRec1168[1]);
			double fTemp544 = (fConst142 * fRec1171[1]);
			fRec1173[0] = (fTemp542 + (fTemp543 + (fRec1173[1] + fTemp544)));
			fRec1171[0] = fRec1173[0];
			double fRec1172 = ((fTemp544 + fTemp543) + fTemp542);
			fRec1170[0] = (fRec1171[0] + fRec1170[1]);
			fRec1168[0] = fRec1170[0];
			double fRec1169 = fRec1172;
			fRec1167[0] = (fTemp540 + (fTemp541 + (fRec1169 + fRec1167[1])));
			fRec1165[0] = fRec1167[0];
			double fRec1166 = (fTemp540 + (fRec1169 + fTemp541));
			fRec1164[0] = (fRec1165[0] + fRec1164[1]);
			fRec1162[0] = fRec1164[0];
			double fRec1163 = fRec1166;
			fRec1161[0] = (fTemp539 + (fRec1163 + fRec1161[1]));
			fRec1159[0] = fRec1161[0];
			double fRec1160 = (fRec1163 + fTemp539);
			double fTemp545 = (fConst144 * fRec1174[1]);
			double fTemp546 = (fConst145 * fRec1177[1]);
			double fTemp547 = (fConst147 * (((0.028821366599999999 * fTemp61) + ((0.082303723699999998 * fTemp60) + ((((0.034112062999999998 * fTemp53) + (0.071048121300000003 * fTemp54)) + (0.052281072900000003 * fTemp56)) + (0.085731005900000004 * fTemp59)))) - (((0.0043342603 * fTemp57) + (0.079673439600000007 * fTemp55)) + (0.036044131799999997 * fTemp58))));
			double fTemp548 = (fConst148 * fRec1180[1]);
			double fTemp549 = (fConst149 * fRec1183[1]);
			fRec1185[0] = (fTemp547 + (fTemp548 + (fRec1185[1] + fTemp549)));
			fRec1183[0] = fRec1185[0];
			double fRec1184 = ((fTemp549 + fTemp548) + fTemp547);
			fRec1182[0] = (fRec1183[0] + fRec1182[1]);
			fRec1180[0] = fRec1182[0];
			double fRec1181 = fRec1184;
			fRec1179[0] = (fTemp545 + (fTemp546 + (fRec1181 + fRec1179[1])));
			fRec1177[0] = fRec1179[0];
			double fRec1178 = (fTemp545 + (fRec1181 + fTemp546));
			fRec1176[0] = (fRec1177[0] + fRec1176[1]);
			fRec1174[0] = fRec1176[0];
			double fRec1175 = fRec1178;
			double fTemp550 = (fConst160 * (((((0.032291960100000003 * fTemp81) + (0.028149608100000001 * fTemp82)) + (0.0055090701000000001 * fTemp85)) + (0.1100413943 * fTemp83)) + (0.064499198699999996 * fTemp84)));
			double fTemp551 = (fConst161 * fRec1186[1]);
			double fTemp552 = (fConst162 * fRec1189[1]);
			fRec1191[0] = (fTemp550 + (fTemp551 + (fRec1191[1] + fTemp552)));
			fRec1189[0] = fRec1191[0];
			double fRec1190 = ((fTemp552 + fTemp551) + fTemp550);
			fRec1188[0] = (fRec1189[0] + fRec1188[1]);
			fRec1186[0] = fRec1188[0];
			double fRec1187 = fRec1190;
			double fTemp553 = (fConst151 * fRec1192[1]);
			double fTemp554 = (fConst153 * (((0.047697994600000002 * fTemp72) + ((0.1082953167 * fTemp68) + ((((0.038209709600000002 * fTemp66) + (0.057503765200000001 * fTemp67)) + (0.019567569399999998 * fTemp69)) + (0.064697349799999998 * fTemp71)))) - (0.063294942800000004 * fTemp70)));
			double fTemp555 = (fConst154 * fRec1195[1]);
			double fTemp556 = (fConst155 * fRec1198[1]);
			fRec1200[0] = (fTemp554 + (fTemp555 + (fRec1200[1] + fTemp556)));
			fRec1198[0] = fRec1200[0];
			double fRec1199 = ((fTemp556 + fTemp555) + fTemp554);
			fRec1197[0] = (fRec1198[0] + fRec1197[1]);
			fRec1195[0] = fRec1197[0];
			double fRec1196 = fRec1199;
			fRec1194[0] = (fTemp553 + (fRec1196 + fRec1194[1]));
			fRec1192[0] = fRec1194[0];
			double fRec1193 = (fRec1196 + fTemp553);
			fVec17[(IOTA & 127)] = (((0.0017626132 * fTemp97) + ((0.0083576984999999999 * fTemp96) + ((0.0186796467 * fTemp7) + ((0.014233516599999999 * fTemp8) + ((0.0020074826999999999 * fTemp11) + ((0.053276281799999999 * fTemp95) + ((0.047764573999999997 * fTemp93) + ((0.052022434100000001 * fTemp92) + ((0.024331470000000001 * fTemp91) + ((0.0043099838999999997 * fTemp90) + ((0.0306211721 * fTemp13) + (fRec1139 + (fRec1142 + (fRec1160 + (fRec1175 + (fRec1187 + fRec1193)))))))))))))))) - ((0.027380326300000001 * fTemp9) + (((0.0059091687999999996 * fTemp12) + ((0.0039529198000000003 * fTemp94) + (0.034359653499999997 * fTemp89))) + (0.061097380399999998 * fTemp10))));
			output17[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec17[((IOTA - iConst163) & 127)])));
			double fTemp557 = (fConst125 * fRec1201[1]);
			double fTemp558 = (fConst126 * fRec1204[1]);
			double fTemp559 = (fConst128 * fRec1207[1]);
			double fTemp560 = (fConst129 * fRec1210[1]);
			double fTemp561 = (fConst131 * (((0.022857013900000001 * fTemp23) + (((0.0086214016999999997 * fTemp20) + ((0.036753430400000002 * fTemp19) + ((0.0057154739000000003 * fTemp25) + (0.0380934697 * fTemp28)))) + (0.0028026773 * fTemp22))) - ((0.0118532867 * fTemp30) + ((0.045583768199999999 * fTemp29) + (((((0.014155940800000001 * fTemp18) + (0.072483714500000004 * fTemp26)) + (0.060035029199999999 * fTemp27)) + (0.064707459499999995 * fTemp21)) + (0.040840608100000002 * fTemp24))))));
			double fTemp562 = (fConst132 * fRec1213[1]);
			double fTemp563 = (fConst133 * fRec1216[1]);
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
			double fTemp564 = (fConst135 * fRec1219[1]);
			double fTemp565 = (fConst137 * fRec1222[1]);
			double fTemp566 = (fConst138 * fRec1225[1]);
			double fTemp567 = (fConst140 * (((0.0073981732999999997 * fTemp45) + ((0.046806107800000003 * fTemp39) + (0.041825001200000003 * fTemp44))) - ((0.025806042099999999 * fTemp47) + (((0.065490446100000002 * fTemp41) + (((((0.0063845550999999997 * fTemp37) + (0.064948325099999996 * fTemp38)) + (0.1150033816 * fTemp42)) + (0.030129419599999999 * fTemp43)) + (0.049805494899999997 * fTemp40))) + (0.047533985799999998 * fTemp46)))));
			double fTemp568 = (fConst141 * fRec1228[1]);
			double fTemp569 = (fConst142 * fRec1231[1]);
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
			double fTemp570 = (fConst144 * fRec1234[1]);
			double fTemp571 = (fConst145 * fRec1237[1]);
			double fTemp572 = (fConst147 * (((0.0730098208 * fTemp59) + ((0.0101406967 * fTemp57) + (0.00427196 * fTemp58))) - ((0.027996421699999999 * fTemp61) + (((((0.033971424600000001 * fTemp53) + (0.11450058220000001 * fTemp54)) + (0.1048835318 * fTemp56)) + (0.0871444725 * fTemp55)) + (0.0041402097000000004 * fTemp60)))));
			double fTemp573 = (fConst148 * fRec1240[1]);
			double fTemp574 = (fConst149 * fRec1243[1]);
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
			double fTemp575 = (fConst151 * fRec1246[1]);
			double fTemp576 = (fConst153 * (((0.093594236999999997 * fTemp71) + (0.0702060563 * fTemp68)) - (((((0.062953242500000006 * fTemp66) + (0.120279476 * fTemp67)) + (0.045284256799999999 * fTemp69)) + (0.054949432499999999 * fTemp70)) + (0.0052855645000000001 * fTemp72))));
			double fTemp577 = (fConst154 * fRec1249[1]);
			double fTemp578 = (fConst155 * fRec1252[1]);
			fRec1254[0] = (fTemp576 + (fTemp577 + (fRec1254[1] + fTemp578)));
			fRec1252[0] = fRec1254[0];
			double fRec1253 = ((fTemp578 + fTemp577) + fTemp576);
			fRec1251[0] = (fRec1252[0] + fRec1251[1]);
			fRec1249[0] = fRec1251[0];
			double fRec1250 = fRec1253;
			fRec1248[0] = (fTemp575 + (fRec1250 + fRec1248[1]));
			fRec1246[0] = fRec1248[0];
			double fRec1247 = (fRec1250 + fTemp575);
			double fTemp579 = (fConst157 * (((0.071384467300000004 * fTemp77) + (0.070400406499999998 * fTemp78)) - (0.040719139299999998 * fTemp76)));
			double fTemp580 = (fConst158 * fRec1255[1]);
			fRec1257[0] = (fTemp579 + (fRec1257[1] + fTemp580));
			fRec1255[0] = fRec1257[0];
			double fRec1256 = (fTemp580 + fTemp579);
			double fTemp581 = (fConst160 * ((((0.024035194700000002 * fTemp85) + (0.1222313142 * fTemp83)) + (0.037372044600000001 * fTemp84)) - ((0.069343358699999996 * fTemp81) + (0.067775739400000007 * fTemp82))));
			double fTemp582 = (fConst161 * fRec1258[1]);
			double fTemp583 = (fConst162 * fRec1261[1]);
			fRec1263[0] = (fTemp581 + (fTemp582 + (fRec1263[1] + fTemp583)));
			fRec1261[0] = fRec1263[0];
			double fRec1262 = ((fTemp583 + fTemp582) + fTemp581);
			fRec1260[0] = (fRec1261[0] + fRec1260[1]);
			fRec1258[0] = fRec1260[0];
			double fRec1259 = fRec1262;
			fVec18[(IOTA & 127)] = (((0.028852915 * fTemp9) + ((0.0310411058 * fTemp95) + ((0.0023283465 * fTemp12) + ((0.047733121900000001 * fTemp89) + ((0.0027240950000000002 * fTemp94) + ((0.0089884205999999998 * fTemp91) + ((0.0040253051000000003 * fTemp90) + ((0.038002752799999998 * fTemp13) + (fRec1202 + (fRec1220 + (fRec1235 + (fRec1247 + (fRec1256 + fRec1259))))))))))))) - ((0.0010394667 * fTemp97) + ((0.020202636 * fTemp96) + ((0.043045385899999997 * fTemp7) + (((0.016030583300000002 * fTemp10) + (((0.019690576099999999 * fTemp92) + (0.049619550700000001 * fTemp93)) + (0.018683046500000001 * fTemp11))) + (0.0090662060000000003 * fTemp8))))));
			output18[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec18[((IOTA - iConst163) & 127)])));
			double fTemp584 = (fConst125 * fRec1264[1]);
			double fTemp585 = (fConst126 * fRec1267[1]);
			double fTemp586 = (fConst128 * fRec1270[1]);
			double fTemp587 = (fConst129 * fRec1273[1]);
			double fTemp588 = (fConst131 * (((0.046306332399999997 * fTemp29) + ((((0.035248227200000003 * fTemp20) + ((0.071814388100000001 * fTemp19) + (((0.072130878100000004 * fTemp26) + (0.021894563499999999 * fTemp27)) + (0.022018603300000002 * fTemp28)))) + (0.058853132099999997 * fTemp22)) + (0.044590881499999999 * fTemp24))) - (((((0.0132350418 * fTemp25) + (0.023419229900000001 * fTemp18)) + (0.0217096411 * fTemp21)) + (0.039913482600000001 * fTemp23)) + (0.0055200598000000002 * fTemp30))));
			double fTemp589 = (fConst132 * fRec1276[1]);
			double fTemp590 = (fConst133 * fRec1279[1]);
			fRec1281[0] = (fTemp588 + (fTemp589 + (fRec1281[1] + fTemp590)));
			fRec1279[0] = fRec1281[0];
			double fRec1280 = ((fTemp590 + fTemp589) + fTemp588);
			fRec1278[0] = (fRec1279[0] + fRec1278[1]);
			fRec1276[0] = fRec1278[0];
			double fRec1277 = fRec1280;
			fRec1275[0] = (fTemp586 + (fTemp587 + (fRec1277 + fRec1275[1])));
			fRec1273[0] = fRec1275[0];
			double fRec1274 = (fTemp586 + (fRec1277 + fTemp587));
			fRec1272[0] = (fRec1273[0] + fRec1272[1]);
			fRec1270[0] = fRec1272[0];
			double fRec1271 = fRec1274;
			fRec1269[0] = (fTemp584 + (fTemp585 + (fRec1271 + fRec1269[1])));
			fRec1267[0] = fRec1269[0];
			double fRec1268 = (fTemp584 + (fRec1271 + fTemp585));
			fRec1266[0] = (fRec1267[0] + fRec1266[1]);
			fRec1264[0] = fRec1266[0];
			double fRec1265 = fRec1268;
			double fTemp591 = (fConst135 * fRec1282[1]);
			double fTemp592 = (fConst137 * fRec1285[1]);
			double fTemp593 = (fConst138 * fRec1288[1]);
			double fTemp594 = (fConst140 * (((0.0242062654 * fTemp47) + ((((0.065107283700000004 * fTemp38) + (0.073068349199999993 * fTemp42)) + (0.098379142500000002 * fTemp39)) + (0.049674152100000001 * fTemp46))) - ((0.0736226933 * fTemp45) + ((0.0072948364999999996 * fTemp44) + ((0.022877380999999999 * fTemp41) + (((0.0141870746 * fTemp37) + (0.016235548999999998 * fTemp43)) + (0.028620153799999999 * fTemp40)))))));
			double fTemp595 = (fConst141 * fRec1291[1]);
			double fTemp596 = (fConst142 * fRec1294[1]);
			fRec1296[0] = (fTemp594 + (fTemp595 + (fRec1296[1] + fTemp596)));
			fRec1294[0] = fRec1296[0];
			double fRec1295 = ((fTemp596 + fTemp595) + fTemp594);
			fRec1293[0] = (fRec1294[0] + fRec1293[1]);
			fRec1291[0] = fRec1293[0];
			double fRec1292 = fRec1295;
			fRec1290[0] = (fTemp592 + (fTemp593 + (fRec1292 + fRec1290[1])));
			fRec1288[0] = fRec1290[0];
			double fRec1289 = (fTemp592 + (fRec1292 + fTemp593));
			fRec1287[0] = (fRec1288[0] + fRec1287[1]);
			fRec1285[0] = fRec1287[0];
			double fRec1286 = fRec1289;
			fRec1284[0] = (fTemp591 + (fRec1286 + fRec1284[1]));
			fRec1282[0] = fRec1284[0];
			double fRec1283 = (fRec1286 + fTemp591);
			double fTemp597 = (fConst144 * fRec1297[1]);
			double fTemp598 = (fConst145 * fRec1300[1]);
			double fTemp599 = (fConst147 * (((((0.0341125397 * fTemp53) + (0.082316823499999997 * fTemp54)) + (0.036036336600000003 * fTemp57)) + (0.028822862599999999 * fTemp61)) - ((0.071022644300000007 * fTemp60) + ((0.085731476200000004 * fTemp59) + (((0.0522847148 * fTemp56) + (0.079680596500000006 * fTemp55)) + (0.0043025155000000004 * fTemp58))))));
			double fTemp600 = (fConst148 * fRec1303[1]);
			double fTemp601 = (fConst149 * fRec1306[1]);
			fRec1308[0] = (fTemp599 + (fTemp600 + (fRec1308[1] + fTemp601)));
			fRec1306[0] = fRec1308[0];
			double fRec1307 = ((fTemp601 + fTemp600) + fTemp599);
			fRec1305[0] = (fRec1306[0] + fRec1305[1]);
			fRec1303[0] = fRec1305[0];
			double fRec1304 = fRec1307;
			fRec1302[0] = (fTemp597 + (fTemp598 + (fRec1304 + fRec1302[1])));
			fRec1300[0] = fRec1302[0];
			double fRec1301 = (fTemp597 + (fRec1304 + fTemp598));
			fRec1299[0] = (fRec1300[0] + fRec1299[1]);
			fRec1297[0] = fRec1299[0];
			double fRec1298 = fRec1301;
			double fTemp602 = (fConst151 * fRec1309[1]);
			double fTemp603 = (fConst153 * (((0.047710902999999999 * fTemp66) + (0.019581777799999998 * fTemp71)) - ((0.038201092999999998 * fTemp72) + ((((0.057491693699999999 * fTemp67) + (0.064715528600000002 * fTemp69)) + (0.063298276000000001 * fTemp70)) + (0.1083150329 * fTemp68)))));
			double fTemp604 = (fConst154 * fRec1312[1]);
			double fTemp605 = (fConst155 * fRec1315[1]);
			fRec1317[0] = (fTemp603 + (fTemp604 + (fRec1317[1] + fTemp605)));
			fRec1315[0] = fRec1317[0];
			double fRec1316 = ((fTemp605 + fTemp604) + fTemp603);
			fRec1314[0] = (fRec1315[0] + fRec1314[1]);
			fRec1312[0] = fRec1314[0];
			double fRec1313 = fRec1316;
			fRec1311[0] = (fTemp602 + (fRec1313 + fRec1311[1]));
			fRec1309[0] = fRec1311[0];
			double fRec1310 = (fRec1313 + fTemp602);
			double fTemp606 = (fConst157 * (((0.053382876199999998 * fTemp77) + (0.016550943200000001 * fTemp78)) - (0.068062192199999996 * fTemp76)));
			double fTemp607 = (fConst158 * fRec1318[1]);
			fRec1320[0] = (fTemp606 + (fRec1320[1] + fTemp607));
			fRec1318[0] = fRec1320[0];
			double fRec1319 = (fTemp607 + fTemp606);
			double fTemp608 = (fConst160 * (((0.0055179063999999996 * fTemp85) + (0.028150457199999999 * fTemp83)) - (((0.032284151099999998 * fTemp81) + (0.1100701746 * fTemp82)) + (0.064516527800000001 * fTemp84))));
			double fTemp609 = (fConst161 * fRec1321[1]);
			double fTemp610 = (fConst162 * fRec1324[1]);
			fRec1326[0] = (fTemp608 + (fTemp609 + (fRec1326[1] + fTemp610)));
			fRec1324[0] = fRec1326[0];
			double fRec1325 = ((fTemp610 + fTemp609) + fTemp608);
			fRec1323[0] = (fRec1324[0] + fRec1323[1]);
			fRec1321[0] = fRec1323[0];
			double fRec1322 = fRec1325;
			fVec19[(IOTA & 127)] = (((0.051981864599999997 * fTemp7) + ((0.0142063902 * fTemp8) + ((0.0038959339000000002 * fTemp9) + ((0.061079201 * fTemp10) + ((0.053238720099999998 * fTemp95) + ((0.034311255700000001 * fTemp89) + ((0.047712846400000002 * fTemp93) + ((0.0016841637 * fTemp90) + ((0.030631296299999999 * fTemp13) + (fRec1265 + (fRec1283 + (fRec1298 + (fRec1310 + (fRec1319 + fRec1322)))))))))))))) - ((0.0043230131000000002 * fTemp97) + ((((((0.024351716400000001 * fTemp91) + (0.018683052200000001 * fTemp92)) + (0.027433833500000001 * fTemp94)) + (0.0019915114999999998 * fTemp12)) + (0.0059492013 * fTemp11)) + (0.0082907333999999999 * fTemp96))));
			output19[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec19[((IOTA - iConst163) & 127)])));
			double fTemp611 = (fConst125 * fRec1327[1]);
			double fTemp612 = (fConst126 * fRec1330[1]);
			double fTemp613 = (fConst128 * fRec1333[1]);
			double fTemp614 = (fConst129 * fRec1336[1]);
			double fTemp615 = (fConst131 * (((((0.0366770872 * fTemp21) + ((0.0085917635000000003 * fTemp20) + (((0.0456294265 * fTemp18) + (0.022916585999999999 * fTemp27)) + (0.064663743699999998 * fTemp19)))) + (0.0600184567 * fTemp23)) + (0.011849361100000001 * fTemp30)) - ((0.0141228723 * fTemp29) + (((((0.0057107457000000004 * fTemp25) + (0.072490549599999995 * fTemp26)) + (0.038080408699999999 * fTemp28)) + (0.0028365853000000001 * fTemp22)) + (0.040878079300000002 * fTemp24)))));
			double fTemp616 = (fConst132 * fRec1339[1]);
			double fTemp617 = (fConst133 * fRec1342[1]);
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
			double fTemp618 = (fConst135 * fRec1345[1]);
			double fTemp619 = (fConst137 * fRec1348[1]);
			double fTemp620 = (fConst138 * fRec1351[1]);
			double fTemp621 = (fConst140 * (((((((0.025825992799999999 * fTemp37) + (0.0073937598999999996 * fTemp42)) + (0.030094396999999998 * fTemp43)) + (0.065430889300000003 * fTemp39)) + (0.046766572899999997 * fTemp41)) + (0.114995571 * fTemp45)) - ((0.0063608405000000002 * fTemp47) + ((((0.064932673100000005 * fTemp38) + (0.049777326199999999 * fTemp40)) + (0.041861726199999998 * fTemp44)) + (0.047602963599999999 * fTemp46)))));
			double fTemp622 = (fConst141 * fRec1354[1]);
			double fTemp623 = (fConst142 * fRec1357[1]);
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
			double fTemp624 = (fConst144 * fRec1360[1]);
			double fTemp625 = (fConst145 * fRec1363[1]);
			double fTemp626 = (fConst147 * ((((0.1048542385 * fTemp56) + (0.0101488086 * fTemp58)) + (0.1145043437 * fTemp60)) - ((((((0.0339556414 * fTemp53) + (0.0041961758000000002 * fTemp54)) + (0.0042976118000000001 * fTemp57)) + (0.087095462100000007 * fTemp55)) + (0.073005793499999999 * fTemp59)) + (0.028043553999999998 * fTemp61))));
			double fTemp627 = (fConst148 * fRec1366[1]);
			double fTemp628 = (fConst149 * fRec1369[1]);
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
			double fTemp629 = (fConst151 * fRec1372[1]);
			double fTemp630 = (fConst153 * (((0.1202824868 * fTemp67) + (0.062959801400000001 * fTemp72)) - (((((0.0053327195000000003 * fTemp66) + (0.093581303099999999 * fTemp69)) + (0.054921770000000002 * fTemp70)) + (0.045266623899999997 * fTemp71)) + (0.070170791999999996 * fTemp68))));
			double fTemp631 = (fConst154 * fRec1375[1]);
			double fTemp632 = (fConst155 * fRec1378[1]);
			fRec1380[0] = (fTemp630 + (fTemp631 + (fRec1380[1] + fTemp632)));
			fRec1378[0] = fRec1380[0];
			double fRec1379 = ((fTemp632 + fTemp631) + fTemp630);
			fRec1377[0] = (fRec1378[0] + fRec1377[1]);
			fRec1375[0] = fRec1377[0];
			double fRec1376 = fRec1379;
			fRec1374[0] = (fTemp629 + (fRec1376 + fRec1374[1]));
			fRec1372[0] = fRec1374[0];
			double fRec1373 = (fRec1376 + fTemp629);
			double fTemp633 = (fConst157 * ((0.071377611199999996 * fTemp77) - ((0.070388008899999993 * fTemp76) + (0.040726760399999999 * fTemp78))));
			double fTemp634 = (fConst158 * fRec1381[1]);
			fRec1383[0] = (fTemp633 + (fRec1383[1] + fTemp634));
			fRec1381[0] = fRec1383[0];
			double fRec1382 = (fTemp634 + fTemp633);
			double fTemp635 = (fConst160 * (((0.069357866800000001 * fTemp81) + (0.024036521700000001 * fTemp85)) - (((0.12220778309999999 * fTemp82) + (0.067775720299999995 * fTemp83)) + (0.037343894099999997 * fTemp84))));
			double fTemp636 = (fConst161 * fRec1384[1]);
			double fTemp637 = (fConst162 * fRec1387[1]);
			fRec1389[0] = (fTemp635 + (fTemp636 + (fRec1389[1] + fTemp637)));
			fRec1387[0] = fRec1389[0];
			double fRec1388 = ((fTemp637 + fTemp636) + fTemp635);
			fRec1386[0] = (fRec1387[0] + fRec1386[1]);
			fRec1384[0] = fRec1386[0];
			double fRec1385 = fRec1388;
			fVec20[(IOTA & 127)] = (((0.020210879099999999 * fTemp96) + ((0.0160516814 * fTemp10) + ((0.0022764781000000002 * fTemp11) + ((0.0309776688 * fTemp95) + ((0.018698904299999999 * fTemp12) + ((0.0289086723 * fTemp94) + (((0.037999764599999999 * fTemp13) + (fRec1328 + (fRec1346 + (fRec1361 + (fRec1373 + (fRec1382 + fRec1385)))))) + (0.043103839499999998 * fTemp92)))))))) - ((0.0039789159000000003 * fTemp97) + ((0.019677195500000001 * fTemp7) + ((0.0090375374000000001 * fTemp8) + (((((0.0010524529 * fTemp90) + (0.0089926017 * fTemp91)) + (0.049647475099999998 * fTemp93)) + (0.0476628147 * fTemp89)) + (0.0027401029000000002 * fTemp9))))));
			output20[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec20[((IOTA - iConst163) & 127)])));
			double fTemp638 = (fConst125 * fRec1390[1]);
			double fTemp639 = (fConst126 * fRec1393[1]);
			double fTemp640 = (fConst128 * fRec1396[1]);
			double fTemp641 = (fConst129 * fRec1399[1]);
			double fTemp642 = (fConst131 * (((((0.071783693300000007 * fTemp21) + ((0.035300383400000003 * fTemp20) + (((0.013209058900000001 * fTemp25) + (0.072177164899999993 * fTemp26)) + (0.021675314800000001 * fTemp19)))) + (0.044600697699999997 * fTemp24)) + (0.0055229197000000001 * fTemp30)) - (((0.021935633499999999 * fTemp23) + ((((0.046318982600000003 * fTemp18) + (0.039890292700000003 * fTemp27)) + (0.022045015300000002 * fTemp28)) + (0.058872026399999999 * fTemp22))) + (0.023387818000000001 * fTemp29))));
			double fTemp643 = (fConst132 * fRec1402[1]);
			double fTemp644 = (fConst133 * fRec1405[1]);
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
			double fTemp645 = (fConst135 * fRec1408[1]);
			double fTemp646 = (fConst137 * fRec1411[1]);
			double fTemp647 = (fConst138 * fRec1414[1]);
			double fTemp648 = (fConst140 * ((((0.0072811964000000003 * fTemp44) + ((((0.065142028500000004 * fTemp38) + (0.016183017800000001 * fTemp43)) + (0.0228765763 * fTemp39)) + (0.098387016999999993 * fTemp41))) + (0.0496561924 * fTemp46)) - (((((0.024204461300000001 * fTemp37) + (0.073623973999999995 * fTemp42)) + (0.0285649984 * fTemp40)) + (0.073087242100000005 * fTemp45)) + (0.0141708322 * fTemp47))));
			double fTemp649 = (fConst141 * fRec1417[1]);
			double fTemp650 = (fConst142 * fRec1420[1]);
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
			double fTemp651 = (fConst144 * fRec1423[1]);
			double fTemp652 = (fConst145 * fRec1426[1]);
			double fTemp653 = (fConst147 * ((((0.085715838500000002 * fTemp59) + ((((0.034129172499999999 * fTemp53) + (0.052249432700000001 * fTemp56)) + (0.0043294913000000001 * fTemp57)) + (0.036075632699999999 * fTemp58))) + (0.028806551999999999 * fTemp61)) - (((0.071043614099999999 * fTemp54) + (0.079647853399999996 * fTemp55)) + (0.082312175400000007 * fTemp60))));
			double fTemp654 = (fConst148 * fRec1429[1]);
			double fTemp655 = (fConst149 * fRec1432[1]);
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
			double fTemp656 = (fConst151 * fRec1435[1]);
			double fTemp657 = (fConst153 * (((0.057486007700000001 * fTemp67) + (0.1082990353 * fTemp68)) - (((((0.038218625200000002 * fTemp66) + (0.019553603499999999 * fTemp69)) + (0.063299092400000007 * fTemp70)) + (0.064664790999999999 * fTemp71)) + (0.047701833200000002 * fTemp72))));
			double fTemp658 = (fConst154 * fRec1438[1]);
			double fTemp659 = (fConst155 * fRec1441[1]);
			fRec1443[0] = (fTemp657 + (fTemp658 + (fRec1443[1] + fTemp659)));
			fRec1441[0] = fRec1443[0];
			double fRec1442 = ((fTemp659 + fTemp658) + fTemp657);
			fRec1440[0] = (fRec1441[0] + fRec1440[1]);
			fRec1438[0] = fRec1440[0];
			double fRec1439 = fRec1442;
			fRec1437[0] = (fTemp656 + (fRec1439 + fRec1437[1]));
			fRec1435[0] = fRec1437[0];
			double fRec1436 = (fRec1439 + fTemp656);
			double fTemp660 = (fConst157 * ((0.053354718400000001 * fTemp77) - ((0.016548580800000001 * fTemp76) + (0.068044421800000005 * fTemp78))));
			double fTemp661 = (fConst158 * fRec1444[1]);
			fRec1446[0] = (fTemp660 + (fRec1446[1] + fTemp661));
			fRec1444[0] = fRec1446[0];
			double fRec1445 = (fTemp661 + fTemp660);
			double fTemp662 = (fConst160 * ((((0.0322900754 * fTemp81) + (0.0054927342000000001 * fTemp85)) + (0.064507223000000002 * fTemp84)) - ((0.028137084600000001 * fTemp82) + (0.11003032159999999 * fTemp83))));
			double fTemp663 = (fConst161 * fRec1447[1]);
			double fTemp664 = (fConst162 * fRec1450[1]);
			fRec1452[0] = (fTemp662 + (fTemp663 + (fRec1452[1] + fTemp664)));
			fRec1450[0] = fRec1452[0];
			double fRec1451 = ((fTemp664 + fTemp663) + fTemp662);
			fRec1449[0] = (fRec1450[0] + fRec1449[1]);
			fRec1447[0] = fRec1449[0];
			double fRec1448 = fRec1451;
			fVec21[(IOTA & 127)] = (((0.0082788931000000003 * fTemp96) + ((0.0142592672 * fTemp8) + ((0.0274052358 * fTemp9) + ((0.053263672400000003 * fTemp95) + ((0.0059115425000000003 * fTemp12) + ((0.0039156258999999997 * fTemp94) + ((0.047760973599999999 * fTemp93) + (((0.0306194443 * fTemp13) + (fRec1391 + (fRec1409 + (fRec1424 + (fRec1436 + (fRec1445 + fRec1448)))))) + (0.024319090099999999 * fTemp91))))))))) - ((0.0017207385 * fTemp97) + (((0.061103699599999999 * fTemp10) + ((((0.0042851616999999998 * fTemp90) + (0.052030989200000002 * fTemp92)) + (0.034283363800000001 * fTemp89)) + (0.0020531430999999999 * fTemp11))) + (0.018654249000000001 * fTemp7))));
			output21[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec21[((IOTA - iConst163) & 127)])));
			double fTemp665 = (fConst125 * fRec1453[1]);
			double fTemp666 = (fConst126 * fRec1456[1]);
			double fTemp667 = (fConst128 * fRec1459[1]);
			double fTemp668 = (fConst129 * fRec1462[1]);
			double fTemp669 = (fConst131 * ((((0.0027691412999999998 * fTemp22) + ((0.064636786900000007 * fTemp21) + (((((0.0057046413000000004 * fTemp25) + (0.0141475218 * fTemp18)) + (0.060014399099999997 * fTemp27)) + (0.038063687700000001 * fTemp28)) + (0.0086795263000000004 * fTemp20)))) + (0.0455812762 * fTemp29)) - (((0.040833476799999997 * fTemp24) + (((0.072462844100000007 * fTemp26) + (0.036685820899999999 * fTemp19)) + (0.0228463421 * fTemp23))) + (0.011862200200000001 * fTemp30))));
			double fTemp670 = (fConst132 * fRec1465[1]);
			double fTemp671 = (fConst133 * fRec1468[1]);
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
			double fTemp672 = (fConst135 * fRec1471[1]);
			double fTemp673 = (fConst137 * fRec1474[1]);
			double fTemp674 = (fConst138 * fRec1477[1]);
			double fTemp675 = (fConst140 * ((((0.041807703600000003 * fTemp44) + (((0.0063982583999999997 * fTemp37) + (0.1149951402 * fTemp42)) + (0.065470731399999996 * fTemp41))) + (0.025804003999999998 * fTemp47)) - ((0.047515727899999999 * fTemp46) + (((((0.0649565738 * fTemp38) + (0.030130829200000001 * fTemp43)) + (0.046759442900000003 * fTemp39)) + (0.049747779300000003 * fTemp40)) + (0.0074199701000000002 * fTemp45)))));
			double fTemp676 = (fConst141 * fRec1480[1]);
			double fTemp677 = (fConst142 * fRec1483[1]);
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
			double fTemp678 = (fConst144 * fRec1486[1]);
			double fTemp679 = (fConst145 * fRec1489[1]);
			double fTemp680 = (fConst147 * (((0.0041004887 * fTemp60) + ((0.1145119819 * fTemp54) + (0.073033457100000004 * fTemp59))) - ((((((0.033988066999999997 * fTemp53) + (0.1048814014 * fTemp56)) + (0.010117339499999999 * fTemp57)) + (0.087112857099999996 * fTemp55)) + (0.0042768677999999996 * fTemp58)) + (0.027981421100000001 * fTemp61))));
			double fTemp681 = (fConst148 * fRec1492[1]);
			double fTemp682 = (fConst149 * fRec1495[1]);
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
			double fTemp683 = (fConst151 * fRec1498[1]);
			double fTemp684 = (fConst153 * (((0.0052570658000000003 * fTemp72) + (((0.062967061899999996 * fTemp66) + (0.045294227200000002 * fTemp69)) + (0.070254434500000004 * fTemp68))) - (((0.12028478419999999 * fTemp67) + (0.054933005700000002 * fTemp70)) + (0.093623455100000003 * fTemp71))));
			double fTemp685 = (fConst154 * fRec1501[1]);
			double fTemp686 = (fConst155 * fRec1504[1]);
			fRec1506[0] = (fTemp684 + (fTemp685 + (fRec1506[1] + fTemp686)));
			fRec1504[0] = fRec1506[0];
			double fRec1505 = ((fTemp686 + fTemp685) + fTemp684);
			fRec1503[0] = (fRec1504[0] + fRec1503[1]);
			fRec1501[0] = fRec1503[0];
			double fRec1502 = fRec1505;
			fRec1500[0] = (fTemp683 + (fRec1502 + fRec1500[1]));
			fRec1498[0] = fRec1500[0];
			double fRec1499 = (fRec1502 + fTemp683);
			double fTemp687 = (fConst157 * (((0.0407218497 * fTemp76) + (0.071420472099999993 * fTemp77)) - (0.070432630699999998 * fTemp78)));
			double fTemp688 = (fConst158 * fRec1507[1]);
			fRec1509[0] = (fTemp687 + (fRec1509[1] + fTemp688));
			fRec1507[0] = fRec1509[0];
			double fRec1508 = (fTemp688 + fTemp687);
			double fTemp689 = (fConst160 * ((((0.067781079499999994 * fTemp82) + (0.024061545 * fTemp85)) + (0.037406373 * fTemp84)) - ((0.069349797699999993 * fTemp81) + (0.12228017099999999 * fTemp83))));
			double fTemp690 = (fConst161 * fRec1510[1]);
			double fTemp691 = (fConst162 * fRec1513[1]);
			fRec1515[0] = (fTemp689 + (fTemp690 + (fRec1515[1] + fTemp691)));
			fRec1513[0] = fRec1515[0];
			double fRec1514 = ((fTemp691 + fTemp690) + fTemp689);
			fRec1512[0] = (fRec1513[0] + fRec1512[1]);
			fRec1510[0] = fRec1512[0];
			double fRec1511 = fRec1514;
			fVec22[(IOTA & 127)] = (((0.0010625246 * fTemp97) + ((0.043045095899999997 * fTemp7) + ((0.018570661400000001 * fTemp11) + ((0.0310612054 * fTemp95) + ((0.047663176500000001 * fTemp89) + ((0.019637951599999998 * fTemp92) + (((0.038020542300000001 * fTemp13) + (fRec1454 + (fRec1472 + (fRec1487 + (fRec1499 + (fRec1508 + fRec1511)))))) + (0.0090084712999999993 * fTemp91)))))))) - (((0.0090734610999999993 * fTemp8) + ((0.028819032299999998 * fTemp9) + (((((0.0040182975000000003 * fTemp90) + (0.049585686099999998 * fTemp93)) + (0.0027275518000000002 * fTemp94)) + (0.0022582491 * fTemp12)) + (0.016044867899999999 * fTemp10)))) + (0.020202592299999999 * fTemp96)));
			output22[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec22[((IOTA - iConst163) & 127)])));
			double fTemp692 = (fConst125 * fRec1516[1]);
			double fTemp693 = (fConst126 * fRec1519[1]);
			double fTemp694 = (fConst128 * fRec1522[1]);
			double fTemp695 = (fConst129 * fRec1525[1]);
			double fTemp696 = (fConst131 * (((0.044581874100000002 * fTemp24) + ((0.039901425599999998 * fTemp23) + ((0.058836390600000003 * fTemp22) + ((0.021711588800000001 * fTemp21) + ((((0.023392970900000001 * fTemp18) + (0.072169944599999994 * fTemp26)) + (0.022082187999999999 * fTemp28)) + (0.035264581000000003 * fTemp20)))))) - ((0.0055388418000000003 * fTemp30) + ((((0.0132177457 * fTemp25) + (0.021960169799999998 * fTemp27)) + (0.071853804399999999 * fTemp19)) + (0.046305671100000001 * fTemp29)))));
			double fTemp697 = (fConst132 * fRec1528[1]);
			double fTemp698 = (fConst133 * fRec1531[1]);
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
			double fTemp699 = (fConst135 * fRec1534[1]);
			double fTemp700 = (fConst137 * fRec1537[1]);
			double fTemp701 = (fConst138 * fRec1540[1]);
			double fTemp702 = (fConst140 * (((0.049614387400000001 * fTemp46) + ((((0.0141639551 * fTemp37) + (0.065139645199999999 * fTemp38)) + (0.022911082900000001 * fTemp41)) + (0.073661101600000001 * fTemp45))) - ((((((0.073071023900000004 * fTemp42) + (0.016199443899999999 * fTemp43)) + (0.098388445399999996 * fTemp39)) + (0.028639465900000001 * fTemp40)) + (0.0073486037999999998 * fTemp44)) + (0.024199353100000001 * fTemp47))));
			double fTemp703 = (fConst141 * fRec1543[1]);
			double fTemp704 = (fConst142 * fRec1546[1]);
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
			double fTemp705 = (fConst144 * fRec1549[1]);
			double fTemp706 = (fConst145 * fRec1552[1]);
			double fTemp707 = (fConst147 * (((0.028772314300000001 * fTemp61) + (((0.034126342599999998 * fTemp53) + (0.0043325257000000001 * fTemp58)) + (0.071074450600000005 * fTemp60))) - (((((0.082256332400000007 * fTemp54) + (0.052302601400000003 * fTemp56)) + (0.036002602299999999 * fTemp57)) + (0.079689907700000007 * fTemp55)) + (0.085746373599999995 * fTemp59))));
			double fTemp708 = (fConst148 * fRec1555[1]);
			double fTemp709 = (fConst149 * fRec1558[1]);
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
			double fTemp710 = (fConst151 * fRec1561[1]);
			double fTemp711 = (fConst153 * (((0.0647337729 * fTemp69) + (0.0382310846 * fTemp72)) - (((((0.0476547056 * fTemp66) + (0.057536119900000002 * fTemp67)) + (0.063280135000000001 * fTemp70)) + (0.019580840400000001 * fTemp71)) + (0.10827217460000001 * fTemp68))));
			double fTemp712 = (fConst154 * fRec1564[1]);
			double fTemp713 = (fConst155 * fRec1567[1]);
			fRec1569[0] = (fTemp711 + (fTemp712 + (fRec1569[1] + fTemp713)));
			fRec1567[0] = fRec1569[0];
			double fRec1568 = ((fTemp713 + fTemp712) + fTemp711);
			fRec1566[0] = (fRec1567[0] + fRec1566[1]);
			fRec1564[0] = fRec1566[0];
			double fRec1565 = fRec1568;
			fRec1563[0] = (fTemp710 + (fRec1565 + fRec1563[1]));
			fRec1561[0] = fRec1563[0];
			double fRec1562 = (fRec1565 + fTemp710);
			double fTemp714 = (fConst157 * (((0.068032778700000004 * fTemp76) + (0.053373362100000002 * fTemp77)) - (0.016565980500000001 * fTemp78)));
			double fTemp715 = (fConst158 * fRec1570[1]);
			fRec1572[0] = (fTemp714 + (fRec1572[1] + fTemp715));
			fRec1570[0] = fRec1572[0];
			double fRec1571 = (fTemp715 + fTemp714);
			double fTemp716 = (fConst160 * (((0.1100449557 * fTemp82) + (0.0055321232 * fTemp85)) - (((0.032314148199999997 * fTemp81) + (0.0281700179 * fTemp83)) + (0.064471198499999993 * fTemp84))));
			double fTemp717 = (fConst161 * fRec1573[1]);
			double fTemp718 = (fConst162 * fRec1576[1]);
			fRec1578[0] = (fTemp716 + (fTemp717 + (fRec1578[1] + fTemp718)));
			fRec1576[0] = fRec1578[0];
			double fRec1577 = ((fTemp718 + fTemp717) + fTemp716);
			fRec1575[0] = (fRec1576[0] + fRec1575[1]);
			fRec1573[0] = fRec1575[0];
			double fRec1574 = fRec1577;
			fVec23[(IOTA & 127)] = (((0.0043127755000000002 * fTemp97) + ((0.014261661700000001 * fTemp8) + ((0.061118446700000002 * fTemp10) + ((0.0059160254999999998 * fTemp11) + ((0.053282586600000001 * fTemp95) + ((0.0020000769999999998 * fTemp12) + ((0.034340739199999998 * fTemp89) + ((0.027382893700000001 * fTemp94) + ((0.0477321406 * fTemp93) + (((0.0306213415 * fTemp13) + (fRec1517 + (fRec1535 + (fRec1550 + (fRec1562 + (fRec1571 + fRec1574)))))) + (0.0186814992 * fTemp92))))))))))) - ((0.0083258150000000003 * fTemp96) + ((((0.0017424923999999999 * fTemp90) + (0.024329822099999999 * fTemp91)) + (0.0039512311 * fTemp9)) + (0.051999526300000001 * fTemp7))));
			output23[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec23[((IOTA - iConst163) & 127)])));
			double fTemp719 = (fConst165 * fRec1579[1]);
			double fTemp720 = (fConst166 * fRec1582[1]);
			double fTemp721 = (fConst168 * fRec1585[1]);
			double fTemp722 = (fConst169 * fRec1588[1]);
			double fTemp723 = (fConst171 * ((((((0.0015313633000000001 * fTemp25) + (0.0013063155999999999 * fTemp26)) + (0.071899315500000005 * fTemp19)) + (0.037116086100000001 * fTemp23)) + (0.0053892753999999999 * fTemp29)) - ((((0.074635780600000007 * fTemp22) + ((0.042380235799999999 * fTemp21) + ((((0.00094315149999999999 * fTemp18) + (0.0216072564 * fTemp27)) + (0.071792914099999994 * fTemp28)) + (0.0475891518 * fTemp20)))) + (0.0014685182999999999 * fTemp24)) + (0.00026841849999999998 * fTemp30))));
			double fTemp724 = (fConst172 * fRec1591[1]);
			double fTemp725 = (fConst173 * fRec1594[1]);
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
			double fTemp726 = (fConst175 * fRec1597[1]);
			double fTemp727 = (fConst177 * fRec1600[1]);
			double fTemp728 = (fConst178 * fRec1603[1]);
			double fTemp729 = (fConst180 * (((((0.00089786689999999997 * fTemp38) + (0.1219692379 * fTemp39)) + (0.028164928200000001 * fTemp45)) + (0.0018380651999999999 * fTemp47)) - (((0.080026943399999995 * fTemp44) + ((0.057334568599999997 * fTemp41) + ((((0.00034342390000000002 * fTemp37) + (0.016898055799999999 * fTemp42)) + (0.071325131999999999 * fTemp43)) + (0.015650774700000002 * fTemp40)))) + (0.0007866444 * fTemp46))));
			double fTemp730 = (fConst181 * fRec1606[1]);
			double fTemp731 = (fConst182 * fRec1609[1]);
			fRec1611[0] = (fTemp729 + (fTemp730 + (fRec1611[1] + fTemp731)));
			fRec1609[0] = fRec1611[0];
			double fRec1610 = ((fTemp731 + fTemp730) + fTemp729);
			fRec1608[0] = (fRec1609[0] + fRec1608[1]);
			fRec1606[0] = fRec1608[0];
			double fRec1607 = fRec1610;
			fRec1605[0] = (fTemp727 + (fTemp728 + (fRec1607 + fRec1605[1])));
			fRec1603[0] = fRec1605[0];
			double fRec1604 = (fTemp727 + (fRec1607 + fTemp728));
			fRec1602[0] = (fRec1603[0] + fRec1602[1]);
			fRec1600[0] = fRec1602[0];
			double fRec1601 = fRec1604;
			fRec1599[0] = (fTemp726 + (fRec1601 + fRec1599[1]));
			fRec1597[0] = fRec1599[0];
			double fRec1598 = (fRec1601 + fTemp726);
			double fTemp732 = (fConst184 * fRec1612[1]);
			double fTemp733 = (fConst185 * fRec1615[1]);
			double fTemp734 = (fConst187 * (((((0.00036988659999999998 * fTemp53) + (0.1489226551 * fTemp57)) + (0.0350328351 * fTemp55)) + (0.016275781199999999 * fTemp60)) - (((0.066697567200000002 * fTemp59) + (((0.0099615417999999994 * fTemp54) + (0.056906549700000003 * fTemp56)) + (0.062940663100000002 * fTemp58))) + (0.00028330519999999999 * fTemp61))));
			double fTemp735 = (fConst188 * fRec1618[1]);
			double fTemp736 = (fConst189 * fRec1621[1]);
			fRec1623[0] = (fTemp734 + (fTemp735 + (fRec1623[1] + fTemp736)));
			fRec1621[0] = fRec1623[0];
			double fRec1622 = ((fTemp736 + fTemp735) + fTemp734);
			fRec1620[0] = (fRec1621[0] + fRec1620[1]);
			fRec1618[0] = fRec1620[0];
			double fRec1619 = fRec1622;
			fRec1617[0] = (fTemp732 + (fTemp733 + (fRec1619 + fRec1617[1])));
			fRec1615[0] = fRec1617[0];
			double fRec1616 = (fTemp732 + (fRec1619 + fTemp733));
			fRec1614[0] = (fRec1615[0] + fRec1614[1]);
			fRec1612[0] = fRec1614[0];
			double fRec1613 = fRec1616;
			double fTemp737 = (fConst191 * fRec1624[1]);
			double fTemp738 = (fConst193 * ((((0.13847193469999999 * fTemp69) + (0.083723758600000003 * fTemp70)) + (0.0062344825999999997 * fTemp72)) - ((((0.0038678001999999999 * fTemp66) + (0.034670622700000001 * fTemp67)) + (0.055250673600000001 * fTemp71)) + (0.041734716800000002 * fTemp68))));
			double fTemp739 = (fConst194 * fRec1627[1]);
			double fTemp740 = (fConst195 * fRec1630[1]);
			fRec1632[0] = (fTemp738 + (fTemp739 + (fRec1632[1] + fTemp740)));
			fRec1630[0] = fRec1632[0];
			double fRec1631 = ((fTemp740 + fTemp739) + fTemp738);
			fRec1629[0] = (fRec1630[0] + fRec1629[1]);
			fRec1627[0] = fRec1629[0];
			double fRec1628 = fRec1631;
			fRec1626[0] = (fTemp737 + (fRec1628 + fRec1626[1]));
			fRec1624[0] = fRec1626[0];
			double fRec1625 = (fRec1628 + fTemp737);
			double fTemp741 = (fConst197 * (((0.039881849099999998 * fTemp76) + (0.088532238999999999 * fTemp77)) - (0.015116001299999999 * fTemp78)));
			double fTemp742 = (fConst198 * fRec1633[1]);
			fRec1635[0] = (fTemp741 + (fRec1635[1] + fTemp742));
			fRec1633[0] = fRec1635[0];
			double fRec1634 = (fTemp742 + fTemp741);
			double fTemp743 = (fConst200 * (((0.094799970499999997 * fTemp82) + (0.10635739380000001 * fTemp85)) - (((0.013823488599999999 * fTemp81) + (0.036598682600000002 * fTemp83)) + (0.016917791000000001 * fTemp84))));
			double fTemp744 = (fConst201 * fRec1636[1]);
			double fTemp745 = (fConst202 * fRec1639[1]);
			fRec1641[0] = (fTemp743 + (fTemp744 + (fRec1641[1] + fTemp745)));
			fRec1639[0] = fRec1641[0];
			double fRec1640 = ((fTemp745 + fTemp744) + fTemp743);
			fRec1638[0] = (fRec1639[0] + fRec1638[1]);
			fRec1636[0] = fRec1638[0];
			double fRec1637 = fRec1640;
			fVec24[0] = (((0.0107613147 * fTemp7) + ((0.038650755799999999 * fTemp9) + ((0.022083609099999998 * fTemp12) + ((0.0010312278000000001 * fTemp93) + (((0.034354885699999997 * fTemp13) + (fRec1580 + (fRec1598 + (fRec1613 + (fRec1625 + (fRec1634 + fRec1637)))))) + (0.0046679911000000003 * fTemp91)))))) - ((0.00051111530000000002 * fTemp97) + (((0.0021115942000000001 * fTemp8) + ((0.0523673162 * fTemp10) + ((0.0254600101 * fTemp11) + (((((0.0003231493 * fTemp90) + (0.0017050991999999999 * fTemp92)) + (0.021421420100000001 * fTemp94)) + (0.0586536774 * fTemp89)) + (0.053051593399999999 * fTemp95))))) + (0.0008531697 * fTemp96))));
			output24[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec24[iConst203])));
			double fTemp746 = (fConst165 * fRec1642[1]);
			double fTemp747 = (fConst166 * fRec1645[1]);
			double fTemp748 = (fConst168 * fRec1648[1]);
			double fTemp749 = (fConst169 * fRec1651[1]);
			double fTemp750 = (fConst171 * ((((0.021522796600000001 * fTemp23) + ((0.074564049800000004 * fTemp22) + (((0.042322893399999999 * fTemp19) + (((0.0012778684000000001 * fTemp26) + (0.037038816600000003 * fTemp27)) + (0.071748967600000005 * fTemp28))) + (0.071927905200000003 * fTemp21)))) + (0.0002700275 * fTemp30)) - ((0.00094608989999999998 * fTemp29) + ((((0.0015253681000000001 * fTemp25) + (0.0053798242999999997 * fTemp18)) + (0.0476347217 * fTemp20)) + (0.0014928806 * fTemp24)))));
			double fTemp751 = (fConst172 * fRec1654[1]);
			double fTemp752 = (fConst173 * fRec1657[1]);
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
			double fTemp753 = (fConst175 * fRec1660[1]);
			double fTemp754 = (fConst177 * fRec1663[1]);
			double fTemp755 = (fConst178 * fRec1666[1]);
			double fTemp756 = (fConst180 * (((0.0168388667 * fTemp45) + ((0.079959720799999995 * fTemp44) + (((((0.00088688120000000002 * fTemp38) + (0.028111043799999999 * fTemp42)) + (0.071284875299999995 * fTemp43)) + (0.057299954799999997 * fTemp39)) + (0.1220212334 * fTemp41)))) - ((0.00034429980000000001 * fTemp47) + (((0.0018336099 * fTemp37) + (0.015664354500000002 * fTemp40)) + (0.0007991993 * fTemp46)))));
			double fTemp757 = (fConst181 * fRec1669[1]);
			double fTemp758 = (fConst182 * fRec1672[1]);
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
			double fTemp759 = (fConst184 * fRec1675[1]);
			double fTemp760 = (fConst185 * fRec1678[1]);
			double fTemp761 = (fConst187 * (((((((((0.0003674145 * fTemp53) + (0.0162470501 * fTemp54)) + (0.056873225600000001 * fTemp56)) + (0.062919761599999999 * fTemp57)) + (0.035059241200000001 * fTemp55)) + (0.14897413879999999 * fTemp58)) + (0.0666431309 * fTemp59)) + (0.0099293989000000006 * fTemp60)) - (0.00028756579999999999 * fTemp61)));
			double fTemp762 = (fConst188 * fRec1681[1]);
			double fTemp763 = (fConst189 * fRec1684[1]);
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
			double fTemp764 = (fConst191 * fRec1687[1]);
			double fTemp765 = (fConst193 * (((((((0.0062242631999999999 * fTemp66) + (0.034648934300000003 * fTemp67)) + (0.055236739799999997 * fTemp69)) + (0.083775584400000006 * fTemp70)) + (0.13850598359999999 * fTemp71)) + (0.041700136399999997 * fTemp68)) + (0.0038560680999999999 * fTemp72)));
			double fTemp766 = (fConst194 * fRec1690[1]);
			double fTemp767 = (fConst195 * fRec1693[1]);
			fRec1695[0] = (fTemp765 + (fTemp766 + (fRec1695[1] + fTemp767)));
			fRec1693[0] = fRec1695[0];
			double fRec1694 = ((fTemp767 + fTemp766) + fTemp765);
			fRec1692[0] = (fRec1693[0] + fRec1692[1]);
			fRec1690[0] = fRec1692[0];
			double fRec1691 = fRec1694;
			fRec1689[0] = (fTemp764 + (fRec1691 + fRec1689[1]));
			fRec1687[0] = fRec1689[0];
			double fRec1688 = (fRec1691 + fTemp764);
			double fTemp768 = (fConst197 * (((0.015112081600000001 * fTemp76) + (0.088570217199999995 * fTemp77)) + (0.039885551200000001 * fTemp78)));
			double fTemp769 = (fConst198 * fRec1696[1]);
			fRec1698[0] = (fTemp768 + (fRec1698[1] + fTemp769));
			fRec1696[0] = fRec1698[0];
			double fRec1697 = (fTemp769 + fTemp768);
			double fTemp770 = (fConst200 * (((((0.0138143112 * fTemp81) + (0.036589704399999999 * fTemp82)) + (0.106411387 * fTemp85)) + (0.094814867900000002 * fTemp83)) + (0.0169033884 * fTemp84)));
			double fTemp771 = (fConst201 * fRec1699[1]);
			double fTemp772 = (fConst202 * fRec1702[1]);
			fRec1704[0] = (fTemp770 + (fTemp771 + (fRec1704[1] + fTemp772)));
			fRec1702[0] = fRec1704[0];
			double fRec1703 = ((fTemp772 + fTemp771) + fTemp770);
			fRec1701[0] = (fRec1702[0] + fRec1701[1]);
			fRec1699[0] = fRec1701[0];
			double fRec1700 = fRec1703;
			fVec25[0] = (((0.00032829039999999999 * fTemp97) + ((0.00085618119999999998 * fTemp96) + ((0.021323585700000001 * fTemp9) + ((0.052295665800000002 * fTemp10) + ((0.0220768927 * fTemp11) + ((0.0253763919 * fTemp12) + ((0.058603265100000003 * fTemp89) + ((0.038562451599999999 * fTemp94) + (((0.034368230399999998 * fTemp13) + (fRec1643 + (fRec1661 + (fRec1676 + (fRec1688 + (fRec1697 + fRec1700)))))) + (0.0009799543 * fTemp93)))))))))) - ((0.0017109121 * fTemp7) + (((((0.00050549419999999996 * fTemp90) + (0.0046514049999999999 * fTemp91)) + (0.0107495083 * fTemp92)) + (0.053098159499999999 * fTemp95)) + (0.0021465634999999999 * fTemp8))));
			output25[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec25[iConst203])));
			double fTemp773 = (fConst165 * fRec1705[1]);
			double fTemp774 = (fConst166 * fRec1708[1]);
			double fTemp775 = (fConst168 * fRec1711[1]);
			double fTemp776 = (fConst169 * fRec1714[1]);
			double fTemp777 = (fConst171 * ((((((0.0015219953 * fTemp25) + (0.00095165600000000005 * fTemp18)) + (0.0013762603999999999 * fTemp26)) + (0.021580580799999999 * fTemp27)) + (0.042258923300000001 * fTemp21)) - ((0.00025761179999999999 * fTemp30) + ((0.0053294019999999996 * fTemp29) + ((0.0014357327999999999 * fTemp24) + ((0.037118971799999997 * fTemp23) + (((0.047575907700000003 * fTemp20) + ((0.071798333500000006 * fTemp28) + (0.071958571200000002 * fTemp19))) + (0.0745752742 * fTemp22))))))));
			double fTemp778 = (fConst172 * fRec1717[1]);
			double fTemp779 = (fConst173 * fRec1720[1]);
			fRec1722[0] = (fTemp777 + (fTemp778 + (fRec1722[1] + fTemp779)));
			fRec1720[0] = fRec1722[0];
			double fRec1721 = ((fTemp779 + fTemp778) + fTemp777);
			fRec1719[0] = (fRec1720[0] + fRec1719[1]);
			fRec1717[0] = fRec1719[0];
			double fRec1718 = fRec1721;
			fRec1716[0] = (fTemp775 + (fTemp776 + (fRec1718 + fRec1716[1])));
			fRec1714[0] = fRec1716[0];
			double fRec1715 = (fTemp775 + (fRec1718 + fTemp776));
			fRec1713[0] = (fRec1714[0] + fRec1713[1]);
			fRec1711[0] = fRec1713[0];
			double fRec1712 = fRec1715;
			fRec1710[0] = (fTemp773 + (fTemp774 + (fRec1712 + fRec1710[1])));
			fRec1708[0] = fRec1710[0];
			double fRec1709 = (fTemp773 + (fRec1712 + fTemp774));
			fRec1707[0] = (fRec1708[0] + fRec1707[1]);
			fRec1705[0] = fRec1707[0];
			double fRec1706 = fRec1709;
			double fTemp780 = (fConst175 * fRec1723[1]);
			double fTemp781 = (fConst177 * fRec1726[1]);
			double fTemp782 = (fConst178 * fRec1729[1]);
			double fTemp783 = (fConst180 * (((((0.00034784239999999998 * fTemp37) + (0.00095683870000000002 * fTemp38)) + (0.016911639400000001 * fTemp42)) + (0.057250342000000003 * fTemp41)) - ((0.0018129146999999999 * fTemp47) + ((0.0007648927 * fTemp46) + ((0.0281986283 * fTemp45) + ((((0.071343861199999997 * fTemp43) + (0.1220141159 * fTemp39)) + (0.0156424137 * fTemp40)) + (0.0799987796 * fTemp44)))))));
			double fTemp784 = (fConst181 * fRec1732[1]);
			double fTemp785 = (fConst182 * fRec1735[1]);
			fRec1737[0] = (fTemp783 + (fTemp784 + (fRec1737[1] + fTemp785)));
			fRec1735[0] = fRec1737[0];
			double fRec1736 = ((fTemp785 + fTemp784) + fTemp783);
			fRec1734[0] = (fRec1735[0] + fRec1734[1]);
			fRec1732[0] = fRec1734[0];
			double fRec1733 = fRec1736;
			fRec1731[0] = (fTemp781 + (fTemp782 + (fRec1733 + fRec1731[1])));
			fRec1729[0] = fRec1731[0];
			double fRec1730 = (fTemp781 + (fRec1733 + fTemp782));
			fRec1728[0] = (fRec1729[0] + fRec1728[1]);
			fRec1726[0] = fRec1728[0];
			double fRec1727 = fRec1730;
			fRec1725[0] = (fTemp780 + (fRec1727 + fRec1725[1]));
			fRec1723[0] = fRec1725[0];
			double fRec1724 = (fRec1727 + fTemp780);
			double fTemp786 = (fConst184 * fRec1738[1]);
			double fTemp787 = (fConst185 * fRec1741[1]);
			double fTemp788 = (fConst187 * (((0.062888960399999999 * fTemp58) + (((0.00039784089999999998 * fTemp53) + (0.0099851135000000001 * fTemp54)) + (0.035041661100000003 * fTemp55))) - ((0.00027412310000000001 * fTemp61) + ((0.016311194099999999 * fTemp60) + (((0.0569313709 * fTemp56) + (0.14896404229999999 * fTemp57)) + (0.066701710999999997 * fTemp59))))));
			double fTemp789 = (fConst188 * fRec1744[1]);
			double fTemp790 = (fConst189 * fRec1747[1]);
			fRec1749[0] = (fTemp788 + (fTemp789 + (fRec1749[1] + fTemp790)));
			fRec1747[0] = fRec1749[0];
			double fRec1748 = ((fTemp790 + fTemp789) + fTemp788);
			fRec1746[0] = (fRec1747[0] + fRec1746[1]);
			fRec1744[0] = fRec1746[0];
			double fRec1745 = fRec1748;
			fRec1743[0] = (fTemp786 + (fTemp787 + (fRec1745 + fRec1743[1])));
			fRec1741[0] = fRec1743[0];
			double fRec1742 = (fTemp786 + (fRec1745 + fTemp787));
			fRec1740[0] = (fRec1741[0] + fRec1740[1]);
			fRec1738[0] = fRec1740[0];
			double fRec1739 = fRec1742;
			double fTemp791 = (fConst191 * fRec1750[1]);
			double fTemp792 = (fConst193 * ((((0.0038815699 * fTemp66) + (0.083737399099999998 * fTemp70)) + (0.055223153599999998 * fTemp71)) - ((0.0062531050000000001 * fTemp72) + (((0.034691040700000002 * fTemp67) + (0.13851131250000001 * fTemp69)) + (0.041751650299999998 * fTemp68)))));
			double fTemp793 = (fConst194 * fRec1753[1]);
			double fTemp794 = (fConst195 * fRec1756[1]);
			fRec1758[0] = (fTemp792 + (fTemp793 + (fRec1758[1] + fTemp794)));
			fRec1756[0] = fRec1758[0];
			double fRec1757 = ((fTemp794 + fTemp793) + fTemp792);
			fRec1755[0] = (fRec1756[0] + fRec1755[1]);
			fRec1753[0] = fRec1755[0];
			double fRec1754 = fRec1757;
			fRec1752[0] = (fTemp791 + (fRec1754 + fRec1752[1]));
			fRec1750[0] = fRec1752[0];
			double fRec1751 = (fRec1754 + fTemp791);
			double fTemp795 = (fConst197 * (((0.088548185599999996 * fTemp77) + (0.0151123496 * fTemp78)) - (0.039895589600000003 * fTemp76)));
			double fTemp796 = (fConst198 * fRec1759[1]);
			fRec1761[0] = (fTemp795 + (fRec1761[1] + fTemp796));
			fRec1759[0] = fRec1761[0];
			double fRec1760 = (fTemp796 + fTemp795);
			double fTemp797 = (fConst200 * (((0.10637524499999999 * fTemp85) + (0.036586640400000002 * fTemp83)) - (((0.0138333298 * fTemp81) + (0.094829860399999993 * fTemp82)) + (0.0169290993 * fTemp84))));
			double fTemp798 = (fConst201 * fRec1762[1]);
			double fTemp799 = (fConst202 * fRec1765[1]);
			fRec1767[0] = (fTemp797 + (fTemp798 + (fRec1767[1] + fTemp799)));
			fRec1765[0] = fRec1767[0];
			double fRec1766 = ((fTemp799 + fTemp798) + fTemp797);
			fRec1764[0] = (fRec1765[0] + fRec1764[1]);
			fRec1762[0] = fRec1764[0];
			double fRec1763 = fRec1766;
			fVec26[0] = (((0.00051645700000000001 * fTemp97) + ((0.025305222299999999 * fTemp11) + ((0.021334878200000001 * fTemp94) + ((0.0010679193 * fTemp93) + ((0.0017114617999999999 * fTemp92) + ((0.0046429573999999998 * fTemp91) + ((0.00031931519999999999 * fTemp90) + ((0.034361336499999999 * fTemp13) + (fRec1706 + (fRec1724 + (fRec1739 + (fRec1751 + (fRec1760 + fRec1763))))))))))))) - ((0.00082550069999999998 * fTemp96) + ((0.0106728164 * fTemp7) + ((0.0020763011 * fTemp8) + ((0.038606718399999997 * fTemp9) + (((0.053030549599999997 * fTemp95) + ((0.058645916399999998 * fTemp89) + (0.022167124199999999 * fTemp12))) + (0.052302689399999998 * fTemp10)))))));
			output26[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec26[iConst203])));
			double fTemp800 = (fConst165 * fRec1768[1]);
			double fTemp801 = (fConst166 * fRec1771[1]);
			double fTemp802 = (fConst168 * fRec1774[1]);
			double fTemp803 = (fConst169 * fRec1777[1]);
			double fTemp804 = (fConst171 * (((0.00026279560000000001 * fTemp30) + (((((0.0053785428000000003 * fTemp18) + (0.0012941545 * fTemp26)) + (0.071789134399999996 * fTemp28)) + (0.074604449599999997 * fTemp22)) + (0.00096254070000000003 * fTemp29))) - ((0.0015045161 * fTemp24) + (((0.071920919299999997 * fTemp21) + ((0.047614389999999999 * fTemp20) + (((0.0015278881000000001 * fTemp25) + (0.037073559700000001 * fTemp27)) + (0.042353747999999997 * fTemp19)))) + (0.021541909800000002 * fTemp23)))));
			double fTemp805 = (fConst172 * fRec1780[1]);
			double fTemp806 = (fConst173 * fRec1783[1]);
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
			double fTemp807 = (fConst175 * fRec1786[1]);
			double fTemp808 = (fConst177 * fRec1789[1]);
			double fTemp809 = (fConst178 * fRec1792[1]);
			double fTemp810 = (fConst180 * ((((((0.0018331738000000001 * fTemp37) + (0.00089944120000000002 * fTemp38)) + (0.071334030600000001 * fTemp43)) + (0.079994080300000006 * fTemp44)) + (0.00035212850000000001 * fTemp47)) - ((0.00081297539999999999 * fTemp46) + (((0.122013476 * fTemp41) + (((0.0281500428 * fTemp42) + (0.057324708100000003 * fTemp39)) + (0.0156685313 * fTemp40))) + (0.016842529299999999 * fTemp45)))));
			double fTemp811 = (fConst181 * fRec1795[1]);
			double fTemp812 = (fConst182 * fRec1798[1]);
			fRec1800[0] = (fTemp810 + (fTemp811 + (fRec1800[1] + fTemp812)));
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
			double fTemp813 = (fConst184 * fRec1801[1]);
			double fTemp814 = (fConst185 * fRec1804[1]);
			double fTemp815 = (fConst187 * (((((0.00037305740000000002 * fTemp53) + (0.056925988300000001 * fTemp56)) + (0.035041152300000003 * fTemp55)) + (0.066669185399999997 * fTemp59)) - ((0.00029503379999999999 * fTemp61) + ((((0.0162765489 * fTemp54) + (0.062950191899999994 * fTemp57)) + (0.1489803931 * fTemp58)) + (0.0099259281000000001 * fTemp60)))));
			double fTemp816 = (fConst188 * fRec1807[1]);
			double fTemp817 = (fConst189 * fRec1810[1]);
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
			double fTemp818 = (fConst191 * fRec1813[1]);
			double fTemp819 = (fConst193 * ((((0.034689685300000002 * fTemp67) + (0.083761760599999999 * fTemp70)) + (0.0417159904 * fTemp68)) - ((((0.0062378497 * fTemp66) + (0.0552722961 * fTemp69)) + (0.13852682529999999 * fTemp71)) + (0.0038529318999999999 * fTemp72))));
			double fTemp820 = (fConst194 * fRec1816[1]);
			double fTemp821 = (fConst195 * fRec1819[1]);
			fRec1821[0] = (fTemp819 + (fTemp820 + (fRec1821[1] + fTemp821)));
			fRec1819[0] = fRec1821[0];
			double fRec1820 = ((fTemp821 + fTemp820) + fTemp819);
			fRec1818[0] = (fRec1819[0] + fRec1818[1]);
			fRec1816[0] = fRec1818[0];
			double fRec1817 = fRec1820;
			fRec1815[0] = (fTemp818 + (fRec1817 + fRec1815[1]));
			fRec1813[0] = fRec1815[0];
			double fRec1814 = (fRec1817 + fTemp818);
			double fTemp822 = (fConst197 * ((0.088579545900000001 * fTemp77) - ((0.015126289899999999 * fTemp76) + (0.0398976973 * fTemp78))));
			double fTemp823 = (fConst198 * fRec1822[1]);
			fRec1824[0] = (fTemp822 + (fRec1824[1] + fTemp823));
			fRec1822[0] = fRec1824[0];
			double fRec1823 = (fTemp823 + fTemp822);
			double fTemp824 = (fConst200 * ((((0.0138334818 * fTemp81) + (0.10641176920000001 * fTemp85)) + (0.016909811800000001 * fTemp84)) - ((0.036619387000000003 * fTemp82) + (0.0948377101 * fTemp83))));
			double fTemp825 = (fConst201 * fRec1825[1]);
			double fTemp826 = (fConst202 * fRec1828[1]);
			fRec1830[0] = (fTemp824 + (fTemp825 + (fRec1830[1] + fTemp826)));
			fRec1828[0] = fRec1830[0];
			double fRec1829 = ((fTemp826 + fTemp825) + fTemp824);
			fRec1827[0] = (fRec1828[0] + fRec1827[1]);
			fRec1825[0] = fRec1827[0];
			double fRec1826 = fRec1829;
			fVec27[0] = (((0.00083903600000000004 * fTemp96) + ((0.0017302127999999999 * fTemp7) + ((0.052341656799999997 * fTemp10) + ((0.058648183200000002 * fTemp89) + ((0.00099093079999999995 * fTemp93) + ((0.0107476759 * fTemp92) + ((0.00051052879999999995 * fTemp90) + ((0.034373545499999998 * fTemp13) + (fRec1769 + (fRec1787 + (fRec1802 + (fRec1814 + (fRec1823 + fRec1826))))))))))))) - (((0.0021428520000000002 * fTemp8) + (((0.022086618799999999 * fTemp11) + ((0.053060559100000002 * fTemp95) + (((0.0046575846000000004 * fTemp91) + (0.038584060500000003 * fTemp94)) + (0.025426749700000001 * fTemp12)))) + (0.0213596151 * fTemp9))) + (0.00032171400000000002 * fTemp97)));
			output27[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec27[iConst203])));
			double fTemp827 = (fConst205 * fRec1831[1]);
			double fTemp828 = (fConst206 * fRec1834[1]);
			double fTemp829 = (fConst208 * fRec1837[1]);
			double fTemp830 = (fConst209 * fRec1840[1]);
			double fTemp831 = (fConst211 * (((2.05631e-05 * fTemp23) + (((0.1077178359 * fTemp20) + ((0.0001357823 * fTemp19) + ((((5.2899999999999997e-08 * fTemp25) + (0.00030485640000000002 * fTemp26)) + (3.7452900000000002e-05 * fTemp27)) + (1.06448e-05 * fTemp28)))) + (8.5221200000000003e-05 * fTemp22))) - ((8.1899999999999999e-08 * fTemp30) + ((1.924e-07 * fTemp29) + (((8.2330000000000002e-07 * fTemp18) + (5.5377799999999997e-05 * fTemp21)) + (0.00015868910000000001 * fTemp24))))));
			double fTemp832 = (fConst212 * fRec1843[1]);
			double fTemp833 = (fConst213 * fRec1846[1]);
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
			double fTemp834 = (fConst215 * fRec1849[1]);
			double fTemp835 = (fConst217 * fRec1852[1]);
			double fTemp836 = (fConst218 * fRec1855[1]);
			double fTemp837 = (fConst220 * (((1.1270900000000001e-05 * fTemp45) + (((0.10068073399999999 * fTemp40) + ((((0.0001214182 * fTemp38) + (1.9471599999999998e-05 * fTemp42)) + (8.6204999999999999e-06 * fTemp43)) + (0.0001178428 * fTemp39))) + (5.6403400000000003e-05 * fTemp44))) - ((5.3099999999999999e-08 * fTemp47) + (((2.251e-07 * fTemp37) + (5.1301400000000003e-05 * fTemp41)) + (6.3188799999999994e-05 * fTemp46)))));
			double fTemp838 = (fConst221 * fRec1858[1]);
			double fTemp839 = (fConst222 * fRec1861[1]);
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
			double fTemp840 = (fConst224 * fRec1864[1]);
			double fTemp841 = (fConst225 * fRec1867[1]);
			double fTemp842 = (fConst227 * (((5.0616e-06 * fTemp60) + ((((((3.4548999999999997e-05 * fTemp53) + (8.3846999999999995e-06 * fTemp54)) + (5.7409999999999998e-06 * fTemp56)) + (9.1636600000000003e-05 * fTemp57)) + (0.089343940799999993 * fTemp55)) + (3.2799000000000002e-05 * fTemp59))) - ((4.1664600000000001e-05 * fTemp58) + (1.7976900000000001e-05 * fTemp61))));
			double fTemp843 = (fConst228 * fRec1870[1]);
			double fTemp844 = (fConst229 * fRec1873[1]);
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
			double fTemp845 = (fConst231 * fRec1876[1]);
			double fTemp846 = (fConst233 * (((1.6007e-06 * fTemp72) + (((((2.5671e-06 * fTemp66) + (3.0189999999999998e-06 * fTemp67)) + (6.2012000000000002e-05 * fTemp69)) + (0.074076867699999993 * fTemp70)) + (1.5710999999999999e-05 * fTemp68))) - (2.9040600000000001e-05 * fTemp71)));
			double fTemp847 = (fConst234 * fRec1879[1]);
			double fTemp848 = (fConst235 * fRec1882[1]);
			fRec1884[0] = (fTemp846 + (fTemp847 + (fRec1884[1] + fTemp848)));
			fRec1882[0] = fRec1884[0];
			double fRec1883 = ((fTemp848 + fTemp847) + fTemp846);
			fRec1881[0] = (fRec1882[0] + fRec1881[1]);
			fRec1879[0] = fRec1881[0];
			double fRec1880 = fRec1883;
			fRec1878[0] = (fTemp845 + (fRec1880 + fRec1878[1]));
			fRec1876[0] = fRec1878[0];
			double fRec1877 = (fRec1880 + fTemp845);
			double fTemp849 = (fConst237 * (((1.24741e-05 * fTemp76) + (0.034345824400000002 * fTemp77)) - (6.0310999999999997e-06 * fTemp78)));
			double fTemp850 = (fConst238 * fRec1885[1]);
			fRec1887[0] = (fTemp849 + (fRec1887[1] + fTemp850));
			fRec1885[0] = fRec1887[0];
			double fRec1886 = (fTemp850 + fTemp849);
			double fTemp851 = (fConst240 * (((((1.0774000000000001e-06 * fTemp81) + (3.4079899999999999e-05 * fTemp82)) + (0.055478496199999998 * fTemp85)) + (5.2643999999999999e-06 * fTemp84)) - (1.6277899999999999e-05 * fTemp83)));
			double fTemp852 = (fConst241 * fRec1888[1]);
			double fTemp853 = (fConst242 * fRec1891[1]);
			fRec1893[0] = (fTemp851 + (fTemp852 + (fRec1893[1] + fTemp853)));
			fRec1891[0] = fRec1893[0];
			double fRec1892 = ((fTemp853 + fTemp852) + fTemp851);
			fRec1890[0] = (fRec1891[0] + fRec1890[1]);
			fRec1888[0] = fRec1890[0];
			double fRec1889 = fRec1892;
			output28[i] = FAUSTFLOAT((fRec0[0] * (((3.2643900000000001e-05 * fTemp9) + ((0.0001168735 * fTemp10) + ((0.1103310052 * fTemp95) + ((0.00014157850000000001 * fTemp12) + ((1.0553100000000001e-05 * fTemp89) + ((6.3477699999999997e-05 * fTemp94) + ((0.00063428699999999998 * fTemp93) + ((2.114e-07 * fTemp91) + ((1.2299999999999999e-08 * fTemp90) + ((0.011628344800000001 * fTemp13) + (fRec1832 + (fRec1850 + (fRec1865 + (fRec1877 + (fRec1886 + fRec1889))))))))))))))) - ((4.3000000000000001e-08 * fTemp97) + ((3.1969999999999998e-07 * fTemp96) + ((4.9539999999999995e-07 * fTemp7) + (((2.1436000000000001e-06 * fTemp92) + (5.2036800000000003e-05 * fTemp11)) + (0.00033026079999999997 * fTemp8))))))));
			double fTemp854 = (fConst244 * fRec1894[1]);
			double fTemp855 = (fConst245 * fRec1897[1]);
			double fTemp856 = (fConst247 * fRec1900[1]);
			double fTemp857 = (fConst248 * fRec1903[1]);
			double fTemp858 = (fConst250 * (((((((0.039643094400000002 * fTemp18) + (0.0078331896000000002 * fTemp26)) + (0.0097967518999999992 * fTemp27)) + (0.015668687399999999 * fTemp28)) + (0.0021496719 * fTemp22)) + (0.092067115699999993 * fTemp29)) - (((0.023454025199999999 * fTemp24) + (((0.020034188200000001 * fTemp21) + ((0.0079192962000000002 * fTemp20) + ((0.097452315400000003 * fTemp25) + (0.017138398499999999 * fTemp19)))) + (0.0059855118000000001 * fTemp23))) + (0.046318673900000003 * fTemp30))));
			double fTemp859 = (fConst251 * fRec1906[1]);
			double fTemp860 = (fConst252 * fRec1909[1]);
			fRec1911[0] = (fTemp858 + (fTemp859 + (fRec1911[1] + fTemp860)));
			fRec1909[0] = fRec1911[0];
			double fRec1910 = ((fTemp860 + fTemp859) + fTemp858);
			fRec1908[0] = (fRec1909[0] + fRec1908[1]);
			fRec1906[0] = fRec1908[0];
			double fRec1907 = fRec1910;
			fRec1905[0] = (fTemp856 + (fTemp857 + (fRec1907 + fRec1905[1])));
			fRec1903[0] = fRec1905[0];
			double fRec1904 = (fTemp856 + (fRec1907 + fTemp857));
			fRec1902[0] = (fRec1903[0] + fRec1902[1]);
			fRec1900[0] = fRec1902[0];
			double fRec1901 = fRec1904;
			fRec1899[0] = (fTemp854 + (fTemp855 + (fRec1901 + fRec1899[1])));
			fRec1897[0] = fRec1899[0];
			double fRec1898 = (fTemp854 + (fRec1901 + fTemp855));
			fRec1896[0] = (fRec1897[0] + fRec1896[1]);
			fRec1894[0] = fRec1896[0];
			double fRec1895 = fRec1898;
			double fTemp861 = (fConst254 * fRec1912[1]);
			double fTemp862 = (fConst256 * fRec1915[1]);
			double fTemp863 = (fConst257 * fRec1918[1]);
			double fTemp864 = (fConst259 * ((((0.0040314490000000003 * fTemp44) + ((((0.015567741600000001 * fTemp42) + (0.026006108999999999 * fTemp43)) + (0.0051470624000000001 * fTemp39)) + (0.0058263137000000003 * fTemp41))) + (0.10123748809999999 * fTemp46)) - (((((0.0467226798 * fTemp37) + (0.031686988200000002 * fTemp38)) + (0.0209533527 * fTemp40)) + (0.0093053256000000008 * fTemp45)) + (0.10626197969999999 * fTemp47))));
			double fTemp865 = (fConst260 * fRec1921[1]);
			double fTemp866 = (fConst261 * fRec1924[1]);
			fRec1926[0] = (fTemp864 + (fTemp865 + (fRec1926[1] + fTemp866)));
			fRec1924[0] = fRec1926[0];
			double fRec1925 = ((fTemp866 + fTemp865) + fTemp864);
			fRec1923[0] = (fRec1924[0] + fRec1923[1]);
			fRec1921[0] = fRec1923[0];
			double fRec1922 = fRec1925;
			fRec1920[0] = (fTemp862 + (fTemp863 + (fRec1922 + fRec1920[1])));
			fRec1918[0] = fRec1920[0];
			double fRec1919 = (fTemp862 + (fRec1922 + fTemp863));
			fRec1917[0] = (fRec1918[0] + fRec1917[1]);
			fRec1915[0] = fRec1917[0];
			double fRec1916 = fRec1919;
			fRec1914[0] = (fTemp861 + (fRec1916 + fRec1914[1]));
			fRec1912[0] = fRec1914[0];
			double fRec1913 = (fRec1916 + fTemp861);
			double fTemp867 = (fConst263 * fRec1927[1]);
			double fTemp868 = (fConst264 * fRec1930[1]);
			double fTemp869 = (fConst266 * (((0.056047287799999998 * fTemp60) + ((0.0011899018 * fTemp59) + ((0.033416372399999998 * fTemp58) + ((((0.035044664400000002 * fTemp53) + (0.0063303526000000002 * fTemp56)) + (0.028673619800000001 * fTemp57)) + (0.0019360950000000001 * fTemp55))))) - ((0.0898425313 * fTemp54) + (0.1141657034 * fTemp61))));
			double fTemp870 = (fConst267 * fRec1933[1]);
			double fTemp871 = (fConst268 * fRec1936[1]);
			fRec1938[0] = (fTemp869 + (fTemp870 + (fRec1938[1] + fTemp871)));
			fRec1936[0] = fRec1938[0];
			double fRec1937 = ((fTemp871 + fTemp870) + fTemp869);
			fRec1935[0] = (fRec1936[0] + fRec1935[1]);
			fRec1933[0] = fRec1935[0];
			double fRec1934 = fRec1937;
			fRec1932[0] = (fTemp867 + (fTemp868 + (fRec1934 + fRec1932[1])));
			fRec1930[0] = fRec1932[0];
			double fRec1931 = (fTemp867 + (fRec1934 + fTemp868));
			fRec1929[0] = (fRec1930[0] + fRec1929[1]);
			fRec1927[0] = fRec1929[0];
			double fRec1928 = fRec1931;
			double fTemp872 = (fConst270 * fRec1939[1]);
			double fTemp873 = (fConst272 * (((0.098709739399999996 * fTemp66) + (0.045077498299999998 * fTemp70)) - ((0.0620865798 * fTemp72) + ((((0.097178974400000007 * fTemp67) + (0.0074881662000000002 * fTemp69)) + (0.0085648378000000008 * fTemp71)) + (0.014866345499999999 * fTemp68)))));
			double fTemp874 = (fConst273 * fRec1942[1]);
			double fTemp875 = (fConst274 * fRec1945[1]);
			fRec1947[0] = (fTemp873 + (fTemp874 + (fRec1947[1] + fTemp875)));
			fRec1945[0] = fRec1947[0];
			double fRec1946 = ((fTemp875 + fTemp874) + fTemp873);
			fRec1944[0] = (fRec1945[0] + fRec1944[1]);
			fRec1942[0] = fRec1944[0];
			double fRec1943 = fRec1946;
			fRec1941[0] = (fTemp872 + (fRec1943 + fRec1941[1]));
			fRec1939[0] = fRec1941[0];
			double fRec1940 = (fRec1943 + fTemp872);
			double fTemp876 = (fConst276 * (((0.0555503148 * fTemp76) + (0.064570036499999997 * fTemp78)) - (0.038110248700000002 * fTemp77)));
			double fTemp877 = (fConst277 * fRec1948[1]);
			fRec1950[0] = (fTemp876 + (fRec1950[1] + fTemp877));
			fRec1948[0] = fRec1950[0];
			double fRec1949 = (fTemp877 + fTemp876);
			double fTemp878 = (fConst279 * (((0.1048690719 * fTemp81) + (0.015807961499999999 * fTemp84)) - (((0.0532736038 * fTemp82) + (0.026508827299999999 * fTemp85)) + (0.062044658400000001 * fTemp83))));
			double fTemp879 = (fConst280 * fRec1951[1]);
			double fTemp880 = (fConst281 * fRec1954[1]);
			fRec1956[0] = (fTemp878 + (fTemp879 + (fRec1956[1] + fTemp880)));
			fRec1954[0] = fRec1956[0];
			double fRec1955 = ((fTemp880 + fTemp879) + fTemp878);
			fRec1953[0] = (fRec1954[0] + fRec1953[1]);
			fRec1951[0] = fRec1953[0];
			double fRec1952 = fRec1955;
			fVec28[(IOTA & 511)] = (((0.025659892399999999 * fTemp97) + ((0.039341306299999997 * fTemp96) + ((0.0002258281 * fTemp8) + ((0.0163014288 * fTemp95) + ((0.019752794800000001 * fTemp94) + ((0.0001048872 * fTemp93) + (((0.033283181699999997 * fTemp13) + (fRec1895 + (fRec1913 + (fRec1928 + (fRec1940 + (fRec1949 + fRec1952)))))) + (0.0806440254 * fTemp91)))))))) - (((0.0127894459 * fTemp9) + ((0.0041442042000000004 * fTemp10) + (((0.0065143670000000001 * fTemp12) + (((0.092632052699999995 * fTemp90) + (0.0101492426 * fTemp92)) + (0.0264451336 * fTemp89))) + (0.0073637879999999996 * fTemp11)))) + (0.025039777799999999 * fTemp7)));
			output29[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec28[((IOTA - iConst282) & 511)])));
			double fTemp881 = (fConst284 * fRec1957[1]);
			double fTemp882 = (fConst285 * fRec1960[1]);
			double fTemp883 = (fConst287 * fRec1963[1]);
			double fTemp884 = (fConst288 * fRec1966[1]);
			double fTemp885 = (fConst290 * (((0.0028406694999999998 * fTemp29) + ((0.0074699147 * fTemp24) + ((0.0066133323999999997 * fTemp23) + (((((0.1011671899 * fTemp25) + (0.023620340900000002 * fTemp26)) + (0.0094267946999999994 * fTemp27)) + (0.0095349990000000006 * fTemp28)) + (0.0124823256 * fTemp22))))) - (((0.025001201099999999 * fTemp21) + ((0.0078491028000000004 * fTemp20) + ((0.1002355296 * fTemp18) + (0.0083012778999999991 * fTemp19)))) + (0.03743958 * fTemp30))));
			double fTemp886 = (fConst291 * fRec1969[1]);
			double fTemp887 = (fConst292 * fRec1972[1]);
			fRec1974[0] = (fTemp885 + (fTemp886 + (fRec1974[1] + fTemp887)));
			fRec1972[0] = fRec1974[0];
			double fRec1973 = ((fTemp887 + fTemp886) + fTemp885);
			fRec1971[0] = (fRec1972[0] + fRec1971[1]);
			fRec1969[0] = fRec1971[0];
			double fRec1970 = fRec1973;
			fRec1968[0] = (fTemp883 + (fTemp884 + (fRec1970 + fRec1968[1])));
			fRec1966[0] = fRec1968[0];
			double fRec1967 = (fTemp883 + (fRec1970 + fTemp884));
			fRec1965[0] = (fRec1966[0] + fRec1965[1]);
			fRec1963[0] = fRec1965[0];
			double fRec1964 = fRec1967;
			fRec1962[0] = (fTemp881 + (fTemp882 + (fRec1964 + fRec1962[1])));
			fRec1960[0] = fRec1962[0];
			double fRec1961 = (fTemp881 + (fRec1964 + fTemp882));
			fRec1959[0] = (fRec1960[0] + fRec1959[1]);
			fRec1957[0] = fRec1959[0];
			double fRec1958 = fRec1961;
			double fTemp888 = (fConst294 * fRec1975[1]);
			double fTemp889 = (fConst296 * fRec1978[1]);
			double fTemp890 = (fConst297 * fRec1981[1]);
			double fTemp891 = (fConst299 * (((0.0106592695 * fTemp45) + ((0.0211450639 * fTemp44) + (((((0.1159641439 * fTemp37) + (0.0147564888 * fTemp42)) + (0.0157376142 * fTemp43)) + (0.0024989598000000001 * fTemp39)) + (0.0072290512000000003 * fTemp41)))) - ((0.0039237372000000001 * fTemp47) + (((0.10165735319999999 * fTemp38) + (0.020958301299999999 * fTemp40)) + (0.030432242299999999 * fTemp46)))));
			double fTemp892 = (fConst300 * fRec1984[1]);
			double fTemp893 = (fConst301 * fRec1987[1]);
			fRec1989[0] = (fTemp891 + (fTemp892 + (fRec1989[1] + fTemp893)));
			fRec1987[0] = fRec1989[0];
			double fRec1988 = ((fTemp893 + fTemp892) + fTemp891);
			fRec1986[0] = (fRec1987[0] + fRec1986[1]);
			fRec1984[0] = fRec1986[0];
			double fRec1985 = fRec1988;
			fRec1983[0] = (fTemp889 + (fTemp890 + (fRec1985 + fRec1983[1])));
			fRec1981[0] = fRec1983[0];
			double fRec1982 = (fTemp889 + (fRec1985 + fTemp890));
			fRec1980[0] = (fRec1981[0] + fRec1980[1]);
			fRec1978[0] = fRec1980[0];
			double fRec1979 = fRec1982;
			fRec1977[0] = (fTemp888 + (fRec1979 + fRec1977[1]));
			fRec1975[0] = fRec1977[0];
			double fRec1976 = (fRec1979 + fTemp888);
			double fTemp894 = (fConst303 * fRec1990[1]);
			double fTemp895 = (fConst304 * fRec1993[1]);
			double fTemp896 = (fConst306 * ((((0.0053189274000000003 * fTemp59) + ((0.041848493299999998 * fTemp58) + ((((0.1144768895 * fTemp53) + (0.0037560648999999998 * fTemp56)) + (0.0138674908 * fTemp57)) + (0.0018571359999999999 * fTemp55)))) + (0.033789075100000003 * fTemp61)) - ((0.086787957400000004 * fTemp54) + (0.060724842299999998 * fTemp60))));
			double fTemp897 = (fConst307 * fRec1996[1]);
			double fTemp898 = (fConst308 * fRec1999[1]);
			fRec2001[0] = (fTemp896 + (fTemp897 + (fRec2001[1] + fTemp898)));
			fRec1999[0] = fRec2001[0];
			double fRec2000 = ((fTemp898 + fTemp897) + fTemp896);
			fRec1998[0] = (fRec1999[0] + fRec1998[1]);
			fRec1996[0] = fRec1998[0];
			double fRec1997 = fRec2000;
			fRec1995[0] = (fTemp894 + (fTemp895 + (fRec1997 + fRec1995[1])));
			fRec1993[0] = fRec1995[0];
			double fRec1994 = (fTemp894 + (fRec1997 + fTemp895));
			fRec1992[0] = (fRec1993[0] + fRec1992[1]);
			fRec1990[0] = fRec1992[0];
			double fRec1991 = fRec1994;
			double fTemp899 = (fConst310 * fRec2002[1]);
			double fTemp900 = (fConst312 * ((((0.095660903800000002 * fTemp66) + (0.045114781399999998 * fTemp70)) + (0.066569255699999996 * fTemp72)) - ((((0.058752662800000001 * fTemp67) + (0.0036296078999999998 * fTemp69)) + (0.0107201437 * fTemp71)) + (0.078853763899999998 * fTemp68))));
			double fTemp901 = (fConst313 * fRec2005[1]);
			double fTemp902 = (fConst314 * fRec2008[1]);
			fRec2010[0] = (fTemp900 + (fTemp901 + (fRec2010[1] + fTemp902)));
			fRec2008[0] = fRec2010[0];
			double fRec2009 = ((fTemp902 + fTemp901) + fTemp900);
			fRec2007[0] = (fRec2008[0] + fRec2007[1]);
			fRec2005[0] = fRec2007[0];
			double fRec2006 = fRec2009;
			fRec2004[0] = (fTemp899 + (fRec2006 + fRec2004[1]));
			fRec2002[0] = fRec2004[0];
			double fRec2003 = (fRec2006 + fTemp899);
			double fTemp903 = (fConst316 * (((0.026849912600000001 * fTemp76) + (0.080783439999999998 * fTemp78)) - (0.038109699300000001 * fTemp77)));
			double fTemp904 = (fConst317 * fRec2011[1]);
			fRec2013[0] = (fTemp903 + (fRec2013[1] + fTemp904));
			fRec2011[0] = fRec2013[0];
			double fRec2012 = (fTemp904 + fTemp903);
			double fTemp905 = (fConst319 * (((0.063454501799999993 * fTemp81) + (0.084898322999999998 * fTemp84)) - (((0.025747456500000002 * fTemp82) + (0.0264804254 * fTemp85)) + (0.077633339100000004 * fTemp83))));
			double fTemp906 = (fConst320 * fRec2014[1]);
			double fTemp907 = (fConst321 * fRec2017[1]);
			fRec2019[0] = (fTemp905 + (fTemp906 + (fRec2019[1] + fTemp907)));
			fRec2017[0] = fRec2019[0];
			double fRec2018 = ((fTemp907 + fTemp906) + fTemp905);
			fRec2016[0] = (fRec2017[0] + fRec2016[1]);
			fRec2014[0] = fRec2016[0];
			double fRec2015 = fRec2018;
			fVec29[(IOTA & 511)] = (((0.030514682899999999 * fTemp96) + ((0.0132273216 * fTemp9) + ((0.016281056200000001 * fTemp95) + ((0.019369305900000001 * fTemp94) + ((0.0270286208 * fTemp92) + ((0.075058082799999995 * fTemp90) + ((0.033264708800000001 * fTemp13) + (fRec1958 + (fRec1976 + (fRec1991 + (fRec2003 + (fRec2012 + fRec2015)))))))))))) - ((0.060045298699999999 * fTemp97) + ((0.00028272019999999999 * fTemp7) + (((0.021440408899999999 * fTemp10) + (((0.0031342599999999998 * fTemp12) + (((0.084424012199999995 * fTemp91) + (0.0001458636 * fTemp93)) + (0.015982873799999998 * fTemp89))) + (0.0092401714000000003 * fTemp11))) + (1.9783400000000001e-05 * fTemp8)))));
			output30[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec29[((IOTA - iConst322) & 511)])));
			double fTemp908 = (fConst244 * fRec2020[1]);
			double fTemp909 = (fConst245 * fRec2023[1]);
			double fTemp910 = (fConst247 * fRec2026[1]);
			double fTemp911 = (fConst248 * fRec2029[1]);
			double fTemp912 = (fConst250 * ((((0.0233705606 * fTemp24) + ((0.011157234800000001 * fTemp23) + (((0.037099355200000003 * fTemp18) + (0.00200723 * fTemp19)) + (0.0157399228 * fTemp22)))) + (0.097577884099999998 * fTemp30)) - (((0.026362418299999999 * fTemp21) + (((((0.046125358900000003 * fTemp25) + (0.0080237312999999998 * fTemp26)) + (0.0026438100999999999 * fTemp27)) + (0.0020539666000000002 * fTemp28)) + (0.0079021630999999998 * fTemp20))) + (0.093121155100000005 * fTemp29))));
			double fTemp913 = (fConst251 * fRec2032[1]);
			double fTemp914 = (fConst252 * fRec2035[1]);
			fRec2037[0] = (fTemp912 + (fTemp913 + (fRec2037[1] + fTemp914)));
			fRec2035[0] = fRec2037[0];
			double fRec2036 = ((fTemp914 + fTemp913) + fTemp912);
			fRec2034[0] = (fRec2035[0] + fRec2034[1]);
			fRec2032[0] = fRec2034[0];
			double fRec2033 = fRec2036;
			fRec2031[0] = (fTemp910 + (fTemp911 + (fRec2033 + fRec2031[1])));
			fRec2029[0] = fRec2031[0];
			double fRec2030 = (fTemp910 + (fRec2033 + fTemp911));
			fRec2028[0] = (fRec2029[0] + fRec2028[1]);
			fRec2026[0] = fRec2028[0];
			double fRec2027 = fRec2030;
			fRec2025[0] = (fTemp908 + (fTemp909 + (fRec2027 + fRec2025[1])));
			fRec2023[0] = fRec2025[0];
			double fRec2024 = (fTemp908 + (fRec2027 + fTemp909));
			fRec2022[0] = (fRec2023[0] + fRec2022[1]);
			fRec2020[0] = fRec2022[0];
			double fRec2021 = fRec2024;
			double fTemp915 = (fConst254 * fRec2038[1]);
			double fTemp916 = (fConst256 * fRec2041[1]);
			double fTemp917 = (fConst257 * fRec2044[1]);
			double fTemp918 = (fConst259 * ((((0.0175372694 * fTemp45) + ((0.0259678913 * fTemp44) + ((0.031716897299999998 * fTemp38) + (0.0078482879000000005 * fTemp41)))) + (0.1082692269 * fTemp47)) - ((((((0.041924418400000003 * fTemp37) + (0.0045808914999999999 * fTemp42)) + (0.0040121705000000004 * fTemp43)) + (0.00042068200000000002 * fTemp39)) + (0.020977332099999999 * fTemp40)) + (0.10121722599999999 * fTemp46))));
			double fTemp919 = (fConst260 * fRec2047[1]);
			double fTemp920 = (fConst261 * fRec2050[1]);
			fRec2052[0] = (fTemp918 + (fTemp919 + (fRec2052[1] + fTemp920)));
			fRec2050[0] = fRec2052[0];
			double fRec2051 = ((fTemp920 + fTemp919) + fTemp918);
			fRec2049[0] = (fRec2050[0] + fRec2049[1]);
			fRec2047[0] = fRec2049[0];
			double fRec2048 = fRec2051;
			fRec2046[0] = (fTemp916 + (fTemp917 + (fRec2048 + fRec2046[1])));
			fRec2044[0] = fRec2046[0];
			double fRec2045 = (fTemp916 + (fRec2048 + fTemp917));
			fRec2043[0] = (fRec2044[0] + fRec2043[1]);
			fRec2041[0] = fRec2043[0];
			double fRec2042 = fRec2045;
			fRec2040[0] = (fTemp915 + (fRec2042 + fRec2040[1]));
			fRec2038[0] = fRec2040[0];
			double fRec2039 = (fRec2042 + fTemp915);
			double fTemp921 = (fConst263 * fRec2053[1]);
			double fTemp922 = (fConst264 * fRec2056[1]);
			double fTemp923 = (fConst266 * ((((0.0063173565999999999 * fTemp59) + ((0.043833602399999998 * fTemp58) + ((0.023924468800000001 * fTemp54) + (0.0019850127999999998 * fTemp55)))) + (0.1142230754 * fTemp61)) - ((((0.034902777900000001 * fTemp53) + (0.0012863905000000001 * fTemp56)) + (0.0033561749999999999 * fTemp57)) + (0.1031383375 * fTemp60))));
			double fTemp924 = (fConst267 * fRec2059[1]);
			double fTemp925 = (fConst268 * fRec2062[1]);
			fRec2064[0] = (fTemp923 + (fTemp924 + (fRec2064[1] + fTemp925)));
			fRec2062[0] = fRec2064[0];
			double fRec2063 = ((fTemp925 + fTemp924) + fTemp923);
			fRec2061[0] = (fRec2062[0] + fRec2061[1]);
			fRec2059[0] = fRec2061[0];
			double fRec2060 = fRec2063;
			fRec2058[0] = (fTemp921 + (fTemp922 + (fRec2060 + fRec2058[1])));
			fRec2056[0] = fRec2058[0];
			double fRec2057 = (fTemp921 + (fRec2060 + fTemp922));
			fRec2055[0] = (fRec2056[0] + fRec2055[1]);
			fRec2053[0] = fRec2055[0];
			double fRec2054 = fRec2057;
			double fTemp926 = (fConst270 * fRec2065[1]);
			double fTemp927 = (fConst272 * (((((0.0148861251 * fTemp67) + (0.00072266569999999996 * fTemp69)) + (0.045025074900000003 * fTemp70)) + (0.1137278704 * fTemp72)) - (((0.0257988961 * fTemp66) + (0.011327129 * fTemp71)) + (0.097165509999999997 * fTemp68))));
			double fTemp928 = (fConst273 * fRec2068[1]);
			double fTemp929 = (fConst274 * fRec2071[1]);
			fRec2073[0] = (fTemp927 + (fTemp928 + (fRec2073[1] + fTemp929)));
			fRec2071[0] = fRec2073[0];
			double fRec2072 = ((fTemp929 + fTemp928) + fTemp927);
			fRec2070[0] = (fRec2071[0] + fRec2070[1]);
			fRec2068[0] = fRec2070[0];
			double fRec2069 = fRec2072;
			fRec2067[0] = (fTemp926 + (fRec2069 + fRec2067[1]));
			fRec2065[0] = fRec2067[0];
			double fRec2066 = (fRec2069 + fTemp926);
			double fTemp930 = (fConst276 * ((0.084942507 * fTemp78) - ((0.0063592984000000003 * fTemp76) + (0.0381259428 * fTemp77))));
			double fTemp931 = (fConst277 * fRec2074[1]);
			fRec2076[0] = (fTemp930 + (fRec2076[1] + fTemp931));
			fRec2074[0] = fRec2076[0];
			double fRec2075 = (fTemp931 + fTemp930);
			double fTemp932 = (fConst279 * (((0.0062100437 * fTemp82) + (0.1048784839 * fTemp84)) - (((0.0157546839 * fTemp81) + (0.026477076400000001 * fTemp85)) + (0.081545686199999995 * fTemp83))));
			double fTemp933 = (fConst280 * fRec2077[1]);
			double fTemp934 = (fConst281 * fRec2080[1]);
			fRec2082[0] = (fTemp932 + (fTemp933 + (fRec2082[1] + fTemp934)));
			fRec2080[0] = fRec2082[0];
			double fRec2081 = ((fTemp934 + fTemp933) + fTemp932);
			fRec2079[0] = (fRec2080[0] + fRec2079[1]);
			fRec2077[0] = fRec2079[0];
			double fRec2078 = fRec2081;
			fVec30[(IOTA & 511)] = (((0.083791871300000001 * fTemp97) + ((0.024776538800000001 * fTemp7) + ((0.023060235500000002 * fTemp9) + ((0.016286794 * fTemp95) + ((0.00059068439999999999 * fTemp12) + ((0.0040693965999999996 * fTemp89) + (((0.033288954699999998 * fTemp13) + (fRec2021 + (fRec2039 + (fRec2054 + (fRec2066 + (fRec2075 + fRec2078)))))) + (0.039373983799999998 * fTemp91)))))))) - ((0.080643591400000006 * fTemp96) + ((0.00019718310000000001 * fTemp8) + ((0.026512872699999999 * fTemp10) + (((((0.047166168699999997 * fTemp90) + (0.010732228 * fTemp92)) + (3.2146800000000002e-05 * fTemp93)) + (0.0048225806000000001 * fTemp94)) + (0.0097170959000000001 * fTemp11))))));
			output31[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec30[((IOTA - iConst282) & 511)])));
			double fTemp935 = (fConst284 * fRec2083[1]);
			double fTemp936 = (fConst285 * fRec2086[1]);
			double fTemp937 = (fConst287 * fRec2089[1]);
			double fTemp938 = (fConst288 * fRec2092[1]);
			double fTemp939 = (fConst290 * ((((0.0019706499 * fTemp23) + (((0.072886843100000001 * fTemp18) + (0.0118153479 * fTemp19)) + (0.0095500337000000001 * fTemp22))) + (0.068813978600000006 * fTemp29)) - ((((0.023510903100000001 * fTemp21) + (((((0.037386785899999997 * fTemp25) + (0.023566104500000001 * fTemp26)) + (0.0113154798 * fTemp27)) + (0.0125820705 * fTemp28)) + (0.0079369708999999997 * fTemp20))) + (0.0073497941999999998 * fTemp24)) + (0.10124456110000001 * fTemp30))));
			double fTemp940 = (fConst291 * fRec2095[1]);
			double fTemp941 = (fConst292 * fRec2098[1]);
			fRec2100[0] = (fTemp939 + (fTemp940 + (fRec2100[1] + fTemp941)));
			fRec2098[0] = fRec2100[0];
			double fRec2099 = ((fTemp941 + fTemp940) + fTemp939);
			fRec2097[0] = (fRec2098[0] + fRec2097[1]);
			fRec2095[0] = fRec2097[0];
			double fRec2096 = fRec2099;
			fRec2094[0] = (fTemp937 + (fTemp938 + (fRec2096 + fRec2094[1])));
			fRec2092[0] = fRec2094[0];
			double fRec2093 = (fTemp937 + (fRec2096 + fTemp938));
			fRec2091[0] = (fRec2092[0] + fRec2091[1]);
			fRec2089[0] = fRec2091[0];
			double fRec2090 = fRec2093;
			fRec2088[0] = (fTemp935 + (fTemp936 + (fRec2090 + fRec2088[1])));
			fRec2086[0] = fRec2088[0];
			double fRec2087 = (fTemp935 + (fRec2090 + fTemp936));
			fRec2085[0] = (fRec2086[0] + fRec2085[1]);
			fRec2083[0] = fRec2085[0];
			double fRec2084 = fRec2087;
			double fTemp942 = (fConst294 * fRec2101[1]);
			double fTemp943 = (fConst296 * fRec2104[1]);
			double fTemp944 = (fConst297 * fRec2107[1]);
			double fTemp945 = (fConst299 * (((0.030380761799999999 * fTemp46) + ((0.0029530737999999999 * fTemp45) + ((0.015719100499999999 * fTemp44) + ((0.1016226001 * fTemp38) + (0.0069555950000000002 * fTemp41))))) - ((((((0.0847848977 * fTemp37) + (0.017856617299999999 * fTemp42)) + (0.021116912599999999 * fTemp43)) + (0.0034212515999999999 * fTemp39)) + (0.0209121193 * fTemp40)) + (0.079316631799999995 * fTemp47))));
			double fTemp946 = (fConst300 * fRec2110[1]);
			double fTemp947 = (fConst301 * fRec2113[1]);
			fRec2115[0] = (fTemp945 + (fTemp946 + (fRec2115[1] + fTemp947)));
			fRec2113[0] = fRec2115[0];
			double fRec2114 = ((fTemp947 + fTemp946) + fTemp945);
			fRec2112[0] = (fRec2113[0] + fRec2112[1]);
			fRec2110[0] = fRec2112[0];
			double fRec2111 = fRec2114;
			fRec2109[0] = (fTemp943 + (fTemp944 + (fRec2111 + fRec2109[1])));
			fRec2107[0] = fRec2109[0];
			double fRec2108 = (fTemp943 + (fRec2111 + fTemp944));
			fRec2106[0] = (fRec2107[0] + fRec2106[1]);
			fRec2104[0] = fRec2106[0];
			double fRec2105 = fRec2108;
			fRec2103[0] = (fTemp942 + (fRec2105 + fRec2103[1]));
			fRec2101[0] = fRec2103[0];
			double fRec2102 = (fRec2105 + fTemp942);
			double fTemp948 = (fConst303 * fRec2116[1]);
			double fTemp949 = (fConst304 * fRec2119[1]);
			double fTemp950 = (fConst306 * (((0.0037265244999999999 * fTemp59) + ((0.039366777800000002 * fTemp58) + ((0.1042477044 * fTemp54) + (0.0019129854 * fTemp55)))) - ((0.033850113299999998 * fTemp61) + ((((0.1145386578 * fTemp53) + (0.0052075050000000003 * fTemp56)) + (0.019758842499999998 * fTemp57)) + (0.018452355399999999 * fTemp60)))));
			double fTemp951 = (fConst307 * fRec2122[1]);
			double fTemp952 = (fConst308 * fRec2125[1]);
			fRec2127[0] = (fTemp950 + (fTemp951 + (fRec2127[1] + fTemp952)));
			fRec2125[0] = fRec2127[0];
			double fRec2126 = ((fTemp952 + fTemp951) + fTemp950);
			fRec2124[0] = (fRec2125[0] + fRec2124[1]);
			fRec2122[0] = fRec2124[0];
			double fRec2123 = fRec2126;
			fRec2121[0] = (fTemp948 + (fTemp949 + (fRec2123 + fRec2121[1])));
			fRec2119[0] = fRec2121[0];
			double fRec2120 = (fTemp948 + (fRec2123 + fTemp949));
			fRec2118[0] = (fRec2119[0] + fRec2118[1]);
			fRec2116[0] = fRec2118[0];
			double fRec2117 = fRec2120;
			double fTemp953 = (fConst310 * fRec2128[1]);
			double fTemp954 = (fConst312 * (((((0.078797231100000004 * fTemp67) + (0.0050690268999999998 * fTemp69)) + (0.045098519099999998 * fTemp70)) + (0.0205600427 * fTemp72)) - (((0.1147884329 * fTemp66) + (0.0102268551 * fTemp71)) + (0.058736826300000003 * fTemp68))));
			double fTemp955 = (fConst313 * fRec2131[1]);
			double fTemp956 = (fConst314 * fRec2134[1]);
			fRec2136[0] = (fTemp954 + (fTemp955 + (fRec2136[1] + fTemp956)));
			fRec2134[0] = fRec2136[0];
			double fRec2135 = ((fTemp956 + fTemp955) + fTemp954);
			fRec2133[0] = (fRec2134[0] + fRec2133[1]);
			fRec2131[0] = fRec2133[0];
			double fRec2132 = fRec2135;
			fRec2130[0] = (fTemp953 + (fRec2132 + fRec2130[1]));
			fRec2128[0] = fRec2130[0];
			double fRec2129 = (fRec2132 + fTemp953);
			double fTemp957 = (fConst316 * ((0.076140564800000005 * fTemp78) - ((0.0381565154 * fTemp76) + (0.038081240299999999 * fTemp77))));
			double fTemp958 = (fConst317 * fRec2137[1]);
			fRec2139[0] = (fTemp957 + (fRec2139[1] + fTemp958));
			fRec2137[0] = fRec2139[0];
			double fRec2138 = (fTemp958 + fTemp957);
			double fTemp959 = (fConst319 * (((0.0366610224 * fTemp82) + (0.063480344100000002 * fTemp84)) - (((0.084950796300000006 * fTemp81) + (0.0265425548 * fTemp85)) + (0.073062467300000003 * fTemp83))));
			double fTemp960 = (fConst320 * fRec2140[1]);
			double fTemp961 = (fConst321 * fRec2143[1]);
			fRec2145[0] = (fTemp959 + (fTemp960 + (fRec2145[1] + fTemp961)));
			fRec2143[0] = fRec2145[0];
			double fRec2144 = ((fTemp961 + fTemp960) + fTemp959);
			fRec2142[0] = (fRec2143[0] + fRec2142[1]);
			fRec2140[0] = fRec2142[0];
			double fRec2141 = fRec2144;
			fVec31[(IOTA & 511)] = (((0.084389492699999999 * fTemp96) + ((6.7661999999999997e-06 * fTemp8) + ((0.0043138137999999999 * fTemp9) + ((0.016278453500000001 * fTemp95) + ((0.0043340664000000003 * fTemp12) + ((0.021428276900000001 * fTemp89) + ((0.0001782877 * fTemp93) + ((0.030541625199999999 * fTemp91) + ((0.0107072086 * fTemp90) + ((0.033273105499999997 * fTemp13) + (fRec2084 + (fRec2102 + (fRec2117 + (fRec2129 + (fRec2138 + fRec2141))))))))))))))) - ((0.095548251799999998 * fTemp97) + (((0.015942413700000001 * fTemp10) + (((0.0193482572 * fTemp92) + (0.0231229763 * fTemp94)) + (0.0088121206000000007 * fTemp11))) + (0.018790212000000001 * fTemp7))));
			output32[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec31[((IOTA - iConst322) & 511)])));
			double fTemp962 = (fConst244 * fRec2146[1]);
			double fTemp963 = (fConst245 * fRec2149[1]);
			double fTemp964 = (fConst247 * fRec2152[1]);
			double fTemp965 = (fConst248 * fRec2155[1]);
			double fTemp966 = (fConst250 * (((0.046326099000000003 * fTemp30) + ((((0.097477754299999997 * fTemp25) + (0.0079148411999999998 * fTemp26)) + (0.020030106200000002 * fTemp19)) + (0.039603923899999997 * fTemp29))) - ((0.023470222499999999 * fTemp24) + ((0.0097517874999999993 * fTemp23) + ((0.0021197684999999999 * fTemp22) + ((0.017148029400000001 * fTemp21) + ((((0.092095138699999995 * fTemp18) + (0.0059872425 * fTemp27)) + (0.015658387100000001 * fTemp28)) + (0.0078509932999999994 * fTemp20))))))));
			double fTemp967 = (fConst251 * fRec2158[1]);
			double fTemp968 = (fConst252 * fRec2161[1]);
			fRec2163[0] = (fTemp966 + (fTemp967 + (fRec2163[1] + fTemp968)));
			fRec2161[0] = fRec2163[0];
			double fRec2162 = ((fTemp968 + fTemp967) + fTemp966);
			fRec2160[0] = (fRec2161[0] + fRec2160[1]);
			fRec2158[0] = fRec2160[0];
			double fRec2159 = fRec2162;
			fRec2157[0] = (fTemp964 + (fTemp965 + (fRec2159 + fRec2157[1])));
			fRec2155[0] = fRec2157[0];
			double fRec2156 = (fTemp964 + (fRec2159 + fTemp965));
			fRec2154[0] = (fRec2155[0] + fRec2154[1]);
			fRec2152[0] = fRec2154[0];
			double fRec2153 = fRec2156;
			fRec2151[0] = (fTemp962 + (fTemp963 + (fRec2153 + fRec2151[1])));
			fRec2149[0] = fRec2151[0];
			double fRec2150 = (fTemp962 + (fRec2153 + fTemp963));
			fRec2148[0] = (fRec2149[0] + fRec2148[1]);
			fRec2146[0] = fRec2148[0];
			double fRec2147 = fRec2150;
			double fTemp969 = (fConst254 * fRec2164[1]);
			double fTemp970 = (fConst256 * fRec2167[1]);
			double fTemp971 = (fConst257 * fRec2170[1]);
			double fTemp972 = (fConst259 * ((((0.10625787740000001 * fTemp37) + (0.0051312151999999998 * fTemp41)) + (0.1012421013 * fTemp46)) - (((0.015667384499999999 * fTemp45) + ((((((0.0317420406 * fTemp38) + (0.0092974079000000005 * fTemp42)) + (0.025961978399999999 * fTemp43)) + (0.0057835088 * fTemp39)) + (0.020965126000000001 * fTemp40)) + (0.0040183064000000003 * fTemp44))) + (0.046719152299999997 * fTemp47))));
			double fTemp973 = (fConst260 * fRec2173[1]);
			double fTemp974 = (fConst261 * fRec2176[1]);
			fRec2178[0] = (fTemp972 + (fTemp973 + (fRec2178[1] + fTemp974)));
			fRec2176[0] = fRec2178[0];
			double fRec2177 = ((fTemp974 + fTemp973) + fTemp972);
			fRec2175[0] = (fRec2176[0] + fRec2175[1]);
			fRec2173[0] = fRec2175[0];
			double fRec2174 = fRec2177;
			fRec2172[0] = (fTemp970 + (fTemp971 + (fRec2174 + fRec2172[1])));
			fRec2170[0] = fRec2172[0];
			double fRec2171 = (fTemp970 + (fRec2174 + fTemp971));
			fRec2169[0] = (fRec2170[0] + fRec2169[1]);
			fRec2167[0] = fRec2169[0];
			double fRec2168 = fRec2171;
			fRec2166[0] = (fTemp969 + (fRec2168 + fRec2166[1]));
			fRec2164[0] = fRec2166[0];
			double fRec2165 = (fRec2168 + fTemp969);
			double fTemp975 = (fConst263 * fRec2179[1]);
			double fTemp976 = (fConst264 * fRec2182[1]);
			double fTemp977 = (fConst266 * ((((0.028648525399999999 * fTemp58) + (((0.035043847500000003 * fTemp53) + (0.056026102899999999 * fTemp54)) + (0.0019036509000000001 * fTemp55))) + (0.089895163 * fTemp60)) - ((((0.0064292795000000002 * fTemp56) + (0.033390495899999997 * fTemp57)) + (0.0012416939 * fTemp59)) + (0.1141380072 * fTemp61))));
			double fTemp978 = (fConst267 * fRec2185[1]);
			double fTemp979 = (fConst268 * fRec2188[1]);
			fRec2190[0] = (fTemp977 + (fTemp978 + (fRec2190[1] + fTemp979)));
			fRec2188[0] = fRec2190[0];
			double fRec2189 = ((fTemp979 + fTemp978) + fTemp977);
			fRec2187[0] = (fRec2188[0] + fRec2187[1]);
			fRec2185[0] = fRec2187[0];
			double fRec2186 = fRec2189;
			fRec2184[0] = (fTemp975 + (fTemp976 + (fRec2186 + fRec2184[1])));
			fRec2182[0] = fRec2184[0];
			double fRec2183 = (fTemp975 + (fRec2186 + fTemp976));
			fRec2181[0] = (fRec2182[0] + fRec2181[1]);
			fRec2179[0] = fRec2181[0];
			double fRec2180 = fRec2183;
			double fTemp980 = (fConst270 * fRec2191[1]);
			double fTemp981 = (fConst272 * (((((0.097218402800000006 * fTemp67) + (0.0084727716999999994 * fTemp69)) + (0.045056816100000001 * fTemp70)) + (0.014904769999999999 * fTemp68)) - (((0.062058498400000002 * fTemp66) + (0.0074275551000000002 * fTemp71)) + (0.098685277700000004 * fTemp72))));
			double fTemp982 = (fConst273 * fRec2194[1]);
			double fTemp983 = (fConst274 * fRec2197[1]);
			fRec2199[0] = (fTemp981 + (fTemp982 + (fRec2199[1] + fTemp983)));
			fRec2197[0] = fRec2199[0];
			double fRec2198 = ((fTemp983 + fTemp982) + fTemp981);
			fRec2196[0] = (fRec2197[0] + fRec2196[1]);
			fRec2194[0] = fRec2196[0];
			double fRec2195 = fRec2198;
			fRec2193[0] = (fTemp980 + (fRec2195 + fRec2193[1]));
			fRec2191[0] = fRec2193[0];
			double fRec2192 = (fRec2195 + fTemp980);
			double fTemp984 = (fConst276 * ((0.055534124300000001 * fTemp78) - ((0.064560003800000001 * fTemp76) + (0.038148365599999998 * fTemp77))));
			double fTemp985 = (fConst277 * fRec2200[1]);
			fRec2202[0] = (fTemp984 + (fRec2202[1] + fTemp985));
			fRec2200[0] = fRec2202[0];
			double fRec2201 = (fTemp985 + fTemp984);
			double fTemp986 = (fConst279 * ((0.062092499199999998 * fTemp82) - ((((0.1048360638 * fTemp81) + (0.026436373700000002 * fTemp85)) + (0.053295253299999998 * fTemp83)) + (0.015813225 * fTemp84))));
			double fTemp987 = (fConst280 * fRec2203[1]);
			double fTemp988 = (fConst281 * fRec2206[1]);
			fRec2208[0] = (fTemp986 + (fTemp987 + (fRec2208[1] + fTemp988)));
			fRec2206[0] = fRec2208[0];
			double fRec2207 = ((fTemp988 + fTemp987) + fTemp986);
			fRec2205[0] = (fRec2206[0] + fRec2205[1]);
			fRec2203[0] = fRec2205[0];
			double fRec2204 = fRec2207;
			fVec32[(IOTA & 511)] = (((0.0926901787 * fTemp97) + ((0.00022651959999999999 * fTemp8) + ((0.0041158621999999997 * fTemp10) + ((0.0162568243 * fTemp95) + ((0.0073046824 * fTemp12) + ((0.026473720700000002 * fTemp89) + ((5.95359e-05 * fTemp93) + ((0.0250610876 * fTemp92) + ((0.025684055599999998 * fTemp90) + ((0.0332842348 * fTemp13) + (fRec2147 + (fRec2165 + (fRec2180 + (fRec2192 + (fRec2201 + fRec2204))))))))))))))) - ((0.039374303700000002 * fTemp96) + (((((0.080631346000000007 * fTemp91) + (0.012813237200000001 * fTemp94)) + (0.0064763583000000003 * fTemp11)) + (0.0197454276 * fTemp9)) + (0.0100803718 * fTemp7))));
			output33[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec32[((IOTA - iConst282) & 511)])));
			double fTemp989 = (fConst284 * fRec2209[1]);
			double fTemp990 = (fConst285 * fRec2212[1]);
			double fTemp991 = (fConst287 * fRec2215[1]);
			double fTemp992 = (fConst288 * fRec2218[1]);
			double fTemp993 = (fConst290 * ((((((0.023570344100000001 * fTemp26) + (0.0065930438999999997 * fTemp27)) + (0.025003052200000001 * fTemp19)) + (0.0074305459000000001 * fTemp24)) + (0.037347613799999999 * fTemp30)) - (((0.0094199182999999999 * fTemp23) + ((0.012551811899999999 * fTemp22) + ((0.0082732707999999995 * fTemp21) + ((((0.1012254278 * fTemp25) + (0.0027766373999999999 * fTemp18)) + (0.0094999239999999999 * fTemp28)) + (0.0078574508000000005 * fTemp20))))) + (0.10019014599999999 * fTemp29))));
			double fTemp994 = (fConst291 * fRec2221[1]);
			double fTemp995 = (fConst292 * fRec2224[1]);
			fRec2226[0] = (fTemp993 + (fTemp994 + (fRec2226[1] + fTemp995)));
			fRec2224[0] = fRec2226[0];
			double fRec2225 = ((fTemp995 + fTemp994) + fTemp993);
			fRec2223[0] = (fRec2224[0] + fRec2223[1]);
			fRec2221[0] = fRec2223[0];
			double fRec2222 = fRec2225;
			fRec2220[0] = (fTemp991 + (fTemp992 + (fRec2222 + fRec2220[1])));
			fRec2218[0] = fRec2220[0];
			double fRec2219 = (fTemp991 + (fRec2222 + fTemp992));
			fRec2217[0] = (fRec2218[0] + fRec2217[1]);
			fRec2215[0] = fRec2217[0];
			double fRec2216 = fRec2219;
			fRec2214[0] = (fTemp989 + (fTemp990 + (fRec2216 + fRec2214[1])));
			fRec2212[0] = fRec2214[0];
			double fRec2213 = (fTemp989 + (fRec2216 + fTemp990));
			fRec2211[0] = (fRec2212[0] + fRec2211[1]);
			fRec2209[0] = fRec2211[0];
			double fRec2210 = fRec2213;
			double fTemp996 = (fConst294 * fRec2227[1]);
			double fTemp997 = (fConst296 * fRec2230[1]);
			double fTemp998 = (fConst297 * fRec2233[1]);
			double fTemp999 = (fConst299 * (((((0.0038138676000000001 * fTemp37) + (0.0106130081 * fTemp42)) + (0.0024886294000000002 * fTemp41)) + (0.1160031044 * fTemp47)) - ((0.030479802600000001 * fTemp46) + ((0.014705922999999999 * fTemp45) + (((((0.1015912773 * fTemp38) + (0.015737087699999999 * fTemp43)) + (0.0073037351 * fTemp39)) + (0.020953242600000001 * fTemp40)) + (0.021115635600000002 * fTemp44))))));
			double fTemp1000 = (fConst300 * fRec2236[1]);
			double fTemp1001 = (fConst301 * fRec2239[1]);
			fRec2241[0] = (fTemp999 + (fTemp1000 + (fRec2241[1] + fTemp1001)));
			fRec2239[0] = fRec2241[0];
			double fRec2240 = ((fTemp1001 + fTemp1000) + fTemp999);
			fRec2238[0] = (fRec2239[0] + fRec2238[1]);
			fRec2236[0] = fRec2238[0];
			double fRec2237 = fRec2240;
			fRec2235[0] = (fTemp997 + (fTemp998 + (fRec2237 + fRec2235[1])));
			fRec2233[0] = fRec2235[0];
			double fRec2234 = (fTemp997 + (fRec2237 + fTemp998));
			fRec2232[0] = (fRec2233[0] + fRec2232[1]);
			fRec2230[0] = fRec2232[0];
			double fRec2231 = fRec2234;
			fRec2229[0] = (fTemp996 + (fRec2231 + fRec2229[1]));
			fRec2227[0] = fRec2229[0];
			double fRec2228 = (fRec2231 + fTemp996);
			double fTemp1002 = (fConst303 * fRec2242[1]);
			double fTemp1003 = (fConst304 * fRec2245[1]);
			double fTemp1004 = (fConst306 * (((0.033897464600000003 * fTemp61) + (((0.013863962699999999 * fTemp58) + ((0.1144869867 * fTemp53) + (0.0019124491999999999 * fTemp55))) + (0.086714518700000007 * fTemp60))) - ((((0.060743407399999998 * fTemp54) + (0.0037140712999999999 * fTemp56)) + (0.041807355900000003 * fTemp57)) + (0.0052659958000000002 * fTemp59))));
			double fTemp1005 = (fConst307 * fRec2248[1]);
			double fTemp1006 = (fConst308 * fRec2251[1]);
			fRec2253[0] = (fTemp1004 + (fTemp1005 + (fRec2253[1] + fTemp1006)));
			fRec2251[0] = fRec2253[0];
			double fRec2252 = ((fTemp1006 + fTemp1005) + fTemp1004);
			fRec2250[0] = (fRec2251[0] + fRec2250[1]);
			fRec2248[0] = fRec2250[0];
			double fRec2249 = fRec2252;
			fRec2247[0] = (fTemp1002 + (fTemp1003 + (fRec2249 + fRec2247[1])));
			fRec2245[0] = fRec2247[0];
			double fRec2246 = (fTemp1002 + (fRec2249 + fTemp1003));
			fRec2244[0] = (fRec2245[0] + fRec2244[1]);
			fRec2242[0] = fRec2244[0];
			double fRec2243 = fRec2246;
			double fTemp1007 = (fConst310 * fRec2254[1]);
			double fTemp1008 = (fConst312 * ((((((0.066656725400000005 * fTemp66) + (0.058691351000000003 * fTemp67)) + (0.0107694785 * fTemp69)) + (0.045080427800000003 * fTemp70)) + (0.078843311299999996 * fTemp68)) - ((0.0036500515999999998 * fTemp71) + (0.095647291300000006 * fTemp72))));
			double fTemp1009 = (fConst313 * fRec2257[1]);
			double fTemp1010 = (fConst314 * fRec2260[1]);
			fRec2262[0] = (fTemp1008 + (fTemp1009 + (fRec2262[1] + fTemp1010)));
			fRec2260[0] = fRec2262[0];
			double fRec2261 = ((fTemp1010 + fTemp1009) + fTemp1008);
			fRec2259[0] = (fRec2260[0] + fRec2259[1]);
			fRec2257[0] = fRec2259[0];
			double fRec2258 = fRec2261;
			fRec2256[0] = (fTemp1007 + (fRec2258 + fRec2256[1]));
			fRec2254[0] = fRec2256[0];
			double fRec2255 = (fRec2258 + fTemp1007);
			double fTemp1011 = (fConst316 * ((0.026835694399999999 * fTemp78) - ((0.080811546499999998 * fTemp76) + (0.0380982391 * fTemp77))));
			double fTemp1012 = (fConst317 * fRec2263[1]);
			fRec2265[0] = (fTemp1011 + (fRec2265[1] + fTemp1012));
			fRec2263[0] = fRec2265[0];
			double fRec2264 = (fTemp1012 + fTemp1011);
			double fTemp1013 = (fConst319 * ((0.0776089425 * fTemp82) - ((((0.063432372299999998 * fTemp81) + (0.026503915499999999 * fTemp85)) + (0.0257158291 * fTemp83)) + (0.084954703100000001 * fTemp84))));
			double fTemp1014 = (fConst320 * fRec2266[1]);
			double fTemp1015 = (fConst321 * fRec2269[1]);
			fRec2271[0] = (fTemp1013 + (fTemp1014 + (fRec2271[1] + fTemp1015)));
			fRec2269[0] = fRec2271[0];
			double fRec2270 = ((fTemp1015 + fTemp1014) + fTemp1013);
			fRec2268[0] = (fRec2269[0] + fRec2268[1]);
			fRec2266[0] = fRec2268[0];
			double fRec2267 = fRec2270;
			fVec33[(IOTA & 511)] = (((0.026983258199999999 * fTemp7) + ((0.021447418499999999 * fTemp10) + ((0.0162344395 * fTemp95) + ((0.0092233791999999995 * fTemp12) + ((0.015909262699999999 * fTemp89) + ((0.0133041662 * fTemp94) + ((0.00031972450000000003 * fTemp92) + (((0.033272114499999998 * fTemp13) + (fRec2210 + (fRec2228 + (fRec2243 + (fRec2255 + (fRec2264 + fRec2267)))))) + (0.084400527500000003 * fTemp91))))))))) - ((0.0751142692 * fTemp97) + ((0.030451960899999998 * fTemp96) + ((2.7917300000000001e-05 * fTemp8) + ((((0.059979714500000003 * fTemp90) + (0.0001590676 * fTemp93)) + (0.0031295009999999998 * fTemp11)) + (0.019329067200000001 * fTemp9))))));
			output34[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec33[((IOTA - iConst322) & 511)])));
			double fTemp1016 = (fConst244 * fRec2272[1]);
			double fTemp1017 = (fConst245 * fRec2275[1]);
			double fTemp1018 = (fConst247 * fRec2278[1]);
			double fTemp1019 = (fConst248 * fRec2281[1]);
			double fTemp1020 = (fConst250 * (((0.037026401100000002 * fTemp29) + ((0.023404115 * fTemp24) + ((((0.0262394089 * fTemp19) + ((((0.046144461800000001 * fTemp25) + (0.093138186400000003 * fTemp18)) + (0.011164246100000001 * fTemp27)) + (0.0020538828000000002 * fTemp28))) + (0.0020003108999999998 * fTemp21)) + (0.0026383072 * fTemp23)))) - ((((0.0079716317000000005 * fTemp26) + (0.0078795176999999997 * fTemp20)) + (0.0156229473 * fTemp22)) + (0.097577455100000002 * fTemp30))));
			double fTemp1021 = (fConst251 * fRec2284[1]);
			double fTemp1022 = (fConst252 * fRec2287[1]);
			fRec2289[0] = (fTemp1020 + (fTemp1021 + (fRec2289[1] + fTemp1022)));
			fRec2287[0] = fRec2289[0];
			double fRec2288 = ((fTemp1022 + fTemp1021) + fTemp1020);
			fRec2286[0] = (fRec2287[0] + fRec2286[1]);
			fRec2284[0] = fRec2286[0];
			double fRec2285 = fRec2288;
			fRec2283[0] = (fTemp1018 + (fTemp1019 + (fRec2285 + fRec2283[1])));
			fRec2281[0] = fRec2283[0];
			double fRec2282 = (fTemp1018 + (fRec2285 + fTemp1019));
			fRec2280[0] = (fRec2281[0] + fRec2280[1]);
			fRec2278[0] = fRec2280[0];
			double fRec2279 = fRec2282;
			fRec2277[0] = (fTemp1016 + (fTemp1017 + (fRec2279 + fRec2277[1])));
			fRec2275[0] = fRec2277[0];
			double fRec2276 = (fTemp1016 + (fRec2279 + fTemp1017));
			fRec2274[0] = (fRec2275[0] + fRec2274[1]);
			fRec2272[0] = fRec2274[0];
			double fRec2273 = fRec2276;
			double fTemp1023 = (fConst254 * fRec2290[1]);
			double fTemp1024 = (fConst256 * fRec2293[1]);
			double fTemp1025 = (fConst257 * fRec2296[1]);
			double fTemp1026 = (fConst259 * (((((0.031650208800000003 * fTemp38) + (0.017592697000000001 * fTemp42)) + (0.0040021539000000004 * fTemp43)) + (0.0045475836999999998 * fTemp45)) - ((0.041919655299999997 * fTemp47) + (((0.0259878066 * fTemp44) + ((0.0004232808 * fTemp41) + (((0.1082578573 * fTemp37) + (0.0076914011000000001 * fTemp39)) + (0.020914834300000001 * fTemp40)))) + (0.1012375878 * fTemp46)))));
			double fTemp1027 = (fConst260 * fRec2299[1]);
			double fTemp1028 = (fConst261 * fRec2302[1]);
			fRec2304[0] = (fTemp1026 + (fTemp1027 + (fRec2304[1] + fTemp1028)));
			fRec2302[0] = fRec2304[0];
			double fRec2303 = ((fTemp1028 + fTemp1027) + fTemp1026);
			fRec2301[0] = (fRec2302[0] + fRec2301[1]);
			fRec2299[0] = fRec2301[0];
			double fRec2300 = fRec2303;
			fRec2298[0] = (fTemp1024 + (fTemp1025 + (fRec2300 + fRec2298[1])));
			fRec2296[0] = fRec2298[0];
			double fRec2297 = (fTemp1024 + (fRec2300 + fTemp1025));
			fRec2295[0] = (fRec2296[0] + fRec2295[1]);
			fRec2293[0] = fRec2295[0];
			double fRec2294 = fRec2297;
			fRec2292[0] = (fTemp1023 + (fRec2294 + fRec2292[1]));
			fRec2290[0] = fRec2292[0];
			double fRec2291 = (fRec2294 + fTemp1023);
			double fTemp1029 = (fConst263 * fRec2305[1]);
			double fTemp1030 = (fConst264 * fRec2308[1]);
			double fTemp1031 = (fConst266 * ((((0.0012697062000000001 * fTemp56) + (0.0018758177999999999 * fTemp55)) + (0.1142017021 * fTemp61)) - ((0.023872140600000001 * fTemp60) + ((0.0063737823000000002 * fTemp59) + ((((0.034883829399999997 * fTemp53) + (0.1031606028 * fTemp54)) + (0.043886616099999998 * fTemp57)) + (0.0033480034000000001 * fTemp58))))));
			double fTemp1032 = (fConst267 * fRec2311[1]);
			double fTemp1033 = (fConst268 * fRec2314[1]);
			fRec2316[0] = (fTemp1031 + (fTemp1032 + (fRec2316[1] + fTemp1033)));
			fRec2314[0] = fRec2316[0];
			double fRec2315 = ((fTemp1033 + fTemp1032) + fTemp1031);
			fRec2313[0] = (fRec2314[0] + fRec2313[1]);
			fRec2311[0] = fRec2313[0];
			double fRec2312 = fRec2315;
			fRec2310[0] = (fTemp1029 + (fTemp1030 + (fRec2312 + fRec2310[1])));
			fRec2308[0] = fRec2310[0];
			double fRec2309 = (fTemp1029 + (fRec2312 + fTemp1030));
			fRec2307[0] = (fRec2308[0] + fRec2307[1]);
			fRec2305[0] = fRec2307[0];
			double fRec2306 = fRec2309;
			double fTemp1034 = (fConst270 * fRec2317[1]);
			double fTemp1035 = (fConst272 * (((0.025776243099999999 * fTemp72) + ((0.097185107199999995 * fTemp68) + ((((0.1137008253 * fTemp66) + (0.011294923700000001 * fTemp69)) + (0.045081476199999998 * fTemp70)) + (0.00072731870000000004 * fTemp71)))) - (0.014852952799999999 * fTemp67)));
			double fTemp1036 = (fConst273 * fRec2320[1]);
			double fTemp1037 = (fConst274 * fRec2323[1]);
			fRec2325[0] = (fTemp1035 + (fTemp1036 + (fRec2325[1] + fTemp1037)));
			fRec2323[0] = fRec2325[0];
			double fRec2324 = ((fTemp1037 + fTemp1036) + fTemp1035);
			fRec2322[0] = (fRec2323[0] + fRec2322[1]);
			fRec2320[0] = fRec2322[0];
			double fRec2321 = fRec2324;
			fRec2319[0] = (fTemp1034 + (fRec2321 + fRec2319[1]));
			fRec2317[0] = fRec2319[0];
			double fRec2318 = (fRec2321 + fTemp1034);
			double fTemp1038 = (fConst276 * (0.0 - (((0.0849192104 * fTemp76) + (0.0381146708 * fTemp77)) + (0.0063509984000000002 * fTemp78))));
			double fTemp1039 = (fConst277 * fRec2326[1]);
			fRec2328[0] = (fTemp1038 + (fRec2328[1] + fTemp1039));
			fRec2326[0] = fRec2328[0];
			double fRec2327 = (fTemp1039 + fTemp1038);
			double fTemp1040 = (fConst279 * ((((0.015736912499999998 * fTemp81) + (0.081553025599999995 * fTemp82)) + (0.0061961741999999997 * fTemp83)) - ((0.0264817496 * fTemp85) + (0.1048513973 * fTemp84))));
			double fTemp1041 = (fConst280 * fRec2329[1]);
			double fTemp1042 = (fConst281 * fRec2332[1]);
			fRec2334[0] = (fTemp1040 + (fTemp1041 + (fRec2334[1] + fTemp1042)));
			fRec2332[0] = fRec2334[0];
			double fRec2333 = ((fTemp1042 + fTemp1041) + fTemp1040);
			fRec2331[0] = (fRec2332[0] + fRec2331[1]);
			fRec2329[0] = fRec2331[0];
			double fRec2330 = fRec2333;
			fVec34[(IOTA & 511)] = (((0.0472153461 * fTemp97) + ((0.080657041400000004 * fTemp96) + ((0.0048138673 * fTemp9) + ((0.026415544700000002 * fTemp10) + ((0.00058703620000000005 * fTemp11) + ((0.016269063899999998 * fTemp95) + ((0.0097436970000000008 * fTemp12) + ((0.0229882543 * fTemp94) + ((0.083799274600000001 * fTemp90) + ((0.033276484600000003 * fTemp13) + (fRec2273 + (fRec2291 + (fRec2306 + (fRec2318 + (fRec2327 + fRec2330))))))))))))))) - ((0.010661955900000001 * fTemp7) + (((((0.039303916100000003 * fTemp91) + (0.024775007000000002 * fTemp92)) + (3.67876e-05 * fTemp93)) + (0.0040552378 * fTemp89)) + (0.0001798413 * fTemp8))));
			output35[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec34[((IOTA - iConst282) & 511)])));
			double fTemp1043 = (fConst284 * fRec2335[1]);
			double fTemp1044 = (fConst285 * fRec2338[1]);
			double fTemp1045 = (fConst287 * fRec2341[1]);
			double fTemp1046 = (fConst288 * fRec2344[1]);
			double fTemp1047 = (fConst290 * (((0.10125447479999999 * fTemp30) + (((((0.023574145500000001 * fTemp19) + (((0.037350570100000001 * fTemp25) + (0.0019224479 * fTemp27)) + (0.012576003400000001 * fTemp28))) + (0.011868766100000001 * fTemp21)) + (0.0113430224 * fTemp23)) + (0.072869315800000001 * fTemp29))) - (((((0.068832252999999996 * fTemp18) + (0.023595615800000001 * fTemp26)) + (0.0078754585999999994 * fTemp20)) + (0.0095360089000000002 * fTemp22)) + (0.0073147191000000004 * fTemp24))));
			double fTemp1048 = (fConst291 * fRec2347[1]);
			double fTemp1049 = (fConst292 * fRec2350[1]);
			fRec2352[0] = (fTemp1047 + (fTemp1048 + (fRec2352[1] + fTemp1049)));
			fRec2350[0] = fRec2352[0];
			double fRec2351 = ((fTemp1049 + fTemp1048) + fTemp1047);
			fRec2349[0] = (fRec2350[0] + fRec2349[1]);
			fRec2347[0] = fRec2349[0];
			double fRec2348 = fRec2351;
			fRec2346[0] = (fTemp1045 + (fTemp1046 + (fRec2348 + fRec2346[1])));
			fRec2344[0] = fRec2346[0];
			double fRec2345 = (fTemp1045 + (fRec2348 + fTemp1046));
			fRec2343[0] = (fRec2344[0] + fRec2343[1]);
			fRec2341[0] = fRec2343[0];
			double fRec2342 = fRec2345;
			fRec2340[0] = (fTemp1043 + (fTemp1044 + (fRec2342 + fRec2340[1])));
			fRec2338[0] = fRec2340[0];
			double fRec2339 = (fTemp1043 + (fRec2342 + fTemp1044));
			fRec2337[0] = (fRec2338[0] + fRec2337[1]);
			fRec2335[0] = fRec2337[0];
			double fRec2336 = fRec2339;
			double fTemp1050 = (fConst294 * fRec2353[1]);
			double fTemp1051 = (fConst296 * fRec2356[1]);
			double fTemp1052 = (fConst297 * fRec2359[1]);
			double fTemp1053 = (fConst299 * (((0.0303990396 * fTemp46) + (((((0.079335644999999996 * fTemp37) + (0.10163163460000001 * fTemp38)) + (0.0029942836000000001 * fTemp42)) + (0.021145309399999999 * fTemp43)) + (0.0178785105 * fTemp45))) - (((0.015704019900000001 * fTemp44) + ((0.0034303630000000001 * fTemp41) + ((0.0069542991999999998 * fTemp39) + (0.0209735411 * fTemp40)))) + (0.084753137199999995 * fTemp47))));
			double fTemp1054 = (fConst300 * fRec2362[1]);
			double fTemp1055 = (fConst301 * fRec2365[1]);
			fRec2367[0] = (fTemp1053 + (fTemp1054 + (fRec2367[1] + fTemp1055)));
			fRec2365[0] = fRec2367[0];
			double fRec2366 = ((fTemp1055 + fTemp1054) + fTemp1053);
			fRec2364[0] = (fRec2365[0] + fRec2364[1]);
			fRec2362[0] = fRec2364[0];
			double fRec2363 = fRec2366;
			fRec2361[0] = (fTemp1051 + (fTemp1052 + (fRec2363 + fRec2361[1])));
			fRec2359[0] = fRec2361[0];
			double fRec2360 = (fTemp1051 + (fRec2363 + fTemp1052));
			fRec2358[0] = (fRec2359[0] + fRec2358[1]);
			fRec2356[0] = fRec2358[0];
			double fRec2357 = fRec2360;
			fRec2355[0] = (fTemp1050 + (fRec2357 + fRec2355[1]));
			fRec2353[0] = fRec2355[0];
			double fRec2354 = (fRec2357 + fTemp1050);
			double fTemp1056 = (fConst303 * fRec2368[1]);
			double fTemp1057 = (fConst304 * fRec2371[1]);
			double fTemp1058 = (fConst306 * (((0.0052216312999999997 * fTemp56) + (0.0019288978 * fTemp55)) - ((0.0338739947 * fTemp61) + ((0.1042714064 * fTemp60) + ((0.0037685707 * fTemp59) + ((((0.1145178768 * fTemp53) + (0.018450642699999999 * fTemp54)) + (0.039361826699999998 * fTemp57)) + (0.019766645699999998 * fTemp58)))))));
			double fTemp1059 = (fConst307 * fRec2374[1]);
			double fTemp1060 = (fConst308 * fRec2377[1]);
			fRec2379[0] = (fTemp1058 + (fTemp1059 + (fRec2379[1] + fTemp1060)));
			fRec2377[0] = fRec2379[0];
			double fRec2378 = ((fTemp1060 + fTemp1059) + fTemp1058);
			fRec2376[0] = (fRec2377[0] + fRec2376[1]);
			fRec2374[0] = fRec2376[0];
			double fRec2375 = fRec2378;
			fRec2373[0] = (fTemp1056 + (fTemp1057 + (fRec2375 + fRec2373[1])));
			fRec2371[0] = fRec2373[0];
			double fRec2372 = (fTemp1056 + (fRec2375 + fTemp1057));
			fRec2370[0] = (fRec2371[0] + fRec2370[1]);
			fRec2368[0] = fRec2370[0];
			double fRec2369 = fRec2372;
			double fTemp1061 = (fConst310 * fRec2380[1]);
			double fTemp1062 = (fConst312 * (((0.11477953809999999 * fTemp72) + ((0.058753453300000001 * fTemp68) + ((((0.0205387338 * fTemp66) + (0.010182545499999999 * fTemp69)) + (0.0450816551 * fTemp70)) + (0.0050588908000000002 * fTemp71)))) - (0.078819765700000002 * fTemp67)));
			double fTemp1063 = (fConst313 * fRec2383[1]);
			double fTemp1064 = (fConst314 * fRec2386[1]);
			fRec2388[0] = (fTemp1062 + (fTemp1063 + (fRec2388[1] + fTemp1064)));
			fRec2386[0] = fRec2388[0];
			double fRec2387 = ((fTemp1064 + fTemp1063) + fTemp1062);
			fRec2385[0] = (fRec2386[0] + fRec2385[1]);
			fRec2383[0] = fRec2385[0];
			double fRec2384 = fRec2387;
			fRec2382[0] = (fTemp1061 + (fRec2384 + fRec2382[1]));
			fRec2380[0] = fRec2382[0];
			double fRec2381 = (fRec2384 + fTemp1061);
			double fTemp1065 = (fConst316 * (0.0 - (((0.076137318100000004 * fTemp76) + (0.0381082248 * fTemp77)) + (0.038158428899999999 * fTemp78))));
			double fTemp1066 = (fConst317 * fRec2389[1]);
			fRec2391[0] = (fTemp1065 + (fRec2391[1] + fTemp1066));
			fRec2389[0] = fRec2391[0];
			double fRec2390 = (fTemp1066 + fTemp1065);
			double fTemp1067 = (fConst319 * ((((0.084949829399999996 * fTemp81) + (0.073090824900000004 * fTemp82)) + (0.036674009200000003 * fTemp83)) - ((0.026502758899999999 * fTemp85) + (0.063467089099999999 * fTemp84))));
			double fTemp1068 = (fConst320 * fRec2392[1]);
			double fTemp1069 = (fConst321 * fRec2395[1]);
			fRec2397[0] = (fTemp1067 + (fTemp1068 + (fRec2397[1] + fTemp1069)));
			fRec2395[0] = fRec2397[0];
			double fRec2396 = ((fTemp1069 + fTemp1068) + fTemp1067);
			fRec2394[0] = (fRec2395[0] + fRec2394[1]);
			fRec2392[0] = fRec2394[0];
			double fRec2393 = fRec2396;
			fVec35[(IOTA & 511)] = (((0.0231034003 * fTemp9) + ((0.015948586399999999 * fTemp10) + ((0.0042937493 * fTemp11) + ((0.0162834242 * fTemp95) + ((0.0087349816000000004 * fTemp12) + ((0.0043110222000000004 * fTemp94) + ((0.000185637 * fTemp93) + (((0.033278067699999997 * fTemp13) + (fRec2336 + (fRec2354 + (fRec2369 + (fRec2381 + (fRec2390 + fRec2393)))))) + (0.018763965000000001 * fTemp92))))))))) - ((0.0107405322 * fTemp97) + ((0.084383888399999996 * fTemp96) + ((0.0193768411 * fTemp7) + ((((0.095552286400000006 * fTemp90) + (0.030503717999999999 * fTemp91)) + (0.0215012443 * fTemp89)) + (6.8140999999999997e-05 * fTemp8))))));
			output36[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec35[((IOTA - iConst322) & 511)])));
			double fTemp1070 = (fConst244 * fRec2398[1]);
			double fTemp1071 = (fConst245 * fRec2401[1]);
			double fTemp1072 = (fConst247 * fRec2404[1]);
			double fTemp1073 = (fConst248 * fRec2407[1]);
			double fTemp1074 = (fConst250 * (((0.0059574155000000004 * fTemp23) + ((0.0020745647999999999 * fTemp22) + (((0.017136667299999998 * fTemp19) + ((0.0079298113000000007 * fTemp26) + (0.015671909000000001 * fTemp28))) + (0.0200021908 * fTemp21)))) - ((0.046252245099999999 * fTemp30) + ((0.092061757699999996 * fTemp29) + (((((0.097569518899999999 * fTemp25) + (0.039643944799999997 * fTemp18)) + (0.0097468642000000001 * fTemp27)) + (0.0078643944000000004 * fTemp20)) + (0.0234356036 * fTemp24))))));
			double fTemp1075 = (fConst251 * fRec2410[1]);
			double fTemp1076 = (fConst252 * fRec2413[1]);
			fRec2415[0] = (fTemp1074 + (fTemp1075 + (fRec2415[1] + fTemp1076)));
			fRec2413[0] = fRec2415[0];
			double fRec2414 = ((fTemp1076 + fTemp1075) + fTemp1074);
			fRec2412[0] = (fRec2413[0] + fRec2412[1]);
			fRec2410[0] = fRec2412[0];
			double fRec2411 = fRec2414;
			fRec2409[0] = (fTemp1072 + (fTemp1073 + (fRec2411 + fRec2409[1])));
			fRec2407[0] = fRec2409[0];
			double fRec2408 = (fTemp1072 + (fRec2411 + fTemp1073));
			fRec2406[0] = (fRec2407[0] + fRec2406[1]);
			fRec2404[0] = fRec2406[0];
			double fRec2405 = fRec2408;
			fRec2403[0] = (fTemp1070 + (fTemp1071 + (fRec2405 + fRec2403[1])));
			fRec2401[0] = fRec2403[0];
			double fRec2402 = (fTemp1070 + (fRec2405 + fTemp1071));
			fRec2400[0] = (fRec2401[0] + fRec2400[1]);
			fRec2398[0] = fRec2400[0];
			double fRec2399 = fRec2402;
			double fTemp1077 = (fConst254 * fRec2416[1]);
			double fTemp1078 = (fConst256 * fRec2419[1]);
			double fTemp1079 = (fConst257 * fRec2422[1]);
			double fTemp1080 = (fConst259 * (((0.1062583351 * fTemp47) + ((0.10123153999999999 * fTemp46) + ((0.0092629765000000006 * fTemp45) + (((0.046837363100000001 * fTemp37) + (0.025946591099999999 * fTemp43)) + (0.0040276803000000002 * fTemp44))))) - ((0.0057918522000000002 * fTemp41) + ((((0.031683004600000002 * fTemp38) + (0.015634270499999998 * fTemp42)) + (0.0051694970999999999 * fTemp39)) + (0.020943918200000002 * fTemp40)))));
			double fTemp1081 = (fConst260 * fRec2425[1]);
			double fTemp1082 = (fConst261 * fRec2428[1]);
			fRec2430[0] = (fTemp1080 + (fTemp1081 + (fRec2430[1] + fTemp1082)));
			fRec2428[0] = fRec2430[0];
			double fRec2429 = ((fTemp1082 + fTemp1081) + fTemp1080);
			fRec2427[0] = (fRec2428[0] + fRec2427[1]);
			fRec2425[0] = fRec2427[0];
			double fRec2426 = fRec2429;
			fRec2424[0] = (fTemp1078 + (fTemp1079 + (fRec2426 + fRec2424[1])));
			fRec2422[0] = fRec2424[0];
			double fRec2423 = (fTemp1078 + (fRec2426 + fTemp1079));
			fRec2421[0] = (fRec2422[0] + fRec2421[1]);
			fRec2419[0] = fRec2421[0];
			double fRec2420 = fRec2423;
			fRec2418[0] = (fTemp1077 + (fRec2420 + fRec2418[1]));
			fRec2416[0] = fRec2418[0];
			double fRec2417 = (fRec2420 + fTemp1077);
			double fTemp1083 = (fConst263 * fRec2431[1]);
			double fTemp1084 = (fConst264 * fRec2434[1]);
			double fTemp1085 = (fConst266 * ((((((0.034963300500000002 * fTemp53) + (0.089837350799999993 * fTemp54)) + (0.0063732414999999997 * fTemp56)) + (0.0019300965 * fTemp55)) + (0.0012383120999999999 * fTemp59)) - ((0.114204951 * fTemp61) + (((0.0286306445 * fTemp57) + (0.033378283699999997 * fTemp58)) + (0.056046316999999998 * fTemp60)))));
			double fTemp1086 = (fConst267 * fRec2437[1]);
			double fTemp1087 = (fConst268 * fRec2440[1]);
			fRec2442[0] = (fTemp1085 + (fTemp1086 + (fRec2442[1] + fTemp1087)));
			fRec2440[0] = fRec2442[0];
			double fRec2441 = ((fTemp1087 + fTemp1086) + fTemp1085);
			fRec2439[0] = (fRec2440[0] + fRec2439[1]);
			fRec2437[0] = fRec2439[0];
			double fRec2438 = fRec2441;
			fRec2436[0] = (fTemp1083 + (fTemp1084 + (fRec2438 + fRec2436[1])));
			fRec2434[0] = fRec2436[0];
			double fRec2435 = (fTemp1083 + (fRec2438 + fTemp1084));
			fRec2433[0] = (fRec2434[0] + fRec2433[1]);
			fRec2431[0] = fRec2433[0];
			double fRec2432 = fRec2435;
			double fTemp1088 = (fConst270 * fRec2443[1]);
			double fTemp1089 = (fConst272 * (((((0.0074615742000000004 * fTemp69) + (0.045040590800000002 * fTemp70)) + (0.0085114636999999993 * fTemp71)) + (0.062137674699999999 * fTemp72)) - (((0.098670418100000004 * fTemp66) + (0.097180163299999997 * fTemp67)) + (0.014864069800000001 * fTemp68))));
			double fTemp1090 = (fConst273 * fRec2446[1]);
			double fTemp1091 = (fConst274 * fRec2449[1]);
			fRec2451[0] = (fTemp1089 + (fTemp1090 + (fRec2451[1] + fTemp1091)));
			fRec2449[0] = fRec2451[0];
			double fRec2450 = ((fTemp1091 + fTemp1090) + fTemp1089);
			fRec2448[0] = (fRec2449[0] + fRec2448[1]);
			fRec2446[0] = fRec2448[0];
			double fRec2447 = fRec2450;
			fRec2445[0] = (fTemp1088 + (fRec2447 + fRec2445[1]));
			fRec2443[0] = fRec2445[0];
			double fRec2444 = (fRec2447 + fTemp1088);
			double fTemp1092 = (fConst276 * (0.0 - (((0.055553733899999999 * fTemp76) + (0.038125752300000003 * fTemp77)) + (0.064552007999999994 * fTemp78))));
			double fTemp1093 = (fConst277 * fRec2452[1]);
			fRec2454[0] = (fTemp1092 + (fRec2454[1] + fTemp1093));
			fRec2452[0] = fRec2454[0];
			double fRec2453 = (fTemp1093 + fTemp1092);
			double fTemp1094 = (fConst279 * (((((0.1048604267 * fTemp81) + (0.0532821084 * fTemp82)) + (0.062049975399999999 * fTemp83)) + (0.015769035099999999 * fTemp84)) - (0.026465696600000001 * fTemp85)));
			double fTemp1095 = (fConst280 * fRec2455[1]);
			double fTemp1096 = (fConst281 * fRec2458[1]);
			fRec2460[0] = (fTemp1094 + (fTemp1095 + (fRec2460[1] + fTemp1096)));
			fRec2458[0] = fRec2460[0];
			double fRec2459 = ((fTemp1096 + fTemp1095) + fTemp1094);
			fRec2457[0] = (fRec2458[0] + fRec2457[1]);
			fRec2455[0] = fRec2457[0];
			double fRec2456 = fRec2459;
			fVec36[(IOTA & 511)] = (((0.0393384856 * fTemp96) + ((0.025070627700000001 * fTemp7) + ((0.00026725719999999998 * fTemp8) + ((0.0128795187 * fTemp9) + ((0.0072882902999999999 * fTemp11) + ((0.0162231852 * fTemp95) + ((0.0064764256000000003 * fTemp12) + ((7.6892799999999997e-05 * fTemp93) + ((0.010038106 * fTemp92) + ((0.080647129400000003 * fTemp91) + ((0.092713472899999996 * fTemp90) + ((0.033283175399999997 * fTemp13) + (fRec2399 + (fRec2417 + (fRec2432 + (fRec2444 + (fRec2453 + fRec2456))))))))))))))))) - ((((0.019700730400000002 * fTemp94) + (0.0264154505 * fTemp89)) + (0.0040980239 * fTemp10)) + (0.0257833796 * fTemp97)));
			output37[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec36[((IOTA - iConst282) & 511)])));
			double fTemp1097 = (fConst284 * fRec2461[1]);
			double fTemp1098 = (fConst285 * fRec2464[1]);
			double fTemp1099 = (fConst287 * fRec2467[1]);
			double fTemp1100 = (fConst288 * fRec2470[1]);
			double fTemp1101 = (fConst290 * ((((0.0125471882 * fTemp22) + (((0.0082971303000000003 * fTemp19) + ((((0.10122433240000001 * fTemp25) + (0.1002244189 * fTemp18)) + (0.0236254311 * fTemp26)) + (0.0094898741999999998 * fTemp28))) + (0.0250270509 * fTemp21))) + (0.0074500028000000001 * fTemp24)) - ((0.037391474600000002 * fTemp30) + ((((0.0094456321999999999 * fTemp27) + (0.0078706125000000005 * fTemp20)) + (0.0065643063999999999 * fTemp23)) + (0.0028217150999999998 * fTemp29)))));
			double fTemp1102 = (fConst291 * fRec2473[1]);
			double fTemp1103 = (fConst292 * fRec2476[1]);
			fRec2478[0] = (fTemp1101 + (fTemp1102 + (fRec2478[1] + fTemp1103)));
			fRec2476[0] = fRec2478[0];
			double fRec2477 = ((fTemp1103 + fTemp1102) + fTemp1101);
			fRec2475[0] = (fRec2476[0] + fRec2475[1]);
			fRec2473[0] = fRec2475[0];
			double fRec2474 = fRec2477;
			fRec2472[0] = (fTemp1099 + (fTemp1100 + (fRec2474 + fRec2472[1])));
			fRec2470[0] = fRec2472[0];
			double fRec2471 = (fTemp1099 + (fRec2474 + fTemp1100));
			fRec2469[0] = (fRec2470[0] + fRec2469[1]);
			fRec2467[0] = fRec2469[0];
			double fRec2468 = fRec2471;
			fRec2466[0] = (fTemp1097 + (fTemp1098 + (fRec2468 + fRec2466[1])));
			fRec2464[0] = fRec2466[0];
			double fRec2465 = (fTemp1097 + (fRec2468 + fTemp1098));
			fRec2463[0] = (fRec2464[0] + fRec2463[1]);
			fRec2461[0] = fRec2463[0];
			double fRec2462 = fRec2465;
			double fTemp1104 = (fConst294 * fRec2479[1]);
			double fTemp1105 = (fConst296 * fRec2482[1]);
			double fTemp1106 = (fConst297 * fRec2485[1]);
			double fTemp1107 = (fConst299 * ((((0.015761323599999998 * fTemp43) + (0.0211084481 * fTemp44)) + (0.0038560119000000002 * fTemp47)) - ((0.030452232900000001 * fTemp46) + (((0.0072634246999999999 * fTemp41) + (((((0.11599028290000001 * fTemp37) + (0.1016397165 * fTemp38)) + (0.0147558584 * fTemp42)) + (0.0024743522 * fTemp39)) + (0.020954784000000001 * fTemp40))) + (0.010654657 * fTemp45)))));
			double fTemp1108 = (fConst300 * fRec2488[1]);
			double fTemp1109 = (fConst301 * fRec2491[1]);
			fRec2493[0] = (fTemp1107 + (fTemp1108 + (fRec2493[1] + fTemp1109)));
			fRec2491[0] = fRec2493[0];
			double fRec2492 = ((fTemp1109 + fTemp1108) + fTemp1107);
			fRec2490[0] = (fRec2491[0] + fRec2490[1]);
			fRec2488[0] = fRec2490[0];
			double fRec2489 = fRec2492;
			fRec2487[0] = (fTemp1105 + (fTemp1106 + (fRec2489 + fRec2487[1])));
			fRec2485[0] = fRec2487[0];
			double fRec2486 = (fTemp1105 + (fRec2489 + fTemp1106));
			fRec2484[0] = (fRec2485[0] + fRec2484[1]);
			fRec2482[0] = fRec2484[0];
			double fRec2483 = fRec2486;
			fRec2481[0] = (fTemp1104 + (fRec2483 + fRec2481[1]));
			fRec2479[0] = fRec2481[0];
			double fRec2480 = (fRec2483 + fTemp1104);
			double fTemp1110 = (fConst303 * fRec2494[1]);
			double fTemp1111 = (fConst304 * fRec2497[1]);
			double fTemp1112 = (fConst306 * (((0.033852430099999997 * fTemp61) + ((0.060739800199999999 * fTemp60) + (((((0.11446973990000001 * fTemp53) + (0.086762481799999999 * fTemp54)) + (0.0037495468000000001 * fTemp56)) + (0.0018638532 * fTemp55)) + (0.0053231116000000004 * fTemp59)))) - ((0.0138807103 * fTemp57) + (0.041821141300000003 * fTemp58))));
			double fTemp1113 = (fConst307 * fRec2500[1]);
			double fTemp1114 = (fConst308 * fRec2503[1]);
			fRec2505[0] = (fTemp1112 + (fTemp1113 + (fRec2505[1] + fTemp1114)));
			fRec2503[0] = fRec2505[0];
			double fRec2504 = ((fTemp1114 + fTemp1113) + fTemp1112);
			fRec2502[0] = (fRec2503[0] + fRec2502[1]);
			fRec2500[0] = fRec2502[0];
			double fRec2501 = fRec2504;
			fRec2499[0] = (fTemp1110 + (fTemp1111 + (fRec2501 + fRec2499[1])));
			fRec2497[0] = fRec2499[0];
			double fRec2498 = (fTemp1110 + (fRec2501 + fTemp1111));
			fRec2496[0] = (fRec2497[0] + fRec2496[1]);
			fRec2494[0] = fRec2496[0];
			double fRec2495 = fRec2498;
			double fTemp1115 = (fConst310 * fRec2506[1]);
			double fTemp1116 = (fConst312 * ((((0.0036356788000000001 * fTemp69) + (0.045101522499999998 * fTemp70)) + (0.010711261600000001 * fTemp71)) - ((0.066610599300000004 * fTemp72) + (((0.095632831200000004 * fTemp66) + (0.058725648499999998 * fTemp67)) + (0.078858663800000006 * fTemp68)))));
			double fTemp1117 = (fConst313 * fRec2509[1]);
			double fTemp1118 = (fConst314 * fRec2512[1]);
			fRec2514[0] = (fTemp1116 + (fTemp1117 + (fRec2514[1] + fTemp1118)));
			fRec2512[0] = fRec2514[0];
			double fRec2513 = ((fTemp1118 + fTemp1117) + fTemp1116);
			fRec2511[0] = (fRec2512[0] + fRec2511[1]);
			fRec2509[0] = fRec2511[0];
			double fRec2510 = fRec2513;
			fRec2508[0] = (fTemp1115 + (fRec2510 + fRec2508[1]));
			fRec2506[0] = fRec2508[0];
			double fRec2507 = (fRec2510 + fTemp1115);
			double fTemp1119 = (fConst316 * (0.0 - (((0.026833309999999999 * fTemp76) + (0.038106907000000002 * fTemp77)) + (0.080781548600000003 * fTemp78))));
			double fTemp1120 = (fConst317 * fRec2515[1]);
			fRec2517[0] = (fTemp1119 + (fRec2517[1] + fTemp1120));
			fRec2515[0] = fRec2517[0];
			double fRec2516 = (fTemp1120 + fTemp1119);
			double fTemp1121 = (fConst319 * (((((0.063424460899999993 * fTemp81) + (0.025729977300000002 * fTemp82)) + (0.077630167700000002 * fTemp83)) + (0.084913400999999999 * fTemp84)) - (0.0264737523 * fTemp85)));
			double fTemp1122 = (fConst320 * fRec2518[1]);
			double fTemp1123 = (fConst321 * fRec2521[1]);
			fRec2523[0] = (fTemp1121 + (fTemp1122 + (fRec2523[1] + fTemp1123)));
			fRec2521[0] = fRec2523[0];
			double fRec2522 = ((fTemp1123 + fTemp1122) + fTemp1121);
			fRec2520[0] = (fRec2521[0] + fRec2520[1]);
			fRec2518[0] = fRec2520[0];
			double fRec2519 = fRec2522;
			fVec37[(IOTA & 511)] = (((0.060036022799999998 * fTemp97) + ((0.0304976886 * fTemp96) + ((0.00032109990000000002 * fTemp7) + ((0.0092586087000000004 * fTemp11) + ((0.016326062299999999 * fTemp95) + (((0.033262025000000001 * fTemp13) + (fRec2462 + (fRec2480 + (fRec2495 + (fRec2507 + (fRec2516 + fRec2519)))))) + (0.0031268797000000002 * fTemp12))))))) - ((7.3554999999999996e-05 * fTemp8) + ((0.0133277433 * fTemp9) + (((((((0.075127645100000001 * fTemp90) + (0.084412457799999993 * fTemp91)) + (0.0270334006 * fTemp92)) + (0.00014850780000000001 * fTemp93)) + (0.019324382099999999 * fTemp94)) + (0.015981281399999998 * fTemp89)) + (0.021489600899999999 * fTemp10)))));
			output38[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec37[((IOTA - iConst322) & 511)])));
			double fTemp1124 = (fConst244 * fRec2524[1]);
			double fTemp1125 = (fConst245 * fRec2527[1]);
			double fTemp1126 = (fConst247 * fRec2530[1]);
			double fTemp1127 = (fConst248 * fRec2533[1]);
			double fTemp1128 = (fConst250 * (((0.097537550200000003 * fTemp30) + ((0.093102855200000001 * fTemp29) + (((0.015707378800000001 * fTemp22) + ((0.0026653355000000002 * fTemp27) + (0.026311358300000001 * fTemp21))) + (0.0233680663 * fTemp24)))) - (((0.0079194244999999993 * fTemp20) + (((((0.046203315699999997 * fTemp25) + (0.037118589200000003 * fTemp18)) + (0.0079546987999999999 * fTemp26)) + (0.0021099268000000001 * fTemp28)) + (0.0020259407000000002 * fTemp19))) + (0.011168592999999999 * fTemp23))));
			double fTemp1129 = (fConst251 * fRec2536[1]);
			double fTemp1130 = (fConst252 * fRec2539[1]);
			fRec2541[0] = (fTemp1128 + (fTemp1129 + (fRec2541[1] + fTemp1130)));
			fRec2539[0] = fRec2541[0];
			double fRec2540 = ((fTemp1130 + fTemp1129) + fTemp1128);
			fRec2538[0] = (fRec2539[0] + fRec2538[1]);
			fRec2536[0] = fRec2538[0];
			double fRec2537 = fRec2540;
			fRec2535[0] = (fTemp1126 + (fTemp1127 + (fRec2537 + fRec2535[1])));
			fRec2533[0] = fRec2535[0];
			double fRec2534 = (fTemp1126 + (fRec2537 + fTemp1127));
			fRec2532[0] = (fRec2533[0] + fRec2532[1]);
			fRec2530[0] = fRec2532[0];
			double fRec2531 = fRec2534;
			fRec2529[0] = (fTemp1124 + (fTemp1125 + (fRec2531 + fRec2529[1])));
			fRec2527[0] = fRec2529[0];
			double fRec2528 = (fTemp1124 + (fRec2531 + fTemp1125));
			fRec2526[0] = (fRec2527[0] + fRec2526[1]);
			fRec2524[0] = fRec2526[0];
			double fRec2525 = fRec2528;
			double fTemp1131 = (fConst254 * fRec2542[1]);
			double fTemp1132 = (fConst256 * fRec2545[1]);
			double fTemp1133 = (fConst257 * fRec2548[1]);
			double fTemp1134 = (fConst259 * ((((((0.0420065705 * fTemp37) + (0.031734005400000001 * fTemp38)) + (0.0045288018999999997 * fTemp42)) + (0.0004477571 * fTemp39)) + (0.025992383500000001 * fTemp44)) - ((0.1082450573 * fTemp47) + ((0.1012038358 * fTemp46) + (((0.0078250448 * fTemp41) + ((0.0040178536999999999 * fTemp43) + (0.020957919299999999 * fTemp40))) + (0.0175188184 * fTemp45))))));
			double fTemp1135 = (fConst260 * fRec2551[1]);
			double fTemp1136 = (fConst261 * fRec2554[1]);
			fRec2556[0] = (fTemp1134 + (fTemp1135 + (fRec2556[1] + fTemp1136)));
			fRec2554[0] = fRec2556[0];
			double fRec2555 = ((fTemp1136 + fTemp1135) + fTemp1134);
			fRec2553[0] = (fRec2554[0] + fRec2553[1]);
			fRec2551[0] = fRec2553[0];
			double fRec2552 = fRec2555;
			fRec2550[0] = (fTemp1132 + (fTemp1133 + (fRec2552 + fRec2550[1])));
			fRec2548[0] = fRec2550[0];
			double fRec2549 = (fTemp1132 + (fRec2552 + fTemp1133));
			fRec2547[0] = (fRec2548[0] + fRec2547[1]);
			fRec2545[0] = fRec2547[0];
			double fRec2546 = fRec2549;
			fRec2544[0] = (fTemp1131 + (fRec2546 + fRec2544[1]));
			fRec2542[0] = fRec2544[0];
			double fRec2543 = (fRec2546 + fTemp1131);
			double fTemp1137 = (fConst263 * fRec2557[1]);
			double fTemp1138 = (fConst264 * fRec2560[1]);
			double fTemp1139 = (fConst266 * (((0.11421576949999999 * fTemp61) + ((0.1031277446 * fTemp60) + (((0.0033561705000000001 * fTemp57) + (0.0019767729999999998 * fTemp55)) + (0.0062842743 * fTemp59)))) - ((((0.034976159299999997 * fTemp53) + (0.0239379552 * fTemp54)) + (0.0012555685 * fTemp56)) + (0.043866424299999998 * fTemp58))));
			double fTemp1140 = (fConst267 * fRec2563[1]);
			double fTemp1141 = (fConst268 * fRec2566[1]);
			fRec2568[0] = (fTemp1139 + (fTemp1140 + (fRec2568[1] + fTemp1141)));
			fRec2566[0] = fRec2568[0];
			double fRec2567 = ((fTemp1141 + fTemp1140) + fTemp1139);
			fRec2565[0] = (fRec2566[0] + fRec2565[1]);
			fRec2563[0] = fRec2565[0];
			double fRec2564 = fRec2567;
			fRec2562[0] = (fTemp1137 + (fTemp1138 + (fRec2564 + fRec2562[1])));
			fRec2560[0] = fRec2562[0];
			double fRec2561 = (fTemp1137 + (fRec2564 + fTemp1138));
			fRec2559[0] = (fRec2560[0] + fRec2559[1]);
			fRec2557[0] = fRec2559[0];
			double fRec2558 = fRec2561;
			double fTemp1142 = (fConst270 * fRec2569[1]);
			double fTemp1143 = (fConst272 * (((((0.025854279399999999 * fTemp66) + (0.0148955627 * fTemp67)) + (0.045049513100000001 * fTemp70)) + (0.0113706473 * fTemp71)) - ((0.11373347 * fTemp72) + ((0.00073515950000000005 * fTemp69) + (0.097154645900000003 * fTemp68)))));
			double fTemp1144 = (fConst273 * fRec2572[1]);
			double fTemp1145 = (fConst274 * fRec2575[1]);
			fRec2577[0] = (fTemp1143 + (fTemp1144 + (fRec2577[1] + fTemp1145)));
			fRec2575[0] = fRec2577[0];
			double fRec2576 = ((fTemp1145 + fTemp1144) + fTemp1143);
			fRec2574[0] = (fRec2575[0] + fRec2574[1]);
			fRec2572[0] = fRec2574[0];
			double fRec2573 = fRec2576;
			fRec2571[0] = (fTemp1142 + (fRec2573 + fRec2571[1]));
			fRec2569[0] = fRec2571[0];
			double fRec2570 = (fRec2573 + fTemp1142);
			double fTemp1146 = (fConst276 * ((0.0063723464999999998 * fTemp76) - ((0.038111018900000002 * fTemp77) + (0.084951557600000005 * fTemp78))));
			double fTemp1147 = (fConst277 * fRec2578[1]);
			fRec2580[0] = (fTemp1146 + (fRec2580[1] + fTemp1147));
			fRec2578[0] = fRec2580[0];
			double fRec2579 = (fTemp1147 + fTemp1146);
			double fTemp1148 = (fConst279 * (((0.081531368000000007 * fTemp83) + (0.1048899032 * fTemp84)) - (((0.015788099199999999 * fTemp81) + (0.0062148454000000002 * fTemp82)) + (0.026511586 * fTemp85))));
			double fTemp1149 = (fConst280 * fRec2581[1]);
			double fTemp1150 = (fConst281 * fRec2584[1]);
			fRec2586[0] = (fTemp1148 + (fTemp1149 + (fRec2586[1] + fTemp1150)));
			fRec2584[0] = fRec2586[0];
			double fRec2585 = ((fTemp1150 + fTemp1149) + fTemp1148);
			fRec2583[0] = (fRec2584[0] + fRec2583[1]);
			fRec2581[0] = fRec2583[0];
			double fRec2582 = fRec2585;
			fVec38[(IOTA & 511)] = (((0.0097544845000000005 * fTemp11) + ((0.016264290000000001 * fTemp95) + ((0.0041236642 * fTemp89) + ((0.0048921104 * fTemp94) + ((0.0106568093 * fTemp92) + ((0.039391791799999999 * fTemp91) + ((0.047225813700000001 * fTemp90) + ((0.033288936200000001 * fTemp13) + (fRec2525 + (fRec2543 + (fRec2558 + (fRec2570 + (fRec2579 + fRec2582))))))))))))) - ((0.083741243300000004 * fTemp97) + ((0.080620404800000003 * fTemp96) + ((0.0247876416 * fTemp7) + ((0.00019956950000000001 * fTemp8) + ((0.023023232599999999 * fTemp9) + (((7.4733400000000005e-05 * fTemp93) + (0.00060973509999999996 * fTemp12)) + (0.026437773899999999 * fTemp10))))))));
			output39[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec38[((IOTA - iConst282) & 511)])));
			double fTemp1151 = (fConst284 * fRec2587[1]);
			double fTemp1152 = (fConst285 * fRec2590[1]);
			double fTemp1153 = (fConst287 * fRec2593[1]);
			double fTemp1154 = (fConst288 * fRec2596[1]);
			double fTemp1155 = (fConst290 * (((0.0095689811999999999 * fTemp22) + ((0.0113295685 * fTemp27) + (0.0234998506 * fTemp21))) - ((0.10125006509999999 * fTemp30) + ((0.068856405199999998 * fTemp29) + ((0.0073770564 * fTemp24) + (((0.0079224800000000008 * fTemp20) + (((((0.037410189199999999 * fTemp25) + (0.072857871800000001 * fTemp18)) + (0.023562477700000001 * fTemp26)) + (0.0125620132 * fTemp28)) + (0.011813337 * fTemp19))) + (0.0019342687999999999 * fTemp23)))))));
			double fTemp1156 = (fConst291 * fRec2599[1]);
			double fTemp1157 = (fConst292 * fRec2602[1]);
			fRec2604[0] = (fTemp1155 + (fTemp1156 + (fRec2604[1] + fTemp1157)));
			fRec2602[0] = fRec2604[0];
			double fRec2603 = ((fTemp1157 + fTemp1156) + fTemp1155);
			fRec2601[0] = (fRec2602[0] + fRec2601[1]);
			fRec2599[0] = fRec2601[0];
			double fRec2600 = fRec2603;
			fRec2598[0] = (fTemp1153 + (fTemp1154 + (fRec2600 + fRec2598[1])));
			fRec2596[0] = fRec2598[0];
			double fRec2597 = (fTemp1153 + (fRec2600 + fTemp1154));
			fRec2595[0] = (fRec2596[0] + fRec2595[1]);
			fRec2593[0] = fRec2595[0];
			double fRec2594 = fRec2597;
			fRec2592[0] = (fTemp1151 + (fTemp1152 + (fRec2594 + fRec2592[1])));
			fRec2590[0] = fRec2592[0];
			double fRec2591 = (fTemp1151 + (fRec2594 + fTemp1152));
			fRec2589[0] = (fRec2590[0] + fRec2589[1]);
			fRec2587[0] = fRec2589[0];
			double fRec2588 = fRec2591;
			double fTemp1158 = (fConst294 * fRec2605[1]);
			double fTemp1159 = (fConst296 * fRec2608[1]);
			double fTemp1160 = (fConst297 * fRec2611[1]);
			double fTemp1161 = (fConst299 * (((0.079312063700000004 * fTemp47) + ((((((0.084794564599999997 * fTemp37) + (0.10161841420000001 * fTemp38)) + (0.017872488999999998 * fTemp42)) + (0.0034022102000000002 * fTemp39)) + (0.0156948461 * fTemp44)) + (0.0304225828 * fTemp46))) - (((0.0069500370000000001 * fTemp41) + ((0.0211301287 * fTemp43) + (0.020923185600000001 * fTemp40))) + (0.0029388359999999998 * fTemp45))));
			double fTemp1162 = (fConst300 * fRec2614[1]);
			double fTemp1163 = (fConst301 * fRec2617[1]);
			fRec2619[0] = (fTemp1161 + (fTemp1162 + (fRec2619[1] + fTemp1163)));
			fRec2617[0] = fRec2619[0];
			double fRec2618 = ((fTemp1163 + fTemp1162) + fTemp1161);
			fRec2616[0] = (fRec2617[0] + fRec2616[1]);
			fRec2614[0] = fRec2616[0];
			double fRec2615 = fRec2618;
			fRec2613[0] = (fTemp1159 + (fTemp1160 + (fRec2615 + fRec2613[1])));
			fRec2611[0] = fRec2613[0];
			double fRec2612 = (fTemp1159 + (fRec2615 + fTemp1160));
			fRec2610[0] = (fRec2611[0] + fRec2610[1]);
			fRec2608[0] = fRec2610[0];
			double fRec2609 = fRec2612;
			fRec2607[0] = (fTemp1158 + (fRec2609 + fRec2607[1]));
			fRec2605[0] = fRec2607[0];
			double fRec2606 = (fRec2609 + fTemp1158);
			double fTemp1164 = (fConst303 * fRec2620[1]);
			double fTemp1165 = (fConst304 * fRec2623[1]);
			double fTemp1166 = (fConst306 * (((0.018425521800000001 * fTemp60) + (((0.0197700858 * fTemp57) + (0.0019149748999999999 * fTemp55)) + (0.0037344672000000001 * fTemp59))) - (((((0.11453679059999999 * fTemp53) + (0.1042617341 * fTemp54)) + (0.0052292166999999999 * fTemp56)) + (0.039355786099999998 * fTemp58)) + (0.03384649 * fTemp61))));
			double fTemp1167 = (fConst307 * fRec2626[1]);
			double fTemp1168 = (fConst308 * fRec2629[1]);
			fRec2631[0] = (fTemp1166 + (fTemp1167 + (fRec2631[1] + fTemp1168)));
			fRec2629[0] = fRec2631[0];
			double fRec2630 = ((fTemp1168 + fTemp1167) + fTemp1166);
			fRec2628[0] = (fRec2629[0] + fRec2628[1]);
			fRec2626[0] = fRec2628[0];
			double fRec2627 = fRec2630;
			fRec2625[0] = (fTemp1164 + (fTemp1165 + (fRec2627 + fRec2625[1])));
			fRec2623[0] = fRec2625[0];
			double fRec2624 = (fTemp1164 + (fRec2627 + fTemp1165));
			fRec2622[0] = (fRec2623[0] + fRec2622[1]);
			fRec2620[0] = fRec2622[0];
			double fRec2621 = fRec2624;
			double fTemp1169 = (fConst310 * fRec2632[1]);
			double fTemp1170 = (fConst312 * (((((0.11478250199999999 * fTemp66) + (0.078816080199999999 * fTemp67)) + (0.045085587000000003 * fTemp70)) + (0.010204327900000001 * fTemp71)) - ((0.020558122099999999 * fTemp72) + ((0.0050579153000000002 * fTemp69) + (0.0587313785 * fTemp68)))));
			double fTemp1171 = (fConst313 * fRec2635[1]);
			double fTemp1172 = (fConst314 * fRec2638[1]);
			fRec2640[0] = (fTemp1170 + (fTemp1171 + (fRec2640[1] + fTemp1172)));
			fRec2638[0] = fRec2640[0];
			double fRec2639 = ((fTemp1172 + fTemp1171) + fTemp1170);
			fRec2637[0] = (fRec2638[0] + fRec2637[1]);
			fRec2635[0] = fRec2637[0];
			double fRec2636 = fRec2639;
			fRec2634[0] = (fTemp1169 + (fRec2636 + fRec2634[1]));
			fRec2632[0] = fRec2634[0];
			double fRec2633 = (fRec2636 + fTemp1169);
			double fTemp1173 = (fConst316 * ((0.0381559624 * fTemp76) - ((0.038096090800000003 * fTemp77) + (0.076137778700000006 * fTemp78))));
			double fTemp1174 = (fConst317 * fRec2641[1]);
			fRec2643[0] = (fTemp1173 + (fRec2643[1] + fTemp1174));
			fRec2641[0] = fRec2643[0];
			double fRec2642 = (fTemp1174 + fTemp1173);
			double fTemp1175 = (fConst319 * (((0.073072578400000004 * fTemp83) + (0.063475489100000004 * fTemp84)) - (((0.084947170000000002 * fTemp81) + (0.036671386100000002 * fTemp82)) + (0.026518126900000001 * fTemp85))));
			double fTemp1176 = (fConst320 * fRec2644[1]);
			double fTemp1177 = (fConst321 * fRec2647[1]);
			fRec2649[0] = (fTemp1175 + (fTemp1176 + (fRec2649[1] + fTemp1177)));
			fRec2647[0] = fRec2649[0];
			double fRec2648 = ((fTemp1177 + fTemp1176) + fTemp1175);
			fRec2646[0] = (fRec2647[0] + fRec2646[1]);
			fRec2644[0] = fRec2646[0];
			double fRec2645 = fRec2648;
			fVec39[(IOTA & 511)] = (((0.095576067799999997 * fTemp97) + ((0.084415717799999998 * fTemp96) + ((0.018815401900000001 * fTemp7) + ((0.0088412963000000008 * fTemp11) + ((0.016270052900000002 * fTemp95) + ((0.021440041600000001 * fTemp89) + ((0.0231050457 * fTemp94) + ((0.00017331099999999999 * fTemp93) + ((0.019321573799999998 * fTemp92) + (((0.0332756908 * fTemp13) + (fRec2588 + (fRec2606 + (fRec2621 + (fRec2633 + (fRec2642 + fRec2645)))))) + (0.030492377300000002 * fTemp91))))))))))) - ((4.6109400000000003e-05 * fTemp8) + ((0.0043505571999999998 * fTemp9) + (((0.0106773966 * fTemp90) + (0.0043456895000000004 * fTemp12)) + (0.015935849700000001 * fTemp10)))));
			output40[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec39[((IOTA - iConst322) & 511)])));
			double fTemp1178 = (fConst244 * fRec2650[1]);
			double fTemp1179 = (fConst245 * fRec2653[1]);
			double fTemp1180 = (fConst247 * fRec2656[1]);
			double fTemp1181 = (fConst248 * fRec2659[1]);
			double fTemp1182 = (fConst250 * ((((((((0.097497088400000001 * fTemp25) + (0.092078626400000002 * fTemp18)) + (0.0079086046000000007 * fTemp26)) + (0.0059466018000000004 * fTemp27)) + (0.017169459200000001 * fTemp21)) + (0.0097958751000000004 * fTemp23)) + (0.046250815100000002 * fTemp30)) - ((0.039604622700000001 * fTemp29) + ((((0.0078977387999999999 * fTemp20) + ((0.015708928899999999 * fTemp28) + (0.0200314625 * fTemp19))) + (0.0020626395 * fTemp22)) + (0.023408481200000001 * fTemp24)))));
			double fTemp1183 = (fConst251 * fRec2662[1]);
			double fTemp1184 = (fConst252 * fRec2665[1]);
			fRec2667[0] = (fTemp1182 + (fTemp1183 + (fRec2667[1] + fTemp1184)));
			fRec2665[0] = fRec2667[0];
			double fRec2666 = ((fTemp1184 + fTemp1183) + fTemp1182);
			fRec2664[0] = (fRec2665[0] + fRec2664[1]);
			fRec2662[0] = fRec2664[0];
			double fRec2663 = fRec2666;
			fRec2661[0] = (fTemp1180 + (fTemp1181 + (fRec2663 + fRec2661[1])));
			fRec2659[0] = fRec2661[0];
			double fRec2660 = (fTemp1180 + (fRec2663 + fTemp1181));
			fRec2658[0] = (fRec2659[0] + fRec2658[1]);
			fRec2656[0] = fRec2658[0];
			double fRec2657 = fRec2660;
			fRec2655[0] = (fTemp1178 + (fTemp1179 + (fRec2657 + fRec2655[1])));
			fRec2653[0] = fRec2655[0];
			double fRec2654 = (fTemp1178 + (fRec2657 + fTemp1179));
			fRec2652[0] = (fRec2653[0] + fRec2652[1]);
			fRec2650[0] = fRec2652[0];
			double fRec2651 = fRec2654;
			double fTemp1185 = (fConst254 * fRec2668[1]);
			double fTemp1186 = (fConst256 * fRec2671[1]);
			double fTemp1187 = (fConst257 * fRec2674[1]);
			double fTemp1188 = (fConst259 * (((0.046797430899999999 * fTemp47) + ((0.10122519000000001 * fTemp46) + (((0.0092491304999999992 * fTemp42) + (0.0058275821999999996 * fTemp39)) + (0.0155879365 * fTemp45)))) - ((0.0040637316999999999 * fTemp44) + ((0.0052142910999999998 * fTemp41) + ((((0.1062499199 * fTemp37) + (0.0317195729 * fTemp38)) + (0.025975322700000001 * fTemp43)) + (0.020963398300000002 * fTemp40))))));
			double fTemp1189 = (fConst260 * fRec2677[1]);
			double fTemp1190 = (fConst261 * fRec2680[1]);
			fRec2682[0] = (fTemp1188 + (fTemp1189 + (fRec2682[1] + fTemp1190)));
			fRec2680[0] = fRec2682[0];
			double fRec2681 = ((fTemp1190 + fTemp1189) + fTemp1188);
			fRec2679[0] = (fRec2680[0] + fRec2679[1]);
			fRec2677[0] = fRec2679[0];
			double fRec2678 = fRec2681;
			fRec2676[0] = (fTemp1186 + (fTemp1187 + (fRec2678 + fRec2676[1])));
			fRec2674[0] = fRec2676[0];
			double fRec2675 = (fTemp1186 + (fRec2678 + fTemp1187));
			fRec2673[0] = (fRec2674[0] + fRec2673[1]);
			fRec2671[0] = fRec2673[0];
			double fRec2672 = fRec2675;
			fRec2670[0] = (fTemp1185 + (fRec2672 + fRec2670[1]));
			fRec2668[0] = fRec2670[0];
			double fRec2669 = (fRec2672 + fTemp1185);
			double fTemp1191 = (fConst263 * fRec2683[1]);
			double fTemp1192 = (fConst264 * fRec2686[1]);
			double fTemp1193 = (fConst266 * ((((0.034996013399999998 * fTemp53) + (0.033408524000000002 * fTemp57)) + (0.0019653728999999998 * fTemp55)) - ((0.1142063656 * fTemp61) + ((0.089858008099999997 * fTemp60) + ((0.0012163095 * fTemp59) + (((0.056028558700000002 * fTemp54) + (0.0063210534999999998 * fTemp56)) + (0.028631855899999999 * fTemp58)))))));
			double fTemp1194 = (fConst267 * fRec2689[1]);
			double fTemp1195 = (fConst268 * fRec2692[1]);
			fRec2694[0] = (fTemp1193 + (fTemp1194 + (fRec2694[1] + fTemp1195)));
			fRec2692[0] = fRec2694[0];
			double fRec2693 = ((fTemp1195 + fTemp1194) + fTemp1193);
			fRec2691[0] = (fRec2692[0] + fRec2691[1]);
			fRec2689[0] = fRec2691[0];
			double fRec2690 = fRec2693;
			fRec2688[0] = (fTemp1191 + (fTemp1192 + (fRec2690 + fRec2688[1])));
			fRec2686[0] = fRec2688[0];
			double fRec2687 = (fTemp1191 + (fRec2690 + fTemp1192));
			fRec2685[0] = (fRec2686[0] + fRec2685[1]);
			fRec2683[0] = fRec2685[0];
			double fRec2684 = fRec2687;
			double fTemp1196 = (fConst270 * fRec2695[1]);
			double fTemp1197 = (fConst272 * (((0.098711720500000003 * fTemp72) + ((0.014878353299999999 * fTemp68) + ((((0.062135463100000003 * fTemp66) + (0.097186882500000002 * fTemp67)) + (0.045057921299999998 * fTemp70)) + (0.0074884495000000001 * fTemp71)))) - (0.0085588732000000008 * fTemp69)));
			double fTemp1198 = (fConst273 * fRec2698[1]);
			double fTemp1199 = (fConst274 * fRec2701[1]);
			fRec2703[0] = (fTemp1197 + (fTemp1198 + (fRec2703[1] + fTemp1199)));
			fRec2701[0] = fRec2703[0];
			double fRec2702 = ((fTemp1199 + fTemp1198) + fTemp1197);
			fRec2700[0] = (fRec2701[0] + fRec2700[1]);
			fRec2698[0] = fRec2700[0];
			double fRec2699 = fRec2702;
			fRec2697[0] = (fTemp1196 + (fRec2699 + fRec2697[1]));
			fRec2695[0] = fRec2697[0];
			double fRec2696 = (fRec2699 + fTemp1196);
			double fTemp1200 = (fConst276 * ((0.064583163400000004 * fTemp76) - ((0.038125736 * fTemp77) + (0.055574241699999999 * fTemp78))));
			double fTemp1201 = (fConst277 * fRec2704[1]);
			fRec2706[0] = (fTemp1200 + (fRec2706[1] + fTemp1201));
			fRec2704[0] = fRec2706[0];
			double fRec2705 = (fTemp1201 + fTemp1200);
			double fTemp1202 = (fConst279 * ((0.053285021299999999 * fTemp83) - ((((0.10490024589999999 * fTemp81) + (0.062057665400000003 * fTemp82)) + (0.0265034338 * fTemp85)) + (0.0157893063 * fTemp84))));
			double fTemp1203 = (fConst280 * fRec2707[1]);
			double fTemp1204 = (fConst281 * fRec2710[1]);
			fRec2712[0] = (fTemp1202 + (fTemp1203 + (fRec2712[1] + fTemp1204)));
			fRec2710[0] = fRec2712[0];
			double fRec2711 = ((fTemp1204 + fTemp1203) + fTemp1202);
			fRec2709[0] = (fRec2710[0] + fRec2709[1]);
			fRec2707[0] = fRec2709[0];
			double fRec2708 = fRec2711;
			fVec40[(IOTA & 511)] = (((0.0100453244 * fTemp7) + ((0.00024596589999999999 * fTemp8) + ((0.019708746700000002 * fTemp9) + ((0.0040868485000000003 * fTemp10) + ((0.0064747946999999997 * fTemp11) + ((0.016241491800000001 * fTemp95) + ((0.026436876599999999 * fTemp89) + ((0.0128997755 * fTemp94) + (((0.033295417100000002 * fTemp13) + (fRec2651 + (fRec2669 + (fRec2684 + (fRec2696 + (fRec2705 + fRec2708)))))) + (0.0001201536 * fTemp93)))))))))) - ((0.092612809000000004 * fTemp97) + (((((0.025734136599999999 * fTemp90) + (0.080624451400000005 * fTemp91)) + (0.025051034400000002 * fTemp92)) + (0.0073074087000000003 * fTemp12)) + (0.039375013600000001 * fTemp96))));
			output41[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec40[((IOTA - iConst282) & 511)])));
			double fTemp1205 = (fConst284 * fRec2713[1]);
			double fTemp1206 = (fConst285 * fRec2716[1]);
			double fTemp1207 = (fConst287 * fRec2719[1]);
			double fTemp1208 = (fConst288 * fRec2722[1]);
			double fTemp1209 = (fConst290 * (((0.0373885625 * fTemp30) + ((0.1002364463 * fTemp29) + ((0.0074730087000000004 * fTemp24) + ((((0.0028314223000000002 * fTemp18) + (0.023630081399999999 * fTemp26)) + (0.0083150399999999992 * fTemp21)) + (0.0094240195000000002 * fTemp23))))) - (((0.0078479016000000002 * fTemp20) + ((((0.10117101840000001 * fTemp25) + (0.0066016801999999996 * fTemp27)) + (0.0095490048000000001 * fTemp28)) + (0.024999365999999999 * fTemp19))) + (0.012473394699999999 * fTemp22))));
			double fTemp1210 = (fConst291 * fRec2725[1]);
			double fTemp1211 = (fConst292 * fRec2728[1]);
			fRec2730[0] = (fTemp1209 + (fTemp1210 + (fRec2730[1] + fTemp1211)));
			fRec2728[0] = fRec2730[0];
			double fRec2729 = ((fTemp1211 + fTemp1210) + fTemp1209);
			fRec2727[0] = (fRec2728[0] + fRec2727[1]);
			fRec2725[0] = fRec2727[0];
			double fRec2726 = fRec2729;
			fRec2724[0] = (fTemp1207 + (fTemp1208 + (fRec2726 + fRec2724[1])));
			fRec2722[0] = fRec2724[0];
			double fRec2723 = (fTemp1207 + (fRec2726 + fTemp1208));
			fRec2721[0] = (fRec2722[0] + fRec2721[1]);
			fRec2719[0] = fRec2721[0];
			double fRec2720 = fRec2723;
			fRec2718[0] = (fTemp1205 + (fTemp1206 + (fRec2720 + fRec2718[1])));
			fRec2716[0] = fRec2718[0];
			double fRec2717 = (fTemp1205 + (fRec2720 + fTemp1206));
			fRec2715[0] = (fRec2716[0] + fRec2715[1]);
			fRec2713[0] = fRec2715[0];
			double fRec2714 = fRec2717;
			double fTemp1212 = (fConst294 * fRec2731[1]);
			double fTemp1213 = (fConst296 * fRec2734[1]);
			double fTemp1214 = (fConst297 * fRec2737[1]);
			double fTemp1215 = (fConst299 * (((0.0072181390000000002 * fTemp39) + (0.0147701077 * fTemp45)) - ((0.11594870259999999 * fTemp47) + (((0.021142105800000002 * fTemp44) + ((0.0025028214999999999 * fTemp41) + (((((0.0038780943 * fTemp37) + (0.1016547523 * fTemp38)) + (0.0106664642 * fTemp42)) + (0.015732499699999999 * fTemp43)) + (0.0209529073 * fTemp40)))) + (0.030444632900000001 * fTemp46)))));
			double fTemp1216 = (fConst300 * fRec2740[1]);
			double fTemp1217 = (fConst301 * fRec2743[1]);
			fRec2745[0] = (fTemp1215 + (fTemp1216 + (fRec2745[1] + fTemp1217)));
			fRec2743[0] = fRec2745[0];
			double fRec2744 = ((fTemp1217 + fTemp1216) + fTemp1215);
			fRec2742[0] = (fRec2743[0] + fRec2742[1]);
			fRec2740[0] = fRec2742[0];
			double fRec2741 = fRec2744;
			fRec2739[0] = (fTemp1213 + (fTemp1214 + (fRec2741 + fRec2739[1])));
			fRec2737[0] = fRec2739[0];
			double fRec2738 = (fTemp1213 + (fRec2741 + fTemp1214));
			fRec2736[0] = (fRec2737[0] + fRec2736[1]);
			fRec2734[0] = fRec2736[0];
			double fRec2735 = fRec2738;
			fRec2733[0] = (fTemp1212 + (fRec2735 + fRec2733[1]));
			fRec2731[0] = fRec2733[0];
			double fRec2732 = (fRec2735 + fTemp1212);
			double fTemp1218 = (fConst303 * fRec2746[1]);
			double fTemp1219 = (fConst304 * fRec2749[1]);
			double fTemp1220 = (fConst306 * ((((((0.1144481352 * fTemp53) + (0.060735275300000002 * fTemp54)) + (0.041848904200000002 * fTemp57)) + (0.0018425021 * fTemp55)) + (0.033819984900000002 * fTemp61)) - ((0.086782093800000001 * fTemp60) + ((0.0053293350999999997 * fTemp59) + ((0.0037694781999999998 * fTemp56) + (0.0138627157 * fTemp58))))));
			double fTemp1221 = (fConst307 * fRec2752[1]);
			double fTemp1222 = (fConst308 * fRec2755[1]);
			fRec2757[0] = (fTemp1220 + (fTemp1221 + (fRec2757[1] + fTemp1222)));
			fRec2755[0] = fRec2757[0];
			double fRec2756 = ((fTemp1222 + fTemp1221) + fTemp1220);
			fRec2754[0] = (fRec2755[0] + fRec2754[1]);
			fRec2752[0] = fRec2754[0];
			double fRec2753 = fRec2756;
			fRec2751[0] = (fTemp1218 + (fTemp1219 + (fRec2753 + fRec2751[1])));
			fRec2749[0] = fRec2751[0];
			double fRec2750 = (fTemp1218 + (fRec2753 + fTemp1219));
			fRec2748[0] = (fRec2749[0] + fRec2748[1]);
			fRec2746[0] = fRec2748[0];
			double fRec2747 = fRec2750;
			double fTemp1223 = (fConst310 * fRec2758[1]);
			double fTemp1224 = (fConst312 * (((0.095629328 * fTemp72) + ((0.078858903300000005 * fTemp68) + (((0.058746469900000001 * fTemp67) + (0.045119389099999997 * fTemp70)) + (0.0036205429999999999 * fTemp71)))) - ((0.066581291599999995 * fTemp66) + (0.010707793300000001 * fTemp69))));
			double fTemp1225 = (fConst313 * fRec2761[1]);
			double fTemp1226 = (fConst314 * fRec2764[1]);
			fRec2766[0] = (fTemp1224 + (fTemp1225 + (fRec2766[1] + fTemp1226)));
			fRec2764[0] = fRec2766[0];
			double fRec2765 = ((fTemp1226 + fTemp1225) + fTemp1224);
			fRec2763[0] = (fRec2764[0] + fRec2763[1]);
			fRec2761[0] = fRec2763[0];
			double fRec2762 = fRec2765;
			fRec2760[0] = (fTemp1223 + (fRec2762 + fRec2760[1]));
			fRec2758[0] = fRec2760[0];
			double fRec2759 = (fRec2762 + fTemp1223);
			double fTemp1227 = (fConst316 * ((0.080772432899999996 * fTemp76) - ((0.038106424999999999 * fTemp77) + (0.026839500700000001 * fTemp78))));
			double fTemp1228 = (fConst317 * fRec2767[1]);
			fRec2769[0] = (fTemp1227 + (fRec2769[1] + fTemp1228));
			fRec2767[0] = fRec2769[0];
			double fRec2768 = (fTemp1228 + fTemp1227);
			double fTemp1229 = (fConst319 * ((0.0257443272 * fTemp83) - ((((0.0634306377 * fTemp81) + (0.077633322199999993 * fTemp82)) + (0.026474699399999999 * fTemp85)) + (0.084894441400000006 * fTemp84))));
			double fTemp1230 = (fConst320 * fRec2770[1]);
			double fTemp1231 = (fConst321 * fRec2773[1]);
			fRec2775[0] = (fTemp1229 + (fTemp1230 + (fRec2775[1] + fTemp1231)));
			fRec2773[0] = fRec2775[0];
			double fRec2774 = ((fTemp1231 + fTemp1230) + fTemp1229);
			fRec2772[0] = (fRec2773[0] + fRec2772[1]);
			fRec2770[0] = fRec2772[0];
			double fRec2771 = fRec2774;
			fVec41[(IOTA & 511)] = (((0.075080351300000001 * fTemp97) + ((0.019394209499999999 * fTemp9) + ((0.021421907399999999 * fTemp10) + ((0.0031329543 * fTemp11) + ((0.016283451399999999 * fTemp95) + ((0.016024986000000001 * fTemp89) + ((0.084425298600000004 * fTemp91) + ((0.059999516900000001 * fTemp90) + ((0.0332589062 * fTemp13) + (fRec2714 + (fRec2732 + (fRec2747 + (fRec2759 + (fRec2768 + fRec2771)))))))))))))) - ((0.030512055699999999 * fTemp96) + ((0.027031186499999998 * fTemp7) + (((((0.00028513600000000002 * fTemp92) + (0.0001461864 * fTemp93)) + (0.013219079200000001 * fTemp94)) + (0.0092311843000000005 * fTemp12)) + (4.5371999999999999e-05 * fTemp8)))));
			output42[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec41[((IOTA - iConst322) & 511)])));
			double fTemp1232 = (fConst244 * fRec2776[1]);
			double fTemp1233 = (fConst245 * fRec2779[1]);
			double fTemp1234 = (fConst247 * fRec2782[1]);
			double fTemp1235 = (fConst248 * fRec2785[1]);
			double fTemp1236 = (fConst250 * ((((0.046095044000000002 * fTemp25) + (0.0020963748000000001 * fTemp28)) + (0.0234159816 * fTemp24)) - ((0.097527386800000004 * fTemp30) + (((0.0026578418 * fTemp23) + ((0.0157014246 * fTemp22) + ((0.002040661 * fTemp21) + ((0.0078701359999999998 * fTemp20) + ((((0.093121633499999995 * fTemp18) + (0.0080064514999999992 * fTemp26)) + (0.011148865000000001 * fTemp27)) + (0.0263446442 * fTemp19)))))) + (0.037112506900000002 * fTemp29)))));
			double fTemp1237 = (fConst251 * fRec2788[1]);
			double fTemp1238 = (fConst252 * fRec2791[1]);
			fRec2793[0] = (fTemp1236 + (fTemp1237 + (fRec2793[1] + fTemp1238)));
			fRec2791[0] = fRec2793[0];
			double fRec2792 = ((fTemp1238 + fTemp1237) + fTemp1236);
			fRec2790[0] = (fRec2791[0] + fRec2790[1]);
			fRec2788[0] = fRec2790[0];
			double fRec2789 = fRec2792;
			fRec2787[0] = (fTemp1234 + (fTemp1235 + (fRec2789 + fRec2787[1])));
			fRec2785[0] = fRec2787[0];
			double fRec2786 = (fTemp1234 + (fRec2789 + fTemp1235));
			fRec2784[0] = (fRec2785[0] + fRec2784[1]);
			fRec2782[0] = fRec2784[0];
			double fRec2783 = fRec2786;
			fRec2781[0] = (fTemp1232 + (fTemp1233 + (fRec2783 + fRec2781[1])));
			fRec2779[0] = fRec2781[0];
			double fRec2780 = (fTemp1232 + (fRec2783 + fTemp1233));
			fRec2778[0] = (fRec2779[0] + fRec2778[1]);
			fRec2776[0] = fRec2778[0];
			double fRec2777 = fRec2780;
			double fTemp1239 = (fConst254 * fRec2794[1]);
			double fTemp1240 = (fConst256 * fRec2797[1]);
			double fTemp1241 = (fConst257 * fRec2800[1]);
			double fTemp1242 = (fConst259 * (((((((0.1082222259 * fTemp37) + (0.031727106499999998 * fTemp38)) + (0.0040080586999999999 * fTemp43)) + (0.0077845980999999998 * fTemp39)) + (0.00044573799999999999 * fTemp41)) + (0.041904105400000002 * fTemp47)) - ((0.1012325779 * fTemp46) + ((0.0045755739000000002 * fTemp45) + (((0.017592053900000001 * fTemp42) + (0.020982178800000001 * fTemp40)) + (0.025974099899999999 * fTemp44))))));
			double fTemp1243 = (fConst260 * fRec2803[1]);
			double fTemp1244 = (fConst261 * fRec2806[1]);
			fRec2808[0] = (fTemp1242 + (fTemp1243 + (fRec2808[1] + fTemp1244)));
			fRec2806[0] = fRec2808[0];
			double fRec2807 = ((fTemp1244 + fTemp1243) + fTemp1242);
			fRec2805[0] = (fRec2806[0] + fRec2805[1]);
			fRec2803[0] = fRec2805[0];
			double fRec2804 = fRec2807;
			fRec2802[0] = (fTemp1240 + (fTemp1241 + (fRec2804 + fRec2802[1])));
			fRec2800[0] = fRec2802[0];
			double fRec2801 = (fTemp1240 + (fRec2804 + fTemp1241));
			fRec2799[0] = (fRec2800[0] + fRec2799[1]);
			fRec2797[0] = fRec2799[0];
			double fRec2798 = fRec2801;
			fRec2796[0] = (fTemp1239 + (fRec2798 + fRec2796[1]));
			fRec2794[0] = fRec2796[0];
			double fRec2795 = (fRec2798 + fTemp1239);
			double fTemp1245 = (fConst263 * fRec2809[1]);
			double fTemp1246 = (fConst264 * fRec2812[1]);
			double fTemp1247 = (fConst266 * (((0.11418412460000001 * fTemp61) + (((0.0033457879000000001 * fTemp58) + ((((0.103164592 * fTemp54) + (0.0012909985 * fTemp56)) + (0.043861270399999999 * fTemp57)) + (0.0019468815999999999 * fTemp55))) + (0.0239328306 * fTemp60))) - ((0.034890412099999997 * fTemp53) + (0.0063689417999999998 * fTemp59))));
			double fTemp1248 = (fConst267 * fRec2815[1]);
			double fTemp1249 = (fConst268 * fRec2818[1]);
			fRec2820[0] = (fTemp1247 + (fTemp1248 + (fRec2820[1] + fTemp1249)));
			fRec2818[0] = fRec2820[0];
			double fRec2819 = ((fTemp1249 + fTemp1248) + fTemp1247);
			fRec2817[0] = (fRec2818[0] + fRec2817[1]);
			fRec2815[0] = fRec2817[0];
			double fRec2816 = fRec2819;
			fRec2814[0] = (fTemp1245 + (fTemp1246 + (fRec2816 + fRec2814[1])));
			fRec2812[0] = fRec2814[0];
			double fRec2813 = (fTemp1245 + (fRec2816 + fTemp1246));
			fRec2811[0] = (fRec2812[0] + fRec2811[1]);
			fRec2809[0] = fRec2811[0];
			double fRec2810 = fRec2813;
			double fTemp1250 = (fConst270 * fRec2821[1]);
			double fTemp1251 = (fConst272 * (((0.045046237599999997 * fTemp70) + (0.097195331699999998 * fTemp68)) - (((((0.1136994328 * fTemp66) + (0.0148935161 * fTemp67)) + (0.011291667199999999 * fTemp69)) + (0.00071408759999999996 * fTemp71)) + (0.0257925406 * fTemp72))));
			double fTemp1252 = (fConst273 * fRec2824[1]);
			double fTemp1253 = (fConst274 * fRec2827[1]);
			fRec2829[0] = (fTemp1251 + (fTemp1252 + (fRec2829[1] + fTemp1253)));
			fRec2827[0] = fRec2829[0];
			double fRec2828 = ((fTemp1253 + fTemp1252) + fTemp1251);
			fRec2826[0] = (fRec2827[0] + fRec2826[1]);
			fRec2824[0] = fRec2826[0];
			double fRec2825 = fRec2828;
			fRec2823[0] = (fTemp1250 + (fRec2825 + fRec2823[1]));
			fRec2821[0] = fRec2823[0];
			double fRec2822 = (fRec2825 + fTemp1250);
			double fTemp1254 = (fConst276 * (((0.084932691599999999 * fTemp76) + (0.0063599618000000002 * fTemp78)) - (0.038136089200000001 * fTemp77)));
			double fTemp1255 = (fConst277 * fRec2830[1]);
			fRec2832[0] = (fTemp1254 + (fRec2832[1] + fTemp1255));
			fRec2830[0] = fRec2832[0];
			double fRec2831 = (fTemp1255 + fTemp1254);
			double fTemp1256 = (fConst279 * ((0.0157526739 * fTemp81) - ((((0.081569276600000004 * fTemp82) + (0.026461297700000001 * fTemp85)) + (0.0062161797000000003 * fTemp83)) + (0.1048605755 * fTemp84))));
			double fTemp1257 = (fConst280 * fRec2833[1]);
			double fTemp1258 = (fConst281 * fRec2836[1]);
			fRec2838[0] = (fTemp1256 + (fTemp1257 + (fRec2838[1] + fTemp1258)));
			fRec2836[0] = fRec2838[0];
			double fRec2837 = ((fTemp1258 + fTemp1257) + fTemp1256);
			fRec2835[0] = (fRec2836[0] + fRec2835[1]);
			fRec2833[0] = fRec2835[0];
			double fRec2834 = fRec2837;
			fVec42[(IOTA & 511)] = (((0.080629055300000002 * fTemp96) + ((0.0107052259 * fTemp7) + ((0.026513475200000001 * fTemp10) + ((0.016280161200000001 * fTemp95) + (((0.033286693800000003 * fTemp13) + (fRec2777 + (fRec2795 + (fRec2810 + (fRec2822 + (fRec2831 + fRec2834)))))) + (0.024802217500000001 * fTemp92)))))) - (((0.0002099724 * fTemp8) + ((((0.0097076365000000001 * fTemp12) + (((((0.083743788700000002 * fTemp90) + (0.039390398200000003 * fTemp91)) + (7.2904600000000007e-05 * fTemp93)) + (0.023047922500000002 * fTemp94)) + (0.0041388023999999997 * fTemp89))) + (0.00058137930000000003 * fTemp11)) + (0.0048738085 * fTemp9))) + (0.047124220699999997 * fTemp97)));
			output43[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec42[((IOTA - iConst282) & 511)])));
			double fTemp1259 = (fConst284 * fRec2839[1]);
			double fTemp1260 = (fConst285 * fRec2842[1]);
			double fTemp1261 = (fConst287 * fRec2845[1]);
			double fTemp1262 = (fConst288 * fRec2848[1]);
			double fTemp1263 = (fConst290 * (((((0.037418084900000002 * fTemp25) + (0.068852492900000006 * fTemp18)) + (0.0125951567 * fTemp28)) + (0.1012681845 * fTemp30)) - ((0.0728232345 * fTemp29) + ((0.0073785086999999996 * fTemp24) + ((0.0113045677 * fTemp23) + ((0.0095081313999999997 * fTemp22) + ((0.011847148 * fTemp21) + ((0.0078857561999999999 * fTemp20) + (((0.0235443215 * fTemp26) + (0.0019509702000000001 * fTemp27)) + (0.0234880035 * fTemp19))))))))));
			double fTemp1264 = (fConst291 * fRec2851[1]);
			double fTemp1265 = (fConst292 * fRec2854[1]);
			fRec2856[0] = (fTemp1263 + (fTemp1264 + (fRec2856[1] + fTemp1265)));
			fRec2854[0] = fRec2856[0];
			double fRec2855 = ((fTemp1265 + fTemp1264) + fTemp1263);
			fRec2853[0] = (fRec2854[0] + fRec2853[1]);
			fRec2851[0] = fRec2853[0];
			double fRec2852 = fRec2855;
			fRec2850[0] = (fTemp1261 + (fTemp1262 + (fRec2852 + fRec2850[1])));
			fRec2848[0] = fRec2850[0];
			double fRec2849 = (fTemp1261 + (fRec2852 + fTemp1262));
			fRec2847[0] = (fRec2848[0] + fRec2847[1]);
			fRec2845[0] = fRec2847[0];
			double fRec2846 = fRec2849;
			fRec2844[0] = (fTemp1259 + (fTemp1260 + (fRec2846 + fRec2844[1])));
			fRec2842[0] = fRec2844[0];
			double fRec2843 = (fTemp1259 + (fRec2846 + fTemp1260));
			fRec2841[0] = (fRec2842[0] + fRec2841[1]);
			fRec2839[0] = fRec2841[0];
			double fRec2840 = fRec2843;
			double fTemp1266 = (fConst294 * fRec2857[1]);
			double fTemp1267 = (fConst296 * fRec2860[1]);
			double fTemp1268 = (fConst297 * fRec2863[1]);
			double fTemp1269 = (fConst299 * (((0.0848089291 * fTemp47) + (((((0.101600287 * fTemp38) + (0.0211045672 * fTemp43)) + (0.0069372634000000001 * fTemp39)) + (0.0034328653999999999 * fTemp41)) + (0.030439323899999999 * fTemp46))) - ((0.017868153899999999 * fTemp45) + ((((0.079331929699999998 * fTemp37) + (0.0029221923000000002 * fTemp42)) + (0.020930383 * fTemp40)) + (0.015715206299999999 * fTemp44)))));
			double fTemp1270 = (fConst300 * fRec2866[1]);
			double fTemp1271 = (fConst301 * fRec2869[1]);
			fRec2871[0] = (fTemp1269 + (fTemp1270 + (fRec2871[1] + fTemp1271)));
			fRec2869[0] = fRec2871[0];
			double fRec2870 = ((fTemp1271 + fTemp1270) + fTemp1269);
			fRec2868[0] = (fRec2869[0] + fRec2868[1]);
			fRec2866[0] = fRec2868[0];
			double fRec2867 = fRec2870;
			fRec2865[0] = (fTemp1267 + (fTemp1268 + (fRec2867 + fRec2865[1])));
			fRec2863[0] = fRec2865[0];
			double fRec2864 = (fTemp1267 + (fRec2867 + fTemp1268));
			fRec2862[0] = (fRec2863[0] + fRec2862[1]);
			fRec2860[0] = fRec2862[0];
			double fRec2861 = fRec2864;
			fRec2859[0] = (fTemp1266 + (fRec2861 + fRec2859[1]));
			fRec2857[0] = fRec2859[0];
			double fRec2858 = (fRec2861 + fTemp1266);
			double fTemp1272 = (fConst303 * fRec2872[1]);
			double fTemp1273 = (fConst304 * fRec2875[1]);
			double fTemp1274 = (fConst306 * ((((0.019749163300000001 * fTemp58) + ((((0.018404886400000001 * fTemp54) + (0.0052370094999999997 * fTemp56)) + (0.0393619568 * fTemp57)) + (0.0019212354 * fTemp55))) + (0.1042655446 * fTemp60)) - (((0.1145611803 * fTemp53) + (0.0037124749999999998 * fTemp59)) + (0.0338621952 * fTemp61))));
			double fTemp1275 = (fConst307 * fRec2878[1]);
			double fTemp1276 = (fConst308 * fRec2881[1]);
			fRec2883[0] = (fTemp1274 + (fTemp1275 + (fRec2883[1] + fTemp1276)));
			fRec2881[0] = fRec2883[0];
			double fRec2882 = ((fTemp1276 + fTemp1275) + fTemp1274);
			fRec2880[0] = (fRec2881[0] + fRec2880[1]);
			fRec2878[0] = fRec2880[0];
			double fRec2879 = fRec2882;
			fRec2877[0] = (fTemp1272 + (fTemp1273 + (fRec2879 + fRec2877[1])));
			fRec2875[0] = fRec2877[0];
			double fRec2876 = (fTemp1272 + (fRec2879 + fTemp1273));
			fRec2874[0] = (fRec2875[0] + fRec2874[1]);
			fRec2872[0] = fRec2874[0];
			double fRec2873 = fRec2876;
			double fTemp1277 = (fConst310 * fRec2884[1]);
			double fTemp1278 = (fConst312 * (((0.045087633299999999 * fTemp70) + (0.058720090199999998 * fTemp68)) - (((((0.020554094700000001 * fTemp66) + (0.078833772999999996 * fTemp67)) + (0.010219548300000001 * fTemp69)) + (0.0050463616000000003 * fTemp71)) + (0.11481363529999999 * fTemp72))));
			double fTemp1279 = (fConst313 * fRec2887[1]);
			double fTemp1280 = (fConst314 * fRec2890[1]);
			fRec2892[0] = (fTemp1278 + (fTemp1279 + (fRec2892[1] + fTemp1280)));
			fRec2890[0] = fRec2892[0];
			double fRec2891 = ((fTemp1280 + fTemp1279) + fTemp1278);
			fRec2889[0] = (fRec2890[0] + fRec2889[1]);
			fRec2887[0] = fRec2889[0];
			double fRec2888 = fRec2891;
			fRec2886[0] = (fTemp1277 + (fRec2888 + fRec2886[1]));
			fRec2884[0] = fRec2886[0];
			double fRec2885 = (fRec2888 + fTemp1277);
			double fTemp1281 = (fConst316 * (((0.076156538300000007 * fTemp76) + (0.038172035700000002 * fTemp78)) - (0.038101486499999997 * fTemp77)));
			double fTemp1282 = (fConst317 * fRec2893[1]);
			fRec2895[0] = (fTemp1281 + (fRec2895[1] + fTemp1282));
			fRec2893[0] = fRec2895[0];
			double fRec2894 = (fTemp1282 + fTemp1281);
			double fTemp1283 = (fConst319 * ((0.084975672099999996 * fTemp81) - ((((0.073075973599999997 * fTemp82) + (0.026528459000000001 * fTemp85)) + (0.036688060199999997 * fTemp83)) + (0.063485609600000006 * fTemp84))));
			double fTemp1284 = (fConst320 * fRec2896[1]);
			double fTemp1285 = (fConst321 * fRec2899[1]);
			fRec2901[0] = (fTemp1283 + (fTemp1284 + (fRec2901[1] + fTemp1285)));
			fRec2899[0] = fRec2901[0];
			double fRec2900 = ((fTemp1285 + fTemp1284) + fTemp1283);
			fRec2898[0] = (fRec2899[0] + fRec2898[1]);
			fRec2896[0] = fRec2898[0];
			double fRec2897 = fRec2900;
			fVec43[(IOTA & 511)] = (((0.0106703489 * fTemp97) + ((0.019294325599999999 * fTemp7) + ((0.015844152699999999 * fTemp10) + ((0.0162178579 * fTemp95) + ((0.00020070520000000001 * fTemp93) + ((0.095592054699999998 * fTemp90) + ((0.033284755200000002 * fTemp13) + (fRec2840 + (fRec2858 + (fRec2873 + (fRec2885 + (fRec2894 + fRec2897)))))))))))) - ((0.084383438000000005 * fTemp96) + ((3.7759100000000002e-05 * fTemp8) + ((((0.0087732134999999999 * fTemp12) + ((((0.0304604661 * fTemp91) + (0.018791202199999999 * fTemp92)) + (0.0042722148999999997 * fTemp94)) + (0.021472209499999999 * fTemp89))) + (0.0043023664999999999 * fTemp11)) + (0.023124465800000001 * fTemp9)))));
			output44[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec43[((IOTA - iConst322) & 511)])));
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
			fRec55[1] = fRec55[0];
			fRec53[1] = fRec53[0];
			fRec52[1] = fRec52[0];
			fRec50[1] = fRec50[0];
			fRec49[1] = fRec49[0];
			fRec47[1] = fRec47[0];
			fRec46[1] = fRec46[0];
			fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec41[1] = fRec41[0];
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
			fRec78[1] = fRec78[0];
			fRec76[1] = fRec76[0];
			fRec75[1] = fRec75[0];
			fRec73[1] = fRec73[0];
			fRec72[1] = fRec72[0];
			fRec70[1] = fRec70[0];
			fRec69[1] = fRec69[0];
			fRec67[1] = fRec67[0];
			fRec97[2] = fRec97[1];
			fRec97[1] = fRec97[0];
			fRec98[2] = fRec98[1];
			fRec98[1] = fRec98[0];
			fRec99[2] = fRec99[1];
			fRec99[1] = fRec99[0];
			fRec100[2] = fRec100[1];
			fRec100[1] = fRec100[0];
			fRec101[2] = fRec101[1];
			fRec101[1] = fRec101[0];
			fRec102[2] = fRec102[1];
			fRec102[1] = fRec102[0];
			fRec103[2] = fRec103[1];
			fRec103[1] = fRec103[0];
			fRec96[1] = fRec96[0];
			fRec94[1] = fRec94[0];
			fRec93[1] = fRec93[0];
			fRec91[1] = fRec91[0];
			fRec90[1] = fRec90[0];
			fRec88[1] = fRec88[0];
			fRec107[2] = fRec107[1];
			fRec107[1] = fRec107[0];
			fRec108[2] = fRec108[1];
			fRec108[1] = fRec108[0];
			fRec109[2] = fRec109[1];
			fRec109[1] = fRec109[0];
			fRec106[1] = fRec106[0];
			fRec104[1] = fRec104[0];
			fRec116[2] = fRec116[1];
			fRec116[1] = fRec116[0];
			fRec117[2] = fRec117[1];
			fRec117[1] = fRec117[0];
			fRec118[2] = fRec118[1];
			fRec118[1] = fRec118[0];
			fRec119[2] = fRec119[1];
			fRec119[1] = fRec119[0];
			fRec120[2] = fRec120[1];
			fRec120[1] = fRec120[0];
			fRec115[1] = fRec115[0];
			fRec113[1] = fRec113[0];
			fRec112[1] = fRec112[0];
			fRec110[1] = fRec110[0];
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
			fRec129[2] = fRec129[1];
			fRec129[1] = fRec129[0];
			IOTA = (IOTA + 1);
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
			fRec132[1] = fRec132[0];
			fRec130[1] = fRec130[0];
			fRec162[1] = fRec162[0];
			fRec160[1] = fRec160[0];
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
			fRec183[1] = fRec183[0];
			fRec181[1] = fRec181[0];
			fRec180[1] = fRec180[0];
			fRec178[1] = fRec178[0];
			fRec177[1] = fRec177[0];
			fRec175[1] = fRec175[0];
			fRec186[1] = fRec186[0];
			fRec184[1] = fRec184[0];
			fRec192[1] = fRec192[0];
			fRec190[1] = fRec190[0];
			fRec189[1] = fRec189[0];
			fRec187[1] = fRec187[0];
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
			fRec195[1] = fRec195[0];
			fRec193[1] = fRec193[0];
			fRec225[1] = fRec225[0];
			fRec223[1] = fRec223[0];
			fRec222[1] = fRec222[0];
			fRec220[1] = fRec220[0];
			fRec219[1] = fRec219[0];
			fRec217[1] = fRec217[0];
			fRec216[1] = fRec216[0];
			fRec214[1] = fRec214[0];
			fRec213[1] = fRec213[0];
			fRec211[1] = fRec211[0];
			fRec234[1] = fRec234[0];
			fRec232[1] = fRec232[0];
			fRec231[1] = fRec231[0];
			fRec229[1] = fRec229[0];
			fRec228[1] = fRec228[0];
			fRec226[1] = fRec226[0];
			fRec237[1] = fRec237[0];
			fRec235[1] = fRec235[0];
			fRec243[1] = fRec243[0];
			fRec241[1] = fRec241[0];
			fRec240[1] = fRec240[0];
			fRec238[1] = fRec238[0];
			fRec255[1] = fRec255[0];
			fRec253[1] = fRec253[0];
			fRec252[1] = fRec252[0];
			fRec250[1] = fRec250[0];
			fRec249[1] = fRec249[0];
			fRec247[1] = fRec247[0];
			fRec246[1] = fRec246[0];
			fRec244[1] = fRec244[0];
			fRec273[1] = fRec273[0];
			fRec271[1] = fRec271[0];
			fRec270[1] = fRec270[0];
			fRec268[1] = fRec268[0];
			fRec267[1] = fRec267[0];
			fRec265[1] = fRec265[0];
			fRec264[1] = fRec264[0];
			fRec262[1] = fRec262[0];
			fRec261[1] = fRec261[0];
			fRec259[1] = fRec259[0];
			fRec258[1] = fRec258[0];
			fRec256[1] = fRec256[0];
			fRec288[1] = fRec288[0];
			fRec286[1] = fRec286[0];
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
			fRec309[1] = fRec309[0];
			fRec307[1] = fRec307[0];
			fRec306[1] = fRec306[0];
			fRec304[1] = fRec304[0];
			fRec303[1] = fRec303[0];
			fRec301[1] = fRec301[0];
			fRec312[1] = fRec312[0];
			fRec310[1] = fRec310[0];
			fRec318[1] = fRec318[0];
			fRec316[1] = fRec316[0];
			fRec315[1] = fRec315[0];
			fRec313[1] = fRec313[0];
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
			fRec351[1] = fRec351[0];
			fRec349[1] = fRec349[0];
			fRec348[1] = fRec348[0];
			fRec346[1] = fRec346[0];
			fRec345[1] = fRec345[0];
			fRec343[1] = fRec343[0];
			fRec342[1] = fRec342[0];
			fRec340[1] = fRec340[0];
			fRec339[1] = fRec339[0];
			fRec337[1] = fRec337[0];
			fRec363[1] = fRec363[0];
			fRec361[1] = fRec361[0];
			fRec360[1] = fRec360[0];
			fRec358[1] = fRec358[0];
			fRec357[1] = fRec357[0];
			fRec355[1] = fRec355[0];
			fRec354[1] = fRec354[0];
			fRec352[1] = fRec352[0];
			fRec372[1] = fRec372[0];
			fRec370[1] = fRec370[0];
			fRec369[1] = fRec369[0];
			fRec367[1] = fRec367[0];
			fRec366[1] = fRec366[0];
			fRec364[1] = fRec364[0];
			fRec375[1] = fRec375[0];
			fRec373[1] = fRec373[0];
			fRec381[1] = fRec381[0];
			fRec379[1] = fRec379[0];
			fRec378[1] = fRec378[0];
			fRec376[1] = fRec376[0];
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
			fRec384[1] = fRec384[0];
			fRec382[1] = fRec382[0];
			fRec414[1] = fRec414[0];
			fRec412[1] = fRec412[0];
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
			fRec435[1] = fRec435[0];
			fRec433[1] = fRec433[0];
			fRec432[1] = fRec432[0];
			fRec430[1] = fRec430[0];
			fRec429[1] = fRec429[0];
			fRec427[1] = fRec427[0];
			fRec438[1] = fRec438[0];
			fRec436[1] = fRec436[0];
			fRec444[1] = fRec444[0];
			fRec442[1] = fRec442[0];
			fRec441[1] = fRec441[0];
			fRec439[1] = fRec439[0];
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
			fRec447[1] = fRec447[0];
			fRec445[1] = fRec445[0];
			fRec477[1] = fRec477[0];
			fRec475[1] = fRec475[0];
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
			fRec498[1] = fRec498[0];
			fRec496[1] = fRec496[0];
			fRec495[1] = fRec495[0];
			fRec493[1] = fRec493[0];
			fRec492[1] = fRec492[0];
			fRec490[1] = fRec490[0];
			fRec501[1] = fRec501[0];
			fRec499[1] = fRec499[0];
			fRec507[1] = fRec507[0];
			fRec505[1] = fRec505[0];
			fRec504[1] = fRec504[0];
			fRec502[1] = fRec502[0];
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
			fRec552[1] = fRec552[0];
			fRec550[1] = fRec550[0];
			fRec549[1] = fRec549[0];
			fRec547[1] = fRec547[0];
			fRec546[1] = fRec546[0];
			fRec544[1] = fRec544[0];
			fRec543[1] = fRec543[0];
			fRec541[1] = fRec541[0];
			fRec561[1] = fRec561[0];
			fRec559[1] = fRec559[0];
			fRec558[1] = fRec558[0];
			fRec556[1] = fRec556[0];
			fRec555[1] = fRec555[0];
			fRec553[1] = fRec553[0];
			fRec564[1] = fRec564[0];
			fRec562[1] = fRec562[0];
			fRec570[1] = fRec570[0];
			fRec568[1] = fRec568[0];
			fRec567[1] = fRec567[0];
			fRec565[1] = fRec565[0];
			fRec588[1] = fRec588[0];
			fRec586[1] = fRec586[0];
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
			fRec615[1] = fRec615[0];
			fRec613[1] = fRec613[0];
			fRec612[1] = fRec612[0];
			fRec610[1] = fRec610[0];
			fRec609[1] = fRec609[0];
			fRec607[1] = fRec607[0];
			fRec606[1] = fRec606[0];
			fRec604[1] = fRec604[0];
			fRec624[1] = fRec624[0];
			fRec622[1] = fRec622[0];
			fRec621[1] = fRec621[0];
			fRec619[1] = fRec619[0];
			fRec618[1] = fRec618[0];
			fRec616[1] = fRec616[0];
			fRec627[1] = fRec627[0];
			fRec625[1] = fRec625[0];
			fRec633[1] = fRec633[0];
			fRec631[1] = fRec631[0];
			fRec630[1] = fRec630[0];
			fRec628[1] = fRec628[0];
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
			fRec690[1] = fRec690[0];
			fRec688[1] = fRec688[0];
			fRec696[1] = fRec696[0];
			fRec694[1] = fRec694[0];
			fRec693[1] = fRec693[0];
			fRec691[1] = fRec691[0];
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
			fRec753[1] = fRec753[0];
			fRec751[1] = fRec751[0];
			fRec759[1] = fRec759[0];
			fRec757[1] = fRec757[0];
			fRec756[1] = fRec756[0];
			fRec754[1] = fRec754[0];
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
			fRec804[1] = fRec804[0];
			fRec802[1] = fRec802[0];
			fRec801[1] = fRec801[0];
			fRec799[1] = fRec799[0];
			fRec798[1] = fRec798[0];
			fRec796[1] = fRec796[0];
			fRec795[1] = fRec795[0];
			fRec793[1] = fRec793[0];
			fRec813[1] = fRec813[0];
			fRec811[1] = fRec811[0];
			fRec810[1] = fRec810[0];
			fRec808[1] = fRec808[0];
			fRec807[1] = fRec807[0];
			fRec805[1] = fRec805[0];
			fRec816[1] = fRec816[0];
			fRec814[1] = fRec814[0];
			fRec822[1] = fRec822[0];
			fRec820[1] = fRec820[0];
			fRec819[1] = fRec819[0];
			fRec817[1] = fRec817[0];
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
			fRec1140[1] = fRec1140[0];
			fRec1138[1] = fRec1138[0];
			fRec1158[1] = fRec1158[0];
			fRec1156[1] = fRec1156[0];
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
			fRec1173[1] = fRec1173[0];
			fRec1171[1] = fRec1171[0];
			fRec1170[1] = fRec1170[0];
			fRec1168[1] = fRec1168[0];
			fRec1167[1] = fRec1167[0];
			fRec1165[1] = fRec1165[0];
			fRec1164[1] = fRec1164[0];
			fRec1162[1] = fRec1162[0];
			fRec1161[1] = fRec1161[0];
			fRec1159[1] = fRec1159[0];
			fRec1185[1] = fRec1185[0];
			fRec1183[1] = fRec1183[0];
			fRec1182[1] = fRec1182[0];
			fRec1180[1] = fRec1180[0];
			fRec1179[1] = fRec1179[0];
			fRec1177[1] = fRec1177[0];
			fRec1176[1] = fRec1176[0];
			fRec1174[1] = fRec1174[0];
			fRec1191[1] = fRec1191[0];
			fRec1189[1] = fRec1189[0];
			fRec1188[1] = fRec1188[0];
			fRec1186[1] = fRec1186[0];
			fRec1200[1] = fRec1200[0];
			fRec1198[1] = fRec1198[0];
			fRec1197[1] = fRec1197[0];
			fRec1195[1] = fRec1195[0];
			fRec1194[1] = fRec1194[0];
			fRec1192[1] = fRec1192[0];
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
			fRec1266[1] = fRec1266[0];
			fRec1264[1] = fRec1264[0];
			fRec1296[1] = fRec1296[0];
			fRec1294[1] = fRec1294[0];
			fRec1293[1] = fRec1293[0];
			fRec1291[1] = fRec1291[0];
			fRec1290[1] = fRec1290[0];
			fRec1288[1] = fRec1288[0];
			fRec1287[1] = fRec1287[0];
			fRec1285[1] = fRec1285[0];
			fRec1284[1] = fRec1284[0];
			fRec1282[1] = fRec1282[0];
			fRec1308[1] = fRec1308[0];
			fRec1306[1] = fRec1306[0];
			fRec1305[1] = fRec1305[0];
			fRec1303[1] = fRec1303[0];
			fRec1302[1] = fRec1302[0];
			fRec1300[1] = fRec1300[0];
			fRec1299[1] = fRec1299[0];
			fRec1297[1] = fRec1297[0];
			fRec1317[1] = fRec1317[0];
			fRec1315[1] = fRec1315[0];
			fRec1314[1] = fRec1314[0];
			fRec1312[1] = fRec1312[0];
			fRec1311[1] = fRec1311[0];
			fRec1309[1] = fRec1309[0];
			fRec1320[1] = fRec1320[0];
			fRec1318[1] = fRec1318[0];
			fRec1326[1] = fRec1326[0];
			fRec1324[1] = fRec1324[0];
			fRec1323[1] = fRec1323[0];
			fRec1321[1] = fRec1321[0];
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
			fRec1611[1] = fRec1611[0];
			fRec1609[1] = fRec1609[0];
			fRec1608[1] = fRec1608[0];
			fRec1606[1] = fRec1606[0];
			fRec1605[1] = fRec1605[0];
			fRec1603[1] = fRec1603[0];
			fRec1602[1] = fRec1602[0];
			fRec1600[1] = fRec1600[0];
			fRec1599[1] = fRec1599[0];
			fRec1597[1] = fRec1597[0];
			fRec1623[1] = fRec1623[0];
			fRec1621[1] = fRec1621[0];
			fRec1620[1] = fRec1620[0];
			fRec1618[1] = fRec1618[0];
			fRec1617[1] = fRec1617[0];
			fRec1615[1] = fRec1615[0];
			fRec1614[1] = fRec1614[0];
			fRec1612[1] = fRec1612[0];
			fRec1632[1] = fRec1632[0];
			fRec1630[1] = fRec1630[0];
			fRec1629[1] = fRec1629[0];
			fRec1627[1] = fRec1627[0];
			fRec1626[1] = fRec1626[0];
			fRec1624[1] = fRec1624[0];
			fRec1635[1] = fRec1635[0];
			fRec1633[1] = fRec1633[0];
			fRec1641[1] = fRec1641[0];
			fRec1639[1] = fRec1639[0];
			fRec1638[1] = fRec1638[0];
			fRec1636[1] = fRec1636[0];
			for (int j0 = 11; (j0 > 0); j0 = (j0 - 1)) {
				fVec24[j0] = fVec24[(j0 - 1)];
				
			}
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
			for (int j1 = 11; (j1 > 0); j1 = (j1 - 1)) {
				fVec25[j1] = fVec25[(j1 - 1)];
				
			}
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
			fRec1707[1] = fRec1707[0];
			fRec1705[1] = fRec1705[0];
			fRec1737[1] = fRec1737[0];
			fRec1735[1] = fRec1735[0];
			fRec1734[1] = fRec1734[0];
			fRec1732[1] = fRec1732[0];
			fRec1731[1] = fRec1731[0];
			fRec1729[1] = fRec1729[0];
			fRec1728[1] = fRec1728[0];
			fRec1726[1] = fRec1726[0];
			fRec1725[1] = fRec1725[0];
			fRec1723[1] = fRec1723[0];
			fRec1749[1] = fRec1749[0];
			fRec1747[1] = fRec1747[0];
			fRec1746[1] = fRec1746[0];
			fRec1744[1] = fRec1744[0];
			fRec1743[1] = fRec1743[0];
			fRec1741[1] = fRec1741[0];
			fRec1740[1] = fRec1740[0];
			fRec1738[1] = fRec1738[0];
			fRec1758[1] = fRec1758[0];
			fRec1756[1] = fRec1756[0];
			fRec1755[1] = fRec1755[0];
			fRec1753[1] = fRec1753[0];
			fRec1752[1] = fRec1752[0];
			fRec1750[1] = fRec1750[0];
			fRec1761[1] = fRec1761[0];
			fRec1759[1] = fRec1759[0];
			fRec1767[1] = fRec1767[0];
			fRec1765[1] = fRec1765[0];
			fRec1764[1] = fRec1764[0];
			fRec1762[1] = fRec1762[0];
			for (int j2 = 11; (j2 > 0); j2 = (j2 - 1)) {
				fVec26[j2] = fVec26[(j2 - 1)];
				
			}
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
			fRec1821[1] = fRec1821[0];
			fRec1819[1] = fRec1819[0];
			fRec1818[1] = fRec1818[0];
			fRec1816[1] = fRec1816[0];
			fRec1815[1] = fRec1815[0];
			fRec1813[1] = fRec1813[0];
			fRec1824[1] = fRec1824[0];
			fRec1822[1] = fRec1822[0];
			fRec1830[1] = fRec1830[0];
			fRec1828[1] = fRec1828[0];
			fRec1827[1] = fRec1827[0];
			fRec1825[1] = fRec1825[0];
			for (int j3 = 11; (j3 > 0); j3 = (j3 - 1)) {
				fVec27[j3] = fVec27[(j3 - 1)];
				
			}
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
			fRec1911[1] = fRec1911[0];
			fRec1909[1] = fRec1909[0];
			fRec1908[1] = fRec1908[0];
			fRec1906[1] = fRec1906[0];
			fRec1905[1] = fRec1905[0];
			fRec1903[1] = fRec1903[0];
			fRec1902[1] = fRec1902[0];
			fRec1900[1] = fRec1900[0];
			fRec1899[1] = fRec1899[0];
			fRec1897[1] = fRec1897[0];
			fRec1896[1] = fRec1896[0];
			fRec1894[1] = fRec1894[0];
			fRec1926[1] = fRec1926[0];
			fRec1924[1] = fRec1924[0];
			fRec1923[1] = fRec1923[0];
			fRec1921[1] = fRec1921[0];
			fRec1920[1] = fRec1920[0];
			fRec1918[1] = fRec1918[0];
			fRec1917[1] = fRec1917[0];
			fRec1915[1] = fRec1915[0];
			fRec1914[1] = fRec1914[0];
			fRec1912[1] = fRec1912[0];
			fRec1938[1] = fRec1938[0];
			fRec1936[1] = fRec1936[0];
			fRec1935[1] = fRec1935[0];
			fRec1933[1] = fRec1933[0];
			fRec1932[1] = fRec1932[0];
			fRec1930[1] = fRec1930[0];
			fRec1929[1] = fRec1929[0];
			fRec1927[1] = fRec1927[0];
			fRec1947[1] = fRec1947[0];
			fRec1945[1] = fRec1945[0];
			fRec1944[1] = fRec1944[0];
			fRec1942[1] = fRec1942[0];
			fRec1941[1] = fRec1941[0];
			fRec1939[1] = fRec1939[0];
			fRec1950[1] = fRec1950[0];
			fRec1948[1] = fRec1948[0];
			fRec1956[1] = fRec1956[0];
			fRec1954[1] = fRec1954[0];
			fRec1953[1] = fRec1953[0];
			fRec1951[1] = fRec1951[0];
			fRec1974[1] = fRec1974[0];
			fRec1972[1] = fRec1972[0];
			fRec1971[1] = fRec1971[0];
			fRec1969[1] = fRec1969[0];
			fRec1968[1] = fRec1968[0];
			fRec1966[1] = fRec1966[0];
			fRec1965[1] = fRec1965[0];
			fRec1963[1] = fRec1963[0];
			fRec1962[1] = fRec1962[0];
			fRec1960[1] = fRec1960[0];
			fRec1959[1] = fRec1959[0];
			fRec1957[1] = fRec1957[0];
			fRec1989[1] = fRec1989[0];
			fRec1987[1] = fRec1987[0];
			fRec1986[1] = fRec1986[0];
			fRec1984[1] = fRec1984[0];
			fRec1983[1] = fRec1983[0];
			fRec1981[1] = fRec1981[0];
			fRec1980[1] = fRec1980[0];
			fRec1978[1] = fRec1978[0];
			fRec1977[1] = fRec1977[0];
			fRec1975[1] = fRec1975[0];
			fRec2001[1] = fRec2001[0];
			fRec1999[1] = fRec1999[0];
			fRec1998[1] = fRec1998[0];
			fRec1996[1] = fRec1996[0];
			fRec1995[1] = fRec1995[0];
			fRec1993[1] = fRec1993[0];
			fRec1992[1] = fRec1992[0];
			fRec1990[1] = fRec1990[0];
			fRec2010[1] = fRec2010[0];
			fRec2008[1] = fRec2008[0];
			fRec2007[1] = fRec2007[0];
			fRec2005[1] = fRec2005[0];
			fRec2004[1] = fRec2004[0];
			fRec2002[1] = fRec2002[0];
			fRec2013[1] = fRec2013[0];
			fRec2011[1] = fRec2011[0];
			fRec2019[1] = fRec2019[0];
			fRec2017[1] = fRec2017[0];
			fRec2016[1] = fRec2016[0];
			fRec2014[1] = fRec2014[0];
			fRec2037[1] = fRec2037[0];
			fRec2035[1] = fRec2035[0];
			fRec2034[1] = fRec2034[0];
			fRec2032[1] = fRec2032[0];
			fRec2031[1] = fRec2031[0];
			fRec2029[1] = fRec2029[0];
			fRec2028[1] = fRec2028[0];
			fRec2026[1] = fRec2026[0];
			fRec2025[1] = fRec2025[0];
			fRec2023[1] = fRec2023[0];
			fRec2022[1] = fRec2022[0];
			fRec2020[1] = fRec2020[0];
			fRec2052[1] = fRec2052[0];
			fRec2050[1] = fRec2050[0];
			fRec2049[1] = fRec2049[0];
			fRec2047[1] = fRec2047[0];
			fRec2046[1] = fRec2046[0];
			fRec2044[1] = fRec2044[0];
			fRec2043[1] = fRec2043[0];
			fRec2041[1] = fRec2041[0];
			fRec2040[1] = fRec2040[0];
			fRec2038[1] = fRec2038[0];
			fRec2064[1] = fRec2064[0];
			fRec2062[1] = fRec2062[0];
			fRec2061[1] = fRec2061[0];
			fRec2059[1] = fRec2059[0];
			fRec2058[1] = fRec2058[0];
			fRec2056[1] = fRec2056[0];
			fRec2055[1] = fRec2055[0];
			fRec2053[1] = fRec2053[0];
			fRec2073[1] = fRec2073[0];
			fRec2071[1] = fRec2071[0];
			fRec2070[1] = fRec2070[0];
			fRec2068[1] = fRec2068[0];
			fRec2067[1] = fRec2067[0];
			fRec2065[1] = fRec2065[0];
			fRec2076[1] = fRec2076[0];
			fRec2074[1] = fRec2074[0];
			fRec2082[1] = fRec2082[0];
			fRec2080[1] = fRec2080[0];
			fRec2079[1] = fRec2079[0];
			fRec2077[1] = fRec2077[0];
			fRec2100[1] = fRec2100[0];
			fRec2098[1] = fRec2098[0];
			fRec2097[1] = fRec2097[0];
			fRec2095[1] = fRec2095[0];
			fRec2094[1] = fRec2094[0];
			fRec2092[1] = fRec2092[0];
			fRec2091[1] = fRec2091[0];
			fRec2089[1] = fRec2089[0];
			fRec2088[1] = fRec2088[0];
			fRec2086[1] = fRec2086[0];
			fRec2085[1] = fRec2085[0];
			fRec2083[1] = fRec2083[0];
			fRec2115[1] = fRec2115[0];
			fRec2113[1] = fRec2113[0];
			fRec2112[1] = fRec2112[0];
			fRec2110[1] = fRec2110[0];
			fRec2109[1] = fRec2109[0];
			fRec2107[1] = fRec2107[0];
			fRec2106[1] = fRec2106[0];
			fRec2104[1] = fRec2104[0];
			fRec2103[1] = fRec2103[0];
			fRec2101[1] = fRec2101[0];
			fRec2127[1] = fRec2127[0];
			fRec2125[1] = fRec2125[0];
			fRec2124[1] = fRec2124[0];
			fRec2122[1] = fRec2122[0];
			fRec2121[1] = fRec2121[0];
			fRec2119[1] = fRec2119[0];
			fRec2118[1] = fRec2118[0];
			fRec2116[1] = fRec2116[0];
			fRec2136[1] = fRec2136[0];
			fRec2134[1] = fRec2134[0];
			fRec2133[1] = fRec2133[0];
			fRec2131[1] = fRec2131[0];
			fRec2130[1] = fRec2130[0];
			fRec2128[1] = fRec2128[0];
			fRec2139[1] = fRec2139[0];
			fRec2137[1] = fRec2137[0];
			fRec2145[1] = fRec2145[0];
			fRec2143[1] = fRec2143[0];
			fRec2142[1] = fRec2142[0];
			fRec2140[1] = fRec2140[0];
			fRec2163[1] = fRec2163[0];
			fRec2161[1] = fRec2161[0];
			fRec2160[1] = fRec2160[0];
			fRec2158[1] = fRec2158[0];
			fRec2157[1] = fRec2157[0];
			fRec2155[1] = fRec2155[0];
			fRec2154[1] = fRec2154[0];
			fRec2152[1] = fRec2152[0];
			fRec2151[1] = fRec2151[0];
			fRec2149[1] = fRec2149[0];
			fRec2148[1] = fRec2148[0];
			fRec2146[1] = fRec2146[0];
			fRec2178[1] = fRec2178[0];
			fRec2176[1] = fRec2176[0];
			fRec2175[1] = fRec2175[0];
			fRec2173[1] = fRec2173[0];
			fRec2172[1] = fRec2172[0];
			fRec2170[1] = fRec2170[0];
			fRec2169[1] = fRec2169[0];
			fRec2167[1] = fRec2167[0];
			fRec2166[1] = fRec2166[0];
			fRec2164[1] = fRec2164[0];
			fRec2190[1] = fRec2190[0];
			fRec2188[1] = fRec2188[0];
			fRec2187[1] = fRec2187[0];
			fRec2185[1] = fRec2185[0];
			fRec2184[1] = fRec2184[0];
			fRec2182[1] = fRec2182[0];
			fRec2181[1] = fRec2181[0];
			fRec2179[1] = fRec2179[0];
			fRec2199[1] = fRec2199[0];
			fRec2197[1] = fRec2197[0];
			fRec2196[1] = fRec2196[0];
			fRec2194[1] = fRec2194[0];
			fRec2193[1] = fRec2193[0];
			fRec2191[1] = fRec2191[0];
			fRec2202[1] = fRec2202[0];
			fRec2200[1] = fRec2200[0];
			fRec2208[1] = fRec2208[0];
			fRec2206[1] = fRec2206[0];
			fRec2205[1] = fRec2205[0];
			fRec2203[1] = fRec2203[0];
			fRec2226[1] = fRec2226[0];
			fRec2224[1] = fRec2224[0];
			fRec2223[1] = fRec2223[0];
			fRec2221[1] = fRec2221[0];
			fRec2220[1] = fRec2220[0];
			fRec2218[1] = fRec2218[0];
			fRec2217[1] = fRec2217[0];
			fRec2215[1] = fRec2215[0];
			fRec2214[1] = fRec2214[0];
			fRec2212[1] = fRec2212[0];
			fRec2211[1] = fRec2211[0];
			fRec2209[1] = fRec2209[0];
			fRec2241[1] = fRec2241[0];
			fRec2239[1] = fRec2239[0];
			fRec2238[1] = fRec2238[0];
			fRec2236[1] = fRec2236[0];
			fRec2235[1] = fRec2235[0];
			fRec2233[1] = fRec2233[0];
			fRec2232[1] = fRec2232[0];
			fRec2230[1] = fRec2230[0];
			fRec2229[1] = fRec2229[0];
			fRec2227[1] = fRec2227[0];
			fRec2253[1] = fRec2253[0];
			fRec2251[1] = fRec2251[0];
			fRec2250[1] = fRec2250[0];
			fRec2248[1] = fRec2248[0];
			fRec2247[1] = fRec2247[0];
			fRec2245[1] = fRec2245[0];
			fRec2244[1] = fRec2244[0];
			fRec2242[1] = fRec2242[0];
			fRec2262[1] = fRec2262[0];
			fRec2260[1] = fRec2260[0];
			fRec2259[1] = fRec2259[0];
			fRec2257[1] = fRec2257[0];
			fRec2256[1] = fRec2256[0];
			fRec2254[1] = fRec2254[0];
			fRec2265[1] = fRec2265[0];
			fRec2263[1] = fRec2263[0];
			fRec2271[1] = fRec2271[0];
			fRec2269[1] = fRec2269[0];
			fRec2268[1] = fRec2268[0];
			fRec2266[1] = fRec2266[0];
			fRec2289[1] = fRec2289[0];
			fRec2287[1] = fRec2287[0];
			fRec2286[1] = fRec2286[0];
			fRec2284[1] = fRec2284[0];
			fRec2283[1] = fRec2283[0];
			fRec2281[1] = fRec2281[0];
			fRec2280[1] = fRec2280[0];
			fRec2278[1] = fRec2278[0];
			fRec2277[1] = fRec2277[0];
			fRec2275[1] = fRec2275[0];
			fRec2274[1] = fRec2274[0];
			fRec2272[1] = fRec2272[0];
			fRec2304[1] = fRec2304[0];
			fRec2302[1] = fRec2302[0];
			fRec2301[1] = fRec2301[0];
			fRec2299[1] = fRec2299[0];
			fRec2298[1] = fRec2298[0];
			fRec2296[1] = fRec2296[0];
			fRec2295[1] = fRec2295[0];
			fRec2293[1] = fRec2293[0];
			fRec2292[1] = fRec2292[0];
			fRec2290[1] = fRec2290[0];
			fRec2316[1] = fRec2316[0];
			fRec2314[1] = fRec2314[0];
			fRec2313[1] = fRec2313[0];
			fRec2311[1] = fRec2311[0];
			fRec2310[1] = fRec2310[0];
			fRec2308[1] = fRec2308[0];
			fRec2307[1] = fRec2307[0];
			fRec2305[1] = fRec2305[0];
			fRec2325[1] = fRec2325[0];
			fRec2323[1] = fRec2323[0];
			fRec2322[1] = fRec2322[0];
			fRec2320[1] = fRec2320[0];
			fRec2319[1] = fRec2319[0];
			fRec2317[1] = fRec2317[0];
			fRec2328[1] = fRec2328[0];
			fRec2326[1] = fRec2326[0];
			fRec2334[1] = fRec2334[0];
			fRec2332[1] = fRec2332[0];
			fRec2331[1] = fRec2331[0];
			fRec2329[1] = fRec2329[0];
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
			fRec2337[1] = fRec2337[0];
			fRec2335[1] = fRec2335[0];
			fRec2367[1] = fRec2367[0];
			fRec2365[1] = fRec2365[0];
			fRec2364[1] = fRec2364[0];
			fRec2362[1] = fRec2362[0];
			fRec2361[1] = fRec2361[0];
			fRec2359[1] = fRec2359[0];
			fRec2358[1] = fRec2358[0];
			fRec2356[1] = fRec2356[0];
			fRec2355[1] = fRec2355[0];
			fRec2353[1] = fRec2353[0];
			fRec2379[1] = fRec2379[0];
			fRec2377[1] = fRec2377[0];
			fRec2376[1] = fRec2376[0];
			fRec2374[1] = fRec2374[0];
			fRec2373[1] = fRec2373[0];
			fRec2371[1] = fRec2371[0];
			fRec2370[1] = fRec2370[0];
			fRec2368[1] = fRec2368[0];
			fRec2388[1] = fRec2388[0];
			fRec2386[1] = fRec2386[0];
			fRec2385[1] = fRec2385[0];
			fRec2383[1] = fRec2383[0];
			fRec2382[1] = fRec2382[0];
			fRec2380[1] = fRec2380[0];
			fRec2391[1] = fRec2391[0];
			fRec2389[1] = fRec2389[0];
			fRec2397[1] = fRec2397[0];
			fRec2395[1] = fRec2395[0];
			fRec2394[1] = fRec2394[0];
			fRec2392[1] = fRec2392[0];
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
			fRec2400[1] = fRec2400[0];
			fRec2398[1] = fRec2398[0];
			fRec2430[1] = fRec2430[0];
			fRec2428[1] = fRec2428[0];
			fRec2427[1] = fRec2427[0];
			fRec2425[1] = fRec2425[0];
			fRec2424[1] = fRec2424[0];
			fRec2422[1] = fRec2422[0];
			fRec2421[1] = fRec2421[0];
			fRec2419[1] = fRec2419[0];
			fRec2418[1] = fRec2418[0];
			fRec2416[1] = fRec2416[0];
			fRec2442[1] = fRec2442[0];
			fRec2440[1] = fRec2440[0];
			fRec2439[1] = fRec2439[0];
			fRec2437[1] = fRec2437[0];
			fRec2436[1] = fRec2436[0];
			fRec2434[1] = fRec2434[0];
			fRec2433[1] = fRec2433[0];
			fRec2431[1] = fRec2431[0];
			fRec2451[1] = fRec2451[0];
			fRec2449[1] = fRec2449[0];
			fRec2448[1] = fRec2448[0];
			fRec2446[1] = fRec2446[0];
			fRec2445[1] = fRec2445[0];
			fRec2443[1] = fRec2443[0];
			fRec2454[1] = fRec2454[0];
			fRec2452[1] = fRec2452[0];
			fRec2460[1] = fRec2460[0];
			fRec2458[1] = fRec2458[0];
			fRec2457[1] = fRec2457[0];
			fRec2455[1] = fRec2455[0];
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
			fRec2463[1] = fRec2463[0];
			fRec2461[1] = fRec2461[0];
			fRec2493[1] = fRec2493[0];
			fRec2491[1] = fRec2491[0];
			fRec2490[1] = fRec2490[0];
			fRec2488[1] = fRec2488[0];
			fRec2487[1] = fRec2487[0];
			fRec2485[1] = fRec2485[0];
			fRec2484[1] = fRec2484[0];
			fRec2482[1] = fRec2482[0];
			fRec2481[1] = fRec2481[0];
			fRec2479[1] = fRec2479[0];
			fRec2505[1] = fRec2505[0];
			fRec2503[1] = fRec2503[0];
			fRec2502[1] = fRec2502[0];
			fRec2500[1] = fRec2500[0];
			fRec2499[1] = fRec2499[0];
			fRec2497[1] = fRec2497[0];
			fRec2496[1] = fRec2496[0];
			fRec2494[1] = fRec2494[0];
			fRec2514[1] = fRec2514[0];
			fRec2512[1] = fRec2512[0];
			fRec2511[1] = fRec2511[0];
			fRec2509[1] = fRec2509[0];
			fRec2508[1] = fRec2508[0];
			fRec2506[1] = fRec2506[0];
			fRec2517[1] = fRec2517[0];
			fRec2515[1] = fRec2515[0];
			fRec2523[1] = fRec2523[0];
			fRec2521[1] = fRec2521[0];
			fRec2520[1] = fRec2520[0];
			fRec2518[1] = fRec2518[0];
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
			fRec2526[1] = fRec2526[0];
			fRec2524[1] = fRec2524[0];
			fRec2556[1] = fRec2556[0];
			fRec2554[1] = fRec2554[0];
			fRec2553[1] = fRec2553[0];
			fRec2551[1] = fRec2551[0];
			fRec2550[1] = fRec2550[0];
			fRec2548[1] = fRec2548[0];
			fRec2547[1] = fRec2547[0];
			fRec2545[1] = fRec2545[0];
			fRec2544[1] = fRec2544[0];
			fRec2542[1] = fRec2542[0];
			fRec2568[1] = fRec2568[0];
			fRec2566[1] = fRec2566[0];
			fRec2565[1] = fRec2565[0];
			fRec2563[1] = fRec2563[0];
			fRec2562[1] = fRec2562[0];
			fRec2560[1] = fRec2560[0];
			fRec2559[1] = fRec2559[0];
			fRec2557[1] = fRec2557[0];
			fRec2577[1] = fRec2577[0];
			fRec2575[1] = fRec2575[0];
			fRec2574[1] = fRec2574[0];
			fRec2572[1] = fRec2572[0];
			fRec2571[1] = fRec2571[0];
			fRec2569[1] = fRec2569[0];
			fRec2580[1] = fRec2580[0];
			fRec2578[1] = fRec2578[0];
			fRec2586[1] = fRec2586[0];
			fRec2584[1] = fRec2584[0];
			fRec2583[1] = fRec2583[0];
			fRec2581[1] = fRec2581[0];
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
			fRec2589[1] = fRec2589[0];
			fRec2587[1] = fRec2587[0];
			fRec2619[1] = fRec2619[0];
			fRec2617[1] = fRec2617[0];
			fRec2616[1] = fRec2616[0];
			fRec2614[1] = fRec2614[0];
			fRec2613[1] = fRec2613[0];
			fRec2611[1] = fRec2611[0];
			fRec2610[1] = fRec2610[0];
			fRec2608[1] = fRec2608[0];
			fRec2607[1] = fRec2607[0];
			fRec2605[1] = fRec2605[0];
			fRec2631[1] = fRec2631[0];
			fRec2629[1] = fRec2629[0];
			fRec2628[1] = fRec2628[0];
			fRec2626[1] = fRec2626[0];
			fRec2625[1] = fRec2625[0];
			fRec2623[1] = fRec2623[0];
			fRec2622[1] = fRec2622[0];
			fRec2620[1] = fRec2620[0];
			fRec2640[1] = fRec2640[0];
			fRec2638[1] = fRec2638[0];
			fRec2637[1] = fRec2637[0];
			fRec2635[1] = fRec2635[0];
			fRec2634[1] = fRec2634[0];
			fRec2632[1] = fRec2632[0];
			fRec2643[1] = fRec2643[0];
			fRec2641[1] = fRec2641[0];
			fRec2649[1] = fRec2649[0];
			fRec2647[1] = fRec2647[0];
			fRec2646[1] = fRec2646[0];
			fRec2644[1] = fRec2644[0];
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
			fRec2652[1] = fRec2652[0];
			fRec2650[1] = fRec2650[0];
			fRec2682[1] = fRec2682[0];
			fRec2680[1] = fRec2680[0];
			fRec2679[1] = fRec2679[0];
			fRec2677[1] = fRec2677[0];
			fRec2676[1] = fRec2676[0];
			fRec2674[1] = fRec2674[0];
			fRec2673[1] = fRec2673[0];
			fRec2671[1] = fRec2671[0];
			fRec2670[1] = fRec2670[0];
			fRec2668[1] = fRec2668[0];
			fRec2694[1] = fRec2694[0];
			fRec2692[1] = fRec2692[0];
			fRec2691[1] = fRec2691[0];
			fRec2689[1] = fRec2689[0];
			fRec2688[1] = fRec2688[0];
			fRec2686[1] = fRec2686[0];
			fRec2685[1] = fRec2685[0];
			fRec2683[1] = fRec2683[0];
			fRec2703[1] = fRec2703[0];
			fRec2701[1] = fRec2701[0];
			fRec2700[1] = fRec2700[0];
			fRec2698[1] = fRec2698[0];
			fRec2697[1] = fRec2697[0];
			fRec2695[1] = fRec2695[0];
			fRec2706[1] = fRec2706[0];
			fRec2704[1] = fRec2704[0];
			fRec2712[1] = fRec2712[0];
			fRec2710[1] = fRec2710[0];
			fRec2709[1] = fRec2709[0];
			fRec2707[1] = fRec2707[0];
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
			fRec2715[1] = fRec2715[0];
			fRec2713[1] = fRec2713[0];
			fRec2745[1] = fRec2745[0];
			fRec2743[1] = fRec2743[0];
			fRec2742[1] = fRec2742[0];
			fRec2740[1] = fRec2740[0];
			fRec2739[1] = fRec2739[0];
			fRec2737[1] = fRec2737[0];
			fRec2736[1] = fRec2736[0];
			fRec2734[1] = fRec2734[0];
			fRec2733[1] = fRec2733[0];
			fRec2731[1] = fRec2731[0];
			fRec2757[1] = fRec2757[0];
			fRec2755[1] = fRec2755[0];
			fRec2754[1] = fRec2754[0];
			fRec2752[1] = fRec2752[0];
			fRec2751[1] = fRec2751[0];
			fRec2749[1] = fRec2749[0];
			fRec2748[1] = fRec2748[0];
			fRec2746[1] = fRec2746[0];
			fRec2766[1] = fRec2766[0];
			fRec2764[1] = fRec2764[0];
			fRec2763[1] = fRec2763[0];
			fRec2761[1] = fRec2761[0];
			fRec2760[1] = fRec2760[0];
			fRec2758[1] = fRec2758[0];
			fRec2769[1] = fRec2769[0];
			fRec2767[1] = fRec2767[0];
			fRec2775[1] = fRec2775[0];
			fRec2773[1] = fRec2773[0];
			fRec2772[1] = fRec2772[0];
			fRec2770[1] = fRec2770[0];
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
			fRec2778[1] = fRec2778[0];
			fRec2776[1] = fRec2776[0];
			fRec2808[1] = fRec2808[0];
			fRec2806[1] = fRec2806[0];
			fRec2805[1] = fRec2805[0];
			fRec2803[1] = fRec2803[0];
			fRec2802[1] = fRec2802[0];
			fRec2800[1] = fRec2800[0];
			fRec2799[1] = fRec2799[0];
			fRec2797[1] = fRec2797[0];
			fRec2796[1] = fRec2796[0];
			fRec2794[1] = fRec2794[0];
			fRec2820[1] = fRec2820[0];
			fRec2818[1] = fRec2818[0];
			fRec2817[1] = fRec2817[0];
			fRec2815[1] = fRec2815[0];
			fRec2814[1] = fRec2814[0];
			fRec2812[1] = fRec2812[0];
			fRec2811[1] = fRec2811[0];
			fRec2809[1] = fRec2809[0];
			fRec2829[1] = fRec2829[0];
			fRec2827[1] = fRec2827[0];
			fRec2826[1] = fRec2826[0];
			fRec2824[1] = fRec2824[0];
			fRec2823[1] = fRec2823[0];
			fRec2821[1] = fRec2821[0];
			fRec2832[1] = fRec2832[0];
			fRec2830[1] = fRec2830[0];
			fRec2838[1] = fRec2838[0];
			fRec2836[1] = fRec2836[0];
			fRec2835[1] = fRec2835[0];
			fRec2833[1] = fRec2833[0];
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
			fRec2841[1] = fRec2841[0];
			fRec2839[1] = fRec2839[0];
			fRec2871[1] = fRec2871[0];
			fRec2869[1] = fRec2869[0];
			fRec2868[1] = fRec2868[0];
			fRec2866[1] = fRec2866[0];
			fRec2865[1] = fRec2865[0];
			fRec2863[1] = fRec2863[0];
			fRec2862[1] = fRec2862[0];
			fRec2860[1] = fRec2860[0];
			fRec2859[1] = fRec2859[0];
			fRec2857[1] = fRec2857[0];
			fRec2883[1] = fRec2883[0];
			fRec2881[1] = fRec2881[0];
			fRec2880[1] = fRec2880[0];
			fRec2878[1] = fRec2878[0];
			fRec2877[1] = fRec2877[0];
			fRec2875[1] = fRec2875[0];
			fRec2874[1] = fRec2874[0];
			fRec2872[1] = fRec2872[0];
			fRec2892[1] = fRec2892[0];
			fRec2890[1] = fRec2890[0];
			fRec2889[1] = fRec2889[0];
			fRec2887[1] = fRec2887[0];
			fRec2886[1] = fRec2886[0];
			fRec2884[1] = fRec2884[0];
			fRec2895[1] = fRec2895[0];
			fRec2893[1] = fRec2893[0];
			fRec2901[1] = fRec2901[0];
			fRec2899[1] = fRec2899[0];
			fRec2898[1] = fRec2898[0];
			fRec2896[1] = fRec2896[0];
			
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
