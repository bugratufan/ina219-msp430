/*
 * INA219.cpp
 *
 *  Created on: 23 Mar 2018
 *      Author: bugra
 */
#include <msp430.h>
#include "I2C.h"
#include "INA219.h"

using namespace MSP430;
I2C ina(UCB1);
unsigned char txData[1];
unsigned char rxData[2];
unsigned char current;
int voltage;

void calibrate_INA(INA inaNumber){
    unsigned char cal[] = {0x05, 0x02,0x1A};
    switch(inaNumber){
        case INA_1:
            ina.transmit(cal, 3, INA_1_ADDR);
        case INA_2:
            ina.transmit(cal, 3, INA_2_ADDR);
        case INA_3:
            ina.transmit(cal, 3, INA_3_ADDR);
        case INA_4:
            ina.transmit(cal, 3, INA_4_ADDR);
        case INA_5:
            ina.transmit(cal, 3, INA_5_ADDR);
        case INA_6:
            ina.transmit(cal, 3, INA_6_ADDR);
    }
}

unsigned char readCurrent(INA inaNumber){
    txData[0] = 0x01;

    switch(inaNumber){
        case INA_1:
            ina.transmit(txData, 1, INA_1_ADDR);
            delay(1);
            ina.receive(rxData, 2, INA_1_ADDR);
            delay(1);
            break;
        case INA_2:
            ina.transmit(txData, 1, INA_2_ADDR);
            delay(1);
            ina.receive(rxData, 2, INA_2_ADDR);
            delay(1);
            break;
        case INA_3:
            ina.transmit(txData, 1, INA_3_ADDR);
            delay(1);
            ina.receive(rxData, 2, INA_3_ADDR);
            delay(1);
            break;
        case INA_4:
            ina.transmit(txData, 1, INA_4_ADDR);
            delay(1);
            ina.receive(rxData, 2, INA_4_ADDR);
            delay(1);
            break;
        case INA_5:
            ina.transmit(txData, 1, INA_5_ADDR);
            delay(1);
            ina.receive(rxData, 2, INA_5_ADDR);
            delay(1);
            break;
        case INA_6:
            ina.transmit(txData, 1, INA_6_ADDR);
            delay(1);
            ina.receive(rxData, 2, INA_6_ADDR);
            delay(1);
            break;
    }
	voltage = ((int)(rxData[0]<<8|rxData[1]))*(0.08);
	current = voltage*2;
    return current;
}
