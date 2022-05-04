1. #### Install KFParticle
     - 1.1 Download KFParticle with  "testsuite" brunch
     - 1.2 unpack it and go to "...KFParticle/" folder
     - 1.3 mkdir build && cd build
     - 1.4 cmake ..
     - 1.5 make
     - 1.6 make DESTDIR=<your_install_dir> install
     - 1.7 cd <your_install_dir> && export $KFPARTICLE_DIR=$(pwd)

2. #### Install and run KFUnitTest
     - 2.1 Download KFUnitTest
     - 2.2 Unpack it
     - 2.3 Download (or generate) MC data and save it to "MCData/your_data/" folder
     - 2.3 Go to the folder ".../KFUnitTest/UnitTests"
     - 2.4 Modify ConfigConstants.h file if it is necessary
     - 2.5 root RunKFUnitTestMacro.cxx

3. #### Explore the outputs
     - 3.1. The first file is the output with 2 trees - KFParticles before reconstrunction and KFParticles after reconstrunction
     - 3.2. The second file is the file with different histograms
