3A:

1. Do the reported values vary even when you do not touch the potentiometer?

Yes the reported values vary.

2. Do the values change continuously, or do they occupy discrete integer levels? Why?

They change continuously. This is because of electrons moving and changing the value of the potnetiometer by 1 bit which causes the reported values of the potentiometer to flacuate.

3. What does Serial Monitor reveal that is difficult to see in Serial Plotter, and vice versa?

In Serial Monitor it is easier to see the numbers changing while in Serial plotter it was easier to see how much the numbers were changing by.

3B:

4. Calculate this resolution in millivolts. For a 5.00 V reference it is about 4.88 mV. Explain why printing many decimal places does not, by itself, give the ADC finer physical resolution.

Printing many decimal places does not give the ADC finer physical resolution because a 10-bit ADC can only distinguish 1024 voltage levels and for 5.00V reference each ADC count represents around 4.88mV. so printing extra digits does not add measured information

3C-Part B:

5. Explain likely departures from the 1/sqrt(N) prediction, including drift, correlated pickup, quantization, and variation of the Arduino reference voltage. Averaging improves precision under these conditions, but it does not automatically improve absolute accuracy or remove calibration errors.

The measured noise may not decrease exactly as 1/sqrt(N) because some errors are not random and independent. Drift, correlated electrical pickup, ADC quantization, and changes in the Arduino reference voltage can cause deviations. Averaging reduces random noise and improves precision, but it cannot necessarily remove systematic errors or improve the absolute accuracy of the measurement.

3D:

6. Explain the tradeoff. Averaging over a finite interval acts as a low-pass filter: rapid fluctuations tend to cancel, but changes occurring during the averaging window are smoothed or delayed. Improved voltage precision therefore comes with reduced time resolution.

When we average a bigger sample size, we get a much more accurate measurement of what the voltage is but the code runs much slower. this is because it takes longer to compute 1000 events than 1 event.

4:

7.What is the period, amplitude and duty-cycle of the PWM as a function of voltage?

The period is approximately 2.04ms, amplitude is 

8.Record the PWM high and low voltages, period, frequency, and duty cycle at two substantially different potentiometer settings. Determine which quantities change and which remain approximately fixed.

the period and amplitude stays constant while the potentiometer is not changed. the duty-cycle changes.

9.Explain why the LED looks continuously lit even though the oscilloscope resolves individual pulses.
