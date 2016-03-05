decimal-degrees-and-degrees-minutes-and-seconds
===============================================

<a href="https://www.storage-b.com/c/16">C++ functions to convert between decimal degrees and degrees, minutes, and seconds</a>

Here's some C++ functions which handle the conversion between these two formats:
<pre>
<tt>
<font color="#2040a0">std</font><font color="4444FF">:</font><font color="4444FF">:</font><font color="#2040a0">string</font> <font color="#2040a0">DMS::DegreesMinutesSeconds</font><font color="4444FF">(</font><strong>double</strong> <font color="#2040a0">ang</font>,
                                       <strong>unsigned</strong> <strong>int</strong> <font color="#2040a0">num_dec_places</font> <font color="4444FF">=</font> <font color="#FF0000">2</font><font color="4444FF">)</font>
<font color="#2040a0">std</font><font color="4444FF">:</font><font color="4444FF">:</font><font color="#2040a0">string</font> <font color="#2040a0">DMS::DegreesMinutesSecondsLat</font><font color="4444FF">(</font><strong>double</strong> <font color="#2040a0">ang</font>,
                                          <strong>unsigned</strong> <strong>int</strong> <font color="#2040a0">num_dec_places</font> <font color="4444FF">=</font> <font color="#FF0000">2</font><font color="4444FF">)</font>
<font color="#2040a0">std</font><font color="4444FF">:</font><font color="4444FF">:</font><font color="#2040a0">string</font> <font color="#2040a0">DMS::DegreesMinutesSecondsLon</font><font color="4444FF">(</font><strong>double</strong> <font color="#2040a0">ang</font>,
                                          <strong>unsigned</strong> <strong>int</strong> <font color="#2040a0">num_dec_places</font> <font color="4444FF">=</font> <font color="#FF0000">2</font><font color="4444FF">)</font>

<strong>double</strong> <font color="#2040a0">DMS::DecimalDegrees</font><font color="4444FF">(</font><strong>const</strong> <font color="#2040a0">std</font><font color="4444FF">:</font><font color="4444FF">:</font><font color="#2040a0">string</font><font color="4444FF">&amp;</font> <font color="#2040a0">dms</font><font color="4444FF">)</font>
</tt>
</pre>
