/**
 * @file steering_can_protocol.h
 * @brief Steering CAN Protocol.
 *
 */


#ifndef _OSCC_STEERING_CAN_PROTOCOL_H_
#define _OSCC_STEERING_CAN_PROTOCOL_H_


#include <stdint.h>


/*
 * @brief Steering command message (CAN frame) ID.
 *
 */
#define OSCC_COMMAND_STEERING_CAN_ID (0x64)

/*
 * @brief Steering report message (CAN frame) ID.
 *
 */
#define OSCC_REPORT_STEERING_CAN_ID (0x65)

/*
 * @brief Steering report message (CAN frame) length.
 *
 */
#define OSCC_REPORT_STEERING_CAN_DLC (8)

/*
 * @brief Steering report message publishing interval. [milliseconds]
 *
 */
#define OSCC_REPORT_STEERING_PUBLISH_INTERVAL_IN_MSEC (20)

/*
 * @brief Steering DTC bitfield position indicating an invalid sensor value.
 *
 */
#define OSCC_STEERING_DTC_INVALID_SENSOR_VAL (0x0)

/**
 * @brief Steering command message data.
 *
 * CAN frame ID: \ref OSCC_COMMAN_STEERING_CAN_ID
 *
 */
typedef struct
{
    uint16_t spoof_value_low; /*!< Value to be sent on the low spoof signal. */

    uint16_t spoof_value_high; /*!< Value to be sent on the high spoof signal. */

    uint8_t enable;    /*!< Command to enable or disable steering control. 
                         * Zero value means disable.
                         * Non-zero value means enable. */

    uint8_t reserved[3]; /*!< Reserved. */
} oscc_steering_command_s;


/**
 * @brief Steering report message data.
 *
 * CAN frame ID: \ref OSCC_REPORT_STEERING_CAN_ID
 *
 */
typedef struct
{

    uint8_t enabled; /*!< Steering controls enabled state.
                      * Zero value means disabled (commands are ignored).
                      * Non-zero value means enabled (no timeouts or overrides have occured). */

    uint8_t operator_override; /*!< Driver override state.
                                * Zero value means there has been no operator override.
                                * Non-zero value means an operator has physically overridden
                                * the system. */

    uint8_t dtcs; /* Bitfield of DTCs present in the module. */

    uint8_t reserved[5]; /*!< Reserved. */
} oscc_steering_report_s;


#endif /* _OSCC_STEERING_CAN_PROTOCOL_H_ */
