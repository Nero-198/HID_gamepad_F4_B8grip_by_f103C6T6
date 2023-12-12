/*
 * gamepad_digital_input_driver.cpp
 *
 *  Created on: Oct 31, 2023
 *      Author: iroen
 */

#include <gamepad_digital_input_driver.h>

gamepad_digital_input_driver::gamepad_digital_input_driver(/* args */)
{
}

gamepad_digital_input_driver::~gamepad_digital_input_driver()
{
}

uint8_t gamepad_digital_input_driver::init_gamepad_digital_input_driver(){
    uint8_t ret = 0;
    return ret;
}

void gamepad_digital_input_driver::getButtonVal(){
    uint8_t gpio_val = 0;
    for (uint8_t i = 0; i < buttons.size(); i++)
    {
        uint8_t bitmask = 0x01 << ((buttons[i].HID_button -1)%8);
        gpio_val = HAL_GPIO_ReadPin(buttons[i].port, buttons[i].pin);
        if (gpio_val == 0 )
        {
            HID_button[i/8] &= ~bitmask;
        }
        else
        {
            HID_button[i/8] |= bitmask;
        }
    }
}

void gamepad_digital_input_driver::setButton(GPIO_TypeDef* port, uint16_t pin, uint8_t HID_button){
    button_t newButton = {port, pin, HID_button};
    buttons.push_back(newButton);
}

void gamepad_digital_input_driver::set_input_key_matrix(GPIO_TypeDef* port, uint16_t pin, uint8_t input_num){
    input_key_matrix_t newInputKeyMatrix = {port, pin, input_num};
    input_key_matrix.push_back(newInputKeyMatrix);
}

void gamepad_digital_input_driver::set_output_key_matrix(GPIO_TypeDef* port, uint16_t pin, uint8_t output_num){
    output_key_matrix_t newOutputKeyMatrix = {port, pin, output_num};
    output_key_matrix.push_back(newOutputKeyMatrix);
}

void gamepad_digital_input_driver::set_matrix_to_HID_button(uint8_t input_num, uint8_t output_num, uint8_t HID_button){
    key_matrix[input_num][output_num].input = input_key_matrix[input_num];
    key_matrix[input_num][output_num].output = output_key_matrix[output_num];
    key_matrix[input_num][output_num].HID_button = HID_button;
}