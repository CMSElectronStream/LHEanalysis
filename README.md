LHEanalysis
===========

Simple LHE analysis


to compile:

    c++ -o ntupleMaker.exe `root-config --glibs --cflags` -lm ntupleMaker.cpp

to use:

    ./ntupleMaker.exe fileLHE outputFileRoot
    ./ntupleMaker.exe /data2/amassiro/Generation/MG5/MG5_aMC_v2_0_1/MY_W_LO/Events/run_01/unweighted_events.lhe   W13TeV.root
    ./ntupleMaker.exe /data2/amassiro/Generation/MG5/MG5_aMC_v2_0_1/MY_W_LO_new/Events/run_01/unweighted_events.lhe   W13TeV_new.root

draw:

    r99t W13TeV.root draw.cxx
    r99t W13TeV.root drawEta.cxx


    r99t W13TeV_new.root draw.cxx
    r99t W13TeV_new.root drawEta.cxx


where: 

    /data2/amassiro/Generation/CMSSW_6_2_2/src/LHEanalysis



