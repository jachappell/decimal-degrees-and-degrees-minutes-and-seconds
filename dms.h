//==================================================================
/**
 *  dms.h -- C++ functions to convert between decimal degrees
 *           and degrees, minutes, and seconds
 *
 *  Copyright (C) 2005-2016 by James A. Chappell
 *
 *  Permission is hereby granted, free of charge, to any person
 *  obtaining a copy of this software and associated documentation
 *  files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use,
 *  copy, modify, merge, publish, distribute, sublicense, and/or
 *  sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following
 *  conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *  OTHER DEALINGS IN THE SOFTWARE.
 */
//=================================================================
/*
 * dms.h:  Version 0.02
 * Created by James A. Chappell <rlrrlrll@gmail.com>
 * http://www.storage-b.com/c/16
 * Created 23 August 2005
 *
 * History:
 * 23-aug-2005  created
 * 25-apr-2008  added latitude/longitude conversions
 * 04-sep-2016  update degrees symbol
 * 
 */
//=================================================================

#ifndef __DMS_H__
#define __DMS_H__

#include <sstream>
#include <math.h> // for nearbyint()

namespace DMS
{
  static const char *DEG_SIM = "\u00B0";
//
//  Convert decimal degrees to degrees, minutes and seconds
// 
  inline std::string DegreesMinutesSeconds(double ang,
                                           unsigned int num_dec_places = 2)
  {
    bool neg(false) ;
    if (ang < 0.0)
    {
      neg = true ;
      ang = -ang ;
    }
  
    int deg = (int)ang ;
    double frac = ang - (double)deg ;

    frac *= 60.0 ;

    int min = (int)frac ;

    frac = frac - (double)min ;

    // fix the DDD MM 60 case
    // TODO: nearbyint isn’t alway available (Visual C++,
    //       for example)
    double sec = nearbyint(frac * 600000.0) ;
    sec /= 10000.0 ;

    if (sec >= 60.0)
    {
      min++ ;
      sec -= 60.0 ;
    }

    std::ostringstream oss ;

    if (neg)
    {
      oss << "-" ;
    }

//  TODO: allow user to define delimiters separating
//        degrees, minutes, and seconds.
    oss.setf(std::ios::fixed, std::ios::floatfield);

    oss << deg  
        << DEG_SIM ;
    oss.fill('0') ;
    oss.width(2) ;
    oss << min
        << "\'" ;
    if (num_dec_places == 0)
    {
      oss.width(2) ;
      oss.precision(0) ;
    }
    else
    {
      oss.width(num_dec_places + 3) ;
      oss.precision(num_dec_places) ;
    }
    oss << sec 
        << "\"" ;

    return oss.str() ;
  }


  inline std::string DegreesMinutesSecondsLat(double ang,
                        unsigned int num_dec_places = 2)
  {
    std::string lat(DegreesMinutesSeconds(ang, num_dec_places)) ;
  
    if (lat[0] == '-')
    {
      lat += std::string(" S") ;
      lat.erase(0, 1) ;
    }
    else
    {
      lat += std::string(" N") ;
    }

    lat = std::string(" ") + lat ;

    return lat ;
  }


  inline std::string DegreesMinutesSecondsLon(double ang,
                        unsigned int num_dec_places = 2)
  {
    std::string lon(DegreesMinutesSeconds(ang, num_dec_places)) ;

    if (lon[0] == '-')
    {
      lon += std::string(" W") ;
      lon.erase(0, 1) ;
    }
    else
    {
      lon += std::string(" E") ;
    }

    if (fabs(ang) < 100.0)
    {
      lon = std::string("0") + lon ;
    }

    return lon ;
  }


//
// Convert degrees, minutes and seconds to decimal degrees.
// 
  inline double DecimalDegrees(const std::string& dms)
  {
    std::string tmp(dms) ;

    // need to handle the -0 MM SS case
    // TODO: handle leading spaces before potential minus sign
    bool neg(false) ;

    if ((tmp[tmp.length() - 1] == 'W') || (tmp[tmp.length() - 1] == 'S') ||
        (tmp[0] == '-'))
    {
      neg = true ;
    }

    for (unsigned int i = 0 ; i < tmp.length() ; i++)
    {
      if (!isdigit(tmp[i]) && (tmp[i] != '.'))
      {
        tmp[i] = ' ' ;
      }
    }

    double deg(0.0), min(0.0), sec(0.0) ;
//  TODO: handle other delimiters
    std::istringstream iss(tmp) ;
    iss >> deg >> min >> sec ;

    double ang = deg + ((min + (sec / 60.0)) / 60.0) ;

    if (neg)
    {
      ang = -ang ;
    }

    return ang ;
  }
} ;

#endif
