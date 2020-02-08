/*
***************************************************************************  
**  Program  : processTelegram - part of DSMRloggerAPI
**  Version  : v0.1.2
**
**  Copyright (c) 2020 Willem Aandewiel
**
**  TERMS OF USE: MIT License. See bottom of file.                                                            
***************************************************************************      
*/  

#if !defined(HAS_NO_SLIMMEMETER)
//==================================================================================
void handleSlimmemeter(){
  
  //DebugTf("showRaw (%s)\r\n", showRaw ?"true":"false");
  if (showRaw) {
    //-- process telegrams in raw mode
    processSlimmemeterRaw();
  } 
  else
  {
    processSlimmemeter();
  } 

}
void processSlimmemeterRaw(){
  char    tlgrm[1200] = "";
   
  DebugTf("handleSlimmerMeter RawCount=[%4d]\r\n", showRawCount);
  showRawCount++;
  showRaw = (showRawCount <= 20);
  if (!showRaw)
  {
    showRawCount  = 0;
    return;
  }
  
  #if defined( HAS_OLED_SSD1306 ) || defined( HAS_OLED_SH1106 )
    oled_Print_Msg(0, "<DSMRloggerAPI>", 0);
    oled_Print_Msg(1, "-------------------------",0);
    oled_Print_Msg(2, "Raw Format",0);
    sprintf(cMsg, "Raw Count %4d", showRawCount);
    oled_Print_Msg(3, cMsg, 0);
  #endif

    slimmeMeter.enable(true);
    Serial.setTimeout(5000);  // 5 seconds must be enough ..
    memset(tlgrm, 0, sizeof(tlgrm));
    int l = 0;
    // The terminator character is discarded from the serial buffer.
    l = Serial.readBytesUntil('/', tlgrm, sizeof(tlgrm));
    // now read from '/' to '!'
    // The terminator character is discarded from the serial buffer.
    l = Serial.readBytesUntil('!', tlgrm, sizeof(tlgrm));
    Serial.setTimeout(1000);  // seems to be the default ..
//    DebugTf("read [%d] bytes\r\n", l);
    if (l == 0) 
    {
      DebugTln(F("RawMode: Timerout - no telegram received within 5 seconds"));
      return;
    }

    tlgrm[l++] = '!';
#if !defined( USE_PRE40_PROTOCOL )
    // next 6 bytes are "<CRC>\r\n"
    for (int i=0; ( i<6 && (i<(sizeof(tlgrm)-7)) ); i++)
    {
      tlgrm[l++] = (char)Serial.read();
    }
#else
    tlgrm[l++]    = '\r';
    tlgrm[l++]    = '\n';
#endif
    tlgrm[(l +1)] = '\0';
    // shift telegram 1 char to the right (make room at pos [0] for '/')
    for (int i=strlen(tlgrm); i>=0; i--) { tlgrm[i+1] = tlgrm[i]; yield(); }
    tlgrm[0] = '/'; 
    //Post result to Debug 
    Debugf("Telegram (%d chars):\r\n/%s\r\n", strlen(tlgrm), tlgrm); 
  return;
}
//==================================================================================
void processSlimmemeter(){
  slimmeMeter.loop();
  if (slimmeMeter.available()) 
  {
    DebugTf("processSlimmerMeter telegramCount=[%d] telegramErrors=[%d]\r\n", telegramCount, telegramErrors);
    DebugTln(F("\r\n[Time----][FreeHeap/mBlck][Function----(line):\r"));
    // Voorbeeld: [21:00:11][   9880/  8960] loop        ( 997): read telegram [28] => [140307210001S]
    telegramCount++;
        
    DSMRdata = {};
    String    DSMRerror;
        
    if (slimmeMeter.parse(&DSMRdata, &DSMRerror))   // Parse succesful, print result
    {
      if (telegramCount > (UINT32_MAX - 1)) 
      {
        delay(1000);
        ESP.reset();
        delay(1000);
      }
      digitalWrite(LED_BUILTIN, LED_OFF);
      processTelegram();
      sendMQTTData();      
      
      if (Verbose2) 
      {
        DSMRdata.applyEach(showValues());
        printData();
      }
          
    } 
    else                  // Parser error, print error
    {
      telegramErrors++;
      DebugTf("Parse error\r\n%s\r\n\r\n", DSMRerror.c_str());
      slimmeMeter.enable(true);
    }
        
  } // if (slimmeMeter.available()) 
      
} // handleSlimmeMeter()

#endif

/***************************************************************************
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to permit
* persons to whom the Software is furnished to do so, subject to the
* following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT
* OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
* THE USE OR OTHER DEALINGS IN THE SOFTWARE.
* 
***************************************************************************/
