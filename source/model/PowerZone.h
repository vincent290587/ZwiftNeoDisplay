/*
 * PowerZone.h
 *
 *  Created on: 14 mrt. 2019
 *      Author: v.golle
 */

#ifndef SOURCE_MODEL_POWERZONE_H_
#define SOURCE_MODEL_POWERZONE_H_


#include <stdint.h>
#include "BinnedData.h"


#define PW_ZONES_NB        7


class PowerZone : public BinnedData {
public:
	PowerZone(uint16_t ftp);

	void addPowerData(uint16_t pw_meas, uint32_t timestamp);
	float getCurPC(void);

	virtual uint32_t getTimeMax(void);
	virtual uint32_t getTimeTotal(void);

	virtual uint32_t getTimeZX(uint16_t i);

	virtual uint32_t getNbBins(void);
	virtual uint32_t getCurBin(void);

private:
	uint32_t m_tot_time;
	uint32_t m_last_bin;
	float m_last_bin_progress_pc;
	uint32_t m_last_timestamp;
	float m_pw_bins[PW_ZONES_NB];
	const uint16_t m_ftp;
};


#endif /* SOURCE_MODEL_POWERZONE_H_ */
