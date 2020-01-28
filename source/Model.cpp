/*
 * Global.cpp
 *
 *  Created on: 17 oct. 2017
 *      Author: Vincent
 */

#include "Model.h"
#include "helper.h"
#include "millis.h"
#include "gpio.h"
#include "boards.h"
#include "sdk_config.h"
#include "drv_ws2812.h"
#include "PowerZone.h"
#include "app_scheduler.h"
#include "segger_wrapper.h"


#if defined (BLE_STACK_SUPPORT_REQD)
#include "ble_api_base.h"
#endif

#ifdef ANT_STACK_SUPPORT_REQD
#include "ant.h"
#endif

#define NEOPIXEL_NB       20

sAppErrorDescr m_app_error __attribute__ ((section(".noinit")));

PowerZone m_pzones(265);
static float m_filt_power = 0.f;
static uint8_t m_is_pw_updated = 0;
static uint16_t m_pw = 0;

void model_dispatch_sensors_update(uint16_t power) {

	m_pw = power;
	m_is_pw_updated = 1;
}

static void model_app_tasks(void) {

	if (m_is_pw_updated) {

		// clear flag
		m_is_pw_updated = 0;

		// update averaging
		//m_filt_power = 0.5f * m_filt_power + (1.f - 0.5f) * ((float)m_pw);

		// TODO filter
		m_pzones.addPowerData(m_pw, millis());

		uint32_t color = 0;
		if (m_pzones.getCurBin() == 0) {

			drv_ws2812_set_pixel_all(color);
			drv_ws2812_display(NULL, NULL);
			return;
		}

#if USE_ONE_COLOR

		// calculate the color of the whole ring
		float f_shift = regFenLim(
			m_pzones.getCurBin() + m_pzones.getCurPC() / 100.f,
			1.f, m_pzones.getNbBins() + 1.f,
			0.5f, 16.5f
			);
		uint8_t shift = (uint8_t) f_shift;
		color = 0xFF << shift;

		drv_ws2812_set_pixel_all(color);

#else

		// calculate the base color
		float f_shift_base = regFenLim(
			m_pzones.getCurBin(),
			1.f, m_pzones.getNbBins() + 1.f,
			0.5f, 16.5f
			);
		uint8_t shift_base = (uint8_t) f_shift_base;
		uint32_t color_base = 0xFF << shift_base;
		if (!m_pzones.getCurBin()) color_base = 0;

		// calculate the up color
		float f_shift_up = regFenLim(
			m_pzones.getCurBin() + 1.f,
			1.f, m_pzones.getNbBins() + 1.f,
			0.5f, 16.5f
			);
		uint8_t shift_up = (uint8_t) f_shift_up;
		uint32_t color_up = 0xFF << shift_up;

		// calculate illumination proportion
		float prop = m_pzones.getCurPC() * (float)NEOPIXEL_NB / 100.f;

		if (m_pzones.getCurBin() % 2 == 1) {

			drv_ws2812_set_pixel_all(color_base);

			// start at the top
			for (int i=0; (float)i + 0.5f < prop / 2.f; i++) {

				drv_ws2812_set_pixel(i, color_up);
				drv_ws2812_set_pixel(NEOPIXEL_NB - i - 1, color_up);
			}

		} else {

			drv_ws2812_set_pixel_all(color_up);

			// bin 1 and so one:
			// start at the base
			for (int i=0; (float)i + 0.5f < prop / 2.f; i++) {

				drv_ws2812_set_pixel(i, color_base);
				drv_ws2812_set_pixel(NEOPIXEL_NB - i - 1, color_base);
			}

		}
#endif

		drv_ws2812_display(NULL, NULL);
	}

}

void perform_system_tasks_light(void) {

#if APP_SCHEDULER_ENABLED
	app_sched_execute();
#endif

	if (LOG_PROCESS() == false)
	{
		pwr_mgmt_run();
	}
}

void peripherals_task(void * p_context)
{
	drv_ws2812_init(0); // TODO pin

	for(;;)
	{

#if APP_SCHEDULER_ENABLED
		app_sched_execute();
#endif

#if defined (ANT_STACK_SUPPORT_REQD)
		ant_tasks();
#endif

		model_app_tasks();

		// BSP tasks
		bsp_tasks();

		w_task_delay(20);

	}
}

/**
 *
 * @param p_context
 */
void idle_task(void * p_context)
{
	for(;;)
	{
		if (LOG_PROCESS() == false) {
			pwr_mgmt_run();
		}

		w_task_yield();
	}
}
