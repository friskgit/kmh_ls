/* ------------------------------------------------------------
author: "AmbisonicDecoderToolkit, Henrik Frisk"
copyright: "(c) Aaron J. Heller 2013"
license: "BSD 3-Clause License"
name: "KMHLS_FullSetup_5h5p_full_6"
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
	double fConst2;
	double fConst3;
	double fConst4;
	double fRec16[3];
	double fRec17[3];
	double fRec18[3];
	double fRec19[3];
	double fRec20[3];
	double fRec21[3];
	double fRec22[3];
	double fRec23[3];
	double fRec24[3];
	double fConst5;
	double fConst6;
	double fConst7;
	double fRec15[2];
	double fRec13[2];
	double fRec12[2];
	double fRec10[2];
	double fConst8;
	double fConst9;
	double fConst10;
	double fRec9[2];
	double fRec7[2];
	double fRec6[2];
	double fRec4[2];
	double fConst11;
	double fConst12;
	double fConst13;
	double fConst14;
	double fConst15;
	double fRec34[3];
	double fRec35[3];
	double fRec36[3];
	double fRec37[3];
	double fRec38[3];
	double fRec39[3];
	double fRec40[3];
	double fRec33[2];
	double fRec31[2];
	double fRec30[2];
	double fRec28[2];
	double fConst16;
	double fRec27[2];
	double fRec25[2];
	double fConst17;
	double fRec47[3];
	double fRec48[3];
	double fRec49[3];
	double fRec50[3];
	double fRec51[3];
	double fConst18;
	double fConst19;
	double fRec46[2];
	double fRec44[2];
	double fRec43[2];
	double fRec41[2];
	double fConst20;
	double fRec55[3];
	double fRec56[3];
	double fRec57[3];
	double fConst21;
	double fRec54[2];
	double fRec52[2];
	double fConst22;
	double fConst23;
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fConst28;
	double fRec73[3];
	double fRec74[3];
	double fRec75[3];
	double fRec76[3];
	double fRec77[3];
	double fRec78[3];
	double fRec79[3];
	double fRec80[3];
	double fRec81[3];
	double fRec82[3];
	double fRec83[3];
	double fConst29;
	double fConst30;
	double fRec72[2];
	double fRec70[2];
	double fRec69[2];
	double fRec67[2];
	double fRec66[2];
	double fRec64[2];
	double fRec63[2];
	double fRec61[2];
	double fConst31;
	double fRec60[2];
	double fRec58[2];
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
	double fRec122[2];
	double fRec120[2];
	double fRec128[2];
	double fRec126[2];
	double fRec125[2];
	double fRec123[2];
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
	double fRec167[2];
	double fRec165[2];
	double fRec173[2];
	double fRec171[2];
	double fRec170[2];
	double fRec168[2];
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
	double fRec212[2];
	double fRec210[2];
	double fRec218[2];
	double fRec216[2];
	double fRec215[2];
	double fRec213[2];
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
	double fRec239[2];
	double fRec237[2];
	double fRec236[2];
	double fRec234[2];
	double fRec242[2];
	double fRec240[2];
	double fRec251[2];
	double fRec249[2];
	double fRec248[2];
	double fRec246[2];
	double fRec245[2];
	double fRec243[2];
	double fRec263[2];
	double fRec261[2];
	double fRec260[2];
	double fRec258[2];
	double fRec257[2];
	double fRec255[2];
	double fRec254[2];
	double fRec252[2];
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
	double fRec284[2];
	double fRec282[2];
	double fRec281[2];
	double fRec279[2];
	double fRec287[2];
	double fRec285[2];
	double fRec296[2];
	double fRec294[2];
	double fRec293[2];
	double fRec291[2];
	double fRec290[2];
	double fRec288[2];
	double fRec308[2];
	double fRec306[2];
	double fRec305[2];
	double fRec303[2];
	double fRec302[2];
	double fRec300[2];
	double fRec299[2];
	double fRec297[2];
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
	double fRec524[2];
	double fRec522[2];
	double fRec521[2];
	double fRec519[2];
	double fRec518[2];
	double fRec516[2];
	double fRec527[2];
	double fRec525[2];
	double fRec533[2];
	double fRec531[2];
	double fRec530[2];
	double fRec528[2];
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
	double fRec587[2];
	double fRec585[2];
	double fRec584[2];
	double fRec582[2];
	double fRec581[2];
	double fRec579[2];
	double fRec593[2];
	double fRec591[2];
	double fRec590[2];
	double fRec588[2];
	double fRec596[2];
	double fRec594[2];
	double fRec608[2];
	double fRec606[2];
	double fRec605[2];
	double fRec603[2];
	double fRec602[2];
	double fRec600[2];
	double fRec599[2];
	double fRec597[2];
	double fRec623[2];
	double fRec621[2];
	double fRec620[2];
	double fRec618[2];
	double fRec617[2];
	double fRec615[2];
	double fRec614[2];
	double fRec612[2];
	double fRec611[2];
	double fRec609[2];
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
	double fConst33;
	double fConst34;
	double fConst35;
	double fConst36;
	double fConst37;
	double fConst38;
	double fRec773[2];
	double fRec771[2];
	double fRec770[2];
	double fRec768[2];
	double fConst39;
	double fConst40;
	double fConst41;
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
	double fRec785[2];
	double fRec783[2];
	double fRec782[2];
	double fRec780[2];
	double fConst48;
	double fConst49;
	double fConst50;
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
	double fRec797[2];
	double fRec795[2];
	double fConst59;
	double fConst60;
	double fConst61;
	double fRec803[2];
	double fRec801[2];
	double fRec800[2];
	double fRec798[2];
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
	double fRec842[2];
	double fRec840[2];
	double fRec848[2];
	double fRec846[2];
	double fRec845[2];
	double fRec843[2];
	double fVec17[512];
	double fRec854[2];
	double fRec852[2];
	double fRec851[2];
	double fRec849[2];
	double fRec857[2];
	double fRec855[2];
	double fRec869[2];
	double fRec867[2];
	double fRec866[2];
	double fRec864[2];
	double fRec863[2];
	double fRec861[2];
	double fRec860[2];
	double fRec858[2];
	double fRec878[2];
	double fRec876[2];
	double fRec875[2];
	double fRec873[2];
	double fRec872[2];
	double fRec870[2];
	double fRec893[2];
	double fRec891[2];
	double fRec890[2];
	double fRec888[2];
	double fRec887[2];
	double fRec885[2];
	double fRec884[2];
	double fRec882[2];
	double fRec881[2];
	double fRec879[2];
	double fVec18[512];
	double fRec902[2];
	double fRec900[2];
	double fRec899[2];
	double fRec897[2];
	double fRec896[2];
	double fRec894[2];
	double fRec917[2];
	double fRec915[2];
	double fRec914[2];
	double fRec912[2];
	double fRec911[2];
	double fRec909[2];
	double fRec908[2];
	double fRec906[2];
	double fRec905[2];
	double fRec903[2];
	double fRec929[2];
	double fRec927[2];
	double fRec926[2];
	double fRec924[2];
	double fRec923[2];
	double fRec921[2];
	double fRec920[2];
	double fRec918[2];
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
	double fRec1088[2];
	double fRec1086[2];
	double fRec1103[2];
	double fRec1101[2];
	double fRec1109[2];
	double fRec1107[2];
	double fRec1106[2];
	double fRec1104[2];
	double fRec1118[2];
	double fRec1116[2];
	double fRec1115[2];
	double fRec1113[2];
	double fRec1112[2];
	double fRec1110[2];
	double fVec23[512];
	double fConst63;
	double fConst64;
	double fConst65;
	double fRec1124[2];
	double fRec1122[2];
	double fRec1121[2];
	double fRec1119[2];
	double fConst66;
	double fConst67;
	double fRec1127[2];
	double fRec1125[2];
	double fConst68;
	double fConst69;
	double fConst70;
	double fConst71;
	double fConst72;
	double fConst73;
	double fRec1142[2];
	double fRec1140[2];
	double fRec1139[2];
	double fRec1137[2];
	double fConst74;
	double fConst75;
	double fConst76;
	double fRec1136[2];
	double fRec1134[2];
	double fRec1133[2];
	double fRec1131[2];
	double fConst77;
	double fRec1130[2];
	double fRec1128[2];
	double fConst78;
	double fConst79;
	double fConst80;
	double fConst81;
	double fConst82;
	double fRec1151[2];
	double fRec1149[2];
	double fRec1148[2];
	double fRec1146[2];
	double fConst83;
	double fRec1145[2];
	double fRec1143[2];
	double fConst84;
	double fConst85;
	double fConst86;
	double fConst87;
	double fConst88;
	double fRec1163[2];
	double fRec1161[2];
	double fRec1160[2];
	double fRec1158[2];
	double fConst89;
	double fConst90;
	double fConst91;
	double fRec1157[2];
	double fRec1155[2];
	double fRec1154[2];
	double fRec1152[2];
	double fVec24[256];
	int iConst92;
	double fRec1175[2];
	double fRec1173[2];
	double fRec1172[2];
	double fRec1170[2];
	double fRec1169[2];
	double fRec1167[2];
	double fRec1166[2];
	double fRec1164[2];
	double fRec1178[2];
	double fRec1176[2];
	double fRec1187[2];
	double fRec1185[2];
	double fRec1184[2];
	double fRec1182[2];
	double fRec1181[2];
	double fRec1179[2];
	double fRec1193[2];
	double fRec1191[2];
	double fRec1190[2];
	double fRec1188[2];
	double fRec1208[2];
	double fRec1206[2];
	double fRec1205[2];
	double fRec1203[2];
	double fRec1202[2];
	double fRec1200[2];
	double fRec1199[2];
	double fRec1197[2];
	double fRec1196[2];
	double fRec1194[2];
	double fVec25[256];
	double fRec1214[2];
	double fRec1212[2];
	double fRec1211[2];
	double fRec1209[2];
	double fRec1217[2];
	double fRec1215[2];
	double fRec1226[2];
	double fRec1224[2];
	double fRec1223[2];
	double fRec1221[2];
	double fRec1220[2];
	double fRec1218[2];
	double fRec1238[2];
	double fRec1236[2];
	double fRec1235[2];
	double fRec1233[2];
	double fRec1232[2];
	double fRec1230[2];
	double fRec1229[2];
	double fRec1227[2];
	double fRec1253[2];
	double fRec1251[2];
	double fRec1250[2];
	double fRec1248[2];
	double fRec1247[2];
	double fRec1245[2];
	double fRec1244[2];
	double fRec1242[2];
	double fRec1241[2];
	double fRec1239[2];
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
	double fRec1280[2];
	double fRec1278[2];
	double fRec1292[2];
	double fRec1290[2];
	double fRec1298[2];
	double fRec1296[2];
	double fRec1295[2];
	double fRec1293[2];
	double fVec27[256];
	double fConst93;
	double fConst94;
	double fConst95;
	double fConst96;
	double fConst97;
	double fRec1307[2];
	double fRec1305[2];
	double fRec1304[2];
	double fRec1302[2];
	double fConst98;
	double fRec1301[2];
	double fRec1299[2];
	double fConst99;
	double fConst100;
	double fConst101;
	double fConst102;
	double fConst103;
	double fConst104;
	double fRec1322[2];
	double fRec1320[2];
	double fRec1319[2];
	double fRec1317[2];
	double fConst105;
	double fConst106;
	double fConst107;
	double fRec1316[2];
	double fRec1314[2];
	double fRec1313[2];
	double fRec1311[2];
	double fConst108;
	double fRec1310[2];
	double fRec1308[2];
	double fConst109;
	double fConst110;
	double fRec1325[2];
	double fRec1323[2];
	double fConst111;
	double fConst112;
	double fConst113;
	double fRec1331[2];
	double fRec1329[2];
	double fRec1328[2];
	double fRec1326[2];
	double fConst114;
	double fConst115;
	double fConst116;
	double fConst117;
	double fConst118;
	double fRec1343[2];
	double fRec1341[2];
	double fRec1340[2];
	double fRec1338[2];
	double fConst119;
	double fConst120;
	double fConst121;
	double fRec1337[2];
	double fRec1335[2];
	double fRec1334[2];
	double fRec1332[2];
	double fRec1352[2];
	double fRec1350[2];
	double fRec1349[2];
	double fRec1347[2];
	double fRec1346[2];
	double fRec1344[2];
	double fRec1358[2];
	double fRec1356[2];
	double fRec1355[2];
	double fRec1353[2];
	double fRec1370[2];
	double fRec1368[2];
	double fRec1367[2];
	double fRec1365[2];
	double fRec1364[2];
	double fRec1362[2];
	double fRec1361[2];
	double fRec1359[2];
	double fRec1373[2];
	double fRec1371[2];
	double fRec1388[2];
	double fRec1386[2];
	double fRec1385[2];
	double fRec1383[2];
	double fRec1382[2];
	double fRec1380[2];
	double fRec1379[2];
	double fRec1377[2];
	double fRec1376[2];
	double fRec1374[2];
	double fVec28[1024];
	double fRec1394[2];
	double fRec1392[2];
	double fRec1391[2];
	double fRec1389[2];
	double fRec1403[2];
	double fRec1401[2];
	double fRec1400[2];
	double fRec1398[2];
	double fRec1397[2];
	double fRec1395[2];
	double fRec1406[2];
	double fRec1404[2];
	double fRec1418[2];
	double fRec1416[2];
	double fRec1415[2];
	double fRec1413[2];
	double fRec1412[2];
	double fRec1410[2];
	double fRec1409[2];
	double fRec1407[2];
	double fRec1433[2];
	double fRec1431[2];
	double fRec1430[2];
	double fRec1428[2];
	double fRec1427[2];
	double fRec1425[2];
	double fRec1424[2];
	double fRec1422[2];
	double fRec1421[2];
	double fRec1419[2];
	double fVec29[1024];
	double fRec1445[2];
	double fRec1443[2];
	double fRec1442[2];
	double fRec1440[2];
	double fRec1439[2];
	double fRec1437[2];
	double fRec1436[2];
	double fRec1434[2];
	double fRec1460[2];
	double fRec1458[2];
	double fRec1457[2];
	double fRec1455[2];
	double fRec1454[2];
	double fRec1452[2];
	double fRec1451[2];
	double fRec1449[2];
	double fRec1448[2];
	double fRec1446[2];
	double fRec1466[2];
	double fRec1464[2];
	double fRec1463[2];
	double fRec1461[2];
	double fRec1469[2];
	double fRec1467[2];
	double fRec1478[2];
	double fRec1476[2];
	double fRec1475[2];
	double fRec1473[2];
	double fRec1472[2];
	double fRec1470[2];
	double fVec30[1024];
	double fRec1493[2];
	double fRec1491[2];
	double fRec1490[2];
	double fRec1488[2];
	double fRec1487[2];
	double fRec1485[2];
	double fRec1484[2];
	double fRec1482[2];
	double fRec1481[2];
	double fRec1479[2];
	double fRec1499[2];
	double fRec1497[2];
	double fRec1496[2];
	double fRec1494[2];
	double fRec1511[2];
	double fRec1509[2];
	double fRec1508[2];
	double fRec1506[2];
	double fRec1505[2];
	double fRec1503[2];
	double fRec1502[2];
	double fRec1500[2];
	double fRec1514[2];
	double fRec1512[2];
	double fRec1523[2];
	double fRec1521[2];
	double fRec1520[2];
	double fRec1518[2];
	double fRec1517[2];
	double fRec1515[2];
	double fVec31[1024];
	double fRec1532[2];
	double fRec1530[2];
	double fRec1529[2];
	double fRec1527[2];
	double fRec1526[2];
	double fRec1524[2];
	double fRec1547[2];
	double fRec1545[2];
	double fRec1544[2];
	double fRec1542[2];
	double fRec1541[2];
	double fRec1539[2];
	double fRec1538[2];
	double fRec1536[2];
	double fRec1535[2];
	double fRec1533[2];
	double fRec1559[2];
	double fRec1557[2];
	double fRec1556[2];
	double fRec1554[2];
	double fRec1553[2];
	double fRec1551[2];
	double fRec1550[2];
	double fRec1548[2];
	double fRec1562[2];
	double fRec1560[2];
	double fRec1568[2];
	double fRec1566[2];
	double fRec1565[2];
	double fRec1563[2];
	double fVec32[1024];
	double fRec1580[2];
	double fRec1578[2];
	double fRec1577[2];
	double fRec1575[2];
	double fRec1574[2];
	double fRec1572[2];
	double fRec1571[2];
	double fRec1569[2];
	double fRec1583[2];
	double fRec1581[2];
	double fRec1592[2];
	double fRec1590[2];
	double fRec1589[2];
	double fRec1587[2];
	double fRec1586[2];
	double fRec1584[2];
	double fRec1598[2];
	double fRec1596[2];
	double fRec1595[2];
	double fRec1593[2];
	double fRec1613[2];
	double fRec1611[2];
	double fRec1610[2];
	double fRec1608[2];
	double fRec1607[2];
	double fRec1605[2];
	double fRec1604[2];
	double fRec1602[2];
	double fRec1601[2];
	double fRec1599[2];
	double fVec33[1024];
	double fRec1616[2];
	double fRec1614[2];
	double fRec1622[2];
	double fRec1620[2];
	double fRec1619[2];
	double fRec1617[2];
	double fRec1634[2];
	double fRec1632[2];
	double fRec1631[2];
	double fRec1629[2];
	double fRec1628[2];
	double fRec1626[2];
	double fRec1625[2];
	double fRec1623[2];
	double fRec1643[2];
	double fRec1641[2];
	double fRec1640[2];
	double fRec1638[2];
	double fRec1637[2];
	double fRec1635[2];
	double fRec1658[2];
	double fRec1656[2];
	double fRec1655[2];
	double fRec1653[2];
	double fRec1652[2];
	double fRec1650[2];
	double fRec1649[2];
	double fRec1647[2];
	double fRec1646[2];
	double fRec1644[2];
	double fVec34[1024];
	double fRec1667[2];
	double fRec1665[2];
	double fRec1664[2];
	double fRec1662[2];
	double fRec1661[2];
	double fRec1659[2];
	double fRec1673[2];
	double fRec1671[2];
	double fRec1670[2];
	double fRec1668[2];
	double fRec1676[2];
	double fRec1674[2];
	double fRec1688[2];
	double fRec1686[2];
	double fRec1685[2];
	double fRec1683[2];
	double fRec1682[2];
	double fRec1680[2];
	double fRec1679[2];
	double fRec1677[2];
	double fRec1703[2];
	double fRec1701[2];
	double fRec1700[2];
	double fRec1698[2];
	double fRec1697[2];
	double fRec1695[2];
	double fRec1694[2];
	double fRec1692[2];
	double fRec1691[2];
	double fRec1689[2];
	double fVec35[1024];
	double fRec1718[2];
	double fRec1716[2];
	double fRec1715[2];
	double fRec1713[2];
	double fRec1712[2];
	double fRec1710[2];
	double fRec1709[2];
	double fRec1707[2];
	double fRec1706[2];
	double fRec1704[2];
	double fRec1730[2];
	double fRec1728[2];
	double fRec1727[2];
	double fRec1725[2];
	double fRec1724[2];
	double fRec1722[2];
	double fRec1721[2];
	double fRec1719[2];
	double fRec1739[2];
	double fRec1737[2];
	double fRec1736[2];
	double fRec1734[2];
	double fRec1733[2];
	double fRec1731[2];
	double fRec1742[2];
	double fRec1740[2];
	double fRec1748[2];
	double fRec1746[2];
	double fRec1745[2];
	double fRec1743[2];
	double fVec36[1024];
	double fRec1754[2];
	double fRec1752[2];
	double fRec1751[2];
	double fRec1749[2];
	double fRec1769[2];
	double fRec1767[2];
	double fRec1766[2];
	double fRec1764[2];
	double fRec1763[2];
	double fRec1761[2];
	double fRec1760[2];
	double fRec1758[2];
	double fRec1757[2];
	double fRec1755[2];
	double fRec1781[2];
	double fRec1779[2];
	double fRec1778[2];
	double fRec1776[2];
	double fRec1775[2];
	double fRec1773[2];
	double fRec1772[2];
	double fRec1770[2];
	double fRec1784[2];
	double fRec1782[2];
	double fRec1793[2];
	double fRec1791[2];
	double fRec1790[2];
	double fRec1788[2];
	double fRec1787[2];
	double fRec1785[2];
	double fVec37[1024];
	double fRec1805[2];
	double fRec1803[2];
	double fRec1802[2];
	double fRec1800[2];
	double fRec1799[2];
	double fRec1797[2];
	double fRec1796[2];
	double fRec1794[2];
	double fRec1814[2];
	double fRec1812[2];
	double fRec1811[2];
	double fRec1809[2];
	double fRec1808[2];
	double fRec1806[2];
	double fRec1820[2];
	double fRec1818[2];
	double fRec1817[2];
	double fRec1815[2];
	double fRec1823[2];
	double fRec1821[2];
	double fRec1838[2];
	double fRec1836[2];
	double fRec1835[2];
	double fRec1833[2];
	double fRec1832[2];
	double fRec1830[2];
	double fRec1829[2];
	double fRec1827[2];
	double fRec1826[2];
	double fRec1824[2];
	double fVec38[1024];
	double fRec1853[2];
	double fRec1851[2];
	double fRec1850[2];
	double fRec1848[2];
	double fRec1847[2];
	double fRec1845[2];
	double fRec1844[2];
	double fRec1842[2];
	double fRec1841[2];
	double fRec1839[2];
	double fRec1865[2];
	double fRec1863[2];
	double fRec1862[2];
	double fRec1860[2];
	double fRec1859[2];
	double fRec1857[2];
	double fRec1856[2];
	double fRec1854[2];
	double fRec1874[2];
	double fRec1872[2];
	double fRec1871[2];
	double fRec1869[2];
	double fRec1868[2];
	double fRec1866[2];
	double fRec1877[2];
	double fRec1875[2];
	double fRec1883[2];
	double fRec1881[2];
	double fRec1880[2];
	double fRec1878[2];
	double fVec39[1024];
	double fRec1886[2];
	double fRec1884[2];
	double fRec1901[2];
	double fRec1899[2];
	double fRec1898[2];
	double fRec1896[2];
	double fRec1895[2];
	double fRec1893[2];
	double fRec1892[2];
	double fRec1890[2];
	double fRec1889[2];
	double fRec1887[2];
	double fRec1913[2];
	double fRec1911[2];
	double fRec1910[2];
	double fRec1908[2];
	double fRec1907[2];
	double fRec1905[2];
	double fRec1904[2];
	double fRec1902[2];
	double fRec1919[2];
	double fRec1917[2];
	double fRec1916[2];
	double fRec1914[2];
	double fRec1928[2];
	double fRec1926[2];
	double fRec1925[2];
	double fRec1923[2];
	double fRec1922[2];
	double fRec1920[2];
	double fVec40[1024];
	double fRec1943[2];
	double fRec1941[2];
	double fRec1940[2];
	double fRec1938[2];
	double fRec1937[2];
	double fRec1935[2];
	double fRec1934[2];
	double fRec1932[2];
	double fRec1931[2];
	double fRec1929[2];
	double fRec1955[2];
	double fRec1953[2];
	double fRec1952[2];
	double fRec1950[2];
	double fRec1949[2];
	double fRec1947[2];
	double fRec1946[2];
	double fRec1944[2];
	double fRec1964[2];
	double fRec1962[2];
	double fRec1961[2];
	double fRec1959[2];
	double fRec1958[2];
	double fRec1956[2];
	double fRec1967[2];
	double fRec1965[2];
	double fRec1973[2];
	double fRec1971[2];
	double fRec1970[2];
	double fRec1968[2];
	double fVec41[1024];
	double fRec1988[2];
	double fRec1986[2];
	double fRec1985[2];
	double fRec1983[2];
	double fRec1982[2];
	double fRec1980[2];
	double fRec1979[2];
	double fRec1977[2];
	double fRec1976[2];
	double fRec1974[2];
	double fRec1997[2];
	double fRec1995[2];
	double fRec1994[2];
	double fRec1992[2];
	double fRec1991[2];
	double fRec1989[2];
	double fRec2009[2];
	double fRec2007[2];
	double fRec2006[2];
	double fRec2004[2];
	double fRec2003[2];
	double fRec2001[2];
	double fRec2000[2];
	double fRec1998[2];
	double fRec2012[2];
	double fRec2010[2];
	double fRec2018[2];
	double fRec2016[2];
	double fRec2015[2];
	double fRec2013[2];
	double fVec42[1024];
	double fRec2027[2];
	double fRec2025[2];
	double fRec2024[2];
	double fRec2022[2];
	double fRec2021[2];
	double fRec2019[2];
	double fRec2039[2];
	double fRec2037[2];
	double fRec2036[2];
	double fRec2034[2];
	double fRec2033[2];
	double fRec2031[2];
	double fRec2030[2];
	double fRec2028[2];
	double fRec2042[2];
	double fRec2040[2];
	double fRec2048[2];
	double fRec2046[2];
	double fRec2045[2];
	double fRec2043[2];
	double fRec2063[2];
	double fRec2061[2];
	double fRec2060[2];
	double fRec2058[2];
	double fRec2057[2];
	double fRec2055[2];
	double fRec2054[2];
	double fRec2052[2];
	double fRec2051[2];
	double fRec2049[2];
	double fVec43[1024];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "AmbisonicDecoderToolkit, Henrik Frisk");
		m->declare("copyright", "(c) Aaron J. Heller 2013");
		m->declare("filename", "KMHLS_FullSetup_5h5p_full_6.dsp");
		m->declare("license", "BSD 3-Clause License");
		m->declare("name", "KMHLS_FullSetup_5h5p_full_6");
		m->declare("version", "1.2");
	}

	virtual int getNumInputs() {
		return 36;
		
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
		fConst11 = (1.0 / ((((8950.8463194903634 / fConst0) + 136.90669911154342) / fConst0) + 1.0));
		fConst12 = (35803.385277961454 / fConst0);
		fConst13 = (fConst12 + 273.81339822308684);
		fConst14 = ((86.443380725268696 / fConst0) + 1.0);
		fConst15 = (1.0 / fConst14);
		fConst16 = (172.88676145053739 / (fConst0 * fConst14));
		fConst17 = (1.0 / ((((4157.1048469258621 / fConst0) + 111.67503991840606) / fConst0) + 1.0));
		fConst18 = (16628.419387703449 / fConst0);
		fConst19 = (fConst18 + 223.35007983681211);
		fConst20 = (1.0 / ((37.225013306135352 / fConst0) + 1.0));
		fConst21 = (74.450026612270705 / fConst0);
		fConst22 = ((((19777.399306469804 / fConst0) + 249.5532431201479) / fConst0) + 1.0);
		fConst23 = (1.0 / (fConst0 * fConst22));
		fConst24 = (79109.597225879217 / fConst0);
		fConst25 = (fConst24 + 499.10648624029579);
		fConst26 = (1.0 / ((((25159.235463955636 / fConst0) + 173.07206373673586) / fConst0) + 1.0));
		fConst27 = ((135.74989273514609 / fConst0) + 1.0);
		fConst28 = (1.0 / (fConst27 * fConst22));
		fConst29 = (100636.94185582254 / fConst0);
		fConst30 = (fConst29 + 346.14412747347171);
		fConst31 = (271.49978547029218 / (fConst0 * fConst27));
		iConst32 = int(((0.0028145653948241961 * fConst0) + 0.5));
		fConst33 = (1.0 / ((((22433.846310978071 / fConst0) + 163.42937603980999) / fConst0) + 1.0));
		fConst34 = (89735.385243912286 / fConst0);
		fConst35 = (fConst34 + 326.85875207961999);
		fConst36 = ((128.18660497931657 / fConst0) + 1.0);
		fConst37 = ((((17635.000757786547 / fConst0) + 235.6494163834252) / fConst0) + 1.0);
		fConst38 = (1.0 / (fConst36 * fConst37));
		fConst39 = (1.0 / (fConst0 * fConst37));
		fConst40 = (70540.003031146189 / fConst0);
		fConst41 = (fConst40 + 471.29883276685041);
		fConst42 = (256.37320995863314 / (fConst0 * fConst36));
		fConst43 = (1.0 / ((((14194.264965114509 / fConst0) + 147.90071367402544) / fConst0) + 1.0));
		fConst44 = (56777.059860458037 / fConst0);
		fConst45 = (fConst44 + 295.80142734805088);
		fConst46 = ((((11293.496952148356 / fConst0) + 203.6095512610093) / fConst0) + 1.0);
		fConst47 = (1.0 / fConst46);
		fConst48 = (1.0 / (fConst0 * fConst46));
		fConst49 = (45173.987808593425 / fConst0);
		fConst50 = (fConst49 + 407.2191025220186);
		fConst51 = (1.0 / ((((7981.2405656089695 / fConst0) + 129.27896003773355) / fConst0) + 1.0));
		fConst52 = (31924.962262435878 / fConst0);
		fConst53 = (fConst52 + 258.55792007546711);
		fConst54 = ((81.627198923287324 / fConst0) + 1.0);
		fConst55 = (1.0 / fConst54);
		fConst56 = (163.25439784657465 / (fConst0 * fConst54));
		fConst57 = (1.0 / ((35.15102649350348 / fConst0) + 1.0));
		fConst58 = (70.302052987006959 / fConst0);
		fConst59 = (1.0 / ((((3706.7839906409508 / fConst0) + 105.45307948051044) / fConst0) + 1.0));
		fConst60 = (14827.135962563803 / fConst0);
		fConst61 = (fConst60 + 210.90615896102088);
		iConst62 = int(((0.0020220583685382951 * fConst0) + 0.5));
		fConst63 = (1.0 / ((((3125.0682617252614 / fConst0) + 96.825641155510993) / fConst0) + 1.0));
		fConst64 = (12500.273046901046 / fConst0);
		fConst65 = (fConst64 + 193.65128231102199);
		fConst66 = (1.0 / ((32.275213718503664 / fConst0) + 1.0));
		fConst67 = (64.550427437007329 / fConst0);
		fConst68 = (1.0 / ((((18913.241578648733 / fConst0) + 150.05871992220281) / fConst0) + 1.0));
		fConst69 = (75652.966314594931 / fConst0);
		fConst70 = (fConst69 + 300.11743984440562);
		fConst71 = ((117.6992675397825 / fConst0) + 1.0);
		fConst72 = ((((14867.491956047414 / fConst0) + 216.37021831556928) / fConst0) + 1.0);
		fConst73 = (1.0 / (fConst71 * fConst72));
		fConst74 = (1.0 / (fConst0 * fConst72));
		fConst75 = (59469.967824189654 / fConst0);
		fConst76 = (fConst75 + 432.74043663113855);
		fConst77 = (235.39853507956499 / (fConst0 * fConst71));
		fConst78 = (1.0 / ((((6728.7226997184644 / fConst0) + 118.70225369648584) / fConst0) + 1.0));
		fConst79 = (26914.890798873857 / fConst0);
		fConst80 = (fConst79 + 237.40450739297168);
		fConst81 = ((74.949028614536147 / fConst0) + 1.0);
		fConst82 = (1.0 / fConst81);
		fConst83 = (149.89805722907229 / (fConst0 * fConst81));
		fConst84 = (1.0 / ((((11966.720222434136 / fConst0) + 135.80050482538877) / fConst0) + 1.0));
		fConst85 = (47866.880889736545 / fConst0);
		fConst86 = (fConst85 + 271.60100965077754);
		fConst87 = ((((9521.1776510740765 / fConst0) + 186.95163235964782) / fConst0) + 1.0);
		fConst88 = (1.0 / fConst87);
		fConst89 = (1.0 / (fConst0 * fConst87));
		fConst90 = (38084.710604296306 / fConst0);
		fConst91 = (fConst90 + 373.90326471929563);
		iConst92 = int(((0.0007546298522354718 * fConst0) + 0.5));
		fConst93 = (1.0 / ((((6118.1542368773398 / fConst0) + 113.18864471022512) / fConst0) + 1.0));
		fConst94 = (24472.616947509359 / fConst0);
		fConst95 = (fConst94 + 226.37728942045024);
		fConst96 = ((71.467716130467849 / fConst0) + 1.0);
		fConst97 = (1.0 / fConst96);
		fConst98 = (142.9354322609357 / (fConst0 * fConst96));
		fConst99 = (1.0 / ((((17197.042330535627 / fConst0) + 143.0886323217992) / fConst0) + 1.0));
		fConst100 = (68788.169322142508 / fConst0);
		fConst101 = (fConst100 + 286.17726464359839);
		fConst102 = ((112.2322463251477 / fConst0) + 1.0);
		fConst103 = ((((13518.406533001747 / fConst0) + 206.32002345478514) / fConst0) + 1.0);
		fConst104 = (1.0 / (fConst102 * fConst103));
		fConst105 = (1.0 / (fConst0 * fConst103));
		fConst106 = (54073.62613200699 / fConst0);
		fConst107 = (fConst106 + 412.64004690957029);
		fConst108 = (224.4644926502954 / (fConst0 * fConst102));
		fConst109 = (1.0 / ((30.776060140115494 / fConst0) + 1.0));
		fConst110 = (61.552120280230987 / fConst0);
		fConst111 = (1.0 / ((((2841.4976332440169 / fConst0) + 92.328180420346484) / fConst0) + 1.0));
		fConst112 = (11365.990532976068 / fConst0);
		fConst113 = (fConst112 + 184.65636084069297);
		fConst114 = (1.0 / ((((10880.852622069639 / fConst0) + 129.49269801947491) / fConst0) + 1.0));
		fConst115 = (43523.410488278554 / fConst0);
		fConst116 = (fConst115 + 258.98539603894983);
		fConst117 = ((((8657.2200974217594 / fConst0) + 178.26790338167996) / fConst0) + 1.0);
		fConst118 = (1.0 / fConst117);
		fConst119 = (1.0 / (fConst0 * fConst117));
		fConst120 = (34628.880389687038 / fConst0);
		fConst121 = (fConst120 + 356.53580676335991);
		
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
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec24[l12] = 0.0;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec15[l13] = 0.0;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec13[l14] = 0.0;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec12[l15] = 0.0;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec10[l16] = 0.0;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec9[l17] = 0.0;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec7[l18] = 0.0;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec6[l19] = 0.0;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec4[l20] = 0.0;
			
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
		for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) {
			fRec40[l27] = 0.0;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec33[l28] = 0.0;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec31[l29] = 0.0;
			
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec30[l30] = 0.0;
			
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec28[l31] = 0.0;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec27[l32] = 0.0;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec25[l33] = 0.0;
			
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec47[l34] = 0.0;
			
		}
		for (int l35 = 0; (l35 < 3); l35 = (l35 + 1)) {
			fRec48[l35] = 0.0;
			
		}
		for (int l36 = 0; (l36 < 3); l36 = (l36 + 1)) {
			fRec49[l36] = 0.0;
			
		}
		for (int l37 = 0; (l37 < 3); l37 = (l37 + 1)) {
			fRec50[l37] = 0.0;
			
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec51[l38] = 0.0;
			
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec46[l39] = 0.0;
			
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec44[l40] = 0.0;
			
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			fRec43[l41] = 0.0;
			
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec41[l42] = 0.0;
			
		}
		for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) {
			fRec55[l43] = 0.0;
			
		}
		for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) {
			fRec56[l44] = 0.0;
			
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec57[l45] = 0.0;
			
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec54[l46] = 0.0;
			
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec52[l47] = 0.0;
			
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
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec72[l59] = 0.0;
			
		}
		for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) {
			fRec70[l60] = 0.0;
			
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fRec69[l61] = 0.0;
			
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec67[l62] = 0.0;
			
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec66[l63] = 0.0;
			
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec64[l64] = 0.0;
			
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fRec63[l65] = 0.0;
			
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec61[l66] = 0.0;
			
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec60[l67] = 0.0;
			
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec58[l68] = 0.0;
			
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
			fRec122[l94] = 0.0;
			
		}
		for (int l95 = 0; (l95 < 2); l95 = (l95 + 1)) {
			fRec120[l95] = 0.0;
			
		}
		for (int l96 = 0; (l96 < 2); l96 = (l96 + 1)) {
			fRec128[l96] = 0.0;
			
		}
		for (int l97 = 0; (l97 < 2); l97 = (l97 + 1)) {
			fRec126[l97] = 0.0;
			
		}
		for (int l98 = 0; (l98 < 2); l98 = (l98 + 1)) {
			fRec125[l98] = 0.0;
			
		}
		for (int l99 = 0; (l99 < 2); l99 = (l99 + 1)) {
			fRec123[l99] = 0.0;
			
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
			fRec167[l125] = 0.0;
			
		}
		for (int l126 = 0; (l126 < 2); l126 = (l126 + 1)) {
			fRec165[l126] = 0.0;
			
		}
		for (int l127 = 0; (l127 < 2); l127 = (l127 + 1)) {
			fRec173[l127] = 0.0;
			
		}
		for (int l128 = 0; (l128 < 2); l128 = (l128 + 1)) {
			fRec171[l128] = 0.0;
			
		}
		for (int l129 = 0; (l129 < 2); l129 = (l129 + 1)) {
			fRec170[l129] = 0.0;
			
		}
		for (int l130 = 0; (l130 < 2); l130 = (l130 + 1)) {
			fRec168[l130] = 0.0;
			
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
			fRec212[l156] = 0.0;
			
		}
		for (int l157 = 0; (l157 < 2); l157 = (l157 + 1)) {
			fRec210[l157] = 0.0;
			
		}
		for (int l158 = 0; (l158 < 2); l158 = (l158 + 1)) {
			fRec218[l158] = 0.0;
			
		}
		for (int l159 = 0; (l159 < 2); l159 = (l159 + 1)) {
			fRec216[l159] = 0.0;
			
		}
		for (int l160 = 0; (l160 < 2); l160 = (l160 + 1)) {
			fRec215[l160] = 0.0;
			
		}
		for (int l161 = 0; (l161 < 2); l161 = (l161 + 1)) {
			fRec213[l161] = 0.0;
			
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
			fRec239[l173] = 0.0;
			
		}
		for (int l174 = 0; (l174 < 2); l174 = (l174 + 1)) {
			fRec237[l174] = 0.0;
			
		}
		for (int l175 = 0; (l175 < 2); l175 = (l175 + 1)) {
			fRec236[l175] = 0.0;
			
		}
		for (int l176 = 0; (l176 < 2); l176 = (l176 + 1)) {
			fRec234[l176] = 0.0;
			
		}
		for (int l177 = 0; (l177 < 2); l177 = (l177 + 1)) {
			fRec242[l177] = 0.0;
			
		}
		for (int l178 = 0; (l178 < 2); l178 = (l178 + 1)) {
			fRec240[l178] = 0.0;
			
		}
		for (int l179 = 0; (l179 < 2); l179 = (l179 + 1)) {
			fRec251[l179] = 0.0;
			
		}
		for (int l180 = 0; (l180 < 2); l180 = (l180 + 1)) {
			fRec249[l180] = 0.0;
			
		}
		for (int l181 = 0; (l181 < 2); l181 = (l181 + 1)) {
			fRec248[l181] = 0.0;
			
		}
		for (int l182 = 0; (l182 < 2); l182 = (l182 + 1)) {
			fRec246[l182] = 0.0;
			
		}
		for (int l183 = 0; (l183 < 2); l183 = (l183 + 1)) {
			fRec245[l183] = 0.0;
			
		}
		for (int l184 = 0; (l184 < 2); l184 = (l184 + 1)) {
			fRec243[l184] = 0.0;
			
		}
		for (int l185 = 0; (l185 < 2); l185 = (l185 + 1)) {
			fRec263[l185] = 0.0;
			
		}
		for (int l186 = 0; (l186 < 2); l186 = (l186 + 1)) {
			fRec261[l186] = 0.0;
			
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
			fRec254[l191] = 0.0;
			
		}
		for (int l192 = 0; (l192 < 2); l192 = (l192 + 1)) {
			fRec252[l192] = 0.0;
			
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
			fRec284[l204] = 0.0;
			
		}
		for (int l205 = 0; (l205 < 2); l205 = (l205 + 1)) {
			fRec282[l205] = 0.0;
			
		}
		for (int l206 = 0; (l206 < 2); l206 = (l206 + 1)) {
			fRec281[l206] = 0.0;
			
		}
		for (int l207 = 0; (l207 < 2); l207 = (l207 + 1)) {
			fRec279[l207] = 0.0;
			
		}
		for (int l208 = 0; (l208 < 2); l208 = (l208 + 1)) {
			fRec287[l208] = 0.0;
			
		}
		for (int l209 = 0; (l209 < 2); l209 = (l209 + 1)) {
			fRec285[l209] = 0.0;
			
		}
		for (int l210 = 0; (l210 < 2); l210 = (l210 + 1)) {
			fRec296[l210] = 0.0;
			
		}
		for (int l211 = 0; (l211 < 2); l211 = (l211 + 1)) {
			fRec294[l211] = 0.0;
			
		}
		for (int l212 = 0; (l212 < 2); l212 = (l212 + 1)) {
			fRec293[l212] = 0.0;
			
		}
		for (int l213 = 0; (l213 < 2); l213 = (l213 + 1)) {
			fRec291[l213] = 0.0;
			
		}
		for (int l214 = 0; (l214 < 2); l214 = (l214 + 1)) {
			fRec290[l214] = 0.0;
			
		}
		for (int l215 = 0; (l215 < 2); l215 = (l215 + 1)) {
			fRec288[l215] = 0.0;
			
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
			fRec527[l373] = 0.0;
			
		}
		for (int l374 = 0; (l374 < 2); l374 = (l374 + 1)) {
			fRec525[l374] = 0.0;
			
		}
		for (int l375 = 0; (l375 < 2); l375 = (l375 + 1)) {
			fRec533[l375] = 0.0;
			
		}
		for (int l376 = 0; (l376 < 2); l376 = (l376 + 1)) {
			fRec531[l376] = 0.0;
			
		}
		for (int l377 = 0; (l377 < 2); l377 = (l377 + 1)) {
			fRec530[l377] = 0.0;
			
		}
		for (int l378 = 0; (l378 < 2); l378 = (l378 + 1)) {
			fRec528[l378] = 0.0;
			
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
			fRec587[l411] = 0.0;
			
		}
		for (int l412 = 0; (l412 < 2); l412 = (l412 + 1)) {
			fRec585[l412] = 0.0;
			
		}
		for (int l413 = 0; (l413 < 2); l413 = (l413 + 1)) {
			fRec584[l413] = 0.0;
			
		}
		for (int l414 = 0; (l414 < 2); l414 = (l414 + 1)) {
			fRec582[l414] = 0.0;
			
		}
		for (int l415 = 0; (l415 < 2); l415 = (l415 + 1)) {
			fRec581[l415] = 0.0;
			
		}
		for (int l416 = 0; (l416 < 2); l416 = (l416 + 1)) {
			fRec579[l416] = 0.0;
			
		}
		for (int l417 = 0; (l417 < 2); l417 = (l417 + 1)) {
			fRec593[l417] = 0.0;
			
		}
		for (int l418 = 0; (l418 < 2); l418 = (l418 + 1)) {
			fRec591[l418] = 0.0;
			
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
			fRec608[l423] = 0.0;
			
		}
		for (int l424 = 0; (l424 < 2); l424 = (l424 + 1)) {
			fRec606[l424] = 0.0;
			
		}
		for (int l425 = 0; (l425 < 2); l425 = (l425 + 1)) {
			fRec605[l425] = 0.0;
			
		}
		for (int l426 = 0; (l426 < 2); l426 = (l426 + 1)) {
			fRec603[l426] = 0.0;
			
		}
		for (int l427 = 0; (l427 < 2); l427 = (l427 + 1)) {
			fRec602[l427] = 0.0;
			
		}
		for (int l428 = 0; (l428 < 2); l428 = (l428 + 1)) {
			fRec600[l428] = 0.0;
			
		}
		for (int l429 = 0; (l429 < 2); l429 = (l429 + 1)) {
			fRec599[l429] = 0.0;
			
		}
		for (int l430 = 0; (l430 < 2); l430 = (l430 + 1)) {
			fRec597[l430] = 0.0;
			
		}
		for (int l431 = 0; (l431 < 2); l431 = (l431 + 1)) {
			fRec623[l431] = 0.0;
			
		}
		for (int l432 = 0; (l432 < 2); l432 = (l432 + 1)) {
			fRec621[l432] = 0.0;
			
		}
		for (int l433 = 0; (l433 < 2); l433 = (l433 + 1)) {
			fRec620[l433] = 0.0;
			
		}
		for (int l434 = 0; (l434 < 2); l434 = (l434 + 1)) {
			fRec618[l434] = 0.0;
			
		}
		for (int l435 = 0; (l435 < 2); l435 = (l435 + 1)) {
			fRec617[l435] = 0.0;
			
		}
		for (int l436 = 0; (l436 < 2); l436 = (l436 + 1)) {
			fRec615[l436] = 0.0;
			
		}
		for (int l437 = 0; (l437 < 2); l437 = (l437 + 1)) {
			fRec614[l437] = 0.0;
			
		}
		for (int l438 = 0; (l438 < 2); l438 = (l438 + 1)) {
			fRec612[l438] = 0.0;
			
		}
		for (int l439 = 0; (l439 < 2); l439 = (l439 + 1)) {
			fRec611[l439] = 0.0;
			
		}
		for (int l440 = 0; (l440 < 2); l440 = (l440 + 1)) {
			fRec609[l440] = 0.0;
			
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
			fRec854[l597] = 0.0;
			
		}
		for (int l598 = 0; (l598 < 2); l598 = (l598 + 1)) {
			fRec852[l598] = 0.0;
			
		}
		for (int l599 = 0; (l599 < 2); l599 = (l599 + 1)) {
			fRec851[l599] = 0.0;
			
		}
		for (int l600 = 0; (l600 < 2); l600 = (l600 + 1)) {
			fRec849[l600] = 0.0;
			
		}
		for (int l601 = 0; (l601 < 2); l601 = (l601 + 1)) {
			fRec857[l601] = 0.0;
			
		}
		for (int l602 = 0; (l602 < 2); l602 = (l602 + 1)) {
			fRec855[l602] = 0.0;
			
		}
		for (int l603 = 0; (l603 < 2); l603 = (l603 + 1)) {
			fRec869[l603] = 0.0;
			
		}
		for (int l604 = 0; (l604 < 2); l604 = (l604 + 1)) {
			fRec867[l604] = 0.0;
			
		}
		for (int l605 = 0; (l605 < 2); l605 = (l605 + 1)) {
			fRec866[l605] = 0.0;
			
		}
		for (int l606 = 0; (l606 < 2); l606 = (l606 + 1)) {
			fRec864[l606] = 0.0;
			
		}
		for (int l607 = 0; (l607 < 2); l607 = (l607 + 1)) {
			fRec863[l607] = 0.0;
			
		}
		for (int l608 = 0; (l608 < 2); l608 = (l608 + 1)) {
			fRec861[l608] = 0.0;
			
		}
		for (int l609 = 0; (l609 < 2); l609 = (l609 + 1)) {
			fRec860[l609] = 0.0;
			
		}
		for (int l610 = 0; (l610 < 2); l610 = (l610 + 1)) {
			fRec858[l610] = 0.0;
			
		}
		for (int l611 = 0; (l611 < 2); l611 = (l611 + 1)) {
			fRec878[l611] = 0.0;
			
		}
		for (int l612 = 0; (l612 < 2); l612 = (l612 + 1)) {
			fRec876[l612] = 0.0;
			
		}
		for (int l613 = 0; (l613 < 2); l613 = (l613 + 1)) {
			fRec875[l613] = 0.0;
			
		}
		for (int l614 = 0; (l614 < 2); l614 = (l614 + 1)) {
			fRec873[l614] = 0.0;
			
		}
		for (int l615 = 0; (l615 < 2); l615 = (l615 + 1)) {
			fRec872[l615] = 0.0;
			
		}
		for (int l616 = 0; (l616 < 2); l616 = (l616 + 1)) {
			fRec870[l616] = 0.0;
			
		}
		for (int l617 = 0; (l617 < 2); l617 = (l617 + 1)) {
			fRec893[l617] = 0.0;
			
		}
		for (int l618 = 0; (l618 < 2); l618 = (l618 + 1)) {
			fRec891[l618] = 0.0;
			
		}
		for (int l619 = 0; (l619 < 2); l619 = (l619 + 1)) {
			fRec890[l619] = 0.0;
			
		}
		for (int l620 = 0; (l620 < 2); l620 = (l620 + 1)) {
			fRec888[l620] = 0.0;
			
		}
		for (int l621 = 0; (l621 < 2); l621 = (l621 + 1)) {
			fRec887[l621] = 0.0;
			
		}
		for (int l622 = 0; (l622 < 2); l622 = (l622 + 1)) {
			fRec885[l622] = 0.0;
			
		}
		for (int l623 = 0; (l623 < 2); l623 = (l623 + 1)) {
			fRec884[l623] = 0.0;
			
		}
		for (int l624 = 0; (l624 < 2); l624 = (l624 + 1)) {
			fRec882[l624] = 0.0;
			
		}
		for (int l625 = 0; (l625 < 2); l625 = (l625 + 1)) {
			fRec881[l625] = 0.0;
			
		}
		for (int l626 = 0; (l626 < 2); l626 = (l626 + 1)) {
			fRec879[l626] = 0.0;
			
		}
		for (int l627 = 0; (l627 < 512); l627 = (l627 + 1)) {
			fVec18[l627] = 0.0;
			
		}
		for (int l628 = 0; (l628 < 2); l628 = (l628 + 1)) {
			fRec902[l628] = 0.0;
			
		}
		for (int l629 = 0; (l629 < 2); l629 = (l629 + 1)) {
			fRec900[l629] = 0.0;
			
		}
		for (int l630 = 0; (l630 < 2); l630 = (l630 + 1)) {
			fRec899[l630] = 0.0;
			
		}
		for (int l631 = 0; (l631 < 2); l631 = (l631 + 1)) {
			fRec897[l631] = 0.0;
			
		}
		for (int l632 = 0; (l632 < 2); l632 = (l632 + 1)) {
			fRec896[l632] = 0.0;
			
		}
		for (int l633 = 0; (l633 < 2); l633 = (l633 + 1)) {
			fRec894[l633] = 0.0;
			
		}
		for (int l634 = 0; (l634 < 2); l634 = (l634 + 1)) {
			fRec917[l634] = 0.0;
			
		}
		for (int l635 = 0; (l635 < 2); l635 = (l635 + 1)) {
			fRec915[l635] = 0.0;
			
		}
		for (int l636 = 0; (l636 < 2); l636 = (l636 + 1)) {
			fRec914[l636] = 0.0;
			
		}
		for (int l637 = 0; (l637 < 2); l637 = (l637 + 1)) {
			fRec912[l637] = 0.0;
			
		}
		for (int l638 = 0; (l638 < 2); l638 = (l638 + 1)) {
			fRec911[l638] = 0.0;
			
		}
		for (int l639 = 0; (l639 < 2); l639 = (l639 + 1)) {
			fRec909[l639] = 0.0;
			
		}
		for (int l640 = 0; (l640 < 2); l640 = (l640 + 1)) {
			fRec908[l640] = 0.0;
			
		}
		for (int l641 = 0; (l641 < 2); l641 = (l641 + 1)) {
			fRec906[l641] = 0.0;
			
		}
		for (int l642 = 0; (l642 < 2); l642 = (l642 + 1)) {
			fRec905[l642] = 0.0;
			
		}
		for (int l643 = 0; (l643 < 2); l643 = (l643 + 1)) {
			fRec903[l643] = 0.0;
			
		}
		for (int l644 = 0; (l644 < 2); l644 = (l644 + 1)) {
			fRec929[l644] = 0.0;
			
		}
		for (int l645 = 0; (l645 < 2); l645 = (l645 + 1)) {
			fRec927[l645] = 0.0;
			
		}
		for (int l646 = 0; (l646 < 2); l646 = (l646 + 1)) {
			fRec926[l646] = 0.0;
			
		}
		for (int l647 = 0; (l647 < 2); l647 = (l647 + 1)) {
			fRec924[l647] = 0.0;
			
		}
		for (int l648 = 0; (l648 < 2); l648 = (l648 + 1)) {
			fRec923[l648] = 0.0;
			
		}
		for (int l649 = 0; (l649 < 2); l649 = (l649 + 1)) {
			fRec921[l649] = 0.0;
			
		}
		for (int l650 = 0; (l650 < 2); l650 = (l650 + 1)) {
			fRec920[l650] = 0.0;
			
		}
		for (int l651 = 0; (l651 < 2); l651 = (l651 + 1)) {
			fRec918[l651] = 0.0;
			
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
			fRec1085[l752] = 0.0;
			
		}
		for (int l753 = 0; (l753 < 2); l753 = (l753 + 1)) {
			fRec1083[l753] = 0.0;
			
		}
		for (int l754 = 0; (l754 < 2); l754 = (l754 + 1)) {
			fRec1082[l754] = 0.0;
			
		}
		for (int l755 = 0; (l755 < 2); l755 = (l755 + 1)) {
			fRec1080[l755] = 0.0;
			
		}
		for (int l756 = 0; (l756 < 2); l756 = (l756 + 1)) {
			fRec1079[l756] = 0.0;
			
		}
		for (int l757 = 0; (l757 < 2); l757 = (l757 + 1)) {
			fRec1077[l757] = 0.0;
			
		}
		for (int l758 = 0; (l758 < 2); l758 = (l758 + 1)) {
			fRec1076[l758] = 0.0;
			
		}
		for (int l759 = 0; (l759 < 2); l759 = (l759 + 1)) {
			fRec1074[l759] = 0.0;
			
		}
		for (int l760 = 0; (l760 < 2); l760 = (l760 + 1)) {
			fRec1100[l760] = 0.0;
			
		}
		for (int l761 = 0; (l761 < 2); l761 = (l761 + 1)) {
			fRec1098[l761] = 0.0;
			
		}
		for (int l762 = 0; (l762 < 2); l762 = (l762 + 1)) {
			fRec1097[l762] = 0.0;
			
		}
		for (int l763 = 0; (l763 < 2); l763 = (l763 + 1)) {
			fRec1095[l763] = 0.0;
			
		}
		for (int l764 = 0; (l764 < 2); l764 = (l764 + 1)) {
			fRec1094[l764] = 0.0;
			
		}
		for (int l765 = 0; (l765 < 2); l765 = (l765 + 1)) {
			fRec1092[l765] = 0.0;
			
		}
		for (int l766 = 0; (l766 < 2); l766 = (l766 + 1)) {
			fRec1091[l766] = 0.0;
			
		}
		for (int l767 = 0; (l767 < 2); l767 = (l767 + 1)) {
			fRec1089[l767] = 0.0;
			
		}
		for (int l768 = 0; (l768 < 2); l768 = (l768 + 1)) {
			fRec1088[l768] = 0.0;
			
		}
		for (int l769 = 0; (l769 < 2); l769 = (l769 + 1)) {
			fRec1086[l769] = 0.0;
			
		}
		for (int l770 = 0; (l770 < 2); l770 = (l770 + 1)) {
			fRec1103[l770] = 0.0;
			
		}
		for (int l771 = 0; (l771 < 2); l771 = (l771 + 1)) {
			fRec1101[l771] = 0.0;
			
		}
		for (int l772 = 0; (l772 < 2); l772 = (l772 + 1)) {
			fRec1109[l772] = 0.0;
			
		}
		for (int l773 = 0; (l773 < 2); l773 = (l773 + 1)) {
			fRec1107[l773] = 0.0;
			
		}
		for (int l774 = 0; (l774 < 2); l774 = (l774 + 1)) {
			fRec1106[l774] = 0.0;
			
		}
		for (int l775 = 0; (l775 < 2); l775 = (l775 + 1)) {
			fRec1104[l775] = 0.0;
			
		}
		for (int l776 = 0; (l776 < 2); l776 = (l776 + 1)) {
			fRec1118[l776] = 0.0;
			
		}
		for (int l777 = 0; (l777 < 2); l777 = (l777 + 1)) {
			fRec1116[l777] = 0.0;
			
		}
		for (int l778 = 0; (l778 < 2); l778 = (l778 + 1)) {
			fRec1115[l778] = 0.0;
			
		}
		for (int l779 = 0; (l779 < 2); l779 = (l779 + 1)) {
			fRec1113[l779] = 0.0;
			
		}
		for (int l780 = 0; (l780 < 2); l780 = (l780 + 1)) {
			fRec1112[l780] = 0.0;
			
		}
		for (int l781 = 0; (l781 < 2); l781 = (l781 + 1)) {
			fRec1110[l781] = 0.0;
			
		}
		for (int l782 = 0; (l782 < 512); l782 = (l782 + 1)) {
			fVec23[l782] = 0.0;
			
		}
		for (int l783 = 0; (l783 < 2); l783 = (l783 + 1)) {
			fRec1124[l783] = 0.0;
			
		}
		for (int l784 = 0; (l784 < 2); l784 = (l784 + 1)) {
			fRec1122[l784] = 0.0;
			
		}
		for (int l785 = 0; (l785 < 2); l785 = (l785 + 1)) {
			fRec1121[l785] = 0.0;
			
		}
		for (int l786 = 0; (l786 < 2); l786 = (l786 + 1)) {
			fRec1119[l786] = 0.0;
			
		}
		for (int l787 = 0; (l787 < 2); l787 = (l787 + 1)) {
			fRec1127[l787] = 0.0;
			
		}
		for (int l788 = 0; (l788 < 2); l788 = (l788 + 1)) {
			fRec1125[l788] = 0.0;
			
		}
		for (int l789 = 0; (l789 < 2); l789 = (l789 + 1)) {
			fRec1142[l789] = 0.0;
			
		}
		for (int l790 = 0; (l790 < 2); l790 = (l790 + 1)) {
			fRec1140[l790] = 0.0;
			
		}
		for (int l791 = 0; (l791 < 2); l791 = (l791 + 1)) {
			fRec1139[l791] = 0.0;
			
		}
		for (int l792 = 0; (l792 < 2); l792 = (l792 + 1)) {
			fRec1137[l792] = 0.0;
			
		}
		for (int l793 = 0; (l793 < 2); l793 = (l793 + 1)) {
			fRec1136[l793] = 0.0;
			
		}
		for (int l794 = 0; (l794 < 2); l794 = (l794 + 1)) {
			fRec1134[l794] = 0.0;
			
		}
		for (int l795 = 0; (l795 < 2); l795 = (l795 + 1)) {
			fRec1133[l795] = 0.0;
			
		}
		for (int l796 = 0; (l796 < 2); l796 = (l796 + 1)) {
			fRec1131[l796] = 0.0;
			
		}
		for (int l797 = 0; (l797 < 2); l797 = (l797 + 1)) {
			fRec1130[l797] = 0.0;
			
		}
		for (int l798 = 0; (l798 < 2); l798 = (l798 + 1)) {
			fRec1128[l798] = 0.0;
			
		}
		for (int l799 = 0; (l799 < 2); l799 = (l799 + 1)) {
			fRec1151[l799] = 0.0;
			
		}
		for (int l800 = 0; (l800 < 2); l800 = (l800 + 1)) {
			fRec1149[l800] = 0.0;
			
		}
		for (int l801 = 0; (l801 < 2); l801 = (l801 + 1)) {
			fRec1148[l801] = 0.0;
			
		}
		for (int l802 = 0; (l802 < 2); l802 = (l802 + 1)) {
			fRec1146[l802] = 0.0;
			
		}
		for (int l803 = 0; (l803 < 2); l803 = (l803 + 1)) {
			fRec1145[l803] = 0.0;
			
		}
		for (int l804 = 0; (l804 < 2); l804 = (l804 + 1)) {
			fRec1143[l804] = 0.0;
			
		}
		for (int l805 = 0; (l805 < 2); l805 = (l805 + 1)) {
			fRec1163[l805] = 0.0;
			
		}
		for (int l806 = 0; (l806 < 2); l806 = (l806 + 1)) {
			fRec1161[l806] = 0.0;
			
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
			fRec1154[l811] = 0.0;
			
		}
		for (int l812 = 0; (l812 < 2); l812 = (l812 + 1)) {
			fRec1152[l812] = 0.0;
			
		}
		for (int l813 = 0; (l813 < 256); l813 = (l813 + 1)) {
			fVec24[l813] = 0.0;
			
		}
		for (int l814 = 0; (l814 < 2); l814 = (l814 + 1)) {
			fRec1175[l814] = 0.0;
			
		}
		for (int l815 = 0; (l815 < 2); l815 = (l815 + 1)) {
			fRec1173[l815] = 0.0;
			
		}
		for (int l816 = 0; (l816 < 2); l816 = (l816 + 1)) {
			fRec1172[l816] = 0.0;
			
		}
		for (int l817 = 0; (l817 < 2); l817 = (l817 + 1)) {
			fRec1170[l817] = 0.0;
			
		}
		for (int l818 = 0; (l818 < 2); l818 = (l818 + 1)) {
			fRec1169[l818] = 0.0;
			
		}
		for (int l819 = 0; (l819 < 2); l819 = (l819 + 1)) {
			fRec1167[l819] = 0.0;
			
		}
		for (int l820 = 0; (l820 < 2); l820 = (l820 + 1)) {
			fRec1166[l820] = 0.0;
			
		}
		for (int l821 = 0; (l821 < 2); l821 = (l821 + 1)) {
			fRec1164[l821] = 0.0;
			
		}
		for (int l822 = 0; (l822 < 2); l822 = (l822 + 1)) {
			fRec1178[l822] = 0.0;
			
		}
		for (int l823 = 0; (l823 < 2); l823 = (l823 + 1)) {
			fRec1176[l823] = 0.0;
			
		}
		for (int l824 = 0; (l824 < 2); l824 = (l824 + 1)) {
			fRec1187[l824] = 0.0;
			
		}
		for (int l825 = 0; (l825 < 2); l825 = (l825 + 1)) {
			fRec1185[l825] = 0.0;
			
		}
		for (int l826 = 0; (l826 < 2); l826 = (l826 + 1)) {
			fRec1184[l826] = 0.0;
			
		}
		for (int l827 = 0; (l827 < 2); l827 = (l827 + 1)) {
			fRec1182[l827] = 0.0;
			
		}
		for (int l828 = 0; (l828 < 2); l828 = (l828 + 1)) {
			fRec1181[l828] = 0.0;
			
		}
		for (int l829 = 0; (l829 < 2); l829 = (l829 + 1)) {
			fRec1179[l829] = 0.0;
			
		}
		for (int l830 = 0; (l830 < 2); l830 = (l830 + 1)) {
			fRec1193[l830] = 0.0;
			
		}
		for (int l831 = 0; (l831 < 2); l831 = (l831 + 1)) {
			fRec1191[l831] = 0.0;
			
		}
		for (int l832 = 0; (l832 < 2); l832 = (l832 + 1)) {
			fRec1190[l832] = 0.0;
			
		}
		for (int l833 = 0; (l833 < 2); l833 = (l833 + 1)) {
			fRec1188[l833] = 0.0;
			
		}
		for (int l834 = 0; (l834 < 2); l834 = (l834 + 1)) {
			fRec1208[l834] = 0.0;
			
		}
		for (int l835 = 0; (l835 < 2); l835 = (l835 + 1)) {
			fRec1206[l835] = 0.0;
			
		}
		for (int l836 = 0; (l836 < 2); l836 = (l836 + 1)) {
			fRec1205[l836] = 0.0;
			
		}
		for (int l837 = 0; (l837 < 2); l837 = (l837 + 1)) {
			fRec1203[l837] = 0.0;
			
		}
		for (int l838 = 0; (l838 < 2); l838 = (l838 + 1)) {
			fRec1202[l838] = 0.0;
			
		}
		for (int l839 = 0; (l839 < 2); l839 = (l839 + 1)) {
			fRec1200[l839] = 0.0;
			
		}
		for (int l840 = 0; (l840 < 2); l840 = (l840 + 1)) {
			fRec1199[l840] = 0.0;
			
		}
		for (int l841 = 0; (l841 < 2); l841 = (l841 + 1)) {
			fRec1197[l841] = 0.0;
			
		}
		for (int l842 = 0; (l842 < 2); l842 = (l842 + 1)) {
			fRec1196[l842] = 0.0;
			
		}
		for (int l843 = 0; (l843 < 2); l843 = (l843 + 1)) {
			fRec1194[l843] = 0.0;
			
		}
		for (int l844 = 0; (l844 < 256); l844 = (l844 + 1)) {
			fVec25[l844] = 0.0;
			
		}
		for (int l845 = 0; (l845 < 2); l845 = (l845 + 1)) {
			fRec1214[l845] = 0.0;
			
		}
		for (int l846 = 0; (l846 < 2); l846 = (l846 + 1)) {
			fRec1212[l846] = 0.0;
			
		}
		for (int l847 = 0; (l847 < 2); l847 = (l847 + 1)) {
			fRec1211[l847] = 0.0;
			
		}
		for (int l848 = 0; (l848 < 2); l848 = (l848 + 1)) {
			fRec1209[l848] = 0.0;
			
		}
		for (int l849 = 0; (l849 < 2); l849 = (l849 + 1)) {
			fRec1217[l849] = 0.0;
			
		}
		for (int l850 = 0; (l850 < 2); l850 = (l850 + 1)) {
			fRec1215[l850] = 0.0;
			
		}
		for (int l851 = 0; (l851 < 2); l851 = (l851 + 1)) {
			fRec1226[l851] = 0.0;
			
		}
		for (int l852 = 0; (l852 < 2); l852 = (l852 + 1)) {
			fRec1224[l852] = 0.0;
			
		}
		for (int l853 = 0; (l853 < 2); l853 = (l853 + 1)) {
			fRec1223[l853] = 0.0;
			
		}
		for (int l854 = 0; (l854 < 2); l854 = (l854 + 1)) {
			fRec1221[l854] = 0.0;
			
		}
		for (int l855 = 0; (l855 < 2); l855 = (l855 + 1)) {
			fRec1220[l855] = 0.0;
			
		}
		for (int l856 = 0; (l856 < 2); l856 = (l856 + 1)) {
			fRec1218[l856] = 0.0;
			
		}
		for (int l857 = 0; (l857 < 2); l857 = (l857 + 1)) {
			fRec1238[l857] = 0.0;
			
		}
		for (int l858 = 0; (l858 < 2); l858 = (l858 + 1)) {
			fRec1236[l858] = 0.0;
			
		}
		for (int l859 = 0; (l859 < 2); l859 = (l859 + 1)) {
			fRec1235[l859] = 0.0;
			
		}
		for (int l860 = 0; (l860 < 2); l860 = (l860 + 1)) {
			fRec1233[l860] = 0.0;
			
		}
		for (int l861 = 0; (l861 < 2); l861 = (l861 + 1)) {
			fRec1232[l861] = 0.0;
			
		}
		for (int l862 = 0; (l862 < 2); l862 = (l862 + 1)) {
			fRec1230[l862] = 0.0;
			
		}
		for (int l863 = 0; (l863 < 2); l863 = (l863 + 1)) {
			fRec1229[l863] = 0.0;
			
		}
		for (int l864 = 0; (l864 < 2); l864 = (l864 + 1)) {
			fRec1227[l864] = 0.0;
			
		}
		for (int l865 = 0; (l865 < 2); l865 = (l865 + 1)) {
			fRec1253[l865] = 0.0;
			
		}
		for (int l866 = 0; (l866 < 2); l866 = (l866 + 1)) {
			fRec1251[l866] = 0.0;
			
		}
		for (int l867 = 0; (l867 < 2); l867 = (l867 + 1)) {
			fRec1250[l867] = 0.0;
			
		}
		for (int l868 = 0; (l868 < 2); l868 = (l868 + 1)) {
			fRec1248[l868] = 0.0;
			
		}
		for (int l869 = 0; (l869 < 2); l869 = (l869 + 1)) {
			fRec1247[l869] = 0.0;
			
		}
		for (int l870 = 0; (l870 < 2); l870 = (l870 + 1)) {
			fRec1245[l870] = 0.0;
			
		}
		for (int l871 = 0; (l871 < 2); l871 = (l871 + 1)) {
			fRec1244[l871] = 0.0;
			
		}
		for (int l872 = 0; (l872 < 2); l872 = (l872 + 1)) {
			fRec1242[l872] = 0.0;
			
		}
		for (int l873 = 0; (l873 < 2); l873 = (l873 + 1)) {
			fRec1241[l873] = 0.0;
			
		}
		for (int l874 = 0; (l874 < 2); l874 = (l874 + 1)) {
			fRec1239[l874] = 0.0;
			
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
			fRec1277[l886] = 0.0;
			
		}
		for (int l887 = 0; (l887 < 2); l887 = (l887 + 1)) {
			fRec1275[l887] = 0.0;
			
		}
		for (int l888 = 0; (l888 < 2); l888 = (l888 + 1)) {
			fRec1274[l888] = 0.0;
			
		}
		for (int l889 = 0; (l889 < 2); l889 = (l889 + 1)) {
			fRec1272[l889] = 0.0;
			
		}
		for (int l890 = 0; (l890 < 2); l890 = (l890 + 1)) {
			fRec1271[l890] = 0.0;
			
		}
		for (int l891 = 0; (l891 < 2); l891 = (l891 + 1)) {
			fRec1269[l891] = 0.0;
			
		}
		for (int l892 = 0; (l892 < 2); l892 = (l892 + 1)) {
			fRec1289[l892] = 0.0;
			
		}
		for (int l893 = 0; (l893 < 2); l893 = (l893 + 1)) {
			fRec1287[l893] = 0.0;
			
		}
		for (int l894 = 0; (l894 < 2); l894 = (l894 + 1)) {
			fRec1286[l894] = 0.0;
			
		}
		for (int l895 = 0; (l895 < 2); l895 = (l895 + 1)) {
			fRec1284[l895] = 0.0;
			
		}
		for (int l896 = 0; (l896 < 2); l896 = (l896 + 1)) {
			fRec1283[l896] = 0.0;
			
		}
		for (int l897 = 0; (l897 < 2); l897 = (l897 + 1)) {
			fRec1281[l897] = 0.0;
			
		}
		for (int l898 = 0; (l898 < 2); l898 = (l898 + 1)) {
			fRec1280[l898] = 0.0;
			
		}
		for (int l899 = 0; (l899 < 2); l899 = (l899 + 1)) {
			fRec1278[l899] = 0.0;
			
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
			fRec1307[l907] = 0.0;
			
		}
		for (int l908 = 0; (l908 < 2); l908 = (l908 + 1)) {
			fRec1305[l908] = 0.0;
			
		}
		for (int l909 = 0; (l909 < 2); l909 = (l909 + 1)) {
			fRec1304[l909] = 0.0;
			
		}
		for (int l910 = 0; (l910 < 2); l910 = (l910 + 1)) {
			fRec1302[l910] = 0.0;
			
		}
		for (int l911 = 0; (l911 < 2); l911 = (l911 + 1)) {
			fRec1301[l911] = 0.0;
			
		}
		for (int l912 = 0; (l912 < 2); l912 = (l912 + 1)) {
			fRec1299[l912] = 0.0;
			
		}
		for (int l913 = 0; (l913 < 2); l913 = (l913 + 1)) {
			fRec1322[l913] = 0.0;
			
		}
		for (int l914 = 0; (l914 < 2); l914 = (l914 + 1)) {
			fRec1320[l914] = 0.0;
			
		}
		for (int l915 = 0; (l915 < 2); l915 = (l915 + 1)) {
			fRec1319[l915] = 0.0;
			
		}
		for (int l916 = 0; (l916 < 2); l916 = (l916 + 1)) {
			fRec1317[l916] = 0.0;
			
		}
		for (int l917 = 0; (l917 < 2); l917 = (l917 + 1)) {
			fRec1316[l917] = 0.0;
			
		}
		for (int l918 = 0; (l918 < 2); l918 = (l918 + 1)) {
			fRec1314[l918] = 0.0;
			
		}
		for (int l919 = 0; (l919 < 2); l919 = (l919 + 1)) {
			fRec1313[l919] = 0.0;
			
		}
		for (int l920 = 0; (l920 < 2); l920 = (l920 + 1)) {
			fRec1311[l920] = 0.0;
			
		}
		for (int l921 = 0; (l921 < 2); l921 = (l921 + 1)) {
			fRec1310[l921] = 0.0;
			
		}
		for (int l922 = 0; (l922 < 2); l922 = (l922 + 1)) {
			fRec1308[l922] = 0.0;
			
		}
		for (int l923 = 0; (l923 < 2); l923 = (l923 + 1)) {
			fRec1325[l923] = 0.0;
			
		}
		for (int l924 = 0; (l924 < 2); l924 = (l924 + 1)) {
			fRec1323[l924] = 0.0;
			
		}
		for (int l925 = 0; (l925 < 2); l925 = (l925 + 1)) {
			fRec1331[l925] = 0.0;
			
		}
		for (int l926 = 0; (l926 < 2); l926 = (l926 + 1)) {
			fRec1329[l926] = 0.0;
			
		}
		for (int l927 = 0; (l927 < 2); l927 = (l927 + 1)) {
			fRec1328[l927] = 0.0;
			
		}
		for (int l928 = 0; (l928 < 2); l928 = (l928 + 1)) {
			fRec1326[l928] = 0.0;
			
		}
		for (int l929 = 0; (l929 < 2); l929 = (l929 + 1)) {
			fRec1343[l929] = 0.0;
			
		}
		for (int l930 = 0; (l930 < 2); l930 = (l930 + 1)) {
			fRec1341[l930] = 0.0;
			
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
			fRec1334[l935] = 0.0;
			
		}
		for (int l936 = 0; (l936 < 2); l936 = (l936 + 1)) {
			fRec1332[l936] = 0.0;
			
		}
		for (int l937 = 0; (l937 < 2); l937 = (l937 + 1)) {
			fRec1352[l937] = 0.0;
			
		}
		for (int l938 = 0; (l938 < 2); l938 = (l938 + 1)) {
			fRec1350[l938] = 0.0;
			
		}
		for (int l939 = 0; (l939 < 2); l939 = (l939 + 1)) {
			fRec1349[l939] = 0.0;
			
		}
		for (int l940 = 0; (l940 < 2); l940 = (l940 + 1)) {
			fRec1347[l940] = 0.0;
			
		}
		for (int l941 = 0; (l941 < 2); l941 = (l941 + 1)) {
			fRec1346[l941] = 0.0;
			
		}
		for (int l942 = 0; (l942 < 2); l942 = (l942 + 1)) {
			fRec1344[l942] = 0.0;
			
		}
		for (int l943 = 0; (l943 < 2); l943 = (l943 + 1)) {
			fRec1358[l943] = 0.0;
			
		}
		for (int l944 = 0; (l944 < 2); l944 = (l944 + 1)) {
			fRec1356[l944] = 0.0;
			
		}
		for (int l945 = 0; (l945 < 2); l945 = (l945 + 1)) {
			fRec1355[l945] = 0.0;
			
		}
		for (int l946 = 0; (l946 < 2); l946 = (l946 + 1)) {
			fRec1353[l946] = 0.0;
			
		}
		for (int l947 = 0; (l947 < 2); l947 = (l947 + 1)) {
			fRec1370[l947] = 0.0;
			
		}
		for (int l948 = 0; (l948 < 2); l948 = (l948 + 1)) {
			fRec1368[l948] = 0.0;
			
		}
		for (int l949 = 0; (l949 < 2); l949 = (l949 + 1)) {
			fRec1367[l949] = 0.0;
			
		}
		for (int l950 = 0; (l950 < 2); l950 = (l950 + 1)) {
			fRec1365[l950] = 0.0;
			
		}
		for (int l951 = 0; (l951 < 2); l951 = (l951 + 1)) {
			fRec1364[l951] = 0.0;
			
		}
		for (int l952 = 0; (l952 < 2); l952 = (l952 + 1)) {
			fRec1362[l952] = 0.0;
			
		}
		for (int l953 = 0; (l953 < 2); l953 = (l953 + 1)) {
			fRec1361[l953] = 0.0;
			
		}
		for (int l954 = 0; (l954 < 2); l954 = (l954 + 1)) {
			fRec1359[l954] = 0.0;
			
		}
		for (int l955 = 0; (l955 < 2); l955 = (l955 + 1)) {
			fRec1373[l955] = 0.0;
			
		}
		for (int l956 = 0; (l956 < 2); l956 = (l956 + 1)) {
			fRec1371[l956] = 0.0;
			
		}
		for (int l957 = 0; (l957 < 2); l957 = (l957 + 1)) {
			fRec1388[l957] = 0.0;
			
		}
		for (int l958 = 0; (l958 < 2); l958 = (l958 + 1)) {
			fRec1386[l958] = 0.0;
			
		}
		for (int l959 = 0; (l959 < 2); l959 = (l959 + 1)) {
			fRec1385[l959] = 0.0;
			
		}
		for (int l960 = 0; (l960 < 2); l960 = (l960 + 1)) {
			fRec1383[l960] = 0.0;
			
		}
		for (int l961 = 0; (l961 < 2); l961 = (l961 + 1)) {
			fRec1382[l961] = 0.0;
			
		}
		for (int l962 = 0; (l962 < 2); l962 = (l962 + 1)) {
			fRec1380[l962] = 0.0;
			
		}
		for (int l963 = 0; (l963 < 2); l963 = (l963 + 1)) {
			fRec1379[l963] = 0.0;
			
		}
		for (int l964 = 0; (l964 < 2); l964 = (l964 + 1)) {
			fRec1377[l964] = 0.0;
			
		}
		for (int l965 = 0; (l965 < 2); l965 = (l965 + 1)) {
			fRec1376[l965] = 0.0;
			
		}
		for (int l966 = 0; (l966 < 2); l966 = (l966 + 1)) {
			fRec1374[l966] = 0.0;
			
		}
		for (int l967 = 0; (l967 < 1024); l967 = (l967 + 1)) {
			fVec28[l967] = 0.0;
			
		}
		for (int l968 = 0; (l968 < 2); l968 = (l968 + 1)) {
			fRec1394[l968] = 0.0;
			
		}
		for (int l969 = 0; (l969 < 2); l969 = (l969 + 1)) {
			fRec1392[l969] = 0.0;
			
		}
		for (int l970 = 0; (l970 < 2); l970 = (l970 + 1)) {
			fRec1391[l970] = 0.0;
			
		}
		for (int l971 = 0; (l971 < 2); l971 = (l971 + 1)) {
			fRec1389[l971] = 0.0;
			
		}
		for (int l972 = 0; (l972 < 2); l972 = (l972 + 1)) {
			fRec1403[l972] = 0.0;
			
		}
		for (int l973 = 0; (l973 < 2); l973 = (l973 + 1)) {
			fRec1401[l973] = 0.0;
			
		}
		for (int l974 = 0; (l974 < 2); l974 = (l974 + 1)) {
			fRec1400[l974] = 0.0;
			
		}
		for (int l975 = 0; (l975 < 2); l975 = (l975 + 1)) {
			fRec1398[l975] = 0.0;
			
		}
		for (int l976 = 0; (l976 < 2); l976 = (l976 + 1)) {
			fRec1397[l976] = 0.0;
			
		}
		for (int l977 = 0; (l977 < 2); l977 = (l977 + 1)) {
			fRec1395[l977] = 0.0;
			
		}
		for (int l978 = 0; (l978 < 2); l978 = (l978 + 1)) {
			fRec1406[l978] = 0.0;
			
		}
		for (int l979 = 0; (l979 < 2); l979 = (l979 + 1)) {
			fRec1404[l979] = 0.0;
			
		}
		for (int l980 = 0; (l980 < 2); l980 = (l980 + 1)) {
			fRec1418[l980] = 0.0;
			
		}
		for (int l981 = 0; (l981 < 2); l981 = (l981 + 1)) {
			fRec1416[l981] = 0.0;
			
		}
		for (int l982 = 0; (l982 < 2); l982 = (l982 + 1)) {
			fRec1415[l982] = 0.0;
			
		}
		for (int l983 = 0; (l983 < 2); l983 = (l983 + 1)) {
			fRec1413[l983] = 0.0;
			
		}
		for (int l984 = 0; (l984 < 2); l984 = (l984 + 1)) {
			fRec1412[l984] = 0.0;
			
		}
		for (int l985 = 0; (l985 < 2); l985 = (l985 + 1)) {
			fRec1410[l985] = 0.0;
			
		}
		for (int l986 = 0; (l986 < 2); l986 = (l986 + 1)) {
			fRec1409[l986] = 0.0;
			
		}
		for (int l987 = 0; (l987 < 2); l987 = (l987 + 1)) {
			fRec1407[l987] = 0.0;
			
		}
		for (int l988 = 0; (l988 < 2); l988 = (l988 + 1)) {
			fRec1433[l988] = 0.0;
			
		}
		for (int l989 = 0; (l989 < 2); l989 = (l989 + 1)) {
			fRec1431[l989] = 0.0;
			
		}
		for (int l990 = 0; (l990 < 2); l990 = (l990 + 1)) {
			fRec1430[l990] = 0.0;
			
		}
		for (int l991 = 0; (l991 < 2); l991 = (l991 + 1)) {
			fRec1428[l991] = 0.0;
			
		}
		for (int l992 = 0; (l992 < 2); l992 = (l992 + 1)) {
			fRec1427[l992] = 0.0;
			
		}
		for (int l993 = 0; (l993 < 2); l993 = (l993 + 1)) {
			fRec1425[l993] = 0.0;
			
		}
		for (int l994 = 0; (l994 < 2); l994 = (l994 + 1)) {
			fRec1424[l994] = 0.0;
			
		}
		for (int l995 = 0; (l995 < 2); l995 = (l995 + 1)) {
			fRec1422[l995] = 0.0;
			
		}
		for (int l996 = 0; (l996 < 2); l996 = (l996 + 1)) {
			fRec1421[l996] = 0.0;
			
		}
		for (int l997 = 0; (l997 < 2); l997 = (l997 + 1)) {
			fRec1419[l997] = 0.0;
			
		}
		for (int l998 = 0; (l998 < 1024); l998 = (l998 + 1)) {
			fVec29[l998] = 0.0;
			
		}
		for (int l999 = 0; (l999 < 2); l999 = (l999 + 1)) {
			fRec1445[l999] = 0.0;
			
		}
		for (int l1000 = 0; (l1000 < 2); l1000 = (l1000 + 1)) {
			fRec1443[l1000] = 0.0;
			
		}
		for (int l1001 = 0; (l1001 < 2); l1001 = (l1001 + 1)) {
			fRec1442[l1001] = 0.0;
			
		}
		for (int l1002 = 0; (l1002 < 2); l1002 = (l1002 + 1)) {
			fRec1440[l1002] = 0.0;
			
		}
		for (int l1003 = 0; (l1003 < 2); l1003 = (l1003 + 1)) {
			fRec1439[l1003] = 0.0;
			
		}
		for (int l1004 = 0; (l1004 < 2); l1004 = (l1004 + 1)) {
			fRec1437[l1004] = 0.0;
			
		}
		for (int l1005 = 0; (l1005 < 2); l1005 = (l1005 + 1)) {
			fRec1436[l1005] = 0.0;
			
		}
		for (int l1006 = 0; (l1006 < 2); l1006 = (l1006 + 1)) {
			fRec1434[l1006] = 0.0;
			
		}
		for (int l1007 = 0; (l1007 < 2); l1007 = (l1007 + 1)) {
			fRec1460[l1007] = 0.0;
			
		}
		for (int l1008 = 0; (l1008 < 2); l1008 = (l1008 + 1)) {
			fRec1458[l1008] = 0.0;
			
		}
		for (int l1009 = 0; (l1009 < 2); l1009 = (l1009 + 1)) {
			fRec1457[l1009] = 0.0;
			
		}
		for (int l1010 = 0; (l1010 < 2); l1010 = (l1010 + 1)) {
			fRec1455[l1010] = 0.0;
			
		}
		for (int l1011 = 0; (l1011 < 2); l1011 = (l1011 + 1)) {
			fRec1454[l1011] = 0.0;
			
		}
		for (int l1012 = 0; (l1012 < 2); l1012 = (l1012 + 1)) {
			fRec1452[l1012] = 0.0;
			
		}
		for (int l1013 = 0; (l1013 < 2); l1013 = (l1013 + 1)) {
			fRec1451[l1013] = 0.0;
			
		}
		for (int l1014 = 0; (l1014 < 2); l1014 = (l1014 + 1)) {
			fRec1449[l1014] = 0.0;
			
		}
		for (int l1015 = 0; (l1015 < 2); l1015 = (l1015 + 1)) {
			fRec1448[l1015] = 0.0;
			
		}
		for (int l1016 = 0; (l1016 < 2); l1016 = (l1016 + 1)) {
			fRec1446[l1016] = 0.0;
			
		}
		for (int l1017 = 0; (l1017 < 2); l1017 = (l1017 + 1)) {
			fRec1466[l1017] = 0.0;
			
		}
		for (int l1018 = 0; (l1018 < 2); l1018 = (l1018 + 1)) {
			fRec1464[l1018] = 0.0;
			
		}
		for (int l1019 = 0; (l1019 < 2); l1019 = (l1019 + 1)) {
			fRec1463[l1019] = 0.0;
			
		}
		for (int l1020 = 0; (l1020 < 2); l1020 = (l1020 + 1)) {
			fRec1461[l1020] = 0.0;
			
		}
		for (int l1021 = 0; (l1021 < 2); l1021 = (l1021 + 1)) {
			fRec1469[l1021] = 0.0;
			
		}
		for (int l1022 = 0; (l1022 < 2); l1022 = (l1022 + 1)) {
			fRec1467[l1022] = 0.0;
			
		}
		for (int l1023 = 0; (l1023 < 2); l1023 = (l1023 + 1)) {
			fRec1478[l1023] = 0.0;
			
		}
		for (int l1024 = 0; (l1024 < 2); l1024 = (l1024 + 1)) {
			fRec1476[l1024] = 0.0;
			
		}
		for (int l1025 = 0; (l1025 < 2); l1025 = (l1025 + 1)) {
			fRec1475[l1025] = 0.0;
			
		}
		for (int l1026 = 0; (l1026 < 2); l1026 = (l1026 + 1)) {
			fRec1473[l1026] = 0.0;
			
		}
		for (int l1027 = 0; (l1027 < 2); l1027 = (l1027 + 1)) {
			fRec1472[l1027] = 0.0;
			
		}
		for (int l1028 = 0; (l1028 < 2); l1028 = (l1028 + 1)) {
			fRec1470[l1028] = 0.0;
			
		}
		for (int l1029 = 0; (l1029 < 1024); l1029 = (l1029 + 1)) {
			fVec30[l1029] = 0.0;
			
		}
		for (int l1030 = 0; (l1030 < 2); l1030 = (l1030 + 1)) {
			fRec1493[l1030] = 0.0;
			
		}
		for (int l1031 = 0; (l1031 < 2); l1031 = (l1031 + 1)) {
			fRec1491[l1031] = 0.0;
			
		}
		for (int l1032 = 0; (l1032 < 2); l1032 = (l1032 + 1)) {
			fRec1490[l1032] = 0.0;
			
		}
		for (int l1033 = 0; (l1033 < 2); l1033 = (l1033 + 1)) {
			fRec1488[l1033] = 0.0;
			
		}
		for (int l1034 = 0; (l1034 < 2); l1034 = (l1034 + 1)) {
			fRec1487[l1034] = 0.0;
			
		}
		for (int l1035 = 0; (l1035 < 2); l1035 = (l1035 + 1)) {
			fRec1485[l1035] = 0.0;
			
		}
		for (int l1036 = 0; (l1036 < 2); l1036 = (l1036 + 1)) {
			fRec1484[l1036] = 0.0;
			
		}
		for (int l1037 = 0; (l1037 < 2); l1037 = (l1037 + 1)) {
			fRec1482[l1037] = 0.0;
			
		}
		for (int l1038 = 0; (l1038 < 2); l1038 = (l1038 + 1)) {
			fRec1481[l1038] = 0.0;
			
		}
		for (int l1039 = 0; (l1039 < 2); l1039 = (l1039 + 1)) {
			fRec1479[l1039] = 0.0;
			
		}
		for (int l1040 = 0; (l1040 < 2); l1040 = (l1040 + 1)) {
			fRec1499[l1040] = 0.0;
			
		}
		for (int l1041 = 0; (l1041 < 2); l1041 = (l1041 + 1)) {
			fRec1497[l1041] = 0.0;
			
		}
		for (int l1042 = 0; (l1042 < 2); l1042 = (l1042 + 1)) {
			fRec1496[l1042] = 0.0;
			
		}
		for (int l1043 = 0; (l1043 < 2); l1043 = (l1043 + 1)) {
			fRec1494[l1043] = 0.0;
			
		}
		for (int l1044 = 0; (l1044 < 2); l1044 = (l1044 + 1)) {
			fRec1511[l1044] = 0.0;
			
		}
		for (int l1045 = 0; (l1045 < 2); l1045 = (l1045 + 1)) {
			fRec1509[l1045] = 0.0;
			
		}
		for (int l1046 = 0; (l1046 < 2); l1046 = (l1046 + 1)) {
			fRec1508[l1046] = 0.0;
			
		}
		for (int l1047 = 0; (l1047 < 2); l1047 = (l1047 + 1)) {
			fRec1506[l1047] = 0.0;
			
		}
		for (int l1048 = 0; (l1048 < 2); l1048 = (l1048 + 1)) {
			fRec1505[l1048] = 0.0;
			
		}
		for (int l1049 = 0; (l1049 < 2); l1049 = (l1049 + 1)) {
			fRec1503[l1049] = 0.0;
			
		}
		for (int l1050 = 0; (l1050 < 2); l1050 = (l1050 + 1)) {
			fRec1502[l1050] = 0.0;
			
		}
		for (int l1051 = 0; (l1051 < 2); l1051 = (l1051 + 1)) {
			fRec1500[l1051] = 0.0;
			
		}
		for (int l1052 = 0; (l1052 < 2); l1052 = (l1052 + 1)) {
			fRec1514[l1052] = 0.0;
			
		}
		for (int l1053 = 0; (l1053 < 2); l1053 = (l1053 + 1)) {
			fRec1512[l1053] = 0.0;
			
		}
		for (int l1054 = 0; (l1054 < 2); l1054 = (l1054 + 1)) {
			fRec1523[l1054] = 0.0;
			
		}
		for (int l1055 = 0; (l1055 < 2); l1055 = (l1055 + 1)) {
			fRec1521[l1055] = 0.0;
			
		}
		for (int l1056 = 0; (l1056 < 2); l1056 = (l1056 + 1)) {
			fRec1520[l1056] = 0.0;
			
		}
		for (int l1057 = 0; (l1057 < 2); l1057 = (l1057 + 1)) {
			fRec1518[l1057] = 0.0;
			
		}
		for (int l1058 = 0; (l1058 < 2); l1058 = (l1058 + 1)) {
			fRec1517[l1058] = 0.0;
			
		}
		for (int l1059 = 0; (l1059 < 2); l1059 = (l1059 + 1)) {
			fRec1515[l1059] = 0.0;
			
		}
		for (int l1060 = 0; (l1060 < 1024); l1060 = (l1060 + 1)) {
			fVec31[l1060] = 0.0;
			
		}
		for (int l1061 = 0; (l1061 < 2); l1061 = (l1061 + 1)) {
			fRec1532[l1061] = 0.0;
			
		}
		for (int l1062 = 0; (l1062 < 2); l1062 = (l1062 + 1)) {
			fRec1530[l1062] = 0.0;
			
		}
		for (int l1063 = 0; (l1063 < 2); l1063 = (l1063 + 1)) {
			fRec1529[l1063] = 0.0;
			
		}
		for (int l1064 = 0; (l1064 < 2); l1064 = (l1064 + 1)) {
			fRec1527[l1064] = 0.0;
			
		}
		for (int l1065 = 0; (l1065 < 2); l1065 = (l1065 + 1)) {
			fRec1526[l1065] = 0.0;
			
		}
		for (int l1066 = 0; (l1066 < 2); l1066 = (l1066 + 1)) {
			fRec1524[l1066] = 0.0;
			
		}
		for (int l1067 = 0; (l1067 < 2); l1067 = (l1067 + 1)) {
			fRec1547[l1067] = 0.0;
			
		}
		for (int l1068 = 0; (l1068 < 2); l1068 = (l1068 + 1)) {
			fRec1545[l1068] = 0.0;
			
		}
		for (int l1069 = 0; (l1069 < 2); l1069 = (l1069 + 1)) {
			fRec1544[l1069] = 0.0;
			
		}
		for (int l1070 = 0; (l1070 < 2); l1070 = (l1070 + 1)) {
			fRec1542[l1070] = 0.0;
			
		}
		for (int l1071 = 0; (l1071 < 2); l1071 = (l1071 + 1)) {
			fRec1541[l1071] = 0.0;
			
		}
		for (int l1072 = 0; (l1072 < 2); l1072 = (l1072 + 1)) {
			fRec1539[l1072] = 0.0;
			
		}
		for (int l1073 = 0; (l1073 < 2); l1073 = (l1073 + 1)) {
			fRec1538[l1073] = 0.0;
			
		}
		for (int l1074 = 0; (l1074 < 2); l1074 = (l1074 + 1)) {
			fRec1536[l1074] = 0.0;
			
		}
		for (int l1075 = 0; (l1075 < 2); l1075 = (l1075 + 1)) {
			fRec1535[l1075] = 0.0;
			
		}
		for (int l1076 = 0; (l1076 < 2); l1076 = (l1076 + 1)) {
			fRec1533[l1076] = 0.0;
			
		}
		for (int l1077 = 0; (l1077 < 2); l1077 = (l1077 + 1)) {
			fRec1559[l1077] = 0.0;
			
		}
		for (int l1078 = 0; (l1078 < 2); l1078 = (l1078 + 1)) {
			fRec1557[l1078] = 0.0;
			
		}
		for (int l1079 = 0; (l1079 < 2); l1079 = (l1079 + 1)) {
			fRec1556[l1079] = 0.0;
			
		}
		for (int l1080 = 0; (l1080 < 2); l1080 = (l1080 + 1)) {
			fRec1554[l1080] = 0.0;
			
		}
		for (int l1081 = 0; (l1081 < 2); l1081 = (l1081 + 1)) {
			fRec1553[l1081] = 0.0;
			
		}
		for (int l1082 = 0; (l1082 < 2); l1082 = (l1082 + 1)) {
			fRec1551[l1082] = 0.0;
			
		}
		for (int l1083 = 0; (l1083 < 2); l1083 = (l1083 + 1)) {
			fRec1550[l1083] = 0.0;
			
		}
		for (int l1084 = 0; (l1084 < 2); l1084 = (l1084 + 1)) {
			fRec1548[l1084] = 0.0;
			
		}
		for (int l1085 = 0; (l1085 < 2); l1085 = (l1085 + 1)) {
			fRec1562[l1085] = 0.0;
			
		}
		for (int l1086 = 0; (l1086 < 2); l1086 = (l1086 + 1)) {
			fRec1560[l1086] = 0.0;
			
		}
		for (int l1087 = 0; (l1087 < 2); l1087 = (l1087 + 1)) {
			fRec1568[l1087] = 0.0;
			
		}
		for (int l1088 = 0; (l1088 < 2); l1088 = (l1088 + 1)) {
			fRec1566[l1088] = 0.0;
			
		}
		for (int l1089 = 0; (l1089 < 2); l1089 = (l1089 + 1)) {
			fRec1565[l1089] = 0.0;
			
		}
		for (int l1090 = 0; (l1090 < 2); l1090 = (l1090 + 1)) {
			fRec1563[l1090] = 0.0;
			
		}
		for (int l1091 = 0; (l1091 < 1024); l1091 = (l1091 + 1)) {
			fVec32[l1091] = 0.0;
			
		}
		for (int l1092 = 0; (l1092 < 2); l1092 = (l1092 + 1)) {
			fRec1580[l1092] = 0.0;
			
		}
		for (int l1093 = 0; (l1093 < 2); l1093 = (l1093 + 1)) {
			fRec1578[l1093] = 0.0;
			
		}
		for (int l1094 = 0; (l1094 < 2); l1094 = (l1094 + 1)) {
			fRec1577[l1094] = 0.0;
			
		}
		for (int l1095 = 0; (l1095 < 2); l1095 = (l1095 + 1)) {
			fRec1575[l1095] = 0.0;
			
		}
		for (int l1096 = 0; (l1096 < 2); l1096 = (l1096 + 1)) {
			fRec1574[l1096] = 0.0;
			
		}
		for (int l1097 = 0; (l1097 < 2); l1097 = (l1097 + 1)) {
			fRec1572[l1097] = 0.0;
			
		}
		for (int l1098 = 0; (l1098 < 2); l1098 = (l1098 + 1)) {
			fRec1571[l1098] = 0.0;
			
		}
		for (int l1099 = 0; (l1099 < 2); l1099 = (l1099 + 1)) {
			fRec1569[l1099] = 0.0;
			
		}
		for (int l1100 = 0; (l1100 < 2); l1100 = (l1100 + 1)) {
			fRec1583[l1100] = 0.0;
			
		}
		for (int l1101 = 0; (l1101 < 2); l1101 = (l1101 + 1)) {
			fRec1581[l1101] = 0.0;
			
		}
		for (int l1102 = 0; (l1102 < 2); l1102 = (l1102 + 1)) {
			fRec1592[l1102] = 0.0;
			
		}
		for (int l1103 = 0; (l1103 < 2); l1103 = (l1103 + 1)) {
			fRec1590[l1103] = 0.0;
			
		}
		for (int l1104 = 0; (l1104 < 2); l1104 = (l1104 + 1)) {
			fRec1589[l1104] = 0.0;
			
		}
		for (int l1105 = 0; (l1105 < 2); l1105 = (l1105 + 1)) {
			fRec1587[l1105] = 0.0;
			
		}
		for (int l1106 = 0; (l1106 < 2); l1106 = (l1106 + 1)) {
			fRec1586[l1106] = 0.0;
			
		}
		for (int l1107 = 0; (l1107 < 2); l1107 = (l1107 + 1)) {
			fRec1584[l1107] = 0.0;
			
		}
		for (int l1108 = 0; (l1108 < 2); l1108 = (l1108 + 1)) {
			fRec1598[l1108] = 0.0;
			
		}
		for (int l1109 = 0; (l1109 < 2); l1109 = (l1109 + 1)) {
			fRec1596[l1109] = 0.0;
			
		}
		for (int l1110 = 0; (l1110 < 2); l1110 = (l1110 + 1)) {
			fRec1595[l1110] = 0.0;
			
		}
		for (int l1111 = 0; (l1111 < 2); l1111 = (l1111 + 1)) {
			fRec1593[l1111] = 0.0;
			
		}
		for (int l1112 = 0; (l1112 < 2); l1112 = (l1112 + 1)) {
			fRec1613[l1112] = 0.0;
			
		}
		for (int l1113 = 0; (l1113 < 2); l1113 = (l1113 + 1)) {
			fRec1611[l1113] = 0.0;
			
		}
		for (int l1114 = 0; (l1114 < 2); l1114 = (l1114 + 1)) {
			fRec1610[l1114] = 0.0;
			
		}
		for (int l1115 = 0; (l1115 < 2); l1115 = (l1115 + 1)) {
			fRec1608[l1115] = 0.0;
			
		}
		for (int l1116 = 0; (l1116 < 2); l1116 = (l1116 + 1)) {
			fRec1607[l1116] = 0.0;
			
		}
		for (int l1117 = 0; (l1117 < 2); l1117 = (l1117 + 1)) {
			fRec1605[l1117] = 0.0;
			
		}
		for (int l1118 = 0; (l1118 < 2); l1118 = (l1118 + 1)) {
			fRec1604[l1118] = 0.0;
			
		}
		for (int l1119 = 0; (l1119 < 2); l1119 = (l1119 + 1)) {
			fRec1602[l1119] = 0.0;
			
		}
		for (int l1120 = 0; (l1120 < 2); l1120 = (l1120 + 1)) {
			fRec1601[l1120] = 0.0;
			
		}
		for (int l1121 = 0; (l1121 < 2); l1121 = (l1121 + 1)) {
			fRec1599[l1121] = 0.0;
			
		}
		for (int l1122 = 0; (l1122 < 1024); l1122 = (l1122 + 1)) {
			fVec33[l1122] = 0.0;
			
		}
		for (int l1123 = 0; (l1123 < 2); l1123 = (l1123 + 1)) {
			fRec1616[l1123] = 0.0;
			
		}
		for (int l1124 = 0; (l1124 < 2); l1124 = (l1124 + 1)) {
			fRec1614[l1124] = 0.0;
			
		}
		for (int l1125 = 0; (l1125 < 2); l1125 = (l1125 + 1)) {
			fRec1622[l1125] = 0.0;
			
		}
		for (int l1126 = 0; (l1126 < 2); l1126 = (l1126 + 1)) {
			fRec1620[l1126] = 0.0;
			
		}
		for (int l1127 = 0; (l1127 < 2); l1127 = (l1127 + 1)) {
			fRec1619[l1127] = 0.0;
			
		}
		for (int l1128 = 0; (l1128 < 2); l1128 = (l1128 + 1)) {
			fRec1617[l1128] = 0.0;
			
		}
		for (int l1129 = 0; (l1129 < 2); l1129 = (l1129 + 1)) {
			fRec1634[l1129] = 0.0;
			
		}
		for (int l1130 = 0; (l1130 < 2); l1130 = (l1130 + 1)) {
			fRec1632[l1130] = 0.0;
			
		}
		for (int l1131 = 0; (l1131 < 2); l1131 = (l1131 + 1)) {
			fRec1631[l1131] = 0.0;
			
		}
		for (int l1132 = 0; (l1132 < 2); l1132 = (l1132 + 1)) {
			fRec1629[l1132] = 0.0;
			
		}
		for (int l1133 = 0; (l1133 < 2); l1133 = (l1133 + 1)) {
			fRec1628[l1133] = 0.0;
			
		}
		for (int l1134 = 0; (l1134 < 2); l1134 = (l1134 + 1)) {
			fRec1626[l1134] = 0.0;
			
		}
		for (int l1135 = 0; (l1135 < 2); l1135 = (l1135 + 1)) {
			fRec1625[l1135] = 0.0;
			
		}
		for (int l1136 = 0; (l1136 < 2); l1136 = (l1136 + 1)) {
			fRec1623[l1136] = 0.0;
			
		}
		for (int l1137 = 0; (l1137 < 2); l1137 = (l1137 + 1)) {
			fRec1643[l1137] = 0.0;
			
		}
		for (int l1138 = 0; (l1138 < 2); l1138 = (l1138 + 1)) {
			fRec1641[l1138] = 0.0;
			
		}
		for (int l1139 = 0; (l1139 < 2); l1139 = (l1139 + 1)) {
			fRec1640[l1139] = 0.0;
			
		}
		for (int l1140 = 0; (l1140 < 2); l1140 = (l1140 + 1)) {
			fRec1638[l1140] = 0.0;
			
		}
		for (int l1141 = 0; (l1141 < 2); l1141 = (l1141 + 1)) {
			fRec1637[l1141] = 0.0;
			
		}
		for (int l1142 = 0; (l1142 < 2); l1142 = (l1142 + 1)) {
			fRec1635[l1142] = 0.0;
			
		}
		for (int l1143 = 0; (l1143 < 2); l1143 = (l1143 + 1)) {
			fRec1658[l1143] = 0.0;
			
		}
		for (int l1144 = 0; (l1144 < 2); l1144 = (l1144 + 1)) {
			fRec1656[l1144] = 0.0;
			
		}
		for (int l1145 = 0; (l1145 < 2); l1145 = (l1145 + 1)) {
			fRec1655[l1145] = 0.0;
			
		}
		for (int l1146 = 0; (l1146 < 2); l1146 = (l1146 + 1)) {
			fRec1653[l1146] = 0.0;
			
		}
		for (int l1147 = 0; (l1147 < 2); l1147 = (l1147 + 1)) {
			fRec1652[l1147] = 0.0;
			
		}
		for (int l1148 = 0; (l1148 < 2); l1148 = (l1148 + 1)) {
			fRec1650[l1148] = 0.0;
			
		}
		for (int l1149 = 0; (l1149 < 2); l1149 = (l1149 + 1)) {
			fRec1649[l1149] = 0.0;
			
		}
		for (int l1150 = 0; (l1150 < 2); l1150 = (l1150 + 1)) {
			fRec1647[l1150] = 0.0;
			
		}
		for (int l1151 = 0; (l1151 < 2); l1151 = (l1151 + 1)) {
			fRec1646[l1151] = 0.0;
			
		}
		for (int l1152 = 0; (l1152 < 2); l1152 = (l1152 + 1)) {
			fRec1644[l1152] = 0.0;
			
		}
		for (int l1153 = 0; (l1153 < 1024); l1153 = (l1153 + 1)) {
			fVec34[l1153] = 0.0;
			
		}
		for (int l1154 = 0; (l1154 < 2); l1154 = (l1154 + 1)) {
			fRec1667[l1154] = 0.0;
			
		}
		for (int l1155 = 0; (l1155 < 2); l1155 = (l1155 + 1)) {
			fRec1665[l1155] = 0.0;
			
		}
		for (int l1156 = 0; (l1156 < 2); l1156 = (l1156 + 1)) {
			fRec1664[l1156] = 0.0;
			
		}
		for (int l1157 = 0; (l1157 < 2); l1157 = (l1157 + 1)) {
			fRec1662[l1157] = 0.0;
			
		}
		for (int l1158 = 0; (l1158 < 2); l1158 = (l1158 + 1)) {
			fRec1661[l1158] = 0.0;
			
		}
		for (int l1159 = 0; (l1159 < 2); l1159 = (l1159 + 1)) {
			fRec1659[l1159] = 0.0;
			
		}
		for (int l1160 = 0; (l1160 < 2); l1160 = (l1160 + 1)) {
			fRec1673[l1160] = 0.0;
			
		}
		for (int l1161 = 0; (l1161 < 2); l1161 = (l1161 + 1)) {
			fRec1671[l1161] = 0.0;
			
		}
		for (int l1162 = 0; (l1162 < 2); l1162 = (l1162 + 1)) {
			fRec1670[l1162] = 0.0;
			
		}
		for (int l1163 = 0; (l1163 < 2); l1163 = (l1163 + 1)) {
			fRec1668[l1163] = 0.0;
			
		}
		for (int l1164 = 0; (l1164 < 2); l1164 = (l1164 + 1)) {
			fRec1676[l1164] = 0.0;
			
		}
		for (int l1165 = 0; (l1165 < 2); l1165 = (l1165 + 1)) {
			fRec1674[l1165] = 0.0;
			
		}
		for (int l1166 = 0; (l1166 < 2); l1166 = (l1166 + 1)) {
			fRec1688[l1166] = 0.0;
			
		}
		for (int l1167 = 0; (l1167 < 2); l1167 = (l1167 + 1)) {
			fRec1686[l1167] = 0.0;
			
		}
		for (int l1168 = 0; (l1168 < 2); l1168 = (l1168 + 1)) {
			fRec1685[l1168] = 0.0;
			
		}
		for (int l1169 = 0; (l1169 < 2); l1169 = (l1169 + 1)) {
			fRec1683[l1169] = 0.0;
			
		}
		for (int l1170 = 0; (l1170 < 2); l1170 = (l1170 + 1)) {
			fRec1682[l1170] = 0.0;
			
		}
		for (int l1171 = 0; (l1171 < 2); l1171 = (l1171 + 1)) {
			fRec1680[l1171] = 0.0;
			
		}
		for (int l1172 = 0; (l1172 < 2); l1172 = (l1172 + 1)) {
			fRec1679[l1172] = 0.0;
			
		}
		for (int l1173 = 0; (l1173 < 2); l1173 = (l1173 + 1)) {
			fRec1677[l1173] = 0.0;
			
		}
		for (int l1174 = 0; (l1174 < 2); l1174 = (l1174 + 1)) {
			fRec1703[l1174] = 0.0;
			
		}
		for (int l1175 = 0; (l1175 < 2); l1175 = (l1175 + 1)) {
			fRec1701[l1175] = 0.0;
			
		}
		for (int l1176 = 0; (l1176 < 2); l1176 = (l1176 + 1)) {
			fRec1700[l1176] = 0.0;
			
		}
		for (int l1177 = 0; (l1177 < 2); l1177 = (l1177 + 1)) {
			fRec1698[l1177] = 0.0;
			
		}
		for (int l1178 = 0; (l1178 < 2); l1178 = (l1178 + 1)) {
			fRec1697[l1178] = 0.0;
			
		}
		for (int l1179 = 0; (l1179 < 2); l1179 = (l1179 + 1)) {
			fRec1695[l1179] = 0.0;
			
		}
		for (int l1180 = 0; (l1180 < 2); l1180 = (l1180 + 1)) {
			fRec1694[l1180] = 0.0;
			
		}
		for (int l1181 = 0; (l1181 < 2); l1181 = (l1181 + 1)) {
			fRec1692[l1181] = 0.0;
			
		}
		for (int l1182 = 0; (l1182 < 2); l1182 = (l1182 + 1)) {
			fRec1691[l1182] = 0.0;
			
		}
		for (int l1183 = 0; (l1183 < 2); l1183 = (l1183 + 1)) {
			fRec1689[l1183] = 0.0;
			
		}
		for (int l1184 = 0; (l1184 < 1024); l1184 = (l1184 + 1)) {
			fVec35[l1184] = 0.0;
			
		}
		for (int l1185 = 0; (l1185 < 2); l1185 = (l1185 + 1)) {
			fRec1718[l1185] = 0.0;
			
		}
		for (int l1186 = 0; (l1186 < 2); l1186 = (l1186 + 1)) {
			fRec1716[l1186] = 0.0;
			
		}
		for (int l1187 = 0; (l1187 < 2); l1187 = (l1187 + 1)) {
			fRec1715[l1187] = 0.0;
			
		}
		for (int l1188 = 0; (l1188 < 2); l1188 = (l1188 + 1)) {
			fRec1713[l1188] = 0.0;
			
		}
		for (int l1189 = 0; (l1189 < 2); l1189 = (l1189 + 1)) {
			fRec1712[l1189] = 0.0;
			
		}
		for (int l1190 = 0; (l1190 < 2); l1190 = (l1190 + 1)) {
			fRec1710[l1190] = 0.0;
			
		}
		for (int l1191 = 0; (l1191 < 2); l1191 = (l1191 + 1)) {
			fRec1709[l1191] = 0.0;
			
		}
		for (int l1192 = 0; (l1192 < 2); l1192 = (l1192 + 1)) {
			fRec1707[l1192] = 0.0;
			
		}
		for (int l1193 = 0; (l1193 < 2); l1193 = (l1193 + 1)) {
			fRec1706[l1193] = 0.0;
			
		}
		for (int l1194 = 0; (l1194 < 2); l1194 = (l1194 + 1)) {
			fRec1704[l1194] = 0.0;
			
		}
		for (int l1195 = 0; (l1195 < 2); l1195 = (l1195 + 1)) {
			fRec1730[l1195] = 0.0;
			
		}
		for (int l1196 = 0; (l1196 < 2); l1196 = (l1196 + 1)) {
			fRec1728[l1196] = 0.0;
			
		}
		for (int l1197 = 0; (l1197 < 2); l1197 = (l1197 + 1)) {
			fRec1727[l1197] = 0.0;
			
		}
		for (int l1198 = 0; (l1198 < 2); l1198 = (l1198 + 1)) {
			fRec1725[l1198] = 0.0;
			
		}
		for (int l1199 = 0; (l1199 < 2); l1199 = (l1199 + 1)) {
			fRec1724[l1199] = 0.0;
			
		}
		for (int l1200 = 0; (l1200 < 2); l1200 = (l1200 + 1)) {
			fRec1722[l1200] = 0.0;
			
		}
		for (int l1201 = 0; (l1201 < 2); l1201 = (l1201 + 1)) {
			fRec1721[l1201] = 0.0;
			
		}
		for (int l1202 = 0; (l1202 < 2); l1202 = (l1202 + 1)) {
			fRec1719[l1202] = 0.0;
			
		}
		for (int l1203 = 0; (l1203 < 2); l1203 = (l1203 + 1)) {
			fRec1739[l1203] = 0.0;
			
		}
		for (int l1204 = 0; (l1204 < 2); l1204 = (l1204 + 1)) {
			fRec1737[l1204] = 0.0;
			
		}
		for (int l1205 = 0; (l1205 < 2); l1205 = (l1205 + 1)) {
			fRec1736[l1205] = 0.0;
			
		}
		for (int l1206 = 0; (l1206 < 2); l1206 = (l1206 + 1)) {
			fRec1734[l1206] = 0.0;
			
		}
		for (int l1207 = 0; (l1207 < 2); l1207 = (l1207 + 1)) {
			fRec1733[l1207] = 0.0;
			
		}
		for (int l1208 = 0; (l1208 < 2); l1208 = (l1208 + 1)) {
			fRec1731[l1208] = 0.0;
			
		}
		for (int l1209 = 0; (l1209 < 2); l1209 = (l1209 + 1)) {
			fRec1742[l1209] = 0.0;
			
		}
		for (int l1210 = 0; (l1210 < 2); l1210 = (l1210 + 1)) {
			fRec1740[l1210] = 0.0;
			
		}
		for (int l1211 = 0; (l1211 < 2); l1211 = (l1211 + 1)) {
			fRec1748[l1211] = 0.0;
			
		}
		for (int l1212 = 0; (l1212 < 2); l1212 = (l1212 + 1)) {
			fRec1746[l1212] = 0.0;
			
		}
		for (int l1213 = 0; (l1213 < 2); l1213 = (l1213 + 1)) {
			fRec1745[l1213] = 0.0;
			
		}
		for (int l1214 = 0; (l1214 < 2); l1214 = (l1214 + 1)) {
			fRec1743[l1214] = 0.0;
			
		}
		for (int l1215 = 0; (l1215 < 1024); l1215 = (l1215 + 1)) {
			fVec36[l1215] = 0.0;
			
		}
		for (int l1216 = 0; (l1216 < 2); l1216 = (l1216 + 1)) {
			fRec1754[l1216] = 0.0;
			
		}
		for (int l1217 = 0; (l1217 < 2); l1217 = (l1217 + 1)) {
			fRec1752[l1217] = 0.0;
			
		}
		for (int l1218 = 0; (l1218 < 2); l1218 = (l1218 + 1)) {
			fRec1751[l1218] = 0.0;
			
		}
		for (int l1219 = 0; (l1219 < 2); l1219 = (l1219 + 1)) {
			fRec1749[l1219] = 0.0;
			
		}
		for (int l1220 = 0; (l1220 < 2); l1220 = (l1220 + 1)) {
			fRec1769[l1220] = 0.0;
			
		}
		for (int l1221 = 0; (l1221 < 2); l1221 = (l1221 + 1)) {
			fRec1767[l1221] = 0.0;
			
		}
		for (int l1222 = 0; (l1222 < 2); l1222 = (l1222 + 1)) {
			fRec1766[l1222] = 0.0;
			
		}
		for (int l1223 = 0; (l1223 < 2); l1223 = (l1223 + 1)) {
			fRec1764[l1223] = 0.0;
			
		}
		for (int l1224 = 0; (l1224 < 2); l1224 = (l1224 + 1)) {
			fRec1763[l1224] = 0.0;
			
		}
		for (int l1225 = 0; (l1225 < 2); l1225 = (l1225 + 1)) {
			fRec1761[l1225] = 0.0;
			
		}
		for (int l1226 = 0; (l1226 < 2); l1226 = (l1226 + 1)) {
			fRec1760[l1226] = 0.0;
			
		}
		for (int l1227 = 0; (l1227 < 2); l1227 = (l1227 + 1)) {
			fRec1758[l1227] = 0.0;
			
		}
		for (int l1228 = 0; (l1228 < 2); l1228 = (l1228 + 1)) {
			fRec1757[l1228] = 0.0;
			
		}
		for (int l1229 = 0; (l1229 < 2); l1229 = (l1229 + 1)) {
			fRec1755[l1229] = 0.0;
			
		}
		for (int l1230 = 0; (l1230 < 2); l1230 = (l1230 + 1)) {
			fRec1781[l1230] = 0.0;
			
		}
		for (int l1231 = 0; (l1231 < 2); l1231 = (l1231 + 1)) {
			fRec1779[l1231] = 0.0;
			
		}
		for (int l1232 = 0; (l1232 < 2); l1232 = (l1232 + 1)) {
			fRec1778[l1232] = 0.0;
			
		}
		for (int l1233 = 0; (l1233 < 2); l1233 = (l1233 + 1)) {
			fRec1776[l1233] = 0.0;
			
		}
		for (int l1234 = 0; (l1234 < 2); l1234 = (l1234 + 1)) {
			fRec1775[l1234] = 0.0;
			
		}
		for (int l1235 = 0; (l1235 < 2); l1235 = (l1235 + 1)) {
			fRec1773[l1235] = 0.0;
			
		}
		for (int l1236 = 0; (l1236 < 2); l1236 = (l1236 + 1)) {
			fRec1772[l1236] = 0.0;
			
		}
		for (int l1237 = 0; (l1237 < 2); l1237 = (l1237 + 1)) {
			fRec1770[l1237] = 0.0;
			
		}
		for (int l1238 = 0; (l1238 < 2); l1238 = (l1238 + 1)) {
			fRec1784[l1238] = 0.0;
			
		}
		for (int l1239 = 0; (l1239 < 2); l1239 = (l1239 + 1)) {
			fRec1782[l1239] = 0.0;
			
		}
		for (int l1240 = 0; (l1240 < 2); l1240 = (l1240 + 1)) {
			fRec1793[l1240] = 0.0;
			
		}
		for (int l1241 = 0; (l1241 < 2); l1241 = (l1241 + 1)) {
			fRec1791[l1241] = 0.0;
			
		}
		for (int l1242 = 0; (l1242 < 2); l1242 = (l1242 + 1)) {
			fRec1790[l1242] = 0.0;
			
		}
		for (int l1243 = 0; (l1243 < 2); l1243 = (l1243 + 1)) {
			fRec1788[l1243] = 0.0;
			
		}
		for (int l1244 = 0; (l1244 < 2); l1244 = (l1244 + 1)) {
			fRec1787[l1244] = 0.0;
			
		}
		for (int l1245 = 0; (l1245 < 2); l1245 = (l1245 + 1)) {
			fRec1785[l1245] = 0.0;
			
		}
		for (int l1246 = 0; (l1246 < 1024); l1246 = (l1246 + 1)) {
			fVec37[l1246] = 0.0;
			
		}
		for (int l1247 = 0; (l1247 < 2); l1247 = (l1247 + 1)) {
			fRec1805[l1247] = 0.0;
			
		}
		for (int l1248 = 0; (l1248 < 2); l1248 = (l1248 + 1)) {
			fRec1803[l1248] = 0.0;
			
		}
		for (int l1249 = 0; (l1249 < 2); l1249 = (l1249 + 1)) {
			fRec1802[l1249] = 0.0;
			
		}
		for (int l1250 = 0; (l1250 < 2); l1250 = (l1250 + 1)) {
			fRec1800[l1250] = 0.0;
			
		}
		for (int l1251 = 0; (l1251 < 2); l1251 = (l1251 + 1)) {
			fRec1799[l1251] = 0.0;
			
		}
		for (int l1252 = 0; (l1252 < 2); l1252 = (l1252 + 1)) {
			fRec1797[l1252] = 0.0;
			
		}
		for (int l1253 = 0; (l1253 < 2); l1253 = (l1253 + 1)) {
			fRec1796[l1253] = 0.0;
			
		}
		for (int l1254 = 0; (l1254 < 2); l1254 = (l1254 + 1)) {
			fRec1794[l1254] = 0.0;
			
		}
		for (int l1255 = 0; (l1255 < 2); l1255 = (l1255 + 1)) {
			fRec1814[l1255] = 0.0;
			
		}
		for (int l1256 = 0; (l1256 < 2); l1256 = (l1256 + 1)) {
			fRec1812[l1256] = 0.0;
			
		}
		for (int l1257 = 0; (l1257 < 2); l1257 = (l1257 + 1)) {
			fRec1811[l1257] = 0.0;
			
		}
		for (int l1258 = 0; (l1258 < 2); l1258 = (l1258 + 1)) {
			fRec1809[l1258] = 0.0;
			
		}
		for (int l1259 = 0; (l1259 < 2); l1259 = (l1259 + 1)) {
			fRec1808[l1259] = 0.0;
			
		}
		for (int l1260 = 0; (l1260 < 2); l1260 = (l1260 + 1)) {
			fRec1806[l1260] = 0.0;
			
		}
		for (int l1261 = 0; (l1261 < 2); l1261 = (l1261 + 1)) {
			fRec1820[l1261] = 0.0;
			
		}
		for (int l1262 = 0; (l1262 < 2); l1262 = (l1262 + 1)) {
			fRec1818[l1262] = 0.0;
			
		}
		for (int l1263 = 0; (l1263 < 2); l1263 = (l1263 + 1)) {
			fRec1817[l1263] = 0.0;
			
		}
		for (int l1264 = 0; (l1264 < 2); l1264 = (l1264 + 1)) {
			fRec1815[l1264] = 0.0;
			
		}
		for (int l1265 = 0; (l1265 < 2); l1265 = (l1265 + 1)) {
			fRec1823[l1265] = 0.0;
			
		}
		for (int l1266 = 0; (l1266 < 2); l1266 = (l1266 + 1)) {
			fRec1821[l1266] = 0.0;
			
		}
		for (int l1267 = 0; (l1267 < 2); l1267 = (l1267 + 1)) {
			fRec1838[l1267] = 0.0;
			
		}
		for (int l1268 = 0; (l1268 < 2); l1268 = (l1268 + 1)) {
			fRec1836[l1268] = 0.0;
			
		}
		for (int l1269 = 0; (l1269 < 2); l1269 = (l1269 + 1)) {
			fRec1835[l1269] = 0.0;
			
		}
		for (int l1270 = 0; (l1270 < 2); l1270 = (l1270 + 1)) {
			fRec1833[l1270] = 0.0;
			
		}
		for (int l1271 = 0; (l1271 < 2); l1271 = (l1271 + 1)) {
			fRec1832[l1271] = 0.0;
			
		}
		for (int l1272 = 0; (l1272 < 2); l1272 = (l1272 + 1)) {
			fRec1830[l1272] = 0.0;
			
		}
		for (int l1273 = 0; (l1273 < 2); l1273 = (l1273 + 1)) {
			fRec1829[l1273] = 0.0;
			
		}
		for (int l1274 = 0; (l1274 < 2); l1274 = (l1274 + 1)) {
			fRec1827[l1274] = 0.0;
			
		}
		for (int l1275 = 0; (l1275 < 2); l1275 = (l1275 + 1)) {
			fRec1826[l1275] = 0.0;
			
		}
		for (int l1276 = 0; (l1276 < 2); l1276 = (l1276 + 1)) {
			fRec1824[l1276] = 0.0;
			
		}
		for (int l1277 = 0; (l1277 < 1024); l1277 = (l1277 + 1)) {
			fVec38[l1277] = 0.0;
			
		}
		for (int l1278 = 0; (l1278 < 2); l1278 = (l1278 + 1)) {
			fRec1853[l1278] = 0.0;
			
		}
		for (int l1279 = 0; (l1279 < 2); l1279 = (l1279 + 1)) {
			fRec1851[l1279] = 0.0;
			
		}
		for (int l1280 = 0; (l1280 < 2); l1280 = (l1280 + 1)) {
			fRec1850[l1280] = 0.0;
			
		}
		for (int l1281 = 0; (l1281 < 2); l1281 = (l1281 + 1)) {
			fRec1848[l1281] = 0.0;
			
		}
		for (int l1282 = 0; (l1282 < 2); l1282 = (l1282 + 1)) {
			fRec1847[l1282] = 0.0;
			
		}
		for (int l1283 = 0; (l1283 < 2); l1283 = (l1283 + 1)) {
			fRec1845[l1283] = 0.0;
			
		}
		for (int l1284 = 0; (l1284 < 2); l1284 = (l1284 + 1)) {
			fRec1844[l1284] = 0.0;
			
		}
		for (int l1285 = 0; (l1285 < 2); l1285 = (l1285 + 1)) {
			fRec1842[l1285] = 0.0;
			
		}
		for (int l1286 = 0; (l1286 < 2); l1286 = (l1286 + 1)) {
			fRec1841[l1286] = 0.0;
			
		}
		for (int l1287 = 0; (l1287 < 2); l1287 = (l1287 + 1)) {
			fRec1839[l1287] = 0.0;
			
		}
		for (int l1288 = 0; (l1288 < 2); l1288 = (l1288 + 1)) {
			fRec1865[l1288] = 0.0;
			
		}
		for (int l1289 = 0; (l1289 < 2); l1289 = (l1289 + 1)) {
			fRec1863[l1289] = 0.0;
			
		}
		for (int l1290 = 0; (l1290 < 2); l1290 = (l1290 + 1)) {
			fRec1862[l1290] = 0.0;
			
		}
		for (int l1291 = 0; (l1291 < 2); l1291 = (l1291 + 1)) {
			fRec1860[l1291] = 0.0;
			
		}
		for (int l1292 = 0; (l1292 < 2); l1292 = (l1292 + 1)) {
			fRec1859[l1292] = 0.0;
			
		}
		for (int l1293 = 0; (l1293 < 2); l1293 = (l1293 + 1)) {
			fRec1857[l1293] = 0.0;
			
		}
		for (int l1294 = 0; (l1294 < 2); l1294 = (l1294 + 1)) {
			fRec1856[l1294] = 0.0;
			
		}
		for (int l1295 = 0; (l1295 < 2); l1295 = (l1295 + 1)) {
			fRec1854[l1295] = 0.0;
			
		}
		for (int l1296 = 0; (l1296 < 2); l1296 = (l1296 + 1)) {
			fRec1874[l1296] = 0.0;
			
		}
		for (int l1297 = 0; (l1297 < 2); l1297 = (l1297 + 1)) {
			fRec1872[l1297] = 0.0;
			
		}
		for (int l1298 = 0; (l1298 < 2); l1298 = (l1298 + 1)) {
			fRec1871[l1298] = 0.0;
			
		}
		for (int l1299 = 0; (l1299 < 2); l1299 = (l1299 + 1)) {
			fRec1869[l1299] = 0.0;
			
		}
		for (int l1300 = 0; (l1300 < 2); l1300 = (l1300 + 1)) {
			fRec1868[l1300] = 0.0;
			
		}
		for (int l1301 = 0; (l1301 < 2); l1301 = (l1301 + 1)) {
			fRec1866[l1301] = 0.0;
			
		}
		for (int l1302 = 0; (l1302 < 2); l1302 = (l1302 + 1)) {
			fRec1877[l1302] = 0.0;
			
		}
		for (int l1303 = 0; (l1303 < 2); l1303 = (l1303 + 1)) {
			fRec1875[l1303] = 0.0;
			
		}
		for (int l1304 = 0; (l1304 < 2); l1304 = (l1304 + 1)) {
			fRec1883[l1304] = 0.0;
			
		}
		for (int l1305 = 0; (l1305 < 2); l1305 = (l1305 + 1)) {
			fRec1881[l1305] = 0.0;
			
		}
		for (int l1306 = 0; (l1306 < 2); l1306 = (l1306 + 1)) {
			fRec1880[l1306] = 0.0;
			
		}
		for (int l1307 = 0; (l1307 < 2); l1307 = (l1307 + 1)) {
			fRec1878[l1307] = 0.0;
			
		}
		for (int l1308 = 0; (l1308 < 1024); l1308 = (l1308 + 1)) {
			fVec39[l1308] = 0.0;
			
		}
		for (int l1309 = 0; (l1309 < 2); l1309 = (l1309 + 1)) {
			fRec1886[l1309] = 0.0;
			
		}
		for (int l1310 = 0; (l1310 < 2); l1310 = (l1310 + 1)) {
			fRec1884[l1310] = 0.0;
			
		}
		for (int l1311 = 0; (l1311 < 2); l1311 = (l1311 + 1)) {
			fRec1901[l1311] = 0.0;
			
		}
		for (int l1312 = 0; (l1312 < 2); l1312 = (l1312 + 1)) {
			fRec1899[l1312] = 0.0;
			
		}
		for (int l1313 = 0; (l1313 < 2); l1313 = (l1313 + 1)) {
			fRec1898[l1313] = 0.0;
			
		}
		for (int l1314 = 0; (l1314 < 2); l1314 = (l1314 + 1)) {
			fRec1896[l1314] = 0.0;
			
		}
		for (int l1315 = 0; (l1315 < 2); l1315 = (l1315 + 1)) {
			fRec1895[l1315] = 0.0;
			
		}
		for (int l1316 = 0; (l1316 < 2); l1316 = (l1316 + 1)) {
			fRec1893[l1316] = 0.0;
			
		}
		for (int l1317 = 0; (l1317 < 2); l1317 = (l1317 + 1)) {
			fRec1892[l1317] = 0.0;
			
		}
		for (int l1318 = 0; (l1318 < 2); l1318 = (l1318 + 1)) {
			fRec1890[l1318] = 0.0;
			
		}
		for (int l1319 = 0; (l1319 < 2); l1319 = (l1319 + 1)) {
			fRec1889[l1319] = 0.0;
			
		}
		for (int l1320 = 0; (l1320 < 2); l1320 = (l1320 + 1)) {
			fRec1887[l1320] = 0.0;
			
		}
		for (int l1321 = 0; (l1321 < 2); l1321 = (l1321 + 1)) {
			fRec1913[l1321] = 0.0;
			
		}
		for (int l1322 = 0; (l1322 < 2); l1322 = (l1322 + 1)) {
			fRec1911[l1322] = 0.0;
			
		}
		for (int l1323 = 0; (l1323 < 2); l1323 = (l1323 + 1)) {
			fRec1910[l1323] = 0.0;
			
		}
		for (int l1324 = 0; (l1324 < 2); l1324 = (l1324 + 1)) {
			fRec1908[l1324] = 0.0;
			
		}
		for (int l1325 = 0; (l1325 < 2); l1325 = (l1325 + 1)) {
			fRec1907[l1325] = 0.0;
			
		}
		for (int l1326 = 0; (l1326 < 2); l1326 = (l1326 + 1)) {
			fRec1905[l1326] = 0.0;
			
		}
		for (int l1327 = 0; (l1327 < 2); l1327 = (l1327 + 1)) {
			fRec1904[l1327] = 0.0;
			
		}
		for (int l1328 = 0; (l1328 < 2); l1328 = (l1328 + 1)) {
			fRec1902[l1328] = 0.0;
			
		}
		for (int l1329 = 0; (l1329 < 2); l1329 = (l1329 + 1)) {
			fRec1919[l1329] = 0.0;
			
		}
		for (int l1330 = 0; (l1330 < 2); l1330 = (l1330 + 1)) {
			fRec1917[l1330] = 0.0;
			
		}
		for (int l1331 = 0; (l1331 < 2); l1331 = (l1331 + 1)) {
			fRec1916[l1331] = 0.0;
			
		}
		for (int l1332 = 0; (l1332 < 2); l1332 = (l1332 + 1)) {
			fRec1914[l1332] = 0.0;
			
		}
		for (int l1333 = 0; (l1333 < 2); l1333 = (l1333 + 1)) {
			fRec1928[l1333] = 0.0;
			
		}
		for (int l1334 = 0; (l1334 < 2); l1334 = (l1334 + 1)) {
			fRec1926[l1334] = 0.0;
			
		}
		for (int l1335 = 0; (l1335 < 2); l1335 = (l1335 + 1)) {
			fRec1925[l1335] = 0.0;
			
		}
		for (int l1336 = 0; (l1336 < 2); l1336 = (l1336 + 1)) {
			fRec1923[l1336] = 0.0;
			
		}
		for (int l1337 = 0; (l1337 < 2); l1337 = (l1337 + 1)) {
			fRec1922[l1337] = 0.0;
			
		}
		for (int l1338 = 0; (l1338 < 2); l1338 = (l1338 + 1)) {
			fRec1920[l1338] = 0.0;
			
		}
		for (int l1339 = 0; (l1339 < 1024); l1339 = (l1339 + 1)) {
			fVec40[l1339] = 0.0;
			
		}
		for (int l1340 = 0; (l1340 < 2); l1340 = (l1340 + 1)) {
			fRec1943[l1340] = 0.0;
			
		}
		for (int l1341 = 0; (l1341 < 2); l1341 = (l1341 + 1)) {
			fRec1941[l1341] = 0.0;
			
		}
		for (int l1342 = 0; (l1342 < 2); l1342 = (l1342 + 1)) {
			fRec1940[l1342] = 0.0;
			
		}
		for (int l1343 = 0; (l1343 < 2); l1343 = (l1343 + 1)) {
			fRec1938[l1343] = 0.0;
			
		}
		for (int l1344 = 0; (l1344 < 2); l1344 = (l1344 + 1)) {
			fRec1937[l1344] = 0.0;
			
		}
		for (int l1345 = 0; (l1345 < 2); l1345 = (l1345 + 1)) {
			fRec1935[l1345] = 0.0;
			
		}
		for (int l1346 = 0; (l1346 < 2); l1346 = (l1346 + 1)) {
			fRec1934[l1346] = 0.0;
			
		}
		for (int l1347 = 0; (l1347 < 2); l1347 = (l1347 + 1)) {
			fRec1932[l1347] = 0.0;
			
		}
		for (int l1348 = 0; (l1348 < 2); l1348 = (l1348 + 1)) {
			fRec1931[l1348] = 0.0;
			
		}
		for (int l1349 = 0; (l1349 < 2); l1349 = (l1349 + 1)) {
			fRec1929[l1349] = 0.0;
			
		}
		for (int l1350 = 0; (l1350 < 2); l1350 = (l1350 + 1)) {
			fRec1955[l1350] = 0.0;
			
		}
		for (int l1351 = 0; (l1351 < 2); l1351 = (l1351 + 1)) {
			fRec1953[l1351] = 0.0;
			
		}
		for (int l1352 = 0; (l1352 < 2); l1352 = (l1352 + 1)) {
			fRec1952[l1352] = 0.0;
			
		}
		for (int l1353 = 0; (l1353 < 2); l1353 = (l1353 + 1)) {
			fRec1950[l1353] = 0.0;
			
		}
		for (int l1354 = 0; (l1354 < 2); l1354 = (l1354 + 1)) {
			fRec1949[l1354] = 0.0;
			
		}
		for (int l1355 = 0; (l1355 < 2); l1355 = (l1355 + 1)) {
			fRec1947[l1355] = 0.0;
			
		}
		for (int l1356 = 0; (l1356 < 2); l1356 = (l1356 + 1)) {
			fRec1946[l1356] = 0.0;
			
		}
		for (int l1357 = 0; (l1357 < 2); l1357 = (l1357 + 1)) {
			fRec1944[l1357] = 0.0;
			
		}
		for (int l1358 = 0; (l1358 < 2); l1358 = (l1358 + 1)) {
			fRec1964[l1358] = 0.0;
			
		}
		for (int l1359 = 0; (l1359 < 2); l1359 = (l1359 + 1)) {
			fRec1962[l1359] = 0.0;
			
		}
		for (int l1360 = 0; (l1360 < 2); l1360 = (l1360 + 1)) {
			fRec1961[l1360] = 0.0;
			
		}
		for (int l1361 = 0; (l1361 < 2); l1361 = (l1361 + 1)) {
			fRec1959[l1361] = 0.0;
			
		}
		for (int l1362 = 0; (l1362 < 2); l1362 = (l1362 + 1)) {
			fRec1958[l1362] = 0.0;
			
		}
		for (int l1363 = 0; (l1363 < 2); l1363 = (l1363 + 1)) {
			fRec1956[l1363] = 0.0;
			
		}
		for (int l1364 = 0; (l1364 < 2); l1364 = (l1364 + 1)) {
			fRec1967[l1364] = 0.0;
			
		}
		for (int l1365 = 0; (l1365 < 2); l1365 = (l1365 + 1)) {
			fRec1965[l1365] = 0.0;
			
		}
		for (int l1366 = 0; (l1366 < 2); l1366 = (l1366 + 1)) {
			fRec1973[l1366] = 0.0;
			
		}
		for (int l1367 = 0; (l1367 < 2); l1367 = (l1367 + 1)) {
			fRec1971[l1367] = 0.0;
			
		}
		for (int l1368 = 0; (l1368 < 2); l1368 = (l1368 + 1)) {
			fRec1970[l1368] = 0.0;
			
		}
		for (int l1369 = 0; (l1369 < 2); l1369 = (l1369 + 1)) {
			fRec1968[l1369] = 0.0;
			
		}
		for (int l1370 = 0; (l1370 < 1024); l1370 = (l1370 + 1)) {
			fVec41[l1370] = 0.0;
			
		}
		for (int l1371 = 0; (l1371 < 2); l1371 = (l1371 + 1)) {
			fRec1988[l1371] = 0.0;
			
		}
		for (int l1372 = 0; (l1372 < 2); l1372 = (l1372 + 1)) {
			fRec1986[l1372] = 0.0;
			
		}
		for (int l1373 = 0; (l1373 < 2); l1373 = (l1373 + 1)) {
			fRec1985[l1373] = 0.0;
			
		}
		for (int l1374 = 0; (l1374 < 2); l1374 = (l1374 + 1)) {
			fRec1983[l1374] = 0.0;
			
		}
		for (int l1375 = 0; (l1375 < 2); l1375 = (l1375 + 1)) {
			fRec1982[l1375] = 0.0;
			
		}
		for (int l1376 = 0; (l1376 < 2); l1376 = (l1376 + 1)) {
			fRec1980[l1376] = 0.0;
			
		}
		for (int l1377 = 0; (l1377 < 2); l1377 = (l1377 + 1)) {
			fRec1979[l1377] = 0.0;
			
		}
		for (int l1378 = 0; (l1378 < 2); l1378 = (l1378 + 1)) {
			fRec1977[l1378] = 0.0;
			
		}
		for (int l1379 = 0; (l1379 < 2); l1379 = (l1379 + 1)) {
			fRec1976[l1379] = 0.0;
			
		}
		for (int l1380 = 0; (l1380 < 2); l1380 = (l1380 + 1)) {
			fRec1974[l1380] = 0.0;
			
		}
		for (int l1381 = 0; (l1381 < 2); l1381 = (l1381 + 1)) {
			fRec1997[l1381] = 0.0;
			
		}
		for (int l1382 = 0; (l1382 < 2); l1382 = (l1382 + 1)) {
			fRec1995[l1382] = 0.0;
			
		}
		for (int l1383 = 0; (l1383 < 2); l1383 = (l1383 + 1)) {
			fRec1994[l1383] = 0.0;
			
		}
		for (int l1384 = 0; (l1384 < 2); l1384 = (l1384 + 1)) {
			fRec1992[l1384] = 0.0;
			
		}
		for (int l1385 = 0; (l1385 < 2); l1385 = (l1385 + 1)) {
			fRec1991[l1385] = 0.0;
			
		}
		for (int l1386 = 0; (l1386 < 2); l1386 = (l1386 + 1)) {
			fRec1989[l1386] = 0.0;
			
		}
		for (int l1387 = 0; (l1387 < 2); l1387 = (l1387 + 1)) {
			fRec2009[l1387] = 0.0;
			
		}
		for (int l1388 = 0; (l1388 < 2); l1388 = (l1388 + 1)) {
			fRec2007[l1388] = 0.0;
			
		}
		for (int l1389 = 0; (l1389 < 2); l1389 = (l1389 + 1)) {
			fRec2006[l1389] = 0.0;
			
		}
		for (int l1390 = 0; (l1390 < 2); l1390 = (l1390 + 1)) {
			fRec2004[l1390] = 0.0;
			
		}
		for (int l1391 = 0; (l1391 < 2); l1391 = (l1391 + 1)) {
			fRec2003[l1391] = 0.0;
			
		}
		for (int l1392 = 0; (l1392 < 2); l1392 = (l1392 + 1)) {
			fRec2001[l1392] = 0.0;
			
		}
		for (int l1393 = 0; (l1393 < 2); l1393 = (l1393 + 1)) {
			fRec2000[l1393] = 0.0;
			
		}
		for (int l1394 = 0; (l1394 < 2); l1394 = (l1394 + 1)) {
			fRec1998[l1394] = 0.0;
			
		}
		for (int l1395 = 0; (l1395 < 2); l1395 = (l1395 + 1)) {
			fRec2012[l1395] = 0.0;
			
		}
		for (int l1396 = 0; (l1396 < 2); l1396 = (l1396 + 1)) {
			fRec2010[l1396] = 0.0;
			
		}
		for (int l1397 = 0; (l1397 < 2); l1397 = (l1397 + 1)) {
			fRec2018[l1397] = 0.0;
			
		}
		for (int l1398 = 0; (l1398 < 2); l1398 = (l1398 + 1)) {
			fRec2016[l1398] = 0.0;
			
		}
		for (int l1399 = 0; (l1399 < 2); l1399 = (l1399 + 1)) {
			fRec2015[l1399] = 0.0;
			
		}
		for (int l1400 = 0; (l1400 < 2); l1400 = (l1400 + 1)) {
			fRec2013[l1400] = 0.0;
			
		}
		for (int l1401 = 0; (l1401 < 1024); l1401 = (l1401 + 1)) {
			fVec42[l1401] = 0.0;
			
		}
		for (int l1402 = 0; (l1402 < 2); l1402 = (l1402 + 1)) {
			fRec2027[l1402] = 0.0;
			
		}
		for (int l1403 = 0; (l1403 < 2); l1403 = (l1403 + 1)) {
			fRec2025[l1403] = 0.0;
			
		}
		for (int l1404 = 0; (l1404 < 2); l1404 = (l1404 + 1)) {
			fRec2024[l1404] = 0.0;
			
		}
		for (int l1405 = 0; (l1405 < 2); l1405 = (l1405 + 1)) {
			fRec2022[l1405] = 0.0;
			
		}
		for (int l1406 = 0; (l1406 < 2); l1406 = (l1406 + 1)) {
			fRec2021[l1406] = 0.0;
			
		}
		for (int l1407 = 0; (l1407 < 2); l1407 = (l1407 + 1)) {
			fRec2019[l1407] = 0.0;
			
		}
		for (int l1408 = 0; (l1408 < 2); l1408 = (l1408 + 1)) {
			fRec2039[l1408] = 0.0;
			
		}
		for (int l1409 = 0; (l1409 < 2); l1409 = (l1409 + 1)) {
			fRec2037[l1409] = 0.0;
			
		}
		for (int l1410 = 0; (l1410 < 2); l1410 = (l1410 + 1)) {
			fRec2036[l1410] = 0.0;
			
		}
		for (int l1411 = 0; (l1411 < 2); l1411 = (l1411 + 1)) {
			fRec2034[l1411] = 0.0;
			
		}
		for (int l1412 = 0; (l1412 < 2); l1412 = (l1412 + 1)) {
			fRec2033[l1412] = 0.0;
			
		}
		for (int l1413 = 0; (l1413 < 2); l1413 = (l1413 + 1)) {
			fRec2031[l1413] = 0.0;
			
		}
		for (int l1414 = 0; (l1414 < 2); l1414 = (l1414 + 1)) {
			fRec2030[l1414] = 0.0;
			
		}
		for (int l1415 = 0; (l1415 < 2); l1415 = (l1415 + 1)) {
			fRec2028[l1415] = 0.0;
			
		}
		for (int l1416 = 0; (l1416 < 2); l1416 = (l1416 + 1)) {
			fRec2042[l1416] = 0.0;
			
		}
		for (int l1417 = 0; (l1417 < 2); l1417 = (l1417 + 1)) {
			fRec2040[l1417] = 0.0;
			
		}
		for (int l1418 = 0; (l1418 < 2); l1418 = (l1418 + 1)) {
			fRec2048[l1418] = 0.0;
			
		}
		for (int l1419 = 0; (l1419 < 2); l1419 = (l1419 + 1)) {
			fRec2046[l1419] = 0.0;
			
		}
		for (int l1420 = 0; (l1420 < 2); l1420 = (l1420 + 1)) {
			fRec2045[l1420] = 0.0;
			
		}
		for (int l1421 = 0; (l1421 < 2); l1421 = (l1421 + 1)) {
			fRec2043[l1421] = 0.0;
			
		}
		for (int l1422 = 0; (l1422 < 2); l1422 = (l1422 + 1)) {
			fRec2063[l1422] = 0.0;
			
		}
		for (int l1423 = 0; (l1423 < 2); l1423 = (l1423 + 1)) {
			fRec2061[l1423] = 0.0;
			
		}
		for (int l1424 = 0; (l1424 < 2); l1424 = (l1424 + 1)) {
			fRec2060[l1424] = 0.0;
			
		}
		for (int l1425 = 0; (l1425 < 2); l1425 = (l1425 + 1)) {
			fRec2058[l1425] = 0.0;
			
		}
		for (int l1426 = 0; (l1426 < 2); l1426 = (l1426 + 1)) {
			fRec2057[l1426] = 0.0;
			
		}
		for (int l1427 = 0; (l1427 < 2); l1427 = (l1427 + 1)) {
			fRec2055[l1427] = 0.0;
			
		}
		for (int l1428 = 0; (l1428 < 2); l1428 = (l1428 + 1)) {
			fRec2054[l1428] = 0.0;
			
		}
		for (int l1429 = 0; (l1429 < 2); l1429 = (l1429 + 1)) {
			fRec2052[l1429] = 0.0;
			
		}
		for (int l1430 = 0; (l1430 < 2); l1430 = (l1430 + 1)) {
			fRec2051[l1430] = 0.0;
			
		}
		for (int l1431 = 0; (l1431 < 2); l1431 = (l1431 + 1)) {
			fRec2049[l1431] = 0.0;
			
		}
		for (int l1432 = 0; (l1432 < 1024); l1432 = (l1432 + 1)) {
			fVec43[l1432] = 0.0;
			
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
		ui_interface->openVerticalBox("KMHLS_FullSetup_5h5p_full_6");
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
			fRec16[0] = (double(input17[i]) - (((fTemp2 * fRec16[2]) + (2.0 * (fTemp3 * fRec16[1]))) / fTemp4));
			double fTemp8 = (((fTemp1 * (fRec16[2] + (fRec16[0] + (2.0 * fRec16[1])))) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec16[1]) + ((fRec16[0] + fRec16[2]) / fTemp4))))));
			fRec17[0] = (double(input16[i]) - (((fTemp2 * fRec17[2]) + (2.0 * (fTemp3 * fRec17[1]))) / fTemp4));
			double fTemp9 = (((fTemp1 * (fRec17[2] + (fRec17[0] + (2.0 * fRec17[1])))) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec17[1]) + ((fRec17[0] + fRec17[2]) / fTemp4))))));
			fRec18[0] = (double(input20[i]) - (((fTemp2 * fRec18[2]) + (2.0 * (fTemp3 * fRec18[1]))) / fTemp4));
			double fTemp10 = (((fTemp1 * (fRec18[2] + (fRec18[0] + (2.0 * fRec18[1])))) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec18[1]) + ((fRec18[0] + fRec18[2]) / fTemp4))))));
			fRec19[0] = (double(input18[i]) - (((fTemp2 * fRec19[2]) + (2.0 * (fTemp3 * fRec19[1]))) / fTemp4));
			double fTemp11 = (((fTemp1 * (fRec19[2] + (fRec19[0] + (2.0 * fRec19[1])))) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec19[1]) + ((fRec19[0] + fRec19[2]) / fTemp4))))));
			fRec20[0] = (double(input19[i]) - (((fTemp2 * fRec20[2]) + (2.0 * (fTemp3 * fRec20[1]))) / fTemp4));
			double fTemp12 = (((fTemp1 * (fRec20[2] + (fRec20[0] + (2.0 * fRec20[1])))) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec20[1]) + ((fRec20[0] + fRec20[2]) / fTemp4))))));
			fRec21[0] = (double(input21[i]) - (((fTemp2 * fRec21[2]) + (2.0 * (fTemp3 * fRec21[1]))) / fTemp4));
			double fTemp13 = (((fTemp1 * (fRec21[2] + (fRec21[0] + (2.0 * fRec21[1])))) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec21[1]) + ((fRec21[0] + fRec21[2]) / fTemp4))))));
			fRec22[0] = (double(input22[i]) - (((fTemp2 * fRec22[2]) + (2.0 * (fTemp3 * fRec22[1]))) / fTemp4));
			double fTemp14 = (((fTemp1 * (fRec22[2] + (fRec22[0] + (2.0 * fRec22[1])))) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec22[1]) + ((fRec22[0] + fRec22[2]) / fTemp4))))));
			fRec23[0] = (double(input23[i]) - (((fTemp2 * fRec23[2]) + (2.0 * (fTemp3 * fRec23[1]))) / fTemp4));
			double fTemp15 = (((fTemp1 * (fRec23[2] + (fRec23[0] + (2.0 * fRec23[1])))) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec23[1]) + ((fRec23[0] + fRec23[2]) / fTemp4))))));
			fRec24[0] = (double(input24[i]) - (((fTemp2 * fRec24[2]) + (2.0 * (fTemp3 * fRec24[1]))) / fTemp4));
			double fTemp16 = (((fTemp1 * (fRec24[2] + (fRec24[0] + (2.0 * fRec24[1])))) / fTemp5) + (0.42200500930000001 * (fRec3[0] * (0.0 - ((fTemp6 * fRec24[1]) + ((fRec24[0] + fRec24[2]) / fTemp4))))));
			double fTemp17 = (fConst2 * ((fConst4 * (((0.057950521999999997 * fTemp8) + ((0.039456378799999997 * fTemp9) + (0.0115401831 * fTemp10))) - ((((((0.0250783768 * fTemp11) + (0.040262045900000001 * fTemp12)) + (0.051515187599999998 * fTemp13)) + (0.0104138279 * fTemp14)) + (0.027503341600000002 * fTemp15)) + (0.064441907300000004 * fTemp16)))) + (fConst5 * (0.0 - ((fConst7 * fRec13[1]) + (fConst6 * fRec10[1]))))));
			fRec15[0] = (fRec15[1] + fTemp17);
			fRec13[0] = fRec15[0];
			double fRec14 = fTemp17;
			fRec12[0] = (fRec13[0] + fRec12[1]);
			fRec10[0] = fRec12[0];
			double fRec11 = fRec14;
			double fTemp18 = (fRec11 + (fConst8 * (0.0 - ((fConst10 * fRec7[1]) + (fConst9 * fRec4[1])))));
			fRec9[0] = (fRec9[1] + fTemp18);
			fRec7[0] = fRec9[0];
			double fRec8 = fTemp18;
			fRec6[0] = (fRec7[0] + fRec6[1]);
			fRec4[0] = fRec6[0];
			double fRec5 = fRec8;
			fRec34[0] = (double(input9[i]) - (((fTemp2 * fRec34[2]) + (2.0 * (fTemp3 * fRec34[1]))) / fTemp4));
			double fTemp19 = (((fTemp1 * (fRec34[2] + (fRec34[0] + (2.0 * fRec34[1])))) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec34[1]) + ((fRec34[0] + fRec34[2]) / fTemp4))))));
			fRec35[0] = (double(input10[i]) - (((fTemp2 * fRec35[2]) + (2.0 * (fTemp3 * fRec35[1]))) / fTemp4));
			double fTemp20 = (((fTemp1 * (fRec35[2] + (fRec35[0] + (2.0 * fRec35[1])))) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec35[1]) + ((fRec35[0] + fRec35[2]) / fTemp4))))));
			fRec36[0] = (double(input14[i]) - (((fTemp2 * fRec36[2]) + (2.0 * (fTemp3 * fRec36[1]))) / fTemp4));
			double fTemp21 = (((fTemp1 * (fRec36[2] + (fRec36[0] + (2.0 * fRec36[1])))) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec36[1]) + ((fRec36[0] + fRec36[2]) / fTemp4))))));
			fRec37[0] = (double(input11[i]) - (((fTemp2 * fRec37[2]) + (2.0 * (fTemp3 * fRec37[1]))) / fTemp4));
			double fTemp22 = (((fTemp1 * (fRec37[2] + (fRec37[0] + (2.0 * fRec37[1])))) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec37[1]) + ((fRec37[0] + fRec37[2]) / fTemp4))))));
			fRec38[0] = (double(input12[i]) - (((fTemp2 * fRec38[2]) + (2.0 * (fTemp3 * fRec38[1]))) / fTemp4));
			double fTemp23 = (((fTemp1 * (fRec38[2] + (fRec38[0] + (2.0 * fRec38[1])))) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec38[1]) + ((fRec38[0] + fRec38[2]) / fTemp4))))));
			fRec39[0] = (double(input13[i]) - (((fTemp2 * fRec39[2]) + (2.0 * (fTemp3 * fRec39[1]))) / fTemp4));
			double fTemp24 = (((fTemp1 * (fRec39[2] + (fRec39[0] + (2.0 * fRec39[1])))) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec39[1]) + ((fRec39[0] + fRec39[2]) / fTemp4))))));
			fRec40[0] = (double(input15[i]) - (((fTemp2 * fRec40[2]) + (2.0 * (fTemp3 * fRec40[1]))) / fTemp4));
			double fTemp25 = (((fTemp1 * (fRec40[2] + (fRec40[0] + (2.0 * fRec40[1])))) / fTemp5) + (0.62824992459999995 * (fRec3[0] * (0.0 - ((fTemp6 * fRec40[1]) + ((fRec40[0] + fRec40[2]) / fTemp4))))));
			double fTemp26 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec31[1]) + (fConst12 * fRec28[1])))) + (fConst15 * ((((0.067383474400000004 * fTemp19) + (0.052350733300000001 * fTemp20)) + (0.0118537247 * fTemp21)) - ((((0.021163786800000001 * fTemp22) + (0.039511652199999997 * fTemp23)) + (0.029526495999999999 * fTemp24)) + (0.027035507699999999 * fTemp25))))));
			fRec33[0] = (fRec33[1] + fTemp26);
			fRec31[0] = fRec33[0];
			double fRec32 = fTemp26;
			fRec30[0] = (fRec31[0] + fRec30[1]);
			fRec28[0] = fRec30[0];
			double fRec29 = fRec32;
			double fTemp27 = (fConst16 * fRec25[1]);
			fRec27[0] = ((fRec29 + fRec27[1]) - fTemp27);
			fRec25[0] = fRec27[0];
			double fRec26 = (fRec29 - fTemp27);
			fRec47[0] = (double(input5[i]) - (((fTemp2 * fRec47[2]) + (2.0 * (fTemp3 * fRec47[1]))) / fTemp4));
			double fTemp28 = (((fTemp1 * (fRec47[2] + (fRec47[0] + (2.0 * fRec47[1])))) / fTemp5) + (0.80424909239999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec47[1]) + ((fRec47[0] + fRec47[2]) / fTemp4))))));
			fRec48[0] = (double(input4[i]) - (((fTemp2 * fRec48[2]) + (2.0 * (fTemp3 * fRec48[1]))) / fTemp4));
			double fTemp29 = (((fTemp1 * (fRec48[2] + (fRec48[0] + (2.0 * fRec48[1])))) / fTemp5) + (0.80424909239999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec48[1]) + ((fRec48[0] + fRec48[2]) / fTemp4))))));
			fRec49[0] = (double(input7[i]) - (((fTemp2 * fRec49[2]) + (2.0 * (fTemp3 * fRec49[1]))) / fTemp4));
			double fTemp30 = (((fTemp1 * (fRec49[2] + (fRec49[0] + (2.0 * fRec49[1])))) / fTemp5) + (0.80424909239999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec49[1]) + ((fRec49[0] + fRec49[2]) / fTemp4))))));
			fRec50[0] = (double(input8[i]) - (((fTemp2 * fRec50[2]) + (2.0 * (fTemp3 * fRec50[1]))) / fTemp4));
			double fTemp31 = (((fTemp1 * (fRec50[2] + (fRec50[0] + (2.0 * fRec50[1])))) / fTemp5) + (0.80424909239999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec50[1]) + ((fRec50[0] + fRec50[2]) / fTemp4))))));
			fRec51[0] = (double(input6[i]) - (((fTemp2 * fRec51[2]) + (2.0 * (fTemp3 * fRec51[1]))) / fTemp4));
			double fTemp32 = (((fTemp1 * (fRec51[2] + (fRec51[0] + (2.0 * fRec51[1])))) / fTemp5) + (0.80424909239999998 * (fRec3[0] * (0.0 - ((fTemp6 * fRec51[1]) + ((fRec51[0] + fRec51[2]) / fTemp4))))));
			double fTemp33 = (fConst17 * ((((0.0242265677 * fTemp28) + ((0.061754740599999997 * fTemp29) + ((0.030165527300000002 * fTemp30) + (0.016700725 * fTemp31)))) - (0.030420442400000001 * fTemp32)) + (fConst5 * (0.0 - ((fConst19 * fRec44[1]) + (fConst18 * fRec41[1]))))));
			fRec46[0] = (fRec46[1] + fTemp33);
			fRec44[0] = fRec46[0];
			double fRec45 = fTemp33;
			fRec43[0] = (fRec44[0] + fRec43[1]);
			fRec41[0] = fRec43[0];
			double fRec42 = fRec45;
			fRec55[0] = (double(input1[i]) - (((fTemp2 * fRec55[2]) + (2.0 * (fTemp3 * fRec55[1]))) / fTemp4));
			double fTemp34 = (((fTemp1 * (fRec55[2] + (fRec55[0] + (2.0 * fRec55[1])))) / fTemp5) + (0.93246951420000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec55[1]) + ((fRec55[0] + fRec55[2]) / fTemp4))))));
			fRec56[0] = (double(input2[i]) - (((fTemp2 * fRec56[2]) + (2.0 * (fTemp3 * fRec56[1]))) / fTemp4));
			double fTemp35 = (((fTemp1 * (fRec56[2] + (fRec56[0] + (2.0 * fRec56[1])))) / fTemp5) + (0.93246951420000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec56[1]) + ((fRec56[0] + fRec56[2]) / fTemp4))))));
			fRec57[0] = (double(input3[i]) - (((fTemp2 * fRec57[2]) + (2.0 * (fTemp3 * fRec57[1]))) / fTemp4));
			double fTemp36 = (((fTemp1 * (fRec57[2] + (fRec57[0] + (2.0 * fRec57[1])))) / fTemp5) + (0.93246951420000002 * (fRec3[0] * (0.0 - ((fTemp6 * fRec57[1]) + ((fRec57[0] + fRec57[2]) / fTemp4))))));
			double fTemp37 = (fConst20 * ((((0.029665454800000001 * fTemp34) + (0.014688123799999999 * fTemp35)) + (0.0385625593 * fTemp36)) - (fConst21 * fRec52[1])));
			fRec54[0] = (fRec54[1] + fTemp37);
			fRec52[0] = fRec54[0];
			double fRec53 = fTemp37;
			double fTemp38 = (fConst23 * (0.0 - ((fConst25 * fRec64[1]) + (fConst24 * fRec61[1]))));
			fRec73[0] = (double(input31[i]) - (((fTemp2 * fRec73[2]) + (2.0 * (fTemp3 * fRec73[1]))) / fTemp4));
			double fTemp39 = (((fTemp1 * (fRec73[2] + (fRec73[0] + (2.0 * fRec73[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec73[1]) + ((fRec73[0] + fRec73[2]) / fTemp4))))));
			fRec74[0] = (double(input30[i]) - (((fTemp2 * fRec74[2]) + (2.0 * (fTemp3 * fRec74[1]))) / fTemp4));
			double fTemp40 = (((fTemp1 * (fRec74[2] + (fRec74[0] + (2.0 * fRec74[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec74[1]) + ((fRec74[0] + fRec74[2]) / fTemp4))))));
			fRec75[0] = (double(input26[i]) - (((fTemp2 * fRec75[2]) + (2.0 * (fTemp3 * fRec75[1]))) / fTemp4));
			double fTemp41 = (((fTemp1 * (fRec75[2] + (fRec75[0] + (2.0 * fRec75[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec75[1]) + ((fRec75[0] + fRec75[2]) / fTemp4))))));
			fRec76[0] = (double(input33[i]) - (((fTemp2 * fRec76[2]) + (2.0 * (fTemp3 * fRec76[1]))) / fTemp4));
			double fTemp42 = (((fTemp1 * (fRec76[2] + (fRec76[0] + (2.0 * fRec76[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec76[1]) + ((fRec76[0] + fRec76[2]) / fTemp4))))));
			fRec77[0] = (double(input29[i]) - (((fTemp2 * fRec77[2]) + (2.0 * (fTemp3 * fRec77[1]))) / fTemp4));
			double fTemp43 = (((fTemp1 * (fRec77[2] + (fRec77[0] + (2.0 * fRec77[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec77[1]) + ((fRec77[0] + fRec77[2]) / fTemp4))))));
			fRec78[0] = (double(input28[i]) - (((fTemp2 * fRec78[2]) + (2.0 * (fTemp3 * fRec78[1]))) / fTemp4));
			double fTemp44 = (((fTemp1 * (fRec78[2] + (fRec78[0] + (2.0 * fRec78[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec78[1]) + ((fRec78[0] + fRec78[2]) / fTemp4))))));
			fRec79[0] = (double(input27[i]) - (((fTemp2 * fRec79[2]) + (2.0 * (fTemp3 * fRec79[1]))) / fTemp4));
			double fTemp45 = (((fTemp1 * (fRec79[2] + (fRec79[0] + (2.0 * fRec79[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec79[1]) + ((fRec79[0] + fRec79[2]) / fTemp4))))));
			fRec80[0] = (double(input25[i]) - (((fTemp2 * fRec80[2]) + (2.0 * (fTemp3 * fRec80[1]))) / fTemp4));
			double fTemp46 = (((fTemp1 * (fRec80[2] + (fRec80[0] + (2.0 * fRec80[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec80[1]) + ((fRec80[0] + fRec80[2]) / fTemp4))))));
			fRec81[0] = (double(input32[i]) - (((fTemp2 * fRec81[2]) + (2.0 * (fTemp3 * fRec81[1]))) / fTemp4));
			double fTemp47 = (((fTemp1 * (fRec81[2] + (fRec81[0] + (2.0 * fRec81[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec81[1]) + ((fRec81[0] + fRec81[2]) / fTemp4))))));
			fRec82[0] = (double(input34[i]) - (((fTemp2 * fRec82[2]) + (2.0 * (fTemp3 * fRec82[1]))) / fTemp4));
			double fTemp48 = (((fTemp1 * (fRec82[2] + (fRec82[0] + (2.0 * fRec82[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec82[1]) + ((fRec82[0] + fRec82[2]) / fTemp4))))));
			fRec83[0] = (double(input35[i]) - (((fTemp2 * fRec83[2]) + (2.0 * (fTemp3 * fRec83[1]))) / fTemp4));
			double fTemp49 = (((fTemp1 * (fRec83[2] + (fRec83[0] + (2.0 * fRec83[1])))) / fTemp5) + (0.20571231109999999 * (fRec3[0] * (0.0 - ((fTemp6 * fRec83[1]) + ((fRec83[0] + fRec83[2]) / fTemp4))))));
			double fTemp50 = (fConst26 * ((fConst28 * (((0.00071347049999999996 * fTemp39) + ((0.0465529212 * fTemp40) + ((0.0313150793 * fTemp41) + (0.00025691949999999999 * fTemp42)))) - ((0.0027149637000000002 * fTemp43) + ((0.065705226800000002 * fTemp44) + ((0.018100475800000002 * fTemp45) + ((0.006187204 * fTemp46) + (((0.017495515699999999 * fTemp47) + (0.061917530200000001 * fTemp48)) + (0.073548111200000002 * fTemp49)))))))) + (fConst5 * (0.0 - ((fConst30 * fRec70[1]) + (fConst29 * fRec67[1]))))));
			fRec72[0] = (fRec72[1] + fTemp50);
			fRec70[0] = fRec72[0];
			double fRec71 = fTemp50;
			fRec69[0] = (fRec70[0] + fRec69[1]);
			fRec67[0] = fRec69[0];
			double fRec68 = fRec71;
			fRec66[0] = (fTemp38 + (fRec68 + fRec66[1]));
			fRec64[0] = fRec66[0];
			double fRec65 = (fRec68 + fTemp38);
			fRec63[0] = (fRec64[0] + fRec63[1]);
			fRec61[0] = fRec63[0];
			double fRec62 = fRec65;
			double fTemp51 = (fConst31 * fRec58[1]);
			fRec60[0] = ((fRec62 + fRec60[1]) - fTemp51);
			fRec58[0] = fRec60[0];
			double fRec59 = (fRec62 - fTemp51);
			fVec0[(IOTA & 1023)] = ((0.017351705500000002 * fTemp7) + (fRec5 + (fRec26 + (fRec42 + (fRec53 + fRec59)))));
			output0[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec0[((IOTA - iConst32) & 1023)])));
			double fTemp52 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec96[1]) + (fConst29 * fRec93[1])))) + (fConst28 * (((0.0175661293 * fTemp39) + ((0.034739817100000001 * fTemp40) + ((0.0033982126000000001 * fTemp43) + ((0.038746606400000001 * fTemp41) + ((0.0576307317 * fTemp46) + ((0.025746116400000001 * fTemp48) + (0.024117195500000001 * fTemp49))))))) - ((0.022565823200000001 * fTemp44) + ((0.016529955299999999 * fTemp45) + ((0.043433748100000003 * fTemp47) + (0.022432127600000001 * fTemp42))))))));
			fRec98[0] = (fRec98[1] + fTemp52);
			fRec96[0] = fRec98[0];
			double fRec97 = fTemp52;
			fRec95[0] = (fRec96[0] + fRec95[1]);
			fRec93[0] = fRec95[0];
			double fRec94 = fRec97;
			double fTemp53 = (fConst23 * (0.0 - ((fConst25 * fRec90[1]) + (fConst24 * fRec87[1]))));
			fRec92[0] = (fRec94 + (fRec92[1] + fTemp53));
			fRec90[0] = fRec92[0];
			double fRec91 = (fRec94 + fTemp53);
			fRec89[0] = (fRec90[0] + fRec89[1]);
			fRec87[0] = fRec89[0];
			double fRec88 = fRec91;
			double fTemp54 = (fConst31 * fRec84[1]);
			fRec86[0] = ((fRec88 + fRec86[1]) - fTemp54);
			fRec84[0] = fRec86[0];
			double fRec85 = (fRec88 - fTemp54);
			double fTemp55 = (fConst8 * (0.0 - ((fConst10 * fRec102[1]) + (fConst9 * fRec99[1]))));
			double fTemp56 = (fConst2 * ((fConst4 * (((((0.0270991579 * fTemp8) + ((0.0491248237 * fTemp9) + (0.018723926700000001 * fTemp10))) + (0.029748641900000001 * fTemp15)) + (0.035891568399999997 * fTemp16)) - ((((0.013735374700000001 * fTemp11) + (0.010291330899999999 * fTemp12)) + (0.041673309499999998 * fTemp13)) + (0.029150095399999999 * fTemp14)))) + (fConst5 * (0.0 - ((fConst7 * fRec108[1]) + (fConst6 * fRec105[1]))))));
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
			double fTemp57 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec117[1]) + (fConst12 * fRec114[1])))) + (fConst15 * (((((0.036262509200000001 * fTemp19) + (0.015085925 * fTemp20)) + (0.028050711499999999 * fTemp21)) + (0.042572835099999998 * fTemp25)) - (((0.0077984969999999997 * fTemp22) + (0.0239365806 * fTemp23)) + (0.0338370016 * fTemp24))))));
			fRec119[0] = (fRec119[1] + fTemp57);
			fRec117[0] = fRec119[0];
			double fRec118 = fTemp57;
			fRec116[0] = (fRec117[0] + fRec116[1]);
			fRec114[0] = fRec116[0];
			double fRec115 = fRec118;
			double fTemp58 = (fConst16 * fRec111[1]);
			fRec113[0] = ((fRec115 + fRec113[1]) - fTemp58);
			fRec111[0] = fRec113[0];
			double fRec112 = (fRec115 - fTemp58);
			double fTemp59 = (fConst20 * ((((0.0081666310000000006 * fTemp34) + (0.0080504287000000008 * fTemp35)) + (0.033948018000000003 * fTemp36)) - (fConst21 * fRec120[1])));
			fRec122[0] = (fRec122[1] + fTemp59);
			fRec120[0] = fRec122[0];
			double fRec121 = fTemp59;
			double fTemp60 = (fConst17 * ((((0.0053739679000000002 * fTemp28) + ((0.0215195561 * fTemp29) + ((0.021276802899999999 * fTemp30) + (0.042249251199999997 * fTemp31)))) - (0.024671526900000001 * fTemp32)) + (fConst5 * (0.0 - ((fConst19 * fRec126[1]) + (fConst18 * fRec123[1]))))));
			fRec128[0] = (fRec128[1] + fTemp60);
			fRec126[0] = fRec128[0];
			double fRec127 = fTemp60;
			fRec125[0] = (fRec126[0] + fRec125[1]);
			fRec123[0] = fRec125[0];
			double fRec124 = fRec127;
			fVec1[(IOTA & 1023)] = ((0.0121423434 * fTemp7) + (fRec85 + (fRec100 + (fRec112 + (fRec121 + fRec124)))));
			output1[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec1[((IOTA - iConst32) & 1023)])));
			double fTemp61 = (fConst26 * ((fConst28 * (((0.047019299399999999 * fTemp40) + ((0.0181103429 * fTemp44) + ((0.0128587745 * fTemp45) + ((0.061554627299999998 * fTemp48) + (0.055571430900000003 * fTemp49))))) - ((0.00098900620000000002 * fTemp39) + ((0.0024478363000000002 * fTemp43) + ((0.032390509599999999 * fTemp41) + ((0.048840966800000003 * fTemp46) + ((0.066083747100000007 * fTemp47) + (0.013253513499999999 * fTemp42)))))))) + (fConst5 * (0.0 - ((fConst30 * fRec141[1]) + (fConst29 * fRec138[1]))))));
			fRec143[0] = (fRec143[1] + fTemp61);
			fRec141[0] = fRec143[0];
			double fRec142 = fTemp61;
			fRec140[0] = (fRec141[0] + fRec140[1]);
			fRec138[0] = fRec140[0];
			double fRec139 = fRec142;
			double fTemp62 = (fConst23 * (0.0 - ((fConst25 * fRec135[1]) + (fConst24 * fRec132[1]))));
			fRec137[0] = (fRec139 + (fRec137[1] + fTemp62));
			fRec135[0] = fRec137[0];
			double fRec136 = (fRec139 + fTemp62);
			fRec134[0] = (fRec135[0] + fRec134[1]);
			fRec132[0] = fRec134[0];
			double fRec133 = fRec136;
			double fTemp63 = (fConst31 * fRec129[1]);
			fRec131[0] = ((fRec133 + fRec131[1]) - fTemp63);
			fRec129[0] = fRec131[0];
			double fRec130 = (fRec133 - fTemp63);
			double fTemp64 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec153[1]) + (fConst6 * fRec150[1])))) + (fConst4 * (((((0.0082661783999999992 * fTemp12) + ((0.0106972762 * fTemp11) + (0.011891380599999999 * fTemp10))) + (0.060349276200000003 * fTemp15)) + (0.064095782399999995 * fTemp16)) - ((((0.040656872500000003 * fTemp9) + (0.022354497099999999 * fTemp8)) + (0.065294007299999998 * fTemp13)) + (0.025470690599999998 * fTemp14))))));
			fRec155[0] = (fRec155[1] + fTemp64);
			fRec153[0] = fRec155[0];
			double fRec154 = fTemp64;
			fRec152[0] = (fRec153[0] + fRec152[1]);
			fRec150[0] = fRec152[0];
			double fRec151 = fRec154;
			double fTemp65 = (fConst8 * (0.0 - ((fConst10 * fRec147[1]) + (fConst9 * fRec144[1]))));
			fRec149[0] = (fRec151 + (fRec149[1] + fTemp65));
			fRec147[0] = fRec149[0];
			double fRec148 = (fRec151 + fTemp65);
			fRec146[0] = (fRec147[0] + fRec146[1]);
			fRec144[0] = fRec146[0];
			double fRec145 = fRec148;
			double fTemp66 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec162[1]) + (fConst12 * fRec159[1])))) + (fConst15 * ((((0.0061069486999999999 * fTemp22) + (0.052434965600000001 * fTemp21)) + (0.066804916899999997 * fTemp25)) - ((((0.029507360900000001 * fTemp19) + (0.012343163900000001 * fTemp20)) + (0.039714498899999999 * fTemp23)) + (0.036296476799999998 * fTemp24))))));
			fRec164[0] = (fRec164[1] + fTemp66);
			fRec162[0] = fRec164[0];
			double fRec163 = fTemp66;
			fRec161[0] = (fRec162[0] + fRec161[1]);
			fRec159[0] = fRec161[0];
			double fRec160 = fRec163;
			double fTemp67 = (fConst16 * fRec156[1]);
			fRec158[0] = ((fRec160 + fRec158[1]) - fTemp67);
			fRec156[0] = fRec158[0];
			double fRec157 = (fRec160 - fTemp67);
			double fTemp68 = (fConst20 * ((((0.014732654 * fTemp35) + (0.048546944699999997 * fTemp36)) - (0.0065354439999999996 * fTemp34)) - (fConst21 * fRec165[1])));
			fRec167[0] = (fRec167[1] + fTemp68);
			fRec165[0] = fRec167[0];
			double fRec166 = fTemp68;
			double fTemp69 = (fConst17 * ((((0.038575806999999997 * fTemp30) + (0.062023356299999999 * fTemp31)) - (((0.0173188131 * fTemp29) + (0.0043816191999999999 * fTemp28)) + (0.030715410700000001 * fTemp32))) + (fConst5 * (0.0 - ((fConst19 * fRec171[1]) + (fConst18 * fRec168[1]))))));
			fRec173[0] = (fRec173[1] + fTemp69);
			fRec171[0] = fRec173[0];
			double fRec172 = fTemp69;
			fRec170[0] = (fRec171[0] + fRec170[1]);
			fRec168[0] = fRec170[0];
			double fRec169 = fRec172;
			fVec2[(IOTA & 1023)] = ((0.017466101899999999 * fTemp7) + (fRec130 + (fRec145 + (fRec157 + (fRec166 + fRec169)))));
			output2[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec2[((IOTA - iConst32) & 1023)])));
			double fTemp70 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec186[1]) + (fConst29 * fRec183[1])))) + (fConst28 * (((0.014835606499999999 * fTemp39) + ((0.034817924 * fTemp40) + ((0.043724372999999997 * fTemp44) + ((0.027560334999999998 * fTemp45) + (0.0046515374999999996 * fTemp42))))) - ((0.010159094400000001 * fTemp43) + ((0.038323148799999998 * fTemp41) + ((0.0222653383 * fTemp46) + (((0.022209774700000001 * fTemp47) + (0.026465798799999999 * fTemp48)) + (0.058418527099999999 * fTemp49)))))))));
			fRec188[0] = (fRec188[1] + fTemp70);
			fRec186[0] = fRec188[0];
			double fRec187 = fTemp70;
			fRec185[0] = (fRec186[0] + fRec185[1]);
			fRec183[0] = fRec185[0];
			double fRec184 = fRec187;
			double fTemp71 = (fConst23 * (0.0 - ((fConst25 * fRec180[1]) + (fConst24 * fRec177[1]))));
			fRec182[0] = (fRec184 + (fRec182[1] + fTemp71));
			fRec180[0] = fRec182[0];
			double fRec181 = (fRec184 + fTemp71);
			fRec179[0] = (fRec180[0] + fRec179[1]);
			fRec177[0] = fRec179[0];
			double fRec178 = fRec181;
			double fTemp72 = (fConst31 * fRec174[1]);
			fRec176[0] = ((fRec178 + fRec176[1]) - fTemp72);
			fRec174[0] = fRec176[0];
			double fRec175 = (fRec178 - fTemp72);
			double fTemp73 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec198[1]) + (fConst6 * fRec195[1])))) + (fConst4 * (((0.022398404199999999 * fTemp12) + ((0.029377012800000001 * fTemp11) + (0.0187892484 * fTemp10))) - ((((((0.048476556499999997 * fTemp9) + (0.0402277511 * fTemp8)) + (0.036716007199999998 * fTemp13)) + (0.013463944800000001 * fTemp14)) + (0.0024083395 * fTemp15)) + (0.036896153899999999 * fTemp16))))));
			fRec200[0] = (fRec200[1] + fTemp73);
			fRec198[0] = fRec200[0];
			double fRec199 = fTemp73;
			fRec197[0] = (fRec198[0] + fRec197[1]);
			fRec195[0] = fRec197[0];
			double fRec196 = fRec199;
			double fTemp74 = (fConst8 * (0.0 - ((fConst10 * fRec192[1]) + (fConst9 * fRec189[1]))));
			fRec194[0] = (fRec196 + (fRec194[1] + fTemp74));
			fRec192[0] = fRec194[0];
			double fRec193 = (fRec196 + fTemp74);
			fRec191[0] = (fRec192[0] + fRec191[1]);
			fRec189[0] = fRec191[0];
			double fRec190 = fRec193;
			double fTemp75 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec207[1]) + (fConst12 * fRec204[1])))) + (fConst15 * (((0.0186099617 * fTemp22) + (0.0148658184 * fTemp21)) - (((((0.055772743499999999 * fTemp19) + (0.028227562099999999 * fTemp20)) + (0.0239814551 * fTemp23)) + (0.029425120900000001 * fTemp24)) + (0.0052783761999999996 * fTemp25))))));
			fRec209[0] = (fRec209[1] + fTemp75);
			fRec207[0] = fRec209[0];
			double fRec208 = fTemp75;
			fRec206[0] = (fRec207[0] + fRec206[1]);
			fRec204[0] = fRec206[0];
			double fRec205 = fRec208;
			double fTemp76 = (fConst16 * fRec201[1]);
			fRec203[0] = ((fRec205 + fRec203[1]) - fTemp76);
			fRec201[0] = fRec203[0];
			double fRec202 = (fRec205 - fTemp76);
			double fTemp77 = (fConst20 * ((((0.0080646999999999993 * fTemp35) + (0.029758019399999999 * fTemp36)) - (0.018411065800000001 * fTemp34)) - (fConst21 * fRec210[1])));
			fRec212[0] = (fRec212[1] + fTemp77);
			fRec210[0] = fRec212[0];
			double fRec211 = fTemp77;
			double fTemp78 = (fConst17 * ((((0.018829361400000001 * fTemp30) + (0.021158426099999999 * fTemp31)) - (((0.042539507800000001 * fTemp29) + (0.011345864400000001 * fTemp28)) + (0.0247318656 * fTemp32))) + (fConst5 * (0.0 - ((fConst19 * fRec216[1]) + (fConst18 * fRec213[1]))))));
			fRec218[0] = (fRec218[1] + fTemp78);
			fRec216[0] = fRec218[0];
			double fRec217 = fTemp78;
			fRec215[0] = (fRec216[0] + fRec215[1]);
			fRec213[0] = fRec215[0];
			double fRec214 = fRec217;
			fVec3[(IOTA & 1023)] = ((0.0121692494 * fTemp7) + (fRec175 + (fRec190 + (fRec202 + (fRec211 + fRec214)))));
			output3[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec3[((IOTA - iConst32) & 1023)])));
			double fTemp79 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec231[1]) + (fConst29 * fRec228[1])))) + (fConst28 * (((0.0477848632 * fTemp40) + ((0.066676676700000007 * fTemp44) + ((0.0353568374 * fTemp41) + ((0.074296191299999995 * fTemp46) + ((0.0198211966 * fTemp47) + (0.018438762099999999 * fTemp42)))))) - ((0.0026775191999999998 * fTemp39) + ((0.00072549430000000002 * fTemp43) + ((0.00034724879999999998 * fTemp45) + ((0.060761972499999997 * fTemp48) + (0.00097000799999999996 * fTemp49)))))))));
			fRec233[0] = (fRec233[1] + fTemp79);
			fRec231[0] = fRec233[0];
			double fRec232 = fTemp79;
			fRec230[0] = (fRec231[0] + fRec230[1]);
			fRec228[0] = fRec230[0];
			double fRec229 = fRec232;
			double fTemp80 = (fConst23 * (0.0 - ((fConst25 * fRec225[1]) + (fConst24 * fRec222[1]))));
			fRec227[0] = (fRec229 + (fRec227[1] + fTemp80));
			fRec225[0] = fRec227[0];
			double fRec226 = (fRec229 + fTemp80);
			fRec224[0] = (fRec225[0] + fRec224[1]);
			fRec222[0] = fRec224[0];
			double fRec223 = fRec226;
			double fTemp81 = (fConst31 * fRec219[1]);
			fRec221[0] = ((fRec223 + fRec221[1]) - fTemp81);
			fRec219[0] = fRec221[0];
			double fRec220 = (fRec223 - fTemp81);
			double fTemp82 = (fConst17 * (((0.0243329644 * fTemp30) - ((0.031185574899999999 * fTemp32) + ((0.0312496123 * fTemp28) + ((0.062592298500000004 * fTemp29) + (0.0188865548 * fTemp31))))) + (fConst5 * (0.0 - ((fConst19 * fRec237[1]) + (fConst18 * fRec234[1]))))));
			fRec239[0] = (fRec239[1] + fTemp82);
			fRec237[0] = fRec239[0];
			double fRec238 = fTemp82;
			fRec236[0] = (fRec237[0] + fRec236[1]);
			fRec234[0] = fRec236[0];
			double fRec235 = fRec238;
			double fTemp83 = (fConst20 * ((((0.015043623000000001 * fTemp35) + (0.029797874200000001 * fTemp36)) - (0.039922928500000003 * fTemp34)) - (fConst21 * fRec240[1])));
			fRec242[0] = (fRec242[1] + fTemp83);
			fRec240[0] = fRec242[0];
			double fRec241 = fTemp83;
			double fTemp84 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec249[1]) + (fConst12 * fRec246[1])))) + (fConst15 * ((0.030563589700000001 * fTemp22) - ((((((0.024552632899999999 * fTemp19) + (0.053104704199999998 * fTemp20)) + (0.040491397300000002 * fTemp23)) + (0.021284622400000001 * fTemp24)) + (0.013705421299999999 * fTemp21)) + (0.069759276800000006 * fTemp25))))));
			fRec251[0] = (fRec251[1] + fTemp84);
			fRec249[0] = fRec251[0];
			double fRec250 = fTemp84;
			fRec248[0] = (fRec249[0] + fRec248[1]);
			fRec246[0] = fRec248[0];
			double fRec247 = fRec250;
			double fTemp85 = (fConst16 * fRec243[1]);
			fRec245[0] = ((fRec247 + fRec245[1]) - fTemp85);
			fRec243[0] = fRec245[0];
			double fRec244 = (fRec247 - fTemp85);
			double fTemp86 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec261[1]) + (fConst6 * fRec258[1])))) + (fConst4 * ((((0.053382000800000003 * fTemp12) + ((0.025399511100000001 * fTemp11) + ((0.043655292900000003 * fTemp9) + (0.011882199899999999 * fTemp10)))) + (0.011306278499999999 * fTemp14)) - ((((0.025355414100000001 * fTemp8) + (0.040476258100000002 * fTemp13)) + (0.060200963199999999 * fTemp15)) + (0.062926540399999994 * fTemp16))))));
			fRec263[0] = (fRec263[1] + fTemp86);
			fRec261[0] = fRec263[0];
			double fRec262 = fTemp86;
			fRec260[0] = (fRec261[0] + fRec260[1]);
			fRec258[0] = fRec260[0];
			double fRec259 = fRec262;
			double fTemp87 = (fConst8 * (0.0 - ((fConst10 * fRec255[1]) + (fConst9 * fRec252[1]))));
			fRec257[0] = (fRec259 + (fRec257[1] + fTemp87));
			fRec255[0] = fRec257[0];
			double fRec256 = (fRec259 + fTemp87);
			fRec254[0] = (fRec255[0] + fRec254[1]);
			fRec252[0] = fRec254[0];
			double fRec253 = fRec256;
			fVec4[(IOTA & 1023)] = ((0.0177769474 * fTemp7) + (fRec220 + (fRec235 + (fRec241 + (fRec244 + fRec253)))));
			output4[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec4[((IOTA - iConst32) & 1023)])));
			double fTemp88 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec276[1]) + (fConst29 * fRec273[1])))) + (fConst28 * (((0.0031342259999999999 * fTemp39) + ((0.035211396399999997 * fTemp40) + ((0.021189306200000001 * fTemp44) + ((0.036981036799999999 * fTemp41) + ((((0.044769852700000001 * fTemp47) + (0.015440888200000001 * fTemp42)) + (0.028801833200000002 * fTemp48)) + (0.055343846100000003 * fTemp49)))))) - (((0.029635049 * fTemp46) + (0.023621150399999999 * fTemp45)) + (0.017963142599999999 * fTemp43))))));
			fRec278[0] = (fRec278[1] + fTemp88);
			fRec276[0] = fRec278[0];
			double fRec277 = fTemp88;
			fRec275[0] = (fRec276[0] + fRec275[1]);
			fRec273[0] = fRec275[0];
			double fRec274 = fRec277;
			double fTemp89 = (fConst23 * (0.0 - ((fConst25 * fRec270[1]) + (fConst24 * fRec267[1]))));
			fRec272[0] = (fRec274 + (fRec272[1] + fTemp89));
			fRec270[0] = fRec272[0];
			double fRec271 = (fRec274 + fTemp89);
			fRec269[0] = (fRec270[0] + fRec269[1]);
			fRec267[0] = fRec269[0];
			double fRec268 = fRec271;
			double fTemp90 = (fConst31 * fRec264[1]);
			fRec266[0] = ((fRec268 + fRec266[1]) - fTemp90);
			fRec264[0] = fRec266[0];
			double fRec265 = (fRec268 - fTemp90);
			double fTemp91 = (fConst17 * (((0.0050270990000000002 * fTemp30) - ((0.0249998318 * fTemp32) + ((0.0216047173 * fTemp28) + ((0.020138157800000001 * fTemp29) + (0.043521099100000002 * fTemp31))))) + (fConst5 * (0.0 - ((fConst19 * fRec282[1]) + (fConst18 * fRec279[1]))))));
			fRec284[0] = (fRec284[1] + fTemp91);
			fRec282[0] = fRec284[0];
			double fRec283 = fTemp91;
			fRec281[0] = (fRec282[0] + fRec281[1]);
			fRec279[0] = fRec281[0];
			double fRec280 = fRec283;
			double fTemp92 = (fConst20 * ((((0.0081369890000000007 * fTemp35) + (0.0076172284000000003 * fTemp36)) - (0.034510821300000001 * fTemp34)) - (fConst21 * fRec285[1])));
			fRec287[0] = (fRec287[1] + fTemp92);
			fRec285[0] = fRec287[0];
			double fRec286 = fTemp92;
			double fTemp93 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec294[1]) + (fConst12 * fRec291[1])))) + (fConst15 * (((0.0450030794 * fTemp19) + (0.034448975999999999 * fTemp22)) - (((((0.014167074700000001 * fTemp20) + (0.0242176159 * fTemp23)) + (0.0072634917000000002 * fTemp24)) + (0.028892031499999998 * fTemp21)) + (0.034128747799999998 * fTemp25))))));
			fRec296[0] = (fRec296[1] + fTemp93);
			fRec294[0] = fRec296[0];
			double fRec295 = fTemp93;
			fRec293[0] = (fRec294[0] + fRec293[1]);
			fRec291[0] = fRec293[0];
			double fRec292 = fRec295;
			double fTemp94 = (fConst16 * fRec288[1]);
			fRec290[0] = ((fRec292 + fRec290[1]) - fTemp94);
			fRec288[0] = fRec290[0];
			double fRec289 = (fRec292 - fTemp94);
			double fTemp95 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec306[1]) + (fConst6 * fRec303[1])))) + (fConst4 * (((((0.042366692400000003 * fTemp12) + ((0.0128109685 * fTemp11) + ((0.031516280000000001 * fTemp8) + ((0.046625532900000002 * fTemp9) + (0.019030370899999999 * fTemp10))))) + (0.030051461299999999 * fTemp14)) + (0.0398196948 * fTemp16)) - ((0.0096296490000000005 * fTemp13) + (0.0256163378 * fTemp15))))));
			fRec308[0] = (fRec308[1] + fTemp95);
			fRec306[0] = fRec308[0];
			double fRec307 = fTemp95;
			fRec305[0] = (fRec306[0] + fRec305[1]);
			fRec303[0] = fRec305[0];
			double fRec304 = fRec307;
			double fTemp96 = (fConst8 * (0.0 - ((fConst10 * fRec300[1]) + (fConst9 * fRec297[1]))));
			fRec302[0] = (fRec304 + (fRec302[1] + fTemp96));
			fRec300[0] = fRec302[0];
			double fRec301 = (fRec304 + fTemp96);
			fRec299[0] = (fRec300[0] + fRec299[1]);
			fRec297[0] = fRec299[0];
			double fRec298 = fRec301;
			fVec5[(IOTA & 1023)] = ((0.0122919182 * fTemp7) + (fRec265 + (fRec280 + (fRec286 + (fRec289 + fRec298)))));
			output5[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec5[((IOTA - iConst32) & 1023)])));
			double fTemp97 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec321[1]) + (fConst29 * fRec318[1])))) + (fConst28 * (((0.048307506100000001 * fTemp40) + ((0.0014151623000000001 * fTemp43) + ((0.066434772200000006 * fTemp47) + (0.057966219999999999 * fTemp48)))) - ((0.0023358551 * fTemp39) + ((0.0228035904 * fTemp44) + ((0.012138807499999999 * fTemp45) + ((0.040584202 * fTemp41) + ((0.047938293399999998 * fTemp46) + ((0.01402425 * fTemp42) + (0.057222960099999998 * fTemp49)))))))))));
			fRec323[0] = (fRec323[1] + fTemp97);
			fRec321[0] = fRec323[0];
			double fRec322 = fTemp97;
			fRec320[0] = (fRec321[0] + fRec320[1]);
			fRec318[0] = fRec320[0];
			double fRec319 = fRec322;
			double fTemp98 = (fConst23 * (0.0 - ((fConst25 * fRec315[1]) + (fConst24 * fRec312[1]))));
			fRec317[0] = (fRec319 + (fRec317[1] + fTemp98));
			fRec315[0] = fRec317[0];
			double fRec316 = (fRec319 + fTemp98);
			fRec314[0] = (fRec315[0] + fRec314[1]);
			fRec312[0] = fRec314[0];
			double fRec313 = fRec316;
			double fTemp99 = (fConst31 * fRec309[1]);
			fRec311[0] = ((fRec313 + fRec311[1]) - fTemp99);
			fRec309[0] = fRec311[0];
			double fRec310 = (fRec313 - fTemp99);
			double fTemp100 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec333[1]) + (fConst6 * fRec330[1])))) + (fConst4 * (((((((0.066867708799999995 * fTemp12) + ((0.059324873399999999 * fTemp8) + (0.012022150699999999 * fTemp10))) + (0.010633501199999999 * fTemp13)) + (0.025197047399999999 * fTemp14)) + (0.028667159899999999 * fTemp15)) + (0.059584912800000001 * fTemp16)) - ((0.048992253800000003 * fTemp9) + (0.0123857741 * fTemp11))))));
			fRec335[0] = (fRec335[1] + fTemp100);
			fRec333[0] = fRec335[0];
			double fRec334 = fTemp100;
			fRec332[0] = (fRec333[0] + fRec332[1]);
			fRec330[0] = fRec332[0];
			double fRec331 = fRec334;
			double fTemp101 = (fConst8 * (0.0 - ((fConst10 * fRec327[1]) + (fConst9 * fRec324[1]))));
			fRec329[0] = (fRec331 + (fRec329[1] + fTemp101));
			fRec327[0] = fRec329[0];
			double fRec328 = (fRec331 + fTemp101);
			fRec326[0] = (fRec327[0] + fRec326[1]);
			fRec324[0] = fRec326[0];
			double fRec325 = fRec328;
			double fTemp102 = (fConst11 * ((fConst15 * ((((((0.065176320100000004 * fTemp19) + (0.016109718799999999 * fTemp20)) + (0.036925357200000002 * fTemp22)) + (0.0073694848000000002 * fTemp24)) + (0.036341354100000001 * fTemp25)) - ((0.040936488600000001 * fTemp23) + (0.053000679199999998 * fTemp21)))) + (fConst5 * (0.0 - ((fConst13 * fRec342[1]) + (fConst12 * fRec339[1]))))));
			fRec344[0] = (fRec344[1] + fTemp102);
			fRec342[0] = fRec344[0];
			double fRec343 = fTemp102;
			fRec341[0] = (fRec342[0] + fRec341[1]);
			fRec339[0] = fRec341[0];
			double fRec340 = fRec343;
			double fTemp103 = (fConst16 * fRec336[1]);
			fRec338[0] = ((fRec340 + fRec338[1]) - fTemp103);
			fRec336[0] = fRec338[0];
			double fRec337 = (fRec340 - fTemp103);
			double fTemp104 = (fConst20 * (((0.015210262699999999 * fTemp35) - ((0.0496797462 * fTemp34) + (0.0082717251999999998 * fTemp36))) - (fConst21 * fRec345[1])));
			fRec347[0] = (fRec347[1] + fTemp104);
			fRec345[0] = fRec347[0];
			double fRec346 = fTemp104;
			double fTemp105 = (fConst17 * (((0.021678712900000001 * fTemp29) - ((0.031534986899999999 * fTemp32) + ((0.039613074499999998 * fTemp28) + ((0.0057907998000000004 * fTemp30) + (0.062392304500000002 * fTemp31))))) + (fConst5 * (0.0 - ((fConst19 * fRec351[1]) + (fConst18 * fRec348[1]))))));
			fRec353[0] = (fRec353[1] + fTemp105);
			fRec351[0] = fRec353[0];
			double fRec352 = fTemp105;
			fRec350[0] = (fRec351[0] + fRec350[1]);
			fRec348[0] = fRec350[0];
			double fRec349 = fRec352;
			fVec6[(IOTA & 1023)] = ((0.017975970800000001 * fTemp7) + (fRec310 + (fRec325 + (fRec337 + (fRec346 + fRec349)))));
			output6[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec6[((IOTA - iConst32) & 1023)])));
			double fTemp106 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec366[1]) + (fConst29 * fRec363[1])))) + (fConst28 * (((0.035693073999999998 * fTemp40) + ((0.0077157511000000003 * fTemp45) + ((0.062261776400000003 * fTemp46) + (0.019416985800000001 * fTemp47)))) - ((0.0109410863 * fTemp39) + ((0.0148455471 * fTemp43) + ((0.046266806299999998 * fTemp44) + ((0.0346117404 * fTemp41) + (((0.027441622499999999 * fTemp42) + (0.032379551399999998 * fTemp48)) + (0.0113202961 * fTemp49))))))))));
			fRec368[0] = (fRec368[1] + fTemp106);
			fRec366[0] = fRec368[0];
			double fRec367 = fTemp106;
			fRec365[0] = (fRec366[0] + fRec365[1]);
			fRec363[0] = fRec365[0];
			double fRec364 = fRec367;
			double fTemp107 = (fConst23 * (0.0 - ((fConst25 * fRec360[1]) + (fConst24 * fRec357[1]))));
			fRec362[0] = (fRec364 + (fRec362[1] + fTemp107));
			fRec360[0] = fRec362[0];
			double fRec361 = (fRec364 + fTemp107);
			fRec359[0] = (fRec360[0] + fRec359[1]);
			fRec357[0] = fRec359[0];
			double fRec358 = fRec361;
			double fTemp108 = (fConst31 * fRec354[1]);
			fRec356[0] = ((fRec358 + fRec356[1]) - fTemp108);
			fRec354[0] = fRec356[0];
			double fRec355 = (fRec358 - fTemp108);
			double fTemp109 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec378[1]) + (fConst6 * fRec375[1])))) + (fConst4 * ((((((0.036750531599999997 * fTemp12) + (0.0192760441 * fTemp10)) + (0.0243021465 * fTemp13)) + (0.011587758 * fTemp14)) + (0.040540927999999997 * fTemp15)) - ((((0.043278828399999997 * fTemp9) + (0.0069781104999999998 * fTemp8)) + (0.030971286099999999 * fTemp11)) + (0.044338717499999999 * fTemp16))))));
			fRec380[0] = (fRec380[1] + fTemp109);
			fRec378[0] = fRec380[0];
			double fRec379 = fTemp109;
			fRec377[0] = (fRec378[0] + fRec377[1]);
			fRec375[0] = fRec377[0];
			double fRec376 = fRec379;
			double fTemp110 = (fConst8 * (0.0 - ((fConst10 * fRec372[1]) + (fConst9 * fRec369[1]))));
			fRec374[0] = (fRec376 + (fRec374[1] + fTemp110));
			fRec372[0] = fRec374[0];
			double fRec373 = (fRec376 + fTemp110);
			fRec371[0] = (fRec372[0] + fRec371[1]);
			fRec369[0] = fRec371[0];
			double fRec370 = fRec373;
			double fTemp111 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec387[1]) + (fConst12 * fRec384[1])))) + (fConst15 * (((((0.0299154498 * fTemp20) + (0.029449540699999999 * fTemp22)) + (0.0201492983 * fTemp24)) + (0.055988441100000001 * fTemp25)) - (((0.011600321199999999 * fTemp19) + (0.024573141400000002 * fTemp23)) + (0.0130363411 * fTemp21))))));
			fRec389[0] = (fRec389[1] + fTemp111);
			fRec387[0] = fRec389[0];
			double fRec388 = fTemp111;
			fRec386[0] = (fRec387[0] + fRec386[1]);
			fRec384[0] = fRec386[0];
			double fRec385 = fRec388;
			double fTemp112 = (fConst16 * fRec381[1]);
			fRec383[0] = ((fRec385 + fRec383[1]) - fTemp112);
			fRec381[0] = fRec383[0];
			double fRec382 = (fRec385 - fTemp112);
			double fTemp113 = (fConst20 * (((0.0082610322000000007 * fTemp35) - ((0.029775918200000001 * fTemp34) + (0.019964574700000001 * fTemp36))) - (fConst21 * fRec390[1])));
			fRec392[0] = (fRec392[1] + fTemp113);
			fRec390[0] = fRec392[0];
			double fRec391 = fTemp113;
			double fTemp114 = (fConst17 * (((0.044987742599999998 * fTemp29) - ((0.025355001700000001 * fTemp32) + ((0.018839948299999999 * fTemp28) + ((0.0123225125 * fTemp30) + (0.018405412699999998 * fTemp31))))) + (fConst5 * (0.0 - ((fConst19 * fRec396[1]) + (fConst18 * fRec393[1]))))));
			fRec398[0] = (fRec398[1] + fTemp114);
			fRec396[0] = fRec398[0];
			double fRec397 = fTemp114;
			fRec395[0] = (fRec396[0] + fRec395[1]);
			fRec393[0] = fRec395[0];
			double fRec394 = fRec397;
			fVec7[(IOTA & 1023)] = ((0.0124723197 * fTemp7) + (fRec355 + (fRec370 + (fRec382 + (fRec391 + fRec394)))));
			output7[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec7[((IOTA - iConst32) & 1023)])));
			double fTemp115 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec411[1]) + (fConst29 * fRec408[1])))) + (fConst28 * (((0.045625803800000003 * fTemp40) + ((0.0022093131000000001 * fTemp43) + ((0.018298455799999998 * fTemp45) + ((0.041279645400000002 * fTemp41) + ((0.0022493434000000001 * fTemp42) + (0.072113317499999996 * fTemp49)))))) - ((0.0013791459999999999 * fTemp39) + ((0.062492380200000003 * fTemp44) + ((0.0109362105 * fTemp46) + ((0.023001939999999998 * fTemp47) + (0.054088906300000003 * fTemp48)))))))));
			fRec413[0] = (fRec413[1] + fTemp115);
			fRec411[0] = fRec413[0];
			double fRec412 = fTemp115;
			fRec410[0] = (fRec411[0] + fRec410[1]);
			fRec408[0] = fRec410[0];
			double fRec409 = fRec412;
			double fTemp116 = (fConst23 * (0.0 - ((fConst25 * fRec405[1]) + (fConst24 * fRec402[1]))));
			fRec407[0] = (fRec409 + (fRec407[1] + fTemp116));
			fRec405[0] = fRec407[0];
			double fRec406 = (fRec409 + fTemp116);
			fRec404[0] = (fRec405[0] + fRec404[1]);
			fRec402[0] = fRec404[0];
			double fRec403 = fRec406;
			double fTemp117 = (fConst31 * fRec399[1]);
			fRec401[0] = ((fRec403 + fRec401[1]) - fTemp117);
			fRec399[0] = fRec401[0];
			double fRec400 = (fRec403 - fTemp117);
			double fTemp118 = (fConst2 * ((fConst4 * (((((0.036857610700000001 * fTemp12) + ((0.049946477699999998 * fTemp9) + (0.0118083966 * fTemp10))) + (0.0519347904 * fTemp13)) + (0.0187913896 * fTemp15)) - ((((0.059644737699999999 * fTemp8) + (0.024001714399999999 * fTemp11)) + (0.0127271378 * fTemp14)) + (0.055027506099999998 * fTemp16)))) + (fConst5 * (0.0 - ((fConst7 * fRec423[1]) + (fConst6 * fRec420[1]))))));
			fRec425[0] = (fRec425[1] + fTemp118);
			fRec423[0] = fRec425[0];
			double fRec424 = fTemp118;
			fRec422[0] = (fRec423[0] + fRec422[1]);
			fRec420[0] = fRec422[0];
			double fRec421 = fRec424;
			double fTemp119 = (fConst8 * (0.0 - ((fConst10 * fRec417[1]) + (fConst9 * fRec414[1]))));
			fRec419[0] = (fRec421 + (fRec419[1] + fTemp119));
			fRec417[0] = fRec419[0];
			double fRec418 = (fRec421 + fTemp119);
			fRec416[0] = (fRec417[0] + fRec416[1]);
			fRec414[0] = fRec416[0];
			double fRec415 = fRec418;
			double fTemp120 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec432[1]) + (fConst12 * fRec429[1])))) + (fConst15 * ((((((0.049535040099999997 * fTemp20) + (0.019507073100000001 * fTemp22)) + (0.0301244596 * fTemp24)) + (0.0161223445 * fTemp21)) + (0.016962588099999999 * fTemp25)) - ((0.069074658100000005 * fTemp19) + (0.038324688000000003 * fTemp23))))));
			fRec434[0] = (fRec434[1] + fTemp120);
			fRec432[0] = fRec434[0];
			double fRec433 = fTemp120;
			fRec431[0] = (fRec432[0] + fRec431[1]);
			fRec429[0] = fRec431[0];
			double fRec430 = fRec433;
			double fTemp121 = (fConst16 * fRec426[1]);
			fRec428[0] = ((fRec430 + fRec428[1]) - fTemp121);
			fRec426[0] = fRec428[0];
			double fRec427 = (fRec430 - fTemp121);
			double fTemp122 = (fConst20 * (((0.0141814517 * fTemp35) - ((0.027112731000000001 * fTemp34) + (0.038888796500000003 * fTemp36))) - (fConst21 * fRec435[1])));
			fRec437[0] = (fRec437[1] + fTemp122);
			fRec435[0] = fRec437[0];
			double fRec436 = fTemp122;
			double fTemp123 = (fConst17 * ((((0.058517032400000002 * fTemp29) + (0.021888716200000002 * fTemp31)) - ((0.029800104599999998 * fTemp32) + ((0.022070168599999999 * fTemp28) + (0.030228014500000001 * fTemp30)))) + (fConst5 * (0.0 - ((fConst19 * fRec441[1]) + (fConst18 * fRec438[1]))))));
			fRec443[0] = (fRec443[1] + fTemp123);
			fRec441[0] = fRec443[0];
			double fRec442 = fTemp123;
			fRec440[0] = (fRec441[0] + fRec440[1]);
			fRec438[0] = fRec440[0];
			double fRec439 = fRec442;
			fVec8[(IOTA & 1023)] = ((0.0168837615 * fTemp7) + (fRec400 + (fRec415 + (fRec427 + (fRec436 + fRec439)))));
			output8[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec8[((IOTA - iConst32) & 1023)])));
			double fTemp124 = (fConst26 * ((fConst28 * (((0.0002356081 * fTemp39) + ((0.045111884300000002 * fTemp40) + ((0.013317236099999999 * fTemp45) + ((0.0327089115 * fTemp41) + ((0.0128097195 * fTemp42) + (0.058772782599999997 * fTemp48)))))) - ((0.0026237346000000002 * fTemp43) + ((0.018255908599999999 * fTemp44) + ((0.049797252799999997 * fTemp46) + ((0.063240645999999998 * fTemp47) + (0.052425355 * fTemp49))))))) + (fConst5 * (0.0 - ((fConst30 * fRec456[1]) + (fConst29 * fRec453[1]))))));
			fRec458[0] = (fRec458[1] + fTemp124);
			fRec456[0] = fRec458[0];
			double fRec457 = fTemp124;
			fRec455[0] = (fRec456[0] + fRec455[1]);
			fRec453[0] = fRec455[0];
			double fRec454 = fRec457;
			double fTemp125 = (fConst23 * (0.0 - ((fConst25 * fRec450[1]) + (fConst24 * fRec447[1]))));
			fRec452[0] = (fRec454 + (fRec452[1] + fTemp125));
			fRec450[0] = fRec452[0];
			double fRec451 = (fRec454 + fTemp125);
			fRec449[0] = (fRec450[0] + fRec449[1]);
			fRec447[0] = fRec449[0];
			double fRec448 = fRec451;
			double fTemp126 = (fConst31 * fRec444[1]);
			fRec446[0] = ((fRec448 + fRec446[1]) - fTemp126);
			fRec444[0] = fRec446[0];
			double fRec445 = (fRec448 - fTemp126);
			double fTemp127 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec468[1]) + (fConst6 * fRec465[1])))) + (fConst4 * (((((0.0082876245000000001 * fTemp12) + ((0.041266226699999999 * fTemp9) + (0.0118156072 * fTemp10))) + (0.062258726200000003 * fTemp13)) + (0.060838951699999998 * fTemp16)) - ((((0.022433164799999999 * fTemp8) + (0.010982688500000001 * fTemp11)) + (0.024689827000000001 * fTemp14)) + (0.0574520164 * fTemp15))))));
			fRec470[0] = (fRec470[1] + fTemp127);
			fRec468[0] = fRec470[0];
			double fRec469 = fTemp127;
			fRec467[0] = (fRec468[0] + fRec467[1]);
			fRec465[0] = fRec467[0];
			double fRec466 = fRec469;
			double fTemp128 = (fConst8 * (0.0 - ((fConst10 * fRec462[1]) + (fConst9 * fRec459[1]))));
			fRec464[0] = (fRec466 + (fRec464[1] + fTemp128));
			fRec462[0] = fRec464[0];
			double fRec463 = (fRec466 + fTemp128);
			fRec461[0] = (fRec462[0] + fRec461[1]);
			fRec459[0] = fRec461[0];
			double fRec460 = fRec463;
			double fTemp129 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec477[1]) + (fConst12 * fRec474[1])))) + (fConst15 * (((((0.012327579599999999 * fTemp20) + (0.0062190835 * fTemp22)) + (0.034988735799999997 * fTemp24)) + (0.049783050099999997 * fTemp21)) - (((0.029840964599999999 * fTemp19) + (0.037730066700000002 * fTemp23)) + (0.063589060399999994 * fTemp25))))));
			fRec479[0] = (fRec479[1] + fTemp129);
			fRec477[0] = fRec479[0];
			double fRec478 = fTemp129;
			fRec476[0] = (fRec477[0] + fRec476[1]);
			fRec474[0] = fRec476[0];
			double fRec475 = fRec478;
			double fTemp130 = (fConst16 * fRec471[1]);
			fRec473[0] = ((fRec475 + fRec473[1]) - fTemp130);
			fRec471[0] = fRec473[0];
			double fRec472 = (fRec475 - fTemp130);
			double fTemp131 = (fConst20 * (((0.0139324784 * fTemp35) - ((0.0065763686000000002 * fTemp34) + (0.046251340600000003 * fTemp36))) - (fConst21 * fRec480[1])));
			fRec482[0] = (fRec482[1] + fTemp131);
			fRec480[0] = fRec482[0];
			double fRec481 = fTemp131;
			double fTemp132 = (fConst17 * ((((0.017464497700000001 * fTemp29) + (0.0590953917 * fTemp31)) - ((0.029421955199999999 * fTemp32) + ((0.0043610463999999996 * fTemp28) + (0.036541627 * fTemp30)))) + (fConst5 * (0.0 - ((fConst19 * fRec486[1]) + (fConst18 * fRec483[1]))))));
			fRec488[0] = (fRec488[1] + fTemp132);
			fRec486[0] = fRec488[0];
			double fRec487 = fTemp132;
			fRec485[0] = (fRec486[0] + fRec485[1]);
			fRec483[0] = fRec485[0];
			double fRec484 = fRec487;
			fVec9[(IOTA & 1023)] = ((0.016628879499999999 * fTemp7) + (fRec445 + (fRec460 + (fRec472 + (fRec481 + fRec484)))));
			output9[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec9[((IOTA - iConst32) & 1023)])));
			double fTemp133 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec501[1]) + (fConst29 * fRec498[1])))) + (fConst28 * (((0.034940235600000001 * fTemp40) + ((0.0033077484999999998 * fTemp43) + ((0.021551177500000001 * fTemp44) + ((0.056261408200000002 * fTemp46) + ((0.0234773343 * fTemp42) + (0.027837470499999999 * fTemp48)))))) - ((0.0181908686 * fTemp39) + ((0.0159802691 * fTemp45) + ((0.037431765899999997 * fTemp41) + ((0.044212142400000001 * fTemp47) + (0.028143733000000001 * fTemp49)))))))));
			fRec503[0] = (fRec503[1] + fTemp133);
			fRec501[0] = fRec503[0];
			double fRec502 = fTemp133;
			fRec500[0] = (fRec501[0] + fRec500[1]);
			fRec498[0] = fRec500[0];
			double fRec499 = fRec502;
			double fTemp134 = (fConst23 * (0.0 - ((fConst25 * fRec495[1]) + (fConst24 * fRec492[1]))));
			fRec497[0] = (fRec499 + (fRec497[1] + fTemp134));
			fRec495[0] = fRec497[0];
			double fRec496 = (fRec499 + fTemp134);
			fRec494[0] = (fRec495[0] + fRec494[1]);
			fRec492[0] = fRec494[0];
			double fRec493 = fRec496;
			double fTemp135 = (fConst31 * fRec489[1]);
			fRec491[0] = ((fRec493 + fRec491[1]) - fTemp135);
			fRec489[0] = fRec491[0];
			double fRec490 = (fRec493 - fTemp135);
			double fTemp136 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec513[1]) + (fConst6 * fRec510[1])))) + (fConst4 * (((((0.013207497 * fTemp11) + ((0.025970928300000001 * fTemp8) + (0.019120708300000001 * fTemp10))) + (0.041974533299999998 * fTemp13)) + (0.038781112700000002 * fTemp16)) - ((((0.047522182699999999 * fTemp9) + (0.0097923941000000007 * fTemp12)) + (0.029980714499999998 * fTemp14)) + (0.0308817529 * fTemp15))))));
			fRec515[0] = (fRec515[1] + fTemp136);
			fRec513[0] = fRec515[0];
			double fRec514 = fTemp136;
			fRec512[0] = (fRec513[0] + fRec512[1]);
			fRec510[0] = fRec512[0];
			double fRec511 = fRec514;
			double fTemp137 = (fConst8 * (0.0 - ((fConst10 * fRec507[1]) + (fConst9 * fRec504[1]))));
			fRec509[0] = (fRec511 + (fRec509[1] + fTemp137));
			fRec507[0] = fRec509[0];
			double fRec508 = (fRec511 + fTemp137);
			fRec506[0] = (fRec507[0] + fRec506[1]);
			fRec504[0] = fRec506[0];
			double fRec505 = fRec508;
			double fTemp138 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec522[1]) + (fConst12 * fRec519[1])))) + (fConst15 * ((((0.034846283499999998 * fTemp19) + (0.034412267900000001 * fTemp24)) + (0.028511208400000002 * fTemp21)) - ((((0.0143775897 * fTemp20) + (0.0074658054 * fTemp22)) + (0.024013405000000002 * fTemp23)) + (0.044376183100000001 * fTemp25))))));
			fRec524[0] = (fRec524[1] + fTemp138);
			fRec522[0] = fRec524[0];
			double fRec523 = fTemp138;
			fRec521[0] = (fRec522[0] + fRec521[1]);
			fRec519[0] = fRec521[0];
			double fRec520 = fRec523;
			double fTemp139 = (fConst16 * fRec516[1]);
			fRec518[0] = ((fRec520 + fRec518[1]) - fTemp139);
			fRec516[0] = fRec518[0];
			double fRec517 = (fRec520 - fTemp139);
			double fTemp140 = (fConst20 * ((((0.0077890746999999998 * fTemp34) + (0.0080658692000000008 * fTemp35)) - (0.034369076700000001 * fTemp36)) - (fConst21 * fRec525[1])));
			fRec527[0] = (fRec527[1] + fTemp140);
			fRec525[0] = fRec527[0];
			double fRec526 = fTemp140;
			double fTemp141 = (fConst17 * ((((0.0051041465000000001 * fTemp28) + (0.043200536400000003 * fTemp31)) - ((0.0249576325 * fTemp32) + ((0.0205832842 * fTemp29) + (0.021394325400000001 * fTemp30)))) + (fConst5 * (0.0 - ((fConst19 * fRec531[1]) + (fConst18 * fRec528[1]))))));
			fRec533[0] = (fRec533[1] + fTemp141);
			fRec531[0] = fRec533[0];
			double fRec532 = fTemp141;
			fRec530[0] = (fRec531[0] + fRec530[1]);
			fRec528[0] = fRec530[0];
			double fRec529 = fRec532;
			fVec10[(IOTA & 1023)] = ((0.0122519133 * fTemp7) + (fRec490 + (fRec505 + (fRec517 + (fRec526 + fRec529)))));
			output10[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec10[((IOTA - iConst32) & 1023)])));
			double fTemp142 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec546[1]) + (fConst29 * fRec543[1])))) + (fConst28 * (((0.045588551099999999 * fTemp40) + ((0.063598181399999995 * fTemp44) + ((0.0013209424 * fTemp46) + ((0.0001792233 * fTemp42) + (0.073262046600000005 * fTemp49))))) - ((0.00072654380000000001 * fTemp39) + ((0.0022586491000000002 * fTemp43) + ((0.017682739199999999 * fTemp45) + ((0.036436880300000002 * fTemp41) + ((0.0199901813 * fTemp47) + (0.057966045299999998 * fTemp48))))))))));
			fRec548[0] = (fRec548[1] + fTemp142);
			fRec546[0] = fRec548[0];
			double fRec547 = fTemp142;
			fRec545[0] = (fRec546[0] + fRec545[1]);
			fRec543[0] = fRec545[0];
			double fRec544 = fRec547;
			double fTemp143 = (fConst23 * (0.0 - ((fConst25 * fRec540[1]) + (fConst24 * fRec537[1]))));
			fRec542[0] = (fRec544 + (fRec542[1] + fTemp143));
			fRec540[0] = fRec542[0];
			double fRec541 = (fRec544 + fTemp143);
			fRec539[0] = (fRec540[0] + fRec539[1]);
			fRec537[0] = fRec539[0];
			double fRec538 = fRec541;
			double fTemp144 = (fConst31 * fRec534[1]);
			fRec536[0] = ((fRec538 + fRec536[1]) - fTemp144);
			fRec534[0] = fRec536[0];
			double fRec535 = (fRec538 - fTemp144);
			double fTemp145 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec558[1]) + (fConst6 * fRec555[1])))) + (fConst4 * (((((0.024378258399999998 * fTemp11) + ((0.058590138700000002 * fTemp8) + (0.0114670459 * fTemp10))) + (0.051197272100000003 * fTemp13)) + (0.022856634899999999 * fTemp15)) - ((((0.044102355699999998 * fTemp9) + (0.038143268700000003 * fTemp12)) + (0.0109541929 * fTemp14)) + (0.060076494799999998 * fTemp16))))));
			fRec560[0] = (fRec560[1] + fTemp145);
			fRec558[0] = fRec560[0];
			double fRec559 = fTemp145;
			fRec557[0] = (fRec558[0] + fRec557[1]);
			fRec555[0] = fRec557[0];
			double fRec556 = fRec559;
			double fTemp146 = (fConst8 * (0.0 - ((fConst10 * fRec552[1]) + (fConst9 * fRec549[1]))));
			fRec554[0] = (fRec556 + (fRec554[1] + fTemp146));
			fRec552[0] = fRec554[0];
			double fRec553 = (fRec556 + fTemp146);
			fRec551[0] = (fRec552[0] + fRec551[1]);
			fRec549[0] = fRec551[0];
			double fRec550 = fRec553;
			double fTemp147 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec567[1]) + (fConst12 * fRec564[1])))) + (fConst15 * (((((0.067686701000000002 * fTemp19) + (0.0293273849 * fTemp24)) + (0.014017185 * fTemp21)) + (0.022222818299999999 * fTemp25)) - (((0.050466446700000001 * fTemp20) + (0.020218088700000001 * fTemp22)) + (0.038476820199999998 * fTemp23))))));
			fRec569[0] = (fRec569[1] + fTemp147);
			fRec567[0] = fRec569[0];
			double fRec568 = fTemp147;
			fRec566[0] = (fRec567[0] + fRec566[1]);
			fRec564[0] = fRec566[0];
			double fRec565 = fRec568;
			double fTemp148 = (fConst16 * fRec561[1]);
			fRec563[0] = ((fRec565 + fRec563[1]) - fTemp148);
			fRec561[0] = fRec563[0];
			double fRec562 = (fRec565 - fTemp148);
			double fTemp149 = (fConst20 * ((((0.028083669299999999 * fTemp34) + (0.0142656394 * fTemp35)) - (0.038231402300000002 * fTemp36)) - (fConst21 * fRec570[1])));
			fRec572[0] = (fRec572[1] + fTemp149);
			fRec570[0] = fRec572[0];
			double fRec571 = fTemp149;
			double fTemp150 = (fConst17 * ((((0.022841757300000001 * fTemp28) + (0.018945038899999999 * fTemp31)) - ((0.029716101000000002 * fTemp32) + ((0.059592769099999998 * fTemp29) + (0.029910834800000001 * fTemp30)))) + (fConst5 * (0.0 - ((fConst19 * fRec576[1]) + (fConst18 * fRec573[1]))))));
			fRec578[0] = (fRec578[1] + fTemp150);
			fRec576[0] = fRec578[0];
			double fRec577 = fTemp150;
			fRec575[0] = (fRec576[0] + fRec575[1]);
			fRec573[0] = fRec575[0];
			double fRec574 = fRec577;
			fVec11[(IOTA & 1023)] = ((0.016899001 * fTemp7) + (fRec535 + (fRec550 + (fRec562 + (fRec571 + fRec574)))));
			output11[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec11[((IOTA - iConst32) & 1023)])));
			double fTemp151 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec585[1]) + (fConst12 * fRec582[1])))) + (fConst15 * ((((0.0086368017999999998 * fTemp19) + (0.018310289699999999 * fTemp24)) + (0.052982696900000001 * fTemp25)) - ((((0.027518740999999999 * fTemp20) + (0.0276104972 * fTemp22)) + (0.022760134800000002 * fTemp23)) + (0.0128853253 * fTemp21))))));
			fRec587[0] = (fRec587[1] + fTemp151);
			fRec585[0] = fRec587[0];
			double fRec586 = fTemp151;
			fRec584[0] = (fRec585[0] + fRec584[1]);
			fRec582[0] = fRec584[0];
			double fRec583 = fRec586;
			double fTemp152 = (fConst16 * fRec579[1]);
			fRec581[0] = ((fRec583 + fRec581[1]) - fTemp152);
			fRec579[0] = fRec581[0];
			double fRec580 = (fRec583 - fTemp152);
			double fTemp153 = (fConst17 * (((0.0176248494 * fTemp28) - ((0.023499625900000001 * fTemp32) + ((0.041423636799999997 * fTemp29) + ((0.011190916800000001 * fTemp30) + (0.018337494199999999 * fTemp31))))) + (fConst5 * (0.0 - ((fConst19 * fRec591[1]) + (fConst18 * fRec588[1]))))));
			fRec593[0] = (fRec593[1] + fTemp153);
			fRec591[0] = fRec593[0];
			double fRec592 = fTemp153;
			fRec590[0] = (fRec591[0] + fRec590[1]);
			fRec588[0] = fRec590[0];
			double fRec589 = fRec592;
			double fTemp154 = (fConst20 * ((((0.0278907766 * fTemp34) + (0.0076511251000000004 * fTemp35)) - (0.018132753800000002 * fTemp36)) - (fConst21 * fRec594[1])));
			fRec596[0] = (fRec596[1] + fTemp154);
			fRec594[0] = fRec596[0];
			double fRec595 = fTemp154;
			double fTemp155 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec606[1]) + (fConst6 * fRec603[1])))) + (fConst4 * ((((((0.0285721086 * fTemp11) + ((0.0050040034999999997 * fTemp8) + ((0.043401817500000002 * fTemp9) + (0.0178838747 * fTemp10)))) + (0.022082653000000001 * fTemp13)) + (0.0116624026 * fTemp14)) + (0.038246039699999998 * fTemp15)) - ((0.034388745999999998 * fTemp12) + (0.0396602525 * fTemp16))))));
			fRec608[0] = (fRec608[1] + fTemp155);
			fRec606[0] = fRec608[0];
			double fRec607 = fTemp155;
			fRec605[0] = (fRec606[0] + fRec605[1]);
			fRec603[0] = fRec605[0];
			double fRec604 = fRec607;
			double fTemp156 = (fConst8 * (0.0 - ((fConst10 * fRec600[1]) + (fConst9 * fRec597[1]))));
			fRec602[0] = (fRec604 + (fRec602[1] + fTemp156));
			fRec600[0] = fRec602[0];
			double fRec601 = (fRec604 + fTemp156);
			fRec599[0] = (fRec600[0] + fRec599[1]);
			fRec597[0] = fRec599[0];
			double fRec598 = fRec601;
			double fTemp157 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec621[1]) + (fConst29 * fRec618[1])))) + (fConst28 * (((0.033069018899999997 * fTemp40) + ((0.0139821576 * fTemp43) + ((0.042608982400000002 * fTemp44) + ((0.034381001000000001 * fTemp41) + (0.019240633699999999 * fTemp47))))) - ((0.0099588112000000006 * fTemp39) + ((0.0060765628999999996 * fTemp45) + ((0.058995007100000003 * fTemp46) + (((0.026149855499999999 * fTemp42) + (0.028864750299999999 * fTemp48)) + (0.0151574302 * fTemp49)))))))));
			fRec623[0] = (fRec623[1] + fTemp157);
			fRec621[0] = fRec623[0];
			double fRec622 = fTemp157;
			fRec620[0] = (fRec621[0] + fRec620[1]);
			fRec618[0] = fRec620[0];
			double fRec619 = fRec622;
			double fTemp158 = (fConst23 * (0.0 - ((fConst25 * fRec615[1]) + (fConst24 * fRec612[1]))));
			fRec617[0] = (fRec619 + (fRec617[1] + fTemp158));
			fRec615[0] = fRec617[0];
			double fRec616 = (fRec619 + fTemp158);
			fRec614[0] = (fRec615[0] + fRec614[1]);
			fRec612[0] = fRec614[0];
			double fRec613 = fRec616;
			double fTemp159 = (fConst31 * fRec609[1]);
			fRec611[0] = ((fRec613 + fRec611[1]) - fTemp159);
			fRec609[0] = fRec611[0];
			double fRec610 = (fRec613 - fTemp159);
			fVec12[(IOTA & 1023)] = ((0.011557190300000001 * fTemp7) + (fRec580 + (fRec589 + (fRec595 + (fRec598 + fRec610)))));
			output12[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec12[((IOTA - iConst32) & 1023)])));
			double fTemp160 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec636[1]) + (fConst29 * fRec633[1])))) + (fConst28 * (((0.0459672 * fTemp40) + ((0.022412283599999999 * fTemp44) + ((0.0099555320999999992 * fTemp45) + ((0.040129537700000002 * fTemp41) + ((0.044623849700000003 * fTemp46) + ((0.063453286600000006 * fTemp47) + (0.056022944800000002 * fTemp48))))))) - ((0.0024256028000000001 * fTemp39) + ((0.0029121846000000002 * fTemp43) + ((0.0141447463 * fTemp42) + (0.0572789644 * fTemp49))))))));
			fRec638[0] = (fRec638[1] + fTemp160);
			fRec636[0] = fRec638[0];
			double fRec637 = fTemp160;
			fRec635[0] = (fRec636[0] + fRec635[1]);
			fRec633[0] = fRec635[0];
			double fRec634 = fRec637;
			double fTemp161 = (fConst23 * (0.0 - ((fConst25 * fRec630[1]) + (fConst24 * fRec627[1]))));
			fRec632[0] = (fRec634 + (fRec632[1] + fTemp161));
			fRec630[0] = fRec632[0];
			double fRec631 = (fRec634 + fTemp161);
			fRec629[0] = (fRec630[0] + fRec629[1]);
			fRec627[0] = fRec629[0];
			double fRec628 = fRec631;
			double fTemp162 = (fConst31 * fRec624[1]);
			fRec626[0] = ((fRec628 + fRec626[1]) - fTemp162);
			fRec624[0] = fRec626[0];
			double fRec625 = (fRec628 - fTemp162);
			double fTemp163 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec648[1]) + (fConst6 * fRec645[1])))) + (fConst4 * (((((((0.012343812399999999 * fTemp11) + ((0.048601047199999997 * fTemp9) + (0.0106044642 * fTemp10))) + (0.0103805129 * fTemp13)) + (0.022853022099999998 * fTemp14)) + (0.0280893384 * fTemp15)) + (0.056179233500000002 * fTemp16)) - ((0.057282213499999998 * fTemp8) + (0.064059343000000005 * fTemp12))))));
			fRec650[0] = (fRec650[1] + fTemp163);
			fRec648[0] = fRec650[0];
			double fRec649 = fTemp163;
			fRec647[0] = (fRec648[0] + fRec647[1]);
			fRec645[0] = fRec647[0];
			double fRec646 = fRec649;
			double fTemp164 = (fConst8 * (0.0 - ((fConst10 * fRec642[1]) + (fConst9 * fRec639[1]))));
			fRec644[0] = (fRec646 + (fRec644[1] + fTemp164));
			fRec642[0] = fRec644[0];
			double fRec643 = (fRec646 + fTemp164);
			fRec641[0] = (fRec642[0] + fRec641[1]);
			fRec639[0] = fRec641[0];
			double fRec640 = fRec643;
			double fTemp165 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec657[1]) + (fConst12 * fRec654[1])))) + (fConst15 * (((0.0072763469000000002 * fTemp24) + (0.035799810199999997 * fTemp25)) - (((((0.061774990199999998 * fTemp19) + (0.015679664999999999 * fTemp20)) + (0.034430659699999998 * fTemp22)) + (0.039324838700000003 * fTemp23)) + (0.051114910399999998 * fTemp21))))));
			fRec659[0] = (fRec659[1] + fTemp165);
			fRec657[0] = fRec659[0];
			double fRec658 = fTemp165;
			fRec656[0] = (fRec657[0] + fRec656[1]);
			fRec654[0] = fRec656[0];
			double fRec655 = fRec658;
			double fTemp166 = (fConst16 * fRec651[1]);
			fRec653[0] = ((fRec655 + fRec653[1]) - fTemp166);
			fRec651[0] = fRec653[0];
			double fRec652 = (fRec655 - fTemp166);
			double fTemp167 = (fConst20 * ((((0.047252739600000003 * fTemp34) + (0.014666551099999999 * fTemp35)) - (0.0080785878999999998 * fTemp36)) - (fConst21 * fRec660[1])));
			fRec662[0] = (fRec662[1] + fTemp167);
			fRec660[0] = fRec662[0];
			double fRec661 = fTemp167;
			double fTemp168 = (fConst17 * (((0.0381809964 * fTemp28) - ((0.029767677199999999 * fTemp32) + ((0.021245538299999998 * fTemp29) + ((0.0056105807999999998 * fTemp30) + (0.059271529599999997 * fTemp31))))) + (fConst5 * (0.0 - ((fConst19 * fRec666[1]) + (fConst18 * fRec663[1]))))));
			fRec668[0] = (fRec668[1] + fTemp168);
			fRec666[0] = fRec668[0];
			double fRec667 = fTemp168;
			fRec665[0] = (fRec666[0] + fRec665[1]);
			fRec663[0] = fRec665[0];
			double fRec664 = fRec667;
			fVec13[(IOTA & 1023)] = ((0.0171159819 * fTemp7) + (fRec625 + (fRec640 + (fRec652 + (fRec661 + fRec664)))));
			output13[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec13[((IOTA - iConst32) & 1023)])));
			double fTemp169 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec681[1]) + (fConst29 * fRec678[1])))) + (fConst28 * (((0.0024603912999999998 * fTemp39) + ((0.034651523199999999 * fTemp40) + ((0.0180867774 * fTemp43) + ((0.0249920197 * fTemp45) + ((0.036407499199999999 * fTemp46) + ((((0.045061212599999997 * fTemp47) + (0.013086811 * fTemp42)) + (0.0316138454 * fTemp48)) + (0.050674432200000001 * fTemp49))))))) - ((0.033751573 * fTemp41) + (0.0187072369 * fTemp44))))));
			fRec683[0] = (fRec683[1] + fTemp169);
			fRec681[0] = fRec683[0];
			double fRec682 = fTemp169;
			fRec680[0] = (fRec681[0] + fRec680[1]);
			fRec678[0] = fRec680[0];
			double fRec679 = fRec682;
			double fTemp170 = (fConst23 * (0.0 - ((fConst25 * fRec675[1]) + (fConst24 * fRec672[1]))));
			fRec677[0] = (fRec679 + (fRec677[1] + fTemp170));
			fRec675[0] = fRec677[0];
			double fRec676 = (fRec679 + fTemp170);
			fRec674[0] = (fRec675[0] + fRec674[1]);
			fRec672[0] = fRec674[0];
			double fRec673 = fRec676;
			double fTemp171 = (fConst31 * fRec669[1]);
			fRec671[0] = ((fRec673 + fRec671[1]) - fTemp171);
			fRec669[0] = fRec671[0];
			double fRec670 = (fRec673 - fTemp171);
			double fTemp172 = (fConst2 * ((fConst4 * ((((0.018907122700000001 * fTemp10) + (0.0305698116 * fTemp14)) + (0.044110852300000003 * fTemp16)) - ((((((0.041883129900000003 * fTemp9) + (0.032700924999999999 * fTemp8)) + (0.010919120799999999 * fTemp11)) + (0.041919300999999999 * fTemp12)) + (0.0084942105999999996 * fTemp13)) + (0.0230855638 * fTemp15)))) + (fConst5 * (0.0 - ((fConst7 * fRec693[1]) + (fConst6 * fRec690[1]))))));
			fRec695[0] = (fRec695[1] + fTemp172);
			fRec693[0] = fRec695[0];
			double fRec694 = fTemp172;
			fRec692[0] = (fRec693[0] + fRec692[1]);
			fRec690[0] = fRec692[0];
			double fRec691 = fRec694;
			double fTemp173 = (fConst8 * (0.0 - ((fConst10 * fRec687[1]) + (fConst9 * fRec684[1]))));
			fRec689[0] = (fRec691 + (fRec689[1] + fTemp173));
			fRec687[0] = fRec689[0];
			double fRec688 = (fRec691 + fTemp173);
			fRec686[0] = (fRec687[0] + fRec686[1]);
			fRec684[0] = fRec686[0];
			double fRec685 = fRec688;
			double fTemp174 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec702[1]) + (fConst12 * fRec699[1])))) + (fConst15 * ((0.012665306600000001 * fTemp20) - ((((((0.047073313300000003 * fTemp19) + (0.034322019199999998 * fTemp22)) + (0.0238393379 * fTemp23)) + (0.0062313291999999999 * fTemp24)) + (0.029053746200000001 * fTemp21)) + (0.030238298300000001 * fTemp25))))));
			fRec704[0] = (fRec704[1] + fTemp174);
			fRec702[0] = fRec704[0];
			double fRec703 = fTemp174;
			fRec701[0] = (fRec702[0] + fRec701[1]);
			fRec699[0] = fRec701[0];
			double fRec700 = fRec703;
			double fTemp175 = (fConst16 * fRec696[1]);
			fRec698[0] = ((fRec700 + fRec698[1]) - fTemp175);
			fRec696[0] = fRec698[0];
			double fRec697 = (fRec700 - fTemp175);
			double fTemp176 = (fConst20 * ((((0.034308696399999998 * fTemp34) + (0.0080115141000000004 * fTemp35)) + (0.0066573066999999998 * fTemp36)) - (fConst21 * fRec705[1])));
			fRec707[0] = (fRec707[1] + fTemp176);
			fRec705[0] = fRec707[0];
			double fRec706 = fTemp176;
			double fTemp177 = (fConst17 * ((((0.021377224 * fTemp28) + ((0.017682478099999999 * fTemp29) + (0.0044768500000000001 * fTemp30))) - ((0.024736782700000001 * fTemp32) + (0.044035055199999999 * fTemp31))) + (fConst5 * (0.0 - ((fConst19 * fRec711[1]) + (fConst18 * fRec708[1]))))));
			fRec713[0] = (fRec713[1] + fTemp177);
			fRec711[0] = fRec713[0];
			double fRec712 = fTemp177;
			fRec710[0] = (fRec711[0] + fRec710[1]);
			fRec708[0] = fRec710[0];
			double fRec709 = fRec712;
			fVec14[(IOTA & 1023)] = ((0.0121517424 * fTemp7) + (fRec670 + (fRec685 + (fRec697 + (fRec706 + fRec709)))));
			output14[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec14[((IOTA - iConst32) & 1023)])));
			double fTemp178 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec726[1]) + (fConst29 * fRec723[1])))) + (fConst28 * (((0.0098158008999999994 * fTemp39) + ((0.034649486299999997 * fTemp40) + ((0.014347459200000001 * fTemp43) + (((0.022653741799999998 * fTemp47) + (0.0270656365 * fTemp42)) + (0.023748579799999999 * fTemp49))))) - ((0.043269088800000001 * fTemp44) + ((0.0042941180000000004 * fTemp45) + ((0.038937321099999998 * fTemp41) + ((0.057253737800000003 * fTemp46) + (0.025357420200000001 * fTemp48)))))))));
			fRec728[0] = (fRec728[1] + fTemp178);
			fRec726[0] = fRec728[0];
			double fRec727 = fTemp178;
			fRec725[0] = (fRec726[0] + fRec725[1]);
			fRec723[0] = fRec725[0];
			double fRec724 = fRec727;
			double fTemp179 = (fConst23 * (0.0 - ((fConst25 * fRec720[1]) + (fConst24 * fRec717[1]))));
			fRec722[0] = (fRec724 + (fRec722[1] + fTemp179));
			fRec720[0] = fRec722[0];
			double fRec721 = (fRec724 + fTemp179);
			fRec719[0] = (fRec720[0] + fRec719[1]);
			fRec717[0] = fRec719[0];
			double fRec718 = fRec721;
			double fTemp180 = (fConst31 * fRec714[1]);
			fRec716[0] = ((fRec718 + fRec716[1]) - fTemp180);
			fRec714[0] = fRec716[0];
			double fRec715 = (fRec718 - fTemp180);
			double fTemp181 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec738[1]) + (fConst6 * fRec735[1])))) + (fConst4 * ((((0.0015782287999999999 * fTemp8) + (0.018392151299999999 * fTemp10)) + (0.013484738099999999 * fTemp14)) - ((((((0.048878875799999999 * fTemp9) + (0.028767154199999999 * fTemp11)) + (0.036735531299999999 * fTemp12)) + (0.022086621899999999 * fTemp13)) + (0.040181063599999997 * fTemp15)) + (0.035422290500000002 * fTemp16))))));
			fRec740[0] = (fRec740[1] + fTemp181);
			fRec738[0] = fRec740[0];
			double fRec739 = fTemp181;
			fRec737[0] = (fRec738[0] + fRec737[1]);
			fRec735[0] = fRec737[0];
			double fRec736 = fRec739;
			double fTemp182 = (fConst8 * (0.0 - ((fConst10 * fRec732[1]) + (fConst9 * fRec729[1]))));
			fRec734[0] = (fRec736 + (fRec734[1] + fTemp182));
			fRec732[0] = fRec734[0];
			double fRec733 = (fRec736 + fTemp182);
			fRec731[0] = (fRec732[0] + fRec731[1]);
			fRec729[0] = fRec731[0];
			double fRec730 = fRec733;
			double fTemp183 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec747[1]) + (fConst12 * fRec744[1])))) + (fConst15 * (((0.0042459413000000001 * fTemp19) + (0.027964285799999999 * fTemp20)) - (((((0.0291018254 * fTemp22) + (0.023920673699999999 * fTemp23)) + (0.018201339800000001 * fTemp24)) + (0.0152251735 * fTemp21)) + (0.055332038200000003 * fTemp25))))));
			fRec749[0] = (fRec749[1] + fTemp183);
			fRec747[0] = fRec749[0];
			double fRec748 = fTemp183;
			fRec746[0] = (fRec747[0] + fRec746[1]);
			fRec744[0] = fRec746[0];
			double fRec745 = fRec748;
			double fTemp184 = (fConst16 * fRec741[1]);
			fRec743[0] = ((fRec745 + fRec743[1]) - fTemp184);
			fRec741[0] = fRec743[0];
			double fRec742 = (fRec745 - fTemp184);
			double fTemp185 = (fConst20 * ((((0.029590851899999999 * fTemp34) + (0.0080539393999999997 * fTemp35)) + (0.0180607804 * fTemp36)) - (fConst21 * fRec750[1])));
			fRec752[0] = (fRec752[1] + fTemp185);
			fRec750[0] = fRec752[0];
			double fRec751 = fTemp185;
			double fTemp186 = (fConst17 * ((((0.018876828599999999 * fTemp28) + ((0.0418831286 * fTemp29) + (0.0111949218 * fTemp30))) - ((0.024445595000000001 * fTemp32) + (0.0214613175 * fTemp31))) + (fConst5 * (0.0 - ((fConst19 * fRec756[1]) + (fConst18 * fRec753[1]))))));
			fRec758[0] = (fRec758[1] + fTemp186);
			fRec756[0] = fRec758[0];
			double fRec757 = fTemp186;
			fRec755[0] = (fRec756[0] + fRec755[1]);
			fRec753[0] = fRec755[0];
			double fRec754 = fRec757;
			fVec15[(IOTA & 1023)] = ((0.012059740100000001 * fTemp7) + (fRec715 + (fRec730 + (fRec742 + (fRec751 + fRec754)))));
			output15[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec15[((IOTA - iConst32) & 1023)])));
			double fTemp187 = (fConst33 * ((fConst5 * (0.0 - ((fConst35 * fRec771[1]) + (fConst34 * fRec768[1])))) + (fConst38 * (((0.0226578448 * fTemp44) + ((0.095884877199999996 * fTemp45) + ((0.078122615300000003 * fTemp41) + ((0.026665955700000001 * fTemp46) + ((((0.041414022600000003 * fTemp47) + (0.064542356699999998 * fTemp42)) + (0.023019951 * fTemp48)) + (0.0011971447000000001 * fTemp49)))))) - (((0.033528091400000001 * fTemp43) + (0.048555427700000001 * fTemp40)) + (0.072624234900000001 * fTemp39))))));
			fRec773[0] = (fRec773[1] + fTemp187);
			fRec771[0] = fRec773[0];
			double fRec772 = fTemp187;
			fRec770[0] = (fRec771[0] + fRec770[1]);
			fRec768[0] = fRec770[0];
			double fRec769 = fRec772;
			double fTemp188 = (fConst39 * (0.0 - ((fConst41 * fRec765[1]) + (fConst40 * fRec762[1]))));
			fRec767[0] = (fRec769 + (fRec767[1] + fTemp188));
			fRec765[0] = fRec767[0];
			double fRec766 = (fRec769 + fTemp188);
			fRec764[0] = (fRec765[0] + fRec764[1]);
			fRec762[0] = fRec764[0];
			double fRec763 = fRec766;
			double fTemp189 = (fConst42 * fRec759[1]);
			fRec761[0] = ((fRec763 + fRec761[1]) - fTemp189);
			fRec759[0] = fRec761[0];
			double fRec760 = (fRec763 - fTemp189);
			double fTemp190 = (fConst43 * ((fConst5 * (0.0 - ((fConst45 * fRec783[1]) + (fConst44 * fRec780[1])))) + (fConst47 * ((((((((0.042564237999999997 * fTemp9) + (0.0960019872 * fTemp8)) + (0.075839598100000002 * fTemp11)) + (0.00056197340000000004 * fTemp13)) + (0.1038907615 * fTemp14)) + (0.065973801600000007 * fTemp15)) + (0.0138388486 * fTemp16)) - ((0.0059110682999999999 * fTemp12) + (0.087146714299999997 * fTemp10))))));
			fRec785[0] = (fRec785[1] + fTemp190);
			fRec783[0] = fRec785[0];
			double fRec784 = fTemp190;
			fRec782[0] = (fRec783[0] + fRec782[1]);
			fRec780[0] = fRec782[0];
			double fRec781 = fRec784;
			double fTemp191 = (fConst48 * (0.0 - ((fConst50 * fRec777[1]) + (fConst49 * fRec774[1]))));
			fRec779[0] = (fRec781 + (fRec779[1] + fTemp191));
			fRec777[0] = fRec779[0];
			double fRec778 = (fRec781 + fTemp191);
			fRec776[0] = (fRec777[0] + fRec776[1]);
			fRec774[0] = fRec776[0];
			double fRec775 = fRec778;
			double fTemp192 = (fConst51 * ((fConst5 * (0.0 - ((fConst53 * fRec792[1]) + (fConst52 * fRec789[1])))) + (fConst55 * (((((((0.052728591999999998 * fTemp19) + (0.084716863700000006 * fTemp20)) + (0.030580698699999999 * fTemp22)) + (0.1007985804 * fTemp24)) + (0.1137285452 * fTemp21)) + (0.037237809500000003 * fTemp25)) - (0.0553800916 * fTemp23)))));
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
			double fTemp194 = (fConst57 * ((((0.025836954200000001 * fTemp34) + (0.073090759300000002 * fTemp35)) + (0.079096781300000002 * fTemp36)) - (fConst58 * fRec795[1])));
			fRec797[0] = (fRec797[1] + fTemp194);
			fRec795[0] = fRec797[0];
			double fRec796 = fTemp194;
			double fTemp195 = (fConst59 * (((0.024724205799999999 * fTemp32) + ((0.043858782300000003 * fTemp28) + ((0.048024604899999997 * fTemp29) + ((0.13566151609999999 * fTemp30) + (0.06470592 * fTemp31))))) + (fConst5 * (0.0 - ((fConst61 * fRec801[1]) + (fConst60 * fRec798[1]))))));
			fRec803[0] = (fRec803[1] + fTemp195);
			fRec801[0] = fRec803[0];
			double fRec802 = fTemp195;
			fRec800[0] = (fRec801[0] + fRec800[1]);
			fRec798[0] = fRec800[0];
			double fRec799 = fRec802;
			fVec16[(IOTA & 511)] = ((0.038935900400000001 * fTemp7) + (fRec760 + (fRec775 + (fRec787 + (fRec796 + fRec799)))));
			output16[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec16[((IOTA - iConst62) & 511)])));
			double fTemp196 = (fConst33 * ((fConst5 * (0.0 - ((fConst35 * fRec816[1]) + (fConst34 * fRec813[1])))) + (fConst38 * (((0.042812562899999997 * fTemp43) + ((0.012751115800000001 * fTemp47) + (0.024489988800000001 * fTemp42))) - ((0.091689767800000002 * fTemp39) + ((0.030345832199999999 * fTemp40) + ((0.011432948599999999 * fTemp44) + ((0.1032633504 * fTemp45) + ((0.079192042300000001 * fTemp41) + ((0.0185183781 * fTemp46) + ((0.0235490306 * fTemp48) + (0.020789076900000002 * fTemp49))))))))))));
			fRec818[0] = (fRec818[1] + fTemp196);
			fRec816[0] = fRec818[0];
			double fRec817 = fTemp196;
			fRec815[0] = (fRec816[0] + fRec815[1]);
			fRec813[0] = fRec815[0];
			double fRec814 = fRec817;
			double fTemp197 = (fConst39 * (0.0 - ((fConst41 * fRec810[1]) + (fConst40 * fRec807[1]))));
			fRec812[0] = (fRec814 + (fRec812[1] + fTemp197));
			fRec810[0] = fRec812[0];
			double fRec811 = (fRec814 + fTemp197);
			fRec809[0] = (fRec810[0] + fRec809[1]);
			fRec807[0] = fRec809[0];
			double fRec808 = fRec811;
			double fTemp198 = (fConst42 * fRec804[1]);
			fRec806[0] = ((fRec808 + fRec806[1]) - fTemp198);
			fRec804[0] = fRec806[0];
			double fRec805 = (fRec808 - fTemp198);
			double fTemp199 = (fConst43 * ((fConst47 * ((((0.015789418 * fTemp12) + (0.066025565499999994 * fTemp14)) + (0.021242065899999999 * fTemp15)) - ((((0.081007449400000001 * fTemp11) + ((0.109361915 * fTemp8) + ((0.042846748099999998 * fTemp9) + (0.081995681700000003 * fTemp10)))) + (0.030705756300000001 * fTemp13)) + (0.0144473742 * fTemp16)))) + (fConst5 * (0.0 - ((fConst45 * fRec828[1]) + (fConst44 * fRec825[1]))))));
			fRec830[0] = (fRec830[1] + fTemp199);
			fRec828[0] = fRec830[0];
			double fRec829 = fTemp199;
			fRec827[0] = (fRec828[0] + fRec827[1]);
			fRec825[0] = fRec827[0];
			double fRec826 = fRec829;
			double fTemp200 = (fConst48 * (0.0 - ((fConst50 * fRec822[1]) + (fConst49 * fRec819[1]))));
			fRec824[0] = (fRec826 + (fRec824[1] + fTemp200));
			fRec822[0] = fRec824[0];
			double fRec823 = (fRec826 + fTemp200);
			fRec821[0] = (fRec822[0] + fRec821[1]);
			fRec819[0] = fRec821[0];
			double fRec820 = fRec823;
			double fTemp201 = (fConst51 * ((fConst5 * (0.0 - ((fConst53 * fRec837[1]) + (fConst52 * fRec834[1])))) + (fConst55 * ((((0.064936305 * fTemp24) + (0.077726390199999995 * fTemp21)) + (0.0104764496 * fTemp25)) - ((((0.0618418835 * fTemp19) + (0.10055832200000001 * fTemp20)) + (0.030644154900000001 * fTemp22)) + (0.064544753600000004 * fTemp23))))));
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
			double fTemp203 = (fConst57 * ((((0.05629634 * fTemp35) + (0.065478709499999996 * fTemp36)) - (0.0324570478 * fTemp34)) - (fConst58 * fRec840[1])));
			fRec842[0] = (fRec842[1] + fTemp203);
			fRec840[0] = fRec842[0];
			double fRec841 = fTemp203;
			double fTemp204 = (fConst59 * ((((0.0068646756 * fTemp32) + ((0.106752281 * fTemp30) + (0.044906605400000001 * fTemp31))) - ((0.059746908199999997 * fTemp29) + (0.052208464599999997 * fTemp28))) + (fConst5 * (0.0 - ((fConst61 * fRec846[1]) + (fConst60 * fRec843[1]))))));
			fRec848[0] = (fRec848[1] + fTemp204);
			fRec846[0] = fRec848[0];
			double fRec847 = fTemp204;
			fRec845[0] = (fRec846[0] + fRec845[1]);
			fRec843[0] = fRec845[0];
			double fRec844 = fRec847;
			fVec17[(IOTA & 511)] = ((0.032144031000000003 * fTemp7) + (fRec805 + (fRec820 + (fRec832 + (fRec841 + fRec844)))));
			output17[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec17[((IOTA - iConst62) & 511)])));
			double fTemp205 = (fConst59 * ((((0.024915884999999999 * fTemp32) + (0.0412290404 * fTemp30)) - ((0.13854293819999999 * fTemp28) + ((0.045399850700000001 * fTemp29) + (0.067569511299999996 * fTemp31)))) + (fConst5 * (0.0 - ((fConst61 * fRec852[1]) + (fConst60 * fRec849[1]))))));
			fRec854[0] = (fRec854[1] + fTemp205);
			fRec852[0] = fRec854[0];
			double fRec853 = fTemp205;
			fRec851[0] = (fRec852[0] + fRec851[1]);
			fRec849[0] = fRec851[0];
			double fRec850 = fRec853;
			double fTemp206 = (fConst57 * ((((0.074133703999999995 * fTemp35) + (0.024320272399999999 * fTemp36)) - (0.080813680799999996 * fTemp34)) - (fConst58 * fRec855[1])));
			fRec857[0] = (fRec857[1] + fTemp206);
			fRec855[0] = fRec857[0];
			double fRec856 = fTemp206;
			double fTemp207 = (fConst43 * ((fConst5 * (0.0 - ((fConst45 * fRec867[1]) + (fConst44 * fRec864[1])))) + (fConst47 * (((((0.040728214200000001 * fTemp9) + (0.072722887799999997 * fTemp8)) + (5.4000599999999999e-05 * fTemp12)) + (0.0173942952 * fTemp16)) - (((((0.071375065200000004 * fTemp11) + (0.088717705600000002 * fTemp10)) + (0.0058092884999999999 * fTemp13)) + (0.1083702305 * fTemp14)) + (0.091201045499999994 * fTemp15))))));
			fRec869[0] = (fRec869[1] + fTemp207);
			fRec867[0] = fRec869[0];
			double fRec868 = fTemp207;
			fRec866[0] = (fRec867[0] + fRec866[1]);
			fRec864[0] = fRec866[0];
			double fRec865 = fRec868;
			double fTemp208 = (fConst48 * (0.0 - ((fConst50 * fRec861[1]) + (fConst49 * fRec858[1]))));
			fRec863[0] = (fRec865 + (fRec863[1] + fTemp208));
			fRec861[0] = fRec863[0];
			double fRec862 = (fRec865 + fTemp208);
			fRec860[0] = (fRec861[0] + fRec860[1]);
			fRec858[0] = fRec860[0];
			double fRec859 = fRec862;
			double fTemp209 = (fConst51 * ((fConst5 * (0.0 - ((fConst53 * fRec876[1]) + (fConst52 * fRec873[1])))) + (fConst55 * (((0.040892376500000001 * fTemp19) + (0.028616354 * fTemp24)) - (((((0.079987332699999997 * fTemp20) + (0.10271072790000001 * fTemp22)) + (0.056507688200000003 * fTemp23)) + (0.1187872858 * fTemp21)) + (0.050146726699999998 * fTemp25))))));
			fRec878[0] = (fRec878[1] + fTemp209);
			fRec876[0] = fRec878[0];
			double fRec877 = fTemp209;
			fRec875[0] = (fRec876[0] + fRec875[1]);
			fRec873[0] = fRec875[0];
			double fRec874 = fRec877;
			double fTemp210 = (fConst56 * fRec870[1]);
			fRec872[0] = ((fRec874 + fRec872[1]) - fTemp210);
			fRec870[0] = fRec872[0];
			double fRec871 = (fRec874 - fTemp210);
			double fTemp211 = (fConst33 * ((fConst5 * (0.0 - ((fConst35 * fRec891[1]) + (fConst34 * fRec888[1])))) + (fConst38 * (((0.075107450100000001 * fTemp43) + ((0.071370817500000003 * fTemp45) + ((0.074672500599999997 * fTemp41) + ((0.029728628900000002 * fTemp48) + (0.025541375799999998 * fTemp49))))) - ((0.031736644799999998 * fTemp39) + ((0.0493060866 * fTemp40) + ((0.020887213500000001 * fTemp44) + ((0.0038786782000000001 * fTemp46) + ((0.042527390499999998 * fTemp47) + (0.090838211000000002 * fTemp42))))))))));
			fRec893[0] = (fRec893[1] + fTemp211);
			fRec891[0] = fRec893[0];
			double fRec892 = fTemp211;
			fRec890[0] = (fRec891[0] + fRec890[1]);
			fRec888[0] = fRec890[0];
			double fRec889 = fRec892;
			double fTemp212 = (fConst39 * (0.0 - ((fConst41 * fRec885[1]) + (fConst40 * fRec882[1]))));
			fRec887[0] = (fRec889 + (fRec887[1] + fTemp212));
			fRec885[0] = fRec887[0];
			double fRec886 = (fRec889 + fTemp212);
			fRec884[0] = (fRec885[0] + fRec884[1]);
			fRec882[0] = fRec884[0];
			double fRec883 = fRec886;
			double fTemp213 = (fConst42 * fRec879[1]);
			fRec881[0] = ((fRec883 + fRec881[1]) - fTemp213);
			fRec879[0] = fRec881[0];
			double fRec880 = (fRec883 - fTemp213);
			fVec18[(IOTA & 511)] = ((0.0395166583 * fTemp7) + (fRec850 + (fRec856 + (fRec859 + (fRec871 + fRec880)))));
			output18[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec18[((IOTA - iConst62) & 511)])));
			double fTemp214 = (fConst51 * ((fConst5 * (0.0 - ((fConst53 * fRec900[1]) + (fConst52 * fRec897[1])))) + (fConst55 * ((((0.0057115324999999998 * fTemp19) + (0.1033305972 * fTemp20)) + (0.062514519199999993 * fTemp25)) - ((((0.062919267599999995 * fTemp22) + (0.064254195 * fTemp23)) + (0.0310701998 * fTemp24)) + (0.072436876799999994 * fTemp21))))));
			fRec902[0] = (fRec902[1] + fTemp214);
			fRec900[0] = fRec902[0];
			double fRec901 = fTemp214;
			fRec899[0] = (fRec900[0] + fRec899[1]);
			fRec897[0] = fRec899[0];
			double fRec898 = fRec901;
			double fTemp215 = (fConst56 * fRec894[1]);
			fRec896[0] = ((fRec898 + fRec896[1]) - fTemp215);
			fRec894[0] = fRec896[0];
			double fRec895 = (fRec898 - fTemp215);
			double fTemp216 = (fConst33 * ((fConst5 * (0.0 - ((fConst35 * fRec915[1]) + (fConst34 * fRec912[1])))) + (fConst38 * (((0.044779442099999997 * fTemp39) + ((0.090016403199999998 * fTemp43) + ((0.0103375189 * fTemp44) + ((0.017543044000000001 * fTemp45) + ((0.0236313098 * fTemp46) + (0.10436145030000001 * fTemp42)))))) - ((0.028910017100000001 * fTemp40) + ((0.076963397200000006 * fTemp41) + (((0.0123781624 * fTemp47) + (0.031948715400000001 * fTemp48)) + (0.015573327499999999 * fTemp49))))))));
			fRec917[0] = (fRec917[1] + fTemp216);
			fRec915[0] = fRec917[0];
			double fRec916 = fTemp216;
			fRec914[0] = (fRec915[0] + fRec914[1]);
			fRec912[0] = fRec914[0];
			double fRec913 = fRec916;
			double fTemp217 = (fConst39 * (0.0 - ((fConst41 * fRec909[1]) + (fConst40 * fRec906[1]))));
			fRec911[0] = (fRec913 + (fRec911[1] + fTemp217));
			fRec909[0] = fRec911[0];
			double fRec910 = (fRec913 + fTemp217);
			fRec908[0] = (fRec909[0] + fRec908[1]);
			fRec906[0] = fRec908[0];
			double fRec907 = fRec910;
			double fTemp218 = (fConst42 * fRec903[1]);
			fRec905[0] = ((fRec907 + fRec905[1]) - fTemp218);
			fRec903[0] = fRec905[0];
			double fRec904 = (fRec907 - fTemp218);
			double fTemp219 = (fConst43 * ((fConst5 * (0.0 - ((fConst45 * fRec927[1]) + (fConst44 * fRec924[1])))) + (fConst47 * ((((((0.013146886999999999 * fTemp8) + (0.082527814300000002 * fTemp11)) + (0.0308654028 * fTemp12)) + (0.0173005525 * fTemp13)) + (0.1105747111 * fTemp15)) - ((((0.041355823299999997 * fTemp9) + (0.080754876399999995 * fTemp10)) + (0.061873372199999999 * fTemp14)) + (0.019124743100000001 * fTemp16))))));
			fRec929[0] = (fRec929[1] + fTemp219);
			fRec927[0] = fRec929[0];
			double fRec928 = fTemp219;
			fRec926[0] = (fRec927[0] + fRec926[1]);
			fRec924[0] = fRec926[0];
			double fRec925 = fRec928;
			double fTemp220 = (fConst48 * (0.0 - ((fConst50 * fRec921[1]) + (fConst49 * fRec918[1]))));
			fRec923[0] = (fRec925 + (fRec923[1] + fTemp220));
			fRec921[0] = fRec923[0];
			double fRec922 = (fRec925 + fTemp220);
			fRec920[0] = (fRec921[0] + fRec920[1]);
			fRec918[0] = fRec920[0];
			double fRec919 = fRec922;
			double fTemp221 = (fConst57 * (((0.0554719974 * fTemp35) - ((0.064131318399999998 * fTemp34) + (0.033694832799999998 * fTemp36))) - (fConst58 * fRec930[1])));
			fRec932[0] = (fRec932[1] + fTemp221);
			fRec930[0] = fRec932[0];
			double fRec931 = fTemp221;
			double fTemp222 = (fConst59 * ((((0.061587189200000003 * fTemp29) + (0.0062667456999999996 * fTemp32)) - ((0.10430949270000001 * fTemp28) + ((0.053937413900000002 * fTemp30) + (0.041737140800000003 * fTemp31)))) + (fConst5 * (0.0 - ((fConst61 * fRec936[1]) + (fConst60 * fRec933[1]))))));
			fRec938[0] = (fRec938[1] + fTemp222);
			fRec936[0] = fRec938[0];
			double fRec937 = fTemp222;
			fRec935[0] = (fRec936[0] + fRec935[1]);
			fRec933[0] = fRec935[0];
			double fRec934 = fRec937;
			fVec19[(IOTA & 511)] = ((0.031777949200000002 * fTemp7) + (fRec895 + (fRec904 + (fRec919 + (fRec931 + fRec934)))));
			output19[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec19[((IOTA - iConst62) & 511)])));
			double fTemp223 = (fConst33 * ((fConst5 * (0.0 - ((fConst35 * fRec951[1]) + (fConst34 * fRec948[1])))) + (fConst38 * (((0.058576265500000002 * fTemp39) + ((0.030247809399999999 * fTemp43) + ((0.022067185999999999 * fTemp44) + ((0.080333374099999993 * fTemp41) + (((0.053966902300000001 * fTemp47) + (0.0123988413 * fTemp48)) + (0.0079689753999999998 * fTemp49)))))) - ((0.053731983400000002 * fTemp40) + ((0.093660473600000002 * fTemp45) + ((0.0295269064 * fTemp46) + (0.063732538699999994 * fTemp42))))))));
			fRec953[0] = (fRec953[1] + fTemp223);
			fRec951[0] = fRec953[0];
			double fRec952 = fTemp223;
			fRec950[0] = (fRec951[0] + fRec950[1]);
			fRec948[0] = fRec950[0];
			double fRec949 = fRec952;
			double fTemp224 = (fConst39 * (0.0 - ((fConst41 * fRec945[1]) + (fConst40 * fRec942[1]))));
			fRec947[0] = (fRec949 + (fRec947[1] + fTemp224));
			fRec945[0] = fRec947[0];
			double fRec946 = (fRec949 + fTemp224);
			fRec944[0] = (fRec945[0] + fRec944[1]);
			fRec942[0] = fRec944[0];
			double fRec943 = fRec946;
			double fTemp225 = (fConst42 * fRec939[1]);
			fRec941[0] = ((fRec943 + fRec941[1]) - fTemp225);
			fRec939[0] = fRec941[0];
			double fRec940 = (fRec943 - fTemp225);
			double fTemp226 = (fConst43 * ((fConst5 * (0.0 - ((fConst45 * fRec963[1]) + (fConst44 * fRec960[1])))) + (fConst47 * ((((((0.043153848299999999 * fTemp9) + (0.071003269899999999 * fTemp11)) + (0.0048909403000000004 * fTemp12)) + (0.10152010960000001 * fTemp14)) + (0.0055458327000000003 * fTemp16)) - ((((0.092593774300000001 * fTemp8) + (0.078952410200000003 * fTemp10)) + (0.0149702233 * fTemp13)) + (0.055213435399999997 * fTemp15))))));
			fRec965[0] = (fRec965[1] + fTemp226);
			fRec963[0] = fRec965[0];
			double fRec964 = fTemp226;
			fRec962[0] = (fRec963[0] + fRec962[1]);
			fRec960[0] = fRec962[0];
			double fRec961 = fRec964;
			double fTemp227 = (fConst48 * (0.0 - ((fConst50 * fRec957[1]) + (fConst49 * fRec954[1]))));
			fRec959[0] = (fRec961 + (fRec959[1] + fTemp227));
			fRec957[0] = fRec959[0];
			double fRec958 = (fRec961 + fTemp227);
			fRec956[0] = (fRec957[0] + fRec956[1]);
			fRec954[0] = fRec956[0];
			double fRec955 = fRec958;
			double fTemp228 = (fConst51 * ((fConst5 * (0.0 - ((fConst53 * fRec972[1]) + (fConst52 * fRec969[1])))) + (fConst55 * (((0.078561127300000005 * fTemp20) + (0.1002470553 * fTemp21)) - (((((0.050464711199999998 * fTemp19) + (0.028088053599999999 * fTemp22)) + (0.043082171400000001 * fTemp23)) + (0.099162839000000003 * fTemp24)) + (0.028347151099999999 * fTemp25))))));
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
			double fTemp230 = (fConst57 * (((0.066152378100000006 * fTemp35) - ((0.023376955599999999 * fTemp34) + (0.067989926899999997 * fTemp36))) - (fConst58 * fRec975[1])));
			fRec977[0] = (fRec977[1] + fTemp230);
			fRec975[0] = fRec977[0];
			double fRec976 = fTemp230;
			double fTemp231 = (fConst59 * ((((0.027660248200000001 * fTemp32) + ((0.044313878199999997 * fTemp29) + (0.054060242600000002 * fTemp31))) - ((0.039839455099999997 * fTemp28) + (0.1211456865 * fTemp30))) + (fConst5 * (0.0 - ((fConst61 * fRec981[1]) + (fConst60 * fRec978[1]))))));
			fRec983[0] = (fRec983[1] + fTemp231);
			fRec981[0] = fRec983[0];
			double fRec982 = fTemp231;
			fRec980[0] = (fRec981[0] + fRec980[1]);
			fRec978[0] = fRec980[0];
			double fRec979 = fRec982;
			fVec20[(IOTA & 511)] = ((0.0341328459 * fTemp7) + (fRec940 + (fRec955 + (fRec967 + (fRec976 + fRec979)))));
			output20[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec20[((IOTA - iConst62) & 511)])));
			double fTemp232 = (fConst33 * ((fConst5 * (0.0 - ((fConst35 * fRec996[1]) + (fConst34 * fRec993[1])))) + (fConst38 * (((0.091860116300000003 * fTemp39) + ((0.096179947000000002 * fTemp45) + ((0.0292749671 * fTemp46) + ((0.0002205725 * fTemp47) + (0.016353283400000002 * fTemp48))))) - ((0.027572460199999999 * fTemp40) + ((0.032190859099999997 * fTemp43) + ((0.021595633999999999 * fTemp44) + ((0.081845828699999998 * fTemp41) + ((0.040390552000000003 * fTemp42) + (0.00013763290000000001 * fTemp49))))))))));
			fRec998[0] = (fRec998[1] + fTemp232);
			fRec996[0] = fRec998[0];
			double fRec997 = fTemp232;
			fRec995[0] = (fRec996[0] + fRec995[1]);
			fRec993[0] = fRec995[0];
			double fRec994 = fRec997;
			double fTemp233 = (fConst39 * (0.0 - ((fConst41 * fRec990[1]) + (fConst40 * fRec987[1]))));
			fRec992[0] = (fRec994 + (fRec992[1] + fTemp233));
			fRec990[0] = fRec992[0];
			double fRec991 = (fRec994 + fTemp233);
			fRec989[0] = (fRec990[0] + fRec989[1]);
			fRec987[0] = fRec989[0];
			double fRec988 = fRec991;
			double fTemp234 = (fConst42 * fRec984[1]);
			fRec986[0] = ((fRec988 + fRec986[1]) - fTemp234);
			fRec984[0] = fRec986[0];
			double fRec985 = (fRec988 - fTemp234);
			double fTemp235 = (fConst43 * ((fConst5 * (0.0 - ((fConst45 * fRec1008[1]) + (fConst44 * fRec1005[1])))) + (fConst47 * (((((0.095628860400000001 * fTemp8) + (0.034675787899999998 * fTemp13)) + (0.068887864899999998 * fTemp14)) + (0.0120505132 * fTemp16)) - (((0.0059923405000000003 * fTemp12) + ((0.073031964300000002 * fTemp11) + ((0.044060430599999999 * fTemp9) + (0.077783141200000003 * fTemp10)))) + (0.053266278299999997 * fTemp15))))));
			fRec1010[0] = (fRec1010[1] + fTemp235);
			fRec1008[0] = fRec1010[0];
			double fRec1009 = fTemp235;
			fRec1007[0] = (fRec1008[0] + fRec1007[1]);
			fRec1005[0] = fRec1007[0];
			double fRec1006 = fRec1009;
			double fTemp236 = (fConst48 * (0.0 - ((fConst50 * fRec1002[1]) + (fConst49 * fRec999[1]))));
			fRec1004[0] = (fRec1006 + (fRec1004[1] + fTemp236));
			fRec1002[0] = fRec1004[0];
			double fRec1003 = (fRec1006 + fTemp236);
			fRec1001[0] = (fRec1002[0] + fRec1001[1]);
			fRec999[0] = fRec1001[0];
			double fRec1000 = fRec1003;
			double fTemp237 = (fConst51 * ((fConst5 * (0.0 - ((fConst53 * fRec1017[1]) + (fConst52 * fRec1014[1])))) + (fConst55 * ((((0.052324425000000001 * fTemp19) + (0.028697261599999999 * fTemp22)) + (0.091584235299999997 * fTemp21)) - ((((0.081633108699999998 * fTemp20) + (0.062078777100000003 * fTemp23)) + (0.061396727300000002 * fTemp24)) + (0.032827189800000003 * fTemp25))))));
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
			double fTemp239 = (fConst57 * ((((0.0244521496 * fTemp34) + (0.053525703899999999 * fTemp35)) - (0.065684384400000004 * fTemp36)) - (fConst58 * fRec1020[1])));
			fRec1022[0] = (fRec1022[1] + fTemp239);
			fRec1020[0] = fRec1022[0];
			double fRec1021 = fTemp239;
			double fTemp240 = (fConst59 * ((((0.0059497676000000001 * fTemp32) + ((0.041430062199999999 * fTemp28) + (0.055674328000000002 * fTemp31))) - ((0.046279424700000002 * fTemp29) + (0.10567978259999999 * fTemp30))) + (fConst5 * (0.0 - ((fConst61 * fRec1026[1]) + (fConst60 * fRec1023[1]))))));
			fRec1028[0] = (fRec1028[1] + fTemp240);
			fRec1026[0] = fRec1028[0];
			double fRec1027 = fTemp240;
			fRec1025[0] = (fRec1026[0] + fRec1025[1]);
			fRec1023[0] = fRec1025[0];
			double fRec1024 = fRec1027;
			fVec21[(IOTA & 511)] = ((0.030686754 * fTemp7) + (fRec985 + (fRec1000 + (fRec1012 + (fRec1021 + fRec1024)))));
			output21[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec21[((IOTA - iConst62) & 511)])));
			double fTemp241 = (fConst33 * ((fConst5 * (0.0 - ((fConst35 * fRec1041[1]) + (fConst34 * fRec1038[1])))) + (fConst38 * (((0.043444557699999997 * fTemp39) + ((0.077848111900000003 * fTemp41) + (0.1037341853 * fTemp42))) - ((0.030713114199999999 * fTemp40) + ((0.089704091700000002 * fTemp43) + ((0.0117935921 * fTemp44) + ((0.020480586200000001 * fTemp45) + ((0.023230636999999998 * fTemp46) + (((0.0134573261 * fTemp47) + (0.028781882000000002 * fTemp48)) + (0.016929549700000001 * fTemp49)))))))))));
			fRec1043[0] = (fRec1043[1] + fTemp241);
			fRec1041[0] = fRec1043[0];
			double fRec1042 = fTemp241;
			fRec1040[0] = (fRec1041[0] + fRec1040[1]);
			fRec1038[0] = fRec1040[0];
			double fRec1039 = fRec1042;
			double fTemp242 = (fConst39 * (0.0 - ((fConst41 * fRec1035[1]) + (fConst40 * fRec1032[1]))));
			fRec1037[0] = (fRec1039 + (fRec1037[1] + fTemp242));
			fRec1035[0] = fRec1037[0];
			double fRec1036 = (fRec1039 + fTemp242);
			fRec1034[0] = (fRec1035[0] + fRec1034[1]);
			fRec1032[0] = fRec1034[0];
			double fRec1033 = fRec1036;
			double fTemp243 = (fConst42 * fRec1029[1]);
			fRec1031[0] = ((fRec1033 + fRec1031[1]) - fTemp243);
			fRec1029[0] = fRec1031[0];
			double fRec1030 = (fRec1033 - fTemp243);
			double fTemp244 = (fConst43 * ((fConst5 * (0.0 - ((fConst45 * fRec1053[1]) + (fConst44 * fRec1050[1])))) + (fConst47 * ((((0.0419299437 * fTemp9) + (0.015903693 * fTemp13)) + (0.1093853518 * fTemp15)) - ((((0.0292068235 * fTemp12) + ((0.081849991799999994 * fTemp11) + ((0.016342566699999998 * fTemp8) + (0.080995262100000007 * fTemp10)))) + (0.063707556700000001 * fTemp14)) + (0.0174119935 * fTemp16))))));
			fRec1055[0] = (fRec1055[1] + fTemp244);
			fRec1053[0] = fRec1055[0];
			double fRec1054 = fTemp244;
			fRec1052[0] = (fRec1053[0] + fRec1052[1]);
			fRec1050[0] = fRec1052[0];
			double fRec1051 = fRec1054;
			double fTemp245 = (fConst48 * (0.0 - ((fConst50 * fRec1047[1]) + (fConst49 * fRec1044[1]))));
			fRec1049[0] = (fRec1051 + (fRec1049[1] + fTemp245));
			fRec1047[0] = fRec1049[0];
			double fRec1048 = (fRec1051 + fTemp245);
			fRec1046[0] = (fRec1047[0] + fRec1046[1]);
			fRec1044[0] = fRec1046[0];
			double fRec1045 = fRec1048;
			double fTemp246 = (fConst51 * ((fConst55 * (((0.064181007999999998 * fTemp22) + (0.0617000074 * fTemp25)) - (((((0.0075418294999999996 * fTemp19) + (0.1012831045 * fTemp20)) + (0.063233559100000003 * fTemp23)) + (0.031045277100000001 * fTemp24)) + (0.074057640600000002 * fTemp21)))) + (fConst5 * (0.0 - ((fConst53 * fRec1062[1]) + (fConst52 * fRec1059[1]))))));
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
			double fTemp248 = (fConst57 * ((((0.063903487199999998 * fTemp34) + (0.055444317600000001 * fTemp35)) - (0.0327476721 * fTemp36)) - (fConst58 * fRec1065[1])));
			fRec1067[0] = (fRec1067[1] + fTemp248);
			fRec1065[0] = fRec1067[0];
			double fRec1066 = fTemp248;
			double fTemp249 = (fConst59 * ((((0.1044964968 * fTemp28) + (0.0070786338000000002 * fTemp32)) - ((0.060076910499999997 * fTemp29) + ((0.052737310599999997 * fTemp30) + (0.042538739999999998 * fTemp31)))) + (fConst5 * (0.0 - ((fConst61 * fRec1071[1]) + (fConst60 * fRec1068[1]))))));
			fRec1073[0] = (fRec1073[1] + fTemp249);
			fRec1071[0] = fRec1073[0];
			double fRec1072 = fTemp249;
			fRec1070[0] = (fRec1071[0] + fRec1070[1]);
			fRec1068[0] = fRec1070[0];
			double fRec1069 = fRec1072;
			fVec22[(IOTA & 511)] = ((0.031584639900000003 * fTemp7) + (fRec1030 + (fRec1045 + (fRec1057 + (fRec1066 + fRec1069)))));
			output22[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec22[((IOTA - iConst62) & 511)])));
			double fTemp250 = (fConst43 * ((fConst5 * (0.0 - ((fConst45 * fRec1083[1]) + (fConst44 * fRec1080[1])))) + (fConst47 * (((0.075692795600000001 * fTemp11) + (0.0047585448999999998 * fTemp16)) - (((((0.0097754320000000006 * fTemp12) + ((0.059515338100000002 * fTemp8) + ((0.0407784697 * fTemp9) + (0.091927626900000003 * fTemp10)))) + (0.014959923999999999 * fTemp13)) + (0.10644125240000001 * fTemp14)) + (0.10346473389999999 * fTemp15))))));
			fRec1085[0] = (fRec1085[1] + fTemp250);
			fRec1083[0] = fRec1085[0];
			double fRec1084 = fTemp250;
			fRec1082[0] = (fRec1083[0] + fRec1082[1]);
			fRec1080[0] = fRec1082[0];
			double fRec1081 = fRec1084;
			double fTemp251 = (fConst48 * (0.0 - ((fConst50 * fRec1077[1]) + (fConst49 * fRec1074[1]))));
			fRec1079[0] = (fRec1081 + (fRec1079[1] + fTemp251));
			fRec1077[0] = fRec1079[0];
			double fRec1078 = (fRec1081 + fTemp251);
			fRec1076[0] = (fRec1077[0] + fRec1076[1]);
			fRec1074[0] = fRec1076[0];
			double fRec1075 = fRec1078;
			double fTemp252 = (fConst33 * ((fConst5 * (0.0 - ((fConst35 * fRec1098[1]) + (fConst34 * fRec1095[1])))) + (fConst38 * (((0.0099442948999999992 * fTemp44) + ((0.0106395068 * fTemp48) + (0.016966368400000001 * fTemp49))) - ((0.039649992199999998 * fTemp39) + ((0.041498773099999997 * fTemp40) + ((0.081701227400000007 * fTemp43) + ((0.064143982500000002 * fTemp45) + ((0.074753127500000002 * fTemp41) + ((0.0047548948999999998 * fTemp46) + ((0.041317189900000002 * fTemp47) + (0.096707616400000002 * fTemp42))))))))))));
			fRec1100[0] = (fRec1100[1] + fTemp252);
			fRec1098[0] = fRec1100[0];
			double fRec1099 = fTemp252;
			fRec1097[0] = (fRec1098[0] + fRec1097[1]);
			fRec1095[0] = fRec1097[0];
			double fRec1096 = fRec1099;
			double fTemp253 = (fConst39 * (0.0 - ((fConst41 * fRec1092[1]) + (fConst40 * fRec1089[1]))));
			fRec1094[0] = (fRec1096 + (fRec1094[1] + fTemp253));
			fRec1092[0] = fRec1094[0];
			double fRec1093 = (fRec1096 + fTemp253);
			fRec1091[0] = (fRec1092[0] + fRec1091[1]);
			fRec1089[0] = fRec1091[0];
			double fRec1090 = fRec1093;
			double fTemp254 = (fConst42 * fRec1086[1]);
			fRec1088[0] = ((fRec1090 + fRec1088[1]) - fTemp254);
			fRec1086[0] = fRec1088[0];
			double fRec1087 = (fRec1090 - fTemp254);
			double fTemp255 = (fConst57 * ((((0.086306478000000006 * fTemp34) + (0.077722109100000006 * fTemp35)) + (0.030579153299999998 * fTemp36)) - (fConst58 * fRec1101[1])));
			fRec1103[0] = (fRec1103[1] + fTemp255);
			fRec1101[0] = fRec1103[0];
			double fRec1102 = fTemp255;
			double fTemp256 = (fConst59 * ((((0.021229604700000002 * fTemp32) + ((0.1447242077 * fTemp28) + ((0.056520760900000001 * fTemp29) + (0.049048282999999998 * fTemp30)))) - (0.066951590300000002 * fTemp31)) + (fConst5 * (0.0 - ((fConst61 * fRec1107[1]) + (fConst60 * fRec1104[1]))))));
			fRec1109[0] = (fRec1109[1] + fTemp256);
			fRec1107[0] = fRec1109[0];
			double fRec1108 = fTemp256;
			fRec1106[0] = (fRec1107[0] + fRec1106[1]);
			fRec1104[0] = fRec1106[0];
			double fRec1105 = fRec1108;
			double fTemp257 = (fConst51 * ((fConst5 * (0.0 - ((fConst53 * fRec1116[1]) + (fConst52 * fRec1113[1])))) + (fConst55 * ((((0.094756458200000004 * fTemp20) + (0.100904202 * fTemp22)) + (0.028565991999999998 * fTemp24)) - ((((0.031892180300000003 * fTemp19) + (0.065394756400000004 * fTemp23)) + (0.1173150315 * fTemp21)) + (0.058814350000000001 * fTemp25))))));
			fRec1118[0] = (fRec1118[1] + fTemp257);
			fRec1116[0] = fRec1118[0];
			double fRec1117 = fTemp257;
			fRec1115[0] = (fRec1116[0] + fRec1115[1]);
			fRec1113[0] = fRec1115[0];
			double fRec1114 = fRec1117;
			double fTemp258 = (fConst56 * fRec1110[1]);
			fRec1112[0] = ((fRec1114 + fRec1112[1]) - fTemp258);
			fRec1110[0] = fRec1112[0];
			double fRec1111 = (fRec1114 - fTemp258);
			fVec23[(IOTA & 511)] = ((0.042479524999999997 * fTemp7) + (fRec1075 + (fRec1087 + (fRec1102 + (fRec1105 + fRec1111)))));
			output23[i] = FAUSTFLOAT((0.87553802008608317 * (fRec0[0] * fVec23[((IOTA - iConst62) & 511)])));
			double fTemp259 = (fConst63 * ((((0.084355014699999994 * fTemp32) + ((0.0532528341 * fTemp28) + ((0.018889524800000002 * fTemp29) + (0.052994769900000002 * fTemp30)))) - (0.0001143287 * fTemp31)) + (fConst5 * (0.0 - ((fConst65 * fRec1122[1]) + (fConst64 * fRec1119[1]))))));
			fRec1124[0] = (fRec1124[1] + fTemp259);
			fRec1122[0] = fRec1124[0];
			double fRec1123 = fTemp259;
			fRec1121[0] = (fRec1122[0] + fRec1121[1]);
			fRec1119[0] = fRec1121[0];
			double fRec1120 = fRec1123;
			double fTemp260 = (fConst66 * ((((0.0220263973 * fTemp34) + (0.066940710599999995 * fTemp35)) + (0.021915488699999999 * fTemp36)) - (fConst67 * fRec1125[1])));
			fRec1127[0] = (fRec1127[1] + fTemp260);
			fRec1125[0] = fRec1127[0];
			double fRec1126 = fTemp260;
			double fTemp261 = (fConst68 * ((fConst5 * (0.0 - ((fConst70 * fRec1140[1]) + (fConst69 * fRec1137[1])))) + (fConst73 * ((((((0.033880384499999999 * fTemp45) + (0.097021274699999993 * fTemp44)) + (0.082867077299999994 * fTemp43)) + (0.010806218899999999 * fTemp40)) + (0.082661755099999998 * fTemp39)) - ((0.00019222339999999999 * fTemp41) + ((0.0018226468000000001 * fTemp46) + ((((0.00055332020000000001 * fTemp47) + (0.034551079300000002 * fTemp42)) + (0.015180261400000001 * fTemp48)) + (0.0017719496000000001 * fTemp49))))))));
			fRec1142[0] = (fRec1142[1] + fTemp261);
			fRec1140[0] = fRec1142[0];
			double fRec1141 = fTemp261;
			fRec1139[0] = (fRec1140[0] + fRec1139[1]);
			fRec1137[0] = fRec1139[0];
			double fRec1138 = fRec1141;
			double fTemp262 = (fConst74 * (0.0 - ((fConst76 * fRec1134[1]) + (fConst75 * fRec1131[1]))));
			fRec1136[0] = (fRec1138 + (fRec1136[1] + fTemp262));
			fRec1134[0] = fRec1136[0];
			double fRec1135 = (fRec1138 + fTemp262);
			fRec1133[0] = (fRec1134[0] + fRec1133[1]);
			fRec1131[0] = fRec1133[0];
			double fRec1132 = fRec1135;
			double fTemp263 = (fConst77 * fRec1128[1]);
			fRec1130[0] = ((fRec1132 + fRec1130[1]) - fTemp263);
			fRec1128[0] = fRec1130[0];
			double fRec1129 = (fRec1132 - fTemp263);
			double fTemp264 = (fConst78 * ((fConst5 * (0.0 - ((fConst80 * fRec1149[1]) + (fConst79 * fRec1146[1])))) + (fConst82 * ((((((0.0074215373999999999 * fTemp19) + (0.047310529900000002 * fTemp20)) + (0.080226799400000007 * fTemp22)) + (0.074249264300000006 * fTemp23)) + (0.079867278700000002 * fTemp24)) - ((0.00028462970000000002 * fTemp21) + (0.0075645291 * fTemp25))))));
			fRec1151[0] = (fRec1151[1] + fTemp264);
			fRec1149[0] = fRec1151[0];
			double fRec1150 = fTemp264;
			fRec1148[0] = (fRec1149[0] + fRec1148[1]);
			fRec1146[0] = fRec1148[0];
			double fRec1147 = fRec1150;
			double fTemp265 = (fConst83 * fRec1143[1]);
			fRec1145[0] = ((fRec1147 + fRec1145[1]) - fTemp265);
			fRec1143[0] = fRec1145[0];
			double fRec1144 = (fRec1147 - fTemp265);
			double fTemp266 = (fConst84 * ((fConst5 * (0.0 - ((fConst86 * fRec1161[1]) + (fConst85 * fRec1158[1])))) + (fConst88 * ((((0.091170567699999996 * fTemp12) + ((0.077527304199999994 * fTemp11) + ((0.019443636100000002 * fTemp8) + (0.044844193800000001 * fTemp10)))) + (0.0908243938 * fTemp13)) - ((((6.83278e-05 * fTemp9) + (0.00045907810000000001 * fTemp14)) + (0.019823344199999999 * fTemp15)) + (0.0055343296000000004 * fTemp16))))));
			fRec1163[0] = (fRec1163[1] + fTemp266);
			fRec1161[0] = fRec1163[0];
			double fRec1162 = fTemp266;
			fRec1160[0] = (fRec1161[0] + fRec1160[1]);
			fRec1158[0] = fRec1160[0];
			double fRec1159 = fRec1162;
			double fTemp267 = (fConst89 * (0.0 - ((fConst91 * fRec1155[1]) + (fConst90 * fRec1152[1]))));
			fRec1157[0] = (fRec1159 + (fRec1157[1] + fTemp267));
			fRec1155[0] = fRec1157[0];
			double fRec1156 = (fRec1159 + fTemp267);
			fRec1154[0] = (fRec1155[0] + fRec1154[1]);
			fRec1152[0] = fRec1154[0];
			double fRec1153 = fRec1156;
			fVec24[(IOTA & 255)] = ((0.025484838499999999 * fTemp7) + (fRec1120 + (fRec1126 + (fRec1129 + (fRec1144 + fRec1153)))));
			output24[i] = FAUSTFLOAT((0.95355093256814927 * (fRec0[0] * fVec24[((IOTA - iConst92) & 255)])));
			double fTemp268 = (fConst84 * ((fConst88 * ((((((0.0001095549 * fTemp9) + (0.035412133300000002 * fTemp10)) + (0.13222508099999999 * fTemp13)) + (0.042095312000000003 * fTemp14)) + (0.00033663619999999998 * fTemp15)) - ((((0.018938804100000001 * fTemp8) + (0.076722609400000003 * fTemp11)) + (0.090556428999999994 * fTemp12)) + (0.00050223140000000004 * fTemp16)))) + (fConst5 * (0.0 - ((fConst86 * fRec1173[1]) + (fConst85 * fRec1170[1]))))));
			fRec1175[0] = (fRec1175[1] + fTemp268);
			fRec1173[0] = fRec1175[0];
			double fRec1174 = fTemp268;
			fRec1172[0] = (fRec1173[0] + fRec1172[1]);
			fRec1170[0] = fRec1172[0];
			double fRec1171 = fRec1174;
			double fTemp269 = (fConst89 * (0.0 - ((fConst91 * fRec1167[1]) + (fConst90 * fRec1164[1]))));
			fRec1169[0] = (fRec1171 + (fRec1169[1] + fTemp269));
			fRec1167[0] = fRec1169[0];
			double fRec1168 = (fRec1171 + fTemp269);
			fRec1166[0] = (fRec1167[0] + fRec1166[1]);
			fRec1164[0] = fRec1166[0];
			double fRec1165 = fRec1168;
			double fTemp270 = (fConst66 * ((((0.088250094200000004 * fTemp35) + (0.036347145999999997 * fTemp36)) - (0.0221166977 * fTemp34)) - (fConst67 * fRec1176[1])));
			fRec1178[0] = (fRec1178[1] + fTemp270);
			fRec1176[0] = fRec1178[0];
			double fRec1177 = fTemp270;
			double fTemp271 = (fConst78 * ((fConst5 * (0.0 - ((fConst80 * fRec1185[1]) + (fConst79 * fRec1182[1])))) + (fConst82 * (((((0.083417450300000001 * fTemp23) + (0.1245961587 * fTemp24)) + (0.0269801361 * fTemp21)) + (0.0001976359 * fTemp25)) - (((0.0072807378999999997 * fTemp19) + (0.047062170200000003 * fTemp20)) + (0.080118257700000001 * fTemp22))))));
			fRec1187[0] = (fRec1187[1] + fTemp271);
			fRec1185[0] = fRec1187[0];
			double fRec1186 = fTemp271;
			fRec1184[0] = (fRec1185[0] + fRec1184[1]);
			fRec1182[0] = fRec1184[0];
			double fRec1183 = fRec1186;
			double fTemp272 = (fConst83 * fRec1179[1]);
			fRec1181[0] = ((fRec1183 + fRec1181[1]) - fTemp272);
			fRec1179[0] = fRec1181[0];
			double fRec1180 = (fRec1183 - fTemp272);
			double fTemp273 = (fConst63 * ((((0.1059216186 * fTemp32) + ((0.085990975400000003 * fTemp30) + (0.0110994197 * fTemp31))) - ((0.018852114400000002 * fTemp29) + (0.053363046400000003 * fTemp28))) + (fConst5 * (0.0 - ((fConst65 * fRec1191[1]) + (fConst64 * fRec1188[1]))))));
			fRec1193[0] = (fRec1193[1] + fTemp273);
			fRec1191[0] = fRec1193[0];
			double fRec1192 = fTemp273;
			fRec1190[0] = (fRec1191[0] + fRec1190[1]);
			fRec1188[0] = fRec1190[0];
			double fRec1189 = fRec1192;
			double fTemp274 = (fConst68 * ((fConst5 * (0.0 - ((fConst70 * fRec1206[1]) + (fConst69 * fRec1203[1])))) + (fConst73 * (((0.1057515086 * fTemp39) + ((0.00039432650000000003 * fTemp41) + ((0.0016894869999999999 * fTemp46) + (((0.048505625099999998 * fTemp47) + (0.00013225619999999999 * fTemp42)) + (0.0012080299999999999 * fTemp49))))) - ((0.0140094637 * fTemp40) + ((0.081620654000000001 * fTemp43) + ((0.095239837300000005 * fTemp44) + ((0.0326343391 * fTemp45) + (0.0013064534999999999 * fTemp48)))))))));
			fRec1208[0] = (fRec1208[1] + fTemp274);
			fRec1206[0] = fRec1208[0];
			double fRec1207 = fTemp274;
			fRec1205[0] = (fRec1206[0] + fRec1205[1]);
			fRec1203[0] = fRec1205[0];
			double fRec1204 = fRec1207;
			double fTemp275 = (fConst74 * (0.0 - ((fConst76 * fRec1200[1]) + (fConst75 * fRec1197[1]))));
			fRec1202[0] = (fRec1204 + (fRec1202[1] + fTemp275));
			fRec1200[0] = fRec1202[0];
			double fRec1201 = (fRec1204 + fTemp275);
			fRec1199[0] = (fRec1200[0] + fRec1199[1]);
			fRec1197[0] = fRec1199[0];
			double fRec1198 = fRec1201;
			double fTemp276 = (fConst77 * fRec1194[1]);
			fRec1196[0] = ((fRec1198 + fRec1196[1]) - fTemp276);
			fRec1194[0] = fRec1196[0];
			double fRec1195 = (fRec1198 - fTemp276);
			fVec25[(IOTA & 255)] = ((0.0342672386 * fTemp7) + (fRec1165 + (fRec1177 + (fRec1180 + (fRec1189 + fRec1195)))));
			output25[i] = FAUSTFLOAT((0.95355093256814927 * (fRec0[0] * fVec25[((IOTA - iConst92) & 255)])));
			double fTemp277 = (fConst63 * ((((0.0192173694 * fTemp29) + (0.1053520488 * fTemp32)) - ((0.0852277699 * fTemp28) + ((0.0538309155 * fTemp30) + (0.010759918699999999 * fTemp31)))) + (fConst5 * (0.0 - ((fConst65 * fRec1212[1]) + (fConst64 * fRec1209[1]))))));
			fRec1214[0] = (fRec1214[1] + fTemp277);
			fRec1212[0] = fRec1214[0];
			double fRec1213 = fTemp277;
			fRec1211[0] = (fRec1212[0] + fRec1211[1]);
			fRec1209[0] = fRec1211[0];
			double fRec1210 = fRec1213;
			double fTemp278 = (fConst66 * (((0.087746924800000001 * fTemp35) - ((0.036021007299999998 * fTemp34) + (0.0223415236 * fTemp36))) - (fConst67 * fRec1215[1])));
			fRec1217[0] = (fRec1217[1] + fTemp278);
			fRec1215[0] = fRec1217[0];
			double fRec1216 = fTemp278;
			double fTemp279 = (fConst78 * ((fConst5 * (0.0 - ((fConst80 * fRec1224[1]) + (fConst79 * fRec1221[1])))) + (fConst82 * ((((0.047892361899999999 * fTemp20) + (0.083063305300000001 * fTemp23)) + (0.0075846198999999998 * fTemp25)) - ((((0.00013548499999999999 * fTemp19) + (0.12352071570000001 * fTemp22)) + (0.080642031099999997 * fTemp24)) + (0.026178806400000001 * fTemp21))))));
			fRec1226[0] = (fRec1226[1] + fTemp279);
			fRec1224[0] = fRec1226[0];
			double fRec1225 = fTemp279;
			fRec1223[0] = (fRec1224[0] + fRec1223[1]);
			fRec1221[0] = fRec1223[0];
			double fRec1222 = fRec1225;
			double fTemp280 = (fConst83 * fRec1218[1]);
			fRec1220[0] = ((fRec1222 + fRec1220[1]) - fTemp280);
			fRec1218[0] = fRec1220[0];
			double fRec1219 = (fRec1222 - fTemp280);
			double fTemp281 = (fConst84 * ((fConst5 * (0.0 - ((fConst86 * fRec1236[1]) + (fConst85 * fRec1233[1])))) + (fConst88 * ((((0.077886471700000001 * fTemp11) + (0.035475477599999999 * fTemp10)) + (0.019692611400000001 * fTemp15)) - ((((((3.8794600000000003e-05 * fTemp9) + (0.00047503239999999999 * fTemp8)) + (0.1311634807 * fTemp12)) + (0.090854007400000006 * fTemp13)) + (0.0409009969 * fTemp14)) + (0.000748532 * fTemp16))))));
			fRec1238[0] = (fRec1238[1] + fTemp281);
			fRec1236[0] = fRec1238[0];
			double fRec1237 = fTemp281;
			fRec1235[0] = (fRec1236[0] + fRec1235[1]);
			fRec1233[0] = fRec1235[0];
			double fRec1234 = fRec1237;
			double fTemp282 = (fConst89 * (0.0 - ((fConst91 * fRec1230[1]) + (fConst90 * fRec1227[1]))));
			fRec1232[0] = (fRec1234 + (fRec1232[1] + fTemp282));
			fRec1230[0] = fRec1232[0];
			double fRec1231 = (fRec1234 + fTemp282);
			fRec1229[0] = (fRec1230[0] + fRec1229[1]);
			fRec1227[0] = fRec1229[0];
			double fRec1228 = fRec1231;
			double fTemp283 = (fConst68 * ((fConst5 * (0.0 - ((fConst70 * fRec1251[1]) + (fConst69 * fRec1248[1])))) + (fConst73 * (((0.096361569300000005 * fTemp44) + ((0.033850340200000002 * fTemp42) + (0.0016694532000000001 * fTemp49))) - ((0.081516563299999997 * fTemp39) + ((0.0134977841 * fTemp40) + ((0.10507075070000001 * fTemp43) + ((0.0011407392000000001 * fTemp45) + ((1.62738e-05 * fTemp41) + ((0.0011009454 * fTemp46) + ((0.0472265532 * fTemp47) + (0.0019315948999999999 * fTemp48))))))))))));
			fRec1253[0] = (fRec1253[1] + fTemp283);
			fRec1251[0] = fRec1253[0];
			double fRec1252 = fTemp283;
			fRec1250[0] = (fRec1251[0] + fRec1250[1]);
			fRec1248[0] = fRec1250[0];
			double fRec1249 = fRec1252;
			double fTemp284 = (fConst74 * (0.0 - ((fConst76 * fRec1245[1]) + (fConst75 * fRec1242[1]))));
			fRec1247[0] = (fRec1249 + (fRec1247[1] + fTemp284));
			fRec1245[0] = fRec1247[0];
			double fRec1246 = (fRec1249 + fTemp284);
			fRec1244[0] = (fRec1245[0] + fRec1244[1]);
			fRec1242[0] = fRec1244[0];
			double fRec1243 = fRec1246;
			double fTemp285 = (fConst77 * fRec1239[1]);
			fRec1241[0] = ((fRec1243 + fRec1241[1]) - fTemp285);
			fRec1239[0] = fRec1241[0];
			double fRec1240 = (fRec1243 - fTemp285);
			fVec26[(IOTA & 255)] = ((0.034068688299999997 * fTemp7) + (fRec1210 + (fRec1216 + (fRec1219 + (fRec1228 + fRec1240)))));
			output26[i] = FAUSTFLOAT((0.95355093256814927 * (fRec0[0] * fVec26[((IOTA - iConst92) & 255)])));
			double fTemp286 = (fConst68 * ((fConst5 * (0.0 - ((fConst70 * fRec1266[1]) + (fConst69 * fRec1263[1])))) + (fConst73 * (((0.1037612626 * fTemp43) + ((0.0012526867000000001 * fTemp46) + (0.0119838293 * fTemp48))) - ((0.1030427476 * fTemp39) + ((0.037145560299999998 * fTemp40) + ((0.093625903699999999 * fTemp44) + ((7.2930999999999997e-06 * fTemp45) + ((0.00043575059999999998 * fTemp41) + (((4.7280400000000002e-05 * fTemp47) + (0.0012021619999999999 * fTemp42)) + (0.0012754428 * fTemp49)))))))))));
			fRec1268[0] = (fRec1268[1] + fTemp286);
			fRec1266[0] = fRec1268[0];
			double fRec1267 = fTemp286;
			fRec1265[0] = (fRec1266[0] + fRec1265[1]);
			fRec1263[0] = fRec1265[0];
			double fRec1264 = fRec1267;
			double fTemp287 = (fConst74 * (0.0 - ((fConst76 * fRec1260[1]) + (fConst75 * fRec1257[1]))));
			fRec1262[0] = (fRec1264 + (fRec1262[1] + fTemp287));
			fRec1260[0] = fRec1262[0];
			double fRec1261 = (fRec1264 + fTemp287);
			fRec1259[0] = (fRec1260[0] + fRec1259[1]);
			fRec1257[0] = fRec1259[0];
			double fRec1258 = fRec1261;
			double fTemp288 = (fConst77 * fRec1254[1]);
			fRec1256[0] = ((fRec1258 + fRec1256[1]) - fTemp288);
			fRec1254[0] = fRec1256[0];
			double fRec1255 = (fRec1258 - fTemp288);
			double fTemp289 = (fConst78 * ((fConst5 * (0.0 - ((fConst80 * fRec1275[1]) + (fConst79 * fRec1272[1])))) + (fConst82 * (((((4.6511999999999996e-06 * fTemp19) + (0.1231784569 * fTemp22)) + (0.091598701500000004 * fTemp23)) + (0.0002487492 * fTemp21)) - (((0.046980838699999999 * fTemp20) + (0.1228703683 * fTemp24)) + (0.00033243319999999999 * fTemp25))))));
			fRec1277[0] = (fRec1277[1] + fTemp289);
			fRec1275[0] = fRec1277[0];
			double fRec1276 = fTemp289;
			fRec1274[0] = (fRec1275[0] + fRec1274[1]);
			fRec1272[0] = fRec1274[0];
			double fRec1273 = fRec1276;
			double fTemp290 = (fConst83 * fRec1269[1]);
			fRec1271[0] = ((fRec1273 + fRec1271[1]) - fTemp290);
			fRec1269[0] = fRec1271[0];
			double fRec1270 = (fRec1273 - fTemp290);
			double fTemp291 = (fConst84 * ((fConst5 * (0.0 - ((fConst86 * fRec1287[1]) + (fConst85 * fRec1284[1])))) + (fConst88 * (((((0.1303688167 * fTemp12) + ((8.2826999999999995e-06 * fTemp8) + (0.0263377365 * fTemp10))) + (0.00021647539999999999 * fTemp14)) + (0.0043209737000000003 * fTemp16)) - ((((0.00016173690000000001 * fTemp9) + (0.076127181000000002 * fTemp11)) + (0.12980282479999999 * fTemp13)) + (0.00079116929999999998 * fTemp15))))));
			fRec1289[0] = (fRec1289[1] + fTemp291);
			fRec1287[0] = fRec1289[0];
			double fRec1288 = fTemp291;
			fRec1286[0] = (fRec1287[0] + fRec1286[1]);
			fRec1284[0] = fRec1286[0];
			double fRec1285 = fRec1288;
			double fTemp292 = (fConst89 * (0.0 - ((fConst91 * fRec1281[1]) + (fConst90 * fRec1278[1]))));
			fRec1283[0] = (fRec1285 + (fRec1283[1] + fTemp292));
			fRec1281[0] = fRec1283[0];
			double fRec1282 = (fRec1285 + fTemp292);
			fRec1280[0] = (fRec1281[0] + fRec1280[1]);
			fRec1278[0] = fRec1280[0];
			double fRec1279 = fRec1282;
			double fTemp293 = (fConst66 * ((((0.036022687499999997 * fTemp34) + (0.10794643850000001 * fTemp35)) - (0.036007171800000001 * fTemp36)) - (fConst67 * fRec1290[1])));
			fRec1292[0] = (fRec1292[1] + fTemp293);
			fRec1290[0] = fRec1292[0];
			double fRec1291 = fTemp293;
			double fTemp294 = (fConst63 * ((((0.12573050590000001 * fTemp32) + ((0.085146978799999995 * fTemp28) + (0.00013258160000000001 * fTemp31))) - ((0.018893480399999999 * fTemp29) + (0.085042134500000005 * fTemp30))) + (fConst5 * (0.0 - ((fConst65 * fRec1296[1]) + (fConst64 * fRec1293[1]))))));
			fRec1298[0] = (fRec1298[1] + fTemp294);
			fRec1296[0] = fRec1298[0];
			double fRec1297 = fTemp294;
			fRec1295[0] = (fRec1296[0] + fRec1295[1]);
			fRec1293[0] = fRec1295[0];
			double fRec1294 = fRec1297;
			fVec27[(IOTA & 255)] = ((0.0424027981 * fTemp7) + (fRec1255 + (fRec1270 + (fRec1279 + (fRec1291 + fRec1294)))));
			output27[i] = FAUSTFLOAT((0.95355093256814927 * (fRec0[0] * fVec27[((IOTA - iConst92) & 255)])));
			double fTemp295 = (fConst93 * ((fConst5 * (0.0 - ((fConst95 * fRec1305[1]) + (fConst94 * fRec1302[1])))) + (fConst97 * ((((((6.3099999999999997e-07 * fTemp19) + (3.4688999999999999e-06 * fTemp20)) + (1.10318e-05 * fTemp22)) + (0.066280089799999997 * fTemp23)) + (1.0543e-06 * fTemp25)) - ((4.2822599999999999e-05 * fTemp24) + (5.2900000000000002e-06 * fTemp21))))));
			fRec1307[0] = (fRec1307[1] + fTemp295);
			fRec1305[0] = fRec1307[0];
			double fRec1306 = fTemp295;
			fRec1304[0] = (fRec1305[0] + fRec1304[1]);
			fRec1302[0] = fRec1304[0];
			double fRec1303 = fRec1306;
			double fTemp296 = (fConst98 * fRec1299[1]);
			fRec1301[0] = ((fRec1303 + fRec1301[1]) - fTemp296);
			fRec1299[0] = fRec1301[0];
			double fRec1300 = (fRec1303 - fTemp296);
			double fTemp297 = (fConst99 * ((fConst5 * (0.0 - ((fConst101 * fRec1320[1]) + (fConst100 * fRec1317[1])))) + (fConst104 * (((0.0916704765 * fTemp40) + ((2.6307100000000001e-05 * fTemp43) + ((1.28405e-05 * fTemp44) + ((4.8663000000000003e-06 * fTemp45) + ((1.1880999999999999e-06 * fTemp41) + ((2.5699999999999999e-08 * fTemp46) + ((7.3862999999999999e-06 * fTemp42) + (4.2000000000000004e-09 * fTemp49)))))))) - ((8.3396699999999994e-05 * fTemp39) + ((1.9692000000000001e-05 * fTemp47) + (9.8370300000000002e-05 * fTemp48)))))));
			fRec1322[0] = (fRec1322[1] + fTemp297);
			fRec1320[0] = fRec1322[0];
			double fRec1321 = fTemp297;
			fRec1319[0] = (fRec1320[0] + fRec1319[1]);
			fRec1317[0] = fRec1319[0];
			double fRec1318 = fRec1321;
			double fTemp298 = (fConst105 * (0.0 - ((fConst107 * fRec1314[1]) + (fConst106 * fRec1311[1]))));
			fRec1316[0] = (fRec1318 + (fRec1316[1] + fTemp298));
			fRec1314[0] = fRec1316[0];
			double fRec1315 = (fRec1318 + fTemp298);
			fRec1313[0] = (fRec1314[0] + fRec1313[1]);
			fRec1311[0] = fRec1313[0];
			double fRec1312 = fRec1315;
			double fTemp299 = (fConst108 * fRec1308[1]);
			fRec1310[0] = ((fRec1312 + fRec1310[1]) - fTemp299);
			fRec1308[0] = fRec1310[0];
			double fRec1309 = (fRec1312 - fTemp299);
			double fTemp300 = (fConst109 * ((((1.9657000000000001e-06 * fTemp34) + (0.0304481074 * fTemp35)) - (8.5176999999999998e-06 * fTemp36)) - (fConst110 * fRec1323[1])));
			fRec1325[0] = (fRec1325[1] + fTemp300);
			fRec1323[0] = fRec1325[0];
			double fRec1324 = fTemp300;
			double fTemp301 = (fConst111 * (((((1.1512000000000001e-06 * fTemp29) + (5.6354999999999997e-06 * fTemp28)) + (0.049362916700000002 * fTemp32)) - ((2.3371799999999999e-05 * fTemp30) + (1.7517999999999999e-06 * fTemp31))) + (fConst5 * (0.0 - ((fConst113 * fRec1329[1]) + (fConst112 * fRec1326[1]))))));
			fRec1331[0] = (fRec1331[1] + fTemp301);
			fRec1329[0] = fRec1331[0];
			double fRec1330 = fTemp301;
			fRec1328[0] = (fRec1329[0] + fRec1328[1]);
			fRec1326[0] = fRec1328[0];
			double fRec1327 = fRec1330;
			double fTemp302 = (fConst114 * ((fConst5 * (0.0 - ((fConst116 * fRec1341[1]) + (fConst115 * fRec1338[1])))) + (fConst118 * ((((1.80029e-05 * fTemp12) + ((7.3386999999999997e-06 * fTemp11) + ((2.0760999999999999e-06 * fTemp8) + ((3.3640000000000002e-07 * fTemp9) + (0.080551933800000003 * fTemp10))))) + (3.3268999999999999e-06 * fTemp15)) - (((6.3924199999999994e-05 * fTemp13) + (1.12209e-05 * fTemp14)) + (2.7866699999999999e-05 * fTemp16))))));
			fRec1343[0] = (fRec1343[1] + fTemp302);
			fRec1341[0] = fRec1343[0];
			double fRec1342 = fTemp302;
			fRec1340[0] = (fRec1341[0] + fRec1340[1]);
			fRec1338[0] = fRec1340[0];
			double fRec1339 = fRec1342;
			double fTemp303 = (fConst119 * (0.0 - ((fConst121 * fRec1335[1]) + (fConst120 * fRec1332[1]))));
			fRec1337[0] = (fRec1339 + (fRec1337[1] + fTemp303));
			fRec1335[0] = fRec1337[0];
			double fRec1336 = (fRec1339 + fTemp303);
			fRec1334[0] = (fRec1335[0] + fRec1334[1]);
			fRec1332[0] = fRec1334[0];
			double fRec1333 = fRec1336;
			output28[i] = FAUSTFLOAT((fRec0[0] * ((0.0102900397 * fTemp7) + (fRec1300 + (fRec1309 + (fRec1324 + (fRec1327 + fRec1333)))))));
			double fTemp304 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec1350[1]) + (fConst12 * fRec1347[1])))) + (fConst15 * ((((0.1163306727 * fTemp19) + (0.042909408500000003 * fTemp23)) + (0.036740617500000003 * fTemp25)) - ((((0.069419295000000006 * fTemp20) + (0.0087417167000000007 * fTemp22)) + (0.019479602499999998 * fTemp24)) + (0.061811414699999997 * fTemp21))))));
			fRec1352[0] = (fRec1352[1] + fTemp304);
			fRec1350[0] = fRec1352[0];
			double fRec1351 = fTemp304;
			fRec1349[0] = (fRec1350[0] + fRec1349[1]);
			fRec1347[0] = fRec1349[0];
			double fRec1348 = fRec1351;
			double fTemp305 = (fConst16 * fRec1344[1]);
			fRec1346[0] = ((fRec1348 + fRec1346[1]) - fTemp305);
			fRec1344[0] = fRec1346[0];
			double fRec1345 = (fRec1348 - fTemp305);
			double fTemp306 = (fConst17 * ((((0.082452155599999993 * fTemp29) + (0.073415326899999994 * fTemp31)) - ((0.031409640699999998 * fTemp32) + ((0.031637392100000002 * fTemp28) + (0.070528638099999999 * fTemp30)))) + (fConst5 * (0.0 - ((fConst19 * fRec1356[1]) + (fConst18 * fRec1353[1]))))));
			fRec1358[0] = (fRec1358[1] + fTemp306);
			fRec1356[0] = fRec1358[0];
			double fRec1357 = fTemp306;
			fRec1355[0] = (fRec1356[0] + fRec1355[1]);
			fRec1353[0] = fRec1355[0];
			double fRec1354 = fRec1357;
			double fTemp307 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec1368[1]) + (fConst6 * fRec1365[1])))) + (fConst4 * ((((0.017399337500000001 * fTemp12) + ((0.12432768650000001 * fTemp9) + (0.0098920378999999992 * fTemp10))) + (0.038786109200000002 * fTemp13)) - (((((0.095389984400000002 * fTemp8) + (0.0040866358000000002 * fTemp11)) + (0.0036228926000000002 * fTemp14)) + (0.030124976299999998 * fTemp15)) + (0.014428450299999999 * fTemp16))))));
			fRec1370[0] = (fRec1370[1] + fTemp307);
			fRec1368[0] = fRec1370[0];
			double fRec1369 = fTemp307;
			fRec1367[0] = (fRec1368[0] + fRec1367[1]);
			fRec1365[0] = fRec1367[0];
			double fRec1366 = fRec1369;
			double fTemp308 = (fConst8 * (0.0 - ((fConst10 * fRec1362[1]) + (fConst9 * fRec1359[1]))));
			fRec1364[0] = (fRec1366 + (fRec1364[1] + fTemp308));
			fRec1362[0] = fRec1364[0];
			double fRec1363 = (fRec1366 + fTemp308);
			fRec1361[0] = (fRec1362[0] + fRec1361[1]);
			fRec1359[0] = fRec1361[0];
			double fRec1360 = fRec1363;
			double fTemp309 = (fConst20 * ((((0.035999881999999997 * fTemp34) + (0.080253251400000003 * fTemp36)) - (0.035996358800000003 * fTemp35)) - (fConst21 * fRec1371[1])));
			fRec1373[0] = (fRec1373[1] + fTemp309);
			fRec1371[0] = fRec1373[0];
			double fRec1372 = fTemp309;
			double fTemp310 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec1386[1]) + (fConst29 * fRec1383[1])))) + (fConst28 * (((0.0172014783 * fTemp39) + ((0.0077311252000000002 * fTemp43) + ((0.0194348019 * fTemp44) + ((0.0051383478999999996 * fTemp45) + ((0.1043784417 * fTemp46) + (((0.017292474299999999 * fTemp47) + (0.0016463813 * fTemp42)) + (0.0115334032 * fTemp48))))))) - ((0.020849784199999999 * fTemp40) + ((0.099300911699999994 * fTemp41) + (0.062113474299999999 * fTemp49)))))));
			fRec1388[0] = (fRec1388[1] + fTemp310);
			fRec1386[0] = fRec1388[0];
			double fRec1387 = fTemp310;
			fRec1385[0] = (fRec1386[0] + fRec1385[1]);
			fRec1383[0] = fRec1385[0];
			double fRec1384 = fRec1387;
			double fTemp311 = (fConst23 * (0.0 - ((fConst25 * fRec1380[1]) + (fConst24 * fRec1377[1]))));
			fRec1382[0] = (fRec1384 + (fRec1382[1] + fTemp311));
			fRec1380[0] = fRec1382[0];
			double fRec1381 = (fRec1384 + fTemp311);
			fRec1379[0] = (fRec1380[0] + fRec1379[1]);
			fRec1377[0] = fRec1379[0];
			double fRec1378 = fRec1381;
			double fTemp312 = (fConst31 * fRec1374[1]);
			fRec1376[0] = ((fRec1378 + fRec1376[1]) - fTemp312);
			fRec1374[0] = fRec1376[0];
			double fRec1375 = (fRec1378 - fTemp312);
			fVec28[(IOTA & 1023)] = ((0.033985482099999999 * fTemp7) + (fRec1345 + (fRec1354 + (fRec1360 + (fRec1372 + fRec1375)))));
			output29[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec28[((IOTA - iConst32) & 1023)])));
			double fTemp313 = (fConst17 * ((((0.0055052596000000004 * fTemp29) + (0.110944865 * fTemp31)) - ((0.031932683199999999 * fTemp32) + ((0.0019055224999999999 * fTemp28) + (0.076810528899999994 * fTemp30)))) + (fConst5 * (0.0 - ((fConst19 * fRec1392[1]) + (fConst18 * fRec1389[1]))))));
			fRec1394[0] = (fRec1394[1] + fTemp313);
			fRec1392[0] = fRec1394[0];
			double fRec1393 = fTemp313;
			fRec1391[0] = (fRec1392[0] + fRec1391[1]);
			fRec1389[0] = fRec1391[0];
			double fRec1390 = fRec1393;
			double fTemp314 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec1401[1]) + (fConst12 * fRec1398[1])))) + (fConst15 * ((((0.0091264992000000007 * fTemp19) + (0.042524342399999998 * fTemp23)) + (0.12248743099999999 * fTemp25)) - ((((0.0045699534 * fTemp20) + (0.00054194729999999997 * fTemp22)) + (0.022290322000000001 * fTemp24)) + (0.092254582399999993 * fTemp21))))));
			fRec1403[0] = (fRec1403[1] + fTemp314);
			fRec1401[0] = fRec1403[0];
			double fRec1402 = fTemp314;
			fRec1400[0] = (fRec1401[0] + fRec1400[1]);
			fRec1398[0] = fRec1400[0];
			double fRec1399 = fRec1402;
			double fTemp315 = (fConst16 * fRec1395[1]);
			fRec1397[0] = ((fRec1399 + fRec1397[1]) - fTemp315);
			fRec1395[0] = fRec1397[0];
			double fRec1396 = (fRec1399 - fTemp315);
			double fTemp316 = (fConst20 * ((((0.0021928950999999999 * fTemp34) + (0.088396874700000003 * fTemp36)) - (0.035796514500000001 * fTemp35)) - (fConst21 * fRec1404[1])));
			fRec1406[0] = (fRec1406[1] + fTemp316);
			fRec1404[0] = fRec1406[0];
			double fRec1405 = fTemp316;
			double fTemp317 = (fConst2 * ((fConst4 * (((((0.0010142829999999999 * fTemp12) + ((0.0124847616 * fTemp9) + (0.0106104272 * fTemp10))) + (0.041893931699999998 * fTemp13)) + (0.12544627250000001 * fTemp16)) - ((((0.0073632157999999996 * fTemp8) + (0.00030961859999999999 * fTemp11)) + (0.0064985249000000002 * fTemp14)) + (0.0991315745 * fTemp15)))) + (fConst5 * (0.0 - ((fConst7 * fRec1416[1]) + (fConst6 * fRec1413[1]))))));
			fRec1418[0] = (fRec1418[1] + fTemp317);
			fRec1416[0] = fRec1418[0];
			double fRec1417 = fTemp317;
			fRec1415[0] = (fRec1416[0] + fRec1415[1]);
			fRec1413[0] = fRec1415[0];
			double fRec1414 = fRec1417;
			double fTemp318 = (fConst8 * (0.0 - ((fConst10 * fRec1410[1]) + (fConst9 * fRec1407[1]))));
			fRec1412[0] = (fRec1414 + (fRec1412[1] + fTemp318));
			fRec1410[0] = fRec1412[0];
			double fRec1411 = (fRec1414 + fTemp318);
			fRec1409[0] = (fRec1410[0] + fRec1409[1]);
			fRec1407[0] = fRec1409[0];
			double fRec1408 = fRec1411;
			double fTemp319 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec1431[1]) + (fConst29 * fRec1428[1])))) + (fConst28 * (((0.019852544699999999 * fTemp39) + ((0.00050846590000000003 * fTemp43) + ((0.0012093478 * fTemp44) + ((0.00033106159999999999 * fTemp45) + ((0.015141551499999999 * fTemp46) + (((0.0253248503 * fTemp47) + (0.0043465337000000003 * fTemp42)) + (0.12140736219999999 * fTemp49))))))) - ((0.020328344700000001 * fTemp40) + ((0.0097965814000000005 * fTemp41) + (0.098881825699999995 * fTemp48)))))));
			fRec1433[0] = (fRec1433[1] + fTemp319);
			fRec1431[0] = fRec1433[0];
			double fRec1432 = fTemp319;
			fRec1430[0] = (fRec1431[0] + fRec1430[1]);
			fRec1428[0] = fRec1430[0];
			double fRec1429 = fRec1432;
			double fTemp320 = (fConst23 * (0.0 - ((fConst25 * fRec1425[1]) + (fConst24 * fRec1422[1]))));
			fRec1427[0] = (fRec1429 + (fRec1427[1] + fTemp320));
			fRec1425[0] = fRec1427[0];
			double fRec1426 = (fRec1429 + fTemp320);
			fRec1424[0] = (fRec1425[0] + fRec1424[1]);
			fRec1422[0] = fRec1424[0];
			double fRec1423 = fRec1426;
			double fTemp321 = (fConst31 * fRec1419[1]);
			fRec1421[0] = ((fRec1423 + fRec1421[1]) - fTemp321);
			fRec1419[0] = fRec1421[0];
			double fRec1420 = (fRec1423 - fTemp321);
			fVec29[(IOTA & 1023)] = ((0.034128871200000001 * fTemp7) + (fRec1390 + (fRec1396 + (fRec1405 + (fRec1408 + fRec1420)))));
			output30[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec29[((IOTA - iConst32) & 1023)])));
			double fTemp322 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec1443[1]) + (fConst6 * fRec1440[1])))) + (fConst4 * (((((0.0037614394999999998 * fTemp11) + ((0.089584713400000002 * fTemp8) + (0.0100336568 * fTemp10))) + (0.039410912899999997 * fTemp13)) + (0.0108904168 * fTemp16)) - ((((0.1247754448 * fTemp9) + (0.015316099999999999 * fTemp12)) + (0.0040979498999999999 * fTemp14)) + (0.044188670700000002 * fTemp15))))));
			fRec1445[0] = (fRec1445[1] + fTemp322);
			fRec1443[0] = fRec1445[0];
			double fRec1444 = fTemp322;
			fRec1442[0] = (fRec1443[0] + fRec1442[1]);
			fRec1440[0] = fRec1442[0];
			double fRec1441 = fRec1444;
			double fTemp323 = (fConst8 * (0.0 - ((fConst10 * fRec1437[1]) + (fConst9 * fRec1434[1]))));
			fRec1439[0] = (fRec1441 + (fRec1439[1] + fTemp323));
			fRec1437[0] = fRec1439[0];
			double fRec1438 = (fRec1441 + fTemp323);
			fRec1436[0] = (fRec1437[0] + fRec1436[1]);
			fRec1434[0] = fRec1436[0];
			double fRec1435 = fRec1438;
			double fTemp324 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec1458[1]) + (fConst29 * fRec1455[1])))) + (fConst28 * (((0.017771121399999999 * fTemp39) + ((0.0994621698 * fTemp41) + ((0.0190326826 * fTemp47) + (0.0023477251999999998 * fTemp42)))) - ((0.020754722100000001 * fTemp40) + ((0.0069230990000000003 * fTemp43) + ((0.017415278100000001 * fTemp44) + ((0.0047302192 * fTemp45) + ((0.11670116010000001 * fTemp46) + ((0.0087177750000000005 * fTemp48) + (0.034054972699999998 * fTemp49)))))))))));
			fRec1460[0] = (fRec1460[1] + fTemp324);
			fRec1458[0] = fRec1460[0];
			double fRec1459 = fTemp324;
			fRec1457[0] = (fRec1458[0] + fRec1457[1]);
			fRec1455[0] = fRec1457[0];
			double fRec1456 = fRec1459;
			double fTemp325 = (fConst23 * (0.0 - ((fConst25 * fRec1452[1]) + (fConst24 * fRec1449[1]))));
			fRec1454[0] = (fRec1456 + (fRec1454[1] + fTemp325));
			fRec1452[0] = fRec1454[0];
			double fRec1453 = (fRec1456 + fTemp325);
			fRec1451[0] = (fRec1452[0] + fRec1451[1]);
			fRec1449[0] = fRec1451[0];
			double fRec1450 = fRec1453;
			double fTemp326 = (fConst31 * fRec1446[1]);
			fRec1448[0] = ((fRec1450 + fRec1448[1]) - fTemp326);
			fRec1446[0] = fRec1448[0];
			double fRec1447 = (fRec1450 - fTemp326);
			double fTemp327 = (fConst17 * ((((0.027981907699999999 * fTemp28) + (0.081420015100000007 * fTemp31)) - ((0.031413526499999997 * fTemp32) + ((0.074619689099999997 * fTemp29) + (0.0719548619 * fTemp30)))) + (fConst5 * (0.0 - ((fConst19 * fRec1464[1]) + (fConst18 * fRec1461[1]))))));
			fRec1466[0] = (fRec1466[1] + fTemp327);
			fRec1464[0] = fRec1466[0];
			double fRec1465 = fTemp327;
			fRec1463[0] = (fRec1464[0] + fRec1463[1]);
			fRec1461[0] = fRec1463[0];
			double fRec1462 = fRec1465;
			double fTemp328 = (fConst20 * (((0.081998725800000005 * fTemp36) - ((0.031891335799999997 * fTemp34) + (0.035974382399999998 * fTemp35))) - (fConst21 * fRec1467[1])));
			fRec1469[0] = (fRec1469[1] + fTemp328);
			fRec1467[0] = fRec1469[0];
			double fRec1468 = fTemp328;
			double fTemp329 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec1476[1]) + (fConst12 * fRec1473[1])))) + (fConst15 * (((((0.062703040500000001 * fTemp20) + (0.0077611802000000004 * fTemp22)) + (0.042753812199999998 * fTemp23)) + (0.053970824100000002 * fTemp25)) - (((0.1094785314 * fTemp19) + (0.0199568613 * fTemp24)) + (0.068433135699999995 * fTemp21))))));
			fRec1478[0] = (fRec1478[1] + fTemp329);
			fRec1476[0] = fRec1478[0];
			double fRec1477 = fTemp329;
			fRec1475[0] = (fRec1476[0] + fRec1475[1]);
			fRec1473[0] = fRec1475[0];
			double fRec1474 = fRec1477;
			double fTemp330 = (fConst16 * fRec1470[1]);
			fRec1472[0] = ((fRec1474 + fRec1472[1]) - fTemp330);
			fRec1470[0] = fRec1472[0];
			double fRec1471 = (fRec1474 - fTemp330);
			fVec30[(IOTA & 1023)] = ((0.033996610300000001 * fTemp7) + (fRec1435 + (fRec1447 + (fRec1462 + (fRec1468 + fRec1471)))));
			output31[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec30[((IOTA - iConst32) & 1023)])));
			double fTemp331 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec1491[1]) + (fConst29 * fRec1488[1])))) + (fConst28 * (((0.0142857448 * fTemp39) + ((0.0064789288000000004 * fTemp41) + ((0.079154066699999998 * fTemp46) + ((0.00087525039999999997 * fTemp47) + (0.099646989599999999 * fTemp48))))) - ((0.0205349703 * fTemp40) + ((0.013814160299999999 * fTemp43) + ((0.0256005903 * fTemp44) + ((0.0032392032 * fTemp45) + ((0.0031234211 * fTemp42) + (0.093528804699999996 * fTemp49))))))))));
			fRec1493[0] = (fRec1493[1] + fTemp331);
			fRec1491[0] = fRec1493[0];
			double fRec1492 = fTemp331;
			fRec1490[0] = (fRec1491[0] + fRec1490[1]);
			fRec1488[0] = fRec1490[0];
			double fRec1489 = fRec1492;
			double fTemp332 = (fConst23 * (0.0 - ((fConst25 * fRec1485[1]) + (fConst24 * fRec1482[1]))));
			fRec1487[0] = (fRec1489 + (fRec1487[1] + fTemp332));
			fRec1485[0] = fRec1487[0];
			double fRec1486 = (fRec1489 + fTemp332);
			fRec1484[0] = (fRec1485[0] + fRec1484[1]);
			fRec1482[0] = fRec1484[0];
			double fRec1483 = fRec1486;
			double fTemp333 = (fConst31 * fRec1479[1]);
			fRec1481[0] = ((fRec1483 + fRec1481[1]) - fTemp333);
			fRec1479[0] = fRec1481[0];
			double fRec1480 = (fRec1483 - fTemp333);
			double fTemp334 = (fConst17 * ((((0.053900869599999998 * fTemp28) + (0.0036687244000000001 * fTemp31)) - ((0.032124069399999997 * fTemp32) + ((0.1117141593 * fTemp29) + (0.055652225899999998 * fTemp30)))) + (fConst5 * (0.0 - ((fConst19 * fRec1497[1]) + (fConst18 * fRec1494[1]))))));
			fRec1499[0] = (fRec1499[1] + fTemp334);
			fRec1497[0] = fRec1499[0];
			double fRec1498 = fTemp334;
			fRec1496[0] = (fRec1497[0] + fRec1496[1]);
			fRec1494[0] = fRec1496[0];
			double fRec1495 = fRec1498;
			double fTemp335 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec1509[1]) + (fConst6 * fRec1506[1])))) + (fConst4 * (((((0.0064228195000000004 * fTemp11) + ((0.074101025200000004 * fTemp8) + (0.010593011899999999 * fTemp10))) + (0.030415986200000002 * fTemp13)) + (0.067244396499999998 * fTemp15)) - ((((0.0083638167999999999 * fTemp9) + (0.0294120236 * fTemp12)) + (0.00030759299999999999 * fTemp14)) + (0.12623552690000001 * fTemp16))))));
			fRec1511[0] = (fRec1511[1] + fTemp335);
			fRec1509[0] = fRec1511[0];
			double fRec1510 = fTemp335;
			fRec1508[0] = (fRec1509[0] + fRec1508[1]);
			fRec1506[0] = fRec1508[0];
			double fRec1507 = fRec1510;
			double fTemp336 = (fConst8 * (0.0 - ((fConst10 * fRec1503[1]) + (fConst9 * fRec1500[1]))));
			fRec1505[0] = (fRec1507 + (fRec1505[1] + fTemp336));
			fRec1503[0] = fRec1505[0];
			double fRec1504 = (fRec1507 + fTemp336);
			fRec1502[0] = (fRec1503[0] + fRec1502[1]);
			fRec1500[0] = fRec1502[0];
			double fRec1501 = fRec1504;
			double fTemp337 = (fConst20 * (((0.063980663399999999 * fTemp36) - ((0.0619228317 * fTemp34) + (0.036098277400000003 * fTemp35))) - (fConst21 * fRec1512[1])));
			fRec1514[0] = (fRec1514[1] + fTemp337);
			fRec1512[0] = fRec1514[0];
			double fRec1513 = fTemp337;
			double fTemp338 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec1521[1]) + (fConst12 * fRec1518[1])))) + (fConst15 * ((((0.093035410499999999 * fTemp20) + (0.015513203 * fTemp22)) + (0.0429151797 * fTemp23)) - ((((0.091502150099999999 * fTemp19) + (0.016097762099999999 * fTemp24)) + (0.002993529 * fTemp21)) + (0.082875892600000001 * fTemp25))))));
			fRec1523[0] = (fRec1523[1] + fTemp338);
			fRec1521[0] = fRec1523[0];
			double fRec1522 = fTemp338;
			fRec1520[0] = (fRec1521[0] + fRec1520[1]);
			fRec1518[0] = fRec1520[0];
			double fRec1519 = fRec1522;
			double fTemp339 = (fConst16 * fRec1515[1]);
			fRec1517[0] = ((fRec1519 + fRec1517[1]) - fTemp339);
			fRec1515[0] = fRec1517[0];
			double fRec1516 = (fRec1519 - fTemp339);
			fVec31[(IOTA & 1023)] = ((0.034376846000000003 * fTemp7) + (fRec1480 + (fRec1495 + (fRec1501 + (fRec1513 + fRec1516)))));
			output32[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec31[((IOTA - iConst32) & 1023)])));
			double fTemp340 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec1530[1]) + (fConst12 * fRec1527[1])))) + (fConst15 * ((((((0.043692687600000002 * fTemp19) + (0.067590558199999998 * fTemp20)) + (0.020160876000000001 * fTemp22)) + (0.043268058800000002 * fTemp23)) + (0.064875360600000001 * fTemp21)) - ((0.0085816519000000008 * fTemp24) + (0.115314396 * fTemp25))))));
			fRec1532[0] = (fRec1532[1] + fTemp340);
			fRec1530[0] = fRec1532[0];
			double fRec1531 = fTemp340;
			fRec1529[0] = (fRec1530[0] + fRec1529[1]);
			fRec1527[0] = fRec1529[0];
			double fRec1528 = fRec1531;
			double fTemp341 = (fConst16 * fRec1524[1]);
			fRec1526[0] = ((fRec1528 + fRec1526[1]) - fTemp341);
			fRec1524[0] = fRec1526[0];
			double fRec1525 = (fRec1528 - fTemp341);
			double fTemp342 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec1545[1]) + (fConst29 * fRec1542[1])))) + (fConst28 * (((0.0076276114000000004 * fTemp39) + ((0.0017809975 * fTemp45) + ((0.052391209500000001 * fTemp46) + ((0.0040958035 * fTemp48) + (0.1103619894 * fTemp49))))) - ((0.020924656 * fTemp40) + ((0.017844112299999999 * fTemp43) + ((0.018795755000000001 * fTemp44) + ((0.1002626039 * fTemp41) + ((0.0180591984 * fTemp47) + (0.0047252756999999999 * fTemp42))))))))));
			fRec1547[0] = (fRec1547[1] + fTemp342);
			fRec1545[0] = fRec1547[0];
			double fRec1546 = fTemp342;
			fRec1544[0] = (fRec1545[0] + fRec1544[1]);
			fRec1542[0] = fRec1544[0];
			double fRec1543 = fRec1546;
			double fTemp343 = (fConst23 * (0.0 - ((fConst25 * fRec1539[1]) + (fConst24 * fRec1536[1]))));
			fRec1541[0] = (fRec1543 + (fRec1541[1] + fTemp343));
			fRec1539[0] = fRec1541[0];
			double fRec1540 = (fRec1543 + fTemp343);
			fRec1538[0] = (fRec1539[0] + fRec1538[1]);
			fRec1536[0] = fRec1538[0];
			double fRec1537 = fRec1540;
			double fTemp344 = (fConst31 * fRec1533[1]);
			fRec1535[0] = ((fRec1537 + fRec1535[1]) - fTemp344);
			fRec1533[0] = fRec1535[0];
			double fRec1534 = (fRec1537 - fTemp344);
			double fTemp345 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec1557[1]) + (fConst6 * fRec1554[1])))) + (fConst4 * ((((((0.0042390850000000001 * fTemp11) + ((0.12615300739999999 * fTemp9) + (0.010253254 * fTemp10))) + (0.016766455499999999 * fTemp13)) + (0.0040842187000000004 * fTemp14)) + (0.094130766800000001 * fTemp15)) - (((0.0356487661 * fTemp8) + (0.039368440900000003 * fTemp12)) + (0.0051209491000000001 * fTemp16))))));
			fRec1559[0] = (fRec1559[1] + fTemp345);
			fRec1557[0] = fRec1559[0];
			double fRec1558 = fTemp345;
			fRec1556[0] = (fRec1557[0] + fRec1556[1]);
			fRec1554[0] = fRec1556[0];
			double fRec1555 = fRec1558;
			double fTemp346 = (fConst8 * (0.0 - ((fConst10 * fRec1551[1]) + (fConst9 * fRec1548[1]))));
			fRec1553[0] = (fRec1555 + (fRec1553[1] + fTemp346));
			fRec1551[0] = fRec1553[0];
			double fRec1552 = (fRec1555 + fTemp346);
			fRec1550[0] = (fRec1551[0] + fRec1550[1]);
			fRec1548[0] = fRec1550[0];
			double fRec1549 = fRec1552;
			double fTemp347 = (fConst20 * (((0.034927997000000002 * fTemp36) - ((0.081945032700000003 * fTemp34) + (0.0363389296 * fTemp35))) - (fConst21 * fRec1560[1])));
			fRec1562[0] = (fRec1562[1] + fTemp347);
			fRec1560[0] = fRec1562[0];
			double fRec1561 = fTemp347;
			double fTemp348 = (fConst17 * (((0.071746467600000002 * fTemp28) - ((0.031937806499999999 * fTemp32) + ((0.080605835400000006 * fTemp29) + ((0.0305874358 * fTemp30) + (0.077384490099999995 * fTemp31))))) + (fConst5 * (0.0 - ((fConst19 * fRec1566[1]) + (fConst18 * fRec1563[1]))))));
			fRec1568[0] = (fRec1568[1] + fTemp348);
			fRec1566[0] = fRec1568[0];
			double fRec1567 = fTemp348;
			fRec1565[0] = (fRec1566[0] + fRec1565[1]);
			fRec1563[0] = fRec1565[0];
			double fRec1564 = fRec1567;
			fVec32[(IOTA & 1023)] = ((0.034416953399999999 * fTemp7) + (fRec1525 + (fRec1534 + (fRec1549 + (fRec1561 + fRec1564)))));
			output33[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec32[((IOTA - iConst32) & 1023)])));
			double fTemp349 = (fConst2 * ((fConst4 * (((((5.6628100000000001e-05 * fTemp11) + ((0.00017025779999999999 * fTemp9) + (0.0105596445 * fTemp10))) + (0.0061573343999999997 * fTemp14)) + (0.12702133569999999 * fTemp16)) - ((((0.1009950171 * fTemp8) + (0.042766231199999998 * fTemp12)) + (1.8634499999999999e-05 * fTemp13)) + (4.4666899999999998e-05 * fTemp15)))) + (fConst5 * (0.0 - ((fConst7 * fRec1578[1]) + (fConst6 * fRec1575[1]))))));
			fRec1580[0] = (fRec1580[1] + fTemp349);
			fRec1578[0] = fRec1580[0];
			double fRec1579 = fTemp349;
			fRec1577[0] = (fRec1578[0] + fRec1577[1]);
			fRec1575[0] = fRec1577[0];
			double fRec1576 = fRec1579;
			double fTemp350 = (fConst8 * (0.0 - ((fConst10 * fRec1572[1]) + (fConst9 * fRec1569[1]))));
			fRec1574[0] = (fRec1576 + (fRec1574[1] + fTemp350));
			fRec1572[0] = fRec1574[0];
			double fRec1573 = (fRec1576 + fTemp350);
			fRec1571[0] = (fRec1572[0] + fRec1571[1]);
			fRec1569[0] = fRec1571[0];
			double fRec1570 = fRec1573;
			double fTemp351 = (fConst20 * (((1.6833700000000001e-05 * fTemp36) - ((0.089838240299999997 * fTemp34) + (0.036576285299999997 * fTemp35))) - (fConst21 * fRec1581[1])));
			fRec1583[0] = (fRec1583[1] + fTemp351);
			fRec1581[0] = fRec1583[0];
			double fRec1582 = fTemp351;
			double fTemp352 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec1590[1]) + (fConst12 * fRec1587[1])))) + (fConst15 * (((((0.1242159033 * fTemp19) + (0.0222397576 * fTemp22)) + (0.043385885700000001 * fTemp23)) + (0.094115795399999994 * fTemp21)) - (((2.7212800000000001e-05 * fTemp20) + (2.64533e-05 * fTemp24)) + (0.0001025116 * fTemp25))))));
			fRec1592[0] = (fRec1592[1] + fTemp352);
			fRec1590[0] = fRec1592[0];
			double fRec1591 = fTemp352;
			fRec1589[0] = (fRec1590[0] + fRec1589[1]);
			fRec1587[0] = fRec1589[0];
			double fRec1588 = fRec1591;
			double fTemp353 = (fConst16 * fRec1584[1]);
			fRec1586[0] = ((fRec1588 + fRec1586[1]) - fTemp353);
			fRec1584[0] = fRec1586[0];
			double fRec1585 = (fRec1588 - fTemp353);
			double fTemp354 = (fConst17 * ((((0.078430445400000007 * fTemp28) + (1.09431e-05 * fTemp30)) - ((0.032247978300000001 * fTemp32) + ((5.1243699999999999e-05 * fTemp29) + (0.1126450264 * fTemp31)))) + (fConst5 * (0.0 - ((fConst19 * fRec1596[1]) + (fConst18 * fRec1593[1]))))));
			fRec1598[0] = (fRec1598[1] + fTemp354);
			fRec1596[0] = fRec1598[0];
			double fRec1597 = fTemp354;
			fRec1595[0] = (fRec1596[0] + fRec1595[1]);
			fRec1593[0] = fRec1595[0];
			double fRec1594 = fRec1597;
			double fTemp355 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec1611[1]) + (fConst29 * fRec1608[1])))) + (fConst28 * (((2.46889e-05 * fTemp39) + ((5.0091299999999999e-05 * fTemp44) + ((0.0048199089000000002 * fTemp45) + ((5.7076400000000001e-05 * fTemp41) + ((8.8036799999999997e-05 * fTemp42) + (0.0002527901 * fTemp49)))))) - ((0.020893629 * fTemp40) + ((0.019916982499999999 * fTemp43) + ((0.1226840517 * fTemp46) + ((0.025910927800000001 * fTemp47) + (0.1005346163 * fTemp48)))))))));
			fRec1613[0] = (fRec1613[1] + fTemp355);
			fRec1611[0] = fRec1613[0];
			double fRec1612 = fTemp355;
			fRec1610[0] = (fRec1611[0] + fRec1610[1]);
			fRec1608[0] = fRec1610[0];
			double fRec1609 = fRec1612;
			double fTemp356 = (fConst23 * (0.0 - ((fConst25 * fRec1605[1]) + (fConst24 * fRec1602[1]))));
			fRec1607[0] = (fRec1609 + (fRec1607[1] + fTemp356));
			fRec1605[0] = fRec1607[0];
			double fRec1606 = (fRec1609 + fTemp356);
			fRec1604[0] = (fRec1605[0] + fRec1604[1]);
			fRec1602[0] = fRec1604[0];
			double fRec1603 = fRec1606;
			double fTemp357 = (fConst31 * fRec1599[1]);
			fRec1601[0] = ((fRec1603 + fRec1601[1]) - fTemp357);
			fRec1599[0] = fRec1601[0];
			double fRec1600 = (fRec1603 - fTemp357);
			fVec33[(IOTA & 1023)] = ((0.034715270499999999 * fTemp7) + (fRec1570 + (fRec1582 + (fRec1585 + (fRec1594 + fRec1600)))));
			output34[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec33[((IOTA - iConst32) & 1023)])));
			double fTemp358 = (fConst20 * ((0.0 - (((0.083163283599999999 * fTemp34) + (0.036774808499999999 * fTemp35)) + (0.035524734799999999 * fTemp36))) - (fConst21 * fRec1614[1])));
			fRec1616[0] = (fRec1616[1] + fTemp358);
			fRec1614[0] = fRec1616[0];
			double fRec1615 = fTemp358;
			double fTemp359 = (fConst17 * ((((0.072576879699999999 * fTemp28) + ((0.081891045499999995 * fTemp29) + (0.030998083799999999 * fTemp30))) - ((0.032562400399999997 * fTemp32) + (0.078359728399999995 * fTemp31))) + (fConst5 * (0.0 - ((fConst19 * fRec1620[1]) + (fConst18 * fRec1617[1]))))));
			fRec1622[0] = (fRec1622[1] + fTemp359);
			fRec1620[0] = fRec1622[0];
			double fRec1621 = fTemp359;
			fRec1619[0] = (fRec1620[0] + fRec1619[1]);
			fRec1617[0] = fRec1619[0];
			double fRec1618 = fRec1621;
			double fTemp360 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec1632[1]) + (fConst6 * fRec1629[1])))) + (fConst4 * (((0.0105385363 * fTemp10) + (0.0043141550999999997 * fTemp14)) - (((((((0.12738720619999999 * fTemp9) + (0.035746257099999998 * fTemp8)) + (0.0045201534999999996 * fTemp11)) + (0.039735932600000003 * fTemp12)) + (0.016963329199999998 * fTemp13)) + (0.095013438000000006 * fTemp15)) + (0.0056393744000000001 * fTemp16))))));
			fRec1634[0] = (fRec1634[1] + fTemp360);
			fRec1632[0] = fRec1634[0];
			double fRec1633 = fTemp360;
			fRec1631[0] = (fRec1632[0] + fRec1631[1]);
			fRec1629[0] = fRec1631[0];
			double fRec1630 = fRec1633;
			double fTemp361 = (fConst8 * (0.0 - ((fConst10 * fRec1626[1]) + (fConst9 * fRec1623[1]))));
			fRec1628[0] = (fRec1630 + (fRec1628[1] + fTemp361));
			fRec1626[0] = fRec1628[0];
			double fRec1627 = (fRec1630 + fTemp361);
			fRec1625[0] = (fRec1626[0] + fRec1625[1]);
			fRec1623[0] = fRec1625[0];
			double fRec1624 = fRec1627;
			double fTemp362 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec1641[1]) + (fConst12 * fRec1638[1])))) + (fConst15 * (((((((0.043941193599999998 * fTemp19) + (0.020674530999999999 * fTemp22)) + (0.043799094099999998 * fTemp23)) + (0.0088331616000000002 * fTemp24)) + (0.065469482800000006 * fTemp21)) + (0.11688296820000001 * fTemp25)) - (0.068400889600000001 * fTemp20)))));
			fRec1643[0] = (fRec1643[1] + fTemp362);
			fRec1641[0] = fRec1643[0];
			double fRec1642 = fTemp362;
			fRec1640[0] = (fRec1641[0] + fRec1640[1]);
			fRec1638[0] = fRec1640[0];
			double fRec1639 = fRec1642;
			double fTemp363 = (fConst16 * fRec1635[1]);
			fRec1637[0] = ((fRec1639 + fRec1637[1]) - fTemp363);
			fRec1635[0] = fRec1637[0];
			double fRec1636 = (fRec1639 - fTemp363);
			double fTemp364 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec1656[1]) + (fConst29 * fRec1653[1])))) + (fConst28 * (((0.018904471400000001 * fTemp44) + ((0.0017107581 * fTemp45) + ((0.1008031798 * fTemp41) + ((0.053264303899999997 * fTemp46) + ((0.0045042392000000002 * fTemp42) + (0.0044246687999999999 * fTemp48)))))) - ((0.0078237726000000007 * fTemp39) + ((0.0210000202 * fTemp40) + ((0.018293438299999999 * fTemp43) + ((0.018112879500000002 * fTemp47) + (0.1107816527 * fTemp49)))))))));
			fRec1658[0] = (fRec1658[1] + fTemp364);
			fRec1656[0] = fRec1658[0];
			double fRec1657 = fTemp364;
			fRec1655[0] = (fRec1656[0] + fRec1655[1]);
			fRec1653[0] = fRec1655[0];
			double fRec1654 = fRec1657;
			double fTemp365 = (fConst23 * (0.0 - ((fConst25 * fRec1650[1]) + (fConst24 * fRec1647[1]))));
			fRec1652[0] = (fRec1654 + (fRec1652[1] + fTemp365));
			fRec1650[0] = fRec1652[0];
			double fRec1651 = (fRec1654 + fTemp365);
			fRec1649[0] = (fRec1650[0] + fRec1649[1]);
			fRec1647[0] = fRec1649[0];
			double fRec1648 = fRec1651;
			double fTemp366 = (fConst31 * fRec1644[1]);
			fRec1646[0] = ((fRec1648 + fRec1646[1]) - fTemp366);
			fRec1644[0] = fRec1646[0];
			double fRec1645 = (fRec1648 - fTemp366);
			fVec34[(IOTA & 1023)] = ((0.034937794899999999 * fTemp7) + (fRec1615 + (fRec1618 + (fRec1624 + (fRec1636 + fRec1645)))));
			output35[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec34[((IOTA - iConst32) & 1023)])));
			double fTemp367 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec1665[1]) + (fConst12 * fRec1662[1])))) + (fConst15 * (((((0.015193916999999999 * fTemp22) + (0.042597784399999998 * fTemp23)) + (0.015866786300000001 * fTemp24)) + (0.081718515899999997 * fTemp25)) - (((0.091431474799999995 * fTemp19) + (0.092551866400000002 * fTemp20)) + (0.0032696553999999999 * fTemp21))))));
			fRec1667[0] = (fRec1667[1] + fTemp367);
			fRec1665[0] = fRec1667[0];
			double fRec1666 = fTemp367;
			fRec1664[0] = (fRec1665[0] + fRec1664[1]);
			fRec1662[0] = fRec1664[0];
			double fRec1663 = fRec1666;
			double fTemp368 = (fConst16 * fRec1659[1]);
			fRec1661[0] = ((fRec1663 + fRec1661[1]) - fTemp368);
			fRec1659[0] = fRec1661[0];
			double fRec1660 = (fRec1663 - fTemp368);
			double fTemp369 = (fConst17 * ((((0.0535121021 * fTemp28) + ((0.1108558581 * fTemp29) + ((0.055430892099999997 * fTemp30) + (0.0041147917999999999 * fTemp31)))) - (0.0317292645 * fTemp32)) + (fConst5 * (0.0 - ((fConst19 * fRec1671[1]) + (fConst18 * fRec1668[1]))))));
			fRec1673[0] = (fRec1673[1] + fTemp369);
			fRec1671[0] = fRec1673[0];
			double fRec1672 = fTemp369;
			fRec1670[0] = (fRec1671[0] + fRec1670[1]);
			fRec1668[0] = fRec1670[0];
			double fRec1669 = fRec1672;
			double fTemp370 = (fConst20 * ((0.0 - (((0.061302160100000003 * fTemp34) + (0.035917217799999998 * fTemp35)) + (0.063604866600000004 * fTemp36))) - (fConst21 * fRec1674[1])));
			fRec1676[0] = (fRec1676[1] + fTemp370);
			fRec1674[0] = fRec1676[0];
			double fRec1675 = fTemp370;
			double fTemp371 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec1686[1]) + (fConst6 * fRec1683[1])))) + (fConst4 * (((0.074106192599999995 * fTemp8) + ((0.0094690130000000001 * fTemp9) + (0.0104579676 * fTemp10))) - ((((((0.0061432557 * fTemp11) + (0.0292092571 * fTemp12)) + (0.030253774899999999 * fTemp13)) + (0.00039235790000000001 * fTemp14)) + (0.066624665599999994 * fTemp15)) + (0.1254790697 * fTemp16))))));
			fRec1688[0] = (fRec1688[1] + fTemp371);
			fRec1686[0] = fRec1688[0];
			double fRec1687 = fTemp371;
			fRec1685[0] = (fRec1686[0] + fRec1685[1]);
			fRec1683[0] = fRec1685[0];
			double fRec1684 = fRec1687;
			double fTemp372 = (fConst8 * (0.0 - ((fConst10 * fRec1680[1]) + (fConst9 * fRec1677[1]))));
			fRec1682[0] = (fRec1684 + (fRec1682[1] + fTemp372));
			fRec1680[0] = fRec1682[0];
			double fRec1681 = (fRec1684 + fTemp372);
			fRec1679[0] = (fRec1680[0] + fRec1679[1]);
			fRec1677[0] = fRec1679[0];
			double fRec1678 = fRec1681;
			double fTemp373 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec1701[1]) + (fConst29 * fRec1698[1])))) + (fConst28 * (((0.025506939199999999 * fTemp44) + ((0.077757611000000004 * fTemp46) + ((((0.0008671916 * fTemp47) + (0.0033302309999999999 * fTemp42)) + (0.099343018000000005 * fTemp48)) + (0.094150912000000003 * fTemp49)))) - (((((0.0070719531999999998 * fTemp41) + (0.0033282520999999999 * fTemp45)) + (0.013573474699999999 * fTemp43)) + (0.020555725600000001 * fTemp40)) + (0.014154738199999999 * fTemp39))))));
			fRec1703[0] = (fRec1703[1] + fTemp373);
			fRec1701[0] = fRec1703[0];
			double fRec1702 = fTemp373;
			fRec1700[0] = (fRec1701[0] + fRec1700[1]);
			fRec1698[0] = fRec1700[0];
			double fRec1699 = fRec1702;
			double fTemp374 = (fConst23 * (0.0 - ((fConst25 * fRec1695[1]) + (fConst24 * fRec1692[1]))));
			fRec1697[0] = (fRec1699 + (fRec1697[1] + fTemp374));
			fRec1695[0] = fRec1697[0];
			double fRec1696 = (fRec1699 + fTemp374);
			fRec1694[0] = (fRec1695[0] + fRec1694[1]);
			fRec1692[0] = fRec1694[0];
			double fRec1693 = fRec1696;
			double fTemp375 = (fConst31 * fRec1689[1]);
			fRec1691[0] = ((fRec1693 + fRec1691[1]) - fTemp375);
			fRec1689[0] = fRec1691[0];
			double fRec1690 = (fRec1693 - fTemp375);
			fVec35[(IOTA & 1023)] = ((0.0341170799 * fTemp7) + (fRec1660 + (fRec1669 + (fRec1675 + (fRec1678 + fRec1690)))));
			output36[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec35[((IOTA - iConst32) & 1023)])));
			double fTemp376 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec1716[1]) + (fConst29 * fRec1713[1])))) + (fConst28 * (((0.017112799599999999 * fTemp44) + ((0.017925386000000001 * fTemp47) + (0.038208615199999997 * fTemp49))) - ((0.017074836400000001 * fTemp39) + ((0.019715748299999999 * fTemp40) + ((0.0067874574000000003 * fTemp43) + ((0.0045151211 * fTemp45) + ((0.097220842599999996 * fTemp41) + ((0.11362972740000001 * fTemp46) + ((0.0020096923000000001 * fTemp42) + (0.0050553602999999997 * fTemp48))))))))))));
			fRec1718[0] = (fRec1718[1] + fTemp376);
			fRec1716[0] = fRec1718[0];
			double fRec1717 = fTemp376;
			fRec1715[0] = (fRec1716[0] + fRec1715[1]);
			fRec1713[0] = fRec1715[0];
			double fRec1714 = fRec1717;
			double fTemp377 = (fConst23 * (0.0 - ((fConst25 * fRec1710[1]) + (fConst24 * fRec1707[1]))));
			fRec1712[0] = (fRec1714 + (fRec1712[1] + fTemp377));
			fRec1710[0] = fRec1712[0];
			double fRec1711 = (fRec1714 + fTemp377);
			fRec1709[0] = (fRec1710[0] + fRec1709[1]);
			fRec1707[0] = fRec1709[0];
			double fRec1708 = fRec1711;
			double fTemp378 = (fConst31 * fRec1704[1]);
			fRec1706[0] = ((fRec1708 + fRec1706[1]) - fTemp378);
			fRec1704[0] = fRec1706[0];
			double fRec1705 = (fRec1708 - fTemp378);
			double fTemp379 = (fConst2 * ((fConst4 * (((((0.087657159700000001 * fTemp8) + ((0.12199520160000001 * fTemp9) + (0.0096611223999999996 * fTemp10))) + (0.040372783400000001 * fTemp15)) + (0.0066097552000000002 * fTemp16)) - ((((0.0037940165000000001 * fTemp11) + (0.0150329517 * fTemp12)) + (0.037602945499999998 * fTemp13)) + (0.0040568501000000003 * fTemp14)))) + (fConst5 * (0.0 - ((fConst7 * fRec1728[1]) + (fConst6 * fRec1725[1]))))));
			fRec1730[0] = (fRec1730[1] + fTemp379);
			fRec1728[0] = fRec1730[0];
			double fRec1729 = fTemp379;
			fRec1727[0] = (fRec1728[0] + fRec1727[1]);
			fRec1725[0] = fRec1727[0];
			double fRec1726 = fRec1729;
			double fTemp380 = (fConst8 * (0.0 - ((fConst10 * fRec1722[1]) + (fConst9 * fRec1719[1]))));
			fRec1724[0] = (fRec1726 + (fRec1724[1] + fTemp380));
			fRec1722[0] = fRec1724[0];
			double fRec1723 = (fRec1726 + fTemp380);
			fRec1721[0] = (fRec1722[0] + fRec1721[1]);
			fRec1719[0] = fRec1721[0];
			double fRec1720 = fRec1723;
			double fTemp381 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec1737[1]) + (fConst12 * fRec1734[1])))) + (fConst15 * ((((0.0076670577000000004 * fTemp22) + (0.040923574900000002 * fTemp23)) + (0.0192668228 * fTemp24)) - ((((0.1071969799 * fTemp19) + (0.061357396699999997 * fTemp20)) + (0.064627233100000001 * fTemp21)) + (0.049552894600000001 * fTemp25))))));
			fRec1739[0] = (fRec1739[1] + fTemp381);
			fRec1737[0] = fRec1739[0];
			double fRec1738 = fTemp381;
			fRec1736[0] = (fRec1737[0] + fRec1736[1]);
			fRec1734[0] = fRec1736[0];
			double fRec1735 = fRec1738;
			double fTemp382 = (fConst16 * fRec1731[1]);
			fRec1733[0] = ((fRec1735 + fRec1733[1]) - fTemp382);
			fRec1731[0] = fRec1733[0];
			double fRec1732 = (fRec1735 - fTemp382);
			double fTemp383 = (fConst20 * ((0.0 - (((0.031235452600000001 * fTemp34) + (0.034344568200000002 * fTemp35)) + (0.078344383300000001 * fTemp36))) - (fConst21 * fRec1740[1])));
			fRec1742[0] = (fRec1742[1] + fTemp383);
			fRec1740[0] = fRec1742[0];
			double fRec1741 = fTemp383;
			double fTemp384 = (fConst17 * ((((0.027370952099999998 * fTemp28) + ((0.073092530200000005 * fTemp29) + ((0.068587093000000002 * fTemp30) + (0.077108314900000002 * fTemp31)))) - (0.030214339 * fTemp32)) + (fConst5 * (0.0 - ((fConst19 * fRec1746[1]) + (fConst18 * fRec1743[1]))))));
			fRec1748[0] = (fRec1748[1] + fTemp384);
			fRec1746[0] = fRec1748[0];
			double fRec1747 = fTemp384;
			fRec1745[0] = (fRec1746[0] + fRec1745[1]);
			fRec1743[0] = fRec1745[0];
			double fRec1744 = fRec1747;
			fVec36[(IOTA & 1023)] = ((0.032537510300000003 * fTemp7) + (fRec1705 + (fRec1720 + (fRec1732 + (fRec1741 + fRec1744)))));
			output37[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec36[((IOTA - iConst32) & 1023)])));
			double fTemp385 = (fConst17 * ((((0.0765607695 * fTemp30) + (0.110333793 * fTemp31)) - (((0.0027476353000000001 * fTemp29) + (0.0009809586999999999 * fTemp28)) + (0.031608978900000001 * fTemp32))) + (fConst5 * (0.0 - ((fConst19 * fRec1752[1]) + (fConst18 * fRec1749[1]))))));
			fRec1754[0] = (fRec1754[1] + fTemp385);
			fRec1752[0] = fRec1754[0];
			double fRec1753 = fTemp385;
			fRec1751[0] = (fRec1752[0] + fRec1751[1]);
			fRec1749[0] = fRec1751[0];
			double fRec1750 = fRec1753;
			double fTemp386 = (fConst26 * ((fConst28 * (((0.00022133 * fTemp43) + ((0.00023837439999999999 * fTemp45) + ((0.0048849360999999999 * fTemp41) + ((0.0071471966 * fTemp46) + (0.0254021265 * fTemp47))))) - ((0.019532324199999999 * fTemp39) + ((0.0203956143 * fTemp40) + ((0.00067224090000000004 * fTemp44) + (((0.0046014903999999999 * fTemp42) + (0.0990964072 * fTemp48)) + (0.1216488535 * fTemp49))))))) + (fConst5 * (0.0 - ((fConst30 * fRec1767[1]) + (fConst29 * fRec1764[1]))))));
			fRec1769[0] = (fRec1769[1] + fTemp386);
			fRec1767[0] = fRec1769[0];
			double fRec1768 = fTemp386;
			fRec1766[0] = (fRec1767[0] + fRec1766[1]);
			fRec1764[0] = fRec1766[0];
			double fRec1765 = fRec1768;
			double fTemp387 = (fConst23 * (0.0 - ((fConst25 * fRec1761[1]) + (fConst24 * fRec1758[1]))));
			fRec1763[0] = (fRec1765 + (fRec1763[1] + fTemp387));
			fRec1761[0] = fRec1763[0];
			double fRec1762 = (fRec1765 + fTemp387);
			fRec1760[0] = (fRec1761[0] + fRec1760[1]);
			fRec1758[0] = fRec1760[0];
			double fRec1759 = fRec1762;
			double fTemp388 = (fConst31 * fRec1755[1]);
			fRec1757[0] = ((fRec1759 + fRec1757[1]) - fTemp388);
			fRec1755[0] = fRec1757[0];
			double fRec1756 = (fRec1759 - fTemp388);
			double fTemp389 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec1779[1]) + (fConst6 * fRec1776[1])))) + (fConst4 * (((((0.00054575070000000003 * fTemp12) + ((0.00010798389999999999 * fTemp11) + (0.0104017754 * fTemp10))) + (0.099092652700000006 * fTemp15)) + (0.1252646228 * fTemp16)) - ((((0.0060428516999999999 * fTemp9) + (0.0037369907000000002 * fTemp8)) + (0.041830830499999999 * fTemp13)) + (0.0062018825000000003 * fTemp14))))));
			fRec1781[0] = (fRec1781[1] + fTemp389);
			fRec1779[0] = fRec1781[0];
			double fRec1780 = fTemp389;
			fRec1778[0] = (fRec1779[0] + fRec1778[1]);
			fRec1776[0] = fRec1778[0];
			double fRec1777 = fRec1780;
			double fTemp390 = (fConst8 * (0.0 - ((fConst10 * fRec1773[1]) + (fConst9 * fRec1770[1]))));
			fRec1775[0] = (fRec1777 + (fRec1775[1] + fTemp390));
			fRec1773[0] = fRec1775[0];
			double fRec1774 = (fRec1777 + fTemp390);
			fRec1772[0] = (fRec1773[0] + fRec1772[1]);
			fRec1770[0] = fRec1772[0];
			double fRec1771 = fRec1774;
			double fTemp391 = (fConst20 * (((0.0011029233999999999 * fTemp34) - ((0.035671842299999999 * fTemp35) + (0.087839536600000004 * fTemp36))) - (fConst21 * fRec1782[1])));
			fRec1784[0] = (fRec1784[1] + fTemp391);
			fRec1782[0] = fRec1784[0];
			double fRec1783 = fTemp391;
			double fTemp392 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec1791[1]) + (fConst12 * fRec1788[1])))) + (fConst15 * (((((0.0044979874000000003 * fTemp19) + (0.0023437961 * fTemp20)) + (0.042377515499999997 * fTemp23)) + (0.021923963800000001 * fTemp24)) - (((0.00025627810000000001 * fTemp22) + (0.092052438400000006 * fTemp21)) + (0.1220087285 * fTemp25))))));
			fRec1793[0] = (fRec1793[1] + fTemp392);
			fRec1791[0] = fRec1793[0];
			double fRec1792 = fTemp392;
			fRec1790[0] = (fRec1791[0] + fRec1790[1]);
			fRec1788[0] = fRec1790[0];
			double fRec1789 = fRec1792;
			double fTemp393 = (fConst16 * fRec1785[1]);
			fRec1787[0] = ((fRec1789 + fRec1787[1]) - fTemp393);
			fRec1785[0] = fRec1787[0];
			double fRec1786 = (fRec1789 - fTemp393);
			fVec37[(IOTA & 1023)] = ((0.033914586699999999 * fTemp7) + (fRec1750 + (fRec1756 + (fRec1771 + (fRec1783 + fRec1786)))));
			output38[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec37[((IOTA - iConst32) & 1023)])));
			double fTemp394 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec1803[1]) + (fConst6 * fRec1800[1])))) + (fConst4 * ((((0.016562508600000001 * fTemp12) + ((0.0042355329000000001 * fTemp11) + (0.0101555443 * fTemp10))) + (0.036137453 * fTemp15)) - (((((0.12569968919999999 * fTemp9) + (0.093474679000000005 * fTemp8)) + (0.0391794684 * fTemp13)) + (0.0039392641000000001 * fTemp14)) + (0.0044471913999999998 * fTemp16))))));
			fRec1805[0] = (fRec1805[1] + fTemp394);
			fRec1803[0] = fRec1805[0];
			double fRec1804 = fTemp394;
			fRec1802[0] = (fRec1803[0] + fRec1802[1]);
			fRec1800[0] = fRec1802[0];
			double fRec1801 = fRec1804;
			double fTemp395 = (fConst8 * (0.0 - ((fConst10 * fRec1797[1]) + (fConst9 * fRec1794[1]))));
			fRec1799[0] = (fRec1801 + (fRec1799[1] + fTemp395));
			fRec1797[0] = fRec1799[0];
			double fRec1798 = (fRec1801 + fTemp395);
			fRec1796[0] = (fRec1797[0] + fRec1796[1]);
			fRec1794[0] = fRec1796[0];
			double fRec1795 = fRec1798;
			double fTemp396 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec1812[1]) + (fConst12 * fRec1809[1])))) + (fConst15 * (((((0.1145522271 * fTemp19) + (0.066932450500000004 * fTemp20)) + (0.043009347400000002 * fTemp23)) + (0.0199841155 * fTemp24)) - (((0.0085181396999999999 * fTemp22) + (0.064869799399999997 * fTemp21)) + (0.044014614899999999 * fTemp25))))));
			fRec1814[0] = (fRec1814[1] + fTemp396);
			fRec1812[0] = fRec1814[0];
			double fRec1813 = fTemp396;
			fRec1811[0] = (fRec1812[0] + fRec1811[1]);
			fRec1809[0] = fRec1811[0];
			double fRec1810 = fRec1813;
			double fTemp397 = (fConst16 * fRec1806[1]);
			fRec1808[0] = ((fRec1810 + fRec1808[1]) - fTemp397);
			fRec1806[0] = fRec1808[0];
			double fRec1807 = (fRec1810 - fTemp397);
			double fTemp398 = (fConst17 * ((((0.071427952700000005 * fTemp30) + (0.0772341322 * fTemp31)) - (((0.079891127899999997 * fTemp29) + (0.030240653999999999 * fTemp28)) + (0.031715759900000001 * fTemp32))) + (fConst5 * (0.0 - ((fConst19 * fRec1818[1]) + (fConst18 * fRec1815[1]))))));
			fRec1820[0] = (fRec1820[1] + fTemp398);
			fRec1818[0] = fRec1820[0];
			double fRec1819 = fTemp398;
			fRec1817[0] = (fRec1818[0] + fRec1817[1]);
			fRec1815[0] = fRec1817[0];
			double fRec1816 = fRec1819;
			double fTemp399 = (fConst20 * (((0.034568476700000003 * fTemp34) - ((0.036137616599999998 * fTemp35) + (0.081525693900000001 * fTemp36))) - (fConst21 * fRec1821[1])));
			fRec1823[0] = (fRec1823[1] + fTemp399);
			fRec1821[0] = fRec1823[0];
			double fRec1822 = fTemp399;
			double fTemp400 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec1836[1]) + (fConst29 * fRec1833[1])))) + (fConst28 * (((0.0075650915999999997 * fTemp43) + ((0.0046983359000000004 * fTemp45) + ((0.099969590600000005 * fTemp41) + ((0.1103593916 * fTemp46) + (((0.018071708799999999 * fTemp47) + (0.0032433421999999998 * fTemp48)) + (0.051734068500000001 * fTemp49)))))) - ((0.0176760844 * fTemp39) + ((0.0208114779 * fTemp40) + ((0.018579713500000001 * fTemp44) + (0.002005944 * fTemp42))))))));
			fRec1838[0] = (fRec1838[1] + fTemp400);
			fRec1836[0] = fRec1838[0];
			double fRec1837 = fTemp400;
			fRec1835[0] = (fRec1836[0] + fRec1835[1]);
			fRec1833[0] = fRec1835[0];
			double fRec1834 = fRec1837;
			double fTemp401 = (fConst23 * (0.0 - ((fConst25 * fRec1830[1]) + (fConst24 * fRec1827[1]))));
			fRec1832[0] = (fRec1834 + (fRec1832[1] + fTemp401));
			fRec1830[0] = fRec1832[0];
			double fRec1831 = (fRec1834 + fTemp401);
			fRec1829[0] = (fRec1830[0] + fRec1829[1]);
			fRec1827[0] = fRec1829[0];
			double fRec1828 = fRec1831;
			double fTemp402 = (fConst31 * fRec1824[1]);
			fRec1826[0] = ((fRec1828 + fRec1826[1]) - fTemp402);
			fRec1824[0] = fRec1826[0];
			double fRec1825 = (fRec1828 - fTemp402);
			fVec38[(IOTA & 1023)] = ((0.034211823400000001 * fTemp7) + (fRec1795 + (fRec1807 + (fRec1816 + (fRec1822 + fRec1825)))));
			output39[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec38[((IOTA - iConst32) & 1023)])));
			double fTemp403 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec1851[1]) + (fConst29 * fRec1848[1])))) + (fConst28 * (((0.013261622400000001 * fTemp43) + ((0.0031690543999999998 * fTemp45) + (((0.0034500829 * fTemp42) + (0.097225752700000001 * fTemp48)) + (0.081856571700000005 * fTemp49)))) - ((0.013102436800000001 * fTemp39) + ((0.019614823999999999 * fTemp40) + ((0.024653400400000001 * fTemp44) + ((0.0029183333000000001 * fTemp41) + ((0.0879460304 * fTemp46) + (0.00036273060000000001 * fTemp47))))))))));
			fRec1853[0] = (fRec1853[1] + fTemp403);
			fRec1851[0] = fRec1853[0];
			double fRec1852 = fTemp403;
			fRec1850[0] = (fRec1851[0] + fRec1850[1]);
			fRec1848[0] = fRec1850[0];
			double fRec1849 = fRec1852;
			double fTemp404 = (fConst23 * (0.0 - ((fConst25 * fRec1845[1]) + (fConst24 * fRec1842[1]))));
			fRec1847[0] = (fRec1849 + (fRec1847[1] + fTemp404));
			fRec1845[0] = fRec1847[0];
			double fRec1846 = (fRec1849 + fTemp404);
			fRec1844[0] = (fRec1845[0] + fRec1844[1]);
			fRec1842[0] = fRec1844[0];
			double fRec1843 = fRec1846;
			double fTemp405 = (fConst31 * fRec1839[1]);
			fRec1841[0] = ((fRec1843 + fRec1841[1]) - fTemp405);
			fRec1839[0] = fRec1841[0];
			double fRec1840 = (fRec1843 - fTemp405);
			double fTemp406 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec1863[1]) + (fConst6 * fRec1860[1])))) + (fConst4 * ((((0.028783856399999998 * fTemp12) + ((0.0058101762999999999 * fTemp11) + ((0.0035142791 * fTemp9) + (0.0098434149999999995 * fTemp10)))) + (2.3346800000000002e-05 * fTemp14)) - ((((0.066658692899999997 * fTemp8) + (0.028359543399999999 * fTemp13)) + (0.069721839499999994 * fTemp15)) + (0.1224423573 * fTemp16))))));
			fRec1865[0] = (fRec1865[1] + fTemp406);
			fRec1863[0] = fRec1865[0];
			double fRec1864 = fTemp406;
			fRec1862[0] = (fRec1863[0] + fRec1862[1]);
			fRec1860[0] = fRec1862[0];
			double fRec1861 = fRec1864;
			double fTemp407 = (fConst8 * (0.0 - ((fConst10 * fRec1857[1]) + (fConst9 * fRec1854[1]))));
			fRec1859[0] = (fRec1861 + (fRec1859[1] + fTemp407));
			fRec1857[0] = fRec1859[0];
			double fRec1858 = (fRec1861 + fTemp407);
			fRec1856[0] = (fRec1857[0] + fRec1856[1]);
			fRec1854[0] = fRec1856[0];
			double fRec1855 = fRec1858;
			double fTemp408 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec1872[1]) + (fConst12 * fRec1869[1])))) + (fConst15 * (((((((0.081919764500000006 * fTemp19) + (0.089090429700000001 * fTemp20)) + (0.040893681000000001 * fTemp23)) + (0.0147467681 * fTemp24)) + (0.0013331096000000001 * fTemp21)) + (0.085528738399999998 * fTemp25)) - (0.014927490200000001 * fTemp22)))));
			fRec1874[0] = (fRec1874[1] + fTemp408);
			fRec1872[0] = fRec1874[0];
			double fRec1873 = fTemp408;
			fRec1871[0] = (fRec1872[0] + fRec1871[1]);
			fRec1869[0] = fRec1871[0];
			double fRec1870 = fRec1873;
			double fTemp409 = (fConst16 * fRec1866[1]);
			fRec1868[0] = ((fRec1870 + fRec1868[1]) - fTemp409);
			fRec1866[0] = fRec1868[0];
			double fRec1867 = (fRec1870 - fTemp409);
			double fTemp410 = (fConst20 * (((0.060240385600000002 * fTemp34) - ((0.034357911499999998 * fTemp35) + (0.059376598099999997 * fTemp36))) - (fConst21 * fRec1875[1])));
			fRec1877[0] = (fRec1877[1] + fTemp410);
			fRec1875[0] = fRec1877[0];
			double fRec1876 = fTemp410;
			double fTemp411 = (fConst17 * (((0.051832372600000003 * fTemp30) - ((0.030378854600000001 * fTemp32) + ((0.052613223100000002 * fTemp28) + ((0.10654592810000001 * fTemp29) + (0.001534299 * fTemp31))))) + (fConst5 * (0.0 - ((fConst19 * fRec1881[1]) + (fConst18 * fRec1878[1]))))));
			fRec1883[0] = (fRec1883[1] + fTemp411);
			fRec1881[0] = fRec1883[0];
			double fRec1882 = fTemp411;
			fRec1880[0] = (fRec1881[0] + fRec1880[1]);
			fRec1878[0] = fRec1880[0];
			double fRec1879 = fRec1882;
			fVec39[(IOTA & 1023)] = ((0.032625369799999998 * fTemp7) + (fRec1840 + (fRec1855 + (fRec1867 + (fRec1876 + fRec1879)))));
			output40[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec39[((IOTA - iConst32) & 1023)])));
			double fTemp412 = (fConst20 * (((0.075912750299999998 * fTemp34) - ((0.033586229099999997 * fTemp35) + (0.032500149499999999 * fTemp36))) - (fConst21 * fRec1884[1])));
			fRec1886[0] = (fRec1886[1] + fTemp412);
			fRec1884[0] = fRec1886[0];
			double fRec1885 = fTemp412;
			double fTemp413 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec1899[1]) + (fConst29 * fRec1896[1])))) + (fConst28 * (((0.016714340300000002 * fTemp43) + ((0.0043939134000000003 * fTemp42) + (0.0044831803000000003 * fTemp48))) - ((0.0071344001000000004 * fTemp39) + ((0.0194061105 * fTemp40) + ((0.017606555499999999 * fTemp44) + ((0.0016470249000000001 * fTemp45) + ((0.095917633799999999 * fTemp41) + ((0.051806169399999998 * fTemp46) + ((0.016755737400000002 * fTemp47) + (0.10707020339999999 * fTemp49))))))))))));
			fRec1901[0] = (fRec1901[1] + fTemp413);
			fRec1899[0] = fRec1901[0];
			double fRec1900 = fTemp413;
			fRec1898[0] = (fRec1899[0] + fRec1898[1]);
			fRec1896[0] = fRec1898[0];
			double fRec1897 = fRec1900;
			double fTemp414 = (fConst23 * (0.0 - ((fConst25 * fRec1893[1]) + (fConst24 * fRec1890[1]))));
			fRec1895[0] = (fRec1897 + (fRec1895[1] + fTemp414));
			fRec1893[0] = fRec1895[0];
			double fRec1894 = (fRec1897 + fTemp414);
			fRec1892[0] = (fRec1893[0] + fRec1892[1]);
			fRec1890[0] = fRec1892[0];
			double fRec1891 = fRec1894;
			double fTemp415 = (fConst31 * fRec1887[1]);
			fRec1889[0] = ((fRec1891 + fRec1889[1]) - fTemp415);
			fRec1887[0] = fRec1889[0];
			double fRec1888 = (fRec1891 - fTemp415);
			double fTemp416 = (fConst2 * ((fConst4 * ((((0.0363760313 * fTemp12) + ((0.0040761707000000003 * fTemp11) + ((0.0331591314 * fTemp8) + ((0.1204740253 * fTemp9) + (0.0096749307000000007 * fTemp10))))) + (0.0038757999 * fTemp14)) - (((0.015591934 * fTemp13) + (0.088786852799999996 * fTemp15)) + (0.0056351897000000003 * fTemp16)))) + (fConst5 * (0.0 - ((fConst7 * fRec1911[1]) + (fConst6 * fRec1908[1]))))));
			fRec1913[0] = (fRec1913[1] + fTemp416);
			fRec1911[0] = fRec1913[0];
			double fRec1912 = fTemp416;
			fRec1910[0] = (fRec1911[0] + fRec1910[1]);
			fRec1908[0] = fRec1910[0];
			double fRec1909 = fRec1912;
			double fTemp417 = (fConst8 * (0.0 - ((fConst10 * fRec1905[1]) + (fConst9 * fRec1902[1]))));
			fRec1907[0] = (fRec1909 + (fRec1907[1] + fTemp417));
			fRec1905[0] = fRec1907[0];
			double fRec1906 = (fRec1909 + fTemp417);
			fRec1904[0] = (fRec1905[0] + fRec1904[1]);
			fRec1902[0] = fRec1904[0];
			double fRec1903 = fRec1906;
			double fTemp418 = (fConst17 * (((0.0284112945 * fTemp30) - ((0.029573968799999999 * fTemp32) + ((0.066366705999999998 * fTemp28) + ((0.075395823099999995 * fTemp29) + (0.071918978999999994 * fTemp31))))) + (fConst5 * (0.0 - ((fConst19 * fRec1917[1]) + (fConst18 * fRec1914[1]))))));
			fRec1919[0] = (fRec1919[1] + fTemp418);
			fRec1917[0] = fRec1919[0];
			double fRec1918 = fTemp418;
			fRec1916[0] = (fRec1917[0] + fRec1916[1]);
			fRec1914[0] = fRec1916[0];
			double fRec1915 = fRec1918;
			double fTemp419 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec1926[1]) + (fConst12 * fRec1923[1])))) + (fConst15 * ((((((0.063138587400000001 * fTemp20) + (0.0399058755 * fTemp23)) + (0.0080503082999999996 * fTemp24)) + (0.060227644800000001 * fTemp21)) + (0.1087938522 * fTemp25)) - ((0.040632101099999998 * fTemp19) + (0.018783130700000001 * fTemp22))))));
			fRec1928[0] = (fRec1928[1] + fTemp419);
			fRec1926[0] = fRec1928[0];
			double fRec1927 = fTemp419;
			fRec1925[0] = (fRec1926[0] + fRec1925[1]);
			fRec1923[0] = fRec1925[0];
			double fRec1924 = fRec1927;
			double fTemp420 = (fConst16 * fRec1920[1]);
			fRec1922[0] = ((fRec1924 + fRec1922[1]) - fTemp420);
			fRec1920[0] = fRec1922[0];
			double fRec1921 = (fRec1924 - fTemp420);
			fVec40[(IOTA & 1023)] = ((0.031844484800000003 * fTemp7) + (fRec1885 + (fRec1888 + (fRec1903 + (fRec1915 + fRec1921)))));
			output41[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec40[((IOTA - iConst32) & 1023)])));
			double fTemp421 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec1941[1]) + (fConst29 * fRec1938[1])))) + (fConst28 * (((0.019113863200000001 * fTemp43) + ((0.1205410942 * fTemp46) + (0.00018720290000000001 * fTemp42))) - ((0.00040752179999999999 * fTemp39) + ((0.019955841500000002 * fTemp40) + ((0.0008850803 * fTemp44) + ((0.0045927842999999996 * fTemp45) + ((0.0077209805000000003 * fTemp41) + (((0.0250377419 * fTemp47) + (0.098040843200000005 * fTemp48)) + (0.0124068553 * fTemp49)))))))))));
			fRec1943[0] = (fRec1943[1] + fTemp421);
			fRec1941[0] = fRec1943[0];
			double fRec1942 = fTemp421;
			fRec1940[0] = (fRec1941[0] + fRec1940[1]);
			fRec1938[0] = fRec1940[0];
			double fRec1939 = fRec1942;
			double fTemp422 = (fConst23 * (0.0 - ((fConst25 * fRec1935[1]) + (fConst24 * fRec1932[1]))));
			fRec1937[0] = (fRec1939 + (fRec1937[1] + fTemp422));
			fRec1935[0] = fRec1937[0];
			double fRec1936 = (fRec1939 + fTemp422);
			fRec1934[0] = (fRec1935[0] + fRec1934[1]);
			fRec1932[0] = fRec1934[0];
			double fRec1933 = fRec1936;
			double fTemp423 = (fConst31 * fRec1929[1]);
			fRec1931[0] = ((fRec1933 + fRec1931[1]) - fTemp423);
			fRec1929[0] = fRec1931[0];
			double fRec1930 = (fRec1933 - fTemp423);
			double fTemp424 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec1953[1]) + (fConst6 * fRec1950[1])))) + (fConst4 * (((((0.041185025399999999 * fTemp12) + ((0.00028976499999999999 * fTemp11) + ((0.097766724299999996 * fTemp8) + ((0.010012856699999999 * fTemp9) + (0.0101201165 * fTemp10))))) + (0.0060592987000000001 * fTemp14)) + (0.1237535315 * fTemp16)) - ((0.00076584769999999997 * fTemp13) + (0.0057082460000000002 * fTemp15))))));
			fRec1955[0] = (fRec1955[1] + fTemp424);
			fRec1953[0] = fRec1955[0];
			double fRec1954 = fTemp424;
			fRec1952[0] = (fRec1953[0] + fRec1952[1]);
			fRec1950[0] = fRec1952[0];
			double fRec1951 = fRec1954;
			double fTemp425 = (fConst8 * (0.0 - ((fConst10 * fRec1947[1]) + (fConst9 * fRec1944[1]))));
			fRec1949[0] = (fRec1951 + (fRec1949[1] + fTemp425));
			fRec1947[0] = fRec1949[0];
			double fRec1948 = (fRec1951 + fTemp425);
			fRec1946[0] = (fRec1947[0] + fRec1946[1]);
			fRec1944[0] = fRec1946[0];
			double fRec1945 = fRec1948;
			double fTemp426 = (fConst11 * ((fConst5 * (0.0 - ((fConst13 * fRec1962[1]) + (fConst12 * fRec1959[1])))) + (fConst15 * ((((((0.0035046299999999999 * fTemp20) + (0.041731580300000001 * fTemp23)) + (0.0004438941 * fTemp24)) + (0.090649313999999995 * fTemp21)) + (0.0072027953999999998 * fTemp25)) - ((0.1202623352 * fTemp19) + (0.021536670399999999 * fTemp22))))));
			fRec1964[0] = (fRec1964[1] + fTemp426);
			fRec1962[0] = fRec1964[0];
			double fRec1963 = fTemp426;
			fRec1961[0] = (fRec1962[0] + fRec1961[1]);
			fRec1959[0] = fRec1961[0];
			double fRec1960 = fRec1963;
			double fTemp427 = (fConst16 * fRec1956[1]);
			fRec1958[0] = ((fRec1960 + fRec1958[1]) - fTemp427);
			fRec1956[0] = fRec1958[0];
			double fRec1957 = (fRec1960 - fTemp427);
			double fTemp428 = (fConst20 * (((0.086360519100000005 * fTemp34) - ((0.035053516799999997 * fTemp35) + (0.0016977392 * fTemp36))) - (fConst21 * fRec1965[1])));
			fRec1967[0] = (fRec1967[1] + fTemp428);
			fRec1965[0] = fRec1967[0];
			double fRec1966 = fTemp428;
			double fTemp429 = (fConst17 * (((0.0014508849 * fTemp30) - ((0.031093106799999999 * fTemp32) + ((0.075304494900000005 * fTemp28) + ((0.0042952473 * fTemp29) + (0.10858048820000001 * fTemp31))))) + (fConst5 * (0.0 - ((fConst19 * fRec1971[1]) + (fConst18 * fRec1968[1]))))));
			fRec1973[0] = (fRec1973[1] + fTemp429);
			fRec1971[0] = fRec1973[0];
			double fRec1972 = fTemp429;
			fRec1970[0] = (fRec1971[0] + fRec1970[1]);
			fRec1968[0] = fRec1970[0];
			double fRec1969 = fRec1972;
			fVec41[(IOTA & 1023)] = ((0.033327394599999997 * fTemp7) + (fRec1930 + (fRec1945 + (fRec1957 + (fRec1966 + fRec1969)))));
			output42[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec41[((IOTA - iConst32) & 1023)])));
			double fTemp430 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec1986[1]) + (fConst29 * fRec1983[1])))) + (fConst28 * (((0.0068476869999999999 * fTemp39) + ((0.017879387600000001 * fTemp43) + ((0.016952188600000001 * fTemp44) + ((0.098701813200000002 * fTemp41) + (0.1177098412 * fTemp49))))) - ((0.0205588409 * fTemp40) + ((0.0024804943999999999 * fTemp45) + ((0.030090076899999998 * fTemp46) + (((0.0191887221 * fTemp47) + (0.0043632295999999999 * fTemp42)) + (0.0117284768 * fTemp48)))))))));
			fRec1988[0] = (fRec1988[1] + fTemp430);
			fRec1986[0] = fRec1988[0];
			double fRec1987 = fTemp430;
			fRec1985[0] = (fRec1986[0] + fRec1985[1]);
			fRec1983[0] = fRec1985[0];
			double fRec1984 = fRec1987;
			double fTemp431 = (fConst23 * (0.0 - ((fConst25 * fRec1980[1]) + (fConst24 * fRec1977[1]))));
			fRec1982[0] = (fRec1984 + (fRec1982[1] + fTemp431));
			fRec1980[0] = fRec1982[0];
			double fRec1981 = (fRec1984 + fTemp431);
			fRec1979[0] = (fRec1980[0] + fRec1979[1]);
			fRec1977[0] = fRec1979[0];
			double fRec1978 = fRec1981;
			double fTemp432 = (fConst31 * fRec1974[1]);
			fRec1976[0] = ((fRec1978 + fRec1976[1]) - fTemp432);
			fRec1974[0] = fRec1976[0];
			double fRec1975 = (fRec1978 - fTemp432);
			double fTemp433 = (fConst11 * ((fConst15 * (((0.0424463983 * fTemp23) + (0.068959401700000006 * fTemp21)) - (((((0.056140290400000001 * fTemp19) + (0.061193656499999999 * fTemp20)) + (0.020110795899999999 * fTemp22)) + (0.0077010723999999999 * fTemp24)) + (0.1079479191 * fTemp25)))) + (fConst5 * (0.0 - ((fConst13 * fRec1995[1]) + (fConst12 * fRec1992[1]))))));
			fRec1997[0] = (fRec1997[1] + fTemp433);
			fRec1995[0] = fRec1997[0];
			double fRec1996 = fTemp433;
			fRec1994[0] = (fRec1995[0] + fRec1994[1]);
			fRec1992[0] = fRec1994[0];
			double fRec1993 = fRec1996;
			double fTemp434 = (fConst16 * fRec1989[1]);
			fRec1991[0] = ((fRec1993 + fRec1991[1]) - fTemp434);
			fRec1989[0] = fRec1991[0];
			double fRec1990 = (fRec1993 - fTemp434);
			double fTemp435 = (fConst2 * ((fConst4 * (((((((0.039251706099999999 * fTemp12) + ((0.046021255499999997 * fTemp8) + (0.010129830500000001 * fTemp10))) + (0.014887686400000001 * fTemp13)) + (0.0042512862 * fTemp14)) + (0.088005270400000002 * fTemp15)) + (0.0143446081 * fTemp16)) - ((0.1241702984 * fTemp9) + (0.0039344007 * fTemp11)))) + (fConst5 * (0.0 - ((fConst7 * fRec2007[1]) + (fConst6 * fRec2004[1]))))));
			fRec2009[0] = (fRec2009[1] + fTemp435);
			fRec2007[0] = fRec2009[0];
			double fRec2008 = fTemp435;
			fRec2006[0] = (fRec2007[0] + fRec2006[1]);
			fRec2004[0] = fRec2006[0];
			double fRec2005 = fRec2008;
			double fTemp436 = (fConst8 * (0.0 - ((fConst10 * fRec2001[1]) + (fConst9 * fRec1998[1]))));
			fRec2003[0] = (fRec2005 + (fRec2003[1] + fTemp436));
			fRec2001[0] = fRec2003[0];
			double fRec2002 = (fRec2005 + fTemp436);
			fRec2000[0] = (fRec2001[0] + fRec2000[1]);
			fRec1998[0] = fRec2000[0];
			double fRec1999 = fRec2002;
			double fTemp437 = (fConst20 * ((((0.081848376400000006 * fTemp34) + (0.031132243 * fTemp36)) - (0.035705976 * fTemp35)) - (fConst21 * fRec2010[1])));
			fRec2012[0] = (fRec2012[1] + fTemp437);
			fRec2010[0] = fRec2012[0];
			double fRec2011 = fTemp437;
			double fTemp438 = (fConst17 * (((0.073120721400000005 * fTemp29) - ((0.031363623100000002 * fTemp32) + ((0.071655394799999994 * fTemp28) + ((0.0272042524 * fTemp30) + (0.082173226299999999 * fTemp31))))) + (fConst5 * (0.0 - ((fConst19 * fRec2016[1]) + (fConst18 * fRec2013[1]))))));
			fRec2018[0] = (fRec2018[1] + fTemp438);
			fRec2016[0] = fRec2018[0];
			double fRec2017 = fTemp438;
			fRec2015[0] = (fRec2016[0] + fRec2015[1]);
			fRec2013[0] = fRec2015[0];
			double fRec2014 = fRec2017;
			fVec42[(IOTA & 1023)] = ((0.033821688199999998 * fTemp7) + (fRec1975 + (fRec1990 + (fRec1999 + (fRec2011 + fRec2014)))));
			output43[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec42[((IOTA - iConst32) & 1023)])));
			double fTemp439 = (fConst11 * ((fConst15 * ((((0.078690439900000006 * fTemp19) + (0.041763714100000002 * fTemp23)) + (0.0046966083999999998 * fTemp21)) - ((((0.09078485 * fTemp20) + (0.015760371200000001 * fTemp22)) + (0.0150048179 * fTemp24)) + (0.091834241999999996 * fTemp25)))) + (fConst5 * (0.0 - ((fConst13 * fRec2025[1]) + (fConst12 * fRec2022[1]))))));
			fRec2027[0] = (fRec2027[1] + fTemp439);
			fRec2025[0] = fRec2027[0];
			double fRec2026 = fTemp439;
			fRec2024[0] = (fRec2025[0] + fRec2024[1]);
			fRec2022[0] = fRec2024[0];
			double fRec2023 = fRec2026;
			double fTemp440 = (fConst16 * fRec2019[1]);
			fRec2021[0] = ((fRec2023 + fRec2021[1]) - fTemp440);
			fRec2019[0] = fRec2021[0];
			double fRec2020 = (fRec2023 - fTemp440);
			double fTemp441 = (fConst2 * ((fConst5 * (0.0 - ((fConst7 * fRec2037[1]) + (fConst6 * fRec2034[1])))) + (fConst4 * ((((((0.029886265799999999 * fTemp12) + (0.010351217399999999 * fTemp10)) + (0.028387725900000001 * fTemp13)) + (0.000263661 * fTemp14)) + (0.074542319600000004 * fTemp15)) - ((((0.012799093500000001 * fTemp9) + (0.063761432699999995 * fTemp8)) + (0.0062580952999999996 * fTemp11)) + (0.1239022935 * fTemp16))))));
			fRec2039[0] = (fRec2039[1] + fTemp441);
			fRec2037[0] = fRec2039[0];
			double fRec2038 = fTemp441;
			fRec2036[0] = (fRec2037[0] + fRec2036[1]);
			fRec2034[0] = fRec2036[0];
			double fRec2035 = fRec2038;
			double fTemp442 = (fConst8 * (0.0 - ((fConst10 * fRec2031[1]) + (fConst9 * fRec2028[1]))));
			fRec2033[0] = (fRec2035 + (fRec2033[1] + fTemp442));
			fRec2031[0] = fRec2033[0];
			double fRec2032 = (fRec2035 + fTemp442);
			fRec2030[0] = (fRec2031[0] + fRec2030[1]);
			fRec2028[0] = fRec2030[0];
			double fRec2029 = fRec2032;
			double fTemp443 = (fConst20 * ((((0.062885901499999994 * fTemp34) + (0.059749737599999998 * fTemp36)) - (0.035164316100000002 * fTemp35)) - (fConst21 * fRec2040[1])));
			fRec2042[0] = (fRec2042[1] + fTemp443);
			fRec2040[0] = fRec2042[0];
			double fRec2041 = fTemp443;
			double fTemp444 = (fConst17 * (((0.1089713154 * fTemp29) - ((0.031249748899999999 * fTemp32) + ((0.054748380399999998 * fTemp28) + ((0.051994365600000002 * fTemp30) + (0.0055815854000000002 * fTemp31))))) + (fConst5 * (0.0 - ((fConst19 * fRec2046[1]) + (fConst18 * fRec2043[1]))))));
			fRec2048[0] = (fRec2048[1] + fTemp444);
			fRec2046[0] = fRec2048[0];
			double fRec2047 = fTemp444;
			fRec2045[0] = (fRec2046[0] + fRec2045[1]);
			fRec2043[0] = fRec2045[0];
			double fRec2044 = fRec2047;
			double fTemp445 = (fConst26 * ((fConst5 * (0.0 - ((fConst30 * fRec2061[1]) + (fConst29 * fRec2058[1])))) + (fConst28 * (((0.0133822104 * fTemp39) + ((0.014054109699999999 * fTemp43) + ((0.025002578599999999 * fTemp44) + ((0.0028077201000000001 * fTemp45) + ((0.010246589400000001 * fTemp41) + (0.097904613599999996 * fTemp48)))))) - ((0.020043353199999999 * fTemp40) + ((0.096253844699999994 * fTemp46) + (((0.0012832570999999999 * fTemp47) + (0.0034272063 * fTemp42)) + (0.074096782599999994 * fTemp49))))))));
			fRec2063[0] = (fRec2063[1] + fTemp445);
			fRec2061[0] = fRec2063[0];
			double fRec2062 = fTemp445;
			fRec2060[0] = (fRec2061[0] + fRec2060[1]);
			fRec2058[0] = fRec2060[0];
			double fRec2059 = fRec2062;
			double fTemp446 = (fConst23 * (0.0 - ((fConst25 * fRec2055[1]) + (fConst24 * fRec2052[1]))));
			fRec2057[0] = (fRec2059 + (fRec2057[1] + fTemp446));
			fRec2055[0] = fRec2057[0];
			double fRec2056 = (fRec2059 + fTemp446);
			fRec2054[0] = (fRec2055[0] + fRec2054[1]);
			fRec2052[0] = fRec2054[0];
			double fRec2053 = fRec2056;
			double fTemp447 = (fConst31 * fRec2049[1]);
			fRec2051[0] = ((fRec2053 + fRec2051[1]) - fTemp447);
			fRec2049[0] = fRec2051[0];
			double fRec2050 = (fRec2053 - fTemp447);
			fVec43[(IOTA & 1023)] = ((0.033472444300000001 * fTemp7) + (fRec2020 + (fRec2029 + (fRec2041 + (fRec2044 + fRec2050)))));
			output44[i] = FAUSTFLOAT((0.8267575322812053 * (fRec0[0] * fVec43[((IOTA - iConst32) & 1023)])));
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
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec15[1] = fRec15[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
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
			fRec47[2] = fRec47[1];
			fRec47[1] = fRec47[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec51[2] = fRec51[1];
			fRec51[1] = fRec51[0];
			fRec46[1] = fRec46[0];
			fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec41[1] = fRec41[0];
			fRec55[2] = fRec55[1];
			fRec55[1] = fRec55[0];
			fRec56[2] = fRec56[1];
			fRec56[1] = fRec56[0];
			fRec57[2] = fRec57[1];
			fRec57[1] = fRec57[0];
			fRec54[1] = fRec54[0];
			fRec52[1] = fRec52[0];
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
			fRec72[1] = fRec72[0];
			fRec70[1] = fRec70[0];
			fRec69[1] = fRec69[0];
			fRec67[1] = fRec67[0];
			fRec66[1] = fRec66[0];
			fRec64[1] = fRec64[0];
			fRec63[1] = fRec63[0];
			fRec61[1] = fRec61[0];
			fRec60[1] = fRec60[0];
			fRec58[1] = fRec58[0];
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
			fRec122[1] = fRec122[0];
			fRec120[1] = fRec120[0];
			fRec128[1] = fRec128[0];
			fRec126[1] = fRec126[0];
			fRec125[1] = fRec125[0];
			fRec123[1] = fRec123[0];
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
			fRec167[1] = fRec167[0];
			fRec165[1] = fRec165[0];
			fRec173[1] = fRec173[0];
			fRec171[1] = fRec171[0];
			fRec170[1] = fRec170[0];
			fRec168[1] = fRec168[0];
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
			fRec212[1] = fRec212[0];
			fRec210[1] = fRec210[0];
			fRec218[1] = fRec218[0];
			fRec216[1] = fRec216[0];
			fRec215[1] = fRec215[0];
			fRec213[1] = fRec213[0];
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
			fRec239[1] = fRec239[0];
			fRec237[1] = fRec237[0];
			fRec236[1] = fRec236[0];
			fRec234[1] = fRec234[0];
			fRec242[1] = fRec242[0];
			fRec240[1] = fRec240[0];
			fRec251[1] = fRec251[0];
			fRec249[1] = fRec249[0];
			fRec248[1] = fRec248[0];
			fRec246[1] = fRec246[0];
			fRec245[1] = fRec245[0];
			fRec243[1] = fRec243[0];
			fRec263[1] = fRec263[0];
			fRec261[1] = fRec261[0];
			fRec260[1] = fRec260[0];
			fRec258[1] = fRec258[0];
			fRec257[1] = fRec257[0];
			fRec255[1] = fRec255[0];
			fRec254[1] = fRec254[0];
			fRec252[1] = fRec252[0];
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
			fRec284[1] = fRec284[0];
			fRec282[1] = fRec282[0];
			fRec281[1] = fRec281[0];
			fRec279[1] = fRec279[0];
			fRec287[1] = fRec287[0];
			fRec285[1] = fRec285[0];
			fRec296[1] = fRec296[0];
			fRec294[1] = fRec294[0];
			fRec293[1] = fRec293[0];
			fRec291[1] = fRec291[0];
			fRec290[1] = fRec290[0];
			fRec288[1] = fRec288[0];
			fRec308[1] = fRec308[0];
			fRec306[1] = fRec306[0];
			fRec305[1] = fRec305[0];
			fRec303[1] = fRec303[0];
			fRec302[1] = fRec302[0];
			fRec300[1] = fRec300[0];
			fRec299[1] = fRec299[0];
			fRec297[1] = fRec297[0];
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
			fRec524[1] = fRec524[0];
			fRec522[1] = fRec522[0];
			fRec521[1] = fRec521[0];
			fRec519[1] = fRec519[0];
			fRec518[1] = fRec518[0];
			fRec516[1] = fRec516[0];
			fRec527[1] = fRec527[0];
			fRec525[1] = fRec525[0];
			fRec533[1] = fRec533[0];
			fRec531[1] = fRec531[0];
			fRec530[1] = fRec530[0];
			fRec528[1] = fRec528[0];
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
			fRec587[1] = fRec587[0];
			fRec585[1] = fRec585[0];
			fRec584[1] = fRec584[0];
			fRec582[1] = fRec582[0];
			fRec581[1] = fRec581[0];
			fRec579[1] = fRec579[0];
			fRec593[1] = fRec593[0];
			fRec591[1] = fRec591[0];
			fRec590[1] = fRec590[0];
			fRec588[1] = fRec588[0];
			fRec596[1] = fRec596[0];
			fRec594[1] = fRec594[0];
			fRec608[1] = fRec608[0];
			fRec606[1] = fRec606[0];
			fRec605[1] = fRec605[0];
			fRec603[1] = fRec603[0];
			fRec602[1] = fRec602[0];
			fRec600[1] = fRec600[0];
			fRec599[1] = fRec599[0];
			fRec597[1] = fRec597[0];
			fRec623[1] = fRec623[0];
			fRec621[1] = fRec621[0];
			fRec620[1] = fRec620[0];
			fRec618[1] = fRec618[0];
			fRec617[1] = fRec617[0];
			fRec615[1] = fRec615[0];
			fRec614[1] = fRec614[0];
			fRec612[1] = fRec612[0];
			fRec611[1] = fRec611[0];
			fRec609[1] = fRec609[0];
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
			fRec854[1] = fRec854[0];
			fRec852[1] = fRec852[0];
			fRec851[1] = fRec851[0];
			fRec849[1] = fRec849[0];
			fRec857[1] = fRec857[0];
			fRec855[1] = fRec855[0];
			fRec869[1] = fRec869[0];
			fRec867[1] = fRec867[0];
			fRec866[1] = fRec866[0];
			fRec864[1] = fRec864[0];
			fRec863[1] = fRec863[0];
			fRec861[1] = fRec861[0];
			fRec860[1] = fRec860[0];
			fRec858[1] = fRec858[0];
			fRec878[1] = fRec878[0];
			fRec876[1] = fRec876[0];
			fRec875[1] = fRec875[0];
			fRec873[1] = fRec873[0];
			fRec872[1] = fRec872[0];
			fRec870[1] = fRec870[0];
			fRec893[1] = fRec893[0];
			fRec891[1] = fRec891[0];
			fRec890[1] = fRec890[0];
			fRec888[1] = fRec888[0];
			fRec887[1] = fRec887[0];
			fRec885[1] = fRec885[0];
			fRec884[1] = fRec884[0];
			fRec882[1] = fRec882[0];
			fRec881[1] = fRec881[0];
			fRec879[1] = fRec879[0];
			fRec902[1] = fRec902[0];
			fRec900[1] = fRec900[0];
			fRec899[1] = fRec899[0];
			fRec897[1] = fRec897[0];
			fRec896[1] = fRec896[0];
			fRec894[1] = fRec894[0];
			fRec917[1] = fRec917[0];
			fRec915[1] = fRec915[0];
			fRec914[1] = fRec914[0];
			fRec912[1] = fRec912[0];
			fRec911[1] = fRec911[0];
			fRec909[1] = fRec909[0];
			fRec908[1] = fRec908[0];
			fRec906[1] = fRec906[0];
			fRec905[1] = fRec905[0];
			fRec903[1] = fRec903[0];
			fRec929[1] = fRec929[0];
			fRec927[1] = fRec927[0];
			fRec926[1] = fRec926[0];
			fRec924[1] = fRec924[0];
			fRec923[1] = fRec923[0];
			fRec921[1] = fRec921[0];
			fRec920[1] = fRec920[0];
			fRec918[1] = fRec918[0];
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
			fRec1088[1] = fRec1088[0];
			fRec1086[1] = fRec1086[0];
			fRec1103[1] = fRec1103[0];
			fRec1101[1] = fRec1101[0];
			fRec1109[1] = fRec1109[0];
			fRec1107[1] = fRec1107[0];
			fRec1106[1] = fRec1106[0];
			fRec1104[1] = fRec1104[0];
			fRec1118[1] = fRec1118[0];
			fRec1116[1] = fRec1116[0];
			fRec1115[1] = fRec1115[0];
			fRec1113[1] = fRec1113[0];
			fRec1112[1] = fRec1112[0];
			fRec1110[1] = fRec1110[0];
			fRec1124[1] = fRec1124[0];
			fRec1122[1] = fRec1122[0];
			fRec1121[1] = fRec1121[0];
			fRec1119[1] = fRec1119[0];
			fRec1127[1] = fRec1127[0];
			fRec1125[1] = fRec1125[0];
			fRec1142[1] = fRec1142[0];
			fRec1140[1] = fRec1140[0];
			fRec1139[1] = fRec1139[0];
			fRec1137[1] = fRec1137[0];
			fRec1136[1] = fRec1136[0];
			fRec1134[1] = fRec1134[0];
			fRec1133[1] = fRec1133[0];
			fRec1131[1] = fRec1131[0];
			fRec1130[1] = fRec1130[0];
			fRec1128[1] = fRec1128[0];
			fRec1151[1] = fRec1151[0];
			fRec1149[1] = fRec1149[0];
			fRec1148[1] = fRec1148[0];
			fRec1146[1] = fRec1146[0];
			fRec1145[1] = fRec1145[0];
			fRec1143[1] = fRec1143[0];
			fRec1163[1] = fRec1163[0];
			fRec1161[1] = fRec1161[0];
			fRec1160[1] = fRec1160[0];
			fRec1158[1] = fRec1158[0];
			fRec1157[1] = fRec1157[0];
			fRec1155[1] = fRec1155[0];
			fRec1154[1] = fRec1154[0];
			fRec1152[1] = fRec1152[0];
			fRec1175[1] = fRec1175[0];
			fRec1173[1] = fRec1173[0];
			fRec1172[1] = fRec1172[0];
			fRec1170[1] = fRec1170[0];
			fRec1169[1] = fRec1169[0];
			fRec1167[1] = fRec1167[0];
			fRec1166[1] = fRec1166[0];
			fRec1164[1] = fRec1164[0];
			fRec1178[1] = fRec1178[0];
			fRec1176[1] = fRec1176[0];
			fRec1187[1] = fRec1187[0];
			fRec1185[1] = fRec1185[0];
			fRec1184[1] = fRec1184[0];
			fRec1182[1] = fRec1182[0];
			fRec1181[1] = fRec1181[0];
			fRec1179[1] = fRec1179[0];
			fRec1193[1] = fRec1193[0];
			fRec1191[1] = fRec1191[0];
			fRec1190[1] = fRec1190[0];
			fRec1188[1] = fRec1188[0];
			fRec1208[1] = fRec1208[0];
			fRec1206[1] = fRec1206[0];
			fRec1205[1] = fRec1205[0];
			fRec1203[1] = fRec1203[0];
			fRec1202[1] = fRec1202[0];
			fRec1200[1] = fRec1200[0];
			fRec1199[1] = fRec1199[0];
			fRec1197[1] = fRec1197[0];
			fRec1196[1] = fRec1196[0];
			fRec1194[1] = fRec1194[0];
			fRec1214[1] = fRec1214[0];
			fRec1212[1] = fRec1212[0];
			fRec1211[1] = fRec1211[0];
			fRec1209[1] = fRec1209[0];
			fRec1217[1] = fRec1217[0];
			fRec1215[1] = fRec1215[0];
			fRec1226[1] = fRec1226[0];
			fRec1224[1] = fRec1224[0];
			fRec1223[1] = fRec1223[0];
			fRec1221[1] = fRec1221[0];
			fRec1220[1] = fRec1220[0];
			fRec1218[1] = fRec1218[0];
			fRec1238[1] = fRec1238[0];
			fRec1236[1] = fRec1236[0];
			fRec1235[1] = fRec1235[0];
			fRec1233[1] = fRec1233[0];
			fRec1232[1] = fRec1232[0];
			fRec1230[1] = fRec1230[0];
			fRec1229[1] = fRec1229[0];
			fRec1227[1] = fRec1227[0];
			fRec1253[1] = fRec1253[0];
			fRec1251[1] = fRec1251[0];
			fRec1250[1] = fRec1250[0];
			fRec1248[1] = fRec1248[0];
			fRec1247[1] = fRec1247[0];
			fRec1245[1] = fRec1245[0];
			fRec1244[1] = fRec1244[0];
			fRec1242[1] = fRec1242[0];
			fRec1241[1] = fRec1241[0];
			fRec1239[1] = fRec1239[0];
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
			fRec1280[1] = fRec1280[0];
			fRec1278[1] = fRec1278[0];
			fRec1292[1] = fRec1292[0];
			fRec1290[1] = fRec1290[0];
			fRec1298[1] = fRec1298[0];
			fRec1296[1] = fRec1296[0];
			fRec1295[1] = fRec1295[0];
			fRec1293[1] = fRec1293[0];
			fRec1307[1] = fRec1307[0];
			fRec1305[1] = fRec1305[0];
			fRec1304[1] = fRec1304[0];
			fRec1302[1] = fRec1302[0];
			fRec1301[1] = fRec1301[0];
			fRec1299[1] = fRec1299[0];
			fRec1322[1] = fRec1322[0];
			fRec1320[1] = fRec1320[0];
			fRec1319[1] = fRec1319[0];
			fRec1317[1] = fRec1317[0];
			fRec1316[1] = fRec1316[0];
			fRec1314[1] = fRec1314[0];
			fRec1313[1] = fRec1313[0];
			fRec1311[1] = fRec1311[0];
			fRec1310[1] = fRec1310[0];
			fRec1308[1] = fRec1308[0];
			fRec1325[1] = fRec1325[0];
			fRec1323[1] = fRec1323[0];
			fRec1331[1] = fRec1331[0];
			fRec1329[1] = fRec1329[0];
			fRec1328[1] = fRec1328[0];
			fRec1326[1] = fRec1326[0];
			fRec1343[1] = fRec1343[0];
			fRec1341[1] = fRec1341[0];
			fRec1340[1] = fRec1340[0];
			fRec1338[1] = fRec1338[0];
			fRec1337[1] = fRec1337[0];
			fRec1335[1] = fRec1335[0];
			fRec1334[1] = fRec1334[0];
			fRec1332[1] = fRec1332[0];
			fRec1352[1] = fRec1352[0];
			fRec1350[1] = fRec1350[0];
			fRec1349[1] = fRec1349[0];
			fRec1347[1] = fRec1347[0];
			fRec1346[1] = fRec1346[0];
			fRec1344[1] = fRec1344[0];
			fRec1358[1] = fRec1358[0];
			fRec1356[1] = fRec1356[0];
			fRec1355[1] = fRec1355[0];
			fRec1353[1] = fRec1353[0];
			fRec1370[1] = fRec1370[0];
			fRec1368[1] = fRec1368[0];
			fRec1367[1] = fRec1367[0];
			fRec1365[1] = fRec1365[0];
			fRec1364[1] = fRec1364[0];
			fRec1362[1] = fRec1362[0];
			fRec1361[1] = fRec1361[0];
			fRec1359[1] = fRec1359[0];
			fRec1373[1] = fRec1373[0];
			fRec1371[1] = fRec1371[0];
			fRec1388[1] = fRec1388[0];
			fRec1386[1] = fRec1386[0];
			fRec1385[1] = fRec1385[0];
			fRec1383[1] = fRec1383[0];
			fRec1382[1] = fRec1382[0];
			fRec1380[1] = fRec1380[0];
			fRec1379[1] = fRec1379[0];
			fRec1377[1] = fRec1377[0];
			fRec1376[1] = fRec1376[0];
			fRec1374[1] = fRec1374[0];
			fRec1394[1] = fRec1394[0];
			fRec1392[1] = fRec1392[0];
			fRec1391[1] = fRec1391[0];
			fRec1389[1] = fRec1389[0];
			fRec1403[1] = fRec1403[0];
			fRec1401[1] = fRec1401[0];
			fRec1400[1] = fRec1400[0];
			fRec1398[1] = fRec1398[0];
			fRec1397[1] = fRec1397[0];
			fRec1395[1] = fRec1395[0];
			fRec1406[1] = fRec1406[0];
			fRec1404[1] = fRec1404[0];
			fRec1418[1] = fRec1418[0];
			fRec1416[1] = fRec1416[0];
			fRec1415[1] = fRec1415[0];
			fRec1413[1] = fRec1413[0];
			fRec1412[1] = fRec1412[0];
			fRec1410[1] = fRec1410[0];
			fRec1409[1] = fRec1409[0];
			fRec1407[1] = fRec1407[0];
			fRec1433[1] = fRec1433[0];
			fRec1431[1] = fRec1431[0];
			fRec1430[1] = fRec1430[0];
			fRec1428[1] = fRec1428[0];
			fRec1427[1] = fRec1427[0];
			fRec1425[1] = fRec1425[0];
			fRec1424[1] = fRec1424[0];
			fRec1422[1] = fRec1422[0];
			fRec1421[1] = fRec1421[0];
			fRec1419[1] = fRec1419[0];
			fRec1445[1] = fRec1445[0];
			fRec1443[1] = fRec1443[0];
			fRec1442[1] = fRec1442[0];
			fRec1440[1] = fRec1440[0];
			fRec1439[1] = fRec1439[0];
			fRec1437[1] = fRec1437[0];
			fRec1436[1] = fRec1436[0];
			fRec1434[1] = fRec1434[0];
			fRec1460[1] = fRec1460[0];
			fRec1458[1] = fRec1458[0];
			fRec1457[1] = fRec1457[0];
			fRec1455[1] = fRec1455[0];
			fRec1454[1] = fRec1454[0];
			fRec1452[1] = fRec1452[0];
			fRec1451[1] = fRec1451[0];
			fRec1449[1] = fRec1449[0];
			fRec1448[1] = fRec1448[0];
			fRec1446[1] = fRec1446[0];
			fRec1466[1] = fRec1466[0];
			fRec1464[1] = fRec1464[0];
			fRec1463[1] = fRec1463[0];
			fRec1461[1] = fRec1461[0];
			fRec1469[1] = fRec1469[0];
			fRec1467[1] = fRec1467[0];
			fRec1478[1] = fRec1478[0];
			fRec1476[1] = fRec1476[0];
			fRec1475[1] = fRec1475[0];
			fRec1473[1] = fRec1473[0];
			fRec1472[1] = fRec1472[0];
			fRec1470[1] = fRec1470[0];
			fRec1493[1] = fRec1493[0];
			fRec1491[1] = fRec1491[0];
			fRec1490[1] = fRec1490[0];
			fRec1488[1] = fRec1488[0];
			fRec1487[1] = fRec1487[0];
			fRec1485[1] = fRec1485[0];
			fRec1484[1] = fRec1484[0];
			fRec1482[1] = fRec1482[0];
			fRec1481[1] = fRec1481[0];
			fRec1479[1] = fRec1479[0];
			fRec1499[1] = fRec1499[0];
			fRec1497[1] = fRec1497[0];
			fRec1496[1] = fRec1496[0];
			fRec1494[1] = fRec1494[0];
			fRec1511[1] = fRec1511[0];
			fRec1509[1] = fRec1509[0];
			fRec1508[1] = fRec1508[0];
			fRec1506[1] = fRec1506[0];
			fRec1505[1] = fRec1505[0];
			fRec1503[1] = fRec1503[0];
			fRec1502[1] = fRec1502[0];
			fRec1500[1] = fRec1500[0];
			fRec1514[1] = fRec1514[0];
			fRec1512[1] = fRec1512[0];
			fRec1523[1] = fRec1523[0];
			fRec1521[1] = fRec1521[0];
			fRec1520[1] = fRec1520[0];
			fRec1518[1] = fRec1518[0];
			fRec1517[1] = fRec1517[0];
			fRec1515[1] = fRec1515[0];
			fRec1532[1] = fRec1532[0];
			fRec1530[1] = fRec1530[0];
			fRec1529[1] = fRec1529[0];
			fRec1527[1] = fRec1527[0];
			fRec1526[1] = fRec1526[0];
			fRec1524[1] = fRec1524[0];
			fRec1547[1] = fRec1547[0];
			fRec1545[1] = fRec1545[0];
			fRec1544[1] = fRec1544[0];
			fRec1542[1] = fRec1542[0];
			fRec1541[1] = fRec1541[0];
			fRec1539[1] = fRec1539[0];
			fRec1538[1] = fRec1538[0];
			fRec1536[1] = fRec1536[0];
			fRec1535[1] = fRec1535[0];
			fRec1533[1] = fRec1533[0];
			fRec1559[1] = fRec1559[0];
			fRec1557[1] = fRec1557[0];
			fRec1556[1] = fRec1556[0];
			fRec1554[1] = fRec1554[0];
			fRec1553[1] = fRec1553[0];
			fRec1551[1] = fRec1551[0];
			fRec1550[1] = fRec1550[0];
			fRec1548[1] = fRec1548[0];
			fRec1562[1] = fRec1562[0];
			fRec1560[1] = fRec1560[0];
			fRec1568[1] = fRec1568[0];
			fRec1566[1] = fRec1566[0];
			fRec1565[1] = fRec1565[0];
			fRec1563[1] = fRec1563[0];
			fRec1580[1] = fRec1580[0];
			fRec1578[1] = fRec1578[0];
			fRec1577[1] = fRec1577[0];
			fRec1575[1] = fRec1575[0];
			fRec1574[1] = fRec1574[0];
			fRec1572[1] = fRec1572[0];
			fRec1571[1] = fRec1571[0];
			fRec1569[1] = fRec1569[0];
			fRec1583[1] = fRec1583[0];
			fRec1581[1] = fRec1581[0];
			fRec1592[1] = fRec1592[0];
			fRec1590[1] = fRec1590[0];
			fRec1589[1] = fRec1589[0];
			fRec1587[1] = fRec1587[0];
			fRec1586[1] = fRec1586[0];
			fRec1584[1] = fRec1584[0];
			fRec1598[1] = fRec1598[0];
			fRec1596[1] = fRec1596[0];
			fRec1595[1] = fRec1595[0];
			fRec1593[1] = fRec1593[0];
			fRec1613[1] = fRec1613[0];
			fRec1611[1] = fRec1611[0];
			fRec1610[1] = fRec1610[0];
			fRec1608[1] = fRec1608[0];
			fRec1607[1] = fRec1607[0];
			fRec1605[1] = fRec1605[0];
			fRec1604[1] = fRec1604[0];
			fRec1602[1] = fRec1602[0];
			fRec1601[1] = fRec1601[0];
			fRec1599[1] = fRec1599[0];
			fRec1616[1] = fRec1616[0];
			fRec1614[1] = fRec1614[0];
			fRec1622[1] = fRec1622[0];
			fRec1620[1] = fRec1620[0];
			fRec1619[1] = fRec1619[0];
			fRec1617[1] = fRec1617[0];
			fRec1634[1] = fRec1634[0];
			fRec1632[1] = fRec1632[0];
			fRec1631[1] = fRec1631[0];
			fRec1629[1] = fRec1629[0];
			fRec1628[1] = fRec1628[0];
			fRec1626[1] = fRec1626[0];
			fRec1625[1] = fRec1625[0];
			fRec1623[1] = fRec1623[0];
			fRec1643[1] = fRec1643[0];
			fRec1641[1] = fRec1641[0];
			fRec1640[1] = fRec1640[0];
			fRec1638[1] = fRec1638[0];
			fRec1637[1] = fRec1637[0];
			fRec1635[1] = fRec1635[0];
			fRec1658[1] = fRec1658[0];
			fRec1656[1] = fRec1656[0];
			fRec1655[1] = fRec1655[0];
			fRec1653[1] = fRec1653[0];
			fRec1652[1] = fRec1652[0];
			fRec1650[1] = fRec1650[0];
			fRec1649[1] = fRec1649[0];
			fRec1647[1] = fRec1647[0];
			fRec1646[1] = fRec1646[0];
			fRec1644[1] = fRec1644[0];
			fRec1667[1] = fRec1667[0];
			fRec1665[1] = fRec1665[0];
			fRec1664[1] = fRec1664[0];
			fRec1662[1] = fRec1662[0];
			fRec1661[1] = fRec1661[0];
			fRec1659[1] = fRec1659[0];
			fRec1673[1] = fRec1673[0];
			fRec1671[1] = fRec1671[0];
			fRec1670[1] = fRec1670[0];
			fRec1668[1] = fRec1668[0];
			fRec1676[1] = fRec1676[0];
			fRec1674[1] = fRec1674[0];
			fRec1688[1] = fRec1688[0];
			fRec1686[1] = fRec1686[0];
			fRec1685[1] = fRec1685[0];
			fRec1683[1] = fRec1683[0];
			fRec1682[1] = fRec1682[0];
			fRec1680[1] = fRec1680[0];
			fRec1679[1] = fRec1679[0];
			fRec1677[1] = fRec1677[0];
			fRec1703[1] = fRec1703[0];
			fRec1701[1] = fRec1701[0];
			fRec1700[1] = fRec1700[0];
			fRec1698[1] = fRec1698[0];
			fRec1697[1] = fRec1697[0];
			fRec1695[1] = fRec1695[0];
			fRec1694[1] = fRec1694[0];
			fRec1692[1] = fRec1692[0];
			fRec1691[1] = fRec1691[0];
			fRec1689[1] = fRec1689[0];
			fRec1718[1] = fRec1718[0];
			fRec1716[1] = fRec1716[0];
			fRec1715[1] = fRec1715[0];
			fRec1713[1] = fRec1713[0];
			fRec1712[1] = fRec1712[0];
			fRec1710[1] = fRec1710[0];
			fRec1709[1] = fRec1709[0];
			fRec1707[1] = fRec1707[0];
			fRec1706[1] = fRec1706[0];
			fRec1704[1] = fRec1704[0];
			fRec1730[1] = fRec1730[0];
			fRec1728[1] = fRec1728[0];
			fRec1727[1] = fRec1727[0];
			fRec1725[1] = fRec1725[0];
			fRec1724[1] = fRec1724[0];
			fRec1722[1] = fRec1722[0];
			fRec1721[1] = fRec1721[0];
			fRec1719[1] = fRec1719[0];
			fRec1739[1] = fRec1739[0];
			fRec1737[1] = fRec1737[0];
			fRec1736[1] = fRec1736[0];
			fRec1734[1] = fRec1734[0];
			fRec1733[1] = fRec1733[0];
			fRec1731[1] = fRec1731[0];
			fRec1742[1] = fRec1742[0];
			fRec1740[1] = fRec1740[0];
			fRec1748[1] = fRec1748[0];
			fRec1746[1] = fRec1746[0];
			fRec1745[1] = fRec1745[0];
			fRec1743[1] = fRec1743[0];
			fRec1754[1] = fRec1754[0];
			fRec1752[1] = fRec1752[0];
			fRec1751[1] = fRec1751[0];
			fRec1749[1] = fRec1749[0];
			fRec1769[1] = fRec1769[0];
			fRec1767[1] = fRec1767[0];
			fRec1766[1] = fRec1766[0];
			fRec1764[1] = fRec1764[0];
			fRec1763[1] = fRec1763[0];
			fRec1761[1] = fRec1761[0];
			fRec1760[1] = fRec1760[0];
			fRec1758[1] = fRec1758[0];
			fRec1757[1] = fRec1757[0];
			fRec1755[1] = fRec1755[0];
			fRec1781[1] = fRec1781[0];
			fRec1779[1] = fRec1779[0];
			fRec1778[1] = fRec1778[0];
			fRec1776[1] = fRec1776[0];
			fRec1775[1] = fRec1775[0];
			fRec1773[1] = fRec1773[0];
			fRec1772[1] = fRec1772[0];
			fRec1770[1] = fRec1770[0];
			fRec1784[1] = fRec1784[0];
			fRec1782[1] = fRec1782[0];
			fRec1793[1] = fRec1793[0];
			fRec1791[1] = fRec1791[0];
			fRec1790[1] = fRec1790[0];
			fRec1788[1] = fRec1788[0];
			fRec1787[1] = fRec1787[0];
			fRec1785[1] = fRec1785[0];
			fRec1805[1] = fRec1805[0];
			fRec1803[1] = fRec1803[0];
			fRec1802[1] = fRec1802[0];
			fRec1800[1] = fRec1800[0];
			fRec1799[1] = fRec1799[0];
			fRec1797[1] = fRec1797[0];
			fRec1796[1] = fRec1796[0];
			fRec1794[1] = fRec1794[0];
			fRec1814[1] = fRec1814[0];
			fRec1812[1] = fRec1812[0];
			fRec1811[1] = fRec1811[0];
			fRec1809[1] = fRec1809[0];
			fRec1808[1] = fRec1808[0];
			fRec1806[1] = fRec1806[0];
			fRec1820[1] = fRec1820[0];
			fRec1818[1] = fRec1818[0];
			fRec1817[1] = fRec1817[0];
			fRec1815[1] = fRec1815[0];
			fRec1823[1] = fRec1823[0];
			fRec1821[1] = fRec1821[0];
			fRec1838[1] = fRec1838[0];
			fRec1836[1] = fRec1836[0];
			fRec1835[1] = fRec1835[0];
			fRec1833[1] = fRec1833[0];
			fRec1832[1] = fRec1832[0];
			fRec1830[1] = fRec1830[0];
			fRec1829[1] = fRec1829[0];
			fRec1827[1] = fRec1827[0];
			fRec1826[1] = fRec1826[0];
			fRec1824[1] = fRec1824[0];
			fRec1853[1] = fRec1853[0];
			fRec1851[1] = fRec1851[0];
			fRec1850[1] = fRec1850[0];
			fRec1848[1] = fRec1848[0];
			fRec1847[1] = fRec1847[0];
			fRec1845[1] = fRec1845[0];
			fRec1844[1] = fRec1844[0];
			fRec1842[1] = fRec1842[0];
			fRec1841[1] = fRec1841[0];
			fRec1839[1] = fRec1839[0];
			fRec1865[1] = fRec1865[0];
			fRec1863[1] = fRec1863[0];
			fRec1862[1] = fRec1862[0];
			fRec1860[1] = fRec1860[0];
			fRec1859[1] = fRec1859[0];
			fRec1857[1] = fRec1857[0];
			fRec1856[1] = fRec1856[0];
			fRec1854[1] = fRec1854[0];
			fRec1874[1] = fRec1874[0];
			fRec1872[1] = fRec1872[0];
			fRec1871[1] = fRec1871[0];
			fRec1869[1] = fRec1869[0];
			fRec1868[1] = fRec1868[0];
			fRec1866[1] = fRec1866[0];
			fRec1877[1] = fRec1877[0];
			fRec1875[1] = fRec1875[0];
			fRec1883[1] = fRec1883[0];
			fRec1881[1] = fRec1881[0];
			fRec1880[1] = fRec1880[0];
			fRec1878[1] = fRec1878[0];
			fRec1886[1] = fRec1886[0];
			fRec1884[1] = fRec1884[0];
			fRec1901[1] = fRec1901[0];
			fRec1899[1] = fRec1899[0];
			fRec1898[1] = fRec1898[0];
			fRec1896[1] = fRec1896[0];
			fRec1895[1] = fRec1895[0];
			fRec1893[1] = fRec1893[0];
			fRec1892[1] = fRec1892[0];
			fRec1890[1] = fRec1890[0];
			fRec1889[1] = fRec1889[0];
			fRec1887[1] = fRec1887[0];
			fRec1913[1] = fRec1913[0];
			fRec1911[1] = fRec1911[0];
			fRec1910[1] = fRec1910[0];
			fRec1908[1] = fRec1908[0];
			fRec1907[1] = fRec1907[0];
			fRec1905[1] = fRec1905[0];
			fRec1904[1] = fRec1904[0];
			fRec1902[1] = fRec1902[0];
			fRec1919[1] = fRec1919[0];
			fRec1917[1] = fRec1917[0];
			fRec1916[1] = fRec1916[0];
			fRec1914[1] = fRec1914[0];
			fRec1928[1] = fRec1928[0];
			fRec1926[1] = fRec1926[0];
			fRec1925[1] = fRec1925[0];
			fRec1923[1] = fRec1923[0];
			fRec1922[1] = fRec1922[0];
			fRec1920[1] = fRec1920[0];
			fRec1943[1] = fRec1943[0];
			fRec1941[1] = fRec1941[0];
			fRec1940[1] = fRec1940[0];
			fRec1938[1] = fRec1938[0];
			fRec1937[1] = fRec1937[0];
			fRec1935[1] = fRec1935[0];
			fRec1934[1] = fRec1934[0];
			fRec1932[1] = fRec1932[0];
			fRec1931[1] = fRec1931[0];
			fRec1929[1] = fRec1929[0];
			fRec1955[1] = fRec1955[0];
			fRec1953[1] = fRec1953[0];
			fRec1952[1] = fRec1952[0];
			fRec1950[1] = fRec1950[0];
			fRec1949[1] = fRec1949[0];
			fRec1947[1] = fRec1947[0];
			fRec1946[1] = fRec1946[0];
			fRec1944[1] = fRec1944[0];
			fRec1964[1] = fRec1964[0];
			fRec1962[1] = fRec1962[0];
			fRec1961[1] = fRec1961[0];
			fRec1959[1] = fRec1959[0];
			fRec1958[1] = fRec1958[0];
			fRec1956[1] = fRec1956[0];
			fRec1967[1] = fRec1967[0];
			fRec1965[1] = fRec1965[0];
			fRec1973[1] = fRec1973[0];
			fRec1971[1] = fRec1971[0];
			fRec1970[1] = fRec1970[0];
			fRec1968[1] = fRec1968[0];
			fRec1988[1] = fRec1988[0];
			fRec1986[1] = fRec1986[0];
			fRec1985[1] = fRec1985[0];
			fRec1983[1] = fRec1983[0];
			fRec1982[1] = fRec1982[0];
			fRec1980[1] = fRec1980[0];
			fRec1979[1] = fRec1979[0];
			fRec1977[1] = fRec1977[0];
			fRec1976[1] = fRec1976[0];
			fRec1974[1] = fRec1974[0];
			fRec1997[1] = fRec1997[0];
			fRec1995[1] = fRec1995[0];
			fRec1994[1] = fRec1994[0];
			fRec1992[1] = fRec1992[0];
			fRec1991[1] = fRec1991[0];
			fRec1989[1] = fRec1989[0];
			fRec2009[1] = fRec2009[0];
			fRec2007[1] = fRec2007[0];
			fRec2006[1] = fRec2006[0];
			fRec2004[1] = fRec2004[0];
			fRec2003[1] = fRec2003[0];
			fRec2001[1] = fRec2001[0];
			fRec2000[1] = fRec2000[0];
			fRec1998[1] = fRec1998[0];
			fRec2012[1] = fRec2012[0];
			fRec2010[1] = fRec2010[0];
			fRec2018[1] = fRec2018[0];
			fRec2016[1] = fRec2016[0];
			fRec2015[1] = fRec2015[0];
			fRec2013[1] = fRec2013[0];
			fRec2027[1] = fRec2027[0];
			fRec2025[1] = fRec2025[0];
			fRec2024[1] = fRec2024[0];
			fRec2022[1] = fRec2022[0];
			fRec2021[1] = fRec2021[0];
			fRec2019[1] = fRec2019[0];
			fRec2039[1] = fRec2039[0];
			fRec2037[1] = fRec2037[0];
			fRec2036[1] = fRec2036[0];
			fRec2034[1] = fRec2034[0];
			fRec2033[1] = fRec2033[0];
			fRec2031[1] = fRec2031[0];
			fRec2030[1] = fRec2030[0];
			fRec2028[1] = fRec2028[0];
			fRec2042[1] = fRec2042[0];
			fRec2040[1] = fRec2040[0];
			fRec2048[1] = fRec2048[0];
			fRec2046[1] = fRec2046[0];
			fRec2045[1] = fRec2045[0];
			fRec2043[1] = fRec2043[0];
			fRec2063[1] = fRec2063[0];
			fRec2061[1] = fRec2061[0];
			fRec2060[1] = fRec2060[0];
			fRec2058[1] = fRec2058[0];
			fRec2057[1] = fRec2057[0];
			fRec2055[1] = fRec2055[0];
			fRec2054[1] = fRec2054[0];
			fRec2052[1] = fRec2052[0];
			fRec2051[1] = fRec2051[0];
			fRec2049[1] = fRec2049[0];
			
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
