/*
 * Thermistor.h
 *
 *  Created on: Nov 5, 2015
 *      Author: sigmond
 */

#ifndef THERMISTOR_H_
#define THERMISTOR_H_
#include "Arduino.h"

#define THERM_NOM_RES 3000
#define STATIC_RES 10000
#define NOM_TEMP_C 25.0
#define DEFAULT_BETA_COEFF 3936
#define MAX_RECORDED_TEMPS 3

// Beta is calculated using two known resistance-temperature values. equation is as follows: (ln(R/R0))/((1/(T+273.15))-(1/(T0+273.15))) where resistance is in ohms, and tmperature is in Celcius

class Thermistor {
	enum Temperature {
		CELCIUS, FAHRENHEIT
	};
public:

	Thermistor(unsigned int analog_pin, unsigned int scale_ohm = THERM_NOM_RES,
			unsigned int static_ohm = STATIC_RES, float temp_nom_c = NOM_TEMP_C,
			unsigned int b_coeff = DEFAULT_BETA_COEFF);
	~Thermistor();

	float readTemp(Temperature temp = CELCIUS);
	float lastTemp(Temperature temp = CELCIUS);
	float average3Temp(Temperature temp = CELCIUS);

private:
	unsigned int m_ScaleOhm;
	unsigned int m_StaticOhm;
	unsigned int m_Pin;
	float m_NomC;
	unsigned int m_BetaCoeff;

	float m_lastTempC[MAX_RECORDED_TEMPS];

};

#endif /* THERMISTOR_H_ */
