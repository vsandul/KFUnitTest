#!/usr/bin/env python
# coding: utf-8

# # Interactive Unit Test

import ROOT
from bokeh.io import output_notebook
from RootInteractive.Tools.aliTreePlayer import *
from RootInteractive.InteractiveDrawing.bokeh.bokehDrawSA import *
from bokeh.io import curdoc
import numpy as np
import os
import sys
from ROOT import TFile, gSystem
#import plotly.express as px
#output_notebook()
from IPython.display import Image
from IPython.core.display import display, HTML
display(HTML("<style>.container { width:100% !important; }</style>"))
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab
import seaborn as sns
import matplotlib.pyplot as plt
from RootInteractive.Tools.compressArray import arrayCompressionRelative16,arrayCompressionRelative8

import pprint
pp = pprint.PrettyPrinter(indent=4)

from RootInteractive.InteractiveDrawing.bokeh.bokehInteractiveParameters import *
#pp.pprint(figureParameters["legend"])

print("Reading tree...")

# Load some macros (to reed tree and to set some aliases)
ROOT.gROOT.LoadMacro("readTree.C")
ROOT.gROOT.LoadMacro("kinematicFunctions.C")

readTreeStatus = ROOT.readTree();
if readTreeStatus != 0:
    sys.exit("readTree() has been failed with error code " + str(readTreeStatus) + ". Exit.")

#ROOT.treeMC.SetAlias("nTracks", "nTracks")
ROOT.treeMC.SetAlias("initialPT","PT(initialPX, initialPY)")
ROOT.treeMC.SetAlias("finalPT","PT(finalPX, finalPY)")
ROOT.treeMC.SetAlias("initialP","P(initialPX, initialPY, initialPZ)")
ROOT.treeMC.SetAlias("finalP","P(finalPX, finalPY, finalPZ)")
ROOT.treeMC.SetAlias("initialE","E(initialPX, initialPY, initialPZ, mass)")
ROOT.treeMC.SetAlias("finalE","E(finalPX, finalPY, finalPZ, mass)")
ROOT.treeMC.SetAlias("initialEta","Eta(initialPX, initialPY, initialPZ)")
ROOT.treeMC.SetAlias("finalEta","Eta(finalPX, finalPY, finalPZ)")
ROOT.treeMC.SetAlias("initialPhi","Phi(initialPX, initialPY)")
ROOT.treeMC.SetAlias("finalPhi","Phi(finalPX, finalPY)")
ROOT.treeMC.SetAlias("initialTheta","Theta(initialPX, initialPY, initialPZ)")
ROOT.treeMC.SetAlias("finalTheta","Theta(finalPX, finalPY, finalPZ)")

nEntriesMC=ROOT.treeMC.GetEntries()

varListMC = [
    'nTracks', 'trackID', 'parentID', 'pdg', 'charge', 'mass', 'initialX', 'initialY', 'initialZ',
    'finalX', 'finalY', 'finalZ', 'trackLength', 'initialPX', 'initialPY', 'initialPZ',
    'finalPX', 'finalPY', 'finalPZ', 'initialGlobalTime', 'finalGlobalTime', 
    'initialPT', 'finalPT', 'initialP', 'finalP', 'initialE', 'finalE',
    'initialEta', 'finalEta', 'initialPhi', 'finalPhi', 'initialTheta', 'finalTheta'
]

columnMask=[["particle__particle_f","p_"]] #????????
particlesMC = tree2Panda(ROOT.treeMC, varListMC, "1", exclude=[], columnMask=columnMask,nEntries=nEntriesMC) #?????

pd.set_option('display.max_columns', None)

nEntriesKFAR=ROOT.treeKFAR.GetEntries()

varListKFAR = [
    'nTracks', 'numOfMCEvent', 'isAllCovMatOK', 'constructMethod',
    'ID', 'IDMC', 'pdgID', 'isCovMatOK', 'massConstraint', 'topoConstraint',
    'x', 'y', 'z', 'pX', 'pY', 'pZ', 'e', 's', 'charge', 'chi2',
    'ndf', 'massHypo', 'isMother', 'isDaughter', 'p', 'pT', 'eta',
    'phi', 'mass', 'decayLength', 'decayLengthXY', 'lifeTime',
    'r', 'rapidity', 'theta', 'xErr', 'yErr', 'zErr', 'pXErr',
    'pYErr', 'pZErr', 'eErr', 'sErr', 'pErr', 'pTErr', 'etaErr',
    'phiErr', 'massErr', 'decayLengthErr', 'decayLengthXYErr',
    'lifeTimeErr', 'rErr',
]

columnMask=[["particle__particle_f","p_"]] #????????
particlesKFAR = tree2Panda(ROOT.treeKFAR, varListKFAR, "1", exclude=[], columnMask=columnMask,nEntries=nEntriesKFAR) #?????

#import pandas as pd
particles = particlesMC.join(particlesKFAR,lsuffix="_MC", rsuffix="_KFAR")
initMetadata(particles)


particles['Xres'] = particles['x'] - np.where(particles['isMother']==1.0, particles['finalX'], particles['initialX'])
particles['Yres'] = particles['y'] - np.where(particles['isMother']==1.0, particles['finalY'], particles['initialY'])
particles['Zres'] = particles['z'] - np.where(particles['isMother']==1.0, particles['finalZ'], particles['initialZ'])

particles['PXres'] = particles['pX'] - np.where(particles['isMother']==1.0, particles['finalPX'], particles['initialPX'])
particles['PYres'] = particles['pY'] - np.where(particles['isMother']==1.0, particles['finalPY'], particles['initialPY'])
particles['PZres'] = particles['pZ'] - np.where(particles['isMother']==1.0, particles['finalPZ'], particles['initialPZ'])

particles['Massres'] = particles['mass_KFAR'] - particles['mass_MC']
particles['PTres'] = particles['pT'] - np.where(particles['isMother']==1.0, particles['initialPT'], particles['finalPT'])
particles['Eres'] = particles['e'] - np.where(particles['isMother']==1.0, particles['finalE'], particles['initialE'])

#-----------

# Pulls

particles['Xpull'] = particles['Xres'] / particles['xErr']
particles['Ypull'] = particles['Yres'] / particles['yErr']
particles['Zpull'] = particles['Zres'] / particles['zErr']

particles['PXpull'] = particles['PXres'] / particles['pXErr']
particles['PYpull'] = particles['PYres'] / particles['pYErr']
particles['PZpull'] = particles['PZres'] / particles['pZErr']

particles['Masspull'] = particles['Massres'] / particles['massErr']
particles['PTpull'] = particles['PTres'] / particles['pTErr']
particles['Epull'] = particles['Eres'] / particles['eErr']

particles["indexMI"]=particles.index


#AxisTitles
#particles.meta.metaData = {'Xres.AxisTitle': "Xres (cm)", }


# Create Rootinteractive interface

print("Creating RootInteractive interface...")
# statistic parameterization
figureParameters["StatParam"]={}
figureParameters["StatParam"]["parameterArray"]=[
        {"name": "nPointsRender", "range":[10, 5000], "value": 350},
]

figureParameters["StatParam"]["widgets"]=[
    ['slider', ['nPointsRender'], {"name": "nPointsRender"}],
#    ['range', ['indexMI'], {"index": True}],
]
figureParameters["StatParam"]["widgetLayout"]=[
    ["nPointsRender"]
]

parameterArray = [
    {"name": "paramX", "value":10, "range": [-20, 20]},
    {"name": "C_cut", "value": 1, "range": [0, 1]},
    {"name": "nPoints", "range":[0, 1200], "value": 1000},
]
parameterArray.extend(figureParameters["legend"]['parameterArray'])   # add legend configuration as in the default 
parameterArray.extend(figureParameters["markers"]['parameterArray'])   # add legend configuration as in the default 
parameterArray.extend(figureParameters["StatParam"]['parameterArray'])   # add legend configuration as in the default 
#
widgetParams=[
              ['range', ['finalPT']], #0
              ['range', ['finalEta']], #1
              ['range', ['finalPhi']], #2
              #
              ['multiSelect', ['pdg']], #3
              ['multiSelect', ['isMother']], #4
              ['multiSelect', ['isAllCovMatOK']], #5
              ['multiSelect', ['constructMethod']], #6
              ['multiSelect', ['massConstraint']], #7
              ['multiSelect', ['topoConstraint']], #8
]

widgetParams.extend(figureParameters["legend"]["widgets"])
widgetParams.extend(figureParameters["markers"]["widgets"])
widgetParams.extend(figureParameters["StatParam"]["widgets"])

widgetLayoutDesc0=[[0,1,2],[3,4,5,6,7,8], {'sizing_mode': 'scale_width'}] 
#
widgetLayoutDesc={
    "Data selection":widgetLayoutDesc0,
    "Legend": figureParameters['legend']['widgetLayout'],
    "Markers":["markerSize"],
    "Stat":figureParameters['StatParam']['widgetLayout'],
}

#figureGlobalOption={"size":"size"}
figureGlobalOption={}
figureGlobalOption=figureParameters["legend"]["figureOptions"]
figureGlobalOption["size"]="markerSize"

histoArray=[]
jsFunctionArray=[]
aliasArray=[]


tooltips = [("initialPT", "(@initialPT)")]

figureArray = [
    # residuals
    [['initialPT'], ['Xres'], { "colorZvar": "pdg"}], #0
    [['initialPT'], ['Yres'], { "colorZvar": "pdg"}], #1
    [['initialPT'], ['Zres'], { "colorZvar": "pdg"}], #2
    
    [['initialPT'], ['PXres'], { "colorZvar": "pdg"}], #3
    [['initialPT'], ['PYres'], { "colorZvar": "pdg"}], #4
    [['initialPT'], ['PZres'], { "colorZvar": "pdg"}], #5
    
    [['initialPT'], ['Massres'], { "colorZvar": "pdg"}], #6
    [['initialPT'], ['PTres'], { "colorZvar": "pdg"}], #7
    [['initialPT'], ['Eres'], { "colorZvar": "pdg"}], #8
    
    # pulls
    [['initialPT'], ['Xpull'], { "colorZvar": "pdg"}], #9
    [['initialPT'], ['Ypull'], { "colorZvar": "pdg"}], #10
    [['initialPT'], ['Zpull'], { "colorZvar": "pdg"}], #11
    
    [['initialPT'], ['PXpull'], { "colorZvar": "pdg"}], #12
    [['initialPT'], ['PYpull'], { "colorZvar": "pdg"}], #13
    [['initialPT'], ['PZpull'], { "colorZvar": "pdg"}], #14
    
    [['initialPT'], ['Masspull'], { "colorZvar": "pdg"}], #15
    [['initialPT'], ['PTpull'], { "colorZvar": "pdg"}], #16
    [['initialPT'], ['Epull'], { "colorZvar": "pdg"}], #17
    

    #[["bin_center"],["itsFindable","itsRefit","entries"],{"source":"histoPt","yAxisTitle":"N", "xAxisTitle":"pt (Gev)"}],
    #[["bin_center"],["trdFindable","trdRefit","entries"],{"source":"histoPt","yAxisTitle":"N", "xAxisTitle":"pt (Gev)"}],
    #[["bin_center"],["tofFindable","tofRefit","entries"],{"source":"histoPt","yAxisTitle":"N", "xAxisTitle":"pt (Gev)"}], 
    #[["bin_center"],["eff_itsFindable","eff_itsRefit"],{"source":"histoPt","yAxisTitle":"eff", "xAxisTitle":"pt (Gev)","errY":["eff_itsFindableErr","eff_itsRefitErr"]}],
    #[["bin_center"],["eff_trdFindable","eff_trdRefit"],{"source":"histoPt","yAxisTitle":"eff", "xAxisTitle":"pt (Gev)","errY":["eff_trdFindableErr","eff_trdRefitErr"]}],
    #[["bin_center"],["eff_tofFindable","eff_tofRefit"],{"source":"histoPt","yAxisTitle":"eff", "xAxisTitle":"pt (Gev)","errY":["eff_tofFindableErr","eff_tofRefitErr"]}],
    #figureGlobalOption
]

figureLayoutDesc={
    "Residuals vs PT": [
        [0, 1, 2,   {  'plot_height': 250}],
        [3, 4, 5,   {  'plot_height': 250}],
        [6, 7, 8,   {  'plot_height': 250}],
        {'plot_height': 200, 'sizing_mode': 'scale_width'} 
    ],
    "Pulls vs PT": [
        [9, 10, 11,   {  'plot_height': 250}],
        [12, 13, 14,   {  'plot_height': 250}],
        [15, 16, 17,   {  'plot_height': 250}],
        {'plot_height': 200, 'sizing_mode': 'scale_width'} 
    ]
    
}


#%pdb

outputFileName = "InteractiveTest.html"
output_file(outputFileName)
fig=bokehDrawSA.fromArray(particles, "finalPT>-1", figureArray, widgetParams, layout=figureLayoutDesc, tooltips=tooltips, parameterArray=parameterArray,
                          widgetLayout=widgetLayoutDesc, sizing_mode="scale_width", nPointRender="nPointsRender", jsFunctionArray=jsFunctionArray,
                           aliasArray=aliasArray,
                          histogramArray=histoArray,
                          arrayCompression=arrayCompressionRelative16)



print("Interactive test is created and saved in "+outputFileName)


