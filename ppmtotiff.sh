#!/bin/bash
# Code converts images of '.ppm' formats to '.tiff'
# '.ppm' files should be in retina_ppm directory.
# Change script easily if you want the image folder to be given as arguments.

# Install libtiff-tools
apt-get install libtiff-tools

# Make a directory for the converted images.
mkdir retina_tiff
# Open the ppm folder and convert files.
cd retina_ppm
for i in *.ppm; do ppm2tiff -c none ${i} ../retina_tiff/"${i}"; done
# Open the tiff folder and rename files properly
cd ../retina_tiff/
for f in *.ppm; do   mv ./"$f" ./"${f%.ppm}.tiff"; done
