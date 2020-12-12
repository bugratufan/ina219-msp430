/*
 * INA219.h
 *
 *  Created on: 23 Mar 2018
 *      Author: bugra
 */

#include <msp430fr5994.h>

#ifndef INA219_H_
#define INA219_H_



    enum INA {INA_1,INA_2, INA_3, INA_4, INA_5, INA_6};

    using namespace MSP430;

    #define INA_1_ADDR 0x40
    #define INA_2_ADDR 0x41
    #define INA_3_ADDR 0x42 //ANTEN_1
    #define INA_4_ADDR 0x43 //ANTEN_2
    #define INA_5_ADDR 0x44 //ANTEN_3
    #define INA_6_ADDR 0x45 //ANTEN_4


    #define CONF_ADDR 0X00
    #define SHUNT_VOLT_ADDR 0x01
    #define BUS_VOLT_ADDR 0x02
    #define POW_ADDR 0x03
    #define CURRENT_ADDR 0x04
    #define CALIB_ADDR 0x05

    void calibrate_INA(INA inaNumber);
    unsigned char readCurrent(INA inaNumber);


#endif /* INA219_H_ */
