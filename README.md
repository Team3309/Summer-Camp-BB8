# Overview

This is a remix of [DIY Machine's 3D printable BB8 robot](https://www.thingiverse.com/thing:2749613/files).

It replaces the stock Arduino Uno with an ESP32 DevKit and includes a reed switch to turn the robot on/off. In addition, a generic L298N motor controller board replaces the original motor shield


# Bill Of Materials

| Qty. | Name | Link |
| ------- | ------ | ------- |
| 10 | 6 * 3mm Neodymium magnets | [Amazon](https://www.amazon.com/DIYMAG-6x3mm-Refrigerator-Premium-Brushed/dp/B07KZQGWNN/)
| 1 | Styrofoam hemisphere |
| 1 | Reed switch |
| 1 | L298N motor controller board |
| 1 | 3.3V Low-dropout regulator board |
| 1 | DOIT ESP32 DevKit v1 |
| 1 | 4*AA Battery harness |
| 2 | Geared 6v motors | [Amazon](https://www.amazon.com/Electric-Magnetic-Gearbox-Plastic-Yeeco/dp/B07DQGX369/) |
| 2 | 2.75in wheels | (included with motors) |
| 2-4 | .25in 4-40 Machine screws |
| 1 | Can of white spray paint |
| 1-2 fl oz | White acrylic paint |
| | Assorted sharpies
| ≥5 | Small zipties |
| ~1in<sup>2<sup> | Low friction PTFE tape |
| A few | Male-male wires |
| A few | Female-female wires |
| One of each | Printed parts | [CAD/STLs](https://github.com/Team3309/Summer-Camp-BB8/tree/main/CAD/STLs) |


# Assembly

## Step 0: Prepping shells and decoration

1. Sand the inside and outside of the shells so that the chassis and head can both slide freely on them

2. Spray paint the outside of the shells

3. Hotglue the styrofoam hemisphere to the head, then use white acrylic paint to coat the assembly

4. Use the stand as a stencil to sharpie BB8 patterns onto the shell

## Step 1: Installing motors and motor controller

1. As shown in DIY Machines' video, put the motors in the chassis and secure them with zip ties

2. Ziptie the motor controller bracket to the neck/mast of the chassis

3. Use the screws to secure the motor controller **with the heatsink facing down**

## Step 2: Installing the reed switch

1. Use the jaws of a pair of calipers to gently bend the leads of the reed switch
    - Make sure the side with the circle artifacts from the injection mold is facing away from the leads

2. Solder a pair of wires (any color, preferably red) to the leads
    - They should be about 4 inches long, better to make it long and cut later
3. Insert the reed switch into the slot on the top of the neck/mast. **Be careful not to bend the leads**, lest you risk breaking the fragile reeds inside

## Step 3: Wiring and cable management

1. Connect the components according to the wiring diagram
    - To connect multiple wires to the screw terminals on the motor controller, strip the ends of the wires and twist them together
    - The GND pin of the LDO needs to be connected directly to the GND pin on the ESP32 board
        - If negative from the battery, GND on the LDO, and GND on the ESP32 are connected with separate wires to the GND terminal of the motor controller, then electrical noise causes the ESP32 to intermittently shut off, which is bad (duh)
        - To solve that issue, strip the opposite end of the wire that is connected to the ESP32's ground pin and (gently) shove that end into the connector on the LDO's ground pin, then put that connector back on the LDO pin
2. Use a ziptie to secure the ESP32 board to the chassis ***TODO: example photo***
3. Do your best to round up all the cables so that none touch the wheels or shell of the robot

![Wiring Diagram](/wiring_diagram.png)
[Source for the above image](https://docs.google.com/presentation/d/1EXfWSO4wvMNs9FQZjlcnMrIVXtP51tsHmDwQ05yeIWY/edit#slide=id.ge3b93e37a7_0_0)

## Step 4: Installing neck and head magnets

1. Glue (try superglue if possible) two magnets in each slot on top of the neck
    - Make sure that they are all in the same orientation

2. Place small squares of PTFE tape on each exposed magnet

3. Put a half of the shell on top of the neck, then put a piece of wax paper

4. Stick three magnets to the ones in the neck (through the shell)

5. Apply hot glue to those magnets, then **quickly**, before the glue cools, place the head as straight as possible, facing forward

2. After the glue has fully cooled, place small squares of PTFE tape on each exposed magnet

## Step 5: Flash ESP32 board

- See /Code/README.md
