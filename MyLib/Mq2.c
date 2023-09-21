#include "../MyLib/Mq2.h"
#include "math.h"
static esp_adc_cal_characteristics_t *adc_chars;
static adc_channel_t channel_mq7 = ADC_CHANNEL_3;
static const adc_channel_t channel_mq6 = ADC_CHANNEL_0;
static const adc_bits_width_t width = ADC_WIDTH_BIT_12;

static const adc_atten_t atten = ADC_ATTEN_DB_0;
static const adc_unit_t unit = ADC_UNIT_1;
uint32_t voltage_mq7 = 0;
uint32_t voltage_mq6 = 0;

__weak void MQ_CallBack_Data(float ppm)
{
}

float MQ_adcToVolt(uint16_t adc_value)
{
	return adc_value * 3.3 / 4095;
}
void MQ_Init(unit32_t _adc, TypeDef_MQ *MQ, float _MQ_Slope, float _MQ_Block_Point)
{
	hadc = _hadc;
	MQ->MQ_Slope = _MQ_Slope;
	MQ->MQ_Block_Point = _MQ_Block_Point;
}
void MQ_set_RS_Gas(TypeDef_MQ *MQ)
{
	MQ->MQ_RS_gas = 3.3 * 10 / (MQ->MQ_Sensor_Volt - 0.1) - 10;
}
void MQ_set_Sensor_Volt(TypeDef_MQ *MQ, uint16_t value_adc)
{
	MQ->MQ_Sensor_Volt = MQ_adcToVolt(value_adc);
}
void MQ_set_Ratio(TypeDef_MQ *MQ)
{
	MQ->MQ_Ratio = MQ->MQ_RS_gas / R0;
}
void MQ_Read_Sensor(TypeDef_MQ *MQ, unit16_t adc_value)
{

	// uint32_t adc_reading_mq7 = 0;
	// uint32_t adc_reading_mq6 = 0;

	// // configure ADC
	// if (unit == ADC_UNIT_1)
	// {
	// 	printf("Configured for ADC 1\n");
	// 	adc1_config_width(width);
	// 	adc1_config_channel_atten(channel_mq7, atten);
	// 	adc1_config_channel_atten(channel_mq6, atten);
	// }

	// // characterize ADC
	// adc_chars = calloc(1, sizeof(esp_adc_cal_characteristics_t));
	// esp_adc_cal_value_t val_type = esp_adc_cal_characterize(unit, atten, width, DEFAULT_VREF, adc_chars);
	// while (1)
	// {
	// 	adc_reading_mq7 = 0;
	// 	adc_reading_mq6 = 0;

	// 	// multisampling
	// 	for (int i = 0; i < NO_OF_SAMPLES; i++)
	// 	{
	// 		if (unit == ADC_UNIT_1)
	// 		{
	// 			adc_reading_mq7 += adc1_get_raw((adc1_channel_t)channel_mq7);
	// 			adc_reading_mq6 += adc1_get_raw((adc1_channel_t)channel_mq6);
	// 		}
	// 	}

	// 	adc_reading_mq7 /= NO_OF_SAMPLES;
	// 	adc_reading_mq6 /= NO_OF_SAMPLES;

	// 	// convert adc_reading to voltage in mV
	// 	voltage_mq7 = esp_adc_cal_raw_to_voltage(adc_reading_mq7, adc_chars);
	// 	voltage_mq6 = esp_adc_cal_raw_to_voltage(adc_reading_mq6, adc_chars);

	MQ_set_Sensor_Volt(MQ, val_type);
	MQ_set_RS_Gas(MQ);
	MQ_set_Ratio(MQ);
	float ppm_log = (log10(MQ->MQ_Ratio) - MQ->MQ_Block_Point) / MQ->MQ_Slope;
	float ppm = pow(10, ppm_log);
	MQ_CallBack_Data(ppm);
	HAL_ADC_Stop(hadc);
}
