/*
  File:  bdecayP.h
  This file creates the parameter tree structure and must be
  edited in parallel with bdecayParameters_standalone.h
  mod 1Sep05 by JPC for 03034 and 05028
*/
  
  
//CEvent* CTreeParameter::pEvent = NULL;
//vector<CTreeParameter*> CTreeParameter::pSelf;

betadecay bdecay = {

  /* Bit registers */
  {
    *(new CTreeParameter("bdecay.bit.betabit1", 16)),
    *(new CTreeParameter("bdecay.bit.betabit2", 16)),
    *(new CTreeParameter("bdecay.bit.nodatamask", 16)),
    *(new CTreeParameter("bdecay.bit.calhitmask", 12)),
    *(new CTreeParameter("bdecay.bit.corrmask", 16))
  },
  
  /* Clock */
  {
    *(new CTreeParameter("bdecay.clock.fast", 16)),
    *(new CTreeParameter("bdecay.clock.slow", 16)),
    *(new CTreeParameter("bdecay.clock.current", 32)),
    *(new CTreeParameter("bdecay.clock.csis1",16)),
    *(new CTreeParameter("bdecay.clock.csis2",16)),
    *(new CTreeParameter("bdecay.clock.csiscurrent",32))
  },

  /* ADCs */
  {
    *(new CTreeParameterArray("bdecay.adc.adc01", 12, 32, 0)),
    *(new CTreeParameterArray("bdecay.adc.adc02", 12, 32, 0)),
    *(new CTreeParameterArray("bdecay.adc.adc03", 12, 32, 0)),
    *(new CTreeParameterArray("bdecay.adc.adc04", 12, 32, 0)),
    *(new CTreeParameterArray("bdecay.adc.adc05", 12, 32, 0)),
    *(new CTreeParameterArray("bdecay.adc.adc06", 12, 32, 0)),
    *(new CTreeParameterArray("bdecay.adc.adc07", 12, 32, 0)),
    *(new CTreeParameterArray("bdecay.adc.adc08", 12, 32, 0))
  },

  /* TDCs */
  {
    *(new CTreeParameterArray("bdecay.tdc.tdc01", 12, 32, 0))
  },

  /* PIN00 */
  {
    *(new CTreeParameter("bdecay.pin00.energy", 12)),
    *(new CTreeParameter("bdecay.pin00.time", 12)),
    *(new CTreeParameter("bdecay.pin00.ecal", 12))
  },

  /* PIN01 */
  {
    *(new CTreeParameter("bdecay.pin01.energy", 12)),
    *(new CTreeParameter("bdecay.pin01.time", 12)),
    *(new CTreeParameter("bdecay.pin01.ecal", 12))
  },

  /* PIN02 */
  {
    *(new CTreeParameter("bdecay.pin02.energy", 12)),
    *(new CTreeParameter("bdecay.pin02.time", 12)),
    *(new CTreeParameter("bdecay.pin02.ecal", 12))
  },

  /* PIN03 */
  {
    *(new CTreeParameter("bdecay.pin03.energy", 12)),
    *(new CTreeParameter("bdecay.pin03.time", 12)),
    *(new CTreeParameter("bdecay.pin03.ecal", 12))
  },

  /* PIN04 */
  {
    *(new CTreeParameter("bdecay.pin04.energy", 12)),
    *(new CTreeParameter("bdecay.pin04.time", 12)),
    *(new CTreeParameter("bdecay.pin04.ecal", 12))
  },

  /* N3 beamline scintillator */
  {
    *(new CTreeParameter("bdecay.n3scint.energy", 12)),
    *(new CTreeParameter("bdecay.n3scint.time", 12)),
    *(new CTreeParameter("bdecay.n3scint.ecal", 12))
  },

  /* RF */
  {
    *(new CTreeParameter("bdecay.rf.time", 12))
  },

  /* Image 2 scintillator, south PMT */
  {
    *(new CTreeParameter("bdecay.i2s.time", 12))
  },

   /* Image 2 scintillator, north PMT */
  {
    *(new CTreeParameter("bdecay.i2n.time", 12))
  },

   /* Ge crystal */
  {
    *(new CTreeParameter("bdecay.ge.energy", 12)),
    *(new CTreeParameter("bdecay.ge.time", 12)),
    *(new CTreeParameter("bdecay.ge.ecal", 12))
  },

  /* DSSD front */
 
  {
    *(new CTreeParameterArray("bdecay.front.hienergy", 12, 41, 0)),
    *(new CTreeParameterArray("bdecay.front.loenergy", 12, 41, 0)),
    *(new CTreeParameterArray("bdecay.front.hiecal", 12, 41, 0)),
    *(new CTreeParameterArray("bdecay.front.loecal", 12, 41, 0)),
    *(new CTreeParameter("bdecay.front.icent", 6)),
    *(new CTreeParameter("bdecay.front.dcent", 6)),
    *(new CTreeParameter("bdecay.front.imax", 12)),
    *(new CTreeParameter("bdecay.front.dmax", 12)),
    *(new CTreeParameter("bdecay.front.imaxch", 6)),
    *(new CTreeParameter("bdecay.front.dmaxch", 6)),
    *(new CTreeParameter("bdecay.front.imult", 6)),
    *(new CTreeParameter("bdecay.front.dmult", 6)),
    *(new CTreeParameter("bdecay.front.isum", 13)),
    *(new CTreeParameter("bdecay.front.dsum", 13))
  },

  /* DSSD back */
  {
    *(new CTreeParameterArray("bdecay.back.hienergy", 12, 41, 0)),
    *(new CTreeParameterArray("bdecay.back.loenergy", 12, 41, 0)),
    *(new CTreeParameterArray("bdecay.back.hiecal", 12, 41, 0)),
    *(new CTreeParameterArray("bdecay.back.loecal", 12, 41, 0)),
    *(new CTreeParameter("bdecay.back.icent", 6)),
    *(new CTreeParameter("bdecay.back.dcent", 6)),
    *(new CTreeParameter("bdecay.back.imax", 12)),
    *(new CTreeParameter("bdecay.back.dmax", 12)),
    *(new CTreeParameter("bdecay.back.imaxch", 6)),
    *(new CTreeParameter("bdecay.back.dmaxch", 6)),
    *(new CTreeParameter("bdecay.back.imult", 6)),
    *(new CTreeParameter("bdecay.back.dmult", 6)),
    *(new CTreeParameter("bdecay.back.isum", 13)),
    *(new CTreeParameter("bdecay.back.dsum", 13))
  },

  /* SSSD1 */
  {
    *(new CTreeParameterArray("bdecay.sssd1.hienergy", 12, 17, 0)),
    *(new CTreeParameterArray("bdecay.sssd1.hiecal", 12, 17, 0)),
    *(new CTreeParameterArray("bdecay.sssd1.loenergy", 12, 17, 0)),
    *(new CTreeParameterArray("bdecay.sssd1.loecal", 12, 17, 0)),
    *(new CTreeParameter("bdecay.sssd1.hicent", 6)),
    *(new CTreeParameter("bdecay.sssd1.himax", 12)),
    *(new CTreeParameter("bdecay.sssd1.himaxch", 6)),
    *(new CTreeParameter("bdecay.sssd1.himult", 6)),
    *(new CTreeParameter("bdecay.sssd1.hisum", 13)),
    *(new CTreeParameter("bdecay.sssd1.locent", 6)),
    *(new CTreeParameter("bdecay.sssd1.lomax", 12)),
    *(new CTreeParameter("bdecay.sssd1.lomaxch", 6)),
    *(new CTreeParameter("bdecay.sssd1.lomult", 6)),
    *(new CTreeParameter("bdecay.sssd1.losum", 13))
  },

  /* Total energies */
  {
    *(new CTreeParameter("bdecay.total.dsum", 13)),
    *(new CTreeParameter("bdecay.total.dmax", 12)),
    *(new CTreeParameter("bdecay.total.isum", 13)),
    *(new CTreeParameter("bdecay.total.imax", 12))
  },

  /* SeGA detectors */
  {
    *(new CTreeParameterArray("bdecay.sega.energy", 13, 17, 0)),
    *(new CTreeParameterArray("bdecay.sega.time", 12, 17, 0)),
    *(new CTreeParameterArray("bdecay.sega.ecal", 13, 17, 0))
  },

  /* Total gamma energy */
  {
    *(new CTreeParameter("bdecay.segatotal.mult", 5)),
    *(new CTreeParameter("bdecay.segatotal.total", 13)),
    *(new CTreeParameter("bdecay.segatotal.tot11", 11)),
    *(new CTreeParameter("bdecay.segatotal.xmatrix", 12)),
    *(new CTreeParameter("bdecay.segatotal.ymatrix", 12))
  },
  
  /* TAC parameters */
  {
    *(new CTreeParameter("bdecay.tac.rf", 12)),
    *(new CTreeParameter("bdecay.tac.ge", 12)),
    *(new CTreeParameter("bdecay.tac.i2stof", 12)),
    *(new CTreeParameter("bdecay.tac.i2ntof", 12)),
    *(new CTreeParameter("bdecay.tac.i2scorr", 12)),
    *(new CTreeParameter("bdecay.tac.i2ncorr", 12)),
    *(new CTreeParameter("bdecay.tac.i2pos", 12))
  },

  /* Correlation parameters */
  {
    *(new CTreeParameter("bdecay.corr.dtimplant", 16)),
    *(new CTreeParameter("bdecay.corr.itime", 32)),
    *(new CTreeParameter("bdecay.corr.ide1", 12)),
    *(new CTreeParameter("bdecay.corr.ide2", 12)),
    *(new CTreeParameter("bdecay.corr.ide3", 12)),
    *(new CTreeParameter("bdecay.corr.ide4", 12)),
    *(new CTreeParameter("bdecay.corr.iisum", 13)),
    *(new CTreeParameter("bdecay.corr.iimax", 13)),
    *(new CTreeParameter("bdecay.corr.itof", 12)),
    *(new CTreeParameter("bdecay.corr.dtime", 32)),
    *(new CTreeParameter("bdecay.corr.dde1", 12)),
    *(new CTreeParameter("bdecay.corr.dde2", 12)),
    *(new CTreeParameter("bdecay.corr.dde3", 12)),
    *(new CTreeParameter("bdecay.corr.dde4", 12)),
    *(new CTreeParameter("bdecay.corr.disum", 13)),
    *(new CTreeParameter("bdecay.corr.dimax", 13)),
    *(new CTreeParameter("bdecay.corr.dtof", 12)),
    *(new CTreeParameter("bdecay.corr.dtimecal", 16)),
    *(new CTreeParameter("bdecay.corr.flag1", 6))
  },

  /* PID */
  {
    *(new CTreeParameter("bdecay.pid.i2stof", 12)),
    *(new CTreeParameter("bdecay.pid.i2ntof", 12)),
    *(new CTreeParameter("bdecay.pid.rftof", 12)),
    *(new CTreeParameter("bdecay.pid.xfptof", 12)),
    *(new CTreeParameter("bdecay.pid.de0", 12)),
    *(new CTreeParameter("bdecay.pid.de1", 12)),
    *(new CTreeParameter("bdecay.pid.de2", 12)),
    *(new CTreeParameter("bdecay.pid.de3", 12)),
    *(new CTreeParameter("bdecay.pid.de4", 12)),
    *(new CTreeParameter("bdecay.pid.isum", 13)),
    *(new CTreeParameter("bdecay.pid.imax", 13))
  }, 

  /* Temperature monitor */
  {
    *(new CTreeParameter("bdecay.temp.temp", 9)),
    *(new CTreeParameter("bdecay.temp.clock", 16))
  }

};

struct detector nero = {
  /* Bit registers*/
  {
    *(new CTreeParameter("nero.coincregister.quadAhitpattern",16)),
    *(new CTreeParameter("nero.coincregister.quadBhitpattern",16)),
    *(new CTreeParameter("nero.coincregister.quadChitpattern",16)),
    *(new CTreeParameter("nero.coincregister.quadDhitpattern",16)), 
    *(new CTreeParameter("nero.coincregister.multiplicity",6)),
    *(new CTreeParameter("nero.coincregister.nodatamask", 16)),
    *(new CTreeParameter("nero.coincregister.timesum",12))
  },
  
  
  /* Quadrant A*/
  {
    *(new CTreeParameter("nero.quadrantA.0.energy", 12)),
    *(new CTreeParameter("nero.quadrantA.0.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantA.0.time",20)),
    *(new CTreeParameter("nero.quadrantA.0.timecal",12)),
    *(new CTreeParameter("nero.quadrantA.1.energy", 12)),
    *(new CTreeParameter("nero.quadrantA.1.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantA.1.time",20)),
    *(new CTreeParameter("nero.quadrantA.1.timecal",12)),
    *(new CTreeParameter("nero.quadrantA.2.energy", 12)),
    *(new CTreeParameter("nero.quadrantA.2.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantA.2.time",20)),
    *(new CTreeParameter("nero.quadrantA.2.timecal",12)),
    *(new CTreeParameter("nero.quadrantA.3.energy", 12)),
    *(new CTreeParameter("nero.quadrantA.3.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantA.3.time",20)),
    *(new CTreeParameter("nero.quadrantA.3.timecal",12)),
    *(new CTreeParameter("nero.quadrantA.4.energy", 12)),
    *(new CTreeParameter("nero.quadrantA.4.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantA.4.time",20)),
    *(new CTreeParameter("nero.quadrantA.4.timecal",12)),
    *(new CTreeParameter("nero.quadrantA.5.energy", 12)),
    *(new CTreeParameter("nero.quadrantA.5.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantA.5.time",20)),
    *(new CTreeParameter("nero.quadrantA.5.timecal",12)),
    *(new CTreeParameter("nero.quadrantA.6.energy", 12)),
    *(new CTreeParameter("nero.quadrantA.6.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantA.6.time",20)),
    *(new CTreeParameter("nero.quadrantA.6.timecal",12)),
    *(new CTreeParameter("nero.quadrantA.7.energy", 12)),
    *(new CTreeParameter("nero.quadrantA.7.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantA.7.time",20)),
    *(new CTreeParameter("nero.quadrantA.7.timecal",12)),
    *(new CTreeParameter("nero.quadrantA.8.energy", 12)),
    *(new CTreeParameter("nero.quadrantA.8.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantA.8.time",20)),
    *(new CTreeParameter("nero.quadrantA.8.timecal",12)),
    *(new CTreeParameter("nero.quadrantA.9.energy", 12)),
    *(new CTreeParameter("nero.quadrantA.9.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantA.9.time",20)),
    *(new CTreeParameter("nero.quadrantA.9.timecal",12)),
    *(new CTreeParameter("nero.quadrantA.10.energy", 12)),
    *(new CTreeParameter("nero.quadrantA.10.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantA.10.time",20)),
    *(new CTreeParameter("nero.quadrantA.10.timecal",12)),
    *(new CTreeParameter("nero.quadrantA.11.energy", 12)),
    *(new CTreeParameter("nero.quadrantA.11.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantA.11.time",20)),
    *(new CTreeParameter("nero.quadrantA.11.timecal",12)),
    *(new CTreeParameter("nero.quadrantA.12.energy", 12)),
    *(new CTreeParameter("nero.quadrantA.12.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantA.12.time",20)),	
    *(new CTreeParameter("nero.quadrantA.12.timecal",12)),
    *(new CTreeParameter("nero.quadrantA.13.energy", 12)),
    *(new CTreeParameter("nero.quadrantA.13.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantA.13.time",20)),
    *(new CTreeParameter("nero.quadrantA.13.timecal",12)),
    *(new CTreeParameter("nero.quadrantA.14.energy", 12)),
    *(new CTreeParameter("nero.quadrantA.14.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantA.14.time",20)),
    *(new CTreeParameter("nero.quadrantA.14.timecal",12)),
    *(new CTreeParameter("nero.quadrantA.15.energy", 12)),
    *(new CTreeParameter("nero.quadrantA.15.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantA.15.time",20)),
    *(new CTreeParameter("nero.quadrantA.15.timecal",12))
  },
  /* Quadrant B */
  {
    *(new CTreeParameter("nero.quadrantB.0.energy", 12)),
    *(new CTreeParameter("nero.quadrantB.0.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantB.0.time",20)),
    *(new CTreeParameter("nero.quadrantB.0.timecal",12)),
    *(new CTreeParameter("nero.quadrantB.1.energy", 12)),
    *(new CTreeParameter("nero.quadrantB.1.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantB.1.time",20)),
    *(new CTreeParameter("nero.quadrantB.1.timecal",12)),
    *(new CTreeParameter("nero.quadrantB.2.energy", 12)),
    *(new CTreeParameter("nero.quadrantB.2.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantB.2.time",20)),
    *(new CTreeParameter("nero.quadrantB.2.timecal",12)),
    *(new CTreeParameter("nero.quadrantB.3.energy", 12)),
    *(new CTreeParameter("nero.quadrantB.3.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantB.3.time",20)),
    *(new CTreeParameter("nero.quadrantB.3.timecal",12)),
    *(new CTreeParameter("nero.quadrantB.4.energy", 12)),
    *(new CTreeParameter("nero.quadrantB.4.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantB.4.time",20)),
    *(new CTreeParameter("nero.quadrantB.4.timecal",12)),
    *(new CTreeParameter("nero.quadrantB.5.energy", 12)),
    *(new CTreeParameter("nero.quadrantB.5.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantB.5.time",20)),
    *(new CTreeParameter("nero.quadrantB.5.timecal",12)),
    *(new CTreeParameter("nero.quadrantB.6.energy", 12)),
    *(new CTreeParameter("nero.quadrantB.6.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantB.6.time",20)),
    *(new CTreeParameter("nero.quadrantB.6.timecal",12)),
    *(new CTreeParameter("nero.quadrantB.7.energy", 12)),
    *(new CTreeParameter("nero.quadrantB.7.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantB.7.time",20)),
    *(new CTreeParameter("nero.quadrantB.7.timecal",12)),	
    *(new CTreeParameter("nero.quadrantB.8.energy", 12)),
    *(new CTreeParameter("nero.quadrantB.8.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantB.8.time",20)),
    *(new CTreeParameter("nero.quadrantB.8.timecal",12)),
    *(new CTreeParameter("nero.quadrantB.9.energy", 12)),
    *(new CTreeParameter("nero.quadrantB.9.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantB.9.time",20)),
    *(new CTreeParameter("nero.quadrantB.9.timecal",12)),
    *(new CTreeParameter("nero.quadrantB.10.energy", 12)),
    *(new CTreeParameter("nero.quadrantB.10.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantB.10.time",20)),
    *(new CTreeParameter("nero.quadrantB.10.timecal",12)),
    *(new CTreeParameter("nero.quadrantB.11.energy", 12)),
    *(new CTreeParameter("nero.quadrantB.11.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantB.11.time",20)),
    *(new CTreeParameter("nero.quadrantB.11.timecal",12)),
    *(new CTreeParameter("nero.quadrantB.12.energy", 12)),
    *(new CTreeParameter("nero.quadrantB.12.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantB.12.time",20)),
    *(new CTreeParameter("nero.quadrantB.12.timecal",12)),
    *(new CTreeParameter("nero.quadrantB.13.energy", 12)),
    *(new CTreeParameter("nero.quadrantB.13.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantB.13.time",20)),
    *(new CTreeParameter("nero.quadrantB.13.timecal",12)),
    *(new CTreeParameter("nero.quadrantB.14.energy", 12)),
    *(new CTreeParameter("nero.quadrantB.14.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantB.14.time",20)),
    *(new CTreeParameter("nero.quadrantB.14.timecal",12)),
    *(new CTreeParameter("nero.quadrantB.15.energy", 12)),
    *(new CTreeParameter("nero.quadrantB.15.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantB.15.time",20)),
    *(new CTreeParameter("nero.quadrantB.15.timecal",12))
  },
  /*Quadrant C*/
  {
    *(new CTreeParameter("nero.quadrantC.0.energy", 12)),
    *(new CTreeParameter("nero.quadrantC.0.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantC.0.time",20)),
    *(new CTreeParameter("nero.quadrantC.0.timecal",12)),
    *(new CTreeParameter("nero.quadrantC.1.energy", 12)),
    *(new CTreeParameter("nero.quadrantC.1.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantC.1.time",20)),
    *(new CTreeParameter("nero.quadrantC.1.timecal",12)),
    *(new CTreeParameter("nero.quadrantC.2.energy", 12)),
    *(new CTreeParameter("nero.quadrantC.2.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantC.2.time",20)),
    *(new CTreeParameter("nero.quadrantC.2.timecal",12)),
    *(new CTreeParameter("nero.quadrantC.3.energy", 12)),
    *(new CTreeParameter("nero.quadrantC.3.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantC.3.time",20)),
    *(new CTreeParameter("nero.quadrantC.3.timecal",12)),
    *(new CTreeParameter("nero.quadrantC.4.energy", 12)),
    *(new CTreeParameter("nero.quadrantC.4.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantC.4.time",20)),
    *(new CTreeParameter("nero.quadrantC.4.timecal",12)),
    *(new CTreeParameter("nero.quadrantC.5.energy", 12)),
    *(new CTreeParameter("nero.quadrantC.5.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantC.5.time",20)),
    *(new CTreeParameter("nero.quadrantC.5.timecal",12)),
    *(new CTreeParameter("nero.quadrantC.6.energy", 12)),
    *(new CTreeParameter("nero.quadrantC.6.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantC.6.time",20)),
    *(new CTreeParameter("nero.quadrantC.6.timecal",12)),
    *(new CTreeParameter("nero.quadrantC.7.energy", 12)),
    *(new CTreeParameter("nero.quadrantC.7.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantC.7.time",20)),
    *(new CTreeParameter("nero.quadrantC.7.timecal",12)),
    *(new CTreeParameter("nero.quadrantC.8.energy", 12)),
    *(new CTreeParameter("nero.quadrantC.8.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantC.8.time",20)),
    *(new CTreeParameter("nero.quadrantC.8.timecal",12)),
    *(new CTreeParameter("nero.quadrantC.9.energy", 12)),
    *(new CTreeParameter("nero.quadrantC.9.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantC.9.time",20)),
    *(new CTreeParameter("nero.quadrantC.9.timecal",12)),
    *(new CTreeParameter("nero.quadrantC.10.energy", 12)),
    *(new CTreeParameter("nero.quadrantC.10.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantC.10.time",20)),
    *(new CTreeParameter("nero.quadrantC.10.timecal",12)),
    *(new CTreeParameter("nero.quadrantC.11.energy", 12)),
    *(new CTreeParameter("nero.quadrantC.11.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantC.11.time",20)),
    *(new CTreeParameter("nero.quadrantC.11.timecal",12)),
    *(new CTreeParameter("nero.quadrantC.12.energy", 12)),
    *(new CTreeParameter("nero.quadrantC.12.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantC.12.time",20)),
    *(new CTreeParameter("nero.quadrantC.12.timecal",12)),
    *(new CTreeParameter("nero.quadrantC.13.energy", 12)),
    *(new CTreeParameter("nero.quadrantC.13.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantC.13.time",20)),
    *(new CTreeParameter("nero.quadrantC.13.timecal",12)),
    *(new CTreeParameter("nero.quadrantC.14.energy", 12)),
    *(new CTreeParameter("nero.quadrantC.14.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantC.14.time",20)),
    *(new CTreeParameter("nero.quadrantC.14.timecal",12)),
    *(new CTreeParameter("nero.quadrantC.15.energy", 12)),
    *(new CTreeParameter("nero.quadrantC.15.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantC.15.time",20)),
    *(new CTreeParameter("nero.quadrantC.15.timecal",12))
  },
  /*Quadrant D*/
  {                                            
    *(new CTreeParameter("nero.quadrantD.0.energy", 12)),
    *(new CTreeParameter("nero.quadrantD.0.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantD.0.time",20)),
    *(new CTreeParameter("nero.quadrantD.0.timecal",12)),
    *(new CTreeParameter("nero.quadrantD.1.energy", 12)),
    *(new CTreeParameter("nero.quadrantD.1.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantD.1.time",20)),
    *(new CTreeParameter("nero.quadrantD.1.timecal",12)),
    *(new CTreeParameter("nero.quadrantD.2.energy", 12)),
    *(new CTreeParameter("nero.quadrantD.2.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantD.2.time",20)),
    *(new CTreeParameter("nero.quadrantD.2.timecal",12)),
    *(new CTreeParameter("nero.quadrantD.3.energy", 12)),
    *(new CTreeParameter("nero.quadrantD.3.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantD.3.time",20)),
    *(new CTreeParameter("nero.quadrantD.3.timecal",12)),
    *(new CTreeParameter("nero.quadrantD.4.energy", 12)),
    *(new CTreeParameter("nero.quadrantD.4.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantD.4.time",20)),
    *(new CTreeParameter("nero.quadrantD.4.timecal",12)),
    *(new CTreeParameter("nero.quadrantD.5.energy", 12)),
    *(new CTreeParameter("nero.quadrantD.5.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantD.5.time",20)),
    *(new CTreeParameter("nero.quadrantD.5.timecal",12)),
    *(new CTreeParameter("nero.quadrantD.6.energy", 12)),
    *(new CTreeParameter("nero.quadrantD.6.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantD.6.time",20)),
    *(new CTreeParameter("nero.quadrantD.6.timecal",12)),
    *(new CTreeParameter("nero.quadrantD.7.energy", 12)),
    *(new CTreeParameter("nero.quadrantD.7.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantD.7.time",20)),
    *(new CTreeParameter("nero.quadrantD.7.timecal",12)),
    *(new CTreeParameter("nero.quadrantD.8.energy", 12)),
    *(new CTreeParameter("nero.quadrantD.8.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantD.8.time",20)),
    *(new CTreeParameter("nero.quadrantD.8.timecal",12)),
    *(new CTreeParameter("nero.quadrantD.9.energy", 12)),
    *(new CTreeParameter("nero.quadrantD.9.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantD.9.time",20)),
    *(new CTreeParameter("nero.quadrantD.9.timecal",12)),
    *(new CTreeParameter("nero.quadrantD.10.energy", 12)),
    *(new CTreeParameter("nero.quadrantD.10.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantD.10.time",20)),
    *(new CTreeParameter("nero.quadrantD.10.timecal",12)),
    *(new CTreeParameter("nero.quadrantD.11.energy", 12)),
    *(new CTreeParameter("nero.quadrantD.11.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantD.11.time",20)),
    *(new CTreeParameter("nero.quadrantD.11.timecal",12)),
    *(new CTreeParameter("nero.quadrantD.12.energy", 12)),
    *(new CTreeParameter("nero.quadrantD.12.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantD.12.time",20)),
    *(new CTreeParameter("nero.quadrantD.12.timecal",12)),
    *(new CTreeParameter("nero.quadrantD.13.energy", 12)),
    *(new CTreeParameter("nero.quadrantD.13.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantD.13.time",20)),
    *(new CTreeParameter("nero.quadrantD.13.timecal",12)),
    *(new CTreeParameter("nero.quadrantD.14.energy", 12)),
    *(new CTreeParameter("nero.quadrantD.14.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantD.14.time",20)),
    *(new CTreeParameter("nero.quadrantD.14.timecal",12)),
    *(new CTreeParameter("nero.quadrantD.15.energy", 12)),
    *(new CTreeParameter("nero.quadrantD.15.energymatch", 12)),
    *(new CTreeParameter("nero.quadrantD.15.time",20)),
    *(new CTreeParameter("nero.quadrantD.15.timecal",12))
  }
};

