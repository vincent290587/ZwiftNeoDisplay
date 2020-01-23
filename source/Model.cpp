/*
 * Global.cpp
 *
 *  Created on: 17 oct. 2017
 *      Author: Vincent
 */

#include "Model.h"
#include "helper.h"
#include "gpio.h"
#include "boards.h"
#include "sdk_config.h"
#include "app_scheduler.h"
#include "segger_wrapper.h"


#if defined (BLE_STACK_SUPPORT_REQD)
#include "ble_api_base.h"
#endif

#ifdef ANT_STACK_SUPPORT_REQD
#include "ant.h"
#endif


sAppErrorDescr m_app_error __attribute__ ((section(".noinit")));


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
	for(;;)
	{

#if APP_SCHEDULER_ENABLED
		app_sched_execute();
#endif

#if defined (ANT_STACK_SUPPORT_REQD)
		ant_tasks();
#endif

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
