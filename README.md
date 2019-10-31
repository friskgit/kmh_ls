# General information

Scroll down to [Klangkupolen, Lilla Salen](#org96d8fc3) for specifics


## Ambisonics in KMH studios and Lilla salen


### About ambisonics

The general idea behind using ambisonics for difusing sounds in a space is to, in the first stage, encode an audio signal to a representation of a sound field - a B-format signal. This B-format signal is idependent of whatever speaker array the signal will later be diffused on. In the second stage the B-format signal is decoded to the layout of a particular speaker array. In between these two stages a number of transformations may be applied, but the sound source specification may conveniently be specified in the encoder.

In principle, any kind of encoder may be combined with any kind of decoder provided that the same channel order is used. Among the encoders (VST) that work with the decoders presented here are [Ambix](http://www.matthiaskronlachner.com/?p=2015) and [IEM Plugin suite](https://plugins.iem.at/). Using these makes it simple to automate panning in a DAW such as [Reaper](https://www.reaper.fm/).


### About the compiled decoders

All decoders use ACN channel order (see [Component order](#org8cce7e7)) and SN3D normalization (see [Normalisation](#org419d138)) and are dual-band, max-rE/rV.

-   A guide to the file names

    For efficiency file names are composed of the following parts
    
    1.  The space (for Lilla Salen this is KMHLS\_AE)
    2.  Speaker configuration (Full or Normal where the former in 108/118 and 114 means the center speaker is included, and in Lilla Salen it refers to the 45.4 setup)
    3.  Order (e.g. 7H7P)
    4.  Redundant speaker configuration (full, but only in certain cases for Lilla Salen)
    5.  Finally, a number depicting the type of decoder according to the following codes:
    
    -   (1) AllRad mixed order (4/3)
    
        Mixed order ambisonics decoder.
    
    -   (2) Decoding with the pseudo-inverse, even-energy
    
        Pinv decoders in 1st, 3rd order with even-energy for inversion variants.
        
        The higher order decoders in pseudo-inverse do not work well, so do not try those above 3rd order.
    
    -   (3) Decoding with the pseudo-inverse, mode-matching
    
        Pinv decoders in 1st, 3rd order, mode-matching for inversion variants. This has been removed from the repository.
    
    -   (4) Same as (2) but with a blend coefficient for inversion variants (energy limited/mode matching 50%)
    
        1st and 3rd and 6th order.
        
        The higher order decoders in pseudo-inverse do not work well, so do not try those above 3rd order - though sixth order has provecd useful.
    
    -   (5) Spherical slepian decoders
    
        SSF decoders in 1st, 3rd and 6th order (6th order is here only as VST, but I can compile the other formats if needed.)
    
    -   (6) All-round decoders
    
        AllRAD decoders in 1st, 3rd, 5th and 7th order.

-   Ouput formats

    In the directory of each decoder there are four subdirectories:
    
    -   ambix: contains the decoder matrix for the ambix VST-plugin for certain settings.
    -   bin: contains all other decoders
    -   doc: documentation, a bare minimal (but a more comprehensive documentation can be built from the source, check the individual Makefiles for each compilere)
    -   src: the faust sources for the decoders
    
    The binaries are prepared in six different formats:
    
    1.  a jack application (start from commandline: $ KMHLS\_Dome\_4h3v\_normal\_1)
    2.  a double clickable CoreAudio application
    3.  a 'max' directory with Max/MSP objects (as package with help files to be put in ~/Documents/Max 7/Packages)
    4.  a 'pd' direcory (bang left most input to get parameter names)
    5.  a 'sc' directory with SuperCollider classes (put all .sc and .scx in ~/Library/Application Support/SuperCollider/Extensions , the supernova files are of course optional)
    6.  an 'ambix' directory with Ambix config file
    
    -   Install on your system
    
        You may simply move the decoders you want to use to the right locations on your system. They are compiled and ready to be used in the repository. As a convenience one may run the corresponding install scripts in the Makefile for the decoders to install them in your default directory:
        
        1.  Open a terminal (such as Terminal.app)
        2.  At the prompt type `$ cd` and drag one of the directories, say 'KMHLS\_AE\_normal\_6' of your downloaded repository onto the terminal and press enter.
        3.  Enter `$ make maxinstall` at the prompt and press enter.
        
        The last step can be made for `scinstall`, `vstinstall` and `pdinstall`
        
        Note that to create a Max/MSP compatible package you may have to run maxinstall and have the reslevant dependencies resolved. Else, contact me!

-   Component order

    The component order for the input to the decoder follows the ACN (Ambisonics Channel Number) standard according to the table below (for third order):
    
    |   |    |    | 0  |    |    |    |
    |   |    | 1  | 2  | 3  |    |    |
    |   | 4  | 5  | 6  | 7  | 8  |    |
    | 9 | 10 | 11 | 12 | 13 | 13 | 15 |
    
    Or: W Y Z X V T R S U Q O M K L N P

-   Normalisation

    The decoder is using SN3D normalisation. With SN3D normalisation no component will exceed the peak value of the 0th order component.

-   Compiling the decoders

    This is only if you wish to tweak the settings in any way. All scripts needed for the compilation is in a speparate GitHub repository that may be found here:
    
    <https://github.com/friskgit/kmh_decoders>
    
    In order to compile the decoders there are a number of dependencies that need to be resolved:
    
    -   ADT (Ambisoncs Decoder Toolkit)
    -   Faust
    -   VST SDK
    -   Pure Data
    -   Max MSP SDK
    -   Links to Supercollider classes
    
    -   Running Makefile scripts for ADT
    
        Run the following for each function that needs to be compiled for lilla salen (108\_all and 114\_all for the studios):
        
        `$ make ls_all function=6`
        
        Note that for fuction 2 & 4 only orders up to 3 are usable.
        
        The decoding matrices end up in a directory above your current directory named 'decoders'. Move into that directory with the following command:
        
        `$ cd ../decoders`
        
        With the decoding matrices calculated the binary decoders for all orders can be compiled by
        
        `$ make -k target=all all`
        
        The target can be either of [all,sc,max,pd,vst]. Following this step the binaries can be installed (to install only one target, use that as the argument for 'target'.:
        
        `$ make -k target=install all`


<a id="org96d8fc3"></a>

# Klangkupolen, Lilla Salen


## Specific info for Klangkupolen


### Output

In Klangkupolen the channel order from the mixer is channel 1-29 for the regular dome. The lower ring starts at channel 33-48 and the subs are at 49-52. This is the reason that in the decoder the names for the sixteen floor speakers start at 33.

The layout is ordered clockwise starting at speaker one.


<a id="org1be9e74"></a>

### Speaker positions

All distances and heigths are measured from 1.25m height from floor.

| ndx | azimuth    | elevation | distance | radius    |
|--- |---------- |--------- |-------- |--------- |
| 1   | -34.689614 | 12.910417 | 4.61     | 4.5789148 |
| 2   | -13.383763 | 12.910417 | 4.61     | 4.5577825 |
| 3   | 10.440725  | 12.910417 | 4.61     | 4.5635592 |
| 4   | 32.117788  | 12.910417 | 4.61     | 4.5386017 |
| 5   | 55.741675  | 12.910417 | 4.61     | 4.4464181 |
| 6   | 78.207673  | 12.910417 | 4.61     | 4.4723909 |
| 7   | 101.49442  | 12.910417 | 4.61     | 4.4461719 |
| 8   | 124.85167  | 12.910417 | 4.61     | 4.5148007 |
| 9   | 147.91193  | 12.910417 | 4.61     | 4.5536496 |
| 10  | 169.17789  | 12.910417 | 4.61     | 4.6069350 |
| 11  | -167.82013 | 12.910417 | 4.61     | 4.7018379 |
| 12  | -145.63454 | 12.910417 | 4.61     | 4.6822723 |
| 13  | -123.78400 | 12.910417 | 4.61     | 4.7368687 |
| 14  | -102.64182 | 12.910417 | 4.61     | 4.6743181 |
| 15  | -79.887731 | 12.910417 | 4.61     | 4.7101696 |
| 16  | -57.926139 | 12.910417 | 4.61     | 4.6119481 |
| 17  | -22.349553 | 34.696822 | 4.882    | 4.0761992 |
| 18  | 22.843958  | 34.696822 | 4.882    | 3.7761827 |
| 19  | 69.013292  | 34.696822 | 4.882    | 4.0485676 |
| 20  | 115.56544  | 34.696822 | 4.882    | 4.1015729 |
| 21  | 158.89992  | 34.696822 | 4.882    | 3.9444645 |
| 22  | -158.89763 | 34.696822 | 4.882    | 3.8051807 |
| 23  | -114.65354 | 34.696822 | 4.882    | 3.6199724 |
| 24  | -68.170128 | 34.696822 | 4.882    | 3.7380476 |
| 25  | -45.       | 69.185799 | 5.317    | 1.7225121 |
| 26  | 45.        | 69.185799 | 5.317    | 1.7225121 |
| 27  | 135.       | 69.185799 | 5.317    | 1.7225121 |
| 28  | -135.      | 69.185799 | 5.317    | 1.7225121 |
| 29  | 0.         | 90.       | 5.576    | 0         |
| 33  | -24.036689 | -3.089583 | 4.61     | 4.5789148 |
| 34  | -1.471519  | -3.089583 | 4.61     | 4.5577825 |
| 35  | 21.279257  | -3.089583 | 4.61     | 4.5635592 |
| 36  | 43.929732  | -3.089583 | 4.61     | 4.5386017 |
| 37  | 66.974674  | -3.089583 | 4.61     | 4.4464181 |
| 38  | 89.851047  | -3.089583 | 4.61     | 4.4723909 |
| 39  | 113.17305  | -3.089583 | 4.61     | 4.4461719 |
| 40  | 136.3818   | -3.089583 | 4.61     | 4.5148007 |
| 41  | 158.56486  | -3.089583 | 4.61     | 4.5536496 |
| 42  | 179.81087  | -3.089583 | 4.61     | 4.6069350 |
| 43  | -156.31914 | -3.089583 | 4.61     | 4.7018379 |
| 44  | -134.54175 | -3.089583 | 4.61     | 4.6822723 |
| 45  | -112.85873 | -3.089583 | 4.61     | 4.7368687 |
| 46  | -92.07073  | -3.089583 | 4.61     | 4.6743181 |
| 47  | -68.510687 | -3.089583 | 4.61     | 4.7101696 |
| 48  | -46.945343 | -3.089583 | 4.61     | 4.6119481 |


### Spat

-   29 speakers

    A setup file for the current speaker arrangments in Lilla Salen (29 speakers) according to [Speaker positions](#org1be9e74) for use with the Ircam spat package.
    
    The following file may be used for a `spat.viewer @numspeakers 29 @showlistener 1 @viewpoint top @width 1200 @height 600`:
    
    ```shell
    speakers aed
    0 12.910417 4.61 -26.34 12.910417 4.61 -58.7 12.910417 4.61 -106 12.910417 4.61 -129.35 12.910417 4.61 129.35 12.910417 4.61 106 12.910417 4.61 58.7 12.910417 4.61 45 12.910417 4.61 -45 12.910417 4.61 -135 12.910417 4.61 135 12.910417 4.61 0 12.910417 4.61 hline 12.910417 4.61
    ```

-   45 speakers

    A setup file for the current speaker arrangments in Lilla Salen (45 speakers) according to [Speaker positions](#org1be9e74) for use with the Ircam spat package.
    
    The following file may be used for a `spat.viewer @numspeakers 29 @showlistener 1 @viewpoint top @width 1200 @height 600`:
    
    ```shell
    speakers aed
    0 12.910417 4.61 -26.34 12.910417 4.61 -58.7 12.910417 4.61 -106 12.910417 4.61 -129.35 12.910417 4.61 129.35 12.910417 4.61 106 12.910417 4.61 58.7 12.910417 4.61 45 12.910417 4.61 -45 12.910417 4.61 -135 12.910417 4.61 135 12.910417 4.61 0 12.910417 4.61 hline 12.910417 4.61
    ```


### Panoramix

-   29 speakers

    A setup file for the current speaker arrangments in Lilla Salen (29 speakers) according to [Speaker positions](#org1be9e74) for use with the Ircam panoramix package.
    
    ![img](./images/panoramix-hoabus.png "A HOA bus in Panoramix")
    
    The following file may be loaded in a HOA bus track (See [fig:hoabus](#fig:hoabus)) in panormaix by selecting the text below, clicking the `spekers...` button and click `paste` in the upper left corner of the newly opened window.
    
    ```shell
    /speaker/number 13
    /speaker/correction/delay off
    /speaker/correction/gain off
    /speakers/aed 24.6 0 3.26 -26.34 0 3.3 -58.7 0 3.35 -106 0 3.27 -129.35 0 3.364 129.35 0 3.376 106 0 3.262 58.7 0 3.296 45 18 3.02 -45 18 3.02 -135 18 3.05 135 18 3.02 0 90 1.6
    /speaker/1/delay 0
    /speaker/2/delay 0
    /speaker/3/delay 0
    /speaker/4/delay 0
    /speaker/5/delay 0
    /speaker/6/delay 0
    /speaker/7/delay 0
    /speaker/8/delay 0
    /speaker/9/delay 0
    /speaker/10/delay 0
    /speaker/11/delay 0
    /speaker/12/delay 0
    /speaker/13/delay 0
    ```
