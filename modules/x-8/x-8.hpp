/********************************************************************************
 *                              Nepenthes
 *                        - finest collection -
 *
 *
 *
 * Copyright (C) 2005  Paul Baecher & Markus Koetter
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 * 
 * 
 *             contact nepenthesdev@users.sourceforge.net  
 *
 *******************************************************************************/

 /* $Id: x-8.hpp 2078 2005-10-11 20:43:28Z common $ */

#include "config.h"

#ifdef HAVE_GEOLOCATION

#include "DialogueFactory.hpp"
#include "Module.hpp"
#include "ModuleManager.hpp"
#include "SocketManager.hpp"
#include "Nepenthes.hpp"
#include "Dialogue.hpp"
#include "Socket.hpp"
#include "GeoLocationCallback.hpp"

using namespace std;

namespace nepenthes
{


	/**
	 * X8 Module
	 * show how to use the GeoLocationManager
	 */
	class X8 : public Module , public DialogueFactory
	{
	public:
		X8(Nepenthes *);
		~X8();
		Dialogue *createDialogue(Socket *socket);
		bool Init();
		bool Exit();
	};


	/**
	 * X8 Module
	 * show how to use the GeoLocationCallback
	 */

	class X8Dialogue : public Dialogue , public GeoLocationCallback
	{
	public:
		X8Dialogue(Socket *socket);
		~X8Dialogue();
		ConsumeLevel incomingData(Message *msg);
		ConsumeLevel outgoingData(Message *msg);
		ConsumeLevel handleTimeout(Message *msg);
		ConsumeLevel connectionLost(Message *msg);
		ConsumeLevel connectionShutdown(Message *msg);

		void locationSuccess(GeoLocationResult *result);
		void locationFailure(GeoLocationResult *result);

	private:
		uint32_t m_RequestsPending;


	};

}
extern nepenthes::Nepenthes *g_Nepenthes;

#endif // HAVE_GEOLOCATION