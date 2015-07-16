/*
 * mmwave-ue-netdevice.h
 *
 *  Created on: Nov 4, 2014
 *      Author: sourjya
 */

#ifndef SRC_MMWAVE_MODEL_MMWAVE_UE_NET_DEVICE_H_
#define SRC_MMWAVE_MODEL_MMWAVE_UE_NET_DEVICE_H_


#include "mmwave-net-device.h"
#include "mmwave-enb-net-device.h"
#include "ns3/event-id.h"
#include "ns3/mac48-address.h"
#include "ns3/traced-callback.h"
#include "ns3/nstime.h"
#include "mmwave-phy.h"
#include "mmwave-ue-mac.h"
#include <ns3/lte-ue-rrc.h>
#include <ns3/epc-ue-nas.h>

namespace ns3{

class Packet;
class PacketBurst;
class Node;
class mmWavePhy;
class mmWaveUePhy;
class mmWaveUeMac;
class mmWaveEnbNetDevice;

class mmWaveUeNetDevice : public mmWaveNetDevice
{
public:
	static TypeId GetTypeId (void);

	mmWaveUeNetDevice (void);
	virtual ~mmWaveUeNetDevice (void);
	virtual void DoDispose ();

	uint32_t GetCsgId () const;
	void SetCsgId (uint32_t csgId);

	void UpdateConfig (void);


	virtual bool DoSend (Ptr<Packet> packet, const Address& dest, uint16_t protocolNumber);

	Ptr<mmWaveUePhy> GetPhy (void) const;

	Ptr<mmWaveUeMac> GetMac (void) const;

	uint64_t GetImsi () const;

	uint16_t GetEarfcn () const;

	Ptr<EpcUeNas> GetNas (void) const;

	Ptr<LteUeRrc> GetRrc () const;

	void SetEarfcn (uint16_t earfcn);

	void SetTargetEnb (Ptr<mmWaveEnbNetDevice> enb);

	Ptr<mmWaveEnbNetDevice> GetTargetEnb (void);

    void SetAntennaNum (uint8_t antennaNum);

    uint8_t GetAntennaNum () const;

protected:
  // inherited from Object
  virtual void DoInitialize (void);

private:

  Ptr<mmWaveEnbNetDevice> m_targetEnb;
  Ptr<mmWaveUePhy> m_phy;
  Ptr<mmWaveUeMac> m_mac;

  Ptr<LteUeRrc> m_rrc;
  Ptr<EpcUeNas> m_nas;

  uint64_t m_imsi;

  uint16_t m_earfcn;

   uint32_t m_csgId;
   bool m_isConstructed;
   uint8_t m_antennaNum;


};

}
#endif /* SRC_MMWAVE_MODEL_MMWAVE_UE_NET_DEVICE_H_ */
