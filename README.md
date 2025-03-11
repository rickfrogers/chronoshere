# CHRONOSPHERE Digital/Analog Hybrid Effects Pedal
*Created by rickfrogers on 2025-03-10*

## Overview
CHRONOSPHERE is a sophisticated multi-effect pedal combining digital signal processing with analog input/output stages to create rich, dynamic effects including rotary speaker simulation, delay, and reverb. The pedal features four distinct operating modes, extensive parameter control, and true bypass switching.

## Features
- 4 selectable effect modes via rotary encoder
- High-quality rotary speaker simulation with separate horn/drum emulation
- Digital delay and reverb processing
- Analog input/output stages for optimal audio quality
- 4 control parameters: Speed, Depth, Tone, and Mix
- True bypass switching
- Settings memory with EEPROM storage
- Status indication via 4 mode LEDs

## Effect Modes
1. **Classic Rotary**
   - Traditional Leslie-style speaker simulation
   - Independent horn and drum rotation
   - Variable speed and depth control

2. **Rotary + Delay**
   - Rotary effect with tempo-synchronized delay
   - Adjustable delay feedback and time
   - Tone control affects delay character

3. **Rotary + Reverb**
   - Rotary effect with spacial enhancement
   - Room size and damping control
   - Perfect for ambient textures

4. **Full Process**
   - Complete signal chain engagement
   - All effects running simultaneously
   - Maximum sound sculpting potential

## Hardware Requirements
### Core Components
- Teensy 4.0/3.2 microcontroller
- PJRC Audio Adapter Board
- 125B (or larger) aluminum enclosure

### Control Interface
- 4× 100kΩ linear potentiometers
- 1× PEC11R-4220F-S0024 rotary encoder
- 1× SPDT momentary footswitch
- 4× 5mm LEDs
- Associated resistors and hardware

### Analog Circuit
- 2× TL072 dual op-amps
- Various resistors and capacitors
- Power regulation components
- Input/output jacks

## Building Instructions
1. **Power Supply Assembly**
   - Build regulated power section first
   - Test voltages before proceeding

2. **Digital Core Setup**
   - Flash Teensy with provided code
   - Test audio shield functionality

3. **Analog Stages**
   - Assemble input buffer circuit
   - Build output stage
   - Test signal path

4. **Control Interface**
   - Mount potentiometers and encoder
   - Wire LED indicators
   - Install footswitch

5. **Final Assembly**
   - Mount all components in enclosure
   - Complete final wiring
   - Perform calibration

## Usage Guidelines
1. **Power Requirements**
   - 9V DC center negative
   - Minimum 100mA current capacity
   - Regulated power supply recommended

2. **Control Operation**
   - Speed: Adjusts modulation rate
   - Depth: Controls effect intensity
   - Tone: Shapes frequency response
   - Mix: Blends dry/wet signal

3. **Mode Selection**
   - Rotate encoder to select mode
   - LED indicators show current mode
   - Settings save automatically

4. **Bypass Operation**
   - True bypass when disengaged
   - LED indicates effect status
   - Smooth transition when switching

## Maintenance
- Regular cleaning of potentiometers
- Check power supply voltage
- Backup settings if replacing components
- Periodic software updates as available

## Troubleshooting
### Common Issues
1. No Power
   - Check power supply polarity
   - Verify voltage regulator output
   - Inspect power connections

2. No Sound
   - Test bypass operation
   - Check input/output connections
   - Verify audio shield settings

3. LED Issues
   - Check current limiting resistors
   - Verify control board connections
   - Test LED polarity

4. Erratic Operation
   - Clean all potentiometers
   - Check encoder connections
   - Verify ground connections

## Code Updates
Latest version: 1.0.0
- Current build: 2025-03-10
- Repository: [Link to be added]
- Update procedure documented in firmware folder

## Safety Notes
- Disconnect power before servicing
- Use proper ESD protection
- Avoid excessive input signals
- Maintain proper ventilation

## License
Copyright © 2025 rickfrogers
All rights reserved.

## Contact
For support and updates:
- GitHub: @rickfrogers
- Project Issues: [Link to be added]

---
*Last Updated: 2025-03-10 20
