/*
Used to make input Pythia cards for multiple runs. The options that change are at the end. This includes turning ccbar or bbbar processes on/off, the random number seed, and the pthat binning. 

The text write is ugly, but necessary.

Z. Miller - 8/26/15

 */

void makeCards(Int_t mode=1, Float_t pthatmin=0, Float_t pthatmax=100, Int_t numRuns=25)
{
  if(mode < 1 || mode > 2)
    {
      cout << "Not a valid mode. Choose 1=ccbar, or 2==bbar\n";
      exit(1);
    }
  for(Int_t run=0; run < numRuns; run++){
    // open an output file
    char ch[1000];
    if(mode == 1)
      sprintf(ch,"cardsAug26/NpeC%.0f_%.0f_%i.cmnd",pthatmin,pthatmax,run);
    if(mode == 2)
      sprintf(ch,"cardsAug26/NpeB%.0f_%.0f_%i.cmnd",pthatmin,pthatmax,run);
    
    std::ofstream outfile (ch);
    
    
    outfile << "#==============================================================================\n# STAR Heavy Flavor Tune 1.0\n#\n# PYTHIA Version 8.1.08\n# Date: September 9, 2008\n# Last updated by: Thomas Ullrich\n#\n# This file contains commands to be read in for a Pythia8 run. \n# Lines not beginning with a letter or digit are comments.\n# Names are case-insensitive  -  but spellings-sensitive!\n#==============================================================================\n\n#------------------------------------------------------------------------------\n# Parameters that need to be set by whoever runs it.\n# Note that they have no meaning unless restored and used\n# in the user provided code (main program).\n# This is not part of the star_hf tune (just convenient)\n# Documentation: <pyhiadir>/htmldoc/MainProgramSettings.html\n#------------------------------------------------------------------------------\nMain:numberOfEvents = 500000      ! number of events to generate\nMain:numberToList = 10              ! number of events to print\nMain:timesToShow = 1000            ! show how far along run is this many times\nMain:timesAllowErrors = 50000     ! abort run after this many flawed events\nMain:showChangedSettings = on      ! print changed flags/modes/parameters\nMain:showAllSettings = on          ! print all flags/modes/parameters\nMain:showAllStatistics = on        ! print statistics at the end\n\n#------------------------------------------------------------------------------\n# Colliding beams and center-of-mass energy\n# Documentation: <pyhiadir>/htmldoc/BeamParameters.html\n#------------------------------------------------------------------------------\nBeams:idA = 2212                  ! proton\nBeams:idB = 2212                  ! proton\nBeams:eCM = 200.                  ! RHIC nominal (GeV)\n\n#------------------------------------------------------------------------------\n# Process Selection\n# Make you selection by uncommenting the referring switches\n# \n# Warning: the b and c producing processes do not catch all possible \n# production modes. You would need to use HardQCD:all or even SoftQCD:minBias\n# for that. But the hard ones are the dominating ones and they are in.\n# Note that for pt -> 0 things might go very wrong. A lower pTHat cut avoids\n# this especially for charm and bottom production.\n# Documentation: <pyhiadir>/htmldoc/QCDProcesses.html\n# Documentation: <pyhiadir>/htmldoc/OniaProcesses.html\n#------------------------------------------------------------------------------\n# Uncomment for charmonium\n#Charmonium:all = on   ! charmonium production\n\n# Uncomment for charmonium singlet only\n# Charmonium:gg2QQbar[3S1(1)]g = on\n# Charmonium:gg2QQbar[3P0(1)]g = on\n# Charmonium:gg2QQbar[3P1(1)]g = on\n# Charmonium:gg2QQbar[3P2(1)]g = on\n# Charmonium:qg2QQbar[3P0(1)]q = on\n# Charmonium:qg2QQbar[3P1(1)]q = on\n# Charmonium:qg2QQbar[3P2(1)]q = on\n# Charmonium:qqbar2QQbar[3P0(1)]g = on\n# Charmonium:qqbar2QQbar[3P1(1)]g = on\n# Charmonium:qqbar2QQbar[3P2(1)]g = on\n\n# Uncomment for charmonium octett only\n# Charmonium:gg2QQbar[3S1(8)]g = on\n# Charmonium:gg2QQbar[1S0(8)]g = on\n# Charmonium:gg2QQbar[3PJ(8)]g = on\n# Charmonium:qg2QQbar[3S1(8)]q = on\n# Charmonium:qg2QQbar[1S0(8)]q = on\n# Charmonium:qg2QQbar[3PJ(8)]q = on\n# Charmonium:qqbar2QQbar[3S1(8)]g = on\n# Charmonium:qqbar2QQbar[1S0(8)]g = on\n# Charmonium:qqbar2QQbar[3PJ(8)]g = on\n\n# Uncomment for bottomonium\n# Bottomonium:all = on  ! bottomonium production\n\n# Uncomment for Drell-Yan\n# WeakSingleBoson:ffbar2gmZ = on\n\n# Hard processes main switch \n# HardQCD:all = on\n\n# Minimum bias \n# SoftQCD:minBias = on\n#------------------------------------------------------------------------------\n# K factor\n# Multiply almost all cross sections by this common fix factor.\n# This is usually no very useful. The data can be shifted up and down\n# later anyhow as we please. \n# Documentation: <pyhiadir>/htmldoc/CouplingsAndScales.html\n#------------------------------------------------------------------------------\n# SigmaProcess:Kfactor = 3\n\n#------------------------------------------------------------------------------\n# Scales (Ramona's suggestions)\n# This sets the scale to settings typically for hard probes:\n# mu_F = mu_R = 2*mT\n# Documentation: <pyhiadir>/htmldoc/CouplingsAndScales.html\n#------------------------------------------------------------------------------\nSigmaProcess:renormScale2 = 3\nSigmaProcess:factorScale2 = 3\nSigmaProcess:renormMultFac = 2   ! 2mT\nSigmaProcess:factorMultFac = 2   ! 2mT\n\n#------------------------------------------------------------------------------\n# PDF Selection:\n# Note: you need LHAPDF to be installed. Pythia 8 only provides a \n# minimal set to get started.\n# The choice of PDF here is greatly motivated by:\n# A.~Sherstnev and R.~S.~Thorne, arXiv:0807.2132 and arXiv:0711.2473v3\n# and W. Vogelsang (private communication)\n# These are PDFs especially made for LO Monte-Carlo generators such\n# as PYTHIA.\n# The state-of-the-art NLO PDF is cteq66.LHgrid which can be used\n# as an alternative (also from LHAPDF) but with the known problems\n# that arise when using a NLO PDF in an LO simulator.\n# Documentation: <pyhiadir>/htmldoc/PDFSelection.html\n#------------------------------------------------------------------------------\nPDF:useLHAPDF = on\nPDF:LHAPDFset = MRSTMCal.LHgrid\nPDF:extrapolateLHAPDF = on\n\n#------------------------------------------------------------------------------\n# Settings for the event generation process in the Pythia8 library\n# Effect/Relevance of MI, ISR and FSR need to be checked. For sure\n# the use more CPU and hence less events/s.\n# If HadronLevel:Hadronize = off we end up with the pure c, b spectra\n# (which might be useful at times)\n# Documentation: <pyhiadir>/htmldoc/MasterSwitches.html\n# Documentation: <pyhiadir>/htmldoc/MultipleInteractions.html\n#------------------------------------------------------------------------------\nPartonLevel:MI = on              ! multiple interactions\nPartonLevel:ISR = on             ! initial-state radiation \nBeamRemnants:primordialKT = on    ! primordial kt\nPartonLevel:FSR = on             ! final-state radiation\n#HadronLevel:Hadronize = off     ! no hadronization use\n\n#------------------------------------------------------------------------------\n# Relative production ratio vector/pseudoscalar for charm and bottom mesons\n# This was originally PARJ(13) where PARJ(13) = V/(PS+V) that is the \n# vector meson  fraction of primary charm+bottom mesons. \n# Andre David (CERN\nA60) made an exhaustive study and found that the\n# world data supports 0.6 while PYTHIA default was PARJ(13) = 3/4 = 0.75\n# from simple spin counting.\n# In PYTHIA8 we now use V/PS not V/(PS+V)\n# Documentation: <pyhiadir>/htmldoc/FlavourSelection.html\n#------------------------------------------------------------------------------\nStringFlav:mesonCvector = 1.5    ! same as PARJ(13)=0.6   -> 1.5\nStringFlav:mesonBvector = 3      ! leave at PARJ(13)=0.75 -> 3\n\n#------------------------------------------------------------------------------\n# Heavy quark masses.\n# Note that this should match with the ones used in the PDF.\n# The masses are listed in the header of the refering PDF file.\n# Documentation: <pyhiadir>/htmldoc/ParticleDataScheme.html\n# Documentation: <pyhiadir>/htmldoc/ParticleData.html\n#------------------------------------------------------------------------------\n4:m0 = 1.43\n5:m0 = 4.30\n\n#------------------------------------------------------------------------------# Particle Decay limits\n# When on, only particles with a decay within a volume limited by \n# rho = sqrt(x^2 + y^2) < xyMax and |z| < zMax are decayed. \n# The above xyMax, expressed in mm/c.\n#------------------------------------------------------------------------------\nParticleDecays:limitCylinder = on\nParticleDecays:xyMax = 600\nParticleDecays:zMax = 1000\n\nOther options below set in each card\n\n#------------------------------------------------------------------------------\n# To limit particle production to a certain pthat range uncomment\n# these lines. Use only when you 100% know what you are doing.\n# It is extremely useful to split runs up in ptHat bins to generate\n# statistics evenly in pt. Book keeping is important then (cross-sections,\n# number of events) to compile the final complete spectra.\n# Documentation: <pyhiadir>/htmldoc/PhaseSpaceCuts.html\n#------------------------------------------------------------------------------\n\n#------------------------------------------------------------------------------\n# Random Number\n# Initialize random generator according to time. Otherwise multiple jobs\n# will produce the same sequence (unless you pass a different seed every\n# time which is not practical).\n# Documentation: <pythiadir>/htmldoc/RandomNumberSeed.html\n#------------------------------------------------------------------------------\n"; // End put of standard options

    if(mode == 1)
      {
	outfile << "\n# Uncomment next 2 lines for charm\n"
		<< "HardQCD:gg2ccbar = on    ! g g -> c cbar\n"
		<< "HardQCD:qqbar2ccbar = on ! q qbar -> c cbar\n\n"
		<< "# Uncomment next 2 lines for bottom\n"
		<< "# HardQCD:gg2bbbar = on    ! g g -> b bbar\n"
		<< "# HardQCD:qqbar2bbbar = on ! q qbar -> b bbar\n\n";
      }
    if(mode == 2)
      {
	outfile << "\n# Uncomment next 2 lines for charm\n"
		<< "# HardQCD:gg2ccbar = on    ! g g -> c cbar\n"
		<< "# HardQCD:qqbar2ccbar = on ! q qbar -> c cbar\n\n"
		<< "# Uncomment next 2 lines for bottom\n"
		<< "HardQCD:gg2bbbar = on    ! g g -> b bbar\n"
		<< "HardQCD:qqbar2bbbar = on ! q qbar -> b bbar\n\n";
      }
    
    outfile << "PhaseSpace:pTHatMin = " << pthatmin << "\n"
	    << "PhaseSpace:pTHatMax = " << pthatmax << "\n";
    
    outfile << "Random:setSeed = on\n"
	    << "Random:seed = " << 1000+run << "\n"
	    << "#EOF";
    
    outfile.close();
  }
}
