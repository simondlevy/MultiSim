/*
* SimFlightController.cpp: Abstract flight-control class for MulticopterSim
*
* Copyright (C) 2019 Simon D. Levy
*
* MIT License
*/

#include "SimFlightController.h"

// Math support
#define _USE_MATH_DEFINES
#include <math.h>

#include <hackflight.hpp>
#include "SimReceiver.h"
//
// MSP comms
#include "msppg/MSPPG.h"

// PID controllers
#include <pidcontrollers/level.hpp>
#include <pidcontrollers/althold.hpp>
#include <pidcontrollers/poshold.hpp>

// Main firmware
static hf::Hackflight hackflight;

// Receiver (joystick)
static hf::SimReceiver * receiver;

// PID tuning

static hf::Rate ratePid = hf::Rate(
	0.01,	// Roll/Pitch P
	0.01,	// Roll/Pitch I
	0.01,	// Roll/Pitch D
	0.5,	// Yaw P
	0.0,	// Yaw I
	8.f);	// Demands to rate


hf::Level level = hf::Level(0.20f);

#ifdef _PYTHON
static PythonLoiter loiter = PythonLoiter(
	0.5f,	// Altitude P
	1.0f,	// Altitude D
	0.2f);	// Cyclic P
#else

static hf::AltitudeHold althold = hf::AltitudeHold(
	1.00f,  // altHoldP
	0.50f,  // altHoldVelP
	0.01f,  // altHoldVelI
	0.10f); // altHoldVelD

static hf::PositionHold poshold = hf::PositionHold(
	0.2,	// posP
	0.2f,	// posrP
	0.0f);	// posrI

#endif

// Mixer
#include <mixers/quadx.hpp>
static hf::MixerQuadX mixer;

class SimBoard : public hf::Board {

    virtual bool getQuaternion(float quat[4]) override
    {
    }

    virtual bool getGyrometer(float gyroRates[3]) override
    {
    }

    virtual void writeMotor(uint8_t index, float value) override
    {
    }

    virtual float getTime(void) override
    {
    }

    virtual uint8_t	serialAvailableBytes(void) override
    {
    }
    
    virtual uint8_t	serialReadByte(void) override
    {
    }

    virtual void serialWriteByte(uint8_t c) override
    {
    }
};


SimFlightController::SimFlightController(void)
{
}

void SimFlightController::initReceiver(uint8_t  axismap[5], uint8_t buttonmap[3], bool reversedVerticals, bool springyThrottle, bool useButtonForAux)
{
    receiver = new hf::SimReceiver(axismap, buttonmap, reversedVerticals, springyThrottle, useButtonForAux);
}

SimFlightController::~SimFlightController(void)
{
}

void SimFlightController::update(void)
{
}

SimFlightController * SimFlightController::createSimFlightController(void)
{
    return new SimFlightController();
}
