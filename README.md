# Material-XML
<a href="url"><img src="application.png" align="top" height="auto" width="auto" ></a>   
A QT GUI application for analyzing XML materials exported from [Smash Forge](https://github.com/jam1garner/Smash-Forge).
A dump of XML material files for most of the models in Smash 4 for Wii U can be
found [here](https://github.com/ScanMountGoat/Sm4sh-Material-Research/blob/master/XML%20Materials/Smash%20XML%20Materials.7z). For bugs or feature suggestions, please use the [Issues page](https://github.com/ScanMountGoat/Smash-Material-XML/issues).

## Usage Guide
The application maintains a single list of xml materials. Each search creates a filtered list of materials based on the search settings used. Not specifying any search settings will include all materials.

### Main Toolbar
**File > Add material from file:** all the materials in the selected XML file will be added to the
materials list.  
**File > Add material from folder:** all the materials in all XML files in the selected directory,
including all subdirectories, will be added to the materials list.  
**Clear materials:** all materials previously added to the materials list will be removed.  
**View > About:** displays a link to the license information.

### Search Button
Finds all the materials in the current material list that match the given search criteria and prints their information.

### Clear Output Button
Clears all the printed text output. To remove the materials from the current material list, use File > Clear Materials instead.

### Search Properties  
Flags values are 8 digit hexadecimal numbers. The src, dst, cull mode, alpha function, and alpha test use the same format as the XML materials. When filtering for a certain property is enabled, the material value is compared to the value in the text box using the operator in the drop down menu.  

### Display Settings
These settings control what material attributes are printed for each of the materials that matches the given search criteria.

## Material Resources  
* [Material Research](https://github.com/ScanMountGoat/Sm4sh-Material-Research): XML material dump and dumped values for NU_ material properties, flags, etc.
* [Material Editing Guide I](https://gamebanana.com/tuts/12139): Tutorial explaining common material properties and how to edit materials.
* [Material Editing Guide II](https://gamebanana.com/tuts/12214): Tutorial explaining more advanced material properties and example materials.


## Credits
The application is based on the XML material import/export and NUD materials used in Smash Forge.
* [Smash Forge](https://github.com/jam1garner/Smash-Forge)
* Copyright (c) 2017 jam1garner, Ploaj, Sammi Husky, smb123w64gb, SMG
* [MIT License](https://github.com/jam1garner/Smash-Forge/blob/master/License.txt)
