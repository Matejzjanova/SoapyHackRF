//
// Created by misha on 10.03.2025.
//
#include "SoapyHackRF.hpp"

#ifndef SDR_IRFCONTROL_H
#define SDR_IRFCONTROL_H
int setFreq(double freq);
int setLNA();
int setAtt();
int initDevice(SoapySDRDevice *sdr);
#endif //SDR_IRFCONTROL_H
