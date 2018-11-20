

# Ambisonics in KMH studios and Lilla salen

## About the compiled decoders

All decoders use ACN channel order (see [Component order](#org73764d8)) and SN3D normalization (see [Normalisation](#orgcc22c51)) and are dual-band, max-rE/rV.


### A guide to the file names

For efficiency file names use the following format

1.  The space (KMHLS\_AE)
2.  Speaker configuration (FullSetup)
3.  Order (7H7P)
4.  Redundant speaker configuration (full)
5.  Type of decoder according to:

-   (1) AllRad mixed order (4/3)

    Mixed order ambisonics decoder.

-   (2) Decoding with the pseudoinverse

    Pinv decoders in 1st, 3rd order.

-   (4) Same as (2) but with a blend coefficient for inversion variants (energy limited/mode matching 50%)

    1st and 3rd and 6th order.

-   (5) Spherical slepian decoders

    SSF decoders in 1st, 3rd and 6th order (6th order is here only as VST, but I can compile the other formats if needed.)

-   (6) All-round decoders

    AllRAD decoders in 1st, 3rd, 5th and 7th order.


### Formats

1.  VST
2.  Max/MSP (as package with help file to be put in ~/Documents/Max 7/Packages)
3.  Pd (bang left most input to get parameter names)
4.  SuperCollider (put all .sc and .scx in ~/Library/Application Support/SuperCollider/Extensions (supernova is of course optional)
5.  Ambix config file


### Speakers

In Klangkupolen the channel order from the mixer is channel 1-29 for the regular dome. The lower ring starts at channel 33-48 and the subs are at 49-52. This is the reason that in the decoder the names for the sixteen floor speakers start at 33.


### Comments

-   (1) AllRad mixed order (4/3)

    Mixed order ambisonics decoder

-   (2) Decoding with the pseudoinverse

    Pinv decoders in 1st and 3rd.

-   (4) Same as (2) but with a blend coefficient for inversion variants (energy limited/mode matching 50%)

    Up to 3rd.

-   (5) Spherical slepian decoders

    SSF decoders in 1st, 3rd and 5th order (up to 6th).

-   (6) All-round decoders

    AllRAD decoders in 1st, 3rd, 5th and 7th order.

