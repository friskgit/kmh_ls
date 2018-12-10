
# Ambisonics in KMH studios and Lilla salen


## About the compiled decoders

All decoders use ACN channel order (see [Component order](#orgf3d55cf)) and SN3D normalization (see [Normalisation](#org024c4b3)) and are dual-band, max-rE/rV.


### A guide to the file names

For efficiency file names use the following format

1.  The space (KMHLS\_AE)
2.  Speaker configuration (FullSetup)
3.  Order (7H7P)
4.  Redundant speaker configuration (full)
5.  Type of decoder according to:

-   (1) AllRad mixed order (4/3)

    Mixed order ambisonics decoder.

-   (2) Decoding with the pseudo-inverse, even-energy

    Pinv decoders in 1st, 3rd order with even-energy for inversion variants.

-   (3) Decoding with the pseudo-inverse, mode-matching

    Pinv decoders in 1st, 3rd order, mode-matching for inversion variants

-   (4) Same as (2) and (4) but with a blend coefficient for inversion variants (energy limited/mode matching 50%)

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


<a id="orgf3d55cf"></a>

### Component order

The component order for the input to the decoder follows the ACN (Ambisonics Channel Number) standard according to the table below (for third order):

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-right" />

<col  class="org-right" />

<col  class="org-right" />

<col  class="org-right" />

<col  class="org-right" />

<col  class="org-left" />
</colgroup>
<tbody>
<tr>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-right">0</td>
<td class="org-right">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-right">&#xa0;</td>
<td class="org-right">1</td>
<td class="org-right">2</td>
<td class="org-right">3</td>
<td class="org-right">&#xa0;</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-left">&#xa0;</td>
<td class="org-right">4</td>
<td class="org-right">5</td>
<td class="org-right">6</td>
<td class="org-right">7</td>
<td class="org-right">8</td>
<td class="org-left">&#xa0;</td>
</tr>


<tr>
<td class="org-left">9</td>
<td class="org-right">10</td>
<td class="org-right">11</td>
<td class="org-right">12</td>
<td class="org-right">13</td>
<td class="org-right">13</td>
<td class="org-left">15</td>
</tr>
</tbody>
</table>

Or: W Y Z X V T R S U Q O M K L N P 


<a id="org024c4b3"></a>

### Normalisation

The decoder is using SN3D normalisation. With SN3D normalisation no component will exceed the peak value of the 0th order component.

