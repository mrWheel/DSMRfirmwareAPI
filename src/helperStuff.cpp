/*
***************************************************************************
**  Program  : helperStuff, part of DSMRloggerAPI
**  Version  : v3.0
**
**  Copyright (c) 2020 .. 2022 Willem Aandewiel
**
**  TERMS OF USE: MIT License. See bottom of file.
***************************************************************************
*/
#include "helperStuff.h"


//===========================================================================================
int readSerialUntil(Stream &uartOut, char cEnd, uint32_t waitT, bool doEcho)
{
  uint32_t waitTimer = millis();
  int charCount = 0;

  while((millis()-waitTimer) < waitT)
  {
    yield();
    char cIn=Serial.read();
    if ((cIn>=' '&& cIn<='z') || cIn=='\r' || cIn=='\n')
    {
      waitTimer = millis(); //-- rewind
      if (doEcho) uartOut.print(cIn);
      charCount++;
      if (cIn==cEnd)
      {
        //if (doEcho) uartOut.println();
        return charCount;
      }
      waitTimer = millis();
    }
  }

  return 0;

} //  readSerialUntil()


//===========================================================================================
bool compare(String x, String y)
{
  for (int i = 0; i < min(x.length(), y.length()); i++)
  {
    if (x[i] != y[i])
    {
      return (bool)(x[i] < y[i]);
    }
  }
  return x.length() < y.length();

} // compare()


//===========================================================================================
boolean isValidIP(IPAddress ip)
{
  /* Works as follows:
    *  example:
    *  127.0.0.1
    *   1 => 127||0||0||1 = 128>0 = true
    *   2 => !(false || false) = true
    *   3 => !(false || false || false || false ) = true
    *   4 => !(true && true && true && true) = false
    *   5 => !(false) = true
    *   true && true & true && false && true = false ==> correct, this is an invalid addres
    *
    *   0.0.0.0
    *   1 => 0||0||0||0 = 0>0 = false
    *   2 => !(true || true) = false
    *   3 => !(false || false || false || false) = true
    *   4 => !(true && true && true && tfalse) = true
    *   5 => !(false) = true
    *   false && false && true && true && true = false ==> correct, this is an invalid addres
    *
    *   192.168.0.1
    *   1 => 192||168||0||1 =233>0 = true
    *   2 => !(false || false) = true
    *   3 +> !(false || false || false || false) = true
    *   4 => !(false && false && true && true) = true
    *   5 => !(false) = true
    *   true & true & true && true && true = true ==> correct, this is a valid address
    *
    *   255.255.255.255
    *   1 => 255||255||255||255 =255>0 = true
    *   2 => !(false || false ) = true
    *   3 +> !(true || true || true || true) = false
    *   4 => !(false && false && false && false) = true
    *   5 => !(true) = false
    *   true && true && false && true && false = false ==> correct, this is an invalid address
    *
    *   0.123.12.1       => true && false && true && true && true = false  ==> correct, this is an invalid address
    *   10.0.0.0         => true && false && true && true && true = false  ==> correct, this is an invalid address
    *   10.255.0.1       => true && true && false && true && true = false  ==> correct, this is an invalid address
    *   150.150.255.150  => true && true && false && true && true = false  ==> correct, this is an invalid address
    *
    *   123.21.1.99      => true && true && true && true && true = true    ==> correct, this is annvalid address
    *   1.1.1.1          => true && true && true && true && true = true    ==> correct, this is annvalid address
    *
    *   Some references on valid ip addresses:
    *   - https://www.quora.com/How-do-you-identify-an-invalid-IP-address
    *
    */
  boolean _isValidIP = false;
  _isValidIP = ((ip[0] || ip[1] || ip[2] || ip[3])>0);                             // if any bits are set, then it is not 0.0.0.0
  _isValidIP &= !((ip[0]==0) || (ip[3]==0));                                       // if either the first or last is a 0, then it is invalid
  _isValidIP &= !((ip[0]==255) || (ip[1]==255) || (ip[2]==255) || (ip[3]==255)) ;  // if any of the octets is 255, then it is invalid
  _isValidIP &= !(ip[0]==127 && ip[1]==0 && ip[2]==0 && ip[3]==1);                 // if not 127.0.0.0 then it might be valid
  _isValidIP &= !(ip[0]>=224);                                                     // if ip[0] >=224 then reserved space

  DebugTf( "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
  if (_isValidIP)
    Debugln(F(" = Valid IP"));
  else
    Debugln(F(" = Invalid IP!"));

  return _isValidIP;

} //  isValidIP()


//===========================================================================================
bool isNumericp(const char *timeStamp, int8_t len)
{
  for (int i=0; (i<len && i<12); i++)
  {
    if (timeStamp[i] < '0' || timeStamp[i] > '9')
    {
      return false;
    }
  }
  return true;

} // isNumericp()


//===========================================================================================
int8_t splitString(String inStrng, char delimiter, String wOut[], uint8_t maxWords)
{
  int16_t inxS = 0, inxE = 0, wordCount = 0;

  inStrng.trim();
  while(inxE < inStrng.length() && wordCount < maxWords)
  {
    inxE  = inStrng.indexOf(delimiter, inxS);         //finds location of first ,
    wOut[wordCount] = inStrng.substring(inxS, inxE);  //captures first data String
    wOut[wordCount].trim();
    //DebugTf("[%d] => [%c] @[%d] found[%s]\r\n", wordCount, delimiter, inxE, wOut[wordCount].c_str());
    inxS = inxE;
    inxS++;
    wordCount++;
  }
  // zero rest of the words
  for(int i=wordCount; i< maxWords; i++)
  {
    wOut[wordCount][0] = 0;
  }
  // if not whole string processed place rest in last word
  if (inxS < inStrng.length())
  {
    wOut[maxWords-1] = inStrng.substring(inxS, inStrng.length());  // store rest of String
  }

  return wordCount;

} // splitString()


//===========================================================================================
String upTime()
{
  char    calcUptime[20];

  snprintf(calcUptime, sizeof(calcUptime), "%d(d)-%02d:%02d(H:m)"
           , int((upTimeSeconds / (60 * 60 * 24)) % 365)
           , int((upTimeSeconds / (60 * 60)) % 24)
           , int((upTimeSeconds / (60)) % 60));

  return calcUptime;

} // upTime()


//===========================================================================================
void strConcat(char *dest, int maxLen, const char *src)
{
  if (strlen(dest) + strlen(src) < maxLen)
  {
    strcat(dest, src);
  }
  else
  {
    DebugTf("Combined string > %d chars\r\n", maxLen);
  }

} // strConcat()


//===========================================================================================
void strConcat(char *dest, int maxLen, float v, int dec)
{
  static char buff[25];
  if (dec == 0)       sprintf(buff, "%.0f", v);
  else if (dec == 1)  sprintf(buff, "%.1f", v);
  else if (dec == 2)  sprintf(buff, "%.2f", v);
  else if (dec == 3)  sprintf(buff, "%.3f", v);
  else if (dec == 4)  sprintf(buff, "%.4f", v);
  else if (dec == 5)  sprintf(buff, "%.5f", v);
  else                sprintf(buff, "%f",   v);

  if (strlen(dest) + strlen(buff) < maxLen)
  {
    strcat(dest, buff);
  }
  else
  {
    DebugTf("Combined string > %d chars\r\n", maxLen);
  }

} // strConcat()


//===========================================================================================
void strConcat(char *dest, int maxLen, int32_t v)
{
  static char buff[25];
  sprintf(buff, "%d", v);

  if (strlen(dest) + strlen(buff) < maxLen)
  {
    strcat(dest, buff);
  }
  else
  {
    DebugTf("Combined string > %d chars\r\n", maxLen);
  }

} // strConcat()


//===========================================================================================
void strToLower(char *src)
{
  for (int i = 0; i < strlen(src); i++)
  {
    if (src[i] == '\0') return;
    if (src[i] >= 'A' && src[i] <= 'Z')
      src[i] += 32;
  }
} // strToLower()

//===========================================================================================
// a 'save' string copy
void strCopy(char *dest, int maxLen, const char *src, uint8_t frm, uint8_t to)
{
  int d=0;
  //DebugTf("dest[%s], src[%s] max[%d], frm[%d], to[%d] =>\r\n", dest, src, maxLen, frm, to);
  dest[0] = '\0';
  for (int i=0; i<=frm; i++)
  {
    if (src[i] == 0) return;
  }
  for (int i=frm; (src[i] != 0  && i<=to && d<maxLen); i++)
  {
    dest[d++] = src[i];
  }
  dest[d] = '\0';

} // strCopy()

//===========================================================================================
// a 'save' version of strncpy() that does not put a '\0' at
// the end of dest if src >= maxLen!
void strCopy(char *dest, int maxLen, const char *src)
{
  dest[0] = '\0';
  strcat(dest, src);

} // strCopy()


//===========================================================================================
int stricmp(const char *a, const char *b)
{
  for (;; a++, b++)
  {
    int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
    if (d != 0 || !*a)
      return d;
  }

} // stricmp()

//===========================================================================================
char *intToStr(int32_t v)
{
  static char buff[25];
  sprintf(buff, "%d", v);
  return buff;

} // intToStr()

//===========================================================================================
char *floatToStr(float v, int dec)
{
  static char buff[25];
  if (dec == 0)       sprintf(buff, "%.0f", v);
  else if (dec == 1)  sprintf(buff, "%.1f", v);
  else if (dec == 2)  sprintf(buff, "%.2f", v);
  else if (dec == 3)  sprintf(buff, "%.3f", v);
  else if (dec == 4)  sprintf(buff, "%.4f", v);
  else if (dec == 5)  sprintf(buff, "%.5f", v);
  else                sprintf(buff, "%f",   v);
  return buff;

} // floattToStr()

//===========================================================================================
float formatFloat(float v, int dec)
{
  return (String(v, dec).toFloat());

} //  formatFloat()

//===========================================================================================
float strToFloat(const char *s, int dec)
{
  float r =  0.0;
  int   p =  0;
  int   d = -1;

  r = strtof(s, NULL);
  p = (int)(r*pow(10, dec));
  r = p / pow(10, dec);
  //DebugTf("[%s][%d] => p[%d] -> r[%f]\r\n", s, dec, p, r);
  return r;

} //  strToFloat()

/***
//=======================================================================
template<typename Item>
Item &typecastValue(Item &i)
{
  return i;
}
***/

//=======================================================================
float typecastValue(TimestampedFixedValue i)
{
  return strToFloat(String(i).c_str(), 3);
}

//=======================================================================
float typecastValue(FixedValue i)
{
  return i;
}
// Add an overload for uint16_t
float typecastValue(uint16_t i) {
    return static_cast<float>(i);  // Cast to float, as `createMQTTjsonMessage` likely expects a float
}

// You may also want to add for other primitive types like uint8_t, int, etc.
float typecastValue(uint8_t i) {
    return static_cast<float>(i);
}

float typecastValue(int i) {
    return static_cast<float>(i);
}

float typecastValue(float i) {
    return i;  // No need to cast, it's already a float
}
// Overload for Arduino String to convert it to a float
float typecastValue(String &i) {
    return i.toFloat();  // Convert the string to a float
}

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