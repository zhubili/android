/* soapServer.cpp
   Generated by gSOAP 2.8.105 for ns.h

gSOAP XML Web services tools
Copyright (C) 2000-2020, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"

SOAP_SOURCE_STAMP("@(#) soapServer.cpp ver 2.8.105 2020-11-11 10:46:13 GMT")
extern "C" SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap *soap)
{
#ifndef WITH_FASTCGI
	soap->keep_alive = soap->max_keep_alive + 1;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (soap->keep_alive > 0 && soap->max_keep_alive > 0)
			soap->keep_alive--;
#endif
		if (soap_begin_serve(soap))
		{	if (soap->error >= SOAP_STOP)
				continue;
			return soap->error;
		}
		if ((soap_serve_request(soap) || (soap->fserveloop && soap->fserveloop(soap))) && soap->error && soap->error < SOAP_STOP)
		{
#ifdef WITH_FASTCGI
			soap_send_fault(soap);
#else
			return soap_send_fault(soap);
#endif
		}
#ifdef WITH_FASTCGI
		soap_destroy(soap);
		soap_end(soap);
	} while (1);
#else
	} while (soap->keep_alive);
#endif
	return SOAP_OK;
}

#ifndef WITH_NOSERVEREQUEST
extern "C" SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap *soap)
{
	(void)soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:syncWriteVehicleInfo"))
		return soap_serve___ns1__syncWriteVehicleInfo(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:writeVehicleInfo"))
		return soap_serve___ns1__writeVehicleInfo(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:login"))
		return soap_serve___ns1__login(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:queryLimitSpeed"))
		return soap_serve___ns1__queryLimitSpeed(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:queryViolateSpeed"))
		return soap_serve___ns1__queryViolateSpeed(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:logout"))
		return soap_serve___ns1__logout(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:querySyncTime"))
		return soap_serve___ns1__querySyncTime(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:writeAlarmInfo"))
		return soap_serve___ns1__writeAlarmInfo(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:NWriteVehicleInfo"))
		return soap_serve___ns1__NWriteVehicleInfo(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:NWriteVehicleInfoEx"))
		return soap_serve___ns1__NWriteVehicleInfoEx(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:NSyncWriteVehicleInfo"))
		return soap_serve___ns1__NSyncWriteVehicleInfo(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:WriteFlux"))
		return soap_serve___ns1__WriteFlux(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:NWriteDeviceStatus"))
		return soap_serve___ns1__NWriteDeviceStatus(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:NSyncWriteMobileEPVInfo"))
		return soap_serve___ns1__NSyncWriteMobileEPVInfo(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:NSyncWriteVioInfo"))
		return soap_serve___ns1__NSyncWriteVioInfo(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:NWritePassStat"))
		return soap_serve___ns1__NWritePassStat(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:SyncWriteVehPassInfo"))
		return soap_serve___ns1__SyncWriteVehPassInfo(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:WriteVehPassInfo"))
		return soap_serve___ns1__WriteVehPassInfo(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:SyncWriteAreaSpeed"))
		return soap_serve___ns1__SyncWriteAreaSpeed(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:WriteAreaSpeed"))
		return soap_serve___ns1__WriteAreaSpeed(soap);
	return soap->error = SOAP_NO_METHOD;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__syncWriteVehicleInfo(struct soap *soap)
{	struct __ns1__syncWriteVehicleInfo soap_tmp___ns1__syncWriteVehicleInfo;
	ns1__syncWriteVehicleInfoResponse ns1__syncWriteVehicleInfoResponse_;
	ns1__syncWriteVehicleInfoResponse_.soap_default(soap);
	soap_default___ns1__syncWriteVehicleInfo(soap, &soap_tmp___ns1__syncWriteVehicleInfo);
	if (!soap_get___ns1__syncWriteVehicleInfo(soap, &soap_tmp___ns1__syncWriteVehicleInfo, "-ns1:syncWriteVehicleInfo", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__syncWriteVehicleInfo(soap, soap_tmp___ns1__syncWriteVehicleInfo.ns1__syncWriteVehicleInfo_, ns1__syncWriteVehicleInfoResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__syncWriteVehicleInfoResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__syncWriteVehicleInfoResponse_.soap_put(soap, "ns1:syncWriteVehicleInfoResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__syncWriteVehicleInfoResponse_.soap_put(soap, "ns1:syncWriteVehicleInfoResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__writeVehicleInfo(struct soap *soap)
{	struct __ns1__writeVehicleInfo soap_tmp___ns1__writeVehicleInfo;
	ns1__writeVehicleInfoResponse ns1__writeVehicleInfoResponse_;
	ns1__writeVehicleInfoResponse_.soap_default(soap);
	soap_default___ns1__writeVehicleInfo(soap, &soap_tmp___ns1__writeVehicleInfo);
	if (!soap_get___ns1__writeVehicleInfo(soap, &soap_tmp___ns1__writeVehicleInfo, "-ns1:writeVehicleInfo", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__writeVehicleInfo(soap, soap_tmp___ns1__writeVehicleInfo.ns1__writeVehicleInfo_, ns1__writeVehicleInfoResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__writeVehicleInfoResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__writeVehicleInfoResponse_.soap_put(soap, "ns1:writeVehicleInfoResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__writeVehicleInfoResponse_.soap_put(soap, "ns1:writeVehicleInfoResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__login(struct soap *soap)
{	struct __ns1__login soap_tmp___ns1__login;
	ns1__loginResponse ns1__loginResponse_;
	ns1__loginResponse_.soap_default(soap);
	soap_default___ns1__login(soap, &soap_tmp___ns1__login);
	if (!soap_get___ns1__login(soap, &soap_tmp___ns1__login, "-ns1:login", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__login(soap, soap_tmp___ns1__login.ns1__login_, ns1__loginResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__loginResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__loginResponse_.soap_put(soap, "ns1:loginResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__loginResponse_.soap_put(soap, "ns1:loginResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__queryLimitSpeed(struct soap *soap)
{	struct __ns1__queryLimitSpeed soap_tmp___ns1__queryLimitSpeed;
	ns1__queryLimitSpeedResponse ns1__queryLimitSpeedResponse_;
	ns1__queryLimitSpeedResponse_.soap_default(soap);
	soap_default___ns1__queryLimitSpeed(soap, &soap_tmp___ns1__queryLimitSpeed);
	if (!soap_get___ns1__queryLimitSpeed(soap, &soap_tmp___ns1__queryLimitSpeed, "-ns1:queryLimitSpeed", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__queryLimitSpeed(soap, soap_tmp___ns1__queryLimitSpeed.ns1__queryLimitSpeed_, ns1__queryLimitSpeedResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__queryLimitSpeedResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__queryLimitSpeedResponse_.soap_put(soap, "ns1:queryLimitSpeedResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__queryLimitSpeedResponse_.soap_put(soap, "ns1:queryLimitSpeedResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__queryViolateSpeed(struct soap *soap)
{	struct __ns1__queryViolateSpeed soap_tmp___ns1__queryViolateSpeed;
	ns1__queryViolateSpeedResponse ns1__queryViolateSpeedResponse_;
	ns1__queryViolateSpeedResponse_.soap_default(soap);
	soap_default___ns1__queryViolateSpeed(soap, &soap_tmp___ns1__queryViolateSpeed);
	if (!soap_get___ns1__queryViolateSpeed(soap, &soap_tmp___ns1__queryViolateSpeed, "-ns1:queryViolateSpeed", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__queryViolateSpeed(soap, soap_tmp___ns1__queryViolateSpeed.ns1__queryViolateSpeed_, ns1__queryViolateSpeedResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__queryViolateSpeedResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__queryViolateSpeedResponse_.soap_put(soap, "ns1:queryViolateSpeedResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__queryViolateSpeedResponse_.soap_put(soap, "ns1:queryViolateSpeedResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__logout(struct soap *soap)
{	struct __ns1__logout soap_tmp___ns1__logout;
	ns1__logoutResponse ns1__logoutResponse_;
	ns1__logoutResponse_.soap_default(soap);
	soap_default___ns1__logout(soap, &soap_tmp___ns1__logout);
	if (!soap_get___ns1__logout(soap, &soap_tmp___ns1__logout, "-ns1:logout", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__logout(soap, soap_tmp___ns1__logout.ns1__logout_, ns1__logoutResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__logoutResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__logoutResponse_.soap_put(soap, "ns1:logoutResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__logoutResponse_.soap_put(soap, "ns1:logoutResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__querySyncTime(struct soap *soap)
{	struct __ns1__querySyncTime soap_tmp___ns1__querySyncTime;
	ns1__querySyncTimeResponse ns1__querySyncTimeResponse_;
	ns1__querySyncTimeResponse_.soap_default(soap);
	soap_default___ns1__querySyncTime(soap, &soap_tmp___ns1__querySyncTime);
	if (!soap_get___ns1__querySyncTime(soap, &soap_tmp___ns1__querySyncTime, "-ns1:querySyncTime", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__querySyncTime(soap, soap_tmp___ns1__querySyncTime.ns1__querySyncTime_, ns1__querySyncTimeResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__querySyncTimeResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__querySyncTimeResponse_.soap_put(soap, "ns1:querySyncTimeResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__querySyncTimeResponse_.soap_put(soap, "ns1:querySyncTimeResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__writeAlarmInfo(struct soap *soap)
{	struct __ns1__writeAlarmInfo soap_tmp___ns1__writeAlarmInfo;
	ns1__writeAlarmInfoResponse ns1__writeAlarmInfoResponse_;
	ns1__writeAlarmInfoResponse_.soap_default(soap);
	soap_default___ns1__writeAlarmInfo(soap, &soap_tmp___ns1__writeAlarmInfo);
	if (!soap_get___ns1__writeAlarmInfo(soap, &soap_tmp___ns1__writeAlarmInfo, "-ns1:writeAlarmInfo", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__writeAlarmInfo(soap, soap_tmp___ns1__writeAlarmInfo.ns1__writeAlarmInfo_, ns1__writeAlarmInfoResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__writeAlarmInfoResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__writeAlarmInfoResponse_.soap_put(soap, "ns1:writeAlarmInfoResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__writeAlarmInfoResponse_.soap_put(soap, "ns1:writeAlarmInfoResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__NWriteVehicleInfo(struct soap *soap)
{	struct __ns1__NWriteVehicleInfo soap_tmp___ns1__NWriteVehicleInfo;
	ns1__NWriteVehicleInfoResponse ns1__NWriteVehicleInfoResponse_;
	ns1__NWriteVehicleInfoResponse_.soap_default(soap);
	soap_default___ns1__NWriteVehicleInfo(soap, &soap_tmp___ns1__NWriteVehicleInfo);
	if (!soap_get___ns1__NWriteVehicleInfo(soap, &soap_tmp___ns1__NWriteVehicleInfo, "-ns1:NWriteVehicleInfo", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__NWriteVehicleInfo(soap, soap_tmp___ns1__NWriteVehicleInfo.ns1__NWriteVehicleInfo_, ns1__NWriteVehicleInfoResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__NWriteVehicleInfoResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__NWriteVehicleInfoResponse_.soap_put(soap, "ns1:NWriteVehicleInfoResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__NWriteVehicleInfoResponse_.soap_put(soap, "ns1:NWriteVehicleInfoResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__NWriteVehicleInfoEx(struct soap *soap)
{	struct __ns1__NWriteVehicleInfoEx soap_tmp___ns1__NWriteVehicleInfoEx;
	ns1__NWriteVehicleInfoExResponse ns1__NWriteVehicleInfoExResponse_;
	ns1__NWriteVehicleInfoExResponse_.soap_default(soap);
	soap_default___ns1__NWriteVehicleInfoEx(soap, &soap_tmp___ns1__NWriteVehicleInfoEx);
	if (!soap_get___ns1__NWriteVehicleInfoEx(soap, &soap_tmp___ns1__NWriteVehicleInfoEx, "-ns1:NWriteVehicleInfoEx", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__NWriteVehicleInfoEx(soap, soap_tmp___ns1__NWriteVehicleInfoEx.ns1__NWriteVehicleInfoEx_, ns1__NWriteVehicleInfoExResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__NWriteVehicleInfoExResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__NWriteVehicleInfoExResponse_.soap_put(soap, "ns1:NWriteVehicleInfoExResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__NWriteVehicleInfoExResponse_.soap_put(soap, "ns1:NWriteVehicleInfoExResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__NSyncWriteVehicleInfo(struct soap *soap)
{	struct __ns1__NSyncWriteVehicleInfo soap_tmp___ns1__NSyncWriteVehicleInfo;
	ns1__NSyncWriteVehicleInfoResponse ns1__NSyncWriteVehicleInfoResponse_;
	ns1__NSyncWriteVehicleInfoResponse_.soap_default(soap);
	soap_default___ns1__NSyncWriteVehicleInfo(soap, &soap_tmp___ns1__NSyncWriteVehicleInfo);
	if (!soap_get___ns1__NSyncWriteVehicleInfo(soap, &soap_tmp___ns1__NSyncWriteVehicleInfo, "-ns1:NSyncWriteVehicleInfo", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__NSyncWriteVehicleInfo(soap, soap_tmp___ns1__NSyncWriteVehicleInfo.ns1__NSyncWriteVehicleInfo_, ns1__NSyncWriteVehicleInfoResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__NSyncWriteVehicleInfoResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__NSyncWriteVehicleInfoResponse_.soap_put(soap, "ns1:NSyncWriteVehicleInfoResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__NSyncWriteVehicleInfoResponse_.soap_put(soap, "ns1:NSyncWriteVehicleInfoResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__WriteFlux(struct soap *soap)
{	struct __ns1__WriteFlux soap_tmp___ns1__WriteFlux;
	ns1__WriteFluxResponse ns1__WriteFluxResponse_;
	ns1__WriteFluxResponse_.soap_default(soap);
	soap_default___ns1__WriteFlux(soap, &soap_tmp___ns1__WriteFlux);
	if (!soap_get___ns1__WriteFlux(soap, &soap_tmp___ns1__WriteFlux, "-ns1:WriteFlux", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__WriteFlux(soap, soap_tmp___ns1__WriteFlux.ns1__WriteFlux_, ns1__WriteFluxResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__WriteFluxResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__WriteFluxResponse_.soap_put(soap, "ns1:WriteFluxResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__WriteFluxResponse_.soap_put(soap, "ns1:WriteFluxResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__NWriteDeviceStatus(struct soap *soap)
{	struct __ns1__NWriteDeviceStatus soap_tmp___ns1__NWriteDeviceStatus;
	ns1__NWriteDeviceStatusResponse ns1__NWriteDeviceStatusResponse_;
	ns1__NWriteDeviceStatusResponse_.soap_default(soap);
	soap_default___ns1__NWriteDeviceStatus(soap, &soap_tmp___ns1__NWriteDeviceStatus);
	if (!soap_get___ns1__NWriteDeviceStatus(soap, &soap_tmp___ns1__NWriteDeviceStatus, "-ns1:NWriteDeviceStatus", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__NWriteDeviceStatus(soap, soap_tmp___ns1__NWriteDeviceStatus.ns1__NWriteDeviceStatus_, ns1__NWriteDeviceStatusResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__NWriteDeviceStatusResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__NWriteDeviceStatusResponse_.soap_put(soap, "ns1:NWriteDeviceStatusResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__NWriteDeviceStatusResponse_.soap_put(soap, "ns1:NWriteDeviceStatusResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__NSyncWriteMobileEPVInfo(struct soap *soap)
{	struct __ns1__NSyncWriteMobileEPVInfo soap_tmp___ns1__NSyncWriteMobileEPVInfo;
	ns1__NSyncWriteMobileEPVInfoResponse ns1__NSyncWriteMobileEPVInfoResponse_;
	ns1__NSyncWriteMobileEPVInfoResponse_.soap_default(soap);
	soap_default___ns1__NSyncWriteMobileEPVInfo(soap, &soap_tmp___ns1__NSyncWriteMobileEPVInfo);
	if (!soap_get___ns1__NSyncWriteMobileEPVInfo(soap, &soap_tmp___ns1__NSyncWriteMobileEPVInfo, "-ns1:NSyncWriteMobileEPVInfo", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__NSyncWriteMobileEPVInfo(soap, soap_tmp___ns1__NSyncWriteMobileEPVInfo.ns1__NSyncWriteMobileEPVInfo_, ns1__NSyncWriteMobileEPVInfoResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__NSyncWriteMobileEPVInfoResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__NSyncWriteMobileEPVInfoResponse_.soap_put(soap, "ns1:NSyncWriteMobileEPVInfoResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__NSyncWriteMobileEPVInfoResponse_.soap_put(soap, "ns1:NSyncWriteMobileEPVInfoResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__NSyncWriteVioInfo(struct soap *soap)
{	struct __ns1__NSyncWriteVioInfo soap_tmp___ns1__NSyncWriteVioInfo;
	ns1__NSyncWriteVioInfoResponse ns1__NSyncWriteVioInfoResponse_;
	ns1__NSyncWriteVioInfoResponse_.soap_default(soap);
	soap_default___ns1__NSyncWriteVioInfo(soap, &soap_tmp___ns1__NSyncWriteVioInfo);
	if (!soap_get___ns1__NSyncWriteVioInfo(soap, &soap_tmp___ns1__NSyncWriteVioInfo, "-ns1:NSyncWriteVioInfo", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__NSyncWriteVioInfo(soap, soap_tmp___ns1__NSyncWriteVioInfo.ns1__NSyncWriteVioInfo_, ns1__NSyncWriteVioInfoResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__NSyncWriteVioInfoResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__NSyncWriteVioInfoResponse_.soap_put(soap, "ns1:NSyncWriteVioInfoResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__NSyncWriteVioInfoResponse_.soap_put(soap, "ns1:NSyncWriteVioInfoResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__NWritePassStat(struct soap *soap)
{	struct __ns1__NWritePassStat soap_tmp___ns1__NWritePassStat;
	ns1__NWritePassStatResponse ns1__NWritePassStatResponse_;
	ns1__NWritePassStatResponse_.soap_default(soap);
	soap_default___ns1__NWritePassStat(soap, &soap_tmp___ns1__NWritePassStat);
	if (!soap_get___ns1__NWritePassStat(soap, &soap_tmp___ns1__NWritePassStat, "-ns1:NWritePassStat", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__NWritePassStat(soap, soap_tmp___ns1__NWritePassStat.ns1__NWritePassStat_, ns1__NWritePassStatResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__NWritePassStatResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__NWritePassStatResponse_.soap_put(soap, "ns1:NWritePassStatResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__NWritePassStatResponse_.soap_put(soap, "ns1:NWritePassStatResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__SyncWriteVehPassInfo(struct soap *soap)
{	struct __ns1__SyncWriteVehPassInfo soap_tmp___ns1__SyncWriteVehPassInfo;
	ns1__SyncWriteVehPassInfoResponse ns1__SyncWriteVehPassInfoResponse_;
	ns1__SyncWriteVehPassInfoResponse_.soap_default(soap);
	soap_default___ns1__SyncWriteVehPassInfo(soap, &soap_tmp___ns1__SyncWriteVehPassInfo);
	if (!soap_get___ns1__SyncWriteVehPassInfo(soap, &soap_tmp___ns1__SyncWriteVehPassInfo, "-ns1:SyncWriteVehPassInfo", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__SyncWriteVehPassInfo(soap, soap_tmp___ns1__SyncWriteVehPassInfo.ns1__SyncWriteVehPassInfo_, ns1__SyncWriteVehPassInfoResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__SyncWriteVehPassInfoResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__SyncWriteVehPassInfoResponse_.soap_put(soap, "ns1:SyncWriteVehPassInfoResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__SyncWriteVehPassInfoResponse_.soap_put(soap, "ns1:SyncWriteVehPassInfoResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__WriteVehPassInfo(struct soap *soap)
{	struct __ns1__WriteVehPassInfo soap_tmp___ns1__WriteVehPassInfo;
	ns1__WriteVehPassInfoResponse ns1__WriteVehPassInfoResponse_;
	ns1__WriteVehPassInfoResponse_.soap_default(soap);
	soap_default___ns1__WriteVehPassInfo(soap, &soap_tmp___ns1__WriteVehPassInfo);
	if (!soap_get___ns1__WriteVehPassInfo(soap, &soap_tmp___ns1__WriteVehPassInfo, "-ns1:WriteVehPassInfo", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__WriteVehPassInfo(soap, soap_tmp___ns1__WriteVehPassInfo.ns1__WriteVehPassInfo_, ns1__WriteVehPassInfoResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__WriteVehPassInfoResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__WriteVehPassInfoResponse_.soap_put(soap, "ns1:WriteVehPassInfoResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__WriteVehPassInfoResponse_.soap_put(soap, "ns1:WriteVehPassInfoResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__SyncWriteAreaSpeed(struct soap *soap)
{	struct __ns1__SyncWriteAreaSpeed soap_tmp___ns1__SyncWriteAreaSpeed;
	ns1__SyncWriteAreaSpeedResponse ns1__SyncWriteAreaSpeedResponse_;
	ns1__SyncWriteAreaSpeedResponse_.soap_default(soap);
	soap_default___ns1__SyncWriteAreaSpeed(soap, &soap_tmp___ns1__SyncWriteAreaSpeed);
	if (!soap_get___ns1__SyncWriteAreaSpeed(soap, &soap_tmp___ns1__SyncWriteAreaSpeed, "-ns1:SyncWriteAreaSpeed", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__SyncWriteAreaSpeed(soap, soap_tmp___ns1__SyncWriteAreaSpeed.ns1__SyncWriteAreaSpeed_, ns1__SyncWriteAreaSpeedResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__SyncWriteAreaSpeedResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__SyncWriteAreaSpeedResponse_.soap_put(soap, "ns1:SyncWriteAreaSpeedResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__SyncWriteAreaSpeedResponse_.soap_put(soap, "ns1:SyncWriteAreaSpeedResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__WriteAreaSpeed(struct soap *soap)
{	struct __ns1__WriteAreaSpeed soap_tmp___ns1__WriteAreaSpeed;
	ns1__WriteAreaSpeedResponse ns1__WriteAreaSpeedResponse_;
	ns1__WriteAreaSpeedResponse_.soap_default(soap);
	soap_default___ns1__WriteAreaSpeed(soap, &soap_tmp___ns1__WriteAreaSpeed);
	if (!soap_get___ns1__WriteAreaSpeed(soap, &soap_tmp___ns1__WriteAreaSpeed, "-ns1:WriteAreaSpeed", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__WriteAreaSpeed(soap, soap_tmp___ns1__WriteAreaSpeed.ns1__WriteAreaSpeed_, ns1__WriteAreaSpeedResponse_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	ns1__WriteAreaSpeedResponse_.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__WriteAreaSpeedResponse_.soap_put(soap, "ns1:WriteAreaSpeedResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__WriteAreaSpeedResponse_.soap_put(soap, "ns1:WriteAreaSpeedResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapServer.cpp */
