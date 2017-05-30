# libRerun
A template for creating recording the movements of a VEX Robot and playing them back autonomously.

The SampleFunctions fileset is simply used to provide an example of typical functions that one would use in a rerun configuration. The rerun.h and rerun.c files make up the entirety of the library.

One will need to modify the rerun.c file to some extent in order to use it with a different robot configuration than the one detailed in SampleFunctions. These locations are distinctly marked, it is recommended that editing other portions of the source file be avoided.

The output is printed live as the data is recorded, so it is recommended that you redirect the output of "pros terminal" into a file through the PROS CLI prior to starting the recording process. This file can later be copied into your auto.c file. 
