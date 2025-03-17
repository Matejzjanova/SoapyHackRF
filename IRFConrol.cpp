//
// Created by misha on 10.03.2025.
//
#include "SoapyHackRF.hpp"
#include "IRFConrol.h"
//get device
int initDevice(SoapyHackRF *sdr) {
    SoapySDRKwargs *results = SoapySDRDevice_enumerate(NULL, &length);
    for (size_t i = 0; i < length; i++)
    {
        printf("Found device #%d: ", (int)i);
        for (size_t j = 0; j < results[i].size; j++)
        {
            printf("%s=%s, ", results[i].keys[j], results[i].vals[j]);
        }
        printf("\n");
    }

    //create device instance
    SoapySDRKwargs args = {};
    SoapySDRKwargs_set(&args, "driver", "hackrf"); //???
    SoapySDRDevice *sdr = SoapySDRDevice_make(&args); //init func
    SoapySDRKwargs_clear(&args);
    //check
    if (sdr == NULL)
    {
        printf("SoapySDRDevice_make fail: %s\n", SoapySDRDevice_lastError());
        return EXIT_FAILURE;
    }
    return 0;
}

int setFreq(double freq, SoapySDRDevice *sdr) {
    if (initDevice(*sdr) != 0)
    {
        return
    }
    if (SoapySDRDevice_setFrequency(sdr, SOAPY_SDR_RX, 0, freq, NULL) != 0)
    {
        printf("setFrequency fail: %s\n", SoapySDRDevice_lastError());
    }
}
