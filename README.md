decimal-degrees-and-degrees-minutes-and-seconds
===============================================

C++ functions to convert between decimal degrees and degrees, minutes, and seconds

Here's some C++ functions which handle the conversion between these two formats:


std::string DMS::DegreesMinutesSeconds(double ang,
                                       unsigned int num_dec_places = 2)

std::string DMS::DegreesMinutesSecondsLat(double ang,
                                          unsigned int num_dec_places = 2)

std::string DMS::DegreesMinutesSecondsLon(double ang,
                                          unsigned int num_dec_places = 2)

double DMS::DecimalDegrees(const std::string& dms)

