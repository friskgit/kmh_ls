/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMHLS_FullSetup_4h3v_full_1"
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
	double fRec16[3];
	double fRec17[3];
	double fRec18[3];
	double fRec19[3];
	double fRec20[3];
	double fRec21[3];
	double fRec22[3];
	double fRec23[3];
	double fConst9;
	double fConst10;
	double fRec15[2];
	double fRec13[2];
	double fRec12[2];
	double fRec10[2];
	double fRec9[2];
	double fRec7[2];
	double fRec6[2];
	double fRec4[2];
	double fConst11;
	double fConst12;
	double fConst13;
	double fConst14;
	double fRec33[3];
	double fRec34[3];
	double fRec35[3];
	double fRec36[3];
	double fRec37[3];
	double fRec38[3];
	double fRec39[3];
	double fConst15;
	double fConst16;
	double fRec32[2];
	double fRec30[2];
	double fRec29[2];
	double fRec27[2];
	double fRec26[2];
	double fRec24[2];
	double fConst17;
	double fConst18;
	double fRec43[3];
	double fRec44[3];
	double fRec45[3];
	double fConst19;
	double fRec42[2];
	double fRec40[2];
	double fConst20;
	double fConst21;
	double fRec52[3];
	double fRec53[3];
	double fRec54[3];
	double fRec55[3];
	double fRec56[3];
	double fConst22;
	double fConst23;
	double fRec51[2];
	double fRec49[2];
	double fRec48[2];
	double fRec46[2];
	int IOTA;
	double fVec0[128];
	int iConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fConst28;
	double fConst29;
	double fConst30;
	double fConst31;
	double fRec68[2];
	double fRec66[2];
	double fRec65[2];
	double fRec63[2];
	double fRec62[2];
	double fRec60[2];
	double fRec59[2];
	double fRec57[2];
	double fConst32;
	double fConst33;
	double fConst34;
	double fConst35;
	double fConst36;
	double fConst37;
	double fRec77[2];
	double fRec75[2];
	double fRec74[2];
	double fRec72[2];
	double fRec71[2];
	double fRec69[2];
	double fConst38;
	double fConst39;
	double fConst40;
	double fRec80[2];
	double fRec78[2];
	double fConst41;
	double fConst42;
	double fConst43;
	double fConst44;
	double fRec86[2];
	double fRec84[2];
	double fRec83[2];
	double fRec81[2];
	double fVec1[128];
	int iConst45;
	double fRec98[2];
	double fRec96[2];
	double fRec95[2];
	double fRec93[2];
	double fRec92[2];
	double fRec90[2];
	double fRec89[2];
	double fRec87[2];
	double fRec107[2];
	double fRec105[2];
	double fRec104[2];
	double fRec102[2];
	double fRec101[2];
	double fRec99[2];
	double fRec110[2];
	double fRec108[2];
	double fRec116[2];
	double fRec114[2];
	double fRec113[2];
	double fRec111[2];
	double fVec2[128];
	double fConst46;
	double fConst47;
	double fConst48;
	double fConst49;
	double fConst50;
	double fConst51;
	double fConst52;
	double fRec128[2];
	double fRec126[2];
	double fRec125[2];
	double fRec123[2];
	double fRec122[2];
	double fRec120[2];
	double fRec119[2];
	double fRec117[2];
	double fConst53;
	double fConst54;
	double fConst55;
	double fConst56;
	double fConst57;
	double fConst58;
	double fRec137[2];
	double fRec135[2];
	double fRec134[2];
	double fRec132[2];
	double fRec131[2];
	double fRec129[2];
	double fConst59;
	double fConst60;
	double fConst61;
	double fRec140[2];
	double fRec138[2];
	double fConst62;
	double fConst63;
	double fConst64;
	double fConst65;
	double fRec146[2];
	double fRec144[2];
	double fRec143[2];
	double fRec141[2];
	double fVec3[128];
	int iConst66;
	double fRec158[2];
	double fRec156[2];
	double fRec155[2];
	double fRec153[2];
	double fRec152[2];
	double fRec150[2];
	double fRec149[2];
	double fRec147[2];
	double fRec167[2];
	double fRec165[2];
	double fRec164[2];
	double fRec162[2];
	double fRec161[2];
	double fRec159[2];
	double fRec170[2];
	double fRec168[2];
	double fRec176[2];
	double fRec174[2];
	double fRec173[2];
	double fRec171[2];
	double fVec4[128];
	double fRec188[2];
	double fRec186[2];
	double fRec185[2];
	double fRec183[2];
	double fRec182[2];
	double fRec180[2];
	double fRec179[2];
	double fRec177[2];
	double fRec197[2];
	double fRec195[2];
	double fRec194[2];
	double fRec192[2];
	double fRec191[2];
	double fRec189[2];
	double fRec200[2];
	double fRec198[2];
	double fRec206[2];
	double fRec204[2];
	double fRec203[2];
	double fRec201[2];
	double fVec5[128];
	double fRec218[2];
	double fRec216[2];
	double fRec215[2];
	double fRec213[2];
	double fRec212[2];
	double fRec210[2];
	double fRec209[2];
	double fRec207[2];
	double fRec227[2];
	double fRec225[2];
	double fRec224[2];
	double fRec222[2];
	double fRec221[2];
	double fRec219[2];
	double fRec230[2];
	double fRec228[2];
	double fRec236[2];
	double fRec234[2];
	double fRec233[2];
	double fRec231[2];
	double fVec6[128];
	double fRec248[2];
	double fRec246[2];
	double fRec245[2];
	double fRec243[2];
	double fRec242[2];
	double fRec240[2];
	double fRec239[2];
	double fRec237[2];
	double fRec257[2];
	double fRec255[2];
	double fRec254[2];
	double fRec252[2];
	double fRec251[2];
	double fRec249[2];
	double fRec260[2];
	double fRec258[2];
	double fRec266[2];
	double fRec264[2];
	double fRec263[2];
	double fRec261[2];
	double fVec7[128];
	double fRec278[2];
	double fRec276[2];
	double fRec275[2];
	double fRec273[2];
	double fRec272[2];
	double fRec270[2];
	double fRec269[2];
	double fRec267[2];
	double fRec287[2];
	double fRec285[2];
	double fRec284[2];
	double fRec282[2];
	double fRec281[2];
	double fRec279[2];
	double fRec290[2];
	double fRec288[2];
	double fRec296[2];
	double fRec294[2];
	double fRec293[2];
	double fRec291[2];
	double fVec8[128];
	double fRec308[2];
	double fRec306[2];
	double fRec305[2];
	double fRec303[2];
	double fRec302[2];
	double fRec300[2];
	double fRec299[2];
	double fRec297[2];
	double fRec317[2];
	double fRec315[2];
	double fRec314[2];
	double fRec312[2];
	double fRec311[2];
	double fRec309[2];
	double fRec320[2];
	double fRec318[2];
	double fRec326[2];
	double fRec324[2];
	double fRec323[2];
	double fRec321[2];
	double fVec9[128];
	double fRec338[2];
	double fRec336[2];
	double fRec335[2];
	double fRec333[2];
	double fRec332[2];
	double fRec330[2];
	double fRec329[2];
	double fRec327[2];
	double fRec347[2];
	double fRec345[2];
	double fRec344[2];
	double fRec342[2];
	double fRec341[2];
	double fRec339[2];
	double fRec350[2];
	double fRec348[2];
	double fRec356[2];
	double fRec354[2];
	double fRec353[2];
	double fRec351[2];
	double fVec10[128];
	double fRec368[2];
	double fRec366[2];
	double fRec365[2];
	double fRec363[2];
	double fRec362[2];
	double fRec360[2];
	double fRec359[2];
	double fRec357[2];
	double fRec377[2];
	double fRec375[2];
	double fRec374[2];
	double fRec372[2];
	double fRec371[2];
	double fRec369[2];
	double fRec380[2];
	double fRec378[2];
	double fRec386[2];
	double fRec384[2];
	double fRec383[2];
	double fRec381[2];
	double fVec11[128];
	double fRec398[2];
	double fRec396[2];
	double fRec395[2];
	double fRec393[2];
	double fRec392[2];
	double fRec390[2];
	double fRec389[2];
	double fRec387[2];
	double fRec407[2];
	double fRec405[2];
	double fRec404[2];
	double fRec402[2];
	double fRec401[2];
	double fRec399[2];
	double fRec410[2];
	double fRec408[2];
	double fRec416[2];
	double fRec414[2];
	double fRec413[2];
	double fRec411[2];
	double fVec12[128];
	double fRec428[2];
	double fRec426[2];
	double fRec425[2];
	double fRec423[2];
	double fRec422[2];
	double fRec420[2];
	double fRec419[2];
	double fRec417[2];
	double fRec437[2];
	double fRec435[2];
	double fRec434[2];
	double fRec432[2];
	double fRec431[2];
	double fRec429[2];
	double fRec440[2];
	double fRec438[2];
	double fRec446[2];
	double fRec444[2];
	double fRec443[2];
	double fRec441[2];
	double fVec13[128];
	double fRec458[2];
	double fRec456[2];
	double fRec455[2];
	double fRec453[2];
	double fRec452[2];
	double fRec450[2];
	double fRec449[2];
	double fRec447[2];
	double fRec467[2];
	double fRec465[2];
	double fRec464[2];
	double fRec462[2];
	double fRec461[2];
	double fRec459[2];
	double fRec470[2];
	double fRec468[2];
	double fRec476[2];
	double fRec474[2];
	double fRec473[2];
	double fRec471[2];
	double fVec14[128];
	double fRec488[2];
	double fRec486[2];
	double fRec485[2];
	double fRec483[2];
	double fRec482[2];
	double fRec480[2];
	double fRec479[2];
	double fRec477[2];
	double fRec497[2];
	double fRec495[2];
	double fRec494[2];
	double fRec492[2];
	double fRec491[2];
	double fRec489[2];
	double fRec500[2];
	double fRec498[2];
	double fRec506[2];
	double fRec504[2];
	double fRec503[2];
	double fRec501[2];
	double fVec15[128];
	double fConst67;
	double fConst68;
	double fConst69;
	double fConst70;
	double fConst71;
	double fConst72;
	double fConst73;
	double fRec518[2];
	double fRec516[2];
	double fRec515[2];
	double fRec513[2];
	double fRec512[2];
	double fRec510[2];
	double fRec509[2];
	double fRec507[2];
	double fConst74;
	double fConst75;
	double fConst76;
	double fConst77;
	double fConst78;
	double fConst79;
	double fRec527[2];
	double fRec525[2];
	double fRec524[2];
	double fRec522[2];
	double fRec521[2];
	double fRec519[2];
	double fConst80;
	double fConst81;
	double fConst82;
	double fRec530[2];
	double fRec528[2];
	double fConst83;
	double fConst84;
	double fConst85;
	double fConst86;
	double fRec536[2];
	double fRec534[2];
	double fRec533[2];
	double fRec531[2];
	double fVec16[128];
	int iConst87;
	double fRec548[2];
	double fRec546[2];
	double fRec545[2];
	double fRec543[2];
	double fRec542[2];
	double fRec540[2];
	double fRec539[2];
	double fRec537[2];
	double fRec557[2];
	double fRec555[2];
	double fRec554[2];
	double fRec552[2];
	double fRec551[2];
	double fRec549[2];
	double fRec560[2];
	double fRec558[2];
	double fRec566[2];
	double fRec564[2];
	double fRec563[2];
	double fRec561[2];
	double fVec17[128];
	double fRec578[2];
	double fRec576[2];
	double fRec575[2];
	double fRec573[2];
	double fRec572[2];
	double fRec570[2];
	double fRec569[2];
	double fRec567[2];
	double fRec587[2];
	double fRec585[2];
	double fRec584[2];
	double fRec582[2];
	double fRec581[2];
	double fRec579[2];
	double fRec590[2];
	double fRec588[2];
	double fRec596[2];
	double fRec594[2];
	double fRec593[2];
	double fRec591[2];
	double fVec18[128];
	double fRec608[2];
	double fRec606[2];
	double fRec605[2];
	double fRec603[2];
	double fRec602[2];
	double fRec600[2];
	double fRec599[2];
	double fRec597[2];
	double fRec617[2];
	double fRec615[2];
	double fRec614[2];
	double fRec612[2];
	double fRec611[2];
	double fRec609[2];
	double fRec620[2];
	double fRec618[2];
	double fRec626[2];
	double fRec624[2];
	double fRec623[2];
	double fRec621[2];
	double fVec19[128];
	double fRec638[2];
	double fRec636[2];
	double fRec635[2];
	double fRec633[2];
	double fRec632[2];
	double fRec630[2];
	double fRec629[2];
	double fRec627[2];
	double fRec647[2];
	double fRec645[2];
	double fRec644[2];
	double fRec642[2];
	double fRec641[2];
	double fRec639[2];
	double fRec650[2];
	double fRec648[2];
	double fRec656[2];
	double fRec654[2];
	double fRec653[2];
	double fRec651[2];
	double fVec20[128];
	double fRec668[2];
	double fRec666[2];
	double fRec665[2];
	double fRec663[2];
	double fRec662[2];
	double fRec660[2];
	double fRec659[2];
	double fRec657[2];
	double fRec677[2];
	double fRec675[2];
	double fRec674[2];
	double fRec672[2];
	double fRec671[2];
	double fRec669[2];
	double fRec680[2];
	double fRec678[2];
	double fRec686[2];
	double fRec684[2];
	double fRec683[2];
	double fRec681[2];
	double fVec21[128];
	double fRec698[2];
	double fRec696[2];
	double fRec695[2];
	double fRec693[2];
	double fRec692[2];
	double fRec690[2];
	double fRec689[2];
	double fRec687[2];
	double fRec707[2];
	double fRec705[2];
	double fRec704[2];
	double fRec702[2];
	double fRec701[2];
	double fRec699[2];
	double fRec710[2];
	double fRec708[2];
	double fRec716[2];
	double fRec714[2];
	double fRec713[2];
	double fRec711[2];
	double fVec22[128];
	double fRec728[2];
	double fRec726[2];
	double fRec725[2];
	double fRec723[2];
	double fRec722[2];
	double fRec720[2];
	double fRec719[2];
	double fRec717[2];
	double fRec737[2];
	double fRec735[2];
	double fRec734[2];
	double fRec732[2];
	double fRec731[2];
	double fRec729[2];
	double fRec740[2];
	double fRec738[2];
	double fRec746[2];
	double fRec744[2];
	double fRec743[2];
	double fRec741[2];
	double fVec23[128];
	double fConst88;
	double fConst89;
	double fConst90;
	double fConst91;
	double fConst92;
	double fConst93;
	double fConst94;
	double fRec758[2];
	double fRec756[2];
	double fRec755[2];
	double fRec753[2];
	double fRec752[2];
	double fRec750[2];
	double fRec749[2];
	double fRec747[2];
	double fConst95;
	double fConst96;
	double fConst97;
	double fConst98;
	double fConst99;
	double fConst100;
	double fRec767[2];
	double fRec765[2];
	double fRec764[2];
	double fRec762[2];
	double fRec761[2];
	double fRec759[2];
	double fConst101;
	double fConst102;
	double fConst103;
	double fRec770[2];
	double fRec768[2];
	double fConst104;
	double fConst105;
	double fConst106;
	double fConst107;
	double fRec776[2];
	double fRec774[2];
	double fRec773[2];
	double fRec771[2];
	double fVec24[12];
	int iConst108;
	double fRec788[2];
	double fRec786[2];
	double fRec785[2];
	double fRec783[2];
	double fRec782[2];
	double fRec780[2];
	double fRec779[2];
	double fRec777[2];
	double fRec797[2];
	double fRec795[2];
	double fRec794[2];
	double fRec792[2];
	double fRec791[2];
	double fRec789[2];
	double fRec800[2];
	double fRec798[2];
	double fRec806[2];
	double fRec804[2];
	double fRec803[2];
	double fRec801[2];
	double fVec25[12];
	double fRec818[2];
	double fRec816[2];
	double fRec815[2];
	double fRec813[2];
	double fRec812[2];
	double fRec810[2];
	double fRec809[2];
	double fRec807[2];
	double fRec827[2];
	double fRec825[2];
	double fRec824[2];
	double fRec822[2];
	double fRec821[2];
	double fRec819[2];
	double fRec830[2];
	double fRec828[2];
	double fRec836[2];
	double fRec834[2];
	double fRec833[2];
	double fRec831[2];
	double fVec26[12];
	double fRec848[2];
	double fRec846[2];
	double fRec845[2];
	double fRec843[2];
	double fRec842[2];
	double fRec840[2];
	double fRec839[2];
	double fRec837[2];
	double fRec857[2];
	double fRec855[2];
	double fRec854[2];
	double fRec852[2];
	double fRec851[2];
	double fRec849[2];
	double fRec860[2];
	double fRec858[2];
	double fRec866[2];
	double fRec864[2];
	double fRec863[2];
	double fRec861[2];
	double fVec27[12];
	double fConst109;
	double fConst110;
	double fConst111;
	double fConst112;
	double fConst113;
	double fConst114;
	double fConst115;
	double fRec878[2];
	double fRec876[2];
	double fRec875[2];
	double fRec873[2];
	double fRec872[2];
	double fRec870[2];
	double fRec869[2];
	double fRec867[2];
	double fConst116;
	double fConst117;
	double fConst118;
	double fConst119;
	double fConst120;
	double fConst121;
	double fRec887[2];
	double fRec885[2];
	double fRec884[2];
	double fRec882[2];
	double fRec881[2];
	double fRec879[2];
	double fConst122;
	double fConst123;
	double fConst124;
	double fRec890[2];
	double fRec888[2];
	double fConst125;
	double fConst126;
	double fConst127;
	double fConst128;
	double fRec896[2];
	double fRec894[2];
	double fRec893[2];
	double fRec891[2];
	double fConst129;
	double fConst130;
	double fConst131;
	double fConst132;
	double fConst133;
	double fConst134;
	double fConst135;
	double fRec908[2];
	double fRec906[2];
	double fRec905[2];
	double fRec903[2];
	double fRec902[2];
	double fRec900[2];
	double fRec899[2];
	double fRec897[2];
	double fConst136;
	double fConst137;
	double fConst138;
	double fConst139;
	double fConst140;
	double fConst141;
	double fRec917[2];
	double fRec915[2];
	double fRec914[2];
	double fRec912[2];
	double fRec911[2];
	double fRec909[2];
	double fConst142;
	double fConst143;
	double fConst144;
	double fRec920[2];
	double fRec918[2];
	double fConst145;
	double fConst146;
	double fConst147;
	double fConst148;
	double fRec926[2];
	double fRec924[2];
	double fRec923[2];
	double fRec921[2];
	double fVec28[512];
	int iConst149;
	double fConst150;
	double fConst151;
	double fConst152;
	double fConst153;
	double fConst154;
	double fConst155;
	double fConst156;
	double fRec938[2];
	double fRec936[2];
	double fRec935[2];
	double fRec933[2];
	double fRec932[2];
	double fRec930[2];
	double fRec929[2];
	double fRec927[2];
	double fConst157;
	double fConst158;
	double fConst159;
	double fConst160;
	double fConst161;
	double fConst162;
	double fRec947[2];
	double fRec945[2];
	double fRec944[2];
	double fRec942[2];
	double fRec941[2];
	double fRec939[2];
	double fConst163;
	double fConst164;
	double fConst165;
	double fRec950[2];
	double fRec948[2];
	double fConst166;
	double fConst167;
	double fConst168;
	double fConst169;
	double fRec956[2];
	double fRec954[2];
	double fRec953[2];
	double fRec951[2];
	double fVec29[512];
	int iConst170;
	double fRec968[2];
	double fRec966[2];
	double fRec965[2];
	double fRec963[2];
	double fRec962[2];
	double fRec960[2];
	double fRec959[2];
	double fRec957[2];
	double fRec977[2];
	double fRec975[2];
	double fRec974[2];
	double fRec972[2];
	double fRec971[2];
	double fRec969[2];
	double fRec980[2];
	double fRec978[2];
	double fRec986[2];
	double fRec984[2];
	double fRec983[2];
	double fRec981[2];
	double fVec30[512];
	double fRec998[2];
	double fRec996[2];
	double fRec995[2];
	double fRec993[2];
	double fRec992[2];
	double fRec990[2];
	double fRec989[2];
	double fRec987[2];
	double fRec1007[2];
	double fRec1005[2];
	double fRec1004[2];
	double fRec1002[2];
	double fRec1001[2];
	double fRec999[2];
	double fRec1010[2];
	double fRec1008[2];
	double fRec1016[2];
	double fRec1014[2];
	double fRec1013[2];
	double fRec1011[2];
	double fVec31[512];
	double fRec1028[2];
	double fRec1026[2];
	double fRec1025[2];
	double fRec1023[2];
	double fRec1022[2];
	double fRec1020[2];
	double fRec1019[2];
	double fRec1017[2];
	double fRec1037[2];
	double fRec1035[2];
	double fRec1034[2];
	double fRec1032[2];
	double fRec1031[2];
	double fRec1029[2];
	double fRec1040[2];
	double fRec1038[2];
	double fRec1046[2];
	double fRec1044[2];
	double fRec1043[2];
	double fRec1041[2];
	double fVec32[512];
	double fRec1058[2];
	double fRec1056[2];
	double fRec1055[2];
	double fRec1053[2];
	double fRec1052[2];
	double fRec1050[2];
	double fRec1049[2];
	double fRec1047[2];
	double fRec1067[2];
	double fRec1065[2];
	double fRec1064[2];
	double fRec1062[2];
	double fRec1061[2];
	double fRec1059[2];
	double fRec1070[2];
	double fRec1068[2];
	double fRec1076[2];
	double fRec1074[2];
	double fRec1073[2];
	double fRec1071[2];
	double fVec33[512];
	double fRec1088[2];
	double fRec1086[2];
	double fRec1085[2];
	double fRec1083[2];
	double fRec1082[2];
	double fRec1080[2];
	double fRec1079[2];
	double fRec1077[2];
	double fRec1097[2];
	double fRec1095[2];
	double fRec1094[2];
	double fRec1092[2];
	double fRec1091[2];
	double fRec1089[2];
	double fRec1100[2];
	double fRec1098[2];
	double fRec1106[2];
	double fRec1104[2];
	double fRec1103[2];
	double fRec1101[2];
	double fVec34[512];
	double fRec1118[2];
	double fRec1116[2];
	double fRec1115[2];
	double fRec1113[2];
	double fRec1112[2];
	double fRec1110[2];
	double fRec1109[2];
	double fRec1107[2];
	double fRec1127[2];
	double fRec1125[2];
	double fRec1124[2];
	double fRec1122[2];
	double fRec1121[2];
	double fRec1119[2];
	double fRec1130[2];
	double fRec1128[2];
	double fRec1136[2];
	double fRec1134[2];
	double fRec1133[2];
	double fRec1131[2];
	double fVec35[512];
	double fRec1148[2];
	double fRec1146[2];
	double fRec1145[2];
	double fRec1143[2];
	double fRec1142[2];
	double fRec1140[2];
	double fRec1139[2];
	double fRec1137[2];
	double fRec1157[2];
	double fRec1155[2];
	double fRec1154[2];
	double fRec1152[2];
	double fRec1151[2];
	double fRec1149[2];
	double fRec1160[2];
	double fRec1158[2];
	double fRec1166[2];
	double fRec1164[2];
	double fRec1163[2];
	double fRec1161[2];
	double fVec36[512];
	double fRec1178[2];
	double fRec1176[2];
	double fRec1175[2];
	double fRec1173[2];
	double fRec1172[2];
	double fRec1170[2];
	double fRec1169[2];
	double fRec1167[2];
	double fRec1187[2];
	double fRec1185[2];
	double fRec1184[2];
	double fRec1182[2];
	double fRec1181[2];
	double fRec1179[2];
	double fRec1190[2];
	double fRec1188[2];
	double fRec1196[2];
	double fRec1194[2];
	double fRec1193[2];
	double fRec1191[2];
	double fVec37[512];
	double fRec1208[2];
	double fRec1206[2];
	double fRec1205[2];
	double fRec1203[2];
	double fRec1202[2];
	double fRec1200[2];
	double fRec1199[2];
	double fRec1197[2];
	double fRec1217[2];
	double fRec1215[2];
	double fRec1214[2];
	double fRec1212[2];
	double fRec1211[2];
	double fRec1209[2];
	double fRec1220[2];
	double fRec1218[2];
	double fRec1226[2];
	double fRec1224[2];
	double fRec1223[2];
	double fRec1221[2];
	double fVec38[512];
	double fRec1238[2];
	double fRec1236[2];
	double fRec1235[2];
	double fRec1233[2];
	double fRec1232[2];
	double fRec1230[2];
	double fRec1229[2];
	double fRec1227[2];
	double fRec1247[2];
	double fRec1245[2];
	double fRec1244[2];
	double fRec1242[2];
	double fRec1241[2];
	double fRec1239[2];
	double fRec1250[2];
	double fRec1248[2];
	double fRec1256[2];
	double fRec1254[2];
	double fRec1253[2];
	double fRec1251[2];
	double fVec39[512];
	double fRec1268[2];
	double fRec1266[2];
	double fRec1265[2];
	double fRec1263[2];
	double fRec1262[2];
	double fRec1260[2];
	double fRec1259[2];
	double fRec1257[2];
	double fRec1277[2];
	double fRec1275[2];
	double fRec1274[2];
	double fRec1272[2];
	double fRec1271[2];
	double fRec1269[2];
	double fRec1280[2];
	double fRec1278[2];
	double fRec1286[2];
	double fRec1284[2];
	double fRec1283[2];
	double fRec1281[2];
	double fVec40[512];
	double fRec1298[2];
	double fRec1296[2];
	double fRec1295[2];
	double fRec1293[2];
	double fRec1292[2];
	double fRec1290[2];
	double fRec1289[2];
	double fRec1287[2];
	double fRec1307[2];
	double fRec1305[2];
	double fRec1304[2];
	double fRec1302[2];
	double fRec1301[2];
	double fRec1299[2];
	double fRec1310[2];
	double fRec1308[2];
	double fRec1316[2];
	double fRec1314[2];
	double fRec1313[2];
	double fRec1311[2];
	double fVec41[512];
	double fRec1328[2];
	double fRec1326[2];
	double fRec1325[2];
	double fRec1323[2];
	double fRec1322[2];
	double fRec1320[2];
	double fRec1319[2];
	double fRec1317[2];
	double fRec1337[2];
	double fRec1335[2];
	double fRec1334[2];
	double fRec1332[2];
	double fRec1331[2];
	double fRec1329[2];
	double fRec1340[2];
	double fRec1338[2];
	double fRec1346[2];
	double fRec1344[2];
	double fRec1343[2];
	double fRec1341[2];
	double fVec42[512];
	double fRec1358[2];
	double fRec1356[2];
	double fRec1355[2];
	double fRec1353[2];
	double fRec1352[2];
	double fRec1350[2];
	double fRec1349[2];
	double fRec1347[2];
	double fRec1367[2];
	double fRec1365[2];
	double fRec1364[2];
	double fRec1362[2];
	double fRec1361[2];
	double fRec1359[2];
	double fRec1370[2];
	double fRec1368[2];
	double fRec1376[2];
	double fRec1374[2];
	double fRec1373[2];
	double fRec1371[2];
	double fVec43[512];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMHLS_FullSetup_4h3v_full_1");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMHLS_FullSetup_4h3v_full_1");
		m->declare("version", "1.2");
	}

	virtual int getNumInputs() {
		return 25;
		
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
		fConst3 = mydsp_faustpower2_f(fConst2);
		fConst4 = ((((10227.965605817382 / fConst2) + 193.7664384515102) / fConst2) + 1.0);
		fConst5 = (0.0 - (40911.862423269529 / (fConst3 * fConst4)));
		fConst6 = (0.0 - (((40911.862423269529 / fConst2) + 387.53287690302039) / (fConst2 * fConst4)));
		fConst7 = ((((12855.048748690073 / fConst2) + 140.75073765235712) / fConst2) + 1.0);
		fConst8 = (1.0 / (fConst4 * fConst7));
		fConst9 = (0.0 - (51420.194994760292 / (fConst3 * fConst7)));
		fConst10 = (0.0 - (((51420.194994760292 / fConst2) + 281.50147530471423) / (fConst2 * fConst7)));
		fConst11 = ((77.681088721927608 / fConst2) + 1.0);
		fConst12 = (0.0 - (155.36217744385522 / (fConst2 * fConst11)));
		fConst13 = ((((7228.2176497399441 / fConst2) + 123.02921694039281) / fConst2) + 1.0);
		fConst14 = (1.0 / (fConst11 * fConst13));
		fConst15 = (0.0 - (28912.870598959777 / (fConst3 * fConst13)));
		fConst16 = (0.0 - (((28912.870598959777 / fConst2) + 246.05843388078563) / (fConst2 * fConst13)));
		fConst17 = ((33.451717610386737 / fConst2) + 1.0);
		fConst18 = (1.0 / fConst17);
		fConst19 = (0.0 - (66.903435220773474 / (fConst2 * fConst17)));
		fConst20 = ((((3357.0522332551745 / fConst2) + 100.35515283116021) / fConst2) + 1.0);
		fConst21 = (1.0 / fConst20);
		fConst22 = (0.0 - (13428.208933020698 / (fConst3 * fConst20)));
		fConst23 = (0.0 - (((13428.208933020698 / fConst2) + 200.71030566232042) / (fConst2 * fConst20)));
		iConst24 = int(((0.00061186204235308644 * double(iConst0)) + 0.5));
		fConst25 = ((((10200.110056355246 / fConst2) + 193.50240008881593) / fConst2) + 1.0);
		fConst26 = (0.0 - (40800.440225420985 / (fConst3 * fConst25)));
		fConst27 = (0.0 - (((40800.440225420985 / fConst2) + 387.00480017763186) / (fConst2 * fConst25)));
		fConst28 = ((((12820.038419162405 / fConst2) + 140.55894182530508) / fConst2) + 1.0);
		fConst29 = (1.0 / (fConst25 * fConst28));
		fConst30 = (0.0 - (51280.153676649621 / (fConst3 * fConst28)));
		fConst31 = (0.0 - (((51280.153676649621 / fConst2) + 281.11788365061017) / (fConst2 * fConst28)));
		fConst32 = ((77.575235573970943 / fConst2) + 1.0);
		fConst33 = (0.0 - (155.15047114794189 / (fConst2 * fConst32)));
		fConst34 = ((((7208.5318214897106 / fConst2) + 122.8615695745017) / fConst2) + 1.0);
		fConst35 = (1.0 / (fConst32 * fConst34));
		fConst36 = (0.0 - (28834.127285958843 / (fConst3 * fConst34)));
		fConst37 = (0.0 - (((28834.127285958843 / fConst2) + 245.7231391490034) / (fConst2 * fConst34)));
		fConst38 = ((33.406134191412107 / fConst2) + 1.0);
		fConst39 = (1.0 / fConst38);
		fConst40 = (0.0 - (66.812268382824215 / (fConst2 * fConst38)));
		fConst41 = ((((3347.9094048438992 / fConst2) + 100.21840257423632) / fConst2) + 1.0);
		fConst42 = (1.0 / fConst41);
		fConst43 = (0.0 - (13391.637619375597 / (fConst3 * fConst41)));
		fConst44 = (0.0 - (((13391.637619375597 / fConst2) + 200.43680514847264) / (fConst2 * fConst41)));
		iConst45 = int(((0.00059146664094131783 * double(iConst0)) + 0.5));
		fConst46 = ((((10212.034197634121 / fConst2) + 193.6154712224868) / fConst2) + 1.0);
		fConst47 = (0.0 - (40848.136790536482 / (fConst3 * fConst46)));
		fConst48 = (0.0 - (((40848.136790536482 / fConst2) + 387.23094244497361) / (fConst2 * fConst46)));
		fConst49 = ((((12835.025311310244 / fConst2) + 140.64107599466149) / fConst2) + 1.0);
		fConst50 = (1.0 / (fConst46 * fConst49));
		fConst51 = (0.0 - (51340.101245240978 / (fConst3 * fConst49)));
		fConst52 = (0.0 - (((51340.101245240978 / fConst2) + 281.28215198932298) / (fConst2 * fConst49)));
		fConst53 = ((77.620565863554475 / fConst2) + 1.0);
		fConst54 = (0.0 - (155.24113172710895 / (fConst2 * fConst53)));
		fConst55 = ((((7216.9587454520797 / fConst2) + 122.93336246673454) / fConst2) + 1.0);
		fConst56 = (1.0 / (fConst53 * fConst55));
		fConst57 = (0.0 - (28867.834981808319 / (fConst3 * fConst55)));
		fConst58 = (0.0 - (((28867.834981808319 / fConst2) + 245.86672493346907) / (fConst2 * fConst55)));
		fConst59 = ((33.425654721714835 / fConst2) + 1.0);
		fConst60 = (1.0 / fConst59);
		fConst61 = (0.0 - (66.85130944342967 / (fConst2 * fConst59)));
		fConst62 = ((((3351.8231807258917 / fConst2) + 100.27696416514451) / fConst2) + 1.0);
		fConst63 = (1.0 / fConst62);
		fConst64 = (0.0 - (13407.292722903567 / (fConst3 * fConst62)));
		fConst65 = (0.0 - (((13407.292722903567 / fConst2) + 200.55392833028901) / (fConst2 * fConst62)));
		iConst66 = int(((0.00060020752726064536 * double(iConst0)) + 0.5));
		fConst67 = ((((9939.1538544721825 / fConst2) + 191.01111246276852) / fConst2) + 1.0);
		fConst68 = (0.0 - (39756.61541788873 / (fConst3 * fConst67)));
		fConst69 = (0.0 - (((39756.61541788873 / fConst2) + 382.02222492553705) / (fConst2 * fConst67)));
		fConst70 = ((((12492.054846889559 / fConst2) + 138.74928596398775) / fConst2) + 1.0);
		fConst71 = (1.0 / (fConst67 * fConst70));
		fConst72 = (0.0 - (49968.219387558238 / (fConst3 * fConst70)));
		fConst73 = (0.0 - (((49968.219387558238 / fConst2) + 277.49857192797549) / (fConst2 * fConst70)));
		fConst74 = ((76.576476776227651 / fConst2) + 1.0);
		fConst75 = (0.0 - (153.1529535524553 / (fConst2 * fConst74)));
		fConst76 = ((((7024.111155938449 / fConst2) + 121.27976227982614) / fConst2) + 1.0);
		fConst77 = (1.0 / (fConst74 * fConst76));
		fConst78 = (0.0 - (28096.444623753796 / (fConst3 * fConst76)));
		fConst79 = (0.0 - (((28096.444623753796 / fConst2) + 242.55952455965229) / (fConst2 * fConst76)));
		fConst80 = ((32.976039842675632 / fConst2) + 1.0);
		fConst81 = (1.0 / fConst80);
		fConst82 = (0.0 - (65.952079685351265 / (fConst2 * fConst80)));
		fConst83 = ((((3262.257611117192 / fConst2) + 98.928119528026897) / fConst2) + 1.0);
		fConst84 = (1.0 / fConst83);
		fConst85 = (0.0 - (13049.030444468768 / (fConst3 * fConst83)));
		fConst86 = (0.0 - (((13049.030444468768 / fConst2) + 197.85623905605379) / (fConst2 * fConst83)));
		iConst87 = int(((0.00039625351314295164 * double(iConst0)) + 0.5));
		fConst88 = ((((9506.8681619800409 / fConst2) + 186.81109363958794) / fConst2) + 1.0);
		fConst89 = (0.0 - (38027.472647920164 / (fConst3 * fConst88)));
		fConst90 = (0.0 - (((38027.472647920164 / fConst2) + 373.62218727917588) / (fConst2 * fConst88)));
		fConst91 = ((((11948.735298846983 / fConst2) + 135.69841837184595) / fConst2) + 1.0);
		fConst92 = (1.0 / (fConst88 * fConst91));
		fConst93 = (0.0 - (47794.941195387932 / (fConst3 * fConst91)));
		fConst94 = (0.0 - (((47794.941195387932 / fConst2) + 271.39683674369189) / (fConst2 * fConst91)));
		fConst95 = ((74.892686552055764 / fConst2) + 1.0);
		fConst96 = (0.0 - (149.78537310411153 / (fConst2 * fConst95)));
		fConst97 = ((((6718.6100237851942 / fConst2) + 118.6130206548046) / fConst2) + 1.0);
		fConst98 = (1.0 / (fConst95 * fConst97));
		fConst99 = (0.0 - (26874.440095140777 / (fConst3 * fConst97)));
		fConst100 = (0.0 - (((26874.440095140777 / fConst2) + 237.2260413096092) / (fConst2 * fConst97)));
		fConst101 = ((32.250951201143394 / fConst2) + 1.0);
		fConst102 = (1.0 / fConst101);
		fConst103 = (0.0 - (64.501902402286788 / (fConst2 * fConst101)));
		fConst104 = ((((3120.3715601355971 / fConst2) + 96.752853603430182) / fConst2) + 1.0);
		fConst105 = (1.0 / fConst104);
		fConst106 = (0.0 - (12481.486240542388 / (fConst3 * fConst104)));
		fConst107 = (0.0 - (((12481.486240542388 / fConst2) + 193.50570720686036) / (fConst2 * fConst104)));
		iConst108 = int(((5.5358946689089155e-05 * double(iConst0)) + 0.5));
		fConst109 = ((((9439.3366456162785 / fConst2) + 186.14640997308004) / fConst2) + 1.0);
		fConst110 = (0.0 - (37757.346582465114 / (fConst3 * fConst109)));
		fConst111 = (0.0 - (((37757.346582465114 / fConst2) + 372.29281994616008) / (fConst2 * fConst109)));
		fConst112 = ((((11863.858113257369 / fConst2) + 135.21559628400601) / fConst2) + 1.0);
		fConst113 = (1.0 / (fConst109 * fConst112));
		fConst114 = (0.0 - (47455.432453029476 / (fConst3 * fConst112)));
		fConst115 = (0.0 - (((47455.432453029476 / fConst2) + 270.43119256801202) / (fConst2 * fConst112)));
		fConst116 = ((74.626214446346196 / fConst2) + 1.0);
		fConst117 = (0.0 - (149.25242889269239 / (fConst2 * fConst116)));
		fConst118 = ((((6670.8847461193591 / fConst2) + 118.19098930790547) / fConst2) + 1.0);
		fConst119 = (1.0 / (fConst116 * fConst118));
		fConst120 = (0.0 - (26683.538984477436 / (fConst3 * fConst118)));
		fConst121 = (0.0 - (((26683.538984477436 / fConst2) + 236.38197861581094) / (fConst2 * fConst118)));
		fConst122 = ((32.136200625708611 / fConst2) + 1.0);
		fConst123 = (1.0 / fConst122);
		fConst124 = (0.0 - (64.272401251417222 / (fConst2 * fConst122)));
		fConst125 = ((((3098.2061719673839 / fConst2) + 96.408601877125832) / fConst2) + 1.0);
		fConst126 = (1.0 / fConst125);
		fConst127 = (0.0 - (12392.824687869535 / (fConst3 * fConst125)));
		fConst128 = (0.0 - (((12392.824687869535 / fConst2) + 192.81720375425166) / (fConst2 * fConst125)));
		fConst129 = ((((12289.445359948479 / fConst2) + 212.39782676415544) / fConst2) + 1.0);
		fConst130 = (0.0 - (49157.781439793915 / (fConst3 * fConst129)));
		fConst131 = (0.0 - (((49157.781439793915 / fConst2) + 424.79565352831088) / (fConst2 * fConst129)));
		fConst132 = ((((15446.025659946026 / fConst2) + 154.28446242662227) / fConst2) + 1.0);
		fConst133 = (1.0 / (fConst129 * fConst132));
		fConst134 = (0.0 - (61784.102639784105 / (fConst3 * fConst132)));
		fConst135 = (0.0 - (((61784.102639784105 / fConst2) + 308.56892485324454) / (fConst2 * fConst132)));
		fConst136 = ((85.150424175959131 / fConst2) + 1.0);
		fConst137 = (0.0 - (170.30084835191826 / (fConst2 * fConst136)));
		fConst138 = ((((8685.0884408302827 / fConst2) + 134.85894933850753) / fConst2) + 1.0);
		fConst139 = (1.0 / (fConst136 * fConst138));
		fConst140 = (0.0 - (34740.353763321131 / (fConst3 * fConst138)));
		fConst141 = (0.0 - (((34740.353763321131 / fConst2) + 269.71789867701506) / (fConst2 * fConst138)));
		fConst142 = ((36.668228919077777 / fConst2) + 1.0);
		fConst143 = (1.0 / fConst142);
		fConst144 = (0.0 - (73.336457838155553 / (fConst2 * fConst142)));
		fConst145 = ((((4033.6770361856752 / fConst2) + 110.00468675723333) / fConst2) + 1.0);
		fConst146 = (1.0 / fConst145);
		fConst147 = (0.0 - (16134.708144742701 / (fConst3 * fConst145)));
		fConst148 = (0.0 - (((16134.708144742701 / fConst2) + 220.00937351446666) / (fConst2 * fConst145)));
		iConst149 = int(((0.001922994990252558 * double(iConst0)) + 0.5));
		fConst150 = ((((12342.133168189845 / fConst2) + 212.8526400976975) / fConst2) + 1.0);
		fConst151 = (0.0 - (49368.532672759378 / (fConst3 * fConst150)));
		fConst152 = (0.0 - (((49368.532672759378 / fConst2) + 425.70528019539501) / (fConst2 * fConst150)));
		fConst153 = ((((15512.246487186505 / fConst2) + 154.61483600783558) / fConst2) + 1.0);
		fConst154 = (1.0 / (fConst150 * fConst153));
		fConst155 = (0.0 - (62048.98594874602 / (fConst3 * fConst153)));
		fConst156 = (0.0 - (((62048.98594874602 / fConst2) + 309.22967201567116) / (fConst2 * fConst153)));
		fConst157 = ((85.332759131368022 / fConst2) + 1.0);
		fConst158 = (0.0 - (170.66551826273604 / (fConst2 * fConst157)));
		fConst159 = ((((8722.3235040025465 / fConst2) + 135.14772653195186) / fConst2) + 1.0);
		fConst160 = (1.0 / (fConst157 * fConst159));
		fConst161 = (0.0 - (34889.294016010186 / (fConst3 * fConst159)));
		fConst162 = (0.0 - (((34889.294016010186 / fConst2) + 270.29545306390372) / (fConst2 * fConst159)));
		fConst163 = ((36.746747610553314 / fConst2) + 1.0);
		fConst164 = (1.0 / fConst163);
		fConst165 = (0.0 - (73.493495221106627 / (fConst2 * fConst163)));
		fConst166 = ((((4050.9703798611172 / fConst2) + 110.24024283165994) / fConst2) + 1.0);
		fConst167 = (1.0 / fConst166);
		fConst168 = (0.0 - (16203.881519444469 / (fConst3 * fConst166)));
		fConst169 = (0.0 - (((16203.881519444469 / fConst2) + 220.48048566331988) / (fConst2 * fConst166)));
		iConst170 = int(((0.0019521312779836569 * double(iConst0)) + 0.5));
		
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
			fRec16[l4] = 0.0;
			
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec17[l5] = 0.0;
			
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec18[l6] = 0.0;
			
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec19[l7] = 0.0;
			
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec20[l8] = 0.0;
			
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec21[l9] = 0.0;
			
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec22[l10] = 0.0;
			
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec23[l11] = 0.0;
			
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec15[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec13[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec12[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec10[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec9[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec7[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec6[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec4[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec33[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec34[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec35[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec36[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 3); l24 = (l24 + 1)) {
			fRec37[l24] = 0.0;
			
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec38[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec39[l26] = 0.0;
			
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec32[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec30[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec29[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec27[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec26[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec24[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 3); l33 = (l33 + 1)) {
			fRec43[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec44[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 3); l35 = (l35 + 1)) {
			fRec45[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec42[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec40[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec52[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 3); l39 = (l39 + 1)) {
			fRec53[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 3); l40 = (l40 + 1)) {
			fRec54[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 3); l41 = (l41 + 1)) {
			fRec55[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec56[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec51[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec49[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec48[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec46[l46] = 0.0;
			
		}
		IOTA = 0;
		for (int l47 = 0; (l47 < 128); l47 = (l47 + 1)) {
			fVec0[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec68[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec66[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec65[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec63[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec62[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fRec60[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec59[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			fRec57[l55] = 0.0;
			
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
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec80[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec78[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec86[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec84[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec83[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec81[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 128); l68 = (l68 + 1)) {
			fVec1[l68] = 0.0;
			
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec98[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec96[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec95[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec93[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec92[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec90[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 2); l75 = (l75 + 1)) {
			fRec89[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) {
			fRec87[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec107[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec105[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			fRec104[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) {
			fRec102[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fRec101[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec99[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			fRec110[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) {
			fRec108[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) {
			fRec116[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 2); l86 = (l86 + 1)) {
			fRec114[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 2); l87 = (l87 + 1)) {
			fRec113[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) {
			fRec111[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 128); l89 = (l89 + 1)) {
			fVec2[l89] = 0.0;
			
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
			fRec137[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec135[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 2); l100 = (l100 + 1)) {
			fRec134[l100] = 0.0;
			
		}
		for (int l101 = 0; (l101 < 2); l101 = (l101 + 1)) {
			fRec132[l101] = 0.0;
			
		}
		for (int l102 = 0; (l102 < 2); l102 = (l102 + 1)) {
			fRec131[l102] = 0.0;
			
		}
		for (int l103 = 0; (l103 < 2); l103 = (l103 + 1)) {
			fRec129[l103] = 0.0;
			
		}
		for (int l104 = 0; (l104 < 2); l104 = (l104 + 1)) {
			fRec140[l104] = 0.0;
			
		}
		for (int l105 = 0; (l105 < 2); l105 = (l105 + 1)) {
			fRec138[l105] = 0.0;
			
		}
		for (int l106 = 0; (l106 < 2); l106 = (l106 + 1)) {
			fRec146[l106] = 0.0;
			
		}
		for (int l107 = 0; (l107 < 2); l107 = (l107 + 1)) {
			fRec144[l107] = 0.0;
			
		}
		for (int l108 = 0; (l108 < 2); l108 = (l108 + 1)) {
			fRec143[l108] = 0.0;
			
		}
		for (int l109 = 0; (l109 < 2); l109 = (l109 + 1)) {
			fRec141[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 128); l110 = (l110 + 1)) {
			fVec3[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec158[l111] = 0.0;
			
		}
		for (int l112 = 0; (l112 < 2); l112 = (l112 + 1)) {
			fRec156[l112] = 0.0;
			
		}
		for (int l113 = 0; (l113 < 2); l113 = (l113 + 1)) {
			fRec155[l113] = 0.0;
			
		}
		for (int l114 = 0; (l114 < 2); l114 = (l114 + 1)) {
			fRec153[l114] = 0.0;
			
		}
		for (int l115 = 0; (l115 < 2); l115 = (l115 + 1)) {
			fRec152[l115] = 0.0;
			
		}
		for (int l116 = 0; (l116 < 2); l116 = (l116 + 1)) {
			fRec150[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec149[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec147[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec167[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec165[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec164[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec162[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec161[l123] = 0.0;
			
		}
		for (int l124 = 0; (l124 < 2); l124 = (l124 + 1)) {
			fRec159[l124] = 0.0;
			
		}
		for (int l125 = 0; (l125 < 2); l125 = (l125 + 1)) {
			fRec170[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec168[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec176[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec174[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec173[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec171[l130] = 0.0;
			
		}
		for (int l131 = 0; (l131 < 128); l131 = (l131 + 1)) {
			fVec4[l131] = 0.0;
			
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
			fRec197[l140] = 0.0;
			
		}
		for (int l141 = 0; (l141 < 2); l141 = (l141 + 1)) {
			fRec195[l141] = 0.0;
			
		}
		for (int l142 = 0; (l142 < 2); l142 = (l142 + 1)) {
			fRec194[l142] = 0.0;
			
		}
		for (int l143 = 0; (l143 < 2); l143 = (l143 + 1)) {
			fRec192[l143] = 0.0;
			
		}
		for (int l144 = 0; (l144 < 2); l144 = (l144 + 1)) {
			fRec191[l144] = 0.0;
			
		}
		for (int l145 = 0; (l145 < 2); l145 = (l145 + 1)) {
			fRec189[l145] = 0.0;
			
		}
		for (int l146 = 0; (l146 < 2); l146 = (l146 + 1)) {
			fRec200[l146] = 0.0;
			
		}
		for (int l147 = 0; (l147 < 2); l147 = (l147 + 1)) {
			fRec198[l147] = 0.0;
			
		}
		for (int l148 = 0; (l148 < 2); l148 = (l148 + 1)) {
			fRec206[l148] = 0.0;
			
		}
		for (int l149 = 0; (l149 < 2); l149 = (l149 + 1)) {
			fRec204[l149] = 0.0;
			
		}
		for (int l150 = 0; (l150 < 2); l150 = (l150 + 1)) {
			fRec203[l150] = 0.0;
			
		}
		for (int l151 = 0; (l151 < 2); l151 = (l151 + 1)) {
			fRec201[l151] = 0.0;
			
		}
		for (int l152 = 0; (l152 < 128); l152 = (l152 + 1)) {
			fVec5[l152] = 0.0;
			
		}
		for (int l153 = 0; (l153 < 2); l153 = (l153 + 1)) {
			fRec218[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec216[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec215[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec213[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec212[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec210[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec209[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec207[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec227[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 2); l162 = (l162 + 1)) {
			fRec225[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			fRec224[l163] = 0.0;
			
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			fRec222[l164] = 0.0;
			
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec221[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec219[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fRec230[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec228[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec236[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec234[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fRec233[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec231[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 128); l173 = (l173 + 1)) {
			fVec6[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec248[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec246[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec245[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec243[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 2); l178 = (l178 + 1)) {
			fRec242[l178] = 0.0;
			
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec240[l179] = 0.0;
			
		}
		for (int l180 = 0; (l180 < 2); l180 = (l180 + 1)) {
			fRec239[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec237[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec257[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fRec255[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec254[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec252[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fRec251[l186] = 0.0;
			
		}
		for (int l187 = 0; (l187 < 2); l187 = (l187 + 1)) {
			fRec249[l187] = 0.0;
			
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec260[l188] = 0.0;
			
		}
		for (int l189 = 0; (l189 < 2); l189 = (l189 + 1)) {
			fRec258[l189] = 0.0;
			
		}
		for (int l190 = 0; (l190 < 2); l190 = (l190 + 1)) {
			fRec266[l190] = 0.0;
			
		}
		for (int l191 = 0; (l191 < 2); l191 = (l191 + 1)) {
			fRec264[l191] = 0.0;
			
		}
		for (int l192 = 0; (l192 < 2); l192 = (l192 + 1)) {
			fRec263[l192] = 0.0;
			
		}
		for (int l193 = 0; (l193 < 2); l193 = (l193 + 1)) {
			fRec261[l193] = 0.0;
			
		}
		for (int l194 = 0; (l194 < 128); l194 = (l194 + 1)) {
			fVec7[l194] = 0.0;
			
		}
		for (int l195 = 0; (l195 < 2); l195 = (l195 + 1)) {
			fRec278[l195] = 0.0;
			
		}
		for (int l196 = 0; (l196 < 2); l196 = (l196 + 1)) {
			fRec276[l196] = 0.0;
			
		}
		for (int l197 = 0; (l197 < 2); l197 = (l197 + 1)) {
			fRec275[l197] = 0.0;
			
		}
		for (int l198 = 0; (l198 < 2); l198 = (l198 + 1)) {
			fRec273[l198] = 0.0;
			
		}
		for (int l199 = 0; (l199 < 2); l199 = (l199 + 1)) {
			fRec272[l199] = 0.0;
			
		}
		for (int l200 = 0; (l200 < 2); l200 = (l200 + 1)) {
			fRec270[l200] = 0.0;
			
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fRec269[l201] = 0.0;
			
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec267[l202] = 0.0;
			
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fRec287[l203] = 0.0;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec285[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec284[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec282[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec281[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec279[l208] = 0.0;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec290[l209] = 0.0;
			
		}
		for (int l210 = 0; (l210 < 2); l210 = (l210 + 1)) {
			fRec288[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 2); l211 = (l211 + 1)) {
			fRec296[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec294[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec293[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fRec291[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 128); l215 = (l215 + 1)) {
			fVec8[l215] = 0.0;
			
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
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec320[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fRec318[l231] = 0.0;
			
		}
		for (int l232 = 0; (l232 < 2); l232 = (l232 + 1)) {
			fRec326[l232] = 0.0;
			
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fRec324[l233] = 0.0;
			
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec323[l234] = 0.0;
			
		}
		for (int l235 = 0; (l235 < 2); l235 = (l235 + 1)) {
			fRec321[l235] = 0.0;
			
		}
		for (int l236 = 0; (l236 < 128); l236 = (l236 + 1)) {
			fVec9[l236] = 0.0;
			
		}
		for (int l237 = 0; (l237 < 2); l237 = (l237 + 1)) {
			fRec338[l237] = 0.0;
			
		}
		for (int l238 = 0; (l238 < 2); l238 = (l238 + 1)) {
			fRec336[l238] = 0.0;
			
		}
		for (int l239 = 0; (l239 < 2); l239 = (l239 + 1)) {
			fRec335[l239] = 0.0;
			
		}
		for (int l240 = 0; (l240 < 2); l240 = (l240 + 1)) {
			fRec333[l240] = 0.0;
			
		}
		for (int l241 = 0; (l241 < 2); l241 = (l241 + 1)) {
			fRec332[l241] = 0.0;
			
		}
		for (int l242 = 0; (l242 < 2); l242 = (l242 + 1)) {
			fRec330[l242] = 0.0;
			
		}
		for (int l243 = 0; (l243 < 2); l243 = (l243 + 1)) {
			fRec329[l243] = 0.0;
			
		}
		for (int l244 = 0; (l244 < 2); l244 = (l244 + 1)) {
			fRec327[l244] = 0.0;
			
		}
		for (int l245 = 0; (l245 < 2); l245 = (l245 + 1)) {
			fRec347[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fRec345[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 2); l247 = (l247 + 1)) {
			fRec344[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 2); l248 = (l248 + 1)) {
			fRec342[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fRec341[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 2); l250 = (l250 + 1)) {
			fRec339[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 2); l251 = (l251 + 1)) {
			fRec350[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 2); l252 = (l252 + 1)) {
			fRec348[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec356[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec354[l254] = 0.0;
			
		}
		for (int l255 = 0; (l255 < 2); l255 = (l255 + 1)) {
			fRec353[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec351[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 128); l257 = (l257 + 1)) {
			fVec10[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec368[l258] = 0.0;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec366[l259] = 0.0;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec365[l260] = 0.0;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec363[l261] = 0.0;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec362[l262] = 0.0;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec360[l263] = 0.0;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec359[l264] = 0.0;
			
		}
		for (int l265 = 0; (l265 < 2); l265 = (l265 + 1)) {
			fRec357[l265] = 0.0;
			
		}
		for (int l266 = 0; (l266 < 2); l266 = (l266 + 1)) {
			fRec377[l266] = 0.0;
			
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec375[l267] = 0.0;
			
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec374[l268] = 0.0;
			
		}
		for (int l269 = 0; (l269 < 2); l269 = (l269 + 1)) {
			fRec372[l269] = 0.0;
			
		}
		for (int l270 = 0; (l270 < 2); l270 = (l270 + 1)) {
			fRec371[l270] = 0.0;
			
		}
		for (int l271 = 0; (l271 < 2); l271 = (l271 + 1)) {
			fRec369[l271] = 0.0;
			
		}
		for (int l272 = 0; (l272 < 2); l272 = (l272 + 1)) {
			fRec380[l272] = 0.0;
			
		}
		for (int l273 = 0; (l273 < 2); l273 = (l273 + 1)) {
			fRec378[l273] = 0.0;
			
		}
		for (int l274 = 0; (l274 < 2); l274 = (l274 + 1)) {
			fRec386[l274] = 0.0;
			
		}
		for (int l275 = 0; (l275 < 2); l275 = (l275 + 1)) {
			fRec384[l275] = 0.0;
			
		}
		for (int l276 = 0; (l276 < 2); l276 = (l276 + 1)) {
			fRec383[l276] = 0.0;
			
		}
		for (int l277 = 0; (l277 < 2); l277 = (l277 + 1)) {
			fRec381[l277] = 0.0;
			
		}
		for (int l278 = 0; (l278 < 128); l278 = (l278 + 1)) {
			fVec11[l278] = 0.0;
			
		}
		for (int l279 = 0; (l279 < 2); l279 = (l279 + 1)) {
			fRec398[l279] = 0.0;
			
		}
		for (int l280 = 0; (l280 < 2); l280 = (l280 + 1)) {
			fRec396[l280] = 0.0;
			
		}
		for (int l281 = 0; (l281 < 2); l281 = (l281 + 1)) {
			fRec395[l281] = 0.0;
			
		}
		for (int l282 = 0; (l282 < 2); l282 = (l282 + 1)) {
			fRec393[l282] = 0.0;
			
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec392[l283] = 0.0;
			
		}
		for (int l284 = 0; (l284 < 2); l284 = (l284 + 1)) {
			fRec390[l284] = 0.0;
			
		}
		for (int l285 = 0; (l285 < 2); l285 = (l285 + 1)) {
			fRec389[l285] = 0.0;
			
		}
		for (int l286 = 0; (l286 < 2); l286 = (l286 + 1)) {
			fRec387[l286] = 0.0;
			
		}
		for (int l287 = 0; (l287 < 2); l287 = (l287 + 1)) {
			fRec407[l287] = 0.0;
			
		}
		for (int l288 = 0; (l288 < 2); l288 = (l288 + 1)) {
			fRec405[l288] = 0.0;
			
		}
		for (int l289 = 0; (l289 < 2); l289 = (l289 + 1)) {
			fRec404[l289] = 0.0;
			
		}
		for (int l290 = 0; (l290 < 2); l290 = (l290 + 1)) {
			fRec402[l290] = 0.0;
			
		}
		for (int l291 = 0; (l291 < 2); l291 = (l291 + 1)) {
			fRec401[l291] = 0.0;
			
		}
		for (int l292 = 0; (l292 < 2); l292 = (l292 + 1)) {
			fRec399[l292] = 0.0;
			
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec410[l293] = 0.0;
			
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec408[l294] = 0.0;
			
		}
		for (int l295 = 0; (l295 < 2); l295 = (l295 + 1)) {
			fRec416[l295] = 0.0;
			
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec414[l296] = 0.0;
			
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec413[l297] = 0.0;
			
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec411[l298] = 0.0;
			
		}
		for (int l299 = 0; (l299 < 128); l299 = (l299 + 1)) {
			fVec12[l299] = 0.0;
			
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec428[l300] = 0.0;
			
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec426[l301] = 0.0;
			
		}
		for (int l302 = 0; (l302 < 2); l302 = (l302 + 1)) {
			fRec425[l302] = 0.0;
			
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec423[l303] = 0.0;
			
		}
		for (int l304 = 0; (l304 < 2); l304 = (l304 + 1)) {
			fRec422[l304] = 0.0;
			
		}
		for (int l305 = 0; (l305 < 2); l305 = (l305 + 1)) {
			fRec420[l305] = 0.0;
			
		}
		for (int l306 = 0; (l306 < 2); l306 = (l306 + 1)) {
			fRec419[l306] = 0.0;
			
		}
		for (int l307 = 0; (l307 < 2); l307 = (l307 + 1)) {
			fRec417[l307] = 0.0;
			
		}
		for (int l308 = 0; (l308 < 2); l308 = (l308 + 1)) {
			fRec437[l308] = 0.0;
			
		}
		for (int l309 = 0; (l309 < 2); l309 = (l309 + 1)) {
			fRec435[l309] = 0.0;
			
		}
		for (int l310 = 0; (l310 < 2); l310 = (l310 + 1)) {
			fRec434[l310] = 0.0;
			
		}
		for (int l311 = 0; (l311 < 2); l311 = (l311 + 1)) {
			fRec432[l311] = 0.0;
			
		}
		for (int l312 = 0; (l312 < 2); l312 = (l312 + 1)) {
			fRec431[l312] = 0.0;
			
		}
		for (int l313 = 0; (l313 < 2); l313 = (l313 + 1)) {
			fRec429[l313] = 0.0;
			
		}
		for (int l314 = 0; (l314 < 2); l314 = (l314 + 1)) {
			fRec440[l314] = 0.0;
			
		}
		for (int l315 = 0; (l315 < 2); l315 = (l315 + 1)) {
			fRec438[l315] = 0.0;
			
		}
		for (int l316 = 0; (l316 < 2); l316 = (l316 + 1)) {
			fRec446[l316] = 0.0;
			
		}
		for (int l317 = 0; (l317 < 2); l317 = (l317 + 1)) {
			fRec444[l317] = 0.0;
			
		}
		for (int l318 = 0; (l318 < 2); l318 = (l318 + 1)) {
			fRec443[l318] = 0.0;
			
		}
		for (int l319 = 0; (l319 < 2); l319 = (l319 + 1)) {
			fRec441[l319] = 0.0;
			
		}
		for (int l320 = 0; (l320 < 128); l320 = (l320 + 1)) {
			fVec13[l320] = 0.0;
			
		}
		for (int l321 = 0; (l321 < 2); l321 = (l321 + 1)) {
			fRec458[l321] = 0.0;
			
		}
		for (int l322 = 0; (l322 < 2); l322 = (l322 + 1)) {
			fRec456[l322] = 0.0;
			
		}
		for (int l323 = 0; (l323 < 2); l323 = (l323 + 1)) {
			fRec455[l323] = 0.0;
			
		}
		for (int l324 = 0; (l324 < 2); l324 = (l324 + 1)) {
			fRec453[l324] = 0.0;
			
		}
		for (int l325 = 0; (l325 < 2); l325 = (l325 + 1)) {
			fRec452[l325] = 0.0;
			
		}
		for (int l326 = 0; (l326 < 2); l326 = (l326 + 1)) {
			fRec450[l326] = 0.0;
			
		}
		for (int l327 = 0; (l327 < 2); l327 = (l327 + 1)) {
			fRec449[l327] = 0.0;
			
		}
		for (int l328 = 0; (l328 < 2); l328 = (l328 + 1)) {
			fRec447[l328] = 0.0;
			
		}
		for (int l329 = 0; (l329 < 2); l329 = (l329 + 1)) {
			fRec467[l329] = 0.0;
			
		}
		for (int l330 = 0; (l330 < 2); l330 = (l330 + 1)) {
			fRec465[l330] = 0.0;
			
		}
		for (int l331 = 0; (l331 < 2); l331 = (l331 + 1)) {
			fRec464[l331] = 0.0;
			
		}
		for (int l332 = 0; (l332 < 2); l332 = (l332 + 1)) {
			fRec462[l332] = 0.0;
			
		}
		for (int l333 = 0; (l333 < 2); l333 = (l333 + 1)) {
			fRec461[l333] = 0.0;
			
		}
		for (int l334 = 0; (l334 < 2); l334 = (l334 + 1)) {
			fRec459[l334] = 0.0;
			
		}
		for (int l335 = 0; (l335 < 2); l335 = (l335 + 1)) {
			fRec470[l335] = 0.0;
			
		}
		for (int l336 = 0; (l336 < 2); l336 = (l336 + 1)) {
			fRec468[l336] = 0.0;
			
		}
		for (int l337 = 0; (l337 < 2); l337 = (l337 + 1)) {
			fRec476[l337] = 0.0;
			
		}
		for (int l338 = 0; (l338 < 2); l338 = (l338 + 1)) {
			fRec474[l338] = 0.0;
			
		}
		for (int l339 = 0; (l339 < 2); l339 = (l339 + 1)) {
			fRec473[l339] = 0.0;
			
		}
		for (int l340 = 0; (l340 < 2); l340 = (l340 + 1)) {
			fRec471[l340] = 0.0;
			
		}
		for (int l341 = 0; (l341 < 128); l341 = (l341 + 1)) {
			fVec14[l341] = 0.0;
			
		}
		for (int l342 = 0; (l342 < 2); l342 = (l342 + 1)) {
			fRec488[l342] = 0.0;
			
		}
		for (int l343 = 0; (l343 < 2); l343 = (l343 + 1)) {
			fRec486[l343] = 0.0;
			
		}
		for (int l344 = 0; (l344 < 2); l344 = (l344 + 1)) {
			fRec485[l344] = 0.0;
			
		}
		for (int l345 = 0; (l345 < 2); l345 = (l345 + 1)) {
			fRec483[l345] = 0.0;
			
		}
		for (int l346 = 0; (l346 < 2); l346 = (l346 + 1)) {
			fRec482[l346] = 0.0;
			
		}
		for (int l347 = 0; (l347 < 2); l347 = (l347 + 1)) {
			fRec480[l347] = 0.0;
			
		}
		for (int l348 = 0; (l348 < 2); l348 = (l348 + 1)) {
			fRec479[l348] = 0.0;
			
		}
		for (int l349 = 0; (l349 < 2); l349 = (l349 + 1)) {
			fRec477[l349] = 0.0;
			
		}
		for (int l350 = 0; (l350 < 2); l350 = (l350 + 1)) {
			fRec497[l350] = 0.0;
			
		}
		for (int l351 = 0; (l351 < 2); l351 = (l351 + 1)) {
			fRec495[l351] = 0.0;
			
		}
		for (int l352 = 0; (l352 < 2); l352 = (l352 + 1)) {
			fRec494[l352] = 0.0;
			
		}
		for (int l353 = 0; (l353 < 2); l353 = (l353 + 1)) {
			fRec492[l353] = 0.0;
			
		}
		for (int l354 = 0; (l354 < 2); l354 = (l354 + 1)) {
			fRec491[l354] = 0.0;
			
		}
		for (int l355 = 0; (l355 < 2); l355 = (l355 + 1)) {
			fRec489[l355] = 0.0;
			
		}
		for (int l356 = 0; (l356 < 2); l356 = (l356 + 1)) {
			fRec500[l356] = 0.0;
			
		}
		for (int l357 = 0; (l357 < 2); l357 = (l357 + 1)) {
			fRec498[l357] = 0.0;
			
		}
		for (int l358 = 0; (l358 < 2); l358 = (l358 + 1)) {
			fRec506[l358] = 0.0;
			
		}
		for (int l359 = 0; (l359 < 2); l359 = (l359 + 1)) {
			fRec504[l359] = 0.0;
			
		}
		for (int l360 = 0; (l360 < 2); l360 = (l360 + 1)) {
			fRec503[l360] = 0.0;
			
		}
		for (int l361 = 0; (l361 < 2); l361 = (l361 + 1)) {
			fRec501[l361] = 0.0;
			
		}
		for (int l362 = 0; (l362 < 128); l362 = (l362 + 1)) {
			fVec15[l362] = 0.0;
			
		}
		for (int l363 = 0; (l363 < 2); l363 = (l363 + 1)) {
			fRec518[l363] = 0.0;
			
		}
		for (int l364 = 0; (l364 < 2); l364 = (l364 + 1)) {
			fRec516[l364] = 0.0;
			
		}
		for (int l365 = 0; (l365 < 2); l365 = (l365 + 1)) {
			fRec515[l365] = 0.0;
			
		}
		for (int l366 = 0; (l366 < 2); l366 = (l366 + 1)) {
			fRec513[l366] = 0.0;
			
		}
		for (int l367 = 0; (l367 < 2); l367 = (l367 + 1)) {
			fRec512[l367] = 0.0;
			
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec510[l368] = 0.0;
			
		}
		for (int l369 = 0; (l369 < 2); l369 = (l369 + 1)) {
			fRec509[l369] = 0.0;
			
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec507[l370] = 0.0;
			
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			fRec527[l371] = 0.0;
			
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			fRec525[l372] = 0.0;
			
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fRec524[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec522[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 2); l375 = (l375 + 1)) {
			fRec521[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec519[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec530[l377] = 0.0;
			
		}
		for (int l378 = 0; (l378 < 2); l378 = (l378 + 1)) {
			fRec528[l378] = 0.0;
			
		}
		for (int l379 = 0; (l379 < 2); l379 = (l379 + 1)) {
			fRec536[l379] = 0.0;
			
		}
		for (int l380 = 0; (l380 < 2); l380 = (l380 + 1)) {
			fRec534[l380] = 0.0;
			
		}
		for (int l381 = 0; (l381 < 2); l381 = (l381 + 1)) {
			fRec533[l381] = 0.0;
			
		}
		for (int l382 = 0; (l382 < 2); l382 = (l382 + 1)) {
			fRec531[l382] = 0.0;
			
		}
		for (int l383 = 0; (l383 < 128); l383 = (l383 + 1)) {
			fVec16[l383] = 0.0;
			
		}
		for (int l384 = 0; (l384 < 2); l384 = (l384 + 1)) {
			fRec548[l384] = 0.0;
			
		}
		for (int l385 = 0; (l385 < 2); l385 = (l385 + 1)) {
			fRec546[l385] = 0.0;
			
		}
		for (int l386 = 0; (l386 < 2); l386 = (l386 + 1)) {
			fRec545[l386] = 0.0;
			
		}
		for (int l387 = 0; (l387 < 2); l387 = (l387 + 1)) {
			fRec543[l387] = 0.0;
			
		}
		for (int l388 = 0; (l388 < 2); l388 = (l388 + 1)) {
			fRec542[l388] = 0.0;
			
		}
		for (int l389 = 0; (l389 < 2); l389 = (l389 + 1)) {
			fRec540[l389] = 0.0;
			
		}
		for (int l390 = 0; (l390 < 2); l390 = (l390 + 1)) {
			fRec539[l390] = 0.0;
			
		}
		for (int l391 = 0; (l391 < 2); l391 = (l391 + 1)) {
			fRec537[l391] = 0.0;
			
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
			fRec560[l398] = 0.0;
			
		}
		for (int l399 = 0; (l399 < 2); l399 = (l399 + 1)) {
			fRec558[l399] = 0.0;
			
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
		for (int l404 = 0; (l404 < 128); l404 = (l404 + 1)) {
			fVec17[l404] = 0.0;
			
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec578[l405] = 0.0;
			
		}
		for (int l406 = 0; (l406 < 2); l406 = (l406 + 1)) {
			fRec576[l406] = 0.0;
			
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec575[l407] = 0.0;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec573[l408] = 0.0;
			
		}
		for (int l409 = 0; (l409 < 2); l409 = (l409 + 1)) {
			fRec572[l409] = 0.0;
			
		}
		for (int l410 = 0; (l410 < 2); l410 = (l410 + 1)) {
			fRec570[l410] = 0.0;
			
		}
		for (int l411 = 0; (l411 < 2); l411 = (l411 + 1)) {
			fRec569[l411] = 0.0;
			
		}
		for (int l412 = 0; (l412 < 2); l412 = (l412 + 1)) {
			fRec567[l412] = 0.0;
			
		}
		for (int l413 = 0; (l413 < 2); l413 = (l413 + 1)) {
			fRec587[l413] = 0.0;
			
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec585[l414] = 0.0;
			
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec584[l415] = 0.0;
			
		}
		for (int l416 = 0; (l416 < 2); l416 = (l416 + 1)) {
			fRec582[l416] = 0.0;
			
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec581[l417] = 0.0;
			
		}
		for (int l418 = 0; (l418 < 2); l418 = (l418 + 1)) {
			fRec579[l418] = 0.0;
			
		}
		for (int l419 = 0; (l419 < 2); l419 = (l419 + 1)) {
			fRec590[l419] = 0.0;
			
		}
		for (int l420 = 0; (l420 < 2); l420 = (l420 + 1)) {
			fRec588[l420] = 0.0;
			
		}
		for (int l421 = 0; (l421 < 2); l421 = (l421 + 1)) {
			fRec596[l421] = 0.0;
			
		}
		for (int l422 = 0; (l422 < 2); l422 = (l422 + 1)) {
			fRec594[l422] = 0.0;
			
		}
		for (int l423 = 0; (l423 < 2); l423 = (l423 + 1)) {
			fRec593[l423] = 0.0;
			
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec591[l424] = 0.0;
			
		}
		for (int l425 = 0; (l425 < 128); l425 = (l425 + 1)) {
			fVec18[l425] = 0.0;
			
		}
		for (int l426 = 0; (l426 < 2); l426 = (l426 + 1)) {
			fRec608[l426] = 0.0;
			
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec606[l427] = 0.0;
			
		}
		for (int l428 = 0; (l428 < 2); l428 = (l428 + 1)) {
			fRec605[l428] = 0.0;
			
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec603[l429] = 0.0;
			
		}
		for (int l430 = 0; (l430 < 2); l430 = (l430 + 1)) {
			fRec602[l430] = 0.0;
			
		}
		for (int l431 = 0; (l431 < 2); l431 = (l431 + 1)) {
			fRec600[l431] = 0.0;
			
		}
		for (int l432 = 0; (l432 < 2); l432 = (l432 + 1)) {
			fRec599[l432] = 0.0;
			
		}
		for (int l433 = 0; (l433 < 2); l433 = (l433 + 1)) {
			fRec597[l433] = 0.0;
			
		}
		for (int l434 = 0; (l434 < 2); l434 = (l434 + 1)) {
			fRec617[l434] = 0.0;
			
		}
		for (int l435 = 0; (l435 < 2); l435 = (l435 + 1)) {
			fRec615[l435] = 0.0;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec614[l436] = 0.0;
			
		}
		for (int l437 = 0; (l437 < 2); l437 = (l437 + 1)) {
			fRec612[l437] = 0.0;
			
		}
		for (int l438 = 0; (l438 < 2); l438 = (l438 + 1)) {
			fRec611[l438] = 0.0;
			
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec609[l439] = 0.0;
			
		}
		for (int l440 = 0; (l440 < 2); l440 = (l440 + 1)) {
			fRec620[l440] = 0.0;
			
		}
		for (int l441 = 0; (l441 < 2); l441 = (l441 + 1)) {
			fRec618[l441] = 0.0;
			
		}
		for (int l442 = 0; (l442 < 2); l442 = (l442 + 1)) {
			fRec626[l442] = 0.0;
			
		}
		for (int l443 = 0; (l443 < 2); l443 = (l443 + 1)) {
			fRec624[l443] = 0.0;
			
		}
		for (int l444 = 0; (l444 < 2); l444 = (l444 + 1)) {
			fRec623[l444] = 0.0;
			
		}
		for (int l445 = 0; (l445 < 2); l445 = (l445 + 1)) {
			fRec621[l445] = 0.0;
			
		}
		for (int l446 = 0; (l446 < 128); l446 = (l446 + 1)) {
			fVec19[l446] = 0.0;
			
		}
		for (int l447 = 0; (l447 < 2); l447 = (l447 + 1)) {
			fRec638[l447] = 0.0;
			
		}
		for (int l448 = 0; (l448 < 2); l448 = (l448 + 1)) {
			fRec636[l448] = 0.0;
			
		}
		for (int l449 = 0; (l449 < 2); l449 = (l449 + 1)) {
			fRec635[l449] = 0.0;
			
		}
		for (int l450 = 0; (l450 < 2); l450 = (l450 + 1)) {
			fRec633[l450] = 0.0;
			
		}
		for (int l451 = 0; (l451 < 2); l451 = (l451 + 1)) {
			fRec632[l451] = 0.0;
			
		}
		for (int l452 = 0; (l452 < 2); l452 = (l452 + 1)) {
			fRec630[l452] = 0.0;
			
		}
		for (int l453 = 0; (l453 < 2); l453 = (l453 + 1)) {
			fRec629[l453] = 0.0;
			
		}
		for (int l454 = 0; (l454 < 2); l454 = (l454 + 1)) {
			fRec627[l454] = 0.0;
			
		}
		for (int l455 = 0; (l455 < 2); l455 = (l455 + 1)) {
			fRec647[l455] = 0.0;
			
		}
		for (int l456 = 0; (l456 < 2); l456 = (l456 + 1)) {
			fRec645[l456] = 0.0;
			
		}
		for (int l457 = 0; (l457 < 2); l457 = (l457 + 1)) {
			fRec644[l457] = 0.0;
			
		}
		for (int l458 = 0; (l458 < 2); l458 = (l458 + 1)) {
			fRec642[l458] = 0.0;
			
		}
		for (int l459 = 0; (l459 < 2); l459 = (l459 + 1)) {
			fRec641[l459] = 0.0;
			
		}
		for (int l460 = 0; (l460 < 2); l460 = (l460 + 1)) {
			fRec639[l460] = 0.0;
			
		}
		for (int l461 = 0; (l461 < 2); l461 = (l461 + 1)) {
			fRec650[l461] = 0.0;
			
		}
		for (int l462 = 0; (l462 < 2); l462 = (l462 + 1)) {
			fRec648[l462] = 0.0;
			
		}
		for (int l463 = 0; (l463 < 2); l463 = (l463 + 1)) {
			fRec656[l463] = 0.0;
			
		}
		for (int l464 = 0; (l464 < 2); l464 = (l464 + 1)) {
			fRec654[l464] = 0.0;
			
		}
		for (int l465 = 0; (l465 < 2); l465 = (l465 + 1)) {
			fRec653[l465] = 0.0;
			
		}
		for (int l466 = 0; (l466 < 2); l466 = (l466 + 1)) {
			fRec651[l466] = 0.0;
			
		}
		for (int l467 = 0; (l467 < 128); l467 = (l467 + 1)) {
			fVec20[l467] = 0.0;
			
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
		for (int l472 = 0; (l472 < 2); l472 = (l472 + 1)) {
			fRec662[l472] = 0.0;
			
		}
		for (int l473 = 0; (l473 < 2); l473 = (l473 + 1)) {
			fRec660[l473] = 0.0;
			
		}
		for (int l474 = 0; (l474 < 2); l474 = (l474 + 1)) {
			fRec659[l474] = 0.0;
			
		}
		for (int l475 = 0; (l475 < 2); l475 = (l475 + 1)) {
			fRec657[l475] = 0.0;
			
		}
		for (int l476 = 0; (l476 < 2); l476 = (l476 + 1)) {
			fRec677[l476] = 0.0;
			
		}
		for (int l477 = 0; (l477 < 2); l477 = (l477 + 1)) {
			fRec675[l477] = 0.0;
			
		}
		for (int l478 = 0; (l478 < 2); l478 = (l478 + 1)) {
			fRec674[l478] = 0.0;
			
		}
		for (int l479 = 0; (l479 < 2); l479 = (l479 + 1)) {
			fRec672[l479] = 0.0;
			
		}
		for (int l480 = 0; (l480 < 2); l480 = (l480 + 1)) {
			fRec671[l480] = 0.0;
			
		}
		for (int l481 = 0; (l481 < 2); l481 = (l481 + 1)) {
			fRec669[l481] = 0.0;
			
		}
		for (int l482 = 0; (l482 < 2); l482 = (l482 + 1)) {
			fRec680[l482] = 0.0;
			
		}
		for (int l483 = 0; (l483 < 2); l483 = (l483 + 1)) {
			fRec678[l483] = 0.0;
			
		}
		for (int l484 = 0; (l484 < 2); l484 = (l484 + 1)) {
			fRec686[l484] = 0.0;
			
		}
		for (int l485 = 0; (l485 < 2); l485 = (l485 + 1)) {
			fRec684[l485] = 0.0;
			
		}
		for (int l486 = 0; (l486 < 2); l486 = (l486 + 1)) {
			fRec683[l486] = 0.0;
			
		}
		for (int l487 = 0; (l487 < 2); l487 = (l487 + 1)) {
			fRec681[l487] = 0.0;
			
		}
		for (int l488 = 0; (l488 < 128); l488 = (l488 + 1)) {
			fVec21[l488] = 0.0;
			
		}
		for (int l489 = 0; (l489 < 2); l489 = (l489 + 1)) {
			fRec698[l489] = 0.0;
			
		}
		for (int l490 = 0; (l490 < 2); l490 = (l490 + 1)) {
			fRec696[l490] = 0.0;
			
		}
		for (int l491 = 0; (l491 < 2); l491 = (l491 + 1)) {
			fRec695[l491] = 0.0;
			
		}
		for (int l492 = 0; (l492 < 2); l492 = (l492 + 1)) {
			fRec693[l492] = 0.0;
			
		}
		for (int l493 = 0; (l493 < 2); l493 = (l493 + 1)) {
			fRec692[l493] = 0.0;
			
		}
		for (int l494 = 0; (l494 < 2); l494 = (l494 + 1)) {
			fRec690[l494] = 0.0;
			
		}
		for (int l495 = 0; (l495 < 2); l495 = (l495 + 1)) {
			fRec689[l495] = 0.0;
			
		}
		for (int l496 = 0; (l496 < 2); l496 = (l496 + 1)) {
			fRec687[l496] = 0.0;
			
		}
		for (int l497 = 0; (l497 < 2); l497 = (l497 + 1)) {
			fRec707[l497] = 0.0;
			
		}
		for (int l498 = 0; (l498 < 2); l498 = (l498 + 1)) {
			fRec705[l498] = 0.0;
			
		}
		for (int l499 = 0; (l499 < 2); l499 = (l499 + 1)) {
			fRec704[l499] = 0.0;
			
		}
		for (int l500 = 0; (l500 < 2); l500 = (l500 + 1)) {
			fRec702[l500] = 0.0;
			
		}
		for (int l501 = 0; (l501 < 2); l501 = (l501 + 1)) {
			fRec701[l501] = 0.0;
			
		}
		for (int l502 = 0; (l502 < 2); l502 = (l502 + 1)) {
			fRec699[l502] = 0.0;
			
		}
		for (int l503 = 0; (l503 < 2); l503 = (l503 + 1)) {
			fRec710[l503] = 0.0;
			
		}
		for (int l504 = 0; (l504 < 2); l504 = (l504 + 1)) {
			fRec708[l504] = 0.0;
			
		}
		for (int l505 = 0; (l505 < 2); l505 = (l505 + 1)) {
			fRec716[l505] = 0.0;
			
		}
		for (int l506 = 0; (l506 < 2); l506 = (l506 + 1)) {
			fRec714[l506] = 0.0;
			
		}
		for (int l507 = 0; (l507 < 2); l507 = (l507 + 1)) {
			fRec713[l507] = 0.0;
			
		}
		for (int l508 = 0; (l508 < 2); l508 = (l508 + 1)) {
			fRec711[l508] = 0.0;
			
		}
		for (int l509 = 0; (l509 < 128); l509 = (l509 + 1)) {
			fVec22[l509] = 0.0;
			
		}
		for (int l510 = 0; (l510 < 2); l510 = (l510 + 1)) {
			fRec728[l510] = 0.0;
			
		}
		for (int l511 = 0; (l511 < 2); l511 = (l511 + 1)) {
			fRec726[l511] = 0.0;
			
		}
		for (int l512 = 0; (l512 < 2); l512 = (l512 + 1)) {
			fRec725[l512] = 0.0;
			
		}
		for (int l513 = 0; (l513 < 2); l513 = (l513 + 1)) {
			fRec723[l513] = 0.0;
			
		}
		for (int l514 = 0; (l514 < 2); l514 = (l514 + 1)) {
			fRec722[l514] = 0.0;
			
		}
		for (int l515 = 0; (l515 < 2); l515 = (l515 + 1)) {
			fRec720[l515] = 0.0;
			
		}
		for (int l516 = 0; (l516 < 2); l516 = (l516 + 1)) {
			fRec719[l516] = 0.0;
			
		}
		for (int l517 = 0; (l517 < 2); l517 = (l517 + 1)) {
			fRec717[l517] = 0.0;
			
		}
		for (int l518 = 0; (l518 < 2); l518 = (l518 + 1)) {
			fRec737[l518] = 0.0;
			
		}
		for (int l519 = 0; (l519 < 2); l519 = (l519 + 1)) {
			fRec735[l519] = 0.0;
			
		}
		for (int l520 = 0; (l520 < 2); l520 = (l520 + 1)) {
			fRec734[l520] = 0.0;
			
		}
		for (int l521 = 0; (l521 < 2); l521 = (l521 + 1)) {
			fRec732[l521] = 0.0;
			
		}
		for (int l522 = 0; (l522 < 2); l522 = (l522 + 1)) {
			fRec731[l522] = 0.0;
			
		}
		for (int l523 = 0; (l523 < 2); l523 = (l523 + 1)) {
			fRec729[l523] = 0.0;
			
		}
		for (int l524 = 0; (l524 < 2); l524 = (l524 + 1)) {
			fRec740[l524] = 0.0;
			
		}
		for (int l525 = 0; (l525 < 2); l525 = (l525 + 1)) {
			fRec738[l525] = 0.0;
			
		}
		for (int l526 = 0; (l526 < 2); l526 = (l526 + 1)) {
			fRec746[l526] = 0.0;
			
		}
		for (int l527 = 0; (l527 < 2); l527 = (l527 + 1)) {
			fRec744[l527] = 0.0;
			
		}
		for (int l528 = 0; (l528 < 2); l528 = (l528 + 1)) {
			fRec743[l528] = 0.0;
			
		}
		for (int l529 = 0; (l529 < 2); l529 = (l529 + 1)) {
			fRec741[l529] = 0.0;
			
		}
		for (int l530 = 0; (l530 < 128); l530 = (l530 + 1)) {
			fVec23[l530] = 0.0;
			
		}
		for (int l531 = 0; (l531 < 2); l531 = (l531 + 1)) {
			fRec758[l531] = 0.0;
			
		}
		for (int l532 = 0; (l532 < 2); l532 = (l532 + 1)) {
			fRec756[l532] = 0.0;
			
		}
		for (int l533 = 0; (l533 < 2); l533 = (l533 + 1)) {
			fRec755[l533] = 0.0;
			
		}
		for (int l534 = 0; (l534 < 2); l534 = (l534 + 1)) {
			fRec753[l534] = 0.0;
			
		}
		for (int l535 = 0; (l535 < 2); l535 = (l535 + 1)) {
			fRec752[l535] = 0.0;
			
		}
		for (int l536 = 0; (l536 < 2); l536 = (l536 + 1)) {
			fRec750[l536] = 0.0;
			
		}
		for (int l537 = 0; (l537 < 2); l537 = (l537 + 1)) {
			fRec749[l537] = 0.0;
			
		}
		for (int l538 = 0; (l538 < 2); l538 = (l538 + 1)) {
			fRec747[l538] = 0.0;
			
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
			fRec770[l545] = 0.0;
			
		}
		for (int l546 = 0; (l546 < 2); l546 = (l546 + 1)) {
			fRec768[l546] = 0.0;
			
		}
		for (int l547 = 0; (l547 < 2); l547 = (l547 + 1)) {
			fRec776[l547] = 0.0;
			
		}
		for (int l548 = 0; (l548 < 2); l548 = (l548 + 1)) {
			fRec774[l548] = 0.0;
			
		}
		for (int l549 = 0; (l549 < 2); l549 = (l549 + 1)) {
			fRec773[l549] = 0.0;
			
		}
		for (int l550 = 0; (l550 < 2); l550 = (l550 + 1)) {
			fRec771[l550] = 0.0;
			
		}
		for (int l551 = 0; (l551 < 12); l551 = (l551 + 1)) {
			fVec24[l551] = 0.0;
			
		}
		for (int l552 = 0; (l552 < 2); l552 = (l552 + 1)) {
			fRec788[l552] = 0.0;
			
		}
		for (int l553 = 0; (l553 < 2); l553 = (l553 + 1)) {
			fRec786[l553] = 0.0;
			
		}
		for (int l554 = 0; (l554 < 2); l554 = (l554 + 1)) {
			fRec785[l554] = 0.0;
			
		}
		for (int l555 = 0; (l555 < 2); l555 = (l555 + 1)) {
			fRec783[l555] = 0.0;
			
		}
		for (int l556 = 0; (l556 < 2); l556 = (l556 + 1)) {
			fRec782[l556] = 0.0;
			
		}
		for (int l557 = 0; (l557 < 2); l557 = (l557 + 1)) {
			fRec780[l557] = 0.0;
			
		}
		for (int l558 = 0; (l558 < 2); l558 = (l558 + 1)) {
			fRec779[l558] = 0.0;
			
		}
		for (int l559 = 0; (l559 < 2); l559 = (l559 + 1)) {
			fRec777[l559] = 0.0;
			
		}
		for (int l560 = 0; (l560 < 2); l560 = (l560 + 1)) {
			fRec797[l560] = 0.0;
			
		}
		for (int l561 = 0; (l561 < 2); l561 = (l561 + 1)) {
			fRec795[l561] = 0.0;
			
		}
		for (int l562 = 0; (l562 < 2); l562 = (l562 + 1)) {
			fRec794[l562] = 0.0;
			
		}
		for (int l563 = 0; (l563 < 2); l563 = (l563 + 1)) {
			fRec792[l563] = 0.0;
			
		}
		for (int l564 = 0; (l564 < 2); l564 = (l564 + 1)) {
			fRec791[l564] = 0.0;
			
		}
		for (int l565 = 0; (l565 < 2); l565 = (l565 + 1)) {
			fRec789[l565] = 0.0;
			
		}
		for (int l566 = 0; (l566 < 2); l566 = (l566 + 1)) {
			fRec800[l566] = 0.0;
			
		}
		for (int l567 = 0; (l567 < 2); l567 = (l567 + 1)) {
			fRec798[l567] = 0.0;
			
		}
		for (int l568 = 0; (l568 < 2); l568 = (l568 + 1)) {
			fRec806[l568] = 0.0;
			
		}
		for (int l569 = 0; (l569 < 2); l569 = (l569 + 1)) {
			fRec804[l569] = 0.0;
			
		}
		for (int l570 = 0; (l570 < 2); l570 = (l570 + 1)) {
			fRec803[l570] = 0.0;
			
		}
		for (int l571 = 0; (l571 < 2); l571 = (l571 + 1)) {
			fRec801[l571] = 0.0;
			
		}
		for (int l572 = 0; (l572 < 12); l572 = (l572 + 1)) {
			fVec25[l572] = 0.0;
			
		}
		for (int l573 = 0; (l573 < 2); l573 = (l573 + 1)) {
			fRec818[l573] = 0.0;
			
		}
		for (int l574 = 0; (l574 < 2); l574 = (l574 + 1)) {
			fRec816[l574] = 0.0;
			
		}
		for (int l575 = 0; (l575 < 2); l575 = (l575 + 1)) {
			fRec815[l575] = 0.0;
			
		}
		for (int l576 = 0; (l576 < 2); l576 = (l576 + 1)) {
			fRec813[l576] = 0.0;
			
		}
		for (int l577 = 0; (l577 < 2); l577 = (l577 + 1)) {
			fRec812[l577] = 0.0;
			
		}
		for (int l578 = 0; (l578 < 2); l578 = (l578 + 1)) {
			fRec810[l578] = 0.0;
			
		}
		for (int l579 = 0; (l579 < 2); l579 = (l579 + 1)) {
			fRec809[l579] = 0.0;
			
		}
		for (int l580 = 0; (l580 < 2); l580 = (l580 + 1)) {
			fRec807[l580] = 0.0;
			
		}
		for (int l581 = 0; (l581 < 2); l581 = (l581 + 1)) {
			fRec827[l581] = 0.0;
			
		}
		for (int l582 = 0; (l582 < 2); l582 = (l582 + 1)) {
			fRec825[l582] = 0.0;
			
		}
		for (int l583 = 0; (l583 < 2); l583 = (l583 + 1)) {
			fRec824[l583] = 0.0;
			
		}
		for (int l584 = 0; (l584 < 2); l584 = (l584 + 1)) {
			fRec822[l584] = 0.0;
			
		}
		for (int l585 = 0; (l585 < 2); l585 = (l585 + 1)) {
			fRec821[l585] = 0.0;
			
		}
		for (int l586 = 0; (l586 < 2); l586 = (l586 + 1)) {
			fRec819[l586] = 0.0;
			
		}
		for (int l587 = 0; (l587 < 2); l587 = (l587 + 1)) {
			fRec830[l587] = 0.0;
			
		}
		for (int l588 = 0; (l588 < 2); l588 = (l588 + 1)) {
			fRec828[l588] = 0.0;
			
		}
		for (int l589 = 0; (l589 < 2); l589 = (l589 + 1)) {
			fRec836[l589] = 0.0;
			
		}
		for (int l590 = 0; (l590 < 2); l590 = (l590 + 1)) {
			fRec834[l590] = 0.0;
			
		}
		for (int l591 = 0; (l591 < 2); l591 = (l591 + 1)) {
			fRec833[l591] = 0.0;
			
		}
		for (int l592 = 0; (l592 < 2); l592 = (l592 + 1)) {
			fRec831[l592] = 0.0;
			
		}
		for (int l593 = 0; (l593 < 12); l593 = (l593 + 1)) {
			fVec26[l593] = 0.0;
			
		}
		for (int l594 = 0; (l594 < 2); l594 = (l594 + 1)) {
			fRec848[l594] = 0.0;
			
		}
		for (int l595 = 0; (l595 < 2); l595 = (l595 + 1)) {
			fRec846[l595] = 0.0;
			
		}
		for (int l596 = 0; (l596 < 2); l596 = (l596 + 1)) {
			fRec845[l596] = 0.0;
			
		}
		for (int l597 = 0; (l597 < 2); l597 = (l597 + 1)) {
			fRec843[l597] = 0.0;
			
		}
		for (int l598 = 0; (l598 < 2); l598 = (l598 + 1)) {
			fRec842[l598] = 0.0;
			
		}
		for (int l599 = 0; (l599 < 2); l599 = (l599 + 1)) {
			fRec840[l599] = 0.0;
			
		}
		for (int l600 = 0; (l600 < 2); l600 = (l600 + 1)) {
			fRec839[l600] = 0.0;
			
		}
		for (int l601 = 0; (l601 < 2); l601 = (l601 + 1)) {
			fRec837[l601] = 0.0;
			
		}
		for (int l602 = 0; (l602 < 2); l602 = (l602 + 1)) {
			fRec857[l602] = 0.0;
			
		}
		for (int l603 = 0; (l603 < 2); l603 = (l603 + 1)) {
			fRec855[l603] = 0.0;
			
		}
		for (int l604 = 0; (l604 < 2); l604 = (l604 + 1)) {
			fRec854[l604] = 0.0;
			
		}
		for (int l605 = 0; (l605 < 2); l605 = (l605 + 1)) {
			fRec852[l605] = 0.0;
			
		}
		for (int l606 = 0; (l606 < 2); l606 = (l606 + 1)) {
			fRec851[l606] = 0.0;
			
		}
		for (int l607 = 0; (l607 < 2); l607 = (l607 + 1)) {
			fRec849[l607] = 0.0;
			
		}
		for (int l608 = 0; (l608 < 2); l608 = (l608 + 1)) {
			fRec860[l608] = 0.0;
			
		}
		for (int l609 = 0; (l609 < 2); l609 = (l609 + 1)) {
			fRec858[l609] = 0.0;
			
		}
		for (int l610 = 0; (l610 < 2); l610 = (l610 + 1)) {
			fRec866[l610] = 0.0;
			
		}
		for (int l611 = 0; (l611 < 2); l611 = (l611 + 1)) {
			fRec864[l611] = 0.0;
			
		}
		for (int l612 = 0; (l612 < 2); l612 = (l612 + 1)) {
			fRec863[l612] = 0.0;
			
		}
		for (int l613 = 0; (l613 < 2); l613 = (l613 + 1)) {
			fRec861[l613] = 0.0;
			
		}
		for (int l614 = 0; (l614 < 12); l614 = (l614 + 1)) {
			fVec27[l614] = 0.0;
			
		}
		for (int l615 = 0; (l615 < 2); l615 = (l615 + 1)) {
			fRec878[l615] = 0.0;
			
		}
		for (int l616 = 0; (l616 < 2); l616 = (l616 + 1)) {
			fRec876[l616] = 0.0;
			
		}
		for (int l617 = 0; (l617 < 2); l617 = (l617 + 1)) {
			fRec875[l617] = 0.0;
			
		}
		for (int l618 = 0; (l618 < 2); l618 = (l618 + 1)) {
			fRec873[l618] = 0.0;
			
		}
		for (int l619 = 0; (l619 < 2); l619 = (l619 + 1)) {
			fRec872[l619] = 0.0;
			
		}
		for (int l620 = 0; (l620 < 2); l620 = (l620 + 1)) {
			fRec870[l620] = 0.0;
			
		}
		for (int l621 = 0; (l621 < 2); l621 = (l621 + 1)) {
			fRec869[l621] = 0.0;
			
		}
		for (int l622 = 0; (l622 < 2); l622 = (l622 + 1)) {
			fRec867[l622] = 0.0;
			
		}
		for (int l623 = 0; (l623 < 2); l623 = (l623 + 1)) {
			fRec887[l623] = 0.0;
			
		}
		for (int l624 = 0; (l624 < 2); l624 = (l624 + 1)) {
			fRec885[l624] = 0.0;
			
		}
		for (int l625 = 0; (l625 < 2); l625 = (l625 + 1)) {
			fRec884[l625] = 0.0;
			
		}
		for (int l626 = 0; (l626 < 2); l626 = (l626 + 1)) {
			fRec882[l626] = 0.0;
			
		}
		for (int l627 = 0; (l627 < 2); l627 = (l627 + 1)) {
			fRec881[l627] = 0.0;
			
		}
		for (int l628 = 0; (l628 < 2); l628 = (l628 + 1)) {
			fRec879[l628] = 0.0;
			
		}
		for (int l629 = 0; (l629 < 2); l629 = (l629 + 1)) {
			fRec890[l629] = 0.0;
			
		}
		for (int l630 = 0; (l630 < 2); l630 = (l630 + 1)) {
			fRec888[l630] = 0.0;
			
		}
		for (int l631 = 0; (l631 < 2); l631 = (l631 + 1)) {
			fRec896[l631] = 0.0;
			
		}
		for (int l632 = 0; (l632 < 2); l632 = (l632 + 1)) {
			fRec894[l632] = 0.0;
			
		}
		for (int l633 = 0; (l633 < 2); l633 = (l633 + 1)) {
			fRec893[l633] = 0.0;
			
		}
		for (int l634 = 0; (l634 < 2); l634 = (l634 + 1)) {
			fRec891[l634] = 0.0;
			
		}
		for (int l635 = 0; (l635 < 2); l635 = (l635 + 1)) {
			fRec908[l635] = 0.0;
			
		}
		for (int l636 = 0; (l636 < 2); l636 = (l636 + 1)) {
			fRec906[l636] = 0.0;
			
		}
		for (int l637 = 0; (l637 < 2); l637 = (l637 + 1)) {
			fRec905[l637] = 0.0;
			
		}
		for (int l638 = 0; (l638 < 2); l638 = (l638 + 1)) {
			fRec903[l638] = 0.0;
			
		}
		for (int l639 = 0; (l639 < 2); l639 = (l639 + 1)) {
			fRec902[l639] = 0.0;
			
		}
		for (int l640 = 0; (l640 < 2); l640 = (l640 + 1)) {
			fRec900[l640] = 0.0;
			
		}
		for (int l641 = 0; (l641 < 2); l641 = (l641 + 1)) {
			fRec899[l641] = 0.0;
			
		}
		for (int l642 = 0; (l642 < 2); l642 = (l642 + 1)) {
			fRec897[l642] = 0.0;
			
		}
		for (int l643 = 0; (l643 < 2); l643 = (l643 + 1)) {
			fRec917[l643] = 0.0;
			
		}
		for (int l644 = 0; (l644 < 2); l644 = (l644 + 1)) {
			fRec915[l644] = 0.0;
			
		}
		for (int l645 = 0; (l645 < 2); l645 = (l645 + 1)) {
			fRec914[l645] = 0.0;
			
		}
		for (int l646 = 0; (l646 < 2); l646 = (l646 + 1)) {
			fRec912[l646] = 0.0;
			
		}
		for (int l647 = 0; (l647 < 2); l647 = (l647 + 1)) {
			fRec911[l647] = 0.0;
			
		}
		for (int l648 = 0; (l648 < 2); l648 = (l648 + 1)) {
			fRec909[l648] = 0.0;
			
		}
		for (int l649 = 0; (l649 < 2); l649 = (l649 + 1)) {
			fRec920[l649] = 0.0;
			
		}
		for (int l650 = 0; (l650 < 2); l650 = (l650 + 1)) {
			fRec918[l650] = 0.0;
			
		}
		for (int l651 = 0; (l651 < 2); l651 = (l651 + 1)) {
			fRec926[l651] = 0.0;
			
		}
		for (int l652 = 0; (l652 < 2); l652 = (l652 + 1)) {
			fRec924[l652] = 0.0;
			
		}
		for (int l653 = 0; (l653 < 2); l653 = (l653 + 1)) {
			fRec923[l653] = 0.0;
			
		}
		for (int l654 = 0; (l654 < 2); l654 = (l654 + 1)) {
			fRec921[l654] = 0.0;
			
		}
		for (int l655 = 0; (l655 < 512); l655 = (l655 + 1)) {
			fVec28[l655] = 0.0;
			
		}
		for (int l656 = 0; (l656 < 2); l656 = (l656 + 1)) {
			fRec938[l656] = 0.0;
			
		}
		for (int l657 = 0; (l657 < 2); l657 = (l657 + 1)) {
			fRec936[l657] = 0.0;
			
		}
		for (int l658 = 0; (l658 < 2); l658 = (l658 + 1)) {
			fRec935[l658] = 0.0;
			
		}
		for (int l659 = 0; (l659 < 2); l659 = (l659 + 1)) {
			fRec933[l659] = 0.0;
			
		}
		for (int l660 = 0; (l660 < 2); l660 = (l660 + 1)) {
			fRec932[l660] = 0.0;
			
		}
		for (int l661 = 0; (l661 < 2); l661 = (l661 + 1)) {
			fRec930[l661] = 0.0;
			
		}
		for (int l662 = 0; (l662 < 2); l662 = (l662 + 1)) {
			fRec929[l662] = 0.0;
			
		}
		for (int l663 = 0; (l663 < 2); l663 = (l663 + 1)) {
			fRec927[l663] = 0.0;
			
		}
		for (int l664 = 0; (l664 < 2); l664 = (l664 + 1)) {
			fRec947[l664] = 0.0;
			
		}
		for (int l665 = 0; (l665 < 2); l665 = (l665 + 1)) {
			fRec945[l665] = 0.0;
			
		}
		for (int l666 = 0; (l666 < 2); l666 = (l666 + 1)) {
			fRec944[l666] = 0.0;
			
		}
		for (int l667 = 0; (l667 < 2); l667 = (l667 + 1)) {
			fRec942[l667] = 0.0;
			
		}
		for (int l668 = 0; (l668 < 2); l668 = (l668 + 1)) {
			fRec941[l668] = 0.0;
			
		}
		for (int l669 = 0; (l669 < 2); l669 = (l669 + 1)) {
			fRec939[l669] = 0.0;
			
		}
		for (int l670 = 0; (l670 < 2); l670 = (l670 + 1)) {
			fRec950[l670] = 0.0;
			
		}
		for (int l671 = 0; (l671 < 2); l671 = (l671 + 1)) {
			fRec948[l671] = 0.0;
			
		}
		for (int l672 = 0; (l672 < 2); l672 = (l672 + 1)) {
			fRec956[l672] = 0.0;
			
		}
		for (int l673 = 0; (l673 < 2); l673 = (l673 + 1)) {
			fRec954[l673] = 0.0;
			
		}
		for (int l674 = 0; (l674 < 2); l674 = (l674 + 1)) {
			fRec953[l674] = 0.0;
			
		}
		for (int l675 = 0; (l675 < 2); l675 = (l675 + 1)) {
			fRec951[l675] = 0.0;
			
		}
		for (int l676 = 0; (l676 < 512); l676 = (l676 + 1)) {
			fVec29[l676] = 0.0;
			
		}
		for (int l677 = 0; (l677 < 2); l677 = (l677 + 1)) {
			fRec968[l677] = 0.0;
			
		}
		for (int l678 = 0; (l678 < 2); l678 = (l678 + 1)) {
			fRec966[l678] = 0.0;
			
		}
		for (int l679 = 0; (l679 < 2); l679 = (l679 + 1)) {
			fRec965[l679] = 0.0;
			
		}
		for (int l680 = 0; (l680 < 2); l680 = (l680 + 1)) {
			fRec963[l680] = 0.0;
			
		}
		for (int l681 = 0; (l681 < 2); l681 = (l681 + 1)) {
			fRec962[l681] = 0.0;
			
		}
		for (int l682 = 0; (l682 < 2); l682 = (l682 + 1)) {
			fRec960[l682] = 0.0;
			
		}
		for (int l683 = 0; (l683 < 2); l683 = (l683 + 1)) {
			fRec959[l683] = 0.0;
			
		}
		for (int l684 = 0; (l684 < 2); l684 = (l684 + 1)) {
			fRec957[l684] = 0.0;
			
		}
		for (int l685 = 0; (l685 < 2); l685 = (l685 + 1)) {
			fRec977[l685] = 0.0;
			
		}
		for (int l686 = 0; (l686 < 2); l686 = (l686 + 1)) {
			fRec975[l686] = 0.0;
			
		}
		for (int l687 = 0; (l687 < 2); l687 = (l687 + 1)) {
			fRec974[l687] = 0.0;
			
		}
		for (int l688 = 0; (l688 < 2); l688 = (l688 + 1)) {
			fRec972[l688] = 0.0;
			
		}
		for (int l689 = 0; (l689 < 2); l689 = (l689 + 1)) {
			fRec971[l689] = 0.0;
			
		}
		for (int l690 = 0; (l690 < 2); l690 = (l690 + 1)) {
			fRec969[l690] = 0.0;
			
		}
		for (int l691 = 0; (l691 < 2); l691 = (l691 + 1)) {
			fRec980[l691] = 0.0;
			
		}
		for (int l692 = 0; (l692 < 2); l692 = (l692 + 1)) {
			fRec978[l692] = 0.0;
			
		}
		for (int l693 = 0; (l693 < 2); l693 = (l693 + 1)) {
			fRec986[l693] = 0.0;
			
		}
		for (int l694 = 0; (l694 < 2); l694 = (l694 + 1)) {
			fRec984[l694] = 0.0;
			
		}
		for (int l695 = 0; (l695 < 2); l695 = (l695 + 1)) {
			fRec983[l695] = 0.0;
			
		}
		for (int l696 = 0; (l696 < 2); l696 = (l696 + 1)) {
			fRec981[l696] = 0.0;
			
		}
		for (int l697 = 0; (l697 < 512); l697 = (l697 + 1)) {
			fVec30[l697] = 0.0;
			
		}
		for (int l698 = 0; (l698 < 2); l698 = (l698 + 1)) {
			fRec998[l698] = 0.0;
			
		}
		for (int l699 = 0; (l699 < 2); l699 = (l699 + 1)) {
			fRec996[l699] = 0.0;
			
		}
		for (int l700 = 0; (l700 < 2); l700 = (l700 + 1)) {
			fRec995[l700] = 0.0;
			
		}
		for (int l701 = 0; (l701 < 2); l701 = (l701 + 1)) {
			fRec993[l701] = 0.0;
			
		}
		for (int l702 = 0; (l702 < 2); l702 = (l702 + 1)) {
			fRec992[l702] = 0.0;
			
		}
		for (int l703 = 0; (l703 < 2); l703 = (l703 + 1)) {
			fRec990[l703] = 0.0;
			
		}
		for (int l704 = 0; (l704 < 2); l704 = (l704 + 1)) {
			fRec989[l704] = 0.0;
			
		}
		for (int l705 = 0; (l705 < 2); l705 = (l705 + 1)) {
			fRec987[l705] = 0.0;
			
		}
		for (int l706 = 0; (l706 < 2); l706 = (l706 + 1)) {
			fRec1007[l706] = 0.0;
			
		}
		for (int l707 = 0; (l707 < 2); l707 = (l707 + 1)) {
			fRec1005[l707] = 0.0;
			
		}
		for (int l708 = 0; (l708 < 2); l708 = (l708 + 1)) {
			fRec1004[l708] = 0.0;
			
		}
		for (int l709 = 0; (l709 < 2); l709 = (l709 + 1)) {
			fRec1002[l709] = 0.0;
			
		}
		for (int l710 = 0; (l710 < 2); l710 = (l710 + 1)) {
			fRec1001[l710] = 0.0;
			
		}
		for (int l711 = 0; (l711 < 2); l711 = (l711 + 1)) {
			fRec999[l711] = 0.0;
			
		}
		for (int l712 = 0; (l712 < 2); l712 = (l712 + 1)) {
			fRec1010[l712] = 0.0;
			
		}
		for (int l713 = 0; (l713 < 2); l713 = (l713 + 1)) {
			fRec1008[l713] = 0.0;
			
		}
		for (int l714 = 0; (l714 < 2); l714 = (l714 + 1)) {
			fRec1016[l714] = 0.0;
			
		}
		for (int l715 = 0; (l715 < 2); l715 = (l715 + 1)) {
			fRec1014[l715] = 0.0;
			
		}
		for (int l716 = 0; (l716 < 2); l716 = (l716 + 1)) {
			fRec1013[l716] = 0.0;
			
		}
		for (int l717 = 0; (l717 < 2); l717 = (l717 + 1)) {
			fRec1011[l717] = 0.0;
			
		}
		for (int l718 = 0; (l718 < 512); l718 = (l718 + 1)) {
			fVec31[l718] = 0.0;
			
		}
		for (int l719 = 0; (l719 < 2); l719 = (l719 + 1)) {
			fRec1028[l719] = 0.0;
			
		}
		for (int l720 = 0; (l720 < 2); l720 = (l720 + 1)) {
			fRec1026[l720] = 0.0;
			
		}
		for (int l721 = 0; (l721 < 2); l721 = (l721 + 1)) {
			fRec1025[l721] = 0.0;
			
		}
		for (int l722 = 0; (l722 < 2); l722 = (l722 + 1)) {
			fRec1023[l722] = 0.0;
			
		}
		for (int l723 = 0; (l723 < 2); l723 = (l723 + 1)) {
			fRec1022[l723] = 0.0;
			
		}
		for (int l724 = 0; (l724 < 2); l724 = (l724 + 1)) {
			fRec1020[l724] = 0.0;
			
		}
		for (int l725 = 0; (l725 < 2); l725 = (l725 + 1)) {
			fRec1019[l725] = 0.0;
			
		}
		for (int l726 = 0; (l726 < 2); l726 = (l726 + 1)) {
			fRec1017[l726] = 0.0;
			
		}
		for (int l727 = 0; (l727 < 2); l727 = (l727 + 1)) {
			fRec1037[l727] = 0.0;
			
		}
		for (int l728 = 0; (l728 < 2); l728 = (l728 + 1)) {
			fRec1035[l728] = 0.0;
			
		}
		for (int l729 = 0; (l729 < 2); l729 = (l729 + 1)) {
			fRec1034[l729] = 0.0;
			
		}
		for (int l730 = 0; (l730 < 2); l730 = (l730 + 1)) {
			fRec1032[l730] = 0.0;
			
		}
		for (int l731 = 0; (l731 < 2); l731 = (l731 + 1)) {
			fRec1031[l731] = 0.0;
			
		}
		for (int l732 = 0; (l732 < 2); l732 = (l732 + 1)) {
			fRec1029[l732] = 0.0;
			
		}
		for (int l733 = 0; (l733 < 2); l733 = (l733 + 1)) {
			fRec1040[l733] = 0.0;
			
		}
		for (int l734 = 0; (l734 < 2); l734 = (l734 + 1)) {
			fRec1038[l734] = 0.0;
			
		}
		for (int l735 = 0; (l735 < 2); l735 = (l735 + 1)) {
			fRec1046[l735] = 0.0;
			
		}
		for (int l736 = 0; (l736 < 2); l736 = (l736 + 1)) {
			fRec1044[l736] = 0.0;
			
		}
		for (int l737 = 0; (l737 < 2); l737 = (l737 + 1)) {
			fRec1043[l737] = 0.0;
			
		}
		for (int l738 = 0; (l738 < 2); l738 = (l738 + 1)) {
			fRec1041[l738] = 0.0;
			
		}
		for (int l739 = 0; (l739 < 512); l739 = (l739 + 1)) {
			fVec32[l739] = 0.0;
			
		}
		for (int l740 = 0; (l740 < 2); l740 = (l740 + 1)) {
			fRec1058[l740] = 0.0;
			
		}
		for (int l741 = 0; (l741 < 2); l741 = (l741 + 1)) {
			fRec1056[l741] = 0.0;
			
		}
		for (int l742 = 0; (l742 < 2); l742 = (l742 + 1)) {
			fRec1055[l742] = 0.0;
			
		}
		for (int l743 = 0; (l743 < 2); l743 = (l743 + 1)) {
			fRec1053[l743] = 0.0;
			
		}
		for (int l744 = 0; (l744 < 2); l744 = (l744 + 1)) {
			fRec1052[l744] = 0.0;
			
		}
		for (int l745 = 0; (l745 < 2); l745 = (l745 + 1)) {
			fRec1050[l745] = 0.0;
			
		}
		for (int l746 = 0; (l746 < 2); l746 = (l746 + 1)) {
			fRec1049[l746] = 0.0;
			
		}
		for (int l747 = 0; (l747 < 2); l747 = (l747 + 1)) {
			fRec1047[l747] = 0.0;
			
		}
		for (int l748 = 0; (l748 < 2); l748 = (l748 + 1)) {
			fRec1067[l748] = 0.0;
			
		}
		for (int l749 = 0; (l749 < 2); l749 = (l749 + 1)) {
			fRec1065[l749] = 0.0;
			
		}
		for (int l750 = 0; (l750 < 2); l750 = (l750 + 1)) {
			fRec1064[l750] = 0.0;
			
		}
		for (int l751 = 0; (l751 < 2); l751 = (l751 + 1)) {
			fRec1062[l751] = 0.0;
			
		}
		for (int l752 = 0; (l752 < 2); l752 = (l752 + 1)) {
			fRec1061[l752] = 0.0;
			
		}
		for (int l753 = 0; (l753 < 2); l753 = (l753 + 1)) {
			fRec1059[l753] = 0.0;
			
		}
		for (int l754 = 0; (l754 < 2); l754 = (l754 + 1)) {
			fRec1070[l754] = 0.0;
			
		}
		for (int l755 = 0; (l755 < 2); l755 = (l755 + 1)) {
			fRec1068[l755] = 0.0;
			
		}
		for (int l756 = 0; (l756 < 2); l756 = (l756 + 1)) {
			fRec1076[l756] = 0.0;
			
		}
		for (int l757 = 0; (l757 < 2); l757 = (l757 + 1)) {
			fRec1074[l757] = 0.0;
			
		}
		for (int l758 = 0; (l758 < 2); l758 = (l758 + 1)) {
			fRec1073[l758] = 0.0;
			
		}
		for (int l759 = 0; (l759 < 2); l759 = (l759 + 1)) {
			fRec1071[l759] = 0.0;
			
		}
		for (int l760 = 0; (l760 < 512); l760 = (l760 + 1)) {
			fVec33[l760] = 0.0;
			
		}
		for (int l761 = 0; (l761 < 2); l761 = (l761 + 1)) {
			fRec1088[l761] = 0.0;
			
		}
		for (int l762 = 0; (l762 < 2); l762 = (l762 + 1)) {
			fRec1086[l762] = 0.0;
			
		}
		for (int l763 = 0; (l763 < 2); l763 = (l763 + 1)) {
			fRec1085[l763] = 0.0;
			
		}
		for (int l764 = 0; (l764 < 2); l764 = (l764 + 1)) {
			fRec1083[l764] = 0.0;
			
		}
		for (int l765 = 0; (l765 < 2); l765 = (l765 + 1)) {
			fRec1082[l765] = 0.0;
			
		}
		for (int l766 = 0; (l766 < 2); l766 = (l766 + 1)) {
			fRec1080[l766] = 0.0;
			
		}
		for (int l767 = 0; (l767 < 2); l767 = (l767 + 1)) {
			fRec1079[l767] = 0.0;
			
		}
		for (int l768 = 0; (l768 < 2); l768 = (l768 + 1)) {
			fRec1077[l768] = 0.0;
			
		}
		for (int l769 = 0; (l769 < 2); l769 = (l769 + 1)) {
			fRec1097[l769] = 0.0;
			
		}
		for (int l770 = 0; (l770 < 2); l770 = (l770 + 1)) {
			fRec1095[l770] = 0.0;
			
		}
		for (int l771 = 0; (l771 < 2); l771 = (l771 + 1)) {
			fRec1094[l771] = 0.0;
			
		}
		for (int l772 = 0; (l772 < 2); l772 = (l772 + 1)) {
			fRec1092[l772] = 0.0;
			
		}
		for (int l773 = 0; (l773 < 2); l773 = (l773 + 1)) {
			fRec1091[l773] = 0.0;
			
		}
		for (int l774 = 0; (l774 < 2); l774 = (l774 + 1)) {
			fRec1089[l774] = 0.0;
			
		}
		for (int l775 = 0; (l775 < 2); l775 = (l775 + 1)) {
			fRec1100[l775] = 0.0;
			
		}
		for (int l776 = 0; (l776 < 2); l776 = (l776 + 1)) {
			fRec1098[l776] = 0.0;
			
		}
		for (int l777 = 0; (l777 < 2); l777 = (l777 + 1)) {
			fRec1106[l777] = 0.0;
			
		}
		for (int l778 = 0; (l778 < 2); l778 = (l778 + 1)) {
			fRec1104[l778] = 0.0;
			
		}
		for (int l779 = 0; (l779 < 2); l779 = (l779 + 1)) {
			fRec1103[l779] = 0.0;
			
		}
		for (int l780 = 0; (l780 < 2); l780 = (l780 + 1)) {
			fRec1101[l780] = 0.0;
			
		}
		for (int l781 = 0; (l781 < 512); l781 = (l781 + 1)) {
			fVec34[l781] = 0.0;
			
		}
		for (int l782 = 0; (l782 < 2); l782 = (l782 + 1)) {
			fRec1118[l782] = 0.0;
			
		}
		for (int l783 = 0; (l783 < 2); l783 = (l783 + 1)) {
			fRec1116[l783] = 0.0;
			
		}
		for (int l784 = 0; (l784 < 2); l784 = (l784 + 1)) {
			fRec1115[l784] = 0.0;
			
		}
		for (int l785 = 0; (l785 < 2); l785 = (l785 + 1)) {
			fRec1113[l785] = 0.0;
			
		}
		for (int l786 = 0; (l786 < 2); l786 = (l786 + 1)) {
			fRec1112[l786] = 0.0;
			
		}
		for (int l787 = 0; (l787 < 2); l787 = (l787 + 1)) {
			fRec1110[l787] = 0.0;
			
		}
		for (int l788 = 0; (l788 < 2); l788 = (l788 + 1)) {
			fRec1109[l788] = 0.0;
			
		}
		for (int l789 = 0; (l789 < 2); l789 = (l789 + 1)) {
			fRec1107[l789] = 0.0;
			
		}
		for (int l790 = 0; (l790 < 2); l790 = (l790 + 1)) {
			fRec1127[l790] = 0.0;
			
		}
		for (int l791 = 0; (l791 < 2); l791 = (l791 + 1)) {
			fRec1125[l791] = 0.0;
			
		}
		for (int l792 = 0; (l792 < 2); l792 = (l792 + 1)) {
			fRec1124[l792] = 0.0;
			
		}
		for (int l793 = 0; (l793 < 2); l793 = (l793 + 1)) {
			fRec1122[l793] = 0.0;
			
		}
		for (int l794 = 0; (l794 < 2); l794 = (l794 + 1)) {
			fRec1121[l794] = 0.0;
			
		}
		for (int l795 = 0; (l795 < 2); l795 = (l795 + 1)) {
			fRec1119[l795] = 0.0;
			
		}
		for (int l796 = 0; (l796 < 2); l796 = (l796 + 1)) {
			fRec1130[l796] = 0.0;
			
		}
		for (int l797 = 0; (l797 < 2); l797 = (l797 + 1)) {
			fRec1128[l797] = 0.0;
			
		}
		for (int l798 = 0; (l798 < 2); l798 = (l798 + 1)) {
			fRec1136[l798] = 0.0;
			
		}
		for (int l799 = 0; (l799 < 2); l799 = (l799 + 1)) {
			fRec1134[l799] = 0.0;
			
		}
		for (int l800 = 0; (l800 < 2); l800 = (l800 + 1)) {
			fRec1133[l800] = 0.0;
			
		}
		for (int l801 = 0; (l801 < 2); l801 = (l801 + 1)) {
			fRec1131[l801] = 0.0;
			
		}
		for (int l802 = 0; (l802 < 512); l802 = (l802 + 1)) {
			fVec35[l802] = 0.0;
			
		}
		for (int l803 = 0; (l803 < 2); l803 = (l803 + 1)) {
			fRec1148[l803] = 0.0;
			
		}
		for (int l804 = 0; (l804 < 2); l804 = (l804 + 1)) {
			fRec1146[l804] = 0.0;
			
		}
		for (int l805 = 0; (l805 < 2); l805 = (l805 + 1)) {
			fRec1145[l805] = 0.0;
			
		}
		for (int l806 = 0; (l806 < 2); l806 = (l806 + 1)) {
			fRec1143[l806] = 0.0;
			
		}
		for (int l807 = 0; (l807 < 2); l807 = (l807 + 1)) {
			fRec1142[l807] = 0.0;
			
		}
		for (int l808 = 0; (l808 < 2); l808 = (l808 + 1)) {
			fRec1140[l808] = 0.0;
			
		}
		for (int l809 = 0; (l809 < 2); l809 = (l809 + 1)) {
			fRec1139[l809] = 0.0;
			
		}
		for (int l810 = 0; (l810 < 2); l810 = (l810 + 1)) {
			fRec1137[l810] = 0.0;
			
		}
		for (int l811 = 0; (l811 < 2); l811 = (l811 + 1)) {
			fRec1157[l811] = 0.0;
			
		}
		for (int l812 = 0; (l812 < 2); l812 = (l812 + 1)) {
			fRec1155[l812] = 0.0;
			
		}
		for (int l813 = 0; (l813 < 2); l813 = (l813 + 1)) {
			fRec1154[l813] = 0.0;
			
		}
		for (int l814 = 0; (l814 < 2); l814 = (l814 + 1)) {
			fRec1152[l814] = 0.0;
			
		}
		for (int l815 = 0; (l815 < 2); l815 = (l815 + 1)) {
			fRec1151[l815] = 0.0;
			
		}
		for (int l816 = 0; (l816 < 2); l816 = (l816 + 1)) {
			fRec1149[l816] = 0.0;
			
		}
		for (int l817 = 0; (l817 < 2); l817 = (l817 + 1)) {
			fRec1160[l817] = 0.0;
			
		}
		for (int l818 = 0; (l818 < 2); l818 = (l818 + 1)) {
			fRec1158[l818] = 0.0;
			
		}
		for (int l819 = 0; (l819 < 2); l819 = (l819 + 1)) {
			fRec1166[l819] = 0.0;
			
		}
		for (int l820 = 0; (l820 < 2); l820 = (l820 + 1)) {
			fRec1164[l820] = 0.0;
			
		}
		for (int l821 = 0; (l821 < 2); l821 = (l821 + 1)) {
			fRec1163[l821] = 0.0;
			
		}
		for (int l822 = 0; (l822 < 2); l822 = (l822 + 1)) {
			fRec1161[l822] = 0.0;
			
		}
		for (int l823 = 0; (l823 < 512); l823 = (l823 + 1)) {
			fVec36[l823] = 0.0;
			
		}
		for (int l824 = 0; (l824 < 2); l824 = (l824 + 1)) {
			fRec1178[l824] = 0.0;
			
		}
		for (int l825 = 0; (l825 < 2); l825 = (l825 + 1)) {
			fRec1176[l825] = 0.0;
			
		}
		for (int l826 = 0; (l826 < 2); l826 = (l826 + 1)) {
			fRec1175[l826] = 0.0;
			
		}
		for (int l827 = 0; (l827 < 2); l827 = (l827 + 1)) {
			fRec1173[l827] = 0.0;
			
		}
		for (int l828 = 0; (l828 < 2); l828 = (l828 + 1)) {
			fRec1172[l828] = 0.0;
			
		}
		for (int l829 = 0; (l829 < 2); l829 = (l829 + 1)) {
			fRec1170[l829] = 0.0;
			
		}
		for (int l830 = 0; (l830 < 2); l830 = (l830 + 1)) {
			fRec1169[l830] = 0.0;
			
		}
		for (int l831 = 0; (l831 < 2); l831 = (l831 + 1)) {
			fRec1167[l831] = 0.0;
			
		}
		for (int l832 = 0; (l832 < 2); l832 = (l832 + 1)) {
			fRec1187[l832] = 0.0;
			
		}
		for (int l833 = 0; (l833 < 2); l833 = (l833 + 1)) {
			fRec1185[l833] = 0.0;
			
		}
		for (int l834 = 0; (l834 < 2); l834 = (l834 + 1)) {
			fRec1184[l834] = 0.0;
			
		}
		for (int l835 = 0; (l835 < 2); l835 = (l835 + 1)) {
			fRec1182[l835] = 0.0;
			
		}
		for (int l836 = 0; (l836 < 2); l836 = (l836 + 1)) {
			fRec1181[l836] = 0.0;
			
		}
		for (int l837 = 0; (l837 < 2); l837 = (l837 + 1)) {
			fRec1179[l837] = 0.0;
			
		}
		for (int l838 = 0; (l838 < 2); l838 = (l838 + 1)) {
			fRec1190[l838] = 0.0;
			
		}
		for (int l839 = 0; (l839 < 2); l839 = (l839 + 1)) {
			fRec1188[l839] = 0.0;
			
		}
		for (int l840 = 0; (l840 < 2); l840 = (l840 + 1)) {
			fRec1196[l840] = 0.0;
			
		}
		for (int l841 = 0; (l841 < 2); l841 = (l841 + 1)) {
			fRec1194[l841] = 0.0;
			
		}
		for (int l842 = 0; (l842 < 2); l842 = (l842 + 1)) {
			fRec1193[l842] = 0.0;
			
		}
		for (int l843 = 0; (l843 < 2); l843 = (l843 + 1)) {
			fRec1191[l843] = 0.0;
			
		}
		for (int l844 = 0; (l844 < 512); l844 = (l844 + 1)) {
			fVec37[l844] = 0.0;
			
		}
		for (int l845 = 0; (l845 < 2); l845 = (l845 + 1)) {
			fRec1208[l845] = 0.0;
			
		}
		for (int l846 = 0; (l846 < 2); l846 = (l846 + 1)) {
			fRec1206[l846] = 0.0;
			
		}
		for (int l847 = 0; (l847 < 2); l847 = (l847 + 1)) {
			fRec1205[l847] = 0.0;
			
		}
		for (int l848 = 0; (l848 < 2); l848 = (l848 + 1)) {
			fRec1203[l848] = 0.0;
			
		}
		for (int l849 = 0; (l849 < 2); l849 = (l849 + 1)) {
			fRec1202[l849] = 0.0;
			
		}
		for (int l850 = 0; (l850 < 2); l850 = (l850 + 1)) {
			fRec1200[l850] = 0.0;
			
		}
		for (int l851 = 0; (l851 < 2); l851 = (l851 + 1)) {
			fRec1199[l851] = 0.0;
			
		}
		for (int l852 = 0; (l852 < 2); l852 = (l852 + 1)) {
			fRec1197[l852] = 0.0;
			
		}
		for (int l853 = 0; (l853 < 2); l853 = (l853 + 1)) {
			fRec1217[l853] = 0.0;
			
		}
		for (int l854 = 0; (l854 < 2); l854 = (l854 + 1)) {
			fRec1215[l854] = 0.0;
			
		}
		for (int l855 = 0; (l855 < 2); l855 = (l855 + 1)) {
			fRec1214[l855] = 0.0;
			
		}
		for (int l856 = 0; (l856 < 2); l856 = (l856 + 1)) {
			fRec1212[l856] = 0.0;
			
		}
		for (int l857 = 0; (l857 < 2); l857 = (l857 + 1)) {
			fRec1211[l857] = 0.0;
			
		}
		for (int l858 = 0; (l858 < 2); l858 = (l858 + 1)) {
			fRec1209[l858] = 0.0;
			
		}
		for (int l859 = 0; (l859 < 2); l859 = (l859 + 1)) {
			fRec1220[l859] = 0.0;
			
		}
		for (int l860 = 0; (l860 < 2); l860 = (l860 + 1)) {
			fRec1218[l860] = 0.0;
			
		}
		for (int l861 = 0; (l861 < 2); l861 = (l861 + 1)) {
			fRec1226[l861] = 0.0;
			
		}
		for (int l862 = 0; (l862 < 2); l862 = (l862 + 1)) {
			fRec1224[l862] = 0.0;
			
		}
		for (int l863 = 0; (l863 < 2); l863 = (l863 + 1)) {
			fRec1223[l863] = 0.0;
			
		}
		for (int l864 = 0; (l864 < 2); l864 = (l864 + 1)) {
			fRec1221[l864] = 0.0;
			
		}
		for (int l865 = 0; (l865 < 512); l865 = (l865 + 1)) {
			fVec38[l865] = 0.0;
			
		}
		for (int l866 = 0; (l866 < 2); l866 = (l866 + 1)) {
			fRec1238[l866] = 0.0;
			
		}
		for (int l867 = 0; (l867 < 2); l867 = (l867 + 1)) {
			fRec1236[l867] = 0.0;
			
		}
		for (int l868 = 0; (l868 < 2); l868 = (l868 + 1)) {
			fRec1235[l868] = 0.0;
			
		}
		for (int l869 = 0; (l869 < 2); l869 = (l869 + 1)) {
			fRec1233[l869] = 0.0;
			
		}
		for (int l870 = 0; (l870 < 2); l870 = (l870 + 1)) {
			fRec1232[l870] = 0.0;
			
		}
		for (int l871 = 0; (l871 < 2); l871 = (l871 + 1)) {
			fRec1230[l871] = 0.0;
			
		}
		for (int l872 = 0; (l872 < 2); l872 = (l872 + 1)) {
			fRec1229[l872] = 0.0;
			
		}
		for (int l873 = 0; (l873 < 2); l873 = (l873 + 1)) {
			fRec1227[l873] = 0.0;
			
		}
		for (int l874 = 0; (l874 < 2); l874 = (l874 + 1)) {
			fRec1247[l874] = 0.0;
			
		}
		for (int l875 = 0; (l875 < 2); l875 = (l875 + 1)) {
			fRec1245[l875] = 0.0;
			
		}
		for (int l876 = 0; (l876 < 2); l876 = (l876 + 1)) {
			fRec1244[l876] = 0.0;
			
		}
		for (int l877 = 0; (l877 < 2); l877 = (l877 + 1)) {
			fRec1242[l877] = 0.0;
			
		}
		for (int l878 = 0; (l878 < 2); l878 = (l878 + 1)) {
			fRec1241[l878] = 0.0;
			
		}
		for (int l879 = 0; (l879 < 2); l879 = (l879 + 1)) {
			fRec1239[l879] = 0.0;
			
		}
		for (int l880 = 0; (l880 < 2); l880 = (l880 + 1)) {
			fRec1250[l880] = 0.0;
			
		}
		for (int l881 = 0; (l881 < 2); l881 = (l881 + 1)) {
			fRec1248[l881] = 0.0;
			
		}
		for (int l882 = 0; (l882 < 2); l882 = (l882 + 1)) {
			fRec1256[l882] = 0.0;
			
		}
		for (int l883 = 0; (l883 < 2); l883 = (l883 + 1)) {
			fRec1254[l883] = 0.0;
			
		}
		for (int l884 = 0; (l884 < 2); l884 = (l884 + 1)) {
			fRec1253[l884] = 0.0;
			
		}
		for (int l885 = 0; (l885 < 2); l885 = (l885 + 1)) {
			fRec1251[l885] = 0.0;
			
		}
		for (int l886 = 0; (l886 < 512); l886 = (l886 + 1)) {
			fVec39[l886] = 0.0;
			
		}
		for (int l887 = 0; (l887 < 2); l887 = (l887 + 1)) {
			fRec1268[l887] = 0.0;
			
		}
		for (int l888 = 0; (l888 < 2); l888 = (l888 + 1)) {
			fRec1266[l888] = 0.0;
			
		}
		for (int l889 = 0; (l889 < 2); l889 = (l889 + 1)) {
			fRec1265[l889] = 0.0;
			
		}
		for (int l890 = 0; (l890 < 2); l890 = (l890 + 1)) {
			fRec1263[l890] = 0.0;
			
		}
		for (int l891 = 0; (l891 < 2); l891 = (l891 + 1)) {
			fRec1262[l891] = 0.0;
			
		}
		for (int l892 = 0; (l892 < 2); l892 = (l892 + 1)) {
			fRec1260[l892] = 0.0;
			
		}
		for (int l893 = 0; (l893 < 2); l893 = (l893 + 1)) {
			fRec1259[l893] = 0.0;
			
		}
		for (int l894 = 0; (l894 < 2); l894 = (l894 + 1)) {
			fRec1257[l894] = 0.0;
			
		}
		for (int l895 = 0; (l895 < 2); l895 = (l895 + 1)) {
			fRec1277[l895] = 0.0;
			
		}
		for (int l896 = 0; (l896 < 2); l896 = (l896 + 1)) {
			fRec1275[l896] = 0.0;
			
		}
		for (int l897 = 0; (l897 < 2); l897 = (l897 + 1)) {
			fRec1274[l897] = 0.0;
			
		}
		for (int l898 = 0; (l898 < 2); l898 = (l898 + 1)) {
			fRec1272[l898] = 0.0;
			
		}
		for (int l899 = 0; (l899 < 2); l899 = (l899 + 1)) {
			fRec1271[l899] = 0.0;
			
		}
		for (int l900 = 0; (l900 < 2); l900 = (l900 + 1)) {
			fRec1269[l900] = 0.0;
			
		}
		for (int l901 = 0; (l901 < 2); l901 = (l901 + 1)) {
			fRec1280[l901] = 0.0;
			
		}
		for (int l902 = 0; (l902 < 2); l902 = (l902 + 1)) {
			fRec1278[l902] = 0.0;
			
		}
		for (int l903 = 0; (l903 < 2); l903 = (l903 + 1)) {
			fRec1286[l903] = 0.0;
			
		}
		for (int l904 = 0; (l904 < 2); l904 = (l904 + 1)) {
			fRec1284[l904] = 0.0;
			
		}
		for (int l905 = 0; (l905 < 2); l905 = (l905 + 1)) {
			fRec1283[l905] = 0.0;
			
		}
		for (int l906 = 0; (l906 < 2); l906 = (l906 + 1)) {
			fRec1281[l906] = 0.0;
			
		}
		for (int l907 = 0; (l907 < 512); l907 = (l907 + 1)) {
			fVec40[l907] = 0.0;
			
		}
		for (int l908 = 0; (l908 < 2); l908 = (l908 + 1)) {
			fRec1298[l908] = 0.0;
			
		}
		for (int l909 = 0; (l909 < 2); l909 = (l909 + 1)) {
			fRec1296[l909] = 0.0;
			
		}
		for (int l910 = 0; (l910 < 2); l910 = (l910 + 1)) {
			fRec1295[l910] = 0.0;
			
		}
		for (int l911 = 0; (l911 < 2); l911 = (l911 + 1)) {
			fRec1293[l911] = 0.0;
			
		}
		for (int l912 = 0; (l912 < 2); l912 = (l912 + 1)) {
			fRec1292[l912] = 0.0;
			
		}
		for (int l913 = 0; (l913 < 2); l913 = (l913 + 1)) {
			fRec1290[l913] = 0.0;
			
		}
		for (int l914 = 0; (l914 < 2); l914 = (l914 + 1)) {
			fRec1289[l914] = 0.0;
			
		}
		for (int l915 = 0; (l915 < 2); l915 = (l915 + 1)) {
			fRec1287[l915] = 0.0;
			
		}
		for (int l916 = 0; (l916 < 2); l916 = (l916 + 1)) {
			fRec1307[l916] = 0.0;
			
		}
		for (int l917 = 0; (l917 < 2); l917 = (l917 + 1)) {
			fRec1305[l917] = 0.0;
			
		}
		for (int l918 = 0; (l918 < 2); l918 = (l918 + 1)) {
			fRec1304[l918] = 0.0;
			
		}
		for (int l919 = 0; (l919 < 2); l919 = (l919 + 1)) {
			fRec1302[l919] = 0.0;
			
		}
		for (int l920 = 0; (l920 < 2); l920 = (l920 + 1)) {
			fRec1301[l920] = 0.0;
			
		}
		for (int l921 = 0; (l921 < 2); l921 = (l921 + 1)) {
			fRec1299[l921] = 0.0;
			
		}
		for (int l922 = 0; (l922 < 2); l922 = (l922 + 1)) {
			fRec1310[l922] = 0.0;
			
		}
		for (int l923 = 0; (l923 < 2); l923 = (l923 + 1)) {
			fRec1308[l923] = 0.0;
			
		}
		for (int l924 = 0; (l924 < 2); l924 = (l924 + 1)) {
			fRec1316[l924] = 0.0;
			
		}
		for (int l925 = 0; (l925 < 2); l925 = (l925 + 1)) {
			fRec1314[l925] = 0.0;
			
		}
		for (int l926 = 0; (l926 < 2); l926 = (l926 + 1)) {
			fRec1313[l926] = 0.0;
			
		}
		for (int l927 = 0; (l927 < 2); l927 = (l927 + 1)) {
			fRec1311[l927] = 0.0;
			
		}
		for (int l928 = 0; (l928 < 512); l928 = (l928 + 1)) {
			fVec41[l928] = 0.0;
			
		}
		for (int l929 = 0; (l929 < 2); l929 = (l929 + 1)) {
			fRec1328[l929] = 0.0;
			
		}
		for (int l930 = 0; (l930 < 2); l930 = (l930 + 1)) {
			fRec1326[l930] = 0.0;
			
		}
		for (int l931 = 0; (l931 < 2); l931 = (l931 + 1)) {
			fRec1325[l931] = 0.0;
			
		}
		for (int l932 = 0; (l932 < 2); l932 = (l932 + 1)) {
			fRec1323[l932] = 0.0;
			
		}
		for (int l933 = 0; (l933 < 2); l933 = (l933 + 1)) {
			fRec1322[l933] = 0.0;
			
		}
		for (int l934 = 0; (l934 < 2); l934 = (l934 + 1)) {
			fRec1320[l934] = 0.0;
			
		}
		for (int l935 = 0; (l935 < 2); l935 = (l935 + 1)) {
			fRec1319[l935] = 0.0;
			
		}
		for (int l936 = 0; (l936 < 2); l936 = (l936 + 1)) {
			fRec1317[l936] = 0.0;
			
		}
		for (int l937 = 0; (l937 < 2); l937 = (l937 + 1)) {
			fRec1337[l937] = 0.0;
			
		}
		for (int l938 = 0; (l938 < 2); l938 = (l938 + 1)) {
			fRec1335[l938] = 0.0;
			
		}
		for (int l939 = 0; (l939 < 2); l939 = (l939 + 1)) {
			fRec1334[l939] = 0.0;
			
		}
		for (int l940 = 0; (l940 < 2); l940 = (l940 + 1)) {
			fRec1332[l940] = 0.0;
			
		}
		for (int l941 = 0; (l941 < 2); l941 = (l941 + 1)) {
			fRec1331[l941] = 0.0;
			
		}
		for (int l942 = 0; (l942 < 2); l942 = (l942 + 1)) {
			fRec1329[l942] = 0.0;
			
		}
		for (int l943 = 0; (l943 < 2); l943 = (l943 + 1)) {
			fRec1340[l943] = 0.0;
			
		}
		for (int l944 = 0; (l944 < 2); l944 = (l944 + 1)) {
			fRec1338[l944] = 0.0;
			
		}
		for (int l945 = 0; (l945 < 2); l945 = (l945 + 1)) {
			fRec1346[l945] = 0.0;
			
		}
		for (int l946 = 0; (l946 < 2); l946 = (l946 + 1)) {
			fRec1344[l946] = 0.0;
			
		}
		for (int l947 = 0; (l947 < 2); l947 = (l947 + 1)) {
			fRec1343[l947] = 0.0;
			
		}
		for (int l948 = 0; (l948 < 2); l948 = (l948 + 1)) {
			fRec1341[l948] = 0.0;
			
		}
		for (int l949 = 0; (l949 < 512); l949 = (l949 + 1)) {
			fVec42[l949] = 0.0;
			
		}
		for (int l950 = 0; (l950 < 2); l950 = (l950 + 1)) {
			fRec1358[l950] = 0.0;
			
		}
		for (int l951 = 0; (l951 < 2); l951 = (l951 + 1)) {
			fRec1356[l951] = 0.0;
			
		}
		for (int l952 = 0; (l952 < 2); l952 = (l952 + 1)) {
			fRec1355[l952] = 0.0;
			
		}
		for (int l953 = 0; (l953 < 2); l953 = (l953 + 1)) {
			fRec1353[l953] = 0.0;
			
		}
		for (int l954 = 0; (l954 < 2); l954 = (l954 + 1)) {
			fRec1352[l954] = 0.0;
			
		}
		for (int l955 = 0; (l955 < 2); l955 = (l955 + 1)) {
			fRec1350[l955] = 0.0;
			
		}
		for (int l956 = 0; (l956 < 2); l956 = (l956 + 1)) {
			fRec1349[l956] = 0.0;
			
		}
		for (int l957 = 0; (l957 < 2); l957 = (l957 + 1)) {
			fRec1347[l957] = 0.0;
			
		}
		for (int l958 = 0; (l958 < 2); l958 = (l958 + 1)) {
			fRec1367[l958] = 0.0;
			
		}
		for (int l959 = 0; (l959 < 2); l959 = (l959 + 1)) {
			fRec1365[l959] = 0.0;
			
		}
		for (int l960 = 0; (l960 < 2); l960 = (l960 + 1)) {
			fRec1364[l960] = 0.0;
			
		}
		for (int l961 = 0; (l961 < 2); l961 = (l961 + 1)) {
			fRec1362[l961] = 0.0;
			
		}
		for (int l962 = 0; (l962 < 2); l962 = (l962 + 1)) {
			fRec1361[l962] = 0.0;
			
		}
		for (int l963 = 0; (l963 < 2); l963 = (l963 + 1)) {
			fRec1359[l963] = 0.0;
			
		}
		for (int l964 = 0; (l964 < 2); l964 = (l964 + 1)) {
			fRec1370[l964] = 0.0;
			
		}
		for (int l965 = 0; (l965 < 2); l965 = (l965 + 1)) {
			fRec1368[l965] = 0.0;
			
		}
		for (int l966 = 0; (l966 < 2); l966 = (l966 + 1)) {
			fRec1376[l966] = 0.0;
			
		}
		for (int l967 = 0; (l967 < 2); l967 = (l967 + 1)) {
			fRec1374[l967] = 0.0;
			
		}
		for (int l968 = 0; (l968 < 2); l968 = (l968 + 1)) {
			fRec1373[l968] = 0.0;
			
		}
		for (int l969 = 0; (l969 < 2); l969 = (l969 + 1)) {
			fRec1371[l969] = 0.0;
			
		}
		for (int l970 = 0; (l970 < 512); l970 = (l970 + 1)) {
			fVec43[l970] = 0.0;
			
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
		ui_interface->openVerticalBox("KMHLS_FullSetup_4h3v_full_1");
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
			double fTemp8 = (fConst5 * fRec4[1]);
			double fTemp9 = (fConst6 * fRec7[1]);
			fRec16[0] = (double(input16[i]) - (((fTemp2 * fRec16[2]) + (2.0 * (fTemp3 * fRec16[1]))) / fTemp4));
			double fTemp10 = (((fTemp1 * (fRec16[2] + (fRec16[0] + (2.0 * fRec16[1])))) / fTemp5) + (0.2457354591 * (fRec3[0] * (0.0 - ((fTemp6 * fRec16[1]) + ((fRec16[0] + fRec16[2]) / fTemp4))))));
			fRec17[0] = (double(input17[i]) - (((fTemp2 * fRec17[2]) + (2.0 * (fTemp3 * fRec17[1]))) / fTemp4));
			double fTemp11 = (((fTemp1 * (fRec17[2] + (fRec17[0] + (2.0 * fRec17[1])))) / fTemp5) + (0.2457354591 * (fRec3[0] * (0.0 - ((fTemp6 * fRec17[1]) + ((fRec17[0] + fRec17[2]) / fTemp4))))));
			fRec18[0] = (double(input18[i]) - (((fTemp2 * fRec18[2]) + (2.0 * (fTemp3 * fRec18[1]))) / fTemp4));
			double fTemp12 = (((fTemp1 * (fRec18[2] + (fRec18[0] + (2.0 * fRec18[1])))) / fTemp5) + (0.2457354591 * (fRec3[0] * (0.0 - ((fTemp6 * fRec18[1]) + ((fRec18[0] + fRec18[2]) / fTemp4))))));
			fRec19[0] = (double(input19[i]) - (((fTemp2 * fRec19[2]) + (2.0 * (fTemp3 * fRec19[1]))) / fTemp4));
			double fTemp13 = (((fTemp1 * (fRec19[2] + (fRec19[0] + (2.0 * fRec19[1])))) / fTemp5) + (0.2457354591 * (fRec3[0] * (0.0 - ((fTemp6 * fRec19[1]) + ((fRec19[0] + fRec19[2]) / fTemp4))))));
			fRec20[0] = (double(input21[i]) - (((fTemp2 * fRec20[2]) + (2.0 * (fTemp3 * fRec20[1]))) / fTemp4));
			double fTemp14 = (((fTemp1 * (fRec20[2] + (fRec20[0] + (2.0 * fRec20[1])))) / fTemp5) + (0.2457354591 * (fRec3[0] * (0.0 - ((fTemp6 * fRec20[1]) + ((fRec20[0] + fRec20[2]) / fTemp4))))));
			fRec21[0] = (double(input22[i]) - (((fTemp2 * fRec21[2]) + (2.0 * (fTemp3 * fRec21[1]))) / fTemp4));
			double fTemp15 = (((fTemp1 * (fRec21[2] + (fRec21[0] + (2.0 * fRec21[1])))) / fTemp5) + (0.2457354591 * (fRec3[0] * (0.0 - ((fTemp6 * fRec21[1]) + ((fRec21[0] + fRec21[2]) / fTemp4))))));
			fRec22[0] = (double(input23[i]) - (((fTemp2 * fRec22[2]) + (2.0 * (fTemp3 * fRec22[1]))) / fTemp4));
			double fTemp16 = (((fTemp1 * (fRec22[2] + (fRec22[0] + (2.0 * fRec22[1])))) / fTemp5) + (0.2457354591 * (fRec3[0] * (0.0 - ((fTemp6 * fRec22[1]) + ((fRec22[0] + fRec22[2]) / fTemp4))))));
			fRec23[0] = (double(input24[i]) - (((fTemp2 * fRec23[2]) + (2.0 * (fTemp3 * fRec23[1]))) / fTemp4));
			double fTemp17 = (((fTemp1 * (fRec23[2] + (fRec23[0] + (2.0 * fRec23[1])))) / fTemp5) + (0.2457354591 * (fRec3[0] * (0.0 - ((fTemp6 * fRec23[1]) + ((fRec23[0] + fRec23[2]) / fTemp4))))));
			double fTemp18 = (fConst8 * (((0.076301153100000005 * fTemp10) + (0.064431403900000003 * fTemp11)) - ((((((0.033049796200000002 * fTemp12) + (0.034642695199999997 * fTemp13)) + (0.055682894599999998 * fTemp14)) + (0.020987958099999999 * fTemp15)) + (0.0076640474000000004 * fTemp16)) + (0.050985000599999997 * fTemp17))));
			double fTemp19 = (fConst9 * fRec10[1]);
			double fTemp20 = (fConst10 * fRec13[1]);
			fRec15[0] = (fTemp18 + (fTemp19 + (fRec15[1] + fTemp20)));
			fRec13[0] = fRec15[0];
			double fRec14 = ((fTemp20 + fTemp19) + fTemp18);
			fRec12[0] = (fRec13[0] + fRec12[1]);
			fRec10[0] = fRec12[0];
			double fRec11 = fRec14;
			fRec9[0] = (fTemp8 + (fTemp9 + (fRec11 + fRec9[1])));
			fRec7[0] = fRec9[0];
			double fRec8 = (fTemp8 + (fRec11 + fTemp9));
			fRec6[0] = (fRec7[0] + fRec6[1]);
			fRec4[0] = fRec6[0];
			double fRec5 = fRec8;
			double fTemp21 = (fConst12 * fRec24[1]);
			fRec33[0] = (double(input9[i]) - (((fTemp2 * fRec33[2]) + (2.0 * (fTemp3 * fRec33[1]))) / fTemp4));
			double fTemp22 = (((fTemp1 * (fRec33[2] + (fRec33[0] + (2.0 * fRec33[1])))) / fTemp5) + (0.50103117100000005 * (fRec3[0] * (0.0 - ((fTemp6 * fRec33[1]) + ((fRec33[0] + fRec33[2]) / fTemp4))))));
			fRec34[0] = (double(input10[i]) - (((fTemp2 * fRec34[2]) + (2.0 * (fTemp3 * fRec34[1]))) / fTemp4));
			double fTemp23 = (((fTemp1 * (fRec34[2] + (fRec34[0] + (2.0 * fRec34[1])))) / fTemp5) + (0.50103117100000005 * (fRec3[0] * (0.0 - ((fTemp6 * fRec34[1]) + ((fRec34[0] + fRec34[2]) / fTemp4))))));
			fRec35[0] = (double(input14[i]) - (((fTemp2 * fRec35[2]) + (2.0 * (fTemp3 * fRec35[1]))) / fTemp4));
			double fTemp24 = (((fTemp1 * (fRec35[2] + (fRec35[0] + (2.0 * fRec35[1])))) / fTemp5) + (0.50103117100000005 * (fRec3[0] * (0.0 - ((fTemp6 * fRec35[1]) + ((fRec35[0] + fRec35[2]) / fTemp4))))));
			fRec36[0] = (double(input11[i]) - (((fTemp2 * fRec36[2]) + (2.0 * (fTemp3 * fRec36[1]))) / fTemp4));
			double fTemp25 = (((fTemp1 * (fRec36[2] + (fRec36[0] + (2.0 * fRec36[1])))) / fTemp5) + (0.50103117100000005 * (fRec3[0] * (0.0 - ((fTemp6 * fRec36[1]) + ((fRec36[0] + fRec36[2]) / fTemp4))))));
			fRec37[0] = (double(input12[i]) - (((fTemp2 * fRec37[2]) + (2.0 * (fTemp3 * fRec37[1]))) / fTemp4));
			double fTemp26 = (((fTemp1 * (fRec37[2] + (fRec37[0] + (2.0 * fRec37[1])))) / fTemp5) + (0.50103117100000005 * (fRec3[0] * (0.0 - ((fTemp6 * fRec37[1]) + ((fRec37[0] + fRec37[2]) / fTemp4))))));
			fRec38[0] = (double(input13[i]) - (((fTemp2 * fRec38[2]) + (2.0 * (fTemp3 * fRec38[1]))) / fTemp4));
			double fTemp27 = (((fTemp1 * (fRec38[2] + (fRec38[0] + (2.0 * fRec38[1])))) / fTemp5) + (0.50103117100000005 * (fRec3[0] * (0.0 - ((fTemp6 * fRec38[1]) + ((fRec38[0] + fRec38[2]) / fTemp4))))));
			fRec39[0] = (double(input15[i]) - (((fTemp2 * fRec39[2]) + (2.0 * (fTemp3 * fRec39[1]))) / fTemp4));
			double fTemp28 = (((fTemp1 * (fRec39[2] + (fRec39[0] + (2.0 * fRec39[1])))) / fTemp5) + (0.50103117100000005 * (fRec3[0] * (0.0 - ((fTemp6 * fRec39[1]) + ((fRec39[0] + fRec39[2]) / fTemp4))))));
			double fTemp29 = (fConst14 * ((((0.086992999000000001 * fTemp22) + (0.049152279799999997 * fTemp23)) + (0.023180860599999999 * fTemp24)) - ((((0.023616205899999999 * fTemp25) + (0.039840277200000003 * fTemp26)) + (0.041084534700000001 * fTemp27)) + (0.0047892942000000004 * fTemp28))));
			double fTemp30 = (fConst15 * fRec27[1]);
			double fTemp31 = (fConst16 * fRec30[1]);
			fRec32[0] = (fTemp29 + (fTemp30 + (fRec32[1] + fTemp31)));
			fRec30[0] = fRec32[0];
			double fRec31 = ((fTemp31 + fTemp30) + fTemp29);
			fRec29[0] = (fRec30[0] + fRec29[1]);
			fRec27[0] = fRec29[0];
			double fRec28 = fRec31;
			fRec26[0] = (fTemp21 + (fRec28 + fRec26[1]));
			fRec24[0] = fRec26[0];
			double fRec25 = (fRec28 + fTemp21);
			fRec43[0] = (double(input1[i]) - (((fTemp2 * fRec43[2]) + (2.0 * (fTemp3 * fRec43[1]))) / fTemp4));
			double fTemp32 = (((fTemp1 * (fRec43[2] + (fRec43[0] + (2.0 * fRec43[1])))) / fTemp5) + (0.9061798459 * (fRec3[0] * (0.0 - ((fTemp6 * fRec43[1]) + ((fRec43[0] + fRec43[2]) / fTemp4))))));
			fRec44[0] = (double(input2[i]) - (((fTemp2 * fRec44[2]) + (2.0 * (fTemp3 * fRec44[1]))) / fTemp4));
			double fTemp33 = (((fTemp1 * (fRec44[2] + (fRec44[0] + (2.0 * fRec44[1])))) / fTemp5) + (0.9061798459 * (fRec3[0] * (0.0 - ((fTemp6 * fRec44[1]) + ((fRec44[0] + fRec44[2]) / fTemp4))))));
			fRec45[0] = (double(input3[i]) - (((fTemp2 * fRec45[2]) + (2.0 * (fTemp3 * fRec45[1]))) / fTemp4));
			double fTemp34 = (((fTemp1 * (fRec45[2] + (fRec45[0] + (2.0 * fRec45[1])))) / fTemp5) + (0.9061798459 * (fRec3[0] * (0.0 - ((fTemp6 * fRec45[1]) + ((fRec45[0] + fRec45[2]) / fTemp4))))));
			double fTemp35 = (fConst18 * (((0.029726642500000001 * fTemp32) + (0.014911744100000001 * fTemp33)) + (0.048964367199999997 * fTemp34)));
			double fTemp36 = (fConst19 * fRec40[1]);
			fRec42[0] = (fTemp35 + (fRec42[1] + fTemp36));
			fRec40[0] = fRec42[0];
			double fRec41 = (fTemp36 + fTemp35);
			fRec52[0] = (double(input4[i]) - (((fTemp2 * fRec52[2]) + (2.0 * (fTemp3 * fRec52[1]))) / fTemp4));
			double fTemp37 = (((fTemp1 * (fRec52[2] + (fRec52[0] + (2.0 * fRec52[1])))) / fTemp5) + (0.73174286980000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec52[1]) + ((fRec52[0] + fRec52[2]) / fTemp4))))));
			fRec53[0] = (double(input5[i]) - (((fTemp2 * fRec53[2]) + (2.0 * (fTemp3 * fRec53[1]))) / fTemp4));
			double fTemp38 = (((fTemp1 * (fRec53[2] + (fRec53[0] + (2.0 * fRec53[1])))) / fTemp5) + (0.73174286980000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec53[1]) + ((fRec53[0] + fRec53[2]) / fTemp4))))));
			fRec54[0] = (double(input7[i]) - (((fTemp2 * fRec54[2]) + (2.0 * (fTemp3 * fRec54[1]))) / fTemp4));
			double fTemp39 = (((fTemp1 * (fRec54[2] + (fRec54[0] + (2.0 * fRec54[1])))) / fTemp5) + (0.73174286980000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec54[1]) + ((fRec54[0] + fRec54[2]) / fTemp4))))));
			fRec55[0] = (double(input8[i]) - (((fTemp2 * fRec55[2]) + (2.0 * (fTemp3 * fRec55[1]))) / fTemp4));
			double fTemp40 = (((fTemp1 * (fRec55[2] + (fRec55[0] + (2.0 * fRec55[1])))) / fTemp5) + (0.73174286980000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec55[1]) + ((fRec55[0] + fRec55[2]) / fTemp4))))));
			fRec56[0] = (double(input6[i]) - (((fTemp2 * fRec56[2]) + (2.0 * (fTemp3 * fRec56[1]))) / fTemp4));
			double fTemp41 = (((fTemp1 * (fRec56[2] + (fRec56[0] + (2.0 * fRec56[1])))) / fTemp5) + (0.73174286980000003 * (fRec3[0] * (0.0 - ((fTemp6 * fRec56[1]) + ((fRec56[0] + fRec56[2]) / fTemp4))))));
			double fTemp42 = (fConst21 * (((((0.067278733399999999 * fTemp37) + (0.0210625147 * fTemp38)) + (0.033079176799999999 * fTemp39)) + (0.035296655400000002 * fTemp40)) - (0.037263030000000003 * fTemp41)));
			double fTemp43 = (fConst22 * fRec46[1]);
			double fTemp44 = (fConst23 * fRec49[1]);
			fRec51[0] = (fTemp42 + (fTemp43 + (fRec51[1] + fTemp44)));
			fRec49[0] = fRec51[0];
			double fRec50 = ((fTemp44 + fTemp43) + fTemp42);
			fRec48[0] = (fRec49[0] + fRec48[1]);
			fRec46[0] = fRec48[0];
			double fRec47 = fRec50;
			fVec0[(IOTA & 127)] = ((0.020287651300000001 * fTemp7) + (fRec5 + (fRec25 + (fRec41 + fRec47))));
			output0[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec0[((IOTA - iConst24) & 127)])));
			double fTemp45 = (fConst26 * fRec57[1]);
			double fTemp46 = (fConst27 * fRec60[1]);
			double fTemp47 = (fConst29 * (((0.065033544400000004 * fTemp17) + (((0.039804079899999997 * fTemp10) + (0.017662780699999998 * fTemp11)) + (0.036427192300000001 * fTemp16))) - ((((0.0111106212 * fTemp12) + (0.0063062444999999996 * fTemp13)) + (0.042520284899999997 * fTemp14)) + (0.042734200999999999 * fTemp15))));
			double fTemp48 = (fConst30 * fRec63[1]);
			double fTemp49 = (fConst31 * fRec66[1]);
			fRec68[0] = (fTemp47 + (fTemp48 + (fRec68[1] + fTemp49)));
			fRec66[0] = fRec68[0];
			double fRec67 = ((fTemp49 + fTemp48) + fTemp47);
			fRec65[0] = (fRec66[0] + fRec65[1]);
			fRec63[0] = fRec65[0];
			double fRec64 = fRec67;
			fRec62[0] = (fTemp45 + (fTemp46 + (fRec64 + fRec62[1])));
			fRec60[0] = fRec62[0];
			double fRec61 = (fTemp45 + (fRec64 + fTemp46));
			fRec59[0] = (fRec60[0] + fRec59[1]);
			fRec57[0] = fRec59[0];
			double fRec58 = fRec61;
			double fTemp50 = (fConst33 * fRec69[1]);
			double fTemp51 = (fConst35 * (((0.063815383899999994 * fTemp28) + (((0.0279606001 * fTemp22) + (0.0095417018999999995 * fTemp23)) + (0.030657757000000001 * fTemp24))) - (((0.0059679968999999996 * fTemp25) + (0.024076274200000001 * fTemp26)) + (0.045125815 * fTemp27))));
			double fTemp52 = (fConst36 * fRec72[1]);
			double fTemp53 = (fConst37 * fRec75[1]);
			fRec77[0] = (fTemp51 + (fTemp52 + (fRec77[1] + fTemp53)));
			fRec75[0] = fRec77[0];
			double fRec76 = ((fTemp53 + fTemp52) + fTemp51);
			fRec74[0] = (fRec75[0] + fRec74[1]);
			fRec72[0] = fRec74[0];
			double fRec73 = fRec76;
			fRec71[0] = (fTemp50 + (fRec73 + fRec71[1]));
			fRec69[0] = fRec71[0];
			double fRec70 = (fRec73 + fTemp50);
			double fTemp54 = (fConst39 * (((0.0059429141000000001 * fTemp32) + (0.0081434539 * fTemp33)) + (0.042622415099999998 * fTemp34)));
			double fTemp55 = (fConst40 * fRec78[1]);
			fRec80[0] = (fTemp54 + (fRec80[1] + fTemp55));
			fRec78[0] = fRec80[0];
			double fRec79 = (fTemp55 + fTemp54);
			double fTemp56 = (fConst42 * (((((0.016014700199999999 * fTemp37) + (0.0033428676 * fTemp38)) + (0.021908569900000001 * fTemp39)) + (0.0565179216 * fTemp40)) - (0.031246433099999998 * fTemp41)));
			double fTemp57 = (fConst43 * fRec81[1]);
			double fTemp58 = (fConst44 * fRec84[1]);
			fRec86[0] = (fTemp56 + (fTemp57 + (fRec86[1] + fTemp58)));
			fRec84[0] = fRec86[0];
			double fRec85 = ((fTemp58 + fTemp57) + fTemp56);
			fRec83[0] = (fRec84[0] + fRec83[1]);
			fRec81[0] = fRec83[0];
			double fRec82 = fRec85;
			fVec1[(IOTA & 127)] = ((0.0148930529 * fTemp7) + (fRec58 + (fRec70 + (fRec79 + fRec82))));
			output1[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec1[((IOTA - iConst45) & 127)])));
			double fTemp59 = (fConst26 * fRec87[1]);
			double fTemp60 = (fConst27 * fRec90[1]);
			double fTemp61 = (fConst29 * (((0.0511303491 * fTemp17) + (((0.021007529899999999 * fTemp12) + (0.014877479399999999 * fTemp13)) + (0.051029004900000001 * fTemp16))) - ((((0.076321344499999999 * fTemp10) + (0.040122302200000001 * fTemp11)) + (0.063934425599999997 * fTemp14)) + (0.033150009199999997 * fTemp15))));
			double fTemp62 = (fConst30 * fRec93[1]);
			double fTemp63 = (fConst31 * fRec96[1]);
			fRec98[0] = (fTemp61 + (fTemp62 + (fRec98[1] + fTemp63)));
			fRec96[0] = fRec98[0];
			double fRec97 = ((fTemp63 + fTemp62) + fTemp61);
			fRec95[0] = (fRec96[0] + fRec95[1]);
			fRec93[0] = fRec95[0];
			double fRec94 = fRec97;
			fRec92[0] = (fTemp59 + (fTemp60 + (fRec94 + fRec92[1])));
			fRec90[0] = fRec92[0];
			double fRec91 = (fTemp59 + (fRec94 + fTemp60));
			fRec89[0] = (fRec90[0] + fRec89[1]);
			fRec87[0] = fRec89[0];
			double fRec88 = fRec91;
			double fTemp64 = (fConst33 * fRec99[1]);
			double fTemp65 = (fConst35 * (((0.065029318399999994 * fTemp28) + ((0.0123580171 * fTemp25) + (0.049193511199999998 * fTemp24))) - ((((0.058135137599999998 * fTemp22) + (0.023170943100000001 * fTemp23)) + (0.039874397800000003 * fTemp26)) + (0.045841434700000003 * fTemp27))));
			double fTemp66 = (fConst36 * fRec102[1]);
			double fTemp67 = (fConst37 * fRec105[1]);
			fRec107[0] = (fTemp65 + (fTemp66 + (fRec107[1] + fTemp67)));
			fRec105[0] = fRec107[0];
			double fRec106 = ((fTemp67 + fTemp66) + fTemp65);
			fRec104[0] = (fRec105[0] + fRec104[1]);
			fRec102[0] = fRec104[0];
			double fRec103 = fRec106;
			fRec101[0] = (fTemp64 + (fRec103 + fRec101[1]));
			fRec99[0] = fRec101[0];
			double fRec100 = (fRec103 + fTemp64);
			double fTemp68 = (fConst39 * (((0.0149225192 * fTemp33) + (0.055717587200000002 * fTemp34)) - (0.0136027847 * fTemp32)));
			double fTemp69 = (fConst40 * fRec108[1]);
			fRec110[0] = (fTemp68 + (fRec110[1] + fTemp69));
			fRec108[0] = fRec110[0];
			double fRec109 = (fTemp69 + fTemp68);
			double fTemp70 = (fConst42 * (((0.038313226700000001 * fTemp39) + (0.067383992200000006 * fTemp40)) - (((0.0352983147 * fTemp37) + (0.0084932597000000002 * fTemp38)) + (0.037320288799999997 * fTemp41))));
			double fTemp71 = (fConst43 * fRec111[1]);
			double fTemp72 = (fConst44 * fRec114[1]);
			fRec116[0] = (fTemp70 + (fTemp71 + (fRec116[1] + fTemp72)));
			fRec114[0] = fRec116[0];
			double fRec115 = ((fTemp72 + fTemp71) + fTemp70);
			fRec113[0] = (fRec114[0] + fRec113[1]);
			fRec111[0] = fRec113[0];
			double fRec112 = fRec115;
			fVec2[(IOTA & 127)] = ((0.020312997499999999 * fTemp7) + (fRec88 + (fRec100 + (fRec109 + fRec112))));
			output2[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec2[((IOTA - iConst45) & 127)])));
			double fTemp73 = (fConst47 * fRec117[1]);
			double fTemp74 = (fConst48 * fRec120[1]);
			double fTemp75 = (fConst50 * (((0.0427717523 * fTemp12) + (0.025651679300000001 * fTemp13)) - ((0.065078857599999998 * fTemp17) + ((0.0133093237 * fTemp16) + ((((0.039704409000000003 * fTemp10) + (0.0382424835 * fTemp11)) + (0.0345562674 * fTemp14)) + (0.011081738799999999 * fTemp15))))));
			double fTemp76 = (fConst51 * fRec123[1]);
			double fTemp77 = (fConst52 * fRec126[1]);
			fRec128[0] = (fTemp75 + (fTemp76 + (fRec128[1] + fTemp77)));
			fRec126[0] = fRec128[0];
			double fRec127 = ((fTemp77 + fTemp76) + fTemp75);
			fRec125[0] = (fRec126[0] + fRec125[1]);
			fRec123[0] = fRec125[0];
			double fRec124 = fRec127;
			fRec122[0] = (fTemp73 + (fTemp74 + (fRec124 + fRec122[1])));
			fRec120[0] = fRec122[0];
			double fRec121 = (fTemp73 + (fRec124 + fTemp74));
			fRec119[0] = (fRec120[0] + fRec119[1]);
			fRec117[0] = fRec119[0];
			double fRec118 = fRec121;
			double fTemp78 = (fConst54 * fRec129[1]);
			double fTemp79 = (fConst56 * (((0.027722318400000001 * fTemp25) + (0.0095264601000000001 * fTemp24)) - (((((0.064875679500000005 * fTemp22) + (0.030682623900000001 * fTemp23)) + (0.024102140099999999 * fTemp26)) + (0.036142177400000003 * fTemp27)) + (0.0254269453 * fTemp28))));
			double fTemp80 = (fConst57 * fRec132[1]);
			double fTemp81 = (fConst58 * fRec135[1]);
			fRec137[0] = (fTemp79 + (fTemp80 + (fRec137[1] + fTemp81)));
			fRec135[0] = fRec137[0];
			double fRec136 = ((fTemp81 + fTemp80) + fTemp79);
			fRec134[0] = (fRec135[0] + fRec134[1]);
			fRec132[0] = fRec134[0];
			double fRec133 = fRec136;
			fRec131[0] = (fTemp78 + (fRec133 + fRec131[1]));
			fRec129[0] = fRec131[0];
			double fRec130 = (fRec133 + fTemp78);
			double fTemp82 = (fConst60 * (((0.0081500327000000004 * fTemp33) + (0.034347769799999997 * fTemp34)) - (0.025961405699999999 * fTemp32)));
			double fTemp83 = (fConst61 * fRec138[1]);
			fRec140[0] = (fTemp82 + (fRec140[1] + fTemp83));
			fRec138[0] = fRec140[0];
			double fRec139 = (fTemp83 + fTemp82);
			double fTemp84 = (fConst63 * (((0.017865129099999998 * fTemp39) + (0.0159787136 * fTemp40)) - (((0.0565492067 * fTemp37) + (0.013144476 * fTemp38)) + (0.031266058399999998 * fTemp41))));
			double fTemp85 = (fConst64 * fRec141[1]);
			double fTemp86 = (fConst65 * fRec144[1]);
			fRec146[0] = (fTemp84 + (fTemp85 + (fRec146[1] + fTemp86)));
			fRec144[0] = fRec146[0];
			double fRec145 = ((fTemp86 + fTemp85) + fTemp84);
			fRec143[0] = (fRec144[0] + fRec143[1]);
			fRec141[0] = fRec143[0];
			double fRec142 = fRec145;
			fVec3[(IOTA & 127)] = ((0.0149006869 * fTemp7) + (fRec118 + (fRec130 + (fRec139 + fRec142))));
			output3[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec3[((IOTA - iConst66) & 127)])));
			double fTemp87 = (fConst5 * fRec147[1]);
			double fTemp88 = (fConst6 * fRec150[1]);
			double fTemp89 = (fConst8 * (((((0.076292876199999998 * fTemp10) + (0.033044275999999997 * fTemp12)) + (0.055717674699999997 * fTemp13)) + (0.020965751000000001 * fTemp15)) - ((0.051095692800000002 * fTemp17) + (((0.0077241684000000001 * fTemp11) + (0.034685050799999999 * fTemp14)) + (0.064498979999999997 * fTemp16)))));
			double fTemp90 = (fConst9 * fRec153[1]);
			double fTemp91 = (fConst10 * fRec156[1]);
			fRec158[0] = (fTemp89 + (fTemp90 + (fRec158[1] + fTemp91)));
			fRec156[0] = fRec158[0];
			double fRec157 = ((fTemp91 + fTemp90) + fTemp89);
			fRec155[0] = (fRec156[0] + fRec155[1]);
			fRec153[0] = fRec155[0];
			double fRec154 = fRec157;
			fRec152[0] = (fTemp87 + (fTemp88 + (fRec154 + fRec152[1])));
			fRec150[0] = fRec152[0];
			double fRec151 = (fTemp87 + (fRec154 + fTemp88));
			fRec149[0] = (fRec150[0] + fRec149[1]);
			fRec147[0] = fRec149[0];
			double fRec148 = fRec151;
			double fTemp92 = (fConst12 * fRec159[1]);
			double fTemp93 = (fConst14 * ((0.041079877600000002 * fTemp25) - ((0.087044369400000002 * fTemp28) + (((((0.0048662371000000003 * fTemp22) + (0.049225619300000002 * fTemp23)) + (0.039881970900000001 * fTemp26)) + (0.0236276347 * fTemp27)) + (0.023181087900000001 * fTemp24)))));
			double fTemp94 = (fConst15 * fRec162[1]);
			double fTemp95 = (fConst16 * fRec165[1]);
			fRec167[0] = (fTemp93 + (fTemp94 + (fRec167[1] + fTemp95)));
			fRec165[0] = fRec167[0];
			double fRec166 = ((fTemp95 + fTemp94) + fTemp93);
			fRec164[0] = (fRec165[0] + fRec164[1]);
			fRec162[0] = fRec164[0];
			double fRec163 = fRec166;
			fRec161[0] = (fTemp92 + (fRec163 + fRec161[1]));
			fRec159[0] = fRec161[0];
			double fRec160 = (fRec163 + fTemp92);
			double fTemp96 = (fConst18 * (((0.014932782 * fTemp33) + (0.029763579500000002 * fTemp34)) - (0.0489911445 * fTemp32)));
			double fTemp97 = (fConst19 * fRec168[1]);
			fRec170[0] = (fTemp96 + (fRec170[1] + fTemp97));
			fRec168[0] = fRec170[0];
			double fRec169 = (fTemp97 + fTemp96);
			double fTemp98 = (fConst21 * ((0.0211000418 * fTemp39) - ((((0.067345779199999997 * fTemp37) + (0.033116199399999997 * fTemp38)) + (0.037278278400000003 * fTemp41)) + (0.035280652199999998 * fTemp40))));
			double fTemp99 = (fConst22 * fRec171[1]);
			double fTemp100 = (fConst23 * fRec174[1]);
			fRec176[0] = (fTemp98 + (fTemp99 + (fRec176[1] + fTemp100)));
			fRec174[0] = fRec176[0];
			double fRec175 = ((fTemp100 + fTemp99) + fTemp98);
			fRec173[0] = (fRec174[0] + fRec173[1]);
			fRec171[0] = fRec173[0];
			double fRec172 = fRec175;
			fVec4[(IOTA & 127)] = ((0.020303679599999999 * fTemp7) + (fRec148 + (fRec160 + (fRec169 + fRec172))));
			output4[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec4[((IOTA - iConst24) & 127)])));
			double fTemp101 = (fConst26 * fRec177[1]);
			double fTemp102 = (fConst27 * fRec180[1]);
			double fTemp103 = (fConst29 * (((((((0.039754495799999998 * fTemp10) + (0.0364189397 * fTemp11)) + (0.011072909000000001 * fTemp12)) + (0.042518380500000001 * fTemp13)) + (0.042662779200000001 * fTemp15)) + (0.064943307899999997 * fTemp17)) - ((0.0063062281999999997 * fTemp14) + (0.017677154800000001 * fTemp16))));
			double fTemp104 = (fConst30 * fRec183[1]);
			double fTemp105 = (fConst31 * fRec186[1]);
			fRec188[0] = (fTemp103 + (fTemp104 + (fRec188[1] + fTemp105)));
			fRec186[0] = fRec188[0];
			double fRec187 = ((fTemp105 + fTemp104) + fTemp103);
			fRec185[0] = (fRec186[0] + fRec185[1]);
			fRec183[0] = fRec185[0];
			double fRec184 = fRec187;
			fRec182[0] = (fTemp101 + (fTemp102 + (fRec184 + fRec182[1])));
			fRec180[0] = fRec182[0];
			double fRec181 = (fTemp101 + (fRec184 + fTemp102));
			fRec179[0] = (fRec180[0] + fRec179[1]);
			fRec177[0] = fRec179[0];
			double fRec178 = fRec181;
			double fTemp106 = (fConst33 * fRec189[1]);
			double fTemp107 = (fConst35 * (((0.063723541300000006 * fTemp22) + (0.045048390200000003 * fTemp25)) - ((0.027924622400000002 * fTemp28) + ((((0.0095516922999999993 * fTemp23) + (0.024077398900000001 * fTemp26)) + (0.0059519671999999999 * fTemp27)) + (0.030657397100000001 * fTemp24)))));
			double fTemp108 = (fConst36 * fRec192[1]);
			double fTemp109 = (fConst37 * fRec195[1]);
			fRec197[0] = (fTemp107 + (fTemp108 + (fRec197[1] + fTemp109)));
			fRec195[0] = fRec197[0];
			double fRec196 = ((fTemp109 + fTemp108) + fTemp107);
			fRec194[0] = (fRec195[0] + fRec194[1]);
			fRec192[0] = fRec194[0];
			double fRec193 = fRec196;
			fRec191[0] = (fTemp106 + (fRec193 + fRec191[1]));
			fRec189[0] = fRec191[0];
			double fRec190 = (fRec193 + fTemp106);
			double fTemp110 = (fConst39 * (((0.0081455725999999996 * fTemp33) + (0.0059358450000000004 * fTemp34)) - (0.042561055899999999 * fTemp32)));
			double fTemp111 = (fConst40 * fRec198[1]);
			fRec200[0] = (fTemp110 + (fRec200[1] + fTemp111));
			fRec198[0] = fRec200[0];
			double fRec199 = (fTemp111 + fTemp110);
			double fTemp112 = (fConst42 * ((0.0033472354000000002 * fTemp39) - ((((0.015994445400000001 * fTemp37) + (0.021911849000000001 * fTemp38)) + (0.031196030900000001 * fTemp41)) + (0.0564357786 * fTemp40))));
			double fTemp113 = (fConst43 * fRec201[1]);
			double fTemp114 = (fConst44 * fRec204[1]);
			fRec206[0] = (fTemp112 + (fTemp113 + (fRec206[1] + fTemp114)));
			fRec204[0] = fRec206[0];
			double fRec205 = ((fTemp114 + fTemp113) + fTemp112);
			fRec203[0] = (fRec204[0] + fRec203[1]);
			fRec201[0] = fRec203[0];
			double fRec202 = fRec205;
			fVec5[(IOTA & 127)] = ((0.0148720972 * fTemp7) + (fRec178 + (fRec190 + (fRec199 + fRec202))));
			output5[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec5[((IOTA - iConst45) & 127)])));
			double fTemp115 = (fConst26 * fRec207[1]);
			double fTemp116 = (fConst27 * fRec210[1]);
			double fTemp117 = (fConst29 * (((0.051192006700000001 * fTemp17) + ((0.040089391299999999 * fTemp16) + ((0.0332188452 * fTemp15) + (((0.051056363799999997 * fTemp11) + (0.063915328499999993 * fTemp13)) + (0.014860421 * fTemp14))))) - ((0.076380795400000007 * fTemp10) + (0.021058597599999999 * fTemp12))));
			double fTemp118 = (fConst30 * fRec213[1]);
			double fTemp119 = (fConst31 * fRec216[1]);
			fRec218[0] = (fTemp117 + (fTemp118 + (fRec218[1] + fTemp119)));
			fRec216[0] = fRec218[0];
			double fRec217 = ((fTemp119 + fTemp118) + fTemp117);
			fRec215[0] = (fRec216[0] + fRec215[1]);
			fRec213[0] = fRec215[0];
			double fRec214 = fRec217;
			fRec212[0] = (fTemp115 + (fTemp116 + (fRec214 + fRec212[1])));
			fRec210[0] = fRec212[0];
			double fRec211 = (fTemp115 + (fRec214 + fTemp116));
			fRec209[0] = (fRec210[0] + fRec209[1]);
			fRec207[0] = fRec209[0];
			double fRec208 = fRec211;
			double fTemp120 = (fConst33 * fRec219[1]);
			double fTemp121 = (fConst35 * ((((((0.065106436899999995 * fTemp22) + (0.023147146699999999 * fTemp23)) + (0.045924851199999998 * fTemp25)) + (0.0123815399 * fTemp27)) + (0.058187098499999999 * fTemp28)) - ((0.039861520099999999 * fTemp26) + (0.049196949800000001 * fTemp24))));
			double fTemp122 = (fConst36 * fRec222[1]);
			double fTemp123 = (fConst37 * fRec225[1]);
			fRec227[0] = (fTemp121 + (fTemp122 + (fRec227[1] + fTemp123)));
			fRec225[0] = fRec227[0];
			double fRec226 = ((fTemp123 + fTemp122) + fTemp121);
			fRec224[0] = (fRec225[0] + fRec224[1]);
			fRec222[0] = fRec224[0];
			double fRec223 = fRec226;
			fRec221[0] = (fTemp120 + (fRec223 + fRec221[1]));
			fRec219[0] = fRec221[0];
			double fRec220 = (fRec223 + fTemp120);
			double fTemp124 = (fConst39 * ((0.014918545300000001 * fTemp33) - ((0.055779355500000002 * fTemp32) + (0.0136150345 * fTemp34))));
			double fTemp125 = (fConst40 * fRec228[1]);
			fRec230[0] = (fTemp124 + (fRec230[1] + fTemp125));
			fRec228[0] = fRec230[0];
			double fRec229 = (fTemp125 + fTemp124);
			double fTemp126 = (fConst42 * ((0.035331008300000001 * fTemp37) - ((((0.038305967500000003 * fTemp38) + (0.037373407400000003 * fTemp41)) + (0.0084833896000000002 * fTemp39)) + (0.0674619682 * fTemp40))));
			double fTemp127 = (fConst43 * fRec231[1]);
			double fTemp128 = (fConst44 * fRec234[1]);
			fRec236[0] = (fTemp126 + (fTemp127 + (fRec236[1] + fTemp128)));
			fRec234[0] = fRec236[0];
			double fRec235 = ((fTemp128 + fTemp127) + fTemp126);
			fRec233[0] = (fRec234[0] + fRec233[1]);
			fRec231[0] = fRec233[0];
			double fRec232 = fRec235;
			fVec6[(IOTA & 127)] = ((0.020334412400000001 * fTemp7) + (fRec208 + (fRec220 + (fRec229 + fRec232))));
			output6[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec6[((IOTA - iConst45) & 127)])));
			double fTemp129 = (fConst47 * fRec237[1]);
			double fTemp130 = (fConst48 * fRec240[1]);
			double fTemp131 = (fConst50 * (((0.038409235399999998 * fTemp16) + ((0.011077795 * fTemp15) + ((0.034674740900000001 * fTemp13) + (0.0257042837 * fTemp14)))) - ((((0.039800237299999999 * fTemp10) + (0.013292439499999999 * fTemp11)) + (0.042654017900000001 * fTemp12)) + (0.065025436399999997 * fTemp17))));
			double fTemp132 = (fConst51 * fRec243[1]);
			double fTemp133 = (fConst52 * fRec246[1]);
			fRec248[0] = (fTemp131 + (fTemp132 + (fRec248[1] + fTemp133)));
			fRec246[0] = fRec248[0];
			double fRec247 = ((fTemp133 + fTemp132) + fTemp131);
			fRec245[0] = (fRec246[0] + fRec245[1]);
			fRec243[0] = fRec245[0];
			double fRec244 = fRec247;
			fRec242[0] = (fTemp129 + (fTemp130 + (fRec244 + fRec242[1])));
			fRec240[0] = fRec242[0];
			double fRec241 = (fTemp129 + (fRec244 + fTemp130));
			fRec239[0] = (fRec240[0] + fRec239[1]);
			fRec237[0] = fRec239[0];
			double fRec238 = fRec241;
			double fTemp134 = (fConst54 * fRec249[1]);
			double fTemp135 = (fConst56 * (((((0.030790350300000002 * fTemp23) + (0.0360911441 * fTemp25)) + (0.0276617423 * fTemp27)) + (0.064907633800000003 * fTemp28)) - (((0.025348098499999999 * fTemp22) + (0.024186315999999999 * fTemp26)) + (0.0096018156000000007 * fTemp24))));
			double fTemp136 = (fConst57 * fRec252[1]);
			double fTemp137 = (fConst58 * fRec255[1]);
			fRec257[0] = (fTemp135 + (fTemp136 + (fRec257[1] + fTemp137)));
			fRec255[0] = fRec257[0];
			double fRec256 = ((fTemp137 + fTemp136) + fTemp135);
			fRec254[0] = (fRec255[0] + fRec254[1]);
			fRec252[0] = fRec254[0];
			double fRec253 = fRec256;
			fRec251[0] = (fTemp134 + (fRec253 + fRec251[1]));
			fRec249[0] = fRec251[0];
			double fRec250 = (fRec253 + fTemp134);
			double fTemp138 = (fConst60 * ((0.0081851201999999998 * fTemp33) - ((0.034363525800000003 * fTemp32) + (0.025948127299999998 * fTemp34))));
			double fTemp139 = (fConst61 * fRec258[1]);
			fRec260[0] = (fTemp138 + (fRec260[1] + fTemp139));
			fRec258[0] = fRec260[0];
			double fRec259 = (fTemp139 + fTemp138);
			double fTemp140 = (fConst63 * ((0.056536760899999997 * fTemp37) - ((((0.017946540300000001 * fTemp38) + (0.031241391699999999 * fTemp41)) + (0.013186598500000001 * fTemp39)) + (0.016029248199999999 * fTemp40))));
			double fTemp141 = (fConst64 * fRec261[1]);
			double fTemp142 = (fConst65 * fRec264[1]);
			fRec266[0] = (fTemp140 + (fTemp141 + (fRec266[1] + fTemp142)));
			fRec264[0] = fRec266[0];
			double fRec265 = ((fTemp142 + fTemp141) + fTemp140);
			fRec263[0] = (fRec264[0] + fRec263[1]);
			fRec261[0] = fRec263[0];
			double fRec262 = fRec265;
			fVec7[(IOTA & 127)] = ((0.0149042737 * fTemp7) + (fRec238 + (fRec250 + (fRec259 + fRec262))));
			output7[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec7[((IOTA - iConst66) & 127)])));
			double fTemp143 = (fConst5 * fRec267[1]);
			double fTemp144 = (fConst6 * fRec270[1]);
			double fTemp145 = (fConst8 * (((((0.076344546200000002 * fTemp10) + (0.034645651999999999 * fTemp13)) + (0.055673970599999997 * fTemp14)) + (0.0076935431999999998 * fTemp16)) - ((((0.064461201600000004 * fTemp11) + (0.033036260300000002 * fTemp12)) + (0.020991414600000001 * fTemp15)) + (0.051025525299999999 * fTemp17))));
			double fTemp146 = (fConst9 * fRec273[1]);
			double fTemp147 = (fConst10 * fRec276[1]);
			fRec278[0] = (fTemp145 + (fTemp146 + (fRec278[1] + fTemp147)));
			fRec276[0] = fRec278[0];
			double fRec277 = ((fTemp147 + fTemp146) + fTemp145);
			fRec275[0] = (fRec276[0] + fRec275[1]);
			fRec273[0] = fRec275[0];
			double fRec274 = fRec277;
			fRec272[0] = (fTemp143 + (fTemp144 + (fRec274 + fRec272[1])));
			fRec270[0] = fRec272[0];
			double fRec271 = (fTemp143 + (fRec274 + fTemp144));
			fRec269[0] = (fRec270[0] + fRec269[1]);
			fRec267[0] = fRec269[0];
			double fRec268 = fRec271;
			double fTemp148 = (fConst12 * fRec279[1]);
			double fTemp149 = (fConst14 * (((0.0048022951000000003 * fTemp28) + ((0.023179443500000001 * fTemp24) + (((0.049185379100000003 * fTemp23) + (0.0236157169 * fTemp25)) + (0.0410878561 * fTemp27)))) - ((0.087046728399999995 * fTemp22) + (0.039849832500000001 * fTemp26))));
			double fTemp150 = (fConst15 * fRec282[1]);
			double fTemp151 = (fConst16 * fRec285[1]);
			fRec287[0] = (fTemp149 + (fTemp150 + (fRec287[1] + fTemp151)));
			fRec285[0] = fRec287[0];
			double fRec286 = ((fTemp151 + fTemp150) + fTemp149);
			fRec284[0] = (fRec285[0] + fRec284[1]);
			fRec282[0] = fRec284[0];
			double fRec283 = fRec286;
			fRec281[0] = (fTemp148 + (fRec283 + fRec281[1]));
			fRec279[0] = fRec281[0];
			double fRec280 = (fRec283 + fTemp148);
			double fTemp152 = (fConst18 * ((0.0149227358 * fTemp33) - ((0.029748477400000001 * fTemp32) + (0.048993963699999997 * fTemp34))));
			double fTemp153 = (fConst19 * fRec288[1]);
			fRec290[0] = (fTemp152 + (fRec290[1] + fTemp153));
			fRec288[0] = fRec290[0];
			double fRec289 = (fTemp153 + fTemp152);
			double fTemp154 = (fConst21 * (((0.067324036099999998 * fTemp37) + (0.035312055600000003 * fTemp40)) - (((0.0210804279 * fTemp38) + (0.0372758714 * fTemp41)) + (0.033096336300000001 * fTemp39))));
			double fTemp155 = (fConst22 * fRec291[1]);
			double fTemp156 = (fConst23 * fRec294[1]);
			fRec296[0] = (fTemp154 + (fTemp155 + (fRec296[1] + fTemp156)));
			fRec294[0] = fRec296[0];
			double fRec295 = ((fTemp156 + fTemp155) + fTemp154);
			fRec293[0] = (fRec294[0] + fRec293[1]);
			fRec291[0] = fRec293[0];
			double fRec292 = fRec295;
			fVec8[(IOTA & 127)] = ((0.0203014626 * fTemp7) + (fRec268 + (fRec280 + (fRec289 + fRec292))));
			output8[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec8[((IOTA - iConst24) & 127)])));
			double fTemp157 = (fConst26 * fRec297[1]);
			double fTemp158 = (fConst27 * fRec300[1]);
			double fTemp159 = (fConst29 * (((((0.039751654499999997 * fTemp10) + (0.0063091683000000001 * fTemp13)) + (0.042588462399999999 * fTemp14)) + (0.065025200699999994 * fTemp17)) - ((0.0365129098 * fTemp16) + (((0.0176913956 * fTemp11) + (0.0110519412 * fTemp12)) + (0.0426323537 * fTemp15)))));
			double fTemp160 = (fConst30 * fRec303[1]);
			double fTemp161 = (fConst31 * fRec306[1]);
			fRec308[0] = (fTemp159 + (fTemp160 + (fRec308[1] + fTemp161)));
			fRec306[0] = fRec308[0];
			double fRec307 = ((fTemp161 + fTemp160) + fTemp159);
			fRec305[0] = (fRec306[0] + fRec305[1]);
			fRec303[0] = fRec305[0];
			double fRec304 = fRec307;
			fRec302[0] = (fTemp157 + (fTemp158 + (fRec304 + fRec302[1])));
			fRec300[0] = fRec302[0];
			double fRec301 = (fTemp157 + (fRec304 + fTemp158));
			fRec299[0] = (fRec300[0] + fRec299[1]);
			fRec297[0] = fRec299[0];
			double fRec298 = fRec301;
			double fTemp162 = (fConst33 * fRec309[1]);
			double fTemp163 = (fConst35 * (((0.0307363241 * fTemp24) + (((0.0095601817999999995 * fTemp23) + (0.0059447804000000003 * fTemp25)) + (0.0450445976 * fTemp27))) - (((0.027921281199999998 * fTemp22) + (0.0241286036 * fTemp26)) + (0.063797515599999993 * fTemp28))));
			double fTemp164 = (fConst36 * fRec312[1]);
			double fTemp165 = (fConst37 * fRec315[1]);
			fRec317[0] = (fTemp163 + (fTemp164 + (fRec317[1] + fTemp165)));
			fRec315[0] = fRec317[0];
			double fRec316 = ((fTemp165 + fTemp164) + fTemp163);
			fRec314[0] = (fRec315[0] + fRec314[1]);
			fRec312[0] = fRec314[0];
			double fRec313 = fRec316;
			fRec311[0] = (fTemp162 + (fRec313 + fRec311[1]));
			fRec309[0] = fRec311[0];
			double fRec310 = (fRec313 + fTemp162);
			double fTemp166 = (fConst39 * ((0.0081684841999999994 * fTemp33) - ((0.0059353063999999997 * fTemp32) + (0.042609599499999998 * fTemp34))));
			double fTemp167 = (fConst40 * fRec318[1]);
			fRec320[0] = (fTemp166 + (fRec320[1] + fTemp167));
			fRec318[0] = fRec320[0];
			double fRec319 = (fTemp167 + fTemp166);
			double fTemp168 = (fConst42 * (((0.015992447399999998 * fTemp37) + (0.056499036900000001 * fTemp40)) - (((0.0033505019 * fTemp38) + (0.031212528199999999 * fTemp41)) + (0.021970014199999999 * fTemp39))));
			double fTemp169 = (fConst43 * fRec321[1]);
			double fTemp170 = (fConst44 * fRec324[1]);
			fRec326[0] = (fTemp168 + (fTemp169 + (fRec326[1] + fTemp170)));
			fRec324[0] = fRec326[0];
			double fRec325 = ((fTemp170 + fTemp169) + fTemp168);
			fRec323[0] = (fRec324[0] + fRec323[1]);
			fRec321[0] = fRec323[0];
			double fRec322 = fRec325;
			fVec9[(IOTA & 127)] = ((0.014890234299999999 * fTemp7) + (fRec298 + (fRec310 + (fRec319 + fRec322))));
			output9[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec9[((IOTA - iConst45) & 127)])));
			double fTemp171 = (fConst26 * fRec327[1]);
			double fTemp172 = (fConst27 * fRec330[1]);
			double fTemp173 = (fConst29 * (((((0.040177372000000003 * fTemp11) + (0.021033395100000001 * fTemp12)) + (0.063884093200000006 * fTemp14)) + (0.0510720759 * fTemp17)) - ((0.050950990000000002 * fTemp16) + (((0.076397032700000006 * fTemp10) + (0.0148908033 * fTemp13)) + (0.033221765299999997 * fTemp15)))));
			double fTemp174 = (fConst30 * fRec333[1]);
			double fTemp175 = (fConst31 * fRec336[1]);
			fRec338[0] = (fTemp173 + (fTemp174 + (fRec338[1] + fTemp175)));
			fRec336[0] = fRec338[0];
			double fRec337 = ((fTemp175 + fTemp174) + fTemp173);
			fRec335[0] = (fRec336[0] + fRec335[1]);
			fRec333[0] = fRec335[0];
			double fRec334 = fRec337;
			fRec332[0] = (fTemp171 + (fTemp172 + (fRec334 + fRec332[1])));
			fRec330[0] = fRec332[0];
			double fRec331 = (fTemp171 + (fRec334 + fTemp172));
			fRec329[0] = (fRec330[0] + fRec329[1]);
			fRec327[0] = fRec329[0];
			double fRec328 = fRec331;
			double fTemp176 = (fConst33 * fRec339[1]);
			double fTemp177 = (fConst35 * (((0.049120922300000001 * fTemp24) + ((0.058211639599999997 * fTemp22) + (0.045905278600000002 * fTemp27))) - ((((0.023203534599999999 * fTemp23) + (0.012376945699999999 * fTemp25)) + (0.0398291375 * fTemp26)) + (0.064992922999999994 * fTemp28))));
			double fTemp178 = (fConst36 * fRec342[1]);
			double fTemp179 = (fConst37 * fRec345[1]);
			fRec347[0] = (fTemp177 + (fTemp178 + (fRec347[1] + fTemp179)));
			fRec345[0] = fRec347[0];
			double fRec346 = ((fTemp179 + fTemp178) + fTemp177);
			fRec344[0] = (fRec345[0] + fRec344[1]);
			fRec342[0] = fRec344[0];
			double fRec343 = fRec346;
			fRec341[0] = (fTemp176 + (fRec343 + fRec341[1]));
			fRec339[0] = fRec341[0];
			double fRec340 = (fRec343 + fTemp176);
			double fTemp180 = (fConst39 * (((0.0136255609 * fTemp32) + (0.014898194599999999 * fTemp33)) - (0.0557105013 * fTemp34)));
			double fTemp181 = (fConst40 * fRec348[1]);
			fRec350[0] = (fTemp180 + (fRec350[1] + fTemp181));
			fRec348[0] = fRec350[0];
			double fRec349 = (fTemp181 + fTemp180);
			double fTemp182 = (fConst42 * (((0.0085057102000000006 * fTemp38) + (0.067367399300000005 * fTemp40)) - (((0.035352712600000002 * fTemp37) + (0.037343438999999999 * fTemp41)) + (0.038255028099999998 * fTemp39))));
			double fTemp183 = (fConst43 * fRec351[1]);
			double fTemp184 = (fConst44 * fRec354[1]);
			fRec356[0] = (fTemp182 + (fTemp183 + (fRec356[1] + fTemp184)));
			fRec354[0] = fRec356[0];
			double fRec355 = ((fTemp184 + fTemp183) + fTemp182);
			fRec353[0] = (fRec354[0] + fRec353[1]);
			fRec351[0] = fRec353[0];
			double fRec352 = fRec355;
			fVec10[(IOTA & 127)] = ((0.020309576900000001 * fTemp7) + (fRec328 + (fRec340 + (fRec349 + fRec352))));
			output10[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec10[((IOTA - iConst45) & 127)])));
			double fTemp185 = (fConst47 * fRec357[1]);
			double fTemp186 = (fConst48 * fRec360[1]);
			double fTemp187 = (fConst50 * (((((0.038386408400000002 * fTemp11) + (0.042730249099999999 * fTemp12)) + (0.034635150099999998 * fTemp14)) + (0.013328174700000001 * fTemp16)) - ((((0.039803916000000002 * fTemp10) + (0.025697066599999999 * fTemp13)) + (0.0110821249 * fTemp15)) + (0.065147456399999998 * fTemp17))));
			double fTemp188 = (fConst51 * fRec363[1]);
			double fTemp189 = (fConst52 * fRec366[1]);
			fRec368[0] = (fTemp187 + (fTemp188 + (fRec368[1] + fTemp189)));
			fRec366[0] = fRec368[0];
			double fRec367 = ((fTemp189 + fTemp188) + fTemp187);
			fRec365[0] = (fRec366[0] + fRec365[1]);
			fRec363[0] = fRec365[0];
			double fRec364 = fRec367;
			fRec362[0] = (fTemp185 + (fTemp186 + (fRec364 + fRec362[1])));
			fRec360[0] = fRec362[0];
			double fRec361 = (fTemp185 + (fRec364 + fTemp186));
			fRec359[0] = (fRec360[0] + fRec359[1]);
			fRec357[0] = fRec359[0];
			double fRec358 = fRec361;
			double fTemp190 = (fConst54 * fRec369[1]);
			double fTemp191 = (fConst56 * (((0.0254303502 * fTemp28) + ((0.0095778079000000006 * fTemp24) + ((0.064990564599999995 * fTemp22) + (0.0361467855 * fTemp27)))) - (((0.030790567000000001 * fTemp23) + (0.0277165373 * fTemp25)) + (0.0241737707 * fTemp26))));
			double fTemp192 = (fConst57 * fRec372[1]);
			double fTemp193 = (fConst58 * fRec375[1]);
			fRec377[0] = (fTemp191 + (fTemp192 + (fRec377[1] + fTemp193)));
			fRec375[0] = fRec377[0];
			double fRec376 = ((fTemp193 + fTemp192) + fTemp191);
			fRec374[0] = (fRec375[0] + fRec374[1]);
			fRec372[0] = fRec374[0];
			double fRec373 = fRec376;
			fRec371[0] = (fTemp190 + (fRec373 + fRec371[1]));
			fRec369[0] = fRec371[0];
			double fRec370 = (fRec373 + fTemp190);
			double fTemp194 = (fConst60 * (((0.0260005299 * fTemp32) + (0.0081851137999999993 * fTemp33)) - (0.0344149469 * fTemp34)));
			double fTemp195 = (fConst61 * fRec378[1]);
			fRec380[0] = (fTemp194 + (fRec380[1] + fTemp195));
			fRec378[0] = fRec380[0];
			double fRec379 = (fTemp195 + fTemp194);
			double fTemp196 = (fConst63 * (((0.013191336099999999 * fTemp38) + (0.0160282884 * fTemp40)) - (((0.056636752499999998 * fTemp37) + (0.031294055600000002 * fTemp41)) + (0.017939345499999999 * fTemp39))));
			double fTemp197 = (fConst64 * fRec381[1]);
			double fTemp198 = (fConst65 * fRec384[1]);
			fRec386[0] = (fTemp196 + (fTemp197 + (fRec386[1] + fTemp198)));
			fRec384[0] = fRec386[0];
			double fRec385 = ((fTemp198 + fTemp197) + fTemp196);
			fRec383[0] = (fRec384[0] + fRec383[1]);
			fRec381[0] = fRec383[0];
			double fRec382 = fRec385;
			fVec11[(IOTA & 127)] = ((0.014929747599999999 * fTemp7) + (fRec358 + (fRec370 + (fRec379 + fRec382))));
			output11[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec11[((IOTA - iConst66) & 127)])));
			double fTemp199 = (fConst5 * fRec387[1]);
			double fTemp200 = (fConst6 * fRec390[1]);
			double fTemp201 = (fConst8 * (((0.064468053499999997 * fTemp16) + ((0.020981976900000001 * fTemp15) + ((((0.076339643299999996 * fTemp10) + (0.0076396624000000003 * fTemp11)) + (0.0330664798 * fTemp12)) + (0.0346489985 * fTemp14)))) - ((0.055704387799999998 * fTemp13) + (0.050999174600000002 * fTemp17))));
			double fTemp202 = (fConst9 * fRec393[1]);
			double fTemp203 = (fConst10 * fRec396[1]);
			fRec398[0] = (fTemp201 + (fTemp202 + (fRec398[1] + fTemp203)));
			fRec396[0] = fRec398[0];
			double fRec397 = ((fTemp203 + fTemp202) + fTemp201);
			fRec395[0] = (fRec396[0] + fRec395[1]);
			fRec393[0] = fRec395[0];
			double fRec394 = fRec397;
			fRec392[0] = (fTemp199 + (fTemp200 + (fRec394 + fRec392[1])));
			fRec390[0] = fRec392[0];
			double fRec391 = (fTemp199 + (fRec394 + fTemp200));
			fRec389[0] = (fRec390[0] + fRec389[1]);
			fRec387[0] = fRec389[0];
			double fRec388 = fRec391;
			double fTemp204 = (fConst12 * fRec399[1]);
			double fTemp205 = (fConst14 * ((((0.0047816266 * fTemp22) + (0.023629899100000001 * fTemp27)) + (0.087036247499999997 * fTemp28)) - ((((0.049170050799999997 * fTemp23) + (0.041100110400000001 * fTemp25)) + (0.039856738199999998 * fTemp26)) + (0.023209618200000001 * fTemp24))));
			double fTemp206 = (fConst15 * fRec402[1]);
			double fTemp207 = (fConst16 * fRec405[1]);
			fRec407[0] = (fTemp205 + (fTemp206 + (fRec407[1] + fTemp207)));
			fRec405[0] = fRec407[0];
			double fRec406 = ((fTemp207 + fTemp206) + fTemp205);
			fRec404[0] = (fRec405[0] + fRec404[1]);
			fRec402[0] = fRec404[0];
			double fRec403 = fRec406;
			fRec401[0] = (fTemp204 + (fRec403 + fRec401[1]));
			fRec399[0] = fRec401[0];
			double fRec400 = (fRec403 + fTemp204);
			double fTemp208 = (fConst18 * (((0.048992347899999997 * fTemp32) + (0.014920154 * fTemp33)) - (0.0297393029 * fTemp34)));
			double fTemp209 = (fConst19 * fRec408[1]);
			fRec410[0] = (fTemp208 + (fRec410[1] + fTemp209));
			fRec408[0] = fRec410[0];
			double fRec409 = (fTemp209 + fTemp208);
			double fTemp210 = (fConst21 * ((0.033100803800000002 * fTemp38) - ((((0.0673100326 * fTemp37) + (0.037280832700000002 * fTemp41)) + (0.0210673405 * fTemp39)) + (0.035321888099999997 * fTemp40))));
			double fTemp211 = (fConst22 * fRec411[1]);
			double fTemp212 = (fConst23 * fRec414[1]);
			fRec416[0] = (fTemp210 + (fTemp211 + (fRec416[1] + fTemp212)));
			fRec414[0] = fRec416[0];
			double fRec415 = ((fTemp212 + fTemp211) + fTemp210);
			fRec413[0] = (fRec414[0] + fRec413[1]);
			fRec411[0] = fRec413[0];
			double fRec412 = fRec415;
			fVec12[(IOTA & 127)] = ((0.0202986639 * fTemp7) + (fRec388 + (fRec400 + (fRec409 + fRec412))));
			output12[i] = FAUSTFLOAT((0.9606741573033708 * (fRec0[0] * fVec12[((IOTA - iConst24) & 127)])));
			double fTemp213 = (fConst26 * fRec417[1]);
			double fTemp214 = (fConst27 * fRec420[1]);
			double fTemp215 = (fConst29 * (((0.065008824800000004 * fTemp17) + ((0.017642417000000001 * fTemp16) + ((0.042724883399999997 * fTemp15) + (((0.0397471904 * fTemp10) + (0.011092876999999999 * fTemp12)) + (0.0062987227999999999 * fTemp14))))) - ((0.036461632500000001 * fTemp11) + (0.042567339799999999 * fTemp13))));
			double fTemp216 = (fConst30 * fRec423[1]);
			double fTemp217 = (fConst31 * fRec426[1]);
			fRec428[0] = (fTemp215 + (fTemp216 + (fRec428[1] + fTemp217)));
			fRec426[0] = fRec428[0];
			double fRec427 = ((fTemp217 + fTemp216) + fTemp215);
			fRec425[0] = (fRec426[0] + fRec425[1]);
			fRec423[0] = fRec425[0];
			double fRec424 = fRec427;
			fRec422[0] = (fTemp213 + (fTemp214 + (fRec424 + fRec422[1])));
			fRec420[0] = fRec422[0];
			double fRec421 = (fTemp213 + (fRec424 + fTemp214));
			fRec419[0] = (fRec420[0] + fRec419[1]);
			fRec417[0] = fRec419[0];
			double fRec418 = fRec421;
			double fTemp218 = (fConst33 * fRec429[1]);
			double fTemp219 = (fConst35 * (((0.0059588126000000002 * fTemp27) + (0.0279206535 * fTemp28)) - (((((0.063793979099999995 * fTemp22) + (0.0095313327000000007 * fTemp23)) + (0.045114823999999998 * fTemp25)) + (0.024099450599999999 * fTemp26)) + (0.0306850291 * fTemp24))));
			double fTemp220 = (fConst36 * fRec432[1]);
			double fTemp221 = (fConst37 * fRec435[1]);
			fRec437[0] = (fTemp219 + (fTemp220 + (fRec437[1] + fTemp221)));
			fRec435[0] = fRec437[0];
			double fRec436 = ((fTemp221 + fTemp220) + fTemp219);
			fRec434[0] = (fRec435[0] + fRec434[1]);
			fRec432[0] = fRec434[0];
			double fRec433 = fRec436;
			fRec431[0] = (fTemp218 + (fRec433 + fRec431[1]));
			fRec429[0] = fRec431[0];
			double fRec430 = (fRec433 + fTemp218);
			double fTemp222 = (fConst39 * (((0.042609770999999998 * fTemp32) + (0.0081499260999999996 * fTemp33)) - (0.0059345589999999998 * fTemp34)));
			double fTemp223 = (fConst40 * fRec438[1]);
			fRec440[0] = (fTemp222 + (fRec440[1] + fTemp223));
			fRec438[0] = fRec440[0];
			double fRec439 = (fTemp223 + fTemp222);
			double fTemp224 = (fConst42 * ((0.021926979799999999 * fTemp38) - ((((0.0159919728 * fTemp37) + (0.031238016100000002 * fTemp41)) + (0.0033394117999999999 * fTemp39)) + (0.056500430800000001 * fTemp40))));
			double fTemp225 = (fConst43 * fRec441[1]);
			double fTemp226 = (fConst44 * fRec444[1]);
			fRec446[0] = (fTemp224 + (fTemp225 + (fRec446[1] + fTemp226)));
			fRec444[0] = fRec446[0];
			double fRec445 = ((fTemp226 + fTemp225) + fTemp224);
			fRec443[0] = (fRec444[0] + fRec443[1]);
			fRec441[0] = fRec443[0];
			double fRec442 = fRec445;
			fVec13[(IOTA & 127)] = ((0.014888663200000001 * fTemp7) + (fRec418 + (fRec430 + (fRec439 + fRec442))));
			output13[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec13[((IOTA - iConst45) & 127)])));
			double fTemp227 = (fConst26 * fRec447[1]);
			double fTemp228 = (fConst27 * fRec450[1]);
			double fTemp229 = (fConst29 * (((0.033158545800000001 * fTemp15) + (0.051132112399999999 * fTemp17)) - ((((((0.076327265599999999 * fTemp10) + (0.0510348204 * fTemp11)) + (0.020991891499999998 * fTemp12)) + (0.063924795199999995 * fTemp13)) + (0.014872882800000001 * fTemp14)) + (0.040142903399999999 * fTemp16))));
			double fTemp230 = (fConst30 * fRec453[1]);
			double fTemp231 = (fConst31 * fRec456[1]);
			fRec458[0] = (fTemp229 + (fTemp230 + (fRec458[1] + fTemp231)));
			fRec456[0] = fRec458[0];
			double fRec457 = ((fTemp231 + fTemp230) + fTemp229);
			fRec455[0] = (fRec456[0] + fRec455[1]);
			fRec453[0] = fRec455[0];
			double fRec454 = fRec457;
			fRec452[0] = (fTemp227 + (fTemp228 + (fRec454 + fRec452[1])));
			fRec450[0] = fRec452[0];
			double fRec451 = (fTemp227 + (fRec454 + fTemp228));
			fRec449[0] = (fRec450[0] + fRec449[1]);
			fRec447[0] = fRec449[0];
			double fRec448 = fRec451;
			double fTemp232 = (fConst33 * fRec459[1]);
			double fTemp233 = (fConst35 * ((0.023183874600000001 * fTemp23) - ((0.058145986699999999 * fTemp28) + (((((0.065032867199999997 * fTemp22) + (0.045848492599999999 * fTemp25)) + (0.039870407599999998 * fTemp26)) + (0.0123535537 * fTemp27)) + (0.049194931800000001 * fTemp24)))));
			double fTemp234 = (fConst36 * fRec462[1]);
			double fTemp235 = (fConst37 * fRec465[1]);
			fRec467[0] = (fTemp233 + (fTemp234 + (fRec467[1] + fTemp235)));
			fRec465[0] = fRec467[0];
			double fRec466 = ((fTemp235 + fTemp234) + fTemp233);
			fRec464[0] = (fRec465[0] + fRec464[1]);
			fRec462[0] = fRec464[0];
			double fRec463 = fRec466;
			fRec461[0] = (fTemp232 + (fRec463 + fRec461[1]));
			fRec459[0] = fRec461[0];
			double fRec460 = (fRec463 + fTemp232);
			double fTemp236 = (fConst39 * (((0.055723472599999997 * fTemp32) + (0.014923150899999999 * fTemp33)) + (0.0136076102 * fTemp34)));
			double fTemp237 = (fConst40 * fRec468[1]);
			fRec470[0] = (fTemp236 + (fRec470[1] + fTemp237));
			fRec468[0] = fRec470[0];
			double fRec469 = (fTemp237 + fTemp236);
			double fTemp238 = (fConst42 * ((((0.0353080598 * fTemp37) + (0.038313705500000003 * fTemp38)) + (0.0084990055999999998 * fTemp39)) - ((0.037324424100000003 * fTemp41) + (0.067389637099999997 * fTemp40))));
			double fTemp239 = (fConst43 * fRec471[1]);
			double fTemp240 = (fConst44 * fRec474[1]);
			fRec476[0] = (fTemp238 + (fTemp239 + (fRec476[1] + fTemp240)));
			fRec474[0] = fRec476[0];
			double fRec475 = ((fTemp240 + fTemp239) + fTemp238);
			fRec473[0] = (fRec474[0] + fRec473[1]);
			fRec471[0] = fRec473[0];
			double fRec472 = fRec475;
			fVec14[(IOTA & 127)] = ((0.020315367599999998 * fTemp7) + (fRec448 + (fRec460 + (fRec469 + fRec472))));
			output14[i] = FAUSTFLOAT((0.9619850187265917 * (fRec0[0] * fVec14[((IOTA - iConst45) & 127)])));
			double fTemp241 = (fConst47 * fRec477[1]);
			double fTemp242 = (fConst48 * fRec480[1]);
			double fTemp243 = (fConst50 * (((0.0133293988 * fTemp11) + (0.011067599500000001 * fTemp15)) - ((0.065078030499999995 * fTemp17) + (((((0.039726134500000003 * fTemp10) + (0.0427061522 * fTemp12)) + (0.034600779800000002 * fTemp13)) + (0.025677240600000002 * fTemp14)) + (0.038329681499999997 * fTemp16)))));
			double fTemp244 = (fConst51 * fRec483[1]);
			double fTemp245 = (fConst52 * fRec486[1]);
			fRec488[0] = (fTemp243 + (fTemp244 + (fRec488[1] + fTemp245)));
			fRec486[0] = fRec488[0];
			double fRec487 = ((fTemp245 + fTemp244) + fTemp243);
			fRec485[0] = (fRec486[0] + fRec485[1]);
			fRec483[0] = fRec485[0];
			double fRec484 = fRec487;
			fRec482[0] = (fTemp241 + (fTemp242 + (fRec484 + fRec482[1])));
			fRec480[0] = fRec482[0];
			double fRec481 = (fTemp241 + (fRec484 + fTemp242));
			fRec479[0] = (fRec480[0] + fRec479[1]);
			fRec477[0] = fRec479[0];
			double fRec478 = fRec481;
			double fTemp246 = (fConst54 * fRec489[1]);
			double fTemp247 = (fConst56 * (((0.025411027700000002 * fTemp22) + (0.030741221400000001 * fTemp23)) - ((0.0648815482 * fTemp28) + ((((0.036105198599999999 * fTemp25) + (0.024137626499999999 * fTemp26)) + (0.027690037800000001 * fTemp27)) + (0.0095517760999999993 * fTemp24)))));
			double fTemp248 = (fConst57 * fRec492[1]);
			double fTemp249 = (fConst58 * fRec495[1]);
			fRec497[0] = (fTemp247 + (fTemp248 + (fRec497[1] + fTemp249)));
			fRec495[0] = fRec497[0];
			double fRec496 = ((fTemp249 + fTemp248) + fTemp247);
			fRec494[0] = (fRec495[0] + fRec494[1]);
			fRec492[0] = fRec494[0];
			double fRec493 = fRec496;
			fRec491[0] = (fTemp246 + (fRec493 + fRec491[1]));
			fRec489[0] = fRec491[0];
			double fRec490 = (fRec493 + fTemp246);
			double fTemp250 = (fConst60 * (((0.034346033800000002 * fTemp32) + (0.0081661475000000001 * fTemp33)) + (0.025954395000000002 * fTemp34)));
			double fTemp251 = (fConst61 * fRec498[1]);
			fRec500[0] = (fTemp250 + (fRec500[1] + fTemp251));
			fRec498[0] = fRec500[0];
			double fRec499 = (fTemp251 + fTemp250);
			double fTemp252 = (fConst63 * ((((0.056540471500000002 * fTemp37) + (0.017900681700000001 * fTemp38)) + (0.0131673502 * fTemp39)) - ((0.031246581999999998 * fTemp41) + (0.015987934400000001 * fTemp40))));
			double fTemp253 = (fConst64 * fRec501[1]);
			double fTemp254 = (fConst65 * fRec504[1]);
			fRec506[0] = (fTemp252 + (fTemp253 + (fRec506[1] + fTemp254)));
			fRec504[0] = fRec506[0];
			double fRec505 = ((fTemp254 + fTemp253) + fTemp252);
			fRec503[0] = (fRec504[0] + fRec503[1]);
			fRec501[0] = fRec503[0];
			double fRec502 = fRec505;
			fVec15[(IOTA & 127)] = ((0.0148994292 * fTemp7) + (fRec478 + (fRec490 + (fRec499 + fRec502))));
			output15[i] = FAUSTFLOAT((0.96142322097378285 * (fRec0[0] * fVec15[((IOTA - iConst66) & 127)])));
			double fTemp255 = (fConst68 * fRec507[1]);
			double fTemp256 = (fConst69 * fRec510[1]);
			double fTemp257 = (fConst71 * ((((0.0041447818000000004 * fTemp11) + (0.1048635136 * fTemp12)) + (0.0042336205000000002 * fTemp13)) - ((0.028000909000000001 * fTemp17) + ((0.1145065529 * fTemp16) + (((0.033978180400000002 * fTemp10) + (0.010158956300000001 * fTemp14)) + (0.073002388500000001 * fTemp15))))));
			double fTemp258 = (fConst72 * fRec513[1]);
			double fTemp259 = (fConst73 * fRec516[1]);
			fRec518[0] = (fTemp257 + (fTemp258 + (fRec518[1] + fTemp259)));
			fRec516[0] = fRec518[0];
			double fRec517 = ((fTemp259 + fTemp258) + fTemp257);
			fRec515[0] = (fRec516[0] + fRec515[1]);
			fRec513[0] = fRec515[0];
			double fRec514 = fRec517;
			fRec512[0] = (fTemp255 + (fTemp256 + (fRec514 + fRec512[1])));
			fRec510[0] = fRec512[0];
			double fRec511 = (fTemp255 + (fRec514 + fTemp256));
			fRec509[0] = (fRec510[0] + fRec509[1]);
			fRec507[0] = fRec509[0];
			double fRec508 = fRec511;
			double fTemp260 = (fConst75 * fRec519[1]);
			double fTemp261 = (fConst77 * (((((0.0052889347999999997 * fTemp22) + (0.1202940882 * fTemp23)) + (0.093574874200000005 * fTemp25)) + (0.045274177899999997 * fTemp27)) - ((0.062968760900000004 * fTemp28) + ((0.054973781899999997 * fTemp26) + (0.0702121629 * fTemp24)))));
			double fTemp262 = (fConst78 * fRec522[1]);
			double fTemp263 = (fConst79 * fRec525[1]);
			fRec527[0] = (fTemp261 + (fTemp262 + (fRec527[1] + fTemp263)));
			fRec525[0] = fRec527[0];
			double fRec526 = ((fTemp263 + fTemp262) + fTemp261);
			fRec524[0] = (fRec525[0] + fRec524[1]);
			fRec522[0] = fRec524[0];
			double fRec523 = fRec526;
			fRec521[0] = (fTemp260 + (fRec523 + fRec521[1]));
			fRec519[0] = fRec521[0];
			double fRec520 = (fRec523 + fTemp260);
			double fTemp264 = (fConst81 * (((0.070419014000000002 * fTemp32) + (0.071391873699999997 * fTemp33)) + (0.040731515199999999 * fTemp34)));
			double fTemp265 = (fConst82 * fRec528[1]);
			fRec530[0] = (fTemp264 + (fRec530[1] + fTemp265));
			fRec528[0] = fRec530[0];
			double fRec529 = (fTemp265 + fTemp264);
			double fTemp266 = (fConst84 * (((((0.069363888799999995 * fTemp37) + (0.12224572190000001 * fTemp38)) + (0.024018279199999999 * fTemp41)) + (0.067786083900000002 * fTemp39)) - (0.037380876299999997 * fTemp40)));
			double fTemp267 = (fConst85 * fRec531[1]);
			double fTemp268 = (fConst86 * fRec534[1]);
			fRec536[0] = (fTemp266 + (fTemp267 + (fRec536[1] + fTemp268)));
			fRec534[0] = fRec536[0];
			double fRec535 = ((fTemp268 + fTemp267) + fTemp266);
			fRec533[0] = (fRec534[0] + fRec533[1]);
			fRec531[0] = fRec533[0];
			double fRec532 = fRec535;
			fVec16[(IOTA & 127)] = ((0.038011396400000001 * fTemp7) + (fRec508 + (fRec520 + (fRec529 + fRec532))));
			output16[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec16[((IOTA - iConst87) & 127)])));
			double fTemp269 = (fConst68 * fRec537[1]);
			double fTemp270 = (fConst69 * fRec540[1]);
			double fTemp271 = (fConst71 * (((0.028821366599999999 * fTemp17) + ((0.082303723699999998 * fTemp16) + ((((0.034112062999999998 * fTemp10) + (0.071048121300000003 * fTemp11)) + (0.052281072900000003 * fTemp12)) + (0.085731005900000004 * fTemp15)))) - ((0.0043342603 * fTemp13) + (0.036044131799999997 * fTemp14))));
			double fTemp272 = (fConst72 * fRec543[1]);
			double fTemp273 = (fConst73 * fRec546[1]);
			fRec548[0] = (fTemp271 + (fTemp272 + (fRec548[1] + fTemp273)));
			fRec546[0] = fRec548[0];
			double fRec547 = ((fTemp273 + fTemp272) + fTemp271);
			fRec545[0] = (fRec546[0] + fRec545[1]);
			fRec543[0] = fRec545[0];
			double fRec544 = fRec547;
			fRec542[0] = (fTemp269 + (fTemp270 + (fRec544 + fRec542[1])));
			fRec540[0] = fRec542[0];
			double fRec541 = (fTemp269 + (fRec544 + fTemp270));
			fRec539[0] = (fRec540[0] + fRec539[1]);
			fRec537[0] = fRec539[0];
			double fRec538 = fRec541;
			double fTemp274 = (fConst75 * fRec549[1]);
			double fTemp275 = (fConst77 * (((0.047697994600000002 * fTemp28) + ((0.1082953167 * fTemp24) + ((((0.038209709600000002 * fTemp22) + (0.057503765200000001 * fTemp23)) + (0.019567569399999998 * fTemp25)) + (0.064697349799999998 * fTemp27)))) - (0.063294942800000004 * fTemp26)));
			double fTemp276 = (fConst78 * fRec552[1]);
			double fTemp277 = (fConst79 * fRec555[1]);
			fRec557[0] = (fTemp275 + (fTemp276 + (fRec557[1] + fTemp277)));
			fRec555[0] = fRec557[0];
			double fRec556 = ((fTemp277 + fTemp276) + fTemp275);
			fRec554[0] = (fRec555[0] + fRec554[1]);
			fRec552[0] = fRec554[0];
			double fRec553 = fRec556;
			fRec551[0] = (fTemp274 + (fRec553 + fRec551[1]));
			fRec549[0] = fRec551[0];
			double fRec550 = (fRec553 + fTemp274);
			double fTemp278 = (fConst81 * (((0.016552897800000001 * fTemp32) + (0.0533641272 * fTemp33)) + (0.068042738800000002 * fTemp34)));
			double fTemp279 = (fConst82 * fRec558[1]);
			fRec560[0] = (fTemp278 + (fRec560[1] + fTemp279));
			fRec558[0] = fRec560[0];
			double fRec559 = (fTemp279 + fTemp278);
			double fTemp280 = (fConst84 * (((((0.032291960100000003 * fTemp37) + (0.028149608100000001 * fTemp38)) + (0.0055090701000000001 * fTemp41)) + (0.1100413943 * fTemp39)) + (0.064499198699999996 * fTemp40)));
			double fTemp281 = (fConst85 * fRec561[1]);
			double fTemp282 = (fConst86 * fRec564[1]);
			fRec566[0] = (fTemp280 + (fTemp281 + (fRec566[1] + fTemp282)));
			fRec564[0] = fRec566[0];
			double fRec565 = ((fTemp282 + fTemp281) + fTemp280);
			fRec563[0] = (fRec564[0] + fRec563[1]);
			fRec561[0] = fRec563[0];
			double fRec562 = fRec565;
			fVec17[(IOTA & 127)] = ((0.0306211721 * fTemp7) + (fRec538 + (fRec550 + (fRec559 + fRec562))));
			output17[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec17[((IOTA - iConst87) & 127)])));
			double fTemp283 = (fConst68 * fRec567[1]);
			double fTemp284 = (fConst69 * fRec570[1]);
			double fTemp285 = (fConst71 * (((0.0730098208 * fTemp15) + ((0.0101406967 * fTemp13) + (0.00427196 * fTemp14))) - ((0.027996421699999999 * fTemp17) + ((((0.033971424600000001 * fTemp10) + (0.11450058220000001 * fTemp11)) + (0.1048835318 * fTemp12)) + (0.0041402097000000004 * fTemp16)))));
			double fTemp286 = (fConst72 * fRec573[1]);
			double fTemp287 = (fConst73 * fRec576[1]);
			fRec578[0] = (fTemp285 + (fTemp286 + (fRec578[1] + fTemp287)));
			fRec576[0] = fRec578[0];
			double fRec577 = ((fTemp287 + fTemp286) + fTemp285);
			fRec575[0] = (fRec576[0] + fRec575[1]);
			fRec573[0] = fRec575[0];
			double fRec574 = fRec577;
			fRec572[0] = (fTemp283 + (fTemp284 + (fRec574 + fRec572[1])));
			fRec570[0] = fRec572[0];
			double fRec571 = (fTemp283 + (fRec574 + fTemp284));
			fRec569[0] = (fRec570[0] + fRec569[1]);
			fRec567[0] = fRec569[0];
			double fRec568 = fRec571;
			double fTemp288 = (fConst75 * fRec579[1]);
			double fTemp289 = (fConst77 * (((0.093594236999999997 * fTemp27) + (0.0702060563 * fTemp24)) - (((((0.062953242500000006 * fTemp22) + (0.120279476 * fTemp23)) + (0.045284256799999999 * fTemp25)) + (0.054949432499999999 * fTemp26)) + (0.0052855645000000001 * fTemp28))));
			double fTemp290 = (fConst78 * fRec582[1]);
			double fTemp291 = (fConst79 * fRec585[1]);
			fRec587[0] = (fTemp289 + (fTemp290 + (fRec587[1] + fTemp291)));
			fRec585[0] = fRec587[0];
			double fRec586 = ((fTemp291 + fTemp290) + fTemp289);
			fRec584[0] = (fRec585[0] + fRec584[1]);
			fRec582[0] = fRec584[0];
			double fRec583 = fRec586;
			fRec581[0] = (fTemp288 + (fRec583 + fRec581[1]));
			fRec579[0] = fRec581[0];
			double fRec580 = (fRec583 + fTemp288);
			double fTemp292 = (fConst81 * (((0.071384467300000004 * fTemp33) + (0.070400406499999998 * fTemp34)) - (0.040719139299999998 * fTemp32)));
			double fTemp293 = (fConst82 * fRec588[1]);
			fRec590[0] = (fTemp292 + (fRec590[1] + fTemp293));
			fRec588[0] = fRec590[0];
			double fRec589 = (fTemp293 + fTemp292);
			double fTemp294 = (fConst84 * ((((0.024035194700000002 * fTemp41) + (0.1222313142 * fTemp39)) + (0.037372044600000001 * fTemp40)) - ((0.069343358699999996 * fTemp37) + (0.067775739400000007 * fTemp38))));
			double fTemp295 = (fConst85 * fRec591[1]);
			double fTemp296 = (fConst86 * fRec594[1]);
			fRec596[0] = (fTemp294 + (fTemp295 + (fRec596[1] + fTemp296)));
			fRec594[0] = fRec596[0];
			double fRec595 = ((fTemp296 + fTemp295) + fTemp294);
			fRec593[0] = (fRec594[0] + fRec593[1]);
			fRec591[0] = fRec593[0];
			double fRec592 = fRec595;
			fVec18[(IOTA & 127)] = ((0.038002752799999998 * fTemp7) + (fRec568 + (fRec580 + (fRec589 + fRec592))));
			output18[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec18[((IOTA - iConst87) & 127)])));
			double fTemp297 = (fConst68 * fRec597[1]);
			double fTemp298 = (fConst69 * fRec600[1]);
			double fTemp299 = (fConst71 * (((((0.0341125397 * fTemp10) + (0.082316823499999997 * fTemp11)) + (0.036036336600000003 * fTemp13)) + (0.028822862599999999 * fTemp17)) - ((0.071022644300000007 * fTemp16) + (((0.0522847148 * fTemp12) + (0.0043025155000000004 * fTemp14)) + (0.085731476200000004 * fTemp15)))));
			double fTemp300 = (fConst72 * fRec603[1]);
			double fTemp301 = (fConst73 * fRec606[1]);
			fRec608[0] = (fTemp299 + (fTemp300 + (fRec608[1] + fTemp301)));
			fRec606[0] = fRec608[0];
			double fRec607 = ((fTemp301 + fTemp300) + fTemp299);
			fRec605[0] = (fRec606[0] + fRec605[1]);
			fRec603[0] = fRec605[0];
			double fRec604 = fRec607;
			fRec602[0] = (fTemp297 + (fTemp298 + (fRec604 + fRec602[1])));
			fRec600[0] = fRec602[0];
			double fRec601 = (fTemp297 + (fRec604 + fTemp298));
			fRec599[0] = (fRec600[0] + fRec599[1]);
			fRec597[0] = fRec599[0];
			double fRec598 = fRec601;
			double fTemp302 = (fConst75 * fRec609[1]);
			double fTemp303 = (fConst77 * (((0.047710902999999999 * fTemp22) + (0.019581777799999998 * fTemp27)) - ((0.038201092999999998 * fTemp28) + ((((0.057491693699999999 * fTemp23) + (0.064715528600000002 * fTemp25)) + (0.063298276000000001 * fTemp26)) + (0.1083150329 * fTemp24)))));
			double fTemp304 = (fConst78 * fRec612[1]);
			double fTemp305 = (fConst79 * fRec615[1]);
			fRec617[0] = (fTemp303 + (fTemp304 + (fRec617[1] + fTemp305)));
			fRec615[0] = fRec617[0];
			double fRec616 = ((fTemp305 + fTemp304) + fTemp303);
			fRec614[0] = (fRec615[0] + fRec614[1]);
			fRec612[0] = fRec614[0];
			double fRec613 = fRec616;
			fRec611[0] = (fTemp302 + (fRec613 + fRec611[1]));
			fRec609[0] = fRec611[0];
			double fRec610 = (fRec613 + fTemp302);
			double fTemp306 = (fConst81 * (((0.053382876199999998 * fTemp33) + (0.016550943200000001 * fTemp34)) - (0.068062192199999996 * fTemp32)));
			double fTemp307 = (fConst82 * fRec618[1]);
			fRec620[0] = (fTemp306 + (fRec620[1] + fTemp307));
			fRec618[0] = fRec620[0];
			double fRec619 = (fTemp307 + fTemp306);
			double fTemp308 = (fConst84 * (((0.0055179063999999996 * fTemp41) + (0.028150457199999999 * fTemp39)) - (((0.032284151099999998 * fTemp37) + (0.1100701746 * fTemp38)) + (0.064516527800000001 * fTemp40))));
			double fTemp309 = (fConst85 * fRec621[1]);
			double fTemp310 = (fConst86 * fRec624[1]);
			fRec626[0] = (fTemp308 + (fTemp309 + (fRec626[1] + fTemp310)));
			fRec624[0] = fRec626[0];
			double fRec625 = ((fTemp310 + fTemp309) + fTemp308);
			fRec623[0] = (fRec624[0] + fRec623[1]);
			fRec621[0] = fRec623[0];
			double fRec622 = fRec625;
			fVec19[(IOTA & 127)] = ((0.030631296299999999 * fTemp7) + (fRec598 + (fRec610 + (fRec619 + fRec622))));
			output19[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec19[((IOTA - iConst87) & 127)])));
			double fTemp311 = (fConst68 * fRec627[1]);
			double fTemp312 = (fConst69 * fRec630[1]);
			double fTemp313 = (fConst71 * ((((0.1048542385 * fTemp12) + (0.0101488086 * fTemp14)) + (0.1145043437 * fTemp16)) - (((((0.0339556414 * fTemp10) + (0.0041961758000000002 * fTemp11)) + (0.0042976118000000001 * fTemp13)) + (0.073005793499999999 * fTemp15)) + (0.028043553999999998 * fTemp17))));
			double fTemp314 = (fConst72 * fRec633[1]);
			double fTemp315 = (fConst73 * fRec636[1]);
			fRec638[0] = (fTemp313 + (fTemp314 + (fRec638[1] + fTemp315)));
			fRec636[0] = fRec638[0];
			double fRec637 = ((fTemp315 + fTemp314) + fTemp313);
			fRec635[0] = (fRec636[0] + fRec635[1]);
			fRec633[0] = fRec635[0];
			double fRec634 = fRec637;
			fRec632[0] = (fTemp311 + (fTemp312 + (fRec634 + fRec632[1])));
			fRec630[0] = fRec632[0];
			double fRec631 = (fTemp311 + (fRec634 + fTemp312));
			fRec629[0] = (fRec630[0] + fRec629[1]);
			fRec627[0] = fRec629[0];
			double fRec628 = fRec631;
			double fTemp316 = (fConst75 * fRec639[1]);
			double fTemp317 = (fConst77 * (((0.1202824868 * fTemp23) + (0.062959801400000001 * fTemp28)) - (((((0.0053327195000000003 * fTemp22) + (0.093581303099999999 * fTemp25)) + (0.054921770000000002 * fTemp26)) + (0.045266623899999997 * fTemp27)) + (0.070170791999999996 * fTemp24))));
			double fTemp318 = (fConst78 * fRec642[1]);
			double fTemp319 = (fConst79 * fRec645[1]);
			fRec647[0] = (fTemp317 + (fTemp318 + (fRec647[1] + fTemp319)));
			fRec645[0] = fRec647[0];
			double fRec646 = ((fTemp319 + fTemp318) + fTemp317);
			fRec644[0] = (fRec645[0] + fRec644[1]);
			fRec642[0] = fRec644[0];
			double fRec643 = fRec646;
			fRec641[0] = (fTemp316 + (fRec643 + fRec641[1]));
			fRec639[0] = fRec641[0];
			double fRec640 = (fRec643 + fTemp316);
			double fTemp320 = (fConst81 * ((0.071377611199999996 * fTemp33) - ((0.070388008899999993 * fTemp32) + (0.040726760399999999 * fTemp34))));
			double fTemp321 = (fConst82 * fRec648[1]);
			fRec650[0] = (fTemp320 + (fRec650[1] + fTemp321));
			fRec648[0] = fRec650[0];
			double fRec649 = (fTemp321 + fTemp320);
			double fTemp322 = (fConst84 * (((0.069357866800000001 * fTemp37) + (0.024036521700000001 * fTemp41)) - (((0.12220778309999999 * fTemp38) + (0.067775720299999995 * fTemp39)) + (0.037343894099999997 * fTemp40))));
			double fTemp323 = (fConst85 * fRec651[1]);
			double fTemp324 = (fConst86 * fRec654[1]);
			fRec656[0] = (fTemp322 + (fTemp323 + (fRec656[1] + fTemp324)));
			fRec654[0] = fRec656[0];
			double fRec655 = ((fTemp324 + fTemp323) + fTemp322);
			fRec653[0] = (fRec654[0] + fRec653[1]);
			fRec651[0] = fRec653[0];
			double fRec652 = fRec655;
			fVec20[(IOTA & 127)] = ((0.037999764599999999 * fTemp7) + (fRec628 + (fRec640 + (fRec649 + fRec652))));
			output20[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec20[((IOTA - iConst87) & 127)])));
			double fTemp325 = (fConst68 * fRec657[1]);
			double fTemp326 = (fConst69 * fRec660[1]);
			double fTemp327 = (fConst71 * ((((0.085715838500000002 * fTemp15) + ((((0.034129172499999999 * fTemp10) + (0.052249432700000001 * fTemp12)) + (0.0043294913000000001 * fTemp13)) + (0.036075632699999999 * fTemp14))) + (0.028806551999999999 * fTemp17)) - ((0.071043614099999999 * fTemp11) + (0.082312175400000007 * fTemp16))));
			double fTemp328 = (fConst72 * fRec663[1]);
			double fTemp329 = (fConst73 * fRec666[1]);
			fRec668[0] = (fTemp327 + (fTemp328 + (fRec668[1] + fTemp329)));
			fRec666[0] = fRec668[0];
			double fRec667 = ((fTemp329 + fTemp328) + fTemp327);
			fRec665[0] = (fRec666[0] + fRec665[1]);
			fRec663[0] = fRec665[0];
			double fRec664 = fRec667;
			fRec662[0] = (fTemp325 + (fTemp326 + (fRec664 + fRec662[1])));
			fRec660[0] = fRec662[0];
			double fRec661 = (fTemp325 + (fRec664 + fTemp326));
			fRec659[0] = (fRec660[0] + fRec659[1]);
			fRec657[0] = fRec659[0];
			double fRec658 = fRec661;
			double fTemp330 = (fConst75 * fRec669[1]);
			double fTemp331 = (fConst77 * (((0.057486007700000001 * fTemp23) + (0.1082990353 * fTemp24)) - (((((0.038218625200000002 * fTemp22) + (0.019553603499999999 * fTemp25)) + (0.063299092400000007 * fTemp26)) + (0.064664790999999999 * fTemp27)) + (0.047701833200000002 * fTemp28))));
			double fTemp332 = (fConst78 * fRec672[1]);
			double fTemp333 = (fConst79 * fRec675[1]);
			fRec677[0] = (fTemp331 + (fTemp332 + (fRec677[1] + fTemp333)));
			fRec675[0] = fRec677[0];
			double fRec676 = ((fTemp333 + fTemp332) + fTemp331);
			fRec674[0] = (fRec675[0] + fRec674[1]);
			fRec672[0] = fRec674[0];
			double fRec673 = fRec676;
			fRec671[0] = (fTemp330 + (fRec673 + fRec671[1]));
			fRec669[0] = fRec671[0];
			double fRec670 = (fRec673 + fTemp330);
			double fTemp334 = (fConst81 * ((0.053354718400000001 * fTemp33) - ((0.016548580800000001 * fTemp32) + (0.068044421800000005 * fTemp34))));
			double fTemp335 = (fConst82 * fRec678[1]);
			fRec680[0] = (fTemp334 + (fRec680[1] + fTemp335));
			fRec678[0] = fRec680[0];
			double fRec679 = (fTemp335 + fTemp334);
			double fTemp336 = (fConst84 * ((((0.0322900754 * fTemp37) + (0.0054927342000000001 * fTemp41)) + (0.064507223000000002 * fTemp40)) - ((0.028137084600000001 * fTemp38) + (0.11003032159999999 * fTemp39))));
			double fTemp337 = (fConst85 * fRec681[1]);
			double fTemp338 = (fConst86 * fRec684[1]);
			fRec686[0] = (fTemp336 + (fTemp337 + (fRec686[1] + fTemp338)));
			fRec684[0] = fRec686[0];
			double fRec685 = ((fTemp338 + fTemp337) + fTemp336);
			fRec683[0] = (fRec684[0] + fRec683[1]);
			fRec681[0] = fRec683[0];
			double fRec682 = fRec685;
			fVec21[(IOTA & 127)] = ((0.0306194443 * fTemp7) + (fRec658 + (fRec670 + (fRec679 + fRec682))));
			output21[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec21[((IOTA - iConst87) & 127)])));
			double fTemp339 = (fConst68 * fRec687[1]);
			double fTemp340 = (fConst69 * fRec690[1]);
			double fTemp341 = (fConst71 * (((0.0041004887 * fTemp16) + ((0.1145119819 * fTemp11) + (0.073033457199999999 * fTemp15))) - (((((0.033988066999999997 * fTemp10) + (0.1048814014 * fTemp12)) + (0.010117339499999999 * fTemp13)) + (0.0042768677999999996 * fTemp14)) + (0.027981421100000001 * fTemp17))));
			double fTemp342 = (fConst72 * fRec693[1]);
			double fTemp343 = (fConst73 * fRec696[1]);
			fRec698[0] = (fTemp341 + (fTemp342 + (fRec698[1] + fTemp343)));
			fRec696[0] = fRec698[0];
			double fRec697 = ((fTemp343 + fTemp342) + fTemp341);
			fRec695[0] = (fRec696[0] + fRec695[1]);
			fRec693[0] = fRec695[0];
			double fRec694 = fRec697;
			fRec692[0] = (fTemp339 + (fTemp340 + (fRec694 + fRec692[1])));
			fRec690[0] = fRec692[0];
			double fRec691 = (fTemp339 + (fRec694 + fTemp340));
			fRec689[0] = (fRec690[0] + fRec689[1]);
			fRec687[0] = fRec689[0];
			double fRec688 = fRec691;
			double fTemp344 = (fConst75 * fRec699[1]);
			double fTemp345 = (fConst77 * (((0.0052570658000000003 * fTemp28) + (((0.062967061899999996 * fTemp22) + (0.045294227200000002 * fTemp25)) + (0.070254434500000004 * fTemp24))) - (((0.12028478419999999 * fTemp23) + (0.054933005700000002 * fTemp26)) + (0.093623455100000003 * fTemp27))));
			double fTemp346 = (fConst78 * fRec702[1]);
			double fTemp347 = (fConst79 * fRec705[1]);
			fRec707[0] = (fTemp345 + (fTemp346 + (fRec707[1] + fTemp347)));
			fRec705[0] = fRec707[0];
			double fRec706 = ((fTemp347 + fTemp346) + fTemp345);
			fRec704[0] = (fRec705[0] + fRec704[1]);
			fRec702[0] = fRec704[0];
			double fRec703 = fRec706;
			fRec701[0] = (fTemp344 + (fRec703 + fRec701[1]));
			fRec699[0] = fRec701[0];
			double fRec700 = (fRec703 + fTemp344);
			double fTemp348 = (fConst81 * (((0.0407218497 * fTemp32) + (0.071420472099999993 * fTemp33)) - (0.070432630699999998 * fTemp34)));
			double fTemp349 = (fConst82 * fRec708[1]);
			fRec710[0] = (fTemp348 + (fRec710[1] + fTemp349));
			fRec708[0] = fRec710[0];
			double fRec709 = (fTemp349 + fTemp348);
			double fTemp350 = (fConst84 * ((((0.067781079499999994 * fTemp38) + (0.024061545 * fTemp41)) + (0.037406373 * fTemp40)) - ((0.069349797699999993 * fTemp37) + (0.12228017099999999 * fTemp39))));
			double fTemp351 = (fConst85 * fRec711[1]);
			double fTemp352 = (fConst86 * fRec714[1]);
			fRec716[0] = (fTemp350 + (fTemp351 + (fRec716[1] + fTemp352)));
			fRec714[0] = fRec716[0];
			double fRec715 = ((fTemp352 + fTemp351) + fTemp350);
			fRec713[0] = (fRec714[0] + fRec713[1]);
			fRec711[0] = fRec713[0];
			double fRec712 = fRec715;
			fVec22[(IOTA & 127)] = ((0.038020542300000001 * fTemp7) + (fRec688 + (fRec700 + (fRec709 + fRec712))));
			output22[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec22[((IOTA - iConst87) & 127)])));
			double fTemp353 = (fConst68 * fRec717[1]);
			double fTemp354 = (fConst69 * fRec720[1]);
			double fTemp355 = (fConst71 * (((0.028772314300000001 * fTemp17) + (((0.034126342599999998 * fTemp10) + (0.0043325257000000001 * fTemp14)) + (0.071074450600000005 * fTemp16))) - ((((0.082256332400000007 * fTemp11) + (0.052302601400000003 * fTemp12)) + (0.036002602299999999 * fTemp13)) + (0.085746373599999995 * fTemp15))));
			double fTemp356 = (fConst72 * fRec723[1]);
			double fTemp357 = (fConst73 * fRec726[1]);
			fRec728[0] = (fTemp355 + (fTemp356 + (fRec728[1] + fTemp357)));
			fRec726[0] = fRec728[0];
			double fRec727 = ((fTemp357 + fTemp356) + fTemp355);
			fRec725[0] = (fRec726[0] + fRec725[1]);
			fRec723[0] = fRec725[0];
			double fRec724 = fRec727;
			fRec722[0] = (fTemp353 + (fTemp354 + (fRec724 + fRec722[1])));
			fRec720[0] = fRec722[0];
			double fRec721 = (fTemp353 + (fRec724 + fTemp354));
			fRec719[0] = (fRec720[0] + fRec719[1]);
			fRec717[0] = fRec719[0];
			double fRec718 = fRec721;
			double fTemp358 = (fConst75 * fRec729[1]);
			double fTemp359 = (fConst77 * (((0.0647337729 * fTemp25) + (0.0382310846 * fTemp28)) - (((((0.0476547056 * fTemp22) + (0.057536119900000002 * fTemp23)) + (0.063280135000000001 * fTemp26)) + (0.019580840400000001 * fTemp27)) + (0.10827217460000001 * fTemp24))));
			double fTemp360 = (fConst78 * fRec732[1]);
			double fTemp361 = (fConst79 * fRec735[1]);
			fRec737[0] = (fTemp359 + (fTemp360 + (fRec737[1] + fTemp361)));
			fRec735[0] = fRec737[0];
			double fRec736 = ((fTemp361 + fTemp360) + fTemp359);
			fRec734[0] = (fRec735[0] + fRec734[1]);
			fRec732[0] = fRec734[0];
			double fRec733 = fRec736;
			fRec731[0] = (fTemp358 + (fRec733 + fRec731[1]));
			fRec729[0] = fRec731[0];
			double fRec730 = (fRec733 + fTemp358);
			double fTemp362 = (fConst81 * (((0.068032778700000004 * fTemp32) + (0.053373362100000002 * fTemp33)) - (0.016565980500000001 * fTemp34)));
			double fTemp363 = (fConst82 * fRec738[1]);
			fRec740[0] = (fTemp362 + (fRec740[1] + fTemp363));
			fRec738[0] = fRec740[0];
			double fRec739 = (fTemp363 + fTemp362);
			double fTemp364 = (fConst84 * (((0.1100449557 * fTemp38) + (0.0055321232 * fTemp41)) - (((0.032314148199999997 * fTemp37) + (0.0281700179 * fTemp39)) + (0.064471198499999993 * fTemp40))));
			double fTemp365 = (fConst85 * fRec741[1]);
			double fTemp366 = (fConst86 * fRec744[1]);
			fRec746[0] = (fTemp364 + (fTemp365 + (fRec746[1] + fTemp366)));
			fRec744[0] = fRec746[0];
			double fRec745 = ((fTemp366 + fTemp365) + fTemp364);
			fRec743[0] = (fRec744[0] + fRec743[1]);
			fRec741[0] = fRec743[0];
			double fRec742 = fRec745;
			fVec23[(IOTA & 127)] = ((0.0306213415 * fTemp7) + (fRec718 + (fRec730 + (fRec739 + fRec742))));
			output23[i] = FAUSTFLOAT((0.97453183520599251 * (fRec0[0] * fVec23[((IOTA - iConst87) & 127)])));
			double fTemp367 = (fConst89 * fRec747[1]);
			double fTemp368 = (fConst90 * fRec750[1]);
			double fTemp369 = (fConst92 * ((((0.00036988659999999998 * fTemp10) + (0.1489226551 * fTemp13)) + (0.016275781199999999 * fTemp16)) - (((((0.0099615417999999994 * fTemp11) + (0.056906549700000003 * fTemp12)) + (0.062940663100000002 * fTemp14)) + (0.066697567200000002 * fTemp15)) + (0.00028330519999999999 * fTemp17))));
			double fTemp370 = (fConst93 * fRec753[1]);
			double fTemp371 = (fConst94 * fRec756[1]);
			fRec758[0] = (fTemp369 + (fTemp370 + (fRec758[1] + fTemp371)));
			fRec756[0] = fRec758[0];
			double fRec757 = ((fTemp371 + fTemp370) + fTemp369);
			fRec755[0] = (fRec756[0] + fRec755[1]);
			fRec753[0] = fRec755[0];
			double fRec754 = fRec757;
			fRec752[0] = (fTemp367 + (fTemp368 + (fRec754 + fRec752[1])));
			fRec750[0] = fRec752[0];
			double fRec751 = (fTemp367 + (fRec754 + fTemp368));
			fRec749[0] = (fRec750[0] + fRec749[1]);
			fRec747[0] = fRec749[0];
			double fRec748 = fRec751;
			double fTemp372 = (fConst96 * fRec759[1]);
			double fTemp373 = (fConst98 * ((((0.13847193469999999 * fTemp25) + (0.083723758600000003 * fTemp26)) + (0.0062344825999999997 * fTemp28)) - ((((0.0038678001999999999 * fTemp22) + (0.034670622700000001 * fTemp23)) + (0.055250673600000001 * fTemp27)) + (0.041734716800000002 * fTemp24))));
			double fTemp374 = (fConst99 * fRec762[1]);
			double fTemp375 = (fConst100 * fRec765[1]);
			fRec767[0] = (fTemp373 + (fTemp374 + (fRec767[1] + fTemp375)));
			fRec765[0] = fRec767[0];
			double fRec766 = ((fTemp375 + fTemp374) + fTemp373);
			fRec764[0] = (fRec765[0] + fRec764[1]);
			fRec762[0] = fRec764[0];
			double fRec763 = fRec766;
			fRec761[0] = (fTemp372 + (fRec763 + fRec761[1]));
			fRec759[0] = fRec761[0];
			double fRec760 = (fRec763 + fTemp372);
			double fTemp376 = (fConst102 * (((0.039881849099999998 * fTemp32) + (0.088532238999999999 * fTemp33)) - (0.015116001299999999 * fTemp34)));
			double fTemp377 = (fConst103 * fRec768[1]);
			fRec770[0] = (fTemp376 + (fRec770[1] + fTemp377));
			fRec768[0] = fRec770[0];
			double fRec769 = (fTemp377 + fTemp376);
			double fTemp378 = (fConst105 * (((0.094799970499999997 * fTemp38) + (0.10635739380000001 * fTemp41)) - (((0.013823488599999999 * fTemp37) + (0.036598682600000002 * fTemp39)) + (0.016917791000000001 * fTemp40))));
			double fTemp379 = (fConst106 * fRec771[1]);
			double fTemp380 = (fConst107 * fRec774[1]);
			fRec776[0] = (fTemp378 + (fTemp379 + (fRec776[1] + fTemp380)));
			fRec774[0] = fRec776[0];
			double fRec775 = ((fTemp380 + fTemp379) + fTemp378);
			fRec773[0] = (fRec774[0] + fRec773[1]);
			fRec771[0] = fRec773[0];
			double fRec772 = fRec775;
			fVec24[0] = ((0.034354885699999997 * fTemp7) + (fRec748 + (fRec760 + (fRec769 + fRec772))));
			output24[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec24[iConst108])));
			double fTemp381 = (fConst89 * fRec777[1]);
			double fTemp382 = (fConst90 * fRec780[1]);
			double fTemp383 = (fConst92 * ((((((((0.0003674145 * fTemp10) + (0.0162470501 * fTemp11)) + (0.056873225600000001 * fTemp12)) + (0.062919761599999999 * fTemp13)) + (0.14897413879999999 * fTemp14)) + (0.0666431309 * fTemp15)) + (0.0099293989000000006 * fTemp16)) - (0.00028756579999999999 * fTemp17)));
			double fTemp384 = (fConst93 * fRec783[1]);
			double fTemp385 = (fConst94 * fRec786[1]);
			fRec788[0] = (fTemp383 + (fTemp384 + (fRec788[1] + fTemp385)));
			fRec786[0] = fRec788[0];
			double fRec787 = ((fTemp385 + fTemp384) + fTemp383);
			fRec785[0] = (fRec786[0] + fRec785[1]);
			fRec783[0] = fRec785[0];
			double fRec784 = fRec787;
			fRec782[0] = (fTemp381 + (fTemp382 + (fRec784 + fRec782[1])));
			fRec780[0] = fRec782[0];
			double fRec781 = (fTemp381 + (fRec784 + fTemp382));
			fRec779[0] = (fRec780[0] + fRec779[1]);
			fRec777[0] = fRec779[0];
			double fRec778 = fRec781;
			double fTemp386 = (fConst96 * fRec789[1]);
			double fTemp387 = (fConst98 * (((((((0.0062242631999999999 * fTemp22) + (0.034648934300000003 * fTemp23)) + (0.055236739799999997 * fTemp25)) + (0.083775584400000006 * fTemp26)) + (0.13850598359999999 * fTemp27)) + (0.041700136399999997 * fTemp24)) + (0.0038560680999999999 * fTemp28)));
			double fTemp388 = (fConst99 * fRec792[1]);
			double fTemp389 = (fConst100 * fRec795[1]);
			fRec797[0] = (fTemp387 + (fTemp388 + (fRec797[1] + fTemp389)));
			fRec795[0] = fRec797[0];
			double fRec796 = ((fTemp389 + fTemp388) + fTemp387);
			fRec794[0] = (fRec795[0] + fRec794[1]);
			fRec792[0] = fRec794[0];
			double fRec793 = fRec796;
			fRec791[0] = (fTemp386 + (fRec793 + fRec791[1]));
			fRec789[0] = fRec791[0];
			double fRec790 = (fRec793 + fTemp386);
			double fTemp390 = (fConst102 * (((0.015112081600000001 * fTemp32) + (0.088570217199999995 * fTemp33)) + (0.039885551200000001 * fTemp34)));
			double fTemp391 = (fConst103 * fRec798[1]);
			fRec800[0] = (fTemp390 + (fRec800[1] + fTemp391));
			fRec798[0] = fRec800[0];
			double fRec799 = (fTemp391 + fTemp390);
			double fTemp392 = (fConst105 * (((((0.0138143112 * fTemp37) + (0.036589704399999999 * fTemp38)) + (0.106411387 * fTemp41)) + (0.094814867900000002 * fTemp39)) + (0.0169033884 * fTemp40)));
			double fTemp393 = (fConst106 * fRec801[1]);
			double fTemp394 = (fConst107 * fRec804[1]);
			fRec806[0] = (fTemp392 + (fTemp393 + (fRec806[1] + fTemp394)));
			fRec804[0] = fRec806[0];
			double fRec805 = ((fTemp394 + fTemp393) + fTemp392);
			fRec803[0] = (fRec804[0] + fRec803[1]);
			fRec801[0] = fRec803[0];
			double fRec802 = fRec805;
			fVec25[0] = ((0.034368230399999998 * fTemp7) + (fRec778 + (fRec790 + (fRec799 + fRec802))));
			output25[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec25[iConst108])));
			double fTemp395 = (fConst89 * fRec807[1]);
			double fTemp396 = (fConst90 * fRec810[1]);
			double fTemp397 = (fConst92 * ((((0.00039784089999999998 * fTemp10) + (0.0099851135000000001 * fTemp11)) + (0.062888960399999999 * fTemp14)) - ((0.00027412310000000001 * fTemp17) + ((0.016311194099999999 * fTemp16) + (((0.0569313709 * fTemp12) + (0.14896404229999999 * fTemp13)) + (0.066701710999999997 * fTemp15))))));
			double fTemp398 = (fConst93 * fRec813[1]);
			double fTemp399 = (fConst94 * fRec816[1]);
			fRec818[0] = (fTemp397 + (fTemp398 + (fRec818[1] + fTemp399)));
			fRec816[0] = fRec818[0];
			double fRec817 = ((fTemp399 + fTemp398) + fTemp397);
			fRec815[0] = (fRec816[0] + fRec815[1]);
			fRec813[0] = fRec815[0];
			double fRec814 = fRec817;
			fRec812[0] = (fTemp395 + (fTemp396 + (fRec814 + fRec812[1])));
			fRec810[0] = fRec812[0];
			double fRec811 = (fTemp395 + (fRec814 + fTemp396));
			fRec809[0] = (fRec810[0] + fRec809[1]);
			fRec807[0] = fRec809[0];
			double fRec808 = fRec811;
			double fTemp400 = (fConst96 * fRec819[1]);
			double fTemp401 = (fConst98 * ((((0.0038815699 * fTemp22) + (0.083737399099999998 * fTemp26)) + (0.055223153599999998 * fTemp27)) - ((0.0062531050000000001 * fTemp28) + (((0.034691040700000002 * fTemp23) + (0.13851131250000001 * fTemp25)) + (0.041751650299999998 * fTemp24)))));
			double fTemp402 = (fConst99 * fRec822[1]);
			double fTemp403 = (fConst100 * fRec825[1]);
			fRec827[0] = (fTemp401 + (fTemp402 + (fRec827[1] + fTemp403)));
			fRec825[0] = fRec827[0];
			double fRec826 = ((fTemp403 + fTemp402) + fTemp401);
			fRec824[0] = (fRec825[0] + fRec824[1]);
			fRec822[0] = fRec824[0];
			double fRec823 = fRec826;
			fRec821[0] = (fTemp400 + (fRec823 + fRec821[1]));
			fRec819[0] = fRec821[0];
			double fRec820 = (fRec823 + fTemp400);
			double fTemp404 = (fConst102 * (((0.088548185599999996 * fTemp33) + (0.0151123496 * fTemp34)) - (0.039895589600000003 * fTemp32)));
			double fTemp405 = (fConst103 * fRec828[1]);
			fRec830[0] = (fTemp404 + (fRec830[1] + fTemp405));
			fRec828[0] = fRec830[0];
			double fRec829 = (fTemp405 + fTemp404);
			double fTemp406 = (fConst105 * (((0.10637524499999999 * fTemp41) + (0.036586640400000002 * fTemp39)) - (((0.0138333298 * fTemp37) + (0.094829860399999993 * fTemp38)) + (0.0169290993 * fTemp40))));
			double fTemp407 = (fConst106 * fRec831[1]);
			double fTemp408 = (fConst107 * fRec834[1]);
			fRec836[0] = (fTemp406 + (fTemp407 + (fRec836[1] + fTemp408)));
			fRec834[0] = fRec836[0];
			double fRec835 = ((fTemp408 + fTemp407) + fTemp406);
			fRec833[0] = (fRec834[0] + fRec833[1]);
			fRec831[0] = fRec833[0];
			double fRec832 = fRec835;
			fVec26[0] = ((0.034361336499999999 * fTemp7) + (fRec808 + (fRec820 + (fRec829 + fRec832))));
			output26[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec26[iConst108])));
			double fTemp409 = (fConst89 * fRec837[1]);
			double fTemp410 = (fConst90 * fRec840[1]);
			double fTemp411 = (fConst92 * ((((0.00037305740000000002 * fTemp10) + (0.056925988300000001 * fTemp12)) + (0.066669185399999997 * fTemp15)) - ((0.00029503379999999999 * fTemp17) + ((((0.0162765489 * fTemp11) + (0.062950191899999994 * fTemp13)) + (0.1489803931 * fTemp14)) + (0.0099259281000000001 * fTemp16)))));
			double fTemp412 = (fConst93 * fRec843[1]);
			double fTemp413 = (fConst94 * fRec846[1]);
			fRec848[0] = (fTemp411 + (fTemp412 + (fRec848[1] + fTemp413)));
			fRec846[0] = fRec848[0];
			double fRec847 = ((fTemp413 + fTemp412) + fTemp411);
			fRec845[0] = (fRec846[0] + fRec845[1]);
			fRec843[0] = fRec845[0];
			double fRec844 = fRec847;
			fRec842[0] = (fTemp409 + (fTemp410 + (fRec844 + fRec842[1])));
			fRec840[0] = fRec842[0];
			double fRec841 = (fTemp409 + (fRec844 + fTemp410));
			fRec839[0] = (fRec840[0] + fRec839[1]);
			fRec837[0] = fRec839[0];
			double fRec838 = fRec841;
			double fTemp414 = (fConst96 * fRec849[1]);
			double fTemp415 = (fConst98 * ((((0.034689685300000002 * fTemp23) + (0.083761760599999999 * fTemp26)) + (0.0417159904 * fTemp24)) - ((((0.0062378497 * fTemp22) + (0.0552722961 * fTemp25)) + (0.13852682529999999 * fTemp27)) + (0.0038529318999999999 * fTemp28))));
			double fTemp416 = (fConst99 * fRec852[1]);
			double fTemp417 = (fConst100 * fRec855[1]);
			fRec857[0] = (fTemp415 + (fTemp416 + (fRec857[1] + fTemp417)));
			fRec855[0] = fRec857[0];
			double fRec856 = ((fTemp417 + fTemp416) + fTemp415);
			fRec854[0] = (fRec855[0] + fRec854[1]);
			fRec852[0] = fRec854[0];
			double fRec853 = fRec856;
			fRec851[0] = (fTemp414 + (fRec853 + fRec851[1]));
			fRec849[0] = fRec851[0];
			double fRec850 = (fRec853 + fTemp414);
			double fTemp418 = (fConst102 * ((0.088579545900000001 * fTemp33) - ((0.015126289899999999 * fTemp32) + (0.0398976973 * fTemp34))));
			double fTemp419 = (fConst103 * fRec858[1]);
			fRec860[0] = (fTemp418 + (fRec860[1] + fTemp419));
			fRec858[0] = fRec860[0];
			double fRec859 = (fTemp419 + fTemp418);
			double fTemp420 = (fConst105 * ((((0.0138334818 * fTemp37) + (0.10641176920000001 * fTemp41)) + (0.016909811800000001 * fTemp40)) - ((0.036619387000000003 * fTemp38) + (0.0948377101 * fTemp39))));
			double fTemp421 = (fConst106 * fRec861[1]);
			double fTemp422 = (fConst107 * fRec864[1]);
			fRec866[0] = (fTemp420 + (fTemp421 + (fRec866[1] + fTemp422)));
			fRec864[0] = fRec866[0];
			double fRec865 = ((fTemp422 + fTemp421) + fTemp420);
			fRec863[0] = (fRec864[0] + fRec863[1]);
			fRec861[0] = fRec863[0];
			double fRec862 = fRec865;
			fVec27[0] = ((0.034373545499999998 * fTemp7) + (fRec838 + (fRec850 + (fRec859 + fRec862))));
			output27[i] = FAUSTFLOAT((0.99644194756554305 * (fRec0[0] * fVec27[iConst108])));
			double fTemp423 = (fConst110 * fRec867[1]);
			double fTemp424 = (fConst111 * fRec870[1]);
			double fTemp425 = (fConst113 * (((5.0616e-06 * fTemp16) + (((((3.4548999999999997e-05 * fTemp10) + (8.3846999999999995e-06 * fTemp11)) + (5.7409999999999998e-06 * fTemp12)) + (9.1636600000000003e-05 * fTemp13)) + (3.2799000000000002e-05 * fTemp15))) - ((4.1664600000000001e-05 * fTemp14) + (1.7976900000000001e-05 * fTemp17))));
			double fTemp426 = (fConst114 * fRec873[1]);
			double fTemp427 = (fConst115 * fRec876[1]);
			fRec878[0] = (fTemp425 + (fTemp426 + (fRec878[1] + fTemp427)));
			fRec876[0] = fRec878[0];
			double fRec877 = ((fTemp427 + fTemp426) + fTemp425);
			fRec875[0] = (fRec876[0] + fRec875[1]);
			fRec873[0] = fRec875[0];
			double fRec874 = fRec877;
			fRec872[0] = (fTemp423 + (fTemp424 + (fRec874 + fRec872[1])));
			fRec870[0] = fRec872[0];
			double fRec871 = (fTemp423 + (fRec874 + fTemp424));
			fRec869[0] = (fRec870[0] + fRec869[1]);
			fRec867[0] = fRec869[0];
			double fRec868 = fRec871;
			double fTemp428 = (fConst117 * fRec879[1]);
			double fTemp429 = (fConst119 * (((1.6007e-06 * fTemp28) + (((((2.5671e-06 * fTemp22) + (3.0189999999999998e-06 * fTemp23)) + (6.2012000000000002e-05 * fTemp25)) + (0.074076867699999993 * fTemp26)) + (1.5710999999999999e-05 * fTemp24))) - (2.9040600000000001e-05 * fTemp27)));
			double fTemp430 = (fConst120 * fRec882[1]);
			double fTemp431 = (fConst121 * fRec885[1]);
			fRec887[0] = (fTemp429 + (fTemp430 + (fRec887[1] + fTemp431)));
			fRec885[0] = fRec887[0];
			double fRec886 = ((fTemp431 + fTemp430) + fTemp429);
			fRec884[0] = (fRec885[0] + fRec884[1]);
			fRec882[0] = fRec884[0];
			double fRec883 = fRec886;
			fRec881[0] = (fTemp428 + (fRec883 + fRec881[1]));
			fRec879[0] = fRec881[0];
			double fRec880 = (fRec883 + fTemp428);
			double fTemp432 = (fConst123 * (((1.24741e-05 * fTemp32) + (0.034345824400000002 * fTemp33)) - (6.0310999999999997e-06 * fTemp34)));
			double fTemp433 = (fConst124 * fRec888[1]);
			fRec890[0] = (fTemp432 + (fRec890[1] + fTemp433));
			fRec888[0] = fRec890[0];
			double fRec889 = (fTemp433 + fTemp432);
			double fTemp434 = (fConst126 * (((((1.0774000000000001e-06 * fTemp37) + (3.4079899999999999e-05 * fTemp38)) + (0.055478496199999998 * fTemp41)) + (5.2643999999999999e-06 * fTemp40)) - (1.6277899999999999e-05 * fTemp39)));
			double fTemp435 = (fConst127 * fRec891[1]);
			double fTemp436 = (fConst128 * fRec894[1]);
			fRec896[0] = (fTemp434 + (fTemp435 + (fRec896[1] + fTemp436)));
			fRec894[0] = fRec896[0];
			double fRec895 = ((fTemp436 + fTemp435) + fTemp434);
			fRec893[0] = (fRec894[0] + fRec893[1]);
			fRec891[0] = fRec893[0];
			double fRec892 = fRec895;
			output28[i] = FAUSTFLOAT((fRec0[0] * ((0.011628344800000001 * fTemp7) + (fRec868 + (fRec880 + (fRec889 + fRec892))))));
			double fTemp437 = (fConst130 * fRec897[1]);
			double fTemp438 = (fConst131 * fRec900[1]);
			double fTemp439 = (fConst133 * (((0.056047287799999998 * fTemp16) + ((0.0011899018 * fTemp15) + ((((0.035044664400000002 * fTemp10) + (0.0063303526000000002 * fTemp12)) + (0.028673619800000001 * fTemp13)) + (0.033416372399999998 * fTemp14)))) - ((0.0898425313 * fTemp11) + (0.1141657034 * fTemp17))));
			double fTemp440 = (fConst134 * fRec903[1]);
			double fTemp441 = (fConst135 * fRec906[1]);
			fRec908[0] = (fTemp439 + (fTemp440 + (fRec908[1] + fTemp441)));
			fRec906[0] = fRec908[0];
			double fRec907 = ((fTemp441 + fTemp440) + fTemp439);
			fRec905[0] = (fRec906[0] + fRec905[1]);
			fRec903[0] = fRec905[0];
			double fRec904 = fRec907;
			fRec902[0] = (fTemp437 + (fTemp438 + (fRec904 + fRec902[1])));
			fRec900[0] = fRec902[0];
			double fRec901 = (fTemp437 + (fRec904 + fTemp438));
			fRec899[0] = (fRec900[0] + fRec899[1]);
			fRec897[0] = fRec899[0];
			double fRec898 = fRec901;
			double fTemp442 = (fConst137 * fRec909[1]);
			double fTemp443 = (fConst139 * (((0.098709739399999996 * fTemp22) + (0.045077498299999998 * fTemp26)) - ((0.0620865798 * fTemp28) + ((((0.097178974400000007 * fTemp23) + (0.0074881662000000002 * fTemp25)) + (0.0085648378000000008 * fTemp27)) + (0.014866345499999999 * fTemp24)))));
			double fTemp444 = (fConst140 * fRec912[1]);
			double fTemp445 = (fConst141 * fRec915[1]);
			fRec917[0] = (fTemp443 + (fTemp444 + (fRec917[1] + fTemp445)));
			fRec915[0] = fRec917[0];
			double fRec916 = ((fTemp445 + fTemp444) + fTemp443);
			fRec914[0] = (fRec915[0] + fRec914[1]);
			fRec912[0] = fRec914[0];
			double fRec913 = fRec916;
			fRec911[0] = (fTemp442 + (fRec913 + fRec911[1]));
			fRec909[0] = fRec911[0];
			double fRec910 = (fRec913 + fTemp442);
			double fTemp446 = (fConst143 * (((0.0555503148 * fTemp32) + (0.064570036499999997 * fTemp34)) - (0.038110248700000002 * fTemp33)));
			double fTemp447 = (fConst144 * fRec918[1]);
			fRec920[0] = (fTemp446 + (fRec920[1] + fTemp447));
			fRec918[0] = fRec920[0];
			double fRec919 = (fTemp447 + fTemp446);
			double fTemp448 = (fConst146 * (((0.1048690719 * fTemp37) + (0.015807961499999999 * fTemp40)) - (((0.0532736038 * fTemp38) + (0.026508827299999999 * fTemp41)) + (0.062044658400000001 * fTemp39))));
			double fTemp449 = (fConst147 * fRec921[1]);
			double fTemp450 = (fConst148 * fRec924[1]);
			fRec926[0] = (fTemp448 + (fTemp449 + (fRec926[1] + fTemp450)));
			fRec924[0] = fRec926[0];
			double fRec925 = ((fTemp450 + fTemp449) + fTemp448);
			fRec923[0] = (fRec924[0] + fRec923[1]);
			fRec921[0] = fRec923[0];
			double fRec922 = fRec925;
			fVec28[(IOTA & 511)] = ((0.033283181699999997 * fTemp7) + (fRec898 + (fRec910 + (fRec919 + fRec922))));
			output29[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec28[((IOTA - iConst149) & 511)])));
			double fTemp451 = (fConst151 * fRec927[1]);
			double fTemp452 = (fConst152 * fRec930[1]);
			double fTemp453 = (fConst154 * ((((0.0053189274000000003 * fTemp15) + ((((0.1144768895 * fTemp10) + (0.0037560648999999998 * fTemp12)) + (0.0138674908 * fTemp13)) + (0.041848493299999998 * fTemp14))) + (0.033789075100000003 * fTemp17)) - ((0.086787957400000004 * fTemp11) + (0.060724842299999998 * fTemp16))));
			double fTemp454 = (fConst155 * fRec933[1]);
			double fTemp455 = (fConst156 * fRec936[1]);
			fRec938[0] = (fTemp453 + (fTemp454 + (fRec938[1] + fTemp455)));
			fRec936[0] = fRec938[0];
			double fRec937 = ((fTemp455 + fTemp454) + fTemp453);
			fRec935[0] = (fRec936[0] + fRec935[1]);
			fRec933[0] = fRec935[0];
			double fRec934 = fRec937;
			fRec932[0] = (fTemp451 + (fTemp452 + (fRec934 + fRec932[1])));
			fRec930[0] = fRec932[0];
			double fRec931 = (fTemp451 + (fRec934 + fTemp452));
			fRec929[0] = (fRec930[0] + fRec929[1]);
			fRec927[0] = fRec929[0];
			double fRec928 = fRec931;
			double fTemp456 = (fConst158 * fRec939[1]);
			double fTemp457 = (fConst160 * ((((0.095660903800000002 * fTemp22) + (0.045114781399999998 * fTemp26)) + (0.066569255699999996 * fTemp28)) - ((((0.058752662800000001 * fTemp23) + (0.0036296078999999998 * fTemp25)) + (0.0107201437 * fTemp27)) + (0.078853763899999998 * fTemp24))));
			double fTemp458 = (fConst161 * fRec942[1]);
			double fTemp459 = (fConst162 * fRec945[1]);
			fRec947[0] = (fTemp457 + (fTemp458 + (fRec947[1] + fTemp459)));
			fRec945[0] = fRec947[0];
			double fRec946 = ((fTemp459 + fTemp458) + fTemp457);
			fRec944[0] = (fRec945[0] + fRec944[1]);
			fRec942[0] = fRec944[0];
			double fRec943 = fRec946;
			fRec941[0] = (fTemp456 + (fRec943 + fRec941[1]));
			fRec939[0] = fRec941[0];
			double fRec940 = (fRec943 + fTemp456);
			double fTemp460 = (fConst164 * (((0.026849912600000001 * fTemp32) + (0.080783439999999998 * fTemp34)) - (0.038109699300000001 * fTemp33)));
			double fTemp461 = (fConst165 * fRec948[1]);
			fRec950[0] = (fTemp460 + (fRec950[1] + fTemp461));
			fRec948[0] = fRec950[0];
			double fRec949 = (fTemp461 + fTemp460);
			double fTemp462 = (fConst167 * (((0.063454501799999993 * fTemp37) + (0.084898322999999998 * fTemp40)) - (((0.025747456500000002 * fTemp38) + (0.0264804254 * fTemp41)) + (0.077633339100000004 * fTemp39))));
			double fTemp463 = (fConst168 * fRec951[1]);
			double fTemp464 = (fConst169 * fRec954[1]);
			fRec956[0] = (fTemp462 + (fTemp463 + (fRec956[1] + fTemp464)));
			fRec954[0] = fRec956[0];
			double fRec955 = ((fTemp464 + fTemp463) + fTemp462);
			fRec953[0] = (fRec954[0] + fRec953[1]);
			fRec951[0] = fRec953[0];
			double fRec952 = fRec955;
			fVec29[(IOTA & 511)] = ((0.033264708800000001 * fTemp7) + (fRec928 + (fRec940 + (fRec949 + fRec952))));
			output30[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec29[((IOTA - iConst170) & 511)])));
			double fTemp465 = (fConst130 * fRec957[1]);
			double fTemp466 = (fConst131 * fRec960[1]);
			double fTemp467 = (fConst133 * ((((0.0063173565999999999 * fTemp15) + ((0.023924468800000001 * fTemp11) + (0.043833602399999998 * fTemp14))) + (0.1142230754 * fTemp17)) - ((((0.034902777900000001 * fTemp10) + (0.0012863905000000001 * fTemp12)) + (0.0033561749999999999 * fTemp13)) + (0.1031383375 * fTemp16))));
			double fTemp468 = (fConst134 * fRec963[1]);
			double fTemp469 = (fConst135 * fRec966[1]);
			fRec968[0] = (fTemp467 + (fTemp468 + (fRec968[1] + fTemp469)));
			fRec966[0] = fRec968[0];
			double fRec967 = ((fTemp469 + fTemp468) + fTemp467);
			fRec965[0] = (fRec966[0] + fRec965[1]);
			fRec963[0] = fRec965[0];
			double fRec964 = fRec967;
			fRec962[0] = (fTemp465 + (fTemp466 + (fRec964 + fRec962[1])));
			fRec960[0] = fRec962[0];
			double fRec961 = (fTemp465 + (fRec964 + fTemp466));
			fRec959[0] = (fRec960[0] + fRec959[1]);
			fRec957[0] = fRec959[0];
			double fRec958 = fRec961;
			double fTemp470 = (fConst137 * fRec969[1]);
			double fTemp471 = (fConst139 * (((((0.0148861251 * fTemp23) + (0.00072266569999999996 * fTemp25)) + (0.045025074900000003 * fTemp26)) + (0.1137278704 * fTemp28)) - (((0.0257988961 * fTemp22) + (0.011327129 * fTemp27)) + (0.097165509999999997 * fTemp24))));
			double fTemp472 = (fConst140 * fRec972[1]);
			double fTemp473 = (fConst141 * fRec975[1]);
			fRec977[0] = (fTemp471 + (fTemp472 + (fRec977[1] + fTemp473)));
			fRec975[0] = fRec977[0];
			double fRec976 = ((fTemp473 + fTemp472) + fTemp471);
			fRec974[0] = (fRec975[0] + fRec974[1]);
			fRec972[0] = fRec974[0];
			double fRec973 = fRec976;
			fRec971[0] = (fTemp470 + (fRec973 + fRec971[1]));
			fRec969[0] = fRec971[0];
			double fRec970 = (fRec973 + fTemp470);
			double fTemp474 = (fConst143 * ((0.084942507 * fTemp34) - ((0.0063592984000000003 * fTemp32) + (0.0381259428 * fTemp33))));
			double fTemp475 = (fConst144 * fRec978[1]);
			fRec980[0] = (fTemp474 + (fRec980[1] + fTemp475));
			fRec978[0] = fRec980[0];
			double fRec979 = (fTemp475 + fTemp474);
			double fTemp476 = (fConst146 * (((0.0062100437 * fTemp38) + (0.1048784839 * fTemp40)) - (((0.0157546839 * fTemp37) + (0.026477076400000001 * fTemp41)) + (0.081545686199999995 * fTemp39))));
			double fTemp477 = (fConst147 * fRec981[1]);
			double fTemp478 = (fConst148 * fRec984[1]);
			fRec986[0] = (fTemp476 + (fTemp477 + (fRec986[1] + fTemp478)));
			fRec984[0] = fRec986[0];
			double fRec985 = ((fTemp478 + fTemp477) + fTemp476);
			fRec983[0] = (fRec984[0] + fRec983[1]);
			fRec981[0] = fRec983[0];
			double fRec982 = fRec985;
			fVec30[(IOTA & 511)] = ((0.033288954699999998 * fTemp7) + (fRec958 + (fRec970 + (fRec979 + fRec982))));
			output31[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec30[((IOTA - iConst149) & 511)])));
			double fTemp479 = (fConst151 * fRec987[1]);
			double fTemp480 = (fConst152 * fRec990[1]);
			double fTemp481 = (fConst154 * (((0.0037265244999999999 * fTemp15) + ((0.1042477044 * fTemp11) + (0.039366777800000002 * fTemp14))) - ((0.033850113299999998 * fTemp17) + ((((0.1145386578 * fTemp10) + (0.0052075050000000003 * fTemp12)) + (0.019758842499999998 * fTemp13)) + (0.018452355399999999 * fTemp16)))));
			double fTemp482 = (fConst155 * fRec993[1]);
			double fTemp483 = (fConst156 * fRec996[1]);
			fRec998[0] = (fTemp481 + (fTemp482 + (fRec998[1] + fTemp483)));
			fRec996[0] = fRec998[0];
			double fRec997 = ((fTemp483 + fTemp482) + fTemp481);
			fRec995[0] = (fRec996[0] + fRec995[1]);
			fRec993[0] = fRec995[0];
			double fRec994 = fRec997;
			fRec992[0] = (fTemp479 + (fTemp480 + (fRec994 + fRec992[1])));
			fRec990[0] = fRec992[0];
			double fRec991 = (fTemp479 + (fRec994 + fTemp480));
			fRec989[0] = (fRec990[0] + fRec989[1]);
			fRec987[0] = fRec989[0];
			double fRec988 = fRec991;
			double fTemp484 = (fConst158 * fRec999[1]);
			double fTemp485 = (fConst160 * (((((0.078797231100000004 * fTemp23) + (0.0050690268999999998 * fTemp25)) + (0.045098519099999998 * fTemp26)) + (0.0205600427 * fTemp28)) - (((0.1147884329 * fTemp22) + (0.0102268551 * fTemp27)) + (0.058736826300000003 * fTemp24))));
			double fTemp486 = (fConst161 * fRec1002[1]);
			double fTemp487 = (fConst162 * fRec1005[1]);
			fRec1007[0] = (fTemp485 + (fTemp486 + (fRec1007[1] + fTemp487)));
			fRec1005[0] = fRec1007[0];
			double fRec1006 = ((fTemp487 + fTemp486) + fTemp485);
			fRec1004[0] = (fRec1005[0] + fRec1004[1]);
			fRec1002[0] = fRec1004[0];
			double fRec1003 = fRec1006;
			fRec1001[0] = (fTemp484 + (fRec1003 + fRec1001[1]));
			fRec999[0] = fRec1001[0];
			double fRec1000 = (fRec1003 + fTemp484);
			double fTemp488 = (fConst164 * ((0.076140564800000005 * fTemp34) - ((0.0381565154 * fTemp32) + (0.038081240299999999 * fTemp33))));
			double fTemp489 = (fConst165 * fRec1008[1]);
			fRec1010[0] = (fTemp488 + (fRec1010[1] + fTemp489));
			fRec1008[0] = fRec1010[0];
			double fRec1009 = (fTemp489 + fTemp488);
			double fTemp490 = (fConst167 * (((0.0366610224 * fTemp38) + (0.063480344100000002 * fTemp40)) - (((0.084950796300000006 * fTemp37) + (0.0265425548 * fTemp41)) + (0.073062467300000003 * fTemp39))));
			double fTemp491 = (fConst168 * fRec1011[1]);
			double fTemp492 = (fConst169 * fRec1014[1]);
			fRec1016[0] = (fTemp490 + (fTemp491 + (fRec1016[1] + fTemp492)));
			fRec1014[0] = fRec1016[0];
			double fRec1015 = ((fTemp492 + fTemp491) + fTemp490);
			fRec1013[0] = (fRec1014[0] + fRec1013[1]);
			fRec1011[0] = fRec1013[0];
			double fRec1012 = fRec1015;
			fVec31[(IOTA & 511)] = ((0.033273105499999997 * fTemp7) + (fRec988 + (fRec1000 + (fRec1009 + fRec1012))));
			output32[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec31[((IOTA - iConst170) & 511)])));
			double fTemp493 = (fConst130 * fRec1017[1]);
			double fTemp494 = (fConst131 * fRec1020[1]);
			double fTemp495 = (fConst133 * (((((0.035043847500000003 * fTemp10) + (0.056026102899999999 * fTemp11)) + (0.028648525399999999 * fTemp14)) + (0.089895163 * fTemp16)) - ((((0.0064292795000000002 * fTemp12) + (0.033390495899999997 * fTemp13)) + (0.0012416939 * fTemp15)) + (0.1141380072 * fTemp17))));
			double fTemp496 = (fConst134 * fRec1023[1]);
			double fTemp497 = (fConst135 * fRec1026[1]);
			fRec1028[0] = (fTemp495 + (fTemp496 + (fRec1028[1] + fTemp497)));
			fRec1026[0] = fRec1028[0];
			double fRec1027 = ((fTemp497 + fTemp496) + fTemp495);
			fRec1025[0] = (fRec1026[0] + fRec1025[1]);
			fRec1023[0] = fRec1025[0];
			double fRec1024 = fRec1027;
			fRec1022[0] = (fTemp493 + (fTemp494 + (fRec1024 + fRec1022[1])));
			fRec1020[0] = fRec1022[0];
			double fRec1021 = (fTemp493 + (fRec1024 + fTemp494));
			fRec1019[0] = (fRec1020[0] + fRec1019[1]);
			fRec1017[0] = fRec1019[0];
			double fRec1018 = fRec1021;
			double fTemp498 = (fConst137 * fRec1029[1]);
			double fTemp499 = (fConst139 * (((((0.097218402800000006 * fTemp23) + (0.0084727716999999994 * fTemp25)) + (0.045056816100000001 * fTemp26)) + (0.014904769999999999 * fTemp24)) - (((0.062058498400000002 * fTemp22) + (0.0074275551000000002 * fTemp27)) + (0.098685277700000004 * fTemp28))));
			double fTemp500 = (fConst140 * fRec1032[1]);
			double fTemp501 = (fConst141 * fRec1035[1]);
			fRec1037[0] = (fTemp499 + (fTemp500 + (fRec1037[1] + fTemp501)));
			fRec1035[0] = fRec1037[0];
			double fRec1036 = ((fTemp501 + fTemp500) + fTemp499);
			fRec1034[0] = (fRec1035[0] + fRec1034[1]);
			fRec1032[0] = fRec1034[0];
			double fRec1033 = fRec1036;
			fRec1031[0] = (fTemp498 + (fRec1033 + fRec1031[1]));
			fRec1029[0] = fRec1031[0];
			double fRec1030 = (fRec1033 + fTemp498);
			double fTemp502 = (fConst143 * ((0.055534124300000001 * fTemp34) - ((0.064560003800000001 * fTemp32) + (0.038148365599999998 * fTemp33))));
			double fTemp503 = (fConst144 * fRec1038[1]);
			fRec1040[0] = (fTemp502 + (fRec1040[1] + fTemp503));
			fRec1038[0] = fRec1040[0];
			double fRec1039 = (fTemp503 + fTemp502);
			double fTemp504 = (fConst146 * ((0.062092499199999998 * fTemp38) - ((((0.1048360638 * fTemp37) + (0.026436373700000002 * fTemp41)) + (0.053295253299999998 * fTemp39)) + (0.015813225 * fTemp40))));
			double fTemp505 = (fConst147 * fRec1041[1]);
			double fTemp506 = (fConst148 * fRec1044[1]);
			fRec1046[0] = (fTemp504 + (fTemp505 + (fRec1046[1] + fTemp506)));
			fRec1044[0] = fRec1046[0];
			double fRec1045 = ((fTemp506 + fTemp505) + fTemp504);
			fRec1043[0] = (fRec1044[0] + fRec1043[1]);
			fRec1041[0] = fRec1043[0];
			double fRec1042 = fRec1045;
			fVec32[(IOTA & 511)] = ((0.0332842348 * fTemp7) + (fRec1018 + (fRec1030 + (fRec1039 + fRec1042))));
			output33[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec32[((IOTA - iConst149) & 511)])));
			double fTemp507 = (fConst151 * fRec1047[1]);
			double fTemp508 = (fConst152 * fRec1050[1]);
			double fTemp509 = (fConst154 * (((0.033897464600000003 * fTemp17) + (((0.1144869867 * fTemp10) + (0.013863962699999999 * fTemp14)) + (0.086714518700000007 * fTemp16))) - ((((0.060743407399999998 * fTemp11) + (0.0037140712999999999 * fTemp12)) + (0.041807355900000003 * fTemp13)) + (0.0052659958000000002 * fTemp15))));
			double fTemp510 = (fConst155 * fRec1053[1]);
			double fTemp511 = (fConst156 * fRec1056[1]);
			fRec1058[0] = (fTemp509 + (fTemp510 + (fRec1058[1] + fTemp511)));
			fRec1056[0] = fRec1058[0];
			double fRec1057 = ((fTemp511 + fTemp510) + fTemp509);
			fRec1055[0] = (fRec1056[0] + fRec1055[1]);
			fRec1053[0] = fRec1055[0];
			double fRec1054 = fRec1057;
			fRec1052[0] = (fTemp507 + (fTemp508 + (fRec1054 + fRec1052[1])));
			fRec1050[0] = fRec1052[0];
			double fRec1051 = (fTemp507 + (fRec1054 + fTemp508));
			fRec1049[0] = (fRec1050[0] + fRec1049[1]);
			fRec1047[0] = fRec1049[0];
			double fRec1048 = fRec1051;
			double fTemp512 = (fConst158 * fRec1059[1]);
			double fTemp513 = (fConst160 * ((((((0.066656725400000005 * fTemp22) + (0.058691351000000003 * fTemp23)) + (0.0107694785 * fTemp25)) + (0.045080427800000003 * fTemp26)) + (0.078843311299999996 * fTemp24)) - ((0.0036500515999999998 * fTemp27) + (0.095647291300000006 * fTemp28))));
			double fTemp514 = (fConst161 * fRec1062[1]);
			double fTemp515 = (fConst162 * fRec1065[1]);
			fRec1067[0] = (fTemp513 + (fTemp514 + (fRec1067[1] + fTemp515)));
			fRec1065[0] = fRec1067[0];
			double fRec1066 = ((fTemp515 + fTemp514) + fTemp513);
			fRec1064[0] = (fRec1065[0] + fRec1064[1]);
			fRec1062[0] = fRec1064[0];
			double fRec1063 = fRec1066;
			fRec1061[0] = (fTemp512 + (fRec1063 + fRec1061[1]));
			fRec1059[0] = fRec1061[0];
			double fRec1060 = (fRec1063 + fTemp512);
			double fTemp516 = (fConst164 * ((0.026835694399999999 * fTemp34) - ((0.080811546499999998 * fTemp32) + (0.0380982391 * fTemp33))));
			double fTemp517 = (fConst165 * fRec1068[1]);
			fRec1070[0] = (fTemp516 + (fRec1070[1] + fTemp517));
			fRec1068[0] = fRec1070[0];
			double fRec1069 = (fTemp517 + fTemp516);
			double fTemp518 = (fConst167 * ((0.0776089425 * fTemp38) - ((((0.063432372299999998 * fTemp37) + (0.026503915499999999 * fTemp41)) + (0.0257158291 * fTemp39)) + (0.084954703100000001 * fTemp40))));
			double fTemp519 = (fConst168 * fRec1071[1]);
			double fTemp520 = (fConst169 * fRec1074[1]);
			fRec1076[0] = (fTemp518 + (fTemp519 + (fRec1076[1] + fTemp520)));
			fRec1074[0] = fRec1076[0];
			double fRec1075 = ((fTemp520 + fTemp519) + fTemp518);
			fRec1073[0] = (fRec1074[0] + fRec1073[1]);
			fRec1071[0] = fRec1073[0];
			double fRec1072 = fRec1075;
			fVec33[(IOTA & 511)] = ((0.033272114499999998 * fTemp7) + (fRec1048 + (fRec1060 + (fRec1069 + fRec1072))));
			output34[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec33[((IOTA - iConst170) & 511)])));
			double fTemp521 = (fConst130 * fRec1077[1]);
			double fTemp522 = (fConst131 * fRec1080[1]);
			double fTemp523 = (fConst133 * (((0.0012697062000000001 * fTemp12) + (0.1142017021 * fTemp17)) - ((0.023872140600000001 * fTemp16) + (((((0.034883829399999997 * fTemp10) + (0.1031606028 * fTemp11)) + (0.043886616099999998 * fTemp13)) + (0.0033480034000000001 * fTemp14)) + (0.0063737823000000002 * fTemp15)))));
			double fTemp524 = (fConst134 * fRec1083[1]);
			double fTemp525 = (fConst135 * fRec1086[1]);
			fRec1088[0] = (fTemp523 + (fTemp524 + (fRec1088[1] + fTemp525)));
			fRec1086[0] = fRec1088[0];
			double fRec1087 = ((fTemp525 + fTemp524) + fTemp523);
			fRec1085[0] = (fRec1086[0] + fRec1085[1]);
			fRec1083[0] = fRec1085[0];
			double fRec1084 = fRec1087;
			fRec1082[0] = (fTemp521 + (fTemp522 + (fRec1084 + fRec1082[1])));
			fRec1080[0] = fRec1082[0];
			double fRec1081 = (fTemp521 + (fRec1084 + fTemp522));
			fRec1079[0] = (fRec1080[0] + fRec1079[1]);
			fRec1077[0] = fRec1079[0];
			double fRec1078 = fRec1081;
			double fTemp526 = (fConst137 * fRec1089[1]);
			double fTemp527 = (fConst139 * (((0.025776243099999999 * fTemp28) + ((0.097185107199999995 * fTemp24) + ((((0.1137008253 * fTemp22) + (0.011294923700000001 * fTemp25)) + (0.045081476199999998 * fTemp26)) + (0.00072731870000000004 * fTemp27)))) - (0.014852952799999999 * fTemp23)));
			double fTemp528 = (fConst140 * fRec1092[1]);
			double fTemp529 = (fConst141 * fRec1095[1]);
			fRec1097[0] = (fTemp527 + (fTemp528 + (fRec1097[1] + fTemp529)));
			fRec1095[0] = fRec1097[0];
			double fRec1096 = ((fTemp529 + fTemp528) + fTemp527);
			fRec1094[0] = (fRec1095[0] + fRec1094[1]);
			fRec1092[0] = fRec1094[0];
			double fRec1093 = fRec1096;
			fRec1091[0] = (fTemp526 + (fRec1093 + fRec1091[1]));
			fRec1089[0] = fRec1091[0];
			double fRec1090 = (fRec1093 + fTemp526);
			double fTemp530 = (fConst143 * (0.0 - (((0.0849192104 * fTemp32) + (0.0381146708 * fTemp33)) + (0.0063509984000000002 * fTemp34))));
			double fTemp531 = (fConst144 * fRec1098[1]);
			fRec1100[0] = (fTemp530 + (fRec1100[1] + fTemp531));
			fRec1098[0] = fRec1100[0];
			double fRec1099 = (fTemp531 + fTemp530);
			double fTemp532 = (fConst146 * ((((0.015736912499999998 * fTemp37) + (0.081553025599999995 * fTemp38)) + (0.0061961741999999997 * fTemp39)) - ((0.0264817496 * fTemp41) + (0.1048513973 * fTemp40))));
			double fTemp533 = (fConst147 * fRec1101[1]);
			double fTemp534 = (fConst148 * fRec1104[1]);
			fRec1106[0] = (fTemp532 + (fTemp533 + (fRec1106[1] + fTemp534)));
			fRec1104[0] = fRec1106[0];
			double fRec1105 = ((fTemp534 + fTemp533) + fTemp532);
			fRec1103[0] = (fRec1104[0] + fRec1103[1]);
			fRec1101[0] = fRec1103[0];
			double fRec1102 = fRec1105;
			fVec34[(IOTA & 511)] = ((0.033276484600000003 * fTemp7) + (fRec1078 + (fRec1090 + (fRec1099 + fRec1102))));
			output35[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec34[((IOTA - iConst149) & 511)])));
			double fTemp535 = (fConst151 * fRec1107[1]);
			double fTemp536 = (fConst152 * fRec1110[1]);
			double fTemp537 = (fConst154 * ((0.0052216312999999997 * fTemp12) - ((0.0338739947 * fTemp17) + ((0.1042714064 * fTemp16) + (((((0.1145178768 * fTemp10) + (0.018450642699999999 * fTemp11)) + (0.039361826699999998 * fTemp13)) + (0.019766645699999998 * fTemp14)) + (0.0037685707 * fTemp15))))));
			double fTemp538 = (fConst155 * fRec1113[1]);
			double fTemp539 = (fConst156 * fRec1116[1]);
			fRec1118[0] = (fTemp537 + (fTemp538 + (fRec1118[1] + fTemp539)));
			fRec1116[0] = fRec1118[0];
			double fRec1117 = ((fTemp539 + fTemp538) + fTemp537);
			fRec1115[0] = (fRec1116[0] + fRec1115[1]);
			fRec1113[0] = fRec1115[0];
			double fRec1114 = fRec1117;
			fRec1112[0] = (fTemp535 + (fTemp536 + (fRec1114 + fRec1112[1])));
			fRec1110[0] = fRec1112[0];
			double fRec1111 = (fTemp535 + (fRec1114 + fTemp536));
			fRec1109[0] = (fRec1110[0] + fRec1109[1]);
			fRec1107[0] = fRec1109[0];
			double fRec1108 = fRec1111;
			double fTemp540 = (fConst158 * fRec1119[1]);
			double fTemp541 = (fConst160 * (((0.11477953809999999 * fTemp28) + ((0.058753453300000001 * fTemp24) + ((((0.0205387338 * fTemp22) + (0.010182545499999999 * fTemp25)) + (0.0450816551 * fTemp26)) + (0.0050588908000000002 * fTemp27)))) - (0.078819765700000002 * fTemp23)));
			double fTemp542 = (fConst161 * fRec1122[1]);
			double fTemp543 = (fConst162 * fRec1125[1]);
			fRec1127[0] = (fTemp541 + (fTemp542 + (fRec1127[1] + fTemp543)));
			fRec1125[0] = fRec1127[0];
			double fRec1126 = ((fTemp543 + fTemp542) + fTemp541);
			fRec1124[0] = (fRec1125[0] + fRec1124[1]);
			fRec1122[0] = fRec1124[0];
			double fRec1123 = fRec1126;
			fRec1121[0] = (fTemp540 + (fRec1123 + fRec1121[1]));
			fRec1119[0] = fRec1121[0];
			double fRec1120 = (fRec1123 + fTemp540);
			double fTemp544 = (fConst164 * (0.0 - (((0.076137318100000004 * fTemp32) + (0.0381082248 * fTemp33)) + (0.038158428899999999 * fTemp34))));
			double fTemp545 = (fConst165 * fRec1128[1]);
			fRec1130[0] = (fTemp544 + (fRec1130[1] + fTemp545));
			fRec1128[0] = fRec1130[0];
			double fRec1129 = (fTemp545 + fTemp544);
			double fTemp546 = (fConst167 * ((((0.084949829399999996 * fTemp37) + (0.073090824900000004 * fTemp38)) + (0.036674009200000003 * fTemp39)) - ((0.026502758899999999 * fTemp41) + (0.063467089099999999 * fTemp40))));
			double fTemp547 = (fConst168 * fRec1131[1]);
			double fTemp548 = (fConst169 * fRec1134[1]);
			fRec1136[0] = (fTemp546 + (fTemp547 + (fRec1136[1] + fTemp548)));
			fRec1134[0] = fRec1136[0];
			double fRec1135 = ((fTemp548 + fTemp547) + fTemp546);
			fRec1133[0] = (fRec1134[0] + fRec1133[1]);
			fRec1131[0] = fRec1133[0];
			double fRec1132 = fRec1135;
			fVec35[(IOTA & 511)] = ((0.033278067699999997 * fTemp7) + (fRec1108 + (fRec1120 + (fRec1129 + fRec1132))));
			output36[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec35[((IOTA - iConst170) & 511)])));
			double fTemp549 = (fConst130 * fRec1137[1]);
			double fTemp550 = (fConst131 * fRec1140[1]);
			double fTemp551 = (fConst133 * (((((0.034963300500000002 * fTemp10) + (0.089837350799999993 * fTemp11)) + (0.0063732414999999997 * fTemp12)) + (0.0012383120999999999 * fTemp15)) - ((0.114204951 * fTemp17) + (((0.0286306445 * fTemp13) + (0.033378283699999997 * fTemp14)) + (0.056046316999999998 * fTemp16)))));
			double fTemp552 = (fConst134 * fRec1143[1]);
			double fTemp553 = (fConst135 * fRec1146[1]);
			fRec1148[0] = (fTemp551 + (fTemp552 + (fRec1148[1] + fTemp553)));
			fRec1146[0] = fRec1148[0];
			double fRec1147 = ((fTemp553 + fTemp552) + fTemp551);
			fRec1145[0] = (fRec1146[0] + fRec1145[1]);
			fRec1143[0] = fRec1145[0];
			double fRec1144 = fRec1147;
			fRec1142[0] = (fTemp549 + (fTemp550 + (fRec1144 + fRec1142[1])));
			fRec1140[0] = fRec1142[0];
			double fRec1141 = (fTemp549 + (fRec1144 + fTemp550));
			fRec1139[0] = (fRec1140[0] + fRec1139[1]);
			fRec1137[0] = fRec1139[0];
			double fRec1138 = fRec1141;
			double fTemp554 = (fConst137 * fRec1149[1]);
			double fTemp555 = (fConst139 * (((((0.0074615742000000004 * fTemp25) + (0.045040590800000002 * fTemp26)) + (0.0085114636999999993 * fTemp27)) + (0.062137674699999999 * fTemp28)) - (((0.098670418100000004 * fTemp22) + (0.097180163299999997 * fTemp23)) + (0.014864069800000001 * fTemp24))));
			double fTemp556 = (fConst140 * fRec1152[1]);
			double fTemp557 = (fConst141 * fRec1155[1]);
			fRec1157[0] = (fTemp555 + (fTemp556 + (fRec1157[1] + fTemp557)));
			fRec1155[0] = fRec1157[0];
			double fRec1156 = ((fTemp557 + fTemp556) + fTemp555);
			fRec1154[0] = (fRec1155[0] + fRec1154[1]);
			fRec1152[0] = fRec1154[0];
			double fRec1153 = fRec1156;
			fRec1151[0] = (fTemp554 + (fRec1153 + fRec1151[1]));
			fRec1149[0] = fRec1151[0];
			double fRec1150 = (fRec1153 + fTemp554);
			double fTemp558 = (fConst143 * (0.0 - (((0.055553733899999999 * fTemp32) + (0.038125752300000003 * fTemp33)) + (0.064552007999999994 * fTemp34))));
			double fTemp559 = (fConst144 * fRec1158[1]);
			fRec1160[0] = (fTemp558 + (fRec1160[1] + fTemp559));
			fRec1158[0] = fRec1160[0];
			double fRec1159 = (fTemp559 + fTemp558);
			double fTemp560 = (fConst146 * (((((0.1048604267 * fTemp37) + (0.0532821084 * fTemp38)) + (0.062049975399999999 * fTemp39)) + (0.015769035099999999 * fTemp40)) - (0.026465696600000001 * fTemp41)));
			double fTemp561 = (fConst147 * fRec1161[1]);
			double fTemp562 = (fConst148 * fRec1164[1]);
			fRec1166[0] = (fTemp560 + (fTemp561 + (fRec1166[1] + fTemp562)));
			fRec1164[0] = fRec1166[0];
			double fRec1165 = ((fTemp562 + fTemp561) + fTemp560);
			fRec1163[0] = (fRec1164[0] + fRec1163[1]);
			fRec1161[0] = fRec1163[0];
			double fRec1162 = fRec1165;
			fVec36[(IOTA & 511)] = ((0.033283175399999997 * fTemp7) + (fRec1138 + (fRec1150 + (fRec1159 + fRec1162))));
			output37[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec36[((IOTA - iConst149) & 511)])));
			double fTemp563 = (fConst151 * fRec1167[1]);
			double fTemp564 = (fConst152 * fRec1170[1]);
			double fTemp565 = (fConst154 * (((0.033852430099999997 * fTemp17) + ((0.060739800199999999 * fTemp16) + ((((0.11446973990000001 * fTemp10) + (0.086762481799999999 * fTemp11)) + (0.0037495468000000001 * fTemp12)) + (0.0053231116000000004 * fTemp15)))) - ((0.0138807103 * fTemp13) + (0.041821141300000003 * fTemp14))));
			double fTemp566 = (fConst155 * fRec1173[1]);
			double fTemp567 = (fConst156 * fRec1176[1]);
			fRec1178[0] = (fTemp565 + (fTemp566 + (fRec1178[1] + fTemp567)));
			fRec1176[0] = fRec1178[0];
			double fRec1177 = ((fTemp567 + fTemp566) + fTemp565);
			fRec1175[0] = (fRec1176[0] + fRec1175[1]);
			fRec1173[0] = fRec1175[0];
			double fRec1174 = fRec1177;
			fRec1172[0] = (fTemp563 + (fTemp564 + (fRec1174 + fRec1172[1])));
			fRec1170[0] = fRec1172[0];
			double fRec1171 = (fTemp563 + (fRec1174 + fTemp564));
			fRec1169[0] = (fRec1170[0] + fRec1169[1]);
			fRec1167[0] = fRec1169[0];
			double fRec1168 = fRec1171;
			double fTemp568 = (fConst158 * fRec1179[1]);
			double fTemp569 = (fConst160 * ((((0.0036356788000000001 * fTemp25) + (0.045101522499999998 * fTemp26)) + (0.010711261600000001 * fTemp27)) - ((0.066610599300000004 * fTemp28) + (((0.095632831200000004 * fTemp22) + (0.058725648499999998 * fTemp23)) + (0.078858663800000006 * fTemp24)))));
			double fTemp570 = (fConst161 * fRec1182[1]);
			double fTemp571 = (fConst162 * fRec1185[1]);
			fRec1187[0] = (fTemp569 + (fTemp570 + (fRec1187[1] + fTemp571)));
			fRec1185[0] = fRec1187[0];
			double fRec1186 = ((fTemp571 + fTemp570) + fTemp569);
			fRec1184[0] = (fRec1185[0] + fRec1184[1]);
			fRec1182[0] = fRec1184[0];
			double fRec1183 = fRec1186;
			fRec1181[0] = (fTemp568 + (fRec1183 + fRec1181[1]));
			fRec1179[0] = fRec1181[0];
			double fRec1180 = (fRec1183 + fTemp568);
			double fTemp572 = (fConst164 * (0.0 - (((0.026833309999999999 * fTemp32) + (0.038106907000000002 * fTemp33)) + (0.080781548600000003 * fTemp34))));
			double fTemp573 = (fConst165 * fRec1188[1]);
			fRec1190[0] = (fTemp572 + (fRec1190[1] + fTemp573));
			fRec1188[0] = fRec1190[0];
			double fRec1189 = (fTemp573 + fTemp572);
			double fTemp574 = (fConst167 * (((((0.063424460899999993 * fTemp37) + (0.025729977300000002 * fTemp38)) + (0.077630167700000002 * fTemp39)) + (0.084913400999999999 * fTemp40)) - (0.0264737523 * fTemp41)));
			double fTemp575 = (fConst168 * fRec1191[1]);
			double fTemp576 = (fConst169 * fRec1194[1]);
			fRec1196[0] = (fTemp574 + (fTemp575 + (fRec1196[1] + fTemp576)));
			fRec1194[0] = fRec1196[0];
			double fRec1195 = ((fTemp576 + fTemp575) + fTemp574);
			fRec1193[0] = (fRec1194[0] + fRec1193[1]);
			fRec1191[0] = fRec1193[0];
			double fRec1192 = fRec1195;
			fVec37[(IOTA & 511)] = ((0.033262025000000001 * fTemp7) + (fRec1168 + (fRec1180 + (fRec1189 + fRec1192))));
			output38[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec37[((IOTA - iConst170) & 511)])));
			double fTemp577 = (fConst130 * fRec1197[1]);
			double fTemp578 = (fConst131 * fRec1200[1]);
			double fTemp579 = (fConst133 * (((0.11421576949999999 * fTemp17) + ((0.1031277446 * fTemp16) + ((0.0033561705000000001 * fTemp13) + (0.0062842743 * fTemp15)))) - ((((0.034976159299999997 * fTemp10) + (0.0239379552 * fTemp11)) + (0.0012555685 * fTemp12)) + (0.043866424299999998 * fTemp14))));
			double fTemp580 = (fConst134 * fRec1203[1]);
			double fTemp581 = (fConst135 * fRec1206[1]);
			fRec1208[0] = (fTemp579 + (fTemp580 + (fRec1208[1] + fTemp581)));
			fRec1206[0] = fRec1208[0];
			double fRec1207 = ((fTemp581 + fTemp580) + fTemp579);
			fRec1205[0] = (fRec1206[0] + fRec1205[1]);
			fRec1203[0] = fRec1205[0];
			double fRec1204 = fRec1207;
			fRec1202[0] = (fTemp577 + (fTemp578 + (fRec1204 + fRec1202[1])));
			fRec1200[0] = fRec1202[0];
			double fRec1201 = (fTemp577 + (fRec1204 + fTemp578));
			fRec1199[0] = (fRec1200[0] + fRec1199[1]);
			fRec1197[0] = fRec1199[0];
			double fRec1198 = fRec1201;
			double fTemp582 = (fConst137 * fRec1209[1]);
			double fTemp583 = (fConst139 * (((((0.025854279399999999 * fTemp22) + (0.0148955627 * fTemp23)) + (0.045049513100000001 * fTemp26)) + (0.0113706473 * fTemp27)) - ((0.11373347 * fTemp28) + ((0.00073515950000000005 * fTemp25) + (0.097154645900000003 * fTemp24)))));
			double fTemp584 = (fConst140 * fRec1212[1]);
			double fTemp585 = (fConst141 * fRec1215[1]);
			fRec1217[0] = (fTemp583 + (fTemp584 + (fRec1217[1] + fTemp585)));
			fRec1215[0] = fRec1217[0];
			double fRec1216 = ((fTemp585 + fTemp584) + fTemp583);
			fRec1214[0] = (fRec1215[0] + fRec1214[1]);
			fRec1212[0] = fRec1214[0];
			double fRec1213 = fRec1216;
			fRec1211[0] = (fTemp582 + (fRec1213 + fRec1211[1]));
			fRec1209[0] = fRec1211[0];
			double fRec1210 = (fRec1213 + fTemp582);
			double fTemp586 = (fConst143 * ((0.0063723464999999998 * fTemp32) - ((0.038111018900000002 * fTemp33) + (0.084951557600000005 * fTemp34))));
			double fTemp587 = (fConst144 * fRec1218[1]);
			fRec1220[0] = (fTemp586 + (fRec1220[1] + fTemp587));
			fRec1218[0] = fRec1220[0];
			double fRec1219 = (fTemp587 + fTemp586);
			double fTemp588 = (fConst146 * (((0.081531368000000007 * fTemp39) + (0.1048899032 * fTemp40)) - (((0.015788099199999999 * fTemp37) + (0.0062148454000000002 * fTemp38)) + (0.026511586 * fTemp41))));
			double fTemp589 = (fConst147 * fRec1221[1]);
			double fTemp590 = (fConst148 * fRec1224[1]);
			fRec1226[0] = (fTemp588 + (fTemp589 + (fRec1226[1] + fTemp590)));
			fRec1224[0] = fRec1226[0];
			double fRec1225 = ((fTemp590 + fTemp589) + fTemp588);
			fRec1223[0] = (fRec1224[0] + fRec1223[1]);
			fRec1221[0] = fRec1223[0];
			double fRec1222 = fRec1225;
			fVec38[(IOTA & 511)] = ((0.033288936200000001 * fTemp7) + (fRec1198 + (fRec1210 + (fRec1219 + fRec1222))));
			output39[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec38[((IOTA - iConst149) & 511)])));
			double fTemp591 = (fConst151 * fRec1227[1]);
			double fTemp592 = (fConst152 * fRec1230[1]);
			double fTemp593 = (fConst154 * (((0.018425521800000001 * fTemp16) + ((0.0197700858 * fTemp13) + (0.0037344672000000001 * fTemp15))) - (((((0.11453679059999999 * fTemp10) + (0.1042617341 * fTemp11)) + (0.0052292166999999999 * fTemp12)) + (0.039355786099999998 * fTemp14)) + (0.03384649 * fTemp17))));
			double fTemp594 = (fConst155 * fRec1233[1]);
			double fTemp595 = (fConst156 * fRec1236[1]);
			fRec1238[0] = (fTemp593 + (fTemp594 + (fRec1238[1] + fTemp595)));
			fRec1236[0] = fRec1238[0];
			double fRec1237 = ((fTemp595 + fTemp594) + fTemp593);
			fRec1235[0] = (fRec1236[0] + fRec1235[1]);
			fRec1233[0] = fRec1235[0];
			double fRec1234 = fRec1237;
			fRec1232[0] = (fTemp591 + (fTemp592 + (fRec1234 + fRec1232[1])));
			fRec1230[0] = fRec1232[0];
			double fRec1231 = (fTemp591 + (fRec1234 + fTemp592));
			fRec1229[0] = (fRec1230[0] + fRec1229[1]);
			fRec1227[0] = fRec1229[0];
			double fRec1228 = fRec1231;
			double fTemp596 = (fConst158 * fRec1239[1]);
			double fTemp597 = (fConst160 * (((((0.11478250199999999 * fTemp22) + (0.078816080199999999 * fTemp23)) + (0.045085587000000003 * fTemp26)) + (0.010204327900000001 * fTemp27)) - ((0.020558122099999999 * fTemp28) + ((0.0050579153000000002 * fTemp25) + (0.0587313785 * fTemp24)))));
			double fTemp598 = (fConst161 * fRec1242[1]);
			double fTemp599 = (fConst162 * fRec1245[1]);
			fRec1247[0] = (fTemp597 + (fTemp598 + (fRec1247[1] + fTemp599)));
			fRec1245[0] = fRec1247[0];
			double fRec1246 = ((fTemp599 + fTemp598) + fTemp597);
			fRec1244[0] = (fRec1245[0] + fRec1244[1]);
			fRec1242[0] = fRec1244[0];
			double fRec1243 = fRec1246;
			fRec1241[0] = (fTemp596 + (fRec1243 + fRec1241[1]));
			fRec1239[0] = fRec1241[0];
			double fRec1240 = (fRec1243 + fTemp596);
			double fTemp600 = (fConst164 * ((0.0381559624 * fTemp32) - ((0.038096090800000003 * fTemp33) + (0.076137778700000006 * fTemp34))));
			double fTemp601 = (fConst165 * fRec1248[1]);
			fRec1250[0] = (fTemp600 + (fRec1250[1] + fTemp601));
			fRec1248[0] = fRec1250[0];
			double fRec1249 = (fTemp601 + fTemp600);
			double fTemp602 = (fConst167 * (((0.073072578400000004 * fTemp39) + (0.063475489100000004 * fTemp40)) - (((0.084947170000000002 * fTemp37) + (0.036671386100000002 * fTemp38)) + (0.026518126900000001 * fTemp41))));
			double fTemp603 = (fConst168 * fRec1251[1]);
			double fTemp604 = (fConst169 * fRec1254[1]);
			fRec1256[0] = (fTemp602 + (fTemp603 + (fRec1256[1] + fTemp604)));
			fRec1254[0] = fRec1256[0];
			double fRec1255 = ((fTemp604 + fTemp603) + fTemp602);
			fRec1253[0] = (fRec1254[0] + fRec1253[1]);
			fRec1251[0] = fRec1253[0];
			double fRec1252 = fRec1255;
			fVec39[(IOTA & 511)] = ((0.0332756908 * fTemp7) + (fRec1228 + (fRec1240 + (fRec1249 + fRec1252))));
			output40[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec39[((IOTA - iConst170) & 511)])));
			double fTemp605 = (fConst130 * fRec1257[1]);
			double fTemp606 = (fConst131 * fRec1260[1]);
			double fTemp607 = (fConst133 * (((0.034996013399999998 * fTemp10) + (0.033408524000000002 * fTemp13)) - ((0.1142063656 * fTemp17) + ((0.089858008099999997 * fTemp16) + ((((0.056028558700000002 * fTemp11) + (0.0063210534999999998 * fTemp12)) + (0.028631855899999999 * fTemp14)) + (0.0012163095 * fTemp15))))));
			double fTemp608 = (fConst134 * fRec1263[1]);
			double fTemp609 = (fConst135 * fRec1266[1]);
			fRec1268[0] = (fTemp607 + (fTemp608 + (fRec1268[1] + fTemp609)));
			fRec1266[0] = fRec1268[0];
			double fRec1267 = ((fTemp609 + fTemp608) + fTemp607);
			fRec1265[0] = (fRec1266[0] + fRec1265[1]);
			fRec1263[0] = fRec1265[0];
			double fRec1264 = fRec1267;
			fRec1262[0] = (fTemp605 + (fTemp606 + (fRec1264 + fRec1262[1])));
			fRec1260[0] = fRec1262[0];
			double fRec1261 = (fTemp605 + (fRec1264 + fTemp606));
			fRec1259[0] = (fRec1260[0] + fRec1259[1]);
			fRec1257[0] = fRec1259[0];
			double fRec1258 = fRec1261;
			double fTemp610 = (fConst137 * fRec1269[1]);
			double fTemp611 = (fConst139 * (((0.098711720500000003 * fTemp28) + ((0.014878353299999999 * fTemp24) + ((((0.062135463100000003 * fTemp22) + (0.097186882500000002 * fTemp23)) + (0.045057921299999998 * fTemp26)) + (0.0074884495000000001 * fTemp27)))) - (0.0085588732000000008 * fTemp25)));
			double fTemp612 = (fConst140 * fRec1272[1]);
			double fTemp613 = (fConst141 * fRec1275[1]);
			fRec1277[0] = (fTemp611 + (fTemp612 + (fRec1277[1] + fTemp613)));
			fRec1275[0] = fRec1277[0];
			double fRec1276 = ((fTemp613 + fTemp612) + fTemp611);
			fRec1274[0] = (fRec1275[0] + fRec1274[1]);
			fRec1272[0] = fRec1274[0];
			double fRec1273 = fRec1276;
			fRec1271[0] = (fTemp610 + (fRec1273 + fRec1271[1]));
			fRec1269[0] = fRec1271[0];
			double fRec1270 = (fRec1273 + fTemp610);
			double fTemp614 = (fConst143 * ((0.064583163400000004 * fTemp32) - ((0.038125736 * fTemp33) + (0.055574241699999999 * fTemp34))));
			double fTemp615 = (fConst144 * fRec1278[1]);
			fRec1280[0] = (fTemp614 + (fRec1280[1] + fTemp615));
			fRec1278[0] = fRec1280[0];
			double fRec1279 = (fTemp615 + fTemp614);
			double fTemp616 = (fConst146 * ((0.053285021299999999 * fTemp39) - ((((0.10490024589999999 * fTemp37) + (0.062057665400000003 * fTemp38)) + (0.0265034338 * fTemp41)) + (0.0157893063 * fTemp40))));
			double fTemp617 = (fConst147 * fRec1281[1]);
			double fTemp618 = (fConst148 * fRec1284[1]);
			fRec1286[0] = (fTemp616 + (fTemp617 + (fRec1286[1] + fTemp618)));
			fRec1284[0] = fRec1286[0];
			double fRec1285 = ((fTemp618 + fTemp617) + fTemp616);
			fRec1283[0] = (fRec1284[0] + fRec1283[1]);
			fRec1281[0] = fRec1283[0];
			double fRec1282 = fRec1285;
			fVec40[(IOTA & 511)] = ((0.033295417100000002 * fTemp7) + (fRec1258 + (fRec1270 + (fRec1279 + fRec1282))));
			output41[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec40[((IOTA - iConst149) & 511)])));
			double fTemp619 = (fConst151 * fRec1287[1]);
			double fTemp620 = (fConst152 * fRec1290[1]);
			double fTemp621 = (fConst154 * (((((0.1144481352 * fTemp10) + (0.060735275300000002 * fTemp11)) + (0.041848904200000002 * fTemp13)) + (0.033819984900000002 * fTemp17)) - ((0.086782093800000001 * fTemp16) + (((0.0037694781999999998 * fTemp12) + (0.0138627157 * fTemp14)) + (0.0053293350999999997 * fTemp15)))));
			double fTemp622 = (fConst155 * fRec1293[1]);
			double fTemp623 = (fConst156 * fRec1296[1]);
			fRec1298[0] = (fTemp621 + (fTemp622 + (fRec1298[1] + fTemp623)));
			fRec1296[0] = fRec1298[0];
			double fRec1297 = ((fTemp623 + fTemp622) + fTemp621);
			fRec1295[0] = (fRec1296[0] + fRec1295[1]);
			fRec1293[0] = fRec1295[0];
			double fRec1294 = fRec1297;
			fRec1292[0] = (fTemp619 + (fTemp620 + (fRec1294 + fRec1292[1])));
			fRec1290[0] = fRec1292[0];
			double fRec1291 = (fTemp619 + (fRec1294 + fTemp620));
			fRec1289[0] = (fRec1290[0] + fRec1289[1]);
			fRec1287[0] = fRec1289[0];
			double fRec1288 = fRec1291;
			double fTemp624 = (fConst158 * fRec1299[1]);
			double fTemp625 = (fConst160 * (((0.095629328 * fTemp28) + ((0.078858903300000005 * fTemp24) + (((0.058746469900000001 * fTemp23) + (0.045119389099999997 * fTemp26)) + (0.0036205429999999999 * fTemp27)))) - ((0.066581291599999995 * fTemp22) + (0.010707793300000001 * fTemp25))));
			double fTemp626 = (fConst161 * fRec1302[1]);
			double fTemp627 = (fConst162 * fRec1305[1]);
			fRec1307[0] = (fTemp625 + (fTemp626 + (fRec1307[1] + fTemp627)));
			fRec1305[0] = fRec1307[0];
			double fRec1306 = ((fTemp627 + fTemp626) + fTemp625);
			fRec1304[0] = (fRec1305[0] + fRec1304[1]);
			fRec1302[0] = fRec1304[0];
			double fRec1303 = fRec1306;
			fRec1301[0] = (fTemp624 + (fRec1303 + fRec1301[1]));
			fRec1299[0] = fRec1301[0];
			double fRec1300 = (fRec1303 + fTemp624);
			double fTemp628 = (fConst164 * ((0.080772432899999996 * fTemp32) - ((0.038106424999999999 * fTemp33) + (0.026839500700000001 * fTemp34))));
			double fTemp629 = (fConst165 * fRec1308[1]);
			fRec1310[0] = (fTemp628 + (fRec1310[1] + fTemp629));
			fRec1308[0] = fRec1310[0];
			double fRec1309 = (fTemp629 + fTemp628);
			double fTemp630 = (fConst167 * ((0.0257443272 * fTemp39) - ((((0.0634306377 * fTemp37) + (0.077633322199999993 * fTemp38)) + (0.026474699399999999 * fTemp41)) + (0.084894441400000006 * fTemp40))));
			double fTemp631 = (fConst168 * fRec1311[1]);
			double fTemp632 = (fConst169 * fRec1314[1]);
			fRec1316[0] = (fTemp630 + (fTemp631 + (fRec1316[1] + fTemp632)));
			fRec1314[0] = fRec1316[0];
			double fRec1315 = ((fTemp632 + fTemp631) + fTemp630);
			fRec1313[0] = (fRec1314[0] + fRec1313[1]);
			fRec1311[0] = fRec1313[0];
			double fRec1312 = fRec1315;
			fVec41[(IOTA & 511)] = ((0.0332589062 * fTemp7) + (fRec1288 + (fRec1300 + (fRec1309 + fRec1312))));
			output42[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec41[((IOTA - iConst170) & 511)])));
			double fTemp633 = (fConst130 * fRec1317[1]);
			double fTemp634 = (fConst131 * fRec1320[1]);
			double fTemp635 = (fConst133 * (((0.11418412460000001 * fTemp17) + (((((0.103164592 * fTemp11) + (0.0012909985 * fTemp12)) + (0.043861270399999999 * fTemp13)) + (0.0033457879000000001 * fTemp14)) + (0.0239328306 * fTemp16))) - ((0.034890412099999997 * fTemp10) + (0.0063689417999999998 * fTemp15))));
			double fTemp636 = (fConst134 * fRec1323[1]);
			double fTemp637 = (fConst135 * fRec1326[1]);
			fRec1328[0] = (fTemp635 + (fTemp636 + (fRec1328[1] + fTemp637)));
			fRec1326[0] = fRec1328[0];
			double fRec1327 = ((fTemp637 + fTemp636) + fTemp635);
			fRec1325[0] = (fRec1326[0] + fRec1325[1]);
			fRec1323[0] = fRec1325[0];
			double fRec1324 = fRec1327;
			fRec1322[0] = (fTemp633 + (fTemp634 + (fRec1324 + fRec1322[1])));
			fRec1320[0] = fRec1322[0];
			double fRec1321 = (fTemp633 + (fRec1324 + fTemp634));
			fRec1319[0] = (fRec1320[0] + fRec1319[1]);
			fRec1317[0] = fRec1319[0];
			double fRec1318 = fRec1321;
			double fTemp638 = (fConst137 * fRec1329[1]);
			double fTemp639 = (fConst139 * (((0.045046237599999997 * fTemp26) + (0.097195331699999998 * fTemp24)) - (((((0.1136994328 * fTemp22) + (0.0148935161 * fTemp23)) + (0.011291667199999999 * fTemp25)) + (0.00071408759999999996 * fTemp27)) + (0.0257925406 * fTemp28))));
			double fTemp640 = (fConst140 * fRec1332[1]);
			double fTemp641 = (fConst141 * fRec1335[1]);
			fRec1337[0] = (fTemp639 + (fTemp640 + (fRec1337[1] + fTemp641)));
			fRec1335[0] = fRec1337[0];
			double fRec1336 = ((fTemp641 + fTemp640) + fTemp639);
			fRec1334[0] = (fRec1335[0] + fRec1334[1]);
			fRec1332[0] = fRec1334[0];
			double fRec1333 = fRec1336;
			fRec1331[0] = (fTemp638 + (fRec1333 + fRec1331[1]));
			fRec1329[0] = fRec1331[0];
			double fRec1330 = (fRec1333 + fTemp638);
			double fTemp642 = (fConst143 * (((0.084932691599999999 * fTemp32) + (0.0063599618000000002 * fTemp34)) - (0.038136089200000001 * fTemp33)));
			double fTemp643 = (fConst144 * fRec1338[1]);
			fRec1340[0] = (fTemp642 + (fRec1340[1] + fTemp643));
			fRec1338[0] = fRec1340[0];
			double fRec1339 = (fTemp643 + fTemp642);
			double fTemp644 = (fConst146 * ((0.0157526739 * fTemp37) - ((((0.081569276600000004 * fTemp38) + (0.026461297700000001 * fTemp41)) + (0.0062161797000000003 * fTemp39)) + (0.1048605755 * fTemp40))));
			double fTemp645 = (fConst147 * fRec1341[1]);
			double fTemp646 = (fConst148 * fRec1344[1]);
			fRec1346[0] = (fTemp644 + (fTemp645 + (fRec1346[1] + fTemp646)));
			fRec1344[0] = fRec1346[0];
			double fRec1345 = ((fTemp646 + fTemp645) + fTemp644);
			fRec1343[0] = (fRec1344[0] + fRec1343[1]);
			fRec1341[0] = fRec1343[0];
			double fRec1342 = fRec1345;
			fVec42[(IOTA & 511)] = ((0.033286693800000003 * fTemp7) + (fRec1318 + (fRec1330 + (fRec1339 + fRec1342))));
			output43[i] = FAUSTFLOAT((0.87640449438202239 * (fRec0[0] * fVec42[((IOTA - iConst149) & 511)])));
			double fTemp647 = (fConst151 * fRec1347[1]);
			double fTemp648 = (fConst152 * fRec1350[1]);
			double fTemp649 = (fConst154 * ((((((0.018404886400000001 * fTemp11) + (0.0052370094999999997 * fTemp12)) + (0.0393619568 * fTemp13)) + (0.019749163300000001 * fTemp14)) + (0.1042655446 * fTemp16)) - (((0.1145611803 * fTemp10) + (0.0037124749999999998 * fTemp15)) + (0.0338621952 * fTemp17))));
			double fTemp650 = (fConst155 * fRec1353[1]);
			double fTemp651 = (fConst156 * fRec1356[1]);
			fRec1358[0] = (fTemp649 + (fTemp650 + (fRec1358[1] + fTemp651)));
			fRec1356[0] = fRec1358[0];
			double fRec1357 = ((fTemp651 + fTemp650) + fTemp649);
			fRec1355[0] = (fRec1356[0] + fRec1355[1]);
			fRec1353[0] = fRec1355[0];
			double fRec1354 = fRec1357;
			fRec1352[0] = (fTemp647 + (fTemp648 + (fRec1354 + fRec1352[1])));
			fRec1350[0] = fRec1352[0];
			double fRec1351 = (fTemp647 + (fRec1354 + fTemp648));
			fRec1349[0] = (fRec1350[0] + fRec1349[1]);
			fRec1347[0] = fRec1349[0];
			double fRec1348 = fRec1351;
			double fTemp652 = (fConst158 * fRec1359[1]);
			double fTemp653 = (fConst160 * (((0.045087633299999999 * fTemp26) + (0.058720090199999998 * fTemp24)) - (((((0.020554094700000001 * fTemp22) + (0.078833772999999996 * fTemp23)) + (0.010219548300000001 * fTemp25)) + (0.0050463616000000003 * fTemp27)) + (0.11481363529999999 * fTemp28))));
			double fTemp654 = (fConst161 * fRec1362[1]);
			double fTemp655 = (fConst162 * fRec1365[1]);
			fRec1367[0] = (fTemp653 + (fTemp654 + (fRec1367[1] + fTemp655)));
			fRec1365[0] = fRec1367[0];
			double fRec1366 = ((fTemp655 + fTemp654) + fTemp653);
			fRec1364[0] = (fRec1365[0] + fRec1364[1]);
			fRec1362[0] = fRec1364[0];
			double fRec1363 = fRec1366;
			fRec1361[0] = (fTemp652 + (fRec1363 + fRec1361[1]));
			fRec1359[0] = fRec1361[0];
			double fRec1360 = (fRec1363 + fTemp652);
			double fTemp656 = (fConst164 * (((0.076156538300000007 * fTemp32) + (0.038172035700000002 * fTemp34)) - (0.038101486499999997 * fTemp33)));
			double fTemp657 = (fConst165 * fRec1368[1]);
			fRec1370[0] = (fTemp656 + (fRec1370[1] + fTemp657));
			fRec1368[0] = fRec1370[0];
			double fRec1369 = (fTemp657 + fTemp656);
			double fTemp658 = (fConst167 * ((0.084975672099999996 * fTemp37) - ((((0.073075973599999997 * fTemp38) + (0.026528459000000001 * fTemp41)) + (0.036688060199999997 * fTemp39)) + (0.063485609600000006 * fTemp40))));
			double fTemp659 = (fConst168 * fRec1371[1]);
			double fTemp660 = (fConst169 * fRec1374[1]);
			fRec1376[0] = (fTemp658 + (fTemp659 + (fRec1376[1] + fTemp660)));
			fRec1374[0] = fRec1376[0];
			double fRec1375 = ((fTemp660 + fTemp659) + fTemp658);
			fRec1373[0] = (fRec1374[0] + fRec1373[1]);
			fRec1371[0] = fRec1373[0];
			double fRec1372 = fRec1375;
			fVec43[(IOTA & 511)] = ((0.033284755200000002 * fTemp7) + (fRec1348 + (fRec1360 + (fRec1369 + fRec1372))));
			output44[i] = FAUSTFLOAT((0.87453183520599254 * (fRec0[0] * fVec43[((IOTA - iConst170) & 511)])));
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec17[2] = fRec17[1];
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
			fRec15[1] = fRec15[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
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
			fRec32[1] = fRec32[0];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec24[1] = fRec24[0];
			fRec43[2] = fRec43[1];
			fRec43[1] = fRec43[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec42[1] = fRec42[0];
			fRec40[1] = fRec40[0];
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
			fRec51[1] = fRec51[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec46[1] = fRec46[0];
			IOTA = (IOTA + 1);
			fRec68[1] = fRec68[0];
			fRec66[1] = fRec66[0];
			fRec65[1] = fRec65[0];
			fRec63[1] = fRec63[0];
			fRec62[1] = fRec62[0];
			fRec60[1] = fRec60[0];
			fRec59[1] = fRec59[0];
			fRec57[1] = fRec57[0];
			fRec77[1] = fRec77[0];
			fRec75[1] = fRec75[0];
			fRec74[1] = fRec74[0];
			fRec72[1] = fRec72[0];
			fRec71[1] = fRec71[0];
			fRec69[1] = fRec69[0];
			fRec80[1] = fRec80[0];
			fRec78[1] = fRec78[0];
			fRec86[1] = fRec86[0];
			fRec84[1] = fRec84[0];
			fRec83[1] = fRec83[0];
			fRec81[1] = fRec81[0];
			fRec98[1] = fRec98[0];
			fRec96[1] = fRec96[0];
			fRec95[1] = fRec95[0];
			fRec93[1] = fRec93[0];
			fRec92[1] = fRec92[0];
			fRec90[1] = fRec90[0];
			fRec89[1] = fRec89[0];
			fRec87[1] = fRec87[0];
			fRec107[1] = fRec107[0];
			fRec105[1] = fRec105[0];
			fRec104[1] = fRec104[0];
			fRec102[1] = fRec102[0];
			fRec101[1] = fRec101[0];
			fRec99[1] = fRec99[0];
			fRec110[1] = fRec110[0];
			fRec108[1] = fRec108[0];
			fRec116[1] = fRec116[0];
			fRec114[1] = fRec114[0];
			fRec113[1] = fRec113[0];
			fRec111[1] = fRec111[0];
			fRec128[1] = fRec128[0];
			fRec126[1] = fRec126[0];
			fRec125[1] = fRec125[0];
			fRec123[1] = fRec123[0];
			fRec122[1] = fRec122[0];
			fRec120[1] = fRec120[0];
			fRec119[1] = fRec119[0];
			fRec117[1] = fRec117[0];
			fRec137[1] = fRec137[0];
			fRec135[1] = fRec135[0];
			fRec134[1] = fRec134[0];
			fRec132[1] = fRec132[0];
			fRec131[1] = fRec131[0];
			fRec129[1] = fRec129[0];
			fRec140[1] = fRec140[0];
			fRec138[1] = fRec138[0];
			fRec146[1] = fRec146[0];
			fRec144[1] = fRec144[0];
			fRec143[1] = fRec143[0];
			fRec141[1] = fRec141[0];
			fRec158[1] = fRec158[0];
			fRec156[1] = fRec156[0];
			fRec155[1] = fRec155[0];
			fRec153[1] = fRec153[0];
			fRec152[1] = fRec152[0];
			fRec150[1] = fRec150[0];
			fRec149[1] = fRec149[0];
			fRec147[1] = fRec147[0];
			fRec167[1] = fRec167[0];
			fRec165[1] = fRec165[0];
			fRec164[1] = fRec164[0];
			fRec162[1] = fRec162[0];
			fRec161[1] = fRec161[0];
			fRec159[1] = fRec159[0];
			fRec170[1] = fRec170[0];
			fRec168[1] = fRec168[0];
			fRec176[1] = fRec176[0];
			fRec174[1] = fRec174[0];
			fRec173[1] = fRec173[0];
			fRec171[1] = fRec171[0];
			fRec188[1] = fRec188[0];
			fRec186[1] = fRec186[0];
			fRec185[1] = fRec185[0];
			fRec183[1] = fRec183[0];
			fRec182[1] = fRec182[0];
			fRec180[1] = fRec180[0];
			fRec179[1] = fRec179[0];
			fRec177[1] = fRec177[0];
			fRec197[1] = fRec197[0];
			fRec195[1] = fRec195[0];
			fRec194[1] = fRec194[0];
			fRec192[1] = fRec192[0];
			fRec191[1] = fRec191[0];
			fRec189[1] = fRec189[0];
			fRec200[1] = fRec200[0];
			fRec198[1] = fRec198[0];
			fRec206[1] = fRec206[0];
			fRec204[1] = fRec204[0];
			fRec203[1] = fRec203[0];
			fRec201[1] = fRec201[0];
			fRec218[1] = fRec218[0];
			fRec216[1] = fRec216[0];
			fRec215[1] = fRec215[0];
			fRec213[1] = fRec213[0];
			fRec212[1] = fRec212[0];
			fRec210[1] = fRec210[0];
			fRec209[1] = fRec209[0];
			fRec207[1] = fRec207[0];
			fRec227[1] = fRec227[0];
			fRec225[1] = fRec225[0];
			fRec224[1] = fRec224[0];
			fRec222[1] = fRec222[0];
			fRec221[1] = fRec221[0];
			fRec219[1] = fRec219[0];
			fRec230[1] = fRec230[0];
			fRec228[1] = fRec228[0];
			fRec236[1] = fRec236[0];
			fRec234[1] = fRec234[0];
			fRec233[1] = fRec233[0];
			fRec231[1] = fRec231[0];
			fRec248[1] = fRec248[0];
			fRec246[1] = fRec246[0];
			fRec245[1] = fRec245[0];
			fRec243[1] = fRec243[0];
			fRec242[1] = fRec242[0];
			fRec240[1] = fRec240[0];
			fRec239[1] = fRec239[0];
			fRec237[1] = fRec237[0];
			fRec257[1] = fRec257[0];
			fRec255[1] = fRec255[0];
			fRec254[1] = fRec254[0];
			fRec252[1] = fRec252[0];
			fRec251[1] = fRec251[0];
			fRec249[1] = fRec249[0];
			fRec260[1] = fRec260[0];
			fRec258[1] = fRec258[0];
			fRec266[1] = fRec266[0];
			fRec264[1] = fRec264[0];
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
			fRec287[1] = fRec287[0];
			fRec285[1] = fRec285[0];
			fRec284[1] = fRec284[0];
			fRec282[1] = fRec282[0];
			fRec281[1] = fRec281[0];
			fRec279[1] = fRec279[0];
			fRec290[1] = fRec290[0];
			fRec288[1] = fRec288[0];
			fRec296[1] = fRec296[0];
			fRec294[1] = fRec294[0];
			fRec293[1] = fRec293[0];
			fRec291[1] = fRec291[0];
			fRec308[1] = fRec308[0];
			fRec306[1] = fRec306[0];
			fRec305[1] = fRec305[0];
			fRec303[1] = fRec303[0];
			fRec302[1] = fRec302[0];
			fRec300[1] = fRec300[0];
			fRec299[1] = fRec299[0];
			fRec297[1] = fRec297[0];
			fRec317[1] = fRec317[0];
			fRec315[1] = fRec315[0];
			fRec314[1] = fRec314[0];
			fRec312[1] = fRec312[0];
			fRec311[1] = fRec311[0];
			fRec309[1] = fRec309[0];
			fRec320[1] = fRec320[0];
			fRec318[1] = fRec318[0];
			fRec326[1] = fRec326[0];
			fRec324[1] = fRec324[0];
			fRec323[1] = fRec323[0];
			fRec321[1] = fRec321[0];
			fRec338[1] = fRec338[0];
			fRec336[1] = fRec336[0];
			fRec335[1] = fRec335[0];
			fRec333[1] = fRec333[0];
			fRec332[1] = fRec332[0];
			fRec330[1] = fRec330[0];
			fRec329[1] = fRec329[0];
			fRec327[1] = fRec327[0];
			fRec347[1] = fRec347[0];
			fRec345[1] = fRec345[0];
			fRec344[1] = fRec344[0];
			fRec342[1] = fRec342[0];
			fRec341[1] = fRec341[0];
			fRec339[1] = fRec339[0];
			fRec350[1] = fRec350[0];
			fRec348[1] = fRec348[0];
			fRec356[1] = fRec356[0];
			fRec354[1] = fRec354[0];
			fRec353[1] = fRec353[0];
			fRec351[1] = fRec351[0];
			fRec368[1] = fRec368[0];
			fRec366[1] = fRec366[0];
			fRec365[1] = fRec365[0];
			fRec363[1] = fRec363[0];
			fRec362[1] = fRec362[0];
			fRec360[1] = fRec360[0];
			fRec359[1] = fRec359[0];
			fRec357[1] = fRec357[0];
			fRec377[1] = fRec377[0];
			fRec375[1] = fRec375[0];
			fRec374[1] = fRec374[0];
			fRec372[1] = fRec372[0];
			fRec371[1] = fRec371[0];
			fRec369[1] = fRec369[0];
			fRec380[1] = fRec380[0];
			fRec378[1] = fRec378[0];
			fRec386[1] = fRec386[0];
			fRec384[1] = fRec384[0];
			fRec383[1] = fRec383[0];
			fRec381[1] = fRec381[0];
			fRec398[1] = fRec398[0];
			fRec396[1] = fRec396[0];
			fRec395[1] = fRec395[0];
			fRec393[1] = fRec393[0];
			fRec392[1] = fRec392[0];
			fRec390[1] = fRec390[0];
			fRec389[1] = fRec389[0];
			fRec387[1] = fRec387[0];
			fRec407[1] = fRec407[0];
			fRec405[1] = fRec405[0];
			fRec404[1] = fRec404[0];
			fRec402[1] = fRec402[0];
			fRec401[1] = fRec401[0];
			fRec399[1] = fRec399[0];
			fRec410[1] = fRec410[0];
			fRec408[1] = fRec408[0];
			fRec416[1] = fRec416[0];
			fRec414[1] = fRec414[0];
			fRec413[1] = fRec413[0];
			fRec411[1] = fRec411[0];
			fRec428[1] = fRec428[0];
			fRec426[1] = fRec426[0];
			fRec425[1] = fRec425[0];
			fRec423[1] = fRec423[0];
			fRec422[1] = fRec422[0];
			fRec420[1] = fRec420[0];
			fRec419[1] = fRec419[0];
			fRec417[1] = fRec417[0];
			fRec437[1] = fRec437[0];
			fRec435[1] = fRec435[0];
			fRec434[1] = fRec434[0];
			fRec432[1] = fRec432[0];
			fRec431[1] = fRec431[0];
			fRec429[1] = fRec429[0];
			fRec440[1] = fRec440[0];
			fRec438[1] = fRec438[0];
			fRec446[1] = fRec446[0];
			fRec444[1] = fRec444[0];
			fRec443[1] = fRec443[0];
			fRec441[1] = fRec441[0];
			fRec458[1] = fRec458[0];
			fRec456[1] = fRec456[0];
			fRec455[1] = fRec455[0];
			fRec453[1] = fRec453[0];
			fRec452[1] = fRec452[0];
			fRec450[1] = fRec450[0];
			fRec449[1] = fRec449[0];
			fRec447[1] = fRec447[0];
			fRec467[1] = fRec467[0];
			fRec465[1] = fRec465[0];
			fRec464[1] = fRec464[0];
			fRec462[1] = fRec462[0];
			fRec461[1] = fRec461[0];
			fRec459[1] = fRec459[0];
			fRec470[1] = fRec470[0];
			fRec468[1] = fRec468[0];
			fRec476[1] = fRec476[0];
			fRec474[1] = fRec474[0];
			fRec473[1] = fRec473[0];
			fRec471[1] = fRec471[0];
			fRec488[1] = fRec488[0];
			fRec486[1] = fRec486[0];
			fRec485[1] = fRec485[0];
			fRec483[1] = fRec483[0];
			fRec482[1] = fRec482[0];
			fRec480[1] = fRec480[0];
			fRec479[1] = fRec479[0];
			fRec477[1] = fRec477[0];
			fRec497[1] = fRec497[0];
			fRec495[1] = fRec495[0];
			fRec494[1] = fRec494[0];
			fRec492[1] = fRec492[0];
			fRec491[1] = fRec491[0];
			fRec489[1] = fRec489[0];
			fRec500[1] = fRec500[0];
			fRec498[1] = fRec498[0];
			fRec506[1] = fRec506[0];
			fRec504[1] = fRec504[0];
			fRec503[1] = fRec503[0];
			fRec501[1] = fRec501[0];
			fRec518[1] = fRec518[0];
			fRec516[1] = fRec516[0];
			fRec515[1] = fRec515[0];
			fRec513[1] = fRec513[0];
			fRec512[1] = fRec512[0];
			fRec510[1] = fRec510[0];
			fRec509[1] = fRec509[0];
			fRec507[1] = fRec507[0];
			fRec527[1] = fRec527[0];
			fRec525[1] = fRec525[0];
			fRec524[1] = fRec524[0];
			fRec522[1] = fRec522[0];
			fRec521[1] = fRec521[0];
			fRec519[1] = fRec519[0];
			fRec530[1] = fRec530[0];
			fRec528[1] = fRec528[0];
			fRec536[1] = fRec536[0];
			fRec534[1] = fRec534[0];
			fRec533[1] = fRec533[0];
			fRec531[1] = fRec531[0];
			fRec548[1] = fRec548[0];
			fRec546[1] = fRec546[0];
			fRec545[1] = fRec545[0];
			fRec543[1] = fRec543[0];
			fRec542[1] = fRec542[0];
			fRec540[1] = fRec540[0];
			fRec539[1] = fRec539[0];
			fRec537[1] = fRec537[0];
			fRec557[1] = fRec557[0];
			fRec555[1] = fRec555[0];
			fRec554[1] = fRec554[0];
			fRec552[1] = fRec552[0];
			fRec551[1] = fRec551[0];
			fRec549[1] = fRec549[0];
			fRec560[1] = fRec560[0];
			fRec558[1] = fRec558[0];
			fRec566[1] = fRec566[0];
			fRec564[1] = fRec564[0];
			fRec563[1] = fRec563[0];
			fRec561[1] = fRec561[0];
			fRec578[1] = fRec578[0];
			fRec576[1] = fRec576[0];
			fRec575[1] = fRec575[0];
			fRec573[1] = fRec573[0];
			fRec572[1] = fRec572[0];
			fRec570[1] = fRec570[0];
			fRec569[1] = fRec569[0];
			fRec567[1] = fRec567[0];
			fRec587[1] = fRec587[0];
			fRec585[1] = fRec585[0];
			fRec584[1] = fRec584[0];
			fRec582[1] = fRec582[0];
			fRec581[1] = fRec581[0];
			fRec579[1] = fRec579[0];
			fRec590[1] = fRec590[0];
			fRec588[1] = fRec588[0];
			fRec596[1] = fRec596[0];
			fRec594[1] = fRec594[0];
			fRec593[1] = fRec593[0];
			fRec591[1] = fRec591[0];
			fRec608[1] = fRec608[0];
			fRec606[1] = fRec606[0];
			fRec605[1] = fRec605[0];
			fRec603[1] = fRec603[0];
			fRec602[1] = fRec602[0];
			fRec600[1] = fRec600[0];
			fRec599[1] = fRec599[0];
			fRec597[1] = fRec597[0];
			fRec617[1] = fRec617[0];
			fRec615[1] = fRec615[0];
			fRec614[1] = fRec614[0];
			fRec612[1] = fRec612[0];
			fRec611[1] = fRec611[0];
			fRec609[1] = fRec609[0];
			fRec620[1] = fRec620[0];
			fRec618[1] = fRec618[0];
			fRec626[1] = fRec626[0];
			fRec624[1] = fRec624[0];
			fRec623[1] = fRec623[0];
			fRec621[1] = fRec621[0];
			fRec638[1] = fRec638[0];
			fRec636[1] = fRec636[0];
			fRec635[1] = fRec635[0];
			fRec633[1] = fRec633[0];
			fRec632[1] = fRec632[0];
			fRec630[1] = fRec630[0];
			fRec629[1] = fRec629[0];
			fRec627[1] = fRec627[0];
			fRec647[1] = fRec647[0];
			fRec645[1] = fRec645[0];
			fRec644[1] = fRec644[0];
			fRec642[1] = fRec642[0];
			fRec641[1] = fRec641[0];
			fRec639[1] = fRec639[0];
			fRec650[1] = fRec650[0];
			fRec648[1] = fRec648[0];
			fRec656[1] = fRec656[0];
			fRec654[1] = fRec654[0];
			fRec653[1] = fRec653[0];
			fRec651[1] = fRec651[0];
			fRec668[1] = fRec668[0];
			fRec666[1] = fRec666[0];
			fRec665[1] = fRec665[0];
			fRec663[1] = fRec663[0];
			fRec662[1] = fRec662[0];
			fRec660[1] = fRec660[0];
			fRec659[1] = fRec659[0];
			fRec657[1] = fRec657[0];
			fRec677[1] = fRec677[0];
			fRec675[1] = fRec675[0];
			fRec674[1] = fRec674[0];
			fRec672[1] = fRec672[0];
			fRec671[1] = fRec671[0];
			fRec669[1] = fRec669[0];
			fRec680[1] = fRec680[0];
			fRec678[1] = fRec678[0];
			fRec686[1] = fRec686[0];
			fRec684[1] = fRec684[0];
			fRec683[1] = fRec683[0];
			fRec681[1] = fRec681[0];
			fRec698[1] = fRec698[0];
			fRec696[1] = fRec696[0];
			fRec695[1] = fRec695[0];
			fRec693[1] = fRec693[0];
			fRec692[1] = fRec692[0];
			fRec690[1] = fRec690[0];
			fRec689[1] = fRec689[0];
			fRec687[1] = fRec687[0];
			fRec707[1] = fRec707[0];
			fRec705[1] = fRec705[0];
			fRec704[1] = fRec704[0];
			fRec702[1] = fRec702[0];
			fRec701[1] = fRec701[0];
			fRec699[1] = fRec699[0];
			fRec710[1] = fRec710[0];
			fRec708[1] = fRec708[0];
			fRec716[1] = fRec716[0];
			fRec714[1] = fRec714[0];
			fRec713[1] = fRec713[0];
			fRec711[1] = fRec711[0];
			fRec728[1] = fRec728[0];
			fRec726[1] = fRec726[0];
			fRec725[1] = fRec725[0];
			fRec723[1] = fRec723[0];
			fRec722[1] = fRec722[0];
			fRec720[1] = fRec720[0];
			fRec719[1] = fRec719[0];
			fRec717[1] = fRec717[0];
			fRec737[1] = fRec737[0];
			fRec735[1] = fRec735[0];
			fRec734[1] = fRec734[0];
			fRec732[1] = fRec732[0];
			fRec731[1] = fRec731[0];
			fRec729[1] = fRec729[0];
			fRec740[1] = fRec740[0];
			fRec738[1] = fRec738[0];
			fRec746[1] = fRec746[0];
			fRec744[1] = fRec744[0];
			fRec743[1] = fRec743[0];
			fRec741[1] = fRec741[0];
			fRec758[1] = fRec758[0];
			fRec756[1] = fRec756[0];
			fRec755[1] = fRec755[0];
			fRec753[1] = fRec753[0];
			fRec752[1] = fRec752[0];
			fRec750[1] = fRec750[0];
			fRec749[1] = fRec749[0];
			fRec747[1] = fRec747[0];
			fRec767[1] = fRec767[0];
			fRec765[1] = fRec765[0];
			fRec764[1] = fRec764[0];
			fRec762[1] = fRec762[0];
			fRec761[1] = fRec761[0];
			fRec759[1] = fRec759[0];
			fRec770[1] = fRec770[0];
			fRec768[1] = fRec768[0];
			fRec776[1] = fRec776[0];
			fRec774[1] = fRec774[0];
			fRec773[1] = fRec773[0];
			fRec771[1] = fRec771[0];
			for (int j0 = 11; (j0 > 0); j0 = (j0 - 1)) {
				fVec24[j0] = fVec24[(j0 - 1)];
				
			}
			fRec788[1] = fRec788[0];
			fRec786[1] = fRec786[0];
			fRec785[1] = fRec785[0];
			fRec783[1] = fRec783[0];
			fRec782[1] = fRec782[0];
			fRec780[1] = fRec780[0];
			fRec779[1] = fRec779[0];
			fRec777[1] = fRec777[0];
			fRec797[1] = fRec797[0];
			fRec795[1] = fRec795[0];
			fRec794[1] = fRec794[0];
			fRec792[1] = fRec792[0];
			fRec791[1] = fRec791[0];
			fRec789[1] = fRec789[0];
			fRec800[1] = fRec800[0];
			fRec798[1] = fRec798[0];
			fRec806[1] = fRec806[0];
			fRec804[1] = fRec804[0];
			fRec803[1] = fRec803[0];
			fRec801[1] = fRec801[0];
			for (int j1 = 11; (j1 > 0); j1 = (j1 - 1)) {
				fVec25[j1] = fVec25[(j1 - 1)];
				
			}
			fRec818[1] = fRec818[0];
			fRec816[1] = fRec816[0];
			fRec815[1] = fRec815[0];
			fRec813[1] = fRec813[0];
			fRec812[1] = fRec812[0];
			fRec810[1] = fRec810[0];
			fRec809[1] = fRec809[0];
			fRec807[1] = fRec807[0];
			fRec827[1] = fRec827[0];
			fRec825[1] = fRec825[0];
			fRec824[1] = fRec824[0];
			fRec822[1] = fRec822[0];
			fRec821[1] = fRec821[0];
			fRec819[1] = fRec819[0];
			fRec830[1] = fRec830[0];
			fRec828[1] = fRec828[0];
			fRec836[1] = fRec836[0];
			fRec834[1] = fRec834[0];
			fRec833[1] = fRec833[0];
			fRec831[1] = fRec831[0];
			for (int j2 = 11; (j2 > 0); j2 = (j2 - 1)) {
				fVec26[j2] = fVec26[(j2 - 1)];
				
			}
			fRec848[1] = fRec848[0];
			fRec846[1] = fRec846[0];
			fRec845[1] = fRec845[0];
			fRec843[1] = fRec843[0];
			fRec842[1] = fRec842[0];
			fRec840[1] = fRec840[0];
			fRec839[1] = fRec839[0];
			fRec837[1] = fRec837[0];
			fRec857[1] = fRec857[0];
			fRec855[1] = fRec855[0];
			fRec854[1] = fRec854[0];
			fRec852[1] = fRec852[0];
			fRec851[1] = fRec851[0];
			fRec849[1] = fRec849[0];
			fRec860[1] = fRec860[0];
			fRec858[1] = fRec858[0];
			fRec866[1] = fRec866[0];
			fRec864[1] = fRec864[0];
			fRec863[1] = fRec863[0];
			fRec861[1] = fRec861[0];
			for (int j3 = 11; (j3 > 0); j3 = (j3 - 1)) {
				fVec27[j3] = fVec27[(j3 - 1)];
				
			}
			fRec878[1] = fRec878[0];
			fRec876[1] = fRec876[0];
			fRec875[1] = fRec875[0];
			fRec873[1] = fRec873[0];
			fRec872[1] = fRec872[0];
			fRec870[1] = fRec870[0];
			fRec869[1] = fRec869[0];
			fRec867[1] = fRec867[0];
			fRec887[1] = fRec887[0];
			fRec885[1] = fRec885[0];
			fRec884[1] = fRec884[0];
			fRec882[1] = fRec882[0];
			fRec881[1] = fRec881[0];
			fRec879[1] = fRec879[0];
			fRec890[1] = fRec890[0];
			fRec888[1] = fRec888[0];
			fRec896[1] = fRec896[0];
			fRec894[1] = fRec894[0];
			fRec893[1] = fRec893[0];
			fRec891[1] = fRec891[0];
			fRec908[1] = fRec908[0];
			fRec906[1] = fRec906[0];
			fRec905[1] = fRec905[0];
			fRec903[1] = fRec903[0];
			fRec902[1] = fRec902[0];
			fRec900[1] = fRec900[0];
			fRec899[1] = fRec899[0];
			fRec897[1] = fRec897[0];
			fRec917[1] = fRec917[0];
			fRec915[1] = fRec915[0];
			fRec914[1] = fRec914[0];
			fRec912[1] = fRec912[0];
			fRec911[1] = fRec911[0];
			fRec909[1] = fRec909[0];
			fRec920[1] = fRec920[0];
			fRec918[1] = fRec918[0];
			fRec926[1] = fRec926[0];
			fRec924[1] = fRec924[0];
			fRec923[1] = fRec923[0];
			fRec921[1] = fRec921[0];
			fRec938[1] = fRec938[0];
			fRec936[1] = fRec936[0];
			fRec935[1] = fRec935[0];
			fRec933[1] = fRec933[0];
			fRec932[1] = fRec932[0];
			fRec930[1] = fRec930[0];
			fRec929[1] = fRec929[0];
			fRec927[1] = fRec927[0];
			fRec947[1] = fRec947[0];
			fRec945[1] = fRec945[0];
			fRec944[1] = fRec944[0];
			fRec942[1] = fRec942[0];
			fRec941[1] = fRec941[0];
			fRec939[1] = fRec939[0];
			fRec950[1] = fRec950[0];
			fRec948[1] = fRec948[0];
			fRec956[1] = fRec956[0];
			fRec954[1] = fRec954[0];
			fRec953[1] = fRec953[0];
			fRec951[1] = fRec951[0];
			fRec968[1] = fRec968[0];
			fRec966[1] = fRec966[0];
			fRec965[1] = fRec965[0];
			fRec963[1] = fRec963[0];
			fRec962[1] = fRec962[0];
			fRec960[1] = fRec960[0];
			fRec959[1] = fRec959[0];
			fRec957[1] = fRec957[0];
			fRec977[1] = fRec977[0];
			fRec975[1] = fRec975[0];
			fRec974[1] = fRec974[0];
			fRec972[1] = fRec972[0];
			fRec971[1] = fRec971[0];
			fRec969[1] = fRec969[0];
			fRec980[1] = fRec980[0];
			fRec978[1] = fRec978[0];
			fRec986[1] = fRec986[0];
			fRec984[1] = fRec984[0];
			fRec983[1] = fRec983[0];
			fRec981[1] = fRec981[0];
			fRec998[1] = fRec998[0];
			fRec996[1] = fRec996[0];
			fRec995[1] = fRec995[0];
			fRec993[1] = fRec993[0];
			fRec992[1] = fRec992[0];
			fRec990[1] = fRec990[0];
			fRec989[1] = fRec989[0];
			fRec987[1] = fRec987[0];
			fRec1007[1] = fRec1007[0];
			fRec1005[1] = fRec1005[0];
			fRec1004[1] = fRec1004[0];
			fRec1002[1] = fRec1002[0];
			fRec1001[1] = fRec1001[0];
			fRec999[1] = fRec999[0];
			fRec1010[1] = fRec1010[0];
			fRec1008[1] = fRec1008[0];
			fRec1016[1] = fRec1016[0];
			fRec1014[1] = fRec1014[0];
			fRec1013[1] = fRec1013[0];
			fRec1011[1] = fRec1011[0];
			fRec1028[1] = fRec1028[0];
			fRec1026[1] = fRec1026[0];
			fRec1025[1] = fRec1025[0];
			fRec1023[1] = fRec1023[0];
			fRec1022[1] = fRec1022[0];
			fRec1020[1] = fRec1020[0];
			fRec1019[1] = fRec1019[0];
			fRec1017[1] = fRec1017[0];
			fRec1037[1] = fRec1037[0];
			fRec1035[1] = fRec1035[0];
			fRec1034[1] = fRec1034[0];
			fRec1032[1] = fRec1032[0];
			fRec1031[1] = fRec1031[0];
			fRec1029[1] = fRec1029[0];
			fRec1040[1] = fRec1040[0];
			fRec1038[1] = fRec1038[0];
			fRec1046[1] = fRec1046[0];
			fRec1044[1] = fRec1044[0];
			fRec1043[1] = fRec1043[0];
			fRec1041[1] = fRec1041[0];
			fRec1058[1] = fRec1058[0];
			fRec1056[1] = fRec1056[0];
			fRec1055[1] = fRec1055[0];
			fRec1053[1] = fRec1053[0];
			fRec1052[1] = fRec1052[0];
			fRec1050[1] = fRec1050[0];
			fRec1049[1] = fRec1049[0];
			fRec1047[1] = fRec1047[0];
			fRec1067[1] = fRec1067[0];
			fRec1065[1] = fRec1065[0];
			fRec1064[1] = fRec1064[0];
			fRec1062[1] = fRec1062[0];
			fRec1061[1] = fRec1061[0];
			fRec1059[1] = fRec1059[0];
			fRec1070[1] = fRec1070[0];
			fRec1068[1] = fRec1068[0];
			fRec1076[1] = fRec1076[0];
			fRec1074[1] = fRec1074[0];
			fRec1073[1] = fRec1073[0];
			fRec1071[1] = fRec1071[0];
			fRec1088[1] = fRec1088[0];
			fRec1086[1] = fRec1086[0];
			fRec1085[1] = fRec1085[0];
			fRec1083[1] = fRec1083[0];
			fRec1082[1] = fRec1082[0];
			fRec1080[1] = fRec1080[0];
			fRec1079[1] = fRec1079[0];
			fRec1077[1] = fRec1077[0];
			fRec1097[1] = fRec1097[0];
			fRec1095[1] = fRec1095[0];
			fRec1094[1] = fRec1094[0];
			fRec1092[1] = fRec1092[0];
			fRec1091[1] = fRec1091[0];
			fRec1089[1] = fRec1089[0];
			fRec1100[1] = fRec1100[0];
			fRec1098[1] = fRec1098[0];
			fRec1106[1] = fRec1106[0];
			fRec1104[1] = fRec1104[0];
			fRec1103[1] = fRec1103[0];
			fRec1101[1] = fRec1101[0];
			fRec1118[1] = fRec1118[0];
			fRec1116[1] = fRec1116[0];
			fRec1115[1] = fRec1115[0];
			fRec1113[1] = fRec1113[0];
			fRec1112[1] = fRec1112[0];
			fRec1110[1] = fRec1110[0];
			fRec1109[1] = fRec1109[0];
			fRec1107[1] = fRec1107[0];
			fRec1127[1] = fRec1127[0];
			fRec1125[1] = fRec1125[0];
			fRec1124[1] = fRec1124[0];
			fRec1122[1] = fRec1122[0];
			fRec1121[1] = fRec1121[0];
			fRec1119[1] = fRec1119[0];
			fRec1130[1] = fRec1130[0];
			fRec1128[1] = fRec1128[0];
			fRec1136[1] = fRec1136[0];
			fRec1134[1] = fRec1134[0];
			fRec1133[1] = fRec1133[0];
			fRec1131[1] = fRec1131[0];
			fRec1148[1] = fRec1148[0];
			fRec1146[1] = fRec1146[0];
			fRec1145[1] = fRec1145[0];
			fRec1143[1] = fRec1143[0];
			fRec1142[1] = fRec1142[0];
			fRec1140[1] = fRec1140[0];
			fRec1139[1] = fRec1139[0];
			fRec1137[1] = fRec1137[0];
			fRec1157[1] = fRec1157[0];
			fRec1155[1] = fRec1155[0];
			fRec1154[1] = fRec1154[0];
			fRec1152[1] = fRec1152[0];
			fRec1151[1] = fRec1151[0];
			fRec1149[1] = fRec1149[0];
			fRec1160[1] = fRec1160[0];
			fRec1158[1] = fRec1158[0];
			fRec1166[1] = fRec1166[0];
			fRec1164[1] = fRec1164[0];
			fRec1163[1] = fRec1163[0];
			fRec1161[1] = fRec1161[0];
			fRec1178[1] = fRec1178[0];
			fRec1176[1] = fRec1176[0];
			fRec1175[1] = fRec1175[0];
			fRec1173[1] = fRec1173[0];
			fRec1172[1] = fRec1172[0];
			fRec1170[1] = fRec1170[0];
			fRec1169[1] = fRec1169[0];
			fRec1167[1] = fRec1167[0];
			fRec1187[1] = fRec1187[0];
			fRec1185[1] = fRec1185[0];
			fRec1184[1] = fRec1184[0];
			fRec1182[1] = fRec1182[0];
			fRec1181[1] = fRec1181[0];
			fRec1179[1] = fRec1179[0];
			fRec1190[1] = fRec1190[0];
			fRec1188[1] = fRec1188[0];
			fRec1196[1] = fRec1196[0];
			fRec1194[1] = fRec1194[0];
			fRec1193[1] = fRec1193[0];
			fRec1191[1] = fRec1191[0];
			fRec1208[1] = fRec1208[0];
			fRec1206[1] = fRec1206[0];
			fRec1205[1] = fRec1205[0];
			fRec1203[1] = fRec1203[0];
			fRec1202[1] = fRec1202[0];
			fRec1200[1] = fRec1200[0];
			fRec1199[1] = fRec1199[0];
			fRec1197[1] = fRec1197[0];
			fRec1217[1] = fRec1217[0];
			fRec1215[1] = fRec1215[0];
			fRec1214[1] = fRec1214[0];
			fRec1212[1] = fRec1212[0];
			fRec1211[1] = fRec1211[0];
			fRec1209[1] = fRec1209[0];
			fRec1220[1] = fRec1220[0];
			fRec1218[1] = fRec1218[0];
			fRec1226[1] = fRec1226[0];
			fRec1224[1] = fRec1224[0];
			fRec1223[1] = fRec1223[0];
			fRec1221[1] = fRec1221[0];
			fRec1238[1] = fRec1238[0];
			fRec1236[1] = fRec1236[0];
			fRec1235[1] = fRec1235[0];
			fRec1233[1] = fRec1233[0];
			fRec1232[1] = fRec1232[0];
			fRec1230[1] = fRec1230[0];
			fRec1229[1] = fRec1229[0];
			fRec1227[1] = fRec1227[0];
			fRec1247[1] = fRec1247[0];
			fRec1245[1] = fRec1245[0];
			fRec1244[1] = fRec1244[0];
			fRec1242[1] = fRec1242[0];
			fRec1241[1] = fRec1241[0];
			fRec1239[1] = fRec1239[0];
			fRec1250[1] = fRec1250[0];
			fRec1248[1] = fRec1248[0];
			fRec1256[1] = fRec1256[0];
			fRec1254[1] = fRec1254[0];
			fRec1253[1] = fRec1253[0];
			fRec1251[1] = fRec1251[0];
			fRec1268[1] = fRec1268[0];
			fRec1266[1] = fRec1266[0];
			fRec1265[1] = fRec1265[0];
			fRec1263[1] = fRec1263[0];
			fRec1262[1] = fRec1262[0];
			fRec1260[1] = fRec1260[0];
			fRec1259[1] = fRec1259[0];
			fRec1257[1] = fRec1257[0];
			fRec1277[1] = fRec1277[0];
			fRec1275[1] = fRec1275[0];
			fRec1274[1] = fRec1274[0];
			fRec1272[1] = fRec1272[0];
			fRec1271[1] = fRec1271[0];
			fRec1269[1] = fRec1269[0];
			fRec1280[1] = fRec1280[0];
			fRec1278[1] = fRec1278[0];
			fRec1286[1] = fRec1286[0];
			fRec1284[1] = fRec1284[0];
			fRec1283[1] = fRec1283[0];
			fRec1281[1] = fRec1281[0];
			fRec1298[1] = fRec1298[0];
			fRec1296[1] = fRec1296[0];
			fRec1295[1] = fRec1295[0];
			fRec1293[1] = fRec1293[0];
			fRec1292[1] = fRec1292[0];
			fRec1290[1] = fRec1290[0];
			fRec1289[1] = fRec1289[0];
			fRec1287[1] = fRec1287[0];
			fRec1307[1] = fRec1307[0];
			fRec1305[1] = fRec1305[0];
			fRec1304[1] = fRec1304[0];
			fRec1302[1] = fRec1302[0];
			fRec1301[1] = fRec1301[0];
			fRec1299[1] = fRec1299[0];
			fRec1310[1] = fRec1310[0];
			fRec1308[1] = fRec1308[0];
			fRec1316[1] = fRec1316[0];
			fRec1314[1] = fRec1314[0];
			fRec1313[1] = fRec1313[0];
			fRec1311[1] = fRec1311[0];
			fRec1328[1] = fRec1328[0];
			fRec1326[1] = fRec1326[0];
			fRec1325[1] = fRec1325[0];
			fRec1323[1] = fRec1323[0];
			fRec1322[1] = fRec1322[0];
			fRec1320[1] = fRec1320[0];
			fRec1319[1] = fRec1319[0];
			fRec1317[1] = fRec1317[0];
			fRec1337[1] = fRec1337[0];
			fRec1335[1] = fRec1335[0];
			fRec1334[1] = fRec1334[0];
			fRec1332[1] = fRec1332[0];
			fRec1331[1] = fRec1331[0];
			fRec1329[1] = fRec1329[0];
			fRec1340[1] = fRec1340[0];
			fRec1338[1] = fRec1338[0];
			fRec1346[1] = fRec1346[0];
			fRec1344[1] = fRec1344[0];
			fRec1343[1] = fRec1343[0];
			fRec1341[1] = fRec1341[0];
			fRec1358[1] = fRec1358[0];
			fRec1356[1] = fRec1356[0];
			fRec1355[1] = fRec1355[0];
			fRec1353[1] = fRec1353[0];
			fRec1352[1] = fRec1352[0];
			fRec1350[1] = fRec1350[0];
			fRec1349[1] = fRec1349[0];
			fRec1347[1] = fRec1347[0];
			fRec1367[1] = fRec1367[0];
			fRec1365[1] = fRec1365[0];
			fRec1364[1] = fRec1364[0];
			fRec1362[1] = fRec1362[0];
			fRec1361[1] = fRec1361[0];
			fRec1359[1] = fRec1359[0];
			fRec1370[1] = fRec1370[0];
			fRec1368[1] = fRec1368[0];
			fRec1376[1] = fRec1376[0];
			fRec1374[1] = fRec1374[0];
			fRec1373[1] = fRec1373[0];
			fRec1371[1] = fRec1371[0];
			
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
