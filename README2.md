# KFUnitTest
[KFUnitTest](https://github.com/vsandul/KFUnitTest) is an instrument to check correctness of [KFParticle package](https://github.com/Ivan-Kisel/KFParticle) performance. 

To use this package, [KFParticle package](https://github.com/Ivan-Kisel/KFParticle) and [ROOT](https://root.cern/) are neccessary.

*Despite it is called **KFUnitTest**, actually the package is more of an integration test.*

# Instructions to install
## ROOT installation
The present version of the **KFUnitTest** package has been developed and tested within **ROOT v.6.26.04**. Proper work for earlier versions of **ROOT** is not guaranteed.
To install the **ROOT** follow the instruction in [this link](https://root.cern/install/).

## KFParticle installation
1. Download the neccessary branch of **KFParticle** from one of the repositories to folder `<path-to-your-KF-folder/your-KF-folder>`
1. Go to `<your-KF-folder>` and build the package via 
        
        $ cd your-KF-folder
        $ mkdir build
        $ cd build
        $ cmake ..
        $ make

1. Install KFParticle into <install> directory
        
        $ cd ..
        $ mkdir install
        $ make DESTDIR=<path-to-your-KF-folder>/install install

1. Point the install directory as the directory containing libraries and headers of KFParticle. You have to do this in every used terminal, otherwise just put this line into `~/.bashrc` file.
        
        $ export KFPARTICLE_DIR=<path-to-your-KF-folder>/install
        
## KFUnitTest installation
1. Download **KFnitTest** from [the repository](https://github.com/vsandul/KFUnitTest)
1. * Download the MC dataset you are interested in: for this go to subfolder `<MCData/name-of-dataset>` and execute bashscript `download-data-name-of-dataset.sh`;
   * Or download GEANT4 programs and create your own dataset: go to `<GeantPrograms/>` subfolder and execute bashscript `download-program-name-of-dataset.sh` ([GEANT4](https://geant4.web.cern.ch/) is required); after build and execute the GEANT4 program (see `README.md` inside of `GeantPrograms` folder).

# Configuring KFUnitTest
The main configuration file to configure the workflow of the unit test is the `ConfigConstants.h` in the `<UnitTests>` folder.

# Running KFUnitTest

# Interactive KFUnitTest

# KFUnitTest workflow

# Extra KFUnitTest settings
