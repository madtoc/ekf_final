  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (qbot2_P)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% qbot2_P.HILInitialize_OOStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% qbot2_P.HILInitialize_OOEnter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% qbot2_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% qbot2_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% qbot2_P.HILInitialize_POFrequency
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% qbot2_P.HILInitialize_POInitial
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% qbot2_P.HILInitialize_POFinal
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% qbot2_P.Gain1_Gain
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% qbot2_P.Memory1_X0
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% qbot2_P.Memory2_X0
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% qbot2_P.Memory_X0
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% qbot2_P.Memory3_X0
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% qbot2_P.HILInitialize_POModes
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% qbot2_P.RoombaInitialize1_SendBufferSiz
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% qbot2_P.RoombaInitialize1_ReceiveBuffer
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% qbot2_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% qbot2_P.HILInitialize_DOChannels
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 12;
	
	  ;% qbot2_P.HILInitialize_POChannels
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 13;
	
	  ;% qbot2_P.HILReadWrite_R_AnalogChannels
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 21;
	
	  ;% qbot2_P.HILReadWrite_R_OtherChannels
	  section.data(5).logicalSrcIdx = 19;
	  section.data(5).dtTransOffset = 26;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% qbot2_P.V_r_Value
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% qbot2_P.V_l_Value
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% qbot2_P.ids1_Value
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% qbot2_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% qbot2_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 1;
	
	  ;% qbot2_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 25;
	  section.data(3).dtTransOffset = 2;
	
	  ;% qbot2_P.HILInitialize_CKStart
	  section.data(4).logicalSrcIdx = 26;
	  section.data(4).dtTransOffset = 3;
	
	  ;% qbot2_P.HILInitialize_CKEnter
	  section.data(5).logicalSrcIdx = 27;
	  section.data(5).dtTransOffset = 4;
	
	  ;% qbot2_P.HILInitialize_AIPStart
	  section.data(6).logicalSrcIdx = 28;
	  section.data(6).dtTransOffset = 5;
	
	  ;% qbot2_P.HILInitialize_AIPEnter
	  section.data(7).logicalSrcIdx = 29;
	  section.data(7).dtTransOffset = 6;
	
	  ;% qbot2_P.HILInitialize_AOPStart
	  section.data(8).logicalSrcIdx = 30;
	  section.data(8).dtTransOffset = 7;
	
	  ;% qbot2_P.HILInitialize_AOPEnter
	  section.data(9).logicalSrcIdx = 31;
	  section.data(9).dtTransOffset = 8;
	
	  ;% qbot2_P.HILInitialize_AOStart
	  section.data(10).logicalSrcIdx = 32;
	  section.data(10).dtTransOffset = 9;
	
	  ;% qbot2_P.HILInitialize_AOEnter
	  section.data(11).logicalSrcIdx = 33;
	  section.data(11).dtTransOffset = 10;
	
	  ;% qbot2_P.HILInitialize_AOTerminate
	  section.data(12).logicalSrcIdx = 34;
	  section.data(12).dtTransOffset = 11;
	
	  ;% qbot2_P.HILInitialize_AOExit
	  section.data(13).logicalSrcIdx = 35;
	  section.data(13).dtTransOffset = 12;
	
	  ;% qbot2_P.HILInitialize_AOReset
	  section.data(14).logicalSrcIdx = 36;
	  section.data(14).dtTransOffset = 13;
	
	  ;% qbot2_P.HILInitialize_DOPStart
	  section.data(15).logicalSrcIdx = 37;
	  section.data(15).dtTransOffset = 14;
	
	  ;% qbot2_P.HILInitialize_DOPEnter
	  section.data(16).logicalSrcIdx = 38;
	  section.data(16).dtTransOffset = 15;
	
	  ;% qbot2_P.HILInitialize_DOStart
	  section.data(17).logicalSrcIdx = 39;
	  section.data(17).dtTransOffset = 16;
	
	  ;% qbot2_P.HILInitialize_DOEnter
	  section.data(18).logicalSrcIdx = 40;
	  section.data(18).dtTransOffset = 17;
	
	  ;% qbot2_P.HILInitialize_DOTerminate
	  section.data(19).logicalSrcIdx = 41;
	  section.data(19).dtTransOffset = 18;
	
	  ;% qbot2_P.HILInitialize_DOExit
	  section.data(20).logicalSrcIdx = 42;
	  section.data(20).dtTransOffset = 19;
	
	  ;% qbot2_P.HILInitialize_DOReset
	  section.data(21).logicalSrcIdx = 43;
	  section.data(21).dtTransOffset = 20;
	
	  ;% qbot2_P.HILInitialize_EIPStart
	  section.data(22).logicalSrcIdx = 44;
	  section.data(22).dtTransOffset = 21;
	
	  ;% qbot2_P.HILInitialize_EIPEnter
	  section.data(23).logicalSrcIdx = 45;
	  section.data(23).dtTransOffset = 22;
	
	  ;% qbot2_P.HILInitialize_EIStart
	  section.data(24).logicalSrcIdx = 46;
	  section.data(24).dtTransOffset = 23;
	
	  ;% qbot2_P.HILInitialize_EIEnter
	  section.data(25).logicalSrcIdx = 47;
	  section.data(25).dtTransOffset = 24;
	
	  ;% qbot2_P.HILInitialize_POPStart
	  section.data(26).logicalSrcIdx = 48;
	  section.data(26).dtTransOffset = 25;
	
	  ;% qbot2_P.HILInitialize_POPEnter
	  section.data(27).logicalSrcIdx = 49;
	  section.data(27).dtTransOffset = 26;
	
	  ;% qbot2_P.HILInitialize_POStart
	  section.data(28).logicalSrcIdx = 50;
	  section.data(28).dtTransOffset = 27;
	
	  ;% qbot2_P.HILInitialize_POEnter
	  section.data(29).logicalSrcIdx = 51;
	  section.data(29).dtTransOffset = 28;
	
	  ;% qbot2_P.HILInitialize_POTerminate
	  section.data(30).logicalSrcIdx = 52;
	  section.data(30).dtTransOffset = 29;
	
	  ;% qbot2_P.HILInitialize_POExit
	  section.data(31).logicalSrcIdx = 53;
	  section.data(31).dtTransOffset = 30;
	
	  ;% qbot2_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 54;
	  section.data(32).dtTransOffset = 31;
	
	  ;% qbot2_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 55;
	  section.data(33).dtTransOffset = 32;
	
	  ;% qbot2_P.HILInitialize_DOInitial
	  section.data(34).logicalSrcIdx = 56;
	  section.data(34).dtTransOffset = 33;
	
	  ;% qbot2_P.HILInitialize_DOFinal
	  section.data(35).logicalSrcIdx = 57;
	  section.data(35).dtTransOffset = 34;
	
	  ;% qbot2_P.HILReadWrite_Active
	  section.data(36).logicalSrcIdx = 58;
	  section.data(36).dtTransOffset = 35;
	
	  ;% qbot2_P.RoombaInitialize1_Active
	  section.data(37).logicalSrcIdx = 59;
	  section.data(37).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (qbot2_B)
    ;%
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% qbot2_B.HILReadWrite_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% qbot2_B.HILReadWrite_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 5;
	
	  ;% qbot2_B.DataTypeConversion
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 11;
	
	  ;% qbot2_B.Gain1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 14;
	
	  ;% qbot2_B.Memory1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 15;
	
	  ;% qbot2_B.Memory2
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 16;
	
	  ;% qbot2_B.Memory
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 17;
	
	  ;% qbot2_B.Memory3
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 21;
	
	  ;% qbot2_B.heading
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 22;
	
	  ;% qbot2_B.sonar
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 23;
	
	  ;% qbot2_B.angle
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 26;
	
	  ;% qbot2_B.dists_cm
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 29;
	
	  ;% qbot2_B.x
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 34;
	
	  ;% qbot2_B.theta
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 35;
	
	  ;% qbot2_B.states
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (qbot2_DWork)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% qbot2_DWork.HILInitialize_POSortedFreqs
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% qbot2_DWork.HILInitialize_POValues
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 8;
	
	  ;% qbot2_DWork.Memory1_PreviousInput
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 16;
	
	  ;% qbot2_DWork.Memory2_PreviousInput
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 17;
	
	  ;% qbot2_DWork.Memory_PreviousInput
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 18;
	
	  ;% qbot2_DWork.Memory3_PreviousInput
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% qbot2_DWork.RoombaInitialize1_Roomba
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% qbot2_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% qbot2_DWork.HILReadWrite_PWORK
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% qbot2_DWork.HILInitialize_DOStates
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% qbot2_DWork.HILInitialize_POModeValues
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% qbot2_DWork.HILInitialize_POAlignValues
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 9;
	
	  ;% qbot2_DWork.HILInitialize_POPolarityVals
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 17;
	
	  ;% qbot2_DWork.sfEvent
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 25;
	
	  ;% qbot2_DWork.sfEvent_e
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 26;
	
	  ;% qbot2_DWork.sfEvent_k
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 27;
	
	  ;% qbot2_DWork.sfEvent_g
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 28;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% qbot2_DWork.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% qbot2_DWork.is_active_c2_qbot2
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% qbot2_DWork.is_active_c1_qbot2
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
	  ;% qbot2_DWork.is_active_c5_qbot2
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 2;
	
	  ;% qbot2_DWork.is_active_c3_qbot2
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% qbot2_DWork.isStable
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% qbot2_DWork.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
	  ;% qbot2_DWork.isStable_l
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 2;
	
	  ;% qbot2_DWork.doneDoubleBufferReInit_d
	  section.data(4).logicalSrcIdx = 25;
	  section.data(4).dtTransOffset = 3;
	
	  ;% qbot2_DWork.isStable_d
	  section.data(5).logicalSrcIdx = 26;
	  section.data(5).dtTransOffset = 4;
	
	  ;% qbot2_DWork.doneDoubleBufferReInit_a
	  section.data(6).logicalSrcIdx = 27;
	  section.data(6).dtTransOffset = 5;
	
	  ;% qbot2_DWork.isStable_o
	  section.data(7).logicalSrcIdx = 28;
	  section.data(7).dtTransOffset = 6;
	
	  ;% qbot2_DWork.doneDoubleBufferReInit_k
	  section.data(8).logicalSrcIdx = 29;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1848512205;
  targMap.checksum1 = 1429672991;
  targMap.checksum2 = 1363043726;
  targMap.checksum3 = 3947479008;

