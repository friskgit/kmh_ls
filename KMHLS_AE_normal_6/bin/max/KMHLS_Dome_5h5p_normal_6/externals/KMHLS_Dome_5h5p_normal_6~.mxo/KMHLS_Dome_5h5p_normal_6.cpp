/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit, Henrik Frisk"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMHLS_Dome_5h5p_normal_6"
version: "1.2"
Code generated with Faust 2.18.3 (https://faust.grame.fr)
Compilation options: -lang cpp -double -ftz 0
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

/************************** BEGIN UI.h **************************/
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

template <typename REAL>
class UIReal
{
    
    public:
        
        UIReal() {}
        virtual ~UIReal() {}
        
        // -- widget's layouts
        
        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;
        
        // -- active widgets
        
        virtual void addButton(const char* label, REAL* zone) = 0;
        virtual void addCheckButton(const char* label, REAL* zone) = 0;
        virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
        virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
        virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
        
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) = 0;
        virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max) = 0;
        
        // -- soundfiles
        
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;
        
        // -- metadata declarations
        
        virtual void declare(REAL* zone, const char* key, const char* val) {}
};

class UI : public UIReal<FAUSTFLOAT>
{

    public:

        UI() {}
        virtual ~UI() {}
};

#endif
/**************************  END  UI.h **************************/
/************************** BEGIN JSONUI.h **************************/
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
#include <iomanip>
#include <sstream>
#include <algorithm>

/************************** BEGIN PathBuilder.h **************************/
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
    
        void pushLabel(const std::string& label) { fControlsLevel.push_back(label); }
        void popLabel() { fControlsLevel.pop_back(); }
    
};

#endif  // FAUST_PATHBUILDER_H
/**************************  END  PathBuilder.h **************************/
/************************** BEGIN meta.h **************************/
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
    virtual ~Meta() {};
    virtual void declare(const char* key, const char* value) = 0;
    
};

#endif
/**************************  END  meta.h **************************/

/*******************************************************************************
 * JSONUI : Faust User Interface
 * This class produce a complete JSON decription of the DSP instance.
 ******************************************************************************/

template <typename REAL>
class JSONUIAux : public PathBuilder, public Meta, public UIReal<REAL>
{

    protected:
    
        std::stringstream fUI;
        std::stringstream fMeta;
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        std::string fVersion;           // Compiler version
        std::string fCompileOptions;    // Compilation options
        std::vector<std::string> fLibraryList;
        std::vector<std::string> fIncludePathnames;
        std::string fName;
        std::string fFileName;
        std::string fExpandedCode;
        std::string fSHAKey;
        int fDSPSize;                   // In bytes
        std::map<std::string, int> fPathTable;
        bool fExtended;
    
        char fCloseUIPar;
        char fCloseMetaPar;
        int fTab;
    
        int fInputs, fOutputs, fSRIndex;
         
        void tab(int n, std::ostream& fout)
        {
            fout << '\n';
            while (n-- > 0) {
                fout << '\t';
            }
        }
    
        std::string flatten(const std::string& src)
        {
            std::string dst;
            for (size_t i = 0; i < src.size(); i++) {
                switch (src[i]) {
                    case '\n':
                    case '\t':
                        break;
                    default:
                        dst += src[i];
                        break;
                }
            }
            return dst;
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
    
        int getAddressIndex(const std::string& path)
        {
            return (fPathTable.find(path) != fPathTable.end()) ? fPathTable[path] : -1;
        }
      
     public:
     
        JSONUIAux(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  int sr_index,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& compile_options,
                  const std::vector<std::string>& library_list,
                  const std::vector<std::string>& include_pathnames,
                  int size,
                  const std::map<std::string, int>& path_table)
        {
            init(name, filename, inputs, outputs, sr_index, sha_key, dsp_code, version, compile_options, library_list, include_pathnames, size, path_table);
        }

        JSONUIAux(const std::string& name, const std::string& filename, int inputs, int outputs)
        {
            init(name, filename, inputs, outputs, -1, "", "", "", "", std::vector<std::string>(), std::vector<std::string>(), -1, std::map<std::string, int>());
        }

        JSONUIAux(int inputs, int outputs)
        {
            init("", "", inputs, outputs, -1, "", "","", "", std::vector<std::string>(), std::vector<std::string>(), -1, std::map<std::string, int>());
        }
        
        JSONUIAux()
        {
            init("", "", -1, -1, -1, "", "", "", "", std::vector<std::string>(), std::vector<std::string>(), -1, std::map<std::string, int>());
        }
 
        virtual ~JSONUIAux() {}
        
        void setInputs(int inputs) { fInputs = inputs; }
        void setOutputs(int outputs) { fOutputs = outputs; }
    
        void setSRIndex(int sr_index) { fSRIndex = sr_index; }
    
        // Init may be called multiple times so fMeta and fUI are reinitialized
        void init(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  int sr_index,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& compile_options,
                  const std::vector<std::string>& library_list,
                  const std::vector<std::string>& include_pathnames,
                  int size,
                  const std::map<std::string, int>& path_table,
                  bool extended = false)
        {
            fTab = 1;
            fExtended = extended;
            if (fExtended) {
                fUI << std::setprecision(std::numeric_limits<REAL>::max_digits10);
                fMeta << std::setprecision(std::numeric_limits<REAL>::max_digits10);
            }
            
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
            fSRIndex = sr_index;
            fExpandedCode = dsp_code;
            fSHAKey = sha_key;
            fDSPSize = size;
            fPathTable = path_table;
            fVersion = version;
            fCompileOptions = compile_options;
            fLibraryList = library_list;
            fIncludePathnames = include_pathnames;
        }
   
        // -- widget's layouts
    
        virtual void openGenericGroup(const char* label, const char* name)
        {
            pushLabel(label);
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            addMeta(fTab);
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
            popLabel();
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
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"address\": \"" << path << "\",";
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path) << ((fMetaAux.size() > 0) ? "," : "");
            } else {
                tab(fTab, fUI); fUI << "\"address\": \"" << path << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            }
            addMeta(fTab, false);
            fTab -= 1;
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
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            tab(fTab, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path) << ",";
            }
            addMeta(fTab);
            tab(fTab, fUI); fUI << "\"init\": " << init << ",";
            tab(fTab, fUI); fUI << "\"min\": " << min << ",";
            tab(fTab, fUI); fUI << "\"max\": " << max << ",";
            tab(fTab, fUI); fUI << "\"step\": " << step;
            fTab -= 1;
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
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            tab(fTab, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path) << ",";
            }
            addMeta(fTab);
            tab(fTab, fUI); fUI << "\"min\": " << min << ",";
            tab(fTab, fUI); fUI << "\"max\": " << max;
            fTab -= 1;
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
            std::string path = buildPath(label);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << "soundfile" << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab, fUI); fUI << "\"url\": \"" << url << "\"" << ",";
            tab(fTab, fUI); fUI << "\"address\": \"" << path << "\"" << ((fPathTable.size() > 0) ? "," : "");
            if (fPathTable.size() > 0) {
                tab(fTab, fUI); fUI << "\"index\": " << getAddressIndex(path);
            }
            fTab -= 1;
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
            std::stringstream JSON;
            if (fExtended) {
                JSON << std::setprecision(std::numeric_limits<REAL>::max_digits10);
            }
            JSON << "{";
            fTab += 1;
            tab(fTab, JSON); JSON << "\"name\": \"" << fName << "\",";
            tab(fTab, JSON); JSON << "\"filename\": \"" << fFileName << "\",";
            if (fVersion != "") { tab(fTab, JSON); JSON << "\"version\": \"" << fVersion << "\","; }
            if (fCompileOptions != "") { tab(fTab, JSON); JSON << "\"compile_options\": \"" <<  fCompileOptions << "\","; }
            if (fLibraryList.size() > 0) {
                tab(fTab, JSON);
                JSON << "\"library_list\": [";
                for (size_t i = 0; i < fLibraryList.size(); i++) {
                    JSON << "\"" << fLibraryList[i] << "\"";
                    if (i < (fLibraryList.size() - 1)) JSON << ",";
                }
                JSON << "],";
            }
            if (fIncludePathnames.size() > 0) {
                tab(fTab, JSON);
                JSON << "\"include_pathnames\": [";
                for (size_t i = 0; i < fIncludePathnames.size(); i++) {
                    JSON << "\"" << fIncludePathnames[i] << "\"";
                    if (i < (fIncludePathnames.size() - 1)) JSON << ",";
                }
                JSON << "],";
            }
            if (fDSPSize != -1) { tab(fTab, JSON); JSON << "\"size\": " << fDSPSize << ","; }
            if (fSHAKey != "") { tab(fTab, JSON); JSON << "\"sha_key\": \"" << fSHAKey << "\","; }
            if (fExpandedCode != "") { tab(fTab, JSON); JSON << "\"code\": \"" << fExpandedCode << "\","; }
            tab(fTab, JSON); JSON << "\"inputs\": " << fInputs << ",";
            tab(fTab, JSON); JSON << "\"outputs\": " << fOutputs << ",";
            if (fSRIndex != -1) { tab(fTab, JSON); JSON << "\"sr_index\": " << fSRIndex << ","; }
            tab(fTab, fMeta); fMeta << "],";
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            if (fCloseMetaPar == ',') { // If "declare" has been called, fCloseMetaPar state is now ','
                JSON << fMeta.str() << fUI.str();
            } else {
                JSON << fUI.str();
            }
            tab(fTab, JSON); JSON << "}";
            return (flat) ? flatten(JSON.str()) : JSON.str();
        }
    
};

// Externally available class using FAUSTFLOAT

class JSONUI : public JSONUIAux<FAUSTFLOAT>, public UI
{
    public :
    
        JSONUI(const std::string& name,
               const std::string& filename,
               int inputs,
               int outputs,
               int sr_index,
               const std::string& sha_key,
               const std::string& dsp_code,
               const std::string& version,
               const std::string& compile_options,
               const std::vector<std::string>& library_list,
               const std::vector<std::string>& include_pathnames,
               int size,
               const std::map<std::string, int>& path_table):
        JSONUIAux<FAUSTFLOAT>(name, filename,
                              inputs, outputs,
                              sr_index,
                              sha_key, dsp_code,
                              version, compile_options,
                              library_list, include_pathnames,
                              size, path_table)
        {}
        
        JSONUI(const std::string& name, const std::string& filename, int inputs, int outputs):
        JSONUIAux<FAUSTFLOAT>(name, filename, inputs, outputs)
        {}
        
        JSONUI(int inputs, int outputs):JSONUIAux<FAUSTFLOAT>(inputs, outputs)
        {}
        
        JSONUI():JSONUIAux<FAUSTFLOAT>()
        {}
    
        virtual void openTabBox(const char* label)
        {
            JSONUIAux<FAUSTFLOAT>::openTabBox(label);
        }
        virtual void openHorizontalBox(const char* label)
        {
            JSONUIAux<FAUSTFLOAT>::openHorizontalBox(label);
        }
        virtual void openVerticalBox(const char* label)
        {
            JSONUIAux<FAUSTFLOAT>::openVerticalBox(label);
        }
        virtual void closeBox()
        {
            JSONUIAux<FAUSTFLOAT>::closeBox();
        }
        
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            JSONUIAux<FAUSTFLOAT>::addButton(label, zone);
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            JSONUIAux<FAUSTFLOAT>::addCheckButton(label, zone);
        }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            JSONUIAux<FAUSTFLOAT>::addVerticalSlider(label, zone, init, min, max, step);
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            JSONUIAux<FAUSTFLOAT>::addHorizontalSlider(label, zone, init, min, max, step);
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            JSONUIAux<FAUSTFLOAT>::addNumEntry(label, zone, init, min, max, step);
        }
        
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            JSONUIAux<FAUSTFLOAT>::addHorizontalBargraph(label, zone, min, max);
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            JSONUIAux<FAUSTFLOAT>::addVerticalBargraph(label, zone, min, max);
        }
        
        // -- soundfiles
        
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone)
        {
            JSONUIAux<FAUSTFLOAT>::addSoundfile(label, filename, sf_zone);
        }
        
        // -- metadata declarations
        
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            JSONUIAux<FAUSTFLOAT>::declare(zone, key, val);
        }
    
        virtual void declare(const char* key, const char* val)
        {
            JSONUIAux<FAUSTFLOAT>::declare(key, val);
        }
    
        virtual ~JSONUI() {}
    
};

#endif // FAUST_JSONUI_H
/**************************  END  JSONUI.h **************************/
/************************** BEGIN JSONUIDecoder.h **************************/
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
#include <cstdlib>
#include <sstream>
#include <functional>

/************************** BEGIN CGlue.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
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

#ifndef CGLUE_H
#define CGLUE_H

/************************** BEGIN CInterface.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
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

#ifndef CINTERFACE_H
#define CINTERFACE_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
    
struct Soundfile;

/*******************************************************************************
 * UI and Meta classes for C or LLVM generated code.
 ******************************************************************************/

// -- widget's layouts

typedef void (* openTabBoxFun) (void* ui_interface, const char* label);
typedef void (* openHorizontalBoxFun) (void* ui_interface, const char* label);
typedef void (* openVerticalBoxFun) (void* ui_interface, const char* label);
typedef void (*closeBoxFun) (void* ui_interface);

// -- active widgets

typedef void (* addButtonFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone);
typedef void (* addCheckButtonFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone);
typedef void (* addVerticalSliderFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step);
typedef void (* addHorizontalSliderFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step);
typedef void (* addNumEntryFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step);

// -- passive widgets

typedef void (* addHorizontalBargraphFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max);
typedef void (* addVerticalBargraphFun) (void* ui_interface, const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max);

// -- soundfiles
    
typedef void (* addSoundfileFun) (void* ui_interface, const char* label, const char* url, struct Soundfile** sf_zone);

typedef void (* declareFun) (void* ui_interface, FAUSTFLOAT* zone, const char* key, const char* value);

typedef struct {

    void* uiInterface;

    openTabBoxFun openTabBox;
    openHorizontalBoxFun openHorizontalBox;
    openVerticalBoxFun openVerticalBox;
    closeBoxFun closeBox;
    addButtonFun addButton;
    addCheckButtonFun addCheckButton;
    addVerticalSliderFun addVerticalSlider;
    addHorizontalSliderFun addHorizontalSlider;
    addNumEntryFun addNumEntry;
    addHorizontalBargraphFun addHorizontalBargraph;
    addVerticalBargraphFun addVerticalBargraph;
    addSoundfileFun addSoundfile;
    declareFun declare;

} UIGlue;

typedef void (* metaDeclareFun) (void* ui_interface, const char* key, const char* value);

typedef struct {

    void* metaInterface;
    
    metaDeclareFun declare;

} MetaGlue;

/***************************************
 *  Interface for the DSP object
 ***************************************/

typedef char dsp_imp;
    
typedef dsp_imp* (* newDspFun) ();
typedef void (* deleteDspFun) (dsp_imp* dsp);
typedef void (* allocateDspFun) (dsp_imp* dsp);
typedef void (* destroyDspFun) (dsp_imp* dsp);
typedef int (* getNumInputsFun) (dsp_imp* dsp);
typedef int (* getNumOutputsFun) (dsp_imp* dsp);
typedef void (* buildUserInterfaceFun) (dsp_imp* dsp, UIGlue* ui);
typedef void (* initFun) (dsp_imp* dsp, int sample_rate);
typedef void (* clearFun) (dsp_imp* dsp);
typedef int (* getSampleRateFun) (dsp_imp* dsp);
typedef void (* computeFun) (dsp_imp* dsp, int len, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs);
typedef void (* metadataFun) (MetaGlue* meta);
typedef void (* classInitFun) (int sample_rate);
typedef const char* (* getJSONFun) ();
    
/***************************************
 * DSP memory manager functions
 ***************************************/

typedef void* (* allocateFun) (void* manager_interface, size_t size);
typedef void (* destroyFun) (void* manager_interface, void* ptr);

typedef struct {
    
    void* managerInterface;
    
    allocateFun allocate;
    destroyFun destroy;
    
} ManagerGlue;

#ifdef __cplusplus
}
#endif

#endif
/**************************  END  CInterface.h **************************/
/************************** BEGIN dsp.h **************************/
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
         * @param sample_rate - the sampling rate in Hertz
         */
        virtual void init(int sample_rate) = 0;

        /**
         * Init instance state
         *
         * @param sample_rate - the sampling rate in Hertz
         */
        virtual void instanceInit(int sample_rate) = 0;

        /**
         * Init instance constant state
         *
         * @param sample_rate - the sampling rate in Hertz
         */
        virtual void instanceConstants(int sample_rate) = 0;
    
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
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (either float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (either float, double or quad)
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
        virtual void init(int sample_rate) { fDSP->init(sample_rate); }
        virtual void instanceInit(int sample_rate) { fDSP->instanceInit(sample_rate); }
        virtual void instanceConstants(int sample_rate) { fDSP->instanceConstants(sample_rate); }
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
        virtual std::string getCompileOptions() = 0;
        virtual std::vector<std::string> getLibraryList() = 0;
        virtual std::vector<std::string> getIncludePathnames() = 0;
    
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
/**************************  END  dsp.h **************************/

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * UI glue code
 ******************************************************************************/
 
class UIFloat
{

    public:

        UIFloat() {}

        virtual ~UIFloat() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, float* zone) = 0;
        virtual void addCheckButton(const char* label, float* zone) = 0;
        virtual void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
        virtual void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
        virtual void addNumEntry(const char* label, float* zone, float init, float min, float max, float step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, float* zone, float min, float max) = 0;
        virtual void addVerticalBargraph(const char* label, float* zone, float min, float max) = 0;
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;

        // -- metadata declarations

        virtual void declare(float* zone, const char* key, const char* val) {}
};

static void openTabBoxGlueFloat(void* cpp_interface, const char* label)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->openTabBox(label);
}

static void openHorizontalBoxGlueFloat(void* cpp_interface, const char* label)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->openHorizontalBox(label);
}

static void openVerticalBoxGlueFloat(void* cpp_interface, const char* label)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->openVerticalBox(label);
}

static void closeBoxGlueFloat(void* cpp_interface)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->closeBox();
}

static void addButtonGlueFloat(void* cpp_interface, const char* label, float* zone)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addButton(label, zone);
}

static void addCheckButtonGlueFloat(void* cpp_interface, const char* label, float* zone)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addCheckButton(label, zone);
}

static void addVerticalSliderGlueFloat(void* cpp_interface, const char* label, float* zone, float init, float min, float max, float step)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addVerticalSlider(label, zone, init, min, max, step);
}

static void addHorizontalSliderGlueFloat(void* cpp_interface, const char* label, float* zone, float init, float min, float max, float step)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addHorizontalSlider(label, zone, init, min, max, step);
}

static void addNumEntryGlueFloat(void* cpp_interface, const char* label, float* zone, float init, float min, float max, float step)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addNumEntry(label, zone, init, min, max, step);
}

static void addHorizontalBargraphGlueFloat(void* cpp_interface, const char* label, float* zone, float min, float max)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addHorizontalBargraph(label, zone, min, max);
}

static void addVerticalBargraphGlueFloat(void* cpp_interface, const char* label, float* zone, float min, float max)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addVerticalBargraph(label, zone, min, max);
}
    
static void addSoundfileGlueFloat(void* cpp_interface, const char* label, const char* url, Soundfile** sf_zone)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->addSoundfile(label, url, sf_zone);
}

static void declareGlueFloat(void* cpp_interface, float* zone, const char* key, const char* value)
{
    UIFloat* ui_interface = static_cast<UIFloat*>(cpp_interface);
    ui_interface->declare(zone, key, value);
}

class UIDouble
{

    public:

        UIDouble() {}

        virtual ~UIDouble() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, double* zone) = 0;
        virtual void addCheckButton(const char* label, double* zone) = 0;
        virtual void addVerticalSlider(const char* label, double* zone, double init, double min, double max, double step) = 0;
        virtual void addHorizontalSlider(const char* label, double* zone, double init, double min, double max, double step) = 0;
        virtual void addNumEntry(const char* label, double* zone, double init, double min, double max, double step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, double* zone, double min, double max) = 0;
        virtual void addVerticalBargraph(const char* label, double* zone, double min, double max) = 0;
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;

        // -- metadata declarations

        virtual void declare(double* zone, const char* key, const char* val) {}
};

static void openTabBoxGlueDouble(void* cpp_interface, const char* label)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->openTabBox(label);
}

static void openHorizontalBoxGlueDouble(void* cpp_interface, const char* label)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->openHorizontalBox(label);
}

static void openVerticalBoxGlueDouble(void* cpp_interface, const char* label)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->openVerticalBox(label);
}

static void closeBoxGlueDouble(void* cpp_interface)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->closeBox();
}

static void addButtonGlueDouble(void* cpp_interface, const char* label, double* zone)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addButton(label, zone);
}

static void addCheckButtonGlueDouble(void* cpp_interface, const char* label, double* zone)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addCheckButton(label, zone);
}

static void addVerticalSliderGlueDouble(void* cpp_interface, const char* label, double* zone, double init, double min, double max, double step)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addVerticalSlider(label, zone, init, min, max, step);
}

static void addHorizontalSliderGlueDouble(void* cpp_interface, const char* label, double* zone, double init, double min, double max, double step)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addHorizontalSlider(label, zone, init, min, max, step);
}

static void addNumEntryGlueDouble(void* cpp_interface, const char* label, double* zone, double init, double min, double max, double step)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addNumEntry(label, zone, init, min, max, step);
}

static void addHorizontalBargraphGlueDouble(void* cpp_interface, const char* label, double* zone, double min, double max)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addHorizontalBargraph(label, zone, min, max);
}

static void addVerticalBargraphGlueDouble(void* cpp_interface, const char* label, double* zone, double min, double max)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addVerticalBargraph(label, zone, min, max);
}
    
static void addSoundfileGlueDouble(void* cpp_interface, const char* label, const char* url, Soundfile** sf_zone)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->addSoundfile(label, url, sf_zone);
}

static void declareGlueDouble(void* cpp_interface, double* zone, const char* key, const char* value)
{
    UIDouble* ui_interface = static_cast<UIDouble*>(cpp_interface);
    ui_interface->declare(zone, key, value);
}

static void buildUIGlue(UIGlue* glue, UI* ui_interface, bool is_double)
{
    glue->uiInterface = ui_interface;
    
    if (is_double) {
        glue->openTabBox = reinterpret_cast<openTabBoxFun>(openTabBoxGlueDouble);
        glue->openHorizontalBox = reinterpret_cast<openHorizontalBoxFun>(openHorizontalBoxGlueDouble);
        glue->openVerticalBox = reinterpret_cast<openVerticalBoxFun>(openVerticalBoxGlueDouble);
        glue->closeBox = reinterpret_cast<closeBoxFun>(closeBoxGlueDouble);
        glue->addButton = reinterpret_cast<addButtonFun>(addButtonGlueDouble);
        glue->addCheckButton = reinterpret_cast<addCheckButtonFun>(addCheckButtonGlueDouble);
        glue->addVerticalSlider = reinterpret_cast<addVerticalSliderFun>(addVerticalSliderGlueDouble);
        glue->addHorizontalSlider = reinterpret_cast<addHorizontalSliderFun>(addHorizontalSliderGlueDouble);
        glue->addNumEntry = reinterpret_cast<addNumEntryFun>(addNumEntryGlueDouble);
        glue->addHorizontalBargraph = reinterpret_cast<addHorizontalBargraphFun>(addHorizontalBargraphGlueDouble);
        glue->addVerticalBargraph = reinterpret_cast<addVerticalBargraphFun>(addVerticalBargraphGlueDouble);
        glue->addSoundfile = reinterpret_cast<addSoundfileFun>(addSoundfileGlueDouble);
        glue->declare = reinterpret_cast<declareFun>(declareGlueDouble);
    } else {
        glue->openTabBox = reinterpret_cast<openTabBoxFun>(openTabBoxGlueFloat);
        glue->openHorizontalBox = reinterpret_cast<openHorizontalBoxFun>(openHorizontalBoxGlueFloat);
        glue->openVerticalBox = reinterpret_cast<openVerticalBoxFun>(openVerticalBoxGlueFloat);
        glue->closeBox = reinterpret_cast<closeBoxFun>(closeBoxGlueFloat);
        glue->addButton = reinterpret_cast<addButtonFun>(addButtonGlueFloat);
        glue->addCheckButton = reinterpret_cast<addCheckButtonFun>(addCheckButtonGlueFloat);
        glue->addVerticalSlider = reinterpret_cast<addVerticalSliderFun>(addVerticalSliderGlueFloat);
        glue->addHorizontalSlider = reinterpret_cast<addHorizontalSliderFun>(addHorizontalSliderGlueFloat);
        glue->addNumEntry = reinterpret_cast<addNumEntryFun>(addNumEntryGlueFloat);
        glue->addHorizontalBargraph = reinterpret_cast<addHorizontalBargraphFun>(addHorizontalBargraphGlueFloat);
        glue->addVerticalBargraph = reinterpret_cast<addVerticalBargraphFun>(addVerticalBargraphGlueFloat);
        glue->addSoundfile = reinterpret_cast<addSoundfileFun>(addSoundfileGlueFloat);
        glue->declare = reinterpret_cast<declareFun>(declareGlueFloat);
    }
}
    
class UITemplate
{
    
    private:
        
        void* fCPPInterface;
        
    public:
        
        UITemplate(void* cpp_interface):fCPPInterface(cpp_interface)
        {}
        
        virtual ~UITemplate() {}
        
        // -- widget's layouts
        
        virtual void openTabBox(const char* label)
        {
            openTabBoxGlueFloat(fCPPInterface, label);
        }
        virtual void openHorizontalBox(const char* label)
        {
            openHorizontalBoxGlueFloat(fCPPInterface, label);
        }
        virtual void openVerticalBox(const char* label)
        {
            openVerticalBoxGlueFloat(fCPPInterface, label);
        }
        virtual void closeBox()
        {
            closeBoxGlueFloat(fCPPInterface);
        }
        
        // float version
        
        // -- active widgets
        
        virtual void addButton(const char* label, float* zone)
        {
            addButtonGlueFloat(fCPPInterface, label, zone);
        }
        virtual void addCheckButton(const char* label, float* zone)
        {
            addCheckButtonGlueFloat(fCPPInterface, label, zone);
        }
        
        virtual void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step)
        {
            addVerticalSliderGlueFloat(fCPPInterface, label, zone, init, min, max, step);
        }
        
        virtual void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step)
        {
            addHorizontalSliderGlueFloat(fCPPInterface, label, zone, init, min, max, step);
        }
        
        virtual void addNumEntry(const char* label, float* zone, float init, float min, float max, float step)
        {
            addNumEntryGlueFloat(fCPPInterface, label, zone, init, min, max, step);
        }
        
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, float* zone, float min, float max)
        {
            addHorizontalBargraphGlueFloat(fCPPInterface, label, zone, min, max);
        }
        
        virtual void addVerticalBargraph(const char* label, float* zone, float min, float max)
        {
            addVerticalBargraphGlueFloat(fCPPInterface, label, zone, min, max);
        }
    
        // -- metadata declarations
        
        virtual void declare(float* zone, const char* key, const char* val)
        {
            declareGlueFloat(fCPPInterface, zone, key, val);
        }
        
        // double version
        
        virtual void addButton(const char* label, double* zone)
        {
            addButtonGlueDouble(fCPPInterface, label, zone);
        }
        virtual void addCheckButton(const char* label, double* zone)
        {
            addCheckButtonGlueDouble(fCPPInterface, label, zone);
        }
        
        virtual void addVerticalSlider(const char* label, double* zone, double init, double min, double max, double step)
        {
            addVerticalSliderGlueDouble(fCPPInterface, label, zone, init, min, max, step);
        }
        
        virtual void addHorizontalSlider(const char* label, double* zone, double init, double min, double max, double step)
        {
            addHorizontalSliderGlueDouble(fCPPInterface, label, zone, init, min, max, step);
        }
        
        virtual void addNumEntry(const char* label, double* zone, double init, double min, double max, double step)
        {
            addNumEntryGlueDouble(fCPPInterface, label, zone, init, min, max, step);
        }
    
        // -- soundfiles
        
        virtual void addSoundfile(const char* label, const char* url, Soundfile** sf_zone)
        {
            addSoundfileGlueFloat(fCPPInterface, label, url, sf_zone);
        }
    
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, double* zone, double min, double max)
        {
            addHorizontalBargraphGlueDouble(fCPPInterface, label, zone, min, max);
        }
        
        virtual void addVerticalBargraph(const char* label, double* zone, double min, double max)
        {
            addVerticalBargraphGlueDouble(fCPPInterface, label, zone, min, max);
        }
    
        // -- metadata declarations
        
        virtual void declare(double* zone, const char* key, const char* val)
        {
            declareGlueDouble(fCPPInterface, zone, key, val);
        }

};

/*******************************************************************************
 * Meta glue code
 ******************************************************************************/

static void declareMetaGlue(void* cpp_interface, const char* key, const char* value)
{
    Meta* meta_interface = static_cast<Meta*>(cpp_interface);
    meta_interface->declare(key, value);
}

static void buildMetaGlue(MetaGlue* glue, Meta* meta)
{
    glue->metaInterface = meta;
    glue->declare = declareMetaGlue;
}
    
/*******************************************************************************
 * Memory manager glue code
 ******************************************************************************/

static void* allocateManagerGlue(void* cpp_interface, size_t size)
{
    dsp_memory_manager* manager_interface = static_cast<dsp_memory_manager*>(cpp_interface);
    return manager_interface->allocate(size);
}
    
static void destroyManagerGlue(void* cpp_interface, void* ptr)
{
    dsp_memory_manager* manager_interface = static_cast<dsp_memory_manager*>(cpp_interface);
    manager_interface->destroy(ptr);
}

static void buildManagerGlue(ManagerGlue* glue, dsp_memory_manager* manager)
{
    glue->managerInterface = manager;
    glue->allocate = allocateManagerGlue;
    glue->destroy = destroyManagerGlue;
}

#ifdef __cplusplus
}
#endif

#endif
/**************************  END  CGlue.h **************************/
/************************** BEGIN SimpleParser.h **************************/
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

struct itemInfo {
    std::string type;
    std::string label;
    std::string url;
    std::string address;
    int index;
    double init;
    double min;
    double max;
    double step;
    std::vector<std::pair<std::string, std::string> > meta;
    
    itemInfo():index(0), init(0.), min(0.), max(0.), step(0.)
    {}
};

// ---------------------------------------------------------------------
//                          Elementary parsers
// ---------------------------------------------------------------------

// Report a parsing error
static bool parseError(const char*& p, const char* errmsg)
{
    std::cerr << "Parse error : " << errmsg << " here : " << p << std::endl;
    return true;
}

/**
 * @brief skipBlank : advance pointer p to the first non blank character
 * @param p the string to parse, then the remaining string
 */
static void skipBlank(const char*& p)
{
    while (isspace(*p)) { p++; }
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
 * @brief parseChar : parse a specific character x
 * @param p the string to parse, then the remaining string
 * @param x the character to recognize
 * @return true if x was found at the begin of p
 */
static bool parseChar(const char*& p, char x)
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
static bool parseWord(const char*& p, const char* w)
{
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail
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
static bool parseDouble(const char*& p, double& x)
{
    double sign = +1.0;    // sign of the number
    double ipart = 0;      // integral part of the number
    double dpart = 0;      // decimal part of the number before division
    double dcoef = 1.0;    // division factor for the decimal part
    
    bool valid = false;    // true if the number contains at least one digit
    skipBlank(p);
    const char* saved = p; // to restore position if we fail
    
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
static bool parseString(const char*& p, char quote, std::string& s)
{
    std::string str;
    skipBlank(p);
    
    const char* saved = p;  // to restore position if we fail
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
static bool parseSQString(const char*& p, std::string& s)
{
    return parseString(p, '\'', s);
}

/**
 * @brief parseDQString, parse a double quoted string "..." and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseDQString(const char*& p, std::string& s)
{
    return parseString(p, '"', s);
}

// ---------------------------------------------------------------------
//
//                          IMPLEMENTATION
// 
// ---------------------------------------------------------------------

/**
 * @brief parseMenuItem, parse a menu item ...'low':440.0...
 * @param p the string to parse, then the remaining string
 * @param name the name found
 * @param value the value found
 * @return true if a nemu item was found
 */
static bool parseMenuItem(const char*& p, std::string& name, double& value)
{
    const char* saved = p;  // to restore position if we fail
    if (parseSQString(p, name) && parseChar(p, ':') && parseDouble(p, value)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

static bool parseMenuItem2(const char*& p, std::string& name)
{
    const char* saved = p;  // to restore position if we fail
    
    // single quoted
    if (parseSQString(p, name)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

/**
 * @brief parseMenuList, parse a menu list {'low' : 440.0; 'mid' : 880.0; 'hi' : 1760.0}...
 * @param p the string to parse, then the remaining string
 * @param names the vector of names found
 * @param values the vector of values found
 * @return true if a menu list was found
 */
static bool parseMenuList(const char*& p, std::vector<std::string>& names, std::vector<double>& values)
{
    std::vector<std::string> tmpnames;
    std::vector<double> tmpvalues;
    const char* saved = p; // to restore position if we fail

    if (parseChar(p, '{')) {
        do {
            std::string n;
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

static bool parseMenuList2(const char*& p, std::vector<std::string>& names, bool debug)
{
    std::vector<std::string> tmpnames;
    const char* saved = p;  // to restore position if we fail
    
    if (parseChar(p, '{')) {
        do {
            std::string n;
            if (parseMenuItem2(p, n)) {
                tmpnames.push_back(n);
            } else {
                goto error;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            return true;
        }
    }
    
error:
    if (debug) { std::cerr << "parseMenuList2 : (" << saved << ") is not a valid list !\n"; }
    p = saved;
    return false;
}

/// ---------------------------------------------------------------------
// Parse list of strings
/// ---------------------------------------------------------------------
static bool parseList(const char*& p, std::vector<std::string>& items)
{
    const char* saved = p;  // to restore position if we fail
    if (parseChar(p, '[')) {
        do {
            std::string item;
            if (!parseDQString(p, item)) {
                p = saved;
                return false;
            }
            items.push_back(item);
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        p = saved;
        return false;
    }
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
/// ---------------------------------------------------------------------
static bool parseGlobalMetaData(const char*& p, std::string& key, std::string& value, double& dbl, std::map<std::string, std::string>& metadatas, std::vector<std::string>& items)
{
    if (parseDQString(p, key)) {
        if (key == "meta") {
            return parseMetaData(p, metadatas);
        } else {
            return parseChar(p, ':') && (parseDQString(p, value) || parseList(p, items) || parseDouble(p, dbl));
        }
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse gui:
// "type" : "...", "label" : "...", "address" : "...", ...
// and store the result in uiItems Vector
/// ---------------------------------------------------------------------
static bool parseUI(const char*& p, std::vector<itemInfo>& uiItems, int& numItems)
{
    if (parseChar(p, '{')) {
   
        std::string label;
        std::string value;
        double dbl = 0;
        
        do {
            if (parseDQString(p, label)) {
                if (label == "type") {
                    if (uiItems.size() != 0) {
                        numItems++;
                    }
                    if (parseChar(p, ':') && parseDQString(p, value)) {   
                        itemInfo item;
                        item.type = value;
                        uiItems.push_back(item);
                    }
                }
                
                else if (label == "label") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].label = value;
                    }
                }
                
                else if (label == "url") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].url = value;
                    }
                }
                
                else if (label == "address") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        uiItems[numItems].address = value;
                    }
                }
                
                else if (label == "index") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].index = dbl;
                    }
                }
                
                else if (label == "meta") {
                    if (!parseItemMetaData(p, uiItems[numItems].meta)) {
                        return false;
                    }
                }
                
                else if (label == "init") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].init = dbl;
                    }
                }
                
                else if (label == "min") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].min = dbl;
                    }
                }
                
                else if (label == "max") {
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].max = dbl;
                    }
                }
                
                else if (label == "step"){
                    if (parseChar(p, ':') && parseDouble(p, dbl)) {
                        uiItems[numItems].step = dbl;
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
                            itemInfo item;
                            item.type = "close";
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
/// ---------------------------------------------------------------------
static bool parseJson(const char*& p,
                      std::map<std::string, std::pair<std::string, double> >& metaDatas0,
                      std::map<std::string, std::string>& metaDatas1,
                      std::map<std::string, std::vector<std::string> >& metaDatas2,
                      std::vector<itemInfo>& uiItems)
{
    parseChar(p, '{');
    
    do {
        std::string key;
        std::string value;
        double dbl = 0;
        std::vector<std::string> items;
        if (parseGlobalMetaData(p, key, value, dbl, metaDatas1, items)) {
            if (key != "meta") {
                // keep "name", "inputs", "outputs" key/value pairs
                if (items.size() > 0) {
                    metaDatas2[key] = items;
                    items.clear();
                } else if (value != "") {
                    metaDatas0[key].first = value;
                } else {
                    metaDatas0[key].second = dbl;
                }
            }
        } else if (key == "ui") {
            int numItems = 0;
            parseChar(p, '[') && parseUI(p, uiItems, numItems);
        }
    } while (tryChar(p, ','));
    
    return parseChar(p, '}');
}

#endif // SIMPLEPARSER_H
/**************************  END  SimpleParser.h **************************/

#ifdef _WIN32
#include <windows.h>
#define snprintf _snprintf
#endif

//-------------------------------------------------------------------
//  Decode a dsp JSON description and implement 'buildUserInterface'
//-------------------------------------------------------------------

#define REAL_UI(ui_interface)  reinterpret_cast<UIReal<REAL>*>(ui_interface)
#define REAL_ADR(offset)       reinterpret_cast<REAL*>(&memory_block[offset])
#define SOUNDFILE_ADR(offset)  reinterpret_cast<Soundfile**>(&memory_block[offset])

typedef std::function<void(double)> ReflectFunction;
typedef std::function<double()> ModifyFunction;

struct ExtZoneParam {

    virtual void reflectZone() = 0;
    virtual void modifyZone() = 0;
    
    virtual void setReflectZoneFun(ReflectFunction reflect) = 0;
    virtual void setModifyZoneFun(ModifyFunction modify) = 0;
    
};

template <typename REAL>
struct JSONUIDecoderAux {
    
    struct ZoneParam : public ExtZoneParam {
        
        REAL fZone;
        int fIndex;
        ReflectFunction fReflect;
        ModifyFunction fModify;
        
    #if defined(TARGET_OS_IPHONE) || defined(WIN32)
        ZoneParam(int index, ReflectFunction reflect = nullptr, ModifyFunction modify = nullptr)
        :fIndex(index), fReflect(reflect), fModify(modify)
        {}
        void reflectZone() { if (fReflect) fReflect(fZone); }
        void modifyZone() { if (fModify) fZone = fModify(); }
    #else
        ZoneParam(int index, ReflectFunction reflect = [](REAL value) {}, ModifyFunction modify = []() { return REAL(-1); })
        :fIndex(index), fReflect(reflect), fModify(modify)
        {}
        void reflectZone() { fReflect(fZone); }
        void modifyZone() { fZone = fModify(); }
    #endif
        
        void setReflectZoneFun(ReflectFunction reflect) { fReflect = reflect; }
        void setModifyZoneFun(ModifyFunction modify) { fModify = modify; }
        
    };

    typedef std::vector<ExtZoneParam*> controlMap;
  
    std::string fName;
    std::string fFileName;
    std::string fJSON;
    std::string fVersion;
    std::string fCompileOptions;
    
    std::map<std::string, std::string> fMetadata;
    std::vector<itemInfo> fUiItems;
    
    std::vector<std::string> fLibraryList;
    std::vector<std::string> fIncludePathnames;
    
    Soundfile** fSoundfiles;
    
    int fNumInputs, fNumOutputs, fSRIndex;
    int fSoundfileItems;
    int fDSPSize;
    
    controlMap fPathInputTable;     // [path, ZoneParam]
    controlMap fPathOutputTable;    // [path, ZoneParam]

    bool isInput(const std::string& type)
    {
        return (type == "vslider" || type == "hslider" || type == "nentry" || type == "button" || type == "checkbox");
    }
    bool isOutput(const std::string& type) { return (type == "hbargraph" || type == "vbargraph"); }
    bool isSoundfile(const std::string& type) { return (type == "soundfile"); }
    
    std::string getString(std::map<std::string, std::pair<std::string, double> >& map, const std::string& key)
    {
        return (map.find(key) != map.end()) ? map[key].first : "";
    }
    
    int getInt(std::map<std::string, std::pair<std::string, double> >& map, const std::string& key)
    {
        return (map.find(key) != map.end()) ? int(map[key].second) : -1;
    }
    
    void setReflectZoneFun(int index, ReflectFunction fun)
    {
        fPathInputTable[index]->setReflectZoneFun(fun);
    }
    
    void setModifyZoneFun(int index, ModifyFunction fun)
    {
        fPathOutputTable[index]->setModifyZoneFun(fun);
    }

    JSONUIDecoderAux(const std::string& json)
    {
        fJSON = json;
        const char* p = fJSON.c_str();
        std::map<std::string, std::pair<std::string, double> > meta_data1;
        std::map<std::string, std::vector<std::string> > meta_data2;
        parseJson(p, meta_data1, fMetadata, meta_data2, fUiItems);
        
        // meta_data1 contains <name : val>, <inputs : val>, <ouputs : val> pairs etc...
        fName = getString(meta_data1, "name");
        fFileName = getString(meta_data1, "filename");
        fVersion = getString(meta_data1, "version");
        fCompileOptions = getString(meta_data1, "compile_options");
        
        if (meta_data2.find("library_list") != meta_data2.end()) {
            fLibraryList = meta_data2["library_list"];
        }
        if (meta_data2.find("include_pathnames") != meta_data2.end()) {
            fIncludePathnames = meta_data2["include_pathnames"];
        }
        
        fDSPSize = getInt(meta_data1, "size");
        fNumInputs = getInt(meta_data1, "inputs");
        fNumOutputs = getInt(meta_data1, "outputs");
        fSRIndex = getInt(meta_data1, "sr_index");
       
        fSoundfileItems = 0;
        for (auto& it : fUiItems) {
            std::string type = it.type;
            if (isSoundfile(type)) {
                fSoundfileItems++;
            }
        }
        
        fSoundfiles = new Soundfile*[fSoundfileItems];
        
        // Prepare the fPathTable and init zone
        for (auto& it : fUiItems) {
            std::string type = it.type;
            // Meta data declaration for input items
            if (isInput(type)) {
                ZoneParam* param = new ZoneParam(it.index);
                fPathInputTable.push_back(param);
                param->fZone = it.init;
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                ZoneParam* param = new ZoneParam(it.index);
                fPathOutputTable.push_back(param);
                param->fZone = REAL(0);
            }
        }
    }
    
    virtual ~JSONUIDecoderAux()
    {
        delete [] fSoundfiles;
    }
    
    void metadata(Meta* m)
    {
        for (auto& it : fMetadata) {
            m->declare(it.first.c_str(), it.second.c_str());
        }
    }
    
    void metadata(MetaGlue* m)
    {
        for (auto& it : fMetadata) {
            m->declare(m->metaInterface, it.first.c_str(), it.second.c_str());
        }
    }
    
    void resetUserInterface()
    {
        int item = 0;
        for (auto& it : fUiItems) {
            if (isInput(it.type)) {
                static_cast<ZoneParam*>(fPathInputTable[item++])->fZone = it.init;
            }
        }
    }
    
    void resetUserInterface(char* memory_block, Soundfile* defaultsound = nullptr)
    {
        for (auto& it : fUiItems) {
            int offset = it.index;
            if (isInput(it.type)) {
                *REAL_ADR(offset) = it.init;
            } else if (isSoundfile(it.type)) {
                if (*SOUNDFILE_ADR(offset) == nullptr) {
                    *SOUNDFILE_ADR(offset) = defaultsound;
                }
            }
        }
    }
    
    int getSampleRate(char* memory_block)
    {
        return *reinterpret_cast<int*>(&memory_block[fSRIndex]);
    }
   
    void buildUserInterface(UI* ui_interface)
    {
        // MANDATORY: to be sure floats or double are correctly parsed
        char* tmp_local = setlocale(LC_ALL, nullptr);
        setlocale(LC_ALL, "C");
        
        int countIn = 0;
        int countOut = 0;
        int countSound = 0;
        
        for (auto& it : fUiItems) {
            
            std::string type = it.type;
            REAL init = it.init;
            REAL min = it.min;
            REAL max = it.max;
            REAL step = it.step;
            
            // Meta data declaration for input items
            if (isInput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(&static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(&static_cast<ZoneParam*>(fPathOutputTable[countOut])->fZone, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(0, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                REAL_UI(ui_interface)->openHorizontalBox(it.label.c_str());
            } else if (type == "vgroup") { 
                REAL_UI(ui_interface)->openVerticalBox(it.label.c_str());
            } else if (type == "tgroup") {
                REAL_UI(ui_interface)->openTabBox(it.label.c_str());
            } else if (type == "vslider") {
                REAL_UI(ui_interface)->addVerticalSlider(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, init, min, max, step);
            } else if (type == "hslider") {
                REAL_UI(ui_interface)->addHorizontalSlider(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, init, min, max, step);
            } else if (type == "checkbox") {
                REAL_UI(ui_interface)->addCheckButton(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone);
            } else if (type == "soundfile") {
                REAL_UI(ui_interface)->addSoundfile(it.label.c_str(), it.url.c_str(), &fSoundfiles[countSound]);
            } else if (type == "hbargraph") {
                REAL_UI(ui_interface)->addHorizontalBargraph(it.label.c_str(), &static_cast<ZoneParam*>(fPathOutputTable[countOut])->fZone, min, max);
            } else if (type == "vbargraph") {
                REAL_UI(ui_interface)->addVerticalBargraph(it.label.c_str(), &static_cast<ZoneParam*>(fPathOutputTable[countOut])->fZone, min, max);
            } else if (type == "nentry") {
                REAL_UI(ui_interface)->addNumEntry(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone, init, min, max, step);
            } else if (type == "button") {
                REAL_UI(ui_interface)->addButton(it.label.c_str(), &static_cast<ZoneParam*>(fPathInputTable[countIn])->fZone);
            } else if (type == "close") {
                REAL_UI(ui_interface)->closeBox();
            }
            
            if (isInput(type)) {
                countIn++;
            } else if (isOutput(type)) {
                countOut++;
            } else if (isSoundfile(type)) {
                countSound++;
            }
        }
        
        setlocale(LC_ALL, tmp_local);
    }
    
    void buildUserInterface(UI* ui_interface, char* memory_block)
    {
        // MANDATORY: to be sure floats or double are correctly parsed
        char* tmp_local = setlocale(LC_ALL, nullptr);
        setlocale(LC_ALL, "C");
        
        for (auto& it : fUiItems) {
            
            std::string type = it.type;
            int offset = it.index;
            REAL init = it.init;
            REAL min = it.min;
            REAL max = it.max;
            REAL step = it.step;
            
            // Meta data declaration for input items
            if (isInput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(REAL_ADR(offset), it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(REAL_ADR(offset), it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < it.meta.size(); i++) {
                    REAL_UI(ui_interface)->declare(0, it.meta[i].first.c_str(), it.meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                REAL_UI(ui_interface)->openHorizontalBox(it.label.c_str());
            } else if (type == "vgroup") {
                REAL_UI(ui_interface)->openVerticalBox(it.label.c_str());
            } else if (type == "tgroup") {
                REAL_UI(ui_interface)->openTabBox(it.label.c_str());
            } else if (type == "vslider") {
                REAL_UI(ui_interface)->addVerticalSlider(it.label.c_str(), REAL_ADR(offset), init, min, max, step);
            } else if (type == "hslider") {
                REAL_UI(ui_interface)->addHorizontalSlider(it.label.c_str(), REAL_ADR(offset), init, min, max, step);
            } else if (type == "checkbox") {
                REAL_UI(ui_interface)->addCheckButton(it.label.c_str(), REAL_ADR(offset));
            } else if (type == "soundfile") {
                REAL_UI(ui_interface)->addSoundfile(it.label.c_str(), it.url.c_str(), SOUNDFILE_ADR(offset));
            } else if (type == "hbargraph") {
                REAL_UI(ui_interface)->addHorizontalBargraph(it.label.c_str(), REAL_ADR(offset), min, max);
            } else if (type == "vbargraph") {
                REAL_UI(ui_interface)->addVerticalBargraph(it.label.c_str(), REAL_ADR(offset), min, max);
            } else if (type == "nentry") {
                REAL_UI(ui_interface)->addNumEntry(it.label.c_str(), REAL_ADR(offset), init, min, max, step);
            } else if (type == "button") {
                REAL_UI(ui_interface)->addButton(it.label.c_str(), REAL_ADR(offset));
            } else if (type == "close") {
                REAL_UI(ui_interface)->closeBox();
            }
        }
        
        setlocale(LC_ALL, tmp_local);
    }
    
    void buildUserInterface(UIGlue* ui_interface, char* memory_block)
    {
        // TODO
    }
    
    bool hasCompileOption(const std::string& option)
    {
        std::istringstream iss(fCompileOptions);
        std::string token;
        while (std::getline(iss, token, ' ')) {
            if (token == option) return true;
        }
        return false;
    }
    
};

// Templated decoder

struct JSONUITemplatedDecoder
{

    virtual ~JSONUITemplatedDecoder()
    {}
    
    virtual void metadata(Meta* m) = 0;
    virtual void metadata(MetaGlue* glue) = 0;
    virtual int getDSPSize() = 0;
    virtual std::string getName() = 0;
    virtual std::string getLibVersion() = 0;
    virtual std::string getCompileOptions() = 0;
    virtual std::vector<std::string> getLibraryList() = 0;
    virtual std::vector<std::string> getIncludePathnames() = 0;
    virtual int getNumInputs() = 0;
    virtual int getNumOutputs() = 0;
    virtual int getSampleRate(char* memory_block) = 0;
    virtual void setReflectZoneFun(int index, ReflectFunction fun) = 0;
    virtual void setModifyZoneFun(int index, ModifyFunction fun) = 0;
    virtual std::vector<ExtZoneParam*>& getInputControls() = 0;
    virtual std::vector<ExtZoneParam*>& getOutputControls() = 0;
    virtual void resetUserInterface(char* memory_block, Soundfile* defaultsound = nullptr) = 0;
    virtual void buildUserInterface(UI* ui_interface) = 0;
    virtual void buildUserInterface(UI* ui_interface, char* memory_block) = 0;
    virtual void buildUserInterface(UIGlue* ui_interface, char* memory_block) = 0;
    virtual bool hasCompileOption(const std::string& option) = 0;
};

struct JSONUIFloatDecoder : public JSONUIDecoderAux<float>, public JSONUITemplatedDecoder
{
    JSONUIFloatDecoder(const std::string& json):JSONUIDecoderAux<float>(json)
    {}
    
    void metadata(Meta* m) { JSONUIDecoderAux<float>::metadata(m); }
    void metadata(MetaGlue* glue) { JSONUIDecoderAux<float>::metadata(glue); }
    int getDSPSize() { return fDSPSize; }
    std::string getName() { return fName; }
    std::string getLibVersion() { return fVersion; }
    std::string getCompileOptions() { return fCompileOptions; }
    std::vector<std::string> getLibraryList() { return fLibraryList; }
    std::vector<std::string> getIncludePathnames() { return fIncludePathnames; }
    int getNumInputs() { return fNumInputs; }
    int getNumOutputs() { return fNumOutputs; }
    int getSampleRate(char* memory_block)  { return JSONUIDecoderAux<float>::getSampleRate(memory_block); }
    void setReflectZoneFun(int index, ReflectFunction fun)
    {
        JSONUIDecoderAux<float>::setReflectZoneFun(index, fun);
    }
    void setModifyZoneFun(int index, ModifyFunction fun)
    {
        JSONUIDecoderAux<float>::setModifyZoneFun(index, fun);
    }
    std::vector<ExtZoneParam*>& getInputControls()
    {
        return fPathInputTable;
    }
    std::vector<ExtZoneParam*>& getOutputControls()
    {
        return fPathOutputTable;
    }
    void resetUserInterface(char* memory_block, Soundfile* defaultsound = nullptr)
    {
        JSONUIDecoderAux<float>::resetUserInterface(memory_block, defaultsound);
    }
    void buildUserInterface(UI* ui_interface)
    {
        JSONUIDecoderAux<float>::buildUserInterface(ui_interface);
    }
    void buildUserInterface(UI* ui_interface, char* memory_block)
    {
        JSONUIDecoderAux<float>::buildUserInterface(ui_interface, memory_block);
    }
    void buildUserInterface(UIGlue* ui_interface, char* memory_block)
    {
        JSONUIDecoderAux<float>::buildUserInterface(ui_interface, memory_block);
    }
    bool hasCompileOption(const std::string& option) { return JSONUIDecoderAux<float>::hasCompileOption(option); }
};

struct JSONUIDoubleDecoder : public JSONUIDecoderAux<double>, public JSONUITemplatedDecoder
{
    JSONUIDoubleDecoder(const std::string& json):JSONUIDecoderAux<double>(json)
    {}
    
    void metadata(Meta* m) { JSONUIDecoderAux<double>::metadata(m); }
    void metadata(MetaGlue* glue) { JSONUIDecoderAux<double>::metadata(glue); }
    int getDSPSize() { return fDSPSize; }
    std::string getName() { return fName; }
    std::string getLibVersion() { return fVersion; }
    std::string getCompileOptions() { return fCompileOptions; }
    std::vector<std::string> getLibraryList() { return fLibraryList; }
    std::vector<std::string> getIncludePathnames() { return fIncludePathnames; }
    int getNumInputs() { return fNumInputs; }
    int getNumOutputs() { return fNumOutputs; }
    int getSampleRate(char* memory_block) { return JSONUIDecoderAux<double>::getSampleRate(memory_block); }
    void setReflectZoneFun(int index, ReflectFunction fun)
    {
        JSONUIDecoderAux<double>::setReflectZoneFun(index, fun);
    }
    void setModifyZoneFun(int index, ModifyFunction fun)
    {
        JSONUIDecoderAux<double>::setModifyZoneFun(index, fun);
    }
    std::vector<ExtZoneParam*>& getInputControls()
    {
        return fPathInputTable;
    }
    std::vector<ExtZoneParam*>& getOutputControls()
    {
        return fPathOutputTable;
    }
    void resetUserInterface(char* memory_block, Soundfile* defaultsound = nullptr)
    {
        JSONUIDecoderAux<double>::resetUserInterface(memory_block, defaultsound);
    }
    void buildUserInterface(UI* ui_interface)
    {
        JSONUIDecoderAux<double>::buildUserInterface(ui_interface);
    }
    void buildUserInterface(UI* ui_interface, char* memory_block)
    {
        JSONUIDecoderAux<double>::buildUserInterface(ui_interface, memory_block);
    }
    void buildUserInterface(UIGlue* ui_interface, char* memory_block)
    {
        JSONUIDecoderAux<double>::buildUserInterface(ui_interface, memory_block);
    }
    bool hasCompileOption(const std::string& option) { return JSONUIDecoderAux<double>::hasCompileOption(option); }
};

// FAUSTFLOAT decoder

struct JSONUIDecoder : public JSONUIDecoderAux<FAUSTFLOAT>
{
    JSONUIDecoder(const std::string& json):JSONUIDecoderAux<FAUSTFLOAT>(json)
    {}
};

static JSONUITemplatedDecoder* createJSONUIDecoder(const std::string& json)
{
    JSONUIDecoder decoder(json);
    if (decoder.hasCompileOption("-double")) {
        return new JSONUIDoubleDecoder(json);
    } else {
        return new JSONUIFloatDecoder(json);
    }
}

#endif
/**************************  END  JSONUIDecoder.h **************************/
/************************** BEGIN dsp-combiner.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2019 GRAME, Centre National de Creation Musicale
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
#include <string>
#include <assert.h>
#include <sstream>


// Base class and common code for binary combiners

class dsp_binary_combiner : public dsp {

    protected:

        dsp* fDSP1;
        dsp* fDSP2;

        void buildUserInterfaceAux(UI* ui_interface, const char* name)
        {
            ui_interface->openTabBox(name);
            ui_interface->openVerticalBox("DSP1");
            fDSP1->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->openVerticalBox("DSP2");
            fDSP2->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->closeBox();
        }

        FAUSTFLOAT** allocateChannels(int num, int buffer_size)
        {
            FAUSTFLOAT** channels = new FAUSTFLOAT*[num];
            for (int chan = 0; chan < num; chan++) {
                channels[chan] = new FAUSTFLOAT[buffer_size];
                memset(channels[chan], 0, sizeof(FAUSTFLOAT) * buffer_size);
            }
            return channels;
        }

        void deleteChannels(FAUSTFLOAT** channels, int num)
        {
            for (int chan = 0; chan < num; chan++) {
                delete [] channels[chan];
            }
            delete [] channels;
        }

     public:

        dsp_binary_combiner(dsp* dsp1, dsp* dsp2):fDSP1(dsp1), fDSP2(dsp2)
        {}

        virtual ~dsp_binary_combiner()
        {
            delete fDSP1;
            delete fDSP2;
        }

        virtual int getSampleRate()
        {
            return fDSP1->getSampleRate();
        }
        virtual void init(int sample_rate)
        {
            fDSP1->init(sample_rate);
            fDSP2->init(sample_rate);
        }
        virtual void instanceInit(int sample_rate)
        {
            fDSP1->instanceInit(sample_rate);
            fDSP2->instanceInit(sample_rate);
        }
        virtual void instanceConstants(int sample_rate)
        {
            fDSP1->instanceConstants(sample_rate);
            fDSP2->instanceConstants(sample_rate);
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

        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }

};

// Combine two 'compatible' DSP in sequence

class dsp_sequencer : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Outputs;

    public:

        dsp_sequencer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096):dsp_binary_combiner(dsp1, dsp2)
        {
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs(), buffer_size);
        }

        virtual ~dsp_sequencer()
        {
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface, "Sequencer");
        }

        virtual dsp* clone()
        {
            return new dsp_sequencer(fDSP1->clone(), fDSP2->clone());
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, fDSP1Outputs);
            fDSP2->compute(count, fDSP1Outputs, outputs);
        }

        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }

};

// Combine two DSP in parallel

class dsp_parallelizer : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP2Inputs;
        FAUSTFLOAT** fDSP2Outputs;

    public:

        dsp_parallelizer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096):dsp_binary_combiner(dsp1, dsp2)
        {
            fDSP2Inputs = new FAUSTFLOAT*[fDSP2->getNumInputs()];
            fDSP2Outputs = new FAUSTFLOAT*[fDSP2->getNumOutputs()];
        }

        virtual ~dsp_parallelizer()
        {
            delete [] fDSP2Inputs;
            delete [] fDSP2Outputs;
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs() + fDSP2->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs() + fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface, "Parallelizer");
        }

        virtual dsp* clone()
        {
            return new dsp_parallelizer(fDSP1->clone(), fDSP2->clone());
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, outputs);

            // Shift inputs/outputs channels for fDSP2
            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                fDSP2Inputs[chan] = inputs[fDSP1->getNumInputs() + chan];
            }
            for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                fDSP2Outputs[chan] = outputs[fDSP1->getNumOutputs() + chan];
            }

            fDSP2->compute(count, fDSP2Inputs, fDSP2Outputs);
        }

        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }

};

// Combine two 'compatible' DSP in splitter

class dsp_splitter : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Outputs;
        FAUSTFLOAT** fDSP2Inputs;

    public:

        dsp_splitter(dsp* dsp1, dsp* dsp2, int buffer_size = 4096):dsp_binary_combiner(dsp1, dsp2)
        {
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs(), buffer_size);
            fDSP2Inputs = new FAUSTFLOAT*[fDSP2->getNumInputs()];
        }

        virtual ~dsp_splitter()
        {
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
            delete [] fDSP2Inputs;
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface, "Splitter");
        }

        virtual dsp* clone()
        {
            return new dsp_splitter(fDSP1->clone(), fDSP2->clone());
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, fDSP1Outputs);

            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                 fDSP2Inputs[chan] = fDSP1Outputs[chan % fDSP1->getNumOutputs()];
            }

            fDSP2->compute(count, fDSP2Inputs, outputs);
        }
};

// Combine two 'compatible' DSP in merger

class dsp_merger : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Inputs;
        FAUSTFLOAT** fDSP1Outputs;
        FAUSTFLOAT** fDSP2Inputs;

        void mix(int count, FAUSTFLOAT* dst, FAUSTFLOAT* src)
        {
            for (int frame = 0; frame < count; frame++) {
                dst[frame] += src[frame];
            }
        }

    public:

        dsp_merger(dsp* dsp1, dsp* dsp2, int buffer_size = 4096):dsp_binary_combiner(dsp1, dsp2)
        {
            fDSP1Inputs = allocateChannels(fDSP1->getNumInputs(), buffer_size);
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs(), buffer_size);
            fDSP2Inputs = new FAUSTFLOAT*[fDSP2->getNumInputs()];
        }

        virtual ~dsp_merger()
        {
            deleteChannels(fDSP1Inputs, fDSP1->getNumInputs());
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
            delete [] fDSP2Inputs;
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface, "Merge");
        }

        virtual dsp* clone()
        {
            return new dsp_merger(fDSP1->clone(), fDSP2->clone());
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, fDSP1Inputs, fDSP1Outputs);

            memset(fDSP2Inputs, 0, sizeof(FAUSTFLOAT*) * fDSP2->getNumInputs());

            for (int chan = 0; chan < fDSP1->getNumOutputs(); chan++) {
                int mchan = chan % fDSP2->getNumInputs();
                if (fDSP2Inputs[mchan]) {
                    mix(count, fDSP2Inputs[mchan], fDSP1Outputs[chan]);
                } else {
                    fDSP2Inputs[mchan] = fDSP1Outputs[chan];
                }
            }

            fDSP2->compute(count, fDSP2Inputs, outputs);
        }
};

// Combine two 'compatible' DSP in a recursive way

class dsp_recursiver : public dsp_binary_combiner {

    private:

        FAUSTFLOAT** fDSP1Inputs;
        FAUSTFLOAT** fDSP1Outputs;

        FAUSTFLOAT** fDSP2Inputs;
        FAUSTFLOAT** fDSP2Outputs;

    public:

        dsp_recursiver(dsp* dsp1, dsp* dsp2):dsp_binary_combiner(dsp1, dsp2)
        {
            fDSP1Inputs = allocateChannels(fDSP1->getNumInputs(), 1);
            fDSP1Outputs = allocateChannels(fDSP1->getNumOutputs(), 1);
            fDSP2Inputs = allocateChannels(fDSP2->getNumInputs(), 1);
            fDSP2Outputs = allocateChannels(fDSP2->getNumOutputs(), 1);
        }

        virtual ~dsp_recursiver()
        {
            deleteChannels(fDSP1Inputs, fDSP1->getNumInputs());
            deleteChannels(fDSP1Outputs, fDSP1->getNumOutputs());
            deleteChannels(fDSP2Inputs, fDSP2->getNumInputs());
            deleteChannels(fDSP2Outputs, fDSP2->getNumOutputs());
        }

        virtual int getNumInputs() { return fDSP1->getNumInputs() - fDSP2->getNumOutputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs(); }

        virtual void buildUserInterface(UI* ui_interface)
        {
            buildUserInterfaceAux(ui_interface, "Recursiver");
        }

        virtual dsp* clone()
        {
            return new dsp_recursiver(fDSP1->clone(), fDSP2->clone());
        }

        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            for (int frame = 0; (frame < count); frame++) {

                for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                    fDSP1Inputs[chan][0] = fDSP2Outputs[chan][0];
                }

                for (int chan = 0; chan < fDSP1->getNumInputs() - fDSP2->getNumOutputs(); chan++) {
                    fDSP1Inputs[chan + fDSP2->getNumOutputs()][0] = inputs[chan][frame];
                }

                fDSP1->compute(1, fDSP1Inputs, fDSP1Outputs);

                for (int chan = 0; chan < fDSP1->getNumOutputs(); chan++) {
                    outputs[chan][frame] = fDSP1Outputs[chan][0];
                }

                for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                    fDSP2Inputs[chan][0] = fDSP1Outputs[chan][0];
                }

                fDSP2->compute(1, fDSP2Inputs, fDSP2Outputs);
            }
        }

        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }

};

#ifndef __dsp_algebra_api__
#define __dsp_algebra_api__
// DSP algebra API
/*
 Each operation takes two DSP as parameters, returns the combined DSPs, or null if failure with an error message.
 */

static dsp* createDSPSequencer(dsp* dsp1, dsp* dsp2, std::string& error)
{
    if (dsp1->getNumOutputs() != dsp2->getNumInputs()) {
        std::stringstream error_aux;
        error_aux << "Connection error int dsp_sequencer : the number of outputs ("
                  << dsp1->getNumOutputs() << ") of A "
                  << "must be equal to the number of inputs (" << dsp2->getNumInputs() << ") of B" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else {
        return new dsp_sequencer(dsp1, dsp2);
    }
}

static dsp* createDSPParallelize(dsp* dsp1, dsp* dsp2, std::string& error)
{
    return new dsp_parallelizer(dsp1, dsp2);
}

static dsp* createDSPSplitter(dsp* dsp1, dsp* dsp2, std::string& error)
{
    if (dsp1->getNumOutputs() == 0) {
        error = "Connection error in dsp_splitter : the first expression has no outputs\n";
        return nullptr;
    } else if (dsp2->getNumInputs() == 0) {
        error = "Connection error in dsp_splitter : the second expression has no inputs\n";
        return nullptr;
    } else if (dsp2->getNumInputs() % dsp1->getNumOutputs() != 0) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_splitter : the number of outputs (" << dsp1->getNumOutputs()
                  << ") of the first expression should be a divisor of the number of inputs ("
                  << dsp2->getNumInputs()
                  << ") of the second expression" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else if (dsp2->getNumInputs() == dsp1->getNumOutputs()) {
        return new dsp_sequencer(dsp1, dsp2);
    } else {
        return new dsp_splitter(dsp1, dsp2);
    }
}

static dsp* createDSPMerger(dsp* dsp1, dsp* dsp2, std::string& error)
{
    if (dsp1->getNumOutputs() == 0) {
        error = "Connection error in dsp_merger : the first expression has no outputs\n";
        return nullptr;
    } else if (dsp2->getNumInputs() == 0) {
        error = "Connection error in dsp_merger : the second expression has no inputs\n";
        return nullptr;
    } else if (dsp1->getNumOutputs() % dsp2->getNumInputs() != 0) {
        std::stringstream error_aux;
        error_aux << "Connection error in dsp_merger : the number of outputs (" << dsp1->getNumOutputs()
                  << ") of the first expression should be a multiple of the number of inputs ("
                  << dsp2->getNumInputs()
                  << ") of the second expression" << std::endl;
        error = error_aux.str();
        return nullptr;
    } else if (dsp2->getNumInputs() == dsp1->getNumOutputs()) {
        return new dsp_sequencer(dsp1, dsp2);
    } else {
        return new dsp_merger(dsp1, dsp2);
    }
}

static dsp* createDSPRecursiver(dsp* dsp1, dsp* dsp2, std::string& error)
{
    if ((dsp2->getNumInputs() > dsp1->getNumOutputs()) || (dsp2->getNumOutputs() > dsp1->getNumInputs())) {
        std::stringstream error_aux;
        error_aux << "Connection error in : dsp_recursiver" << std::endl;
        if (dsp2->getNumInputs() > dsp1->getNumOutputs()) {
            error_aux << "The number of outputs " << dsp1->getNumOutputs()
                      << " of the first expression should be greater or equal to the number of inputs ("
                      << dsp2->getNumInputs()
                      << ") of the second expression" << std::endl;
        }
        if (dsp2->getNumOutputs() > dsp1->getNumInputs()) {
            error_aux << "The number of inputs " << dsp1->getNumInputs()
                      << " of the first expression should be greater or equal to the number of outputs ("
                      << dsp2->getNumOutputs()
                      << ") of the second expression" << std::endl;
        }
        error = error_aux.str();
        return nullptr;
    } else {
        return new dsp_recursiver(dsp1, dsp2);
    }
}
#endif

#endif
/**************************  END  dsp-combiner.h **************************/
/************************** BEGIN misc.h **************************/
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
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <string>


using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key] = value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key] = value; }
};

static int lsr(int x, int n) { return int(((unsigned int)x) >> n); }

static int int2pow2(int x) { int r = 0; while ((1<<r) < x) r++; return r; }

static long lopt(char* argv[], const char* name, long def)
{
	int	i;
    for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return std::atoi(argv[i+1]);
	return def;
}

static bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

static const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

static std::string pathToContent(const std::string& path)
{
    std::ifstream file(path.c_str(), std::ifstream::binary);
    
    file.seekg(0, file.end);
    int size = int(file.tellg());
    file.seekg(0, file.beg);
    
    // And allocate buffer to that a single line can be read...
    char* buffer = new char[size + 1];
    file.read(buffer, size);
    
    // Terminate the string
    buffer[size] = 0;
    std::string result = buffer;
    file.close();
    delete [] buffer;
    return result;
}

#endif

/**************************  END  misc.h **************************/

// Always included
/************************** BEGIN OSCUI.h **************************/
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

#ifndef __OSCUI__
#define __OSCUI__

#include <vector>
#include <string>

/*

  Faust Project

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __OSCControler__
#define __OSCControler__

#include <string>
/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __FaustFactory__
#define __FaustFactory__

#include <stack>
#include <string>
#include <sstream>

/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __FaustNode__
#define __FaustNode__

#include <string>
#include <vector>

/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __MessageDriven__
#define __MessageDriven__

#include <string>
#include <vector>

/*

  Copyright (C) 2010  Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __MessageProcessor__
#define __MessageProcessor__

namespace oscfaust
{

class Message;
//--------------------------------------------------------------------------
/*!
	\brief an abstract class for objects able to process OSC messages	
*/
class MessageProcessor
{
	public:
		virtual		~MessageProcessor() {}
		virtual void processMessage( const Message* msg ) = 0;
};

} // end namespoace

#endif
/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __smartpointer__
#define __smartpointer__

#include <cassert>

namespace oscfaust
{

/*!
\brief the base class for smart pointers implementation

	Any object that want to support smart pointers should
	inherit from the smartable class which provides reference counting
	and automatic delete when the reference count drops to zero.
*/
class smartable {
	private:
		unsigned 	refCount;		
	public:
		//! gives the reference count of the object
		unsigned refs() const         { return refCount; }
		//! addReference increments the ref count and checks for refCount overflow
		void addReference()           { refCount++; assert(refCount != 0); }
		//! removeReference delete the object when refCount is zero		
		void removeReference()		  { if (--refCount == 0) delete this; }
		
	protected:
		smartable() : refCount(0) {}
		smartable(const smartable&): refCount(0) {}
		//! destructor checks for non-zero refCount
		virtual ~smartable()    
        { 
            /* 
                See "Static SFaustNode create (const char* name, C* zone, C init, C min, C max, const char* prefix, GUI* ui)" comment.
                assert (refCount == 0); 
            */
        }
		smartable& operator=(const smartable&) { return *this; }
};

/*!
\brief the smart pointer implementation

	A smart pointer is in charge of maintaining the objects reference count 
	by the way of pointers operators overloading. It supports class 
	inheritance and conversion whenever possible.
\n	Instances of the SMARTP class are supposed to use \e smartable types (or at least
	objects that implements the \e addReference and \e removeReference
	methods in a consistent way).
*/
template<class T> class SMARTP {
	private:
		//! the actual pointer to the class
		T* fSmartPtr;

	public:
		//! an empty constructor - points to null
		SMARTP()	: fSmartPtr(0) {}
		//! build a smart pointer from a class pointer
		SMARTP(T* rawptr) : fSmartPtr(rawptr)              { if (fSmartPtr) fSmartPtr->addReference(); }
		//! build a smart pointer from an convertible class reference
		template<class T2> 
		SMARTP(const SMARTP<T2>& ptr) : fSmartPtr((T*)ptr) { if (fSmartPtr) fSmartPtr->addReference(); }
		//! build a smart pointer from another smart pointer reference
		SMARTP(const SMARTP& ptr) : fSmartPtr((T*)ptr)     { if (fSmartPtr) fSmartPtr->addReference(); }

		//! the smart pointer destructor: simply removes one reference count
		~SMARTP()  { if (fSmartPtr) fSmartPtr->removeReference(); }
		
		//! cast operator to retrieve the actual class pointer
		operator T*() const  { return fSmartPtr;	}

		//! '*' operator to access the actual class pointer
		T& operator*() const {
			// checks for null dereference
			assert (fSmartPtr != 0);
			return *fSmartPtr;
		}

		//! operator -> overloading to access the actual class pointer
		T* operator->() const	{ 
			// checks for null dereference
			assert (fSmartPtr != 0);
			return fSmartPtr;
		}

		//! operator = that moves the actual class pointer
		template <class T2>
		SMARTP& operator=(T2 p1_)	{ *this=(T*)p1_; return *this; }

		//! operator = that moves the actual class pointer
		SMARTP& operator=(T* p_)	{
			// check first that pointers differ
			if (fSmartPtr != p_) {
				// increments the ref count of the new pointer if not null
				if (p_ != 0) p_->addReference();
				// decrements the ref count of the old pointer if not null
				if (fSmartPtr != 0) fSmartPtr->removeReference();
				// and finally stores the new actual pointer
				fSmartPtr = p_;
			}
			return *this;
		}
		//! operator < to support SMARTP map with Visual C++
		bool operator<(const SMARTP<T>& p_)	const			  { return fSmartPtr < ((T *) p_); }
		//! operator = to support inherited class reference
		SMARTP& operator=(const SMARTP<T>& p_)                { return operator=((T *) p_); }
		//! dynamic cast support
		template<class T2> SMARTP& cast(T2* p_)               { return operator=(dynamic_cast<T*>(p_)); }
		//! dynamic cast support
		template<class T2> SMARTP& cast(const SMARTP<T2>& p_) { return operator=(dynamic_cast<T*>(p_)); }
};

}

#endif

namespace oscfaust
{

class Message;
class OSCRegexp;
class MessageDriven;
typedef class SMARTP<MessageDriven>	SMessageDriven;

//--------------------------------------------------------------------------
/*!
	\brief a base class for objects accepting OSC messages
	
	Message driven objects are hierarchically organized in a tree.
	They provides the necessary to dispatch an OSC message to its destination
	node, according to the message OSC address. 
	
	The principle of the dispatch is the following:
	- first the processMessage() method should be called on the top level node
	- next processMessage call propose 
*/
class MessageDriven : public MessageProcessor, public smartable
{
	std::string						fName;			///< the node name
	std::string						fOSCPrefix;		///< the node OSC address prefix (OSCAddress = fOSCPrefix + '/' + fName)
	std::vector<SMessageDriven>		fSubNodes;		///< the subnodes of the current node

	protected:
				 MessageDriven(const char *name, const char *oscprefix) : fName (name), fOSCPrefix(oscprefix) {}
		virtual ~MessageDriven() {}

	public:
		static SMessageDriven create(const char* name, const char *oscprefix)	{ return new MessageDriven(name, oscprefix); }

		/*!
			\brief OSC message processing method.
			\param msg the osc message to be processed
			The method should be called on the top level node.
		*/
		virtual void	processMessage(const Message* msg);

		/*!
			\brief propose an OSc message at a given hierarchy level.
			\param msg the osc message currently processed
			\param regexp a regular expression based on the osc address head
			\param addrTail the osc address tail
			
			The method first tries to match the regular expression with the object name. 
			When it matches:
			- it calls \c accept when \c addrTail is empty 
			- or it \c propose the message to its subnodes when \c addrTail is not empty. 
			  In this case a new \c regexp is computed with the head of \c addrTail and a new \c addrTail as well.
		*/
		virtual void	propose(const Message* msg, const OSCRegexp* regexp, const std::string addrTail);

		/*!
			\brief accept an OSC message. 
			\param msg the osc message currently processed
			\return true when the message is processed by the node
			
			The method is called only for the destination nodes. The real message acceptance is the node 
			responsability and may depend on the message content.
		*/
		virtual bool	accept(const Message* msg);

		/*!
			\brief handler for the \c 'get' message
			\param ipdest the output message destination IP
			
			The \c 'get' message is supported by every node:
			- it is propagated to the subnodes until it reaches terminal nodes
			- a terminal node send its state on \c 'get' request to the IP address given as parameter.
			The \c get method is basically called by the accept method.
		*/
		virtual void	get(unsigned long ipdest) const;

		/*!
			\brief handler for the \c 'get' 'attribute' message
			\param ipdest the output message destination IP
			\param what the requested attribute
			
			The \c 'get' message is supported by every node:
			- it is propagated to the subnodes until it reaches terminal nodes
			- a terminal node send its state on \c 'get' request to the IP address given as parameter.
			The \c get method is basically called by the accept method.
		*/
		virtual void	get (unsigned long ipdest, const std::string & what) const {}

		void			add(SMessageDriven node)	{ fSubNodes.push_back (node); }
		const char*		getName() const				{ return fName.c_str(); }
		std::string		getOSCAddress() const;
		int				size() const				{ return (int)fSubNodes.size (); }
		
		const std::string&	name() const			{ return fName; }
		SMessageDriven	subnode(int i)              { return fSubNodes[i]; }
};

} // end namespoace

#endif
/*

  Copyright (C) 2011  Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/


#ifndef __Message__
#define __Message__

#include <string>
#include <vector>

namespace oscfaust
{

class OSCStream;
template <typename T> class MsgParam;
class baseparam;
typedef SMARTP<baseparam>	Sbaseparam;

//--------------------------------------------------------------------------
/*!
	\brief base class of a message parameters
*/
class baseparam : public smartable
{
	public:
		virtual ~baseparam() {}

		/*!
		 \brief utility for parameter type checking
		*/
		template<typename X> bool isType() const { return dynamic_cast<const MsgParam<X>*> (this) != 0; }
		/*!
		 \brief utility for parameter convertion
		 \param errvalue the returned value when no conversion applies
		 \return the parameter value when the type matches
		*/
		template<typename X> X	value(X errvalue) const 
			{ const MsgParam<X>* o = dynamic_cast<const MsgParam<X>*> (this); return o ? o->getValue() : errvalue; }
		/*!
		 \brief utility for parameter comparison
		*/
		template<typename X> bool	equal(const baseparam& p) const 
			{ 
				const MsgParam<X>* a = dynamic_cast<const MsgParam<X>*> (this); 
				const MsgParam<X>* b = dynamic_cast<const MsgParam<X>*> (&p);
				return a && b && (a->getValue() == b->getValue());
			}
		/*!
		 \brief utility for parameter comparison
		*/
		bool operator==(const baseparam& p) const 
			{ 
				return equal<float>(p) || equal<int>(p) || equal<std::string>(p);
			}
		bool operator!=(const baseparam& p) const
			{ 
				return !equal<float>(p) && !equal<int>(p) && !equal<std::string>(p);
			}
			
		virtual SMARTP<baseparam> copy() const = 0;
};

//--------------------------------------------------------------------------
/*!
	\brief template for a message parameter
*/
template <typename T> class MsgParam : public baseparam
{
	T fParam;
	public:
				 MsgParam(T val) : fParam(val)	{}
		virtual ~MsgParam() {}
		
		T getValue() const { return fParam; }
		
		virtual Sbaseparam copy() const { return new MsgParam<T>(fParam); }
};

//--------------------------------------------------------------------------
/*!
	\brief a message description
	
	A message is composed of an address (actually an OSC address),
	a message string that may be viewed as a method name
	and a list of message parameters.
*/
class Message
{
    public:
        typedef SMARTP<baseparam>		argPtr;		///< a message argument ptr type
        typedef std::vector<argPtr>		argslist;	///< args list type

    private:
        unsigned long	fSrcIP;			///< the message source IP number
        std::string	fAddress;			///< the message osc destination address
        std::string	fAlias;             ///< the message alias osc destination address
        argslist	fArguments;			///< the message arguments

    public:
            /*!
                \brief an empty message constructor
            */
             Message() {}
            /*!
                \brief a message constructor
                \param address the message destination address
            */
            Message(const std::string& address) : fAddress(address), fAlias("") {}
             
            Message(const std::string& address, const std::string& alias) : fAddress(address), fAlias(alias) {}
            /*!
                \brief a message constructor
                \param address the message destination address
                \param args the message parameters
            */
            Message(const std::string& address, const argslist& args) 
                : fAddress(address), fArguments(args) {}
            /*!
                \brief a message constructor
                \param msg a message
            */
             Message(const Message& msg);
    virtual ~Message() {} //{ freed++; std::cout << "running messages: " << (allocated - freed) << std::endl; }

    /*!
        \brief adds a parameter to the message
        \param val the parameter
    */
    template <typename T> void add(T val)	{ fArguments.push_back(new MsgParam<T>(val)); }
    /*!
        \brief adds a float parameter to the message
        \param val the parameter value
    */
    void	add(float val)					{ add<float>(val); }
    /*!
        \brief adds an int parameter to the message
        \param val the parameter value
    */
    void	add(int val)					{ add<int>(val); }
    /*!
        \brief adds a string parameter to the message
        \param val the parameter value
    */
    void	add(const std::string& val)		{ add<std::string>(val); }

    /*!
        \brief adds a parameter to the message
        \param val the parameter
    */
    void	add(argPtr val)                 { fArguments.push_back( val ); }

    /*!
        \brief sets the message address
        \param addr the address
    */
    void				setSrcIP(unsigned long addr)		{ fSrcIP = addr; }

    /*!
        \brief sets the message address
        \param addr the address
    */
    void				setAddress(const std::string& addr)		{ fAddress = addr; }
    /*!
        \brief print the message
        \param out the output stream
    */
    void				print(std::ostream& out) const;
    /*!
        \brief send the message to OSC
        \param out the OSC output stream
    */
    void				print(OSCStream& out) const;
    /*!
        \brief print message arguments
        \param out the OSC output stream
    */
    void				printArgs(OSCStream& out) const;

    /// \brief gives the message address
    const std::string&	address() const		{ return fAddress; }
    /// \brief gives the message alias
    const std::string&	alias() const		{ return fAlias; }
    /// \brief gives the message parameters list
    const argslist&		params() const		{ return fArguments; }
    /// \brief gives the message parameters list
    argslist&			params()			{ return fArguments; }
    /// \brief gives the message source IP 
    unsigned long		src() const			{ return fSrcIP; }
    /// \brief gives the message parameters count
    int					size() const		{ return (int)fArguments.size(); }

    bool operator == (const Message& other) const;	

    /*!
        \brief gives a message float parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, float& val) const		{ val = params()[i]->value<float>(val); return params()[i]->isType<float>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, int& val) const		{ val = params()[i]->value<int>(val); return params()[i]->isType<int>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, unsigned int& val) const		{ val = params()[i]->value<int>(val); return params()[i]->isType<int>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
        \note a boolean value is handled as integer
    */
    bool	param(int i, bool& val) const		{ int ival = 0; ival = params()[i]->value<int>(ival); val = ival!=0; return params()[i]->isType<int>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, long int& val) const	{ val = long(params()[i]->value<int>(val)); return params()[i]->isType<int>(); }
    /*!
        \brief gives a message string parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, std::string& val) const { val = params()[i]->value<std::string>(val); return params()[i]->isType<std::string>(); }
};


} // end namespoace

#endif
/************************** BEGIN GUI.h **************************/
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

/************************** BEGIN ring-buffer.h **************************/
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
# pragma warning (disable: 4334)
#else
# pragma GCC diagnostic ignored "-Wunused-function"
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

static ringbuffer_t *ringbuffer_create(size_t sz);
static void ringbuffer_free(ringbuffer_t *rb);
static void ringbuffer_get_read_vector(const ringbuffer_t *rb,
                                         ringbuffer_data_t *vec);
static void ringbuffer_get_write_vector(const ringbuffer_t *rb,
                                          ringbuffer_data_t *vec);
static size_t ringbuffer_read(ringbuffer_t *rb, char *dest, size_t cnt);
static size_t ringbuffer_peek(ringbuffer_t *rb, char *dest, size_t cnt);
static void ringbuffer_read_advance(ringbuffer_t *rb, size_t cnt);
static size_t ringbuffer_read_space(const ringbuffer_t *rb);
static int ringbuffer_mlock(ringbuffer_t *rb);
static void ringbuffer_reset(ringbuffer_t *rb);
static void ringbuffer_reset_size (ringbuffer_t * rb, size_t sz);
static size_t ringbuffer_write(ringbuffer_t *rb, const char *src,
                                 size_t cnt);
static void ringbuffer_write_advance(ringbuffer_t *rb, size_t cnt);
static size_t ringbuffer_write_space(const ringbuffer_t *rb);

/* Create a new ringbuffer to hold at least `sz' bytes of data. The
   actual buffer size is rounded up to the next power of two. */

static ringbuffer_t *
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

static void
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

static int
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

static void
ringbuffer_reset (ringbuffer_t * rb)
{
	rb->read_ptr = 0;
	rb->write_ptr = 0;
    memset(rb->buf, 0, rb->size);
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

static void
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

static size_t
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

static size_t
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

static size_t
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

static size_t
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

static size_t
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

static void
ringbuffer_read_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->read_ptr + cnt) & rb->size_mask;
	rb->read_ptr = tmp;
}

/* Advance the write pointer `cnt' places. */

static void
ringbuffer_write_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->write_ptr + cnt) & rb->size_mask;
	rb->write_ptr = tmp;
}

/* The non-copying data reader. `vec' is an array of two places. Set
   the values at `vec' to hold the current readable data at `rb'. If
   the readable data is in one segment the second segment has zero
   length. */

static void
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

static void
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
/**************************  END  ring-buffer.h **************************/

/*******************************************************************************
 * GUI : Abstract Graphic User Interface
 * Provides additional mechanisms to synchronize widgets and zones. Widgets
 * should both reflect the value of a zone and allow to change this value.
 ******************************************************************************/

class uiItem;
class GUI;
struct clist;

typedef void (*uiCallback)(FAUSTFLOAT val, void* data);

struct uiItemBase
{
    
    uiItemBase(GUI* ui, FAUSTFLOAT* zone) {}
    
    virtual ~uiItemBase()
    {}
    
    virtual void modifyZone(FAUSTFLOAT v) = 0;
    virtual void modifyZone(double date, FAUSTFLOAT v) {}
    virtual double cache() = 0;
    virtual void reflectZone() = 0;
};


static void deleteClist(clist* cl);

struct clist : public std::list<uiItemBase*>
{
    
    virtual ~clist()
    {
        deleteClist(this);
    }
        
};

static void createUiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data);

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
        
        void registerZone(FAUSTFLOAT* z, uiItemBase* c)
        {
            if (fZoneMap.find(z) == fZoneMap.end()) fZoneMap[z] = new clist();
            fZoneMap[z]->push_back(c);
        }
 
        void updateAllZones()
        {
            for (zmap::iterator m = fZoneMap.begin(); m != fZoneMap.end(); m++) {
                FAUSTFLOAT* z = m->first;
                clist* l = m->second;
                if (z) {
                    FAUSTFLOAT v = *z;
                    for (clist::iterator c = l->begin(); c != l->end(); c++) {
                        if ((*c)->cache() != v) (*c)->reflectZone();
                    }
                }
            }
        }
        
        void updateZone(FAUSTFLOAT* z)
        {
            FAUSTFLOAT v = *z;
            clist* l = fZoneMap[z];
            for (clist::iterator c = l->begin(); c != l->end(); c++) {
                if ((*c)->cache() != v) (*c)->reflectZone();
            }
        }
    
        static void updateAllGuis()
        {
            std::list<GUI*>::iterator g;
            for (g = fGuiList.begin(); g != fGuiList.end(); g++) {
                (*g)->updateAllZones();
            }
        }
    
        void addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data)
        {
            createUiCallbackItem(this, zone, foo, data);
        }

        virtual void show() {};	
        virtual bool run() { return false; };

        static void runAllGuis() {
            std::list<GUI*>::iterator g;
            for (g = fGuiList.begin(); g != fGuiList.end(); g++) {
                (*g)->run();
            }
        }
    
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

template <typename REAL>
class uiTypedItem : public uiItemBase
{
    protected:
        
        GUI* fGUI;
        REAL* fZone;
        REAL fCache;
        
        uiTypedItem(GUI* ui, REAL* zone):uiItemBase(ui, static_cast<FAUSTFLOAT*>(zone)),
        fGUI(ui), fZone(zone), fCache(REAL(-123456.654321))
        {
            ui->registerZone(zone, this);
        }
        
    public:
        
        virtual ~uiTypedItem()
        {}
    
        void modifyZone(REAL v)
        {
            fCache = v;
            if (*fZone != v) {
                *fZone = v;
                fGUI->updateZone(fZone);
            }
        }
    
        double cache() { return fCache; }
    
};

class uiItem : public uiTypedItem<FAUSTFLOAT> {
    
    protected:
    
        uiItem(GUI* ui, FAUSTFLOAT* zone):uiTypedItem<FAUSTFLOAT>(ui, zone)
        {}

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

class uiCallbackItem : public uiItem {
    
    protected:
    
        uiCallback fCallback;
        void* fData;
    
    public:
    
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
 *  For timestamped control
 */

struct DatedControl {
    
    double fDate;
    FAUSTFLOAT fValue;
    
    DatedControl(double d = 0., FAUSTFLOAT v = FAUSTFLOAT(0)):fDate(d), fValue(v) {}
    
};

/**
 * Base class for timed items
 */

class uiTimedItem : public uiItem
{
    
    protected:
        
        bool fDelete;
        
    public:
    
        using uiItem::modifyZone;
        
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

// Can not be defined as method in the classes

static void createUiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data)
{
    new uiCallbackItem(ui, zone, foo, data);
}

static void deleteClist(clist* cl)
{
    std::list<uiItemBase*>::iterator it;
    for (it = cl->begin(); it != cl->end(); it++) {
        uiOwnedItem* owned = dynamic_cast<uiOwnedItem*>(*it);
        // owned items are deleted by external code
        if (!owned) {
            delete (*it);
        }
    }
}

#endif
/**************************  END  GUI.h **************************/
/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __RootNode__
#define __RootNode__

#include <map>
#include <string>
#include <vector>


namespace oscfaust
{

class OSCIO;
class RootNode;
typedef class SMARTP<RootNode> SRootNode;

/**
 * an alias target includes a map to rescale input values to output values
 * and a target osc address. The input values can be given in reversed order
 * to reverse the control
 */
struct aliastarget
{
	float       fMinIn;
	float       fMaxIn;
	float       fMinOut;
	float       fMaxOut;
	std::string fTarget;	// the real osc address

	aliastarget(const char* address, float imin, float imax, float omin, float omax)
		: fMinIn(imin), fMaxIn(imax), fMinOut(omin), fMaxOut(omax), fTarget(address) {}

	aliastarget(const aliastarget& t)
		: fMinIn(t.fMinIn), fMaxIn(t.fMaxIn), fMinOut(t.fMinOut), fMaxOut(t.fMaxOut), fTarget(t.fTarget) {}

	float scale(float x) const 
    {
        if (fMinIn < fMaxIn) {
            // increasing control
            float z = (x < fMinIn) ? fMinIn : (x > fMaxIn) ? fMaxIn : x;
            return fMinOut + (z-fMinIn)*(fMaxOut-fMinOut)/(fMaxIn-fMinIn);
            
        } else if (fMinIn > fMaxIn) {
            // reversed control
            float z = (x < fMaxIn) ? fMaxIn : (x > fMinIn) ? fMinIn : x;
            return fMinOut + (fMinIn-z)*(fMaxOut-fMinOut)/(fMinIn-fMaxIn);
            
        } else {
            // no control !
            return (fMinOut+fMaxOut)/2.0f;
        }
    }
    
    float invscale(float x) const
    {
        if (fMinOut < fMaxOut) {
            // increasing control
            float z = (x < fMinOut) ? fMinOut : (x > fMaxOut) ? fMaxOut : x;
            return fMinIn + (z-fMinOut)*(fMaxIn-fMinIn)/(fMaxOut-fMinOut);
            
        } else if (fMinOut > fMaxOut) {
            // reversed control
            float z = (x < fMaxOut) ? fMaxOut : (x > fMinOut) ? fMinOut : x;
            return fMinIn + (fMinOut-z)*(fMaxIn-fMinIn)/(fMinOut-fMaxOut);
            
        } else {
            // no control !
            return (fMinIn+fMaxIn)/2.0f;
        }
    }
};

//--------------------------------------------------------------------------
/*!
	\brief a faust root node

	A Faust root node handles the \c 'hello' message and provides support
	for incoming osc signal data. 
*/
class RootNode : public MessageDriven
{

    private:
        int *fUPDIn, *fUDPOut, *fUDPErr;    // the osc port numbers (required by the hello method)
        OSCIO* fIO;                         // an OSC IO controler
        JSONUI* fJSON;

        typedef std::map<std::string, std::vector<aliastarget> > TAliasMap;
        TAliasMap fAliases;

        void processAlias(const std::string& address, float val);
        void eraseAliases(const std::string& target);
        void eraseAlias(const std::string& target, const std::string& alias);
        bool aliasError(const Message* msg);

    protected:
        RootNode(const char *name, JSONUI* json, OSCIO* io = NULL) : MessageDriven(name, ""), fUPDIn(0), fUDPOut(0), fUDPErr(0), fIO(io), fJSON(json) {}
        virtual ~RootNode() {}

    public:
        static SRootNode create(const char* name, JSONUI* json, OSCIO* io = NULL) { return new RootNode(name, json, io); }

        virtual void processMessage(const Message* msg);
        virtual bool accept(const Message* msg);
        virtual void get(unsigned long ipdest) const;
        virtual void get(unsigned long ipdest, const std::string& what) const;

        bool aliasMsg(const Message* msg, float omin, float omax);
        void addAlias(const char* alias, const char* address, float imin, float imax, float omin, float omax);
        bool acceptSignal(const Message* msg);      ///< handler for signal data
        void hello(unsigned long ipdest) const;     ///< handler for the 'hello' message
        void setPorts(int* in, int* out, int* err);

        std::vector<std::pair<std::string, double> > getAliases(const std::string& address, double value);
};

} // end namespoace

#endif

namespace oscfaust
{

/**
 * map (rescale) input values to output values
 */
template <typename C> struct mapping
{
	const C fMinOut;
	const C fMaxOut;
	mapping(C omin, C omax) : fMinOut(omin), fMaxOut(omax) {}
	C clip (C x) { return (x < fMinOut) ? fMinOut : (x > fMaxOut) ? fMaxOut : x; }
};

//--------------------------------------------------------------------------
/*!
	\brief a faust node is a terminal node and represents a faust parameter controler
*/
template <typename C> class FaustNode : public MessageDriven, public uiTypedItem<C>
{
	mapping<C>	fMapping;
    RootNode* fRoot;
    bool fInput;  // true for input nodes (slider, button...)
	
	//---------------------------------------------------------------------
	// Warning !!!
	// The cast (C *)fZone is necessary because the real size allocated is
	// only known at execution time. When the library is compiled, fZone is
	// uniquely defined by FAUSTFLOAT.
	//---------------------------------------------------------------------
	bool	store(C val) { *(C *)this->fZone = fMapping.clip(val); return true; }
	void	sendOSC() const;

	protected:
		FaustNode(RootNode* root, const char *name, C* zone, C init, C min, C max, const char* prefix, GUI* ui, bool initZone, bool input) 
			: MessageDriven(name, prefix), uiTypedItem<C>(ui, zone), fMapping(min, max), fRoot(root), fInput(input)
			{
                if (initZone) {
                    *zone = init; 
                }
            }
			
		virtual ~FaustNode() {}

	public:
		typedef SMARTP<FaustNode<C> > SFaustNode;
		static SFaustNode create(RootNode* root, const char* name, C* zone, C init, C min, C max, const char* prefix, GUI* ui, bool initZone, bool input)	
        { 
            SFaustNode node = new FaustNode(root, name, zone, init, min, max, prefix, ui, initZone, input); 
            /*
                Since FaustNode is a subclass of uiItem, the pointer will also be kept in the GUI class, and it's desallocation will be done there.
                So we don't want to have smartpointer logic desallocate it and we increment the refcount.
            */
            node->addReference();
            return node; 
        }
    
		bool accept(const Message* msg);
		void get(unsigned long ipdest) const;		///< handler for the 'get' message
		virtual void reflectZone() { sendOSC(); this->fCache = *this->fZone; }
};

} // end namespace

#endif

class GUI;
namespace oscfaust
{

class OSCIO;
class RootNode;
typedef class SMARTP<RootNode> SRootNode;
class MessageDriven;
typedef class SMARTP<MessageDriven>	SMessageDriven;

//--------------------------------------------------------------------------
/*!
	\brief a factory to build a OSC UI hierarchy
	
	Actually, makes use of a stack to build the UI hierarchy.
	It includes a pointer to a OSCIO controler, but just to give it to the root node.
*/
class FaustFactory
{
	std::stack<SMessageDriven>	fNodes;		///< maintains the current hierarchy level
	SRootNode					fRoot;		///< keep track of the root node
	OSCIO*                      fIO;		///< hack to support audio IO via OSC, actually the field is given to the root node
	GUI*						fGUI;		///< a GUI pointer to support updateAllGuis(), required for bi-directionnal OSC
    JSONUI*                     fJSON;
    
	private:
		std::string addressFirst(const std::string& address) const;
		std::string addressTail(const std::string& address) const;

	public:
				 FaustFactory(GUI* ui, JSONUI* json, OSCIO * io = NULL);
		virtual ~FaustFactory(); 

		template <typename C> void addnode(const char* label, C* zone, C init, C min, C max, bool initZone, bool input);
		template <typename C> void addAlias(const std::string& fullpath, C* zone, C imin, C imax, C init, C min, C max, const char* label);
        
		void addAlias(const char* alias, const char* address, float imin, float imax, float omin, float omax);
		void opengroup(const char* label);
		void closegroup();

		SRootNode root() const; 
};

/**
 * Add a node to the OSC UI tree in the current group at the top of the stack 
 */
template <typename C> void FaustFactory::addnode(const char* label, C* zone, C init, C min, C max, bool initZone, bool input) 
{
	SMessageDriven top;
	if (fNodes.size()) top = fNodes.top();
	if (top) {
		std::string prefix = top->getOSCAddress();
		top->add(FaustNode<C>::create(root(), label, zone, init, min, max, prefix.c_str(), fGUI, initZone, input));
	}
}

/**
 * Add an alias (actually stored and handled at root node level
 */
template <typename C> void FaustFactory::addAlias(const std::string& fullpath, C* zone, C imin, C imax, C init, C min, C max, const char* label)
{
	std::istringstream 	ss(fullpath);
	std::string 		realpath; 
 
	ss >> realpath >> imin >> imax;
	SMessageDriven top = fNodes.top();
	if (top) {
		std::string target = top->getOSCAddress() + "/" + label;
		addAlias(realpath.c_str(), target.c_str(), float(imin), float(imax), float(min), float(max));
	}
}

} // end namespoace

#endif

class GUI;

typedef void (*ErrorCallback)(void*);  

namespace oscfaust
{

class OSCIO;
class OSCSetup;
class OSCRegexp;
    
//--------------------------------------------------------------------------
/*!
	\brief the main Faust OSC Lib API
	
	The OSCControler is essentially a glue between the memory representation (in charge of the FaustFactory),
	and the network services (in charge of OSCSetup).
*/
class OSCControler
{
	int fUDPPort,   fUDPOut, fUPDErr;	// the udp ports numbers
	std::string     fDestAddress;		// the osc messages destination address, used at initialization only
										// to collect the address from the command line
	std::string     fBindAddress;		// when non empty, the address used to bind the socket for listening
	OSCSetup*		fOsc;				// the network manager (handles the udp sockets)
	OSCIO*			fIO;				// hack for OSC IO support (actually only relayed to the factory)
	FaustFactory*	fFactory;			// a factory to build the memory representation

    bool            fInit;
    
	public:
		/*
			base udp port is chosen in an unassigned range from IANA PORT NUMBERS (last updated 2011-01-24)
			see at http://www.iana.org/assignments/port-numbers
			5507-5552  Unassigned
		*/
		enum { kUDPBasePort = 5510 };
            
        OSCControler(int argc, char* argv[], GUI* ui, JSONUI* json, OSCIO* io = NULL, ErrorCallback errCallback = NULL, void* arg = NULL, bool init = true);

        virtual ~OSCControler();
	
		//--------------------------------------------------------------------------
		// addnode, opengroup and closegroup are simply relayed to the factory
		//--------------------------------------------------------------------------
		// Add a node in the current group (top of the group stack)
		template <typename T> void addnode(const char* label, T* zone, T init, T min, T max, bool input = true)
							{ fFactory->addnode(label, zone, init, min, max, fInit, input); }
		
		//--------------------------------------------------------------------------
		// This method is used for alias messages. The arguments imin and imax allow
		// to map incomming values from the alias input range to the actual range 
		template <typename T> void addAlias(const std::string& fullpath, T* zone, T imin, T imax, T init, T min, T max, const char* label)
							{ fFactory->addAlias(fullpath, zone, imin, imax, init, min, max, label); }

		void opengroup(const char* label)		{ fFactory->opengroup(label); }
		void closegroup()						{ fFactory->closegroup(); }
	   
		//--------------------------------------------------------------------------
		void run();				// starts the network services
		void endBundle();		// when bundle mode is on, close and send the current bundle (if any)
		void stop();			// stop the network services
		std::string getInfos() const; // gives information about the current environment (version, port numbers,...)

		int	getUDPPort() const			{ return fUDPPort; }
		int	getUDPOut()	const			{ return fUDPOut; }
		int	getUDPErr()	const			{ return fUPDErr; }
		const char*	getDestAddress() const { return fDestAddress.c_str(); }
		const char*	getRootName() const;	// probably useless, introduced for UI extension experiments
    
        void setUDPPort(int port) { fUDPPort = port; }
        void setUDPOut(int port) { fUDPOut = port; }
        void setUDPErr(int port) { fUPDErr = port; }
        void setDestAddress(const char* address) { fDestAddress = address; }

        // By default, an osc interface emits all parameters. You can filter specific params dynamically.
        static std::vector<OSCRegexp*>     fFilteredPaths; // filtered paths will not be emitted
        static void addFilteredPath(std::string path);
        static bool isPathFiltered(std::string path);
        static void resetFilteredPaths();
    
		static float version();				// the Faust OSC library version number
		static const char* versionstr();	// the Faust OSC library version number as a string
		static int gXmit;                   // a static variable to control the transmission of values
                                            // i.e. the use of the interface as a controler
		static int gBundle;                 // a static variable to control the osc bundle mode
};

#define kNoXmit     0
#define kAll        1
#define kAlias      2

}

#endif

#ifdef _WIN32
#define strcasecmp _stricmp
#endif

/******************************************************************************
 *******************************************************************************
 
 OSC (Open Sound Control) USER INTERFACE
 
 *******************************************************************************
 *******************************************************************************/
/*
 
 Note about the OSC addresses and the Faust UI names:
 ----------------------------------------------------
 There are potential conflicts between the Faust UI objects naming scheme and
 the OSC address space. An OSC symbolic names is an ASCII string consisting of
 printable characters other than the following:
	space
 #	number sign
 *	asterisk
 ,	comma
 /	forward
 ?	question mark
 [	open bracket
 ]	close bracket
 {	open curly brace
 }	close curly brace
 
 a simple solution to address the problem consists in replacing
 space or tabulation with '_' (underscore)
 all the other osc excluded characters with '-' (hyphen)
 
 This solution is implemented in the proposed OSC UI;
 */

class OSCUI : public GUI
{
    
    private:
        
        oscfaust::OSCControler*	fCtrl;
        std::vector<const char*> fAlias;
        JSONUI fJSON;
        
        const char* tr(const char* label) const
        {
            static char buffer[1024];
            char * ptr = buffer; int n=1;
            while (*label && (n++ < 1024)) {
                switch (*label) {
                    case ' ': case '	':
                        *ptr++ = '_';
                        break;
                    case '#': case '*': case ',': case '/': case '?':
                    case '[': case ']': case '{': case '}': case '(': case ')':
                        *ptr++ = '_';
                        break;
                    default:
                        *ptr++ = *label;
                }
                label++;
            }
            *ptr = 0;
            return buffer;
        }
        
        // add all accumulated alias
        void addalias(FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, const char* label)
        {
            for (unsigned int i = 0; i < fAlias.size(); i++) {
                fCtrl->addAlias(fAlias[i], zone, FAUSTFLOAT(0), FAUSTFLOAT(1), init, min, max, label);
            }
            fAlias.clear();
        }
        
    public:
        
        OSCUI(const char* /*applicationname*/, int argc, char* argv[], oscfaust::OSCIO* io = NULL, ErrorCallback errCallback = NULL, void* arg = NULL, bool init = true) : GUI()
        {
            fCtrl = new oscfaust::OSCControler(argc, argv, this, &fJSON, io, errCallback, arg, init);
            //		fCtrl->opengroup(applicationname);
        }
        
        virtual ~OSCUI() { delete fCtrl; }
        
        // -- widget's layouts
        
        virtual void openTabBox(const char* label)          { fCtrl->opengroup(tr(label)); fJSON.openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fCtrl->opengroup(tr(label)); fJSON.openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fCtrl->opengroup(tr(label)); fJSON.openVerticalBox(label); }
        virtual void closeBox()                             { fCtrl->closegroup(); fJSON.closeBox(); }
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            const char* l = tr(label);
            addalias(zone, 0, 0, 1, l);
            fCtrl->addnode(l, zone, FAUSTFLOAT(0), FAUSTFLOAT(0), FAUSTFLOAT(1));
            fJSON.addButton(label, zone);
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            const char* l = tr(label);
            addalias(zone, 0, 0, 1, l);
            fCtrl->addnode(l, zone, FAUSTFLOAT(0), FAUSTFLOAT(0), FAUSTFLOAT(1));
            fJSON.addCheckButton(label, zone);
        }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            const char* l = tr(label);
            addalias(zone, init, min, max, l);
            fCtrl->addnode(l, zone, init, min, max);
            fJSON.addVerticalSlider(label, zone, init, min, max, step);
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            const char* l = tr(label);
            addalias(zone, init, min, max, l);
            fCtrl->addnode(l, zone, init, min, max);
            fJSON.addHorizontalSlider(label, zone, init, min, max, step);
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            const char* l = tr(label);
            addalias(zone, init, min, max, l);
            fCtrl->addnode(l, zone, init, min, max);
            fJSON.addNumEntry(label, zone, init, min, max, step);
        }
        
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            const char* l = tr(label);
            addalias(zone, 0, min, max, l);
            fCtrl->addnode(l, zone, FAUSTFLOAT(0), min, max, false);
            fJSON.addHorizontalBargraph(label, zone, min, max);
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            const char* l = tr(label);
            addalias(zone, 0, min, max, l);
            fCtrl->addnode(l, zone, FAUSTFLOAT(0), min, max, false);
            fJSON.addVerticalBargraph(label, zone, min, max);
        }
            
        // -- metadata declarations
        
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* alias)
        {
            if (strcasecmp(key, "OSC") == 0) fAlias.push_back(alias);
            fJSON.declare(zone, key, alias);
        }
        
        virtual void show() {}
        
        bool run()
        {
            fCtrl->run();
            return true;
        }
        
        void stop()			{ fCtrl->stop(); }
        void endBundle() 	{ fCtrl->endBundle(); }
        
        std::string getInfos()          { return fCtrl->getInfos(); }
        
        const char* getRootName()		{ return fCtrl->getRootName(); }
        int getUDPPort()                { return fCtrl->getUDPPort(); }
        int getUDPOut()                 { return fCtrl->getUDPOut(); }
        int getUDPErr()                 { return fCtrl->getUDPErr(); }
        const char* getDestAddress()    { return fCtrl->getDestAddress(); }
        
        void setUDPPort(int port)       { fCtrl->setUDPPort(port); }
        void setUDPOut(int port)        { fCtrl->setUDPOut(port); }
        void setUDPErr(int port)        { fCtrl->setUDPErr(port); }
        void setDestAddress(const char* address)    { return fCtrl->setDestAddress(address); }
    
};

#endif // __OSCUI__
/**************************  END  OSCUI.h **************************/

#ifdef POLY2
#include "effect.h"
#endif

#if SOUNDFILE
/************************** BEGIN SoundUI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
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

/************************** BEGIN DecoratorUI.h **************************/
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
/**************************  END  DecoratorUI.h **************************/

#ifdef __APPLE__
#include <CoreFoundation/CFBundle.h>
#endif

// Always included otherwise -i mode later on will not always include it (with the conditional includes)
/************************** BEGIN Soundfile.h **************************/
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

#ifndef __Soundfile__
#define __Soundfile__

#include <iostream>
#include <string.h>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#define BUFFER_SIZE 16384
#define SAMPLE_RATE 44100
#define MAX_CHAN 64
#define MAX_SOUNDFILE_PARTS 256

#ifdef _MSC_VER
#define PRE_PACKED_STRUCTURE __pragma(pack(push, 1))
#define POST_PACKED_STRUCTURE \
    ;                         \
    __pragma(pack(pop))
#else
#define PRE_PACKED_STRUCTURE
#define POST_PACKED_STRUCTURE __attribute__((__packed__))
#endif

/*
 The soundfile structure to be used by the DSP code. Soundfile has a MAX_SOUNDFILE_PARTS parts 
 (even a single soundfile or an empty soundfile). 
 fLength, fOffset and fSR fields are filled accordingly by repeating
 the actual parts if needed.
 
 It has to be 'packed' to that the LLVM backend can correctly access it.

 Index computation:
    - p is the current part number [0..MAX_SOUNDFILE_PARTS-1] (must be proved by the type system)
    - i is the current position in the part. It will be constrained between [0..length]
    - idx(p,i) = fOffset[p] + max(0, min(i, fLength[p]));
*/

PRE_PACKED_STRUCTURE
struct Soundfile {
    FAUSTFLOAT** fBuffers;
    int* fLength;   // length of each part
    int* fSR;       // sample rate of each part
    int* fOffset;   // offset of each part in the global buffer
    int fChannels;  // max number of channels of all concatenated files

    Soundfile()
    {
        fBuffers  = NULL;
        fChannels = -1;
        fLength   = new int[MAX_SOUNDFILE_PARTS];
        fSR       = new int[MAX_SOUNDFILE_PARTS];
        fOffset   = new int[MAX_SOUNDFILE_PARTS];
    }

    ~Soundfile()
    {
        // Free the real channels only
        for (int chan = 0; chan < fChannels; chan++) {
            delete fBuffers[chan];
        }
        delete[] fBuffers;
        delete[] fLength;
        delete[] fSR;
        delete[] fOffset;
    }

} POST_PACKED_STRUCTURE;

/*
 The generic soundfile reader.
 */

class SoundfileReader {
    
   protected:
    
    int fDriverSR;
    
    void emptyFile(Soundfile* soundfile, int part, int& offset)
    {
        soundfile->fLength[part] = BUFFER_SIZE;
        soundfile->fSR[part] = SAMPLE_RATE;
        soundfile->fOffset[part] = offset;
        // Update offset
        offset += soundfile->fLength[part];
    }

    Soundfile* createSoundfile(int cur_chan, int length, int max_chan)
    {
        Soundfile* soundfile = new Soundfile();
        if (!soundfile) {
            throw std::bad_alloc();
        }
        
        soundfile->fBuffers = new FAUSTFLOAT*[max_chan];
        if (!soundfile->fBuffers) {
            throw std::bad_alloc();
        }
        
        for (int chan = 0; chan < cur_chan; chan++) {
            soundfile->fBuffers[chan] = new FAUSTFLOAT[length];
            if (!soundfile->fBuffers[chan]) {
                throw std::bad_alloc();
            }
            memset(soundfile->fBuffers[chan], 0, sizeof(FAUSTFLOAT) * length);
        }
        
        soundfile->fChannels = cur_chan;
        return soundfile;
    }

    void getBuffersOffset(Soundfile* soundfile, FAUSTFLOAT** buffers, int offset)
    {
        for (int chan = 0; chan < soundfile->fChannels; chan++) {
            buffers[chan] = &soundfile->fBuffers[chan][offset];
        }
    }
    
    // Check if a soundfile exists and return its real path_name
    std::string checkFile(const std::vector<std::string>& sound_directories, const std::string& file_name)
    {
        if (checkFile(file_name)) {
            return file_name;
        } else {
            for (size_t i = 0; i < sound_directories.size(); i++) {
                std::string path_name = sound_directories[i] + "/" + file_name;
                if (checkFile(path_name)) { return path_name; }
            }
            return "";
        }
    }
    
    bool isResampling(int sample_rate) { return (fDriverSR > 0 && fDriverSR != sample_rate); }
 
    // To be implemented by subclasses

    /**
     * Check the availability of a sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     *
     * @return true if the sound resource is available, false otherwise.
     */
    virtual bool checkFile(const std::string& path_name) = 0;
    
    /**
     * Check the availability of a sound resource.
     *
     * @param buffer - the sound buffer
     * @param buffer - the sound buffer length
     *
     * @return true if the sound resource is available, false otherwise.
     */

    virtual bool checkFile(unsigned char* buffer, size_t length) { return true; }

    /**
     * Get the channels and length values of the given sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param channels - the channels value to be filled with the sound resource number of channels
     * @param length - the length value to be filled with the sound resource length in frames
     *
     */
    virtual void getParamsFile(const std::string& path_name, int& channels, int& length) = 0;
    
    /**
     * Get the channels and length values of the given sound resource.
     *
     * @param buffer - the sound buffer
     * @param buffer - the sound buffer length
     * @param channels - the channels value to be filled with the sound resource number of channels
     * @param length - the length value to be filled with the sound resource length in frames
     *
     */
    virtual void getParamsFile(unsigned char* buffer, size_t size, int& channels, int& length) {}

    /**
     * Read one sound resource and fill the 'soundfile' structure accordingly
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param part - the part number to be filled in the soundfile
     * @param offset - the offset value to be incremented with the actual sound resource length in frames
     * @param max_chan - the maximum number of mono channels to fill
     *
     */
    virtual void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan) = 0;
    
    /**
     * Read one sound resource and fill the 'soundfile' structure accordingly
     *
     * @param buffer - the sound buffer
     * @param buffer - the sound buffer length
     * @param part - the part number to be filled in the soundfile
     * @param offset - the offset value to be incremented with the actual sound resource length in frames
     * @param max_chan - the maximum number of mono channels to fill
     *
     */
    virtual void readFile(Soundfile* soundfile, unsigned char* buffer, size_t length, int part, int& offset, int max_chan) {}

  public:
    
    virtual ~SoundfileReader() {}
    
    void setSampleRate(int sample_rate) { fDriverSR = sample_rate; }
   
    Soundfile* createSoundfile(const std::vector<std::string>& path_name_list, int max_chan)
    {
        try {
            int cur_chan = 1; // At least one buffer
            int total_length = 0;
            
            // Compute total length and channels max of all files
            for (int i = 0; i < int(path_name_list.size()); i++) {
                int chan, length;
                if (path_name_list[i] == "__empty_sound__") {
                    length = BUFFER_SIZE;
                    chan = 1;
                } else {
                    getParamsFile(path_name_list[i], chan, length);
                }
                cur_chan = std::max<int>(cur_chan, chan);
                total_length += length;
            }
           
            // Complete with empty parts
            total_length += (MAX_SOUNDFILE_PARTS - path_name_list.size()) * BUFFER_SIZE;
            
            // Create the soundfile
            Soundfile* soundfile = createSoundfile(cur_chan, total_length, max_chan);
            
            // Init offset
            int offset = 0;
            
            // Read all files
            for (int i = 0; i < int(path_name_list.size()); i++) {
                if (path_name_list[i] == "__empty_sound__") {
                    emptyFile(soundfile, i, offset);
                } else {
                    readFile(soundfile, path_name_list[i], i, offset, max_chan);
                }
            }
            
            // Complete with empty parts
            for (int i = int(path_name_list.size()); i < MAX_SOUNDFILE_PARTS; i++) {
                emptyFile(soundfile, i, offset);
            }
            
            // Share the same buffers for all other channels so that we have max_chan channels available
            for (int chan = cur_chan; chan < max_chan; chan++) {
                soundfile->fBuffers[chan] = soundfile->fBuffers[chan % cur_chan];
            }
            
            return soundfile;
            
        } catch (...) {
            return NULL;
        }
    }

    // Check if all soundfiles exist and return their real path_name
    std::vector<std::string> checkFiles(const std::vector<std::string>& sound_directories,
                                        const std::vector<std::string>& file_name_list)
    {
        std::vector<std::string> path_name_list;
        for (size_t i = 0; i < file_name_list.size(); i++) {
            std::string path_name = checkFile(sound_directories, file_name_list[i]);
            // If 'path_name' is not found, it is replaced by an empty sound (= silence)
            path_name_list.push_back((path_name == "") ? "__empty_sound__" : path_name);
        }
        return path_name_list;
    }

};

#endif
/**************************  END  Soundfile.h **************************/

#if defined(JUCE_32BIT) || defined(JUCE_64BIT)
/************************** BEGIN JuceReader.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
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

#ifndef __JuceReader__
#define __JuceReader__

#include <assert.h>


struct JuceReader : public SoundfileReader {
    
    AudioFormatManager fFormatManager;
    
    JuceReader() { fFormatManager.registerBasicFormats(); }
    
    bool checkFile(const std::string& path_name)
    {
        File file(path_name);
        if (file.existsAsFile()) {
            return true;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name << "'" << std::endl;
            return false;
        }
    }
    
    void getParamsFile(const std::string& path_name, int& channels, int& length)
    {
        ScopedPointer<AudioFormatReader> formatReader = fFormatManager.createReaderFor(File(path_name));
        assert(formatReader);
        channels = int(formatReader->numChannels);
        length = int(formatReader->lengthInSamples);
    }
    
    void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan)
    {
        ScopedPointer<AudioFormatReader> formatReader = fFormatManager.createReaderFor(File(path_name));
        
        int channels = std::min<int>(max_chan, int(formatReader->numChannels));
        
        soundfile->fLength[part] = int(formatReader->lengthInSamples);
        soundfile->fSR[part] = int(formatReader->sampleRate);
        soundfile->fOffset[part] = offset;
        
        FAUSTFLOAT* buffers[soundfile->fChannels];
        getBuffersOffset(soundfile, buffers, offset);
        
        if (formatReader->read(reinterpret_cast<int *const *>(buffers), int(formatReader->numChannels), 0, int(formatReader->lengthInSamples), false)) {
            
            // Possibly concert samples
            if (!formatReader->usesFloatingPointData) {
                for (int chan = 0; chan < int(formatReader->numChannels); ++chan) {
                    FAUSTFLOAT* buffer = &soundfile->fBuffers[chan][soundfile->fOffset[part]];
                    FloatVectorOperations::convertFixedToFloat(buffer, reinterpret_cast<const int*>(buffer), 1.0f/0x7fffffff, int(formatReader->lengthInSamples));
                }
            }
            
        } else {
            std::cerr << "Error reading the file : " << path_name << std::endl;
        }
            
        // Update offset
        offset += soundfile->fLength[part];
    }
    
};

#endif
/**************************  END  JuceReader.h **************************/
JuceReader gReader;
#elif defined(MEMORY_READER)
/************************** BEGIN MemoryReader.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
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

#ifndef __MemoryReader__
#define __MemoryReader__


/*
 A 'MemoryReader' object can be used to prepare a set of sound resources in memory, to be used by SoundUI::addSoundfile.
 
 A Soundfile* object will have to be filled with a list of sound resources: the fLength, fOffset, fSampleRate and fBuffers fields 
 have to be completed with the appropriate values, and will be accessed in the DSP object while running.
 *
 */

// To adapt for a real case use

#define SOUND_CHAN      2
#define SOUND_LENGTH    4096
#define SOUND_SR        40100

struct MemoryReader : public SoundfileReader {
    
    MemoryReader()
    {}
    
    /**
     * Check the availability of a sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     *
     * @return true if the sound resource is available, false otherwise.
     */
    virtual bool checkFile(const std::string& path_name) { return true; }
    
    /**
     * Get the channels and length values of the given sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param channels - the channels value to be filled with the sound resource number of channels
     * @param length - the length value to be filled with the sound resource length in frames
     *
     */
    virtual void getParamsFile(const std::string& path_name, int& channels, int& length)
    {
        channels = SOUND_CHAN;
        length = SOUND_LENGTH;
    }
    
    /**
     * Read one sound resource and fill the 'soundfile' structure accordingly
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param part - the part number to be filled in the soundfile
     * @param offset - the offset value to be incremented with the actual sound resource length in frames
     * @param max_chan - the maximum number of mono channels to fill
     *
     */
    virtual void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan)
    {
        soundfile->fLength[part] = SOUND_LENGTH;
        soundfile->fSR[part] = SOUND_SR;
        soundfile->fOffset[part] = offset;
        
        // Audio frames have to be written for each chan
        for (int sample = 0; sample < SOUND_LENGTH; sample++) {
            for (int chan = 0; chan < SOUND_CHAN; chan++) {
                soundfile->fBuffers[chan][offset + sample] = 0.f;
            }
        }
        
        // Update offset
        offset += SOUND_LENGTH;
    }
    
};

#endif
/**************************  END  MemoryReader.h **************************/
MemoryReader gReader;
#else
/************************** BEGIN LibsndfileReader.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
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

#ifndef __LibsndfileReader__
#define __LibsndfileReader__

#ifdef SAMPLERATE
#include <samplerate.h>
#endif
#include <sndfile.h>
#include <string.h>
#include <assert.h>
#include <iostream>


struct VFLibsndfile {
    
    #define SIGNED_SIZEOF(x) ((int)sizeof(x))
    
    unsigned char* fBuffer;
    size_t fLength;
    size_t fOffset;
    SF_VIRTUAL_IO fVIO;
    
    VFLibsndfile(unsigned char* buffer, size_t length):fBuffer(buffer), fLength(length), fOffset(0)
    {
        fVIO.get_filelen = vfget_filelen;
        fVIO.seek = vfseek;
        fVIO.read = vfread;
        fVIO.write = vfwrite;
        fVIO.tell = vftell;
    }
    
    static sf_count_t vfget_filelen(void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        return vf->fLength;
    }
  
    static sf_count_t vfseek(sf_count_t offset, int whence, void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        switch (whence) {
            case SEEK_SET:
                vf->fOffset = offset;
                break;
                
            case SEEK_CUR:
                vf->fOffset = vf->fOffset + offset;
                break;
                
            case SEEK_END:
                vf->fOffset = vf->fLength + offset;
                break;
                
            default:
                break;
        };
        
        return vf->fOffset;
    }
    
    static sf_count_t vfread(void* ptr, sf_count_t count, void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        
        /*
         **	This will break badly for files over 2Gig in length, but
         **	is sufficient for testing.
         */
        if (vf->fOffset + count > vf->fLength) {
            count = vf->fLength - vf->fOffset;
        }
        
        memcpy(ptr, vf->fBuffer + vf->fOffset, count);
        vf->fOffset += count;
        
        return count;
    }
    
    static sf_count_t vfwrite(const void* ptr, sf_count_t count, void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        
        /*
         **	This will break badly for files over 2Gig in length, but
         **	is sufficient for testing.
         */
        if (vf->fOffset >= SIGNED_SIZEOF(vf->fBuffer)) {
            return 0;
        }
        
        if (vf->fOffset + count > SIGNED_SIZEOF(vf->fBuffer)) {
            count = sizeof (vf->fBuffer) - vf->fOffset;
        }
        
        memcpy(vf->fBuffer + vf->fOffset, ptr, (size_t)count);
        vf->fOffset += count;
        
        if (vf->fOffset > vf->fLength) {
            vf->fLength = vf->fOffset;
        }
        
        return count;
    }
    
    static sf_count_t vftell(void* user_data)
    {
        VFLibsndfile* vf = static_cast<VFLibsndfile*>(user_data);
        return vf->fOffset;
    }
 
};

struct LibsndfileReader : public SoundfileReader {
	
    LibsndfileReader() {}
	
    typedef sf_count_t (* sample_read)(SNDFILE* sndfile, FAUSTFLOAT* ptr, sf_count_t frames);
	
    // Check file
    bool checkFile(const std::string& path_name)
    {
        SF_INFO snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        return checkFileAux(snd_file, path_name);
    }
    
    bool checkFile(unsigned char* buffer, size_t length)
    {
        SF_INFO snd_info;
        snd_info.format = 0;
        VFLibsndfile vio(buffer, length);
        SNDFILE* snd_file = sf_open_virtual(&vio.fVIO, SFM_READ, &snd_info, &vio);
        return checkFileAux(snd_file, "virtual file");
    }
    
    bool checkFileAux(SNDFILE* snd_file, const std::string& path_name)
    {
        if (snd_file) {
            sf_close(snd_file);
            return true;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name << "' (" << sf_strerror(NULL) << ")" << std::endl;
            return false;
        }
    }

    // Open the file and returns its length and channels
    void getParamsFile(const std::string& path_name, int& channels, int& length)
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        getParamsFileAux(snd_file, snd_info, channels, length);
    }
    
    void getParamsFile(unsigned char* buffer, size_t size, int& channels, int& length)
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        VFLibsndfile vio(buffer, size);
        SNDFILE* snd_file = sf_open_virtual(&vio.fVIO, SFM_READ, &snd_info, &vio);
        getParamsFileAux(snd_file, snd_info, channels, length);
    }
    
    void getParamsFileAux(SNDFILE* snd_file, const SF_INFO& snd_info, int& channels, int& length)
    {
        assert(snd_file);
        channels = int(snd_info.channels);
    #ifdef SAMPLERATE
        length = (isResampling(snd_info.samplerate)) ? ((double(snd_info.frames) * double(fDriverSR) / double(snd_info.samplerate)) + BUFFER_SIZE) : int(snd_info.frames);
    #else
        length = int(snd_info.frames);
    #endif
        sf_close(snd_file);
    }
    
    // Read the file
    void copyToOut(Soundfile* soundfile, int size, int channels, int max_channels, int offset, FAUSTFLOAT* buffer)
    {
        for (int sample = 0; sample < size; sample++) {
            for (int chan = 0; chan < channels; chan++) {
                soundfile->fBuffers[chan][offset + sample] = buffer[sample * max_channels + chan];
            }
        }
    }
    
    void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan)
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        readFileAux(soundfile, snd_file, snd_info, part, offset, max_chan);
    }
    
    void readFile(Soundfile* soundfile, unsigned char* buffer, size_t length, int part, int& offset, int max_chan)
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        VFLibsndfile vio(buffer, length);
        SNDFILE* snd_file = sf_open_virtual(&vio.fVIO, SFM_READ, &snd_info, &vio);
        readFileAux(soundfile, snd_file, snd_info, part, offset, max_chan);
    }
	
    // Will be called to fill all parts from 0 to MAX_SOUNDFILE_PARTS-1
    void readFileAux(Soundfile* soundfile, SNDFILE* snd_file, const SF_INFO& snd_info, int part, int& offset, int max_chan)
    {
        assert(snd_file);
        int channels = std::min<int>(max_chan, snd_info.channels);
    #ifdef SAMPLERATE
        if (isResampling(snd_info.samplerate)) {
            soundfile->fLength[part] = int(double(snd_info.frames) * double(fDriverSR) / double(snd_info.samplerate));
            soundfile->fSR[part] = fDriverSR;
        } else {
            soundfile->fLength[part] = int(snd_info.frames);
            soundfile->fSR[part] = snd_info.samplerate;
        }
    #else
        soundfile->fLength[part] = int(snd_info.frames);
        soundfile->fSR[part] = snd_info.samplerate;
    #endif
        soundfile->fOffset[part] = offset;
		
        // Read and fill snd_info.channels number of channels
        sf_count_t nbf;
        FAUSTFLOAT* buffer_in = (FAUSTFLOAT*)alloca(BUFFER_SIZE * sizeof(FAUSTFLOAT) * snd_info.channels);
        sample_read reader;
        
        if (sizeof(FAUSTFLOAT) == 4) {
            reader = reinterpret_cast<sample_read>(sf_readf_float);
        } else {
            reader = reinterpret_cast<sample_read>(sf_readf_double);
        }
        
    #ifdef SAMPLERATE
        // Resampling
        SRC_STATE* resampler = nullptr;
        FAUSTFLOAT* buffer_out = nullptr;
        if  (isResampling(snd_info.samplerate)) {
            int error;
            resampler = src_new(SRC_SINC_FASTEST, channels, &error);
            if (error != 0) {
                std::cerr << "ERROR : src_new " << src_strerror(error) << std::endl;
                throw -1;
            }
            buffer_out = (FAUSTFLOAT*)alloca(BUFFER_SIZE * sizeof(FAUSTFLOAT) * snd_info.channels);
        }
    #endif
        
        do {
            nbf = reader(snd_file, buffer_in, BUFFER_SIZE);
        #ifdef SAMPLERATE
            // Resampling
            if  (isResampling(snd_info.samplerate)) {
                int in_offset = 0;
                SRC_DATA src_data;
                src_data.src_ratio = double(fDriverSR)/double(snd_info.samplerate);
                do {
                    src_data.data_in = &buffer_in[in_offset * snd_info.channels];
                    src_data.data_out = buffer_out;
                    src_data.input_frames = nbf - in_offset;
                    src_data.output_frames = BUFFER_SIZE;
                    src_data.end_of_input = (nbf < BUFFER_SIZE);
                    int res = src_process(resampler, &src_data);
                    if (res != 0) {
                        std::cerr << "ERROR : src_process " << src_strerror(res) << std::endl;
                        throw -1;
                    }
                    copyToOut(soundfile, src_data.output_frames_gen, channels, snd_info.channels, offset, buffer_out);
                    in_offset += src_data.input_frames_used;
                    // Update offset
                    offset += src_data.output_frames_gen;
                } while (in_offset < nbf);
            } else {
                copyToOut(soundfile, nbf, channels, snd_info.channels, offset, buffer_in);
                // Update offset
                offset += nbf;
            }
        #else
            copyToOut(soundfile, nbf, channels, snd_info.channels, offset, buffer_in);
            // Update offset
            offset += nbf;
        #endif
        } while (nbf == BUFFER_SIZE);
		
        sf_close(snd_file);
    #ifdef SAMPLERATE
        if (resampler) src_delete(resampler);
    #endif
    }

};

#endif
/**************************  END  LibsndfileReader.h **************************/
LibsndfileReader gReader;
#endif

// To be used by DSP code if no SoundUI is used
std::vector<std::string> path_name_list;
Soundfile* defaultsound = gReader.createSoundfile(path_name_list, MAX_CHAN);

class SoundUI : public GenericUI
{
		
    private:
    
        std::vector<std::string> fSoundfileDir;             // The soundfile directories
        std::map<std::string, Soundfile*> fSoundfileMap;    // Map to share loaded soundfiles
        SoundfileReader* fSoundReader;

     public:
    
        SoundUI(const std::string& sound_directory = "", int sample_rate = -1, SoundfileReader* reader = nullptr)
        {
            fSoundfileDir.push_back(sound_directory);
            fSoundReader = (reader) ? reader : &gReader;
            fSoundReader->setSampleRate(sample_rate);
        }
    
        SoundUI(const std::vector<std::string>& sound_directories, int sample_rate = -1, SoundfileReader* reader = nullptr)
        :fSoundfileDir(sound_directories)
        {
            fSoundReader = (reader) ? reader : &gReader;
            fSoundReader->setSampleRate(sample_rate);
        }
    
        virtual ~SoundUI()
        {   
            // Delete all soundfiles
            std::map<std::string, Soundfile*>::iterator it;
            for (it = fSoundfileMap.begin(); it != fSoundfileMap.end(); it++) {
                delete (*it).second;
            }
        }

        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* url, Soundfile** sf_zone)
        {
            const char* saved_url = url; // 'url' is consumed by parseMenuList2
            std::vector<std::string> file_name_list;
            
            bool menu = parseMenuList2(url, file_name_list, true);
            // If not a list, we have as single file
            if (!menu) { file_name_list.push_back(saved_url); }
            
            // Parse the possible list
            if (fSoundfileMap.find(saved_url) == fSoundfileMap.end()) {
                // Check all files and get their complete path
                std::vector<std::string> path_name_list = fSoundReader->checkFiles(fSoundfileDir, file_name_list);
                // Read them and create the Soundfile
                Soundfile* sound_file = fSoundReader->createSoundfile(path_name_list, MAX_CHAN);
                if (sound_file) {
                    fSoundfileMap[saved_url] = sound_file;
                } else {
                    // If failure, use 'defaultsound'
                    std::cerr << "addSoundfile : soundfile for " << saved_url << " cannot be created !" << std::endl;
                    *sf_zone = defaultsound;
                    return;
                }
            }
            
            // Get the soundfile
            *sf_zone = fSoundfileMap[saved_url];
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
        #ifdef ANDROID_DRIVER
            bundle_path_str = "/data/data/__CURRENT_ANDROID_PACKAGE__/files";
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
        #ifdef ANDROID_DRIVER
            bundle_path_str = "/data/data/__CURRENT_ANDROID_PACKAGE__/files";
        #endif
            return bundle_path_str;
        }
};

#endif
/**************************  END  SoundUI.h **************************/
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

static double mydsp_faustpower2_f(double value) {
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
	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	double fConst8;
	FAUSTFLOAT fHslider1;
	double fRec16[2];
	double fRec17[3];
	FAUSTFLOAT fHslider2;
	double fRec18[2];
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
	double fRec15[2];
	double fRec13[2];
	double fRec12[2];
	double fRec10[2];
	double fConst9;
	double fConst10;
	double fConst11;
	double fRec9[2];
	double fRec7[2];
	double fRec6[2];
	double fRec4[2];
	double fConst12;
	double fRec3[2];
	double fRec1[2];
	double fConst13;
	double fConst14;
	double fConst15;
	double fConst16;
	double fConst17;
	double fRec41[3];
	double fRec42[3];
	double fRec43[3];
	double fRec44[3];
	double fRec45[3];
	double fRec46[3];
	double fRec47[3];
	double fRec48[3];
	double fRec49[3];
	double fRec40[2];
	double fRec38[2];
	double fRec37[2];
	double fRec35[2];
	double fConst18;
	double fConst19;
	double fConst20;
	double fRec34[2];
	double fRec32[2];
	double fRec31[2];
	double fRec29[2];
	double fConst21;
	double fConst22;
	double fConst23;
	double fConst24;
	double fConst25;
	double fRec59[3];
	double fRec60[3];
	double fRec61[3];
	double fRec62[3];
	double fRec63[3];
	double fRec64[3];
	double fRec65[3];
	double fRec58[2];
	double fRec56[2];
	double fRec55[2];
	double fRec53[2];
	double fConst26;
	double fRec52[2];
	double fRec50[2];
	double fConst27;
	double fRec72[3];
	double fRec73[3];
	double fRec74[3];
	double fRec75[3];
	double fRec76[3];
	double fConst28;
	double fConst29;
	double fRec71[2];
	double fRec69[2];
	double fRec68[2];
	double fRec66[2];
	double fConst30;
	double fRec80[3];
	double fRec81[3];
	double fRec82[3];
	double fConst31;
	double fRec79[2];
	double fRec77[2];
	double fRec83[3];
	int IOTA;
	double fVec0[1024];
	int iConst32;
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
	double fRec110[2];
	double fRec108[2];
	double fRec107[2];
	double fRec105[2];
	double fRec104[2];
	double fRec102[2];
	double fRec101[2];
	double fRec99[2];
	double fRec119[2];
	double fRec117[2];
	double fRec116[2];
	double fRec114[2];
	double fRec113[2];
	double fRec111[2];
	double fRec125[2];
	double fRec123[2];
	double fRec122[2];
	double fRec120[2];
	double fRec128[2];
	double fRec126[2];
	double fVec1[1024];
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
	double fRec170[2];
	double fRec168[2];
	double fRec167[2];
	double fRec165[2];
	double fRec173[2];
	double fRec171[2];
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
	double fRec209[2];
	double fRec207[2];
	double fRec206[2];
	double fRec204[2];
	double fRec203[2];
	double fRec201[2];
	double fRec215[2];
	double fRec213[2];
	double fRec212[2];
	double fRec210[2];
	double fRec218[2];
	double fRec216[2];
	double fVec3[1024];
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
	double fRec260[2];
	double fRec258[2];
	double fRec257[2];
	double fRec255[2];
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
	double fRec305[2];
	double fRec303[2];
	double fRec302[2];
	double fRec300[2];
	double fRec308[2];
	double fRec306[2];
	double fVec5[1024];
	double fRec317[2];
	double fRec315[2];
	double fRec314[2];
	double fRec312[2];
	double fRec311[2];
	double fRec309[2];
	double fRec323[2];
	double fRec321[2];
	double fRec320[2];
	double fRec318[2];
	double fRec326[2];
	double fRec324[2];
	double fRec338[2];
	double fRec336[2];
	double fRec335[2];
	double fRec333[2];
	double fRec332[2];
	double fRec330[2];
	double fRec329[2];
	double fRec327[2];
	double fRec353[2];
	double fRec351[2];
	double fRec350[2];
	double fRec348[2];
	double fRec347[2];
	double fRec345[2];
	double fRec344[2];
	double fRec342[2];
	double fRec341[2];
	double fRec339[2];
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
	double fRec524[2];
	double fRec522[2];
	double fRec521[2];
	double fRec519[2];
	double fRec518[2];
	double fRec516[2];
	double fRec530[2];
	double fRec528[2];
	double fRec527[2];
	double fRec525[2];
	double fRec533[2];
	double fRec531[2];
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
	double fRec575[2];
	double fRec573[2];
	double fRec572[2];
	double fRec570[2];
	double fRec578[2];
	double fRec576[2];
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
	double fRec620[2];
	double fRec618[2];
	double fRec617[2];
	double fRec615[2];
	double fRec623[2];
	double fRec621[2];
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
	double fRec665[2];
	double fRec663[2];
	double fRec662[2];
	double fRec660[2];
	double fRec668[2];
	double fRec666[2];
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
	double fRec710[2];
	double fRec708[2];
	double fRec707[2];
	double fRec705[2];
	double fRec713[2];
	double fRec711[2];
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
	double fRec755[2];
	double fRec753[2];
	double fRec752[2];
	double fRec750[2];
	double fRec758[2];
	double fRec756[2];
	double fVec15[1024];
	double fConst33;
	double fConst34;
	double fConst35;
	double fConst36;
	double fConst37;
	double fConst38;
	double fConst39;
	double fConst40;
	double fConst41;
	double fRec773[2];
	double fRec771[2];
	double fRec770[2];
	double fRec768[2];
	double fRec767[2];
	double fRec765[2];
	double fRec764[2];
	double fRec762[2];
	double fConst42;
	double fRec761[2];
	double fRec759[2];
	double fConst43;
	double fConst44;
	double fConst45;
	double fConst46;
	double fConst47;
	double fConst48;
	double fConst49;
	double fConst50;
	double fRec785[2];
	double fRec783[2];
	double fRec782[2];
	double fRec780[2];
	double fRec779[2];
	double fRec777[2];
	double fRec776[2];
	double fRec774[2];
	double fConst51;
	double fConst52;
	double fConst53;
	double fConst54;
	double fConst55;
	double fRec794[2];
	double fRec792[2];
	double fRec791[2];
	double fRec789[2];
	double fConst56;
	double fRec788[2];
	double fRec786[2];
	double fConst57;
	double fConst58;
	double fConst59;
	double fRec800[2];
	double fRec798[2];
	double fRec797[2];
	double fRec795[2];
	double fConst60;
	double fConst61;
	double fRec803[2];
	double fRec801[2];
	double fVec16[512];
	int iConst62;
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
	double fRec845[2];
	double fRec843[2];
	double fRec842[2];
	double fRec840[2];
	double fRec848[2];
	double fRec846[2];
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
	double fRec890[2];
	double fRec888[2];
	double fRec887[2];
	double fRec885[2];
	double fRec893[2];
	double fRec891[2];
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
	double fRec935[2];
	double fRec933[2];
	double fRec932[2];
	double fRec930[2];
	double fRec938[2];
	double fRec936[2];
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
	double fRec980[2];
	double fRec978[2];
	double fRec977[2];
	double fRec975[2];
	double fRec983[2];
	double fRec981[2];
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
	double fRec1025[2];
	double fRec1023[2];
	double fRec1022[2];
	double fRec1020[2];
	double fRec1028[2];
	double fRec1026[2];
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
	double fRec1070[2];
	double fRec1068[2];
	double fRec1067[2];
	double fRec1065[2];
	double fRec1073[2];
	double fRec1071[2];
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
	double fRec1115[2];
	double fRec1113[2];
	double fRec1112[2];
	double fRec1110[2];
	double fRec1118[2];
	double fRec1116[2];
	double fVec23[512];
	double fConst63;
	double fConst64;
	double fConst65;
	double fConst66;
	double fConst67;
	double fConst68;
	double fConst69;
	double fConst70;
	double fConst71;
	double fRec1133[2];
	double fRec1131[2];
	double fRec1130[2];
	double fRec1128[2];
	double fRec1127[2];
	double fRec1125[2];
	double fRec1124[2];
	double fRec1122[2];
	double fConst72;
	double fRec1121[2];
	double fRec1119[2];
	double fConst73;
	double fConst74;
	double fConst75;
	double fConst76;
	double fConst77;
	double fConst78;
	double fConst79;
	double fConst80;
	double fRec1145[2];
	double fRec1143[2];
	double fRec1142[2];
	double fRec1140[2];
	double fRec1139[2];
	double fRec1137[2];
	double fRec1136[2];
	double fRec1134[2];
	double fConst81;
	double fConst82;
	double fConst83;
	double fConst84;
	double fConst85;
	double fRec1154[2];
	double fRec1152[2];
	double fRec1151[2];
	double fRec1149[2];
	double fConst86;
	double fRec1148[2];
	double fRec1146[2];
	double fConst87;
	double fConst88;
	double fConst89;
	double fRec1160[2];
	double fRec1158[2];
	double fRec1157[2];
	double fRec1155[2];
	double fConst90;
	double fConst91;
	double fRec1163[2];
	double fRec1161[2];
	double fVec24[256];
	int iConst92;
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
	double fRec1205[2];
	double fRec1203[2];
	double fRec1202[2];
	double fRec1200[2];
	double fRec1208[2];
	double fRec1206[2];
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
	double fRec1250[2];
	double fRec1248[2];
	double fRec1247[2];
	double fRec1245[2];
	double fRec1253[2];
	double fRec1251[2];
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
	double fRec1295[2];
	double fRec1293[2];
	double fRec1292[2];
	double fRec1290[2];
	double fRec1298[2];
	double fRec1296[2];
	double fVec27[256];
	double fConst93;
	double fConst94;
	double fConst95;
	double fConst96;
	double fConst97;
	double fConst98;
	double fConst99;
	double fConst100;
	double fConst101;
	double fRec1313[2];
	double fRec1311[2];
	double fRec1310[2];
	double fRec1308[2];
	double fRec1307[2];
	double fRec1305[2];
	double fRec1304[2];
	double fRec1302[2];
	double fConst102;
	double fRec1301[2];
	double fRec1299[2];
	double fConst103;
	double fConst104;
	double fConst105;
	double fConst106;
	double fConst107;
	double fConst108;
	double fConst109;
	double fConst110;
	double fRec1325[2];
	double fRec1323[2];
	double fRec1322[2];
	double fRec1320[2];
	double fRec1319[2];
	double fRec1317[2];
	double fRec1316[2];
	double fRec1314[2];
	double fConst111;
	double fConst112;
	double fConst113;
	double fConst114;
	double fConst115;
	double fRec1334[2];
	double fRec1332[2];
	double fRec1331[2];
	double fRec1329[2];
	double fConst116;
	double fRec1328[2];
	double fRec1326[2];
	double fConst117;
	double fConst118;
	double fConst119;
	double fRec1340[2];
	double fRec1338[2];
	double fRec1337[2];
	double fRec1335[2];
	double fConst120;
	double fConst121;
	double fRec1343[2];
	double fRec1341[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit, Henrik Frisk");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMHLS_Dome_5h5p_normal_6.dsp");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMHLS_Dome_5h5p_normal_6");
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
	
	static void classInit(int sample_rate) {
		
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = double(std::min<int>(192000, std::max<int>(1, fSampleRate)));
		fConst1 = (1.0 / ((((25159.235463955636 / fConst0) + 173.07206373673586) / fConst0) + 1.0));
		fConst2 = (1.0 / fConst0);
		fConst3 = (100636.94185582254 / fConst0);
		fConst4 = (fConst3 + 346.14412747347171);
		fConst5 = ((135.74989273514609 / fConst0) + 1.0);
		fConst6 = ((((19777.399306469804 / fConst0) + 249.5532431201479) / fConst0) + 1.0);
		fConst7 = (1.0 / (fConst5 * fConst6));
		fConst8 = (3.1415926535897931 / fConst0);
		fConst9 = (1.0 / (fConst0 * fConst6));
		fConst10 = (79109.597225879217 / fConst0);
		fConst11 = (fConst10 + 499.10648624029579);
		fConst12 = (271.49978547029218 / (fConst0 * fConst5));
		fConst13 = (1.0 / ((((15918.663680972788 / fConst0) + 156.62717660663603) / fConst0) + 1.0));
		fConst14 = (63674.654723891152 / fConst0);
		fConst15 = (fConst14 + 313.25435321327205);
		fConst16 = ((((12665.494141837065 / fConst0) + 215.62295645471744) / fConst0) + 1.0);
		fConst17 = (1.0 / fConst16);
		fConst18 = (1.0 / (fConst0 * fConst16));
		fConst19 = (50661.976567348262 / fConst0);
		fConst20 = (fConst19 + 431.24591290943488);
		fConst21 = (1.0 / ((((8950.8463194903634 / fConst0) + 136.90669911154342) / fConst0) + 1.0));
		fConst22 = (35803.385277961454 / fConst0);
		fConst23 = (fConst22 + 273.81339822308684);
		fConst24 = ((86.443380725268696 / fConst0) + 1.0);
		fConst25 = (1.0 / fConst24);
		fConst26 = (172.88676145053739 / (fConst0 * fConst24));
		fConst27 = (1.0 / ((((4157.1048469258621 / fConst0) + 111.67503991840606) / fConst0) + 1.0));
		fConst28 = (16628.419387703449 / fConst0);
		fConst29 = (fConst28 + 223.35007983681211);
		fConst30 = (1.0 / ((37.225013306135352 / fConst0) + 1.0));
		fConst31 = (74.450026612270705 / fConst0);
		iConst32 = int(((0.0028145653948241961 * fConst0) + 0.5));
		fConst33 = ((((17635.000757786547 / fConst0) + 235.6494163834252) / fConst0) + 1.0);
		fConst34 = (1.0 / (fConst0 * fConst33));
		fConst35 = (70540.003031146189 / fConst0);
		fConst36 = (fConst35 + 471.29883276685041);
		fConst37 = (1.0 / ((((22433.846310978071 / fConst0) + 163.42937603980999) / fConst0) + 1.0));
		fConst38 = (89735.385243912286 / fConst0);
		fConst39 = (fConst38 + 326.85875207961999);
		fConst40 = ((128.18660497931657 / fConst0) + 1.0);
		fConst41 = (1.0 / (fConst40 * fConst33));
		fConst42 = (256.37320995863314 / (fConst0 * fConst40));
		fConst43 = ((((11293.496952148356 / fConst0) + 203.6095512610093) / fConst0) + 1.0);
		fConst44 = (1.0 / (fConst0 * fConst43));
		fConst45 = (45173.987808593425 / fConst0);
		fConst46 = (fConst45 + 407.2191025220186);
		fConst47 = (1.0 / ((((14194.264965114509 / fConst0) + 147.90071367402544) / fConst0) + 1.0));
		fConst48 = (56777.059860458037 / fConst0);
		fConst49 = (fConst48 + 295.80142734805088);
		fConst50 = (1.0 / fConst43);
		fConst51 = (1.0 / ((((7981.2405656089695 / fConst0) + 129.27896003773355) / fConst0) + 1.0));
		fConst52 = (31924.962262435878 / fConst0);
		fConst53 = (fConst52 + 258.55792007546711);
		fConst54 = ((81.627198923287324 / fConst0) + 1.0);
		fConst55 = (1.0 / fConst54);
		fConst56 = (163.25439784657465 / (fConst0 * fConst54));
		fConst57 = (1.0 / ((((3706.7839906409508 / fConst0) + 105.45307948051044) / fConst0) + 1.0));
		fConst58 = (14827.135962563803 / fConst0);
		fConst59 = (fConst58 + 210.90615896102088);
		fConst60 = (1.0 / ((35.15102649350348 / fConst0) + 1.0));
		fConst61 = (70.302052987006959 / fConst0);
		iConst62 = int(((0.0020220583685382951 * fConst0) + 0.5));
		fConst63 = ((((14867.491956047414 / fConst0) + 216.37021831556928) / fConst0) + 1.0);
		fConst64 = (1.0 / (fConst0 * fConst63));
		fConst65 = (59469.967824189654 / fConst0);
		fConst66 = (fConst65 + 432.74043663113855);
		fConst67 = (1.0 / ((((18913.241578648733 / fConst0) + 150.05871992220281) / fConst0) + 1.0));
		fConst68 = (75652.966314594931 / fConst0);
		fConst69 = (fConst68 + 300.11743984440562);
		fConst70 = ((117.6992675397825 / fConst0) + 1.0);
		fConst71 = (1.0 / (fConst70 * fConst63));
		fConst72 = (235.39853507956499 / (fConst0 * fConst70));
		fConst73 = ((((9521.1776510740765 / fConst0) + 186.95163235964782) / fConst0) + 1.0);
		fConst74 = (1.0 / (fConst0 * fConst73));
		fConst75 = (38084.710604296306 / fConst0);
		fConst76 = (fConst75 + 373.90326471929563);
		fConst77 = (1.0 / ((((11966.720222434136 / fConst0) + 135.80050482538877) / fConst0) + 1.0));
		fConst78 = (47866.880889736545 / fConst0);
		fConst79 = (fConst78 + 271.60100965077754);
		fConst80 = (1.0 / fConst73);
		fConst81 = (1.0 / ((((6728.7226997184644 / fConst0) + 118.70225369648584) / fConst0) + 1.0));
		fConst82 = (26914.890798873857 / fConst0);
		fConst83 = (fConst82 + 237.40450739297168);
		fConst84 = ((74.949028614536147 / fConst0) + 1.0);
		fConst85 = (1.0 / fConst84);
		fConst86 = (149.89805722907229 / (fConst0 * fConst84));
		fConst87 = (1.0 / ((((3125.0682617252614 / fConst0) + 96.825641155510993) / fConst0) + 1.0));
		fConst88 = (12500.273046901046 / fConst0);
		fConst89 = (fConst88 + 193.65128231102199);
		fConst90 = (1.0 / ((32.275213718503664 / fConst0) + 1.0));
		fConst91 = (64.550427437007329 / fConst0);
		iConst92 = int(((0.0007546298522354718 * fConst0) + 0.5));
		fConst93 = ((((13518.406533001747 / fConst0) + 206.32002345478514) / fConst0) + 1.0);
		fConst94 = (1.0 / (fConst0 * fConst93));
		fConst95 = (54073.62613200699 / fConst0);
		fConst96 = (fConst95 + 412.64004690957029);
		fConst97 = (1.0 / ((((17197.042330535627 / fConst0) + 143.0886323217992) / fConst0) + 1.0));
		fConst98 = (68788.169322142508 / fConst0);
		fConst99 = (fConst98 + 286.17726464359839);
		fConst100 = ((112.2322463251477 / fConst0) + 1.0);
		fConst101 = (1.0 / (fConst100 * fConst93));
		fConst102 = (224.4644926502954 / (fConst0 * fConst100));
		fConst103 = ((((8657.2200974217594 / fConst0) + 178.26790338167996) / fConst0) + 1.0);
		fConst104 = (1.0 / (fConst0 * fConst103));
		fConst105 = (34628.880389687038 / fConst0);
		fConst106 = (fConst105 + 356.53580676335991);
		fConst107 = (1.0 / ((((10880.852622069639 / fConst0) + 129.49269801947491) / fConst0) + 1.0));
		fConst108 = (43523.410488278554 / fConst0);
		fConst109 = (fConst108 + 258.98539603894983);
		fConst110 = (1.0 / fConst103);
		fConst111 = (1.0 / ((((6118.1542368773398 / fConst0) + 113.18864471022512) / fConst0) + 1.0));
		fConst112 = (24472.616947509359 / fConst0);
		fConst113 = (fConst112 + 226.37728942045024);
		fConst114 = ((71.467716130467849 / fConst0) + 1.0);
		fConst115 = (1.0 / fConst114);
		fConst116 = (142.9354322609357 / (fConst0 * fConst114));
		fConst117 = (1.0 / ((((2841.4976332440169 / fConst0) + 92.328180420346484) / fConst0) + 1.0));
		fConst118 = (11365.990532976068 / fConst0);
		fConst119 = (fConst118 + 184.65636084069297);
		fConst120 = (1.0 / ((30.776060140115494 / fConst0) + 1.0));
		fConst121 = (61.552120280230987 / fConst0);
		
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
			fRec16[l1] = 0.0;
			
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec17[l2] = 0.0;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
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
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec28[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec15[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec13[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec12[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec10[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec9[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec7[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec6[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec4[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec3[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec1[l23] = 0.0;
			
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
		for (int l32 = 0; (l32 < 3); l32 = (l32 + 1)) {
			fRec49[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec40[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec38[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec37[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec35[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec34[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec32[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec31[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec29[l40] = 0.0;
			
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
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec65[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec58[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec56[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec55[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec53[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec52[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fRec50[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) {
			fRec72[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec73[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec74[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 3); l57 = (l57 + 1)) {
			fRec75[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 3); l58 = (l58 + 1)) {
			fRec76[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec71[l59] = 0.0;
			
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			fRec69[l60] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec68[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec66[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 3); l63 = (l63 + 1)) {
			fRec80[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 3); l64 = (l64 + 1)) {
			fRec81[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 3); l65 = (l65 + 1)) {
			fRec82[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec79[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec77[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 3); l68 = (l68 + 1)) {
			fRec83[l68] = 0.0;
			
		}
		IOTA = 0;
		for (int l69 = 0; (l69 < 1024); l69 = (l69 + 1)) {
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
			fRec125[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec123[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fRec122[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec120[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec128[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec126[l99] = 0.0;
			
		}
		for (int l100 = 0; (l100 < 1024); l100 = (l100 + 1)) {
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
			fRec170[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec168[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec167[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec165[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec173[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec171[l130] = 0.0;
			
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
			fRec215[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec213[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec212[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec210[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec218[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec216[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 1024); l162 = (l162 + 1)) {
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
			fRec260[l187] = 0.0;
			
		}
		for (int l188 = 0; (l188 < 2); l188 = (l188 + 1)) {
			fRec258[l188] = 0.0;
			
		}
		for (int l189 = 0; (l189 < 2); l189 = (l189 + 1)) {
			fRec257[l189] = 0.0;
			
		}
		for (int l190 = 0; (l190 < 2); l190 = (l190 + 1)) {
			fRec255[l190] = 0.0;
			
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
			fRec308[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec306[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 1024); l224 = (l224 + 1)) {
			fVec5[l224] = 0.0;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec317[l225] = 0.0;
			
		}
		for (int l226 = 0; (l226 < 2); l226 = (l226 + 1)) {
			fRec315[l226] = 0.0;
			
		}
		for (int l227 = 0; (l227 < 2); l227 = (l227 + 1)) {
			fRec314[l227] = 0.0;
			
		}
		for (int l228 = 0; (l228 < 2); l228 = (l228 + 1)) {
			fRec312[l228] = 0.0;
			
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fRec311[l229] = 0.0;
			
		}
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec309[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fRec323[l231] = 0.0;
			
		}
		for (int l232 = 0; (l232 < 2); l232 = (l232 + 1)) {
			fRec321[l232] = 0.0;
			
		}
		for (int l233 = 0; (l233 < 2); l233 = (l233 + 1)) {
			fRec320[l233] = 0.0;
			
		}
		for (int l234 = 0; (l234 < 2); l234 = (l234 + 1)) {
			fRec318[l234] = 0.0;
			
		}
		for (int l235 = 0; (l235 < 2); l235 = (l235 + 1)) {
			fRec326[l235] = 0.0;
			
		}
		for (int l236 = 0; (l236 < 2); l236 = (l236 + 1)) {
			fRec324[l236] = 0.0;
			
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
			fRec353[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fRec351[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 2); l247 = (l247 + 1)) {
			fRec350[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 2); l248 = (l248 + 1)) {
			fRec348[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fRec347[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 2); l250 = (l250 + 1)) {
			fRec345[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 2); l251 = (l251 + 1)) {
			fRec344[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 2); l252 = (l252 + 1)) {
			fRec342[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec341[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec339[l254] = 0.0;
			
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
			fRec530[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec528[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 2); l375 = (l375 + 1)) {
			fRec527[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec525[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec533[l377] = 0.0;
			
		}
		for (int l378 = 0; (l378 < 2); l378 = (l378 + 1)) {
			fRec531[l378] = 0.0;
			
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
			fRec575[l404] = 0.0;
			
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec573[l405] = 0.0;
			
		}
		for (int l406 = 0; (l406 < 2); l406 = (l406 + 1)) {
			fRec572[l406] = 0.0;
			
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec570[l407] = 0.0;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec578[l408] = 0.0;
			
		}
		for (int l409 = 0; (l409 < 2); l409 = (l409 + 1)) {
			fRec576[l409] = 0.0;
			
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
			fRec620[l435] = 0.0;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec618[l436] = 0.0;
			
		}
		for (int l437 = 0; (l437 < 2); l437 = (l437 + 1)) {
			fRec617[l437] = 0.0;
			
		}
		for (int l438 = 0; (l438 < 2); l438 = (l438 + 1)) {
			fRec615[l438] = 0.0;
			
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec623[l439] = 0.0;
			
		}
		for (int l440 = 0; (l440 < 2); l440 = (l440 + 1)) {
			fRec621[l440] = 0.0;
			
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
			fRec665[l466] = 0.0;
			
		}
		for (int l467 = 0; (l467 < 2); l467 = (l467 + 1)) {
			fRec663[l467] = 0.0;
			
		}
		for (int l468 = 0; (l468 < 2); l468 = (l468 + 1)) {
			fRec662[l468] = 0.0;
			
		}
		for (int l469 = 0; (l469 < 2); l469 = (l469 + 1)) {
			fRec660[l469] = 0.0;
			
		}
		for (int l470 = 0; (l470 < 2); l470 = (l470 + 1)) {
			fRec668[l470] = 0.0;
			
		}
		for (int l471 = 0; (l471 < 2); l471 = (l471 + 1)) {
			fRec666[l471] = 0.0;
			
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
			fRec710[l497] = 0.0;
			
		}
		for (int l498 = 0; (l498 < 2); l498 = (l498 + 1)) {
			fRec708[l498] = 0.0;
			
		}
		for (int l499 = 0; (l499 < 2); l499 = (l499 + 1)) {
			fRec707[l499] = 0.0;
			
		}
		for (int l500 = 0; (l500 < 2); l500 = (l500 + 1)) {
			fRec705[l500] = 0.0;
			
		}
		for (int l501 = 0; (l501 < 2); l501 = (l501 + 1)) {
			fRec713[l501] = 0.0;
			
		}
		for (int l502 = 0; (l502 < 2); l502 = (l502 + 1)) {
			fRec711[l502] = 0.0;
			
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
			fRec755[l528] = 0.0;
			
		}
		for (int l529 = 0; (l529 < 2); l529 = (l529 + 1)) {
			fRec753[l529] = 0.0;
			
		}
		for (int l530 = 0; (l530 < 2); l530 = (l530 + 1)) {
			fRec752[l530] = 0.0;
			
		}
		for (int l531 = 0; (l531 < 2); l531 = (l531 + 1)) {
			fRec750[l531] = 0.0;
			
		}
		for (int l532 = 0; (l532 < 2); l532 = (l532 + 1)) {
			fRec758[l532] = 0.0;
			
		}
		for (int l533 = 0; (l533 < 2); l533 = (l533 + 1)) {
			fRec756[l533] = 0.0;
			
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
			fRec800[l559] = 0.0;
			
		}
		for (int l560 = 0; (l560 < 2); l560 = (l560 + 1)) {
			fRec798[l560] = 0.0;
			
		}
		for (int l561 = 0; (l561 < 2); l561 = (l561 + 1)) {
			fRec797[l561] = 0.0;
			
		}
		for (int l562 = 0; (l562 < 2); l562 = (l562 + 1)) {
			fRec795[l562] = 0.0;
			
		}
		for (int l563 = 0; (l563 < 2); l563 = (l563 + 1)) {
			fRec803[l563] = 0.0;
			
		}
		for (int l564 = 0; (l564 < 2); l564 = (l564 + 1)) {
			fRec801[l564] = 0.0;
			
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
			fRec845[l590] = 0.0;
			
		}
		for (int l591 = 0; (l591 < 2); l591 = (l591 + 1)) {
			fRec843[l591] = 0.0;
			
		}
		for (int l592 = 0; (l592 < 2); l592 = (l592 + 1)) {
			fRec842[l592] = 0.0;
			
		}
		for (int l593 = 0; (l593 < 2); l593 = (l593 + 1)) {
			fRec840[l593] = 0.0;
			
		}
		for (int l594 = 0; (l594 < 2); l594 = (l594 + 1)) {
			fRec848[l594] = 0.0;
			
		}
		for (int l595 = 0; (l595 < 2); l595 = (l595 + 1)) {
			fRec846[l595] = 0.0;
			
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
			fRec890[l621] = 0.0;
			
		}
		for (int l622 = 0; (l622 < 2); l622 = (l622 + 1)) {
			fRec888[l622] = 0.0;
			
		}
		for (int l623 = 0; (l623 < 2); l623 = (l623 + 1)) {
			fRec887[l623] = 0.0;
			
		}
		for (int l624 = 0; (l624 < 2); l624 = (l624 + 1)) {
			fRec885[l624] = 0.0;
			
		}
		for (int l625 = 0; (l625 < 2); l625 = (l625 + 1)) {
			fRec893[l625] = 0.0;
			
		}
		for (int l626 = 0; (l626 < 2); l626 = (l626 + 1)) {
			fRec891[l626] = 0.0;
			
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
			fRec935[l652] = 0.0;
			
		}
		for (int l653 = 0; (l653 < 2); l653 = (l653 + 1)) {
			fRec933[l653] = 0.0;
			
		}
		for (int l654 = 0; (l654 < 2); l654 = (l654 + 1)) {
			fRec932[l654] = 0.0;
			
		}
		for (int l655 = 0; (l655 < 2); l655 = (l655 + 1)) {
			fRec930[l655] = 0.0;
			
		}
		for (int l656 = 0; (l656 < 2); l656 = (l656 + 1)) {
			fRec938[l656] = 0.0;
			
		}
		for (int l657 = 0; (l657 < 2); l657 = (l657 + 1)) {
			fRec936[l657] = 0.0;
			
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
			fRec980[l683] = 0.0;
			
		}
		for (int l684 = 0; (l684 < 2); l684 = (l684 + 1)) {
			fRec978[l684] = 0.0;
			
		}
		for (int l685 = 0; (l685 < 2); l685 = (l685 + 1)) {
			fRec977[l685] = 0.0;
			
		}
		for (int l686 = 0; (l686 < 2); l686 = (l686 + 1)) {
			fRec975[l686] = 0.0;
			
		}
		for (int l687 = 0; (l687 < 2); l687 = (l687 + 1)) {
			fRec983[l687] = 0.0;
			
		}
		for (int l688 = 0; (l688 < 2); l688 = (l688 + 1)) {
			fRec981[l688] = 0.0;
			
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
			fRec1025[l714] = 0.0;
			
		}
		for (int l715 = 0; (l715 < 2); l715 = (l715 + 1)) {
			fRec1023[l715] = 0.0;
			
		}
		for (int l716 = 0; (l716 < 2); l716 = (l716 + 1)) {
			fRec1022[l716] = 0.0;
			
		}
		for (int l717 = 0; (l717 < 2); l717 = (l717 + 1)) {
			fRec1020[l717] = 0.0;
			
		}
		for (int l718 = 0; (l718 < 2); l718 = (l718 + 1)) {
			fRec1028[l718] = 0.0;
			
		}
		for (int l719 = 0; (l719 < 2); l719 = (l719 + 1)) {
			fRec1026[l719] = 0.0;
			
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
			fRec1070[l745] = 0.0;
			
		}
		for (int l746 = 0; (l746 < 2); l746 = (l746 + 1)) {
			fRec1068[l746] = 0.0;
			
		}
		for (int l747 = 0; (l747 < 2); l747 = (l747 + 1)) {
			fRec1067[l747] = 0.0;
			
		}
		for (int l748 = 0; (l748 < 2); l748 = (l748 + 1)) {
			fRec1065[l748] = 0.0;
			
		}
		for (int l749 = 0; (l749 < 2); l749 = (l749 + 1)) {
			fRec1073[l749] = 0.0;
			
		}
		for (int l750 = 0; (l750 < 2); l750 = (l750 + 1)) {
			fRec1071[l750] = 0.0;
			
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
			fRec1115[l776] = 0.0;
			
		}
		for (int l777 = 0; (l777 < 2); l777 = (l777 + 1)) {
			fRec1113[l777] = 0.0;
			
		}
		for (int l778 = 0; (l778 < 2); l778 = (l778 + 1)) {
			fRec1112[l778] = 0.0;
			
		}
		for (int l779 = 0; (l779 < 2); l779 = (l779 + 1)) {
			fRec1110[l779] = 0.0;
			
		}
		for (int l780 = 0; (l780 < 2); l780 = (l780 + 1)) {
			fRec1118[l780] = 0.0;
			
		}
		for (int l781 = 0; (l781 < 2); l781 = (l781 + 1)) {
			fRec1116[l781] = 0.0;
			
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
			fRec1160[l807] = 0.0;
			
		}
		for (int l808 = 0; (l808 < 2); l808 = (l808 + 1)) {
			fRec1158[l808] = 0.0;
			
		}
		for (int l809 = 0; (l809 < 2); l809 = (l809 + 1)) {
			fRec1157[l809] = 0.0;
			
		}
		for (int l810 = 0; (l810 < 2); l810 = (l810 + 1)) {
			fRec1155[l810] = 0.0;
			
		}
		for (int l811 = 0; (l811 < 2); l811 = (l811 + 1)) {
			fRec1163[l811] = 0.0;
			
		}
		for (int l812 = 0; (l812 < 2); l812 = (l812 + 1)) {
			fRec1161[l812] = 0.0;
			
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
			fRec1205[l838] = 0.0;
			
		}
		for (int l839 = 0; (l839 < 2); l839 = (l839 + 1)) {
			fRec1203[l839] = 0.0;
			
		}
		for (int l840 = 0; (l840 < 2); l840 = (l840 + 1)) {
			fRec1202[l840] = 0.0;
			
		}
		for (int l841 = 0; (l841 < 2); l841 = (l841 + 1)) {
			fRec1200[l841] = 0.0;
			
		}
		for (int l842 = 0; (l842 < 2); l842 = (l842 + 1)) {
			fRec1208[l842] = 0.0;
			
		}
		for (int l843 = 0; (l843 < 2); l843 = (l843 + 1)) {
			fRec1206[l843] = 0.0;
			
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
			fRec1250[l869] = 0.0;
			
		}
		for (int l870 = 0; (l870 < 2); l870 = (l870 + 1)) {
			fRec1248[l870] = 0.0;
			
		}
		for (int l871 = 0; (l871 < 2); l871 = (l871 + 1)) {
			fRec1247[l871] = 0.0;
			
		}
		for (int l872 = 0; (l872 < 2); l872 = (l872 + 1)) {
			fRec1245[l872] = 0.0;
			
		}
		for (int l873 = 0; (l873 < 2); l873 = (l873 + 1)) {
			fRec1253[l873] = 0.0;
			
		}
		for (int l874 = 0; (l874 < 2); l874 = (l874 + 1)) {
			fRec1251[l874] = 0.0;
			
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
			fRec1295[l900] = 0.0;
			
		}
		for (int l901 = 0; (l901 < 2); l901 = (l901 + 1)) {
			fRec1293[l901] = 0.0;
			
		}
		for (int l902 = 0; (l902 < 2); l902 = (l902 + 1)) {
			fRec1292[l902] = 0.0;
			
		}
		for (int l903 = 0; (l903 < 2); l903 = (l903 + 1)) {
			fRec1290[l903] = 0.0;
			
		}
		for (int l904 = 0; (l904 < 2); l904 = (l904 + 1)) {
			fRec1298[l904] = 0.0;
			
		}
		for (int l905 = 0; (l905 < 2); l905 = (l905 + 1)) {
			fRec1296[l905] = 0.0;
			
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
			fRec1340[l931] = 0.0;
			
		}
		for (int l932 = 0; (l932 < 2); l932 = (l932 + 1)) {
			fRec1338[l932] = 0.0;
			
		}
		for (int l933 = 0; (l933 < 2); l933 = (l933 + 1)) {
			fRec1337[l933] = 0.0;
			
		}
		for (int l934 = 0; (l934 < 2); l934 = (l934 + 1)) {
			fRec1335[l934] = 0.0;
			
		}
		for (int l935 = 0; (l935 < 2); l935 = (l935 + 1)) {
			fRec1343[l935] = 0.0;
			
		}
		for (int l936 = 0; (l936 < 2); l936 = (l936 + 1)) {
			fRec1341[l936] = 0.0;
			
		}
		
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
		
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("KMHLS_Dome_5h5p_normal_6");
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
			fRec16[0] = (fSlow1 + (0.999 * fRec16[1]));
			double fTemp0 = std::tan((fConst8 * fRec16[0]));
			double fTemp1 = mydsp_faustpower2_f(fTemp0);
			double fTemp2 = ((fTemp0 * (fTemp0 + -2.0)) + 1.0);
			double fTemp3 = (fTemp1 + -1.0);
			double fTemp4 = ((fTemp0 * (fTemp0 + 2.0)) + 1.0);
			fRec17[0] = (double(input29[i]) - (((fTemp2 * fRec17[2]) + (2.0 * (fTemp3 * fRec17[1]))) / fTemp4));
			fRec18[0] = (fSlow2 + (0.999 * fRec18[1]));
			double fTemp5 = (fRec18[0] * fTemp4);
			double fTemp6 = (0.0 - (2.0 / fTemp4));
			double fTemp7 = (((fTemp1 * (fRec17[2] + (fRec17[0] + (2.0 * fRec17[1])))) / fTemp5) + (0.20571231109999999 * (fRec18[0] * (0.0 - ((fTemp6 * fRec17[1]) + ((fRec17[0] + fRec17[2]) / fTemp4))))));
			fRec19[0] = (double(input30[i]) - (((fTemp2 * fRec19[2]) + (2.0 * (fTemp3 * fRec19[1]))) / fTemp4));
			double fTemp8 = (((fTemp1 * (fRec19[2] + (fRec19[0] + (2.0 * fRec19[1])))) / fTemp5) + (0.20571231109999999 * (fRec18[0] * (0.0 - ((fTemp6 * fRec19[1]) + ((fRec19[0] + fRec19[2]) / fTemp4))))));
			fRec20[0] = (double(input31[i]) - (((fTemp2 * fRec20[2]) + (2.0 * (fTemp3 * fRec20[1]))) / fTemp4));
			double fTemp9 = (((fTemp1 * (fRec20[2] + (fRec20[0] + (2.0 * fRec20[1])))) / fTemp5) + (0.20571231109999999 * (fRec18[0] * (0.0 - ((fTemp6 * fRec20[1]) + ((fRec20[0] + fRec20[2]) / fTemp4))))));
			fRec21[0] = (double(input34[i]) - (((fTemp2 * fRec21[2]) + (2.0 * (fTemp3 * fRec21[1]))) / fTemp4));
			double fTemp10 = (((fTemp1 * (fRec21[2] + (fRec21[0] + (2.0 * fRec21[1])))) / fTemp5) + (0.20571231109999999 * (fRec18[0] * (0.0 - ((fTemp6 * fRec21[1]) + ((fRec21[0] + fRec21[2]) / fTemp4))))));
			fRec22[0] = (double(input25[i]) - (((fTemp2 * fRec22[2]) + (2.0 * (fTemp3 * fRec22[1]))) / fTemp4));
			double fTemp11 = (((fTemp1 * (fRec22[2] + (fRec22[0] + (2.0 * fRec22[1])))) / fTemp5) + (0.20571231109999999 * (fRec18[0] * (0.0 - ((fTemp6 * fRec22[1]) + ((fRec22[0] + fRec22[2]) / fTemp4))))));
			fRec23[0] = (double(input26[i]) - (((fTemp2 * fRec23[2]) + (2.0 * (fTemp3 * fRec23[1]))) / fTemp4));
			double fTemp12 = (((fTemp1 * (fRec23[2] + (fRec23[0] + (2.0 * fRec23[1])))) / fTemp5) + (0.20571231109999999 * (fRec18[0] * (0.0 - ((fTemp6 * fRec23[1]) + ((fRec23[0] + fRec23[2]) / fTemp4))))));
			fRec24[0] = (double(input27[i]) - (((fTemp2 * fRec24[2]) + (2.0 * (fTemp3 * fRec24[1]))) / fTemp4));
			double fTemp13 = (((fTemp1 * (fRec24[2] + (fRec24[0] + (2.0 * fRec24[1])))) / fTemp5) + (0.20571231109999999 * (fRec18[0] * (0.0 - ((fTemp6 * fRec24[1]) + ((fRec24[0] + fRec24[2]) / fTemp4))))));
			fRec25[0] = (double(input28[i]) - (((fTemp2 * fRec25[2]) + (2.0 * (fTemp3 * fRec25[1]))) / fTemp4));
			double fTemp14 = (((fTemp1 * (fRec25[2] + (fRec25[0] + (2.0 * fRec25[1])))) / fTemp5) + (0.20571231109999999 * (fRec18[0] * (0.0 - ((fTemp6 * fRec25[1]) + ((fRec25[0] + fRec25[2]) / fTemp4))))));
			fRec26[0] = (double(input32[i]) - (((fTemp2 * fRec26[2]) + (2.0 * (fTemp3 * fRec26[1]))) / fTemp4));
			double fTemp15 = (((fTemp1 * (fRec26[2] + (fRec26[0] + (2.0 * fRec26[1])))) / fTemp5) + (0.20571231109999999 * (fRec18[0] * (0.0 - ((fTemp6 * fRec26[1]) + ((fRec26[0] + fRec26[2]) / fTemp4))))));
			fRec27[0] = (double(input33[i]) - (((fTemp2 * fRec27[2]) + (2.0 * (fTemp3 * fRec27[1]))) / fTemp4));
			double fTemp16 = (((fTemp1 * (fRec27[2] + (fRec27[0] + (2.0 * fRec27[1])))) / fTemp5) + (0.20571231109999999 * (fRec18[0] * (0.0 - ((fTemp6 * fRec27[1]) + ((fRec27[0] + fRec27[2]) / fTemp4))))));
			fRec28[0] = (double(input35[i]) - (((fTemp2 * fRec28[2]) + (2.0 * (fTemp3 * fRec28[1]))) / fTemp4));
			double fTemp17 = (((fTemp1 * (fRec28[2] + (fRec28[0] + (2.0 * fRec28[1])))) / fTemp5) + (0.20571231109999999 * (fRec18[0] * (0.0 - ((fTemp6 * fRec28[1]) + ((fRec28[0] + fRec28[2]) / fTemp4))))));
			double fTemp18 = (fConst1 * ((fConst2 * (0.0 - ((fConst4 * fRec13[1]) + (fConst3 * fRec10[1])))) + (fConst7 * (((((0.0054692498999999997 * fTemp7) + (0.025605406399999999 * fTemp8)) + (0.0122225202 * fTemp9)) + (0.0080098557000000004 * fTemp10)) - (((((((0.00051876210000000001 * fTemp11) + (0.0245638509 * fTemp12)) + (0.0093127706000000008 * fTemp13)) + (0.041273748200000002 * fTemp14)) + (0.0089632995000000007 * fTemp15)) + (0.0022866255000000002 * fTemp16)) + (0.16803774860000001 * fTemp17))))));
			fRec15[0] = (fRec15[1] + fTemp18);
			fRec13[0] = fRec15[0];
			double fRec14 = fTemp18;
			fRec12[0] = (fRec13[0] + fRec12[1]);
			fRec10[0] = fRec12[0];
			double fRec11 = fRec14;
			double fTemp19 = (fConst9 * (0.0 - ((fConst11 * fRec7[1]) + (fConst10 * fRec4[1]))));
			fRec9[0] = (fRec11 + (fRec9[1] + fTemp19));
			fRec7[0] = fRec9[0];
			double fRec8 = (fRec11 + fTemp19);
			fRec6[0] = (fRec7[0] + fRec6[1]);
			fRec4[0] = fRec6[0];
			double fRec5 = fRec8;
			double fTemp20 = (fConst12 * fRec1[1]);
			fRec3[0] = ((fRec5 + fRec3[1]) - fTemp20);
			fRec1[0] = fRec3[0];
			double fRec2 = (fRec5 - fTemp20);
			fRec41[0] = (double(input16[i]) - (((fTemp2 * fRec41[2]) + (2.0 * (fTemp3 * fRec41[1]))) / fTemp4));
			double fTemp21 = (((fTemp1 * (fRec41[2] + (fRec41[0] + (2.0 * fRec41[1])))) / fTemp5) + (0.42200500930000001 * (fRec18[0] * (0.0 - ((fTemp6 * fRec41[1]) + ((fRec41[0] + fRec41[2]) / fTemp4))))));
			fRec42[0] = (double(input20[i]) - (((fTemp2 * fRec42[2]) + (2.0 * (fTemp3 * fRec42[1]))) / fTemp4));
			double fTemp22 = (((fTemp1 * (fRec42[2] + (fRec42[0] + (2.0 * fRec42[1])))) / fTemp5) + (0.42200500930000001 * (fRec18[0] * (0.0 - ((fTemp6 * fRec42[1]) + ((fRec42[0] + fRec42[2]) / fTemp4))))));
			fRec43[0] = (double(input17[i]) - (((fTemp2 * fRec43[2]) + (2.0 * (fTemp3 * fRec43[1]))) / fTemp4));
			double fTemp23 = (((fTemp1 * (fRec43[2] + (fRec43[0] + (2.0 * fRec43[1])))) / fTemp5) + (0.42200500930000001 * (fRec18[0] * (0.0 - ((fTemp6 * fRec43[1]) + ((fRec43[0] + fRec43[2]) / fTemp4))))));
			fRec44[0] = (double(input18[i]) - (((fTemp2 * fRec44[2]) + (2.0 * (fTemp3 * fRec44[1]))) / fTemp4));
			double fTemp24 = (((fTemp1 * (fRec44[2] + (fRec44[0] + (2.0 * fRec44[1])))) / fTemp5) + (0.42200500930000001 * (fRec18[0] * (0.0 - ((fTemp6 * fRec44[1]) + ((fRec44[0] + fRec44[2]) / fTemp4))))));
			fRec45[0] = (double(input19[i]) - (((fTemp2 * fRec45[2]) + (2.0 * (fTemp3 * fRec45[1]))) / fTemp4));
			double fTemp25 = (((fTemp1 * (fRec45[2] + (fRec45[0] + (2.0 * fRec45[1])))) / fTemp5) + (0.42200500930000001 * (fRec18[0] * (0.0 - ((fTemp6 * fRec45[1]) + ((fRec45[0] + fRec45[2]) / fTemp4))))));
			fRec46[0] = (double(input21[i]) - (((fTemp2 * fRec46[2]) + (2.0 * (fTemp3 * fRec46[1]))) / fTemp4));
			double fTemp26 = (((fTemp1 * (fRec46[2] + (fRec46[0] + (2.0 * fRec46[1])))) / fTemp5) + (0.42200500930000001 * (fRec18[0] * (0.0 - ((fTemp6 * fRec46[1]) + ((fRec46[0] + fRec46[2]) / fTemp4))))));
			fRec47[0] = (double(input22[i]) - (((fTemp2 * fRec47[2]) + (2.0 * (fTemp3 * fRec47[1]))) / fTemp4));
			double fTemp27 = (((fTemp1 * (fRec47[2] + (fRec47[0] + (2.0 * fRec47[1])))) / fTemp5) + (0.42200500930000001 * (fRec18[0] * (0.0 - ((fTemp6 * fRec47[1]) + ((fRec47[0] + fRec47[2]) / fTemp4))))));
			fRec48[0] = (double(input23[i]) - (((fTemp2 * fRec48[2]) + (2.0 * (fTemp3 * fRec48[1]))) / fTemp4));
			double fTemp28 = (((fTemp1 * (fRec48[2] + (fRec48[0] + (2.0 * fRec48[1])))) / fTemp5) + (0.42200500930000001 * (fRec18[0] * (0.0 - ((fTemp6 * fRec48[1]) + ((fRec48[0] + fRec48[2]) / fTemp4))))));
			fRec49[0] = (double(input24[i]) - (((fTemp2 * fRec49[2]) + (2.0 * (fTemp3 * fRec49[1]))) / fTemp4));
			double fTemp29 = (((fTemp1 * (fRec49[2] + (fRec49[0] + (2.0 * fRec49[1])))) / fTemp5) + (0.42200500930000001 * (fRec18[0] * (0.0 - ((fTemp6 * fRec49[1]) + ((fRec49[0] + fRec49[2]) / fTemp4))))));
			double fTemp30 = (fConst13 * ((fConst2 * (0.0 - ((fConst15 * fRec38[1]) + (fConst14 * fRec35[1])))) + (fConst17 * (((0.1017768928 * fTemp21) + (0.018566114799999998 * fTemp22)) - (((((((0.026705150600000001 * fTemp23) + (0.026031991300000001 * fTemp24)) + (0.018025295100000002 * fTemp25)) + (0.020171640899999999 * fTemp26)) + (0.010759039099999999 * fTemp27)) + (0.0031356171999999999 * fTemp28)) + (0.14230859500000001 * fTemp29))))));
			fRec40[0] = (fRec40[1] + fTemp30);
			fRec38[0] = fRec40[0];
			double fRec39 = fTemp30;
			fRec37[0] = (fRec38[0] + fRec37[1]);
			fRec35[0] = fRec37[0];
			double fRec36 = fRec39;
			double fTemp31 = (fConst18 * (0.0 - ((fConst20 * fRec32[1]) + (fConst19 * fRec29[1]))));
			fRec34[0] = (fRec36 + (fRec34[1] + fTemp31));
			fRec32[0] = fRec34[0];
			double fRec33 = (fRec36 + fTemp31);
			fRec31[0] = (fRec32[0] + fRec31[1]);
			fRec29[0] = fRec31[0];
			double fRec30 = fRec33;
			fRec59[0] = (double(input9[i]) - (((fTemp2 * fRec59[2]) + (2.0 * (fTemp3 * fRec59[1]))) / fTemp4));
			double fTemp32 = (((fTemp1 * (fRec59[2] + (fRec59[0] + (2.0 * fRec59[1])))) / fTemp5) + (0.62824992459999995 * (fRec18[0] * (0.0 - ((fTemp6 * fRec59[1]) + ((fRec59[0] + fRec59[2]) / fTemp4))))));
			fRec60[0] = (double(input10[i]) - (((fTemp2 * fRec60[2]) + (2.0 * (fTemp3 * fRec60[1]))) / fTemp4));
			double fTemp33 = (((fTemp1 * (fRec60[2] + (fRec60[0] + (2.0 * fRec60[1])))) / fTemp5) + (0.62824992459999995 * (fRec18[0] * (0.0 - ((fTemp6 * fRec60[1]) + ((fRec60[0] + fRec60[2]) / fTemp4))))));
			fRec61[0] = (double(input11[i]) - (((fTemp2 * fRec61[2]) + (2.0 * (fTemp3 * fRec61[1]))) / fTemp4));
			double fTemp34 = (((fTemp1 * (fRec61[2] + (fRec61[0] + (2.0 * fRec61[1])))) / fTemp5) + (0.62824992459999995 * (fRec18[0] * (0.0 - ((fTemp6 * fRec61[1]) + ((fRec61[0] + fRec61[2]) / fTemp4))))));
			fRec62[0] = (double(input12[i]) - (((fTemp2 * fRec62[2]) + (2.0 * (fTemp3 * fRec62[1]))) / fTemp4));
			double fTemp35 = (((fTemp1 * (fRec62[2] + (fRec62[0] + (2.0 * fRec62[1])))) / fTemp5) + (0.62824992459999995 * (fRec18[0] * (0.0 - ((fTemp6 * fRec62[1]) + ((fRec62[0] + fRec62[2]) / fTemp4))))));
			fRec63[0] = (double(input13[i]) - (((fTemp2 * fRec63[2]) + (2.0 * (fTemp3 * fRec63[1]))) / fTemp4));
			double fTemp36 = (((fTemp1 * (fRec63[2] + (fRec63[0] + (2.0 * fRec63[1])))) / fTemp5) + (0.62824992459999995 * (fRec18[0] * (0.0 - ((fTemp6 * fRec63[1]) + ((fRec63[0] + fRec63[2]) / fTemp4))))));
			fRec64[0] = (double(input14[i]) - (((fTemp2 * fRec64[2]) + (2.0 * (fTemp3 * fRec64[1]))) / fTemp4));
			double fTemp37 = (((fTemp1 * (fRec64[2] + (fRec64[0] + (2.0 * fRec64[1])))) / fTemp5) + (0.62824992459999995 * (fRec18[0] * (0.0 - ((fTemp6 * fRec64[1]) + ((fRec64[0] + fRec64[2]) / fTemp4))))));
			fRec65[0] = (double(input15[i]) - (((fTemp2 * fRec65[2]) + (2.0 * (fTemp3 * fRec65[1]))) / fTemp4));
			double fTemp38 = (((fTemp1 * (fRec65[2] + (fRec65[0] + (2.0 * fRec65[1])))) / fTemp5) + (0.62824992459999995 * (fRec18[0] * (0.0 - ((fTemp6 * fRec65[1]) + ((fRec65[0] + fRec65[2]) / fTemp4))))));
			double fTemp39 = (fConst21 * ((fConst2 * (0.0 - ((fConst23 * fRec56[1]) + (fConst22 * fRec53[1])))) + (fConst25 * ((0.1622545282 * fTemp32) - ((((((0.024057898099999999 * fTemp33) + (0.0298325246 * fTemp34)) + (0.0021655190999999999 * fTemp35)) + (0.041760736 * fTemp36)) + (0.0148752695 * fTemp37)) + (0.054301215399999998 * fTemp38))))));
			fRec58[0] = (fRec58[1] + fTemp39);
			fRec56[0] = fRec58[0];
			double fRec57 = fTemp39;
			fRec55[0] = (fRec56[0] + fRec55[1]);
			fRec53[0] = fRec55[0];
			double fRec54 = fRec57;
			double fTemp40 = (fConst26 * fRec50[1]);
			fRec52[0] = ((fRec54 + fRec52[1]) - fTemp40);
			fRec50[0] = fRec52[0];
			double fRec51 = (fRec54 - fTemp40);
			fRec72[0] = (double(input4[i]) - (((fTemp2 * fRec72[2]) + (2.0 * (fTemp3 * fRec72[1]))) / fTemp4));
			double fTemp41 = (((fTemp1 * (fRec72[2] + (fRec72[0] + (2.0 * fRec72[1])))) / fTemp5) + (0.80424909239999998 * (fRec18[0] * (0.0 - ((fTemp6 * fRec72[1]) + ((fRec72[0] + fRec72[2]) / fTemp4))))));
			fRec73[0] = (double(input8[i]) - (((fTemp2 * fRec73[2]) + (2.0 * (fTemp3 * fRec73[1]))) / fTemp4));
			double fTemp42 = (((fTemp1 * (fRec73[2] + (fRec73[0] + (2.0 * fRec73[1])))) / fTemp5) + (0.80424909239999998 * (fRec18[0] * (0.0 - ((fTemp6 * fRec73[1]) + ((fRec73[0] + fRec73[2]) / fTemp4))))));
			fRec74[0] = (double(input5[i]) - (((fTemp2 * fRec74[2]) + (2.0 * (fTemp3 * fRec74[1]))) / fTemp4));
			double fTemp43 = (((fTemp1 * (fRec74[2] + (fRec74[0] + (2.0 * fRec74[1])))) / fTemp5) + (0.80424909239999998 * (fRec18[0] * (0.0 - ((fTemp6 * fRec74[1]) + ((fRec74[0] + fRec74[2]) / fTemp4))))));
			fRec75[0] = (double(input6[i]) - (((fTemp2 * fRec75[2]) + (2.0 * (fTemp3 * fRec75[1]))) / fTemp4));
			double fTemp44 = (((fTemp1 * (fRec75[2] + (fRec75[0] + (2.0 * fRec75[1])))) / fTemp5) + (0.80424909239999998 * (fRec18[0] * (0.0 - ((fTemp6 * fRec75[1]) + ((fRec75[0] + fRec75[2]) / fTemp4))))));
			fRec76[0] = (double(input7[i]) - (((fTemp2 * fRec76[2]) + (2.0 * (fTemp3 * fRec76[1]))) / fTemp4));
			double fTemp45 = (((fTemp1 * (fRec76[2] + (fRec76[0] + (2.0 * fRec76[1])))) / fTemp5) + (0.80424909239999998 * (fRec18[0] * (0.0 - ((fTemp6 * fRec76[1]) + ((fRec76[0] + fRec76[2]) / fTemp4))))));
			double fTemp46 = (fConst27 * ((((0.1469509473 * fTemp41) + (0.0465245793 * fTemp42)) - (((0.0144956852 * fTemp43) + (0.055047154600000002 * fTemp44)) + (0.024390740300000002 * fTemp45))) + (fConst2 * (0.0 - ((fConst29 * fRec69[1]) + (fConst28 * fRec66[1]))))));
			fRec71[0] = (fRec71[1] + fTemp46);
			fRec69[0] = fRec71[0];
			double fRec70 = fTemp46;
			fRec68[0] = (fRec69[0] + fRec68[1]);
			fRec66[0] = fRec68[0];
			double fRec67 = fRec70;
			fRec80[0] = (double(input1[i]) - (((fTemp2 * fRec80[2]) + (2.0 * (fTemp3 * fRec80[1]))) / fTemp4));
			double fTemp47 = (((fTemp1 * (fRec80[2] + (fRec80[0] + (2.0 * fRec80[1])))) / fTemp5) + (0.93246951420000002 * (fRec18[0] * (0.0 - ((fTemp6 * fRec80[1]) + ((fRec80[0] + fRec80[2]) / fTemp4))))));
			fRec81[0] = (double(input3[i]) - (((fTemp2 * fRec81[2]) + (2.0 * (fTemp3 * fRec81[1]))) / fTemp4));
			double fTemp48 = (((fTemp1 * (fRec81[2] + (fRec81[0] + (2.0 * fRec81[1])))) / fTemp5) + (0.93246951420000002 * (fRec18[0] * (0.0 - ((fTemp6 * fRec81[1]) + ((fRec81[0] + fRec81[2]) / fTemp4))))));
			fRec82[0] = (double(input2[i]) - (((fTemp2 * fRec82[2]) + (2.0 * (fTemp3 * fRec82[1]))) / fTemp4));
			double fTemp49 = (((fTemp1 * (fRec82[2] + (fRec82[0] + (2.0 * fRec82[1])))) / fTemp5) + (0.93246951420000002 * (fRec18[0] * (0.0 - ((fTemp6 * fRec82[1]) + ((fRec82[0] + fRec82[2]) / fTemp4))))));
			double fTemp50 = (fConst30 * ((((0.071586830300000001 * fTemp47) + (0.097640750100000007 * fTemp48)) - (0.016439957200000001 * fTemp49)) - (fConst31 * fRec77[1])));
			fRec79[0] = (fRec79[1] + fTemp50);
			fRec77[0] = fRec79[0];
			double fRec78 = fTemp50;
			fRec83[0] = (double(input0[i]) - (((fRec83[2] * fTemp2) + (2.0 * (fRec83[1] * fTemp3))) / fTemp4));
			double fTemp51 = (((fTemp1 * (fRec83[2] + (fRec83[0] + (2.0 * fRec83[1])))) / fTemp5) + (fRec18[0] * (0.0 - ((fRec83[1] * fTemp6) + ((fRec83[0] + fRec83[2]) / fTemp4)))));
			fVec0[(IOTA & 1023)] = (fRec2 + (fRec30 + (fRec51 + (fRec67 + (fRec78 + (0.045516111300000002 * fTemp51))))));
			output0[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec0[((IOTA - iConst32) & 1023)])));
			double fTemp52 = (fConst9 * (0.0 - ((fConst11 * fRec90[1]) + (fConst10 * fRec87[1]))));
			double fTemp53 = (fConst1 * ((fConst2 * (0.0 - ((fConst4 * fRec96[1]) + (fConst3 * fRec93[1])))) + (fConst7 * ((((((0.14204408600000001 * fTemp11) + (0.0065158096999999998 * fTemp7)) + (0.013522907900000001 * fTemp8)) + (0.031824351899999999 * fTemp9)) + (0.067856711 * fTemp17)) - ((((((0.0304920513 * fTemp12) + (0.010833832 * fTemp13)) + (0.0115577639 * fTemp14)) + (0.019860437000000002 * fTemp15)) + (0.0153451343 * fTemp16)) + (0.031950860400000003 * fTemp10))))));
			fRec98[0] = (fRec98[1] + fTemp53);
			fRec96[0] = fRec98[0];
			double fRec97 = fTemp53;
			fRec95[0] = (fRec96[0] + fRec95[1]);
			fRec93[0] = fRec95[0];
			double fRec94 = fRec97;
			fRec92[0] = (fTemp52 + (fRec94 + fRec92[1]));
			fRec90[0] = fRec92[0];
			double fRec91 = (fRec94 + fTemp52);
			fRec89[0] = (fRec90[0] + fRec89[1]);
			fRec87[0] = fRec89[0];
			double fRec88 = fRec91;
			double fTemp54 = (fConst12 * fRec84[1]);
			fRec86[0] = ((fRec88 + fRec86[1]) - fTemp54);
			fRec84[0] = fRec86[0];
			double fRec85 = (fRec88 - fTemp54);
			double fTemp55 = (fConst18 * (0.0 - ((fConst20 * fRec102[1]) + (fConst19 * fRec99[1]))));
			double fTemp56 = (fConst13 * ((fConst2 * (0.0 - ((fConst15 * fRec108[1]) + (fConst14 * fRec105[1])))) + (fConst17 * ((((0.1262312437 * fTemp21) + (0.026085545000000002 * fTemp22)) + (0.1005566247 * fTemp29)) - ((((((0.0271664782 * fTemp23) + (0.0141253649 * fTemp24)) + (0.0018970648 * fTemp25)) + (0.0038360565999999998 * fTemp26)) + (0.0302844931 * fTemp27)) + (0.040712696399999998 * fTemp28))))));
			fRec110[0] = (fRec110[1] + fTemp56);
			fRec108[0] = fRec110[0];
			double fRec109 = fTemp56;
			fRec107[0] = (fRec108[0] + fRec107[1]);
			fRec105[0] = fRec107[0];
			double fRec106 = fRec109;
			fRec104[0] = (fTemp55 + (fRec106 + fRec104[1]));
			fRec102[0] = fRec104[0];
			double fRec103 = (fRec106 + fTemp55);
			fRec101[0] = (fRec102[0] + fRec101[1]);
			fRec99[0] = fRec101[0];
			double fRec100 = fRec103;
			double fTemp57 = (fConst21 * ((fConst2 * (0.0 - ((fConst23 * fRec117[1]) + (fConst22 * fRec114[1])))) + (fConst25 * ((((0.097059238699999995 * fTemp32) + (0.0137764659 * fTemp35)) + (0.1218701485 * fTemp38)) - ((((0.019583497200000001 * fTemp33) + (0.0110642116 * fTemp34)) + (0.048826395799999998 * fTemp36)) + (0.046133351199999999 * fTemp37))))));
			fRec119[0] = (fRec119[1] + fTemp57);
			fRec117[0] = fRec119[0];
			double fRec118 = fTemp57;
			fRec116[0] = (fRec117[0] + fRec116[1]);
			fRec114[0] = fRec116[0];
			double fRec115 = fRec118;
			double fTemp58 = (fConst26 * fRec111[1]);
			fRec113[0] = ((fRec115 + fRec113[1]) - fTemp58);
			fRec111[0] = fRec113[0];
			double fRec112 = (fRec115 - fTemp58);
			double fTemp59 = (fConst27 * ((((0.0601762198 * fTemp41) + (0.12525324409999999 * fTemp42)) - (((0.0093175714000000003 * fTemp43) + (0.049692294599999999 * fTemp44)) + (0.0448848897 * fTemp45))) + (fConst2 * (0.0 - ((fConst29 * fRec123[1]) + (fConst28 * fRec120[1]))))));
			fRec125[0] = (fRec125[1] + fTemp59);
			fRec123[0] = fRec125[0];
			double fRec124 = fTemp59;
			fRec122[0] = (fRec123[0] + fRec122[1]);
			fRec120[0] = fRec122[0];
			double fRec121 = fRec124;
			double fTemp60 = (fConst30 * ((((0.024070503100000001 * fTemp47) + (0.1057768072 * fTemp48)) - (0.023531261000000001 * fTemp49)) - (fConst31 * fRec126[1])));
			fRec128[0] = (fRec128[1] + fTemp60);
			fRec126[0] = fRec128[0];
			double fRec127 = fTemp60;
			fVec1[(IOTA & 1023)] = (fRec85 + (fRec100 + (fRec112 + (fRec121 + (fRec127 + (0.040761164599999997 * fTemp51))))));
			output1[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec1[((IOTA - iConst32) & 1023)])));
			double fTemp61 = (fConst9 * (0.0 - ((fConst11 * fRec135[1]) + (fConst10 * fRec132[1]))));
			double fTemp62 = (fConst1 * ((fConst2 * (0.0 - ((fConst4 * fRec141[1]) + (fConst3 * fRec138[1])))) + (fConst7 * (((((((0.024528943099999999 * fTemp12) + (0.0081944628999999995 * fTemp13)) + (0.0093692500000000008 * fTemp14)) + (0.025763212099999998 * fTemp8)) + (0.0135194298 * fTemp9)) + (0.1187555503 * fTemp17)) - (((((0.1200846465 * fTemp11) + (0.0048753824000000003 * fTemp7)) + (0.041383614999999999 * fTemp15)) + (0.0054095167999999999 * fTemp16)) + (0.0088415630999999998 * fTemp10))))));
			fRec143[0] = (fRec143[1] + fTemp62);
			fRec141[0] = fRec143[0];
			double fRec142 = fTemp62;
			fRec140[0] = (fRec141[0] + fRec140[1]);
			fRec138[0] = fRec140[0];
			double fRec139 = fRec142;
			fRec137[0] = (fTemp61 + (fRec139 + fRec137[1]));
			fRec135[0] = fRec137[0];
			double fRec136 = (fRec139 + fTemp61);
			fRec134[0] = (fRec135[0] + fRec134[1]);
			fRec132[0] = fRec134[0];
			double fRec133 = fRec136;
			double fTemp63 = (fConst12 * fRec129[1]);
			fRec131[0] = ((fRec133 + fRec131[1]) - fTemp63);
			fRec129[0] = fRec131[0];
			double fRec130 = (fRec133 - fTemp63);
			double fTemp64 = (fConst18 * (0.0 - ((fConst20 * fRec147[1]) + (fConst19 * fRec144[1]))));
			double fTemp65 = (fConst13 * ((fConst2 * (0.0 - ((fConst15 * fRec153[1]) + (fConst14 * fRec150[1])))) + (fConst17 * ((((((0.021255139700000002 * fTemp23) + (0.010948785900000001 * fTemp24)) + (0.0016793146999999999 * fTemp25)) + (0.019246670600000002 * fTemp22)) + (0.14297327500000001 * fTemp29)) - ((((0.1038200881 * fTemp21) + (0.026777868400000002 * fTemp26)) + (0.0266978363 * fTemp27)) + (0.0177548766 * fTemp28))))));
			fRec155[0] = (fRec155[1] + fTemp65);
			fRec153[0] = fRec155[0];
			double fRec154 = fTemp65;
			fRec152[0] = (fRec153[0] + fRec152[1]);
			fRec150[0] = fRec152[0];
			double fRec151 = fRec154;
			fRec149[0] = (fTemp64 + (fRec151 + fRec149[1]));
			fRec147[0] = fRec149[0];
			double fRec148 = (fRec151 + fTemp64);
			fRec146[0] = (fRec147[0] + fRec146[1]);
			fRec144[0] = fRec146[0];
			double fRec145 = fRec148;
			double fTemp66 = (fConst21 * ((fConst2 * (0.0 - ((fConst23 * fRec162[1]) + (fConst22 * fRec159[1])))) + (fConst25 * ((((0.0150852179 * fTemp33) + (0.0086371095000000002 * fTemp34)) + (0.15472521859999999 * fTemp38)) - ((((0.078220605200000001 * fTemp32) + (0.0016405848999999999 * fTemp35)) + (0.051604712900000002 * fTemp36)) + (0.0253070988 * fTemp37))))));
			fRec164[0] = (fRec164[1] + fTemp66);
			fRec162[0] = fRec164[0];
			double fRec163 = fTemp66;
			fRec161[0] = (fRec162[0] + fRec161[1]);
			fRec159[0] = fRec161[0];
			double fRec160 = fRec163;
			double fTemp67 = (fConst26 * fRec156[1]);
			fRec158[0] = ((fRec160 + fRec158[1]) - fTemp67);
			fRec156[0] = fRec158[0];
			double fRec157 = (fRec160 - fTemp67);
			double fTemp68 = (fConst27 * ((((0.0071355784999999998 * fTemp43) + (0.1490434893 * fTemp42)) - (((0.047824110199999999 * fTemp41) + (0.056006683699999997 * fTemp44)) + (0.028704830099999998 * fTemp45))) + (fConst2 * (0.0 - ((fConst29 * fRec168[1]) + (fConst28 * fRec165[1]))))));
			fRec170[0] = (fRec170[1] + fTemp68);
			fRec168[0] = fRec170[0];
			double fRec169 = fTemp68;
			fRec167[0] = (fRec168[0] + fRec167[1]);
			fRec165[0] = fRec167[0];
			double fRec166 = fRec169;
			double fTemp69 = (fConst30 * (((0.1216281125 * fTemp48) - ((0.018975220399999999 * fTemp47) + (0.0170522078 * fTemp49))) - (fConst31 * fRec171[1])));
			fRec173[0] = (fRec173[1] + fTemp69);
			fRec171[0] = fRec173[0];
			double fRec172 = fTemp69;
			fVec2[(IOTA & 1023)] = (fRec130 + (fRec145 + (fRec157 + (fRec166 + (fRec172 + (0.0462990151 * fTemp51))))));
			output2[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec2[((IOTA - iConst32) & 1023)])));
			double fTemp70 = (fConst9 * (0.0 - ((fConst11 * fRec180[1]) + (fConst10 * fRec177[1]))));
			double fTemp71 = (fConst1 * ((fConst2 * (0.0 - ((fConst4 * fRec186[1]) + (fConst3 * fRec183[1])))) + (fConst7 * ((((((((0.029847310599999999 * fTemp12) + (0.018528276699999999 * fTemp13)) + (0.0199050427 * fTemp14)) + (0.0136574494 * fTemp8)) + (0.027015304 * fTemp9)) + (0.0035414790000000002 * fTemp16)) + (0.032798924799999997 * fTemp10)) - ((((0.048531574500000001 * fTemp11) + (0.018077489400000001 * fTemp7)) + (0.0113323665 * fTemp15)) + (0.14988777859999999 * fTemp17))))));
			fRec188[0] = (fRec188[1] + fTemp71);
			fRec186[0] = fRec188[0];
			double fRec187 = fTemp71;
			fRec185[0] = (fRec186[0] + fRec185[1]);
			fRec183[0] = fRec185[0];
			double fRec184 = fRec187;
			fRec182[0] = (fTemp70 + (fRec184 + fRec182[1]));
			fRec180[0] = fRec182[0];
			double fRec181 = (fRec184 + fTemp70);
			fRec179[0] = (fRec180[0] + fRec179[1]);
			fRec177[0] = fRec179[0];
			double fRec178 = fRec181;
			double fTemp72 = (fConst12 * fRec174[1]);
			fRec176[0] = ((fRec178 + fRec176[1]) - fTemp72);
			fRec174[0] = fRec176[0];
			double fRec175 = (fRec178 - fTemp72);
			double fTemp73 = (fConst18 * (0.0 - ((fConst20 * fRec192[1]) + (fConst19 * fRec189[1]))));
			double fTemp74 = (fConst13 * ((fConst2 * (0.0 - ((fConst15 * fRec198[1]) + (fConst14 * fRec195[1])))) + (fConst17 * ((((((0.0480452923 * fTemp23) + (0.030564337300000001 * fTemp24)) + (0.0012816253999999999 * fTemp25)) + (0.0260373268 * fTemp22)) + (0.010449711299999999 * fTemp28)) - ((((0.1243140745 * fTemp21) + (0.0038961770999999998 * fTemp26)) + (0.0138512507 * fTemp27)) + (0.1033804128 * fTemp29))))));
			fRec200[0] = (fRec200[1] + fTemp74);
			fRec198[0] = fRec200[0];
			double fRec199 = fTemp74;
			fRec197[0] = (fRec198[0] + fRec197[1]);
			fRec195[0] = fRec197[0];
			double fRec196 = fRec199;
			fRec194[0] = (fTemp73 + (fRec196 + fRec194[1]));
			fRec192[0] = fRec194[0];
			double fRec193 = (fRec196 + fTemp73);
			fRec191[0] = (fRec192[0] + fRec191[1]);
			fRec189[0] = fRec191[0];
			double fRec190 = fRec193;
			double fTemp75 = (fConst21 * ((fConst2 * (0.0 - ((fConst23 * fRec207[1]) + (fConst22 * fRec204[1])))) + (fConst25 * ((((0.046567382400000003 * fTemp33) + (0.0270487643 * fTemp34)) + (0.0140234162 * fTemp35)) - ((((0.1549101306 * fTemp32) + (0.042404592200000001 * fTemp36)) + (0.019153562400000001 * fTemp37)) + (0.020017535600000001 * fTemp38))))));
			fRec209[0] = (fRec209[1] + fTemp75);
			fRec207[0] = fRec209[0];
			double fRec208 = fTemp75;
			fRec206[0] = (fRec207[0] + fRec206[1]);
			fRec204[0] = fRec206[0];
			double fRec205 = fRec208;
			double fTemp76 = (fConst26 * fRec201[1]);
			fRec203[0] = ((fRec205 + fRec203[1]) - fTemp76);
			fRec201[0] = fRec203[0];
			double fRec202 = (fRec205 - fTemp76);
			double fTemp77 = (fConst27 * ((((0.0254689889 * fTemp43) + (0.059052657299999999 * fTemp42)) - (((0.12625715260000001 * fTemp41) + (0.049965192200000001 * fTemp44)) + (0.038347881399999999 * fTemp45))) + (fConst2 * (0.0 - ((fConst29 * fRec213[1]) + (fConst28 * fRec210[1]))))));
			fRec215[0] = (fRec215[1] + fTemp77);
			fRec213[0] = fRec215[0];
			double fRec214 = fTemp77;
			fRec212[0] = (fRec213[0] + fRec212[1]);
			fRec210[0] = fRec212[0];
			double fRec211 = fRec214;
			double fTemp78 = (fConst30 * (((0.091816812499999997 * fTemp48) - ((0.058441326199999998 * fTemp47) + (0.023577950399999999 * fTemp49))) - (fConst31 * fRec216[1])));
			fRec218[0] = (fRec218[1] + fTemp78);
			fRec216[0] = fRec218[0];
			double fRec217 = fTemp78;
			fVec3[(IOTA & 1023)] = (fRec175 + (fRec190 + (fRec202 + (fRec211 + (fRec217 + (0.040882448600000003 * fTemp51))))));
			output3[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec3[((IOTA - iConst32) & 1023)])));
			double fTemp79 = (fConst9 * (0.0 - ((fConst11 * fRec225[1]) + (fConst10 * fRec222[1]))));
			double fTemp80 = (fConst1 * ((fConst2 * (0.0 - ((fConst4 * fRec231[1]) + (fConst3 * fRec228[1])))) + (fConst7 * (((((((((0.16913761760000001 * fTemp11) + (0.0418836816 * fTemp14)) + (0.026082075199999999 * fTemp8)) + (0.0058612954999999996 * fTemp9)) + (0.0104597006 * fTemp15)) + (0.0094475731000000004 * fTemp16)) + (0.0075992344999999996 * fTemp10)) + (0.0101939011 * fTemp17)) - (((0.025009579300000001 * fTemp12) + (0.0024633148000000001 * fTemp13)) + (0.013031675100000001 * fTemp7))))));
			fRec233[0] = (fRec233[1] + fTemp80);
			fRec231[0] = fRec233[0];
			double fRec232 = fTemp80;
			fRec230[0] = (fRec231[0] + fRec230[1]);
			fRec228[0] = fRec230[0];
			double fRec229 = fRec232;
			fRec227[0] = (fTemp79 + (fRec229 + fRec227[1]));
			fRec225[0] = fRec227[0];
			double fRec226 = (fRec229 + fTemp79);
			fRec224[0] = (fRec225[0] + fRec224[1]);
			fRec222[0] = fRec224[0];
			double fRec223 = fRec226;
			double fTemp81 = (fConst12 * fRec219[1]);
			fRec221[0] = ((fRec223 + fRec221[1]) - fTemp81);
			fRec219[0] = fRec221[0];
			double fRec220 = (fRec223 - fTemp81);
			double fTemp82 = (fConst18 * (0.0 - ((fConst20 * fRec237[1]) + (fConst19 * fRec234[1]))));
			double fTemp83 = (fConst13 * ((fConst2 * (0.0 - ((fConst15 * fRec243[1]) + (fConst14 * fRec240[1])))) + (fConst17 * (((((((0.1108501195 * fTemp21) + (0.026577578099999999 * fTemp24)) + (0.02086855 * fTemp25)) + (0.019472051099999999 * fTemp22)) + (0.011668777 * fTemp27)) + (0.027492638600000001 * fTemp28)) - (((0.0035940332 * fTemp23) + (0.017996710400000001 * fTemp26)) + (0.13931355549999999 * fTemp29))))));
			fRec245[0] = (fRec245[1] + fTemp83);
			fRec243[0] = fRec245[0];
			double fRec244 = fTemp83;
			fRec242[0] = (fRec243[0] + fRec242[1]);
			fRec240[0] = fRec242[0];
			double fRec241 = fRec244;
			fRec239[0] = (fTemp82 + (fRec241 + fRec239[1]));
			fRec237[0] = fRec239[0];
			double fRec238 = (fRec241 + fTemp82);
			fRec236[0] = (fRec237[0] + fRec236[1]);
			fRec234[0] = fRec236[0];
			double fRec235 = fRec238;
			double fTemp84 = (fConst21 * ((fConst2 * (0.0 - ((fConst23 * fRec252[1]) + (fConst22 * fRec249[1])))) + (fConst25 * ((((0.024930579200000001 * fTemp33) + (0.043427742900000003 * fTemp34)) + (0.015782055 * fTemp37)) - ((((0.049125078900000001 * fTemp32) + (0.002027816 * fTemp35)) + (0.0302226866 * fTemp36)) + (0.16821880750000001 * fTemp38))))));
			fRec254[0] = (fRec254[1] + fTemp84);
			fRec252[0] = fRec254[0];
			double fRec253 = fTemp84;
			fRec251[0] = (fRec252[0] + fRec251[1]);
			fRec249[0] = fRec251[0];
			double fRec250 = fRec253;
			double fTemp85 = (fConst26 * fRec246[1]);
			fRec248[0] = ((fRec250 + fRec248[1]) - fTemp85);
			fRec246[0] = fRec248[0];
			double fRec247 = (fRec250 - fTemp85);
			double fTemp86 = (fConst27 * (((0.025643109599999998 * fTemp43) - ((((0.1498746608 * fTemp41) + (0.056713020599999997 * fTemp44)) + (0.014990696499999999 * fTemp45)) + (0.051785676900000001 * fTemp42))) + (fConst2 * (0.0 - ((fConst29 * fRec258[1]) + (fConst28 * fRec255[1]))))));
			fRec260[0] = (fRec260[1] + fTemp86);
			fRec258[0] = fRec260[0];
			double fRec259 = fTemp86;
			fRec257[0] = (fRec258[0] + fRec257[1]);
			fRec255[0] = fRec257[0];
			double fRec256 = fRec259;
			double fTemp87 = (fConst30 * (((0.072509489100000005 * fTemp48) - ((0.1016666058 * fTemp47) + (0.017216940600000001 * fTemp49))) - (fConst31 * fRec261[1])));
			fRec263[0] = (fRec263[1] + fTemp87);
			fRec261[0] = fRec263[0];
			double fRec262 = fTemp87;
			fVec4[(IOTA & 1023)] = (fRec220 + (fRec235 + (fRec247 + (fRec256 + (fRec262 + (0.047004010800000003 * fTemp51))))));
			output4[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec4[((IOTA - iConst32) & 1023)])));
			double fTemp88 = (fConst9 * (0.0 - ((fConst11 * fRec270[1]) + (fConst10 * fRec267[1]))));
			double fTemp89 = (fConst1 * ((fConst2 * (0.0 - ((fConst4 * fRec276[1]) + (fConst3 * fRec273[1])))) + (fConst7 * (((((((0.0108072108 * fTemp14) + (0.0138288648 * fTemp8)) + (0.0060483452000000002 * fTemp9)) + (0.020466809999999998 * fTemp15)) + (0.0102096388 * fTemp16)) + (0.13587434670000001 * fTemp17)) - (((((0.080729308 * fTemp11) + (0.028506407099999999 * fTemp12)) + (0.0160792513 * fTemp13)) + (0.0323617681 * fTemp7)) + (0.034172117799999999 * fTemp10))))));
			fRec278[0] = (fRec278[1] + fTemp89);
			fRec276[0] = fRec278[0];
			double fRec277 = fTemp89;
			fRec275[0] = (fRec276[0] + fRec275[1]);
			fRec273[0] = fRec275[0];
			double fRec274 = fRec277;
			fRec272[0] = (fTemp88 + (fRec274 + fRec272[1]));
			fRec270[0] = fRec272[0];
			double fRec271 = (fRec274 + fTemp88);
			fRec269[0] = (fRec270[0] + fRec269[1]);
			fRec267[0] = fRec269[0];
			double fRec268 = fRec271;
			double fTemp90 = (fConst12 * fRec264[1]);
			fRec266[0] = ((fRec268 + fRec266[1]) - fTemp90);
			fRec264[0] = fRec266[0];
			double fRec265 = (fRec268 - fTemp90);
			double fTemp91 = (fConst18 * (0.0 - ((fConst20 * fRec282[1]) + (fConst19 * fRec279[1]))));
			double fTemp92 = (fConst13 * ((fConst2 * (0.0 - ((fConst15 * fRec288[1]) + (fConst14 * fRec285[1])))) + (fConst17 * ((((((((0.119617759 * fTemp21) + (0.013283941800000001 * fTemp24)) + (0.0037685520000000001 * fTemp25)) + (0.026361701099999999 * fTemp22)) + (0.0312020202 * fTemp27)) + (0.0253888572 * fTemp28)) + (0.11015482579999999 * fTemp29)) - ((0.042490355600000002 * fTemp23) + (0.0017460816 * fTemp26))))));
			fRec290[0] = (fRec290[1] + fTemp92);
			fRec288[0] = fRec290[0];
			double fRec289 = fTemp92;
			fRec287[0] = (fRec288[0] + fRec287[1]);
			fRec285[0] = fRec287[0];
			double fRec286 = fRec289;
			fRec284[0] = (fTemp91 + (fRec286 + fRec284[1]));
			fRec282[0] = fRec284[0];
			double fRec283 = (fRec286 + fTemp91);
			fRec281[0] = (fRec282[0] + fRec281[1]);
			fRec279[0] = fRec281[0];
			double fRec280 = fRec283;
			double fTemp93 = (fConst21 * ((fConst2 * (0.0 - ((fConst23 * fRec297[1]) + (fConst22 * fRec294[1])))) + (fConst25 * ((((((0.12815799589999999 * fTemp32) + (0.018275929199999999 * fTemp33)) + (0.049752041699999999 * fTemp34)) + (0.0141515627 * fTemp35)) + (0.047388156600000002 * fTemp37)) - ((0.0103759639 * fTemp36) + (0.091354549399999999 * fTemp38))))));
			fRec299[0] = (fRec299[1] + fTemp93);
			fRec297[0] = fRec299[0];
			double fRec298 = fTemp93;
			fRec296[0] = (fRec297[0] + fRec296[1]);
			fRec294[0] = fRec296[0];
			double fRec295 = fRec298;
			double fTemp94 = (fConst26 * fRec291[1]);
			fRec293[0] = ((fRec295 + fRec293[1]) - fTemp94);
			fRec291[0] = fRec293[0];
			double fRec292 = (fRec295 - fTemp94);
			double fTemp95 = (fConst27 * (((0.0456690347 * fTemp43) - ((((0.056378535100000002 * fTemp41) + (0.050466321500000001 * fTemp44)) + (0.0086800188999999993 * fTemp45)) + (0.12882164700000001 * fTemp42))) + (fConst2 * (0.0 - ((fConst29 * fRec303[1]) + (fConst28 * fRec300[1]))))));
			fRec305[0] = (fRec305[1] + fTemp95);
			fRec303[0] = fRec305[0];
			double fRec304 = fTemp95;
			fRec302[0] = (fRec303[0] + fRec302[1]);
			fRec300[0] = fRec302[0];
			double fRec301 = fRec304;
			double fTemp96 = (fConst30 * (((0.0224882187 * fTemp48) - ((0.1075533969 * fTemp47) + (0.0238195688 * fTemp49))) - (fConst31 * fRec306[1])));
			fRec308[0] = (fRec308[1] + fTemp96);
			fRec306[0] = fRec308[0];
			double fRec307 = fTemp96;
			fVec5[(IOTA & 1023)] = (fRec265 + (fRec280 + (fRec292 + (fRec301 + (fRec307 + (0.041283035900000001 * fTemp51))))));
			output5[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec5[((IOTA - iConst32) & 1023)])));
			double fTemp97 = (fConst21 * ((fConst2 * (0.0 - ((fConst23 * fRec315[1]) + (fConst22 * fRec312[1])))) + (fConst25 * ((((((0.14949616560000001 * fTemp32) + (0.052506193299999997 * fTemp34)) + (0.0105500761 * fTemp36)) + (0.0245960741 * fTemp37)) + (0.094423353500000001 * fTemp38)) - ((0.016903074099999998 * fTemp33) + (0.0019129273999999999 * fTemp35))))));
			fRec317[0] = (fRec317[1] + fTemp97);
			fRec315[0] = fRec317[0];
			double fRec316 = fTemp97;
			fRec314[0] = (fRec315[0] + fRec314[1]);
			fRec312[0] = fRec314[0];
			double fRec313 = fRec316;
			double fTemp98 = (fConst26 * fRec309[1]);
			fRec311[0] = ((fRec313 + fRec311[1]) - fTemp98);
			fRec309[0] = fRec311[0];
			double fRec310 = (fRec313 - fTemp98);
			double fTemp99 = (fConst27 * (((((0.058589913299999997 * fTemp41) + (0.028949595700000001 * fTemp43)) + (0.0081857836999999992 * fTemp45)) - ((0.057461898499999997 * fTemp44) + (0.14917678640000001 * fTemp42))) + (fConst2 * (0.0 - ((fConst29 * fRec321[1]) + (fConst28 * fRec318[1]))))));
			fRec323[0] = (fRec323[1] + fTemp99);
			fRec321[0] = fRec323[0];
			double fRec322 = fTemp99;
			fRec320[0] = (fRec321[0] + fRec320[1]);
			fRec318[0] = fRec320[0];
			double fRec319 = fRec322;
			double fTemp100 = (fConst30 * ((0.0 - (((0.12414152420000001 * fTemp47) + (0.0174064037 * fTemp49)) + (0.023448789000000001 * fTemp48))) - (fConst31 * fRec324[1])));
			fRec326[0] = (fRec326[1] + fTemp100);
			fRec324[0] = fRec326[0];
			double fRec325 = fTemp100;
			double fTemp101 = (fConst18 * (0.0 - ((fConst20 * fRec330[1]) + (fConst19 * fRec327[1]))));
			double fTemp102 = (fConst13 * ((fConst2 * (0.0 - ((fConst15 * fRec336[1]) + (fConst14 * fRec333[1])))) + (fConst17 * ((((((0.027637718700000001 * fTemp25) + (0.019614027999999999 * fTemp22)) + (0.0026214063999999999 * fTemp26)) + (0.0263549857 * fTemp27)) + (0.13056731890000001 * fTemp29)) - ((((0.1226936755 * fTemp21) + (0.015755353900000001 * fTemp23)) + (0.0128833986 * fTemp24)) + (0.023072761600000002 * fTemp28))))));
			fRec338[0] = (fRec338[1] + fTemp102);
			fRec336[0] = fRec338[0];
			double fRec337 = fTemp102;
			fRec335[0] = (fRec336[0] + fRec335[1]);
			fRec333[0] = fRec335[0];
			double fRec334 = fRec337;
			fRec332[0] = (fTemp101 + (fRec334 + fRec332[1]));
			fRec330[0] = fRec332[0];
			double fRec331 = (fRec334 + fTemp101);
			fRec329[0] = (fRec330[0] + fRec329[1]);
			fRec327[0] = fRec329[0];
			double fRec328 = fRec331;
			double fTemp103 = (fConst9 * (0.0 - ((fConst11 * fRec345[1]) + (fConst10 * fRec342[1]))));
			double fTemp104 = (fConst1 * ((fConst2 * (0.0 - ((fConst4 * fRec351[1]) + (fConst3 * fRec348[1])))) + (fConst7 * ((((0.0255626482 * fTemp12) + (0.026464233899999998 * fTemp8)) + (0.041775442000000003 * fTemp15)) - ((((((((0.099192251300000006 * fTemp11) + (0.0044476721000000002 * fTemp13)) + (0.0122827518 * fTemp14)) + (0.013390920299999999 * fTemp7)) + (0.0053433773000000004 * fTemp9)) + (0.0087263862000000001 * fTemp16)) + (0.0057005398000000004 * fTemp10)) + (0.13795071859999999 * fTemp17))))));
			fRec353[0] = (fRec353[1] + fTemp104);
			fRec351[0] = fRec353[0];
			double fRec352 = fTemp104;
			fRec350[0] = (fRec351[0] + fRec350[1]);
			fRec348[0] = fRec350[0];
			double fRec349 = fRec352;
			fRec347[0] = (fTemp103 + (fRec349 + fRec347[1]));
			fRec345[0] = fRec347[0];
			double fRec346 = (fRec349 + fTemp103);
			fRec344[0] = (fRec345[0] + fRec344[1]);
			fRec342[0] = fRec344[0];
			double fRec343 = fRec346;
			double fTemp105 = (fConst12 * fRec339[1]);
			fRec341[0] = ((fRec343 + fRec341[1]) - fTemp105);
			fRec339[0] = fRec341[0];
			double fRec340 = (fRec343 - fTemp105);
			fVec6[(IOTA & 1023)] = (fRec310 + (fRec319 + (fRec325 + ((0.0475581666 * fTemp51) + (fRec328 + fRec340)))));
			output6[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec6[((IOTA - iConst32) & 1023)])));
			double fTemp106 = (fConst9 * (0.0 - ((fConst11 * fRec360[1]) + (fConst10 * fRec357[1]))));
			double fTemp107 = (fConst1 * ((fConst2 * (0.0 - ((fConst4 * fRec366[1]) + (fConst3 * fRec363[1])))) + (fConst7 * (((((((0.15723919859999999 * fTemp11) + (0.025426929500000001 * fTemp12)) + (0.0053892254999999998 * fTemp13)) + (0.0139257505 * fTemp8)) + (0.0100893992 * fTemp15)) + (0.036752594100000001 * fTemp10)) - (((((0.021263014600000001 * fTemp14) + (0.027153221700000001 * fTemp7)) + (0.019474125700000001 * fTemp9)) + (0.0183969067 * fTemp16)) + (0.021723513400000002 * fTemp17))))));
			fRec368[0] = (fRec368[1] + fTemp107);
			fRec366[0] = fRec368[0];
			double fRec367 = fTemp107;
			fRec365[0] = (fRec366[0] + fRec365[1]);
			fRec363[0] = fRec365[0];
			double fRec364 = fRec367;
			fRec362[0] = (fTemp106 + (fRec364 + fRec362[1]));
			fRec360[0] = fRec362[0];
			double fRec361 = (fRec364 + fTemp106);
			fRec359[0] = (fRec360[0] + fRec359[1]);
			fRec357[0] = fRec359[0];
			double fRec358 = fRec361;
			double fTemp108 = (fConst12 * fRec354[1]);
			fRec356[0] = ((fRec358 + fRec356[1]) - fTemp108);
			fRec354[0] = fRec356[0];
			double fRec355 = (fRec358 - fTemp108);
			double fTemp109 = (fConst18 * (0.0 - ((fConst20 * fRec372[1]) + (fConst19 * fRec369[1]))));
			double fTemp110 = (fConst13 * ((fConst2 * (0.0 - ((fConst15 * fRec378[1]) + (fConst14 * fRec375[1])))) + (fConst17 * ((((((0.0154051472 * fTemp23) + (0.0040186767000000003 * fTemp25)) + (0.026818020099999999 * fTemp22)) + (0.0015909226 * fTemp26)) + (0.0120248882 * fTemp27)) - ((((0.1102393195 * fTemp21) + (0.032100150000000001 * fTemp24)) + (0.047501493499999999 * fTemp28)) + (0.1213526826 * fTemp29))))));
			fRec380[0] = (fRec380[1] + fTemp110);
			fRec378[0] = fRec380[0];
			double fRec379 = fTemp110;
			fRec377[0] = (fRec378[0] + fRec377[1]);
			fRec375[0] = fRec377[0];
			double fRec376 = fRec379;
			fRec374[0] = (fTemp109 + (fRec376 + fRec374[1]));
			fRec372[0] = fRec374[0];
			double fRec373 = (fRec376 + fTemp109);
			fRec371[0] = (fRec372[0] + fRec371[1]);
			fRec369[0] = fRec371[0];
			double fRec370 = fRec373;
			double fTemp111 = (fConst21 * ((fConst2 * (0.0 - ((fConst23 * fRec387[1]) + (fConst22 * fRec384[1])))) + (fConst25 * ((((((0.042418395800000001 * fTemp34) + (0.014233097300000001 * fTemp35)) + (0.029136868 * fTemp36)) + (0.0163560596 * fTemp37)) + (0.15483944129999999 * fTemp38)) - ((0.036693249499999997 * fTemp32) + (0.048724794500000002 * fTemp33))))));
			fRec389[0] = (fRec389[1] + fTemp111);
			fRec387[0] = fRec389[0];
			double fRec388 = fTemp111;
			fRec386[0] = (fRec387[0] + fRec386[1]);
			fRec384[0] = fRec386[0];
			double fRec385 = fRec388;
			double fTemp112 = (fConst26 * fRec381[1]);
			fRec383[0] = ((fRec385 + fRec383[1]) - fTemp112);
			fRec381[0] = fRec383[0];
			double fRec382 = (fRec385 - fTemp112);
			double fTemp113 = (fConst30 * ((0.0 - (((0.091892606200000004 * fTemp47) + (0.024202001500000001 * fTemp49)) + (0.063052502799999993 * fTemp48))) - (fConst31 * fRec390[1])));
			fRec392[0] = (fRec392[1] + fTemp113);
			fRec390[0] = fRec392[0];
			double fRec391 = fTemp113;
			double fTemp114 = (fConst27 * (((((0.13290044710000001 * fTemp41) + (0.038372802400000003 * fTemp43)) + (0.027371650099999999 * fTemp45)) - ((0.051111494100000002 * fTemp44) + (0.051283751799999999 * fTemp42))) + (fConst2 * (0.0 - ((fConst29 * fRec396[1]) + (fConst28 * fRec393[1]))))));
			fRec398[0] = (fRec398[1] + fTemp114);
			fRec396[0] = fRec398[0];
			double fRec397 = fTemp114;
			fRec395[0] = (fRec396[0] + fRec395[1]);
			fRec393[0] = fRec395[0];
			double fRec394 = fRec397;
			fVec7[(IOTA & 1023)] = ((0.041900611499999997 * fTemp51) + (fRec355 + (fRec370 + (fRec382 + (fRec391 + fRec394)))));
			output7[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec7[((IOTA - iConst32) & 1023)])));
			double fTemp115 = (fConst9 * (0.0 - ((fConst11 * fRec405[1]) + (fConst10 * fRec402[1]))));
			double fTemp116 = (fConst1 * ((fConst2 * (0.0 - ((fConst4 * fRec411[1]) + (fConst3 * fRec408[1])))) + (fConst7 * ((((((0.0095194761999999999 * fTemp13) + (0.024925714500000001 * fTemp8)) + (0.0032990413000000001 * fTemp16)) + (0.0041310907999999999 * fTemp10)) + (0.16311394739999999 * fTemp17)) - ((((((0.037704834200000002 * fTemp11) + (0.026317866200000001 * fTemp12)) + (0.039159303399999998 * fTemp14)) + (0.0055726009000000003 * fTemp7)) + (0.013372330700000001 * fTemp9)) + (0.012305367500000001 * fTemp15))))));
			fRec413[0] = (fRec413[1] + fTemp116);
			fRec411[0] = fRec413[0];
			double fRec412 = fTemp116;
			fRec410[0] = (fRec411[0] + fRec410[1]);
			fRec408[0] = fRec410[0];
			double fRec409 = fRec412;
			fRec407[0] = (fTemp115 + (fRec409 + fRec407[1]));
			fRec405[0] = fRec407[0];
			double fRec406 = (fRec409 + fTemp115);
			fRec404[0] = (fRec405[0] + fRec404[1]);
			fRec402[0] = fRec404[0];
			double fRec403 = fRec406;
			double fTemp117 = (fConst12 * fRec399[1]);
			fRec401[0] = ((fRec403 + fRec401[1]) - fTemp117);
			fRec399[0] = fRec401[0];
			double fRec400 = (fRec403 - fTemp117);
			double fTemp118 = (fConst18 * (0.0 - ((fConst20 * fRec417[1]) + (fConst19 * fRec414[1]))));
			double fTemp119 = (fConst13 * ((fConst2 * (0.0 - ((fConst15 * fRec423[1]) + (fConst14 * fRec420[1])))) + (fConst17 * (((((((0.1253270376 * fTemp21) + (0.0271910494 * fTemp23)) + (0.016233035999999999 * fTemp25)) + (0.018931517599999999 * fTemp22)) + (0.0198023043 * fTemp26)) + (0.0064534922999999996 * fTemp28)) - (((0.025212416099999999 * fTemp24) + (0.0131429202 * fTemp27)) + (0.1204002841 * fTemp29))))));
			fRec425[0] = (fRec425[1] + fTemp119);
			fRec423[0] = fRec425[0];
			double fRec424 = fTemp119;
			fRec422[0] = (fRec423[0] + fRec422[1]);
			fRec420[0] = fRec422[0];
			double fRec421 = fRec424;
			fRec419[0] = (fTemp118 + (fRec421 + fRec419[1]));
			fRec417[0] = fRec419[0];
			double fRec418 = (fRec421 + fTemp118);
			fRec416[0] = (fRec417[0] + fRec416[1]);
			fRec414[0] = fRec416[0];
			double fRec415 = fRec418;
			double fTemp120 = (fConst21 * ((fConst2 * (0.0 - ((fConst23 * fRec432[1]) + (fConst22 * fRec429[1])))) + (fConst25 * ((((0.027751674300000001 * fTemp34) + (0.0428594791 * fTemp36)) + (0.031066263699999999 * fTemp38)) - ((((0.16669111519999999 * fTemp32) + (0.023699060599999999 * fTemp33)) + (0.0011684028999999999 * fTemp35)) + (0.0173965362 * fTemp37))))));
			fRec434[0] = (fRec434[1] + fTemp120);
			fRec432[0] = fRec434[0];
			double fRec433 = fTemp120;
			fRec431[0] = (fRec432[0] + fRec431[1]);
			fRec429[0] = fRec431[0];
			double fRec430 = fRec433;
			double fTemp121 = (fConst26 * fRec426[1]);
			fRec428[0] = ((fRec430 + fRec428[1]) - fTemp121);
			fRec426[0] = fRec428[0];
			double fRec427 = (fRec430 - fTemp121);
			double fTemp122 = (fConst30 * ((0.0 - (((0.066198228799999995 * fTemp47) + (0.016762492 * fTemp49)) + (0.099666691900000007 * fTemp48))) - (fConst31 * fRec435[1])));
			fRec437[0] = (fRec437[1] + fTemp122);
			fRec435[0] = fRec437[0];
			double fRec436 = fTemp122;
			double fTemp123 = (fConst27 * ((((((0.14050126869999999 * fTemp41) + (0.0138843228 * fTemp43)) + (0.0257576653 * fTemp45)) + (0.059271900299999999 * fTemp42)) - (0.054474888800000003 * fTemp44)) + (fConst2 * (0.0 - ((fConst29 * fRec441[1]) + (fConst28 * fRec438[1]))))));
			fRec443[0] = (fRec443[1] + fTemp123);
			fRec441[0] = fRec443[0];
			double fRec442 = fTemp123;
			fRec440[0] = (fRec441[0] + fRec440[1]);
			fRec438[0] = fRec440[0];
			double fRec439 = fRec442;
			fVec8[(IOTA & 1023)] = ((0.044961095299999997 * fTemp51) + (fRec400 + (fRec415 + (fRec427 + (fRec436 + fRec439)))));
			output8[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec8[((IOTA - iConst32) & 1023)])));
			double fTemp124 = (fConst9 * (0.0 - ((fConst11 * fRec450[1]) + (fConst10 * fRec447[1]))));
			double fTemp125 = (fConst1 * ((fConst2 * (0.0 - ((fConst4 * fRec456[1]) + (fConst3 * fRec453[1])))) + (fConst7 * ((((0.0086478396000000003 * fTemp13) + (0.024439496000000002 * fTemp8)) + (0.0056834342000000003 * fTemp16)) - ((((((((0.1235593654 * fTemp11) + (0.025805330899999999 * fTemp12)) + (0.0092833464999999993 * fTemp14)) + (0.0051374658000000002 * fTemp7)) + (0.0142529502 * fTemp9)) + (0.039440470599999999 * fTemp15)) + (0.0083323566000000002 * fTemp10)) + (0.1125171624 * fTemp17))))));
			fRec458[0] = (fRec458[1] + fTemp125);
			fRec456[0] = fRec458[0];
			double fRec457 = fTemp125;
			fRec455[0] = (fRec456[0] + fRec455[1]);
			fRec453[0] = fRec455[0];
			double fRec454 = fRec457;
			fRec452[0] = (fTemp124 + (fRec454 + fRec452[1]));
			fRec450[0] = fRec452[0];
			double fRec451 = (fRec454 + fTemp124);
			fRec449[0] = (fRec450[0] + fRec449[1]);
			fRec447[0] = fRec449[0];
			double fRec448 = fRec451;
			double fTemp126 = (fConst12 * fRec444[1]);
			fRec446[0] = ((fRec448 + fRec446[1]) - fTemp126);
			fRec444[0] = fRec446[0];
			double fRec445 = (fRec448 - fTemp126);
			double fTemp127 = (fConst18 * (0.0 - ((fConst20 * fRec462[1]) + (fConst19 * fRec459[1]))));
			double fTemp128 = (fConst13 * ((fConst2 * (0.0 - ((fConst15 * fRec468[1]) + (fConst14 * fRec465[1])))) + (fConst17 * ((((((((0.106455587 * fTemp21) + (0.022350073200000001 * fTemp23)) + (0.001528794 * fTemp25)) + (0.019288445500000001 * fTemp22)) + (0.024948327999999999 * fTemp26)) + (0.017738462 * fTemp28)) + (0.13676627999999999 * fTemp29)) - ((0.0113139253 * fTemp24) + (0.026265426599999999 * fTemp27))))));
			fRec470[0] = (fRec470[1] + fTemp128);
			fRec468[0] = fRec470[0];
			double fRec469 = fTemp128;
			fRec467[0] = (fRec468[0] + fRec467[1]);
			fRec465[0] = fRec467[0];
			double fRec466 = fRec469;
			fRec464[0] = (fTemp127 + (fRec466 + fRec464[1]));
			fRec462[0] = fRec464[0];
			double fRec463 = (fRec466 + fTemp127);
			fRec461[0] = (fRec462[0] + fRec461[1]);
			fRec459[0] = fRec461[0];
			double fRec460 = fRec463;
			double fTemp129 = (fConst21 * ((fConst2 * (0.0 - ((fConst23 * fRec477[1]) + (fConst22 * fRec474[1])))) + (fConst25 * (((0.0088467096000000005 * fTemp34) + (0.050191121999999998 * fTemp36)) - (((((0.080013013199999997 * fTemp32) + (0.015818632199999998 * fTemp33)) + (0.00079871089999999998 * fTemp35)) + (0.025494235399999999 * fTemp37)) + (0.14882285279999999 * fTemp38))))));
			fRec479[0] = (fRec479[1] + fTemp129);
			fRec477[0] = fRec479[0];
			double fRec478 = fTemp129;
			fRec476[0] = (fRec477[0] + fRec476[1]);
			fRec474[0] = fRec476[0];
			double fRec475 = fRec478;
			double fTemp130 = (fConst26 * fRec471[1]);
			fRec473[0] = ((fRec475 + fRec473[1]) - fTemp130);
			fRec471[0] = fRec473[0];
			double fRec472 = (fRec475 - fTemp130);
			double fTemp131 = (fConst30 * ((0.0 - (((0.0193611237 * fTemp47) + (0.016998759700000001 * fTemp49)) + (0.1175406724 * fTemp48))) - (fConst31 * fRec480[1])));
			fRec482[0] = (fRec482[1] + fTemp131);
			fRec480[0] = fRec482[0];
			double fRec481 = fTemp131;
			double fTemp132 = (fConst27 * ((((((0.0488413132 * fTemp41) + (0.0074527608000000004 * fTemp43)) + (0.0288162275 * fTemp45)) + (0.1438050173 * fTemp42)) - (0.054188403599999997 * fTemp44)) + (fConst2 * (0.0 - ((fConst29 * fRec486[1]) + (fConst28 * fRec483[1]))))));
			fRec488[0] = (fRec488[1] + fTemp132);
			fRec486[0] = fRec488[0];
			double fRec487 = fTemp132;
			fRec485[0] = (fRec486[0] + fRec485[1]);
			fRec483[0] = fRec485[0];
			double fRec484 = fRec487;
			fVec9[(IOTA & 1023)] = (fRec445 + ((0.044771906700000003 * fTemp51) + (fRec460 + (fRec472 + (fRec481 + fRec484)))));
			output9[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec9[((IOTA - iConst32) & 1023)])));
			double fTemp133 = (fConst9 * (0.0 - ((fConst11 * fRec495[1]) + (fConst10 * fRec492[1]))));
			double fTemp134 = (fConst1 * ((fConst2 * (0.0 - ((fConst4 * fRec501[1]) + (fConst3 * fRec498[1])))) + (fConst7 * (((((((0.1380115915 * fTemp11) + (0.029349379700000001 * fTemp12)) + (0.010951038499999999 * fTemp14)) + (0.0062265641999999996 * fTemp7)) + (0.0136355717 * fTemp8)) + (0.015698179 * fTemp16)) - (((((0.0104088142 * fTemp13) + (0.031960120199999997 * fTemp9)) + (0.020140290200000001 * fTemp15)) + (0.033034031300000002 * fTemp10)) + (0.075990342899999994 * fTemp17))))));
			fRec503[0] = (fRec503[1] + fTemp134);
			fRec501[0] = fRec503[0];
			double fRec502 = fTemp134;
			fRec500[0] = (fRec501[0] + fRec500[1]);
			fRec498[0] = fRec500[0];
			double fRec499 = fRec502;
			fRec497[0] = (fTemp133 + (fRec499 + fRec497[1]));
			fRec495[0] = fRec497[0];
			double fRec496 = (fRec499 + fTemp133);
			fRec494[0] = (fRec495[0] + fRec494[1]);
			fRec492[0] = fRec494[0];
			double fRec493 = fRec496;
			double fTemp135 = (fConst12 * fRec489[1]);
			fRec491[0] = ((fRec493 + fRec491[1]) - fTemp135);
			fRec489[0] = fRec491[0];
			double fRec490 = (fRec493 - fTemp135);
			double fTemp136 = (fConst18 * (0.0 - ((fConst20 * fRec507[1]) + (fConst19 * fRec504[1]))));
			double fTemp137 = (fConst13 * ((fConst2 * (0.0 - ((fConst15 * fRec513[1]) + (fConst14 * fRec510[1])))) + (fConst17 * ((((((0.0134999266 * fTemp24) + (0.026028021799999999 * fTemp22)) + (0.0037731395000000002 * fTemp26)) + (0.041505324599999997 * fTemp28)) + (0.106238349 * fTemp29)) - ((((0.1216394542 * fTemp21) + (0.0261021762 * fTemp23)) + (0.0017477087 * fTemp25)) + (0.0306278288 * fTemp27))))));
			fRec515[0] = (fRec515[1] + fTemp137);
			fRec513[0] = fRec515[0];
			double fRec514 = fTemp137;
			fRec512[0] = (fRec513[0] + fRec512[1]);
			fRec510[0] = fRec512[0];
			double fRec511 = fRec514;
			fRec509[0] = (fTemp136 + (fRec511 + fRec509[1]));
			fRec507[0] = fRec509[0];
			double fRec508 = (fRec511 + fTemp136);
			fRec506[0] = (fRec507[0] + fRec506[1]);
			fRec504[0] = fRec506[0];
			double fRec505 = fRec508;
			double fTemp138 = (fConst21 * ((fConst2 * (0.0 - ((fConst23 * fRec522[1]) + (fConst22 * fRec519[1])))) + (fConst25 * (((((0.092981085399999996 * fTemp32) + (0.018774072100000001 * fTemp33)) + (0.0139374384 * fTemp35)) + (0.049000392400000002 * fTemp36)) - (((0.0105425424 * fTemp34) + (0.046590572900000002 * fTemp37)) + (0.12512365070000001 * fTemp38))))));
			fRec524[0] = (fRec524[1] + fTemp138);
			fRec522[0] = fRec524[0];
			double fRec523 = fTemp138;
			fRec521[0] = (fRec522[0] + fRec521[1]);
			fRec519[0] = fRec521[0];
			double fRec520 = fRec523;
			double fTemp139 = (fConst26 * fRec516[1]);
			fRec518[0] = ((fRec520 + fRec518[1]) - fTemp139);
			fRec516[0] = fRec518[0];
			double fRec517 = (fRec520 - fTemp139);
			double fTemp140 = (fConst27 * ((((0.045066289900000001 * fTemp45) + (0.12661481799999999 * fTemp42)) - (((0.057421154799999999 * fTemp41) + (0.0089122188999999994 * fTemp43)) + (0.0497783854 * fTemp44))) + (fConst2 * (0.0 - ((fConst29 * fRec528[1]) + (fConst28 * fRec525[1]))))));
			fRec530[0] = (fRec530[1] + fTemp140);
			fRec528[0] = fRec530[0];
			double fRec529 = fTemp140;
			fRec527[0] = (fRec528[0] + fRec527[1]);
			fRec525[0] = fRec527[0];
			double fRec526 = fRec529;
			double fTemp141 = (fConst30 * (((0.022915958300000001 * fTemp47) - ((0.023541647299999999 * fTemp49) + (0.1060778049 * fTemp48))) - (fConst31 * fRec531[1])));
			fRec533[0] = (fRec533[1] + fTemp141);
			fRec531[0] = fRec533[0];
			double fRec532 = fTemp141;
			fVec10[(IOTA & 1023)] = (fRec490 + (fRec505 + (fRec517 + (fRec526 + (fRec532 + (0.040765473500000003 * fTemp51))))));
			output10[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec10[((IOTA - iConst32) & 1023)])));
			double fTemp142 = (fConst9 * (0.0 - ((fConst11 * fRec540[1]) + (fConst10 * fRec537[1]))));
			double fTemp143 = (fConst1 * ((fConst2 * (0.0 - ((fConst4 * fRec546[1]) + (fConst3 * fRec543[1])))) + (fConst7 * (((((((((0.016024746199999999 * fTemp11) + (0.0240272635 * fTemp12)) + (0.039858781699999998 * fTemp14)) + (0.0057636628000000004 * fTemp7)) + (0.024864640699999999 * fTemp8)) + (0.0022691474000000001 * fTemp16)) + (0.0070880403 * fTemp10)) + (0.16685412820000001 * fTemp17)) - (((0.0092487872000000006 * fTemp13) + (0.012587880900000001 * fTemp9)) + (0.0107150336 * fTemp15))))));
			fRec548[0] = (fRec548[1] + fTemp143);
			fRec546[0] = fRec548[0];
			double fRec547 = fTemp143;
			fRec545[0] = (fRec546[0] + fRec545[1]);
			fRec543[0] = fRec545[0];
			double fRec544 = fRec547;
			fRec542[0] = (fTemp142 + (fRec544 + fRec542[1]));
			fRec540[0] = fRec542[0];
			double fRec541 = (fRec544 + fTemp142);
			fRec539[0] = (fRec540[0] + fRec539[1]);
			fRec537[0] = fRec539[0];
			double fRec538 = fRec541;
			double fTemp144 = (fConst12 * fRec534[1]);
			fRec536[0] = ((fRec538 + fRec536[1]) - fTemp144);
			fRec534[0] = fRec536[0];
			double fRec535 = (fRec538 - fTemp144);
			double fTemp145 = (fConst18 * (0.0 - ((fConst20 * fRec552[1]) + (fConst19 * fRec549[1]))));
			double fTemp146 = (fConst13 * ((fConst2 * (0.0 - ((fConst15 * fRec558[1]) + (fConst14 * fRec555[1])))) + (fConst17 * (((((0.025627492700000001 * fTemp24) + (0.0187673205 * fTemp22)) + (0.019900212399999999 * fTemp26)) + (0.0035218543000000001 * fTemp28)) - (((((0.1121265108 * fTemp21) + (0.0264477672 * fTemp23)) + (0.016805886700000001 * fTemp25)) + (0.011563790799999999 * fTemp27)) + (0.13268593009999999 * fTemp29))))));
			fRec560[0] = (fRec560[1] + fTemp146);
			fRec558[0] = fRec560[0];
			double fRec559 = fTemp146;
			fRec557[0] = (fRec558[0] + fRec557[1]);
			fRec555[0] = fRec557[0];
			double fRec556 = fRec559;
			fRec554[0] = (fTemp145 + (fRec556 + fRec554[1]));
			fRec552[0] = fRec554[0];
			double fRec553 = (fRec556 + fTemp145);
			fRec551[0] = (fRec552[0] + fRec551[1]);
			fRec549[0] = fRec551[0];
			double fRec550 = fRec553;
			double fTemp147 = (fConst21 * ((fConst2 * (0.0 - ((fConst23 * fRec567[1]) + (fConst22 * fRec564[1])))) + (fConst25 * (((((0.1635297483 * fTemp32) + (0.023996505599999999 * fTemp33)) + (0.041897928299999998 * fTemp36)) + (0.043748289199999998 * fTemp38)) - (((0.028714473300000001 * fTemp34) + (0.0017052578 * fTemp35)) + (0.015264704800000001 * fTemp37))))));
			fRec569[0] = (fRec569[1] + fTemp147);
			fRec567[0] = fRec569[0];
			double fRec568 = fTemp147;
			fRec566[0] = (fRec567[0] + fRec566[1]);
			fRec564[0] = fRec566[0];
			double fRec565 = fRec568;
			double fTemp148 = (fConst26 * fRec561[1]);
			fRec563[0] = ((fRec565 + fRec563[1]) - fTemp148);
			fRec561[0] = fRec563[0];
			double fRec562 = (fRec565 - fTemp148);
			double fTemp149 = (fConst27 * ((((0.0246980875 * fTemp45) + (0.0518872893 * fTemp42)) - (((0.142982515 * fTemp41) + (0.014361445400000001 * fTemp43)) + (0.054215231900000001 * fTemp44))) + (fConst2 * (0.0 - ((fConst29 * fRec573[1]) + (fConst28 * fRec570[1]))))));
			fRec575[0] = (fRec575[1] + fTemp149);
			fRec573[0] = fRec575[0];
			double fRec574 = fTemp149;
			fRec572[0] = (fRec573[0] + fRec572[1]);
			fRec570[0] = fRec572[0];
			double fRec571 = fRec574;
			double fTemp150 = (fConst30 * (((0.068504168800000001 * fTemp47) - ((0.016504912 * fTemp49) + (0.097651557299999997 * fTemp48))) - (fConst31 * fRec576[1])));
			fRec578[0] = (fRec578[1] + fTemp150);
			fRec576[0] = fRec578[0];
			double fRec577 = fTemp150;
			fVec11[(IOTA & 1023)] = (fRec535 + (fRec550 + (fRec562 + (fRec571 + (fRec577 + (0.044828623999999997 * fTemp51))))));
			output11[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec11[((IOTA - iConst32) & 1023)])));
			double fTemp151 = (fConst9 * (0.0 - ((fConst11 * fRec585[1]) + (fConst10 * fRec582[1]))));
			double fTemp152 = (fConst1 * ((fConst2 * (0.0 - ((fConst4 * fRec591[1]) + (fConst3 * fRec588[1])))) + (fConst7 * ((((((0.019492432699999999 * fTemp14) + (0.025405116599999999 * fTemp7)) + (0.0129937573 * fTemp8)) + (0.0098512932999999994 * fTemp15)) + (0.034186733699999999 * fTemp10)) - ((((((0.1516889907 * fTemp11) + (0.026432532200000001 * fTemp12)) + (0.0044536393000000002 * fTemp13)) + (0.017768092400000001 * fTemp9)) + (0.0176367118 * fTemp16)) + (0.030951374899999998 * fTemp17))))));
			fRec593[0] = (fRec593[1] + fTemp152);
			fRec591[0] = fRec593[0];
			double fRec592 = fTemp152;
			fRec590[0] = (fRec591[0] + fRec590[1]);
			fRec588[0] = fRec590[0];
			double fRec589 = fRec592;
			fRec587[0] = (fTemp151 + (fRec589 + fRec587[1]));
			fRec585[0] = fRec587[0];
			double fRec586 = (fRec589 + fTemp151);
			fRec584[0] = (fRec585[0] + fRec584[1]);
			fRec582[0] = fRec584[0];
			double fRec583 = fRec586;
			double fTemp153 = (fConst12 * fRec579[1]);
			fRec581[0] = ((fRec583 + fRec581[1]) - fTemp153);
			fRec579[0] = fRec581[0];
			double fRec580 = (fRec583 - fTemp153);
			double fTemp154 = (fConst18 * (0.0 - ((fConst20 * fRec597[1]) + (fConst19 * fRec594[1]))));
			double fTemp155 = (fConst13 * ((fConst2 * (0.0 - ((fConst15 * fRec603[1]) + (fConst14 * fRec600[1])))) + (fConst17 * ((((((0.1111823817 * fTemp21) + (0.029696510400000001 * fTemp24)) + (0.024732994000000001 * fTemp22)) + (0.0013815380999999999 * fTemp26)) + (0.0119951395 * fTemp27)) - ((((0.0128718893 * fTemp23) + (0.0036757401999999999 * fTemp25)) + (0.045526531799999999 * fTemp28)) + (0.11050397219999999 * fTemp29))))));
			fRec605[0] = (fRec605[1] + fTemp155);
			fRec603[0] = fRec605[0];
			double fRec604 = fTemp155;
			fRec602[0] = (fRec603[0] + fRec602[1]);
			fRec600[0] = fRec602[0];
			double fRec601 = fRec604;
			fRec599[0] = (fTemp154 + (fRec601 + fRec599[1]));
			fRec597[0] = fRec599[0];
			double fRec598 = (fRec601 + fTemp154);
			fRec596[0] = (fRec597[0] + fRec596[1]);
			fRec594[0] = fRec596[0];
			double fRec595 = fRec598;
			double fTemp156 = (fConst21 * ((fConst2 * (0.0 - ((fConst23 * fRec612[1]) + (fConst22 * fRec609[1])))) + (fConst25 * (((((((0.028986762999999999 * fTemp32) + (0.045165012300000001 * fTemp33)) + (0.013282145 * fTemp35)) + (0.0265388415 * fTemp36)) + (0.0164186846 * fTemp37)) + (0.1471202429 * fTemp38)) - (0.039713684700000002 * fTemp34)))));
			fRec614[0] = (fRec614[1] + fTemp156);
			fRec612[0] = fRec614[0];
			double fRec613 = fTemp156;
			fRec611[0] = (fRec612[0] + fRec611[1]);
			fRec609[0] = fRec611[0];
			double fRec610 = fRec613;
			double fTemp157 = (fConst26 * fRec606[1]);
			fRec608[0] = ((fRec610 + fRec608[1]) - fTemp157);
			fRec606[0] = fRec608[0];
			double fRec607 = (fRec610 - fTemp157);
			double fTemp158 = (fConst27 * (((0.024961409899999999 * fTemp45) - ((((0.12273815540000001 * fTemp41) + (0.035919698299999997 * fTemp43)) + (0.047383676600000001 * fTemp44)) + (0.050976372499999999 * fTemp42))) + (fConst2 * (0.0 - ((fConst29 * fRec618[1]) + (fConst28 * fRec615[1]))))));
			fRec620[0] = (fRec620[1] + fTemp158);
			fRec618[0] = fRec620[0];
			double fRec619 = fTemp158;
			fRec617[0] = (fRec618[0] + fRec617[1]);
			fRec615[0] = fRec617[0];
			double fRec616 = fRec619;
			double fTemp159 = (fConst30 * (((0.085966535299999994 * fTemp47) - ((0.0223731351 * fTemp49) + (0.057398756600000003 * fTemp48))) - (fConst31 * fRec621[1])));
			fRec623[0] = (fRec623[1] + fTemp159);
			fRec621[0] = fRec623[0];
			double fRec622 = fTemp159;
			fVec12[(IOTA & 1023)] = (fRec580 + (fRec595 + (fRec607 + (fRec616 + (fRec622 + (0.038777960399999999 * fTemp51))))));
			output12[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec12[((IOTA - iConst32) & 1023)])));
			double fTemp160 = (fConst9 * (0.0 - ((fConst11 * fRec630[1]) + (fConst10 * fRec627[1]))));
			double fTemp161 = (fConst1 * ((fConst2 * (0.0 - ((fConst4 * fRec636[1]) + (fConst3 * fRec633[1])))) + (fConst7 * (((((((0.091710288500000001 * fTemp11) + (0.0033757784 * fTemp13)) + (0.0120085795 * fTemp14)) + (0.0114266344 * fTemp7)) + (0.025589218800000001 * fTemp8)) + (0.040515439100000002 * fTemp15)) - (((((0.026180570600000001 * fTemp12) + (0.0054222385999999996 * fTemp9)) + (0.0090239593999999999 * fTemp16)) + (0.0026271447999999999 * fTemp10)) + (0.1398122312 * fTemp17))))));
			fRec638[0] = (fRec638[1] + fTemp161);
			fRec636[0] = fRec638[0];
			double fRec637 = fTemp161;
			fRec635[0] = (fRec636[0] + fRec635[1]);
			fRec633[0] = fRec635[0];
			double fRec634 = fRec637;
			fRec632[0] = (fTemp160 + (fRec634 + fRec632[1]));
			fRec630[0] = fRec632[0];
			double fRec631 = (fRec634 + fTemp160);
			fRec629[0] = (fRec630[0] + fRec629[1]);
			fRec627[0] = fRec629[0];
			double fRec628 = fRec631;
			double fTemp162 = (fConst12 * fRec624[1]);
			fRec626[0] = ((fRec628 + fRec626[1]) - fTemp162);
			fRec624[0] = fRec626[0];
			double fRec625 = (fRec628 - fTemp162);
			double fTemp163 = (fConst18 * (0.0 - ((fConst20 * fRec642[1]) + (fConst19 * fRec639[1]))));
			double fTemp164 = (fConst13 * ((fConst2 * (0.0 - ((fConst15 * fRec648[1]) + (fConst14 * fRec645[1])))) + (fConst17 * ((((((((0.1229346109 * fTemp21) + (0.012705102899999999 * fTemp23)) + (0.012902431799999999 * fTemp24)) + (0.018017575899999999 * fTemp22)) + (0.0024736557000000002 * fTemp26)) + (0.024453051900000002 * fTemp27)) + (0.1226247415 * fTemp29)) - ((0.027311858200000001 * fTemp25) + (0.023410352299999999 * fTemp28))))));
			fRec650[0] = (fRec650[1] + fTemp164);
			fRec648[0] = fRec650[0];
			double fRec649 = fTemp164;
			fRec647[0] = (fRec648[0] + fRec647[1]);
			fRec645[0] = fRec647[0];
			double fRec646 = fRec649;
			fRec644[0] = (fTemp163 + (fRec646 + fRec644[1]));
			fRec642[0] = fRec644[0];
			double fRec643 = (fRec646 + fTemp163);
			fRec641[0] = (fRec642[0] + fRec641[1]);
			fRec639[0] = fRec641[0];
			double fRec640 = fRec643;
			double fTemp165 = (fConst21 * ((fConst2 * (0.0 - ((fConst23 * fRec657[1]) + (fConst22 * fRec654[1])))) + (fConst25 * (((((0.017015386899999999 * fTemp33) + (0.010437583800000001 * fTemp36)) + (0.0215876807 * fTemp37)) + (0.093814130999999995 * fTemp38)) - (((0.14120646880000001 * fTemp32) + (0.049510825799999998 * fTemp34)) + (0.0026763783999999998 * fTemp35))))));
			fRec659[0] = (fRec659[1] + fTemp165);
			fRec657[0] = fRec659[0];
			double fRec658 = fTemp165;
			fRec656[0] = (fRec657[0] + fRec656[1]);
			fRec654[0] = fRec656[0];
			double fRec655 = fRec658;
			double fTemp166 = (fConst26 * fRec651[1]);
			fRec653[0] = ((fRec655 + fRec653[1]) - fTemp166);
			fRec651[0] = fRec653[0];
			double fRec652 = (fRec655 - fTemp166);
			double fTemp167 = (fConst27 * (((0.0081904114999999996 * fTemp45) - ((((0.0578733237 * fTemp41) + (0.026190610400000001 * fTemp43)) + (0.054415445600000001 * fTemp44)) + (0.141181589 * fTemp42))) + (fConst2 * (0.0 - ((fConst29 * fRec663[1]) + (fConst28 * fRec660[1]))))));
			fRec665[0] = (fRec665[1] + fTemp167);
			fRec663[0] = fRec665[0];
			double fRec664 = fTemp167;
			fRec662[0] = (fRec663[0] + fRec662[1]);
			fRec660[0] = fRec662[0];
			double fRec661 = fRec664;
			double fTemp168 = (fConst30 * (((0.1175510806 * fTemp47) - ((0.015968805499999999 * fTemp49) + (0.023082134000000001 * fTemp48))) - (fConst31 * fRec666[1])));
			fRec668[0] = (fRec668[1] + fTemp168);
			fRec666[0] = fRec668[0];
			double fRec667 = fTemp168;
			fVec13[(IOTA & 1023)] = (fRec625 + (fRec640 + (fRec652 + (fRec661 + (fRec667 + (0.045030867000000002 * fTemp51))))));
			output13[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec13[((IOTA - iConst32) & 1023)])));
			double fTemp169 = (fConst9 * (0.0 - ((fConst11 * fRec675[1]) + (fConst10 * fRec672[1]))));
			double fTemp170 = (fConst1 * ((fConst2 * (0.0 - ((fConst4 * fRec681[1]) + (fConst3 * fRec678[1])))) + (fConst7 * ((((((((((0.097955973500000001 * fTemp11) + (0.023211334899999998 * fTemp12)) + (0.016753846900000001 * fTemp13)) + (0.031838053300000002 * fTemp7)) + (0.013456146699999999 * fTemp8)) + (0.0048809172999999999 * fTemp9)) + (0.020524561100000002 * fTemp15)) + (0.0084868875 * fTemp16)) + (0.1223788671 * fTemp17)) - ((0.0099629509999999994 * fTemp14) + (0.0378000317 * fTemp10))))));
			fRec683[0] = (fRec683[1] + fTemp170);
			fRec681[0] = fRec683[0];
			double fRec682 = fTemp170;
			fRec680[0] = (fRec681[0] + fRec680[1]);
			fRec678[0] = fRec680[0];
			double fRec679 = fRec682;
			fRec677[0] = (fTemp169 + (fRec679 + fRec677[1]));
			fRec675[0] = fRec677[0];
			double fRec676 = (fRec679 + fTemp169);
			fRec674[0] = (fRec675[0] + fRec674[1]);
			fRec672[0] = fRec674[0];
			double fRec673 = fRec676;
			double fTemp171 = (fConst12 * fRec669[1]);
			fRec671[0] = ((fRec673 + fRec671[1]) - fTemp171);
			fRec669[0] = fRec671[0];
			double fRec670 = (fRec673 - fTemp171);
			double fTemp172 = (fConst18 * (0.0 - ((fConst20 * fRec687[1]) + (fConst19 * fRec684[1]))));
			double fTemp173 = (fConst13 * ((fConst2 * (0.0 - ((fConst15 * fRec693[1]) + (fConst14 * fRec690[1])))) + (fConst17 * ((((((0.044251945399999999 * fTemp23) + (0.0258711976 * fTemp22)) + (0.0312757325 * fTemp27)) + (0.020488006199999999 * fTemp28)) + (0.1210844511 * fTemp29)) - ((((0.10522688669999999 * fTemp21) + (0.011205200800000001 * fTemp24)) + (0.0038650865 * fTemp25)) + (0.0019130048999999999 * fTemp26))))));
			fRec695[0] = (fRec695[1] + fTemp173);
			fRec693[0] = fRec695[0];
			double fRec694 = fTemp173;
			fRec692[0] = (fRec693[0] + fRec692[1]);
			fRec690[0] = fRec692[0];
			double fRec691 = fRec694;
			fRec689[0] = (fTemp172 + (fRec691 + fRec689[1]));
			fRec687[0] = fRec689[0];
			double fRec688 = (fRec691 + fTemp172);
			fRec686[0] = (fRec687[0] + fRec686[1]);
			fRec684[0] = fRec686[0];
			double fRec685 = fRec688;
			double fTemp174 = (fConst21 * ((fConst2 * (0.0 - ((fConst23 * fRec702[1]) + (fConst22 * fRec699[1])))) + (fConst25 * (((0.0136266857 * fTemp35) + (0.047498834599999998 * fTemp37)) - (((((0.13297087029999999 * fTemp32) + (0.0147101833 * fTemp33)) + (0.048908940900000003 * fTemp34)) + (0.0087713231000000006 * fTemp36)) + (0.078976453500000002 * fTemp38))))));
			fRec704[0] = (fRec704[1] + fTemp174);
			fRec702[0] = fRec704[0];
			double fRec703 = fTemp174;
			fRec701[0] = (fRec702[0] + fRec701[1]);
			fRec699[0] = fRec701[0];
			double fRec700 = fRec703;
			double fTemp175 = (fConst26 * fRec696[1]);
			fRec698[0] = ((fRec700 + fRec698[1]) - fTemp175);
			fRec696[0] = fRec698[0];
			double fRec697 = (fRec700 - fTemp175);
			double fTemp176 = (fConst27 * (((0.048157827299999997 * fTemp41) - ((((0.044849789799999998 * fTemp43) + (0.049278436699999997 * fTemp44)) + (0.0070098920000000002 * fTemp45)) + (0.12912435620000001 * fTemp42))) + (fConst2 * (0.0 - ((fConst29 * fRec708[1]) + (fConst28 * fRec705[1]))))));
			fRec710[0] = (fRec710[1] + fTemp176);
			fRec708[0] = fRec710[0];
			double fRec709 = fTemp176;
			fRec707[0] = (fRec708[0] + fRec707[1]);
			fRec705[0] = fRec707[0];
			double fRec706 = fRec709;
			double fTemp177 = (fConst30 * ((((0.10581820679999999 * fTemp47) + (0.019073984299999999 * fTemp48)) - (0.023290355200000001 * fTemp49)) - (fConst31 * fRec711[1])));
			fRec713[0] = (fRec713[1] + fTemp177);
			fRec711[0] = fRec713[0];
			double fRec712 = fTemp177;
			fVec14[(IOTA & 1023)] = (fRec670 + (fRec685 + (fRec697 + (fRec706 + (fRec712 + (0.040390916899999997 * fTemp51))))));
			output14[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec14[((IOTA - iConst32) & 1023)])));
			double fTemp178 = (fConst9 * (0.0 - ((fConst11 * fRec720[1]) + (fConst10 * fRec717[1]))));
			double fTemp179 = (fConst1 * ((fConst2 * (0.0 - ((fConst4 * fRec726[1]) + (fConst3 * fRec723[1])))) + (fConst7 * (((((((((0.030107716900000001 * fTemp12) + (0.026979463299999999 * fTemp7)) + (0.0137199161 * fTemp8)) + (0.017925994000000001 * fTemp9)) + (0.011701367400000001 * fTemp15)) + (0.0185169328 * fTemp16)) + (0.032515872000000001 * fTemp10)) + (0.052300087000000002 * fTemp17)) - (((0.14849722000000001 * fTemp11) + (0.0033189997999999998 * fTemp13)) + (0.019816449399999998 * fTemp14))))));
			fRec728[0] = (fRec728[1] + fTemp179);
			fRec726[0] = fRec728[0];
			double fRec727 = fTemp179;
			fRec725[0] = (fRec726[0] + fRec725[1]);
			fRec723[0] = fRec725[0];
			double fRec724 = fRec727;
			fRec722[0] = (fTemp178 + (fRec724 + fRec722[1]));
			fRec720[0] = fRec722[0];
			double fRec721 = (fRec724 + fTemp178);
			fRec719[0] = (fRec720[0] + fRec719[1]);
			fRec717[0] = fRec719[0];
			double fRec718 = fRec721;
			double fTemp180 = (fConst12 * fRec714[1]);
			fRec716[0] = ((fRec718 + fRec716[1]) - fTemp180);
			fRec714[0] = fRec716[0];
			double fRec715 = (fRec718 - fTemp180);
			double fTemp181 = (fConst18 * (0.0 - ((fConst20 * fRec732[1]) + (fConst19 * fRec729[1]))));
			double fTemp182 = (fConst13 * ((fConst2 * (0.0 - ((fConst15 * fRec738[1]) + (fConst14 * fRec735[1])))) + (fConst17 * ((((0.025972437000000001 * fTemp22) + (0.0141148456 * fTemp27)) + (0.0479619212 * fTemp28)) - ((((((0.1262795159 * fTemp21) + (0.0100311933 * fTemp23)) + (0.030344899200000001 * fTemp24)) + (0.0040875002000000001 * fTemp25)) + (0.0012885500000000001 * fTemp26)) + (0.10066921500000001 * fTemp29))))));
			fRec740[0] = (fRec740[1] + fTemp182);
			fRec738[0] = fRec740[0];
			double fRec739 = fTemp182;
			fRec737[0] = (fRec738[0] + fRec737[1]);
			fRec735[0] = fRec737[0];
			double fRec736 = fRec739;
			fRec734[0] = (fTemp181 + (fRec736 + fRec734[1]));
			fRec732[0] = fRec734[0];
			double fRec733 = (fRec736 + fTemp181);
			fRec731[0] = (fRec732[0] + fRec731[1]);
			fRec729[0] = fRec731[0];
			double fRec730 = fRec733;
			double fTemp183 = (fConst21 * ((fConst2 * (0.0 - ((fConst23 * fRec747[1]) + (fConst22 * fRec744[1])))) + (fConst25 * ((((0.017561055400000001 * fTemp32) + (0.013858587299999999 * fTemp35)) + (0.019353002599999999 * fTemp37)) - ((((0.046238244300000002 * fTemp33) + (0.042447635599999999 * fTemp34)) + (0.026758762299999999 * fTemp36)) + (0.15497015110000001 * fTemp38))))));
			fRec749[0] = (fRec749[1] + fTemp183);
			fRec747[0] = fRec749[0];
			double fRec748 = fTemp183;
			fRec746[0] = (fRec747[0] + fRec746[1]);
			fRec744[0] = fRec746[0];
			double fRec745 = fRec748;
			double fTemp184 = (fConst26 * fRec741[1]);
			fRec743[0] = ((fRec745 + fRec743[1]) - fTemp184);
			fRec741[0] = fRec743[0];
			double fRec742 = (fRec745 - fTemp184);
			double fTemp185 = (fConst27 * (((0.12540924919999999 * fTemp41) - ((((0.038257431699999997 * fTemp43) + (0.0498504408 * fTemp44)) + (0.025219579499999999 * fTemp45)) + (0.0602701717 * fTemp42))) + (fConst2 * (0.0 - ((fConst29 * fRec753[1]) + (fConst28 * fRec750[1]))))));
			fRec755[0] = (fRec755[1] + fTemp185);
			fRec753[0] = fRec755[0];
			double fRec754 = fTemp185;
			fRec752[0] = (fRec753[0] + fRec752[1]);
			fRec750[0] = fRec752[0];
			double fRec751 = fRec754;
			double fTemp186 = (fConst30 * ((((0.091948842000000003 * fTemp47) + (0.057847784999999999 * fTemp48)) - (0.023486025899999999 * fTemp49)) - (fConst31 * fRec756[1])));
			fRec758[0] = (fRec758[1] + fTemp186);
			fRec756[0] = fRec758[0];
			double fRec757 = fTemp186;
			fVec15[(IOTA & 1023)] = (fRec715 + (fRec730 + (fRec742 + (fRec751 + (fRec757 + (0.040805683199999998 * fTemp51))))));
			output15[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec15[((IOTA - iConst32) & 1023)])));
			double fTemp187 = (fConst34 * (0.0 - ((fConst36 * fRec765[1]) + (fConst35 * fRec762[1]))));
			double fTemp188 = (fConst37 * ((fConst2 * (0.0 - ((fConst39 * fRec771[1]) + (fConst38 * fRec768[1])))) + (fConst41 * (((((((((0.026665955700000001 * fTemp11) + (0.078122615300000003 * fTemp12)) + (0.095884877199999996 * fTemp13)) + (0.0226578448 * fTemp14)) + (0.041414022600000003 * fTemp15)) + (0.064542356699999998 * fTemp16)) + (0.023019951 * fTemp10)) + (0.0011971447000000001 * fTemp17)) - (((0.033528091400000001 * fTemp7) + (0.048555427700000001 * fTemp8)) + (0.072624234900000001 * fTemp9))))));
			fRec773[0] = (fRec773[1] + fTemp188);
			fRec771[0] = fRec773[0];
			double fRec772 = fTemp188;
			fRec770[0] = (fRec771[0] + fRec770[1]);
			fRec768[0] = fRec770[0];
			double fRec769 = fRec772;
			fRec767[0] = (fTemp187 + (fRec769 + fRec767[1]));
			fRec765[0] = fRec767[0];
			double fRec766 = (fRec769 + fTemp187);
			fRec764[0] = (fRec765[0] + fRec764[1]);
			fRec762[0] = fRec764[0];
			double fRec763 = fRec766;
			double fTemp189 = (fConst42 * fRec759[1]);
			fRec761[0] = ((fRec763 + fRec761[1]) - fTemp189);
			fRec759[0] = fRec761[0];
			double fRec760 = (fRec763 - fTemp189);
			double fTemp190 = (fConst44 * (0.0 - ((fConst46 * fRec777[1]) + (fConst45 * fRec774[1]))));
			double fTemp191 = (fConst47 * ((fConst2 * (0.0 - ((fConst49 * fRec783[1]) + (fConst48 * fRec780[1])))) + (fConst50 * ((((((((0.042564237999999997 * fTemp21) + (0.0960019872 * fTemp23)) + (0.075839598100000002 * fTemp24)) + (0.00056197340000000004 * fTemp26)) + (0.1038907615 * fTemp27)) + (0.065973801600000007 * fTemp28)) + (0.0138388486 * fTemp29)) - ((0.0059110682999999999 * fTemp25) + (0.087146714299999997 * fTemp22))))));
			fRec785[0] = (fRec785[1] + fTemp191);
			fRec783[0] = fRec785[0];
			double fRec784 = fTemp191;
			fRec782[0] = (fRec783[0] + fRec782[1]);
			fRec780[0] = fRec782[0];
			double fRec781 = fRec784;
			fRec779[0] = (fTemp190 + (fRec781 + fRec779[1]));
			fRec777[0] = fRec779[0];
			double fRec778 = (fRec781 + fTemp190);
			fRec776[0] = (fRec777[0] + fRec776[1]);
			fRec774[0] = fRec776[0];
			double fRec775 = fRec778;
			double fTemp192 = (fConst51 * ((fConst2 * (0.0 - ((fConst53 * fRec792[1]) + (fConst52 * fRec789[1])))) + (fConst55 * (((((((0.052728591999999998 * fTemp32) + (0.084716863700000006 * fTemp33)) + (0.030580698699999999 * fTemp34)) + (0.1007985804 * fTemp36)) + (0.1137285452 * fTemp37)) + (0.037237809500000003 * fTemp38)) - (0.0553800916 * fTemp35)))));
			fRec794[0] = (fRec794[1] + fTemp192);
			fRec792[0] = fRec794[0];
			double fRec793 = fTemp192;
			fRec791[0] = (fRec792[0] + fRec791[1]);
			fRec789[0] = fRec791[0];
			double fRec790 = fRec793;
			double fTemp193 = (fConst56 * fRec786[1]);
			fRec788[0] = ((fRec790 + fRec788[1]) - fTemp193);
			fRec786[0] = fRec788[0];
			double fRec787 = (fRec790 - fTemp193);
			double fTemp194 = (fConst57 * ((((((0.048024604899999997 * fTemp41) + (0.043858782300000003 * fTemp43)) + (0.024724205799999999 * fTemp44)) + (0.13566151609999999 * fTemp45)) + (0.06470592 * fTemp42)) + (fConst2 * (0.0 - ((fConst59 * fRec798[1]) + (fConst58 * fRec795[1]))))));
			fRec800[0] = (fRec800[1] + fTemp194);
			fRec798[0] = fRec800[0];
			double fRec799 = fTemp194;
			fRec797[0] = (fRec798[0] + fRec797[1]);
			fRec795[0] = fRec797[0];
			double fRec796 = fRec799;
			double fTemp195 = (fConst60 * ((((0.025836954200000001 * fTemp47) + (0.073090759300000002 * fTemp49)) + (0.079096781300000002 * fTemp48)) - (fConst61 * fRec801[1])));
			fRec803[0] = (fRec803[1] + fTemp195);
			fRec801[0] = fRec803[0];
			double fRec802 = fTemp195;
			fVec16[(IOTA & 511)] = (fRec760 + (fRec775 + (fRec787 + (fRec796 + (fRec802 + (0.038935900400000001 * fTemp51))))));
			output16[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec16[((IOTA - iConst62) & 511)])));
			double fTemp196 = (fConst34 * (0.0 - ((fConst36 * fRec810[1]) + (fConst35 * fRec807[1]))));
			double fTemp197 = (fConst37 * ((fConst2 * (0.0 - ((fConst39 * fRec816[1]) + (fConst38 * fRec813[1])))) + (fConst41 * ((((0.042812562899999997 * fTemp7) + (0.012751115800000001 * fTemp15)) + (0.024489988800000001 * fTemp16)) - ((((((((0.0185183781 * fTemp11) + (0.079192042300000001 * fTemp12)) + (0.1032633504 * fTemp13)) + (0.011432948599999999 * fTemp14)) + (0.030345832199999999 * fTemp8)) + (0.091689767800000002 * fTemp9)) + (0.0235490306 * fTemp10)) + (0.020789076900000002 * fTemp17))))));
			fRec818[0] = (fRec818[1] + fTemp197);
			fRec816[0] = fRec818[0];
			double fRec817 = fTemp197;
			fRec815[0] = (fRec816[0] + fRec815[1]);
			fRec813[0] = fRec815[0];
			double fRec814 = fRec817;
			fRec812[0] = (fTemp196 + (fRec814 + fRec812[1]));
			fRec810[0] = fRec812[0];
			double fRec811 = (fRec814 + fTemp196);
			fRec809[0] = (fRec810[0] + fRec809[1]);
			fRec807[0] = fRec809[0];
			double fRec808 = fRec811;
			double fTemp198 = (fConst42 * fRec804[1]);
			fRec806[0] = ((fRec808 + fRec806[1]) - fTemp198);
			fRec804[0] = fRec806[0];
			double fRec805 = (fRec808 - fTemp198);
			double fTemp199 = (fConst44 * (0.0 - ((fConst46 * fRec822[1]) + (fConst45 * fRec819[1]))));
			double fTemp200 = (fConst47 * ((fConst2 * (0.0 - ((fConst49 * fRec828[1]) + (fConst48 * fRec825[1])))) + (fConst50 * ((((0.015789418 * fTemp25) + (0.066025565499999994 * fTemp27)) + (0.021242065899999999 * fTemp28)) - ((((((0.042846748099999998 * fTemp21) + (0.109361915 * fTemp23)) + (0.081007449400000001 * fTemp24)) + (0.081995681700000003 * fTemp22)) + (0.030705756300000001 * fTemp26)) + (0.0144473742 * fTemp29))))));
			fRec830[0] = (fRec830[1] + fTemp200);
			fRec828[0] = fRec830[0];
			double fRec829 = fTemp200;
			fRec827[0] = (fRec828[0] + fRec827[1]);
			fRec825[0] = fRec827[0];
			double fRec826 = fRec829;
			fRec824[0] = (fTemp199 + (fRec826 + fRec824[1]));
			fRec822[0] = fRec824[0];
			double fRec823 = (fRec826 + fTemp199);
			fRec821[0] = (fRec822[0] + fRec821[1]);
			fRec819[0] = fRec821[0];
			double fRec820 = fRec823;
			double fTemp201 = (fConst51 * ((fConst2 * (0.0 - ((fConst53 * fRec837[1]) + (fConst52 * fRec834[1])))) + (fConst55 * ((((0.064936305 * fTemp36) + (0.077726390199999995 * fTemp37)) + (0.0104764496 * fTemp38)) - ((((0.0618418835 * fTemp32) + (0.10055832200000001 * fTemp33)) + (0.030644154900000001 * fTemp34)) + (0.064544753600000004 * fTemp35))))));
			fRec839[0] = (fRec839[1] + fTemp201);
			fRec837[0] = fRec839[0];
			double fRec838 = fTemp201;
			fRec836[0] = (fRec837[0] + fRec836[1]);
			fRec834[0] = fRec836[0];
			double fRec835 = fRec838;
			double fTemp202 = (fConst56 * fRec831[1]);
			fRec833[0] = ((fRec835 + fRec833[1]) - fTemp202);
			fRec831[0] = fRec833[0];
			double fRec832 = (fRec835 - fTemp202);
			double fTemp203 = (fConst57 * (((((0.0068646756 * fTemp44) + (0.106752281 * fTemp45)) + (0.044906605400000001 * fTemp42)) - ((0.059746908199999997 * fTemp41) + (0.052208464599999997 * fTemp43))) + (fConst2 * (0.0 - ((fConst59 * fRec843[1]) + (fConst58 * fRec840[1]))))));
			fRec845[0] = (fRec845[1] + fTemp203);
			fRec843[0] = fRec845[0];
			double fRec844 = fTemp203;
			fRec842[0] = (fRec843[0] + fRec842[1]);
			fRec840[0] = fRec842[0];
			double fRec841 = fRec844;
			double fTemp204 = (fConst60 * ((((0.05629634 * fTemp49) + (0.065478709499999996 * fTemp48)) - (0.0324570478 * fTemp47)) - (fConst61 * fRec846[1])));
			fRec848[0] = (fRec848[1] + fTemp204);
			fRec846[0] = fRec848[0];
			double fRec847 = fTemp204;
			fVec17[(IOTA & 511)] = (fRec805 + (fRec820 + (fRec832 + (fRec841 + (fRec847 + (0.032144031000000003 * fTemp51))))));
			output17[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec17[((IOTA - iConst62) & 511)])));
			double fTemp205 = (fConst34 * (0.0 - ((fConst36 * fRec855[1]) + (fConst35 * fRec852[1]))));
			double fTemp206 = (fConst37 * ((fConst2 * (0.0 - ((fConst39 * fRec861[1]) + (fConst38 * fRec858[1])))) + (fConst41 * ((((((0.074672500599999997 * fTemp12) + (0.071370817500000003 * fTemp13)) + (0.075107450100000001 * fTemp7)) + (0.029728628900000002 * fTemp10)) + (0.025541375799999998 * fTemp17)) - ((((((0.0038786782000000001 * fTemp11) + (0.020887213500000001 * fTemp14)) + (0.0493060866 * fTemp8)) + (0.031736644799999998 * fTemp9)) + (0.042527390499999998 * fTemp15)) + (0.090838211000000002 * fTemp16))))));
			fRec863[0] = (fRec863[1] + fTemp206);
			fRec861[0] = fRec863[0];
			double fRec862 = fTemp206;
			fRec860[0] = (fRec861[0] + fRec860[1]);
			fRec858[0] = fRec860[0];
			double fRec859 = fRec862;
			fRec857[0] = (fTemp205 + (fRec859 + fRec857[1]));
			fRec855[0] = fRec857[0];
			double fRec856 = (fRec859 + fTemp205);
			fRec854[0] = (fRec855[0] + fRec854[1]);
			fRec852[0] = fRec854[0];
			double fRec853 = fRec856;
			double fTemp207 = (fConst42 * fRec849[1]);
			fRec851[0] = ((fRec853 + fRec851[1]) - fTemp207);
			fRec849[0] = fRec851[0];
			double fRec850 = (fRec853 - fTemp207);
			double fTemp208 = (fConst44 * (0.0 - ((fConst46 * fRec867[1]) + (fConst45 * fRec864[1]))));
			double fTemp209 = (fConst47 * ((fConst2 * (0.0 - ((fConst49 * fRec873[1]) + (fConst48 * fRec870[1])))) + (fConst50 * (((((0.040728214200000001 * fTemp21) + (0.072722887799999997 * fTemp23)) + (5.4000599999999999e-05 * fTemp25)) + (0.0173942952 * fTemp29)) - (((((0.071375065200000004 * fTemp24) + (0.088717705600000002 * fTemp22)) + (0.0058092884999999999 * fTemp26)) + (0.1083702305 * fTemp27)) + (0.091201045499999994 * fTemp28))))));
			fRec875[0] = (fRec875[1] + fTemp209);
			fRec873[0] = fRec875[0];
			double fRec874 = fTemp209;
			fRec872[0] = (fRec873[0] + fRec872[1]);
			fRec870[0] = fRec872[0];
			double fRec871 = fRec874;
			fRec869[0] = (fTemp208 + (fRec871 + fRec869[1]));
			fRec867[0] = fRec869[0];
			double fRec868 = (fRec871 + fTemp208);
			fRec866[0] = (fRec867[0] + fRec866[1]);
			fRec864[0] = fRec866[0];
			double fRec865 = fRec868;
			double fTemp210 = (fConst51 * ((fConst2 * (0.0 - ((fConst53 * fRec882[1]) + (fConst52 * fRec879[1])))) + (fConst55 * (((0.040892376500000001 * fTemp32) + (0.028616354 * fTemp36)) - (((((0.079987332699999997 * fTemp33) + (0.10271072790000001 * fTemp34)) + (0.056507688200000003 * fTemp35)) + (0.1187872858 * fTemp37)) + (0.050146726699999998 * fTemp38))))));
			fRec884[0] = (fRec884[1] + fTemp210);
			fRec882[0] = fRec884[0];
			double fRec883 = fTemp210;
			fRec881[0] = (fRec882[0] + fRec881[1]);
			fRec879[0] = fRec881[0];
			double fRec880 = fRec883;
			double fTemp211 = (fConst56 * fRec876[1]);
			fRec878[0] = ((fRec880 + fRec878[1]) - fTemp211);
			fRec876[0] = fRec878[0];
			double fRec877 = (fRec880 - fTemp211);
			double fTemp212 = (fConst57 * ((((0.024915884999999999 * fTemp44) + (0.0412290404 * fTemp45)) - (((0.045399850700000001 * fTemp41) + (0.13854293819999999 * fTemp43)) + (0.067569511299999996 * fTemp42))) + (fConst2 * (0.0 - ((fConst59 * fRec888[1]) + (fConst58 * fRec885[1]))))));
			fRec890[0] = (fRec890[1] + fTemp212);
			fRec888[0] = fRec890[0];
			double fRec889 = fTemp212;
			fRec887[0] = (fRec888[0] + fRec887[1]);
			fRec885[0] = fRec887[0];
			double fRec886 = fRec889;
			double fTemp213 = (fConst60 * ((((0.074133703999999995 * fTemp49) + (0.024320272399999999 * fTemp48)) - (0.080813680799999996 * fTemp47)) - (fConst61 * fRec891[1])));
			fRec893[0] = (fRec893[1] + fTemp213);
			fRec891[0] = fRec893[0];
			double fRec892 = fTemp213;
			fVec18[(IOTA & 511)] = (fRec850 + (fRec865 + (fRec877 + (fRec886 + (fRec892 + (0.0395166583 * fTemp51))))));
			output18[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec18[((IOTA - iConst62) & 511)])));
			double fTemp214 = (fConst34 * (0.0 - ((fConst36 * fRec900[1]) + (fConst35 * fRec897[1]))));
			double fTemp215 = (fConst37 * ((fConst2 * (0.0 - ((fConst39 * fRec906[1]) + (fConst38 * fRec903[1])))) + (fConst41 * (((((((0.0236313098 * fTemp11) + (0.017543044000000001 * fTemp13)) + (0.0103375189 * fTemp14)) + (0.090016403199999998 * fTemp7)) + (0.044779442099999997 * fTemp9)) + (0.10436145030000001 * fTemp16)) - (((((0.076963397200000006 * fTemp12) + (0.028910017100000001 * fTemp8)) + (0.0123781624 * fTemp15)) + (0.031948715400000001 * fTemp10)) + (0.015573327499999999 * fTemp17))))));
			fRec908[0] = (fRec908[1] + fTemp215);
			fRec906[0] = fRec908[0];
			double fRec907 = fTemp215;
			fRec905[0] = (fRec906[0] + fRec905[1]);
			fRec903[0] = fRec905[0];
			double fRec904 = fRec907;
			fRec902[0] = (fTemp214 + (fRec904 + fRec902[1]));
			fRec900[0] = fRec902[0];
			double fRec901 = (fRec904 + fTemp214);
			fRec899[0] = (fRec900[0] + fRec899[1]);
			fRec897[0] = fRec899[0];
			double fRec898 = fRec901;
			double fTemp216 = (fConst42 * fRec894[1]);
			fRec896[0] = ((fRec898 + fRec896[1]) - fTemp216);
			fRec894[0] = fRec896[0];
			double fRec895 = (fRec898 - fTemp216);
			double fTemp217 = (fConst44 * (0.0 - ((fConst46 * fRec912[1]) + (fConst45 * fRec909[1]))));
			double fTemp218 = (fConst47 * ((fConst2 * (0.0 - ((fConst49 * fRec918[1]) + (fConst48 * fRec915[1])))) + (fConst50 * ((((((0.013146886999999999 * fTemp23) + (0.082527814300000002 * fTemp24)) + (0.0308654028 * fTemp25)) + (0.0173005525 * fTemp26)) + (0.1105747111 * fTemp28)) - ((((0.041355823299999997 * fTemp21) + (0.080754876399999995 * fTemp22)) + (0.061873372199999999 * fTemp27)) + (0.019124743100000001 * fTemp29))))));
			fRec920[0] = (fRec920[1] + fTemp218);
			fRec918[0] = fRec920[0];
			double fRec919 = fTemp218;
			fRec917[0] = (fRec918[0] + fRec917[1]);
			fRec915[0] = fRec917[0];
			double fRec916 = fRec919;
			fRec914[0] = (fTemp217 + (fRec916 + fRec914[1]));
			fRec912[0] = fRec914[0];
			double fRec913 = (fRec916 + fTemp217);
			fRec911[0] = (fRec912[0] + fRec911[1]);
			fRec909[0] = fRec911[0];
			double fRec910 = fRec913;
			double fTemp219 = (fConst51 * ((fConst2 * (0.0 - ((fConst53 * fRec927[1]) + (fConst52 * fRec924[1])))) + (fConst55 * ((((0.0057115324999999998 * fTemp32) + (0.1033305972 * fTemp33)) + (0.062514519199999993 * fTemp38)) - ((((0.062919267599999995 * fTemp34) + (0.064254195 * fTemp35)) + (0.0310701998 * fTemp36)) + (0.072436876799999994 * fTemp37))))));
			fRec929[0] = (fRec929[1] + fTemp219);
			fRec927[0] = fRec929[0];
			double fRec928 = fTemp219;
			fRec926[0] = (fRec927[0] + fRec926[1]);
			fRec924[0] = fRec926[0];
			double fRec925 = fRec928;
			double fTemp220 = (fConst56 * fRec921[1]);
			fRec923[0] = ((fRec925 + fRec923[1]) - fTemp220);
			fRec921[0] = fRec923[0];
			double fRec922 = (fRec925 - fTemp220);
			double fTemp221 = (fConst57 * ((((0.061587189200000003 * fTemp41) + (0.0062667456999999996 * fTemp44)) - (((0.10430949270000001 * fTemp43) + (0.053937413900000002 * fTemp45)) + (0.041737140800000003 * fTemp42))) + (fConst2 * (0.0 - ((fConst59 * fRec933[1]) + (fConst58 * fRec930[1]))))));
			fRec935[0] = (fRec935[1] + fTemp221);
			fRec933[0] = fRec935[0];
			double fRec934 = fTemp221;
			fRec932[0] = (fRec933[0] + fRec932[1]);
			fRec930[0] = fRec932[0];
			double fRec931 = fRec934;
			double fTemp222 = (fConst60 * (((0.0554719974 * fTemp49) - ((0.064131318399999998 * fTemp47) + (0.033694832799999998 * fTemp48))) - (fConst61 * fRec936[1])));
			fRec938[0] = (fRec938[1] + fTemp222);
			fRec936[0] = fRec938[0];
			double fRec937 = fTemp222;
			fVec19[(IOTA & 511)] = (fRec895 + (fRec910 + (fRec922 + (fRec931 + (fRec937 + (0.031777949200000002 * fTemp51))))));
			output19[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec19[((IOTA - iConst62) & 511)])));
			double fTemp223 = (fConst34 * (0.0 - ((fConst36 * fRec945[1]) + (fConst35 * fRec942[1]))));
			double fTemp224 = (fConst37 * ((fConst2 * (0.0 - ((fConst39 * fRec951[1]) + (fConst38 * fRec948[1])))) + (fConst41 * ((((((((0.080333374099999993 * fTemp12) + (0.022067185999999999 * fTemp14)) + (0.030247809399999999 * fTemp7)) + (0.058576265500000002 * fTemp9)) + (0.053966902300000001 * fTemp15)) + (0.0123988413 * fTemp10)) + (0.0079689753999999998 * fTemp17)) - ((((0.0295269064 * fTemp11) + (0.093660473600000002 * fTemp13)) + (0.053731983400000002 * fTemp8)) + (0.063732538699999994 * fTemp16))))));
			fRec953[0] = (fRec953[1] + fTemp224);
			fRec951[0] = fRec953[0];
			double fRec952 = fTemp224;
			fRec950[0] = (fRec951[0] + fRec950[1]);
			fRec948[0] = fRec950[0];
			double fRec949 = fRec952;
			fRec947[0] = (fTemp223 + (fRec949 + fRec947[1]));
			fRec945[0] = fRec947[0];
			double fRec946 = (fRec949 + fTemp223);
			fRec944[0] = (fRec945[0] + fRec944[1]);
			fRec942[0] = fRec944[0];
			double fRec943 = fRec946;
			double fTemp225 = (fConst42 * fRec939[1]);
			fRec941[0] = ((fRec943 + fRec941[1]) - fTemp225);
			fRec939[0] = fRec941[0];
			double fRec940 = (fRec943 - fTemp225);
			double fTemp226 = (fConst44 * (0.0 - ((fConst46 * fRec957[1]) + (fConst45 * fRec954[1]))));
			double fTemp227 = (fConst47 * ((fConst2 * (0.0 - ((fConst49 * fRec963[1]) + (fConst48 * fRec960[1])))) + (fConst50 * ((((((0.043153848299999999 * fTemp21) + (0.071003269899999999 * fTemp24)) + (0.0048909403000000004 * fTemp25)) + (0.10152010960000001 * fTemp27)) + (0.0055458327000000003 * fTemp29)) - ((((0.092593774300000001 * fTemp23) + (0.078952410200000003 * fTemp22)) + (0.0149702233 * fTemp26)) + (0.055213435399999997 * fTemp28))))));
			fRec965[0] = (fRec965[1] + fTemp227);
			fRec963[0] = fRec965[0];
			double fRec964 = fTemp227;
			fRec962[0] = (fRec963[0] + fRec962[1]);
			fRec960[0] = fRec962[0];
			double fRec961 = fRec964;
			fRec959[0] = (fTemp226 + (fRec961 + fRec959[1]));
			fRec957[0] = fRec959[0];
			double fRec958 = (fRec961 + fTemp226);
			fRec956[0] = (fRec957[0] + fRec956[1]);
			fRec954[0] = fRec956[0];
			double fRec955 = fRec958;
			double fTemp228 = (fConst51 * ((fConst2 * (0.0 - ((fConst53 * fRec972[1]) + (fConst52 * fRec969[1])))) + (fConst55 * (((0.078561127300000005 * fTemp33) + (0.1002470553 * fTemp37)) - (((((0.050464711199999998 * fTemp32) + (0.028088053599999999 * fTemp34)) + (0.043082171400000001 * fTemp35)) + (0.099162839000000003 * fTemp36)) + (0.028347151099999999 * fTemp38))))));
			fRec974[0] = (fRec974[1] + fTemp228);
			fRec972[0] = fRec974[0];
			double fRec973 = fTemp228;
			fRec971[0] = (fRec972[0] + fRec971[1]);
			fRec969[0] = fRec971[0];
			double fRec970 = fRec973;
			double fTemp229 = (fConst56 * fRec966[1]);
			fRec968[0] = ((fRec970 + fRec968[1]) - fTemp229);
			fRec966[0] = fRec968[0];
			double fRec967 = (fRec970 - fTemp229);
			double fTemp230 = (fConst57 * (((((0.044313878199999997 * fTemp41) + (0.027660248200000001 * fTemp44)) + (0.054060242600000002 * fTemp42)) - ((0.039839455099999997 * fTemp43) + (0.1211456865 * fTemp45))) + (fConst2 * (0.0 - ((fConst59 * fRec978[1]) + (fConst58 * fRec975[1]))))));
			fRec980[0] = (fRec980[1] + fTemp230);
			fRec978[0] = fRec980[0];
			double fRec979 = fTemp230;
			fRec977[0] = (fRec978[0] + fRec977[1]);
			fRec975[0] = fRec977[0];
			double fRec976 = fRec979;
			double fTemp231 = (fConst60 * (((0.066152378100000006 * fTemp49) - ((0.023376955599999999 * fTemp47) + (0.067989926899999997 * fTemp48))) - (fConst61 * fRec981[1])));
			fRec983[0] = (fRec983[1] + fTemp231);
			fRec981[0] = fRec983[0];
			double fRec982 = fTemp231;
			fVec20[(IOTA & 511)] = (fRec940 + (fRec955 + (fRec967 + (fRec976 + (fRec982 + (0.0341328459 * fTemp51))))));
			output20[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec20[((IOTA - iConst62) & 511)])));
			double fTemp232 = (fConst34 * (0.0 - ((fConst36 * fRec990[1]) + (fConst35 * fRec987[1]))));
			double fTemp233 = (fConst37 * ((fConst2 * (0.0 - ((fConst39 * fRec996[1]) + (fConst38 * fRec993[1])))) + (fConst41 * ((((((0.0292749671 * fTemp11) + (0.096179947000000002 * fTemp13)) + (0.091860116300000003 * fTemp9)) + (0.0002205725 * fTemp15)) + (0.016353283400000002 * fTemp10)) - ((((((0.081845828699999998 * fTemp12) + (0.021595633999999999 * fTemp14)) + (0.032190859099999997 * fTemp7)) + (0.027572460199999999 * fTemp8)) + (0.040390552000000003 * fTemp16)) + (0.00013763290000000001 * fTemp17))))));
			fRec998[0] = (fRec998[1] + fTemp233);
			fRec996[0] = fRec998[0];
			double fRec997 = fTemp233;
			fRec995[0] = (fRec996[0] + fRec995[1]);
			fRec993[0] = fRec995[0];
			double fRec994 = fRec997;
			fRec992[0] = (fTemp232 + (fRec994 + fRec992[1]));
			fRec990[0] = fRec992[0];
			double fRec991 = (fRec994 + fTemp232);
			fRec989[0] = (fRec990[0] + fRec989[1]);
			fRec987[0] = fRec989[0];
			double fRec988 = fRec991;
			double fTemp234 = (fConst42 * fRec984[1]);
			fRec986[0] = ((fRec988 + fRec986[1]) - fTemp234);
			fRec984[0] = fRec986[0];
			double fRec985 = (fRec988 - fTemp234);
			double fTemp235 = (fConst44 * (0.0 - ((fConst46 * fRec1002[1]) + (fConst45 * fRec999[1]))));
			double fTemp236 = (fConst47 * ((fConst2 * (0.0 - ((fConst49 * fRec1008[1]) + (fConst48 * fRec1005[1])))) + (fConst50 * (((((0.095628860400000001 * fTemp23) + (0.034675787899999998 * fTemp26)) + (0.068887864899999998 * fTemp27)) + (0.0120505132 * fTemp29)) - (((((0.044060430599999999 * fTemp21) + (0.073031964300000002 * fTemp24)) + (0.0059923405000000003 * fTemp25)) + (0.077783141200000003 * fTemp22)) + (0.053266278299999997 * fTemp28))))));
			fRec1010[0] = (fRec1010[1] + fTemp236);
			fRec1008[0] = fRec1010[0];
			double fRec1009 = fTemp236;
			fRec1007[0] = (fRec1008[0] + fRec1007[1]);
			fRec1005[0] = fRec1007[0];
			double fRec1006 = fRec1009;
			fRec1004[0] = (fTemp235 + (fRec1006 + fRec1004[1]));
			fRec1002[0] = fRec1004[0];
			double fRec1003 = (fRec1006 + fTemp235);
			fRec1001[0] = (fRec1002[0] + fRec1001[1]);
			fRec999[0] = fRec1001[0];
			double fRec1000 = fRec1003;
			double fTemp237 = (fConst51 * ((fConst2 * (0.0 - ((fConst53 * fRec1017[1]) + (fConst52 * fRec1014[1])))) + (fConst55 * ((((0.052324425000000001 * fTemp32) + (0.028697261599999999 * fTemp34)) + (0.091584235299999997 * fTemp37)) - ((((0.081633108699999998 * fTemp33) + (0.062078777100000003 * fTemp35)) + (0.061396727300000002 * fTemp36)) + (0.032827189800000003 * fTemp38))))));
			fRec1019[0] = (fRec1019[1] + fTemp237);
			fRec1017[0] = fRec1019[0];
			double fRec1018 = fTemp237;
			fRec1016[0] = (fRec1017[0] + fRec1016[1]);
			fRec1014[0] = fRec1016[0];
			double fRec1015 = fRec1018;
			double fTemp238 = (fConst56 * fRec1011[1]);
			fRec1013[0] = ((fRec1015 + fRec1013[1]) - fTemp238);
			fRec1011[0] = fRec1013[0];
			double fRec1012 = (fRec1015 - fTemp238);
			double fTemp239 = (fConst57 * (((((0.041430062199999999 * fTemp43) + (0.0059497676000000001 * fTemp44)) + (0.055674328000000002 * fTemp42)) - ((0.046279424700000002 * fTemp41) + (0.10567978259999999 * fTemp45))) + (fConst2 * (0.0 - ((fConst59 * fRec1023[1]) + (fConst58 * fRec1020[1]))))));
			fRec1025[0] = (fRec1025[1] + fTemp239);
			fRec1023[0] = fRec1025[0];
			double fRec1024 = fTemp239;
			fRec1022[0] = (fRec1023[0] + fRec1022[1]);
			fRec1020[0] = fRec1022[0];
			double fRec1021 = fRec1024;
			double fTemp240 = (fConst60 * ((((0.0244521496 * fTemp47) + (0.053525703899999999 * fTemp49)) - (0.065684384400000004 * fTemp48)) - (fConst61 * fRec1026[1])));
			fRec1028[0] = (fRec1028[1] + fTemp240);
			fRec1026[0] = fRec1028[0];
			double fRec1027 = fTemp240;
			fVec21[(IOTA & 511)] = (fRec985 + (fRec1000 + (fRec1012 + (fRec1021 + (fRec1027 + (0.030686754 * fTemp51))))));
			output21[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec21[((IOTA - iConst62) & 511)])));
			double fTemp241 = (fConst34 * (0.0 - ((fConst36 * fRec1035[1]) + (fConst35 * fRec1032[1]))));
			double fTemp242 = (fConst37 * ((fConst2 * (0.0 - ((fConst39 * fRec1041[1]) + (fConst38 * fRec1038[1])))) + (fConst41 * ((((0.077848111900000003 * fTemp12) + (0.043444557699999997 * fTemp9)) + (0.1037341853 * fTemp16)) - ((((((((0.023230636999999998 * fTemp11) + (0.020480586200000001 * fTemp13)) + (0.0117935921 * fTemp14)) + (0.089704091700000002 * fTemp7)) + (0.030713114199999999 * fTemp8)) + (0.0134573261 * fTemp15)) + (0.028781882000000002 * fTemp10)) + (0.016929549700000001 * fTemp17))))));
			fRec1043[0] = (fRec1043[1] + fTemp242);
			fRec1041[0] = fRec1043[0];
			double fRec1042 = fTemp242;
			fRec1040[0] = (fRec1041[0] + fRec1040[1]);
			fRec1038[0] = fRec1040[0];
			double fRec1039 = fRec1042;
			fRec1037[0] = (fTemp241 + (fRec1039 + fRec1037[1]));
			fRec1035[0] = fRec1037[0];
			double fRec1036 = (fRec1039 + fTemp241);
			fRec1034[0] = (fRec1035[0] + fRec1034[1]);
			fRec1032[0] = fRec1034[0];
			double fRec1033 = fRec1036;
			double fTemp243 = (fConst42 * fRec1029[1]);
			fRec1031[0] = ((fRec1033 + fRec1031[1]) - fTemp243);
			fRec1029[0] = fRec1031[0];
			double fRec1030 = (fRec1033 - fTemp243);
			double fTemp244 = (fConst44 * (0.0 - ((fConst46 * fRec1047[1]) + (fConst45 * fRec1044[1]))));
			double fTemp245 = (fConst47 * ((fConst2 * (0.0 - ((fConst49 * fRec1053[1]) + (fConst48 * fRec1050[1])))) + (fConst50 * ((((0.0419299437 * fTemp21) + (0.015903693 * fTemp26)) + (0.1093853518 * fTemp28)) - ((((((0.016342566699999998 * fTemp23) + (0.081849991799999994 * fTemp24)) + (0.0292068235 * fTemp25)) + (0.080995262100000007 * fTemp22)) + (0.063707556700000001 * fTemp27)) + (0.0174119935 * fTemp29))))));
			fRec1055[0] = (fRec1055[1] + fTemp245);
			fRec1053[0] = fRec1055[0];
			double fRec1054 = fTemp245;
			fRec1052[0] = (fRec1053[0] + fRec1052[1]);
			fRec1050[0] = fRec1052[0];
			double fRec1051 = fRec1054;
			fRec1049[0] = (fTemp244 + (fRec1051 + fRec1049[1]));
			fRec1047[0] = fRec1049[0];
			double fRec1048 = (fRec1051 + fTemp244);
			fRec1046[0] = (fRec1047[0] + fRec1046[1]);
			fRec1044[0] = fRec1046[0];
			double fRec1045 = fRec1048;
			double fTemp246 = (fConst51 * ((fConst2 * (0.0 - ((fConst53 * fRec1062[1]) + (fConst52 * fRec1059[1])))) + (fConst55 * (((0.064181007999999998 * fTemp34) + (0.0617000074 * fTemp38)) - (((((0.0075418294999999996 * fTemp32) + (0.1012831045 * fTemp33)) + (0.063233559100000003 * fTemp35)) + (0.031045277100000001 * fTemp36)) + (0.074057640600000002 * fTemp37))))));
			fRec1064[0] = (fRec1064[1] + fTemp246);
			fRec1062[0] = fRec1064[0];
			double fRec1063 = fTemp246;
			fRec1061[0] = (fRec1062[0] + fRec1061[1]);
			fRec1059[0] = fRec1061[0];
			double fRec1060 = fRec1063;
			double fTemp247 = (fConst56 * fRec1056[1]);
			fRec1058[0] = ((fRec1060 + fRec1058[1]) - fTemp247);
			fRec1056[0] = fRec1058[0];
			double fRec1057 = (fRec1060 - fTemp247);
			double fTemp248 = (fConst57 * ((((0.1044964968 * fTemp43) + (0.0070786338000000002 * fTemp44)) - (((0.060076910499999997 * fTemp41) + (0.052737310599999997 * fTemp45)) + (0.042538739999999998 * fTemp42))) + (fConst2 * (0.0 - ((fConst59 * fRec1068[1]) + (fConst58 * fRec1065[1]))))));
			fRec1070[0] = (fRec1070[1] + fTemp248);
			fRec1068[0] = fRec1070[0];
			double fRec1069 = fTemp248;
			fRec1067[0] = (fRec1068[0] + fRec1067[1]);
			fRec1065[0] = fRec1067[0];
			double fRec1066 = fRec1069;
			double fTemp249 = (fConst60 * ((((0.063903487199999998 * fTemp47) + (0.055444317600000001 * fTemp49)) - (0.0327476721 * fTemp48)) - (fConst61 * fRec1071[1])));
			fRec1073[0] = (fRec1073[1] + fTemp249);
			fRec1071[0] = fRec1073[0];
			double fRec1072 = fTemp249;
			fVec22[(IOTA & 511)] = (fRec1030 + (fRec1045 + (fRec1057 + (fRec1066 + (fRec1072 + (0.031584639900000003 * fTemp51))))));
			output22[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec22[((IOTA - iConst62) & 511)])));
			double fTemp250 = (fConst34 * (0.0 - ((fConst36 * fRec1080[1]) + (fConst35 * fRec1077[1]))));
			double fTemp251 = (fConst37 * ((fConst2 * (0.0 - ((fConst39 * fRec1086[1]) + (fConst38 * fRec1083[1])))) + (fConst41 * ((((0.0099442948999999992 * fTemp14) + (0.0106395068 * fTemp10)) + (0.016966368400000001 * fTemp17)) - ((((((((0.0047548948999999998 * fTemp11) + (0.074753127500000002 * fTemp12)) + (0.064143982500000002 * fTemp13)) + (0.081701227400000007 * fTemp7)) + (0.041498773099999997 * fTemp8)) + (0.039649992199999998 * fTemp9)) + (0.041317189900000002 * fTemp15)) + (0.096707616400000002 * fTemp16))))));
			fRec1088[0] = (fRec1088[1] + fTemp251);
			fRec1086[0] = fRec1088[0];
			double fRec1087 = fTemp251;
			fRec1085[0] = (fRec1086[0] + fRec1085[1]);
			fRec1083[0] = fRec1085[0];
			double fRec1084 = fRec1087;
			fRec1082[0] = (fTemp250 + (fRec1084 + fRec1082[1]));
			fRec1080[0] = fRec1082[0];
			double fRec1081 = (fRec1084 + fTemp250);
			fRec1079[0] = (fRec1080[0] + fRec1079[1]);
			fRec1077[0] = fRec1079[0];
			double fRec1078 = fRec1081;
			double fTemp252 = (fConst42 * fRec1074[1]);
			fRec1076[0] = ((fRec1078 + fRec1076[1]) - fTemp252);
			fRec1074[0] = fRec1076[0];
			double fRec1075 = (fRec1078 - fTemp252);
			double fTemp253 = (fConst44 * (0.0 - ((fConst46 * fRec1092[1]) + (fConst45 * fRec1089[1]))));
			double fTemp254 = (fConst47 * ((fConst2 * (0.0 - ((fConst49 * fRec1098[1]) + (fConst48 * fRec1095[1])))) + (fConst50 * (((0.075692795600000001 * fTemp24) + (0.0047585448999999998 * fTemp29)) - (((((((0.0407784697 * fTemp21) + (0.059515338100000002 * fTemp23)) + (0.0097754320000000006 * fTemp25)) + (0.091927626900000003 * fTemp22)) + (0.014959923999999999 * fTemp26)) + (0.10644125240000001 * fTemp27)) + (0.10346473389999999 * fTemp28))))));
			fRec1100[0] = (fRec1100[1] + fTemp254);
			fRec1098[0] = fRec1100[0];
			double fRec1099 = fTemp254;
			fRec1097[0] = (fRec1098[0] + fRec1097[1]);
			fRec1095[0] = fRec1097[0];
			double fRec1096 = fRec1099;
			fRec1094[0] = (fTemp253 + (fRec1096 + fRec1094[1]));
			fRec1092[0] = fRec1094[0];
			double fRec1093 = (fRec1096 + fTemp253);
			fRec1091[0] = (fRec1092[0] + fRec1091[1]);
			fRec1089[0] = fRec1091[0];
			double fRec1090 = fRec1093;
			double fTemp255 = (fConst51 * ((fConst2 * (0.0 - ((fConst53 * fRec1107[1]) + (fConst52 * fRec1104[1])))) + (fConst55 * ((((0.094756458200000004 * fTemp33) + (0.100904202 * fTemp34)) + (0.028565991999999998 * fTemp36)) - ((((0.031892180300000003 * fTemp32) + (0.065394756400000004 * fTemp35)) + (0.1173150315 * fTemp37)) + (0.058814350000000001 * fTemp38))))));
			fRec1109[0] = (fRec1109[1] + fTemp255);
			fRec1107[0] = fRec1109[0];
			double fRec1108 = fTemp255;
			fRec1106[0] = (fRec1107[0] + fRec1106[1]);
			fRec1104[0] = fRec1106[0];
			double fRec1105 = fRec1108;
			double fTemp256 = (fConst56 * fRec1101[1]);
			fRec1103[0] = ((fRec1105 + fRec1103[1]) - fTemp256);
			fRec1101[0] = fRec1103[0];
			double fRec1102 = (fRec1105 - fTemp256);
			double fTemp257 = (fConst57 * ((((((0.056520760900000001 * fTemp41) + (0.1447242077 * fTemp43)) + (0.021229604700000002 * fTemp44)) + (0.049048282999999998 * fTemp45)) - (0.066951590300000002 * fTemp42)) + (fConst2 * (0.0 - ((fConst59 * fRec1113[1]) + (fConst58 * fRec1110[1]))))));
			fRec1115[0] = (fRec1115[1] + fTemp257);
			fRec1113[0] = fRec1115[0];
			double fRec1114 = fTemp257;
			fRec1112[0] = (fRec1113[0] + fRec1112[1]);
			fRec1110[0] = fRec1112[0];
			double fRec1111 = fRec1114;
			double fTemp258 = (fConst60 * ((((0.086306478000000006 * fTemp47) + (0.077722109100000006 * fTemp49)) + (0.030579153299999998 * fTemp48)) - (fConst61 * fRec1116[1])));
			fRec1118[0] = (fRec1118[1] + fTemp258);
			fRec1116[0] = fRec1118[0];
			double fRec1117 = fTemp258;
			fVec23[(IOTA & 511)] = (fRec1075 + (fRec1090 + (fRec1102 + (fRec1111 + (fRec1117 + (0.042479524999999997 * fTemp51))))));
			output23[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec23[((IOTA - iConst62) & 511)])));
			double fTemp259 = (fConst64 * (0.0 - ((fConst66 * fRec1125[1]) + (fConst65 * fRec1122[1]))));
			double fTemp260 = (fConst67 * ((fConst2 * (0.0 - ((fConst69 * fRec1131[1]) + (fConst68 * fRec1128[1])))) + (fConst71 * ((((((0.033880384499999999 * fTemp13) + (0.097021274699999993 * fTemp14)) + (0.082867077299999994 * fTemp7)) + (0.010806218899999999 * fTemp8)) + (0.082661755099999998 * fTemp9)) - ((((((0.0018226468000000001 * fTemp11) + (0.00019222339999999999 * fTemp12)) + (0.00055332020000000001 * fTemp15)) + (0.034551079300000002 * fTemp16)) + (0.015180261400000001 * fTemp10)) + (0.0017719496000000001 * fTemp17))))));
			fRec1133[0] = (fRec1133[1] + fTemp260);
			fRec1131[0] = fRec1133[0];
			double fRec1132 = fTemp260;
			fRec1130[0] = (fRec1131[0] + fRec1130[1]);
			fRec1128[0] = fRec1130[0];
			double fRec1129 = fRec1132;
			fRec1127[0] = (fTemp259 + (fRec1129 + fRec1127[1]));
			fRec1125[0] = fRec1127[0];
			double fRec1126 = (fRec1129 + fTemp259);
			fRec1124[0] = (fRec1125[0] + fRec1124[1]);
			fRec1122[0] = fRec1124[0];
			double fRec1123 = fRec1126;
			double fTemp261 = (fConst72 * fRec1119[1]);
			fRec1121[0] = ((fRec1123 + fRec1121[1]) - fTemp261);
			fRec1119[0] = fRec1121[0];
			double fRec1120 = (fRec1123 - fTemp261);
			double fTemp262 = (fConst74 * (0.0 - ((fConst76 * fRec1137[1]) + (fConst75 * fRec1134[1]))));
			double fTemp263 = (fConst77 * ((fConst2 * (0.0 - ((fConst79 * fRec1143[1]) + (fConst78 * fRec1140[1])))) + (fConst80 * ((((((0.019443636100000002 * fTemp23) + (0.077527304199999994 * fTemp24)) + (0.091170567699999996 * fTemp25)) + (0.044844193800000001 * fTemp22)) + (0.0908243938 * fTemp26)) - ((((6.83278e-05 * fTemp21) + (0.00045907810000000001 * fTemp27)) + (0.019823344199999999 * fTemp28)) + (0.0055343296000000004 * fTemp29))))));
			fRec1145[0] = (fRec1145[1] + fTemp263);
			fRec1143[0] = fRec1145[0];
			double fRec1144 = fTemp263;
			fRec1142[0] = (fRec1143[0] + fRec1142[1]);
			fRec1140[0] = fRec1142[0];
			double fRec1141 = fRec1144;
			fRec1139[0] = (fTemp262 + (fRec1141 + fRec1139[1]));
			fRec1137[0] = fRec1139[0];
			double fRec1138 = (fRec1141 + fTemp262);
			fRec1136[0] = (fRec1137[0] + fRec1136[1]);
			fRec1134[0] = fRec1136[0];
			double fRec1135 = fRec1138;
			double fTemp264 = (fConst81 * ((fConst2 * (0.0 - ((fConst83 * fRec1152[1]) + (fConst82 * fRec1149[1])))) + (fConst85 * ((((((0.0074215373999999999 * fTemp32) + (0.047310529900000002 * fTemp33)) + (0.080226799400000007 * fTemp34)) + (0.074249264300000006 * fTemp35)) + (0.079867278700000002 * fTemp36)) - ((0.00028462970000000002 * fTemp37) + (0.0075645291 * fTemp38))))));
			fRec1154[0] = (fRec1154[1] + fTemp264);
			fRec1152[0] = fRec1154[0];
			double fRec1153 = fTemp264;
			fRec1151[0] = (fRec1152[0] + fRec1151[1]);
			fRec1149[0] = fRec1151[0];
			double fRec1150 = fRec1153;
			double fTemp265 = (fConst86 * fRec1146[1]);
			fRec1148[0] = ((fRec1150 + fRec1148[1]) - fTemp265);
			fRec1146[0] = fRec1148[0];
			double fRec1147 = (fRec1150 - fTemp265);
			double fTemp266 = (fConst87 * ((((((0.018889524800000002 * fTemp41) + (0.0532528341 * fTemp43)) + (0.084355014699999994 * fTemp44)) + (0.052994769900000002 * fTemp45)) - (0.0001143287 * fTemp42)) + (fConst2 * (0.0 - ((fConst89 * fRec1158[1]) + (fConst88 * fRec1155[1]))))));
			fRec1160[0] = (fRec1160[1] + fTemp266);
			fRec1158[0] = fRec1160[0];
			double fRec1159 = fTemp266;
			fRec1157[0] = (fRec1158[0] + fRec1157[1]);
			fRec1155[0] = fRec1157[0];
			double fRec1156 = fRec1159;
			double fTemp267 = (fConst90 * ((((0.0220263973 * fTemp47) + (0.066940710599999995 * fTemp49)) + (0.021915488699999999 * fTemp48)) - (fConst91 * fRec1161[1])));
			fRec1163[0] = (fRec1163[1] + fTemp267);
			fRec1161[0] = fRec1163[0];
			double fRec1162 = fTemp267;
			fVec24[(IOTA & 255)] = (fRec1120 + (fRec1135 + (fRec1147 + (fRec1156 + (fRec1162 + (0.025484838499999999 * fTemp51))))));
			output24[i] = FAUSTFLOAT((0.95355093256814927 * (fRec0[0] * fVec24[((IOTA - iConst92) & 255)])));
			double fTemp268 = (fConst64 * (0.0 - ((fConst66 * fRec1170[1]) + (fConst65 * fRec1167[1]))));
			double fTemp269 = (fConst67 * ((fConst2 * (0.0 - ((fConst69 * fRec1176[1]) + (fConst68 * fRec1173[1])))) + (fConst71 * (((((((0.0016894869999999999 * fTemp11) + (0.00039432650000000003 * fTemp12)) + (0.1057515086 * fTemp9)) + (0.048505625099999998 * fTemp15)) + (0.00013225619999999999 * fTemp16)) + (0.0012080299999999999 * fTemp17)) - (((((0.0326343391 * fTemp13) + (0.095239837300000005 * fTemp14)) + (0.081620654000000001 * fTemp7)) + (0.0140094637 * fTemp8)) + (0.0013064534999999999 * fTemp10))))));
			fRec1178[0] = (fRec1178[1] + fTemp269);
			fRec1176[0] = fRec1178[0];
			double fRec1177 = fTemp269;
			fRec1175[0] = (fRec1176[0] + fRec1175[1]);
			fRec1173[0] = fRec1175[0];
			double fRec1174 = fRec1177;
			fRec1172[0] = (fTemp268 + (fRec1174 + fRec1172[1]));
			fRec1170[0] = fRec1172[0];
			double fRec1171 = (fRec1174 + fTemp268);
			fRec1169[0] = (fRec1170[0] + fRec1169[1]);
			fRec1167[0] = fRec1169[0];
			double fRec1168 = fRec1171;
			double fTemp270 = (fConst72 * fRec1164[1]);
			fRec1166[0] = ((fRec1168 + fRec1166[1]) - fTemp270);
			fRec1164[0] = fRec1166[0];
			double fRec1165 = (fRec1168 - fTemp270);
			double fTemp271 = (fConst74 * (0.0 - ((fConst76 * fRec1182[1]) + (fConst75 * fRec1179[1]))));
			double fTemp272 = (fConst77 * ((fConst2 * (0.0 - ((fConst79 * fRec1188[1]) + (fConst78 * fRec1185[1])))) + (fConst80 * ((((((0.0001095549 * fTemp21) + (0.035412133300000002 * fTemp22)) + (0.13222508099999999 * fTemp26)) + (0.042095312000000003 * fTemp27)) + (0.00033663619999999998 * fTemp28)) - ((((0.018938804100000001 * fTemp23) + (0.076722609400000003 * fTemp24)) + (0.090556428999999994 * fTemp25)) + (0.00050223140000000004 * fTemp29))))));
			fRec1190[0] = (fRec1190[1] + fTemp272);
			fRec1188[0] = fRec1190[0];
			double fRec1189 = fTemp272;
			fRec1187[0] = (fRec1188[0] + fRec1187[1]);
			fRec1185[0] = fRec1187[0];
			double fRec1186 = fRec1189;
			fRec1184[0] = (fTemp271 + (fRec1186 + fRec1184[1]));
			fRec1182[0] = fRec1184[0];
			double fRec1183 = (fRec1186 + fTemp271);
			fRec1181[0] = (fRec1182[0] + fRec1181[1]);
			fRec1179[0] = fRec1181[0];
			double fRec1180 = fRec1183;
			double fTemp273 = (fConst81 * ((fConst2 * (0.0 - ((fConst83 * fRec1197[1]) + (fConst82 * fRec1194[1])))) + (fConst85 * (((((0.083417450300000001 * fTemp35) + (0.1245961587 * fTemp36)) + (0.0269801361 * fTemp37)) + (0.0001976359 * fTemp38)) - (((0.0072807378999999997 * fTemp32) + (0.047062170200000003 * fTemp33)) + (0.080118257700000001 * fTemp34))))));
			fRec1199[0] = (fRec1199[1] + fTemp273);
			fRec1197[0] = fRec1199[0];
			double fRec1198 = fTemp273;
			fRec1196[0] = (fRec1197[0] + fRec1196[1]);
			fRec1194[0] = fRec1196[0];
			double fRec1195 = fRec1198;
			double fTemp274 = (fConst86 * fRec1191[1]);
			fRec1193[0] = ((fRec1195 + fRec1193[1]) - fTemp274);
			fRec1191[0] = fRec1193[0];
			double fRec1192 = (fRec1195 - fTemp274);
			double fTemp275 = (fConst87 * (((((0.1059216186 * fTemp44) + (0.085990975400000003 * fTemp45)) + (0.0110994197 * fTemp42)) - ((0.018852114400000002 * fTemp41) + (0.053363046400000003 * fTemp43))) + (fConst2 * (0.0 - ((fConst89 * fRec1203[1]) + (fConst88 * fRec1200[1]))))));
			fRec1205[0] = (fRec1205[1] + fTemp275);
			fRec1203[0] = fRec1205[0];
			double fRec1204 = fTemp275;
			fRec1202[0] = (fRec1203[0] + fRec1202[1]);
			fRec1200[0] = fRec1202[0];
			double fRec1201 = fRec1204;
			double fTemp276 = (fConst90 * ((((0.088250094200000004 * fTemp49) + (0.036347145999999997 * fTemp48)) - (0.0221166977 * fTemp47)) - (fConst91 * fRec1206[1])));
			fRec1208[0] = (fRec1208[1] + fTemp276);
			fRec1206[0] = fRec1208[0];
			double fRec1207 = fTemp276;
			fVec25[(IOTA & 255)] = (fRec1165 + (fRec1180 + (fRec1192 + (fRec1201 + (fRec1207 + (0.0342672386 * fTemp51))))));
			output25[i] = FAUSTFLOAT((0.95355093256814927 * (fRec0[0] * fVec25[((IOTA - iConst92) & 255)])));
			double fTemp277 = (fConst64 * (0.0 - ((fConst66 * fRec1215[1]) + (fConst65 * fRec1212[1]))));
			double fTemp278 = (fConst67 * ((fConst2 * (0.0 - ((fConst69 * fRec1221[1]) + (fConst68 * fRec1218[1])))) + (fConst71 * ((((0.096361569300000005 * fTemp14) + (0.033850340200000002 * fTemp16)) + (0.0016694532000000001 * fTemp17)) - ((((((((0.0011009454 * fTemp11) + (1.62738e-05 * fTemp12)) + (0.0011407392000000001 * fTemp13)) + (0.10507075070000001 * fTemp7)) + (0.0134977841 * fTemp8)) + (0.081516563299999997 * fTemp9)) + (0.0472265532 * fTemp15)) + (0.0019315948999999999 * fTemp10))))));
			fRec1223[0] = (fRec1223[1] + fTemp278);
			fRec1221[0] = fRec1223[0];
			double fRec1222 = fTemp278;
			fRec1220[0] = (fRec1221[0] + fRec1220[1]);
			fRec1218[0] = fRec1220[0];
			double fRec1219 = fRec1222;
			fRec1217[0] = (fTemp277 + (fRec1219 + fRec1217[1]));
			fRec1215[0] = fRec1217[0];
			double fRec1216 = (fRec1219 + fTemp277);
			fRec1214[0] = (fRec1215[0] + fRec1214[1]);
			fRec1212[0] = fRec1214[0];
			double fRec1213 = fRec1216;
			double fTemp279 = (fConst72 * fRec1209[1]);
			fRec1211[0] = ((fRec1213 + fRec1211[1]) - fTemp279);
			fRec1209[0] = fRec1211[0];
			double fRec1210 = (fRec1213 - fTemp279);
			double fTemp280 = (fConst74 * (0.0 - ((fConst76 * fRec1227[1]) + (fConst75 * fRec1224[1]))));
			double fTemp281 = (fConst77 * ((fConst2 * (0.0 - ((fConst79 * fRec1233[1]) + (fConst78 * fRec1230[1])))) + (fConst80 * ((((0.077886471700000001 * fTemp24) + (0.035475477599999999 * fTemp22)) + (0.019692611400000001 * fTemp28)) - ((((((3.8794600000000003e-05 * fTemp21) + (0.00047503239999999999 * fTemp23)) + (0.1311634807 * fTemp25)) + (0.090854007400000006 * fTemp26)) + (0.0409009969 * fTemp27)) + (0.000748532 * fTemp29))))));
			fRec1235[0] = (fRec1235[1] + fTemp281);
			fRec1233[0] = fRec1235[0];
			double fRec1234 = fTemp281;
			fRec1232[0] = (fRec1233[0] + fRec1232[1]);
			fRec1230[0] = fRec1232[0];
			double fRec1231 = fRec1234;
			fRec1229[0] = (fTemp280 + (fRec1231 + fRec1229[1]));
			fRec1227[0] = fRec1229[0];
			double fRec1228 = (fRec1231 + fTemp280);
			fRec1226[0] = (fRec1227[0] + fRec1226[1]);
			fRec1224[0] = fRec1226[0];
			double fRec1225 = fRec1228;
			double fTemp282 = (fConst81 * ((fConst2 * (0.0 - ((fConst83 * fRec1242[1]) + (fConst82 * fRec1239[1])))) + (fConst85 * ((((0.047892361899999999 * fTemp33) + (0.083063305300000001 * fTemp35)) + (0.0075846198999999998 * fTemp38)) - ((((0.00013548499999999999 * fTemp32) + (0.12352071570000001 * fTemp34)) + (0.080642031099999997 * fTemp36)) + (0.026178806400000001 * fTemp37))))));
			fRec1244[0] = (fRec1244[1] + fTemp282);
			fRec1242[0] = fRec1244[0];
			double fRec1243 = fTemp282;
			fRec1241[0] = (fRec1242[0] + fRec1241[1]);
			fRec1239[0] = fRec1241[0];
			double fRec1240 = fRec1243;
			double fTemp283 = (fConst86 * fRec1236[1]);
			fRec1238[0] = ((fRec1240 + fRec1238[1]) - fTemp283);
			fRec1236[0] = fRec1238[0];
			double fRec1237 = (fRec1240 - fTemp283);
			double fTemp284 = (fConst87 * ((((0.0192173694 * fTemp41) + (0.1053520488 * fTemp44)) - (((0.0852277699 * fTemp43) + (0.0538309155 * fTemp45)) + (0.010759918699999999 * fTemp42))) + (fConst2 * (0.0 - ((fConst89 * fRec1248[1]) + (fConst88 * fRec1245[1]))))));
			fRec1250[0] = (fRec1250[1] + fTemp284);
			fRec1248[0] = fRec1250[0];
			double fRec1249 = fTemp284;
			fRec1247[0] = (fRec1248[0] + fRec1247[1]);
			fRec1245[0] = fRec1247[0];
			double fRec1246 = fRec1249;
			double fTemp285 = (fConst90 * (((0.087746924800000001 * fTemp49) - ((0.036021007299999998 * fTemp47) + (0.0223415236 * fTemp48))) - (fConst91 * fRec1251[1])));
			fRec1253[0] = (fRec1253[1] + fTemp285);
			fRec1251[0] = fRec1253[0];
			double fRec1252 = fTemp285;
			fVec26[(IOTA & 255)] = (fRec1210 + (fRec1225 + (fRec1237 + (fRec1246 + (fRec1252 + (0.034068688299999997 * fTemp51))))));
			output26[i] = FAUSTFLOAT((0.95355093256814927 * (fRec0[0] * fVec26[((IOTA - iConst92) & 255)])));
			double fTemp286 = (fConst64 * (0.0 - ((fConst66 * fRec1260[1]) + (fConst65 * fRec1257[1]))));
			double fTemp287 = (fConst67 * ((fConst2 * (0.0 - ((fConst69 * fRec1266[1]) + (fConst68 * fRec1263[1])))) + (fConst71 * ((((0.0012526867000000001 * fTemp11) + (0.1037612626 * fTemp7)) + (0.0119838293 * fTemp10)) - ((((((((0.00043575059999999998 * fTemp12) + (7.2930999999999997e-06 * fTemp13)) + (0.093625903699999999 * fTemp14)) + (0.037145560299999998 * fTemp8)) + (0.1030427476 * fTemp9)) + (4.7280400000000002e-05 * fTemp15)) + (0.0012021619999999999 * fTemp16)) + (0.0012754428 * fTemp17))))));
			fRec1268[0] = (fRec1268[1] + fTemp287);
			fRec1266[0] = fRec1268[0];
			double fRec1267 = fTemp287;
			fRec1265[0] = (fRec1266[0] + fRec1265[1]);
			fRec1263[0] = fRec1265[0];
			double fRec1264 = fRec1267;
			fRec1262[0] = (fTemp286 + (fRec1264 + fRec1262[1]));
			fRec1260[0] = fRec1262[0];
			double fRec1261 = (fRec1264 + fTemp286);
			fRec1259[0] = (fRec1260[0] + fRec1259[1]);
			fRec1257[0] = fRec1259[0];
			double fRec1258 = fRec1261;
			double fTemp288 = (fConst72 * fRec1254[1]);
			fRec1256[0] = ((fRec1258 + fRec1256[1]) - fTemp288);
			fRec1254[0] = fRec1256[0];
			double fRec1255 = (fRec1258 - fTemp288);
			double fTemp289 = (fConst74 * (0.0 - ((fConst76 * fRec1272[1]) + (fConst75 * fRec1269[1]))));
			double fTemp290 = (fConst77 * ((fConst2 * (0.0 - ((fConst79 * fRec1278[1]) + (fConst78 * fRec1275[1])))) + (fConst80 * ((((((8.2826999999999995e-06 * fTemp23) + (0.1303688167 * fTemp25)) + (0.0263377365 * fTemp22)) + (0.00021647539999999999 * fTemp27)) + (0.0043209737000000003 * fTemp29)) - ((((0.00016173690000000001 * fTemp21) + (0.076127181000000002 * fTemp24)) + (0.12980282479999999 * fTemp26)) + (0.00079116929999999998 * fTemp28))))));
			fRec1280[0] = (fRec1280[1] + fTemp290);
			fRec1278[0] = fRec1280[0];
			double fRec1279 = fTemp290;
			fRec1277[0] = (fRec1278[0] + fRec1277[1]);
			fRec1275[0] = fRec1277[0];
			double fRec1276 = fRec1279;
			fRec1274[0] = (fTemp289 + (fRec1276 + fRec1274[1]));
			fRec1272[0] = fRec1274[0];
			double fRec1273 = (fRec1276 + fTemp289);
			fRec1271[0] = (fRec1272[0] + fRec1271[1]);
			fRec1269[0] = fRec1271[0];
			double fRec1270 = fRec1273;
			double fTemp291 = (fConst81 * ((fConst2 * (0.0 - ((fConst83 * fRec1287[1]) + (fConst82 * fRec1284[1])))) + (fConst85 * (((((4.6511999999999996e-06 * fTemp32) + (0.1231784569 * fTemp34)) + (0.091598701500000004 * fTemp35)) + (0.0002487492 * fTemp37)) - (((0.046980838699999999 * fTemp33) + (0.1228703683 * fTemp36)) + (0.00033243319999999999 * fTemp38))))));
			fRec1289[0] = (fRec1289[1] + fTemp291);
			fRec1287[0] = fRec1289[0];
			double fRec1288 = fTemp291;
			fRec1286[0] = (fRec1287[0] + fRec1286[1]);
			fRec1284[0] = fRec1286[0];
			double fRec1285 = fRec1288;
			double fTemp292 = (fConst86 * fRec1281[1]);
			fRec1283[0] = ((fRec1285 + fRec1283[1]) - fTemp292);
			fRec1281[0] = fRec1283[0];
			double fRec1282 = (fRec1285 - fTemp292);
			double fTemp293 = (fConst87 * (((((0.085146978799999995 * fTemp43) + (0.12573050590000001 * fTemp44)) + (0.00013258160000000001 * fTemp42)) - ((0.018893480399999999 * fTemp41) + (0.085042134500000005 * fTemp45))) + (fConst2 * (0.0 - ((fConst89 * fRec1293[1]) + (fConst88 * fRec1290[1]))))));
			fRec1295[0] = (fRec1295[1] + fTemp293);
			fRec1293[0] = fRec1295[0];
			double fRec1294 = fTemp293;
			fRec1292[0] = (fRec1293[0] + fRec1292[1]);
			fRec1290[0] = fRec1292[0];
			double fRec1291 = fRec1294;
			double fTemp294 = (fConst90 * ((((0.036022687499999997 * fTemp47) + (0.10794643850000001 * fTemp49)) - (0.036007171800000001 * fTemp48)) - (fConst91 * fRec1296[1])));
			fRec1298[0] = (fRec1298[1] + fTemp294);
			fRec1296[0] = fRec1298[0];
			double fRec1297 = fTemp294;
			fVec27[(IOTA & 255)] = (fRec1255 + (fRec1270 + (fRec1282 + (fRec1291 + (fRec1297 + (0.0424027981 * fTemp51))))));
			output27[i] = FAUSTFLOAT((0.95355093256814927 * (fRec0[0] * fVec27[((IOTA - iConst92) & 255)])));
			double fTemp295 = (fConst94 * (0.0 - ((fConst96 * fRec1305[1]) + (fConst95 * fRec1302[1]))));
			double fTemp296 = (fConst97 * ((fConst2 * (0.0 - ((fConst99 * fRec1311[1]) + (fConst98 * fRec1308[1])))) + (fConst101 * (((((((((2.5699999999999999e-08 * fTemp11) + (1.1880999999999999e-06 * fTemp12)) + (4.8663000000000003e-06 * fTemp13)) + (1.28405e-05 * fTemp14)) + (2.6307100000000001e-05 * fTemp7)) + (0.0916704765 * fTemp8)) + (7.3862999999999999e-06 * fTemp16)) + (4.2000000000000004e-09 * fTemp17)) - (((8.3396699999999994e-05 * fTemp9) + (1.9692000000000001e-05 * fTemp15)) + (9.8370300000000002e-05 * fTemp10))))));
			fRec1313[0] = (fRec1313[1] + fTemp296);
			fRec1311[0] = fRec1313[0];
			double fRec1312 = fTemp296;
			fRec1310[0] = (fRec1311[0] + fRec1310[1]);
			fRec1308[0] = fRec1310[0];
			double fRec1309 = fRec1312;
			fRec1307[0] = (fTemp295 + (fRec1309 + fRec1307[1]));
			fRec1305[0] = fRec1307[0];
			double fRec1306 = (fRec1309 + fTemp295);
			fRec1304[0] = (fRec1305[0] + fRec1304[1]);
			fRec1302[0] = fRec1304[0];
			double fRec1303 = fRec1306;
			double fTemp297 = (fConst102 * fRec1299[1]);
			fRec1301[0] = ((fRec1303 + fRec1301[1]) - fTemp297);
			fRec1299[0] = fRec1301[0];
			double fRec1300 = (fRec1303 - fTemp297);
			double fTemp298 = (fConst104 * (0.0 - ((fConst106 * fRec1317[1]) + (fConst105 * fRec1314[1]))));
			double fTemp299 = (fConst107 * ((fConst2 * (0.0 - ((fConst109 * fRec1323[1]) + (fConst108 * fRec1320[1])))) + (fConst110 * (((((((3.3640000000000002e-07 * fTemp21) + (2.0760999999999999e-06 * fTemp23)) + (7.3386999999999997e-06 * fTemp24)) + (1.80029e-05 * fTemp25)) + (0.080551933800000003 * fTemp22)) + (3.3268999999999999e-06 * fTemp28)) - (((6.3924199999999994e-05 * fTemp26) + (1.12209e-05 * fTemp27)) + (2.7866699999999999e-05 * fTemp29))))));
			fRec1325[0] = (fRec1325[1] + fTemp299);
			fRec1323[0] = fRec1325[0];
			double fRec1324 = fTemp299;
			fRec1322[0] = (fRec1323[0] + fRec1322[1]);
			fRec1320[0] = fRec1322[0];
			double fRec1321 = fRec1324;
			fRec1319[0] = (fTemp298 + (fRec1321 + fRec1319[1]));
			fRec1317[0] = fRec1319[0];
			double fRec1318 = (fRec1321 + fTemp298);
			fRec1316[0] = (fRec1317[0] + fRec1316[1]);
			fRec1314[0] = fRec1316[0];
			double fRec1315 = fRec1318;
			double fTemp300 = (fConst111 * ((fConst2 * (0.0 - ((fConst113 * fRec1332[1]) + (fConst112 * fRec1329[1])))) + (fConst115 * ((((((6.3099999999999997e-07 * fTemp32) + (3.4688999999999999e-06 * fTemp33)) + (1.10318e-05 * fTemp34)) + (0.066280089799999997 * fTemp35)) + (1.0543e-06 * fTemp38)) - ((4.2822599999999999e-05 * fTemp36) + (5.2900000000000002e-06 * fTemp37))))));
			fRec1334[0] = (fRec1334[1] + fTemp300);
			fRec1332[0] = fRec1334[0];
			double fRec1333 = fTemp300;
			fRec1331[0] = (fRec1332[0] + fRec1331[1]);
			fRec1329[0] = fRec1331[0];
			double fRec1330 = fRec1333;
			double fTemp301 = (fConst116 * fRec1326[1]);
			fRec1328[0] = ((fRec1330 + fRec1328[1]) - fTemp301);
			fRec1326[0] = fRec1328[0];
			double fRec1327 = (fRec1330 - fTemp301);
			double fTemp302 = (fConst117 * (((((1.1512000000000001e-06 * fTemp41) + (5.6354999999999997e-06 * fTemp43)) + (0.049362916700000002 * fTemp44)) - ((2.3371799999999999e-05 * fTemp45) + (1.7517999999999999e-06 * fTemp42))) + (fConst2 * (0.0 - ((fConst119 * fRec1338[1]) + (fConst118 * fRec1335[1]))))));
			fRec1340[0] = (fRec1340[1] + fTemp302);
			fRec1338[0] = fRec1340[0];
			double fRec1339 = fTemp302;
			fRec1337[0] = (fRec1338[0] + fRec1337[1]);
			fRec1335[0] = fRec1337[0];
			double fRec1336 = fRec1339;
			double fTemp303 = (fConst120 * ((((1.9657000000000001e-06 * fTemp47) + (0.0304481074 * fTemp49)) - (8.5176999999999998e-06 * fTemp48)) - (fConst121 * fRec1341[1])));
			fRec1343[0] = (fRec1343[1] + fTemp303);
			fRec1341[0] = fRec1343[0];
			double fRec1342 = fTemp303;
			output28[i] = FAUSTFLOAT((fRec0[0] * (fRec1300 + (fRec1315 + (fRec1327 + (fRec1336 + (fRec1342 + (0.0102900397 * fTemp51))))))));
			fRec0[1] = fRec0[0];
			fRec16[1] = fRec16[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
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
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
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
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fRec40[1] = fRec40[0];
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec29[1] = fRec29[0];
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
			fRec58[1] = fRec58[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec53[1] = fRec53[0];
			fRec52[1] = fRec52[0];
			fRec50[1] = fRec50[0];
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
			fRec71[1] = fRec71[0];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			fRec66[1] = fRec66[0];
			fRec80[2] = fRec80[1];
			fRec80[1] = fRec80[0];
			fRec81[2] = fRec81[1];
			fRec81[1] = fRec81[0];
			fRec82[2] = fRec82[1];
			fRec82[1] = fRec82[0];
			fRec79[1] = fRec79[0];
			fRec77[1] = fRec77[0];
			fRec83[2] = fRec83[1];
			fRec83[1] = fRec83[0];
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
			fRec125[1] = fRec125[0];
			fRec123[1] = fRec123[0];
			fRec122[1] = fRec122[0];
			fRec120[1] = fRec120[0];
			fRec128[1] = fRec128[0];
			fRec126[1] = fRec126[0];
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
			fRec170[1] = fRec170[0];
			fRec168[1] = fRec168[0];
			fRec167[1] = fRec167[0];
			fRec165[1] = fRec165[0];
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
			fRec215[1] = fRec215[0];
			fRec213[1] = fRec213[0];
			fRec212[1] = fRec212[0];
			fRec210[1] = fRec210[0];
			fRec218[1] = fRec218[0];
			fRec216[1] = fRec216[0];
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
			fRec260[1] = fRec260[0];
			fRec258[1] = fRec258[0];
			fRec257[1] = fRec257[0];
			fRec255[1] = fRec255[0];
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
			fRec305[1] = fRec305[0];
			fRec303[1] = fRec303[0];
			fRec302[1] = fRec302[0];
			fRec300[1] = fRec300[0];
			fRec308[1] = fRec308[0];
			fRec306[1] = fRec306[0];
			fRec317[1] = fRec317[0];
			fRec315[1] = fRec315[0];
			fRec314[1] = fRec314[0];
			fRec312[1] = fRec312[0];
			fRec311[1] = fRec311[0];
			fRec309[1] = fRec309[0];
			fRec323[1] = fRec323[0];
			fRec321[1] = fRec321[0];
			fRec320[1] = fRec320[0];
			fRec318[1] = fRec318[0];
			fRec326[1] = fRec326[0];
			fRec324[1] = fRec324[0];
			fRec338[1] = fRec338[0];
			fRec336[1] = fRec336[0];
			fRec335[1] = fRec335[0];
			fRec333[1] = fRec333[0];
			fRec332[1] = fRec332[0];
			fRec330[1] = fRec330[0];
			fRec329[1] = fRec329[0];
			fRec327[1] = fRec327[0];
			fRec353[1] = fRec353[0];
			fRec351[1] = fRec351[0];
			fRec350[1] = fRec350[0];
			fRec348[1] = fRec348[0];
			fRec347[1] = fRec347[0];
			fRec345[1] = fRec345[0];
			fRec344[1] = fRec344[0];
			fRec342[1] = fRec342[0];
			fRec341[1] = fRec341[0];
			fRec339[1] = fRec339[0];
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
			fRec530[1] = fRec530[0];
			fRec528[1] = fRec528[0];
			fRec527[1] = fRec527[0];
			fRec525[1] = fRec525[0];
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
			fRec575[1] = fRec575[0];
			fRec573[1] = fRec573[0];
			fRec572[1] = fRec572[0];
			fRec570[1] = fRec570[0];
			fRec578[1] = fRec578[0];
			fRec576[1] = fRec576[0];
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
			fRec620[1] = fRec620[0];
			fRec618[1] = fRec618[0];
			fRec617[1] = fRec617[0];
			fRec615[1] = fRec615[0];
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
			fRec665[1] = fRec665[0];
			fRec663[1] = fRec663[0];
			fRec662[1] = fRec662[0];
			fRec660[1] = fRec660[0];
			fRec668[1] = fRec668[0];
			fRec666[1] = fRec666[0];
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
			fRec710[1] = fRec710[0];
			fRec708[1] = fRec708[0];
			fRec707[1] = fRec707[0];
			fRec705[1] = fRec705[0];
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
			fRec755[1] = fRec755[0];
			fRec753[1] = fRec753[0];
			fRec752[1] = fRec752[0];
			fRec750[1] = fRec750[0];
			fRec758[1] = fRec758[0];
			fRec756[1] = fRec756[0];
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
			fRec800[1] = fRec800[0];
			fRec798[1] = fRec798[0];
			fRec797[1] = fRec797[0];
			fRec795[1] = fRec795[0];
			fRec803[1] = fRec803[0];
			fRec801[1] = fRec801[0];
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
			fRec845[1] = fRec845[0];
			fRec843[1] = fRec843[0];
			fRec842[1] = fRec842[0];
			fRec840[1] = fRec840[0];
			fRec848[1] = fRec848[0];
			fRec846[1] = fRec846[0];
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
			fRec890[1] = fRec890[0];
			fRec888[1] = fRec888[0];
			fRec887[1] = fRec887[0];
			fRec885[1] = fRec885[0];
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
			fRec935[1] = fRec935[0];
			fRec933[1] = fRec933[0];
			fRec932[1] = fRec932[0];
			fRec930[1] = fRec930[0];
			fRec938[1] = fRec938[0];
			fRec936[1] = fRec936[0];
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
			fRec980[1] = fRec980[0];
			fRec978[1] = fRec978[0];
			fRec977[1] = fRec977[0];
			fRec975[1] = fRec975[0];
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
			fRec1025[1] = fRec1025[0];
			fRec1023[1] = fRec1023[0];
			fRec1022[1] = fRec1022[0];
			fRec1020[1] = fRec1020[0];
			fRec1028[1] = fRec1028[0];
			fRec1026[1] = fRec1026[0];
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
			fRec1070[1] = fRec1070[0];
			fRec1068[1] = fRec1068[0];
			fRec1067[1] = fRec1067[0];
			fRec1065[1] = fRec1065[0];
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
			fRec1115[1] = fRec1115[0];
			fRec1113[1] = fRec1113[0];
			fRec1112[1] = fRec1112[0];
			fRec1110[1] = fRec1110[0];
			fRec1118[1] = fRec1118[0];
			fRec1116[1] = fRec1116[0];
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
			fRec1160[1] = fRec1160[0];
			fRec1158[1] = fRec1158[0];
			fRec1157[1] = fRec1157[0];
			fRec1155[1] = fRec1155[0];
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
			fRec1205[1] = fRec1205[0];
			fRec1203[1] = fRec1203[0];
			fRec1202[1] = fRec1202[0];
			fRec1200[1] = fRec1200[0];
			fRec1208[1] = fRec1208[0];
			fRec1206[1] = fRec1206[0];
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
			fRec1250[1] = fRec1250[0];
			fRec1248[1] = fRec1248[0];
			fRec1247[1] = fRec1247[0];
			fRec1245[1] = fRec1245[0];
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
			fRec1295[1] = fRec1295[0];
			fRec1293[1] = fRec1293[0];
			fRec1292[1] = fRec1292[0];
			fRec1290[1] = fRec1290[0];
			fRec1298[1] = fRec1298[0];
			fRec1296[1] = fRec1296[0];
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
			fRec1340[1] = fRec1340[0];
			fRec1338[1] = fRec1338[0];
			fRec1337[1] = fRec1337[0];
			fRec1335[1] = fRec1335[0];
			fRec1343[1] = fRec1343[0];
			fRec1341[1] = fRec1341[0];
			
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

#define EXTERNAL_VERSION    "0.68"
#define STR_SIZE            512

/************************** BEGIN MidiUI.h **************************/
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

/************************** BEGIN MapUI.h **************************/
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
            pushLabel(label);
        }
        void openHorizontalBox(const char* label)
        {
            pushLabel(label);
        }
        void openVerticalBox(const char* label)
        {
            pushLabel(label);
        }
        void closeBox()
        {
            popLabel();
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
    
        static bool endsWith(std::string const& str, std::string const& end)
        {
            size_t l1 = str.length();
            size_t l2 = end.length();
            return (l1 >= l2) && (0 == str.compare(l1 - l2, l2, end));
        }
};


#endif // FAUST_MAPUI_H
/**************************  END  MapUI.h **************************/
/************************** BEGIN MetaDataUI.h **************************/
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

#ifndef MetaData_UI_H
#define MetaData_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <map>
#include <set>
#include <string>
#include <assert.h>


static bool startWith(const std::string& str, const std::string& prefix)
{
    return (str.substr(0, prefix.size()) == prefix);
}

/**
 * Convert a dB value into a scale between 0 and 1 (following IEC standard ?)
 */
static FAUSTFLOAT dB2Scale(FAUSTFLOAT dB)
{
    FAUSTFLOAT scale = FAUSTFLOAT(1.0);
    
    /*if (dB < -70.0f)
     scale = 0.0f;
     else*/
    if (dB < FAUSTFLOAT(-60.0))
        scale = (dB + FAUSTFLOAT(70.0)) * FAUSTFLOAT(0.0025);
    else if (dB < FAUSTFLOAT(-50.0))
        scale = (dB + FAUSTFLOAT(60.0)) * FAUSTFLOAT(0.005) + FAUSTFLOAT(0.025);
    else if (dB < FAUSTFLOAT(-40.0))
        scale = (dB + FAUSTFLOAT(50.0)) * FAUSTFLOAT(0.0075) + FAUSTFLOAT(0.075);
    else if (dB < FAUSTFLOAT(-30.0))
        scale = (dB + FAUSTFLOAT(40.0)) * FAUSTFLOAT(0.015) + FAUSTFLOAT(0.15);
    else if (dB < FAUSTFLOAT(-20.0))
        scale = (dB + FAUSTFLOAT(30.0)) * FAUSTFLOAT(0.02) + FAUSTFLOAT(0.3);
    else if (dB < FAUSTFLOAT(-0.001) || dB > FAUSTFLOAT(0.001))  /* if (dB < 0.0) */
        scale = (dB + FAUSTFLOAT(20.0)) * FAUSTFLOAT(0.025) + FAUSTFLOAT(0.5);
    
    return scale;
}

/*******************************************************************************
 * MetaDataUI : Common class for MetaData handling
 ******************************************************************************/

//============================= BEGIN GROUP LABEL METADATA===========================
// Unlike widget's label, metadata inside group's label are not extracted directly by
// the Faust compiler. Therefore they must be extracted within the architecture file
//-----------------------------------------------------------------------------------

class MetaDataUI {
    
    protected:
        
        std::string                         fGroupTooltip;
        std::map<FAUSTFLOAT*, FAUSTFLOAT>   fGuiSize;            // map widget zone with widget size coef
        std::map<FAUSTFLOAT*, std::string>  fTooltip;            // map widget zone with tooltip strings
        std::map<FAUSTFLOAT*, std::string>  fUnit;               // map widget zone to unit string (i.e. "dB")
        std::map<FAUSTFLOAT*, std::string>  fRadioDescription;   // map zone to {'low':440; ...; 'hi':1000.0}
        std::map<FAUSTFLOAT*, std::string>  fMenuDescription;    // map zone to {'low':440; ...; 'hi':1000.0}
        std::set<FAUSTFLOAT*>               fKnobSet;            // set of widget zone to be knobs
        std::set<FAUSTFLOAT*>               fLedSet;             // set of widget zone to be LEDs
        std::set<FAUSTFLOAT*>               fNumSet;             // set of widget zone to be numerical bargraphs
        std::set<FAUSTFLOAT*>               fLogSet;             // set of widget zone having a log UI scale
        std::set<FAUSTFLOAT*>               fExpSet;             // set of widget zone having an exp UI scale
        std::set<FAUSTFLOAT*>               fHiddenSet;          // set of hidden widget zone
        
        void clearMetadata()
        {
            fGuiSize.clear();
            fTooltip.clear();
            fUnit.clear();
            fRadioDescription.clear();
            fMenuDescription.clear();
            fKnobSet.clear();
            fLedSet.clear();
            fNumSet.clear();
            fLogSet.clear();
            fExpSet.clear();
            fHiddenSet.clear();
        }
        
        /**
         * rmWhiteSpaces(): Remove the leading and trailing white spaces of a string
         * (but not those in the middle of the string)
         */
        static std::string rmWhiteSpaces(const std::string& s)
        {
            size_t i = s.find_first_not_of(" \t");
            size_t j = s.find_last_not_of(" \t");
            if ((i != std::string::npos) && (j != std::string::npos)) {
                return s.substr(i, 1+j-i);
            } else {
                return "";
            }
        }
        
        /**
         * Format tooltip string by replacing some white spaces by
         * return characters so that line width doesn't exceed n.
         * Limitation : long words exceeding n are not cut
         */
        std::string formatTooltip(int n, const std::string& tt)
        {
            std::string ss = tt;  // ss string we are going to format
            int lws = 0;          // last white space encountered
            int lri = 0;          // last return inserted
            for (int i = 0; i < (int)tt.size(); i++) {
                if (tt[i] == ' ') lws = i;
                if (((i-lri) >= n) && (lws > lri)) {
                    // insert return here
                    ss[lws] = '\n';
                    lri = lws;
                }
            }
            return ss;
        }
        
    public:
        
        virtual ~MetaDataUI()
        {}
        
        enum Scale {
            kLin,
            kLog,
            kExp
        };
        
        Scale getScale(FAUSTFLOAT* zone)
        {
            if (fLogSet.count(zone) > 0) return kLog;
            if (fExpSet.count(zone) > 0) return kExp;
            return kLin;
        }
        
        bool isKnob(FAUSTFLOAT* zone)
        {
            return fKnobSet.count(zone) > 0;
        }
        
        bool isRadio(FAUSTFLOAT* zone)
        {
            return fRadioDescription.count(zone) > 0;
        }
        
        bool isMenu(FAUSTFLOAT* zone)
        {
            return fMenuDescription.count(zone) > 0;
        }
        
        bool isLed(FAUSTFLOAT* zone)
        {
            return fLedSet.count(zone) > 0;
        }
        
        bool isNumerical(FAUSTFLOAT* zone)
        {
            return fNumSet.count(zone) > 0;
        }
        
        bool isHidden(FAUSTFLOAT* zone)
        {
            return fHiddenSet.count(zone) > 0;
        }
        
        /**
         * Extracts metadata from a label : 'vol [unit: dB]' -> 'vol' + metadata(unit=dB)
         */
        static void extractMetadata(const std::string& fulllabel, std::string& label, std::map<std::string, std::string>& metadata)
        {
            enum {kLabel, kEscape1, kEscape2, kEscape3, kKey, kValue};
            int state = kLabel; int deep = 0;
            std::string key, value;
            
            for (unsigned int i = 0; i < fulllabel.size(); i++) {
                char c = fulllabel[i];
                switch (state) {
                    case kLabel :
                        assert(deep == 0);
                        switch (c) {
                            case '\\' : state = kEscape1; break;
                            case '[' : state = kKey; deep++; break;
                            default : label += c;
                        }
                        break;
                        
                    case kEscape1:
                        label += c;
                        state = kLabel;
                        break;
                        
                    case kEscape2:
                        key += c;
                        state = kKey;
                        break;
                        
                    case kEscape3:
                        value += c;
                        state = kValue;
                        break;
                        
                    case kKey:
                        assert(deep > 0);
                        switch (c) {
                            case '\\':
                                state = kEscape2;
                                break;
                                
                            case '[':
                                deep++;
                                key += c;
                                break;
                                
                            case ':':
                                if (deep == 1) {
                                    state = kValue;
                                } else {
                                    key += c;
                                }
                                break;
                            case ']':
                                deep--;
                                if (deep < 1) {
                                    metadata[rmWhiteSpaces(key)] = "";
                                    state = kLabel;
                                    key="";
                                    value="";
                                } else {
                                    key += c;
                                }
                                break;
                            default : key += c;
                        }
                        break;
                        
                    case kValue:
                        assert(deep > 0);
                        switch (c) {
                            case '\\':
                                state = kEscape3;
                                break;
                                
                            case '[':
                                deep++;
                                value += c;
                                break;
                                
                            case ']':
                                deep--;
                                if (deep < 1) {
                                    metadata[rmWhiteSpaces(key)] = rmWhiteSpaces(value);
                                    state = kLabel;
                                    key = "";
                                    value = "";
                                } else {
                                    value += c;
                                }
                                break;
                            default : value += c;
                        }
                        break;
                        
                    default:
                        std::cerr << "ERROR unrecognized state " << state << std::endl;
                }
            }
            label = rmWhiteSpaces(label);
        }
        
        /**
         * Analyses the widget zone metadata declarations and takes appropriate actions
         */
        void declare(FAUSTFLOAT* zone, const char* key, const char* value)
        {
            if (zone == 0) {
                // special zone 0 means group metadata
                if (strcmp(key, "tooltip") == 0) {
                    // only group tooltip are currently implemented
                    fGroupTooltip = formatTooltip(30, value);
                } else if (strcmp(key, "hidden") == 0) {
                    fHiddenSet.insert(zone);
                }
            } else {
                if (strcmp(key, "size") == 0) {
                    fGuiSize[zone] = atof(value);
                }
                else if (strcmp(key, "tooltip") == 0) {
                    fTooltip[zone] = formatTooltip(30, value);
                }
                else if (strcmp(key, "unit") == 0) {
                    fUnit[zone] = value;
                }
                else if (strcmp(key, "hidden") == 0) {
                    fHiddenSet.insert(zone);
                }
                else if (strcmp(key, "scale") == 0) {
                    if (strcmp(value, "log") == 0) {
                        fLogSet.insert(zone);
                    } else if (strcmp(value, "exp") == 0) {
                        fExpSet.insert(zone);
                    }
                }
                else if (strcmp(key, "style") == 0) {
                    if (strcmp(value, "knob") == 0) {
                        fKnobSet.insert(zone);
                    } else if (strcmp(value, "led") == 0) {
                        fLedSet.insert(zone);
                    } else if (strcmp(value, "numerical") == 0) {
                        fNumSet.insert(zone);
                    } else {
                        const char* p = value;
                        if (parseWord(p, "radio")) {
                            fRadioDescription[zone] = std::string(p);
                        } else if (parseWord(p, "menu")) {
                            fMenuDescription[zone] = std::string(p);
                        }
                    }
                }
            }
        }
    
};

#endif
/**************************  END  MetaDataUI.h **************************/
/************************** BEGIN midi.h **************************/
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
#include <assert.h>

class MapUI;

/*************************************
 A time-stamped short MIDI message
**************************************/

#pragma pack (push, 1)
struct MIDIMessage
{
    uint32_t frameIndex;
    uint8_t byte0, byte1, byte2;
};
#pragma pack (pop)

/*******************************************************************************
 * MIDI processor definition.
 *
 * MIDI input or output handling classes will implement this interface,
 * so the same method names (keyOn, ctrlChange...) will be used either
 * when decoding MIDI input or encoding MIDI output events.
 *******************************************************************************/

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
    
        virtual void keyPress(double, int channel, int pitch, int press)
        {
            keyPress(channel, pitch, press);
        }
        
        virtual void chanPress(double date, int channel, int press)
        {
            chanPress(channel, press);
        }
    
        virtual void pitchWheel(double, int channel, int wheel)
        {
            pitchWheel(channel, wheel);
        }
           
        virtual void ctrlChange(double, int channel, int ctrl, int value)
        {
            ctrlChange(channel, ctrl, value);
        }
    
        virtual void ctrlChange14bits(double, int channel, int ctrl, int value)
        {
            ctrlChange14bits(channel, ctrl, value);
        }

        virtual void progChange(double, int channel, int pgm)
        {
            progChange(channel, pgm);
        }
    
        virtual void sysEx(double, std::vector<unsigned char>& message)
        {
            sysEx(message);
        }

        // MIDI sync
        virtual void startSync(double date)  {}
        virtual void stopSync(double date)   {}
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
        virtual void sysEx(std::vector<unsigned char>& message)         {}

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
            MIDI_CONT = 0xFB,
            MIDI_STOP = 0xFC,
            MIDI_SYSEX_START = 0xF0,
            MIDI_SYSEX_STOP = 0xF7

        };

        enum MidiCtrl {

            ALL_NOTES_OFF = 123,
            ALL_SOUND_OFF = 120

        };
};

/****************************************************
 * Base class for MIDI input handling.
 *
 * Shared common code used for input handling:
 * - decoding Real-Time messages: handleSync
 * - decoding one data byte messages: handleData1
 * - decoding two data byte messages: handleData2
 * - getting ready messages in polling mode
 ****************************************************/

class midi_handler : public midi {

    protected:

        std::vector<midi*> fMidiInputs;
        std::string fName;
    
        int range(int min, int max, int val) { return (val < min) ? min : ((val >= max) ? max : val); }
  
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

        virtual bool startMidi() { return true; }
        virtual void stopMidi() {}
    
        void setName(const std::string& name) { fName = name; }
        std::string getName() { return fName; }
    
        // To be used in polling mode
        virtual int getMessages(std::vector<MIDIMessage>* message) { return 0; }
    
        void handleSync(double time, int type)
        {
            if (type == MIDI_CLOCK) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->clock(time);
                }
            } else if (type == MIDI_START) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->startSync(time);
                }
            } else if (type == MIDI_STOP) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->stopSync(time);
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
                    fMidiInputs[i]->pitchWheel(time, channel, (data2 << 7) + data1);
                }
            } else if (type == MIDI_POLY_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyPress(time, channel, data1, data2);
                }
            }
        }
    
        void handleMessage(double time, int type, std::vector<unsigned char>& message)
        {
            if (type == MIDI_SYSEX_START) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->sysEx(time, message);
                }
            }
        }

};

//-------------------------------
// For timestamped MIDI messages
//-------------------------------

struct DatedMessage {
    
    double fDate;
    unsigned char fBuffer[3];
    size_t fSize;
    
    DatedMessage(double date, unsigned char* buffer, size_t size)
    :fDate(date), fSize(size)
    {
        assert(size <= 3);
        memcpy(fBuffer, buffer, size);
    }
    
    DatedMessage():fDate(0.0), fSize(0)
    {}
    
};

#endif // __midi__
/**************************  END  midi.h **************************/
/************************** BEGIN ValueConverter.h **************************/
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
/**************************  END  ValueConverter.h **************************/

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
    
    static void analyse(dsp* mono_dsp, bool& midi_sync, int& nvoices)
    {
        JSONUI jsonui;
        mono_dsp->buildUserInterface(&jsonui);
        std::string json = jsonui.JSON();
        midi_sync = ((json.find("midi") != std::string::npos) &&
                     ((json.find("start") != std::string::npos) ||
                      (json.find("stop") != std::string::npos) ||
                      (json.find("clock") != std::string::npos) ||
                      (json.find("timestamp") != std::string::npos)));
    
    #if defined(NVOICES) && NVOICES!=NUM_VOICES
        nvoices = NVOICES;
    #else
        MidiMeta meta;
        mono_dsp->metadata(&meta);
        bool found_voices = false;
        // If "options" metadata is used
        std::string options = meta.get("options", "");
        if (options != "") {
            std::map<std::string, std::string> metadata;
            std::string res;
            MetaDataUI::extractMetadata(options, res, metadata);
            if (metadata.find("nvoices") != metadata.end()) {
                nvoices = std::atoi(metadata["nvoices"].c_str());
                found_voices = true;
            }
        }
        // Otherwise test for "nvoices" metadata
        if (!found_voices) {
            std::string numVoices = meta.get("nvoices", "0");
            nvoices = std::atoi(numVoices.c_str());
        }
        nvoices = std::max<int>(0, nvoices);
    #endif
    }
    
    static bool checkPolyphony(dsp* mono_dsp)
    {
        MapUI map_ui;
        mono_dsp->buildUserInterface(&map_ui);
        bool has_freq = false;
        bool has_gate = false;
        bool has_gain = false;
        for (int i = 0; i < map_ui.getParamsCount(); i++) {
            std::string path = map_ui.getParamAddress(i);
            has_freq |= MapUI::endsWith(path, "/freq");
            has_gate |= MapUI::endsWith(path, "/gate");
            has_gain |= MapUI::endsWith(path, "/gain");
        }
        return (has_freq && has_gate && has_gain);
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

/*****************************************************************************
 * Base class for MIDI aware UI items
 ******************************************************************************/

class uiMidiItem : public uiMidi, public uiItem {
    
    public:
        
        uiMidiItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidi(midi_out, input), uiItem(ui, zone)
        {}
        virtual ~uiMidiItem()
        {}
    
        virtual void reflectZone() {}
    
};

/*****************************************************************************
 * Base class for MIDI aware UI items with timestamp support
 ******************************************************************************/

class uiMidiTimedItem : public uiMidi, public uiTimedItem {
    
    public:
        
        uiMidiTimedItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidi(midi_out, input), uiTimedItem(ui, zone)
        {}
        virtual ~uiMidiTimedItem()
        {}
    
        virtual void reflectZone() {}
    
};

//-------------
// MIDI sync
//-------------

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
                fMidiOut->startSync(0);
            }
        }
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(v));
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
                fMidiOut->stopSync(0);
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(v));
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

//----------------------
// Standard MIDI events
//----------------------

class uiMidiProgChange : public uiMidiTimedItem
{
    
    private:
        
        int fPgm;
  
    public:
    
        uiMidiProgChange(midi* midi_out, int pgm, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fPgm(pgm)
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

class uiMidiChanPress : public uiMidiTimedItem
{
    private:
        
        int fPress;
  
    public:
    
        uiMidiChanPress(midi* midi_out, int press, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fPress(press)
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

class uiMidiCtrlChange : public uiMidiTimedItem
{
    private:
    
        int fCtrl;
        LinearValueConverter fConverter;
 
    public:
    
        uiMidiCtrlChange(midi* midi_out, int ctrl, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fCtrl(ctrl), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiCtrlChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->ctrlChange(0, fCtrl, fConverter.faust2ui(v));
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
 
};

class uiMidiPitchWheel : public uiMidiTimedItem
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
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiPitchWheel()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->pitchWheel(0, bend2wheel(v));
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(wheel2bend(v));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, wheel2bend(v));
            }
        }
 
};

class uiMidiKeyOn : public uiMidiTimedItem
{

    private:
        
        int fKeyOn;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOn(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fKeyOn(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOn()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOn(0, fKeyOn, fConverter.faust2ui(v));
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
};

class uiMidiKeyOff : public uiMidiTimedItem
{

    private:
        
        int fKeyOff;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOff(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fKeyOff(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOff()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOff(0, fKeyOff, fConverter.faust2ui(v));
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
};

class uiMidiKeyPress : public uiMidiTimedItem
{

    private:
    
        int fKey;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyPress(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fKey(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyPress(0, fKey, fConverter.faust2ui(v));
        }
        
        void modifyZone(FAUSTFLOAT v)
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
    
};

class MapUI;

/******************************************************************************************
 * MidiUI : Faust User Interface
 * This class decodes MIDI metadata and maps incoming MIDI messages to them.
 * Currently ctrl, keyon/keyoff, keypress, pgm, chanpress, pitchwheel/pitchbend
 * start/stop/clock meta data are handled.
 *
 * Maps associating MIDI event ID (like each ctrl number) with all MIDI aware UI items
 * are defined and progressively filled when decoding MIDI related metadata.
 * MIDI aware UI items are used in both directions:
 *  - modifying their internal state when receving MIDI input events
 *  - sending their internal state as MIDI output events
 *******************************************************************************************/

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
        bool fTimeStamp;
    
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
                        } else if (fMetaAux[i].second == "pitchwheel" || fMetaAux[i].second == "pitchbend") {
                            fPitchWheelTable.push_back(new uiMidiPitchWheel(fMidiHandler, this, zone, input));
                        // MIDI sync
                        } else if (fMetaAux[i].second == "start") {
                            fStartTable.push_back(new uiMidiStart(fMidiHandler, this, zone, input));
                        } else if (fMetaAux[i].second == "stop") {
                            fStopTable.push_back(new uiMidiStop(fMidiHandler, this, zone, input));
                        } else if (fMetaAux[i].second == "clock") {
                            fClockTable.push_back(new uiMidiClock(fMidiHandler, this, zone, input));
                        // Explicit metadata to activate 'timestamp' mode
                        } else if (fMetaAux[i].second == "timestamp") {
                            fTimeStamp = true;
                        }
                    }
                }
            }
            fMetaAux.clear();
        }

    public:
    
        MidiUI():fMidiHandler(NULL), fDelete(false), fTimeStamp(false)
        {}

        MidiUI(midi_handler* midi_handler, bool delete_handler = false)
        {
            fMidiHandler = midi_handler;
            fMidiHandler->addMidiIn(this);
            fDelete = delete_handler;
            fTimeStamp = false;
        }
 
        virtual ~MidiUI() 
        { 
            fMidiHandler->removeMidiIn(this);
            if (fDelete) delete fMidiHandler;
        }
        
        bool run() { return fMidiHandler->startMidi(); }
        void stop() { fMidiHandler->stopMidi(); }
        
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
                if (fTimeStamp) {
                    for (unsigned int i = 0; i < fKeyOnTable[note].size(); i++) {
                        fKeyOnTable[note][i]->modifyZone(date, FAUSTFLOAT(velocity));
                    }
                } else {
                    for (unsigned int i = 0; i < fKeyOnTable[note].size(); i++) {
                        fKeyOnTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                    }
                }
            }
            // If note is in fKeyTable, handle it as a keyOn
            if (fKeyTable.find(note) != fKeyTable.end()) {
                if (fTimeStamp) {
                    for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                        fKeyTable[note][i]->modifyZone(date, FAUSTFLOAT(velocity));
                    }
                } else {
                    for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                        fKeyTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                    }
                }
            }
            return 0;
        }
        
        void keyOff(double date, int channel, int note, int velocity)
        {
            if (fKeyOffTable.find(note) != fKeyOffTable.end()) {
                if (fTimeStamp) {
                    for (unsigned int i = 0; i < fKeyOffTable[note].size(); i++) {
                        fKeyOffTable[note][i]->modifyZone(date, FAUSTFLOAT(velocity));
                    }
                } else {
                    for (unsigned int i = 0; i < fKeyOffTable[note].size(); i++) {
                        fKeyOffTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                    }
                }
            }
            // If note is in fKeyTable, handle it as a keyOff with a 0 velocity
            if (fKeyTable.find(note) != fKeyTable.end()) {
                if (fTimeStamp) {
                    for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                        fKeyTable[note][i]->modifyZone(date, 0);
                    }
                } else {
                    for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                        fKeyTable[note][i]->modifyZone(0);
                    }
                }
            }
        }
           
        void ctrlChange(double date, int channel, int ctrl, int value)
        {
            if (fCtrlChangeTable.find(ctrl) != fCtrlChangeTable.end()) {
                if (fTimeStamp) {
                    for (unsigned int i = 0; i < fCtrlChangeTable[ctrl].size(); i++) {
                        fCtrlChangeTable[ctrl][i]->modifyZone(date, FAUSTFLOAT(value));
                    }
                } else {
                    for (unsigned int i = 0; i < fCtrlChangeTable[ctrl].size(); i++) {
                        fCtrlChangeTable[ctrl][i]->modifyZone(FAUSTFLOAT(value));
                    }
                }
            }
        }
        
        void progChange(double date, int channel, int pgm)
        {
            if (fProgChangeTable.find(pgm) != fProgChangeTable.end()) {
                if (fTimeStamp) {
                    for (unsigned int i = 0; i < fProgChangeTable[pgm].size(); i++) {
                        fProgChangeTable[pgm][i]->modifyZone(date, FAUSTFLOAT(1));
                    }
                } else {
                    for (unsigned int i = 0; i < fProgChangeTable[pgm].size(); i++) {
                        fProgChangeTable[pgm][i]->modifyZone(FAUSTFLOAT(1));
                    }
                }
            }
        }
        
        void pitchWheel(double date, int channel, int wheel) 
        {
            if (fTimeStamp) {
                for (unsigned int i = 0; i < fPitchWheelTable.size(); i++) {
                    fPitchWheelTable[i]->modifyZone(date, FAUSTFLOAT(wheel));
                }
            } else {
                for (unsigned int i = 0; i < fPitchWheelTable.size(); i++) {
                    fPitchWheelTable[i]->modifyZone(FAUSTFLOAT(wheel));
                }
            }
        }
        
        void keyPress(double date, int channel, int pitch, int press) 
        {
            if (fKeyPressTable.find(pitch) != fKeyPressTable.end()) {
                if (fTimeStamp) {
                    for (unsigned int i = 0; i < fKeyPressTable[pitch].size(); i++) {
                        fKeyPressTable[pitch][i]->modifyZone(date, FAUSTFLOAT(press));
                    }
                } else {
                    for (unsigned int i = 0; i < fKeyPressTable[pitch].size(); i++) {
                        fKeyPressTable[pitch][i]->modifyZone(FAUSTFLOAT(press));
                    }
                }
            }
        }
        
        void chanPress(double date, int channel, int press)
        {
            if (fChanPressTable.find(press) != fChanPressTable.end()) {
                if (fTimeStamp) {
                    for (unsigned int i = 0; i < fChanPressTable[press].size(); i++) {
                        fChanPressTable[press][i]->modifyZone(date, FAUSTFLOAT(1));
                    }
                } else {
                    for (unsigned int i = 0; i < fChanPressTable[press].size(); i++) {
                        fChanPressTable[press][i]->modifyZone(FAUSTFLOAT(1));
                    }
                }
            } 
        }
        
        void ctrlChange14bits(double date, int channel, int ctrl, int value) {}
        
        // MIDI sync
        
        void startSync(double date)
        {
            for (unsigned int i = 0; i < fStartTable.size(); i++) {
                fStartTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
        
        void stopSync(double date)
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
/**************************  END  MidiUI.h **************************/
/************************** BEGIN mspUI.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
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
//
//  mspUI.h for static Max/MSP externals and faustgen~
//
//  Created by Martin Di Rollo on 18/04/12.
//  Copyright (c) 2012-2019 Grame. All rights reserved.
//

#ifndef _mspUI_h
#define _mspUI_h

#include <math.h>
#include <string>
#include <map>


#define STR_SIZE    512
#define MULTI_SIZE  256

#ifdef WIN32
#include <stdio.h>
#define snprintf _snprintf
#ifndef NAN
    static const unsigned long __nan[2] = {0xffffffff, 0x7fffffff};
    #define NAN (*(const float *) __nan)
#endif
#endif

using namespace std;

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

class mspUIObject {
    
    protected:
        
        string fLabel;
        FAUSTFLOAT* fZone;
        
        FAUSTFLOAT range(FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT val) {return (val < min) ? min : (val > max) ? max : val;}
        
    public:
        
        mspUIObject(const string& label, FAUSTFLOAT* zone):fLabel(label),fZone(zone) {}
        virtual ~mspUIObject() {}
        
        virtual void setValue(FAUSTFLOAT f) { *fZone = range(0.0,1.0,f); }
        virtual FAUSTFLOAT getValue() { return *fZone; }
        virtual void toString(char* buffer) {}
        virtual string getName() { return fLabel; }
};

class mspCheckButton : public mspUIObject {
    
    public:
        
        mspCheckButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
        virtual ~mspCheckButton() {}
        
        void toString(char* buffer)
        {
            snprintf(buffer, STR_SIZE, "CheckButton(float): %s", fLabel.c_str());
        }
};

class mspButton : public mspUIObject {
    
    public:
        
        mspButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
        virtual ~mspButton() {}
        
        void toString(char* buffer)
        {
            snprintf(buffer, STR_SIZE, "Button(float): %s", fLabel.c_str());
        }
};

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
        
        void setValue(FAUSTFLOAT f) { *fZone = range(fMin,fMax,f); }
};

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

class mspUI : public UI, public PathBuilder
{
    private:
        
        map<string, mspUIObject*> fUITable1;       // Table using labels
        map<string, mspUIObject*> fUITable2;       // Table using complete path
        map<string, mspUIObject*> fUITable3;       // Table containing bargraph
        
        map<const char*, const char*> fDeclareTable;
        
        FAUSTFLOAT* fMultiTable[MULTI_SIZE];
        int fMultiIndex;
        int fMultiControl;
        
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
        
        void openTabBox(const char* label) { pushLabel(label); fDeclareTable.clear(); }
        void openHorizontalBox(const char* label) { pushLabel(label); fDeclareTable.clear(); }
        void openVerticalBox(const char* label) { pushLabel(label); fDeclareTable.clear(); }
        void closeBox() {popLabel(); fDeclareTable.clear();}
        
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
            for (auto& it : fUITable1) {
                delete it.second;
            }
            
            fUITable1.clear();
            fUITable2.clear();
        }
        
        void displayControls()
        {
            post((char*)"------- Range and path ----------");
            for (auto& it : fUITable2) {
                char param[STR_SIZE];
                it.second->toString(param);
                post(param);
                string path = "Complete path: " + it.first;
                post(path.c_str());
            }
            post((char*)"---------------------------------");
        }
};

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

#endif
/**************************  END  mspUI.h **************************/
/************************** BEGIN poly-dsp.h **************************/
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
#include <assert.h>

/************************** BEGIN proxy-dsp.h **************************/
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


//----------------------------------------------------------------
//  Proxy dsp definition created from the DSP JSON description
//  This class allows a 'proxy' dsp to control a real dsp 
//  possibly running somewhere else.
//----------------------------------------------------------------

class proxy_dsp : public dsp {

    private:
    
        JSONUIDecoder* fDecoder;
        int fSampleRate;
        
    public:
    
        proxy_dsp():fDecoder(nullptr), fSampleRate(-1)
        {}
    
        proxy_dsp(const std::string& json)
        {
            init(json);
        }
    
        void init(const std::string& json)
        {
            fDecoder = new JSONUIDecoder(json);
            fSampleRate = -1;
        }
          
        proxy_dsp(dsp* dsp)
        {
            JSONUI builder(dsp->getNumInputs(), dsp->getNumOutputs());
            dsp->metadata(&builder);
            dsp->buildUserInterface(&builder);
            fSampleRate = dsp->getSampleRate();
            fDecoder = new JSONUIDecoder(builder.JSON());
        }
      
        virtual ~proxy_dsp()
        {
            delete fDecoder;
        }
       
        virtual int getNumInputs() { return fDecoder->fNumInputs; }
        virtual int getNumOutputs() { return fDecoder->fNumOutputs; }
        
        virtual void buildUserInterface(UI* ui) { fDecoder->buildUserInterface(ui); }
        
        // To possibly implement in a concrete proxy dsp 
        virtual void init(int sample_rate)
        {
            instanceInit(sample_rate);
        }
        virtual void instanceInit(int sample_rate)
        {
            instanceConstants(sample_rate);
            instanceResetUserInterface();
            instanceClear();
        }
        virtual void instanceConstants(int sample_rate) { fSampleRate = sample_rate; }
        virtual void instanceResetUserInterface() { fDecoder->resetUserInterface(); }
        virtual void instanceClear() {}
    
        virtual int getSampleRate() { return fSampleRate; }
    
        virtual proxy_dsp* clone() { return new proxy_dsp(fDecoder->fJSON); }
        virtual void metadata(Meta* m) { fDecoder->metadata(m); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {}
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {} 
        
};

#endif
/**************************  END  proxy-dsp.h **************************/
/************************** BEGIN JSONControl.h **************************/
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2019 GRAME, Centre National de Creation Musicale
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

#ifndef __JSON_CONTROL__
#define __JSON_CONTROL__

#include <string>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

struct JSONControl {
    
    virtual std::string getJSON() { return ""; }

    virtual void setParamValue(const std::string& path, FAUSTFLOAT value) {}

    virtual FAUSTFLOAT getParamValue(const std::string& path) { return 0; }
    
};

#endif
/**************************  END  JSONControl.h **************************/

#define kActiveVoice      0
#define kFreeVoice        -1
#define kReleaseVoice     -2
#define kNoVoice          -3

#define VOICE_STOP_LEVEL  0.0005    // -70 db
#define MIX_BUFFER_SIZE   4096

// endsWith(<str>,<end>) : returns true if <str> ends with <end>

static double midiToFreq(double note)
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
            if (!MapUI::endsWith(label, "/gate")
                && !MapUI::endsWith(label, "/freq")
                && !MapUI::endsWith(label, "/gain")) {

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
            pushLabel(label);
        }
        void openHorizontalBox(const char* label)
        {
            pushLabel(label);
        }
        void openVerticalBox(const char* label)
        {
            pushLabel(label);
        }
        void closeBox()
        {
            popLabel();
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

    int fNote;                          // Playing note actual pitch
    int fDate;                          // KeyOn date
    int fRelease;                       // Current number of samples used in release mode to detect end of note
    int fMinRelease;                    // Max of samples used in release mode to detect end of note
    FAUSTFLOAT fLevel;                  // Last audio block level
    std::vector<std::string> fGatePath; // Paths of 'gate' control
    std::vector<std::string> fGainPath; // Paths of 'gain' control
    std::vector<std::string> fFreqPath; // Paths of 'freq' control
 
    dsp_voice(dsp* dsp):decorator_dsp(dsp)
    {
        dsp->buildUserInterface(this);
        fNote = kFreeVoice;
        fLevel = FAUSTFLOAT(0);
        fDate = 0;
        fMinRelease = dsp->getSampleRate()/2; // One 1/2 sec used in release mode to detect end of note
        extractPaths(fGatePath, fFreqPath, fGainPath);
    }
    virtual ~dsp_voice()
    {}

    void extractPaths(std::vector<std::string>& gate, std::vector<std::string>& freq, std::vector<std::string>& gain)
    {
        // Keep gain, freq and gate labels
        std::map<std::string, FAUSTFLOAT*>::iterator it;
        for (it = getMap().begin(); it != getMap().end(); it++) {
            std::string path = (*it).first;
            if (endsWith(path, "/gate")) {
                gate.push_back(path);
            } else if (endsWith(path, "/freq")) {
                freq.push_back(path);
            } else if (endsWith(path, "/gain")) {
                gain.push_back(path);
            }
        }
    }

    // MIDI velocity [0..127]
    void keyOn(int pitch, int velocity, bool trigger)
    {
        keyOn(pitch, float(velocity)/127.f, trigger);
    }

    // Normalized MIDI velocity [0..1]
    void keyOn(int pitch, float velocity, bool trigger)
    {
        for (size_t i = 0; i < fFreqPath.size(); i++) {
            setParamValue(fFreqPath[i], midiToFreq(pitch));
        }
        for (size_t i = 0; i < fGatePath.size(); i++) {
            setParamValue(fGatePath[i], FAUSTFLOAT(1));
        }
        for (size_t i = 0; i < fGainPath.size(); i++) {
            setParamValue(fGainPath[i], velocity);
        }
        
        fNote = pitch;
    }

    void keyOff(bool hard = false)
    {
        // No use of velocity for now...
        for (size_t i = 0; i < fGatePath.size(); i++) {
            setParamValue(fGatePath[i], FAUSTFLOAT(0));
        }
        
        if (hard) {
            // Immediately stop voice
            fNote = kFreeVoice;
        } else {
            // Release voice
            fRelease = fMinRelease;
            fNote = kReleaseVoice;
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
                    snprintf(buffer, 32, ((fVoiceTable.size() < 8) ? "Voice%ld" : "V%ld"), long(i+1));
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
 * Base class for MIDI controllable DSP.
 */

#ifdef EMCC
#endif

class dsp_poly : public decorator_dsp, public midi, public JSONControl {

    protected:
    
    #ifdef EMCC
        MapUI fMapUI;
        std::string fJSON;
    #endif
    
    public:
    
        dsp_poly()
        {}
        dsp_poly(dsp* dsp):decorator_dsp(dsp)
        {
        #ifdef EMCC
            JSONUI jsonui(getNumInputs(), getNumOutputs());
            buildUserInterface(&jsonui);
            fJSON = jsonui.JSON(true);
            buildUserInterface(&fMapUI);
        #endif
        }
    
        virtual ~dsp_poly() {}
    
        // Reimplemented for EMCC
    #ifdef EMCC
        virtual int getNumInputs() { return decorator_dsp::getNumInputs(); }
        virtual int getNumOutputs() { return decorator_dsp::getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { decorator_dsp::buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return decorator_dsp::getSampleRate(); }
        virtual void init(int sample_rate) { decorator_dsp::init(sample_rate); }
        virtual void instanceInit(int sample_rate) { decorator_dsp::instanceInit(sample_rate); }
        virtual void instanceConstants(int sample_rate) { decorator_dsp::instanceConstants(sample_rate); }
        virtual void instanceResetUserInterface() { decorator_dsp::instanceResetUserInterface(); }
        virtual void instanceClear() { decorator_dsp::instanceClear(); }
        virtual dsp_poly* clone() { return new dsp_poly(fDSP->clone()); }
        virtual void metadata(Meta* m) { decorator_dsp::metadata(m); }
    
        // Additional API
        std::string getJSON()
        {
            return fJSON;
        }
    
        virtual void setParamValue(const std::string& path, FAUSTFLOAT value)
        {
            fMapUI.setParamValue(path, value);
            GUI::updateAllGuis();
        }
        
        virtual FAUSTFLOAT getParamValue(const std::string& path) { return fMapUI.getParamValue(path); }

        virtual void computeJS(int count, uintptr_t inputs, uintptr_t outputs)
        {
            decorator_dsp::compute(count, reinterpret_cast<FAUSTFLOAT**>(inputs),reinterpret_cast<FAUSTFLOAT**>(outputs));
        }
    #endif
    
        virtual  MapUI* keyOn(int channel, int pitch, int velocity)
        {
            return midi::keyOn(channel, pitch, velocity);
        }
        virtual  void keyOff(int channel, int pitch, int velocity)
        {
            midi::keyOff(channel, pitch, velocity);
        }
        virtual  void keyPress(int channel, int pitch, int press)
        {
            midi::keyPress(channel, pitch, press);
        }
        virtual void chanPress(int channel, int press)
        {
            midi::chanPress(channel, press);
        }
        virtual void ctrlChange(int channel, int ctrl, int value)
        {
            midi::ctrlChange(channel, ctrl, value);
        }
        virtual void ctrlChange14bits(int channel, int ctrl, int value)
        {
            midi::ctrlChange14bits(channel, ctrl, value);
        }
        virtual void pitchWheel(int channel, int wheel)
        {
            midi::pitchWheel(channel, wheel);
        }
        virtual void progChange(int channel, int pgm)
        {
            midi::progChange(channel, pgm);
        }
    
        // Group API
        virtual void setGroup(bool group) {}
        virtual bool getGroup() { return false; }

};

/**
 * Polyphonic DSP: groups a set of DSP to be played together or triggered by MIDI.
 *
 * All voices are preallocated by cloning the single DSP voice given at creation time.
 * Dynamic voice allocation is done in 'getFreeVoice'
 */

class mydsp_poly : public dsp_voice_group, public dsp_poly {

    private:

        FAUSTFLOAT** fMixBuffer;
        int fDate;

        FAUSTFLOAT mixCheckVoice(int count, FAUSTFLOAT** outputBuffer, FAUSTFLOAT** mixBuffer)
        {
            FAUSTFLOAT level = 0;
            for (int i = 0; i < getNumOutputs(); i++) {
                FAUSTFLOAT* mixChannel = mixBuffer[i];
                FAUSTFLOAT* outChannel = outputBuffer[i];
                for (int j = 0; j < count; j++) {
                    level = std::max<FAUSTFLOAT>(level, (FAUSTFLOAT)fabs(outChannel[j]));
                    mixChannel[j] += outChannel[j];
                }
            }
            return level;
        }
    
        void mixVoice(int count, FAUSTFLOAT** outputBuffer, FAUSTFLOAT** mixBuffer)
        {
            FAUSTFLOAT level = 0;
            for (int i = 0; i < getNumOutputs(); i++) {
                FAUSTFLOAT* mixChannel = mixBuffer[i];
                FAUSTFLOAT* outChannel = outputBuffer[i];
                for (int j = 0; j < count; j++) {
                    mixChannel[j] += outChannel[j];
                }
            }
        }

        void clearOutput(int count, FAUSTFLOAT** mixBuffer)
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                memset(mixBuffer[i], 0, count * sizeof(FAUSTFLOAT));
            }
        }
    
        int getPlayingVoice(int pitch)
        {
            int voice_playing = kNoVoice;
            int oldest_date_playing = INT_MAX;
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == pitch) {
                    // Keeps oldest playing voice
                    if (fVoiceTable[i]->fDate < oldest_date_playing) {
                        oldest_date_playing = fVoiceTable[i]->fDate;
                        voice_playing = int(i);
                    }
                }
            }
            
            return voice_playing;
        }
    
        // Always returns a voice
        int getFreeVoice()
        {
            int voice = kNoVoice;
            
            // Looks for the first available voice
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == kFreeVoice) {
                    voice = int(i);
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
                            voice_release = int(i);
                        }
                    } else {
                        // Otherwise keeps oldest playing voice
                        if (fVoiceTable[i]->fDate < oldest_date_playing) {
                            oldest_date_playing = fVoiceTable[i]->fDate;
                            voice_playing = int(i);
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
            // So that envelop is always re-initialized
            fVoiceTable[voice]->instanceClear();
            fVoiceTable[voice]->fDate = fDate++;
            fVoiceTable[voice]->fNote = kActiveVoice;
            return voice;
        }

        static void panic(FAUSTFLOAT val, void* arg)
        {
            if (val == FAUSTFLOAT(1)) {
                static_cast<mydsp_poly*>(arg)->allNotesOff(true);
            }
        }

        bool checkPolyphony()
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
         * @param nvoices - number of polyphony voices, should be at least 1
         * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
         *                If false all voices are always running.
         * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
         *                a given control on all voices, assuming GUI::updateAllGuis() is called.
         *                If false, all voices can be individually controlled.
         *                setGroup/getGroup methods can be used to set/get the group state.
         *
         */
        mydsp_poly(dsp* dsp,
                   int nvoices,
                   bool control = false,
                   bool group = true)
        : dsp_voice_group(panic, this, control, group), dsp_poly(dsp) // dsp parameter is deallocated by ~dsp_poly
        {
            fDate = 0;

            // Create voices
            assert(nvoices > 0);
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

        void init(int sample_rate)
        {
            decorator_dsp::init(sample_rate);
            fVoiceGroup->init(sample_rate);
            fPanic = FAUSTFLOAT(0);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->init(sample_rate);
            }
        }
    
        void instanceInit(int samplingFreq)
        {
            instanceConstants(samplingFreq);
            instanceResetUserInterface();
            instanceClear();
        }

        void instanceConstants(int sample_rate)
        {
            decorator_dsp::instanceConstants(sample_rate);
            fVoiceGroup->instanceConstants(sample_rate);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceConstants(sample_rate);
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
            assert(count <= MIX_BUFFER_SIZE);

            // First clear the outputs
            clearOutput(count, outputs);

            if (fVoiceControl) {
                // Mix all playing voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    dsp_voice* voice = fVoiceTable[i];
                    if (voice->fNote != kFreeVoice) {
                        voice->compute(count, inputs, fMixBuffer);
                        // Mix it in result
                        voice->fLevel = mixCheckVoice(count, fMixBuffer, outputs);
                        // Check the level to possibly set the voice in kFreeVoice again
                        voice->fRelease -= count;
                        if ((voice->fNote == kReleaseVoice)
                            && (voice->fRelease < 0)
                            && (voice->fLevel < VOICE_STOP_LEVEL)) {
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
    
        // Terminate all active voices, gently or immediately (depending of 'hard' value)
        void allNotesOff(bool hard = false)
        {
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->keyOff(hard);
            }
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
    
        void setGroup(bool group) { fGroupControl = group; }
        bool getGroup() { return fGroupControl; }

        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            if (checkPolyphony()) {
                int voice = getFreeVoice();
                fVoiceTable[voice]->keyOn(pitch, velocity, true);
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

};

/**
 * Polyphonic DSP with an integrated effect. fPolyDSP will respond to MIDI messages.
 */
class dsp_poly_effect : public dsp_poly {
    
    private:
        
        dsp_poly* fPolyDSP;
        
    public:
        
        dsp_poly_effect(dsp_poly* dsp1, dsp* dsp2)
        :dsp_poly(dsp2), fPolyDSP(dsp1)
        {}
        
        virtual ~dsp_poly_effect()
        {
            // dsp_poly_effect is also a decorator_dsp, which will free fPolyDSP
        }
        
        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            return fPolyDSP->keyOn(channel, pitch, velocity);
        }
        void keyOff(int channel, int pitch, int velocity)
        {
            fPolyDSP->keyOff(channel, pitch, velocity);
        }
        void keyPress(int channel, int pitch, int press)
        {
            fPolyDSP->keyPress(channel, pitch, press);
        }
        void chanPress(int channel, int press)
        {
            fPolyDSP->chanPress(channel, press);
        }
        void ctrlChange(int channel, int ctrl, int value)
        {
            fPolyDSP->ctrlChange(channel, ctrl, value);
        }
        void ctrlChange14bits(int channel, int ctrl, int value)
        {
            fPolyDSP->ctrlChange14bits(channel, ctrl, value);
        }
        void pitchWheel(int channel, int wheel)
        {
            fPolyDSP->pitchWheel(channel, wheel);
        }
        void progChange(int channel, int pgm)
        {
            fPolyDSP->progChange(channel, pgm);
        }
        
        // Group API
        void setGroup(bool group)
        {
            fPolyDSP->setGroup(group);
        }
        bool getGroup()
        {
            return fPolyDSP->getGroup();
        }
};

/**
 * Polyphonic DSP factory class. Helper code to support polyphonic DSP source with an integrated effect.
 */

struct dsp_poly_factory : public dsp_factory {
    
    dsp_factory* fProcessFactory;
    dsp_factory* fEffectFactory;
    
    std::string getEffectCode(const std::string& dsp_content)
    {
        std::stringstream effect_code;
        effect_code << "adapt(1,1) = _; adapt(2,2) = _,_; adapt(1,2) = _ <: _,_; adapt(2,1) = _,_ :> _;";
        effect_code << "adaptor(F,G) = adapt(outputs(F),inputs(G)); dsp_code = environment{ " << dsp_content << " };";
        effect_code << "process = adaptor(dsp_code.process, dsp_code.effect) : dsp_code.effect;";
        return effect_code.str();
    }

    dsp_poly_factory(dsp_factory* process_factory = NULL,
                     dsp_factory* effect_factory = NULL):
    fProcessFactory(process_factory)
    ,fEffectFactory(effect_factory)
    {}
    
    virtual ~dsp_poly_factory()
    {}
    
    virtual std::string getName() { return fProcessFactory->getName(); }
    virtual std::string getSHAKey() { return fProcessFactory->getSHAKey(); }
    virtual std::string getDSPCode() { return fProcessFactory->getDSPCode(); }
    virtual std::string getCompileOptions() { return fProcessFactory->getCompileOptions(); }
    virtual std::vector<std::string> getLibraryList() { return fProcessFactory->getLibraryList(); }
    virtual std::vector<std::string> getIncludePathnames() { return fProcessFactory->getIncludePathnames(); }
    
    virtual void setMemoryManager(dsp_memory_manager* manager)
    {
        fProcessFactory->setMemoryManager(manager);
        if (fEffectFactory) {
            fEffectFactory->setMemoryManager(manager);
        }
    }
    virtual dsp_memory_manager* getMemoryManager() { return fProcessFactory->getMemoryManager(); }
    
    /* Create a new polyphonic DSP instance with global effect, to be deleted with C++ 'delete'
     *
     * @param nvoices - number of polyphony voices, should be at least 1
     * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
     *                If false all voices are always running.
     * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
     *                a given control on all voices, assuming GUI::updateAllGuis() is called.
     *                If false, all voices can be individually controlled.
     */
    dsp_poly* createPolyDSPInstance(int nvoices, bool control, bool group)
    {
        dsp_poly* dsp_poly = new mydsp_poly(fProcessFactory->createDSPInstance(), nvoices, control, group);
        if (fEffectFactory) {
            // the 'dsp_poly' object has to be controlled with MIDI, so kept separated from new dsp_sequencer(...) object
            return new dsp_poly_effect(dsp_poly, new dsp_sequencer(dsp_poly, fEffectFactory->createDSPInstance()));
        } else {
            return new dsp_poly_effect(dsp_poly, dsp_poly);
        }
    }
    
    /* Create a new DSP instance, to be deleted with C++ 'delete' */
    dsp* createDSPInstance()
    {
        return fProcessFactory->createDSPInstance();
    }
    
};

#endif // __poly_dsp__
/**************************  END  poly-dsp.h **************************/

std::list<GUI*> GUI::fGuiList;
ztimedmap GUI::gTimedZoneMap;

static const char* getCodeSize()
{
    int tmp;
    return (sizeof(&tmp) == 8) ? "64 bits" : "32 bits";
}

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
#ifdef OSCCTRL
    OSCUI* m_oscInterface;
#endif
} t_faust;

void* faust_class;

void faust_create_jsui(t_faust* x);
void faust_make_json(t_faust* x);

/*--------------------------------------------------------------------------*/
void faust_anything(t_faust* obj, t_symbol* s, short ac, t_atom* av)
{
    if (ac < 0) return;
    
    bool res = false;
    string name = string((s)->s_name);
    
    // If no argument is there, consider it as a toggle message for a button
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
            
            stringstream num_val; num_val << num + i;
            stringstream param_name; param_name << prefix;
            for (int i = 0; i < ndigit - count_digit(num_val.str()); i++) {
                param_name << ' ';
            }
            param_name << num_val.str();
              
            // Try special naming scheme for list of parameters
            res = obj->m_dspUI->setValue(param_name.str(), value);
            
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
        if (!res) {
            post("Unknown parameter : %s", (s)->s_name);
        }
    }
}

/*--------------------------------------------------------------------------*/
void faust_polyphony(t_faust* x, t_symbol* s, short ac, t_atom* av)
{
    if (systhread_mutex_lock(x->m_mutex) == MAX_ERR_NONE) {
    #ifdef MIDICTRL
        mydsp_poly* poly = dynamic_cast<mydsp_poly*>(x->m_dsp);
        if (poly) {
            x->m_midiHandler->removeMidiIn(poly);
        }
    #endif
        // Delete old
        delete x->m_dsp;
        x->m_dspUI->clear();
        mydsp_poly* dsp_poly = NULL;
        // Allocate new one
        if (av[0].a_w.w_long > 0) {
            post("polyphonic DSP voices = %d", av[0].a_w.w_long);
            dsp_poly = new mydsp_poly(new mydsp(), av[0].a_w.w_long, true, true);
        #ifdef POLY2
            x->m_dsp = new dsp_sequencer(dsp_poly, new effect());
        #else
            x->m_dsp = dsp_poly;
        #endif
        } else {
            x->m_dsp = new mydsp();
            post("monophonic DSP");
        }
        // Initialize User Interface (here connnection with controls)
        x->m_dsp->buildUserInterface(x->m_dspUI);
    #ifdef MIDICTRL
        x->m_midiHandler->addMidiIn(dsp_poly);
        x->m_dsp->buildUserInterface(x->m_midiUI);
    #endif
        // Initialize at the system's sampling rate
        x->m_dsp->init(long(sys_getsr()));
        
        // Prepare JSON
        faust_make_json(x);
        
        // Send JSON to JS script
        faust_create_jsui(x);
        
        systhread_mutex_unlock(x->m_mutex);
    } else {
        post("Mutex lock cannot be taken...");
    }
}

/*--------------------------------------------------------------------------*/
#ifdef MIDICTRL
void faust_midievent(t_faust* x, t_symbol* s, short ac, t_atom* av) 
{
    if (ac > 0) {
        int type = (int)av[0].a_w.w_long & 0xf0;
        int channel = (int)av[0].a_w.w_long & 0x0f;
                
        if (ac == 1) {
            x->m_midiHandler->handleSync(0.0, av[0].a_w.w_long);
        } else if (ac == 2) {
            x->m_midiHandler->handleData1(0.0, type, channel, av[1].a_w.w_long);
        } else if (ac == 3) {
            x->m_midiHandler->handleData2(0.0, type, channel, av[1].a_w.w_long, av[2].a_w.w_long);
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
    // SoundUI has to be dispatched on all internal voices
    if (dsp_poly) dsp_poly->setGroup(false);
    x->m_dsp->buildUserInterface(x->m_soundInterface);
    if (dsp_poly) dsp_poly->setGroup(true);
#endif
    
#ifdef OSCCTRL
    x->m_oscInterface = NULL;
#endif
    
    // Send JSON to JS script
    faust_create_jsui(x);
    
    // Display controls
    x->m_dspUI->displayControls();
    return x;
}

#ifdef OSCCTRL
// osc 'IP inport outport xmit bundle'
void faust_osc(t_faust* x, t_symbol* s, short ac, t_atom* av)
{
    if (ac == 5) {
        if (systhread_mutex_lock(x->m_mutex) == MAX_ERR_NONE) {
            
            delete x->m_oscInterface;
            
            const char* argv1[32];
            int argc1 = 0;
            
            argv1[argc1++] = "Faust";
            
            argv1[argc1++]  = "-desthost";
            argv1[argc1++]  = atom_getsym(&av[0])->s_name;
            
            char inport[32];
            snprintf(inport, 32, "%ld", long(av[1].a_w.w_long));
            argv1[argc1++] = "-port";
            argv1[argc1++] = inport;
            
            char outport[32];
            snprintf(outport, 32, "%ld", long(av[2].a_w.w_long));
            argv1[argc1++] = "-outport";
            argv1[argc1++] = outport;
            
            char xmit[32];
            snprintf(xmit, 32, "%ld", long(av[3].a_w.w_long));
            argv1[argc1++] = "-xmit";
            argv1[argc1++] = xmit;
            
            char bundle[32];
            snprintf(bundle, 32, "%ld", long(av[4].a_w.w_long));
            argv1[argc1++] = "-bundle";
            argv1[argc1++] = bundle;
            
            x->m_oscInterface = new OSCUI("Faust", argc1, (char**)argv1);
            x->m_dsp->buildUserInterface(x->m_oscInterface);
            x->m_oscInterface->run();
            
            post(x->m_oscInterface->getInfos().c_str());
            systhread_mutex_unlock(x->m_mutex);
        } else {
            post("Mutex lock cannot be taken...");
        }
    } else {
        post("Should be : osc 'IP inport outport xmit(0|1|2) bundle(0|1)'");
    }
}
#endif

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
#ifdef OSCCTRL
    delete x->m_oscInterface;
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
        #ifdef OSCCTRL
            if (x->m_oscInterface) x->m_oscInterface->endBundle();
        #endif
            faust_update_outputs(x);
        }
    #if defined(MIDICTRL) || defined(OSCCTRL)
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
#ifdef OSCCTRL
    addmess((method)faust_osc, (char*)"osc", A_GIMME, 0);
#endif
#ifdef MIDICTRL
    addmess((method)faust_midievent, (char*)"midievent", A_GIMME, 0);
#endif
    addmess((method)faust_dsp64, (char*)"dsp64", A_CANT, 0);
    addmess((method)faust_dblclick, (char*)"dblclick", A_CANT, 0);
    addmess((method)faust_assist, (char*)"assist", A_CANT, 0);
    addmess((method)faust_mute, (char*)"mute", A_GIMME, 0);
    dsp_initclass();

    post((char*)"Faust DSP object v%s (sample = 64 bits code = %s)", EXTERNAL_VERSION, getCodeSize());
    post((char*)"Copyright (c) 2012-2019 Grame");
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
