#include <tcl.h>


proc save {runname} {

  exec mkdir -p ../ClemensData/$runname
  exec mkdir ../ClemensData/$runname/ADC
  exec mkdir ../ClemensData/$runname/TDC
  exec mkdir ../ClemensData/$runname/ADC!TDC
  exec mkdir ../ClemensData/$runname/ADC!TDC_ch2
  exec mkdir ../ClemensData/$runname/ADC!TDC_0-50
  exec mkdir ../ClemensData/$runname/ADC!TDC_50-400000
  exec cp ../scalers/$runname.scalers ../ClemensData/$runname/
  exec cp ../readout/cfd_init_nero.dat ../ClemensData/$runname/
  exec cp ../readout/shaper_init_nero.dat ../ClemensData/$runname/


    for { set i 1 } { $i<17 } {incr i } {

      swrite -format ascii ../ClemensData/$runname/ADC!TDC_ch2/quadA_$i!TDC_ch2.dat quadA_$i!TDC_ch2
      swrite -format ascii ../ClemensData/$runname/ADC!TDC_ch2/quadB_$i!TDC_ch2.dat quadB_$i!TDC_ch2
      swrite -format ascii ../ClemensData/$runname/ADC!TDC_ch2/quadC_$i!TDC_ch2.dat quadC_$i!TDC_ch2
      swrite -format ascii ../ClemensData/$runname/ADC!TDC_ch2/quadD_$i!TDC_ch2.dat quadD_$i!TDC_ch2

      swrite -format ascii ../ClemensData/$runname/ADC!TDC/quadA_$i!TDC.dat quadA_$i!TDC
      swrite -format ascii ../ClemensData/$runname/ADC!TDC/quadB_$i!TDC.dat quadB_$i!TDC
      swrite -format ascii ../ClemensData/$runname/ADC!TDC/quadC_$i!TDC.dat quadC_$i!TDC
      swrite -format ascii ../ClemensData/$runname/ADC!TDC/quadD_$i!TDC.dat quadD_$i!TDC

      swrite -format ascii ../ClemensData/$runname/ADC/quadA_$i.dat quadA_$i
      swrite -format ascii ../ClemensData/$runname/ADC/quadB_$i.dat quadB_$i
      swrite -format ascii ../ClemensData/$runname/ADC/quadC_$i.dat quadC_$i
      swrite -format ascii ../ClemensData/$runname/ADC/quadD_$i.dat quadD_$i

      swrite -format ascii ../ClemensData/$runname/TDC/quadA_$i.dat quadAtime$i
      swrite -format ascii ../ClemensData/$runname/TDC/quadB_$i.dat quadBtime$i
      swrite -format ascii ../ClemensData/$runname/TDC/quadC_$i.dat quadCtime$i
      swrite -format ascii ../ClemensData/$runname/TDC/quadD_$i.dat quadDtime$i

      swrite -format ascii ../ClemensData/$runname/ADC!TDC_0-50/quadA_$i!TDC_0-50.dat quadA_$i!TDC_0-50
      swrite -format ascii ../ClemensData/$runname/ADC!TDC_0-50/quadB_$i!TDC_0-50.dat quadB_$i!TDC_0-50
      swrite -format ascii ../ClemensData/$runname/ADC!TDC_0-50/quadC_$i!TDC_0-50.dat quadC_$i!TDC_0-50
      swrite -format ascii ../ClemensData/$runname/ADC!TDC_0-50/quadD_$i!TDC_0-50.dat quadD_$i!TDC_0-50

      swrite -format ascii ../ClemensData/$runname/ADC!TDC_50-400000/quadA_$i!TDC_50-400000.dat quadA_$i!TDC_50-400000
      swrite -format ascii ../ClemensData/$runname/ADC!TDC_50-400000/quadB_$i!TDC_50-400000.dat quadB_$i!TDC_50-400000
      swrite -format ascii ../ClemensData/$runname/ADC!TDC_50-400000/quadC_$i!TDC_50-400000.dat quadC_$i!TDC_50-400000
      swrite -format ascii ../ClemensData/$runname/ADC!TDC_50-400000/quadD_$i!TDC_50-400000.dat quadD_$i!TDC_50-400000

    }

    swrite -format ascii ../ClemensData/$runname/multiplicity.dat multiplicity 

}

proc saveCRS {runname} {

  exec mkdir -p ../ClemensData/$runname/CRS

      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_00.dat crs_qdc_00_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_01.dat crs_qdc_01_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_02.dat crs_qdc_02_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_03.dat crs_qdc_03_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_04.dat crs_qdc_04_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_05.dat crs_qdc_05_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_06.dat crs_qdc_06_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_07.dat crs_qdc_07_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_08.dat crs_qdc_08_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_09.dat crs_qdc_09_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_10.dat crs_qdc_10_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_11.dat crs_qdc_11_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_12.dat crs_qdc_12_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_13.dat crs_qdc_13_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_14.dat crs_qdc_14_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_15.dat crs_qdc_15_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_16.dat crs_qdc_16_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_17.dat crs_qdc_17_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_18.dat crs_qdc_18_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_19.dat crs_qdc_19_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_20.dat crs_qdc_20_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_21.dat crs_qdc_21_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_22.dat crs_qdc_22_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_23.dat crs_qdc_23_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_24.dat crs_qdc_24_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_25.dat crs_qdc_25_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_26.dat crs_qdc_26_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_27.dat crs_qdc_27_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_28.dat crs_qdc_28_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_29.dat crs_qdc_29_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_30.dat crs_qdc_30_energy
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_31.dat crs_qdc_31_energy

#-----coincidence spectra of QDC channels 0 and 1#

#-----QDC channels 0 and 1 cut off low energy noise. Threshold - gated to itself#

      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_00!qdc00.dat crs_qdc_00_energy!qdc00
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_01!qdc01.dat crs_qdc_01_energy!qdc01

#-----QDC channels:  ch0 coinc. with ch1   and   coinc ch1 with ch0#

      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_00!qdc01.dat crs_qdc_00_energy!qdc01
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_01!qdc00.dat crs_qdc_01_energy!qdc00

#-----QDC gated by TDC_all#

      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_00!tdc_all.dat crs_qdc_00_energy!TDC_all
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_01!tdc_all.dat crs_qdc_01_energy!TDC_all


#-----QDC gated by TDC_0-50 and TDC_50-400000#

      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_01!tdc_0-50.dat crs_qdc_01_energy!TDC_0-50
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_01!tdc_50-400000.dat crs_qdc_01_energy!TDC_50-400000
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_00!tdc_0-50.dat crs_qdc_00_energy!TDC_0-50
      swrite -format ascii ../ClemensData/$runname/CRS/CRS_QDC_00!tdc_50-400000.dat crs_qdc_00_energy!TDC_50-400000
}



proc saveModTime {runname} {

  exec mkdir -p ../ClemensData/$runname/ModTime


      swrite -format ascii ../ClemensData/$runname/ModTime/quadAtime2.dat quadAtime2
      swrite -format ascii ../ClemensData/$runname/ModTime/quadAtime2!quadA_threshold.dat quadAtime2!quadA_threshold
      swrite -format ascii ../ClemensData/$runname/ModTime/quadAtime2!quadB_threshold.dat quadAtime2!quadB_threshold
      swrite -format ascii ../ClemensData/$runname/ModTime/quadAtime2!quadC_threshold.dat quadAtime2!quadC_threshold
      swrite -format ascii ../ClemensData/$runname/ModTime/quadAtime2!quadD_threshold.dat quadAtime2!quadD_threshold
      swrite -format ascii ../ClemensData/$runname/ModTime/quadAtime2!quadALL_threshold.dat quadAtime2!quadALL_threshold
      swrite -format ascii ../ClemensData/$runname/ModTime/quadAtime2!quadRing1_threshold.dat quadAtime2!quadRing1_threshold
      swrite -format ascii ../ClemensData/$runname/ModTime/quadAtime2!quadRing2_threshold.dat quadAtime2!quadRing2_threshold
      swrite -format ascii ../ClemensData/$runname/ModTime/quadAtime2!quadRing3_threshold.dat quadAtime2!quadRing3_threshold

      swrite -format ascii ../ClemensData/$runname/ModTime/quadAtime2!CRS_QDC_00_01-coinc.dat quadAtime2!CRS_QDC_00_01-coinc

}



proc saveall {fname runtime} {
  
  set spectra "!TDC_ch2"

  set string_ "_"
#-----Configuration of quads and channels-----#

    set quadA_1 quadA_1
    set quadA_2 quadA_2
    set quadA_3 quadA_3
    set quadA_4 quadA_4
    set quadA_5 quadA_5
    set quadA_6 quadA_6
    set quadA_7 quadA_7
    set quadA_8 quadA_8
    set quadA_9 quadA_16
    set quadA_10 quadA_10
    set quadA_11 quadA_11
    set quadA_12 quadA_12
    set quadA_13 quadA_13
    set quadA_14 quadA_14
    set quadA_15 quadA_15

    set quadB_1 quadB_1
    set quadB_2 quadB_2
    set quadB_3 quadB_3
    set quadB_4 quadB_4
    set quadB_5 quadB_5
    set quadB_6 quadB_6
    set quadB_7 quadB_7
    set quadB_8 quadB_8
    set quadB_9 quadB_9
    set quadB_10 quadB_10
    set quadB_11 quadB_11
    set quadB_12 quadB_12
    set quadB_13 quadB_13
    set quadB_14 quadB_14
    set quadB_15 quadB_15

    set quadC_1 quadC_1
    set quadC_2 quadC_2
    set quadC_3 quadC_3
    set quadC_4 quadC_4
    set quadC_5 quadC_5
    set quadC_6 quadC_6
    set quadC_7 quadC_7
    set quadC_8 quadC_8
    set quadC_9 quadC_9
    set quadC_10 quadC_10
    set quadC_11 quadC_11
    set quadC_12 quadC_12
    set quadC_13 quadC_13
    set quadC_14 quadC_14
    set quadC_15 quadC_15

    set quadD_1 quadD_1
    set quadD_2 quadD_2
    set quadD_3 quadD_3
    set quadD_4 quadD_4
    set quadD_5 quadD_5
    set quadD_6 quadD_6
    set quadD_7 quadD_7
    set quadD_8 quadD_8
    set quadD_9 quadD_9
    set quadD_10 quadD_10
    set quadD_11 quadD_11
    set quadD_12 quadD_12
    set quadD_13 quadD_13
    set quadD_14 quadD_14
    set quadD_15 quadD_15

#-----end of Configuration of quads and channels-----#


#-----Configuration of ring1 and channels-----#

    set ring1_1 quadA_1
    set ring1_2 quadA_2
    set ring1_3 quadA_3
    set ring1_4 quadA_4

    set ring1_5 quadB_1
    set ring1_6 quadB_2
    set ring1_7 quadB_3
    set ring1_8 quadB_4

    set ring1_9 quadC_1
    set ring1_10 quadC_2
    set ring1_11 quadC_3
    set ring1_12 quadC_4

    set ring1_13 quadD_1
    set ring1_14 quadD_2
    set ring1_15 quadD_3
    set ring1_16 quadD_4

#-----end of Configuration of rings and channels-----#


#-----Configuration of ring2 and channels-----#

    set ring2_1 quadA_6
    set ring2_2 quadA_5
    set ring2_3 quadA_7
    set ring2_4 quadA_8
    set ring2_5 quadA_16

    set ring2_6 quadB_5
    set ring2_7 quadB_6
    set ring2_8 quadB_7
    set ring2_9 quadB_8
    set ring2_10 quadB_9

    set ring2_11 quadC_5
    set ring2_12 quadC_6
    set ring2_13 quadC_7
    set ring2_14 quadC_8
    set ring2_15 quadC_9

    set ring2_16 quadD_5
    set ring2_17 quadD_6
    set ring2_18 quadD_7
    set ring2_19 quadD_8
    set ring2_20 quadD_9

#-----end of Configuration of rings and channels-----#


#-----Configuration of ring3 and channels-----#

    set ring3_1 quadA_10
    set ring3_2 quadA_11
    set ring3_3 quadA_12
    set ring3_4 quadA_13
    set ring3_5 quadA_14
    set ring3_6 quadA_15

    set ring3_7 quadB_10
    set ring3_8 quadB_11
    set ring3_9 quadB_12
    set ring3_10 quadB_13
    set ring3_11 quadB_14
    set ring3_12 quadB_15

    set ring3_13 quadC_10
    set ring3_14 quadC_11
    set ring3_15 quadC_12
    set ring3_16 quadC_13
    set ring3_17 quadC_14
    set ring3_18 quadC_15

    set ring3_19 quadD_10
    set ring3_20 quadD_11
    set ring3_21 quadD_12
    set ring3_22 quadD_13
    set ring3_23 quadD_14
    set ring3_24 quadD_15

#-----end of Configuration of rings and channels-----#

  set fd [open $fname w]
  puts $fd "group tube\# spectrumname sumADC sumTDC sumADC!TDC sumADC!TDC_ch2  runtime= $runtime"

  foreach spectratemp {ADC TDC ADCgTDC ADCgTDC_ch2} { 

  set event_quadA_$spectratemp 0
  set event_quadB_$spectratemp 0
  set event_quadC_$spectratemp 0
  set event_quadD_$spectratemp 0

  set event_ring1_$spectratemp 0
  set event_ring2_$spectratemp 0
  set event_ring3_$spectratemp 0

  set event_all_$spectratemp 0

  }


#------quadA quadB quadC quadD------#
  
  foreach grouptemp {quadA quadB quadC quadD} { 

    set event_quad_ADC 0
    set event_quad_TDC 0
    set event_quad_ADCgTDC 0
    set event_quad_ADCgTDC_ch2 0

    puts $fd ""
    foreach num {1 2 3 4 5 6 7 8 9 10 11 12 13 14 15} {

      set event_tubeADC 0
      set event_tubeTDC 0
      set event_tubeADCgTDC 0
      set event_tubeADCgTDC_ch2 0


#-----TDC---------------------

      set spectra "time"

      set spectrum1 "[set $grouptemp$string_$num]"
      
      set spectrum "[string replace $spectrum1 5 5 $spectra]"
      set event_ch 0

      for { set i 0 } { $i<4095+1 } {incr i } {
        set event_ch [channel -get "$spectrum" "$i"]
        set event_tubeTDC [expr $event_tubeTDC+$event_ch]
      }

#      puts "$spectrum has detected $event_tubeTDC events"
      set event_quad_TDC [expr $event_quad_TDC+$event_tubeTDC]



#-----ADC!TDC_ch2-------------

      set spectra "!TDC_ch2"

      set spectrum1 "[set $grouptemp$string_$num]"
      set spectrum "$spectrum1$spectra"
      set event_ch 0

      for { set i 0 } { $i<4095+1 } {incr i } {
        set event_ch [channel -get "$spectrum" "$i"]
        set event_tubeADCgTDC_ch2 [expr $event_tubeADCgTDC_ch2+$event_ch]
      }

#      puts "$spectrum has detected $event_tubeADCgTDC_ch2 events"
      set event_quad_ADCgTDC_ch2 [expr $event_quad_ADCgTDC_ch2+$event_tubeADCgTDC_ch2] 



#-----ADC-------------

set spectra ""

      set spectrum1 "[set $grouptemp$string_$num]"
      set spectrum "$spectrum1$spectra"
      set event_ch 0

      for { set i 0 } { $i<4095+1 } {incr i } {
        set event_ch [channel -get "$spectrum" "$i"]
        set event_tubeADC [expr $event_tubeADC+$event_ch]
      }

#      puts "$spectrum has detected $event_tubeADC events"
      set event_quad_ADC [expr $event_quad_ADC+$event_tubeADC]

#-----ADC!TDC-------------

set spectra "!TDC"

      set spectrum1 "[set $grouptemp$string_$num]"
      set spectrum "$spectrum1$spectra"
      set event_ch 0

      for { set i 0 } { $i<4095+1 } {incr i } {
        set event_ch [channel -get "$spectrum" "$i"]
        set event_tubeADCgTDC [expr $event_tubeADCgTDC+$event_ch]
      }

#      puts "$spectrum has detected $event_tubeADCgTDC events"
      set event_quad_ADCgTDC [expr $event_quad_ADCgTDC+$event_tubeADCgTDC]



#-------------------------


      puts $fd "$grouptemp $num $spectrum1 $event_tubeADC $event_tubeTDC $event_tubeADCgTDC $event_tubeADCgTDC_ch2"
    }
    set event_$grouptemp $event_quad_ADCgTDC_ch2
    set event_all_ADCgTDC_ch2 [expr $event_all_ADCgTDC_ch2+$event_quad_ADCgTDC_ch2]  




#    puts ""
    puts "$grouptemp : ADC $event_quad_ADC - TDC $event_quad_TDC - ADC!TDC $event_quad_ADCgTDC - ADC!TDC_ch2 $event_quad_ADCgTDC_ch2"
    set var_temp "ADCgTDC_ch2"
    set var_name1 "event_$grouptemp$string_$var_temp"
    set "[set var_name1]" $event_quad_ADCgTDC_ch2

#    puts ""
    set var_temp "TDC"
    set var_name1 "event_$grouptemp$string_$var_temp"
    set "[set var_name1]" $event_quad_TDC

#    puts ""
    set var_temp "ADCgTDC"
    set var_name1 "event_$grouptemp$string_$var_temp"
    set "[set var_name1]" $event_quad_ADCgTDC    

#    puts ""
    set var_temp "ADC"
    set var_name1 "event_$grouptemp$string_$var_temp"
    set "[set var_name1]" $event_quad_ADC 

  }




#-------ring1---------#

  set event_ring_ADC 0
  set event_ring_TDC 0
  set event_ring_ADCgTDC 0
  set event_ring_ADCgTDC_ch2 0

  puts $fd ""
    foreach num {1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16} {

      set event_tubeADC 0
      set event_tubeTDC 0
      set event_tubeADCgTDC 0
      set event_tubeADCgTDC_ch2 0



#-----ADC----------------------------

      set spectra ""

      set name1 "[set ring1_$num]"
      set spectrum "$name1$spectra"
      set event_ch 0

      for { set i 0 } { $i<4095+1 } {incr i } {
        set event_ch [channel -get "$spectrum" "$i"]
        set event_tubeADC [expr $event_tubeADC+$event_ch]
      }
#      puts "ring1_$num has detected $event_tube events"

      set event_ring_ADC [expr $event_ring_ADC+$event_tubeADC]  


#-----TDC----------------------------
      set spectra "time"

      set spectrum1 "[set ring1$string_$num]"
      
      set spectrum "[string replace $spectrum1 5 5 $spectra]"
      set event_ch 0

      for { set i 0 } { $i<4095+1 } {incr i } {
        set event_ch [channel -get "$spectrum" "$i"]
        set event_tubeTDC [expr $event_tubeTDC+$event_ch]
      }
#      puts "ring1_$num has detected $event_tube events"

      set event_ring_TDC [expr $event_ring_TDC+$event_tubeTDC]  

#-----ADC!TDC------------------------

      set spectra "!TDC"

      set name1 "[set ring1_$num]"
      set spectrum "$name1$spectra"
      set event_ch 0

      for { set i 0 } { $i<4095+1 } {incr i } {
        set event_ch [channel -get "$spectrum" "$i"]
        set event_tubeADCgTDC [expr $event_tubeADCgTDC+$event_ch]
      }
#      puts "ring1_$num has detected $event_tube events"

      set event_ring_ADCgTDC [expr $event_ring_ADCgTDC+$event_tubeADCgTDC]  


#-----ADC!TDC_ch2--------------------

      set spectra "!TDC_ch2"

      set name1 "[set ring1_$num]"
      set spectrum "$name1$spectra"
      set event_ch 0

      for { set i 0 } { $i<4095+1 } {incr i } {
        set event_ch [channel -get "$spectrum" "$i"]
        set event_tubeADCgTDC_ch2 [expr $event_tubeADCgTDC_ch2+$event_ch]
      }
#      puts "ring1_$num has detected $event_tube events"

      set event_ring_ADCgTDC_ch2 [expr $event_ring_ADCgTDC_ch2+$event_tubeADCgTDC_ch2]  

#----------------------------



      puts $fd "ring1 $num $name1 $event_tubeADC $event_tubeTDC $event_tubeADCgTDC $event_tubeADCgTDC_ch2"

    }

#  puts ""
  puts "ring1: ADC $event_ring_ADC - TDC $event_ring_TDC - ADC!TDC $event_ring_ADCgTDC - ADC!TDC_ch2 $event_ring_ADCgTDC_ch2"
  set event_ring1_ADCgTDC_ch2 $event_ring_ADCgTDC_ch2
  set event_ring1_ADCgTDC $event_ring_ADCgTDC
  set event_ring1_ADC $event_ring_ADC
  set event_ring1_TDC $event_ring_TDC



#-------ring2---------#


  set event_ring_ADC 0
  set event_ring_TDC 0
  set event_ring_ADCgTDC 0
  set event_ring_ADCgTDC_ch2 0

  puts $fd ""
    foreach num {1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20} {

      set event_tubeADC 0
      set event_tubeTDC 0
      set event_tubeADCgTDC 0
      set event_tubeADCgTDC_ch2 0



#-----ADC----------------------------

      set spectra ""

      set name1 "[set ring2_$num]"
      set spectrum "$name1$spectra"
      set event_ch 0

      for { set i 0 } { $i<4095+1 } {incr i } {
        set event_ch [channel -get "$spectrum" "$i"]
        set event_tubeADC [expr $event_tubeADC+$event_ch]
      }
#      puts "ring2_$num has detected $event_tube events"

      set event_ring_ADC [expr $event_ring_ADC+$event_tubeADC]  


#-----TDC----------------------------

      set spectra "time"

      set spectrum1 "[set ring2$string_$num]"
      
      set spectrum "[string replace $spectrum1 5 5 $spectra]"
      set event_ch 0

      for { set i 0 } { $i<4095+1 } {incr i } {
        set event_ch [channel -get "$spectrum" "$i"]
        set event_tubeTDC [expr $event_tubeTDC+$event_ch]
      }
#      puts "ring2_$num has detected $event_tube events"

      set event_ring_TDC [expr $event_ring_TDC+$event_tubeTDC]  


#-----ADC!TDC------------------------

      set spectra "!TDC"

      set name1 "[set ring2_$num]"
      set spectrum "$name1$spectra"
      set event_ch 0

      for { set i 0 } { $i<4095+1 } {incr i } {
        set event_ch [channel -get "$spectrum" "$i"]
        set event_tubeADCgTDC [expr $event_tubeADCgTDC+$event_ch]
      }
#      puts "ring2_$num has detected $event_tube events"

      set event_ring_ADCgTDC [expr $event_ring_ADCgTDC+$event_tubeADCgTDC]  


#-----ADC!TDC_ch2--------------------

      set spectra "!TDC_ch2"

      set name1 "[set ring2_$num]"
      set spectrum "$name1$spectra"
      set event_ch 0

      for { set i 0 } { $i<4095+1 } {incr i } {
        set event_ch [channel -get "$spectrum" "$i"]
        set event_tubeADCgTDC_ch2 [expr $event_tubeADCgTDC_ch2+$event_ch]
      }
#      puts "ring2_$num has detected $event_tube events"

      set event_ring_ADCgTDC_ch2 [expr $event_ring_ADCgTDC_ch2+$event_tubeADCgTDC_ch2]  

#----------------------------



      puts $fd "ring2 $num $name1 $event_tubeADC $event_tubeTDC $event_tubeADCgTDC $event_tubeADCgTDC_ch2"

    }

#  puts ""
  puts "ring2: ADC $event_ring_ADC - TDC $event_ring_TDC - ADC!TDC $event_ring_ADCgTDC - ADC!TDC_ch2 $event_ring_ADCgTDC_ch2"
  set event_ring2_ADCgTDC_ch2 $event_ring_ADCgTDC_ch2
  set event_ring2_ADCgTDC $event_ring_ADCgTDC
  set event_ring2_ADC $event_ring_ADC
  set event_ring2_TDC $event_ring_TDC






#-------ring3---------#

  set event_ring_ADC 0
  set event_ring_TDC 0
  set event_ring_ADCgTDC 0
  set event_ring_ADCgTDC_ch2 0

  puts $fd ""
    foreach num {1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24} {

      set event_tubeADC 0
      set event_tubeTDC 0
      set event_tubeADCgTDC 0
      set event_tubeADCgTDC_ch2 0



#-----ADC----------------------------

      set spectra ""

      set name1 "[set ring3_$num]"
      set spectrum "$name1$spectra"
      set event_ch 0

      for { set i 0 } { $i<4095+1 } {incr i } {
        set event_ch [channel -get "$spectrum" "$i"]
        set event_tubeADC [expr $event_tubeADC+$event_ch]
      }
#      puts "ring3_$num has detected $event_tube events"

      set event_ring_ADC [expr $event_ring_ADC+$event_tubeADC]  


#-----TDC----------------------------

      set spectra "time"

      set spectrum1 "[set ring3$string_$num]"
      
      set spectrum "[string replace $spectrum1 5 5 $spectra]"
      set event_ch 0

      for { set i 0 } { $i<4095+1 } {incr i } {
        set event_ch [channel -get "$spectrum" "$i"]
        set event_tubeTDC [expr $event_tubeTDC+$event_ch]
      }
#      puts "ring3_$num has detected $event_tube events"

      set event_ring_TDC [expr $event_ring_TDC+$event_tubeTDC]  

#-----ADC!TDC------------------------

      set spectra "!TDC"

      set name1 "[set ring3_$num]"
      set spectrum "$name1$spectra"
      set event_ch 0

      for { set i 0 } { $i<4095+1 } {incr i } {
        set event_ch [channel -get "$spectrum" "$i"]
        set event_tubeADCgTDC [expr $event_tubeADCgTDC+$event_ch]
      }
#      puts "ring3_$num has detected $event_tube events"

      set event_ring_ADCgTDC [expr $event_ring_ADCgTDC+$event_tubeADCgTDC]  


#-----ADC!TDC_ch2--------------------

      set spectra "!TDC_ch2"

      set name1 "[set ring3_$num]"
      set spectrum "$name1$spectra"
      set event_ch 0

      for { set i 0 } { $i<4095+1 } {incr i } {
        set event_ch [channel -get "$spectrum" "$i"]
        set event_tubeADCgTDC_ch2 [expr $event_tubeADCgTDC_ch2+$event_ch]
      }
#      puts "ring3_$num has detected $event_tube events"

      set event_ring_ADCgTDC_ch2 [expr $event_ring_ADCgTDC_ch2+$event_tubeADCgTDC_ch2]  

#----------------------------



      puts $fd "ring3 $num $name1 $event_tubeADC $event_tubeTDC $event_tubeADCgTDC $event_tubeADCgTDC_ch2"

    }

#  puts ""
  puts "ring3: ADC $event_ring_ADC - TDC $event_ring_TDC - ADC!TDC $event_ring_ADCgTDC - ADC!TDC_ch2 $event_ring_ADCgTDC_ch2"
  set event_ring3_ADCgTDC_ch2 $event_ring_ADCgTDC_ch2
  set event_ring3_ADCgTDC $event_ring_ADCgTDC
  set event_ring3_ADC $event_ring_ADC
  set event_ring3_TDC $event_ring_TDC

  set event_all_ADC [expr $event_quadA_ADC+$event_quadB_ADC+$event_quadC_ADC+$event_quadD_ADC]
  set event_all_TDC [expr $event_quadA_TDC+$event_quadB_TDC+$event_quadC_TDC+$event_quadD_TDC]
  set event_all_ADCgTDC [expr $event_quadA_ADCgTDC+$event_quadB_ADCgTDC+$event_quadC_ADCgTDC+$event_quadD_ADCgTDC]
  set event_all_ADCgTDC_ch2 [expr $event_quadA_ADCgTDC_ch2+$event_quadB_ADCgTDC_ch2+$event_quadC_ADCgTDC_ch2+$event_quadD_ADCgTDC_ch2]


#  set event_all_ADC [expr $event_ring1_ADC+$event_ring2_ADC+$event_ring3_ADC]
#  set event_all_TDC [expr $event_ring1_TDC+$event_ring2_TDC+$event_ring3_TDC]
#  set event_all_ADCgTDC [expr $event_ring1_ADCgTDC+$event_ring2_ADCgTDC+$event_ring3_ADCgTDC]
#  set event_all_ADCgTDC_ch2 [expr $event_ring1_ADCgTDC_ch2+$event_ring2_ADCgTDC_ch2+$event_ring3_ADCgTDC_ch2]


#-------output-------#


  puts ""
  puts "group - ADC - TDC - ADC!TDC - ADC!TDC_ch2"
  puts "quadA - $event_quadA_ADC - $event_quadA_TDC - $event_quadA_ADCgTDC - $event_quadA_ADCgTDC_ch2"
  puts "quadB - $event_quadB_ADC - $event_quadB_TDC - $event_quadB_ADCgTDC - $event_quadB_ADCgTDC_ch2"
  puts "quadC - $event_quadC_ADC - $event_quadC_TDC - $event_quadC_ADCgTDC - $event_quadC_ADCgTDC_ch2"
  puts "quadD - $event_quadD_ADC - $event_quadD_TDC - $event_quadD_ADCgTDC - $event_quadD_ADCgTDC_ch2"
  puts "ring1 - $event_ring1_ADC - $event_ring1_TDC - $event_ring1_ADCgTDC - $event_ring1_ADCgTDC_ch2"
  puts "ring2 - $event_ring2_ADC - $event_ring2_TDC - $event_ring2_ADCgTDC - $event_ring2_ADCgTDC_ch2"
  puts "ring3 - $event_ring3_ADC - $event_ring3_TDC - $event_ring3_ADCgTDC - $event_ring3_ADCgTDC_ch2"
  puts "all   - $event_all_ADC - $event_all_TDC - $event_all_ADCgTDC - $event_all_ADCgTDC_ch2"
  puts ""


  puts $fd ""
  puts $fd ""
  puts $fd "Summary"
  puts $fd "quadA ALL - $event_quadA_ADC $event_quadA_TDC $event_quadA_ADCgTDC $event_quadA_ADCgTDC_ch2"
  puts $fd "quadB ALL - $event_quadB_ADC $event_quadB_TDC $event_quadB_ADCgTDC $event_quadB_ADCgTDC_ch2"
  puts $fd "quadC ALL - $event_quadC_ADC $event_quadC_TDC $event_quadC_ADCgTDC $event_quadC_ADCgTDC_ch2"
  puts $fd "quadD ALL - $event_quadD_ADC $event_quadD_TDC $event_quadD_ADCgTDC $event_quadD_ADCgTDC_ch2"
  puts $fd "ring1 ALL - $event_ring1_ADC $event_ring1_TDC $event_ring1_ADCgTDC $event_ring1_ADCgTDC_ch2"
  puts $fd "ring2 ALL - $event_ring2_ADC $event_ring2_TDC $event_ring2_ADCgTDC $event_ring2_ADCgTDC_ch2"
  puts $fd "ring3 ALL - $event_ring3_ADC $event_ring3_TDC $event_ring3_ADCgTDC $event_ring3_ADCgTDC_ch2"
  puts $fd "all ALL - $event_all_ADC $event_all_TDC $event_all_ADCgTDC $event_all_ADCgTDC_ch2"
   

 
  puts "----------------"
  puts "end of procedure"
  puts ""  


  flush $fd

}


proc test {} {

  set quadA_9 quadA_16
  
  puts "$quadA_9"

  set name1 "[string replace $quadA_9 5 5 time]"

  puts "$name1"

  set name2 [string trimright $name1 "time"]

  puts "$name2"


}   