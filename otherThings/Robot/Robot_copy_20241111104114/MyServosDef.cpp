#include "MyServosDef.h"

myServo hipL = {
    .taskSignalName = "HipL",
    .writePin = 16,
    .readPin = 11,
    .delayTime = 1500,
    .degree = 90,
    .isLeft = 1,
    .limitAngleStart = 45,
    .limitAngleEnd = 135,
    .errorFixAngle = 0,
    .isSetting = 0
};

myServo hipR = {
    .taskSignalName = "HipR",
    .writePin = 26,
    .readPin = 12,
    .delayTime = 1500,
    .degree = 90,
    .isLeft = 0,
    .limitAngleStart = 45,
    .limitAngleEnd = 135,
    .errorFixAngle = 0,
    .isSetting = 0
};

myServo thighL = {
    .taskSignalName = "ThighL",
    .writePin = 4,
    .readPin = 13,
    .delayTime = 1500,
    .degree = 90,
    .isLeft = 1,
    .limitAngleStart = 0,
    .limitAngleEnd = 180,
    .errorFixAngle = 0,
    .isSetting = 0
};

myServo thighR = {
    .taskSignalName = "ThighR",
    .writePin = 27,
    .readPin = 14,
    .delayTime = 1500,
    .degree = 90,
    .isLeft = 0,
    .limitAngleStart = 0,
    .limitAngleEnd = 180,
    .errorFixAngle = 0,
    .isSetting = 0
};

myServo calfL = {
    .taskSignalName = "CalfL",
    .writePin = 5,
    .readPin = 15,
    .delayTime = 1500,
    .degree = 90,
    .isLeft = 1,
    .limitAngleStart = 0,
    .limitAngleEnd = 180,
    .errorFixAngle = 0,
    .isSetting = 0
};

myServo calfR = {
    .taskSignalName = "CalfR",
    .writePin = 14,
    .readPin = 16,
    .delayTime = 1500,
    .degree = 90,
    .isLeft = 0,
    .limitAngleStart = 0,
    .limitAngleEnd = 180,
    .errorFixAngle = 0,
    .isSetting = 0
};

myServo ankleL = {
    .taskSignalName = "AnkleL",
    .writePin = 17,
    .readPin = 17,
    .delayTime = 1500,
    .degree = 90,
    .isLeft = 1,
    .limitAngleStart = 30,
    .limitAngleEnd = 150,
    .errorFixAngle = 0,
    .isSetting = 0
};

myServo ankleR = {
    .taskSignalName = "AnkleR",
    .writePin = 12,
    .readPin = 18,
    .delayTime = 1500,
    .degree = 90,
    .isLeft = 0,
    .limitAngleStart = 30,
    .limitAngleEnd = 150,
    .errorFixAngle = 0,
    .isSetting = 0
};
