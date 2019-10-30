/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit, Henrik Frisk"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMHLS_FullSetup_7h7p_full_6"
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
	double fRec22[3];
	double fRec23[3];
	double fRec24[3];
	double fRec25[3];
	double fRec26[3];
	double fRec27[3];
	double fRec28[3];
	double fRec29[3];
	double fRec30[3];
	double fConst5;
	double fConst6;
	double fConst7;
	double fRec21[2];
	double fRec19[2];
	double fRec18[2];
	double fRec16[2];
	double fConst8;
	double fConst9;
	double fConst10;
	double fRec15[2];
	double fRec13[2];
	double fRec12[2];
	double fRec10[2];
	double fConst11;
	double fConst12;
	double fConst13;
	double fConst14;
	double fConst15;
	double fConst16;
	double fConst17;
	double fConst18;
	double fConst19;
	double fConst20;
	double fConst21;
	double fConst22;
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
	double fRec60[3];
	double fRec61[3];
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
	double fConst23;
	double fConst24;
	double fConst25;
	double fRec71[3];
	double fRec72[3];
	double fRec73[3];
	double fRec74[3];
	double fRec75[3];
	double fRec76[3];
	double fRec77[3];
	double fConst26;
	double fConst27;
	double fRec70[2];
	double fRec68[2];
	double fRec67[2];
	double fRec65[2];
	double fConst28;
	double fRec64[2];
	double fRec62[2];
	double fConst29;
	double fRec84[3];
	double fRec85[3];
	double fRec86[3];
	double fRec87[3];
	double fRec88[3];
	double fConst30;
	double fConst31;
	double fRec83[2];
	double fRec81[2];
	double fRec80[2];
	double fRec78[2];
	double fConst32;
	double fRec92[3];
	double fRec93[3];
	double fRec94[3];
	double fConst33;
	double fRec91[2];
	double fRec89[2];
	double fConst34;
	double fConst35;
	double fConst36;
	double fConst37;
	double fConst38;
	double fConst39;
	double fConst40;
	double fConst41;
	double fConst42;
	double fRec110[3];
	double fRec111[3];
	double fRec112[3];
	double fRec113[3];
	double fRec114[3];
	double fRec115[3];
	double fRec116[3];
	double fRec117[3];
	double fRec118[3];
	double fRec119[3];
	double fRec120[3];
	double fRec109[2];
	double fRec107[2];
	double fRec106[2];
	double fRec104[2];
	double fRec103[2];
	double fRec101[2];
	double fRec100[2];
	double fRec98[2];
	double fConst43;
	double fRec97[2];
	double fRec95[2];
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
	double fVec0[1024];
	int iConst44;
	double fRec141[2];
	double fRec139[2];
	double fRec138[2];
	double fRec136[2];
	double fRec135[2];
	double fRec133[2];
	double fRec132[2];
	double fRec130[2];
	double fRec150[2];
	double fRec148[2];
	double fRec147[2];
	double fRec145[2];
	double fRec144[2];
	double fRec142[2];
	double fRec156[2];
	double fRec154[2];
	double fRec153[2];
	double fRec151[2];
	double fRec159[2];
	double fRec157[2];
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
	double fRec219[2];
	double fRec217[2];
	double fRec216[2];
	double fRec214[2];
	double fRec213[2];
	double fRec211[2];
	double fRec210[2];
	double fRec208[2];
	double fRec228[2];
	double fRec226[2];
	double fRec225[2];
	double fRec223[2];
	double fRec222[2];
	double fRec220[2];
	double fRec234[2];
	double fRec232[2];
	double fRec231[2];
	double fRec229[2];
	double fRec237[2];
	double fRec235[2];
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
	double fRec264[2];
	double fRec262[2];
	double fRec261[2];
	double fRec259[2];
	double fRec258[2];
	double fRec256[2];
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
	double fRec267[2];
	double fRec265[2];
	double fRec297[2];
	double fRec295[2];
	double fRec294[2];
	double fRec292[2];
	double fRec291[2];
	double fRec289[2];
	double fRec288[2];
	double fRec286[2];
	double fRec285[2];
	double fRec283[2];
	double fRec309[2];
	double fRec307[2];
	double fRec306[2];
	double fRec304[2];
	double fRec303[2];
	double fRec301[2];
	double fRec300[2];
	double fRec298[2];
	double fRec312[2];
	double fRec310[2];
	double fRec318[2];
	double fRec316[2];
	double fRec315[2];
	double fRec313[2];
	double fVec3[1024];
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
	double fRec336[2];
	double fRec334[2];
	double fRec342[2];
	double fRec340[2];
	double fRec354[2];
	double fRec352[2];
	double fRec351[2];
	double fRec349[2];
	double fRec348[2];
	double fRec346[2];
	double fRec345[2];
	double fRec343[2];
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
	double fRec366[2];
	double fRec364[2];
	double fVec4[1024];
	double fRec387[2];
	double fRec385[2];
	double fRec384[2];
	double fRec382[2];
	double fRec390[2];
	double fRec388[2];
	double fRec408[2];
	double fRec406[2];
	double fRec405[2];
	double fRec403[2];
	double fRec402[2];
	double fRec400[2];
	double fRec399[2];
	double fRec397[2];
	double fRec396[2];
	double fRec394[2];
	double fRec393[2];
	double fRec391[2];
	double fRec423[2];
	double fRec421[2];
	double fRec420[2];
	double fRec418[2];
	double fRec417[2];
	double fRec415[2];
	double fRec414[2];
	double fRec412[2];
	double fRec411[2];
	double fRec409[2];
	double fRec432[2];
	double fRec430[2];
	double fRec429[2];
	double fRec427[2];
	double fRec426[2];
	double fRec424[2];
	double fRec444[2];
	double fRec442[2];
	double fRec441[2];
	double fRec439[2];
	double fRec438[2];
	double fRec436[2];
	double fRec435[2];
	double fRec433[2];
	double fVec5[1024];
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
	double fRec504[2];
	double fRec502[2];
	double fRec501[2];
	double fRec499[2];
	double fRec507[2];
	double fRec505[2];
	double fVec6[1024];
	double fRec519[2];
	double fRec517[2];
	double fRec516[2];
	double fRec514[2];
	double fRec513[2];
	double fRec511[2];
	double fRec510[2];
	double fRec508[2];
	double fRec528[2];
	double fRec526[2];
	double fRec525[2];
	double fRec523[2];
	double fRec522[2];
	double fRec520[2];
	double fRec534[2];
	double fRec532[2];
	double fRec531[2];
	double fRec529[2];
	double fRec537[2];
	double fRec535[2];
	double fRec552[2];
	double fRec550[2];
	double fRec549[2];
	double fRec547[2];
	double fRec546[2];
	double fRec544[2];
	double fRec543[2];
	double fRec541[2];
	double fRec540[2];
	double fRec538[2];
	double fRec570[2];
	double fRec568[2];
	double fRec567[2];
	double fRec565[2];
	double fRec564[2];
	double fRec562[2];
	double fRec561[2];
	double fRec559[2];
	double fRec558[2];
	double fRec556[2];
	double fRec555[2];
	double fRec553[2];
	double fVec7[1024];
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
	double fRec597[2];
	double fRec595[2];
	double fRec594[2];
	double fRec592[2];
	double fRec591[2];
	double fRec589[2];
	double fRec612[2];
	double fRec610[2];
	double fRec609[2];
	double fRec607[2];
	double fRec606[2];
	double fRec604[2];
	double fRec603[2];
	double fRec601[2];
	double fRec600[2];
	double fRec598[2];
	double fRec624[2];
	double fRec622[2];
	double fRec621[2];
	double fRec619[2];
	double fRec618[2];
	double fRec616[2];
	double fRec615[2];
	double fRec613[2];
	double fRec630[2];
	double fRec628[2];
	double fRec627[2];
	double fRec625[2];
	double fRec633[2];
	double fRec631[2];
	double fVec8[1024];
	double fRec645[2];
	double fRec643[2];
	double fRec642[2];
	double fRec640[2];
	double fRec639[2];
	double fRec637[2];
	double fRec636[2];
	double fRec634[2];
	double fRec648[2];
	double fRec646[2];
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
	double fRec651[2];
	double fRec649[2];
	double fRec681[2];
	double fRec679[2];
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
	double fRec696[2];
	double fRec694[2];
	double fRec693[2];
	double fRec691[2];
	double fRec690[2];
	double fRec688[2];
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
	double fRec753[2];
	double fRec751[2];
	double fRec759[2];
	double fRec757[2];
	double fRec756[2];
	double fRec754[2];
	double fVec10[1024];
	double fRec771[2];
	double fRec769[2];
	double fRec768[2];
	double fRec766[2];
	double fRec765[2];
	double fRec763[2];
	double fRec762[2];
	double fRec760[2];
	double fRec777[2];
	double fRec775[2];
	double fRec774[2];
	double fRec772[2];
	double fRec780[2];
	double fRec778[2];
	double fRec798[2];
	double fRec796[2];
	double fRec795[2];
	double fRec793[2];
	double fRec792[2];
	double fRec790[2];
	double fRec789[2];
	double fRec787[2];
	double fRec786[2];
	double fRec784[2];
	double fRec783[2];
	double fRec781[2];
	double fRec813[2];
	double fRec811[2];
	double fRec810[2];
	double fRec808[2];
	double fRec807[2];
	double fRec805[2];
	double fRec804[2];
	double fRec802[2];
	double fRec801[2];
	double fRec799[2];
	double fRec822[2];
	double fRec820[2];
	double fRec819[2];
	double fRec817[2];
	double fRec816[2];
	double fRec814[2];
	double fVec11[1024];
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
	double fRec840[2];
	double fRec838[2];
	double fRec864[2];
	double fRec862[2];
	double fRec861[2];
	double fRec859[2];
	double fRec858[2];
	double fRec856[2];
	double fRec870[2];
	double fRec868[2];
	double fRec867[2];
	double fRec865[2];
	double fRec873[2];
	double fRec871[2];
	double fRec885[2];
	double fRec883[2];
	double fRec882[2];
	double fRec880[2];
	double fRec879[2];
	double fRec877[2];
	double fRec876[2];
	double fRec874[2];
	double fVec12[1024];
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
	double fRec912[2];
	double fRec910[2];
	double fRec909[2];
	double fRec907[2];
	double fRec906[2];
	double fRec904[2];
	double fRec903[2];
	double fRec901[2];
	double fRec921[2];
	double fRec919[2];
	double fRec918[2];
	double fRec916[2];
	double fRec915[2];
	double fRec913[2];
	double fRec927[2];
	double fRec925[2];
	double fRec924[2];
	double fRec922[2];
	double fRec930[2];
	double fRec928[2];
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
	double fRec933[2];
	double fRec931[2];
	double fVec13[1024];
	double fRec957[2];
	double fRec955[2];
	double fRec954[2];
	double fRec952[2];
	double fRec951[2];
	double fRec949[2];
	double fRec969[2];
	double fRec967[2];
	double fRec966[2];
	double fRec964[2];
	double fRec963[2];
	double fRec961[2];
	double fRec960[2];
	double fRec958[2];
	double fRec987[2];
	double fRec985[2];
	double fRec984[2];
	double fRec982[2];
	double fRec981[2];
	double fRec979[2];
	double fRec978[2];
	double fRec976[2];
	double fRec975[2];
	double fRec973[2];
	double fRec972[2];
	double fRec970[2];
	double fRec1002[2];
	double fRec1000[2];
	double fRec999[2];
	double fRec997[2];
	double fRec996[2];
	double fRec994[2];
	double fRec993[2];
	double fRec991[2];
	double fRec990[2];
	double fRec988[2];
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
	double fRec1071[2];
	double fRec1069[2];
	double fRec1068[2];
	double fRec1066[2];
	double fRec1074[2];
	double fRec1072[2];
	double fVec15[1024];
	double fConst45;
	double fConst46;
	double fConst47;
	double fConst48;
	double fConst49;
	double fConst50;
	double fConst51;
	double fConst52;
	double fConst53;
	double fConst54;
	double fConst55;
	double fConst56;
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
	double fConst63;
	double fConst64;
	double fConst65;
	double fRec1101[2];
	double fRec1099[2];
	double fRec1098[2];
	double fRec1096[2];
	double fConst66;
	double fRec1095[2];
	double fRec1093[2];
	double fConst67;
	double fConst68;
	double fConst69;
	double fConst70;
	double fConst71;
	double fRec1116[2];
	double fRec1114[2];
	double fRec1113[2];
	double fRec1111[2];
	double fConst72;
	double fRec1110[2];
	double fRec1108[2];
	double fConst73;
	double fConst74;
	double fConst75;
	double fRec1122[2];
	double fRec1120[2];
	double fRec1119[2];
	double fRec1117[2];
	double fConst76;
	double fConst77;
	double fRec1125[2];
	double fRec1123[2];
	double fConst78;
	double fConst79;
	double fConst80;
	double fConst81;
	double fConst82;
	double fConst83;
	double fConst84;
	double fConst85;
	double fRec1137[2];
	double fRec1135[2];
	double fRec1134[2];
	double fRec1132[2];
	double fRec1131[2];
	double fRec1129[2];
	double fRec1128[2];
	double fRec1126[2];
	double fVec16[512];
	int iConst86;
	double fRec1143[2];
	double fRec1141[2];
	double fRec1140[2];
	double fRec1138[2];
	double fRec1161[2];
	double fRec1159[2];
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
	double fRec1173[2];
	double fRec1171[2];
	double fRec1170[2];
	double fRec1168[2];
	double fRec1167[2];
	double fRec1165[2];
	double fRec1164[2];
	double fRec1162[2];
	double fRec1182[2];
	double fRec1180[2];
	double fRec1179[2];
	double fRec1177[2];
	double fRec1176[2];
	double fRec1174[2];
	double fRec1185[2];
	double fRec1183[2];
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
	double fRec1248[2];
	double fRec1246[2];
	double fRec1254[2];
	double fRec1252[2];
	double fRec1251[2];
	double fRec1249[2];
	double fRec1263[2];
	double fRec1261[2];
	double fRec1260[2];
	double fRec1258[2];
	double fRec1257[2];
	double fRec1255[2];
	double fVec18[512];
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
	double fVec19[512];
	double fRec1332[2];
	double fRec1330[2];
	double fRec1329[2];
	double fRec1327[2];
	double fRec1335[2];
	double fRec1333[2];
	double fRec1353[2];
	double fRec1351[2];
	double fRec1350[2];
	double fRec1348[2];
	double fRec1347[2];
	double fRec1345[2];
	double fRec1344[2];
	double fRec1342[2];
	double fRec1341[2];
	double fRec1339[2];
	double fRec1338[2];
	double fRec1336[2];
	double fRec1368[2];
	double fRec1366[2];
	double fRec1365[2];
	double fRec1363[2];
	double fRec1362[2];
	double fRec1360[2];
	double fRec1359[2];
	double fRec1357[2];
	double fRec1356[2];
	double fRec1354[2];
	double fRec1380[2];
	double fRec1378[2];
	double fRec1377[2];
	double fRec1375[2];
	double fRec1374[2];
	double fRec1372[2];
	double fRec1371[2];
	double fRec1369[2];
	double fRec1389[2];
	double fRec1387[2];
	double fRec1386[2];
	double fRec1384[2];
	double fRec1383[2];
	double fRec1381[2];
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
	double fRec1449[2];
	double fRec1447[2];
	double fRec1446[2];
	double fRec1444[2];
	double fRec1452[2];
	double fRec1450[2];
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
	double fRec1497[2];
	double fRec1495[2];
	double fRec1494[2];
	double fRec1492[2];
	double fRec1500[2];
	double fRec1498[2];
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
	double fRec1575[2];
	double fRec1573[2];
	double fRec1572[2];
	double fRec1570[2];
	double fRec1578[2];
	double fRec1576[2];
	double fVec23[512];
	double fConst87;
	double fConst88;
	double fConst89;
	double fConst90;
	double fConst91;
	double fConst92;
	double fConst93;
	double fConst94;
	double fRec1590[2];
	double fRec1588[2];
	double fRec1587[2];
	double fRec1585[2];
	double fRec1584[2];
	double fRec1582[2];
	double fRec1581[2];
	double fRec1579[2];
	double fConst95;
	double fConst96;
	double fConst97;
	double fConst98;
	double fConst99;
	double fRec1599[2];
	double fRec1597[2];
	double fRec1596[2];
	double fRec1594[2];
	double fConst100;
	double fRec1593[2];
	double fRec1591[2];
	double fConst101;
	double fConst102;
	double fConst103;
	double fConst104;
	double fConst105;
	double fConst106;
	double fConst107;
	double fConst108;
	double fConst109;
	double fRec1617[2];
	double fRec1615[2];
	double fRec1614[2];
	double fRec1612[2];
	double fConst110;
	double fConst111;
	double fConst112;
	double fRec1611[2];
	double fRec1609[2];
	double fRec1608[2];
	double fRec1606[2];
	double fRec1605[2];
	double fRec1603[2];
	double fRec1602[2];
	double fRec1600[2];
	double fConst113;
	double fConst114;
	double fConst115;
	double fRec1623[2];
	double fRec1621[2];
	double fRec1620[2];
	double fRec1618[2];
	double fConst116;
	double fConst117;
	double fRec1626[2];
	double fRec1624[2];
	double fConst118;
	double fConst119;
	double fConst120;
	double fConst121;
	double fConst122;
	double fConst123;
	double fConst124;
	double fConst125;
	double fConst126;
	double fRec1641[2];
	double fRec1639[2];
	double fRec1638[2];
	double fRec1636[2];
	double fRec1635[2];
	double fRec1633[2];
	double fRec1632[2];
	double fRec1630[2];
	double fConst127;
	double fRec1629[2];
	double fRec1627[2];
	double fVec24[256];
	int iConst128;
	double fRec1644[2];
	double fRec1642[2];
	double fRec1662[2];
	double fRec1660[2];
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
	double fRec1677[2];
	double fRec1675[2];
	double fRec1674[2];
	double fRec1672[2];
	double fRec1671[2];
	double fRec1669[2];
	double fRec1668[2];
	double fRec1666[2];
	double fRec1665[2];
	double fRec1663[2];
	double fRec1686[2];
	double fRec1684[2];
	double fRec1683[2];
	double fRec1681[2];
	double fRec1680[2];
	double fRec1678[2];
	double fRec1692[2];
	double fRec1690[2];
	double fRec1689[2];
	double fRec1687[2];
	double fRec1704[2];
	double fRec1702[2];
	double fRec1701[2];
	double fRec1699[2];
	double fRec1698[2];
	double fRec1696[2];
	double fRec1695[2];
	double fRec1693[2];
	double fVec25[256];
	double fRec1716[2];
	double fRec1714[2];
	double fRec1713[2];
	double fRec1711[2];
	double fRec1710[2];
	double fRec1708[2];
	double fRec1707[2];
	double fRec1705[2];
	double fRec1725[2];
	double fRec1723[2];
	double fRec1722[2];
	double fRec1720[2];
	double fRec1719[2];
	double fRec1717[2];
	double fRec1743[2];
	double fRec1741[2];
	double fRec1740[2];
	double fRec1738[2];
	double fRec1737[2];
	double fRec1735[2];
	double fRec1734[2];
	double fRec1732[2];
	double fRec1731[2];
	double fRec1729[2];
	double fRec1728[2];
	double fRec1726[2];
	double fRec1749[2];
	double fRec1747[2];
	double fRec1746[2];
	double fRec1744[2];
	double fRec1752[2];
	double fRec1750[2];
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
	double fRec1797[2];
	double fRec1795[2];
	double fRec1812[2];
	double fRec1810[2];
	double fRec1809[2];
	double fRec1807[2];
	double fRec1815[2];
	double fRec1813[2];
	double fRec1830[2];
	double fRec1828[2];
	double fRec1827[2];
	double fRec1825[2];
	double fRec1824[2];
	double fRec1822[2];
	double fRec1821[2];
	double fRec1819[2];
	double fRec1818[2];
	double fRec1816[2];
	double fVec27[256];
	double fConst129;
	double fConst130;
	double fConst131;
	double fConst132;
	double fConst133;
	double fConst134;
	double fConst135;
	double fConst136;
	double fConst137;
	double fRec1845[2];
	double fRec1843[2];
	double fRec1842[2];
	double fRec1840[2];
	double fRec1839[2];
	double fRec1837[2];
	double fRec1836[2];
	double fRec1834[2];
	double fConst138;
	double fRec1833[2];
	double fRec1831[2];
	double fConst139;
	double fConst140;
	double fConst141;
	double fConst142;
	double fConst143;
	double fConst144;
	double fConst145;
	double fConst146;
	double fRec1857[2];
	double fRec1855[2];
	double fRec1854[2];
	double fRec1852[2];
	double fRec1851[2];
	double fRec1849[2];
	double fRec1848[2];
	double fRec1846[2];
	double fConst147;
	double fConst148;
	double fRec1860[2];
	double fRec1858[2];
	double fConst149;
	double fConst150;
	double fConst151;
	double fConst152;
	double fConst153;
	double fConst154;
	double fConst155;
	double fConst156;
	double fConst157;
	double fConst158;
	double fConst159;
	double fConst160;
	double fRec1878[2];
	double fRec1876[2];
	double fRec1875[2];
	double fRec1873[2];
	double fRec1872[2];
	double fRec1870[2];
	double fRec1869[2];
	double fRec1867[2];
	double fRec1866[2];
	double fRec1864[2];
	double fRec1863[2];
	double fRec1861[2];
	double fConst161;
	double fConst162;
	double fConst163;
	double fRec1884[2];
	double fRec1882[2];
	double fRec1881[2];
	double fRec1879[2];
	double fConst164;
	double fConst165;
	double fConst166;
	double fConst167;
	double fConst168;
	double fRec1893[2];
	double fRec1891[2];
	double fRec1890[2];
	double fRec1888[2];
	double fConst169;
	double fRec1887[2];
	double fRec1885[2];
	double fRec1902[2];
	double fRec1900[2];
	double fRec1899[2];
	double fRec1897[2];
	double fRec1896[2];
	double fRec1894[2];
	double fRec1914[2];
	double fRec1912[2];
	double fRec1911[2];
	double fRec1909[2];
	double fRec1908[2];
	double fRec1906[2];
	double fRec1905[2];
	double fRec1903[2];
	double fRec1917[2];
	double fRec1915[2];
	double fRec1935[2];
	double fRec1933[2];
	double fRec1932[2];
	double fRec1930[2];
	double fRec1929[2];
	double fRec1927[2];
	double fRec1926[2];
	double fRec1924[2];
	double fRec1923[2];
	double fRec1921[2];
	double fRec1920[2];
	double fRec1918[2];
	double fRec1941[2];
	double fRec1939[2];
	double fRec1938[2];
	double fRec1936[2];
	double fRec1956[2];
	double fRec1954[2];
	double fRec1953[2];
	double fRec1951[2];
	double fRec1950[2];
	double fRec1948[2];
	double fRec1947[2];
	double fRec1945[2];
	double fRec1944[2];
	double fRec1942[2];
	double fVec28[1024];
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
	double fRec1986[2];
	double fRec1984[2];
	double fRec1983[2];
	double fRec1981[2];
	double fRec1980[2];
	double fRec1978[2];
	double fRec1977[2];
	double fRec1975[2];
	double fRec1995[2];
	double fRec1993[2];
	double fRec1992[2];
	double fRec1990[2];
	double fRec1989[2];
	double fRec1987[2];
	double fRec2010[2];
	double fRec2008[2];
	double fRec2007[2];
	double fRec2005[2];
	double fRec2004[2];
	double fRec2002[2];
	double fRec2001[2];
	double fRec1999[2];
	double fRec1998[2];
	double fRec1996[2];
	double fRec2016[2];
	double fRec2014[2];
	double fRec2013[2];
	double fRec2011[2];
	double fRec2019[2];
	double fRec2017[2];
	double fVec29[1024];
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
	double fRec2043[2];
	double fRec2041[2];
	double fRec2040[2];
	double fRec2038[2];
	double fRec2046[2];
	double fRec2044[2];
	double fRec2061[2];
	double fRec2059[2];
	double fRec2058[2];
	double fRec2056[2];
	double fRec2055[2];
	double fRec2053[2];
	double fRec2052[2];
	double fRec2050[2];
	double fRec2049[2];
	double fRec2047[2];
	double fRec2070[2];
	double fRec2068[2];
	double fRec2067[2];
	double fRec2065[2];
	double fRec2064[2];
	double fRec2062[2];
	double fRec2082[2];
	double fRec2080[2];
	double fRec2079[2];
	double fRec2077[2];
	double fRec2076[2];
	double fRec2074[2];
	double fRec2073[2];
	double fRec2071[2];
	double fVec30[1024];
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
	double fRec2100[2];
	double fRec2098[2];
	double fRec2118[2];
	double fRec2116[2];
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
	double fRec2124[2];
	double fRec2122[2];
	double fRec2121[2];
	double fRec2119[2];
	double fRec2136[2];
	double fRec2134[2];
	double fRec2133[2];
	double fRec2131[2];
	double fRec2130[2];
	double fRec2128[2];
	double fRec2127[2];
	double fRec2125[2];
	double fRec2145[2];
	double fRec2143[2];
	double fRec2142[2];
	double fRec2140[2];
	double fRec2139[2];
	double fRec2137[2];
	double fVec31[1024];
	double fRec2154[2];
	double fRec2152[2];
	double fRec2151[2];
	double fRec2149[2];
	double fRec2148[2];
	double fRec2146[2];
	double fRec2160[2];
	double fRec2158[2];
	double fRec2157[2];
	double fRec2155[2];
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
	double fRec2196[2];
	double fRec2194[2];
	double fRec2208[2];
	double fRec2206[2];
	double fRec2205[2];
	double fRec2203[2];
	double fRec2202[2];
	double fRec2200[2];
	double fRec2199[2];
	double fRec2197[2];
	double fVec32[1024];
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
	double fVec33[1024];
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
	double fRec2331[2];
	double fRec2329[2];
	double fRec2328[2];
	double fRec2326[2];
	double fRec2334[2];
	double fRec2332[2];
	double fVec34[1024];
	double fRec2346[2];
	double fRec2344[2];
	double fRec2343[2];
	double fRec2341[2];
	double fRec2340[2];
	double fRec2338[2];
	double fRec2337[2];
	double fRec2335[2];
	double fRec2355[2];
	double fRec2353[2];
	double fRec2352[2];
	double fRec2350[2];
	double fRec2349[2];
	double fRec2347[2];
	double fRec2361[2];
	double fRec2359[2];
	double fRec2358[2];
	double fRec2356[2];
	double fRec2364[2];
	double fRec2362[2];
	double fRec2379[2];
	double fRec2377[2];
	double fRec2376[2];
	double fRec2374[2];
	double fRec2373[2];
	double fRec2371[2];
	double fRec2370[2];
	double fRec2368[2];
	double fRec2367[2];
	double fRec2365[2];
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
	double fRec2382[2];
	double fRec2380[2];
	double fVec35[1024];
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
	double fRec2436[2];
	double fRec2434[2];
	double fRec2433[2];
	double fRec2431[2];
	double fRec2448[2];
	double fRec2446[2];
	double fRec2445[2];
	double fRec2443[2];
	double fRec2442[2];
	double fRec2440[2];
	double fRec2439[2];
	double fRec2437[2];
	double fRec2457[2];
	double fRec2455[2];
	double fRec2454[2];
	double fRec2452[2];
	double fRec2451[2];
	double fRec2449[2];
	double fRec2460[2];
	double fRec2458[2];
	double fVec36[1024];
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
	double fRec2487[2];
	double fRec2485[2];
	double fRec2484[2];
	double fRec2482[2];
	double fRec2481[2];
	double fRec2479[2];
	double fRec2478[2];
	double fRec2476[2];
	double fRec2496[2];
	double fRec2494[2];
	double fRec2493[2];
	double fRec2491[2];
	double fRec2490[2];
	double fRec2488[2];
	double fRec2502[2];
	double fRec2500[2];
	double fRec2499[2];
	double fRec2497[2];
	double fRec2505[2];
	double fRec2503[2];
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
	double fRec2508[2];
	double fRec2506[2];
	double fVec37[1024];
	double fRec2526[2];
	double fRec2524[2];
	double fRec2544[2];
	double fRec2542[2];
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
	double fRec2559[2];
	double fRec2557[2];
	double fRec2556[2];
	double fRec2554[2];
	double fRec2553[2];
	double fRec2551[2];
	double fRec2550[2];
	double fRec2548[2];
	double fRec2547[2];
	double fRec2545[2];
	double fRec2571[2];
	double fRec2569[2];
	double fRec2568[2];
	double fRec2566[2];
	double fRec2565[2];
	double fRec2563[2];
	double fRec2562[2];
	double fRec2560[2];
	double fRec2580[2];
	double fRec2578[2];
	double fRec2577[2];
	double fRec2575[2];
	double fRec2574[2];
	double fRec2572[2];
	double fRec2586[2];
	double fRec2584[2];
	double fRec2583[2];
	double fRec2581[2];
	double fVec38[1024];
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
	double fVec39[1024];
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
	double fRec2673[2];
	double fRec2671[2];
	double fRec2670[2];
	double fRec2668[2];
	double fRec2676[2];
	double fRec2674[2];
	double fRec2691[2];
	double fRec2689[2];
	double fRec2688[2];
	double fRec2686[2];
	double fRec2685[2];
	double fRec2683[2];
	double fRec2682[2];
	double fRec2680[2];
	double fRec2679[2];
	double fRec2677[2];
	double fRec2700[2];
	double fRec2698[2];
	double fRec2697[2];
	double fRec2695[2];
	double fRec2694[2];
	double fRec2692[2];
	double fRec2712[2];
	double fRec2710[2];
	double fRec2709[2];
	double fRec2707[2];
	double fRec2706[2];
	double fRec2704[2];
	double fRec2703[2];
	double fRec2701[2];
	double fVec40[1024];
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
	double fRec2739[2];
	double fRec2737[2];
	double fRec2736[2];
	double fRec2734[2];
	double fRec2733[2];
	double fRec2731[2];
	double fRec2730[2];
	double fRec2728[2];
	double fRec2748[2];
	double fRec2746[2];
	double fRec2745[2];
	double fRec2743[2];
	double fRec2742[2];
	double fRec2740[2];
	double fRec2754[2];
	double fRec2752[2];
	double fRec2751[2];
	double fRec2749[2];
	double fRec2757[2];
	double fRec2755[2];
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
	double fRec2760[2];
	double fRec2758[2];
	double fVec41[1024];
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
	double fVec42[1024];
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
	double fRec2862[2];
	double fRec2860[2];
	double fRec2859[2];
	double fRec2857[2];
	double fRec2856[2];
	double fRec2854[2];
	double fRec2868[2];
	double fRec2866[2];
	double fRec2865[2];
	double fRec2863[2];
	double fRec2871[2];
	double fRec2869[2];
	double fRec2889[2];
	double fRec2887[2];
	double fRec2886[2];
	double fRec2884[2];
	double fRec2883[2];
	double fRec2881[2];
	double fRec2880[2];
	double fRec2878[2];
	double fRec2877[2];
	double fRec2875[2];
	double fRec2874[2];
	double fRec2872[2];
	double fRec2901[2];
	double fRec2899[2];
	double fRec2898[2];
	double fRec2896[2];
	double fRec2895[2];
	double fRec2893[2];
	double fRec2892[2];
	double fRec2890[2];
	double fVec43[1024];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit, Henrik Frisk");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMHLS_FullSetup_7h7p_full_6.dsp");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMHLS_FullSetup_7h7p_full_6");
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
	
	static void classInit(int sample_rate) {
		
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = double(std::min<int>(192000, std::max<int>(1, fSampleRate)));
		fConst1 = (3.1415926535897931 / fConst0);
		fConst2 = (1.0 / ((((15918.663680972788 / fConst0) + 156.62717660663603) / fConst0) + 1.0));
		fConst3 = ((((12665.494141837065 / fConst0) + 215.62295645471744) / fConst0) + 1.0);
		fConst4 = (1.0 / fConst3);
		fConst5 = (1.0 / fConst0);
		fConst6 = (63674.654723891152 / fConst0);
		fConst7 = (fConst6 + 313.25435321327205);
		fConst8 = (1.0 / (fConst0 * fConst3));
		fConst9 = (50661.976567348262 / fConst0);
		fConst10 = (fConst9 + 431.24591290943488);
		fConst11 = ((((26052.757033862956 / fConst0) + 316.29047008051657) / fConst0) + 1.0);
		fConst12 = (1.0 / (fConst0 * fConst11));
		fConst13 = (104211.02813545182 / fConst0);
		fConst14 = (fConst13 + 632.58094016103314);
		fConst15 = ((((28895.790767614679 / fConst0) + 278.12358654414095) / fConst0) + 1.0);
		fConst16 = (1.0 / (fConst0 * fConst15));
		fConst17 = (115583.16307045872 / fConst0);
		fConst18 = (fConst17 + 556.2471730882819);
		fConst19 = (1.0 / ((((36740.52775644674 / fConst0) + 187.31122280418569) / fConst0) + 1.0));
		fConst20 = (146962.11102578696 / fConst0);
		fConst21 = (fConst20 + 374.62244560837138);
		fConst22 = (1.0 / (fConst11 * fConst15));
		fConst23 = (1.0 / ((((8950.8463194903634 / fConst0) + 136.90669911154342) / fConst0) + 1.0));
		fConst24 = ((86.443380725268696 / fConst0) + 1.0);
		fConst25 = (1.0 / fConst24);
		fConst26 = (35803.385277961454 / fConst0);
		fConst27 = (fConst26 + 273.81339822308684);
		fConst28 = (172.88676145053739 / (fConst0 * fConst24));
		fConst29 = (1.0 / ((((4157.1048469258621 / fConst0) + 111.67503991840606) / fConst0) + 1.0));
		fConst30 = (16628.419387703449 / fConst0);
		fConst31 = (fConst30 + 223.35007983681211);
		fConst32 = (1.0 / ((37.225013306135352 / fConst0) + 1.0));
		fConst33 = (74.450026612270705 / fConst0);
		fConst34 = ((((19777.399306469804 / fConst0) + 249.5532431201479) / fConst0) + 1.0);
		fConst35 = (1.0 / (fConst0 * fConst34));
		fConst36 = (79109.597225879217 / fConst0);
		fConst37 = (fConst36 + 499.10648624029579);
		fConst38 = (1.0 / ((((25159.235463955636 / fConst0) + 173.07206373673586) / fConst0) + 1.0));
		fConst39 = (100636.94185582254 / fConst0);
		fConst40 = (fConst39 + 346.14412747347171);
		fConst41 = ((135.74989273514609 / fConst0) + 1.0);
		fConst42 = (1.0 / (fConst41 * fConst34));
		fConst43 = (271.49978547029218 / (fConst0 * fConst41));
		iConst44 = int(((0.0028145653948241961 * fConst0) + 0.5));
		fConst45 = ((((23230.576625123042 / fConst0) + 298.668387355834) / fConst0) + 1.0);
		fConst46 = (1.0 / (fConst0 * fConst45));
		fConst47 = (92922.306500492166 / fConst0);
		fConst48 = (fConst47 + 597.336774711668);
		fConst49 = ((((25765.637037880293 / fConst0) + 262.62796681042397) / fConst0) + 1.0);
		fConst50 = (1.0 / (fConst0 * fConst49));
		fConst51 = (103062.54815152117 / fConst0);
		fConst52 = (fConst51 + 525.25593362084794);
		fConst53 = (1.0 / ((((32760.588224279891 / fConst0) + 176.87520219731587) / fConst0) + 1.0));
		fConst54 = (131042.35289711956 / fConst0);
		fConst55 = (fConst54 + 353.75040439463174);
		fConst56 = (1.0 / (fConst45 * fConst49));
		fConst57 = (1.0 / ((((22433.846310978071 / fConst0) + 163.42937603980999) / fConst0) + 1.0));
		fConst58 = (89735.385243912286 / fConst0);
		fConst59 = (fConst58 + 326.85875207961999);
		fConst60 = ((128.18660497931657 / fConst0) + 1.0);
		fConst61 = ((((17635.000757786547 / fConst0) + 235.6494163834252) / fConst0) + 1.0);
		fConst62 = (1.0 / (fConst60 * fConst61));
		fConst63 = (1.0 / (fConst0 * fConst61));
		fConst64 = (70540.003031146189 / fConst0);
		fConst65 = (fConst64 + 471.29883276685041);
		fConst66 = (256.37320995863314 / (fConst0 * fConst60));
		fConst67 = (1.0 / ((((7981.2405656089695 / fConst0) + 129.27896003773355) / fConst0) + 1.0));
		fConst68 = ((81.627198923287324 / fConst0) + 1.0);
		fConst69 = (1.0 / fConst68);
		fConst70 = (31924.962262435878 / fConst0);
		fConst71 = (fConst70 + 258.55792007546711);
		fConst72 = (163.25439784657465 / (fConst0 * fConst68));
		fConst73 = (1.0 / ((((3706.7839906409508 / fConst0) + 105.45307948051044) / fConst0) + 1.0));
		fConst74 = (14827.135962563803 / fConst0);
		fConst75 = (fConst74 + 210.90615896102088);
		fConst76 = (1.0 / ((35.15102649350348 / fConst0) + 1.0));
		fConst77 = (70.302052987006959 / fConst0);
		fConst78 = ((((11293.496952148356 / fConst0) + 203.6095512610093) / fConst0) + 1.0);
		fConst79 = (1.0 / (fConst0 * fConst78));
		fConst80 = (45173.987808593425 / fConst0);
		fConst81 = (fConst80 + 407.2191025220186);
		fConst82 = (1.0 / ((((14194.264965114509 / fConst0) + 147.90071367402544) / fConst0) + 1.0));
		fConst83 = (56777.059860458037 / fConst0);
		fConst84 = (fConst83 + 295.80142734805088);
		fConst85 = (1.0 / fConst78);
		iConst86 = int(((0.0020220583685382951 * fConst0) + 0.5));
		fConst87 = ((((9521.1776510740765 / fConst0) + 186.95163235964782) / fConst0) + 1.0);
		fConst88 = (1.0 / (fConst0 * fConst87));
		fConst89 = (38084.710604296306 / fConst0);
		fConst90 = (fConst89 + 373.90326471929563);
		fConst91 = (1.0 / ((((11966.720222434136 / fConst0) + 135.80050482538877) / fConst0) + 1.0));
		fConst92 = (47866.880889736545 / fConst0);
		fConst93 = (fConst92 + 271.60100965077754);
		fConst94 = (1.0 / fConst87);
		fConst95 = (1.0 / ((((6728.7226997184644 / fConst0) + 118.70225369648584) / fConst0) + 1.0));
		fConst96 = (26914.890798873857 / fConst0);
		fConst97 = (fConst96 + 237.40450739297168);
		fConst98 = ((74.949028614536147 / fConst0) + 1.0);
		fConst99 = (1.0 / fConst98);
		fConst100 = (149.89805722907229 / (fConst0 * fConst98));
		fConst101 = ((((19584.938830006053 / fConst0) + 274.23341490900532) / fConst0) + 1.0);
		fConst102 = (1.0 / (fConst0 * fConst101));
		fConst103 = (78339.755320024211 / fConst0);
		fConst104 = (fConst103 + 548.46682981801064);
		fConst105 = (1.0 / ((((27619.379697775363 / fConst0) + 162.40450199873914) / fConst0) + 1.0));
		fConst106 = (110477.51879110145 / fConst0);
		fConst107 = (fConst106 + 324.80900399747827);
		fConst108 = ((((21722.165293017177 / fConst0) + 241.14157118083315) / fConst0) + 1.0);
		fConst109 = (1.0 / (fConst101 * fConst108));
		fConst110 = (1.0 / (fConst0 * fConst108));
		fConst111 = (86888.661172068707 / fConst0);
		fConst112 = (fConst111 + 482.28314236166631);
		fConst113 = (1.0 / ((((3125.0682617252614 / fConst0) + 96.825641155510993) / fConst0) + 1.0));
		fConst114 = (12500.273046901046 / fConst0);
		fConst115 = (fConst114 + 193.65128231102199);
		fConst116 = (1.0 / ((32.275213718503664 / fConst0) + 1.0));
		fConst117 = (64.550427437007329 / fConst0);
		fConst118 = ((((14867.491956047414 / fConst0) + 216.37021831556928) / fConst0) + 1.0);
		fConst119 = (1.0 / (fConst0 * fConst118));
		fConst120 = (59469.967824189654 / fConst0);
		fConst121 = (fConst120 + 432.74043663113855);
		fConst122 = (1.0 / ((((18913.241578648733 / fConst0) + 150.05871992220281) / fConst0) + 1.0));
		fConst123 = ((117.6992675397825 / fConst0) + 1.0);
		fConst124 = (1.0 / (fConst123 * fConst118));
		fConst125 = (75652.966314594931 / fConst0);
		fConst126 = (fConst125 + 300.11743984440562);
		fConst127 = (235.39853507956499 / (fConst0 * fConst123));
		iConst128 = int(((0.0007546298522354718 * fConst0) + 0.5));
		fConst129 = ((((13518.406533001747 / fConst0) + 206.32002345478514) / fConst0) + 1.0);
		fConst130 = (1.0 / (fConst0 * fConst129));
		fConst131 = (54073.62613200699 / fConst0);
		fConst132 = (fConst131 + 412.64004690957029);
		fConst133 = (1.0 / ((((17197.042330535627 / fConst0) + 143.0886323217992) / fConst0) + 1.0));
		fConst134 = ((112.2322463251477 / fConst0) + 1.0);
		fConst135 = (1.0 / (fConst134 * fConst129));
		fConst136 = (68788.169322142508 / fConst0);
		fConst137 = (fConst136 + 286.17726464359839);
		fConst138 = (224.4644926502954 / (fConst0 * fConst134));
		fConst139 = ((((8657.2200974217594 / fConst0) + 178.26790338167996) / fConst0) + 1.0);
		fConst140 = (1.0 / (fConst0 * fConst139));
		fConst141 = (34628.880389687038 / fConst0);
		fConst142 = (fConst141 + 356.53580676335991);
		fConst143 = (1.0 / ((((10880.852622069639 / fConst0) + 129.49269801947491) / fConst0) + 1.0));
		fConst144 = (1.0 / fConst139);
		fConst145 = (43523.410488278554 / fConst0);
		fConst146 = (fConst145 + 258.98539603894983);
		fConst147 = (1.0 / ((30.776060140115494 / fConst0) + 1.0));
		fConst148 = (61.552120280230987 / fConst0);
		fConst149 = ((((17807.789357525253 / fConst0) + 261.49552852783023) / fConst0) + 1.0);
		fConst150 = (1.0 / (fConst0 * fConst149));
		fConst151 = (71231.157430101011 / fConst0);
		fConst152 = (fConst151 + 522.99105705566046);
		fConst153 = ((((19751.082568342958 / fConst0) + 229.9407700804322) / fConst0) + 1.0);
		fConst154 = (1.0 / (fConst0 * fConst153));
		fConst155 = (79004.33027337183 / fConst0);
		fConst156 = (fConst155 + 459.8815401608644);
		fConst157 = (1.0 / ((((25113.18008764703 / fConst0) + 154.86096433416358) / fConst0) + 1.0));
		fConst158 = (100452.72035058812 / fConst0);
		fConst159 = (fConst158 + 309.72192866832717);
		fConst160 = (1.0 / (fConst149 * fConst153));
		fConst161 = (1.0 / ((((2841.4976332440169 / fConst0) + 92.328180420346484) / fConst0) + 1.0));
		fConst162 = (11365.990532976068 / fConst0);
		fConst163 = (fConst162 + 184.65636084069297);
		fConst164 = (1.0 / ((((6118.1542368773398 / fConst0) + 113.18864471022512) / fConst0) + 1.0));
		fConst165 = (24472.616947509359 / fConst0);
		fConst166 = (fConst165 + 226.37728942045024);
		fConst167 = ((71.467716130467849 / fConst0) + 1.0);
		fConst168 = (1.0 / fConst167);
		fConst169 = (142.9354322609357 / (fConst0 * fConst167));
		
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
			fRec22[l10] = 0.0;
			
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec23[l11] = 0.0;
			
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec24[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec25[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec26[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec27[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec28[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec29[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec30[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec21[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec19[l20] = 0.0;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec18[l21] = 0.0;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec16[l22] = 0.0;
			
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec15[l23] = 0.0;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec13[l24] = 0.0;
			
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec12[l25] = 0.0;
			
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec10[l26] = 0.0;
			
		}
		for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) {
			fRec49[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 3); l28 = (l28 + 1)) {
			fRec50[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 3); l29 = (l29 + 1)) {
			fRec51[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) {
			fRec52[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) {
			fRec53[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 3); l32 = (l32 + 1)) {
			fRec54[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 3); l33 = (l33 + 1)) {
			fRec55[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec56[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 3); l35 = (l35 + 1)) {
			fRec57[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 3); l36 = (l36 + 1)) {
			fRec58[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 3); l37 = (l37 + 1)) {
			fRec59[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec60[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 3); l39 = (l39 + 1)) {
			fRec61[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec48[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec46[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec45[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec43[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec42[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec40[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec39[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec37[l47] = 0.0;
			
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec36[l48] = 0.0;
			
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec34[l49] = 0.0;
			
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec33[l50] = 0.0;
			
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			fRec31[l51] = 0.0;
			
		}
		for (int l52 = 0; (l52 < 3); l52 = (l52 + 1)) {
			fRec71[l52] = 0.0;
			
		}
		for (int l53 = 0; (l53 < 3); l53 = (l53 + 1)) {
			fRec72[l53] = 0.0;
			
		}
		for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) {
			fRec73[l54] = 0.0;
			
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec74[l55] = 0.0;
			
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec75[l56] = 0.0;
			
		}
		for (int l57 = 0; (l57 < 3); l57 = (l57 + 1)) {
			fRec76[l57] = 0.0;
			
		}
		for (int l58 = 0; (l58 < 3); l58 = (l58 + 1)) {
			fRec77[l58] = 0.0;
			
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec70[l59] = 0.0;
			
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			fRec68[l60] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec67[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec65[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec64[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec62[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 3); l65 = (l65 + 1)) {
			fRec84[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 3); l66 = (l66 + 1)) {
			fRec85[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 3); l67 = (l67 + 1)) {
			fRec86[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 3); l68 = (l68 + 1)) {
			fRec87[l68] = 0.0;
			
		}
		for (int l69 = 0; (l69 < 3); l69 = (l69 + 1)) {
			fRec88[l69] = 0.0;
			
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec83[l70] = 0.0;
			
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			fRec81[l71] = 0.0;
			
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec80[l72] = 0.0;
			
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fRec78[l73] = 0.0;
			
		}
		for (int l74 = 0; (l74 < 3); l74 = (l74 + 1)) {
			fRec92[l74] = 0.0;
			
		}
		for (int l75 = 0; (l75 < 3); l75 = (l75 + 1)) {
			fRec93[l75] = 0.0;
			
		}
		for (int l76 = 0; (l76 < 3); l76 = (l76 + 1)) {
			fRec94[l76] = 0.0;
			
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fRec91[l77] = 0.0;
			
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec89[l78] = 0.0;
			
		}
		for (int l79 = 0; (l79 < 3); l79 = (l79 + 1)) {
			fRec110[l79] = 0.0;
			
		}
		for (int l80 = 0; (l80 < 3); l80 = (l80 + 1)) {
			fRec111[l80] = 0.0;
			
		}
		for (int l81 = 0; (l81 < 3); l81 = (l81 + 1)) {
			fRec112[l81] = 0.0;
			
		}
		for (int l82 = 0; (l82 < 3); l82 = (l82 + 1)) {
			fRec113[l82] = 0.0;
			
		}
		for (int l83 = 0; (l83 < 3); l83 = (l83 + 1)) {
			fRec114[l83] = 0.0;
			
		}
		for (int l84 = 0; (l84 < 3); l84 = (l84 + 1)) {
			fRec115[l84] = 0.0;
			
		}
		for (int l85 = 0; (l85 < 3); l85 = (l85 + 1)) {
			fRec116[l85] = 0.0;
			
		}
		for (int l86 = 0; (l86 < 3); l86 = (l86 + 1)) {
			fRec117[l86] = 0.0;
			
		}
		for (int l87 = 0; (l87 < 3); l87 = (l87 + 1)) {
			fRec118[l87] = 0.0;
			
		}
		for (int l88 = 0; (l88 < 3); l88 = (l88 + 1)) {
			fRec119[l88] = 0.0;
			
		}
		for (int l89 = 0; (l89 < 3); l89 = (l89 + 1)) {
			fRec120[l89] = 0.0;
			
		}
		for (int l90 = 0; (l90 < 2); l90 = (l90 + 1)) {
			fRec109[l90] = 0.0;
			
		}
		for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) {
			fRec107[l91] = 0.0;
			
		}
		for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) {
			fRec106[l92] = 0.0;
			
		}
		for (int l93 = 0; (l93 < 2); l93 = (l93 + 1)) {
			fRec104[l93] = 0.0;
			
		}
		for (int l94 = 0; (l94 < 2); l94 = (l94 + 1)) {
			fRec103[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec101[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fRec100[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec98[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec97[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec95[l99] = 0.0;
			
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
		for (int l109 = 0; (l109 < 1024); l109 = (l109 + 1)) {
			fVec0[l109] = 0.0;
			
		}
		for (int l110 = 0; (l110 < 2); l110 = (l110 + 1)) {
			fRec141[l110] = 0.0;
			
		}
		for (int l111 = 0; (l111 < 2); l111 = (l111 + 1)) {
			fRec139[l111] = 0.0;
			
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
			fRec132[l116] = 0.0;
			
		}
		for (int l117 = 0; (l117 < 2); l117 = (l117 + 1)) {
			fRec130[l117] = 0.0;
			
		}
		for (int l118 = 0; (l118 < 2); l118 = (l118 + 1)) {
			fRec150[l118] = 0.0;
			
		}
		for (int l119 = 0; (l119 < 2); l119 = (l119 + 1)) {
			fRec148[l119] = 0.0;
			
		}
		for (int l120 = 0; (l120 < 2); l120 = (l120 + 1)) {
			fRec147[l120] = 0.0;
			
		}
		for (int l121 = 0; (l121 < 2); l121 = (l121 + 1)) {
			fRec145[l121] = 0.0;
			
		}
		for (int l122 = 0; (l122 < 2); l122 = (l122 + 1)) {
			fRec144[l122] = 0.0;
			
		}
		for (int l123 = 0; (l123 < 2); l123 = (l123 + 1)) {
			fRec142[l123] = 0.0;
			
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
			fRec159[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec157[l129] = 0.0;
			
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
			fRec207[l153] = 0.0;
			
		}
		for (int l154 = 0; (l154 < 2); l154 = (l154 + 1)) {
			fRec205[l154] = 0.0;
			
		}
		for (int l155 = 0; (l155 < 2); l155 = (l155 + 1)) {
			fRec204[l155] = 0.0;
			
		}
		for (int l156 = 0; (l156 < 2); l156 = (l156 + 1)) {
			fRec202[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec201[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec199[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec198[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec196[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec195[l161] = 0.0;
			
		}
		for (int l162 = 0; (l162 < 2); l162 = (l162 + 1)) {
			fRec193[l162] = 0.0;
			
		}
		for (int l163 = 0; (l163 < 2); l163 = (l163 + 1)) {
			fRec219[l163] = 0.0;
			
		}
		for (int l164 = 0; (l164 < 2); l164 = (l164 + 1)) {
			fRec217[l164] = 0.0;
			
		}
		for (int l165 = 0; (l165 < 2); l165 = (l165 + 1)) {
			fRec216[l165] = 0.0;
			
		}
		for (int l166 = 0; (l166 < 2); l166 = (l166 + 1)) {
			fRec214[l166] = 0.0;
			
		}
		for (int l167 = 0; (l167 < 2); l167 = (l167 + 1)) {
			fRec213[l167] = 0.0;
			
		}
		for (int l168 = 0; (l168 < 2); l168 = (l168 + 1)) {
			fRec211[l168] = 0.0;
			
		}
		for (int l169 = 0; (l169 < 2); l169 = (l169 + 1)) {
			fRec210[l169] = 0.0;
			
		}
		for (int l170 = 0; (l170 < 2); l170 = (l170 + 1)) {
			fRec208[l170] = 0.0;
			
		}
		for (int l171 = 0; (l171 < 2); l171 = (l171 + 1)) {
			fRec228[l171] = 0.0;
			
		}
		for (int l172 = 0; (l172 < 2); l172 = (l172 + 1)) {
			fRec226[l172] = 0.0;
			
		}
		for (int l173 = 0; (l173 < 2); l173 = (l173 + 1)) {
			fRec225[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec223[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec222[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec220[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec234[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 2); l178 = (l178 + 1)) {
			fRec232[l178] = 0.0;
			
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec231[l179] = 0.0;
			
		}
		for (int l180 = 0; (l180 < 2); l180 = (l180 + 1)) {
			fRec229[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec237[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec235[l182] = 0.0;
			
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
			fRec264[l196] = 0.0;
			
		}
		for (int l197 = 0; (l197 < 2); l197 = (l197 + 1)) {
			fRec262[l197] = 0.0;
			
		}
		for (int l198 = 0; (l198 < 2); l198 = (l198 + 1)) {
			fRec261[l198] = 0.0;
			
		}
		for (int l199 = 0; (l199 < 2); l199 = (l199 + 1)) {
			fRec259[l199] = 0.0;
			
		}
		for (int l200 = 0; (l200 < 2); l200 = (l200 + 1)) {
			fRec258[l200] = 0.0;
			
		}
		for (int l201 = 0; (l201 < 2); l201 = (l201 + 1)) {
			fRec256[l201] = 0.0;
			
		}
		for (int l202 = 0; (l202 < 2); l202 = (l202 + 1)) {
			fRec282[l202] = 0.0;
			
		}
		for (int l203 = 0; (l203 < 2); l203 = (l203 + 1)) {
			fRec280[l203] = 0.0;
			
		}
		for (int l204 = 0; (l204 < 2); l204 = (l204 + 1)) {
			fRec279[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec277[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec276[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec274[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec273[l208] = 0.0;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec271[l209] = 0.0;
			
		}
		for (int l210 = 0; (l210 < 2); l210 = (l210 + 1)) {
			fRec270[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 2); l211 = (l211 + 1)) {
			fRec268[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec267[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec265[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fRec297[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 2); l215 = (l215 + 1)) {
			fRec295[l215] = 0.0;
			
		}
		for (int l216 = 0; (l216 < 2); l216 = (l216 + 1)) {
			fRec294[l216] = 0.0;
			
		}
		for (int l217 = 0; (l217 < 2); l217 = (l217 + 1)) {
			fRec292[l217] = 0.0;
			
		}
		for (int l218 = 0; (l218 < 2); l218 = (l218 + 1)) {
			fRec291[l218] = 0.0;
			
		}
		for (int l219 = 0; (l219 < 2); l219 = (l219 + 1)) {
			fRec289[l219] = 0.0;
			
		}
		for (int l220 = 0; (l220 < 2); l220 = (l220 + 1)) {
			fRec288[l220] = 0.0;
			
		}
		for (int l221 = 0; (l221 < 2); l221 = (l221 + 1)) {
			fRec286[l221] = 0.0;
			
		}
		for (int l222 = 0; (l222 < 2); l222 = (l222 + 1)) {
			fRec285[l222] = 0.0;
			
		}
		for (int l223 = 0; (l223 < 2); l223 = (l223 + 1)) {
			fRec283[l223] = 0.0;
			
		}
		for (int l224 = 0; (l224 < 2); l224 = (l224 + 1)) {
			fRec309[l224] = 0.0;
			
		}
		for (int l225 = 0; (l225 < 2); l225 = (l225 + 1)) {
			fRec307[l225] = 0.0;
			
		}
		for (int l226 = 0; (l226 < 2); l226 = (l226 + 1)) {
			fRec306[l226] = 0.0;
			
		}
		for (int l227 = 0; (l227 < 2); l227 = (l227 + 1)) {
			fRec304[l227] = 0.0;
			
		}
		for (int l228 = 0; (l228 < 2); l228 = (l228 + 1)) {
			fRec303[l228] = 0.0;
			
		}
		for (int l229 = 0; (l229 < 2); l229 = (l229 + 1)) {
			fRec301[l229] = 0.0;
			
		}
		for (int l230 = 0; (l230 < 2); l230 = (l230 + 1)) {
			fRec300[l230] = 0.0;
			
		}
		for (int l231 = 0; (l231 < 2); l231 = (l231 + 1)) {
			fRec298[l231] = 0.0;
			
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
		for (int l238 = 0; (l238 < 1024); l238 = (l238 + 1)) {
			fVec3[l238] = 0.0;
			
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
		for (int l243 = 0; (l243 < 2); l243 = (l243 + 1)) {
			fRec327[l243] = 0.0;
			
		}
		for (int l244 = 0; (l244 < 2); l244 = (l244 + 1)) {
			fRec325[l244] = 0.0;
			
		}
		for (int l245 = 0; (l245 < 2); l245 = (l245 + 1)) {
			fRec324[l245] = 0.0;
			
		}
		for (int l246 = 0; (l246 < 2); l246 = (l246 + 1)) {
			fRec322[l246] = 0.0;
			
		}
		for (int l247 = 0; (l247 < 2); l247 = (l247 + 1)) {
			fRec321[l247] = 0.0;
			
		}
		for (int l248 = 0; (l248 < 2); l248 = (l248 + 1)) {
			fRec319[l248] = 0.0;
			
		}
		for (int l249 = 0; (l249 < 2); l249 = (l249 + 1)) {
			fRec339[l249] = 0.0;
			
		}
		for (int l250 = 0; (l250 < 2); l250 = (l250 + 1)) {
			fRec337[l250] = 0.0;
			
		}
		for (int l251 = 0; (l251 < 2); l251 = (l251 + 1)) {
			fRec336[l251] = 0.0;
			
		}
		for (int l252 = 0; (l252 < 2); l252 = (l252 + 1)) {
			fRec334[l252] = 0.0;
			
		}
		for (int l253 = 0; (l253 < 2); l253 = (l253 + 1)) {
			fRec342[l253] = 0.0;
			
		}
		for (int l254 = 0; (l254 < 2); l254 = (l254 + 1)) {
			fRec340[l254] = 0.0;
			
		}
		for (int l255 = 0; (l255 < 2); l255 = (l255 + 1)) {
			fRec354[l255] = 0.0;
			
		}
		for (int l256 = 0; (l256 < 2); l256 = (l256 + 1)) {
			fRec352[l256] = 0.0;
			
		}
		for (int l257 = 0; (l257 < 2); l257 = (l257 + 1)) {
			fRec351[l257] = 0.0;
			
		}
		for (int l258 = 0; (l258 < 2); l258 = (l258 + 1)) {
			fRec349[l258] = 0.0;
			
		}
		for (int l259 = 0; (l259 < 2); l259 = (l259 + 1)) {
			fRec348[l259] = 0.0;
			
		}
		for (int l260 = 0; (l260 < 2); l260 = (l260 + 1)) {
			fRec346[l260] = 0.0;
			
		}
		for (int l261 = 0; (l261 < 2); l261 = (l261 + 1)) {
			fRec345[l261] = 0.0;
			
		}
		for (int l262 = 0; (l262 < 2); l262 = (l262 + 1)) {
			fRec343[l262] = 0.0;
			
		}
		for (int l263 = 0; (l263 < 2); l263 = (l263 + 1)) {
			fRec363[l263] = 0.0;
			
		}
		for (int l264 = 0; (l264 < 2); l264 = (l264 + 1)) {
			fRec361[l264] = 0.0;
			
		}
		for (int l265 = 0; (l265 < 2); l265 = (l265 + 1)) {
			fRec360[l265] = 0.0;
			
		}
		for (int l266 = 0; (l266 < 2); l266 = (l266 + 1)) {
			fRec358[l266] = 0.0;
			
		}
		for (int l267 = 0; (l267 < 2); l267 = (l267 + 1)) {
			fRec357[l267] = 0.0;
			
		}
		for (int l268 = 0; (l268 < 2); l268 = (l268 + 1)) {
			fRec355[l268] = 0.0;
			
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
			fRec366[l279] = 0.0;
			
		}
		for (int l280 = 0; (l280 < 2); l280 = (l280 + 1)) {
			fRec364[l280] = 0.0;
			
		}
		for (int l281 = 0; (l281 < 1024); l281 = (l281 + 1)) {
			fVec4[l281] = 0.0;
			
		}
		for (int l282 = 0; (l282 < 2); l282 = (l282 + 1)) {
			fRec387[l282] = 0.0;
			
		}
		for (int l283 = 0; (l283 < 2); l283 = (l283 + 1)) {
			fRec385[l283] = 0.0;
			
		}
		for (int l284 = 0; (l284 < 2); l284 = (l284 + 1)) {
			fRec384[l284] = 0.0;
			
		}
		for (int l285 = 0; (l285 < 2); l285 = (l285 + 1)) {
			fRec382[l285] = 0.0;
			
		}
		for (int l286 = 0; (l286 < 2); l286 = (l286 + 1)) {
			fRec390[l286] = 0.0;
			
		}
		for (int l287 = 0; (l287 < 2); l287 = (l287 + 1)) {
			fRec388[l287] = 0.0;
			
		}
		for (int l288 = 0; (l288 < 2); l288 = (l288 + 1)) {
			fRec408[l288] = 0.0;
			
		}
		for (int l289 = 0; (l289 < 2); l289 = (l289 + 1)) {
			fRec406[l289] = 0.0;
			
		}
		for (int l290 = 0; (l290 < 2); l290 = (l290 + 1)) {
			fRec405[l290] = 0.0;
			
		}
		for (int l291 = 0; (l291 < 2); l291 = (l291 + 1)) {
			fRec403[l291] = 0.0;
			
		}
		for (int l292 = 0; (l292 < 2); l292 = (l292 + 1)) {
			fRec402[l292] = 0.0;
			
		}
		for (int l293 = 0; (l293 < 2); l293 = (l293 + 1)) {
			fRec400[l293] = 0.0;
			
		}
		for (int l294 = 0; (l294 < 2); l294 = (l294 + 1)) {
			fRec399[l294] = 0.0;
			
		}
		for (int l295 = 0; (l295 < 2); l295 = (l295 + 1)) {
			fRec397[l295] = 0.0;
			
		}
		for (int l296 = 0; (l296 < 2); l296 = (l296 + 1)) {
			fRec396[l296] = 0.0;
			
		}
		for (int l297 = 0; (l297 < 2); l297 = (l297 + 1)) {
			fRec394[l297] = 0.0;
			
		}
		for (int l298 = 0; (l298 < 2); l298 = (l298 + 1)) {
			fRec393[l298] = 0.0;
			
		}
		for (int l299 = 0; (l299 < 2); l299 = (l299 + 1)) {
			fRec391[l299] = 0.0;
			
		}
		for (int l300 = 0; (l300 < 2); l300 = (l300 + 1)) {
			fRec423[l300] = 0.0;
			
		}
		for (int l301 = 0; (l301 < 2); l301 = (l301 + 1)) {
			fRec421[l301] = 0.0;
			
		}
		for (int l302 = 0; (l302 < 2); l302 = (l302 + 1)) {
			fRec420[l302] = 0.0;
			
		}
		for (int l303 = 0; (l303 < 2); l303 = (l303 + 1)) {
			fRec418[l303] = 0.0;
			
		}
		for (int l304 = 0; (l304 < 2); l304 = (l304 + 1)) {
			fRec417[l304] = 0.0;
			
		}
		for (int l305 = 0; (l305 < 2); l305 = (l305 + 1)) {
			fRec415[l305] = 0.0;
			
		}
		for (int l306 = 0; (l306 < 2); l306 = (l306 + 1)) {
			fRec414[l306] = 0.0;
			
		}
		for (int l307 = 0; (l307 < 2); l307 = (l307 + 1)) {
			fRec412[l307] = 0.0;
			
		}
		for (int l308 = 0; (l308 < 2); l308 = (l308 + 1)) {
			fRec411[l308] = 0.0;
			
		}
		for (int l309 = 0; (l309 < 2); l309 = (l309 + 1)) {
			fRec409[l309] = 0.0;
			
		}
		for (int l310 = 0; (l310 < 2); l310 = (l310 + 1)) {
			fRec432[l310] = 0.0;
			
		}
		for (int l311 = 0; (l311 < 2); l311 = (l311 + 1)) {
			fRec430[l311] = 0.0;
			
		}
		for (int l312 = 0; (l312 < 2); l312 = (l312 + 1)) {
			fRec429[l312] = 0.0;
			
		}
		for (int l313 = 0; (l313 < 2); l313 = (l313 + 1)) {
			fRec427[l313] = 0.0;
			
		}
		for (int l314 = 0; (l314 < 2); l314 = (l314 + 1)) {
			fRec426[l314] = 0.0;
			
		}
		for (int l315 = 0; (l315 < 2); l315 = (l315 + 1)) {
			fRec424[l315] = 0.0;
			
		}
		for (int l316 = 0; (l316 < 2); l316 = (l316 + 1)) {
			fRec444[l316] = 0.0;
			
		}
		for (int l317 = 0; (l317 < 2); l317 = (l317 + 1)) {
			fRec442[l317] = 0.0;
			
		}
		for (int l318 = 0; (l318 < 2); l318 = (l318 + 1)) {
			fRec441[l318] = 0.0;
			
		}
		for (int l319 = 0; (l319 < 2); l319 = (l319 + 1)) {
			fRec439[l319] = 0.0;
			
		}
		for (int l320 = 0; (l320 < 2); l320 = (l320 + 1)) {
			fRec438[l320] = 0.0;
			
		}
		for (int l321 = 0; (l321 < 2); l321 = (l321 + 1)) {
			fRec436[l321] = 0.0;
			
		}
		for (int l322 = 0; (l322 < 2); l322 = (l322 + 1)) {
			fRec435[l322] = 0.0;
			
		}
		for (int l323 = 0; (l323 < 2); l323 = (l323 + 1)) {
			fRec433[l323] = 0.0;
			
		}
		for (int l324 = 0; (l324 < 1024); l324 = (l324 + 1)) {
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
			fRec504[l361] = 0.0;
			
		}
		for (int l362 = 0; (l362 < 2); l362 = (l362 + 1)) {
			fRec502[l362] = 0.0;
			
		}
		for (int l363 = 0; (l363 < 2); l363 = (l363 + 1)) {
			fRec501[l363] = 0.0;
			
		}
		for (int l364 = 0; (l364 < 2); l364 = (l364 + 1)) {
			fRec499[l364] = 0.0;
			
		}
		for (int l365 = 0; (l365 < 2); l365 = (l365 + 1)) {
			fRec507[l365] = 0.0;
			
		}
		for (int l366 = 0; (l366 < 2); l366 = (l366 + 1)) {
			fRec505[l366] = 0.0;
			
		}
		for (int l367 = 0; (l367 < 1024); l367 = (l367 + 1)) {
			fVec6[l367] = 0.0;
			
		}
		for (int l368 = 0; (l368 < 2); l368 = (l368 + 1)) {
			fRec519[l368] = 0.0;
			
		}
		for (int l369 = 0; (l369 < 2); l369 = (l369 + 1)) {
			fRec517[l369] = 0.0;
			
		}
		for (int l370 = 0; (l370 < 2); l370 = (l370 + 1)) {
			fRec516[l370] = 0.0;
			
		}
		for (int l371 = 0; (l371 < 2); l371 = (l371 + 1)) {
			fRec514[l371] = 0.0;
			
		}
		for (int l372 = 0; (l372 < 2); l372 = (l372 + 1)) {
			fRec513[l372] = 0.0;
			
		}
		for (int l373 = 0; (l373 < 2); l373 = (l373 + 1)) {
			fRec511[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec510[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 2); l375 = (l375 + 1)) {
			fRec508[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec528[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec526[l377] = 0.0;
			
		}
		for (int l378 = 0; (l378 < 2); l378 = (l378 + 1)) {
			fRec525[l378] = 0.0;
			
		}
		for (int l379 = 0; (l379 < 2); l379 = (l379 + 1)) {
			fRec523[l379] = 0.0;
			
		}
		for (int l380 = 0; (l380 < 2); l380 = (l380 + 1)) {
			fRec522[l380] = 0.0;
			
		}
		for (int l381 = 0; (l381 < 2); l381 = (l381 + 1)) {
			fRec520[l381] = 0.0;
			
		}
		for (int l382 = 0; (l382 < 2); l382 = (l382 + 1)) {
			fRec534[l382] = 0.0;
			
		}
		for (int l383 = 0; (l383 < 2); l383 = (l383 + 1)) {
			fRec532[l383] = 0.0;
			
		}
		for (int l384 = 0; (l384 < 2); l384 = (l384 + 1)) {
			fRec531[l384] = 0.0;
			
		}
		for (int l385 = 0; (l385 < 2); l385 = (l385 + 1)) {
			fRec529[l385] = 0.0;
			
		}
		for (int l386 = 0; (l386 < 2); l386 = (l386 + 1)) {
			fRec537[l386] = 0.0;
			
		}
		for (int l387 = 0; (l387 < 2); l387 = (l387 + 1)) {
			fRec535[l387] = 0.0;
			
		}
		for (int l388 = 0; (l388 < 2); l388 = (l388 + 1)) {
			fRec552[l388] = 0.0;
			
		}
		for (int l389 = 0; (l389 < 2); l389 = (l389 + 1)) {
			fRec550[l389] = 0.0;
			
		}
		for (int l390 = 0; (l390 < 2); l390 = (l390 + 1)) {
			fRec549[l390] = 0.0;
			
		}
		for (int l391 = 0; (l391 < 2); l391 = (l391 + 1)) {
			fRec547[l391] = 0.0;
			
		}
		for (int l392 = 0; (l392 < 2); l392 = (l392 + 1)) {
			fRec546[l392] = 0.0;
			
		}
		for (int l393 = 0; (l393 < 2); l393 = (l393 + 1)) {
			fRec544[l393] = 0.0;
			
		}
		for (int l394 = 0; (l394 < 2); l394 = (l394 + 1)) {
			fRec543[l394] = 0.0;
			
		}
		for (int l395 = 0; (l395 < 2); l395 = (l395 + 1)) {
			fRec541[l395] = 0.0;
			
		}
		for (int l396 = 0; (l396 < 2); l396 = (l396 + 1)) {
			fRec540[l396] = 0.0;
			
		}
		for (int l397 = 0; (l397 < 2); l397 = (l397 + 1)) {
			fRec538[l397] = 0.0;
			
		}
		for (int l398 = 0; (l398 < 2); l398 = (l398 + 1)) {
			fRec570[l398] = 0.0;
			
		}
		for (int l399 = 0; (l399 < 2); l399 = (l399 + 1)) {
			fRec568[l399] = 0.0;
			
		}
		for (int l400 = 0; (l400 < 2); l400 = (l400 + 1)) {
			fRec567[l400] = 0.0;
			
		}
		for (int l401 = 0; (l401 < 2); l401 = (l401 + 1)) {
			fRec565[l401] = 0.0;
			
		}
		for (int l402 = 0; (l402 < 2); l402 = (l402 + 1)) {
			fRec564[l402] = 0.0;
			
		}
		for (int l403 = 0; (l403 < 2); l403 = (l403 + 1)) {
			fRec562[l403] = 0.0;
			
		}
		for (int l404 = 0; (l404 < 2); l404 = (l404 + 1)) {
			fRec561[l404] = 0.0;
			
		}
		for (int l405 = 0; (l405 < 2); l405 = (l405 + 1)) {
			fRec559[l405] = 0.0;
			
		}
		for (int l406 = 0; (l406 < 2); l406 = (l406 + 1)) {
			fRec558[l406] = 0.0;
			
		}
		for (int l407 = 0; (l407 < 2); l407 = (l407 + 1)) {
			fRec556[l407] = 0.0;
			
		}
		for (int l408 = 0; (l408 < 2); l408 = (l408 + 1)) {
			fRec555[l408] = 0.0;
			
		}
		for (int l409 = 0; (l409 < 2); l409 = (l409 + 1)) {
			fRec553[l409] = 0.0;
			
		}
		for (int l410 = 0; (l410 < 1024); l410 = (l410 + 1)) {
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
			fRec597[l423] = 0.0;
			
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec595[l424] = 0.0;
			
		}
		for (int l425 = 0; (l425 < 2); l425 = (l425 + 1)) {
			fRec594[l425] = 0.0;
			
		}
		for (int l426 = 0; (l426 < 2); l426 = (l426 + 1)) {
			fRec592[l426] = 0.0;
			
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec591[l427] = 0.0;
			
		}
		for (int l428 = 0; (l428 < 2); l428 = (l428 + 1)) {
			fRec589[l428] = 0.0;
			
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec612[l429] = 0.0;
			
		}
		for (int l430 = 0; (l430 < 2); l430 = (l430 + 1)) {
			fRec610[l430] = 0.0;
			
		}
		for (int l431 = 0; (l431 < 2); l431 = (l431 + 1)) {
			fRec609[l431] = 0.0;
			
		}
		for (int l432 = 0; (l432 < 2); l432 = (l432 + 1)) {
			fRec607[l432] = 0.0;
			
		}
		for (int l433 = 0; (l433 < 2); l433 = (l433 + 1)) {
			fRec606[l433] = 0.0;
			
		}
		for (int l434 = 0; (l434 < 2); l434 = (l434 + 1)) {
			fRec604[l434] = 0.0;
			
		}
		for (int l435 = 0; (l435 < 2); l435 = (l435 + 1)) {
			fRec603[l435] = 0.0;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec601[l436] = 0.0;
			
		}
		for (int l437 = 0; (l437 < 2); l437 = (l437 + 1)) {
			fRec600[l437] = 0.0;
			
		}
		for (int l438 = 0; (l438 < 2); l438 = (l438 + 1)) {
			fRec598[l438] = 0.0;
			
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec624[l439] = 0.0;
			
		}
		for (int l440 = 0; (l440 < 2); l440 = (l440 + 1)) {
			fRec622[l440] = 0.0;
			
		}
		for (int l441 = 0; (l441 < 2); l441 = (l441 + 1)) {
			fRec621[l441] = 0.0;
			
		}
		for (int l442 = 0; (l442 < 2); l442 = (l442 + 1)) {
			fRec619[l442] = 0.0;
			
		}
		for (int l443 = 0; (l443 < 2); l443 = (l443 + 1)) {
			fRec618[l443] = 0.0;
			
		}
		for (int l444 = 0; (l444 < 2); l444 = (l444 + 1)) {
			fRec616[l444] = 0.0;
			
		}
		for (int l445 = 0; (l445 < 2); l445 = (l445 + 1)) {
			fRec615[l445] = 0.0;
			
		}
		for (int l446 = 0; (l446 < 2); l446 = (l446 + 1)) {
			fRec613[l446] = 0.0;
			
		}
		for (int l447 = 0; (l447 < 2); l447 = (l447 + 1)) {
			fRec630[l447] = 0.0;
			
		}
		for (int l448 = 0; (l448 < 2); l448 = (l448 + 1)) {
			fRec628[l448] = 0.0;
			
		}
		for (int l449 = 0; (l449 < 2); l449 = (l449 + 1)) {
			fRec627[l449] = 0.0;
			
		}
		for (int l450 = 0; (l450 < 2); l450 = (l450 + 1)) {
			fRec625[l450] = 0.0;
			
		}
		for (int l451 = 0; (l451 < 2); l451 = (l451 + 1)) {
			fRec633[l451] = 0.0;
			
		}
		for (int l452 = 0; (l452 < 2); l452 = (l452 + 1)) {
			fRec631[l452] = 0.0;
			
		}
		for (int l453 = 0; (l453 < 1024); l453 = (l453 + 1)) {
			fVec8[l453] = 0.0;
			
		}
		for (int l454 = 0; (l454 < 2); l454 = (l454 + 1)) {
			fRec645[l454] = 0.0;
			
		}
		for (int l455 = 0; (l455 < 2); l455 = (l455 + 1)) {
			fRec643[l455] = 0.0;
			
		}
		for (int l456 = 0; (l456 < 2); l456 = (l456 + 1)) {
			fRec642[l456] = 0.0;
			
		}
		for (int l457 = 0; (l457 < 2); l457 = (l457 + 1)) {
			fRec640[l457] = 0.0;
			
		}
		for (int l458 = 0; (l458 < 2); l458 = (l458 + 1)) {
			fRec639[l458] = 0.0;
			
		}
		for (int l459 = 0; (l459 < 2); l459 = (l459 + 1)) {
			fRec637[l459] = 0.0;
			
		}
		for (int l460 = 0; (l460 < 2); l460 = (l460 + 1)) {
			fRec636[l460] = 0.0;
			
		}
		for (int l461 = 0; (l461 < 2); l461 = (l461 + 1)) {
			fRec634[l461] = 0.0;
			
		}
		for (int l462 = 0; (l462 < 2); l462 = (l462 + 1)) {
			fRec648[l462] = 0.0;
			
		}
		for (int l463 = 0; (l463 < 2); l463 = (l463 + 1)) {
			fRec646[l463] = 0.0;
			
		}
		for (int l464 = 0; (l464 < 2); l464 = (l464 + 1)) {
			fRec666[l464] = 0.0;
			
		}
		for (int l465 = 0; (l465 < 2); l465 = (l465 + 1)) {
			fRec664[l465] = 0.0;
			
		}
		for (int l466 = 0; (l466 < 2); l466 = (l466 + 1)) {
			fRec663[l466] = 0.0;
			
		}
		for (int l467 = 0; (l467 < 2); l467 = (l467 + 1)) {
			fRec661[l467] = 0.0;
			
		}
		for (int l468 = 0; (l468 < 2); l468 = (l468 + 1)) {
			fRec660[l468] = 0.0;
			
		}
		for (int l469 = 0; (l469 < 2); l469 = (l469 + 1)) {
			fRec658[l469] = 0.0;
			
		}
		for (int l470 = 0; (l470 < 2); l470 = (l470 + 1)) {
			fRec657[l470] = 0.0;
			
		}
		for (int l471 = 0; (l471 < 2); l471 = (l471 + 1)) {
			fRec655[l471] = 0.0;
			
		}
		for (int l472 = 0; (l472 < 2); l472 = (l472 + 1)) {
			fRec654[l472] = 0.0;
			
		}
		for (int l473 = 0; (l473 < 2); l473 = (l473 + 1)) {
			fRec652[l473] = 0.0;
			
		}
		for (int l474 = 0; (l474 < 2); l474 = (l474 + 1)) {
			fRec651[l474] = 0.0;
			
		}
		for (int l475 = 0; (l475 < 2); l475 = (l475 + 1)) {
			fRec649[l475] = 0.0;
			
		}
		for (int l476 = 0; (l476 < 2); l476 = (l476 + 1)) {
			fRec681[l476] = 0.0;
			
		}
		for (int l477 = 0; (l477 < 2); l477 = (l477 + 1)) {
			fRec679[l477] = 0.0;
			
		}
		for (int l478 = 0; (l478 < 2); l478 = (l478 + 1)) {
			fRec678[l478] = 0.0;
			
		}
		for (int l479 = 0; (l479 < 2); l479 = (l479 + 1)) {
			fRec676[l479] = 0.0;
			
		}
		for (int l480 = 0; (l480 < 2); l480 = (l480 + 1)) {
			fRec675[l480] = 0.0;
			
		}
		for (int l481 = 0; (l481 < 2); l481 = (l481 + 1)) {
			fRec673[l481] = 0.0;
			
		}
		for (int l482 = 0; (l482 < 2); l482 = (l482 + 1)) {
			fRec672[l482] = 0.0;
			
		}
		for (int l483 = 0; (l483 < 2); l483 = (l483 + 1)) {
			fRec670[l483] = 0.0;
			
		}
		for (int l484 = 0; (l484 < 2); l484 = (l484 + 1)) {
			fRec669[l484] = 0.0;
			
		}
		for (int l485 = 0; (l485 < 2); l485 = (l485 + 1)) {
			fRec667[l485] = 0.0;
			
		}
		for (int l486 = 0; (l486 < 2); l486 = (l486 + 1)) {
			fRec687[l486] = 0.0;
			
		}
		for (int l487 = 0; (l487 < 2); l487 = (l487 + 1)) {
			fRec685[l487] = 0.0;
			
		}
		for (int l488 = 0; (l488 < 2); l488 = (l488 + 1)) {
			fRec684[l488] = 0.0;
			
		}
		for (int l489 = 0; (l489 < 2); l489 = (l489 + 1)) {
			fRec682[l489] = 0.0;
			
		}
		for (int l490 = 0; (l490 < 2); l490 = (l490 + 1)) {
			fRec696[l490] = 0.0;
			
		}
		for (int l491 = 0; (l491 < 2); l491 = (l491 + 1)) {
			fRec694[l491] = 0.0;
			
		}
		for (int l492 = 0; (l492 < 2); l492 = (l492 + 1)) {
			fRec693[l492] = 0.0;
			
		}
		for (int l493 = 0; (l493 < 2); l493 = (l493 + 1)) {
			fRec691[l493] = 0.0;
			
		}
		for (int l494 = 0; (l494 < 2); l494 = (l494 + 1)) {
			fRec690[l494] = 0.0;
			
		}
		for (int l495 = 0; (l495 < 2); l495 = (l495 + 1)) {
			fRec688[l495] = 0.0;
			
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
		for (int l539 = 0; (l539 < 1024); l539 = (l539 + 1)) {
			fVec10[l539] = 0.0;
			
		}
		for (int l540 = 0; (l540 < 2); l540 = (l540 + 1)) {
			fRec771[l540] = 0.0;
			
		}
		for (int l541 = 0; (l541 < 2); l541 = (l541 + 1)) {
			fRec769[l541] = 0.0;
			
		}
		for (int l542 = 0; (l542 < 2); l542 = (l542 + 1)) {
			fRec768[l542] = 0.0;
			
		}
		for (int l543 = 0; (l543 < 2); l543 = (l543 + 1)) {
			fRec766[l543] = 0.0;
			
		}
		for (int l544 = 0; (l544 < 2); l544 = (l544 + 1)) {
			fRec765[l544] = 0.0;
			
		}
		for (int l545 = 0; (l545 < 2); l545 = (l545 + 1)) {
			fRec763[l545] = 0.0;
			
		}
		for (int l546 = 0; (l546 < 2); l546 = (l546 + 1)) {
			fRec762[l546] = 0.0;
			
		}
		for (int l547 = 0; (l547 < 2); l547 = (l547 + 1)) {
			fRec760[l547] = 0.0;
			
		}
		for (int l548 = 0; (l548 < 2); l548 = (l548 + 1)) {
			fRec777[l548] = 0.0;
			
		}
		for (int l549 = 0; (l549 < 2); l549 = (l549 + 1)) {
			fRec775[l549] = 0.0;
			
		}
		for (int l550 = 0; (l550 < 2); l550 = (l550 + 1)) {
			fRec774[l550] = 0.0;
			
		}
		for (int l551 = 0; (l551 < 2); l551 = (l551 + 1)) {
			fRec772[l551] = 0.0;
			
		}
		for (int l552 = 0; (l552 < 2); l552 = (l552 + 1)) {
			fRec780[l552] = 0.0;
			
		}
		for (int l553 = 0; (l553 < 2); l553 = (l553 + 1)) {
			fRec778[l553] = 0.0;
			
		}
		for (int l554 = 0; (l554 < 2); l554 = (l554 + 1)) {
			fRec798[l554] = 0.0;
			
		}
		for (int l555 = 0; (l555 < 2); l555 = (l555 + 1)) {
			fRec796[l555] = 0.0;
			
		}
		for (int l556 = 0; (l556 < 2); l556 = (l556 + 1)) {
			fRec795[l556] = 0.0;
			
		}
		for (int l557 = 0; (l557 < 2); l557 = (l557 + 1)) {
			fRec793[l557] = 0.0;
			
		}
		for (int l558 = 0; (l558 < 2); l558 = (l558 + 1)) {
			fRec792[l558] = 0.0;
			
		}
		for (int l559 = 0; (l559 < 2); l559 = (l559 + 1)) {
			fRec790[l559] = 0.0;
			
		}
		for (int l560 = 0; (l560 < 2); l560 = (l560 + 1)) {
			fRec789[l560] = 0.0;
			
		}
		for (int l561 = 0; (l561 < 2); l561 = (l561 + 1)) {
			fRec787[l561] = 0.0;
			
		}
		for (int l562 = 0; (l562 < 2); l562 = (l562 + 1)) {
			fRec786[l562] = 0.0;
			
		}
		for (int l563 = 0; (l563 < 2); l563 = (l563 + 1)) {
			fRec784[l563] = 0.0;
			
		}
		for (int l564 = 0; (l564 < 2); l564 = (l564 + 1)) {
			fRec783[l564] = 0.0;
			
		}
		for (int l565 = 0; (l565 < 2); l565 = (l565 + 1)) {
			fRec781[l565] = 0.0;
			
		}
		for (int l566 = 0; (l566 < 2); l566 = (l566 + 1)) {
			fRec813[l566] = 0.0;
			
		}
		for (int l567 = 0; (l567 < 2); l567 = (l567 + 1)) {
			fRec811[l567] = 0.0;
			
		}
		for (int l568 = 0; (l568 < 2); l568 = (l568 + 1)) {
			fRec810[l568] = 0.0;
			
		}
		for (int l569 = 0; (l569 < 2); l569 = (l569 + 1)) {
			fRec808[l569] = 0.0;
			
		}
		for (int l570 = 0; (l570 < 2); l570 = (l570 + 1)) {
			fRec807[l570] = 0.0;
			
		}
		for (int l571 = 0; (l571 < 2); l571 = (l571 + 1)) {
			fRec805[l571] = 0.0;
			
		}
		for (int l572 = 0; (l572 < 2); l572 = (l572 + 1)) {
			fRec804[l572] = 0.0;
			
		}
		for (int l573 = 0; (l573 < 2); l573 = (l573 + 1)) {
			fRec802[l573] = 0.0;
			
		}
		for (int l574 = 0; (l574 < 2); l574 = (l574 + 1)) {
			fRec801[l574] = 0.0;
			
		}
		for (int l575 = 0; (l575 < 2); l575 = (l575 + 1)) {
			fRec799[l575] = 0.0;
			
		}
		for (int l576 = 0; (l576 < 2); l576 = (l576 + 1)) {
			fRec822[l576] = 0.0;
			
		}
		for (int l577 = 0; (l577 < 2); l577 = (l577 + 1)) {
			fRec820[l577] = 0.0;
			
		}
		for (int l578 = 0; (l578 < 2); l578 = (l578 + 1)) {
			fRec819[l578] = 0.0;
			
		}
		for (int l579 = 0; (l579 < 2); l579 = (l579 + 1)) {
			fRec817[l579] = 0.0;
			
		}
		for (int l580 = 0; (l580 < 2); l580 = (l580 + 1)) {
			fRec816[l580] = 0.0;
			
		}
		for (int l581 = 0; (l581 < 2); l581 = (l581 + 1)) {
			fRec814[l581] = 0.0;
			
		}
		for (int l582 = 0; (l582 < 1024); l582 = (l582 + 1)) {
			fVec11[l582] = 0.0;
			
		}
		for (int l583 = 0; (l583 < 2); l583 = (l583 + 1)) {
			fRec837[l583] = 0.0;
			
		}
		for (int l584 = 0; (l584 < 2); l584 = (l584 + 1)) {
			fRec835[l584] = 0.0;
			
		}
		for (int l585 = 0; (l585 < 2); l585 = (l585 + 1)) {
			fRec834[l585] = 0.0;
			
		}
		for (int l586 = 0; (l586 < 2); l586 = (l586 + 1)) {
			fRec832[l586] = 0.0;
			
		}
		for (int l587 = 0; (l587 < 2); l587 = (l587 + 1)) {
			fRec831[l587] = 0.0;
			
		}
		for (int l588 = 0; (l588 < 2); l588 = (l588 + 1)) {
			fRec829[l588] = 0.0;
			
		}
		for (int l589 = 0; (l589 < 2); l589 = (l589 + 1)) {
			fRec828[l589] = 0.0;
			
		}
		for (int l590 = 0; (l590 < 2); l590 = (l590 + 1)) {
			fRec826[l590] = 0.0;
			
		}
		for (int l591 = 0; (l591 < 2); l591 = (l591 + 1)) {
			fRec825[l591] = 0.0;
			
		}
		for (int l592 = 0; (l592 < 2); l592 = (l592 + 1)) {
			fRec823[l592] = 0.0;
			
		}
		for (int l593 = 0; (l593 < 2); l593 = (l593 + 1)) {
			fRec855[l593] = 0.0;
			
		}
		for (int l594 = 0; (l594 < 2); l594 = (l594 + 1)) {
			fRec853[l594] = 0.0;
			
		}
		for (int l595 = 0; (l595 < 2); l595 = (l595 + 1)) {
			fRec852[l595] = 0.0;
			
		}
		for (int l596 = 0; (l596 < 2); l596 = (l596 + 1)) {
			fRec850[l596] = 0.0;
			
		}
		for (int l597 = 0; (l597 < 2); l597 = (l597 + 1)) {
			fRec849[l597] = 0.0;
			
		}
		for (int l598 = 0; (l598 < 2); l598 = (l598 + 1)) {
			fRec847[l598] = 0.0;
			
		}
		for (int l599 = 0; (l599 < 2); l599 = (l599 + 1)) {
			fRec846[l599] = 0.0;
			
		}
		for (int l600 = 0; (l600 < 2); l600 = (l600 + 1)) {
			fRec844[l600] = 0.0;
			
		}
		for (int l601 = 0; (l601 < 2); l601 = (l601 + 1)) {
			fRec843[l601] = 0.0;
			
		}
		for (int l602 = 0; (l602 < 2); l602 = (l602 + 1)) {
			fRec841[l602] = 0.0;
			
		}
		for (int l603 = 0; (l603 < 2); l603 = (l603 + 1)) {
			fRec840[l603] = 0.0;
			
		}
		for (int l604 = 0; (l604 < 2); l604 = (l604 + 1)) {
			fRec838[l604] = 0.0;
			
		}
		for (int l605 = 0; (l605 < 2); l605 = (l605 + 1)) {
			fRec864[l605] = 0.0;
			
		}
		for (int l606 = 0; (l606 < 2); l606 = (l606 + 1)) {
			fRec862[l606] = 0.0;
			
		}
		for (int l607 = 0; (l607 < 2); l607 = (l607 + 1)) {
			fRec861[l607] = 0.0;
			
		}
		for (int l608 = 0; (l608 < 2); l608 = (l608 + 1)) {
			fRec859[l608] = 0.0;
			
		}
		for (int l609 = 0; (l609 < 2); l609 = (l609 + 1)) {
			fRec858[l609] = 0.0;
			
		}
		for (int l610 = 0; (l610 < 2); l610 = (l610 + 1)) {
			fRec856[l610] = 0.0;
			
		}
		for (int l611 = 0; (l611 < 2); l611 = (l611 + 1)) {
			fRec870[l611] = 0.0;
			
		}
		for (int l612 = 0; (l612 < 2); l612 = (l612 + 1)) {
			fRec868[l612] = 0.0;
			
		}
		for (int l613 = 0; (l613 < 2); l613 = (l613 + 1)) {
			fRec867[l613] = 0.0;
			
		}
		for (int l614 = 0; (l614 < 2); l614 = (l614 + 1)) {
			fRec865[l614] = 0.0;
			
		}
		for (int l615 = 0; (l615 < 2); l615 = (l615 + 1)) {
			fRec873[l615] = 0.0;
			
		}
		for (int l616 = 0; (l616 < 2); l616 = (l616 + 1)) {
			fRec871[l616] = 0.0;
			
		}
		for (int l617 = 0; (l617 < 2); l617 = (l617 + 1)) {
			fRec885[l617] = 0.0;
			
		}
		for (int l618 = 0; (l618 < 2); l618 = (l618 + 1)) {
			fRec883[l618] = 0.0;
			
		}
		for (int l619 = 0; (l619 < 2); l619 = (l619 + 1)) {
			fRec882[l619] = 0.0;
			
		}
		for (int l620 = 0; (l620 < 2); l620 = (l620 + 1)) {
			fRec880[l620] = 0.0;
			
		}
		for (int l621 = 0; (l621 < 2); l621 = (l621 + 1)) {
			fRec879[l621] = 0.0;
			
		}
		for (int l622 = 0; (l622 < 2); l622 = (l622 + 1)) {
			fRec877[l622] = 0.0;
			
		}
		for (int l623 = 0; (l623 < 2); l623 = (l623 + 1)) {
			fRec876[l623] = 0.0;
			
		}
		for (int l624 = 0; (l624 < 2); l624 = (l624 + 1)) {
			fRec874[l624] = 0.0;
			
		}
		for (int l625 = 0; (l625 < 1024); l625 = (l625 + 1)) {
			fVec12[l625] = 0.0;
			
		}
		for (int l626 = 0; (l626 < 2); l626 = (l626 + 1)) {
			fRec900[l626] = 0.0;
			
		}
		for (int l627 = 0; (l627 < 2); l627 = (l627 + 1)) {
			fRec898[l627] = 0.0;
			
		}
		for (int l628 = 0; (l628 < 2); l628 = (l628 + 1)) {
			fRec897[l628] = 0.0;
			
		}
		for (int l629 = 0; (l629 < 2); l629 = (l629 + 1)) {
			fRec895[l629] = 0.0;
			
		}
		for (int l630 = 0; (l630 < 2); l630 = (l630 + 1)) {
			fRec894[l630] = 0.0;
			
		}
		for (int l631 = 0; (l631 < 2); l631 = (l631 + 1)) {
			fRec892[l631] = 0.0;
			
		}
		for (int l632 = 0; (l632 < 2); l632 = (l632 + 1)) {
			fRec891[l632] = 0.0;
			
		}
		for (int l633 = 0; (l633 < 2); l633 = (l633 + 1)) {
			fRec889[l633] = 0.0;
			
		}
		for (int l634 = 0; (l634 < 2); l634 = (l634 + 1)) {
			fRec888[l634] = 0.0;
			
		}
		for (int l635 = 0; (l635 < 2); l635 = (l635 + 1)) {
			fRec886[l635] = 0.0;
			
		}
		for (int l636 = 0; (l636 < 2); l636 = (l636 + 1)) {
			fRec912[l636] = 0.0;
			
		}
		for (int l637 = 0; (l637 < 2); l637 = (l637 + 1)) {
			fRec910[l637] = 0.0;
			
		}
		for (int l638 = 0; (l638 < 2); l638 = (l638 + 1)) {
			fRec909[l638] = 0.0;
			
		}
		for (int l639 = 0; (l639 < 2); l639 = (l639 + 1)) {
			fRec907[l639] = 0.0;
			
		}
		for (int l640 = 0; (l640 < 2); l640 = (l640 + 1)) {
			fRec906[l640] = 0.0;
			
		}
		for (int l641 = 0; (l641 < 2); l641 = (l641 + 1)) {
			fRec904[l641] = 0.0;
			
		}
		for (int l642 = 0; (l642 < 2); l642 = (l642 + 1)) {
			fRec903[l642] = 0.0;
			
		}
		for (int l643 = 0; (l643 < 2); l643 = (l643 + 1)) {
			fRec901[l643] = 0.0;
			
		}
		for (int l644 = 0; (l644 < 2); l644 = (l644 + 1)) {
			fRec921[l644] = 0.0;
			
		}
		for (int l645 = 0; (l645 < 2); l645 = (l645 + 1)) {
			fRec919[l645] = 0.0;
			
		}
		for (int l646 = 0; (l646 < 2); l646 = (l646 + 1)) {
			fRec918[l646] = 0.0;
			
		}
		for (int l647 = 0; (l647 < 2); l647 = (l647 + 1)) {
			fRec916[l647] = 0.0;
			
		}
		for (int l648 = 0; (l648 < 2); l648 = (l648 + 1)) {
			fRec915[l648] = 0.0;
			
		}
		for (int l649 = 0; (l649 < 2); l649 = (l649 + 1)) {
			fRec913[l649] = 0.0;
			
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
			fRec930[l654] = 0.0;
			
		}
		for (int l655 = 0; (l655 < 2); l655 = (l655 + 1)) {
			fRec928[l655] = 0.0;
			
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
			fRec933[l666] = 0.0;
			
		}
		for (int l667 = 0; (l667 < 2); l667 = (l667 + 1)) {
			fRec931[l667] = 0.0;
			
		}
		for (int l668 = 0; (l668 < 1024); l668 = (l668 + 1)) {
			fVec13[l668] = 0.0;
			
		}
		for (int l669 = 0; (l669 < 2); l669 = (l669 + 1)) {
			fRec957[l669] = 0.0;
			
		}
		for (int l670 = 0; (l670 < 2); l670 = (l670 + 1)) {
			fRec955[l670] = 0.0;
			
		}
		for (int l671 = 0; (l671 < 2); l671 = (l671 + 1)) {
			fRec954[l671] = 0.0;
			
		}
		for (int l672 = 0; (l672 < 2); l672 = (l672 + 1)) {
			fRec952[l672] = 0.0;
			
		}
		for (int l673 = 0; (l673 < 2); l673 = (l673 + 1)) {
			fRec951[l673] = 0.0;
			
		}
		for (int l674 = 0; (l674 < 2); l674 = (l674 + 1)) {
			fRec949[l674] = 0.0;
			
		}
		for (int l675 = 0; (l675 < 2); l675 = (l675 + 1)) {
			fRec969[l675] = 0.0;
			
		}
		for (int l676 = 0; (l676 < 2); l676 = (l676 + 1)) {
			fRec967[l676] = 0.0;
			
		}
		for (int l677 = 0; (l677 < 2); l677 = (l677 + 1)) {
			fRec966[l677] = 0.0;
			
		}
		for (int l678 = 0; (l678 < 2); l678 = (l678 + 1)) {
			fRec964[l678] = 0.0;
			
		}
		for (int l679 = 0; (l679 < 2); l679 = (l679 + 1)) {
			fRec963[l679] = 0.0;
			
		}
		for (int l680 = 0; (l680 < 2); l680 = (l680 + 1)) {
			fRec961[l680] = 0.0;
			
		}
		for (int l681 = 0; (l681 < 2); l681 = (l681 + 1)) {
			fRec960[l681] = 0.0;
			
		}
		for (int l682 = 0; (l682 < 2); l682 = (l682 + 1)) {
			fRec958[l682] = 0.0;
			
		}
		for (int l683 = 0; (l683 < 2); l683 = (l683 + 1)) {
			fRec987[l683] = 0.0;
			
		}
		for (int l684 = 0; (l684 < 2); l684 = (l684 + 1)) {
			fRec985[l684] = 0.0;
			
		}
		for (int l685 = 0; (l685 < 2); l685 = (l685 + 1)) {
			fRec984[l685] = 0.0;
			
		}
		for (int l686 = 0; (l686 < 2); l686 = (l686 + 1)) {
			fRec982[l686] = 0.0;
			
		}
		for (int l687 = 0; (l687 < 2); l687 = (l687 + 1)) {
			fRec981[l687] = 0.0;
			
		}
		for (int l688 = 0; (l688 < 2); l688 = (l688 + 1)) {
			fRec979[l688] = 0.0;
			
		}
		for (int l689 = 0; (l689 < 2); l689 = (l689 + 1)) {
			fRec978[l689] = 0.0;
			
		}
		for (int l690 = 0; (l690 < 2); l690 = (l690 + 1)) {
			fRec976[l690] = 0.0;
			
		}
		for (int l691 = 0; (l691 < 2); l691 = (l691 + 1)) {
			fRec975[l691] = 0.0;
			
		}
		for (int l692 = 0; (l692 < 2); l692 = (l692 + 1)) {
			fRec973[l692] = 0.0;
			
		}
		for (int l693 = 0; (l693 < 2); l693 = (l693 + 1)) {
			fRec972[l693] = 0.0;
			
		}
		for (int l694 = 0; (l694 < 2); l694 = (l694 + 1)) {
			fRec970[l694] = 0.0;
			
		}
		for (int l695 = 0; (l695 < 2); l695 = (l695 + 1)) {
			fRec1002[l695] = 0.0;
			
		}
		for (int l696 = 0; (l696 < 2); l696 = (l696 + 1)) {
			fRec1000[l696] = 0.0;
			
		}
		for (int l697 = 0; (l697 < 2); l697 = (l697 + 1)) {
			fRec999[l697] = 0.0;
			
		}
		for (int l698 = 0; (l698 < 2); l698 = (l698 + 1)) {
			fRec997[l698] = 0.0;
			
		}
		for (int l699 = 0; (l699 < 2); l699 = (l699 + 1)) {
			fRec996[l699] = 0.0;
			
		}
		for (int l700 = 0; (l700 < 2); l700 = (l700 + 1)) {
			fRec994[l700] = 0.0;
			
		}
		for (int l701 = 0; (l701 < 2); l701 = (l701 + 1)) {
			fRec993[l701] = 0.0;
			
		}
		for (int l702 = 0; (l702 < 2); l702 = (l702 + 1)) {
			fRec991[l702] = 0.0;
			
		}
		for (int l703 = 0; (l703 < 2); l703 = (l703 + 1)) {
			fRec990[l703] = 0.0;
			
		}
		for (int l704 = 0; (l704 < 2); l704 = (l704 + 1)) {
			fRec988[l704] = 0.0;
			
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
			fRec1071[l748] = 0.0;
			
		}
		for (int l749 = 0; (l749 < 2); l749 = (l749 + 1)) {
			fRec1069[l749] = 0.0;
			
		}
		for (int l750 = 0; (l750 < 2); l750 = (l750 + 1)) {
			fRec1068[l750] = 0.0;
			
		}
		for (int l751 = 0; (l751 < 2); l751 = (l751 + 1)) {
			fRec1066[l751] = 0.0;
			
		}
		for (int l752 = 0; (l752 < 2); l752 = (l752 + 1)) {
			fRec1074[l752] = 0.0;
			
		}
		for (int l753 = 0; (l753 < 2); l753 = (l753 + 1)) {
			fRec1072[l753] = 0.0;
			
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
			fRec1116[l777] = 0.0;
			
		}
		for (int l778 = 0; (l778 < 2); l778 = (l778 + 1)) {
			fRec1114[l778] = 0.0;
			
		}
		for (int l779 = 0; (l779 < 2); l779 = (l779 + 1)) {
			fRec1113[l779] = 0.0;
			
		}
		for (int l780 = 0; (l780 < 2); l780 = (l780 + 1)) {
			fRec1111[l780] = 0.0;
			
		}
		for (int l781 = 0; (l781 < 2); l781 = (l781 + 1)) {
			fRec1110[l781] = 0.0;
			
		}
		for (int l782 = 0; (l782 < 2); l782 = (l782 + 1)) {
			fRec1108[l782] = 0.0;
			
		}
		for (int l783 = 0; (l783 < 2); l783 = (l783 + 1)) {
			fRec1122[l783] = 0.0;
			
		}
		for (int l784 = 0; (l784 < 2); l784 = (l784 + 1)) {
			fRec1120[l784] = 0.0;
			
		}
		for (int l785 = 0; (l785 < 2); l785 = (l785 + 1)) {
			fRec1119[l785] = 0.0;
			
		}
		for (int l786 = 0; (l786 < 2); l786 = (l786 + 1)) {
			fRec1117[l786] = 0.0;
			
		}
		for (int l787 = 0; (l787 < 2); l787 = (l787 + 1)) {
			fRec1125[l787] = 0.0;
			
		}
		for (int l788 = 0; (l788 < 2); l788 = (l788 + 1)) {
			fRec1123[l788] = 0.0;
			
		}
		for (int l789 = 0; (l789 < 2); l789 = (l789 + 1)) {
			fRec1137[l789] = 0.0;
			
		}
		for (int l790 = 0; (l790 < 2); l790 = (l790 + 1)) {
			fRec1135[l790] = 0.0;
			
		}
		for (int l791 = 0; (l791 < 2); l791 = (l791 + 1)) {
			fRec1134[l791] = 0.0;
			
		}
		for (int l792 = 0; (l792 < 2); l792 = (l792 + 1)) {
			fRec1132[l792] = 0.0;
			
		}
		for (int l793 = 0; (l793 < 2); l793 = (l793 + 1)) {
			fRec1131[l793] = 0.0;
			
		}
		for (int l794 = 0; (l794 < 2); l794 = (l794 + 1)) {
			fRec1129[l794] = 0.0;
			
		}
		for (int l795 = 0; (l795 < 2); l795 = (l795 + 1)) {
			fRec1128[l795] = 0.0;
			
		}
		for (int l796 = 0; (l796 < 2); l796 = (l796 + 1)) {
			fRec1126[l796] = 0.0;
			
		}
		for (int l797 = 0; (l797 < 512); l797 = (l797 + 1)) {
			fVec16[l797] = 0.0;
			
		}
		for (int l798 = 0; (l798 < 2); l798 = (l798 + 1)) {
			fRec1143[l798] = 0.0;
			
		}
		for (int l799 = 0; (l799 < 2); l799 = (l799 + 1)) {
			fRec1141[l799] = 0.0;
			
		}
		for (int l800 = 0; (l800 < 2); l800 = (l800 + 1)) {
			fRec1140[l800] = 0.0;
			
		}
		for (int l801 = 0; (l801 < 2); l801 = (l801 + 1)) {
			fRec1138[l801] = 0.0;
			
		}
		for (int l802 = 0; (l802 < 2); l802 = (l802 + 1)) {
			fRec1161[l802] = 0.0;
			
		}
		for (int l803 = 0; (l803 < 2); l803 = (l803 + 1)) {
			fRec1159[l803] = 0.0;
			
		}
		for (int l804 = 0; (l804 < 2); l804 = (l804 + 1)) {
			fRec1158[l804] = 0.0;
			
		}
		for (int l805 = 0; (l805 < 2); l805 = (l805 + 1)) {
			fRec1156[l805] = 0.0;
			
		}
		for (int l806 = 0; (l806 < 2); l806 = (l806 + 1)) {
			fRec1155[l806] = 0.0;
			
		}
		for (int l807 = 0; (l807 < 2); l807 = (l807 + 1)) {
			fRec1153[l807] = 0.0;
			
		}
		for (int l808 = 0; (l808 < 2); l808 = (l808 + 1)) {
			fRec1152[l808] = 0.0;
			
		}
		for (int l809 = 0; (l809 < 2); l809 = (l809 + 1)) {
			fRec1150[l809] = 0.0;
			
		}
		for (int l810 = 0; (l810 < 2); l810 = (l810 + 1)) {
			fRec1149[l810] = 0.0;
			
		}
		for (int l811 = 0; (l811 < 2); l811 = (l811 + 1)) {
			fRec1147[l811] = 0.0;
			
		}
		for (int l812 = 0; (l812 < 2); l812 = (l812 + 1)) {
			fRec1146[l812] = 0.0;
			
		}
		for (int l813 = 0; (l813 < 2); l813 = (l813 + 1)) {
			fRec1144[l813] = 0.0;
			
		}
		for (int l814 = 0; (l814 < 2); l814 = (l814 + 1)) {
			fRec1173[l814] = 0.0;
			
		}
		for (int l815 = 0; (l815 < 2); l815 = (l815 + 1)) {
			fRec1171[l815] = 0.0;
			
		}
		for (int l816 = 0; (l816 < 2); l816 = (l816 + 1)) {
			fRec1170[l816] = 0.0;
			
		}
		for (int l817 = 0; (l817 < 2); l817 = (l817 + 1)) {
			fRec1168[l817] = 0.0;
			
		}
		for (int l818 = 0; (l818 < 2); l818 = (l818 + 1)) {
			fRec1167[l818] = 0.0;
			
		}
		for (int l819 = 0; (l819 < 2); l819 = (l819 + 1)) {
			fRec1165[l819] = 0.0;
			
		}
		for (int l820 = 0; (l820 < 2); l820 = (l820 + 1)) {
			fRec1164[l820] = 0.0;
			
		}
		for (int l821 = 0; (l821 < 2); l821 = (l821 + 1)) {
			fRec1162[l821] = 0.0;
			
		}
		for (int l822 = 0; (l822 < 2); l822 = (l822 + 1)) {
			fRec1182[l822] = 0.0;
			
		}
		for (int l823 = 0; (l823 < 2); l823 = (l823 + 1)) {
			fRec1180[l823] = 0.0;
			
		}
		for (int l824 = 0; (l824 < 2); l824 = (l824 + 1)) {
			fRec1179[l824] = 0.0;
			
		}
		for (int l825 = 0; (l825 < 2); l825 = (l825 + 1)) {
			fRec1177[l825] = 0.0;
			
		}
		for (int l826 = 0; (l826 < 2); l826 = (l826 + 1)) {
			fRec1176[l826] = 0.0;
			
		}
		for (int l827 = 0; (l827 < 2); l827 = (l827 + 1)) {
			fRec1174[l827] = 0.0;
			
		}
		for (int l828 = 0; (l828 < 2); l828 = (l828 + 1)) {
			fRec1185[l828] = 0.0;
			
		}
		for (int l829 = 0; (l829 < 2); l829 = (l829 + 1)) {
			fRec1183[l829] = 0.0;
			
		}
		for (int l830 = 0; (l830 < 2); l830 = (l830 + 1)) {
			fRec1200[l830] = 0.0;
			
		}
		for (int l831 = 0; (l831 < 2); l831 = (l831 + 1)) {
			fRec1198[l831] = 0.0;
			
		}
		for (int l832 = 0; (l832 < 2); l832 = (l832 + 1)) {
			fRec1197[l832] = 0.0;
			
		}
		for (int l833 = 0; (l833 < 2); l833 = (l833 + 1)) {
			fRec1195[l833] = 0.0;
			
		}
		for (int l834 = 0; (l834 < 2); l834 = (l834 + 1)) {
			fRec1194[l834] = 0.0;
			
		}
		for (int l835 = 0; (l835 < 2); l835 = (l835 + 1)) {
			fRec1192[l835] = 0.0;
			
		}
		for (int l836 = 0; (l836 < 2); l836 = (l836 + 1)) {
			fRec1191[l836] = 0.0;
			
		}
		for (int l837 = 0; (l837 < 2); l837 = (l837 + 1)) {
			fRec1189[l837] = 0.0;
			
		}
		for (int l838 = 0; (l838 < 2); l838 = (l838 + 1)) {
			fRec1188[l838] = 0.0;
			
		}
		for (int l839 = 0; (l839 < 2); l839 = (l839 + 1)) {
			fRec1186[l839] = 0.0;
			
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
			fRec1248[l871] = 0.0;
			
		}
		for (int l872 = 0; (l872 < 2); l872 = (l872 + 1)) {
			fRec1246[l872] = 0.0;
			
		}
		for (int l873 = 0; (l873 < 2); l873 = (l873 + 1)) {
			fRec1254[l873] = 0.0;
			
		}
		for (int l874 = 0; (l874 < 2); l874 = (l874 + 1)) {
			fRec1252[l874] = 0.0;
			
		}
		for (int l875 = 0; (l875 < 2); l875 = (l875 + 1)) {
			fRec1251[l875] = 0.0;
			
		}
		for (int l876 = 0; (l876 < 2); l876 = (l876 + 1)) {
			fRec1249[l876] = 0.0;
			
		}
		for (int l877 = 0; (l877 < 2); l877 = (l877 + 1)) {
			fRec1263[l877] = 0.0;
			
		}
		for (int l878 = 0; (l878 < 2); l878 = (l878 + 1)) {
			fRec1261[l878] = 0.0;
			
		}
		for (int l879 = 0; (l879 < 2); l879 = (l879 + 1)) {
			fRec1260[l879] = 0.0;
			
		}
		for (int l880 = 0; (l880 < 2); l880 = (l880 + 1)) {
			fRec1258[l880] = 0.0;
			
		}
		for (int l881 = 0; (l881 < 2); l881 = (l881 + 1)) {
			fRec1257[l881] = 0.0;
			
		}
		for (int l882 = 0; (l882 < 2); l882 = (l882 + 1)) {
			fRec1255[l882] = 0.0;
			
		}
		for (int l883 = 0; (l883 < 512); l883 = (l883 + 1)) {
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
		for (int l926 = 0; (l926 < 512); l926 = (l926 + 1)) {
			fVec19[l926] = 0.0;
			
		}
		for (int l927 = 0; (l927 < 2); l927 = (l927 + 1)) {
			fRec1332[l927] = 0.0;
			
		}
		for (int l928 = 0; (l928 < 2); l928 = (l928 + 1)) {
			fRec1330[l928] = 0.0;
			
		}
		for (int l929 = 0; (l929 < 2); l929 = (l929 + 1)) {
			fRec1329[l929] = 0.0;
			
		}
		for (int l930 = 0; (l930 < 2); l930 = (l930 + 1)) {
			fRec1327[l930] = 0.0;
			
		}
		for (int l931 = 0; (l931 < 2); l931 = (l931 + 1)) {
			fRec1335[l931] = 0.0;
			
		}
		for (int l932 = 0; (l932 < 2); l932 = (l932 + 1)) {
			fRec1333[l932] = 0.0;
			
		}
		for (int l933 = 0; (l933 < 2); l933 = (l933 + 1)) {
			fRec1353[l933] = 0.0;
			
		}
		for (int l934 = 0; (l934 < 2); l934 = (l934 + 1)) {
			fRec1351[l934] = 0.0;
			
		}
		for (int l935 = 0; (l935 < 2); l935 = (l935 + 1)) {
			fRec1350[l935] = 0.0;
			
		}
		for (int l936 = 0; (l936 < 2); l936 = (l936 + 1)) {
			fRec1348[l936] = 0.0;
			
		}
		for (int l937 = 0; (l937 < 2); l937 = (l937 + 1)) {
			fRec1347[l937] = 0.0;
			
		}
		for (int l938 = 0; (l938 < 2); l938 = (l938 + 1)) {
			fRec1345[l938] = 0.0;
			
		}
		for (int l939 = 0; (l939 < 2); l939 = (l939 + 1)) {
			fRec1344[l939] = 0.0;
			
		}
		for (int l940 = 0; (l940 < 2); l940 = (l940 + 1)) {
			fRec1342[l940] = 0.0;
			
		}
		for (int l941 = 0; (l941 < 2); l941 = (l941 + 1)) {
			fRec1341[l941] = 0.0;
			
		}
		for (int l942 = 0; (l942 < 2); l942 = (l942 + 1)) {
			fRec1339[l942] = 0.0;
			
		}
		for (int l943 = 0; (l943 < 2); l943 = (l943 + 1)) {
			fRec1338[l943] = 0.0;
			
		}
		for (int l944 = 0; (l944 < 2); l944 = (l944 + 1)) {
			fRec1336[l944] = 0.0;
			
		}
		for (int l945 = 0; (l945 < 2); l945 = (l945 + 1)) {
			fRec1368[l945] = 0.0;
			
		}
		for (int l946 = 0; (l946 < 2); l946 = (l946 + 1)) {
			fRec1366[l946] = 0.0;
			
		}
		for (int l947 = 0; (l947 < 2); l947 = (l947 + 1)) {
			fRec1365[l947] = 0.0;
			
		}
		for (int l948 = 0; (l948 < 2); l948 = (l948 + 1)) {
			fRec1363[l948] = 0.0;
			
		}
		for (int l949 = 0; (l949 < 2); l949 = (l949 + 1)) {
			fRec1362[l949] = 0.0;
			
		}
		for (int l950 = 0; (l950 < 2); l950 = (l950 + 1)) {
			fRec1360[l950] = 0.0;
			
		}
		for (int l951 = 0; (l951 < 2); l951 = (l951 + 1)) {
			fRec1359[l951] = 0.0;
			
		}
		for (int l952 = 0; (l952 < 2); l952 = (l952 + 1)) {
			fRec1357[l952] = 0.0;
			
		}
		for (int l953 = 0; (l953 < 2); l953 = (l953 + 1)) {
			fRec1356[l953] = 0.0;
			
		}
		for (int l954 = 0; (l954 < 2); l954 = (l954 + 1)) {
			fRec1354[l954] = 0.0;
			
		}
		for (int l955 = 0; (l955 < 2); l955 = (l955 + 1)) {
			fRec1380[l955] = 0.0;
			
		}
		for (int l956 = 0; (l956 < 2); l956 = (l956 + 1)) {
			fRec1378[l956] = 0.0;
			
		}
		for (int l957 = 0; (l957 < 2); l957 = (l957 + 1)) {
			fRec1377[l957] = 0.0;
			
		}
		for (int l958 = 0; (l958 < 2); l958 = (l958 + 1)) {
			fRec1375[l958] = 0.0;
			
		}
		for (int l959 = 0; (l959 < 2); l959 = (l959 + 1)) {
			fRec1374[l959] = 0.0;
			
		}
		for (int l960 = 0; (l960 < 2); l960 = (l960 + 1)) {
			fRec1372[l960] = 0.0;
			
		}
		for (int l961 = 0; (l961 < 2); l961 = (l961 + 1)) {
			fRec1371[l961] = 0.0;
			
		}
		for (int l962 = 0; (l962 < 2); l962 = (l962 + 1)) {
			fRec1369[l962] = 0.0;
			
		}
		for (int l963 = 0; (l963 < 2); l963 = (l963 + 1)) {
			fRec1389[l963] = 0.0;
			
		}
		for (int l964 = 0; (l964 < 2); l964 = (l964 + 1)) {
			fRec1387[l964] = 0.0;
			
		}
		for (int l965 = 0; (l965 < 2); l965 = (l965 + 1)) {
			fRec1386[l965] = 0.0;
			
		}
		for (int l966 = 0; (l966 < 2); l966 = (l966 + 1)) {
			fRec1384[l966] = 0.0;
			
		}
		for (int l967 = 0; (l967 < 2); l967 = (l967 + 1)) {
			fRec1383[l967] = 0.0;
			
		}
		for (int l968 = 0; (l968 < 2); l968 = (l968 + 1)) {
			fRec1381[l968] = 0.0;
			
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
			fRec1449[l1006] = 0.0;
			
		}
		for (int l1007 = 0; (l1007 < 2); l1007 = (l1007 + 1)) {
			fRec1447[l1007] = 0.0;
			
		}
		for (int l1008 = 0; (l1008 < 2); l1008 = (l1008 + 1)) {
			fRec1446[l1008] = 0.0;
			
		}
		for (int l1009 = 0; (l1009 < 2); l1009 = (l1009 + 1)) {
			fRec1444[l1009] = 0.0;
			
		}
		for (int l1010 = 0; (l1010 < 2); l1010 = (l1010 + 1)) {
			fRec1452[l1010] = 0.0;
			
		}
		for (int l1011 = 0; (l1011 < 2); l1011 = (l1011 + 1)) {
			fRec1450[l1011] = 0.0;
			
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
			fRec1482[l1025] = 0.0;
			
		}
		for (int l1026 = 0; (l1026 < 2); l1026 = (l1026 + 1)) {
			fRec1480[l1026] = 0.0;
			
		}
		for (int l1027 = 0; (l1027 < 2); l1027 = (l1027 + 1)) {
			fRec1479[l1027] = 0.0;
			
		}
		for (int l1028 = 0; (l1028 < 2); l1028 = (l1028 + 1)) {
			fRec1477[l1028] = 0.0;
			
		}
		for (int l1029 = 0; (l1029 < 2); l1029 = (l1029 + 1)) {
			fRec1476[l1029] = 0.0;
			
		}
		for (int l1030 = 0; (l1030 < 2); l1030 = (l1030 + 1)) {
			fRec1474[l1030] = 0.0;
			
		}
		for (int l1031 = 0; (l1031 < 2); l1031 = (l1031 + 1)) {
			fRec1473[l1031] = 0.0;
			
		}
		for (int l1032 = 0; (l1032 < 2); l1032 = (l1032 + 1)) {
			fRec1471[l1032] = 0.0;
			
		}
		for (int l1033 = 0; (l1033 < 2); l1033 = (l1033 + 1)) {
			fRec1491[l1033] = 0.0;
			
		}
		for (int l1034 = 0; (l1034 < 2); l1034 = (l1034 + 1)) {
			fRec1489[l1034] = 0.0;
			
		}
		for (int l1035 = 0; (l1035 < 2); l1035 = (l1035 + 1)) {
			fRec1488[l1035] = 0.0;
			
		}
		for (int l1036 = 0; (l1036 < 2); l1036 = (l1036 + 1)) {
			fRec1486[l1036] = 0.0;
			
		}
		for (int l1037 = 0; (l1037 < 2); l1037 = (l1037 + 1)) {
			fRec1485[l1037] = 0.0;
			
		}
		for (int l1038 = 0; (l1038 < 2); l1038 = (l1038 + 1)) {
			fRec1483[l1038] = 0.0;
			
		}
		for (int l1039 = 0; (l1039 < 2); l1039 = (l1039 + 1)) {
			fRec1497[l1039] = 0.0;
			
		}
		for (int l1040 = 0; (l1040 < 2); l1040 = (l1040 + 1)) {
			fRec1495[l1040] = 0.0;
			
		}
		for (int l1041 = 0; (l1041 < 2); l1041 = (l1041 + 1)) {
			fRec1494[l1041] = 0.0;
			
		}
		for (int l1042 = 0; (l1042 < 2); l1042 = (l1042 + 1)) {
			fRec1492[l1042] = 0.0;
			
		}
		for (int l1043 = 0; (l1043 < 2); l1043 = (l1043 + 1)) {
			fRec1500[l1043] = 0.0;
			
		}
		for (int l1044 = 0; (l1044 < 2); l1044 = (l1044 + 1)) {
			fRec1498[l1044] = 0.0;
			
		}
		for (int l1045 = 0; (l1045 < 2); l1045 = (l1045 + 1)) {
			fRec1515[l1045] = 0.0;
			
		}
		for (int l1046 = 0; (l1046 < 2); l1046 = (l1046 + 1)) {
			fRec1513[l1046] = 0.0;
			
		}
		for (int l1047 = 0; (l1047 < 2); l1047 = (l1047 + 1)) {
			fRec1512[l1047] = 0.0;
			
		}
		for (int l1048 = 0; (l1048 < 2); l1048 = (l1048 + 1)) {
			fRec1510[l1048] = 0.0;
			
		}
		for (int l1049 = 0; (l1049 < 2); l1049 = (l1049 + 1)) {
			fRec1509[l1049] = 0.0;
			
		}
		for (int l1050 = 0; (l1050 < 2); l1050 = (l1050 + 1)) {
			fRec1507[l1050] = 0.0;
			
		}
		for (int l1051 = 0; (l1051 < 2); l1051 = (l1051 + 1)) {
			fRec1506[l1051] = 0.0;
			
		}
		for (int l1052 = 0; (l1052 < 2); l1052 = (l1052 + 1)) {
			fRec1504[l1052] = 0.0;
			
		}
		for (int l1053 = 0; (l1053 < 2); l1053 = (l1053 + 1)) {
			fRec1503[l1053] = 0.0;
			
		}
		for (int l1054 = 0; (l1054 < 2); l1054 = (l1054 + 1)) {
			fRec1501[l1054] = 0.0;
			
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
			fRec1575[l1092] = 0.0;
			
		}
		for (int l1093 = 0; (l1093 < 2); l1093 = (l1093 + 1)) {
			fRec1573[l1093] = 0.0;
			
		}
		for (int l1094 = 0; (l1094 < 2); l1094 = (l1094 + 1)) {
			fRec1572[l1094] = 0.0;
			
		}
		for (int l1095 = 0; (l1095 < 2); l1095 = (l1095 + 1)) {
			fRec1570[l1095] = 0.0;
			
		}
		for (int l1096 = 0; (l1096 < 2); l1096 = (l1096 + 1)) {
			fRec1578[l1096] = 0.0;
			
		}
		for (int l1097 = 0; (l1097 < 2); l1097 = (l1097 + 1)) {
			fRec1576[l1097] = 0.0;
			
		}
		for (int l1098 = 0; (l1098 < 512); l1098 = (l1098 + 1)) {
			fVec23[l1098] = 0.0;
			
		}
		for (int l1099 = 0; (l1099 < 2); l1099 = (l1099 + 1)) {
			fRec1590[l1099] = 0.0;
			
		}
		for (int l1100 = 0; (l1100 < 2); l1100 = (l1100 + 1)) {
			fRec1588[l1100] = 0.0;
			
		}
		for (int l1101 = 0; (l1101 < 2); l1101 = (l1101 + 1)) {
			fRec1587[l1101] = 0.0;
			
		}
		for (int l1102 = 0; (l1102 < 2); l1102 = (l1102 + 1)) {
			fRec1585[l1102] = 0.0;
			
		}
		for (int l1103 = 0; (l1103 < 2); l1103 = (l1103 + 1)) {
			fRec1584[l1103] = 0.0;
			
		}
		for (int l1104 = 0; (l1104 < 2); l1104 = (l1104 + 1)) {
			fRec1582[l1104] = 0.0;
			
		}
		for (int l1105 = 0; (l1105 < 2); l1105 = (l1105 + 1)) {
			fRec1581[l1105] = 0.0;
			
		}
		for (int l1106 = 0; (l1106 < 2); l1106 = (l1106 + 1)) {
			fRec1579[l1106] = 0.0;
			
		}
		for (int l1107 = 0; (l1107 < 2); l1107 = (l1107 + 1)) {
			fRec1599[l1107] = 0.0;
			
		}
		for (int l1108 = 0; (l1108 < 2); l1108 = (l1108 + 1)) {
			fRec1597[l1108] = 0.0;
			
		}
		for (int l1109 = 0; (l1109 < 2); l1109 = (l1109 + 1)) {
			fRec1596[l1109] = 0.0;
			
		}
		for (int l1110 = 0; (l1110 < 2); l1110 = (l1110 + 1)) {
			fRec1594[l1110] = 0.0;
			
		}
		for (int l1111 = 0; (l1111 < 2); l1111 = (l1111 + 1)) {
			fRec1593[l1111] = 0.0;
			
		}
		for (int l1112 = 0; (l1112 < 2); l1112 = (l1112 + 1)) {
			fRec1591[l1112] = 0.0;
			
		}
		for (int l1113 = 0; (l1113 < 2); l1113 = (l1113 + 1)) {
			fRec1617[l1113] = 0.0;
			
		}
		for (int l1114 = 0; (l1114 < 2); l1114 = (l1114 + 1)) {
			fRec1615[l1114] = 0.0;
			
		}
		for (int l1115 = 0; (l1115 < 2); l1115 = (l1115 + 1)) {
			fRec1614[l1115] = 0.0;
			
		}
		for (int l1116 = 0; (l1116 < 2); l1116 = (l1116 + 1)) {
			fRec1612[l1116] = 0.0;
			
		}
		for (int l1117 = 0; (l1117 < 2); l1117 = (l1117 + 1)) {
			fRec1611[l1117] = 0.0;
			
		}
		for (int l1118 = 0; (l1118 < 2); l1118 = (l1118 + 1)) {
			fRec1609[l1118] = 0.0;
			
		}
		for (int l1119 = 0; (l1119 < 2); l1119 = (l1119 + 1)) {
			fRec1608[l1119] = 0.0;
			
		}
		for (int l1120 = 0; (l1120 < 2); l1120 = (l1120 + 1)) {
			fRec1606[l1120] = 0.0;
			
		}
		for (int l1121 = 0; (l1121 < 2); l1121 = (l1121 + 1)) {
			fRec1605[l1121] = 0.0;
			
		}
		for (int l1122 = 0; (l1122 < 2); l1122 = (l1122 + 1)) {
			fRec1603[l1122] = 0.0;
			
		}
		for (int l1123 = 0; (l1123 < 2); l1123 = (l1123 + 1)) {
			fRec1602[l1123] = 0.0;
			
		}
		for (int l1124 = 0; (l1124 < 2); l1124 = (l1124 + 1)) {
			fRec1600[l1124] = 0.0;
			
		}
		for (int l1125 = 0; (l1125 < 2); l1125 = (l1125 + 1)) {
			fRec1623[l1125] = 0.0;
			
		}
		for (int l1126 = 0; (l1126 < 2); l1126 = (l1126 + 1)) {
			fRec1621[l1126] = 0.0;
			
		}
		for (int l1127 = 0; (l1127 < 2); l1127 = (l1127 + 1)) {
			fRec1620[l1127] = 0.0;
			
		}
		for (int l1128 = 0; (l1128 < 2); l1128 = (l1128 + 1)) {
			fRec1618[l1128] = 0.0;
			
		}
		for (int l1129 = 0; (l1129 < 2); l1129 = (l1129 + 1)) {
			fRec1626[l1129] = 0.0;
			
		}
		for (int l1130 = 0; (l1130 < 2); l1130 = (l1130 + 1)) {
			fRec1624[l1130] = 0.0;
			
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
			fRec1644[l1142] = 0.0;
			
		}
		for (int l1143 = 0; (l1143 < 2); l1143 = (l1143 + 1)) {
			fRec1642[l1143] = 0.0;
			
		}
		for (int l1144 = 0; (l1144 < 2); l1144 = (l1144 + 1)) {
			fRec1662[l1144] = 0.0;
			
		}
		for (int l1145 = 0; (l1145 < 2); l1145 = (l1145 + 1)) {
			fRec1660[l1145] = 0.0;
			
		}
		for (int l1146 = 0; (l1146 < 2); l1146 = (l1146 + 1)) {
			fRec1659[l1146] = 0.0;
			
		}
		for (int l1147 = 0; (l1147 < 2); l1147 = (l1147 + 1)) {
			fRec1657[l1147] = 0.0;
			
		}
		for (int l1148 = 0; (l1148 < 2); l1148 = (l1148 + 1)) {
			fRec1656[l1148] = 0.0;
			
		}
		for (int l1149 = 0; (l1149 < 2); l1149 = (l1149 + 1)) {
			fRec1654[l1149] = 0.0;
			
		}
		for (int l1150 = 0; (l1150 < 2); l1150 = (l1150 + 1)) {
			fRec1653[l1150] = 0.0;
			
		}
		for (int l1151 = 0; (l1151 < 2); l1151 = (l1151 + 1)) {
			fRec1651[l1151] = 0.0;
			
		}
		for (int l1152 = 0; (l1152 < 2); l1152 = (l1152 + 1)) {
			fRec1650[l1152] = 0.0;
			
		}
		for (int l1153 = 0; (l1153 < 2); l1153 = (l1153 + 1)) {
			fRec1648[l1153] = 0.0;
			
		}
		for (int l1154 = 0; (l1154 < 2); l1154 = (l1154 + 1)) {
			fRec1647[l1154] = 0.0;
			
		}
		for (int l1155 = 0; (l1155 < 2); l1155 = (l1155 + 1)) {
			fRec1645[l1155] = 0.0;
			
		}
		for (int l1156 = 0; (l1156 < 2); l1156 = (l1156 + 1)) {
			fRec1677[l1156] = 0.0;
			
		}
		for (int l1157 = 0; (l1157 < 2); l1157 = (l1157 + 1)) {
			fRec1675[l1157] = 0.0;
			
		}
		for (int l1158 = 0; (l1158 < 2); l1158 = (l1158 + 1)) {
			fRec1674[l1158] = 0.0;
			
		}
		for (int l1159 = 0; (l1159 < 2); l1159 = (l1159 + 1)) {
			fRec1672[l1159] = 0.0;
			
		}
		for (int l1160 = 0; (l1160 < 2); l1160 = (l1160 + 1)) {
			fRec1671[l1160] = 0.0;
			
		}
		for (int l1161 = 0; (l1161 < 2); l1161 = (l1161 + 1)) {
			fRec1669[l1161] = 0.0;
			
		}
		for (int l1162 = 0; (l1162 < 2); l1162 = (l1162 + 1)) {
			fRec1668[l1162] = 0.0;
			
		}
		for (int l1163 = 0; (l1163 < 2); l1163 = (l1163 + 1)) {
			fRec1666[l1163] = 0.0;
			
		}
		for (int l1164 = 0; (l1164 < 2); l1164 = (l1164 + 1)) {
			fRec1665[l1164] = 0.0;
			
		}
		for (int l1165 = 0; (l1165 < 2); l1165 = (l1165 + 1)) {
			fRec1663[l1165] = 0.0;
			
		}
		for (int l1166 = 0; (l1166 < 2); l1166 = (l1166 + 1)) {
			fRec1686[l1166] = 0.0;
			
		}
		for (int l1167 = 0; (l1167 < 2); l1167 = (l1167 + 1)) {
			fRec1684[l1167] = 0.0;
			
		}
		for (int l1168 = 0; (l1168 < 2); l1168 = (l1168 + 1)) {
			fRec1683[l1168] = 0.0;
			
		}
		for (int l1169 = 0; (l1169 < 2); l1169 = (l1169 + 1)) {
			fRec1681[l1169] = 0.0;
			
		}
		for (int l1170 = 0; (l1170 < 2); l1170 = (l1170 + 1)) {
			fRec1680[l1170] = 0.0;
			
		}
		for (int l1171 = 0; (l1171 < 2); l1171 = (l1171 + 1)) {
			fRec1678[l1171] = 0.0;
			
		}
		for (int l1172 = 0; (l1172 < 2); l1172 = (l1172 + 1)) {
			fRec1692[l1172] = 0.0;
			
		}
		for (int l1173 = 0; (l1173 < 2); l1173 = (l1173 + 1)) {
			fRec1690[l1173] = 0.0;
			
		}
		for (int l1174 = 0; (l1174 < 2); l1174 = (l1174 + 1)) {
			fRec1689[l1174] = 0.0;
			
		}
		for (int l1175 = 0; (l1175 < 2); l1175 = (l1175 + 1)) {
			fRec1687[l1175] = 0.0;
			
		}
		for (int l1176 = 0; (l1176 < 2); l1176 = (l1176 + 1)) {
			fRec1704[l1176] = 0.0;
			
		}
		for (int l1177 = 0; (l1177 < 2); l1177 = (l1177 + 1)) {
			fRec1702[l1177] = 0.0;
			
		}
		for (int l1178 = 0; (l1178 < 2); l1178 = (l1178 + 1)) {
			fRec1701[l1178] = 0.0;
			
		}
		for (int l1179 = 0; (l1179 < 2); l1179 = (l1179 + 1)) {
			fRec1699[l1179] = 0.0;
			
		}
		for (int l1180 = 0; (l1180 < 2); l1180 = (l1180 + 1)) {
			fRec1698[l1180] = 0.0;
			
		}
		for (int l1181 = 0; (l1181 < 2); l1181 = (l1181 + 1)) {
			fRec1696[l1181] = 0.0;
			
		}
		for (int l1182 = 0; (l1182 < 2); l1182 = (l1182 + 1)) {
			fRec1695[l1182] = 0.0;
			
		}
		for (int l1183 = 0; (l1183 < 2); l1183 = (l1183 + 1)) {
			fRec1693[l1183] = 0.0;
			
		}
		for (int l1184 = 0; (l1184 < 256); l1184 = (l1184 + 1)) {
			fVec25[l1184] = 0.0;
			
		}
		for (int l1185 = 0; (l1185 < 2); l1185 = (l1185 + 1)) {
			fRec1716[l1185] = 0.0;
			
		}
		for (int l1186 = 0; (l1186 < 2); l1186 = (l1186 + 1)) {
			fRec1714[l1186] = 0.0;
			
		}
		for (int l1187 = 0; (l1187 < 2); l1187 = (l1187 + 1)) {
			fRec1713[l1187] = 0.0;
			
		}
		for (int l1188 = 0; (l1188 < 2); l1188 = (l1188 + 1)) {
			fRec1711[l1188] = 0.0;
			
		}
		for (int l1189 = 0; (l1189 < 2); l1189 = (l1189 + 1)) {
			fRec1710[l1189] = 0.0;
			
		}
		for (int l1190 = 0; (l1190 < 2); l1190 = (l1190 + 1)) {
			fRec1708[l1190] = 0.0;
			
		}
		for (int l1191 = 0; (l1191 < 2); l1191 = (l1191 + 1)) {
			fRec1707[l1191] = 0.0;
			
		}
		for (int l1192 = 0; (l1192 < 2); l1192 = (l1192 + 1)) {
			fRec1705[l1192] = 0.0;
			
		}
		for (int l1193 = 0; (l1193 < 2); l1193 = (l1193 + 1)) {
			fRec1725[l1193] = 0.0;
			
		}
		for (int l1194 = 0; (l1194 < 2); l1194 = (l1194 + 1)) {
			fRec1723[l1194] = 0.0;
			
		}
		for (int l1195 = 0; (l1195 < 2); l1195 = (l1195 + 1)) {
			fRec1722[l1195] = 0.0;
			
		}
		for (int l1196 = 0; (l1196 < 2); l1196 = (l1196 + 1)) {
			fRec1720[l1196] = 0.0;
			
		}
		for (int l1197 = 0; (l1197 < 2); l1197 = (l1197 + 1)) {
			fRec1719[l1197] = 0.0;
			
		}
		for (int l1198 = 0; (l1198 < 2); l1198 = (l1198 + 1)) {
			fRec1717[l1198] = 0.0;
			
		}
		for (int l1199 = 0; (l1199 < 2); l1199 = (l1199 + 1)) {
			fRec1743[l1199] = 0.0;
			
		}
		for (int l1200 = 0; (l1200 < 2); l1200 = (l1200 + 1)) {
			fRec1741[l1200] = 0.0;
			
		}
		for (int l1201 = 0; (l1201 < 2); l1201 = (l1201 + 1)) {
			fRec1740[l1201] = 0.0;
			
		}
		for (int l1202 = 0; (l1202 < 2); l1202 = (l1202 + 1)) {
			fRec1738[l1202] = 0.0;
			
		}
		for (int l1203 = 0; (l1203 < 2); l1203 = (l1203 + 1)) {
			fRec1737[l1203] = 0.0;
			
		}
		for (int l1204 = 0; (l1204 < 2); l1204 = (l1204 + 1)) {
			fRec1735[l1204] = 0.0;
			
		}
		for (int l1205 = 0; (l1205 < 2); l1205 = (l1205 + 1)) {
			fRec1734[l1205] = 0.0;
			
		}
		for (int l1206 = 0; (l1206 < 2); l1206 = (l1206 + 1)) {
			fRec1732[l1206] = 0.0;
			
		}
		for (int l1207 = 0; (l1207 < 2); l1207 = (l1207 + 1)) {
			fRec1731[l1207] = 0.0;
			
		}
		for (int l1208 = 0; (l1208 < 2); l1208 = (l1208 + 1)) {
			fRec1729[l1208] = 0.0;
			
		}
		for (int l1209 = 0; (l1209 < 2); l1209 = (l1209 + 1)) {
			fRec1728[l1209] = 0.0;
			
		}
		for (int l1210 = 0; (l1210 < 2); l1210 = (l1210 + 1)) {
			fRec1726[l1210] = 0.0;
			
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
			fRec1752[l1215] = 0.0;
			
		}
		for (int l1216 = 0; (l1216 < 2); l1216 = (l1216 + 1)) {
			fRec1750[l1216] = 0.0;
			
		}
		for (int l1217 = 0; (l1217 < 2); l1217 = (l1217 + 1)) {
			fRec1767[l1217] = 0.0;
			
		}
		for (int l1218 = 0; (l1218 < 2); l1218 = (l1218 + 1)) {
			fRec1765[l1218] = 0.0;
			
		}
		for (int l1219 = 0; (l1219 < 2); l1219 = (l1219 + 1)) {
			fRec1764[l1219] = 0.0;
			
		}
		for (int l1220 = 0; (l1220 < 2); l1220 = (l1220 + 1)) {
			fRec1762[l1220] = 0.0;
			
		}
		for (int l1221 = 0; (l1221 < 2); l1221 = (l1221 + 1)) {
			fRec1761[l1221] = 0.0;
			
		}
		for (int l1222 = 0; (l1222 < 2); l1222 = (l1222 + 1)) {
			fRec1759[l1222] = 0.0;
			
		}
		for (int l1223 = 0; (l1223 < 2); l1223 = (l1223 + 1)) {
			fRec1758[l1223] = 0.0;
			
		}
		for (int l1224 = 0; (l1224 < 2); l1224 = (l1224 + 1)) {
			fRec1756[l1224] = 0.0;
			
		}
		for (int l1225 = 0; (l1225 < 2); l1225 = (l1225 + 1)) {
			fRec1755[l1225] = 0.0;
			
		}
		for (int l1226 = 0; (l1226 < 2); l1226 = (l1226 + 1)) {
			fRec1753[l1226] = 0.0;
			
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
			fRec1794[l1240] = 0.0;
			
		}
		for (int l1241 = 0; (l1241 < 2); l1241 = (l1241 + 1)) {
			fRec1792[l1241] = 0.0;
			
		}
		for (int l1242 = 0; (l1242 < 2); l1242 = (l1242 + 1)) {
			fRec1791[l1242] = 0.0;
			
		}
		for (int l1243 = 0; (l1243 < 2); l1243 = (l1243 + 1)) {
			fRec1789[l1243] = 0.0;
			
		}
		for (int l1244 = 0; (l1244 < 2); l1244 = (l1244 + 1)) {
			fRec1788[l1244] = 0.0;
			
		}
		for (int l1245 = 0; (l1245 < 2); l1245 = (l1245 + 1)) {
			fRec1786[l1245] = 0.0;
			
		}
		for (int l1246 = 0; (l1246 < 2); l1246 = (l1246 + 1)) {
			fRec1806[l1246] = 0.0;
			
		}
		for (int l1247 = 0; (l1247 < 2); l1247 = (l1247 + 1)) {
			fRec1804[l1247] = 0.0;
			
		}
		for (int l1248 = 0; (l1248 < 2); l1248 = (l1248 + 1)) {
			fRec1803[l1248] = 0.0;
			
		}
		for (int l1249 = 0; (l1249 < 2); l1249 = (l1249 + 1)) {
			fRec1801[l1249] = 0.0;
			
		}
		for (int l1250 = 0; (l1250 < 2); l1250 = (l1250 + 1)) {
			fRec1800[l1250] = 0.0;
			
		}
		for (int l1251 = 0; (l1251 < 2); l1251 = (l1251 + 1)) {
			fRec1798[l1251] = 0.0;
			
		}
		for (int l1252 = 0; (l1252 < 2); l1252 = (l1252 + 1)) {
			fRec1797[l1252] = 0.0;
			
		}
		for (int l1253 = 0; (l1253 < 2); l1253 = (l1253 + 1)) {
			fRec1795[l1253] = 0.0;
			
		}
		for (int l1254 = 0; (l1254 < 2); l1254 = (l1254 + 1)) {
			fRec1812[l1254] = 0.0;
			
		}
		for (int l1255 = 0; (l1255 < 2); l1255 = (l1255 + 1)) {
			fRec1810[l1255] = 0.0;
			
		}
		for (int l1256 = 0; (l1256 < 2); l1256 = (l1256 + 1)) {
			fRec1809[l1256] = 0.0;
			
		}
		for (int l1257 = 0; (l1257 < 2); l1257 = (l1257 + 1)) {
			fRec1807[l1257] = 0.0;
			
		}
		for (int l1258 = 0; (l1258 < 2); l1258 = (l1258 + 1)) {
			fRec1815[l1258] = 0.0;
			
		}
		for (int l1259 = 0; (l1259 < 2); l1259 = (l1259 + 1)) {
			fRec1813[l1259] = 0.0;
			
		}
		for (int l1260 = 0; (l1260 < 2); l1260 = (l1260 + 1)) {
			fRec1830[l1260] = 0.0;
			
		}
		for (int l1261 = 0; (l1261 < 2); l1261 = (l1261 + 1)) {
			fRec1828[l1261] = 0.0;
			
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
			fRec1818[l1268] = 0.0;
			
		}
		for (int l1269 = 0; (l1269 < 2); l1269 = (l1269 + 1)) {
			fRec1816[l1269] = 0.0;
			
		}
		for (int l1270 = 0; (l1270 < 256); l1270 = (l1270 + 1)) {
			fVec27[l1270] = 0.0;
			
		}
		for (int l1271 = 0; (l1271 < 2); l1271 = (l1271 + 1)) {
			fRec1845[l1271] = 0.0;
			
		}
		for (int l1272 = 0; (l1272 < 2); l1272 = (l1272 + 1)) {
			fRec1843[l1272] = 0.0;
			
		}
		for (int l1273 = 0; (l1273 < 2); l1273 = (l1273 + 1)) {
			fRec1842[l1273] = 0.0;
			
		}
		for (int l1274 = 0; (l1274 < 2); l1274 = (l1274 + 1)) {
			fRec1840[l1274] = 0.0;
			
		}
		for (int l1275 = 0; (l1275 < 2); l1275 = (l1275 + 1)) {
			fRec1839[l1275] = 0.0;
			
		}
		for (int l1276 = 0; (l1276 < 2); l1276 = (l1276 + 1)) {
			fRec1837[l1276] = 0.0;
			
		}
		for (int l1277 = 0; (l1277 < 2); l1277 = (l1277 + 1)) {
			fRec1836[l1277] = 0.0;
			
		}
		for (int l1278 = 0; (l1278 < 2); l1278 = (l1278 + 1)) {
			fRec1834[l1278] = 0.0;
			
		}
		for (int l1279 = 0; (l1279 < 2); l1279 = (l1279 + 1)) {
			fRec1833[l1279] = 0.0;
			
		}
		for (int l1280 = 0; (l1280 < 2); l1280 = (l1280 + 1)) {
			fRec1831[l1280] = 0.0;
			
		}
		for (int l1281 = 0; (l1281 < 2); l1281 = (l1281 + 1)) {
			fRec1857[l1281] = 0.0;
			
		}
		for (int l1282 = 0; (l1282 < 2); l1282 = (l1282 + 1)) {
			fRec1855[l1282] = 0.0;
			
		}
		for (int l1283 = 0; (l1283 < 2); l1283 = (l1283 + 1)) {
			fRec1854[l1283] = 0.0;
			
		}
		for (int l1284 = 0; (l1284 < 2); l1284 = (l1284 + 1)) {
			fRec1852[l1284] = 0.0;
			
		}
		for (int l1285 = 0; (l1285 < 2); l1285 = (l1285 + 1)) {
			fRec1851[l1285] = 0.0;
			
		}
		for (int l1286 = 0; (l1286 < 2); l1286 = (l1286 + 1)) {
			fRec1849[l1286] = 0.0;
			
		}
		for (int l1287 = 0; (l1287 < 2); l1287 = (l1287 + 1)) {
			fRec1848[l1287] = 0.0;
			
		}
		for (int l1288 = 0; (l1288 < 2); l1288 = (l1288 + 1)) {
			fRec1846[l1288] = 0.0;
			
		}
		for (int l1289 = 0; (l1289 < 2); l1289 = (l1289 + 1)) {
			fRec1860[l1289] = 0.0;
			
		}
		for (int l1290 = 0; (l1290 < 2); l1290 = (l1290 + 1)) {
			fRec1858[l1290] = 0.0;
			
		}
		for (int l1291 = 0; (l1291 < 2); l1291 = (l1291 + 1)) {
			fRec1878[l1291] = 0.0;
			
		}
		for (int l1292 = 0; (l1292 < 2); l1292 = (l1292 + 1)) {
			fRec1876[l1292] = 0.0;
			
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
			fRec1863[l1301] = 0.0;
			
		}
		for (int l1302 = 0; (l1302 < 2); l1302 = (l1302 + 1)) {
			fRec1861[l1302] = 0.0;
			
		}
		for (int l1303 = 0; (l1303 < 2); l1303 = (l1303 + 1)) {
			fRec1884[l1303] = 0.0;
			
		}
		for (int l1304 = 0; (l1304 < 2); l1304 = (l1304 + 1)) {
			fRec1882[l1304] = 0.0;
			
		}
		for (int l1305 = 0; (l1305 < 2); l1305 = (l1305 + 1)) {
			fRec1881[l1305] = 0.0;
			
		}
		for (int l1306 = 0; (l1306 < 2); l1306 = (l1306 + 1)) {
			fRec1879[l1306] = 0.0;
			
		}
		for (int l1307 = 0; (l1307 < 2); l1307 = (l1307 + 1)) {
			fRec1893[l1307] = 0.0;
			
		}
		for (int l1308 = 0; (l1308 < 2); l1308 = (l1308 + 1)) {
			fRec1891[l1308] = 0.0;
			
		}
		for (int l1309 = 0; (l1309 < 2); l1309 = (l1309 + 1)) {
			fRec1890[l1309] = 0.0;
			
		}
		for (int l1310 = 0; (l1310 < 2); l1310 = (l1310 + 1)) {
			fRec1888[l1310] = 0.0;
			
		}
		for (int l1311 = 0; (l1311 < 2); l1311 = (l1311 + 1)) {
			fRec1887[l1311] = 0.0;
			
		}
		for (int l1312 = 0; (l1312 < 2); l1312 = (l1312 + 1)) {
			fRec1885[l1312] = 0.0;
			
		}
		for (int l1313 = 0; (l1313 < 2); l1313 = (l1313 + 1)) {
			fRec1902[l1313] = 0.0;
			
		}
		for (int l1314 = 0; (l1314 < 2); l1314 = (l1314 + 1)) {
			fRec1900[l1314] = 0.0;
			
		}
		for (int l1315 = 0; (l1315 < 2); l1315 = (l1315 + 1)) {
			fRec1899[l1315] = 0.0;
			
		}
		for (int l1316 = 0; (l1316 < 2); l1316 = (l1316 + 1)) {
			fRec1897[l1316] = 0.0;
			
		}
		for (int l1317 = 0; (l1317 < 2); l1317 = (l1317 + 1)) {
			fRec1896[l1317] = 0.0;
			
		}
		for (int l1318 = 0; (l1318 < 2); l1318 = (l1318 + 1)) {
			fRec1894[l1318] = 0.0;
			
		}
		for (int l1319 = 0; (l1319 < 2); l1319 = (l1319 + 1)) {
			fRec1914[l1319] = 0.0;
			
		}
		for (int l1320 = 0; (l1320 < 2); l1320 = (l1320 + 1)) {
			fRec1912[l1320] = 0.0;
			
		}
		for (int l1321 = 0; (l1321 < 2); l1321 = (l1321 + 1)) {
			fRec1911[l1321] = 0.0;
			
		}
		for (int l1322 = 0; (l1322 < 2); l1322 = (l1322 + 1)) {
			fRec1909[l1322] = 0.0;
			
		}
		for (int l1323 = 0; (l1323 < 2); l1323 = (l1323 + 1)) {
			fRec1908[l1323] = 0.0;
			
		}
		for (int l1324 = 0; (l1324 < 2); l1324 = (l1324 + 1)) {
			fRec1906[l1324] = 0.0;
			
		}
		for (int l1325 = 0; (l1325 < 2); l1325 = (l1325 + 1)) {
			fRec1905[l1325] = 0.0;
			
		}
		for (int l1326 = 0; (l1326 < 2); l1326 = (l1326 + 1)) {
			fRec1903[l1326] = 0.0;
			
		}
		for (int l1327 = 0; (l1327 < 2); l1327 = (l1327 + 1)) {
			fRec1917[l1327] = 0.0;
			
		}
		for (int l1328 = 0; (l1328 < 2); l1328 = (l1328 + 1)) {
			fRec1915[l1328] = 0.0;
			
		}
		for (int l1329 = 0; (l1329 < 2); l1329 = (l1329 + 1)) {
			fRec1935[l1329] = 0.0;
			
		}
		for (int l1330 = 0; (l1330 < 2); l1330 = (l1330 + 1)) {
			fRec1933[l1330] = 0.0;
			
		}
		for (int l1331 = 0; (l1331 < 2); l1331 = (l1331 + 1)) {
			fRec1932[l1331] = 0.0;
			
		}
		for (int l1332 = 0; (l1332 < 2); l1332 = (l1332 + 1)) {
			fRec1930[l1332] = 0.0;
			
		}
		for (int l1333 = 0; (l1333 < 2); l1333 = (l1333 + 1)) {
			fRec1929[l1333] = 0.0;
			
		}
		for (int l1334 = 0; (l1334 < 2); l1334 = (l1334 + 1)) {
			fRec1927[l1334] = 0.0;
			
		}
		for (int l1335 = 0; (l1335 < 2); l1335 = (l1335 + 1)) {
			fRec1926[l1335] = 0.0;
			
		}
		for (int l1336 = 0; (l1336 < 2); l1336 = (l1336 + 1)) {
			fRec1924[l1336] = 0.0;
			
		}
		for (int l1337 = 0; (l1337 < 2); l1337 = (l1337 + 1)) {
			fRec1923[l1337] = 0.0;
			
		}
		for (int l1338 = 0; (l1338 < 2); l1338 = (l1338 + 1)) {
			fRec1921[l1338] = 0.0;
			
		}
		for (int l1339 = 0; (l1339 < 2); l1339 = (l1339 + 1)) {
			fRec1920[l1339] = 0.0;
			
		}
		for (int l1340 = 0; (l1340 < 2); l1340 = (l1340 + 1)) {
			fRec1918[l1340] = 0.0;
			
		}
		for (int l1341 = 0; (l1341 < 2); l1341 = (l1341 + 1)) {
			fRec1941[l1341] = 0.0;
			
		}
		for (int l1342 = 0; (l1342 < 2); l1342 = (l1342 + 1)) {
			fRec1939[l1342] = 0.0;
			
		}
		for (int l1343 = 0; (l1343 < 2); l1343 = (l1343 + 1)) {
			fRec1938[l1343] = 0.0;
			
		}
		for (int l1344 = 0; (l1344 < 2); l1344 = (l1344 + 1)) {
			fRec1936[l1344] = 0.0;
			
		}
		for (int l1345 = 0; (l1345 < 2); l1345 = (l1345 + 1)) {
			fRec1956[l1345] = 0.0;
			
		}
		for (int l1346 = 0; (l1346 < 2); l1346 = (l1346 + 1)) {
			fRec1954[l1346] = 0.0;
			
		}
		for (int l1347 = 0; (l1347 < 2); l1347 = (l1347 + 1)) {
			fRec1953[l1347] = 0.0;
			
		}
		for (int l1348 = 0; (l1348 < 2); l1348 = (l1348 + 1)) {
			fRec1951[l1348] = 0.0;
			
		}
		for (int l1349 = 0; (l1349 < 2); l1349 = (l1349 + 1)) {
			fRec1950[l1349] = 0.0;
			
		}
		for (int l1350 = 0; (l1350 < 2); l1350 = (l1350 + 1)) {
			fRec1948[l1350] = 0.0;
			
		}
		for (int l1351 = 0; (l1351 < 2); l1351 = (l1351 + 1)) {
			fRec1947[l1351] = 0.0;
			
		}
		for (int l1352 = 0; (l1352 < 2); l1352 = (l1352 + 1)) {
			fRec1945[l1352] = 0.0;
			
		}
		for (int l1353 = 0; (l1353 < 2); l1353 = (l1353 + 1)) {
			fRec1944[l1353] = 0.0;
			
		}
		for (int l1354 = 0; (l1354 < 2); l1354 = (l1354 + 1)) {
			fRec1942[l1354] = 0.0;
			
		}
		for (int l1355 = 0; (l1355 < 1024); l1355 = (l1355 + 1)) {
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
			fRec1986[l1368] = 0.0;
			
		}
		for (int l1369 = 0; (l1369 < 2); l1369 = (l1369 + 1)) {
			fRec1984[l1369] = 0.0;
			
		}
		for (int l1370 = 0; (l1370 < 2); l1370 = (l1370 + 1)) {
			fRec1983[l1370] = 0.0;
			
		}
		for (int l1371 = 0; (l1371 < 2); l1371 = (l1371 + 1)) {
			fRec1981[l1371] = 0.0;
			
		}
		for (int l1372 = 0; (l1372 < 2); l1372 = (l1372 + 1)) {
			fRec1980[l1372] = 0.0;
			
		}
		for (int l1373 = 0; (l1373 < 2); l1373 = (l1373 + 1)) {
			fRec1978[l1373] = 0.0;
			
		}
		for (int l1374 = 0; (l1374 < 2); l1374 = (l1374 + 1)) {
			fRec1977[l1374] = 0.0;
			
		}
		for (int l1375 = 0; (l1375 < 2); l1375 = (l1375 + 1)) {
			fRec1975[l1375] = 0.0;
			
		}
		for (int l1376 = 0; (l1376 < 2); l1376 = (l1376 + 1)) {
			fRec1995[l1376] = 0.0;
			
		}
		for (int l1377 = 0; (l1377 < 2); l1377 = (l1377 + 1)) {
			fRec1993[l1377] = 0.0;
			
		}
		for (int l1378 = 0; (l1378 < 2); l1378 = (l1378 + 1)) {
			fRec1992[l1378] = 0.0;
			
		}
		for (int l1379 = 0; (l1379 < 2); l1379 = (l1379 + 1)) {
			fRec1990[l1379] = 0.0;
			
		}
		for (int l1380 = 0; (l1380 < 2); l1380 = (l1380 + 1)) {
			fRec1989[l1380] = 0.0;
			
		}
		for (int l1381 = 0; (l1381 < 2); l1381 = (l1381 + 1)) {
			fRec1987[l1381] = 0.0;
			
		}
		for (int l1382 = 0; (l1382 < 2); l1382 = (l1382 + 1)) {
			fRec2010[l1382] = 0.0;
			
		}
		for (int l1383 = 0; (l1383 < 2); l1383 = (l1383 + 1)) {
			fRec2008[l1383] = 0.0;
			
		}
		for (int l1384 = 0; (l1384 < 2); l1384 = (l1384 + 1)) {
			fRec2007[l1384] = 0.0;
			
		}
		for (int l1385 = 0; (l1385 < 2); l1385 = (l1385 + 1)) {
			fRec2005[l1385] = 0.0;
			
		}
		for (int l1386 = 0; (l1386 < 2); l1386 = (l1386 + 1)) {
			fRec2004[l1386] = 0.0;
			
		}
		for (int l1387 = 0; (l1387 < 2); l1387 = (l1387 + 1)) {
			fRec2002[l1387] = 0.0;
			
		}
		for (int l1388 = 0; (l1388 < 2); l1388 = (l1388 + 1)) {
			fRec2001[l1388] = 0.0;
			
		}
		for (int l1389 = 0; (l1389 < 2); l1389 = (l1389 + 1)) {
			fRec1999[l1389] = 0.0;
			
		}
		for (int l1390 = 0; (l1390 < 2); l1390 = (l1390 + 1)) {
			fRec1998[l1390] = 0.0;
			
		}
		for (int l1391 = 0; (l1391 < 2); l1391 = (l1391 + 1)) {
			fRec1996[l1391] = 0.0;
			
		}
		for (int l1392 = 0; (l1392 < 2); l1392 = (l1392 + 1)) {
			fRec2016[l1392] = 0.0;
			
		}
		for (int l1393 = 0; (l1393 < 2); l1393 = (l1393 + 1)) {
			fRec2014[l1393] = 0.0;
			
		}
		for (int l1394 = 0; (l1394 < 2); l1394 = (l1394 + 1)) {
			fRec2013[l1394] = 0.0;
			
		}
		for (int l1395 = 0; (l1395 < 2); l1395 = (l1395 + 1)) {
			fRec2011[l1395] = 0.0;
			
		}
		for (int l1396 = 0; (l1396 < 2); l1396 = (l1396 + 1)) {
			fRec2019[l1396] = 0.0;
			
		}
		for (int l1397 = 0; (l1397 < 2); l1397 = (l1397 + 1)) {
			fRec2017[l1397] = 0.0;
			
		}
		for (int l1398 = 0; (l1398 < 1024); l1398 = (l1398 + 1)) {
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
			fRec2043[l1411] = 0.0;
			
		}
		for (int l1412 = 0; (l1412 < 2); l1412 = (l1412 + 1)) {
			fRec2041[l1412] = 0.0;
			
		}
		for (int l1413 = 0; (l1413 < 2); l1413 = (l1413 + 1)) {
			fRec2040[l1413] = 0.0;
			
		}
		for (int l1414 = 0; (l1414 < 2); l1414 = (l1414 + 1)) {
			fRec2038[l1414] = 0.0;
			
		}
		for (int l1415 = 0; (l1415 < 2); l1415 = (l1415 + 1)) {
			fRec2046[l1415] = 0.0;
			
		}
		for (int l1416 = 0; (l1416 < 2); l1416 = (l1416 + 1)) {
			fRec2044[l1416] = 0.0;
			
		}
		for (int l1417 = 0; (l1417 < 2); l1417 = (l1417 + 1)) {
			fRec2061[l1417] = 0.0;
			
		}
		for (int l1418 = 0; (l1418 < 2); l1418 = (l1418 + 1)) {
			fRec2059[l1418] = 0.0;
			
		}
		for (int l1419 = 0; (l1419 < 2); l1419 = (l1419 + 1)) {
			fRec2058[l1419] = 0.0;
			
		}
		for (int l1420 = 0; (l1420 < 2); l1420 = (l1420 + 1)) {
			fRec2056[l1420] = 0.0;
			
		}
		for (int l1421 = 0; (l1421 < 2); l1421 = (l1421 + 1)) {
			fRec2055[l1421] = 0.0;
			
		}
		for (int l1422 = 0; (l1422 < 2); l1422 = (l1422 + 1)) {
			fRec2053[l1422] = 0.0;
			
		}
		for (int l1423 = 0; (l1423 < 2); l1423 = (l1423 + 1)) {
			fRec2052[l1423] = 0.0;
			
		}
		for (int l1424 = 0; (l1424 < 2); l1424 = (l1424 + 1)) {
			fRec2050[l1424] = 0.0;
			
		}
		for (int l1425 = 0; (l1425 < 2); l1425 = (l1425 + 1)) {
			fRec2049[l1425] = 0.0;
			
		}
		for (int l1426 = 0; (l1426 < 2); l1426 = (l1426 + 1)) {
			fRec2047[l1426] = 0.0;
			
		}
		for (int l1427 = 0; (l1427 < 2); l1427 = (l1427 + 1)) {
			fRec2070[l1427] = 0.0;
			
		}
		for (int l1428 = 0; (l1428 < 2); l1428 = (l1428 + 1)) {
			fRec2068[l1428] = 0.0;
			
		}
		for (int l1429 = 0; (l1429 < 2); l1429 = (l1429 + 1)) {
			fRec2067[l1429] = 0.0;
			
		}
		for (int l1430 = 0; (l1430 < 2); l1430 = (l1430 + 1)) {
			fRec2065[l1430] = 0.0;
			
		}
		for (int l1431 = 0; (l1431 < 2); l1431 = (l1431 + 1)) {
			fRec2064[l1431] = 0.0;
			
		}
		for (int l1432 = 0; (l1432 < 2); l1432 = (l1432 + 1)) {
			fRec2062[l1432] = 0.0;
			
		}
		for (int l1433 = 0; (l1433 < 2); l1433 = (l1433 + 1)) {
			fRec2082[l1433] = 0.0;
			
		}
		for (int l1434 = 0; (l1434 < 2); l1434 = (l1434 + 1)) {
			fRec2080[l1434] = 0.0;
			
		}
		for (int l1435 = 0; (l1435 < 2); l1435 = (l1435 + 1)) {
			fRec2079[l1435] = 0.0;
			
		}
		for (int l1436 = 0; (l1436 < 2); l1436 = (l1436 + 1)) {
			fRec2077[l1436] = 0.0;
			
		}
		for (int l1437 = 0; (l1437 < 2); l1437 = (l1437 + 1)) {
			fRec2076[l1437] = 0.0;
			
		}
		for (int l1438 = 0; (l1438 < 2); l1438 = (l1438 + 1)) {
			fRec2074[l1438] = 0.0;
			
		}
		for (int l1439 = 0; (l1439 < 2); l1439 = (l1439 + 1)) {
			fRec2073[l1439] = 0.0;
			
		}
		for (int l1440 = 0; (l1440 < 2); l1440 = (l1440 + 1)) {
			fRec2071[l1440] = 0.0;
			
		}
		for (int l1441 = 0; (l1441 < 1024); l1441 = (l1441 + 1)) {
			fVec30[l1441] = 0.0;
			
		}
		for (int l1442 = 0; (l1442 < 2); l1442 = (l1442 + 1)) {
			fRec2097[l1442] = 0.0;
			
		}
		for (int l1443 = 0; (l1443 < 2); l1443 = (l1443 + 1)) {
			fRec2095[l1443] = 0.0;
			
		}
		for (int l1444 = 0; (l1444 < 2); l1444 = (l1444 + 1)) {
			fRec2094[l1444] = 0.0;
			
		}
		for (int l1445 = 0; (l1445 < 2); l1445 = (l1445 + 1)) {
			fRec2092[l1445] = 0.0;
			
		}
		for (int l1446 = 0; (l1446 < 2); l1446 = (l1446 + 1)) {
			fRec2091[l1446] = 0.0;
			
		}
		for (int l1447 = 0; (l1447 < 2); l1447 = (l1447 + 1)) {
			fRec2089[l1447] = 0.0;
			
		}
		for (int l1448 = 0; (l1448 < 2); l1448 = (l1448 + 1)) {
			fRec2088[l1448] = 0.0;
			
		}
		for (int l1449 = 0; (l1449 < 2); l1449 = (l1449 + 1)) {
			fRec2086[l1449] = 0.0;
			
		}
		for (int l1450 = 0; (l1450 < 2); l1450 = (l1450 + 1)) {
			fRec2085[l1450] = 0.0;
			
		}
		for (int l1451 = 0; (l1451 < 2); l1451 = (l1451 + 1)) {
			fRec2083[l1451] = 0.0;
			
		}
		for (int l1452 = 0; (l1452 < 2); l1452 = (l1452 + 1)) {
			fRec2100[l1452] = 0.0;
			
		}
		for (int l1453 = 0; (l1453 < 2); l1453 = (l1453 + 1)) {
			fRec2098[l1453] = 0.0;
			
		}
		for (int l1454 = 0; (l1454 < 2); l1454 = (l1454 + 1)) {
			fRec2118[l1454] = 0.0;
			
		}
		for (int l1455 = 0; (l1455 < 2); l1455 = (l1455 + 1)) {
			fRec2116[l1455] = 0.0;
			
		}
		for (int l1456 = 0; (l1456 < 2); l1456 = (l1456 + 1)) {
			fRec2115[l1456] = 0.0;
			
		}
		for (int l1457 = 0; (l1457 < 2); l1457 = (l1457 + 1)) {
			fRec2113[l1457] = 0.0;
			
		}
		for (int l1458 = 0; (l1458 < 2); l1458 = (l1458 + 1)) {
			fRec2112[l1458] = 0.0;
			
		}
		for (int l1459 = 0; (l1459 < 2); l1459 = (l1459 + 1)) {
			fRec2110[l1459] = 0.0;
			
		}
		for (int l1460 = 0; (l1460 < 2); l1460 = (l1460 + 1)) {
			fRec2109[l1460] = 0.0;
			
		}
		for (int l1461 = 0; (l1461 < 2); l1461 = (l1461 + 1)) {
			fRec2107[l1461] = 0.0;
			
		}
		for (int l1462 = 0; (l1462 < 2); l1462 = (l1462 + 1)) {
			fRec2106[l1462] = 0.0;
			
		}
		for (int l1463 = 0; (l1463 < 2); l1463 = (l1463 + 1)) {
			fRec2104[l1463] = 0.0;
			
		}
		for (int l1464 = 0; (l1464 < 2); l1464 = (l1464 + 1)) {
			fRec2103[l1464] = 0.0;
			
		}
		for (int l1465 = 0; (l1465 < 2); l1465 = (l1465 + 1)) {
			fRec2101[l1465] = 0.0;
			
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
			fRec2136[l1470] = 0.0;
			
		}
		for (int l1471 = 0; (l1471 < 2); l1471 = (l1471 + 1)) {
			fRec2134[l1471] = 0.0;
			
		}
		for (int l1472 = 0; (l1472 < 2); l1472 = (l1472 + 1)) {
			fRec2133[l1472] = 0.0;
			
		}
		for (int l1473 = 0; (l1473 < 2); l1473 = (l1473 + 1)) {
			fRec2131[l1473] = 0.0;
			
		}
		for (int l1474 = 0; (l1474 < 2); l1474 = (l1474 + 1)) {
			fRec2130[l1474] = 0.0;
			
		}
		for (int l1475 = 0; (l1475 < 2); l1475 = (l1475 + 1)) {
			fRec2128[l1475] = 0.0;
			
		}
		for (int l1476 = 0; (l1476 < 2); l1476 = (l1476 + 1)) {
			fRec2127[l1476] = 0.0;
			
		}
		for (int l1477 = 0; (l1477 < 2); l1477 = (l1477 + 1)) {
			fRec2125[l1477] = 0.0;
			
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
			fRec2139[l1482] = 0.0;
			
		}
		for (int l1483 = 0; (l1483 < 2); l1483 = (l1483 + 1)) {
			fRec2137[l1483] = 0.0;
			
		}
		for (int l1484 = 0; (l1484 < 1024); l1484 = (l1484 + 1)) {
			fVec31[l1484] = 0.0;
			
		}
		for (int l1485 = 0; (l1485 < 2); l1485 = (l1485 + 1)) {
			fRec2154[l1485] = 0.0;
			
		}
		for (int l1486 = 0; (l1486 < 2); l1486 = (l1486 + 1)) {
			fRec2152[l1486] = 0.0;
			
		}
		for (int l1487 = 0; (l1487 < 2); l1487 = (l1487 + 1)) {
			fRec2151[l1487] = 0.0;
			
		}
		for (int l1488 = 0; (l1488 < 2); l1488 = (l1488 + 1)) {
			fRec2149[l1488] = 0.0;
			
		}
		for (int l1489 = 0; (l1489 < 2); l1489 = (l1489 + 1)) {
			fRec2148[l1489] = 0.0;
			
		}
		for (int l1490 = 0; (l1490 < 2); l1490 = (l1490 + 1)) {
			fRec2146[l1490] = 0.0;
			
		}
		for (int l1491 = 0; (l1491 < 2); l1491 = (l1491 + 1)) {
			fRec2160[l1491] = 0.0;
			
		}
		for (int l1492 = 0; (l1492 < 2); l1492 = (l1492 + 1)) {
			fRec2158[l1492] = 0.0;
			
		}
		for (int l1493 = 0; (l1493 < 2); l1493 = (l1493 + 1)) {
			fRec2157[l1493] = 0.0;
			
		}
		for (int l1494 = 0; (l1494 < 2); l1494 = (l1494 + 1)) {
			fRec2155[l1494] = 0.0;
			
		}
		for (int l1495 = 0; (l1495 < 2); l1495 = (l1495 + 1)) {
			fRec2178[l1495] = 0.0;
			
		}
		for (int l1496 = 0; (l1496 < 2); l1496 = (l1496 + 1)) {
			fRec2176[l1496] = 0.0;
			
		}
		for (int l1497 = 0; (l1497 < 2); l1497 = (l1497 + 1)) {
			fRec2175[l1497] = 0.0;
			
		}
		for (int l1498 = 0; (l1498 < 2); l1498 = (l1498 + 1)) {
			fRec2173[l1498] = 0.0;
			
		}
		for (int l1499 = 0; (l1499 < 2); l1499 = (l1499 + 1)) {
			fRec2172[l1499] = 0.0;
			
		}
		for (int l1500 = 0; (l1500 < 2); l1500 = (l1500 + 1)) {
			fRec2170[l1500] = 0.0;
			
		}
		for (int l1501 = 0; (l1501 < 2); l1501 = (l1501 + 1)) {
			fRec2169[l1501] = 0.0;
			
		}
		for (int l1502 = 0; (l1502 < 2); l1502 = (l1502 + 1)) {
			fRec2167[l1502] = 0.0;
			
		}
		for (int l1503 = 0; (l1503 < 2); l1503 = (l1503 + 1)) {
			fRec2166[l1503] = 0.0;
			
		}
		for (int l1504 = 0; (l1504 < 2); l1504 = (l1504 + 1)) {
			fRec2164[l1504] = 0.0;
			
		}
		for (int l1505 = 0; (l1505 < 2); l1505 = (l1505 + 1)) {
			fRec2163[l1505] = 0.0;
			
		}
		for (int l1506 = 0; (l1506 < 2); l1506 = (l1506 + 1)) {
			fRec2161[l1506] = 0.0;
			
		}
		for (int l1507 = 0; (l1507 < 2); l1507 = (l1507 + 1)) {
			fRec2193[l1507] = 0.0;
			
		}
		for (int l1508 = 0; (l1508 < 2); l1508 = (l1508 + 1)) {
			fRec2191[l1508] = 0.0;
			
		}
		for (int l1509 = 0; (l1509 < 2); l1509 = (l1509 + 1)) {
			fRec2190[l1509] = 0.0;
			
		}
		for (int l1510 = 0; (l1510 < 2); l1510 = (l1510 + 1)) {
			fRec2188[l1510] = 0.0;
			
		}
		for (int l1511 = 0; (l1511 < 2); l1511 = (l1511 + 1)) {
			fRec2187[l1511] = 0.0;
			
		}
		for (int l1512 = 0; (l1512 < 2); l1512 = (l1512 + 1)) {
			fRec2185[l1512] = 0.0;
			
		}
		for (int l1513 = 0; (l1513 < 2); l1513 = (l1513 + 1)) {
			fRec2184[l1513] = 0.0;
			
		}
		for (int l1514 = 0; (l1514 < 2); l1514 = (l1514 + 1)) {
			fRec2182[l1514] = 0.0;
			
		}
		for (int l1515 = 0; (l1515 < 2); l1515 = (l1515 + 1)) {
			fRec2181[l1515] = 0.0;
			
		}
		for (int l1516 = 0; (l1516 < 2); l1516 = (l1516 + 1)) {
			fRec2179[l1516] = 0.0;
			
		}
		for (int l1517 = 0; (l1517 < 2); l1517 = (l1517 + 1)) {
			fRec2196[l1517] = 0.0;
			
		}
		for (int l1518 = 0; (l1518 < 2); l1518 = (l1518 + 1)) {
			fRec2194[l1518] = 0.0;
			
		}
		for (int l1519 = 0; (l1519 < 2); l1519 = (l1519 + 1)) {
			fRec2208[l1519] = 0.0;
			
		}
		for (int l1520 = 0; (l1520 < 2); l1520 = (l1520 + 1)) {
			fRec2206[l1520] = 0.0;
			
		}
		for (int l1521 = 0; (l1521 < 2); l1521 = (l1521 + 1)) {
			fRec2205[l1521] = 0.0;
			
		}
		for (int l1522 = 0; (l1522 < 2); l1522 = (l1522 + 1)) {
			fRec2203[l1522] = 0.0;
			
		}
		for (int l1523 = 0; (l1523 < 2); l1523 = (l1523 + 1)) {
			fRec2202[l1523] = 0.0;
			
		}
		for (int l1524 = 0; (l1524 < 2); l1524 = (l1524 + 1)) {
			fRec2200[l1524] = 0.0;
			
		}
		for (int l1525 = 0; (l1525 < 2); l1525 = (l1525 + 1)) {
			fRec2199[l1525] = 0.0;
			
		}
		for (int l1526 = 0; (l1526 < 2); l1526 = (l1526 + 1)) {
			fRec2197[l1526] = 0.0;
			
		}
		for (int l1527 = 0; (l1527 < 1024); l1527 = (l1527 + 1)) {
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
		for (int l1570 = 0; (l1570 < 1024); l1570 = (l1570 + 1)) {
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
			fRec2331[l1607] = 0.0;
			
		}
		for (int l1608 = 0; (l1608 < 2); l1608 = (l1608 + 1)) {
			fRec2329[l1608] = 0.0;
			
		}
		for (int l1609 = 0; (l1609 < 2); l1609 = (l1609 + 1)) {
			fRec2328[l1609] = 0.0;
			
		}
		for (int l1610 = 0; (l1610 < 2); l1610 = (l1610 + 1)) {
			fRec2326[l1610] = 0.0;
			
		}
		for (int l1611 = 0; (l1611 < 2); l1611 = (l1611 + 1)) {
			fRec2334[l1611] = 0.0;
			
		}
		for (int l1612 = 0; (l1612 < 2); l1612 = (l1612 + 1)) {
			fRec2332[l1612] = 0.0;
			
		}
		for (int l1613 = 0; (l1613 < 1024); l1613 = (l1613 + 1)) {
			fVec34[l1613] = 0.0;
			
		}
		for (int l1614 = 0; (l1614 < 2); l1614 = (l1614 + 1)) {
			fRec2346[l1614] = 0.0;
			
		}
		for (int l1615 = 0; (l1615 < 2); l1615 = (l1615 + 1)) {
			fRec2344[l1615] = 0.0;
			
		}
		for (int l1616 = 0; (l1616 < 2); l1616 = (l1616 + 1)) {
			fRec2343[l1616] = 0.0;
			
		}
		for (int l1617 = 0; (l1617 < 2); l1617 = (l1617 + 1)) {
			fRec2341[l1617] = 0.0;
			
		}
		for (int l1618 = 0; (l1618 < 2); l1618 = (l1618 + 1)) {
			fRec2340[l1618] = 0.0;
			
		}
		for (int l1619 = 0; (l1619 < 2); l1619 = (l1619 + 1)) {
			fRec2338[l1619] = 0.0;
			
		}
		for (int l1620 = 0; (l1620 < 2); l1620 = (l1620 + 1)) {
			fRec2337[l1620] = 0.0;
			
		}
		for (int l1621 = 0; (l1621 < 2); l1621 = (l1621 + 1)) {
			fRec2335[l1621] = 0.0;
			
		}
		for (int l1622 = 0; (l1622 < 2); l1622 = (l1622 + 1)) {
			fRec2355[l1622] = 0.0;
			
		}
		for (int l1623 = 0; (l1623 < 2); l1623 = (l1623 + 1)) {
			fRec2353[l1623] = 0.0;
			
		}
		for (int l1624 = 0; (l1624 < 2); l1624 = (l1624 + 1)) {
			fRec2352[l1624] = 0.0;
			
		}
		for (int l1625 = 0; (l1625 < 2); l1625 = (l1625 + 1)) {
			fRec2350[l1625] = 0.0;
			
		}
		for (int l1626 = 0; (l1626 < 2); l1626 = (l1626 + 1)) {
			fRec2349[l1626] = 0.0;
			
		}
		for (int l1627 = 0; (l1627 < 2); l1627 = (l1627 + 1)) {
			fRec2347[l1627] = 0.0;
			
		}
		for (int l1628 = 0; (l1628 < 2); l1628 = (l1628 + 1)) {
			fRec2361[l1628] = 0.0;
			
		}
		for (int l1629 = 0; (l1629 < 2); l1629 = (l1629 + 1)) {
			fRec2359[l1629] = 0.0;
			
		}
		for (int l1630 = 0; (l1630 < 2); l1630 = (l1630 + 1)) {
			fRec2358[l1630] = 0.0;
			
		}
		for (int l1631 = 0; (l1631 < 2); l1631 = (l1631 + 1)) {
			fRec2356[l1631] = 0.0;
			
		}
		for (int l1632 = 0; (l1632 < 2); l1632 = (l1632 + 1)) {
			fRec2364[l1632] = 0.0;
			
		}
		for (int l1633 = 0; (l1633 < 2); l1633 = (l1633 + 1)) {
			fRec2362[l1633] = 0.0;
			
		}
		for (int l1634 = 0; (l1634 < 2); l1634 = (l1634 + 1)) {
			fRec2379[l1634] = 0.0;
			
		}
		for (int l1635 = 0; (l1635 < 2); l1635 = (l1635 + 1)) {
			fRec2377[l1635] = 0.0;
			
		}
		for (int l1636 = 0; (l1636 < 2); l1636 = (l1636 + 1)) {
			fRec2376[l1636] = 0.0;
			
		}
		for (int l1637 = 0; (l1637 < 2); l1637 = (l1637 + 1)) {
			fRec2374[l1637] = 0.0;
			
		}
		for (int l1638 = 0; (l1638 < 2); l1638 = (l1638 + 1)) {
			fRec2373[l1638] = 0.0;
			
		}
		for (int l1639 = 0; (l1639 < 2); l1639 = (l1639 + 1)) {
			fRec2371[l1639] = 0.0;
			
		}
		for (int l1640 = 0; (l1640 < 2); l1640 = (l1640 + 1)) {
			fRec2370[l1640] = 0.0;
			
		}
		for (int l1641 = 0; (l1641 < 2); l1641 = (l1641 + 1)) {
			fRec2368[l1641] = 0.0;
			
		}
		for (int l1642 = 0; (l1642 < 2); l1642 = (l1642 + 1)) {
			fRec2367[l1642] = 0.0;
			
		}
		for (int l1643 = 0; (l1643 < 2); l1643 = (l1643 + 1)) {
			fRec2365[l1643] = 0.0;
			
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
			fRec2382[l1654] = 0.0;
			
		}
		for (int l1655 = 0; (l1655 < 2); l1655 = (l1655 + 1)) {
			fRec2380[l1655] = 0.0;
			
		}
		for (int l1656 = 0; (l1656 < 1024); l1656 = (l1656 + 1)) {
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
			fRec2436[l1679] = 0.0;
			
		}
		for (int l1680 = 0; (l1680 < 2); l1680 = (l1680 + 1)) {
			fRec2434[l1680] = 0.0;
			
		}
		for (int l1681 = 0; (l1681 < 2); l1681 = (l1681 + 1)) {
			fRec2433[l1681] = 0.0;
			
		}
		for (int l1682 = 0; (l1682 < 2); l1682 = (l1682 + 1)) {
			fRec2431[l1682] = 0.0;
			
		}
		for (int l1683 = 0; (l1683 < 2); l1683 = (l1683 + 1)) {
			fRec2448[l1683] = 0.0;
			
		}
		for (int l1684 = 0; (l1684 < 2); l1684 = (l1684 + 1)) {
			fRec2446[l1684] = 0.0;
			
		}
		for (int l1685 = 0; (l1685 < 2); l1685 = (l1685 + 1)) {
			fRec2445[l1685] = 0.0;
			
		}
		for (int l1686 = 0; (l1686 < 2); l1686 = (l1686 + 1)) {
			fRec2443[l1686] = 0.0;
			
		}
		for (int l1687 = 0; (l1687 < 2); l1687 = (l1687 + 1)) {
			fRec2442[l1687] = 0.0;
			
		}
		for (int l1688 = 0; (l1688 < 2); l1688 = (l1688 + 1)) {
			fRec2440[l1688] = 0.0;
			
		}
		for (int l1689 = 0; (l1689 < 2); l1689 = (l1689 + 1)) {
			fRec2439[l1689] = 0.0;
			
		}
		for (int l1690 = 0; (l1690 < 2); l1690 = (l1690 + 1)) {
			fRec2437[l1690] = 0.0;
			
		}
		for (int l1691 = 0; (l1691 < 2); l1691 = (l1691 + 1)) {
			fRec2457[l1691] = 0.0;
			
		}
		for (int l1692 = 0; (l1692 < 2); l1692 = (l1692 + 1)) {
			fRec2455[l1692] = 0.0;
			
		}
		for (int l1693 = 0; (l1693 < 2); l1693 = (l1693 + 1)) {
			fRec2454[l1693] = 0.0;
			
		}
		for (int l1694 = 0; (l1694 < 2); l1694 = (l1694 + 1)) {
			fRec2452[l1694] = 0.0;
			
		}
		for (int l1695 = 0; (l1695 < 2); l1695 = (l1695 + 1)) {
			fRec2451[l1695] = 0.0;
			
		}
		for (int l1696 = 0; (l1696 < 2); l1696 = (l1696 + 1)) {
			fRec2449[l1696] = 0.0;
			
		}
		for (int l1697 = 0; (l1697 < 2); l1697 = (l1697 + 1)) {
			fRec2460[l1697] = 0.0;
			
		}
		for (int l1698 = 0; (l1698 < 2); l1698 = (l1698 + 1)) {
			fRec2458[l1698] = 0.0;
			
		}
		for (int l1699 = 0; (l1699 < 1024); l1699 = (l1699 + 1)) {
			fVec36[l1699] = 0.0;
			
		}
		for (int l1700 = 0; (l1700 < 2); l1700 = (l1700 + 1)) {
			fRec2475[l1700] = 0.0;
			
		}
		for (int l1701 = 0; (l1701 < 2); l1701 = (l1701 + 1)) {
			fRec2473[l1701] = 0.0;
			
		}
		for (int l1702 = 0; (l1702 < 2); l1702 = (l1702 + 1)) {
			fRec2472[l1702] = 0.0;
			
		}
		for (int l1703 = 0; (l1703 < 2); l1703 = (l1703 + 1)) {
			fRec2470[l1703] = 0.0;
			
		}
		for (int l1704 = 0; (l1704 < 2); l1704 = (l1704 + 1)) {
			fRec2469[l1704] = 0.0;
			
		}
		for (int l1705 = 0; (l1705 < 2); l1705 = (l1705 + 1)) {
			fRec2467[l1705] = 0.0;
			
		}
		for (int l1706 = 0; (l1706 < 2); l1706 = (l1706 + 1)) {
			fRec2466[l1706] = 0.0;
			
		}
		for (int l1707 = 0; (l1707 < 2); l1707 = (l1707 + 1)) {
			fRec2464[l1707] = 0.0;
			
		}
		for (int l1708 = 0; (l1708 < 2); l1708 = (l1708 + 1)) {
			fRec2463[l1708] = 0.0;
			
		}
		for (int l1709 = 0; (l1709 < 2); l1709 = (l1709 + 1)) {
			fRec2461[l1709] = 0.0;
			
		}
		for (int l1710 = 0; (l1710 < 2); l1710 = (l1710 + 1)) {
			fRec2487[l1710] = 0.0;
			
		}
		for (int l1711 = 0; (l1711 < 2); l1711 = (l1711 + 1)) {
			fRec2485[l1711] = 0.0;
			
		}
		for (int l1712 = 0; (l1712 < 2); l1712 = (l1712 + 1)) {
			fRec2484[l1712] = 0.0;
			
		}
		for (int l1713 = 0; (l1713 < 2); l1713 = (l1713 + 1)) {
			fRec2482[l1713] = 0.0;
			
		}
		for (int l1714 = 0; (l1714 < 2); l1714 = (l1714 + 1)) {
			fRec2481[l1714] = 0.0;
			
		}
		for (int l1715 = 0; (l1715 < 2); l1715 = (l1715 + 1)) {
			fRec2479[l1715] = 0.0;
			
		}
		for (int l1716 = 0; (l1716 < 2); l1716 = (l1716 + 1)) {
			fRec2478[l1716] = 0.0;
			
		}
		for (int l1717 = 0; (l1717 < 2); l1717 = (l1717 + 1)) {
			fRec2476[l1717] = 0.0;
			
		}
		for (int l1718 = 0; (l1718 < 2); l1718 = (l1718 + 1)) {
			fRec2496[l1718] = 0.0;
			
		}
		for (int l1719 = 0; (l1719 < 2); l1719 = (l1719 + 1)) {
			fRec2494[l1719] = 0.0;
			
		}
		for (int l1720 = 0; (l1720 < 2); l1720 = (l1720 + 1)) {
			fRec2493[l1720] = 0.0;
			
		}
		for (int l1721 = 0; (l1721 < 2); l1721 = (l1721 + 1)) {
			fRec2491[l1721] = 0.0;
			
		}
		for (int l1722 = 0; (l1722 < 2); l1722 = (l1722 + 1)) {
			fRec2490[l1722] = 0.0;
			
		}
		for (int l1723 = 0; (l1723 < 2); l1723 = (l1723 + 1)) {
			fRec2488[l1723] = 0.0;
			
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
			fRec2505[l1728] = 0.0;
			
		}
		for (int l1729 = 0; (l1729 < 2); l1729 = (l1729 + 1)) {
			fRec2503[l1729] = 0.0;
			
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
			fRec2508[l1740] = 0.0;
			
		}
		for (int l1741 = 0; (l1741 < 2); l1741 = (l1741 + 1)) {
			fRec2506[l1741] = 0.0;
			
		}
		for (int l1742 = 0; (l1742 < 1024); l1742 = (l1742 + 1)) {
			fVec37[l1742] = 0.0;
			
		}
		for (int l1743 = 0; (l1743 < 2); l1743 = (l1743 + 1)) {
			fRec2526[l1743] = 0.0;
			
		}
		for (int l1744 = 0; (l1744 < 2); l1744 = (l1744 + 1)) {
			fRec2524[l1744] = 0.0;
			
		}
		for (int l1745 = 0; (l1745 < 2); l1745 = (l1745 + 1)) {
			fRec2544[l1745] = 0.0;
			
		}
		for (int l1746 = 0; (l1746 < 2); l1746 = (l1746 + 1)) {
			fRec2542[l1746] = 0.0;
			
		}
		for (int l1747 = 0; (l1747 < 2); l1747 = (l1747 + 1)) {
			fRec2541[l1747] = 0.0;
			
		}
		for (int l1748 = 0; (l1748 < 2); l1748 = (l1748 + 1)) {
			fRec2539[l1748] = 0.0;
			
		}
		for (int l1749 = 0; (l1749 < 2); l1749 = (l1749 + 1)) {
			fRec2538[l1749] = 0.0;
			
		}
		for (int l1750 = 0; (l1750 < 2); l1750 = (l1750 + 1)) {
			fRec2536[l1750] = 0.0;
			
		}
		for (int l1751 = 0; (l1751 < 2); l1751 = (l1751 + 1)) {
			fRec2535[l1751] = 0.0;
			
		}
		for (int l1752 = 0; (l1752 < 2); l1752 = (l1752 + 1)) {
			fRec2533[l1752] = 0.0;
			
		}
		for (int l1753 = 0; (l1753 < 2); l1753 = (l1753 + 1)) {
			fRec2532[l1753] = 0.0;
			
		}
		for (int l1754 = 0; (l1754 < 2); l1754 = (l1754 + 1)) {
			fRec2530[l1754] = 0.0;
			
		}
		for (int l1755 = 0; (l1755 < 2); l1755 = (l1755 + 1)) {
			fRec2529[l1755] = 0.0;
			
		}
		for (int l1756 = 0; (l1756 < 2); l1756 = (l1756 + 1)) {
			fRec2527[l1756] = 0.0;
			
		}
		for (int l1757 = 0; (l1757 < 2); l1757 = (l1757 + 1)) {
			fRec2559[l1757] = 0.0;
			
		}
		for (int l1758 = 0; (l1758 < 2); l1758 = (l1758 + 1)) {
			fRec2557[l1758] = 0.0;
			
		}
		for (int l1759 = 0; (l1759 < 2); l1759 = (l1759 + 1)) {
			fRec2556[l1759] = 0.0;
			
		}
		for (int l1760 = 0; (l1760 < 2); l1760 = (l1760 + 1)) {
			fRec2554[l1760] = 0.0;
			
		}
		for (int l1761 = 0; (l1761 < 2); l1761 = (l1761 + 1)) {
			fRec2553[l1761] = 0.0;
			
		}
		for (int l1762 = 0; (l1762 < 2); l1762 = (l1762 + 1)) {
			fRec2551[l1762] = 0.0;
			
		}
		for (int l1763 = 0; (l1763 < 2); l1763 = (l1763 + 1)) {
			fRec2550[l1763] = 0.0;
			
		}
		for (int l1764 = 0; (l1764 < 2); l1764 = (l1764 + 1)) {
			fRec2548[l1764] = 0.0;
			
		}
		for (int l1765 = 0; (l1765 < 2); l1765 = (l1765 + 1)) {
			fRec2547[l1765] = 0.0;
			
		}
		for (int l1766 = 0; (l1766 < 2); l1766 = (l1766 + 1)) {
			fRec2545[l1766] = 0.0;
			
		}
		for (int l1767 = 0; (l1767 < 2); l1767 = (l1767 + 1)) {
			fRec2571[l1767] = 0.0;
			
		}
		for (int l1768 = 0; (l1768 < 2); l1768 = (l1768 + 1)) {
			fRec2569[l1768] = 0.0;
			
		}
		for (int l1769 = 0; (l1769 < 2); l1769 = (l1769 + 1)) {
			fRec2568[l1769] = 0.0;
			
		}
		for (int l1770 = 0; (l1770 < 2); l1770 = (l1770 + 1)) {
			fRec2566[l1770] = 0.0;
			
		}
		for (int l1771 = 0; (l1771 < 2); l1771 = (l1771 + 1)) {
			fRec2565[l1771] = 0.0;
			
		}
		for (int l1772 = 0; (l1772 < 2); l1772 = (l1772 + 1)) {
			fRec2563[l1772] = 0.0;
			
		}
		for (int l1773 = 0; (l1773 < 2); l1773 = (l1773 + 1)) {
			fRec2562[l1773] = 0.0;
			
		}
		for (int l1774 = 0; (l1774 < 2); l1774 = (l1774 + 1)) {
			fRec2560[l1774] = 0.0;
			
		}
		for (int l1775 = 0; (l1775 < 2); l1775 = (l1775 + 1)) {
			fRec2580[l1775] = 0.0;
			
		}
		for (int l1776 = 0; (l1776 < 2); l1776 = (l1776 + 1)) {
			fRec2578[l1776] = 0.0;
			
		}
		for (int l1777 = 0; (l1777 < 2); l1777 = (l1777 + 1)) {
			fRec2577[l1777] = 0.0;
			
		}
		for (int l1778 = 0; (l1778 < 2); l1778 = (l1778 + 1)) {
			fRec2575[l1778] = 0.0;
			
		}
		for (int l1779 = 0; (l1779 < 2); l1779 = (l1779 + 1)) {
			fRec2574[l1779] = 0.0;
			
		}
		for (int l1780 = 0; (l1780 < 2); l1780 = (l1780 + 1)) {
			fRec2572[l1780] = 0.0;
			
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
		for (int l1785 = 0; (l1785 < 1024); l1785 = (l1785 + 1)) {
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
		for (int l1828 = 0; (l1828 < 1024); l1828 = (l1828 + 1)) {
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
			fRec2673[l1841] = 0.0;
			
		}
		for (int l1842 = 0; (l1842 < 2); l1842 = (l1842 + 1)) {
			fRec2671[l1842] = 0.0;
			
		}
		for (int l1843 = 0; (l1843 < 2); l1843 = (l1843 + 1)) {
			fRec2670[l1843] = 0.0;
			
		}
		for (int l1844 = 0; (l1844 < 2); l1844 = (l1844 + 1)) {
			fRec2668[l1844] = 0.0;
			
		}
		for (int l1845 = 0; (l1845 < 2); l1845 = (l1845 + 1)) {
			fRec2676[l1845] = 0.0;
			
		}
		for (int l1846 = 0; (l1846 < 2); l1846 = (l1846 + 1)) {
			fRec2674[l1846] = 0.0;
			
		}
		for (int l1847 = 0; (l1847 < 2); l1847 = (l1847 + 1)) {
			fRec2691[l1847] = 0.0;
			
		}
		for (int l1848 = 0; (l1848 < 2); l1848 = (l1848 + 1)) {
			fRec2689[l1848] = 0.0;
			
		}
		for (int l1849 = 0; (l1849 < 2); l1849 = (l1849 + 1)) {
			fRec2688[l1849] = 0.0;
			
		}
		for (int l1850 = 0; (l1850 < 2); l1850 = (l1850 + 1)) {
			fRec2686[l1850] = 0.0;
			
		}
		for (int l1851 = 0; (l1851 < 2); l1851 = (l1851 + 1)) {
			fRec2685[l1851] = 0.0;
			
		}
		for (int l1852 = 0; (l1852 < 2); l1852 = (l1852 + 1)) {
			fRec2683[l1852] = 0.0;
			
		}
		for (int l1853 = 0; (l1853 < 2); l1853 = (l1853 + 1)) {
			fRec2682[l1853] = 0.0;
			
		}
		for (int l1854 = 0; (l1854 < 2); l1854 = (l1854 + 1)) {
			fRec2680[l1854] = 0.0;
			
		}
		for (int l1855 = 0; (l1855 < 2); l1855 = (l1855 + 1)) {
			fRec2679[l1855] = 0.0;
			
		}
		for (int l1856 = 0; (l1856 < 2); l1856 = (l1856 + 1)) {
			fRec2677[l1856] = 0.0;
			
		}
		for (int l1857 = 0; (l1857 < 2); l1857 = (l1857 + 1)) {
			fRec2700[l1857] = 0.0;
			
		}
		for (int l1858 = 0; (l1858 < 2); l1858 = (l1858 + 1)) {
			fRec2698[l1858] = 0.0;
			
		}
		for (int l1859 = 0; (l1859 < 2); l1859 = (l1859 + 1)) {
			fRec2697[l1859] = 0.0;
			
		}
		for (int l1860 = 0; (l1860 < 2); l1860 = (l1860 + 1)) {
			fRec2695[l1860] = 0.0;
			
		}
		for (int l1861 = 0; (l1861 < 2); l1861 = (l1861 + 1)) {
			fRec2694[l1861] = 0.0;
			
		}
		for (int l1862 = 0; (l1862 < 2); l1862 = (l1862 + 1)) {
			fRec2692[l1862] = 0.0;
			
		}
		for (int l1863 = 0; (l1863 < 2); l1863 = (l1863 + 1)) {
			fRec2712[l1863] = 0.0;
			
		}
		for (int l1864 = 0; (l1864 < 2); l1864 = (l1864 + 1)) {
			fRec2710[l1864] = 0.0;
			
		}
		for (int l1865 = 0; (l1865 < 2); l1865 = (l1865 + 1)) {
			fRec2709[l1865] = 0.0;
			
		}
		for (int l1866 = 0; (l1866 < 2); l1866 = (l1866 + 1)) {
			fRec2707[l1866] = 0.0;
			
		}
		for (int l1867 = 0; (l1867 < 2); l1867 = (l1867 + 1)) {
			fRec2706[l1867] = 0.0;
			
		}
		for (int l1868 = 0; (l1868 < 2); l1868 = (l1868 + 1)) {
			fRec2704[l1868] = 0.0;
			
		}
		for (int l1869 = 0; (l1869 < 2); l1869 = (l1869 + 1)) {
			fRec2703[l1869] = 0.0;
			
		}
		for (int l1870 = 0; (l1870 < 2); l1870 = (l1870 + 1)) {
			fRec2701[l1870] = 0.0;
			
		}
		for (int l1871 = 0; (l1871 < 1024); l1871 = (l1871 + 1)) {
			fVec40[l1871] = 0.0;
			
		}
		for (int l1872 = 0; (l1872 < 2); l1872 = (l1872 + 1)) {
			fRec2727[l1872] = 0.0;
			
		}
		for (int l1873 = 0; (l1873 < 2); l1873 = (l1873 + 1)) {
			fRec2725[l1873] = 0.0;
			
		}
		for (int l1874 = 0; (l1874 < 2); l1874 = (l1874 + 1)) {
			fRec2724[l1874] = 0.0;
			
		}
		for (int l1875 = 0; (l1875 < 2); l1875 = (l1875 + 1)) {
			fRec2722[l1875] = 0.0;
			
		}
		for (int l1876 = 0; (l1876 < 2); l1876 = (l1876 + 1)) {
			fRec2721[l1876] = 0.0;
			
		}
		for (int l1877 = 0; (l1877 < 2); l1877 = (l1877 + 1)) {
			fRec2719[l1877] = 0.0;
			
		}
		for (int l1878 = 0; (l1878 < 2); l1878 = (l1878 + 1)) {
			fRec2718[l1878] = 0.0;
			
		}
		for (int l1879 = 0; (l1879 < 2); l1879 = (l1879 + 1)) {
			fRec2716[l1879] = 0.0;
			
		}
		for (int l1880 = 0; (l1880 < 2); l1880 = (l1880 + 1)) {
			fRec2715[l1880] = 0.0;
			
		}
		for (int l1881 = 0; (l1881 < 2); l1881 = (l1881 + 1)) {
			fRec2713[l1881] = 0.0;
			
		}
		for (int l1882 = 0; (l1882 < 2); l1882 = (l1882 + 1)) {
			fRec2739[l1882] = 0.0;
			
		}
		for (int l1883 = 0; (l1883 < 2); l1883 = (l1883 + 1)) {
			fRec2737[l1883] = 0.0;
			
		}
		for (int l1884 = 0; (l1884 < 2); l1884 = (l1884 + 1)) {
			fRec2736[l1884] = 0.0;
			
		}
		for (int l1885 = 0; (l1885 < 2); l1885 = (l1885 + 1)) {
			fRec2734[l1885] = 0.0;
			
		}
		for (int l1886 = 0; (l1886 < 2); l1886 = (l1886 + 1)) {
			fRec2733[l1886] = 0.0;
			
		}
		for (int l1887 = 0; (l1887 < 2); l1887 = (l1887 + 1)) {
			fRec2731[l1887] = 0.0;
			
		}
		for (int l1888 = 0; (l1888 < 2); l1888 = (l1888 + 1)) {
			fRec2730[l1888] = 0.0;
			
		}
		for (int l1889 = 0; (l1889 < 2); l1889 = (l1889 + 1)) {
			fRec2728[l1889] = 0.0;
			
		}
		for (int l1890 = 0; (l1890 < 2); l1890 = (l1890 + 1)) {
			fRec2748[l1890] = 0.0;
			
		}
		for (int l1891 = 0; (l1891 < 2); l1891 = (l1891 + 1)) {
			fRec2746[l1891] = 0.0;
			
		}
		for (int l1892 = 0; (l1892 < 2); l1892 = (l1892 + 1)) {
			fRec2745[l1892] = 0.0;
			
		}
		for (int l1893 = 0; (l1893 < 2); l1893 = (l1893 + 1)) {
			fRec2743[l1893] = 0.0;
			
		}
		for (int l1894 = 0; (l1894 < 2); l1894 = (l1894 + 1)) {
			fRec2742[l1894] = 0.0;
			
		}
		for (int l1895 = 0; (l1895 < 2); l1895 = (l1895 + 1)) {
			fRec2740[l1895] = 0.0;
			
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
			fRec2757[l1900] = 0.0;
			
		}
		for (int l1901 = 0; (l1901 < 2); l1901 = (l1901 + 1)) {
			fRec2755[l1901] = 0.0;
			
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
			fRec2760[l1912] = 0.0;
			
		}
		for (int l1913 = 0; (l1913 < 2); l1913 = (l1913 + 1)) {
			fRec2758[l1913] = 0.0;
			
		}
		for (int l1914 = 0; (l1914 < 1024); l1914 = (l1914 + 1)) {
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
		for (int l1957 = 0; (l1957 < 1024); l1957 = (l1957 + 1)) {
			fVec42[l1957] = 0.0;
			
		}
		for (int l1958 = 0; (l1958 < 2); l1958 = (l1958 + 1)) {
			fRec2853[l1958] = 0.0;
			
		}
		for (int l1959 = 0; (l1959 < 2); l1959 = (l1959 + 1)) {
			fRec2851[l1959] = 0.0;
			
		}
		for (int l1960 = 0; (l1960 < 2); l1960 = (l1960 + 1)) {
			fRec2850[l1960] = 0.0;
			
		}
		for (int l1961 = 0; (l1961 < 2); l1961 = (l1961 + 1)) {
			fRec2848[l1961] = 0.0;
			
		}
		for (int l1962 = 0; (l1962 < 2); l1962 = (l1962 + 1)) {
			fRec2847[l1962] = 0.0;
			
		}
		for (int l1963 = 0; (l1963 < 2); l1963 = (l1963 + 1)) {
			fRec2845[l1963] = 0.0;
			
		}
		for (int l1964 = 0; (l1964 < 2); l1964 = (l1964 + 1)) {
			fRec2844[l1964] = 0.0;
			
		}
		for (int l1965 = 0; (l1965 < 2); l1965 = (l1965 + 1)) {
			fRec2842[l1965] = 0.0;
			
		}
		for (int l1966 = 0; (l1966 < 2); l1966 = (l1966 + 1)) {
			fRec2841[l1966] = 0.0;
			
		}
		for (int l1967 = 0; (l1967 < 2); l1967 = (l1967 + 1)) {
			fRec2839[l1967] = 0.0;
			
		}
		for (int l1968 = 0; (l1968 < 2); l1968 = (l1968 + 1)) {
			fRec2862[l1968] = 0.0;
			
		}
		for (int l1969 = 0; (l1969 < 2); l1969 = (l1969 + 1)) {
			fRec2860[l1969] = 0.0;
			
		}
		for (int l1970 = 0; (l1970 < 2); l1970 = (l1970 + 1)) {
			fRec2859[l1970] = 0.0;
			
		}
		for (int l1971 = 0; (l1971 < 2); l1971 = (l1971 + 1)) {
			fRec2857[l1971] = 0.0;
			
		}
		for (int l1972 = 0; (l1972 < 2); l1972 = (l1972 + 1)) {
			fRec2856[l1972] = 0.0;
			
		}
		for (int l1973 = 0; (l1973 < 2); l1973 = (l1973 + 1)) {
			fRec2854[l1973] = 0.0;
			
		}
		for (int l1974 = 0; (l1974 < 2); l1974 = (l1974 + 1)) {
			fRec2868[l1974] = 0.0;
			
		}
		for (int l1975 = 0; (l1975 < 2); l1975 = (l1975 + 1)) {
			fRec2866[l1975] = 0.0;
			
		}
		for (int l1976 = 0; (l1976 < 2); l1976 = (l1976 + 1)) {
			fRec2865[l1976] = 0.0;
			
		}
		for (int l1977 = 0; (l1977 < 2); l1977 = (l1977 + 1)) {
			fRec2863[l1977] = 0.0;
			
		}
		for (int l1978 = 0; (l1978 < 2); l1978 = (l1978 + 1)) {
			fRec2871[l1978] = 0.0;
			
		}
		for (int l1979 = 0; (l1979 < 2); l1979 = (l1979 + 1)) {
			fRec2869[l1979] = 0.0;
			
		}
		for (int l1980 = 0; (l1980 < 2); l1980 = (l1980 + 1)) {
			fRec2889[l1980] = 0.0;
			
		}
		for (int l1981 = 0; (l1981 < 2); l1981 = (l1981 + 1)) {
			fRec2887[l1981] = 0.0;
			
		}
		for (int l1982 = 0; (l1982 < 2); l1982 = (l1982 + 1)) {
			fRec2886[l1982] = 0.0;
			
		}
		for (int l1983 = 0; (l1983 < 2); l1983 = (l1983 + 1)) {
			fRec2884[l1983] = 0.0;
			
		}
		for (int l1984 = 0; (l1984 < 2); l1984 = (l1984 + 1)) {
			fRec2883[l1984] = 0.0;
			
		}
		for (int l1985 = 0; (l1985 < 2); l1985 = (l1985 + 1)) {
			fRec2881[l1985] = 0.0;
			
		}
		for (int l1986 = 0; (l1986 < 2); l1986 = (l1986 + 1)) {
			fRec2880[l1986] = 0.0;
			
		}
		for (int l1987 = 0; (l1987 < 2); l1987 = (l1987 + 1)) {
			fRec2878[l1987] = 0.0;
			
		}
		for (int l1988 = 0; (l1988 < 2); l1988 = (l1988 + 1)) {
			fRec2877[l1988] = 0.0;
			
		}
		for (int l1989 = 0; (l1989 < 2); l1989 = (l1989 + 1)) {
			fRec2875[l1989] = 0.0;
			
		}
		for (int l1990 = 0; (l1990 < 2); l1990 = (l1990 + 1)) {
			fRec2874[l1990] = 0.0;
			
		}
		for (int l1991 = 0; (l1991 < 2); l1991 = (l1991 + 1)) {
			fRec2872[l1991] = 0.0;
			
		}
		for (int l1992 = 0; (l1992 < 2); l1992 = (l1992 + 1)) {
			fRec2901[l1992] = 0.0;
			
		}
		for (int l1993 = 0; (l1993 < 2); l1993 = (l1993 + 1)) {
			fRec2899[l1993] = 0.0;
			
		}
		for (int l1994 = 0; (l1994 < 2); l1994 = (l1994 + 1)) {
			fRec2898[l1994] = 0.0;
			
		}
		for (int l1995 = 0; (l1995 < 2); l1995 = (l1995 + 1)) {
			fRec2896[l1995] = 0.0;
			
		}
		for (int l1996 = 0; (l1996 < 2); l1996 = (l1996 + 1)) {
			fRec2895[l1996] = 0.0;
			
		}
		for (int l1997 = 0; (l1997 < 2); l1997 = (l1997 + 1)) {
			fRec2893[l1997] = 0.0;
			
		}
		for (int l1998 = 0; (l1998 < 2); l1998 = (l1998 + 1)) {
			fRec2892[l1998] = 0.0;
			
		}
		for (int l1999 = 0; (l1999 < 2); l1999 = (l1999 + 1)) {
			fRec2890[l1999] = 0.0;
			
		}
		for (int l2000 = 0; (l2000 < 1024); l2000 = (l2000 + 1)) {
			fVec43[l2000] = 0.0;
			
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
		ui_interface->openVerticalBox("KMHLS_FullSetup_7h7p_full_6");
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
			fRec2[0] = (double(input58[i]) - (((fTemp2 * fRec2[2]) + (2.0 * (fTemp3 * fRec2[1]))) / fTemp4));
			fRec3[0] = (fSlow2 + (0.999 * fRec3[1]));
			double fTemp5 = (fRec3[0] * fTemp4);
			double fTemp6 = (0.0 - (2.0 / fTemp4));
			double fTemp7 = (((fTemp1 * (fRec2[2] + (fRec2[0] + (2.0 * fRec2[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec2[1]) + ((fRec2[0] + fRec2[2]) / fTemp4))))));
			fRec4[0] = (double(input61[i]) - (((fTemp2 * fRec4[2]) + (2.0 * (fTemp3 * fRec4[1]))) / fTemp4));
			double fTemp8 = (((fTemp1 * (fRec4[2] + (fRec4[0] + (2.0 * fRec4[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec4[1]) + ((fRec4[0] + fRec4[2]) / fTemp4))))));
			fRec5[0] = (double(input60[i]) - (((fTemp2 * fRec5[2]) + (2.0 * (fTemp3 * fRec5[1]))) / fTemp4));
			double fTemp9 = (((fTemp1 * (fRec5[2] + (fRec5[0] + (2.0 * fRec5[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec5[1]) + ((fRec5[0] + fRec5[2]) / fTemp4))))));
			fRec6[0] = (double(input59[i]) - (((fTemp2 * fRec6[2]) + (2.0 * (fTemp3 * fRec6[1]))) / fTemp4));
			double fTemp10 = (((fTemp1 * (fRec6[2] + (fRec6[0] + (2.0 * fRec6[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec6[1]) + ((fRec6[0] + fRec6[2]) / fTemp4))))));
			fRec7[0] = (double(input57[i]) - (((fTemp2 * fRec7[2]) + (2.0 * (fTemp3 * fRec7[1]))) / fTemp4));
			double fTemp11 = (((fTemp1 * (fRec7[2] + (fRec7[0] + (2.0 * fRec7[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec7[1]) + ((fRec7[0] + fRec7[2]) / fTemp4))))));
			fRec8[0] = (double(input55[i]) - (((fTemp2 * fRec8[2]) + (2.0 * (fTemp3 * fRec8[1]))) / fTemp4));
			double fTemp12 = (((fTemp1 * (fRec8[2] + (fRec8[0] + (2.0 * fRec8[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec8[1]) + ((fRec8[0] + fRec8[2]) / fTemp4))))));
			fRec9[0] = (double(input0[i]) - (((fRec9[2] * fTemp2) + (2.0 * (fRec9[1] * fTemp3))) / fTemp4));
			double fTemp13 = (((fTemp1 * (fRec9[2] + (fRec9[0] + (2.0 * fRec9[1])))) / fTemp5) + (fRec3[0] * (0.0 - ((fRec9[1] * fTemp6) + ((fRec9[0] + fRec9[2]) / fTemp4)))));
			fRec22[0] = (double(input16[i]) - (((fTemp2 * fRec22[2]) + (2.0 * (fTemp3 * fRec22[1]))) / fTemp4));
			double fTemp14 = (((fTemp1 * (fRec22[2] + (fRec22[0] + (2.0 * fRec22[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec22[1]) + ((fRec22[0] + fRec22[2]) / fTemp4))))));
			fRec23[0] = (double(input17[i]) - (((fTemp2 * fRec23[2]) + (2.0 * (fTemp3 * fRec23[1]))) / fTemp4));
			double fTemp15 = (((fTemp1 * (fRec23[2] + (fRec23[0] + (2.0 * fRec23[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec23[1]) + ((fRec23[0] + fRec23[2]) / fTemp4))))));
			fRec24[0] = (double(input20[i]) - (((fTemp2 * fRec24[2]) + (2.0 * (fTemp3 * fRec24[1]))) / fTemp4));
			double fTemp16 = (((fTemp1 * (fRec24[2] + (fRec24[0] + (2.0 * fRec24[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec24[1]) + ((fRec24[0] + fRec24[2]) / fTemp4))))));
			fRec25[0] = (double(input22[i]) - (((fTemp2 * fRec25[2]) + (2.0 * (fTemp3 * fRec25[1]))) / fTemp4));
			double fTemp17 = (((fTemp1 * (fRec25[2] + (fRec25[0] + (2.0 * fRec25[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec25[1]) + ((fRec25[0] + fRec25[2]) / fTemp4))))));
			fRec26[0] = (double(input18[i]) - (((fTemp2 * fRec26[2]) + (2.0 * (fTemp3 * fRec26[1]))) / fTemp4));
			double fTemp18 = (((fTemp1 * (fRec26[2] + (fRec26[0] + (2.0 * fRec26[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec26[1]) + ((fRec26[0] + fRec26[2]) / fTemp4))))));
			fRec27[0] = (double(input23[i]) - (((fTemp2 * fRec27[2]) + (2.0 * (fTemp3 * fRec27[1]))) / fTemp4));
			double fTemp19 = (((fTemp1 * (fRec27[2] + (fRec27[0] + (2.0 * fRec27[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec27[1]) + ((fRec27[0] + fRec27[2]) / fTemp4))))));
			fRec28[0] = (double(input21[i]) - (((fTemp2 * fRec28[2]) + (2.0 * (fTemp3 * fRec28[1]))) / fTemp4));
			double fTemp20 = (((fTemp1 * (fRec28[2] + (fRec28[0] + (2.0 * fRec28[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec28[1]) + ((fRec28[0] + fRec28[2]) / fTemp4))))));
			fRec29[0] = (double(input19[i]) - (((fTemp2 * fRec29[2]) + (2.0 * (fTemp3 * fRec29[1]))) / fTemp4));
			double fTemp21 = (((fTemp1 * (fRec29[2] + (fRec29[0] + (2.0 * fRec29[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec29[1]) + ((fRec29[0] + fRec29[2]) / fTemp4))))));
			fRec30[0] = (double(input24[i]) - (((fTemp2 * fRec30[2]) + (2.0 * (fTemp3 * fRec30[1]))) / fTemp4));
			double fTemp22 = (((fTemp1 * (fRec30[2] + (fRec30[0] + (2.0 * fRec30[1])))) / fTemp5) + (0.63729376449999997 * (fRec3[0] * (0.0 - ((fTemp6 * fRec30[1]) + ((fRec30[0] + fRec30[2]) / fTemp4))))));
			double fTemp23 = (fConst2 * ((fConst4 * ((((0.039456378799999997 * fTemp14) + (0.057950521999999997 * fTemp15)) + (0.0115401831 * fTemp16)) - ((0.0104138279 * fTemp17) + ((0.0250783768 * fTemp18) + ((0.027503341600000002 * fTemp19) + ((0.051515187599999998 * fTemp20) + ((0.040262045900000001 * fTemp21) + (0.064441907300000004 * fTemp22)))))))) + (fConst5 * (0.0 - ((fConst7 * fRec19[1]) + (fConst6 * fRec16[1]))))));
			fRec21[0] = (fRec21[1] + fTemp23);
			fRec19[0] = fRec21[0];
			double fRec20 = fTemp23;
			fRec18[0] = (fRec19[0] + fRec18[1]);
			fRec16[0] = fRec18[0];
			double fRec17 = fRec20;
			double fTemp24 = (fRec17 + (fConst8 * (0.0 - ((fConst10 * fRec13[1]) + (fConst9 * fRec10[1])))));
			fRec15[0] = (fRec15[1] + fTemp24);
			fRec13[0] = fRec15[0];
			double fRec14 = fTemp24;
			fRec12[0] = (fRec13[0] + fRec12[1]);
			fRec10[0] = fRec12[0];
			double fRec11 = fRec14;
			double fTemp25 = (fConst12 * (0.0 - ((fConst14 * fRec34[1]) + (fConst13 * fRec31[1]))));
			double fTemp26 = (fConst16 * (0.0 - ((fConst18 * fRec40[1]) + (fConst17 * fRec37[1]))));
			fRec49[0] = (double(input41[i]) - (((fTemp2 * fRec49[2]) + (2.0 * (fTemp3 * fRec49[1]))) / fTemp4));
			double fTemp27 = (((fTemp1 * (fRec49[2] + (fRec49[0] + (2.0 * fRec49[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec49[1]) + ((fRec49[0] + fRec49[2]) / fTemp4))))));
			fRec50[0] = (double(input42[i]) - (((fTemp2 * fRec50[2]) + (2.0 * (fTemp3 * fRec50[1]))) / fTemp4));
			double fTemp28 = (((fTemp1 * (fRec50[2] + (fRec50[0] + (2.0 * fRec50[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec50[1]) + ((fRec50[0] + fRec50[2]) / fTemp4))))));
			fRec51[0] = (double(input43[i]) - (((fTemp2 * fRec51[2]) + (2.0 * (fTemp3 * fRec51[1]))) / fTemp4));
			double fTemp29 = (((fTemp1 * (fRec51[2] + (fRec51[0] + (2.0 * fRec51[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec51[1]) + ((fRec51[0] + fRec51[2]) / fTemp4))))));
			fRec52[0] = (double(input44[i]) - (((fTemp2 * fRec52[2]) + (2.0 * (fTemp3 * fRec52[1]))) / fTemp4));
			double fTemp30 = (((fTemp1 * (fRec52[2] + (fRec52[0] + (2.0 * fRec52[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec52[1]) + ((fRec52[0] + fRec52[2]) / fTemp4))))));
			fRec53[0] = (double(input45[i]) - (((fTemp2 * fRec53[2]) + (2.0 * (fTemp3 * fRec53[1]))) / fTemp4));
			double fTemp31 = (((fTemp1 * (fRec53[2] + (fRec53[0] + (2.0 * fRec53[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec53[1]) + ((fRec53[0] + fRec53[2]) / fTemp4))))));
			fRec54[0] = (double(input46[i]) - (((fTemp2 * fRec54[2]) + (2.0 * (fTemp3 * fRec54[1]))) / fTemp4));
			double fTemp32 = (((fTemp1 * (fRec54[2] + (fRec54[0] + (2.0 * fRec54[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec54[1]) + ((fRec54[0] + fRec54[2]) / fTemp4))))));
			fRec55[0] = (double(input40[i]) - (((fTemp2 * fRec55[2]) + (2.0 * (fTemp3 * fRec55[1]))) / fTemp4));
			double fTemp33 = (((fTemp1 * (fRec55[2] + (fRec55[0] + (2.0 * fRec55[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec55[1]) + ((fRec55[0] + fRec55[2]) / fTemp4))))));
			fRec56[0] = (double(input37[i]) - (((fTemp2 * fRec56[2]) + (2.0 * (fTemp3 * fRec56[1]))) / fTemp4));
			double fTemp34 = (((fTemp1 * (fRec56[2] + (fRec56[0] + (2.0 * fRec56[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec56[1]) + ((fRec56[0] + fRec56[2]) / fTemp4))))));
			fRec57[0] = (double(input36[i]) - (((fTemp2 * fRec57[2]) + (2.0 * (fTemp3 * fRec57[1]))) / fTemp4));
			double fTemp35 = (((fTemp1 * (fRec57[2] + (fRec57[0] + (2.0 * fRec57[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec57[1]) + ((fRec57[0] + fRec57[2]) / fTemp4))))));
			fRec58[0] = (double(input38[i]) - (((fTemp2 * fRec58[2]) + (2.0 * (fTemp3 * fRec58[1]))) / fTemp4));
			double fTemp36 = (((fTemp1 * (fRec58[2] + (fRec58[0] + (2.0 * fRec58[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec58[1]) + ((fRec58[0] + fRec58[2]) / fTemp4))))));
			fRec59[0] = (double(input39[i]) - (((fTemp2 * fRec59[2]) + (2.0 * (fTemp3 * fRec59[1]))) / fTemp4));
			double fTemp37 = (((fTemp1 * (fRec59[2] + (fRec59[0] + (2.0 * fRec59[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec59[1]) + ((fRec59[0] + fRec59[2]) / fTemp4))))));
			fRec60[0] = (double(input47[i]) - (((fTemp2 * fRec60[2]) + (2.0 * (fTemp3 * fRec60[1]))) / fTemp4));
			double fTemp38 = (((fTemp1 * (fRec60[2] + (fRec60[0] + (2.0 * fRec60[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec60[1]) + ((fRec60[0] + fRec60[2]) / fTemp4))))));
			fRec61[0] = (double(input48[i]) - (((fTemp2 * fRec61[2]) + (2.0 * (fTemp3 * fRec61[1]))) / fTemp4));
			double fTemp39 = (((fTemp1 * (fRec61[2] + (fRec61[0] + (2.0 * fRec61[1])))) / fTemp5) + (0.31899212910000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec61[1]) + ((fRec61[0] + fRec61[2]) / fTemp4))))));
			double fTemp40 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec46[1]) + (fConst20 * fRec43[1])))) + (fConst22 * (((((((0.0348941231 * fTemp27) + (0.0144612206 * fTemp28)) + (0.047595756000000003 * fTemp29)) + (0.0015761389 * fTemp30)) + (0.023379815299999999 * fTemp31)) + (0.0018232664 * fTemp32)) - ((0.015414116699999999 * fTemp33) + ((0.012693626899999999 * fTemp34) + ((0.044560315199999999 * fTemp35) + ((((0.0124374012 * fTemp36) + (0.0607790894 * fTemp37)) + (0.068251771200000005 * fTemp38)) + (0.051859986800000001 * fTemp39)))))))));
			fRec48[0] = (fRec48[1] + fTemp40);
			fRec46[0] = fRec48[0];
			double fRec47 = fTemp40;
			fRec45[0] = (fRec46[0] + fRec45[1]);
			fRec43[0] = fRec45[0];
			double fRec44 = fRec47;
			fRec42[0] = (fTemp26 + (fRec44 + fRec42[1]));
			fRec40[0] = fRec42[0];
			double fRec41 = (fRec44 + fTemp26);
			fRec39[0] = (fRec40[0] + fRec39[1]);
			fRec37[0] = fRec39[0];
			double fRec38 = fRec41;
			fRec36[0] = (fTemp25 + (fRec38 + fRec36[1]));
			fRec34[0] = fRec36[0];
			double fRec35 = (fRec38 + fTemp25);
			fRec33[0] = (fRec34[0] + fRec33[1]);
			fRec31[0] = fRec33[0];
			double fRec32 = fRec35;
			fRec71[0] = (double(input9[i]) - (((fTemp2 * fRec71[2]) + (2.0 * (fTemp3 * fRec71[1]))) / fTemp4));
			double fTemp41 = (((fTemp1 * (fRec71[2] + (fRec71[0] + (2.0 * fRec71[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec71[1]) + ((fRec71[0] + fRec71[2]) / fTemp4))))));
			fRec72[0] = (double(input10[i]) - (((fTemp2 * fRec72[2]) + (2.0 * (fTemp3 * fRec72[1]))) / fTemp4));
			double fTemp42 = (((fTemp1 * (fRec72[2] + (fRec72[0] + (2.0 * fRec72[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec72[1]) + ((fRec72[0] + fRec72[2]) / fTemp4))))));
			fRec73[0] = (double(input14[i]) - (((fTemp2 * fRec73[2]) + (2.0 * (fTemp3 * fRec73[1]))) / fTemp4));
			double fTemp43 = (((fTemp1 * (fRec73[2] + (fRec73[0] + (2.0 * fRec73[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec73[1]) + ((fRec73[0] + fRec73[2]) / fTemp4))))));
			fRec74[0] = (double(input12[i]) - (((fTemp2 * fRec74[2]) + (2.0 * (fTemp3 * fRec74[1]))) / fTemp4));
			double fTemp44 = (((fTemp1 * (fRec74[2] + (fRec74[0] + (2.0 * fRec74[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec74[1]) + ((fRec74[0] + fRec74[2]) / fTemp4))))));
			fRec75[0] = (double(input13[i]) - (((fTemp2 * fRec75[2]) + (2.0 * (fTemp3 * fRec75[1]))) / fTemp4));
			double fTemp45 = (((fTemp1 * (fRec75[2] + (fRec75[0] + (2.0 * fRec75[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec75[1]) + ((fRec75[0] + fRec75[2]) / fTemp4))))));
			fRec76[0] = (double(input11[i]) - (((fTemp2 * fRec76[2]) + (2.0 * (fTemp3 * fRec76[1]))) / fTemp4));
			double fTemp46 = (((fTemp1 * (fRec76[2] + (fRec76[0] + (2.0 * fRec76[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec76[1]) + ((fRec76[0] + fRec76[2]) / fTemp4))))));
			fRec77[0] = (double(input15[i]) - (((fTemp2 * fRec77[2]) + (2.0 * (fTemp3 * fRec77[1]))) / fTemp4));
			double fTemp47 = (((fTemp1 * (fRec77[2] + (fRec77[0] + (2.0 * fRec77[1])))) / fTemp5) + (0.77340930829999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec77[1]) + ((fRec77[0] + fRec77[2]) / fTemp4))))));
			double fTemp48 = (fConst23 * ((fConst25 * (((0.067383474400000004 * fTemp41) + ((0.052350733300000001 * fTemp42) + (0.0118537247 * fTemp43))) - ((0.039511652199999997 * fTemp44) + ((0.029526495999999999 * fTemp45) + ((0.021163786800000001 * fTemp46) + (0.027035507699999999 * fTemp47)))))) + (fConst5 * (0.0 - ((fConst27 * fRec68[1]) + (fConst26 * fRec65[1]))))));
			fRec70[0] = (fRec70[1] + fTemp48);
			fRec68[0] = fRec70[0];
			double fRec69 = fTemp48;
			fRec67[0] = (fRec68[0] + fRec67[1]);
			fRec65[0] = fRec67[0];
			double fRec66 = fRec69;
			double fTemp49 = (fConst28 * fRec62[1]);
			fRec64[0] = ((fRec66 + fRec64[1]) - fTemp49);
			fRec62[0] = fRec64[0];
			double fRec63 = (fRec66 - fTemp49);
			fRec84[0] = (double(input4[i]) - (((fTemp2 * fRec84[2]) + (2.0 * (fTemp3 * fRec84[1]))) / fTemp4));
			double fTemp50 = (((fTemp1 * (fRec84[2] + (fRec84[0] + (2.0 * fRec84[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec84[1]) + ((fRec84[0] + fRec84[2]) / fTemp4))))));
			fRec85[0] = (double(input5[i]) - (((fTemp2 * fRec85[2]) + (2.0 * (fTemp3 * fRec85[1]))) / fTemp4));
			double fTemp51 = (((fTemp1 * (fRec85[2] + (fRec85[0] + (2.0 * fRec85[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec85[1]) + ((fRec85[0] + fRec85[2]) / fTemp4))))));
			fRec86[0] = (double(input7[i]) - (((fTemp2 * fRec86[2]) + (2.0 * (fTemp3 * fRec86[1]))) / fTemp4));
			double fTemp52 = (((fTemp1 * (fRec86[2] + (fRec86[0] + (2.0 * fRec86[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec86[1]) + ((fRec86[0] + fRec86[2]) / fTemp4))))));
			fRec87[0] = (double(input8[i]) - (((fTemp2 * fRec87[2]) + (2.0 * (fTemp3 * fRec87[1]))) / fTemp4));
			double fTemp53 = (((fTemp1 * (fRec87[2] + (fRec87[0] + (2.0 * fRec87[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec87[1]) + ((fRec87[0] + fRec87[2]) / fTemp4))))));
			fRec88[0] = (double(input6[i]) - (((fTemp2 * fRec88[2]) + (2.0 * (fTemp3 * fRec88[1]))) / fTemp4));
			double fTemp54 = (((fTemp1 * (fRec88[2] + (fRec88[0] + (2.0 * fRec88[1])))) / fTemp5) + (0.88323491269999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec88[1]) + ((fRec88[0] + fRec88[2]) / fTemp4))))));
			double fTemp55 = (fConst29 * ((((((0.061754740599999997 * fTemp50) + (0.0242265677 * fTemp51)) + (0.030165527300000002 * fTemp52)) + (0.016700725 * fTemp53)) - (0.030420442400000001 * fTemp54)) + (fConst5 * (0.0 - ((fConst31 * fRec81[1]) + (fConst30 * fRec78[1]))))));
			fRec83[0] = (fRec83[1] + fTemp55);
			fRec81[0] = fRec83[0];
			double fRec82 = fTemp55;
			fRec80[0] = (fRec81[0] + fRec80[1]);
			fRec78[0] = fRec80[0];
			double fRec79 = fRec82;
			fRec92[0] = (double(input1[i]) - (((fTemp2 * fRec92[2]) + (2.0 * (fTemp3 * fRec92[1]))) / fTemp4));
			double fTemp56 = (((fTemp1 * (fRec92[2] + (fRec92[0] + (2.0 * fRec92[1])))) / fTemp5) + (0.96028985649999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec92[1]) + ((fRec92[0] + fRec92[2]) / fTemp4))))));
			fRec93[0] = (double(input2[i]) - (((fTemp2 * fRec93[2]) + (2.0 * (fTemp3 * fRec93[1]))) / fTemp4));
			double fTemp57 = (((fTemp1 * (fRec93[2] + (fRec93[0] + (2.0 * fRec93[1])))) / fTemp5) + (0.96028985649999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec93[1]) + ((fRec93[0] + fRec93[2]) / fTemp4))))));
			fRec94[0] = (double(input3[i]) - (((fTemp2 * fRec94[2]) + (2.0 * (fTemp3 * fRec94[1]))) / fTemp4));
			double fTemp58 = (((fTemp1 * (fRec94[2] + (fRec94[0] + (2.0 * fRec94[1])))) / fTemp5) + (0.96028985649999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec94[1]) + ((fRec94[0] + fRec94[2]) / fTemp4))))));
			double fTemp59 = (fConst32 * ((((0.029665454800000001 * fTemp56) + (0.014688123799999999 * fTemp57)) + (0.0385625593 * fTemp58)) - (fConst33 * fRec89[1])));
			fRec91[0] = (fRec91[1] + fTemp59);
			fRec89[0] = fRec91[0];
			double fRec90 = fTemp59;
			double fTemp60 = (fConst35 * (0.0 - ((fConst37 * fRec101[1]) + (fConst36 * fRec98[1]))));
			fRec110[0] = (double(input26[i]) - (((fTemp2 * fRec110[2]) + (2.0 * (fTemp3 * fRec110[1]))) / fTemp4));
			double fTemp61 = (((fTemp1 * (fRec110[2] + (fRec110[0] + (2.0 * fRec110[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec110[1]) + ((fRec110[0] + fRec110[2]) / fTemp4))))));
			fRec111[0] = (double(input30[i]) - (((fTemp2 * fRec111[2]) + (2.0 * (fTemp3 * fRec111[1]))) / fTemp4));
			double fTemp62 = (((fTemp1 * (fRec111[2] + (fRec111[0] + (2.0 * fRec111[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec111[1]) + ((fRec111[0] + fRec111[2]) / fTemp4))))));
			fRec112[0] = (double(input31[i]) - (((fTemp2 * fRec112[2]) + (2.0 * (fTemp3 * fRec112[1]))) / fTemp4));
			double fTemp63 = (((fTemp1 * (fRec112[2] + (fRec112[0] + (2.0 * fRec112[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec112[1]) + ((fRec112[0] + fRec112[2]) / fTemp4))))));
			fRec113[0] = (double(input33[i]) - (((fTemp2 * fRec113[2]) + (2.0 * (fTemp3 * fRec113[1]))) / fTemp4));
			double fTemp64 = (((fTemp1 * (fRec113[2] + (fRec113[0] + (2.0 * fRec113[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec113[1]) + ((fRec113[0] + fRec113[2]) / fTemp4))))));
			fRec114[0] = (double(input27[i]) - (((fTemp2 * fRec114[2]) + (2.0 * (fTemp3 * fRec114[1]))) / fTemp4));
			double fTemp65 = (((fTemp1 * (fRec114[2] + (fRec114[0] + (2.0 * fRec114[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec114[1]) + ((fRec114[0] + fRec114[2]) / fTemp4))))));
			fRec115[0] = (double(input25[i]) - (((fTemp2 * fRec115[2]) + (2.0 * (fTemp3 * fRec115[1]))) / fTemp4));
			double fTemp66 = (((fTemp1 * (fRec115[2] + (fRec115[0] + (2.0 * fRec115[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec115[1]) + ((fRec115[0] + fRec115[2]) / fTemp4))))));
			fRec116[0] = (double(input28[i]) - (((fTemp2 * fRec116[2]) + (2.0 * (fTemp3 * fRec116[1]))) / fTemp4));
			double fTemp67 = (((fTemp1 * (fRec116[2] + (fRec116[0] + (2.0 * fRec116[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec116[1]) + ((fRec116[0] + fRec116[2]) / fTemp4))))));
			fRec117[0] = (double(input29[i]) - (((fTemp2 * fRec117[2]) + (2.0 * (fTemp3 * fRec117[1]))) / fTemp4));
			double fTemp68 = (((fTemp1 * (fRec117[2] + (fRec117[0] + (2.0 * fRec117[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec117[1]) + ((fRec117[0] + fRec117[2]) / fTemp4))))));
			fRec118[0] = (double(input32[i]) - (((fTemp2 * fRec118[2]) + (2.0 * (fTemp3 * fRec118[1]))) / fTemp4));
			double fTemp69 = (((fTemp1 * (fRec118[2] + (fRec118[0] + (2.0 * fRec118[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec118[1]) + ((fRec118[0] + fRec118[2]) / fTemp4))))));
			fRec119[0] = (double(input34[i]) - (((fTemp2 * fRec119[2]) + (2.0 * (fTemp3 * fRec119[1]))) / fTemp4));
			double fTemp70 = (((fTemp1 * (fRec119[2] + (fRec119[0] + (2.0 * fRec119[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec119[1]) + ((fRec119[0] + fRec119[2]) / fTemp4))))));
			fRec120[0] = (double(input35[i]) - (((fTemp2 * fRec120[2]) + (2.0 * (fTemp3 * fRec120[1]))) / fTemp4));
			double fTemp71 = (((fTemp1 * (fRec120[2] + (fRec120[0] + (2.0 * fRec120[1])))) / fTemp5) + (0.48284868110000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec120[1]) + ((fRec120[0] + fRec120[2]) / fTemp4))))));
			double fTemp72 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec107[1]) + (fConst39 * fRec104[1])))) + (fConst42 * (((0.0313150793 * fTemp61) + (((0.0465529212 * fTemp62) + (0.00071347049999999996 * fTemp63)) + (0.00025691949999999999 * fTemp64))) - ((((0.018100475800000002 * fTemp65) + ((0.006187204 * fTemp66) + (((0.065705226800000002 * fTemp67) + (0.0027149637000000002 * fTemp68)) + (0.017495515699999999 * fTemp69)))) + (0.061917530200000001 * fTemp70)) + (0.073548111200000002 * fTemp71))))));
			fRec109[0] = (fRec109[1] + fTemp72);
			fRec107[0] = fRec109[0];
			double fRec108 = fTemp72;
			fRec106[0] = (fRec107[0] + fRec106[1]);
			fRec104[0] = fRec106[0];
			double fRec105 = fRec108;
			fRec103[0] = (fTemp60 + (fRec105 + fRec103[1]));
			fRec101[0] = fRec103[0];
			double fRec102 = (fRec105 + fTemp60);
			fRec100[0] = (fRec101[0] + fRec100[1]);
			fRec98[0] = fRec100[0];
			double fRec99 = fRec102;
			double fTemp73 = (fConst43 * fRec95[1]);
			fRec97[0] = ((fRec99 + fRec97[1]) - fTemp73);
			fRec95[0] = fRec97[0];
			double fRec96 = (fRec99 - fTemp73);
			fRec121[0] = (double(input54[i]) - (((fTemp2 * fRec121[2]) + (2.0 * (fTemp3 * fRec121[1]))) / fTemp4));
			double fTemp74 = (((fTemp1 * (fRec121[2] + (fRec121[0] + (2.0 * fRec121[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec121[1]) + ((fRec121[0] + fRec121[2]) / fTemp4))))));
			fRec122[0] = (double(input62[i]) - (((fTemp2 * fRec122[2]) + (2.0 * (fTemp3 * fRec122[1]))) / fTemp4));
			double fTemp75 = (((fTemp1 * (fRec122[2] + (fRec122[0] + (2.0 * fRec122[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec122[1]) + ((fRec122[0] + fRec122[2]) / fTemp4))))));
			fRec123[0] = (double(input51[i]) - (((fTemp2 * fRec123[2]) + (2.0 * (fTemp3 * fRec123[1]))) / fTemp4));
			double fTemp76 = (((fTemp1 * (fRec123[2] + (fRec123[0] + (2.0 * fRec123[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec123[1]) + ((fRec123[0] + fRec123[2]) / fTemp4))))));
			fRec124[0] = (double(input50[i]) - (((fTemp2 * fRec124[2]) + (2.0 * (fTemp3 * fRec124[1]))) / fTemp4));
			double fTemp77 = (((fTemp1 * (fRec124[2] + (fRec124[0] + (2.0 * fRec124[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec124[1]) + ((fRec124[0] + fRec124[2]) / fTemp4))))));
			fRec125[0] = (double(input49[i]) - (((fTemp2 * fRec125[2]) + (2.0 * (fTemp3 * fRec125[1]))) / fTemp4));
			double fTemp78 = (((fTemp1 * (fRec125[2] + (fRec125[0] + (2.0 * fRec125[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec125[1]) + ((fRec125[0] + fRec125[2]) / fTemp4))))));
			fRec126[0] = (double(input56[i]) - (((fTemp2 * fRec126[2]) + (2.0 * (fTemp3 * fRec126[1]))) / fTemp4));
			double fTemp79 = (((fTemp1 * (fRec126[2] + (fRec126[0] + (2.0 * fRec126[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec126[1]) + ((fRec126[0] + fRec126[2]) / fTemp4))))));
			fRec127[0] = (double(input53[i]) - (((fTemp2 * fRec127[2]) + (2.0 * (fTemp3 * fRec127[1]))) / fTemp4));
			double fTemp80 = (((fTemp1 * (fRec127[2] + (fRec127[0] + (2.0 * fRec127[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec127[1]) + ((fRec127[0] + fRec127[2]) / fTemp4))))));
			fRec128[0] = (double(input52[i]) - (((fTemp2 * fRec128[2]) + (2.0 * (fTemp3 * fRec128[1]))) / fTemp4));
			double fTemp81 = (((fTemp1 * (fRec128[2] + (fRec128[0] + (2.0 * fRec128[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec128[1]) + ((fRec128[0] + fRec128[2]) / fTemp4))))));
			fRec129[0] = (double(input63[i]) - (((fTemp2 * fRec129[2]) + (2.0 * (fTemp3 * fRec129[1]))) / fTemp4));
			double fTemp82 = (((fTemp1 * (fRec129[2] + (fRec129[0] + (2.0 * fRec129[1])))) / fTemp5) + (0.1550188129 * (fRec3[0] * (0.0 - ((fTemp6 * fRec129[1]) + ((fRec129[0] + fRec129[2]) / fTemp4))))));
			fVec0[(IOTA & 1023)] = (((0.016679103599999998 * fTemp7) + ((0.0026486737000000001 * fTemp8) + ((0.0484105274 * fTemp9) + ((0.015951401800000001 * fTemp10) + ((0.0235241848 * fTemp11) + ((0.021061476499999999 * fTemp12) + (((0.017351705500000002 * fTemp13) + (fRec11 + (fRec32 + (fRec63 + (fRec79 + (fRec90 + fRec96)))))) + (0.045591458000000001 * fTemp74)))))))) - ((0.043904434700000002 * fTemp75) + ((0.0121441721 * fTemp76) + ((0.047743410799999997 * fTemp77) + ((0.058543082400000002 * fTemp78) + ((0.031344283100000002 * fTemp79) + ((0.018236289499999999 * fTemp80) + ((0.033069805600000002 * fTemp81) + (0.0145601399 * fTemp82)))))))));
			output0[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec0[((IOTA - iConst44) & 1023)])));
			double fTemp83 = (fConst8 * (0.0 - ((fConst10 * fRec133[1]) + (fConst9 * fRec130[1]))));
			double fTemp84 = (fConst2 * ((fConst4 * (((0.018723926700000001 * fTemp16) + ((0.029748641900000001 * fTemp19) + ((0.0270991579 * fTemp15) + ((0.0491248237 * fTemp14) + (0.035891568399999997 * fTemp22))))) - (((0.013735374700000001 * fTemp18) + ((0.010291330899999999 * fTemp21) + (0.041673309499999998 * fTemp20))) + (0.029150095399999999 * fTemp17)))) + (fConst5 * (0.0 - ((fConst7 * fRec139[1]) + (fConst6 * fRec136[1]))))));
			fRec141[0] = (fRec141[1] + fTemp84);
			fRec139[0] = fRec141[0];
			double fRec140 = fTemp84;
			fRec138[0] = (fRec139[0] + fRec138[1]);
			fRec136[0] = fRec138[0];
			double fRec137 = fRec140;
			fRec135[0] = (fTemp83 + (fRec137 + fRec135[1]));
			fRec133[0] = fRec135[0];
			double fRec134 = (fRec137 + fTemp83);
			fRec132[0] = (fRec133[0] + fRec132[1]);
			fRec130[0] = fRec132[0];
			double fRec131 = fRec134;
			double fTemp85 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec148[1]) + (fConst26 * fRec145[1])))) + (fConst25 * (((0.036262509200000001 * fTemp41) + ((0.028050711499999999 * fTemp43) + ((0.015085925 * fTemp42) + (0.042572835099999998 * fTemp47)))) - ((0.0239365806 * fTemp44) + ((0.0077984969999999997 * fTemp46) + (0.0338370016 * fTemp45)))))));
			fRec150[0] = (fRec150[1] + fTemp85);
			fRec148[0] = fRec150[0];
			double fRec149 = fTemp85;
			fRec147[0] = (fRec148[0] + fRec147[1]);
			fRec145[0] = fRec147[0];
			double fRec146 = fRec149;
			double fTemp86 = (fConst28 * fRec142[1]);
			fRec144[0] = ((fRec146 + fRec144[1]) - fTemp86);
			fRec142[0] = fRec144[0];
			double fRec143 = (fRec146 - fTemp86);
			double fTemp87 = (fConst29 * ((((((0.0215195561 * fTemp50) + (0.0053739679000000002 * fTemp51)) + (0.021276802899999999 * fTemp52)) + (0.042249251199999997 * fTemp53)) - (0.024671526900000001 * fTemp54)) + (fConst5 * (0.0 - ((fConst31 * fRec154[1]) + (fConst30 * fRec151[1]))))));
			fRec156[0] = (fRec156[1] + fTemp87);
			fRec154[0] = fRec156[0];
			double fRec155 = fTemp87;
			fRec153[0] = (fRec154[0] + fRec153[1]);
			fRec151[0] = fRec153[0];
			double fRec152 = fRec155;
			double fTemp88 = (fConst32 * ((((0.0081666310000000006 * fTemp56) + (0.0080504287000000008 * fTemp57)) + (0.033948018000000003 * fTemp58)) - (fConst33 * fRec157[1])));
			fRec159[0] = (fRec159[1] + fTemp88);
			fRec157[0] = fRec159[0];
			double fRec158 = fTemp88;
			double fTemp89 = (fConst35 * (0.0 - ((fConst37 * fRec166[1]) + (fConst36 * fRec163[1]))));
			double fTemp90 = (fConst38 * ((fConst42 * (((((0.038746606400000001 * fTemp61) + ((0.0576307317 * fTemp66) + (((0.0033982126000000001 * fTemp68) + (0.034739817100000001 * fTemp62)) + (0.0175661293 * fTemp63)))) + (0.025746116400000001 * fTemp70)) + (0.024117195500000001 * fTemp71)) - ((0.016529955299999999 * fTemp65) + (((0.022565823200000001 * fTemp67) + (0.043433748100000003 * fTemp69)) + (0.022432127600000001 * fTemp64))))) + (fConst5 * (0.0 - ((fConst40 * fRec172[1]) + (fConst39 * fRec169[1]))))));
			fRec174[0] = (fRec174[1] + fTemp90);
			fRec172[0] = fRec174[0];
			double fRec173 = fTemp90;
			fRec171[0] = (fRec172[0] + fRec171[1]);
			fRec169[0] = fRec171[0];
			double fRec170 = fRec173;
			fRec168[0] = (fTemp89 + (fRec170 + fRec168[1]));
			fRec166[0] = fRec168[0];
			double fRec167 = (fRec170 + fTemp89);
			fRec165[0] = (fRec166[0] + fRec165[1]);
			fRec163[0] = fRec165[0];
			double fRec164 = fRec167;
			double fTemp91 = (fConst43 * fRec160[1]);
			fRec162[0] = ((fRec164 + fRec162[1]) - fTemp91);
			fRec160[0] = fRec162[0];
			double fRec161 = (fRec164 - fTemp91);
			double fTemp92 = (fConst12 * (0.0 - ((fConst14 * fRec178[1]) + (fConst13 * fRec175[1]))));
			double fTemp93 = (fConst16 * (0.0 - ((fConst18 * fRec184[1]) + (fConst17 * fRec181[1]))));
			double fTemp94 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec190[1]) + (fConst20 * fRec187[1])))) + (fConst22 * (((0.0024977608999999998 * fTemp33) + ((0.0474522738 * fTemp34) + ((0.060402101200000002 * fTemp35) + (((((0.0118211568 * fTemp27) + (0.0499075592 * fTemp29)) + (0.0090645321999999993 * fTemp30)) + (0.016788921599999999 * fTemp38)) + (0.0097937683000000001 * fTemp39))))) - (((((0.0160236645 * fTemp36) + (0.033805598999999999 * fTemp37)) + (0.0039784560999999996 * fTemp28)) + (0.039243261699999997 * fTemp31)) + (0.015645744100000001 * fTemp32))))));
			fRec192[0] = (fRec192[1] + fTemp94);
			fRec190[0] = fRec192[0];
			double fRec191 = fTemp94;
			fRec189[0] = (fRec190[0] + fRec189[1]);
			fRec187[0] = fRec189[0];
			double fRec188 = fRec191;
			fRec186[0] = (fTemp93 + (fRec188 + fRec186[1]));
			fRec184[0] = fRec186[0];
			double fRec185 = (fRec188 + fTemp93);
			fRec183[0] = (fRec184[0] + fRec183[1]);
			fRec181[0] = fRec183[0];
			double fRec182 = fRec185;
			fRec180[0] = (fTemp92 + (fRec182 + fRec180[1]));
			fRec178[0] = fRec180[0];
			double fRec179 = (fRec182 + fTemp92);
			fRec177[0] = (fRec178[0] + fRec177[1]);
			fRec175[0] = fRec177[0];
			double fRec176 = fRec179;
			fVec1[(IOTA & 1023)] = (((0.044912403400000002 * fTemp7) + ((0.0047209764999999997 * fTemp75) + ((0.0029003615999999999 * fTemp10) + ((0.051346109399999999 * fTemp77) + ((0.057270897000000001 * fTemp78) + ((0.0043072639999999999 * fTemp11) + ((0.0020590636000000001 * fTemp12) + (((0.0121423434 * fTemp13) + (fRec131 + (fRec143 + (fRec152 + (fRec158 + (fRec161 + fRec176)))))) + (0.021949770899999999 * fTemp74))))))))) - ((0.0103794205 * fTemp8) + ((0.030541513999999999 * fTemp9) + ((0.013023161199999999 * fTemp76) + ((0.0348599619 * fTemp79) + ((0.00155835 * fTemp80) + ((0.041596271499999997 * fTemp81) + (0.0043920540000000003 * fTemp82))))))));
			output1[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec1[((IOTA - iConst44) & 1023)])));
			double fTemp95 = (fConst35 * (0.0 - ((fConst37 * fRec199[1]) + (fConst36 * fRec196[1]))));
			double fTemp96 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec205[1]) + (fConst39 * fRec202[1])))) + (fConst42 * (((((0.0128587745 * fTemp65) + ((0.0181103429 * fTemp67) + (0.047019299399999999 * fTemp62))) + (0.061554627299999998 * fTemp70)) + (0.055571430900000003 * fTemp71)) - ((0.032390509599999999 * fTemp61) + ((0.048840966800000003 * fTemp66) + ((((0.0024478363000000002 * fTemp68) + (0.00098900620000000002 * fTemp63)) + (0.066083747100000007 * fTemp69)) + (0.013253513499999999 * fTemp64))))))));
			fRec207[0] = (fRec207[1] + fTemp96);
			fRec205[0] = fRec207[0];
			double fRec206 = fTemp96;
			fRec204[0] = (fRec205[0] + fRec204[1]);
			fRec202[0] = fRec204[0];
			double fRec203 = fRec206;
			fRec201[0] = (fTemp95 + (fRec203 + fRec201[1]));
			fRec199[0] = fRec201[0];
			double fRec200 = (fRec203 + fTemp95);
			fRec198[0] = (fRec199[0] + fRec198[1]);
			fRec196[0] = fRec198[0];
			double fRec197 = fRec200;
			double fTemp97 = (fConst43 * fRec193[1]);
			fRec195[0] = ((fRec197 + fRec195[1]) - fTemp97);
			fRec193[0] = fRec195[0];
			double fRec194 = (fRec197 - fTemp97);
			double fTemp98 = (fConst8 * (0.0 - ((fConst10 * fRec211[1]) + (fConst9 * fRec208[1]))));
			double fTemp99 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec217[1]) + (fConst6 * fRec214[1])))) + (fConst4 * (((0.011891380599999999 * fTemp16) + ((0.0106972762 * fTemp18) + ((0.060349276200000003 * fTemp19) + ((0.0082661783999999992 * fTemp21) + (0.064095782399999995 * fTemp22))))) - ((((0.040656872500000003 * fTemp14) + (0.022354497099999999 * fTemp15)) + (0.065294007299999998 * fTemp20)) + (0.025470690599999998 * fTemp17))))));
			fRec219[0] = (fRec219[1] + fTemp99);
			fRec217[0] = fRec219[0];
			double fRec218 = fTemp99;
			fRec216[0] = (fRec217[0] + fRec216[1]);
			fRec214[0] = fRec216[0];
			double fRec215 = fRec218;
			fRec213[0] = (fTemp98 + (fRec215 + fRec213[1]));
			fRec211[0] = fRec213[0];
			double fRec212 = (fRec215 + fTemp98);
			fRec210[0] = (fRec211[0] + fRec210[1]);
			fRec208[0] = fRec210[0];
			double fRec209 = fRec212;
			double fTemp100 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec226[1]) + (fConst26 * fRec223[1])))) + (fConst25 * (((0.052434965600000001 * fTemp43) + ((0.0061069486999999999 * fTemp46) + (0.066804916899999997 * fTemp47))) - ((0.039714498899999999 * fTemp44) + ((0.029507360900000001 * fTemp41) + ((0.012343163900000001 * fTemp42) + (0.036296476799999998 * fTemp45))))))));
			fRec228[0] = (fRec228[1] + fTemp100);
			fRec226[0] = fRec228[0];
			double fRec227 = fTemp100;
			fRec225[0] = (fRec226[0] + fRec225[1]);
			fRec223[0] = fRec225[0];
			double fRec224 = fRec227;
			double fTemp101 = (fConst28 * fRec220[1]);
			fRec222[0] = ((fRec224 + fRec222[1]) - fTemp101);
			fRec220[0] = fRec222[0];
			double fRec221 = (fRec224 - fTemp101);
			double fTemp102 = (fConst29 * ((((0.038575806999999997 * fTemp52) + (0.062023356299999999 * fTemp53)) - (((0.0173188131 * fTemp50) + (0.0043816191999999999 * fTemp51)) + (0.030715410700000001 * fTemp54))) + (fConst5 * (0.0 - ((fConst31 * fRec232[1]) + (fConst30 * fRec229[1]))))));
			fRec234[0] = (fRec234[1] + fTemp102);
			fRec232[0] = fRec234[0];
			double fRec233 = fTemp102;
			fRec231[0] = (fRec232[0] + fRec231[1]);
			fRec229[0] = fRec231[0];
			double fRec230 = fRec233;
			double fTemp103 = (fConst32 * ((((0.014732654 * fTemp57) + (0.048546944699999997 * fTemp58)) - (0.0065354439999999996 * fTemp56)) - (fConst33 * fRec235[1])));
			fRec237[0] = (fRec237[1] + fTemp103);
			fRec235[0] = fRec237[0];
			double fRec236 = fTemp103;
			double fTemp104 = (fConst12 * (0.0 - ((fConst14 * fRec241[1]) + (fConst13 * fRec238[1]))));
			double fTemp105 = (fConst16 * (0.0 - ((fConst18 * fRec247[1]) + (fConst17 * fRec244[1]))));
			double fTemp106 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec253[1]) + (fConst20 * fRec250[1])))) + (fConst22 * (((((((0.012526953699999999 * fTemp36) + (0.0272452797 * fTemp37)) + (0.0142653668 * fTemp28)) + (0.059099783099999997 * fTemp29)) + (0.056512833300000002 * fTemp38)) + (0.0433148618 * fTemp39)) - ((0.0014916642 * fTemp33) + ((0.040430783800000002 * fTemp34) + ((0.052841268599999998 * fTemp35) + ((((0.0092613971000000007 * fTemp27) + (0.015104731 * fTemp30)) + (0.059728203799999997 * fTemp31)) + (0.0019687197000000001 * fTemp32)))))))));
			fRec255[0] = (fRec255[1] + fTemp106);
			fRec253[0] = fRec255[0];
			double fRec254 = fTemp106;
			fRec252[0] = (fRec253[0] + fRec252[1]);
			fRec250[0] = fRec252[0];
			double fRec251 = fRec254;
			fRec249[0] = (fTemp105 + (fRec251 + fRec249[1]));
			fRec247[0] = fRec249[0];
			double fRec248 = (fRec251 + fTemp105);
			fRec246[0] = (fRec247[0] + fRec246[1]);
			fRec244[0] = fRec246[0];
			double fRec245 = fRec248;
			fRec243[0] = (fTemp104 + (fRec245 + fRec243[1]));
			fRec241[0] = fRec243[0];
			double fRec242 = (fRec245 + fTemp104);
			fRec240[0] = (fRec241[0] + fRec240[1]);
			fRec238[0] = fRec240[0];
			double fRec239 = fRec242;
			fVec2[(IOTA & 1023)] = (((0.0463047584 * fTemp7) + ((0.046672664699999998 * fTemp75) + ((0.0066662691999999999 * fTemp8) + ((0.010345744299999999 * fTemp76) + ((0.031459402099999999 * fTemp11) + ((0.0018613232000000001 * fTemp80) + ((0.033860443300000001 * fTemp81) + ((0.017466101899999999 * fTemp13) + (fRec194 + (fRec209 + (fRec221 + (fRec230 + (fRec236 + (fRec239 + (0.029550176099999999 * fTemp82))))))))))))))) - ((((0.044890122800000001 * fTemp77) + ((0.052241988599999997 * fTemp78) + (((0.017104419900000001 * fTemp74) + (0.0018550185999999999 * fTemp12)) + (0.032025042900000002 * fTemp79)))) + (0.0239624885 * fTemp10)) + (0.048371564899999997 * fTemp9)));
			output2[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec2[((IOTA - iConst44) & 1023)])));
			double fTemp107 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec262[1]) + (fConst26 * fRec259[1])))) + (fConst25 * (((0.0186099617 * fTemp46) + (0.0148658184 * fTemp43)) - ((0.0239814551 * fTemp44) + ((0.055772743499999999 * fTemp41) + ((0.029425120900000001 * fTemp45) + ((0.028227562099999999 * fTemp42) + (0.0052783761999999996 * fTemp47)))))))));
			fRec264[0] = (fRec264[1] + fTemp107);
			fRec262[0] = fRec264[0];
			double fRec263 = fTemp107;
			fRec261[0] = (fRec262[0] + fRec261[1]);
			fRec259[0] = fRec261[0];
			double fRec260 = fRec263;
			double fTemp108 = (fConst28 * fRec256[1]);
			fRec258[0] = ((fRec260 + fRec258[1]) - fTemp108);
			fRec256[0] = fRec258[0];
			double fRec257 = (fRec260 - fTemp108);
			double fTemp109 = (fConst12 * (0.0 - ((fConst14 * fRec268[1]) + (fConst13 * fRec265[1]))));
			double fTemp110 = (fConst16 * (0.0 - ((fConst18 * fRec274[1]) + (fConst17 * fRec271[1]))));
			double fTemp111 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec280[1]) + (fConst20 * fRec277[1])))) + (fConst22 * (((0.011632736899999999 * fTemp35) + ((((((0.0156948082 * fTemp36) + (0.051691598599999999 * fTemp37)) + (0.043631522399999997 * fTemp29)) + (0.002384387 * fTemp30)) + (0.0045830439999999997 * fTemp31)) + (0.016088890299999999 * fTemp32))) - ((0.0091871639999999994 * fTemp33) + ((0.020655175299999998 * fTemp34) + ((((0.027207986 * fTemp27) + (0.0040345816 * fTemp28)) + (0.045938265899999997 * fTemp38)) + (0.060065893099999997 * fTemp39))))))));
			fRec282[0] = (fRec282[1] + fTemp111);
			fRec280[0] = fRec282[0];
			double fRec281 = fTemp111;
			fRec279[0] = (fRec280[0] + fRec279[1]);
			fRec277[0] = fRec279[0];
			double fRec278 = fRec281;
			fRec276[0] = (fTemp110 + (fRec278 + fRec276[1]));
			fRec274[0] = fRec276[0];
			double fRec275 = (fRec278 + fTemp110);
			fRec273[0] = (fRec274[0] + fRec273[1]);
			fRec271[0] = fRec273[0];
			double fRec272 = fRec275;
			fRec270[0] = (fTemp109 + (fRec272 + fRec270[1]));
			fRec268[0] = fRec270[0];
			double fRec269 = (fRec272 + fTemp109);
			fRec267[0] = (fRec268[0] + fRec267[1]);
			fRec265[0] = fRec267[0];
			double fRec266 = fRec269;
			double fTemp112 = (fConst35 * (0.0 - ((fConst37 * fRec289[1]) + (fConst36 * fRec286[1]))));
			double fTemp113 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec295[1]) + (fConst39 * fRec292[1])))) + (fConst42 * (((0.027560334999999998 * fTemp65) + ((((0.043724372999999997 * fTemp67) + (0.034817924 * fTemp62)) + (0.014835606499999999 * fTemp63)) + (0.0046515374999999996 * fTemp64))) - ((((0.038323148799999998 * fTemp61) + ((0.0222653383 * fTemp66) + ((0.010159094400000001 * fTemp68) + (0.022209774700000001 * fTemp69)))) + (0.026465798799999999 * fTemp70)) + (0.058418527099999999 * fTemp71))))));
			fRec297[0] = (fRec297[1] + fTemp113);
			fRec295[0] = fRec297[0];
			double fRec296 = fTemp113;
			fRec294[0] = (fRec295[0] + fRec294[1]);
			fRec292[0] = fRec294[0];
			double fRec293 = fRec296;
			fRec291[0] = (fTemp112 + (fRec293 + fRec291[1]));
			fRec289[0] = fRec291[0];
			double fRec290 = (fRec293 + fTemp112);
			fRec288[0] = (fRec289[0] + fRec288[1]);
			fRec286[0] = fRec288[0];
			double fRec287 = fRec290;
			double fTemp114 = (fConst43 * fRec283[1]);
			fRec285[0] = ((fRec287 + fRec285[1]) - fTemp114);
			fRec283[0] = fRec285[0];
			double fRec284 = (fRec287 - fTemp114);
			double fTemp115 = (fConst8 * (0.0 - ((fConst10 * fRec301[1]) + (fConst9 * fRec298[1]))));
			double fTemp116 = (fConst2 * ((fConst4 * ((((0.029377012800000001 * fTemp18) + (0.022398404199999999 * fTemp21)) + (0.0187892484 * fTemp16)) - ((0.013463944800000001 * fTemp17) + ((0.0024083395 * fTemp19) + ((0.036716007199999998 * fTemp20) + ((0.0402277511 * fTemp15) + ((0.048476556499999997 * fTemp14) + (0.036896153899999999 * fTemp22)))))))) + (fConst5 * (0.0 - ((fConst7 * fRec307[1]) + (fConst6 * fRec304[1]))))));
			fRec309[0] = (fRec309[1] + fTemp116);
			fRec307[0] = fRec309[0];
			double fRec308 = fTemp116;
			fRec306[0] = (fRec307[0] + fRec306[1]);
			fRec304[0] = fRec306[0];
			double fRec305 = fRec308;
			fRec303[0] = (fTemp115 + (fRec305 + fRec303[1]));
			fRec301[0] = fRec303[0];
			double fRec302 = (fRec305 + fTemp115);
			fRec300[0] = (fRec301[0] + fRec300[1]);
			fRec298[0] = fRec300[0];
			double fRec299 = fRec302;
			double fTemp117 = (fConst32 * ((((0.0080646999999999993 * fTemp57) + (0.029758019399999999 * fTemp58)) - (0.018411065800000001 * fTemp56)) - (fConst33 * fRec310[1])));
			fRec312[0] = (fRec312[1] + fTemp117);
			fRec310[0] = fRec312[0];
			double fRec311 = fTemp117;
			double fTemp118 = (fConst29 * ((((0.018829361400000001 * fTemp52) + (0.021158426099999999 * fTemp53)) - (((0.042539507800000001 * fTemp50) + (0.011345864400000001 * fTemp51)) + (0.0247318656 * fTemp54))) + (fConst5 * (0.0 - ((fConst31 * fRec316[1]) + (fConst30 * fRec313[1]))))));
			fRec318[0] = (fRec318[1] + fTemp118);
			fRec316[0] = fRec318[0];
			double fRec317 = fTemp118;
			fRec315[0] = (fRec316[0] + fRec315[1]);
			fRec313[0] = fRec315[0];
			double fRec314 = fRec317;
			fVec3[(IOTA & 1023)] = (((0.0215688817 * fTemp7) + ((0.016692311500000001 * fTemp8) + ((0.031398273099999999 * fTemp9) + ((0.0013168310999999999 * fTemp76) + ((0.0061540902000000001 * fTemp77) + ((0.038909421700000002 * fTemp78) + ((0.0044589225000000003 * fTemp11) + (((0.0121692494 * fTemp13) + (fRec257 + (fRec266 + (fRec284 + (fRec299 + (fRec311 + fRec314)))))) + (0.041066169800000003 * fTemp81))))))))) - ((0.051192919199999999 * fTemp75) + ((0.0032822976999999998 * fTemp10) + ((0.0349738931 * fTemp79) + ((0.0015465804 * fTemp12) + ((0.045255896300000001 * fTemp74) + ((0.0009537813 * fTemp80) + (0.042151026699999997 * fTemp82))))))));
			output3[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec3[((IOTA - iConst44) & 1023)])));
			double fTemp119 = (fConst35 * (0.0 - ((fConst37 * fRec325[1]) + (fConst36 * fRec322[1]))));
			double fTemp120 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec331[1]) + (fConst39 * fRec328[1])))) + (fConst42 * (((0.0353568374 * fTemp61) + ((0.074296191299999995 * fTemp66) + ((((0.066676676700000007 * fTemp67) + (0.0477848632 * fTemp62)) + (0.0198211966 * fTemp69)) + (0.018438762099999999 * fTemp64)))) - ((((0.00034724879999999998 * fTemp65) + ((0.00072549430000000002 * fTemp68) + (0.0026775191999999998 * fTemp63))) + (0.060761972499999997 * fTemp70)) + (0.00097000799999999996 * fTemp71))))));
			fRec333[0] = (fRec333[1] + fTemp120);
			fRec331[0] = fRec333[0];
			double fRec332 = fTemp120;
			fRec330[0] = (fRec331[0] + fRec330[1]);
			fRec328[0] = fRec330[0];
			double fRec329 = fRec332;
			fRec327[0] = (fTemp119 + (fRec329 + fRec327[1]));
			fRec325[0] = fRec327[0];
			double fRec326 = (fRec329 + fTemp119);
			fRec324[0] = (fRec325[0] + fRec324[1]);
			fRec322[0] = fRec324[0];
			double fRec323 = fRec326;
			double fTemp121 = (fConst43 * fRec319[1]);
			fRec321[0] = ((fRec323 + fRec321[1]) - fTemp121);
			fRec319[0] = fRec321[0];
			double fRec320 = (fRec323 - fTemp121);
			double fTemp122 = (fConst29 * (((0.0243329644 * fTemp52) - ((((0.062592298500000004 * fTemp50) + (0.0312496123 * fTemp51)) + (0.031185574899999999 * fTemp54)) + (0.0188865548 * fTemp53))) + (fConst5 * (0.0 - ((fConst31 * fRec337[1]) + (fConst30 * fRec334[1]))))));
			fRec339[0] = (fRec339[1] + fTemp122);
			fRec337[0] = fRec339[0];
			double fRec338 = fTemp122;
			fRec336[0] = (fRec337[0] + fRec336[1]);
			fRec334[0] = fRec336[0];
			double fRec335 = fRec338;
			double fTemp123 = (fConst32 * ((((0.015043623000000001 * fTemp57) + (0.029797874200000001 * fTemp58)) - (0.039922928500000003 * fTemp56)) - (fConst33 * fRec340[1])));
			fRec342[0] = (fRec342[1] + fTemp123);
			fRec340[0] = fRec342[0];
			double fRec341 = fTemp123;
			double fTemp124 = (fConst8 * (0.0 - ((fConst10 * fRec346[1]) + (fConst9 * fRec343[1]))));
			double fTemp125 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec352[1]) + (fConst6 * fRec349[1])))) + (fConst4 * (((((0.025399511100000001 * fTemp18) + ((0.043655292900000003 * fTemp14) + (0.053382000800000003 * fTemp21))) + (0.011882199899999999 * fTemp16)) + (0.011306278499999999 * fTemp17)) - ((0.060200963199999999 * fTemp19) + ((0.040476258100000002 * fTemp20) + ((0.025355414100000001 * fTemp15) + (0.062926540399999994 * fTemp22))))))));
			fRec354[0] = (fRec354[1] + fTemp125);
			fRec352[0] = fRec354[0];
			double fRec353 = fTemp125;
			fRec351[0] = (fRec352[0] + fRec351[1]);
			fRec349[0] = fRec351[0];
			double fRec350 = fRec353;
			fRec348[0] = (fTemp124 + (fRec350 + fRec348[1]));
			fRec346[0] = fRec348[0];
			double fRec347 = (fRec350 + fTemp124);
			fRec345[0] = (fRec346[0] + fRec345[1]);
			fRec343[0] = fRec345[0];
			double fRec344 = fRec347;
			double fTemp126 = (fConst23 * ((fConst25 * ((0.030563589700000001 * fTemp46) - ((0.040491397300000002 * fTemp44) + ((0.024552632899999999 * fTemp41) + ((0.013705421299999999 * fTemp43) + ((0.021284622400000001 * fTemp45) + ((0.053104704199999998 * fTemp42) + (0.069759276800000006 * fTemp47)))))))) + (fConst5 * (0.0 - ((fConst27 * fRec361[1]) + (fConst26 * fRec358[1]))))));
			fRec363[0] = (fRec363[1] + fTemp126);
			fRec361[0] = fRec363[0];
			double fRec362 = fTemp126;
			fRec360[0] = (fRec361[0] + fRec360[1]);
			fRec358[0] = fRec360[0];
			double fRec359 = fRec362;
			double fTemp127 = (fConst28 * fRec355[1]);
			fRec357[0] = ((fRec359 + fRec357[1]) - fTemp127);
			fRec355[0] = fRec357[0];
			double fRec356 = (fRec359 - fTemp127);
			double fTemp128 = (fConst12 * (0.0 - ((fConst14 * fRec367[1]) + (fConst13 * fRec364[1]))));
			double fTemp129 = (fConst16 * (0.0 - ((fConst18 * fRec373[1]) + (fConst17 * fRec370[1]))));
			double fTemp130 = (fConst19 * ((fConst22 * (((0.015662085900000001 * fTemp33) + ((0.069400468199999996 * fTemp34) + ((0.039935683700000002 * fTemp35) + ((0.0013240859999999999 * fTemp32) + (((((0.021213972099999999 * fTemp37) + (0.014759575800000001 * fTemp28)) + (0.035177494599999998 * fTemp29)) + (0.062926717399999998 * fTemp31)) + (0.055300033999999998 * fTemp39)))))) - ((((0.0125293885 * fTemp36) + (0.049373979899999997 * fTemp27)) + (0.0010456547 * fTemp30)) + (0.0077544902000000002 * fTemp38)))) + (fConst5 * (0.0 - ((fConst21 * fRec379[1]) + (fConst20 * fRec376[1]))))));
			fRec381[0] = (fRec381[1] + fTemp130);
			fRec379[0] = fRec381[0];
			double fRec380 = fTemp130;
			fRec378[0] = (fRec379[0] + fRec378[1]);
			fRec376[0] = fRec378[0];
			double fRec377 = fRec380;
			fRec375[0] = (fTemp129 + (fRec377 + fRec375[1]));
			fRec373[0] = fRec375[0];
			double fRec374 = (fRec377 + fTemp129);
			fRec372[0] = (fRec373[0] + fRec372[1]);
			fRec370[0] = fRec372[0];
			double fRec371 = fRec374;
			fRec369[0] = (fTemp128 + (fRec371 + fRec369[1]));
			fRec367[0] = fRec369[0];
			double fRec368 = (fRec371 + fTemp128);
			fRec366[0] = (fRec367[0] + fRec366[1]);
			fRec364[0] = fRec366[0];
			double fRec365 = fRec368;
			fVec4[(IOTA & 1023)] = (((0.047647070600000001 * fTemp75) + ((0.047201819800000003 * fTemp9) + ((0.019233460599999998 * fTemp10) + ((0.043620700900000003 * fTemp77) + ((0.0211505515 * fTemp11) + ((0.0152220806 * fTemp80) + ((0.0177769474 * fTemp13) + (fRec320 + (fRec335 + (fRec341 + (fRec344 + (fRec356 + (fRec365 + (0.056036273999999997 * fTemp82)))))))))))))) - ((0.018304105500000001 * fTemp7) + (((0.0018737044 * fTemp76) + ((0.0199150921 * fTemp78) + ((((0.036170729999999998 * fTemp81) + (0.046352066599999998 * fTemp74)) + (0.024401680799999999 * fTemp12)) + (0.032331045599999997 * fTemp79)))) + (0.012088388300000001 * fTemp8))));
			output4[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec4[((IOTA - iConst44) & 1023)])));
			double fTemp131 = (fConst29 * (((0.0050270990000000002 * fTemp52) - ((((0.020138157800000001 * fTemp50) + (0.0216047173 * fTemp51)) + (0.0249998318 * fTemp54)) + (0.043521099100000002 * fTemp53))) + (fConst5 * (0.0 - ((fConst31 * fRec385[1]) + (fConst30 * fRec382[1]))))));
			fRec387[0] = (fRec387[1] + fTemp131);
			fRec385[0] = fRec387[0];
			double fRec386 = fTemp131;
			fRec384[0] = (fRec385[0] + fRec384[1]);
			fRec382[0] = fRec384[0];
			double fRec383 = fRec386;
			double fTemp132 = (fConst32 * ((((0.0081369890000000007 * fTemp57) + (0.0076172284000000003 * fTemp58)) - (0.034510821300000001 * fTemp56)) - (fConst33 * fRec388[1])));
			fRec390[0] = (fRec390[1] + fTemp132);
			fRec388[0] = fRec390[0];
			double fRec389 = fTemp132;
			double fTemp133 = (fConst12 * (0.0 - ((fConst14 * fRec394[1]) + (fConst13 * fRec391[1]))));
			double fTemp134 = (fConst16 * (0.0 - ((fConst18 * fRec400[1]) + (fConst17 * fRec397[1]))));
			double fTemp135 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec406[1]) + (fConst20 * fRec403[1])))) + (fConst22 * ((((0.011060745800000001 * fTemp29) + (0.031921855200000002 * fTemp31)) + (0.045900579300000001 * fTemp38)) - ((0.0022266728000000001 * fTemp33) + ((0.0212924333 * fTemp34) + ((0.058939848400000001 * fTemp35) + ((0.016980631100000001 * fTemp32) + ((((((0.0149570637 * fTemp36) + (0.041510953599999997 * fTemp37)) + (0.050837012100000002 * fTemp27)) + (0.0041222215999999999 * fTemp28)) + (0.0093649148000000005 * fTemp30)) + (0.016686009599999999 * fTemp39))))))))));
			fRec408[0] = (fRec408[1] + fTemp135);
			fRec406[0] = fRec408[0];
			double fRec407 = fTemp135;
			fRec405[0] = (fRec406[0] + fRec405[1]);
			fRec403[0] = fRec405[0];
			double fRec404 = fRec407;
			fRec402[0] = (fTemp134 + (fRec404 + fRec402[1]));
			fRec400[0] = fRec402[0];
			double fRec401 = (fRec404 + fTemp134);
			fRec399[0] = (fRec400[0] + fRec399[1]);
			fRec397[0] = fRec399[0];
			double fRec398 = fRec401;
			fRec396[0] = (fTemp133 + (fRec398 + fRec396[1]));
			fRec394[0] = fRec396[0];
			double fRec395 = (fRec398 + fTemp133);
			fRec393[0] = (fRec394[0] + fRec393[1]);
			fRec391[0] = fRec393[0];
			double fRec392 = fRec395;
			double fTemp136 = (fConst35 * (0.0 - ((fConst37 * fRec415[1]) + (fConst36 * fRec412[1]))));
			double fTemp137 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec421[1]) + (fConst39 * fRec418[1])))) + (fConst42 * (((((0.036981036799999999 * fTemp61) + (((((0.021189306200000001 * fTemp67) + (0.035211396399999997 * fTemp62)) + (0.0031342259999999999 * fTemp63)) + (0.044769852700000001 * fTemp69)) + (0.015440888200000001 * fTemp64))) + (0.028801833200000002 * fTemp70)) + (0.055343846100000003 * fTemp71)) - ((0.023621150399999999 * fTemp65) + ((0.029635049 * fTemp66) + (0.017963142599999999 * fTemp68)))))));
			fRec423[0] = (fRec423[1] + fTemp137);
			fRec421[0] = fRec423[0];
			double fRec422 = fTemp137;
			fRec420[0] = (fRec421[0] + fRec420[1]);
			fRec418[0] = fRec420[0];
			double fRec419 = fRec422;
			fRec417[0] = (fTemp136 + (fRec419 + fRec417[1]));
			fRec415[0] = fRec417[0];
			double fRec416 = (fRec419 + fTemp136);
			fRec414[0] = (fRec415[0] + fRec414[1]);
			fRec412[0] = fRec414[0];
			double fRec413 = fRec416;
			double fTemp138 = (fConst43 * fRec409[1]);
			fRec411[0] = ((fRec413 + fRec411[1]) - fTemp138);
			fRec409[0] = fRec411[0];
			double fRec410 = (fRec413 - fTemp138);
			double fTemp139 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec430[1]) + (fConst26 * fRec427[1])))) + (fConst25 * (((0.0450030794 * fTemp41) + (0.034448975999999999 * fTemp46)) - ((0.0242176159 * fTemp44) + ((0.028892031499999998 * fTemp43) + ((0.0072634917000000002 * fTemp45) + ((0.014167074700000001 * fTemp42) + (0.034128747799999998 * fTemp47)))))))));
			fRec432[0] = (fRec432[1] + fTemp139);
			fRec430[0] = fRec432[0];
			double fRec431 = fTemp139;
			fRec429[0] = (fRec430[0] + fRec429[1]);
			fRec427[0] = fRec429[0];
			double fRec428 = fRec431;
			double fTemp140 = (fConst28 * fRec424[1]);
			fRec426[0] = ((fRec428 + fRec426[1]) - fTemp140);
			fRec424[0] = fRec426[0];
			double fRec425 = (fRec428 - fTemp140);
			double fTemp141 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec442[1]) + (fConst6 * fRec439[1])))) + (fConst4 * (((0.030051461299999999 * fTemp17) + ((0.019030370899999999 * fTemp16) + ((0.0128109685 * fTemp18) + ((0.031516280000000001 * fTemp15) + ((0.046625532900000002 * fTemp14) + ((0.042366692400000003 * fTemp21) + (0.0398196948 * fTemp22))))))) - ((0.0096296490000000005 * fTemp20) + (0.0256163378 * fTemp19))))));
			fRec444[0] = (fRec444[1] + fTemp141);
			fRec442[0] = fRec444[0];
			double fRec443 = fTemp141;
			fRec441[0] = (fRec442[0] + fRec441[1]);
			fRec439[0] = fRec441[0];
			double fRec440 = fRec443;
			double fTemp142 = (fRec440 + (fConst8 * (0.0 - ((fConst10 * fRec436[1]) + (fConst9 * fRec433[1])))));
			fRec438[0] = (fRec438[1] + fTemp142);
			fRec436[0] = fRec438[0];
			double fRec437 = fTemp142;
			fRec435[0] = (fRec436[0] + fRec435[1]);
			fRec433[0] = fRec435[0];
			double fRec434 = fRec437;
			fVec5[(IOTA & 1023)] = (((0.0017019273999999999 * fTemp10) + ((0.0116470711 * fTemp76) + ((0.0033767501 * fTemp78) + ((0.0019902697 * fTemp11) + (((0.0122919182 * fTemp13) + (fRec383 + (fRec389 + (fRec392 + (fRec410 + (fRec425 + fRec434)))))) + (0.0029188317 * fTemp80)))))) - ((0.046341117000000001 * fTemp7) + ((0.010534834099999999 * fTemp75) + ((0.0120454425 * fTemp8) + ((0.033840242800000003 * fTemp9) + ((0.050587403099999997 * fTemp77) + ((0.035429654800000002 * fTemp79) + ((0.0042928784000000001 * fTemp12) + ((0.020589832299999999 * fTemp74) + ((0.039580930799999997 * fTemp81) + (0.057121018400000001 * fTemp82)))))))))));
			output5[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec5[((IOTA - iConst44) & 1023)])));
			double fTemp143 = (fConst12 * (0.0 - ((fConst14 * fRec448[1]) + (fConst13 * fRec445[1]))));
			double fTemp144 = (fConst16 * (0.0 - ((fConst18 * fRec454[1]) + (fConst17 * fRec451[1]))));
			double fTemp145 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec460[1]) + (fConst20 * fRec457[1])))) + (fConst22 * (((0.00026450319999999999 * fTemp33) + ((0.059754255399999998 * fTemp35) + (((0.0124947644 * fTemp36) + (0.0149024243 * fTemp28)) + (0.0157702004 * fTemp30)))) - ((0.0499270297 * fTemp34) + ((0.00045650600000000002 * fTemp32) + ((((((0.058024985699999997 * fTemp37) + (0.060204108999999999 * fTemp27)) + (0.0113756619 * fTemp29)) + (0.033380040999999999 * fTemp31)) + (0.049177024299999997 * fTemp38)) + (0.033068080800000003 * fTemp39))))))));
			fRec462[0] = (fRec462[1] + fTemp145);
			fRec460[0] = fRec462[0];
			double fRec461 = fTemp145;
			fRec459[0] = (fRec460[0] + fRec459[1]);
			fRec457[0] = fRec459[0];
			double fRec458 = fRec461;
			fRec456[0] = (fTemp144 + (fRec458 + fRec456[1]));
			fRec454[0] = fRec456[0];
			double fRec455 = (fRec458 + fTemp144);
			fRec453[0] = (fRec454[0] + fRec453[1]);
			fRec451[0] = fRec453[0];
			double fRec452 = fRec455;
			fRec450[0] = (fTemp143 + (fRec452 + fRec450[1]));
			fRec448[0] = fRec450[0];
			double fRec449 = (fRec452 + fTemp143);
			fRec447[0] = (fRec448[0] + fRec447[1]);
			fRec445[0] = fRec447[0];
			double fRec446 = fRec449;
			double fTemp146 = (fConst35 * (0.0 - ((fConst37 * fRec469[1]) + (fConst36 * fRec466[1]))));
			double fTemp147 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec475[1]) + (fConst39 * fRec472[1])))) + (fConst42 * (((((0.0014151623000000001 * fTemp68) + (0.048307506100000001 * fTemp62)) + (0.066434772200000006 * fTemp69)) + (0.057966219999999999 * fTemp70)) - (((0.012138807499999999 * fTemp65) + ((0.040584202 * fTemp61) + ((0.047938293399999998 * fTemp66) + (((0.0228035904 * fTemp67) + (0.0023358551 * fTemp63)) + (0.01402425 * fTemp64))))) + (0.057222960099999998 * fTemp71))))));
			fRec477[0] = (fRec477[1] + fTemp147);
			fRec475[0] = fRec477[0];
			double fRec476 = fTemp147;
			fRec474[0] = (fRec475[0] + fRec474[1]);
			fRec472[0] = fRec474[0];
			double fRec473 = fRec476;
			fRec471[0] = (fTemp146 + (fRec473 + fRec471[1]));
			fRec469[0] = fRec471[0];
			double fRec470 = (fRec473 + fTemp146);
			fRec468[0] = (fRec469[0] + fRec468[1]);
			fRec466[0] = fRec468[0];
			double fRec467 = fRec470;
			double fTemp148 = (fConst43 * fRec463[1]);
			fRec465[0] = ((fRec467 + fRec465[1]) - fTemp148);
			fRec463[0] = fRec465[0];
			double fRec464 = (fRec467 - fTemp148);
			double fTemp149 = (fConst8 * (0.0 - ((fConst10 * fRec481[1]) + (fConst9 * fRec478[1]))));
			double fTemp150 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec487[1]) + (fConst6 * fRec484[1])))) + (fConst4 * (((0.025197047399999999 * fTemp17) + ((0.012022150699999999 * fTemp16) + ((0.028667159899999999 * fTemp19) + ((0.010633501199999999 * fTemp20) + ((0.059324873399999999 * fTemp15) + ((0.066867708799999995 * fTemp21) + (0.059584912800000001 * fTemp22))))))) - ((0.048992253800000003 * fTemp14) + (0.0123857741 * fTemp18))))));
			fRec489[0] = (fRec489[1] + fTemp150);
			fRec487[0] = fRec489[0];
			double fRec488 = fTemp150;
			fRec486[0] = (fRec487[0] + fRec486[1]);
			fRec484[0] = fRec486[0];
			double fRec485 = fRec488;
			fRec483[0] = (fTemp149 + (fRec485 + fRec483[1]));
			fRec481[0] = fRec483[0];
			double fRec482 = (fRec485 + fTemp149);
			fRec480[0] = (fRec481[0] + fRec480[1]);
			fRec478[0] = fRec480[0];
			double fRec479 = fRec482;
			double fTemp151 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec496[1]) + (fConst26 * fRec493[1])))) + (fConst25 * (((0.065176320100000004 * fTemp41) + ((0.0073694848000000002 * fTemp45) + ((0.036925357200000002 * fTemp46) + ((0.016109718799999999 * fTemp42) + (0.036341354100000001 * fTemp47))))) - ((0.040936488600000001 * fTemp44) + (0.053000679199999998 * fTemp43))))));
			fRec498[0] = (fRec498[1] + fTemp151);
			fRec496[0] = fRec498[0];
			double fRec497 = fTemp151;
			fRec495[0] = (fRec496[0] + fRec495[1]);
			fRec493[0] = fRec495[0];
			double fRec494 = fRec497;
			double fTemp152 = (fConst28 * fRec490[1]);
			fRec492[0] = ((fRec494 + fRec492[1]) - fTemp152);
			fRec490[0] = fRec492[0];
			double fRec491 = (fRec494 - fTemp152);
			double fTemp153 = (fConst29 * (((0.021678712900000001 * fTemp50) - ((((0.039613074499999998 * fTemp51) + (0.031534986899999999 * fTemp54)) + (0.0057907998000000004 * fTemp52)) + (0.062392304500000002 * fTemp53))) + (fConst5 * (0.0 - ((fConst31 * fRec502[1]) + (fConst30 * fRec499[1]))))));
			fRec504[0] = (fRec504[1] + fTemp153);
			fRec502[0] = fRec504[0];
			double fRec503 = fTemp153;
			fRec501[0] = (fRec502[0] + fRec501[1]);
			fRec499[0] = fRec501[0];
			double fRec500 = fRec503;
			double fTemp154 = (fConst32 * (((0.015210262699999999 * fTemp57) - ((0.0496797462 * fTemp56) + (0.0082717251999999998 * fTemp58))) - (fConst33 * fRec505[1])));
			fRec507[0] = (fRec507[1] + fTemp154);
			fRec505[0] = fRec507[0];
			double fRec506 = fTemp154;
			fVec6[(IOTA & 1023)] = (((0.0089488481000000002 * fTemp8) + ((0.0525920135 * fTemp77) + ((0.017844169300000001 * fTemp78) + ((0.0203264776 * fTemp74) + ((0.0400960936 * fTemp81) + ((0.017975970800000001 * fTemp13) + (fRec446 + (fRec464 + (fRec479 + (fRec491 + (fRec500 + (fRec506 + (0.056510982100000003 * fTemp82))))))))))))) - ((0.0460210697 * fTemp7) + (((((0.0079785451999999993 * fTemp76) + ((((0.024193057800000001 * fTemp80) + (0.032452055799999997 * fTemp12)) + (0.032694955999999997 * fTemp79)) + (0.0030662656000000001 * fTemp11))) + (0.0045450949000000003 * fTemp10)) + (0.044344137200000001 * fTemp9)) + (0.0374274707 * fTemp75))));
			output6[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec6[((IOTA - iConst44) & 1023)])));
			double fTemp155 = (fConst8 * (0.0 - ((fConst10 * fRec511[1]) + (fConst9 * fRec508[1]))));
			double fTemp156 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec517[1]) + (fConst6 * fRec514[1])))) + (fConst4 * (((0.011587758 * fTemp17) + ((0.0192760441 * fTemp16) + (((0.036750531599999997 * fTemp21) + (0.0243021465 * fTemp20)) + (0.040540927999999997 * fTemp19)))) - ((0.030971286099999999 * fTemp18) + ((0.0069781104999999998 * fTemp15) + ((0.043278828399999997 * fTemp14) + (0.044338717499999999 * fTemp22))))))));
			fRec519[0] = (fRec519[1] + fTemp156);
			fRec517[0] = fRec519[0];
			double fRec518 = fTemp156;
			fRec516[0] = (fRec517[0] + fRec516[1]);
			fRec514[0] = fRec516[0];
			double fRec515 = fRec518;
			fRec513[0] = (fTemp155 + (fRec515 + fRec513[1]));
			fRec511[0] = fRec513[0];
			double fRec512 = (fRec515 + fTemp155);
			fRec510[0] = (fRec511[0] + fRec510[1]);
			fRec508[0] = fRec510[0];
			double fRec509 = fRec512;
			double fTemp157 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec526[1]) + (fConst26 * fRec523[1])))) + (fConst25 * (((0.0201492983 * fTemp45) + ((0.029449540699999999 * fTemp46) + ((0.0299154498 * fTemp42) + (0.055988441100000001 * fTemp47)))) - ((0.024573141400000002 * fTemp44) + ((0.011600321199999999 * fTemp41) + (0.0130363411 * fTemp43)))))));
			fRec528[0] = (fRec528[1] + fTemp157);
			fRec526[0] = fRec528[0];
			double fRec527 = fTemp157;
			fRec525[0] = (fRec526[0] + fRec525[1]);
			fRec523[0] = fRec525[0];
			double fRec524 = fRec527;
			double fTemp158 = (fConst28 * fRec520[1]);
			fRec522[0] = ((fRec524 + fRec522[1]) - fTemp158);
			fRec520[0] = fRec522[0];
			double fRec521 = (fRec524 - fTemp158);
			double fTemp159 = (fConst29 * (((0.044987742599999998 * fTemp50) - ((((0.018839948299999999 * fTemp51) + (0.025355001700000001 * fTemp54)) + (0.0123225125 * fTemp52)) + (0.018405412699999998 * fTemp53))) + (fConst5 * (0.0 - ((fConst31 * fRec532[1]) + (fConst30 * fRec529[1]))))));
			fRec534[0] = (fRec534[1] + fTemp159);
			fRec532[0] = fRec534[0];
			double fRec533 = fTemp159;
			fRec531[0] = (fRec532[0] + fRec531[1]);
			fRec529[0] = fRec531[0];
			double fRec530 = fRec533;
			double fTemp160 = (fConst32 * (((0.0082610322000000007 * fTemp57) - ((0.029775918200000001 * fTemp56) + (0.019964574700000001 * fTemp58))) - (fConst33 * fRec535[1])));
			fRec537[0] = (fRec537[1] + fTemp160);
			fRec535[0] = fRec537[0];
			double fRec536 = fTemp160;
			double fTemp161 = (fConst38 * ((fConst42 * (((0.0077157511000000003 * fTemp65) + ((0.062261776400000003 * fTemp66) + ((0.035693073999999998 * fTemp62) + (0.019416985800000001 * fTemp69)))) - ((((0.0346117404 * fTemp61) + ((((0.046266806299999998 * fTemp67) + (0.0148455471 * fTemp68)) + (0.0109410863 * fTemp63)) + (0.027441622499999999 * fTemp64))) + (0.032379551399999998 * fTemp70)) + (0.0113202961 * fTemp71)))) + (fConst5 * (0.0 - ((fConst40 * fRec550[1]) + (fConst39 * fRec547[1]))))));
			fRec552[0] = (fRec552[1] + fTemp161);
			fRec550[0] = fRec552[0];
			double fRec551 = fTemp161;
			fRec549[0] = (fRec550[0] + fRec549[1]);
			fRec547[0] = fRec549[0];
			double fRec548 = fRec551;
			double fTemp162 = (fRec548 + (fConst35 * (0.0 - ((fConst37 * fRec544[1]) + (fConst36 * fRec541[1])))));
			fRec546[0] = (fRec546[1] + fTemp162);
			fRec544[0] = fRec546[0];
			double fRec545 = fTemp162;
			fRec543[0] = (fRec544[0] + fRec543[1]);
			fRec541[0] = fRec543[0];
			double fRec542 = fRec545;
			double fTemp163 = (fConst43 * fRec538[1]);
			fRec540[0] = ((fRec542 + fRec540[1]) - fTemp163);
			fRec538[0] = fRec540[0];
			double fRec539 = (fRec542 - fTemp163);
			double fTemp164 = (fConst12 * (0.0 - ((fConst14 * fRec556[1]) + (fConst13 * fRec553[1]))));
			double fTemp165 = (fConst16 * (0.0 - ((fConst18 * fRec562[1]) + (fConst17 * fRec559[1]))));
			double fTemp166 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec568[1]) + (fConst20 * fRec565[1])))) + (fConst22 * (((0.0095285165000000005 * fTemp33) + ((0.049611082600000002 * fTemp34) + ((0.018392361199999999 * fTemp32) + (((0.0134453318 * fTemp36) + (0.010365760999999999 * fTemp37)) + (0.056359816299999997 * fTemp39))))) - ((0.024732047399999998 * fTemp35) + ((((((0.043687384000000003 * fTemp27) + (0.0041504780999999996 * fTemp28)) + (0.029464111500000001 * fTemp29)) + (0.0018082731 * fTemp30)) + (0.051939578299999997 * fTemp31)) + (0.0120089367 * fTemp38)))))));
			fRec570[0] = (fRec570[1] + fTemp166);
			fRec568[0] = fRec570[0];
			double fRec569 = fTemp166;
			fRec567[0] = (fRec568[0] + fRec567[1]);
			fRec565[0] = fRec567[0];
			double fRec566 = fRec569;
			fRec564[0] = (fTemp165 + (fRec566 + fRec564[1]));
			fRec562[0] = fRec564[0];
			double fRec563 = (fRec566 + fTemp165);
			fRec561[0] = (fRec562[0] + fRec561[1]);
			fRec559[0] = fRec561[0];
			double fRec560 = fRec563;
			fRec558[0] = (fTemp164 + (fRec560 + fRec558[1]));
			fRec556[0] = fRec558[0];
			double fRec557 = (fRec560 + fTemp164);
			fRec555[0] = (fRec556[0] + fRec555[1]);
			fRec553[0] = fRec555[0];
			double fRec554 = fRec557;
			fVec7[(IOTA & 1023)] = (((0.0489478624 * fTemp75) + ((0.037593730800000003 * fTemp9) + ((0.00058553149999999998 * fTemp10) + ((0.047748904699999997 * fTemp74) + (((0.0124723197 * fTemp13) + (fRec509 + (fRec521 + (fRec530 + (fRec536 + (fRec539 + fRec554)))))) + (0.036720774099999999 * fTemp81)))))) - ((0.018729702300000001 * fTemp7) + ((0.0016526780000000001 * fTemp8) + ((0.016703949900000001 * fTemp76) + ((0.017453575400000001 * fTemp77) + ((0.030622983699999998 * fTemp78) + ((0.0017647177000000001 * fTemp11) + ((0.035865281200000002 * fTemp79) + ((0.004490997 * fTemp12) + ((0.0033464048000000001 * fTemp80) + (0.048371075499999999 * fTemp82)))))))))));
			output7[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec7[((IOTA - iConst44) & 1023)])));
			double fTemp167 = (fConst12 * (0.0 - ((fConst14 * fRec574[1]) + (fConst13 * fRec571[1]))));
			double fTemp168 = (fConst16 * (0.0 - ((fConst18 * fRec580[1]) + (fConst17 * fRec577[1]))));
			double fTemp169 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec586[1]) + (fConst20 * fRec583[1])))) + (fConst22 * (((((0.062514975799999997 * fTemp37) + (0.013457263400000001 * fTemp28)) + (0.00060701069999999997 * fTemp30)) + (0.068512749900000003 * fTemp38)) - ((0.0143993075 * fTemp33) + ((0.0030952288000000001 * fTemp34) + ((0.028250781499999999 * fTemp35) + ((0.00029280050000000002 * fTemp32) + (((((0.0129732426 * fTemp36) + (0.032286395799999999 * fTemp27)) + (0.048590010199999999 * fTemp29)) + (0.014542539300000001 * fTemp31)) + (0.0618066481 * fTemp39))))))))));
			fRec588[0] = (fRec588[1] + fTemp169);
			fRec586[0] = fRec588[0];
			double fRec587 = fTemp169;
			fRec585[0] = (fRec586[0] + fRec585[1]);
			fRec583[0] = fRec585[0];
			double fRec584 = fRec587;
			fRec582[0] = (fTemp168 + (fRec584 + fRec582[1]));
			fRec580[0] = fRec582[0];
			double fRec581 = (fRec584 + fTemp168);
			fRec579[0] = (fRec580[0] + fRec579[1]);
			fRec577[0] = fRec579[0];
			double fRec578 = fRec581;
			fRec576[0] = (fTemp167 + (fRec578 + fRec576[1]));
			fRec574[0] = fRec576[0];
			double fRec575 = (fRec578 + fTemp167);
			fRec573[0] = (fRec574[0] + fRec573[1]);
			fRec571[0] = fRec573[0];
			double fRec572 = fRec575;
			double fTemp170 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec595[1]) + (fConst26 * fRec592[1])))) + (fConst25 * (((0.0161223445 * fTemp43) + ((0.0301244596 * fTemp45) + ((0.019507073100000001 * fTemp46) + ((0.049535040099999997 * fTemp42) + (0.016962588099999999 * fTemp47))))) - ((0.069074658100000005 * fTemp41) + (0.038324688000000003 * fTemp44))))));
			fRec597[0] = (fRec597[1] + fTemp170);
			fRec595[0] = fRec597[0];
			double fRec596 = fTemp170;
			fRec594[0] = (fRec595[0] + fRec594[1]);
			fRec592[0] = fRec594[0];
			double fRec593 = fRec596;
			double fTemp171 = (fConst28 * fRec589[1]);
			fRec591[0] = ((fRec593 + fRec591[1]) - fTemp171);
			fRec589[0] = fRec591[0];
			double fRec590 = (fRec593 - fTemp171);
			double fTemp172 = (fConst35 * (0.0 - ((fConst37 * fRec604[1]) + (fConst36 * fRec601[1]))));
			double fTemp173 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec610[1]) + (fConst39 * fRec607[1])))) + (fConst42 * ((((0.018298455799999998 * fTemp65) + ((0.041279645400000002 * fTemp61) + (((0.0022093131000000001 * fTemp68) + (0.045625803800000003 * fTemp62)) + (0.0022493434000000001 * fTemp64)))) + (0.072113317499999996 * fTemp71)) - (((0.0109362105 * fTemp66) + (((0.062492380200000003 * fTemp67) + (0.0013791459999999999 * fTemp63)) + (0.023001939999999998 * fTemp69))) + (0.054088906300000003 * fTemp70))))));
			fRec612[0] = (fRec612[1] + fTemp173);
			fRec610[0] = fRec612[0];
			double fRec611 = fTemp173;
			fRec609[0] = (fRec610[0] + fRec609[1]);
			fRec607[0] = fRec609[0];
			double fRec608 = fRec611;
			fRec606[0] = (fTemp172 + (fRec608 + fRec606[1]));
			fRec604[0] = fRec606[0];
			double fRec605 = (fRec608 + fTemp172);
			fRec603[0] = (fRec604[0] + fRec603[1]);
			fRec601[0] = fRec603[0];
			double fRec602 = fRec605;
			double fTemp174 = (fConst43 * fRec598[1]);
			fRec600[0] = ((fRec602 + fRec600[1]) - fTemp174);
			fRec598[0] = fRec600[0];
			double fRec599 = (fRec602 - fTemp174);
			double fTemp175 = (fConst8 * (0.0 - ((fConst10 * fRec616[1]) + (fConst9 * fRec613[1]))));
			double fTemp176 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec622[1]) + (fConst6 * fRec619[1])))) + (fConst4 * (((0.0118083966 * fTemp16) + ((((0.049946477699999998 * fTemp14) + (0.036857610700000001 * fTemp21)) + (0.0519347904 * fTemp20)) + (0.0187913896 * fTemp19))) - ((0.0127271378 * fTemp17) + ((0.024001714399999999 * fTemp18) + ((0.059644737699999999 * fTemp15) + (0.055027506099999998 * fTemp22))))))));
			fRec624[0] = (fRec624[1] + fTemp176);
			fRec622[0] = fRec624[0];
			double fRec623 = fTemp176;
			fRec621[0] = (fRec622[0] + fRec621[1]);
			fRec619[0] = fRec621[0];
			double fRec620 = fRec623;
			fRec618[0] = (fTemp175 + (fRec620 + fRec618[1]));
			fRec616[0] = fRec618[0];
			double fRec617 = (fRec620 + fTemp175);
			fRec615[0] = (fRec616[0] + fRec615[1]);
			fRec613[0] = fRec615[0];
			double fRec614 = fRec617;
			double fTemp177 = (fConst29 * ((((0.058517032400000002 * fTemp50) + (0.021888716200000002 * fTemp53)) - (((0.022070168599999999 * fTemp51) + (0.029800104599999998 * fTemp54)) + (0.030228014500000001 * fTemp52))) + (fConst5 * (0.0 - ((fConst31 * fRec628[1]) + (fConst30 * fRec625[1]))))));
			fRec630[0] = (fRec630[1] + fTemp177);
			fRec628[0] = fRec630[0];
			double fRec629 = fTemp177;
			fRec627[0] = (fRec628[0] + fRec627[1]);
			fRec625[0] = fRec627[0];
			double fRec626 = fRec629;
			double fTemp178 = (fConst32 * (((0.0141814517 * fTemp57) - ((0.027112731000000001 * fTemp56) + (0.038888796500000003 * fTemp58))) - (fConst33 * fRec631[1])));
			fRec633[0] = (fRec633[1] + fTemp178);
			fRec631[0] = fRec633[0];
			double fRec632 = fTemp178;
			fVec8[(IOTA & 1023)] = (((0.020750693000000001 * fTemp7) + ((0.041187480899999997 * fTemp9) + ((0.01280363 * fTemp76) + ((0.050782886499999999 * fTemp78) + ((0.0438273343 * fTemp74) + ((0.0191981861 * fTemp80) + ((0.0168837615 * fTemp13) + (fRec572 + (fRec590 + (fRec599 + (fRec614 + (fRec626 + (fRec632 + (0.032647432499999997 * fTemp82)))))))))))))) - (((((0.033993080799999999 * fTemp77) + ((((0.041084915399999998 * fTemp81) + (0.019193140099999999 * fTemp12)) + (0.031457486299999997 * fTemp79)) + (0.023306426500000001 * fTemp11))) + (0.013149334400000001 * fTemp10)) + (3.1268500000000001e-05 * fTemp8)) + (0.055019865199999997 * fTemp75)));
			output8[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec8[((IOTA - iConst44) & 1023)])));
			double fTemp179 = (fConst8 * (0.0 - ((fConst10 * fRec637[1]) + (fConst9 * fRec634[1]))));
			double fTemp180 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec643[1]) + (fConst6 * fRec640[1])))) + (fConst4 * (((0.0118156072 * fTemp16) + ((0.062258726200000003 * fTemp20) + ((0.041266226699999999 * fTemp14) + ((0.0082876245000000001 * fTemp21) + (0.060838951699999998 * fTemp22))))) - ((0.024689827000000001 * fTemp17) + ((0.010982688500000001 * fTemp18) + ((0.022433164799999999 * fTemp15) + (0.0574520164 * fTemp19))))))));
			fRec645[0] = (fRec645[1] + fTemp180);
			fRec643[0] = fRec645[0];
			double fRec644 = fTemp180;
			fRec642[0] = (fRec643[0] + fRec642[1]);
			fRec640[0] = fRec642[0];
			double fRec641 = fRec644;
			fRec639[0] = (fTemp179 + (fRec641 + fRec639[1]));
			fRec637[0] = fRec639[0];
			double fRec638 = (fRec641 + fTemp179);
			fRec636[0] = (fRec637[0] + fRec636[1]);
			fRec634[0] = fRec636[0];
			double fRec635 = fRec638;
			double fTemp181 = (fConst32 * (((0.0139324784 * fTemp57) - ((0.0065763686000000002 * fTemp56) + (0.046251340600000003 * fTemp58))) - (fConst33 * fRec646[1])));
			fRec648[0] = (fRec648[1] + fTemp181);
			fRec646[0] = fRec648[0];
			double fRec647 = fTemp181;
			double fTemp182 = (fConst12 * (0.0 - ((fConst14 * fRec652[1]) + (fConst13 * fRec649[1]))));
			double fTemp183 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec664[1]) + (fConst20 * fRec661[1])))) + (fConst22 * (((0.0018209096999999999 * fTemp33) + ((0.054179180899999999 * fTemp35) + ((((0.0276365664 * fTemp37) + (0.013128503099999999 * fTemp28)) + (0.057294956000000001 * fTemp31)) + (0.040346523699999998 * fTemp39)))) - ((0.041159858399999999 * fTemp34) + ((0.0015511481000000001 * fTemp32) + (((((0.013068481200000001 * fTemp36) + (0.0094054341999999999 * fTemp27)) + (0.057101793800000002 * fTemp29)) + (0.0139767061 * fTemp30)) + (0.054120065600000003 * fTemp38))))))));
			fRec666[0] = (fRec666[1] + fTemp183);
			fRec664[0] = fRec666[0];
			double fRec665 = fTemp183;
			fRec663[0] = (fRec664[0] + fRec663[1]);
			fRec661[0] = fRec663[0];
			double fRec662 = fRec665;
			double fTemp184 = (fRec662 + (fConst16 * (0.0 - ((fConst18 * fRec658[1]) + (fConst17 * fRec655[1])))));
			fRec660[0] = (fRec660[1] + fTemp184);
			fRec658[0] = fRec660[0];
			double fRec659 = fTemp184;
			fRec657[0] = (fRec658[0] + fRec657[1]);
			fRec655[0] = fRec657[0];
			double fRec656 = fRec659;
			fRec654[0] = (fTemp182 + (fRec656 + fRec654[1]));
			fRec652[0] = fRec654[0];
			double fRec653 = (fRec656 + fTemp182);
			fRec651[0] = (fRec652[0] + fRec651[1]);
			fRec649[0] = fRec651[0];
			double fRec650 = fRec653;
			double fTemp185 = (fConst35 * (0.0 - ((fConst37 * fRec673[1]) + (fConst36 * fRec670[1]))));
			double fTemp186 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec679[1]) + (fConst39 * fRec676[1])))) + (fConst42 * ((((0.013317236099999999 * fTemp65) + ((0.0327089115 * fTemp61) + (((0.045111884300000002 * fTemp62) + (0.0002356081 * fTemp63)) + (0.0128097195 * fTemp64)))) + (0.058772782599999997 * fTemp70)) - (((0.049797252799999997 * fTemp66) + (((0.018255908599999999 * fTemp67) + (0.0026237346000000002 * fTemp68)) + (0.063240645999999998 * fTemp69))) + (0.052425355 * fTemp71))))));
			fRec681[0] = (fRec681[1] + fTemp186);
			fRec679[0] = fRec681[0];
			double fRec680 = fTemp186;
			fRec678[0] = (fRec679[0] + fRec678[1]);
			fRec676[0] = fRec678[0];
			double fRec677 = fRec680;
			fRec675[0] = (fTemp185 + (fRec677 + fRec675[1]));
			fRec673[0] = fRec675[0];
			double fRec674 = (fRec677 + fTemp185);
			fRec672[0] = (fRec673[0] + fRec672[1]);
			fRec670[0] = fRec672[0];
			double fRec671 = fRec674;
			double fTemp187 = (fConst43 * fRec667[1]);
			fRec669[0] = ((fRec671 + fRec669[1]) - fTemp187);
			fRec667[0] = fRec669[0];
			double fRec668 = (fRec671 - fTemp187);
			double fTemp188 = (fConst29 * ((((0.017464497700000001 * fTemp50) + (0.0590953917 * fTemp53)) - (((0.0043610463999999996 * fTemp51) + (0.029421955199999999 * fTemp54)) + (0.036541627 * fTemp52))) + (fConst5 * (0.0 - ((fConst31 * fRec685[1]) + (fConst30 * fRec682[1]))))));
			fRec687[0] = (fRec687[1] + fTemp188);
			fRec685[0] = fRec687[0];
			double fRec686 = fTemp188;
			fRec684[0] = (fRec685[0] + fRec684[1]);
			fRec682[0] = fRec684[0];
			double fRec683 = fRec686;
			double fTemp189 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec694[1]) + (fConst26 * fRec691[1])))) + (fConst25 * (((((0.012327579599999999 * fTemp42) + (0.0062190835 * fTemp46)) + (0.034988735799999997 * fTemp45)) + (0.049783050099999997 * fTemp43)) - ((0.037730066700000002 * fTemp44) + ((0.029840964599999999 * fTemp41) + (0.063589060399999994 * fTemp47)))))));
			fRec696[0] = (fRec696[1] + fTemp189);
			fRec694[0] = fRec696[0];
			double fRec695 = fTemp189;
			fRec693[0] = (fRec694[0] + fRec693[1]);
			fRec691[0] = fRec693[0];
			double fRec692 = fRec695;
			double fTemp190 = (fConst28 * fRec688[1]);
			fRec690[0] = ((fRec692 + fRec690[1]) - fTemp190);
			fRec688[0] = fRec690[0];
			double fRec689 = (fRec692 - fTemp190);
			fVec9[(IOTA & 1023)] = (((0.045004953200000003 * fTemp7) + ((0.044814246600000003 * fTemp75) + ((0.022952476600000001 * fTemp10) + ((0.0107947805 * fTemp76) + ((0.046182687299999997 * fTemp77) + ((0.0175081965 * fTemp74) + (((0.016628879499999999 * fTemp13) + (fRec635 + (fRec647 + (fRec650 + (fRec668 + (fRec683 + fRec689)))))) + (0.0015051155 * fTemp80)))))))) - ((0.007383845 * fTemp8) + ((0.046344745 * fTemp9) + ((0.053947395500000002 * fTemp78) + ((0.0296962775 * fTemp11) + ((0.031366335699999998 * fTemp79) + ((0.001711796 * fTemp12) + ((0.034581200300000003 * fTemp81) + (0.026762998900000001 * fTemp82)))))))));
			output9[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec9[((IOTA - iConst44) & 1023)])));
			double fTemp191 = (fConst12 * (0.0 - ((fConst14 * fRec700[1]) + (fConst13 * fRec697[1]))));
			double fTemp192 = (fConst16 * (0.0 - ((fConst18 * fRec706[1]) + (fConst17 * fRec703[1]))));
			double fTemp193 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec712[1]) + (fConst20 * fRec709[1])))) + (fConst22 * (((0.046348053399999999 * fTemp34) + (((((0.0155667012 * fTemp36) + (0.011284290400000001 * fTemp27)) + (0.0096531111000000003 * fTemp30)) + (0.0407235019 * fTemp31)) + (0.0147881122 * fTemp39))) - ((0.0025207889999999998 * fTemp33) + ((0.059697163599999999 * fTemp35) + ((0.016757690400000001 * fTemp32) + ((((0.032459502100000003 * fTemp37) + (0.0044148659999999999 * fTemp28)) + (0.050421359200000002 * fTemp29)) + (0.019961367899999999 * fTemp38)))))))));
			fRec714[0] = (fRec714[1] + fTemp193);
			fRec712[0] = fRec714[0];
			double fRec713 = fTemp193;
			fRec711[0] = (fRec712[0] + fRec711[1]);
			fRec709[0] = fRec711[0];
			double fRec710 = fRec713;
			fRec708[0] = (fTemp192 + (fRec710 + fRec708[1]));
			fRec706[0] = fRec708[0];
			double fRec707 = (fRec710 + fTemp192);
			fRec705[0] = (fRec706[0] + fRec705[1]);
			fRec703[0] = fRec705[0];
			double fRec704 = fRec707;
			fRec702[0] = (fTemp191 + (fRec704 + fRec702[1]));
			fRec700[0] = fRec702[0];
			double fRec701 = (fRec704 + fTemp191);
			fRec699[0] = (fRec700[0] + fRec699[1]);
			fRec697[0] = fRec699[0];
			double fRec698 = fRec701;
			double fTemp194 = (fConst35 * (0.0 - ((fConst37 * fRec721[1]) + (fConst36 * fRec718[1]))));
			double fTemp195 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec727[1]) + (fConst39 * fRec724[1])))) + (fConst42 * ((((0.056261408200000002 * fTemp66) + ((((0.021551177500000001 * fTemp67) + (0.0033077484999999998 * fTemp68)) + (0.034940235600000001 * fTemp62)) + (0.0234773343 * fTemp64))) + (0.027837470499999999 * fTemp70)) - (((0.0159802691 * fTemp65) + ((0.037431765899999997 * fTemp61) + ((0.0181908686 * fTemp63) + (0.044212142400000001 * fTemp69)))) + (0.028143733000000001 * fTemp71))))));
			fRec729[0] = (fRec729[1] + fTemp195);
			fRec727[0] = fRec729[0];
			double fRec728 = fTemp195;
			fRec726[0] = (fRec727[0] + fRec726[1]);
			fRec724[0] = fRec726[0];
			double fRec725 = fRec728;
			fRec723[0] = (fTemp194 + (fRec725 + fRec723[1]));
			fRec721[0] = fRec723[0];
			double fRec722 = (fRec725 + fTemp194);
			fRec720[0] = (fRec721[0] + fRec720[1]);
			fRec718[0] = fRec720[0];
			double fRec719 = fRec722;
			double fTemp196 = (fConst43 * fRec715[1]);
			fRec717[0] = ((fRec719 + fRec717[1]) - fTemp196);
			fRec715[0] = fRec717[0];
			double fRec716 = (fRec719 - fTemp196);
			double fTemp197 = (fConst8 * (0.0 - ((fConst10 * fRec733[1]) + (fConst9 * fRec730[1]))));
			double fTemp198 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec739[1]) + (fConst6 * fRec736[1])))) + (fConst4 * (((0.019120708300000001 * fTemp16) + ((0.013207497 * fTemp18) + ((0.041974533299999998 * fTemp20) + ((0.025970928300000001 * fTemp15) + (0.038781112700000002 * fTemp22))))) - ((0.029980714499999998 * fTemp17) + (((0.047522182699999999 * fTemp14) + (0.0097923941000000007 * fTemp21)) + (0.0308817529 * fTemp19)))))));
			fRec741[0] = (fRec741[1] + fTemp198);
			fRec739[0] = fRec741[0];
			double fRec740 = fTemp198;
			fRec738[0] = (fRec739[0] + fRec738[1]);
			fRec736[0] = fRec738[0];
			double fRec737 = fRec740;
			fRec735[0] = (fTemp197 + (fRec737 + fRec735[1]));
			fRec733[0] = fRec735[0];
			double fRec734 = (fRec737 + fTemp197);
			fRec732[0] = (fRec733[0] + fRec732[1]);
			fRec730[0] = fRec732[0];
			double fRec731 = fRec734;
			double fTemp199 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec748[1]) + (fConst26 * fRec745[1])))) + (fConst25 * (((0.034846283499999998 * fTemp41) + ((0.034412267900000001 * fTemp45) + (0.028511208400000002 * fTemp43))) - ((0.024013405000000002 * fTemp44) + ((0.0074658054 * fTemp46) + ((0.0143775897 * fTemp42) + (0.044376183100000001 * fTemp47))))))));
			fRec750[0] = (fRec750[1] + fTemp199);
			fRec748[0] = fRec750[0];
			double fRec749 = fTemp199;
			fRec747[0] = (fRec748[0] + fRec747[1]);
			fRec745[0] = fRec747[0];
			double fRec746 = fRec749;
			double fTemp200 = (fConst28 * fRec742[1]);
			fRec744[0] = ((fRec746 + fRec744[1]) - fTemp200);
			fRec742[0] = fRec744[0];
			double fRec743 = (fRec746 - fTemp200);
			double fTemp201 = (fConst32 * ((((0.0077890746999999998 * fTemp56) + (0.0080658692000000008 * fTemp57)) - (0.034369076700000001 * fTemp58)) - (fConst33 * fRec751[1])));
			fRec753[0] = (fRec753[1] + fTemp201);
			fRec751[0] = fRec753[0];
			double fRec752 = fTemp201;
			double fTemp202 = (fConst29 * ((((0.0051041465000000001 * fTemp51) + (0.043200536400000003 * fTemp53)) - (((0.0205832842 * fTemp50) + (0.0249576325 * fTemp54)) + (0.021394325400000001 * fTemp52))) + (fConst5 * (0.0 - ((fConst31 * fRec757[1]) + (fConst30 * fRec754[1]))))));
			fRec759[0] = (fRec759[1] + fTemp202);
			fRec757[0] = fRec759[0];
			double fRec758 = fTemp202;
			fRec756[0] = (fRec757[0] + fRec756[1]);
			fRec754[0] = fRec756[0];
			double fRec755 = fRec758;
			fVec10[(IOTA & 1023)] = (((0.045836171799999999 * fTemp7) + ((0.0088631287999999999 * fTemp75) + ((0.011372537 * fTemp8) + ((0.057560607299999997 * fTemp78) + ((0.0018803833999999999 * fTemp12) + (((0.0122519133 * fTemp13) + (fRec698 + (fRec716 + (fRec731 + (fRec743 + (fRec752 + fRec755)))))) + (0.040220239099999999 * fTemp81))))))) - ((0.032788705000000001 * fTemp9) + ((0.0032543203999999999 * fTemp10) + ((0.0126561902 * fTemp76) + ((0.050905112400000001 * fTemp77) + ((0.0037601900000000001 * fTemp11) + ((0.035216522299999997 * fTemp79) + ((0.0210362963 * fTemp74) + ((0.0013469698 * fTemp80) + (0.001205303 * fTemp82))))))))));
			output10[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec10[((IOTA - iConst44) & 1023)])));
			double fTemp203 = (fConst8 * (0.0 - ((fConst10 * fRec763[1]) + (fConst9 * fRec760[1]))));
			double fTemp204 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec769[1]) + (fConst6 * fRec766[1])))) + (fConst4 * (((0.0114670459 * fTemp16) + ((0.024378258399999998 * fTemp18) + (((0.058590138700000002 * fTemp15) + (0.051197272100000003 * fTemp20)) + (0.022856634899999999 * fTemp19)))) - ((0.0109541929 * fTemp17) + ((0.044102355699999998 * fTemp14) + ((0.038143268700000003 * fTemp21) + (0.060076494799999998 * fTemp22))))))));
			fRec771[0] = (fRec771[1] + fTemp204);
			fRec769[0] = fRec771[0];
			double fRec770 = fTemp204;
			fRec768[0] = (fRec769[0] + fRec768[1]);
			fRec766[0] = fRec768[0];
			double fRec767 = fRec770;
			fRec765[0] = (fTemp203 + (fRec767 + fRec765[1]));
			fRec763[0] = fRec765[0];
			double fRec764 = (fRec767 + fTemp203);
			fRec762[0] = (fRec763[0] + fRec762[1]);
			fRec760[0] = fRec762[0];
			double fRec761 = fRec764;
			double fTemp205 = (fConst29 * ((((0.022841757300000001 * fTemp51) + (0.018945038899999999 * fTemp53)) - (((0.059592769099999998 * fTemp50) + (0.029716101000000002 * fTemp54)) + (0.029910834800000001 * fTemp52))) + (fConst5 * (0.0 - ((fConst31 * fRec775[1]) + (fConst30 * fRec772[1]))))));
			fRec777[0] = (fRec777[1] + fTemp205);
			fRec775[0] = fRec777[0];
			double fRec776 = fTemp205;
			fRec774[0] = (fRec775[0] + fRec774[1]);
			fRec772[0] = fRec774[0];
			double fRec773 = fRec776;
			double fTemp206 = (fConst32 * ((((0.028083669299999999 * fTemp56) + (0.0142656394 * fTemp57)) - (0.038231402300000002 * fTemp58)) - (fConst33 * fRec778[1])));
			fRec780[0] = (fRec780[1] + fTemp206);
			fRec778[0] = fRec780[0];
			double fRec779 = fTemp206;
			double fTemp207 = (fConst12 * (0.0 - ((fConst14 * fRec784[1]) + (fConst13 * fRec781[1]))));
			double fTemp208 = (fConst16 * (0.0 - ((fConst18 * fRec790[1]) + (fConst17 * fRec787[1]))));
			double fTemp209 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec796[1]) + (fConst20 * fRec793[1])))) + (fConst22 * (((0.0147567957 * fTemp33) + ((0.038160673200000002 * fTemp35) + ((0.0013690377000000001 * fTemp32) + (((((0.011545553700000001 * fTemp36) + (0.0333981494 * fTemp27)) + (0.0139434598 * fTemp28)) + (0.00038206999999999998 * fTemp30)) + (0.068900640700000002 * fTemp38))))) - ((0.0048814497999999998 * fTemp34) + ((((0.061218422500000001 * fTemp37) + (0.047489687500000002 * fTemp29)) + (0.0192118893 * fTemp31)) + (0.056796322900000001 * fTemp39)))))));
			fRec798[0] = (fRec798[1] + fTemp209);
			fRec796[0] = fRec798[0];
			double fRec797 = fTemp209;
			fRec795[0] = (fRec796[0] + fRec795[1]);
			fRec793[0] = fRec795[0];
			double fRec794 = fRec797;
			fRec792[0] = (fTemp208 + (fRec794 + fRec792[1]));
			fRec790[0] = fRec792[0];
			double fRec791 = (fRec794 + fTemp208);
			fRec789[0] = (fRec790[0] + fRec789[1]);
			fRec787[0] = fRec789[0];
			double fRec788 = fRec791;
			fRec786[0] = (fTemp207 + (fRec788 + fRec786[1]));
			fRec784[0] = fRec786[0];
			double fRec785 = (fRec788 + fTemp207);
			fRec783[0] = (fRec784[0] + fRec783[1]);
			fRec781[0] = fRec783[0];
			double fRec782 = fRec785;
			double fTemp210 = (fConst35 * (0.0 - ((fConst37 * fRec805[1]) + (fConst36 * fRec802[1]))));
			double fTemp211 = (fConst38 * ((fConst42 * ((((0.0013209424 * fTemp66) + (((0.063598181399999995 * fTemp67) + (0.045588551099999999 * fTemp62)) + (0.0001792233 * fTemp64))) + (0.073262046600000005 * fTemp71)) - (((0.017682739199999999 * fTemp65) + ((0.036436880300000002 * fTemp61) + (((0.0022586491000000002 * fTemp68) + (0.00072654380000000001 * fTemp63)) + (0.0199901813 * fTemp69)))) + (0.057966045299999998 * fTemp70)))) + (fConst5 * (0.0 - ((fConst40 * fRec811[1]) + (fConst39 * fRec808[1]))))));
			fRec813[0] = (fRec813[1] + fTemp211);
			fRec811[0] = fRec813[0];
			double fRec812 = fTemp211;
			fRec810[0] = (fRec811[0] + fRec810[1]);
			fRec808[0] = fRec810[0];
			double fRec809 = fRec812;
			fRec807[0] = (fTemp210 + (fRec809 + fRec807[1]));
			fRec805[0] = fRec807[0];
			double fRec806 = (fRec809 + fTemp210);
			fRec804[0] = (fRec805[0] + fRec804[1]);
			fRec802[0] = fRec804[0];
			double fRec803 = fRec806;
			double fTemp212 = (fConst43 * fRec799[1]);
			fRec801[0] = ((fRec803 + fRec801[1]) - fTemp212);
			fRec799[0] = fRec801[0];
			double fRec800 = (fRec803 - fTemp212);
			double fTemp213 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec820[1]) + (fConst26 * fRec817[1])))) + (fConst25 * (((0.067686701000000002 * fTemp41) + ((0.014017185 * fTemp43) + ((0.0293273849 * fTemp45) + (0.022222818299999999 * fTemp47)))) - (((0.050466446700000001 * fTemp42) + (0.020218088700000001 * fTemp46)) + (0.038476820199999998 * fTemp44))))));
			fRec822[0] = (fRec822[1] + fTemp213);
			fRec820[0] = fRec822[0];
			double fRec821 = fTemp213;
			fRec819[0] = (fRec820[0] + fRec819[1]);
			fRec817[0] = fRec819[0];
			double fRec818 = fRec821;
			double fTemp214 = (fConst28 * fRec814[1]);
			fRec816[0] = ((fRec818 + fRec816[1]) - fTemp214);
			fRec814[0] = fRec816[0];
			double fRec815 = (fRec818 - fTemp214);
			fVec11[(IOTA & 1023)] = (((0.018014810400000001 * fTemp7) + ((0.0451940142 * fTemp9) + ((0.041815599199999998 * fTemp77) + ((0.019832848399999999 * fTemp12) + ((0.036427727200000003 * fTemp81) + ((0.016899001 * fTemp13) + (fRec761 + (fRec773 + (fRec779 + (fRec782 + (fRec800 + (fRec815 + (0.022374315400000001 * fTemp82))))))))))))) - (((((0.0109649477 * fTemp76) + ((0.056703260599999999 * fTemp78) + ((((0.019126475300000001 * fTemp80) + (0.044474395999999999 * fTemp74)) + (0.0310454823 * fTemp79)) + (0.023546583100000001 * fTemp11)))) + (0.0136594015 * fTemp10)) + (0.0011367948000000001 * fTemp8)) + (0.050045293800000001 * fTemp75)));
			output11[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec11[((IOTA - iConst44) & 1023)])));
			double fTemp215 = (fConst35 * (0.0 - ((fConst37 * fRec829[1]) + (fConst36 * fRec826[1]))));
			double fTemp216 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec835[1]) + (fConst39 * fRec832[1])))) + (fConst42 * (((0.034381001000000001 * fTemp61) + ((((0.042608982400000002 * fTemp67) + (0.0139821576 * fTemp68)) + (0.033069018899999997 * fTemp62)) + (0.019240633699999999 * fTemp69))) - ((((0.0060765628999999996 * fTemp65) + ((0.058995007100000003 * fTemp66) + ((0.0099588112000000006 * fTemp63) + (0.026149855499999999 * fTemp64)))) + (0.028864750299999999 * fTemp70)) + (0.0151574302 * fTemp71))))));
			fRec837[0] = (fRec837[1] + fTemp216);
			fRec835[0] = fRec837[0];
			double fRec836 = fTemp216;
			fRec834[0] = (fRec835[0] + fRec834[1]);
			fRec832[0] = fRec834[0];
			double fRec833 = fRec836;
			fRec831[0] = (fTemp215 + (fRec833 + fRec831[1]));
			fRec829[0] = fRec831[0];
			double fRec830 = (fRec833 + fTemp215);
			fRec828[0] = (fRec829[0] + fRec828[1]);
			fRec826[0] = fRec828[0];
			double fRec827 = fRec830;
			double fTemp217 = (fConst43 * fRec823[1]);
			fRec825[0] = ((fRec827 + fRec825[1]) - fTemp217);
			fRec823[0] = fRec825[0];
			double fRec824 = (fRec827 - fTemp217);
			double fTemp218 = (fConst12 * (0.0 - ((fConst14 * fRec841[1]) + (fConst13 * fRec838[1]))));
			double fTemp219 = (fConst16 * (0.0 - ((fConst18 * fRec847[1]) + (fConst17 * fRec844[1]))));
			double fTemp220 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec853[1]) + (fConst20 * fRec850[1])))) + (fConst22 * (((0.019394751299999999 * fTemp35) + ((0.016697628199999998 * fTemp32) + ((0.040912037999999998 * fTemp27) + (0.057140385699999997 * fTemp39)))) - ((0.0088762253000000003 * fTemp33) + ((0.046753708300000002 * fTemp34) + (((((((0.0139506356 * fTemp36) + (0.0077663233 * fTemp37)) + (0.003893695 * fTemp28)) + (0.026803257899999999 * fTemp29)) + (0.0020601055000000002 * fTemp30)) + (0.049129575199999997 * fTemp31)) + (0.0146896892 * fTemp38))))))));
			fRec855[0] = (fRec855[1] + fTemp220);
			fRec853[0] = fRec855[0];
			double fRec854 = fTemp220;
			fRec852[0] = (fRec853[0] + fRec852[1]);
			fRec850[0] = fRec852[0];
			double fRec851 = fRec854;
			fRec849[0] = (fTemp219 + (fRec851 + fRec849[1]));
			fRec847[0] = fRec849[0];
			double fRec848 = (fRec851 + fTemp219);
			fRec846[0] = (fRec847[0] + fRec846[1]);
			fRec844[0] = fRec846[0];
			double fRec845 = fRec848;
			fRec843[0] = (fTemp218 + (fRec845 + fRec843[1]));
			fRec841[0] = fRec843[0];
			double fRec842 = (fRec845 + fTemp218);
			fRec840[0] = (fRec841[0] + fRec840[1]);
			fRec838[0] = fRec840[0];
			double fRec839 = fRec842;
			double fTemp221 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec862[1]) + (fConst26 * fRec859[1])))) + (fConst25 * (((0.0086368017999999998 * fTemp41) + ((0.018310289699999999 * fTemp45) + (0.052982696900000001 * fTemp47))) - ((0.022760134800000002 * fTemp44) + (((0.027518740999999999 * fTemp42) + (0.0276104972 * fTemp46)) + (0.0128853253 * fTemp43)))))));
			fRec864[0] = (fRec864[1] + fTemp221);
			fRec862[0] = fRec864[0];
			double fRec863 = fTemp221;
			fRec861[0] = (fRec862[0] + fRec861[1]);
			fRec859[0] = fRec861[0];
			double fRec860 = fRec863;
			double fTemp222 = (fConst28 * fRec856[1]);
			fRec858[0] = ((fRec860 + fRec858[1]) - fTemp222);
			fRec856[0] = fRec858[0];
			double fRec857 = (fRec860 - fTemp222);
			double fTemp223 = (fConst29 * (((0.0176248494 * fTemp51) - ((((0.041423636799999997 * fTemp50) + (0.023499625900000001 * fTemp54)) + (0.011190916800000001 * fTemp52)) + (0.018337494199999999 * fTemp53))) + (fConst5 * (0.0 - ((fConst31 * fRec868[1]) + (fConst30 * fRec865[1]))))));
			fRec870[0] = (fRec870[1] + fTemp223);
			fRec868[0] = fRec870[0];
			double fRec869 = fTemp223;
			fRec867[0] = (fRec868[0] + fRec867[1]);
			fRec865[0] = fRec867[0];
			double fRec866 = fRec869;
			double fTemp224 = (fConst32 * ((((0.0278907766 * fTemp56) + (0.0076511251000000004 * fTemp57)) - (0.018132753800000002 * fTemp58)) - (fConst33 * fRec871[1])));
			fRec873[0] = (fRec873[1] + fTemp224);
			fRec871[0] = fRec873[0];
			double fRec872 = fTemp224;
			double fTemp225 = (fConst8 * (0.0 - ((fConst10 * fRec877[1]) + (fConst9 * fRec874[1]))));
			double fTemp226 = (fConst2 * ((fConst4 * (((0.0116624026 * fTemp17) + ((0.0178838747 * fTemp16) + ((0.0285721086 * fTemp18) + ((((0.043401817500000002 * fTemp14) + (0.0050040034999999997 * fTemp15)) + (0.022082653000000001 * fTemp20)) + (0.038246039699999998 * fTemp19))))) - ((0.034388745999999998 * fTemp21) + (0.0396602525 * fTemp22)))) + (fConst5 * (0.0 - ((fConst7 * fRec883[1]) + (fConst6 * fRec880[1]))))));
			fRec885[0] = (fRec885[1] + fTemp226);
			fRec883[0] = fRec885[0];
			double fRec884 = fTemp226;
			fRec882[0] = (fRec883[0] + fRec882[1]);
			fRec880[0] = fRec882[0];
			double fRec881 = fRec884;
			fRec879[0] = (fTemp225 + (fRec881 + fRec879[1]));
			fRec877[0] = fRec879[0];
			double fRec878 = (fRec881 + fTemp225);
			fRec876[0] = (fRec877[0] + fRec876[1]);
			fRec874[0] = fRec876[0];
			double fRec875 = fRec878;
			fVec12[(IOTA & 1023)] = (((0.049038968400000001 * fTemp75) + ((0.033797954099999999 * fTemp9) + ((0.0008539455 * fTemp10) + ((0.016343537700000001 * fTemp76) + ((0.013176558099999999 * fTemp77) + ((0.035476198600000002 * fTemp78) + ((0.0040803923000000001 * fTemp12) + (((0.011557190300000001 * fTemp13) + (fRec824 + (fRec839 + (fRec857 + (fRec866 + (fRec872 + fRec875)))))) + (0.002956789 * fTemp80))))))))) - ((0.0186678212 * fTemp7) + ((0.00013409749999999999 * fTemp8) + ((0.001587343 * fTemp11) + ((0.033259048399999998 * fTemp79) + ((0.044071762100000002 * fTemp74) + ((0.036764945399999999 * fTemp81) + (0.045194867 * fTemp82))))))));
			output12[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec12[((IOTA - iConst44) & 1023)])));
			double fTemp227 = (fConst35 * (0.0 - ((fConst37 * fRec892[1]) + (fConst36 * fRec889[1]))));
			double fTemp228 = (fConst38 * ((fConst42 * ((((0.0099555320999999992 * fTemp65) + ((0.040129537700000002 * fTemp61) + ((0.044623849700000003 * fTemp66) + (((0.022412283599999999 * fTemp67) + (0.0459672 * fTemp62)) + (0.063453286600000006 * fTemp69))))) + (0.056022944800000002 * fTemp70)) - ((((0.0029121846000000002 * fTemp68) + (0.0024256028000000001 * fTemp63)) + (0.0141447463 * fTemp64)) + (0.0572789644 * fTemp71)))) + (fConst5 * (0.0 - ((fConst40 * fRec898[1]) + (fConst39 * fRec895[1]))))));
			fRec900[0] = (fRec900[1] + fTemp228);
			fRec898[0] = fRec900[0];
			double fRec899 = fTemp228;
			fRec897[0] = (fRec898[0] + fRec897[1]);
			fRec895[0] = fRec897[0];
			double fRec896 = fRec899;
			fRec894[0] = (fTemp227 + (fRec896 + fRec894[1]));
			fRec892[0] = fRec894[0];
			double fRec893 = (fRec896 + fTemp227);
			fRec891[0] = (fRec892[0] + fRec891[1]);
			fRec889[0] = fRec891[0];
			double fRec890 = fRec893;
			double fTemp229 = (fConst43 * fRec886[1]);
			fRec888[0] = ((fRec890 + fRec888[1]) - fTemp229);
			fRec886[0] = fRec888[0];
			double fRec887 = (fRec890 - fTemp229);
			double fTemp230 = (fConst8 * (0.0 - ((fConst10 * fRec904[1]) + (fConst9 * fRec901[1]))));
			double fTemp231 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec910[1]) + (fConst6 * fRec907[1])))) + (fConst4 * (((0.022853022099999998 * fTemp17) + ((0.0106044642 * fTemp16) + ((0.012343812399999999 * fTemp18) + ((0.0280893384 * fTemp19) + ((0.0103805129 * fTemp20) + ((0.048601047199999997 * fTemp14) + (0.056179233500000002 * fTemp22))))))) - ((0.057282213499999998 * fTemp15) + (0.064059343000000005 * fTemp21))))));
			fRec912[0] = (fRec912[1] + fTemp231);
			fRec910[0] = fRec912[0];
			double fRec911 = fTemp231;
			fRec909[0] = (fRec910[0] + fRec909[1]);
			fRec907[0] = fRec909[0];
			double fRec908 = fRec911;
			fRec906[0] = (fTemp230 + (fRec908 + fRec906[1]));
			fRec904[0] = fRec906[0];
			double fRec905 = (fRec908 + fTemp230);
			fRec903[0] = (fRec904[0] + fRec903[1]);
			fRec901[0] = fRec903[0];
			double fRec902 = fRec905;
			double fTemp232 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec919[1]) + (fConst26 * fRec916[1])))) + (fConst25 * (((0.0072763469000000002 * fTemp45) + (0.035799810199999997 * fTemp47)) - ((0.039324838700000003 * fTemp44) + ((0.061774990199999998 * fTemp41) + (((0.015679664999999999 * fTemp42) + (0.034430659699999998 * fTemp46)) + (0.051114910399999998 * fTemp43))))))));
			fRec921[0] = (fRec921[1] + fTemp232);
			fRec919[0] = fRec921[0];
			double fRec920 = fTemp232;
			fRec918[0] = (fRec919[0] + fRec918[1]);
			fRec916[0] = fRec918[0];
			double fRec917 = fRec920;
			double fTemp233 = (fConst28 * fRec913[1]);
			fRec915[0] = ((fRec917 + fRec915[1]) - fTemp233);
			fRec913[0] = fRec915[0];
			double fRec914 = (fRec917 - fTemp233);
			double fTemp234 = (fConst29 * (((0.0381809964 * fTemp51) - ((((0.021245538299999998 * fTemp50) + (0.029767677199999999 * fTemp54)) + (0.0056105807999999998 * fTemp52)) + (0.059271529599999997 * fTemp53))) + (fConst5 * (0.0 - ((fConst31 * fRec925[1]) + (fConst30 * fRec922[1]))))));
			fRec927[0] = (fRec927[1] + fTemp234);
			fRec925[0] = fRec927[0];
			double fRec926 = fTemp234;
			fRec924[0] = (fRec925[0] + fRec924[1]);
			fRec922[0] = fRec924[0];
			double fRec923 = fRec926;
			double fTemp235 = (fConst32 * ((((0.047252739600000003 * fTemp56) + (0.014666551099999999 * fTemp57)) - (0.0080785878999999998 * fTemp58)) - (fConst33 * fRec928[1])));
			fRec930[0] = (fRec930[1] + fTemp235);
			fRec928[0] = fRec930[0];
			double fRec929 = fTemp235;
			double fTemp236 = (fConst12 * (0.0 - ((fConst14 * fRec934[1]) + (fConst13 * fRec931[1]))));
			double fTemp237 = (fConst16 * (0.0 - ((fConst18 * fRec940[1]) + (fConst17 * fRec937[1]))));
			double fTemp238 = (fConst19 * ((fConst22 * (((0.0481937359 * fTemp34) + (((((0.055139078799999998 * fTemp37) + (0.056797343200000003 * fTemp27)) + (0.0153991961 * fTemp28)) + (0.016889474599999999 * fTemp30)) + (0.0016662592000000001 * fTemp32))) - ((0.00051291059999999998 * fTemp33) + ((0.0604910403 * fTemp35) + (((((0.0127776777 * fTemp36) + (0.0112396435 * fTemp29)) + (0.033099211699999999 * fTemp31)) + (0.049210169400000003 * fTemp38)) + (0.029763110999999998 * fTemp39)))))) + (fConst5 * (0.0 - ((fConst21 * fRec946[1]) + (fConst20 * fRec943[1]))))));
			fRec948[0] = (fRec948[1] + fTemp238);
			fRec946[0] = fRec948[0];
			double fRec947 = fTemp238;
			fRec945[0] = (fRec946[0] + fRec945[1]);
			fRec943[0] = fRec945[0];
			double fRec944 = fRec947;
			fRec942[0] = (fTemp237 + (fRec944 + fRec942[1]));
			fRec940[0] = fRec942[0];
			double fRec941 = (fRec944 + fTemp237);
			fRec939[0] = (fRec940[0] + fRec939[1]);
			fRec937[0] = fRec939[0];
			double fRec938 = fRec941;
			fRec936[0] = (fTemp236 + (fRec938 + fRec936[1]));
			fRec934[0] = fRec936[0];
			double fRec935 = (fRec938 + fTemp236);
			fRec933[0] = (fRec934[0] + fRec933[1]);
			fRec931[0] = fRec933[0];
			double fRec932 = fRec935;
			fVec13[(IOTA & 1023)] = (((0.0092568287000000006 * fTemp8) + ((0.0101694192 * fTemp76) + ((0.032584229300000003 * fTemp12) + ((0.0251515044 * fTemp80) + ((0.0171159819 * fTemp13) + (fRec887 + (fRec902 + (fRec914 + (fRec923 + (fRec929 + (fRec932 + (0.058015820799999999 * fTemp82)))))))))))) - ((0.042783307700000002 * fTemp7) + (((((0.053451930799999998 * fTemp77) + ((0.014344177899999999 * fTemp78) + ((((0.040200605100000002 * fTemp81) + (0.020262183699999999 * fTemp74)) + (0.030306671 * fTemp79)) + (0.0029162225000000002 * fTemp11)))) + (0.0042349965000000002 * fTemp10)) + (0.041654224599999998 * fTemp9)) + (0.035822771699999999 * fTemp75))));
			output13[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec13[((IOTA - iConst44) & 1023)])));
			double fTemp239 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec955[1]) + (fConst26 * fRec952[1])))) + (fConst25 * ((0.012665306600000001 * fTemp42) - ((0.0238393379 * fTemp44) + ((0.047073313300000003 * fTemp41) + ((0.029053746200000001 * fTemp43) + ((0.0062313291999999999 * fTemp45) + ((0.034322019199999998 * fTemp46) + (0.030238298300000001 * fTemp47))))))))));
			fRec957[0] = (fRec957[1] + fTemp239);
			fRec955[0] = fRec957[0];
			double fRec956 = fTemp239;
			fRec954[0] = (fRec955[0] + fRec954[1]);
			fRec952[0] = fRec954[0];
			double fRec953 = fRec956;
			double fTemp240 = (fConst28 * fRec949[1]);
			fRec951[0] = ((fRec953 + fRec951[1]) - fTemp240);
			fRec949[0] = fRec951[0];
			double fRec950 = (fRec953 - fTemp240);
			double fTemp241 = (fConst2 * ((fConst4 * (((0.0305698116 * fTemp17) + ((0.018907122700000001 * fTemp16) + (0.044110852300000003 * fTemp22))) - ((0.010919120799999999 * fTemp18) + ((((0.032700924999999999 * fTemp15) + ((0.041883129900000003 * fTemp14) + (0.041919300999999999 * fTemp21))) + (0.0084942105999999996 * fTemp20)) + (0.0230855638 * fTemp19))))) + (fConst5 * (0.0 - ((fConst7 * fRec967[1]) + (fConst6 * fRec964[1]))))));
			fRec969[0] = (fRec969[1] + fTemp241);
			fRec967[0] = fRec969[0];
			double fRec968 = fTemp241;
			fRec966[0] = (fRec967[0] + fRec966[1]);
			fRec964[0] = fRec966[0];
			double fRec965 = fRec968;
			double fTemp242 = (fRec965 + (fConst8 * (0.0 - ((fConst10 * fRec961[1]) + (fConst9 * fRec958[1])))));
			fRec963[0] = (fRec963[1] + fTemp242);
			fRec961[0] = fRec963[0];
			double fRec962 = fTemp242;
			fRec960[0] = (fRec961[0] + fRec960[1]);
			fRec958[0] = fRec960[0];
			double fRec959 = fRec962;
			double fTemp243 = (fConst12 * (0.0 - ((fConst14 * fRec973[1]) + (fConst13 * fRec970[1]))));
			double fTemp244 = (fConst16 * (0.0 - ((fConst18 * fRec979[1]) + (fConst17 * fRec976[1]))));
			double fTemp245 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec985[1]) + (fConst20 * fRec982[1])))) + (fConst22 * (((0.0013377420000000001 * fTemp33) + ((0.026074217600000001 * fTemp34) + ((0.055354265200000002 * fTemp35) + ((((((0.012594079399999999 * fTemp36) + (0.043194804400000002 * fTemp37)) + (0.050307832099999998 * fTemp27)) + (0.0095784483000000004 * fTemp29)) + (0.028331018600000001 * fTemp31)) + (0.042650327000000002 * fTemp38))))) - ((0.019150699199999999 * fTemp32) + (((0.0042893549999999999 * fTemp28) + (0.0098556764000000009 * fTemp30)) + (0.025686086600000001 * fTemp39)))))));
			fRec987[0] = (fRec987[1] + fTemp245);
			fRec985[0] = fRec987[0];
			double fRec986 = fTemp245;
			fRec984[0] = (fRec985[0] + fRec984[1]);
			fRec982[0] = fRec984[0];
			double fRec983 = fRec986;
			fRec981[0] = (fTemp244 + (fRec983 + fRec981[1]));
			fRec979[0] = fRec981[0];
			double fRec980 = (fRec983 + fTemp244);
			fRec978[0] = (fRec979[0] + fRec978[1]);
			fRec976[0] = fRec978[0];
			double fRec977 = fRec980;
			fRec975[0] = (fTemp243 + (fRec977 + fRec975[1]));
			fRec973[0] = fRec975[0];
			double fRec974 = (fRec977 + fTemp243);
			fRec972[0] = (fRec973[0] + fRec972[1]);
			fRec970[0] = fRec972[0];
			double fRec971 = fRec974;
			double fTemp246 = (fConst38 * ((fConst42 * (((((0.0249920197 * fTemp65) + ((0.036407499199999999 * fTemp66) + (((((0.0180867774 * fTemp68) + (0.034651523199999999 * fTemp62)) + (0.0024603912999999998 * fTemp63)) + (0.045061212599999997 * fTemp69)) + (0.013086811 * fTemp64)))) + (0.0316138454 * fTemp70)) + (0.050674432200000001 * fTemp71)) - ((0.033751573 * fTemp61) + (0.0187072369 * fTemp67)))) + (fConst5 * (0.0 - ((fConst40 * fRec1000[1]) + (fConst39 * fRec997[1]))))));
			fRec1002[0] = (fRec1002[1] + fTemp246);
			fRec1000[0] = fRec1002[0];
			double fRec1001 = fTemp246;
			fRec999[0] = (fRec1000[0] + fRec999[1]);
			fRec997[0] = fRec999[0];
			double fRec998 = fRec1001;
			double fTemp247 = (fRec998 + (fConst35 * (0.0 - ((fConst37 * fRec994[1]) + (fConst36 * fRec991[1])))));
			fRec996[0] = (fRec996[1] + fTemp247);
			fRec994[0] = fRec996[0];
			double fRec995 = fTemp247;
			fRec993[0] = (fRec994[0] + fRec993[1]);
			fRec991[0] = fRec993[0];
			double fRec992 = fRec995;
			double fTemp248 = (fConst43 * fRec988[1]);
			fRec990[0] = ((fRec992 + fRec990[1]) - fTemp248);
			fRec988[0] = fRec990[0];
			double fRec989 = (fRec992 - fTemp248);
			double fTemp249 = (fConst32 * ((((0.034308696399999998 * fTemp56) + (0.0080115141000000004 * fTemp57)) + (0.0066573066999999998 * fTemp58)) - (fConst33 * fRec1003[1])));
			fRec1005[0] = (fRec1005[1] + fTemp249);
			fRec1003[0] = fRec1005[0];
			double fRec1004 = fTemp249;
			double fTemp250 = (fConst29 * (((((0.017682478099999999 * fTemp50) + (0.021377224 * fTemp51)) + (0.0044768500000000001 * fTemp52)) - ((0.024736782700000001 * fTemp54) + (0.044035055199999999 * fTemp53))) + (fConst5 * (0.0 - ((fConst31 * fRec1009[1]) + (fConst30 * fRec1006[1]))))));
			fRec1011[0] = (fRec1011[1] + fTemp250);
			fRec1009[0] = fRec1011[0];
			double fRec1010 = fTemp250;
			fRec1008[0] = (fRec1009[0] + fRec1008[1]);
			fRec1006[0] = fRec1008[0];
			double fRec1007 = fRec1010;
			fVec14[(IOTA & 1023)] = (((0.0024237247000000002 * fTemp10) + ((0.048159666499999997 * fTemp77) + ((0.0020710923000000002 * fTemp11) + ((0.0038428987999999998 * fTemp12) + ((0.017752865499999999 * fTemp74) + (((0.0121517424 * fTemp13) + (fRec950 + (fRec959 + (fRec971 + (fRec989 + (fRec1004 + fRec1007)))))) + (0.0354934176 * fTemp81))))))) - ((0.046727173499999997 * fTemp7) + ((0.017203584800000001 * fTemp75) + ((0.010020936500000001 * fTemp8) + ((0.0373265895 * fTemp9) + ((0.0143461656 * fTemp76) + ((0.013866548500000001 * fTemp78) + ((0.034863840200000003 * fTemp79) + ((0.0035790930999999998 * fTemp80) + (0.0554474015 * fTemp82))))))))));
			output14[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec14[((IOTA - iConst44) & 1023)])));
			double fTemp251 = (fConst12 * (0.0 - ((fConst14 * fRec1015[1]) + (fConst13 * fRec1012[1]))));
			double fTemp252 = (fConst16 * (0.0 - ((fConst18 * fRec1021[1]) + (fConst17 * fRec1018[1]))));
			double fTemp253 = (fConst19 * ((fConst22 * (((0.0086995392000000001 * fTemp33) + ((0.015637537999999999 * fTemp32) + ((((((0.015476045500000001 * fTemp36) + (0.043503956900000001 * fTemp27)) + (0.026801474499999998 * fTemp29)) + (0.0515239449 * fTemp31)) + (0.022139255300000001 * fTemp38)) + (0.059973528700000001 * fTemp39)))) - ((0.045111989200000001 * fTemp34) + ((0.0094794141999999994 * fTemp35) + (((0.0036555076999999999 * fTemp37) + (0.0035983234999999998 * fTemp28)) + (0.0020794956 * fTemp30)))))) + (fConst5 * (0.0 - ((fConst21 * fRec1027[1]) + (fConst20 * fRec1024[1]))))));
			fRec1029[0] = (fRec1029[1] + fTemp253);
			fRec1027[0] = fRec1029[0];
			double fRec1028 = fTemp253;
			fRec1026[0] = (fRec1027[0] + fRec1026[1]);
			fRec1024[0] = fRec1026[0];
			double fRec1025 = fRec1028;
			fRec1023[0] = (fTemp252 + (fRec1025 + fRec1023[1]));
			fRec1021[0] = fRec1023[0];
			double fRec1022 = (fRec1025 + fTemp252);
			fRec1020[0] = (fRec1021[0] + fRec1020[1]);
			fRec1018[0] = fRec1020[0];
			double fRec1019 = fRec1022;
			fRec1017[0] = (fTemp251 + (fRec1019 + fRec1017[1]));
			fRec1015[0] = fRec1017[0];
			double fRec1016 = (fRec1019 + fTemp251);
			fRec1014[0] = (fRec1015[0] + fRec1014[1]);
			fRec1012[0] = fRec1014[0];
			double fRec1013 = fRec1016;
			double fTemp254 = (fConst35 * (0.0 - ((fConst37 * fRec1036[1]) + (fConst36 * fRec1033[1]))));
			double fTemp255 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec1042[1]) + (fConst39 * fRec1039[1])))) + (fConst42 * (((((((0.014347459200000001 * fTemp68) + (0.034649486299999997 * fTemp62)) + (0.0098158008999999994 * fTemp63)) + (0.022653741799999998 * fTemp69)) + (0.0270656365 * fTemp64)) + (0.023748579799999999 * fTemp71)) - (((0.0042941180000000004 * fTemp65) + ((0.038937321099999998 * fTemp61) + ((0.057253737800000003 * fTemp66) + (0.043269088800000001 * fTemp67)))) + (0.025357420200000001 * fTemp70))))));
			fRec1044[0] = (fRec1044[1] + fTemp255);
			fRec1042[0] = fRec1044[0];
			double fRec1043 = fTemp255;
			fRec1041[0] = (fRec1042[0] + fRec1041[1]);
			fRec1039[0] = fRec1041[0];
			double fRec1040 = fRec1043;
			fRec1038[0] = (fTemp254 + (fRec1040 + fRec1038[1]));
			fRec1036[0] = fRec1038[0];
			double fRec1037 = (fRec1040 + fTemp254);
			fRec1035[0] = (fRec1036[0] + fRec1035[1]);
			fRec1033[0] = fRec1035[0];
			double fRec1034 = fRec1037;
			double fTemp256 = (fConst43 * fRec1030[1]);
			fRec1032[0] = ((fRec1034 + fRec1032[1]) - fTemp256);
			fRec1030[0] = fRec1032[0];
			double fRec1031 = (fRec1034 - fTemp256);
			double fTemp257 = (fConst8 * (0.0 - ((fConst10 * fRec1048[1]) + (fConst9 * fRec1045[1]))));
			double fTemp258 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec1054[1]) + (fConst6 * fRec1051[1])))) + (fConst4 * ((((0.0015782287999999999 * fTemp15) + (0.018392151299999999 * fTemp16)) + (0.013484738099999999 * fTemp17)) - ((0.028767154199999999 * fTemp18) + ((0.040181063599999997 * fTemp19) + ((0.022086621899999999 * fTemp20) + ((0.048878875799999999 * fTemp14) + ((0.036735531299999999 * fTemp21) + (0.035422290500000002 * fTemp22))))))))));
			fRec1056[0] = (fRec1056[1] + fTemp258);
			fRec1054[0] = fRec1056[0];
			double fRec1055 = fTemp258;
			fRec1053[0] = (fRec1054[0] + fRec1053[1]);
			fRec1051[0] = fRec1053[0];
			double fRec1052 = fRec1055;
			fRec1050[0] = (fTemp257 + (fRec1052 + fRec1050[1]));
			fRec1048[0] = fRec1050[0];
			double fRec1049 = (fRec1052 + fTemp257);
			fRec1047[0] = (fRec1048[0] + fRec1047[1]);
			fRec1045[0] = fRec1047[0];
			double fRec1046 = fRec1049;
			double fTemp259 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec1063[1]) + (fConst26 * fRec1060[1])))) + (fConst25 * (((0.0042459413000000001 * fTemp41) + (0.027964285799999999 * fTemp42)) - ((0.023920673699999999 * fTemp44) + ((0.0152251735 * fTemp43) + ((0.018201339800000001 * fTemp45) + ((0.0291018254 * fTemp46) + (0.055332038200000003 * fTemp47)))))))));
			fRec1065[0] = (fRec1065[1] + fTemp259);
			fRec1063[0] = fRec1065[0];
			double fRec1064 = fTemp259;
			fRec1062[0] = (fRec1063[0] + fRec1062[1]);
			fRec1060[0] = fRec1062[0];
			double fRec1061 = fRec1064;
			double fTemp260 = (fConst28 * fRec1057[1]);
			fRec1059[0] = ((fRec1061 + fRec1059[1]) - fTemp260);
			fRec1057[0] = fRec1059[0];
			double fRec1058 = (fRec1061 - fTemp260);
			double fTemp261 = (fConst29 * (((((0.0418831286 * fTemp50) + (0.018876828599999999 * fTemp51)) + (0.0111949218 * fTemp52)) - ((0.024445595000000001 * fTemp54) + (0.0214613175 * fTemp53))) + (fConst5 * (0.0 - ((fConst31 * fRec1069[1]) + (fConst30 * fRec1066[1]))))));
			fRec1071[0] = (fRec1071[1] + fTemp261);
			fRec1069[0] = fRec1071[0];
			double fRec1070 = fTemp261;
			fRec1068[0] = (fRec1069[0] + fRec1068[1]);
			fRec1066[0] = fRec1068[0];
			double fRec1067 = fRec1070;
			double fTemp262 = (fConst32 * ((((0.029590851899999999 * fTemp56) + (0.0080539393999999997 * fTemp57)) + (0.0180607804 * fTemp58)) - (fConst33 * fRec1072[1])));
			fRec1074[0] = (fRec1074[1] + fTemp262);
			fRec1072[0] = fRec1074[0];
			double fRec1073 = fTemp262;
			fVec15[(IOTA & 1023)] = (((0.051287778700000002 * fTemp75) + ((0.030331675200000002 * fTemp9) + ((0.016394192200000001 * fTemp76) + ((0.0434008959 * fTemp78) + ((0.0017607825 * fTemp11) + ((0.0050112574 * fTemp12) + ((0.044706381599999998 * fTemp74) + ((0.0034744727 * fTemp80) + ((0.041550712900000002 * fTemp81) + ((0.012059740100000001 * fTemp13) + (fRec1013 + (fRec1031 + (fRec1046 + (fRec1058 + (fRec1067 + (fRec1073 + (0.036970267500000001 * fTemp82))))))))))))))))) - ((0.0218416112 * fTemp7) + ((((0.0040829713 * fTemp77) + (0.034672275000000002 * fTemp79)) + (0.00044471849999999999 * fTemp10)) + (0.0012607244000000001 * fTemp8))));
			output15[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec15[((IOTA - iConst44) & 1023)])));
			double fTemp263 = (fConst46 * (0.0 - ((fConst48 * fRec1078[1]) + (fConst47 * fRec1075[1]))));
			double fTemp264 = (fConst50 * (0.0 - ((fConst52 * fRec1084[1]) + (fConst51 * fRec1081[1]))));
			double fTemp265 = (fConst53 * ((fConst5 * (0.0 - ((fConst55 * fRec1090[1]) + (fConst54 * fRec1087[1])))) + (fConst56 * (((0.047634048900000003 * fTemp34) + ((0.012698079500000001 * fTemp35) + ((0.020460395400000001 * fTemp32) + (((((0.080543404499999999 * fTemp36) + (0.047426320299999998 * fTemp37)) + (0.0098382556999999995 * fTemp28)) + (0.035236140200000002 * fTemp31)) + (0.0001516868 * fTemp38))))) - ((0.031012501800000002 * fTemp33) + ((((0.030904728400000001 * fTemp27) + (0.065094485600000002 * fTemp29)) + (0.0158168185 * fTemp30)) + (0.0021111380999999999 * fTemp39)))))));
			fRec1092[0] = (fRec1092[1] + fTemp265);
			fRec1090[0] = fRec1092[0];
			double fRec1091 = fTemp265;
			fRec1089[0] = (fRec1090[0] + fRec1089[1]);
			fRec1087[0] = fRec1089[0];
			double fRec1088 = fRec1091;
			fRec1086[0] = (fTemp264 + (fRec1088 + fRec1086[1]));
			fRec1084[0] = fRec1086[0];
			double fRec1085 = (fRec1088 + fTemp264);
			fRec1083[0] = (fRec1084[0] + fRec1083[1]);
			fRec1081[0] = fRec1083[0];
			double fRec1082 = fRec1085;
			fRec1080[0] = (fTemp263 + (fRec1082 + fRec1080[1]));
			fRec1078[0] = fRec1080[0];
			double fRec1079 = (fRec1082 + fTemp263);
			fRec1077[0] = (fRec1078[0] + fRec1077[1]);
			fRec1075[0] = fRec1077[0];
			double fRec1076 = fRec1079;
			double fTemp266 = (fConst57 * ((fConst5 * (0.0 - ((fConst59 * fRec1105[1]) + (fConst58 * fRec1102[1])))) + (fConst62 * (((((0.095884877199999996 * fTemp65) + ((0.078122615300000003 * fTemp61) + ((0.026665955700000001 * fTemp66) + (((0.0226578448 * fTemp67) + (0.041414022600000003 * fTemp69)) + (0.064542356699999998 * fTemp64))))) + (0.023019951 * fTemp70)) + (0.0011971447000000001 * fTemp71)) - (((0.033528091400000001 * fTemp68) + (0.048555427700000001 * fTemp62)) + (0.072624234900000001 * fTemp63))))));
			fRec1107[0] = (fRec1107[1] + fTemp266);
			fRec1105[0] = fRec1107[0];
			double fRec1106 = fTemp266;
			fRec1104[0] = (fRec1105[0] + fRec1104[1]);
			fRec1102[0] = fRec1104[0];
			double fRec1103 = fRec1106;
			double fTemp267 = (fRec1103 + (fConst63 * (0.0 - ((fConst65 * fRec1099[1]) + (fConst64 * fRec1096[1])))));
			fRec1101[0] = (fRec1101[1] + fTemp267);
			fRec1099[0] = fRec1101[0];
			double fRec1100 = fTemp267;
			fRec1098[0] = (fRec1099[0] + fRec1098[1]);
			fRec1096[0] = fRec1098[0];
			double fRec1097 = fRec1100;
			double fTemp268 = (fConst66 * fRec1093[1]);
			fRec1095[0] = ((fRec1097 + fRec1095[1]) - fTemp268);
			fRec1093[0] = fRec1095[0];
			double fRec1094 = (fRec1097 - fTemp268);
			double fTemp269 = (fConst67 * ((fConst69 * (((0.052728591999999998 * fTemp41) + ((0.1137285452 * fTemp43) + ((0.1007985804 * fTemp45) + ((0.030580698699999999 * fTemp46) + ((0.084716863700000006 * fTemp42) + (0.037237809500000003 * fTemp47)))))) - (0.0553800916 * fTemp44))) + (fConst5 * (0.0 - ((fConst71 * fRec1114[1]) + (fConst70 * fRec1111[1]))))));
			fRec1116[0] = (fRec1116[1] + fTemp269);
			fRec1114[0] = fRec1116[0];
			double fRec1115 = fTemp269;
			fRec1113[0] = (fRec1114[0] + fRec1113[1]);
			fRec1111[0] = fRec1113[0];
			double fRec1112 = fRec1115;
			double fTemp270 = (fConst72 * fRec1108[1]);
			fRec1110[0] = ((fRec1112 + fRec1110[1]) - fTemp270);
			fRec1108[0] = fRec1110[0];
			double fRec1109 = (fRec1112 - fTemp270);
			double fTemp271 = (fConst73 * ((((((0.048024604899999997 * fTemp50) + (0.043858782300000003 * fTemp51)) + (0.024724205799999999 * fTemp54)) + (0.13566151609999999 * fTemp52)) + (0.06470592 * fTemp53)) + (fConst5 * (0.0 - ((fConst75 * fRec1120[1]) + (fConst74 * fRec1117[1]))))));
			fRec1122[0] = (fRec1122[1] + fTemp271);
			fRec1120[0] = fRec1122[0];
			double fRec1121 = fTemp271;
			fRec1119[0] = (fRec1120[0] + fRec1119[1]);
			fRec1117[0] = fRec1119[0];
			double fRec1118 = fRec1121;
			double fTemp272 = (fConst76 * ((((0.025836954200000001 * fTemp56) + (0.073090759300000002 * fTemp57)) + (0.079096781300000002 * fTemp58)) - (fConst77 * fRec1123[1])));
			fRec1125[0] = (fRec1125[1] + fTemp272);
			fRec1123[0] = fRec1125[0];
			double fRec1124 = fTemp272;
			double fTemp273 = (fConst79 * (0.0 - ((fConst81 * fRec1129[1]) + (fConst80 * fRec1126[1]))));
			double fTemp274 = (fConst82 * ((fConst5 * (0.0 - ((fConst84 * fRec1135[1]) + (fConst83 * fRec1132[1])))) + (fConst85 * (((0.1038907615 * fTemp17) + ((0.075839598100000002 * fTemp18) + ((0.065973801600000007 * fTemp19) + ((0.00056197340000000004 * fTemp20) + ((0.0960019872 * fTemp15) + ((0.042564237999999997 * fTemp14) + (0.0138388486 * fTemp22))))))) - ((0.0059110682999999999 * fTemp21) + (0.087146714299999997 * fTemp16))))));
			fRec1137[0] = (fRec1137[1] + fTemp274);
			fRec1135[0] = fRec1137[0];
			double fRec1136 = fTemp274;
			fRec1134[0] = (fRec1135[0] + fRec1134[1]);
			fRec1132[0] = fRec1134[0];
			double fRec1133 = fRec1136;
			fRec1131[0] = (fTemp273 + (fRec1133 + fRec1131[1]));
			fRec1129[0] = fRec1131[0];
			double fRec1130 = (fRec1133 + fTemp273);
			fRec1128[0] = (fRec1129[0] + fRec1128[1]);
			fRec1126[0] = fRec1128[0];
			double fRec1127 = fRec1130;
			fVec16[(IOTA & 511)] = (((0.0098681471999999999 * fTemp9) + ((0.0086396823999999994 * fTemp10) + ((0.046532118099999999 * fTemp76) + ((0.020814405500000001 * fTemp77) + ((0.0037706114999999998 * fTemp78) + ((0.0303463208 * fTemp79) + (((0.038935900400000001 * fTemp13) + (fRec1076 + (fRec1094 + (fRec1109 + (fRec1118 + (fRec1124 + fRec1127)))))) + (0.044748394300000001 * fTemp81)))))))) - ((0.024361016999999999 * fTemp7) + ((0.0041940987999999997 * fTemp75) + ((0.0031801373000000001 * fTemp8) + ((0.011786821899999999 * fTemp11) + ((0.0073278609000000001 * fTemp12) + ((0.045010484099999998 * fTemp74) + ((0.0095811351000000006 * fTemp80) + (0.00058700210000000002 * fTemp82)))))))));
			output16[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec16[((IOTA - iConst86) & 511)])));
			double fTemp275 = (fConst73 * (((((0.0068646756 * fTemp54) + (0.106752281 * fTemp52)) + (0.044906605400000001 * fTemp53)) - ((0.059746908199999997 * fTemp50) + (0.052208464599999997 * fTemp51))) + (fConst5 * (0.0 - ((fConst75 * fRec1141[1]) + (fConst74 * fRec1138[1]))))));
			fRec1143[0] = (fRec1143[1] + fTemp275);
			fRec1141[0] = fRec1143[0];
			double fRec1142 = fTemp275;
			fRec1140[0] = (fRec1141[0] + fRec1140[1]);
			fRec1138[0] = fRec1140[0];
			double fRec1139 = fRec1142;
			double fTemp276 = (fConst46 * (0.0 - ((fConst48 * fRec1147[1]) + (fConst47 * fRec1144[1]))));
			double fTemp277 = (fConst50 * (0.0 - ((fConst52 * fRec1153[1]) + (fConst51 * fRec1150[1]))));
			double fTemp278 = (fConst53 * ((fConst56 * (((0.046441896500000003 * fTemp33) + (((0.029294994099999999 * fTemp27) + (0.033968584500000003 * fTemp28)) + (0.0147762702 * fTemp31))) - ((0.035791716299999998 * fTemp34) + ((0.0022685258999999998 * fTemp35) + ((0.0193180235 * fTemp32) + ((((((0.082795180800000007 * fTemp36) + (0.042898746100000003 * fTemp37)) + (0.069299089600000002 * fTemp29)) + (0.038169590099999998 * fTemp30)) + (0.036523168100000003 * fTemp38)) + (0.013559352300000001 * fTemp39))))))) + (fConst5 * (0.0 - ((fConst55 * fRec1159[1]) + (fConst54 * fRec1156[1]))))));
			fRec1161[0] = (fRec1161[1] + fTemp278);
			fRec1159[0] = fRec1161[0];
			double fRec1160 = fTemp278;
			fRec1158[0] = (fRec1159[0] + fRec1158[1]);
			fRec1156[0] = fRec1158[0];
			double fRec1157 = fRec1160;
			fRec1155[0] = (fTemp277 + (fRec1157 + fRec1155[1]));
			fRec1153[0] = fRec1155[0];
			double fRec1154 = (fRec1157 + fTemp277);
			fRec1152[0] = (fRec1153[0] + fRec1152[1]);
			fRec1150[0] = fRec1152[0];
			double fRec1151 = fRec1154;
			fRec1149[0] = (fTemp276 + (fRec1151 + fRec1149[1]));
			fRec1147[0] = fRec1149[0];
			double fRec1148 = (fRec1151 + fTemp276);
			fRec1146[0] = (fRec1147[0] + fRec1146[1]);
			fRec1144[0] = fRec1146[0];
			double fRec1145 = fRec1148;
			double fTemp279 = (fConst79 * (0.0 - ((fConst81 * fRec1165[1]) + (fConst80 * fRec1162[1]))));
			double fTemp280 = (fConst82 * ((fConst5 * (0.0 - ((fConst84 * fRec1171[1]) + (fConst83 * fRec1168[1])))) + (fConst85 * (((0.066025565499999994 * fTemp17) + ((0.015789418 * fTemp21) + (0.021242065899999999 * fTemp19))) - ((0.081995681700000003 * fTemp16) + ((0.081007449400000001 * fTemp18) + ((0.030705756300000001 * fTemp20) + ((0.109361915 * fTemp15) + ((0.042846748099999998 * fTemp14) + (0.0144473742 * fTemp22))))))))));
			fRec1173[0] = (fRec1173[1] + fTemp280);
			fRec1171[0] = fRec1173[0];
			double fRec1172 = fTemp280;
			fRec1170[0] = (fRec1171[0] + fRec1170[1]);
			fRec1168[0] = fRec1170[0];
			double fRec1169 = fRec1172;
			fRec1167[0] = (fTemp279 + (fRec1169 + fRec1167[1]));
			fRec1165[0] = fRec1167[0];
			double fRec1166 = (fRec1169 + fTemp279);
			fRec1164[0] = (fRec1165[0] + fRec1164[1]);
			fRec1162[0] = fRec1164[0];
			double fRec1163 = fRec1166;
			double fTemp281 = (fConst67 * ((fConst5 * (0.0 - ((fConst71 * fRec1180[1]) + (fConst70 * fRec1177[1])))) + (fConst69 * (((0.077726390199999995 * fTemp43) + ((0.064936305 * fTemp45) + (0.0104764496 * fTemp47))) - (((0.0618418835 * fTemp41) + ((0.10055832200000001 * fTemp42) + (0.030644154900000001 * fTemp46))) + (0.064544753600000004 * fTemp44))))));
			fRec1182[0] = (fRec1182[1] + fTemp281);
			fRec1180[0] = fRec1182[0];
			double fRec1181 = fTemp281;
			fRec1179[0] = (fRec1180[0] + fRec1179[1]);
			fRec1177[0] = fRec1179[0];
			double fRec1178 = fRec1181;
			double fTemp282 = (fConst72 * fRec1174[1]);
			fRec1176[0] = ((fRec1178 + fRec1176[1]) - fTemp282);
			fRec1174[0] = fRec1176[0];
			double fRec1175 = (fRec1178 - fTemp282);
			double fTemp283 = (fConst76 * ((((0.05629634 * fTemp57) + (0.065478709499999996 * fTemp58)) - (0.0324570478 * fTemp56)) - (fConst77 * fRec1183[1])));
			fRec1185[0] = (fRec1185[1] + fTemp283);
			fRec1183[0] = fRec1185[0];
			double fRec1184 = fTemp283;
			double fTemp284 = (fConst63 * (0.0 - ((fConst65 * fRec1192[1]) + (fConst64 * fRec1189[1]))));
			double fTemp285 = (fConst57 * ((fConst5 * (0.0 - ((fConst59 * fRec1198[1]) + (fConst58 * fRec1195[1])))) + (fConst62 * ((((0.042812562899999997 * fTemp68) + (0.012751115800000001 * fTemp69)) + (0.024489988800000001 * fTemp64)) - ((((0.1032633504 * fTemp65) + ((0.079192042300000001 * fTemp61) + ((0.0185183781 * fTemp66) + (((0.011432948599999999 * fTemp67) + (0.030345832199999999 * fTemp62)) + (0.091689767800000002 * fTemp63))))) + (0.0235490306 * fTemp70)) + (0.020789076900000002 * fTemp71))))));
			fRec1200[0] = (fRec1200[1] + fTemp285);
			fRec1198[0] = fRec1200[0];
			double fRec1199 = fTemp285;
			fRec1197[0] = (fRec1198[0] + fRec1197[1]);
			fRec1195[0] = fRec1197[0];
			double fRec1196 = fRec1199;
			fRec1194[0] = (fTemp284 + (fRec1196 + fRec1194[1]));
			fRec1192[0] = fRec1194[0];
			double fRec1193 = (fRec1196 + fTemp284);
			fRec1191[0] = (fRec1192[0] + fRec1191[1]);
			fRec1189[0] = fRec1191[0];
			double fRec1190 = fRec1193;
			double fTemp286 = (fConst66 * fRec1186[1]);
			fRec1188[0] = ((fRec1190 + fRec1188[1]) - fTemp286);
			fRec1186[0] = fRec1188[0];
			double fRec1187 = (fRec1190 - fTemp286);
			fVec17[(IOTA & 511)] = (((0.0021174613999999999 * fTemp78) + ((0.051436894900000002 * fTemp79) + ((0.048097403699999999 * fTemp74) + (((0.032144031000000003 * fTemp13) + (fRec1139 + (fRec1145 + (fRec1163 + (fRec1175 + (fRec1184 + fRec1187)))))) + (0.020048982 * fTemp80))))) - ((0.0478501073 * fTemp7) + ((0.023738348199999999 * fTemp75) + ((0.035190481500000002 * fTemp8) + ((0.0053211185999999999 * fTemp9) + ((0.0031324935999999999 * fTemp10) + ((0.040599639399999998 * fTemp76) + ((0.0051556522000000002 * fTemp77) + ((0.0013000793000000001 * fTemp11) + ((0.0024028396000000001 * fTemp12) + ((0.047787316599999997 * fTemp81) + (0.0034493821 * fTemp82))))))))))));
			output17[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec17[((IOTA - iConst86) & 511)])));
			double fTemp287 = (fConst53 * ((fConst56 * (((0.029859914500000001 * fTemp33) + ((0.027633796700000001 * fTemp32) + (((((((0.076759735600000004 * fTemp36) + (0.038515008199999999 * fTemp37)) + (0.067309628799999993 * fTemp27)) + (0.010292575199999999 * fTemp28)) + (0.018199842099999999 * fTemp30)) + (0.045499202400000001 * fTemp38)) + (0.00055937070000000003 * fTemp39)))) - ((0.0051542089999999999 * fTemp34) + ((0.0118732782 * fTemp35) + ((0.029074260500000001 * fTemp29) + (0.044428988699999998 * fTemp31)))))) + (fConst5 * (0.0 - ((fConst55 * fRec1216[1]) + (fConst54 * fRec1213[1]))))));
			fRec1218[0] = (fRec1218[1] + fTemp287);
			fRec1216[0] = fRec1218[0];
			double fRec1217 = fTemp287;
			fRec1215[0] = (fRec1216[0] + fRec1215[1]);
			fRec1213[0] = fRec1215[0];
			double fRec1214 = fRec1217;
			double fTemp288 = (fRec1214 + (fConst50 * (0.0 - ((fConst52 * fRec1210[1]) + (fConst51 * fRec1207[1])))));
			fRec1212[0] = (fRec1212[1] + fTemp288);
			fRec1210[0] = fRec1212[0];
			double fRec1211 = fTemp288;
			fRec1209[0] = (fRec1210[0] + fRec1209[1]);
			fRec1207[0] = fRec1209[0];
			double fRec1208 = fRec1211;
			double fTemp289 = (fRec1208 + (fConst46 * (0.0 - ((fConst48 * fRec1204[1]) + (fConst47 * fRec1201[1])))));
			fRec1206[0] = (fRec1206[1] + fTemp289);
			fRec1204[0] = fRec1206[0];
			double fRec1205 = fTemp289;
			fRec1203[0] = (fRec1204[0] + fRec1203[1]);
			fRec1201[0] = fRec1203[0];
			double fRec1202 = fRec1205;
			double fTemp290 = (fConst63 * (0.0 - ((fConst65 * fRec1225[1]) + (fConst64 * fRec1222[1]))));
			double fTemp291 = (fConst57 * ((fConst62 * (((((0.071370817500000003 * fTemp65) + ((0.074672500599999997 * fTemp61) + (0.075107450100000001 * fTemp68))) + (0.029728628900000002 * fTemp70)) + (0.025541375799999998 * fTemp71)) - ((0.0038786782000000001 * fTemp66) + (((((0.020887213500000001 * fTemp67) + (0.0493060866 * fTemp62)) + (0.031736644799999998 * fTemp63)) + (0.042527390499999998 * fTemp69)) + (0.090838211000000002 * fTemp64))))) + (fConst5 * (0.0 - ((fConst59 * fRec1231[1]) + (fConst58 * fRec1228[1]))))));
			fRec1233[0] = (fRec1233[1] + fTemp291);
			fRec1231[0] = fRec1233[0];
			double fRec1232 = fTemp291;
			fRec1230[0] = (fRec1231[0] + fRec1230[1]);
			fRec1228[0] = fRec1230[0];
			double fRec1229 = fRec1232;
			fRec1227[0] = (fTemp290 + (fRec1229 + fRec1227[1]));
			fRec1225[0] = fRec1227[0];
			double fRec1226 = (fRec1229 + fTemp290);
			fRec1224[0] = (fRec1225[0] + fRec1224[1]);
			fRec1222[0] = fRec1224[0];
			double fRec1223 = fRec1226;
			double fTemp292 = (fConst66 * fRec1219[1]);
			fRec1221[0] = ((fRec1223 + fRec1221[1]) - fTemp292);
			fRec1219[0] = fRec1221[0];
			double fRec1220 = (fRec1223 - fTemp292);
			double fTemp293 = (fConst79 * (0.0 - ((fConst81 * fRec1237[1]) + (fConst80 * fRec1234[1]))));
			double fTemp294 = (fConst82 * ((fConst85 * (((0.072722887799999997 * fTemp15) + ((0.040728214200000001 * fTemp14) + ((5.4000599999999999e-05 * fTemp21) + (0.0173942952 * fTemp22)))) - ((0.1083702305 * fTemp17) + ((0.088717705600000002 * fTemp16) + ((0.071375065200000004 * fTemp18) + ((0.0058092884999999999 * fTemp20) + (0.091201045499999994 * fTemp19))))))) + (fConst5 * (0.0 - ((fConst84 * fRec1243[1]) + (fConst83 * fRec1240[1]))))));
			fRec1245[0] = (fRec1245[1] + fTemp294);
			fRec1243[0] = fRec1245[0];
			double fRec1244 = fTemp294;
			fRec1242[0] = (fRec1243[0] + fRec1242[1]);
			fRec1240[0] = fRec1242[0];
			double fRec1241 = fRec1244;
			fRec1239[0] = (fTemp293 + (fRec1241 + fRec1239[1]));
			fRec1237[0] = fRec1239[0];
			double fRec1238 = (fRec1241 + fTemp293);
			fRec1236[0] = (fRec1237[0] + fRec1236[1]);
			fRec1234[0] = fRec1236[0];
			double fRec1235 = fRec1238;
			double fTemp295 = (fConst76 * ((((0.074133703999999995 * fTemp57) + (0.024320272399999999 * fTemp58)) - (0.080813680799999996 * fTemp56)) - (fConst77 * fRec1246[1])));
			fRec1248[0] = (fRec1248[1] + fTemp295);
			fRec1246[0] = fRec1248[0];
			double fRec1247 = fTemp295;
			double fTemp296 = (fConst73 * ((((0.024915884999999999 * fTemp54) + (0.0412290404 * fTemp52)) - (((0.045399850700000001 * fTemp50) + (0.13854293819999999 * fTemp51)) + (0.067569511299999996 * fTemp53))) + (fConst5 * (0.0 - ((fConst75 * fRec1252[1]) + (fConst74 * fRec1249[1]))))));
			fRec1254[0] = (fRec1254[1] + fTemp296);
			fRec1252[0] = fRec1254[0];
			double fRec1253 = fTemp296;
			fRec1251[0] = (fRec1252[0] + fRec1251[1]);
			fRec1249[0] = fRec1251[0];
			double fRec1250 = fRec1253;
			double fTemp297 = (fConst67 * ((fConst69 * (((0.040892376500000001 * fTemp41) + (0.028616354 * fTemp45)) - ((0.056507688200000003 * fTemp44) + ((0.1187872858 * fTemp43) + ((0.10271072790000001 * fTemp46) + ((0.079987332699999997 * fTemp42) + (0.050146726699999998 * fTemp47))))))) + (fConst5 * (0.0 - ((fConst71 * fRec1261[1]) + (fConst70 * fRec1258[1]))))));
			fRec1263[0] = (fRec1263[1] + fTemp297);
			fRec1261[0] = fRec1263[0];
			double fRec1262 = fTemp297;
			fRec1260[0] = (fRec1261[0] + fRec1260[1]);
			fRec1258[0] = fRec1260[0];
			double fRec1259 = fRec1262;
			double fTemp298 = (fConst72 * fRec1255[1]);
			fRec1257[0] = ((fRec1259 + fRec1257[1]) - fTemp298);
			fRec1255[0] = fRec1257[0];
			double fRec1256 = (fRec1259 - fTemp298);
			fVec18[(IOTA & 511)] = (((0.027743845699999999 * fTemp7) + ((0.001479628 * fTemp75) + ((0.044119359800000001 * fTemp8) + ((0.013992539300000001 * fTemp9) + ((0.0099793396999999992 * fTemp10) + ((2.8839500000000001e-05 * fTemp78) + ((0.031306726999999999 * fTemp79) + ((0.012265739499999999 * fTemp12) + ((0.042841047899999998 * fTemp74) + ((0.0073815909000000002 * fTemp80) + (((0.0395166583 * fTemp13) + (fRec1202 + (fRec1220 + (fRec1235 + (fRec1247 + (fRec1250 + fRec1256)))))) + (0.042152058700000002 * fTemp81)))))))))))) - ((0.0020618588 * fTemp76) + ((0.019115021400000001 * fTemp77) + ((0.0067131129999999997 * fTemp11) + (0.0028994643000000001 * fTemp82)))));
			output18[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec18[((IOTA - iConst86) & 511)])));
			double fTemp299 = (fConst46 * (0.0 - ((fConst48 * fRec1267[1]) + (fConst47 * fRec1264[1]))));
			double fTemp300 = (fConst50 * (0.0 - ((fConst52 * fRec1273[1]) + (fConst51 * fRec1270[1]))));
			double fTemp301 = (fConst53 * ((fConst56 * (((0.042143438399999997 * fTemp34) + (((((((0.013038852599999999 * fTemp37) + (0.067210084500000003 * fTemp27)) + (0.0345696515 * fTemp28)) + (0.029773692399999999 * fTemp29)) + (0.035504778600000002 * fTemp30)) + (0.043060902400000003 * fTemp31)) + (0.014160015600000001 * fTemp39))) - ((0.049039748299999998 * fTemp33) + ((0.00042105920000000001 * fTemp35) + ((0.027537076099999998 * fTemp32) + ((0.081405602199999996 * fTemp36) + (0.0309046275 * fTemp38))))))) + (fConst5 * (0.0 - ((fConst55 * fRec1279[1]) + (fConst54 * fRec1276[1]))))));
			fRec1281[0] = (fRec1281[1] + fTemp301);
			fRec1279[0] = fRec1281[0];
			double fRec1280 = fTemp301;
			fRec1278[0] = (fRec1279[0] + fRec1278[1]);
			fRec1276[0] = fRec1278[0];
			double fRec1277 = fRec1280;
			fRec1275[0] = (fTemp300 + (fRec1277 + fRec1275[1]));
			fRec1273[0] = fRec1275[0];
			double fRec1274 = (fRec1277 + fTemp300);
			fRec1272[0] = (fRec1273[0] + fRec1272[1]);
			fRec1270[0] = fRec1272[0];
			double fRec1271 = fRec1274;
			fRec1269[0] = (fTemp299 + (fRec1271 + fRec1269[1]));
			fRec1267[0] = fRec1269[0];
			double fRec1268 = (fRec1271 + fTemp299);
			fRec1266[0] = (fRec1267[0] + fRec1266[1]);
			fRec1264[0] = fRec1266[0];
			double fRec1265 = fRec1268;
			double fTemp302 = (fConst63 * (0.0 - ((fConst65 * fRec1288[1]) + (fConst64 * fRec1285[1]))));
			double fTemp303 = (fConst57 * ((fConst62 * (((0.017543044000000001 * fTemp65) + ((0.0236313098 * fTemp66) + ((((0.0103375189 * fTemp67) + (0.090016403199999998 * fTemp68)) + (0.044779442099999997 * fTemp63)) + (0.10436145030000001 * fTemp64)))) - ((((0.076963397200000006 * fTemp61) + ((0.028910017100000001 * fTemp62) + (0.0123781624 * fTemp69))) + (0.031948715400000001 * fTemp70)) + (0.015573327499999999 * fTemp71)))) + (fConst5 * (0.0 - ((fConst59 * fRec1294[1]) + (fConst58 * fRec1291[1]))))));
			fRec1296[0] = (fRec1296[1] + fTemp303);
			fRec1294[0] = fRec1296[0];
			double fRec1295 = fTemp303;
			fRec1293[0] = (fRec1294[0] + fRec1293[1]);
			fRec1291[0] = fRec1293[0];
			double fRec1292 = fRec1295;
			fRec1290[0] = (fTemp302 + (fRec1292 + fRec1290[1]));
			fRec1288[0] = fRec1290[0];
			double fRec1289 = (fRec1292 + fTemp302);
			fRec1287[0] = (fRec1288[0] + fRec1287[1]);
			fRec1285[0] = fRec1287[0];
			double fRec1286 = fRec1289;
			double fTemp304 = (fConst66 * fRec1282[1]);
			fRec1284[0] = ((fRec1286 + fRec1284[1]) - fTemp304);
			fRec1282[0] = fRec1284[0];
			double fRec1283 = (fRec1286 - fTemp304);
			double fTemp305 = (fConst79 * (0.0 - ((fConst81 * fRec1300[1]) + (fConst80 * fRec1297[1]))));
			double fTemp306 = (fConst82 * ((fConst5 * (0.0 - ((fConst84 * fRec1306[1]) + (fConst83 * fRec1303[1])))) + (fConst85 * (((0.082527814300000002 * fTemp18) + ((((0.013146886999999999 * fTemp15) + (0.0308654028 * fTemp21)) + (0.0173005525 * fTemp20)) + (0.1105747111 * fTemp19))) - ((0.061873372199999999 * fTemp17) + ((0.080754876399999995 * fTemp16) + ((0.041355823299999997 * fTemp14) + (0.019124743100000001 * fTemp22))))))));
			fRec1308[0] = (fRec1308[1] + fTemp306);
			fRec1306[0] = fRec1308[0];
			double fRec1307 = fTemp306;
			fRec1305[0] = (fRec1306[0] + fRec1305[1]);
			fRec1303[0] = fRec1305[0];
			double fRec1304 = fRec1307;
			fRec1302[0] = (fTemp305 + (fRec1304 + fRec1302[1]));
			fRec1300[0] = fRec1302[0];
			double fRec1301 = (fRec1304 + fTemp305);
			fRec1299[0] = (fRec1300[0] + fRec1299[1]);
			fRec1297[0] = fRec1299[0];
			double fRec1298 = fRec1301;
			double fTemp307 = (fConst67 * ((fConst5 * (0.0 - ((fConst71 * fRec1315[1]) + (fConst70 * fRec1312[1])))) + (fConst69 * (((0.0057115324999999998 * fTemp41) + ((0.1033305972 * fTemp42) + (0.062514519199999993 * fTemp47))) - ((0.064254195 * fTemp44) + (((0.062919267599999995 * fTemp46) + (0.0310701998 * fTemp45)) + (0.072436876799999994 * fTemp43)))))));
			fRec1317[0] = (fRec1317[1] + fTemp307);
			fRec1315[0] = fRec1317[0];
			double fRec1316 = fTemp307;
			fRec1314[0] = (fRec1315[0] + fRec1314[1]);
			fRec1312[0] = fRec1314[0];
			double fRec1313 = fRec1316;
			double fTemp308 = (fConst72 * fRec1309[1]);
			fRec1311[0] = ((fRec1313 + fRec1311[1]) - fTemp308);
			fRec1309[0] = fRec1311[0];
			double fRec1310 = (fRec1313 - fTemp308);
			double fTemp309 = (fConst76 * (((0.0554719974 * fTemp57) - ((0.064131318399999998 * fTemp56) + (0.033694832799999998 * fTemp58))) - (fConst77 * fRec1318[1])));
			fRec1320[0] = (fRec1320[1] + fTemp309);
			fRec1318[0] = fRec1320[0];
			double fRec1319 = fTemp309;
			double fTemp310 = (fConst73 * ((((0.061587189200000003 * fTemp50) + (0.0062667456999999996 * fTemp54)) - (((0.10430949270000001 * fTemp51) + (0.053937413900000002 * fTemp52)) + (0.041737140800000003 * fTemp53))) + (fConst5 * (0.0 - ((fConst75 * fRec1324[1]) + (fConst74 * fRec1321[1]))))));
			fRec1326[0] = (fRec1326[1] + fTemp310);
			fRec1324[0] = fRec1326[0];
			double fRec1325 = fTemp310;
			fRec1323[0] = (fRec1324[0] + fRec1323[1]);
			fRec1321[0] = fRec1323[0];
			double fRec1322 = fRec1325;
			fVec19[(IOTA & 511)] = (((0.045280332800000003 * fTemp7) + ((0.0254589089 * fTemp75) + ((0.041730033200000002 * fTemp76) + ((0.00040187909999999999 * fTemp77) + ((0.050833146099999997 * fTemp79) + (((0.031777949200000002 * fTemp13) + (fRec1265 + (fRec1283 + (fRec1298 + (fRec1310 + (fRec1319 + fRec1322)))))) + (0.00026488130000000001 * fTemp12))))))) - ((0.036561428899999998 * fTemp8) + ((0.0090558533999999993 * fTemp9) + ((0.021074899599999999 * fTemp10) + ((0.0028861232000000001 * fTemp78) + ((0.0036268271 * fTemp11) + ((0.0497601108 * fTemp74) + ((0.00019261279999999999 * fTemp80) + ((0.048147976600000003 * fTemp81) + (0.0033240105999999998 * fTemp82))))))))));
			output19[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec19[((IOTA - iConst86) & 511)])));
			double fTemp311 = (fConst73 * (((((0.044313878199999997 * fTemp50) + (0.027660248200000001 * fTemp54)) + (0.054060242600000002 * fTemp53)) - ((0.039839455099999997 * fTemp51) + (0.1211456865 * fTemp52))) + (fConst5 * (0.0 - ((fConst75 * fRec1330[1]) + (fConst74 * fRec1327[1]))))));
			fRec1332[0] = (fRec1332[1] + fTemp311);
			fRec1330[0] = fRec1332[0];
			double fRec1331 = fTemp311;
			fRec1329[0] = (fRec1330[0] + fRec1329[1]);
			fRec1327[0] = fRec1329[0];
			double fRec1328 = fRec1331;
			double fTemp312 = (fConst76 * (((0.066152378100000006 * fTemp57) - ((0.023376955599999999 * fTemp56) + (0.067989926899999997 * fTemp58))) - (fConst77 * fRec1333[1])));
			fRec1335[0] = (fRec1335[1] + fTemp312);
			fRec1333[0] = fRec1335[0];
			double fRec1334 = fTemp312;
			double fTemp313 = (fConst46 * (0.0 - ((fConst48 * fRec1339[1]) + (fConst47 * fRec1336[1]))));
			double fTemp314 = (fConst50 * (0.0 - ((fConst52 * fRec1345[1]) + (fConst51 * fRec1342[1]))));
			double fTemp315 = (fConst53 * ((fConst5 * (0.0 - ((fConst55 * fRec1351[1]) + (fConst54 * fRec1348[1])))) + (fConst56 * (((0.016260198 * fTemp35) + ((0.018281111400000001 * fTemp32) + ((((0.084764347800000001 * fTemp36) + (0.028338074899999999 * fTemp27)) + (0.067754134600000002 * fTemp29)) + (0.0135226961 * fTemp38)))) - ((0.028284364999999999 * fTemp33) + ((0.054295212500000002 * fTemp34) + (((((0.047634111600000001 * fTemp37) + (0.0017042562 * fTemp28)) + (0.0021039495000000001 * fTemp30)) + (0.0481332685 * fTemp31)) + (0.012564222099999999 * fTemp39))))))));
			fRec1353[0] = (fRec1353[1] + fTemp315);
			fRec1351[0] = fRec1353[0];
			double fRec1352 = fTemp315;
			fRec1350[0] = (fRec1351[0] + fRec1350[1]);
			fRec1348[0] = fRec1350[0];
			double fRec1349 = fRec1352;
			fRec1347[0] = (fTemp314 + (fRec1349 + fRec1347[1]));
			fRec1345[0] = fRec1347[0];
			double fRec1346 = (fRec1349 + fTemp314);
			fRec1344[0] = (fRec1345[0] + fRec1344[1]);
			fRec1342[0] = fRec1344[0];
			double fRec1343 = fRec1346;
			fRec1341[0] = (fTemp313 + (fRec1343 + fRec1341[1]));
			fRec1339[0] = fRec1341[0];
			double fRec1340 = (fRec1343 + fTemp313);
			fRec1338[0] = (fRec1339[0] + fRec1338[1]);
			fRec1336[0] = fRec1338[0];
			double fRec1337 = fRec1340;
			double fTemp316 = (fConst57 * ((fConst5 * (0.0 - ((fConst59 * fRec1366[1]) + (fConst58 * fRec1363[1])))) + (fConst62 * (((((0.080333374099999993 * fTemp61) + ((((0.022067185999999999 * fTemp67) + (0.030247809399999999 * fTemp68)) + (0.058576265500000002 * fTemp63)) + (0.053966902300000001 * fTemp69))) + (0.0123988413 * fTemp70)) + (0.0079689753999999998 * fTemp71)) - ((0.093660473600000002 * fTemp65) + ((0.0295269064 * fTemp66) + ((0.053731983400000002 * fTemp62) + (0.063732538699999994 * fTemp64))))))));
			fRec1368[0] = (fRec1368[1] + fTemp316);
			fRec1366[0] = fRec1368[0];
			double fRec1367 = fTemp316;
			fRec1365[0] = (fRec1366[0] + fRec1365[1]);
			fRec1363[0] = fRec1365[0];
			double fRec1364 = fRec1367;
			double fTemp317 = (fRec1364 + (fConst63 * (0.0 - ((fConst65 * fRec1360[1]) + (fConst64 * fRec1357[1])))));
			fRec1362[0] = (fRec1362[1] + fTemp317);
			fRec1360[0] = fRec1362[0];
			double fRec1361 = fTemp317;
			fRec1359[0] = (fRec1360[0] + fRec1359[1]);
			fRec1357[0] = fRec1359[0];
			double fRec1358 = fRec1361;
			double fTemp318 = (fConst66 * fRec1354[1]);
			fRec1356[0] = ((fRec1358 + fRec1356[1]) - fTemp318);
			fRec1354[0] = fRec1356[0];
			double fRec1355 = (fRec1358 - fTemp318);
			double fTemp319 = (fConst79 * (0.0 - ((fConst81 * fRec1372[1]) + (fConst80 * fRec1369[1]))));
			double fTemp320 = (fConst82 * ((fConst85 * (((0.10152010960000001 * fTemp17) + ((0.071003269899999999 * fTemp18) + ((0.043153848299999999 * fTemp14) + ((0.0048909403000000004 * fTemp21) + (0.0055458327000000003 * fTemp22))))) - ((0.078952410200000003 * fTemp16) + (((0.092593774300000001 * fTemp15) + (0.0149702233 * fTemp20)) + (0.055213435399999997 * fTemp19))))) + (fConst5 * (0.0 - ((fConst84 * fRec1378[1]) + (fConst83 * fRec1375[1]))))));
			fRec1380[0] = (fRec1380[1] + fTemp320);
			fRec1378[0] = fRec1380[0];
			double fRec1379 = fTemp320;
			fRec1377[0] = (fRec1378[0] + fRec1377[1]);
			fRec1375[0] = fRec1377[0];
			double fRec1376 = fRec1379;
			fRec1374[0] = (fTemp319 + (fRec1376 + fRec1374[1]));
			fRec1372[0] = fRec1374[0];
			double fRec1373 = (fRec1376 + fTemp319);
			fRec1371[0] = (fRec1372[0] + fRec1371[1]);
			fRec1369[0] = fRec1371[0];
			double fRec1370 = fRec1373;
			double fTemp321 = (fConst67 * ((fConst5 * (0.0 - ((fConst71 * fRec1387[1]) + (fConst70 * fRec1384[1])))) + (fConst69 * (((0.078561127300000005 * fTemp42) + (0.1002470553 * fTemp43)) - ((0.043082171400000001 * fTemp44) + ((0.050464711199999998 * fTemp41) + ((0.099162839000000003 * fTemp45) + ((0.028088053599999999 * fTemp46) + (0.028347151099999999 * fTemp47)))))))));
			fRec1389[0] = (fRec1389[1] + fTemp321);
			fRec1387[0] = fRec1389[0];
			double fRec1388 = fTemp321;
			fRec1386[0] = (fRec1387[0] + fRec1386[1]);
			fRec1384[0] = fRec1386[0];
			double fRec1385 = fRec1388;
			double fTemp322 = (fConst72 * fRec1381[1]);
			fRec1383[0] = ((fRec1385 + fRec1383[1]) - fTemp322);
			fRec1381[0] = fRec1383[0];
			double fRec1382 = (fRec1385 - fTemp322);
			fVec20[(IOTA & 511)] = (((0.0109987395 * fTemp8) + ((0.021148038000000001 * fTemp9) + ((0.028525895700000001 * fTemp77) + ((0.026948234799999998 * fTemp11) + ((0.026808161899999999 * fTemp79) + ((0.0070733942000000003 * fTemp12) + ((0.0083822157000000008 * fTemp80) + ((0.049382412000000001 * fTemp81) + ((0.0341328459 * fTemp13) + (fRec1328 + (fRec1334 + (fRec1337 + (fRec1355 + (fRec1370 + (fRec1382 + (0.0116887381 * fTemp82)))))))))))))))) - ((0.025649234600000001 * fTemp7) + ((((0.055984109999999997 * fTemp76) + ((0.0067215047000000003 * fTemp78) + (0.042343977800000002 * fTemp74))) + (0.023526762100000001 * fTemp10)) + (0.021701201900000001 * fTemp75))));
			output20[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec20[((IOTA - iConst86) & 511)])));
			double fTemp323 = (fConst46 * (0.0 - ((fConst48 * fRec1393[1]) + (fConst47 * fRec1390[1]))));
			double fTemp324 = (fConst50 * (0.0 - ((fConst52 * fRec1399[1]) + (fConst51 * fRec1396[1]))));
			double fTemp325 = (fConst53 * ((fConst5 * (0.0 - ((fConst55 * fRec1405[1]) + (fConst54 * fRec1402[1])))) + (fConst56 * (((0.030581421899999999 * fTemp33) + ((0.053862758199999999 * fTemp34) + ((0.0051090616999999996 * fTemp32) + ((((0.048372608599999999 * fTemp37) + (0.033523361100000003 * fTemp28)) + (0.064238065400000002 * fTemp29)) + (0.0043710238000000002 * fTemp38))))) - ((0.0152181087 * fTemp35) + (((((0.086322678599999994 * fTemp36) + (0.029726656300000001 * fTemp27)) + (0.052857117299999999 * fTemp30)) + (0.00059536400000000003 * fTemp31)) + (0.0032141806999999999 * fTemp39)))))));
			fRec1407[0] = (fRec1407[1] + fTemp325);
			fRec1405[0] = fRec1407[0];
			double fRec1406 = fTemp325;
			fRec1404[0] = (fRec1405[0] + fRec1404[1]);
			fRec1402[0] = fRec1404[0];
			double fRec1403 = fRec1406;
			fRec1401[0] = (fTemp324 + (fRec1403 + fRec1401[1]));
			fRec1399[0] = fRec1401[0];
			double fRec1400 = (fRec1403 + fTemp324);
			fRec1398[0] = (fRec1399[0] + fRec1398[1]);
			fRec1396[0] = fRec1398[0];
			double fRec1397 = fRec1400;
			fRec1395[0] = (fTemp323 + (fRec1397 + fRec1395[1]));
			fRec1393[0] = fRec1395[0];
			double fRec1394 = (fRec1397 + fTemp323);
			fRec1392[0] = (fRec1393[0] + fRec1392[1]);
			fRec1390[0] = fRec1392[0];
			double fRec1391 = fRec1394;
			double fTemp326 = (fConst63 * (0.0 - ((fConst65 * fRec1414[1]) + (fConst64 * fRec1411[1]))));
			double fTemp327 = (fConst57 * ((fConst62 * ((((0.096179947000000002 * fTemp65) + ((0.0292749671 * fTemp66) + ((0.091860116300000003 * fTemp63) + (0.0002205725 * fTemp69)))) + (0.016353283400000002 * fTemp70)) - (((0.081845828699999998 * fTemp61) + ((((0.021595633999999999 * fTemp67) + (0.032190859099999997 * fTemp68)) + (0.027572460199999999 * fTemp62)) + (0.040390552000000003 * fTemp64))) + (0.00013763290000000001 * fTemp71)))) + (fConst5 * (0.0 - ((fConst59 * fRec1420[1]) + (fConst58 * fRec1417[1]))))));
			fRec1422[0] = (fRec1422[1] + fTemp327);
			fRec1420[0] = fRec1422[0];
			double fRec1421 = fTemp327;
			fRec1419[0] = (fRec1420[0] + fRec1419[1]);
			fRec1417[0] = fRec1419[0];
			double fRec1418 = fRec1421;
			fRec1416[0] = (fTemp326 + (fRec1418 + fRec1416[1]));
			fRec1414[0] = fRec1416[0];
			double fRec1415 = (fRec1418 + fTemp326);
			fRec1413[0] = (fRec1414[0] + fRec1413[1]);
			fRec1411[0] = fRec1413[0];
			double fRec1412 = fRec1415;
			double fTemp328 = (fConst66 * fRec1408[1]);
			fRec1410[0] = ((fRec1412 + fRec1410[1]) - fTemp328);
			fRec1408[0] = fRec1410[0];
			double fRec1409 = (fRec1412 - fTemp328);
			double fTemp329 = (fConst82 * ((fConst5 * (0.0 - ((fConst84 * fRec1432[1]) + (fConst83 * fRec1429[1])))) + (fConst85 * (((0.068887864899999998 * fTemp17) + ((0.034675787899999998 * fTemp20) + ((0.095628860400000001 * fTemp15) + (0.0120505132 * fTemp22)))) - ((0.077783141200000003 * fTemp16) + ((0.073031964300000002 * fTemp18) + (((0.044060430599999999 * fTemp14) + (0.0059923405000000003 * fTemp21)) + (0.053266278299999997 * fTemp19))))))));
			fRec1434[0] = (fRec1434[1] + fTemp329);
			fRec1432[0] = fRec1434[0];
			double fRec1433 = fTemp329;
			fRec1431[0] = (fRec1432[0] + fRec1431[1]);
			fRec1429[0] = fRec1431[0];
			double fRec1430 = fRec1433;
			double fTemp330 = (fRec1430 + (fConst79 * (0.0 - ((fConst81 * fRec1426[1]) + (fConst80 * fRec1423[1])))));
			fRec1428[0] = (fRec1428[1] + fTemp330);
			fRec1426[0] = fRec1428[0];
			double fRec1427 = fTemp330;
			fRec1425[0] = (fRec1426[0] + fRec1425[1]);
			fRec1423[0] = fRec1425[0];
			double fRec1424 = fRec1427;
			double fTemp331 = (fConst67 * ((fConst5 * (0.0 - ((fConst71 * fRec1441[1]) + (fConst70 * fRec1438[1])))) + (fConst69 * (((0.052324425000000001 * fTemp41) + ((0.028697261599999999 * fTemp46) + (0.091584235299999997 * fTemp43))) - ((0.062078777100000003 * fTemp44) + ((0.061396727300000002 * fTemp45) + ((0.081633108699999998 * fTemp42) + (0.032827189800000003 * fTemp47))))))));
			fRec1443[0] = (fRec1443[1] + fTemp331);
			fRec1441[0] = fRec1443[0];
			double fRec1442 = fTemp331;
			fRec1440[0] = (fRec1441[0] + fRec1440[1]);
			fRec1438[0] = fRec1440[0];
			double fRec1439 = fRec1442;
			double fTemp332 = (fConst72 * fRec1435[1]);
			fRec1437[0] = ((fRec1439 + fRec1437[1]) - fTemp332);
			fRec1435[0] = fRec1437[0];
			double fRec1436 = (fRec1439 - fTemp332);
			double fTemp333 = (fConst73 * (((((0.041430062199999999 * fTemp51) + (0.0059497676000000001 * fTemp54)) + (0.055674328000000002 * fTemp53)) - ((0.046279424700000002 * fTemp50) + (0.10567978259999999 * fTemp52))) + (fConst5 * (0.0 - ((fConst75 * fRec1447[1]) + (fConst74 * fRec1444[1]))))));
			fRec1449[0] = (fRec1449[1] + fTemp333);
			fRec1447[0] = fRec1449[0];
			double fRec1448 = fTemp333;
			fRec1446[0] = (fRec1447[0] + fRec1446[1]);
			fRec1444[0] = fRec1446[0];
			double fRec1445 = fRec1448;
			double fTemp334 = (fConst76 * ((((0.0244521496 * fTemp56) + (0.053525703899999999 * fTemp57)) - (0.065684384400000004 * fTemp58)) - (fConst77 * fRec1450[1])));
			fRec1452[0] = (fRec1452[1] + fTemp334);
			fRec1450[0] = fRec1452[0];
			double fRec1451 = fTemp334;
			fVec21[(IOTA & 511)] = (((0.014371105699999999 * fTemp8) + ((0.030372864199999999 * fTemp10) + ((0.056005440300000001 * fTemp76) + ((0.0054833766000000001 * fTemp78) + ((0.048765029000000001 * fTemp79) + ((0.044797437000000002 * fTemp74) + ((0.030686754 * fTemp13) + (fRec1391 + (fRec1409 + (fRec1424 + (fRec1436 + (fRec1445 + (fRec1451 + (0.0016126281999999999 * fTemp82)))))))))))))) - ((0.048181253200000003 * fTemp7) + ((((0.026781576200000001 * fTemp77) + ((((0.050769899899999998 * fTemp81) + (0.0091690855000000002 * fTemp80)) + (0.0074450256000000003 * fTemp12)) + (0.0048871733000000004 * fTemp11))) + (0.015738845500000001 * fTemp9)) + (0.0082917307999999992 * fTemp75))));
			output21[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec21[((IOTA - iConst86) & 511)])));
			double fTemp335 = (fConst46 * (0.0 - ((fConst48 * fRec1456[1]) + (fConst47 * fRec1453[1]))));
			double fTemp336 = (fConst53 * ((fConst5 * (0.0 - ((fConst55 * fRec1468[1]) + (fConst54 * fRec1465[1])))) + (fConst56 * (((0.046978766999999998 * fTemp33) + ((((((0.082005263800000006 * fTemp36) + (0.032862320799999997 * fTemp28)) + (0.0299703578 * fTemp29)) + (0.035743263599999998 * fTemp30)) + (0.0435722682 * fTemp31)) + (0.015193266800000001 * fTemp39))) - ((0.040996295799999999 * fTemp34) + ((0.0003909044 * fTemp35) + ((0.024236998100000001 * fTemp32) + (((0.014130824599999999 * fTemp37) + (0.069005147200000005 * fTemp27)) + (0.0331582396 * fTemp38)))))))));
			fRec1470[0] = (fRec1470[1] + fTemp336);
			fRec1468[0] = fRec1470[0];
			double fRec1469 = fTemp336;
			fRec1467[0] = (fRec1468[0] + fRec1467[1]);
			fRec1465[0] = fRec1467[0];
			double fRec1466 = fRec1469;
			double fTemp337 = (fRec1466 + (fConst50 * (0.0 - ((fConst52 * fRec1462[1]) + (fConst51 * fRec1459[1])))));
			fRec1464[0] = (fRec1464[1] + fTemp337);
			fRec1462[0] = fRec1464[0];
			double fRec1463 = fTemp337;
			fRec1461[0] = (fRec1462[0] + fRec1461[1]);
			fRec1459[0] = fRec1461[0];
			double fRec1460 = fRec1463;
			fRec1458[0] = (fTemp335 + (fRec1460 + fRec1458[1]));
			fRec1456[0] = fRec1458[0];
			double fRec1457 = (fRec1460 + fTemp335);
			fRec1455[0] = (fRec1456[0] + fRec1455[1]);
			fRec1453[0] = fRec1455[0];
			double fRec1454 = fRec1457;
			double fTemp338 = (fConst79 * (0.0 - ((fConst81 * fRec1474[1]) + (fConst80 * fRec1471[1]))));
			double fTemp339 = (fConst82 * ((fConst5 * (0.0 - ((fConst84 * fRec1480[1]) + (fConst83 * fRec1477[1])))) + (fConst85 * ((((0.0419299437 * fTemp14) + (0.015903693 * fTemp20)) + (0.1093853518 * fTemp19)) - ((0.063707556700000001 * fTemp17) + ((0.080995262100000007 * fTemp16) + ((0.081849991799999994 * fTemp18) + ((0.016342566699999998 * fTemp15) + ((0.0292068235 * fTemp21) + (0.0174119935 * fTemp22))))))))));
			fRec1482[0] = (fRec1482[1] + fTemp339);
			fRec1480[0] = fRec1482[0];
			double fRec1481 = fTemp339;
			fRec1479[0] = (fRec1480[0] + fRec1479[1]);
			fRec1477[0] = fRec1479[0];
			double fRec1478 = fRec1481;
			fRec1476[0] = (fTemp338 + (fRec1478 + fRec1476[1]));
			fRec1474[0] = fRec1476[0];
			double fRec1475 = (fRec1478 + fTemp338);
			fRec1473[0] = (fRec1474[0] + fRec1473[1]);
			fRec1471[0] = fRec1473[0];
			double fRec1472 = fRec1475;
			double fTemp340 = (fConst67 * ((fConst5 * (0.0 - ((fConst71 * fRec1489[1]) + (fConst70 * fRec1486[1])))) + (fConst69 * (((0.064181007999999998 * fTemp46) + (0.0617000074 * fTemp47)) - ((0.063233559100000003 * fTemp44) + ((0.0075418294999999996 * fTemp41) + (((0.1012831045 * fTemp42) + (0.031045277100000001 * fTemp45)) + (0.074057640600000002 * fTemp43))))))));
			fRec1491[0] = (fRec1491[1] + fTemp340);
			fRec1489[0] = fRec1491[0];
			double fRec1490 = fTemp340;
			fRec1488[0] = (fRec1489[0] + fRec1488[1]);
			fRec1486[0] = fRec1488[0];
			double fRec1487 = fRec1490;
			double fTemp341 = (fConst72 * fRec1483[1]);
			fRec1485[0] = ((fRec1487 + fRec1485[1]) - fTemp341);
			fRec1483[0] = fRec1485[0];
			double fRec1484 = (fRec1487 - fTemp341);
			double fTemp342 = (fConst73 * ((((0.1044964968 * fTemp51) + (0.0070786338000000002 * fTemp54)) - (((0.060076910499999997 * fTemp50) + (0.052737310599999997 * fTemp52)) + (0.042538739999999998 * fTemp53))) + (fConst5 * (0.0 - ((fConst75 * fRec1495[1]) + (fConst74 * fRec1492[1]))))));
			fRec1497[0] = (fRec1497[1] + fTemp342);
			fRec1495[0] = fRec1497[0];
			double fRec1496 = fTemp342;
			fRec1494[0] = (fRec1495[0] + fRec1494[1]);
			fRec1492[0] = fRec1494[0];
			double fRec1493 = fRec1496;
			double fTemp343 = (fConst76 * ((((0.063903487199999998 * fTemp56) + (0.055444317600000001 * fTemp57)) - (0.0327476721 * fTemp58)) - (fConst77 * fRec1498[1])));
			fRec1500[0] = (fRec1500[1] + fTemp343);
			fRec1498[0] = fRec1500[0];
			double fRec1499 = fTemp343;
			double fTemp344 = (fConst63 * (0.0 - ((fConst65 * fRec1507[1]) + (fConst64 * fRec1504[1]))));
			double fTemp345 = (fConst57 * ((fConst5 * (0.0 - ((fConst59 * fRec1513[1]) + (fConst58 * fRec1510[1])))) + (fConst62 * (((0.077848111900000003 * fTemp61) + ((0.043444557699999997 * fTemp63) + (0.1037341853 * fTemp64))) - ((((0.020480586200000001 * fTemp65) + ((0.023230636999999998 * fTemp66) + ((((0.0117935921 * fTemp67) + (0.089704091700000002 * fTemp68)) + (0.030713114199999999 * fTemp62)) + (0.0134573261 * fTemp69)))) + (0.028781882000000002 * fTemp70)) + (0.016929549700000001 * fTemp71))))));
			fRec1515[0] = (fRec1515[1] + fTemp345);
			fRec1513[0] = fRec1515[0];
			double fRec1514 = fTemp345;
			fRec1512[0] = (fRec1513[0] + fRec1512[1]);
			fRec1510[0] = fRec1512[0];
			double fRec1511 = fRec1514;
			fRec1509[0] = (fTemp344 + (fRec1511 + fRec1509[1]));
			fRec1507[0] = fRec1509[0];
			double fRec1508 = (fRec1511 + fTemp344);
			fRec1506[0] = (fRec1507[0] + fRec1506[1]);
			fRec1504[0] = fRec1506[0];
			double fRec1505 = fRec1508;
			double fTemp346 = (fConst66 * fRec1501[1]);
			fRec1503[0] = ((fRec1505 + fRec1503[1]) - fTemp346);
			fRec1501[0] = fRec1503[0];
			double fRec1502 = (fRec1505 - fTemp346);
			fVec22[(IOTA & 511)] = (((0.046504427500000001 * fTemp7) + ((0.026800473700000001 * fTemp75) + ((0.0043273015999999997 * fTemp78) + ((0.051063872099999998 * fTemp79) + ((0.049234703599999999 * fTemp74) + ((0.00095756710000000002 * fTemp80) + (((0.031584639900000003 * fTemp13) + (fRec1454 + (fRec1472 + (fRec1484 + (fRec1493 + (fRec1499 + fRec1502)))))) + (0.048073854999999999 * fTemp81)))))))) - ((0.038405579500000002 * fTemp8) + ((0.0072046443999999998 * fTemp9) + ((0.019917919700000002 * fTemp10) + ((0.039738056100000002 * fTemp76) + ((0.0019291707 * fTemp77) + ((0.0022440007000000001 * fTemp11) + ((0.0026862470000000001 * fTemp12) + (0.0038883552000000001 * fTemp82)))))))));
			output22[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec22[((IOTA - iConst86) & 511)])));
			double fTemp347 = (fConst46 * (0.0 - ((fConst48 * fRec1519[1]) + (fConst47 * fRec1516[1]))));
			double fTemp348 = (fConst50 * (0.0 - ((fConst52 * fRec1525[1]) + (fConst51 * fRec1522[1]))));
			double fTemp349 = (fConst53 * ((fConst5 * (0.0 - ((fConst55 * fRec1531[1]) + (fConst54 * fRec1528[1])))) + (fConst56 * (((0.0003721555 * fTemp35) + ((0.0158193924 * fTemp32) + ((((0.020696651100000001 * fTemp28) + (0.0176508997 * fTemp30)) + (0.032148770399999999 * fTemp38)) + (0.00055138509999999997 * fTemp39)))) - ((0.043478053000000003 * fTemp33) + ((0.0082344717000000008 * fTemp34) + (((((0.076990299499999998 * fTemp36) + (0.0432505366 * fTemp37)) + (0.062020836000000003 * fTemp27)) + (0.0261497786 * fTemp29)) + (0.038927336600000001 * fTemp31))))))));
			fRec1533[0] = (fRec1533[1] + fTemp349);
			fRec1531[0] = fRec1533[0];
			double fRec1532 = fTemp349;
			fRec1530[0] = (fRec1531[0] + fRec1530[1]);
			fRec1528[0] = fRec1530[0];
			double fRec1529 = fRec1532;
			fRec1527[0] = (fTemp348 + (fRec1529 + fRec1527[1]));
			fRec1525[0] = fRec1527[0];
			double fRec1526 = (fRec1529 + fTemp348);
			fRec1524[0] = (fRec1525[0] + fRec1524[1]);
			fRec1522[0] = fRec1524[0];
			double fRec1523 = fRec1526;
			fRec1521[0] = (fTemp347 + (fRec1523 + fRec1521[1]));
			fRec1519[0] = fRec1521[0];
			double fRec1520 = (fRec1523 + fTemp347);
			fRec1518[0] = (fRec1519[0] + fRec1518[1]);
			fRec1516[0] = fRec1518[0];
			double fRec1517 = fRec1520;
			double fTemp350 = (fConst63 * (0.0 - ((fConst65 * fRec1540[1]) + (fConst64 * fRec1537[1]))));
			double fTemp351 = (fConst57 * ((fConst5 * (0.0 - ((fConst59 * fRec1546[1]) + (fConst58 * fRec1543[1])))) + (fConst62 * ((((0.0099442948999999992 * fTemp67) + (0.0106395068 * fTemp70)) + (0.016966368400000001 * fTemp71)) - ((0.064143982500000002 * fTemp65) + ((0.074753127500000002 * fTemp61) + ((0.0047548948999999998 * fTemp66) + (((((0.081701227400000007 * fTemp68) + (0.041498773099999997 * fTemp62)) + (0.039649992199999998 * fTemp63)) + (0.041317189900000002 * fTemp69)) + (0.096707616400000002 * fTemp64)))))))));
			fRec1548[0] = (fRec1548[1] + fTemp351);
			fRec1546[0] = fRec1548[0];
			double fRec1547 = fTemp351;
			fRec1545[0] = (fRec1546[0] + fRec1545[1]);
			fRec1543[0] = fRec1545[0];
			double fRec1544 = fRec1547;
			fRec1542[0] = (fTemp350 + (fRec1544 + fRec1542[1]));
			fRec1540[0] = fRec1542[0];
			double fRec1541 = (fRec1544 + fTemp350);
			fRec1539[0] = (fRec1540[0] + fRec1539[1]);
			fRec1537[0] = fRec1539[0];
			double fRec1538 = fRec1541;
			double fTemp352 = (fConst66 * fRec1534[1]);
			fRec1536[0] = ((fRec1538 + fRec1536[1]) - fTemp352);
			fRec1534[0] = fRec1536[0];
			double fRec1535 = (fRec1538 - fTemp352);
			double fTemp353 = (fConst82 * ((fConst5 * (0.0 - ((fConst84 * fRec1558[1]) + (fConst83 * fRec1555[1])))) + (fConst85 * (((0.075692795600000001 * fTemp18) + (0.0047585448999999998 * fTemp22)) - ((0.10644125240000001 * fTemp17) + ((0.091927626900000003 * fTemp16) + ((((0.059515338100000002 * fTemp15) + ((0.0407784697 * fTemp14) + (0.0097754320000000006 * fTemp21))) + (0.014959923999999999 * fTemp20)) + (0.10346473389999999 * fTemp19))))))));
			fRec1560[0] = (fRec1560[1] + fTemp353);
			fRec1558[0] = fRec1560[0];
			double fRec1559 = fTemp353;
			fRec1557[0] = (fRec1558[0] + fRec1557[1]);
			fRec1555[0] = fRec1557[0];
			double fRec1556 = fRec1559;
			double fTemp354 = (fRec1556 + (fConst79 * (0.0 - ((fConst81 * fRec1552[1]) + (fConst80 * fRec1549[1])))));
			fRec1554[0] = (fRec1554[1] + fTemp354);
			fRec1552[0] = fRec1554[0];
			double fRec1553 = fTemp354;
			fRec1551[0] = (fRec1552[0] + fRec1551[1]);
			fRec1549[0] = fRec1551[0];
			double fRec1550 = fRec1553;
			double fTemp355 = (fConst67 * ((fConst69 * ((((0.094756458200000004 * fTemp42) + (0.100904202 * fTemp46)) + (0.028565991999999998 * fTemp45)) - ((0.065394756400000004 * fTemp44) + ((0.031892180300000003 * fTemp41) + ((0.1173150315 * fTemp43) + (0.058814350000000001 * fTemp47)))))) + (fConst5 * (0.0 - ((fConst71 * fRec1567[1]) + (fConst70 * fRec1564[1]))))));
			fRec1569[0] = (fRec1569[1] + fTemp355);
			fRec1567[0] = fRec1569[0];
			double fRec1568 = fTemp355;
			fRec1566[0] = (fRec1567[0] + fRec1566[1]);
			fRec1564[0] = fRec1566[0];
			double fRec1565 = fRec1568;
			double fTemp356 = (fConst72 * fRec1561[1]);
			fRec1563[0] = ((fRec1565 + fRec1563[1]) - fTemp356);
			fRec1561[0] = fRec1563[0];
			double fRec1562 = (fRec1565 - fTemp356);
			double fTemp357 = (fConst73 * ((((((0.056520760900000001 * fTemp50) + (0.1447242077 * fTemp51)) + (0.021229604700000002 * fTemp54)) + (0.049048282999999998 * fTemp52)) - (0.066951590300000002 * fTemp53)) + (fConst5 * (0.0 - ((fConst75 * fRec1573[1]) + (fConst74 * fRec1570[1]))))));
			fRec1575[0] = (fRec1575[1] + fTemp357);
			fRec1573[0] = fRec1575[0];
			double fRec1574 = fTemp357;
			fRec1572[0] = (fRec1573[0] + fRec1572[1]);
			fRec1570[0] = fRec1572[0];
			double fRec1571 = fRec1574;
			double fTemp358 = (fConst76 * ((((0.086306478000000006 * fTemp56) + (0.077722109100000006 * fTemp57)) + (0.030579153299999998 * fTemp58)) - (fConst77 * fRec1576[1])));
			fRec1578[0] = (fRec1578[1] + fTemp358);
			fRec1576[0] = fRec1578[0];
			double fRec1577 = fTemp358;
			fVec23[(IOTA & 511)] = (((0.025742549100000001 * fTemp7) + ((0.0010603196000000001 * fTemp75) + ((0.035228830099999997 * fTemp8) + ((0.018747608999999998 * fTemp9) + ((0.0196994575 * fTemp10) + ((0.00068174719999999998 * fTemp77) + ((0.0036185690999999999 * fTemp11) + ((0.03185487 * fTemp79) + ((0.042479524999999997 * fTemp13) + (fRec1517 + (fRec1535 + (fRec1550 + (fRec1562 + (fRec1571 + (fRec1577 + (0.0047059952999999998 * fTemp82)))))))))))))))) - ((0.0069789014999999998 * fTemp76) + ((0.0074424761000000004 * fTemp78) + ((((0.042862929899999999 * fTemp81) + (0.0179969962 * fTemp80)) + (0.043099454500000002 * fTemp74)) + (0.00041846610000000002 * fTemp12)))));
			output23[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec23[((IOTA - iConst86) & 511)])));
			double fTemp359 = (fConst88 * (0.0 - ((fConst90 * fRec1582[1]) + (fConst89 * fRec1579[1]))));
			double fTemp360 = (fConst91 * ((fConst5 * (0.0 - ((fConst93 * fRec1588[1]) + (fConst92 * fRec1585[1])))) + (fConst94 * (((0.044844193800000001 * fTemp16) + ((0.077527304199999994 * fTemp18) + (((0.019443636100000002 * fTemp15) + (0.091170567699999996 * fTemp21)) + (0.0908243938 * fTemp20)))) - ((0.00045907810000000001 * fTemp17) + ((0.019823344199999999 * fTemp19) + ((6.83278e-05 * fTemp14) + (0.0055343296000000004 * fTemp22))))))));
			fRec1590[0] = (fRec1590[1] + fTemp360);
			fRec1588[0] = fRec1590[0];
			double fRec1589 = fTemp360;
			fRec1587[0] = (fRec1588[0] + fRec1587[1]);
			fRec1585[0] = fRec1587[0];
			double fRec1586 = fRec1589;
			fRec1584[0] = (fTemp359 + (fRec1586 + fRec1584[1]));
			fRec1582[0] = fRec1584[0];
			double fRec1583 = (fRec1586 + fTemp359);
			fRec1581[0] = (fRec1582[0] + fRec1581[1]);
			fRec1579[0] = fRec1581[0];
			double fRec1580 = fRec1583;
			double fTemp361 = (fConst95 * ((fConst5 * (0.0 - ((fConst97 * fRec1597[1]) + (fConst96 * fRec1594[1])))) + (fConst99 * (((0.074249264300000006 * fTemp44) + ((0.0074215373999999999 * fTemp41) + (((0.047310529900000002 * fTemp42) + (0.080226799400000007 * fTemp46)) + (0.079867278700000002 * fTemp45)))) - ((0.00028462970000000002 * fTemp43) + (0.0075645291 * fTemp47))))));
			fRec1599[0] = (fRec1599[1] + fTemp361);
			fRec1597[0] = fRec1599[0];
			double fRec1598 = fTemp361;
			fRec1596[0] = (fRec1597[0] + fRec1596[1]);
			fRec1594[0] = fRec1596[0];
			double fRec1595 = fRec1598;
			double fTemp362 = (fConst100 * fRec1591[1]);
			fRec1593[0] = ((fRec1595 + fRec1593[1]) - fTemp362);
			fRec1591[0] = fRec1593[0];
			double fRec1592 = (fRec1595 - fTemp362);
			double fTemp363 = (fConst102 * (0.0 - ((fConst104 * fRec1603[1]) + (fConst103 * fRec1600[1]))));
			double fTemp364 = (fConst105 * ((fConst5 * (0.0 - ((fConst107 * fRec1615[1]) + (fConst106 * fRec1612[1])))) + (fConst109 * (((0.097567377699999999 * fTemp33) + ((((0.045254595799999998 * fTemp37) + (0.061233848200000003 * fTemp27)) + (0.061246801699999999 * fTemp29)) + (1.1094099999999999e-05 * fTemp39))) - ((0.0052185130999999997 * fTemp34) + ((0.00087582060000000002 * fTemp35) + ((0.0279242884 * fTemp32) + (((((0.00036341530000000001 * fTemp36) + (0.0146085142 * fTemp28)) + (0.00050955939999999995 * fTemp30)) + (0.046159838299999999 * fTemp31)) + (0.0050672701999999997 * fTemp38)))))))));
			fRec1617[0] = (fRec1617[1] + fTemp364);
			fRec1615[0] = fRec1617[0];
			double fRec1616 = fTemp364;
			fRec1614[0] = (fRec1615[0] + fRec1614[1]);
			fRec1612[0] = fRec1614[0];
			double fRec1613 = fRec1616;
			double fTemp365 = (fRec1613 + (fConst110 * (0.0 - ((fConst112 * fRec1609[1]) + (fConst111 * fRec1606[1])))));
			fRec1611[0] = (fRec1611[1] + fTemp365);
			fRec1609[0] = fRec1611[0];
			double fRec1610 = fTemp365;
			fRec1608[0] = (fRec1609[0] + fRec1608[1]);
			fRec1606[0] = fRec1608[0];
			double fRec1607 = fRec1610;
			fRec1605[0] = (fTemp363 + (fRec1607 + fRec1605[1]));
			fRec1603[0] = fRec1605[0];
			double fRec1604 = (fRec1607 + fTemp363);
			fRec1602[0] = (fRec1603[0] + fRec1602[1]);
			fRec1600[0] = fRec1602[0];
			double fRec1601 = fRec1604;
			double fTemp366 = (fConst113 * ((((((0.018889524800000002 * fTemp50) + (0.0532528341 * fTemp51)) + (0.084355014699999994 * fTemp54)) + (0.052994769900000002 * fTemp52)) - (0.0001143287 * fTemp53)) + (fConst5 * (0.0 - ((fConst115 * fRec1621[1]) + (fConst114 * fRec1618[1]))))));
			fRec1623[0] = (fRec1623[1] + fTemp366);
			fRec1621[0] = fRec1623[0];
			double fRec1622 = fTemp366;
			fRec1620[0] = (fRec1621[0] + fRec1620[1]);
			fRec1618[0] = fRec1620[0];
			double fRec1619 = fRec1622;
			double fTemp367 = (fConst116 * ((((0.0220263973 * fTemp56) + (0.066940710599999995 * fTemp57)) + (0.021915488699999999 * fTemp58)) - (fConst117 * fRec1624[1])));
			fRec1626[0] = (fRec1626[1] + fTemp367);
			fRec1624[0] = fRec1626[0];
			double fRec1625 = fTemp367;
			double fTemp368 = (fConst119 * (0.0 - ((fConst121 * fRec1633[1]) + (fConst120 * fRec1630[1]))));
			double fTemp369 = (fConst122 * ((fConst124 * (((0.033880384499999999 * fTemp65) + ((((0.097021274699999993 * fTemp67) + (0.082867077299999994 * fTemp68)) + (0.010806218899999999 * fTemp62)) + (0.082661755099999998 * fTemp63))) - ((((0.00019222339999999999 * fTemp61) + ((0.0018226468000000001 * fTemp66) + ((0.00055332020000000001 * fTemp69) + (0.034551079300000002 * fTemp64)))) + (0.015180261400000001 * fTemp70)) + (0.0017719496000000001 * fTemp71)))) + (fConst5 * (0.0 - ((fConst126 * fRec1639[1]) + (fConst125 * fRec1636[1]))))));
			fRec1641[0] = (fRec1641[1] + fTemp369);
			fRec1639[0] = fRec1641[0];
			double fRec1640 = fTemp369;
			fRec1638[0] = (fRec1639[0] + fRec1638[1]);
			fRec1636[0] = fRec1638[0];
			double fRec1637 = fRec1640;
			fRec1635[0] = (fTemp368 + (fRec1637 + fRec1635[1]));
			fRec1633[0] = fRec1635[0];
			double fRec1634 = (fRec1637 + fTemp368);
			fRec1632[0] = (fRec1633[0] + fRec1632[1]);
			fRec1630[0] = fRec1632[0];
			double fRec1631 = fRec1634;
			double fTemp370 = (fConst127 * fRec1627[1]);
			fRec1629[0] = ((fRec1631 + fRec1629[1]) - fTemp370);
			fRec1627[0] = fRec1629[0];
			double fRec1628 = (fRec1631 - fTemp370);
			fVec24[(IOTA & 255)] = (((3.6035699999999998e-05 * fTemp75) + ((0.037242685800000001 * fTemp11) + ((0.037019729299999998 * fTemp12) + ((0.079754769599999997 * fTemp74) + ((0.0484313065 * fTemp80) + ((0.025484838499999999 * fTemp13) + (fRec1580 + (fRec1592 + (fRec1601 + (fRec1619 + (fRec1625 + (fRec1628 + (2.3256900000000001e-05 * fTemp82))))))))))))) - ((0.00033137070000000002 * fTemp7) + (((((0.010062624500000001 * fTemp76) + ((0.0025986469999999999 * fTemp77) + ((2.9488500000000001e-05 * fTemp78) + ((0.00052853640000000005 * fTemp81) + (0.0255275082 * fTemp79))))) + (0.049401036400000001 * fTemp10)) + (0.039513326699999997 * fTemp9)) + (0.0097580106999999999 * fTemp8))));
			output24[i] = FAUSTFLOAT((0.95355093256814927 * (fRec0[0] * fVec24[((IOTA - iConst128) & 255)])));
			double fTemp371 = (fConst116 * ((((0.088250094200000004 * fTemp57) + (0.036347145999999997 * fTemp58)) - (0.0221166977 * fTemp56)) - (fConst117 * fRec1642[1])));
			fRec1644[0] = (fRec1644[1] + fTemp371);
			fRec1642[0] = fRec1644[0];
			double fRec1643 = fTemp371;
			double fTemp372 = (fConst102 * (0.0 - ((fConst104 * fRec1648[1]) + (fConst103 * fRec1645[1]))));
			double fTemp373 = (fConst110 * (0.0 - ((fConst112 * fRec1654[1]) + (fConst111 * fRec1651[1]))));
			double fTemp374 = (fConst105 * ((fConst5 * (0.0 - ((fConst107 * fRec1660[1]) + (fConst106 * fRec1657[1])))) + (fConst109 * (((0.0048826579000000002 * fTemp34) + ((0.00067104459999999997 * fTemp35) + (((((0.00098828340000000009 * fTemp36) + (0.059107625499999997 * fTemp29)) + (0.041903070200000003 * fTemp30)) + (0.0036029609 * fTemp38)) + (0.0015209374999999999 * fTemp39)))) - ((0.094534886400000004 * fTemp33) + (((((0.042814636199999999 * fTemp37) + (0.059541774899999997 * fTemp27)) + (0.044505795899999999 * fTemp28)) + (0.00070471439999999998 * fTemp31)) + (0.0021902911000000001 * fTemp32)))))));
			fRec1662[0] = (fRec1662[1] + fTemp374);
			fRec1660[0] = fRec1662[0];
			double fRec1661 = fTemp374;
			fRec1659[0] = (fRec1660[0] + fRec1659[1]);
			fRec1657[0] = fRec1659[0];
			double fRec1658 = fRec1661;
			fRec1656[0] = (fTemp373 + (fRec1658 + fRec1656[1]));
			fRec1654[0] = fRec1656[0];
			double fRec1655 = (fRec1658 + fTemp373);
			fRec1653[0] = (fRec1654[0] + fRec1653[1]);
			fRec1651[0] = fRec1653[0];
			double fRec1652 = fRec1655;
			fRec1650[0] = (fTemp372 + (fRec1652 + fRec1650[1]));
			fRec1648[0] = fRec1650[0];
			double fRec1649 = (fRec1652 + fTemp372);
			fRec1647[0] = (fRec1648[0] + fRec1647[1]);
			fRec1645[0] = fRec1647[0];
			double fRec1646 = fRec1649;
			double fTemp375 = (fConst119 * (0.0 - ((fConst121 * fRec1669[1]) + (fConst120 * fRec1666[1]))));
			double fTemp376 = (fConst122 * ((fConst5 * (0.0 - ((fConst126 * fRec1675[1]) + (fConst125 * fRec1672[1])))) + (fConst124 * ((((0.00039432650000000003 * fTemp61) + ((0.0016894869999999999 * fTemp66) + (((0.1057515086 * fTemp63) + (0.048505625099999998 * fTemp69)) + (0.00013225619999999999 * fTemp64)))) + (0.0012080299999999999 * fTemp71)) - (((0.0326343391 * fTemp65) + (((0.095239837300000005 * fTemp67) + (0.081620654000000001 * fTemp68)) + (0.0140094637 * fTemp62))) + (0.0013064534999999999 * fTemp70))))));
			fRec1677[0] = (fRec1677[1] + fTemp376);
			fRec1675[0] = fRec1677[0];
			double fRec1676 = fTemp376;
			fRec1674[0] = (fRec1675[0] + fRec1674[1]);
			fRec1672[0] = fRec1674[0];
			double fRec1673 = fRec1676;
			fRec1671[0] = (fTemp375 + (fRec1673 + fRec1671[1]));
			fRec1669[0] = fRec1671[0];
			double fRec1670 = (fRec1673 + fTemp375);
			fRec1668[0] = (fRec1669[0] + fRec1668[1]);
			fRec1666[0] = fRec1668[0];
			double fRec1667 = fRec1670;
			double fTemp377 = (fConst127 * fRec1663[1]);
			fRec1665[0] = ((fRec1667 + fRec1665[1]) - fTemp377);
			fRec1663[0] = fRec1665[0];
			double fRec1664 = (fRec1667 - fTemp377);
			double fTemp378 = (fConst95 * ((fConst5 * (0.0 - ((fConst97 * fRec1684[1]) + (fConst96 * fRec1681[1])))) + (fConst99 * (((0.083417450300000001 * fTemp44) + ((0.0269801361 * fTemp43) + ((0.1245961587 * fTemp45) + (0.0001976359 * fTemp47)))) - ((0.0072807378999999997 * fTemp41) + ((0.047062170200000003 * fTemp42) + (0.080118257700000001 * fTemp46)))))));
			fRec1686[0] = (fRec1686[1] + fTemp378);
			fRec1684[0] = fRec1686[0];
			double fRec1685 = fTemp378;
			fRec1683[0] = (fRec1684[0] + fRec1683[1]);
			fRec1681[0] = fRec1683[0];
			double fRec1682 = fRec1685;
			double fTemp379 = (fConst100 * fRec1678[1]);
			fRec1680[0] = ((fRec1682 + fRec1680[1]) - fTemp379);
			fRec1678[0] = fRec1680[0];
			double fRec1679 = (fRec1682 - fTemp379);
			double fTemp380 = (fConst113 * (((((0.1059216186 * fTemp54) + (0.085990975400000003 * fTemp52)) + (0.0110994197 * fTemp53)) - ((0.018852114400000002 * fTemp50) + (0.053363046400000003 * fTemp51))) + (fConst5 * (0.0 - ((fConst115 * fRec1690[1]) + (fConst114 * fRec1687[1]))))));
			fRec1692[0] = (fRec1692[1] + fTemp380);
			fRec1690[0] = fRec1692[0];
			double fRec1691 = fTemp380;
			fRec1689[0] = (fRec1690[0] + fRec1689[1]);
			fRec1687[0] = fRec1689[0];
			double fRec1688 = fRec1691;
			double fTemp381 = (fConst88 * (0.0 - ((fConst90 * fRec1696[1]) + (fConst89 * fRec1693[1]))));
			double fTemp382 = (fConst91 * ((fConst5 * (0.0 - ((fConst93 * fRec1702[1]) + (fConst92 * fRec1699[1])))) + (fConst94 * (((0.042095312000000003 * fTemp17) + ((0.035412133300000002 * fTemp16) + (((0.0001095549 * fTemp14) + (0.13222508099999999 * fTemp20)) + (0.00033663619999999998 * fTemp19)))) - ((0.076722609400000003 * fTemp18) + ((0.018938804100000001 * fTemp15) + ((0.090556428999999994 * fTemp21) + (0.00050223140000000004 * fTemp22))))))));
			fRec1704[0] = (fRec1704[1] + fTemp382);
			fRec1702[0] = fRec1704[0];
			double fRec1703 = fTemp382;
			fRec1701[0] = (fRec1702[0] + fRec1701[1]);
			fRec1699[0] = fRec1701[0];
			double fRec1700 = fRec1703;
			fRec1698[0] = (fTemp381 + (fRec1700 + fRec1698[1]));
			fRec1696[0] = fRec1698[0];
			double fRec1697 = (fRec1700 + fTemp381);
			fRec1695[0] = (fRec1696[0] + fRec1695[1]);
			fRec1693[0] = fRec1695[0];
			double fRec1694 = fRec1697;
			fVec25[(IOTA & 255)] = (((0.024339520999999999 * fTemp7) + ((0.0046630341000000004 * fTemp75) + ((0.0073654382000000003 * fTemp8) + ((0.0095518174000000008 * fTemp76) + ((0.0020033243 * fTemp77) + ((0.0141196407 * fTemp11) + ((0.0019881279 * fTemp81) + ((0.0342672386 * fTemp13) + (fRec1643 + (fRec1646 + (fRec1664 + (fRec1679 + (fRec1688 + (fRec1694 + (0.00060702 * fTemp82))))))))))))))) - ((((0.0001184947 * fTemp78) + ((((0.044428932800000001 * fTemp80) + (0.0755789927 * fTemp74)) + (0.035368703899999999 * fTemp12)) + (0.049015149700000003 * fTemp79))) + (0.0021804480000000002 * fTemp10)) + (0.0025871422999999998 * fTemp9)));
			output25[i] = FAUSTFLOAT((0.95355093256814927 * (fRec0[0] * fVec25[((IOTA - iConst128) & 255)])));
			double fTemp383 = (fConst88 * (0.0 - ((fConst90 * fRec1708[1]) + (fConst89 * fRec1705[1]))));
			double fTemp384 = (fConst91 * ((fConst5 * (0.0 - ((fConst93 * fRec1714[1]) + (fConst92 * fRec1711[1])))) + (fConst94 * (((0.035475477599999999 * fTemp16) + ((0.077886471700000001 * fTemp18) + (0.019692611400000001 * fTemp19))) - ((0.0409009969 * fTemp17) + ((0.090854007400000006 * fTemp20) + ((0.00047503239999999999 * fTemp15) + ((3.8794600000000003e-05 * fTemp14) + ((0.1311634807 * fTemp21) + (0.000748532 * fTemp22))))))))));
			fRec1716[0] = (fRec1716[1] + fTemp384);
			fRec1714[0] = fRec1716[0];
			double fRec1715 = fTemp384;
			fRec1713[0] = (fRec1714[0] + fRec1713[1]);
			fRec1711[0] = fRec1713[0];
			double fRec1712 = fRec1715;
			fRec1710[0] = (fTemp383 + (fRec1712 + fRec1710[1]));
			fRec1708[0] = fRec1710[0];
			double fRec1709 = (fRec1712 + fTemp383);
			fRec1707[0] = (fRec1708[0] + fRec1707[1]);
			fRec1705[0] = fRec1707[0];
			double fRec1706 = fRec1709;
			double fTemp385 = (fConst95 * ((fConst5 * (0.0 - ((fConst97 * fRec1723[1]) + (fConst96 * fRec1720[1])))) + (fConst99 * (((0.083063305300000001 * fTemp44) + ((0.047892361899999999 * fTemp42) + (0.0075846198999999998 * fTemp47))) - ((0.00013548499999999999 * fTemp41) + (((0.12352071570000001 * fTemp46) + (0.080642031099999997 * fTemp45)) + (0.026178806400000001 * fTemp43)))))));
			fRec1725[0] = (fRec1725[1] + fTemp385);
			fRec1723[0] = fRec1725[0];
			double fRec1724 = fTemp385;
			fRec1722[0] = (fRec1723[0] + fRec1722[1]);
			fRec1720[0] = fRec1722[0];
			double fRec1721 = fRec1724;
			double fTemp386 = (fConst100 * fRec1717[1]);
			fRec1719[0] = ((fRec1721 + fRec1719[1]) - fTemp386);
			fRec1717[0] = fRec1719[0];
			double fRec1718 = (fRec1721 - fTemp386);
			double fTemp387 = (fConst102 * (0.0 - ((fConst104 * fRec1729[1]) + (fConst103 * fRec1726[1]))));
			double fTemp388 = (fConst110 * (0.0 - ((fConst112 * fRec1735[1]) + (fConst111 * fRec1732[1]))));
			double fTemp389 = (fConst105 * ((fConst109 * (((0.095210034099999993 * fTemp33) + (((0.00022245690000000001 * fTemp36) + (0.044269887500000001 * fTemp31)) + (0.0047963976000000002 * fTemp38))) - ((0.0033206176999999999 * fTemp34) + ((0.00070310920000000001 * fTemp35) + ((0.0032231794000000002 * fTemp32) + ((((((0.0021590565000000001 * fTemp37) + (0.0590342487 * fTemp27)) + (0.043702841300000003 * fTemp28)) + (0.059098052999999998 * fTemp29)) + (0.040936190900000002 * fTemp30)) + (0.0015409843999999999 * fTemp39))))))) + (fConst5 * (0.0 - ((fConst107 * fRec1741[1]) + (fConst106 * fRec1738[1]))))));
			fRec1743[0] = (fRec1743[1] + fTemp389);
			fRec1741[0] = fRec1743[0];
			double fRec1742 = fTemp389;
			fRec1740[0] = (fRec1741[0] + fRec1740[1]);
			fRec1738[0] = fRec1740[0];
			double fRec1739 = fRec1742;
			fRec1737[0] = (fTemp388 + (fRec1739 + fRec1737[1]));
			fRec1735[0] = fRec1737[0];
			double fRec1736 = (fRec1739 + fTemp388);
			fRec1734[0] = (fRec1735[0] + fRec1734[1]);
			fRec1732[0] = fRec1734[0];
			double fRec1733 = fRec1736;
			fRec1731[0] = (fTemp387 + (fRec1733 + fRec1731[1]));
			fRec1729[0] = fRec1731[0];
			double fRec1730 = (fRec1733 + fTemp387);
			fRec1728[0] = (fRec1729[0] + fRec1728[1]);
			fRec1726[0] = fRec1728[0];
			double fRec1727 = fRec1730;
			double fTemp390 = (fConst113 * ((((0.0192173694 * fTemp50) + (0.1053520488 * fTemp54)) - (((0.0852277699 * fTemp51) + (0.0538309155 * fTemp52)) + (0.010759918699999999 * fTemp53))) + (fConst5 * (0.0 - ((fConst115 * fRec1747[1]) + (fConst114 * fRec1744[1]))))));
			fRec1749[0] = (fRec1749[1] + fTemp390);
			fRec1747[0] = fRec1749[0];
			double fRec1748 = fTemp390;
			fRec1746[0] = (fRec1747[0] + fRec1746[1]);
			fRec1744[0] = fRec1746[0];
			double fRec1745 = fRec1748;
			double fTemp391 = (fConst116 * (((0.087746924800000001 * fTemp57) - ((0.036021007299999998 * fTemp56) + (0.0223415236 * fTemp58))) - (fConst117 * fRec1750[1])));
			fRec1752[0] = (fRec1752[1] + fTemp391);
			fRec1750[0] = fRec1752[0];
			double fRec1751 = fTemp391;
			double fTemp392 = (fConst119 * (0.0 - ((fConst121 * fRec1759[1]) + (fConst120 * fRec1756[1]))));
			double fTemp393 = (fConst122 * ((fConst5 * (0.0 - ((fConst126 * fRec1765[1]) + (fConst125 * fRec1762[1])))) + (fConst124 * ((((0.096361569300000005 * fTemp67) + (0.033850340200000002 * fTemp64)) + (0.0016694532000000001 * fTemp71)) - (((0.0011407392000000001 * fTemp65) + ((1.62738e-05 * fTemp61) + ((0.0011009454 * fTemp66) + ((((0.10507075070000001 * fTemp68) + (0.0134977841 * fTemp62)) + (0.081516563299999997 * fTemp63)) + (0.0472265532 * fTemp69))))) + (0.0019315948999999999 * fTemp70))))));
			fRec1767[0] = (fRec1767[1] + fTemp393);
			fRec1765[0] = fRec1767[0];
			double fRec1766 = fTemp393;
			fRec1764[0] = (fRec1765[0] + fRec1764[1]);
			fRec1762[0] = fRec1764[0];
			double fRec1763 = fRec1766;
			fRec1761[0] = (fTemp392 + (fRec1763 + fRec1761[1]));
			fRec1759[0] = fRec1761[0];
			double fRec1760 = (fRec1763 + fTemp392);
			fRec1758[0] = (fRec1759[0] + fRec1758[1]);
			fRec1756[0] = fRec1758[0];
			double fRec1757 = fRec1760;
			double fTemp394 = (fConst127 * fRec1753[1]);
			fRec1755[0] = ((fRec1757 + fRec1755[1]) - fTemp394);
			fRec1753[0] = fRec1755[0];
			double fRec1754 = (fRec1757 - fTemp394);
			fVec26[(IOTA & 255)] = (((0.0093138253000000001 * fTemp8) + ((0.045750388400000001 * fTemp10) + ((0.00069393829999999995 * fTemp78) + ((0.075629463399999999 * fTemp74) + ((0.00088086429999999997 * fTemp81) + ((0.034068688299999997 * fTemp13) + (fRec1706 + (fRec1718 + (fRec1727 + (fRec1745 + (fRec1751 + (fRec1754 + (9.2771500000000004e-05 * fTemp82))))))))))))) - ((0.0239533527 * fTemp7) + ((((0.0068776836000000001 * fTemp76) + ((0.0020685450000000002 * fTemp77) + ((((0.0033925877000000001 * fTemp80) + (0.0146321522 * fTemp12)) + (0.048196677 * fTemp79)) + (0.034849742699999998 * fTemp11)))) + (0.0038418432999999998 * fTemp9)) + (0.0047241395000000002 * fTemp75))));
			output26[i] = FAUSTFLOAT((0.95355093256814927 * (fRec0[0] * fVec26[((IOTA - iConst128) & 255)])));
			double fTemp395 = (fConst102 * (0.0 - ((fConst104 * fRec1771[1]) + (fConst103 * fRec1768[1]))));
			double fTemp396 = (fConst110 * (0.0 - ((fConst112 * fRec1777[1]) + (fConst111 * fRec1774[1]))));
			double fTemp397 = (fConst105 * ((fConst5 * (0.0 - ((fConst107 * fRec1783[1]) + (fConst106 * fRec1780[1])))) + (fConst109 * (((0.0036984153000000001 * fTemp34) + ((0.00056827519999999999 * fTemp35) + ((0.0224367977 * fTemp32) + ((0.057387883399999999 * fTemp27) + (0.00013582430000000001 * fTemp39))))) - ((0.091575617900000003 * fTemp33) + (((((((0.00078150680000000001 * fTemp36) + (8.4949600000000004e-05 * fTemp37)) + (0.071978986699999997 * fTemp28)) + (0.0567845898 * fTemp29)) + (0.00045945609999999999 * fTemp30)) + (0.0013246811999999999 * fTemp31)) + (0.0037257916000000002 * fTemp38)))))));
			fRec1785[0] = (fRec1785[1] + fTemp397);
			fRec1783[0] = fRec1785[0];
			double fRec1784 = fTemp397;
			fRec1782[0] = (fRec1783[0] + fRec1782[1]);
			fRec1780[0] = fRec1782[0];
			double fRec1781 = fRec1784;
			fRec1779[0] = (fTemp396 + (fRec1781 + fRec1779[1]));
			fRec1777[0] = fRec1779[0];
			double fRec1778 = (fRec1781 + fTemp396);
			fRec1776[0] = (fRec1777[0] + fRec1776[1]);
			fRec1774[0] = fRec1776[0];
			double fRec1775 = fRec1778;
			fRec1773[0] = (fTemp395 + (fRec1775 + fRec1773[1]));
			fRec1771[0] = fRec1773[0];
			double fRec1772 = (fRec1775 + fTemp395);
			fRec1770[0] = (fRec1771[0] + fRec1770[1]);
			fRec1768[0] = fRec1770[0];
			double fRec1769 = fRec1772;
			double fTemp398 = (fConst95 * ((fConst5 * (0.0 - ((fConst97 * fRec1792[1]) + (fConst96 * fRec1789[1])))) + (fConst99 * (((0.091598701500000004 * fTemp44) + ((4.6511999999999996e-06 * fTemp41) + ((0.1231784569 * fTemp46) + (0.0002487492 * fTemp43)))) - ((0.1228703683 * fTemp45) + ((0.046980838699999999 * fTemp42) + (0.00033243319999999999 * fTemp47)))))));
			fRec1794[0] = (fRec1794[1] + fTemp398);
			fRec1792[0] = fRec1794[0];
			double fRec1793 = fTemp398;
			fRec1791[0] = (fRec1792[0] + fRec1791[1]);
			fRec1789[0] = fRec1791[0];
			double fRec1790 = fRec1793;
			double fTemp399 = (fConst100 * fRec1786[1]);
			fRec1788[0] = ((fRec1790 + fRec1788[1]) - fTemp399);
			fRec1786[0] = fRec1788[0];
			double fRec1787 = (fRec1790 - fTemp399);
			double fTemp400 = (fConst88 * (0.0 - ((fConst90 * fRec1798[1]) + (fConst89 * fRec1795[1]))));
			double fTemp401 = (fConst91 * ((fConst5 * (0.0 - ((fConst93 * fRec1804[1]) + (fConst92 * fRec1801[1])))) + (fConst94 * (((0.00021647539999999999 * fTemp17) + ((0.0263377365 * fTemp16) + ((8.2826999999999995e-06 * fTemp15) + ((0.1303688167 * fTemp21) + (0.0043209737000000003 * fTemp22))))) - ((0.076127181000000002 * fTemp18) + (((0.00016173690000000001 * fTemp14) + (0.12980282479999999 * fTemp20)) + (0.00079116929999999998 * fTemp19)))))));
			fRec1806[0] = (fRec1806[1] + fTemp401);
			fRec1804[0] = fRec1806[0];
			double fRec1805 = fTemp401;
			fRec1803[0] = (fRec1804[0] + fRec1803[1]);
			fRec1801[0] = fRec1803[0];
			double fRec1802 = fRec1805;
			fRec1800[0] = (fTemp400 + (fRec1802 + fRec1800[1]));
			fRec1798[0] = fRec1800[0];
			double fRec1799 = (fRec1802 + fTemp400);
			fRec1797[0] = (fRec1798[0] + fRec1797[1]);
			fRec1795[0] = fRec1797[0];
			double fRec1796 = fRec1799;
			double fTemp402 = (fConst113 * (((((0.085146978799999995 * fTemp51) + (0.12573050590000001 * fTemp54)) + (0.00013258160000000001 * fTemp53)) - ((0.018893480399999999 * fTemp50) + (0.085042134500000005 * fTemp52))) + (fConst5 * (0.0 - ((fConst115 * fRec1810[1]) + (fConst114 * fRec1807[1]))))));
			fRec1812[0] = (fRec1812[1] + fTemp402);
			fRec1810[0] = fRec1812[0];
			double fRec1811 = fTemp402;
			fRec1809[0] = (fRec1810[0] + fRec1809[1]);
			fRec1807[0] = fRec1809[0];
			double fRec1808 = fRec1811;
			double fTemp403 = (fConst116 * ((((0.036022687499999997 * fTemp56) + (0.10794643850000001 * fTemp57)) - (0.036007171800000001 * fTemp58)) - (fConst117 * fRec1813[1])));
			fRec1815[0] = (fRec1815[1] + fTemp403);
			fRec1813[0] = fRec1815[0];
			double fRec1814 = fTemp403;
			double fTemp404 = (fConst119 * (0.0 - ((fConst121 * fRec1822[1]) + (fConst120 * fRec1819[1]))));
			double fTemp405 = (fConst122 * ((fConst5 * (0.0 - ((fConst126 * fRec1828[1]) + (fConst125 * fRec1825[1])))) + (fConst124 * ((((0.0012526867000000001 * fTemp66) + (0.1037612626 * fTemp68)) + (0.0119838293 * fTemp70)) - (((7.2930999999999997e-06 * fTemp65) + ((0.00043575059999999998 * fTemp61) + (((((0.093625903699999999 * fTemp67) + (0.037145560299999998 * fTemp62)) + (0.1030427476 * fTemp63)) + (4.7280400000000002e-05 * fTemp69)) + (0.0012021619999999999 * fTemp64)))) + (0.0012754428 * fTemp71))))));
			fRec1830[0] = (fRec1830[1] + fTemp405);
			fRec1828[0] = fRec1830[0];
			double fRec1829 = fTemp405;
			fRec1827[0] = (fRec1828[0] + fRec1827[1]);
			fRec1825[0] = fRec1827[0];
			double fRec1826 = fRec1829;
			fRec1824[0] = (fTemp404 + (fRec1826 + fRec1824[1]));
			fRec1822[0] = fRec1824[0];
			double fRec1823 = (fRec1826 + fTemp404);
			fRec1821[0] = (fRec1822[0] + fRec1821[1]);
			fRec1819[0] = fRec1821[0];
			double fRec1820 = fRec1823;
			double fTemp406 = (fConst127 * fRec1816[1]);
			fRec1818[0] = ((fRec1820 + fRec1818[1]) - fTemp406);
			fRec1816[0] = fRec1818[0];
			double fRec1817 = (fRec1820 - fTemp406);
			fVec27[(IOTA & 255)] = (((0.0003718894 * fTemp75) + ((0.032689231999999999 * fTemp9) + ((0.0074419114 * fTemp76) + ((0.0017081735000000001 * fTemp77) + (((0.0424027981 * fTemp13) + (fRec1769 + (fRec1787 + (fRec1796 + (fRec1808 + (fRec1814 + fRec1817)))))) + (0.0130691499 * fTemp12)))))) - ((0.00079129839999999999 * fTemp7) + ((0.0074049236999999997 * fTemp8) + ((0.0010930651000000001 * fTemp10) + ((0.00049793560000000001 * fTemp78) + ((0.012881291899999999 * fTemp11) + ((0.070168286100000005 * fTemp79) + ((0.071417033300000002 * fTemp74) + ((0.00028829389999999999 * fTemp80) + ((0.0010664432000000001 * fTemp81) + (0.00068703259999999995 * fTemp82)))))))))));
			output27[i] = FAUSTFLOAT((0.95355093256814927 * (fRec0[0] * fVec27[((IOTA - iConst128) & 255)])));
			double fTemp407 = (fConst130 * (0.0 - ((fConst132 * fRec1837[1]) + (fConst131 * fRec1834[1]))));
			double fTemp408 = (fConst133 * ((fConst135 * ((((4.8663000000000003e-06 * fTemp65) + ((1.1880999999999999e-06 * fTemp61) + ((2.5699999999999999e-08 * fTemp66) + ((((1.28405e-05 * fTemp67) + (2.6307100000000001e-05 * fTemp68)) + (0.0916704765 * fTemp62)) + (7.3862999999999999e-06 * fTemp64))))) + (4.2000000000000004e-09 * fTemp71)) - (((8.3396699999999994e-05 * fTemp63) + (1.9692000000000001e-05 * fTemp69)) + (9.8370300000000002e-05 * fTemp70)))) + (fConst5 * (0.0 - ((fConst137 * fRec1843[1]) + (fConst136 * fRec1840[1]))))));
			fRec1845[0] = (fRec1845[1] + fTemp408);
			fRec1843[0] = fRec1845[0];
			double fRec1844 = fTemp408;
			fRec1842[0] = (fRec1843[0] + fRec1842[1]);
			fRec1840[0] = fRec1842[0];
			double fRec1841 = fRec1844;
			fRec1839[0] = (fTemp407 + (fRec1841 + fRec1839[1]));
			fRec1837[0] = fRec1839[0];
			double fRec1838 = (fRec1841 + fTemp407);
			fRec1836[0] = (fRec1837[0] + fRec1836[1]);
			fRec1834[0] = fRec1836[0];
			double fRec1835 = fRec1838;
			double fTemp409 = (fConst138 * fRec1831[1]);
			fRec1833[0] = ((fRec1835 + fRec1833[1]) - fTemp409);
			fRec1831[0] = fRec1833[0];
			double fRec1832 = (fRec1835 - fTemp409);
			double fTemp410 = (fConst140 * (0.0 - ((fConst142 * fRec1849[1]) + (fConst141 * fRec1846[1]))));
			double fTemp411 = (fConst143 * ((fConst144 * (((0.080551933800000003 * fTemp16) + ((7.3386999999999997e-06 * fTemp18) + (((2.0760999999999999e-06 * fTemp15) + ((3.3640000000000002e-07 * fTemp14) + (1.80029e-05 * fTemp21))) + (3.3268999999999999e-06 * fTemp19)))) - ((1.12209e-05 * fTemp17) + ((6.3924199999999994e-05 * fTemp20) + (2.7866699999999999e-05 * fTemp22))))) + (fConst5 * (0.0 - ((fConst146 * fRec1855[1]) + (fConst145 * fRec1852[1]))))));
			fRec1857[0] = (fRec1857[1] + fTemp411);
			fRec1855[0] = fRec1857[0];
			double fRec1856 = fTemp411;
			fRec1854[0] = (fRec1855[0] + fRec1854[1]);
			fRec1852[0] = fRec1854[0];
			double fRec1853 = fRec1856;
			fRec1851[0] = (fTemp410 + (fRec1853 + fRec1851[1]));
			fRec1849[0] = fRec1851[0];
			double fRec1850 = (fRec1853 + fTemp410);
			fRec1848[0] = (fRec1849[0] + fRec1848[1]);
			fRec1846[0] = fRec1848[0];
			double fRec1847 = fRec1850;
			double fTemp412 = (fConst147 * ((((1.9657000000000001e-06 * fTemp56) + (0.0304481074 * fTemp57)) - (8.5176999999999998e-06 * fTemp58)) - (fConst148 * fRec1858[1])));
			fRec1860[0] = (fRec1860[1] + fTemp412);
			fRec1858[0] = fRec1860[0];
			double fRec1859 = fTemp412;
			double fTemp413 = (fConst150 * (0.0 - ((fConst152 * fRec1864[1]) + (fConst151 * fRec1861[1]))));
			double fTemp414 = (fConst154 * (0.0 - ((fConst156 * fRec1870[1]) + (fConst155 * fRec1867[1]))));
			double fTemp415 = (fConst157 * ((fConst5 * (0.0 - ((fConst159 * fRec1876[1]) + (fConst158 * fRec1873[1])))) + (fConst160 * (((1.98308e-05 * fTemp33) + ((1.0190000000000001e-07 * fTemp34) + ((((((3.0006999999999999e-06 * fTemp36) + (9.4677999999999994e-06 * fTemp37)) + (3.5589300000000002e-05 * fTemp27)) + (0.099291706800000004 * fTemp28)) + (1.34191e-05 * fTemp31)) + (2.6000000000000001e-09 * fTemp38)))) - ((4.0000000000000002e-09 * fTemp35) + ((0.00024832419999999998 * fTemp32) + (((9.8078099999999999e-05 * fTemp29) + (3.0507000000000001e-05 * fTemp30)) + (1.2499999999999999e-08 * fTemp39))))))));
			fRec1878[0] = (fRec1878[1] + fTemp415);
			fRec1876[0] = fRec1878[0];
			double fRec1877 = fTemp415;
			fRec1875[0] = (fRec1876[0] + fRec1875[1]);
			fRec1873[0] = fRec1875[0];
			double fRec1874 = fRec1877;
			fRec1872[0] = (fTemp414 + (fRec1874 + fRec1872[1]));
			fRec1870[0] = fRec1872[0];
			double fRec1871 = (fRec1874 + fTemp414);
			fRec1869[0] = (fRec1870[0] + fRec1869[1]);
			fRec1867[0] = fRec1869[0];
			double fRec1868 = fRec1871;
			fRec1866[0] = (fTemp413 + (fRec1868 + fRec1866[1]));
			fRec1864[0] = fRec1866[0];
			double fRec1865 = (fRec1868 + fTemp413);
			fRec1863[0] = (fRec1864[0] + fRec1863[1]);
			fRec1861[0] = fRec1863[0];
			double fRec1862 = fRec1865;
			double fTemp416 = (fConst161 * (((((1.1512000000000001e-06 * fTemp50) + (5.6354999999999997e-06 * fTemp51)) + (0.049362916700000002 * fTemp54)) - ((2.3371799999999999e-05 * fTemp52) + (1.7517999999999999e-06 * fTemp53))) + (fConst5 * (0.0 - ((fConst163 * fRec1882[1]) + (fConst162 * fRec1879[1]))))));
			fRec1884[0] = (fRec1884[1] + fTemp416);
			fRec1882[0] = fRec1884[0];
			double fRec1883 = fTemp416;
			fRec1881[0] = (fRec1882[0] + fRec1881[1]);
			fRec1879[0] = fRec1881[0];
			double fRec1880 = fRec1883;
			double fTemp417 = (fConst164 * ((fConst5 * (0.0 - ((fConst166 * fRec1891[1]) + (fConst165 * fRec1888[1])))) + (fConst168 * (((0.066280089799999997 * fTemp44) + ((6.3099999999999997e-07 * fTemp41) + ((1.10318e-05 * fTemp46) + ((3.4688999999999999e-06 * fTemp42) + (1.0543e-06 * fTemp47))))) - ((4.2822599999999999e-05 * fTemp45) + (5.2900000000000002e-06 * fTemp43))))));
			fRec1893[0] = (fRec1893[1] + fTemp417);
			fRec1891[0] = fRec1893[0];
			double fRec1892 = fTemp417;
			fRec1890[0] = (fRec1891[0] + fRec1890[1]);
			fRec1888[0] = fRec1890[0];
			double fRec1889 = fRec1892;
			double fTemp418 = (fConst169 * fRec1885[1]);
			fRec1887[0] = ((fRec1889 + fRec1887[1]) - fTemp418);
			fRec1885[0] = fRec1887[0];
			double fRec1886 = (fRec1889 - fTemp418);
			output28[i] = FAUSTFLOAT((fRec0[0] * (((2.1174399999999998e-05 * fTemp10) + ((2.9040000000000001e-07 * fTemp76) + ((0.1032496351 * fTemp79) + ((4.5362399999999998e-05 * fTemp12) + ((2.7949600000000001e-05 * fTemp74) + ((1.62694e-05 * fTemp80) + (((0.0102900397 * fTemp13) + (fRec1832 + (fRec1847 + (fRec1859 + (fRec1862 + (fRec1880 + fRec1886)))))) + (6.2856999999999998e-06 * fTemp81)))))))) - ((4.3121899999999998e-05 * fTemp7) + ((4.8900000000000001e-08 * fTemp75) + ((3.4399999999999997e-08 * fTemp8) + ((0.00051997559999999998 * fTemp9) + ((1.51e-08 * fTemp77) + ((8.0000000000000003e-10 * fTemp78) + ((0.00010535959999999999 * fTemp11) + (2.1299999999999999e-08 * fTemp82)))))))))));
			double fTemp419 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec1900[1]) + (fConst26 * fRec1897[1])))) + (fConst25 * (((0.042909408500000003 * fTemp44) + ((0.1163306727 * fTemp41) + (0.036740617500000003 * fTemp47))) - ((((0.069419295000000006 * fTemp42) + (0.0087417167000000007 * fTemp46)) + (0.019479602499999998 * fTemp45)) + (0.061811414699999997 * fTemp43))))));
			fRec1902[0] = (fRec1902[1] + fTemp419);
			fRec1900[0] = fRec1902[0];
			double fRec1901 = fTemp419;
			fRec1899[0] = (fRec1900[0] + fRec1899[1]);
			fRec1897[0] = fRec1899[0];
			double fRec1898 = fRec1901;
			double fTemp420 = (fConst28 * fRec1894[1]);
			fRec1896[0] = ((fRec1898 + fRec1896[1]) - fTemp420);
			fRec1894[0] = fRec1896[0];
			double fRec1895 = (fRec1898 - fTemp420);
			double fTemp421 = (fConst8 * (0.0 - ((fConst10 * fRec1906[1]) + (fConst9 * fRec1903[1]))));
			double fTemp422 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec1912[1]) + (fConst6 * fRec1909[1])))) + (fConst4 * (((0.0098920378999999992 * fTemp16) + (((0.12432768650000001 * fTemp14) + (0.017399337500000001 * fTemp21)) + (0.038786109200000002 * fTemp20))) - ((0.0036228926000000002 * fTemp17) + ((0.0040866358000000002 * fTemp18) + ((0.030124976299999998 * fTemp19) + ((0.095389984400000002 * fTemp15) + (0.014428450299999999 * fTemp22)))))))));
			fRec1914[0] = (fRec1914[1] + fTemp422);
			fRec1912[0] = fRec1914[0];
			double fRec1913 = fTemp422;
			fRec1911[0] = (fRec1912[0] + fRec1911[1]);
			fRec1909[0] = fRec1911[0];
			double fRec1910 = fRec1913;
			fRec1908[0] = (fTemp421 + (fRec1910 + fRec1908[1]));
			fRec1906[0] = fRec1908[0];
			double fRec1907 = (fRec1910 + fTemp421);
			fRec1905[0] = (fRec1906[0] + fRec1905[1]);
			fRec1903[0] = fRec1905[0];
			double fRec1904 = fRec1907;
			double fTemp423 = (fConst32 * ((((0.035999881999999997 * fTemp56) + (0.080253251400000003 * fTemp58)) - (0.035996358800000003 * fTemp57)) - (fConst33 * fRec1915[1])));
			fRec1917[0] = (fRec1917[1] + fTemp423);
			fRec1915[0] = fRec1917[0];
			double fRec1916 = fTemp423;
			double fTemp424 = (fConst12 * (0.0 - ((fConst14 * fRec1921[1]) + (fConst13 * fRec1918[1]))));
			double fTemp425 = (fConst16 * (0.0 - ((fConst18 * fRec1927[1]) + (fConst17 * fRec1924[1]))));
			double fTemp426 = (fConst19 * ((fConst22 * (((0.019414708100000001 * fTemp33) + ((0.064597736099999997 * fTemp35) + (((((0.012059637999999999 * fTemp36) + (0.0113960112 * fTemp37)) + (0.017250956800000002 * fTemp30)) + (0.0035712998999999999 * fTemp31)) + (0.048106305799999999 * fTemp38)))) - ((0.080795693299999999 * fTemp34) + ((0.0013704416 * fTemp32) + ((((0.010799613 * fTemp27) + (0.0152405943 * fTemp28)) + (0.024036451300000001 * fTemp29)) + (0.091830558500000006 * fTemp39)))))) + (fConst5 * (0.0 - ((fConst21 * fRec1933[1]) + (fConst20 * fRec1930[1]))))));
			fRec1935[0] = (fRec1935[1] + fTemp426);
			fRec1933[0] = fRec1935[0];
			double fRec1934 = fTemp426;
			fRec1932[0] = (fRec1933[0] + fRec1932[1]);
			fRec1930[0] = fRec1932[0];
			double fRec1931 = fRec1934;
			fRec1929[0] = (fTemp425 + (fRec1931 + fRec1929[1]));
			fRec1927[0] = fRec1929[0];
			double fRec1928 = (fRec1931 + fTemp425);
			fRec1926[0] = (fRec1927[0] + fRec1926[1]);
			fRec1924[0] = fRec1926[0];
			double fRec1925 = fRec1928;
			fRec1923[0] = (fTemp424 + (fRec1925 + fRec1923[1]));
			fRec1921[0] = fRec1923[0];
			double fRec1922 = (fRec1925 + fTemp424);
			fRec1920[0] = (fRec1921[0] + fRec1920[1]);
			fRec1918[0] = fRec1920[0];
			double fRec1919 = fRec1922;
			double fTemp427 = (fConst29 * ((((0.082452155599999993 * fTemp50) + (0.073415326899999994 * fTemp53)) - (((0.031637392100000002 * fTemp51) + (0.031409640699999998 * fTemp54)) + (0.070528638099999999 * fTemp52))) + (fConst5 * (0.0 - ((fConst31 * fRec1939[1]) + (fConst30 * fRec1936[1]))))));
			fRec1941[0] = (fRec1941[1] + fTemp427);
			fRec1939[0] = fRec1941[0];
			double fRec1940 = fTemp427;
			fRec1938[0] = (fRec1939[0] + fRec1938[1]);
			fRec1936[0] = fRec1938[0];
			double fRec1937 = fRec1940;
			double fTemp428 = (fConst35 * (0.0 - ((fConst37 * fRec1948[1]) + (fConst36 * fRec1945[1]))));
			double fTemp429 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec1954[1]) + (fConst39 * fRec1951[1])))) + (fConst42 * ((((0.0051383478999999996 * fTemp65) + ((0.1043784417 * fTemp66) + (((((0.0194348019 * fTemp67) + (0.0077311252000000002 * fTemp68)) + (0.0172014783 * fTemp63)) + (0.017292474299999999 * fTemp69)) + (0.0016463813 * fTemp64)))) + (0.0115334032 * fTemp70)) - (((0.099300911699999994 * fTemp61) + (0.020849784199999999 * fTemp62)) + (0.062113474299999999 * fTemp71))))));
			fRec1956[0] = (fRec1956[1] + fTemp429);
			fRec1954[0] = fRec1956[0];
			double fRec1955 = fTemp429;
			fRec1953[0] = (fRec1954[0] + fRec1953[1]);
			fRec1951[0] = fRec1953[0];
			double fRec1952 = fRec1955;
			fRec1950[0] = (fTemp428 + (fRec1952 + fRec1950[1]));
			fRec1948[0] = fRec1950[0];
			double fRec1949 = (fRec1952 + fTemp428);
			fRec1947[0] = (fRec1948[0] + fRec1947[1]);
			fRec1945[0] = fRec1947[0];
			double fRec1946 = fRec1949;
			double fTemp430 = (fConst43 * fRec1942[1]);
			fRec1944[0] = ((fRec1946 + fRec1944[1]) - fTemp430);
			fRec1942[0] = fRec1944[0];
			double fRec1943 = (fRec1946 - fTemp430);
			fVec28[(IOTA & 1023)] = (((0.068356671699999996 * fTemp75) + ((0.0097006761999999993 * fTemp10) + ((0.0132745196 * fTemp76) + ((0.018937055500000001 * fTemp78) + ((0.0159788443 * fTemp79) + ((0.030814817500000001 * fTemp80) + (((0.033985482099999999 * fTemp13) + (fRec1895 + (fRec1904 + (fRec1916 + (fRec1919 + (fRec1937 + fRec1943)))))) + (0.00057242790000000001 * fTemp81)))))))) - ((0.017390723300000001 * fTemp7) + ((0.0078679260000000008 * fTemp8) + ((0.0001133044 * fTemp9) + ((0.048035338499999997 * fTemp77) + ((0.017913499999999999 * fTemp11) + ((0.0080436224000000004 * fTemp12) + ((0.019591159399999999 * fTemp74) + (0.0971544092 * fTemp82)))))))));
			output29[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec28[((IOTA - iConst44) & 1023)])));
			double fTemp431 = (fConst12 * (0.0 - ((fConst14 * fRec1960[1]) + (fConst13 * fRec1957[1]))));
			double fTemp432 = (fConst16 * (0.0 - ((fConst18 * fRec1966[1]) + (fConst17 * fRec1963[1]))));
			double fTemp433 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec1972[1]) + (fConst20 * fRec1969[1])))) + (fConst22 * (((0.001366815 * fTemp33) + ((0.016787485000000001 * fTemp35) + ((0.011155080600000001 * fTemp32) + (((((0.0011044182999999999 * fTemp36) + (0.00076984760000000003 * fTemp37)) + (0.026881648099999999 * fTemp30)) + (0.011219806400000001 * fTemp31)) + (0.1117978962 * fTemp39))))) - ((0.0115064005 * fTemp34) + ((((0.0006280201 * fTemp27) + (0.015934495699999999 * fTemp28)) + (0.025454674300000001 * fTemp29)) + (0.092819125500000002 * fTemp38)))))));
			fRec1974[0] = (fRec1974[1] + fTemp433);
			fRec1972[0] = fRec1974[0];
			double fRec1973 = fTemp433;
			fRec1971[0] = (fRec1972[0] + fRec1971[1]);
			fRec1969[0] = fRec1971[0];
			double fRec1970 = fRec1973;
			fRec1968[0] = (fTemp432 + (fRec1970 + fRec1968[1]));
			fRec1966[0] = fRec1968[0];
			double fRec1967 = (fRec1970 + fTemp432);
			fRec1965[0] = (fRec1966[0] + fRec1965[1]);
			fRec1963[0] = fRec1965[0];
			double fRec1964 = fRec1967;
			fRec1962[0] = (fTemp431 + (fRec1964 + fRec1962[1]));
			fRec1960[0] = fRec1962[0];
			double fRec1961 = (fRec1964 + fTemp431);
			fRec1959[0] = (fRec1960[0] + fRec1959[1]);
			fRec1957[0] = fRec1959[0];
			double fRec1958 = fRec1961;
			double fTemp434 = (fConst8 * (0.0 - ((fConst10 * fRec1978[1]) + (fConst9 * fRec1975[1]))));
			double fTemp435 = (fConst2 * ((fConst4 * (((0.0106104272 * fTemp16) + ((0.041893931699999998 * fTemp20) + ((0.0124847616 * fTemp14) + ((0.0010142829999999999 * fTemp21) + (0.12544627250000001 * fTemp22))))) - ((0.0064985249000000002 * fTemp17) + ((0.00030961859999999999 * fTemp18) + ((0.0073632157999999996 * fTemp15) + (0.0991315745 * fTemp19)))))) + (fConst5 * (0.0 - ((fConst7 * fRec1984[1]) + (fConst6 * fRec1981[1]))))));
			fRec1986[0] = (fRec1986[1] + fTemp435);
			fRec1984[0] = fRec1986[0];
			double fRec1985 = fTemp435;
			fRec1983[0] = (fRec1984[0] + fRec1983[1]);
			fRec1981[0] = fRec1983[0];
			double fRec1982 = fRec1985;
			fRec1980[0] = (fTemp434 + (fRec1982 + fRec1980[1]));
			fRec1978[0] = fRec1980[0];
			double fRec1979 = (fRec1982 + fTemp434);
			fRec1977[0] = (fRec1978[0] + fRec1977[1]);
			fRec1975[0] = fRec1977[0];
			double fRec1976 = fRec1979;
			double fTemp436 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec1993[1]) + (fConst26 * fRec1990[1])))) + (fConst25 * (((0.042524342399999998 * fTemp44) + ((0.0091264992000000007 * fTemp41) + (0.12248743099999999 * fTemp47))) - ((((0.0045699534 * fTemp42) + (0.00054194729999999997 * fTemp46)) + (0.022290322000000001 * fTemp45)) + (0.092254582399999993 * fTemp43))))));
			fRec1995[0] = (fRec1995[1] + fTemp436);
			fRec1993[0] = fRec1995[0];
			double fRec1994 = fTemp436;
			fRec1992[0] = (fRec1993[0] + fRec1992[1]);
			fRec1990[0] = fRec1992[0];
			double fRec1991 = fRec1994;
			double fTemp437 = (fConst28 * fRec1987[1]);
			fRec1989[0] = ((fRec1991 + fRec1989[1]) - fTemp437);
			fRec1987[0] = fRec1989[0];
			double fRec1988 = (fRec1991 - fTemp437);
			double fTemp438 = (fConst35 * (0.0 - ((fConst37 * fRec2002[1]) + (fConst36 * fRec1999[1]))));
			double fTemp439 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec2008[1]) + (fConst39 * fRec2005[1])))) + (fConst42 * ((((0.00033106159999999999 * fTemp65) + ((0.015141551499999999 * fTemp66) + (((((0.0012093478 * fTemp67) + (0.00050846590000000003 * fTemp68)) + (0.019852544699999999 * fTemp63)) + (0.0253248503 * fTemp69)) + (0.0043465337000000003 * fTemp64)))) + (0.12140736219999999 * fTemp71)) - (((0.0097965814000000005 * fTemp61) + (0.020328344700000001 * fTemp62)) + (0.098881825699999995 * fTemp70))))));
			fRec2010[0] = (fRec2010[1] + fTemp439);
			fRec2008[0] = fRec2010[0];
			double fRec2009 = fTemp439;
			fRec2007[0] = (fRec2008[0] + fRec2007[1]);
			fRec2005[0] = fRec2007[0];
			double fRec2006 = fRec2009;
			fRec2004[0] = (fTemp438 + (fRec2006 + fRec2004[1]));
			fRec2002[0] = fRec2004[0];
			double fRec2003 = (fRec2006 + fTemp438);
			fRec2001[0] = (fRec2002[0] + fRec2001[1]);
			fRec1999[0] = fRec2001[0];
			double fRec2000 = fRec2003;
			double fTemp440 = (fConst43 * fRec1996[1]);
			fRec1998[0] = ((fRec2000 + fRec1998[1]) - fTemp440);
			fRec1996[0] = fRec1998[0];
			double fRec1997 = (fRec2000 - fTemp440);
			double fTemp441 = (fConst29 * ((((0.0055052596000000004 * fTemp50) + (0.110944865 * fTemp53)) - (((0.0019055224999999999 * fTemp51) + (0.031932683199999999 * fTemp54)) + (0.076810528899999994 * fTemp52))) + (fConst5 * (0.0 - ((fConst31 * fRec2014[1]) + (fConst30 * fRec2011[1]))))));
			fRec2016[0] = (fRec2016[1] + fTemp441);
			fRec2014[0] = fRec2016[0];
			double fRec2015 = fTemp441;
			fRec2013[0] = (fRec2014[0] + fRec2013[1]);
			fRec2011[0] = fRec2013[0];
			double fRec2012 = fRec2015;
			double fTemp442 = (fConst32 * ((((0.0021928950999999999 * fTemp56) + (0.088396874700000003 * fTemp58)) - (0.035796514500000001 * fTemp57)) - (fConst33 * fRec2017[1])));
			fRec2019[0] = (fRec2019[1] + fTemp442);
			fRec2017[0] = fRec2019[0];
			double fRec2018 = fTemp442;
			fVec29[(IOTA & 1023)] = (((0.0145904594 * fTemp8) + ((0.033061419600000003 * fTemp10) + ((0.0017959796000000001 * fTemp76) + ((0.017251449700000001 * fTemp78) + ((0.0152307689 * fTemp79) + ((0.0025122276999999999 * fTemp80) + ((0.034128871200000001 * fTemp13) + (fRec1958 + (fRec1976 + (fRec1988 + (fRec1997 + (fRec2012 + (fRec2018 + (0.098054065699999998 * fTemp82)))))))))))))) - ((0.025189474100000001 * fTemp7) + ((((0.012262187500000001 * fTemp77) + ((((8.7919199999999997e-05 * fTemp81) + (0.0012435262000000001 * fTemp74)) + (0.00050864569999999997 * fTemp12)) + (0.020599121599999999 * fTemp11))) + (0.0001062949 * fTemp9)) + (0.0823005396 * fTemp75))));
			output30[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec29[((IOTA - iConst44) & 1023)])));
			double fTemp443 = (fConst12 * (0.0 - ((fConst14 * fRec2023[1]) + (fConst13 * fRec2020[1]))));
			double fTemp444 = (fConst16 * (0.0 - ((fConst18 * fRec2029[1]) + (fConst17 * fRec2026[1]))));
			double fTemp445 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec2035[1]) + (fConst20 * fRec2032[1])))) + (fConst22 * (((0.090204270000000003 * fTemp34) + ((0.0010722092 * fTemp32) + ((((0.0094996847000000002 * fTemp27) + (0.0192763725 * fTemp30)) + (0.0052135712000000002 * fTemp31)) + (0.0262697273 * fTemp38)))) - ((0.017698473900000001 * fTemp33) + ((0.089135363300000006 * fTemp35) + (((((0.0119842974 * fTemp36) + (0.010520877 * fTemp37)) + (0.015316311399999999 * fTemp28)) + (0.0244291487 * fTemp29)) + (0.068461857599999995 * fTemp39))))))));
			fRec2037[0] = (fRec2037[1] + fTemp445);
			fRec2035[0] = fRec2037[0];
			double fRec2036 = fTemp445;
			fRec2034[0] = (fRec2035[0] + fRec2034[1]);
			fRec2032[0] = fRec2034[0];
			double fRec2033 = fRec2036;
			fRec2031[0] = (fTemp444 + (fRec2033 + fRec2031[1]));
			fRec2029[0] = fRec2031[0];
			double fRec2030 = (fRec2033 + fTemp444);
			fRec2028[0] = (fRec2029[0] + fRec2028[1]);
			fRec2026[0] = fRec2028[0];
			double fRec2027 = fRec2030;
			fRec2025[0] = (fTemp443 + (fRec2027 + fRec2025[1]));
			fRec2023[0] = fRec2025[0];
			double fRec2024 = (fRec2027 + fTemp443);
			fRec2022[0] = (fRec2023[0] + fRec2022[1]);
			fRec2020[0] = fRec2022[0];
			double fRec2021 = fRec2024;
			double fTemp446 = (fConst29 * ((((0.027981907699999999 * fTemp51) + (0.081420015100000007 * fTemp53)) - (((0.074619689099999997 * fTemp50) + (0.031413526499999997 * fTemp54)) + (0.0719548619 * fTemp52))) + (fConst5 * (0.0 - ((fConst31 * fRec2041[1]) + (fConst30 * fRec2038[1]))))));
			fRec2043[0] = (fRec2043[1] + fTemp446);
			fRec2041[0] = fRec2043[0];
			double fRec2042 = fTemp446;
			fRec2040[0] = (fRec2041[0] + fRec2040[1]);
			fRec2038[0] = fRec2040[0];
			double fRec2039 = fRec2042;
			double fTemp447 = (fConst32 * (((0.081998725800000005 * fTemp58) - ((0.031891335799999997 * fTemp56) + (0.035974382399999998 * fTemp57))) - (fConst33 * fRec2044[1])));
			fRec2046[0] = (fRec2046[1] + fTemp447);
			fRec2044[0] = fRec2046[0];
			double fRec2045 = fTemp447;
			double fTemp448 = (fConst35 * (0.0 - ((fConst37 * fRec2053[1]) + (fConst36 * fRec2050[1]))));
			double fTemp449 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec2059[1]) + (fConst39 * fRec2056[1])))) + (fConst42 * (((0.0994621698 * fTemp61) + (((0.017771121399999999 * fTemp63) + (0.0190326826 * fTemp69)) + (0.0023477251999999998 * fTemp64))) - ((((0.0047302192 * fTemp65) + ((0.11670116010000001 * fTemp66) + (((0.017415278100000001 * fTemp67) + (0.0069230990000000003 * fTemp68)) + (0.020754722100000001 * fTemp62)))) + (0.0087177750000000005 * fTemp70)) + (0.034054972699999998 * fTemp71))))));
			fRec2061[0] = (fRec2061[1] + fTemp449);
			fRec2059[0] = fRec2061[0];
			double fRec2060 = fTemp449;
			fRec2058[0] = (fRec2059[0] + fRec2058[1]);
			fRec2056[0] = fRec2058[0];
			double fRec2057 = fRec2060;
			fRec2055[0] = (fTemp448 + (fRec2057 + fRec2055[1]));
			fRec2053[0] = fRec2055[0];
			double fRec2054 = (fRec2057 + fTemp448);
			fRec2052[0] = (fRec2053[0] + fRec2052[1]);
			fRec2050[0] = fRec2052[0];
			double fRec2051 = fRec2054;
			double fTemp450 = (fConst43 * fRec2047[1]);
			fRec2049[0] = ((fRec2051 + fRec2049[1]) - fTemp450);
			fRec2047[0] = fRec2049[0];
			double fRec2048 = (fRec2051 - fTemp450);
			double fTemp451 = (fConst23 * ((fConst25 * (((0.042753812199999998 * fTemp44) + ((0.0077611802000000004 * fTemp46) + ((0.062703040500000001 * fTemp42) + (0.053970824100000002 * fTemp47)))) - ((0.1094785314 * fTemp41) + ((0.0199568613 * fTemp45) + (0.068433135699999995 * fTemp43))))) + (fConst5 * (0.0 - ((fConst27 * fRec2068[1]) + (fConst26 * fRec2065[1]))))));
			fRec2070[0] = (fRec2070[1] + fTemp451);
			fRec2068[0] = fRec2070[0];
			double fRec2069 = fTemp451;
			fRec2067[0] = (fRec2068[0] + fRec2067[1]);
			fRec2065[0] = fRec2067[0];
			double fRec2066 = fRec2069;
			double fTemp452 = (fConst28 * fRec2062[1]);
			fRec2064[0] = ((fRec2066 + fRec2064[1]) - fTemp452);
			fRec2062[0] = fRec2064[0];
			double fRec2063 = (fRec2066 - fTemp452);
			double fTemp453 = (fConst8 * (0.0 - ((fConst10 * fRec2074[1]) + (fConst9 * fRec2071[1]))));
			double fTemp454 = (fConst2 * ((fConst4 * (((0.0100336568 * fTemp16) + ((0.0037614394999999998 * fTemp18) + ((0.039410912899999997 * fTemp20) + ((0.089584713400000002 * fTemp15) + (0.0108904168 * fTemp22))))) - ((0.0040979498999999999 * fTemp17) + (((0.1247754448 * fTemp14) + (0.015316099999999999 * fTemp21)) + (0.044188670700000002 * fTemp19))))) + (fConst5 * (0.0 - ((fConst7 * fRec2080[1]) + (fConst6 * fRec2077[1]))))));
			fRec2082[0] = (fRec2082[1] + fTemp454);
			fRec2080[0] = fRec2082[0];
			double fRec2081 = fTemp454;
			fRec2079[0] = (fRec2080[0] + fRec2079[1]);
			fRec2077[0] = fRec2079[0];
			double fRec2078 = fRec2081;
			fRec2076[0] = (fTemp453 + (fRec2078 + fRec2076[1]));
			fRec2074[0] = fRec2076[0];
			double fRec2075 = (fRec2078 + fTemp453);
			fRec2073[0] = (fRec2074[0] + fRec2073[1]);
			fRec2071[0] = fRec2073[0];
			double fRec2072 = fRec2075;
			fVec30[(IOTA & 1023)] = (((0.050829459100000002 * fTemp75) + ((5.9188000000000003e-05 * fTemp9) + ((0.0143370098 * fTemp10) + ((0.066283830399999993 * fTemp77) + ((0.015785788200000001 * fTemp79) + ((0.0071566273000000001 * fTemp12) + (((0.033996610300000001 * fTemp13) + (fRec2021 + (fRec2039 + (fRec2045 + (fRec2048 + (fRec2063 + fRec2072)))))) + (0.0175980588 * fTemp74)))))))) - ((0.019195728799999999 * fTemp7) + ((0.0042659422000000001 * fTemp8) + ((0.0147517134 * fTemp76) + ((0.051352267200000003 * fTemp78) + ((0.018386613 * fTemp11) + ((0.0291496542 * fTemp80) + ((0.00040081930000000001 * fTemp81) + (0.084756505699999998 * fTemp82)))))))));
			output31[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec30[((IOTA - iConst44) & 1023)])));
			double fTemp455 = (fConst35 * (0.0 - ((fConst37 * fRec2089[1]) + (fConst36 * fRec2086[1]))));
			double fTemp456 = (fConst38 * ((fConst42 * ((((0.0064789288000000004 * fTemp61) + ((0.079154066699999998 * fTemp66) + ((0.0142857448 * fTemp63) + (0.00087525039999999997 * fTemp69)))) + (0.099646989599999999 * fTemp70)) - (((0.0032392032 * fTemp65) + ((((0.0256005903 * fTemp67) + (0.013814160299999999 * fTemp68)) + (0.0205349703 * fTemp62)) + (0.0031234211 * fTemp64))) + (0.093528804699999996 * fTemp71)))) + (fConst5 * (0.0 - ((fConst40 * fRec2095[1]) + (fConst39 * fRec2092[1]))))));
			fRec2097[0] = (fRec2097[1] + fTemp456);
			fRec2095[0] = fRec2097[0];
			double fRec2096 = fTemp456;
			fRec2094[0] = (fRec2095[0] + fRec2094[1]);
			fRec2092[0] = fRec2094[0];
			double fRec2093 = fRec2096;
			fRec2091[0] = (fTemp455 + (fRec2093 + fRec2091[1]));
			fRec2089[0] = fRec2091[0];
			double fRec2090 = (fRec2093 + fTemp455);
			fRec2088[0] = (fRec2089[0] + fRec2088[1]);
			fRec2086[0] = fRec2088[0];
			double fRec2087 = fRec2090;
			double fTemp457 = (fConst43 * fRec2083[1]);
			fRec2085[0] = ((fRec2087 + fRec2085[1]) - fTemp457);
			fRec2083[0] = fRec2085[0];
			double fRec2084 = (fRec2087 - fTemp457);
			double fTemp458 = (fConst32 * (((0.063980663399999999 * fTemp58) - ((0.0619228317 * fTemp56) + (0.036098277400000003 * fTemp57))) - (fConst33 * fRec2098[1])));
			fRec2100[0] = (fRec2100[1] + fTemp458);
			fRec2098[0] = fRec2100[0];
			double fRec2099 = fTemp458;
			double fTemp459 = (fConst12 * (0.0 - ((fConst14 * fRec2104[1]) + (fConst13 * fRec2101[1]))));
			double fTemp460 = (fConst16 * (0.0 - ((fConst18 * fRec2110[1]) + (fConst17 * fRec2107[1]))));
			double fTemp461 = (fConst19 * ((fConst22 * (((0.1123494917 * fTemp35) + (((0.017903620299999999 * fTemp27) + (0.00089537890000000004 * fTemp30)) + (0.071488114199999994 * fTemp38))) - ((0.026973457900000001 * fTemp33) + ((0.060682646299999997 * fTemp34) + ((0.0113323075 * fTemp32) + ((((((0.0005798353 * fTemp36) + (0.0084821858 * fTemp37)) + (0.0159937647 * fTemp28)) + (0.018474658099999999 * fTemp29)) + (0.0076185243999999999 * fTemp31)) + (0.011290978300000001 * fTemp39))))))) + (fConst5 * (0.0 - ((fConst21 * fRec2116[1]) + (fConst20 * fRec2113[1]))))));
			fRec2118[0] = (fRec2118[1] + fTemp461);
			fRec2116[0] = fRec2118[0];
			double fRec2117 = fTemp461;
			fRec2115[0] = (fRec2116[0] + fRec2115[1]);
			fRec2113[0] = fRec2115[0];
			double fRec2114 = fRec2117;
			fRec2112[0] = (fTemp460 + (fRec2114 + fRec2112[1]));
			fRec2110[0] = fRec2112[0];
			double fRec2111 = (fRec2114 + fTemp460);
			fRec2109[0] = (fRec2110[0] + fRec2109[1]);
			fRec2107[0] = fRec2109[0];
			double fRec2108 = fRec2111;
			fRec2106[0] = (fTemp459 + (fRec2108 + fRec2106[1]));
			fRec2104[0] = fRec2106[0];
			double fRec2105 = (fRec2108 + fTemp459);
			fRec2103[0] = (fRec2104[0] + fRec2103[1]);
			fRec2101[0] = fRec2103[0];
			double fRec2102 = fRec2105;
			double fTemp462 = (fConst29 * ((((0.053900869599999998 * fTemp51) + (0.0036687244000000001 * fTemp53)) - (((0.1117141593 * fTemp50) + (0.032124069399999997 * fTemp54)) + (0.055652225899999998 * fTemp52))) + (fConst5 * (0.0 - ((fConst31 * fRec2122[1]) + (fConst30 * fRec2119[1]))))));
			fRec2124[0] = (fRec2124[1] + fTemp462);
			fRec2122[0] = fRec2124[0];
			double fRec2123 = fTemp462;
			fRec2121[0] = (fRec2122[0] + fRec2121[1]);
			fRec2119[0] = fRec2121[0];
			double fRec2120 = fRec2123;
			double fTemp463 = (fConst8 * (0.0 - ((fConst10 * fRec2128[1]) + (fConst9 * fRec2125[1]))));
			double fTemp464 = (fConst2 * ((fConst4 * (((0.010593011899999999 * fTemp16) + ((0.0064228195000000004 * fTemp18) + (((0.074101025200000004 * fTemp15) + (0.030415986200000002 * fTemp20)) + (0.067244396499999998 * fTemp19)))) - ((0.00030759299999999999 * fTemp17) + ((0.0083638167999999999 * fTemp14) + ((0.0294120236 * fTemp21) + (0.12623552690000001 * fTemp22)))))) + (fConst5 * (0.0 - ((fConst7 * fRec2134[1]) + (fConst6 * fRec2131[1]))))));
			fRec2136[0] = (fRec2136[1] + fTemp464);
			fRec2134[0] = fRec2136[0];
			double fRec2135 = fTemp464;
			fRec2133[0] = (fRec2134[0] + fRec2133[1]);
			fRec2131[0] = fRec2133[0];
			double fRec2132 = fRec2135;
			fRec2130[0] = (fTemp463 + (fRec2132 + fRec2130[1]));
			fRec2128[0] = fRec2130[0];
			double fRec2129 = (fRec2132 + fTemp463);
			fRec2127[0] = (fRec2128[0] + fRec2127[1]);
			fRec2125[0] = fRec2127[0];
			double fRec2126 = fRec2129;
			double fTemp465 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec2143[1]) + (fConst26 * fRec2140[1])))) + (fConst25 * ((((0.093035410499999999 * fTemp42) + (0.015513203 * fTemp46)) + (0.0429151797 * fTemp44)) - ((0.091502150099999999 * fTemp41) + ((0.002993529 * fTemp43) + ((0.016097762099999999 * fTemp45) + (0.082875892600000001 * fTemp47))))))));
			fRec2145[0] = (fRec2145[1] + fTemp465);
			fRec2143[0] = fRec2145[0];
			double fRec2144 = fTemp465;
			fRec2142[0] = (fRec2143[0] + fRec2142[1]);
			fRec2140[0] = fRec2142[0];
			double fRec2141 = fRec2144;
			double fTemp466 = (fConst28 * fRec2137[1]);
			fRec2139[0] = ((fRec2141 + fRec2139[1]) - fTemp466);
			fRec2137[0] = fRec2139[0];
			double fRec2138 = (fRec2141 - fTemp466);
			fVec31[(IOTA & 1023)] = (((0.0081758066999999997 * fTemp75) + ((2.5599799999999998e-05 * fTemp9) + ((0.0096907733999999999 * fTemp76) + ((0.077810763300000002 * fTemp78) + ((0.0154318296 * fTemp79) + ((0.0143825403 * fTemp12) + ((0.025473750399999998 * fTemp74) + ((0.034376846000000003 * fTemp13) + (fRec2084 + (fRec2099 + (fRec2102 + (fRec2120 + (fRec2126 + (fRec2138 + (0.061369877000000003 * fTemp82))))))))))))))) - ((0.00079413889999999999 * fTemp7) + ((((0.082748005700000002 * fTemp77) + (((4.5899799999999997e-05 * fTemp81) + (0.0246470531 * fTemp80)) + (0.014904116199999999 * fTemp11))) + (0.022323840300000002 * fTemp10)) + (0.0111670226 * fTemp8))));
			output32[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec31[((IOTA - iConst44) & 1023)])));
			double fTemp467 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec2152[1]) + (fConst26 * fRec2149[1])))) + (fConst25 * (((0.043268058800000002 * fTemp44) + ((0.043692687600000002 * fTemp41) + (((0.067590558199999998 * fTemp42) + (0.020160876000000001 * fTemp46)) + (0.064875360600000001 * fTemp43)))) - ((0.0085816519000000008 * fTemp45) + (0.115314396 * fTemp47))))));
			fRec2154[0] = (fRec2154[1] + fTemp467);
			fRec2152[0] = fRec2154[0];
			double fRec2153 = fTemp467;
			fRec2151[0] = (fRec2152[0] + fRec2151[1]);
			fRec2149[0] = fRec2151[0];
			double fRec2150 = fRec2153;
			double fTemp468 = (fConst28 * fRec2146[1]);
			fRec2148[0] = ((fRec2150 + fRec2148[1]) - fTemp468);
			fRec2146[0] = fRec2148[0];
			double fRec2147 = (fRec2150 - fTemp468);
			double fTemp469 = (fConst29 * (((0.071746467600000002 * fTemp51) - ((((0.080605835400000006 * fTemp50) + (0.031937806499999999 * fTemp54)) + (0.0305874358 * fTemp52)) + (0.077384490099999995 * fTemp53))) + (fConst5 * (0.0 - ((fConst31 * fRec2158[1]) + (fConst30 * fRec2155[1]))))));
			fRec2160[0] = (fRec2160[1] + fTemp469);
			fRec2158[0] = fRec2160[0];
			double fRec2159 = fTemp469;
			fRec2157[0] = (fRec2158[0] + fRec2157[1]);
			fRec2155[0] = fRec2157[0];
			double fRec2156 = fRec2159;
			double fTemp470 = (fConst12 * (0.0 - ((fConst14 * fRec2164[1]) + (fConst13 * fRec2161[1]))));
			double fTemp471 = (fConst16 * (0.0 - ((fConst18 * fRec2170[1]) + (fConst17 * fRec2167[1]))));
			double fTemp472 = (fConst19 * ((fConst22 * (((((0.011813919000000001 * fTemp36) + (0.0041922536999999998 * fTemp37)) + (0.02422274 * fTemp27)) + (0.084181640899999993 * fTemp39)) - ((0.019187301800000001 * fTemp33) + ((0.040383026699999998 * fTemp34) + ((0.074593818399999998 * fTemp35) + ((0.0004875484 * fTemp32) + (((((0.0156464103 * fTemp28) + (0.010348707699999999 * fTemp29)) + (0.018379761099999999 * fTemp30)) + (0.0110514645 * fTemp31)) + (0.084975391299999994 * fTemp38)))))))) + (fConst5 * (0.0 - ((fConst21 * fRec2176[1]) + (fConst20 * fRec2173[1]))))));
			fRec2178[0] = (fRec2178[1] + fTemp472);
			fRec2176[0] = fRec2178[0];
			double fRec2177 = fTemp472;
			fRec2175[0] = (fRec2176[0] + fRec2175[1]);
			fRec2173[0] = fRec2175[0];
			double fRec2174 = fRec2177;
			fRec2172[0] = (fTemp471 + (fRec2174 + fRec2172[1]));
			fRec2170[0] = fRec2172[0];
			double fRec2171 = (fRec2174 + fTemp471);
			fRec2169[0] = (fRec2170[0] + fRec2169[1]);
			fRec2167[0] = fRec2169[0];
			double fRec2168 = fRec2171;
			fRec2166[0] = (fTemp470 + (fRec2168 + fRec2166[1]));
			fRec2164[0] = fRec2166[0];
			double fRec2165 = (fRec2168 + fTemp470);
			fRec2163[0] = (fRec2164[0] + fRec2163[1]);
			fRec2161[0] = fRec2163[0];
			double fRec2162 = fRec2165;
			double fTemp473 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec2191[1]) + (fConst39 * fRec2188[1])))) + (fConst42 * (((((0.0017809975 * fTemp65) + ((0.052391209500000001 * fTemp66) + (0.0076276114000000004 * fTemp63))) + (0.0040958035 * fTemp70)) + (0.1103619894 * fTemp71)) - ((0.1002626039 * fTemp61) + (((((0.018795755000000001 * fTemp67) + (0.017844112299999999 * fTemp68)) + (0.020924656 * fTemp62)) + (0.0180591984 * fTemp69)) + (0.0047252756999999999 * fTemp64)))))));
			fRec2193[0] = (fRec2193[1] + fTemp473);
			fRec2191[0] = fRec2193[0];
			double fRec2192 = fTemp473;
			fRec2190[0] = (fRec2191[0] + fRec2190[1]);
			fRec2188[0] = fRec2190[0];
			double fRec2189 = fRec2192;
			double fTemp474 = (fRec2189 + (fConst35 * (0.0 - ((fConst37 * fRec2185[1]) + (fConst36 * fRec2182[1])))));
			fRec2187[0] = (fRec2187[1] + fTemp474);
			fRec2185[0] = fRec2187[0];
			double fRec2186 = fTemp474;
			fRec2184[0] = (fRec2185[0] + fRec2184[1]);
			fRec2182[0] = fRec2184[0];
			double fRec2183 = fRec2186;
			double fTemp475 = (fConst43 * fRec2179[1]);
			fRec2181[0] = ((fRec2183 + fRec2181[1]) - fTemp475);
			fRec2179[0] = fRec2181[0];
			double fRec2180 = (fRec2183 - fTemp475);
			double fTemp476 = (fConst32 * (((0.034927997000000002 * fTemp58) - ((0.081945032700000003 * fTemp56) + (0.0363389296 * fTemp57))) - (fConst33 * fRec2194[1])));
			fRec2196[0] = (fRec2196[1] + fTemp476);
			fRec2194[0] = fRec2196[0];
			double fRec2195 = fTemp476;
			double fTemp477 = (fConst8 * (0.0 - ((fConst10 * fRec2200[1]) + (fConst9 * fRec2197[1]))));
			double fTemp478 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec2206[1]) + (fConst6 * fRec2203[1])))) + (fConst4 * (((0.0040842187000000004 * fTemp17) + ((0.010253254 * fTemp16) + ((0.0042390850000000001 * fTemp18) + (((0.12615300739999999 * fTemp14) + (0.016766455499999999 * fTemp20)) + (0.094130766800000001 * fTemp19))))) - ((0.0356487661 * fTemp15) + ((0.039368440900000003 * fTemp21) + (0.0051209491000000001 * fTemp22)))))));
			fRec2208[0] = (fRec2208[1] + fTemp478);
			fRec2206[0] = fRec2208[0];
			double fRec2207 = fTemp478;
			fRec2205[0] = (fRec2206[0] + fRec2205[1]);
			fRec2203[0] = fRec2205[0];
			double fRec2204 = fRec2207;
			fRec2202[0] = (fTemp477 + (fRec2204 + fRec2202[1]));
			fRec2200[0] = fRec2202[0];
			double fRec2201 = (fRec2204 + fTemp477);
			fRec2199[0] = (fRec2200[0] + fRec2199[1]);
			fRec2197[0] = fRec2199[0];
			double fRec2198 = fRec2201;
			fVec32[(IOTA & 1023)] = (((0.018075039000000001 * fTemp7) + ((0.013652628599999999 * fTemp8) + ((0.0064922581000000004 * fTemp76) + ((0.055160309099999999 * fTemp77) + ((0.0158997767 * fTemp79) + ((0.018594808300000001 * fTemp12) + ((0.018870956500000001 * fTemp74) + ((0.011620341399999999 * fTemp80) + (((0.034416953399999999 * fTemp13) + (fRec2147 + (fRec2156 + (fRec2162 + (fRec2180 + (fRec2195 + fRec2198)))))) + (0.00035780060000000001 * fTemp81)))))))))) - ((0.062334581600000001 * fTemp75) + ((1.8729800000000001e-05 * fTemp9) + ((0.0307752146 * fTemp10) + ((0.093528867500000001 * fTemp78) + ((0.0079119212999999994 * fTemp11) + (0.031289230500000001 * fTemp82)))))));
			output33[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec32[((IOTA - iConst44) & 1023)])));
			double fTemp479 = (fConst12 * (0.0 - ((fConst14 * fRec2212[1]) + (fConst13 * fRec2209[1]))));
			double fTemp480 = (fConst16 * (0.0 - ((fConst18 * fRec2218[1]) + (fConst17 * fRec2215[1]))));
			double fTemp481 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec2224[1]) + (fConst20 * fRec2221[1])))) + (fConst22 * (((0.094080680799999997 * fTemp34) + ((0.0116244435 * fTemp32) + (((((0.011575153600000001 * fTemp37) + (0.026277799399999999 * fTemp27)) + (3.9657299999999997e-05 * fTemp29)) + (8.9007999999999999e-05 * fTemp31)) + (5.8328200000000002e-05 * fTemp38)))) - ((5.8329799999999998e-05 * fTemp33) + ((0.00034647060000000002 * fTemp35) + ((((0.00011588500000000001 * fTemp36) + (0.015962728999999998 * fTemp28)) + (0.027089452199999999 * fTemp30)) + (0.11266776890000001 * fTemp39))))))));
			fRec2226[0] = (fRec2226[1] + fTemp481);
			fRec2224[0] = fRec2226[0];
			double fRec2225 = fTemp481;
			fRec2223[0] = (fRec2224[0] + fRec2223[1]);
			fRec2221[0] = fRec2223[0];
			double fRec2222 = fRec2225;
			fRec2220[0] = (fTemp480 + (fRec2222 + fRec2220[1]));
			fRec2218[0] = fRec2220[0];
			double fRec2219 = (fRec2222 + fTemp480);
			fRec2217[0] = (fRec2218[0] + fRec2217[1]);
			fRec2215[0] = fRec2217[0];
			double fRec2216 = fRec2219;
			fRec2214[0] = (fTemp479 + (fRec2216 + fRec2214[1]));
			fRec2212[0] = fRec2214[0];
			double fRec2213 = (fRec2216 + fTemp479);
			fRec2211[0] = (fRec2212[0] + fRec2211[1]);
			fRec2209[0] = fRec2211[0];
			double fRec2210 = fRec2213;
			double fTemp482 = (fConst35 * (0.0 - ((fConst37 * fRec2233[1]) + (fConst36 * fRec2230[1]))));
			double fTemp483 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec2239[1]) + (fConst39 * fRec2236[1])))) + (fConst42 * ((((0.0048199089000000002 * fTemp65) + ((5.7076400000000001e-05 * fTemp61) + (((5.0091299999999999e-05 * fTemp67) + (2.46889e-05 * fTemp63)) + (8.8036799999999997e-05 * fTemp64)))) + (0.0002527901 * fTemp71)) - (((0.1226840517 * fTemp66) + (((0.019916982499999999 * fTemp68) + (0.020893629 * fTemp62)) + (0.025910927800000001 * fTemp69))) + (0.1005346163 * fTemp70))))));
			fRec2241[0] = (fRec2241[1] + fTemp483);
			fRec2239[0] = fRec2241[0];
			double fRec2240 = fTemp483;
			fRec2238[0] = (fRec2239[0] + fRec2238[1]);
			fRec2236[0] = fRec2238[0];
			double fRec2237 = fRec2240;
			fRec2235[0] = (fTemp482 + (fRec2237 + fRec2235[1]));
			fRec2233[0] = fRec2235[0];
			double fRec2234 = (fRec2237 + fTemp482);
			fRec2232[0] = (fRec2233[0] + fRec2232[1]);
			fRec2230[0] = fRec2232[0];
			double fRec2231 = fRec2234;
			double fTemp484 = (fConst43 * fRec2227[1]);
			fRec2229[0] = ((fRec2231 + fRec2229[1]) - fTemp484);
			fRec2227[0] = fRec2229[0];
			double fRec2228 = (fRec2231 - fTemp484);
			double fTemp485 = (fConst8 * (0.0 - ((fConst10 * fRec2245[1]) + (fConst9 * fRec2242[1]))));
			double fTemp486 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec2251[1]) + (fConst6 * fRec2248[1])))) + (fConst4 * (((0.0061573343999999997 * fTemp17) + ((0.0105596445 * fTemp16) + ((5.6628100000000001e-05 * fTemp18) + ((0.00017025779999999999 * fTemp14) + (0.12702133569999999 * fTemp22))))) - ((((0.1009950171 * fTemp15) + (0.042766231199999998 * fTemp21)) + (1.8634499999999999e-05 * fTemp20)) + (4.4666899999999998e-05 * fTemp19))))));
			fRec2253[0] = (fRec2253[1] + fTemp486);
			fRec2251[0] = fRec2253[0];
			double fRec2252 = fTemp486;
			fRec2250[0] = (fRec2251[0] + fRec2250[1]);
			fRec2248[0] = fRec2250[0];
			double fRec2249 = fRec2252;
			fRec2247[0] = (fTemp485 + (fRec2249 + fRec2247[1]));
			fRec2245[0] = fRec2247[0];
			double fRec2246 = (fRec2249 + fTemp485);
			fRec2244[0] = (fRec2245[0] + fRec2244[1]);
			fRec2242[0] = fRec2244[0];
			double fRec2243 = fRec2246;
			double fTemp487 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec2260[1]) + (fConst26 * fRec2257[1])))) + (fConst25 * (((0.043385885700000001 * fTemp44) + ((0.1242159033 * fTemp41) + ((0.0222397576 * fTemp46) + (0.094115795399999994 * fTemp43)))) - ((2.64533e-05 * fTemp45) + ((2.7212800000000001e-05 * fTemp42) + (0.0001025116 * fTemp47)))))));
			fRec2262[0] = (fRec2262[1] + fTemp487);
			fRec2260[0] = fRec2262[0];
			double fRec2261 = fTemp487;
			fRec2259[0] = (fRec2260[0] + fRec2259[1]);
			fRec2257[0] = fRec2259[0];
			double fRec2258 = fRec2261;
			double fTemp488 = (fConst28 * fRec2254[1]);
			fRec2256[0] = ((fRec2258 + fRec2256[1]) - fTemp488);
			fRec2254[0] = fRec2256[0];
			double fRec2255 = (fRec2258 - fTemp488);
			double fTemp489 = (fConst32 * (((1.6833700000000001e-05 * fTemp58) - ((0.089838240299999997 * fTemp56) + (0.036576285299999997 * fTemp57))) - (fConst33 * fRec2263[1])));
			fRec2265[0] = (fRec2265[1] + fTemp489);
			fRec2263[0] = fRec2265[0];
			double fRec2264 = fTemp489;
			double fTemp490 = (fConst29 * ((((0.078430445400000007 * fTemp51) + (1.09431e-05 * fTemp52)) - (((5.1243699999999999e-05 * fTemp50) + (0.032247978300000001 * fTemp54)) + (0.1126450264 * fTemp53))) + (fConst5 * (0.0 - ((fConst31 * fRec2269[1]) + (fConst30 * fRec2266[1]))))));
			fRec2271[0] = (fRec2271[1] + fTemp490);
			fRec2269[0] = fRec2271[0];
			double fRec2270 = fTemp490;
			fRec2268[0] = (fRec2269[0] + fRec2268[1]);
			fRec2266[0] = fRec2268[0];
			double fRec2267 = fRec2270;
			fVec33[(IOTA & 1023)] = (((0.026018550200000001 * fTemp7) + ((0.083030970900000001 * fTemp75) + ((7.3873600000000004e-05 * fTemp9) + ((0.0984479251 * fTemp78) + ((0.0157491066 * fTemp79) + ((0.020595327699999999 * fTemp12) + (((0.034715270499999999 * fTemp13) + (fRec2210 + (fRec2228 + (fRec2243 + (fRec2255 + (fRec2264 + fRec2267)))))) + (0.033375916300000003 * fTemp80)))))))) - ((0.00013447200000000001 * fTemp8) + ((9.8296599999999997e-05 * fTemp10) + ((0.014944302600000001 * fTemp76) + ((4.3880900000000002e-05 * fTemp77) + ((4.2898200000000002e-05 * fTemp11) + ((8.0127200000000001e-05 * fTemp74) + ((0.00013007439999999999 * fTemp81) + (0.00044556830000000002 * fTemp82)))))))));
			output34[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec33[((IOTA - iConst44) & 1023)])));
			double fTemp491 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec2287[1]) + (fConst20 * fRec2284[1])))) + (fConst22 * (((0.019605815799999999 * fTemp33) + ((0.074122863900000002 * fTemp35) + ((((((0.0041386121999999999 * fTemp37) + (0.024257999799999999 * fTemp27)) + (0.010357649999999999 * fTemp29)) + (0.0109399847 * fTemp31)) + (0.084929922699999993 * fTemp38)) + (0.084758957199999999 * fTemp39)))) - ((0.040780133000000003 * fTemp34) + ((((0.0116404955 * fTemp36) + (0.016087145099999998 * fTemp28)) + (0.018742730199999998 * fTemp30)) + (0.00049019959999999996 * fTemp32)))))));
			fRec2289[0] = (fRec2289[1] + fTemp491);
			fRec2287[0] = fRec2289[0];
			double fRec2288 = fTemp491;
			fRec2286[0] = (fRec2287[0] + fRec2286[1]);
			fRec2284[0] = fRec2286[0];
			double fRec2285 = fRec2288;
			double fTemp492 = (fRec2285 + (fConst16 * (0.0 - ((fConst18 * fRec2281[1]) + (fConst17 * fRec2278[1])))));
			fRec2283[0] = (fRec2283[1] + fTemp492);
			fRec2281[0] = fRec2283[0];
			double fRec2282 = fTemp492;
			fRec2280[0] = (fRec2281[0] + fRec2280[1]);
			fRec2278[0] = fRec2280[0];
			double fRec2279 = fRec2282;
			double fTemp493 = (fRec2279 + (fConst12 * (0.0 - ((fConst14 * fRec2275[1]) + (fConst13 * fRec2272[1])))));
			fRec2277[0] = (fRec2277[1] + fTemp493);
			fRec2275[0] = fRec2277[0];
			double fRec2276 = fTemp493;
			fRec2274[0] = (fRec2275[0] + fRec2274[1]);
			fRec2272[0] = fRec2274[0];
			double fRec2273 = fRec2276;
			double fTemp494 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec2302[1]) + (fConst39 * fRec2299[1])))) + (fConst42 * ((((0.0017107581 * fTemp65) + ((0.1008031798 * fTemp61) + ((0.053264303899999997 * fTemp66) + ((0.018904471400000001 * fTemp67) + (0.0045042392000000002 * fTemp64))))) + (0.0044246687999999999 * fTemp70)) - (((((0.018293438299999999 * fTemp68) + (0.0210000202 * fTemp62)) + (0.0078237726000000007 * fTemp63)) + (0.018112879500000002 * fTemp69)) + (0.1107816527 * fTemp71))))));
			fRec2304[0] = (fRec2304[1] + fTemp494);
			fRec2302[0] = fRec2304[0];
			double fRec2303 = fTemp494;
			fRec2301[0] = (fRec2302[0] + fRec2301[1]);
			fRec2299[0] = fRec2301[0];
			double fRec2300 = fRec2303;
			double fTemp495 = (fRec2300 + (fConst35 * (0.0 - ((fConst37 * fRec2296[1]) + (fConst36 * fRec2293[1])))));
			fRec2298[0] = (fRec2298[1] + fTemp495);
			fRec2296[0] = fRec2298[0];
			double fRec2297 = fTemp495;
			fRec2295[0] = (fRec2296[0] + fRec2295[1]);
			fRec2293[0] = fRec2295[0];
			double fRec2294 = fRec2297;
			double fTemp496 = (fConst43 * fRec2290[1]);
			fRec2292[0] = ((fRec2294 + fRec2292[1]) - fTemp496);
			fRec2290[0] = fRec2292[0];
			double fRec2291 = (fRec2294 - fTemp496);
			double fTemp497 = (fConst8 * (0.0 - ((fConst10 * fRec2308[1]) + (fConst9 * fRec2305[1]))));
			double fTemp498 = (fConst2 * ((fConst4 * (((0.0105385363 * fTemp16) + (0.0043141550999999997 * fTemp17)) - ((0.0045201534999999996 * fTemp18) + ((0.095013438000000006 * fTemp19) + ((0.016963329199999998 * fTemp20) + ((0.035746257099999998 * fTemp15) + ((0.12738720619999999 * fTemp14) + ((0.039735932600000003 * fTemp21) + (0.0056393744000000001 * fTemp22))))))))) + (fConst5 * (0.0 - ((fConst7 * fRec2314[1]) + (fConst6 * fRec2311[1]))))));
			fRec2316[0] = (fRec2316[1] + fTemp498);
			fRec2314[0] = fRec2316[0];
			double fRec2315 = fTemp498;
			fRec2313[0] = (fRec2314[0] + fRec2313[1]);
			fRec2311[0] = fRec2313[0];
			double fRec2312 = fRec2315;
			fRec2310[0] = (fTemp497 + (fRec2312 + fRec2310[1]));
			fRec2308[0] = fRec2310[0];
			double fRec2309 = (fRec2312 + fTemp497);
			fRec2307[0] = (fRec2308[0] + fRec2307[1]);
			fRec2305[0] = fRec2307[0];
			double fRec2306 = fRec2309;
			double fTemp499 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec2323[1]) + (fConst26 * fRec2320[1])))) + (fConst25 * (((0.043799094099999998 * fTemp44) + ((0.043941193599999998 * fTemp41) + ((0.065469482800000006 * fTemp43) + ((0.0088331616000000002 * fTemp45) + ((0.020674530999999999 * fTemp46) + (0.11688296820000001 * fTemp47)))))) - (0.068400889600000001 * fTemp42)))));
			fRec2325[0] = (fRec2325[1] + fTemp499);
			fRec2323[0] = fRec2325[0];
			double fRec2324 = fTemp499;
			fRec2322[0] = (fRec2323[0] + fRec2322[1]);
			fRec2320[0] = fRec2322[0];
			double fRec2321 = fRec2324;
			double fTemp500 = (fConst28 * fRec2317[1]);
			fRec2319[0] = ((fRec2321 + fRec2319[1]) - fTemp500);
			fRec2317[0] = fRec2319[0];
			double fRec2318 = (fRec2321 - fTemp500);
			double fTemp501 = (fConst29 * (((((0.081891045499999995 * fTemp50) + (0.072576879699999999 * fTemp51)) + (0.030998083799999999 * fTemp52)) - ((0.032562400399999997 * fTemp54) + (0.078359728399999995 * fTemp53))) + (fConst5 * (0.0 - ((fConst31 * fRec2329[1]) + (fConst30 * fRec2326[1]))))));
			fRec2331[0] = (fRec2331[1] + fTemp501);
			fRec2329[0] = fRec2331[0];
			double fRec2330 = fTemp501;
			fRec2328[0] = (fRec2329[0] + fRec2328[1]);
			fRec2326[0] = fRec2328[0];
			double fRec2327 = fRec2330;
			double fTemp502 = (fConst32 * ((0.0 - (((0.083163283599999999 * fTemp56) + (0.036774808499999999 * fTemp57)) + (0.035524734799999999 * fTemp58))) - (fConst33 * fRec2332[1])));
			fRec2334[0] = (fRec2334[1] + fTemp502);
			fRec2332[0] = fRec2334[0];
			double fRec2333 = fTemp502;
			fVec34[(IOTA & 1023)] = (((0.018060833500000002 * fTemp7) + ((2.6528499999999999e-05 * fTemp9) + ((0.0313220601 * fTemp10) + ((0.0064454901000000004 * fTemp76) + ((0.0081521237999999992 * fTemp11) + ((0.015934945400000001 * fTemp79) + ((0.0190860892 * fTemp12) + ((0.0117582295 * fTemp80) + ((0.034937794899999999 * fTemp13) + (fRec2273 + (fRec2291 + (fRec2306 + (fRec2318 + (fRec2327 + (fRec2333 + (0.030313551500000001 * fTemp82)))))))))))))))) - ((((0.054608062399999997 * fTemp77) + ((0.093253030700000003 * fTemp78) + ((8.3369399999999995e-05 * fTemp81) + (0.018850243999999999 * fTemp74)))) + (0.0134821288 * fTemp8)) + (0.062358340300000002 * fTemp75)));
			output35[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec34[((IOTA - iConst44) & 1023)])));
			double fTemp503 = (fConst8 * (0.0 - ((fConst10 * fRec2338[1]) + (fConst9 * fRec2335[1]))));
			double fTemp504 = (fConst2 * ((fConst4 * ((((0.0094690130000000001 * fTemp14) + (0.074106192599999995 * fTemp15)) + (0.0104579676 * fTemp16)) - ((0.00039235790000000001 * fTemp17) + ((0.0061432557 * fTemp18) + ((0.066624665599999994 * fTemp19) + ((0.030253774899999999 * fTemp20) + ((0.0292092571 * fTemp21) + (0.1254790697 * fTemp22)))))))) + (fConst5 * (0.0 - ((fConst7 * fRec2344[1]) + (fConst6 * fRec2341[1]))))));
			fRec2346[0] = (fRec2346[1] + fTemp504);
			fRec2344[0] = fRec2346[0];
			double fRec2345 = fTemp504;
			fRec2343[0] = (fRec2344[0] + fRec2343[1]);
			fRec2341[0] = fRec2343[0];
			double fRec2342 = fRec2345;
			fRec2340[0] = (fTemp503 + (fRec2342 + fRec2340[1]));
			fRec2338[0] = fRec2340[0];
			double fRec2339 = (fRec2342 + fTemp503);
			fRec2337[0] = (fRec2338[0] + fRec2337[1]);
			fRec2335[0] = fRec2337[0];
			double fRec2336 = fRec2339;
			double fTemp505 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec2353[1]) + (fConst26 * fRec2350[1])))) + (fConst25 * (((0.042597784399999998 * fTemp44) + ((0.015866786300000001 * fTemp45) + ((0.015193916999999999 * fTemp46) + (0.081718515899999997 * fTemp47)))) - ((0.091431474799999995 * fTemp41) + ((0.092551866400000002 * fTemp42) + (0.0032696553999999999 * fTemp43)))))));
			fRec2355[0] = (fRec2355[1] + fTemp505);
			fRec2353[0] = fRec2355[0];
			double fRec2354 = fTemp505;
			fRec2352[0] = (fRec2353[0] + fRec2352[1]);
			fRec2350[0] = fRec2352[0];
			double fRec2351 = fRec2354;
			double fTemp506 = (fConst28 * fRec2347[1]);
			fRec2349[0] = ((fRec2351 + fRec2349[1]) - fTemp506);
			fRec2347[0] = fRec2349[0];
			double fRec2348 = (fRec2351 - fTemp506);
			double fTemp507 = (fConst29 * ((((((0.1108558581 * fTemp50) + (0.0535121021 * fTemp51)) + (0.055430892099999997 * fTemp52)) + (0.0041147917999999999 * fTemp53)) - (0.0317292645 * fTemp54)) + (fConst5 * (0.0 - ((fConst31 * fRec2359[1]) + (fConst30 * fRec2356[1]))))));
			fRec2361[0] = (fRec2361[1] + fTemp507);
			fRec2359[0] = fRec2361[0];
			double fRec2360 = fTemp507;
			fRec2358[0] = (fRec2359[0] + fRec2358[1]);
			fRec2356[0] = fRec2358[0];
			double fRec2357 = fRec2360;
			double fTemp508 = (fConst32 * ((0.0 - (((0.061302160100000003 * fTemp56) + (0.035917217799999998 * fTemp57)) + (0.063604866600000004 * fTemp58))) - (fConst33 * fRec2362[1])));
			fRec2364[0] = (fRec2364[1] + fTemp508);
			fRec2362[0] = fRec2364[0];
			double fRec2363 = fTemp508;
			double fTemp509 = (fConst35 * (0.0 - ((fConst37 * fRec2371[1]) + (fConst36 * fRec2368[1]))));
			double fTemp510 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec2377[1]) + (fConst39 * fRec2374[1])))) + (fConst42 * (((((0.077757611000000004 * fTemp66) + (((0.025506939199999999 * fTemp67) + (0.0008671916 * fTemp69)) + (0.0033302309999999999 * fTemp64))) + (0.099343018000000005 * fTemp70)) + (0.094150912000000003 * fTemp71)) - ((0.0033282520999999999 * fTemp65) + ((0.0070719531999999998 * fTemp61) + (((0.013573474699999999 * fTemp68) + (0.020555725600000001 * fTemp62)) + (0.014154738199999999 * fTemp63))))))));
			fRec2379[0] = (fRec2379[1] + fTemp510);
			fRec2377[0] = fRec2379[0];
			double fRec2378 = fTemp510;
			fRec2376[0] = (fRec2377[0] + fRec2376[1]);
			fRec2374[0] = fRec2376[0];
			double fRec2375 = fRec2378;
			fRec2373[0] = (fTemp509 + (fRec2375 + fRec2373[1]));
			fRec2371[0] = fRec2373[0];
			double fRec2372 = (fRec2375 + fTemp509);
			fRec2370[0] = (fRec2371[0] + fRec2370[1]);
			fRec2368[0] = fRec2370[0];
			double fRec2369 = fRec2372;
			double fTemp511 = (fConst43 * fRec2365[1]);
			fRec2367[0] = ((fRec2369 + fRec2367[1]) - fTemp511);
			fRec2365[0] = fRec2367[0];
			double fRec2366 = (fRec2369 - fTemp511);
			double fTemp512 = (fConst12 * (0.0 - ((fConst14 * fRec2383[1]) + (fConst13 * fRec2380[1]))));
			double fTemp513 = (fConst16 * (0.0 - ((fConst18 * fRec2389[1]) + (fConst17 * fRec2386[1]))));
			double fTemp514 = (fConst19 * ((fConst22 * (((0.026658866600000001 * fTemp33) + (((((0.00050881539999999995 * fTemp36) + (0.017939610700000001 * fTemp27)) + (0.018504386599999999 * fTemp29)) + (0.0010749355999999999 * fTemp30)) + (0.0077141005000000004 * fTemp31))) - ((0.0600950861 * fTemp34) + ((0.1120769625 * fTemp35) + ((0.011502337200000001 * fTemp32) + ((((0.0084384655000000006 * fTemp37) + (0.015660224899999999 * fTemp28)) + (0.071911245299999996 * fTemp38)) + (0.0130005134 * fTemp39))))))) + (fConst5 * (0.0 - ((fConst21 * fRec2395[1]) + (fConst20 * fRec2392[1]))))));
			fRec2397[0] = (fRec2397[1] + fTemp514);
			fRec2395[0] = fRec2397[0];
			double fRec2396 = fTemp514;
			fRec2394[0] = (fRec2395[0] + fRec2394[1]);
			fRec2392[0] = fRec2394[0];
			double fRec2393 = fRec2396;
			fRec2391[0] = (fTemp513 + (fRec2393 + fRec2391[1]));
			fRec2389[0] = fRec2391[0];
			double fRec2390 = (fRec2393 + fTemp513);
			fRec2388[0] = (fRec2389[0] + fRec2388[1]);
			fRec2386[0] = fRec2388[0];
			double fRec2387 = fRec2390;
			fRec2385[0] = (fTemp512 + (fRec2387 + fRec2385[1]));
			fRec2383[0] = fRec2385[0];
			double fRec2384 = (fRec2387 + fTemp512);
			fRec2382[0] = (fRec2383[0] + fRec2382[1]);
			fRec2380[0] = fRec2382[0];
			double fRec2381 = fRec2384;
			fVec35[(IOTA & 1023)] = (((0.0089732852000000002 * fTemp75) + ((0.0112376104 * fTemp8) + ((0.021871622199999999 * fTemp10) + ((0.0098391066999999992 * fTemp76) + ((0.082847460299999995 * fTemp77) + ((0.079199372200000007 * fTemp78) + ((0.0146607274 * fTemp11) + ((0.0153638478 * fTemp79) + (((0.0341170799 * fTemp13) + (fRec2336 + (fRec2348 + (fRec2357 + (fRec2363 + (fRec2366 + fRec2381)))))) + (0.0140369949 * fTemp12)))))))))) - ((0.00076603390000000004 * fTemp7) + ((0.00010032239999999999 * fTemp9) + ((0.025536442100000001 * fTemp74) + ((0.024635864100000002 * fTemp80) + ((0.00017384480000000001 * fTemp81) + (0.060028862400000001 * fTemp82)))))));
			output36[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec35[((IOTA - iConst44) & 1023)])));
			double fTemp515 = (fConst12 * (0.0 - ((fConst14 * fRec2401[1]) + (fConst13 * fRec2398[1]))));
			double fTemp516 = (fConst16 * (0.0 - ((fConst18 * fRec2407[1]) + (fConst17 * fRec2404[1]))));
			double fTemp517 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec2413[1]) + (fConst20 * fRec2410[1])))) + (fConst22 * (((0.017347306600000001 * fTemp33) + ((0.087849128900000004 * fTemp34) + ((0.085807096599999994 * fTemp35) + (((((0.011637215899999999 * fTemp36) + (0.0092759629999999999 * fTemp27)) + (0.0231185218 * fTemp29)) + (0.018359197800000001 * fTemp30)) + (0.00051786949999999997 * fTemp32))))) - (((((0.010377062499999999 * fTemp37) + (0.014866610000000001 * fTemp28)) + (0.0046369699999999998 * fTemp31)) + (0.029850300999999999 * fTemp38)) + (0.072619544800000005 * fTemp39))))));
			fRec2415[0] = (fRec2415[1] + fTemp517);
			fRec2413[0] = fRec2415[0];
			double fRec2414 = fTemp517;
			fRec2412[0] = (fRec2413[0] + fRec2412[1]);
			fRec2410[0] = fRec2412[0];
			double fRec2411 = fRec2414;
			fRec2409[0] = (fTemp516 + (fRec2411 + fRec2409[1]));
			fRec2407[0] = fRec2409[0];
			double fRec2408 = (fRec2411 + fTemp516);
			fRec2406[0] = (fRec2407[0] + fRec2406[1]);
			fRec2404[0] = fRec2406[0];
			double fRec2405 = fRec2408;
			fRec2403[0] = (fTemp515 + (fRec2405 + fRec2403[1]));
			fRec2401[0] = fRec2403[0];
			double fRec2402 = (fRec2405 + fTemp515);
			fRec2400[0] = (fRec2401[0] + fRec2400[1]);
			fRec2398[0] = fRec2400[0];
			double fRec2399 = fRec2402;
			double fTemp518 = (fConst35 * (0.0 - ((fConst37 * fRec2422[1]) + (fConst36 * fRec2419[1]))));
			double fTemp519 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec2428[1]) + (fConst39 * fRec2425[1])))) + (fConst42 * ((((0.017112799599999999 * fTemp67) + (0.017925386000000001 * fTemp69)) + (0.038208615199999997 * fTemp71)) - (((0.0045151211 * fTemp65) + ((0.097220842599999996 * fTemp61) + ((0.11362972740000001 * fTemp66) + ((((0.0067874574000000003 * fTemp68) + (0.019715748299999999 * fTemp62)) + (0.017074836400000001 * fTemp63)) + (0.0020096923000000001 * fTemp64))))) + (0.0050553602999999997 * fTemp70))))));
			fRec2430[0] = (fRec2430[1] + fTemp519);
			fRec2428[0] = fRec2430[0];
			double fRec2429 = fTemp519;
			fRec2427[0] = (fRec2428[0] + fRec2427[1]);
			fRec2425[0] = fRec2427[0];
			double fRec2426 = fRec2429;
			fRec2424[0] = (fTemp518 + (fRec2426 + fRec2424[1]));
			fRec2422[0] = fRec2424[0];
			double fRec2423 = (fRec2426 + fTemp518);
			fRec2421[0] = (fRec2422[0] + fRec2421[1]);
			fRec2419[0] = fRec2421[0];
			double fRec2420 = fRec2423;
			double fTemp520 = (fConst43 * fRec2416[1]);
			fRec2418[0] = ((fRec2420 + fRec2418[1]) - fTemp520);
			fRec2416[0] = fRec2418[0];
			double fRec2417 = (fRec2420 - fTemp520);
			double fTemp521 = (fConst29 * ((((((0.073092530200000005 * fTemp50) + (0.027370952099999998 * fTemp51)) + (0.068587093000000002 * fTemp52)) + (0.077108314900000002 * fTemp53)) - (0.030214339 * fTemp54)) + (fConst5 * (0.0 - ((fConst31 * fRec2434[1]) + (fConst30 * fRec2431[1]))))));
			fRec2436[0] = (fRec2436[1] + fTemp521);
			fRec2434[0] = fRec2436[0];
			double fRec2435 = fTemp521;
			fRec2433[0] = (fRec2434[0] + fRec2433[1]);
			fRec2431[0] = fRec2433[0];
			double fRec2432 = fRec2435;
			double fTemp522 = (fConst8 * (0.0 - ((fConst10 * fRec2440[1]) + (fConst9 * fRec2437[1]))));
			double fTemp523 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec2446[1]) + (fConst6 * fRec2443[1])))) + (fConst4 * (((0.0096611223999999996 * fTemp16) + ((0.040372783400000001 * fTemp19) + ((0.087657159700000001 * fTemp15) + ((0.12199520160000001 * fTemp14) + (0.0066097552000000002 * fTemp22))))) - (((0.0037940165000000001 * fTemp18) + ((0.0150329517 * fTemp21) + (0.037602945499999998 * fTemp20))) + (0.0040568501000000003 * fTemp17))))));
			fRec2448[0] = (fRec2448[1] + fTemp523);
			fRec2446[0] = fRec2448[0];
			double fRec2447 = fTemp523;
			fRec2445[0] = (fRec2446[0] + fRec2445[1]);
			fRec2443[0] = fRec2445[0];
			double fRec2444 = fRec2447;
			fRec2442[0] = (fTemp522 + (fRec2444 + fRec2442[1]));
			fRec2440[0] = fRec2442[0];
			double fRec2441 = (fRec2444 + fTemp522);
			fRec2439[0] = (fRec2440[0] + fRec2439[1]);
			fRec2437[0] = fRec2439[0];
			double fRec2438 = fRec2441;
			double fTemp524 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec2455[1]) + (fConst26 * fRec2452[1])))) + (fConst25 * (((0.040923574900000002 * fTemp44) + ((0.0076670577000000004 * fTemp46) + (0.0192668228 * fTemp45))) - ((0.1071969799 * fTemp41) + ((0.064627233100000001 * fTemp43) + ((0.061357396699999997 * fTemp42) + (0.049552894600000001 * fTemp47))))))));
			fRec2457[0] = (fRec2457[1] + fTemp524);
			fRec2455[0] = fRec2457[0];
			double fRec2456 = fTemp524;
			fRec2454[0] = (fRec2455[0] + fRec2454[1]);
			fRec2452[0] = fRec2454[0];
			double fRec2453 = fRec2456;
			double fTemp525 = (fConst28 * fRec2449[1]);
			fRec2451[0] = ((fRec2453 + fRec2451[1]) - fTemp525);
			fRec2449[0] = fRec2451[0];
			double fRec2450 = (fRec2453 - fTemp525);
			double fTemp526 = (fConst32 * ((0.0 - (((0.031235452600000001 * fTemp56) + (0.034344568200000002 * fTemp57)) + (0.078344383300000001 * fTemp58))) - (fConst33 * fRec2458[1])));
			fRec2460[0] = (fRec2460[1] + fTemp526);
			fRec2458[0] = fRec2460[0];
			double fRec2459 = fTemp526;
			fVec36[(IOTA & 1023)] = (((0.054502355099999997 * fTemp75) + ((0.0049909044000000001 * fTemp8) + ((0.0178285665 * fTemp11) + ((0.0150776661 * fTemp79) + ((0.0070789924000000002 * fTemp12) + ((0.00048135119999999999 * fTemp81) + ((0.032537510300000003 * fTemp13) + (fRec2399 + (fRec2417 + (fRec2432 + (fRec2438 + (fRec2450 + (fRec2459 + (0.089001262100000006 * fTemp82)))))))))))))) - ((0.017971385699999998 * fTemp7) + ((((0.0143403856 * fTemp76) + ((0.063826338900000001 * fTemp77) + ((0.047615886000000003 * fTemp78) + ((0.028538519200000001 * fTemp80) + (0.017201936599999999 * fTemp74))))) + (0.0132673953 * fTemp10)) + (0.000172058 * fTemp9))));
			output37[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec36[((IOTA - iConst44) & 1023)])));
			double fTemp527 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec2473[1]) + (fConst39 * fRec2470[1])))) + (fConst42 * (((0.00023837439999999999 * fTemp65) + ((0.0048849360999999999 * fTemp61) + ((0.0071471966 * fTemp66) + ((0.00022133 * fTemp68) + (0.0254021265 * fTemp69))))) - ((((((0.00067224090000000004 * fTemp67) + (0.0203956143 * fTemp62)) + (0.019532324199999999 * fTemp63)) + (0.0046014903999999999 * fTemp64)) + (0.0990964072 * fTemp70)) + (0.1216488535 * fTemp71))))));
			fRec2475[0] = (fRec2475[1] + fTemp527);
			fRec2473[0] = fRec2475[0];
			double fRec2474 = fTemp527;
			fRec2472[0] = (fRec2473[0] + fRec2472[1]);
			fRec2470[0] = fRec2472[0];
			double fRec2471 = fRec2474;
			double fTemp528 = (fRec2471 + (fConst35 * (0.0 - ((fConst37 * fRec2467[1]) + (fConst36 * fRec2464[1])))));
			fRec2469[0] = (fRec2469[1] + fTemp528);
			fRec2467[0] = fRec2469[0];
			double fRec2468 = fTemp528;
			fRec2466[0] = (fRec2467[0] + fRec2466[1]);
			fRec2464[0] = fRec2466[0];
			double fRec2465 = fRec2468;
			double fTemp529 = (fConst43 * fRec2461[1]);
			fRec2463[0] = ((fRec2465 + fRec2463[1]) - fTemp529);
			fRec2461[0] = fRec2463[0];
			double fRec2462 = (fRec2465 - fTemp529);
			double fTemp530 = (fConst8 * (0.0 - ((fConst10 * fRec2479[1]) + (fConst9 * fRec2476[1]))));
			double fTemp531 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec2485[1]) + (fConst6 * fRec2482[1])))) + (fConst4 * (((0.0104017754 * fTemp16) + ((0.00010798389999999999 * fTemp18) + ((0.099092652700000006 * fTemp19) + ((0.00054575070000000003 * fTemp21) + (0.1252646228 * fTemp22))))) - ((((0.0060428516999999999 * fTemp14) + (0.0037369907000000002 * fTemp15)) + (0.041830830499999999 * fTemp20)) + (0.0062018825000000003 * fTemp17))))));
			fRec2487[0] = (fRec2487[1] + fTemp531);
			fRec2485[0] = fRec2487[0];
			double fRec2486 = fTemp531;
			fRec2484[0] = (fRec2485[0] + fRec2484[1]);
			fRec2482[0] = fRec2484[0];
			double fRec2483 = fRec2486;
			fRec2481[0] = (fTemp530 + (fRec2483 + fRec2481[1]));
			fRec2479[0] = fRec2481[0];
			double fRec2480 = (fRec2483 + fTemp530);
			fRec2478[0] = (fRec2479[0] + fRec2478[1]);
			fRec2476[0] = fRec2478[0];
			double fRec2477 = fRec2480;
			double fTemp532 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec2494[1]) + (fConst26 * fRec2491[1])))) + (fConst25 * (((0.042377515499999997 * fTemp44) + ((0.0044979874000000003 * fTemp41) + ((0.0023437961 * fTemp42) + (0.021923963800000001 * fTemp45)))) - ((0.092052438400000006 * fTemp43) + ((0.00025627810000000001 * fTemp46) + (0.1220087285 * fTemp47)))))));
			fRec2496[0] = (fRec2496[1] + fTemp532);
			fRec2494[0] = fRec2496[0];
			double fRec2495 = fTemp532;
			fRec2493[0] = (fRec2494[0] + fRec2493[1]);
			fRec2491[0] = fRec2493[0];
			double fRec2492 = fRec2495;
			double fTemp533 = (fConst28 * fRec2488[1]);
			fRec2490[0] = ((fRec2492 + fRec2490[1]) - fTemp533);
			fRec2488[0] = fRec2490[0];
			double fRec2489 = (fRec2492 - fTemp533);
			double fTemp534 = (fConst29 * ((((0.0765607695 * fTemp52) + (0.110333793 * fTemp53)) - (((0.0027476353000000001 * fTemp50) + (0.0009809586999999999 * fTemp51)) + (0.031608978900000001 * fTemp54))) + (fConst5 * (0.0 - ((fConst31 * fRec2500[1]) + (fConst30 * fRec2497[1]))))));
			fRec2502[0] = (fRec2502[1] + fTemp534);
			fRec2500[0] = fRec2502[0];
			double fRec2501 = fTemp534;
			fRec2499[0] = (fRec2500[0] + fRec2499[1]);
			fRec2497[0] = fRec2499[0];
			double fRec2498 = fRec2501;
			double fTemp535 = (fConst32 * (((0.0011029233999999999 * fTemp56) - ((0.035671842299999999 * fTemp57) + (0.087839536600000004 * fTemp58))) - (fConst33 * fRec2503[1])));
			fRec2505[0] = (fRec2505[1] + fTemp535);
			fRec2503[0] = fRec2505[0];
			double fRec2504 = fTemp535;
			double fTemp536 = (fConst12 * (0.0 - ((fConst14 * fRec2509[1]) + (fConst13 * fRec2506[1]))));
			double fTemp537 = (fConst16 * (0.0 - ((fConst18 * fRec2515[1]) + (fConst17 * fRec2512[1]))));
			double fTemp538 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec2521[1]) + (fConst20 * fRec2518[1])))) + (fConst22 * (((0.0113957981 * fTemp32) + (((((0.00048332429999999998 * fTemp37) + (0.0256079759 * fTemp29)) + (0.026554926900000001 * fTemp30)) + (0.093337437199999998 * fTemp38)) + (0.11253543370000001 * fTemp39))) - ((0.00062395430000000002 * fTemp33) + ((0.0055834313000000003 * fTemp34) + ((0.007653511 * fTemp35) + ((((0.00062555360000000003 * fTemp36) + (0.00034547380000000001 * fTemp27)) + (0.0156464849 * fTemp28)) + (0.0113972137 * fTemp31)))))))));
			fRec2523[0] = (fRec2523[1] + fTemp538);
			fRec2521[0] = fRec2523[0];
			double fRec2522 = fTemp538;
			fRec2520[0] = (fRec2521[0] + fRec2520[1]);
			fRec2518[0] = fRec2520[0];
			double fRec2519 = fRec2522;
			fRec2517[0] = (fTemp537 + (fRec2519 + fRec2517[1]));
			fRec2515[0] = fRec2517[0];
			double fRec2516 = (fRec2519 + fTemp537);
			fRec2514[0] = (fRec2515[0] + fRec2514[1]);
			fRec2512[0] = fRec2514[0];
			double fRec2513 = fRec2516;
			fRec2511[0] = (fTemp536 + (fRec2513 + fRec2511[1]));
			fRec2509[0] = fRec2511[0];
			double fRec2510 = (fRec2513 + fTemp536);
			fRec2508[0] = (fRec2509[0] + fRec2508[1]);
			fRec2506[0] = fRec2508[0];
			double fRec2507 = fRec2510;
			fVec37[(IOTA & 1023)] = (((0.00011322100000000001 * fTemp9) + ((0.00093087390000000001 * fTemp76) + ((0.0057080658999999999 * fTemp77) + ((0.0074881623999999997 * fTemp78) + ((0.020223139899999999 * fTemp11) + ((0.0153168045 * fTemp79) + ((0.00070100160000000002 * fTemp74) + (((0.033914586699999999 * fTemp13) + (fRec2462 + (fRec2477 + (fRec2489 + (fRec2498 + (fRec2504 + fRec2507)))))) + (0.0011595073 * fTemp80))))))))) - ((0.025382542099999999 * fTemp7) + ((0.083123316599999997 * fTemp75) + ((0.014838680999999999 * fTemp8) + ((0.032778862800000003 * fTemp10) + ((0.0002381072 * fTemp12) + ((9.5043999999999993e-05 * fTemp81) + (0.099299273699999996 * fTemp82))))))));
			output38[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec37[((IOTA - iConst44) & 1023)])));
			double fTemp539 = (fConst32 * (((0.034568476700000003 * fTemp56) - ((0.036137616599999998 * fTemp57) + (0.081525693900000001 * fTemp58))) - (fConst33 * fRec2524[1])));
			fRec2526[0] = (fRec2526[1] + fTemp539);
			fRec2524[0] = fRec2526[0];
			double fRec2525 = fTemp539;
			double fTemp540 = (fConst12 * (0.0 - ((fConst14 * fRec2530[1]) + (fConst13 * fRec2527[1]))));
			double fTemp541 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec2542[1]) + (fConst20 * fRec2539[1])))) + (fConst22 * ((((0.010936082600000001 * fTemp37) + (0.024123942799999999 * fTemp29)) + (0.0182405278 * fTemp30)) - ((0.019019952900000001 * fTemp33) + ((0.085200430699999996 * fTemp34) + ((0.074841319599999998 * fTemp35) + ((0.0001687506 * fTemp32) + ((((((0.011861602000000001 * fTemp36) + (0.0101999173 * fTemp27)) + (0.0154718324 * fTemp28)) + (0.0043203336000000002 * fTemp31)) + (0.039543047900000003 * fTemp38)) + (0.083914918800000002 * fTemp39))))))))));
			fRec2544[0] = (fRec2544[1] + fTemp541);
			fRec2542[0] = fRec2544[0];
			double fRec2543 = fTemp541;
			fRec2541[0] = (fRec2542[0] + fRec2541[1]);
			fRec2539[0] = fRec2541[0];
			double fRec2540 = fRec2543;
			double fTemp542 = (fRec2540 + (fConst16 * (0.0 - ((fConst18 * fRec2536[1]) + (fConst17 * fRec2533[1])))));
			fRec2538[0] = (fRec2538[1] + fTemp542);
			fRec2536[0] = fRec2538[0];
			double fRec2537 = fTemp542;
			fRec2535[0] = (fRec2536[0] + fRec2535[1]);
			fRec2533[0] = fRec2535[0];
			double fRec2534 = fRec2537;
			fRec2532[0] = (fTemp540 + (fRec2534 + fRec2532[1]));
			fRec2530[0] = fRec2532[0];
			double fRec2531 = (fRec2534 + fTemp540);
			fRec2529[0] = (fRec2530[0] + fRec2529[1]);
			fRec2527[0] = fRec2529[0];
			double fRec2528 = fRec2531;
			double fTemp543 = (fConst35 * (0.0 - ((fConst37 * fRec2551[1]) + (fConst36 * fRec2548[1]))));
			double fTemp544 = (fConst38 * ((fConst42 * (((((0.0046983359000000004 * fTemp65) + ((0.099969590600000005 * fTemp61) + ((0.1103593916 * fTemp66) + ((0.0075650915999999997 * fTemp68) + (0.018071708799999999 * fTemp69))))) + (0.0032433421999999998 * fTemp70)) + (0.051734068500000001 * fTemp71)) - ((((0.018579713500000001 * fTemp67) + (0.0208114779 * fTemp62)) + (0.0176760844 * fTemp63)) + (0.002005944 * fTemp64)))) + (fConst5 * (0.0 - ((fConst40 * fRec2557[1]) + (fConst39 * fRec2554[1]))))));
			fRec2559[0] = (fRec2559[1] + fTemp544);
			fRec2557[0] = fRec2559[0];
			double fRec2558 = fTemp544;
			fRec2556[0] = (fRec2557[0] + fRec2556[1]);
			fRec2554[0] = fRec2556[0];
			double fRec2555 = fRec2558;
			fRec2553[0] = (fTemp543 + (fRec2555 + fRec2553[1]));
			fRec2551[0] = fRec2553[0];
			double fRec2552 = (fRec2555 + fTemp543);
			fRec2550[0] = (fRec2551[0] + fRec2550[1]);
			fRec2548[0] = fRec2550[0];
			double fRec2549 = fRec2552;
			double fTemp545 = (fConst43 * fRec2545[1]);
			fRec2547[0] = ((fRec2549 + fRec2547[1]) - fTemp545);
			fRec2545[0] = fRec2547[0];
			double fRec2546 = (fRec2549 - fTemp545);
			double fTemp546 = (fConst8 * (0.0 - ((fConst10 * fRec2563[1]) + (fConst9 * fRec2560[1]))));
			double fTemp547 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec2569[1]) + (fConst6 * fRec2566[1])))) + (fConst4 * (((0.0101555443 * fTemp16) + ((0.0042355329000000001 * fTemp18) + ((0.016562508600000001 * fTemp21) + (0.036137453 * fTemp19)))) - ((0.0039392641000000001 * fTemp17) + ((0.0391794684 * fTemp20) + ((0.093474679000000005 * fTemp15) + ((0.12569968919999999 * fTemp14) + (0.0044471913999999998 * fTemp22)))))))));
			fRec2571[0] = (fRec2571[1] + fTemp547);
			fRec2569[0] = fRec2571[0];
			double fRec2570 = fTemp547;
			fRec2568[0] = (fRec2569[0] + fRec2568[1]);
			fRec2566[0] = fRec2568[0];
			double fRec2567 = fRec2570;
			fRec2565[0] = (fTemp546 + (fRec2567 + fRec2565[1]));
			fRec2563[0] = fRec2565[0];
			double fRec2564 = (fRec2567 + fTemp546);
			fRec2562[0] = (fRec2563[0] + fRec2562[1]);
			fRec2560[0] = fRec2562[0];
			double fRec2561 = fRec2564;
			double fTemp548 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec2578[1]) + (fConst26 * fRec2575[1])))) + (fConst25 * (((0.043009347400000002 * fTemp44) + ((0.1145522271 * fTemp41) + ((0.066932450500000004 * fTemp42) + (0.0199841155 * fTemp45)))) - ((0.064869799399999997 * fTemp43) + ((0.0085181396999999999 * fTemp46) + (0.044014614899999999 * fTemp47)))))));
			fRec2580[0] = (fRec2580[1] + fTemp548);
			fRec2578[0] = fRec2580[0];
			double fRec2579 = fTemp548;
			fRec2577[0] = (fRec2578[0] + fRec2577[1]);
			fRec2575[0] = fRec2577[0];
			double fRec2576 = fRec2579;
			double fTemp549 = (fConst28 * fRec2572[1]);
			fRec2574[0] = ((fRec2576 + fRec2574[1]) - fTemp549);
			fRec2572[0] = fRec2574[0];
			double fRec2573 = (fRec2576 - fTemp549);
			double fTemp550 = (fConst29 * ((((0.071427952700000005 * fTemp52) + (0.0772341322 * fTemp53)) - (((0.079891127899999997 * fTemp50) + (0.030240653999999999 * fTemp51)) + (0.031715759900000001 * fTemp54))) + (fConst5 * (0.0 - ((fConst31 * fRec2584[1]) + (fConst30 * fRec2581[1]))))));
			fRec2586[0] = (fRec2586[1] + fTemp550);
			fRec2584[0] = fRec2586[0];
			double fRec2585 = fTemp550;
			fRec2583[0] = (fRec2584[0] + fRec2583[1]);
			fRec2581[0] = fRec2583[0];
			double fRec2582 = fRec2585;
			fVec38[(IOTA & 1023)] = (((0.061898373 * fTemp75) + ((0.0061744905000000001 * fTemp8) + ((0.00012881939999999999 * fTemp9) + ((0.013847015799999999 * fTemp76) + ((0.055724890800000003 * fTemp77) + ((0.031332617799999997 * fTemp78) + ((0.018387352999999999 * fTemp11) + ((0.015762613799999999 * fTemp79) + ((0.018625303900000001 * fTemp74) + ((0.030550710599999999 * fTemp80) + ((0.034211823400000001 * fTemp13) + (fRec2525 + (fRec2528 + (fRec2546 + (fRec2561 + (fRec2573 + (fRec2582 + (0.093763604299999997 * fTemp82)))))))))))))))))) - ((0.018121346600000001 * fTemp7) + (((0.00036528690000000002 * fTemp81) + (0.0078317713999999997 * fTemp12)) + (0.011595838000000001 * fTemp10))));
			output39[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec38[((IOTA - iConst44) & 1023)])));
			double fTemp551 = (fConst12 * (0.0 - ((fConst14 * fRec2590[1]) + (fConst13 * fRec2587[1]))));
			double fTemp552 = (fConst16 * (0.0 - ((fConst18 * fRec2596[1]) + (fConst17 * fRec2593[1]))));
			double fTemp553 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec2602[1]) + (fConst20 * fRec2599[1])))) + (fConst22 * (((0.067947623700000001 * fTemp34) + ((0.1124849424 * fTemp35) + (((((0.00046155460000000002 * fTemp36) + (0.0077569576000000003 * fTemp37)) + (0.0173578359 * fTemp29)) + (0.0081165470999999996 * fTemp31)) + (0.0048423791000000004 * fTemp39)))) - ((0.025523628 * fTemp33) + ((0.0113937811 * fTemp32) + ((((0.017622619799999999 * fTemp27) + (0.015068307 * fTemp28)) + (0.00033889940000000001 * fTemp30)) + (0.063014389599999998 * fTemp38))))))));
			fRec2604[0] = (fRec2604[1] + fTemp553);
			fRec2602[0] = fRec2604[0];
			double fRec2603 = fTemp553;
			fRec2601[0] = (fRec2602[0] + fRec2601[1]);
			fRec2599[0] = fRec2601[0];
			double fRec2600 = fRec2603;
			fRec2598[0] = (fTemp552 + (fRec2600 + fRec2598[1]));
			fRec2596[0] = fRec2598[0];
			double fRec2597 = (fRec2600 + fTemp552);
			fRec2595[0] = (fRec2596[0] + fRec2595[1]);
			fRec2593[0] = fRec2595[0];
			double fRec2594 = fRec2597;
			fRec2592[0] = (fTemp551 + (fRec2594 + fRec2592[1]));
			fRec2590[0] = fRec2592[0];
			double fRec2591 = (fRec2594 + fTemp551);
			fRec2589[0] = (fRec2590[0] + fRec2589[1]);
			fRec2587[0] = fRec2589[0];
			double fRec2588 = fRec2591;
			double fTemp554 = (fConst35 * (0.0 - ((fConst37 * fRec2611[1]) + (fConst36 * fRec2608[1]))));
			double fTemp555 = (fConst38 * ((fConst42 * (((((0.0031690543999999998 * fTemp65) + ((0.013261622400000001 * fTemp68) + (0.0034500829 * fTemp64))) + (0.097225752700000001 * fTemp70)) + (0.081856571700000005 * fTemp71)) - ((0.0029183333000000001 * fTemp61) + ((0.0879460304 * fTemp66) + ((((0.024653400400000001 * fTemp67) + (0.019614823999999999 * fTemp62)) + (0.013102436800000001 * fTemp63)) + (0.00036273060000000001 * fTemp69)))))) + (fConst5 * (0.0 - ((fConst40 * fRec2617[1]) + (fConst39 * fRec2614[1]))))));
			fRec2619[0] = (fRec2619[1] + fTemp555);
			fRec2617[0] = fRec2619[0];
			double fRec2618 = fTemp555;
			fRec2616[0] = (fRec2617[0] + fRec2616[1]);
			fRec2614[0] = fRec2616[0];
			double fRec2615 = fRec2618;
			fRec2613[0] = (fTemp554 + (fRec2615 + fRec2613[1]));
			fRec2611[0] = fRec2613[0];
			double fRec2612 = (fRec2615 + fTemp554);
			fRec2610[0] = (fRec2611[0] + fRec2610[1]);
			fRec2608[0] = fRec2610[0];
			double fRec2609 = fRec2612;
			double fTemp556 = (fConst43 * fRec2605[1]);
			fRec2607[0] = ((fRec2609 + fRec2607[1]) - fTemp556);
			fRec2605[0] = fRec2607[0];
			double fRec2606 = (fRec2609 - fTemp556);
			double fTemp557 = (fConst8 * (0.0 - ((fConst10 * fRec2623[1]) + (fConst9 * fRec2620[1]))));
			double fTemp558 = (fConst2 * ((fConst4 * (((((0.0058101762999999999 * fTemp18) + ((0.0035142791 * fTemp14) + (0.028783856399999998 * fTemp21))) + (0.0098434149999999995 * fTemp16)) + (2.3346800000000002e-05 * fTemp17)) - ((0.069721839499999994 * fTemp19) + ((0.028359543399999999 * fTemp20) + ((0.066658692899999997 * fTemp15) + (0.1224423573 * fTemp22)))))) + (fConst5 * (0.0 - ((fConst7 * fRec2629[1]) + (fConst6 * fRec2626[1]))))));
			fRec2631[0] = (fRec2631[1] + fTemp558);
			fRec2629[0] = fRec2631[0];
			double fRec2630 = fTemp558;
			fRec2628[0] = (fRec2629[0] + fRec2628[1]);
			fRec2626[0] = fRec2628[0];
			double fRec2627 = fRec2630;
			fRec2625[0] = (fTemp557 + (fRec2627 + fRec2625[1]));
			fRec2623[0] = fRec2625[0];
			double fRec2624 = (fRec2627 + fTemp557);
			fRec2622[0] = (fRec2623[0] + fRec2622[1]);
			fRec2620[0] = fRec2622[0];
			double fRec2621 = fRec2624;
			double fTemp559 = (fConst23 * ((fConst25 * (((0.040893681000000001 * fTemp44) + ((0.081919764500000006 * fTemp41) + ((0.0013331096000000001 * fTemp43) + ((0.0147467681 * fTemp45) + ((0.089090429700000001 * fTemp42) + (0.085528738399999998 * fTemp47)))))) - (0.014927490200000001 * fTemp46))) + (fConst5 * (0.0 - ((fConst27 * fRec2638[1]) + (fConst26 * fRec2635[1]))))));
			fRec2640[0] = (fRec2640[1] + fTemp559);
			fRec2638[0] = fRec2640[0];
			double fRec2639 = fTemp559;
			fRec2637[0] = (fRec2638[0] + fRec2637[1]);
			fRec2635[0] = fRec2637[0];
			double fRec2636 = fRec2639;
			double fTemp560 = (fConst28 * fRec2632[1]);
			fRec2634[0] = ((fRec2636 + fRec2634[1]) - fTemp560);
			fRec2632[0] = fRec2634[0];
			double fRec2633 = (fRec2636 - fTemp560);
			double fTemp561 = (fConst32 * (((0.060240385600000002 * fTemp56) - ((0.034357911499999998 * fTemp57) + (0.059376598099999997 * fTemp58))) - (fConst33 * fRec2641[1])));
			fRec2643[0] = (fRec2643[1] + fTemp561);
			fRec2641[0] = fRec2643[0];
			double fRec2642 = fTemp561;
			double fTemp562 = (fConst29 * (((0.051832372600000003 * fTemp52) - ((((0.10654592810000001 * fTemp50) + (0.052613223100000002 * fTemp51)) + (0.030378854600000001 * fTemp54)) + (0.001534299 * fTemp53))) + (fConst5 * (0.0 - ((fConst31 * fRec2647[1]) + (fConst30 * fRec2644[1]))))));
			fRec2649[0] = (fRec2649[1] + fTemp562);
			fRec2647[0] = fRec2649[0];
			double fRec2648 = fTemp562;
			fRec2646[0] = (fRec2647[0] + fRec2646[1]);
			fRec2644[0] = fRec2646[0];
			double fRec2645 = fRec2648;
			fVec39[(IOTA & 1023)] = (((0.00039577770000000001 * fTemp7) + ((0.010075662900000001 * fTemp8) + ((0.022864948400000001 * fTemp10) + ((0.0136671104 * fTemp11) + ((0.0149504737 * fTemp79) + ((0.024694095199999998 * fTemp74) + ((0.021955411800000001 * fTemp80) + (((0.032625369799999998 * fTemp13) + (fRec2588 + (fRec2606 + (fRec2621 + (fRec2633 + (fRec2642 + fRec2645)))))) + (2.78643e-05 * fTemp81))))))))) - ((0.0038063744000000001 * fTemp75) + ((0.00033840120000000002 * fTemp9) + ((0.0110696149 * fTemp76) + ((0.083712214899999998 * fTemp77) + ((0.067743546599999996 * fTemp78) + ((0.0138411869 * fTemp12) + (0.074916582100000004 * fTemp82))))))));
			output40[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec39[((IOTA - iConst44) & 1023)])));
			double fTemp563 = (fConst12 * (0.0 - ((fConst14 * fRec2653[1]) + (fConst13 * fRec2650[1]))));
			double fTemp564 = (fConst16 * (0.0 - ((fConst18 * fRec2659[1]) + (fConst17 * fRec2656[1]))));
			double fTemp565 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec2665[1]) + (fConst20 * fRec2662[1])))) + (fConst22 * (((0.040080851100000002 * fTemp34) + (((((0.011368933600000001 * fTemp36) + (0.0096044922999999997 * fTemp29)) + (0.010514806599999999 * fTemp31)) + (0.082877489200000001 * fTemp38)) + (0.084650841399999996 * fTemp39))) - ((0.0179462856 * fTemp33) + ((0.073740365899999993 * fTemp35) + (((((0.0038978533999999999 * fTemp37) + (0.022463482100000001 * fTemp27)) + (0.014466945 * fTemp28)) + (0.017178152700000001 * fTemp30)) + (0.00052618249999999999 * fTemp32))))))));
			fRec2667[0] = (fRec2667[1] + fTemp565);
			fRec2665[0] = fRec2667[0];
			double fRec2666 = fTemp565;
			fRec2664[0] = (fRec2665[0] + fRec2664[1]);
			fRec2662[0] = fRec2664[0];
			double fRec2663 = fRec2666;
			fRec2661[0] = (fTemp564 + (fRec2663 + fRec2661[1]));
			fRec2659[0] = fRec2661[0];
			double fRec2660 = (fRec2663 + fTemp564);
			fRec2658[0] = (fRec2659[0] + fRec2658[1]);
			fRec2656[0] = fRec2658[0];
			double fRec2657 = fRec2660;
			fRec2655[0] = (fTemp563 + (fRec2657 + fRec2655[1]));
			fRec2653[0] = fRec2655[0];
			double fRec2654 = (fRec2657 + fTemp563);
			fRec2652[0] = (fRec2653[0] + fRec2652[1]);
			fRec2650[0] = fRec2652[0];
			double fRec2651 = fRec2654;
			double fTemp566 = (fConst29 * (((0.0284112945 * fTemp52) - ((((0.075395823099999995 * fTemp50) + (0.066366705999999998 * fTemp51)) + (0.029573968799999999 * fTemp54)) + (0.071918978999999994 * fTemp53))) + (fConst5 * (0.0 - ((fConst31 * fRec2671[1]) + (fConst30 * fRec2668[1]))))));
			fRec2673[0] = (fRec2673[1] + fTemp566);
			fRec2671[0] = fRec2673[0];
			double fRec2672 = fTemp566;
			fRec2670[0] = (fRec2671[0] + fRec2670[1]);
			fRec2668[0] = fRec2670[0];
			double fRec2669 = fRec2672;
			double fTemp567 = (fConst32 * (((0.075912750299999998 * fTemp56) - ((0.033586229099999997 * fTemp57) + (0.032500149499999999 * fTemp58))) - (fConst33 * fRec2674[1])));
			fRec2676[0] = (fRec2676[1] + fTemp567);
			fRec2674[0] = fRec2676[0];
			double fRec2675 = fTemp567;
			double fTemp568 = (fConst35 * (0.0 - ((fConst37 * fRec2683[1]) + (fConst36 * fRec2680[1]))));
			double fTemp569 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec2689[1]) + (fConst39 * fRec2686[1])))) + (fConst42 * ((((0.016714340300000002 * fTemp68) + (0.0043939134000000003 * fTemp64)) + (0.0044831803000000003 * fTemp70)) - (((0.0016470249000000001 * fTemp65) + ((0.095917633799999999 * fTemp61) + ((0.051806169399999998 * fTemp66) + ((((0.017606555499999999 * fTemp67) + (0.0194061105 * fTemp62)) + (0.0071344001000000004 * fTemp63)) + (0.016755737400000002 * fTemp69))))) + (0.10707020339999999 * fTemp71))))));
			fRec2691[0] = (fRec2691[1] + fTemp569);
			fRec2689[0] = fRec2691[0];
			double fRec2690 = fTemp569;
			fRec2688[0] = (fRec2689[0] + fRec2688[1]);
			fRec2686[0] = fRec2688[0];
			double fRec2687 = fRec2690;
			fRec2685[0] = (fTemp568 + (fRec2687 + fRec2685[1]));
			fRec2683[0] = fRec2685[0];
			double fRec2684 = (fRec2687 + fTemp568);
			fRec2682[0] = (fRec2683[0] + fRec2682[1]);
			fRec2680[0] = fRec2682[0];
			double fRec2681 = fRec2684;
			double fTemp570 = (fConst43 * fRec2677[1]);
			fRec2679[0] = ((fRec2681 + fRec2679[1]) - fTemp570);
			fRec2677[0] = fRec2679[0];
			double fRec2678 = (fRec2681 - fTemp570);
			double fTemp571 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec2698[1]) + (fConst26 * fRec2695[1])))) + (fConst25 * (((0.0399058755 * fTemp44) + ((0.060227644800000001 * fTemp43) + ((0.0080503082999999996 * fTemp45) + ((0.063138587400000001 * fTemp42) + (0.1087938522 * fTemp47))))) - ((0.040632101099999998 * fTemp41) + (0.018783130700000001 * fTemp46))))));
			fRec2700[0] = (fRec2700[1] + fTemp571);
			fRec2698[0] = fRec2700[0];
			double fRec2699 = fTemp571;
			fRec2697[0] = (fRec2698[0] + fRec2697[1]);
			fRec2695[0] = fRec2697[0];
			double fRec2696 = fRec2699;
			double fTemp572 = (fConst28 * fRec2692[1]);
			fRec2694[0] = ((fRec2696 + fRec2694[1]) - fTemp572);
			fRec2692[0] = fRec2694[0];
			double fRec2693 = (fRec2696 - fTemp572);
			double fTemp573 = (fConst8 * (0.0 - ((fConst10 * fRec2704[1]) + (fConst9 * fRec2701[1]))));
			double fTemp574 = (fConst2 * ((fConst4 * (((((0.0040761707000000003 * fTemp18) + ((0.0331591314 * fTemp15) + ((0.1204740253 * fTemp14) + (0.0363760313 * fTemp21)))) + (0.0096749307000000007 * fTemp16)) + (0.0038757999 * fTemp17)) - ((0.088786852799999996 * fTemp19) + ((0.015591934 * fTemp20) + (0.0056351897000000003 * fTemp22))))) + (fConst5 * (0.0 - ((fConst7 * fRec2710[1]) + (fConst6 * fRec2707[1]))))));
			fRec2712[0] = (fRec2712[1] + fTemp574);
			fRec2710[0] = fRec2712[0];
			double fRec2711 = fTemp574;
			fRec2709[0] = (fRec2710[0] + fRec2709[1]);
			fRec2707[0] = fRec2709[0];
			double fRec2708 = fRec2711;
			fRec2706[0] = (fTemp573 + (fRec2708 + fRec2706[1]));
			fRec2704[0] = fRec2706[0];
			double fRec2705 = (fRec2708 + fTemp573);
			fRec2703[0] = (fRec2704[0] + fRec2703[1]);
			fRec2701[0] = fRec2703[0];
			double fRec2702 = fRec2705;
			fVec40[(IOTA & 1023)] = (((0.016820638400000001 * fTemp7) + ((0.028972672800000002 * fTemp10) + ((0.055171633499999997 * fTemp77) + ((0.096691438199999993 * fTemp78) + ((0.0073778367999999999 * fTemp11) + ((0.0145335732 * fTemp79) + ((0.017576030699999998 * fTemp74) + ((0.00052236939999999999 * fTemp81) + ((0.031844484800000003 * fTemp13) + (fRec2651 + (fRec2669 + (fRec2675 + (fRec2678 + (fRec2693 + (fRec2702 + (0.031360459100000002 * fTemp82)))))))))))))))) - (((((0.0065308750000000002 * fTemp76) + ((0.010875882200000001 * fTemp80) + (0.0172297098 * fTemp12))) + (4.31137e-05 * fTemp9)) + (0.0135340809 * fTemp8)) + (0.063265335000000006 * fTemp75)));
			output41[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec40[((IOTA - iConst44) & 1023)])));
			double fTemp575 = (fConst35 * (0.0 - ((fConst37 * fRec2719[1]) + (fConst36 * fRec2716[1]))));
			double fTemp576 = (fConst38 * ((fConst5 * (0.0 - ((fConst40 * fRec2725[1]) + (fConst39 * fRec2722[1])))) + (fConst42 * (((0.1205410942 * fTemp66) + ((0.019113863200000001 * fTemp68) + (0.00018720290000000001 * fTemp64))) - ((((0.0045927842999999996 * fTemp65) + ((0.0077209805000000003 * fTemp61) + ((((0.0008850803 * fTemp67) + (0.019955841500000002 * fTemp62)) + (0.00040752179999999999 * fTemp63)) + (0.0250377419 * fTemp69)))) + (0.098040843200000005 * fTemp70)) + (0.0124068553 * fTemp71))))));
			fRec2727[0] = (fRec2727[1] + fTemp576);
			fRec2725[0] = fRec2727[0];
			double fRec2726 = fTemp576;
			fRec2724[0] = (fRec2725[0] + fRec2724[1]);
			fRec2722[0] = fRec2724[0];
			double fRec2723 = fRec2726;
			fRec2721[0] = (fTemp575 + (fRec2723 + fRec2721[1]));
			fRec2719[0] = fRec2721[0];
			double fRec2720 = (fRec2723 + fTemp575);
			fRec2718[0] = (fRec2719[0] + fRec2718[1]);
			fRec2716[0] = fRec2718[0];
			double fRec2717 = fRec2720;
			double fTemp577 = (fConst43 * fRec2713[1]);
			fRec2715[0] = ((fRec2717 + fRec2715[1]) - fTemp577);
			fRec2713[0] = fRec2715[0];
			double fRec2714 = (fRec2717 - fTemp577);
			double fTemp578 = (fConst8 * (0.0 - ((fConst10 * fRec2731[1]) + (fConst9 * fRec2728[1]))));
			double fTemp579 = (fConst2 * ((fConst4 * (((0.0060592987000000001 * fTemp17) + ((0.0101201165 * fTemp16) + ((0.00028976499999999999 * fTemp18) + ((0.097766724299999996 * fTemp15) + ((0.010012856699999999 * fTemp14) + ((0.041185025399999999 * fTemp21) + (0.1237535315 * fTemp22))))))) - ((0.00076584769999999997 * fTemp20) + (0.0057082460000000002 * fTemp19)))) + (fConst5 * (0.0 - ((fConst7 * fRec2737[1]) + (fConst6 * fRec2734[1]))))));
			fRec2739[0] = (fRec2739[1] + fTemp579);
			fRec2737[0] = fRec2739[0];
			double fRec2738 = fTemp579;
			fRec2736[0] = (fRec2737[0] + fRec2736[1]);
			fRec2734[0] = fRec2736[0];
			double fRec2735 = fRec2738;
			fRec2733[0] = (fTemp578 + (fRec2735 + fRec2733[1]));
			fRec2731[0] = fRec2733[0];
			double fRec2732 = (fRec2735 + fTemp578);
			fRec2730[0] = (fRec2731[0] + fRec2730[1]);
			fRec2728[0] = fRec2730[0];
			double fRec2729 = fRec2732;
			double fTemp580 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec2746[1]) + (fConst26 * fRec2743[1])))) + (fConst25 * (((0.041731580300000001 * fTemp44) + ((0.090649313999999995 * fTemp43) + ((0.0004438941 * fTemp45) + ((0.0035046299999999999 * fTemp42) + (0.0072027953999999998 * fTemp47))))) - ((0.1202623352 * fTemp41) + (0.021536670399999999 * fTemp46))))));
			fRec2748[0] = (fRec2748[1] + fTemp580);
			fRec2746[0] = fRec2748[0];
			double fRec2747 = fTemp580;
			fRec2745[0] = (fRec2746[0] + fRec2745[1]);
			fRec2743[0] = fRec2745[0];
			double fRec2744 = fRec2747;
			double fTemp581 = (fConst28 * fRec2740[1]);
			fRec2742[0] = ((fRec2744 + fRec2742[1]) - fTemp581);
			fRec2740[0] = fRec2742[0];
			double fRec2741 = (fRec2744 - fTemp581);
			double fTemp582 = (fConst29 * (((0.0014508849 * fTemp52) - ((((0.0042952473 * fTemp50) + (0.075304494900000005 * fTemp51)) + (0.031093106799999999 * fTemp54)) + (0.10858048820000001 * fTemp53))) + (fConst5 * (0.0 - ((fConst31 * fRec2752[1]) + (fConst30 * fRec2749[1]))))));
			fRec2754[0] = (fRec2754[1] + fTemp582);
			fRec2752[0] = fRec2754[0];
			double fRec2753 = fTemp582;
			fRec2751[0] = (fRec2752[0] + fRec2751[1]);
			fRec2749[0] = fRec2751[0];
			double fRec2750 = fRec2753;
			double fTemp583 = (fConst32 * (((0.086360519100000005 * fTemp56) - ((0.035053516799999997 * fTemp57) + (0.0016977392 * fTemp58))) - (fConst33 * fRec2755[1])));
			fRec2757[0] = (fRec2757[1] + fTemp583);
			fRec2755[0] = fRec2757[0];
			double fRec2756 = fTemp583;
			double fTemp584 = (fConst12 * (0.0 - ((fConst14 * fRec2761[1]) + (fConst13 * fRec2758[1]))));
			double fTemp585 = (fConst16 * (0.0 - ((fConst18 * fRec2767[1]) + (fConst17 * fRec2764[1]))));
			double fTemp586 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec2773[1]) + (fConst20 * fRec2770[1])))) + (fConst22 * (((0.0113292563 * fTemp32) + ((((0.00079656430000000003 * fTemp36) + (0.00043183989999999998 * fTemp29)) + (0.00051354150000000002 * fTemp31)) + (0.0092846531 * fTemp38))) - ((0.0011148716999999999 * fTemp33) + ((0.092692702500000002 * fTemp34) + ((0.0141459467 * fTemp35) + (((((0.0112898815 * fTemp37) + (0.025080271000000001 * fTemp27)) + (0.0154672647 * fTemp28)) + (0.0260850041 * fTemp30)) + (0.1119284641 * fTemp39)))))))));
			fRec2775[0] = (fRec2775[1] + fTemp586);
			fRec2773[0] = fRec2775[0];
			double fRec2774 = fTemp586;
			fRec2772[0] = (fRec2773[0] + fRec2772[1]);
			fRec2770[0] = fRec2772[0];
			double fRec2771 = fRec2774;
			fRec2769[0] = (fTemp585 + (fRec2771 + fRec2769[1]));
			fRec2767[0] = fRec2769[0];
			double fRec2768 = (fRec2771 + fTemp585);
			fRec2766[0] = (fRec2767[0] + fRec2766[1]);
			fRec2764[0] = fRec2766[0];
			double fRec2765 = fRec2768;
			fRec2763[0] = (fTemp584 + (fRec2765 + fRec2763[1]));
			fRec2761[0] = fRec2763[0];
			double fRec2762 = (fRec2765 + fTemp584);
			fRec2760[0] = (fRec2761[0] + fRec2760[1]);
			fRec2758[0] = fRec2760[0];
			double fRec2759 = fRec2762;
			fVec41[(IOTA & 1023)] = (((0.024929448399999998 * fTemp7) + ((0.082962847899999997 * fTemp75) + ((0.0002073993 * fTemp9) + ((0.0020575369999999999 * fTemp10) + ((0.014793967 * fTemp76) + ((0.010223490599999999 * fTemp77) + ((0.0004499026 * fTemp11) + ((0.0151177919 * fTemp79) + ((0.00088415200000000003 * fTemp74) + ((0.033327394599999997 * fTemp13) + (fRec2714 + (fRec2729 + (fRec2741 + (fRec2750 + (fRec2756 + (fRec2759 + (0.015075780699999999 * fTemp82))))))))))))))))) - (((0.099215400800000006 * fTemp78) + (((0.00019402239999999999 * fTemp81) + (0.032278005700000001 * fTemp80)) + (0.0200080313 * fTemp12))) + (0.0013906922999999999 * fTemp8)));
			output42[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec41[((IOTA - iConst44) & 1023)])));
			double fTemp587 = (fConst12 * (0.0 - ((fConst14 * fRec2779[1]) + (fConst13 * fRec2776[1]))));
			double fTemp588 = (fConst16 * (0.0 - ((fConst18 * fRec2785[1]) + (fConst17 * fRec2782[1]))));
			double fTemp589 = (fConst19 * ((fConst5 * (0.0 - ((fConst21 * fRec2791[1]) + (fConst20 * fRec2788[1])))) + (fConst22 * (((0.0174749233 * fTemp33) + ((0.022812093700000001 * fTemp34) + ((0.091802604100000004 * fTemp35) + ((0.0016080177 * fTemp32) + (0.065067277600000001 * fTemp39))))) - ((((((((0.011689487599999999 * fTemp36) + (0.0054948599000000002 * fTemp37)) + (0.024244099500000001 * fTemp27)) + (0.0153657849 * fTemp28)) + (0.0091481523999999998 * fTemp29)) + (0.019495320300000001 * fTemp30)) + (0.0102559404 * fTemp31)) + (0.090882115999999999 * fTemp38))))));
			fRec2793[0] = (fRec2793[1] + fTemp589);
			fRec2791[0] = fRec2793[0];
			double fRec2792 = fTemp589;
			fRec2790[0] = (fRec2791[0] + fRec2790[1]);
			fRec2788[0] = fRec2790[0];
			double fRec2789 = fRec2792;
			fRec2787[0] = (fTemp588 + (fRec2789 + fRec2787[1]));
			fRec2785[0] = fRec2787[0];
			double fRec2786 = (fRec2789 + fTemp588);
			fRec2784[0] = (fRec2785[0] + fRec2784[1]);
			fRec2782[0] = fRec2784[0];
			double fRec2783 = fRec2786;
			fRec2781[0] = (fTemp587 + (fRec2783 + fRec2781[1]));
			fRec2779[0] = fRec2781[0];
			double fRec2780 = (fRec2783 + fTemp587);
			fRec2778[0] = (fRec2779[0] + fRec2778[1]);
			fRec2776[0] = fRec2778[0];
			double fRec2777 = fRec2780;
			double fTemp590 = (fConst35 * (0.0 - ((fConst37 * fRec2800[1]) + (fConst36 * fRec2797[1]))));
			double fTemp591 = (fConst38 * ((fConst42 * ((((0.098701813200000002 * fTemp61) + (((0.016952188600000001 * fTemp67) + (0.017879387600000001 * fTemp68)) + (0.0068476869999999999 * fTemp63))) + (0.1177098412 * fTemp71)) - (((0.0024804943999999999 * fTemp65) + ((0.030090076899999998 * fTemp66) + (((0.0205588409 * fTemp62) + (0.0191887221 * fTemp69)) + (0.0043632295999999999 * fTemp64)))) + (0.0117284768 * fTemp70)))) + (fConst5 * (0.0 - ((fConst40 * fRec2806[1]) + (fConst39 * fRec2803[1]))))));
			fRec2808[0] = (fRec2808[1] + fTemp591);
			fRec2806[0] = fRec2808[0];
			double fRec2807 = fTemp591;
			fRec2805[0] = (fRec2806[0] + fRec2805[1]);
			fRec2803[0] = fRec2805[0];
			double fRec2804 = fRec2807;
			fRec2802[0] = (fTemp590 + (fRec2804 + fRec2802[1]));
			fRec2800[0] = fRec2802[0];
			double fRec2801 = (fRec2804 + fTemp590);
			fRec2799[0] = (fRec2800[0] + fRec2799[1]);
			fRec2797[0] = fRec2799[0];
			double fRec2798 = fRec2801;
			double fTemp592 = (fConst43 * fRec2794[1]);
			fRec2796[0] = ((fRec2798 + fRec2796[1]) - fTemp592);
			fRec2794[0] = fRec2796[0];
			double fRec2795 = (fRec2798 - fTemp592);
			double fTemp593 = (fConst8 * (0.0 - ((fConst10 * fRec2812[1]) + (fConst9 * fRec2809[1]))));
			double fTemp594 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec2818[1]) + (fConst6 * fRec2815[1])))) + (fConst4 * (((0.0042512862 * fTemp17) + ((0.010129830500000001 * fTemp16) + ((0.088005270400000002 * fTemp19) + ((0.014887686400000001 * fTemp20) + ((0.046021255499999997 * fTemp15) + ((0.039251706099999999 * fTemp21) + (0.0143446081 * fTemp22))))))) - ((0.1241702984 * fTemp14) + (0.0039344007 * fTemp18))))));
			fRec2820[0] = (fRec2820[1] + fTemp594);
			fRec2818[0] = fRec2820[0];
			double fRec2819 = fTemp594;
			fRec2817[0] = (fRec2818[0] + fRec2817[1]);
			fRec2815[0] = fRec2817[0];
			double fRec2816 = fRec2819;
			fRec2814[0] = (fTemp593 + (fRec2816 + fRec2814[1]));
			fRec2812[0] = fRec2814[0];
			double fRec2813 = (fRec2816 + fTemp593);
			fRec2811[0] = (fRec2812[0] + fRec2811[1]);
			fRec2809[0] = fRec2811[0];
			double fRec2810 = fRec2813;
			double fTemp595 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec2827[1]) + (fConst26 * fRec2824[1])))) + (fConst25 * (((0.0424463983 * fTemp44) + (0.068959401700000006 * fTemp43)) - ((0.056140290400000001 * fTemp41) + ((0.0077010723999999999 * fTemp45) + ((0.020110795899999999 * fTemp46) + ((0.061193656499999999 * fTemp42) + (0.1079479191 * fTemp47)))))))));
			fRec2829[0] = (fRec2829[1] + fTemp595);
			fRec2827[0] = fRec2829[0];
			double fRec2828 = fTemp595;
			fRec2826[0] = (fRec2827[0] + fRec2826[1]);
			fRec2824[0] = fRec2826[0];
			double fRec2825 = fRec2828;
			double fTemp596 = (fConst28 * fRec2821[1]);
			fRec2823[0] = ((fRec2825 + fRec2823[1]) - fTemp596);
			fRec2821[0] = fRec2823[0];
			double fRec2822 = (fRec2825 - fTemp596);
			double fTemp597 = (fConst32 * ((((0.081848376400000006 * fTemp56) + (0.031132243 * fTemp58)) - (0.035705976 * fTemp57)) - (fConst33 * fRec2830[1])));
			fRec2832[0] = (fRec2832[1] + fTemp597);
			fRec2830[0] = fRec2832[0];
			double fRec2831 = fTemp597;
			double fTemp598 = (fConst29 * (((0.073120721400000005 * fTemp50) - ((((0.071655394799999994 * fTemp51) + (0.031363623100000002 * fTemp54)) + (0.0272042524 * fTemp52)) + (0.082173226299999999 * fTemp53))) + (fConst5 * (0.0 - ((fConst31 * fRec2836[1]) + (fConst30 * fRec2833[1]))))));
			fRec2838[0] = (fRec2838[1] + fTemp598);
			fRec2836[0] = fRec2838[0];
			double fRec2837 = fTemp598;
			fRec2835[0] = (fRec2836[0] + fRec2835[1]);
			fRec2833[0] = fRec2835[0];
			double fRec2834 = fRec2837;
			fVec42[(IOTA & 1023)] = (((0.0193206392 * fTemp7) + ((0.014804870899999999 * fTemp8) + ((0.00022780749999999999 * fTemp9) + ((0.0828234833 * fTemp78) + (((0.033821688199999998 * fTemp13) + (fRec2777 + (fRec2795 + (fRec2810 + (fRec2822 + (fRec2831 + fRec2834)))))) + (0.0155963539 * fTemp79)))))) - ((0.047921787399999999 * fTemp75) + ((0.028841016600000002 * fTemp10) + ((0.0034719668999999998 * fTemp76) + ((0.068396658099999993 * fTemp77) + ((0.0071139751999999999 * fTemp11) + ((0.018496182900000002 * fTemp12) + ((0.0170088407 * fTemp74) + ((0.0148440529 * fTemp80) + ((0.00032448619999999998 * fTemp81) + (0.055020214300000002 * fTemp82)))))))))));
			output43[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec42[((IOTA - iConst44) & 1023)])));
			double fTemp599 = (fConst35 * (0.0 - ((fConst37 * fRec2845[1]) + (fConst36 * fRec2842[1]))));
			double fTemp600 = (fConst38 * ((fConst42 * ((((0.0028077201000000001 * fTemp65) + ((0.010246589400000001 * fTemp61) + (((0.025002578599999999 * fTemp67) + (0.014054109699999999 * fTemp68)) + (0.0133822104 * fTemp63)))) + (0.097904613599999996 * fTemp70)) - (((0.096253844699999994 * fTemp66) + (((0.020043353199999999 * fTemp62) + (0.0012832570999999999 * fTemp69)) + (0.0034272063 * fTemp64))) + (0.074096782599999994 * fTemp71)))) + (fConst5 * (0.0 - ((fConst40 * fRec2851[1]) + (fConst39 * fRec2848[1]))))));
			fRec2853[0] = (fRec2853[1] + fTemp600);
			fRec2851[0] = fRec2853[0];
			double fRec2852 = fTemp600;
			fRec2850[0] = (fRec2851[0] + fRec2850[1]);
			fRec2848[0] = fRec2850[0];
			double fRec2849 = fRec2852;
			fRec2847[0] = (fTemp599 + (fRec2849 + fRec2847[1]));
			fRec2845[0] = fRec2847[0];
			double fRec2846 = (fRec2849 + fTemp599);
			fRec2844[0] = (fRec2845[0] + fRec2844[1]);
			fRec2842[0] = fRec2844[0];
			double fRec2843 = fRec2846;
			double fTemp601 = (fConst43 * fRec2839[1]);
			fRec2841[0] = ((fRec2843 + fRec2841[1]) - fTemp601);
			fRec2839[0] = fRec2841[0];
			double fRec2840 = (fRec2843 - fTemp601);
			double fTemp602 = (fConst23 * ((fConst5 * (0.0 - ((fConst27 * fRec2860[1]) + (fConst26 * fRec2857[1])))) + (fConst25 * (((0.041763714100000002 * fTemp44) + ((0.078690439900000006 * fTemp41) + (0.0046966083999999998 * fTemp43))) - ((0.0150048179 * fTemp45) + ((0.015760371200000001 * fTemp46) + ((0.09078485 * fTemp42) + (0.091834241999999996 * fTemp47))))))));
			fRec2862[0] = (fRec2862[1] + fTemp602);
			fRec2860[0] = fRec2862[0];
			double fRec2861 = fTemp602;
			fRec2859[0] = (fRec2860[0] + fRec2859[1]);
			fRec2857[0] = fRec2859[0];
			double fRec2858 = fRec2861;
			double fTemp603 = (fConst28 * fRec2854[1]);
			fRec2856[0] = ((fRec2858 + fRec2856[1]) - fTemp603);
			fRec2854[0] = fRec2856[0];
			double fRec2855 = (fRec2858 - fTemp603);
			double fTemp604 = (fConst29 * (((0.1089713154 * fTemp50) - ((((0.054748380399999998 * fTemp51) + (0.031249748899999999 * fTemp54)) + (0.051994365600000002 * fTemp52)) + (0.0055815854000000002 * fTemp53))) + (fConst5 * (0.0 - ((fConst31 * fRec2866[1]) + (fConst30 * fRec2863[1]))))));
			fRec2868[0] = (fRec2868[1] + fTemp604);
			fRec2866[0] = fRec2868[0];
			double fRec2867 = fTemp604;
			fRec2865[0] = (fRec2866[0] + fRec2865[1]);
			fRec2863[0] = fRec2865[0];
			double fRec2864 = fRec2867;
			double fTemp605 = (fConst32 * ((((0.062885901499999994 * fTemp56) + (0.059749737599999998 * fTemp58)) - (0.035164316100000002 * fTemp57)) - (fConst33 * fRec2869[1])));
			fRec2871[0] = (fRec2871[1] + fTemp605);
			fRec2869[0] = fRec2871[0];
			double fRec2870 = fTemp605;
			double fTemp606 = (fConst12 * (0.0 - ((fConst14 * fRec2875[1]) + (fConst13 * fRec2872[1]))));
			double fTemp607 = (fConst16 * (0.0 - ((fConst18 * fRec2881[1]) + (fConst17 * fRec2878[1]))));
			double fTemp608 = (fConst19 * ((fConst22 * (((0.026340291799999999 * fTemp33) + ((0.073936910999999994 * fTemp34) + (((0.0073087984999999998 * fTemp37) + (0.056678541499999999 * fTemp38)) + (0.017587681000000001 * fTemp39)))) - ((0.1115819327 * fTemp35) + (((((((0.0012949808000000001 * fTemp36) + (0.0182190211 * fTemp27)) + (0.0155552919 * fTemp28)) + (0.017311111600000002 * fTemp29)) + (0.0013191589000000001 * fTemp30)) + (0.0085243711000000007 * fTemp31)) + (0.0111466981 * fTemp32))))) + (fConst5 * (0.0 - ((fConst21 * fRec2887[1]) + (fConst20 * fRec2884[1]))))));
			fRec2889[0] = (fRec2889[1] + fTemp608);
			fRec2887[0] = fRec2889[0];
			double fRec2888 = fTemp608;
			fRec2886[0] = (fRec2887[0] + fRec2886[1]);
			fRec2884[0] = fRec2886[0];
			double fRec2885 = fRec2888;
			fRec2883[0] = (fTemp607 + (fRec2885 + fRec2883[1]));
			fRec2881[0] = fRec2883[0];
			double fRec2882 = (fRec2885 + fTemp607);
			fRec2880[0] = (fRec2881[0] + fRec2880[1]);
			fRec2878[0] = fRec2880[0];
			double fRec2879 = fRec2882;
			fRec2877[0] = (fTemp606 + (fRec2879 + fRec2877[1]));
			fRec2875[0] = fRec2877[0];
			double fRec2876 = (fRec2879 + fTemp606);
			fRec2874[0] = (fRec2875[0] + fRec2874[1]);
			fRec2872[0] = fRec2874[0];
			double fRec2873 = fRec2876;
			double fTemp609 = (fConst8 * (0.0 - ((fConst10 * fRec2893[1]) + (fConst9 * fRec2890[1]))));
			double fTemp610 = (fConst2 * ((fConst4 * (((0.000263661 * fTemp17) + ((0.010351217399999999 * fTemp16) + (((0.029886265799999999 * fTemp21) + (0.028387725900000001 * fTemp20)) + (0.074542319600000004 * fTemp19)))) - ((0.0062580952999999996 * fTemp18) + ((0.063761432699999995 * fTemp15) + ((0.012799093500000001 * fTemp14) + (0.1239022935 * fTemp22)))))) + (fConst5 * (0.0 - ((fConst7 * fRec2899[1]) + (fConst6 * fRec2896[1]))))));
			fRec2901[0] = (fRec2901[1] + fTemp610);
			fRec2899[0] = fRec2901[0];
			double fRec2900 = fTemp610;
			fRec2898[0] = (fRec2899[0] + fRec2898[1]);
			fRec2896[0] = fRec2898[0];
			double fRec2897 = fRec2900;
			fRec2895[0] = (fTemp609 + (fRec2897 + fRec2895[1]));
			fRec2893[0] = fRec2895[0];
			double fRec2894 = (fRec2897 + fTemp609);
			fRec2892[0] = (fRec2893[0] + fRec2892[1]);
			fRec2890[0] = fRec2892[0];
			double fRec2891 = fRec2894;
			fVec43[(IOTA & 1023)] = (((0.0012840225000000001 * fTemp7) + ((0.082433508500000002 * fTemp77) + ((0.0150045257 * fTemp79) + ((0.021227905799999999 * fTemp80) + ((1.5551999999999999e-06 * fTemp81) + ((0.033472444300000001 * fTemp13) + (fRec2840 + (fRec2855 + (fRec2864 + (fRec2870 + (fRec2873 + (fRec2891 + (0.082728342799999993 * fTemp82))))))))))))) - ((((((0.0118034648 * fTemp76) + ((0.0567439104 * fTemp78) + (((0.0249055688 * fTemp74) + (0.0146102253 * fTemp12)) + (0.0138965371 * fTemp11)))) + (0.024726095 * fTemp10)) + (7.5844200000000001e-05 * fTemp9)) + (0.0088477241000000009 * fTemp8)) + (0.013253296600000001 * fTemp75)));
			output44[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec43[((IOTA - iConst44) & 1023)])));
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
			fRec21[1] = fRec21[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec16[1] = fRec16[0];
			fRec15[1] = fRec15[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec10[1] = fRec10[0];
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
			fRec60[2] = fRec60[1];
			fRec60[1] = fRec60[0];
			fRec61[2] = fRec61[1];
			fRec61[1] = fRec61[0];
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
			fRec70[1] = fRec70[0];
			fRec68[1] = fRec68[0];
			fRec67[1] = fRec67[0];
			fRec65[1] = fRec65[0];
			fRec64[1] = fRec64[0];
			fRec62[1] = fRec62[0];
			fRec84[2] = fRec84[1];
			fRec84[1] = fRec84[0];
			fRec85[2] = fRec85[1];
			fRec85[1] = fRec85[0];
			fRec86[2] = fRec86[1];
			fRec86[1] = fRec86[0];
			fRec87[2] = fRec87[1];
			fRec87[1] = fRec87[0];
			fRec88[2] = fRec88[1];
			fRec88[1] = fRec88[0];
			fRec83[1] = fRec83[0];
			fRec81[1] = fRec81[0];
			fRec80[1] = fRec80[0];
			fRec78[1] = fRec78[0];
			fRec92[2] = fRec92[1];
			fRec92[1] = fRec92[0];
			fRec93[2] = fRec93[1];
			fRec93[1] = fRec93[0];
			fRec94[2] = fRec94[1];
			fRec94[1] = fRec94[0];
			fRec91[1] = fRec91[0];
			fRec89[1] = fRec89[0];
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
			fRec119[2] = fRec119[1];
			fRec119[1] = fRec119[0];
			fRec120[2] = fRec120[1];
			fRec120[1] = fRec120[0];
			fRec109[1] = fRec109[0];
			fRec107[1] = fRec107[0];
			fRec106[1] = fRec106[0];
			fRec104[1] = fRec104[0];
			fRec103[1] = fRec103[0];
			fRec101[1] = fRec101[0];
			fRec100[1] = fRec100[0];
			fRec98[1] = fRec98[0];
			fRec97[1] = fRec97[0];
			fRec95[1] = fRec95[0];
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
			fRec141[1] = fRec141[0];
			fRec139[1] = fRec139[0];
			fRec138[1] = fRec138[0];
			fRec136[1] = fRec136[0];
			fRec135[1] = fRec135[0];
			fRec133[1] = fRec133[0];
			fRec132[1] = fRec132[0];
			fRec130[1] = fRec130[0];
			fRec150[1] = fRec150[0];
			fRec148[1] = fRec148[0];
			fRec147[1] = fRec147[0];
			fRec145[1] = fRec145[0];
			fRec144[1] = fRec144[0];
			fRec142[1] = fRec142[0];
			fRec156[1] = fRec156[0];
			fRec154[1] = fRec154[0];
			fRec153[1] = fRec153[0];
			fRec151[1] = fRec151[0];
			fRec159[1] = fRec159[0];
			fRec157[1] = fRec157[0];
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
			fRec219[1] = fRec219[0];
			fRec217[1] = fRec217[0];
			fRec216[1] = fRec216[0];
			fRec214[1] = fRec214[0];
			fRec213[1] = fRec213[0];
			fRec211[1] = fRec211[0];
			fRec210[1] = fRec210[0];
			fRec208[1] = fRec208[0];
			fRec228[1] = fRec228[0];
			fRec226[1] = fRec226[0];
			fRec225[1] = fRec225[0];
			fRec223[1] = fRec223[0];
			fRec222[1] = fRec222[0];
			fRec220[1] = fRec220[0];
			fRec234[1] = fRec234[0];
			fRec232[1] = fRec232[0];
			fRec231[1] = fRec231[0];
			fRec229[1] = fRec229[0];
			fRec237[1] = fRec237[0];
			fRec235[1] = fRec235[0];
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
			fRec264[1] = fRec264[0];
			fRec262[1] = fRec262[0];
			fRec261[1] = fRec261[0];
			fRec259[1] = fRec259[0];
			fRec258[1] = fRec258[0];
			fRec256[1] = fRec256[0];
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
			fRec267[1] = fRec267[0];
			fRec265[1] = fRec265[0];
			fRec297[1] = fRec297[0];
			fRec295[1] = fRec295[0];
			fRec294[1] = fRec294[0];
			fRec292[1] = fRec292[0];
			fRec291[1] = fRec291[0];
			fRec289[1] = fRec289[0];
			fRec288[1] = fRec288[0];
			fRec286[1] = fRec286[0];
			fRec285[1] = fRec285[0];
			fRec283[1] = fRec283[0];
			fRec309[1] = fRec309[0];
			fRec307[1] = fRec307[0];
			fRec306[1] = fRec306[0];
			fRec304[1] = fRec304[0];
			fRec303[1] = fRec303[0];
			fRec301[1] = fRec301[0];
			fRec300[1] = fRec300[0];
			fRec298[1] = fRec298[0];
			fRec312[1] = fRec312[0];
			fRec310[1] = fRec310[0];
			fRec318[1] = fRec318[0];
			fRec316[1] = fRec316[0];
			fRec315[1] = fRec315[0];
			fRec313[1] = fRec313[0];
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
			fRec336[1] = fRec336[0];
			fRec334[1] = fRec334[0];
			fRec342[1] = fRec342[0];
			fRec340[1] = fRec340[0];
			fRec354[1] = fRec354[0];
			fRec352[1] = fRec352[0];
			fRec351[1] = fRec351[0];
			fRec349[1] = fRec349[0];
			fRec348[1] = fRec348[0];
			fRec346[1] = fRec346[0];
			fRec345[1] = fRec345[0];
			fRec343[1] = fRec343[0];
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
			fRec366[1] = fRec366[0];
			fRec364[1] = fRec364[0];
			fRec387[1] = fRec387[0];
			fRec385[1] = fRec385[0];
			fRec384[1] = fRec384[0];
			fRec382[1] = fRec382[0];
			fRec390[1] = fRec390[0];
			fRec388[1] = fRec388[0];
			fRec408[1] = fRec408[0];
			fRec406[1] = fRec406[0];
			fRec405[1] = fRec405[0];
			fRec403[1] = fRec403[0];
			fRec402[1] = fRec402[0];
			fRec400[1] = fRec400[0];
			fRec399[1] = fRec399[0];
			fRec397[1] = fRec397[0];
			fRec396[1] = fRec396[0];
			fRec394[1] = fRec394[0];
			fRec393[1] = fRec393[0];
			fRec391[1] = fRec391[0];
			fRec423[1] = fRec423[0];
			fRec421[1] = fRec421[0];
			fRec420[1] = fRec420[0];
			fRec418[1] = fRec418[0];
			fRec417[1] = fRec417[0];
			fRec415[1] = fRec415[0];
			fRec414[1] = fRec414[0];
			fRec412[1] = fRec412[0];
			fRec411[1] = fRec411[0];
			fRec409[1] = fRec409[0];
			fRec432[1] = fRec432[0];
			fRec430[1] = fRec430[0];
			fRec429[1] = fRec429[0];
			fRec427[1] = fRec427[0];
			fRec426[1] = fRec426[0];
			fRec424[1] = fRec424[0];
			fRec444[1] = fRec444[0];
			fRec442[1] = fRec442[0];
			fRec441[1] = fRec441[0];
			fRec439[1] = fRec439[0];
			fRec438[1] = fRec438[0];
			fRec436[1] = fRec436[0];
			fRec435[1] = fRec435[0];
			fRec433[1] = fRec433[0];
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
			fRec504[1] = fRec504[0];
			fRec502[1] = fRec502[0];
			fRec501[1] = fRec501[0];
			fRec499[1] = fRec499[0];
			fRec507[1] = fRec507[0];
			fRec505[1] = fRec505[0];
			fRec519[1] = fRec519[0];
			fRec517[1] = fRec517[0];
			fRec516[1] = fRec516[0];
			fRec514[1] = fRec514[0];
			fRec513[1] = fRec513[0];
			fRec511[1] = fRec511[0];
			fRec510[1] = fRec510[0];
			fRec508[1] = fRec508[0];
			fRec528[1] = fRec528[0];
			fRec526[1] = fRec526[0];
			fRec525[1] = fRec525[0];
			fRec523[1] = fRec523[0];
			fRec522[1] = fRec522[0];
			fRec520[1] = fRec520[0];
			fRec534[1] = fRec534[0];
			fRec532[1] = fRec532[0];
			fRec531[1] = fRec531[0];
			fRec529[1] = fRec529[0];
			fRec537[1] = fRec537[0];
			fRec535[1] = fRec535[0];
			fRec552[1] = fRec552[0];
			fRec550[1] = fRec550[0];
			fRec549[1] = fRec549[0];
			fRec547[1] = fRec547[0];
			fRec546[1] = fRec546[0];
			fRec544[1] = fRec544[0];
			fRec543[1] = fRec543[0];
			fRec541[1] = fRec541[0];
			fRec540[1] = fRec540[0];
			fRec538[1] = fRec538[0];
			fRec570[1] = fRec570[0];
			fRec568[1] = fRec568[0];
			fRec567[1] = fRec567[0];
			fRec565[1] = fRec565[0];
			fRec564[1] = fRec564[0];
			fRec562[1] = fRec562[0];
			fRec561[1] = fRec561[0];
			fRec559[1] = fRec559[0];
			fRec558[1] = fRec558[0];
			fRec556[1] = fRec556[0];
			fRec555[1] = fRec555[0];
			fRec553[1] = fRec553[0];
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
			fRec597[1] = fRec597[0];
			fRec595[1] = fRec595[0];
			fRec594[1] = fRec594[0];
			fRec592[1] = fRec592[0];
			fRec591[1] = fRec591[0];
			fRec589[1] = fRec589[0];
			fRec612[1] = fRec612[0];
			fRec610[1] = fRec610[0];
			fRec609[1] = fRec609[0];
			fRec607[1] = fRec607[0];
			fRec606[1] = fRec606[0];
			fRec604[1] = fRec604[0];
			fRec603[1] = fRec603[0];
			fRec601[1] = fRec601[0];
			fRec600[1] = fRec600[0];
			fRec598[1] = fRec598[0];
			fRec624[1] = fRec624[0];
			fRec622[1] = fRec622[0];
			fRec621[1] = fRec621[0];
			fRec619[1] = fRec619[0];
			fRec618[1] = fRec618[0];
			fRec616[1] = fRec616[0];
			fRec615[1] = fRec615[0];
			fRec613[1] = fRec613[0];
			fRec630[1] = fRec630[0];
			fRec628[1] = fRec628[0];
			fRec627[1] = fRec627[0];
			fRec625[1] = fRec625[0];
			fRec633[1] = fRec633[0];
			fRec631[1] = fRec631[0];
			fRec645[1] = fRec645[0];
			fRec643[1] = fRec643[0];
			fRec642[1] = fRec642[0];
			fRec640[1] = fRec640[0];
			fRec639[1] = fRec639[0];
			fRec637[1] = fRec637[0];
			fRec636[1] = fRec636[0];
			fRec634[1] = fRec634[0];
			fRec648[1] = fRec648[0];
			fRec646[1] = fRec646[0];
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
			fRec651[1] = fRec651[0];
			fRec649[1] = fRec649[0];
			fRec681[1] = fRec681[0];
			fRec679[1] = fRec679[0];
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
			fRec696[1] = fRec696[0];
			fRec694[1] = fRec694[0];
			fRec693[1] = fRec693[0];
			fRec691[1] = fRec691[0];
			fRec690[1] = fRec690[0];
			fRec688[1] = fRec688[0];
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
			fRec771[1] = fRec771[0];
			fRec769[1] = fRec769[0];
			fRec768[1] = fRec768[0];
			fRec766[1] = fRec766[0];
			fRec765[1] = fRec765[0];
			fRec763[1] = fRec763[0];
			fRec762[1] = fRec762[0];
			fRec760[1] = fRec760[0];
			fRec777[1] = fRec777[0];
			fRec775[1] = fRec775[0];
			fRec774[1] = fRec774[0];
			fRec772[1] = fRec772[0];
			fRec780[1] = fRec780[0];
			fRec778[1] = fRec778[0];
			fRec798[1] = fRec798[0];
			fRec796[1] = fRec796[0];
			fRec795[1] = fRec795[0];
			fRec793[1] = fRec793[0];
			fRec792[1] = fRec792[0];
			fRec790[1] = fRec790[0];
			fRec789[1] = fRec789[0];
			fRec787[1] = fRec787[0];
			fRec786[1] = fRec786[0];
			fRec784[1] = fRec784[0];
			fRec783[1] = fRec783[0];
			fRec781[1] = fRec781[0];
			fRec813[1] = fRec813[0];
			fRec811[1] = fRec811[0];
			fRec810[1] = fRec810[0];
			fRec808[1] = fRec808[0];
			fRec807[1] = fRec807[0];
			fRec805[1] = fRec805[0];
			fRec804[1] = fRec804[0];
			fRec802[1] = fRec802[0];
			fRec801[1] = fRec801[0];
			fRec799[1] = fRec799[0];
			fRec822[1] = fRec822[0];
			fRec820[1] = fRec820[0];
			fRec819[1] = fRec819[0];
			fRec817[1] = fRec817[0];
			fRec816[1] = fRec816[0];
			fRec814[1] = fRec814[0];
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
			fRec840[1] = fRec840[0];
			fRec838[1] = fRec838[0];
			fRec864[1] = fRec864[0];
			fRec862[1] = fRec862[0];
			fRec861[1] = fRec861[0];
			fRec859[1] = fRec859[0];
			fRec858[1] = fRec858[0];
			fRec856[1] = fRec856[0];
			fRec870[1] = fRec870[0];
			fRec868[1] = fRec868[0];
			fRec867[1] = fRec867[0];
			fRec865[1] = fRec865[0];
			fRec873[1] = fRec873[0];
			fRec871[1] = fRec871[0];
			fRec885[1] = fRec885[0];
			fRec883[1] = fRec883[0];
			fRec882[1] = fRec882[0];
			fRec880[1] = fRec880[0];
			fRec879[1] = fRec879[0];
			fRec877[1] = fRec877[0];
			fRec876[1] = fRec876[0];
			fRec874[1] = fRec874[0];
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
			fRec912[1] = fRec912[0];
			fRec910[1] = fRec910[0];
			fRec909[1] = fRec909[0];
			fRec907[1] = fRec907[0];
			fRec906[1] = fRec906[0];
			fRec904[1] = fRec904[0];
			fRec903[1] = fRec903[0];
			fRec901[1] = fRec901[0];
			fRec921[1] = fRec921[0];
			fRec919[1] = fRec919[0];
			fRec918[1] = fRec918[0];
			fRec916[1] = fRec916[0];
			fRec915[1] = fRec915[0];
			fRec913[1] = fRec913[0];
			fRec927[1] = fRec927[0];
			fRec925[1] = fRec925[0];
			fRec924[1] = fRec924[0];
			fRec922[1] = fRec922[0];
			fRec930[1] = fRec930[0];
			fRec928[1] = fRec928[0];
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
			fRec933[1] = fRec933[0];
			fRec931[1] = fRec931[0];
			fRec957[1] = fRec957[0];
			fRec955[1] = fRec955[0];
			fRec954[1] = fRec954[0];
			fRec952[1] = fRec952[0];
			fRec951[1] = fRec951[0];
			fRec949[1] = fRec949[0];
			fRec969[1] = fRec969[0];
			fRec967[1] = fRec967[0];
			fRec966[1] = fRec966[0];
			fRec964[1] = fRec964[0];
			fRec963[1] = fRec963[0];
			fRec961[1] = fRec961[0];
			fRec960[1] = fRec960[0];
			fRec958[1] = fRec958[0];
			fRec987[1] = fRec987[0];
			fRec985[1] = fRec985[0];
			fRec984[1] = fRec984[0];
			fRec982[1] = fRec982[0];
			fRec981[1] = fRec981[0];
			fRec979[1] = fRec979[0];
			fRec978[1] = fRec978[0];
			fRec976[1] = fRec976[0];
			fRec975[1] = fRec975[0];
			fRec973[1] = fRec973[0];
			fRec972[1] = fRec972[0];
			fRec970[1] = fRec970[0];
			fRec1002[1] = fRec1002[0];
			fRec1000[1] = fRec1000[0];
			fRec999[1] = fRec999[0];
			fRec997[1] = fRec997[0];
			fRec996[1] = fRec996[0];
			fRec994[1] = fRec994[0];
			fRec993[1] = fRec993[0];
			fRec991[1] = fRec991[0];
			fRec990[1] = fRec990[0];
			fRec988[1] = fRec988[0];
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
			fRec1071[1] = fRec1071[0];
			fRec1069[1] = fRec1069[0];
			fRec1068[1] = fRec1068[0];
			fRec1066[1] = fRec1066[0];
			fRec1074[1] = fRec1074[0];
			fRec1072[1] = fRec1072[0];
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
			fRec1116[1] = fRec1116[0];
			fRec1114[1] = fRec1114[0];
			fRec1113[1] = fRec1113[0];
			fRec1111[1] = fRec1111[0];
			fRec1110[1] = fRec1110[0];
			fRec1108[1] = fRec1108[0];
			fRec1122[1] = fRec1122[0];
			fRec1120[1] = fRec1120[0];
			fRec1119[1] = fRec1119[0];
			fRec1117[1] = fRec1117[0];
			fRec1125[1] = fRec1125[0];
			fRec1123[1] = fRec1123[0];
			fRec1137[1] = fRec1137[0];
			fRec1135[1] = fRec1135[0];
			fRec1134[1] = fRec1134[0];
			fRec1132[1] = fRec1132[0];
			fRec1131[1] = fRec1131[0];
			fRec1129[1] = fRec1129[0];
			fRec1128[1] = fRec1128[0];
			fRec1126[1] = fRec1126[0];
			fRec1143[1] = fRec1143[0];
			fRec1141[1] = fRec1141[0];
			fRec1140[1] = fRec1140[0];
			fRec1138[1] = fRec1138[0];
			fRec1161[1] = fRec1161[0];
			fRec1159[1] = fRec1159[0];
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
			fRec1173[1] = fRec1173[0];
			fRec1171[1] = fRec1171[0];
			fRec1170[1] = fRec1170[0];
			fRec1168[1] = fRec1168[0];
			fRec1167[1] = fRec1167[0];
			fRec1165[1] = fRec1165[0];
			fRec1164[1] = fRec1164[0];
			fRec1162[1] = fRec1162[0];
			fRec1182[1] = fRec1182[0];
			fRec1180[1] = fRec1180[0];
			fRec1179[1] = fRec1179[0];
			fRec1177[1] = fRec1177[0];
			fRec1176[1] = fRec1176[0];
			fRec1174[1] = fRec1174[0];
			fRec1185[1] = fRec1185[0];
			fRec1183[1] = fRec1183[0];
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
			fRec1248[1] = fRec1248[0];
			fRec1246[1] = fRec1246[0];
			fRec1254[1] = fRec1254[0];
			fRec1252[1] = fRec1252[0];
			fRec1251[1] = fRec1251[0];
			fRec1249[1] = fRec1249[0];
			fRec1263[1] = fRec1263[0];
			fRec1261[1] = fRec1261[0];
			fRec1260[1] = fRec1260[0];
			fRec1258[1] = fRec1258[0];
			fRec1257[1] = fRec1257[0];
			fRec1255[1] = fRec1255[0];
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
			fRec1332[1] = fRec1332[0];
			fRec1330[1] = fRec1330[0];
			fRec1329[1] = fRec1329[0];
			fRec1327[1] = fRec1327[0];
			fRec1335[1] = fRec1335[0];
			fRec1333[1] = fRec1333[0];
			fRec1353[1] = fRec1353[0];
			fRec1351[1] = fRec1351[0];
			fRec1350[1] = fRec1350[0];
			fRec1348[1] = fRec1348[0];
			fRec1347[1] = fRec1347[0];
			fRec1345[1] = fRec1345[0];
			fRec1344[1] = fRec1344[0];
			fRec1342[1] = fRec1342[0];
			fRec1341[1] = fRec1341[0];
			fRec1339[1] = fRec1339[0];
			fRec1338[1] = fRec1338[0];
			fRec1336[1] = fRec1336[0];
			fRec1368[1] = fRec1368[0];
			fRec1366[1] = fRec1366[0];
			fRec1365[1] = fRec1365[0];
			fRec1363[1] = fRec1363[0];
			fRec1362[1] = fRec1362[0];
			fRec1360[1] = fRec1360[0];
			fRec1359[1] = fRec1359[0];
			fRec1357[1] = fRec1357[0];
			fRec1356[1] = fRec1356[0];
			fRec1354[1] = fRec1354[0];
			fRec1380[1] = fRec1380[0];
			fRec1378[1] = fRec1378[0];
			fRec1377[1] = fRec1377[0];
			fRec1375[1] = fRec1375[0];
			fRec1374[1] = fRec1374[0];
			fRec1372[1] = fRec1372[0];
			fRec1371[1] = fRec1371[0];
			fRec1369[1] = fRec1369[0];
			fRec1389[1] = fRec1389[0];
			fRec1387[1] = fRec1387[0];
			fRec1386[1] = fRec1386[0];
			fRec1384[1] = fRec1384[0];
			fRec1383[1] = fRec1383[0];
			fRec1381[1] = fRec1381[0];
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
			fRec1449[1] = fRec1449[0];
			fRec1447[1] = fRec1447[0];
			fRec1446[1] = fRec1446[0];
			fRec1444[1] = fRec1444[0];
			fRec1452[1] = fRec1452[0];
			fRec1450[1] = fRec1450[0];
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
			fRec1497[1] = fRec1497[0];
			fRec1495[1] = fRec1495[0];
			fRec1494[1] = fRec1494[0];
			fRec1492[1] = fRec1492[0];
			fRec1500[1] = fRec1500[0];
			fRec1498[1] = fRec1498[0];
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
			fRec1575[1] = fRec1575[0];
			fRec1573[1] = fRec1573[0];
			fRec1572[1] = fRec1572[0];
			fRec1570[1] = fRec1570[0];
			fRec1578[1] = fRec1578[0];
			fRec1576[1] = fRec1576[0];
			fRec1590[1] = fRec1590[0];
			fRec1588[1] = fRec1588[0];
			fRec1587[1] = fRec1587[0];
			fRec1585[1] = fRec1585[0];
			fRec1584[1] = fRec1584[0];
			fRec1582[1] = fRec1582[0];
			fRec1581[1] = fRec1581[0];
			fRec1579[1] = fRec1579[0];
			fRec1599[1] = fRec1599[0];
			fRec1597[1] = fRec1597[0];
			fRec1596[1] = fRec1596[0];
			fRec1594[1] = fRec1594[0];
			fRec1593[1] = fRec1593[0];
			fRec1591[1] = fRec1591[0];
			fRec1617[1] = fRec1617[0];
			fRec1615[1] = fRec1615[0];
			fRec1614[1] = fRec1614[0];
			fRec1612[1] = fRec1612[0];
			fRec1611[1] = fRec1611[0];
			fRec1609[1] = fRec1609[0];
			fRec1608[1] = fRec1608[0];
			fRec1606[1] = fRec1606[0];
			fRec1605[1] = fRec1605[0];
			fRec1603[1] = fRec1603[0];
			fRec1602[1] = fRec1602[0];
			fRec1600[1] = fRec1600[0];
			fRec1623[1] = fRec1623[0];
			fRec1621[1] = fRec1621[0];
			fRec1620[1] = fRec1620[0];
			fRec1618[1] = fRec1618[0];
			fRec1626[1] = fRec1626[0];
			fRec1624[1] = fRec1624[0];
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
			fRec1644[1] = fRec1644[0];
			fRec1642[1] = fRec1642[0];
			fRec1662[1] = fRec1662[0];
			fRec1660[1] = fRec1660[0];
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
			fRec1677[1] = fRec1677[0];
			fRec1675[1] = fRec1675[0];
			fRec1674[1] = fRec1674[0];
			fRec1672[1] = fRec1672[0];
			fRec1671[1] = fRec1671[0];
			fRec1669[1] = fRec1669[0];
			fRec1668[1] = fRec1668[0];
			fRec1666[1] = fRec1666[0];
			fRec1665[1] = fRec1665[0];
			fRec1663[1] = fRec1663[0];
			fRec1686[1] = fRec1686[0];
			fRec1684[1] = fRec1684[0];
			fRec1683[1] = fRec1683[0];
			fRec1681[1] = fRec1681[0];
			fRec1680[1] = fRec1680[0];
			fRec1678[1] = fRec1678[0];
			fRec1692[1] = fRec1692[0];
			fRec1690[1] = fRec1690[0];
			fRec1689[1] = fRec1689[0];
			fRec1687[1] = fRec1687[0];
			fRec1704[1] = fRec1704[0];
			fRec1702[1] = fRec1702[0];
			fRec1701[1] = fRec1701[0];
			fRec1699[1] = fRec1699[0];
			fRec1698[1] = fRec1698[0];
			fRec1696[1] = fRec1696[0];
			fRec1695[1] = fRec1695[0];
			fRec1693[1] = fRec1693[0];
			fRec1716[1] = fRec1716[0];
			fRec1714[1] = fRec1714[0];
			fRec1713[1] = fRec1713[0];
			fRec1711[1] = fRec1711[0];
			fRec1710[1] = fRec1710[0];
			fRec1708[1] = fRec1708[0];
			fRec1707[1] = fRec1707[0];
			fRec1705[1] = fRec1705[0];
			fRec1725[1] = fRec1725[0];
			fRec1723[1] = fRec1723[0];
			fRec1722[1] = fRec1722[0];
			fRec1720[1] = fRec1720[0];
			fRec1719[1] = fRec1719[0];
			fRec1717[1] = fRec1717[0];
			fRec1743[1] = fRec1743[0];
			fRec1741[1] = fRec1741[0];
			fRec1740[1] = fRec1740[0];
			fRec1738[1] = fRec1738[0];
			fRec1737[1] = fRec1737[0];
			fRec1735[1] = fRec1735[0];
			fRec1734[1] = fRec1734[0];
			fRec1732[1] = fRec1732[0];
			fRec1731[1] = fRec1731[0];
			fRec1729[1] = fRec1729[0];
			fRec1728[1] = fRec1728[0];
			fRec1726[1] = fRec1726[0];
			fRec1749[1] = fRec1749[0];
			fRec1747[1] = fRec1747[0];
			fRec1746[1] = fRec1746[0];
			fRec1744[1] = fRec1744[0];
			fRec1752[1] = fRec1752[0];
			fRec1750[1] = fRec1750[0];
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
			fRec1770[1] = fRec1770[0];
			fRec1768[1] = fRec1768[0];
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
			fRec1797[1] = fRec1797[0];
			fRec1795[1] = fRec1795[0];
			fRec1812[1] = fRec1812[0];
			fRec1810[1] = fRec1810[0];
			fRec1809[1] = fRec1809[0];
			fRec1807[1] = fRec1807[0];
			fRec1815[1] = fRec1815[0];
			fRec1813[1] = fRec1813[0];
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
			fRec1857[1] = fRec1857[0];
			fRec1855[1] = fRec1855[0];
			fRec1854[1] = fRec1854[0];
			fRec1852[1] = fRec1852[0];
			fRec1851[1] = fRec1851[0];
			fRec1849[1] = fRec1849[0];
			fRec1848[1] = fRec1848[0];
			fRec1846[1] = fRec1846[0];
			fRec1860[1] = fRec1860[0];
			fRec1858[1] = fRec1858[0];
			fRec1878[1] = fRec1878[0];
			fRec1876[1] = fRec1876[0];
			fRec1875[1] = fRec1875[0];
			fRec1873[1] = fRec1873[0];
			fRec1872[1] = fRec1872[0];
			fRec1870[1] = fRec1870[0];
			fRec1869[1] = fRec1869[0];
			fRec1867[1] = fRec1867[0];
			fRec1866[1] = fRec1866[0];
			fRec1864[1] = fRec1864[0];
			fRec1863[1] = fRec1863[0];
			fRec1861[1] = fRec1861[0];
			fRec1884[1] = fRec1884[0];
			fRec1882[1] = fRec1882[0];
			fRec1881[1] = fRec1881[0];
			fRec1879[1] = fRec1879[0];
			fRec1893[1] = fRec1893[0];
			fRec1891[1] = fRec1891[0];
			fRec1890[1] = fRec1890[0];
			fRec1888[1] = fRec1888[0];
			fRec1887[1] = fRec1887[0];
			fRec1885[1] = fRec1885[0];
			fRec1902[1] = fRec1902[0];
			fRec1900[1] = fRec1900[0];
			fRec1899[1] = fRec1899[0];
			fRec1897[1] = fRec1897[0];
			fRec1896[1] = fRec1896[0];
			fRec1894[1] = fRec1894[0];
			fRec1914[1] = fRec1914[0];
			fRec1912[1] = fRec1912[0];
			fRec1911[1] = fRec1911[0];
			fRec1909[1] = fRec1909[0];
			fRec1908[1] = fRec1908[0];
			fRec1906[1] = fRec1906[0];
			fRec1905[1] = fRec1905[0];
			fRec1903[1] = fRec1903[0];
			fRec1917[1] = fRec1917[0];
			fRec1915[1] = fRec1915[0];
			fRec1935[1] = fRec1935[0];
			fRec1933[1] = fRec1933[0];
			fRec1932[1] = fRec1932[0];
			fRec1930[1] = fRec1930[0];
			fRec1929[1] = fRec1929[0];
			fRec1927[1] = fRec1927[0];
			fRec1926[1] = fRec1926[0];
			fRec1924[1] = fRec1924[0];
			fRec1923[1] = fRec1923[0];
			fRec1921[1] = fRec1921[0];
			fRec1920[1] = fRec1920[0];
			fRec1918[1] = fRec1918[0];
			fRec1941[1] = fRec1941[0];
			fRec1939[1] = fRec1939[0];
			fRec1938[1] = fRec1938[0];
			fRec1936[1] = fRec1936[0];
			fRec1956[1] = fRec1956[0];
			fRec1954[1] = fRec1954[0];
			fRec1953[1] = fRec1953[0];
			fRec1951[1] = fRec1951[0];
			fRec1950[1] = fRec1950[0];
			fRec1948[1] = fRec1948[0];
			fRec1947[1] = fRec1947[0];
			fRec1945[1] = fRec1945[0];
			fRec1944[1] = fRec1944[0];
			fRec1942[1] = fRec1942[0];
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
			fRec1986[1] = fRec1986[0];
			fRec1984[1] = fRec1984[0];
			fRec1983[1] = fRec1983[0];
			fRec1981[1] = fRec1981[0];
			fRec1980[1] = fRec1980[0];
			fRec1978[1] = fRec1978[0];
			fRec1977[1] = fRec1977[0];
			fRec1975[1] = fRec1975[0];
			fRec1995[1] = fRec1995[0];
			fRec1993[1] = fRec1993[0];
			fRec1992[1] = fRec1992[0];
			fRec1990[1] = fRec1990[0];
			fRec1989[1] = fRec1989[0];
			fRec1987[1] = fRec1987[0];
			fRec2010[1] = fRec2010[0];
			fRec2008[1] = fRec2008[0];
			fRec2007[1] = fRec2007[0];
			fRec2005[1] = fRec2005[0];
			fRec2004[1] = fRec2004[0];
			fRec2002[1] = fRec2002[0];
			fRec2001[1] = fRec2001[0];
			fRec1999[1] = fRec1999[0];
			fRec1998[1] = fRec1998[0];
			fRec1996[1] = fRec1996[0];
			fRec2016[1] = fRec2016[0];
			fRec2014[1] = fRec2014[0];
			fRec2013[1] = fRec2013[0];
			fRec2011[1] = fRec2011[0];
			fRec2019[1] = fRec2019[0];
			fRec2017[1] = fRec2017[0];
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
			fRec2043[1] = fRec2043[0];
			fRec2041[1] = fRec2041[0];
			fRec2040[1] = fRec2040[0];
			fRec2038[1] = fRec2038[0];
			fRec2046[1] = fRec2046[0];
			fRec2044[1] = fRec2044[0];
			fRec2061[1] = fRec2061[0];
			fRec2059[1] = fRec2059[0];
			fRec2058[1] = fRec2058[0];
			fRec2056[1] = fRec2056[0];
			fRec2055[1] = fRec2055[0];
			fRec2053[1] = fRec2053[0];
			fRec2052[1] = fRec2052[0];
			fRec2050[1] = fRec2050[0];
			fRec2049[1] = fRec2049[0];
			fRec2047[1] = fRec2047[0];
			fRec2070[1] = fRec2070[0];
			fRec2068[1] = fRec2068[0];
			fRec2067[1] = fRec2067[0];
			fRec2065[1] = fRec2065[0];
			fRec2064[1] = fRec2064[0];
			fRec2062[1] = fRec2062[0];
			fRec2082[1] = fRec2082[0];
			fRec2080[1] = fRec2080[0];
			fRec2079[1] = fRec2079[0];
			fRec2077[1] = fRec2077[0];
			fRec2076[1] = fRec2076[0];
			fRec2074[1] = fRec2074[0];
			fRec2073[1] = fRec2073[0];
			fRec2071[1] = fRec2071[0];
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
			fRec2100[1] = fRec2100[0];
			fRec2098[1] = fRec2098[0];
			fRec2118[1] = fRec2118[0];
			fRec2116[1] = fRec2116[0];
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
			fRec2124[1] = fRec2124[0];
			fRec2122[1] = fRec2122[0];
			fRec2121[1] = fRec2121[0];
			fRec2119[1] = fRec2119[0];
			fRec2136[1] = fRec2136[0];
			fRec2134[1] = fRec2134[0];
			fRec2133[1] = fRec2133[0];
			fRec2131[1] = fRec2131[0];
			fRec2130[1] = fRec2130[0];
			fRec2128[1] = fRec2128[0];
			fRec2127[1] = fRec2127[0];
			fRec2125[1] = fRec2125[0];
			fRec2145[1] = fRec2145[0];
			fRec2143[1] = fRec2143[0];
			fRec2142[1] = fRec2142[0];
			fRec2140[1] = fRec2140[0];
			fRec2139[1] = fRec2139[0];
			fRec2137[1] = fRec2137[0];
			fRec2154[1] = fRec2154[0];
			fRec2152[1] = fRec2152[0];
			fRec2151[1] = fRec2151[0];
			fRec2149[1] = fRec2149[0];
			fRec2148[1] = fRec2148[0];
			fRec2146[1] = fRec2146[0];
			fRec2160[1] = fRec2160[0];
			fRec2158[1] = fRec2158[0];
			fRec2157[1] = fRec2157[0];
			fRec2155[1] = fRec2155[0];
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
			fRec2196[1] = fRec2196[0];
			fRec2194[1] = fRec2194[0];
			fRec2208[1] = fRec2208[0];
			fRec2206[1] = fRec2206[0];
			fRec2205[1] = fRec2205[0];
			fRec2203[1] = fRec2203[0];
			fRec2202[1] = fRec2202[0];
			fRec2200[1] = fRec2200[0];
			fRec2199[1] = fRec2199[0];
			fRec2197[1] = fRec2197[0];
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
			fRec2331[1] = fRec2331[0];
			fRec2329[1] = fRec2329[0];
			fRec2328[1] = fRec2328[0];
			fRec2326[1] = fRec2326[0];
			fRec2334[1] = fRec2334[0];
			fRec2332[1] = fRec2332[0];
			fRec2346[1] = fRec2346[0];
			fRec2344[1] = fRec2344[0];
			fRec2343[1] = fRec2343[0];
			fRec2341[1] = fRec2341[0];
			fRec2340[1] = fRec2340[0];
			fRec2338[1] = fRec2338[0];
			fRec2337[1] = fRec2337[0];
			fRec2335[1] = fRec2335[0];
			fRec2355[1] = fRec2355[0];
			fRec2353[1] = fRec2353[0];
			fRec2352[1] = fRec2352[0];
			fRec2350[1] = fRec2350[0];
			fRec2349[1] = fRec2349[0];
			fRec2347[1] = fRec2347[0];
			fRec2361[1] = fRec2361[0];
			fRec2359[1] = fRec2359[0];
			fRec2358[1] = fRec2358[0];
			fRec2356[1] = fRec2356[0];
			fRec2364[1] = fRec2364[0];
			fRec2362[1] = fRec2362[0];
			fRec2379[1] = fRec2379[0];
			fRec2377[1] = fRec2377[0];
			fRec2376[1] = fRec2376[0];
			fRec2374[1] = fRec2374[0];
			fRec2373[1] = fRec2373[0];
			fRec2371[1] = fRec2371[0];
			fRec2370[1] = fRec2370[0];
			fRec2368[1] = fRec2368[0];
			fRec2367[1] = fRec2367[0];
			fRec2365[1] = fRec2365[0];
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
			fRec2382[1] = fRec2382[0];
			fRec2380[1] = fRec2380[0];
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
			fRec2436[1] = fRec2436[0];
			fRec2434[1] = fRec2434[0];
			fRec2433[1] = fRec2433[0];
			fRec2431[1] = fRec2431[0];
			fRec2448[1] = fRec2448[0];
			fRec2446[1] = fRec2446[0];
			fRec2445[1] = fRec2445[0];
			fRec2443[1] = fRec2443[0];
			fRec2442[1] = fRec2442[0];
			fRec2440[1] = fRec2440[0];
			fRec2439[1] = fRec2439[0];
			fRec2437[1] = fRec2437[0];
			fRec2457[1] = fRec2457[0];
			fRec2455[1] = fRec2455[0];
			fRec2454[1] = fRec2454[0];
			fRec2452[1] = fRec2452[0];
			fRec2451[1] = fRec2451[0];
			fRec2449[1] = fRec2449[0];
			fRec2460[1] = fRec2460[0];
			fRec2458[1] = fRec2458[0];
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
			fRec2487[1] = fRec2487[0];
			fRec2485[1] = fRec2485[0];
			fRec2484[1] = fRec2484[0];
			fRec2482[1] = fRec2482[0];
			fRec2481[1] = fRec2481[0];
			fRec2479[1] = fRec2479[0];
			fRec2478[1] = fRec2478[0];
			fRec2476[1] = fRec2476[0];
			fRec2496[1] = fRec2496[0];
			fRec2494[1] = fRec2494[0];
			fRec2493[1] = fRec2493[0];
			fRec2491[1] = fRec2491[0];
			fRec2490[1] = fRec2490[0];
			fRec2488[1] = fRec2488[0];
			fRec2502[1] = fRec2502[0];
			fRec2500[1] = fRec2500[0];
			fRec2499[1] = fRec2499[0];
			fRec2497[1] = fRec2497[0];
			fRec2505[1] = fRec2505[0];
			fRec2503[1] = fRec2503[0];
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
			fRec2508[1] = fRec2508[0];
			fRec2506[1] = fRec2506[0];
			fRec2526[1] = fRec2526[0];
			fRec2524[1] = fRec2524[0];
			fRec2544[1] = fRec2544[0];
			fRec2542[1] = fRec2542[0];
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
			fRec2559[1] = fRec2559[0];
			fRec2557[1] = fRec2557[0];
			fRec2556[1] = fRec2556[0];
			fRec2554[1] = fRec2554[0];
			fRec2553[1] = fRec2553[0];
			fRec2551[1] = fRec2551[0];
			fRec2550[1] = fRec2550[0];
			fRec2548[1] = fRec2548[0];
			fRec2547[1] = fRec2547[0];
			fRec2545[1] = fRec2545[0];
			fRec2571[1] = fRec2571[0];
			fRec2569[1] = fRec2569[0];
			fRec2568[1] = fRec2568[0];
			fRec2566[1] = fRec2566[0];
			fRec2565[1] = fRec2565[0];
			fRec2563[1] = fRec2563[0];
			fRec2562[1] = fRec2562[0];
			fRec2560[1] = fRec2560[0];
			fRec2580[1] = fRec2580[0];
			fRec2578[1] = fRec2578[0];
			fRec2577[1] = fRec2577[0];
			fRec2575[1] = fRec2575[0];
			fRec2574[1] = fRec2574[0];
			fRec2572[1] = fRec2572[0];
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
			fRec2673[1] = fRec2673[0];
			fRec2671[1] = fRec2671[0];
			fRec2670[1] = fRec2670[0];
			fRec2668[1] = fRec2668[0];
			fRec2676[1] = fRec2676[0];
			fRec2674[1] = fRec2674[0];
			fRec2691[1] = fRec2691[0];
			fRec2689[1] = fRec2689[0];
			fRec2688[1] = fRec2688[0];
			fRec2686[1] = fRec2686[0];
			fRec2685[1] = fRec2685[0];
			fRec2683[1] = fRec2683[0];
			fRec2682[1] = fRec2682[0];
			fRec2680[1] = fRec2680[0];
			fRec2679[1] = fRec2679[0];
			fRec2677[1] = fRec2677[0];
			fRec2700[1] = fRec2700[0];
			fRec2698[1] = fRec2698[0];
			fRec2697[1] = fRec2697[0];
			fRec2695[1] = fRec2695[0];
			fRec2694[1] = fRec2694[0];
			fRec2692[1] = fRec2692[0];
			fRec2712[1] = fRec2712[0];
			fRec2710[1] = fRec2710[0];
			fRec2709[1] = fRec2709[0];
			fRec2707[1] = fRec2707[0];
			fRec2706[1] = fRec2706[0];
			fRec2704[1] = fRec2704[0];
			fRec2703[1] = fRec2703[0];
			fRec2701[1] = fRec2701[0];
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
			fRec2739[1] = fRec2739[0];
			fRec2737[1] = fRec2737[0];
			fRec2736[1] = fRec2736[0];
			fRec2734[1] = fRec2734[0];
			fRec2733[1] = fRec2733[0];
			fRec2731[1] = fRec2731[0];
			fRec2730[1] = fRec2730[0];
			fRec2728[1] = fRec2728[0];
			fRec2748[1] = fRec2748[0];
			fRec2746[1] = fRec2746[0];
			fRec2745[1] = fRec2745[0];
			fRec2743[1] = fRec2743[0];
			fRec2742[1] = fRec2742[0];
			fRec2740[1] = fRec2740[0];
			fRec2754[1] = fRec2754[0];
			fRec2752[1] = fRec2752[0];
			fRec2751[1] = fRec2751[0];
			fRec2749[1] = fRec2749[0];
			fRec2757[1] = fRec2757[0];
			fRec2755[1] = fRec2755[0];
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
			fRec2760[1] = fRec2760[0];
			fRec2758[1] = fRec2758[0];
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
			fRec2862[1] = fRec2862[0];
			fRec2860[1] = fRec2860[0];
			fRec2859[1] = fRec2859[0];
			fRec2857[1] = fRec2857[0];
			fRec2856[1] = fRec2856[0];
			fRec2854[1] = fRec2854[0];
			fRec2868[1] = fRec2868[0];
			fRec2866[1] = fRec2866[0];
			fRec2865[1] = fRec2865[0];
			fRec2863[1] = fRec2863[0];
			fRec2871[1] = fRec2871[0];
			fRec2869[1] = fRec2869[0];
			fRec2889[1] = fRec2889[0];
			fRec2887[1] = fRec2887[0];
			fRec2886[1] = fRec2886[0];
			fRec2884[1] = fRec2884[0];
			fRec2883[1] = fRec2883[0];
			fRec2881[1] = fRec2881[0];
			fRec2880[1] = fRec2880[0];
			fRec2878[1] = fRec2878[0];
			fRec2877[1] = fRec2877[0];
			fRec2875[1] = fRec2875[0];
			fRec2874[1] = fRec2874[0];
			fRec2872[1] = fRec2872[0];
			fRec2901[1] = fRec2901[0];
			fRec2899[1] = fRec2899[0];
			fRec2898[1] = fRec2898[0];
			fRec2896[1] = fRec2896[0];
			fRec2895[1] = fRec2895[0];
			fRec2893[1] = fRec2893[0];
			fRec2892[1] = fRec2892[0];
			fRec2890[1] = fRec2890[0];
			
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
