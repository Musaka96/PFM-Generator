# PFM Generator (cppTest4 ^^)

PFM Generator is an Unreal Engine project for generating PFM geometry files for use with nDisplay plugin.

# Process:
  - Create the right mesh
  - Attach a mesh to the "script attached actor as a child"
  - Export


-----------------
### 1. Creating the right mesh file

In order to know what mesh file you need, you need to know the aspect ratio you will be using for that paticular projection and the shape/orientation/curve of the space you will be outputing.

The mesh has to have a full UV channel as the output will be mapped by it:

![](http://10.10.10.28/milosromanic/PFM-Generator/blob/master/Documentation/11.PNG "UV channel 0")